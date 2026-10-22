/***************************************************************************//**
* \file cybsp_pm_callbacks.c
*
* Description:
* Provides initialization code for starting up the hardware contained on the
* Infineon board.
*
********************************************************************************
* \copyright
* (c) 2018-2026, Infineon Technologies AG, or an affiliate of Infineon
* Technologies AG.
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
#include "cybsp_pm_callbacks.h"
#include "cy_sysclk.h"
#include "cybsp_dsram.h"

#if defined(__cplusplus)
extern "C" {
#endif

////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////// BSP PM callbacks order values //////////////////////////////////////

// The sysclk deep sleep callback is recommended to be the last callback that is executed before
// entry into deep sleep mode and the first one upon exit the deep sleep mode.
// Doing so minimizes the time spent on low power mode entry and exit.
#ifndef CYBSP_SYSCLK_PM_CALLBACK_ORDER
    #define CYBSP_SYSCLK_PM_CALLBACK_ORDER      (255u)
#endif

////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////// BSP PM callbacks ///////////////////////////////////////////////////

//--------------------------------------------------------------------------------------------------
// cybsp_deepsleep_ram_callback
//--------------------------------------------------------------------------------------------------
cy_en_syspm_status_t cybsp_deepsleep_ram_callback(cy_stc_syspm_callback_params_t* callbackParams,
                                                  cy_en_syspm_callback_mode_t mode)
{
    cy_en_syspm_status_t retVal = CY_SYSPM_FAIL;

    CY_UNUSED_PARAMETER(callbackParams);

    switch (mode)
    {
        case CY_SYSPM_CHECK_READY:
        case CY_SYSPM_CHECK_FAIL:
        case CY_SYSPM_BEFORE_TRANSITION:
        {
            retVal = CY_SYSPM_SUCCESS;
            break;
        }

        case CY_SYSPM_AFTER_TRANSITION:
        {
            Cy_Syslib_SetWarmBootEntryPoint((uint32_t*)&syspmBspDeepSleepEntryPoint, true);

            retVal = CY_SYSPM_SUCCESS;
            break;
        }

        default:
            break;
    }

    return retVal;
}



////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////// BSP PM callbacks config structures ////////////////////////////////////

#if !defined(CYBSP_CUSTOM_SYSCLK_PM_CALLBACK)
static cy_stc_syspm_callback_params_t cybsp_sysclk_pm_callback_param = { NULL, NULL };
static cy_stc_syspm_callback_t        cybsp_sysclk_pm_callback       =
{
    .callback       = &Cy_SysClk_DeepSleepCallback,
    #if (CY_CFG_PWR_SYS_IDLE_MODE == CY_CFG_PWR_MODE_DEEPSLEEP_RAM)
    .type           = (cy_en_syspm_callback_type_t)CY_SYSPM_MODE_DEEPSLEEP_RAM,
    #else
    .type           = (cy_en_syspm_callback_type_t)CY_SYSPM_MODE_DEEPSLEEP,
    #endif
    .callbackParams = &cybsp_sysclk_pm_callback_param,
    .order          = CYBSP_SYSCLK_PM_CALLBACK_ORDER
};
#endif // if !defined(CYBSP_CUSTOM_SYSCLK_PM_CALLBACK)

static cy_stc_syspm_callback_params_t cybsp_ds_ram_pm_callback_param = { NULL, NULL };
static cy_stc_syspm_callback_t        cybsp_ds_ram_pm_callback       =
{
    .callback       = &cybsp_deepsleep_ram_callback,
    .type           = CY_SYSPM_DEEPSLEEP_RAM,
    .callbackParams = &cybsp_ds_ram_pm_callback_param,
    .order          = 0u
};

////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////// BSP PM callbacks array ////////////////////////////////////////////////

cy_stc_syspm_callback_t* _cybsp_callbacks_array[] =
{
    #if !defined(CYBSP_CUSTOM_SYSCLK_PM_CALLBACK)
    &cybsp_sysclk_pm_callback,
    #endif // if !defined(CYBSP_CUSTOM_SYSCLK_PM_CALLBACK)
    &cybsp_ds_ram_pm_callback
};

////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////// BSP PM callbacks array helper function ////////////////////////////////

void _cybsp_pm_callbacks_get_ptr_and_number(cy_stc_syspm_callback_t*** arr_ptr,
                                            size_t* number_of_elements)
{
    *number_of_elements = 0;
    if (sizeof(_cybsp_callbacks_array) != 0)
    {
        *arr_ptr = _cybsp_callbacks_array;
        *number_of_elements = sizeof(_cybsp_callbacks_array) / sizeof(_cybsp_callbacks_array[0]);
    }
}


#if defined(__cplusplus)
}
#endif
