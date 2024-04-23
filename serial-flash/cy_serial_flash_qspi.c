/***********************************************************************************************//**
 * \file cy_serial_flash_qspi.c
 *
 * \brief
 * Provides APIs for interacting with an external flash connected to the SPI or
 * QSPI interface, uses SFDP to auto-discover memory properties if SFDP is
 * enabled in the configuration.
 *
 ***************************************************************************************************
 * \copyright
 * Copyright 2018-2022 Cypress Semiconductor Corporation (an Infineon company) or
 * an affiliate of Cypress Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 **************************************************************************************************/

#include <stdbool.h>
#include "cy_serial_flash_qspi.h"
#include "cyhal_qspi.h"
#include "cy_trigmux.h"
#include "cy_dma.h"
#include "cy_utils.h"
#if defined(_CYHAL_DRIVER_AVAILABLE_IRQ) && (_CYHAL_DRIVER_AVAILABLE_IRQ)
#include "cyhal_irq_impl.h"
#endif /* defined(_CYHAL_DRIVER_AVAILABLE_IRQ) && (_CYHAL_DRIVER_AVAILABLE_IRQ) */

#if defined(CY_SERIAL_FLASH_QSPI_THREAD_SAFE)
#include <stdlib.h>
#include "cyabs_rtos.h"
#endif /* #if defined(CY_SERIAL_FLASH_QSPI_THREAD_SAFE) */

#ifdef CY_IP_MXSMIF

#if defined(__cplusplus)
extern "C" {
#endif


/** \cond INTERNAL */

/** Timeout to apply while polling the memory for its ready status after quad
 *  enable command has been sent out. Quad enable is a non-volatile write.
 */
#define CY_SERIAL_FLASH_QUAD_ENABLE_TIMEOUT_US      (5000lu) // in microseconds

#define _CY_SERIAL_FLASH_ALL_DMA_EVENTS             (CYHAL_DMA_DESCRIPTOR_COMPLETE |\
                                                     CYHAL_DMA_SRC_BUS_ERROR | CYHAL_DMA_DST_BUS_ERROR | CYHAL_DMA_SRC_MISAL |\
                                                     CYHAL_DMA_DST_MISAL | CYHAL_DMA_CURR_PTR_NULL |\
                                                     CYHAL_DMA_ACTIVE_CH_DISABLED | CYHAL_DMA_DESCR_BUS_ERROR)

/** Number of loops to run while polling the SMIF for its busy status. */
#define SMIF_BUSY_CHECK_LOOP_COUNT                  (10lu)

/** Timeout to apply per loop while polling the SMIF for its busy status. */
#define SMIF_BUSY_CHECK_TIMEOUT_MS                  (1lu) // in milliseconds

/* Default deselect delay for SMIF Config */
#define SMIF_OSPI_DESELECT_DELAY                    (7UL)

// Number of memories supported by the driver
#define SMIF_MEM_DEVICES                            (1u)

// SMIF slot from which the memory configuration is picked up - fixed to 0 as
// the driver supports only one device
#define MEM_SLOT                                    (0u)

/* Maximum number of bytes that can be read by SMIF in one transfer */
#define SMIF_MAX_RX_COUNT                           (65536lu)

#define MSB_SHIFT_EIGHT                             (0x08u)
#define LSB_MASK                                    (0xFFlu)

/* Masks used for checking the flag bits */
#define FLAG_QSPI_HAL_INIT_DONE                     (0x01lu << 0)
#define FLAG_DMA_INIT_DONE                          (0x01lu << 1)
#define FLAG_READ_IN_PROGRESS                       (0x01lu << 2)

#define IS_FLAG_SET(mask)                           (status_flags & (mask))
#define SET_FLAG(mask)                              (status_flags |= (mask))
#define CLEAR_FLAG(mask)                            (status_flags &= ~(mask))

/* Some devices execute program code from external QSPI memory (XIP mode).
 * SerialFlash still can work on such devices, but with some limitations. */
#if defined(CY_DEVICE_CYW20829)
#define _CY_SERIAL_FLASH_USING_XIP_MEMORY
#endif /* defined(CY_DEVICE_CYW20829) */

/** \endcond */

static cyhal_qspi_t qspi_obj;
static volatile uint32_t status_flags;
static cy_stc_smif_mem_config_t* qspi_mem_config[SMIF_MEM_DEVICES];

static cy_stc_smif_block_config_t qspi_block_config =
{
    // The number of SMIF memories defined.
    .memCount     = SMIF_MEM_DEVICES,
    // The pointer to the array of memory config structures of size memCount.
    .memConfig    = (cy_stc_smif_mem_config_t**)qspi_mem_config,
    // The version of the SMIF driver.
    .majorVersion = CY_SMIF_DRV_VERSION_MAJOR,
    // The version of the SMIF driver.
    .minorVersion = CY_SMIF_DRV_VERSION_MINOR
};

#if defined(CY_SERIAL_FLASH_QSPI_THREAD_SAFE)
static cy_mutex_t serial_flash_mutex;
#endif /* #if defined(CY_SERIAL_FLASH_QSPI_THREAD_SAFE) */

#if CYHAL_DRIVER_AVAILABLE_DMA
#if (CY_CPU_CORTEX_M55)
CY_SECTION(".cy_socmem_data") static cyhal_dma_t dma;
#else
static cyhal_dma_t dma;
#endif

typedef struct
{
    uint32_t addr;
    size_t length;
    uint8_t* buf;
    cy_serial_flash_qspi_read_complete_callback_t callback;
    void* callback_arg;
} read_txfr_info_t;

static read_txfr_info_t read_txfr_info;

static cy_rslt_t _init_dma(void);
static cy_rslt_t _deinit_dma(void);
static void _rx_dma_irq_handler(void* args, cyhal_dma_event_t events);
static cy_en_smif_status_t _read_next_chunk(void);
#if !defined(_CY_SERIAL_FLASH_USING_XIP_MEMORY)
static void _value_to_byte_array(uint32_t value, uint8_t* byte_array, uint32_t start_pos,
                                 uint32_t size);
static void _qspi_enable_rx_output(cyhal_qspi_t* obj, cyhal_source_t* source);
#endif /* #if !defined(_CY_SERIAL_FLASH_USING_XIP_MEMORY) */
#if !defined(CYHAL_API_AVAILABLE_DMA_GET_MAX_ELEMENTS_PER_BURST)
static uint32_t _dma_get_max_elements_per_burst(cyhal_dma_t* obj);
#endif /* !defined(CYHAL_API_AVAILABLE_DMA_GET_MAX_ELEMENTS_PER_BURST) */
#endif /* CYHAL_DRIVER_AVAILABLE_DMA */
cy_rslt_t _cyhal_serial_flash_qspi_init_common(void);
void _cyhal_serial_flash_qspi_deinit_common(void);
//Temporarily commented out as only in SFDP mode it is needed.
//If specifying the qspi configuration
//device is already operating correctly. Issue tracked in
// https://jiracc.intra.infineon.com/browse/BSP-5762
// #if (CY_IP_MXSMIF_VERSION >= 5)
// CY_SECTION_RAMFUNC_BEGIN
// static cy_en_smif_status_t _enable_octal_mode_if_needed(void);
// static cy_en_smif_status_t _set_capture_mode_to_normal_if_needed(void);
// CY_SECTION_RAMFUNC_END
// #endif /* (CY_IP_MXSMIF_VERSION >= 5) */

static inline cy_rslt_t _mutex_acquire(void);
static inline cy_rslt_t _mutex_release(void);

#if !defined(CYHAL_API_AVAILABLE_QSPI_IS_BUSY)
bool _qspi_is_busy(cyhal_qspi_t* obj);
#endif /* !defined(CYHAL_API_AVAILABLE_QSPI_IS_BUSY) */

#if defined(_CY_SERIAL_FLASH_USING_XIP_MEMORY)
static cy_stc_smif_context_t SMIFContext;
#endif /* defined(_CY_SERIAL_FLASH_USING_XIP_MEMORY) */

//--------------------------------------------------------------------------------------------------
// cy_serial_flash_qspi_init
//
// The driver supports only one memory. When multiple memory configurations are generated by the
// SMIF configurator tool, provide only the configuration for memory that need to be supported by
// the driver.  Memory configuration can be changed by deinit followed by init with new
// configuration
//--------------------------------------------------------------------------------------------------
cy_rslt_t cy_serial_flash_qspi_init(
    const cy_stc_smif_mem_config_t* mem_config,
    cyhal_gpio_t io0,
    cyhal_gpio_t io1,
    cyhal_gpio_t io2,
    cyhal_gpio_t io3,
    cyhal_gpio_t io4,
    cyhal_gpio_t io5,
    cyhal_gpio_t io6,
    cyhal_gpio_t io7,
    cyhal_gpio_t sclk,
    cyhal_gpio_t ssel,
    uint32_t hz)
{
    cy_rslt_t result = CY_RSLT_SUCCESS;

    #if defined(_CY_SERIAL_FLASH_USING_XIP_MEMORY)
    CY_UNUSED_PARAMETER(io0); CY_UNUSED_PARAMETER(io1); CY_UNUSED_PARAMETER(io2);
    CY_UNUSED_PARAMETER(io3); CY_UNUSED_PARAMETER(io4); CY_UNUSED_PARAMETER(io5);
    CY_UNUSED_PARAMETER(io6); CY_UNUSED_PARAMETER(io7); CY_UNUSED_PARAMETER(sclk);
    CY_UNUSED_PARAMETER(ssel); CY_UNUSED_PARAMETER(hz);
    #endif /* defined(_CY_SERIAL_FLASH_USING_XIP_MEMORY) */

    #if (CYHAL_API_VERSION >= 2)
    // SMIF is already initialized in XIP mode hence we can skip calling cyhal_qspi_init.
    // initializing only the SMIF base address and the context variables.
    #if defined(_CY_SERIAL_FLASH_USING_XIP_MEMORY)
    qspi_obj.base = SMIF0;
    qspi_obj.context = SMIFContext;
    #else /* defined(_CY_SERIAL_FLASH_USING_XIP_MEMORY) */
    cyhal_qspi_slave_pin_config_t memory_pin_set =
    {
        .io   = { io0, io1, io2, io3, io4, io5, io6, io7 },
        .ssel = ssel
    };
    result = cyhal_qspi_init(&qspi_obj, sclk, &memory_pin_set, hz, 0, NULL);
    #endif /* defined(_CY_SERIAL_FLASH_USING_XIP_MEMORY) */

    #else /* HAL API version 1 */
    result = cyhal_qspi_init(&qspi_obj, io0, io1, io2, io3, io4, io5, io6, io7, sclk, ssel, hz, 0);
    #endif /* HAL API version 1 */

    qspi_mem_config[MEM_SLOT] = (cy_stc_smif_mem_config_t*)mem_config;

    if (CY_RSLT_SUCCESS == result)
    {
        SET_FLAG(FLAG_QSPI_HAL_INIT_DONE);
        result = _cyhal_serial_flash_qspi_init_common();
    }

    if (CY_RSLT_SUCCESS != result)
    {
        cy_serial_flash_qspi_deinit();
    }

    return result;
}


//--------------------------------------------------------------------------------------------------
// cy_serial_flash_qspi_deinit
//--------------------------------------------------------------------------------------------------
void cy_serial_flash_qspi_deinit(void)
{
    cy_rslt_t result;

    if (IS_FLAG_SET(FLAG_QSPI_HAL_INIT_DONE))
    {
        /* BOOTROM enables XIP by default and user is not expected to
           disable memory while in XIP */
        #if !defined(_CY_SERIAL_FLASH_USING_XIP_MEMORY)
        if (qspi_obj.base != NULL)
        {
            /* There is no harm in calling this even if Cy_SMIF_MemInit() did
             * not succeed since anyway we own the QSPI object.
             */
            Cy_SMIF_MemDeInit(qspi_obj.base);
        }

        cyhal_qspi_free(&qspi_obj);
        #endif /* !defined(_CY_SERIAL_FLASH_USING_XIP_MEMORY) */
        CLEAR_FLAG(FLAG_QSPI_HAL_INIT_DONE);

        _cyhal_serial_flash_qspi_deinit_common();
    }

    CY_UNUSED_PARAMETER(result); /* To avoid compiler warning in Release mode. */
}


#if defined(CYHAL_API_AVAILABLE_QSPI_ATTACH)
//--------------------------------------------------------------------------------------------------
// cy_serial_flash_qspi_attach
//
// This API attaches to a preconfigures SMIF peripheral but reconfigures the Memory Device
// because it needs the information about its sizes, commands and configuration to correctly
// be able to perform read/write/erase operations.
//--------------------------------------------------------------------------------------------------
cy_rslt_t cy_serial_flash_qspi_attach(
    const cy_stc_smif_mem_config_t* mem_config,
    cyhal_gpio_t io0,
    cyhal_gpio_t io1,
    cyhal_gpio_t io2,
    cyhal_gpio_t io3,
    cyhal_gpio_t io4,
    cyhal_gpio_t io5,
    cyhal_gpio_t io6,
    cyhal_gpio_t io7,
    cyhal_gpio_t ssel)
{
    cy_rslt_t result = CY_RSLT_SUCCESS;

    cyhal_qspi_slave_pin_config_t memory_pin_set =
    {
        .io   = { io0, io1, io2, io3, io4, io5, io6, io7 },
        .ssel = ssel
    };
    result = cyhal_qspi_attach(&qspi_obj, &memory_pin_set);

    qspi_mem_config[MEM_SLOT] = (cy_stc_smif_mem_config_t*)mem_config;

    if (CY_RSLT_SUCCESS == result)
    {
        SET_FLAG(FLAG_QSPI_HAL_INIT_DONE);
        result = _cyhal_serial_flash_qspi_init_common();
    }

    if (CY_RSLT_SUCCESS != result)
    {
        cy_serial_flash_qspi_detach();
    }
    return result;
}


#endif /* defined(CYHAL_API_AVAILABLE_QSPI_ATTACH) */

#if defined(CYHAL_API_AVAILABLE_QSPI_DETACH)
//--------------------------------------------------------------------------------------------------
// cy_serial_flash_qspi_detach
//--------------------------------------------------------------------------------------------------
void cy_serial_flash_qspi_detach(void)
{
    if (IS_FLAG_SET(FLAG_QSPI_HAL_INIT_DONE))
    {
        cyhal_qspi_detach(&qspi_obj);

        CLEAR_FLAG(FLAG_QSPI_HAL_INIT_DONE);
    }
    _cyhal_serial_flash_qspi_deinit_common();
}


#endif /* defined(CYHAL_API_AVAILABLE_QSPI_DETACH) */

//--------------------------------------------------------------------------------------------------
// cy_serial_flash_qspi_get_size
//--------------------------------------------------------------------------------------------------
size_t cy_serial_flash_qspi_get_size(void)
{
    return (size_t)qspi_block_config.memConfig[MEM_SLOT]->deviceCfg->memSize;
}


//--------------------------------------------------------------------------------------------------
// cy_serial_flash_qspi_get_erase_size
//--------------------------------------------------------------------------------------------------
size_t cy_serial_flash_qspi_get_erase_size(uint32_t addr)
{
    size_t                            erase_sector_size;
    cy_stc_smif_hybrid_region_info_t* hybrid_info = NULL;

    cy_en_smif_status_t smif_status =
        Cy_SMIF_MemLocateHybridRegion(qspi_block_config.memConfig[MEM_SLOT], &hybrid_info, addr);

    if (CY_SMIF_SUCCESS != smif_status)
    {
        erase_sector_size = (size_t)qspi_block_config.memConfig[MEM_SLOT]->deviceCfg->eraseSize;
    }
    else
    {
        erase_sector_size = (size_t)hybrid_info->eraseSize;
    }

    return erase_sector_size;
}


//--------------------------------------------------------------------------------------------------
// cy_serial_flash_qspi_get_prog_size
//--------------------------------------------------------------------------------------------------
size_t cy_serial_flash_qspi_get_prog_size(uint32_t addr)
{
    CY_UNUSED_PARAMETER(addr);
    return (size_t)qspi_block_config.memConfig[MEM_SLOT]->deviceCfg->programSize;
}


//--------------------------------------------------------------------------------------------------
// cy_serial_flash_qspi_read
//--------------------------------------------------------------------------------------------------
cy_rslt_t cy_serial_flash_qspi_read(uint32_t addr, size_t length, uint8_t* buf)
{
    cy_rslt_t result_mutex_rel = CY_RSLT_SUCCESS;

    cy_rslt_t result = _mutex_acquire();

    if (CY_RSLT_SUCCESS == result)
    {
        // Cy_SMIF_MemRead() returns error if (addr + length) > total flash size.
        result = (cy_rslt_t)Cy_SMIF_MemRead(qspi_obj.base, qspi_block_config.memConfig[MEM_SLOT],
                                            addr,
                                            buf, length, &qspi_obj.context);
        result_mutex_rel = _mutex_release();
    }

    /* Give priority to the status of SMIF operation when both SMIF operation
     * and mutex release fail.
     */
    return ((CY_RSLT_SUCCESS == result) ? result_mutex_rel : result);
}


//--------------------------------------------------------------------------------------------------
// cy_serial_flash_qspi_abort_read
//--------------------------------------------------------------------------------------------------
cy_rslt_t cy_serial_flash_qspi_abort_read(void)
{
    #if CYHAL_DRIVER_AVAILABLE_DMA
    cy_rslt_t result;

    /* Wait until SMIF finishes any pending transfer. */
    for (uint32_t loop = 0; loop < SMIF_BUSY_CHECK_LOOP_COUNT; loop++)
    {
        #if !defined(CYHAL_API_AVAILABLE_QSPI_IS_BUSY)
        if (!_qspi_is_busy(&qspi_obj))
        #else
        if (!cyhal_qspi_is_busy(&qspi_obj))
        #endif /* !defined(CYHAL_API_AVAILABLE_QSPI_IS_BUSY) or other */
        {
            break;
        }

        cyhal_system_delay_ms(SMIF_BUSY_CHECK_TIMEOUT_MS);
    }

    #if !defined(CYHAL_API_AVAILABLE_QSPI_IS_BUSY)
    if (_qspi_is_busy(&qspi_obj))
    #else
    if (cyhal_qspi_is_busy(&qspi_obj))
    #endif /* !defined(CYHAL_API_AVAILABLE_QSPI_IS_BUSY) or other */
    {
        SET_FLAG(FLAG_READ_IN_PROGRESS);
        result = CY_RSLT_SERIAL_FLASH_ERR_QSPI_BUSY;
    }
    else
    {
        result = cyhal_dma_disable(&dma);
        if (CY_RSLT_SUCCESS == result)
        {
            CLEAR_FLAG(FLAG_READ_IN_PROGRESS);
        }
    }

    return result;
    #else /* !CYHAL_DRIVER_AVAILABLE_DMA */
    return CY_RSLT_SERIAL_FLASH_ERR_UNSUPPORTED;
    #endif /* CYHAL_DRIVER_AVAILABLE_DMA */
}


//--------------------------------------------------------------------------------------------------
// cy_serial_flash_qspi_read_async
//--------------------------------------------------------------------------------------------------
cy_rslt_t cy_serial_flash_qspi_read_async(uint32_t addr, size_t length, uint8_t* buf,
                                          cy_serial_flash_qspi_read_complete_callback_t callback,
                                          void* callback_arg)
{
    #if CYHAL_DRIVER_AVAILABLE_DMA
    cy_rslt_t result = CY_RSLT_SERIAL_FLASH_ERR_BAD_PARAM;
    cy_rslt_t result_mutex_rel = CY_RSLT_SUCCESS;

    CY_ASSERT(NULL != buf);

    if (IS_FLAG_SET(FLAG_READ_IN_PROGRESS))
    {
        result = CY_RSLT_SERIAL_FLASH_ERR_READ_BUSY; /* Previous read request is not yet complete.
                                                      */
    }
    else if ((addr + length) <= cy_serial_flash_qspi_get_size())
    {
        result = _mutex_acquire();

        if (CY_RSLT_SUCCESS == result)
        {
            read_txfr_info.addr = addr;
            read_txfr_info.length = length;
            read_txfr_info.buf = buf;
            read_txfr_info.callback = callback;
            read_txfr_info.callback_arg = callback_arg;

            SET_FLAG(FLAG_READ_IN_PROGRESS);
            result = (cy_rslt_t)_read_next_chunk();  /* Start the read transfer */

            if (CY_RSLT_SUCCESS != result)
            {
                CLEAR_FLAG(FLAG_READ_IN_PROGRESS);
            }

            result_mutex_rel = _mutex_release();
        }
    }

    /* Give priority to the status of SMIF operation when both SMIF operation
     * and mutex release fail.
     */
    return ((CY_RSLT_SUCCESS == result) ? result_mutex_rel : result);
    #else /* !CYHAL_DRIVER_AVAILABLE_DMA */
    CY_UNUSED_PARAMETER(addr);
    CY_UNUSED_PARAMETER(length);
    CY_UNUSED_PARAMETER(buf);
    CY_UNUSED_PARAMETER(callback);
    CY_UNUSED_PARAMETER(callback_arg);

    return CY_RSLT_SERIAL_FLASH_ERR_UNSUPPORTED;
    #endif /* CYHAL_DRIVER_AVAILABLE_DMA */
}


//--------------------------------------------------------------------------------------------------
// cy_serial_flash_qspi_write
//--------------------------------------------------------------------------------------------------
cy_rslt_t cy_serial_flash_qspi_write(uint32_t addr, size_t length, const uint8_t* buf)
{
    cy_rslt_t result_mutex_rel = CY_RSLT_SUCCESS;

    cy_rslt_t result = _mutex_acquire();

    if (CY_RSLT_SUCCESS == result)
    {
        // Cy_SMIF_MemWrite() returns error if (addr + length) > total flash size.
        result = (cy_rslt_t)Cy_SMIF_MemWrite(qspi_obj.base, qspi_block_config.memConfig[MEM_SLOT],
                                             addr,
                                             (uint8_t*)buf, length, &qspi_obj.context);
        result_mutex_rel = _mutex_release();
    }

    /* Give priority to the status of SMIF operation when both SMIF operation
     * and mutex release fail.
     */
    return ((CY_RSLT_SUCCESS == result) ? result_mutex_rel : result);
}


//--------------------------------------------------------------------------------------------------
// cy_serial_flash_qspi_erase
//--------------------------------------------------------------------------------------------------
cy_rslt_t cy_serial_flash_qspi_erase(uint32_t addr, size_t length)
{
    cy_rslt_t result_mutex_rel = CY_RSLT_SUCCESS;

    cy_rslt_t result = _mutex_acquire();

    if (CY_RSLT_SUCCESS == result)
    {
        // If the erase is for the entire chip, use chip erase command
        if ((addr == 0u) && (length == cy_serial_flash_qspi_get_size()))
        {
            result =
                (cy_rslt_t)Cy_SMIF_MemEraseChip(qspi_obj.base,
                                                qspi_block_config.memConfig[MEM_SLOT],
                                                &qspi_obj.context);
        }
        else
        {
            // Cy_SMIF_MemEraseSector() returns error if (addr + length) > total flash size or if
            // addr is not aligned to erase sector size or if (addr + length) is not aligned to
            // erase sector size.
            result =
                (cy_rslt_t)Cy_SMIF_MemEraseSector(qspi_obj.base,
                                                  qspi_block_config.memConfig[MEM_SLOT],
                                                  addr, length, &qspi_obj.context);
        }

        result_mutex_rel = _mutex_release();
    }

    /* Give priority to the status of SMIF operation when both SMIF operation
     * and mutex release fail.
     */
    return ((CY_RSLT_SUCCESS == result) ? result_mutex_rel : result);
}


//--------------------------------------------------------------------------------------------------
// cy_serial_flash_qspi_enable_xip
//
// This function enables or disables XIP on the MCU, does not send any command
// to the serial flash. XIP register configuration is already done as part of
// cy_serial_flash_qspi_init() if MMIO mode is enabled in the QSPI
// Configurator.
//--------------------------------------------------------------------------------------------------
cy_rslt_t cy_serial_flash_qspi_enable_xip(bool enable)
{
    if (enable)
    {
        Cy_SMIF_SetMode(qspi_obj.base, CY_SMIF_MEMORY);
    }
    else
    {
        Cy_SMIF_SetMode(qspi_obj.base, CY_SMIF_NORMAL);
    }

    return CY_RSLT_SUCCESS;
}


//--------------------------------------------------------------------------------------------------
// cy_serial_flash_qspi_set_interrupt_priority
//--------------------------------------------------------------------------------------------------
void cy_serial_flash_qspi_set_interrupt_priority(uint8_t priority)
{
    /* Here cyhal_qspi_enable_event does not change any QSPI interrupt-related configuration except
     *  changing the priority of QSPI interrupt */
    cyhal_qspi_enable_event(&qspi_obj, CYHAL_QSPI_EVENT_NONE, priority, false);
}


//--------------------------------------------------------------------------------------------------
// cy_serial_flash_qspi_set_interrupt_priority
//--------------------------------------------------------------------------------------------------
void cy_serial_flash_qspi_set_dma_interrupt_priority(uint8_t priority)
{
    #if CYHAL_DRIVER_AVAILABLE_DMA
    /* Here cyhal_dma_enable_event does not change any DMA interrupt-related configuration except
     *  changing the priority of DMA interrupt */
    cyhal_dma_enable_event(&dma, CYHAL_DMA_NO_INTR, priority, false);
    #else
    CY_UNUSED_PARAMETER(priority);
    #endif /* CYHAL_DRIVER_AVAILABLE_DMA */
}


//--------------------------------------------------------------------------------------------------
// _cyhal_serial_flash_qspi_init_common
//--------------------------------------------------------------------------------------------------
cy_rslt_t _cyhal_serial_flash_qspi_init_common(void)
{
    cy_en_smif_status_t smif_status = CY_SMIF_SUCCESS;
    cy_rslt_t result = CY_RSLT_SUCCESS;

    // For MemInit to complete successfully the SMIF peripheral needs to have
    // capture mode set to normal. Check its value and update it if needed.
    #if (CY_IP_MXSMIF_VERSION >= 5)
    //Temporarily commented out as only in SFDP mode it is needed. If specifying the qspi
    // configuration
    //device is already operating correctly. Issue tracked in
    // https://jiracc.intra.infineon.com/browse/BSP-5762
    // smif_status = _set_capture_mode_to_normal_if_needed();

    if (CY_SMIF_SUCCESS == smif_status)
    {
    #endif // if (CY_IP_MXSMIF_VERSION >= 5)
    // Perform SFDP detection and XIP register configuration depending on the memory
    // configuration.
    smif_status = Cy_SMIF_MemInit(qspi_obj.base, &qspi_block_config, &qspi_obj.context);
    #if (CY_IP_MXSMIF_VERSION >= 5)
}


    #endif // if (CY_IP_MXSMIF_VERSION >= 5)

    if (CY_SMIF_SUCCESS == smif_status)
    {
        // Enable Quad mode (1-1-4 or 1-4-4 modes) to use all the four I/Os during
        // communication if needed.
        if ((qspi_block_config.memConfig[MEM_SLOT]->deviceCfg->readCmd->dataWidth ==
             CY_SMIF_WIDTH_QUAD) ||
            (qspi_block_config.memConfig[MEM_SLOT]->deviceCfg->programCmd->dataWidth ==
             CY_SMIF_WIDTH_QUAD))
        {
            bool isQuadEnabled = false;
            smif_status =
                Cy_SMIF_MemIsQuadEnabled(qspi_obj.base, qspi_block_config.memConfig[MEM_SLOT],
                                         &isQuadEnabled, &qspi_obj.context);
            if ((CY_SMIF_SUCCESS == smif_status) && !isQuadEnabled)
            {
                smif_status =
                    Cy_SMIF_MemEnableQuadMode(qspi_obj.base,
                                              qspi_block_config.memConfig[MEM_SLOT],
                                              CY_SERIAL_FLASH_QUAD_ENABLE_TIMEOUT_US,
                                              &qspi_obj.context);
            }
        }
        #if (CY_IP_MXSMIF_VERSION >= 5)
        // Enable Octal mode (8S-8S-8S or 8D-8D-8D modes) to use all the eight I/Os during
        // communication if needed.
        //Temporarily commented out as only in SFDP mode it is needed. If specifying the qspi
        // configuration
        //device is already operating correctly. Issue tracked in
        // https://jiracc.intra.infineon.com/browse/BSP-5762
        // smif_status = _enable_octal_mode_if_needed();
        #endif // if (CY_IP_MXSMIF_VERSION >= 5)
    }

    if (CY_SMIF_SUCCESS == smif_status)
    {
        #if CYHAL_DRIVER_AVAILABLE_DMA
        result = _init_dma();

        if (CY_RSLT_SUCCESS == result)
        {
            SET_FLAG(FLAG_DMA_INIT_DONE);
        #endif /* CYHAL_DRIVER_AVAILABLE_DMA */

        #if defined(CY_SERIAL_FLASH_QSPI_THREAD_SAFE)
        /* Initialize the mutex */
        result = cy_rtos_init_mutex(&serial_flash_mutex);
        #endif /* #if defined(CY_SERIAL_FLASH_QSPI_THREAD_SAFE) */

        #if CYHAL_DRIVER_AVAILABLE_DMA
    }
        #endif /* CYHAL_DRIVER_AVAILABLE_DMA */
    }

    if (CY_SMIF_SUCCESS != smif_status)
    {
        result = (cy_rslt_t)smif_status;
    }

    return result;
}

//--------------------------------------------------------------------------------------------------
// _cyhal_serial_flash_qspi_deinit_common
//--------------------------------------------------------------------------------------------------
void _cyhal_serial_flash_qspi_deinit_common(void)
{
    cy_rslt_t result = CY_RSLT_SUCCESS;

    #if CYHAL_DRIVER_AVAILABLE_DMA
    if (IS_FLAG_SET(FLAG_DMA_INIT_DONE))
    {
        result = _deinit_dma();
        CY_ASSERT(CY_RSLT_SUCCESS == result);

        CLEAR_FLAG(FLAG_DMA_INIT_DONE);
    #endif /* CYHAL_DRIVER_AVAILABLE_DMA */

    #if defined(CY_SERIAL_FLASH_QSPI_THREAD_SAFE)
    result = cy_rtos_deinit_mutex(&serial_flash_mutex);
    CY_ASSERT(CY_RSLT_SUCCESS == result);
    #endif /* #if defined(CY_SERIAL_FLASH_QSPI_THREAD_SAFE) */

    #if CYHAL_DRIVER_AVAILABLE_DMA
}


    #endif

    CY_UNUSED_PARAMETER(result);     /* To avoid compiler warning in Release mode. */
}

#if CYHAL_DRIVER_AVAILABLE_DMA
//--------------------------------------------------------------------------------------------------
// _read_next_chunk
//--------------------------------------------------------------------------------------------------
static cy_en_smif_status_t _read_next_chunk(void)
{
    cy_en_smif_status_t smif_status = CY_SMIF_SUCCESS;
    uint32_t chunk;
    #if !defined(_CY_SERIAL_FLASH_USING_XIP_MEMORY)
    uint8_t addr_array[CY_SMIF_FOUR_BYTES_ADDR] = { 0U }
    ;
    #endif /* !defined(_CY_SERIAL_FLASH_USING_XIP_MEMORY) */

    if (read_txfr_info.length > 0UL)
    {
        /* SMIF can read only up to 65536 bytes in one go. Split the larger read into multiple
           chunks */
        chunk =
            (read_txfr_info.length >
             SMIF_MAX_RX_COUNT) ? (SMIF_MAX_RX_COUNT) : read_txfr_info.length;

        cyhal_dma_cfg_t dma_config =
        {
            #if !defined(_CY_SERIAL_FLASH_USING_XIP_MEMORY)
            .src_addr       = (uint32_t)&(SMIF_RX_DATA_FIFO_RD1(qspi_obj.base)),
            .src_increment  = 0,
            #else /* defined(_CY_SERIAL_FLASH_USING_XIP_MEMORY) */
            .src_addr       =
                (uint32_t)(qspi_block_config.memConfig[MEM_SLOT]->baseAddress +
                           read_txfr_info.addr),
            .src_increment  = 1,
            #endif /* !defined(_CY_SERIAL_FLASH_USING_XIP_MEMORY) or other */
            .transfer_width = 8,
            .dst_addr       = (uint32_t)read_txfr_info.buf,
            .dst_increment  = 1,
            .length         = 0,
            .burst_size     = 0,
            .action         = CYHAL_DMA_TRANSFER_FULL_DISABLE,
        }
        ;

        #if !defined(CYHAL_API_AVAILABLE_DMA_GET_MAX_ELEMENTS_PER_BURST)
        uint32_t dma_max_elements_per_transfer = _dma_get_max_elements_per_burst(&dma);
        #else
        uint32_t dma_max_elements_per_transfer = cyhal_dma_get_max_elements_per_burst(&dma);
        #endif /* !defined(CYHAL_API_AVAILABLE_DMA_GET_MAX_ELEMENTS_PER_BURST) or other */
        dma_config.length = chunk;
        /* In 2D transfer, (X_count x Y_count) should be a multiple of
           dma_max_elements_per_transfer. */
        if (chunk > dma_max_elements_per_transfer)
        {
            /* Make chunk divisible by dma_max_elements_per_transfer by masking out the LS bits */
            chunk &= ~(dma_max_elements_per_transfer - 1);

            dma_config.burst_size = dma_max_elements_per_transfer;
        }
        else
        {
            dma_config.burst_size = 0;
        }

        cy_rslt_t result = cyhal_dma_configure(&dma, &dma_config);
        CY_UNUSED_PARAMETER(result); /* CY_ASSERT only processes in DEBUG, ignores for others */
        CY_ASSERT(CY_RSLT_SUCCESS == result);
        result = cyhal_dma_enable(&dma);
        CY_ASSERT(CY_RSLT_SUCCESS == result);

        #if defined(_CY_SERIAL_FLASH_USING_XIP_MEMORY)
        result = cyhal_dma_start_transfer(&dma);
        CY_ASSERT(CY_RSLT_SUCCESS == result);
        #else
        /* Pass NULL for buffer (and callback) so that the function does not
         * set up FIFO interrupt. We don't need FIFO interrupt to be setup
         * since we will be using DMA.
         */
        _value_to_byte_array(read_txfr_info.addr, &addr_array[0], 0UL,
                             qspi_block_config.memConfig[MEM_SLOT]->deviceCfg->numOfAddrBytes);

        smif_status = Cy_SMIF_MemCmdRead(qspi_obj.base, qspi_block_config.memConfig[MEM_SLOT],
                                         addr_array, NULL, chunk, NULL, &qspi_obj.context);

        if (CY_SMIF_SUCCESS == smif_status)
        #endif /* defined(_CY_SERIAL_FLASH_USING_XIP_MEMORY) */
        {
            /* Recalculate the next rxBuffer offset */
            read_txfr_info.length -= chunk;
            read_txfr_info.addr += chunk;
            read_txfr_info.buf += chunk;
        }
    }

    return smif_status;
}


//--------------------------------------------------------------------------------------------------
// _init_dma
//--------------------------------------------------------------------------------------------------
static cy_rslt_t _init_dma(void)
{
    cy_rslt_t result = CY_RSLT_SUCCESS;

    #if !defined(_CY_SERIAL_FLASH_USING_XIP_MEMORY)
    cyhal_source_t source;
    _qspi_enable_rx_output(&qspi_obj, &source);
    #endif /* !defined(_CY_SERIAL_FLASH_USING_XIP_MEMORY) */

    #if !defined(_CY_SERIAL_FLASH_USING_XIP_MEMORY)
    cyhal_dma_src_t dma_src =
    {
        .source = source,
        .input  = CYHAL_DMA_INPUT_TRIGGER_ALL_ELEMENTS,
    };
    result = cyhal_dma_init_adv(&dma, &dma_src, NULL, NULL, 1, CYHAL_DMA_DIRECTION_PERIPH2MEM);
    #else /* defined(_CY_SERIAL_FLASH_USING_XIP_MEMORY) */
    result = cyhal_dma_init(&dma, 1, CYHAL_DMA_DIRECTION_MEM2MEM);
    #endif

    if (CY_RSLT_SUCCESS == result)
    {
        cyhal_dma_register_callback(&dma, _rx_dma_irq_handler, NULL);
        cyhal_dma_enable_event(&dma, (cyhal_dma_event_t)_CY_SERIAL_FLASH_ALL_DMA_EVENTS, 3, true);
    }

    return result;
}


//--------------------------------------------------------------------------------------------------
// _deinit_dma
//--------------------------------------------------------------------------------------------------
static cy_rslt_t _deinit_dma(void)
{
    cy_rslt_t result = CY_RSLT_SUCCESS;

    cyhal_dma_enable_event(&dma, (cyhal_dma_event_t)_CY_SERIAL_FLASH_ALL_DMA_EVENTS, 3, false);

    cyhal_dma_disable(&dma);
    cyhal_dma_free(&dma);

    return result;
}


//--------------------------------------------------------------------------------------------------
// _rx_dma_irq_handler
//--------------------------------------------------------------------------------------------------
static void _rx_dma_irq_handler(void* args, cyhal_dma_event_t events)
{
    CY_UNUSED_PARAMETER(args);

    cy_en_smif_status_t smif_status = CY_SMIF_SUCCESS;
    bool terminate_read_txfr = true;

    if (0 != (CYHAL_DMA_DESCRIPTOR_COMPLETE & events))
    {
        if (read_txfr_info.length > 0UL)
        {
            smif_status = _read_next_chunk();

            if (CY_SMIF_SUCCESS == smif_status)
            {
                terminate_read_txfr = false;
            }
        }
    }
    else
    {
        smif_status = (cy_en_smif_status_t)CY_RSLT_SERIAL_FLASH_ERR_DMA;
    }

    if (terminate_read_txfr)
    {
        cyhal_dma_disable(&dma);
        CLEAR_FLAG(FLAG_READ_IN_PROGRESS);

        /* Execute the callback */
        if (NULL != read_txfr_info.callback)
        {
            read_txfr_info.callback((cy_rslt_t)smif_status, read_txfr_info.callback_arg);
        }
    }
}


#if !defined(_CY_SERIAL_FLASH_USING_XIP_MEMORY)
/*******************************************************************************
* Function Name: _value_to_byte_array
****************************************************************************//**
*
* Unpacks the specified number of bytes from a 32-bit value into the given byte
* array.
*
* \param value
* The 32-bit (4-byte) value to unpack.
*
* \param byte_array
* The byte array to fill.
*
* \param start_pos
* The start position of the byte array to begin filling from.
*
* \param size
* The number of bytes to unpack.
*
*******************************************************************************/
static void _value_to_byte_array(uint32_t value, uint8_t* byte_array, uint32_t start_pos,
                                 uint32_t size)
{
    CY_ASSERT((0lu < size) && (CY_SMIF_FOUR_BYTES_ADDR >= size));
    CY_ASSERT(NULL != byte_array);

    do
    {
        size--;
        byte_array[size + start_pos] = (uint8_t)(value & LSB_MASK);
        value >>= MSB_SHIFT_EIGHT; /* Shift to get the next byte */
    } while (size > 0U);
}


//--------------------------------------------------------------------------------------------------
// _qspi_enable_rx_output
//--------------------------------------------------------------------------------------------------
static void _qspi_enable_rx_output(cyhal_qspi_t* obj, cyhal_source_t* source)
{
    cyhal_internal_source_t src_int;
    #if !defined(COMPONENT_CAT1D)
    CY_UNUSED_PARAMETER(obj);
    #endif // !defined(COMPONENT_CAT1D)
    #if defined(COMPONENT_CAT1C)
    src_int = (cyhal_internal_source_t)(_CYHAL_TRIGGER_SMIF0_TR_RX_REQ);
    #elif defined(COMPONENT_CAT1D)
    src_int =
        (cyhal_internal_source_t)(_CYHAL_TRIGGER_SMIF_SMIF0_TR_RX_REQ +
                                  obj->resource.block_num * 2);
    #else
    src_int = (cyhal_internal_source_t)(_CYHAL_TRIGGER_SMIF_TR_RX_REQ);
    #endif

    *source = (cyhal_source_t)_CYHAL_TRIGGER_CREATE_SOURCE(src_int, CYHAL_SIGNAL_TYPE_EDGE);
}


#endif // !defined(_CY_SERIAL_FLASH_USING_XIP_MEMORY)


//--------------------------------------------------------------------------------------------------
// _dma_get_max_elements_per_burst
//--------------------------------------------------------------------------------------------------
#if !defined(CYHAL_API_AVAILABLE_DMA_GET_MAX_ELEMENTS_PER_BURST)
static uint32_t _dma_get_max_elements_per_burst(cyhal_dma_t* obj)
{
    CY_ASSERT(NULL != obj);

    #if (_CYHAL_DRIVER_AVAILABLE_DMA_DMAC)
    #if (_CYHAL_DRIVER_AVAILABLE_DMA_DW)
    if (obj->resource.type == CYHAL_RSC_DMA)
    #endif
    {
        return CY_DMAC_LOOP_COUNT_MAX;
    }
    #endif
    #if (_CYHAL_DRIVER_AVAILABLE_DMA_DW)
    CY_ASSERT(obj->resource.type == CYHAL_RSC_DW);
    return CY_DMA_LOOP_COUNT_MAX;
    #endif
    // Should never get here during normal operation
    CY_ASSERT(0);
    return 0;
}


#endif /* !defined(CYHAL_API_AVAILABLE_DMA_GET_MAX_ELEMENTS_PER_BURST) */

#endif /* CYHAL_DRIVER_AVAILABLE_DMA */


//--------------------------------------------------------------------------------------------------
// _mutex_acquire
//--------------------------------------------------------------------------------------------------
static inline cy_rslt_t _mutex_acquire(void)
{
    #if defined(CY_SERIAL_FLASH_QSPI_THREAD_SAFE)
    return cy_rtos_get_mutex(&serial_flash_mutex, CY_RTOS_NEVER_TIMEOUT);
    #else
    return CY_RSLT_SUCCESS;
    #endif /* #if defined(CY_SERIAL_FLASH_QSPI_THREAD_SAFE) */
}


//--------------------------------------------------------------------------------------------------
// _mutex_release
//--------------------------------------------------------------------------------------------------
static inline cy_rslt_t _mutex_release(void)
{
    #if defined(CY_SERIAL_FLASH_QSPI_THREAD_SAFE)
    return cy_rtos_set_mutex(&serial_flash_mutex);
    #else
    return CY_RSLT_SUCCESS;
    #endif /* #if defined(CY_SERIAL_FLASH_QSPI_THREAD_SAFE) */
}


//--------------------------------------------------------------------------------------------------
// _qspi_is_busy
//--------------------------------------------------------------------------------------------------
#if !defined(CYHAL_API_AVAILABLE_QSPI_IS_BUSY)
bool _qspi_is_busy(cyhal_qspi_t* obj)
{
    CY_ASSERT(obj != NULL);
    CY_ASSERT(obj->base != NULL);

    uint32_t smif_status = Cy_SMIF_GetTransferStatus(obj->base, &(obj->context));
    return (Cy_SMIF_BusyCheck(obj->base) ||
            ((CY_SMIF_SEND_BUSY == smif_status) || (CY_SMIF_RX_BUSY == smif_status)));
}


#endif /* !defined(CYHAL_API_AVAILABLE_QSPI_IS_BUSY) */


//Temporarily commented out as only in SFDP mode it is needed. If specifying the qspi
// configuration
//device is already operating correctly. Issue tracked in
// https://jiracc.intra.infineon.com/browse/BSP-5762
// #if (CY_IP_MXSMIF_VERSION >= 5)
// //Necessary to solve errors in pipeline for products that have no RAM available for component
// CM55
// #if !defined(COMPONENT_CM55)
// CY_SECTION_RAMFUNC_BEGIN
// #endif /* !defined(COMPONENT_CM55) */
// //--------------------------------------------------------------------------------------------------
// // _enable_octal_mode_if_needed
// //--------------------------------------------------------------------------------------------------
// static cy_en_smif_status_t _enable_octal_mode_if_needed(void)
// {
//     cy_en_smif_status_t smif_status = CY_SMIF_SUCCESS;
//     if ((qspi_block_config.memConfig[MEM_SLOT]->deviceCfg->readCmd->dataWidth ==
//          CY_SMIF_WIDTH_OCTAL) ||
//         (qspi_block_config.memConfig[MEM_SLOT]->deviceCfg->programCmd->dataWidth ==
//          CY_SMIF_WIDTH_OCTAL))
//     {
//         cy_en_smif_data_rate_t dataRate;

//         if ((qspi_block_config.memConfig[MEM_SLOT]->deviceCfg->readCmd->dataRate ==
//              CY_SMIF_DDR) &&
//             (qspi_block_config.memConfig[MEM_SLOT]->deviceCfg->programCmd->dataRate ==
//              CY_SMIF_DDR))
//         {
//             dataRate = CY_SMIF_DDR;
//         }
//         else
//         {
//             dataRate = CY_SMIF_SDR;
//         }

//         smif_status =
//             Cy_SMIF_MemOctalEnable(qspi_obj.base,
//                                    qspi_block_config.memConfig[MEM_SLOT],
//                                    dataRate,
//                                    &qspi_obj.context);
//         if (CY_SMIF_SUCCESS == smif_status)
//         {
//             /* Disable IP */
//             Cy_SMIF_Disable(qspi_obj.base);

//             const cy_stc_smif_config_t smif_config =
//             {
//                 .mode          = (uint32_t)CY_SMIF_NORMAL,
//                 .deselectDelay = SMIF_OSPI_DESELECT_DELAY,
//                 .rxClockSel    = (uint32_t)CY_SMIF_SEL_INVERTED_FEEDBACK_CLK,
//                 .blockEvent    = (uint32_t)CY_SMIF_BUS_ERROR,
//             };

//             /* Re init IP */
//             smif_status = Cy_SMIF_Init(qspi_obj.base, &smif_config, 1000, &qspi_obj.context);

//             if (smif_status == CY_SMIF_SUCCESS)
//             {
//                 /* Set new Capture mode */
//                 Cy_SMIF_SetRxCaptureMode(qspi_obj.base, CY_SMIF_SEL_XSPI_HYPERBUS_WITH_DQS,
//                                          qspi_block_config.memConfig[MEM_SLOT]->slaveSelect);
//                 Cy_SMIF_SetDataSelect(qspi_obj.base,
//                                       qspi_block_config.memConfig[MEM_SLOT]->slaveSelect,
//                                       qspi_block_config.memConfig[MEM_SLOT]->dataSelect);
//                 Cy_SMIF_Enable(qspi_obj.base, &qspi_obj.context);
//             }
//         }
//     }

//     return smif_status;
// }


// //--------------------------------------------------------------------------------------------------
// // _set_capture_mode_to_normal_if_needed
// //--------------------------------------------------------------------------------------------------
// static cy_en_smif_status_t _set_capture_mode_to_normal_if_needed(void)
// {
//     cy_en_smif_status_t smif_status = CY_SMIF_SUCCESS;

//     if ((qspi_obj.base->CTL2 & SMIF_CORE_CTL2_RX_CAPTURE_MODE_Msk) >>
//         SMIF_CORE_CTL2_RX_CAPTURE_MODE_Pos ==
//         CY_SMIF_SEL_XSPI_HYPERBUS_WITH_DQS)
//     {
//         Cy_SMIF_Disable(qspi_obj.base);

//         const cy_stc_smif_config_t smif_config =
//         {
//             .mode          = (uint32_t)CY_SMIF_NORMAL,
//             .deselectDelay = SMIF_OSPI_DESELECT_DELAY,
//             .rxClockSel    = (uint32_t)CY_SMIF_SEL_INVERTED_FEEDBACK_CLK,
//             .blockEvent    = (uint32_t)CY_SMIF_BUS_ERROR,
//         };

//         /* Re init IP */
//         smif_status = Cy_SMIF_Init(qspi_obj.base, &smif_config, 1000, &qspi_obj.context);

//         if (smif_status == CY_SMIF_SUCCESS)
//         {
//             /* Set new Capture mode */
//             Cy_SMIF_SetRxCaptureMode(qspi_obj.base, CY_SMIF_SEL_NORMAL_SPI,
//                                      qspi_block_config.memConfig[MEM_SLOT]->slaveSelect);
//             Cy_SMIF_SetDataSelect(qspi_obj.base,
//                                   qspi_block_config.memConfig[MEM_SLOT]->slaveSelect,
//                                   qspi_block_config.memConfig[MEM_SLOT]->dataSelect);
//             Cy_SMIF_Enable(qspi_obj.base, &qspi_obj.context);
//         }
//     }
//     return smif_status;
// }


// #if !defined(COMPONENT_CM55)
// CY_SECTION_RAMFUNC_END
// #endif /* !defined(COMPONENT_CM55) */
// #endif /* (CY_IP_MXSMIF_VERSION >= 5) */


#if defined(__cplusplus)
}
#endif

#endif // CY_IP_MXSMIF
