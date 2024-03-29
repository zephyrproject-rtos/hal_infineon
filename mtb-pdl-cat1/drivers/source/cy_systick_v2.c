/***************************************************************************//**
* \file cy_systick.c
* \version 1.70.1
*
* Provides the API definitions of the SisTick driver.
*
********************************************************************************
* \copyright
* Copyright (c) (2016-2022), Cypress Semiconductor Corporation (an Infineon company) or
* an affiliate of Cypress Semiconductor Corporation.
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

#include "cy_device.h"

#if defined (CY_IP_M33SYSCPUSS) || defined(CY_IP_M55APPCPUSS)

#include <stddef.h>     /* for NULL */
#include "cy_systick.h"
#include "cy_sysint.h"

static Cy_SysTick_Callback Cy_SysTick_Callbacks[CY_SYS_SYST_NUM_OF_CALLBACKS];
static void Cy_SysTick_ServiceCallbacks(void);

void Cy_SysTick_EnableInterrupt(void)
{
    SYSTICK_CTRL = SYSTICK_CTRL | SysTick_CTRL_TICKINT_Msk;
}

void Cy_SysTick_DisableInterrupt(void)
{
    SYSTICK_CTRL = SYSTICK_CTRL & ~SysTick_CTRL_TICKINT_Msk;
}

void Cy_SysTick_SetReload(uint32_t value)
{
    CY_ASSERT_L1(CY_SYSTICK_IS_RELOAD_VALID(value));

    SYSTICK_LOAD = (value & SysTick_LOAD_RELOAD_Msk);
}

uint32_t Cy_SysTick_GetReload(void)
{
    return (SYSTICK_LOAD);
}

uint32_t Cy_SysTick_GetValue(void)
{
    return (SYSTICK_VAL);
}

void Cy_SysTick_Clear(void)
{
    SYSTICK_VAL = 0u;
}

uint32_t Cy_SysTick_GetCountFlag(void)
{
    return (SYSTICK_CTRL & SysTick_CTRL_COUNTFLAG_Msk);
}

void Cy_SysTick_Init(cy_en_systick_clock_source_t clockSource, uint32_t interval)
{
    CY_ASSERT_L1(CY_SYSTICK_IS_RELOAD_VALID(interval));

    uint32_t i;

    for (i = 0u; i<CY_SYS_SYST_NUM_OF_CALLBACKS; i++)
    {
        Cy_SysTick_Callbacks[i] = NULL;
    }

    (void)Cy_SysInt_SetVector(CY_SYSTICK_IRQ_NUM, Cy_SysTick_ServiceCallbacks); /* Suppress a compiler warning about unused return value */
    Cy_SysTick_SetClockSource(clockSource);

    Cy_SysTick_SetReload(interval);
    Cy_SysTick_Clear();
    Cy_SysTick_Enable();
}

void Cy_SysTick_Enable(void)
{
    Cy_SysTick_EnableInterrupt();
    SYSTICK_CTRL |= SysTick_CTRL_ENABLE_Msk;
}

void Cy_SysTick_Disable(void)
{
    Cy_SysTick_DisableInterrupt();
    SYSTICK_CTRL &= ~SysTick_CTRL_ENABLE_Msk;
}


#if defined(CY_PDL_TZ_ENABLED) && (defined(__SAUREGION_PRESENT) && (__SAUREGION_PRESENT == 1))

void Cy_NsSysTick_EnableInterrupt(void)
{
    SYSTICK_NS_CTRL = SYSTICK_NS_CTRL | SysTick_CTRL_TICKINT_Msk;
}


void Cy_NsSysTick_DisableInterrupt(void)
{
    SYSTICK_NS_CTRL = SYSTICK_NS_CTRL & ~SysTick_CTRL_TICKINT_Msk;
}

void Cy_NsSysTick_Enable(void)
{
    Cy_NsSysTick_EnableInterrupt();
    SYSTICK_NS_CTRL |= SysTick_CTRL_ENABLE_Msk;
}

void Cy_NsSysTick_Disable(void)
{
    Cy_NsSysTick_DisableInterrupt();
    SYSTICK_NS_CTRL &= ~SysTick_CTRL_ENABLE_Msk;
}
#endif

void Cy_SysTick_SetClockSource(cy_en_systick_clock_source_t clockSource)
{
    if (clockSource == CY_SYSTICK_CLOCK_SOURCE_CLK_CPU)
    {
        SYSTICK_CTRL |= SysTick_CTRL_CLKSOURCE_Msk;
    }
    else
    {
#ifdef CY_PDL_TZ_ENABLED
        CPUSS_SYSTICK_S_CTL = _VAL2FLD(CPUSS_SYSTICK_S_CTL_CLOCK_SOURCE, (uint32_t) clockSource);
#else
        CPUSS_SYSTICK_NS_CTL = _VAL2FLD(CPUSS_SYSTICK_NS_CTL_CLOCK_SOURCE, (uint32_t) clockSource);
#endif

        SYSTICK_CTRL &= ~SysTick_CTRL_CLKSOURCE_Msk;
    }
}

cy_en_systick_clock_source_t Cy_SysTick_GetClockSource(void)
{
    cy_en_systick_clock_source_t returnValue;

    if ((SYSTICK_CTRL & SysTick_CTRL_CLKSOURCE_Msk) != 0u)
    {
        returnValue = CY_SYSTICK_CLOCK_SOURCE_CLK_CPU;
    }
    else
    {
#ifdef CY_PDL_TZ_ENABLED
        returnValue =  (cy_en_systick_clock_source_t) ((uint32_t) _FLD2VAL(CPUSS_SYSTICK_S_CTL_CLOCK_SOURCE, CPUSS_SYSTICK_S_CTL));
#else
        returnValue =  (cy_en_systick_clock_source_t) ((uint32_t) _FLD2VAL(CPUSS_SYSTICK_NS_CTL_CLOCK_SOURCE, CPUSS_SYSTICK_NS_CTL));
#endif

    }

    return(returnValue);
}

Cy_SysTick_Callback Cy_SysTick_SetCallback(uint32_t number, Cy_SysTick_Callback function)
{
    Cy_SysTick_Callback retVal;

    if (number < CY_SYS_SYST_NUM_OF_CALLBACKS)
    {
        retVal = Cy_SysTick_Callbacks[number];
        Cy_SysTick_Callbacks[number] = function;
    }
    else
    {
        retVal = NULL;
    }

    return (retVal);
}

Cy_SysTick_Callback Cy_SysTick_GetCallback(uint32_t number)
{
    Cy_SysTick_Callback retVal;

    if (number < CY_SYS_SYST_NUM_OF_CALLBACKS)
    {
        retVal = Cy_SysTick_Callbacks[number];
    }
    else
    {
        retVal = NULL;
    }

    return (retVal);
}

static void Cy_SysTick_ServiceCallbacks(void)
{
    uint32_t i;

    /* Verify that tick timer flag was set */
    if (0u != Cy_SysTick_GetCountFlag())
    {
        for (i=0u; i < CY_SYS_SYST_NUM_OF_CALLBACKS; i++)
        {
            if (Cy_SysTick_Callbacks[i] != NULL)
            {
                (void)(Cy_SysTick_Callbacks[i])();
            }
        }
    }
}

#endif

/* [] END OF FILE */
