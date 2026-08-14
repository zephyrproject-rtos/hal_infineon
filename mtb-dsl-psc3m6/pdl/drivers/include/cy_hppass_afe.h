/***************************************************************************//**
* \file cy_hppass_afe.h
* \version 1.0.0
*
* Header file for the Autonomous Controller (AC) subsystem of
* the High Performance Programmable Analog Sub-System (HPPASS).
*
********************************************************************************
* \copyright
* (c) 2024-2026, Infineon Technologies AG, or an affiliate of Infineon
* Technologies AG.
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
* \addtogroup group_hppass_afe
* \{
* The AFE driver provides an API to configure and control the Analog Front End
* (AFE) subsystem within the High Performance Programmable Analog Sub-System (HPPASS).
*
* The HPPASS AFE subsystem provides four independent programmable gain amplifier
* (PGA) instances that can be configured as unity gain buffers (UGB) or as
* programmable gain amplifiers with selectable gain settings. Each AFE instance
* supports multiple input configurations and can operate in various modes including
* single-ended and differential operation.
*
* \section section_hppass_afe_features Features
* * Four independent AFE instances (0-3)
* * Programmable gain settings: 1x, 2x, 4x, 8x, 16x, 32x
* * Multiple input source options:
*   - Four external pins (PIN 0-3)
*   - Internal DAC output
*   - Analog reference (AREF)
*   - Ground (GND)
* * Five output modes:
*   - External single-ended input/output with Unity Gain Buffer (UGB)
*   - Internal single-ended input/output with UGB
*   - Internal differential input/output with Programmable Gain Amplifier (PGA)
*   - Internal single-ended input/output with PGA
*   - Internal differential input/single-ended output with PGA
* * Four configuration structures per AFE instance:
*   - Each config defines gain, input sources, and output mode
*   - Dynamic switching between configurations via control register
*   - Trigger-based configuration selection (Config 0/1 or Config 2/3)
* * Hardware trigger support for configuration switching (TR0-TR15)
* * Integrated charge pump enable/disable control
* * Independent OPAMP enable/disable control
*
* \section section_hppass_afe_configuration Configuration Considerations
*
* The AFE is configured using the \ref cy_stc_hppass_afe_t structure which contains
* an array of four \ref cy_stc_hppass_afe_config_t configuration structures, along
* with configuration control and trigger selection parameters.
*
* \subsection subsection_afe_gain_modes Gain Configuration
* Each AFE supports six programmable gain settings:
* * **1x Gain**: Unity gain, no amplification
* * **2x Gain**: 2x amplification
* * **4x Gain**: 4x amplification
* * **8x Gain**: 8x amplification
* * **16x Gain**: 16x amplification
* * **32x Gain**: 32x amplification
*
* The gain is configured independently for each of the four configuration structures,
* allowing rapid switching between different gain settings during operation.
*
* \subsection subsection_afe_output_modes Output Modes
* Five distinct output modes support different signal path configurations:
*
* * **External SE In/Out UGB (0)**: External single-ended input and output with unity gain buffer
*   - External pins used for both input and output
*   - Unity gain buffer mode
*   - Suitable for buffering external signals
*
* * **Internal SE In/Out UGB (1)**: Internal single-ended input and output with unity gain buffer
*   - Internal signal routing
*   - Unity gain buffer mode
*   - Output available to internal HPPASS blocks
*
* * **Internal Diff In/Out PGA (2)**: Internal differential input and differential output with PGA
*   - Fully differential signal path
*   - Programmable gain amplifier
*   - Both inputs and outputs differential
*
* * **Internal SE In/Out PGA (3)**: Internal single-ended input and output with PGA
*   - Single-ended signal path
*   - Programmable gain amplifier
*   - Single-ended input and output
*
* * **Internal Diff In/SE Out PGA (4)**: Internal differential input and single-ended output with PGA
*   - Differential to single-ended conversion
*   - Programmable gain amplifier
*   - Differential input, single-ended output
*
* \subsection subsection_afe_input_sources Input Source Selection
* Seven input source options available for positive and negative inputs:
* * **PIN 0-3**: Four external analog input pins
* * **DAC**: Internal DAC buffer output
* * **AREF**: Analog reference voltage
* * **GND**: Ground reference
*
* Positive and negative inputs can be independently configured, enabling:
* * Single-ended operation: Positive input from source, negative to GND
* * Differential operation: Both positive and negative from different sources
* * Reference measurements: Input vs AREF comparison
*
* \subsection subsection_afe_config_structures Multiple Configuration Structures
* Each AFE instance supports four independent configuration structures (Config 0-3).
* Each structure defines:
* * Gain setting (1x to 32x)
* * Positive input source selection
* * Negative input source selection
* * Output mode selection
*
* The active configuration is selected via the configuration control register, enabling
* rapid switching between different AFE operating modes without reconfiguration overhead.
*
* \subsection subsection_afe_config_control Configuration Control
* Six configuration control modes determine which config structure is active:
*
* * **SELECT0_STRUCT_0 (0)**: Always use Config 0
* * **SELECT1_STRUCT_1 (1)**: Always use Config 1
* * **SELECT2_STRUCT_2 (2)**: Always use Config 2
* * **SELECT3_STRUCT_3 (3)**: Always use Config 3
* * **SELECT01_TRIG_01 (4)**: Trigger-based selection between Config 0 and Config 1
*   - Use trigger select register to switch between configurations
*   - Enables dynamic switching based on external events
* * **SELECT23_TRIG_23 (5)**: Trigger-based selection between Config 2 and Config 3
*   - Use trigger select register to switch between configurations
*   - Enables dynamic switching based on external events
*
* \subsection subsection_afe_triggers Trigger Configuration
* When configuration control is set to trigger-based mode (TRIG_01 or TRIG_23),
* the trigger select register determines the trigger source:
* * Trigger 0: Trigger input disabled
* * Triggers 1-16: Hardware triggers TR0-TR15 from MCPASS infrastructure
*
* Triggers enable event-driven configuration switching for applications requiring
* rapid changes in gain, input source, or output mode based on external conditions.
*
* \subsection subsection_afe_charge_pump Charge Pump Control
* The integrated charge pump provides voltage boosting for the OPAMP:
* * Independent enable/disable control
* * Can be controlled separately from OPAMP enable
* * Required for proper OPAMP operation in most configurations
*
* The charge pump should typically be enabled when the AFE is in use and disabled
* when the AFE is not needed to minimize power consumption.
*
* \subsection subsection_afe_power_control Power Management
* Each AFE instance provides two levels of power control:
* * **OPAMP Enable/Disable**: Controls the operational amplifier
*   - Enable for active signal processing
*   - Disable to save power when AFE not in use
* * **Charge Pump Enable/Disable**: Controls voltage boosting circuit
*   - Enable for OPAMP operation
*   - Disable for additional power savings
*
* For lowest power consumption, disable both OPAMP and charge pump. For fastest
* wake-up, keep charge pump enabled and only control OPAMP enable.
*
* \section section_hppass_afe_usage Usage Examples
*
* \subsection subsection_afe_basic_init Basic Initialization
* \code
* // Configure AFE for single-ended PGA with 4x gain
* cy_stc_hppass_afe_config_t config0 =
* {
*     .afe_gain = CY_HPPASS_AFE_GAIN_4,
*     .pIn = CY_HPPASS_AFE_INPUT_SRC_PIN_0,
*     .nIn = CY_HPPASS_AFE_INPUT_SRC_GND,
*     .output_mode = CY_HPPASS_AFE_INT_SEIN_SEOUT_PGA
* };
*
* // Configure AFE with single config structure
* cy_stc_hppass_afe_t afeConfig =
* {
*     .afe_gain_config = {config0, config0, config0, config0},
*     .config_ctl = CY_HPPASS_AFE_SELECT0_STRUCT_0,
*     .trigger_select = 0  // Trigger disabled
* };
*
* // Initialize AFE instance 0
* Cy_HPPASS_AFE_Init(0, &afeConfig);
*
* // Enable AFE
* Cy_HPPASS_AFE_Enable(0);
* \endcode
*
* \subsection subsection_afe_differential Differential Configuration
* \code
* // Configure AFE for differential input, single-ended output
* cy_stc_hppass_afe_config_t diffConfig =
* {
*     .afe_gain = CY_HPPASS_AFE_GAIN_16,
*     .pIn = CY_HPPASS_AFE_INPUT_SRC_PIN_0,
*     .nIn = CY_HPPASS_AFE_INPUT_SRC_PIN_1,
*     .output_mode = CY_HPPASS_AFE_INT_DIFIN_SEOUT_PGA
* };
*
* cy_stc_hppass_afe_t afeConfig =
* {
*     .afe_gain_config = {diffConfig, diffConfig, diffConfig, diffConfig},
*     .config_ctl = CY_HPPASS_AFE_SELECT0_STRUCT_0,
*     .trigger_select = 0
* };
*
* Cy_HPPASS_AFE_Init(1, &afeConfig);
* Cy_HPPASS_AFE_Enable(1);
* \endcode
*
* \subsection subsection_afe_multi_config Multiple Configuration Structures
* \code
* // Define four different configurations
* cy_stc_hppass_afe_config_t config0 = {CY_HPPASS_AFE_GAIN_1, CY_HPPASS_AFE_INPUT_SRC_PIN_0,
*                                        CY_HPPASS_AFE_INPUT_SRC_GND, CY_HPPASS_AFE_INT_SEIN_SEOUT_UGB};
* cy_stc_hppass_afe_config_t config1 = {CY_HPPASS_AFE_GAIN_4, CY_HPPASS_AFE_INPUT_SRC_PIN_1,
*                                        CY_HPPASS_AFE_INPUT_SRC_GND, CY_HPPASS_AFE_INT_SEIN_SEOUT_PGA};
* cy_stc_hppass_afe_config_t config2 = {CY_HPPASS_AFE_GAIN_16, CY_HPPASS_AFE_INPUT_SRC_PIN_2,
*                                        CY_HPPASS_AFE_INPUT_SRC_GND, CY_HPPASS_AFE_INT_SEIN_SEOUT_PGA};
* cy_stc_hppass_afe_config_t config3 = {CY_HPPASS_AFE_GAIN_32, CY_HPPASS_AFE_INPUT_SRC_PIN_3,
*                                        CY_HPPASS_AFE_INPUT_SRC_GND, CY_HPPASS_AFE_INT_SEIN_SEOUT_PGA};
*
* cy_stc_hppass_afe_t afeConfig =
* {
*     .afe_gain_config = {config0, config1, config2, config3},
*     .config_ctl = CY_HPPASS_AFE_SELECT0_STRUCT_0,  // Start with Config 0
*     .trigger_select = 0
* };
*
* Cy_HPPASS_AFE_Init(0, &afeConfig);
* Cy_HPPASS_AFE_Enable(0);
*
* // Switch to Config 1 at runtime
* Cy_HPPASS_AFE_ConfigSelect(0, CY_HPPASS_AFE_SELECT1_STRUCT_1);
* \endcode
*
* \subsection subsection_afe_trigger_based Trigger-Based Configuration Switching
* \code
* // Configure for trigger-based switching between Config 0 and 1
* cy_stc_hppass_afe_config_t lowGain = {CY_HPPASS_AFE_GAIN_1, CY_HPPASS_AFE_INPUT_SRC_PIN_0,
*                                        CY_HPPASS_AFE_INPUT_SRC_GND, CY_HPPASS_AFE_INT_SEIN_SEOUT_PGA};
* cy_stc_hppass_afe_config_t highGain = {CY_HPPASS_AFE_GAIN_32, CY_HPPASS_AFE_INPUT_SRC_PIN_0,
*                                         CY_HPPASS_AFE_INPUT_SRC_GND, CY_HPPASS_AFE_INT_SEIN_SEOUT_PGA};
*
* cy_stc_hppass_afe_t afeConfig =
* {
*     .afe_gain_config = {lowGain, highGain, lowGain, highGain},
*     .config_ctl = CY_HPPASS_AFE_SELECT01_TRIG_01,  // Trigger-based switching
*     .trigger_select = 5  // Use trigger TR4 (value 5 = trigger 1-based)
* };
*
* Cy_HPPASS_AFE_Init(2, &afeConfig);
* Cy_HPPASS_AFE_Enable(2);
*
* // Configuration will now switch based on TR4 trigger events
* \endcode
*
* \subsection subsection_afe_runtime_update Runtime Configuration Updates
* \code
* // Update individual configuration parameters at runtime
*
* // Change gain for Config 0 of AFE instance 1
* Cy_HPPASS_AFE_GainConfig(1, 0, CY_HPPASS_AFE_GAIN_8);
*
* // Change input sources for Config 2 of AFE instance 0
* Cy_HPPASS_AFE_InputConfig(0, 2, CY_HPPASS_AFE_INPUT_SRC_PIN_2, CY_HPPASS_AFE_INPUT_SRC_PIN_3);
*
* // Update complete configuration structure
* cy_stc_hppass_afe_config_t newConfig = {CY_HPPASS_AFE_GAIN_2, CY_HPPASS_AFE_INPUT_SRC_DAC,
*                                          CY_HPPASS_AFE_INPUT_SRC_GND, CY_HPPASS_AFE_INT_SEIN_SEOUT_PGA};
* Cy_HPPASS_AFE_Config(0, 1, &newConfig);
* \endcode
*
* \subsection subsection_afe_power_save Power Management Example
* \code
* // Enable AFE for signal processing
* Cy_HPPASS_AFE_Enable(0);
*
* // ... perform signal processing ...
*
* // Disable AFE to save power
* Cy_HPPASS_AFE_Disable(0);
*
* // Or for finer control:
* Cy_HPPASS_AFE_ChargePump_Enable(1);   // Enable charge pump
* // ... short delay for charge pump stabilization ...
* Cy_HPPASS_AFE_Enable(1);               // Enable OPAMP
*
* // ... signal processing ...
*
* Cy_HPPASS_AFE_Disable(1);              // Disable OPAMP
* Cy_HPPASS_AFE_ChargePump_Disable(1);   // Disable charge pump for max power savings
* \endcode
*
* \section section_hppass_afe_important_notes Important Implementation Notes
*
* * All four configuration structures should be initialized even if not all are used
*   to ensure predictable behavior when configuration control is changed.
*
* * When using trigger-based configuration switching, ensure triggers are properly
*   configured in the MCPASS trigger infrastructure before enabling the AFE.
*
* * The trigger_select parameter uses 0 for disabled, values 1-16 map to triggers TR0-TR15.
*
* * Charge pump should be enabled before enabling the OPAMP for proper operation.
*   Allow sufficient settling time after enabling the charge pump.
*
* * When switching between configurations with different output modes, consider the
*   impact on downstream blocks (ADC, comparators, etc.) that may be using the AFE output.
*
* * For differential configurations, ensure both positive and negative inputs are
*   properly connected and within the common-mode input range.
*
* * Runtime configuration updates via Cy_HPPASS_AFE_GainConfig(), Cy_HPPASS_AFE_InputConfig(),
*   or Cy_HPPASS_AFE_Config() modify the configuration structure registers directly.
*   Changes take effect immediately if that configuration is currently active.
*
* \defgroup group_hppass_afe_macros Macros
* \{
*   \defgroup group_hppass_afe_dout GPIO Out Masks
*   \defgroup group_hppass_afe_seq_grp SAR Sequencer Groups mask.
* \}
* \defgroup group_hppass_afe_functions Functions
* \defgroup group_hppass_afe_data_structures Data Structures
* \defgroup group_hppass_afe_enums Enumerated Types
* \} */

#if !defined(CY_HPPASS_AFE_H)
#define CY_HPPASS_AFE_H

#include "cy_device.h"

#if defined(CY_IP_MXS40MCPASS) && (CY_IP_MXS40MCPASS_VERSION >= 3u)

#include "cy_hppass_ac.h"

#if defined(__cplusplus)
extern "C" {
#endif

/* CY_HPPASS_DRV_VERSION_MAJOR, CY_HPPASS_DRV_VERSION_MINOR, and CY_HPPASS_ID
 * are defined in cy_hppass_ac.h - do not redefine here. */



/**
* \addtogroup group_hppass_afe_macros
* \{
*/

#define CY_HPPASS_AFE_TRIGGER_SELECT_NUM       (15U) /**< The number Triggers available. */
#define CY_HPPASS_AFE_NUM_CONFIG_STRUCTS       (4U)  /**< The number of AFE Config structures available */
#define CY_HPPASS_AFE_NUM_INSTANCE             (4U)  /**< The number of AFE instance available */
#define CY_HPPASS_AFE_CONFIG_STRUCT_VALID(confIdx)               (CY_HPPASS_AFE_NUM_CONFIG_STRUCTS > (confIdx)) /**< For validating the config struct index passed */
#define CY_HPPASS_AFE_INDEX_VALID(afeIdx)                    (CY_HPPASS_AFE_NUM_INSTANCE > (afeIdx))        /**< For validating the AFE instance index passed */
#define CY_HPPASS_AFE_TRIGGER_NUMBER_VALID(trigger_number)   (CY_HPPASS_AFE_TRIGGER_SELECT_NUM > (trigger_number))  /**< For validating the trigger number passed */

/** \} group_hppass_afe_macros */

/***************************************
*       Enumerated Types
***************************************/


/**
* \addtogroup group_hppass_afe_enums
* \{
*/

/**
* AFE Gain selection
*/
typedef enum
{
    CY_HPPASS_AFE_GAIN_1   = 1U,  /**< AFE Gain 1x (Differential/Inverting SE), 2x (Noninverting SE). */
    CY_HPPASS_AFE_GAIN_2   = 2U,  /**< AFE Gain 2x (Differential/Inverting SE), 3x (Noninverting SE). */
    CY_HPPASS_AFE_GAIN_4   = 3U,  /**< AFE Gain 4x (Differential/Inverting SE), 5x (Noninverting SE). */
    CY_HPPASS_AFE_GAIN_8   = 4U,  /**< AFE Gain 8x (Differential/Inverting SE), 9x (Noninverting SE). */
    CY_HPPASS_AFE_GAIN_16  = 5U,  /**< AFE Gain 16x (Differential/Inverting SE), 17x (Noninverting SE). */
    CY_HPPASS_AFE_GAIN_32  = 6U,  /**< AFE Gain 32x (Differential/Inverting SE), 33x (Noninverting SE). */
    CY_HPPASS_AFE_GAIN_64  = 7U,  /**< AFE Gain 64x (Differential/Inverting SE), 65x (Noninverting SE). */
} cy_en_hppass_afe_gain_t;

/**
* AFE Input Source selection
*/
typedef enum
{
    CY_HPPASS_AFE_INPUT_SRC_PIN_0   = 0U,  /**< AFE Input source is set to PIN0. */
    CY_HPPASS_AFE_INPUT_SRC_PIN_1   = 1U,  /**< AFE Input source is set to PIN1. */
    CY_HPPASS_AFE_INPUT_SRC_PIN_2   = 2U,  /**< AFE Input source is set to PIN2. */
    CY_HPPASS_AFE_INPUT_SRC_PIN_3   = 3U,  /**< AFE Input source is set to PIN3. */
    CY_HPPASS_AFE_INPUT_SRC_DAC     = 4U,  /**< AFE Input source is set to DAC.  */
    CY_HPPASS_AFE_INPUT_SRC_AREF    = 5U,  /**< AFE Input source is set to AREF. */
    CY_HPPASS_AFE_INPUT_SRC_GND     = 6U,  /**< AFE Input source is set to GND.  */
} cy_en_hppass_afe_input_src_t;

/**
* AFE Output mode selection
*/
typedef enum
{
    CY_HPPASS_AFE_EXT_SEIN_SEOUT         = 0U,  /**< External single ended input and single ended output. Can be configured as UGB or PGA. */
    CY_HPPASS_AFE_EXT_SEIN_SEOUT_UGB     = 0U,  /**< \deprecated Use CY_HPPASS_AFE_EXT_SEIN_SEOUT instead. */
    CY_HPPASS_AFE_INT_SEIN_SEOUT_UGB    = 1U,  /**< Internal single ended input and single ended output with Unity Gain Amplifier. */
    CY_HPPASS_AFE_INT_DIFIN_DIFOUT_PGA  = 2U,  /**< Internal Differential input and Differential output with Programmable Gain Amplifier. */
    CY_HPPASS_AFE_INT_SEIN_SEOUT_PGA    = 3U,  /**< Internal single ended input and single ended output with Programmable Gain Amplifier. */
    CY_HPPASS_AFE_INT_DIFIN_SEOUT_PGA   = 4U,  /**< Internal Differential input and single ended output with Programmable Gain Amplifier. */
} cy_en_hppass_afe_output_mode_t;

/**
* AFE VCM (common-mode voltage) control selection.
* The VCM generator is shared amongst all AFE OpAmps.
* \note DIFIN_DIFOUT_PGA mode requires VCM to be set to
*       \ref CY_HPPASS_AFE_VCM_VDDA_DIV2 or \ref CY_HPPASS_AFE_VCM_VAREF_DIV2.
*       DIFIN_SEOUT_PGA mode requires VCM to be \ref CY_HPPASS_AFE_VCM_OFF.
*       Other modes are independent of VCM.
*/
typedef enum
{
    CY_HPPASS_AFE_VCM_OFF          = 0U,  /**< VCM generator block off (reset default). Required for DIFIN_SEOUT_PGA mode. */
    CY_HPPASS_AFE_VCM_VDDA_DIV2    = 1U,  /**< VCM connects to VDDA and outputs VDDA/2. Required for DIFIN_DIFOUT_PGA mode. */
    CY_HPPASS_AFE_VCM_VAREF_DIV2   = 2U,  /**< VCM connects to varef_ext and outputs varef_ext/2. Alternative for DIFIN_DIFOUT_PGA mode. */
} cy_en_hppass_afe_vcm_t;

/**
* AFE Config Control selection
*/
typedef enum
{
    CY_HPPASS_AFE_SELECT0_STRUCT_0   = 0U,  /**< AFE config control set to config struct 0. */
    CY_HPPASS_AFE_SELECT1_STRUCT_1   = 1U,  /**< AFE config control set to config struct 1. */
    CY_HPPASS_AFE_SELECT2_STRUCT_2   = 2U,  /**< AFE config control set to config struct 2. */
    CY_HPPASS_AFE_SELECT3_STRUCT_3   = 3U,  /**< AFE config control set to config struct 3. */
    CY_HPPASS_AFE_SELECT01_TRIG_01   = 4U,  /**< Use Trigger Based Selection to Choose Configuration 0 ot 1.  */
    CY_HPPASS_AFE_SELECT23_TRIG_23   = 5U,  /**< Use Trigger Based Selection to Choose Configuration 2 ot 3. */
} cy_en_hppass_afe_config_ctl_t;

/** \} group_hppass_afe_enums */

/***************************************
*       Configuration Structures
***************************************/

/**
* \addtogroup group_hppass_afe_data_structures
* \{
*/

/** Opamp configuration structure */
typedef struct
{
    cy_en_hppass_afe_gain_t afe_gain;              /**< Gain configuration. \ref cy_en_hppass_afe_gain_t */
    cy_en_hppass_afe_input_src_t pIn;              /**< Positive line input selection. \ref cy_en_hppass_afe_input_src_t */
    cy_en_hppass_afe_input_src_t nIn;              /**< Negative line input selection. \ref cy_en_hppass_afe_input_src_t */
    cy_en_hppass_afe_output_mode_t output_mode;    /**< AFE Output mode selection. \ref cy_en_hppass_afe_output_mode_t */
} cy_stc_hppass_afe_config_t;

/** Startup configuration structure */
typedef struct
{
    cy_stc_hppass_afe_config_t afe_gain_config[4];   /**< Gain configuration. \ref cy_stc_hppass_afe_config_t */
    cy_en_hppass_afe_config_ctl_t config_ctl;             /**< Sets the config structure to be used out of the four structures available.  \ref cy_en_hppass_afe_config_ctl_t */
    uint8_t trigger_select;                               /**< Trigger selection. Total 16 triggers values : 1 to 16. When set to 0 trigger input is disabled. */
} cy_stc_hppass_afe_t;

/** \} group_hppass_afe_data_structures */


/***************************************
*        Function Prototypes
***************************************/

/** \addtogroup group_hppass_afe_functions
*   \{ */


/*******************************************************************************
* Function Name: Cy_HPPASS_AFE_Enable
****************************************************************************//**
*
* Enables the AFE OPAMP based on the index passed.
*
* \param afeIdx
* AFE Index number
*
*******************************************************************************/
__STATIC_INLINE void Cy_HPPASS_AFE_Enable(uint8_t afeIdx)
{
    CY_ASSERT_L1(CY_HPPASS_AFE_INDEX_VALID(afeIdx));

    /* The AFE input pins are held under direct control until the AFE is brought
     * into operation. Hand control of the input pins back to the configuration
     * field while the AFE OPAMP is enabled by clearing ENABLE_DIRECT_CTRL. */
    HPPASS_AFE_TSTCTL(HPPASS_BASE, afeIdx) &= ~HPPASS_AFE_AFE_AFE_ANALOG_TST_CTRL_ENABLE_DIRECT_CTRL_Msk;

    HPPASS_AFE_ANALOG_CTRL(HPPASS_BASE, afeIdx) |= HPPASS_AFE_AFE_AFE_ANALOG_CTRL_AFE_CTRL_EN_OPAMP_Msk |
                                                    HPPASS_AFE_AFE_AFE_ANALOG_CTRL_AFE_CTRL_EN_CP_Msk |
                                                    HPPASS_AFE_AFE_AFE_ANALOG_CTRL_AFE_CTRL_PROT_RESET_Msk;
}

/*******************************************************************************
* Function Name: Cy_HPPASS_AFE_Disable
****************************************************************************//**
*
* Disables the AFE OPAMP based on the index passed.
*
* \param afeIdx
* AFE Index number
*
*******************************************************************************/
__STATIC_INLINE void Cy_HPPASS_AFE_Disable(uint8_t afeIdx)
{
    CY_ASSERT_L1(CY_HPPASS_AFE_INDEX_VALID(afeIdx));
    HPPASS_AFE_ANALOG_CTRL(HPPASS_BASE, afeIdx) &= ~(HPPASS_AFE_AFE_AFE_ANALOG_CTRL_AFE_CTRL_EN_OPAMP_Msk | HPPASS_AFE_AFE_AFE_ANALOG_CTRL_AFE_CTRL_EN_CP_Msk);

    /* With the AFE OPAMP disabled, return the AFE input pins to direct control
     * by re-asserting ENABLE_DIRECT_CTRL, matching the post-boot safe state. */
    HPPASS_AFE_TSTCTL(HPPASS_BASE, afeIdx) |= HPPASS_AFE_AFE_AFE_ANALOG_TST_CTRL_ENABLE_DIRECT_CTRL_Msk;
}

/*******************************************************************************
* Function Name: Cy_HPPASS_AFE_ChargePump_Enable
****************************************************************************//**
*
* Enables the AFE charge pump based on the index passed.
*
* \param afeIdx
* AFE Index number
*
*******************************************************************************/
__STATIC_INLINE void Cy_HPPASS_AFE_ChargePump_Enable(uint8_t afeIdx)
{
    CY_ASSERT_L1(CY_HPPASS_AFE_INDEX_VALID(afeIdx));
    HPPASS_AFE_ANALOG_CTRL(HPPASS_BASE, afeIdx) |= HPPASS_AFE_AFE_AFE_ANALOG_CTRL_AFE_CTRL_EN_CP_Msk;
}

/*******************************************************************************
* Function Name: Cy_HPPASS_AFE_ChargePump_Disable
****************************************************************************//**
*
* Disables the AFE charge pump based on the index passed.
*
* \param afeIdx
* AFE Index number
*
*******************************************************************************/
__STATIC_INLINE void Cy_HPPASS_AFE_ChargePump_Disable(uint8_t afeIdx)
{
    CY_ASSERT_L1(CY_HPPASS_AFE_INDEX_VALID(afeIdx));
    HPPASS_AFE_ANALOG_CTRL(HPPASS_BASE, afeIdx) &= ~HPPASS_AFE_AFE_AFE_ANALOG_CTRL_AFE_CTRL_EN_CP_Msk;
}

/*******************************************************************************
* Function Name: Cy_HPPASS_AFE_SetVcm
****************************************************************************//**
*
* Configures the AFE common-mode voltage (VCM) generator.
* The VCM generator is shared amongst all four AFE OpAmps.
*
* \note DIFIN_DIFOUT_PGA mode requires VCM to be set to
*       \ref CY_HPPASS_AFE_VCM_VDDA_DIV2 or \ref CY_HPPASS_AFE_VCM_VAREF_DIV2.
*       DIFIN_SEOUT_PGA mode requires VCM to be \ref CY_HPPASS_AFE_VCM_OFF.
*       Other modes are independent of VCM.
*       Since VCM is shared, all active AFE instances must use modes
*       compatible with the selected VCM setting.
*
* \param vcm
* VCM generator control value. \ref cy_en_hppass_afe_vcm_t
*
*******************************************************************************/
__STATIC_INLINE void Cy_HPPASS_AFE_SetVcm(cy_en_hppass_afe_vcm_t vcm)
{
    CY_REG32_CLR_SET(HPPASS_INFRA_ANA_COMMON_CTRL(HPPASS_BASE),
                     HPPASS_INFRA_ANA_COMMON_CTRL_AFE_VCM_CTRL,
                     (uint32_t)vcm);
}

/*******************************************************************************
* Function Name: Cy_HPPASS_AFE_GetVcm
****************************************************************************//**
*
* Returns the current AFE common-mode voltage (VCM) generator setting.
*
* \return
* Current VCM setting. \ref cy_en_hppass_afe_vcm_t
*
*******************************************************************************/
__STATIC_INLINE cy_en_hppass_afe_vcm_t Cy_HPPASS_AFE_GetVcm(void)
{
    return (cy_en_hppass_afe_vcm_t)_FLD2VAL(HPPASS_INFRA_ANA_COMMON_CTRL_AFE_VCM_CTRL,
                                            HPPASS_INFRA_ANA_COMMON_CTRL(HPPASS_BASE));
}

/*******************************************************************************
* Function Name: Cy_HPPASS_AFE_Config
****************************************************************************//**
*
* Programs one of the four available configuration structures (0-3) with the
* specified gain, positive input, negative input, and output mode settings.
*
* \note This function only programs the configuration register and does not
*       modify the shared VCM setting. VCM is automatically configured by
*       \ref Cy_HPPASS_AFE_Init and \ref Cy_HPPASS_AFE_ConfigSelect based on
*       the active configuration's output mode. Use \ref Cy_HPPASS_AFE_SetVcm
*       to override if needed.
*
* \param afeIdx
* AFE Index number
*
* \param confIdx
* Config struct Index number
*
* \param config
*  configures the config structure  \ref cy_stc_hppass_afe_config_t
*
* \return
* Status of initialization, \ref cy_en_hppass_status_t.
*******************************************************************************/
__STATIC_INLINE cy_en_hppass_status_t Cy_HPPASS_AFE_Config(uint8_t afeIdx, uint8_t confIdx, const cy_stc_hppass_afe_config_t *config)
{
    CY_ASSERT_L1(CY_HPPASS_AFE_INDEX_VALID(afeIdx));
    CY_ASSERT_L1(CY_HPPASS_AFE_CONFIG_STRUCT_VALID(confIdx));
    cy_rslt_t result = (cy_rslt_t)CY_HPPASS_SUCCESS;
    if (NULL == config)
    {
        result = (cy_rslt_t)CY_HPPASS_BAD_PARAM;
    }
    else
    {
        HPPASS_AFE_CONFIG(HPPASS_BASE, afeIdx, confIdx) = _VAL2FLD(HPPASS_AFE_AFE_AFE_CONFIG_OPAMP_GAIN, (uint32_t)config->afe_gain)      |
                                                    _VAL2FLD(HPPASS_AFE_AFE_AFE_CONFIG_CONFIGURATION, (uint32_t)config->output_mode) |
                                                    _VAL2FLD(HPPASS_AFE_AFE_AFE_CONFIG_POS_INPUT_SRC, (uint32_t)config->pIn)         |
                                                    _VAL2FLD(HPPASS_AFE_AFE_AFE_CONFIG_NEG_INPUT_SRC, (uint32_t)config->nIn);

        result = (cy_rslt_t)CY_HPPASS_SUCCESS;
    }
    return (cy_en_hppass_status_t)result;
}

/*******************************************************************************
* Function Name: Cy_HPPASS_AFE_ConfigSelect
****************************************************************************//**
*
* Selects which of the four configuration structures (0-3) is currently active.
* Use Cy_HPPASS_AFE_Config() to program the configuration structure settings.
*
* \note For non-trigger-based selections (Config 0-3), this function
*       automatically configures the shared VCM generator based on the
*       selected configuration's output mode:
*       - \ref CY_HPPASS_AFE_INT_DIFIN_DIFOUT_PGA: VCM set to VDDA/2
*         (if currently off)
*       - \ref CY_HPPASS_AFE_INT_DIFIN_SEOUT_PGA: VCM set to off
*       - Other modes: VCM not modified
*       For trigger-based modes (TRIG_01, TRIG_23), VCM is not
*       auto-configured; ensure both configs use compatible VCM settings
*       or call \ref Cy_HPPASS_AFE_SetVcm manually.
*
* \param afeIdx
* AFE Index number
*
* \param config_ctl
*  Sets the config structure to be used out of the four structures available.  \ref cy_en_hppass_afe_config_ctl_t
*
*******************************************************************************/
__STATIC_INLINE void Cy_HPPASS_AFE_ConfigSelect(uint8_t afeIdx, cy_en_hppass_afe_config_ctl_t config_ctl)
{
    CY_ASSERT_L1(CY_HPPASS_AFE_INDEX_VALID(afeIdx));
    CY_REG32_CLR_SET(HPPASS_AFE_CNFGCTL(HPPASS_BASE, afeIdx), HPPASS_AFE_AFE_AFECONFIG_CTRL_MUX_CTRL, (uint32_t)config_ctl);

    /* Auto-configure VCM based on the newly selected configuration's output mode */
    if ((uint32_t)config_ctl <= (uint32_t)CY_HPPASS_AFE_SELECT3_STRUCT_3)
    {
        cy_en_hppass_afe_output_mode_t mode = (cy_en_hppass_afe_output_mode_t)
            _FLD2VAL(HPPASS_AFE_AFE_AFE_CONFIG_CONFIGURATION,
                     HPPASS_AFE_CONFIG(HPPASS_BASE, afeIdx, (uint32_t)config_ctl));

        if (CY_HPPASS_AFE_INT_DIFIN_DIFOUT_PGA == mode)
        {
            if (CY_HPPASS_AFE_VCM_OFF == Cy_HPPASS_AFE_GetVcm())
            {
                Cy_HPPASS_AFE_SetVcm(CY_HPPASS_AFE_VCM_VDDA_DIV2);
            }
        }
        else if (CY_HPPASS_AFE_INT_DIFIN_SEOUT_PGA == mode)
        {
            Cy_HPPASS_AFE_SetVcm(CY_HPPASS_AFE_VCM_OFF);
        }
        else
        {
            /* Other modes are independent of VCM - do not modify */
        }
    }
    /* For trigger-based modes (TRIG_01, TRIG_23), VCM is not auto-configured.
     * User must ensure both trigger configs use compatible VCM settings,
     * or call Cy_HPPASS_AFE_SetVcm() manually. */
}

/*******************************************************************************
* Function Name: Cy_HPPASS_AFE_TriggerConfigSelect
****************************************************************************//**
*
* sets the trigger number. mainly this is used when Config select is configured to TRIG01 or TRIG23. \ref cy_en_hppass_afe_config_ctl_t
*
* \param afeIdx
* AFE Index number
*
* \param trigger_number
*  Sets the trigger number.
*
*******************************************************************************/
__STATIC_INLINE cy_en_hppass_status_t Cy_HPPASS_AFE_TriggerConfigSelect(uint8_t afeIdx, uint8_t trigger_number)
{
    CY_ASSERT_L1(CY_HPPASS_AFE_INDEX_VALID(afeIdx));
    CY_REG32_CLR_SET(HPPASS_AFE_CNFGCTL(HPPASS_BASE, afeIdx), HPPASS_AFE_AFE_AFECONFIG_CTRL_AFEMUX_CONFIG_TR_SEL, trigger_number);
    return (cy_en_hppass_status_t)CY_HPPASS_SUCCESS;
}

/*******************************************************************************
* Function Name: Cy_HPPASS_AFE_InputConfig
****************************************************************************//**
*
* Sets positive input line selection and the negative input line selection.
*
* \param afeIdx
* AFE Index number
*
* \param confIdx
* Config struct Index number
*
* \param pIn
*  Positive line input selection. \ref cy_en_hppass_afe_input_src_t
*
* \param nIn
*  Negative line input selection. \ref cy_en_hppass_afe_input_src_t
*
*******************************************************************************/
__STATIC_INLINE cy_en_hppass_status_t Cy_HPPASS_AFE_InputConfig(uint8_t afeIdx, uint8_t confIdx, cy_en_hppass_afe_input_src_t pIn, cy_en_hppass_afe_input_src_t nIn)
{
    CY_ASSERT_L1(CY_HPPASS_AFE_INDEX_VALID(afeIdx));
    CY_ASSERT_L1(CY_HPPASS_AFE_CONFIG_STRUCT_VALID(confIdx));
    CY_REG32_CLR_SET(HPPASS_AFE_CONFIG(HPPASS_BASE, afeIdx, confIdx), HPPASS_AFE_AFE_AFE_CONFIG_POS_INPUT_SRC, (uint32_t)pIn);
    CY_REG32_CLR_SET(HPPASS_AFE_CONFIG(HPPASS_BASE, afeIdx, confIdx), HPPASS_AFE_AFE_AFE_CONFIG_NEG_INPUT_SRC, (uint32_t)nIn);
    return (cy_en_hppass_status_t)CY_HPPASS_SUCCESS;
}

/*******************************************************************************
* Function Name: Cy_HPPASS_AFE_GainConfig
****************************************************************************//**
*
* sets the gain value
*
* \param afeIdx
* AFE Index number
*
* \param confIdx
* Config struct Index number
*
* \param gain
*  Gain value. \ref cy_en_hppass_afe_gain_t
*
*******************************************************************************/
__STATIC_INLINE cy_en_hppass_status_t Cy_HPPASS_AFE_GainConfig(uint8_t afeIdx, uint8_t confIdx, cy_en_hppass_afe_gain_t gain)
{
    CY_ASSERT_L1(CY_HPPASS_AFE_INDEX_VALID(afeIdx));
    CY_ASSERT_L1(CY_HPPASS_AFE_CONFIG_STRUCT_VALID(confIdx));
    CY_REG32_CLR_SET(HPPASS_AFE_CONFIG(HPPASS_BASE, afeIdx, confIdx), HPPASS_AFE_AFE_AFE_CONFIG_OPAMP_GAIN, (uint32_t)gain);
    return (cy_en_hppass_status_t)CY_HPPASS_SUCCESS;
}

/*******************************************************************************
* Function Name: Cy_HPPASS_AFE_Init
****************************************************************************//**
*
* Initializes the AFE instance with the configuration structure provided.
* Programs all four configuration structures, sets configuration control mode,
* and configures trigger selection.
*
* \note For non-trigger-based config_ctl selections (Config 0-3), this function
*       automatically configures the shared VCM generator based on the
*       initially active configuration's output mode:
*       - \ref CY_HPPASS_AFE_INT_DIFIN_DIFOUT_PGA: VCM set to VDDA/2
*         (if currently off)
*       - \ref CY_HPPASS_AFE_INT_DIFIN_SEOUT_PGA: VCM set to off
*       - Other modes: VCM not modified
*       For trigger-based config_ctl (TRIG_01, TRIG_23), VCM is not
*       auto-configured; call \ref Cy_HPPASS_AFE_SetVcm manually.
*       Since VCM is shared across all AFE instances, ensure all active
*       AFE instances use modes compatible with the same VCM setting.
*
* \param afeIdx
* AFE Index number
*
* \param config
* Config struct
*
* \return
* Status of initialization, \ref cy_en_hppass_status_t.
*******************************************************************************/
__STATIC_INLINE cy_en_hppass_status_t Cy_HPPASS_AFE_Init(uint8_t afeIdx, const cy_stc_hppass_afe_t *config)
{
    CY_ASSERT_L1(CY_HPPASS_AFE_INDEX_VALID(afeIdx));
    cy_rslt_t result = (cy_rslt_t)CY_HPPASS_SUCCESS;

    if (NULL == config)
    {
        result = (cy_rslt_t)CY_HPPASS_BAD_PARAM;
    }
    else
    {
        for (uint32_t i = 0UL; i < CY_HPPASS_AFE_NUM_CONFIG_STRUCTS; i++)
        {
            result |= (cy_rslt_t)Cy_HPPASS_AFE_Config(afeIdx, i, &config->afe_gain_config[i]);
        }
        HPPASS_AFE_CNFGCTL(HPPASS_BASE, afeIdx) = _VAL2FLD(HPPASS_AFE_AFE_AFECONFIG_CTRL_MUX_CTRL, (uint32_t)config->config_ctl)  |
                                                  _VAL2FLD(HPPASS_AFE_AFE_AFECONFIG_CTRL_AFEMUX_CONFIG_TR_SEL, config->trigger_select);

        /* Set VCM based on the initially active configuration's output mode */
        if ((uint32_t)config->config_ctl <= (uint32_t)CY_HPPASS_AFE_SELECT3_STRUCT_3)
        {
            cy_en_hppass_afe_output_mode_t mode = config->afe_gain_config[(uint32_t)config->config_ctl].output_mode;

            if (CY_HPPASS_AFE_INT_DIFIN_DIFOUT_PGA == mode)
            {
                if (CY_HPPASS_AFE_VCM_OFF == Cy_HPPASS_AFE_GetVcm())
                {
                    Cy_HPPASS_AFE_SetVcm(CY_HPPASS_AFE_VCM_VDDA_DIV2);
                }
            }
            else if (CY_HPPASS_AFE_INT_DIFIN_SEOUT_PGA == mode)
            {
                Cy_HPPASS_AFE_SetVcm(CY_HPPASS_AFE_VCM_OFF);
            }
            else
            {
                /* Other modes are independent of VCM - do not modify */
            }
        }
        /* For trigger-based modes, VCM is not auto-configured */
    }
    return (cy_en_hppass_status_t)result;
}

/** \} group_hppass_afe_functions */

/** \} */

#if defined(__cplusplus)
}
#endif

#endif /* CY_IP_MXS40MCPASS && CY_IP_MXS40MCPASS_VERSION >= 3u */

#endif /** !defined(CY_HPPASS_AFE_H) */

/* [] END OF FILE */
