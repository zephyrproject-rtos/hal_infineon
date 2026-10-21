/***************************************************************************//**
* \file cy_wdt.c
* \version 1.10
*
*  This file provides the source code to the API for the WDT driver.
*
********************************************************************************
* \copyright
* (c) (2016-2024), Cypress Semiconductor Corporation (an Infineon company) or
* an affiliate of Cypress Semiconductor Corporation.
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

#include "cy_wdt.h"
#include "cy_syslib.h"

#if defined(__cplusplus)
extern "C" {
#endif


/*******************************************************************************
* Function Name: Cy_WDT_Init
****************************************************************************//**
*
* Initializes the Watchdog timer to its default state:
* - WDT disabled
* - WDT match value is 4096
* - None of ignore bits are set: the whole WDT counter bits are checked against
* the match value.
*
* This function clears the WDT interrupt.
*
* For PSOC4 HVMS/PA devices the given default setting of the WDT:
* - The WDT is unlocked and disabled.
* - The WDT Lower Limit value is set to 0 and Lower action to None.
* - The WDT Warn Limit value is set to 0 and Warn action to None.
* - The WDT Upper Limit value is set to 32768 (~1 sec when clk_lf = 32KHz) and Upper action to Reset.
* - The WDT is locked again.
*
*******************************************************************************/
void Cy_WDT_Init(void)
{
#if defined(CY_IP_S8SRSSLT)
    Cy_WDT_Disable();
    Cy_WDT_SetMatch(CY_SRSS_WDT_DEFAULT_MATCH_VALUE);
    Cy_WDT_SetIgnoreBits(CY_SRSS_WDT_DEFAULT_IGNORE_BITS);
#elif defined(CY_IP_M0S8SRSSHV)
    /* Unlock the WDT registers by two writes */
    Cy_WDT_Unlock();

    Cy_WDT_Disable();

    /* The WDT Lower Limit value is set to 0 and Lower action to None. */
    Cy_WDT_SetLowerLimit(CY_WDT_DEFAULT_LOWER_LIMIT);
    Cy_WDT_SetLowerAction(CY_WDT_LOW_UPPER_LIMIT_ACTION_NONE);
    /* The WDT Warn Limit value is set to 0 and Warn action to None. */
    Cy_WDT_SetWarnLimit(CY_WDT_DEFAULT_WARN_LIMIT);
    Cy_WDT_SetWarnAction(CY_WDT_WARN_ACTION_NONE);
    /* The WDT Upper Limit value is set to 32768 (~1 sec when clk_lf = 32KHz)
    and Upper action to Reset. */
    Cy_WDT_SetUpperLimit(CY_WDT_DEFAULT_UPPER_LIMIT);
    Cy_WDT_SetUpperAction(CY_WDT_LOW_UPPER_LIMIT_ACTION_RESET);

    /* Lock the WDT registers */
    Cy_WDT_Lock();
#endif /* CY_IP_S8SRSSLT */
    Cy_WDT_ClearInterrupt();
}


#if defined(CY_IP_S8SRSSLT)
/*******************************************************************************
* Function Name: Cy_WDT_SetMatch
****************************************************************************//**
*
* Configures the WDT counter match comparison value.
*
* \param match
* The valid range is [0-65535]. The value to be used to match
* against the counter.
*
* \note Not applicable for PSOC4 HVMS/PA.
*
*******************************************************************************/
void Cy_WDT_SetMatch(uint32_t match)
{
    CY_ASSERT_L2(CY_WDT_IS_MATCH_VALID(match));
    CY_REG32_CLR_SET(SRSSLT_WDT_MATCH, SRSSLT_WDT_MATCH_MATCH, match);
}


/*******************************************************************************
* Function Name: Cy_WDT_SetIgnoreBits
****************************************************************************//**
*
* Configures the number of the most significant bits of the Watchdog timer that
* are not checked against the match.
*
* \param bitsNum
* The number of the most significant bits. The valid range is [0-15].
*
* \details The value of bitsNum controls the time-to-reset of the Watchdog timer.
* This happens after 3 successive matches.
*
* \note Certain products may enforce a minimum value for this register
* through design time configuration.
*
* \warning This function changes the WDT interrupt period, therefore
* the device can go into an infinite WDT reset loop. This may happen
* if a WDT reset occurs faster that a device start-up.
*
* \note Not applicable for PSOC4 HVMS/PA.
*
*******************************************************************************/
void Cy_WDT_SetIgnoreBits(uint32_t bitsNum)
{
   CY_ASSERT_L2(CY_WDT_IS_IGNORE_BITS_VALID(bitsNum));
   CY_REG32_CLR_SET(SRSSLT_WDT_MATCH, SRSSLT_WDT_MATCH_IGNORE_BITS, bitsNum);
}
#endif /* CY_IP_S8SRSSLT */


/*******************************************************************************
* Function Name: Cy_WDT_ClearInterrupt
****************************************************************************//**
*
* Clears the WDT interrupt request which is set
* as configured by WDT action and limits.
*
*******************************************************************************/
void Cy_WDT_ClearInterrupt(void)
{
#if defined(CY_IP_S8SRSSLT)
    SRSS_SRSS_INTR = SRSSLT_SRSS_INTR_WDT_MATCH_Msk;

    /* Read the interrupt register to ensure that the initial clearing write has
    * been flushed out to the hardware.
    */
    (void) SRSS_SRSS_INTR;
#elif defined(CY_IP_M0S8SRSSHV)
    WDT->INTR = WDT_INTR_WDT_Msk;

    /* Due to internal synchronization, it takes up to 8 SYSCLK cycles
    * to update after a W1C or reading this register and during this time
    * AHB bus is stalled.
    */
    Cy_SysLib_DelayCycles(8U);
    /* Read the interrupt register to ensure that the initial clearing write has
    * been flushed out to the hardware.
    */
    (void) WDT->INTR;
#endif /* CY_IP_S8SRSSLT */
}


#if defined(__cplusplus)
}
#endif


/* [] END OF FILE */
