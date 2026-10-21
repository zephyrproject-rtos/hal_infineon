/***************************************************************************//**
* \file cy_wdt.h
* \version 1.10
*
*  This file provides constants and parameter values for the WDT driver.
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
* \addtogroup group_wdt
* \{
*
* The Watchdog timer (WDT) has a 16-bit (or 32-bit resolution for PSOC4 HVMS/PA devices)
* free-running up-counter with programmable limit values.
*
* The functions and other declarations used in this driver are in cy_wdt.h.
* You can include cy_pdl.h to get access to all functions
* and declarations in the PDL.
*
* The WDT can issue counter match interrupts, and a device reset if its interrupts are not
* handled. Use the Watchdog timer for two main purposes:
*
* The <b> First use case </b> is recovering from a CPU or firmware failure.
* A timeout period is set up in the Watchdog timer, and if a timeout occurs, the
* device is reset (WRES). <br>
* The <b>Second use case</b> is to generate periodic interrupts.
*
* You can use the WDT to generate periodic interrupts.
* However, the \ref group_sysclk_ilo (or \ref group_sysclk_lf for PSOC4 HVMS/PA devices)
* is the clock source for the WDT, so its accuracy should be considered.
* Use the ILO compensation (\ref Cy_SysClk_IloCompensate()) technique to increase ILO accuracy or
* use \ref group_sysclk_calclk together with \ref group_sysclk_trim technique
* to increase \ref group_sysclk_lf accuracy for PSOC4 HVMS/PA devices.\n
* Other options may provide a more precise periodic interrupt.
* See \ref group_wdc (using \ref group_sysclk_wco as clock source) or
* \ref group_arm_system_timer (in active power mode).
*
* \note The \ref group_wdc and \ref group_sysclk_wco not applicable for PSOC4 HVMS/PA.
*
* A "reset cause" register exists, and the firmware should check this register
* at a start-up \ref Cy_SysLib_GetResetReason().
* An appropriate action can be taken if a WRES reset is detected.
*
* The user's firmware periodically resets the timeout period (clears or "feeds"
* the watchdog) before a timeout occurs. If the firmware fails to do so, that is
* considered to be a CPU crash or a firmware failure, and the reason for a
* device reset.
* The WDT can generate an interrupt instead of a device reset. The Interrupt
* Service Routine (ISR) can handle the interrupt either as a periodic interrupt,
* or as an early indication of a firmware failure and respond accordingly.
* However, it is not recommended to use the WDT for periodic interrupt
* generation. The \ref group_wdc can be used to generate
* periodic interrupts if such are presented in the device.
*
* <b> Functional Description </b>
*
* The WDT generates an interrupt when the count value in the counter equals the
* configured match value.
*
* Note that the counter is not reset on a match. In such case the WDT
* reset period is:
* WDT_Reset_Period = ILO_Period * (2*2^(16-IgnoreBits) + MatchValue);
* When the counter reaches a match value, it generates an interrupt and then
* keeps counting up until it overflows and rolls back to zero and reaches the
* match value again, at which point another interrupt is generated.
*
* To use a WDT to generate a periodic interrupt, the match value should be
* incremented in the ISR. As a result, the next WDT interrupt is generated when
* the counter reaches a new match value.
*
* You can also reduce the entire WDT counter period by
* specifying the number of most significant bits that are ignored in the WDT
* counter. For example, if the \ref Cy_WDT_SetIgnoreBits() function is called with
* parameter 3, the WDT counter becomes a 13-bit free-running up-counter.
*
* <b> PSOC4 HVMS/PA Functional Design Details </b>
*
* For PSOC4 HVMS/PA devices, the WDT can be configured to act on different counter limits
* where a reset is triggered if the watchdog is not serviced before the upper limit.
* In the window mode, a reset is triggered if the servicing occurs before the lower limit
* is reached. The warning limit triggers an interrupt to request servicing.
* Each of these actions can be activated independently.
* The WDT is enabled and specific registers are locked by default. An unlocking sequence
* is required to prevent accidental accesses. The WDT operates in active, sleep, and deepsleep modes.
* After a WDT reset the device returns to active mode.
*
* \image html basic_wdt_functional_diagram.png "PSOC4 HVMS/PA Basic WDT functional diagram"
*
* <b> Register Locking </b>
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* You can prevent accidental corruption of the WDT configuration by calling
* the \ref Cy_WDT_Lock() function. When the WDT is locked, any writing to the WDT_*,
* CLK_ILO_CONFIG, CLK_SELECT.LFCLK_SEL, and CLK_TRIM_ILO_CTL registers is
* ignored.
* Call the \ref Cy_WDT_Unlock() function to allow registers modification, mentioned
* above.
*
* \note The WDT lock state is not retained during system Deep Sleep. After
* the wakeup from system Deep Sleep the WDT is locked.
*
* <b> Power Modes </b>
*
* WDT can operate in all possible low power modes.
*
* In CPU Active mode, an interrupt request from the WDT is sent to the
* CPU. In CPU Sleep, CPU Deep Sleep mode, the CPU subsystem
* is powered down, so the interrupt request from the WDT is sent directly to the
* WakeUp Interrupt Controller (WIC) which will then wake up the CPU. The
* CPU then acknowledges the interrupt request and executes the ISR.
*
* <b> Clock Source </b>
*
* The WDT is clocked by the ILO (or \ref group_sysclk_lf for PSOC4 HVMS/PA devices).
* The WDT must be disabled before disabling the ILO (or \ref group_sysclk_lf).
* Need to consider ILO (or \ref group_sysclk_lf) accuracy while configuring WDT intervals to
* make sure that unwanted device resets do not occur on some devices.
*
* Refer to the device datasheet for more information on the oscillator accuracy.
*
* <b> Clearing WDT </b>
*
* The ILO (or \ref group_sysclk_lf) clock is asynchronous to the SysClk. Therefore it generally
* takes three ILO (or \ref group_sysclk_lf) cycles for WDT register changes to come into effect.
* It is important to remember that a WDT should be cleared at least <b>four cycles</b>
* (3 + 1 for sure) before a timeout occurs, especially when small
* match values / low-toggle bit numbers are used.
*
* \warning It may happen that a WDT reset can be generated
* faster than a device start-up. To prevent this, calculate the
* start-up time and WDT reset time. The WDT reset time should be always greater
* than device start-up time.
*
* <b> Reset Detection </b>
*
* Use the \ref Cy_SysLib_GetResetReason() function to detect whether the WDT has
* triggered a device reset.
*
* <b> Interrupt Configuration </b>
*
* If the WDT is configured to generate an interrupt, pending
* interrupts must be cleared within the ISR (otherwise, the interrupt will be
* generated continuously).
* A pending interrupt to the WDT block must be cleared by calling the
* \ref Cy_WDT_ClearInterrupt() function. The call to the function will clear the
* unhandled WDT interrupt counter.
*
* Use the WDT ISR as a timer to trigger certain actions
* and to change a next WDT match or limit value.
*
* Ensure that the interrupts from the WDT are passed to the CPU to avoid
* unregistered interrupts. Unregistered WDT interrupts result in a continuous
* device reset. To avoid this, call \ref Cy_WDT_UnmaskInterrupt().
* After that, call the WDT API functions for interrupt
* handling/clearing.
*
* It is not recommended to reset the watchdog counter in the WDT interrupt
* service routine (ISR), if WDT is being used as a reset source to protect
* the system against crashes. If necessary, use the warning interrupt to set a flag
* in the ISR. Local processing loops can observe that flag and break out of their loop.
* This allows the main loop to reach the servicing code
* (and clear the flag for the next pass through the main loop).
*
* \section group_wdt_configuration Configuration Considerations
*
* To start the WDT, make sure that ILO (or \ref group_sysclk_lf) is enabled.
* After the ILO (or \ref group_sysclk_lf) is enabled, ensure that the watchdog reset
* is disabled by calling the \ref Cy_WDT_Disable() function. Set the WDT match
* value by calling \ref Cy_WDT_SetMatch() with the required match value. If needed,
* set the ignore bits for reducing the WDT counter period by calling
* \ref Cy_WDT_SetIgnoreBits() function. After the WDT configuration is set,
* call \ref Cy_WDT_Enable().
*
* \note The watchdog counter is a free-running counter that cannot be disabled.
*
* \note Enable a WDT if the power supply can produce
* sudden brownout events that may compromise the CPU functionality. This
* ensures that the system can recover after a brownout.
*
* When the WDT is used to protect against system crashes, the
* WDT interrupt should be cleared by a portion of the code that is not directly
* associated with the WDT interrupt.
* Otherwise, it is possible that the main firmware loop has crashed or is in an
* endless loop, but the WDT interrupt vector continues to operate and service
* the WDT. The user should:
* * Feed the watchdog by clearing the interrupt bit regularly in the main body
* of the firmware code.
*
* * Guarantee that the interrupt is cleared at least once every WDT period.
*
* * Use the WDT ISR only as a timer to trigger certain actions and to change the
* next match value.
*
* \section group_wdt_section_use_case_1 Use case 1. Configure the WDT for periodic interrupt.
*
* Set parameters of the WDT.
*
* \snippet wdt_snippet.c snippet_WDT_useCase_1_config_data
*
* Create an interrupt config structure and interrupt handler.
*
* \snippet wdt_snippet.c snippet_WDT_useCase_1_Isr_config
*
* Hook the interrupt service routine and enable interrupt than config the WDT.
*
* \snippet wdt_snippet.c snippet_WDT_useCase_1_config
*
* \note Additionally, global interrupts should be enabled.
*
* \note Before the WDT initialization, ensure that the WDT clock source is enabled.
* Refer to \ref group_sysclk_ilo of SysClk driver documentation.
*
* \section group_wdt_section_use_case_2 Use case 2. Configure the WDT for the system reset generation after a configurable interval.
*
* In this case, the WDT resets every third WDT event of the system(1.2287s at ILO 40kHz).
*
* As part of this code, the snippet uses the formula from the <b> Functional Description </b>.
*
* \snippet wdt_snippet.c snippet_WDT_useCase_2_config_data
* \snippet wdt_snippet.c snippet_WDT_useCase_2_config
*
* \section group_wdt_section_use_case_3_srsshv Use case 3. The WDT counter in interrupt mode.
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* The timing diagram below shows the behavior of the WDT counter in interrupt mode. LOWER
* and UPPER actions are disabled. An interrupt is issued each time the counter matches the
* WARN_LIMIT. The interrupt period is calculated by 2^32 x LFCLK clock cycles.
* The WDT counter could be cleared (serviced) in two ways:
* * manually by calling \ref Cy_WDT_SetService() function
* * automatically by calling \ref Cy_WDT_SetAutoService() function
*
* \image html wdt_interrupt_mode_operation_diagram.png "WDT counter operation with WARN interrupt only"
*
* Set parameters of the WDT.
*
* \snippet wdt_snippet.c snippet_WDT_useCase_3_config_data
*
* Create an interrupt config structure and interrupt handler.
*
* \snippet wdt_snippet.c snippet_WDT_useCase_3_Isr_config
*
* Hook the interrupt service routine and enable interrupt than config the WDT.
*
* \snippet wdt_snippet.c snippet_WDT_useCase_3_config
*
* \note Additionally, global interrupts should be enabled.
*
* \note Before the WDT initialization, ensure that the WDT clock source is enabled.
* Refer to \ref group_sysclk_lf of SysClk driver documentation.
*
* \section group_wdt_section_use_case_4 Use case 4. Configure the WDT counter in window mode.
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* The timing diagram below shows the behavior of the WDT counter in window mode.
* The timing diagram shows all scenarios of the WDT operation while LOWER_ACTION,
* WARN_ACTION, and UPPER_ACTION are enabled.
* * Counter is serviced between LOWER_LIMIT and WARN_LIMIT: This is the regular
* behavior of the WDT. No WARN interrupt is issued and no RESET is done.
* * Counter is serviced between WARN_LIMIT and UPPER_LIMIT: The service is done late,
* a WARN interrupt is issued but no RESET is done.
* * Counter is not serviced at all: WARN interrupt is issued but the SERVICE bit
* is not set. When the counter reaches the UPPER_LIMIT a reset is executed.
* * Counter is serviced before the LOWER_LIMIT is reached: The counter is serviced
* too early; a reset is executed because the counter is cleared outside of the window.
*
* \image html wdt_window_mode_operation_diagram.png "WDT counter operation in window mode"
*
* \note The timing diagram illustrates the different scenarios with or without servicing
* the watchdog counter. It does not consider the WDT configuration, especially after a reset.
*
* \section group_wdt_section_more_information More Information
*
* For more information on the WDT peripheral, refer to the technical reference
* manual (TRM).
*
* \section group_wdt_changelog Changelog
* <table class="doxtable">
*   <tr><th>Version</th><th>Changes</th><th>Reason for Change</th></tr>
*   <tr>
*     <td>1.10</td>
*     <td>Added support for PSOC4 HVMS/PA platform.\n
*     Updated APIs to incorporate PSOC4 HVMS/PA platform configuration.\n
*     Documentation enhancement. Provided code snippets.</td>
*     <td>New device support.</td>
*   </tr>
*   <tr>
*     <td>1.0.3</td>
*     <td>Updated code snippets.</td>
*     <td>Documentation enhancement.</td>
*   </tr>
*   <tr>
*     <td>1.0.2</td>
*     <td>Update the paths to the code snippets.</td>
*     <td>PDL structure update.</td>
*   </tr>
*   <tr>
*     <td>1.0.1</td>
*     <td>Code snippets added.</td>
*     <td>Documentation enhancement.</td>
*   </tr>
*   <tr>
*     <td>1.0</td>
*     <td>Initial version</td>
*     <td></td>
*   </tr>
* </table>
*
* \defgroup group_wdt_macros Macros
* \defgroup group_wdt_enums Enumerated Types
* \defgroup group_wdt_functions Functions
*
*/

#if !defined(CY_WDT_H)
#define CY_WDT_H

#include <stdint.h>
#include <stdbool.h>
#include "cy_device_headers.h"
#include "cy_device.h"
#include "cy_syslib.h"

#if defined(__cplusplus)
extern "C" {
#endif


/*******************************************************************************
*       Function Constants
*******************************************************************************/

/**
* \addtogroup group_wdt_macros
* \{
*/

/** The driver major version */
#define CY_WDT_DRV_VERSION_MAJOR                       1

/** The driver minor version */
#define CY_WDT_DRV_VERSION_MINOR                       10

#if defined(CY_IP_S8SRSSLT)
    /** The WDT default match value */
    #define CY_SRSS_WDT_DEFAULT_MATCH_VALUE                (4096UL)

    /** The WDT default disable value */
    #define CY_SRSS_WDT_DISABLE_VALUE                      (0xACED8865UL)

    /** The WDT default enable value */
    #define CY_SRSS_WDT_ENABLE_VALUE                       (0UL)

    /** The default match value of the WDT ignore bits */
    #define CY_SRSS_WDT_DEFAULT_IGNORE_BITS                (0UL)
#endif /* CY_IP_S8SRSSLT */

#if defined(CY_IP_M0S8SRSSHV)
    /** The WDT default LOWER_LIMIT value */
    /**
    * \note This Macro is applicable to PSOC4 HVMS/PA only.
    **/
    #define CY_WDT_DEFAULT_LOWER_LIMIT                     (0U)

    /** The WDT default UPPER_LIMIT value */
    /**
    * \note This Macro is applicable to PSOC4 HVMS/PA only.
    **/
    #define CY_WDT_DEFAULT_UPPER_LIMIT                     (0x8000U) /* 32768 (~1 sec when clk_lf = 32KHz) */

    /** The WDT default WARN_LIMIT value */
    /**
    * \note This Macro is applicable to PSOC4 HVMS/PA only.
    **/
    #define CY_WDT_DEFAULT_WARN_LIMIT                     (0U)
#endif /* CY_IP_M0S8SRSSHV */

/** The WDT driver identifier */
#define CY_WDT_ID                                      CY_PDL_DRV_ID(0x34U)

/** \} group_wdt_macros */

/** \cond Internal */
#if defined(CY_IP_S8SRSSLT)
    /** The WDT maximum match value */
    #define WDT_MAX_MATCH_VALUE                      (SRSSLT_WDT_MATCH_MATCH_Msk >> SRSSLT_WDT_MATCH_MATCH_Pos)

    /** The WDT maximum match value */
    #define WDT_MAX_IGNORE_BITS                      (SRSSLT_WDT_MATCH_IGNORE_BITS_Msk >> SRSSLT_WDT_MATCH_IGNORE_BITS_Pos)

    /* Internal macro to validate match value */
    #define CY_WDT_IS_MATCH_VALID(match)             ((match) <= WDT_MAX_MATCH_VALUE)

    /* Internal macro to validate match value */
    #define CY_WDT_IS_IGNORE_BITS_VALID(bitsNum)     ((bitsNum) <= WDT_MAX_IGNORE_BITS)
#endif /* CY_IP_S8SRSSLT */

#if defined(CY_IP_M0S8SRSSHV)
    /* Internal macro value to be loaded to unlock the WDT */
    #define CY_WDT_UNLOCK_VALUE_0                          (1UL)

    /* Internal macro value to be loaded to unlock the WDT */
    #define CY_WDT_UNLOCK_VALUE_1                          (2UL)

    /* Internal macro value to be loaded to lock the WDT */
    #define CY_WDT_LOCK_VALUE                              (3UL)
#endif /* CY_IP_M0S8SRSSHV */

/** \endcond */


/*******************************************************************************
*        Enumerated Types
*******************************************************************************/
/**
* \addtogroup group_wdt_enums
* \{
*/
#if defined(CY_IP_M0S8SRSSHV)
    /** The wdt lower/upper limit actions. */
    /**
    * \note This Enum is applicable to PSOC4 HVMS/PA only.
    **/
    typedef enum
    {
        CY_WDT_LOW_UPPER_LIMIT_ACTION_NONE, /**< Do nothing */
        CY_WDT_LOW_UPPER_LIMIT_ACTION_RESET /**< Trigger a reset */
    } cy_en_wdt_lower_upper_action_t;

    /** The wdt lower/upper limit actions. */
    /**
    * \note This Enum is applicable to PSOC4 HVMS/PA only.
    **/
    typedef enum
    {
        CY_WDT_WARN_ACTION_NONE, /**< Do nothing */
        CY_WDT_WARN_ACTION_INT   /**< Trigger an interrupt */
    } cy_en_wdt_warn_action_t;

    /** The wdt Disable/Enable Macros. */
    /**
    * \note This Enum is applicable to PSOC4 HVMS/PA only.
    **/
    typedef enum
    {
        CY_WDT_DISABLE,
        CY_WDT_ENABLE
    } cy_en_wdt_enable_t;
#endif /* CY_IP_M0S8SRSSHV */
/** \} group_wdt_enums */

/** \cond */
#define CY_WDT_IS_LOW_UPPER_ACTION_VALID(action) \
    ((CY_WDT_LOW_UPPER_LIMIT_ACTION_NONE == action) || \
    (CY_WDT_LOW_UPPER_LIMIT_ACTION_RESET == action))

#define CY_WDT_IS_WARN_ACTION_VALID(action) \
    ((CY_WDT_WARN_ACTION_NONE == action) || \
    (CY_WDT_WARN_ACTION_INT == action))

#define CY_WDT_IS_ENABLE_DISABLE_VALID(action) \
    ((CY_WDT_DISABLE == action) || \
    (CY_WDT_ENABLE == action))
/** \endcond */


/*******************************************************************************
*        Function Prototypes
*******************************************************************************/
/**
* \addtogroup group_wdt_functions
* \{
*/
void Cy_WDT_Init(void);
__STATIC_INLINE void Cy_WDT_Enable(void);
__STATIC_INLINE bool Cy_WDT_IsEnabled(void);
__STATIC_INLINE void Cy_WDT_Disable(void);
__STATIC_INLINE uint32_t Cy_WDT_GetCount(void);

#if defined(CY_IP_S8SRSSLT)
    void Cy_WDT_SetMatch(uint32_t match);
    __STATIC_INLINE uint32_t Cy_WDT_GetMatch(void);
    void Cy_WDT_SetIgnoreBits(uint32_t bitsNum);
    __STATIC_INLINE uint32_t Cy_WDT_GetIgnoreBits(void);
#endif /* CY_IP_S8SRSSLT */

__STATIC_INLINE void Cy_WDT_MaskInterrupt(void);
__STATIC_INLINE void Cy_WDT_UnmaskInterrupt(void);
__STATIC_INLINE bool Cy_WDT_GetInterruptStatusMasked(void);
void Cy_WDT_ClearInterrupt(void);
__STATIC_INLINE void Cy_WDT_ClearWatchdog(void);

#if defined(CY_IP_M0S8SRSSHV)
    __STATIC_INLINE void Cy_WDT_Lock(void);
    __STATIC_INLINE void Cy_WDT_Unlock(void);
    __STATIC_INLINE bool Cy_WDT_Locked(void);
    __STATIC_INLINE void Cy_WDT_SetLowerLimit(uint32_t match);
    __STATIC_INLINE void Cy_WDT_SetUpperLimit(uint32_t match);
    __STATIC_INLINE void Cy_WDT_SetWarnLimit(uint32_t match);
    __STATIC_INLINE void Cy_WDT_SetLowerAction(cy_en_wdt_lower_upper_action_t action);
    __STATIC_INLINE void Cy_WDT_SetUpperAction(cy_en_wdt_lower_upper_action_t action);
    __STATIC_INLINE void Cy_WDT_SetWarnAction(cy_en_wdt_warn_action_t action);
    __STATIC_INLINE void Cy_WDT_SetAutoService(cy_en_wdt_enable_t enable);
    __STATIC_INLINE void Cy_WDT_SetDeepSleepPause(cy_en_wdt_enable_t enable);
    __STATIC_INLINE void Cy_WDT_SetDebugRun(cy_en_wdt_enable_t enable);
    __STATIC_INLINE void Cy_WDT_SetService(void);
    __STATIC_INLINE void Cy_WDT_SetCount(uint32_t count);
    __STATIC_INLINE void Cy_WDT_SetInterrupt(void);
#endif /* CY_IP_M0S8SRSSHV */


/*******************************************************************************
* Function Name: Cy_WDT_Enable
****************************************************************************//**
*
* Enables watchdog timer reset generation.
*
* \warning For PSOC4 HVMS/PA the Watchdog timer should be unlocked before
* being enabled. Call the \ref Cy_WDT_Unlock() API to unlock the WDT.
*
* \note May take up to three \ref group_sysclk_lf cycles to take effect.
* Do not enter DeepSleep if the WDT enabling doesn't take effect.
* It can be done by waiting until \ref Cy_WDT_IsEnabled() returns true.
*
* \funcusage
* \snippet wdt_snippet.c snippet_WDT_Enable
*
*******************************************************************************/
__STATIC_INLINE void Cy_WDT_Enable(void)
{
#if defined(CY_IP_S8SRSSLT)
    SRSSLT_WDT_DISABLE_KEY = CY_SRSS_WDT_ENABLE_VALUE;
#elif defined(CY_IP_M0S8SRSSHV)
    CY_ASSERT_L2(false == Cy_WDT_Locked());
    WDT->CTL = WDT_CTL_ENABLE_Msk;
#endif /* CY_IP_S8SRSSLT */
}


/*******************************************************************************
* Function Name: Cy_WDT_IsEnabled
****************************************************************************//**
*
* Returns the WDT enable/disable state.
*
* \return
* The WDT state.
* * true  : Counter is enabled (counting up).
* * false : Counter is disabled (not clocked).
*
* \funcusage
* \snippet wdt_snippet.c snippet_WDT_Enable
*
*******************************************************************************/
__STATIC_INLINE bool Cy_WDT_IsEnabled(void)
{
#if defined(CY_IP_S8SRSSLT)
    return(CY_SRSS_WDT_DISABLE_VALUE != SRSSLT_WDT_DISABLE_KEY);
#elif defined(CY_IP_M0S8SRSSHV)
    return (_FLD2BOOL(WDT_CTL_ENABLED, WDT->CTL));
#endif /* CY_IP_S8SRSSLT */
}


/*******************************************************************************
* Function Name: Cy_WDT_Disable
****************************************************************************//**
*
* Disables the WDT reset generation.
*
* \warning For PSOC4 HVMS/PA the Watchdog timer should be unlocked before
* being disabled. Call the \ref Cy_WDT_Unlock() API to unlock the WDT.
*
* \note When disable the WDT, the counter is cleared.
*
* \note May take up to three \ref group_sysclk_lf cycles to take effect.
* It can be done by waiting until \ref Cy_WDT_IsEnabled() returns false.
*
* \funcusage
* \snippet wdt_snippet.c snippet_WDT_Disable
*
*******************************************************************************/
__STATIC_INLINE void Cy_WDT_Disable(void)
{
#if defined(CY_IP_S8SRSSLT)
    SRSSLT_WDT_DISABLE_KEY = CY_SRSS_WDT_DISABLE_VALUE;
#elif defined(CY_IP_M0S8SRSSHV)
    CY_ASSERT_L2(false == Cy_WDT_Locked());
    /* 
     * SRSSHV prevents writing control and configuration registers related 
     * to WDT when LOCK register is not equal to 0. Requires at least two 
     * different writes to unlock. The CTL register is then set to 0 to disable
     * the WDT.
     */
    WDT->CTL &= ~(WDT_CTL_ENABLE_Msk);
#endif /* CY_IP_S8SRSSLT */
}

#if defined(CY_IP_S8SRSSLT)
/*******************************************************************************
* Function Name: Cy_WDT_GetMatch
****************************************************************************//**
*
* Reads the WDT counter match comparison value.
*
* \return The counter match value.
*
* \note Not applicable for PSOC4 HVMS/PA.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_WDT_GetMatch(void)
{
    return (_FLD2VAL(SRSSLT_WDT_MATCH_MATCH, SRSSLT_WDT_MATCH));
}
#endif /* CY_IP_S8SRSSLT */

/*******************************************************************************
* Function Name: Cy_WDT_GetCount
****************************************************************************//**
*
* Reads the current WDT counter value.
*
* \return A live counter value.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_WDT_GetCount(void)
{
#if defined(CY_IP_S8SRSSLT)
    return (_FLD2VAL(SRSSLT_WDT_COUNTER_COUNTER, SRSSLT_WDT_COUNTER));
#elif defined(CY_IP_M0S8SRSSHV)
    return (_FLD2VAL(WDT_CNT_CNT, WDT->CNT));
#endif /* CY_IP_S8SRSSLT */
}

#if defined(CY_IP_S8SRSSLT)
/*******************************************************************************
* Function Name: Cy_WDT_GetIgnoreBits
****************************************************************************//**
*
* Reads the number of the most significant bits of the Watchdog timer that are
* not checked against the match.
*
* \return The number of the most significant bits.
*
* \note Not applicable for PSOC4 HVMS/PA.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_WDT_GetIgnoreBits(void)
{
    return (_FLD2VAL(SRSSLT_WDT_MATCH_IGNORE_BITS, SRSSLT_WDT_MATCH));
}
#endif /* CY_IP_S8SRSSLT */

/*******************************************************************************
* Function Name: Cy_WDT_MaskInterrupt
****************************************************************************//**
*
* After masking interrupts from the WDT, they are not passed to the CPU.
* This function does not disable the WDT-reset generation.
*
*******************************************************************************/
__STATIC_INLINE void Cy_WDT_MaskInterrupt(void)
{
#if defined(CY_IP_S8SRSSLT)
    SRSS_SRSS_INTR_MASK &= ~SRSSLT_SRSS_INTR_MASK_WDT_MATCH_Msk;
#elif defined(CY_IP_M0S8SRSSHV)
    WDT->INTR_MASK &= ~(WDT_INTR_MASK_WDT_Msk);
#endif /* CY_IP_S8SRSSLT */
}

/*******************************************************************************
* Function Name: Cy_WDT_UnmaskInterrupt
****************************************************************************//**
*
* After unmasking interrupts from the WDT, they are passed to CPU.
* This function does not impact the reset generation.
*
*******************************************************************************/
__STATIC_INLINE void Cy_WDT_UnmaskInterrupt(void)
{
#if defined(CY_IP_S8SRSSLT)
    SRSS_SRSS_INTR_MASK |= SRSSLT_SRSS_INTR_MASK_WDT_MATCH_Msk;
#elif defined(CY_IP_M0S8SRSSHV)
    WDT->INTR_MASK = WDT_INTR_MASK_WDT_Msk;
#endif /* CY_IP_S8SRSSLT */
}

/*******************************************************************************
* Function Name: Cy_WDT_GetInterruptStatusMasked
****************************************************************************//**
*
* Returns an interrupt request register masked by an interrupt mask.
* Returns the result of the bitwise AND operation between the corresponding
* interrupt request and mask bits.
*
* \return
* The masked interrupt status.
* * true  : Masked interrupt occurs.
* * false : No Masked interrupt occurs.
*
* \note For PSOC4 HVMS/PA, due to internal synchronization, it takes up to 8 SYSCLK
* cycles to read from this register and during this time AHB bus is stalled.
*
*******************************************************************************/
__STATIC_INLINE bool Cy_WDT_GetInterruptStatusMasked(void)
{
#if defined(CY_IP_S8SRSSLT)
    return (_FLD2BOOL(SRSSLT_SRSS_INTR_MASK_WDT_MATCH,SRSS_SRSS_INTR_MASK) && \
            _FLD2BOOL(SRSSLT_SRSS_INTR_WDT_MATCH,SRSS_SRSS_INTR));
#elif defined(CY_IP_M0S8SRSSHV)
    return _FLD2BOOL(WDT_INTR_MASKED_WDT, WDT->INTR_MASKED);
#endif /* CY_IP_S8SRSSLT */
}


/*******************************************************************************
* Function Name: Cy_WDT_ClearWatchdog
****************************************************************************//**
*
* Clears ("feeds") the watchdog, to prevent a XRES device reset.
* This function simply call \ref Cy_WDT_ClearInterrupt() function.
*
*******************************************************************************/
__STATIC_INLINE void Cy_WDT_ClearWatchdog(void)
{
    Cy_WDT_ClearInterrupt();
}


#if defined(CY_IP_M0S8SRSSHV)
/*******************************************************************************
* Function Name: Cy_WDT_Lock
****************************************************************************//**
*
* Locks out configuration changes to the Watchdog Timer register.
*
* After this function is called, the WDT configuration cannot be changed until
* \ref Cy_WDT_Unlock() is called.
*
* \warning
* The WDT lock state is not retained during system Deep Sleep. After the wakeup
* from system Deep Sleep the WDT is locked.
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \funcusage
* \snippet wdt_snippet.c snippet_Cy_WDT_Lock
*
*******************************************************************************/
__STATIC_INLINE void Cy_WDT_Lock(void)
{
    WDT->LOCK = CY_WDT_LOCK_VALUE;
}


/*******************************************************************************
* Function Name: Cy_WDT_Unlock
****************************************************************************//**
*
* Unlocks the Watchdog Timer configuration register.
* The Watchdog timer should be unlocked before:
* - ILO being enabled/disabled
* - PILO being enabled/disabled
* - the LFCLK source being changed
* - WDT being reconfigured
*
* \warning
* The WDT lock state is not retained during system Deep Sleep. After the wakeup
* from system Deep Sleep the WDT is locked.
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \funcusage
* \snippet wdt_snippet.c snippet_Cy_WDT_Unlock
*
*******************************************************************************/
__STATIC_INLINE void Cy_WDT_Unlock(void)
{
    /*
     * SRSSHV prevents writing control and configuration registers related
     * to WDT when LOCK register is not equal to 0. Requires at least two
     * different writes to unlock.
     */
    WDT->LOCK = CY_WDT_UNLOCK_VALUE_0;
    WDT->LOCK = CY_WDT_UNLOCK_VALUE_1;
}


/*******************************************************************************
* Function Name: Cy_WDT_Locked
****************************************************************************//**
*
* Returns the WDT lock state.
*
* \return
* The WDT lock state.
* * true  : if WDT is locked.
* * false : if WDT is unlocked.
*
* \warning
* The WDT lock state is not retained during system Deep Sleep. After the wakeup
* from system Deep Sleep the WDT is locked.
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \funcusage
* \snippet wdt_snippet.c snippet_Cy_WDT_Unlock
*
*******************************************************************************/
__STATIC_INLINE bool Cy_WDT_Locked(void)
{
    /* Prohibits writing to the WDT registers and other CLK_LF */
    return (0u != _FLD2VAL(WDT_LOCK_WDT_LOCK, WDT->LOCK));
}


/*******************************************************************************
* Function Name: Cy_WDT_SetLowerLimit
****************************************************************************//**
*
* Set lower limit for watchdog.
*
* \param match - Value to be matched
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \warning The Watchdog timer should be unlocked and disabled before
* being configured. Call the \ref Cy_WDT_Unlock() API to unlock the WDT.
*
* \funcusage \ref group_wdt_section_use_case_3_srsshv
*
*******************************************************************************/
__STATIC_INLINE void Cy_WDT_SetLowerLimit(uint32_t match)
{
    CY_ASSERT_L2(false == Cy_WDT_Locked());
    CY_ASSERT_L2(false == Cy_WDT_IsEnabled());
    WDT->LOWER_LIMIT = match;
}


/*******************************************************************************
* Function Name: Cy_WDT_SetUpperLimit
****************************************************************************//**
*
* Set upper limit for watchdog.
*
* \param match - Value to be matched
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \warning The Watchdog timer should be unlocked and disabled before
* being configured. Call the \ref Cy_WDT_Unlock() API to unlock the WDT.
*
* \funcusage \ref group_wdt_section_use_case_3_srsshv
*
*******************************************************************************/
__STATIC_INLINE void Cy_WDT_SetUpperLimit(uint32_t match)
{
    CY_ASSERT_L2(false == Cy_WDT_Locked());
    CY_ASSERT_L2(false == Cy_WDT_IsEnabled());
    WDT->UPPER_LIMIT = match;
}


/*******************************************************************************
* Function Name: Cy_WDT_SetWarnLimit
****************************************************************************//**
*
* Set warn limit for watchdog.
*
* \param match - Value to be matched
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \warning The Watchdog timer should be unlocked and disabled before
* being configured. Call the \ref Cy_WDT_Unlock() API to unlock the WDT.
*
* \funcusage \ref group_wdt_section_use_case_3_srsshv
*
*******************************************************************************/
__STATIC_INLINE void Cy_WDT_SetWarnLimit(uint32_t match)
{
    CY_ASSERT_L2(false == Cy_WDT_Locked());
    CY_ASSERT_L2(false == Cy_WDT_IsEnabled());
    WDT->WARN_LIMIT = match;
}


/*******************************************************************************
* Function Name: Cy_WDT_SetLowerAction
****************************************************************************//**
*
* Set action taken if this watchdog is serviced before LOWER_LIMIT is reached.
*
* \param action
* \ref cy_en_wdt_lower_upper_action_t
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \warning The Watchdog timer should be unlocked and disabled before
* being configured. Call the \ref Cy_WDT_Unlock() API to unlock the WDT.
*
* \funcusage \ref group_wdt_section_use_case_3_srsshv
*
*******************************************************************************/
__STATIC_INLINE void Cy_WDT_SetLowerAction(cy_en_wdt_lower_upper_action_t action)
{
    CY_ASSERT_L2(CY_WDT_IS_LOW_UPPER_ACTION_VALID(action));
    CY_ASSERT_L2(false == Cy_WDT_Locked());
    CY_ASSERT_L2(false == Cy_WDT_IsEnabled());
    CY_REG32_CLR_SET(WDT->CONFIG, WDT_CONFIG_LOWER_ACTION, action);
}


/*******************************************************************************
* Function Name: Cy_WDT_SetUpperAction
****************************************************************************//**
*
* Set action taken if this watchdog is not serviced before UPPER_LIMIT is reached.
*
* \param action
* \ref cy_en_wdt_lower_upper_action_t
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \warning The Watchdog timer should be unlocked and disabled before
* being configured. Call the \ref Cy_WDT_Unlock() API to unlock the WDT.
*
* \funcusage \ref group_wdt_section_use_case_3_srsshv
*
*******************************************************************************/
__STATIC_INLINE void Cy_WDT_SetUpperAction(cy_en_wdt_lower_upper_action_t action)
{
    CY_ASSERT_L2(CY_WDT_IS_LOW_UPPER_ACTION_VALID(action));
    CY_ASSERT_L2(false == Cy_WDT_Locked());
    CY_ASSERT_L2(false == Cy_WDT_IsEnabled());
    CY_REG32_CLR_SET(WDT->CONFIG, WDT_CONFIG_UPPER_ACTION, action);
}


/*******************************************************************************
* Function Name: Cy_WDT_SetWarnAction
****************************************************************************//**
*
* Set action taken when the count value reaches WARN_LIMIT.
*
* \param action
* \ref cy_en_wdt_warn_action_t
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \warning The Watchdog timer should be unlocked and disabled before
* being configured. Call the \ref Cy_WDT_Unlock() API to unlock the WDT.
*
* \funcusage \ref group_wdt_section_use_case_3_srsshv
*
*******************************************************************************/
__STATIC_INLINE void Cy_WDT_SetWarnAction(cy_en_wdt_warn_action_t action)
{
    CY_ASSERT_L2(CY_WDT_IS_WARN_ACTION_VALID(action));
    CY_ASSERT_L2(false == Cy_WDT_Locked());
    CY_ASSERT_L2(false == Cy_WDT_IsEnabled());
    CY_REG32_CLR_SET(WDT->CONFIG, WDT_CONFIG_WARN_ACTION, action);
}


/*******************************************************************************
* Function Name: Cy_WDT_SetAutoService
****************************************************************************//**
*
* Set automatically service when the count value reaches WARN_LIMIT.
* This function is used for WARN_LIMIT.
* This allows creation of a periodic interrupt if this counter is not needed as a watchdog.
* This configuration is ignored when LOWER_ACTION or when UPPER_ACTION is set to trigger a reset.
*
* \param enable
* \ref cy_en_wdt_enable_t
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \warning The Watchdog timer should be unlocked and disabled before
* being configured. Call the \ref Cy_WDT_Unlock() API to unlock the WDT.
*
* \funcusage \ref group_wdt_section_use_case_3_srsshv
*
*******************************************************************************/
__STATIC_INLINE void Cy_WDT_SetAutoService(cy_en_wdt_enable_t enable)
{
    CY_ASSERT_L2(CY_WDT_IS_ENABLE_DISABLE_VALID(enable));
    CY_ASSERT_L2(false == Cy_WDT_Locked());
    CY_ASSERT_L2(false == Cy_WDT_IsEnabled());
    CY_REG32_CLR_SET(WDT->CONFIG, WDT_CONFIG_AUTO_SERVICE, enable);
}


/*******************************************************************************
* Function Name: Cy_WDT_SetDeepSleepPause
****************************************************************************//**
*
* Set whether the WDT counter runs/pauses when the system is in DEEPSLEEP.
*
* \param enable
* \ref cy_en_wdt_enable_t
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \warning The Watchdog timer should be unlocked and disabled before
* being configured. Call the \ref Cy_WDT_Unlock() API to unlock the WDT.
*
*******************************************************************************/
__STATIC_INLINE void Cy_WDT_SetDeepSleepPause(cy_en_wdt_enable_t enable)
{
    CY_ASSERT_L2(CY_WDT_IS_ENABLE_DISABLE_VALID(enable));
    CY_ASSERT_L2(false == Cy_WDT_Locked());
    CY_ASSERT_L2(false == Cy_WDT_IsEnabled());
    CY_REG32_CLR_SET(WDT->CONFIG, WDT_CONFIG_DPSLP_PAUSE, enable);
}


/*******************************************************************************
* Function Name: Cy_WDT_SetDebugRun
****************************************************************************//**
*
* Set the debug run value. It needs when using debugger.
*
* \param enable
* \ref cy_en_wdt_enable_t
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \warning The Watchdog timer should be unlocked and disabled before
* being configured. Call the \ref Cy_WDT_Unlock() API to unlock the WDT.
*
*******************************************************************************/
__STATIC_INLINE void Cy_WDT_SetDebugRun(cy_en_wdt_enable_t enable)
{
    CY_ASSERT_L2(CY_WDT_IS_ENABLE_DISABLE_VALID(enable));
    CY_ASSERT_L2(false == Cy_WDT_Locked());
    CY_ASSERT_L2(false == Cy_WDT_IsEnabled());
    CY_REG32_CLR_SET(WDT->CONFIG, WDT_CONFIG_DEBUG_RUN, enable);
}


/*******************************************************************************
* Function Name: Cy_WDT_SetService
****************************************************************************//**
*
* Set service of the watchdog. This resets the count value to zero.
* If WDT is disabled, service will not trigger a LOWER_ACTION
* and will not clear a preloaded count value.
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \note May take up to three \ref group_sysclk_lf cycles to take effect.
*
* \warning The Watchdog timer should be unlocked and disabled before
* being configured. Call the \ref Cy_WDT_Unlock() API to unlock the WDT.
*
*******************************************************************************/
__STATIC_INLINE void Cy_WDT_SetService(void)
{
    CY_ASSERT_L2(true == Cy_WDT_IsEnabled());
    CY_ASSERT_L2(false == Cy_WDT_Locked());
    while(0U != WDT->SERVICE)
    {
        /* Do nothing.
        * To ensure a pending SERVICE write is reflected,
        * firmware should wait until this bit reads low before
        * attempting to write SERVICE=1.
        */
    }
    WDT->SERVICE = WDT_SERVICE_SERVICE_Msk;
}


/*******************************************************************************
* Function Name: Cy_WDT_SetCount
****************************************************************************//**
*
* Set the WDT counter value.
*
* When WDT is disabled and unlocked, the count value can be written
* for verification and debugging purposes.
* Software writes are always ignored when the WDT is enabled.
* Set the WDT counter value may lag the actual count value
* by up to one \ref group_sysclk_lf cycle, due to internal synchronization.
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \warning The Watchdog timer should be unlocked and disabled before
* being configured. Call the \ref Cy_WDT_Unlock() API to unlock the WDT.
*
*******************************************************************************/
__STATIC_INLINE void Cy_WDT_SetCount(uint32_t count)
{
    CY_ASSERT_L2(false == Cy_WDT_IsEnabled());
    CY_ASSERT_L2(false == Cy_WDT_Locked());
    WDT->CNT = count;
}


/*******************************************************************************
* Function Name: Cy_WDT_SetInterrupt
****************************************************************************//**
*
* Triggers an interrupt with software.
* Can be used to set interrupts for firmware testing.
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \note Due to internal synchronization, it takes up to 8 \ref group_sysclk_clk_sys
* cycles to update after a W1S or reading from this register
* and during this time AHB bus is stalled.
*
*******************************************************************************/
__STATIC_INLINE void Cy_WDT_SetInterrupt(void)
{
    /* Write a "1" to Set the INTR_SET bit */
    WDT->INTR_SET = WDT_INTR_SET_WDT_Msk;
}

#endif /* CY_IP_M0S8SRSSHV */

/** \} group_wdt_functions */

#if defined(__cplusplus)
}
#endif

#endif /* CY_WDT_H */

/** \} group_wdt */


/* [] END OF FILE */
