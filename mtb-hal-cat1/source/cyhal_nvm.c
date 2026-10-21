/***************************************************************************//**
* \file cyhal_nvm.c
*
* Description:
* Provides a high level interface for interacting with the Infineon embedded
* non-volatile memory (NVM). This is wrapper around the lower level PDL API.
*
********************************************************************************
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
*******************************************************************************/

#include "cyhal_hwmgr.h"
#include "cyhal_hw_types.h"
#include "cyhal_nvm.h"
#include "cy_utils.h"
#include "cyhal_syspm.h"
#include "cyhal_utils_impl.h"
#include "cyhal_irq_impl.h"
#include <string.h>

#if (CYHAL_DRIVER_AVAILABLE_FLASH)
#include "cyhal_flash.h"
#endif /* (CYHAL_DRIVER_AVAILABLE_FLASH) */


#if (CYHAL_DRIVER_AVAILABLE_NVM)

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

#if (_CYHAL_DRIVER_AVAILABLE_NVM_FLASH)
static uint16_t _cyhal_nvm_init_count = 0;
typedef cy_en_flashdrv_status_t (*_cyhal_flash_operation)(uint32_t rowAddr, const uint32_t* data);

static bool _cyhal_flash_pm_callback(cyhal_syspm_callback_state_t state, cyhal_syspm_callback_mode_t mode, void* callback_arg);

#if defined(CPUSS_FLASHC_ECT)
#define _CYHAL_USES_ECT_FLASH (CPUSS_FLASHC_ECT == 1)
#else
#define _CYHAL_USES_ECT_FLASH (0u)
#endif

#if (_CYHAL_USES_ECT_FLASH)
#define _CYHAL_INTERNAL_FLASH_MEMORY_BLOCKS (4u)
#elif (CY_EM_EEPROM_SIZE > 0)
#define _CYHAL_INTERNAL_FLASH_MEMORY_BLOCKS (2u)
#else
#define _CYHAL_INTERNAL_FLASH_MEMORY_BLOCKS (1u)
#endif

static bool _cyhal_flash_pending_pm_change = false;

static cyhal_syspm_callback_data_t _cyhal_flash_internal_pm_cb = {
    .callback = _cyhal_flash_pm_callback,
    .states = (cyhal_syspm_callback_state_t)(CYHAL_SYSPM_CB_CPU_SLEEP | CYHAL_SYSPM_CB_CPU_DEEPSLEEP | CYHAL_SYSPM_CB_CPU_DEEPSLEEP_RAM | CYHAL_SYSPM_CB_SYSTEM_HIBERNATE | CYHAL_SYSPM_CB_SYSTEM_LOW),
    .next = NULL,
    .args = NULL,
    .ignore_modes = (cyhal_syspm_callback_mode_t)(CYHAL_SYSPM_AFTER_DS_WFI_TRANSITION),
};

static inline cy_rslt_t _cyhal_flash_convert_status(uint32_t pdl_status)
{
    return (pdl_status == CY_FLASH_DRV_OPERATION_STARTED) ? CY_RSLT_SUCCESS : pdl_status;
}

#if defined(CY_IP_S8SRSSLT) && CY_FLASH_NON_BLOCKING_SUPPORTED
static void _cyhal_flash_irq_handler(void)
{
    (void) Cy_Flash_ResumeWrite();
}
#endif

static bool _cyhal_flash_pm_callback(cyhal_syspm_callback_state_t state, cyhal_syspm_callback_mode_t mode, void* callback_arg)
{
    CY_UNUSED_PARAMETER(state);
    CY_UNUSED_PARAMETER(callback_arg);
    bool allow = true;

    switch (mode)
    {
        case CYHAL_SYSPM_CHECK_READY:
            _cyhal_flash_pending_pm_change = true;
            #if defined(CY_IP_MXS40SRSS) || (_CYHAL_USES_ECT_FLASH) || CY_FLASH_NON_BLOCKING_SUPPORTED
            if (CY_RSLT_SUCCESS != Cy_Flash_IsOperationComplete())
            {
                #if (_CYHAL_USES_ECT_FLASH)
                /* The SROM API response is invalid unless a flash operation has occurred at least once.
                   Therefore allow that case as an exception. */
                un_srom_api_resps_t resp = {{ 0UL }};
                cy_en_srom_api_status_t status = Cy_Srom_GetApiResponse(&resp);
                if(CY_SROM_STATUS_INVALID != status)
                #endif
                {
                    _cyhal_flash_pending_pm_change = false;
                    allow = false;
                }
            }
            #endif
            break;
        case CYHAL_SYSPM_BEFORE_TRANSITION:
        case CYHAL_SYSPM_AFTER_TRANSITION:
        case CYHAL_SYSPM_CHECK_FAIL:
            _cyhal_flash_pending_pm_change = false;
            break;
        default:
            /* Don't care */
            break;
    }

    return allow;
}

static inline bool _cyhal_flash_is_sram_address(uint32_t address)
{
    return ((CY_SRAM_BASE <= address) && (address < (CY_SRAM_BASE + CY_SRAM_SIZE)));
}

static cy_rslt_t _cyhal_flash_run_operation(
    _cyhal_flash_operation operation, uint32_t address, const uint32_t* data, bool clearCache)
{
    cy_rslt_t status;
    if (_cyhal_flash_pending_pm_change)
        status = CYHAL_SYSPM_RSLT_ERR_PM_PENDING;
    else
    {
        status = (_cyhal_flash_is_sram_address((uint32_t)data))
            ? (cy_rslt_t)_cyhal_flash_convert_status((cy_rslt_t)operation(address, data))
            : CYHAL_NVM_RSLT_ERR_ADDRESS;
#if defined(CY_IP_M7CPUSS) || defined (CY_IP_MXS40FLASHC) /* PDL automatically clears cache when necessary */
        CY_UNUSED_PARAMETER(clearCache);
#else
        if (clearCache)
        {
            Cy_SysLib_ClearFlashCacheAndBuffer();
        }
#endif
    }

    return status;
}

#endif /* #if (_CYHAL_DRIVER_AVAILABLE_NVM_FLASH) */

#if (_CYHAL_DRIVER_AVAILABLE_NVM_OTP)

#if (CY_RRAM_PROTECTED_OTP_SIZE > 0) && (CY_RRAM_GENERAL_OTP_SIZE > 0)
#define _CYHAL_INTERNAL_OTP_MEMORY_BLOCKS  (2u)
#else
#define _CYHAL_INTERNAL_OTP_MEMORY_BLOCKS  (1u)
#endif

#endif /* #if (_CYHAL_DRIVER_AVAILABLE_NVM_OTP) */

#if (_CYHAL_DRIVER_AVAILABLE_NVM_RRAM)

enum {
#if (CY_RRAM_WORK_REGION_SIZE > 0)
    _CYHAL_RRAM_WORK_REGION,
#endif
#if (CY_RRAM_SFLASH_REGION_SIZE > 0)
    _CYHAL_RRAM_SFLASH_REGION,
#endif
#if (CY_RRAM_PROTECTED_REGION_SIZE > 0)
    _CYHAL_RRAM_PROTECTED_REGION,
#endif
#if (CY_RRAM_MAIN_REGION_SIZE > 0)
    _CYHAL_RRAM_MAIN_REGION,
#endif
    _CYHAL_RRAM_REGION_COUNT
} _cyhal_rram_regions_count;

#define _CYHAL_INTERNAL_RRAM_MEMORY_BLOCKS      (_CYHAL_RRAM_REGION_COUNT)

__STATIC_INLINE bool _cyhal_rram_is_busy()
{
    return (bool)_FLD2VAL(RRAMC_RRAM_SFR_NVM_STATUS_BUSY, RRAM_NVM_STATUS(RRAMC0));
}

#endif /* #if (_CYHAL_DRIVER_AVAILABLE_NVM_RRAM) */


#ifndef _CYHAL_INTERNAL_FLASH_MEMORY_BLOCKS
#define _CYHAL_INTERNAL_FLASH_MEMORY_BLOCKS     (0)
#endif /* (_CYHAL_INTERNAL_FLASH_MEMORY_BLOCKS) */

#ifndef _CYHAL_INTERNAL_RRAM_MEMORY_BLOCKS
#define _CYHAL_INTERNAL_RRAM_MEMORY_BLOCKS      (0)
#endif /* (_CYHAL_INTERNAL_RRAM_MEMORY_BLOCKS) */

#ifndef _CYHAL_INTERNAL_OTP_MEMORY_BLOCKS
#define _CYHAL_INTERNAL_OTP_MEMORY_BLOCKS       (0)
#endif /* (_CYHAL_INTERNAL_OTP_MEMORY_BLOCKS) */


#define _CYHAL_NVM_MEMORY_BLOCKS_COUNT  (_CYHAL_INTERNAL_FLASH_MEMORY_BLOCKS + \
                                         _CYHAL_INTERNAL_RRAM_MEMORY_BLOCKS + \
                                         _CYHAL_INTERNAL_OTP_MEMORY_BLOCKS)


static const cyhal_nvm_region_info_t _cyhal_nvm_mem_regions[_CYHAL_NVM_MEMORY_BLOCKS_COUNT] = {
#if (_CYHAL_DRIVER_AVAILABLE_NVM_FLASH)
    #if _CYHAL_USES_ECT_FLASH
        /* Each flash area is divided into two regions: A "large" region with 2KB sectors and a
        * "small" region with 128b sectors. The flash can be configured in either single- or
        * double-bank mode. In double-bank mode, the flash is divided into two sub-regions such
        * that it is possible to read from one region while writing to another region. Because
        * dual-bank mode is highly device specific, for simplicity we stick to single-bank mode
        * in the portable HAL driver */
        // Large main flash region, 32KB sectors
        {
            .nvm_type = CYHAL_NVM_TYPE_FLASH,
            .start_address = CY_FLASH_LG_SBM_BASE,
            .size = CY_FLASH_LG_SBM_SIZE,
            .sector_size = 32768u,
            .block_size = 8u,
            .is_erase_required = true,
            .erase_value = 0xFFU,
        },
        // Small main flash region, 8KB sectors
        {
            .nvm_type = CYHAL_NVM_TYPE_FLASH,
            .start_address = CY_FLASH_SM_SBM_BASE,
            .size = CY_FLASH_SM_SBM_SIZE,
            .sector_size = 8192u,
            .block_size = 8u,
            .is_erase_required = true,
            .erase_value = 0xFFU,
        },
        // Large wflash region, 32KB sectors
        {
            .nvm_type = CYHAL_NVM_TYPE_FLASH,
            .start_address = CY_WFLASH_LG_SBM_BASE,
            .size = CY_WFLASH_LG_SBM_SIZE,
            .sector_size = 2048u, /* Hard-coded in the IP */
            .block_size = 4u,
            .is_erase_required = true,
            .erase_value = 0xFFU,
        },
        // Small wflash region, 128B sectors
        {
            .nvm_type = CYHAL_NVM_TYPE_FLASH,
            .start_address = CY_WFLASH_SM_SBM_BASE,
            .size = CY_WFLASH_SM_SBM_SIZE,
            .sector_size = 128u,
            .block_size = 4u,
            .is_erase_required = true,
            .erase_value = 0xFFU,
        },
    #else
        // Main Flash
        {
            .nvm_type = CYHAL_NVM_TYPE_FLASH,
            .start_address = CY_FLASH_BASE,
            .size = CY_FLASH_SIZE,
            .sector_size = CY_FLASH_SIZEOF_ROW,
            .block_size = CY_FLASH_SIZEOF_ROW,
            .is_erase_required = true,
            .erase_value = 0x00U,
        },
        // Working Flash
        #if (CY_EM_EEPROM_SIZE > 0)
            {
                .nvm_type = CYHAL_NVM_TYPE_FLASH,
                .start_address = CY_EM_EEPROM_BASE,
                .size = CY_EM_EEPROM_SIZE,
                .sector_size = CY_FLASH_SIZEOF_ROW,
                .block_size = CY_FLASH_SIZEOF_ROW,
                .is_erase_required = true,
                .erase_value = 0x00U,
            },
        #endif
    #endif /* CY_IP_M7CPUSS or other */
#endif /* (_CYHAL_DRIVER_AVAILABLE_NVM_FLASH) */

#if (_CYHAL_DRIVER_AVAILABLE_NVM_RRAM)
    #if (CY_RRAM_MAIN_REGION_SIZE > 0)
        // Main RRAM region, 8KB sectors
        {
            .nvm_type = CYHAL_NVM_TYPE_RRAM,
            .start_address = CY_RRAM_MAIN_HOST_NS_START_ADDRESS,
            .size = CY_RRAM_MAIN_REGION_SIZE,
            .sector_size = CY_RRAM_REGION_SIZE_UNIT,
            .block_size = CY_RRAM_BLOCK_SIZE_BYTES,
            .is_erase_required = false,
            .erase_value = 0x00U,
        },
    #endif /* (CY_RRAM_MAIN_REGION_SIZE > 0) */
    #if (CY_RRAM_WORK_REGION_SIZE > 0)
        // Work RRAM region, 8KB sectors
        {
            .nvm_type = CYHAL_NVM_TYPE_RRAM,
            .start_address = CY_RRAM_WORK_HOST_NS_START_ADDRESS,
            .size = CY_RRAM_WORK_REGION_SIZE,
            .sector_size = CY_RRAM_REGION_SIZE_UNIT,
            .block_size = CY_RRAM_BLOCK_SIZE_BYTES,
            .is_erase_required = false,
            .erase_value = 0x00U,
        },
    #endif /* (CY_RRAM_WORK_REGION_SIZE > 0) */
    #if (CY_RRAM_SFLASH_REGION_SIZE > 0)
        // SFALSH RRAM region, 8KB sectors
        {
            .nvm_type = CYHAL_NVM_TYPE_RRAM,
            .start_address = CY_RRAM_SFLASH_HOST_NS_START_ADDRESS,
            .size = CY_RRAM_SFLASH_REGION_SIZE,
            .sector_size = CY_RRAM_REGION_SIZE_UNIT,
            .block_size = CY_RRAM_BLOCK_SIZE_BYTES,
            .is_erase_required = false,
            .erase_value = 0x00U,
        },
    #endif /* (CY_RRAM_SFLASH_REGION_SIZE > 0) */
    #if (CY_RRAM_PROTECTED_REGION_SIZE > 0)
        // SFALSH RRAM region, 8KB sectors
        {
            .nvm_type = CYHAL_NVM_TYPE_RRAM,
            .start_address = CY_RRAM_PROTECTED_HOST_NS_START_ADDRESS,
            .size = CY_RRAM_PROTECTED_REGION_SIZE,
            .sector_size = CY_RRAM_REGION_SIZE_UNIT,
            .block_size = CY_RRAM_BLOCK_SIZE_BYTES,
            .is_erase_required = false,
            .erase_value = 0x00U,
        },
    #endif /* (CY_RRAM_PROTECTED_REGION_SIZE > 0) */
#endif /* (_CYHAL_DRIVER_AVAILABLE_NVM_RRAM) */

#if (_CYHAL_DRIVER_AVAILABLE_NVM_OTP)
    #if (CY_RRAM_GENERAL_OTP_SIZE > 0)
        // General RRAM OTP region, 5.5KB sector
        {
            .nvm_type = CYHAL_NVM_TYPE_OTP,
            .start_address = CY_RRAM_GENERAL_OTP_MMIO_NS_START_ADDRESS,
            .size = CY_RRAM_GENERAL_OTP_SIZE,
            .sector_size = 5632u,
            .block_size = CY_RRAM_BLOCK_SIZE_BYTES,
            .is_erase_required = false,
            .erase_value = 0xFFU,
        },
    #endif /* (CY_RRAM_GENERAL_OTP_SIZE > 0) */
    #if (CY_RRAM_PROTECTED_OTP_SIZE > 0)
        // Protected RRAM OTP region, 8KB sector
        {
            .nvm_type = CYHAL_NVM_TYPE_OTP,
            .start_address = CY_RRAM_PROTECTED_OTP_PROTECTED_NS_START_ADDRESS,
            .size = CY_RRAM_PROTECTED_OTP_SIZE,
            .sector_size = 8192u,
            .block_size = CY_RRAM_BLOCK_SIZE_BYTES,
            .is_erase_required = false,
            .erase_value = 0xFFU,
        },
    #endif /* (CY_RRAM_PROTECTED_OTP_SIZE > 0) */
#endif /* (_CYHAL_DRIVER_AVAILABLE_NVM_OTP) */
};


static inline bool _cyhal_nvm_address_in_region(uint32_t address, const cyhal_nvm_region_info_t* region_info)
{
    return (address >= region_info->start_address && address < (region_info->start_address + region_info->size));
}

static bool _cyhal_nvm_get_nvm_region_by_boundaries(uint32_t start_address, uint32_t end_address, cyhal_nvm_region_info_t *block_info)
{
    bool start_address_valid = false;
    bool end_address_valid = false;
    bool end_address_check_need = (end_address == 0) ? false : true;
    memset(block_info, 0, sizeof(*block_info));

    for (uint32_t region_id = 0; region_id < _CYHAL_NVM_MEMORY_BLOCKS_COUNT; region_id++)
    {
        start_address_valid = _cyhal_nvm_address_in_region(start_address, &_cyhal_nvm_mem_regions[region_id]);
        end_address_valid = (!end_address_check_need) ? true :
            _cyhal_nvm_address_in_region(end_address, &_cyhal_nvm_mem_regions[region_id]);
        if (start_address_valid && end_address_valid)
        {
            *block_info = _cyhal_nvm_mem_regions[region_id];
            block_info->offset = start_address - _cyhal_nvm_mem_regions[region_id].start_address;
            break;
        }
    }

    return (start_address_valid && end_address_valid);
}

static inline bool _cyhal_nvm_get_nvm_region_by_address(uint32_t address, cyhal_nvm_region_info_t *region_info)
{
    return _cyhal_nvm_get_nvm_region_by_boundaries(address, 0, region_info);
}

/*******************************************************************************
*       Functions
*******************************************************************************/

cy_rslt_t cyhal_nvm_init(cyhal_nvm_t *obj)
{
    CY_ASSERT(NULL != obj);
    CY_UNUSED_PARAMETER(obj);

    cy_rslt_t status = CYHAL_NVM_RSLT_ERR_NOT_SUPPORTED;

#if (_CYHAL_DRIVER_AVAILABLE_NVM_FLASH)
#if defined(CY_IP_S8SRSSLT) && CY_FLASH_NON_BLOCKING_SUPPORTED
    /* Configure Flash interrupt */
    _cyhal_irq_register(cpuss_interrupt_spcif_IRQn, 0u, &_cyhal_flash_irq_handler);
    _cyhal_irq_enable(cpuss_interrupt_spcif_IRQn);
#endif /* defined(CY_IP_S8SRSSLT) && CY_FLASH_NON_BLOCKING_SUPPORTED */
    if(_cyhal_nvm_init_count == 0)
    {
    #if _CYHAL_USES_ECT_FLASH
        // Cy_Flash_Init is only safe to call a single time after the SysPm HAL
        // has been initialized (or anything else in the application has registered
        // a callback). It unconditionally re-initializes its callback struct each
        // time, which would remove any callbacks registered with lower priority.
        static bool flash_initialized = false;
        if(false == flash_initialized)
        {
            flash_initialized = true;
            Cy_Flash_Init();
        }
        // Always call this, because `cyhal_nvm_free` disables the work flash write
        Cy_Flashc_WorkWriteEnable();
    #endif /* _CYHAL_USES_ECT_FLASH */
    _cyhal_syspm_register_peripheral_callback(&_cyhal_flash_internal_pm_cb);
    }
    _cyhal_nvm_init_count++;
    status = CY_RSLT_SUCCESS;
#endif /* #if (_CYHAL_DRIVER_AVAILABLE_NVM_FLASH) */

#if (_CYHAL_DRIVER_AVAILABLE_NVM_RRAM)
    /* Nothing to do for RRAM initialization */
    status = CY_RSLT_SUCCESS;
#endif /* #if (_CYHAL_DRIVER_AVAILABLE_NVM_RRAM) */

#if (_CYHAL_DRIVER_AVAILABLE_NVM_OTP)
    /* Nothing to do for RRAM initialization */
    status = CY_RSLT_SUCCESS;
#endif /* #if (_CYHAL_DRIVER_AVAILABLE_NVM_OTP) */

    return status;
}

void cyhal_nvm_free(cyhal_nvm_t *obj)
{
    CY_ASSERT(NULL != obj);
    CY_UNUSED_PARAMETER(obj);

#if (_CYHAL_DRIVER_AVAILABLE_NVM_FLASH)
#if defined(CY_IP_S8SRSSLT) && CY_FLASH_NON_BLOCKING_SUPPORTED
    _cyhal_irq_free(cpuss_interrupt_spcif_IRQn);
#endif /* defined(CY_IP_S8SRSSLT) && CY_FLASH_NON_BLOCKING_SUPPORTED */
    CY_ASSERT(_cyhal_nvm_init_count > 0);
    _cyhal_nvm_init_count--;
    if(_cyhal_nvm_init_count == 0)
    {
        _cyhal_syspm_unregister_peripheral_callback(&_cyhal_flash_internal_pm_cb);
    #if _CYHAL_USES_ECT_FLASH
        Cy_Flashc_WorkWriteDisable();
    #endif /* _CYHAL_USES_ECT_FLASH */
    }
#endif /* #if (_CYHAL_DRIVER_AVAILABLE_NVM_FLASH) */

#if (_CYHAL_DRIVER_AVAILABLE_NVM_RRAM)
    /* Nothing to do for RRAM deinitialization */
#endif /* #if (_CYHAL_DRIVER_AVAILABLE_NVM_RRAM) */

#if (_CYHAL_DRIVER_AVAILABLE_NVM_OTP)
    /* Nothing to do for OTP deinitialization */
#endif /* #if (_CYHAL_DRIVER_AVAILABLE_NVM_OTP) */
}

void cyhal_nvm_get_info(cyhal_nvm_t *obj, cyhal_nvm_info_t *info)
{
    CY_ASSERT(NULL != obj);
    CY_ASSERT(NULL != info);
    CY_UNUSED_PARAMETER(obj);

    info->region_count = _CYHAL_NVM_MEMORY_BLOCKS_COUNT;
    info->regions = &_cyhal_nvm_mem_regions[0];
}

cy_rslt_t cyhal_nvm_read(cyhal_nvm_t *obj, uint32_t address, uint8_t *data, size_t size)
{
    CY_ASSERT(NULL != obj);
    CY_UNUSED_PARAMETER(obj);

    cyhal_nvm_region_info_t _cyhal_nvm_current_block_info;
    cy_rslt_t status = CYHAL_NVM_RSLT_ERR_NOT_SUPPORTED;

    bool is_address_valid = false;
    is_address_valid = _cyhal_nvm_get_nvm_region_by_boundaries(address, (address + size - 1), &_cyhal_nvm_current_block_info);

    if (!is_address_valid)
    {
        status = CYHAL_NVM_RSLT_ERR_ADDRESS;
    }
    else
    {
        if (CYHAL_NVM_TYPE_FLASH == _cyhal_nvm_current_block_info.nvm_type)
        {
        #if (_CYHAL_DRIVER_AVAILABLE_NVM_FLASH)
            memcpy((void *)data, (void *)address, size);
            status = CY_RSLT_SUCCESS;
        #endif /* #if (_CYHAL_DRIVER_AVAILABLE_NVM_FLASH) */
        }
        else if (CYHAL_NVM_TYPE_RRAM == _cyhal_nvm_current_block_info.nvm_type)
        {
        #if (_CYHAL_DRIVER_AVAILABLE_NVM_RRAM)
            status = (cy_rslt_t)Cy_RRAM_NvmReadByteArray(RRAMC0, address, data, size);
        #endif /* #if (_CYHAL_DRIVER_AVAILABLE_NVM_RRAM) */
        }
        else if (CYHAL_NVM_TYPE_OTP == _cyhal_nvm_current_block_info.nvm_type)
        {
        #if (_CYHAL_DRIVER_AVAILABLE_NVM_OTP)
            status = (cy_rslt_t)Cy_RRAM_OtpReadByteArray(RRAMC0, address, data, size);
        #endif /* (_CYHAL_DRIVER_AVAILABLE_NVM_OTP) */
        }
        else
        {
            /* Not supported type of NVM */
            CY_UNUSED_PARAMETER(address);
            CY_UNUSED_PARAMETER(data);
            CY_UNUSED_PARAMETER(size);
            status = CYHAL_NVM_RSLT_ERR_NOT_SUPPORTED;
        }
    }
    return status;
}

cy_rslt_t cyhal_nvm_erase(cyhal_nvm_t *obj, uint32_t address)
{
    CY_ASSERT(NULL != obj);
    CY_UNUSED_PARAMETER(obj);

    cyhal_nvm_region_info_t _cyhal_nvm_current_block_info;
    cy_rslt_t status = CYHAL_NVM_RSLT_ERR_NOT_SUPPORTED;

    bool is_address_valid = false;
    is_address_valid = _cyhal_nvm_get_nvm_region_by_address(address, &_cyhal_nvm_current_block_info);

    if (!is_address_valid)
    {
        status = CYHAL_NVM_RSLT_ERR_ADDRESS;
    }
    else
    {
        #if defined (__DCACHE_PRESENT) && (__DCACHE_PRESENT == 1U)
        SCB_InvalidateDCache_by_Addr((void *)address, _cyhal_nvm_current_block_info.sector_size);
        #endif
        if (CYHAL_NVM_TYPE_FLASH == _cyhal_nvm_current_block_info.nvm_type)
        {
        #if (defined(CY_IP_MXS40SRSS) || (_CYHAL_USES_ECT_FLASH)) && (_CYHAL_DRIVER_AVAILABLE_NVM_FLASH)
            if (_cyhal_flash_pending_pm_change)
            {
                status = CYHAL_SYSPM_RSLT_ERR_PM_PENDING;
            }
            else
            {
            #if (_CYHAL_USES_ECT_FLASH) 
                /* This IP does not support row-at-a-time erase */
                status = (cy_rslt_t)_cyhal_flash_convert_status(Cy_Flash_EraseSector(address));
            #else
                status = (cy_rslt_t)_cyhal_flash_convert_status(Cy_Flash_EraseRow(address));
            #endif
			
        #if !defined(CY_IP_M7CPUSS) && !defined (CY_IP_MXS40FLASHC)
				Cy_SysLib_ClearFlashCacheAndBuffer();
			#endif
			/* PDL automatically clears cache when necessary in M7 devices */
            }
        #else
            status = CYHAL_NVM_RSLT_ERR_NOT_SUPPORTED;
        #endif /* (defined(CY_IP_MXS40SRSS) || (_CYHAL_USES_ECT_FLASH)) && (_CYHAL_DRIVER_AVAILABLE_NVM_FLASH) */
        }
        else if (CYHAL_NVM_TYPE_RRAM == _cyhal_nvm_current_block_info.nvm_type)
        {
            /* Erase operation not needed for RRAM */
            status = CY_RSLT_SUCCESS;
        }
        else if (CYHAL_NVM_TYPE_OTP == _cyhal_nvm_current_block_info.nvm_type)
        {
            /* Not supported for OTP */
            status = CYHAL_NVM_RSLT_ERR_NOT_SUPPORTED;
        }
        else
        {
            /* Not supported type of NVM */
            CY_UNUSED_PARAMETER(address);
            status = CYHAL_NVM_RSLT_ERR_NOT_SUPPORTED;
        }
    }
    return status;
}

cy_rslt_t cyhal_nvm_write(cyhal_nvm_t *obj, uint32_t address, const uint32_t* data)
{
    CY_ASSERT(NULL != obj);
    CY_UNUSED_PARAMETER(obj);

    cyhal_nvm_region_info_t _cyhal_nvm_current_block_info;
    cy_rslt_t status = CYHAL_NVM_RSLT_ERR_NOT_SUPPORTED;

    bool is_address_valid = false;
    is_address_valid = _cyhal_nvm_get_nvm_region_by_address(address, &_cyhal_nvm_current_block_info);

    if (!is_address_valid)
    {
        status = CYHAL_NVM_RSLT_ERR_ADDRESS;
    }
    else
    {
        if (CYHAL_NVM_TYPE_FLASH == _cyhal_nvm_current_block_info.nvm_type)
        {
        #if !(_CYHAL_USES_ECT_FLASH) && (_CYHAL_DRIVER_AVAILABLE_NVM_FLASH)
            status = _cyhal_flash_run_operation(Cy_Flash_WriteRow, address, data, true);
        #else
            /* CY_IP_M7CPUSS does not support a bundled write (erase + program) operation. Instead,
            * it is necessary to perform an erase operation followed by a program operation.
            */
            CY_UNUSED_PARAMETER(address);
            CY_UNUSED_PARAMETER(data);
            status = CYHAL_NVM_RSLT_ERR_NOT_SUPPORTED;
        #endif /* !(_CYHAL_USES_ECT_FLASH) && (_CYHAL_DRIVER_AVAILABLE_NVM_FLASH) */
        }
        else if (CYHAL_NVM_TYPE_RRAM == _cyhal_nvm_current_block_info.nvm_type)
        {
        #if (_CYHAL_DRIVER_AVAILABLE_NVM_RRAM)
            status = (cy_rslt_t)Cy_RRAM_NvmWriteBlock(RRAMC0, address, (uint8_t *)data);
        #endif /* #if (_CYHAL_DRIVER_AVAILABLE_NVM_RRAM) */
        }
        else if (CYHAL_NVM_TYPE_OTP == _cyhal_nvm_current_block_info.nvm_type)
        {
            /* Not supported for OTP */
            status = CYHAL_NVM_RSLT_ERR_NOT_SUPPORTED;
        }
        else
        {
            /* Not supported type of NVM */
            status = CYHAL_NVM_RSLT_ERR_NOT_SUPPORTED;
        }
    }
    return status;
}

cy_rslt_t cyhal_nvm_otp_write(cyhal_nvm_t* obj, uint32_t address, uint8_t data)
{
    CY_ASSERT(NULL != obj);
    CY_UNUSED_PARAMETER(obj);

    cyhal_nvm_region_info_t _cyhal_nvm_current_block_info;
    cy_rslt_t status = CYHAL_NVM_RSLT_ERR_NOT_SUPPORTED;

    bool is_address_valid = false;
    is_address_valid = _cyhal_nvm_get_nvm_region_by_address(address, &_cyhal_nvm_current_block_info);

    if (!is_address_valid)
    {
        status = CYHAL_NVM_RSLT_ERR_ADDRESS;
    }
    else
    {
        if (CYHAL_NVM_TYPE_OTP == _cyhal_nvm_current_block_info.nvm_type)
        {
        #if (_CYHAL_DRIVER_AVAILABLE_NVM_OTP)
            status = (cy_rslt_t)Cy_RRAM_OtpWriteByteArray(RRAMC0, address, (const uint8_t *)&data, 1UL);
        #endif /* (_CYHAL_DRIVER_AVAILABLE_NVM_OTP) */
        }
        else
        {
            /* Not supported type of NVM */
            CY_UNUSED_PARAMETER(data);
            status = CYHAL_NVM_RSLT_ERR_NOT_SUPPORTED;
        }
    }
    return status;
}

cy_rslt_t cyhal_nvm_program(cyhal_nvm_t *obj, uint32_t address, const uint32_t *data)
{
    CY_ASSERT(NULL != obj);
    CY_UNUSED_PARAMETER(obj);

    cyhal_nvm_region_info_t _cyhal_nvm_current_block_info;
    cy_rslt_t status = CYHAL_NVM_RSLT_ERR_NOT_SUPPORTED;

    bool is_address_valid = false;
    is_address_valid = _cyhal_nvm_get_nvm_region_by_address(address, &_cyhal_nvm_current_block_info);

    if (!is_address_valid)
    {
        status = CYHAL_NVM_RSLT_ERR_ADDRESS;
    }
    else
    {
        #if defined (__DCACHE_PRESENT) && (__DCACHE_PRESENT == 1U)
        SCB_CleanDCache_by_Addr((void *)data, _cyhal_nvm_current_block_info.block_size);
        SCB_InvalidateDCache_by_Addr((void *)address, _cyhal_nvm_current_block_info.block_size);
        #endif
        if (CYHAL_NVM_TYPE_FLASH == _cyhal_nvm_current_block_info.nvm_type)
        {
        #if (defined(CY_IP_MXS40SRSS) || (_CYHAL_USES_ECT_FLASH)) && (_CYHAL_DRIVER_AVAILABLE_NVM_FLASH)
            status = _cyhal_flash_run_operation(Cy_Flash_ProgramRow, address, data, true);
        #endif /* (defined(CY_IP_MXS40SRSS) || (_CYHAL_USES_ECT_FLASH)) && (_CYHAL_DRIVER_AVAILABLE_NVM_FLASH) */
        }
        else if (CYHAL_NVM_TYPE_RRAM == _cyhal_nvm_current_block_info.nvm_type)
        {
        #if (_CYHAL_DRIVER_AVAILABLE_NVM_RRAM)
            status = (cy_rslt_t)Cy_RRAM_NvmWriteBlock(RRAMC0, address, (uint8_t *)data);
        #endif /* #if (_CYHAL_DRIVER_AVAILABLE_NVM_RRAM) */
        }
        else if (CYHAL_NVM_TYPE_OTP == _cyhal_nvm_current_block_info.nvm_type)
        {
            /* Not supported for OTP */
            status = CYHAL_NVM_RSLT_ERR_NOT_SUPPORTED;
        }
        else
        {
            /* Not supported type of NVM */
            CY_UNUSED_PARAMETER(address);
            CY_UNUSED_PARAMETER(data);
            status = CYHAL_NVM_RSLT_ERR_NOT_SUPPORTED;
        }
    }
    return status;
}

cy_rslt_t cyhal_nvm_start_erase(cyhal_nvm_t *obj, uint32_t address)
{
    CY_ASSERT(NULL != obj);
    CY_UNUSED_PARAMETER(obj);

    cyhal_nvm_region_info_t _cyhal_nvm_current_block_info;
    cy_rslt_t status = CYHAL_NVM_RSLT_ERR_NOT_SUPPORTED;

    bool is_address_valid = false;
    is_address_valid = _cyhal_nvm_get_nvm_region_by_address(address, &_cyhal_nvm_current_block_info);

    if (!is_address_valid)
    {
        status = CYHAL_NVM_RSLT_ERR_ADDRESS;
    }
    else
    {
        if (CYHAL_NVM_TYPE_FLASH == _cyhal_nvm_current_block_info.nvm_type)
        {
        #if defined(CY_IP_MXS40SRSS) && (_CYHAL_DRIVER_AVAILABLE_NVM_FLASH)
            if (_cyhal_flash_pending_pm_change)
            {
                status = CYHAL_SYSPM_RSLT_ERR_PM_PENDING;
            }
            else
            {
                status = (cy_rslt_t)_cyhal_flash_convert_status(
            #if _CYHAL_USES_ECT_FLASH
                    Cy_Flash_StartEraseSector(address)
            #else
                    Cy_Flash_StartEraseRow(address)
            #endif
                    );
            }
        #endif /* defined(CY_IP_MXS40SRSS) && (_CYHAL_DRIVER_AVAILABLE_NVM_FLASH) */
        }
        else if (CYHAL_NVM_TYPE_RRAM == _cyhal_nvm_current_block_info.nvm_type)
        {
            /* Erase operation not needed for RRAM */
            status = CY_RSLT_SUCCESS;
        }
        else if (CYHAL_NVM_TYPE_OTP == _cyhal_nvm_current_block_info.nvm_type)
        {
            /* Not supported for OTP */
            status = CYHAL_NVM_RSLT_ERR_NOT_SUPPORTED;
        }
        else
        {
            /* Not supported type of NVM */
            CY_UNUSED_PARAMETER(address);
            status = CYHAL_NVM_RSLT_ERR_NOT_SUPPORTED;
        }
    }
    return status;
}

cy_rslt_t cyhal_nvm_start_write(cyhal_nvm_t *obj, uint32_t address, const uint32_t* data)
{
    CY_ASSERT(NULL != obj);
    CY_UNUSED_PARAMETER(obj);

    cyhal_nvm_region_info_t _cyhal_nvm_current_block_info;
    cy_rslt_t status = CYHAL_NVM_RSLT_ERR_NOT_SUPPORTED;

    bool is_address_valid = false;
    is_address_valid = _cyhal_nvm_get_nvm_region_by_address(address, &_cyhal_nvm_current_block_info);

    if (!is_address_valid)
    {
        status = CYHAL_NVM_RSLT_ERR_ADDRESS;
    }
    else
    {
        if (CYHAL_NVM_TYPE_FLASH == _cyhal_nvm_current_block_info.nvm_type)
        {
            /* M7CPUSS does not support write, only erase + program */
        #if ((defined(CY_IP_MXS40SRSS) && !(_CYHAL_USES_ECT_FLASH)) || CY_FLASH_NON_BLOCKING_SUPPORTED) && (_CYHAL_DRIVER_AVAILABLE_NVM_FLASH)
            status = _cyhal_flash_run_operation(Cy_Flash_StartWrite, address, data, false);
        #else
            CY_UNUSED_PARAMETER(address);
            CY_UNUSED_PARAMETER(data);
            status = CYHAL_NVM_RSLT_ERR_NOT_SUPPORTED;
        #endif /* ((defined(CY_IP_MXS40SRSS) && !(_CYHAL_USES_ECT_FLASH)) || CY_FLASH_NON_BLOCKING_SUPPORTED) && (_CYHAL_DRIVER_AVAILABLE_NVM_FLASH)*/
        }
        else if (CYHAL_NVM_TYPE_RRAM == _cyhal_nvm_current_block_info.nvm_type)
        {
        #if (_CYHAL_DRIVER_AVAILABLE_NVM_RRAM)
            status = (cy_rslt_t)Cy_RRAM_NonBlockingNvmWriteByteArray(
                        RRAMC0, address, (const uint8_t *)data, _cyhal_nvm_current_block_info.block_size);
        #endif /* #if (_CYHAL_DRIVER_AVAILABLE_NVM_RRAM) */
        }
        else if (CYHAL_NVM_TYPE_OTP == _cyhal_nvm_current_block_info.nvm_type)
        {
            /* Not supported for OTP */
            status = CYHAL_NVM_RSLT_ERR_NOT_SUPPORTED;
        }
        else
        {
            /* Not supported type of NVM */
            status = CYHAL_NVM_RSLT_ERR_NOT_SUPPORTED;
        }
    }
    return status;
}

cy_rslt_t cyhal_nvm_start_program(cyhal_nvm_t *obj, uint32_t address, const uint32_t* data)
{
    CY_ASSERT(NULL != obj);
    CY_UNUSED_PARAMETER(obj);

    cyhal_nvm_region_info_t _cyhal_nvm_current_block_info;
    cy_rslt_t status = CYHAL_NVM_RSLT_ERR_NOT_SUPPORTED;

    bool is_address_valid = false;
    is_address_valid = _cyhal_nvm_get_nvm_region_by_address(address, &_cyhal_nvm_current_block_info);

    if (!is_address_valid)
    {
        status = CYHAL_NVM_RSLT_ERR_ADDRESS;
    }
    else
    {
        if (CYHAL_NVM_TYPE_FLASH == _cyhal_nvm_current_block_info.nvm_type)
        {
        #if defined(CY_IP_MXS40SRSS) && (_CYHAL_DRIVER_AVAILABLE_NVM_FLASH)
            #if _CYHAL_USES_ECT_FLASH /* StartWrite on this device behaves the same as StartProgram on others */
                status = _cyhal_flash_run_operation(Cy_Flash_StartWrite, address, data, false);
            #else
                status = _cyhal_flash_run_operation(Cy_Flash_StartProgram, address, data, false);
            #endif
        #else
            status = CYHAL_NVM_RSLT_ERR_NOT_SUPPORTED;
        #endif /* defined(CY_IP_MXS40SRSS) && (_CYHAL_DRIVER_AVAILABLE_NVM_FLASH)*/
        }
        else if (CYHAL_NVM_TYPE_RRAM == _cyhal_nvm_current_block_info.nvm_type)
        {
        #if (_CYHAL_DRIVER_AVAILABLE_NVM_RRAM)
            status = (cy_rslt_t)Cy_RRAM_NonBlockingNvmWriteByteArray(
                        RRAMC0, address, (const uint8_t *)data, _cyhal_nvm_current_block_info.block_size);
        #endif /* #if (_CYHAL_DRIVER_AVAILABLE_NVM_RRAM) */
        }
        else if (CYHAL_NVM_TYPE_OTP == _cyhal_nvm_current_block_info.nvm_type)
        {
            /* Not supported for OTP */
            status = CYHAL_NVM_RSLT_ERR_NOT_SUPPORTED;
        }
        else
        {
            /* Not supported type of NVM */
            CY_UNUSED_PARAMETER(address);
            CY_UNUSED_PARAMETER(data);
            status = CYHAL_NVM_RSLT_ERR_NOT_SUPPORTED;
        }
    }
    return status;
}

bool cyhal_nvm_is_operation_complete(cyhal_nvm_t *obj)
{
    CY_ASSERT(NULL != obj);
    CY_UNUSED_PARAMETER(obj);

    bool complete = true;

#if (defined(CY_IP_MXS40SRSS) || (_CYHAL_USES_ECT_FLASH) || CY_FLASH_NON_BLOCKING_SUPPORTED) && (_CYHAL_DRIVER_AVAILABLE_NVM_FLASH)
    complete = (CY_FLASH_DRV_SUCCESS == Cy_Flash_IsOperationComplete());
    #if !defined(CY_IP_M7CPUSS) && !defined (CY_IP_MXS40FLASHC) /* PDL automatically clears cache when necessary */
        if (complete)
            Cy_SysLib_ClearFlashCacheAndBuffer();
    #endif
#else
    complete = true;
#endif /* (defined(CY_IP_MXS40SRSS) || (_CYHAL_USES_ECT_FLASH) || CY_FLASH_NON_BLOCKING_SUPPORTED) && (_CYHAL_DRIVER_AVAILABLE_NVM_FLASH) */

#if (_CYHAL_DRIVER_AVAILABLE_NVM_RRAM)
    if (complete)
    {
        complete = !_cyhal_rram_is_busy();
    }
#endif /* #if (_CYHAL_DRIVER_AVAILABLE_NVM_RRAM) */

    return complete;
}

/*
*  BWC for Flash HAL
*  DO NOT USE IN THE NEW DESIGN
*/

#if (CYHAL_DRIVER_AVAILABLE_FLASH)
static cyhal_flash_block_info_t _flash_blocks[_CYHAL_INTERNAL_FLASH_MEMORY_BLOCKS] = {0};

void cyhal_flash_get_info(const cyhal_flash_t *obj, cyhal_flash_info_t *info)
{
    CY_UNUSED_PARAMETER(obj);

    cyhal_nvm_info_t nvm_info;
    uint32_t flash_region_count = 0;

    nvm_info.region_count = _CYHAL_NVM_MEMORY_BLOCKS_COUNT;
    nvm_info.regions = &_cyhal_nvm_mem_regions[0];

    for (uint32_t i = 0; i < nvm_info.region_count; i++)
    {
        if (CYHAL_NVM_TYPE_FLASH == nvm_info.regions[i].nvm_type)
        {
            _flash_blocks[flash_region_count].start_address = nvm_info.regions[i].start_address;
            _flash_blocks[flash_region_count].size = nvm_info.regions[i].size;
            _flash_blocks[flash_region_count].sector_size = nvm_info.regions[i].sector_size;
            _flash_blocks[flash_region_count].page_size = nvm_info.regions[i].block_size;
            _flash_blocks[flash_region_count].erase_value = nvm_info.regions[i].erase_value;
            flash_region_count++;
        }
    }
    info->block_count = flash_region_count;
    info->blocks = &_flash_blocks[0];
}

#endif /* (CYHAL_DRIVER_AVAILABLE_FLASH) */


#if defined(__cplusplus)
}
#endif /* __cplusplus */

#endif /* (CYHAL_DRIVER_AVAILABLE_NVM) */
