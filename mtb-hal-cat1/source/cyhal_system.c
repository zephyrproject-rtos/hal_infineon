/***************************************************************************//**
* \file cyhal_system.c
*
* \brief
* Provides a high level interface for interacting with the Infineon power
* management and system clock configuration. This interface abstracts out the
* chip specific details. If any chip specific functionality is necessary, or
* performance is critical the low level functions can be used directly.
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

#include "cyhal_system.h"

#if (defined(COMPONENT_CAT1A) || defined(COMPONENT_CAT1B) || defined(COMPONENT_CAT1C) || defined(COMPONENT_CAT1D))
#include "cy_syslib.h"
#endif

#if defined(CY_RTOS_AWARE) || defined(COMPONENT_RTOS_AWARE)
#include "cyabs_rtos.h"
#endif

#if (CYHAL_DRIVER_AVAILABLE_SYSTEM)

#if defined(__cplusplus)
extern "C"
{
#endif

#define _CYHAL_SYSTEM_HZ_PER_MHZ 1000000

static uint32_t _cyhal_system_supply_voltages[((size_t)CYHAL_VOLTAGE_SUPPLY_MAX) + 1] = { 0 };

#if (defined(COMPONENT_CAT1A) || defined(COMPONENT_CAT1B) || defined(COMPONENT_CAT1C) || defined(COMPONENT_CAT1D)) &&\
    !defined(CYHAL_DISABLE_WEAK_FUNC_IMPL)
/* Overrides weak implemenation for Cy_SysLib_Rtos_Delay to provide a way
* to call into a RTOS if so configured. This function is only available
* in mtb-pdl-cat1 version 2.2.0 or later.
*/
void Cy_SysLib_Rtos_Delay(uint32_t milliseconds)
{
    cy_rslt_t result = cyhal_system_delay_ms(milliseconds);
    CY_ASSERT(CY_RSLT_SUCCESS == result);
    CY_UNUSED_PARAMETER(result);
}
#endif

cy_rslt_t cyhal_system_delay_ms(uint32_t milliseconds)
{
#if defined(CY_RTOS_AWARE) || defined(COMPONENT_RTOS_AWARE)
    // The RTOS is configured to round down, while this API is intended to wait at least the
    // requested time. Add 1 to the requested time to make it behave the same.
    return cy_rtos_delay_milliseconds(milliseconds + 1);
#else
    Cy_SysLib_Delay(milliseconds);
    return CY_RSLT_SUCCESS;
#endif
}

cyhal_reset_reason_t cyhal_system_get_reset_reason(void)
{
    uint32_t pdl_reason = Cy_SysLib_GetResetReason();
    cyhal_reset_reason_t reason = CYHAL_SYSTEM_RESET_NONE;

    if (CY_SYSLIB_RESET_SOFT & pdl_reason)
        reason |= CYHAL_SYSTEM_RESET_SOFT;
    if (CY_SYSLIB_RESET_HWWDT & pdl_reason)
        reason |= CYHAL_SYSTEM_RESET_WDT;
#if defined(CY_IP_S8SRSSLT)
    if (CY_SYSLIB_PROT_FAULT & pdl_reason)
        reason |= CYHAL_SYSTEM_RESET_PROTECTION;
#endif
#if defined(CY_IP_MXS40SRSS) || defined(CY_IP_MXS40SSRSS) || defined(CY_IP_MXS22SSRSS)
    if (CY_SYSLIB_RESET_ACT_FAULT & pdl_reason)
        reason |= CYHAL_SYSTEM_RESET_ACTIVE_FAULT;
    if (CY_SYSLIB_RESET_DPSLP_FAULT & pdl_reason)
        reason |= CYHAL_SYSTEM_RESET_DEEPSLEEP_FAULT;
    if (CY_SYSLIB_RESET_HIB_WAKEUP & pdl_reason)
        reason |= CYHAL_SYSTEM_RESET_HIB_WAKEUP;
    if (CY_SYSLIB_RESET_CSV_LOSS_WAKEUP & pdl_reason)
        reason |= CYHAL_SYSTEM_RESET_SYS_CLK_ERR;
    if (CY_SYSLIB_RESET_CSV_ERROR_WAKEUP & pdl_reason)
        reason |= CYHAL_SYSTEM_RESET_SYS_CLK_ERR;
    if ((CY_SYSLIB_RESET_SWWDT0 | CY_SYSLIB_RESET_SWWDT1 | CY_SYSLIB_RESET_SWWDT2 | CY_SYSLIB_RESET_SWWDT3) & pdl_reason)
        reason |= CYHAL_SYSTEM_RESET_WDT;
#endif
#if (SRSS_WCOCSV_PRESENT != 0U)
    if (CY_SYSLIB_RESET_CSV_WCO_LOSS & pdl_reason)
        reason |= CYHAL_SYSTEM_RESET_WCO_ERR;
#endif
#if (SRSS_MASK_HFCSV != 0U)
    if ((CY_SYSLIB_RESET_HFCLK_LOSS | CY_SYSLIB_RESET_HFCLK_ERR) & pdl_reason)
        reason |= CYHAL_SYSTEM_RESET_SYS_CLK_ERR;
#endif

#if defined(CY_IP_MXS40SSRSS)
    if ((reason == CYHAL_SYSTEM_RESET_NONE) && Cy_SysLib_IsDSRAMWarmBootEntry())
        reason |= CYHAL_SYSTEM_RESET_WARMBOOT;
#endif

    return reason;
}

cy_rslt_t cyhal_system_set_isr(int32_t irq_num, int32_t irq_src, uint8_t priority, cyhal_irq_handler handler)
{
    CY_UNUSED_PARAMETER(irq_src); // Not used by most configurations as there is a 1:1 mapping from irq_src to irq_num
    cy_stc_sysint_t cfg =
    {
#if defined (CY_IP_M7CPUSS)
        .intrSrc = (uint32_t)irq_src | ((uint32_t)irq_num << CY_SYSINT_INTRSRC_MUXIRQ_SHIFT),
#elif defined (CY_IP_M4CPUSS) && (CY_IP_M4CPUSS_VERSION == 2) && (CPUSS_SYSTEM_IRQ_PRESENT)
        .intrSrc = (IRQn_Type)((uint32_t)irq_src | ((uint32_t)irq_num << CY_SYSINT_INTRSRC_MUXIRQ_SHIFT)),
#else
        .intrSrc = (IRQn_Type)irq_num,
#endif
        .intrPriority = priority,
#if (CY_CPU_CORTEX_M0P) && defined (CY_IP_M4CPUSS)
        .cm0pSrc = (cy_en_intr_t)irq_src,
#endif
    };
    return Cy_SysInt_Init(&cfg, (cy_israddress)handler);
}

void cyhal_system_set_supply_voltage(cyhal_system_voltage_supply_t supply, uint32_t mvolts)
{
    CY_ASSERT((size_t)supply <= CYHAL_VOLTAGE_SUPPLY_MAX);
    _cyhal_system_supply_voltages[(size_t)supply] = mvolts;
}

uint32_t cyhal_system_get_supply_voltage(cyhal_system_voltage_supply_t supply)
{
    CY_ASSERT((size_t)supply <= CYHAL_VOLTAGE_SUPPLY_MAX);
    return _cyhal_system_supply_voltages[(size_t)supply];
}

#if defined(__cplusplus)
}
#endif

#endif /* CYHAL_DRIVER_AVAILABLE_SYSTEM */
