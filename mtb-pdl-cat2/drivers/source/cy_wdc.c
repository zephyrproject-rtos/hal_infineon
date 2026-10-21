/***************************************************************************//**
* \file cy_wdc.c
* \version 1.0.2
*
*  This file provides the source code to the API for the WDC driver.
*
********************************************************************************
* \copyright
* (c) (2016-2021), Cypress Semiconductor Corporation (an Infineon company) or
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

#include "cy_wdc.h"
#include "cy_syslib.h"

#if (defined(WCO_WDT_EN) && (WCO_WDT_EN == 1u))

#if defined(__cplusplus)
extern "C" {
#endif


/*******************************************************************************
* Function Name: Cy_WDC_Init
****************************************************************************//**
*
* Initializes the WDC block.
*
*  \param base
*  The base pointer to a structure that describes the registers.
*
*  \param config
*  The pointer to a structure that contains component configuration data.
*
* \return cy_en_wdc_status_t
*  Returns an error if any of the structure pointers is NULL.
*
*  \note
*  Do not call this function when the counters are running. First, disable
*  counters using \ref Cy_WDC_Disable.
*
*  \note
*  This function waits four WDC clock source cycles in order to
*  set the WDC clock source.
*
*******************************************************************************/
cy_en_wdc_status_t Cy_WDC_Init(WCO_Type *base, cy_stc_wdc_config_t const *config)
{
    cy_en_wdc_status_t ret = CY_WDC_BAD_PARAM;

    if ((base != NULL) && (config != NULL))
    {
        CY_ASSERT_L2(CY_WDC_IS_MATCH_VALID(config->counter0ClearOnMatch, config->counter0Match));
        CY_ASSERT_L2(CY_WDC_IS_MATCH_VALID(config->counter1ClearOnMatch, config->counter1Match));
        CY_ASSERT_L2(CY_WDC_IS_BIT_VALID(config->counter2ToggleBit));

        WCO_WDT_MATCH(base) = _VAL2FLD(WCO_WDT_MATCH_WDT_MATCH1, config->counter1Match) |
                              _VAL2FLD(WCO_WDT_MATCH_WDT_MATCH0, config->counter0Match);

        WCO_WDT_CONFIG(base) =  _VAL2FLD(WCO_WDT_CONFIG_WDT_BITS2, config->counter2ToggleBit)       |
                                (config->counter0Interrupt ? CY_WDC_CONFIG_MODE0_INTR : 0U)         |
                                (config->counter1Interrupt ? CY_WDC_CONFIG_MODE1_INTR : 0U)         |
                                (config->counter2Interrupt ? CY_WDC_CONFIG_MODE2_INTR : 0U)         |
                                _BOOL2FLD(WCO_WDT_CONFIG_WDT_CLEAR0, config->counter0ClearOnMatch)  |
                                _BOOL2FLD(WCO_WDT_CONFIG_WDT_CLEAR1, config->counter1ClearOnMatch)  |
                                (CY_WDC_CASCADE_ALL & config->countersCascade);

        Cy_WDC_SetClockSource(base, config->clockSource);

        ret = CY_WDC_SUCCESS;
    }

    return (ret);
}


/*******************************************************************************
* Function Name: Cy_WDC_DeInit
****************************************************************************//**
*
*  De-initializes the WDC block, returns register values to their default state.
*
*  \param base
*  The base pointer to a structure that describes the registers.
*
*  \note
*  Do not call this function when the counters are running. First, disable
*  counters using \ref Cy_WDC_Disable.
*
*  \note
*  Call this function only after calling the \ref Cy_WDC_Init() function.
*
*  \note
*  This function does not reset the WDC match value.
*
*  \note
*  This function takes 10 WDC clock source cycles in order perform
*  de-initialization.
*
*******************************************************************************/
void Cy_WDC_DeInit(WCO_Type *base)
{
    uint16_t delayOneCycleUs;

    delayOneCycleUs =
        (Cy_WDC_GetClockSource(base) == CY_WDC_CLOCK_ILO) ? CY_WDC_CLK_ILO_CYCLE_US : CY_WDC_CLK_WCO_CYCLE_US;

    /* Set the default value for the control register and reset counters */
    WCO_WDT_CONTROL(base) = CY_WDC_CONTROL_RESET_VAL;

    /* Wait for three clock cycles until changes are applied */
    Cy_SysLib_DelayUs(delayOneCycleUs * 3U);

    /* Set the default value for the CONFIG register except the clock selection bits */
    WCO_WDT_CONFIG(base) &= CY_WDC_CONFIG_DEFAULT_VAL_MASK;

    /* Wait for three clock cycles until changes are applied */
    Cy_SysLib_DelayUs(delayOneCycleUs * 3U);

    /* Disable the WDC clock */
    WCO_WDT_CLKEN(base) &= ~(WCO_WDT_CLKEN_CLK_ILO_EN_FOR_WDT_Msk |
                             WCO_WDT_CLKEN_CLK_WCO_EN_FOR_WDT_Msk);

    /* Wait for four clock cycles until the clock is disabled */
    Cy_SysLib_DelayUs(delayOneCycleUs * 4U);
}


/*******************************************************************************
* Function Name: Cy_WDC_GetCountCascaded
****************************************************************************//**
*
*  Reports the current value of combined C1-C0 cascaded counters.
*
*  \param base
*  The base pointer to a structure that describes the registers.
*
*  \note
*  Enable both counters, and cascade C0 to C1
*  before calling this function. C2 is not reported.
*  Instead, to get a 64-bit C2-C1-C0 cascaded value,
*  call this function followed by
*  Cy_WDC_GetCount(base, CY_WDC_COUNTER2), and then combine the results.
*  \note This function does not return the correct result when it is called
*  after the Cy_WDC_Enable() or Cy_WDC_ResetCounters() function with
*  a delay less than three WDC clock source cycles. The recommended waitUs
*  parameter value is defined by \ref CY_WDC_CLK_ILO_3CYCLES_US and
*  \ref CY_WDC_CLK_WCO_3CYCLES_US macros.
*
* \return  The value of combined C1-C0 cascaded counters.
*
*******************************************************************************/
uint32_t Cy_WDC_GetCountCascaded(WCO_Type const *base)
{
    uint32_t countVal = WCO_WDT_CTRLOW(base);
    uint32_t counter1 = countVal >> WCO_WDT_CTRLOW_WDT_CTR1_Pos;
    uint32_t counter0 = countVal & WCO_WDT_CTRLOW_WDT_CTR0_Msk;
    uint32_t match0 = _FLD2VAL(WCO_WDT_MATCH_WDT_MATCH0, WCO_WDT_MATCH(base));
    uint32_t match1 = _FLD2VAL(WCO_WDT_MATCH_WDT_MATCH1, WCO_WDT_MATCH(base));

    /*
     * The counter  counter0 goes to zero when it reaches match0
     * value (c0ClearOnMatch = 1) or reaches the maximum
     * value (c0ClearOnMatch = 0). The counter counter1 increments on
     * the next rising edge of the WDC clock after
     * the Clear On Match event takes place.
     * The software increments counter1 to eliminate the case
     * when both counter0 and counter1 counters have zeros.
    */
    if (0UL == counter0)
    {
        counter1++;
    }

    /* Check if counter0 is Free running */
    if (0UL == _FLD2VAL(WCO_WDT_CONFIG_WDT_CLEAR0, WCO_WDT_CONFIG(base)))
    {
        /* Save the match0 value with the correction when counter0
         *  goes to zero when it reaches the match0 value.
        */
        countVal = match0 + 1UL;

        if (0UL != counter1)
        {
            /* Set the match to the maximum value */
            match0 = WCO_WDT_CTRLOW_WDT_CTR0_Msk;
        }

        if (countVal < counter0)
        {
            /* Decrement counter1 when the counter0 is greater than the match0 value */
            counter1--;
        }
    }

    /* Add the correction to counter0 */
    counter0 += counter1;

    /* Set the counter1 match value to 65535 when the counter1 is free running */
    if (0UL == _FLD2VAL(WCO_WDT_CONFIG_WDT_CLEAR1, WCO_WDT_CONFIG(base)))
    {
        match1 = WCO_WDT_CTRLOW_WDT_CTR1_Msk >> WCO_WDT_CTRLOW_WDT_CTR1_Pos;
    }

    /* Check for overflow */
    if (match1 < counter1)
    {
        /* Reset counter0 in order to disable the added correction of the counter1 value */
        counter0 = 0UL;

        /* Reset counter1 to prevent the wrong cascaded value calculation
         * because counter1 is updated only on the following clock edge after clearing counter0
         */
        counter1 = 0UL;
    }

    /* Calculate the combined value for C1-C0 cascaded counters */
    countVal = counter0 + (counter1 * match0);

    return (countVal);
}


/*******************************************************************************
* Function Name: SetClockSource
****************************************************************************//**
*
*  Sets the clock source for WDC timers.
*
*  \param base
*  The base pointer to a structure describes registers.
*
*  \param source
*  WDC timers clock source. See \ref cy_en_wdc_clock_t
*
*  \warning WDC reset is required if counters source was switched while
*  any of the counters were running. Call the Cy_WDC_ResetCounters() function after
*  WDC source switching.
*  It is highly recommended to disable WDC before clock source
*  switching. Changing the WDC clock source may change the functionality that
*  uses WDC as the clock source.
*
*******************************************************************************/
void Cy_WDC_SetClockSource(WCO_Type *base, cy_en_wdc_clock_t source)
{
    CY_ASSERT_L2(CY_WDC_IS_CLOCK_VALID(source));

    /* Reset both _EN bits in the WCO_WDT_CLKEN register */
    WCO_WDT_CLKEN(base) &= ~(WCO_WDT_CLKEN_CLK_ILO_EN_FOR_WDT_Msk |
                             WCO_WDT_CLKEN_CLK_WCO_EN_FOR_WDT_Msk);

    if (Cy_WDC_GetClockSource(base) != source)
    {
        Cy_SysLib_DelayUs((CY_WDC_CLOCK_ILO == source) ? CY_WDC_CLK_ILO_4CYCLES_US : CY_WDC_CLK_WCO_4CYCLES_US);
        CY_REG32_CLR_SET(WCO_WDT_CONFIG(base), WCO_WDT_CONFIG_LFCLK_SEL, source);
    }

    if(CY_WDC_CLOCK_ILO == source)
    {
        WCO_WDT_CLKEN(base) |= WCO_WDT_CLKEN_CLK_ILO_EN_FOR_WDT_Msk;
    }
    else
    {
        WCO_WDT_CLKEN(base) |= WCO_WDT_CLKEN_CLK_WCO_EN_FOR_WDT_Msk;
    }
}

#if defined(__cplusplus)
}
#endif

#endif /* WCO_WDT_EN */

/* [] END OF FILE */
