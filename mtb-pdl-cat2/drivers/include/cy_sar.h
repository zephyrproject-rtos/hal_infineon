/***************************************************************************//**
* \file cy_sar.h
* \version 2.70
*
* Header file for the SAR driver.
*
********************************************************************************
* \copyright
* (c) (2020-2025), Cypress Semiconductor Corporation (an Infineon company) or
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
*******************************************************************************/

/**
* \addtogroup group_sar
* \{
* This driver configures and controls the SAR ADC subsystem block.
*
* The functions and other declarations used in this driver are in cy_sar.h.
* You can include cy_pdl.h to get access to all functions
* and declarations in the PDL.
*
* This SAR ADC subsystem is comprised of:
*   - a 12-bit SAR converter (SARADC)
*   - an embedded reference block (SARREF)
*   - a mux (\ref group_sar_sarmux "SARMUX") at the inputs of the converter
*   - a sequence controller (\ref group_sar_sarmux "SARSEQ") that enables multi-channel acquisition
*       in a round robin fashion, without CPU intervention, to maximize scan rates.
*
* \image html sar_block_diagram.png
*
* The high level features of the subsystem are:
*   - maximum sample rate of 1 Msps
*   - sixteen individually configurable channels (depends on device routing capabilities)
*   - per channel selectable
*       - single-ended or differential input mode
*       - input from external pin (8 channels in single-ended mode or 4 channels in differential mode)
*         or from internal signals (AMUXBUS, CTB)
*       - choose one of four programmable acquisition times
*       - averaging and accumulation
*   - scan can be triggered by firmware or hardware in single shot or continuous mode
*   - hardware averaging from 2 to 256 samples
*   - selectable voltage references
*       - internal VDDA and VDDA/2 references
*       - buffered 1.2 V bandgap reference
*       - external reference from dedicated pin
*   - interrupt generation
*
* \section group_sar_configuration Configuration Considerations
* As an example, following SAR configuration will be used:
* - Three channels:
*   - Single-ended channel on Pin 0
*   - Single-ended channel on Pin 1
*   - Differential channel between Pin 0 (positive input) and Pin 1 (negative input)
* - 12-bit resolution for all three channels
* - No sample averaging for all three channels
* - Trigger SAR from TCPWM-based timer.
*
* The high level steps to use SAR driver are:
*
*   - \ref group_sar_config_structure
*   - \ref group_sar_initialization
*   - \ref group_sar_clock
*   - \ref group_sar_trigger_conversions
*   - \ref group_sar_handle_interrupts
*   - \ref group_sar_retrieve_result
*
* \section group_sar_config_structure Configuration structure
*
* To configure the SAR subsystem, call \ref Cy_SAR_Init. This function requires two pointers:
* a pointer to the \ref SAR_Type structure for the base hardware register address
* and pointer to the configuration structure \ref cy_stc_sar_config_t.
*
* Configuration structure \ref cy_stc_sar_config_t includes two substructures:
* \ref cy_stc_sar_config_t::channelConfig and \ref cy_stc_sar_config_t::routingConfig.
*
* \ref cy_stc_sar_channel_config_t is used to configure individual channels.
* Here is an example of SAR channels configuration for our use case:
*
* \snippet sar/snippet/sar_snippet.c SNIPPET_SAR_CHAN_STRUCT
*
* \ref cy_stc_sar_routing_config_t is used to define SARMUX configuration.
* Use one or more values from the \ref group_sar_mux_switch and "OR" them together.
* Firmware control can be changed at run-time by calling \ref Cy_SAR_SetAnalogSwitch the desired switch states
* SARSEQ control can be changed at run-time by calling \ref Cy_SAR_SetSwitchSarSeqCtrl.
*
* \snippet sar/snippet/sar_snippet.c SNIPPET_SAR_MUX_SWITCH
*
* Firmware control also can be changed at run-time by calling \ref Cy_SAR_SetDiagSwitch the desired switch states
* SARSEQ control can be changed at run-time by calling \ref Cy_SAR_SetDiagHwCtrl for the DIAGMUX/EXPMUX
*
* \snippet sar/snippet/sar_snippet.c SNIPPET_SAR_DIAG_SWITCH
*
* In order to complete SAR configuration structure, all remaining fields of
* \ref cy_stc_sar_config_t should be filled:
*
* \snippet sar/snippet/sar_snippet.c SNIPPET_SAR_INIT_STRUCT
*
* \section group_sar_initialization Initialization and Enable
* As mentioned in a previous step, to configure the SAR subsystem, call
* \ref Cy_SAR_Init function with pointers to \ref SAR_Type and
* \ref cy_stc_sar_config_t structures.
* After initialization, call \ref Cy_SAR_Enable to enable the hardware.
*
* \snippet sar/snippet/sar_snippet.c SNIPPET_SAR_INIT
*
* \section group_sar_clock SAR Clock Configuration
*
* The SAR requires a clock. Assign a clock to the SAR using the
* pre-defined enum, PCLK_PASS_CLOCK_SAR, to identify the SAR subsystem.
* Set the clock divider value to achieve the desired clock rate. The SAR can support
* a maximum frequency of 18 MHz.
*
* \snippet sar/snippet/sar_snippet.c SAR_SNIPPET_CONFIGURE_CLOCK
*
* \section group_sar_trigger_conversions Triggering Conversions
*
* The SAR subsystem has the following modes for triggering a conversion:
* <table class="doxtable">
*   <tr>
*     <th>Mode</th>
*     <th>Description</th>
*     <th>Usage</th>
*   </tr>
*   <tr>
*     <td>Continuous</td>
*     <td>After completing a scan, the
*     SARSEQ will immediately start the next scan. That is, the SARSEQ will always be BUSY.
*     As a result all other triggers, firmware or hardware, are essentially ignored.
*  </td>
*     <td>To enter this mode, call \ref Cy_SAR_StartConvert with \ref CY_SAR_START_CONVERT_CONTINUOUS.
*     To stop continuous conversions, call \ref Cy_SAR_StopConvert.
*     </td>
*   </tr>
*   <tr>
*     <td>Firmware single shot</td>
*     <td>A single conversion of all enabled channels is triggered with a function call to \ref Cy_SAR_StartConvert with
*     \ref CY_SAR_START_CONVERT_SINGLE_SHOT.
*     </td>
*     <td>
*     Firmware triggering is always available by calling \ref Cy_SAR_StartConvert with \ref CY_SAR_START_CONVERT_SINGLE_SHOT.
*     To allow only firmware triggering, or disable
*     hardware triggering, set up the \ref cy_stc_sar_config_t::trigMode field of config structure with \ref CY_SAR_TRIGGER_MODE_FW_ONLY.
*     </td>
*   </tr>
*   <tr>
*     <td>Hardware edge sensitive</td>
*     <td>A single conversion of all enabled channels is triggered on the rising edge of the hardware
*     trigger signal.</td>
*     <td>To enable this mode, set up the \ref cy_stc_sar_config_t::trigMode field of  config structure with
*     \ref CY_SAR_TRIGGER_MODE_FW_AND_HWEDGE.</td>
*    </tr>
*    <tr>
*     <td>Hardware level sensitive</td>
*     <td>Conversions are triggered continuously when the hardware trigger signal is high.</td>
*     <td>To enable this mode, set up the \ref cy_stc_sar_config_t::trigMode field of  config structure with
*     \ref CY_SAR_TRIGGER_MODE_FW_AND_HWLEVEL.</td>
*    </tr>
* </table>
*
* If the trigger occurs during a scan, a \ref CY_SAR_INTR_FW_COLLISION interrupt occurs and the trigger is delayed until the end of the scan.
*
* The trigger mode can be changed during run time with \ref Cy_SAR_SetConvertMode.
*
* For the hardware trigger modes, use the \ref group_trigmux driver to route an internal or external
* signal to the SAR trigger input.
* When making the required \ref Cy_TrigMux_Connect calls, use the pre-defined enum, TRIG6_OUT_PASS_TR_SAR_IN,
* for the SAR trigger input.
*
* \snippet sar/snippet/sar_snippet.c SNIPPET_SAR_CONFIG_TRIGGER
*
* \section group_sar_handle_interrupts Handling Interrupts
*
* The SAR can generate interrupts on these events:
*
*   - End of scan (EOS): when scanning of all enabled channels complete.
*   - Overflow: when the result register is updated before the previous result is read.
*   - FW collision: when a new trigger is received while the SAR is still processing the previous trigger.
*   - Saturation detection: when the channel result is equal to the minimum or maximum value.
*   - Range detection: when the channel result meets the programmed upper or lower threshold values.
*
* The SAR interrupt to the NVIC is raised any time the intersection (logic and) of the interrupt
* flags and the corresponding interrupt masks are non-zero.
*
* Implement an interrupt routine and assign it to the SAR interrupt.
* Use the pre-defined enum, pass_interrupt_sar_IRQn, as the interrupt source for the SAR.
*
* The following code snippet demonstrates how to implement a routine to handle the interrupt.
* The routine gets called when any one of the SAR interrupts are triggered.
* When servicing an interrupt, the user must clear the interrupt so that subsequent
* interrupts can be handled.
*
* \snippet sar/snippet/sar_snippet.c SNIPPET_SAR_ISR
*
* The following code snippet demonstrates how to configure and enable the interrupt.
*
* \snippet sar/snippet/sar_snippet.c SNIPPET_SAR_CONFIG_INTR
*
* Alternately, instead of handling the interrupts, the \ref Cy_SAR_IsEndConversion function
* allows for firmware polling of the end of conversion status.
*
* \section group_sar_retrieve_result Retrieve Channel Results
*
* Retrieve the ADC result by calling \ref Cy_SAR_GetResult16 with the desired channel.
* To convert the result to a voltage, pass the ADC result to \ref Cy_SAR_CountsTo_Volts, \ref Cy_SAR_CountsTo_mVolts, or
* \ref Cy_SAR_CountsTo_uVolts.
* To customize the counts-to-volts conversion process, use \ref Cy_SAR_SetChannelOffset and \ref Cy_SAR_SetChannelGain functions.
*
* \section group_sar_scan_time Scan Rate
*
* The scan rate is dependent on the following:
*
*   - ADC clock rate
*   - Number of channels
*   - Averaging
*   - Resolution
*   - Acquisition times
*
* \subsection group_sar_acquisition_time Acquisition Time
*
* The acquisition time of a channel is based on which of the four global aperture times are selected for that
* channel. The selection is done during initialization per channel with \ref cy_stc_sar_channel_config_t.
* The four global aperture times are also set during initialization with from \ref cy_stc_sar_config_t::sampleTime0 through
* \ref cy_stc_sar_config_t::sampleTime3. Note that these global aperture times are in SAR clock cycles and the
* acquisition time is 1 less than that value in the register.
*
* \image html sar_acquisition_time_eqn.png
*
* \subsection group_sar_channel_sample_time Channel Sample Time
*
* The sample time for a channel is the time required to acquire the analog signal
* and convert it to a digital code.
*
* \image html sar_channel_sample_time_eqn.png
*
* The SAR ADC is a 12-bit converter so Resolution = 12.
*
* \subsection group_sar_total_scan_time Total Scan Time
*
* Channels using one of the sequential averaging modes: accumulating or fixed (see \ref cy_stc_sar_config_t::avgShift)
* are sampled multiple times per scan. The number of samples averaged are set during initialization
* using \ref cy_stc_sar_config_t::avgCnt.
* Channels that are not averaged are only sampled once per scan.
*
* The total scan time is the sum of each channel's sample time multiplied by the samples per scan.
*
* \image html sar_scan_rate_eqn.png
*
* where N is the total number of channels in the scan.
*
* \section group_sar_sarmux SARMUX and SARSEQ
*
* The SARMUX is an analog programmable multiplexer. Its switches can be controlled by the SARSEQ or firmware.
* and the inputs can come from:
*   - a dedicated port (can support 8 single-ended channels or 4 differential channels)
*   - an internal die temperature (DieTemp) sensor
*   - CTB output via SARBUS0/1 (if CTBs are available on the device)
*   - AMUXBUSA/B
*
* The following figure shows the SARMUX switches. See the device datasheet for the exact location of SARMUX pins.
*
* \image html sar_sarmux_switches.png
*
* When using the SARSEQ, the following configurations must be performed:
*   - enable SARSEQ control of required switches ( \ref cy_stc_sar_routing_config_t::muxSwitchHwCtrl)
*   - close the required switches with firmware ( \ref cy_stc_sar_routing_config_t::muxSwitch)
*   - configure the PORT_ADDR and PIN_ADDR
*
* While firmware can control every switch in the SARMUX, not every switch can be controlled by the SARSEQ (green switches in the above figure).
* Additionally, switches outside of the SARMUX such as the AMUXBUSA/B switches or
* CTB switches will require separate function calls (see \ref group_gpio "GPIO" and CTB drivers).
* The SARSEQ can control three switches in the CTB driver.
* These switches need to be enabled for SARSEQ control if the CTB outputs are used as the SARMUX inputs.
*
* \subsection group_sar_sarmux_se_diff Input from SARMUX port
*
* The following figure and code snippet show how two GPIOs on the SARMUX dedicated port
* are connected to the SARADC as separate single-ended channels and as a differential-pair channel.
*
* \image html sar_sarmux_dedicated_port.png
*
* \snippet sar/snippet/sar_snippet.c SNIPPET_SAR_CHAN_STRUCT
* \snippet sar/snippet/sar_snippet.c SNIPPET_SAR_MUX_SWITCH
*
* \subsection group_sar_sarmux_ctb Input from CTB output via SARBUS0/1
*
* The following figure and code snippet show how the two opamp outputs from the CTB
* are connected to the SARADC as separate single-ended channels and as a differential-pair channel.
* Note that separate function calls are needed to configure and enable the opamps, perform required analog routing,
* and enable SARSEQ control of the switches contained in the CTB.
*
* \image html sar_sarmux_ctb.png
*
* Use \ref group_sar_sarmux_se_diff code snippet for reference.
*
* \snippet sar/snippet/sar_snippet.c SNIPPET_SAR_SARMUX_CTB
* Then use \ref Cy_SAR_Init and results retrieval as usual.
* For more information about CTB see \ref group_ctb.
*
* \subsection group_sar_sarmux_amuxbus Input from other pins through AMUXBUSA/B
*
* The following figure and code snippet show how two GPIOs on any port through the AMUXBUSA and AMUXBUSB
* are connected to the SARADC as separate single-ended channels and as a differential-pair channel.
* Note that separate function calls are needed to route the device pins to the SARMUX. The AMUXBUSes
* are separated into multiple segments and these segments are connected/disconnected using the AMUX_SPLIT_CTL
* registers in the HSIOM.
*
* \image html sar_sarmux_amuxbus.png
*
* Use \ref group_sar_sarmux_se_diff code snippet for reference.
*
* \snippet sar_snippet.c SNIPPET_SAR_SARMUX_AMUXBUS
*
* To connect SARMUX to any other non-dedicated port, you may need to close additional HSIOM switches to route signals
* through AMUXBUS.
* For more detail, see the device TRM, AMUX splitting.
*
* The following code snippet is an alternative pin configuration. To connect Port 1 to AMUXBUS, close the left and
* right switches of AMUX_SPLIT_CTL[1] and AMUX_SPLIT_CTL[6].
*
* \subsection group_sar_sarmux_dietemp Die temperature measurement
*
* The DieTemp sensor scanning typically is being done by the injection channel:
*
* \snippet sar/snippet/sar_snippet.c SNIPPET_SAR_INJ_STRUCT
* \snippet sar/snippet/sar_snippet.c SNIPPET_SAR_TEMP_INIT
* Then the regular initialization is going on:
* \snippet sar/snippet/sar_snippet.c SNIPPET_SAR_INIT
* Then during the ADC working the injection channel is being activated:
* \snippet sar/snippet/sar_snippet.c SNIPPET_SAR_EN_INJ
* Then the retrieved injection channel result can be transformed into the temperature value:
* \snippet sar/snippet/sar_snippet.c SNIPPET_SAR_INJ
* \snippet sar/snippet/sar_snippet.c SNIPPET_SAR_TEMP
*
* \section group_sar_low_power Low Power Support
* This SAR driver provides a callback function to handle power mode transitions.
* The \ref Cy_SAR_DeepSleepCallback function ensures that SAR conversions are stopped
* before Deep Sleep entry. Upon wakeup, the callback
* enables the hardware and continuous conversions, if previously enabled.
*
* To trigger the callback execution, the callback must be registered before calling \ref Cy_SysPm_CpuEnterDeepSleep. Refer to
* \ref group_syspm driver for more information about power mode transitions and
* callback registration.
*
* Recall that during configuration the SARMUX can be configured to remain enabled in Deep Sleep mode
* by the \ref cy_stc_sar_config_t::sarMuxDsEn setting.
* All other blocks (SARADC, REFBUF, and SARSEQ) do not support Deep Sleep mode operation.
*
* \section group_sar_more_information More Information
* For more information on the SAR ADC subsystem, refer to the technical reference manual (TRM).
*
* \section group_sar_changelog Changelog
* <table class="doxtable">
*   <tr><th>Version</th><th>Changes</th><th>Reason for Change</th></tr>
*   <tr>
*     <td rowspan="1">2.70</td>
*     <td>Added the \ref Cy_SAR_SetAveragingMode function.</td>
*     <td>API improvement</td>
*   </tr>
*   <tr>
*     <td rowspan="4">2.60</td>
*     <td>Added support of PSOC 4100T Plus device family.</td>
*     <td>New device support.</td>
*   </tr>
*   <tr>
*     <td>Re-defined settings of the SAR_DFT_CTRL_DCEN bit in the Cy_SAR_Init() and Cy_SAR_SetVref() functions.</td>
*     <td>Bug fixing.</td>
*   </tr>
*   <tr>
*     <td>Temperature ranges are updated in the Cy_SAR_CountsTo_degreeC() function.</td>
*     <td>Bug fixing.</td>
*   </tr>
*   <tr>
*     <td>The \ref cy_stc_sar_config_t::sampleTime0 description is updated.</td>
*     <td>Documentation improvement.</td>
*   </tr>
*   <tr>
*     <td rowspan="2">2.50</td>
*     <td>Added the \ref Cy_SAR_CountsTo_degreeC function</td>
*     <td>API improvement</td>
*   </tr>
*   <tr>
*     <td>The configuration restoring during DeepSleep cycle is updated in the \ref Cy_SAR_DeepSleepCallback function</td>
*     <td>Bug fix</td>
*   </tr>
*   <tr>
*     <td rowspan="1">2.40</td>
*     <td>Added support for a new version of SAR.\n
*     Added support for PSOC4 HVMS/PA platform.\n
*     Updated APIs to incorporate PSOC4 HVMS/PA platform configuration.\n
*     Documentation enhancement.</td>
*     <td>New device support.</td>
*   </tr>
*   <tr>
*     <td rowspan="2">2.30</td>
*     <td>The \ref Cy_SAR_DeepSleepCallback parameter type is changed to match with the
*             \ref cy_stc_syspm_callback_t::callback type</td>
*     <td>Eliminate compiler warnings</td>
*   </tr>
*   <tr>
*     <td>The \ref Cy_SAR_IsEndConversion timeout is corrected</td>
*     <td>Fixed incorrect timeout value and related documentation</td>
*   </tr>
*   <tr>
*     <td rowspan="2">2.20</td>
*     <td>The \ref Cy_SAR_CountsTo_uVolts is updated to avoid 64-bit math</td>
*     <td>Memory consumption reduction</td>
*   </tr>
*   <tr>
*     <td>Update the paths to the code snippets.</td>
*     <td>PDL structure update.</td>
*   </tr>
*   <tr>
*     <td rowspan="3">2.10</td>
*     <td>Added the \ref cy_stc_sar_channel_config_t::rangeIntrEn and
*                   \ref cy_stc_sar_channel_config_t::satIntrEn settings</td>
*     <td>Bug fixing</td>
*   </tr>
*   <tr>
*     <td>Fixed the \ref Cy_SAR_SetConvertMode function</td>
*     <td>Bug fixing</td>
*   </tr>
*   <tr>
*     <td>Updated the \ref Cy_SAR_CountsTo_uVolts,
*                     \ref Cy_SAR_CountsTo_mVolts and
*                     \ref Cy_SAR_CountsTo_Volts functions so that
*                 they now support sub-resolutions</td>
*     <td>Bug fixing</td>
*   </tr>
*   <tr>
*     <td rowspan="4">2.0</td>
*     <td>Added the \ref Cy_SAR_CountsTo_degreeC function</td>
*     <td>\ref group_sar_sarmux_dietemp support</td>
*   </tr>
*   <tr>
*     <td>Added the \ref Cy_SAR_EnableChannels and \ref Cy_SAR_DisableChannels functions</td>
*     <td>API enhancement</td>
*   </tr>
*   <tr>
*     <td>Added code snippets how to interconnect with \ref group_ctb</td>
*     <td>\ref group_ctb support</td>
*   </tr>
*   <tr>
*     <td>The type of \ref cy_stc_sar_channel_config_t::sampleTimeSel is changed
*         from uint32_t to \ref cy_en_sar_channel_sampletime_t</td>
*     <td>Improved the API error proofness</td>
*   </tr>
*   <tr>
*     <td>1.0.1</td>
*     <td>Minor documentation updates.</td>
*     <td>Documentation enhancement</td>
*   </tr>
*   <tr>
*     <td>1.0</td>
*     <td>Initial version</td>
*     <td></td>
*   </tr>
* </table>
*
* \defgroup group_sar_macros Macros
*   \{
*       \defgroup group_sar_macros_interrupt        Interrupt Masks
*       \defgroup group_sar_mux_switch              SARMUX Switch Control Register Masks
*       \defgroup group_sar_diag_exp_mux_switch     EXPMUX/DIAGMUX Switch Control Register Masks
*   \}
* \defgroup group_sar_functions Functions
*   \{
*       \defgroup group_sar_functions_basic         Initialization and Basic Functions
*       \defgroup group_sar_functions_power         Low Power Callback
*       \defgroup group_sar_functions_config        Run-time Configuration Functions
*       \defgroup group_sar_functions_countsto      Counts Conversion Functions
*       \defgroup group_sar_functions_interrupt     Interrupt Functions
*       \defgroup group_sar_functions_switches      SARMUX Switch Control Functions
*       \defgroup group_sar_functions_helper        Useful Configuration Query Functions
*   \}
* \defgroup group_sar_data_structures Data Structures
* \defgroup group_sar_enums Enumerated Types
*   \{
*       \defgroup group_sar_ctrl_register_enums         Control Register Enums
*       \defgroup group_sar_sample_ctrl_register_enums  Sample Control Register Enums
*       \defgroup group_sar_sample_time_shift_enums     Sample Time Register Enums
*       \defgroup group_sar_range_thres_register_enums  Range Interrupt Register Enums
*       \defgroup group_sar_chan_config_register_enums  Channel Configuration Register Enums
*   \}
*/

#if !defined(CY_SAR_H)
#define CY_SAR_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include "cy_syslib.h"
#include "cy_syspm.h"
#include "cy_device.h"

#ifdef CY_IP_M0S8PASS4A_SAR

#if defined(__cplusplus)
extern "C" {
#endif

/** \addtogroup group_sar_macros
* \{
*/

/** Driver major version */
#define CY_SAR_DRV_VERSION_MAJOR        2

/** Driver minor version */
#define CY_SAR_DRV_VERSION_MINOR        60

/** SAR driver identifier */
#define CY_SAR_ID                       CY_PDL_DRV_ID(0x01U)

/** Number of sequencer channels */
#if defined(PASS1_SAR_SAR_CHANNELS) && \
    (PASS1_SAR_SAR_CHANNELS > PASS0_SAR_SAR_CHANNELS)
    #define CY_SAR_SEQ_NUM_CHANNELS     (PASS1_SAR_SAR_CHANNELS)
#else
    #define CY_SAR_SEQ_NUM_CHANNELS     (PASS0_SAR_SAR_CHANNELS)
#endif /* PASS1_SAR_SAR_CHANNELS */

/** Number of all channels including the injection channel */
#define CY_SAR_NUM_CHANNELS             (CY_SAR_SEQ_NUM_CHANNELS + 1UL)

/** Injection channel index */
#define CY_SAR_INJ_CHANNEL              (CY_SAR_SEQ_NUM_CHANNELS)

/** Channels mask */
#define CY_SAR_CHANNELS_MASK            ((1UL << CY_SAR_SEQ_NUM_CHANNELS) - 1UL)

/** Injection channel mask */
#define CY_SAR_INJ_CHAN_MASK            (1UL << CY_SAR_INJ_CHANNEL)

/** \addtogroup group_sar_macros_interrupt
* \{
*/

/** Interrupt masks */
#define CY_SAR_INTR_EOS                 (SAR_INTR_MASK_EOS_MASK_Msk)           /**< Enable end of scan (EOS) interrupt */
#define CY_SAR_INTR_OVERFLOW            (SAR_INTR_MASK_OVERFLOW_MASK_Msk)      /**< Enable overflow interrupt */
#define CY_SAR_INTR_FW_COLLISION        (SAR_INTR_MASK_FW_COLLISION_MASK_Msk)  /**< Enable firmware collision interrupt */
#define CY_SAR_INTR_INJ_EOC             (SAR_INTR_INJ_EOC_INTR_Msk)            /**< Enable injection channel end of conversion (EOC) interrupt */
#define CY_SAR_INTR_INJ_SATURATE        (SAR_INTR_INJ_SATURATE_INTR_Msk)       /**< Enable injection channel saturation interrupt */
#define CY_SAR_INTR_INJ_RANGE           (SAR_INTR_INJ_RANGE_INTR_Msk)          /**< Enable injection channel range detection interrupt */
#define CY_SAR_INTR_INJ_COLLISION       (SAR_INTR_INJ_COLLISION_INTR_Msk)      /**< Enable injection channel firmware collision interrupt */

/** Combined interrupt mask */
#define CY_SAR_INTR                     (CY_SAR_INTR_EOS | \
                                         CY_SAR_INTR_OVERFLOW | \
                                         CY_SAR_INTR_FW_COLLISION | \
                                         CY_SAR_INTR_INJ_EOC | \
                                         CY_SAR_INTR_INJ_SATURATE | \
                                         CY_SAR_INTR_INJ_RANGE | \
                                         CY_SAR_INTR_INJ_COLLISION)
/** \} group_sar_macros_interrupt */

/** \cond INTERNAL */
#define CY_SAR_WRK_MAX_12BIT            (0x00001000UL)     /**< Maximum SAR work register value for a 12-bit resolution */

#if (CY_IP_M0S8PASS4A_SAR_INSTANCES == 1U)
    /* Unconditionally return zero if there is one SAR instance */
    #define CY_SAR_INSTANCE(base)           ((SAR0 == (base)) ? 0UL : 0UL)
#else
    #define CY_SAR_INSTANCE(base)           ((SAR0 == (base)) ? 0UL : 1UL)
#endif /* (CY_IP_M0S8PASS4A_SAR_INSTANCES == 1U) */

/* Macros for conditions used in CY_ASSERT calls */
#define CY_SAR_CHANMASK(mask)          (0UL == ((mask) & ~CY_SAR_CHANNELS_MASK))
#define CY_SAR_INTRMASK(mask)          (0UL == ((mask) & ~CY_SAR_INTR))
#define CY_SAR_RANGE_COND(cond)        ((CY_SAR_RANGE_COND_BELOW    == (cond)) || \
                                        (CY_SAR_RANGE_COND_INSIDE   == (cond)) || \
                                        (CY_SAR_RANGE_COND_ABOVE    == (cond)) || \
                                        (CY_SAR_RANGE_COND_OUTSIDE  == (cond)))
#define CY_SAR_AVG_MODE(mode)          ((CY_SAR_AVG_MODE_ACCUNDUMP   == (mode)) || \
                                        (CY_SAR_AVG_MODE_INTERLEAVED == (mode)))
/** \endcond */


/** \addtogroup group_sar_mux_switch
* \{
* Mask definitions of SARMUX switches that can be controlled by the SARSEQ.
* To enable the sequencer control of multiple switches, "OR" the values together.
*/

#define CY_SAR_MUX_HW_CTRL_P0          (SAR_MUX_SWITCH_HW_CTRL_MUX_HW_CTRL_P0_Msk)        /**< Enable SARSEQ control of Pin 0 switches (for Vplus and Vminus) of SARMUX dedicated port */
#define CY_SAR_MUX_HW_CTRL_P1          (SAR_MUX_SWITCH_HW_CTRL_MUX_HW_CTRL_P1_Msk)        /**< Enable SARSEQ control of Pin 1 switches (for Vplus and Vminus) of SARMUX dedicated port */
#define CY_SAR_MUX_HW_CTRL_P2          (SAR_MUX_SWITCH_HW_CTRL_MUX_HW_CTRL_P2_Msk)        /**< Enable SARSEQ control of Pin 2 switches (for Vplus and Vminus) of SARMUX dedicated port */
#define CY_SAR_MUX_HW_CTRL_P3          (SAR_MUX_SWITCH_HW_CTRL_MUX_HW_CTRL_P3_Msk)        /**< Enable SARSEQ control of Pin 3 switches (for Vplus and Vminus) of SARMUX dedicated port */
#define CY_SAR_MUX_HW_CTRL_P4          (SAR_MUX_SWITCH_HW_CTRL_MUX_HW_CTRL_P4_Msk)        /**< Enable SARSEQ control of Pin 4 switches (for Vplus and Vminus) of SARMUX dedicated port */
#define CY_SAR_MUX_HW_CTRL_P5          (SAR_MUX_SWITCH_HW_CTRL_MUX_HW_CTRL_P5_Msk)        /**< Enable SARSEQ control of Pin 5 switches (for Vplus and Vminus) of SARMUX dedicated port */
#define CY_SAR_MUX_HW_CTRL_P6          (SAR_MUX_SWITCH_HW_CTRL_MUX_HW_CTRL_P6_Msk)        /**< Enable SARSEQ control of Pin 6 switches (for Vplus and Vminus) of SARMUX dedicated port */
#define CY_SAR_MUX_HW_CTRL_P7          (SAR_MUX_SWITCH_HW_CTRL_MUX_HW_CTRL_P7_Msk)        /**< Enable SARSEQ control of Pin 7 switches (for Vplus and Vminus) of SARMUX dedicated port */
#define CY_SAR_MUX_HW_CTRL_VSSA        (SAR_MUX_SWITCH_HW_CTRL_MUX_HW_CTRL_VSSA_Msk)      /**< Enable SARSEQ control of the switch between VSSA and Vminus */
#define CY_SAR_MUX_HW_CTRL_TEMP        (SAR_MUX_SWITCH_HW_CTRL_MUX_HW_CTRL_TEMP_Msk)      /**< Enable SARSEQ control of the switch between DieTemp and Vplus */
#define CY_SAR_MUX_HW_CTRL_AMUXBUSA    (SAR_MUX_SWITCH_HW_CTRL_MUX_HW_CTRL_AMUXBUSA_Msk)  /**< Enable SARSEQ control of AMUXBUSA switches (for Vplus and Vminus) */
#define CY_SAR_MUX_HW_CTRL_AMUXBUSB    (SAR_MUX_SWITCH_HW_CTRL_MUX_HW_CTRL_AMUXBUSB_Msk)  /**< Enable SARSEQ control of AMUXBUSB switches (for Vplus and Vminus) */
#define CY_SAR_MUX_HW_CTRL_SARBUS0     (SAR_MUX_SWITCH_HW_CTRL_MUX_HW_CTRL_SARBUS0_Msk)   /**< Enable SARSEQ control of SARBUS0 switches (for Vplus and Vminus) */
#define CY_SAR_MUX_HW_CTRL_SARBUS1     (SAR_MUX_SWITCH_HW_CTRL_MUX_HW_CTRL_SARBUS1_Msk)   /**< Enable SARSEQ control of SARBUS1 switches (for Vplus and Vminus) */

/* SARMUX pins to Vplus */
#define CY_SAR_MUX_FW_P0_VPLUS         (SAR_MUX_SWITCH0_MUX_FW_P0_VPLUS_Msk)    /**< Switch between Pin 0 of SARMUX and Vplus of SARADC */
#define CY_SAR_MUX_FW_P1_VPLUS         (SAR_MUX_SWITCH0_MUX_FW_P1_VPLUS_Msk)    /**< Switch between Pin 1 of SARMUX and Vplus of SARADC */
#define CY_SAR_MUX_FW_P2_VPLUS         (SAR_MUX_SWITCH0_MUX_FW_P2_VPLUS_Msk)    /**< Switch between Pin 2 of SARMUX and Vplus of SARADC */
#define CY_SAR_MUX_FW_P3_VPLUS         (SAR_MUX_SWITCH0_MUX_FW_P3_VPLUS_Msk)    /**< Switch between Pin 3 of SARMUX and Vplus of SARADC */
#define CY_SAR_MUX_FW_P4_VPLUS         (SAR_MUX_SWITCH0_MUX_FW_P4_VPLUS_Msk)    /**< Switch between Pin 4 of SARMUX and Vplus of SARADC */
#define CY_SAR_MUX_FW_P5_VPLUS         (SAR_MUX_SWITCH0_MUX_FW_P5_VPLUS_Msk)    /**< Switch between Pin 5 of SARMUX and Vplus of SARADC */
#define CY_SAR_MUX_FW_P6_VPLUS         (SAR_MUX_SWITCH0_MUX_FW_P6_VPLUS_Msk)    /**< Switch between Pin 6 of SARMUX and Vplus of SARADC */
#define CY_SAR_MUX_FW_P7_VPLUS         (SAR_MUX_SWITCH0_MUX_FW_P7_VPLUS_Msk)    /**< Switch between Pin 7 of SARMUX and Vplus of SARADC */

/* SARMUX pins to Vminus */
#define CY_SAR_MUX_FW_P0_VMINUS        (SAR_MUX_SWITCH0_MUX_FW_P0_VMINUS_Msk)   /**< Switch between Pin 0 of SARMUX and Vminus of SARADC */
#define CY_SAR_MUX_FW_P1_VMINUS        (SAR_MUX_SWITCH0_MUX_FW_P1_VMINUS_Msk)   /**< Switch between Pin 1 of SARMUX and Vminus of SARADC */
#define CY_SAR_MUX_FW_P2_VMINUS        (SAR_MUX_SWITCH0_MUX_FW_P2_VMINUS_Msk)   /**< Switch between Pin 2 of SARMUX and Vminus of SARADC */
#define CY_SAR_MUX_FW_P3_VMINUS        (SAR_MUX_SWITCH0_MUX_FW_P3_VMINUS_Msk)   /**< Switch between Pin 3 of SARMUX and Vminus of SARADC */
#define CY_SAR_MUX_FW_P4_VMINUS        (SAR_MUX_SWITCH0_MUX_FW_P4_VMINUS_Msk)   /**< Switch between Pin 4 of SARMUX and Vminus of SARADC */
#define CY_SAR_MUX_FW_P5_VMINUS        (SAR_MUX_SWITCH0_MUX_FW_P5_VMINUS_Msk)   /**< Switch between Pin 5 of SARMUX and Vminus of SARADC */
#define CY_SAR_MUX_FW_P6_VMINUS        (SAR_MUX_SWITCH0_MUX_FW_P6_VMINUS_Msk)   /**< Switch between Pin 6 of SARMUX and Vminus of SARADC */
#define CY_SAR_MUX_FW_P7_VMINUS        (SAR_MUX_SWITCH0_MUX_FW_P7_VMINUS_Msk)   /**< Switch between Pin 7 of SARMUX and Vminus of SARADC */

/* Vssa to Vminus and temperature sensor to Vplus */
#define CY_SAR_MUX_FW_VSSA_VMINUS      (SAR_MUX_SWITCH0_MUX_FW_VSSA_VMINUS_Msk)    /**< Switch between VSSA and Vminus of SARADC */
#define CY_SAR_MUX_FW_TEMP_VPLUS       (SAR_MUX_SWITCH0_MUX_FW_TEMP_VPLUS_Msk)     /**< Switch between the DieTemp sensor and vplus of SARADC */

/* Amuxbus A and B to Vplus and Vminus */
#define CY_SAR_MUX_FW_AMUXBUSA_VPLUS   (SAR_MUX_SWITCH0_MUX_FW_AMUXBUSA_VPLUS_Msk)     /**< Switch between AMUXBUSA and vplus of SARADC */
#define CY_SAR_MUX_FW_AMUXBUSB_VPLUS   (SAR_MUX_SWITCH0_MUX_FW_AMUXBUSB_VPLUS_Msk)     /**< Switch between AMUXBUSB and vplus of SARADC */
#define CY_SAR_MUX_FW_AMUXBUSA_VMINUS  (SAR_MUX_SWITCH0_MUX_FW_AMUXBUSA_VMINUS_Msk)    /**< Switch between AMUXBUSA and vminus of SARADC */
#define CY_SAR_MUX_FW_AMUXBUSB_VMINUS  (SAR_MUX_SWITCH0_MUX_FW_AMUXBUSB_VMINUS_Msk)    /**< Switch between AMUXBUSB and vminus of SARADC */

/* Sarbus 0 and 1 to Vplus and Vminus */
#define CY_SAR_MUX_FW_SARBUS0_VPLUS    (SAR_MUX_SWITCH0_MUX_FW_SARBUS0_VPLUS_Msk)      /**< Switch between SARBUS0 and vplus of SARADC */
#define CY_SAR_MUX_FW_SARBUS1_VPLUS    (SAR_MUX_SWITCH0_MUX_FW_SARBUS1_VPLUS_Msk)      /**< Switch between SARBUS1 and vplus of SARADC */
#define CY_SAR_MUX_FW_SARBUS0_VMINUS   (SAR_MUX_SWITCH0_MUX_FW_SARBUS0_VMINUS_Msk)     /**< Switch between SARBUS0 and vminus of SARADC */
#define CY_SAR_MUX_FW_SARBUS1_VMINUS   (SAR_MUX_SWITCH0_MUX_FW_SARBUS1_VMINUS_Msk)     /**< Switch between SARBUS1 and vminus of SARADC */

/* SARMUX pins to Core IO */
#define CY_SAR_MUX_FW_P4_COREIO0       (SAR_MUX_SWITCH0_MUX_FW_P4_COREIO0_Msk)      /**< Switch between Pin 4 of SARMUX and coreio0, if present */
#define CY_SAR_MUX_FW_P5_COREIO1       (SAR_MUX_SWITCH0_MUX_FW_P5_COREIO1_Msk)      /**< Switch between Pin 5 of SARMUX and coreio1, if present */
#define CY_SAR_MUX_FW_P6_COREIO2       (SAR_MUX_SWITCH0_MUX_FW_P6_COREIO2_Msk)      /**< Switch between Pin 6 of SARMUX and coreio2, if present */
#define CY_SAR_MUX_FW_P7_COREIO3       (SAR_MUX_SWITCH0_MUX_FW_P7_COREIO3_Msk)      /**< Switch between Pin 7 of SARMUX and coreio3, if present */

/** \} group_sar_mux_switch */

/** \addtogroup group_sar_diag_exp_mux_switch
* \{
* Mask definitions of EXPMUX/DIAGMUX switches that can be controlled by the SARSEQ.
* To enable the sequencer control of multiple switches, "OR" the values together.
*
* \note Applicable to PSOC4 HVMS/PA only.
*/

#if (defined (CY_IP_M0S8PASS4A_SAR_VERSION) && (4U <= CY_IP_M0S8PASS4A_SAR_VERSION)) || defined (CY_DOXYGEN)
#if (defined (CY_PASS0_SAR_EXPMUX_PRESENT) && (1U == CY_PASS0_SAR_EXPMUX_PRESENT)) || defined (CY_DOXYGEN)
#define CY_SAR_EXPMUX_HW_CTRL_P0       (SAR_MUX_SWITCH_HW_CTRL2_MUX_HW_CTRL_EXP_P0_Msk)   /**< Enable SARSEQ control of Pin 0 switches (for Vplus and Vminus) of EXPMUX dedicated port */
#define CY_SAR_EXPMUX_HW_CTRL_P1       (SAR_MUX_SWITCH_HW_CTRL2_MUX_HW_CTRL_EXP_P1_Msk)   /**< Enable SARSEQ control of Pin 1 switches (for Vplus and Vminus) of EXPMUX dedicated port */
#define CY_SAR_EXPMUX_HW_CTRL_P2       (SAR_MUX_SWITCH_HW_CTRL2_MUX_HW_CTRL_EXP_P2_Msk)   /**< Enable SARSEQ control of Pin 2 switches (for Vplus and Vminus) of EXPMUX dedicated port */
#define CY_SAR_EXPMUX_HW_CTRL_P3       (SAR_MUX_SWITCH_HW_CTRL2_MUX_HW_CTRL_EXP_P3_Msk)   /**< Enable SARSEQ control of Pin 3 switches (for Vplus and Vminus) of EXPMUX dedicated port */
#define CY_SAR_EXPMUX_HW_CTRL_P4       (SAR_MUX_SWITCH_HW_CTRL2_MUX_HW_CTRL_EXP_P4_Msk)   /**< Enable SARSEQ control of Pin 4 switches (for Vplus and Vminus) of EXPMUX dedicated port */
#define CY_SAR_EXPMUX_HW_CTRL_P5       (SAR_MUX_SWITCH_HW_CTRL2_MUX_HW_CTRL_EXP_P5_Msk)   /**< Enable SARSEQ control of Pin 5 switches (for Vplus and Vminus) of EXPMUX dedicated port */
#define CY_SAR_EXPMUX_HW_CTRL_P6       (SAR_MUX_SWITCH_HW_CTRL2_MUX_HW_CTRL_EXP_P6_Msk)   /**< Enable SARSEQ control of Pin 6 switches (for Vplus and Vminus) of EXPMUX dedicated port */
#define CY_SAR_EXPMUX_HW_CTRL_P7       (SAR_MUX_SWITCH_HW_CTRL2_MUX_HW_CTRL_EXP_P7_Msk)   /**< Enable SARSEQ control of Pin 7 switches (for Vplus and Vminus) of EXPMUX dedicated port */
#endif /* 1U == CY_PASS0_SAR_EXPMUX_PRESENT */
#define CY_SAR_DIAGMUX_HW_CTRL_V0      (SAR_MUX_SWITCH_HW_CTRL2_MUX_FW_VD0_VG0_Msk)       /**< Enable SARSEQ control of Pin 0 switches (for Vdiag and Vgnd) of DIAGMUX dedicated port */
#define CY_SAR_DIAGMUX_HW_CTRL_V1      (SAR_MUX_SWITCH_HW_CTRL2_MUX_FW_VD1_VG1_Msk)       /**< Enable SARSEQ control of Pin 1 switches (for Vdiag and Vgnd) of DIAGMUX dedicated port */
#define CY_SAR_DIAGMUX_HW_CTRL_V2      (SAR_MUX_SWITCH_HW_CTRL2_MUX_FW_VD2_VG2_Msk)       /**< Enable SARSEQ control of Pin 2 switches (for Vdiag and Vgnd) of DIAGMUX dedicated port */
#define CY_SAR_DIAGMUX_HW_CTRL_V3      (SAR_MUX_SWITCH_HW_CTRL2_MUX_FW_VD3_VG3_Msk)       /**< Enable SARSEQ control of Pin 3 switches (for Vdiag and Vgnd) of DIAGMUX dedicated port */
#define CY_SAR_DIAGMUX_HW_CTRL_V4      (SAR_MUX_SWITCH_HW_CTRL2_MUX_FW_VD4_Msk)           /**< Enable SARSEQ control of DIAGMUX dedicated port */
#define CY_SAR_DIAGMUX_HW_CTRL_V5      (SAR_MUX_SWITCH_HW_CTRL2_MUX_FW_VD5_Msk)           /**< Enable SARSEQ control of DIAGMUX dedicated port */
#define CY_SAR_DIAGMUX_HW_CTRL_V6      (SAR_MUX_SWITCH_HW_CTRL2_MUX_FW_VD6_Msk)           /**< Enable SARSEQ control of DIAGMUX dedicated port */
#define CY_SAR_DIAGMUX_HW_CTRL_V7      (SAR_MUX_SWITCH_HW_CTRL2_MUX_FW_VD7_Msk)           /**< Enable SARSEQ control of DIAGMUX dedicated port */

#define CY_SAR_HW_CTRL_CSRC_VPLUS      (SAR_MUX_SWITCH_HW_CTRL2_MUX_FW_CSRC_VPLUS_Msk)    /**< Enable SARSEQ control of source current connected to vplus */
#define CY_SAR_HW_CTRL_CSRC_VMINUS     (SAR_MUX_SWITCH_HW_CTRL2_MUX_FW_CSRC_VMINUS_Msk)   /**< Enable SARSEQ control of source current connected to vminus */
#define CY_SAR_HW_CTRL_CSINK_VPLUS     (SAR_MUX_SWITCH_HW_CTRL2_MUX_FW_CSRC_VPLUS_Msk)    /**< Enable SARSEQ control of sink current connected to vplus */
#define CY_SAR_HW_CTRL_CSINK_VMINUS    (SAR_MUX_SWITCH_HW_CTRL2_MUX_FW_CSRC_VMINUS_Msk)   /**< Enable SARSEQ control of sink current connected to vminus */

/* EXPMUX/DIAG pins to Vplus */
#if (defined (CY_PASS0_SAR_EXPMUX_PRESENT) && (1U == CY_PASS0_SAR_EXPMUX_PRESENT)) || defined (CY_DOXYGEN)
#define CY_SAR_EXPMUX_FW_P0_VPLUS      (SAR_MUX_SWITCH2_MUX_FW_EXP_P0_VPLUS_Msk)    /**< Switch between Pin 0 of EXPMUX and Vplus of SARADC */
#define CY_SAR_EXPMUX_FW_P1_VPLUS      (SAR_MUX_SWITCH2_MUX_FW_EXP_P1_VPLUS_Msk)    /**< Switch between Pin 1 of EXPMUX and Vplus of SARADC */
#define CY_SAR_EXPMUX_FW_P2_VPLUS      (SAR_MUX_SWITCH2_MUX_FW_EXP_P2_VPLUS_Msk)    /**< Switch between Pin 2 of EXPMUX and Vplus of SARADC */
#define CY_SAR_EXPMUX_FW_P3_VPLUS      (SAR_MUX_SWITCH2_MUX_FW_EXP_P3_VPLUS_Msk)    /**< Switch between Pin 3 of EXPMUX and Vplus of SARADC */
#define CY_SAR_EXPMUX_FW_P4_VPLUS      (SAR_MUX_SWITCH2_MUX_FW_EXP_P4_VPLUS_Msk)    /**< Switch between Pin 4 of EXPMUX and Vplus of SARADC */
#define CY_SAR_EXPMUX_FW_P5_VPLUS      (SAR_MUX_SWITCH2_MUX_FW_EXP_P5_VPLUS_Msk)    /**< Switch between Pin 5 of EXPMUX and Vplus of SARADC */
#define CY_SAR_EXPMUX_FW_P6_VPLUS      (SAR_MUX_SWITCH2_MUX_FW_EXP_P6_VPLUS_Msk)    /**< Switch between Pin 6 of EXPMUX and Vplus of SARADC */
#define CY_SAR_EXPMUX_FW_P7_VPLUS      (SAR_MUX_SWITCH2_MUX_FW_EXP_P7_VPLUS_Msk)    /**< Switch between Pin 7 of EXPMUX and Vplus of SARADC */
#endif /* 1U == CY_PASS0_SAR_EXPMUX_PRESENT */
#define CY_SAR_DIAGMUX_FW_VD0_VPLUS    (SAR_MUX_SWITCH2_MUX_FW_VD0_VPLUS_Msk)       /**< Switch between internal Vdiag.0 and vplus of SARADC */
#define CY_SAR_DIAGMUX_FW_VD1_VPLUS    (SAR_MUX_SWITCH2_MUX_FW_VD1_VPLUS_Msk)       /**< Switch between internal Vdiag.1 and vplus of SARADC */
#define CY_SAR_DIAGMUX_FW_VD2_VPLUS    (SAR_MUX_SWITCH2_MUX_FW_VD2_VPLUS_Msk)       /**< Switch between internal Vdiag.2 and vplus of SARADC */
#define CY_SAR_DIAGMUX_FW_VD3_VPLUS    (SAR_MUX_SWITCH2_MUX_FW_VD3_VPLUS_Msk)       /**< Switch between internal Vdiag.3 and vplus of SARADC */
#define CY_SAR_DIAGMUX_FW_VD4_VPLUS    (SAR_MUX_SWITCH2_MUX_FW_VD4_VPLUS_Msk)       /**< Switch between internal Vdiag.4 and vplus of SARADC */
#define CY_SAR_DIAGMUX_FW_VD5_VPLUS    (SAR_MUX_SWITCH2_MUX_FW_VD5_VPLUS_Msk)       /**< Switch between internal Vdiag.5 and vplus of SARADC */
#define CY_SAR_DIAGMUX_FW_VD6_VPLUS    (SAR_MUX_SWITCH2_MUX_FW_VD6_VPLUS_Msk)       /**< Switch between internal Vdiag.6 and vplus of SARADC */
#define CY_SAR_DIAGMUX_FW_VD7_VPLUS    (SAR_MUX_SWITCH2_MUX_FW_VD7_VPLUS_Msk)       /**< Switch between internal Vdiag.7 and vplus of SARADC */

/* EXPMUX/DIAG pins to Vminus */
#if (defined (CY_PASS0_SAR_EXPMUX_PRESENT) && (1U == CY_PASS0_SAR_EXPMUX_PRESENT)) || defined (CY_DOXYGEN)
#define CY_SAR_EXPMUX_FW_P0_VMINUS    (SAR_MUX_SWITCH2_MUX_FW_EXP_P0_VMINUS_Msk) /**< Switch between Pin 0 of EXPMUX and Vminus of SARADC */
#define CY_SAR_EXPMUX_FW_P1_VMINUS    (SAR_MUX_SWITCH2_MUX_FW_EXP_P1_VMINUS_Msk) /**< Switch between Pin 1 of EXPMUX and Vminus of SARADC */
#define CY_SAR_EXPMUX_FW_P2_VMINUS    (SAR_MUX_SWITCH2_MUX_FW_EXP_P2_VMINUS_Msk) /**< Switch between Pin 2 of EXPMUX and Vminus of SARADC */
#define CY_SAR_EXPMUX_FW_P3_VMINUS    (SAR_MUX_SWITCH2_MUX_FW_EXP_P3_VMINUS_Msk) /**< Switch between Pin 3 of EXPMUX and Vminus of SARADC */
#define CY_SAR_EXPMUX_FW_P4_VMINUS    (SAR_MUX_SWITCH2_MUX_FW_EXP_P4_VMINUS_Msk) /**< Switch between Pin 4 of EXPMUX and Vminus of SARADC */
#define CY_SAR_EXPMUX_FW_P5_VMINUS    (SAR_MUX_SWITCH2_MUX_FW_EXP_P5_VMINUS_Msk) /**< Switch between Pin 5 of EXPMUX and Vminus of SARADC */
#define CY_SAR_EXPMUX_FW_P6_VMINUS    (SAR_MUX_SWITCH2_MUX_FW_EXP_P6_VMINUS_Msk) /**< Switch between Pin 6 of EXPMUX and Vminus of SARADC */
#define CY_SAR_EXPMUX_FW_P7_VMINUS    (SAR_MUX_SWITCH2_MUX_FW_EXP_P7_VMINUS_Msk) /**< Switch between Pin 7 of EXPMUX and Vminus of SARADC */
#endif /* 1U == CY_PASS0_SAR_EXPMUX_PRESENT */
#define CY_SAR_DIAGMUX_FW_VG0_VMINUS    (SAR_MUX_SWITCH2_MUX_FW_VG0_VMINUS_Msk)  /**< Switch between internal Vdiag.0 and Vminus of SARADC */
#define CY_SAR_DIAGMUX_FW_VG1_VMINUS    (SAR_MUX_SWITCH2_MUX_FW_VG1_VMINUS_Msk)  /**< Switch between internal Vdiag.1 and Vminus of SARADC */
#define CY_SAR_DIAGMUX_FW_VG2_VMINUS    (SAR_MUX_SWITCH2_MUX_FW_VG2_VMINUS_Msk)  /**< Switch between internal Vdiag.2 and Vminus of SARADC */
#define CY_SAR_DIAGMUX_FW_VG3_VMINUS    (SAR_MUX_SWITCH2_MUX_FW_VG3_VMINUS_Msk)  /**< Switch between internal Vdiag.3 and Vminus of SARADC */

#define CY_SAR_DIAGMUX_FW_CSRC_VPLUS    (SAR_MUX_SWITCH2_MUX_FW_CSRC_VPLUS_Msk)  /**< switch between 10uA current source and the vplus signal */
#define CY_SAR_DIAGMUX_FW_CSINK_VPLUS   (SAR_MUX_SWITCH2_MUX_FW_CSINK_VPLUS_Msk) /**< switch between 10uA current sink and the vplus signal */
#define CY_SAR_DIAGMUX_FW_CSRC_VMINUS   (SAR_MUX_SWITCH2_MUX_FW_CSRC_VMINUS_Msk) /**< switch between 10uA current source and the vminus signal */
#define CY_SAR_DIAGMUX_FW_CSINK_VMINUS  (SAR_MUX_SWITCH2_MUX_FW_CSINK_VMINUS_Msk)/**< switch between 10uA current sink and the vminus signal */
#endif /* 4U <= CY_IP_M0S8PASS4A_SAR_VERSION */

/** \} group_sar_diag_exp_mux_switch */

/** \} group_sar_macro */

/** \addtogroup group_sar_enums
* \{
*/

/******************************************************************************
 * Enumerations
 *****************************************************************************/

/** The SAR status/error code definitions */
typedef enum
{
    CY_SAR_SUCCESS    = 0x00UL,                                              /**< Success */
    CY_SAR_BAD_PARAM  = CY_SAR_ID | CY_PDL_STATUS_ERROR | 0x01UL,            /**< Invalid input parameters */
    CY_SAR_TIMEOUT    = CY_SAR_ID | CY_PDL_STATUS_ERROR | 0x02UL,            /**< A timeout occurred */
    CY_SAR_CONVERSION_NOT_COMPLETE = CY_SAR_ID | CY_PDL_STATUS_INFO | 0x03UL /**< SAR conversion is not complete */
} cy_en_sar_status_t;

/** Definitions for starting a conversion used in \ref Cy_SAR_StartConvert */
typedef enum
{
    CY_SAR_START_CONVERT_SINGLE_SHOT = 0UL, /**< Start a single scan (one shot) from firmware */
    CY_SAR_START_CONVERT_CONTINUOUS  = 1UL, /**< Continuously scan enabled channels and ignores all triggers, firmware or hardware */
} cy_en_sar_start_convert_sel_t;

/** Definitions for the return mode used in \ref Cy_SAR_IsEndConversion */
typedef enum
{
    CY_SAR_RETURN_STATUS       = 0UL,    /**< Immediately returns the conversion status. */
    CY_SAR_WAIT_FOR_RESULT     = 1UL,    /**< Does not return a result until the conversion of all sequential channels is complete. This mode is blocking. */
    CY_SAR_RETURN_STATUS_INJ   = 2UL,    /**< Immediately returns the conversion status of the injection channel. */
    CY_SAR_WAIT_FOR_RESULT_INJ = 3UL     /**< Does not return a result until the conversion of injection channels is complete. This mode is blocking. */
} cy_en_sar_return_mode_t;

/** Reference voltage selection definitions */
typedef enum
{
    CY_SAR_VREF_SEL_BGR         = 4UL,  /**< 1.2V from BandGap (VREF buffer on) */
    CY_SAR_VREF_SEL_EXT         = 5UL,  /**< External precision Vref direct from a pin (low impedance path) */
    CY_SAR_VREF_SEL_VDDA_DIV_2  = 6UL,  /**< Vdda/2  (VREF buffer on) */
    CY_SAR_VREF_SEL_VDDA        = 7UL   /**< Vdda */
} cy_en_sar_ctrl_vref_sel_t;


/** Negative terminal (Vminus) selection definitions for single-ended channels.
*
* The Vminus input for single ended channels can be connected to
* Vref, VSSA, or routed out to an external pin.
* The options for routing to a pin are through Pin 1, Pin 3, Pin 5, or Pin 7
* of the SARMUX dedicated port or an acore wire in AROUTE, if available on the device.
*
* \ref CY_SAR_NEG_SEL_VSSA_KELVIN comes straight from a Vssa pad without any shared branches
* so that to keep quiet and avoid voltage drops.
*/
typedef enum
{
    CY_SAR_NEG_SEL_VSSA_KELVIN  = 0UL,  /**< Connect Vminus to VSSA_KELVIN */
    CY_SAR_NEG_SEL_ART_VSSA     = 1UL,
    CY_SAR_NEG_SEL_P1           = 2UL,  /**< Connect Vminus to Pin 1 of SARMUX dedicated port */
    CY_SAR_NEG_SEL_P3           = 3UL,  /**< Connect Vminus to Pin 3 of SARMUX dedicated port */
    CY_SAR_NEG_SEL_P5           = 4UL,  /**< Connect Vminus to Pin 5 of SARMUX dedicated port */
    CY_SAR_NEG_SEL_P7           = 5UL,  /**< Connect Vminus to Pin 7 of SARMUX dedicated port */
    CY_SAR_NEG_SEL_ACORE        = 6UL,  /**< Connect Vminus to an ACORE in AROUTE */
    CY_SAR_NEG_SEL_VREF         = 7UL   /**< Connect Vminus to VREF input of SARADC */
}cy_en_sar_ctrl_neg_sel_t;

/** Enable hardware control of the switch between Vref and the Vminus input */
typedef enum
{
    CY_SAR_NEGVREF_FW_ONLY = 0UL,    /**< Only firmware control of the switch */
    CY_SAR_NEGVREF_HW      = 1UL     /**< Enable hardware control of the switch */
} cy_en_sar_ctrl_hw_ctrl_negvref_t;

/** Power mode */
typedef enum
{
    CY_SAR_NORMAL_PWR  = 0UL, /**< Normal power (default), max clk_sar is 18MHz. */
    CY_SAR_HALF_PWR    = 1UL, /**< 1/2 power mode, max clk_sar is 9MHz. */
    CY_SAR_MORE_PWR    = 2UL, /**< 1.333 power mode, max clk_sar is 18MHz. */
    CY_SAR_QUARTER_PWR = 3UL  /**< 1/4 power mode, max clk_sar is 4.5MHz. */
} cy_en_sar_ctrl_pwr_t;

/** DSI mode */
typedef enum
{
    CY_SAR_DSI_MODE_NORMAL  = 0UL, /**< SAR sequencer operates according to CHAN_EN enables and CHAN_CONFIG channel configurations */
    CY_SAR_DSI_MODE_IGNORED = 1UL  /**< CHAN_EN, INJ_START_EN and channel configurations in CHAN_CONFIG and INJ_CHAN_CONFIG are ignored */
} cy_en_sar_sample_ctrl_dsi_mode_t;

/** SubResolution */
typedef enum
{
    CY_SAR_SUB_RESOLUTION_8B = 0UL,
    CY_SAR_SUB_RESOLUTION_10B = 1UL
} cy_en_sar_sample_ctrl_sub_resolution_t;


/** Configure number of samples for averaging.
* This applies only to channels with averaging enabled.
*/
typedef enum
{
    CY_SAR_AVG_CNT_2          = 0UL,    /**< Set samples averaged to 2 */
    CY_SAR_AVG_CNT_4          = 1UL,    /**< Set samples averaged to 4 */
    CY_SAR_AVG_CNT_8          = 2UL,    /**< Set samples averaged to 8 */
    CY_SAR_AVG_CNT_16         = 3UL,    /**< Set samples averaged to 16 */
    CY_SAR_AVG_CNT_32         = 4UL,    /**< Set samples averaged to 32 */
    CY_SAR_AVG_CNT_64         = 5UL,    /**< Set samples averaged to 64 */
    CY_SAR_AVG_CNT_128        = 6UL,    /**< Set samples averaged to 128 */
    CY_SAR_AVG_CNT_256        = 7UL     /**< Set samples averaged to 256 */
} cy_en_sar_sample_ctrl_avg_cnt_t;

#if (defined (CY_IP_M0S8PASS4A_SAR_VERSION) && (4U <= CY_IP_M0S8PASS4A_SAR_VERSION)) || defined (CY_DOXYGEN)
/** Configure the averaging mode.
* \note This applies only to the PSoC HV device family.
*/
typedef enum
{
    CY_SAR_AVG_MODE_ACCUNDUMP          = 0UL,   /**< Accumulate and Dump (1st order accumulate and dump filter): a channel will be sampled back to back and averaged  */
    CY_SAR_AVG_MODE_INTERLEAVED        = 1UL    /**< Interleaved: On each scan (trigger) one sample is taken per channel and averaged over several scans.  */
} cy_en_sar_sample_ctrl_avg_mode_t;
#endif /* 4U <= CY_IP_M0S8PASS4A_SAR_VERSION */

/** Configure the trigger mode.
*
* Firmware triggering is always enabled and can be single shot or continuous.
* Additionally, hardware triggering can be enabled with the option to be
* edge or level sensitive.
*/
typedef enum
{
    CY_SAR_TRIGGER_MODE_FW_ONLY        = 0UL, /**< Firmware trigger only, disable hardware trigger*/
    CY_SAR_TRIGGER_MODE_FW_AND_HWEDGE  = 1UL, /**< Enable edge sensitive hardware trigger. Each rising edge will trigger a single scan. */
    CY_SAR_TRIGGER_MODE_FW_AND_HWLEVEL = 3UL  /**< Enable level sensitive hardware trigger. The SAR will continuously scan while the trigger signal is high. */
} cy_en_sar_sample_ctrl_trigger_mode_t;

/* \} */


/* \} */

/** \addtogroup group_sar_range_thres_register_enums
* This set of enumerations aids in configuring the SAR RANGE* registers
* \{
*/
/** Configure the lower and upper thresholds for range detection
*
* The SARSEQ supports range detection to allow for automatic detection of sample
* values compared to two programmable thresholds without CPU involvement.
* Range detection is defined by two global thresholds and a condition.
* The RANGE_LOW value defines the lower threshold and RANGE_HIGH defines
* the upper threshold of the range.
*
* Range detect is done after averaging, alignment, and sign extension (if applicable).
* In other words, the thresholds values must have the same data format as the result data.
* Range detection is always done for all channels scanned. By making RANGE_INTR_MASK=0,
* the firmware can choose to ignore the range detect interrupt for any channel.
*/

/** Configure the condition (below, inside, above, or outside) of the range detection interrupt */
typedef enum
{
    CY_SAR_RANGE_COND_BELOW     = 0UL,  /**< Range interrupt detected when result < RANGE_LOW */
    CY_SAR_RANGE_COND_INSIDE    = 1UL,  /**< Range interrupt detected when RANGE_LOW <= result < RANGE_HIGH */
    CY_SAR_RANGE_COND_ABOVE     = 2UL,  /**< Range interrupt detected when RANGE_HIGH <= result */
    CY_SAR_RANGE_COND_OUTSIDE   = 3UL   /**< Range interrupt detected when result < RANGE_LOW || RANGE_HIGH <= result */
} cy_en_sar_range_detect_condition_t;
/* \} */

/** \addtogroup group_sar_chan_config_register_enums
* This set of enumerations aids in configuring the SAR CHAN_CONFIG and INJ_CHAN_CONFIG registers
* \{
*/
/** Configure the input mode of the channel
*
* - Single ended channel: the \ref cy_en_sar_ctrl_neg_sel_t selection in the group_sar_init_struct_ctrl register
*   determines what drives the Vminus pin
* - Differential: Vplus and Vminus are a pair. Bit 0 of \ref cy_en_sar_chan_config_port_pin_addr_t
*   is ignored and considered to be 0.
*   In other words, \ref cy_en_sar_chan_config_port_pin_addr_t points to the even pin of a pin pair.
*   The even pin is connected to Vplus and the next odd pin is connected to Vminus.
* - Extended differential: the \ref cy_en_sar_chan_config_neg_port_pin_addr_t selection
*   determines what drives the Vminus pin (if NEG_ADDR_EN =1)
*/

/** Configure address of the port and the pin connected to the Vplus terminal of the SARADC
* See the \ref group_sar_sarmux section for more guidance.
*/
typedef enum
{
    CY_SAR_ADDR_SARMUX_0         = 0x0UL,  /**< Dedicated SARMUX pin 0 */
    CY_SAR_ADDR_SARMUX_1         = 0x1UL,  /**< Dedicated SARMUX pin 1, valid for single ended channels only */
    CY_SAR_ADDR_SARMUX_2         = 0x2UL,  /**< Dedicated SARMUX pin 2 */
    CY_SAR_ADDR_SARMUX_3         = 0x3UL,  /**< Dedicated SARMUX pin 3, valid for single ended channels only */
    CY_SAR_ADDR_SARMUX_4         = 0x4UL,  /**< Dedicated SARMUX pin 4 */
    CY_SAR_ADDR_SARMUX_5         = 0x5UL,  /**< Dedicated SARMUX pin 5, valid for single ended channels only */
    CY_SAR_ADDR_SARMUX_6         = 0x6UL,  /**< Dedicated SARMUX pin 6 */
    CY_SAR_ADDR_SARMUX_7         = 0x7UL,  /**< Dedicated SARMUX pin 7, valid for single ended channels only */
    CY_SAR_ADDR_CTB0_OA0         = 0x12UL,  /**< CTB0 OA0 output, if present */
    CY_SAR_ADDR_CTB0_OA1         = 0x13UL,  /**< CTB0 OA1 output, if present */
    CY_SAR_ADDR_CTB1_OA0         = 0x22UL,  /**< CTB1 OA0 output, if present */
    CY_SAR_ADDR_CTB1_OA1         = 0x23UL,  /**< CTB1 OA1 output, if present */
    CY_SAR_ADDR_CTB2_OA0         = 0x32UL,  /**< CTB2 OA0 output, if present */
    CY_SAR_ADDR_CTB2_OA1         = 0x33UL,  /**< CTB2 OA1 output, if present */
    CY_SAR_ADDR_CTB3_OA0         = 0x42UL,  /**< CTB3 OA0 output, if present */
    CY_SAR_ADDR_CTB3_OA1         = 0x43UL,  /**< CTB3 OA1 output, if present */
#if (defined (PASS0_SAR_EXPMUX_PRESENT) && (1U == PASS0_SAR_EXPMUX_PRESENT)) || defined (CY_DOXYGEN)
    CY_SAR_ADDR_EXPMUX_0         = 0x50UL,  /**< GPIO Expansion Mux pin 0, if present */
    CY_SAR_ADDR_EXPMUX_1         = 0x51UL,  /**< GPIO Expansion Mux pin 1, if present */
    CY_SAR_ADDR_EXPMUX_2         = 0x52UL,  /**< GPIO Expansion Mux pin 2, if present */
    CY_SAR_ADDR_EXPMUX_3         = 0x53UL,  /**< GPIO Expansion Mux pin 3, if present */
    CY_SAR_ADDR_EXPMUX_4         = 0x54UL,  /**< GPIO Expansion Mux pin 4, if present */
    CY_SAR_ADDR_EXPMUX_5         = 0x55UL,  /**< GPIO Expansion Mux pin 5, if present */
    CY_SAR_ADDR_EXPMUX_6         = 0x56UL,  /**< GPIO Expansion Mux pin 6, if present */
    CY_SAR_ADDR_EXPMUX_7         = 0x57UL,  /**< GPIO Expansion Mux pin 7, if present */
#endif /* PASS0_SAR_EXPMUX_PRESENT */
#if (defined (CY_IP_M0S8PASS4A_SAR_VERSION) && (4U <= CY_IP_M0S8PASS4A_SAR_VERSION)) || defined (CY_DOXYGEN)
    CY_SAR_ADDR_DIAG_GND         = 0x60UL,  /**< Diagnostic Mux VSSA, if present */
    CY_SAR_ADDR_DIAG_SRSS_BGR    = 0x61UL,  /**< Diagnostic Mux SRSS bandgap voltage, if present */
    CY_SAR_ADDR_DIAG_VBAT_DIV_24 = 0x63UL,  /**< Diagnostic Mux VBAT/24 from HVDIV, if present */
    CY_SAR_ADDR_DIAG_VCC_DIV_2   = 0x66UL,  /**< Diagnostic Mux VCC/2, if present */
    CY_SAR_ADDR_DIAG_VDD_DIV_6   = 0x67UL,  /**< Diagnostic Mux VDD/6, if present */
#endif /* 4U <= CY_IP_M0S8PASS4A_SAR_VERSION */
    CY_SAR_ADDR_SARMUX_DIE_TEMP  = 0x70UL,  /**< SARMUX virtual port for DieTemp */
    CY_SAR_ADDR_SARMUX_AMUXBUS_A = 0x72UL,  /**< SARMUX virtual port for AMUXBUSA */
    CY_SAR_ADDR_SARMUX_AMUXBUS_B = 0x73UL   /**< SARMUX virtual port for AMUXBUSB */
} cy_en_sar_chan_config_port_pin_addr_t;

#if (defined (CY_IP_M0S8PASS4A_SAR_VERSION) && (4U <= CY_IP_M0S8PASS4A_SAR_VERSION)) || defined (CY_DOXYGEN)
/** Configure the address of the port and the pin connected to the Vminus terminal of the SARADC.
* See the \ref group_sar_sarmux section for more guidance.
*/
typedef enum
{
    CY_SAR_NEG_ADDR_SARMUX_0            = 0x0UL,  /**< Dedicated SARMUX pin 0 */
    CY_SAR_NEG_ADDR_SARMUX_1            = 0x1UL,  /**< Dedicated SARMUX pin 1 */
    CY_SAR_NEG_ADDR_SARMUX_2            = 0x2UL,  /**< Dedicated SARMUX pin 2 */
    CY_SAR_NEG_ADDR_SARMUX_3            = 0x3UL,  /**< Dedicated SARMUX pin 3 */
    CY_SAR_NEG_ADDR_SARMUX_4            = 0x4UL,  /**< Dedicated SARMUX pin 4 */
    CY_SAR_NEG_ADDR_SARMUX_5            = 0x5UL,  /**< Dedicated SARMUX pin 5 */
    CY_SAR_NEG_ADDR_SARMUX_6            = 0x6UL,  /**< Dedicated SARMUX pin 6 */
    CY_SAR_NEG_ADDR_SARMUX_7            = 0x7UL,  /**< Dedicated SARMUX pin 7 */
#if (defined (CY_PASS0_SAR_EXPMUX_PRESENT) && (1U == CY_PASS0_SAR_EXPMUX_PRESENT)) || defined (CY_DOXYGEN)
    CY_SAR_NEG_ADDR_EXPMUX_0            = 0x50UL,  /**< GPIO Expansion Mux pin 0, if present */
    CY_SAR_NEG_ADDR_EXPMUX_1            = 0x51UL,  /**< GPIO Expansion Mux pin 1, if present */
    CY_SAR_NEG_ADDR_EXPMUX_2            = 0x52UL,  /**< GPIO Expansion Mux pin 2, if present */
    CY_SAR_NEG_ADDR_EXPMUX_3            = 0x53UL,  /**< GPIO Expansion Mux pin 3, if present */
    CY_SAR_NEG_ADDR_EXPMUX_4            = 0x54UL,  /**< GPIO Expansion Mux pin 4, if present */
    CY_SAR_NEG_ADDR_EXPMUX_5            = 0x55UL,  /**< GPIO Expansion Mux pin 5, if present */
    CY_SAR_NEG_ADDR_EXPMUX_6            = 0x56UL,  /**< GPIO Expansion Mux pin 6, if present */
    CY_SAR_NEG_ADDR_EXPMUX_7            = 0x57UL,  /**< GPIO Expansion Mux pin 7, if present */
#endif /* (#if(1U == CY_PASS0_SAR_EXPMUX_PRESENT)) */
    CY_SAR_NEG_ADDR_DIAG_VSSA           = 0x60UL,  /**< Diagnostic Mux VSSA */
    CY_SAR_NEG_ADDR_DIAG_VSSD           = 0x61UL,  /**< Diagnostic Mux VSSD */
    CY_SAR_NEG_ADDR_SARMUX_AMUXBUS_A    = 0x72UL,  /**< SARMUX virtual port for AMUXBUS-A */
    CY_SAR_NEG_ADDR_SARMUX_AMUXBUS_B    = 0x73UL   /**< SARMUX virtual port for AMUXBUS-B */
} cy_en_sar_chan_config_neg_port_pin_addr_t;
#endif /* 4U <= CY_IP_M0S8PASS4A_SAR_VERSION */

/** Resolution */
typedef enum
{
    CY_SAR_MAX_RES               = 0UL,     /**< Maximum 12b resolution */
    CY_SAR_SUB_RES               = 1UL      /**< Reduced resolution, defined by \ref cy_en_sar_sample_ctrl_sub_resolution_t */
} cy_en_sar_channel_ctrl_resolution_t;

/** Sampling Timer selection */
typedef enum
{
    CY_SAR_SAMPLE_TIME_0         = 0,       /**< Sampling Timer 0 */
    CY_SAR_SAMPLE_TIME_1         = 1,       /**< Sampling Timer 1 */
    CY_SAR_SAMPLE_TIME_2         = 2,       /**< Sampling Timer 2 */
    CY_SAR_SAMPLE_TIME_3         = 3        /**< Sampling Timer 3 */
} cy_en_sar_channel_sampletime_t;

/* \} */

/** \addtogroup group_sar_data_structures
* \{
*/

/** Channel configuration structure */
typedef struct
{
    cy_en_sar_chan_config_port_pin_addr_t addr;           /**< The combined SARMUX port address and pin address value. */
    bool differential;                                    /**< Differential enable for this channel.
                                                           *   - false: The voltage on the addressed pin is measured (Single-ended)
                                                           *   and the resulting value is stored in the corresponding data register.
                                                           *   - true: The differential voltage on the addressed pin pair is measured
                                                           *   and the resulting value is stored in the corresponding data register. (pinAddr[0] is ignored).
                                                           */
    cy_en_sar_channel_ctrl_resolution_t resolution;       /**< Resolution for this channel.  When AVG_EN is set this bit is ignored and
                                                           * always a 12-bit resolution (or highest resolution allowed by wounding) is used for this channel.
                                                           */
    bool avgEn;                                           /**< Averaging enable for this channel. If set the avgCnt and avgShift settings are used for sampling the addressed pin(s) */
    cy_en_sar_channel_sampletime_t sampleTimeSel;         /**< Sample time select: select which of the 4 global sample times to use for this channel */
    bool rangeIntrEn;                                     /**< Range detection interrupt enable */
    bool satIntrEn;                                       /**< Saturation detection interrupt enable */
#if (defined (CY_IP_M0S8PASS4A_SAR_VERSION) && (4U <= CY_IP_M0S8PASS4A_SAR_VERSION)) || defined (CY_DOXYGEN)
    cy_en_sar_chan_config_neg_port_pin_addr_t neg_addr;   /**< The combined SARMUX negative port address and pin address value. */
    bool negAddrEn;                                       /**< Enable addressing negative pin for new differential mode */
    bool diagVplusSource;                                 /**< Diagnostic broken wire Vplus source current */
    bool diagVplusSink;                                   /**< Diagnostic broken wire Vplus sink current */
    bool diagVminusSoure;                                 /**< Diagnostic broken wire Vminus source current */
    bool diagVminusSink;                                  /**< Diagnostic broken wire Vminus sink current */
#endif /* 4U <= CY_IP_M0S8PASS4A_SAR_VERSION */
} cy_stc_sar_channel_config_t;

/** Routing Configuration */
typedef struct
{
    uint32_t muxSwitch;                                   /**< SARMUX firmware switches to connect analog signals to SAR */
    uint32_t muxSwitchHwCtrl;                             /**< Enable SARSEQ control of specific SARMUX switches */
#if (defined (CY_IP_M0S8PASS4A_SAR_VERSION) && (4u <= CY_IP_M0S8PASS4A_SAR_VERSION)) || defined (CY_DOXYGEN)
    uint32_t muxSwitch2;                                  /**< Firmware control for EXPMUX and DIAGMUX switches to connect analog signals to the SAR */
    uint32_t muxSwitchHwCtrl2;                            /**< Allow SARSEQ control for EXPMUX and DIAGMUX switches */
#endif /* 4u <= CY_IP_M0S8PASS4A_SAR_VERSION */
} cy_stc_sar_routing_config_t;

/** This structure is used to initialize the SAR ADC subsystem.
*
* The SAR ADC subsystem is highly configurable with many options.
* When calling \ref Cy_SAR_Init, provide a pointer to the structure containing this configuration data.
* A set of enumerations is provided in this
* driver to help with configuring this structure.
*
* See the \ref group_sar_initialization section for guidance.
**/
typedef struct
{
    cy_en_sar_ctrl_vref_sel_t vrefSel;                    /**< Internal VREF selection */
    bool vrefBypCapEn;                                    /**< VREF bypass cap enable for when VREF buffer is on */
    cy_en_sar_ctrl_neg_sel_t negSel;                      /**< Internal NEG selection for Single ended conversion */
    cy_en_sar_ctrl_hw_ctrl_negvref_t negVref;             /**< Hardware control of the VREF to NEG switch */
    bool boostPump;                                       /**< Internal pump:
                                                           *   false = disabled/bypassed, pump output is VDDA,
                                                           *   true = enabled, pump output is boosted.
                                                           */
    cy_en_sar_ctrl_pwr_t power;                           /**< Power mode */
    bool sarMuxDsEn;                                      /**< Enable SarMux during Deep Sleep cycle */
    bool switchDisable;                                   /**< Disable SAR sequencer from enabling routing switches (note DSI and firmware can always close switches independent of this control) */
    cy_en_sar_sample_ctrl_sub_resolution_t subResolution; /**< Conversion resolution for channels that have sub-resolution enabled */
    bool leftAlign;                                       /**< Left align data in data[15:0], default data is right aligned in data[11:0], with sign extension to 16 bits if the channel is differential. */
    bool singleEndedSigned;                               /**< Output data from a single ended conversion as a signed value */
    bool differentialSigned;                              /**< Output data from a differential conversion as a signed value */
    cy_en_sar_sample_ctrl_avg_cnt_t avgCnt;               /**< Averaging Count for channels that have over sampling enabled (avgEn = true).
                                                           *   A channel will be sampled back to back avgCnt times before the result is stored and
                                                           *   the next enabled channel is sampled (1st order accumulate and dump filter).
                                                           *   If shifting is not enabled (avgShift = true) then the result is forced to shift right so that is fits in 16 bits,
                                                           *   so right shift is done by max(0,AVG_CNT-3).
                                                           */
    bool avgShift;                                        /**< Averaging shifting: after averaging the result is shifted right to fit in the sample resolution.
                                                           *   For averaging the sample resolution is the highest resolution allowed by wounding.
                                                           */
    cy_en_sar_sample_ctrl_trigger_mode_t trigMode;        /**< Trigger Mode: FW only, edge or level sensitive */
    bool eosEn;                                           /**< Enable to output EOS_INTR to trigger output. When enabled each time EOS_INTR is set by the hardware also a pulse is send on the trigger signal. */
    uint32_t sampleTime0;                                 /**< Sample time in ADC clocks for Sample Time 0.
                                                           *   For all the sampleTimeX fields, valid range is 2 - 1023 cycles.
                                                           *   The minimum aperture time is 194 ns. With an 18 MHz ADC clock, this is
                                                           *   equal to 3.5 cycles or a value of 4 in this field.
                                                           *   The actual aperture time is half cycle less than the value stored in this field.
                                                           */
    uint32_t sampleTime1;                                 /**< Sample time in ADC clocks for Sample Time 1 */
    uint32_t sampleTime2;                                 /**< Sample time in ADC clocks for Sample Time 2 */
    uint32_t sampleTime3;                                 /**< Sample time in ADC clocks for Sample Time 3 */
    uint32_t rangeThresLow;                               /**< Range detect low threshold for all channels. Used to generate range interrupt.
                                                           *   Range detection for both rangeThresLow and rangeThresHigh is done after averaging, alignment, and sign extension (if applicable),
                                                           *   i.e. threshold values need to have the same data format as the result data.
                                                           *   The values are interpreted as signed or unsigned according to each channel's configuration */
    uint32_t rangeThresHigh;                              /**< Range detect high threshold for all channels. Used to generate range interrupt */
    cy_en_sar_range_detect_condition_t rangeCond;         /**< Range detect condition (below, inside, output, or above) for all channels. Used to generate range interrupt */
    uint32_t chanEn;                                      /**< Enable bits for the channels.
                                                            *  All the sequential channels bits are within \ref CY_SAR_CHANNELS_MASK,
                                                            *  the injection channel mask is \ref CY_SAR_INJ_CHAN_MASK.
                                                            */
    const cy_stc_sar_channel_config_t * channelConfig[CY_SAR_NUM_CHANNELS]; /**< Pointers to channel configuration structures, NULL means the channel is not configured */
    const cy_stc_sar_routing_config_t * routingConfig;    /**< Pointer to the routing configuration structure. Can be NULL in case of no need to configure the routing */
    uint32_t vrefMvValue;                                 /**< Reference voltage in millivolts used in converting counts to volts */
} cy_stc_sar_config_t;

/** This structure is used by the driver to backup the state of the SAR
* before entering sleep so that it can be re-enabled after waking up */
typedef struct
{
    uint32_t hwEnabled;                                 /**< SAR enabled state */
    uint32_t continuous;                                /**< State of the continuous bit */
} cy_stc_sar_state_backup_t;

/** \} group_sar_data_structures */

/** \addtogroup group_sar_functions
* \{
*/

/***************************************
*        Function Prototypes
***************************************/

/** \addtogroup group_sar_functions_basic
* This set of functions is for initialization and basic usage
* \{
*/
cy_en_sar_status_t Cy_SAR_Init(SAR_Type * base, const cy_stc_sar_config_t *config);
cy_en_sar_status_t Cy_SAR_DeInit(SAR_Type * base, bool deInitRouting);
void Cy_SAR_Enable(SAR_Type * base);
void Cy_SAR_Disable(SAR_Type * base);
void Cy_SAR_StartConvert(SAR_Type * base, cy_en_sar_start_convert_sel_t startSelect);
void Cy_SAR_StopConvert(SAR_Type * base);
cy_en_sar_status_t Cy_SAR_IsEndConversion(SAR_Type * base, cy_en_sar_return_mode_t retMode);
bool Cy_SAR_GetBusyStatus(const SAR_Type * base);
int16_t Cy_SAR_GetResult16(const SAR_Type * base, uint32_t chan);
int32_t Cy_SAR_GetResult32(const SAR_Type * base, uint32_t chan);
__STATIC_INLINE uint32_t Cy_SAR_GetChanResultUpdated(const SAR_Type * base);
__STATIC_INLINE void Cy_SAR_EnableInjection(SAR_Type * base, bool tailgating);
__STATIC_INLINE void Cy_SAR_EnableChannels(SAR_Type * base, uint32_t chanMask);
__STATIC_INLINE void Cy_SAR_DisableChannels(SAR_Type * base, uint32_t chanMask);
/** \} */

/** \addtogroup group_sar_functions_power
* This set of functions is for Deep Sleep entry and exit
* \{
*/
cy_en_syspm_status_t Cy_SAR_DeepSleepCallback(cy_stc_syspm_callback_params_t *callbackParams, cy_en_syspm_callback_mode_t mode);
void Cy_SAR_DeepSleep(SAR_Type * base);
void Cy_SAR_Wakeup(SAR_Type * base);
/** \} */

/** \addtogroup group_sar_functions_config
* This set of functions allows changes to the SAR configuration
* after initialization.
* \{
*/
void Cy_SAR_SetConvertMode(SAR_Type * base, cy_en_sar_sample_ctrl_trigger_mode_t mode);
__STATIC_INLINE void Cy_SAR_SetChanMask(SAR_Type * base, uint32_t enableMask);
__STATIC_INLINE uint32_t Cy_SAR_GetChanMask(SAR_Type * base);
void Cy_SAR_SetLowLimit(SAR_Type * base, uint32_t lowLimit);
void Cy_SAR_SetHighLimit(SAR_Type * base, uint32_t highLimit);
void Cy_SAR_SetVref(SAR_Type *base, cy_en_sar_ctrl_vref_sel_t vrefSel);
__STATIC_INLINE void Cy_SAR_SetRangeCond(SAR_Type * base, cy_en_sar_range_detect_condition_t cond);
#if (defined (CY_IP_M0S8PASS4A_SAR_VERSION) && (4U <= CY_IP_M0S8PASS4A_SAR_VERSION)) || defined (CY_DOXYGEN)
__STATIC_INLINE void Cy_SAR_SetAveragingMode(SAR_Type * base, cy_en_sar_sample_ctrl_avg_mode_t mode);
#endif /* 4U <= CY_IP_M0S8PASS4A_SAR_VERSION */
/** \} */

/** \addtogroup group_sar_functions_countsto
* This set of functions performs counts to *volts conversions.
* \{
*/
int16_t Cy_SAR_RawCounts2Counts(const SAR_Type * base, uint32_t chan, int16_t adcCounts);
float32_t Cy_SAR_CountsTo_Volts(const SAR_Type * base, uint32_t chan, int16_t adcCounts);
int16_t Cy_SAR_CountsTo_mVolts(const SAR_Type * base, uint32_t chan, int16_t adcCounts);
int32_t Cy_SAR_CountsTo_uVolts(const SAR_Type * base, uint32_t chan, int16_t adcCounts);
int16_t Cy_SAR_CountsTo_degreeC(const SAR_Type * base, uint32_t chan, int16_t adcCounts);
#if defined (SFLASH_HAS_DYNAMIC_IMO)
int16_t Cy_SAR_CountsTo_tenthDegreeC(const SAR_Type *base, uint32_t chan, int16_t adcCounts);
#endif
cy_en_sar_status_t Cy_SAR_SetChannelOffset(const SAR_Type * base, uint32_t chan, int16_t offsetCount);
cy_en_sar_status_t Cy_SAR_SetChannelGain(const SAR_Type * base, uint32_t chan, int32_t adcGain);
/** \} */

/** \addtogroup group_sar_functions_switches
* This set of functions is for controlling/querying the SARMUX switches
* \{
*/
void Cy_SAR_SetAnalogSwitch(SAR_Type * base, uint32_t switchMask, bool state);
uint32_t Cy_SAR_GetAnalogSwitch(const SAR_Type * base);
__STATIC_INLINE void Cy_SAR_SetVssaVminusSwitch(SAR_Type * base, bool state);
void Cy_SAR_SetSwitchSarSeqCtrl(SAR_Type * base, uint32_t switchMask, bool ctrl);
__STATIC_INLINE void Cy_SAR_SetVssaSarSeqCtrl(SAR_Type * base, bool ctrl);
#if (defined (CY_IP_M0S8PASS4A_SAR_VERSION) && (4u <= CY_IP_M0S8PASS4A_SAR_VERSION)) || defined (CY_DOXYGEN)
void Cy_SAR_SetDiagSwitch(const SAR_Type * base, uint32_t mask, bool setSwitch);
uint32_t Cy_SAR_GetDiagSwitch(const SAR_Type * base);
void Cy_SAR_SetDiagHwCtrl(volatile SAR_Type * base, uint32_t mask);
uint32_t Cy_SAR_GetDiagHwCtrl(const SAR_Type * base);
#endif /* 4u <= CY_IP_M0S8PASS4A_SAR_VERSION */
/** \} */

/** \addtogroup group_sar_functions_interrupt
* This set of functions are related to SAR interrupts.
* \{
*/
__STATIC_INLINE uint32_t Cy_SAR_GetInterruptStatus(const SAR_Type * base);
__STATIC_INLINE void Cy_SAR_ClearInterrupt(SAR_Type * base, uint32_t intrMask);
__STATIC_INLINE void Cy_SAR_SetInterrupt(SAR_Type * base, uint32_t intrMask);
__STATIC_INLINE void Cy_SAR_SetInterruptMask(SAR_Type * base, uint32_t intrMask);
__STATIC_INLINE uint32_t Cy_SAR_GetInterruptMask(const SAR_Type * base);
__STATIC_INLINE uint32_t Cy_SAR_GetInterruptStatusMasked(const SAR_Type * base);

__STATIC_INLINE uint32_t Cy_SAR_GetRangeInterruptStatus(const SAR_Type * base);
__STATIC_INLINE void Cy_SAR_ClearRangeInterrupt(SAR_Type * base, uint32_t chanMask);
__STATIC_INLINE void Cy_SAR_SetRangeInterrupt(SAR_Type * base, uint32_t chanMask);
__STATIC_INLINE void Cy_SAR_SetRangeInterruptMask(SAR_Type * base, uint32_t chanMask);
__STATIC_INLINE uint32_t Cy_SAR_GetRangeInterruptMask(const SAR_Type * base);
__STATIC_INLINE uint32_t Cy_SAR_GetRangeInterruptStatusMasked(const SAR_Type * base);

__STATIC_INLINE uint32_t Cy_SAR_GetSatInterruptStatus(const SAR_Type * base);
__STATIC_INLINE void Cy_SAR_ClearSatInterrupt(SAR_Type * base, uint32_t chanMask);
__STATIC_INLINE void Cy_SAR_SetSatInterrupt(SAR_Type * base, uint32_t chanMask);
__STATIC_INLINE void Cy_SAR_SetSatInterruptMask(SAR_Type * base, uint32_t chanMask);
__STATIC_INLINE uint32_t Cy_SAR_GetSatInterruptMask(const SAR_Type * base);
__STATIC_INLINE uint32_t Cy_SAR_GetSatInterruptStatusMasked(const SAR_Type * base);

__STATIC_INLINE uint32_t Cy_SAR_GetInterruptCause(const SAR_Type * base);
/** \} */


/** \addtogroup group_sar_functions_helper
* This set of functions is for useful configuration query
* \{
*/
bool Cy_SAR_IsChannelSigned(const SAR_Type * base, uint32_t chan);
bool Cy_SAR_IsChannelSingleEnded(const SAR_Type * base, uint32_t chan);
__STATIC_INLINE bool Cy_SAR_IsChannelDifferential(const SAR_Type * base, uint32_t chan);
/** \} */

/** \addtogroup group_sar_functions_basic
* \{
*/


/*******************************************************************************
* Function Name: Cy_SAR_GetChanResultUpdated
****************************************************************************//**
*
* Return whether the RESULT register has been updated or not.
* If the bit is high, the corresponding channel RESULT register was updated,
* i.e. was sampled during the previous scan.
*
* \param base
* Pointer to structure describing registers
*
* \return
* Each bit of the result corresponds to the channel.
* Bit 0 is for channel 0, etc.
*
* \funcusage
*
* \snippet sar_snippet.c SNIPPET_SAR_GET_CHAN_RESULT_UPDATED
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_SAR_GetChanResultUpdated(const SAR_Type * base)
{
    return (SAR_CHAN_RESULT_VALID(base));
}


/*******************************************************************************
* Function Name: Cy_SAR_EnableInjection
****************************************************************************//**
*
* Triggers the injection channel sample.
*
* \param base
* Pointer to structure describing registers
*
* \param tailgating
* Injection channel tailgating enable:
* - true: The addressed pin is sampled after the next trigger and after all enabled channels have been scanned.
* - false: SAR is immediately triggered when the SAR is not busy.
*   If the SAR is busy, the INJ channel addressed pin is sampled at the end of the current scan.
*
* \funcusage \snippet sar/snippet/sar_snippet.c SNIPPET_SAR_EN_INJ
*
*******************************************************************************/
__STATIC_INLINE void Cy_SAR_EnableInjection(SAR_Type * base, bool tailgating)
{
    SAR_INJ_CHAN_CONFIG(base) = _CLR_SET_FLD32U(SAR_INJ_CHAN_CONFIG(base), SAR_INJ_CHAN_CONFIG_INJ_TAILGATING, tailgating ? 1UL : 0UL) | SAR_INJ_CHAN_CONFIG_INJ_START_EN_Msk;
}
/** \} */

/** \addtogroup group_sar_functions_config
* \{
*/


/*******************************************************************************
* Function Name: Cy_SAR_SetChanMask
****************************************************************************//**
*
* Set the enable/disable mask for the channels.
*
* \param base
* Pointer to structure describing registers
*
* \param enableMask
* Channel enable/disable mask. Each bit corresponds to a channel.
* - 0: the corresponding channel is disabled.
* - 1: the corresponding channel is enabled; it will be included in the next scan.
*
* \funcusage \snippet sar_snippet.c SNIPPET_SAR_SET_CHAN_MASK
*
*******************************************************************************/
__STATIC_INLINE void Cy_SAR_SetChanMask(SAR_Type * base, uint32_t enableMask)
{
    CY_ASSERT_L2(CY_SAR_CHANMASK(enableMask));

    SAR_CHAN_EN(base) = SAR_CHAN_EN_CHAN_EN_Msk & enableMask;
}


/*******************************************************************************
* Function Name: Cy_SAR_GetChanMask
****************************************************************************//**
*
* Get the enable/disable mask for the channels.
*
* \param base
* The pointer to the structure, which describes registers.
*
* \return
* Channel enable/disable mask. Each bit corresponds to a channel.
* - 0: the corresponding channel is disabled.
* - 1: the corresponding channel is enabled; it will be included in the next scan.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_SAR_GetChanMask(SAR_Type * base)
{
    return (SAR_CHAN_EN(base) & SAR_CHAN_EN_CHAN_EN_Msk);
}


/*******************************************************************************
* Function Name: Cy_SAR_EnableChannels
****************************************************************************//**
*
* Enable the specified channels.
*
* \param base
* Pointer to structure describing registers
*
* \param chanMask
* Combined mask of all channels to be enabled.
*
* \funcusage
* \snippet sar_snippet.c SNIPPET_SAR_EN_CHAN
*
*******************************************************************************/
__STATIC_INLINE void Cy_SAR_EnableChannels(SAR_Type * base, uint32_t chanMask)
{
    CY_ASSERT_L2(CY_SAR_CHANMASK(chanMask));

    SAR_CHAN_EN(base) |= SAR_CHAN_EN_CHAN_EN_Msk & chanMask;
}


/*******************************************************************************
* Function Name: Cy_SAR_DisableChannels
****************************************************************************//**
*
* Disable the specified channels.
*
* \param base
* Pointer to structure describing registers
*
* \param chanMask
* Combined mask of all channels to be disabled.
*
* \funcusage
* \snippet sar_snippet.c SNIPPET_SAR_EN_CHAN
*
*******************************************************************************/
__STATIC_INLINE void Cy_SAR_DisableChannels(SAR_Type * base, uint32_t chanMask)
{
    CY_ASSERT_L2(CY_SAR_CHANMASK(chanMask));

    SAR_CHAN_EN(base) &= ~(SAR_CHAN_EN_CHAN_EN_Msk & chanMask);
}


/*******************************************************************************
* Function Name: Cy_SAR_SetRangeCond
****************************************************************************//**
*
* Set the condition in which range detection interrupts are triggered.
*
* \param base
* Pointer to structure describing registers
*
* \param cond
* A value of the enum \ref cy_en_sar_range_detect_condition_t.
*
* \funcusage \snippet sar_snippet.c SNIPPET_SAR_SET_RANGE_COND
*
*******************************************************************************/
__STATIC_INLINE void Cy_SAR_SetRangeCond(SAR_Type * base, cy_en_sar_range_detect_condition_t cond)
{
    CY_ASSERT_L3(CY_SAR_RANGE_COND(cond));

    SAR_RANGE_COND(base) = (uint32_t)cond << SAR_RANGE_COND_RANGE_COND_Pos;
}


#if (defined (CY_IP_M0S8PASS4A_SAR_VERSION) && (4U <= CY_IP_M0S8PASS4A_SAR_VERSION)) || defined (CY_DOXYGEN)
/*******************************************************************************
* Function Name: Cy_SAR_SetAveragingMode
****************************************************************************//**
*
* Set the averaging mode.
*
* \param base
* Pointer to structure describing registers
*
* \param mode
* A value of the enum \ref cy_en_sar_sample_ctrl_avg_mode_t.
*
* \note Applicable to PSOC4 HVMS only.
*
*******************************************************************************/
__STATIC_INLINE void Cy_SAR_SetAveragingMode(SAR_Type * base, cy_en_sar_sample_ctrl_avg_mode_t mode)
{
    CY_ASSERT_L3(CY_SAR_AVG_MODE(mode));

    CY_REG32_CLR_SET(SAR_SAMPLE_CTRL(base), SAR_SAMPLE_CTRL_AVG_MODE, mode);
}
#endif /* 4U <= CY_IP_M0S8PASS4A_SAR_VERSION */
/** \} */

/** \addtogroup group_sar_functions_interrupt
* \{
*/
/*******************************************************************************
* Function Name: Cy_SAR_GetInterruptStatus
****************************************************************************//**
*
* Return the interrupt register status.
*
* \param base
* Pointer to structure describing registers
*
* \return Interrupt status
*
* \funcusage
*
* \snippet sar/snippet/sar_snippet.c SNIPPET_SAR_ISR
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_SAR_GetInterruptStatus(const SAR_Type * base)
{
    return SAR_INTR(base);
}


/*******************************************************************************
* Function Name: Cy_SAR_ClearInterrupt
****************************************************************************//**
*
* Clear the interrupt.
* The interrupt must be cleared with this function so that the hardware
* can set subsequent interrupts and those interrupts can be forwarded
* to the interrupt controller, if enabled.
*
* \param base
* Pointer to structure describing registers
*
* \param intrMask
* The mask of interrupts to clear. Typically this will be the value returned
* from \ref Cy_SAR_GetInterruptStatus.
* Alternately, select one or more values from \ref group_sar_macros_interrupt and "OR" them together.
* - \ref CY_SAR_INTR_EOS
* - \ref CY_SAR_INTR_OVERFLOW
* - \ref CY_SAR_INTR_FW_COLLISION
* - \ref CY_SAR_INTR_INJ_EOC
* - \ref CY_SAR_INTR_INJ_SATURATE
* - \ref CY_SAR_INTR_INJ_RANGE
* - \ref CY_SAR_INTR_INJ_COLLISION
*
* \return None
*
*******************************************************************************/
__STATIC_INLINE void Cy_SAR_ClearInterrupt(SAR_Type * base, uint32_t intrMask)
{
    CY_ASSERT_L2(CY_SAR_INTRMASK(intrMask));
    SAR_INTR(base) = intrMask & CY_SAR_INTR;
    /* Dummy read for buffered writes. */
    (void) SAR_INTR(base);
}


/*******************************************************************************
* Function Name: Cy_SAR_SetInterrupt
****************************************************************************//**
*
* Trigger an interrupt with software.
*
* \param base
* Pointer to structure describing registers
*
* \param intrMask
* The mask of interrupts to set.
* Select one or more values from \ref group_sar_macros_interrupt and "OR" them together.
* - \ref CY_SAR_INTR_EOS
* - \ref CY_SAR_INTR_OVERFLOW
* - \ref CY_SAR_INTR_FW_COLLISION
* - \ref CY_SAR_INTR_INJ_EOC
* - \ref CY_SAR_INTR_INJ_SATURATE
* - \ref CY_SAR_INTR_INJ_RANGE
* - \ref CY_SAR_INTR_INJ_COLLISION
*
* \return None
*
*******************************************************************************/
__STATIC_INLINE void Cy_SAR_SetInterrupt(SAR_Type * base, uint32_t intrMask)
{
    CY_ASSERT_L2(CY_SAR_INTRMASK(intrMask));

    SAR_INTR_SET(base) = intrMask & CY_SAR_INTR;
}


/*******************************************************************************
* Function Name: Cy_SAR_SetInterruptMask
****************************************************************************//**
*
* Enable which interrupts can trigger the CPU interrupt controller.
*
* \param base
* Pointer to structure describing registers
*
* \param intrMask
* The mask of interrupts. Select one or more values from \ref group_sar_macros_interrupt
* and "OR" them together:
* - \ref CY_SAR_INTR_EOS
* - \ref CY_SAR_INTR_OVERFLOW
* - \ref CY_SAR_INTR_FW_COLLISION
* - \ref CY_SAR_INTR_INJ_EOC
* - \ref CY_SAR_INTR_INJ_SATURATE
* - \ref CY_SAR_INTR_INJ_RANGE
* - \ref CY_SAR_INTR_INJ_COLLISION
*
* \return None
*
* \funcusage
*
* \snippet sar_snippet.c SNIPPET_SAR_SET_INTERRUPT_MASK
*
*******************************************************************************/
__STATIC_INLINE void Cy_SAR_SetInterruptMask(SAR_Type * base, uint32_t intrMask)
{
    CY_ASSERT_L2(CY_SAR_INTRMASK(intrMask));

    SAR_INTR_MASK(base) = intrMask & CY_SAR_INTR;
}


/*******************************************************************************
* Function Name: Cy_SAR_GetInterruptMask
****************************************************************************//**
*
* Return which interrupts can trigger the CPU interrupt controller
* as configured by \ref Cy_SAR_SetInterruptMask.
*
* \param base
* Pointer to structure describing registers
*
* \return
* Interrupt mask. Compare this value with masks in \ref group_sar_macros_interrupt.
*
* \funcusage
*
* \snippet sar_snippet.c SNIPPET_SAR_GET_INTERRUPT_MASK
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_SAR_GetInterruptMask(const SAR_Type * base)
{
    return SAR_INTR_MASK(base);
}


/*******************************************************************************
* Function Name: Cy_SAR_GetInterruptStatusMasked
****************************************************************************//**
*
* Return the bitwise AND between the interrupt request and mask registers.
* See \ref Cy_SAR_GetInterruptStatus and \ref Cy_SAR_GetInterruptMask.
*
* \param base
* Pointer to structure describing registers
*
* \return
* Bitwise AND of the interrupt request and mask registers
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_SAR_GetInterruptStatusMasked(const SAR_Type * base)
{
    return SAR_INTR_MASKED(base);
}


/*******************************************************************************
* Function Name: Cy_SAR_GetRangeInterruptStatus
****************************************************************************//**
*
* Return the range interrupt register status.
* If the status bit is low for a channel, the channel may not be enabled
* (\ref Cy_SAR_SetChanMask), range detection is not enabled for the
* channel (\ref Cy_SAR_SetRangeInterruptMask), or range detection was not
* triggered for the channel.
*
* \param base
* Pointer to structure describing registers
*
* \return
* The range interrupt status for all channels. Bit 0 is for channel 0, etc.
*
* \funcusage
*
* \snippet sar_snippet.c SNIPPET_SAR_GET_RANGE_INTERRUPT_STATUS
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_SAR_GetRangeInterruptStatus(const SAR_Type * base)
{
    return SAR_RANGE_INTR(base);
}


/*******************************************************************************
* Function Name: Cy_SAR_ClearRangeInterrupt
****************************************************************************//**
*
* Clear the range interrupt for the specified channel mask.
* The interrupt must be cleared with this function so that
* the hardware can set subset interrupts and those interrupts can
* be forwarded to the interrupt controller, if enabled.
*
* \param base
* Pointer to structure describing registers
*
* \param chanMask
* The channel mask. Bit 0 is for channel 0, etc.
* Typically, this is the value returned from \ref Cy_SAR_GetRangeInterruptStatus.
*
* \return None
*
*******************************************************************************/
__STATIC_INLINE void Cy_SAR_ClearRangeInterrupt(SAR_Type * base, uint32_t chanMask)
{
    CY_ASSERT_L2(CY_SAR_CHANMASK(chanMask));

    SAR_RANGE_INTR(base) = chanMask & CY_SAR_CHANNELS_MASK;

    /* Dummy read for buffered writes. */
    (void) SAR_RANGE_INTR(base);
}


/*******************************************************************************
* Function Name: Cy_SAR_SetRangeInterrupt
****************************************************************************//**
*
* Trigger a range interrupt with software for the specific channel mask.
*
* \param base
* Pointer to structure describing registers
*
* \param chanMask
* The channel mask. Bit 0 is for channel 0, etc.
*
* \return None
*
*******************************************************************************/
__STATIC_INLINE void Cy_SAR_SetRangeInterrupt(SAR_Type * base, uint32_t chanMask)
{
    CY_ASSERT_L2(CY_SAR_CHANMASK(chanMask));

    SAR_RANGE_INTR_SET(base) = chanMask & CY_SAR_CHANNELS_MASK;
}


/*******************************************************************************
* Function Name: Cy_SAR_SetRangeInterruptMask
****************************************************************************//**
*
* Enable which channels can trigger a range interrupt.
*
* \param base
* Pointer to structure describing registers
*
* \param chanMask
* The channel mask. Bit 0 is for channel 0, etc.
*
* \return None
*
* \funcusage
*
* \snippet sar_snippet.c SNIPPET_SAR_SET_RANGE_INTERRUPT_MASK
*
*******************************************************************************/
__STATIC_INLINE void Cy_SAR_SetRangeInterruptMask(SAR_Type * base, uint32_t chanMask)
{
    CY_ASSERT_L2(CY_SAR_CHANMASK(chanMask));

    SAR_RANGE_INTR_MASK(base) = chanMask & CY_SAR_CHANNELS_MASK;
}


/*******************************************************************************
* Function Name: Cy_SAR_GetRangeInterruptMask
****************************************************************************//**
*
* Return which interrupts can trigger a range interrupt as configured by
* \ref Cy_SAR_SetRangeInterruptMask.
*
* \param base
* Pointer to structure describing registers
*
* \return
* The range interrupt mask
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_SAR_GetRangeInterruptMask(const SAR_Type * base)
{
    return SAR_RANGE_INTR_MASK(base);
}


/*******************************************************************************
* Function Name: Cy_SAR_GetRangeInterruptStatusMasked
****************************************************************************//**
*
* Return the bitwise AND between the range interrupt request and mask registers.
* See \ref Cy_SAR_GetRangeInterruptStatus and \ref Cy_SAR_GetRangeInterruptMask.
*
* \param base
* Pointer to structure describing registers
*
* \return
* Bitwise AND between of range interrupt request and mask
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_SAR_GetRangeInterruptStatusMasked(const SAR_Type * base)
{
    return SAR_RANGE_INTR_MASKED(base);
}


/*******************************************************************************
* Function Name: Cy_SAR_GetSatInterruptStatus
****************************************************************************//**
*
* Return the saturate interrupt register status.
* If the status bit is low for a channel, the channel may not be enabled
* (\ref Cy_SAR_SetChanMask), saturation detection is not enabled for the
* channel (\ref Cy_SAR_SetSatInterruptMask), or saturation detection was not
* triggered for the channel.
*
* \param base
* Pointer to structure describing registers
*
* \return
* The saturate interrupt status for all channels. Bit 0 is for channel 0, etc.
*
* \funcusage
*
* \snippet sar_snippet.c SNIPPET_SAR_GET_SAT_INTERRUPT_STATUS
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_SAR_GetSatInterruptStatus(const SAR_Type * base)
{
    return SAR_SATURATE_INTR(base);
}


/*******************************************************************************
* Function Name: Cy_SAR_ClearSatInterrupt
****************************************************************************//**
*
* Clear the saturate interrupt for the specified channel mask.
* The interrupt must be cleared with this function so that the hardware
* can set subsequent interrupts and those interrupts can be forwarded
* to the interrupt controller, if enabled.
*
* \param base
* Pointer to structure describing registers
*
* \param chanMask
* The channel mask. Bit 0 is for channel 0, etc.
* Typically, this is the value returned from \ref Cy_SAR_GetSatInterruptStatus.
*
* \return None
*
*******************************************************************************/
__STATIC_INLINE void Cy_SAR_ClearSatInterrupt(SAR_Type * base, uint32_t chanMask)
{
    CY_ASSERT_L2(CY_SAR_CHANMASK(chanMask));

    SAR_SATURATE_INTR(base) = chanMask & CY_SAR_CHANNELS_MASK;

    /* Dummy read for buffered writes. */
    (void) SAR_SATURATE_INTR(base);
}


/*******************************************************************************
* Function Name: Cy_SAR_SetSatInterrupt
****************************************************************************//**
*
* Trigger a saturate interrupt with software for the specific channel mask.
*
* \param base
* Pointer to structure describing registers
*
* \param chanMask
* The channel mask. Bit 0 is for channel 0, etc.
*
* \return None
*
*******************************************************************************/
__STATIC_INLINE void Cy_SAR_SetSatInterrupt(SAR_Type * base, uint32_t chanMask)
{
    CY_ASSERT_L2(CY_SAR_CHANMASK(chanMask));

    SAR_SATURATE_INTR_SET(base) = chanMask & CY_SAR_CHANNELS_MASK;
}


/*******************************************************************************
* Function Name: Cy_SAR_SetSatInterruptMask
****************************************************************************//**
*
* Enable which channels can trigger a saturate interrupt.
*
* \param base
* Pointer to structure describing registers
*
* \param chanMask
* The channel mask. Bit 0 is for channel 0, etc.
*
* \return None
*
* \funcusage
*
* \snippet sar_snippet.c SNIPPET_SAR_GET_SAT_INTERRUPT_MASK
*
*******************************************************************************/
__STATIC_INLINE void Cy_SAR_SetSatInterruptMask(SAR_Type * base, uint32_t chanMask)
{
    CY_ASSERT_L2(CY_SAR_CHANMASK(chanMask));

    SAR_SATURATE_INTR_MASK(base) = chanMask & CY_SAR_CHANNELS_MASK;
}


/*******************************************************************************
* Function Name: Cy_SAR_GetSatInterruptMask
****************************************************************************//**
*
* Return which interrupts can trigger a saturate interrupt as configured
* by \ref Cy_SAR_SetSatInterruptMask.
*
* \param base
* Pointer to structure describing registers
*
* \return
* The saturate interrupt mask. Bit 0 is for channel 0, etc.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_SAR_GetSatInterruptMask(const SAR_Type * base)
{
    return (SAR_SATURATE_INTR_MASK(base));
}

/*******************************************************************************
* Function Name: Cy_SAR_GetSatInterruptStatusMasked
****************************************************************************//**
*
* Return the bitwise AND between the saturate interrupt request and mask registers.
* See \ref Cy_SAR_GetSatInterruptStatus and \ref Cy_SAR_GetSatInterruptMask.
*
* \param base
* Pointer to structure describing registers
*
* \return
* Bitwise AND of the saturate interrupt request and mask
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_SAR_GetSatInterruptStatusMasked(const SAR_Type * base)
{
    return (SAR_SATURATE_INTR_MASKED(base));
}


/*******************************************************************************
* Function Name: Cy_SAR_GetInterruptCause
****************************************************************************//**
*
* Return the cause of the interrupt.
* The interrupt routine can be called due to one of the following events:
*   - End of scan (EOS)
*   - Overflow
*   - Firmware collision
*   - Saturation detected on one or more channels
*   - Range detected on one or more channels
*
* \param base
* Pointer to structure describing registers
*
* \return
* Mask of what caused the interrupt. Compare this value with one of these masks:
*   - SAR_INTR_CAUSE_EOS_MASKED_MIR_Msk : EOS caused the interrupt
*   - SAR_INTR_CAUSE_OVERFLOW_MASKED_MIR_Msk : Overflow caused the interrupt
*   - SAR_INTR_CAUSE_FW_COLLISION_MASKED_MIR_Msk : Firmware collision cause the interrupt
*   - SAR_INTR_CAUSE_SATURATE_MASKED_RED_Msk : Saturation detection on one or more channels caused the interrupt
*   - SAR_INTR_CAUSE_RANGE_MASKED_RED_Msk : Range detection on one or more channels caused the interrupt
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_SAR_GetInterruptCause(const SAR_Type * base)
{
    return (SAR_INTR_CAUSE(base));
}
/** \} */

/** \addtogroup group_sar_functions_helper
* \{
*/


/*******************************************************************************
* Function Name: Cy_SAR_IsChannelDifferential
****************************************************************************//**
*
* Return true of channel is differential, else false.
*
* \param base
* Pointer to structure describing registers
*
* \param chan
* The channel to check, starting at 0.
*
* \return
* A false is return if chan is invalid.
*
* \funcusage
*
* \snippet sar_snippet.c SNIPPET_SAR_IS_CHANNEL_DIFF
*
*******************************************************************************/
__STATIC_INLINE bool Cy_SAR_IsChannelDifferential(const SAR_Type * base, uint32_t chan)
{
    return (!Cy_SAR_IsChannelSingleEnded(base, chan));
}
/** \} */

/** \addtogroup group_sar_functions_switches
* \{
*/
/*******************************************************************************
* Function Name: Cy_SAR_SetVssaVminusSwitch
****************************************************************************//**
*
* Open or close the switch between VSSA and Vminus of the SARADC through firmware.
* This function calls \ref Cy_SAR_SetAnalogSwitch with
* switchMask set to SAR_MUX_SWITCH0_MUX_FW_VSSA_VMINUS_Msk.
*
* \param base
* Pointer to structure describing registers
*
* \param state
* true - open or false - close the switch.
*
* \note
* This is an advanced function used for the low-level hardware control of the switches.
* This function is not required for a typical SAR sequencer-based application.
*
* \funcusage \snippet sar_snippet.c SNIPPET_SAR_VSSA_VMINUS_SWITCH
*
*******************************************************************************/
__STATIC_INLINE void Cy_SAR_SetVssaVminusSwitch(SAR_Type * base, bool state)
{
    Cy_SAR_SetAnalogSwitch(base, SAR_MUX_SWITCH0_MUX_FW_VSSA_VMINUS_Msk, state);
}


/*******************************************************************************
* Function Name: Cy_SAR_SetVssaSarSeqCtrl
****************************************************************************//**
*
* Enable or disable SARSEQ control of the switch between VSSA and Vminus of the SARADC.
* This function calls \ref Cy_SAR_SetSwitchSarSeqCtrl
* with switchMask set to SAR_MUX_SWITCH_SQ_CTRL_MUX_SQ_CTRL_VSSA_Msk.
*
* \param base
* Pointer to structure describing registers
*
* \param ctrl
* true - enable or false - disable control.
*
* \note
* This is an advanced function used for the low-level hardware control of the switches.
* This function is not required for a typical SAR sequencer-based application.
*
* \funcusage \snippet sar_snippet.c SNIPPET_SAR_VSSA_SARSEQ_CTRL
*
*******************************************************************************/
__STATIC_INLINE void Cy_SAR_SetVssaSarSeqCtrl(SAR_Type * base, bool ctrl)
{
    Cy_SAR_SetSwitchSarSeqCtrl(base, SAR_MUX_SWITCH_HW_CTRL_MUX_HW_CTRL_VSSA_Msk, ctrl);
}
/** \} */




/** \} group_sar_functions */

#if defined(__cplusplus)
}
#endif

#endif /* CY_IP_M0S8PASS4A_SAR */

#endif /* !defined(CY_SAR_H) */

/** \} group_sar */

/* [] END OF FILE */
