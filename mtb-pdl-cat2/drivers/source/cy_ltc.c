/***************************************************************************//**
* \file cy_ltc.c
* \version 1.0
*
*  This file provides the source code to the API for the LTC driver.
*
********************************************************************************
* \copyright
* Copyright 2024 Cypress Semiconductor Corporation
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

#include "cy_ltc.h"
#include "cy_syslib.h"
#include "cy_sysclk.h"

#if defined(CY_IP_M0S8SRSSHV)

#if defined(__cplusplus)
extern "C" {
#endif

/** \cond */

/* The LTC counter changing requires 1 LFCLK cycle. */
#define CY_LTC_CNT_CNG_CYCLES (1UL)
#define CY_LTC_CNT_CNG_DELAY_BY_FREQ(freq) \
    (CY_LTC_CNT_CNG_CYCLES * 1000000UL / (freq))

#define CY_LTC_IS_DIV_VALID(div) ((CY_LTC_PRESEL_DIV_2  == (div)) || \
                                  (CY_LTC_PRESEL_DIV_4  == (div)) || \
                                  (CY_LTC_PRESEL_DIV_8  == (div)) || \
                                  (CY_LTC_PRESEL_DIV_16 == (div)) || \
                                  (CY_LTC_PRESEL_DIV_32 == (div)))

/* The LTC divider enum lookup table */
static const cy_en_ltc_div_t divLookupTbl[] =
{
    CY_LTC_PRESEL_DIV_2,
    CY_LTC_PRESEL_DIV_4,
    CY_LTC_PRESEL_DIV_8,
    CY_LTC_PRESEL_DIV_16,
    CY_LTC_PRESEL_DIV_32,
};

/** \endcond */

/*******************************************************************************
* Function Name: Cy_LTC_Init
****************************************************************************//**
*
* Initializes the lifetime counter to its default state.
*
* \details 
* - The Lifetime counter disable.
* - The Lifetime counter value is set to 0.
* - The Lifetime wakeup value is set to default(\ref CY_LTC_DEFAULT_WAKEUP_VALUE) value
* - Configure default(\ref CY_LTC_PRESEL_DIV_2) divide ratio for preselector. 
* - Clear mask and interrupt
* - The Lifetime counter enable.
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \warning A Low frequency clock source(\ref group_sysclk_lf) should be enabled before this driver usage.
*
* \return none
*
* \funcusage
* \snippet ltc_snippet.c snippet_LTC_basic
*
*******************************************************************************/
void Cy_LTC_Init(void)
{
    Cy_LTC_Disable();
    /* Set default values */
    Cy_LTC_SetCounterValue(0);
    Cy_LTC_SetWakeup(CY_LTC_DEFAULT_WAKEUP_VALUE);
    /* Clear previous interrupt activity */
    Cy_LTC_ClearInterrupt();
    Cy_LTC_SetInterruptMask(false);
    Cy_LTC_Enable();
}

/*******************************************************************************
* Function Name: Cy_LTC_IsEnabled
****************************************************************************//**
*
* Returns the lifetime counter HW actual status.
*
* \note May lag by up to one \ref group_sysclk_lf cycle
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \return
* true  - Lifetime counter actual status is enabled. \n
* false - Lifetime counter actual status is disabled.
*
* \funcusage
* \snippet ltc_snippet.c snippet_LTC_Change_Counter
*
*******************************************************************************/
bool Cy_LTC_IsEnabled(void)
{
    return(_FLD2BOOL(SRSSHV_LIFETIME_CTL_STATUS_ENABLED, SRSSHV->LIFETIME_CTL));
}

/*******************************************************************************
* Function Name: Cy_LTC_Enable
****************************************************************************//**
*
* Enables the lifetime counter and the counter of the lifetime counter starts counting up
*
* \details The user does not need to wait for enable synchronization before entering Deep Sleep.
* This will occur within one \ref group_sysclk_lf cycle. But it is recommended to wait for the enabled status
* before entering Deep sleep ( \ref Cy_SysPm_CpuEnterDeepSleep ).
*
* \note Due to internal synchronization, may take up to one \ref group_sysclk_lf cycle to take effect.
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \return none
*
* \funcusage
* \snippet ltc_snippet.c snippet_LTC_Change_Counter
*
*******************************************************************************/
void Cy_LTC_Enable(void)
{
    /* Avoid lock register's potential race condition. */
    uint32_t intrState = Cy_SysLib_EnterCriticalSection();
    Cy_SysClk_UnlockProtReg();
    SRSSHV->LIFETIME_CTL |= SRSSHV_LIFETIME_CTL_ENABLED_Msk;
    Cy_SysClk_LockProtReg();
    Cy_SysLib_ExitCriticalSection(intrState);

    /* Due to internal synchronization, may take up to one clk_lf cycles to take effect. */
    while(!Cy_LTC_IsEnabled())
    {
        Cy_SysLib_DelayUs(1);
    }
}

/*******************************************************************************
* Function Name: Cy_LTC_Disable
****************************************************************************//**
*
* Disables the lifetime counter and the counter of the lifetime counter stops counting, but is not cleared to 0.
*
* \note Due to internal synchronization, may take up to one \ref group_sysclk_lf cycle to take effect.
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \return none
*
* \funcusage
* \snippet ltc_snippet.c snippet_LTC_Change_Counter
*
*******************************************************************************/
void Cy_LTC_Disable(void)
{
    /* Avoid lock register's potential race condition. */
    uint32_t intrState = Cy_SysLib_EnterCriticalSection();
    Cy_SysClk_UnlockProtReg();
    SRSSHV->LIFETIME_CTL &= ~SRSSHV_LIFETIME_CTL_ENABLED_Msk;
    Cy_SysClk_LockProtReg();
    Cy_SysLib_ExitCriticalSection(intrState);

    /* Due to internal synchronization, may take up to one clk_lf cycles to take effect. */
    while(Cy_LTC_IsEnabled())
    {
        Cy_SysLib_DelayUs(1);
    }
}

/*******************************************************************************
* Function Name: Cy_LTC_SetDivider
****************************************************************************//**
*
* Configures the divide ratio for the pre-selector.
*
* \warning Writes will be ignored when lifetime counter is enabled by \ref Cy_LTC_Enable function.
*
* \note Due to internal synchronization, it takes about 1 \ref group_sysclk_lf cycle
* to update the counters after configuration.
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \param divider \ref cy_en_ltc_div_t
*
* \return none
*
* \funcusage
* \snippet ltc_snippet.c snippet_LTC_Set_Divider
*
*******************************************************************************/
void Cy_LTC_SetDivider(cy_en_ltc_div_t divider)
{
    CY_ASSERT_L2(CY_LTC_IS_DIV_VALID(divider));
    CY_ASSERT_L2(false == Cy_LTC_IsEnabled());

    /* Avoid lock register's potential race condition. */
    uint32_t intrState = Cy_SysLib_EnterCriticalSection();
    Cy_SysClk_UnlockProtReg();
    SRSSHV->LIFETIME_CTL = (SRSSHV->LIFETIME_CTL & ~SRSSHV_LIFETIME_CTL_PRESEL_Msk) |
                           ((uint32_t)divider & SRSSHV_LIFETIME_CTL_PRESEL_Msk);
    Cy_SysClk_LockProtReg();
    Cy_SysLib_ExitCriticalSection(intrState);
}

/*******************************************************************************
* Function Name: Cy_LTC_GetDivider
****************************************************************************//**
*
* Returns the divide ratio for the pre-selector value.
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \return \ref cy_en_ltc_div_t : \n
* \ref CY_LTC_PRESEL_DIV_2  - Divide \ref group_sysclk_lf by 2.  \n
* \ref CY_LTC_PRESEL_DIV_4  - Divide \ref group_sysclk_lf by 4.  \n
* \ref CY_LTC_PRESEL_DIV_8  - Divide \ref group_sysclk_lf by 8.  \n
* \ref CY_LTC_PRESEL_DIV_16 - Divide \ref group_sysclk_lf by 16. \n
* \ref CY_LTC_PRESEL_DIV_32 - Divide \ref group_sysclk_lf by 32. \n
*
* \funcusage
* \snippet ltc_snippet.c snippet_LTC_Get_Divider
*
*******************************************************************************/
cy_en_ltc_div_t Cy_LTC_GetDivider(void)
{
    uint32_t rawVal = SRSSHV->LIFETIME_CTL & SRSSHV_LIFETIME_CTL_PRESEL_Msk;
    return (divLookupTbl[rawVal]);
}

/*******************************************************************************
* Function Name: Cy_LTC_SetCounterValue
****************************************************************************//**
*
* Configures lifetime counter current value.
*
* \note This function configuration is ignored when lifetime counter enabled.
*
* \note The counter doesn't increment unless enabled(\ref Cy_LTC_Enable).
*
* \note The counter doesn't increment unless enabled(\ref Cy_LTC_Enable).
* \note Due to internal synchronization, it takes about one \ref group_sysclk_lf 
* cycle to update the counters after divider configuration and counter needs to be disabled
* one \ref group_sysclk_lf cycle for the internal synchronization of this counter to take place.
*
* \warning Do not change this setting when lifetime counter is enabled.
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \param count
* Lifetime counter current value.
*
* \return none
*
* \funcusage
* \snippet ltc_snippet.c snippet_LTC_Change_Counter
*
*******************************************************************************/
void Cy_LTC_SetCounterValue(uint32_t count)
{
    if(!Cy_LTC_IsEnabled())
    {
        SRSSHV->LIFETIME_COUNTER = count;
        
        /* The counter shall be disabled one LFCLK cycle
        for the internal synchronization of this counter to take place. */
        uint32_t lfclkFreq = Cy_SysClk_ClkLfGetFrequency();
        /* In an unexpected situation, get the highest delay */
        if(0UL == lfclkFreq)
        {
            lfclkFreq = CY_SYSCLK_PILO_FREQ;
        }
            
        uint16_t delay = (uint16_t)CY_LTC_CNT_CNG_DELAY_BY_FREQ(lfclkFreq);
        /* Wait for LTC counter changing. */
        Cy_SysLib_DelayUs(delay);
    }
    else
    {
        /* Changes ignored */
        CY_UNUSED_PARAMETER(count);
    }
}

/*******************************************************************************
* Function Name: Cy_LTC_GetCounterValue
****************************************************************************//**
*
* Returns lifetime counter current value
*
* \note The counter doesn't increment unless enabled(\ref Cy_LTC_Enable).
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \return The lifetime current counter value.
*
* \funcusage
* \snippet ltc_snippet.c snippet_LTC_Change_Counter
*
*******************************************************************************/
uint32_t Cy_LTC_GetCounterValue(void)
{
    return (SRSSHV->LIFETIME_COUNTER);
}

/*******************************************************************************
* Function Name: Cy_LTC_SetWakeup
****************************************************************************//**
*
* Configures the lifetime wakeup value.
*
* \details The user can change the WAKEUP value without disabling the lifetime counter.
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \param wakeupValue
* Lifetime wakeup value.
*
* \return none
*
* \funcusage
* \snippet ltc_snippet.c snippet_LTC_Change_Wakeup
*
*******************************************************************************/
void Cy_LTC_SetWakeup(uint32_t wakeupValue)
{
    SRSSHV->LIFETIME_WAKEUP = wakeupValue;
}

/*******************************************************************************
* Function Name: Cy_LTC_GetWakeup
****************************************************************************//**
*
* Returns the lifetime wakeup value.
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \return The lifetime wakeup value.
*
* \funcusage
* \snippet ltc_snippet.c snippet_LTC_Change_Wakeup
*
*******************************************************************************/
uint32_t Cy_LTC_GetWakeup(void)
{
    return (SRSSHV->LIFETIME_WAKEUP);
}

/*******************************************************************************
* Function Name: Cy_LTC_SetInterrupt
****************************************************************************//**
*
* Triggers an interrupt with software. Can be used to set interrupts for firmware testing. 
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \return none
*
*******************************************************************************/
void Cy_LTC_SetInterrupt(void)
{
    SRSSHV->SRSS_INTR_SET = SRSSHV_SRSS_INTR_SET_LIFETIME_WAKEUP_Msk;
}

/*******************************************************************************
* Function Name: Cy_LTC_GetInterruptStatus
****************************************************************************//**
*
* Returns the interrupt status.
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \return
* True  - Interrupt occurred. \n
* False - Interrupt did not occur.
*
* \funcusage
* \snippet ltc_snippet.c snippet_LTC_Isr_config
*
*******************************************************************************/
bool Cy_LTC_GetInterruptStatus(void)
{
    return (_FLD2BOOL(SRSSHV_SRSS_INTR_LIFETIME_WAKEUP, SRSSHV->SRSS_INTR));
}

/*******************************************************************************
* Function Name: Cy_LTC_ClearInterrupt
****************************************************************************//**
*
* Clears the lifetime counter interrupt factor.
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \return none
*
* \funcusage
* \snippet ltc_snippet.c snippet_LTC_Isr_config
*
*******************************************************************************/
void Cy_LTC_ClearInterrupt(void)
{
    SRSSHV->SRSS_INTR = SRSSHV_SRSS_INTR_LIFETIME_WAKEUP_Msk;

    /* This read ensures that the initial write has been flushed out to the hardware */
    (void)SRSSHV->SRSS_INTR;
}

/*******************************************************************************
* Function Name: Cy_LTC_SetInterruptMask
****************************************************************************//**
*
* Enables or disables the lifetime counter interrupt handler triggering.
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \param enable
*  true  : to masking interrupt. After masking the interrupt, it is not passed to the CPU. \n
*  false : to reset masking. After unmasking the interrupt, it is passed to CPU.
*
* \return none
*
* \funcusage
* \snippet ltc_snippet.c snippet_LTC_SetIrqMask
*
*******************************************************************************/
void Cy_LTC_SetInterruptMask(bool enable)
{
    if (!enable)
    {
        SRSSHV->SRSS_INTR_MASK |= SRSSHV_SRSS_INTR_MASK_LIFETIME_WAKEUP_Msk;
    }
    else
    {
        SRSSHV->SRSS_INTR_MASK &= ~SRSSHV_SRSS_INTR_MASK_LIFETIME_WAKEUP_Msk;
    }
}

/*******************************************************************************
* Function Name: Cy_LTC_GetInterruptStatusMasked
****************************************************************************//**
*
* Gets Bitwise "AND" between the interrupt request and mask configuration.
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \return 
* true  : There is Lifetime Counter interrupt factor and mask bit is set \n
* false : There is no Lifetime Counter interrupt factor or mask bit is cleared
*
* \funcusage
* \snippet ltc_snippet.c snippet_LTC_SetIrqMask
*
*******************************************************************************/
bool Cy_LTC_GetInterruptStatusMasked(void)
{
    return (_FLD2BOOL(SRSSHV_SRSS_MASKED_LIFETIME_WAKEUP, SRSSHV->SRSS_MASKED));
}

#if defined(__cplusplus)
}
#endif

#endif /* CY_IP_M0S8SRSSHV */

/* [] END OF FILE */
