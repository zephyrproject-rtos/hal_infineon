/***************************************************************************//**
* \file cy_dsadc.h
* \version 1.0
*
* \brief
* Provides an API declaration of the Delta-Sigma ADC driver
*
********************************************************************************
* \copyright
* (c) (2025), Cypress Semiconductor Corporation (an Infineon company) or
* an affiliate of Cypress Semiconductor Corporation.
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
* \addtogroup group_dsadc
* \{
* The ADC driver provides a function API to manage the Delta-Sigma ADC.
*
* \note Supported on PSOC4 HVPA only.
*
* The functions and other declarations used in this driver are in cy_dsadc.h.
* You can include cy_pdl.h to get access to all functions
* and declarations in the PDL.
*
* The PSOC4 HVPA PACSS has two delta-sigma analog-to-digital converters (ADCs)
* to perform 16 - 20+ bit measurements at a sample rate of up to 48 ksps
* for continuous measurements.
* Higher resolution can be achieved at slower sample rates by accumulating
* more modulator results in the decimator.
*
* Analog-to-digital converters (ADCs) are split into the analog part and the digital part.
* The PSOC4 HVPA PACSS has two analog parts followed by four digital parts:
* * Common part, which applies (see \ref common "Common part") to the entire system.
* * Two analog parts (see \ref achan "Analog part").
* * Four digital parts (see \ref dchan "Digital part").
*
* \anchor common **Common part**
*
* The common part contains:
* * \ref Sequencer "Sequencers".
* * \ref Temperature "Temperature sensors".
* * \ref AGC "Auto-Gain Controller".
* * Logic that mixes data between digital and analog.
*
* \anchor Sequencer **Sequencers**
*
* Sequencer is based on finite state machine (FSM).
* The PACSS has two sequencers which are associated with the two analog
* front-end channels (see \ref achan "Analog part").
*
* \image html seq_adc.png "Sequencers"
*
* When triggered, the sequencer loads the input pin selection of the first assigned
* digital channel (see \ref dchan "Digital part") then starts the decimator which initializes
* the modulator (see \ref DSM "Delta-sigma modulator") to start the conversion.
*
* The modulator output data is transferred to the assigned digital channel.
*
* There are two supported conversion modes: incremental (single sample) and continuous.
* When a conversion is finished, the sequencer is notified by the decimator.
*
* \anchor Temperature **Temperature sensors**
*
* On-die temperature sensor
*
* On-die temperature measurements are made with an internal temperature sensor
* by measuring bipolar "base-emitter voltage" (VBE) at different current densities
* and calculating temperature.
*
* External temperature sensor
*
* The external temperature sensor uses a fixed resistor and a temperature-dependent
* resistor (generally a negative temperature coefficient thermistor) - the resistor
* and thermistor form a voltage divider whose output voltage is temperature dependent.
* When enabled, the External Temperature Sensor block provides power to the off-chip
* temperature-dependent divider (and a reference supply for the ADC) of VDDD/3.
*
* \anchor AGC **Auto-Gain Controller**
*
* The AGC can automatically control the gain of either channel.
* AGC circuits typically monitor either the input voltage or output of the PGA
* and increase gain when signal amplitude is below a certain threshold or reduce
* gain when above another threshold. This function can also be achieved with a
* low-resolution A/D converter with digital comparison for gain selection.
*
* \image html agc_adc.png "Auto-Gain Control"
*
* \anchor achan **Analog part**
*
* \image html analog_adc.png "Analog ADC part"
*
* The analog portion of the ADCs consists:
* * \ref multiplexer "Input/diagnostic multiplexer"
* * \ref pga "Programmable gain amplifier (PGA)"
* * \ref aaf "Anti-alias filter (AAF)"
* * \ref buffer "Buffer amplifier"
* * \ref DSM "Delta-sigma modulator"
*
* The analog DSM system receives a differential signal selected through the analog multiplexer.
* This differential signal is received by a programmable gain amplifier (PGA).
* The output of the PGA feeds a low-pass anti-alias filter (AAF) with a bandwidth of ~30 kHz.
* A buffer amplifier drives the DSM modulator - this amplifier has high bandwidth
* to settle the modulator capacitors to better than 16 bits each time they are settled.
* The modulator uses capacitor dividers to set gain.
* The modulator is a third order with switched capacitor amplifier circuits.
* The modulator produces a multi-level digital bitstream sent to the digital channel.
* PGA and buffer amplifiers have offset trim, which reduces to offset these sub-blocks
* to <0.5 mV (across temperature).
* Offset trim is done during production.
* To reduce offset further, there is circuit chopping in PGA, buffer, and modulator.
* Chopping frequency is programmable from Fs/2 to Fs/256 (in 2's powers), where default is Fs/32.
* Fs here is the modulator clock.
*
* \anchor multiplexer **Input/diagnostic multiplexer**
*
* \image html mux_adc.png "Input/diagnostic multiplexer"
*
* \note Resistor dividers enable/select (RDIVen/RDIVsel) coming from HVSS
* (see \ref group_hvss).
*
* \anchor pga **Programmable gain amplifier (PGA)**
*
* The PGA is a fully-differential pseudo-instrumentation amplifier implemented with two Opamps.
* The PGA can be programmed for gains of 1 to 32.
* The PGA gain can be programmed via the internal bus or comes from the AGC.
* The PGA input range is -250 mV to 1.2 V
* (For RSH/RSL input pins, the input range is -300 mV to +300 mV).
* A negative pump is used to allow inputs to be below ground.
* This PGA has low-noise and input capacitance of about 1.5 pF.
* The PGA includes input/output chopping, which the sequencer can enable, and digital offset trim.
*
* \anchor aaf **Anti-alias filter (AAF)**
*
* The anti-alias filter (AAF) is a first order RC filter with a 30-kHz corner frequency.
* 30 kHz is selected to give 40 dB attenuation at modulator sampling frequency,
* which is 3.072 MHz.
* The filter also has bypass switches, which allow the filter to be removed from
* the signal path, and a set of fast switches that bypass the "R" in the RC filter,
* moving the corner frequency approximately 600 kHz.
*
* Following shows the AAF.
* \image html aaf_adc.png "Anti-alias filter (AAF)"
*
* To alternately measure two signals with one channel, the anti-alias filter
* can be temporarily shorted since the AAF needs about 60 mks to settle to 16-bits
* before conversions can start - the measurement sample rate needs to slow to 4 ksps
* if the AAF is not bypassed.
*
* \anchor buffer **Buffer amplifier**
*
* The buffer amplifier converts the high-impedance AAF filter output
* to low impedance for driving the DSM modulator.
* The buffer includes digital offset trim and chopping,
* which can be enabled or disabled with a control signal.
*
* \anchor DSM **Delta-sigma modulator**
*
* The delta-sigma modulator works by taking the difference between input
* and feedback signals (delta) and accumulating that difference (sigma)
* to produce a digital output.
*
* The digital stream goes to a decimator (see \ref dchan), which converts
* the fast oversampled bit stream into slower high-resolution results.
*
* \anchor dchan **Digital part**
*
* \image html digital_adc.png "Digital ADC part"
*
* The digital data system has four digital channels that include:
* * \ref scaler
* * \ref decimator
* * \ref compensation
* * FIR filter
* * accumulator
* * comparator
* * offset, and gain calibrations
*
* The digital channels process outputs from either of the two analog channels.
* Two digital channels are with FIR filter and the others are without the FIR Filter.
* The digital channel without FIR filter has every other feature.
* The channels are typically used for current, voltage, temperature, and diagnostic measurements
* although they can be associated with any inputs.
* The digital system of the PACSS is largely autonomous; it performs acquisitions, filtering,
* post-processing, and data storage without firmware intervention.
* This allows real-time measurements without loading the CPU.
*
* The digital data system optionally generates various interrupts to enable further processing
* of the results, or to handle diagnosis errors.
*
* \anchor scaler **Scaler**
*
* A scaler is used so the LSB of the ADC can have the same weight regardless of gain.
* The LSB is established by the ADC resolution at maximum gain - for the current channel,
* the LSB is 0.715 mA with a gain of 512. The scaler multiplies the output of the modulator
* by 512/Gain to normalize results and maintain 0.715 mA for the LSB regardless of gain setting.
* To multiply by 2, the scaler shifts results up one bit. To cover a gain range of 1 to 512 means
* results can be shifted up to 9 bits.
*
* \anchor decimator **Decimator**
*
* There are two decimators - one is configurable as Sinc3 or Sinc4,
* and the other is used as rate reducer and is a Sinc2.
* The first decimator can be configured for third or fourth order operation.
* The decimation rate (DR) is programmable and can range from 2 to 128.
* Both the third and fourth order decimator configurations can be used for incremental or continuous mode.
*
* The second decimator (rate reducer) DR2 is programmable and can range from 1 to 32.
*
* \note For instance, with a 3.072 MHz clock, DR is set to 64, and DR2 is set to 6 to achieve an 8 ksps sample rate.
*
* \anchor compensation **Compensation**
*
* Compensation block multiplies results for gain adjustment and adds constants for offset correction.
* Up to 64 tap finite impulse response (FIR) filter with programmable coefficients follows the compensation block.
* Results are then normalized to remove unused bits and averaging, accumulation, and threshold detection can be performed.
*
* \section group_dsadc_on_die_configuration On-Die Temperature Initialization
*
* This section describes the process of initializing the on-die temperature sensor
* using the Delta-Sigma ADC (DSADC). The initialization includes enabling the temperature
* sensor, configuring the measurement parameters, performing the measurements
* to calculate the current ratio for calibration and then performing the temperature measurements.
*
* \note In actual applications, before configuring the temperature sensor \ref cy_stc_dsadc_config_t should be initialized,
* and \ref Cy_DSADC_Init should be called.
*
* \anchor stucture **Configuration structure**
*
* This snippet demonstrates how to create and initialize the configuration structures for the on-die temperature sensor.
*
* Two configurations are defined:
* - one_config: Used for the first measurement with a lower current (e.g., 1x current).
* - unit_config: Used for the second measurement with a higher current (e.g., 9x current).
*
* \note The configuration structures are initialized for demonstration purposes only.
* The actual values for the current source, load mode, current, and bipolar units should be set using
* function \ref Cy_DSADC_InitializeDieTempConfigs.
*
* \snippet dsadc_snippet.c snippet_Cy_DSADC_CreateStructure
*
* \anchor initialization **Initialization and Calibration**
*
* To ensure proper initialization during configuration, it is important to maintain appropriate delays.
* Temperature measurement occurs in two stages: first, on-die calibration is performed, and only after that,
* the actual temperature measurement is conducted.
*
* After enabling the on-die sensor, the structures are initialized using the \ref Cy_DSADC_InitializeDieTempConfigs function
* to perform two current measurements on the resistor for 1x and 9x currents. The obtained values are shifted
* as required for 29-bit measurements and passed to the \ref Cy_DSADC_CalcCurrentRatio function to
* get the ratio of the resistor measurements and normalize the results.
*
* \snippet dsadc_snippet.c snippet_Cy_DSADC_InitOnDie
*
* \anchor result **Measurement process**
*
* The temperature measurement process requires reconfiguring the on-die structures to measure the temperature using
* the transistor load mode \ref CY_DSADC_TEMPERATURE_MEASUREMENT_TRANSISTOR. Result of two measurements are shifted
* as required for 29-bit measurements and calculated before value currentRatio passed to the function
* \ref Cy_DSADC_CalcDieTemp to calculate the temperature in fixed point Q12.20 format.
*
* \snippet dsadc_snippet.c snippet_Cy_DSADC_PerformMeasurement
*
*
*
* \section group_dsadc_changelog Changelog
* <table class="doxtable">
*   <tr><th>Version</th><th>Changes</th><th>Reason for Change</th></tr>
*   <tr>
*     <td>1.0</td>
*     <td>Initial version</td>
*     <td></td>
*   </tr>
* </table>
*
* \defgroup group_dsadc_macro Macros
*   \{
*       \defgroup group_dsadc_macros_interrupt Interrupt Masks
*       \defgroup group_dsadc_cause_macros_interrupt Interrupt Cause Masks
*       \defgroup group_dsadc_macros_temperature_sensor On-die Temperature Masks
*       \defgroup group_dsadc_macros_modulator_gain Modulator Gain Masks
*   \}
* \defgroup group_dsadc_functions Functions
*   \{
*       \defgroup group_dsadc_base_functions Base Functions
*         \{
*             \defgroup group_dsadc_base_common_functions Common Functions
*             \defgroup group_dsadc_base_dchan_functions DCHAN Functions
*             \defgroup group_dsadc_base_calibration_functions Calibration
*         \}
*       \defgroup group_dsadc_interrupt_functions Interrupt Functions
*       \defgroup group_dsadc_extended_functions Extended Functions
*         \{
*             \defgroup group_dsadc_ext_common_functions Common Functions
*             \defgroup group_dsadc_ext_achan_functions ACHAN Functions
*             \defgroup group_dsadc_ext_dchan_functions DCHAN Functions
*         \}
*   \}
* \defgroup group_dsadc_data_structures Data Structures
*   \{
*       \defgroup group_data_common COMMON Data Settings
*       \defgroup group_data_analog_chan ACHAN Data Settings
*       \defgroup group_data_digital_chan DCHAN Data Settings
*   \}
* \defgroup group_dsadc_enums Enumerated Types
*   \{
*       \defgroup group_enum_common COMMON Enumerated Types
*       \defgroup group_enum_achan ACHAN Enumerated Types
*       \defgroup group_enum_dchan DCHAN Enumerated Types
*   \}
*/


#if !defined(CY_DSADC_H)
#define CY_DSADC_H

/*****************************************************************************/
/* Include files                                                             */
/*****************************************************************************/
#include "cy_device.h"
#include "cy_syslib.h"
#include <stdint.h>
#include <stdbool.h>

#if defined(CY_IP_M0S8PACSS)
#if !defined(SFLASH_HAS_PACSS) || (1U != SFLASH_HAS_PACSS)
    #error Device does not have calibration data in the SFLASH for PACSS!
#endif

#if defined(__cplusplus)
extern "C" {
#endif

/**
* \addtogroup group_dsadc_macro
* \{
*/

/*****************************************************************************/
/* Global pre-processor symbols/macros ('#define')                           */
/*****************************************************************************/
/** Driver major version */
#define CY_DSADC_DRV_VERSION_MAJOR    1

/** Driver minor version */
#define CY_DSADC_DRV_VERSION_MINOR    0

/** DSADC driver ID */
#define CY_DSADC_ID CY_PDL_DRV_ID(0x50U)

/** Temperature fraction bits num (Q20 format) */
#define CY_DSADC_TEMPERATURE_FRACTION_BITS      (20U)

/** Allow the temperature sensor to settle before taking a measurement. */
#define CY_DSADC_TEMPERATURE_SENSOR_DELAY_US    (10U)

/** \} group_dsadc_macro */

/** \addtogroup group_dsadc_macros_interrupt
* \{
*/

/** Interrupt DCHAN masks */
#define CY_DSADC_DCHAN_INTR_DATA_VAL        (PACSS_DCHAN_INTR_DATA_VAL_INTR_Msk)       /**< Enable data valid interrupt */
#define CY_DSADC_DCHAN_INTR_OVERFLOW        (PACSS_DCHAN_INTR_OVERFLOW_INTR_Msk)       /**< Enable overflow interrupt */
#define CY_DSADC_DCHAN_INTR_FWT_COLLISION   (PACSS_DCHAN_INTR_FWT_COLLISION_INTR_Msk)  /**< Enable firmware trigger collision interrupt */
#define CY_DSADC_DCHAN_INTR_HWT_COLLISION   (PACSS_DCHAN_INTR_HWT_COLLISION_INTR_Msk)  /**< Enable hardware trigger collision interrupt */
#define CY_DSADC_DCHAN_INTR_OVERLOAD        (PACSS_DCHAN_INTR_OVERLOAD_INTR_Msk)       /**< Enable overload interrupt */
#define CY_DSADC_DCHAN_INTR_SATURATE        (PACSS_DCHAN_INTR_SATURATE_INTR_Msk)       /**< Enable saturate interrupt */
#define CY_DSADC_DCHAN_INTR_ACC_THRESH      (PACSS_DCHAN_INTR_ACC_THRESH_INTR_Msk)     /**< Enable accumulated threshold interrupt */
#define CY_DSADC_DCHAN_INTR_RANGE           (PACSS_DCHAN_INTR_RANGE_INTR_Msk)          /**< Enable range detect interrupt */

/** Combined interrupt DCHAN mask */
#define CY_DSADC_INTR_MASK                  (CY_DSADC_DCHAN_INTR_DATA_VAL | \
                                             CY_DSADC_DCHAN_INTR_OVERFLOW | \
                                             CY_DSADC_DCHAN_INTR_FWT_COLLISION | \
                                             CY_DSADC_DCHAN_INTR_HWT_COLLISION | \
                                             CY_DSADC_DCHAN_INTR_OVERLOAD | \
                                             CY_DSADC_DCHAN_INTR_SATURATE | \
                                             CY_DSADC_DCHAN_INTR_ACC_THRESH | \
                                             CY_DSADC_DCHAN_INTR_RANGE)

/** \} group_dsadc_macros_interrupt */

/** \addtogroup group_dsadc_cause_macros_interrupt
* \{
*/

/** Interrupt MMIO cause masks */
#define CY_DSADC_MMIO_INTR_CAUSE_DCH0       (PACSS_MMIO_INTR_CAUSE_DCH0_INT_Msk)        /**< Interrupt cause is DCHAN 0 Interrupt Pending */
#define CY_DSADC_MMIO_INTR_CAUSE_DCH1       (PACSS_MMIO_INTR_CAUSE_DCH1_INT_Msk)        /**< Interrupt cause is DCHAN 1 Interrupt Pending */
#define CY_DSADC_MMIO_INTR_CAUSE_DCH2       (PACSS_MMIO_INTR_CAUSE_DCH2_INT_Msk)        /**< Interrupt cause is DCHAN 2 Interrupt Pending */
#define CY_DSADC_MMIO_INTR_CAUSE_DCH3       (PACSS_MMIO_INTR_CAUSE_DCH3_INT_Msk)        /**< Interrupt cause is DCHAN 3 Interrupt Pending */
#define CY_DSADC_MMIO_INTR_CAUSE_PACSS      (PACSS_MMIO_INTR_CAUSE_PACSS_INT_Msk)       /**< Interrupt cause is System (PACSS_MMIO) Interrupt Pending */

/** Combined interrupt cause mask */
#define CY_DSADC_INTR_CAUSE_MASK            (CY_DSADC_MMIO_INTR_CAUSE_DCH0 | \
                                             CY_DSADC_MMIO_INTR_CAUSE_DCH1 | \
                                             CY_DSADC_MMIO_INTR_CAUSE_DCH2 | \
                                             CY_DSADC_MMIO_INTR_CAUSE_DCH3 | \
                                             CY_DSADC_MMIO_INTR_CAUSE_PACSS)

/** \} group_dsadc_cause_macros_interrupt */

/** \addtogroup group_dsadc_macros_temperature_sensor
* \{
* Set of the macros used to connect the temperature sensor BJT/Resistor load and 'VTEMP' pin.
*/

#define CY_DSADC_MMIO_TMPS_CTL_AMUXA        (PACSS_MMIO_TMPS_CTL_AMUXA_SEL_Msk)     /**< Select amuxbus_a as a current source for biasing BJTs or Resistor */
#define CY_DSADC_MMIO_TMPS_CTL_AMUXB        (PACSS_MMIO_TMPS_CTL_AMUXB_SEL_Msk)     /**< Select amuxbus_b to be connected to temp sensor vbe/vres output. */
#define CY_DSADC_MMIO_TMPS_CTL_VTEMP_SUP    (PACSS_MMIO_TMPS_CTL_VTEMP_SUP_SEL_Msk) /**< Select external current source to bias the BJTs or Resistor. */
#define CY_DSADC_MMIO_TMPS_CTL_VTEMP        (PACSS_MMIO_TMPS_CTL_VTEMP_SEL_Msk)     /**< Connect VTEMP pin to vbe/vres output voltage. */
#define CY_DSADC_MMIO_TMPS_CTL_VTEMP_RET    (PACSS_MMIO_TMPS_CTL_VTEMP_RET_SEL_Msk) /**< Connect VTEMP_RET pin to the vssa_kelvin of the BJTs and resistor.  */

/** Combined temperature sensor mask */
#define CY_DSADC_TMPS_SEL_MASK              (CY_DSADC_MMIO_TMPS_CTL_AMUXA | \
                                             CY_DSADC_MMIO_TMPS_CTL_AMUXB | \
                                             CY_DSADC_MMIO_TMPS_CTL_VTEMP_SUP | \
                                             CY_DSADC_MMIO_TMPS_CTL_VTEMP | \
                                             CY_DSADC_MMIO_TMPS_CTL_VTEMP_RET)

/** \} group_dsadc_macros_temperature_sensor */

/** \addtogroup group_dsadc_macros_modulator_gain
* \{
* Modulator capacitor settings for the DCHAN.
* Refer to the \ref cy_stc_dsadc_gain_mod_cap_config_t structure for more details.
* The macros below are used to set the modulator gain.
*/

/** Modulator Gain 0.5x */
#define CY_DSADC_CONFIG_MOD_GAIN_0P5X  \
    { \
         .fCap1 = 0x39U, .fCap2 = 0xAU, .fCap3 = 0xDU, .dacCap = 0x1FU, .ipCap1 = 0xDU, .ipCap2 = 0x4U, .ipCap3 = 0x4U, \
         .sumCapIn = 0x7U, .sumCap1 = 0x7U, .sumCap2 = 0x7U, .sumCap3 = 0x7U, .sumCapFb = 0x7U                          \
    }

/** Modulator Gain 1x */
#define CY_DSADC_CONFIG_MOD_GAIN_1X  \
    { \
         .fCap1 = 0x39U, .fCap2 = 0xAU, .fCap3 = 0xDU, .dacCap = 0x1FU, .ipCap1 = 0x1BU, .ipCap2 = 0x4U, .ipCap3 = 0x4U, \
         .sumCapIn = 0x3U, .sumCap1 = 0x3U, .sumCap2 = 0x3U, .sumCap3 = 0x3U, .sumCapFb = 0x7U                           \
    }

/** Modulator Gain 2x */
#define CY_DSADC_CONFIG_MOD_GAIN_2X  \
    { \
         .fCap1 = 0x39U, .fCap2 = 0xAU, .fCap3 = 0xDU, .dacCap = 0xFU, .ipCap1 = 0x1BU, .ipCap2 = 0x4U, .ipCap3 = 0x4U, \
         .sumCapIn = 0x3U, .sumCap1 = 0x3U, .sumCap2 = 0x3U, .sumCap3 = 0x3U, .sumCapFb = 0x3U                          \
    }

/** Modulator Gain 4x */
#define CY_DSADC_CONFIG_MOD_GAIN_4X  \
    { \
         .fCap1 = 0x39U, .fCap2 = 0xAU, .fCap3 = 0xDU, .dacCap = 0x7U, .ipCap1 = 0x1BU, .ipCap2 = 0x4U, .ipCap3 = 0x4U, \
         .sumCapIn = 0x3U, .sumCap1 = 0x3U, .sumCap2 = 0x3U, .sumCap3 = 0x3U, .sumCapFb = 0x1U                          \
    }

/** \} group_dsadc_macros_modulator_gain */

/** \cond INTERNAL */

/* Macros for conditions used in CY_ASSERT calls */
#define CY_DSADC_INTRMASK_VALID(mask)       (0UL == ((mask) & ~CY_DSADC_INTR_MASK))
#define CY_DSADC_TMPS_MASK_VALID(mask)      (0UL == ((mask) & ~CY_DSADC_TMPS_SEL_MASK))

/* Macros for use with bit field definitions (xxx_Pos, xxx_Msk) for 16 bit values. */
#define CY_DSADC_GET_INT16(field, value)    ((int16_t)(((value) & (field ## _Msk)) >> (field ## _Pos)))
#define CY_DSADC_GET_UINT16(field, value)   ((uint16_t)(((value) & (field ## _Msk)) >> (field ## _Pos)))

/** \endcond */

/******************************************************************************
 * Enumerations
 *****************************************************************************/

/** \addtogroup group_enum_common
* \{
*/

/** The divider for the chopping clock frequency. Used for Modulator,
 * programmable gain amplifier (PGA),
 * and High-Precision BandGap Reference (HPBGR) chopping. */
typedef enum
{
    CY_DSADC_CHOPPING_CLOCK_DIVIDER_2   = 0U, /**< Chopping frequency is sampling frequency divided by 2.   */
    CY_DSADC_CHOPPING_CLOCK_DIVIDER_4   = 1U, /**< Chopping frequency is sampling frequency divided by 4.   */
    CY_DSADC_CHOPPING_CLOCK_DIVIDER_8   = 2U, /**< Chopping frequency is sampling frequency divided by 8.   */
    CY_DSADC_CHOPPING_CLOCK_DIVIDER_16  = 3U, /**< Chopping frequency is sampling frequency divided by 16.  */
    CY_DSADC_CHOPPING_CLOCK_DIVIDER_32  = 4U, /**< Chopping frequency is sampling frequency divided by 32.  */
    CY_DSADC_CHOPPING_CLOCK_DIVIDER_64  = 5U, /**< Chopping frequency is sampling frequency divided by 64.  */
    CY_DSADC_CHOPPING_CLOCK_DIVIDER_128 = 6U, /**< Chopping frequency is sampling frequency divided by 128. */
    CY_DSADC_CHOPPING_CLOCK_DIVIDER_256 = 7U  /**< Chopping frequency is sampling frequency divided by 256. */
} cy_en_dsadc_chopping_clock_divider_t;

/** Configure the behavior of the Anti-Aliasing Filter ( \ref aaf) when the
 *  Automatic Gain Correction ( \ref AGC) is updating the \ref achan / \ref dchan registers.
 */
typedef enum
{
    CY_DSADC_AGC_AAF_BLANK_MODE_SHORT = 0U, /**< Short the AAF resistor (close SW2 see \ref aaf) */
    CY_DSADC_AGC_AAF_BLANK_MODE_OPEN  = 1U  /**< Disconnect AAF (open SW1 see \ref aaf) */
} cy_en_dsadc_agc_aaf_blank_mode_t;

/** Ground Reference options for \ref Cy_DSADC_SetGroundReference. */
typedef enum
{
    CY_DSADC_GROUND_REFERENCE_VSSA0 = 0U, /**< Set the High Voltage Divider Ground Connection to VSSA. If VSSA is
                                         * used, and VSSA is connected to the negative battery pole, then any
                                         * voltage across the shunt resistor will appear as an offset voltage to
                                         * chassis ground for the LIN pin.
                                         * If VSSA is connected to chassis ground, then RSL / RSH should be used
                                         * as the reference to avoid battery voltage measurement error.
                                         */
    CY_DSADC_GROUND_REFERENCE_VSSA1 = 1U, /**< Set the High Voltage Divider Ground Connection to VSSA. If VSSA is
                                         * used, and VSSA is connected to the negative battery pole, then any
                                         * voltage across the shunt resistor will appear as an offset voltage to
                                         * chassis ground for the LIN pin.
                                         * If VSSA is connected to chassis ground, then RSL / RSH should be used
                                         * as the reference to avoid battery voltage measurement error.
                                         */
    CY_DSADC_GROUND_REFERENCE_RSH   = 2U, /**< Set the High Voltage Divider Ground Connection to RSH. The RSH
                                         * Terminal is one of the terminals intended to be used with a shunt
                                         * resistor to measure battery current.
                                         * The orientation of RSH / RSL in hardware is dependent on the desired
                                         * sign of the current charge / discharge. For charging current to be
                                         * positive, RSH should be connected to ground.
                                         */
    CY_DSADC_GROUND_REFERENCE_RSL   = 3U  /**< Set the High Voltage Divider Ground Connection to RSL. Similar to RSH,
                                         * this terminal is one of the terminals to use used with a shunt
                                         * resistor to measure battery current.
                                         * The orientation of RSH / RSL in hardware is dependent on the desired
                                         * sign of the current charge / discharge. For discharging current to be
                                         * positive, RSL should be connected to ground.
                                         */
} cy_en_dsadc_ground_reference_t;

/** Chopping Phase between the HPBGR "BGR Core" and the "output buffer".
 *
 * The HPBGR contains a "Band Gap Reference Core" (BGR Core) and an "output
 * buffer", which are circuit chopped to reduce offset error.
 *
 * The offset is reduced most when the BGR Core uses the opposite clock edge to
 * chop when compared to the output buffer, which is referred to here as the
 * 'reverse' chopping phase.
 *
 * Optionally, the BGR Core and the output buffer can use the same clock edge
 * for circuit chopping, referred to here as the 'normal' chopping phase.
 */
typedef enum
{
  CY_DSADC_HPBGR_CHOPPING_PHASE_NORMAL  = 0U, /**< The HPBGR 'Output Buffer' and the 'BGR Core' use the same chopping
                                               * clock phase
                                               */
  CY_DSADC_HPBGR_CHOPPING_PHASE_REVERSE = 1U  /**< The HPBGR 'Output Buffer' and the 'BGR Core' use opposite chopping
                                               * clock phase, reducing the offset between the two HPBGR internal
                                               * components
                                               */
} cy_en_dsadc_hpbgr_chopping_phase_t;

/** Buffer phase compensation option for external capacitor.
 *
 * Buffer phase compensation option (external capacitor is present or absent).
 */
typedef enum
{
  CY_DSADC_HPBGR_EXTERNAL_CAPACITOR_PRESENT = 0U, /**< External capacitor is present. */
  CY_DSADC_HPBGR_EXTERNAL_CAPACITOR_ABSENT  = 1U  /**< External capacitor is absent. */
} cy_en_dsadc_hpbgr_external_capacitor_t;

/** Configure the Digital Channel [DCHAN] PGA Gain */
typedef enum
{
    CY_DSADC_DCHAN_PGA_GAIN_1X  = 0U, /**< Gain level 1X */
    CY_DSADC_DCHAN_PGA_GAIN_2X  = 1U, /**< Gain level 2X */
    CY_DSADC_DCHAN_PGA_GAIN_4X  = 2U, /**< Gain level 4X */
    CY_DSADC_DCHAN_PGA_GAIN_8X  = 3U, /**< Gain level 8X */
    CY_DSADC_DCHAN_PGA_GAIN_16X = 4U, /**< Gain level 16X */
    CY_DSADC_DCHAN_PGA_GAIN_32X = 5U  /**< Gain level 32X */
} cy_en_dsadc_dchan_pga_gain_t;

/** Select high or low threshold counter */
typedef enum
{
    CY_DSADC_HIGH_THRESHHOLD_CNTR = 0U,    /**< Used to get status of High threshold counter */
    CY_DSADC_LOW_THRESHHOLD_CNTR = 1U,     /**< Used to get status of Low threshold counter */
} cy_en_dsadc_threshold_select_t;

/** Current source selection for the temperature sensor. */
typedef enum
{
    CY_DSADC_TEMPERATURE_CURRENT_SOURCE_AREF = 0U,  /**< Use the AREF as the current source. */
    CY_DSADC_TEMPERATURE_CURRENT_SOURCE_SRSS = 1U   /**< Use the SRSS as the current source */
} cy_en_dsadc_temperature_current_source_t;

/** Load current configuration for the on-die temperature sensor. */
typedef enum
{
    CY_DSADC_TEMPERATURE_LOAD_MODE_PNP      = 0U,   /**< Configure for PNP, for user temperature measurements. */
    CY_DSADC_TEMPERATURE_LOAD_MODE_NPN      = 1U,   /**< Configure for NPN, for factory calibration. */
    CY_DSADC_TEMPERATURE_LOAD_MODE_RESISTOR = 2U    /**< Configure for the internal resistor (5k Ohms). */
} cy_en_dsadc_temperature_load_mode_t;

/** The temperature measurement parameters selection. */
typedef enum
{
    CY_DSADC_TEMPERATURE_CONFIG_PRIMARY   = 0U,     /**< Select primary temperature measurement parameters. */
    CY_DSADC_TEMPERATURE_CONFIG_ALTERNATE = 1U      /**< Select alternate temperature measurement parameters. */
}cy_en_dsadc_temperature_setup_t;

/** Target voltage measurement configuration selection. */
typedef enum
{
    CY_DSADC_TEMPERATURE_MEASUREMENT_RESISTOR   = 0U,   /**< Configure target voltage measurement
                                                         * across resistor (5k Ohms).
                                                         */
    CY_DSADC_TEMPERATURE_MEASUREMENT_TRANSISTOR = 1U    /**< Configure target voltage measurement
                                                         * across bipolar transistor (PNP/NPN).
                                                         */
}cy_en_dsadc_temp_volt_meas_t;

/** Target to start convert selection */
typedef enum
{
    CY_DSADC_ACHAN0        = 0U, /**< Start convert ACHAN0 */
    CY_DSADC_ACHAN1        = 1U, /**< Start convert ACHAN1 */
    CY_DSADC_ALL_PRIMARY   = 2U, /**< Start convert all Primary channels */
    CY_DSADC_ALL_SECONDARY = 3U  /**< Start convert all Secondary channels */
}cy_en_dsadc_convert_source_t;

/** \} group_enum_common */

/** \addtogroup group_enum_achan
* \{
*/

/** Configure the circuit chopping. */
typedef enum
{
    CY_DSADC_ACHAN_CIRCUIT_CHOPPING_OFF     = 0U, /**< Circuit chopping off. */
    CY_DSADC_ACHAN_CIRCUIT_CHOPPING_CYCLE_1 = 1U, /**< Disconnect Anti-Aliasing Filter (AAF) (SW1 see \ref aaf)
                                                   *   for 1 Delta-Sigma Modulator (DSM) clock cycle after Fchop clock edge.
                                                   */
    CY_DSADC_ACHAN_CIRCUIT_CHOPPING_CYCLE_2 = 2U, /**< Disconnect Anti-Aliasing Filter (AAF) (SW1 see \ref aaf)
                                                   *   for 2 Delta-Sigma Modulator (DSM) clock cycle after Fchop clock edge.
                                                   */
    CY_DSADC_ACHAN_CIRCUIT_CHOPPING_CYCLE_4 = 3U  /**< Disconnect Anti-Aliasing Filter (AAF) (SW1 see \ref aaf)
                                                   *   for 4 Delta-Sigma Modulator (DSM) clock cycle after Fchop clock edge.
                                                   */
} cy_en_dsadc_achan_circuit_chopping_t;

/** Power level for the buffer before the modulator. */
typedef enum
{
    CY_DSADC_BUFFER_POWER_LEVEL_32_PERCENT  = 0U, /**< Approximately 32% power */
    CY_DSADC_BUFFER_POWER_LEVEL_55_PERCENT  = 1U, /**< Approximately 55% power */
    CY_DSADC_BUFFER_POWER_LEVEL_78_PERCENT  = 2U, /**< Approximately 78% power */
    CY_DSADC_BUFFER_POWER_LEVEL_100_PERCENT = 3U  /**< Full power */
} cy_en_dsadc_buffer_power_level_t;

/** Configure the power setting of the quantizer block. */
typedef enum
{
    CY_DSADC_ACHAN_MODULATOR_COMP_POWER_50  = 0U, /**< Quantizer power setting (50%) */
    CY_DSADC_ACHAN_MODULATOR_COMP_POWER_75  = 1U, /**< Quantizer power setting (75%) */
    CY_DSADC_ACHAN_MODULATOR_COMP_POWER_100 = 2U, /**< Quantizer power setting (100%) */
    CY_DSADC_ACHAN_MODULATOR_COMP_POWER_200 = 3U  /**< Quantizer power setting (200%) */
} cy_en_dsadc_achan_modulator_comp_power_t;

/** Configure the PGA Gain for Gain Level Structure.
 * The recommended power setting for performance is the "100%" setting */
typedef enum
{
    CY_DSADC_ACHAN_MODULATOR_FIRST_STAGE_POWER_10  = 0U, /**< Power setting for first stage Opamp power (10%) */
    CY_DSADC_ACHAN_MODULATOR_FIRST_STAGE_POWER_31  = 1U, /**< Power setting for first stage Opamp power (31%) */
    CY_DSADC_ACHAN_MODULATOR_FIRST_STAGE_POWER_44  = 2U, /**< Power setting for first stage Opamp power (44%) */
    CY_DSADC_ACHAN_MODULATOR_FIRST_STAGE_POWER_63  = 3U, /**< Power setting for first stage Opamp power (63%) */
    CY_DSADC_ACHAN_MODULATOR_FIRST_STAGE_POWER_75  = 4U, /**< Power setting for first stage Opamp power (75%) */
    CY_DSADC_ACHAN_MODULATOR_FIRST_STAGE_POWER_88  = 5U, /**< Power setting for first stage Opamp power (88%) */
    CY_DSADC_ACHAN_MODULATOR_FIRST_STAGE_POWER_100 = 6U, /**< Power setting for first stage Opamp power (100%) */
    CY_DSADC_ACHAN_MODULATOR_FIRST_STAGE_POWER_150 = 7U  /**< Power setting for first stage Opamp power (150%) */
} cy_en_dsadc_achan_modulator_first_stage_power_t;

/** Configure the Non-overlap delay of the modulator clock phases. */
typedef enum
{
    CY_DSADC_ACHAN_MODULATOR_NON_OVERLAP_DELAY_LOW       = 0U, /**< 1.57 ns typical delay. */
    CY_DSADC_ACHAN_MODULATOR_NON_OVERLAP_DELAY_MEDIUM    = 1U, /**< 2.54 ns typical delay. */
    CY_DSADC_ACHAN_MODULATOR_NON_OVERLAP_DELAY_HIGH      = 2U, /**< 6.47 ns typical delay. */
    CY_DSADC_ACHAN_MODULATOR_NON_OVERLAP_DELAY_VERY_HIGH = 3U  /**< 9.91 ns typical delay. */
} cy_en_dsadc_achan_modulator_non_overlap_delay_t;

/** Configure the Second and Third Opamp Power Structure. */
typedef enum
{
    CY_DSADC_ACHAN_MODULATOR_SECOND_THIRD_STAGE_POWER_75  = 0U, /**< Power setting for second and third stage Opamp power (75%) */
    CY_DSADC_ACHAN_MODULATOR_SECOND_THIRD_STAGE_POWER_81  = 1U, /**< Power setting for second and third stage Opamp power (81%) */
    CY_DSADC_ACHAN_MODULATOR_SECOND_THIRD_STAGE_POWER_94  = 2U, /**< Power setting for second and third stage Opamp power (94%) */
    CY_DSADC_ACHAN_MODULATOR_SECOND_THIRD_STAGE_POWER_100 = 3U, /**< Power setting for second and third stage Opamp power (100%) */
    CY_DSADC_ACHAN_MODULATOR_SECOND_THIRD_STAGE_POWER_150 = 4U  /**< Power setting for second and third stage Opamp power (150%) */
} cy_en_dsadc_achan_modulator_second_third_stage_power_t;

/** Configure the Summer Power Structure. */
typedef enum
{
    CY_DSADC_ACHAN_MODULATOR_SUMMER_POWER_75  = 0U, /**< Summer power setting (75%) */
    CY_DSADC_ACHAN_MODULATOR_SUMMER_POWER_81  = 1U, /**< Summer power setting (81%) */
    CY_DSADC_ACHAN_MODULATOR_SUMMER_POWER_94  = 2U, /**< Summer power setting (94%) */
    CY_DSADC_ACHAN_MODULATOR_SUMMER_POWER_100 = 3U, /**< Summer power setting (100%)*/
    CY_DSADC_ACHAN_MODULATOR_SUMMER_POWER_150 = 4U  /**< Summer power setting (150%) */
} cy_en_dsadc_achan_modulator_summer_power_t;

/** Configure the Analog Channel Pump clock divider based on the source clock frequency. */
typedef enum
{
    CY_DSADC_ACHAN_PUMP_CLOCK_SOURCE_48MHZ       = 0U, /**< Source clock is 48 MHz, and is sourced by the Pump Clock in the ACHAN */
    CY_DSADC_ACHAN_PUMP_CLOCK_SOURCE_24MHZ       = 1U, /**< Source clock is 24 MHz, and is sourced by the Pump Clock in the ACHAN */
    CY_DSADC_ACHAN_PUMP_CLOCK_SOURCE_HFCLK_48MHZ = 2U, /**< Source clock is 48 MHz, and is sourced by the \ref group_sysclk_clk_hf (HFCLK) */
    CY_DSADC_ACHAN_PUMP_CLOCK_SOURCE_HFCLK_24MHZ = 3U  /**< Source clock is 24 MHz, and is sourced by the \ref group_sysclk_clk_hf (HFCLK) */
} cy_en_dsadc_achan_pump_clock_source_t;

/** Select the Primary or Secondary Trigger source. */
typedef enum
{
    CY_DSADC_ACHAN_TRIGGER_HW_IN0 = 0U, /**< Maps to Hardware IN0 - This does not disable firmware triggering. */
    CY_DSADC_ACHAN_TRIGGER_HW_IN1 = 1U, /**< Maps to Hardware IN1 - This does not disable firmware triggering. */
    CY_DSADC_ACHAN_TRIGGER_HW_IN2 = 2U, /**< Maps to Hardware IN2 - This does not disable firmware triggering. */
    CY_DSADC_ACHAN_TRIGGER_HW_IN3 = 3U, /**< Maps to Hardware IN3 - This does not disable firmware triggering. */
    CY_DSADC_ACHAN_TRIGGER_FW     = 4U  /**< Use Firmware triggering only - Disable hardware triggering of the
                                         *        selected trigger source (primary / secondary)
                                         */
} cy_en_dsadc_achan_trigger_t;

/** Configure the positive pump's power level. */
typedef enum
{
    CY_DSADC_VCM_POWER_LEVEL_LOW   = 0U, /**< Low power */
    CY_DSADC_VCM_POWER_LEVEL_MED   = 1U, /**< Medium power */
    CY_DSADC_VCM_POWER_LEVEL_HIGH  = 2U, /**< High power */
    CY_DSADC_VCM_POWER_LEVEL_TURBO = 3U  /**< Turbo power */
} cy_en_dsadc_achan_reference_vcm_power_level_t;

/** Configure the positive pump's power level. */
typedef enum
{
    CY_DSADC_VREF_POWER_LEVEL_LOW   = 0U, /**< Low power */
    CY_DSADC_VREF_POWER_LEVEL_MED   = 1U, /**< Medium power */
    CY_DSADC_VREF_POWER_LEVEL_HIGH  = 2U, /**< High power */
    CY_DSADC_VREF_POWER_LEVEL_TURBO = 3U  /**< Turbo power */
} cy_en_dsadc_achan_reference_vref_power_level_t;

/** Configure the trigger synchronization. */
typedef enum
{
    CY_DSADC_ACHAN_TRIGGER_UNSYNCHRONIZED = 0U, /**< Bypass clock domain synchronization of the trigger signal */
    CY_DSADC_ACHAN_TRIGGER_SYNCHRONIZED   = 1U  /**< Synchronize the trigger signal to the Delta-Sigma Modulator (DSM) clock domain,
                                                 * if needed an edge detect is done in the peripheral clock domain.
                                                 */
} cy_en_dsadc_achan_trigger_synchronized_t;

/** The mode of dynamic element matching based dynamic element matching (DEM) scheme. */
typedef enum
{
    CY_DSADC_DEM_MODE_DWA   = 0U, /**< Data weighted averaging DWA mode */
    CY_DSADC_DEM_MODE_ADWA  = 1U, /**< Alternate data weighted averaging DWA mode */
    CY_DSADC_DEM_MODE_BIDWA = 2U  /**< A bi-directional data weighted averaging Bi-DWA mode 78% power */
} cy_en_dsadc_dem_mode_t;

/** The power of the programmable gain amplifier (PGA). */
typedef enum
{
    CY_DSADC_PGA_POWER_LEVEL_39_PERCENT  = 0U, /**< Approximately 39% power */
    CY_DSADC_PGA_POWER_LEVEL_58_PERCENT  = 1U, /**< Approximately 58% power */
    CY_DSADC_PGA_POWER_LEVEL_78_PERCENT  = 2U, /**< Approximately 78% power */
    CY_DSADC_PGA_POWER_LEVEL_100_PERCENT = 3U  /**< Full Power */
} cy_en_dsadc_pga_power_level_t;

/** Anti-Aliasing Filter (AAF) Cut-off Frequency. */
typedef enum
{
    CY_DSADC_ACHAN_AAF_CUTOFF_FREQ_30KHZ = 0U, /**< 30kHz */
    CY_DSADC_ACHAN_AAF_CUTOFF_FREQ_10KHZ = 1U, /**< 10kHz */
    CY_DSADC_ACHAN_AAF_CUTOFF_FREQ_20KHZ = 2U  /**< 20kHz */
} cy_en_dsadc_achan_aaf_cutoff_freq_t;

/** Configure the channel chopping type. */
typedef enum
{
  CY_DSADC_ACHAN_CHOPPING_OFF     = 0U, /**< Channel chopping disabled */
  CY_DSADC_ACHAN_CHOPPING_CHANNEL = 1U, /**< Channel chopping enabled. Chopping occurs between the inmux and
                                         *   modulator output using the modbit. The modbit toggles according to
                                         *   the modbit sample count.
                                         */
  CY_DSADC_ACHAN_CHOPPING_CROSS   = 3U  /**< Channel chopping enabled. Chopping occurs between the input and
                                         *   output of the buff using the modbit. The modbit toggles according to
                                         *   the modbit sample count.
                                         */
} cy_en_dsadc_achan_chopping_type_t;

/** The gain value to refer to the two temperature trim values for ACHAN0. */
typedef enum
{
    CY_DSADC_ACHAN0_2TEMP_GAIN_1X   = 0U,   /**< The index for gain 1X. */
    CY_DSADC_ACHAN0_2TEMP_GAIN_2X   = 1U,   /**< The index for gain 2X. */
    CY_DSADC_ACHAN0_2TEMP_GAIN_4X   = 2U,   /**< The index for gain 4X. */
    CY_DSADC_ACHAN0_2TEMP_GAIN_8X   = 3U,   /**< The index for gain 8X. */
    CY_DSADC_ACHAN0_2TEMP_GAIN_16X  = 4U,   /**< The index for gain 16X. */
    CY_DSADC_ACHAN0_2TEMP_GAIN_32X  = 5U,   /**< The index for gain 32X. */
    CY_DSADC_ACHAN0_2TEMP_GAIN_64X  = 6U,   /**< The index for gain 64X. */
    CY_DSADC_ACHAN0_2TEMP_GAIN_128X = 7U,   /**< The index for gain 128X. */
    CY_DSADC_ACHAN0_2TEMP_GAIN_256X = 8U,   /**< The index for gain 256X. */
    CY_DSADC_ACHAN0_2TEMP_GAIN_512X = 9U    /**< The index for gain 512X. */
} cy_en_dsadc_achan0_2temp_trim_gain_type_t;

/** The gain value to refer to the two temperature trim values for ACHAN1. */
typedef enum
{
    CY_DSADC_ACHAN1_2TEMP_GAIN_0P5X = 0U,   /**< The index for gain 0.5X. */
    CY_DSADC_ACHAN1_2TEMP_GAIN_1X   = 1U,   /**< The index for gain 1X. */
    CY_DSADC_ACHAN1_2TEMP_GAIN_2X   = 2U,   /**< The index for gain 2X. */
    CY_DSADC_ACHAN1_2TEMP_GAIN_4X   = 3U,   /**< The index for gain 4X. */
    CY_DSADC_ACHAN1_2TEMP_GAIN_8X   = 4U,   /**< The index for gain 8X. */
    CY_DSADC_ACHAN1_2TEMP_GAIN_16X  = 5U,   /**< The index for gain 16X. */
    CY_DSADC_ACHAN1_2TEMP_GAIN_32X  = 6U,   /**< The index for gain 32X. */
    CY_DSADC_ACHAN1_2TEMP_GAIN_64X  = 7U,   /**< The index for gain 64X. */
    CY_DSADC_ACHAN1_2TEMP_GAIN_128X = 8U,   /**< The index for gain 128X. */
    CY_DSADC_ACHAN1_2TEMP_GAIN_256X = 9U,   /**< The index for gain 256X. */
    CY_DSADC_ACHAN1_2TEMP_GAIN_512X = 10U   /**< The index for gain 512X. */
} cy_en_dsadc_achan1_2temp_trim_gain_type_t;

/** The divider output value to refer to the three temperature trim values for ACHAN. */
typedef enum
{
    CY_DSADC_ACHAN_3TEMP_VSENSE_16 = 0U,   /**< The index for VSENSE/16. */
    CY_DSADC_ACHAN_3TEMP_VSENSE_24 = 1U,   /**< The index for VSENSE/24. */
    CY_DSADC_ACHAN_3TEMP_VDIAG_16  = 2U,   /**< The index for VDIAG/16. */
    CY_DSADC_ACHAN_3TEMP_VDIAG_24  = 3U    /**< The index for VDIAG/24. */
} cy_en_dsadc_achan_3temp_trim_divider_type_t;

/** \} group_enum_achan */

/** \addtogroup group_enum_dchan
* \{
*/

/** Decimator sinc filter modes. */
typedef enum
{
    CY_DSADC_DCHAN_DECIMATOR_SINC_MODE_SINC3 = 0U, /**< Set the Decimator sinc filter to 'Sinc3' */
    CY_DSADC_DCHAN_DECIMATOR_SINC_MODE_SINC4 = 1U  /**< Set the Decimator sinc filter to 'Sinc4' */
} cy_en_dsadc_dchan_decimator_sinc_mode_t;

/** Negative input pin selection for ADC. */
typedef enum
{
    CY_DSADC_DCHAN_NEGATIVE_PIN_VSSA     = 0x00U, /**< VSSA */
    CY_DSADC_DCHAN_NEGATIVE_PIN_VREFL    = 0x09U, /**< Voltage Reference Low Connection */
    CY_DSADC_DCHAN_NEGATIVE_PIN_SRSS_VSS = 0x0AU, /**< VDIV_RET */
    CY_DSADC_DCHAN_NEGATIVE_PIN_VDIV_RET = 0x0BU, /**< SRSS Ground (VSS) */
    CY_DSADC_DCHAN_NEGATIVE_PIN_VTS_RET  = 0x0CU, /**< External Temperature Sensor Return */
    CY_DSADC_DCHAN_NEGATIVE_PIN_VINT_RET = 0x0DU, /**< Internal Temperature Sensor Return */
    CY_DSADC_DCHAN_NEGATIVE_PIN_GPIO0    = 0x0EU, /**< GPIO 0 (P0_0) */
    CY_DSADC_DCHAN_NEGATIVE_PIN_GPIO2    = 0x0FU, /**< GPIO 2 (P0_2) */
    CY_DSADC_DCHAN_NEGATIVE_PIN_RSL_0    = 0x10U, /**< Low Side of Shunt Resistor Zero */
    CY_DSADC_DCHAN_NEGATIVE_PIN_RSL_1    = 0x18U, /**< Low Side of Shunt Resistor One */
    CY_DSADC_DCHAN_NEGATIVE_PIN_AMUXA    = 0x1AU, /**< AMUXA Bus */
    CY_DSADC_DCHAN_NEGATIVE_PIN_AMUXB    = 0x1BU  /**< AMUXB Bus */
} cy_en_dsadc_dchan_negative_pin_t;

/** Select the positive input pin for the DCHAN while the DCHAN is being scanned. */
typedef enum
{
    CY_DSADC_DCHAN_POSITIVE_PIN_HVDIV0          = 0x0U,  /**< Set the positive input pin to the output of high voltage divider 0
                                                          *   (HVDIV0 or VSENSE).
                                                          */
    CY_DSADC_DCHAN_POSITIVE_PIN_HVDIV1          = 0x04U, /**< Set the positive input pin to the output of high voltage divider 1
                                                          *   (HVDIV1 or VDIAG).
                                                          */
    CY_DSADC_DCHAN_POSITIVE_PIN_VTS             = 0x08U, /**< Set the positive input pin to the external temperature sensor
                                                          *   pin. (P1_1)
                                                          */
    CY_DSADC_DCHAN_POSITIVE_PIN_VINT            = 0x0CU, /**< Internal Temperature Sensor Input */
    CY_DSADC_DCHAN_POSITIVE_PIN_VSSA            = 0x10U, /**< Ground Connection Analog (VSSA) */
    CY_DSADC_DCHAN_POSITIVE_PIN_VSSD            = 0x11U, /**< Ground Connection Digital (VSSD) */
    CY_DSADC_DCHAN_POSITIVE_PIN_VSSL            = 0x12U, /**< High Voltage Subsystem ground connection */
    CY_DSADC_DCHAN_POSITIVE_PIN_VREFL           = 0x13U, /**< Voltage Reference Low connection */
    CY_DSADC_DCHAN_POSITIVE_PIN_VTS_RET_K       = 0x15U, /**< External Temperature Sensor Return Kelvin, equivalent to VTS_RET */
    CY_DSADC_DCHAN_POSITIVE_PIN_VINT_RET        = 0x16U, /**< Internal Temperature Sensor Return */
    CY_DSADC_DCHAN_POSITIVE_PIN_VSUB            = 0x17U, /**< VSUB */
    CY_DSADC_DCHAN_POSITIVE_PIN_VCCD_DIV_2      = 0x18U, /**< VCCD / 2 */
    CY_DSADC_DCHAN_POSITIVE_PIN_VCCHIB_DIV_2    = 0x19U, /**< High Voltage Input Bus VCCD / 2 */
    CY_DSADC_DCHAN_POSITIVE_PIN_VDDA_DIV_4      = 0x1AU, /**< VDDA / 4 */
    CY_DSADC_DCHAN_POSITIVE_PIN_VDDD_DIV_4      = 0x1BU, /**< VDDD / 4 */
    CY_DSADC_DCHAN_POSITIVE_PIN_VREFH_1P2_HPBGR = 0x1CU, /**< 1.2 V HPBGR Voltage Reference High connection */
    CY_DSADC_DCHAN_POSITIVE_PIN_VREFH_0P8_HPBGR = 0x1DU, /**< 0.8 V HPBGR Voltage Reference High connection */
    CY_DSADC_DCHAN_POSITIVE_PIN_VREFH_0P7_HPBGR = 0x1EU, /**< 0.7 V HPBGR Voltage Reference High connection */
    CY_DSADC_DCHAN_POSITIVE_PIN_VREFH_1P2_SRSS  = 0x1FU, /**< 1.2 V SRSS Voltage Reference High connection */
    CY_DSADC_DCHAN_POSITIVE_PIN_GPIO0           = 0x20U, /**< GPIO 0 Connection (P0_0) */
    CY_DSADC_DCHAN_POSITIVE_PIN_GPIO1           = 0x24U, /**< GPIO 1 Connection (P0_1) */
    CY_DSADC_DCHAN_POSITIVE_PIN_GPIO2           = 0x28U, /**< GPIO 2 Connection (P0_2) */
    CY_DSADC_DCHAN_POSITIVE_PIN_GPIO3           = 0x2CU, /**< GPIO 3 Connection (P0_3) */
    CY_DSADC_DCHAN_POSITIVE_PIN_GPIO4           = 0x30U, /**< GPIO 4 Connection (P0_4) */
    CY_DSADC_DCHAN_POSITIVE_PIN_GPIO5           = 0x34U, /**< GPIO 5 Connection (P0_5) */
    CY_DSADC_DCHAN_POSITIVE_PIN_GPIO6           = 0x38U, /**< GPIO 6 Connection (P0_6) */
    CY_DSADC_DCHAN_POSITIVE_PIN_GPIO7           = 0x3CU, /**< GPIO 7 Connection (P0_7) */
    CY_DSADC_DCHAN_POSITIVE_PIN_RSH_0           = 0x40U, /**< Shunt Resistor Zero High Side */
    CY_DSADC_DCHAN_POSITIVE_PIN_RSH_1           = 0x60U, /**< Shunt Resistor One High Side */
    CY_DSADC_DCHAN_POSITIVE_PIN_AMUXA           = 0x7AU, /**< Analog Mux Bus A */
    CY_DSADC_DCHAN_POSITIVE_PIN_AMUXB           = 0x7BU  /**< Analog Mux Bus B */
} cy_en_dsadc_dchan_positive_pin_t;

/** Select the condition in which the Range Condition interrupt is triggered */
typedef enum
{
    CY_DSADC_DCHAN_RANGE_CONDITIONAL_LESS_THAN    = 0U, /**< Triggered when the result is less than the Lower Range Threshold
                                                         *   (result < LOWER_RANGE)
                                                         */
    CY_DSADC_DCHAN_RANGE_CONDITIONAL_BETWEEN      = 1U, /**< Triggered when the result is between the lower and upper range
                                                         *   thresholds (LOWER_RANGE <= result < UPPER_RANGE)
                                                         */
    CY_DSADC_DCHAN_RANGE_CONDITIONAL_GREATER_THAN = 2U, /**< Triggered when the result is greater than the upper threshold
                                                         *   (UPPER_RANGE <= result)
                                                         */
    CY_DSADC_DCHAN_RANGE_CONDITIONAL_OUTSIDE      = 3U  /**< Triggered when the result is lower than the Lower Range Threshold or
                                                         *   greater than the upper range threshold
                                                         *   (LOWER_RANGE > result || UPPER_RANGE <= result)
                                                         */
} cy_en_dsadc_dchan_post_processing_range_conditional_t;

/** Enable / Configure the Range Detection Mode */
typedef enum
{
    CY_DSADC_DCHAN_RANGE_MODE_DISABLE     = 0U, /**< Disable range detection */
    CY_DSADC_DCHAN_RANGE_MODE_SIMPLE      = 1U, /**< Enable range detection */
    CY_DSADC_DCHAN_RANGE_MODE_EVENT_COUNT = 2U  /**< Enable range detection with event filtering counter */
} cy_en_dsadc_dchan_post_processing_range_mode_t;

/** Priority settings for the digital channel. */
typedef enum
{
    CY_DSADC_DCHAN_PRIORITY_PRIMARY   = 0U, /**< Primary priority. Does not respond to secondary triggers. */
    CY_DSADC_DCHAN_PRIORITY_SECONDARY = 1U  /**< Secondary priority. When a secondary trigger is received, queue this
                                             *   channel to be used in a conversion after the next primary conversion
                                             *   finishes.
                                             */
} cy_en_dsadc_dchan_priority_t;

/** Configure the RS open detection pull-up selection. */
typedef enum
{
    CY_DSADC_DCHAN_REFERENCE_PULLUP_RSH1 = 0U, /**< Connect RSH[1] to the 4k pull-up to VDDA */
    CY_DSADC_DCHAN_REFERENCE_PULLUP_RSH0 = 1U, /**< Connect RSH[0] to the 4k pull-up to VDDA */
    CY_DSADC_DCHAN_REFERENCE_PULLUP_RSL1 = 2U, /**< Connect RSL[1] to the 4k pull-up to VDDA */
    CY_DSADC_DCHAN_REFERENCE_PULLUP_RSL0 = 3U  /**< Connect RSL[0] to the 4k pull-up to VDDA */
} cy_en_dsadc_dchan_reference_pullup_t;

/** Configure the VREF High selection. */
typedef enum
{
    CY_DSADC_DCHAN_REFERENCE_VREFH_DIRECT     = 0U, /**< High-Precision BandGap Reference (HPBGR) */
    CY_DSADC_DCHAN_REFERENCE_VREFH_BUFFERED   = 1U, /**< High-Precision BandGap Reference (HPBGR) buffered */
    CY_DSADC_DCHAN_REFERENCE_VREFH_SRSS       = 2U, /**< SRSS */
    CY_DSADC_DCHAN_REFERENCE_VREFH_VTS_REF    = 3U, /**< Temperature Sensor common connection */
    CY_DSADC_DCHAN_REFERENCE_VREFH_VDDA_DIV_4 = 4U, /**< VDDA / 4 */
    CY_DSADC_DCHAN_REFERENCE_VREFH_VDDA_DIV_3 = 5U  /**< VDDA / 3 */
} cy_en_dsadc_dchan_reference_vrefh_t;

/** Configure the VREF Low selection. */
typedef enum
{
    CY_DSADC_DCHAN_REFERENCE_VREFL_VREFL       = 0U, /**< VREFL input from pad, treated as a ground */
    CY_DSADC_DCHAN_REFERENCE_VREFL_VSSA_SRSS   = 1U, /**< The VSSA Connection from the SRSS */
    CY_DSADC_DCHAN_REFERENCE_VREFL_VSSA_KELVIN = 2U, /**< The VSSA Connection from the Temperature */
    CY_DSADC_DCHAN_REFERENCE_VREFL_VTS_RET     = 3U  /**< Temperature Sensor return connection */
} cy_en_dsadc_dchan_reference_vrefl_t;

/** Sample mode for the digital channel */
typedef enum
{
    CY_DSADC_DCHAN_SAMPLE_MODE_SINGLE_SHOT = 0U, /**< The channel will do a single conversion after it receives a trigger. */
    CY_DSADC_DCHAN_SAMPLE_MODE_CONTINUOUS  = 1U  /**< The channel will do back-to-back conversions after it is triggered
                                                  *   once.
                                                  */
} cy_en_dsadc_dchan_sample_mode_t;

/** Select the Analog Channel to use from the Digital Channel Configuration. */
typedef enum
{
    CY_DSADC_DCHAN_SELECT_ACHAN0 = 0U, /**< Select Analog Channel 0 */
    CY_DSADC_DCHAN_SELECT_ACHAN1 = 1U  /**< Select Analog Channel 1 */
} cy_en_dsadc_dchan_achan_select_t;

/** Set the number of samples to average or accumulated in DCHAN post processing. */
typedef enum
{
    CY_DSADC_AVERAGING_SAMPLES_NONE = 0U, /**< Disable Averaging / Accumulating */
    CY_DSADC_AVERAGING_SAMPLES_2    = 1U, /**< Average or Accumulate 2 samples */
    CY_DSADC_AVERAGING_SAMPLES_4    = 2U  /**< Average or Accumulate 4 samples */
} cy_en_dsadc_averaging_samples_t;

/** Configure fast decimator scaler. */
typedef enum
{
    CY_DSADC_AGC_FAST_DECIMATOR_SCALER_1 = 0U, /**< FAST_DEC_RESULT is same as result (FAST_DEC_RESULT = RESULT). */
    CY_DSADC_AGC_FAST_DECIMATOR_SCALER_2 = 1U, /**< FAST_DEC_RESULT is 2 times of result (FAST_DEC_RESULT = RESULT << 1). */
    CY_DSADC_AGC_FAST_DECIMATOR_SCALER_4 = 2U, /**< FAST_DEC_RESULT is 4 times of result (FAST_DEC_RESULT = RESULT << 2) */
    CY_DSADC_AGC_FAST_DECIMATOR_SCALER_8 = 3U  /**< FAST_DEC_RESULT is 8 times of result (FAST_DEC_RESULT = RESULT << 3) */
} cy_en_dsadc_agc_fast_decimator_scaler_t;

/** Configure threshold filter mode. */
typedef enum
{
    CY_DSADC_AGC_THRESHOLD_FILTER_MODE_COUNTER    = 0U, /**< Set counter mode. */
    CY_DSADC_AGC_THRESHOLD_FILTER_MODE_INTEGRATOR = 1U /**< Set integrator mode. */
} cy_en_dsadc_agc_threshold_filter_mode_t;

/** Configure the averaging mode. */
typedef enum
{
    CY_DSADC_AVERAGING_MODE_AVERAGE    = 0U, /**< Average the set number of samples in the result register. */
    CY_DSADC_AVERAGING_MODE_ACCUMULATE = 1U  /**< Accumulate the number of samples in the result register. */
} cy_en_dsadc_averaging_mode_t;

/** Selection describes how the Anti-Aliasing Filter will be used by the channel. */
typedef enum
{
    CY_DSADC_AAF_BYPASS          = 0U, /**< Anti-Aliasing Filter will be bypassed. */
    CY_DSADC_AAF_ENABLE          = 1U, /**< Anti-Aliasing Filter will be used continually. */
    CY_DSADC_AAF_SHORT_ON_SELECT = 2U  /**< Anti-Aliasing Filter will be pre-charged during channel select delay
                                        *   and used normally afterward.
                                        */
} cy_en_dsadc_aaf_mode_t;

/** \} group_enum_dchan */

/** \addtogroup group_data_analog_chan
* \{
*/
/** Configure the selected Analog Channel. */
typedef struct
{
    cy_en_dsadc_achan_aaf_cutoff_freq_t                    aafCutoffFreq;           /**< Select the anti-aliasing filter cut-off frequency. */
    cy_en_dsadc_achan_circuit_chopping_t                   aafDisconnectCount;      /**< Set the cycle that disconnects the AAF for the set number
                                                                                     *   of clock cycles after a Fchop clock edge.
                                                                                     */
    cy_en_dsadc_buffer_power_level_t                       bufferPowerLevel;        /**< Set the buffer Power Levels. */
    cy_en_dsadc_achan_modulator_comp_power_t               compPower;               /**< Select the chopping clock frequency. */
    cy_en_dsadc_chopping_clock_divider_t                   datapathChoppingDivider; /**< Set the power control for the quantizer block. */
    cy_en_dsadc_dem_mode_t                                 demMode;                 /**< Set the dynamic element matching (DEM) mode. */
    cy_en_dsadc_achan_modulator_first_stage_power_t        firstStagePower;         /**< Select the First stage Opamp power level. */
    cy_en_dsadc_chopping_clock_divider_t                   modulatorChoppingDivider;/**< Select the modulator chopping clock frequency. */
    cy_en_dsadc_achan_modulator_non_overlap_delay_t        nonOverlapDelay;         /**< Select the Non-Overlap delay of clock phases. */
    cy_en_dsadc_pga_power_level_t                          pgaPowerLevel;           /**< Select the PGA power level. */
    cy_en_dsadc_achan_trigger_t                            primaryTrigger;          /**< Select the primary trigger source for the ACHAN */
    cy_en_dsadc_achan_trigger_t                            secondaryTrigger;        /**< Select the secondary trigger source for the ACHAN */
    cy_en_dsadc_achan_modulator_second_third_stage_power_t secondThirdStagePower;   /**< Select the power level for the second and third
                                                                                     *   integrator stages.
                                                                                     */
    cy_en_dsadc_achan_modulator_summer_power_t             summerPower;             /**< Select the power level for the summer block. */
    cy_en_dsadc_achan_trigger_synchronized_t               syncPrimaryTrigger;      /**< Enable to synchronize the trigger signal to the delta-sigma modulator (DSM)
                                                                                     *    clock domain, or bypass clock domain synchronization of the trigger signal.
                                                                                     */
    cy_en_dsadc_achan_trigger_synchronized_t               syncSecondaryTrigger;    /**< Enable to synchronize the trigger signal to the DSM clock domain,
                                                                                     *   or bypass clock domain synchronization of the trigger signal.
                                                                                     */
    cy_en_dsadc_achan_pump_clock_source_t                  pumpClock;               /**< The pump clock frequency is set based off the source clock frequency.
                                                                                     *   If the source clock frequency is 48 MHz, then this should be
                                                                                     *   \ref CY_DSADC_ACHAN_PUMP_CLOCK_SOURCE_48MHZ. If the source clock frequency
                                                                                     *   is 24 MHz, then this should be set to
                                                                                     *   \ref CY_DSADC_ACHAN_PUMP_CLOCK_SOURCE_24MHZ.
                                                                                     *   These are the only two valid source clock frequencies for the ADC.
                                                                                     */
    cy_en_dsadc_achan_reference_vcm_power_level_t          vcmPowerLevel;           /**< Select the power level for the voltage reference buffer. */
    cy_en_dsadc_achan_reference_vref_power_level_t         vrefPower;               /**< Select the positive pump power level. */
    uint8_t                                              overloadDetectThr;         /**< Set the overload detect threshold. */
    bool                                                 enableDem;                 /**< Enable or disable dynamic element matching (DEM). */
    bool                                                 enableReset1;              /**< Enable or disable 1st stage integrating capacitance to be reset. */
    bool                                                 enableReset2;              /**< Enable or disable 2nd stage integrating capacitance to be reset. */
    bool                                                 enableReset3;              /**< Enable or disable 3rd stage integrating capacitance to be reset. */
    bool                                                 enableSecIntegrChopping;   /**< Enable or disable the 2nd stage circuit chopping. */
    bool                                                 useOverloadDetection;      /**< Enable / Configure the overload detection circuitry. Overload
                                                                                     *   detection can be useful to avoid input saturation. It is recommended
                                                                                     *   to disable overload detection (set this to 'false') while debugging the
                                                                                     *   ADC. Enable overload detection (set this to 'true') is recommended for
                                                                                     *   the final project implementation.
                                                                                     */
} cy_stc_dsadc_achan_config_t;

/** Configure the ACHAN Channel chopping. */
typedef struct
{
    cy_en_dsadc_achan_chopping_type_t choppingType;     /**< Enable/Disable/Configure ACHAN Channel chopping.
                                                         *   See \ref cy_en_dsadc_achan_chopping_type_t
                                                         */
    uint8_t                          modbitSampleCount; /**< Set the number of "Stage 1 decimator" samples wait for before toggling
                                                         *   the modbit (which starts the channel chopping process).
                                                         */
    uint8_t                          aafShortCount;     /**< Set the number of DSM Clocks to short the Anti-aliasing filter after
                                                         *   the modbit toggles.
                                                         */
    uint8_t                          decimatorBlankCount;/**< Set the number of DSM Clocks to disconnect the decimator from the
                                                          *   modulator. While disconnected, the decimator will be fed values from
                                                          *   the circular buffer of past values.
                                                          */
} cy_stc_dsadc_achan_channel_chopping_config_t;

/** \} group_data_analog_chan */

/** \addtogroup group_data_digital_chan
* \{
*/

/** Modulator capacitor settings for the DCHAN.
* Refer to the \ref group_dsadc_macros_modulator_gain macros for more details.
*/
typedef struct
{
    uint8_t fCap1;   /**< The first stage integrating capacitance value.
                      *   This is applicable only for DCHAN and is not overridden by the AGC.
                      */
    uint8_t fCap2;   /**< The second stage integrating capacitance value
                      *   This is applicable only for DCHAN and is not overridden by the AGC.
                      */
    uint8_t fCap3;   /**< The third stage integrating capacitance value.
                      *   This is applicable only for DCHAN and is not overridden by the AGC.
                      */
    uint8_t dacCap;  /**< The DAC capacitance value. */
    uint8_t ipCap1;  /**< The first integrators input sampling capacitance value. */
    uint8_t ipCap2;  /**< The second integrators input sampling capacitance value. */
    uint8_t ipCap3;  /**< The third integrators input sampling capacitance value. */
    uint8_t sumCapIn;/**< The input summer capacitance value. */
    uint8_t sumCap1; /**< The first integrator output summer capacitance value. */
    uint8_t sumCap2; /**< The second integrator output summer capacitance value. */
    uint8_t sumCap3; /**< The third integrator output summer capacitance value. */
    uint8_t sumCapFb;/**< The summer feedback capacitance value. */
} cy_stc_dsadc_gain_mod_cap_config_t;

/** Gain Level configuration for the AGC Gain Levels as well as the
 * Digital Channel Gain Settings.
 */
typedef struct
{
    int16_t                          offsetCorrection;   /**< Set the Offset correction value */
    uint16_t                         gainCorrection;     /**< Set the Gain correction value. */
    cy_en_dsadc_dchan_pga_gain_t       pgaGain;          /**< PGA Gain setting for the DCHAN, which is applied to the PGA of the
                                                          *   ACHAN specified in the DCHAN Configuration structure when this DCHAN
                                                          *   is selected.
                                                          */
    uint8_t                          leftShift;          /**< Amount to left shift the value entering the decimator from the
                                                          *   modulator.
                                                          */
    cy_stc_dsadc_gain_mod_cap_config_t modCapConfig;       /**< Modulator capacitor settings for the DCHAN. */
} cy_stc_dsadc_gain_level_config_t;

/** Automatic Gain Control [AGC] configuration structure, which can be
 * used to quickly configure the AGC.
 */
typedef struct
{
    const cy_stc_dsadc_gain_level_config_t* gainLevels;        /**< Gain Level configuration options. The AGC can have up to 10 different
                                                                *   gain levels, which override settings in the DCHAN which uses the AGC.
                                                                */
    uint16_t                              lowerFilterCount;    /**< Number of low threshold filter counter. */
    uint16_t                              upperFilterCount;    /**< Number of high threshold filter counter. */
    cy_en_dsadc_agc_fast_decimator_scaler_t decimationScaler;  /**< Select fast decimator scaler. */
    cy_en_dsadc_agc_threshold_filter_mode_t lowerFilterMode;   /**< Set low threshold filter mode. */
    cy_en_dsadc_agc_threshold_filter_mode_t upperFilterMode;   /**< Set high threshold filter mode. */
    cy_en_dsadc_agc_aaf_blank_mode_t        aafBlankMode;      /**< Set the Anti-Alias Filter (AAF) blanking mode when the AGC changes
                                                                *   gain level settings in the ACHAN.
                                                                */
    uint8_t                               minGainLevel;        /**< Set the minimum gain level that will be used by the AGC. */
    uint8_t                               initialGainLevel;    /**< Set the initial gain level that will be used by the AGC. */
    uint8_t                               maxGainLevel;        /**< Set the maximum gain level that will be used by the AGC. */
    uint8_t                               decimationRatio;     /**< Set the Decimation Ratio for the AGC fast decimator. */
    uint8_t                               decimatorBlankCount; /**< Set the number of modulator clocks to blank the decimator when the
                                                                *   gain level is changed by the AGC.
                                                                */
    uint8_t                               lowerThreshold;      /**< Set the lower threshold for the AGC, which determines when the AGC
                                                                *   gain level is changed downward.
                                                                */
    uint8_t                               upperThreshold;      /**< Set the upper threshold for the AGC, which determines when the AGC
                                                                *   gain level is changed upward.
                                                                */
    uint8_t                               aafBlankCount;       /**< Set the Anti-Alias Filter (AAF) blanking clock count when the AGC
                                                                *   changes gain level settings in the ACHAN.
                                                                */
    uint8_t                               gainScalerBlankCount;/**< Set the number of modulator clock to delay the gain scaler change when
                                                                *   the gain level is changed by the AGC.
                                                                */
    uint8_t                               numGainLevels;       /**< Number of gain levels to configure from 'gainLevelsPtr'. The first gain
                                                                *   level configured will be PACSS AGC Gain Level 0 up to 'numGainLevels'.
                                                                *   This must be between 1 and 10. Set this to '0' to disable configuring
                                                                *   the gain levels.
                                                                */
} cy_stc_dsadc_agc_config_t;

/** Configure the DCHAN FIR Filter. */
typedef struct
{
    const int16_t* coefficients; /**< FIR Coefficient array pointer. This array should be at least as long
                                  *   as 'numTaps'
                                  */
    uint8_t        numTaps;      /**< Number of FIR taps to use. Maximum number of taps is 64 (minimum is 1) */
} cy_stc_dsadc_fir_config_t;

/** Configure the Digital Channel */
typedef struct
{
    const cy_stc_dsadc_gain_level_config_t*             gain;                   /**< Gain configuration options for the DCHAN */
    const cy_stc_dsadc_fir_config_t*                    fir;                    /**< FIR filter configuration options */
    int32_t                                             rangeLowerThreshold;    /**< Lower threshold of the range condition. Not all conditionals require
                                                                                 *   the lower range - this value will be ignored in that condition.
                                                                                 */
    int32_t                                             rangeUpperThreshold;    /**<  Upper threshold of the range condition. Not all conditionals require
                                                                                 *    the upper range - this value will be ignored in that condition.
                                                                                 */
    cy_en_dsadc_dchan_achan_select_t                      achan;                /**< Analog Channel to get modulator data from. */
    cy_en_dsadc_dchan_sample_mode_t                       conversionMode;       /**< Select the ADC Conversion Mode */
    cy_en_dsadc_dchan_priority_t                          priority;             /**< Channel Priority (Primary / Secondary Channel) */
    cy_en_dsadc_dchan_reference_vrefh_t                   vrefhSelect;          /**< Reference to use for the ADC VREFH internal input. */
    cy_en_dsadc_dchan_reference_vrefl_t                   vreflSelect;          /**< Reference to use for the ADC VREFL internal input. */
    cy_en_dsadc_dchan_positive_pin_t                      pinPositive;          /**< Positive input pin to sample */
    cy_en_dsadc_dchan_negative_pin_t                      pinNegative;          /**< Negative input pin to sample */
    cy_en_dsadc_aaf_mode_t                                aafMode;              /**< Configure the way in which the Anti-Aliasing Filter will be used. */
    cy_en_dsadc_averaging_mode_t                          averagingMode;        /**< Configure the Averaging mode to use in the Post Processing block.
                                                                                 *   There are two averaging modes:
                                                                                 *   * \ref CY_DSADC_AVERAGING_MODE_AVERAGE
                                                                                 *   * \ref CY_DSADC_AVERAGING_MODE_ACCUMULATE
                                                                                 */
    cy_en_dsadc_averaging_samples_t                       averagingSamples;     /**< Configure the number of samples to average:
                                                                                 *   * \ref CY_DSADC_AVERAGING_SAMPLES_2
                                                                                 *   * \ref CY_DSADC_AVERAGING_SAMPLES_4
                                                                                 */
    cy_en_dsadc_dchan_post_processing_range_mode_t        rangeMode;            /**< Enable / Disable the range detection, or configure the range mode for
                                                                                 *   'Event Count'. In 'Event Count' mode, the range conditional works as
                                                                                 *   described by the conditional, except that the condition must be met
                                                                                 *   'rangeCount' times before the interrupt is generated.
                                                                                 */
    cy_en_dsadc_dchan_post_processing_range_conditional_t rangeConditional;     /**< Set the Range Condition. */
    cy_en_dsadc_dchan_decimator_sinc_mode_t               sincMode;             /**< Select the decimator sinc mode (Sinc3 or Sinc4) */
    uint8_t                                             ppRightShift;           /**< FIR Right Shift. This right shift lives in the Post Processor, and
                                                                                 *   requires the Post Processor be enabled (it is enabled by default)
                                                                                 */
    uint8_t                                             stage1DecimationRatio;  /**< Decimation ratio for the first decimator stage
                                                                                 *   Set to 64 for OSR of 64
                                                                                 */
    uint8_t                                             stage2DecimationRatio;  /**< Decimation ratio for the second decimator stage
                                                                                 *   Set to 6 for OSR of 6
                                                                                 */
    uint8_t                                             rightShift;             /**< Configure the right shift for values out of the decimator. Values out
                                                                                 *   of the decimator can more than 32 bits, based on the quantization
                                                                                 *   level, the decimation ratio of the decimator, the decimator
                                                                                 *   left shift, and offset / gain correction values.
                                                                                 *   The minimum value for this should be:
                                                                                 *   val = log2(quantizationLevel)
                                                                                 *   \+ MAX(LeftShiftNumBits)
                                                                                 *   \+ N*log2(Stage1DecimationRatio)
                                                                                 *   \- 32
                                                                                 *   Where:
                                                                                 *     * quantizationLevel is '9' by default
                                                                                 *     * N is the order of the decimator (3 by default)
                                                                                 */
    uint8_t                                             rateReducerRightShift;  /**< Configure the right shift for values out of the rate reducing (second
                                                                                 *   stage) decimator. Values out of the rate reducing decimator can more
                                                                                 *   than 32 bits, based on the decimation ratio of the decimator.
                                                                                 *   The minimum value for this should be:
                                                                                 *   val = 2 *log2(Stage2DecimationRatio)
                                                                                 */
    uint8_t                                             channelSelectDelay;     /**< Channel selection delay applied when the input channels are switched
                                                                                 *   by the sequencer.
                                                                                 */
    uint8_t                                             validGcorBits;          /**< Provides the exponent-1 of the number and limits its precision.
                                                                                 *
                                                                                 * Bits in the significant that are beyond the exponent are ignored.
                                                                                 * E.g., gcor=0x3, validGcorBits=2 represents the number 0.11b   = 0.75
                                                                                 * E.g., gcor=0xc, validGcorBits=4 represents the number 0.1100b = 0.75
                                                                                 * E.g., gcor=0xc, validGcorBits=2 represents the number 1.00b   = 1.0
                                                                                 * (gcor bit number 4 is ignored)
                                                                                 * This value affects the gain correction of the DCHAN and AGC
                                                                                 */
    uint8_t                                             rangeCount;             /**< Number of times the conditional must be met before the interrupt is
                                                                                 *   generated. Requires that 'rangeMode' be configured for
                                                                                 *   \ref CY_DSADC_DCHAN_RANGE_MODE_EVENT_COUNT
                                                                                 */
    bool                                                useAgc;                 /**< Enable Automatic Gain Correction for some of the settings in DCHAN
                                                                                 *   Set to false to disable AGC.
                                                                                 */
    bool                                                enableGainCorrection;   /**< Enable the gain correction. */
    bool                                                enableOffsetCorrection; /**< Enable or disable offset correction of the decimator values */
} cy_stc_dsadc_dchan_config_t;

/** \} group_data_digital_chan */

/** \addtogroup group_data_common
* \{
*/

/** Configure the High Precision Band Gap Reference (HPBGR). */
typedef struct
{
    cy_en_dsadc_chopping_clock_divider_t   hpbgrChoppingDivider;    /**< Select the chopping clock divider */
    cy_en_dsadc_hpbgr_chopping_phase_t     hpbgrChoppingPhase;      /**< Select the HPBGR chopping phase */
    cy_en_dsadc_hpbgr_external_capacitor_t enableExternalCapacitor; /**< Enable/disable the external capacitor */
} cy_stc_dsadc_hpbgr_config_t;

/** Configure the on-die temperature sensor. */
typedef struct
{
    uint16_t                                    current;        /**< The bitmask value of IREF current unit for the on-die temperature sensor.
                                                                 * Each bit corresponds to an IREF switch. If a bit is 1, corresponding switch of IREF current unit is closed.
                                                                 * The value of 0x0000 means all switches are opened.
                                                                 * Total IREF current in on-die temperature sensor is 9.6 uA * (number of bits set).
                                                                 */
    uint16_t                                    bipolar;        /**< The bitmask value of bipolar units for on-die temperature sensor.
                                                                 * Each bit corresponds to a bipolar switch. If a bit is 1, corresponding switch of bipolar unit is closed.
                                                                 * The value of 0x0000 means all switches are opened.
                                                                 * Total number of bipolar connections in on-die temperature sensor is the number of bits set.
                                                                 * This value is only applicable when loadMode is not CY_DSADC_TEMPERATURE_LOAD_MODE_RESISTOR.
                                                                 */
    cy_en_dsadc_temperature_current_source_t    currentSource;  /**< The on-die temperature sensor current source. */
    cy_en_dsadc_temperature_load_mode_t         loadMode;       /**< The on-die temperature sensor load mode. */
} cy_stc_dsadc_temperature_config_t;

/** Configure the Delta-Sigma ADC */
typedef struct {
    const cy_stc_dsadc_dchan_config_t* DCHAN[4];                           /**< Array of the pointers to the DCHAN configurations */
    const cy_stc_dsadc_achan_config_t* ACHAN[2];                           /**< Array of the pointers to the ACHAN configurations */
    const cy_stc_dsadc_achan_channel_chopping_config_t* ACHAN_CHOPPING[2]; /**< Array of the pointers to the chopping configurations */
    const cy_stc_dsadc_agc_config_t*   AGC;                                /**< Automatic Gain Control (AGC) configuration pointer */
    const cy_stc_dsadc_hpbgr_config_t* HPBGR;                              /**< High precision bandgap reference configuration pointer */
} cy_stc_dsadc_config_t;

/** \} group_data_common */

/** \addtogroup group_dsadc_base_common_functions
* \{
*/

void Cy_DSADC_LockProtReg(PACSS_MMIO_Type* base);
void Cy_DSADC_UnlockProtReg(PACSS_MMIO_Type* base);
bool Cy_DSADC_GetLockStatus(const PACSS_MMIO_Type* base);

void Cy_DSADC_Init(const PACSS_Type* base, cy_stc_dsadc_config_t* config);
void Cy_DSADC_Deinit(const PACSS_Type* base);

void Cy_DSADC_Enable(const PACSS_Type* base, cy_stc_dsadc_config_t* config);
void Cy_DSADC_Disable(const PACSS_Type* base);

void Cy_DSADC_EnableSequencer(PACSS_MMIO_Type* base);
void Cy_DSADC_DisableSequencer(PACSS_MMIO_Type* base);
bool Cy_DSADC_GetSequencerBusy(const PACSS_MMIO_Type* base, uint8_t channel);

uint8_t Cy_DSADC_AgcGetGainLevel(const PACSS_MMIO_Type* base);
uint16_t Cy_DSADC_AgcGetFastDecimatorResult(const PACSS_MMIO_Type* base);

float32_t Cy_DSADC_CountsTo_Volts(int32_t counts,
                                  float32_t vref,
                                  float32_t analogGain,
                                  cy_stc_dsadc_dchan_config_t* dchan_config);
float32_t Cy_DSADC_CountsTo_mVolts(int32_t counts,
                                   float32_t vref,
                                   float32_t analogGain,
                                   cy_stc_dsadc_dchan_config_t* dchan_config);
float32_t Cy_DSADC_CountsTo_uVolts(int32_t counts,
                                   float32_t vref,
                                   float32_t analogGain,
                                   cy_stc_dsadc_dchan_config_t* dchan_config);

void Cy_DSADC_ConnectTemperature(PACSS_MMIO_Type* base, uint32_t selectMask);
void Cy_DSADC_DisconnectTemperature(PACSS_MMIO_Type* base, uint32_t selectMask);
void Cy_DSADC_EnableTemperature(PACSS_MMIO_Type* base);
void Cy_DSADC_DisableTemperature(PACSS_MMIO_Type* base);
void Cy_DSADC_InitTemperature(PACSS_MMIO_Type* base, cy_stc_dsadc_temperature_config_t* config);
void Cy_DSADC_InitializeDieTempConfigs(cy_stc_dsadc_temperature_config_t* one,
                                       cy_stc_dsadc_temperature_config_t* unit,
                                       cy_en_dsadc_temperature_setup_t setup,
                                       cy_en_dsadc_temp_volt_meas_t target);
uint32_t Cy_DSADC_CalcCurrentRatio(int32_t currentOne, int32_t currentUnit);
int32_t Cy_DSADC_CalcDieTemp(int32_t vbeOne,
                             int32_t vbeUnit,
                             uint32_t currentRatio,
                             cy_en_dsadc_temperature_setup_t setup);

void Cy_DSADC_StartConvert(PACSS_Type* base, cy_en_dsadc_convert_source_t source);
void Cy_DSADC_StopConvert(PACSS_DCHAN_Type* base);

void Cy_DSADC_EnableLowPowerMode(PACSS_MMIO_Type* base);
void Cy_DSADC_DisableLowPowerMode(PACSS_MMIO_Type* base);

/** \} group_dsadc_base_common_functions */

/** \addtogroup group_dsadc_ext_common_functions
* \{
*/

void Cy_DSADC_EnableHPBGR(PACSS_MMIO_Type* base, const cy_stc_dsadc_hpbgr_config_t* config);
void Cy_DSADC_DisableHPBGR(PACSS_MMIO_Type* base);
void Cy_DSADC_SetGroundReference(PACSS_MMIO_Type* base, cy_en_dsadc_ground_reference_t select);

uint16_t Cy_DSADC_GetThresholdCount(const PACSS_MMIO_Type* base, cy_en_dsadc_threshold_select_t select);
void Cy_DSADC_SetChoppingPosition(PACSS_MMIO_Type* base, cy_en_dsadc_hpbgr_chopping_phase_t select);
cy_en_dsadc_hpbgr_chopping_phase_t Cy_DSADC_GetChoppingPosition(const PACSS_MMIO_Type* base);

void Cy_DSADC_AgcInit(PACSS_MMIO_Type* base, const cy_stc_dsadc_agc_config_t* config);
void Cy_DSADC_AgcEnable(PACSS_MMIO_Type* base);
void Cy_DSADC_AgcDisable(PACSS_MMIO_Type* base);
bool Cy_DSADC_AgcIsEnabled(const PACSS_MMIO_Type* base);
void Cy_DSADC_AgcSetGainCorrection(PACSS_MMIO_Type* base, uint8_t index, uint16_t gain);
void Cy_DSADC_AgcSetOffsetCorrection(PACSS_MMIO_Type* base, uint8_t index, int16_t offset);

void Cy_DSADC_EnableLowDropoutRegulator(PACSS_MMIO_Type* base);
void Cy_DSADC_DisableLowDropoutRegulator(PACSS_MMIO_Type* base);
void Cy_DSADC_SetAccumulatorThreshold(PACSS_DCHAN_Type* base, int32_t threshold);
void Cy_DSADC_ResetAccumulator(PACSS_DCHAN_Type* base);
void Cy_DSADC_StartConversionAll(PACSS_MMIO_Type* base);
void Cy_DSADC_PendSecondConvAll(PACSS_MMIO_Type* base);

/** \} group_dsadc_ext_common_functions */

/** \addtogroup group_dsadc_ext_achan_functions
* \{
*/

/* Cy_DSADC_achan */
void Cy_DSADC_DisableAchan(PACSS_ACHAN_Type* base);
void Cy_DSADC_EnableAchan(PACSS_ACHAN_Type* base);
void Cy_DSADC_InitAchan(PACSS_ACHAN_Type* base, const cy_stc_dsadc_achan_config_t* config);
void Cy_DSADC_PendSecondConvAchan(PACSS_ACHAN_Type* base);
void Cy_DSADC_StartConversionAchan(PACSS_ACHAN_Type* base);
void Cy_DSADC_InitAchanChannelChopping(PACSS_ACHAN_Type* base,
        const cy_stc_dsadc_achan_channel_chopping_config_t* config);

/** \} group_dsadc_ext_achan_functions */

/** \addtogroup group_dsadc_base_calibration_functions
* \{
* Applicable to PSOC4 HVPA only with additional calibration data in SFLASH.
*/

/* calibration */
void Cy_DSADC_CalibrateAchan0_2TempTrim(PACSS_DCHAN_Type *base,
                                        cy_en_dsadc_achan0_2temp_trim_gain_type_t gain,
                                        int32_t temperature);
void Cy_DSADC_CalibrateAchan1_2TempTrim(PACSS_DCHAN_Type *base,
                                        cy_en_dsadc_achan1_2temp_trim_gain_type_t gain,
                                        int32_t temperature);
void Cy_DSADC_CalibrateAchan1_3TempTrim(PACSS_DCHAN_Type *base,
                                        cy_en_dsadc_achan_3temp_trim_divider_type_t divider,
                                        int32_t temperature);
void Cy_DSADC_CalibrateAchan0_3TempTrim(PACSS_DCHAN_Type *base,
                                        cy_en_dsadc_achan_3temp_trim_divider_type_t divider,
                                        int32_t temperature);
void Cy_DSADC_CalibrateAgcGainLevel(PACSS_MMIO_Type *base,
                                    cy_en_dsadc_achan0_2temp_trim_gain_type_t gain,
                                    uint8_t index,
                                    int32_t temperature);
void Cy_DSADC_CalibrateAchan1_ExtTempTrim(PACSS_DCHAN_Type *base, int32_t temperature);
uint16_t Cy_DSADC_GetPullupResistance(cy_en_dsadc_dchan_reference_pullup_t select, int32_t temperature);

/** \} group_dsadc_base_calibration_functions */

/** \addtogroup group_dsadc_base_dchan_functions
* \{
*/

int32_t Cy_DSADC_GetResult(const PACSS_DCHAN_Type* base);
int32_t Cy_DSADC_GetAccumulatorResult(const PACSS_DCHAN_Type* base);
uint32_t Cy_DSADC_CalcMaxCount(const cy_stc_dsadc_dchan_config_t* config);

/** \} group_dsadc_base_dchan_functions */

/** \addtogroup group_dsadc_ext_dchan_functions
* \{
*/

void Cy_DSADC_InitDchan(PACSS_DCHAN_Type* base, const cy_stc_dsadc_dchan_config_t* config);
void Cy_DSADC_EnableDchan(PACSS_DCHAN_Type* base);
void Cy_DSADC_DisableDchan(PACSS_DCHAN_Type* base);

/* gain level */
void Cy_DSADC_ConfigureGainLevel(PACSS_DCHAN_Type* base, const cy_stc_dsadc_gain_level_config_t* gain);
void Cy_DSADC_SetSampleMode(PACSS_DCHAN_Type* base, cy_en_dsadc_dchan_sample_mode_t mode);
void Cy_DSADC_SetVref(PACSS_DCHAN_Type* base,
                      cy_en_dsadc_dchan_reference_vrefh_t vrefh,
                      cy_en_dsadc_dchan_reference_vrefl_t vrefl);
/* pullup */
void Cy_DSADC_EnablePullup(PACSS_DCHAN_Type* base);
void Cy_DSADC_DisablePullup(PACSS_DCHAN_Type* base);
void Cy_DSADC_SetPullupSelect(PACSS_DCHAN_Type* base, cy_en_dsadc_dchan_reference_pullup_t select);
/* gain correction */
void Cy_DSADC_EnableGainCorrection(PACSS_DCHAN_Type* base);
void Cy_DSADC_DisableGainCorrection(PACSS_DCHAN_Type* base);
void Cy_DSADC_SetGainCorrection(PACSS_DCHAN_Type* base, uint16_t gain);
/* offset correction */
void Cy_DSADC_EnableOffsetCorrection(PACSS_DCHAN_Type* base);
void Cy_DSADC_DisableOffsetCorrection(PACSS_DCHAN_Type* base);
void Cy_DSADC_SetOffsetCorrection(PACSS_DCHAN_Type* base, int16_t offset);

void Cy_DSADC_SetInputPin(PACSS_DCHAN_Type* base,
                          cy_en_dsadc_dchan_positive_pin_t pinPositive,
                          cy_en_dsadc_dchan_negative_pin_t pinNegative);

/** \} group_dsadc_ext_dchan_functions */

/** \addtogroup group_dsadc_interrupt_functions
* This set of functions are related to DSADC interrupts.
* \{
*/

__STATIC_INLINE void        Cy_DSADC_ClearInterrupt(PACSS_DCHAN_Type* base, uint32_t intrMask);
__STATIC_INLINE uint32_t    Cy_DSADC_GetInterruptStatus(const PACSS_DCHAN_Type* base);
__STATIC_INLINE void        Cy_DSADC_SetInterrupt(PACSS_DCHAN_Type* base, uint32_t intrMask);
__STATIC_INLINE uint32_t    Cy_DSADC_GetInterruptMask(const PACSS_DCHAN_Type* base);
__STATIC_INLINE void        Cy_DSADC_SetInterruptMask(PACSS_DCHAN_Type* base, uint32_t intrMask);
__STATIC_INLINE uint32_t    Cy_DSADC_GetInterruptStatusMasked(const PACSS_DCHAN_Type* base);
__STATIC_INLINE uint32_t    Cy_DSADC_GetInterruptCause(const PACSS_MMIO_Type* base);
__STATIC_INLINE uint32_t    Cy_DSADC_GetOverloadCause(const PACSS_DCHAN_Type* base);

/*******************************************************************************
* Function Name: Cy_DSADC_ClearInterrupt
****************************************************************************//**
*
* \brief
* Clears the specified interrupt for the specified DCHAN.
*
* \param base
* The base address for the Digital Channel.
*
* \param intrMask
* The bitmask of statuses to clear.
* Select one or more values from \ref group_dsadc_macros_interrupt and "OR" them together.
*
* \funcusage
* \snippet dsadc_snippet.c snippet_Cy_DSADC_DCHAN0Isr_Handler
*
*******************************************************************************/
__STATIC_INLINE void Cy_DSADC_ClearInterrupt(PACSS_DCHAN_Type* base, uint32_t intrMask)
{
    CY_ASSERT_L2(CY_DSADC_INTRMASK_VALID(intrMask));

    base->INTR = intrMask & CY_DSADC_INTR_MASK;
    /* Dummy read for buffered writes. */
    (void) base->INTR;
}

/*******************************************************************************
* Function Name: Cy_DSADC_GetInterruptStatus
****************************************************************************//**
*
* \brief
* Gets the interrupt status for the specified DCHAN.
*
* \param base
* The base address for the Digital Channel.
*
* \return
* The bitmask of interrupt statuses.
*
* \funcusage
* \snippet dsadc_snippet.c snippet_Cy_DSADC_DCHAN0Isr_Handler
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_DSADC_GetInterruptStatus(const PACSS_DCHAN_Type* base)
{
    return (base->INTR & CY_DSADC_INTR_MASK);
}

/*******************************************************************************
* Function Name: Cy_DSADC_SetInterrupt
****************************************************************************//**
*
* \brief
* Set the interrupt source to check if HW operates correctly
* or to use it as a SW interrupt.
*
* \param base
* The base address for the Digital Channel.
*
* \param intrMask
* The bit field determines which interrupt will be triggered.
* Select one or more values from \ref group_dsadc_macros_interrupt and "OR" them together.
*
* \funcusage
* \snippet dsadc_snippet.c snippet_Cy_DSADC_DCHAN0Interrupt
*
*******************************************************************************/
__STATIC_INLINE void Cy_DSADC_SetInterrupt(PACSS_DCHAN_Type* base, uint32_t intrMask)
{
    CY_ASSERT_L2(CY_DSADC_INTRMASK_VALID(intrMask));

    base->INTR_SET = intrMask & CY_DSADC_INTR_MASK;
}

/*******************************************************************************
* Function Name: Cy_DSADC_GetInterruptMask
****************************************************************************//**
*
* \brief
* Returns the interrupt mask for the specified DCHAN.
*
* \param base
* The base address for the Digital Channel.
*
* \return
* The bit field determines which status changes can cause an interrupt.
*
* \funcusage
* \snippet dsadc_snippet.c snippet_Cy_DSADC_DCHAN0Interrupt
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_DSADC_GetInterruptMask(const PACSS_DCHAN_Type* base)
{
    return (base->INTR_MASK & CY_DSADC_INTR_MASK);
}

/*******************************************************************************
* Function Name: Cy_DSADC_SetInterruptMask
****************************************************************************//**
*
* \brief
* Enables the specified interrupt for the specified DCHAN.
*
* \param base
* The base address for the Digital Channel.
*
* \param intrMask
* The bit field determines which status changes can cause an interrupt.
* Select one or more values from \ref group_dsadc_macros_interrupt and "OR" them together.
*
* \funcusage
* \snippet dsadc_snippet.c snippet_Cy_DSADC_DCHAN0Interrupt
*
*******************************************************************************/
__STATIC_INLINE void Cy_DSADC_SetInterruptMask(PACSS_DCHAN_Type* base, uint32_t intrMask)
{
    CY_ASSERT_L2(CY_DSADC_INTRMASK_VALID(intrMask));

    base->INTR_MASK = intrMask & CY_DSADC_INTR_MASK;
}

/*******************************************************************************
* Function Name: Cy_DSADC_GetInterruptStatusMasked
****************************************************************************//**
*
* \brief
* Returns the masked (enabled) interrupt status for the specified DCHAN.
*
* \param base
* The base address for the Digital Channel.
*
* \return
* Bitwise AND of the interrupt request and mask registers.
*
* \funcusage
* \snippet dsadc_snippet.c snippet_Cy_DSADC_DCHAN0Isr_Handler
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_DSADC_GetInterruptStatusMasked(const PACSS_DCHAN_Type* base)
{
    return (base->INTR_MASKED & CY_DSADC_INTR_MASK);
}

/*******************************************************************************
* Function Name: Cy_DSADC_GetInterruptCause
****************************************************************************//**
*
* \brief
* Get the interrupt pending for each DCHAN or System interrupt pending.
*
* \param base
* The pointer to the MMIO instance of the PACSS.
*
* \return
* The bit field determines which DCHAN or System interrupt pending cause an interrupt.
* See \ref group_dsadc_cause_macros_interrupt
*
* | Name                          | Value
* |-------------------------------|---------------------
* | CY_DSADC_MMIO_INTR_CAUSE_DCH0 | 0x00000001UL (bit0)
* | CY_DSADC_MMIO_INTR_CAUSE_DCH1 | 0x00000002UL (bit1)
* | CY_DSADC_MMIO_INTR_CAUSE_DCH2 | 0x00000004UL (bit2)
* | CY_DSADC_MMIO_INTR_CAUSE_DCH3 | 0x00000008UL (bit3)
* | CY_DSADC_MMIO_INTR_CAUSE_PACSS| 0x00000010UL (bit4)
*
* \funcusage
* \snippet dsadc_snippet.c snippet_Cy_DSADC_GetInterruptCause
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_DSADC_GetInterruptCause(const PACSS_MMIO_Type* base)
{
    return (base->INTR_CAUSE & CY_DSADC_INTR_CAUSE_MASK);
}

/*******************************************************************************
* Function Name: Cy_DSADC_GetOverloadCause
****************************************************************************//**
*
* \brief
* Get the overload cause to check if the modulator output is all 0 or all 1.
*
* \param base
* The base address for the Digital Channel.
*
* \return
* Get the overload cause value.
*
* \note
* To be read after overload interrupt issues. If read returns 0, overload is due to all 0s.
* If read returns 1, overload is due to all 1s.
*
* \funcusage
* \snippet dsadc_snippet.c snippet_Cy_DSADC_DCHAN0Isr_Handler
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_DSADC_GetOverloadCause(const PACSS_DCHAN_Type* base)
{
    return (base->STATUS & PACSS_DCHAN_STATUS_OVERLOAD_CAUSE_Msk);
}

__STATIC_INLINE void    Cy_DSADC_AgcClearInterrupt(PACSS_MMIO_Type* base);
__STATIC_INLINE bool    Cy_DSADC_AgcGetInterruptStatus(PACSS_MMIO_Type* base);
__STATIC_INLINE void    Cy_DSADC_AgcSetInterrupt(PACSS_MMIO_Type* base);
__STATIC_INLINE bool    Cy_DSADC_AgcGetInterruptMask(PACSS_MMIO_Type* base);
__STATIC_INLINE void    Cy_DSADC_AgcSetInterruptMask(PACSS_MMIO_Type* base);
__STATIC_INLINE bool    Cy_DSADC_AgcGetInterruptStatusMasked(PACSS_MMIO_Type* base);

/*******************************************************************************
* Function Name: Cy_DSADC_AgcClearInterrupt
****************************************************************************//**
*
* \brief
* Clears the specified AGC MMIO interrupt.
*
* \param base
* The pointer to the MMIO instance of the PACSS.
*
* \funcusage
* \snippet dsadc_snippet.c snippet_Cy_DSADC_AgcIsr_Handler
*
*******************************************************************************/
__STATIC_INLINE void Cy_DSADC_AgcClearInterrupt(PACSS_MMIO_Type* base)
{
    base->INTR |= PACSS_MMIO_INTR_AGC_GLVL_CHG_Msk;
    /* Dummy read for buffered writes. */
    (void) base->INTR;
}

/*******************************************************************************
* Function Name: Cy_DSADC_AgcGetInterruptStatus
****************************************************************************//**
*
* \brief
* Returns the AGC MMIO interrupt status.
*
* \param base
* The pointer to the MMIO instance of the PACSS.
*
* \return
* Interrupt status.
*
* \funcusage
* \snippet dsadc_snippet.c snippet_Cy_DSADC_AgcIsr_Handler
*
*******************************************************************************/
__STATIC_INLINE bool Cy_DSADC_AgcGetInterruptStatus(PACSS_MMIO_Type* base)
{
    return _FLD2BOOL(PACSS_MMIO_INTR_AGC_GLVL_CHG, base->INTR);
}

/*******************************************************************************
* Function Name: Cy_DSADC_AgcSetInterrupt
****************************************************************************//**
*
* \brief
* Write with '1' to set corresponding bit in interrupt request register.
* Can be used to set interrupts for firmware testing.
*
* \param base
* The pointer to the MMIO instance of the PACSS.
*
* \funcusage
* \snippet dsadc_snippet.c snippet_Cy_DSADC_AgcInterrupt
*
*******************************************************************************/
__STATIC_INLINE void Cy_DSADC_AgcSetInterrupt(PACSS_MMIO_Type* base)
{
    base->INTR_SET |= PACSS_MMIO_INTR_SET_AGC_GLVL_CHG_SET_Msk;
}

/*******************************************************************************
* Function Name: Cy_DSADC_AgcGetInterruptMask
****************************************************************************//**
*
* \brief
* Returns the AGC MMIO interrupt mask.
*
* \param base
* The pointer to the MMIO instance of the PACSS.
*
* \return
* The mask interrupt status.
*
* \funcusage
* \snippet dsadc_snippet.c snippet_Cy_DSADC_AgcInterrupt
*
*******************************************************************************/
__STATIC_INLINE bool Cy_DSADC_AgcGetInterruptMask(PACSS_MMIO_Type* base)
{
    return _FLD2BOOL(PACSS_MMIO_INTR_MASK_AGC_GLVL_CHG_MASK, base->INTR_MASK);
}

/*******************************************************************************
* Function Name: Cy_DSADC_AgcSetInterruptMask
****************************************************************************//**
*
* \brief
* Returns the masked (enabled) MMIO interrupt status.
*
* \param base
* The pointer to the MMIO instance of the PACSS.
*
* \funcusage
* \snippet dsadc_snippet.c snippet_Cy_DSADC_AgcInterrupt
*
*******************************************************************************/
__STATIC_INLINE void Cy_DSADC_AgcSetInterruptMask(PACSS_MMIO_Type* base)
{
    base->INTR_MASK |= PACSS_MMIO_INTR_MASK_AGC_GLVL_CHG_MASK_Msk;
}

/*******************************************************************************
* Function Name: Cy_DSADC_AgcGetInterruptStatusMasked
****************************************************************************//**
*
* \brief
* Returns the result of the bitwise AND operation between the corresponding
* interrupt request and mask bits.
*
* \param base
* The pointer to the MMIO instance of the PACSS.
*
* \return
* The masked interrupt status.
* true  : Masked interrupt occurs.
* false : No Masked interrupt occurs.
*
* \funcusage
* \snippet dsadc_snippet.c snippet_Cy_DSADC_AgcIsr_Handler
*
*******************************************************************************/
__STATIC_INLINE bool Cy_DSADC_AgcGetInterruptStatusMasked(PACSS_MMIO_Type* base)
{
    return _FLD2BOOL(PACSS_MMIO_INTR_MASKED_AGC_GLVL_CHG_MASKED, base->INTR_MASKED);
}

/** \} group_dsadc_interrupt_functions */

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /*(CY_IP_M0S8PACSS) */

#endif /* CY_DSADC_H */

/** \} group_dsadc */

/* [] END OF FILE */
