/***************************************************************************//**
* \file cy_ltc.h
* \version 1.0
*
*  This file provides constants and parameter values for the LTC driver.
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
*
*******************************************************************************/

/**
* \addtogroup group_ltc
* \{
*
* Provides a basic 32-bit lifetime counter with a prescaler (/2 to /32).
*
* \note Supported on PSOC4 HVMS/PA.
*
* The functions and other declarations used in this driver are in cy_ltc.h.
* You can include cy_pdl.h to get access to all functions
* and declarations in the PDL.
*
* Provides a basic 32-bit up-counter operation in the DeepSleep domain at a frequency lower
* than \ref group_sysclk_lf, which can provide a Deep Sleep interrupt when set by FW (match WAKEUP
* value) or a regular lifetime counter without an interrupt.
* With the prescaler, the net resolution of the counter becomes 37-bit causing an overflow every 49.7 days. 
* The counter will continue counting upon overflow.
*
* The lifetime counter shall survive all resets except POR/XRES/BOD.
*
* <b> Clock Source </b>
*
* \image html ltc_irq.png "LTC Solution" 
*
* The lifetime counter operates on \ref group_sysclk_lf. The \ref group_sysclk_lf release depends on
* the startup time of the clock. Any AHB writes before \ref group_sysclk_lf is released will
* be not pass through to the actual lifetime counter configuration until the \ref group_sysclk_lf
* starts. If there is a system reset before the synchronization takes place, the
* values will be reset, and FW will have to write the configuration again. FW can
* read the counter value to make sure the counter has started.
*
* The lifetime counter includes a prescaler and is triggered from the \ref group_sysclk_lf clock.
* The prescaler provides the \ref group_sysclk_lf from divide-by-2 up to divide-by-32.
*
* The 32-bit counter runs off of the pre-scaled clock. It is capable of wrapping. The initial value 
* is intended to provide a life-cycle count maintained by software. The value is expected to be
* loaded after POR by software, and software periodically updates flash to the current count.
*
* <b> Application </b>
* * a) The customer wants to know how long the battery has been connected (the same battery that powers our part).
* The lifetime counter and periodic writes are combined to NV memory.
* The lifetime counter is up to every 49.7 days of the roll over, which is used to calculate the total time the battery is connected. \n
* * b) After manufacturing, some devices are frequently put on a ship, and it can take months to arrive
* at the destination. When they arrive, the battery is expected to be still in the ready state. It would be
* better to keep track of actual Lifetime in this mode. In that case, we need to keep
* PILO and Lifetime counter running, disable WDT, CRWDT, and disable Lifetime wake-up.
*
* <b> Power Modes </b>
*
* The "WAKEUP" value is compared against the hardware "COUNT" value. If
* there is a match, a Deep Sleep interrupt occurs.
*
* User does NOT need to wait for enable synchronization before entering deepsleep.
* This will occur within one \ref group_sysclk_lf cycle. But it is recommended to wait for
* the enabled status ( \ref Cy_LTC_IsEnabled ) before entering Deep Sleep.
*
* \section group_rtc_section_configuration Configuration Considerations
*
* Before using the \ref Cy_LTC_SetDivider or \ref Cy_LTC_SetCounterValue function,
* disable the lifetime counter by the \ref Cy_LTC_Disable function.
*
* FW shall wait for the counter disabled synchronization before re-enabling
* the lifetime counter to ensure that the synchronization is completed. The user can read \ref Cy_LTC_IsEnabled
* to check that the lifetime counter is disabled.
*
* \note The user can change the WAKEUP value without disabling the lifetime counter
*
* For example:
* \snippet ltc_snippet.c snippet_LTC_basic
*
* \section group_ltc_section_more_information More Information
*
* For more information on the LTC peripheral, refer to the technical reference
* manual (TRM).
*
* \section group_ltc_changelog Changelog
* <table class="doxtable">
*   <tr><th>Version</th><th>Changes</th><th>Reason for Change</th></tr>
*   <tr>
*     <td>1.0</td>
*     <td>Initial version</td>
*     <td></td>
*   </tr>
* </table>
*
* \defgroup group_ltc_macros Macros
* \defgroup group_ltc_enums Enumerated Types
* \defgroup group_ltc_functions Functions
*
*/

#if !defined(CY_LTC_H)
#define CY_LTC_H

#include <stdint.h>
#include <stdbool.h>
#include "cy_device_headers.h"
#include "cy_device.h"
#include "cy_syslib.h"

#if defined(CY_IP_M0S8SRSSHV)

#if defined(__cplusplus)
extern "C" {
#endif


/*******************************************************************************
*       Function Constants
*******************************************************************************/
/**
* \addtogroup group_ltc_macros
* \{
*/

/** The driver major version */
#define CY_LTC_DRV_VERSION_MAJOR                   1

/** The driver minor version */
#define CY_LTC_DRV_VERSION_MINOR                   0

/** The LTC default wakeup value */
#define CY_LTC_DEFAULT_WAKEUP_VALUE                (0xFFFFFFFFUL)

/** The LTC init counter value */
#define CY_LTC_INIT_COUNTER_VALUE                  (0UL)

/** The LTC driver identifier */
#define CY_LTC_ID                                  CY_PDL_DRV_ID(0x36U)

/** \} group_ltc_macros */


/*******************************************************************************
*        Enumerated Types
*******************************************************************************/
/**
* \addtogroup group_ltc_enums
* \{
*/
/**
* Lifetime prescaler values.
*/
typedef enum
{
    CY_LTC_PRESEL_DIV_2  = 0U, /**< Divide \ref group_sysclk_lf by 2  */
    CY_LTC_PRESEL_DIV_4  = 1U, /**< Divide \ref group_sysclk_lf by 4  */
    CY_LTC_PRESEL_DIV_8  = 2U, /**< Divide \ref group_sysclk_lf by 8  */
    CY_LTC_PRESEL_DIV_16 = 3U, /**< Divide \ref group_sysclk_lf by 16 */
    CY_LTC_PRESEL_DIV_32 = 4U, /**< Divide \ref group_sysclk_lf by 32 */
} cy_en_ltc_div_t;


/** \} group_ltc_enums */


/*******************************************************************************
*        Function Prototypes
*******************************************************************************/
/**
* \addtogroup group_ltc_functions
* \{
*/

void Cy_LTC_Init(void);
bool Cy_LTC_IsEnabled(void);
void Cy_LTC_Enable(void);
void Cy_LTC_Disable(void);
void Cy_LTC_SetDivider(cy_en_ltc_div_t divider);
cy_en_ltc_div_t Cy_LTC_GetDivider(void); 
void Cy_LTC_SetCounterValue(uint32_t count);
uint32_t Cy_LTC_GetCounterValue(void);
void Cy_LTC_SetWakeup(uint32_t wakeupValue);
uint32_t Cy_LTC_GetWakeup(void);
void Cy_LTC_SetInterrupt(void);
bool Cy_LTC_GetInterruptStatus(void);
void Cy_LTC_ClearInterrupt(void);
void Cy_LTC_SetInterruptMask(bool enable);
bool Cy_LTC_GetInterruptStatusMasked(void);

/** \} group_ltc_functions */

#if defined(__cplusplus)
}
#endif

#endif /* CY_IP_M0S8SRSSHV */

#endif /* CY_LTC_H */

/** \} group_ltc */


/* [] END OF FILE */
