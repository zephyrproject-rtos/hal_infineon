/***************************************************************************//**
* \file cy_sysint.h
* \version 1.10.2
*
* \brief
* Provides an API declaration of the SysInt driver
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
* \addtogroup group_sysint
* \{
* The SysInt driver provides an API to configure the device peripheral interrupts.
* It provides a lightweight interface to complement
* the <a href="https://www.keil.com/pack/doc/CMSIS/Core/html/group__NVIC__gr.html">CMSIS core NVIC API</a>.
* The provided functions are applicable for all cores in a device and they can
* be used to configure and connect device peripheral interrupts to one or more
* cores.
*
* The functions and other declarations used in this driver are in cy_sysint.h.
* You can include cy_pdl.h to get access to all functions
* and declarations in the PDL.
*
* \section group_sysint_vector_table Vector Table
* The vector table defines the entry addresses of the processor exceptions and
* the device specific interrupts. It is located at the start address of the flash
* and is copied by the startup code to RAM. The symbol code __VECTOR_TABLE is the
* address of the vector table in the startup code and the register SCB->VTOR
* holds the start address of the vector table. See \ref group_system_config_device_vector_table
* section for the implementation details.
*
* The default interrupt handler functions are defined as weak functions to a dummy handler
* in the startup file. The naming convention is \<interrupt_name\>_IRQHandler.
* Defining these in the user application allows the linker to place them in
* the vector table in flash. For example:
* \code
* void ioss_interrupts_gpio_0_IRQHandler(void)
* {
*     ...
* }
* \endcode
* And can be used like this:
* \snippet sysint_snippet.c snippet_Cy_SysInt_DefineInterruptSource
* \snippet sysint_snippet.c snippet_Cy_SysInt_flashVT
* Using this method avoids the need for a RAM vector table. However in this scenario,
* interrupt handler re-location at run-time is not possible, unless the vector table is
* relocated to RAM.

* \section group_sysint_driver_usage Driver Usage
*
* \subsection group_sysint_initialization Initialization
*
* Interrupt numbers are defined in a device-specific header file, such as
* cy8c4146azi_s433.h, and are consistent with interrupt handlers defined in the
* vector table.
*
* To configure an interrupt, call Cy_SysInt_Init(). Populate
* the configuration structure (\ref cy_stc_sysint_t) and pass it as a parameter
* along with the ISR address. This initializes the interrupt and
* instructs the CPU to jump to the specified ISR vector upon a valid trigger.
* All the supported interrupts are listed in \ref IRQn_Type.
* The priority of these interrupts is determined by the
* interrupt number (index in the \ref IRQn_Type enumeration).
*
* \subsection group_sysint_enable Enable
*
* After initializing an interrupt, use the CMSIS Core
* <a href="https://www.keil.com/pack/doc/CMSIS/Core/html/group__NVIC__gr.html#ga530ad9fda2ed1c8b70e439ecfe80591f">NVIC_EnableIRQ()</a> function
* to enable it. Given an initialization structure named config,
* the function should be called as follows:
* \code
* NVIC_EnableIRQ(config.intrSrc)
* \endcode
*
* \subsection group_sysint_service Writing an interrupt service routine
*
* Servicing interrupts in the Peripheral Drivers should follow a prescribed
* recipe to ensure all interrupts are serviced and duplicate interrupts are not
* received. Any peripheral-specific register that must be written to clear the
* source of the interrupt should be written as soon as possible in the interrupt
* service routine. However, note that due to buffering on the output bus to the
* peripherals, the write clearing of the interrupt may be delayed. After performing
* the normal interrupt service that should respond to the interrupting
* condition, the interrupt register that was initially written to clear the
* register should be read before returning from the interrupt service routine.
* This read ensures that the initial write has been flushed out to the hardware.
* Note, no additional processing should be performed based on the result of this
* read, as this read is intended only to ensure the write operation is flushed.
*
* This final read may indicate a pending interrupt. What this means is that in
* the interval between when the write actually happened at the peripheral and
* when the read actually happened at the peripheral, an interrupting condition
* occurred. This is ok and a return from the interrupt is still the correct
* action. As soon as conditions warrant, meaning interrupts are enabled and
* there are no higher priority interrupts pending, the interrupt will be
* triggered again to service the additional condition.
*
* \section group_sysint_section_configuration_considerations Configuration Considerations
*
* Below is an example of typical interrupt configuration:
* \snippet sysint_snippet.c snippet_Cy_SysInt_DefineInterruptSource
* \snippet sysint_snippet.c snippet_Cy_SysInt_Init
*
* \section group_sysint_more_information More Information
*
* Refer to the technical reference manual (TRM) and the device datasheet.
*
* \section group_sysint_changelog Changelog
* <table class="doxtable">
*   <tr><th>Version</th><th>Changes</th><th>Reason for Change</th></tr>
*   <tr>
*     <td rowspan="1">1.10.2</td>
*     <td>Updated undefined values in the code snippets.</td>
*     <td>Documentation enhancement.</td>
*   </tr>
*   <tr>
*     <td rowspan="2">1.10.1</td>
*     <td>Update the paths to the code snippets.</td>
*     <td>PDL structure update.</td>
*   </tr>
*   <tr>
*     <td>Minor documentation updates. Code snippets were updated.</td>
*     <td>Documentation enhancement.</td>
*   </tr>
*   <tr>
*     <td rowspan="3">1.10</td>
*     <td>Moved vector table declaration to the system header file.</td>
*     <td></td>
*   </tr>
*   <tr>
*     <td>Fixed MISRA violations.</td>
*     <td>MISRA compliance.</td>
*   </tr>
*   <tr>
*     <td>Minor documentation updates.</td>
*     <td>Documentation enhancement.</td>
*   </tr>
*   <tr>
*     <td>1.0</td>
*     <td>Initial version</td>
*     <td></td>
*   </tr>
* </table>
*
* \defgroup group_sysint_macros Macros
* \defgroup group_sysint_globals Global variables
* \defgroup group_sysint_functions Functions
* \defgroup group_sysint_data_structures Data Structures
* \defgroup group_sysint_enums Enumerated Types
*/


#if !defined(CY_SYSINT_H)
#define CY_SYSINT_H

#include <stddef.h>
#include "cy_device.h"
#include "cy_syslib.h"
#include "cy_device_headers.h"

#if defined(__cplusplus)
extern "C" {
#endif


/***************************************
*       Global Variable
***************************************/


/***************************************
*       Global Interrupt
***************************************/

/**
* \addtogroup group_sysint_macros
* \{
*/

/** Driver major version */
#define CY_SYSINT_DRV_VERSION_MAJOR    1

/** Driver minor version */
#define CY_SYSINT_DRV_VERSION_MINOR    10

/** SysInt driver ID */
#define CY_SYSINT_ID CY_PDL_DRV_ID     (0x15U)

/** \} group_sysint_macros */


/***************************************
*       Enumeration
***************************************/

/**
* \addtogroup group_sysint_enums
* \{
*/

/**
* SysInt Driver error codes
*/
typedef enum
{
    CY_SYSINT_SUCCESS   = 0x0UL,                                      /**< Returned successful */
    CY_SYSINT_BAD_PARAM = CY_SYSINT_ID | CY_PDL_STATUS_ERROR | 0x1UL, /**< Bad parameter was passed */
} cy_en_sysint_status_t;

/** NMI connection input */
typedef enum
{
    CY_SYSINT_NMI1       = 1UL, /**< NMI source input 1 */
    CY_SYSINT_NMI2       = 2UL, /**< NMI source input 2 */
    CY_SYSINT_NMI3       = 3UL, /**< NMI source input 3 */
    CY_SYSINT_NMI4       = 4UL, /**< NMI source input 4 */
} cy_en_sysint_nmi_t;

/** \} group_sysint_enums */


/***************************************
*       Configuration Structure
***************************************/

/**
* \addtogroup group_sysint_data_structures
* \{
*/

/**
* Initialization configuration structure for a single interrupt channel
*/
typedef struct {
    IRQn_Type       intrSrc;        /**< Interrupt source */
    uint32_t        intrPriority;   /**< Interrupt priority number (Refer to __NVIC_PRIO_BITS) */
} cy_stc_sysint_t;

/** \} group_sysint_data_structures */


/***************************************
*              Constants
***************************************/

/** \cond INTERNAL */

    #define CY_INT_IRQ_BASE            (16U)    /**< Start location of interrupts in the vector table */

    /* Parameter validation macros */
    #define CY_SYSINT_IS_PRIORITY_VALID(intrPriority)     ((uint32_t)(1UL << __NVIC_PRIO_BITS) > (intrPriority))
    #define CY_SYSINT_IS_VECTOR_VALID(userIsr)            (NULL != (userIsr))

/** \endcond */


/***************************************
*       Function Prototypes
***************************************/

/**
* \addtogroup group_sysint_functions
* \{
*/

cy_en_sysint_status_t Cy_SysInt_Init(const cy_stc_sysint_t* config, cy_israddress userIsr);
cy_israddress Cy_SysInt_SetVector(IRQn_Type IRQn, cy_israddress userIsr);
cy_israddress Cy_SysInt_GetVector(IRQn_Type IRQn);

/** \} group_sysint_functions */

#if defined(__cplusplus)
}
#endif

#endif /* CY_SYSINT_H */

/** \} group_sysint */

/* [] END OF FILE */
