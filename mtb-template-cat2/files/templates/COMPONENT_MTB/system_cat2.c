/***************************************************************************//**
* \file system_cat2.c
* \version 2.1
*
* The device system-source file.
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

#include <stdbool.h>
#include "system_cat2.h"
#include "cy_device.h"
#include "cy_device_headers.h"
#include "cy_syslib.h"
#include "cy_sysclk.h"
#include "cy_wdt.h"


/*******************************************************************************
* SystemCoreClockUpdate()
*******************************************************************************/

/** Default SYSCLK system core frequency in Hz */
#define CY_CLK_SYSTEM_FREQ_HZ_DEFAULT       (24000000UL)


/**
* Holds the SYSCLK system core clock,
* which is the system clock frequency supplied to the SysTick timer and the
* processor core clock.
* This variable implements CMSIS Core global variable.
* Refer to the [CMSIS documentation]
* (http://www.keil.com/pack/doc/CMSIS/Core/html/group__system__init__gr.html "System and Clock Configuration")
* for more details.
* This variable can be used by debuggers to query the frequency
* of the debug timer or to configure the trace clock speed.
*
* \attention Compilers must be configured to avoid removing this variable in case
* the application program is not using it. Debugging systems require the variable
* to be physically present in memory so that it can be examined to configure the debugger. */
uint32_t SystemCoreClock = CY_CLK_SYSTEM_FREQ_HZ_DEFAULT;


/*******************************************************************************
* SystemCoreClockUpdate (void)
*******************************************************************************/

/* Do not use these definitions directly in your application */
#define CY_DELAY_MS_OVERFLOW_THRESHOLD  (0x8000u)
#define CY_DELAY_1K_THRESHOLD           (1000u)
#define CY_DELAY_1M_THRESHOLD           (1000000u)

uint32_t cy_delayFreqKhz  = CY_SYSLIB_DIV_ROUNDUP(CY_CLK_SYSTEM_FREQ_HZ_DEFAULT, CY_DELAY_1K_THRESHOLD);

uint8_t cy_delayFreqMhz  = (uint8_t)CY_SYSLIB_DIV_ROUNDUP(CY_CLK_SYSTEM_FREQ_HZ_DEFAULT, CY_DELAY_1M_THRESHOLD);

uint32_t cy_delay32kMs    = CY_DELAY_MS_OVERFLOW_THRESHOLD *
                            CY_SYSLIB_DIV_ROUNDUP(CY_CLK_SYSTEM_FREQ_HZ_DEFAULT, CY_DELAY_1K_THRESHOLD);


/*******************************************************************************
* Function Name: SystemInit
****************************************************************************//**
*
* Initializes the system: unlocks and disables the WDT, disables the interrupts
* and calls the \ref Cy_SystemInit() function.
*
* \note
* This function does not initialize clocks.
* To set up clocks in pre-main, define strong function \ref Cy_SystemInit with
* your custom clock initialization.
*
* \warning For PSoC4 HVMS/PA the Watchdog timer should be unlocked before
* being disabled.
*
*******************************************************************************/
void SystemInit(void)
{
#if defined(CY_IP_M0S8SRSSHV)
    /* The Watchdog timer should be unlocked before being disabled */
    Cy_WDT_Unlock();
#endif /* CY_IP_M0S8SRSSHV */
    Cy_WDT_Disable();
#if defined(CY_IP_M0S8SRSSHV)
    Cy_WDT_Lock();
#endif /* CY_IP_M0S8SRSSHV */
    __disable_irq();
    Cy_SystemInit();
}


/*******************************************************************************
* Function Name: Cy_SystemInit
****************************************************************************//**
*
* Empty weak function. The application code provides a strong function
* for the actual implementation.
*
* \note Call \ref SystemCoreClockUpdate() in this function if this function
* affects the HFCLK frequency.
*
*******************************************************************************/
__WEAK void Cy_SystemInit(void)
{
    /* A strong function can be provided instead of this function */
}


/*******************************************************************************
* Function Name: SystemCoreClockUpdate
****************************************************************************//**
*
* Gets core clock frequency, updates \ref SystemCoreClock, and global variables
* used by the \ref Cy_SysLib_Delay(), \ref Cy_SysLib_DelayUs(), and
* \ref Cy_SysLib_DelayCycles().
*
* \attention The function must be called whenever the core clock is changed
* during program execution.
*
*******************************************************************************/
void SystemCoreClockUpdate (void)
{
    uint32_t locCoreClock = Cy_SysClk_ClkSysGetFrequency();

    if (0UL != locCoreClock)
    {
        SystemCoreClock = locCoreClock;

        /* Sets clock frequency for Delay API */
        cy_delayFreqMhz = (uint8_t)CY_SYSLIB_DIV_ROUNDUP(SystemCoreClock, CY_DELAY_1M_THRESHOLD);
        cy_delayFreqKhz = CY_SYSLIB_DIV_ROUNDUP(SystemCoreClock, CY_DELAY_1K_THRESHOLD);
        cy_delay32kMs   = CY_DELAY_MS_OVERFLOW_THRESHOLD * cy_delayFreqKhz;
    }
}


/* [] END OF FILE */
