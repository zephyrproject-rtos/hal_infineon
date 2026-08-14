/***************************************************************************//**
* \file cy_syspm.h
* \version 5.180
*
* Provides the function definitions for the power management API.
*
********************************************************************************
* \copyright
(c) 2016-2026, Infineon Technologies AG or an affiliate of
* Infineon Technologies AG.
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
* \defgroup group_syspm_pdcm            PDCM (Power Dependency Control Matrix)
* \defgroup group_syspm_ppu             PPU (Power Policy Unit)
* \} */

/**
* \addtogroup group_syspm
* \{
*
* Use the System Power Management (SysPm) driver to change power modes and
* reduce system power consumption in power sensitive designs.
*
* The functions and other declarations used in this driver are in cy_syspm.h.
* You can include cy_pdl.h to get access to all functions
* and declarations in the PDL.
*
* For multi-CPU devices, this library allows you to individually enter low power
* modes for each CPU.
*
* This document contains the following topics:
*
* * \ref group_syspm_power_modes
* * \ref group_syspm_system_power_modes
*   - \ref group_syspm_switching_into_ulp
*     - \ref group_syspm_ulp_limitations
*   - \ref group_syspm_switching_into_lp
*     - \ref group_syspm_lp_limitations
*   - \ref group_syspm_switching_into_sleep
*   - \ref group_syspm_switching_into_lpactivelpsleep
*   - \ref group_syspm_switching_into_deepsleep
*   - \ref group_syspm_switching_into_deepsleep-ram
*   - \ref group_syspm_switching_into_deepsleep-off
*   - \ref group_syspm_wakingup_from_sleep_deepsleep
*   - \ref group_syspm_switching_into_hibernate
*   - \ref group_syspm_wakingup_from_hibernate
* * \ref group_syspm_system_reg_curr_mode
*   - \ref group_syspm_system_set_min_reg_curr_mode
*   - \ref group_syspm_system_set_normal_reg_curr_mode
* * \ref group_syspm_cb
*   - \ref group_syspm_cb_example
*   - \ref group_syspm_cb_config_consideration
*     - \ref group_syspm_cb_parameters
*     - \ref group_syspm_cb_structures
*     - \ref group_syspm_cb_function_implementation
*     - \ref group_syspm_cb_flow
*     - \ref group_syspm_cb_registering
*     - \ref group_syspm_cb_unregistering
* * \ref group_syspm_definitions
*
* \section group_syspm_section_configuration Configuration Considerations
* \subsection group_syspm_power_modes Power Modes
* This device adopts the <b>ARM Power Control Architecture</b>. It supports the following power modes:
*
* * <b>ACTIVE, SLEEP </b> - standard ARM defined power modes, supported by
*   the ARM CPUs and ISA.
* * <b>LPACTIVE/LPSLEEP</b> - are low power profiles implemented as register
*   configurations within ACTIVE/SLEEP modes.
* * <b>DEEPSLEEP </b> - a lower power mode where high-frequency clocks are
*   disabled.  Most register state is retained and the platform supports saving
*   a configurable amount of SRAM state.
* * <b>DEEPSLEEP-RAM </b> -  a lower mode than DEEPSLEEP that keeps DeepSleep
*   peripherals running, but on wakeup the CPU (and most peripherals) go
*   through a reset.  A configurable amount of system RAM is retained.
* * <b>DEEPSLEEP-OFF </b> -   similar to DEEPSLEEP-RAM but does not retain
*   system RAM.
* * <b>HIBERNATE </b> -   is an even lower power mode than DEEPSLEEP-OFF, but
*   on wakeup the CPU (and almost all peripherals) go through a full reset.
*   DeepSleep peripherals do not operate in HIBERNATE.
* * <b>XRES </b> - occurs when an external reset is applied, either XRES or
*   alternate XRES (AXRES).  It is also considered a power mode with a current
*   target spec.
* * <b>OFF </b> - state simply represents the state of the part with no power
*   applied to it.
*
* * SRSS implements an ARM Power Policy Unit (PPU) that provides the software
* interface to power mode control for VCCACT_PD.The PPU interacts with a
* Power Control State Machine (PSCM) that interfaces with the core SRSS
* to enter/exit DEEPSLEEP*.
* * SRSS implements a Power Dependency Control Matrix (PDCM) that allows hardware
* and software to specify dependencies between power domains.
*
*
* \subsection group_syspm_system_power_modes System Power Modes
* * <b>LP</b> - In this mode, code is executed and all logic and
*   memories are powered. Firmware may disable/reduce clocks for specific
*   peripherals and power down specific analog power domains.
*
* * <b>ULP</b> - This power mode is like LP mode, but
*   with clock restrictions and limited/slower peripherals to achieve lower
*   current consumption. Refer to \ref group_syspm_switching_into_ulp in
*   Configuration considerations.
*
* * <b>LPACTIVE/LPSLEEP</b> - low power profiles implemented as register
*   configurations within ACTIVE/SLEEP modes.Refer to
*   \ref group_syspm_switching_into_lpactivelpsleep in Configuration considerations.
*
* * <b>DEEPSLEEP</b> - Is a lower power mode where high-frequency clocks are
*   disabled. Refer to \ref group_syspm_switching_into_deepsleep in
*   Configuration considerations. Deep-sleep-capable peripherals are available.
*   A normal wakeup from Deep Sleep returns to either system LP or ULP mode,
*   depending on the previous state and programmed behavior for the configured
*   wakeup interrupt. Likewise, a debug wakes up from system Deep Sleep and
*   woken CPU returns to CPU Sleep. Refer
*   to \ref group_syspm_wakingup_from_sleep_deepsleep in Configuration
*   considerations.
*
* * <b>DEEPSLEEP-RAM</b> - a lower mode than DEEPSLEEP that keeps DeepSleep
*   peripherals running, but on wakeup the CPU (and most peripherals) go through
*   a reset. A configurable amount of system RAM is retained.Refer to
*   \ref group_syspm_switching_into_deepsleep-ram in Configuration considerations.
*   Refer to \ref group_syspm_wakingup_from_sleep_deepsleep in Configuration
*   considerations.
*
* * <b>DEEPSLEEP-OFF</b> -  similar to DEEPSLEEP-RAM but does not retain system RAM.
*   Refer to \ref group_syspm_switching_into_deepsleep-off in Configuration considerations.
*   Refer to \ref group_syspm_wakingup_from_sleep_deepsleep in Configuration
*   considerations.
*
* * <b>Hibernate</b> - Is the lowest power mode that is entered from
*   firmware. Refer to \ref group_syspm_switching_into_hibernate in
*   Configuration considerations. On wakeup the CPU(s) and all peripherals
*   go through a full reset. The I/O's state is frozen so that the
*   output driver state is held in system Hibernate. Note that in this mode,
*   the CPU(s) and all peripherals lose their states, so the system and firmware
*   reboot on a wakeup event. Backup memory (if present) can be used to store
*   limited system state for use on the next reboot. Refer to
*   \ref group_syspm_wakingup_from_hibernate in Configuration considerations.
*
* \warning * Above is list of all the System Power modes in general, a device
* support subset of the above System Power modes.Please refer to TRM for more information.
*
* \subsubsection group_syspm_switching_into_lp Switching the System into Low Power
* To set system LP mode you need to set LP voltage for the active core
* regulator:
* * If active core regulator is the LDO, call:
*   \code{.c}
*   Cy_SysPm_LdoSetVoltage(CY_SYSPM_LDO_VOLTAGE_LP);
*   \endcode
* * If active core regulator is the Buck, call:
*   \code{.c}
*   Cy_SysPm_BuckSetVoltage1(CY_SYSPM_BUCK_OUT1_VOLTAGE_LP)
*   \endcode
*
* After switching into system LP mode, the operating frequency and current
* consumption may now be increased up to \ref group_syspm_lp_limitations.
* The wait states for flash may be changed to increase device performance by
* calling SysLib function Cy_SysLib_SetWaitStates(true, hfClkFreqMz), where
* hfClkFreqMz is the frequency of HfClk0 in MHz.
*
* \subsubsection group_syspm_lp_limitations LP Limitations
* When the system is in LP mode, the core regulator voltage is set to
* <b>1.1 V (nominal)</b> and the following limitations must be met:
*
*   - The maximum operating frequency for all Clk_HF paths must not exceed
*     <b>150 MHz*</b>, and peripheral and slow clock must
*     not exceed <b>100 MHz *</b>
*
*   - The total current consumption must be less than or equal to
*     <b>250 mA *</b>
*
* \warning * - Numbers shown are approximate and real limit values may be
* different because they are device specific. You should refer to the device
* datasheet for exact values of maximum frequency and current in system LP mode.
*
* \subsubsection group_syspm_switching_into_ulp Switching the System into Ultra Low Power
* Before switching into system ULP mode, ensure that the device meets
* \ref group_syspm_ulp_limitations. Decrease the clock frequencies,
* and slow or disable peripherals. Also ensure that appropriate wait state
* values are set for the flash. Flash wait states can be set by calling
* SysLib function Cy_SysLib_SetWaitStates(true, hfClkFreqMz), where hfClkFreqMz
* is the frequency of HfClk0 in MHz.
*
* After the \ref group_syspm_ulp_limitations are met and appropriate wait
* states are set, you must set ULP voltage for the active core regulator:
* * If active core regulator is the LDO Core Voltage Regulator, call
* Cy_SysPm_LdoSetVoltage(CY_SYSPM_LDO_VOLTAGE_ULP)
* * If active core regulator is the Buck Core Voltage Regulator, then call
* Cy_SysPm_BuckSetVoltage1(CY_SYSPM_BUCK_OUT1_VOLTAGE_ULP)
*
* \subsubsection group_syspm_ulp_limitations ULP Limitations
* When the system is in ULP mode the core regulator voltage is set to <b>0.9 V
* (nominal)</b> and the following limitations must be meet:
*
*   - The maximum operating frequency for all Clk_HF paths must not exceed
*     <b>50 MHz *</b>, whereas the peripheral and slow clock must not exceed
*     <b>25 MHz *</b>.
*
*   - The total current consumption must be less than or equal
*     to <b>20 mA*</b>
*
*   - the flash write operations are prohibited. The flash works in the
*     Read-only operation. If Write operations are required, you must switch to
*     the system LP mode.
*
* \warning * - Numbers shown are approximate and real limit values may be
* different because they are device specific. You should refer to the device
* datasheet for exact values of maximum frequency and current in system
* ULP mode.
*
* \subsubsection group_syspm_switching_into_lpactivelpsleep Switching the System into LPACTIVE/LPSLEEP
* Call Cy_SysPm_SystemLpActiveEnter() to enter LPACTIVE/LPSLEEP mode and
* Cy_SysPm_SystemLpActiveExit() to exit.
*
* \subsubsection group_syspm_switching_into_sleep Switching CPU into Sleep
* For multi-CPU devices, the Cy_SysPm_CpuEnterSleep() switches only the CPU
* that calls the function into the CPU Sleep power mode.
*
* All pending interrupts must be cleared before the CPU is put into a
* Sleep mode, even if they are masked.
*
* The CPU event register can be set in the past, for example, as a result of
* internal system calls. So an old event can cause the CPU to not enter
* Sleep mode upon WFE(). Therefore usually the WFE() is used in an idle loop or
* polling loop as it might or might not cause entering of CPU Sleep mode. If
* the idle loop or polling loop is not used, then it is recommended to use
* WFI() instruction.
*
* \subsubsection group_syspm_switching_into_deepsleep Switching the System or CPU into Deep Sleep
* For multi-CPU devices, the Cy_SysPm_CpuEnterDeepSleep() function switches
* only the CPU that calls the function into the CPU Deep Sleep power mode.
* To set the whole system into Deep Sleep power mode, ensure that all CPUs call
* the Cy_SysPm_CpuEnterDeepSleep() function.
*
* \warning * For 20829/PSC3 devices we need to call Cy_SysPm_SetDeepSleepMode() function with
* appropriate type of deepsleep as parameter before calling Cy_SysPm_CpuEnterDeepSleep()
* function.
*
* \subsubsection group_syspm_switching_into_deepsleep-ram Switching the System or CPU into Deep Sleep-RAM
* For multi-CPU devices, the Cy_SysPm_CpuEnterDeepSleep() function switches
* only the CPU that calls the function into the CPU DEEPSLEEP-RAM power mode.
* To set the whole system into Deep Sleep power mode, ensure that all CPUs call
* the Cy_SysPm_CpuEnterDeepSleep() function.
*
* \warning * For 20829/PSC3 devices we need to call Cy_SysPm_SetDeepSleepMode() function with
* appropriate type of deepsleep as parameter before calling Cy_SysPm_CpuEnterDeepSleep()
* function.
*
* \subsubsection group_syspm_switching_into_deepsleep-off Switching the System or CPU into Deep Sleep-OFF
* For multi-CPU devices, the Cy_SysPm_CpuEnterDeepSleep() function switches
* only the CPU that calls the function into the CPU DEEPSLEEP-OFF power mode.
* To set the whole system into Deep Sleep power mode, ensure that all CPUs call
* the Cy_SysPm_CpuEnterDeepSleep() function.
*
* Note:- For 20829/PSC3 devices we need to call Cy_SysPm_SetDeepSleepMode() function with
* appropriate type of deepsleep as parameter before calling Cy_SysPm_CpuEnterDeepSleep()
* function.
*
* There are situations when the system does not switch into the Deep Sleep
* power mode immediately after the last CPU calls Cy_SysPm_CpuEnterDeepSleep().
* The system will switch into Deep Sleep mode automatically a short time later,
* after the low power circuits are ready to switch into Deep Sleep. Refer to
* the Cy_SysPm_CpuEnterDeepSleep() description for more detail.
*
* All pending interrupts must be cleared before the system is put into a
* Deep Sleep mode, even if they are masked.
*
* The CPU event register can be set in the past, for example, as a result of
* internal system calls. So an old event can cause the CPU to not enter Deep
* Sleep mode upon WFE(). Therefore usually the WFE() is used in an idle loop or
* polling loop as it might or might not cause entering of CPU Deep Sleep mode.
* If the idle loop or polling loop is not used, then it is recommended to use
* WFI() instruction.
*
* For single-CPU devices, SysPm functions that return the status of the
* unsupported CPU always return CY_SYSPM_STATUS_<CPU>_DEEPSLEEP.
*
* \subsubsection group_syspm_wakingup_from_sleep_deepsleep Waking Up from Sleep or Deep Sleep
* For Arm-based devices, an interrupt is required for the CPU to wake up.
* For multi-CPU devices, one CPU can wake up the other CPU by sending the
* event instruction. Use the Cy_SysPm_CpuSendWakeupEvent() function.
*
* \subsubsection group_syspm_switching_into_hibernate Switching System to Hibernate
* If you call Cy_SysPm_SystemEnterHibernate() from either CPU, the system will
* be switched into the Hibernate power mode directly, because there is no
* handshake between CPUs.
*
* \subsubsection group_syspm_wakingup_from_hibernate Waking Up from Hibernate
*
* The system can wake up from Hibernate mode by configuring the following wakeup
* sources:
* - Wakeup pin
* - LP Comparator
* - RTC alarm
* - WDT interrupt
*
* Wakeup is supported from device specific pin(s) with programmable polarity.
* Additionally, unregulated peripherals can wake the system under some
* conditions. For example, a low power comparator can wake the system by
* comparing two external voltages, but does not support comparison to an
* internally-generated voltage. The backup power domain remains functional, and
* if present it can schedule an alarm to wake the system from Hibernate using
* the RTC. Alternatively, the Watchdog Timer (WDT) can be configured to wake-up
* the system by WDT interrupt. Refer to \ref Cy_SysPm_SetHibernateWakeupSource()
* for more detail.
*
* \subsection group_syspm_system_reg_curr_mode System Regulator Current Mode
* In addition to system ULP and LP modes, the five different resource
* power settings can be configured to reduce current consumption:
* -# <b>Linear regulator low power mode</b>. Can be used only if core current
*    is below the LDO regulator LP threshold.
* -# <b>POR/BOD circuit low power mode</b>. Requires compatible power supply
*    stability due to stability increase response time.
* -# <b>Bandgap reference circuits low power mode</b> (turns on Deep Sleep
*    Bandgap). Requires design to accept reduced Vref accuracy. Active ref can
*    be turned off after this feature is enabled.
* -# <b>Reference buffer circuit low power mode</b>. Requires design to accept
*    reduced Vref accuracy.
* -# <b>Current reference circuit low power mode</b>. Require design to accept
*    reduced Iref accuracy.
*
* These five sub features can modify both system LP or ULP modes as they are
* independent from LP/ULP settings.
* When all five sub features are set to their low power modes, the system
* operates in regulator minimum current mode. In regulator minimum current mode,
* the system current consumption is limited to a device-specific value. Refer to
* the device datasheet for the exact current consumption value in regulator
* minimum current mode.
*
* When all five sub features are set to their normal mode, the system operates
* in regulator normal current mode. When regulator normal current mode is set,
* the system may operate at device maximum current.
*
* \subsection group_syspm_system_set_min_reg_curr_mode Setting Minimum System Regulator Current Mode
*
* Before setting the regulator minimum current mode ensure that current limits
* are be met. After current limits are met, call the
* Cy_SysPm_SystemSetMinRegulatorCurrent() function.
*
* \subsection group_syspm_system_set_normal_reg_curr_mode Setting Normal System Regulator Current Mode
*
* To set regulator normal current mode, call the
* Cy_SysPm_SystemSetNormalRegulatorCurrent() function. After the function call,
* the current limits can be increased to a maximum current, depending on what
* system power mode is set: LP or ULP.
*
* \subsection group_syspm_cb SysPm Callbacks
* The SysPm driver handles low power callbacks declared in the application.
*
* If there are no callbacks registered, the device executes the power mode
* transition. However, frequently your application firmware must make
* modifications for low power mode. For example, you may need to disable a
* peripheral, or ensure that a message is not being transmitted or received.
*
* To enable this, the SysPm driver implements a callback mechanism. When a lower
* power mode transition is about to take place (either entering or exiting
* \ref group_syspm_system_power_modes), the registered callbacks for that
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
* \subsection group_syspm_cb_example SysPm Callbacks Example
*
* The following code snippets demonstrate how use the SysPm callbacks mechanism.
* We will build the prototype for an application that registers
* three callback functions:
*    -# myDeepSleep1 - Handles CPU Deep Sleep.
*    -# myDeepSleep2 - Handles CPU Deep Sleep and is associated with peripheral
*       HW1_address (see <a href="..\..\pdl_user_guide.pdf">PDL Design</a>
*       section to learn about the base hardware address).
*    -# myDeepSleep3 - Handles entering and exiting system Deep Sleep and is
*       associated with peripheral HW2_address.
*
* We set things up so that the myDeepSleep1 and myDeepSleep2 callbacks do
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
* \snippet syspm/snippet/main.c snippet_Cy_SysPm_Callback_Func_Declaration
*
* Now we setup the \ref cy_stc_syspm_callback_params_t structures that we will
* pass to the callback functions. Note that for the myDeepSleep2 and
* myDeepSleep3 callbacks we also pass pointers to the peripherals related to
* that callback (see <a href="..\..\pdl_user_guide.pdf">PDL Design</a> section
* to learn about base hardware addresses).
* The configuration considerations related to this structure are described
* in \ref group_syspm_cb_parameters in \ref group_syspm_cb_config_consideration.
*
* \snippet syspm/snippet/main.c snippet_Cy_SysPm_Callback_Params_Declaration
*
* Now we setup the actual callback configuration structures. Each of these
* contains, among the other fields, the address of the
* \ref cy_stc_syspm_callback_params_t we just set up. We will use the callback
* configuration structures later in the code to register the callbacks in the
* SysPm driver. Again, we set things up so that the myDeepSleep1 and
* myDeepSleep2 callbacks do nothing while entering the low power mode
* (skip on CY_SYSPM_SKIP_BEFORE_TRANSITION) - see
* \ref group_syspm_cb_function_implementation in
* \ref group_syspm_cb_config_consideration.
*
* \snippet syspm/snippet/main.c snippet_Cy_SysPm_Callback_Structure_Declaration
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
* \snippet syspm/snippet/main.c snippet_Cy_SysPm_Callback_Func_Implementation
*
* Finally, we register the callbacks so that the SysPm driver knows about them.
* The order in which the callbacks will be called depends upon the order in
* which the callbacks are registered. If there are no callbacks registered,
* the device just executes the power mode transition.
*
* Callbacks that reconfigure global resources, such as clock frequencies, should
* be registered last. They then modify global resources as the final step before
* entering the low power mode, and restore those resources first, as the system
* returns from low power mode.
*
* \snippet syspm/snippet/main.c snippet_Cy_SysPm_RegisterCallback
*
* We are done configuring three callbacks. Now the SysPm driver will execute the
* callbacks appropriately whenever there is a call to a power mode transition
* function: \ref Cy_SysPm_CpuEnterSleep(), \ref Cy_SysPm_CpuEnterDeepSleep(),
* \ref Cy_SysPm_SystemEnterUlp(), \ref Cy_SysPm_SystemEnterLp(), and
* \ref Cy_SysPm_SystemEnterHibernate().
* \note On a wakeup from hibernate the device goes through a reset, so the
* callbacks with CY_SYSPM_AFTER_TRANSITION are not executed. Refer to
* \ref Cy_SysPm_SystemEnterHibernate() for more detail.
*
* Refer to \ref group_syspm_cb_unregistering in
* \ref group_syspm_cb_config_consideration to learn what to do if you need to
* remove the callback from the linked list. You might want to unregister the
* callback for debug purposes.
*
* Refer to \ref group_syspm_cb_flow in \ref group_syspm_cb_config_consideration
* to learn about how the SysPm processes the callbacks.
*
* \subsection group_syspm_cb_config_consideration Callback Configuration Considerations
*
* \subsubsection group_syspm_cb_parameters Callback Function Parameters
*
* The <b>callbackParams</b> parameter of the callback function is a
* \ref cy_stc_syspm_callback_params_t structure. The second parameter
* (<b>mode</b>) is for internal use. In the example code we used a
* dummy value CY_SYSPM_CHECK_READY to eliminate compilation errors associated
* with the enumeration. The driver sets the <b>mode</b> field to the correct
* value when calling the callback functions (the mode is referred to as step in
* the \ref group_syspm_cb_function_implementation). The callback function reads
* the value and executes code based on the mode set by the SysPm driver.
* The <b>base</b> and <b>context</b> fields are optional and can be NULL.
* Some drivers require a base hardware address and context to store information
* about the mode transition. If your callback routine requires access to the
* driver registers or context, provide those values
* (see <a href="..\..\pdl_user_guide.pdf">PDL Design</a> section
* to learn about Base Hardware Address). Be aware of MISRA warnings if these
* parameters are NULL.
*
* \subsubsection group_syspm_cb_structures Callback Function Structure
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
* \subsubsection group_syspm_cb_function_implementation Callback Function Implementation
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
* \subsubsection group_syspm_cb_flow Callbacks Execution Flow
*
* This section explains what happens during a power transition, when callbacks
* are implemented and set up correctly. The following discussion assumes:
* * All required callback functions are defined and implemented
* * All cy_stc_syspm_callback_t structures are filled with required values
* * All callbacks are successfully registered
*
* User calls one of the power mode transition functions: \ref Cy_SysPm_CpuEnterSleep(),
* \ref Cy_SysPm_CpuEnterDeepSleep(), \ref Cy_SysPm_SystemEnterUlp(),
* \ref Cy_SysPm_SystemEnterLp(), or \ref Cy_SysPm_SystemEnterHibernate().
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
* execution of the code for that mode inside each user callback. The final
* execution of callbacks depends on the low power mode in which callbacks were
* called:
* * For CPU Sleep or Deep Sleep power modes, the CY_SYSPM_AFTER_TRANSITION mode
*   is called after the CPU wakes from Sleep or Deep Sleep.
* * For system Hibernate, the CY_SYSPM_AFTER_TRANSITION mode is not executed
*   because the device reboots after the wakeup from the Hibernate.
* * For system LP and ULP modes, after the CY_SYSPM_AFTER_TRANSITION mode was
*   called the system remains in the new power mode: LP or ULP.
*
* A callback can return CY_SYSPM_FAIL only while executing the
* CY_SYSPM_CHECK_READY mode. If that happens, then the remaining callbacks are
* not executed. Any callbacks that have already executed are called again, in
* reverse order, with CY_SYSPM_CHECK_FAIL. This allows the system to return to
* the previous state. If a callback returns a fail then any of the functions
* (\ref Cy_SysPm_CpuEnterSleep(), \ref Cy_SysPm_CpuEnterDeepSleep(),
* \ref Cy_SysPm_SystemEnterUlp(), \ref Cy_SysPm_SystemEnterLp(), or
* \ref Cy_SysPm_SystemEnterHibernate()) that attempt to switch the device into
* a low power mode will also return CY_SYSPM_FAIL.
*
* Callbacks that reconfigure global resources, such as clock frequencies,
* should be registered last. They then modify global resources as the final
* step before entering the low power mode, and restore those resources first,
* as the system returns from low power mode.
*
* \subsubsection group_syspm_cb_registering Callback Registering
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
* \snippet syspm/snippet/main.c snippet_Cy_SysPm_RegisterCallback
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
* \subsubsection group_syspm_cb_unregistering Callback Unregistering
*
* Unregistering the callback might be useful when you need to dynamically manage
* the callbacks.
*
* \snippet syspm/snippet/main.c snippet_Cy_SysPm_UnregisterCallback
* The callback structures after myDeepSleep2 callback is unregistered:
* \image html syspm_unregistration.png
*
* \section group_syspm_section_secure_aware Secure Aware SYSPM
* Some SYSPM APIs are marked as Secure Aware. This means that if the resource in SYSPM
* is marked as a secure region in the Peripheral Protection Controller (PPC) and these
* APIs are called from a non-secure CPU state, the PDL will submit a request to the
* Secure Request Framework (SRF) middleware to transition to a secure CPU state to
* perform the operation. From the application's perspective, the API will behave
* the same whether it is called from a secure or non-secure CPU state albeit slower.
*
* This functionality is automatically enabled on devices with ARM TrustZone processors.
* To disable, set the DEFINE+=CY_PDL_ENABLE_SECURE_AWARE_SYSPM=0 in the application
* Makefile.
*
* For more information on Secure Aware PDL behavior, see \ref group_pdl_srf_general.
*
* \section group_syspm_definitions Definitions
*
* <table class="doxtable">
*   <tr>
*     <th>Term</th>
*     <th>Definition</th>
*   </tr>
*
*   <tr>
*     <td>LDO</td>
*     <td>Low dropout linear regulator. The functions that manage this
*         block are grouped as \ref group_syspm_functions_ldo under
*         \ref group_syspm_functions_core_regulators</td>
*   </tr>
*
*   <tr>
*     <td>SIMO Buck</td>
*     <td>Single inductor multiple Output Buck regulator, referred as
*         "Buck regulator" throughout the documentation. The functions that
*         manage this block are grouped as \ref group_syspm_functions_buck under
*         \ref group_syspm_functions_core_regulators</td>
*   </tr>
*
*   <tr>
*     <td>SISO Buck</td>
*     <td>Single inductor single output Buck regulator, referred as
*         "Buck regulator" throughout the documentation. The functions that
*         manage this block are grouped as \ref group_syspm_functions_buck under
*         \ref group_syspm_functions_core_regulators</td>
*   </tr>

*   <tr>
*     <td>PMIC</td>
*     <td>Power management integrated circuit. The functions that manage this
*         block are grouped as \ref group_syspm_functions_pmic</td>
*   </tr>
*
*   <tr>
*     <td>LP</td>
*     <td>System low power mode. See the \ref group_syspm_switching_into_lp
*         section for details.</td>
*   </tr>
*
*   <tr>
*     <td>ULP</td>
*     <td>System ultra low power mode. See the
*         \ref group_syspm_switching_into_ulp section for details.</td>
*   </tr>
* </table>
*
* \section group_syspm_section_more_information More Information
* For more information on the SysPm driver,
* refer to the technical reference manual (TRM).
*
* \defgroup group_syspm_macros Macros
* \defgroup group_syspm_functions Functions
* \{
    \defgroup group_syspm_functions_general        General
*   \defgroup group_syspm_functions_power          Power Modes
*   \defgroup group_syspm_functions_power_status   Power Status
*   \defgroup group_syspm_functions_iofreeze       I/Os Freeze
*   \defgroup group_syspm_functions_core_regulators    Core Voltage Regulation
*   \{
*     \defgroup group_syspm_functions_ldo      LDO
*     \defgroup group_syspm_functions_buck     Buck
*   \}
*   \defgroup group_syspm_functions_pmic       PMIC
*   \defgroup group_syspm_functions_backup     Backup Domain
*   \defgroup group_syspm_functions_callback   Low Power Callbacks
* \}
* \defgroup group_syspm_data_structures Data Structures
* \defgroup group_syspm_data_enumerates Enumerated Types
*/

#if !defined (CY_SYSPM_H)
#define CY_SYSPM_H

#include "cy_device.h"

#if defined (CY_IP_MXS28SRSS) || defined (CY_IP_MXS40SRSS) || defined (CY_IP_MXS40SSRSS) || defined (CY_IP_MXS22SRSS)

#include <stdbool.h>
#include <stddef.h>

#include "cy_device_headers.h"
#include "cy_syslib.h"

#if ((CY_CPU_CORTEX_M4) && (defined (CY_DEVICE_SECURE)))
    #include "cy_pra.h"
#endif /* #if ((CY_CPU_CORTEX_M4) && (defined (CY_DEVICE_SECURE))) */

#include "cy_pdl_srf.h"
#include "cy_pdl_srf_common.h"

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
#define CY_SYSPM_DRV_VERSION_MAJOR       5

/** Driver minor version */
#define CY_SYSPM_DRV_VERSION_MINOR       190

/** SysPm driver identifier */
#define CY_SYSPM_ID                      (CY_PDL_DRV_ID(CY_PDL_RSLT_MODULE_SYSPM))


/*******************************************************************************
*       Internal Defines
*******************************************************************************/

/** \cond INTERNAL */

/* The internal define of the tries number in the
* CoreBuck and LDO status functions
*/
#define CY_SYSPM_CBUCK_BUSY_RETRY_COUNT         (100000U)
#define CY_SYSPM_CBUCK_BUSY_RETRY_DELAY_US      (1U)

/* Macro to validate parameters in Cy_SysPm_SetHibernateWakeupSource() and for Cy_SysPm_ClearHibernateWakeupSource() function */
#define CY_SYSPM_IS_WAKE_UP_SOURCE_VALID(wakeupSource)   (0UL == ((wakeupSource) & \
                                                          ((uint32_t) ~(CY_SYSPM_HIB_WAKEUP_SOURCE_MASK))))

/* Second part of condition handles the specific case for PSC3M4 (SSRSS v1.4);
 * the third handles PSC3S5 (SSRSS v1.3 without a VBCK backup domain). */
#if (defined (CY_IP_MXS40SRSS) || (defined (CY_IP_MXS40SSRSS) && (SRSS_BACKUP_VBCK_PRESENT == 1UL))) || \
     (defined (CY_IP_MXS40SSRSS_VERSION_MINOR) && (CY_IP_MXS40SSRSS_VERSION_MINOR == 4)) || \
     (defined (CY_IP_MXS40SSRSS_VERSION_MINOR) && (CY_IP_MXS40SSRSS_VERSION_MINOR == 3))

/* Macro to validate parameters in Cy_SysPm_PmicDisable() function */
#define CY_SYSPM_IS_POLARITY_VALID(polarity)            (((polarity) == CY_SYSPM_PMIC_POLARITY_LOW) || \
                                                         ((polarity) == CY_SYSPM_PMIC_POLARITY_HIGH))

/* Second part of condition handles the specific case for PSC3M4 (SSRSS v1.4);
 * the third handles PSC3S5 (SSRSS v1.3 without a VBCK backup domain). */
#if (defined (CY_IP_MXS40SSRSS) && (SRSS_BACKUP_VBCK_PRESENT == 1UL)) || ((defined (CY_IP_MXS40SSRSS)) && \
     defined (CY_IP_MXS40SSRSS_VERSION_MINOR) && (CY_IP_MXS40SSRSS_VERSION_MINOR == 4)) || \
     ((defined (CY_IP_MXS40SSRSS)) && defined (CY_IP_MXS40SSRSS_VERSION_MINOR) && (CY_IP_MXS40SSRSS_VERSION_MINOR == 3))
/* Macro to validate parameters in Cy_SysPm_LdoSetVoltage() function */
#define CY_SYSPM_IS_LDO_VOLTAGE_VALID(voltage)          (((voltage) == CY_SYSPM_LDO_VOLTAGE_0_9V) || \
                                                         ((voltage) == CY_SYSPM_LDO_VOLTAGE_1_0V) || \
                                                         ((voltage) == CY_SYSPM_LDO_VOLTAGE_1_1V) || \
                                                         ((voltage) == CY_SYSPM_LDO_VOLTAGE_1_2V))

#else
/* Macro to validate parameters in Cy_SysPm_BuckSetVoltage1() function */
#define CY_SYSPM_IS_BUCK_VOLTAGE1_VALID(voltage)        (((voltage) == CY_SYSPM_BUCK_OUT1_VOLTAGE_0_9V) || \
                                                         ((voltage) == CY_SYSPM_BUCK_OUT1_VOLTAGE_1_1V))

/* Macro to validate parameters in Cy_SysPm_BuckSetVoltage2() function */
#define CY_SYSPM_IS_BUCK_VOLTAGE2_VALID(voltage)        (((voltage) == CY_SYSPM_BUCK_OUT2_VOLTAGE_1_15V) || \
                                                         ((voltage) == CY_SYSPM_BUCK_OUT2_VOLTAGE_1_2V)  || \
                                                         ((voltage) == CY_SYSPM_BUCK_OUT2_VOLTAGE_1_25V) || \
                                                         ((voltage) == CY_SYSPM_BUCK_OUT2_VOLTAGE_1_3V)  || \
                                                         ((voltage) == CY_SYSPM_BUCK_OUT2_VOLTAGE_1_35V) || \
                                                         ((voltage) == CY_SYSPM_BUCK_OUT2_VOLTAGE_1_4V)  || \
                                                         ((voltage) == CY_SYSPM_BUCK_OUT2_VOLTAGE_1_45V) || \
                                                         ((voltage) == CY_SYSPM_BUCK_OUT2_VOLTAGE_1_5V))

/* Macro to validate parameters in Cy_SysPm_BuckIsOutputEnabled() function */
#define CY_SYSPM_IS_BUCK_OUTPUT_VALID(output)           (((output) == CY_SYSPM_BUCK_VBUCK_1) || \
                                                         ((output) == CY_SYSPM_BUCK_VRF))

/* Macro to validate parameters in Cy_SysPm_LdoSetVoltage() function */
#define CY_SYSPM_IS_LDO_VOLTAGE_VALID(voltage)          (((voltage) == CY_SYSPM_LDO_VOLTAGE_0_9V) || \
                                                         ((voltage) == CY_SYSPM_LDO_VOLTAGE_1_1V))

#endif

#endif

/* Macro to validate parameters in Cy_SysPm_ExecuteCallback() function */


#if defined (CY_IP_MXS40SSRSS) || defined (CY_IP_MXS22SRSS) || defined (CY_DOXYGEN)

/* Macro to validate deep sleep modes in Cy_SysPm_CpuEnterDeepSleep() function */
#define CY_SYSPM_IS_DEEPSLEEP_MODE_VALID(mode)             (((mode) == CY_SYSPM_DEEPSLEEP)     || \
                                                            ((mode) == CY_SYSPM_DEEPSLEEP_RAM) || \
                                                            ((mode) == CY_SYSPM_DEEPSLEEP_OFF))
/* Macro to validate parameters in Cy_SysPm_SetupDeepSleepRAM() function */
#define CY_SYSPM_IS_DSRAM_CHECK_VALID(dsramCheck)          (((dsramCheck) == CY_SYSPM_PRE_DSRAM) || \
                                                            ((dsramCheck) == CY_SYSPM_POST_DSRAM))

/* Macro to validate core buck mode in Cy_SysPm_CoreBuckConfig() function */
#define CY_SYSPM_IS_CORE_BUCK_MODE_VALID(mode)           (((mode) == CY_SYSPM_CORE_BUCK_MODE_LP)     || \
                                                          ((mode) == CY_SYSPM_CORE_BUCK_MODE_HP))

/* Macro to validate SOCMEM SRAM Power modes in Cy_SysPm_SetSOCMemPartitionPwrMode() function */
#define CY_SYSPM_IS_SOCMEM_PWR_MODE_VALID(mode)             (((mode) == CY_SYSPM_SOCMEM_SRAM_ACTIVE_MODE_ON)     || \
                                                            ((mode) == CY_SYSPM_SOCMEM_SRAM_ACTIVE_MODE_OFF) || \
                                                            ((mode) == CY_SYSPM_SOCMEM_SRAM_DS_MODE_RET_ON) || \
                                                            ((mode) == CY_SYSPM_SOCMEM_SRAM_DS_MODE_RET_OFF))

#endif

#if defined (CY_IP_MXS40SSRSS) || defined (CY_DOXYGEN)
#define CY_SYSPM_IS_CALLBACK_TYPE_VALID(type)           (((type) == CY_SYSPM_SLEEP)         || \
                                                         ((type) == CY_SYSPM_LPACTIVE_ENTER)|| \
                                                         ((type) == CY_SYSPM_LPACTIVE_EXIT) || \
                                                         ((type) == CY_SYSPM_DEEPSLEEP)     || \
                                                         ((type) == CY_SYSPM_DEEPSLEEP_RAM) || \
                                                         ((type) == CY_SYSPM_DEEPSLEEP_OFF) || \
                                                         ((type) == CY_SYSPM_HIBERNATE))


/* Macro to validate parameters in Cy_SysPm_CoreBuckSetVoltage() & Cy_SysPm_CoreBuckConfig functions */
#define CY_SYSPM_IS_CORE_BUCK_VOLTAGE_VALID(voltage)    (((voltage) == CY_SYSPM_CORE_BUCK_VOLTAGE_0_76V) || \
                                                         ((voltage) == CY_SYSPM_CORE_BUCK_VOLTAGE_0_78V)  || \
                                                         ((voltage) == CY_SYSPM_CORE_BUCK_VOLTAGE_0_80V) || \
                                                         ((voltage) == CY_SYSPM_CORE_BUCK_VOLTAGE_0_82V)  || \
                                                         ((voltage) == CY_SYSPM_CORE_BUCK_VOLTAGE_0_84V) || \
                                                         ((voltage) == CY_SYSPM_CORE_BUCK_VOLTAGE_0_86V)  || \
                                                         ((voltage) == CY_SYSPM_CORE_BUCK_VOLTAGE_0_88V) || \
                                                         ((voltage) == CY_SYSPM_CORE_BUCK_VOLTAGE_0_90V)  || \
                                                         ((voltage) == CY_SYSPM_CORE_BUCK_VOLTAGE_0_92V) || \
                                                         ((voltage) == CY_SYSPM_CORE_BUCK_VOLTAGE_0_94V)  || \
                                                         ((voltage) == CY_SYSPM_CORE_BUCK_VOLTAGE_0_96V) || \
                                                         ((voltage) == CY_SYSPM_CORE_BUCK_VOLTAGE_0_98V)  || \
                                                         ((voltage) == CY_SYSPM_CORE_BUCK_VOLTAGE_1_00V) || \
                                                         ((voltage) == CY_SYSPM_CORE_BUCK_VOLTAGE_1_02V) || \
                                                         ((voltage) == CY_SYSPM_CORE_BUCK_VOLTAGE_1_04V) || \
                                                         ((voltage) == CY_SYSPM_CORE_BUCK_VOLTAGE_1_06V) || \
                                                         ((voltage) == CY_SYSPM_CORE_BUCK_VOLTAGE_1_08V) || \
                                                         ((voltage) == CY_SYSPM_CORE_BUCK_VOLTAGE_1_10V) || \
                                                         ((voltage) == CY_SYSPM_CORE_BUCK_VOLTAGE_1_12V) || \
                                                         ((voltage) == CY_SYSPM_CORE_BUCK_VOLTAGE_1_14V) || \
                                                         ((voltage) == CY_SYSPM_CORE_BUCK_VOLTAGE_1_16V) || \
                                                         ((voltage) == CY_SYSPM_CORE_BUCK_VOLTAGE_1_18V) || \
                                                         ((voltage) == CY_SYSPM_CORE_BUCK_VOLTAGE_1_20V) || \
                                                         ((voltage) == CY_SYSPM_CORE_BUCK_VOLTAGE_1_22V) || \
                                                         ((voltage) == CY_SYSPM_CORE_BUCK_VOLTAGE_1_24V) || \
                                                         ((voltage) == CY_SYSPM_CORE_BUCK_VOLTAGE_1_26V) || \
                                                         ((voltage) == CY_SYSPM_CORE_BUCK_VOLTAGE_1_28V) || \
                                                         ((voltage) == CY_SYSPM_CORE_BUCK_VOLTAGE_1_30V) || \
                                                         ((voltage) == CY_SYSPM_CORE_BUCK_VOLTAGE_1_32V) || \
                                                         ((voltage) == CY_SYSPM_CORE_BUCK_VOLTAGE_1_34V) || \
                                                         ((voltage) == CY_SYSPM_CORE_BUCK_VOLTAGE_1_36V) || \
                                                         ((voltage) == CY_SYSPM_CORE_BUCK_VOLTAGE_1_38V))

/* Macro to Enable/Disable Pause on Core Buck Regulator */
#define CY_SYSPM_CORE_BUCK_PAUSE_ENABLE(enable)          CY_REG32_CLR_SET(SRSS_PWR_CBUCK_CTL2, SRSS_PWR_CBUCK_CTL2_CBUCK_PAUSE, \
                                                          enable)

/* Macro to Enable/Disable Override on Core Buck Regulator */
#define CY_SYSPM_CORE_BUCK_OVERRIDE_ENABLE(enable)          CY_REG32_CLR_SET(SRSS_PWR_CBUCK_CTL2, SRSS_PWR_CBUCK_CTL2_CBUCK_OVERRIDE, \
                                                          enable)

/* Macro to Enable/Disable Copy Settings of Core Buck Regulator*/
#define CY_SYSPM_CORE_BUCK_COPY_SETTINGS_ENABLE(enable)          CY_REG32_CLR_SET(SRSS_PWR_CBUCK_CTL2, SRSS_PWR_CBUCK_CTL2_CBUCK_COPY_SETTINGS, \
                                                          enable)


/* Macro to validate core buck Inrush Limit in Cy_SysPm_CoreBuckConfig() function */
#define CY_SYSPM_IS_CORE_BUCK_INRUSH_LIMIT_VALID(limit)    (((limit) == CY_SYSPM_CORE_BUCK_INRUSH_LIMIT_10)     || \
                                                            ((limit) == CY_SYSPM_CORE_BUCK_INRUSH_LIMIT_100))

/* Macro to validate parameters in Cy_SysPm_LdoSdrConfigure() function */
#define CY_SYSPM_IS_SDR_VOLTAGE_VALID(voltage)          (((voltage) == CY_SYSPM_SDR_VOLTAGE_0_900V) || \
                                                         ((voltage) == CY_SYSPM_SDR_VOLTAGE_1_000V) || \
                                                         ((voltage) == CY_SYSPM_SDR_VOLTAGE_1_100V))

/* Macro to validate parameters in Cy_SysPm_HvLdoConfigure() function */
#define CY_SYSPM_IS_HVLDO_VOLTAGE_VALID(voltage)        (((voltage) == CY_SYSPM_HVLDO_VOLTAGE_1_800V) || \
                                                         ((voltage) == CY_SYSPM_HVLDO_VOLTAGE_1_900V)  || \
                                                         ((voltage) == CY_SYSPM_HVLDO_VOLTAGE_2_000V) || \
                                                         ((voltage) == CY_SYSPM_HVLDO_VOLTAGE_2_100V) || \
                                                         ((voltage) == CY_SYSPM_HVLDO_VOLTAGE_2_200V)  || \
                                                         ((voltage) == CY_SYSPM_HVLDO_VOLTAGE_2_300V) || \
                                                         ((voltage) == CY_SYSPM_HVLDO_VOLTAGE_2_400V)  || \
                                                         ((voltage) == CY_SYSPM_HVLDO_VOLTAGE_2_500V) || \
                                                         ((voltage) == CY_SYSPM_HVLDO_VOLTAGE_2_600V)  || \
                                                         ((voltage) == CY_SYSPM_HVLDO_VOLTAGE_2_700V) || \
                                                         ((voltage) == CY_SYSPM_HVLDO_VOLTAGE_2_800V)  || \
                                                         ((voltage) == CY_SYSPM_HVLDO_VOLTAGE_2_900V) || \
                                                         ((voltage) == CY_SYSPM_HVLDO_VOLTAGE_3_000V)  || \
                                                         ((voltage) == CY_SYSPM_HVLDO_VOLTAGE_3_100V) || \
                                                         ((voltage) == CY_SYSPM_HVLDO_VOLTAGE_3_200V) || \
                                                         ((voltage) == CY_SYSPM_HVLDO_VOLTAGE_3_300V))

/* Macro to validate if the SDR number in Cy_SysPm_LdoSdrConfigure() function */
#define CY_SYSPM_IS_SDR_NUM_VALID(num)    (((num) == CY_SYSPM_SDR_0)     || \
                                           ((num) == CY_SYSPM_SDR_1))

/* Macro to validate parameters in RAM/ROM TRIM functions */
#define CY_SYSPM_IS_SDR_TRIM_VOLTAGE_VALID(voltage)     (((voltage) == CY_SYSPM_SDR_VOLTAGE_0_900V) || \
                                                         ((voltage) == CY_SYSPM_SDR_VOLTAGE_1_000V)  || \
                                                         ((voltage) == CY_SYSPM_SDR_VOLTAGE_1_100V))

/* Macro to validate number of Macros supported in SRAM0 */

#define CY_SYSPM_IS_SRAM0_MACRO_NUM_VALID(macroNum)      (((macroNum) == CY_SYSPM_SRAM0_MACRO_0)         || \
                                                         ((macroNum) == CY_SYSPM_SRAM0_MACRO_1))

#endif /* defined (CY_IP_MXS40SSRSS) || defined (CY_DOXYGEN) */


/* Macro to validate parameters in Cy_SysPm_ExecuteCallback() function */

#if defined (CY_IP_MXS40SSRSS)
#define CY_SYSPM_IS_CALLBACK_MODE_VALID(mode)           (((mode) == CY_SYSPM_CHECK_READY) || \
                                                         ((mode) == CY_SYSPM_CHECK_FAIL) || \
                                                         ((mode) == CY_SYSPM_BEFORE_TRANSITION) || \
                                                         ((mode) == CY_SYSPM_AFTER_TRANSITION) || \
                                                         ((mode) == CY_SYSPM_AFTER_DS_WFI_TRANSITION))
#endif


/* Macro to validate parameters in Cy_SysPm_CpuEnterSleep() and for Cy_SysPm_CpuEnterDeepSleep() function */
#define CY_SYSPM_IS_WAIT_FOR_VALID(waitFor)             (((waitFor) == CY_SYSPM_WAIT_FOR_INTERRUPT) || \
                                                         ((waitFor) == CY_SYSPM_WAIT_FOR_EVENT))

/* Macro to validate parameters in Cy_SysPm_BackupSetSupply() function */
#define CY_SYSPM_IS_VDDBACKUP_VALID(vddBackControl)      (((vddBackControl) == CY_SYSPM_VDDBACKUP_DEFAULT) || \
                                                          ((vddBackControl) == CY_SYSPM_VDDBACKUP_VBACKUP))

/* Macro to validate parameters in Cy_SysPm_BackupSuperCapCharge() function */
#define CY_SYSPM_IS_SC_CHARGE_KEY_VALID(key)            (((key) == CY_SYSPM_SC_CHARGE_ENABLE) || \
                                                         ((key) == CY_SYSPM_SC_CHARGE_DISABLE))

/* Macro to validate parameters in Cy_SysPm_LdoSetMode() function */
#define CY_SYSPM_IS_LDO_MODE_VALID(key)            (((mode) == CY_SYSPM_LDO_MODE_DISABLED) || \
                                                    ((mode) == CY_SYSPM_LDO_MODE_NORMAL) || \
                                                    ((mode) == CY_SYSPM_LDO_MODE_MIN))

/* Macro to validate parameters in Cy_SysPm_WriteVoltageBitForFlash() function */
#define CY_SYSPM_IS_BIT_FOR_FLASH_VALID(value)     (((value) == CY_SYSPM_FLASH_VOLTAGE_BIT_ULP) || \
                                                    ((value) == CY_SYSPM_FLASH_VOLTAGE_BIT_LP))

/** The internal define of the SRAM PWR MACRO register key for write operation */
#define CY_SYSPM_PWR_MACRO_CTL_WRITE_KEY            (0x05FAU)

/** The internal define of the unlock value for the PMIC functions */
#define CY_SYSPM_PMIC_UNLOCK_KEY                    (0x3AU)

#if defined (CY_IP_MXS22SRSS) && (CY_IP_MXS22SRSS_VERSION == 2UL) && (CY_IP_MXS22SRSS_VERSION_MINOR == 1UL) && defined (CY_DEVICE_PSB3)

/** The internal define of the first wakeup pin bit used in the
* Cy_SysPm_SetHibernateWakeupSource() function
*/
#define CY_SYSPM_HIB_WAKEUP_PIN0_POS                ((uint32_t) 0x1U << 0U)

/** The internal define of the second wakeup pin bit
* used in the Cy_SysPm_SetHibernateWakeupSource() function
*/
#define CY_SYSPM_HIB_WAKEUP_PIN1_POS                ((uint32_t) 0x1U << 1U)


/** The internal define of the third wakeup pin bit used in the
* Cy_SysPm_SetHibernateWakeupSource() function
*/
#define CY_SYSPM_HIB_WAKEUP_PIN2_POS                ((uint32_t) 0x1U << 2U)

/** The internal define of the fourth wakeup pin bit
* used in the Cy_SysPm_SetHibernateWakeupSource() function
*/
#define CY_SYSPM_HIB_WAKEUP_PIN3_POS                ((uint32_t) 0x1U << 3U)

/** The internal define of the BTSS wakeup bit
* used in the Cy_SysPm_SetHibernateWakeupSource() function
*/
#define CY_SYSPM_HIB_WAKEUP_BTSS_POS                ((uint32_t) 0x1U << 4U)

/** The internal define of the WDT0 wake bit
* used in the Cy_SysPm_SetHibernateWakeupSource() function
*/
#define CY_SYSPM_HIB_WAKEUP_WDT0_POS                ((uint32_t) 0x1U << 0U)

#if defined(SRSS_NUM_WDT_A) && (SRSS_NUM_WDT_A > 1)
/** The internal define of the WDT1 wake bit
* used in the Cy_SysPm_SetHibernateWakeupSource() function
*/
#define CY_SYSPM_HIB_WAKEUP_WDT1_POS                ((uint32_t) 0x1U << 1U)
#endif

#else

/** The internal define of the first wakeup pin bit used in the
* Cy_SysPm_SetHibernateWakeupSource() function
*/
#define CY_SYSPM_HIB_WAKEUP_PIN0_POS                (1UL)

/** The internal define of the second wakeup pin bit
* used in the Cy_SysPm_SetHibernateWakeupSource() function
*/
#define CY_SYSPM_HIB_WAKEUP_PIN1_POS                (2UL)

/**
* The internal define of the first LPComparator bit
* used in the Cy_SysPm_SetHibernateWakeupSource() function
*/
#define CY_SYSPM_HIB_WAKEUP_LPCOMP0_POS             (4UL)

/**
* The internal define for the second LPComparator bit
* used in the Cy_SysPm_SetHibernateWakeupSource() function
*/
#define CY_SYSPM_HIB_WAKEUP_LPCOMP1_POS             (8UL)

#endif /* defined (CY_IP_MXS22SRSS) && (CY_IP_MXS22SRSS_VERSION == 2UL) && (CY_IP_MXS22SRSS_VERSION_MINOR == 1UL) && defined (CY_DEVICE_PSB3) */

#if defined (CY_IP_MXS40SSRSS) || defined (CY_IP_MXS22SRSS) || defined (CY_DOXYGEN)

#if (CY_IP_MXS22SRSS_VERSION == 2UL) && (CY_IP_MXS22SRSS_VERSION_MINOR == 1UL) && defined (CY_DEVICE_PSB3)

/**
* The internal define of the first wake-up pin value
* used in the Cy_SysPm_SetHibernateWakeupSource() function
*/
#define CY_SYSPM_HIB_WAKEUP_PIN0_MASK    (_VAL2FLD(PWRCTL_MAIN_HV_HIBERNATE_PWR_HIB_WAKE_CTL_HIB_WAKE_SRC, CY_SYSPM_HIB_WAKEUP_PIN0_POS))

/**
* The internal define of the second wake-up pin value
* used in the Cy_SysPm_SetHibernateWakeupSource() function
*/
#define CY_SYSPM_HIB_WAKEUP_PIN1_MASK    (_VAL2FLD(PWRCTL_MAIN_HV_HIBERNATE_PWR_HIB_WAKE_CTL_HIB_WAKE_SRC, CY_SYSPM_HIB_WAKEUP_PIN1_POS))

/**
* The internal define of the third wake-up pin value
* used in the Cy_SysPm_SetHibernateWakeupSource() function
*/
#define CY_SYSPM_HIB_WAKEUP_PIN2_MASK    (_VAL2FLD(PWRCTL_MAIN_HV_HIBERNATE_PWR_HIB_WAKE_CTL_HIB_WAKE_SRC, CY_SYSPM_HIB_WAKEUP_PIN2_POS))

/**
* The internal define of the fourth wake-up pin value
* used in the Cy_SysPm_SetHibernateWakeupSource() function
*/
#define CY_SYSPM_HIB_WAKEUP_PIN3_MASK    (_VAL2FLD(PWRCTL_MAIN_HV_HIBERNATE_PWR_HIB_WAKE_CTL_HIB_WAKE_SRC, CY_SYSPM_HIB_WAKEUP_PIN3_POS))

/**
* The internal define of the BTSS interrupt wake value
* used in the Cy_SysPm_SetHibernateWakeupSource() function
*/
#define CY_SYSPM_HIB_WAKEUP_BTSS_MASK    (_VAL2FLD(PWRCTL_MAIN_HV_HIBERNATE_PWR_HIB_WAKE_CTL_HIB_WAKE_SRC, CY_SYSPM_HIB_WAKEUP_BTSS_POS))

/**
* The internal define of the WDT wakeup source
* used in the Cy_SysPm_SetHibernateWakeupSource() function
*/
#define CY_SYSPM_HIB_WAKEUP_WDT_MASK    PWRCTL_MAIN_HV_HIBERNATE_PWR_HIB_WAKE_CTL_HIB_WAKE_WDT_Msk

/**
* The internal define of the WDT0 wakeup source
* used in the Cy_SysPm_SetHibernateWakeupSource() function
*/
#define CY_SYSPM_HIB_WAKEUP_WDT0_MASK  (_VAL2FLD(PWRCTL_MAIN_HV_HIBERNATE_PWR_HIB_WAKE_CTL_HIB_WAKE_WDT, CY_SYSPM_HIB_WAKEUP_WDT0_POS))

#if defined(SRSS_NUM_WDT_A) && (SRSS_NUM_WDT_A > 1)
/**
* The internal define of the WDT1 wakeup source
* used in the Cy_SysPm_SetHibernateWakeupSource() function
*/
#define CY_SYSPM_HIB_WAKEUP_WDT1_MASK  (_VAL2FLD(PWRCTL_MAIN_HV_HIBERNATE_PWR_HIB_WAKE_CTL_HIB_WAKE_WDT, CY_SYSPM_HIB_WAKEUP_WDT1_POS))
#endif

/**
* The internal define of the RTC wakeup source
* used in the Cy_SysPm_SetHibernateWakeupSource() function
*/
#define CY_SYSPM_HIB_WAKEUP_RTC_MASK    PWRCTL_MAIN_HV_HIBERNATE_PWR_HIB_WAKE_CTL_HIB_WAKE_RTC_Msk

/** The internal define for the first wake-up pin polarity configuration */
#define CY_SYSPM_HIB_WAKEUP_PIN0_POLARITY_HIGH_MASK    \
                                  (_VAL2FLD(PWRCTL_MAIN_HV_HIBERNATE_PWR_HIB_WAKE_CTL2_HIB_WAKE_SRC, CY_SYSPM_HIB_WAKEUP_PIN0_POS))

/** The internal define for the second wake-up pin polarity configuration */
#define CY_SYSPM_HIB_WAKEUP_PIN1_POLARITY_HIGH_MASK    \
                                  (_VAL2FLD(PWRCTL_MAIN_HV_HIBERNATE_PWR_HIB_WAKE_CTL2_HIB_WAKE_SRC, CY_SYSPM_HIB_WAKEUP_PIN1_POS))

/** The internal define for the third wake-up pin polarity configuration */
#define CY_SYSPM_HIB_WAKEUP_PIN2_POLARITY_HIGH_MASK    \
                                  (_VAL2FLD(PWRCTL_MAIN_HV_HIBERNATE_PWR_HIB_WAKE_CTL2_HIB_WAKE_SRC, CY_SYSPM_HIB_WAKEUP_PIN2_POS))

/** The internal define for the fourth wake-up pin polarity configuration */
#define CY_SYSPM_HIB_WAKEUP_PIN3_POLARITY_HIGH_MASK    \
                                  (_VAL2FLD(PWRCTL_MAIN_HV_HIBERNATE_PWR_HIB_WAKE_CTL2_HIB_WAKE_SRC, CY_SYSPM_HIB_WAKEUP_PIN3_POS))

/** The internal define for the BTSS signal polarity configuration */
#define CY_SYSPM_HIB_WAKEUP_BTSS_POLARITY_HIGH_MASK    \
                                  (_VAL2FLD(PWRCTL_MAIN_HV_HIBERNATE_PWR_HIB_WAKE_CTL2_HIB_WAKE_SRC, CY_SYSPM_HIB_WAKEUP_BTSS_POS))

#elif (CY_IP_MXS22SRSS_VERSION == 2UL)
/**
* The internal define of the first LPComparator value
* used in the Cy_SysPm_SetHibernateWakeupSource() function
*/
#define CY_SYSPM_HIB_WAKEUP_LPCOMP0_MASK    (_VAL2FLD(PWRCTL_MAIN_HV_HIBERNATE_PWR_HIB_WAKE_CTL_HIB_WAKE_SRC, CY_SYSPM_HIB_WAKEUP_LPCOMP0_POS))

/**
* The internal define of the second LPComparator value
* used in the Cy_SysPm_SetHibernateWakeupSource() function
*/
#define CY_SYSPM_HIB_WAKEUP_LPCOMP1_MASK    (_VAL2FLD(PWRCTL_MAIN_HV_HIBERNATE_PWR_HIB_WAKE_CTL_HIB_WAKE_SRC, CY_SYSPM_HIB_WAKEUP_LPCOMP1_POS))

/**
* The internal define of the first wake-up pin value
* used in the Cy_SysPm_SetHibernateWakeupSource() function
*/
#define CY_SYSPM_HIB_WAKEUP_PIN0_MASK    (_VAL2FLD(PWRCTL_MAIN_HV_HIBERNATE_PWR_HIB_WAKE_CTL_HIB_WAKE_SRC, CY_SYSPM_HIB_WAKEUP_PIN0_POS))

/**
* The internal define of the second wake-up pin value used
* in the Cy_SysPm_SetHibernateWakeupSource() function
*/
#define CY_SYSPM_HIB_WAKEUP_PIN1_MASK    (_VAL2FLD(PWRCTL_MAIN_HV_HIBERNATE_PWR_HIB_WAKE_CTL_HIB_WAKE_SRC, CY_SYSPM_HIB_WAKEUP_PIN1_POS))

/** The internal define for the first LPComparator polarity configuration */
#define CY_SYSPM_HIB_WAKEUP_LPCOMP0_POLARITY_HIGH_MASK    \
                                  (_VAL2FLD(PWRCTL_MAIN_HV_HIBERNATE_PWR_HIB_WAKE_CTL2_HIB_WAKE_SRC, CY_SYSPM_HIB_WAKEUP_LPCOMP0_POS))

/** The internal define for the second LPComparator polarity configuration */
#define CY_SYSPM_HIB_WAKEUP_LPCOMP1_POLARITY_HIGH_MASK    \
                                  (_VAL2FLD(PWRCTL_MAIN_HV_HIBERNATE_PWR_HIB_WAKE_CTL2_HIB_WAKE_SRC, CY_SYSPM_HIB_WAKEUP_LPCOMP1_POS))

/** The internal define for the first wake-up pin polarity configuration */
#define CY_SYSPM_HIB_WAKEUP_PIN0_POLARITY_HIGH_MASK    \
                                  (_VAL2FLD(PWRCTL_MAIN_HV_HIBERNATE_PWR_HIB_WAKE_CTL2_HIB_WAKE_SRC, CY_SYSPM_HIB_WAKEUP_PIN0_POS))

/** The internal define for the second wake-up pin polarity configuration */
#define CY_SYSPM_HIB_WAKEUP_PIN1_POLARITY_HIGH_MASK    \
                                  (_VAL2FLD(PWRCTL_MAIN_HV_HIBERNATE_PWR_HIB_WAKE_CTL2_HIB_WAKE_SRC, CY_SYSPM_HIB_WAKEUP_PIN1_POS))

/**
* The internal define of the WDT wakeup source
* used in the Cy_SysPm_SetHibernateWakeupSource() function
*/
#define CY_SYSPM_HIB_WAKEUP_WDT_MASK    PWRCTL_MAIN_HV_HIBERNATE_PWR_HIB_WAKE_CTL_HIB_WAKE_WDT_Msk

/**
* The internal define of the WDT wakeup source
* used in the Cy_SysPm_SetHibernateWakeupSource() function
*/
#define CY_SYSPM_HIB_WAKEUP_RTC_MASK    PWRCTL_MAIN_HV_HIBERNATE_PWR_HIB_WAKE_CTL_HIB_WAKE_RTC_Msk

#else
/**
* The internal define of the first LPComparator value
* used in the Cy_SysPm_SetHibernateWakeupSource() function
*/
#define CY_SYSPM_HIB_WAKEUP_LPCOMP0_MASK    (_VAL2FLD(SRSS_PWR_HIB_WAKE_CTL_HIB_WAKE_SRC, CY_SYSPM_HIB_WAKEUP_LPCOMP0_POS))

/**
* The internal define of the second LPComparator value
* used in the Cy_SysPm_SetHibernateWakeupSource() function
*/
#define CY_SYSPM_HIB_WAKEUP_LPCOMP1_MASK    (_VAL2FLD(SRSS_PWR_HIB_WAKE_CTL_HIB_WAKE_SRC, CY_SYSPM_HIB_WAKEUP_LPCOMP1_POS))

/**
* The internal define of the first wake-up pin value
* used in the Cy_SysPm_SetHibernateWakeupSource() function
*/
#define CY_SYSPM_HIB_WAKEUP_PIN0_MASK    (_VAL2FLD(SRSS_PWR_HIB_WAKE_CTL_HIB_WAKE_SRC, CY_SYSPM_HIB_WAKEUP_PIN0_POS))

/**
* The internal define of the second wake-up pin value used
* in the Cy_SysPm_SetHibernateWakeupSource() function
*/
#define CY_SYSPM_HIB_WAKEUP_PIN1_MASK    (_VAL2FLD(SRSS_PWR_HIB_WAKE_CTL_HIB_WAKE_SRC, CY_SYSPM_HIB_WAKEUP_PIN1_POS))

/** The internal define for the first LPComparator polarity configuration */
#define CY_SYSPM_HIB_WAKEUP_LPCOMP0_POLARITY_HIGH_MASK    \
                                  (_VAL2FLD(SRSS_PWR_HIB_WAKE_CTL2_HIB_WAKE_SRC, CY_SYSPM_HIB_WAKEUP_LPCOMP0_POS))

/** The internal define for the second LPComparator polarity configuration */
#define CY_SYSPM_HIB_WAKEUP_LPCOMP1_POLARITY_HIGH_MASK    \
                                  (_VAL2FLD(SRSS_PWR_HIB_WAKE_CTL2_HIB_WAKE_SRC, CY_SYSPM_HIB_WAKEUP_LPCOMP1_POS))

/** The internal define for the first wake-up pin polarity configuration */
#define CY_SYSPM_HIB_WAKEUP_PIN0_POLARITY_HIGH_MASK    \
                                  (_VAL2FLD(SRSS_PWR_HIB_WAKE_CTL2_HIB_WAKE_SRC, CY_SYSPM_HIB_WAKEUP_PIN0_POS))

/** The internal define for the second wake-up pin polarity configuration */
#define CY_SYSPM_HIB_WAKEUP_PIN1_POLARITY_HIGH_MASK    \
                                  (_VAL2FLD(SRSS_PWR_HIB_WAKE_CTL2_HIB_WAKE_SRC, CY_SYSPM_HIB_WAKEUP_PIN1_POS))

/**
* The internal define of the WDT wakeup source
* used in the Cy_SysPm_SetHibernateWakeupSource() function
*/
#define CY_SYSPM_HIB_WAKEUP_WDT_MASK    SRSS_PWR_HIB_WAKE_CTL_HIB_WAKE_WDT_Msk

/**
* The internal define of the WDT wakeup source
* used in the Cy_SysPm_SetHibernateWakeupSource() function
*/
#define CY_SYSPM_HIB_WAKEUP_RTC_MASK    SRSS_PWR_HIB_WAKE_CTL_HIB_WAKE_RTC_Msk
#endif /*(CY_IP_MXS22SRSS_VERSION == 2UL) && (CY_IP_MXS22SRSS_VERSION_MINOR == 1UL) && defined (CY_DEVICE_PSB3)*/
#endif /*(CY_IP_MXS40SSRSS) || defined (CY_IP_MXS22SRSS)*/

#if defined (CY_IP_MXS22SRSS) && (CY_IP_MXS22SRSS_VERSION == 2UL) && (CY_IP_MXS22SRSS_VERSION_MINOR >= 1UL)
#define CY_SYSPM_HIB_WAKEUP_SOURCE_MASK    (CY_SYSPM_HIBERNATE_PIN0_LOW    | CY_SYSPM_HIBERNATE_PIN0_HIGH |\
                                            CY_SYSPM_HIBERNATE_PIN1_LOW    | CY_SYSPM_HIBERNATE_PIN1_HIGH |\
                                            CY_SYSPM_HIBERNATE_PIN2_LOW    | CY_SYSPM_HIBERNATE_PIN2_HIGH |\
                                            CY_SYSPM_HIBERNATE_PIN3_LOW    | CY_SYSPM_HIBERNATE_PIN3_HIGH |\
                                            CY_SYSPM_HIBERNATE_BTSS_LOW    | CY_SYSPM_HIBERNATE_BTSS_HIGH |\
                                            CY_SYSPM_HIBERNATE_WDT0        | CY_SYSPM_HIBERNATE_WDT1 | \
                                            CY_SYSPM_HIBERNATE_RTC_ALARM )
#else
/* Internal macro of all possible wakeup sources from hibernate power mode */
#define CY_SYSPM_HIB_WAKEUP_SOURCE_MASK    (CY_SYSPM_HIBERNATE_LPCOMP0_LOW | CY_SYSPM_HIBERNATE_LPCOMP0_HIGH |\
                                            CY_SYSPM_HIBERNATE_LPCOMP1_LOW | CY_SYSPM_HIBERNATE_LPCOMP1_HIGH |\
                                            CY_SYSPM_HIBERNATE_RTC_ALARM   | CY_SYSPM_HIBERNATE_WDT |\
                                            CY_SYSPM_HIBERNATE_PIN0_LOW    | CY_SYSPM_HIBERNATE_PIN0_HIGH |\
                                            CY_SYSPM_HIBERNATE_PIN1_LOW    | CY_SYSPM_HIBERNATE_PIN1_HIGH)
#endif


/* The mask for low power modes the power circuits (POR/BOD, Bandgap
*  reference, Reference buffer, Current reference) when active core regulator is
*  LDO
*/
#define CY_SYSPM_PWR_CIRCUITS_LPMODE_ACTIVE_LDO_MASK    (SRSS_PWR_CTL2_LINREG_LPMODE_Msk | CY_SYSPM_PWR_CIRCUITS_LPMODE_ACTIVE_BUCK_MASK)

/* The mask for low power modes the power circuits (POR/BOD, Bandgap
*  reference, Reference buffer, Current reference) when active core regulator is
*  Buck
*/
#define CY_SYSPM_PWR_CIRCUITS_LPMODE_ACTIVE_BUCK_MASK    (SRSS_PWR_CTL2_PORBOD_LPMODE_Msk |\
                                                          SRSS_PWR_CTL2_REFVBUF_DIS_Msk |\
                                                          SRSS_PWR_CTL2_BGREF_LPMODE_Msk)

/* Macro to validate the word index supported in Backup Domain for Store/Restore */
#define CY_SYSPM_IS_WORD_INDEX_VALID(index)    ((index < CY_SRSS_BACKUP_NUM_BREG) && \
                                                 (index > 0U))

/* Macro to validate number of words supported in Backup Domain for Store/Restore */
#define CY_SYSPM_IS_WORD_SIZE_VALID(size)    ((size) <= CY_SRSS_BACKUP_NUM_BREG)

/** \endcond */

/**
* \defgroup group_syspm_return_status The Power Mode Status Defines
* \{
* Defines for the CPU and system power modes status.
*/





/** The system is Low Power mode */
#define CY_SYSPM_STATUS_SYSTEM_LP        ((uint32_t) ((uint32_t)0x80U))

/** The system is in Ultra Low Power mode */
#define CY_SYSPM_STATUS_SYSTEM_ULP       ((uint32_t) ((uint32_t)0x08U << 8U))

/** The system is LPACTIVE Power mode */
#define CY_SYSPM_STATUS_SYSTEM_LPACTIVE  ((uint32_t) ((uint32_t)0x08UL << 16U))

#if !defined(CY_IP_MXS22SRSS)
/** The system is Medium Frequency Low Power mode */
#define CY_SYSPM_STATUS_SYSTEM_MF        ((uint32_t) ((uint32_t)0x08UL << 24U))
#endif

/** The system is OD Low Power mode */
#define CY_SYSPM_STATUS_SYSTEM_OD        ((uint32_t) ((uint32_t)0x08UL << 28U))

/** The wait time for transition of the device from the Active into
* the LPActive (Low Power Active)
*/
#define CY_SYSPM_ACTIVE_TO_LP_WAIT_US           (1u)

/** The wait delay time which occurs before the Active reference is settled.
* This delay is used in transition of the device from Active into the
* LPACTIVE (Low Power Active) mode
*/
#define CY_SYSPM_LP_TO_ACTIVE_WAIT_BEFORE_US    (8u)

/** The wait delay time which occurs after the Active reference is settled.
* This delay is used in transition the device from Active into the
* LPACTIVE (Low Power Active) mode
*/
#define CY_SYSPM_LP_TO_ACTIVE_WAIT_AFTER_US    (1u)

/** The internal define of the tries number in the Cy_SysPm_ExitLpMode()
* function
 */
#define CY_SYSPM_WAIT_DELAY_TRIES                        (100u)

/** \} group_syspm_return_status */

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
    CY_SYSPM_CANCELED        = CY_SYSPM_ID | CY_PDL_STATUS_ERROR | 0x04U,    /**< Operation canceled. */
    CY_SYSPM_SYSCALL_PENDING = CY_SYSPM_ID | CY_PDL_STATUS_ERROR | 0x05U,    /**< Canceled due syscall operation pending. */
    CY_SYSPM_FAIL            = CY_SYSPM_ID | CY_PDL_STATUS_ERROR | 0xFFU     /**< Unknown failure. */
} cy_en_syspm_status_t;

/**
* This enumeration is used to initialize the functions wait action. The wait actions can be -
* an interrupt or an event. Refer to the CMSIS for WFE and WFI instruction explanations.
*/
typedef enum
{
    CY_SYSPM_WAIT_FOR_INTERRUPT,    /**< Wait for an interrupt. */
    CY_SYSPM_WAIT_FOR_EVENT         /**< Wait for an event. */
} cy_en_syspm_waitfor_t;

#if defined (CY_IP_MXS40SSRSS) || defined (CY_DOXYGEN)
/**
* This enumeration is used to distinguish between the pre and post checks required during DS-RAM.
*/

typedef enum
{
    CY_SYSPM_PRE_DSRAM,             /**< Pre DSRAM Checks. */
    CY_SYSPM_POST_DSRAM             /**< Post DSRAM Checks. */
} cy_en_syspm_dsram_checks_t;
#endif

/** This enumeration is used to configure wakeup sources for the System Hibernate
*   power mode.
*/
#if defined (CY_IP_MXS40SSRSS) || defined (CY_IP_MXS22SRSS) || defined (CY_DOXYGEN)

#if defined (CY_IP_MXS22SRSS) && (CY_IP_MXS22SRSS_VERSION == 2UL) && (CY_IP_MXS22SRSS_VERSION_MINOR >= 1UL)
typedef enum
{
     /** Configure a low logic level for the first wakeup-pin. See device datasheet for specific pin. */
    CY_SYSPM_HIBERNATE_PIN0_LOW     = ((uint32_t) 0x1U << 0U),

    /** Configure a high logic level for the first wakeup-pin. See device datasheet for specific pin.*/
    CY_SYSPM_HIBERNATE_PIN0_HIGH    = ((uint32_t) 0x1U << 1U),

    /** Configure a low logic level for the second wakeup-pin. See device datasheet for specific pin.*/
    CY_SYSPM_HIBERNATE_PIN1_LOW     = ((uint32_t) 0x1U << 2U),

    /** Configure a high logic level for the second wakeup-pin. See device datasheet for specific pin.*/
    CY_SYSPM_HIBERNATE_PIN1_HIGH    = ((uint32_t) 0x1U << 3U),

    /** Configure a low logic level for the third wakeup-pin. See device datasheet for specific pin. */
    CY_SYSPM_HIBERNATE_PIN2_LOW     = ((uint32_t) 0x1U << 4U),

    /** Configure a high logic level for the third wakeup-pin. See device datasheet for specific pin.*/
    CY_SYSPM_HIBERNATE_PIN2_HIGH    = ((uint32_t) 0x1U << 5U),

    /** Configure a low logic level for the fourth wakeup-pin. See device datasheet for specific pin.*/
    CY_SYSPM_HIBERNATE_PIN3_LOW     = ((uint32_t) 0x1U << 6U),

    /** Configure a high logic level for the fourth wakeup-pin. See device datasheet for specific pin.*/
    CY_SYSPM_HIBERNATE_PIN3_HIGH    = ((uint32_t) 0x1U << 7U),

    /** Configure a low logic level for the BTSS wake signal. See device datasheet for specific pin.*/
    CY_SYSPM_HIBERNATE_BTSS_LOW     = ((uint32_t) 0x1U << 8U),

    /** Configure a high logic level for the BTSS wake signal. See device datasheet for specific pin.*/
    CY_SYSPM_HIBERNATE_BTSS_HIGH    = ((uint32_t) 0x1U << 9U),

    /** Configure the WDT0 interrupt as wakeup source. */
    CY_SYSPM_HIBERNATE_WDT0         = ((uint32_t) 0x1U << 10U),

    /** Configure the WDT0 interrupt as wakeup source. */
    CY_SYSPM_HIBERNATE_WDT1         = ((uint32_t) 0x1U << 11U),

     /** Configure the RTC alarm as wakeup source. */
    CY_SYSPM_HIBERNATE_RTC_ALARM    = ((uint32_t) 0x1U << 12U)
} cy_en_syspm_hibernate_wakeup_source_t;
#else
typedef enum
{
    /** Wake on a low logic level for the LPComp0. */
    CY_SYSPM_HIBERNATE_LPCOMP0_LOW  = 0x1U,

    /** Wake on a high logic level for the LPComp0. */
    CY_SYSPM_HIBERNATE_LPCOMP0_HIGH = (0x1U << 1),

    /** Wake on a low logic level for the LPComp1. */
    CY_SYSPM_HIBERNATE_LPCOMP1_LOW  = (0x1U << 2),

    /** Wake on a high logic level for the LPComp1. */
    CY_SYSPM_HIBERNATE_LPCOMP1_HIGH = (0x1U << 3),

    /** Configure the RTC alarm as wakeup source. */
    CY_SYSPM_HIBERNATE_RTC_ALARM    = (0x1U << 4),

    /** Configure the WDT interrupt as wakeup source. */
    CY_SYSPM_HIBERNATE_WDT          = (0x1U << 5),

    /** Configure a low logic level for the first wakeup-pin. See device datasheet for specific pin. */
    CY_SYSPM_HIBERNATE_PIN0_LOW     = (0x1U << 6),

    /** Configure a high logic level for the first wakeup-pin. See device datasheet for specific pin.*/
    CY_SYSPM_HIBERNATE_PIN0_HIGH    = (0x1U << 7),

    /** Configure a low logic level for the second wakeup-pin. See device datasheet for specific pin.*/
    CY_SYSPM_HIBERNATE_PIN1_LOW     = (0x1U << 8),

    /** Configure a high logic level for the second wakeup-pin. See device datasheet for specific pin.*/
    CY_SYSPM_HIBERNATE_PIN1_HIGH    = (0x1U << 9)
} cy_en_syspm_hibernate_wakeup_source_t;
#endif
#endif

#if defined (CY_IP_MXS40SSRSS) && (CY_MXS40SSRSS_VER_1_2 > 0UL)
/** This enumeration is used to select LDO regulator output voltage. */
typedef enum
{
    CY_SYSPM_LDO_VOLTAGE_ULP  = 0U,    /**< System ULP nominal LDO voltage.
                                            See device datasheet for specific voltage. */
    CY_SYSPM_LDO_VOLTAGE_LP   = 1U,    /**< System LP nominal LDO voltage.
                                            See device datasheet for specific voltage. */
    CY_SYSPM_LDO_VOLTAGE_MF   = 2U,    /**< System MF nominal LDO voltage.
                                            See device datasheet for specific voltage. */
    CY_SYSPM_LDO_VOLTAGE_OD   = 3U,    /**< System OD nominal LDO voltage.
                                            See device datasheet for specific voltage. */
    CY_SYSPM_LDO_VOLTAGE_0_9V = 0U,    /**< 0.9 V nominal LDO voltage */
    CY_SYSPM_LDO_VOLTAGE_1_1V = 1U,     /**< 1.1 V nominal LDO voltage */
    CY_SYSPM_LDO_VOLTAGE_1_0V = 2U,    /**< 1.0 V nominal LDO voltage */
    CY_SYSPM_LDO_VOLTAGE_1_2V = 3U     /**< 1.2 V nominal LDO voltage */
} cy_en_syspm_ldo_voltage_t;
#endif

/** This enumeration is used to select the LDO regulator operating mode. */
typedef enum
{
    CY_SYSPM_LDO_MODE_DISABLED = 0U,    /**< Disables the LDO. */
    CY_SYSPM_LDO_MODE_NORMAL   = 1U,    /**< Sets normal current mode. See device datasheet for
                                             specific maximum current limit. */
    CY_SYSPM_LDO_MODE_MIN      = 2U     /**< Sets minimum current mode. See device datasheet for
                                             specific  current limit.  */
} cy_en_syspm_ldo_mode_t;

/**
*  This enumeration is used to select the output voltage for the Buck regulator output 1.
*/
typedef enum
{
    CY_SYSPM_BUCK_OUT1_VOLTAGE_ULP  = 0x02U,    /**< System ULP nominal Buck voltage.
                                                     See device datasheet for specific voltage. */
    CY_SYSPM_BUCK_OUT1_VOLTAGE_LP   = 0x05U,    /**< LP nominal Buck voltage.
                                                     See device datasheet for specific voltage. */
    CY_SYSPM_BUCK_OUT1_VOLTAGE_0_9V = 0x02U,    /**< 0.9 V nominal Buck voltage */
    CY_SYSPM_BUCK_OUT1_VOLTAGE_1_1V = 0x05U     /**< 1.1 V nominal Buck voltage */
} cy_en_syspm_buck_voltage1_t;

/** This enumeration is used to select the Buck regulator outputs. */
typedef enum
{
    CY_SYSPM_BUCK_VBUCK_1 = 0x0U,    /**< Buck output 1 Voltage (Vbuck1). Typically used to
                                          supply the PSOC digital core logic. */
    CY_SYSPM_BUCK_VRF                /**< Buck out 2 Voltage (Vbuckrf). Typically used to
                                          supply the BLE radio logic. */
} cy_en_syspm_buck_out_t;

/**
* This enumeration is used to select the output voltage for the Buck regulator
* output 2, which can source the BLE radio.
*/
typedef enum
{
    CY_SYSPM_BUCK_OUT2_VOLTAGE_1_15V = 0U,    /**< 1.15 V nominal voltage. */
    CY_SYSPM_BUCK_OUT2_VOLTAGE_1_2V  = 1U,    /**< 1.20 V nominal voltage. */
    CY_SYSPM_BUCK_OUT2_VOLTAGE_1_25V = 2U,    /**< 1.25 V nominal voltage. */
    CY_SYSPM_BUCK_OUT2_VOLTAGE_1_3V  = 3U,    /**< 1.3 V nominal voltage.  */
    CY_SYSPM_BUCK_OUT2_VOLTAGE_1_35V = 4U,    /**< 1.35 V nominal voltage. */
    CY_SYSPM_BUCK_OUT2_VOLTAGE_1_4V  = 5U,    /**< 1.4 V nominal voltage. */
    CY_SYSPM_BUCK_OUT2_VOLTAGE_1_45V = 6U,    /**< 1.45 V nominal voltage. */
    CY_SYSPM_BUCK_OUT2_VOLTAGE_1_5V  = 7U     /**< 1.5 V nominal voltage. */
} cy_en_syspm_buck_voltage2_t;

/**
* This enumeration is used to set the polarity for the PMIC input. The PMIC output is
* automatically enabled when the configured polarity of the PMIC input and the logic level
* driven to the pmic_wakeup_in pin match.
*
* \warning
* Do not use CY_SYSPM_PMIC_POLARITY_LOW as it is not supported by hardware.
*/
typedef enum
{
    CY_SYSPM_PMIC_POLARITY_LOW   = 0U,    /**< Set active low logic level for the PMIC input. */
    CY_SYSPM_PMIC_POLARITY_HIGH  = 1U     /**< Set active high logic level for the PMIC input. */
} cy_en_syspm_pmic_wakeup_polarity_t;

/** This enumeration selects Vbackup or Vddd to supply Vddbackup. */
typedef enum
{
    CY_SYSPM_VDDBACKUP_DEFAULT         = 0U,    /**< Logic automatically selects Vddd if present or
                                                     Vbackup if Vddd is not present to supply Vddbackup */
    CY_SYSPM_VDDBACKUP_VBACKUP         = 2U     /**< Sets only Vbackup to supply Vddbackup */
} cy_en_syspm_vddbackup_control_t;

/** This enumeration enables supercapacitor charging. */
typedef enum
{
    CY_SYSPM_SC_CHARGE_ENABLE     = 0x3CU,    /**< Enables supercapacitor charging */
    CY_SYSPM_SC_CHARGE_DISABLE    = 0x00U     /**< Disables supercapacitor charging */
} cy_en_syspm_sc_charge_key_t;

/** This enumeration configures the flash voltage bit for different system power modes. */
typedef enum
{
    CY_SYSPM_FLASH_VOLTAGE_BIT_LP  = 0U,    /**< Set the flash voltage bit for system LP mode */
    CY_SYSPM_FLASH_VOLTAGE_BIT_ULP = 1U,    /**< Set the flash voltage bit for system ULP mode */
} cy_en_syspm_flash_voltage_bit_t;

/**
* This enumeration is used to select the low power mode for which the
* appropriate registered callback handler will be executed. For example,
* the registered callback of the type CY_SYSPM_SLEEP will be executed while
* switching into the Sleep power mode.
*/
typedef enum
{
    CY_SYSPM_SLEEP          = 0U,    /**< The Sleep enum callback type */
    CY_SYSPM_DEEPSLEEP      = 1U,    /**< The Deep Sleep enum callback type */
    CY_SYSPM_HIBERNATE      = 2U,    /**< The Hibernate enum callback type */
#if (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION < 2)) || defined (CY_IP_MXS22SRSS) || (defined (CY_IP_MXS40SSRSS) && (CY_MXS40SSRSS_VER_1_2 > 0UL)) ||defined (CY_DOXYGEN)
    CY_SYSPM_LP             = 3U,    /**< The Low Power enum callback type */
    CY_SYSPM_ULP            = 4U,     /**< The Ultra Low Power enum callback type */
#endif
#if defined (CY_IP_MXS40SSRSS) || defined (CY_IP_MXS28SRSS) || (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION >= 2)) || defined (CY_IP_MXS22SRSS) || defined (CY_DOXYGEN)
    CY_SYSPM_LPACTIVE_ENTER = 3U,    /**< The LPACTIVE (Low Power Active)/LPSLEEP (Low Power Sleep) ENTER enum callback type */
    CY_SYSPM_LPACTIVE_EXIT  = 4U,    /**< The LPACTIVE  (Low Power Active)/LPSLEEP (Low Power Sleep) EXIT enum callback type */
#endif
#if defined (CY_IP_MXS40SSRSS) || defined (CY_IP_MXS28SRSS) || defined (CY_IP_MXS22SRSS) || defined (CY_DOXYGEN)
    CY_SYSPM_DEEPSLEEP_RAM  = 5U,    /**< The Deep Sleep RAM enum callback type */
    CY_SYSPM_DEEPSLEEP_OFF  = 6U,    /**< The Deep Sleep OFF enum callback type */
#endif
#if defined (CY_IP_MXS40SSRSS) && (CY_MXS40SSRSS_VER_1_2 > 0UL)
    CY_SYSPM_MF             = 7U,     /**< The Medium Frequency mode enum callback type */
#endif

#if defined (CY_IP_MXS40SSRSS) && (CY_MXS40SSRSS_VER_1_2 > 0UL)
    CY_SYSPM_OD             = 8U,     /**< The Over drive Frequency enum callback type */
#endif
#if defined (CY_IP_MXS22SRSS) && (CY_IP_MXS22SRSS_VERSION == 2) && (CY_IP_MXS22SRSS_VERSION_MINOR >= 1)
    CY_SYSPM_HIBERNATE_RAM   = 9U,     /**< The Hibernate ram callback type */
#endif
    CY_SYSPM_MAX_CALLBACK_INDEX_PLUS_1
} cy_en_syspm_callback_type_t;

#if defined (CY_IP_MXS40SSRSS) || defined (CY_IP_MXS28SRSS) || defined (CY_IP_MXS22SRSS) || defined (CY_DOXYGEN)
/**
* This enumeration is used to list the available deep sleep modes.
*/
typedef enum
{
    CY_SYSPM_MODE_DEEPSLEEP        = CY_SYSPM_DEEPSLEEP,        /**< Deep Sleep Mode. */
    CY_SYSPM_MODE_DEEPSLEEP_RAM    = CY_SYSPM_DEEPSLEEP_RAM,    /**< Deep Sleep RAM Mode. */
    CY_SYSPM_MODE_DEEPSLEEP_OFF    = CY_SYSPM_DEEPSLEEP_OFF,    /**< Deep Sleep OFF Mode. */
    CY_SYSPM_MODE_DEEPSLEEP_NONE   = CY_SYSPM_SLEEP,                     /**< Not Deep Sleep Mode. */
} cy_en_syspm_deep_sleep_mode_t;

/**
* This enumeration is used to list the available wakeup modes after deepsleep.
*/
typedef enum
{
    CY_SYSPM_WARM_BOOT_MODE      = 0,    /**< Warm Boot - After DEEPSLEEP-RAM. */
    CY_SYSPM_COLD_BOOT_MODE      = 1,    /**< Cold Boot - After DEEPSLEEP-OFF. */
    CY_SYSPM_POR_BOOT_MODE       = 2,    /**< POR Boot  - After POR Wakeup. */
} cy_en_syspm_boot_mode_t;

/**
* This enumeration is used to select the mode for the
* Core Buck regulator.
*/
typedef enum
{
    CY_SYSPM_CORE_BUCK_MODE_LP    = 0x01U,    /**< Low Power Mode. */
    CY_SYSPM_CORE_BUCK_MODE_HP    = 0x11U,    /**< High Performance mode(Low Ripple Mode) */
} cy_en_syspm_core_buck_mode_t;

#if defined (CY_IP_MXS40SSRSS) || defined (CY_DOXYGEN)
/**
* This enumeration is used to select the Inrush limit for the
* Core Buck regulator.
*/
typedef enum
{
    CY_SYSPM_CORE_BUCK_INRUSH_LIMIT_10    = 0U,    /**< Inrush limit : 10mA. */
    CY_SYSPM_CORE_BUCK_INRUSH_LIMIT_100   = 1U,    /**< Inrush limit : 100mA. */
} cy_en_syspm_core_inrush_limit_t;

typedef enum
{
    CY_SYSPM_CORE_BUCK_VOLTAGE_0_76V = 0U,    /**< 0.76 V nominal voltage. */
    CY_SYSPM_CORE_BUCK_VOLTAGE_0_78V = 1U,    /**< 0.78 V nominal voltage. */
    CY_SYSPM_CORE_BUCK_VOLTAGE_0_80V = 2U,    /**< 0.80 V nominal voltage. */
    CY_SYSPM_CORE_BUCK_VOLTAGE_0_82V = 3U,    /**< 0.82 V nominal voltage. */
    CY_SYSPM_CORE_BUCK_VOLTAGE_0_84V = 4U,    /**< 0.84 V nominal voltage. */
    CY_SYSPM_CORE_BUCK_VOLTAGE_0_86V = 5U,    /**< 0.86 V nominal voltage. */
    CY_SYSPM_CORE_BUCK_VOLTAGE_0_88V = 6U,    /**< 0.88 V nominal voltage. */
    CY_SYSPM_CORE_BUCK_VOLTAGE_0_90V = 7U,    /**< 0.90 V nominal voltage. */
    CY_SYSPM_CORE_BUCK_VOLTAGE_0_92V = 8U,    /**< 0.92 V nominal voltage. */
    CY_SYSPM_CORE_BUCK_VOLTAGE_0_94V = 9U,    /**< 0.94 V nominal voltage. */
    CY_SYSPM_CORE_BUCK_VOLTAGE_0_96V = 10U,    /**< 0.96 V nominal voltage. */
    CY_SYSPM_CORE_BUCK_VOLTAGE_0_98V = 11U,    /**< 0.98 V nominal voltage. */
    CY_SYSPM_CORE_BUCK_VOLTAGE_1_00V = 12U,    /**< 1.00 V nominal voltage. */
    CY_SYSPM_CORE_BUCK_VOLTAGE_1_02V = 13U,    /**< 1.02 V nominal voltage. */
    CY_SYSPM_CORE_BUCK_VOLTAGE_1_04V = 14U,    /**< 1.04 V nominal voltage. */
    CY_SYSPM_CORE_BUCK_VOLTAGE_1_06V = 15U,    /**< 1.06 V nominal voltage. */
    CY_SYSPM_CORE_BUCK_VOLTAGE_1_08V = 16U,    /**< 1.08 V nominal voltage. */
    CY_SYSPM_CORE_BUCK_VOLTAGE_1_10V = 17U,    /**< 1.10 V nominal voltage. */
    CY_SYSPM_CORE_BUCK_VOLTAGE_1_12V = 18U,    /**< 1.12 V nominal voltage. */
    CY_SYSPM_CORE_BUCK_VOLTAGE_1_14V = 19U,    /**< 1.14 V nominal voltage. */
    CY_SYSPM_CORE_BUCK_VOLTAGE_1_16V = 20U,    /**< 1.16 V nominal voltage. */
    CY_SYSPM_CORE_BUCK_VOLTAGE_1_18V = 21U,    /**< 1.18 V nominal voltage. */
    CY_SYSPM_CORE_BUCK_VOLTAGE_1_20V = 22U,    /**< 1.20 V nominal voltage. */
    CY_SYSPM_CORE_BUCK_VOLTAGE_1_22V = 23U,    /**< 1.22 V nominal voltage. */
    CY_SYSPM_CORE_BUCK_VOLTAGE_1_24V = 24U,    /**< 1.24 V nominal voltage. */
    CY_SYSPM_CORE_BUCK_VOLTAGE_1_26V = 25U,    /**< 1.26 V nominal voltage. */
    CY_SYSPM_CORE_BUCK_VOLTAGE_1_28V = 26U,    /**< 1.28 V nominal voltage. */
    CY_SYSPM_CORE_BUCK_VOLTAGE_1_30V = 27U,    /**< 1.30 V nominal voltage. */
    CY_SYSPM_CORE_BUCK_VOLTAGE_1_32V = 28U,    /**< 1.32 V nominal voltage. */
    CY_SYSPM_CORE_BUCK_VOLTAGE_1_34V = 29U,    /**< 1.34 V nominal voltage. */
    CY_SYSPM_CORE_BUCK_VOLTAGE_1_36V = 30U,    /**< 1.36 V nominal voltage. */
    CY_SYSPM_CORE_BUCK_VOLTAGE_1_38V = 31U,    /**< 1.38 V nominal voltage. */
} cy_en_syspm_core_buck_voltage_t;
#endif /* defined (CY_IP_MXS40SSRSS) || defined (CY_DOXYGEN) */



#if defined (CY_IP_MXS40SSRSS)
/**
* \note
* This enum is available for PSC devices.
**/
/**
* For SDR's(Step Down Regulators), this enumeration is used to select the SDR0 or SDR1
*/
typedef enum
{
    CY_SYSPM_SDR_0              = 0U,    /**< SDR0 */
    CY_SYSPM_SDR_1              = 1U,    /**< SDR1 */
} cy_en_syspm_sdr_t;

/**
* This enumeration is used to select the output voltage for the
* SDR(Step Down Regulator) output.
*/
typedef enum
{
    CY_SYSPM_SDR_VOLTAGE_0_850V = 0U,    /**< 0.850 V nominal voltage. */
    CY_SYSPM_SDR_VOLTAGE_0_875V = 1U,    /**< 0.875 V nominal voltage. */
    CY_SYSPM_SDR_VOLTAGE_0_900V = 2U,    /**< 0.900 V nominal voltage. */
    CY_SYSPM_SDR_VOLTAGE_0_925V = 3U,    /**< 0.925 V nominal voltage. */
    CY_SYSPM_SDR_VOLTAGE_0_950V = 4U,    /**< 0.950 V nominal voltage. */
    CY_SYSPM_SDR_VOLTAGE_0_975V = 5U,    /**< 0.975 V nominal voltage. */
    CY_SYSPM_SDR_VOLTAGE_1_000V = 6U,    /**< 1.000 V nominal voltage. */
    CY_SYSPM_SDR_VOLTAGE_1_025V = 7U,    /**< 1.025 V nominal voltage. */
    CY_SYSPM_SDR_VOLTAGE_1_050V = 8U,    /**< 1.050 V nominal voltage. */
    CY_SYSPM_SDR_VOLTAGE_1_075V = 9U,    /**< 1.075 V nominal voltage. */
    CY_SYSPM_SDR_VOLTAGE_1_100V = 10U,   /**< 1.100 V nominal voltage. */
    CY_SYSPM_SDR_VOLTAGE_1_125V = 11U,   /**< 1.125 V nominal voltage. */
    CY_SYSPM_SDR_VOLTAGE_1_150V = 12U,   /**< 1.150 V nominal voltage. */
    CY_SYSPM_SDR_VOLTAGE_1_175V = 13U,   /**< 1.175 V nominal voltage. */
    CY_SYSPM_SDR_VOLTAGE_1_200V = 14U,   /**< 1.200 V nominal voltage. */
    CY_SYSPM_SDR_VOLTAGE_1_225V = 15U,   /**< 1.225 V nominal voltage. */
} cy_en_syspm_sdr_voltage_t;

/**
* This enumeration is used to select the output voltage for the
* HVLDO Regulator.
*/
typedef enum
{
    CY_SYSPM_HVLDO_VOLTAGE_1_800V = 0U,     /**< 1.800 V nominal voltage. */
    CY_SYSPM_HVLDO_VOLTAGE_1_900V = 1U,     /**< 1.900 V nominal voltage. */
    CY_SYSPM_HVLDO_VOLTAGE_2_000V = 2U,     /**< 2.000 V nominal voltage. */
    CY_SYSPM_HVLDO_VOLTAGE_2_100V = 3U,     /**< 2.100 V nominal voltage. */
    CY_SYSPM_HVLDO_VOLTAGE_2_200V = 4U,     /**< 2.200 V nominal voltage. */
    CY_SYSPM_HVLDO_VOLTAGE_2_300V = 5U,     /**< 2.300 V nominal voltage. */
    CY_SYSPM_HVLDO_VOLTAGE_2_400V = 6U,     /**< 2.400 V nominal voltage. */
    CY_SYSPM_HVLDO_VOLTAGE_2_500V = 7U,     /**< 2.500 V nominal voltage. */
    CY_SYSPM_HVLDO_VOLTAGE_2_600V = 8U,     /**< 2.600 V nominal voltage. */
    CY_SYSPM_HVLDO_VOLTAGE_2_700V = 9U,     /**< 2.700 V nominal voltage. */
    CY_SYSPM_HVLDO_VOLTAGE_2_800V = 10U,    /**< 2.800 V nominal voltage. */
    CY_SYSPM_HVLDO_VOLTAGE_2_900V = 11U,    /**< 2.900 V nominal voltage. */
    CY_SYSPM_HVLDO_VOLTAGE_3_000V = 12U,    /**< 3.000 V nominal voltage. */
    CY_SYSPM_HVLDO_VOLTAGE_3_100V = 13U,    /**< 3.100 V nominal voltage. */
    CY_SYSPM_HVLDO_VOLTAGE_3_200V = 14U,    /**< 3.200 V nominal voltage. */
    CY_SYSPM_HVLDO_VOLTAGE_3_300V = 15U,    /**< 3.300 V nominal voltage. */
} cy_en_syspm_hvldo_voltage_t;
#endif /* defined (CY_IP_MXS40SSRSS)  */

#endif



/**
* For SRAM0, this enumeration represents the Macro Numbers
*/
typedef enum
{
    CY_SYSPM_SRAM0_MACRO_0              = 0U,    /**< SRAM0:Macro-0 */
    CY_SYSPM_SRAM0_MACRO_1              = 1U,    /**< SRAM0:Macro-1 */
    CY_SYSPM_SRAM0_MACRO_2              = 2U,    /**< SRAM0:Macro-2 */
    CY_SYSPM_SRAM0_MACRO_3              = 3U,    /**< SRAM0:Macro-3 */
    CY_SYSPM_SRAM0_MACRO_4              = 4U,    /**< SRAM0:Macro-4 */
    CY_SYSPM_SRAM0_MACRO_5              = 5U,    /**< SRAM0:Macro-5 */
    CY_SYSPM_SRAM0_MACRO_6              = 6U,    /**< SRAM0:Macro-6 */
    CY_SYSPM_SRAM0_MACRO_7              = 7U,    /**< SRAM0:Macro-7 */
} cy_en_syspm_sram0_macro_t;



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
    CY_SYSPM_AFTER_TRANSITION         = 0x08U,     /**< Performs the actions to be done after exiting the low power mode
                                                 if entered. */
#if defined (CY_IP_MXS40SSRSS)
    /**
     * \note
     * Below enum should be used only during exit of Deepsleep
     **/
    CY_SYSPM_AFTER_DS_WFI_TRANSITION  = 0x10U,    /**< Performs the actions to be done after exiting the Deepsleep low
                                                     power mode if entered and before the interrupts are enabled. */
#endif
} cy_en_syspm_callback_mode_t;

/**
* This enumeration is used to select a particular SRAM.
*/
typedef enum
{
    CY_SYSPM_SRAM0_MEMORY      = 0U,    /**< SRAM0 Memory Area */
    CY_SYSPM_SRAM1_MEMORY      = 1U,    /**< SRAM1 Memory Area */
    CY_SYSPM_SRAM2_MEMORY      = 2U,    /**< SRAM2 Memory Area */
} cy_en_syspm_sram_index_t;

/**
* This enumeration is used to select a particular SRAM Power Mode.
*/
typedef enum
{
    CY_SYSPM_SRAM_PWR_MODE_OFF      = 0U,   /**< SRAM Power Mode OFF */
    CY_SYSPM_SRAM_PWR_MODE_INVALID  = 1U,   /**< Invalid SRAM Power Mode */
    CY_SYSPM_SRAM_PWR_MODE_ON       = 3U    /**< SRAM Power Mode ON */
} cy_en_syspm_sram_pwr_mode_t;


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

/** The type for syspm callbacks */
typedef cy_en_syspm_status_t (*Cy_SysPmCallback) (cy_stc_syspm_callback_params_t *callbackParams, cy_en_syspm_callback_mode_t mode);

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


#if (defined(CY_DEVICE_SECURE))
/** PRA structure for Cy_SysPm_BuckSetVoltage2 function parameters */
typedef struct
{
    cy_en_syspm_buck_voltage2_t praVoltage;     /**< The voltage of the Buck regulator output 2 */
    bool praWaitToSettle;                       /**< Enable/disable the delay after setting a higher voltage */
} cy_stc_pra_voltage2_t;

typedef struct
{
    cy_en_syspm_sram_index_t sramNum;           /**< SRAM index */
    uint32_t sramMacroNum;                      /**< SRAM macro number */
    cy_en_syspm_sram_pwr_mode_t sramPwrMode;    /**< Power mode */
} cy_stc_pra_sram_power_mode_config_t;

#endif /* (defined(CY_DEVICE_SECURE)) */


#if defined (CY_IP_MXS40SSRSS) || defined (CY_IP_MXS22SRSS) || defined (CY_DOXYGEN)
/** The structure contains warmboot entry point struct used during DEEPSLEEP-RAM entry*/
typedef struct
{
    uint32_t *stack_pointer;      /**< Stack Pointer */
    uint32_t *entry_pointer;      /**< Entry Function Address */
} cy_stc_syspm_warmboot_entrypoint_t;

/** The structure contains warmboot CPU context information used during DEEPSLEEP-RAM entry/exit */
typedef struct {
    uint32_t r[13];     /**< R0-R12 register content */
    uint32_t lr;        /**< LR register content */
    uint32_t exit;      /**< DS Exit address */
    uint32_t msp;       /**< Main stack pointer */
    uint32_t wfiStatus; /**< WFI entry/exit status */
} cy_stc_syspm_warmboot_context_t;

/**
* \note
* This structure is available for PSC devices.
**/
/** The structure contains syspm core buck configuration parameters */
typedef struct
{
    uint8_t   voltageSel;      /**< Core Buck Voltage Select \ref cy_en_syspm_core_buck_voltage_t */
    uint8_t   mode;            /**< Core Buck Mode :
                                    0x01 - Low Power Mode,
                                    0x11 - High Performance mode(Low Ripple Mode) */
    bool      override;        /**< Core Buck Override : Forces Corebuck to
                                    use the setting in the PWR_CBUCK_CTL register */
    bool      copySettings;    /**< Core Buck Copy Settings :
                                    Copies the current CBUCK composite state to
                                    PWR_CBUCK_CTL register */
    bool      useSettings;     /**< Core Buck use Settings :
                                    Causes the settings in PWR_CBUCK_CTL to be
                                    used in CBUCK settings decision */
    uint8_t   inRushLimitSel;  /**< Core Buck In Rush Limit Selection
                                    0: 10mA  limit
                                    1: 100mA limit */
} cy_stc_syspm_core_buck_params_t;

/** The structure contains syspm SDR0/SDR1(Step Down Regulator) LDO configuration parameters */
typedef struct
{
    uint8_t   coreBuckVoltSel;     /**< Core Buck Voltage Select \ref cy_en_syspm_core_buck_voltage_t */
    uint8_t   coreBuckMode;        /**< Core Buck Mode :
                                    0x01 - Low Power Mode,
                                    0x11 - High Performance mode(Low Ripple Mode) */

    /* This field applicable only for SDR0 */
    uint8_t   coreBuckDpSlpVoltSel; /**< Deep Sleep Core Buck Voltage Select \ref cy_en_syspm_core_buck_voltage_t */

    /* This field applicable only for SDR0 */
    uint8_t   coreBuckDpSlpMode;    /**< Deep sleep Core Buck Mode :
                                     0x01 - Low Power Mode,
                                     0x11 - High Performance mode(Low Ripple Mode) */

    uint8_t   sdrVoltSel;           /**< SDR Regulator Voltage Select \ref cy_en_syspm_sdr_voltage_t */

    /* This field applicable only for SDR0 */
    uint8_t   sdr0DpSlpVoltSel;     /**< SDR Regulator Voltage Select \ref cy_en_syspm_sdr_voltage_t */

    /* This field applicable only for SDR0 */
    bool      sdr0Allowbypass;      /**< Allow SDR bypass :
                                     true  - Allow SDR to bypass
                                     false - SDR is not bypassed and will regulate */
    /* This field applicable only for SDR1 */
    bool      sdr1HwControl;        /**< Allow SDR1 HW Control :
                                     true  - sdr1Enable(bit: SDR1_ENABLE) is ignored, HW will control
                                     false - sdr1Enable(bit: SDR1_ENABLE) will control, HW control is ignored */
    /* This field applicable only for SDR1 */
    bool      sdr1Enable;           /**<  SDR1 Enable/Disable:
                                     true  - SDR1 is enabled
                                     false - SDR1 is disabled */
} cy_stc_syspm_sdr_params_t;

/** The structure contains syspm HVLDO configuration parameters */
typedef struct
{
    uint8_t   voltageSel;      /**< HVLDO Voltage Select \ref cy_en_syspm_hvldo_voltage_t */
    bool      hwSel;           /**< HVLDO HW Select :
                                    0 - HVLDO0_ENABLE controls SDR1,HW controls are ignored
                                    1 - HVLDO0_ENABLE is ignored and HW signal is used instead */
    bool      hvldoEnable;     /**< HVLDO Enable/Disable:
                                    true - HVLDO is enabled
                                    false - HVLDO is disabled */
} cy_stc_syspm_hvldo_params_t;


/** The structure contains syspm Extra Requestor configuration parameters */
typedef struct
{
    uint8_t   coreBuckVoltSel; /**< Core Buck Voltage Select \ref cy_en_syspm_core_buck_voltage_t */
    uint8_t   coreBuckMode;    /**< Core Buck Mode :
                                    0x00 - Low Power Mode,
                                    0x10 - Low Ripple(high power) */
    cy_stc_syspm_sdr_params_t *sdr0Config; /**< SDR-0 Parameters \ref cy_stc_syspm_sdr_params_t */
    cy_stc_syspm_sdr_params_t *sdr1Config; /**< SDR-1 Parameters \ref cy_stc_syspm_sdr_params_t */
} cy_stc_syspm_extraReq_params_t;

#endif

/** \cond INTERNAL */
#if defined (CY_IP_MXS40PPSS) && !defined (COMPONENT_PPCA_DEVICE) || defined (CY_DOXYGEN)

/**
* \note
* This structure is available for PSC devices.
**/
/** Describes the PPCA CPU Core images */
typedef struct
{
    void     *flash_address0;      /**< Flash address of PPCA core 0 */
    void     *flash_address1;    /**< Flash address of PPCA core 1 */
    uint32_t image_size0;         /**< Image size of PPCA core 0 */
    uint32_t image_size1;          /**< Image size of PPCA core 1 */
} cy_stc_syspm_ppca_images_t;

#endif /* defined (CY_IP_MXS40PPSS) && !defined (COMPONENT_PPCA_DEVICE) */

#if defined(CY_IP_MXCM55) && defined(CY_PDL_SYSPM_ENABLE_SRF_INTEG)
/** This is only used by secure-aware. The structure contains enable CM55 configuration parameters */
typedef struct {
    uint32_t vectorTableOffset;
    cy_app_cpu_dbg_port_type_t dbgMode;
    uint32_t waitus;
} cy_pdl_syspm_srf_syscm55enable_in_t;


/** This is only used by secure-aware. The structure contains reset CM55 configuration parameters */
typedef struct {
    uint32_t waitus;
} cy_pdl_syspm_srf_syscm55reset_in_t;

#endif /* defined(CY_IP_MXCM55) && defined(CY_PDL_SYSPM_ENABLE_SRF_INTEG) */
/** \endcond */
/** \} group_syspm_data_structures */

/**
* \addtogroup group_syspm_functions
* \{
*/


/**
* \addtogroup group_syspm_functions_ppca
* \{
*/

#if defined (CY_IP_MXS40PPSS) && !defined (COMPONENT_PPCA_DEVICE) || defined (CY_DOXYGEN)

/*******************************************************************************
* Function Name: Cy_SysPm_PPCA_ClearDeepSleepInterrupt
****************************************************************************//**
*
* Clear the PPCA deep-sleep ready interrupt
*
*******************************************************************************/
void Cy_SysPm_PPCA_ClearDeepSleepInterrupt(void);

/*******************************************************************************
* Function Name: Cy_SysPm_PPCA_IsDeepSleepReady
****************************************************************************//**
*
* Check if PPCA is ready for deep-sleep entry
*
* \return
* PPCA ready(1) or not ready(0)
*
*******************************************************************************/
bool Cy_SysPm_PPCA_IsDeepSleepReady(void);

/*******************************************************************************
* Function Name: Cy_SysPm_PPCA_RequestDeepSleep
****************************************************************************//**
*
* Request the PPCA cores to enter deep-sleep.
*
* \param coreImages
* Flash image location and size for the PPCA core applications
*
* \return
* - CY_SYSPM_SUCCESS - Request was successful
* - CY_SYSPM_INVALID_STATE - At least one PPCA CPU should be enabled
* - CY_SYSPM_BAD_PARAM - Input parameter should define at least one image
*
*******************************************************************************/
cy_en_syspm_status_t Cy_SysPm_PPCA_RequestDeepSleep(cy_stc_syspm_ppca_images_t *coreImages);

#endif /* defined (CY_IP_MXS40PPSS) && !defined (COMPONENT_PPCA_DEVICE) || defined (CY_DOXYGEN) */
/** \} group_syspm_functions_ppca */

/**
* \addtogroup group_syspm_functions_general
* \{
*/

/*******************************************************************************
* Function Name: Cy_SysPm_SetSRAMMacroPwrMode
****************************************************************************//**
*
* Function to set Power Mode for each of the Macro in a particular SRAM.
*
* \param sramNum
* SRAM's index number has to be passed
* ex: CY_SYSPM_SRAM0_MEMORY or CY_SYSPM_SRAM1_MEMORY or CY_SYSPM_SRAM2_MEMORY
* See \ref cy_en_syspm_sram_index_t.
*
* \param sramMacroNum
* Macro number of a particular SRAM.
*
* \note
* If SRAM1 and SRAM2 consists of single power partition, power mode will be
* applied to whole SRAM region, so 0 must be passed for sramMacroNum parameter.
*
* \param sramPwrMode
* Power Mode that needs to be set.
*
* \return
* - CY_SYSPM_SUCCESS - SRAM MACRO power mode is set.
* - CY_SYSPM_BAD_PARAM - Input parameters are out of range.
* See \ref cy_en_syspm_status_t.
*
*
*
*******************************************************************************/
cy_en_syspm_status_t Cy_SysPm_SetSRAMMacroPwrMode(cy_en_syspm_sram_index_t sramNum, uint32_t sramMacroNum, cy_en_syspm_sram_pwr_mode_t sramPwrMode);

/*******************************************************************************
* Function Name: Cy_SysPm_GetSRAMMacroPwrMode
****************************************************************************//**
*
* Function to get Power Mode for each of the Macro in a particular SRAM.
*
* \param sramNum
* SRAM's index number has to be passed
* ex: CY_SYSPM_SRAM0_MEMORY or CY_SYSPM_SRAM1_MEMORY or CY_SYSPM_SRAM2_MEMORY
* See \ref cy_en_syspm_sram_index_t.
*
* \param sramMacroNum
* Macro number of a particular SRAM.
*
* \note
* If SRAM1 and SRAM2 consists of single power partition, power mode will be
* applied to whole SRAM region, so 0 must be passed for sramMacroNum parameter,
* and the power mode obtained will be for whole SRAM.
*
* \return
* Returns SRAM power mode. See \ref cy_en_syspm_sram_pwr_mode_t.
*
*******************************************************************************/
cy_en_syspm_sram_pwr_mode_t Cy_SysPm_GetSRAMMacroPwrMode(cy_en_syspm_sram_index_t sramNum, uint32_t sramMacroNum);

/*******************************************************************************
* Function Name: Cy_SysPm_SetSRAMPwrMode
****************************************************************************//**
*
* Function to set Power Mode for all the Macros for a particular SRAM.
*
* \param sramNum
* SRAM's index number has to be passed
* ex: CY_SYSPM_SRAM0_MEMORY or CY_SYSPM_SRAM1_MEMORY or CY_SYSPM_SRAM2_MEMORY
* See \ref cy_en_syspm_sram_index_t.
*
* \param sramPwrMode
* Power Mode that needs to be set.
*
* \return
* - CY_SYSPM_SUCCESS - SRAM power mode is set.
* - CY_SYSPM_BAD_PARAM - Input parameters are out of range.
* See \ref cy_en_syspm_status_t.
*
*
*******************************************************************************/
cy_en_syspm_status_t Cy_SysPm_SetSRAMPwrMode(cy_en_syspm_sram_index_t sramNum, cy_en_syspm_sram_pwr_mode_t sramPwrMode);



/** \} group_syspm_functions_general */


/**
* \addtogroup group_syspm_functions_power_status
* \{
*/

#if defined (CY_IP_MXS40SRSS) || defined (CY_IP_MXS22SRSS) || (defined (CY_IP_MXS40SSRSS) && (CY_MXS40SSRSS_VER_1_2 > 0UL)) || defined (CY_DOXYGEN)
/*******************************************************************************
* Function Name: Cy_SysPm_ReadStatus
****************************************************************************//**
*
* Reads the power modes status of the system and CPU(s).
*
* \return
* The current power mode. See \ref group_syspm_return_status.
*
* \funcusage
* \snippet syspm/snippet/main.c snippet_Cy_SysPm_ReadStatus
*
*******************************************************************************/
uint32_t Cy_SysPm_ReadStatus(void);
#endif
/** \} group_syspm_functions_power_status */

/**
* \addtogroup group_syspm_functions_power
* \{
*/


/*******************************************************************************
* Function Name: Cy_SysPm_DeepSleepSetup
****************************************************************************//**
*
* Sets the startup deepsleep mode of \ref cy_DeepSleepMode variable.
*
* \param deepSleepMode
* CY_SYSPM_MODE_DEEPSLEEP or CY_SYSPM_MODE_DEEPSLEEP_RAM or CY_SYSPM_MODE_DEEPSLEEP_OFF
*
* \note This API does not take into account any run-time deepsleep mode updates.
* Should any updates occur, \ref Cy_SysPm_DeepSleepUpdate must be called afterwards
* on the CM33_NS and CM55.
*
*******************************************************************************/
void Cy_SysPm_DeepSleepSetup(cy_en_syspm_deep_sleep_mode_t deepSleepMode);

/*******************************************************************************
* Function Name: Cy_SysPm_DeepSleepUpdate
****************************************************************************//**
*
* Gets deepsleep mode and updates \ref cy_DeepSleepMode variable.
*
* Updates global variables used by the \ref Cy_SysPm_CpuEnterDeepSleep().
*
*******************************************************************************/
void Cy_SysPm_DeepSleepUpdate (void);


/*******************************************************************************
* Function Name: Cy_SysPm_CpuEnterSleep
****************************************************************************//**
*
* Sets executing CPU to Sleep mode.
*
* Puts the CPU executing this function into CPU Sleep power mode. If callback
* functions were registered they are also executed.
*
* For more detail about switching into CPU Sleep power mode and debug,
* refer to the device technical reference manual (TRM).
*
* If at least one callback function with the CY_SYSPM_SLEEP type was registered,
* the following algorithm is executed:
* Prior to entering CPU Sleep mode, all callback functions of the CY_SYSPM_SLEEP
* type with the CY_SYSPM_CHECK_READY parameter are called. This allows the
* driver to signal whether it is ready to enter the low power mode. If any of
* the callbacks of the CY_SYSPM_SLEEP type with the CY_SYSPM_CHECK_READY
* parameter returns CY_SYSPM_FAIL, the remaining callbacks of the
* CY_SYSPM_SLEEP type with the CY_SYSPM_CHECK_READY parameter are skipped.
* After the first CY_SYSPM_FAIL, all the CY_SYSPM_SLEEP callbacks that were
* previously executed before getting the CY_SYSPM_CHECK_FAIL are executed with
* the CY_SYSPM_CHECK_FAIL parameter. The CPU Sleep mode is not entered and the
* Cy_SysPm_CpuEnterSleep() function returns CY_SYSPM_FAIL.
*
* If all of the callbacks of the CY_SYSPM_SLEEP type with the
* CY_SYSPM_CHECK_READY parameter return CY_SYSPM_SUCCESS, then all
* callbacks of the CY_SYSPM_SLEEP type with the CY_SYSPM_CHECK_FAIL parameters
* calls are skipped. All callbacks of the CY_SYSPM_SLEEP type and then
* CY_SYSPM_BEFORE_TRANSITION parameter calls are executed, allowing the
* peripherals to prepare for CPU Sleep. The CPU then enters Sleep mode.
* This is a CPU-centric power mode. This means that the CPU has entered Sleep
* mode and its main clock is removed. Any enabled interrupt can cause a CPU
* wakeup from Sleep mode.
*
* For multi-core devices, CPU wakeup can also be performed using the Send Event
* (SEV) assembly instruction executed from the other active CPU. Such wakeup is
* expected only if the CPU Sleep power mode is done with WFE assembly
* instruction.
*
* After a wakeup from CPU Sleep, all of the registered callbacks of the
* CY_SYSPM_SLEEP type and with the CY_SYSPM_AFTER_TRANSITION parameter are
* executed to return the peripherals to CPU active operation.
* The Cy_SysPm_CpuEnterSleep() function returns CY_SYSPM_SUCCESS.
* No callbacks of the CY_SYSPM_SLEEP type with the CY_SYSPM_BEFORE_TRANSITION
* parameter or callbacks of the CY_SYSPM_SLEEP type and
* CY_SYSPM_AFTER_TRANSITION parameter callbacks are executed if CPU Sleep mode
* is not entered.
*
* \note The last callback that returns CY_SYSPM_FAIL is not executed with the
* CY_SYSPM_CHECK_FAIL parameter because of the FAIL. The callback generating
* CY_SYSPM_FAIL is expected to not make any changes that require being undone.
*
* To support control of callback execution order the following method is
* implemented. Callback function with the CY_SYSPM_CHECK_READY and
* CY_SYSPM_BEFORE_TRANSITION parameter are executed in the same order they are
* registered. Callback function with the CY_SYSPM_CHECK_FAIL and
* CY_SYSPM_AFTER_TRANSITION parameter are executed in the reverse order they
* are registered.

* The return value from executed callback functions with the
* CY_SYSPM_CHECK_FAIL, CY_SYSPM_BEFORE_TRANSITION, and CY_SYSPM_AFTER_TRANSITION
* modes are ignored.
*
* \ref cy_en_syspm_callback_mode_t, except the CY_SYSPM_CHECK_READY, are ignored
*
* \note The Arm BSD assembly instruction is not required in this function
* because the function implementation ensures the SLEEPDEEP bit of SCS register
* is settled prior executing WFI/WFE instruction.
*
* \note This API is secure aware but when running on the core without TrustZone,
* there will be no special security-related behavior. See header subsection Secure
* Aware SYSPM for further details.
*
* \param waitFor
* Selects wait for action. See \ref cy_en_syspm_waitfor_t.
*
* \return
* Entered status, see \ref cy_en_syspm_status_t.
*
* \sideeffect
* For CY8C6xx6, CY8C6xx7 devices this function clears the Event Register of the
* CM4 CPU after wakeup from WFE.
*
* \funcusage
* \snippet syspm/snippet/main.c snippet_Cy_SysPm_CpuEnterSleep
*
*******************************************************************************/
cy_en_syspm_status_t Cy_SysPm_CpuEnterSleep(cy_en_syspm_waitfor_t waitFor);

#if defined (CY_IP_MXS40SSRSS) || defined (CY_IP_MXS22SRSS) || defined (CY_DOXYGEN)

/*******************************************************************************
* Function Name: Cy_SysPm_Init
****************************************************************************//**
*
* Initializes SysPm Driver
*
*******************************************************************************/
void Cy_SysPm_Init(void);
#endif

#if defined (CY_IP_MXS40SSRSS) || (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION >= 2)) || defined (CY_IP_MXS22SRSS) || defined (CY_DOXYGEN)

/*******************************************************************************
* Function Name: Cy_SysPm_IsLpmReady
****************************************************************************//**
*
* Checks if the system is LPM ready.
*
* \note This API is secure aware. See header subsection Secure Aware SYSPM for further details.
* The involved PPC regions is PROT_PERI0_SRSS_MAIN.
*
* \return
* - True if the system is LPM Ready.
* - False if the system is not LPM Ready.
*
*******************************************************************************/
bool Cy_SysPm_IsLpmReady(void);
#endif  /* defined (CY_IP_MXS40SSRSS) || (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION >= 2)) || defined (CY_DOXYGEN) */

#if defined (CY_IP_MXS40SSRSS) || (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION >= 2)) || defined (CY_DOXYGEN)

/*******************************************************************************
* Function Name: Cy_SysPm_SystemLpActiveEnter
****************************************************************************//**
*
* Change the system from ACTIVE Profile to LPACTIVE (Low Power Active)/LPSLEEP
* (Low Power Sleep) Profile
*
* \return
* - CY_SYSPM_SUCCESS - Entered the system Low Power mode or
* the device is already in Low Power mode.
* - CY_SYSPM_INVALID_STATE - The system Low Power mode was not set. The
* system Low Power mode was not set because the protection context value is
* higher than zero
*   (PC > 0) or the device revision does not support modifying registers
*   (to enter LP mode) via syscall.
* - CY_SYSPM_CANCELED - Operation was canceled. Call the function again until
*   the function returns CY_SYSPM_SUCCESS.
* - CY_SYSPM_FAIL - The system Low Power mode is not entered.
*
*******************************************************************************/
cy_en_syspm_status_t Cy_SysPm_SystemLpActiveEnter(void);

/*******************************************************************************
* Function Name: Cy_SysPm_SystemLpActiveExit
****************************************************************************//**
*
* Changes the system from LPACTIVE (Low Power Active)/LPSLEEP (Low Power Sleep)
* Profile to ACTIVE Profile
*
* \return
* - CY_SYSPM_SUCCESS - Entered the system Low Power mode or
* the device is already in Low Power mode.
* - CY_SYSPM_INVALID_STATE - The system Low Power mode was not set. The
* system Low Power mode was not set because the protection context value is
* higher than zero
*   (PC > 0) or the device revision does not support modifying registers
*   (to enter LP mode) via syscall.
* - CY_SYSPM_CANCELED - Operation was canceled. Call the function again until
*   the function returns CY_SYSPM_SUCCESS.
* - CY_SYSPM_FAIL - The system Low Power mode is not entered.
*
*
*******************************************************************************/
cy_en_syspm_status_t Cy_SysPm_SystemLpActiveExit(void);

/*******************************************************************************
* Function Name: Cy_SysPm_IsSystemLpActiveEnabled
****************************************************************************//**
*
* Checks if the system is in LPACTIVE (Low Power Active)/LPSLEEP (Low Power Sleep)
* Profile
*
* \return
* True if enabled, False if disabled.
*
*******************************************************************************/
bool Cy_SysPm_IsSystemLpActiveEnabled(void);
#endif  /* defined (CY_IP_MXS40SSRSS) || (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION >= 2)) || defined (CY_DOXYGEN) */

/*******************************************************************************
* Function Name: Cy_SysPm_StoreDSContext_Wfi
****************************************************************************//**
*
* Allow users to implement any context store required before entering deep sleep
* in RTOS based builds, It is defined weak to allow callers override the default
* PDL implementation.
*
*******************************************************************************/

#if defined (CY_IP_MXS40SSRSS) || defined (CY_DOXYGEN)
void Cy_SysPm_StoreDSContext_Wfi(void);
#endif

#if defined (CY_IP_MXS40SSRSS) || defined (CY_IP_MXS22SRSS) || defined (CY_DOXYGEN)

/*******************************************************************************
* Function Name: Cy_SysPm_SetDeepSleepMode
****************************************************************************//**
*
* Set the deepsleep mode - deepsleep or deepsleep-ram or deepsleep-off
*
* \note
* If mode is set to CY_SYSPM_MODE_DEEPSLEEP_RAM && Application in Flash, user
* needs to take care of below
*
* Two types of images need to be generated
* 1. Flash image
*    - Contains the actual application.
*
* 2. RAM Image(Resides in RAM)
*    - Contains Warmboot Entry Point function.
*    - SMIF initialization is performed only during coldboot, and not in
*      warmboot, so RAM Image will have the code performing SMIF
*      initialization before jumping to Flash Image.
*
* Before entering CY_SYSPM_MODE_DEEPSLEEP_RAM, user need to take care of below
* 1. Entry point
*    - Set entry point to a function located in RAM Image using
*    - Cy_Syslib_SetWarmBootEntryPoint(Syslib Driver)
*
* After waking up from CY_SYSPM_MODE_DEEPSLEEP_RAM, bootrom jumps to
* entry point function located in RAM image code. Entry point function should
* take care of below
*
* 1. Vector table and Peripheral IP's enabling
*    - Set VTOR register with vector table address.
*    - Enable all the peripheral IP's using \ref Cy_SysClk_PeriGroupSetSlaveCtl.
* 2. SMIF Initialization
*    - Perform  SMIF Initialization.
* 3. Jump to API in the Flash.
*
* \param deepSleepMode
* CY_SYSPM_MODE_DEEPSLEEP or CY_SYSPM_MODE_DEEPSLEEP_RAM or CY_SYSPM_MODE_DEEPSLEEP_OFF
*
* \return
* - CY_SYSPM_SUCCESS - Deep sleep mode is set
* - CY_SYSPM_CANCELED - Operation was canceled. Call the function again until
*   the function returns CY_SYSPM_SUCCESS.
*
*******************************************************************************/
cy_en_syspm_status_t Cy_SysPm_SetDeepSleepMode(cy_en_syspm_deep_sleep_mode_t deepSleepMode);


/*******************************************************************************
* Function Name: Cy_SysPm_GetDeepSleepMode
****************************************************************************//**
*
* Get the overall system's deepsleep mode - deepsleep or deepsleep-ram or deepsleep-off
*
* \return
* Returns \ref cy_en_syspm_deep_sleep_mode_t
*
* \note
* In a multi-core/multi-power domain architectures, CY_SYSPM_MODE_DEEPSLEEP_NONE
* will be returned by the API, if any of the following conditions are met ...
*
* 1) Main Power domains(PD0, PD1) are not at all configured for a particular DS.
*
* 2) A mix in DS states between power domains, for example
* PD0 configures deepsleep and PD1 configures deepsleep-RAM.
*
* \note
* This API should only be used after Cy_SysPm_SetDeepSleepMode, as it will give only
* the mode that is set by Cy_SysPm_SetDeepSleepMode.
*
* \note This API is secure aware. See header subsection Secure Aware SYSPM for further details.
* The involved PPC regions is PROT_PERI0_PWRMODE_PWRMODE.
*
*******************************************************************************/
cy_en_syspm_deep_sleep_mode_t Cy_SysPm_GetDeepSleepMode(void);


#if defined (CY_IP_MXS22SRSS) && (CY_IP_MXS22SRSS_VERSION == 2) && (CY_IP_MXS22SRSS_VERSION_MINOR >= 1)
/*******************************************************************************
* Function Name: Cy_SysPm_SetHibernateRamMode
****************************************************************************//**
*
* Sets the Hibernate RAM mode. PPU settings are same as that of DeepSleep RAM
*
* \note
* If mode is set to Hibernate RAM && Application in Flash, user
* needs to take care of below
*
* Two types of images need to be generated
* 1. Flash image
*    - Contains the actual application.
*
* 2. RAM Image(Resides in RAM)
*    - Contains Warmboot Entry Point function.
*    - SMIF initialization is performed only during coldboot, and not in
*      warmboot, so RAM Image will have the code performing SMIF
*      initialization before jumping to Flash Image.
*
* Before entering Hibernate RAM, user need to take care of below
* 1. Entry point
*    - Set entry point to a function located in RAM Image using
*    - Cy_Syslib_SetWarmBootEntryPoint(Syslib Driver)
*
* After waking up from Hibernate RAM, bootrom jumps to
* entry point function located in RAM image code. Entry point function should
* take care of below
*
* 1. Vector table and Peripheral IP's enabling
*    - Set VTOR register with vector table address.
*    - Enable all the peripheral IP's using \ref Cy_SysClk_PeriGroupSetSlaveCtl.
* 2. SMIF Initialization
*    - Perform  SMIF Initialization.
* 3. Jump to API in the Flash.
*
* \return
* \ref cy_en_syspm_status_t
*
*******************************************************************************/
cy_en_syspm_status_t Cy_SysPm_SetHibernateRamMode(void);

#endif /* defined (CY_IP_MXS22SRSS) && (CY_IP_MXS22SRSS_VERSION == 2) && (CY_IP_MXS22SRSS_VERSION_MINOR >= 1)*/

/*******************************************************************************
* Function Name: Cy_SysPm_GetBootMode
****************************************************************************//**
*
* Checks from which Deep Sleep mode the system has woke up.
*
* \return
* Returns CY_SYSPM_WARM_BOOT_MODE or CY_SYSPM_WARM_COLD_MODE, if system performs
* warm or cold, else return CY_SYSPM_POR_BOOT_MODE if its a normal(POR) boot.
*
* \note
* Use this API immediately after the boot, before writing any of the PPU
* registers,because this API depends on the programmed state of the PPU
* registers, so call it before the PPU registers get overwritten.
*
*******************************************************************************/
cy_en_syspm_boot_mode_t Cy_SysPm_GetBootMode(void);

/*******************************************************************************
* Function Name: Cy_SysPm_TriggerSoftReset
****************************************************************************//**
*
* Triggers the System Soft reset.
*
*******************************************************************************/
void Cy_SysPm_TriggerSoftReset(void);

/*******************************************************************************
* Function Name: Cy_SysPm_TriggerXRes
****************************************************************************//**
*
* Triggers the XRES  reset.
*
*******************************************************************************/
void Cy_SysPm_TriggerXRes(void);

#endif

/*******************************************************************************
* Function Name: Cy_SysPm_CpuEnterDeepSleep
****************************************************************************//**
*
* Sets executing CPU to the Deep Sleep mode.
*
* Puts the CPU executing the function into CPU Deep Sleep. For a single CPU
* devices the device will immediately transition to system Deep Sleep. For a
* dual CPU devices the device will transition to system Deep Sleep only after
* both CPUs are in CPU Deep Sleep power mode.
*
* Prior to entering the CPU Deep Sleep mode, all callbacks of the
* CY_SYSPM_DEEPSLEEP type with the CY_SYSPM_CHECK_READY parameter registered
* callbacks are called, allowing the driver to signal whether it is ready to
* enter the power mode. If any CY_SYSPM_DEEPSLEEP type with the
* CY_SYSPM_CHECK_READY parameter call returns CY_SYSPM_FAIL, the remaining
* callback CY_SYSPM_DEEPSLEEP type with the CY_SYSPM_CHECK_READY parameter are
* skipped. After the first CY_SYSPM_FAIL, all the CY_SYSPM_DEEPSLEEP callbacks
* that were previously executed before getting the CY_SYSPM_CHECK_FAIL are
* executed with the CY_SYSPM_CHECK_FAIL parameter. The CPU Deep Sleep mode is
* not entered and the Cy_SysPm_CpuEnterDeepSleep() function returns
* CY_SYSPM_FAIL.
*
* If all callbacks of the CY_SYSPM_DEEPSLEEP type with the CY_SYSPM_CHECK_READY
* parameter return CY_SYSPM_SUCCESS, then all callbacks of the
* CY_SYSPM_DEEPSLEEP type with the CY_SYSPM_CHECK_FAIL parameter calls are
* skipped. All callbacks of the CY_SYSPM_DEEPSLEEP type with the
* CY_SYSPM_BEFORE_TRANSITION parameter calls are then executed, allowing the
* peripherals to prepare for CPU Deep Sleep. The Deep Sleep mode is then
* entered. Any enabled interrupt can cause a wakeup from the Deep Sleep mode.
*
* \note The last callback that returns CY_SYSPM_FAIL is not executed with the
* CY_SYSPM_CHECK_FAIL parameter because of the FAIL. The callback generating
* CY_SYSPM_FAIL is expected to not make any changes that require being undone.
*
* For multi-CPU devices (except CY8C6xx6 and CY8C6xx7) there is a possible
* situation when a syscall operation (for example during flash read or write)
* is executing. If the CM0+ CPU tries to enter Deep Sleep, it will fail. All
* the CY_SYSPM_DEEPSLEEP callbacks that were previously executed, are executed
* with the CY_SYSPM_CHECK_FAIL parameter. Deep Sleep mode is not entered and
* the Cy_SysPm_CpuEnterDeepSleep() function returns CY_SYSPM_SYSCALL_PENDING.
*
* The return value from executed callback functions with the
* CY_SYSPM_CHECK_FAIL, CY_SYSPM_BEFORE_TRANSITION, and CY_SYSPM_AFTER_TRANSITION
* modes are ignored.
*
* If the firmware attempts to enter this mode before the system is ready (that
* is, when PWR_CONTROL.LPM_READY = 0), then the CPU(s) will go into the CPU
* Sleep mode instead and automatically enter system Deep Sleep mode when the
* system is ready. On dual CPU devices, if one CPU enters CPU Deep Sleep and the
* other CPU remains active or is in CPU Sleep the first CPU will remain in CPU
* Deep Sleep. A CPU Deep Sleep is functionally identical to CPU Sleep.
*
* The device enters system Deep Sleep mode when all the CPU(s) are in CPU
* Deep Sleep, there are no busy peripherals, the debugger is not active, and the
* Deep Sleep power and reference are ready (PWR_CONTROL.LPM_READY=1).
*
* The peripherals that do not need a clock or that receive a clock from their
* external interface (e.g. I2C/SPI) may continue operating in system Deep Sleep.
* All circuits using current from Vccdpslp supply are limited by its maximum
* current specification of the Deep Sleep regulator.
*
* Wakeup occurs when an interrupt asserts from a Deep Sleep active peripheral.
* For more detail, see the corresponding peripheral's datasheet.
*
* For multi-core devices, CPU wakeup can also be performed using the Send Event
* (SEV) assembly instruction executed from the other active CPU. Such wakeup is
* expected only if the CPU Sleep power mode is done with WFE assembly
* instruction.
*
* \note
* For multi-CPU devices, the second CPU, if it did not participate in
* system wakeup, remains in CPU Deep Sleep mode. Any Deep Sleep capable
* interrupt routed to this CPU can also wake it.
*
* For more detail about switching into the system Deep Sleep power mode and
* debug, refer to the device TRM.
*
* A normal wakeup from the Deep Sleep power mode returns to either ULP or LP
* mode, depending on the previous state and programmed behavior for the
* particular wakeup interrupt. As soon as the system resumes LP or ULP mode the
* CPU(s) return to CPU Active or CPU Deep Sleep mode, depending on their
* configured wakeup settings.
*
* After wakeup from CPU Deep Sleep, all of the registered callbacks with
* CY_SYSPM_DEEPSLEEP type with CY_SYSPM_AFTER_TRANSITION are executed to return
* peripherals to active operation. The Cy_SysPm_CpuEnterDeepSleep() function
* returns CY_SYSPM_SUCCESS. No callbacks are executed with CY_SYSPM_DEEPSLEEP
* type with CY_SYSPM_BEFORE_TRANSITION or CY_SYSPM_AFTER_TRANSITION parameter,
* if Deep Sleep mode was not entered.
*
* To support control of callback execution order th following method is
* implemented. Callback function with the CY_SYSPM_CHECK_READY and
* CY_SYSPM_BEFORE_TRANSITION parameter are executed in the same order they are
* registered. Callback function with the CY_SYSPM_CHECK_FAIL and
* CY_SYSPM_AFTER_TRANSITION parameter are executed in the reverse order they
* are registered.
*
* \note
* This function clears the reset reason before going to deep sleep
*
* \note This API is secure aware but when running on the core without TrustZone,
* there will be no special security-related behavior. See header subsection Secure
* Aware SYSPM for further details.
* The involved PPC regions is PROT_PERI0_SRSS_MAIN.
*
* \param waitFor
* Selects wait for action. See \ref cy_en_syspm_waitfor_t.
*
* \sideeffect
* For CY8C6xx6, CY8C6xx7 devices this function clears the Event Register of the
* CM4 CPU after wakeup from WFE.
*
* \sideeffect
* This function changes the slow and fast clock dividers right before
* entering into system Deep Sleep and restores these dividers after wakeup.
*
* \return
* Entered status, see \ref cy_en_syspm_status_t.
*
* \note
* The FLL/PLL are not restored right before the CPU(s) start executing the
* instructions after system Deep Sleep. This can affect the peripheral that is
* driven by PLL/FLL. Ensure that the PLL/FLL are properly restored (locked)
* after wakeup from System Deep Sleep. Refer to the
* \ref group_sysclk driver documentation for information about how to
* read the PLL/FLL lock statuses.
*
* \note The Arm BSD assembly instruction is not required in this function
* because the function implementation ensures the SLEEPDEEP bit of SCS register
* is settled prior executing the WFI/WFE instruction.
*
* \funcusage
* \snippet syspm/snippet/main.c snippet_Cy_SysPm_CpuEnterDeepSleep
*
*******************************************************************************/
cy_en_syspm_status_t Cy_SysPm_CpuEnterDeepSleep(cy_en_syspm_waitfor_t waitFor);

#if (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION < 2)) || defined (CY_IP_MXS22SRSS) || (defined (CY_IP_MXS40SSRSS) && (CY_MXS40SSRSS_VER_1_2 > 0UL)) || defined (CY_DOXYGEN)

/*******************************************************************************
* Function Name: Cy_SysPm_SystemEnterLp
****************************************************************************//**
*
* Sets device into system Low Power mode.
*
* Returns the system to the default LP mode by raising the core voltage.
* In the LP mode, the clock frequencies can be increased to t
he LP mode
* limitations. Refer to the device datasheet for frequency limitations in the
* LP mode. Approximate LP limit values - \ref group_syspm_lp_limitations.
*
* Prior to entering the system LP mode, all the registered CY_SYSPM_LP callbacks
* with CY_SYSPM_CHECK_READY parameter are called. This allows the driver to
* signal that it is not ready to enter the system LP mode. If any CY_SYSPM_LP
* callbacks with the CY_SYSPM_CHECK_READY parameter call return CY_SYSPM_FAIL,
* the remaining CY_SYSPM_LP callbacks with the
* CY_SYSPM_CHECK_READY parameter calls are skipped.
* All of the CY_SYSPM_LP callbacks with the CY_SYSPM_BEFORE_TRANSITION
* require to reduce the clock frequency before entering LP mode.
* All of the CY_SYSPM_LP callbacks with the CY_SYSPM_AFTER_TRANSITION
* may now increase the Clock frequency to the target for LP mode.
*
* After a CY_SYSPM_FAIL, all of the CY_SYSPM_LP callbacks with
* CY_SYSPM_CHECK_FAIL parameter are executed that correspond to the
* CY_SYSPM_LP callbacks with CY_SYSPM_CHECK_READY parameter that occurred up to
* the point of failure. System LP mode is not entered and the
* Cy_SysPm_SystemEnterLp() function returns CY_SYSPM_FAIL.
*
* If all CY_SYSPM_LP callbacks with the CY_SYSPM_CHECK_READY
* parameter return CY_SYSPM_SUCCESS, then all CY_SYSPM_LP callbacks with
* CY_SYSPM_CHECK_FAIL are skipped and all CY_SYSPM_LP callbacks with the
* CY_SYSPM_BEFORE_TRANSITION parameter are executed. This allows the
* peripherals to prepare for LP mode. The system LP mode is then entered.
*
* After entering the system LP mode, all of the registered
* CY_SYSPM_LP callbacks with the CY_SYSPM_AFTER_TRANSITION parameter
* are executed to complete preparing the peripherals for low power operation.
* The Cy_SysPm_SystemEnterLp() function returns CY_SYSPM_SUCCESS.
* No CY_SYSPM_LP callbacks with the CY_SYSPM_BEFORE_TRANSITION or
* CY_SYSPM_AFTER_TRANSITION parameter are executed if the system LP mode is not
* entered.
*
* \note The last callback that returns CY_SYSPM_FAIL is not executed with the
* CY_SYSPM_CHECK_FAIL parameter because of the FAIL. The callback generating
* CY_SYSPM_FAIL is expected to not make any changes that require being undone.
*
* \note It is not possible to transition directly between ULP and HP modes.
* The device must first be transitioned to LP mode and then to the desired mode.
*
* The return value from executed callback functions with the
* CY_SYSPM_CHECK_FAIL, CY_SYSPM_BEFORE_TRANSITION, and CY_SYSPM_AFTER_TRANSITION
* modes are ignored.
*
* To support control of callback execution order th following method is
* implemented. Callback function with the CY_SYSPM_CHECK_READY and
* CY_SYSPM_BEFORE_TRANSITION parameter are executed in the same order they are
* registered. Callback function with the CY_SYSPM_CHECK_FAIL and
* CY_SYSPM_AFTER_TRANSITION parameter are executed in the reverse order they
* are registered.
*
* \return
* - CY_SYSPM_SUCCESS - Entered the system LP mode or the device is already in LP mode.
* - CY_SYSPM_INVALID_STATE - The system LP mode was not set. The system LP mode
*   was not set because the protection context value is higher than zero
*   (PC > 0) or the device revision does not support modifying registers
*   (to enter LP mode) via syscall.
* - CY_SYSPM_CANCELED - Operation was canceled. Call the function again until
*   the function returns CY_SYSPM_SUCCESS.
* - CY_SYSPM_FAIL - The system LP mode is not entered.
*   For the PSOC 64 devices there are possible situations when function returns
*   the PRA error status code. This is because for PSOC 64 devices the function
*   uses the PRA driver to change the protected registers. Refer to
*   \ref cy_en_pra_status_t for more details.
*
* \funcusage
* \snippet syspm/snippet/main.c snippet_Cy_SysPm_SystemEnterLp
*
*******************************************************************************/
#if !(defined (CY_IP_MXS22SRSS) && (CY_IP_MXS22SRSS_VERSION == 2) && (CY_IP_MXS22SRSS_VERSION_MINOR == 2))
cy_en_syspm_status_t Cy_SysPm_SystemEnterLp(void);
#endif /* !(CY_IP_MXS22SRSS VERSION_MINOR == 2) */


#if !(defined (CY_IP_MXS22SRSS) && (CY_IP_MXS22SRSS_VERSION == 2) && (CY_IP_MXS22SRSS_VERSION_MINOR == 1)) || defined (CY_DOXYGEN)
/*******************************************************************************
* Function Name: Cy_SysPm_SystemEnterUlp
****************************************************************************//**
*
* Sets device into system Ultra Low Power mode.
*
* System ULP mode is similar to system LP mode. The difference is that the
* system is put under \ref group_syspm_ulp_limitations.
*
* Before entering system ULP mode, the user must configure the system so
* the maximum clock frequencies are less than the ULP mode specifications
* presented in the device datasheet. Refer to the device datasheet for
* the maximum clock limitations in the ULP mode with reduced core supply
* regulator voltages.
*
* Prior to entering system ULP mode, all the registered CY_SYSPM_ULP callbacks
* with CY_SYSPM_CHECK_READY parameter are called. This allows the driver to
* signal if it is not ready to enter system ULP mode. If any CY_SYSPM_ULP
* callback with the CY_SYSPM_CHECK_READY parameter call returns CY_SYSPM_FAIL,
* the remaining CY_SYSPM_ULP callbacks with the CY_SYSPM_CHECK_READY parameter
* are skipped.
*
* All of the CY_SYSPM_ULP callbacks with the CY_SYSPM_BEFORE_TRANSITION
* require to reduce the clock frequency before entering ULP mode.
* All of the CY_SYSPM_ULP callbacks with the CY_SYSPM_AFTER_TRANSITION
* may now increase the Clock frequency to the target for ULP mode.
*
* After a CY_SYSPM_FAIL, all of the CY_SYSPM_ULP callbacks with the
* CY_SYSPM_CHECK_FAIL parameter are executed that correspond to the
* CY_SYSPM_ULP callback with CY_SYSPM_CHECK_READY parameter that occurred up to
* the point of failure. System ULP mode is not entered
* and the Cy_SysPm_SystemEnterUlp() function returns CY_SYSPM_FAIL.
*
* If all CY_SYSPM_ULP callbacks with the CY_SYSPM_CHECK_READY
* parameter return CY_SYSPM_SUCCESS, then all CY_SYSPM_ULP
* callbacks with CY_SYSPM_CHECK_FAIL calls are skipped and all CY_SYSPM_ULP
* callbacks with the CY_SYSPM_BEFORE_TRANSITION parameter are executed. This
* allows preparation for ULP. The system ULP mode is then entered.
*
* After entering system ULP, all of the registered CY_SYSPM_ULP callbacks with
* the CY_SYSPM_AFTER_TRANSITION parameter are executed to complete preparing the
* peripherals for ULP operation. The Cy_SysPm_SystemEnterUlp() function
* returns CY_SYSPM_SUCCESS. No CY_SYSPM_ULP callbacks with the
* CY_SYSPM_BEFORE_TRANSITION or CY_SYSPM_AFTER_TRANSITION parameter are
* executed, if ULP mode is not entered.
*
* \note The last callback that returns CY_SYSPM_FAIL is not executed with the
* CY_SYSPM_CHECK_FAIL parameter because of the FAIL. The callback generating
* CY_SYSPM_FAIL is expected to not make any changes that require being undone.
*
* \note It is not possible to transition directly between ULP and HP modes.
* The device must first be transitioned to LP mode and then to the desired mode.
*
* The return value from executed callback functions with the
* CY_SYSPM_CHECK_FAIL, CY_SYSPM_BEFORE_TRANSITION, and CY_SYSPM_AFTER_TRANSITION
* modes are ignored.
*
* To support control of callback execution order th following method is
* implemented. Callback function with the CY_SYSPM_CHECK_READY and
* CY_SYSPM_BEFORE_TRANSITION parameter are executed in the same order they are
* registered. Callback function with the CY_SYSPM_CHECK_FAIL and
* CY_SYSPM_AFTER_TRANSITION parameter are executed in the reverse order they
* are registered.
*
* \return
* - CY_SYSPM_SUCCESS - Entered the system ULP mode or the device is already in ULP mode.
* - CY_SYSPM_INVALID_STATE - System ULP mode was not set. The ULP mode was not
*   set because the protection context value is higher than zero (PC > 0) or the
*   device revision does not support modifying registers (to enter system
*   ULP mode) via syscall.
* - CY_SYSPM_CANCELED - Operation was canceled. Call the function again until
*   the function returns CY_SYSPM_SUCCESS.
* - CY_SYSPM_FAIL - The system ULP mode is not entered.
*   For the PSOC 64 devices there are possible situations when function returns
*   the PRA error status code. This is because for PSOC 64 devices the function
*   uses the PRA driver to change the protected registers. Refer to
*   \ref cy_en_pra_status_t for more details.
*
* \funcusage
* \snippet syspm/snippet/main.c snippet_Cy_SysPm_SystemEnterUlp
*
*******************************************************************************/
cy_en_syspm_status_t Cy_SysPm_SystemEnterUlp(void);

#endif /* #if !(defined (CY_IP_MXS22SRSS) && (CY_IP_MXS22SRSS_VERSION == 2) && (CY_IP_MXS22SRSS_VERSION_MINOR == 1)) || defined (CY_DOXYGEN) */
#if defined (CY_IP_MXS22SRSS) || defined (CY_IP_MXS40SSRSS) && (CY_MXS40SSRSS_VER_1_2 > 0UL) || defined (CY_DOXYGEN)


#if defined (CY_IP_MXS40SSRSS) && (CY_MXS40SSRSS_VER_1_2 > 0UL)
/*******************************************************************************
* Function Name: Cy_SysPm_SystemEnterMf
****************************************************************************//**
*
* Sets device into system Medium Frequency(MF) Low Power mode.
*
* System MF mode is similar to system LP and ULP mode. The difference is that the
* system is put under voltage which are in between LP and ULP.
*
* Before entering system MF mode, the user must configure the system so
* the maximum clock frequencies are less than the MF mode specifications
* presented in the device datasheet. Refer to the device datasheet for
* the maximum clock limitations in the MF mode with reduced core supply
* regulator voltages.
*
* Prior to entering system MF mode, all the registered CY_SYSPM_MF callbacks
* with CY_SYSPM_CHECK_READY parameter are called. This allows the driver to
* signal if it is not ready to enter system MF mode. If any CY_SYSPM_MF
* callback with the CY_SYSPM_CHECK_READY parameter call returns CY_SYSPM_FAIL,
* the remaining CY_SYSPM_MF callbacks with the CY_SYSPM_CHECK_READY parameter
* are skipped.
*
* After a CY_SYSPM_FAIL, all of the CY_SYSPM_MF callbacks with the
* CY_SYSPM_CHECK_FAIL parameter are executed that correspond to the
* CY_SYSPM_MF callback with CY_SYSPM_CHECK_READY parameter that occurred up to
* the point of failure. System MF mode is not entered
* and the Cy_SysPm_SystemEnterMf() function returns CY_SYSPM_FAIL.
*
* If all CY_SYSPM_MF callbacks with the CY_SYSPM_CHECK_READY
* parameter return CY_SYSPM_SUCCESS, then all CY_SYSPM_MF
* callbacks with CY_SYSPM_CHECK_FAIL calls are skipped and all CY_SYSPM_MF
* callbacks with the CY_SYSPM_BEFORE_TRANSITION parameter are executed. This
* allows preparation for MF. The system MF mode is then entered.
*
* After entering system MF, all of the registered CY_SYSPM_MF callbacks with
* the CY_SYSPM_AFTER_TRANSITION parameter are executed to complete preparing the
* peripherals for MF operation. The Cy_SysPm_SystemEnterUlp() function
* returns CY_SYSPM_SUCCESS. No CY_SYSPM_MF callbacks with the
* CY_SYSPM_BEFORE_TRANSITION or CY_SYSPM_AFTER_TRANSITION parameter are
* executed, if MF mode is not entered.
*
* \note The last callback that returns CY_SYSPM_FAIL is not executed with the
* CY_SYSPM_CHECK_FAIL parameter because of the FAIL. The callback generating
* CY_SYSPM_FAIL is expected to not make any changes that require being undone.
*
* The return value from executed callback functions with the
* CY_SYSPM_CHECK_FAIL, CY_SYSPM_BEFORE_TRANSITION, and CY_SYSPM_AFTER_TRANSITION
* modes are ignored.
*
* To support control of callback execution order th following method is
* implemented. Callback function with the CY_SYSPM_CHECK_READY and
* CY_SYSPM_BEFORE_TRANSITION parameter are executed in the same order they are
* registered. Callback function with the CY_SYSPM_CHECK_FAIL and
* CY_SYSPM_AFTER_TRANSITION parameter are executed in the reverse order they
* are registered.
*
* \return
* - CY_SYSPM_SUCCESS - Entered the system MF mode or the device is already in MF mode.
* - CY_SYSPM_INVALID_STATE - System MF mode was not set. The MF mode was not
*   set because the protection context value is higher than zero (PC > 0) or the
*   device revision does not support modifying registers (to enter system
*   MF mode) via syscall.
* - CY_SYSPM_CANCELED - Operation was canceled. Call the function again until
*   the function returns CY_SYSPM_SUCCESS.
* - CY_SYSPM_FAIL - The system MF mode is not entered.
*   For the PSOC 64 devices there are possible situations when function returns
*   the PRA error status code. This is because for PSOC 64 devices the function
*   uses the PRA driver to change the protected registers. Refer to
*   \ref cy_en_pra_status_t for more details.
*
* \funcusage
* \snippet syspm/snippet/main.c snippet_Cy_SysPm_SystemEnterMf
*
*******************************************************************************/
cy_en_syspm_status_t Cy_SysPm_SystemEnterMf(void);


/*******************************************************************************
* Function Name: Cy_SysPm_SystemEnterOd
****************************************************************************//**
*
* Sets device into system Over drive Power mode.
*
* System OD mode is similar to system LP mode. The difference is that the
* system is put under voltage which are is higher than LP.
*
* Before entering system OD mode, the user must configure the system so
* the maximum clock frequencies are less than the OD mode specifications
* presented in the device datasheet. Refer to the device datasheet for
* the maximum clock limitations in the ULP mode with reduced core supply
* regulator voltages.
*
* Prior to entering system OD mode, all the registered CY_SYSPM_OD callbacks
* with CY_SYSPM_CHECK_READY parameter are called. This allows the driver to
* signal if it is not ready to enter system OD mode. If any CY_SYSPM_OD
* callback with the CY_SYSPM_CHECK_READY parameter call returns CY_SYSPM_FAIL,
* the remaining CY_SYSPM_OD callbacks with the CY_SYSPM_CHECK_READY parameter
* are skipped.
*
* After a CY_SYSPM_FAIL, all of the CY_SYSPM_OD callbacks with the
* CY_SYSPM_CHECK_FAIL parameter are executed that correspond to the
* CY_SYSPM_OD callback with CY_SYSPM_CHECK_READY parameter that occurred up to
* the point of failure. System OD mode is not entered
* and the Cy_SysPm_SystemEnterOd() function returns CY_SYSPM_FAIL.
*
* If all CY_SYSPM_OD callbacks with the CY_SYSPM_CHECK_READY
* parameter return CY_SYSPM_SUCCESS, then all CY_SYSPM_OD
* callbacks with CY_SYSPM_CHECK_FAIL calls are skipped and all CY_SYSPM_OD
* callbacks with the CY_SYSPM_BEFORE_TRANSITION parameter are executed. This
* allows preparation for OD. The system OD mode is then entered.
*
* After entering system OD, all of the registered CY_SYSPM_OD callbacks with
* the CY_SYSPM_AFTER_TRANSITION parameter are executed to complete preparing the
* peripherals for OD operation. The Cy_SysPm_SystemEnterOd() function
* returns CY_SYSPM_SUCCESS. No CY_SYSPM_OD callbacks with the
* CY_SYSPM_BEFORE_TRANSITION or CY_SYSPM_AFTER_TRANSITION parameter are
* executed, if OD mode is not entered.
*
* \note The last callback that returns CY_SYSPM_FAIL is not executed with the
* CY_SYSPM_CHECK_FAIL parameter because of the FAIL. The callback generating
* CY_SYSPM_FAIL is expected to not make any changes that require being undone.
*
* The return value from executed callback functions with the
* CY_SYSPM_CHECK_FAIL, CY_SYSPM_BEFORE_TRANSITION, and CY_SYSPM_AFTER_TRANSITION
* modes are ignored.
*
* To support control of callback execution order th following method is
* implemented. Callback function with the CY_SYSPM_CHECK_READY and
* CY_SYSPM_BEFORE_TRANSITION parameter are executed in the same order they are
* registered. Callback function with the CY_SYSPM_CHECK_FAIL and
* CY_SYSPM_AFTER_TRANSITION parameter are executed in the reverse order they
* are registered.
*
* \return
* - CY_SYSPM_SUCCESS - Entered the system ULP mode or the device is already in ULP mode.
* - CY_SYSPM_INVALID_STATE - System ULP mode was not set. The ULP mode was not
*   set because the protection context value is higher than zero (PC > 0) or the
*   device revision does not support modifying registers (to enter system
*   ULP mode) via syscall.
* - CY_SYSPM_CANCELED - Operation was canceled. Call the function again until
*   the function returns CY_SYSPM_SUCCESS.
* - CY_SYSPM_FAIL - The system OD mode is not entered.
*
* \funcusage
* \snippet syspm/snippet/main.c snippet_Cy_SysPm_SystemEnterOd
*
*******************************************************************************/
cy_en_syspm_status_t Cy_SysPm_SystemEnterOd(void);

#endif


#endif /* CY_IP_MXS22SRSS || defined (CY_DOXYGEN)*/


#endif /* (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION < 2)) || defined (CY_IP_MXS22SRSS) || defined (CY_DOXYGEN) ||
           (defined (CY_IP_MXS40SSRSS) && (CY_MXS40SSRSS_VER_1_2 > 0UL))*/

#if defined (CY_IP_MXS22SRSS) && (CY_IP_MXS22SRSS_VERSION == 2) && (CY_IP_MXS22SRSS_VERSION_MINOR >= 1)

/*******************************************************************************
* Function Name: Cy_SysPm_SystemEnterHibernateRam
****************************************************************************//**
*
* Configures the system to enter the Hibernate RAM mode. Before entering the
* Hibernate RAM mode, system perform the context save and if the context save fails
* device triggers a power reset. The context info saved by the syspm driver is
* used by the Boot code on wakeup to restore the configuration to perform warm boot
*
* Puts the device into the system Hibernate RAM power mode. Prior to entering
* Hibernate mode, all callbacks of the CY_SYSPM_HIBERNATE_RAM type are executed.
*
* First, callbacks of the CY_SYSPM_HIBERNATE_RAM type are called with the
* CY_SYSPM_CHECK_READY parameter. This allows the callback to signal that the
* driver is not ready to enter the system Hibernate RAM power mode. If any of the
* callback return CY_SYSPM_FAIL, the remaining CY_SYSPM_HIBERNATE_RAM callbacks are
* skipped. In this case, all of the callbacks that have already been called are
* called again with the CY_SYSPM_CHECK_FAIL parameter. System Hibernate mode is
* not entered and the Cy_SysPm_SystemEnterHibernate() function returns
* CY_SYSPM_FAIL.
*
* If all CY_SYSPM_HIBERNATE_RAM callbacks with the CY_SYSPM_CHECK_READY parameter
* return CY_SYSPM_SUCCESS, then all CY_SYSPM_HIBERNATE_RAM callbacks with
* CY_SYSPM_CHECK_FAIL calls are skipped and all CY_SYSPM_HIBERNATE_RAM callbacks
* with CY_SYSPM_BEFORE_TRANSITION parameter are executed allowing the
* peripherals to prepare for system Hibernate RAM.
*
* \note The last callback that returns CY_SYSPM_FAIL is not executed with the
* CY_SYSPM_CHECK_FAIL parameter because of the FAIL. The callback generating
* CY_SYSPM_FAIL is expected to not make any changes that require being undone.
*
* The return value from executed callback functions with the
* CY_SYSPM_CHECK_FAIL, CY_SYSPM_BEFORE_TRANSITION, and CY_SYSPM_AFTER_TRANSITION
* modes are ignored.
*
* Wakeup from system Hibernate RAM is similar to that of Hibernate mode and is
* triggered by toggling the wakeup pin(s), WDT
* match, or back-up domain RTC alarm expiration, depending on how the they are
* configured. To configure the wakeup pin(s), a digital input pin must be
* configured, and resistively pulled up or down to the inverse state of the
* wakeup polarity.
*
* \return
* \ref cy_en_syspm_status_t
*
*******************************************************************************/
cy_en_syspm_status_t Cy_SysPm_SystemEnterHibernateRam(cy_en_syspm_waitfor_t waitFor);

#endif /* defined (CY_IP_MXS22SRSS) && (CY_IP_MXS22SRSS_VERSION == 2) && (CY_IP_MXS22SRSS_VERSION_MINOR >= 1) */

/*******************************************************************************
* Function Name: Cy_SysPm_SystemEnterHibernate
****************************************************************************//**
*
* Sets the device into system Hibernate mode.
*
* Puts the device into the system Hibernate power mode. Prior to entering
* Hibernate mode, all callbacks of the CY_SYSPM_HIBERNATE type are executed.
*
* First, callbacks of the CY_SYSPM_HIBERNATE type are called with the
* CY_SYSPM_CHECK_READY parameter. This allows the callback to signal that the
* driver is not ready to enter the system Hibernate power mode. If any of the
* callback return CY_SYSPM_FAIL, the remaining CY_SYSPM_HIBERNATE callbacks are
* skipped. In this case, all of the callbacks that have already been called are
* called again with the CY_SYSPM_CHECK_FAIL parameter. System Hibernate mode is
* not entered and the Cy_SysPm_SystemEnterHibernate() function returns
* CY_SYSPM_FAIL.
*
* If all CY_SYSPM_HIBERNATE callbacks with the CY_SYSPM_CHECK_READY parameter
* return CY_SYSPM_SUCCESS, then all CY_SYSPM_HIBERNATE callbacks with
* CY_SYSPM_CHECK_FAIL calls are skipped and all CY_SYSPM_HIBERNATE callbacks
* with CY_SYSPM_BEFORE_TRANSITION parameter are executed allowing the
* peripherals to prepare for system Hibernate.
*
* The I/O output state is automatically frozen by hardware system and Hibernate
* mode is then entered. In Hibernate mode, all internal supplies are off and no
* internal state is retained. The only exception is resources powered by the
* Vbackup domain continue to operate, if enabled. For multi-CPU devices, there
* is no handshake with the CPUs and the chip will enter Hibernate power
* mode immediately.
*
* \note The last callback that returns CY_SYSPM_FAIL is not executed with the
* CY_SYSPM_CHECK_FAIL parameter because of the FAIL. The callback generating
* CY_SYSPM_FAIL is expected to not make any changes that require being undone.
*
* The return value from executed callback functions with the
* CY_SYSPM_CHECK_FAIL, CY_SYSPM_BEFORE_TRANSITION, and CY_SYSPM_AFTER_TRANSITION
* modes are ignored.
*
* Wakeup from system Hibernate is triggered by toggling the wakeup pin(s), WDT
* match, or back-up domain RTC alarm expiration, depending on how the they are
* configured. A wakeup causes a normal boot procedure.
* To configure the wakeup pin(s), a digital input pin must be configured, and
* resistively pulled up or down to the inverse state of the wakeup polarity. To
* distinguish a Hibernate mode from a general reset wakeup event, the
* Cy_SysLib_GetResetReason() function can be used. The wakeup pin and low-power
* comparators are active-low by default. The wakeup pin or the LPComparators
* polarity can be changed with the \ref Cy_SysPm_SetHibernateWakeupSource()
* function.
* This function call will not return if system Hibernate mode is entered.
* The CY_SYSPM_HIBERNATE callbacks with the CY_SYSPM_AFTER_TRANSITION parameter
* are never executed.
*
* This function freezes the I/O pins implicitly. Entering system Hibernate mode
* before freezing the I/O pins is not possible. The I/O pins remain frozen after
* waking from Hibernate mode until the firmware unfreezes them with
* a \ref Cy_SysPm_IoUnfreeze() function call.
*
* Boot firmware should reconfigure the I/O pins as required by the application
* prior unfreezing them.
*
* To support control of callback execution order the following method is
* implemented. Callback function with the CY_SYSPM_CHECK_READY and
* CY_SYSPM_BEFORE_TRANSITION parameter are executed in the same order they are
* registered. Callback function with the CY_SYSPM_CHECK_FAIL and
* CY_SYSPM_AFTER_TRANSITION parameter are executed in the reverse order they
* are registered.
*
* \note This API is secure aware but when running on the core without TrustZone,
* there will be no special security-related behavior. See header subsection Secure
* Aware SYSPM for further details.
* If Secure Aware SYSPM is enabled and the corresponding SYSPM PPC region is secured,
* we don't allow the CM55 to request hibernate entry on its own, since that is a system-wide impact.
* The involved PPC regions are PROT_PERI0_SRSS_MAIN/PROT_PERI0_SRSS_HIB_DATA.
* Both PROT_PERI0_SRSS_MAIN/PROT_PERI0_SRSS_HIB_DATA should be either secure or non-secure.
*
* \return
* Entered status, see \ref cy_en_syspm_status_t.
* For the PSOC 64 devices there are possible situations when function returns
* the PRA error status code. This is because for PSOC 64 devices the function
* uses the PRA driver to change the protected registers. Refer to
* \ref cy_en_pra_status_t for more details.
*
* \funcusage
* \snippet syspm/snippet/main.c snippet_Cy_SysPm_SystemEnterHibernate
*
* \note In order to get correct value of hibernate wake up cause at next hibernation,
* upper layer have to clear the interrupt register first
* and then clear the hibernate wake up cause \ref Cy_SysPm_ClearHibernateWakeupCause()
* for the current hibernation.
*
*******************************************************************************/
cy_en_syspm_status_t Cy_SysPm_SystemEnterHibernate(void);


/*******************************************************************************
* Function Name: Cy_SysPm_SetHibernateWakeupSource
****************************************************************************//**
*
* This function configures sources to wake up the device from the system
* Hibernate power mode. Sources can be wakeup pins, LPComparators, Watchdog (WDT)
* interrupt, or a Real-Time clock (RTC) alarm (interrupt). Wakeup from system
* Hibernate always results in a device reset and normal boot process.
*
* Wakeup pins:
*
* A wakeup is supported by up to two pins with programmable polarity. These pins
* are typically connected to the GPIO pins or on-chip peripherals under some
* conditions. See device datasheet for specific pin connections.
* Setting the wakeup pin to this level will cause a wakeup from system Hibernate
* mode. The wakeup pins are active-low by default.
*
* LPComparators:
*
* A wakeup is supported by up to two LPComps with programmable polarity.
* Setting the LPComp to this level will cause a wakeup from system Hibernate
* mode. The wakeup LPComps are active-low by default.
*
* \note The low-power comparators should be configured and enabled before
* switching to system Hibernate mode. Refer to the LPComp
* driver description for more detail.
*
* Watchdog Timer:
*
* \note The WDT should be configured and enabled before entering to system
* Hibernate mode.
*
* A wakeup is performed by a WDT interrupt.
*
* Real-time Clock:
*
* A wakeup is performed by the RTC alarm.
* Refer to the Real-Time Clock (RTC) driver description for more detail.
*
* For information about wakeup sources and their assignment in specific
* devices, refer to the appropriate device TRM.
*
* \param wakeupSource
* The source to be configured as a wakeup source from
* the system Hibernate power mode, see \ref cy_en_syspm_hibernate_wakeup_source_t.
* The input parameter values can be ORed. For example, if you want to enable
* LPComp0 (active high) and WDT, call this function:
* Cy_SysPm_SetHibernateWakeupSource(CY_SYSPM_HIBERNATE_LPCOMP0_HIGH | CY_SYSPM_HIBERNATE_WDT).
*
* \warning Do not call this function with different polarity levels for the same
* wakeup source. For example, do not call a function like this:
* Cy_SysPm_SetHibernateWakeupSource(CY_SYSPM_HIBERNATE_LPCOMP0_LOW, CY_SYSPM_HIBERNATE_LPCOMP0_HIGH);
*
* \funcusage
* \snippet syspm/snippet/main.c snippet_Cy_SysPm_SetHibernateWakeupSource
*
*******************************************************************************/
void Cy_SysPm_SetHibernateWakeupSource(uint32_t wakeupSource);


/*******************************************************************************
* Function Name: Cy_SysPm_ClearHibernateWakeupSource
****************************************************************************//**
*
* This function disables a wakeup source that was previously configured to
* wake up the device from the system Hibernate mode.
*
* \param wakeupSource
* For the source to be disabled, see \ref cy_en_syspm_hibernate_wakeup_source_t.
* The input parameters values can be ORed. For example, if you want to disable
* LPComp0 (active high) and WDT call this function:
* Cy_SysPm_ClearHibernateWakeupSource(CY_SYSPM_HIBERNATE_LPCOMP0_HIGH | CY_SYSPM_HIBERNATE_WDT).
*
* \funcusage
* \snippet syspm/snippet/main.c snippet_Cy_SysPm_ClearHibernateWakeupSource
*
*******************************************************************************/
void Cy_SysPm_ClearHibernateWakeupSource(uint32_t wakeupSource);

#if defined (CY_IP_MXS40SSRSS) || defined (CY_IP_MXS22SRSS) || (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION == 3u) && defined (CY_IP_MXS40SRSS_VERSION_MINOR) && (CY_IP_MXS40SRSS_VERSION_MINOR >= 3u)) || defined (CY_DOXYGEN)
/*******************************************************************************
* Function Name: Cy_SysPm_GetHibernateWakeupCause
****************************************************************************//**
*
* This function gets the wakeup cause for Hibernate mode.
*
* \return
* Wakeup Reason \ref cy_en_syspm_hibernate_wakeup_source_t
*
*******************************************************************************/
cy_en_syspm_hibernate_wakeup_source_t Cy_SysPm_GetHibernateWakeupCause(void);

/*******************************************************************************
* Function Name: Cy_SysPm_ClearHibernateWakeupCause
****************************************************************************//**
*
* This function Clears the wakeup cause register.
*
*******************************************************************************/
__STATIC_INLINE void Cy_SysPm_ClearHibernateWakeupCause(void)
{
    uint32_t temp = SRSS_PWR_HIB_WAKE_CAUSE;
    SRSS_PWR_HIB_WAKE_CAUSE = temp;
}

#endif



/*******************************************************************************
* Function Name: Cy_SysPm_SystemSetMinRegulatorCurrent
****************************************************************************//**
*
* Sets the system into minimum core regulator current mode. This mode limits
* maximum current available for the system core logic.
*
* Minimum regulator current mode modifies operation of the system in LP or ULP
* modes to further reduce current consumption. If the system current is below
* datasheet current limits for the active core voltage regulator (LDO or Buck),
* this mode may be entered. The user is responsible for ensuring the
* regulator current limit is met in their application.
*
* When in minimum regulator current mode, the following system resources are
* also set to their LP mode:
* - Linear regulator (If LDO is active regulator)
* - POR/BOD circuit
* - Bandgap reference circuit
* - Reference buffer circuit
* - Current reference circuit
*
* The LDO and Buck current limits must be met prior to entering this
* mode. If these are not met, the device may brown out, resulting in an
* exception or reset. These changes also reduce power supply rejection of
* the affected system resources, which can result in increased noise or response
* time. These effects must be evaluated in each application.
*
* \return
* See \ref cy_en_syspm_status_t.
* - CY_SYSPM_SUCCESS - Minimum regulator current mode was set
* - CY_SYSPM_CANCELED - The power circuits were not ready to enter into
*   minimum current mode. You should call the function again.
*   For the PSOC 64 devices there are possible situations when function returns
*   the PRA error status code. This is because for PSOC 64 devices the function
*   uses the PRA driver to change the protected registers. Refer to
*   \ref cy_en_pra_status_t for more details.
*
* Refer to device datasheet for maximum current value in regulator minimum
* current mode.
*
* \funcusage
* \snippet syspm/snippet/main.c snippet_Cy_SysPm_SystemSetMinRegulatorCurrent
*
*******************************************************************************/
cy_en_syspm_status_t Cy_SysPm_SystemSetMinRegulatorCurrent(void);


/*******************************************************************************
* Function Name: Cy_SysPm_SystemSetNormalRegulatorCurrent
****************************************************************************//**
*
* Sets the system to normal regulator current mode.
*
* Normal regulator current mode modifies operation of the system in LP or ULP
* modes to provide maximum core current consumption. If the LDO core regulator
* is in use, the normal mode output current limits may be used. If the buck
* regulator is in use, its reduced current output limits still apply.
*
* When in normal regulator current mode, the following system resources are set
* to their normal mode:
* - Linear regulator (If LDO is active regulator)
* - POR/BOD circuit
* - Bandgap reference circuit
* - Reference buffer circuit
* - Current reference circuit
*
* \return
* - CY_SYSPM_SUCCESS - Normal regulator current mode was set
* - CY_SYSPM_TIMEOUT - The timeout occurred because device was not
*   ready to enter into the normal regulator current mode
*   For the PSOC 64 devices there are possible situations when function returns
*   the PRA error status code. This is because for PSOC 64 devices the function
*   uses the PRA driver to change the protected registers. Refer to
*   \ref cy_en_pra_status_t for more details.
*
* \funcusage
* \snippet syspm/snippet/main.c snippet_Cy_SysPm_SystemSetNormalRegulatorCurrent
*
*******************************************************************************/
cy_en_syspm_status_t Cy_SysPm_SystemSetNormalRegulatorCurrent(void);


/*******************************************************************************
* Function Name: Cy_SysPm_CpuSleepOnExit
****************************************************************************//**
*
* This function configures the sleep-on-exit feature of the CPU.
*
* This API sets the SLEEPONEXIT bit of the SCR register.
*
* When the sleep-on-exit feature is enabled (the SLEEPONEXIT bit is set),
* the CPU wakes up to service the interrupt and then immediately goes
* back to sleep. Because of this, the unstacking process is not carried out, so
* this feature is useful for interrupt driven application and helps to
* reduce unnecessary stack push and pop operations.
* The CPU does not go to sleep if the interrupt handler returns to
* another interrupt handler (nested interrupt).
* You can use this feature in applications that require the CPU to only run
* when an interrupt occurs.
*
* When the sleep-on-exit feature is disabled (the SLEEPONEXIT bit is cleared),
* the CPU returns back to the main thread after servicing the interrupt
* without going back to sleep.
*
* Refer to the Arm documentation about the sleep-on-exit feature and
* SLEEPONEXIT in the SCR register.
*
* \param enable
* - True if enable sleep-on-exit feature.
* - False if disable sleep-on-exit feature.
*
* \funcusage
* \snippet syspm/snippet/main.c snippet_Cy_SysPm_CpuSleepOnExit
*
*******************************************************************************/
__STATIC_INLINE void Cy_SysPm_CpuSleepOnExit(bool enable)
{
    if(enable)
    {
        /* Enable sleep-on-exit feature */
        SCB_SCR |= SCB_SCR_SLEEPONEXIT_Msk;
    }
    else
    {
        /* Disable sleep-on-exit feature */
        SCB_SCR &= (uint32_t) ~(SCB_SCR_SLEEPONEXIT_Msk);
    }
}

/** \} group_syspm_functions_power */


/**
* \addtogroup group_syspm_functions_power
* \{
*/
/*******************************************************************************
* Function Name: Cy_SysPm_CpuSendWakeupEvent
****************************************************************************//**
*
* Sends the SEV (Send Event) ARM instruction to the system.
*
* \note In secure settings, this API is safe to call from both a secure and
* non-secure CPU state. See header subsection Secure Aware SYSPM for further details.
*
* \funcusage
* \snippet syspm/snippet/main.c snippet_Cy_SysPm_CpuSendWakeupEvent
*
*******************************************************************************/
__STATIC_INLINE void Cy_SysPm_CpuSendWakeupEvent(void)
{
    __SEV();
}

#if defined (CY_IP_MXS22SRSS) || defined (CY_DOXYGEN)
/*******************************************************************************
* Function Name: Cy_SysPm_SystemIsMinRegulatorCurrentSet
****************************************************************************//**
*
* Check whether the system regulator is set to minimal current mode.
*
* \return
* - True - system is in regulator minimum current mode.
* - False - system is in normal regulator current mode.
*
* \funcusage
* \snippet syspm/snippet/main.c snippet_Cy_SysPm_SystemSetNormalRegulatorCurrent
*
*******************************************************************************/
__STATIC_INLINE bool Cy_SysPm_SystemIsMinRegulatorCurrentSet(void)
{
    #if defined (CY_IP_MXS22SRSS) && (CY_IP_MXS22SRSS_VERSION == 2UL)
    return ((0U == _FLD2VAL(PWRCTL_MAIN_HV_PWR_CTL2_REFSYS_VBUF_DIS, SRSS_PWR_CTL2)) ? false : true);
    #else
    return ((0U == _FLD2VAL(SRSS_PWR_CTL2_REFSYS_VBUF_DIS, SRSS_PWR_CTL2)) ? false : true);
    #endif
}
#endif /* defined (CY_IP_MXS40SRSS) || defined (CY_IP_MXS40SSRSS) || defined (CY_DOXYGEN) */
#if defined (CY_IP_MXS40SRSS) || defined (CY_IP_MXS40SSRSS)
__STATIC_INLINE bool Cy_SysPm_SystemIsMinRegulatorCurrentSet(void)
{
#if (defined (CY_IP_MXS40SSRSS) && (SRSS_S40S_REGSETB_PRESENT == 1UL))
    uint32_t regMask = Cy_SysPm_LdoIsEnabled() ? CY_SYSPM_PWR_CIRCUITS_LPMODE_ACTIVE_LDO_MASK : CY_SYSPM_PWR_CIRCUITS_LPMODE_ACTIVE_BUCK_MASK;

    return ((SRSS_PWR_CTL & regMask) == regMask);
#else
    return ((0U == _FLD2VAL(SRSS_PWR_CTL2_REFV_DIS, SRSS_PWR_CTL2)) ? false : true);
#endif
}
#endif
/** \} group_syspm_functions_power */

/**
* \addtogroup group_syspm_functions_ldo
* \{
*/

#if (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION < 2)) || (defined (CY_IP_MXS40SSRSS) && (CY_MXS40SSRSS_VER_1_2 > 0UL)) || defined (CY_DOXYGEN)

/*******************************************************************************
* Function Name: Cy_SysPm_LdoSetVoltage
****************************************************************************//**
*
* Set output voltage on the core LDO regulator.
*
* When changing from a higher voltage to a lower voltage as when the device
* enters system ULP mode, ensure that:
* * The device maximum operating frequency for all the Clk_HF paths, peripheral,
*   and slow clock are under the \ref group_syspm_ulp_limitations.
* * The total current consumption is under the \ref group_syspm_ulp_limitations.
* * The appropriate wait states values are set for the flash using
*   The Cy_SysLib_SetWaitStates() function as explained below.
*
* <b>Setting wait states values for flash</b>
*
* The flash access time when the core voltage is 0.9 V (nominal) is
* longer than at 1.1 V (nominal). Therefore, the number of the wait states must
* be adjusted. Use the Cy_SysLib_SetWaitStates() function to set the appropriate
* wait state values for flash.
*
* To change from a higher voltage to a lower voltage 0.9 V (nominal),
* call the Cy_SysLib_SetWaitStates(true, hfClkFreqMz) function before changing
* the voltage, where hfClkFreqMz is the frequency of HfClk0 in MHz.
*
* To change from a lower voltage to a higher voltage 1.1 V (nominal), calling
* the Cy_SysLib_SetWaitStates(false, hfClkFreqMz) function to set the
* wait states is optional, but can be done to improve performance.
* The clock frequency may now be increased up to
* \ref group_syspm_lp_limitations.
*
* \note 1. The output is set to 0.9 V (nominal) - the system is in ULP mode and
* flash works for read-only operation.
* \note 2. The output is set to 1.1 V (nominal) - the system is in LP mode
* and flash works for read and write operations.
* \note 3. The actual device Vccd voltage can be different from the nominal
* voltage because the actual voltage value depends on conditions
* including the load current.
*
* For more detail, refer to the \ref group_syspm_switching_into_ulp and
* \ref group_syspm_switching_into_lp sections.
* Refer to the \ref group_syslib driver for more detail about setting the wait
* states.
*
* \param voltage
* The desired output regulator voltage.
* See \ref cy_en_syspm_ldo_voltage_t voltage
*
* \return
* - CY_SYSPM_SUCCESS - The voltage is set.
* - CY_SYSPM_INVALID_STATE - The voltage was not set. The voltage cannot be set
*   because the protection context value is higher than zero (PC > 0) or the
*   device revision does not support modifying registers via syscall.
* - CY_SYSPM_CANCELED - Operation was canceled. Call the function again until
*   the function returns CY_SYSPM_SUCCESS. See \ref cy_en_syspm_status_t.
*   For the PSOC 64 devices there are possible situations when function returns
*   the PRA error status code. This is because for PSOC 64 devices the function
*   uses the PRA driver to change the protected registers. Refer to
*   \ref cy_en_pra_status_t for more details.
*
* \funcusage
* \snippet syspm/snippet/main.c snippet_Cy_SysPm_VoltageRegulator
*
*******************************************************************************/
cy_en_syspm_status_t Cy_SysPm_LdoSetVoltage(cy_en_syspm_ldo_voltage_t voltage);
#endif /* (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION < 2)) */

/*******************************************************************************
* Function Name: Cy_SysPm_LdoSetMode
****************************************************************************//**
*
* Configures the core LDO regulator operating mode to one of three modes.
* Disabled - turns off the LDO regulator and should be selected only after the
* Buck regulator is operating. Normal mode configures the LDO for operation at
* the maximum output current limit. Minimal current mode optimizes the LDO at a
* reduced output current limit. Specific device current limits can be found in
* the device datasheet.
*
* \param mode
* The desired LDO regulator operating mode.
* See \ref cy_en_syspm_ldo_mode_t mode
*
* \return
* - CY_SYSPM_SUCCESS - Requested regulator current mode was set
* - CY_SYSPM_CANCELED - The power circuits were not ready to enter into
*   minimum current mode. You should try to call the function again
* - CY_SYSPM_TIMEOUT - Timeout occurred because of active reference was not
*   ready to enter into the normal regulator current mode
* - CY_SYSPM_FAIL - incorrect mode value was passed
*   For the PSOC 64 devices there are possible situations when function returns
*   the PRA error status code. This is because for PSOC 64 devices the function
*   uses the PRA driver to change the protected registers. Refer to
*   \ref cy_en_pra_status_t for more details.
*
* \sideeffect
* For PSOC 64 series devices CY_SYSPM_LDO_MODE_DISABLED mode is not supported.
* Use \ref Cy_SysPm_BuckEnable() instead.
*
*******************************************************************************/
cy_en_syspm_status_t Cy_SysPm_LdoSetMode(cy_en_syspm_ldo_mode_t mode);


/*******************************************************************************
* Function Name: Cy_SysPm_LdoGetMode
****************************************************************************//**
*
* Returns the current core LDO regulator operating mode.
*
* \return
* The LDO regulator operating mode.
* See \ref cy_en_syspm_ldo_mode_t mode
*
*******************************************************************************/
__STATIC_INLINE cy_en_syspm_ldo_mode_t Cy_SysPm_LdoGetMode(void)
{
    cy_en_syspm_ldo_mode_t retVal;

    if (Cy_SysPm_SystemIsMinRegulatorCurrentSet())
    {
        retVal = CY_SYSPM_LDO_MODE_MIN;
    }
    else
    {
        retVal = CY_SYSPM_LDO_MODE_NORMAL;
    }

    return retVal;
}

/** \} group_syspm_functions_ldo */

/**
* \addtogroup group_syspm_functions_linearreg
* \{
*/
#if (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION >= 2)) || (defined (CY_IP_MXS40SSRSS) && (SRSS_S40S_REGSETA_PRESENT == 1UL))

/*******************************************************************************
* Function Name: Cy_SysPm_LinearRegDisable
****************************************************************************//**
*
* Disables internal linear regulator.
*
*******************************************************************************/
void Cy_SysPm_LinearRegDisable(void);

/*******************************************************************************
* Function Name: Cy_SysPm_LinearRegEnable
****************************************************************************//**
*
* Enables internal linear regulator.
*
*******************************************************************************/
void Cy_SysPm_LinearRegEnable(void);


/*******************************************************************************
* Function Name: Cy_SysPm_LinearRegGetStatus
****************************************************************************//**
*
* Check the status of the internal linear regulator.
*
* \return
* true  - status ok
* false - status fail
*
*******************************************************************************/
bool Cy_SysPm_LinearRegGetStatus(void);


/*******************************************************************************
* Function Name: Cy_SysPm_DeepSleepRegDisable
****************************************************************************//**
*
* Disables internal DeepSleep regulator.
*
*******************************************************************************/
void Cy_SysPm_DeepSleepRegDisable(void);


/*******************************************************************************
* Function Name: Cy_SysPm_DeepSleepRegEnable
****************************************************************************//**
*
* Enables internal DeepSleep regulator.
*
*******************************************************************************/
void Cy_SysPm_DeepSleepRegEnable(void);

/*******************************************************************************
* Function Name: Cy_SySPm_IsDeepSleepRegEnabled
****************************************************************************//**
*
* Checks if internal DeepSleep regulator is enabled or not.
*
* \return
* true  - Enabled
* false - Disabled
*
*******************************************************************************/
bool Cy_SySPm_IsDeepSleepRegEnabled(void);

#endif  /* defined ((CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION >= 2) */

/** \} group_syspm_functions_linearreg */



/**
* \addtogroup group_syspm_functions_reghc
* \{
*/
#if (defined (SRSS_S40E_REGHC_PRESENT) && (SRSS_S40E_REGHC_PRESENT == 1u)) || \
    ((defined (SRSS_S40E_HTREGHC_PRESENT) && (SRSS_S40E_HTREGHC_PRESENT == 1u))) || \
    defined (CY_DOXYGEN)

/*******************************************************************************
* Function Name: Cy_SysPm_ReghcSelectMode
****************************************************************************//**
*
* Selects one of the supported REGHC modes.
*
* \param
* mode - PMIC or Pass Transistor
*
*******************************************************************************/
void Cy_SysPm_ReghcSelectMode(cy_en_syspm_reghc_mode_t mode);

/*******************************************************************************
* Function Name: Cy_SysPm_ReghcGetMode
****************************************************************************//**
*
* Gets the supported REGHC modes.
*
* \return \ref cy_en_syspm_reghc_mode_t
*
*******************************************************************************/
cy_en_syspm_reghc_mode_t Cy_SysPm_ReghcGetMode(void);

/*******************************************************************************
* Function Name: Cy_SysPm_ReghcSelectDriveOut
****************************************************************************//**
*
* Selects DRV_OUT setting.
*
* \param
* drvOut - \ref cy_en_syspm_reghc_drive_out_t
*
*******************************************************************************/
void Cy_SysPm_ReghcSelectDriveOut(cy_en_syspm_reghc_drive_out_t drvOut);

/*******************************************************************************
* Function Name: Cy_SysPm_ReghcGetDriveOut
****************************************************************************//**
*
* Gets the DRV_OUT setting.
*
* \return \ref cy_en_syspm_reghc_drive_out_t
*
*******************************************************************************/
cy_en_syspm_reghc_drive_out_t Cy_SysPm_ReghcGetDriveOut(void);


/*******************************************************************************
* Function Name: Cy_SysPm_ReghcAdjustOutputVoltage
****************************************************************************//**
*
* Selects regulator output voltage adjustment.
*
* \param
* trim - \ref cy_en_syspm_reghc_vadj_t
*
*******************************************************************************/
void Cy_SysPm_ReghcAdjustOutputVoltage(cy_en_syspm_reghc_vadj_t trim);


/*******************************************************************************
* Function Name: Cy_SysPm_ReghcDisableIntSupplyWhileExtActive
****************************************************************************//**
*
*  Internal Active Linear Regulator disabled after PMIC enabled.  OCD is disabled.
*
*******************************************************************************/
void Cy_SysPm_ReghcDisableIntSupplyWhileExtActive(void);


/*******************************************************************************
* Function Name: Cy_SysPm_ReghcEnableIntSupplyWhileExtActive
****************************************************************************//**
*
*   Internal Active Linear Regulator kept enabled.  See datasheet for minimum
*   PMIC vccd input to prevent OCD.
*
*******************************************************************************/
void Cy_SysPm_ReghcEnableIntSupplyWhileExtActive(void);


/*******************************************************************************
* Function Name: Cy_SysPm_ReghcDisablePmicEnableOutput
****************************************************************************//**
*
* Disables "PMIC enable" output.
*
*******************************************************************************/
void Cy_SysPm_ReghcDisablePmicEnableOutput(void);


/*******************************************************************************
* Function Name: Cy_SysPm_ReghcEnablePmicEnableOutput
****************************************************************************//**
*
* Enables "PMIC enable" output.
*
* \param
* polarity => true - output high, false - output low.
*
*******************************************************************************/
void Cy_SysPm_ReghcEnablePmicEnableOutput(bool polarity);


/*******************************************************************************
* Function Name: Cy_SysPm_ReghcEnablePmicStatusInput
****************************************************************************//**
*
* Enables receiving status from PMIC.
*
* \param
* polarity => true/false -> receiving high/low means abnormal status.
*
*******************************************************************************/
void Cy_SysPm_ReghcEnablePmicStatusInput(bool polarity);

/*******************************************************************************
* Function Name: Cy_SysPm_ReghcDisablePmicStatusInput
****************************************************************************//**
*
* Disables PMIC status input
*
*******************************************************************************/
void Cy_SysPm_ReghcDisablePmicStatusInput(void);

/*******************************************************************************
* Function Name: Cy_SysPm_ReghcSetPmicStatusWaitTime
****************************************************************************//**
*
* Wait count in 4us steps after PMIC status ok. This is used by the hardware
* sequencer to allow additional settling time before disabling the internal
* regulator.
* The LSB is 32 IMO periods which results in a nominal LSB step of 4us.
*
* \param
* waitTime = 0 to 1023 -> (waitTime * 4us) Delay
*
*******************************************************************************/
void Cy_SysPm_ReghcSetPmicStatusWaitTime(uint16_t waitTime);

/*******************************************************************************
* Function Name: Cy_SysPm_ReghcIsConfigured
****************************************************************************//**
*
* Indicates that the REGHC has been configured.
* Do not change REGHC settings after this bit is high.
*
* \return
* true - Configured, false - Not configured
*
*******************************************************************************/
bool Cy_SysPm_ReghcIsConfigured(void);


/*******************************************************************************
* Function Name: Cy_SysPm_ReghcSetConfigured
****************************************************************************//**
*
* Set REGHC is configured. This is required to apply setting before enabling REGHC.
*
*******************************************************************************/
void Cy_SysPm_ReghcSetConfigured(void);

/*******************************************************************************
* Function Name: Cy_SysPm_ReghcDisable
****************************************************************************//**
*
* Disables REGHC.
*
*******************************************************************************/
void Cy_SysPm_ReghcDisable(void);

/*******************************************************************************
* Function Name: Cy_SysPm_ReghcEnable
****************************************************************************//**
*
* Enables REGHC.
*
*******************************************************************************/
void Cy_SysPm_ReghcEnable(void);


/*******************************************************************************
* Function Name: Cy_SysPm_ReghcDisablePmicStatusTimeout
****************************************************************************//**
*
* Disables timeout when waiting for REGHC_PMIC_STATUS_OK.
*
*******************************************************************************/
void Cy_SysPm_ReghcDisablePmicStatusTimeout(void);


/*******************************************************************************
* Function Name: Cy_SysPm_ReghcEnablePmicStatusTimeout
****************************************************************************//**
*
* Enables timeout while waiting for REGHC_PMIC_STATUS_OK==1 when switching to PMIC.
* Timeout expiration triggers reset.
*
* \param
* timeout = 1 - 255 -> (timeout * 128us) delay until reset
*
*******************************************************************************/
void Cy_SysPm_ReghcEnablePmicStatusTimeout(uint8_t timeout);


/*******************************************************************************
* Function Name: Cy_SysPm_ReghcIsEnabled
****************************************************************************//**
*
* Indicates the state of the REGHC enable/disable sequencer.  This bit is only
* valid when REGHC_SEQ_BUSY==0.
*
* \return
* true - Enabled, false - Disabled
*
*******************************************************************************/
bool Cy_SysPm_ReghcIsEnabled(void);


/*******************************************************************************
* Function Name: Cy_SysPm_ReghcIsStatusOk
****************************************************************************//**
*
* Indicates the PMIC status is ok.  This includes polarity adjustment according
* to REGHC_PMIC_STATUS_POLARITY.
*
* \return
* false: PMIC status is not ok or PMIC input is disabled (PMIC_STATUS_INEN == 0)
* true:  PMIC status input is enabled and indicates ok
*
*******************************************************************************/
bool Cy_SysPm_ReghcIsStatusOk(void);


/*******************************************************************************
* Function Name: Cy_SysPm_ReghcIsSequencerBusy
****************************************************************************//**
*
* Indicates whether the REGHC circuit is busy. Indicates the REGHC enable/disable
* sequencer is busy transitioning to/from REGHC.
*
* \return
* true:  REGHC busy
* false: REGHC not busy
*
*******************************************************************************/
bool Cy_SysPm_ReghcIsSequencerBusy(void);


/*******************************************************************************
* Function Name: Cy_SysPm_ReghcDisableVAdj
****************************************************************************//**
*
* Device does not generate VADJ, and it must not be part of the PMIC feedback loop.
* This reduces current by turning off the internal resistor divider that generates
* VADJ.
*
*******************************************************************************/
void Cy_SysPm_ReghcDisableVAdj(void);

/*******************************************************************************
* Function Name: Cy_SysPm_ReghcEnableVAdj
****************************************************************************//**
*
* Device generates VADJ when PMIC is enabled.  This allows the feedback loop to
* compensate for voltage drops in the PCB and package.
*
*******************************************************************************/
void Cy_SysPm_ReghcEnableVAdj(void);

/*******************************************************************************
* Function Name: Cy_SysPm_ReghcDisablePmicInDeepSleep
****************************************************************************//**
*
* Device operates from internal regulators during DEEPSLEEP.  If PMIC is enabled
* at the beginning of the DEEPSLEEP transition, hardware changes to the internal
* regulators and disables the PMIC.
*
*******************************************************************************/
void Cy_SysPm_ReghcDisablePmicInDeepSleep(void);


/*******************************************************************************
* Function Name: Cy_SysPm_ReghcEnablePmicInDeepSleep
****************************************************************************//**
*
* DEEPSLEEP transition does not change PMIC enable.
*
*******************************************************************************/
void Cy_SysPm_ReghcEnablePmicInDeepSleep(void);

/*******************************************************************************
* Function Name: Cy_SysPm_ReghcIsOcdWithinLimits
****************************************************************************//**
*
* Indicates the over-current detector is operating and the current drawn from
* REGHC is within limits.  OCD is only a choice for transistor mode, and it is
* disabled for PMIC mode.
*
* \return
* false: Current measurement exceeds limit or detector is OFF,
* true:  Current measurement within limit
*
*******************************************************************************/
bool Cy_SysPm_ReghcIsOcdWithinLimits(void);


/*******************************************************************************
* Function Name: Cy_SysPm_ReghcIsCircuitEnabledAndOperating
****************************************************************************//**
*
* Indicates the REGHC circuit is enabled and operating.
*
* \return
* false: REGHC Disabled
* true:  REGHC Enabled and Operating
*
*******************************************************************************/
bool Cy_SysPm_ReghcIsCircuitEnabledAndOperating(void);

/*******************************************************************************
* Function Name: Cy_SysPm_ReghcConfigure
****************************************************************************//**
*
* Configures REGHC.
*
* \param mode \ref cy_en_syspm_reghc_mode_t.
*
* \param vadj \ref cy_en_syspm_reghc_vadj_t.
*
* \return
* - CY_SYSPM_SUCCESS - REGHC Configured Successfully
* - CY_SYSPM_TIMEOUT - REGHC Configuration Failed
*
* \note
* This API takes care of the sequence needed for changing from Linear
* Regulator to REGHC with External Transistor, this API do not support changing to
* REGHC with External PMIC.
*
*******************************************************************************/
cy_en_syspm_status_t Cy_SysPm_ReghcConfigure(cy_en_syspm_reghc_mode_t mode, cy_en_syspm_reghc_vadj_t vadj);

/*******************************************************************************
* Function Name: Cy_SysPm_ReghcDeConfigure
****************************************************************************//**
*
* De-Configures REGHC.
*
* \return
* - CY_SYSPM_SUCCESS - REGHC De-Configured Successfully
* - CY_SYSPM_TIMEOUT - REGHC De-Configuration Failed
*
*******************************************************************************/
cy_en_syspm_status_t Cy_SysPm_ReghcDeConfigure(void);


#endif  /* (SRSS_S40E_REGHC_PRESENT == 1u) || (SRSS_S40E_HTREGHC_PRESENT == 1u) || defined (CY_DOXYGEN) */
/** \} group_syspm_functions_reghc */







/**
* \addtogroup group_syspm_functions_callback
* \{
*/


/*******************************************************************************
* Function Name: Cy_SysPm_RegisterCallback
****************************************************************************//**
*
* Registers a new syspm callback.
*
* A callback is a function called after an event in the driver or
* middleware module has occurred. The handler callback API will be executed if
* the specific event occurs. SysPm callbacks are called when changing power
* modes. See \ref cy_stc_syspm_callback_t.
*
* \note The registered callbacks are executed in two orders, based on callback
* mode \ref cy_en_syspm_callback_mode_t. For modes CY_SYSPM_CHECK_READY and
* CY_SYSPM_BEFORE_TRANSITION, the order is same order as callbacks were
* registered.
* For modes CY_SYSPM_AFTER_TRANSITION and CY_SYSPM_CHECK_FAIL, the order is
* reverse as the order callbacks were registered.
*
* \param handler
* The address of the syspm callback structure.
* See \ref cy_stc_syspm_callback_t.
*
* \return
* - True if a callback was registered.
* - False if a callback was not registered.
*
* \note Do not modify the registered structure in run-time.
* \warning After being registered, the SysPm callback structures must be
* allocated during power mode transition.
*
* \funcusage
* \snippet syspm/snippet/main.c snippet_Cy_SysPm_Callback_Func_Declaration
* \snippet syspm/snippet/main.c snippet_Cy_SysPm_Callback_Params_Declaration
* \snippet syspm/snippet/main.c snippet_Cy_SysPm_Callback_Structure_Declaration
* \snippet syspm/snippet/main.c snippet_Cy_SysPm_Callback_Func_Implementation
* \snippet syspm/snippet/main.c snippet_Cy_SysPm_RegisterCallback
*
*******************************************************************************/
bool Cy_SysPm_RegisterCallback(cy_stc_syspm_callback_t *handler);


/*******************************************************************************
* Function Name: Cy_SysPm_UnregisterCallback
****************************************************************************//**
*
* This function unregisters a callback.
*
* The registered callback can be unregistered and the function returns true.
* Otherwise, false is returned.
*
* \param handler The item that should be unregistered.
* See \ref cy_stc_syspm_callback_t.
*
* \return
* - True if callback was unregistered.
* - False if it was not unregistered or no callbacks are registered.
*
* \funcusage
* \snippet syspm/snippet/main.c snippet_Cy_SysPm_UnregisterCallback
*
*******************************************************************************/
bool Cy_SysPm_UnregisterCallback(cy_stc_syspm_callback_t const *handler);


/*******************************************************************************
* Function Name: Cy_SysPm_ExecuteCallback
****************************************************************************//**
*
* The function executes all registered callbacks with provided type and mode.
* \note This low-level function is being used by \ref Cy_SysPm_CpuEnterSleep,
* \ref Cy_SysPm_CpuEnterDeepSleep, \ref Cy_SysPm_SystemEnterHibernate,
* \ref Cy_SysPm_SystemEnterUlp and \ref Cy_SysPm_SystemEnterLp API functions.
* However, it might be also useful as an independent API function in some custom
* applications.
*
* \note The registered callbacks will be executed in order based on
* \ref cy_en_syspm_callback_type_t value. There are two possible callback
* execution orders:
* * From first registered to last registered. This order applies to
*   callbacks with mode CY_SYSPM_CHECK_READY and CY_SYSPM_BEFORE_TRANSITION.
* * Backward flow execution:
*   - From last registered to the first registered. This order applies
*     to callbacks with mode CY_SYSPM_AFTER_TRANSITION.
*   - From last called to the first registered callback. This order applies
*     to callbacks with mode CY_SYSPM_CHECK_FAIL. Note that, the last called
*     callback function  that generated the CY_SYSPM_CHECK_FAIL is skipped when
*     mode CY_SYSPM_CHECK_FAIL. This is because the callback that returns
*     CY_SYSPM_FAIL already knows that it failed and will not take any action
*     that requires correction.
*
* If no callbacks are registered, returns CY_SYSPM_SUCCESS.
*
* \param type
* The callback type. See \ref cy_en_syspm_callback_type_t.
*
* \param mode
* The callback mode. See \ref cy_en_syspm_callback_mode_t.
*
* \return
* - CY_SYSPM_SUCCESS if callback successfully completed or nor callbacks
*   registered.
* - CY_SYSPM_FAIL one of the executed callback(s) returned fail.
*
* \funcusage
* \snippet syspm/snippet/main.c snippet_Cy_SysPm_ExecuteCallback
*
*******************************************************************************/
cy_en_syspm_status_t Cy_SysPm_ExecuteCallback(cy_en_syspm_callback_type_t type, cy_en_syspm_callback_mode_t mode);


/*******************************************************************************
* Function Name: Cy_SysPm_GetFailedCallback
****************************************************************************//**
*
* Reads the result of the callback execution after the power mode functions
* execution.
*
* This function reads the value of the pointer that stores the result of callback
* execution. It takes power mode as the parameter and returns the address of the
* callback configuration structure in the case of failure or NULL in the case of
* success. This address of the failed callback allows finding the callback that
* blocks entering power mode.
*
* \param type
* Power mode for which a callback execution result is required.
*
* \return
* - The address of the callback configuration structure if the callback handler
* function failed.
* - NULL if the callback skipped or executed successfully.
*
* \funcusage
* \snippet syspm/snippet/main.c snippet_Cy_SysPm_GetFailedCallback
*
*******************************************************************************/
cy_stc_syspm_callback_t* Cy_SysPm_GetFailedCallback(cy_en_syspm_callback_type_t type);
/** \} group_syspm_functions_callback */

/**
* \addtogroup group_syspm_functions_power_status
* \{
*/
#if defined (CY_IP_MXS40SRSS)  || defined (CY_IP_MXS22SRSS) || (defined (CY_IP_MXS40SSRSS) && (CY_MXS40SSRSS_VER_1_2 > 0UL)) || defined (CY_DOXYGEN)

#if (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION < 2)) || defined (CY_IP_MXS22SRSS) || (defined (CY_IP_MXS40SSRSS) && (CY_MXS40SSRSS_VER_1_2 > 0UL)) || defined (CY_DOXYGEN)

/*******************************************************************************
* Function Name: Cy_SysPm_IsSystemUlp
****************************************************************************//**
*
* Checks if the system is in ULP mode.
*
* \return
* - True the system is in ULP mode.
* - False the system is is not ULP mode.
*
* \funcusage
* \snippet syspm/snippet/main.c snippet_Cy_SysPm_IsSystemUlp
*
*******************************************************************************/
bool Cy_SysPm_IsSystemUlp(void);
#endif /* (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION < 2)) || defined (CY_IP_MXS22SRSS) || defined (CY_DOXYGEN) */

#if defined (CY_IP_MXS40SRSS) || defined (CY_IP_MXS22SRSS) || (defined (CY_IP_MXS40SSRSS) && (CY_MXS40SSRSS_VER_1_2 > 0UL)) ||defined (CY_DOXYGEN)

/*******************************************************************************
* Function Name: Cy_SysPm_IsSystemLp
****************************************************************************//**
*
* Checks if the system is in LP mode.
*
* \return
* - True the system is in LP mode.
* - False the system is not in LP mode.
*
* \funcusage
* \snippet syspm/snippet/main.c snippet_Cy_SysPm_IsSystemLp
*
*******************************************************************************/
#if !((CY_IP_MXS22SRSS_VERSION == 2) && (CY_IP_MXS22SRSS_VERSION_MINOR == 2))
bool Cy_SysPm_IsSystemLp(void);
#endif
#endif

#if (defined (CY_IP_MXS40SSRSS) && (CY_MXS40SSRSS_VER_1_2 > 0UL)) || defined (CY_DOXYGEN)

/*******************************************************************************
* Function Name: Cy_SysPm_IsSystemMf
****************************************************************************//**
*
* Checks if the system is in MF mode.
*
* \return
* - True the system is in MF mode.
* - False the system is not in MF mode.
*
* \funcusage
* \snippet syspm/snippet/main.c snippet_Cy_SysPm_IsSystemMf
*
*******************************************************************************/
bool Cy_SysPm_IsSystemMf(void);
#endif



#if (defined (CY_IP_MXS40SSRSS) && (CY_MXS40SSRSS_VER_1_2 > 0UL))
/*******************************************************************************
* Function Name: Cy_SysPm_IsSystemOd
****************************************************************************//**
*
* Checks if the system is in OD mode.
*
* \return
* - True the system is in OD mode.
* - False the system is not in OD mode.
*
* \funcusage
* \snippet syspm/snippet/main.c snippet_Cy_SysPm_IsSystemOd
*
*******************************************************************************/
bool Cy_SysPm_IsSystemOd(void);
#endif

#endif



/** \} group_syspm_functions_power_status */


#if defined (CY_IP_MXS40SSRSS) || defined (CY_IP_MXS22SRSS) && (CY_IP_MXS22SRSS_VERSION < 2UL) || defined (CY_DOXYGEN)
/**
* \addtogroup group_syspm_functions_buck
* \{
*/
/*******************************************************************************
* Function Name: Cy_SysPm_CoreBuckStatus
****************************************************************************//**
*
* Get the status of Core Buck Regulator
*
* \return
* Gets enum value of type \ref cy_en_syspm_status_t
*
*******************************************************************************/
__STATIC_INLINE cy_en_syspm_status_t Cy_SysPm_CoreBuckStatus(void)
{
    cy_en_syspm_status_t retVal = CY_SYSPM_TIMEOUT;
    uint32_t syspmCbuckRetry = CY_SYSPM_CBUCK_BUSY_RETRY_COUNT;

    while((_FLD2VAL(SRSS_PWR_CBUCK_STATUS_PMU_DONE, SRSS_PWR_CBUCK_STATUS) == 0U) && (syspmCbuckRetry != 0U))
    {
        syspmCbuckRetry--;
        Cy_SysLib_DelayUs(CY_SYSPM_CBUCK_BUSY_RETRY_DELAY_US);
    }

    if(syspmCbuckRetry != 0UL)
    {
        retVal = CY_SYSPM_SUCCESS;
    }

    return retVal;
}

/*******************************************************************************
* Function Name: Cy_SysPm_CoreBuckSetVoltage
****************************************************************************//**
*
* Set the Core Buck Regulator Voltage
*
* \param voltage
* Pick from \ref cy_en_syspm_core_buck_voltage_t
*
* \return
* see \ref cy_en_syspm_status_t.
*
*******************************************************************************/
__STATIC_INLINE cy_en_syspm_status_t Cy_SysPm_CoreBuckSetVoltage(cy_en_syspm_core_buck_voltage_t voltage)
{
    CY_ASSERT_L2(CY_SYSPM_IS_CORE_BUCK_VOLTAGE_VALID(voltage));

    CY_REG32_CLR_SET(SRSS_PWR_CBUCK_CTL, SRSS_PWR_CBUCK_CTL_CBUCK_VSEL, voltage);

    return Cy_SysPm_CoreBuckStatus();
}

/*******************************************************************************
* Function Name: Cy_SysPm_CoreBuckGetVoltage
****************************************************************************//**
*
* Get the Core Buck Regulator Voltage
*
* \return
* Gets enum value of type \ref cy_en_syspm_core_buck_voltage_t
*
*******************************************************************************/
__STATIC_INLINE cy_en_syspm_core_buck_voltage_t Cy_SysPm_CoreBuckGetVoltage(void)
{
    CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 10.8','Intentional typecast to cy_en_syspm_core_buck_voltage_t enum.');
    return (cy_en_syspm_core_buck_voltage_t)(_FLD2VAL(SRSS_PWR_CBUCK_CTL_CBUCK_VSEL, SRSS_PWR_CBUCK_CTL));
}

/*******************************************************************************
* Function Name: Cy_SysPm_CoreBuckSetMode
****************************************************************************//**
*
* Set the Core Buck Regulator mode
*
* \param mode
* Pick from \ref cy_en_syspm_core_buck_mode_t
*
*******************************************************************************/
__STATIC_INLINE void Cy_SysPm_CoreBuckSetMode(cy_en_syspm_core_buck_mode_t mode)
{
    CY_ASSERT_L2(CY_SYSPM_IS_CORE_BUCK_MODE_VALID(mode));

    CY_REG32_CLR_SET(SRSS_PWR_CBUCK_CTL, SRSS_PWR_CBUCK_CTL_CBUCK_MODE, mode);
}


/*******************************************************************************
* Function Name: Cy_SysPm_CoreBuckGetMode
****************************************************************************//**
*
* Get the Core Buck Regulator Mode
*
* \return
* Gets enum value of type \ref cy_en_syspm_core_buck_mode_t
*
*******************************************************************************/
__STATIC_INLINE cy_en_syspm_core_buck_mode_t Cy_SysPm_CoreBuckGetMode(void)
{
    CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 10.8','Intentional typecast to cy_en_syspm_core_buck_mode_t enum.');
    return (cy_en_syspm_core_buck_mode_t)(_FLD2VAL(SRSS_PWR_CBUCK_CTL_CBUCK_MODE, SRSS_PWR_CBUCK_CTL));
}



#if defined (CY_IP_MXS40SSRSS)  || defined (CY_DOXYGEN)
#if 0

/*******************************************************************************
* Function Name: Cy_SysPm_CoreBuckSetInrushLimit
****************************************************************************//**
*
* Set the Core Buck Inrush Limit
*
* \param inrushLimit
* Pick from \ref cy_en_syspm_core_inrush_limit_t
*
*******************************************************************************/
void Cy_SysPm_CoreBuckSetInrushLimit(cy_en_syspm_core_inrush_limit_t inrushLimit);


/*******************************************************************************
* Function Name: Cy_SysPm_CoreBuckGetInrushLimit
****************************************************************************//**
*
* Get the Core Buck Inrush Limit
*
* \return
* Gets enum value of type \ref cy_en_syspm_core_inrush_limit_t
*
*******************************************************************************/
cy_en_syspm_core_inrush_limit_t Cy_SysPm_CoreBuckGetInrushLimit(void);
#endif //if 0

/*******************************************************************************
* Function Name: Cy_SysPm_CoreBuckConfig
****************************************************************************//**
*
* Configures the Core Buck Regulator
*
* \note
* Core buck voltage and mode are selected based on a voting system by the
* following 5 requesters
* Deepsleep Requester, SDR0 DS Requester, SDR0 Requester, SDR1 Requester and
* Extra Requester.
* The requesters may all request different voltages and CBUCK modes.
* When multiple requesters are used for a profile, the requests are harmonized
* into a composite request according to rules:
*  - The composite CBUCK voltage request is the maximum voltage from all
*    enabled requesters.
*  - The composite CBUCK mode is the maximum setting among all enabled requesters
*    to get the highest mode.
*
* For information about the CBUCK control, refer to the appropriate device TRM.
*
* \param config
* Structure containing the config parameters, \ref cy_stc_syspm_core_buck_params_t
*
* \return
* see \ref cy_en_syspm_status_t.
*
*******************************************************************************/
cy_en_syspm_status_t Cy_SysPm_CoreBuckConfig(cy_stc_syspm_core_buck_params_t *config);

/*******************************************************************************
* Function Name: Cy_SysPm_LdoExtraRequesterConfig
****************************************************************************//**
*
* Configures the Extra Requester for Core Buck Regulator
*
* \note
* The extra requester caters to two special cases:
*   - To temporarily force the system to choose a scratch profile with the
*     settings defined by the extra requester.  This allows other requester
*     settings to be changed without changing the internal setting of an active
*     profile.  This can be used to change the target voltage of an enabled
*     stepdown regulator.
*   - To participate in requester harmonization as an extra requester.
*     This can be used to restrict the composite settings higher than the
*     hardware would normally choose according to the harmonization rules.
*
* For information about the CBUCK control, refer to the appropriate device TRM.
*
* \param extraReqConfig
* Pointer to structure containing the extra requester config parameters,
* \ref cy_stc_syspm_extraReq_params_t
*
* \return
* see \ref cy_en_syspm_status_t.
*
*******************************************************************************/
cy_en_syspm_status_t Cy_SysPm_LdoExtraRequesterConfig(cy_stc_syspm_extraReq_params_t *extraReqConfig);
#endif /* defined (CY_IP_MXS40SSRSS)  || defined (CY_DOXYGEN) */

/** \} group_syspm_functions_buck */
#endif /* defined (CY_IP_MXS40SSRSS) || defined (CY_IP_MXS22SRSS) || defined (CY_DOXYGEN) */

#if defined (CY_IP_MXS22SRSS) || defined (CY_IP_MXS22SRSS) && (CY_IP_MXS22SRSS_VERSION == 2UL)
/*******************************************************************************
* Function Name: Cy_SysPm_MiscLdoStatus
****************************************************************************//**
*
* Get the status of MISCLDO Regulator
*
* \return
* Gets enum value of type \ref cy_en_syspm_status_t
*
*******************************************************************************/
cy_en_syspm_status_t Cy_SysPm_MiscLdoStatus(void);

/*******************************************************************************
* Function Name: Cy_SysPm_MiscLdoConfigure
****************************************************************************//**
*
* Configures the MISCLDO Regulator
*
* \param miscLdoParam
* Structure containing the config parameters, \ref cy_stc_syspm_miscldo_params_t
*
* \return
* see \ref cy_en_syspm_status_t.
*
*******************************************************************************/
cy_en_syspm_status_t Cy_SysPm_MiscLdoConfigure(cy_stc_syspm_miscldo_params_t *miscLdoParam);
#endif

/**
* \addtogroup group_syspm_functions_ldo
* \{
*/
#if (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION < 2)) || (defined (CY_IP_MXS40SSRSS) && (CY_MXS40SSRSS_VER_1_2 > 0UL))

/*******************************************************************************
* Function Name: Cy_SysPm_LdoGetVoltage
****************************************************************************//**
*
* Gets the current output voltage value of the core LDO regulator.
*
* \note The actual device Vccd voltage can be different from the
* nominal voltage because the actual voltage value depends on conditions
* including the load current.
*
* \return
* The nominal output voltage of the LDO. See \ref cy_en_syspm_ldo_voltage_t.
*
* \funcusage
* \snippet syspm/snippet/main.c snippet_Cy_SysPm_VoltageRegulator
*
*******************************************************************************/
cy_en_syspm_ldo_voltage_t Cy_SysPm_LdoGetVoltage(void);

#endif /* (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION < 2)) */

#if defined (CY_IP_MXS40SSRSS) || defined (CY_IP_MXS40SRSS) || defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION >= 2) || defined (CY_DOXYGEN)

/*******************************************************************************
* Function Name: Cy_SysPm_LdoIsEnabled
****************************************************************************//**
*
* Reads the current status of the core LDO regulator.
*
* \return
* - True means the LDO is enabled.
* - False means it is disabled.
*
* \funcusage
* \snippet syspm/snippet/main.c snippet_Cy_SysPm_VoltageRegulator
*
*******************************************************************************/
bool Cy_SysPm_LdoIsEnabled(void);

#endif  /* defined (CY_IP_MXS40SSRSS) || defined (CY_IP_MXS40SRSS) || defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION >= 2) */

#if defined (CY_IP_MXS40SSRSS) || defined (CY_DOXYGEN)
/*******************************************************************************
* Function Name: Cy_SysPm_SdrConfigure
****************************************************************************//**
*
* Configures the SDR(Step Down Regulator)
*
* \note
*  The CBUCK voltage selection must be 60mV higher than the SDR output or the
* regulator output may bypass.
*
* \param sdr
* CY_SYSPM_SDR_0 - for SDR0
* CY_SYSPM_SDR_1 - for SDR1
*
* \param config
* Structure containing the config parameters, \ref cy_stc_syspm_sdr_params_t
*
* \note
* Maintain below conditions when switching th voltages
* High to Low voltage --> Set TRIM's first , Set Voltage next
* Low to High voltage --> Set Voltage first , Set TRIM's next
*
*******************************************************************************/
void Cy_SysPm_SdrConfigure(cy_en_syspm_sdr_t sdr, cy_stc_syspm_sdr_params_t *config);

/*******************************************************************************
* Function Name: Cy_SysPm_SdrSetVoltage
****************************************************************************//**
*
* Set the SDR(Step Down Regulator) Voltage
*
* \note
*  The CBUCK voltage selection must be 60mV higher than the SDR output or the
* regulator output may bypass.
*
* \param sdr
* CY_SYSPM_SDR_0 - for SDR0
* CY_SYSPM_SDR_1 - for SDR1
*
* \param voltage
* Pick from \ref cy_en_syspm_sdr_voltage_t
*
* \note
* Maintain below conditions when switching th voltages
* High to Low voltage --> Set TRIM's first , Set Voltage next
* Low to High voltage --> Set Voltage first , Set TRIM's next
*
*******************************************************************************/
void Cy_SysPm_SdrSetVoltage(cy_en_syspm_sdr_t sdr, cy_en_syspm_sdr_voltage_t voltage);


/*******************************************************************************
* Function Name: Cy_SysPm_SdrGetVoltage
****************************************************************************//**
*
* Get the SDR(Step Down Regulator) Voltage
*
* \param sdr
* CY_SYSPM_SDR_0 - for SDR0
* CY_SYSPM_SDR_1 - for SDR1
*
* \return
* Gets Voltage enum value of type \ref cy_en_syspm_sdr_t
*
*******************************************************************************/
cy_en_syspm_sdr_voltage_t Cy_SysPm_SdrGetVoltage(cy_en_syspm_sdr_t sdr);

/*******************************************************************************
* Function Name: Cy_SysPm_SdrEnable
****************************************************************************//**
*
* Enable the SDR(Step Down Regulator)
*
* \note
* Applicable for only SDR1, whereas SDR0 is always enabled.
*
* \param sdr
* CY_SYSPM_SDR_0 - for SDR0
* CY_SYSPM_SDR_1 - for SDR1
*
* \param enable
* true - enable, false - disable
*
*******************************************************************************/
void Cy_SysPm_SdrEnable(cy_en_syspm_sdr_t sdr, bool enable);

/*******************************************************************************
* Function Name: Cy_SysPm_IsSdrEnabled
****************************************************************************//**
*
* Checks if SDR(Step Down Regulator) is enabled or not.
*
* \param sdr
* CY_SYSPM_SDR_0 - for SDR0
* CY_SYSPM_SDR_1 - for SDR1
*
* \return
* True if enabled, False if disabled.
*
*******************************************************************************/
bool Cy_SysPm_IsSdrEnabled(cy_en_syspm_sdr_t sdr);

/*******************************************************************************
* Function Name: Cy_SysPm_HvLdoConfigure
****************************************************************************//**
*
* Configures the HVLDO Regulator
*
* \param config
* Structure containing the config parameters, \ref cy_stc_syspm_hvldo_params_t
*
*******************************************************************************/
void Cy_SysPm_HvLdoConfigure(cy_stc_syspm_hvldo_params_t *config);

/*******************************************************************************
* Function Name: Cy_SysPm_HvLdoSetVoltage
****************************************************************************//**
*
* Set the HVLDO Regulator Voltage
*
* \param voltage
* Pick from \ref cy_en_syspm_hvldo_voltage_t
*
*******************************************************************************/
void Cy_SysPm_HvLdoSetVoltage(cy_en_syspm_hvldo_voltage_t voltage);

/*******************************************************************************
* Function Name: Cy_SysPm_HvLdoGetVoltage
****************************************************************************//**
*
* Get the HVLDO Regulator Voltage
*
* \return
* Gets Voltage enum value of type \ref cy_en_syspm_hvldo_voltage_t
*
*******************************************************************************/
cy_en_syspm_hvldo_voltage_t Cy_SysPm_HvLdoGetVoltage(void);

/*******************************************************************************
* Function Name: Cy_SysPm_HvLdoEnable
****************************************************************************//**
*
* Enable the HVLDO Regulator
*
* \param enable
* true - enable, false - disable
*
*******************************************************************************/
void Cy_SysPm_HvLdoEnable(bool enable);

/*******************************************************************************
* Function Name: Cy_SysPm_IsHvLdoEnabled
****************************************************************************//**
*
* Checks if HVLDO Regulator is enabled or not.
*
* \return
* True if enabled, False if disabled.
*
*******************************************************************************/
bool Cy_SysPm_IsHvLdoEnabled(void);

#endif  /* defined (CY_IP_MXS40SSRSS) || defined (CY_DOXYGEN) */
/** \} group_syspm_functions_ldo */


/**
* \addtogroup group_syspm_functions_iofreeze
* \{
*/
/*******************************************************************************
* Function Name: Cy_SysPm_IoIsFrozen
****************************************************************************//**
*
* Checks whether IOs are frozen.
*
* \return
* - True if IOs are frozen.
* - False if IOs are unfrozen.
*
* \funcusage
* \snippet syspm/snippet/main.c snippet_Cy_SysPm_IoUnfreeze
*
*******************************************************************************/
__STATIC_INLINE bool Cy_SysPm_IoIsFrozen(void)
{
    #if defined (CY_IP_MXS22SRSS) && (CY_IP_MXS22SRSS_VERSION == 2) && (CY_IP_MXS22SRSS_VERSION_MINOR == 1)
    return (0U != _FLD2VAL(PWRCTL_MAIN_HV_HIBERNATE_PWR_FREEZE_FREEZE, SRSS_PWR_FREEZE));
    #elif defined (CY_IP_MXS22SRSS) && (CY_IP_MXS22SRSS_VERSION == 2)
    return (0U != _FLD2VAL(PWRCTL_MAIN_HV_HIBERNATE_PWR_FREEZE_FREEZE, SRSS_PWR_HIBERNATE));
    #else
    return (0U != _FLD2VAL(SRSS_PWR_HIBERNATE_FREEZE, SRSS_PWR_HIBERNATE));
    #endif
}

/*******************************************************************************
* Function Name: Cy_SysPm_IoUnfreeze
****************************************************************************//**
*
* This function unfreezes the I/O cells that are automatically frozen when
* Hibernate is entered with the call to \ref Cy_SysPm_SystemEnterHibernate().
*
* I/O cells remain frozen after a wakeup from Hibernate mode until the
* firmware unfreezes them by calling this function.
*
* If the firmware must retain the data value on the pin, then the
* value must be read and re-written to the pin's port data register before
* calling this function. Furthermore, the drive mode must be re-programmed
* before the pins are unfrozen. If this is not done, the pin will change to
* the default state the moment the freeze is removed.
*
* Note that I/O cell configuration can be changed while frozen. The new
* configuration becomes effective only after the pins are unfrozen.
*
* \funcusage
* \snippet syspm/snippet/main.c snippet_Cy_SysPm_IoUnfreeze
*
*******************************************************************************/
void Cy_SysPm_IoUnfreeze(void);


#if defined (CY_IP_MXS40SSRSS) || defined (CY_IP_MXS22SRSS) || defined (CY_DOXYGEN)

/*******************************************************************************
* Function Name: Cy_SysPm_DeepSleepIoIsFrozen
****************************************************************************//**
*
* Checks whether IOs are frozen during DEEPSLEEP-RAM/OFF
*
* \return
* - True if IOs are frozen.
* - False if IOs are unfrozen.
*
*******************************************************************************/
bool Cy_SysPm_DeepSleepIoIsFrozen(void);

/*******************************************************************************
* Function Name: Cy_SysPm_DeepSleepIoUnfreeze
****************************************************************************//**
*
* This function unfreezes the I/O cells that are automatically frozen when
* DEEPSLEEP-RAM/OFF is entered.
*
* I/O cells remain frozen after a wakeup from DEEPSLEEP_RAM/OFF mode until the
* firmware unfreezes them by calling this function.
*
* If the firmware must retain the data value on the pin, then the
* value must be read and re-written to the pin's port data register before
* calling this function. Furthermore, the drive mode must be re-programmed
* before the pins are unfrozen. If this is not done, the pin will change to
* the default state the moment the freeze is removed.
*
* Note that I/O cell configuration can be changed while frozen. The new
* configuration becomes effective only after the pins are unfrozen.
*
*******************************************************************************/
void Cy_SysPm_DeepSleepIoUnfreeze(void);

/*******************************************************************************
* Function Name: Cy_SysPm_SystemTransitionInitiate
****************************************************************************//**
*
* Initiates a system power mode transition by disabling the Secure Enclave (SE).
*
* This function is called at the beginning of system power transitions to prepare
* the system by disabling security-sensitive components like the Secure Enclave.
* It must be paired with Cy_SysPm_SystemTransitionFinalize() to complete the
* transition process.
*
* The function handles the operation differently based on the system configuration:
* - In secure enclave enabled device configurations :
*   if called from secure core, it directly disables the SE
*   else if SRF-integrated configurations, it uses the Secure Runtime Framework
*   else returns fail
* - In secure enclave disabled device configurations
*   it returns success as SE is disbaled at boot up time
*
* \return
* - CY_SYSPM_SUCCESS - SE disabled successfully or operation not required
* - CY_SYSPM_FAIL - Failed to disable SE or resource allocation failed
*
* \note
* This function is typically called by the power management framework and
* should be used with caution in application code. Ensure proper pairing
* with Cy_SysPm_SystemTransitionFinalize().
*
*******************************************************************************/
cy_en_syspm_status_t Cy_SysPm_SystemTransitionInitiate(void);

/*******************************************************************************
* Function Name: Cy_SysPm_SystemTransitionFinalize
****************************************************************************//**
*
* Finalizes a system power mode transition by re-enabling the Secure Enclave (SE).
*
* This function is called at the end of system power transitions to restore
* security-sensitive components like the Secure Enclave after the transition
* is complete. It must be paired with Cy_SysPm_SystemTransitionInitiate() for
* proper system transition handling.
*
* The function handles the operation differently based on the system configuration:
* - In secure enclave enabled device configurations :
*   if called from secure core, it directly enables the SE
*   else if SRF-integrated configurations, it uses the Secure Runtime Framework
*   else returns fail
* - In secure enclave disabled device configurations
*   it returns success as disbaling SE is not applicable
*
* \return
* - CY_SYSPM_SUCCESS - SE enabled successfully or operation not required
* - CY_SYSPM_FAIL - Failed to enable SE or resource allocation failed
*
* \note
* This function is typically called by the power management framework and
* should be used with caution in application code. Must be paired with
* Cy_SysPm_SystemTransitionInitiate() for proper operation.
*
*******************************************************************************/
cy_en_syspm_status_t Cy_SysPm_SystemTransitionFinalize(void);

#endif  /* defined (CY_IP_MXS40SSRSS) || defined (CY_IP_MXS22SRSS) || defined (CY_DOXYGEN) */

/** \} group_syspm_functions_iofreeze */



/**
* \addtogroup group_syspm_functions_pmic
* \{
*/

/* The pmic functionality is available for SRSSv1, or SRSSv2+ only if the BACKUP_VBCK IP is present. */
#if ((defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION < 2u)) || \
    ((defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION >= 2u)) && (defined (SRSS_BACKUP_VBCK_PRESENT) && (SRSS_BACKUP_VBCK_PRESENT == 1u)))) || \
    defined (CY_DOXYGEN)
/*******************************************************************************
* Function Name: Cy_SysPm_PmicEnable
****************************************************************************//**
*
* Enable the external PMIC controller that supplies Vddd (if present).
*
* For information about the PMIC controller input and output pins and their
* assignment in specific devices, refer to the appropriate device TRM.
*
* This function is not effective when the PMIC controller is locked. Call
* Cy_SysPm_PmicUnlock() before enabling the PMIC.
*
* \funcusage
* \snippet syspm/snippet/main.c snippet_Cy_SysPm_PmicEnable
*
*******************************************************************************/
void Cy_SysPm_PmicEnable(void);


/*******************************************************************************
* Function Name: Cy_SysPm_PmicDisable
****************************************************************************//**
*
* Disable the external PMIC controller that supplies Vddd (if present).
* This function does not affect the PMIC controller output pin. The PMIC
* controller input pin has programmable polarity to
* enable the external PMIC using different input polarities. The PMIC controller
* is automatically enabled when the input pin polarity and configured polarity
* match. This function is not effective when the active level of PMIC controller
* input pin is equal to the configured PMIC controller polarity.
*
* The function is not effective when the PMIC controller is locked. Call
* Cy_SysPm_PmicUnlock() before enabling the PMIC controller.
*
* \param polarity
* Configures the PMIC controller wakeup input pin to be active low or active
* high. The PMIC will be automatically enabled when the set polarity and the
* active level of PMIC input pin match.
* See \ref cy_en_syspm_pmic_wakeup_polarity_t.
*
* The PMIC controller will be enabled automatically by any of RTC alarm or
* PMIC wakeup events, regardless of the PMIC controller lock state.
*
* \note
* Before disabling the PMIC controller, ensure that PMIC input and PMIC output
* pins are configured correctly to enable expected PMIC operation.
*
* \warning
* The PMIC is enabled automatically when you call Cy_SysPm_PmicLock().
* To keep the external PMIC disabled, the PMIC controller must remain unlocked.
*
* \warning
* Do not call Cy_SysPm_PmicDisable(CY_SYSPM_PMIC_POLARITY_LOW) because this
* is not supported by hardware.
*
* For information about the PMIC controller input and output pins and their
* assignment in the specific devices, refer to the appropriate
* device TRM.
*
* \funcusage
* \snippet syspm/snippet/main.c snippet_Cy_SysPm_PmicDisable
*
*******************************************************************************/
void Cy_SysPm_PmicDisable(cy_en_syspm_pmic_wakeup_polarity_t polarity);


/*******************************************************************************
* Function Name: Cy_SysPm_PmicAlwaysEnable
****************************************************************************//**
*
* Enable the external PMIC controller that supplies Vddd (if present) and force
* active. This is a Write once API. It ensures that the PMIC controller cannot
* be disabled or polarity changed until a next device reset.
*
* For information about the PMIC controller input and output pins and their
* assignment in the specific devices, refer to the appropriate device TRM.
*
* \funcusage
* \snippet syspm/snippet/main.c snippet_Cy_SysPm_PmicAlwaysEnable
*
*******************************************************************************/
void Cy_SysPm_PmicAlwaysEnable(void);


/*******************************************************************************
* Function Name: Cy_SysPm_PmicEnableOutput
****************************************************************************//**
*
* Enables the PMIC controller output pin.
*
* The function is not effective when the PMIC controller is locked. Call
* Cy_SysPm_PmicUnlock() before enabling the PMIC controller.
*
* For information about the PMIC controller output pin and its assignment in
* specific devices, refer to the appropriate device TRM.
*
* \funcusage
* \snippet syspm/snippet/main.c snippet_Cy_SysPm_PmicEnableOutput
*
*******************************************************************************/
void Cy_SysPm_PmicEnableOutput(void);


/*******************************************************************************
* Function Name: Cy_SysPm_PmicDisableOutput
****************************************************************************//**
*
* Disables the PMIC controller output pin.
*
* When the PMIC controller output pin is disabled and is unlocked, the PMIC
* controller output pin can be used for the another purpose.
*
* The function has no effect when the PMIC is locked. Call
* Cy_SysPm_PmicUnlock() before enabling the PMIC.
*
* For information about the PMIC controller output pin and its assignment in
* specific devices, refer to the appropriate device TRM.
*
* \note
* After the PMIC controller output is disabled, the PMIC output pin returns to
* its GPIO configured state.
*
* \warning
* The PMIC controller output is enabled automatically when you call
* Cy_SysPm_PmicLock(). To keep the PMIC controller output disabled, the PMIC
* controller must remain unlocked.
*
* \funcusage
* \snippet syspm/snippet/main.c snippet_Cy_SysPm_PmicDisableOutput
*
*******************************************************************************/
void Cy_SysPm_PmicDisableOutput(void);


/*******************************************************************************
* Function Name: Cy_SysPm_PmicLock
****************************************************************************//**
*
* Locks the PMIC control controller register so that no changes can be made.
* The changes are related to PMIC enabling/disabling and PMIC output pin
* enabling/disabling.
*
* \warning
* The PMIC controller and/or the PMIC output are enabled automatically when
* you call Cy_SysPm_PmicLock(). To keep the PMIC or PMIC controller output
* disabled, the PMIC controller must remain unlocked.
*
* \funcusage
* \snippet syspm/snippet/main.c snippet_Cy_SysPm_PmicLock
*
*******************************************************************************/
void Cy_SysPm_PmicLock(void);


/*******************************************************************************
* Function Name: Cy_SysPm_PmicUnlock
****************************************************************************//**
*
* Unlocks the PMIC control register so that changes can be made. The changes are
* related to the PMIC controller enabling/disabling and PMIC output pin
* enabling/disabling.
*
* \warning
* The PMIC controller and/or the PMIC output are enabled automatically when
* you call Cy_SysPm_PmicLock(). To keep the PMIC controller or PMIC output
* disabled, the PMIC must remain unlocked.
*
* \funcusage
* \snippet syspm/snippet/main.c snippet_Cy_SysPm_PmicEnable
*
*******************************************************************************/
void Cy_SysPm_PmicUnlock(void);


/*******************************************************************************
* Function Name: Cy_SysPm_PmicIsEnabled
****************************************************************************//**
*
* This function returns the status of the PMIC controller.
*
* \return
* - True if the PMIC is enabled.
* - False if the PMIC is disabled.
*
* \funcusage
* \snippet syspm/snippet/main.c snippet_Cy_SysPm_PmicLock
*
*******************************************************************************/
bool Cy_SysPm_PmicIsEnabled(void);


/*******************************************************************************
* Function Name: Cy_SysPm_PmicIsOutputEnabled
****************************************************************************//**
*
* This function returns the status of the PMIC controller output.
*
* \return
* - True if the PMIC output is enabled.
* - False if the PMIC output is disabled.
*
* \funcusage
* \snippet syspm/snippet/main.c snippet_Cy_SysPm_PmicDisable
*
*******************************************************************************/
bool Cy_SysPm_PmicIsOutputEnabled(void);


/*******************************************************************************
* Function Name: Cy_SysPm_PmicIsLocked
****************************************************************************//**
*
* Returns the PMIC controller lock status.
*
* \return
* - True if the PMIC is locked.
* - False if the PMIC is unlocked.
*
* \funcusage
* \snippet syspm/snippet/main.c snippet_Cy_SysPm_PmicLock
*
*******************************************************************************/
bool Cy_SysPm_PmicIsLocked(void);
#endif  /* (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION < 2)) || ((CY_IP_MXS40SRSS_VERSION >= 2u) && (SRSS_BACKUP_VBCK_PRESENT)) */
/** \} group_syspm_functions_pmic */

/**
* \addtogroup group_syspm_functions_backup
* \{
*/
#if defined (CY_IP_MXS40SSRSS) || defined (CY_IP_MXS40SRSS) || defined (CY_DOXYGEN)

/*******************************************************************************
* Function Name: Cy_SysPm_BackupEnableVoltageMeasurement
****************************************************************************//**
*
* This function enables Vbackup supply measurement by the ADC. The function
* connects the Vbackup supply to AMuxBusA. The ADC input can then be connected
* to AMuxBusA. Note that the measured signal is scaled by 10% to allow full
* range measurement by the ADC.
*
* Refer to device TRM for more detail about backup supply modes.  Will do nothing
* if device TRM denotes VBACKUP_MEAS register field is unavailable.
*
* \funcusage
* \snippet syspm/snippet/main.c snippet_Cy_SysPm_BackupEnableVoltageMeasurement
*
*******************************************************************************/
void Cy_SysPm_BackupEnableVoltageMeasurement(void);


/*******************************************************************************
* Function Name: Cy_SysPm_BackupDisableVoltageMeasurement
****************************************************************************//**
*
* The function disables Vbackup supply measurement by the ADC by disconnecting
* the Vbackup supply from AMuxBusA.
*
* Refer to device TRM for more detail about backup supply modes. Will do nothing
* if device TRM denotes VBACKUP_MEAS register field is unavailable.
*
* \funcusage
* \snippet syspm/snippet/main.c snippet_Cy_SysPm_BackupDisableVoltageMeasurement
*
*******************************************************************************/
void Cy_SysPm_BackupDisableVoltageMeasurement(void);

/*******************************************************************************
* Function Name: Cy_SysPm_BackupSuperCapCharge
****************************************************************************//**
*
* Configures the supercapacitor charger circuit.
*
* \param key
* Passes the key to enable or disable the supercapacitor charger circuit.
* See \ref cy_en_syspm_sc_charge_key_t.
*
* \warning
* This function is used only for charging the supercapacitor.
* Do not use this function to charge a battery. Refer to device TRM for more
* detail about backup supply modes.  Will do nothing if device TRM denotes
* EN_CHARGE_KEY register field is unavailable.
*
* \funcusage
* \snippet syspm/snippet/main.c snippet_Cy_SysPm_BackupSuperCapCharge
*
*******************************************************************************/
void Cy_SysPm_BackupSuperCapCharge(cy_en_syspm_sc_charge_key_t key);
#endif


#if defined (CY_IP_MXS40SSRSS) || (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION >= 2) && (defined (SRSS_BACKUP_PRESENT) && (SRSS_BACKUP_PRESENT == 1u))) || (defined (CY_IP_MXS22SRSS) && (CY_IP_MXS22SRSS_VERSION < 2) && defined (BACKUP_BREG_SET0)) || defined (CY_DOXYGEN)
/*******************************************************************************
* Function Name: Cy_SysPm_BackupWordStore
****************************************************************************//**
*
* Stores supported number of words(SRSS_BACKUP_NUM_BREG) in Backup Domain
*
* \param wordIndex
* Offset/Index of Backup Register Region(BREG) to where the data needs
* to be stored.
* Starts with 0, ends with (SRSS_BACKUP_NUM_BREG - 1)
*
* \param wordSrcPointer
* Source address from where the words have to be picked and backed up.
*
* \param wordSize
* Number of words to be stored
*
*******************************************************************************/

void Cy_SysPm_BackupWordStore(uint32_t wordIndex, uint32_t *wordSrcPointer, uint32_t wordSize);

/*******************************************************************************
* Function Name: Cy_SysPm_BackupWordReStore
****************************************************************************//**
*
* Restores supported number of words(SRSS_BACKUP_NUM_BREG) in Backup Domain
*
* \param wordIndex
* Offset/Index of Backup Register Region(BREG) from where the data need
* to be Restored.
* Starts with 0, ends with (SRSS_BACKUP_NUM_BREG - 1)
*
* \param wordDstPointer
* Destination address from where the backed up words have to be written.
*
* \param wordSize
* Number of words to be Restored
*
*******************************************************************************/
void Cy_SysPm_BackupWordReStore(uint32_t wordIndex, uint32_t *wordDstPointer, uint32_t wordSize);
#endif  /* (defined (CY_IP_MXS40SSRSS) || defined (CY_IP_MXS40SRSS)) && (defined (SRSS_BACKUP_PRESENT) && (SRSS_BACKUP_PRESENT == 1u)) || (defined (CY_IP_MXS22SRSS) && (CY_IP_MXS22SRSS_VERSION < 2) && defined (BACKUP_BREG_SET0)) || defined (CY_DOXYGEN) */

#if defined (CY_IP_MXS40SSRSS) || defined (CY_DOXYGEN)
/*******************************************************************************
* Function Name: Cy_SysPm_SetupDeepSleepRAM
****************************************************************************//**
*
* Implements Pre and Post Deepsleep RAM Setup.
*
* \param dsramCheck
* CY_SYSPM_PRE_DSRAM or CY_SYSPM_POST_DSRAM
*
* \param dsramIntState
* Variable to save the interrupt state before and after Deepsleep RAM.
*
* \return
* - CY_SYSPM_SUCCESS - Deepsleep RAM checks are successful
* - CY_SYSPM_CANCELED - Operation was canceled. Call the function again until
*   the function returns CY_SYSPM_SUCCESS.
*
*******************************************************************************/
cy_en_syspm_status_t Cy_SysPm_SetupDeepSleepRAM(cy_en_syspm_dsram_checks_t dsramCheck, uint32_t *dsramIntState);

/*******************************************************************************
* Function Name: Cy_SysPm_CpuEnterRAMOffDeepSleep
****************************************************************************//**
*
* Sets executing CPU to the Deep Sleep mode forceful RAM OFF.
*
* \return
* Entered status, see \ref cy_en_syspm_status_t.
*
* \note
* This API is not a standard PDL interface, it is a custom defined Power
* Management State, not to be used by the customers.
*
*******************************************************************************/
cy_en_syspm_status_t Cy_SysPm_CpuEnterRAMOffDeepSleep(void);

#endif  /* defined (CY_IP_MXS40SSRSS) || defined (CY_DOXYGEN) */
/** \} group_syspm_functions_backup */
/** \} group_syspm_functions */

/** \cond INTERNAL */

/*******************************************************************************
* Backward compatibility macro. The following code is DEPRECATED and must
* not be used in new projects
*******************************************************************************/
#if defined (CY_IP_MXS40SSRSS)
#define CY_SYSPM_HVLDO_VOLTAGE_1_500V        CY_SYSPM_HVLDO_VOLTAGE_1_800V
#define CY_SYSPM_HVLDO_VOLTAGE_1_600V        CY_SYSPM_HVLDO_VOLTAGE_1_900V
#define CY_SYSPM_HVLDO_VOLTAGE_1_700V        CY_SYSPM_HVLDO_VOLTAGE_2_000V

#endif /* defined (CY_IP_MXS40SSRSS) */


#define CY_SYSPM_LPCOMP0_LOW                 CY_SYSPM_HIBERNATE_LPCOMP0_LOW
#define CY_SYSPM_LPCOMP0_HIGH                CY_SYSPM_HIBERNATE_LPCOMP0_HIGH
#define CY_SYSPM_LPCOMP1_LOW                 CY_SYSPM_HIBERNATE_LPCOMP1_LOW
#define CY_SYSPM_LPCOMP1_HIGH                CY_SYSPM_HIBERNATE_LPCOMP1_HIGH
#define CY_SYSPM_HIBALARM                    CY_SYSPM_HIBERNATE_RTC_ALARM
#define CY_SYSPM_HIBWDT                      CY_SYSPM_HIBERNATE_WDT
#define CY_SYSPM_HIBPIN0_LOW                 CY_SYSPM_HIBERNATE_PIN0_LOW
#define CY_SYSPM_HIBPIN0_HIGH                CY_SYSPM_HIBERNATE_PIN0_HIGH
#define CY_SYSPM_HIBPIN1_LOW                 CY_SYSPM_HIBERNATE_PIN1_LOW
#define CY_SYSPM_HIBPIN1_HIGH                CY_SYSPM_HIBERNATE_PIN1_HIGH



typedef cy_en_syspm_hibernate_wakeup_source_t  cy_en_syspm_hib_wakeup_source_t;

/* BWC defines related to hibernation functions */
#define Cy_SysPm_SetHibWakeupSource          Cy_SysPm_SetHibernateWakeupSource
#define Cy_SysPm_ClearHibWakeupSource        Cy_SysPm_ClearHibernateWakeupSource
#define Cy_SysPm_GetIoFreezeStatus           Cy_SysPm_IoIsFrozen

/* BWC defines for Backup related functions */
#define Cy_SysPm_EnableBackupVMeasure        Cy_SysPm_BackupEnableVoltageMeasurement
#define Cy_SysPm_DisableBackupVMeasure       Cy_SysPm_BackupDisableVoltageMeasurement


/* BWC defines for functions related to low power transition */
#define Cy_SysPm_Sleep                       Cy_SysPm_CpuEnterSleep
#define Cy_SysPm_DeepSleep                   Cy_SysPm_CpuEnterDeepSleep
#define Cy_SysPm_Hibernate                   Cy_SysPm_SystemEnterHibernate

#define Cy_SysPm_SleepOnExit                 Cy_SysPm_CpuSleepOnExit

/* BWC defines for functions related to low power transition */
#define Cy_SysPm_EnterLpMode                 Cy_SysPm_EnterLowPowerMode
#define Cy_SysPm_ExitLpMode                  Cy_SysPm_ExitLowPowerMode
#define Cy_SysPm_IsLowPower                  Cy_SysPm_IsSystemUlp

#define Cy_SysPm_EnterLowPowerMode           Cy_SysPm_SystemSetMinRegulatorCurrent
#define Cy_SysPm_ExitLowPowerMode            Cy_SysPm_SystemSetNormalRegulatorCurrent

#define CY_SYSPM_WAKEUP_PIN0_BIT             CY_SYSPM_HIB_WAKEUP_PIN0_POS
#define CY_SYSPM_WAKEUP_PIN1_BIT             CY_SYSPM_HIB_WAKEUP_PIN1_POS
#define CY_SYSPM_WAKEUP_LPCOMP0_BIT          CY_SYSPM_HIB_WAKEUP_LPCOMP0_POS
#define CY_SYSPM_WAKEUP_LPCOMP1_BIT          CY_SYSPM_HIB_WAKEUP_LPCOMP1_POS

#define CY_SYSPM_WAKEUP_LPCOMP0                  CY_SYSPM_HIB_WAKEUP_LPCOMP0_MASK
#define CY_SYSPM_WAKEUP_LPCOMP1                  CY_SYSPM_HIB_WAKEUP_LPCOMP1_MASK
#define CY_SYSPM_WAKEUP_PIN0                     CY_SYSPM_HIB_WAKEUP_PIN0_MASK
#define CY_SYSPM_WAKEUP_PIN1                     CY_SYSPM_HIB_WAKEUP_PIN1_MASK
#define CY_SYSPM_WAKEUP_LPCOMP0_POLARITY_HIGH    CY_SYSPM_HIB_WAKEUP_LPCOMP0_POLARITY_HIGH_MASK
#define CY_SYSPM_WAKEUP_LPCOMP1_POLARITY_HIGH    CY_SYSPM_HIB_WAKEUP_LPCOMP1_POLARITY_HIGH_MASK
#define CY_SYSPM_WAKEUP_PIN0_POLARITY_HIGH       CY_SYSPM_HIB_WAKEUP_PIN0_POLARITY_HIGH_MASK
#define CY_SYSPM_WAKEUP_PIN1_POLARITY_HIGH       CY_SYSPM_HIB_WAKEUP_PIN1_POLARITY_HIGH_MASK

#define CY_SYSPM_PWR_TOKEN_HIBERNATE             HIBERNATE_TOKEN
#define CY_SYSPM_PWR_WAKEUP_HIB_MASK             HIBERNATE_WAKEUP_MASK
#define CY_SYSPM_PWR_RETAIN_HIBERNATE_STATUS     HIBERNATE_RETAIN_STATUS_MASK
#define CY_SYSPM_PWR_SET_HIBERNATE               SET_HIBERNATE_MODE
#define CY_SYSPM_PWR_HIBERNATE_UNLOCK            HIBERNATE_UNLOCK_VAL

/** \endcond */

#ifdef __cplusplus
}
#endif

#endif /* defined (CY_IP_MXS28SRSS) || defined (CY_IP_MXS40SRSS) || defined (CY_IP_MXS40SSRSS) || defined (CY_IP_MXS22SRSS) */

#endif /* CY_SYSPM_H */

/** \} group_syspm */


/* [] END OF FILE */
