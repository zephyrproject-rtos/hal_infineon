/***************************************************************************//**
* \file cy_wdc.h
* \version 1.0.2
*
*  This file provides constants and parameter values for the WDC driver.
*
********************************************************************************
* \copyright
* (c) (2016-2021), Cypress Semiconductor Corporation (an Infineon company) or
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
* \addtogroup group_wdc
* \{
* Watchdog Counters (WDC) are general-purpose timers clocked from a low-
* frequency clock source and capable of generating interrupts.
*
* Features:
* - Two 16-bit and one 32-bit counters
* - Can be configured to generate periodic interrupts
* - Can be clocked from ILO or WCO
* - Counters can be cascaded to achieve a bigger period
* - Can work in Sleep and Deep Sleep power modes
*
* The functions and other declarations used in this driver are in cy_wdc.h.
* You can include cy_pdl.h to get access to all functions
* and declarations in the PDL.
*
* There are two primary use cases for WDC: generating periodic CPU interrupts;
* and implementing a free-running timer. Both have many applications in
* embedded systems:
* * Measuring time between events
* * Generating periodic events
* * Synchronizing actions
* * Real-time clocking
* * Polling.
*
********************************************************************************
* \section group_wdc_configuration Configuration Considerations
********************************************************************************
* The WDC block contains three sub-counters, each of which can be configured for
* one of the system utility functions - free running counter or periodic interrupts.
*
* A simplified diagram of the WDC hardware is shown below:
* \image html wdc.png
* The frequency of the periodic interrupts for C0 and C1 counters can be configured using the Match
* value using \ref Cy_WDC_SetMatch() together with Clear on match option, which can be set
* using \ref Cy_WDC_SetClearOnMatch() function. When Clear on match option
* is not set, the periodic interrupts of the C0 and C1 16-bit sub-counters occur
* after 65535 counts and the match value defines the shift between interrupts
* (see the figure below). The enabled Clear on match option
* resets the counter when the interrupt occurs.
*
* <b>Clear on match is disabled: </b>
* \image html wdc_C0_C1_NoClearOnMatch.png
*
* <b>Clear on match is enabled: </b>
* \image html wdc_C0_C1_ClearOnMatch.png
*
* 32-bit sub-counter C2 does not have the Clear on match option.
* The interrupt of counter C2 occurs when the counts equal
* 2<sup>Toggle bit</sup> value. For example: when toggle bit = 0, C2 will generate
* interrupt every WDC clock source rising edge; when toggle bit = 31, C2 will generate
* interrupt every 2<sup>31</sup> WDC clock source rising edge.
* \image html wdc_C2.png
*
* WDC initialization can be divided into a number of sequential steps listed below:
* * \ref group_wdc_config
* * \ref group_wdc_cascade
* * \ref group_wdc_interrupt
* * \ref group_wdc_enable
*
********************************************************************************
* \subsection group_wdc_config Configure WDC
********************************************************************************
* To set up a WDC, provide the configuration parameters in the
* \ref cy_stc_wdc_config_t structure. Then call \ref Cy_WDC_Init() to initialize
* the driver.
*
* \snippet wdc_snippet.c snippet_Cy_WDC_Init
*
* \note Before initialization of WDC, ensure that the selected WDC clock source is enabled.
*       Refer to \ref group_sysclk_ilo and \ref group_sysclk_wco sections of
*       SysClk driver documentation.
*
********************************************************************************
* \subsection group_wdc_cascade Counters Cascading
********************************************************************************
* The WDC counter can be cascaded in order to achieve longer wait periods.
* When a counter is cascaded, it uses the previous counter event signal in order to
* perform the increment operation instead of the WDC clock source.
* For example, to configure a WDC to generate interrupts approx. every 20 seconds
* using ILO clock source (40KHz), the total timer period should be set to
* 40000 * 20 = 800000 counts, which is above the 16-bit single timer resolution.
* For a long period delays, 32-bit counter 2 can be used, but it only allows fixed period values.
* In our case, it will generate interrupts with 13.1 seconds (2^19 = 524288)
* or 26.2 seconds (2^20 = 1048576) periods.
* To achieve higher timing precision, counters 0 and 1 can be cascaded.
* In this case, the following configuration structure can be used:
*
* \snippet wdc_snippet.c snippet_Cy_WDC_StructCascade
*
* Alternatively, the same settings can be applied using the corresponding WDC
* functions after calling the \ref Cy_WDC_Init function.
* Refer to \ref group_wdc_functions for details.
*
* There are four possible cascading options:
* - \ref CY_WDC_CASCADE_NONE - all counters work independently
* - \ref CY_WDC_CASCADE_COUNTERS01 - counters 0 and 1 are cascaded. If Clean on match
*   is set for both counters total cascaded period will be equal to
*   (C0_Match + 1) * C1_Match
* - \ref CY_WDC_CASCADE_COUNTERS12 - counters 1 and 2 are cascaded. If Clean on match
*   is set for counter 1 total cascaded period will be equal to
*   (C1_Match + 1) * 2<sup>C2_Toggle_bit</sup>
* - \ref CY_WDC_CASCADE_ALL - counters 0, 1 and 2 are cascaded. If Clean on match
*   is set for counters 0 and 1 counters total cascaded period will be equal to
*   (C0_Match + 1) * C1_Match * 2<sup>C2_Toggle_bit</sup>.
*
********************************************************************************
* \subsection group_wdc_interrupt Configure Interrupt
********************************************************************************
* All counter interrupts are OR'd together to form a single combined WDC interrupt.
* To configure a WDC interrupt, initialize the referenced
* interrupt by setting the priority and the interrupt vector using
* \ref Cy_SysInt_Init() of the SysInt driver and provide interrupt handler:
*
* \snippet wdc_snippet.c snippet_Cy_WDC_ISR
* \snippet wdc_snippet.c snippet_Cy_WDC_ISR_Init
*
* Additionally, global interrupts should be enabled.
*
********************************************************************************
* \subsection group_wdc_enable Enable Counters
********************************************************************************
* The last configuration step enables the configured counters using \ref Cy_WDC_Enable function.
*
* \snippet wdc_snippet.c snippet_Cy_WDC_Enable
*
* \note In addition to WDCs, each device has a separate watchdog timer
* (WDT) to generate a watchdog reset or periodic
* interrupts. For detail on the WDT, see \ref group_wdt section.
*
* \section group_wdc_more_information More Information
*
* For detail on the WDC peripheral, refer to
* the technical reference manual (TRM).
*
* \section group_wdc_changelog Changelog
* <table class="doxtable">
*   <tr><th>Version</th><th>Changes</th><th>Reason for Change</th></tr>
*   <tr>
*     <td>1.0.2</td>
*     <td>Update the paths to the code snippets.</td>
*     <td>PDL structure update.</td>
*   </tr>
*   <tr>
*     <td>1.0.1</td>
*     <td>Corrected source code comments text.</td>
*     <td></td>
*   </tr>
*   <tr>
*     <td>1.0</td>
*     <td>Initial version</td>
*     <td></td>
*   </tr>
* </table>
*
* \defgroup group_wdc_macros Macros
* \{
* \defgroup group_wdc_macros_cascading_masks Cascading Masks
* \}
* \defgroup group_wdc_functions Functions
* \defgroup group_wdc_data_structures Data Structures
* \defgroup group_wdc_enums Enumerated Types
*/

#if !defined(CY_WDC_H)
#define CY_WDC_H

#include <stdbool.h>
#include <stddef.h>
#include "cy_device_headers.h"
#include "cy_device.h"
#include "cy_syslib.h"

#if (defined(WCO_WDT_EN) && (WCO_WDT_EN == 1u))

#if defined(__cplusplus)
extern "C" {
#endif

/*******************************************************************************
*       Function Constants
*******************************************************************************/

/**
* \addtogroup group_wdc_macros
* \{
*/

/** Driver major version */
#define CY_WDC_DRV_VERSION_MAJOR       1

/** Driver minor version */
#define CY_WDC_DRV_VERSION_MINOR       0

/** \cond INTERNAL_MACROS */

/***************************************
*        Registers Constants
***************************************/

#define CY_WDC_BYTE_SHIFT     (8U)

#define CY_WDC_CTR0_Pos (0U)
#define CY_WDC_CTR1_Pos (1U)
#define CY_WDC_CTR2_Pos (2U)

#define CY_WDC_CONFIG_MODE_NONE (0UL)
#define CY_WDC_CONFIG_MODE_INTR (1UL)
#define CY_WDC_CONFIG_MODE_MASK (1UL)

#define CY_WDC_CONFIG_MODE0_INTR (_VAL2FLD(WCO_WDT_CONFIG_WDT_MODE0, CY_WDC_CONFIG_MODE_INTR))
#define CY_WDC_CONFIG_MODE1_INTR (_VAL2FLD(WCO_WDT_CONFIG_WDT_MODE1, CY_WDC_CONFIG_MODE_INTR))
#define CY_WDC_CONFIG_MODE2_INTR (_VAL2FLD(WCO_WDT_CONFIG_WDT_MODE2, CY_WDC_CONFIG_MODE_INTR))

#define CY_WDC_CONFIG_LFCLK_SEL_ILO     (0U)
#define CY_WDC_CONFIG_DEFAULT_VAL_MASK  (0xC0000000UL)
#define CY_WDC_CONTROL_RESET_VAL        (0x00808080UL)

/** \endcond */

/***************************************
*            API Constants
***************************************/

#define CY_WDC_ID           CY_PDL_DRV_ID(0x35u)        /**< WDC PDL ID */

#define CY_WDC_COUNTER0_Msk (1UL << CY_WDC_CTR0_Pos)    /**< Counter 0 mask. This macro is used with functions
                                                            that handle multiple counters, including \ref Cy_WDC_Enable(),
                                                            \ref Cy_WDC_Disable(), \ref Cy_WDC_ClearInterrupt() and
                                                            \ref Cy_WDC_ResetCounters(). */
#define CY_WDC_COUNTER1_Msk (1UL << CY_WDC_CTR1_Pos)    /**< Counter 1 mask. This macro is used with functions
                                                            that handle multiple counters, including \ref Cy_WDC_Enable(),
                                                            \ref Cy_WDC_Disable(), \ref Cy_WDC_ClearInterrupt() and
                                                            \ref Cy_WDC_ResetCounters(). */
#define CY_WDC_COUNTER2_Msk (1UL << CY_WDC_CTR2_Pos)    /**< Counter 2 mask. This macro is used with functions
                                                            that handle multiple counters, including \ref Cy_WDC_Enable(),
                                                            \ref Cy_WDC_Disable(), \ref Cy_WDC_ClearInterrupt() and \ref
                                                            Cy_WDC_ResetCounters(). */
#define CY_WDC_COUNTERS_Msk  (CY_WDC_COUNTER0_Msk | \
                              CY_WDC_COUNTER1_Msk | \
                              CY_WDC_COUNTER2_Msk)      /**< The mask for all counters. This macro is used with functions
                                                            that handle multiple counters, including \ref Cy_WDC_Enable(),
                                                            \ref Cy_WDC_Disable(), \ref Cy_WDC_ClearInterrupt() and
                                                            \ref Cy_WDC_ResetCounters(). */

#define CY_WDC_CLK_ILO_CYCLE_US     (63U) /**< One ILO cycle delay value in microseconds. Calculated for worst-case scenario: 40KHz -60% */
#define CY_WDC_CLK_WCO_CYCLE_US     (31U) /**< One WCO cycle delay value in microseconds. Calculated for 32.768KHz WCO. */

#define CY_WDC_CLK_ILO_3CYCLES_US   (3U * CY_WDC_CLK_ILO_CYCLE_US)  /**< Three ILO cycles delay value in microseconds. */
#define CY_WDC_CLK_WCO_3CYCLES_US   (3U * CY_WDC_CLK_WCO_CYCLE_US)  /**< Three WCO cycles delay value in microseconds. */

#define CY_WDC_CLK_ILO_4CYCLES_US   (4U * CY_WDC_CLK_ILO_CYCLE_US)  /**< Three ILO cycles delay value in microseconds. */
#define CY_WDC_CLK_WCO_4CYCLES_US   (4U * CY_WDC_CLK_WCO_CYCLE_US)  /**< Three WCO cycles delay value in microseconds. */

/**
* \addtogroup group_wdc_macros_cascading_masks
* The WDC cascading settings. Used in \ref cy_stc_wdc_config_t configuration structure,
* \ref Cy_WDC_GetCascade and \ref Cy_WDC_SetCascade functions.
* \{
*/

#define CY_WDC_CASCADE_NONE         (0U)                                /**< Cascading is disabled. */
#define CY_WDC_CASCADE_COUNTERS01   (WCO_WDT_CONFIG_WDT_CASCADE0_1_Msk) /**< Counter 1 is clocked by Counter 0. */
#define CY_WDC_CASCADE_COUNTERS12   (WCO_WDT_CONFIG_WDT_CASCADE1_2_Msk) /**< Counter 2 is clocked by Counter 1. */
#define CY_WDC_CASCADE_ALL          (CY_WDC_CASCADE_COUNTERS01 | CY_WDC_CASCADE_COUNTERS12) /**< All three counters are cascaded */
/** \} group_wdc_macros_cascading_masks */

/** \} group_wdc_macros */


/**
* \addtogroup group_wdc_enums
* \{
*/

/** WDC identifiers. */
typedef enum
{
    CY_WDC_COUNTER0 = 0U, /**< Counter 0 identifier. */
    CY_WDC_COUNTER1 = 1U, /**< Counter 1 identifier. */
    CY_WDC_COUNTER2 = 2U  /**< Counter 2 identifier. */
} cy_en_wdc_ctr_t;

/** The WDC clock source */
typedef enum
{
    CY_WDC_CLOCK_ILO = 0U,  /**< Internal Low Frequency Oscillator (ILO). */
    CY_WDC_CLOCK_WCO = 1U   /**< Low Frequency Watch Crystal Oscillator (WCO). */
} cy_en_wdc_clock_t;

/** The WDC error codes. */
typedef enum
{
    CY_WDC_SUCCESS = 0x00U,                                         /**< Successful */
    CY_WDC_BAD_PARAM = CY_WDC_ID | CY_PDL_STATUS_ERROR | 0x01U,     /**< One or more invalid parameters */
} cy_en_wdc_status_t;

/** \} group_wdc_enums */


/**
* \addtogroup group_wdc_data_structures
* \{
*/

/** The WDC component configuration structure. */
typedef struct
{
    uint16_t counter0Match;         /**< Counter 0 match comparison value, used for interrupt generation.
                                        Range: 0 - 65535 for counter0ClearOnMatch = 0 and 1 - 65535 for
                                        counter0ClearOnMatch = 1. */
    uint16_t counter1Match;         /**< Counter 1 match comparison value, used for interrupt generation.
                                        Range: 0 - 65535 for counter1ClearOnMatch = 0 and 1 - 65535 for
                                        counter1ClearOnMatch = 1. */
    uint8_t counter2ToggleBit;      /**< Counter 2 Period / Toggle Bit value.
                                        Range: 0 - 31. */
    bool counter0Interrupt;         /**< Enable/Disable interrupt from Counter 0 */
    bool counter1Interrupt;         /**< Enable/Disable interrupt from Counter 1 */
    bool counter2Interrupt;         /**< Enable/Disable interrupt from Counter 2 */
    bool counter0ClearOnMatch;      /**< Enable/Disable Counter 0 Clear On Match parameter. */
    bool counter1ClearOnMatch;      /**< Enable/Disable Counter 1 Clear On Match parameter. */
    uint32_t countersCascade;       /**< Counters cascading configuration. Refer to \ref group_wdc_macros_cascading_masks
                                         Cascading defines clock source for counters 1 and 2. Possible options are WDC clock source or previous counter.
                                         When cascading all three counters, counter1ClearOnMatch must be enabled. */
    cy_en_wdc_clock_t clockSource;  /**< The WDC clock source. It can have one of the following values: \ref CY_WDC_CLOCK_ILO or
                                         \ref CY_WDC_CLOCK_WCO.*/
} cy_stc_wdc_config_t;

/** \} group_wdc_data_structures */


/** \cond PARAM_CHECK_MACROS */

/** Parameter check macros */
#define CY_WDC_IS_CNTS_MASK_VALID(counters)  (0U == ((counters) & (uint32_t)~CY_WDC_COUNTERS_Msk))

#define CY_WDC_IS_CNT_NUM_VALID(counter)     ((CY_WDC_COUNTER0 == (counter)) || \
                                             (CY_WDC_COUNTER1 == (counter))  || \
                                             (CY_WDC_COUNTER2 == (counter)))

#define CY_WDC_IS_ENABLE_VALID(enable)       (1UL >= (enable))

#define CY_WDC_IS_CASCADE_VALID(cascade)     (0UL == ((cascade) & ~CY_WDC_CASCADE_ALL))

#define CY_WDC_IS_MATCH_VALID(clearOnMatch, match)  ((clearOnMatch) ? (1UL <= (match)) : true)

#define CY_WDC_IS_BIT_VALID(bit)             (31UL >= (bit))

#define CY_WDC_IS_CLOCK_VALID(source)        ((CY_WDC_CLOCK_WCO == (source)) || \
                                             (CY_WDC_CLOCK_ILO == (source)))

/** \endcond */



/*******************************************************************************
*        Function Prototypes
*******************************************************************************/
/**
* \addtogroup group_wdc_functions
* \{
*/
cy_en_wdc_status_t                  Cy_WDC_Init(WCO_Type *base, cy_stc_wdc_config_t const *config);
                void                Cy_WDC_DeInit(WCO_Type *base);
__STATIC_INLINE void                Cy_WDC_Enable(WCO_Type *base, uint32_t counters, uint16_t waitUs);
__STATIC_INLINE void                Cy_WDC_Disable(WCO_Type *base, uint32_t counters, uint16_t waitUs);
__STATIC_INLINE uint32_t            Cy_WDC_GetEnabledStatus(WCO_Type const *base, cy_en_wdc_ctr_t counter);
__STATIC_INLINE void                Cy_WDC_InterruptEnable(WCO_Type *base, cy_en_wdc_ctr_t counter);
__STATIC_INLINE void                Cy_WDC_InterruptDisable(WCO_Type *base, cy_en_wdc_ctr_t counter);
__STATIC_INLINE bool                Cy_WDC_GetInterruptSetting(WCO_Type const *base, cy_en_wdc_ctr_t counter);
__STATIC_INLINE void                Cy_WDC_SetClearOnMatch(WCO_Type *base, cy_en_wdc_ctr_t counter, uint32_t enable);
__STATIC_INLINE uint32_t            Cy_WDC_GetClearOnMatch(WCO_Type const *base, cy_en_wdc_ctr_t counter);
__STATIC_INLINE void                Cy_WDC_SetCascade(WCO_Type *base, uint32_t cascade);
__STATIC_INLINE uint32_t            Cy_WDC_GetCascade(WCO_Type const *base);
__STATIC_INLINE void                Cy_WDC_SetMatch(WCO_Type *base, cy_en_wdc_ctr_t counter, uint32_t match, uint16_t waitUs);
__STATIC_INLINE uint32_t            Cy_WDC_GetMatch(WCO_Type const *base, cy_en_wdc_ctr_t counter);
__STATIC_INLINE void                Cy_WDC_SetToggleBit(WCO_Type *base, uint32_t bit);
__STATIC_INLINE uint32_t            Cy_WDC_GetToggleBit(WCO_Type const *base);
__STATIC_INLINE uint32_t            Cy_WDC_GetCount(WCO_Type const *base, cy_en_wdc_ctr_t counter);
__STATIC_INLINE void                Cy_WDC_ResetCounters(WCO_Type *base, uint32_t counters, uint16_t waitUs);
__STATIC_INLINE uint32_t            Cy_WDC_GetInterruptStatus(WCO_Type const *base);
__STATIC_INLINE void                Cy_WDC_ClearInterrupt(WCO_Type *base, uint32_t counters);
                uint32_t            Cy_WDC_GetCountCascaded(WCO_Type const *base);
__STATIC_INLINE cy_en_wdc_clock_t   Cy_WDC_GetClockSource(WCO_Type const *base);
                void                Cy_WDC_SetClockSource(WCO_Type *base, cy_en_wdc_clock_t source);


/*******************************************************************************
* Function Name: Cy_WDC_Enable
****************************************************************************//**
*
*  Enables all specified counters.
*
*  \param base
*  The base pointer to a structure that describes registers.
*
*  \param counters
*  OR of all counters to enable. See the \ref CY_WDC_COUNTER0_Msk,
*  \ref CY_WDC_COUNTER1_Msk, and \ref CY_WDC_COUNTER2_Msk macros.
*
*  \param waitUs
*  The function waits for some delay in microseconds before returning,
*  because the counter begins counting after three WDC clock-source cycles pass.
*  The recommended waitUs parameter value is defined by
*  \ref CY_WDC_CLK_ILO_3CYCLES_US and \ref CY_WDC_CLK_WCO_3CYCLES_US macros.
*  \note
*  Setting this parameter to a zero means No wait. In this case, it is
*  the user's responsibility to check whether the selected counters were enabled
*  immediately after the function call. This can be done by the
*  Cy_WDC_GetEnabledStatus() API.
*
*******************************************************************************/
__STATIC_INLINE void Cy_WDC_Enable(WCO_Type *base, uint32_t counters, uint16_t waitUs)
{
    CY_ASSERT_L2(CY_WDC_IS_CNTS_MASK_VALID(counters));

    /* Extract particular counters for enable */
    WCO_WDT_CONTROL(base) |=
            ((0UL != (counters & CY_WDC_COUNTER0_Msk)) ? WCO_WDT_CONTROL_WDT_ENABLE0_Msk : 0UL) |
            ((0UL != (counters & CY_WDC_COUNTER1_Msk)) ? WCO_WDT_CONTROL_WDT_ENABLE1_Msk : 0UL) |
            ((0UL != (counters & CY_WDC_COUNTER2_Msk)) ? WCO_WDT_CONTROL_WDT_ENABLE2_Msk : 0UL);

    Cy_SysLib_DelayUs(waitUs);
}


/*******************************************************************************
* Function Name: Cy_WDC_Disable
****************************************************************************//**
*
*  Disables all specified counters.
*
*  \param base
*  The base pointer to a structure describing registers.
*
*  \param counters
*  OR of all counters to disable. See the \ref CY_WDC_COUNTER0_Msk,
*  \ref CY_WDC_COUNTER1_Msk, and \ref CY_WDC_COUNTER2_Msk macros.
*
*  \param waitUs
*  The function waits for some delay in microseconds before returning,
*  because the counter stops counting after three WDC clock source cycles pass.
*  The recommended waitUs parameter value is defined by
*  \ref CY_WDC_CLK_ILO_3CYCLES_US and \ref CY_WDC_CLK_WCO_3CYCLES_US macros.
*  \note
*  Setting this parameter to a zero means No wait. In this case, it is
*  the user's responsibility to check whether the selected counters were disabled
*  immediately after the function call. This can be done by the
*  Cy_WDC_GetEnabledStatus() API.
*
*******************************************************************************/
__STATIC_INLINE void Cy_WDC_Disable(WCO_Type *base, uint32_t counters, uint16_t waitUs)
{
    CY_ASSERT_L2(CY_WDC_IS_CNTS_MASK_VALID(counters));

    /* Extract particular counters for disable */
    WCO_WDT_CONTROL(base) &=
            ~(((0UL != (counters & CY_WDC_COUNTER0_Msk)) ? WCO_WDT_CONTROL_WDT_ENABLE0_Msk : 0UL) |
              ((0UL != (counters & CY_WDC_COUNTER1_Msk)) ? WCO_WDT_CONTROL_WDT_ENABLE1_Msk : 0UL) |
              ((0UL != (counters & CY_WDC_COUNTER2_Msk)) ? WCO_WDT_CONTROL_WDT_ENABLE2_Msk : 0UL));

    Cy_SysLib_DelayUs(waitUs);
}


/*******************************************************************************
* Function Name: Cy_WDC_GetEnabledStatus
****************************************************************************//**
*
*  Reports the enabled status of the specified counter.
*
*  \param base
*  The base pointer to a structure that describes registers.
*
*  \param counter
*   The number of the WDT counter. See \ref cy_en_wdc_ctr_t
*
*  \return
*  The status of the WDC counter: 0 = disabled, 1 = enabled.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_WDC_GetEnabledStatus(WCO_Type const *base, cy_en_wdc_ctr_t counter)
{
    uint32_t status = 0u;

    CY_ASSERT_L3(CY_WDC_IS_CNT_NUM_VALID(counter));

    switch (counter)
    {
        case CY_WDC_COUNTER0:
            status = _FLD2VAL(WCO_WDT_CONTROL_WDT_ENABLED0, WCO_WDT_CONTROL(base));
            break;
        case CY_WDC_COUNTER1:
            status = _FLD2VAL(WCO_WDT_CONTROL_WDT_ENABLED1, WCO_WDT_CONTROL(base));
            break;
        case CY_WDC_COUNTER2:
            status = _FLD2VAL(WCO_WDT_CONTROL_WDT_ENABLED2, WCO_WDT_CONTROL(base));
            break;

        default:
            CY_ASSERT(0u != 0u);
        break;
    }

    return (status);
}

/*******************************************************************************
* Function Name: Cy_WDC_InterruptEnable
****************************************************************************//**
*
*  Enables interrupt generation for the specified counter.
*
*  \param base
*  The base pointer to a structure that describes registers.
*
*  \param counter
*   The number of the WDT counter. See \ref cy_en_wdc_ctr_t
*
*  \note
*  Do not call this function while the counters are running.
*  Disable the counter prior to calling this function using \ref Cy_WDC_Disable.
*
*******************************************************************************/
__STATIC_INLINE void Cy_WDC_InterruptEnable(WCO_Type *base, cy_en_wdc_ctr_t counter)
{
    uint32_t mask;
    uint32_t shift;

    CY_ASSERT_L3(CY_WDC_IS_CNT_NUM_VALID(counter));

    shift = CY_WDC_BYTE_SHIFT * ((uint32_t)counter);
    mask = CY_WDC_CONFIG_MODE_MASK << shift;

    WCO_WDT_CONFIG(base) = (WCO_WDT_CONFIG(base) & ~mask) | (CY_WDC_CONFIG_MODE_INTR << shift);
}


/*******************************************************************************
* Function Name: Cy_WDC_InterruptDisable
****************************************************************************//**
*
*  Disables interrupt generation for the specified counter.
*
*  \param base
*  The base pointer to a structure that describes registers.
*
*  \param counter
*   The number of the WDT counter. See \ref cy_en_wdc_ctr_t
*
*  \note
*  Do not call tis function while the counters are running.
*  Disable the counter prior to calling this function using \ref Cy_WDC_Disable.
*
*******************************************************************************/
__STATIC_INLINE void Cy_WDC_InterruptDisable(WCO_Type *base, cy_en_wdc_ctr_t counter)
{
    uint32_t mask;
    uint32_t shift;

    CY_ASSERT_L3(CY_WDC_IS_CNT_NUM_VALID(counter));

    shift = CY_WDC_BYTE_SHIFT * ((uint32_t)counter);
    mask = CY_WDC_CONFIG_MODE_MASK << shift;

    WCO_WDT_CONFIG(base) = (WCO_WDT_CONFIG(base) & ~mask) | (CY_WDC_CONFIG_MODE_NONE << shift);
}


/*******************************************************************************
* Function Name: Cy_WDC_GetInterruptSetting
****************************************************************************//**
*
*  Reports interrupt setting for specified counter.
*
*  \param base
*  The base pointer to a structure that describes registers.
*
*  \param counter
*   The number of the WDT counter. See \ref cy_en_wdc_ctr_t
*
*  \return
*  The current setting of the counter.
*  true  - interrupt enabled
*  false - interrupt disabled.
*
*******************************************************************************/
__STATIC_INLINE bool Cy_WDC_GetInterruptSetting(WCO_Type const *base, cy_en_wdc_ctr_t counter)
{
    uint32_t mask;

    CY_ASSERT_L3(CY_WDC_IS_CNT_NUM_VALID(counter));

    mask = CY_WDC_CONFIG_MODE_MASK << (CY_WDC_BYTE_SHIFT * ((uint32_t)counter));

    return (0UL != (WCO_WDT_CONFIG(base) & mask));
}


/*******************************************************************************
* Function Name: Cy_WDC_SetClearOnMatch
****************************************************************************//**
*
*  Sets the Clear on match option for the specified counter.
*
*  \param base
*  The base pointer to a structure that describes registers.
*
*  \param counter
*   The number of the WDT counter. See \ref cy_en_wdc_ctr_t
*
*  \note
*  The match values are not supported by Counter 2.
*
*  \param enable
*  Set 0 to disable; 1 to enable.
*
*  \note
*  Do not call this function while the counters are running.
*  Disable the counter prior to calling this function using \ref Cy_WDC_Disable.
*
*******************************************************************************/
__STATIC_INLINE void Cy_WDC_SetClearOnMatch(WCO_Type *base, cy_en_wdc_ctr_t counter, uint32_t enable)
{
    CY_ASSERT_L3(CY_WDC_IS_CNT_NUM_VALID(counter));
    CY_ASSERT_L2(CY_WDC_IS_ENABLE_VALID(enable));

    if (CY_WDC_COUNTER0 == counter)
    {
        WCO_WDT_CONFIG(base) = _CLR_SET_FLD32U(WCO_WDT_CONFIG(base), WCO_WDT_CONFIG_WDT_CLEAR0, enable);
    }
    else
    {
        WCO_WDT_CONFIG(base) = _CLR_SET_FLD32U(WCO_WDT_CONFIG(base), WCO_WDT_CONFIG_WDT_CLEAR1, enable);
    }
}


/*******************************************************************************
* Function Name: Cy_WDC_GetClearOnMatch
****************************************************************************//**
*
*  Reports the Clear on match setting for the specified counter.
*
*  \param base
*  The base pointer to a structure that describes registers.
*
*  \param counter
*   The number of the WDT counter. See \ref cy_en_wdc_ctr_t
*
*  \return
*  The Clear on match status: 1 = enabled, 0 = disabled.
*
*  \note
*  The match value is not supported by Counter 2.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_WDC_GetClearOnMatch(WCO_Type const *base, cy_en_wdc_ctr_t counter)
{
    uint32_t getClear;

    CY_ASSERT_L3(CY_WDC_IS_CNT_NUM_VALID(counter));

    if (CY_WDC_COUNTER0 == counter)
    {
        getClear = _FLD2VAL(WCO_WDT_CONFIG_WDT_CLEAR0, WCO_WDT_CONFIG(base));
    }
    else
    {
        getClear = _FLD2VAL(WCO_WDT_CONFIG_WDT_CLEAR1, WCO_WDT_CONFIG(base));
    }

    return (getClear);
}


/*******************************************************************************
* Function Name: Cy_WDC_SetCascade
****************************************************************************//**
*
*  Sets all the counter cascade options.
*
*  \param base
*  The base pointer to a structure that describes registers.
*
*  \param cascade
*  Sets or clears each of the cascade options \ref group_wdc_macros_cascading_masks.
*
*  \note
*  Do not call this function when the counters are running.
*  Disable counters to be cascaded prior to calling this function
*  using \ref Cy_WDC_Disable.
*
*  \note
*  When cascading all three counters, enable the Clear on match option for
*  counter 1.
*
*******************************************************************************/
__STATIC_INLINE void Cy_WDC_SetCascade(WCO_Type *base, uint32_t cascade)
{
    CY_ASSERT_L3(CY_WDC_IS_CASCADE_VALID(cascade));

    WCO_WDT_CONFIG(base) = CY_WDC_CASCADE_ALL & cascade;
}


/*******************************************************************************
* Function Name: Cy_WDC_GetCascade
****************************************************************************//**
*
*  Reports all the counter cascade option settings.
*
*  \param base
*  The base pointer to a structure that describes registers.
*
*  \return
*  The current cascade option values \ref group_wdc_macros_cascading_masks.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_WDC_GetCascade(WCO_Type const *base)
{
    return (CY_WDC_CASCADE_ALL & WCO_WDT_CONFIG(base));
}


/*******************************************************************************
* Function Name: Cy_WDC_SetMatch
****************************************************************************//**
*
*  Sets the match comparison value for the specified counter (0 or 1).
*
*  \param base
*  The base pointer to a structure that describes registers.
*
*  \param counter
*   The number of the WDT counter. See \ref cy_en_wdc_ctr_t
*
*  \param match
*  The value to match against the counter.
*  The valid range is [0-65535] for c0ClearOnMatch (or c1ClearOnMatch) = 0
*  and [1-65535] for c0ClearOnMatch (or c1ClearOnMatch) = 1.
*
*  \note
*  The match value is not supported by Counter 2.
*
*  \note
*  The match is done on the next increment after the counter value
*  equals the match value.
*
*  \param waitUs
*  The function waits for some delay in microseconds before returning,
*  because the match affects after three WDC clock source cycles pass.
*  The recommended waitUs parameter value is defined by
*  \ref CY_WDC_CLK_ILO_3CYCLES_US and \ref CY_WDC_CLK_WCO_3CYCLES_US macros.
*  \note
*  Setting this parameter to a zero means No wait. Take this
*  into account when changing the match values on the running counters.
*
*******************************************************************************/
__STATIC_INLINE void Cy_WDC_SetMatch(WCO_Type *base, cy_en_wdc_ctr_t counter, uint32_t match, uint16_t waitUs)
{
    CY_ASSERT_L3(CY_WDC_IS_CNT_NUM_VALID(counter));
    CY_ASSERT_L2(CY_WDC_IS_MATCH_VALID((CY_WDC_COUNTER0 == counter) ?                                     \
                                         ((WCO_WDT_CONFIG(base) & WCO_WDT_CONFIG_WDT_CLEAR0_Msk) > 0U) :  \
                                         ((WCO_WDT_CONFIG(base) & WCO_WDT_CONFIG_WDT_CLEAR1_Msk) > 0U),   \
                                          match));

    WCO_WDT_MATCH(base) = (counter == CY_WDC_COUNTER0) ?
        _CLR_SET_FLD32U(WCO_WDT_MATCH(base), WCO_WDT_MATCH_WDT_MATCH0, match) :
        _CLR_SET_FLD32U(WCO_WDT_MATCH(base), WCO_WDT_MATCH_WDT_MATCH1, match);

    Cy_SysLib_DelayUs(waitUs);
}


/*******************************************************************************
* Function Name: Cy_WDC_GetMatch
****************************************************************************//**
*
*  Reports the match comparison value for the specified counter (0 or 1).
*
*  \param base
*  The base pointer to a structure that describes registers.
*
*  \param counter
*   The number of the WDT counter. See \ref cy_en_wdc_ctr_t
*
*  \note
*  The match values are not supported by Counter 2.
*
*  \return
*  A 16-bit match value.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_WDC_GetMatch(WCO_Type const *base, cy_en_wdc_ctr_t counter)
{
    uint32_t match;

    CY_ASSERT_L3(CY_WDC_IS_CNT_NUM_VALID(counter));

    match = (counter == CY_WDC_COUNTER0) ? _FLD2VAL(WCO_WDT_MATCH_WDT_MATCH0, WCO_WDT_MATCH(base)) :
                                          _FLD2VAL(WCO_WDT_MATCH_WDT_MATCH1, WCO_WDT_MATCH(base));

    return (match);
}


/*******************************************************************************
* Function Name: Cy_WDC_SetToggleBit
****************************************************************************//**
*
*  Sets a bit in Counter 2 to monitor for a toggle.
*
*  \param base
*  The base pointer to a structure that describes registers.
*
*  \param bit
*  The Counter 2 bit is set to monitor for a toggle. The valid range [0-31].
*
*  \note
*  Do not call this function when the counter is running.
*  Disable the counter prior to calling this function using \ref Cy_WDC_Disable.
*
*******************************************************************************/
__STATIC_INLINE void Cy_WDC_SetToggleBit(WCO_Type *base, uint32_t bit)
{
    CY_ASSERT_L2(CY_WDC_IS_BIT_VALID(bit));

    WCO_WDT_CONFIG(base) = _CLR_SET_FLD32U(WCO_WDT_CONFIG(base), WCO_WDT_CONFIG_WDT_BITS2, bit);
}


/*******************************************************************************
* Function Name: Cy_WDC_GetToggleBit
****************************************************************************//**
*
*  Reports which bit in Counter 2 is monitored for a toggle.
*
*  \param base
*  The base pointer to a structure that describes registers.
*
*  \return
*  The bit that is monitored (range 0 to 31).
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_WDC_GetToggleBit(WCO_Type const *base)
{
    return (_FLD2VAL(WCO_WDT_CONFIG_WDT_BITS2, WCO_WDT_CONFIG(base)));
}


/*******************************************************************************
* Function Name: Cy_WDC_GetCount
****************************************************************************//**
*
*  Reports the current counter value of the specified counter.
*
*  \param base
*  The base pointer to a structure that describes registers.
*
*  \param counter
*   The number of the WDT counter. See \ref cy_en_wdc_ctr_t
*
*  \return
*  A live counter value. Counters 0 and 1 are 16-bit counters and Counter 2 is
*  a 32-bit counter.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_WDC_GetCount(WCO_Type const *base, cy_en_wdc_ctr_t counter)
{
    uint32_t countVal = 0u;

    CY_ASSERT_L3(CY_WDC_IS_CNT_NUM_VALID(counter));

    switch (counter)
    {
        case CY_WDC_COUNTER0:
            countVal = _FLD2VAL(WCO_WDT_CTRLOW_WDT_CTR0, WCO_WDT_CTRLOW(base));
            break;
        case CY_WDC_COUNTER1:
            countVal = _FLD2VAL(WCO_WDT_CTRLOW_WDT_CTR1, WCO_WDT_CTRLOW(base));
            break;
        case CY_WDC_COUNTER2:
            countVal = _FLD2VAL(WCO_WDT_CTRHIGH_WDT_CTR2, WCO_WDT_CTRHIGH(base));
            break;

        default:
            CY_ASSERT_L1(false);
        break;
    }

    return (countVal);
}


/*******************************************************************************
* Function Name: Cy_WDC_ResetCounters
****************************************************************************//**
*
*  Resets all specified counters.
*
*  \param base
*  The base pointer to a structure that describes registers.
*
*  \param counters
*  OR of all counters to reset. See the \ref CY_WDC_COUNTER0_Msk,
*  \ref CY_WDC_COUNTER1_Msk, and \ref CY_WDC_COUNTER2_Msk  macros.
*
*  \param waitUs
*  The function waits for some delay in microseconds before returning, because
*  a reset occurs after three WDC clock source cycle passes.
*  The recommended waitUs parameter value is defined by
*  \ref CY_WDC_CLK_ILO_3CYCLES_US and \ref CY_WDC_CLK_WCO_3CYCLES_US macros.
*  \note
*  Setting this parameter to a zero means No wait. In this case, it is the
*  user's responsibility to check whether the selected counters were reset
*  immediately after the function call. This can be done by the
*  Cy_WDC_GetCount() API.
*
*******************************************************************************/
__STATIC_INLINE void Cy_WDC_ResetCounters(WCO_Type *base, uint32_t counters, uint16_t waitUs)
{
    CY_ASSERT_L2(CY_WDC_IS_CNTS_MASK_VALID(counters));

    /* Extract particular counters for reset */
    WCO_WDT_CONTROL(base) |=
            ((0UL != (counters & CY_WDC_COUNTER0_Msk)) ? WCO_WDT_CONTROL_WDT_RESET0_Msk : 0UL) |
            ((0UL != (counters & CY_WDC_COUNTER1_Msk)) ? WCO_WDT_CONTROL_WDT_RESET1_Msk : 0UL) |
            ((0UL != (counters & CY_WDC_COUNTER2_Msk)) ? WCO_WDT_CONTROL_WDT_RESET2_Msk : 0UL);

    Cy_SysLib_DelayUs(waitUs);
}


/*******************************************************************************
* Function Name: Cy_WDC_GetInterruptStatus
****************************************************************************//**
*
*  Reports the state of all WDC interrupts.
*
*  \param base
*  The base pointer to a structure that describes registers.
*
*  \return
*  The OR'd state of the interrupts. See the \ref CY_WDC_COUNTER0_Msk,
*  \ref CY_WDC_COUNTER1_Msk, and \ref CY_WDC_COUNTER2_Msk macros.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_WDC_GetInterruptStatus(WCO_Type const *base)
{
    uint32_t status;

    status = WCO_WDT_CONTROL(base);

    status = (_FLD2VAL(WCO_WDT_CONTROL_WDT_INT0, status) << CY_WDC_CTR0_Pos) |
             (_FLD2VAL(WCO_WDT_CONTROL_WDT_INT1, status) << CY_WDC_CTR1_Pos) |
             (_FLD2VAL(WCO_WDT_CONTROL_WDT_INT2, status) << CY_WDC_CTR2_Pos);

    return (status);
}


/*******************************************************************************
* Function Name: Cy_WDC_ClearInterrupt
****************************************************************************//**
*
*  Clears all specified WDC interrupts.
*
*  All the WDT interrupts must be cleared by the firmware; otherwise
*  interrupts are generated continuously.
*
*  \param base
*  The base pointer to a structure describes registers.
*
*  \param counters
*  OR of all interrupt sources to clear. See the \ref CY_WDC_COUNTER0_Msk,
*  \ref CY_WDC_COUNTER1_Msk, and CY_WDC_COUNTER2_Msk  macros.
*
*******************************************************************************/
__STATIC_INLINE void Cy_WDC_ClearInterrupt(WCO_Type *base, uint32_t counters)
{
    uint32_t interruptState;

    CY_ASSERT_L2(CY_WDC_IS_CNTS_MASK_VALID(counters));

    /* Enter critical section before modifying the register */
    interruptState = Cy_SysLib_EnterCriticalSection();

    WCO_WDT_CONTROL(base)|=
            _BOOL2FLD(WCO_WDT_CONTROL_WDT_INT0, (counters & CY_WDC_COUNTER0_Msk) != 0U) |
            _BOOL2FLD(WCO_WDT_CONTROL_WDT_INT1, (counters & CY_WDC_COUNTER1_Msk) != 0U) |
            _BOOL2FLD(WCO_WDT_CONTROL_WDT_INT2, (counters & CY_WDC_COUNTER2_Msk) != 0U);

    /* Read the CY_SYS_WDT_CONTROL_REG to clear the interrupt request.*/
    (void)WCO_WDT_CONTROL(base);

    Cy_SysLib_ExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: GetClockSource
****************************************************************************//**
*
*  Returns the clock source for WDC timers.
*
*  \param base
*  The base pointer to a structure describes registers.
*
*  \return
*  The WDC timers clock source. See \ref cy_en_wdc_clock_t
*
*******************************************************************************/
__STATIC_INLINE cy_en_wdc_clock_t Cy_WDC_GetClockSource(WCO_Type const *base)
{
    return ((CY_WDC_CONFIG_LFCLK_SEL_ILO == _FLD2VAL(WCO_WDT_CONFIG_LFCLK_SEL, WCO_WDT_CONFIG(base))) ?
            CY_WDC_CLOCK_ILO : CY_WDC_CLOCK_WCO);
}


/** \} group_wdc_functions */


#if defined(__cplusplus)
}
#endif

#endif /* WCO_WDT_EN */

#endif /* CY_WDC_H */

/** \} group_wdc */


/* [] END OF FILE */
