/***************************************************************************//**
* \file cy_ppca_epu.h
* \version 1.00
*
* Provides the API declarations of the PPCA EPU driver.
*
********************************************************************************
* \copyright
* (c) 2024-2026, Infineon Technologies AG or an affiliate of
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
*******************************************************************************/
/**
* \addtogroup group_ppca_epu
* \{
* The EPU (Event Processing Unit) driver provides an interface to the
* hardware event processing and trigger routing engine within the
* Programmable Power Control Accelerator (PPCA).
* The EPU creates hardware sequences of processed, timed triggers to enable
* autonomous subsystem operation, offloading the embedded processors from
* real-time event management tasks.
*
* \section group_ppca_epu_overview Overview
*
* The EPU subsystem (EPU_SS) consists of:
* - <b>EPU module:</b> 32 Processing Units Type 1 (PU_T1) and 16 Processing
*   Units Type 2 (PU_T2)
* - <b>EPU IRQ Generator:</b> Multiplexes up to 8 COMBO outputs as interrupt
*   sources for the PPSS CPUs
* - <b>AHB2AHB bus bridge:</b> Provides bus isolation
*
* <b>Processing Unit Architecture:</b>
*
* Each Processing Unit processes its input through two stages:
* - <b>PRESTAGE:</b> Input qualification with source selection, polarity
*   inversion, and rising-edge extraction
* - <b>MXSTAGE:</b> Signal conditioning (PU_T1 only) with one of four
*   processing functions:
*   - Rising Edge Extraction with pulse delay (up to 128 clock cycles)
*   - Masking: suppresses input for a configured duration after the first
*     valid transition
*   - Blanking: suppresses input after detection of the first valid
*     transition (rising and falling) for a configured duration
*   - Debouncing: requires the input to remain stable for a configured
*     number of clock cycles before the output changes
*
* PU_T2 modules provide a simpler path with PRESTAGE only (bypass, polarity
* inversion, and edge extraction), without the MXSTAGE processing functions.
*
* <b>COMBO Section:</b>
*
* The 123 COMBO blocks perform linear combination (logical AND) of selected
* PU outputs to form the EPU trigger outputs (EVOUT[122:0]). Each COMBO
* block can select:
* - A pair of PU_T1 outputs from PUT1_OUT[0:15] (via bank selection)
* - One PU_T1 output from PUT1_OUT[16:31] and one PU_T2 output from
*   PUT2_OUT[0:15]
* - An optional qualifier signal from PUT1_OUT[28:31] or PUT2_OUT[12:15]
* - Output polarity inversion
*
* <b>Event Inputs (256 total):</b>
* Events are sourced from all PPSS peripherals including MXTCPWM (PWM
* counters and MOTIF), HW Filters, CLB, ATOPSS (ADC, DCSG), the PPSS CPUs,
* and external trigger inputs.
*
* <b>Trigger Outputs (123 total):</b>
* EVOUT signals are routed to MXTCPWM, CLB, ADC (SOC, sampling window,
* MIN/MAX triggers), DCSG comparator triggers, DMA requests, CPU interrupts,
* external pins, and PPSS_CNFG control signals.
*
* <b>COMBO Feedback:</b>
* Up to 8 COMBO outputs can be fed back into the EPU input space via the
* COMBO_FB path, enabling cascaded trigger logic.
*
* <b>Resource Allocation:</b>
* PU and COMBO resources can be allocated to CPU0 or CPU1 via the
* PPSS_CNFG.CNFG1 register. Exclusive access enforcement can be enabled
* or disabled at runtime.
*
* <b>Software Events:</b>
* Each PU can generate a software event by enabling constant-input mode
* and setting the constant input level, allowing the CPU to inject events
* into the hardware trigger network.
*
* \section group_ppca_epu_use_cases Typical Use Cases
* - Synchronizing multiple PWM outputs with hardware-timed enable/disable
* - LLC, Totem Pole PFC, and 3L-ANPC power converter control
* - Protection shutdown: disabling PWM outputs on comparator trip events
* - Propagating interrupts to the Main CPU based on event combinations
* - Event-based control algorithms (e.g., comparator-triggered PWM kill)
* \section group_ppca_epu_changelog Changelog
* <table class="doxtable">
*   <tr><th>Version</th><th>Changes</th><th>Reason for Change</th></tr>
*   <tr>
*     <td>1.0</td>
*     <td>Initial version</td>
*     <td></td>
*   </tr>
* </table>
* \defgroup group_ppca_epu_functions Functions
* \defgroup group_ppca_epu_structures Configuration Structures
* \defgroup group_ppca_epu_enums Enumerations
* \defgroup group_ppca_epu_macros Macros
*
*/
#if !defined(CY_PPCA_EPU_H)
#define CY_PPCA_EPU_H

#include "cy_device.h"

#if defined (CY_IP_MXS40PPSS) || defined (CY_DOXYGEN)

#include "cy_syslib.h"

#if defined(__cplusplus)
extern "C" {
#endif

/***************************************
*       Macros
***************************************/

/**
* \addtogroup group_ppca_epu_macros
* \{
*/
/** The driver major version */
#define CY_PPCA_EPU_DRV_VERSION_MAJOR       1U

/** The driver minor version */
#define CY_PPCA_EPU_DRV_VERSION_MINOR       0U

/** The PPCA EPU driver ID */
#define CY_PPCA_EPU_ID               CY_PDL_DRV_ID(CY_PDL_RSLT_MODULE_PPCA_EPU)

/** \cond INTERNAL */

#define CY_IS_PARAM_VALID(base)              (NULL != base)
#define CY_IS_PUT1_INDEX_VALID(index)        (index <= 31u)
#define CY_IS_PUT2_INDEX_VALID(index)        (index <= 15u)
#define CY_IS_COMBO_INDEX_VALID(index)       (index <= 122u)
#define CY_IS_COMBO_FB_INDEX_VALID(index)    (index <= 7u)

/** \endcond */

/** \} group_ppca_epu_macros */


/***************************************
*       Enumerations
***************************************/
/**
* \addtogroup group_ppca_epu_enums
* \{
*/

/** PPCA epu status enumeration */
typedef enum
{
    CY_PPCA_EPU_SUCCESS = 0U,                                             /**< Returned successful */
    CY_PPCA_EPU_BAD_PARAM = (CY_PPCA_EPU_ID | CY_PDL_STATUS_ERROR | 1U), /**< Bad parameter was passed */
} cy_en_ppca_epu_status_t;


/** Enable/Disable and Bypass Configuration of Processing Unit.
 *  Controls whether the PU is disabled, enabled with full processing, or
 *  enabled in bypass mode (synchronous or asynchronous pass-through). */
typedef enum
{
    CY_PU_DISABLE          = 0U, /**< Disable PU; output is inactive */
    CY_ENABLE_ASYNC_BYPASS = 1U, /**< Enable PU in asynchronous bypass (input passes through without clock synchronization) */
    CY_ENABLE_SYNC_BYPASS  = 2U, /**< Enable PU in synchronous bypass (input passes through synchronized to EPU clock) */
    CY_ENABLE_PU           = 3U, /**< Enable PU with full PRESTAGE and MXSTAGE processing */
} cy_en_ppca_epu_en_pu_t;


/** PU Input Selection.
 *  Selects whether the MXSTAGE (PU_T1) or output (PU_T2) receives the
 *  level signal or the rising-edge-extracted signal from the PRESTAGE. */
typedef enum
{
    CY_LEVEL_SIGNAL        = 0U,   /**< Use the level output of the Polarity Inversion stage */
    CY_EDGE_SIGNAL         = 1U,   /**< Use the rising-edge extracted output of the Polarity Inversion stage */
} cy_en_ppca_epu_input_pu_t;

/** Constant Input Level from PU */
typedef enum
{
    CY_CONSTANT_0        = 0U,   /**< Constant 0 is sent to combiner */
    CY_CONSTANT_1        = 1U,   /**< Constant 1 is sent to combiner */
} cy_en_ppca_epu_constant_level_t;


/** PU_T1 MXSTAGE Processing Function.
 *  Selects the signal conditioning operation applied in the MXSTAGE of
 *  a Type 1 Processing Unit. The DATA field (clk_cycles) configures the
 *  duration parameter for each function (0-127 EPU clock cycles). */
typedef enum
{
    CY_EXTRACT_RISING_EDGE        = 0U,   /**< Extract rising edge and delay the output pulse by DATA clock cycles */
    CY_MASK_INPUT_SIGNAL          = 1U,   /**< Mask (suppress) input for DATA clock cycles after the first valid transition */
    CY_BLANK_INPUT_SIGNAL         = 2U,   /**< Blank (suppress) input for DATA clock cycles after any transition (rising or falling) */
    CY_DEBOUNCE_INPUT_SIGNAL      = 3U,   /**< Debounce input: output changes only after input is stable for DATA clock cycles */
} cy_en_ppca_epu_pu_processing_func_t;


/**
 * COMBO Block:
 * Combination of 2 Processing Unit T1 module outputs. {SIGNAL_A, SIGNAL_B}
 * Select input signals : put1_selected[i] = {put1[2*i],put1[2*i+1]}, i=[0,7]
 */
typedef enum
{
    CY_COMBO_UNASSIGNED_BANK_OUT   = 0U,  /**< PUT Out unassigned */
    CY_COMBO_PUT1_OUT0_PUT1_OUT1   = 0U,  /**< Select input signals PUT1_OUT0 and PUT1_OUT1   */
    CY_COMBO_PUT1_OUT2_PUT1_OUT3   = 1U,  /**< Select input signals PUT1_OUT2 and PUT1_OUT3   */
    CY_COMBO_PUT1_OUT4_PUT1_OUT5   = 2U,  /**< Select input signals PUT1_OUT4 and PUT1_OUT5   */
    CY_COMBO_PUT1_OUT6_PUT1_OUT7   = 3U,  /**< Select input signals PUT1_OUT6 and PUT1_OUT7   */
    CY_COMBO_PUT1_OUT8_PUT1_OUT9   = 4U,  /**< Select input signals PUT1_OUT8 and PUT1_OUT9   */
    CY_COMBO_PUT1_OUT10_PUT1_OUT11 = 5U,  /**< Select input signals PUT1_OUT10 and PUT1_OUT11 */
    CY_COMBO_PUT1_OUT12_PUT1_OUT13 = 6U,  /**< Select input signals PUT1_OUT12 and PUT1_OUT13 */
    CY_COMBO_PUT1_OUT14_PUT1_OUT15 = 7U,  /**< Select input signals PUT1_OUT14 and PUT1_OUT15 */
}cy_en_ppca_epu_bank_sel_t;


/**
 * COMBO Block: Enable input signals. {SIGNAL_A, SIGNAL_B}
 */
typedef enum
{
    CY_COMBO_DISABLE_INPUT_SIGNAL_A_AND_B = 0U, /**< Disable both SIGNAL_A and SIGNAL_B*/
    CY_COMBO_ENABLE_INPUT_SIGNAL_A        = 1U, /**< tbd - check with IP team; Enable SIGNAL_A */
    CY_COMBO_ENABLE_INPUT_SIGNAL_B        = 2U, /**< tbd - check with IP team; Enable SIGNAL_B */
    CY_COMBO_ENABLE_INPUT_SIGNAL_A_AND_B  = 3U, /**< Enable both SIGNAL_A and SIGNAL_B*/
}cy_en_ppca_epu_en_input_signal_t;


/**
 * COMBO Block:
 * Select 1 of 16 Processing Units T1 and 1 of 16 Processing Units T2. {SIGNAL_A, SIGNAL_B}
 * Select {pu_src_sel0, pu_src_sel1} = {put1[16+i],put2[i]}, i=[0,15]
 */
typedef enum
{
    CY_COMBO_UNASSIGNED_PUT_OUT     = 0U,  /**< PUT Out unassigned */
    CY_COMBO_PUT1_OUT16_PUT2_OUT0   = 0U,  /**< Select input signals PUT1_OUT16 and PUT2_OUT0   */
    CY_COMBO_PUT1_OUT17_PUT2_OUT1   = 1U,  /**< Select input signals PUT1_OUT17 and PUT2_OUT1   */
    CY_COMBO_PUT1_OUT18_PUT2_OUT2   = 2U,  /**< Select input signals PUT1_OUT18 and PUT2_OUT2   */
    CY_COMBO_PUT1_OUT19_PUT2_OUT3   = 3U,  /**< Select input signals PUT1_OUT19 and PUT2_OUT3   */
    CY_COMBO_PUT1_OUT20_PUT2_OUT4   = 4U,  /**< Select input signals PUT1_OUT20 and PUT2_OUT4   */
    CY_COMBO_PUT1_OUT21_PUT2_OUT5   = 5U,  /**< Select input signals PUT1_OUT21 and PUT2_OUT5   */
    CY_COMBO_PUT1_OUT22_PUT2_OUT6   = 6U,  /**< Select input signals PUT1_OUT22 and PUT2_OUT6   */
    CY_COMBO_PUT1_OUT23_PUT2_OUT7   = 7U,  /**< Select input signals PUT1_OUT23 and PUT2_OUT7   */
    CY_COMBO_PUT1_OUT24_PUT2_OUT8   = 8U,  /**< Select input signals PUT1_OUT24 and PUT2_OUT8   */
    CY_COMBO_PUT1_OUT25_PUT2_OUT9   = 9U,  /**< Select input signals PUT1_OUT25 and PUT2_OUT9   */
    CY_COMBO_PUT1_OUT26_PUT2_OUT10  = 10U, /**< Select input signals PUT1_OUT26 and PUT2_OUT10  */
    CY_COMBO_PUT1_OUT27_PUT2_OUT11  = 11U, /**< Select input signals PUT1_OUT27 and PUT2_OUT11  */
    CY_COMBO_PUT1_OUT28_PUT2_OUT12  = 12U, /**< Select input signals PUT1_OUT28 and PUT2_OUT12  */
    CY_COMBO_PUT1_OUT29_PUT2_OUT13  = 13U, /**< Select input signals PUT1_OUT29 and PUT2_OUT13  */
    CY_COMBO_PUT1_OUT30_PUT2_OUT14  = 14U, /**< Select input signals PUT1_OUT30 and PUT2_OUT14  */
    CY_COMBO_PUT1_OUT31_PUT2_OUT15  = 15U, /**< Select input signals PUT1_OUT31 and PUT2_OUT15  */
}cy_en_ppca_epu_pu_src_in_t;

/**
 * COMBO Block: Select PU (= PUT1_OUT31:PUT1_OUT28, PUT2_OUT15:PUT2_OUT12) as qualifier.
 */
typedef enum
{
    CY_COMBO_UNASSIGNED_QUAL = 0U,  /**< Qualifier unassigned */
    CY_COMBO_PUT1_OUT28_QUAL = 0U,  /**< PUT1_OUT28 as qualifier */
    CY_COMBO_PUT1_OUT29_QUAL = 1U,  /**< PUT1_OUT29 as qualifier */
    CY_COMBO_PUT1_OUT30_QUAL = 2U,  /**< PUT1_OUT30 as qualifier */
    CY_COMBO_PUT1_OUT31_QUAL = 3U,  /**< PUT1_OUT31 as qualifier */
    CY_COMBO_PUT2_OUT12_QUAL = 4U,  /**< PUT2_OUT12 as qualifier */
    CY_COMBO_PUT2_OUT13_QUAL = 5U,  /**< PUT2_OUT13 as qualifier */
    CY_COMBO_PUT2_OUT14_QUAL = 6U,  /**< PUT2_OUT14 as qualifier */
    CY_COMBO_PUT2_OUT15_QUAL = 7U,  /**< PUT2_OUT15 as qualifier */
}cy_en_ppca_epu_in_qual_t;


/** \} group_ppca_epu_enums */


/***************************************
*       Configuration Structures
***************************************/

/**
* \addtogroup group_ppca_epu_structures
* \{
*/

/** PPCA EPU PU Type 1 Configuration.
 *  Configures a PU_T1 module including its PRESTAGE (input selection,
 *  polarity, edge extraction) and MXSTAGE (processing function, duration). */
typedef struct cy_stc_ppca_epu_PU_T1_config
{
    cy_en_ppca_epu_en_pu_t PUT1_enable;             /**< Enable mode: disabled, sync/async bypass, or full processing */
    bool inpPolarityInv;                            /**< true: invert input polarity in PRESTAGE */
    cy_en_ppca_epu_input_pu_t PUT1_IN_Sel;          /**< Select level or edge-extracted input to MXSTAGE */
    cy_en_ppca_epu_pu_processing_func_t opcode;     /**< MXSTAGE processing function (edge extract, mask, blank, debounce) */
    uint8_t clk_cycles;                             /**< DATA parameter: duration in EPU clock cycles (0-127) */
    bool PUT1_ENQ;                                  /**< true: enable qualifier input to gate the PU output */
    uint8_t PUT1_SRC_SEL;                           /**< Input source index from the 256-entry event input table */
    uint8_t PUT1_SRCQ_SEL;                          /**< Qualifier input source index */
    bool swEventEnable;                             /**< true: use constant input level instead of hardware event */
    cy_en_ppca_epu_constant_level_t inputLevel;     /**< Constant input level (0 or 1) when swEventEnable is true */
}cy_stc_ppca_epu_PU_T1_config_t;


/** PPCA EPU PU Type 2 Configuration.
 *  Configures a PU_T2 module. PU_T2 provides PRESTAGE-only processing
 *  (bypass, polarity inversion, edge extraction) without MXSTAGE. */
typedef struct cy_stc_ppca_epu_PU_T2_config
{
    cy_en_ppca_epu_en_pu_t PUT2_enable;             /**< Enable mode: disabled, sync/async bypass, or processing */
    bool inpPolarityInv;                            /**< true: invert input polarity */
    cy_en_ppca_epu_input_pu_t PUT2_IN_Sel;          /**< Select level or edge-extracted input */
    uint8_t PUT2_SRC_SEL;                           /**< Input source index from the 256-entry event input table */
    bool swEventEnable;                             /**< true: use constant input level instead of hardware event */
    cy_en_ppca_epu_constant_level_t inputLevel;     /**< Constant input level (0 or 1) when swEventEnable is true */
}cy_stc_ppca_epu_PU_T2_config_t;


/** PPCA EPU COMBO Block Configuration.
 *  Configures one of the 123 COMBO blocks that performs a logical AND
 *  combination of selected PU outputs to produce an EPU trigger output
 *  (EVOUT). Each COMBO selects up to 4 PU signals plus an optional
 *  qualifier, then applies optional output polarity inversion. */
typedef struct cy_stc_ppca_epu_combo_config
{
    cy_en_ppca_epu_bank_sel_t bankSel;             /**< Select a pair of PU_T1 outputs from PUT1_OUT[0:15] */
    cy_en_ppca_epu_en_input_signal_t put1InEnable; /**< Enable SIGNAL_A and/or SIGNAL_B from the selected PUT1_OUT[0:15] pair */
    cy_en_ppca_epu_pu_src_in_t puSrcIn;            /**< Select a PU_T1 output from PUT1_OUT[16:31] and a PU_T2 output from PUT2_OUT[0:15] */
    cy_en_ppca_epu_en_input_signal_t srcInEnable;  /**< Enable SIGNAL_A and/or SIGNAL_B from the selected PUT1_OUT[16:31]/PUT2_OUT pair */
    cy_en_ppca_epu_in_qual_t inQual;               /**< Select qualifier source from PUT1_OUT[28:31] or PUT2_OUT[12:15] */
    bool enableQual;                               /**< true: enable qualifier gating on the COMBO output */
    bool enablePolInv;                             /**< true: invert the COMBO output polarity */
}cy_stc_ppca_epu_combo_config_t;

/** \} group_ppca_epu_structures */


/***************************************
*        Function Prototypes
***************************************/

/**
* \addtogroup group_ppca_epu_functions
* \{
*/

/*******************************************************************************
* Function Name: Cy_PPCA_EPU_Enable
****************************************************************************//**
*
* Enables the EPU block. Once enabled, the Processing Units and COMBO blocks
* begin processing input events and generating trigger outputs.
*
* \param *base
* The PPCA EPU registers structure pointer.
*
*******************************************************************************/
__STATIC_INLINE void Cy_PPCA_EPU_Enable(PPCA_EPU_Type *base)
{
    PPCA_EPU_CTRL(base) |= PPCA_EPU_CTRL_EPU_EN_Msk;
}


/*******************************************************************************
* Function Name: Cy_PPCA_EPU_Disable
****************************************************************************//**
*
* Disables the EPU block. All Processing Units and COMBO blocks stop processing
* and trigger outputs are deactivated.
*
* \param *base
* The PPCA EPU registers structure pointer.
*
*******************************************************************************/
__STATIC_INLINE void Cy_PPCA_EPU_Disable(PPCA_EPU_Type *base)
{
    PPCA_EPU_CTRL(base) &= (uint32_t) ~PPCA_EPU_CTRL_EPU_EN_Msk;
}


/*******************************************************************************
* Function Name: Cy_PPCA_EPU_EnableExclusiveAccess
****************************************************************************//**
*
* Enable exclusive access to the EPU resources based on the provided
* resources allocation configuration.
*
* \param *base
* The PPCA EPU registers structure pointer.
*
* \param enable
* true: CPU0 or CPU1 can access only its own resources,
*       as specified by the configuration registers (PPCA CNFG))
* false: all EPU resources can be accessed by both CPU0 & CPU1,
*        i.e. the configuration registers are ignored.
*
*******************************************************************************/
__STATIC_INLINE void Cy_PPCA_EPU_EnableExclusiveAccess(PPCA_EPU_Type *base, bool enable)
{
    if(enable)
    {
        PPCA_EPU_CTRL(base) |= PPCA_EPU_CTRL_EN_EXCLUSIVE_ACCESS_Msk;
    }
    else
    {
        PPCA_EPU_CTRL(base) &= (uint32_t) ~(PPCA_EPU_CTRL_EN_EXCLUSIVE_ACCESS_Msk);
    }
}


/*******************************************************************************
* Function Name: Cy_PPCA_EPU_PU_T1_Configure
****************************************************************************//**
*
* Configures a Processing Unit Type 1 module including PRESTAGE (input source,
* polarity inversion, edge extraction, qualifier) and MXSTAGE (processing
* function, clock cycle duration). This writes the full PU_T1 configuration
* in a single operation. The PU is kept disabled after configuration.
* Use \ref Cy_PPCA_EPU_PU_T1_Enable to enable the PU after configuration.
*
* \param *base
* The PPCA EPU registers structure pointer.
*
* \param index
* The Processing Unit Type 1 index (PUT1). Range: 0-31.
*
* \param config
* The pointer to the PU_T1 configuration structure \ref cy_stc_ppca_epu_PU_T1_config_t.
*
* \snippet ppca/snippet/ppca_snippet.c SNIPPET_PPCA_EPU_PU_T1_CONFIGURE
*
*******************************************************************************/
void Cy_PPCA_EPU_PU_T1_Configure( PPCA_EPU_EPU_Type *base, uint32_t index, cy_stc_ppca_epu_PU_T1_config_t const *config);


/*******************************************************************************
* Function Name: Cy_PPCA_EPU_PU_T2_Configure
****************************************************************************//**
*
* Configures a Processing Unit Type 2 module. PU_T2 modules provide
* PRESTAGE-only processing (input source, polarity inversion, edge
* extraction) without MXSTAGE signal conditioning. The PU is kept disabled
* after configuration. Use \ref Cy_PPCA_EPU_PU_T2_Enable to enable the PU
* after configuration.
*
* \param *base
* The PPCA EPU registers structure pointer.
*
* \param index
* The Processing Unit Type 2 index (PUT2). Range: 0-15.
*
* \param config
* The pointer to the PU_T2 configuration structure \ref cy_stc_ppca_epu_PU_T2_config_t.
*
*******************************************************************************/
void Cy_PPCA_EPU_PU_T2_Configure( PPCA_EPU_EPU_Type *base, uint32_t index, cy_stc_ppca_epu_PU_T2_config_t const *config);


/*******************************************************************************
* Function Name: Cy_PPCA_EPU_Combo_Configure
****************************************************************************//**
*
* Configures a COMBO block that performs logical AND combination of selected
* PU outputs to produce one of the 123 EPU trigger outputs (EVOUT).
*
* \param *base
* The PPCA EPU registers structure pointer.
*
* \param index
* The COMBO block index. Range: 0-122.
*
* \param config
* The pointer to the COMBO configuration structure \ref cy_stc_ppca_epu_combo_config_t.
*
*******************************************************************************/
void Cy_PPCA_EPU_Combo_Configure( PPCA_EPU_EPU_Type *base, uint32_t index, cy_stc_ppca_epu_combo_config_t const  *config);


/*******************************************************************************
* Function Name: Cy_PPCA_EPU_Combo_Feedback_Configure
****************************************************************************//**
*
* Configures a COMBO Feedback path. Up to 8 COMBO outputs can be fed back
* into the EPU input space, enabling cascaded trigger logic where the output
* of one COMBO block serves as an input event for subsequent processing.
*
* \param *base
* The PPCA EPU registers structure pointer.
*
* \param index
* The COMBO Feedback block index. Range: 0-7.
*
* \param comboFBSrcIn
* The COMBO output index to feed back. Range: 0-122.
*
*******************************************************************************/
__STATIC_INLINE void Cy_PPCA_EPU_Combo_Feedback_Configure( PPCA_EPU_EPU_Type *base, uint32_t index, uint32_t comboFBSrcIn)
{
    CY_ASSERT_L1(CY_IS_PARAM_VALID(base));
    CY_ASSERT_L2(CY_IS_COMBO_FB_INDEX_VALID(index));

    PPCA_EPU_EPU_COMBO_FB_CNFG(base, index) = comboFBSrcIn;
}

//PUT1

/*******************************************************************************
* Function Name: Cy_PPCA_EPU_PU_T1_Enable
****************************************************************************//**
*
* Enable/Disable and Bypass Configure the Processing Unit.
*
* \param *base
* The PPCA EPU registers structure pointer.
*
* \param index
* The Processing Unit Type 1 index (PUT1) . Range: 0-31.
*
* \param enable
* Enable/Disable or Bypass the PU. See \ref cy_en_ppca_epu_en_pu_t .
*
*******************************************************************************/
void Cy_PPCA_EPU_PU_T1_Enable(PPCA_EPU_EPU_Type *base, uint32_t index, cy_en_ppca_epu_en_pu_t enable);


/*******************************************************************************
* Function Name: Cy_PPCA_EPU_PU_T1_Enable_PolInv
****************************************************************************//**
*
* Enable/Disable Input Polarity Inversion.
*
* \param *base
* The PPCA EPU registers structure pointer.
*
* \param index
* The Processing Unit Type 1 index (PUT1) . Range: 0-31
*
* \param enable
* true: enable
* false: disable.
*
*******************************************************************************/
__STATIC_INLINE void Cy_PPCA_EPU_PU_T1_Enable_PolInv(PPCA_EPU_EPU_Type *base, uint32_t index, bool enable)
{
    if(enable)
    {
        PPCA_EPU_EPU_PU_T1_CNFG(base, index) |= PPCA_EPU_EPU_PU_T1_CNFG_PUT1_POL_Msk;
    }
    else
    {
        PPCA_EPU_EPU_PU_T1_CNFG(base, index) &= (uint32_t) ~(PPCA_EPU_EPU_PU_T1_CNFG_PUT1_POL_Msk);
    }
}

/*******************************************************************************
* Function Name: Cy_PPCA_EPU_PU_T1_Enable_SWEventGeneration
****************************************************************************//**
*
* Enable/Disable Software Event Generation.
*
* \param *base
* The PPCA EPU registers structure pointer.
*
* \param index
* The Processing Unit Type 1 index (PUT1) . Range: 0-31
*
* \param enable
* true: enable
* false: disable.
*
*******************************************************************************/
__STATIC_INLINE void Cy_PPCA_EPU_PU_T1_Enable_SWEventGeneration(PPCA_EPU_EPU_Type *base, uint32_t index, bool enable)
{
    if(enable)
    {
        PPCA_EPU_EPU_PU_T1_CNFG(base, index) |= PPCA_EPU_EPU_PU_T1_CNFG_PUT1_SEL_CONSTANT_IN_Msk;
    }
    else
    {
        PPCA_EPU_EPU_PU_T1_CNFG(base, index) &= (uint32_t) ~(PPCA_EPU_EPU_PU_T1_CNFG_PUT1_SEL_CONSTANT_IN_Msk);
    }
}

/*******************************************************************************
* Function Name: Cy_PPCA_EPU_PU_T1_Generate_SW_Event
****************************************************************************//**
*
* Generates a SW event.
*
* \param *base
* The PPCA EPU registers structure pointer.
*
* \note For this to generate a SW event Cy_PPCA_EPU_PU_T1_Enable_SWEventGeneration this needs to be set
*
* \param index
* The Processing Unit Type 1 index (PUT1) . Range: 0-31
*
* \param enable
* true: generates a SW event.
* false: should be set to false after event generation is complete.
*
* \note User should call this API to Generate a Software Event.
* \note User should also call this API to set this to 0 after event is generated.
*
*******************************************************************************/
__STATIC_INLINE void Cy_PPCA_EPU_PU_T1_Generate_SW_Event(PPCA_EPU_EPU_Type *base, uint32_t index, bool enable)
{
    if(enable)
    {
        PPCA_EPU_EPU_PU_T1_CNFG(base, index) |= PPCA_EPU_EPU_PU_T1_CNFG_PUT1_CONSTANT_IN_Msk;
    }
    else
    {
        PPCA_EPU_EPU_PU_T1_CNFG(base, index) &= (uint32_t) ~(PPCA_EPU_EPU_PU_T1_CNFG_PUT1_CONSTANT_IN_Msk);
    }
}

/*******************************************************************************
* Function Name: Cy_PPCA_EPU_PU_T1_Select_Input
****************************************************************************//**
*
* Selects whether the PU_T1 MXSTAGE receives the level signal or the
* rising-edge-extracted signal from the PRESTAGE.
*
* \param *base
* The PPCA EPU registers structure pointer.
*
* \param index
* The Processing Unit Type 1 index (PUT1). Range: 0-31.
*
* \param input
* Input of PUT1. See \ref cy_en_ppca_epu_input_pu_t.
*
*******************************************************************************/
void Cy_PPCA_EPU_PU_T1_Select_Input(PPCA_EPU_EPU_Type *base, uint32_t index, cy_en_ppca_epu_input_pu_t input);


/*******************************************************************************
* Function Name: Cy_PPCA_EPU_PU_T1_Select_ProcessingFunc
****************************************************************************//**
*
* Selects the MXSTAGE processing function for a PU_T1 module and configures
* the associated clock cycle duration parameter.
*
* \param *base
* The PPCA EPU registers structure pointer.
*
* \param index
* The Processing Unit Type 1 index (PUT1). Range: 0-31.
*
* \param func
* PU processing function. See \ref cy_en_ppca_epu_pu_processing_func_t.
*
* \param clk_cycles
* Duration in EPU clock cycles. Range: 0-127.
*
*******************************************************************************/
void Cy_PPCA_EPU_PU_T1_Select_ProcessingFunc(PPCA_EPU_EPU_Type *base, uint32_t index, cy_en_ppca_epu_pu_processing_func_t func, uint32_t clk_cycles);


/*******************************************************************************
* Function Name: Cy_PPCA_EPU_PU_T1_Config_QualifierInput
****************************************************************************//**
*
* Configures the qualifier input for a PU_T1 module. When the qualifier is
* enabled, the PU output is gated (ANDed) with the qualifier signal, allowing
* conditional event processing.
*
* \param *base
* The PPCA EPU registers structure pointer.
*
* \param index
* The Processing Unit Type 1 index (PUT1). Range: 0-31.
*
* \param enable
* true: enable qualifier gating. false: disable qualifier.
*
* \param qualInSrc
* The qualifier input source index.
*
*******************************************************************************/
void Cy_PPCA_EPU_PU_T1_Config_QualifierInput(PPCA_EPU_EPU_Type *base, uint32_t index, bool enable, uint8_t qualInSrc);


/*******************************************************************************
* Function Name: Cy_PPCA_EPU_PU_T1_Config_InputSource
****************************************************************************//**
*
* Selects the event input source for a PU_T1 module from the 256-entry
* EPU event input table.
*
* \param *base
* The PPCA EPU registers structure pointer.
*
* \param index
* The Processing Unit Type 1 index (PUT1). Range: 0-31.
*
* \param inSrc
* Input source index from the EPU event input table.
*
*******************************************************************************/
void Cy_PPCA_EPU_PU_T1_Config_InputSource(PPCA_EPU_EPU_Type *base, uint32_t index, uint8_t inSrc);


/*******************************************************************************
* Function Name: Cy_PPCA_EPU_PU_T1_Config_NumOfClkCycles
****************************************************************************//**
*
* Configures the DATA (duration) parameter for the MXSTAGE processing function
* of a PU_T1 module. The meaning depends on the selected processing function:
* pulse delay, mask duration, blank duration, or debounce threshold.
*
* \param *base
* The PPCA EPU registers structure pointer.
*
* \param index
* The Processing Unit Type 1 index (PUT1). Range: 0-31.
*
* \param data
* Number of EPU clock cycles (0-127).
*
*******************************************************************************/
void Cy_PPCA_EPU_PU_T1_Config_NumOfClkCycles(PPCA_EPU_EPU_Type *base, uint32_t index, uint8_t data);


/*******************************************************************************
* Function Name: Cy_PPCA_EPU_PU_T1_TestInConfig
****************************************************************************//**
*
* Select Test Input Signal to Processing Uint Type 1.
*
* \param *base
* The PPCA EPU registers structure pointer.
*
* \param index
* The Processing Unit Type 1 index PUT1) . Range: 0-31.
*
* \param enableTestIn
* Enable TEST_IN input to the PU unit.
*
* \param testInVal
* Set the value of the TEST_IN input signal.
* * 0 = TEST_IN set to 0
* * 1 = TEST_IN set to 1
*
*******************************************************************************/
void Cy_PPCA_EPU_PU_T1_TestInConfig(PPCA_EPU_EPU_Type *base, uint32_t index, bool enableTestIn, bool testInVal);


//PUT2

/*******************************************************************************
* Function Name: Cy_PPCA_EPU_PU_T2_Enable
****************************************************************************//**
*
* Enable/Disable and Bypass Configure the Processing Unit.
*
* \param *base
* The PPCA EPU registers structure pointer.
*
* \param index
* The Processing Unit Type 2 index (PUT2) . Range: 0-15.
*
* \param enable
* Enable/Disable or Bypass the PU. See \ref cy_en_ppca_epu_en_pu_t .
*
*******************************************************************************/
void Cy_PPCA_EPU_PU_T2_Enable(PPCA_EPU_EPU_Type *base, uint32_t index, cy_en_ppca_epu_en_pu_t enable);


/*******************************************************************************
* Function Name: Cy_PPCA_EPU_PU_T2_Enable_PolInv
****************************************************************************//**
*
* Enable/Disable Input Polarity Inversion.
*
* \param *base
* The PPCA EPU registers structure pointer.
*
* \param index
* The Processing Unit Type 2 index (PUT2) . Range: 0-15.
*
* \param enable
* true: enable
* false: disable.
*
*******************************************************************************/
__STATIC_INLINE void Cy_PPCA_EPU_PU_T2_Enable_PolInv(PPCA_EPU_EPU_Type *base, uint32_t index, bool enable)
{
    if(enable)
    {
        PPCA_EPU_EPU_PU_T2_CNFG(base, index) |= PPCA_EPU_EPU_PU_T2_CNFG_PUT2_POL_Msk;
    }
    else
    {
        PPCA_EPU_EPU_PU_T2_CNFG(base, index) &= (uint32_t) ~(PPCA_EPU_EPU_PU_T2_CNFG_PUT2_POL_Msk);
    }
}


/*******************************************************************************
* Function Name: Cy_PPCA_EPU_PU_T2_Enable_SWEventGeneration
****************************************************************************//**
*
* Enable/Disable Software Event Generation.
*
* \param *base
* The PPCA EPU registers structure pointer.
*
* \param index
* The Processing Unit Type 2 index (PUT2) . Range: 0-15
*
* \param enable
* true: enable
* false: disable.
*
*******************************************************************************/
__STATIC_INLINE void Cy_PPCA_EPU_PU_T2_Enable_SWEventGeneration(PPCA_EPU_EPU_Type *base, uint32_t index, bool enable)
{
    if(enable)
    {
        PPCA_EPU_EPU_PU_T2_CNFG(base, index) |= PPCA_EPU_EPU_PU_T2_CNFG_PUT2_SEL_CONSTANT_IN_Msk;
    }
    else
    {
        PPCA_EPU_EPU_PU_T2_CNFG(base, index) &= (uint32_t) ~(PPCA_EPU_EPU_PU_T2_CNFG_PUT2_SEL_CONSTANT_IN_Msk);
    }
}

/*******************************************************************************
* Function Name: Cy_PPCA_EPU_PU_T2_Generate_SW_Event
****************************************************************************//**
*
* Generates a SW event.
*
* \param *base
* The PPCA EPU registers structure pointer.
*
* \note For this to generate a SW event Cy_PPCA_EPU_PU_T2_Enable_SWEventGeneration this needs to be set
*
* \param index
* The Processing Unit Type 2 index (PUT2) . Range: 0-15
*
* \param enable
* true: generates a SW event.
* false: should be set to false after event generation is complete.
*
* \note User should call this API to Generate a Software Event.
* \note User should also call this API to set this to 0 after event is generated.
*
*******************************************************************************/
__STATIC_INLINE void Cy_PPCA_EPU_PU_T2_Generate_SW_Event(PPCA_EPU_EPU_Type *base, uint32_t index, bool enable)
{
    if(enable)
    {
        PPCA_EPU_EPU_PU_T2_CNFG(base, index) |= PPCA_EPU_EPU_PU_T2_CNFG_PUT2_CONSTANT_IN_Msk;
    }
    else
    {
        PPCA_EPU_EPU_PU_T2_CNFG(base, index) &= (uint32_t) ~(PPCA_EPU_EPU_PU_T2_CNFG_PUT2_CONSTANT_IN_Msk);
    }
}


/*******************************************************************************
* Function Name: Cy_PPCA_EPU_PU_T2_Select_Input
****************************************************************************//**
*
* Selects whether the PU_T2 output receives the level signal or the
* rising-edge-extracted signal from the PRESTAGE.
*
* \param *base
* The PPCA EPU registers structure pointer.
*
* \param index
* The Processing Unit Type 2 index (PUT2). Range: 0-15.
*
* \param input
* Input of PUT2. See \ref cy_en_ppca_epu_input_pu_t.
*
*******************************************************************************/
void Cy_PPCA_EPU_PU_T2_Select_Input(PPCA_EPU_EPU_Type *base, uint32_t index, cy_en_ppca_epu_input_pu_t input);


/*******************************************************************************
* Function Name: Cy_PPCA_EPU_PU_T2_Config_InputSource
****************************************************************************//**
*
* Selects the event input source for a PU_T2 module from the 256-entry
* EPU event input table.
*
* \param *base
* The PPCA EPU registers structure pointer.
*
* \param index
* The Processing Unit Type 2 index (PUT2). Range: 0-15.
*
* \param inSrc
* Input source index from the EPU event input table.
*
*******************************************************************************/
void Cy_PPCA_EPU_PU_T2_Config_InputSource(PPCA_EPU_EPU_Type *base, uint32_t index, uint8_t inSrc);

/*******************************************************************************
* Function Name: Cy_PPCA_EPU_PU_T2_TestInConfig
****************************************************************************//**
*
* Select Test Input Signal to Processing Uint Type 2.
*
* \param *base
* The PPCA EPU registers structure pointer.
*
* \param index
* The Processing Unit Type 2 index PUT2) . Range: 0-15.
*
* \param enableTestIn
* Enable TEST_IN input to the PU unit.
*
* \param testInVal
* Set the value of the TEST_IN input signal.
* * 0 = TEST_IN set to 0
* * 1 = TEST_IN set to 1
*
*******************************************************************************/
void Cy_PPCA_EPU_PU_T2_TestInConfig(PPCA_EPU_EPU_Type *base, uint32_t index, bool enableTestIn, bool testInVal);


//COMBINER APIs

/*******************************************************************************
* Function Name: Cy_PPCA_EPU_COMBO_InputSignals_PUT1_0_15
****************************************************************************//**
*
* Selects a pair of PU_T1 outputs from PUT1_OUT[0:15] as COMBO input signals
* and enables one or both signals of the pair.
*
* \param *base
* The PPCA EPU registers structure pointer.
*
* \param index
* The COMBO block index. Range: 0-122.
*
* \param bankSel
* Selects which pair from PUT1_OUT[0:15]. See \ref cy_en_ppca_epu_bank_sel_t.
*
* \param put1InEnable
* Enables SIGNAL_A and/or SIGNAL_B of the selected pair.
* See \ref cy_en_ppca_epu_en_input_signal_t.
*
*******************************************************************************/
void Cy_PPCA_EPU_COMBO_InputSignals_PUT1_0_15(PPCA_EPU_EPU_Type *base, uint32_t index, cy_en_ppca_epu_bank_sel_t bankSel, cy_en_ppca_epu_en_input_signal_t put1InEnable);


/*******************************************************************************
* Function Name: Cy_PPCA_EPU_COMBO_InputSignals_PUT1_PUT2
****************************************************************************//**
*
* Selects one PU_T1 output from PUT1_OUT[16:31] and one PU_T2 output from
* PUT2_OUT[0:15] as COMBO input signals, and enables one or both signals.
*
* \param *base
* The PPCA EPU registers structure pointer.
*
* \param index
* The COMBO block index. Range: 0-122.
*
* \param puSrcIn
* Selects the PUT1_OUT[16:31] / PUT2_OUT[0:15] pair.
* See \ref cy_en_ppca_epu_pu_src_in_t.
*
* \param srcInEnable
* Enables SIGNAL_A and/or SIGNAL_B of the selected pair.
* See \ref cy_en_ppca_epu_en_input_signal_t.
*
*******************************************************************************/
void Cy_PPCA_EPU_COMBO_InputSignals_PUT1_PUT2(PPCA_EPU_EPU_Type *base, uint32_t index, cy_en_ppca_epu_pu_src_in_t puSrcIn, cy_en_ppca_epu_en_input_signal_t srcInEnable);


/*******************************************************************************
* Function Name: Cy_PPCA_EPU_COMBO_QualifierInput
****************************************************************************//**
*
* Enable/Disable Qualifier and select the input qualifier signal.
*
* \param *base
* The PPCA EPU registers structure pointer.
*
* \param index
* The COMBO block index. Range: 0-122.
*
* \param enableQual
* Enable/Disable Qualifier.
*
* \param inQual
* Select PU (= PUT1_OUT31:PUT1_OUT27, PUT2_OUT15:PUT2_OUT12) as qualifier.
*
*******************************************************************************/
void Cy_PPCA_EPU_COMBO_QualifierInput(PPCA_EPU_EPU_Type *base, uint32_t index, bool enableQual, cy_en_ppca_epu_in_qual_t inQual);


/*******************************************************************************
* Function Name: Cy_PPCA_EPU_COMBO_Enable_PolInv
****************************************************************************//**
*
* Enable/Disable COMBO Polarity Inversion.
*
* \param *base
* The PPCA EPU registers structure pointer.
*
* \param index
* The COMBO block index. Range: 0-122.
*
* \param enable
* true: enable
* false: disable.
*
*******************************************************************************/
__STATIC_INLINE void Cy_PPCA_EPU_COMBO_Enable_PolInv(PPCA_EPU_EPU_Type *base, uint32_t index, bool enable)
{
    if(enable)
    {
        PPCA_EPU_EPU_COMBO_CNFG(base, index) |= PPCA_EPU_EPU_COMBO_CNFG_COMBO_POL_Msk;
    }
    else
    {
        PPCA_EPU_EPU_COMBO_CNFG(base, index) &= (uint32_t) ~(PPCA_EPU_EPU_COMBO_CNFG_COMBO_POL_Msk);
    }
}



//Interrupt Functions

/*******************************************************************************
* Function Name: Cy_PPCA_EPU_InterruptSourceSelect
****************************************************************************//**
*
* Configures the EPU IRQ Generator. Selects one of the 123 COMBO outputs
* (EVOUT) as the interrupt source and optionally bypasses the IRQ formatter
* logic for the internal PPSS CPUs.
*
* \param base
* The pointer to the PPCA_EPU_EPU_IRQ instance.
*
* \param bypassFormatter
* true: bypass the EPU IRQ formatter (direct COMBO output to interrupt).
* false: use the IRQ formatter with the selected source.
*
* \param srcSel
* COMBO output index to use as the interrupt source (0-122).
*
*******************************************************************************/
__STATIC_INLINE void Cy_PPCA_EPU_InterruptSourceSelect(PPCA_EPU_EPU_IRQ_Type *base, bool bypassFormatter, uint8_t srcSel)
{
    if(bypassFormatter)
    {
        PPCA_EPU_EPU_IRQ_INTR_SRCSEL(base) = _BOOL2FLD(PPCA_EPU_EPU_IRQ_INTR_SRCSEL_BYPASS_EPU_IRQ, bypassFormatter);
    }
    else
    {
        PPCA_EPU_EPU_IRQ_INTR_SRCSEL(base) = _BOOL2FLD(PPCA_EPU_EPU_IRQ_INTR_SRCSEL_BYPASS_EPU_IRQ, bypassFormatter) |
                                                  _VAL2FLD(PPCA_EPU_EPU_IRQ_INTR_SRCSEL_EPU_IRQ_SRCSEL, (uint32_t)srcSel);
    }
}

/*******************************************************************************
* Function Name: Cy_PPCA_EPU_GetInterruptStatus
****************************************************************************//**
*
* Returns the interrupt status.
*
* \param base
* The pointer to the PPCA_EPU_EPU_IRQ instance.
*
* \return
* The current status of the interrupt source.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_PPCA_EPU_GetInterruptStatus(PPCA_EPU_EPU_IRQ_Type *base)
{
    return (PPCA_EPU_EPU_IRQ_INTR(base));
}


/*******************************************************************************
* Function Name: Cy_PPCA_EPU_ClearInterrupt
****************************************************************************//**
*
* Clears the interrupt sources in the interrupt cause register.
*
* \param base
* The pointer to the PPCA_EPU_EPU_IRQ instance.
*
*******************************************************************************/
__STATIC_INLINE void Cy_PPCA_EPU_ClearInterrupt(PPCA_EPU_EPU_IRQ_Type *base)
{
        PPCA_EPU_EPU_IRQ_INTR(base) = 1u;
}


/*******************************************************************************
* Function Name: Cy_PPCA_EPU_SetInterrupt
****************************************************************************//**
*
* Sets the interrupt sources in the interrupt set register.
*
* \param base
* The pointer to the PPCA_EPU_EPU_IRQ instance.
*
*******************************************************************************/
__STATIC_INLINE void Cy_PPCA_EPU_SetInterrupt(PPCA_EPU_EPU_IRQ_Type *base)
{
    PPCA_EPU_EPU_IRQ_INTR_SET(base) = 1u;
}

/*******************************************************************************
* Function Name: Cy_PPCA_EPU_GetInterruptMask
****************************************************************************//**
*
* Returns the interrupt mask register.
*
* \param base
* The pointer to the PPCA_EPU_EPU_IRQ instance.
*
* \return
* Enabled interrupt sources.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_PPCA_EPU_GetInterruptMask(PPCA_EPU_EPU_IRQ_Type *base)
{
    return (PPCA_EPU_EPU_IRQ_INTR_MASK(base));
}


/*******************************************************************************
* Function Name: Cy_PPCA_EPU_SetInterruptMask
****************************************************************************//**
*
* Writes interrupt mask register.
*
* \param base
* The pointer to the PPCA_EPU_EPU_IRQ instance.
*
*******************************************************************************/
__STATIC_INLINE void Cy_PPCA_EPU_SetInterruptMask(PPCA_EPU_EPU_IRQ_Type *base)
{
    PPCA_EPU_EPU_IRQ_INTR_MASK(base) = 1u;
}


/*******************************************************************************
* Function Name: Cy_PPCA_EPU_GetInterruptStatusMasked
****************************************************************************//**
*
* Returns the interrupt masked register. This register contains a
* logical AND of corresponding bits from the interrupt cause and mask
* registers.
* This function is intended to be used in the interrupt service routine to
* identify which of enabled interrupt sources caused the interrupt
* event.
*
* \param base
* The pointer to the PPCA_EPU_EPU_IRQ instance.
*
* \return
* The current status of enabled interrupt sources.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_PPCA_EPU_GetInterruptStatusMasked(PPCA_EPU_EPU_IRQ_Type *base)
{
    return (PPCA_EPU_EPU_IRQ_INTR_MASKED(base));
}


/** \} group_ppca_epu_functions */

#if defined(__cplusplus)
}
#endif

#endif /* #if defined(CY_IP_MXS40PPSS) */

#endif /* (CY_PPCA_EPU_H) */

/** \} group_ppca_epu */

/* [] END OF FILE */
