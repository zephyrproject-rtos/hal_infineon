/***************************************************************************//**
* \file cy_crwdt.h
* \version 1.0
*
*  This file provides constants and parameter values for the
*  Challenge Response WDT driver.
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
* \addtogroup group_crwdt
* \{
*
* The Challenge Response Watchdog Timer (CRWDT) uses challenge/response inter-operations
* during a measured window to ensure that software is in control.
* \note Supported on PSOC4 HVMS/PA.
*
* The functions and other declarations used in this driver are in cy_crwdt.h.
* You can include cy_pdl.h to get access to all functions
* and declarations in the PDL.
*
** <b> Clock Source </b>
*
* ![](crwdt_limits.png)
* The CRWDT_CNT (UP COUNTER) counter is clocked by LFCLK \ref group_sysclk_lf
*
* <b> Application </b>
*
* The challenge and response values are provided by the Linear Feedback Shift Register (LFSR),
* and are used to validate time logged by CRWDT_CNT (UP COUNTER).
*
* Firmware reads the Linear Feedback Shift Register (LFSR) value from CRWDT_CHALLENGE.
* The actions of reading CRWDT_CHALLENGE or writing CRWDT_RESPONSE both increment the
* Linear Feedback Shift Register (LFSR).
* The CRWDT is serviced by writing the value of CRWDT_RESPONSE in a timely manner.
* that value matches the current Linear Feedback Shift Register (LFSR) value.
*
* Successful servicing resets CRWDT_CNT (UP COUNTER) to zero and a new counting period starts.
*
* <b> Actions </b>
*
* The CRWDT provides early warning and late actions using FAULTS, as well as interrupts, or forces a reset
* if CRWDT was not serviced for long or serviced by incorrect CRWDT_RESPONSEs.
* ![](crwdt_diagram.png)

*
* \section group_crwdt_section_more_information More Information
*
* For more information on the CRWDT peripheral, refer to the technical reference
* manual (TRM).
*
* \section group_crwdt_changelog Changelog
* <table class="doxtable">
*   <tr><th>Version</th><th>Changes</th><th>Reason for Change</th></tr>
*   <tr>
*     <td>1.0</td>
*     <td>Initial version</td>
*     <td></td>
*   </tr>
* </table>
*
* \defgroup group_crwdt_macros Macros
* \{
    \defgroup group_crwdt_actions_bitmask_macros Actions
* \}
* \defgroup group_crwdt_functions Functions
*
*/

#if !defined(CY_CRWDT_H)
#define CY_CRWDT_H

#include <stdint.h>
#include <stdbool.h>
#include "cy_device_headers.h"
#include "cy_device.h"
#include "cy_sysclk.h"
#include "cy_syslib.h"

#if (defined(CY_IP_M0S8SRSSHV) && (1UL == SRSSHV_CRWDT_PRESENT)) || defined (CY_DOXYGEN)

#if defined(__cplusplus)
extern "C" {
#endif


/*******************************************************************************
*       Function Constants
*******************************************************************************/
/**
* \addtogroup group_crwdt_macros
* \{
*/

/** The driver major version */
#define CY_CRWDT_DRV_VERSION_MAJOR                   1

/** The driver minor version */
#define CY_CRWDT_DRV_VERSION_MINOR                   0

/** The CRWDT driver identifier */
#define CY_CRWDT_ID                                  CY_PDL_DRV_ID(0x32U)

/**
* \addtogroup group_crwdt_actions_bitmask_macros
* \{
*/
/** Bit mask for No action allowed */
#define CY_CRWDT_NO_ACTION                          (0UL)

/** Bit mask for Early action */
#define CY_CRWDT_EARLY_ACTION                       (0x1UL)

/** Bit mask for Late action */
#define CY_CRWDT_LATE_ACTION                        (0x10UL)

/** Bit mask for Warn action */
#define CY_CRWDT_WARN_ACTION                        (0x100UL)

/** Bit mask for Fail action */
#define CY_CRWDT_FAIL_ACTION                        (0x800UL)

/** Bit mask for Debug action */
#define CY_CRWDT_DEBUG_ACTION                       (0x80000000U)

/** Bit masks for All available actions */
#define CY_CRWDT_ALL_ACTIONS                        (CY_CRWDT_EARLY_ACTION | \
                                                     CY_CRWDT_LATE_ACTION | \
                                                     CY_CRWDT_WARN_ACTION | \
                                                     CY_CRWDT_FAIL_ACTION | \
                                                     CY_CRWDT_DEBUG_ACTION)
/** \} group_crwdt_actions_bitmask_macros */
/** \} group_crwdt_macros */

/*******************************************************************************
*        Function Prototypes
*******************************************************************************/
/**
* \addtogroup group_crwdt_functions
* \{
*/

void Cy_CRWDT_Init(void);
bool Cy_CRWDT_IsEnabled(void);
void Cy_CRWDT_Enable(void);
void Cy_CRWDT_Disable(void);

uint8_t Cy_CRWDT_GetChallenge(void);
uint8_t Cy_CRWDT_CalculateResponse(uint8_t challengeValue);
void Cy_CRWDT_SetResponse(uint8_t responseValue);

uint32_t Cy_CRWDT_GetUpCnt(void);
void Cy_CRWDT_SetEarlyLimit(uint32_t early);
void Cy_CRWDT_SetWarnLimit(uint32_t warn);
void Cy_CRWDT_SetLateLimit(uint32_t late);
void Cy_CRWDT_SetAction(uint32_t action);

bool Cy_CRWDT_GetInterruptStatus(void);
void Cy_CRWDT_SetInterrupt(void);
void Cy_CRWDT_ClearInterrupt(void);
void Cy_CRWDT_SetInterruptMask(bool enable);
bool Cy_CRWDT_GetInterruptStatusMasked(void);

/** \} group_crwdt_functions */

#if defined(__cplusplus)
}
#endif

#endif /* defined(CY_IP_M0S8SRSSHV) && (1UL == SRSSHV_CRWDT_PRESENT) */

#endif /* CY_CRWDT_H */

/** \} group_crwdt */


/* [] END OF FILE */
