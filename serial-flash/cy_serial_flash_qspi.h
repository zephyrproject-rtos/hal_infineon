/***********************************************************************************************//**
 * \file cy_serial_flash_qspi.h
 *
 * \brief
 * Provides APIs for interacting with an external flash connected to the SPI or
 * QSPI interface. Read is implemented as both blocking and non-blocking whereas
 * write, and erase are implemented as blocking functions.
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

/**
 * \addtogroup group_board_libs Serial Flash
 * \ingroup group_lib_impl
 * \{
 *
 * \section section_dma_qspi_frequency DMA vs QSPI frequencies consideration
 * When DMA-based functions are used (e.g. \ref cy_serial_flash_qspi_read_async), it is critical to
 * understand on what frequency DMA is operating and to configure QSPI frequency accordingly
 * (or vice versa - configure DMA frequency accoring to QSPI frequency being set). Recommendation is
 * to have QSPI clock not more than 2 times differ (lower or higher) comparing to DMA clock.
 *
 * \section section_dma_qspi_transfers_len DMA transfers data length constraints
 * Due to limitations of underlying DMA, DMA-based transfers (e.g. triggered with help ofis_busy
 * \ref cy_serial_flash_qspi_read_async) with length greater than 256, number of total elements to
 * be transferred should be divisible by 256, e.g. 512, 768, 1024, etc.
 *
 * \section section_serial_flash_pre_initialized Attaching to a preinitialized peripheral
 * For devices that don't have internal NVM or simply decide to store their code on an external
 * memory region, it is still possible to use the serial flash library to interface other memory
 * areas of that same external memory.
 * It is necessary to take precautions while doing so: first of all the configuration of the SMIF
 * peripheral should not be altered in a way that makes it interfere with the XIP of the core
 * region.
 * API \ref cy_serial_flash_qspi_attach is the API to use the existing SMIF configuration and
 * configure only the SMIF DEVICE for correctly being able to then use the read/write/erase
 * functionality of serial flash. The initialization of the memory device for octal memories
 * requires SMIF's rxCaptureMode to not be already setup in HyperBus with Data strobe line mode.
 * Therefore \ref cy_serial_flash_qspi_attach checks this setting of the SMIF and if needed changes
 * it back to Normal SPI. After the memory device initialization if the device requires to work
 * in octal mode then the code flow makes sure to restore the setting once more.
 * When wanting to free the serial flash object, function \ref cy_serial_flash_qspi_detach needs
 * to be used to free up the QSPI object but not interfere with the preexisting configuration of the
 * peripheral, rather than \ref cy_serial_flash_qspi_deinit.
 *
 */

#pragma once

#include <stddef.h>
#include "cy_result.h"
#include "cy_pdl.h"
#include "cyhal.h"

#ifdef CY_IP_MXSMIF

#if defined(__cplusplus)
extern "C" {
#endif

/** The function or operation is not supported on the target or the memory */
#define CY_RSLT_SERIAL_FLASH_ERR_UNSUPPORTED \
    (CY_RSLT_CREATE(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_BOARD_LIB_SERIAL_FLASH, 1))

/** Parameters passed to a function are invalid */
#define CY_RSLT_SERIAL_FLASH_ERR_BAD_PARAM \
    (CY_RSLT_CREATE(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_BOARD_LIB_SERIAL_FLASH, 2))

/** A previously initiated read operation is not yet complete */
#define CY_RSLT_SERIAL_FLASH_ERR_READ_BUSY \
    (CY_RSLT_CREATE(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_BOARD_LIB_SERIAL_FLASH, 3))

/** A DMA error occurred during read transfer */
#define CY_RSLT_SERIAL_FLASH_ERR_DMA \
    (CY_RSLT_CREATE(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_BOARD_LIB_SERIAL_FLASH, 4))

/** Read abort failed. QSPI block is busy. */
#define CY_RSLT_SERIAL_FLASH_ERR_QSPI_BUSY \
    (CY_RSLT_CREATE(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_BOARD_LIB_SERIAL_FLASH, 5))

#ifdef DOXYGEN
/** Enables thread-safety for use with multi-threaded RTOS environment. */
#define CY_SERIAL_FLASH_QSPI_THREAD_SAFE
#endif /* #ifdef DOXYGEN */

/**
 * Callback pointer to use with \ref cy_serial_flash_qspi_read_async().
 * \param operation_status Status of the read operation
 * \param callback_arg Pointer to be passed back to the callback function
 */
typedef void (* cy_serial_flash_qspi_read_complete_callback_t)(cy_rslt_t operation_status,
                                                               void* callback_arg);

/**
 * \brief Initializes the serial flash memory. This function accepts up to 8
 * I/Os. Number of I/Os depend on the type of memory interface. Pass NC when an
 * I/O is unused.
 * Single SPI - (io0, io1) or (io2, io3) or (io4, io5) or (io6, io7)
 * Dual SPI   - (io0, io1) or (io2, io3) or (io4, io5) or (io6, io7)
 * Quad SPI   - (io0, io1, io2, io3) or (io4, io5, io6, io7)
 * Octal SPI  - All 8 I/Os are used.
 * \param mem_config Memory configuration to be used for initializing
 * \param io0 Data/IO pin 0 connected to the memory, Pass NC when unused.
 * \param io1 Data/IO pin 1 connected to the memory, Pass NC when unused.
 * \param io2 Data/IO pin 2 connected to the memory, Pass NC when unused.
 * \param io3 Data/IO pin 3 connected to the memory, Pass NC when unused.
 * \param io4 Data/IO pin 4 connected to the memory, Pass NC when unused.
 * \param io5 Data/IO pin 5 connected to the memory, Pass NC when unused.
 * \param io6 Data/IO pin 6 connected to the memory, Pass NC when unused.
 * \param io7 Data/IO pin 7 connected to the memory, Pass NC when unused.
 * \param sclk Clock pin connected to the memory
 * \param ssel Slave select pin connected to the memory
 * \param hz Clock frequency to be used with the memory.
 * \returns CY_RSLT_SUCCESS if the initialization was successful, an error code
 *          otherwise.
 */
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
    uint32_t hz);

/**
 * \brief De-initializes the serial flash memory.
 * Before calling this function, ensure that an ongoing asynchronous read
 * operation is either completed or successfully aborted.
 * Async read is started by calling \ref cy_serial_flash_qspi_read_async() and
 * aborted by calling \ref cy_serial_flash_qspi_abort_read().
 */
void cy_serial_flash_qspi_deinit(void);

/**
 * \brief Returns the size of the serial flash memory in bytes.
 * \returns Memory size in bytes.
 */
size_t cy_serial_flash_qspi_get_size(void);

/**
 * \brief Returns the size of the erase sector to which the given address
 * belongs. Address is used only for a memory with hybrid sector size.
 * \param addr Address that belongs to the sector for which size is returned.
 * \returns Erase sector size in bytes.
 */
size_t cy_serial_flash_qspi_get_erase_size(uint32_t addr);

/**
 * \brief Returns the page size for programming of the sector to which the given
 * address belongs. Address is used only for a memory with hybrid sector size.
 * \param addr Address that belongs to the sector for which size is returned.
 * \returns Page size in bytes.
 */
size_t cy_serial_flash_qspi_get_prog_size(uint32_t addr);

/**
 * \brief Utility function to calculate the starting address of an erase sector
 * to which the given address belongs.
 * \param addr Address in the sector for which the starting address is returned.
 * \returns Starting address of the sector
 */
__STATIC_INLINE uint32_t cy_serial_flash_get_sector_start_address(uint32_t addr)
{
    return (addr & ~(cy_serial_flash_qspi_get_erase_size(addr) - 1));
}


/**
 * \brief Reads data from the serial flash memory. This is a blocking
 * function. Returns error if (addr + length) exceeds the flash size.
 * \param addr Starting address to read from
 * \param length Number of data bytes to read
 * \param buf Pointer to the buffer to store the data read from the memory
 * \returns CY_RSLT_SUCCESS if the read was successful, an error code otherwise.
 */
cy_rslt_t cy_serial_flash_qspi_read(uint32_t addr, size_t length, uint8_t* buf);

/**
 * \brief Reads data from the serial flash memory. This is a non-blocking
 * function. Returns error if (addr + length) exceeds the flash size.
 * Uses DMA for transferring the data from QSPI RX FIFO to the user-provided buffer.
 * \param addr Starting address to read from
 * \param length Number of data bytes to read
 * \param buf Pointer to the buffer to store the data read from the memory
 * \param callback Pointer to the callback function to be called after the read
 *        operation is complete. Callback is invoked from the DMA ISR.
 * \param callback_arg Pointer to the argument to be passed to the callback
 *        function
 * \returns CY_RSLT_SUCCESS if the read was successful, an error code otherwise.
 */
cy_rslt_t cy_serial_flash_qspi_read_async(uint32_t addr, size_t length, uint8_t* buf,
                                          cy_serial_flash_qspi_read_complete_callback_t callback,
                                          void* callback_arg);

/**
 * \brief Aborts an ongoing asynchronous read initiated by calling
 * \ref cy_serial_flash_qspi_read_async().
 *
 * \returns CY_RSLT_SUCCESS if the abort was successful, an error code
 *          if the QSPI block is still busy after a timeout.
 */
cy_rslt_t cy_serial_flash_qspi_abort_read(void);

/**
 * \brief Writes the data to the serial flash memory. The program area
 * must have been erased prior to calling this API using
 * \ref cy_serial_flash_qspi_erase() This is a blocking function. Returns error if
 * (addr + length) exceeds the flash size.
 * \param addr Starting address to write to
 * \param length Number of bytes to write
 * \param buf Pointer to the buffer storing the data to be written
 * \returns CY_RSLT_SUCCESS if the write was successful, an error code
 *          otherwise.
 */
cy_rslt_t cy_serial_flash_qspi_write(uint32_t addr, size_t length, const uint8_t* buf);

/**
 * \brief Erases the serial flash memory, uses chip erase command when
 * addr = 0 and length = flash_size otherwise uses sector erase command. This is
 * a blocking function. Returns error if addr or (addr + length) is not aligned
 * to the sector size or if (addr + length) exceeds the flash size.
 * For memories with hybrid sectors, returns error if the end address
 * (=addr + length) is not aligned to the size of the sector in which the end
 * address is located.
 * Call \ref cy_serial_flash_qspi_get_size() to get the flash size and
 * call \ref cy_serial_flash_qspi_get_erase_size() to get the size of an erase
 * sector.
 *
 * \param addr Starting address to begin erasing
 * \param length Number of bytes to erase
 * \returns CY_RSLT_SUCCESS if the erase was successful, an error code
 *          otherwise.
 */
cy_rslt_t cy_serial_flash_qspi_erase(uint32_t addr, size_t length);

/**
 * \brief Enables Execute-in-Place (memory mapped) mode on the MCU. This
 * function does not send any command to the serial flash. This may not be
 * supported on all the targets in which case
 * CY_RSLT_SERIAL_FLASH_ERR_UNSUPPORTED is returned.
 * \param enable true: XIP mode is set, false: normal mode is set
 * \returns CY_RSLT_SUCCESS if the operation was successful.
 *          CY_RSLT_SERIAL_FLASH_ERR_UNSUPPORTED if the target does not
 *          support XIP.
 */
cy_rslt_t cy_serial_flash_qspi_enable_xip(bool enable);

/**
 * \brief Changes QSPI interrupt priority
 * \param priority interrupt priority to be set
 */
void cy_serial_flash_qspi_set_interrupt_priority(uint8_t priority);

/**
 * \brief Changes the DMA interrupt priority
 * \param priority interrupt priority to be set
 */
void cy_serial_flash_qspi_set_dma_interrupt_priority(uint8_t priority);

#if defined(CYHAL_API_AVAILABLE_QSPI_ATTACH)
/**
 * \brief Attaches to a preinitialized serial flash memory. This function accepts up to 8
 * I/Os. Number of I/Os depend on the type of memory interface. Pass NC when an
 * I/O is unused.
 * Single SPI - (io0, io1) or (io2, io3) or (io4, io5) or (io6, io7)
 * Dual SPI   - (io0, io1) or (io2, io3) or (io4, io5) or (io6, io7)
 * Quad SPI   - (io0, io1, io2, io3) or (io4, io5, io6, io7)
 * Octal SPI  - All 8 I/Os are used.
 * \param mem_config Memory configuration to be used for initializing
 * \param io0 Data/IO pin 0 connected to the memory, Pass NC when unused.
 * \param io1 Data/IO pin 1 connected to the memory, Pass NC when unused.
 * \param io2 Data/IO pin 2 connected to the memory, Pass NC when unused.
 * \param io3 Data/IO pin 3 connected to the memory, Pass NC when unused.
 * \param io4 Data/IO pin 4 connected to the memory, Pass NC when unused.
 * \param io5 Data/IO pin 5 connected to the memory, Pass NC when unused.
 * \param io6 Data/IO pin 6 connected to the memory, Pass NC when unused.
 * \param io7 Data/IO pin 7 connected to the memory, Pass NC when unused.
 * \param ssel Slave select pin connected to the memory
 * \returns CY_RSLT_SUCCESS if the attach was successful, an error code
 *          otherwise.
 */
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
    cyhal_gpio_t ssel);

#endif /* if defined(CYHAL_API_AVAILABLE_QSPI_ATTACH)*/

#if defined(CYHAL_API_AVAILABLE_QSPI_DETACH)
/**
 * \brief Detach the serial flash memory.
 */
void cy_serial_flash_qspi_detach(void);
#endif /* if defined(CYHAL_API_AVAILABLE_QSPI_DETACH)*/

#if defined(__cplusplus)
}
#endif

#endif // CY_IP_MXSMIF

/** \} group_board_libs */
