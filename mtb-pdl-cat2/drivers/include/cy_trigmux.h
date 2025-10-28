/***************************************************************************//**
* \file cy_trigmux.h
* \version 1.0.1
*
*  This file provides constants and parameter values for the Trigger multiplexer driver.
*
********************************************************************************
* \copyright
* Copyright 2016-2020 Cypress Semiconductor Corporation
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

/**
* \addtogroup group_trigmux
* \{
* The trigger multiplexer provides access to the multiplexer that selects a set
* of trigger output signals from different peripheral blocks to route them to the
* specific trigger input of another peripheral block.
*
* The functions and other declarations used in this driver are in cy_trigmux.h.
* You can include cy_pdl.h to get access to all functions
* and declarations in the PDL.
*
* The TrigMux driver is based on the trigger multiplexer's hardware block.
* The Trigger multiplexer block consists of multiple trigger multiplexers.
* These trigger multiplexers are grouped in trigger groups. All the trigger
* multiplexers in the trigger group share similar input options.
*
* The trigger architecture of the PSOC device is explained in the technical reference
* manual (TRM). Refer to the TRM to better understand the trigger multiplexer routing
* architecture available.
*
* \section group_trigmux_section_Configuration_Considerations Configuration Considerations
*
* To route a trigger signal from one peripheral in the PSOC
* to another, the user must configure a reduction multiplexer and a distribution
* multiplexer. The \ref Cy_TrigMux_Connect is used to configure a trigger multiplexer connection.
*
* The Cy_TrigMux_Connect() function has two main parameters, inTrig and outTrig that
* refer to the input and output trigger lines connected using the multiplexer.
* These parameters are represented in the following format:<br>
* \image html trigmux_parameter_30.png
* All the constants associated with the different trigger signals in the system
* (input and output) are defined as constants in the device configuration header file.
*
* The constants for TrigMux in the device configuration header file are divided into two
* types based on the signal being input/output.
*
* The two types of the input/output parameters are:
* * The parameters for the multiplexer's inputs (input signals of TrigMux);
* * The parameters for the multiplexer's outputs (output signals of TrigMux);
*
* Refer to the TRM for a more detailed description of this architecture and different options.
*
* The steps to connect one peripheral block to the other:
*
* Step 1. Find the trigger group number in the Trigger Group Inputs section of the device
* configuration header file that corresponds to the output of the source peripheral block.
* For example, TRIG0_IN_TCPWM_TR_OVERFLOW0 TrigMux input belongs to Trigger Group 0.
*
* Step 2. Find the same trigger group number in the Trigger Group Outputs section of the
* device configuration header file that corresponds to the trigger group number found in
* Step 1. Select the TrigMux output that can be connected to the destination peripheral
* block. For example, TRIG0_OUT_CPUSS_DMAC_TR_IN0 means that the trigger multiplexer
* Output 0 of Trigger Group 0 can be connected to the CPUSS channel 0 trigger input
*
* Step 3. Call Cy_TrigMux_Connect() API with the constants for the inTrig and outTrig
* parameters found in Steps 1 and Step 2.
* For example:
* \snippet trigmux_snippet.c snippet_Cy_TrigMux_Connect
*
* \section group_trigmux_more_information More Information
* For more information on the TrigMux peripheral, refer to the technical reference manual (TRM).
*
* \section group_trigmux_Changelog Changelog
* <table class="doxtable">
*   <tr><th>Version</th><th>Changes</th><th>Reason for Change</th></tr>
*   <tr>
*     <td>1.0.1</td>
*     <td>Update the paths to the code snippets.</td>
*     <td>PDL structure update.</td>
*   </tr>
*   <tr>
*     <td>1.0</td>
*     <td>Initial version</td>
*     <td></td>
*   </tr>
* </table>
*
* \defgroup group_trigmux_macros Macros
* \defgroup group_trigmux_functions Functions
* \defgroup group_trigmux_enums Enumerated Types
*/

#if !defined(CY_TRIGMUX_H)
#define CY_TRIGMUX_H


#include "cy_syslib.h"

#if defined(CY_IP_M0S8PERI_TR)

#if defined(__cplusplus)
extern "C" {
#endif

/******************************************************************************
 * Macros
 *****************************************************************************/

/**
* \addtogroup group_trigmux_macros
* \{
*/

/** The driver major version */
#define CY_TRIGMUX_DRV_VERSION_MAJOR       1

/** The driver minor version */
#define CY_TRIGMUX_DRV_VERSION_MINOR       0

/** TRIGMUX PDL ID */
#define CY_TRIGMUX_ID                       CY_PDL_DRV_ID(0x33UL) /**< The trigger multiplexer driver identifier */

/** Values for the cycles parameter in the \ref Cy_TrigMux_SwTrigger() function */
#define CY_TRIGGER_INFINITE                 (255UL) /**< The trigger will be active until the user clears it or a hardware deactivates it. */
#define CY_TRIGGER_DEACTIVATE               (0UL)   /**< Use this parameter value to deactivate the trigger. */

/** \} group_trigmux_macros */

/**
* \addtogroup group_trigmux_enums
* \{
*/

/******************************************************************************
 * Enumerations
 *****************************************************************************/

/** The TRIGMUX error codes. */
typedef enum
{
    CY_TRIGMUX_SUCCESS = 0x0UL,                                             /**< Successful */
    CY_TRIGMUX_BAD_PARAM = CY_TRIGMUX_ID | CY_PDL_STATUS_ERROR | 0x1UL,     /**< One or more invalid parameters */
    CY_TRIGMUX_INVALID_STATE = CY_TRIGMUX_ID | CY_PDL_STATUS_ERROR | 0x2UL  /**< Operation not set up or is in an improper state */
} cy_en_trigmux_status_t;

/** \} group_trigmux_enums */

/**
* \addtogroup group_trigmux_functions
* \{
*/

cy_en_trigmux_status_t Cy_TrigMux_Connect(uint32_t inTrig, uint32_t outTrig);
cy_en_trigmux_status_t Cy_TrigMux_SwTrigger(uint32_t trigLine, uint32_t cycles);

/** \} group_trigmux_functions */

#if defined(__cplusplus)
}
#endif

#endif /* defined(CY_IP_M0S8PERI_TR) */

#endif /* CY_TRIGMUX_H */

/** \} group_trigmux */

/* [] END OF FILE */
