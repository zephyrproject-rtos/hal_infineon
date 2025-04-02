/***************************************************************************//**
* \file cybsp.c
*
* Description:
* Provides initialization code for starting up the hardware contained on the
* Infineon board.
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

#include <stdlib.h>

#if !defined(CYBSP_SKIP_PM_REGISTRATION)
#include "cybsp_pm.h"
#endif

#include "cy_syspm.h"
#include "cy_sysclk.h"
#include "cybsp.h"
#if defined(CY_USING_HAL)
#include "cyhal_hwmgr.h"
#include "cyhal_syspm.h"
#include "cyhal_system.h"
#endif
#include "cybsp_dsram.h"
#if defined(CY_IP_MXSMIF_INSTANCES) && (CY_IP_MXSMIF_INSTANCES > 0)
#include "cycfg_qspi_memslot.h"
#endif

#if defined(__cplusplus)
extern "C" {
#endif

//--------------------------------------------------------------------------------------------------
// cybsp_init
//--------------------------------------------------------------------------------------------------
cy_rslt_t cybsp_init(void)
{
    // Setup hardware manager to track resource usage then initialize all system (clock/power) board
    // configuration
    #if defined(CY_USING_HAL)
    cy_rslt_t result = cyhal_hwmgr_init();

    if (CY_RSLT_SUCCESS == result)
    {
        #if (CYHAL_DRIVER_AVAILABLE_SYSPM)
        result = cyhal_syspm_init();
        #endif
    }
    #else // if defined(CY_USING_HAL)
    cy_rslt_t result = CY_RSLT_SUCCESS;
    #endif // if defined(CY_USING_HAL)

    #ifdef CY_CFG_PWR_VDDA_MV
    if (CY_RSLT_SUCCESS == result)
    {
        #if defined(CY_USING_HAL)
        // Old versions of classic HAL have this API in the Syspm HAL. In versions of HAL which
        // support HAL-Lite configuration, this is moved to the System HAL, with compatibility
        // macros that exist in classic HAL configuration only (HAL-Lite configuration does
        // not include SysPm HAL)
        cyhal_syspm_set_supply_voltage(CYHAL_VOLTAGE_SUPPLY_VDDA, CY_CFG_PWR_VDDA_MV);
        #endif
    }
    #endif // ifdef CY_CFG_PWR_VDDA_MV


    init_cycfg_all();

    if (CY_RSLT_SUCCESS == result)
    {
        #if defined(CYBSP_CUSTOM_SYSCLK_PM_CALLBACK)
        result = cybsp_register_custom_sysclk_pm_callback();
        #endif
    }

    #if !defined(CYBSP_SKIP_PM_REGISTRATION)
    if (CY_RSLT_SUCCESS == result)
    {
        result = cybsp_syspm_dsram_init();
    }

    if (CY_RSLT_SUCCESS == result)
    {
        result = cybsp_pm_callbacks_register();
    }
    #endif //#if !defined(CYBSP_SKIP_PM_REGISTRATION)

    // CYHAL_HWMGR_RSLT_ERR_INUSE result could be returned if any resourced needed for the BSP was
    // previously reserved by the user. Review the Device Configurator (design.modus) and the BSP
    // reservation list (cyreservedresources.list) to make sure no resources are reserved by both.
    return result;
}


#if defined(__cplusplus)
}
#endif
