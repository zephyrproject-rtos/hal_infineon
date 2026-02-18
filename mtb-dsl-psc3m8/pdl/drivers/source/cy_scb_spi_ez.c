/***************************************************************************//**
* \file cy_scb_spi_ez.c
* \version 1.0
*
* Provides SPI EZ mode API implementation of the SCB driver.
*
********************************************************************************
* \copyright
* (c) 2024-2026, Infineon Technologies AG or an affiliate of
* Infineon Technologies AG.
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

#include "cy_scb_spi_ez.h"

#if defined(__cplusplus)
extern "C" {
#endif


/*******************************************************************************
* Function Name: Cy_SCB_SPI_EZ_DeepSleepCallback
****************************************************************************//**
*
* Handles the transition of the SPI EZ EC-mode slave into and out of DeepSleep.
*
* In externally-clocked operation mode (EC_OP_MODE=1), the SPI slave processes
* complete EZ transactions using only the external SPI clock. The EC interrupt
* (INTR_SPI_EC) is asynchronous and DeepSleep-capable, so it can wake the CPU
* without requiring clk_scb.
*
* This callback:
* - CHECK_READY: blocks entry if the SPI bus is currently active (mid-transfer)
* - BEFORE_TRANSITION: clears pending EC interrupt flags
* - AFTER_TRANSITION: no-op
*
* \note The INTR_SPI_EC_MASK must be configured by the application at init time
* (e.g., WAKEUP | EZ_WRITE_STOP) and should remain enabled permanently.
*
* Register this callback with \ref Cy_SysPm_RegisterCallback using
* \ref CY_SYSPM_DEEPSLEEP type. The callbackParams->base must point to the
* SPI target SCB instance.
*
* \param callbackParams
* The pointer to the callback parameters structure. base = SPI target SCB.
*
* \param mode
* Callback mode, see \ref cy_en_syspm_callback_mode_t
*
* \return
* \ref cy_en_syspm_status_t
*
*******************************************************************************/
cy_en_syspm_status_t Cy_SCB_SPI_EZ_DeepSleepCallback(
    cy_stc_syspm_callback_params_t *callbackParams,
    cy_en_syspm_callback_mode_t mode)
{
    CySCB_Type *locBase = (CySCB_Type *)callbackParams->base;
    cy_en_syspm_status_t retStatus = CY_SYSPM_FAIL;

    switch (mode)
    {
        case CY_SYSPM_CHECK_READY:
        {
            /* Block DeepSleep entry if the bus is mid-transfer */
            if (!Cy_SCB_SPI_IsBusBusy(locBase))
            {
                Cy_SCB_SPI_EZ_ClearEcStatus(locBase, CY_SCB_SPI_EZ_EC_INTR_MASK);

                retStatus = CY_SYSPM_SUCCESS;
            }
        }
        break;

        case CY_SYSPM_CHECK_FAIL:
        {
            retStatus = CY_SYSPM_SUCCESS;
        }
        break;

        case CY_SYSPM_BEFORE_TRANSITION:
        {
            /* Clear stale EC flags before entering DeepSleep */
            Cy_SCB_SPI_EZ_ClearEcStatus(locBase, CY_SCB_SPI_EZ_EC_INTR_MASK);

            retStatus = CY_SYSPM_SUCCESS;
        }
        break;

        case CY_SYSPM_AFTER_TRANSITION:
        {
            retStatus = CY_SYSPM_SUCCESS;
        }
        break;

        default:
            /* Unhandled mode - retain CY_SYSPM_FAIL */
            retStatus = CY_SYSPM_FAIL;
            break;
    }

    return retStatus;
}

#if defined(__cplusplus)
}
#endif

/* [] END OF FILE */
