/***************************************************************************//**
* \file cy_wdt.h
* \version 1.90
*
* \brief
* This file provides constants and parameter values for the WDT driver.
*
********************************************************************************
* \copyright
* Copyright(c) 2016-2026 Infineon Technologies AG or an affiliate of
* Infineon Technologies AG
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


/**
* \addtogroup group_wdt
* \{
*
* The Watchdog timer (WDT) has a 16-bit free-running up-counter.
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
* It is strongly recommended not to use the WDT for periodic interrupt
* generation. However, if absolutely required, see information below.
*
* A "reset cause" register(RES_CAUSE, Part of SRSS IP) exists, and the firmware should
* check this register at a start-up. An appropriate action can be taken if a WRES
* reset is detected.
*
* The user's firmware periodically resets the timeout period (clears or "feeds"
* the watchdog) before a timeout occurs. If the firmware fails to do so, that is
* considered to be a CPU crash or a firmware failure, and the reason for a
* device reset.
* The WDT can generate an interrupt instead of a device reset. The Interrupt
* Service Routine (ISR) can handle the interrupt either as a periodic interrupt,
* or as an early indication of a firmware failure and respond accordingly.
* However, it is not recommended to use the WDT for periodic interrupt
* generation. The Multi-counter Watchdog Timers (MCWDT) can be used to generate
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
* counter. For example, if the Cy_WDT_SetIgnoreBits() function is called with
* parameter 3, the WDT counter becomes a 13-bit free-running up-counter.
*
* <b> Power Modes </b>
*
* WDT can operate in all possible low power modes.
* Operation during Hibernate mode is possible because the logic and
* high-voltage internal low oscillator (ILO) are supplied by the external
* high-voltage supply (Vddd). The WDT can be configured to wake the device from
* Hibernate mode.
*
* In CPU Active mode, an interrupt request from the WDT is sent to the
* CPU. In CPU Sleep, CPU Deep Sleep mode, the CPU subsystem
* is powered down, so the interrupt request from the WDT is sent directly to the
* WakeUp Interrupt Controller (WIC) which will then wake up the CPU. The
* CPU then acknowledges the interrupt request and executes the ISR.
* Clear the interrupt in the ISR. The Reset occurs on the 3rd WDT counter match.
*
* In Hibernate mode, the entire device except a few peripherals
* (such as WDT and LPCOMP) are powered down. Any interrupt to wake up the device
* in this mode results in a device reset. Hence, there is no interrupt service
* routine or mechanism associated with this mode. The Reset occurs on the first
* WDT counter match.
*
* <b> Clock Source </b>
*
* The WDT is clocked by the ILO. The WDT must be disabled before disabling
* the ILO. According to the device datasheet, the ILO accuracy is +/-30% over
* voltage and temperature. This means that the timeout period may vary by 30%
* from the configured value. Appropriate margins should be added while
* configuring WDT intervals to make sure that unwanted device resets do not
* occur on some devices.
*
* Refer to the device datasheet for more information on the oscillator accuracy.
*
* <b> Register Locking </b>
*
* You can prevent accidental corruption of the WDT configuration by calling
* the Cy_WDT_Lock() function. When the WDT is locked, any writing to the WDT_*,
* CLK_ILO_CONFIG, CLK_SELECT.LFCLK_SEL, and CLK_TRIM_ILO_CTL registers is
* ignored.
* Call the Cy_WDT_Unlock() function to allow registers modification, mentioned
* above.
*
* Note that the WDT lock state is not retained during system Deep Sleep. After
* the wakeup from system Deep Sleep the WDT is locked.
*
* <b> Clearing WDT </b>
*
* The ILO clock is asynchronous to the SysClk. Therefore it generally
* takes three ILO cycles for WDT register changes to come into effect. It is
* important to remember that a WDT should be cleared at least four cycles
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
* Use the Cy_SysLib_GetResetReason() function to detect whether the WDT has
* triggered a device reset.
*
* <b> Interrupt Configuration </b>
*
* If the WDT is configured to generate an interrupt, pending
* interrupts must be cleared within the ISR (otherwise, the interrupt will be
* generated continuously).
* A pending interrupt to the WDT block must be cleared by calling the
* Cy_WDT_ClearInterrupt() function. The call to the function will clear the
* unhandled WDT interrupt counter.
*
* Use the WDT ISR as a timer to trigger certain actions
* and to change a next WDT match value.
*
* Ensure that the interrupts from the WDT are passed to the CPU to avoid
* unregistered interrupts. Unregistered WDT interrupts result in a continuous
* device reset. To avoid this, call Cy_WDT_UnmaskInterrupt().
* After that, call the WDT API functions for interrupt
* handling/clearing.
*
* \section group_wdt_configuration Configuration Considerations
*
* To start the WDT, make sure that ILO is enabled.
* After the ILO is enabled, ensure that the WDT is unlocked and disabled by
* calling the Cy_WDT_Unlock() and Cy_WDT_Disable() functions. Set the WDT match
* value by calling Cy_WDT_SetMatch() with the required match value. If needed,
* set the ignore bits for reducing the WDT counter period by calling
* Cy_WDT_SetIgnoreBits() function. After the WDT configuration is set,
* call Cy_WDT_Enable().
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
* \section group_wdt_section_more_information More Information
*
* For more information on the WDT peripheral, refer to the technical reference
* manual (TRM).
*
* \defgroup group_wdt_macros Macros
* \defgroup group_wdt_clk_src_enums Enums
* \defgroup group_wdt_structures Data Structures
* \defgroup group_wdt_functions Functions
*
*/

#if !defined(CY_WDT_H)
#define CY_WDT_H

#include "cy_device.h"

#if defined (CY_IP_MXS28SRSS)|| defined (CY_IP_MXS40SSRSS ) || defined (CY_IP_MXS40SRSS) || defined (CY_IP_MXS22SRSS)

#include <stdint.h>
#include <stdbool.h>
#include "cy_syslib.h"
#if defined(CY_DEVICE_SECURE)
    #include "cy_pra.h"
#endif /* defined(CY_DEVICE_SECURE) */


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
#define CY_WDT_DRV_VERSION_MINOR                       90

#if !(defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION >= 2))
#if (defined (CY_IP_MXS22SRSS) && (CY_IP_MXS22SRSS_VERSION==2))

/** The internal define for the first iteration of WDT unlocking */
#define CY_SRSS_WDT_LOCK_BIT0                           ((uint32_t)0x01U)

/** The internal define for the second iteration of WDT unlocking */
#define CY_SRSS_WDT_LOCK_BIT1                           ((uint32_t)0x02U)
#else
/** The internal define for the first iteration of WDT unlocking */
#define CY_SRSS_WDT_LOCK_BIT0                           ((uint32_t)0x01U << 30U)

/** The internal define for the second iteration of WDT unlocking */
#define CY_SRSS_WDT_LOCK_BIT1                           ((uint32_t)0x01U << 31U)
#endif
#endif

/** The WDT default match value */
#define CY_SRSS_WDT_DEFAULT_MATCH_VALUE                 ((uint32_t) 4096U)

/** The default match value of the WDT ignore bits */
#define CY_SRSS_WDT_DEFAULT_IGNORE_BITS                 (0U)

/** The default match value of the WDT ignore bits */
#define CY_SRSS_WDT_LOCK_BITS                           (3U)

/** The WDT driver identifier */
#define CY_WDT_ID                                       CY_PDL_DRV_ID(CY_PDL_RSLT_MODULE_WDT)

/** \cond Internal */

#if defined (CY_IP_MXS40SSRSS) || defined (CY_IP_MXS22SRSS)
/** The WDT maximum match value */
#define WDT_MAX_MATCH_VALUE                      ((0xFFFFFFFFuL) >> (32 - SRSS_NUM_WDT_A_BITS))
/* Internal macro to validate match value */
#define CY_WDT_IS_IGNORE_BITS_ABOVE_VALID(bitPos)     ((bitPos) < SRSS_NUM_WDT_A_BITS)

/** The WDT maximum Ignore Bits */
#define WDT_MAX_IGNORE_BITS                      (SRSS_NUM_WDT_A_BITS - 1U)

#endif


 /* Internal macro to validate match value */
#if defined(SRSS_NUM_WDT_A_BITS) && (SRSS_NUM_WDT_A_BITS >= 32U)
 /* All uint32_t values are valid when WDT counter is 32-bit */
 #define CY_WDT_IS_MATCH_VAL_VALID(match)        (true)
#else
 #define CY_WDT_IS_MATCH_VAL_VALID(match)        ((match) <= (WDT_MAX_MATCH_VALUE))
#endif

/* Internal macro to validate match value */
#define CY_WDT_IS_IGNORE_BITS_VALID(bitsNum)     ((bitsNum) <= WDT_MAX_IGNORE_BITS)

#if defined (CY_IP_MXS22SRSS) && (CY_IP_MXS22SRSS_VERSION == 2)
/* The WDT needs 5 cycles(three cycles of the originally selected
   clock plus two cycles of the newly selected clock) to switch
   away from existing source. The source clock of wdt is fixed to
   32KHz. So 5 cycles become ~153us */
#define CY_WDT_SRC_CLK_SWITCH_DELAY              (153UL)
#else
/* The WDT needs 4 cycles to switch away from existing source.
 * The source clock of wdt is fixed to 32KHz. So 4 cycles become 122us */
#define CY_WDT_SRC_CLK_SWITCH_DELAY              (122UL)
#endif


#if defined (CY_IP_MXS22SRSS) && (CY_IP_MXS22SRSS_VERSION == 2)
/* Internal macro to validate match value */
#define CY_WDT_IS_CLK_SRC_VALID(src)         (((src) == CY_WDT_CLK_SOURCE_ILO)  || \
                                              ((src) == CY_WDT_CLK_SOURCE_PILO) || \
                                              ((src) == CY_WDT_CLK_SOURCE_WCO))
/** WDT driver retry macros. WDT busy bet is set for three clock cycles
 *  (~92us) after writing to WDT_CNT.COUNTER or after writing to
 *  WDT_INTR_SET (set) or WDT_INTR (clear).*/
#define CY_WDT_ACCESS_BUSY_RETRY_COUNT    (92u)

/** WDT driver retry delay value */
#define CY_WDT_BUSY_RETRY_DELAY_US         (1u)     /* 1 usec */

#elif defined (CY_IP_MXS22SRSS) && (CY_IP_MXS22SRSS_VERSION <= 2)
/* Internal macro to validate match value */
#define CY_WDT_IS_CLK_SRC_VALID(src)         (((src) == CY_WDT_CLK_SOURCE_PILO)  || \
                                              ((src) == CY_WDT_CLK_SOURCE_BAK))
#elif defined (CY_IP_MXS40SSRSS)
/* Internal macro to validate match value */
#define CY_WDT_IS_CLK_SRC_VALID(src)         (((src) == CY_WDT_CLK_SOURCE_ILO)  || \
                                              ((src) == CY_WDT_CLK_SOURCE_PILO) || \
                                              ((src) == CY_WDT_CLK_SOURCE_BAK))
#endif

/** \endcond */
/** \} group_wdt_macros */
/**
* \addtogroup group_wdt_clk_src_enums
* \{
*/

#if defined (CY_IP_MXS40SSRSS) || defined (CY_IP_MXS22SRSS) ||defined (CY_DOXYGEN)

/** WDT status enumeration */
typedef enum
 {
    CY_WDT_SUCCESS       = 0x00U,    /**< Successful */
    CY_WDT_BAD_PARAM     = CY_WDT_ID | CY_PDL_STATUS_ERROR | 0x01U,    /**< One or more invalid parameters */
    CY_WDT_TIMEOUT       = CY_WDT_ID | CY_PDL_STATUS_ERROR | 0x02U,    /**< Time-out occurs */
    CY_WDT_LOCKED        = CY_WDT_ID | CY_PDL_STATUS_ERROR | 0x03U,    /**< WDT is in locked state */
    CY_WDT_UNKNOWN       = CY_WDT_ID | CY_PDL_STATUS_ERROR | 0xFFU     /**< Unknown failure */
} cy_en_wdt_status_t;



typedef enum
{
#if defined (CY_IP_MXS40SSRSS) || defined (CY_IP_MXS22SRSS_VERSION) && (CY_IP_MXS22SRSS_VERSION ==2 )
    CY_WDT_CLK_SOURCE_ILO       =     0U, /**< Select the ILO as clock source to WDT */
#endif
    CY_WDT_CLK_SOURCE_PILO      =     1U, /**< Select the PILO as clock source to WDT */
#if defined (CY_IP_MXS22SRSS_VERSION) && (CY_IP_MXS22SRSS_VERSION ==2 )
    CY_WDT_CLK_SOURCE_WCO       =     2U, /**< Select the WCO as clock source to WDT */
#else
    CY_WDT_CLK_SOURCE_BAK       =     2U, /**< Select the clk_bak as clock source to WDT */
#endif
} cy_en_wdt_clk_sources_t;
#endif /* defined (CY_IP_MXS40SSRSS) || defined (CY_IP_MXS22SRSS) ||defined (CY_DOXYGEN) */


/** \} group_wdt_clk_src_enums */

/**
* \addtogroup group_wdt_structures
* \{
*/

/**
  * \brief Watchdog Timer Configuration Structure
  */
typedef struct{
    uint32_t match;         /**< Match value for Watchdog counter */
    uint32_t ignoreBits;    /**< Number of the most significant bits of the Watchdog counter that
                                are excluded  from the match comparison. When this is set to 1,
                                just the MSB is ignored. When set to 2, MSB and (MSB-1) bits
                                are ignored and so on */
} cy_stc_wdt_config_t;
/** \} group_wdt_structures */

/*******************************************************************************
*        Function Prototypes
*******************************************************************************/
/**
* \addtogroup group_wdt_functions
* @{
*/
#if defined (CY_IP_MXS22SRSS) && ( CY_IP_MXS22SRSS_VERSION == 2) && defined(SRSS_NUM_WDT_A) && (SRSS_NUM_WDT_A > 1)
/* WDT APIs to support multiple instances of WDT */
cy_en_wdt_status_t Cy_WDTx_Init(WDT_STRUCT_Type *base, cy_stc_wdt_config_t const *config);
void Cy_WDTx_Lock(WDT_STRUCT_Type *base);
void Cy_WDTx_Unlock(WDT_STRUCT_Type *base);
bool Cy_WDTx_Locked(WDT_STRUCT_Type *base);
cy_en_wdt_status_t Cy_WDTx_ClearInterrupt(WDT_STRUCT_Type *base);
cy_en_wdt_status_t Cy_WDTx_ClearWatchdog(WDT_STRUCT_Type *base);

__STATIC_INLINE cy_en_wdt_status_t Cy_WDTx_Enable(WDT_STRUCT_Type *base);
__STATIC_INLINE cy_en_wdt_status_t Cy_WDTx_Disable(WDT_STRUCT_Type *base);
__STATIC_INLINE bool Cy_WDTx_IsEnabled(WDT_STRUCT_Type *base);
__STATIC_INLINE uint32_t Cy_WDTx_GetCount(WDT_STRUCT_Type *base);
__STATIC_INLINE cy_en_wdt_status_t Cy_WDTx_ResetCounter(WDT_STRUCT_Type *base);
__STATIC_INLINE void Cy_WDTx_MaskInterrupt(WDT_STRUCT_Type *base);
__STATIC_INLINE void Cy_WDTx_UnmaskInterrupt(WDT_STRUCT_Type *base);
cy_en_wdt_status_t Cy_WDTx_SetMatch(WDT_STRUCT_Type *base, uint32_t match);
cy_en_wdt_status_t Cy_WDTx_SetIgnoreBits(WDT_STRUCT_Type *base, uint32_t bitsNum);
__STATIC_INLINE uint32_t Cy_WDTx_GetMatch(WDT_STRUCT_Type *base);
__STATIC_INLINE uint32_t Cy_WDTx_GetIgnoreBits(WDT_STRUCT_Type *base);
cy_en_wdt_status_t Cy_WDTx_SetMatchBits(WDT_STRUCT_Type *base, uint32_t bitPos);
__STATIC_INLINE cy_en_wdt_status_t Cy_WDTx_SetClkSource(WDT_STRUCT_Type *base, cy_en_wdt_clk_sources_t src);
__STATIC_INLINE cy_en_wdt_clk_sources_t Cy_WDTx_GetClkSource(WDT_STRUCT_Type *base);
__STATIC_INLINE uint32_t Cy_WDTx_GetMatchBits(WDT_STRUCT_Type *base);
__STATIC_INLINE cy_en_wdt_status_t Cy_WDTx_EnableReset(WDT_STRUCT_Type *base);
__STATIC_INLINE cy_en_wdt_status_t Cy_WDTx_DisableReset(WDT_STRUCT_Type *base);
#else
/* WDT API */
void Cy_WDT_Init(void);
void Cy_WDT_Lock(void);
void Cy_WDT_Unlock(void);
bool Cy_WDT_Locked(void);
void Cy_WDT_ClearInterrupt(void);
void Cy_WDT_ClearWatchdog(void);

__STATIC_INLINE void Cy_WDT_Enable(void);
__STATIC_INLINE void Cy_WDT_Disable(void);
__STATIC_INLINE bool Cy_WDT_IsEnabled(void);
__STATIC_INLINE uint32_t Cy_WDT_GetCount(void);
__STATIC_INLINE void Cy_WDT_ResetCounter(void);
__STATIC_INLINE void Cy_WDT_MaskInterrupt(void);
__STATIC_INLINE void Cy_WDT_UnmaskInterrupt(void);

#if defined (CY_IP_MXS28SRSS) || defined (CY_IP_MXS40SSRSS) || defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION < 2) || defined (CY_IP_MXS22SRSS)
void Cy_WDT_SetMatch(uint32_t match);
void Cy_WDT_SetIgnoreBits(uint32_t bitsNum);
__STATIC_INLINE uint32_t Cy_WDT_GetMatch(void);
__STATIC_INLINE uint32_t Cy_WDT_GetIgnoreBits(void);

#if defined (CY_IP_MXS40SSRSS) || defined (CY_IP_MXS22SRSS) ||defined (CY_DOXYGEN)
void Cy_WDT_SetMatchBits(uint32_t bitPos);
__STATIC_INLINE void Cy_WDT_SetClkSource(cy_en_wdt_clk_sources_t src);
__STATIC_INLINE cy_en_wdt_clk_sources_t Cy_WDT_GetClkSource(void);
__STATIC_INLINE uint32_t Cy_WDT_GetMatchBits(void);
#endif

#endif

#if (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION >= 2))
void Cy_WDT_SetLowerLimit(uint32_t match);
void Cy_WDT_SetUpperLimit(uint32_t match);
void Cy_WDT_SetWarnLimit(uint32_t match);
void Cy_WDT_SetLowerAction(cy_en_wdt_lower_upper_action_t action);
void Cy_WDT_SetUpperAction(cy_en_wdt_lower_upper_action_t action);
void Cy_WDT_SetWarnAction(cy_en_wdt_warn_action_t action);
void Cy_WDT_SetAutoService(cy_en_wdt_enable_t enable);
void Cy_WDT_SetDeepSleepPause(cy_en_wdt_enable_t enable);
void Cy_WDT_SetHibernatePause(cy_en_wdt_enable_t enable);
void Cy_WDT_SetDebugRun(cy_en_wdt_enable_t enable);
void Cy_WDT_SetService(void);
#endif
#if defined (CY_IP_MXS22SRSS) && ( CY_IP_MXS22SRSS_VERSION == 2)
__STATIC_INLINE void Cy_WDT_EnableReset(void);
__STATIC_INLINE void Cy_WDT_DisableReset(void);
#endif // defined (CY_IP_MXS22SRSS) && ( CY_IP_MXS22SRSS_VERSION == 2)
#endif // (CY_IP_MXS22SRSS) && ( CY_IP_MXS22SRSS_VERSION == 2) && defined(SRSS_NUM_WDT_A) && (SRSS_NUM_WDT_A > 1)

#if defined (CY_IP_MXS22SRSS) && ( CY_IP_MXS22SRSS_VERSION == 2)

__STATIC_INLINE cy_en_wdt_status_t Cy_WDTx_WaitForNotBusy_Common(WDT_STRUCT_Type *base)
{
    cy_en_wdt_status_t status         = CY_WDT_TIMEOUT;
    uint32_t           wdtAccessRetry = CY_WDT_ACCESS_BUSY_RETRY_COUNT;
    while ((_FLD2BOOL(WDT_MAIN_WDT_STATUS_BUSY, SRSS_WDT_STATUS(base)) == true) && (wdtAccessRetry != 0))
    {
        wdtAccessRetry--;
        Cy_SysLib_DelayUs(CY_WDT_BUSY_RETRY_DELAY_US);
    }
    if(wdtAccessRetry != 0)
    {
        status = CY_WDT_SUCCESS;
    }
    return status;
}

__STATIC_INLINE  bool Cy_WDTx_Locked_Common(WDT_STRUCT_Type *base)
{
    /* Prohibits writing to the WDT registers and other CLK_LF */
    return (0u != _FLD2VAL(WDT_MAIN_WDT_LOCK_WDT_LOCK, SRSS_WDT_LOCK(base)));
}

__STATIC_INLINE cy_en_wdt_status_t Cy_WDTx_ClearInterrupt_Common(WDT_STRUCT_Type *base)
{
    cy_en_wdt_status_t status = Cy_WDTx_WaitForNotBusy_Common(base);
    if(CY_WDT_SUCCESS == status)
    {
        SRSS_WDT_INTR(base) = WDT_MAIN_WDT_INTR_WDT_MATCH_Msk;

        /* Read the interrupt register to ensure that the initial clearing write has
        * been flushed out to the hardware.
        */
        (void) SRSS_WDT_INTR(base);
    }
    return status;
}

__STATIC_INLINE cy_en_wdt_status_t Cy_WDTx_Enable_Common(WDT_STRUCT_Type *base)
{
    cy_en_wdt_status_t status = CY_WDT_LOCKED;
    if (false == Cy_WDTx_Locked_Common(base))
    {
        /* Enables the Watchdog timer */
        SRSS_WDT_CTL(base) |= WDT_MAIN_WDT_CTL_WDT_EN_Msk;
        status =  Cy_WDTx_ClearInterrupt_Common(base);
    }
    return status;
}

__STATIC_INLINE cy_en_wdt_status_t Cy_WDTx_Disable_Common(WDT_STRUCT_Type *base)
{
    cy_en_wdt_status_t status = CY_WDT_LOCKED;
    if (false == Cy_WDTx_Locked_Common(base))
    {
        /* Disables the Watchdog timer */
        SRSS_WDT_CTL(base) &= ((uint32_t) ~(WDT_MAIN_WDT_CTL_WDT_EN_Msk));
        status = CY_WDT_SUCCESS;
    }
    return status;
}

__STATIC_INLINE bool Cy_WDTx_IsEnabled_Common(WDT_STRUCT_Type *base)
{
    return _FLD2BOOL(WDT_MAIN_WDT_CTL_WDT_EN, SRSS_WDT_CTL(base));
}

__STATIC_INLINE uint32_t Cy_WDTx_GetMatch_Common(WDT_STRUCT_Type *base)
{
    /* Reads the WDT counter match comparison value*/
    return ((uint32_t) _FLD2VAL(WDT_MAIN_WDT_MATCH_MATCH, SRSS_WDT_MATCH(base)));
}

__STATIC_INLINE uint32_t Cy_WDTx_GetIgnoreBits_Common(WDT_STRUCT_Type *base)
{
    /* Reads the number of the most significant bits of the Watchdog timer that are
       not checked against the match*/
    return((uint32_t) (WDT_MAX_IGNORE_BITS - _FLD2VAL(WDT_MAIN_WDT_MATCH2_IGNORE_BITS_ABOVE, SRSS_WDT_MATCH2(base))));
}



__STATIC_INLINE cy_en_wdt_status_t Cy_WDTx_SetClkSource_Common(WDT_STRUCT_Type *base, cy_en_wdt_clk_sources_t src)
{
    cy_en_wdt_status_t status = CY_WDT_LOCKED;
    CY_ASSERT_L2(CY_WDT_IS_CLK_SRC_VALID(src));
    status = Cy_WDTx_Locked_Common(base) ? CY_WDT_LOCKED : CY_WDT_SUCCESS;
    if(CY_WDT_SUCCESS == status)
    {
        status = Cy_WDTx_WaitForNotBusy_Common(base);
    }
    if(CY_WDT_SUCCESS == status)
    {
        SRSS_WDT_CTL(base) = _CLR_SET_FLD32U((SRSS_WDT_CTL(base)), WDT_MAIN_WDT_CTL_WDT_CLK_SEL, src);
        /** Adding 4 cycle delay */
        Cy_SysLib_DelayUs((uint16_t)CY_WDT_SRC_CLK_SWITCH_DELAY);
    }
    return status;
}

__STATIC_INLINE cy_en_wdt_clk_sources_t Cy_WDTx_GetClkSource_Common(WDT_STRUCT_Type *base)
{
    CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 10.8','Intentional typecast to cy_en_wdt_clk_sources_t enum.');
    return ((cy_en_wdt_clk_sources_t) _FLD2VAL(WDT_MAIN_WDT_CTL_WDT_CLK_SEL, SRSS_WDT_CTL(base)));
}

__STATIC_INLINE uint32_t Cy_WDTx_GetMatchBits_Common(WDT_STRUCT_Type *base)
{
    return((uint32_t) (_FLD2VAL(WDT_MAIN_WDT_MATCH2_IGNORE_BITS_ABOVE, SRSS_WDT_MATCH2(base))));
}

__STATIC_INLINE uint32_t Cy_WDTx_GetCount_Common(WDT_STRUCT_Type *base)
{
    return ((uint32_t) _FLD2VAL(WDT_MAIN_WDT_CNT_COUNTER, SRSS_WDT_CNT(base)));
}

__STATIC_INLINE cy_en_wdt_status_t Cy_WDTx_ResetCounter_Common(WDT_STRUCT_Type *base)
{
    cy_en_wdt_status_t status = CY_WDT_LOCKED;
    status = Cy_WDTx_Locked_Common(base) ? CY_WDT_LOCKED : CY_WDT_SUCCESS;
    if(CY_WDT_SUCCESS == status)
    {
        status = Cy_WDTx_WaitForNotBusy_Common(base);
    }
    if( CY_WDT_SUCCESS == status )
    {
        SRSS_WDT_CNT(base) = 0x0U;
    }
    return status;
}

__STATIC_INLINE void Cy_WDTx_MaskInterrupt_Common(WDT_STRUCT_Type *base)
{
    SRSS_WDT_INTR_MASK(base) &= (uint32_t)(~ WDT_MAIN_WDT_INTR_MASK_WDT_MATCH_Msk);
}

__STATIC_INLINE void Cy_WDTx_UnmaskInterrupt_Common(WDT_STRUCT_Type *base)
{
    SRSS_WDT_INTR_MASK(base) |= WDT_MAIN_WDT_INTR_MASK_WDT_MATCH_Msk;
}
__STATIC_INLINE cy_en_wdt_status_t Cy_WDTx_EnableReset_Common(WDT_STRUCT_Type *base)
{
    cy_en_wdt_status_t status = CY_WDT_LOCKED;
    if (false == Cy_WDTx_Locked_Common(base))
    {
        SRSS_WDT_CTL(base) &= ((uint32_t)(~ WDT_MAIN_WDT_CTL_MASK_WDT_RESET_Msk));
        status = CY_WDT_SUCCESS;
    }
    return status;
}
__STATIC_INLINE cy_en_wdt_status_t Cy_WDTx_DisableReset_Common(WDT_STRUCT_Type *base)
{
    cy_en_wdt_status_t status = CY_WDT_LOCKED;
    if (false == Cy_WDTx_Locked_Common(base))
    {
        SRSS_WDT_CTL(base) |= WDT_MAIN_WDT_CTL_MASK_WDT_RESET_Msk;
        status = CY_WDT_SUCCESS;
    }
    return status;
}
#endif

#if defined (CY_IP_MXS22SRSS) && ( CY_IP_MXS22SRSS_VERSION == 2) && defined(SRSS_NUM_WDT_A) && (SRSS_NUM_WDT_A > 1)

/*******************************************************************************
* Function Name: Cy_WDTx_Enable
****************************************************************************//**
*
* Enables the Watchdog timer.The Watchdog timer should be unlocked before being
* enabled. Call the Cy_WDTx_Unlock() API to unlock the WDT.
*
* \param base
* The pointer to the WDT instance.
*
* \return
* The status of the WDT enable request. \ref cy_en_wdt_status_t
*
* \sideeffect
* This function clears the WDT interrupt.
*
*******************************************************************************/
__STATIC_INLINE cy_en_wdt_status_t Cy_WDTx_Enable(WDT_STRUCT_Type *base)
{
    return Cy_WDTx_Enable_Common(base);
}


/*******************************************************************************
* Function Name: Cy_WDTx_Disable
****************************************************************************//**
*
* Disables the Watchdog timer. The Watchdog timer should be unlocked before being
* disabled. Call the Cy_WDT_Unlock() API to unlock the WDT.
*
* \param base
* The pointer to the WDT instance.
*
* \return
* The status of the WDT disable request. \ref cy_en_wdt_status_t
*
*******************************************************************************/
__STATIC_INLINE cy_en_wdt_status_t Cy_WDTx_Disable(WDT_STRUCT_Type *base)
{
    return Cy_WDTx_Disable_Common(base);
}


/*******************************************************************************
* Function Name: Cy_WDTx_IsEnabled
****************************************************************************//**
*
* Reports an enable/disable state of the Watchdog timer.
*
* \param base
* The pointer to the WDT instance.
*
* \return
* - true - if the timer is enabled
* - false - if the timer is disabled
*
*******************************************************************************/
__STATIC_INLINE bool Cy_WDTx_IsEnabled(WDT_STRUCT_Type *base)
{
    return Cy_WDTx_IsEnabled_Common(base);
}

/*******************************************************************************
* Function Name: Cy_WDTx_GetMatch
****************************************************************************//**
*
* Reads the WDT counter match comparison value.
*
* \param base
* The pointer to the WDT instance.
*
* \return The counter match value.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_WDTx_GetMatch(WDT_STRUCT_Type *base)
{
    return Cy_WDTx_GetMatch_Common(base);
}

/*******************************************************************************
* Function Name: Cy_WDTx_GetIgnoreBits
****************************************************************************//**
*
* Reads the number of the most significant bits of the Watchdog timer that are
* not checked against the match.
*
* \param base
* The pointer to the WDT instance.
*
* \return The number of the most significant bits.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_WDTx_GetIgnoreBits(WDT_STRUCT_Type *base)
{
    return Cy_WDTx_GetIgnoreBits_Common(base);
}

/*******************************************************************************
* Function Name: Cy_WDTx_SetClkSource
****************************************************************************//**
*
* Configures the WDT clock source
*
* \param base
* The pointer to the WDT instance.
*
* \param src
* Clock sources for WDT. \ref cy_en_wdt_clk_sources_t
*
* \return
* The status of the WDT enable request. \ref cy_en_wdt_status_t
*
* \note  It takes three cycles of the originally selected clock plus two cycles
* of the newly selected clock to switch away  from it.  Do not disable the
* original clock during this time.
*
*******************************************************************************/
__STATIC_INLINE cy_en_wdt_status_t Cy_WDTx_SetClkSource(WDT_STRUCT_Type *base, cy_en_wdt_clk_sources_t src)
{
    return Cy_WDTx_SetClkSource_Common(base, src);
}

/*******************************************************************************
* Function Name: Cy_WDTx_GetClkSource
****************************************************************************//**
*
* Gets the WDT clock source configured.
*
* \param base
* The pointer to the WDT instance.
*
* \return The Clock source enum \ref cy_en_wdt_clk_sources_t
*
*
*******************************************************************************/
__STATIC_INLINE cy_en_wdt_clk_sources_t Cy_WDTx_GetClkSource(WDT_STRUCT_Type *base)
{
    return Cy_WDTx_GetClkSource_Common(base);
}

/*******************************************************************************
* Function Name: Cy_WDTx_GetMatchBits
****************************************************************************//**
*
* Gets the bit position above which the bits will be ignored for match.
*
* \param base
* The pointer to the WDT instance.
*
* \return The bit position above which the bits will be ignored for match.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_WDTx_GetMatchBits(WDT_STRUCT_Type *base)
{
    return Cy_WDTx_GetMatchBits_Common(base);
}

/*******************************************************************************
* Function Name: Cy_WDTx_GetCount
****************************************************************************//**
*
* Reads the current WDT counter value.
*
* \param base
* The pointer to the WDT instance.
*
* \return A live counter value.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_WDTx_GetCount(WDT_STRUCT_Type *base)
{
    return Cy_WDTx_GetCount_Common(base);
}

/*******************************************************************************
* Function Name: Cy_WDTx_ResetCounter
****************************************************************************//**
*
* Resets the WDT counter value.
*
* \param base
* The pointer to the WDT instance.
*
* \return
* The status of the WDT reset counter request. \ref cy_en_wdt_status_t
*
* \note
* This API must be called only after WDT is disabled, else the writes will be
* ignored if WDT is enabled.
*
*
*******************************************************************************/
__STATIC_INLINE cy_en_wdt_status_t Cy_WDTx_ResetCounter(WDT_STRUCT_Type *base)
{
   return Cy_WDTx_ResetCounter_Common(base);
}

/*******************************************************************************
* Function Name: Cy_WDTx_MaskInterrupt
****************************************************************************//**
*
* After masking interrupts from the WDT, they are not passed to the CPU.
* This function does not disable the WDT-reset generation.
*
* \param base
* The pointer to the WDT instance.
*
*******************************************************************************/
__STATIC_INLINE void Cy_WDTx_MaskInterrupt(WDT_STRUCT_Type *base)
{
    Cy_WDTx_MaskInterrupt_Common(base);
}


/*******************************************************************************
* Function Name: Cy_WDTx_UnmaskInterrupt
****************************************************************************//**
*
* After unmasking interrupts from the WDT, they are passed to CPU.
* This function does not impact the reset generation.
*
* \param base
* The pointer to the WDT instance.
*
*******************************************************************************/
__STATIC_INLINE void Cy_WDTx_UnmaskInterrupt(WDT_STRUCT_Type *base)
{
    Cy_WDTx_UnmaskInterrupt_Common(base);
}

/*******************************************************************************
* Function Name: Cy_WDTx_EnableReset
****************************************************************************//**
*
* Enable the generation of reset signal by the WDT.
*
* \param base
* The pointer to the WDT instance.
*
* \return
* The status of the WDT reset enable request. \ref cy_en_wdt_status_t
*
*\note WDT reset is enabled by default. Use this function to enable the reset
* in case the reset was disabled using \ref Cy_WDTx_DisableReset.
* WDT should be unlocked for the settings to take effect.
*
*******************************************************************************/
__STATIC_INLINE cy_en_wdt_status_t Cy_WDTx_EnableReset(WDT_STRUCT_Type *base)
{
    return Cy_WDTx_EnableReset_Common(base);
}

/*******************************************************************************
* Function Name: Cy_WDTx_DisableReset
****************************************************************************//**
*
* Disable the generation of reset signal by the WDT. When disabled, missed WDT
* interrupts will not generate a reset
*
* \param base
* The pointer to the WDT instance.
*
* \return
* The status of the WDT reset disable request. \ref cy_en_wdt_status_t
*
*\note WDT reset is enabled by default. Use this function to disable the reset.
* WDT should be unlocked for the settings to take effect.
*
*******************************************************************************/
__STATIC_INLINE cy_en_wdt_status_t Cy_WDTx_DisableReset(WDT_STRUCT_Type *base)
{
    return Cy_WDTx_DisableReset_Common(base);
}

#else

/*******************************************************************************
* Function Name: Cy_WDT_Enable
****************************************************************************//**
*
* Enables the Watchdog timer.
*
* \sideeffect
* This function clears the WDT interrupt.
*
*******************************************************************************/
__STATIC_INLINE void Cy_WDT_Enable(void)
{
#if defined (CY_IP_MXS22SRSS) && (CY_IP_MXS22SRSS_VERSION == 2) && defined(SRSS_NUM_WDT_A) && (SRSS_NUM_WDT_A == 1)
    Cy_WDTx_Enable_Common(WDT_DEFAULT);
#else
#if (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION >= 2))
    SRSS_WDT_CTL |= WDT_CTL_ENABLE_Msk;
#else
    SRSS_WDT_CTL |= _VAL2FLD(SRSS_WDT_CTL_WDT_EN, 1U);
#endif
    Cy_WDT_ClearInterrupt();
#endif
}


/*******************************************************************************
* Function Name: Cy_WDT_Disable
****************************************************************************//**
*
* Disables the Watchdog timer. The Watchdog timer should be unlocked before being
* disabled. Call the Cy_WDT_Unlock() API to unlock the WDT.
*
*******************************************************************************/
__STATIC_INLINE void Cy_WDT_Disable(void)
{
#if defined (CY_IP_MXS22SRSS) && (CY_IP_MXS22SRSS_VERSION == 2) && defined(SRSS_NUM_WDT_A) && (SRSS_NUM_WDT_A == 1)
    Cy_WDTx_Disable_Common(WDT_DEFAULT);
#elif (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION >= 2))
    SRSS_WDT_CTL &= ((uint32_t) ~(_VAL2FLD(WDT_CTL_ENABLE, 1U)));
#else
    SRSS_WDT_CTL &= ((uint32_t) ~(_VAL2FLD(SRSS_WDT_CTL_WDT_EN, 1U)));
#endif
}


/*******************************************************************************
* Function Name: Cy_WDT_IsEnabled
****************************************************************************//**
*
* Reports an enable/disable state of the Watchdog timer.
*
* \return
* - true - if the timer is enabled
* - false - if the timer is disabled
*
*******************************************************************************/
__STATIC_INLINE bool Cy_WDT_IsEnabled(void)
{
#if defined (CY_IP_MXS22SRSS) && (CY_IP_MXS22SRSS_VERSION == 2) && defined(SRSS_NUM_WDT_A) && (SRSS_NUM_WDT_A == 1)
    return Cy_WDTx_IsEnabled_Common(WDT_DEFAULT);
#elif (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION >= 2))
    return _FLD2BOOL(WDT_CTL_ENABLE, SRSS_WDT_CTL);
#else
    return _FLD2BOOL(SRSS_WDT_CTL_WDT_EN, SRSS_WDT_CTL);
#endif
}

#if defined (CY_IP_MXS28SRSS) || defined (CY_IP_MXS40SSRSS) || defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION < 2) || defined (CY_IP_MXS22SRSS)

/*******************************************************************************
* Function Name: Cy_WDT_GetMatch
****************************************************************************//**
*
* Reads the WDT counter match comparison value.
*
* \return The counter match value.
*
* \note
* This API is available for PSOC, PSC and PSE devices.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_WDT_GetMatch(void)
{
#if defined (CY_IP_MXS22SRSS) && (CY_IP_MXS22SRSS_VERSION == 2) && defined(SRSS_NUM_WDT_A) && (SRSS_NUM_WDT_A == 1)
    return Cy_WDTx_GetMatch_Common(WDT_DEFAULT);
#else
    return ((uint32_t) _FLD2VAL(SRSS_WDT_MATCH_MATCH, SRSS_WDT_MATCH));
#endif
}

/*******************************************************************************
* Function Name: Cy_WDT_GetIgnoreBits
****************************************************************************//**
*
* Reads the number of the most significant bits of the Watchdog timer that are
* not checked against the match.
*
* \return The number of the most significant bits.
*
* \note
* This API is available for PSOC, PSC and PSE devices.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_WDT_GetIgnoreBits(void)
{
#if defined (CY_IP_MXS22SRSS) && (CY_IP_MXS22SRSS_VERSION == 2) && defined(SRSS_NUM_WDT_A) && (SRSS_NUM_WDT_A == 1)
    return Cy_WDTx_GetIgnoreBits_Common(WDT_DEFAULT);
#elif defined (CY_IP_MXS40SSRSS) || defined (CY_IP_MXS22SRSS)
    return((uint32_t) (WDT_MAX_IGNORE_BITS - _FLD2VAL(SRSS_WDT_MATCH2_IGNORE_BITS_ABOVE, SRSS_WDT_MATCH2)));
#else
    return((uint32_t) _FLD2VAL(SRSS_WDT_MATCH_IGNORE_BITS, SRSS_WDT_MATCH));
#endif
}

#if defined (CY_IP_MXS40SSRSS) || defined (CY_IP_MXS22SRSS) || defined (CY_DOXYGEN)
/*******************************************************************************
* Function Name: Cy_WDT_SetClkSource
****************************************************************************//**
*
* Configures the WDT clock source
*
* \param src
* \ref cy_en_wdt_clk_sources_t
*
* \note
* This API is available for PSC and PSE devices.
*
* \note  It takes four cycles of the originally selected clock to switch away
* from it.  Do not disable the original clock during this time.
*
*******************************************************************************/
__STATIC_INLINE void Cy_WDT_SetClkSource(cy_en_wdt_clk_sources_t src)
{
#if defined (CY_IP_MXS22SRSS) && (CY_IP_MXS22SRSS_VERSION == 2) && defined(SRSS_NUM_WDT_A) && (SRSS_NUM_WDT_A == 1)
    Cy_WDTx_SetClkSource_Common(WDT_DEFAULT, src);
#else
    CY_ASSERT_L2(CY_WDT_IS_CLK_SRC_VALID(src));

    if (false == Cy_WDT_Locked())
    {
        SRSS_WDT_CTL = _CLR_SET_FLD32U((SRSS_WDT_CTL), SRSS_WDT_CTL_WDT_CLK_SEL, src);
        /** Adding 4 cycle delay */
        Cy_SysLib_DelayUs((uint16_t)CY_WDT_SRC_CLK_SWITCH_DELAY);
    }
#endif
}

/*******************************************************************************
* Function Name: Cy_WDT_GetClkSource
****************************************************************************//**
*
* Gets the WDT clock source configured.
*
* \return The Clock source enum \ref cy_en_wdt_clk_sources_t
*
*******************************************************************************/
__STATIC_INLINE cy_en_wdt_clk_sources_t Cy_WDT_GetClkSource(void)
{
#if defined (CY_IP_MXS22SRSS) && (CY_IP_MXS22SRSS_VERSION == 2) && defined(SRSS_NUM_WDT_A) && (SRSS_NUM_WDT_A == 1)
    return Cy_WDTx_GetClkSource_Common(WDT_DEFAULT);
#else
    CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 10.8','Intentional typecast to cy_en_wdt_clk_sources_t enum.');
    return ((cy_en_wdt_clk_sources_t) _FLD2VAL(SRSS_WDT_CTL_WDT_CLK_SEL, SRSS_WDT_CTL));
#endif
}

/*******************************************************************************
* Function Name: Cy_WDT_GetMatchBits
****************************************************************************//**
*
* Gets the bit position above which the bits will be ignored for match.
*
* \return The bit position above which the bits will be ignored for match.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_WDT_GetMatchBits(void)
{
#if defined (CY_IP_MXS22SRSS) && (CY_IP_MXS22SRSS_VERSION == 2) && defined(SRSS_NUM_WDT_A) && (SRSS_NUM_WDT_A == 1)
    return Cy_WDTx_GetMatchBits_Common(WDT_DEFAULT);
#else
    return((uint32_t) (_FLD2VAL(SRSS_WDT_MATCH2_IGNORE_BITS_ABOVE, SRSS_WDT_MATCH2)));
#endif
}
#endif

#endif /*defined (CY_IP_MXS28SRSS) || defined (CY_IP_MXS40SSRSS) || defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION < 2) */


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
#if defined (CY_IP_MXS22SRSS) && (CY_IP_MXS22SRSS_VERSION == 2) && defined(SRSS_NUM_WDT_A) && (SRSS_NUM_WDT_A == 1)
    return Cy_WDTx_GetCount_Common(WDT_DEFAULT);
#elif (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION >= 2))
    return ((uint32_t) _FLD2VAL(WDT_CNT_CNT, SRSS_WDT_CNT));
#else
    return ((uint32_t) _FLD2VAL(SRSS_WDT_CNT_COUNTER, SRSS_WDT_CNT));
#endif
}

/*******************************************************************************
* Function Name: Cy_WDT_ResetCounter
****************************************************************************//**
*
* Resets the WDT counter value.
*
* \note
* This API must be called only after WDT is disabled, else the writes will be
* ignored if WDT is enabled.
*
*
*******************************************************************************/
__STATIC_INLINE void Cy_WDT_ResetCounter(void)
{
#if defined (CY_IP_MXS22SRSS) && (CY_IP_MXS22SRSS_VERSION == 2) && defined(SRSS_NUM_WDT_A) && (SRSS_NUM_WDT_A == 1)
    (void) Cy_WDTx_ResetCounter_Common(WDT_DEFAULT);
#else
    SRSS_WDT_CNT = 0x0U;
#endif
}

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
#if defined (CY_IP_MXS22SRSS) && (CY_IP_MXS22SRSS_VERSION == 2) && defined(SRSS_NUM_WDT_A) && (SRSS_NUM_WDT_A == 1)
    (void)Cy_WDTx_MaskInterrupt_Common(WDT_DEFAULT);
#elif (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION >= 2))
    SRSS_WDT_INTR_MASK &= ~WDT_INTR_MASK_WDT_Msk;
#else
    #if CY_CPU_CORTEX_M4 && defined(CY_DEVICE_SECURE)
        CY_PRA_REG32_CLR_SET(CY_PRA_INDX_SRSS_SRSS_INTR_MASK, SRSS_SRSS_INTR_MASK_WDT_MATCH, 0U);
    #else
        SRSS_SRSS_INTR_MASK &= (uint32_t)(~ _VAL2FLD(SRSS_SRSS_INTR_MASK_WDT_MATCH, 1U));
    #endif /* CY_CPU_CORTEX_M4 && defined(CY_DEVICE_SECURE) */
#endif
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
#if defined (CY_IP_MXS22SRSS) && (CY_IP_MXS22SRSS_VERSION == 2) && defined(SRSS_NUM_WDT_A) && (SRSS_NUM_WDT_A == 1)
    (void)Cy_WDTx_UnmaskInterrupt_Common(WDT_DEFAULT);
#elif (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION >= 2))
    SRSS_WDT_INTR_MASK |= WDT_INTR_MASK_WDT_Msk;
#else
    #if CY_CPU_CORTEX_M4 && defined(CY_DEVICE_SECURE)
        CY_PRA_REG32_CLR_SET(CY_PRA_INDX_SRSS_SRSS_INTR_MASK, SRSS_SRSS_INTR_MASK_WDT_MATCH, 1U);
    #else
        SRSS_SRSS_INTR_MASK |= _VAL2FLD(SRSS_SRSS_INTR_MASK_WDT_MATCH, 1U);
    #endif /* CY_CPU_CORTEX_M4 && defined(CY_DEVICE_SECURE) */
#endif
}
/** \} group_wdt_functions */
#if defined (CY_IP_MXS22SRSS) && ( CY_IP_MXS22SRSS_VERSION == 2)

/*******************************************************************************
* Function Name: Cy_WDT_EnableReset
****************************************************************************//**
*
* Enable the generation of reset signal by the WDT.
*
*\note WDT reset is enabled by default. Use this function to enable the reset
* in case the reset was disabled using \ref Cy_WDT_DisableReset.
* WDT should be unlocked for the settings to take effect.
*
*******************************************************************************/
__STATIC_INLINE void Cy_WDT_EnableReset(void)
{
    Cy_WDTx_EnableReset_Common(WDT_DEFAULT);
}

/*******************************************************************************
* Function Name: Cy_WDT_DisableReset
****************************************************************************//**
*
* Disable the generation of reset signal by the WDT. When disabled, missed WDT
* interrupts will not generate a reset
*
*\note WDT reset is enabled by default. Use this function to disable the reset.
* WDT should be unlocked for the settings to take effect.
*
*******************************************************************************/
__STATIC_INLINE void Cy_WDT_DisableReset(void)
{
    Cy_WDTx_DisableReset_Common(WDT_DEFAULT);
}
#endif /* defined (CY_IP_MXS22SRSS) && ( CY_IP_MXS22SRSS_VERSION == 2) */

/** \} group_wdt_functions */

#endif

#if defined(__cplusplus)
}
#endif

#endif /* CY_IP_MXS28SRSS, CY_IP_MXS40SRSS */

#endif /* CY_WDT_H */

/** \} group_wdt */


/* [] END OF FILE */
