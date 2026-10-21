/***************************************************************************//**
* \file cy_systick.h
* \version 1.20.2
*
* Provides the API declarations of the SysTick driver.
*
********************************************************************************
* \copyright
* Copyright 2016-2021 Cypress Semiconductor Corporation
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

#ifndef CY_SYSTICK_H
#define CY_SYSTICK_H

/**
* \addtogroup group_arm_system_timer
* \{
* Provides vendor-specific SysTick API.
*
* The functions and other declarations used in this driver are in cy_systick.h.
* You can include cy_pdl.h to get access to all functions
* and declarations in the PDL.
*
* The SysTick timer is part of the CPU. The timer is a down counter with a 24-bit
* reload/tick value that is clocked by the System clock or LF clock.
* The timer has the capability to generate an interrupt when the set number of
* ticks expires and the counter is reloaded. This interrupt is available as part
* of the Nested Vectored Interrupt Controller (NVIC) for service by the CPU
* and can be used for general-purpose timing control in user code.
*
* The timer is independent of the CPU (except for the clock), which is useful
* in applications requiring precise timing that do not have a dedicated
* timer/counter available for the job.
*
* \section group_systick_configuration Configuration Considerations
*
* The \ref Cy_SysTick_Init() performs all required driver's initialization and
* enables the timer. The function accepts two parameters: clock source
* \ref cy_en_systick_clock_source_t and the timer interval. You must ensure
* the selected clock source for SysTick is enabled. The callbacks can be
* registered/unregistered any time after \ref Cy_SysTick_Init() by calling
* \ref Cy_SysTick_SetCallback().
*
* Changing the SysTick clock source and/or its frequency will change the
* interrupt interval and therefore \ref Cy_SysTick_SetReload() should be called
* to compensate for this change.
*
* Example of SysTick initialization. At first define SysTick callback, which will
* be invoked at each SysTick interrupt.
* \snippet systick_snippet.c snippet_Cy_SysTick_Callback
* At second step initialize SysTick and register created callback function.
* \snippet systick_snippet.c snippet_Cy_SysTick_Configuration
*
* \section group_systick_more_information More Information
*
* Refer to the SysTick section of the ARM reference guide for complete details
* on the registers and their use. See also the "CPU Subsystem (CPUSS)" chapter
* of the device technical reference manual (TRM).
*
* \section group_systick_changelog Changelog
*
* <table class="doxtable">
* <tr><th>Version</th><th>Changes</th><th>Reason for Change</th></tr>
* <tr>
* <td>1.20.2</td>
* <td>Update the paths to the code snippets.</td>
* <td>PDL structure update.</td>
* </tr>
* <tr>
* <td>1.20.1</td>
* <td>
*   - Added information that setting reload value to zero has no effect because the SysTick exception
*     request and count flag are activated when counting from 1 to 0.</td>
* <td>Documentation enhancement.</td>
* </tr>
* <tr>
* <td>1.20</td>
* <td>
*   - Added \ref Cy_SysTick_IsEnabled() to return timer's enable/disable state.</td>
* <td>Implementation enhancement.</td>
* </tr>
* <tr>
* <td>1.10</td>
* <td>
*   - Added CY_ASSERT_L1 for the input parameter of the \ref Cy_SysTick_Init() and \ref Cy_SysTick_SetReload() functions.
*   - Updated register access style of the Cy_SysTick_SetClockSource() function.
*   - Fixed MISRA violation in \ref Cy_SysTick_GetClockSource().
*   - Noted that \ref Cy_SysTick_Clear() clears the count flag.
*   - Noted that \ref Cy_SysTick_GetCountFlag() is available in the polling mode only.
*   - Specified the valid range for the interval parameter of the \ref Cy_SysTick_Init().
*   - Added SysTick initialization code snippet.</td>
* <td>Implementation and documentation enhancements.</td>
* </tr>
* <tr>
* <td>1.0</td>
* <td>Initial version</td>
* <td></td>
* </tr>
* </table>
*
* \defgroup group_systick_macros Macros
* \defgroup group_systick_functions Functions
* \defgroup group_systick_data_structures Data Structures
*/

#include <stdint.h>
#include "cy_syslib.h"
#include "cy_device.h"

#ifdef __cplusplus
extern "C" {
#endif

/** \cond */
typedef void (*Cy_SysTick_Callback)(void);
/** \endcond */

/**
* \addtogroup group_systick_data_structures
* \{
*/
/** SysTick clocks sources */
typedef enum
{
    CY_SYSTICK_CLOCK_SOURCE_CLK_LF    = 0u,     /**< The low frequency clock clk_lf is selected. */
    CY_SYSTICK_CLOCK_SOURCE_CLK_CPU   = 1u,     /**< The System clock is selected. */
} cy_en_systick_clock_source_t;

/** \} group_systick_data_structures */


/** \cond Macros for the conditions used by CY_ASSERT calls */

#define CY_SYSTICK_IS_RELOAD_VALID(load)         ((load) <= 0xFFFFFFUL)

/** \endcond */


/**
* \addtogroup group_systick_functions
* \{
*/

void Cy_SysTick_Init(cy_en_systick_clock_source_t clockSource, uint32_t interval);
void Cy_SysTick_Enable(void);
void Cy_SysTick_Disable(void);
__STATIC_INLINE bool Cy_SysTick_IsEnabled(void);
Cy_SysTick_Callback Cy_SysTick_SetCallback(uint32_t number, Cy_SysTick_Callback function);
Cy_SysTick_Callback Cy_SysTick_GetCallback(uint32_t number);
void Cy_SysTick_SetClockSource(cy_en_systick_clock_source_t clockSource);
cy_en_systick_clock_source_t Cy_SysTick_GetClockSource(void);
__STATIC_INLINE void Cy_SysTick_EnableInterrupt(void);
__STATIC_INLINE void Cy_SysTick_DisableInterrupt(void);
__STATIC_INLINE void Cy_SysTick_SetReload(uint32_t value);
__STATIC_INLINE uint32_t Cy_SysTick_GetReload(void);
__STATIC_INLINE uint32_t Cy_SysTick_GetValue(void);
__STATIC_INLINE uint32_t Cy_SysTick_GetCountFlag(void);
__STATIC_INLINE void Cy_SysTick_Clear(void);

/** \} group_systick_functions */


/**
* \addtogroup group_systick_macros
* \{
*/

/** Driver major version */
#define SYSTICK_DRV_VERSION_MAJOR       1

/** Driver minor version */
#define SYSTICK_DRV_VERSION_MINOR       20

/** Number of the callbacks assigned to the SysTick interrupt */
#define CY_SYS_SYST_NUM_OF_CALLBACKS         (5u)

/** \} group_systick_macros */


/** \cond */
/** Interrupt number in the vector table */
#define CY_SYSTICK_IRQ_NUM                   (15u)
/** \endcond */

/**
* \addtogroup group_systick_functions
* \{
*/

/*******************************************************************************
* Function Name: Cy_SysTick_EnableInterrupt
****************************************************************************//**
*
* Enables the SysTick interrupt.
*
* \sideeffect Clears the SysTick count flag if it was set
*
*******************************************************************************/
__STATIC_INLINE void Cy_SysTick_EnableInterrupt(void)
{
    SYSTICK_CTRL = SYSTICK_CTRL | SysTick_CTRL_TICKINT_Msk;
}


/*******************************************************************************
* Function Name: Cy_SysTick_DisableInterrupt
****************************************************************************//**
*
* Disables the SysTick interrupt.
*
* \sideeffect Clears the SysTick count flag if it was set
*
*******************************************************************************/
__STATIC_INLINE void Cy_SysTick_DisableInterrupt(void)
{
    SYSTICK_CTRL = SYSTICK_CTRL & ~SysTick_CTRL_TICKINT_Msk;
}


/*******************************************************************************
* Function Name: Cy_SysTick_SetReload
****************************************************************************//**
*
* Sets the value the counter is set to on a startup and after it reaches zero.
* This function does not change or reset the current sysTick counter value, so
* it should be cleared using the Cy_SysTick_Clear() API.
*
* \param value: The valid range is [0x0-0x00FFFFFF]. The counter reset value.
* \note Zero no effect because the SysTick exception request and count flag
* are activated when counting from 1 to 0.
*
*******************************************************************************/
__STATIC_INLINE void Cy_SysTick_SetReload(uint32_t value)
{
    CY_ASSERT_L1(CY_SYSTICK_IS_RELOAD_VALID(value));

    SYSTICK_LOAD = (value & SysTick_LOAD_RELOAD_Msk);
}


/*******************************************************************************
* Function Name: Cy_SysTick_GetReload
****************************************************************************//**
*
* Gets the value the counter is set to on a startup and after it reaches zero.
*
* \return The counter reset value.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_SysTick_GetReload(void)
{
    return (SYSTICK_LOAD);
}


/*******************************************************************************
* Function Name: Cy_SysTick_GetValue
****************************************************************************//**
*
* Gets the current SysTick counter value.
*
* \return The current SysTick counter value.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_SysTick_GetValue(void)
{
    return (SYSTICK_VAL);
}


/*******************************************************************************
* Function Name: Cy_SysTick_Clear
****************************************************************************//**
*
* Clears the SysTick counter for a well-defined startup.
*
* \sideeffect Clears the SysTick count flag.
*
*******************************************************************************/
__STATIC_INLINE void Cy_SysTick_Clear(void)
{
    SYSTICK_VAL = 0u;
}


/*******************************************************************************
* Function Name: Cy_SysTick_GetCountFlag
****************************************************************************//**
*
* Gets the values of the count flag. The count flag is set once the SysTick
* counter reaches zero. The flag is cleared on read.
*
* \return Returns a non-zero value if a flag is set; otherwise a zero is
* returned.
*
* \sideeffect Clears the SysTick count flag.
*
* \note Applicable only in Polling mode. If the SysTick interrupt is enabled,
* the count flag will be cleared automatically on interrupt event.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_SysTick_GetCountFlag(void)
{
    return (SYSTICK_CTRL & SysTick_CTRL_COUNTFLAG_Msk);
}

/*******************************************************************************
* Function Name: Cy_SysTick_IsEnabled
****************************************************************************//**
*
* Returns the SysTick enable/disable state.
*
* \return Returns true is the timer is enabled; otherwise false is returned.
*
*******************************************************************************/
__STATIC_INLINE bool Cy_SysTick_IsEnabled(void)
{
    return ((SYSTICK_CTRL & SysTick_CTRL_ENABLE_Msk) != 0U);
}


/** \} group_systick_functions */

#ifdef __cplusplus
}
#endif

#endif /* CY_SYSTICK_H */

/** \} group_systick */


/* [] END OF FILE */
