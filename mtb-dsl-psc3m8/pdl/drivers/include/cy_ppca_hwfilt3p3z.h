/***************************************************************************//**
* \file cy_ppca_hwfilt3p3z.h
* \version 1.10
*
* Provides the API declarations of the PPCA HW Filter 3P3Z driver.
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
* \addtogroup group_ppca_hwfilt3p3z
* \{
*
* \section group_ppca_hwfilt3p3z_overview Overview
*
* The HW3P3Z is a hardware-accelerated 3-Pole/3-Zero (3P3Z) digital compensator - the
* digital implementation of the analog Type III controller. It is a Soft IP within the
* PPCA subsystem that introduces a specific gain and phase boost into the control loop
* by implementing three poles and three zeroes as a fixed-point IIR filter.
*
* The MCU provides several instances of the HW3P3Z filter (the available number
* depends on the selected MPN). Each instance can operate in one of two modes:
* - <b>Datapath mode:</b> The HW3P3Z is connected to on-chip ADCs (input) and TCPWM compare
*   registers (output), enabling autonomous closed-loop control without CPU intervention.
* - <b>CPU accelerator mode:</b> The CPU writes input values and reads filter output via AHB,
*   using the HW3P3Z as a fast fixed-point math accelerator for arbitrary control quantities.
*
* Data path connections:
* - In \ref CY_AHB_IF mode, the CPU writes the selected DATA_IN register through the AHB interface
*   and reads the computed result through the filter output registers.
* - In \ref CY_DATA_PATH mode, an ADC channel feeds the ADC filter, whose result is connected to
*   DATA_IN1 through the PPCA register-slave datapath; the filter output can drive the configured
*   TCPWM compare or other connected consumer.
* - On supported MXS40 devices, ADC filter outputs are mapped to HWFILT3P3Z SS0/SS1
*   instances through the REGs Master IF. HWFILT3P3Z outputs are mapped through the
*   REGs Master IF to compatible TCPWM/PWM SS0/SS1 counters.
* - Writing DATA_IN0 or DATA_IN1 starts processing when the corresponding trigger is enabled.
* - The \c eop[0] event signal reports completion and may be routed to the next configured block.
* - The datapath is autonomous only in \ref CY_DATA_PATH mode; AHB mode is CPU-driven.
*
* A typical autonomous control-loop datapath is:
*
* \verbatim
* ADC channel -> ADC filter -> REGs Master IF -> HWFILT3P3Z SS0/SS1
*     -> REGs Master IF -> TCPWM/PWM SS0/SS1
* \endverbatim
*
* The configured hardware mapping transfers the signal between these blocks without
* CPU or AHB data movement. The TCPWM parallel-path selection enables the mapped
* HWFILT3P3Z signal at the selected compare input.
*
* Representative ADC filter to HWFILT3P3Z mappings are:
* \verbatim
* ADC0: ADC_FILT_00 -> HWFILT3P3Z SS1 0   ADC_FILT_01 -> HWFILT3P3Z SS1 1
* ADC1: ADC_FILT_1  -> HWFILT3P3Z SS0 0   ADC2: ADC_FILT_2 -> HWFILT3P3Z SS0 1
* ADC3: ADC_FILT_30 -> HWFILT3P3Z SS0 2   ADC_FILT_31 -> HWFILT3P3Z SS0 3
*
* Representative HWFILT3P3Z-to-TCPWM mappings are:
* TCPWM group 0 counters 0/1/2/3 -> HWFILT3P3Z SS0 0/1/2/3
* TCPWM group 1 counters 0/1     -> HWFILT3P3Z SS1 0/1
* \endverbatim
*
* \image html hwfilt3p3z_tcpwm_datapath.svg "HWFILT3P3Z input and direct TCPWM datapath"
*
* \section group_ppca_hwfilt3p3z_glossary Features
*
* The HW3P3Z module features:
* - 3 poles, 3 zeroes
* - 16-bit input, 24-bit output
* - 24-bit coefficient registers (1 sign bit + 23 fractional value bits, range [-1, +1))
* - 40-bit multiplier
* - 44-bit internal accumulator
* - Maximum 8 CPU clock cycles execution latency
* - Saturation operators with configurable min/max output limits
* - 2's complement arithmetic
* - Programmable data path
* - Filter processing triggered by writing into one of the two data registers (DATA_IN0 or DATA_IN1)
* - Generates a pulse event at the completion of filter computation
* - AHB Slave interface (chosen to reduce access latency)
* - Register Slave interface (connected to ADC_FILT outputs for datapath mode)
*
* \section group_ppca_hwfilt3p3z_transfer_function Transfer Function
*
* The discrete-time transfer function implemented by the HW3P3Z is:
*
* <b>H(z) = k_OUT * (B0 + B1*z^-1 + B2*z^-2 + B3*z^-3) / (1 + A1*z^-1 + A2*z^-2 + A3*z^-3)</b>
*
* Where B0..B3 are the numerator (zero) coefficients, A1..A3 are the denominator (pole) coefficients,
* and k_OUT is the output gain that translates between the ADC and TCPWM domains.
*
* The filter difference equations are:
* - x(n) = x_ref - xin(n)
* - y(n) = Sum(i=0..3)[bi * x(n-i)] - Sum(j=1..3)[aj * y(n-j)]
* - y(out) = y(n) + Offset
* - y(out) = y(n),    if LimMin <= y(n) <= LimMax
* - y(out) = LimMin,  if y(n) < LimMin
* - y(out) = LimMax,  if y(n) > LimMax
*
* \section group_ppca_hwfilt3p3z_fixed_point Fixed-Point Representation
*
* The HW3P3Z uses a fixed-point representation with the following properties:
* - Inputs are 16-bit values. An internal fixed 8-bit left shift is applied on the input
*   side (equivalent to multiplication by 256) to bridge the 16-bit input and 24-bit output domains.
* - Outputs are 24-bit values.
* - Coefficients are 24-bit signed fixed-point values in Q0.23 format, ranging between -1 and +1.
*
* \subsection group_ppca_hwfilt3p3z_coeff_scaling Coefficient Scaling
*
* If any B (numerator / X) coefficient magnitude exceeds 1.0, divide all B coefficients by 2 and
* increment \ref cy_stc_ppca_hwfilt3p3z_config_t::scaleCX by 1. Repeat until all B coefficients
* are in the [-1, +1) range.
*
* If any A (denominator / Y) coefficient magnitude exceeds 1.0, divide all A coefficients by 2 and
* increment \ref cy_stc_ppca_hwfilt3p3z_config_t::scaleCY by 1. Repeat until all A coefficients
* are in the [-1, +1) range.
*
* All Y (denominator) coefficients must have their sign swapped (negate) before programming into
* the hardware registers, as required by the filter difference equation implementation.
*
* \subsection group_ppca_hwfilt3p3z_gains Input and Output Gains
*
* - \ref cy_stc_ppca_hwfilt3p3z_config_t::gIn amplifies the input difference (x_ref - xin) by
*   left-shifting it by the specified number of bits (maximum value 3, i.e., up to 8x amplification).
* - \ref cy_stc_ppca_hwfilt3p3z_config_t::gOut scales down the output by right-shifting it by the
*   specified number of bits. This is used to counter-balance the internal 8-bit left shift on the
*   input path and any coefficient scaling.
*
* \subsection group_ppca_hwfilt3p3z_offset Output Offset
*
* \ref cy_stc_ppca_hwfilt3p3z_config_t::dataOutOffset is a direct addition to the filter output
* value. The offset uses the same fixed-point format (same number of fractional bits) as the
* actual output.
*
* \subsection group_ppca_hwfilt3p3z_float_to_fixed Floating-Point to Fixed-Point Conversion
*
* To convert floating-point coefficients to 24-bit fixed-point registers:
* -# Identify the maximum coefficient magnitude among all B (scaled by k_OUT / 2^8) and A coefficients.
* -# Determine the normalization factor: ceil(log2(max_coeff_magnitude)).
* -# Compute integer coefficients: coeff_int = round(coeff_float * 2^(23 - normalization_factor)).
* -# The normalization factor becomes the \ref cy_stc_ppca_hwfilt3p3z_config_t::scaleCX /
*    \ref cy_stc_ppca_hwfilt3p3z_config_t::scaleCY output shift value.
* -# If the floating-point coefficient is negative, the integer result is stored in 2's complement.
*
* \section group_ppca_hwfilt3p3z_changelog Changelog
* <table class="doxtable">
*   <tr><th>Version</th><th>Changes</th><th>Reason for Change</th></tr>
*   <tr>
*     <td>1.10</td>
*     <td>Added getter/readback APIs: \ref Cy_PPCA_HWFILT3P3Z_GetCoefficients,
*         \ref Cy_PPCA_HWFILT3P3Z_GetOffset, \ref Cy_PPCA_HWFILT3P3Z_GetFilterOutLimits,
*         \ref Cy_PPCA_HWFILT3P3Z_GetCoefficientScaleFactors, \ref Cy_PPCA_HWFILT3P3Z_GetGains,
*         \ref Cy_PPCA_HWFILT3P3Z_GetFilterProcessing, \ref Cy_PPCA_HWFILT3P3Z_GetFilterEnable,
*         \ref Cy_PPCA_HWFILT3P3Z_SS_GetPeripheralEnable, and consolidated
*         \ref Cy_PPCA_HWFILT3P3Z_GetFilterConfig.</td>
*     <td>DRIVERS-25967: STL save/restore support requires PDL getter APIs to avoid
*         direct register access bypassing the abstraction layer.</td>
*   </tr>
*   <tr>
*     <td>1.0</td>
*     <td>Initial version</td>
*     <td></td>
*   </tr>
* </table>
*
*
* \defgroup group_ppca_hwfilt3p3z_functions Functions
* \defgroup group_ppca_hwfilt3p3z_structures Configuration Structures
* \defgroup group_ppca_hwfilt3p3z_enums Enumerations
* \defgroup group_ppca_hwfilt3p3z_macros Macros
*
*/
#if !defined(CY_PPCA_HWFILT3P3Z_H)
#define CY_PPCA_HWFILT3P3Z_H

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
* \addtogroup group_ppca_hwfilt3p3z_macros
* \{
*/
/** The driver major version */
#define CY_PPCA_HWFILT3P3Z_DRV_VERSION_MAJOR       1U

/** The driver minor version */
#define CY_PPCA_HWFILT3P3Z_DRV_VERSION_MINOR       10U

/** The PPCA HW Filter 3P3Z driver ID */
#define CY_PPCA_HWFILT3P3Z_ID                      CY_PDL_DRV_ID(CY_PDL_RSLT_MODULE_PPCA_HWFILT3P3Z)

/** \cond INTERNAL */

#define CY_IS_HWFILTER_PARAM_VALID(param)              (NULL != param)
#define PPCA_HWFILT3P3Z_CNFG_EN_DATA_IN_Pos (PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z_CNFG_EN_TRIG0_Pos)
#define PPCA_HWFILT3P3Z_CNFG_EN_DATA_IN_Msk (PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z_CNFG_EN_TRIG0_Msk | PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z_CNFG_EN_TRIG1_Msk)

/** \endcond */

/** \} group_ppca_hwfilt3p3z_macros */


/***************************************
*       Enumerations
***************************************/
/**
* \addtogroup group_ppca_hwfilt3p3z_enums
* \{
*/

/** Source select for the DATA_IN1 data register.
 * Determines whether DATA_IN1 receives data from the CPU via AHB bus writes
 * or automatically from the ADC filter output (datapath mode). */
typedef enum
{
    CY_AHB_IF    = 0U,   /**< DATA_IN1 is sourced from AHB interface (CPU writes). Use this for CPU accelerator mode. */
    CY_DATA_PATH = 1U,  /**< DATA_IN1 is sourced from the ADC Filter output (hardware datapath). Use this for autonomous closed-loop control. */
}cy_en_ppca_filter_src_sel_t;

/** Selects which data input register triggers filter processing.
 * Writing to the selected data register starts the filter computation.
 * Only one trigger source should be enabled at a time. */
typedef enum
{
    CY_DISABLE_DATA_IN     = 0U,  /**< Both DATA_IN0 and DATA_IN1 trigger disabled. Filter must be triggered by other means. */
    CY_ENABLE_DATA_IN0     = 1U,  /**< Filter processing is triggered by writing to DATA_IN0. */
    CY_ENABLE_DATA_IN1     = 2U,  /**< Filter processing is triggered by writing to DATA_IN1. */
}cy_en_ppca_filter_data_sel_t;


/** Scale factors for coefficient normalization.
 * Each increment of the scale factor applies a left shift of 1 bit (multiplication by 2)
 * to compensate for coefficients that were divided by 2 to fit within the [-1, +1) range.
 * For example, if all B coefficients were divided by 4 (2 times by 2), set scaleCX = 2. */
typedef enum
{
    CY_SCALE_FACTOR_0 = 0U,  /**< No scaling applied (coefficients already in [-1, +1) range) */
    CY_SCALE_FACTOR_1 = 1U,  /**< Multiply output by 2^1 to compensate 1 coefficient halving */
    CY_SCALE_FACTOR_2 = 2U,  /**< Multiply output by 2^2 to compensate 2 coefficient halvings */
    CY_SCALE_FACTOR_3 = 3U,  /**< Multiply output by 2^3 to compensate 3 coefficient halvings */
    CY_SCALE_FACTOR_4 = 4U,  /**< Multiply output by 2^4 to compensate 4 coefficient halvings */
    CY_SCALE_FACTOR_5 = 5U,  /**< Multiply output by 2^5 to compensate 5 coefficient halvings */
    CY_SCALE_FACTOR_6 = 6U,  /**< Multiply output by 2^6 to compensate 6 coefficient halvings */
    CY_SCALE_FACTOR_7 = 7U,  /**< Multiply output by 2^7 to compensate 7 coefficient halvings */
}cy_en_ppca_filter_scale_factor_t;


/** Filter busy status.
 * The filter becomes busy when a computation is triggered (by writing to a data input register)
 * and returns to free after the computation completes (maximum 8 CPU clock cycles). */
typedef enum
{
    CY_FILTER_IS_FREE    = 0U,  /**< The filter is idle and ready to accept new input data */
    CY_FILTER_IS_BUSY    = 1U,  /**< The filter is currently computing; output is not yet valid */
}cy_en_ppca_filter_status_t;

/** \} group_ppca_hwfilt3p3z_enums */


/***************************************
*       Configuration Structures
***************************************/

/**
* \addtogroup group_ppca_hwfilt3p3z_structures
* \{
*/

/** Filter coefficients for the 3P3Z IIR filter.
 * These are 24-bit signed fixed-point values in Q0.23 format (range [-1, +1)).
 * The B (numerator/X) coefficients correspond to the zeros and multiply the input samples.
 * The A (denominator/Y) coefficients correspond to the poles and multiply the previous output samples.
 * \note All Y coefficients must be sign-swapped (negated) before being written to hardware,
 * as required by the filter's internal difference equation implementation. */
typedef struct cy_stc_ppca_filter_coefficients
{
    uint32_t cx0;       /**< B0 (X0) numerator coefficient - multiplies x(n), the current input sample */
    uint32_t cx1;       /**< B1 (X1) numerator coefficient - multiplies x(n-1), the previous input sample */
    uint32_t cx2;       /**< B2 (X2) numerator coefficient - multiplies x(n-2) */
    uint32_t cx3;       /**< B3 (X3) numerator coefficient - multiplies x(n-3) */
    uint32_t cy1;       /**< A1 (Y1) denominator coefficient - multiplies y(n-1), the previous output (sign-swapped) */
    uint32_t cy2;       /**< A2 (Y2) denominator coefficient - multiplies y(n-2) (sign-swapped) */
    uint32_t cy3;       /**< A3 (Y3) denominator coefficient - multiplies y(n-3) (sign-swapped) */
}cy_stc_ppca_filter_coefficients_t;


/** HWFILT3P3Z full configuration structure.
 * This structure holds all parameters needed to initialize a HW3P3Z filter instance,
 * including the data source selection, trigger configuration, all 7 filter coefficients,
 * the output offset, saturation limits, coefficient scaling factors, and input/output gains.
 *
 * In <b>datapath mode</b> (srcSel = CY_DATA_PATH), the filter receives input from the ADC filter
 * output and writes results to a TCPWM compare register.
 * In <b>CPU accelerator mode</b> (srcSel = CY_AHB_IF), the CPU writes input values and reads
 * the filter output via AHB. */
typedef struct cy_stc_ppca_hwfilt3p3z_config
{
    cy_en_ppca_filter_src_sel_t srcSel;          /**< Source for the DATA_IN1 data register: AHB (CPU) or ADC filter output (datapath) */
    bool enTrig0;                                /**< Enable filter processing trigger on DATA_IN0 write. Only one of enTrig0/enTrig1 should be true. */
    bool enTrig1;                                /**< Enable filter processing trigger on DATA_IN1 write. Only one of enTrig0/enTrig1 should be true. */
    uint32_t cx0;                                /**< B0 (X0) numerator coefficient - 24-bit Q0.23 fixed-point */
    uint32_t cx1;                                /**< B1 (X1) numerator coefficient - 24-bit Q0.23 fixed-point */
    uint32_t cx2;                                /**< B2 (X2) numerator coefficient - 24-bit Q0.23 fixed-point */
    uint32_t cx3;                                /**< B3 (X3) numerator coefficient - 24-bit Q0.23 fixed-point */
    uint32_t cy1;                                /**< A1 (Y1) denominator coefficient - 24-bit Q0.23, sign-swapped */
    uint32_t cy2;                                /**< A2 (Y2) denominator coefficient - 24-bit Q0.23, sign-swapped */
    uint32_t cy3;                                /**< A3 (Y3) denominator coefficient - 24-bit Q0.23, sign-swapped */
    uint32_t dataOutOffset;                      /**< Additive offset applied to filter output. Uses same fixed-point format as output. */
    uint32_t limMax;                             /**< Maximum saturation limit for filter output. Output is clamped to this value if exceeded. */
    uint32_t limMin;                             /**< Minimum saturation limit for filter output. Output is clamped to this value if below. */
    uint8_t scaleCX;                             /**< B (X) coefficient scale factor: compensates for coefficient normalization (left shift applied to X partial sum) */
    uint8_t scaleCY;                             /**< A (Y) coefficient scale factor: compensates for coefficient normalization (left shift applied to Y partial sum) */
    uint8_t gIn;                                 /**< Input gain: left-shifts the input difference (x_ref - xin) by this many bits. Max value 3 (8x amplification). */
    uint8_t gOut;                                /**< Output gain (attenuation): right-shifts the output by this many bits. Used to compensate for the internal 8-bit input left shift and scaling. */
}cy_stc_ppca_hwfilt3p3z_config_t;

/** \} group_ppca_hwfilt3p3z_structures */


/***************************************
*        Function Prototypes
***************************************/

/**
* \addtogroup group_ppca_hwfilt3p3z_functions
* \{
*/

/*******************************************************************************
* Function Name: Cy_PPCA_HWFILT3P3Z_SS_PeripheralEnable
****************************************************************************//**
*
* Enables the PPCA HWFILT3P3Z subsystem block. This must be called before
* enabling individual filter instances within the subsystem.
*
* \param *base
* The PPCA HWFILT3P3Z_SS registers structure pointer.
*
*******************************************************************************/
__STATIC_INLINE void Cy_PPCA_HWFILT3P3Z_SS_PeripheralEnable(PPCA_HWFILT3P3Z_SS_Type *base)
{
    CY_ASSERT_L1(NULL != base);
    PPCA_HWFILT3P3Z_CTRL(base) |= PPCA_HWFILT3P3Z_SS_0_CTRL_HWFILT3P3Z_EN_Msk;
}


/*******************************************************************************
* Function Name: Cy_PPCA_HWFILT3P3Z_SS_PeripheralDisable
****************************************************************************//**
*
* Disables the PPCA HWFILT3P3Z subsystem block. This powers down all filter
* instances within the subsystem.
*
* \param *base
* The PPCA HWFILT3P3Z_SS registers structure pointer.
*
*******************************************************************************/
__STATIC_INLINE void Cy_PPCA_HWFILT3P3Z_SS_PeripheralDisable(PPCA_HWFILT3P3Z_SS_Type *base)
{
    PPCA_HWFILT3P3Z_CTRL(base) &= (uint32_t)~PPCA_HWFILT3P3Z_SS_0_CTRL_HWFILT3P3Z_EN_Msk;
}


/*******************************************************************************
* Function Name: Cy_PPCA_HWFILT3P3Z_FilterEnable
****************************************************************************//**
*
* Enables or disables a specific HW3P3Z filter instance. When enabled, the
* filter is ready to process data when triggered by a write to a data input
* register. When disabled, writes to data registers have no effect and any
* in-progress computation is halted.
*
* \param *base
* The PPCA HWFILT3P3Z_SS registers structure pointer.
*
* \param enable
* true: enables the filter instance for processing.
* false: disables the filter instance.
*
*******************************************************************************/
__STATIC_INLINE void Cy_PPCA_HWFILT3P3Z_FilterEnable(PPCA_HWFILT3P3Z_SS_HWFILT3P3Z_Type *base, bool enable)
{
    if(enable)
    {
        PPCA_HWFILT3P3Z_SS_CTRL(base) |= PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z_CTRL_FILTER_EN_Msk;
    }
    else
    {
        PPCA_HWFILT3P3Z_SS_CTRL(base) &= (uint32_t)~PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z_CTRL_FILTER_EN_Msk;
    }
}


/*******************************************************************************
* Function Name: Cy_PPCA_HWFILT3P3Z_InitFilterConfig
****************************************************************************//**
*
* Performs a complete initialization of a HW3P3Z filter instance by configuring
* all parameters in a single call: data source selection, processing trigger,
* all 7 filter coefficients (B0-B3, A1-A3), the output offset, saturation
* limits, coefficient scaling factors, and input/output gains.
*
* This is the recommended initialization function. For runtime reconfiguration
* of individual parameters, use the dedicated Config functions
* (e.g. \ref Cy_PPCA_HWFILT3P3Z_ConfigCoefficients).
*
* \param *base
* The PPCA HWFILT3P3Z_SS registers structure pointer.
*
* \param *config
* The pointer to the HWFILT3P3Z configuration structure.
* See \ref cy_stc_ppca_hwfilt3p3z_config_t for field descriptions.
*
* \snippet ppca/snippet/ppca_snippet.c SNIPPET_PPCA_HWFILT3P3Z_INIT
*
*******************************************************************************/
void Cy_PPCA_HWFILT3P3Z_InitFilterConfig(PPCA_HWFILT3P3Z_SS_HWFILT3P3Z_Type *base, cy_stc_ppca_hwfilt3p3z_config_t const *config);


/*******************************************************************************
* Function Name: Cy_PPCA_HWFILT3P3Z_ReadFilterStatus
****************************************************************************//**
*
* Returns the busy status of the filter. The filter becomes busy when a
* computation is triggered (by writing to a data input register) and returns
* to free state after the computation completes. Maximum computation latency
* is 8 CPU clock cycles.
*
* \param *base
* The PPCA HWFILT3P3Z_SS registers structure pointer.
*
* \return
* The filter busy status. \ref cy_en_ppca_filter_status_t .
* - CY_FILTER_IS_FREE: filter is idle and output data is valid.
* - CY_FILTER_IS_BUSY: filter is computing; output is not yet available.
*
*******************************************************************************/

__STATIC_INLINE cy_en_ppca_filter_status_t Cy_PPCA_HWFILT3P3Z_ReadFilterStatus(PPCA_HWFILT3P3Z_SS_HWFILT3P3Z_Type *base)
{
    uint32_t ss_ctrl = _FLD2VAL(PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z_CTRL_FILTER_BUSY, PPCA_HWFILT3P3Z_SS_CTRL(base));
    return (cy_en_ppca_filter_status_t)(ss_ctrl);
}


/*******************************************************************************
* Function Name: Cy_PPCA_HWFILT3P3Z_ReadFilterDataOutput
****************************************************************************//**
*
* Reads the 24-bit filter computation output. The output includes any
* configured offset addition, output gain (right shift), and saturation
* clamping to the limMin/limMax range.
*
* \note Ensure the filter is not busy (\ref Cy_PPCA_HWFILT3P3Z_ReadFilterStatus
* returns CY_FILTER_IS_FREE) before reading the output to guarantee valid data.
*
* \param *base
* The PPCA HWFILT3P3Z_SS registers structure pointer.
*
* \return
* Signed 24-bit filter data output, sign-extended to 32 bits.
*
*******************************************************************************/
__STATIC_INLINE int32_t Cy_PPCA_HWFILT3P3Z_ReadFilterDataOutput(PPCA_HWFILT3P3Z_SS_HWFILT3P3Z_Type *base)
{
    return (int32_t)PPCA_HWFILT3P3Z_SS_DATA_OUT(base);  /* TBD */
}


/*******************************************************************************
* Function Name: Cy_PPCA_HWFILT3P3Z_ConfigFilterProcessing
****************************************************************************//**
*
* Configures the filter processing parameters: the data source for DATA_IN1
* and which data input register triggers filter computation.
*
* In <b>datapath mode</b>, set srcSel to CY_DATA_PATH so DATA_IN1 receives
* samples directly from the ADC filter output. In <b>CPU accelerator mode</b>,
* set srcSel to CY_AHB_IF for CPU-driven input.
*
* \param *base
* The PPCA HWFILT3P3Z_SS registers structure pointer.
*
* \param srcSel
* The data source for register DATA_IN1. \ref cy_en_ppca_filter_src_sel_t.
*
* \param data_in
* Selects which data register triggers filter computation. \ref cy_en_ppca_filter_data_sel_t.
* Only one of DATA_IN0 or DATA_IN1 should be enabled as the trigger source.
*
*******************************************************************************/
__STATIC_INLINE void Cy_PPCA_HWFILT3P3Z_ConfigFilterProcessing(PPCA_HWFILT3P3Z_SS_HWFILT3P3Z_Type *base, cy_en_ppca_filter_src_sel_t srcSel, cy_en_ppca_filter_data_sel_t data_in)
{
    PPCA_HWFILT3P3Z_SS_CNFG(base) = _VAL2FLD(PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z_CNFG_SRC_SEL, srcSel) |
                                    _VAL2FLD(PPCA_HWFILT3P3Z_CNFG_EN_DATA_IN, data_in);
}

/*******************************************************************************
* Function Name: Cy_PPCA_HWFILT3P3Z_Write_DATA_IN0
****************************************************************************//**
*
* Writes a 16-bit input sample to the DATA_IN0 register. If enTrig0 is enabled
* in the filter configuration, this write also triggers filter computation.
* The input is internally left-shifted by 8 bits before processing.
*
* \param *base
* The PPCA HWFILT3P3Z_SS registers structure pointer.
*
* \param inputData
* 16-bit signed input sample value.
*
*******************************************************************************/
__STATIC_INLINE void Cy_PPCA_HWFILT3P3Z_Write_DATA_IN0(PPCA_HWFILT3P3Z_SS_HWFILT3P3Z_Type *base, int32_t inputData)
{
    PPCA_HWFILT3P3Z_SS_DATA_IN0(base) = (uint32_t)inputData;
}



/*******************************************************************************
* Function Name: Cy_PPCA_HWFILT3P3Z_Write_DATA_IN1
****************************************************************************//**
*
* Writes a 16-bit input sample to the DATA_IN1 register. If enTrig1 is enabled
* in the filter configuration, this write also triggers filter computation.
* In datapath mode (srcSel = CY_DATA_PATH), this register is automatically
* written by the ADC filter output and should not be written by the CPU.
*
* \param *base
* The PPCA HWFILT3P3Z_SS registers structure pointer.
*
* \param inputData
* 16-bit signed input sample value.
*
*******************************************************************************/
__STATIC_INLINE void Cy_PPCA_HWFILT3P3Z_Write_DATA_IN1(PPCA_HWFILT3P3Z_SS_HWFILT3P3Z_Type *base, int32_t inputData)
{
    PPCA_HWFILT3P3Z_SS_DATA_IN1(base) = (uint32_t)inputData;
}


/*******************************************************************************
* Function Name: Cy_PPCA_HWFILT3P3Z_ConfigCoefficients
****************************************************************************//**
*
* Programs all 7 filter coefficients (B0-B3 numerator / X coefficients and
* A1-A3 denominator / Y coefficients) into the hardware registers.
*
* Coefficients are 24-bit signed fixed-point values in Q0.23 format, stored
* in the lower 24 bits of each 32-bit register. If any coefficient exceeds
* the [-1, +1) range, it must be scaled down by dividing by 2 and the
* corresponding scale factor (scaleCX or scaleCY) incremented.
*
* \note Y coefficients must be sign-swapped (negated) before passing to this
* function, as required by the filter's difference equation.
*
* \param *base
* The PPCA HWFILT3P3Z_SS registers structure pointer.
*
* \param *config
* The pointer to the HWFILT3P3Z filter coefficients structure.
* \ref cy_stc_ppca_filter_coefficients_t .
*
*******************************************************************************/
__STATIC_INLINE void Cy_PPCA_HWFILT3P3Z_ConfigCoefficients(PPCA_HWFILT3P3Z_SS_HWFILT3P3Z_Type *base, cy_stc_ppca_filter_coefficients_t const *config)
{
    PPCA_HWFILT3P3Z_SS_CX0(base) = config->cx0;
    PPCA_HWFILT3P3Z_SS_CX1(base) = config->cx1;
    PPCA_HWFILT3P3Z_SS_CX2(base) = config->cx2;
    PPCA_HWFILT3P3Z_SS_CX3(base) = config->cx3;
    PPCA_HWFILT3P3Z_SS_CY1(base) = config->cy1;
    PPCA_HWFILT3P3Z_SS_CY2(base) = config->cy2;
    PPCA_HWFILT3P3Z_SS_CY3(base) = config->cy3;
}

/*******************************************************************************
* Function Name: Cy_PPCA_HWFILT3P3Z_ConfigOffset
****************************************************************************//**
*
* Configures the additive output offset. This value is added to the filter
* computation result before saturation clamping. The offset uses the same
* fixed-point format (same number of fractional bits) as the filter output.
*
* \param *base
* The PPCA HWFILT3P3Z_SS registers structure pointer.
*
* \param offset
* The signed offset value to add to the filter output.
*
*******************************************************************************/
__STATIC_INLINE void Cy_PPCA_HWFILT3P3Z_ConfigOffset(PPCA_HWFILT3P3Z_SS_HWFILT3P3Z_Type *base, int32_t offset)
{
    PPCA_HWFILT3P3Z_SS_OFFSET(base) = (uint32_t)offset;
}


/*******************************************************************************
* Function Name: Cy_PPCA_HWFILT3P3Z_ConfigFilterOutLimits
****************************************************************************//**
*
* Configures the output saturation limits. The filter output is clamped to
* the range [lmin, lmax]. If y(n) < lmin, output is set to lmin.
* If y(n) > lmax, output is set to lmax.
*
* These limits are essential for protecting the downstream hardware (e.g.,
* TCPWM duty cycle) from out-of-range values.
*
* \param *base
* The PPCA HWFILT3P3Z_SS registers structure pointer.
*
* \param lmax
* The maximum saturation limit for the filter output.
*
* \param lmin
* The minimum saturation limit for the filter output.
*
*******************************************************************************/
__STATIC_INLINE void Cy_PPCA_HWFILT3P3Z_ConfigFilterOutLimits(PPCA_HWFILT3P3Z_SS_HWFILT3P3Z_Type *base, int32_t lmax, int32_t lmin)
{
    PPCA_HWFILT3P3Z_SS_LIMMAX(base) = (uint32_t)lmax;
    PPCA_HWFILT3P3Z_SS_LIMMIN(base) = (uint32_t)lmin;
}


/*******************************************************************************
* Function Name: Cy_PPCA_HWFILT3P3Z_ConfigCoefficientScaleFactors
****************************************************************************//**
*
* Configures the scaling factors that compensate for coefficient normalization.
* When floating-point coefficients exceed the [-1, +1) range and are normalized
* by dividing by powers of 2, the corresponding scale factor is set to re-apply
* the removed magnitude as a left shift on the partial sum during computation.
*
* For example, if B coefficients were divided by 4 (two halvings) to fit in
* [-1, +1), set scaleCX to CY_SCALE_FACTOR_2 to apply a 2-bit left shift.
*
* \param *base
* The PPCA HWFILT3P3Z_SS registers structure pointer.
*
* \param scaleCX
* Scale factor for B (numerator / X) coefficients. \ref cy_en_ppca_filter_scale_factor_t.
*
* \param scaleCY
* Scale factor for A (denominator / Y) coefficients. \ref cy_en_ppca_filter_scale_factor_t.
*
*******************************************************************************/
__STATIC_INLINE void Cy_PPCA_HWFILT3P3Z_ConfigCoefficientScaleFactors(PPCA_HWFILT3P3Z_SS_HWFILT3P3Z_Type *base, cy_en_ppca_filter_scale_factor_t scaleCX, cy_en_ppca_filter_scale_factor_t scaleCY)
{
    PPCA_HWFILT3P3Z_SS_SCALECX(base) = (uint32_t)scaleCX;
    PPCA_HWFILT3P3Z_SS_SCALECY(base) = (uint32_t)scaleCY;
}


/*******************************************************************************
* Function Name: Cy_PPCA_HWFILT3P3Z_ConfigGains
****************************************************************************//**
*
* Configures the input amplification and output attenuation gains.
*
* gIn applies a left shift to the input difference (x_ref - xin), amplifying
* the error signal. Maximum value is 3, providing up to 8x amplification.
*
* gOut applies a right shift to the output value. This is used to counter-balance
* the internal 8-bit left shift on the input path (which converts the 16-bit
* input to the 24-bit internal domain) and any coefficient scaling applied.
*
* \param *base
* The PPCA HWFILT3P3Z_SS registers structure pointer.
*
* \param gIn
* Input amplification factor (number of left-shift bits). Max value: 3.
*
* \param gOut
* Output attenuation factor (number of right-shift bits).
*
*******************************************************************************/
__STATIC_INLINE void Cy_PPCA_HWFILT3P3Z_ConfigGains(PPCA_HWFILT3P3Z_SS_HWFILT3P3Z_Type *base, uint8_t gIn, uint8_t gOut)
{
    PPCA_HWFILT3P3Z_SS_GIN(base)  = gIn;
    PPCA_HWFILT3P3Z_SS_GOUT(base) = gOut;
}


/*******************************************************************************
* Function Name: Cy_PPCA_HWFILT3P3Z_SS_GetPeripheralEnable
****************************************************************************//**
*
* Returns whether the PPCA HWFILT3P3Z subsystem block is enabled.
*
* \param *base
* The PPCA HWFILT3P3Z_SS registers structure pointer.
*
* \return
* true if the subsystem is enabled, false otherwise.
*
*******************************************************************************/
__STATIC_INLINE bool Cy_PPCA_HWFILT3P3Z_SS_GetPeripheralEnable(PPCA_HWFILT3P3Z_SS_Type *base)
{
    CY_ASSERT_L1(NULL != base);
    return (0UL != (PPCA_HWFILT3P3Z_CTRL(base) & PPCA_HWFILT3P3Z_SS_0_CTRL_HWFILT3P3Z_EN_Msk));
}


/*******************************************************************************
* Function Name: Cy_PPCA_HWFILT3P3Z_GetFilterEnable
****************************************************************************//**
*
* Returns whether a specific HW3P3Z filter instance is enabled.
*
* \param *base
* The PPCA HWFILT3P3Z_SS_HWFILT3P3Z registers structure pointer.
*
* \return
* true if the filter instance is enabled, false otherwise.
*
*******************************************************************************/
__STATIC_INLINE bool Cy_PPCA_HWFILT3P3Z_GetFilterEnable(PPCA_HWFILT3P3Z_SS_HWFILT3P3Z_Type *base)
{
    CY_ASSERT_L1(NULL != base);
    return (0UL != (PPCA_HWFILT3P3Z_SS_CTRL(base) & PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z_CTRL_FILTER_EN_Msk));
}


/*******************************************************************************
* Function Name: Cy_PPCA_HWFILT3P3Z_GetFilterProcessing
****************************************************************************//**
*
* Reads back the filter processing configuration: the data source for DATA_IN1
* and which data input register triggers filter computation.
*
* \param *base
* The PPCA HWFILT3P3Z_SS_HWFILT3P3Z registers structure pointer.
*
* \param *srcSel
* Pointer to store the data source selection for DATA_IN1.
* \ref cy_en_ppca_filter_src_sel_t.
*
* \param *data_in
* Pointer to store the data register trigger selection.
* \ref cy_en_ppca_filter_data_sel_t.
*
*******************************************************************************/
__STATIC_INLINE void Cy_PPCA_HWFILT3P3Z_GetFilterProcessing(PPCA_HWFILT3P3Z_SS_HWFILT3P3Z_Type *base,
                                                              cy_en_ppca_filter_src_sel_t *srcSel,
                                                              cy_en_ppca_filter_data_sel_t *data_in)
{
    CY_ASSERT_L1(CY_IS_HWFILTER_PARAM_VALID(base));
    CY_ASSERT_L1(NULL != srcSel);
    CY_ASSERT_L1(NULL != data_in);
    uint32_t cnfg = PPCA_HWFILT3P3Z_SS_CNFG(base);
    *srcSel = (cy_en_ppca_filter_src_sel_t)_FLD2VAL(PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z_CNFG_SRC_SEL, cnfg);
    bool trig1 = (0UL != _FLD2VAL(PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z_CNFG_EN_TRIG1, cnfg));
    bool trig0 = (0UL != _FLD2VAL(PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z_CNFG_EN_TRIG0, cnfg));
    *data_in = trig1 ? CY_ENABLE_DATA_IN1 : (trig0 ? CY_ENABLE_DATA_IN0 : CY_DISABLE_DATA_IN);
}


/*******************************************************************************
* Function Name: Cy_PPCA_HWFILT3P3Z_GetCoefficients
****************************************************************************//**
*
* Reads back all 7 filter coefficients (B0-B3 numerator / X coefficients and
* A1-A3 denominator / Y coefficients) from the hardware registers.
*
* The values are the raw 24-bit Q0.23 fixed-point register contents.
* Y coefficients are returned as stored in hardware (sign-swapped form).
*
* \param *base
* The PPCA HWFILT3P3Z_SS_HWFILT3P3Z registers structure pointer.
*
* \param *config
* Pointer to the coefficient structure to populate.
* \ref cy_stc_ppca_filter_coefficients_t.
*
*******************************************************************************/
__STATIC_INLINE void Cy_PPCA_HWFILT3P3Z_GetCoefficients(PPCA_HWFILT3P3Z_SS_HWFILT3P3Z_Type *base,
                                                          cy_stc_ppca_filter_coefficients_t *config)
{
    CY_ASSERT_L1(CY_IS_HWFILTER_PARAM_VALID(base));
    CY_ASSERT_L1(NULL != config);
    config->cx0 = PPCA_HWFILT3P3Z_SS_CX0(base);
    config->cx1 = PPCA_HWFILT3P3Z_SS_CX1(base);
    config->cx2 = PPCA_HWFILT3P3Z_SS_CX2(base);
    config->cx3 = PPCA_HWFILT3P3Z_SS_CX3(base);
    config->cy1 = PPCA_HWFILT3P3Z_SS_CY1(base);
    config->cy2 = PPCA_HWFILT3P3Z_SS_CY2(base);
    config->cy3 = PPCA_HWFILT3P3Z_SS_CY3(base);
}


/*******************************************************************************
* Function Name: Cy_PPCA_HWFILT3P3Z_GetOffset
****************************************************************************//**
*
* Reads back the additive output offset value from the hardware register.
*
* \param *base
* The PPCA HWFILT3P3Z_SS_HWFILT3P3Z registers structure pointer.
*
* \return
* The signed offset value added to the filter output.
*
*******************************************************************************/
__STATIC_INLINE int32_t Cy_PPCA_HWFILT3P3Z_GetOffset(PPCA_HWFILT3P3Z_SS_HWFILT3P3Z_Type *base)
{
    CY_ASSERT_L1(CY_IS_HWFILTER_PARAM_VALID(base));
    return (int32_t)PPCA_HWFILT3P3Z_SS_OFFSET(base);
}


/*******************************************************************************
* Function Name: Cy_PPCA_HWFILT3P3Z_GetFilterOutLimits
****************************************************************************//**
*
* Reads back the output saturation limits from the hardware registers.
*
* \param *base
* The PPCA HWFILT3P3Z_SS_HWFILT3P3Z registers structure pointer.
*
* \param *lmax
* Pointer to store the maximum saturation limit.
*
* \param *lmin
* Pointer to store the minimum saturation limit.
*
*******************************************************************************/
__STATIC_INLINE void Cy_PPCA_HWFILT3P3Z_GetFilterOutLimits(PPCA_HWFILT3P3Z_SS_HWFILT3P3Z_Type *base,
                                                             int32_t *lmax, int32_t *lmin)
{
    CY_ASSERT_L1(CY_IS_HWFILTER_PARAM_VALID(base));
    CY_ASSERT_L1(NULL != lmax);
    CY_ASSERT_L1(NULL != lmin);
    *lmax = (int32_t)PPCA_HWFILT3P3Z_SS_LIMMAX(base);
    *lmin = (int32_t)PPCA_HWFILT3P3Z_SS_LIMMIN(base);
}


/*******************************************************************************
* Function Name: Cy_PPCA_HWFILT3P3Z_GetCoefficientScaleFactors
****************************************************************************//**
*
* Reads back the coefficient scaling factors from the hardware registers.
*
* \param *base
* The PPCA HWFILT3P3Z_SS_HWFILT3P3Z registers structure pointer.
*
* \param *scaleCX
* Pointer to store the B (numerator / X) coefficient scale factor.
* \ref cy_en_ppca_filter_scale_factor_t.
*
* \param *scaleCY
* Pointer to store the A (denominator / Y) coefficient scale factor.
* \ref cy_en_ppca_filter_scale_factor_t.
*
*******************************************************************************/
__STATIC_INLINE void Cy_PPCA_HWFILT3P3Z_GetCoefficientScaleFactors(PPCA_HWFILT3P3Z_SS_HWFILT3P3Z_Type *base,
                                                                     cy_en_ppca_filter_scale_factor_t *scaleCX,
                                                                     cy_en_ppca_filter_scale_factor_t *scaleCY)
{
    CY_ASSERT_L1(CY_IS_HWFILTER_PARAM_VALID(base));
    CY_ASSERT_L1(NULL != scaleCX);
    CY_ASSERT_L1(NULL != scaleCY);
    *scaleCX = (cy_en_ppca_filter_scale_factor_t)PPCA_HWFILT3P3Z_SS_SCALECX(base);
    *scaleCY = (cy_en_ppca_filter_scale_factor_t)PPCA_HWFILT3P3Z_SS_SCALECY(base);
}


/*******************************************************************************
* Function Name: Cy_PPCA_HWFILT3P3Z_GetGains
****************************************************************************//**
*
* Reads back the input amplification and output attenuation gain values from
* the hardware registers.
*
* \param *base
* The PPCA HWFILT3P3Z_SS_HWFILT3P3Z registers structure pointer.
*
* \param *gIn
* Pointer to store the input gain (number of left-shift bits).
*
* \param *gOut
* Pointer to store the output gain (number of right-shift bits).
*
*******************************************************************************/
__STATIC_INLINE void Cy_PPCA_HWFILT3P3Z_GetGains(PPCA_HWFILT3P3Z_SS_HWFILT3P3Z_Type *base,
                                                   uint8_t *gIn, uint8_t *gOut)
{
    CY_ASSERT_L1(CY_IS_HWFILTER_PARAM_VALID(base));
    CY_ASSERT_L1(NULL != gIn);
    CY_ASSERT_L1(NULL != gOut);
    *gIn  = (uint8_t)PPCA_HWFILT3P3Z_SS_GIN(base);
    *gOut = (uint8_t)PPCA_HWFILT3P3Z_SS_GOUT(base);
}


/*******************************************************************************
* Function Name: Cy_PPCA_HWFILT3P3Z_GetFilterConfig
****************************************************************************//**
*
* Reads back the complete filter configuration from all hardware registers into
* a \ref cy_stc_ppca_hwfilt3p3z_config_t structure. This is the reverse of
* \ref Cy_PPCA_HWFILT3P3Z_InitFilterConfig and is intended for save/restore
* use cases (e.g., STL self-test invocations).
*
* \note The CTRL FILTER_EN bit (enable state) is not part of
* cy_stc_ppca_hwfilt3p3z_config_t. Use \ref Cy_PPCA_HWFILT3P3Z_GetFilterEnable
* separately to save/restore the enable state.
*
* \param *base
* The PPCA HWFILT3P3Z_SS_HWFILT3P3Z registers structure pointer.
*
* \param *config
* Pointer to the configuration structure to populate with register readback values.
* See \ref cy_stc_ppca_hwfilt3p3z_config_t for field descriptions.
*
*******************************************************************************/
__STATIC_INLINE void Cy_PPCA_HWFILT3P3Z_GetFilterConfig(PPCA_HWFILT3P3Z_SS_HWFILT3P3Z_Type *base,
                                                          cy_stc_ppca_hwfilt3p3z_config_t *config)
{
    CY_ASSERT_L1(CY_IS_HWFILTER_PARAM_VALID(base));
    CY_ASSERT_L1(CY_IS_HWFILTER_PARAM_VALID(config));

    uint32_t cnfg = PPCA_HWFILT3P3Z_SS_CNFG(base);
    config->srcSel       = (cy_en_ppca_filter_src_sel_t)_FLD2VAL(PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z_CNFG_SRC_SEL, cnfg);
    config->enTrig0      = (0UL != _FLD2VAL(PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z_CNFG_EN_TRIG0, cnfg));
    config->enTrig1      = (0UL != _FLD2VAL(PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z_CNFG_EN_TRIG1, cnfg));
    config->cx0          = PPCA_HWFILT3P3Z_SS_CX0(base);
    config->cx1          = PPCA_HWFILT3P3Z_SS_CX1(base);
    config->cx2          = PPCA_HWFILT3P3Z_SS_CX2(base);
    config->cx3          = PPCA_HWFILT3P3Z_SS_CX3(base);
    config->cy1          = PPCA_HWFILT3P3Z_SS_CY1(base);
    config->cy2          = PPCA_HWFILT3P3Z_SS_CY2(base);
    config->cy3          = PPCA_HWFILT3P3Z_SS_CY3(base);
    config->dataOutOffset = PPCA_HWFILT3P3Z_SS_OFFSET(base);
    config->limMax       = PPCA_HWFILT3P3Z_SS_LIMMAX(base);
    config->limMin       = PPCA_HWFILT3P3Z_SS_LIMMIN(base);
    config->scaleCX      = (uint8_t)PPCA_HWFILT3P3Z_SS_SCALECX(base);
    config->scaleCY      = (uint8_t)PPCA_HWFILT3P3Z_SS_SCALECY(base);
    config->gIn          = (uint8_t)PPCA_HWFILT3P3Z_SS_GIN(base);
    config->gOut         = (uint8_t)PPCA_HWFILT3P3Z_SS_GOUT(base);
}


/** \} group_ppca_hwfilt3p3z_functions */

#if defined(__cplusplus)
}
#endif

#endif /* #if defined(CY_IP_MXS40PPSS) */

#endif /* (CY_PPCA_HWFILT3P3Z_H) */

/** \} group_ppca_hwfilt3p3z */

/* [] END OF FILE */
