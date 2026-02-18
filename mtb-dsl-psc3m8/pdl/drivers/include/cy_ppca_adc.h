/***************************************************************************//**
* \file cy_ppca_adc.h
* \version 1.0
*
* The header file of the PPCA ADC driver.
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


#if !defined(CY_PPCA_ADC_H)
#define CY_PPCA_ADC_H

#include "cy_device.h"

#if defined (CY_IP_MXS40PPSS) || defined (CY_DOXYGEN)

#include "cy_syslib.h"

#if defined(__cplusplus)
extern "C" {
#endif



/**
* \addtogroup group_ppca_atop          ATOP
* \{
* The MXS40ATOPSS (Analog Top SubSystem) provides the analog front-end for the
* Programmable Power Control Accelerator (PPCA). It operates autonomously, independent of the
* chip main CPU, and is fully controlled by the PPSS embedded processors or
* by an external bus master.
*
* \section group_ppca_atop_overview Overview
*
* The ATOPSS contains the following analog blocks:
* - <b>4 ADC instances</b> (SAR, 12-bit, up to 25 MSPS) organized in groups
*   (ADC_GRP_0, ADC_GRP_1, ADC_GRP_2, ADC_GRP_3) each with its own AFE
* - <b>2 ADC Filter blocks per ADC</b> with Median, Linear Interpolation,
*   Low-Pass, CIC3, and Averaging stages plus MIN/MAX detection
* - <b>9 DCSG slices</b> (Digital Comparator and Slope Generator) organized in
*   two groups: GRP_0 (6 slices) and GRP_1 (3 slices)
* - <b>2 R2R DACs</b> (12-bit, up to 2 MHz refresh rate)
* - <b>1 IDAC</b> (current output DAC for sensor biasing)
* - <b>2 Input MUXes</b> for flexible analog channel routing
* - <b>1 Temperature Sensor (TSNS)</b> for on-chip temperature measurement
* - <b>1 AREF</b> (Analog Reference) providing bandgap voltage and current
*   references for all analog blocks
*
* The ATOPSS is accessed through 6 AHB5 slave interfaces and supports hardware
* triggered operation via the EPU trigger bus.
*
* \section group_ppca_atop_glossary Glossary
* <table class="doxtable">
*   <tr><th>Abbreviation</th><th>Description</th></tr>
*   <tr><td>ADC</td><td>Analog-to-Digital Converter (SAR architecture)</td></tr>
*   <tr><td>AFE</td><td>Analog Front End (programmable gain amplifier)</td></tr>
*   <tr><td>AREF</td><td>Analog Reference (bandgap voltage/current generator)</td></tr>
*   <tr><td>CIC</td><td>Cascaded Integrator-Comb filter (3rd order)</td></tr>
*   <tr><td>DAC R2R</td><td>R2R ladder Digital-to-Analog Converter</td></tr>
*   <tr><td>DCSG</td><td>Digital Comparator and Slope Generator</td></tr>
*   <tr><td>GPI</td><td>General Purpose Input (analog level detector)</td></tr>
*   <tr><td>IDAC</td><td>Current-output Digital-to-Analog Converter</td></tr>
*   <tr><td>SLGEN</td><td>Slope Generator (ramp waveform generator within DCSG)</td></tr>
*   <tr><td>TSNS</td><td>Temperature Sensor</td></tr>
* </table>

*******************************************************************************
* \section group_ppca_atop_changelog Changelog
*******************************************************************************
* <table class="doxtable">
*   <tr><th>Version</th><th>Changes</th><th>Reason for Change</th></tr>
*   <tr>
*     <td rowspan="1">1.0</td>
*     <td>Initial version.</td>
*     <td></td>
*   </tr>
* </table>
*
* \defgroup group_ppca_adc           ADC
* \{
*   The ADC driver provides an interface to the SAR (Successive Approximation
*   Register) ADC and its associated Analog Front End (AFE) within the ATOPSS.
*
*   \section group_ppca_adc_overview Overview
*
*   Each ADC instance is a 12-bit SAR converter capable of up to 25 MSPS
*   conversion rate. The input voltage range is -0.4 V to 3.63 V (single ended)
*   and the ADC accepts both single-ended and differential inputs.
*
*   <b>ADC Groups and Channels:</b>
*   - ADC_GRP_0 / ADC_GRP_3: 4 differential or 8 single-ended channels (ch0–ch7)
*     plus auxiliary channels (DAC R2R loopback, AI0/AI1, TSNS, VREF, VDDA/2)
*   - ADC_GRP_1 / ADC_GRP_2: 2 differential or 4 single-ended channels (ch0–ch3)
*
*   \note Channel 7 is multiplexed with the auxiliary (AUX) and alternate
*   auxiliary (ALT_AUX) channel inputs. To use AUX or ALT_AUX channels,
*   channel 7 must be enabled (bit 7 set in \ref cy_stc_ppca_adc_config_t
*   channels field) and the \ref cy_stc_aux_slot_config_t ch7_data_path
*   field must be set to \ref CY_DATA_PATH_AUX or \ref CY_DATA_PATH_ALT_AUX
*   accordingly. When channel 7 is used as a regular ADC input, set
*   ch7_data_path to \ref CY_DATA_PATH_ADC7.
*
*   <b>Analog Front End (AFE):</b>
*   Each ADC group has an optional AFE that provides programmable gain
*   (x3, x6, x12, x24) and configurable power/speed trade-offs. The AFE clock
*   ratio setting determines the effective MSPS rate relative to ATOP_CLK.
*
*   <b>Trigger Modes:</b>
*   - Manual: CPU triggers a single conversion sequence
*   - Auto: Continuous conversion after initial trigger
*   - Arbitrary: Individual channel conversion via external SOC signals
*
*   <b>Reference Voltage:</b>
*   Supports an internal 1.2 V bandgap reference or an external reference via
*   AREF. The internal reference is generated by the AREF block.
*
*   \note <b>Analog power-up ordering (required):</b> On PSC3M8-A0 the AFE must
*   be enabled before the ADC — if the AFE is not powered up first, ADC_BUSY
*   never clears and conversions never complete. After enabling the AREF, allow
*   an adequate bandgap settling delay (~10 ms) before starting conversions;
*   otherwise VREF reads near 0. The complete power-up sequence is:
*
*   \code
*   // 1. AFE (analog front-end power) -- REQUIRED, or ADC_BUSY never clears
*   Cy_PPCA_AFE_Init(afeBase, &afeConfig);
*   Cy_PPCA_AFE_Enable(afeBase);
*
*   // 2. AREF (bandgap)
*   Cy_PPCA_AREF_Init(arefBase, &arefConfig);
*   Cy_PPCA_AREF_Enable(arefBase);
*   Cy_PPCA_AREF_SetAnalogCtrl(arefBase, CY_AREF_FORCE_POR_1); // after AREF_Enable
*   Cy_SysLib_Delay(10U);                                      // AREF bandgap settling ~10 ms
*
*   // 3. ADC
*   Cy_PPCA_ADC_Init(adcBase, &adcConfig);
*   Cy_PPCA_ADC_Enable(adcBase);
*   \endcode
*
*   \note Initialization of ADC and AFE (Cy_PPCA_ADC_Init, Cy_PPCA_AFE_Init)
*   must be called from the Main core so that trim registers are configured
*   correctly.
*
*   \note When VREF monitoring is enabled as an AUX channel (CY_AUX_CHANNEL_VREF),
*   sampling VREF introduces kickback noise that disturbs the VREF node voltage.
*   Since VREF is the reference used by the ADC, this can degrade measurement
*   accuracy across all ADC channels (not only AUX channels). To mitigate this,
*   set auto_trigger_sample_clck to the maximum value (63) in
*   \ref cy_stc_adc_conversion_config_t to allow sufficient settling time after
*   the kickback noise.
*
*   \note <b>ADC output data path:</b> the raw ADC_IP conversion result (or, when
*   test mode is enabled via Cy_PPCA_ADC_Set_Test_mode, the value written via
*   Cy_PPCA_ADC_Write_Test_data) is first passed through Gain Correction, then
*   Offset Correction. The corrected result is available both as an unsigned
*   value and, via a Signed Translation stage, as a signed value. A final
*   selector (based on the per-channel ADC_SIGN_UNSIGN_CNFG / AUX_SIGN_UNSIGN_CNFG /
*   AUX_AL_SIGN_UNSIGN_CNFG configuration) determines which representation is
*   presented in the mmio result registers (ADC_DATA / ADC_AUX_DATA /
*   ADC_ALT_AUX_DATA), in the Export Data outputs, and to the DCMP. The ADC
*   Filter input path has its own independent signed/unsigned selector,
*   AFLT_CTL.UNSIGN_PATH_EN (0 = normal/signed filter operation; 1 = unsigned
*   bypass, intended for test purposes only - do not use in normal operation).
*   \note Gain Correction and Offset Correction are per-channel silicon
*   calibration stages, controllable via \ref Cy_PPCA_ADC_Set_Gain_Correction /
*   \ref Cy_PPCA_ADC_Get_Gain_Correction (ADC_CALGAIN) and
*   \ref Cy_PPCA_ADC_Set_Offset / \ref Cy_PPCA_ADC_Get_Offset (ADC_CALOFFSET),
*   each with independent single-ended and differential fields selected via
*   the \p mode parameter (\ref CY_ADC_SINGLE_ENDED_CHANNEL /
*   \ref CY_ADC_DIFFERENTIAL_CHANNEL). The AFE gain preset applied ahead of
*   this stage (when the AFE is in use) remains separately readable via
*   \ref Cy_PPCA_ADC_Get_Gain_Setting (AFE_GAIN_SET, selected through
*   Cy_PPCA_AFE_Init).
*
*   \section group_ppca_adc_changelog Changelog
*    <table class="doxtable">
*     <tr><th>Version</th><th>Changes</th><th>Reason for Change</th></tr>
*     <tr>
*       <td>1.0</td>
*       <td>Initial version</td>
*       <td></td>
*     </tr>
*    </table>
*   \defgroup group_ppca_adc_macros                Macros
*   \defgroup group_ppca_adc_functions             Functions
*   \defgroup group_ppca_adc_data_structures Data Structures
*
* \}
* \defgroup group_ppca_adc_filter    ADC Filter
* \defgroup group_ppca_dcmp          DCMP         (Digital Comparator)
* \defgroup group_ppca_dcsg          DCSG         (Differential Comparator And Slope Generator)
* \defgroup group_ppca_dcsg_slgen    DCSG SLGEN   (Slope Generator)
* \defgroup group_ppca_dacr2r        DAC          (DAC R2R)
* \defgroup group_ppca_aref          AREF
* \} */

/**
* \addtogroup group_ppca_adc_macros
* \{
*/
/** ATOPSS AFE Type */
#define ATOPSS_AFE_TYPE PPCA_ATOPSS_ADC_GRP_SLICE_AFE_Type
/** ATOPSS ADC Type */
#define ATOPSS_ADC_TYPE PPCA_ATOPSS_ADC_GRP_SLICE_ADC_Type
/** ADC Mirror Type */
#define ADCM_TYPE PPCA_ADCM_ADCM_Type
/** ADC Error interrupt mask */
#define ATOPSS_ADC_ERROR_INTERRUPT_MASK PPCA_ATOPSS_ADC_GRP_ADC_SLICE_ADC_ADC_INTR_MASK_TR_ERROR_Msk

/** \} group_ppca_adc_macros */

/** \cond INTERNAL */
#define CY_ADC_CHANNEL(ch_num)            (ch_num <= 16u)
#define CY_ADC_AUX_CHANNEL(ch_num)        ((uint16_t)ch_num <= 16u)
#define CY_ADC_ALT_AUX_CHANNEL(ch_num)    ((uint16_t)ch_num <= 8u)

#define CY_ADC_MIRROR_MAX_INDEX         (48u)

#define CY_ADC_SINGLE_ENDED_CHANNEL    0U
#define CY_ADC_DIFFERENTIAL_CHANNEL    1U

#define CY_ADC_SIGNED_CHANNEL          1
#define CY_ADC_UNSIGNED_CHANNEL        0
#define CY_PPCA_ADC_TEMP_VALID(val)       ((0 < (val)))
#define CY_PPCA_TWO_TOPOWEROF_TEN ((int32_t)1024)
#define CY_PPCA_TWO_TOPOWEROF_SIXTEEN ((int32_t)65536)
#define CY_PPCA_XC (float)15.0
#define CY_PPCA_YC (float)0.5
#define CY_PPCA_SAR_100C (float)100.0
#define CY_PPCA_SAR_40C (float)40.0
#define Cy_PPCA_ADC_Manual_Trigger Cy_PPCA_ADC_Trigger
/** \endcond */
/**
* \addtogroup group_ppca_adc_data_structures
* \{
*/

/** ADC Auxiliary Channels selection multiplexed with channel 7 P Pin  */
typedef enum
{
    CY_DAC_R2R0_OUTPUT      = 0UL,        /**< DAC_R2R_0 Output      */
    CY_DAC_R2R1_OUTPUT      = 1UL,        /**< DAC_R2R_1 Output      */
    CY_AUX_CHANNEL_AI0      = 2UL,        /**< Auxiliary channel AI0  */
    CY_AUX_CHANNEL_AI1      = 3UL,        /**< Auxiliary channel AI1  */
    CY_AUX_CHANNEL_TSNS     = 4UL,        /**< Auxiliary channel TSNS */
    CY_AUX_CHANNEL_VREF     = 5UL,        /**< Auxiliary channel VREF. \note Enabling VREF monitoring introduces kickback noise that can affect ADC accuracy. Set auto_trigger_sample_clck to 63 in \ref cy_stc_adc_conversion_config_t to mitigate this. */
    CY_VDDA_DIV2_DCSG_GRP0  = 6UL,        /**< VDDA Div 2 Voltage from DCSG_GRP_0   */
    CY_VDDA_DIV2_DCSG_GRP1  = 7UL,        /**< VDDA Div 2 Voltage from DCSG_GRP_1   */
} cy_en_aux_channel_t;

/** ADC DFT AUX Source Selection for SEL_SRC_N field of ADC_DFT_AUX_CNFG.
 *  Used to select the source to connect R2R_DAC output directly to AI0/AI1 pins. */
typedef enum
{
    CY_ADC_DFT_SRC_0           = 0UL,        /**< DFT Source 0 */
    CY_ADC_DFT_SRC_1           = 1UL,        /**< DFT Source 1 */
    CY_ADC_DFT_SRC_2           = 2UL,        /**< DFT Source 2 */
    CY_ADC_DFT_SRC_3           = 3UL,        /**< DFT Source 3 */
    CY_ADC_DFT_SRC_4           = 4UL,        /**< DFT Source 4 */
    CY_ADC_DFT_SRC_5           = 5UL,        /**< DFT Source 5 */
    CY_ADC_DFT_SRC_6           = 6UL,        /**< DFT Source 6 */
    CY_ADC_DFT_SRC_7           = 7UL,        /**< DFT Source 7 */
} cy_en_adc_dft_src_t;

/** ADC ALT Auxiliary Channels selection multiplexed with AI_AUX  */
typedef enum
{
    CY_ALT_AUX_AIN3N_AIN11N   = 0UL,        /**< For ADC_GRP_0, it will be AIN3N. For ADC_GRP_3, it will be AIN11N */
    CY_ALT_AUX_AI2_AI9        = 1UL,        /**< For ADC_GRP_0, it will be AI2. For ADC_GRP_3, it will be AI9      */
    CY_ALT_AUX_AI3_AI10       = 2UL,        /**< For ADC_GRP_0, it will be AI3. For ADC_GRP_3, it will be AI10     */
    CY_ALT_AUX_AI4_AI11       = 3UL,        /**< For ADC_GRP_0, it will be AI4. For ADC_GRP_3, it will be AI11     */
    CY_ALT_AUX_AI5_AI12       = 4UL,        /**< For ADC_GRP_0, it will be AI5. For ADC_GRP_3, it will be AI12     */
    CY_ALT_AUX_AI6_AI13       = 5UL,        /**< For ADC_GRP_0, it will be AI6. For ADC_GRP_3, it will be AI13     */
    CY_ALT_AUX_AI7_AI14       = 6UL,        /**< For ADC_GRP_0, it will be AI7. For ADC_GRP_3, it will be AI14     */
    CY_ALT_AUX_AI8_AI15       = 7UL,        /**< For ADC_GRP_0, it will be AI8. For ADC_GRP_3, it will be AI15     */
} cy_en_alt_aux_channel_t;

/** VSSA  */
typedef enum
{
    CY_ADC_VSSA_ADC3            = 0UL,        /**< For VSSA_ADC3          */
    CY_ADC_VSSA_DCSG_GRP0       = 1UL,        /**< For VSSA_DCSG_GRP0     */
    CY_ADC_VSSA_DCSG_GRP1       = 2UL,        /**< For VSSA_DCSG_GRP1     */
    CY_ADC_VSSA_DCSG_GRP1_SP    = 3UL,        /**< For VSSA_DCSG_GRP1_SP  */
} cy_en_adc_vssa_t;

/** Specifies the ADC7,AUX_DATA,ALT_AUX_DATA path  */
typedef enum
{
    CY_DATA_PATH_ADC7      = 0UL,        /**< ADC data path set to ADC7    */
    CY_DATA_PATH_AUX       = 2UL,        /**< ADC data path set to AUX     */
    CY_DATA_PATH_ALT_AUX   = 3UL,        /**< ADC data path set to ALT_AUX */
} cy_en_adc_data_path_t;

/** Specifies the Trigger Mode  */
typedef enum
{
    CY_ADC_MANUAL_TRIGGER      = 0UL,        /**< Manual Trigger Mode    */
    CY_ADC_AUTO_TRIGGER        = 1UL,        /**< Auto trigger Mode (Continuous Conversion)     */
    CY_ADC_ARBITRARY_TRIGGER   = 2UL,        /**< Arbitrary trigger Mode (Arbitrary Conversion - Based on the individual adc_soc_i[x]) */
} cy_en_adc_trigger_mode_t;

/** AFE GAIN Settings. */
typedef enum
{
    CY_AFE_GAIN_0       = 0UL,        /**<AFE gain Set to 0. Gain is off. */
    CY_AFE_GAIN_3       = 1UL,        /**<AFE gain of 3 is set.  */
    CY_AFE_GAIN_6       = 2UL,        /**<AFE gain of 6 is set.  */
    CY_AFE_GAIN_12      = 3UL,        /**<AFE gain of 12 is set. */
    CY_AFE_GAIN_24      = 4UL,        /**<AFE gain of 24 is set. */
} cy_en_afe_gain_t;

/** AFE Power Setting. */
typedef enum
{
    CY_AFE_PWR_HFLG       = 0UL,        /**<AFE power setting for High frequency low gain. */
    CY_AFE_PWR_HFLG_LP    = 1UL,        /**<AFE power setting for High frequency low gain, Low Power */
    CY_AFE_PWR_HFLG_ULP   = 2UL,        /**<AFE power setting for High frequency low gain, Ultra Low Power */
    CY_AFE_PWR_LFHG       = 3UL,        /**<AFE power setting for Low frequency high gain */

} cy_en_afe_power_t;

/** AFE Clock Ratio Setting. Define the ADC MSPS setup based on ATOP_CLK relationship */
typedef enum
{
    CY_AFE_CLK_RATIO_ATOPCLK_BY_4    = 0UL,        /**<AFE Clock Ratio set to ATOP_CLOCK/4  */
    CY_AFE_CLK_RATIO_ATOPCLK_BY_8    = 1UL,        /**<AFE Clock Ratio set to ATOP_CLOCK/8  */
    CY_AFE_CLK_RATIO_ATOPCLK_BY_16   = 2UL,        /**<AFE Clock Ratio set to ATOP_CLOCK/16 */
    CY_AFE_CLK_RATIO_ATOPCLK_BY_32   = 3UL,        /**<AFE Clock Ratio set to ATOP_CLOCK/32 */

} cy_en_afe_clock_ratio_t;

/** PPCA ADC Auxiliary Slot configuration structure */
typedef struct cy_stc_aux_slot_config
{
    uint8_t                 aux_ch;               /**< ADC Auxiliary Channels selection multiplexed with channel 7 P Pin. \note Channel 7 must be enabled in \ref cy_stc_ppca_adc_config_t channels (bit 7) for AUX channels to function.  */
    uint8_t                 aux_ch_gnd;           /**< ADC Auxiliary Channels selection multiplexed with channel 7 N Pin. \note Channel 7 must be enabled in \ref cy_stc_ppca_adc_config_t channels (bit 7) for AUX channels to function.  */
    uint8_t                 alt_aux_ch;           /**< ADC ALT Auxiliary Channels selection multiplexed with AI_AUX  */
    uint8_t                 alt_aux_ch_gnd;       /**< ADC ALT Auxiliary Channels GND selection multiplexed with AI_AUX  */
    cy_en_adc_vssa_t        aux_gnd_group2;       /**< AUX_GND_GRP_2  */
    cy_en_adc_vssa_t        alt_aux_gnd_group2;   /**< ALT_AUX_GND_GRP_2  */
    cy_en_adc_data_path_t   ch7_data_path;        /**< Selects the data source for channel 7: \ref CY_DATA_PATH_ADC7 for regular ADC channel 7 input, \ref CY_DATA_PATH_AUX for auxiliary channel data, or \ref CY_DATA_PATH_ALT_AUX for alternate auxiliary channel data. Channel 7 must be enabled (bit 7 in channels) regardless of the selected data path.  */
    bool                    gnd_group;            /**< When set to 0 : Bit 11:8/Bit 26:24 are used for ground. When set to 1 : Bit 13:12/Bit 28:27 are used for ground. */
}cy_stc_aux_slot_config_t;


/** PPCA ADC Conversion configuration structure */
typedef struct cy_stc_adc_conversion_config
{
    bool              group_channel;                  /**< Select between Single channel or Group of sequence of Channels to be converted at provided trigger. */
    cy_en_adc_trigger_mode_t  trigger_mode;           /**< Trigger Mode Selection \ref cy_en_adc_trigger_mode_t  */
    uint8_t           auto_trigger_sample_clck;       /**< Number of system clock cycles for sampling on top of a minimum of 4 clock cycles (0+4). This is not applicable for Arbitrary trigger mode. When AFE is used, AFE_CLOCK_RATIO will define the sample period. Range : 0 to 63. \note When VREF is included in AUX slot conversion, set this to 63 to allow sufficient VREF settling time after kickback noise. */
    uint8_t           num_of_slot;                    /**< Number of Slot to be converted for each provided trigger when Group of Channel flag is set. Do not set more than the maximum number of the NUM_CH of in the GRP ADC.   */
    bool              eos_src;                        /**< Select Source of EOS (when in Manual Trigger mode). false : Internal EOS. true : External EOS  */
    uint8_t           num_of_aux_slot;                /**< Number of AUX Slot to be converted for each provided trigger when Group of Channel flag is set */
    uint8_t           num_of_alt_aux_slot;            /**< Number of ALT AUX Slot to be converted for each provided trigger when Group of Channel flag is set */
    uint8_t           aux_slot_scan_rate;             /**< To define how many time the channel will be converted before slot switches to the next AUX Channel 0x00 = 1 time. 0x1F is 32 times */
    bool              ext_src;                        /**< EXT_SOURCE_SEL 0: not part of the AUX and ALT_AUX channel slot control. 1: part of slot control, This means EXT_SOURCE_SEL channel is configured in the ADC_CH_CNFGx  */
    uint32_t          sequence_of_channel;            /**< sequence of Channel to be converted. Sequence to be provided in hex. example: if ch2 and ch6 are enabled and 6 to be converted first then the value should be 0x26. CH1_TBC will be the default channel for AFE if AFE is enabled. */
    uint32_t          sequence_of_aux_channel;        /**< sequence of Auxiliary Channel to be converted. Sequence to be provided in hex. example: if ch3 and ch2 are enabled and 2 to be converted first then the value should be 0x32. */
    uint32_t          sequence_of_alt_aux_channel;    /**< sequence of ALT Auxiliary Channel to be converted. Sequence to be provided in hex. example: if ch0 and ch7 are enabled and 0 to be converted first then the value should be 0x70. */
}cy_stc_adc_conversion_config_t;

/** PPCA ADC configuration structure */
typedef struct cy_stc_ppca_adc_config
{
    bool              calib_gain_mode;                   /**< if enabled, IP handles calibration and gain computation. */
    bool              aux_slot;                          /**< Specifies the slot control scheme for the AUX Channel */
    bool              alt_aux_slot;                      /**< Specifies the slot control scheme for the ALT AUX Channel */
    uint16_t          channels;                          /**< Channels to be enabled. Each bit represents one channel (bit 0 = ch0, bit 1 = ch1, ... bit 7 = ch7). For ADC_GRP_0/ADC_GRP_3 up to 8 channels (bits 0–7) are available; for ADC_GRP_1/ADC_GRP_2 up to 4 channels (bits 0–3). \note Bit 7 (channel 7) must also be set when using auxiliary (AUX) or alternate auxiliary (ALT_AUX) channels, since channel 7 pin is multiplexed with the AUX input. */
    uint16_t          channel_type;                      /**< Single ended or differential channel. Each bit represent one channel  */
    uint16_t          channel_data_type;                 /**< configuration for signed or unsigned ADC channel. 0: unsigned, 1: signed. Each bit represent one channel  */
    uint16_t          aux_channel_data_type;             /**< configuration for signed or unsigned AUX ADC channel. 0: unsigned, 1: signed. Each bit represent one channel  */
    uint8_t           alt_aux_channel_data_type;         /**< configuration for signed or unsigned ALT AUX ADC channel. 0: unsigned, 1: signed. Each bit represent one channel  */
    cy_stc_aux_slot_config_t   *aux_slot_config;         /**< Aux Slot Configuration */
    cy_stc_adc_conversion_config_t adc_conv_config;      /**< ADC Conversion Configuration */
}cy_stc_ppca_adc_config_t;

/** PPCA AFE configuration structure */
typedef struct cy_stc_ppca_afe_config
{
    cy_en_afe_gain_t afe_gain;                        /**< AFE gain Setting. */
    cy_en_afe_power_t afe_pwr;                        /**< AFE Power Setting. */
    cy_en_afe_clock_ratio_t afe_clk_ratio;            /**< AFE Clock Ratio Setting. Define the ADC MSPS setup based on ATOP_CLK relationship */
}cy_stc_ppca_afe_config_t;


/** \} group_ppca_adc_data_structures */


/**
* \addtogroup group_ppca_adc_functions
* \{
*/

/******************************************************************************
* Function Name: Cy_PPCA_AFE_Init
***************************************************************************//**
*
* Initializes the Analog Front End (AFE) associated with an ADC group.
* Configures gain, power mode, and clock ratio settings. Also loads the
* required trim values from the SFLASH region.
*
* \param base The pointer to the AFE instance address.
*
* \param config The pointer to the AFE config structure \ref cy_stc_ppca_afe_config_t.
*
* \note Must be called from the Main core so that trim registers are
* configured correctly. Trim values are not loaded if called from PPCA cores.
******************************************************************************/
#if defined (COMPONENT_PPCA_DEVICE) && !defined (__ICCARM__)
void Cy_PPCA_AFE_Init(ATOPSS_AFE_TYPE *base, cy_stc_ppca_afe_config_t const *config )__attribute__((warning("Initialization of PPCA peripherals like AREF, ADC, DAC and DCSG to be done on Main core. Trim values are not configured if called on PPCA cores.")));
#else
void Cy_PPCA_AFE_Init(ATOPSS_AFE_TYPE *base, cy_stc_ppca_afe_config_t const *config );
#endif

/******************************************************************************
* Function Name: Cy_PPCA_AFE_DeInit
***************************************************************************//**
*
* De-Initializes and disables the AFE
*
* \param base The pointer to the AFE instance address.
*
******************************************************************************/
void Cy_PPCA_AFE_DeInit(ATOPSS_AFE_TYPE *base);


/******************************************************************************
* Function Name: Cy_PPCA_ADC_Init
***************************************************************************//**
*
* Initializes the SAR ADC. Configures channel selection, single-ended or
* differential mode, trigger mode, auxiliary channel routing, and conversion
* sequence. Also loads trim values from the SFLASH region.
*
* \param base The pointer to the ADC instance address.
*
* \param config The pointer to the ADC config structure \ref cy_stc_ppca_adc_config_t.
*
* \note Must be called from the Main core so that trim registers are
* configured correctly. Trim values are not loaded if called from PPCA cores.
*
* \snippet ppca/snippet/ppca_snippet.c SNIPPET_PPCA_ADC_INIT
******************************************************************************/
#if defined (COMPONENT_PPCA_DEVICE) && !defined (__ICCARM__)
void Cy_PPCA_ADC_Init(ATOPSS_ADC_TYPE *base, cy_stc_ppca_adc_config_t const *config )__attribute__((warning("Initialization of PPCA peripherals like AREF, ADC, DAC and DCSG to be done on Main core. Trim values are not configured if called on PPCA cores.")));
#else
void Cy_PPCA_ADC_Init(ATOPSS_ADC_TYPE *base, cy_stc_ppca_adc_config_t const *config );
#endif



/******************************************************************************
* Function Name: Cy_PPCA_ADC_DeInit
***************************************************************************//**
*
* De-Initializes and disables the ADC
*
* \param base The pointer to the ADC instance address.
*
******************************************************************************/
void Cy_PPCA_ADC_DeInit(ATOPSS_ADC_TYPE *base);

/******************************************************************************
* Function Name: Cy_PPCA_ADC_Enable
***************************************************************************//**
*
* Enables the ADC
*
* \param base The pointer to the ADC instance address.
*
* \note The Analog Front End (AFE) must be enabled (Cy_PPCA_AFE_Enable)
* before the ADC. Otherwise ADC_BUSY never clears and conversions never
* complete. See the ADC driver overview for the full power-up sequence.
*
******************************************************************************/
__STATIC_INLINE void Cy_PPCA_ADC_Enable(ATOPSS_ADC_TYPE *base)
{
    CY_ASSERT_L1(NULL != base);
    PPCA_ATOP_ADC_CTRL(base) |= PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CTL_ADC_EN_Msk;
}

/******************************************************************************
* Function Name: Cy_PPCA_ADC_Disable
***************************************************************************//**
*
* Disables the ADC
*
* \param base The pointer to the ADC instance address.
*
******************************************************************************/
__STATIC_INLINE void Cy_PPCA_ADC_Disable(ATOPSS_ADC_TYPE *base)
{
    CY_ASSERT_L1(NULL != base);
    PPCA_ATOP_ADC_CTRL(base) &= (uint32_t) ~PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CTL_ADC_EN_Msk;
}

/******************************************************************************
* Function Name: Cy_PPCA_AFE_Enable
***************************************************************************//**
*
* Enables the AFE
*
* \param base The pointer to the AFE instance address.
*
******************************************************************************/
__STATIC_INLINE void Cy_PPCA_AFE_Enable(ATOPSS_AFE_TYPE *base)
{
    CY_ASSERT_L1(NULL != base);
    PPCA_ATOP_AFE_CTL(base) |= PPCA_ATOPSS_ADC_GRP_SLICE_AFE_AFE_CTL_AFE_EN_0_Msk;
}

/******************************************************************************
* Function Name: Cy_PPCA_AFE_Disable
***************************************************************************//**
*
* Disables the AFE
*
* \param base The pointer to the AFE instance address.
*
******************************************************************************/
__STATIC_INLINE void Cy_PPCA_AFE_Disable(ATOPSS_AFE_TYPE *base)
{
    CY_ASSERT_L1(NULL != base);
    PPCA_ATOP_AFE_CTL(base) &= (uint32_t) ~PPCA_ATOPSS_ADC_GRP_SLICE_AFE_AFE_CTL_AFE_EN_0_Msk;
}


/******************************************************************************
* Function Name: Cy_PPCA_ADC_Is_ADC_Busy
***************************************************************************//**
*
* Returns the status of the ADC
*
* \param base The pointer to the ADC instance address.
*
* \return returns if ADC is busy or not.
*
******************************************************************************/
__STATIC_INLINE bool Cy_PPCA_ADC_Is_ADC_Busy(ATOPSS_ADC_TYPE *base)
{
    return (bool)_FLD2VAL(PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CTL_ADC_BUSY, PPCA_ATOP_ADC_CTRL(base));
}

/******************************************************************************
* Function Name: Cy_PPCA_ADC_Set_Calib_Gain_mode
***************************************************************************//**
*
* Selects who computes/applies the ADC's Gain Correction stage (see the
* ADC output data path note in the module Overview section):
* - gain_mode = true:  the IP automatically computes and applies gain
*   correction internally; no firmware action is required for gain.
* - gain_mode = false: gain (and offset) values are instead sourced from
*   whichever block is active for this group - the AFE (if enabled, see
*   Cy_PPCA_AFE_Init() / AFE_CNFG.AFE_GAIN_SET, readable via
*   \ref Cy_PPCA_ADC_Get_Gain_Setting) or the ADC's own static configuration.
*
* \param base The pointer to the ADC instance address.
*
* \param gain_mode true = IP auto-calibration, false = AFE/ADC static gain
* (see \ref Cy_PPCA_ADC_Get_Gain_Setting to read back the resulting gain
* preset when gain_mode is false and the AFE is in use).
*
******************************************************************************/
__STATIC_INLINE void Cy_PPCA_ADC_Set_Calib_Gain_mode(ATOPSS_ADC_TYPE *base, bool gain_mode)
{
    CY_ASSERT_L1(NULL != base);
    if(gain_mode)
    {
        PPCA_ATOP_ADC_CTRL(base) |= PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CTL_CALIB_GAIN_MODE_Msk;
    }
    else
    {
        PPCA_ATOP_ADC_CTRL(base) &= (uint32_t) ~(PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CTL_CALIB_GAIN_MODE_Msk);
    }
}

/******************************************************************************
* Function Name: Cy_PPCA_ADC_Get_Gain_Setting
***************************************************************************//**
*
* Returns the AFE gain preset currently applied to the Gain Correction stage
* of the ADC output data path (see the module Overview section), as
* configured via cy_stc_ppca_afe_config_t.afe_gain during Cy_PPCA_AFE_Init().
*
* \param base The pointer to the ADC instance address.
*
* \return the gain preset value (0-7); see AFE_GAIN_SET / cy_en_afe_gain_t
* encoding in the driver/TRM for the corresponding gain multiplier.
*
* \note This reflects a discrete preset selection (AFE_CNFG.AFE_GAIN_SET),
* not a continuous/arbitrary calibration value. There is no dedicated
* runtime "Set" API distinct from Cy_PPCA_AFE_Init() at this time.
*
******************************************************************************/
__STATIC_INLINE uint8_t Cy_PPCA_ADC_Get_Gain_Setting(ATOPSS_ADC_TYPE *base)
{
    CY_ASSERT_L1(NULL != base);
    return (uint8_t)_FLD2VAL(PPCA_ATOPSS_ADC_GRP_SLICE_AFE_AFE_CNFG_AFE_GAIN_SET, PPCA_ATOP_AFE_CNFG(base));
}

/******************************************************************************
* Function Name: Cy_PPCA_ADC_Set_Test_mode
***************************************************************************//**
*
* If enabled, IP runs in test mode. The value written via
* \ref Cy_PPCA_ADC_Write_Test_data is substituted for the real ADC conversion
* result and appears in ADC_DATA[ch_num], readable via
* \ref Cy_PPCA_ADC_Read_ADC_Data, after a triggered conversion.
*
* \note For the injected value to appear in ADC_DATA[ch_num] all of the
* following prerequisites must be met, in order:
* 1. \ref Cy_PPCA_ADC_Init must have been called with the channel-conversion
*    sequence fully configured (ADC_CNV_CNFG, ADC_CH_CNFG0/1). Without this
*    a trigger does not convert the channel and ADC_DATA[ch_num] stays 0.
* 2. \ref Cy_PPCA_ADC_Set_Calib_Gain_mode(false) must be called so the
*    injected value is not rescaled by the calibration gain stage.
* 3. \ref Cy_PPCA_ADC_Write_Test_data must be called to load the test value.
* 4. A trigger must be issued via \ref Cy_PPCA_ADC_Trigger to clock the
*    injected value into ADC_DATA[ch_num].
*
* \param base The pointer to the ADC instance address.
*
* \param test_mode enable/disable test mode.
*
******************************************************************************/
__STATIC_INLINE void Cy_PPCA_ADC_Set_Test_mode(ATOPSS_ADC_TYPE *base, bool test_mode)
{
    CY_ASSERT_L1(NULL != base);
    if(test_mode)
    {
        PPCA_ATOP_ADC_CTRL(base) |= PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CTL_ADC_TEST_DATA_SEL_Msk;
    }
    else
    {
        PPCA_ATOP_ADC_CTRL(base) &= (uint32_t) ~(PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CTL_ADC_TEST_DATA_SEL_Msk);
    }
}

/******************************************************************************
* Function Name: Cy_PPCA_ADC_Is_Test_Mode_Enabled
***************************************************************************//**
*
* Reports whether the ADC is currently in test mode, i.e. whether the value
* written via Cy_PPCA_ADC_Write_Test_data is being substituted for the real
* conversion result (see Cy_PPCA_ADC_Set_Test_mode).
*
* \param base The pointer to the ADC instance address.
*
* \return true if test mode is enabled, false if the ADC is in normal
* (real conversion) mode.
*
******************************************************************************/
__STATIC_INLINE bool Cy_PPCA_ADC_Is_Test_Mode_Enabled(ATOPSS_ADC_TYPE *base)
{
    CY_ASSERT_L1(NULL != base);
    return (bool)_FLD2VAL(PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CTL_ADC_TEST_DATA_SEL, PPCA_ATOP_ADC_CTRL(base));
}

/******************************************************************************
* Function Name: Cy_PPCA_ADC_Write_Test_data
***************************************************************************//**
*
* Sets Test data. This data will be copied to ADC_DATA[ch_num], readable via
* \ref Cy_PPCA_ADC_Read_ADC_Data, on the next triggered conversion.
* \ref Cy_PPCA_ADC_Set_Test_mode must be enabled for this to take effect.
*
* \note This is a single, group-wide test-data register (not per-channel).
* The value written here is substituted directly at the ADC_IP conversion
* result stage, ahead of Gain Correction and Offset Correction (see the
* ADC output data path note in the module Overview section) - it is not
* possible to inject test data after those correction stages. Use
* \ref Cy_PPCA_ADC_Is_Channel_Signed to determine, ahead of time, how the
* channel you are testing will interpret/present the resulting value.
*
* \note Full downstream path for DICO self-test: injected value →
* ADC_DATA[ch] (after trigger) → ADC Group 0 analog filter chain (AFLT[0])
* → \ref CY_ADC_GROUP_0_FILT_OUT0 → DICO IL input (SEL_IL0 in DICO_CNFG).
* For DICO ilAccu to advance from this injected value, active PCO switching
* is additionally required (see \ref Cy_PPCA_CLB_DICO_Enable note on
* bare-board behaviour).
*
* \param base The pointer to the ADC instance address.
*
* \param test_data 12 bit test data.
*
******************************************************************************/
__STATIC_INLINE void Cy_PPCA_ADC_Write_Test_data(ATOPSS_ADC_TYPE *base, uint32_t test_data)
{
    CY_ASSERT_L1(NULL != base);
    CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 11.3','Intentional pointer type conversion to access DATA_TEST_OFFSET');
    CY_SET_REG32(((uint8_t *)base + PPCA_ATOP_ADC_DATA_TEST_OFFSET), test_data);
}

/******************************************************************************
* Function Name: Cy_PPCA_ADC_Is_Channel_Signed
***************************************************************************//**
*
* Reports whether the given main ADC channel is currently configured as signed
* or unsigned, as selected by the ADC_SIGN_UNSIGN_CNFG bitmask (see the ADC
* output data path note in the module Overview section). This mirrors the
* channel_data_type setting applied via cy_stc_ppca_adc_config_t at
* Cy_PPCA_ADC_Init() time, read back directly from hardware.
*
* \note This function covers main ADC channels only. For AUX and ALT_AUX
* channels (which have their own independent AUX_SIGN_UNSIGN_CNFG /
* AUX_AL_SIGN_UNSIGN_CNFG registers) use \ref Cy_PPCA_ADC_Is_Aux_Channel_Signed
* and \ref Cy_PPCA_ADC_Is_Alt_Aux_Channel_Signed instead.
*
* \param base The pointer to the ADC instance address.
*
* \param ch_num ADC channel number to query.
*
* \return true if the channel is configured as signed, false if unsigned.
*
******************************************************************************/
__STATIC_INLINE bool Cy_PPCA_ADC_Is_Channel_Signed(ATOPSS_ADC_TYPE *base, uint8_t ch_num)
{
    CY_ASSERT_L1(NULL != base);
    return (bool)((PPCA_ATOP_ADC_SIGN_UNSIGN_CNFG(base) >> ch_num) & 0x1U);
}

/******************************************************************************
* Function Name: Cy_PPCA_ADC_Is_Aux_Channel_Signed
***************************************************************************//**
*
* Reports whether the given AUX ADC channel is currently configured as signed
* or unsigned, as selected by the AUX_SIGN_UNSIGN_CNFG bitmask (see the ADC
* output data path note in the module Overview section). This mirrors the
* aux_channel_data_type setting applied via cy_stc_ppca_adc_config_t at
* Cy_PPCA_ADC_Init() time, read back directly from hardware.
*
* \param base The pointer to the ADC instance address.
*
* \param ch_num AUX ADC channel number to query.
*
* \return true if the AUX channel is configured as signed, false if unsigned.
*
******************************************************************************/
__STATIC_INLINE bool Cy_PPCA_ADC_Is_Aux_Channel_Signed(ATOPSS_ADC_TYPE *base, uint8_t ch_num)
{
    CY_ASSERT_L1(NULL != base);
    return (bool)((PPCA_ATOP_ADC_AUX_SIGN_UNSIGN_CNFG(base) >> ch_num) & 0x1U);
}

/******************************************************************************
* Function Name: Cy_PPCA_ADC_Is_Alt_Aux_Channel_Signed
***************************************************************************//**
*
* Reports whether the given ALT_AUX ADC channel is currently configured as
* signed or unsigned, as selected by the AUX_AL_SIGN_UNSIGN_CNFG bitmask (see
* the ADC output data path note in the module Overview section). This mirrors
* the alt_aux_channel_data_type setting applied via cy_stc_ppca_adc_config_t
* at Cy_PPCA_ADC_Init() time, read back directly from hardware.
*
* \param base The pointer to the ADC instance address.
*
* \param ch_num ALT_AUX ADC channel number to query.
*
* \return true if the ALT_AUX channel is configured as signed, false if unsigned.
*
******************************************************************************/
__STATIC_INLINE bool Cy_PPCA_ADC_Is_Alt_Aux_Channel_Signed(ATOPSS_ADC_TYPE *base, uint8_t ch_num)
{
    CY_ASSERT_L1(NULL != base);
    return (bool)((PPCA_ATOP_ADC_AUX_ALT_SIGN_UNSIGN_CNFG(base) >> ch_num) & 0x1U);
}

/******************************************************************************
* Function Name: Cy_PPCA_ADC_Set_Gain_Correction
***************************************************************************//**
*
* Sets the per-channel Gain Correction value applied to the ADC conversion
* result (ADC_CALGAIN), for either the single-ended or the differential path
* of the given channel. See the ADC output data path note in the module
* Overview section for where Gain Correction sits in the data pipeline.
*
* \param base The pointer to the ADC instance address.
*
* \param ch_num ADC channel number (0-15) to configure.
*
* \param mode Selects which field to write: \ref CY_ADC_SINGLE_ENDED_CHANNEL
* or \ref CY_ADC_DIFFERENTIAL_CHANNEL.
*
* \param gain_value Gain correction value to apply (11-bit, 0-0x7FF).
*
******************************************************************************/
__STATIC_INLINE void Cy_PPCA_ADC_Set_Gain_Correction(ATOPSS_ADC_TYPE *base, uint8_t ch_num, uint8_t mode, uint16_t gain_value)
{
    CY_ASSERT_L1(NULL != base);
    if (CY_ADC_DIFFERENTIAL_CHANNEL == mode)
    {
        PPCA_ATOP_ADC_CALGAIN(base, ch_num) = (PPCA_ATOP_ADC_CALGAIN(base, ch_num) & (uint32_t)~PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CALGAIN_GAINX1_DIFF_MODE_Msk) |
                                               _VAL2FLD(PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CALGAIN_GAINX1_DIFF_MODE, gain_value);
    }
    else
    {
        PPCA_ATOP_ADC_CALGAIN(base, ch_num) = (PPCA_ATOP_ADC_CALGAIN(base, ch_num) & (uint32_t)~PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CALGAIN_GAINX1_SE_MODE_Msk) |
                                               _VAL2FLD(PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CALGAIN_GAINX1_SE_MODE, gain_value);
    }
}

/******************************************************************************
* Function Name: Cy_PPCA_ADC_Get_Gain_Correction
***************************************************************************//**
*
* Gets the per-channel Gain Correction value currently applied to the ADC
* conversion result (ADC_CALGAIN), for either the single-ended or the
* differential path of the given channel.
*
* \param base The pointer to the ADC instance address.
*
* \param ch_num ADC channel number (0-15) to query.
*
* \param mode Selects which field to read: \ref CY_ADC_SINGLE_ENDED_CHANNEL
* or \ref CY_ADC_DIFFERENTIAL_CHANNEL.
*
* \return The configured gain correction value (11-bit, 0-0x7FF).
*
******************************************************************************/
__STATIC_INLINE uint16_t Cy_PPCA_ADC_Get_Gain_Correction(ATOPSS_ADC_TYPE *base, uint8_t ch_num, uint8_t mode)
{
    uint16_t result;
    CY_ASSERT_L1(NULL != base);
    if (CY_ADC_DIFFERENTIAL_CHANNEL == mode)
    {
        result = (uint16_t)_FLD2VAL(PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CALGAIN_GAINX1_DIFF_MODE, PPCA_ATOP_ADC_CALGAIN(base, ch_num));
    }
    else
    {
        result = (uint16_t)_FLD2VAL(PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CALGAIN_GAINX1_SE_MODE, PPCA_ATOP_ADC_CALGAIN(base, ch_num));
    }
    return result;
}

/******************************************************************************
* Function Name: Cy_PPCA_ADC_Set_Offset
***************************************************************************//**
*
* Sets the per-channel Offset Correction value applied to the ADC conversion
* result (ADC_CALOFFSET), for either the single-ended or the differential
* path of the given channel. See the ADC output data path note in the module
* Overview section for where Offset Correction sits in the data pipeline.
*
* \param base The pointer to the ADC instance address.
*
* \param ch_num ADC channel number (0-15) to configure.
*
* \param mode Selects which field to write: \ref CY_ADC_SINGLE_ENDED_CHANNEL
* or \ref CY_ADC_DIFFERENTIAL_CHANNEL.
*
* \param offset_value Offset correction value to apply (8-bit, 0-0xFF).
*
******************************************************************************/
__STATIC_INLINE void Cy_PPCA_ADC_Set_Offset(ATOPSS_ADC_TYPE *base, uint8_t ch_num, uint8_t mode, uint8_t offset_value)
{
    CY_ASSERT_L1(NULL != base);
    if (CY_ADC_DIFFERENTIAL_CHANNEL == mode)
    {
        PPCA_ATOP_ADC_CALOFFSET(base, ch_num) = (PPCA_ATOP_ADC_CALOFFSET(base, ch_num) & (uint32_t)~PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CALOFFSET_OFFSET_DIFF_Msk) |
                                                 _VAL2FLD(PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CALOFFSET_OFFSET_DIFF, offset_value);
    }
    else
    {
        PPCA_ATOP_ADC_CALOFFSET(base, ch_num) = (PPCA_ATOP_ADC_CALOFFSET(base, ch_num) & (uint32_t)~PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CALOFFSET_OFFSET_SE_Msk) |
                                                 _VAL2FLD(PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CALOFFSET_OFFSET_SE, offset_value);
    }
}

/******************************************************************************
* Function Name: Cy_PPCA_ADC_Get_Offset
***************************************************************************//**
*
* Gets the per-channel Offset Correction value currently applied to the ADC
* conversion result (ADC_CALOFFSET), for either the single-ended or the
* differential path of the given channel.
*
* \param base The pointer to the ADC instance address.
*
* \param ch_num ADC channel number (0-15) to query.
*
* \param mode Selects which field to read: \ref CY_ADC_SINGLE_ENDED_CHANNEL
* or \ref CY_ADC_DIFFERENTIAL_CHANNEL.
*
* \return The configured offset correction value (8-bit, 0-0xFF).
*
******************************************************************************/
__STATIC_INLINE uint8_t Cy_PPCA_ADC_Get_Offset(ATOPSS_ADC_TYPE *base, uint8_t ch_num, uint8_t mode)
{
    uint8_t result;
    CY_ASSERT_L1(NULL != base);
    if (CY_ADC_DIFFERENTIAL_CHANNEL == mode)
    {
        result = (uint8_t)_FLD2VAL(PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CALOFFSET_OFFSET_DIFF, PPCA_ATOP_ADC_CALOFFSET(base, ch_num));
    }
    else
    {
        result = (uint8_t)_FLD2VAL(PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CALOFFSET_OFFSET_SE, PPCA_ATOP_ADC_CALOFFSET(base, ch_num));
    }
    return result;
}

/******************************************************************************
* Function Name: Cy_PPCA_ADC_Set_Trigger_mode
***************************************************************************//**
*
* Sets ADC trigger mode.
* For arbitrary mode, the TRIGGER signal comes from SOC signal (external signal) or by Cy_PPCA_ADC_Trigger call.
* For auto mode, the trigger signal comes from Cy_PPCA_ADC_Trigger call. In the auto trigger mode, the first trigger occurrence will start the auto trigger sequence.
* In the manual trigger mode, Cy_PPCA_ADC_Trigger call will start the programmed conversion sequence and then it waits for the next trigger.
*
* \param base The pointer to the ADC instance address.
*
* \param trigger_mode Trigger mode selection.
*
******************************************************************************/
__STATIC_INLINE void Cy_PPCA_ADC_Set_Trigger_mode(ATOPSS_ADC_TYPE *base, cy_en_adc_trigger_mode_t trigger_mode)
{
    CY_ASSERT_L1(NULL != base);
    PPCA_ATOP_ADC_CNV_CNFG(base) &= (uint32_t) ~(PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CNV_CNFG_TRIGGER_MODE_Msk);
    PPCA_ATOP_ADC_CNV_CNFG(base) |= _VAL2FLD(PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_CNV_CNFG_TRIGGER_MODE, trigger_mode);
}

/******************************************************************************
* Function Name: Cy_PPCA_ADC_Trigger
***************************************************************************//**
*
* Software trigger or Manual trigger for ADC 
* In arbitrary mode, This will start conversion.
* In auto mode, this trigger occurrence will start the auto trigger sequence. and conversion will continue until trigger mode is set to Manual trigger mode.
* In the manual trigger mode, this call will start the conversion sequence and then it waits for the next trigger to start next conversion sequence.
*
* \param base The pointer to the ADC instance address.
*
* \param trigger Trigger a channel. Each bit represent one channel.
*
******************************************************************************/
__STATIC_INLINE void Cy_PPCA_ADC_Trigger(ATOPSS_ADC_TYPE *base, uint16_t trigger)
{
    CY_ASSERT_L1(NULL != base);
    PPCA_ATOP_ADC_TRIGGER(base) = (uint16_t)trigger;
}

/******************************************************************************
* Function Name: Cy_PPCA_ADC_Read_ADC_Data
***************************************************************************//**
*
* Returns 12 bit ADC Data for that particular channel
*
* \param base The pointer to the ADC instance address.
*
* \param ch_num Channel number for which ADC data to be read.
*
* \return returns ADC data.
*
******************************************************************************/
__STATIC_INLINE uint16_t Cy_PPCA_ADC_Read_ADC_Data(ATOPSS_ADC_TYPE *base, uint8_t ch_num)
{
    CY_ASSERT(CY_ADC_CHANNEL(ch_num));
    return (uint16_t)_FLD2VAL(PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_DATA_ADC_DATA, PPCA_ATOP_ADC_DATA(base, ch_num));
}

/******************************************************************************
* Function Name: Cy_PPCA_ADC_Read_SignExtended_ADC_Data
***************************************************************************//**
*
* Returns the Sign extended ADC Data for that particular channel.
* When ADC data is negative in the sign configuration, 13 to 31 bits will be 1.
* When ADC data is positive in the sign configuration or unsigned configuration, 13 to 31 bits will be 0.
*
* \param base The pointer to the ADC instance address.
*
* \param ch_num Channel number for which ADC data to be read.
*
* \return returns ADC data.
*
******************************************************************************/
__STATIC_INLINE uint32_t Cy_PPCA_ADC_Read_SignExtended_ADC_Data(ATOPSS_ADC_TYPE *base, uint8_t ch_num)
{
    CY_ASSERT(CY_ADC_CHANNEL(ch_num));
    return PPCA_ATOP_ADC_DATA(base, ch_num);
}

/******************************************************************************
* Function Name: Cy_PPCA_ADC_Read_AUX_ADC_Data
***************************************************************************//**
*
* Returns 12 bit AUX ADC Data for that particular channel
*
* \param base The pointer to the ADC instance address.
*
* \param ch_num Channel number for which AUX ADC data to be read. \ref cy_en_aux_channel_t
*
* \return returns ADC data.
*
******************************************************************************/
__STATIC_INLINE uint16_t Cy_PPCA_ADC_Read_AUX_ADC_Data(ATOPSS_ADC_TYPE *base, cy_en_aux_channel_t ch_num)
{
    CY_ASSERT(CY_ADC_AUX_CHANNEL(ch_num));
    return (uint16_t)_FLD2VAL(PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_AUX_DATA_ADC_AUX_DATA, PPCA_ATOP_ADC_AUX_DATA(base, ch_num));
}

/******************************************************************************
* Function Name: Cy_PPCA_ADC_Read_SignExtended_AUX_ADC_Data
***************************************************************************//**
*
* Returns the Sign extended AUX ADC Data for that particular channel.
* When ADC data is negative in the sign configuration, 13 to 31 bits will be 1.
* When ADC data is positive in the sign configuration or unsigned configuration, 13 to 31 bits will be 0.
*
* \param base The pointer to the ADC instance address.
*
* \param ch_num Channel number for which AUX ADC data to be read. \ref cy_en_aux_channel_t
*
* \return returns ADC data.
*
******************************************************************************/
__STATIC_INLINE uint32_t Cy_PPCA_ADC_Read_SignExtended_AUX_ADC_Data(ATOPSS_ADC_TYPE *base, cy_en_aux_channel_t ch_num)
{
    CY_ASSERT(CY_ADC_AUX_CHANNEL(ch_num));
    return PPCA_ATOP_ADC_AUX_DATA(base, ch_num);
}

/******************************************************************************
* Function Name: Cy_PPCA_ADC_Read_ALT_AUX_ADC_Data
***************************************************************************//**
*
* Returns 12 bit ALT AUX ADC Data for that particular channel
*
* \param base The pointer to the ADC instance address.
*
* \param ch_num Channel number for which ALT AUX ADC data to be read. \ref cy_en_alt_aux_channel_t
*
* \return returns ADC data.
*
******************************************************************************/
__STATIC_INLINE uint16_t Cy_PPCA_ADC_Read_ALT_AUX_ADC_Data(ATOPSS_ADC_TYPE *base, cy_en_alt_aux_channel_t ch_num)
{
    CY_ASSERT(CY_ADC_ALT_AUX_CHANNEL(ch_num));
    return (uint16_t)_FLD2VAL(PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_AUX_DATA_ADC_AUX_DATA, PPCA_ATOP_ADC_ALT_AUX_DATA(base, ch_num));
}

/******************************************************************************
* Function Name: Cy_PPCA_ADC_Read_SignExtended_ALT_AUX_ADC_Data
***************************************************************************//**
*
* Returns the Sign extended ALT AUX ADC Data for that particular channel.
* When ADC data is negative in the sign configuration, 13 to 31 bits will be 1.
* When ADC data is positive in the sign configuration or unsigned configuration, 13 to 31 bits will be 0.
*
* \param base The pointer to the ADC instance address.
*
* \param ch_num Channel number for which ALT AUX ADC data to be read. \ref cy_en_alt_aux_channel_t
*
* \return returns ADC data.
*
******************************************************************************/
__STATIC_INLINE uint32_t Cy_PPCA_ADC_Read_SignExtended_ALT_AUX_ADC_Data(ATOPSS_ADC_TYPE *base, cy_en_alt_aux_channel_t ch_num)
{
    CY_ASSERT(CY_ADC_ALT_AUX_CHANNEL(ch_num));
    return PPCA_ATOP_ADC_ALT_AUX_DATA(base, ch_num);
}

/******************************************************************************
* Function Name: Cy_PPCA_ADC_Read_ADC_Mirror_Data
***************************************************************************//**
*
* Reads the ADC Mirrored Result Data. The ADC_MIRROR peripheral mirrors ADC
* conversion results for all channels.
*
* \param base The pointer to the ADC Mirror peripheral instance address.
*
* \param index Index to the ADC Mirror Data (0-47). One ADC Data per channel.
*
* \return The ADC Mirror data for the specified channel index.
*
******************************************************************************/
__STATIC_INLINE uint32_t Cy_PPCA_ADC_Read_ADC_Mirror_Data(ADCM_TYPE *base, uint32_t index)
{
    CY_ASSERT_L1(NULL != base);
    CY_ASSERT(index < CY_ADC_MIRROR_MAX_INDEX);
    return PPCA_ADCM_DATA(base, index);
}

/******************************************************************************
* Function Name: Cy_PPCA_ADC_Set_Channel_Sampling_Mask
***************************************************************************//**
*
* Sets ADC Channel sampling Mask. Each bit represent one channel.
* When the bit is set, It Mask's that particular Channel Sampling.
*
* \param base The pointer to the ADC instance address.
*
* \param ch_mask ADC Channel sampling Mask. Each bit represent one channel.
*
******************************************************************************/
__STATIC_INLINE void Cy_PPCA_ADC_Set_Channel_Sampling_Mask(ATOPSS_ADC_TYPE *base, uint16_t ch_mask)
{
    CY_ASSERT_L1(NULL != base);
    PPCA_ATOP_ADC_SAMPLING_MASK(base) = ch_mask;
}

/******************************************************************************
* Function Name: Cy_PPCA_ADC_Get_Channel_Sampling_Mask
***************************************************************************//**
*
* Sets ADC Channel sampling Mask. Each bit represent one channel.
* When the bit is set, It Mask's that particular Channel Sampling.
*
* \param base The pointer to the ADC instance address.
*
* \return returns ADC Channel sampling Mask. Each bit represent one channel.
*
******************************************************************************/
__STATIC_INLINE uint16_t Cy_PPCA_ADC_Get_Channel_Sampling_Mask(ATOPSS_ADC_TYPE *base)
{
    return (uint16_t)(PPCA_ATOP_ADC_SAMPLING_MASK(base));
}

/** ------ Interrupts    ------- */

/******************************************************************************
* Function Name: Cy_PPCA_ADC_GetInterruptStatus
***************************************************************************//**
*
* Reports the status of the interrupts
*
* \param base The pointer to the ADC instance address.
*
* \return returns the Status of the interrupts
*
******************************************************************************/
__STATIC_INLINE uint32_t Cy_PPCA_ADC_GetInterruptStatus(ATOPSS_ADC_TYPE *base)
{
    return PPCA_ATOP_ADC_INTR(base);
}

/******************************************************************************
* Function Name: Cy_PPCA_ADC_ClearInterrupt
***************************************************************************//**
*
* Clears the triggered interrupts
*
* \param base The pointer to the ADC instance address.
*
******************************************************************************/
__STATIC_INLINE void Cy_PPCA_ADC_ClearInterrupt(ATOPSS_ADC_TYPE *base)
{
    CY_ASSERT_L1(NULL != base);
    PPCA_ATOP_ADC_INTR(base) = 1u;
}

/******************************************************************************
* Function Name: Cy_PPCA_ADC_SetInterrupt
***************************************************************************//**
*
* Software option to set the required interrupts. Interrupt handler will be called. 
*
* \param base The pointer to the ADC instance address.
*
******************************************************************************/
__STATIC_INLINE void Cy_PPCA_ADC_SetInterrupt(ATOPSS_ADC_TYPE *base)
{
    CY_ASSERT_L1(NULL != base);
    PPCA_ATOP_ADC_INTR_SET(base) = 1u;
}

/******************************************************************************
* Function Name: Cy_PPCA_ADC_SetInterruptMask
***************************************************************************//**
*
* Sets one or more ADC module interrupt factor bits (sets the INTR_MASK register).
*
* \param base The pointer to the ADC instance address.
*
******************************************************************************/
__STATIC_INLINE void Cy_PPCA_ADC_SetInterruptMask(ATOPSS_ADC_TYPE *base)
{
    CY_ASSERT_L1(NULL != base);
    PPCA_ATOP_ADC_INTR_MASK(base) = 1u;
}


/******************************************************************************
* Function Name: Cy_PPCA_ADC_GetInterruptMask
***************************************************************************//**
*
* Reports the interrupt mask set
*
* \param base The pointer to the ADC instance address.
*
* \return returns the interrupt mask set
*
******************************************************************************/
__STATIC_INLINE uint32_t Cy_PPCA_ADC_GetInterruptMask(ATOPSS_ADC_TYPE *base)
{
    return PPCA_ATOP_ADC_INTR_MASK(base);
}

#if defined (LOAD_PPCA_TRIMS) || defined(CY_DOXYGEN)

/*******************************************************************************
* Function Name: Cy_PPCA_ADC_TEMP_Calc
****************************************************************************//**
*
* Calculates the temperature based on ADC reading results of
* temperature sensor.
* See the device Architecture Technical Reference Manual for more detail.
*
* \param adcOut ADC reading when the selected temp sensor is
* biased with a additional 1.0uA current.
*
* \note should be called from Main core only.
*
* \return
* Temperature value.
*
*
*******************************************************************************/
__STATIC_INLINE float Cy_PPCA_ADC_TEMP_Calc(int16_t adcOut)
{
    CY_ASSERT_L1(CY_PPCA_ADC_TEMP_VALID(adcOut));

    int16_t coeff_A = (int16_t)(SFLASH_SAR_TEMP_COEF_A);
    int16_t coeff_B = (int16_t)(SFLASH_SAR_TEMP_COEF_B);

    int32_t tempCalc = (((int32_t)adcOut * (int32_t)coeff_A) + ((int32_t)coeff_B*CY_PPCA_TWO_TOPOWEROF_TEN));

    float t_initial = ((float)(tempCalc)/(float)CY_PPCA_TWO_TOPOWEROF_SIXTEEN);
    float t_adjust;

    if(t_initial >= CY_PPCA_XC)
    {
        t_adjust = ((CY_PPCA_YC/(CY_PPCA_SAR_100C - CY_PPCA_XC)) * (CY_PPCA_SAR_100C - t_initial));
    }
    else
    {
        t_adjust = ((CY_PPCA_YC/(CY_PPCA_SAR_40C + CY_PPCA_XC)) * (CY_PPCA_SAR_40C + t_initial));
    }

    return (t_initial + t_adjust);

}

#endif /* defined (LOAD_PPCA_TRIMS) */


/******************************************************************************
* Function Name: Cy_PPCA_ADC_DftAuxCnfg_Enable
***************************************************************************//**
*
* Enables the ADFT path in the ADC_DFT_AUX_CNFG register.
* This allows connecting the R2R_DAC output directly to the AI0 and AI1 pins
* without using the buffer.
*
* \param base The pointer to the ADC instance address.
*
******************************************************************************/
__STATIC_INLINE void Cy_PPCA_ADC_DftAuxCnfg_Enable(ATOPSS_ADC_TYPE *base)
{
    CY_ASSERT_L1(NULL != base);
    PPCA_ATOP_ADC_DFT_AUX_CNFG(base) |= PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_DFT_AUX_CNFG_ADFT_EN_Msk;
}

/******************************************************************************
* Function Name: Cy_PPCA_ADC_DftAuxCnfg_Disable
***************************************************************************//**
*
* Disables the ADFT path in the ADC_DFT_AUX_CNFG register.
*
* \param base The pointer to the ADC instance address.
*
******************************************************************************/
__STATIC_INLINE void Cy_PPCA_ADC_DftAuxCnfg_Disable(ATOPSS_ADC_TYPE *base)
{
    CY_ASSERT_L1(NULL != base);
    PPCA_ATOP_ADC_DFT_AUX_CNFG(base) &= (uint32_t) ~PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_DFT_AUX_CNFG_ADFT_EN_Msk;
}

/******************************************************************************
* Function Name: Cy_PPCA_ADC_DftAuxCnfg_SetSrcN
***************************************************************************//**
*
* Selects the source N in the ADC_DFT_AUX_CNFG register.
*
* \param base The pointer to the ADC instance address.
*
* \param src Source selection value \ref cy_en_adc_dft_src_t.
*
******************************************************************************/
__STATIC_INLINE void Cy_PPCA_ADC_DftAuxCnfg_SetSrcN(ATOPSS_ADC_TYPE *base, cy_en_adc_dft_src_t src)
{
    CY_ASSERT_L1(NULL != base);
    PPCA_ATOP_ADC_DFT_AUX_CNFG(base) = (PPCA_ATOP_ADC_DFT_AUX_CNFG(base) &
                                         (uint32_t) ~PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_DFT_AUX_CNFG_SEL_SRC_N_Msk) |
                                         _VAL2FLD(PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_DFT_AUX_CNFG_SEL_SRC_N, src);
}

/******************************************************************************
* Function Name: Cy_PPCA_ADC_DftAuxCnfg_GetSrcN
***************************************************************************//**
*
* Returns the current source N selection from the ADC_DFT_AUX_CNFG register.
*
* \param base The pointer to the ADC instance address.
*
* \return Current source selection value.
*
******************************************************************************/
__STATIC_INLINE uint32_t Cy_PPCA_ADC_DftAuxCnfg_GetSrcN(ATOPSS_ADC_TYPE *base)
{
    CY_ASSERT_L1(NULL != base);
    return _FLD2VAL(PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_DFT_AUX_CNFG_SEL_SRC_N, PPCA_ATOP_ADC_DFT_AUX_CNFG(base));
}

/******************************************************************************
* Function Name: Cy_PPCA_ADC_DftAuxCnfg_EnableMuxToPin
***************************************************************************//**
*
* Enables the ADC MUX to Pin connection in the ADC_DFT_AUX_CNFG register.
* This routes the R2R_DAC output through the ADC mux to the external AI0/AI1 pins.
*
* \param base The pointer to the ADC instance address.
*
******************************************************************************/
__STATIC_INLINE void Cy_PPCA_ADC_DftAuxCnfg_EnableMuxToPin(ATOPSS_ADC_TYPE *base)
{
    CY_ASSERT_L1(NULL != base);
    PPCA_ATOP_ADC_DFT_AUX_CNFG(base) |= PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_DFT_AUX_CNFG_ADC_MUX_TO_PIN_Msk;
}

/******************************************************************************
* Function Name: Cy_PPCA_ADC_DftAuxCnfg_DisableMuxToPin
***************************************************************************//**
*
* Disables the ADC MUX to Pin connection in the ADC_DFT_AUX_CNFG register.
*
* \param base The pointer to the ADC instance address.
*
******************************************************************************/
__STATIC_INLINE void Cy_PPCA_ADC_DftAuxCnfg_DisableMuxToPin(ATOPSS_ADC_TYPE *base)
{
    CY_ASSERT_L1(NULL != base);
    PPCA_ATOP_ADC_DFT_AUX_CNFG(base) &= (uint32_t) ~PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_DFT_AUX_CNFG_ADC_MUX_TO_PIN_Msk;
}

/******************************************************************************
* Function Name: Cy_PPCA_ADC_DftAuxCnfg_Set
***************************************************************************//**
*
* Configures the full ADC_DFT_AUX_CNFG register to connect R2R_DAC output
* directly to the AI0/AI1 pins without using the buffer.
*
* \param base The pointer to the ADC instance address.
*
* \param adft_enable Enable/disable ADFT path.
*
* \param src Source selection value \ref cy_en_adc_dft_src_t.
*
* \param mux_to_pin_enable Enable/disable ADC MUX to pin connection.
*
******************************************************************************/
__STATIC_INLINE void Cy_PPCA_ADC_DftAuxCnfg_Set(ATOPSS_ADC_TYPE *base, bool adft_enable, cy_en_adc_dft_src_t src, bool mux_to_pin_enable)
{
    CY_ASSERT_L1(NULL != base);
    PPCA_ATOP_ADC_DFT_AUX_CNFG(base) = _VAL2FLD(PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_DFT_AUX_CNFG_ADFT_EN, (uint32_t)adft_enable) |
                                         _VAL2FLD(PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_DFT_AUX_CNFG_SEL_SRC_N, src) |
                                         _VAL2FLD(PPCA_ATOPSS_ADC_GRP_SLICE_ADC_ADC_DFT_AUX_CNFG_ADC_MUX_TO_PIN, (uint32_t)mux_to_pin_enable);
}

/******************************************************************************
* Function Name: Cy_PPCA_ADC_DftAuxCnfg_Get
***************************************************************************//**
*
* Returns the current value of the ADC_DFT_AUX_CNFG register.
*
* \param base The pointer to the ADC instance address.
*
* \return Current register value.
*
******************************************************************************/
__STATIC_INLINE uint32_t Cy_PPCA_ADC_DftAuxCnfg_Get(ATOPSS_ADC_TYPE *base)
{
    CY_ASSERT_L1(NULL != base);
    return PPCA_ATOP_ADC_DFT_AUX_CNFG(base);
}

/** \} group_ppca_adc_functions */



#if defined(__cplusplus)
}
#endif
#endif /* CY_IP_MXS40PPSS */

#endif /* CY_PPCA_ADC_H */

