/***************************************************************************//**
* \file cy_syspm.h
* \version 3.10
*
* Provides the function definitions for the power management API.
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
*
*******************************************************************************/

/**
* \addtogroup group_syspm
* \{
*
* Use the System Power Management (SysPm) driver to change power modes and
* reduce system power consumption in power sensitive designs.
*
* The functions and other declarations used in this driver are in cy_syspm.h.
* You can include cy_pdl.h to get access to all functions and declarations
* in the PDL.
*
********************************************************************************
* \section group_syspm_section_configuration Configuration Considerations
********************************************************************************
*
********************************************************************************
* \subsection group_syspm_power_modes Power Modes
********************************************************************************
* PSOC 4 MCUs support three CPU power modes. These power modes
* are intended to minimize average power consumption in an application.
*
* The CPU **Active**, **Sleep** and **Deep Sleep** power modes are
* Arm-defined power modes supported by the Arm CPU instruction
* set architecture (ISA).
*
********************************************************************************
* \subsubsection group_syspm_switching_into_sleep Switching CPU into Sleep
********************************************************************************
*
* All pending interrupts must be cleared before the CPU is put into a
* Sleep mode, even if they are masked.
*
********************************************************************************
* \subsubsection group_syspm_switching_into_deepsleep Switching into Deep Sleep
********************************************************************************
*
* All pending interrupts must be cleared before the system is put into a
* Deep Sleep mode, even if they are masked.
*
********************************************************************************
* \subsection group_syspm_wakingup_from_sleep_deepsleep Waking Up from Sleep or Deep Sleep
********************************************************************************
*
* For Arm-based devices, an interrupt is required for the CPU to wake up.
*
********************************************************************************
* \subsection group_syspm_cb SysPm Callbacks
********************************************************************************
*
* The SysPm driver handles low power callbacks declared in the application.
*
* If there are no callbacks registered, the device executes the power mode
* transition. However, frequently your application firmware must make
* modifications for low power mode. For example, you may need to disable a
* peripheral, or ensure that a message is not being transmitted or received.
*
* To enable this, the SysPm driver implements a callback mechanism. When a lower
* power mode transition is about to take place (either entering or exiting
* \ref group_syspm_power_modes), the registered callbacks for that
* transition are called.
*
* The SysPm driver organizes all the callbacks into a linked list. While
* entering a low power mode, SysPm goes through that linked list from first to
* last, executing the callbacks one after another. While exiting low power mode,
* SysPm goes through that linked list again, but in the opposite direction from
* last to first. This ordering supports prioritization of callbacks relative to
* the transition event.
*
* For example, the picture below shows three callback structures organized into
* a linked list: myDeepSleep1, myDeepSleep2, myDeepSleep3 (represented with the
* \ref cy_stc_syspm_callback_t configuration structure). Each structure
* contains, among other fields, the address of the callback function. The code
* snippets below set this up so that myDeepSleep1 is called first when entering
* the low power mode. This also means that myDeepSleep1 will be the last one to
* execute when exiting the low power mode.
*
* The callback structures after registration:
* \image html syspm_register_eq.png
*
* Your application must register each callback, so that SysPm can execute it.
* Upon registration, the linked list is built by the SysPm driver. Notice
* the &myDeepSleep1 address in the myDeepSleep1
* \ref cy_stc_syspm_callback_t structure. This is filled in by the SysPm driver,
* when you register myDeepSleep1. The cy_stc_syspm_callback_t.order element
* defines the order of their execution by the SysPm driver.
* Call \ref Cy_SysPm_RegisterCallback() to register each callback function.
*
* A callback function is typically associated with a particular driver that
* handles the peripheral. So the callback mechanism enables a peripheral to
* prepare for a low power mode (for instance, shutting down the analog part);
* or to perform tasks while exiting a low power mode (like enabling the analog
* part again).
*
* With the callback mechanism you can prevent switching into a low power mode if
* a peripheral is not ready. For example, driver X is in the process of
* receiving a message. In the callback function implementation simply return
* CY_SYSPM_FAIL in a response to CY_SYSPM_CHECK_READY.
*
* If success is returned while executing a callback, the SysPm driver calls the
* next callback and so on to the end of the list. If at some point a callback
* returns CY_SYSPM_FAIL in response to the CY_SYSPM_CHECK_READY step, all the
* callbacks that have already executed are executed in reverse order, with the
* CY_SYSPM_CHECK_FAIL mode parameter. This allows each callback to know that
* entering the low power mode has failed. The callback can then undo whatever it
* did to prepare for low power mode, if required. For example, if the driver X
* callback shut down the analog part, it can re-enable the analog part.
*
* Let's switch to an example explaining the implementation, setup, and
* registration of three callbacks (myDeepSleep1, myDeepSleep2, myDeepSleep2) in
* the application. The \ref group_syspm_cb_config_consideration are provided
* after the \ref group_syspm_cb_example.
*
********************************************************************************
* \subsection group_syspm_cb_example SysPm Callbacks Example
********************************************************************************
*
* The following code snippets demonstrate how use the SysPm callbacks mechanism.
* We will build the prototype for an application that registers
* three callback functions:
*    -# MyDeepSleepFunc1 - Handles CPU Deep Sleep.
*    -# MyDeepSleepFunc2 - Handles CPU Deep Sleep and is associated with peripheral
*       HW1_address.
*    -# MyDeepSleepFunc3 - Handles entering and exiting system Deep Sleep and is
*       associated with peripheral HW2_address.
*
* We set the myDeepSleep1 and myDeepSleep2 callbacks structures to do
* nothing while entering the low power mode (skip on
* CY_SYSPM_SKIP_BEFORE_TRANSITION -
* see \ref group_syspm_cb_function_implementation in
* \ref group_syspm_cb_config_consideration).
* Skipping the actions while entering low power might be useful if you need
* to save time while switching low power modes. This is because the callback
* function with a skipped mode is not even called avoiding the call and return
* overhead.
*
* Let's first declare the callback functions. Each gets the pointer to the
* \ref cy_stc_syspm_callback_params_t structure as the argument.
*
* \snippet syspm_snippet.c snippet_Cy_SysPm_Callback_Func_Declaration
*
* Now we setup the \ref cy_stc_syspm_callback_params_t structures that we will
* pass to the callback functions. Note that for the MyDeepSleepFunc2 and
* MyDeepSleepFunc3 callbacks we also pass pointers to the peripherals related to
* that callback.
* The configuration considerations related to this structure are described
* in \ref group_syspm_cb_parameters in \ref group_syspm_cb_config_consideration.
*
* \snippet syspm_snippet.c snippet_Cy_SysPm_Callback_Params_Declaration
*
* Now we setup the actual callback configuration structures. Each of these
* contains, among the other fields, the address of the
* \ref cy_stc_syspm_callback_params_t we just set up. We will use the callback
* configuration structures later in the code to register the callbacks in the
* SysPm driver. Again, we set things up so that the MyDeepSleepFunc1 and
* MyDeepSleepFunc2 callbacks do nothing while entering the low power mode
* (skip on CY_SYSPM_SKIP_BEFORE_TRANSITION) - see
* \ref group_syspm_cb_function_implementation in
* \ref group_syspm_cb_config_consideration.
*
* \snippet syspm_snippet.c snippet_Cy_SysPm_Callback_Structure_Declaration
*
* Note that in each case the last two fields are NULL. These are fields used by
* the SysPm driver to set up the linked list of callback functions.
*
* The callback structures are now defined and allocated in the user's
* memory space:
* \image html syspm_before_registration.png
*
* Now we implement the callback functions. See
* \ref group_syspm_cb_function_implementation in
* \ref group_syspm_cb_config_consideration for the instructions on how the
* callback functions should be implemented.
*
* \snippet syspm_snippet.c snippet_Cy_SysPm_Callback_Func_Implementation
*
* Finally, we register the callbacks so that the SysPm driver knows about them.
* The order in which the callbacks will be called depends upon the order in
* which the callbacks are registered. If there are no callbacks registered,
* the device just executes the power mode transition, without additional
* interruptions.
*
* Callbacks that reconfigure global resources, such as clock frequencies, should
* be registered last. They then modify global resources as the final step before
* entering the low power mode, and restore those resources first, as the system
* returns from low power mode.
*
* \snippet syspm_snippet.c snippet_Cy_SysPm_RegisterCallback
*
* We are done configuring three callbacks. Now the SysPm driver will execute the
* callbacks appropriately whenever there is a call to a power mode transition
* function: \ref Cy_SysPm_CpuEnterSleep(), \ref Cy_SysPm_CpuEnterDeepSleep().
*
* Refer to \ref group_syspm_cb_unregistering in
* \ref group_syspm_cb_config_consideration to learn what to do if you need to
* remove the callback from the linked list. You might want to unregister the
* callback for debug purposes.
*
* Refer to \ref group_syspm_cb_flow in \ref group_syspm_cb_config_consideration
* to learn about how the SysPm processes the callbacks.
*
********************************************************************************
* \subsection group_syspm_cb_config_consideration Callback Configuration Considerations
********************************************************************************
*
********************************************************************************
* \subsubsection group_syspm_cb_parameters Callback Function Parameters
********************************************************************************
*
* The **callbackParams** parameter of the callback function is a
* \ref cy_stc_syspm_callback_params_t structure. The second parameter
* (**mode**) is for internal use. In the example code we used a
* dummy value CY_SYSPM_CHECK_READY to eliminate compilation errors associated
* with the enumeration. The driver sets the **mode** field to the correct
* value when calling the callback functions (the mode is referred to as step in
* the \ref group_syspm_cb_function_implementation). The callback function reads
* the value and executes code based on the mode set by the SysPm driver.
* The **base** and **context** fields are optional and can be NULL.
* Some drivers require a base hardware address and context to store information
* about the mode transition. If your callback routine requires access to the
* driver registers or context, provide those values. Be aware of MISRA warnings
* if these parameters are NULL.
*
********************************************************************************
* \subsubsection group_syspm_cb_structures Callback Function Structure
********************************************************************************
*
* For each callback, provide a \ref cy_stc_syspm_callback_t structure. Some
* fields in this structure are maintained by the driver. Use NULL for
* cy_stc_syspm_callback_t.prevItm and cy_stc_syspm_callback_t.nextItm.
* Driver uses these fields to build a linked list of callback functions.
* The value of cy_stc_syspm_callback_t.order element is used to define the order
* how the callbacks are put into linked list, and sequentially, how the
* callbacks are executed. See \ref group_syspm_cb_registering section.
*
* \warning The Cy_SysPm_RegisterCallback() function stores a pointer to the
* cy_stc_syspm_callback_t structure. Do not modify elements of the
* cy_stc_syspm_callback_t structure after the callback is registered.
* You are responsible for ensuring that the structure remains in scope.
* Typically the structure is declared as a global or static variable, or as a
* local variable in the main() function.
*
********************************************************************************
* \subsubsection group_syspm_cb_function_implementation Callback Function Implementation
********************************************************************************
*
* Every callback function should handle four possible steps (referred to as
* "mode") defined in \ref cy_en_syspm_callback_mode_t :
*    * CY_SYSPM_CHECK_READY - Check if ready to enter a power mode.
*    * CY_SYSPM_BEFORE_TRANSITION - The actions to be done before entering
*      the low power mode.
*    * CY_SYSPM_AFTER_TRANSITION - The actions to be done after exiting the
*      low power mode.
*    * CY_SYSPM_CHECK_FAIL - Roll back any actions performed in the callback
*      executed previously with CY_SYSPM_CHECK_READY.
*
* A callback function can skip steps (see \ref group_syspm_skip_callback_modes).
* In our example myDeepSleep1 and myDeepSleep2 callbacks do nothing while
* entering the low power mode (skip on CY_SYSPM_BEFORE_TRANSITION). If there is
* anything preventing low power mode entry - return CY_SYSPM_FAIL in response to
* CY_SYSPM_CHECK_READY in your callback implementation. Note that the callback
* should return CY_SYSPM_FAIL only in response to CY_SYSPM_CHECK_READY. The
* callback function should always return CY_SYSPM_PASS for other modes:
* CY_SYSPM_CHECK_FAIL, CY_SYSPM_BEFORE_TRANSITION, and CY_SYSPM_AFTER_TRANSITION
* (see \ref group_syspm_cb_flow).
*
********************************************************************************
* \subsubsection group_syspm_cb_flow Callbacks Execution Flow
********************************************************************************
*
* This section explains what happens during a power transition, when callbacks
* are implemented and set up correctly. The following discussion assumes:
* * All required callback functions are defined and implemented
* * All cy_stc_syspm_callback_t structures are filled with required values
* * All callbacks are successfully registered
*
* User calls \ref Cy_SysPm_CpuEnterSleep() or \ref Cy_SysPm_CpuEnterDeepSleep().
* It calls each callback with the mode set to CY_SYSPM_CHECK_READY. This
* triggers execution of the code for that mode inside of each user callback.
*
* The intent of CY_SYSPM_CHECK_READY is to only signal if the resources is ready
* to transition. Ideally, no transition changes should be made at this time.
* In some cases a small change may be required. For example a communication
* resource callback may set a flag telling firmware not to start any new
* transition.

* If that process is successful for all callbacks, then
* \ref Cy_SysPm_ExecuteCallback() calls each callback with the mode set to
* CY_SYSPM_BEFORE_TRANSITION. This triggers execution of the code for that mode
* inside each user callback. We then enter the low power mode after all callback
* are executed.
*
* When exiting the low power mode, the SysPm driver executes
* \ref Cy_SysPm_ExecuteCallback() again. This time it calls each callback in
* reverse order, with the mode set to CY_SYSPM_AFTER_TRANSITION. This triggers
* execution of the code for that mode inside each user callback.
*
* A callback can return CY_SYSPM_FAIL only while executing the
* CY_SYSPM_CHECK_READY mode. If that happens, then the remaining callbacks are
* not executed. Any callbacks that have already executed are called again, in
* reverse order, with CY_SYSPM_CHECK_FAIL. This allows the system to return to
* the previous state. If a callback returns a fail then any of the functions
* (\ref Cy_SysPm_CpuEnterSleep(), \ref Cy_SysPm_CpuEnterDeepSleep())
* that attempt to switch the device into
* a low power mode will also return CY_SYSPM_FAIL.
*
* Callbacks that reconfigure global resources, such as clock frequencies,
* should be registered last. They then modify global resources as the final
* step before entering the low power mode, and restore those resources first,
* as the system returns from low power mode.
*
********************************************************************************
* \subsubsection group_syspm_cb_registering Callback Registering
********************************************************************************
*
* While registration the callback is put into the linked list. The
* place where the callback structure is put into the linked list is based on
* cy_stc_syspm_callback_t.order. The callback with the lowest
* cy_stc_syspm_callback_t.order value will be placed at the beginning of linked
* list. The callback with the highest cy_stc_syspm_callback_t.order value will
* be placed at the end of the linked list.
* If there is already a callback structure in the linked list with the same
* cy_stc_syspm_callback_t.order value as you attend to register, then your
* callback will be placed right after such a callback.
*
* Such a registration order defines how the callbacks are executed:
* * Callbacks with the lower cy_stc_syspm_callback_t.order are executed first
* when entering into low power and last when exiting from low power.
* * Callbacks with the higher cy_stc_syspm_callback_t.order are executed last
* when entering into low power and first when exiting from low power.
*
* \snippet syspm_snippet.c snippet_Cy_SysPm_RegisterCallback
*
* Callbacks with equal cy_stc_syspm_callback_t.order values are
* registered in the same order as they are registered:
* \image html syspm_register_eq.png

* Callbacks with a different cy_stc_syspm_callback_t.order value will be
* stored based on the cy_stc_syspm_callback_t.order value, with no matter when
* they when registered:
*
* \image html syspm_register_dif.png
*
* This can be useful to ensure that system resources (clock dividers, etc) are
* changed right before entering low power mode and immediately after exiting
* from low power.
*
********************************************************************************
* \subsubsection group_syspm_cb_unregistering Callback Unregistering
********************************************************************************
*
* Unregistering the callback might be useful when you need to dynamically manage
* the callbacks.
*
* \snippet syspm_snippet.c snippet_Cy_SysPm_UnregisterCallback
* The callback structures after myDeepSleep2 callback is unregistered:
* \image html syspm_unregistration.png
*
********************************************************************************
* \section group_syspm_section_more_information More Information
********************************************************************************
*
* For more information on the SysPm driver,
* refer to the technical reference manual (TRM).
*
********************************************************************************
* \section group_syspm_changelog Changelog
********************************************************************************
*
* <table class="doxtable">
*   <tr><th>Version</th><th>Changes</th><th>Reason for Change</th></tr>
*   <tr>
*     <td>3.10</td>
*     <td>Add OVD and BOD support. \ref group_syspm_function_monitoring.</td>
*     <td>Applicable to PSOC4 HVMS/PA only.</td>
*   </tr>
*   <tr>
*     <td rowspan="2">3.0</td>
*     <td>Added \ref Cy_SysPm_CpuEnterSleepNoCallbacks() and
*         \ref Cy_SysPm_CpuEnterDeepSleepNoCallbacks(). 
*         Alternative to \ref Cy_SysPm_CpuEnterSleep() and
*         \ref Cy_SysPm_CpuEnterDeepSleep() but without execution of
*         registered callbacks. The newly added functions can be used for
*         minimization of flash memory consumption and/or speed-up of
*         the Low-power mode entry/exit. The application is responsible
*         for preparing a device for entering Low-power mode and
*         restoring its state on a wakeup. </td>
*     <td>Flash memory consumption optimization</td>
*   </tr>
*   <tr>
*     <td>Removed unused status macros.</td>
*     <td>Code cleanup.</td>
*   </tr>
*   <tr>
*     <td>2.10.1</td>
*     <td>Update the paths to the code snippets.</td>
*     <td>PDL structure update.</td>
*   </tr>
*   <tr>
*     <td>2.10</td>
*     <td>Corrected the size of the internal callback array to match the number
*         of the supported low power modes.</td>
*     <td>Implementation enhancement.</td>
*   </tr>
*   <tr>
*     <td>2.0</td>
*     <td>\ref Cy_SysPm_CpuEnterDeepSleep is changed so that the
*         \ref Cy_SysClk_DeepSleepCallback registration is needed.
*         The clock tree manipulation code is removed.</td>
*     <td>SysClk enhancement, see \ref group_sysclk_pm</td>
*   </tr>
*   <tr>
*     <td>1.0</td>
*     <td>Initial version</td>
*     <td></td>
*   </tr>
* </table>
*
********************************************************************************
*
* \defgroup group_syspm_macros Macros
* \defgroup group_syspm_functions Functions
* \{
*   \defgroup group_syspm_functions_power       Power Modes
*   \defgroup group_syspm_functions_callback    Low Power Callbacks
*   \defgroup group_syspm_function_monitoring   BOD/OVD monitoring
* \}
* \defgroup group_syspm_data_structures Data Structures
* \defgroup group_syspm_data_enumerates Enumerated Types

* \defgroup group_syspm_function_monitoring   BOD/OVD monitoring
* \{
* The power supply includes monitoring to ensure that the required
* voltage levels exist. The voltage monitoring system includes
* power-on reset (POR), brownout detection (BOD)
* and over-voltage detection (OVD).
*
* <b> BOD </b>
*
* The BOD circuit protects the operating or retaining logic from possibly
* unsafe supply conditions by applying reset to the device.
* The BOD circuit generates a reset if the core voltage dips
* below the minimum safe operating voltage. The system will not come out
* of RESET until the supply is detected to be valid again.
*
* <b> OVD </b>
*
* PSOC HV MS offers two OVD circuits that are VDDD detection (OVD VDDD)
* and VCCD detection (OVD VCCD). Similar to the BOD circuit, the OVD circuit
* detects supply conditions above a threshold and applies a reset. As the
* name suggests, the OVD circuit maintains a device reset,
* if VDDD or VCCD supply stays higher than thresholds. The OVD circuit can
* generate a reset in all device power modes except
* Deep Sleep mode (\ref group_syspm_power_modes).
*
* The OVDs are disabled by default and firmware needs to enable them.
*
* After OVD VDDD is enabled OVD VDDD ok status
* (\ref Cy_SysPm_SupplySupervisionStatus) will always read 1,
* because a detected over-voltage condition will reset the chip.
* After OVD VCCD is enabledOVD VCCD ok status
* (\ref Cy_SysPm_SupplySupervisionStatus) it will always read 1,
* because a detected over-over-voltage condition will reset the chip.
*
* Hardware clears this statuses during POR.
*
* <b> Reset Detection </b>
*
* Use the \ref Cy_SysLib_GetResetReason() function to detect whether the BOD/OVD has
* triggered a device reset.
* \}
*/

#if !defined (CY_SYSPM_H)
#define CY_SYSPM_H

#include <stdbool.h>
#include <stddef.h>

#include "cy_device.h"
#include "cy_syslib.h"

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
*       Register Constants
*******************************************************************************/

/**
* \addtogroup group_syspm_macros
* \{
*/

/** Driver major version */
#define CY_SYSPM_DRV_VERSION_MAJOR       3

/** Driver minor version */
#define CY_SYSPM_DRV_VERSION_MINOR       10

/** SysPm driver identifier */
#define CY_SYSPM_ID                      (CY_PDL_DRV_ID(0x10U))

#if defined(CY_IP_M0S8SRSSHV)
/** \cond */
#define CY_SYSPM_OVD_SEL_IS_VALID(sel)      ((CY_SYSPM_OVD_VDD == (sel)) || \
                                             (CY_SYSPM_OVD_VCC == (sel)))
/** \endcond */
#endif /* defined(CY_IP_M0S8SRSSHV) */

/*******************************************************************************
*       Internal Defines
*******************************************************************************/

/** \cond INTERNAL */

/* Macro to validate parameters in Cy_SysPm_ExecuteCallback() function */
#define CY_SYSPM_IS_CALLBACK_TYPE_VALID(type)           (((type) == CY_SYSPM_SLEEP) || \
                                                         ((type) == CY_SYSPM_DEEPSLEEP))

/* Macro to validate parameters in Cy_SysPm_ExecuteCallback() function */
#define CY_SYSPM_IS_CALLBACK_MODE_VALID(mode)           (((mode) == CY_SYSPM_CHECK_READY) || \
                                                         ((mode) == CY_SYSPM_CHECK_FAIL) || \
                                                         ((mode) == CY_SYSPM_BEFORE_TRANSITION) || \
                                                         ((mode) == CY_SYSPM_AFTER_TRANSITION))

/** \endcond */

/** \} group_syspm_macros */

/*******************************************************************************
*       Configuration Structures
*******************************************************************************/

/**
* \addtogroup group_syspm_data_enumerates
* \{
*/

/** The SysPm function return value status definitions. */
typedef enum
{
    CY_SYSPM_SUCCESS         = 0x0U,                                         /**< Successful. */
    CY_SYSPM_BAD_PARAM       = CY_SYSPM_ID | CY_PDL_STATUS_ERROR | 0x01U,    /**< One or more invalid parameters. */
    CY_SYSPM_TIMEOUT         = CY_SYSPM_ID | CY_PDL_STATUS_ERROR | 0x02U,    /**< A time-out occurred. */
    CY_SYSPM_INVALID_STATE   = CY_SYSPM_ID | CY_PDL_STATUS_ERROR | 0x03U,    /**< The operation is not setup or is in an
                                                                                  improper state. */
    CY_SYSPM_FAIL            = CY_SYSPM_ID | CY_PDL_STATUS_ERROR | 0xFFU     /**< Unknown failure. */
} cy_en_syspm_status_t;


/**
* This enumeration is used to select the low power mode for which the
* appropriate registered callback handler will be executed. For example,
* the registered callback of the type CY_SYSPM_SLEEP will be executed while
* switching into the Sleep power mode.
*/
typedef enum
{
    CY_SYSPM_SLEEP      = 0U,   /**< The Sleep enum callback type */
    CY_SYSPM_DEEPSLEEP  = 1U,   /**< The Deep Sleep enum callback type */
    CY_SYSPM_HIBERNATE  = 2U,    /**< Currently not supported. Reserved for Future. */

} cy_en_syspm_callback_type_t;

#if defined(CY_IP_M0S8SRSSHV)
/**
 * This enumerator is used to select
 * on which line overvoltage will be detected
 */
typedef enum
{
    CY_SYSPM_OVD_VDD = 0U,   /**< Enable for OVD on vddd. */
    CY_SYSPM_OVD_VCC = 1U,   /**< Enable for OVD on vccd. */
} cy_en_syspm_ovd_sel_t;

/**
 * This enumerator is used to select
 * on which detector status will be checked
 */
typedef enum
{
    CY_SYSPM_OVD_VDD_OK = 0U,   /**< Indication status for OVD on vddd. */
    CY_SYSPM_OVD_VCC_OK = 1U,   /**< Indication status for OVD on vccd. */
    CY_SYSPM_BOD_VDD_OK = 2U,   /**< Indication status for BOD on vddd. */
    CY_SYSPM_BOD_VCC_OK = 3U,   /**< Indication status for for BOD on vccd. */
    CY_SYSPM_BOD_HV_OK  = 4U,   /**< Indication status for for BOD on high voltage subsystem. */
}cy_en_syspm_supply_entity_select_t;
#endif /* defined(CY_IP_M0S8SRSSHV) */

/** This enumeration specifies the associated callback mode. This enum defines the callback mode. */
typedef enum
{
    CY_SYSPM_CHECK_READY        = 0x01U,    /**< Callbacks with this mode are executed before entering into the
                                                 low power mode. The purpose of his callback function is to check
                                                 if the device is ready to enter the low power mode. */
    CY_SYSPM_CHECK_FAIL         = 0x02U,    /**< Callbacks with this mode are executed after the CY_SYSPM_CHECK_READY
                                                 callbacks execution returns CY_SYSPM_FAIL.
                                                 The callback with the CY_SYSPM_CHECK_FAIL mode should roll back the
                                                 actions performed in the previously executed callback with
                                                 CY_SYSPM_CHECK_READY */
    CY_SYSPM_BEFORE_TRANSITION  = 0x04U,    /**< Callbacks with this mode are executed after the CY_SYSPM_CHECK_READY
                                                 callbacks execution returns CY_SYSPM_SUCCESS.
                                                 Performs the actions to be done before entering into the
                                                 low power mode. */
    CY_SYSPM_AFTER_TRANSITION   = 0x08U     /**< Performs the actions to be done after exiting the low power mode
                                                 if entered. */
} cy_en_syspm_callback_mode_t;


/** \} group_syspm_data_enumerates */

/**
* \addtogroup group_syspm_macros
* \{
*/
/**
* \defgroup group_syspm_skip_callback_modes Defines to skip the callbacks modes
* \{
* Defines for the SysPm callbacks modes that can be skipped during execution.
* For more information about callbacks modes, refer
* to \ref cy_en_syspm_callback_mode_t.
*/
#define CY_SYSPM_SKIP_CHECK_READY                   (0x01U)   /**< Define to skip check ready mode in the syspm callback */
#define CY_SYSPM_SKIP_CHECK_FAIL                    (0x02U)   /**< Define to skip check fail mode in the syspm callback */
#define CY_SYSPM_SKIP_BEFORE_TRANSITION             (0x04U)   /**< Define to skip before transition mode in the syspm callback */
#define CY_SYSPM_SKIP_AFTER_TRANSITION              (0x08U)   /**< Define to skip after transition mode in the syspm callback */
/** \} group_syspm_skip_callback_modes */
/** \} group_syspm_macros */

/**
* \addtogroup group_syspm_data_structures
* \{
*/

/** The structure contains syspm callback parameters */
typedef struct
{
    void *base;         /**< Base address of a HW instance, matches name of the driver in
                             the API for the base address. Can be undefined if not required. Base address is not
                             required for the SysPm driver as the device has only one set of power modes */
    void *context;      /**< Context for the handler function. This item can be
                             skipped if not required. Can be undefined if not required. */

} cy_stc_syspm_callback_params_t;
/** \cond */
/** The type for syspm callbacks */
typedef cy_en_syspm_status_t (*Cy_SysPmCallback) (cy_stc_syspm_callback_params_t *callbackParams, cy_en_syspm_callback_mode_t mode);
/** \endcond */
/** Structure with syspm callback configuration elements */
typedef struct cy_stc_syspm_callback
{
    Cy_SysPmCallback callback;                         /**< The callback handler function. */
    cy_en_syspm_callback_type_t type;                  /**< The callback type, see \ref cy_en_syspm_callback_type_t. */
    uint32_t skipMode;                                 /**< The mask of modes to be skipped during callback
                                                            execution, see \ref group_syspm_skip_callback_modes. The
                                                            corresponding callback mode won't execute if the
                                                            appropriate define is set. These values can be ORed.
                                                            If all modes are required to be executed this element
                                                            should be equal to zero. Skipping unneeded callback modes speeds up
                                                            power mode transitions by skipping unneeded operations. */

    cy_stc_syspm_callback_params_t *callbackParams;    /**< The address of a cy_stc_syspm_callback_params_t,
                                                            the callback is executed with these parameters. */

    struct cy_stc_syspm_callback *prevItm;             /**< The previous list item. This element should not be
                                                            defined, or defined as NULL. It is for internal
                                                            usage to link this structure to the next registered
                                                            structure. It will be updated during callback
                                                            registration. Do not modify this element at run-time. */

    struct cy_stc_syspm_callback *nextItm;             /**< The next list item. This element should not be
                                                            defined, or defined as NULL. It is for internal usage to
                                                            link this structure to the previous registered structure.
                                                            It will be updated during callback registration. Do not
                                                            modify this element at run-time. */
    uint8_t order;                                     /**< Holds the callback execution order value. Range: 0-255.
                                                            While entering low power mode, callbacks with lower order values
                                                            are executed first. While exiting low power mode,
                                                            the callbacks are executed in the opposite order.
                                                            Callbacks with the same order value are executed in the
                                                            order they are registered in the application. */
} cy_stc_syspm_callback_t;

/** \} group_syspm_data_structures */

/**
* \addtogroup group_syspm_functions
* \{
*/


/**
* \addtogroup group_syspm_functions_power
* \{
*/
cy_en_syspm_status_t Cy_SysPm_CpuEnterSleep(void);
cy_en_syspm_status_t Cy_SysPm_CpuEnterDeepSleep(void);
void Cy_SysPm_CpuEnterSleepNoCallbacks(void);
void Cy_SysPm_CpuEnterDeepSleepNoCallbacks(void);
void                 Cy_SysPm_SleepOnExit(bool enable);

/** \} group_syspm_functions_power */

/**
* \addtogroup group_syspm_function_monitoring
* \{
*/

#if defined(CY_IP_M0S8SRSSHV)
bool Cy_SysPm_SupplySupervisionStatus(cy_en_syspm_supply_entity_select_t supplyEntitySelect);

void Cy_SysPm_BodHVEnable(void);
void Cy_SysPm_BodHVDisable(void);

void Cy_SysPm_OvdEnable(cy_en_syspm_ovd_sel_t ovdSel);
void Cy_SysPm_OvdDisable(cy_en_syspm_ovd_sel_t ovdSel);
#endif /* defined(CY_IP_M0S8SRSSHV) */

/** \} group_syspm_function_monitoring */

/**
* \addtogroup group_syspm_functions_callback
* \{
*/
bool Cy_SysPm_RegisterCallback(cy_stc_syspm_callback_t *handler);
bool Cy_SysPm_UnregisterCallback(cy_stc_syspm_callback_t const *handler);
cy_en_syspm_status_t Cy_SysPm_ExecuteCallback(cy_en_syspm_callback_type_t type, cy_en_syspm_callback_mode_t mode);
cy_stc_syspm_callback_t* Cy_SysPm_GetFailedCallback(cy_en_syspm_callback_type_t type);
/** \} group_syspm_functions_callback */

/** \} group_syspm_functions*/


#ifdef __cplusplus
}
#endif

#endif /* CY_SYSPM_H */
/** \} group_syspm */


/* [] END OF FILE */
