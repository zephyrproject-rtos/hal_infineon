/***************************************************************************//**
* \file cy_crwdt.c
* \version 1.0
*
*  This file provides the source code
*  to the API for the Challenge Response WDT driver.
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

#include "cy_crwdt.h"
#include "cy_syslib.h"

#if (defined(CY_IP_M0S8SRSSHV) && (1UL == SRSSHV_CRWDT_PRESENT)) || defined (CY_DOXYGEN)

#if defined(__cplusplus)
extern "C" {
#endif

/** \cond INTERNAL */
#define CY_CRWDT_DEFAULT   (SRSSHV_CRWDT_CONFIG_LATE_ACTION_Msk | \
                            SRSSHV_CRWDT_CONFIG_CHALLENGE_FAIL_ACTION_Msk | \
                            SRSSHV_CRWDT_CONFIG_DEBUG_RUN_Msk)

/* CRC8 */
#define CY_CRWDT_CRC_LOOP_LIMIT    (8U)    /* CRC8 loop Limit    */
#define CY_CRWDT_CRC_MASK_VALUE    (0x80U) /* CRC8 mask value    */
#define CY_CRWDT_CRC_MODULUS_VALUE (0x2FU) /* CRC8 modulus value */
/** \endcond */

/*******************************************************************************
* Function Name: Cy_CRWDT_Init
****************************************************************************//**
*
* Initializes the Challenge Response WDT (CRWDT) to its default state.
*
* \details
* - EARLY_ACTION - None
* - WARN_ACTION - None
* - LATE_ACTION - Trigger a fault.
* Further, trigger a system-wide reset if the CRWDT is not disabled within 6
* - CHALLENGE_FAIL_ACTION - Action taken when a failed response occurs,
* For example, the expected LFSR value is different from the  expected value.
* - DEBUG - When the debugger is connected, the counter pauses incrementing.
* - The Challenge Response WDT enable \ref Cy_CRWDT_Enable
*
* \note After the initialization, the CRWDT is enabled,
* and the counter of CRWDT starts counting up from 0.
*
* \warning Will require 2 \ref group_sysclk_lf cycles to take effect.
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \return none
*
* \funcusage
* \snippet crwdt_snippet.c snippet_CRWDT_init
*
*******************************************************************************/
void Cy_CRWDT_Init(void)
{
    Cy_CRWDT_Disable();
    SRSSHV->CRWDT_CONFIG = CY_CRWDT_DEFAULT;
    Cy_CRWDT_Enable();
}

/*******************************************************************************
* Function Name: Cy_CRWDT_IsEnabled
****************************************************************************//**
*
* Returns the Challenge Response WDT (CRWDT) HW actual status.
*
* \warning May lag \ref Cy_CRWDT_Enable by up to one \ref group_sysclk_lf cycles.
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \return
* true  - Challenge Response WDT is enabled. \n
* false - Challenge Response WDT is disabled.
*
* \funcusage
* \snippet crwdt_snippet.c snippet_CRWDT_configure
*
*******************************************************************************/
bool Cy_CRWDT_IsEnabled(void)
{
    return _FLD2BOOL(SRSSHV_CRWDT_CTL_STATUS_ENABLED,SRSSHV->CRWDT_CTL);
}

/*******************************************************************************
* Function Name: Cy_CRWDT_Enable
****************************************************************************//**
*
* Enables the Challenge Response WDT (CRWDT)
*
* \note The counter of CRWDT starts counting up
*
* \warning Will require 2 \ref group_sysclk_lf cycles to take effect.
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \return none
*
* \funcusage
* \snippet crwdt_snippet.c snippet_CRWDT_configure
*
*******************************************************************************/
void Cy_CRWDT_Enable(void)
{
    /* Avoid lock register's potential race condition. */
    uint32_t intrState = Cy_SysLib_EnterCriticalSection();
    Cy_SysClk_UnlockProtReg();
    SRSSHV->CRWDT_CTL |= SRSSHV_CRWDT_CTL_ENABLED_Msk;
    Cy_SysClk_LockProtReg();
    Cy_SysLib_ExitCriticalSection(intrState);
}

/*******************************************************************************
* Function Name: Cy_CRWDT_Disable
****************************************************************************//**
*
* Disables the Challenge Response WDT (CRWDT)
*
* \note The counter of the CRWDT stops counting, and is cleared to 0.
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \return none
*
* \funcusage
* \snippet crwdt_snippet.c snippet_CRWDT_configure
*
*******************************************************************************/
void Cy_CRWDT_Disable(void)
{
    /* Avoid lock register's potential race condition. */
    uint32_t intrState = Cy_SysLib_EnterCriticalSection();
    Cy_SysClk_UnlockProtReg();
    SRSSHV->CRWDT_CTL &= ~SRSSHV_CRWDT_CTL_ENABLED_Msk;
    Cy_SysClk_LockProtReg();
    Cy_SysLib_ExitCriticalSection(intrState);
}

/*******************************************************************************
* Function Name: Cy_CRWDT_GetChallenge
****************************************************************************//**
*
* Challenge/Response WatchDog Challenge value.
*
* \note Implements the Linear Feedback Shift Register (LFSR) CCRC8-AutoSar
* using the polynomial x^8+x^5+x^3+x^2+x+1.
* The next value in the LFSR sequence is used to compare against the response value.
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \return Challenge CRC-8 code
*
* \funcusage
* \snippet crwdt_snippet.c snippet_CRWDT_feed
*
*******************************************************************************/
uint8_t Cy_CRWDT_GetChallenge(void)
{
    return (uint8_t)_FLD2VAL(SRSSHV_CRWDT_CHALLENGE_CHALLENGE, SRSSHV->CRWDT_CHALLENGE);
}

/*******************************************************************************
* Function Name: Cy_CRWDT_CalculateResponse
****************************************************************************//**
*
* Calculates the response value according to the challenge value.
*
* \param challengeValue - Challenge CRC-8 code.
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \return Response CRC-8 code.
*
* \funcusage
* \snippet crwdt_snippet.c snippet_CRWDT_feed
*
*******************************************************************************/
uint8_t Cy_CRWDT_CalculateResponse(uint8_t challengeValue)
{
    uint8_t  crcValue   = challengeValue; /* CRC value          */
    uint32_t crcShift   = 0UL;            /* CRC shift value    */
    uint32_t crcModulus = 0UL;            /* CRC modulus value  */
    uint32_t loop       = 0UL;            /* Loop counter       */

    /* Implements the LFSR CCRC8-AutoSar using the polynomial x^8+x^5+x^3+x^2+x+1 */
    for(loop = 0U; loop < CY_CRWDT_CRC_LOOP_LIMIT; loop++)
    {
      crcShift   = ((uint32_t)crcValue << 1U);
      crcModulus = (((uint32_t)crcValue & CY_CRWDT_CRC_MASK_VALUE) != 0U) ? CY_CRWDT_CRC_MODULUS_VALUE : 0U;
      crcValue   = (uint8_t)(crcShift ^ crcModulus);
    }

    return crcValue;
}

/*******************************************************************************
* Function Name: Cy_CRWDT_SetResponse
****************************************************************************//**
*
* Sets the response value to service the Challenge Response WDT (CRWDT)
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \param  responseValue - calculated response value to service CRWDT
*
* \return none
*
* \funcusage
* \snippet crwdt_snippet.c snippet_CRWDT_feed
*
*******************************************************************************/
void Cy_CRWDT_SetResponse(uint8_t responseValue)
{
    SRSSHV->CRWDT_RESPONSE = _VAL2FLD(SRSSHV_CRWDT_RESPONSE_RESPONSE, responseValue);
}

/*******************************************************************************
* Function Name: Cy_CRWDT_GetUpCnt
****************************************************************************//**
*
* Get Up counter from Challenge Response WDT (CRWDT)
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \return current up counter value
*
* \funcusage
* \snippet crwdt_snippet.c snippet_CRWDT_feed
*
*******************************************************************************/
uint32_t Cy_CRWDT_GetUpCnt(void)
{
    return _FLD2VAL(SRSSHV_CRWDT_UPCNT_UPCNT, SRSSHV->CRWDT_UPCNT);
}

/*******************************************************************************
* Function Name: Cy_CRWDT_SetEarlyLimit
****************************************************************************//**
*
* Set Early limit for Challenge Response WDT (CRWDT) action
*
* \param early - limit for early action (24-bit)
*
* \note This function is ignored if CRWDT is not disabled
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \return none
*
* \funcusage
* \snippet crwdt_snippet.c snippet_CRWDT_configure
*
*******************************************************************************/
void Cy_CRWDT_SetEarlyLimit(uint32_t early)
{
    /* The limit shall be not bigger than 24 bits */
    CY_ASSERT_L2(early == (early & 0x00FFFFFF));
    /* Avoid lock register's potential race condition. */
    uint32_t intrState = Cy_SysLib_EnterCriticalSection();
    Cy_SysClk_UnlockProtReg();
    SRSSHV->CRWDT_EARLY = _VAL2FLD(SRSSHV_CRWDT_EARLY_EARLY, early);
    Cy_SysClk_LockProtReg();
    Cy_SysLib_ExitCriticalSection(intrState);
}

/*******************************************************************************
* Function Name: Cy_CRWDT_SetWarnLimit
****************************************************************************//**
*
* Set Warn limit for Challenge Response WDT (CRWDT) action
*
* \param warn - limit for late action (24-bit)
*
* \note This function is ignored if CRWDT is disabled
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \return none
*
* \funcusage
* \snippet crwdt_snippet.c snippet_CRWDT_configure
*
*******************************************************************************/
void Cy_CRWDT_SetWarnLimit(uint32_t warn)
{
    /* The limit shall be not bigger than 24 bits */
    CY_ASSERT_L2(warn == (warn & 0x00FFFFFF));
    /* Avoid lock register's potential race condition. */
    uint32_t intrState = Cy_SysLib_EnterCriticalSection();
    Cy_SysClk_UnlockProtReg();
    SRSSHV->CRWDT_WARN = _VAL2FLD(SRSSHV_CRWDT_WARN_WARNING, warn);
    Cy_SysClk_LockProtReg();
    Cy_SysLib_ExitCriticalSection(intrState);
}

/*******************************************************************************
* Function Name: Cy_CRWDT_SetLateLimit
****************************************************************************//**
*
* Set Late limit for Challenge Response WDT (CRWDT) action
*
* \param late - limit for late action (24-bit)
*
* \note This function is ignored if CRWDT is disabled
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \return none
*
* \funcusage
* \snippet crwdt_snippet.c snippet_CRWDT_configure
*
*******************************************************************************/
void Cy_CRWDT_SetLateLimit(uint32_t late)
{
    /* The limit shall be not bigger than 24 bits */
    CY_ASSERT_L2(late == (late & 0x00FFFFFF));
    /* Avoid lock register's potential race condition. */
    uint32_t intrState = Cy_SysLib_EnterCriticalSection();
    Cy_SysClk_UnlockProtReg();
    SRSSHV->CRWDT_LATE = _VAL2FLD(SRSSHV_CRWDT_LATE_LATE, late);
    Cy_SysClk_LockProtReg();
    Cy_SysLib_ExitCriticalSection(intrState);
}

/*******************************************************************************
* Function Name: Cy_CRWDT_SetAction
****************************************************************************//**
*
* Enabling one or more actions for the CRWDT by specifying a composite action bitmask.
*
* \param action - The type of action to be activated
*
* \details
* \ref group_crwdt_actions_bitmask_macros details:
*
* - \ref CY_CRWDT_EARLY_ACTION
*   * 0        Do nothing
*   * 1        Trigger a Fault and interrupt
* - \ref CY_CRWDT_LATE_ACTION
*   * 0        Do nothing
*   * 1        Trigger a fault.  Further, trigger a system-wide reset
*      if the CRWDT is not disabled within 6 \ref group_sysclk_lf cycles.
* - \ref CY_CRWDT_WARN_ACTION
*   * 0        Do nothing
*   * 1        Trigger a Fault and interrupt
* - \ref CY_CRWDT_FAIL_ACTION
*   * 0        Do nothing
*   * 1        Trigger a Reset
* - \ref CY_CRWDT_DEBUG_ACTION
*   * 0        When debugger connected, counter pauses incrementing.
*   * 1        When debugger connected, counter increments normally, but reset generation is blocked.
* - \ref CY_CRWDT_NO_ACTION - sets all action to 0 state
*
* \note This function is ignored if CRWDT is not Disabled
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \return none
*
* \funcusage
* \snippet crwdt_snippet.c snippet_CRWDT_action
*
*******************************************************************************/
void Cy_CRWDT_SetAction(uint32_t action)
{
    CY_ASSERT_L2(action == (action & CY_CRWDT_ALL_ACTIONS));
    SRSSHV->CRWDT_CONFIG = action;
}

/*******************************************************************************
* Function Name: Cy_CRWDT_GetInterruptStatus
****************************************************************************//**
*
* Get interrupt status for Challenge Response WDT (CRWDT)
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \return
* true  - CRWDT interrupt occurred. \n
* false - CRWDT interrupt did not occur.
*
* \funcusage
* \snippet crwdt_snippet.c snippet_CRWDT_Interrupt
*
*******************************************************************************/
bool Cy_CRWDT_GetInterruptStatus(void)
{
    return _FLD2BOOL(SRSSHV_SRSS_INTR_CRWDT, SRSS_SRSS_INTR);
}


/*******************************************************************************
* Function Name: Cy_CRWDT_SetInterrupt
****************************************************************************//**
*
* Triggers an interrupt with software. Can be used to set interrupts for firmware testing.
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \return none
*
* \funcusage
* \snippet crwdt_snippet.c snippet_CRWDT_Interrupt
*
*******************************************************************************/
void Cy_CRWDT_SetInterrupt(void)
{
    /* Write a "1" to Set the SRSS_INTR_SET_CRWDT bit */
    (SRSSHV->SRSS_INTR_SET) = SRSSHV_SRSS_INTR_SET_CRWDT_Msk;
}

/*******************************************************************************
* Function Name: Cy_CRWDT_ClearInterrupt
****************************************************************************//**
*
* Clears the CRWDT interrupt status.
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \return none
*
* \funcusage
* \snippet crwdt_snippet.c snippet_CRWDT_Interrupt
*
*******************************************************************************/
void Cy_CRWDT_ClearInterrupt(void)
{
    /* Write a "1" to Clear the SRSS_INTR_SET_CRWDT bit */
    (SRSSHV->SRSS_INTR) = SRSSHV_SRSS_INTR_SET_CRWDT_Msk;
    /* Read the interrupt register to ensure that the initial clearing write has
    * been flushed out to the hardware.
    */
    (void) (SRSSHV->SRSS_INTR);
}

/*******************************************************************************
* Function Name: Cy_CRWDT_SetInterruptMask
****************************************************************************//**
*
* Sets the Challenge Response WDT (CRWDT) interrupt mask.
* This API enables or disables interrupt handling, but not enable or disable interrupt itself.
*
* \param enable
*  true  : to masking interrupt. After masking the interrupt, it is not passed to the CPU. \n
*  false : to reset masking. After unmasking the interrupt, it is passed to CPU.
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \return none
*
* \funcusage
* \snippet crwdt_snippet.c snippet_CRWDT_Interrupt
*
*******************************************************************************/
void Cy_CRWDT_SetInterruptMask(bool enable)
{
    /* Write a "1" to Set the SRSS_INTR_MASK_CRWDT bit */
    if (!enable)
    {
        SRSS_SRSS_INTR_MASK |= SRSSHV_SRSS_INTR_MASK_CRWDT_Msk;
    }
    else
    {
        SRSS_SRSS_INTR_MASK &= ~SRSSHV_SRSS_INTR_MASK_CRWDT_Msk;
    }
}

/*******************************************************************************
* Function Name: Cy_CRWDT_GetInterruptStatusMasked
****************************************************************************//**
*
* Reads the Challenge Response WDT (CRWDT) masked interrupt status.
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \return
* true  : Masked interrupt occurs \n
* false : No Masked interrupt occurs.
*
* \funcusage
* \snippet crwdt_snippet.c snippet_CRWDT_Interrupt
*
*******************************************************************************/
bool Cy_CRWDT_GetInterruptStatusMasked(void)
{
    return _FLD2BOOL(SRSSHV_SRSS_MASKED_CRWDT, SRSSHV->SRSS_MASKED);
}

#if defined(__cplusplus)
}
#endif

#endif /* defined(CY_IP_M0S8SRSSHV) && (1UL == SRSSHV_CRWDT_PRESENT) */

/* [] END OF FILE */
