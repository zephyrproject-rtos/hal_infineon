/***************************************************************************//**
* \file cy_hppass_hwfilt3p3z.h
* \version 1.10
*
* Provides the API declarations of the HPPASS HW Filter 3P3Z driver.
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
* \addtogroup group_hppass_hwfilt3p3z
* \{
*
* \section group_hppass_hwfilt3p3z_glossary Glossary
*  The HW3P3Z module is a Soft IP. It implements a configurable HW filter function, three poles / three zeroes.
*  The HW3P3Z features:
* * 3 poles, 3 zeroes
* * 16-bit input, 24-bit output
* * 40-bit multiplier
* * 44-bit internal accumulator
* * Max 8 CPU clock cycles execution latency
* * Saturation Operators supported
* * Arithmetic 2's complement
* * Programmed and programmable data path
* * Filter processing triggered by writing into one of the two data registers
* * Generates a pulse event at the completion of Filter computation
* * AHB Slave interface (AHB interface is chosen to reduce the access latency)
* * Register Slave interface (connected to ADC_FILT outputs)
*
*
* Equations:
* * x(n)= x_ref- xin(n)
* * y(n) = Sigma(i=0 to 3) [bi.x(n-i)] - Sigma(j=1 to 3) [aj.y(n-j)]
* * y(out)=y(n)+Offset
* * y(out)=y(n),  LimMin  <= y(n) <= LimMax
* * y(out)=LimMin,LimMin > y(n)
* * y(out)=LimMax,   LimMax <= y(n)
*
* The 3-Pole/ 3-Zero (3P3Z) Compensator is the digital implementation of the analog type III controller.
* It is a filter that introduces a specific gain and phase boost into the system by considering three poles and three zeroes.
*
* The 3P3Z is implementing a fixed-point structure with 24bits coefficient registers, in which 1 bit is for the sign,
* remaining for the fractional value.
* Input to 3p3z filter is a 16 bit value.
* Output from 3p3z filter is a fixed-point 24 bit value.
* Coefficients are also fixed-point 24 bit values, ranged between 1 and -1.
* If any x coefficient is greater than 1 then divide all the x coefficients by 2 and add 1 to scaleCX to match the reduced value. \ref cy_stc_hppass_hwfilt3p3z_config_t
* If any y coefficient is greater than 1 then divide all the y coefficients by 2 and add 1 to scaleCY to match the reduced value. \ref cy_stc_hppass_hwfilt3p3z_config_t
* All the Y coefficients must swap the sign: if it is a negative value, it should be converted to positive, and if it is positive, it should be converted to negative. This is to numerically solve Transfer Function equation.
* dataOutOffset is direct addition to the output value. dataOutOffset will also contain the same number of fractional bits as actual output. \ref cy_stc_hppass_hwfilt3p3z_config_t
* gIn is mainly for amplifying the output. maximum supported value is 3 ie the output will be left shifted by 3. \ref cy_stc_hppass_hwfilt3p3z_config_t
* gOut is mainly to scale down. output is right shifted by the gOut value. \ref cy_stc_hppass_hwfilt3p3z_config_t
*
* Floating point to Hex conversion
* * All the floating points are 23 bit fractional values.
* * Multiply the floating pointer number with 2^23.
* * Convert the resulting integer to hex. The binary representation will have 23 bits.
* * If the floating point number is a negative number then calculate the 2's complement of the resulting hex.
*
* \section group_hppass_hwfilt3p3z_changelog Changelog
* <table class="doxtable">
*   <tr><th>Version</th><th>Changes</th><th>Reason for Change</th></tr>
*   <tr>
*     <td>1.10</td>
*     <td>Added getter/readback APIs: \ref Cy_HPPASS_HWFILT3P3Z_GetCoefficients,
*         \ref Cy_HPPASS_HWFILT3P3Z_GetOffset, \ref Cy_HPPASS_HWFILT3P3Z_GetFilterOutLimits,
*         \ref Cy_HPPASS_HWFILT3P3Z_GetCoefficientScaleFactors, \ref Cy_HPPASS_HWFILT3P3Z_GetGains,
*         \ref Cy_HPPASS_HWFILT3P3Z_GetAntiWindup, \ref Cy_HPPASS_HWFILT3P3Z_GetFilterProcessing,
*         \ref Cy_HPPASS_HWFILT3P3Z_GetFilterEnable, \ref Cy_HPPASS_HWFILT3P3Z_TOP_GetPeripheralEnable,
*         and consolidated \ref Cy_HPPASS_HWFILT3P3Z_GetFilterConfig.</td>
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
* \defgroup group_hppass_hwfilt3p3z_functions Functions
* \defgroup group_hppass_hwfilt3p3z_structures Configuration Structures
* \defgroup group_hppass_hwfilt3p3z_enums Enumerations
* \defgroup group_hppass_hwfilt3p3z_macros Macros
*
*/
#if !defined(CY_HPPASS_HWFILT3P3Z_H)
#define CY_HPPASS_HWFILT3P3Z_H

#include "cy_device.h"

#if (defined (CY_IP_MXS40MCPASS) && (CY_IP_MXS40MCPASS_VERSION >= 3u)) || defined (CY_DOXYGEN)

#include "cy_syslib.h"

#if defined(__cplusplus)
extern "C" {
#endif

/***************************************
*       Macros
***************************************/

/**
* \addtogroup group_hppass_hwfilt3p3z_macros
* \{
*/
/** The driver major version */
#define CY_HPPASS_HWFILT3P3Z_DRV_VERSION_MAJOR       1U

/** The driver minor version */
#define CY_HPPASS_HWFILT3P3Z_DRV_VERSION_MINOR       10U

/** The HPPASS HWFILT3P3Z driver ID */
#define CY_HPPASS_HWFILT3P3Z_ID                      CY_PDL_DRV_ID(CY_PDL_RSLT_MODULE_HPPASS_HWFILT3P3Z)

/** The number of HW Filter 3P3Z instances available */
#define CY_HPPASS_HWFILT3P3Z_NUM_INSTANCE            (4U)

/** Macro for validating the filter instance index */
#define CY_HPPASS_HWFILT3P3Z_INDEX_VALID(filtIdx)    (CY_HPPASS_HWFILT3P3Z_NUM_INSTANCE > (filtIdx))

/** \cond INTERNAL */

#define CY_IS_HWFILTER_PARAM_VALID(param)              (NULL != param)
#define HPPASS_HWFILT3P3Z_CNFG_EN_DATA_IN_Pos (HPPASS_MX3P3ZFILT_HWFILT3P3Z_CNFG_EN_TRIG0_Pos)
#define HPPASS_HWFILT3P3Z_CNFG_EN_DATA_IN_Msk (HPPASS_MX3P3ZFILT_HWFILT3P3Z_CNFG_EN_TRIG0_Msk | HPPASS_MX3P3ZFILT_HWFILT3P3Z_CNFG_EN_TRIG1_Msk)

/** \endcond */

/** \} group_hppass_hwfilt3p3z_macros */


/***************************************
*       Enumerations
***************************************/
/**
* \addtogroup group_hppass_hwfilt3p3z_enums
* \{
*/

/** Source for DATA_IN1 data register */
typedef enum
{
    CY_AHB_IF    = 0U,   /**< The register is sourced from AHB interface */
    CY_DATA_PATH = 1U,  /**< The register is sourced from the ADC Filter */
}cy_en_hppass_filter_src_sel_t;

/** Data from DATA IN0 or DATA IN1 */
typedef enum
{
    CY_DISABLE_DATA_IN     = 0U,  /**< Both DATA IN0 and DATA IN1 are disabled. */
    CY_ENABLE_DATA_IN0     = 1U,  /**< DATA IN0 is enabled. */
    CY_ENABLE_DATA_IN1     = 2U,  /**< DATA IN1 is enabled. */
}cy_en_hppass_filter_data_sel_t;


/** Scale Factors for Coefficients */
typedef enum
{
    CY_SCALE_FACTOR_0 = 0U,  /**< Scale Factor is 0 */
    CY_SCALE_FACTOR_1 = 1U,  /**< Scale Factor is 1 */
    CY_SCALE_FACTOR_2 = 2U,  /**< Scale Factor is 2 */
    CY_SCALE_FACTOR_3 = 3U,  /**< Scale Factor is 3 */
    CY_SCALE_FACTOR_4 = 4U,  /**< Scale Factor is 4 */
    CY_SCALE_FACTOR_5 = 5U,  /**< Scale Factor is 5 */
    CY_SCALE_FACTOR_6 = 6U,  /**< Scale Factor is 6 */
    CY_SCALE_FACTOR_7 = 7U,  /**< Scale Factor is 7 */
}cy_en_hppass_filter_scale_factor_t;


/** Filter Status */
typedef enum
{
    CY_FILTER_IS_FREE    = 0U,  /**< The filter is free */
    CY_FILTER_IS_BUSY    = 1U,  /**< The filer is busy */
}cy_en_hppass_filter_status_t;

/** \} group_hppass_hwfilt3p3z_enums */


/***************************************
*       Configuration Structures
***************************************/

/**
* \addtogroup group_hppass_hwfilt3p3z_structures
* \{
*/

/** Filter Coefficients */
typedef struct cy_stc_hppass_filter_coefficients
{
    uint32_t cx0;       /**< X0 coefficient data */
    uint32_t cx1;       /**< X1 coefficient data */
    uint32_t cx2;       /**< X2 coefficient data */
    uint32_t cx3;       /**< X3 coefficient data */
    uint32_t cy1;       /**< Y1 coefficient data */
    uint32_t cy2;       /**< Y2 coefficient data */
    uint32_t cy3;       /**< Y3 coefficient data */
}cy_stc_hppass_filter_coefficients_t;


/** HWFILT3P3Z configuration structure */
typedef struct cy_stc_hppass_hwfilt3p3z_config
{
    cy_en_hppass_filter_src_sel_t srcSel;          /**< Source for the DATA_IN1 data register */
    bool enTrig0;                                /**< Enable/Disable filter processing on writing into DATA_IN0. enTrig0 and enTrig1 should not be set at the same time */
    bool enTrig1;                                /**< Enable/Disable filter processing on writing into DATA_IN1. enTrig0 and enTrig1 should not be set at the same time */
    uint32_t cx0;                                /**< X0 coefficient data */
    uint32_t cx1;                                /**< X1 coefficient data */
    uint32_t cx2;                                /**< X2 coefficient data */
    uint32_t cx3;                                /**< X3 coefficient data */
    uint32_t cy1;                                /**< Y1 coefficient data */
    uint32_t cy2;                                /**< Y2 coefficient data */
    uint32_t cy3;                                /**< Y3 coefficient data */
    uint32_t dataOutOffset;                      /**< Filter data out offset */
    uint32_t limMax;                             /**< Max limit of filter out */
    uint32_t limMin;                             /**< Min limit of filter out */
    uint8_t scaleCX;                             /**< Scale X coefficients factor */
    uint8_t scaleCY;                             /**< Scale Y coefficients factor */
    uint8_t gIn;                                 /**< Amplify input difference factor */
    uint8_t gOut;                                /**< Scale down output factor */
    uint32_t awMax;                              /**< Anti-windup max limit (24-bit) */
    uint32_t awMin;                              /**< Anti-windup min limit (24-bit) */
    uint32_t awGain;                             /**< Anti-windup gain (24-bit) */
    uint8_t channelSel;                            /**< SAR ADC channel selection for the 3P3Z filter input.
                                                    *   0 = Disabled (no channel selected).
                                                    *   1..35 = SAR channel 0..34 (register value = channel number + 1).
                                                    *   Written to HWFILT3P3Z_IND_CTRL[filtIdx].CHANNEL_SEL.
                                                    *   Only applicable for filter instances 0..2.
                                                    */
}cy_stc_hppass_hwfilt3p3z_config_t;

/** \} group_hppass_hwfilt3p3z_structures */


/***************************************
*        Function Prototypes
***************************************/

/**
* \addtogroup group_hppass_hwfilt3p3z_functions
* \{
*/

/*******************************************************************************
* Function Name: Cy_HPPASS_HWFILT3P3Z_TOP_PeripheralEnable
****************************************************************************//**
*
* Enables HPPASS HWFILT3P3Z TOP block.
*
*******************************************************************************/
__STATIC_INLINE void Cy_HPPASS_HWFILT3P3Z_TOP_PeripheralEnable(void)
{
    HPPASS_HWFILT3P3Z_TOP_CTRL(HPPASS_BASE) |= HPPASS_MX3P3ZFILT_HWFILT3P3Z_TOP_CTRL_HWFILT3P3Z_EN_Msk;
}


/*******************************************************************************
* Function Name: Cy_HPPASS_HWFILT3P3Z_TOP_PeripheralDisable
****************************************************************************//**
*
* Disables HPPASS HWFILT3P3Z TOP block.
*
*******************************************************************************/
__STATIC_INLINE void Cy_HPPASS_HWFILT3P3Z_TOP_PeripheralDisable(void)
{
    HPPASS_HWFILT3P3Z_TOP_CTRL(HPPASS_BASE) &= (uint32_t)~HPPASS_MX3P3ZFILT_HWFILT3P3Z_TOP_CTRL_HWFILT3P3Z_EN_Msk;
}


/*******************************************************************************
* Function Name: Cy_HPPASS_HWFILT3P3Z_FilterEnable
****************************************************************************//**
*
* Enables/Disables filter.
*
* \param filtIdx
* Filter instance index (0-3).
*
* \param enable
* true: enables the filter
* false: disables the filter.
*
*******************************************************************************/
__STATIC_INLINE void Cy_HPPASS_HWFILT3P3Z_FilterEnable(uint8_t filtIdx, bool enable)
{
    if(enable)
    {
        HPPASS_HWFILT3P3Z_CTRL(HPPASS_BASE, filtIdx) |= HPPASS_MX3P3ZFILT_HWFILT3P3Z_CTRL_FILTER_EN_Msk;
    }
    else
    {
        HPPASS_HWFILT3P3Z_CTRL(HPPASS_BASE, filtIdx) &= (uint32_t)~HPPASS_MX3P3ZFILT_HWFILT3P3Z_CTRL_FILTER_EN_Msk;
    }
}


 /*******************************************************************************
* Function Name: Cy_HPPASS_HWFILT3P3Z_InitFilterConfig
****************************************************************************//**
*
* Configures the initial parameters of the HWFILT3P3Z filter including the
* filter processing config, coefficients, data out offset, limits,
* coefficients scaling factors, and gains.
*
* \param filtIdx
* Filter instance index (0-3).
*
* \param *config
* The pointer to the HWFILT3P3Z configuration structure.
*
*******************************************************************************/
void Cy_HPPASS_HWFILT3P3Z_InitFilterConfig(uint8_t filtIdx, cy_stc_hppass_hwfilt3p3z_config_t const *config);


/*******************************************************************************
* Function Name: Cy_HPPASS_HWFILT3P3Z_ReadFilterStatus
****************************************************************************//**
*
* Provides the filter busy status.
*
* \param filtIdx
* Filter instance index (0-3).
*
* \return
* The filter busy status. \ref cy_en_hppass_filter_status_t .
*
*******************************************************************************/

__STATIC_INLINE cy_en_hppass_filter_status_t Cy_HPPASS_HWFILT3P3Z_ReadFilterStatus(uint8_t filtIdx)
{
    uint32_t ctrl = _FLD2VAL(HPPASS_MX3P3ZFILT_HWFILT3P3Z_CTRL_FILTER_BUSY, HPPASS_HWFILT3P3Z_CTRL(HPPASS_BASE, filtIdx));
    return (cy_en_hppass_filter_status_t)(ctrl);
}


/*******************************************************************************
* Function Name: Cy_HPPASS_HWFILT3P3Z_ReadFilterDataOutput
****************************************************************************//**
*
* Provides the filter data output.
*
* \param filtIdx
* Filter instance index (0-3).
*
* \return
* Filter data output.
*
*******************************************************************************/
__STATIC_INLINE int32_t Cy_HPPASS_HWFILT3P3Z_ReadFilterDataOutput(uint8_t filtIdx)
{
    return (int32_t)HPPASS_HWFILT3P3Z_DATA_OUT(HPPASS_BASE, filtIdx);
}


/*******************************************************************************
* Function Name: Cy_HPPASS_HWFILT3P3Z_ConfigFilterProcessing
****************************************************************************//**
*
* Configures the filter processing parameters.
*
* \param filtIdx
* Filter instance index (0-3).
*
* \param srcSel
* The data source for register DATA_IN1. \ref cy_en_hppass_filter_src_sel_t.
*
* \param data_in
* Configures data from DATA IN0 or DATA IN1. \ref cy_en_hppass_filter_data_sel_t
*
*******************************************************************************/
__STATIC_INLINE void Cy_HPPASS_HWFILT3P3Z_ConfigFilterProcessing(uint8_t filtIdx, cy_en_hppass_filter_src_sel_t srcSel, cy_en_hppass_filter_data_sel_t data_in)
{
    HPPASS_HWFILT3P3Z_CNFG(HPPASS_BASE, filtIdx) = _VAL2FLD(HPPASS_MX3P3ZFILT_HWFILT3P3Z_CNFG_SRC_SEL, srcSel) |
                                                    _VAL2FLD(HPPASS_HWFILT3P3Z_CNFG_EN_DATA_IN, data_in);
}

/*******************************************************************************
* Function Name: Cy_HPPASS_HWFILT3P3Z_Write_DATA_IN0
****************************************************************************//**
*
* Writes Filter Data 0 Input.
*
* \param filtIdx
* Filter instance index (0-3).
*
* \param inputData
* 16 bit Filter Data 0 input value.
*
*******************************************************************************/
__STATIC_INLINE void Cy_HPPASS_HWFILT3P3Z_Write_DATA_IN0(uint8_t filtIdx, int32_t inputData)
{
    HPPASS_HWFILT3P3Z_DATA_IN0(HPPASS_BASE, filtIdx) = (uint32_t)inputData;
}



/*******************************************************************************
* Function Name: Cy_HPPASS_HWFILT3P3Z_Write_DATA_IN1
****************************************************************************//**
*
* Writes Filter Data 1 Input.
*
* \param filtIdx
* Filter instance index (0-3).
*
* \param inputData
* 16 bit Filter Data 1 input value.
*
*******************************************************************************/
__STATIC_INLINE void Cy_HPPASS_HWFILT3P3Z_Write_DATA_IN1(uint8_t filtIdx, int32_t inputData)
{
    HPPASS_HWFILT3P3Z_DATA_IN1(HPPASS_BASE, filtIdx) = (uint32_t)inputData;
}


/*******************************************************************************
* Function Name: Cy_HPPASS_HWFILT3P3Z_ConfigCoefficients
****************************************************************************//**
*
* Configures the filter coefficients: CX0, CX1, CX2, CX3, CY1, CY2, CY3.
*
* \param filtIdx
* Filter instance index (0-3).
*
* \param *config
* The pointer to the HWFILT3P3Z filter coefficients structure.
* \ref cy_stc_hppass_filter_coefficients_t .
*
*******************************************************************************/
__STATIC_INLINE void Cy_HPPASS_HWFILT3P3Z_ConfigCoefficients(uint8_t filtIdx, cy_stc_hppass_filter_coefficients_t const *config)
{
    HPPASS_HWFILT3P3Z_CX0(HPPASS_BASE, filtIdx) = config->cx0;
    HPPASS_HWFILT3P3Z_CX1(HPPASS_BASE, filtIdx) = config->cx1;
    HPPASS_HWFILT3P3Z_CX2(HPPASS_BASE, filtIdx) = config->cx2;
    HPPASS_HWFILT3P3Z_CX3(HPPASS_BASE, filtIdx) = config->cx3;
    HPPASS_HWFILT3P3Z_CY1(HPPASS_BASE, filtIdx) = config->cy1;
    HPPASS_HWFILT3P3Z_CY2(HPPASS_BASE, filtIdx) = config->cy2;
    HPPASS_HWFILT3P3Z_CY3(HPPASS_BASE, filtIdx) = config->cy3;
}

/*******************************************************************************
* Function Name: Cy_HPPASS_HWFILT3P3Z_ConfigOffset
****************************************************************************//**
*
* Configures the filter data out offset value.
*
* \param filtIdx
* Filter instance index (0-3).
*
* \param offset
* The filter data out offset value.
*
*******************************************************************************/
__STATIC_INLINE void Cy_HPPASS_HWFILT3P3Z_ConfigOffset(uint8_t filtIdx, int32_t offset)
{
    HPPASS_HWFILT3P3Z_OFFSET(HPPASS_BASE, filtIdx) = (uint32_t)offset;
}


/*******************************************************************************
* Function Name: Cy_HPPASS_HWFILT3P3Z_ConfigFilterOutLimits
****************************************************************************//**
*
* Configures the filter out max and min limit values.
*
* \param filtIdx
* Filter instance index (0-3).
*
* \param lmax
* The filter out max limit value.
*
* \param lmin
* The filter out min limit value.
*
*******************************************************************************/
__STATIC_INLINE void Cy_HPPASS_HWFILT3P3Z_ConfigFilterOutLimits(uint8_t filtIdx, int32_t lmax, int32_t lmin)
{
    HPPASS_HWFILT3P3Z_LIMMAX(HPPASS_BASE, filtIdx) = (uint32_t)lmax;
    HPPASS_HWFILT3P3Z_LIMMIN(HPPASS_BASE, filtIdx) = (uint32_t)lmin;
}


/*******************************************************************************
* Function Name: Cy_HPPASS_HWFILT3P3Z_ConfigCoefficientScaleFactors
****************************************************************************//**
*
* Configures the scaling factors for the filter coefficients.
*
* \param filtIdx
* Filter instance index (0-3).
*
* \param scaleCX
* Scale X coefficients factor. \ref cy_en_hppass_filter_scale_factor_t.
*
* \param scaleCY
* Scale Y coefficients factor. \ref cy_en_hppass_filter_scale_factor_t.
*
*******************************************************************************/
__STATIC_INLINE void Cy_HPPASS_HWFILT3P3Z_ConfigCoefficientScaleFactors(uint8_t filtIdx, cy_en_hppass_filter_scale_factor_t scaleCX, cy_en_hppass_filter_scale_factor_t scaleCY)
{
    HPPASS_HWFILT3P3Z_SCALECX(HPPASS_BASE, filtIdx) = (uint32_t)scaleCX;
    HPPASS_HWFILT3P3Z_SCALECY(HPPASS_BASE, filtIdx) = (uint32_t)scaleCY;
}


/*******************************************************************************
* Function Name: Cy_HPPASS_HWFILT3P3Z_ConfigGains
****************************************************************************//**
*
* Configures the filter gain factors.
*
* \param filtIdx
* Filter instance index (0-3).
*
* \param gIn
* Amplify input difference factor.
*
* \param gOut
* Scale down output factor.
*
*******************************************************************************/
__STATIC_INLINE void Cy_HPPASS_HWFILT3P3Z_ConfigGains(uint8_t filtIdx, uint8_t gIn, uint8_t gOut)
{
    HPPASS_HWFILT3P3Z_GIN(HPPASS_BASE, filtIdx)  = gIn;
    HPPASS_HWFILT3P3Z_GOUT(HPPASS_BASE, filtIdx) = gOut;
}

/*******************************************************************************
* Function Name: Cy_HPPASS_HWFILT3P3Z_ConfigAntiWindup
****************************************************************************//**
*
* Configures the anti-windup parameters for the filter.
*
* \param filtIdx
* Filter instance index (0-3).
*
* \param awMax
* Anti-windup maximum limit value (24-bit, sign-extended to 32-bit).
*
* \param awMin
* Anti-windup minimum limit value (24-bit, sign-extended to 32-bit).
*
* \param awGain
* Anti-windup gain value (24-bit, sign-extended to 32-bit).
*
*******************************************************************************/
__STATIC_INLINE void Cy_HPPASS_HWFILT3P3Z_ConfigAntiWindup(uint8_t filtIdx, uint32_t awMax, uint32_t awMin, uint32_t awGain)
{
    HPPASS_HWFILT3P3Z_AWMAX(HPPASS_BASE, filtIdx)  = awMax;
    HPPASS_HWFILT3P3Z_AWMIN(HPPASS_BASE, filtIdx)  = awMin;
    HPPASS_HWFILT3P3Z_AWGAIN(HPPASS_BASE, filtIdx) = awGain;
}


/*******************************************************************************
* Function Name: Cy_HPPASS_HWFILT3P3Z_TOP_GetPeripheralEnable
****************************************************************************//**
*
* Returns whether the HPPASS HWFILT3P3Z TOP block is enabled.
*
* \return
* true if the TOP block is enabled, false otherwise.
*
*******************************************************************************/
__STATIC_INLINE bool Cy_HPPASS_HWFILT3P3Z_TOP_GetPeripheralEnable(void)
{
    return (0UL != (HPPASS_HWFILT3P3Z_TOP_CTRL(HPPASS_BASE) & HPPASS_MX3P3ZFILT_HWFILT3P3Z_TOP_CTRL_HWFILT3P3Z_EN_Msk));
}


/*******************************************************************************
* Function Name: Cy_HPPASS_HWFILT3P3Z_GetFilterEnable
****************************************************************************//**
*
* Returns whether a specific HWFILT3P3Z filter instance is enabled.
*
* \param filtIdx
* Filter instance index (0-3).
*
* \return
* true if the filter instance is enabled, false otherwise.
*
*******************************************************************************/
__STATIC_INLINE bool Cy_HPPASS_HWFILT3P3Z_GetFilterEnable(uint8_t filtIdx)
{
    CY_ASSERT_L1(CY_HPPASS_HWFILT3P3Z_INDEX_VALID(filtIdx));
    return (0UL != (HPPASS_HWFILT3P3Z_CTRL(HPPASS_BASE, filtIdx) & HPPASS_MX3P3ZFILT_HWFILT3P3Z_CTRL_FILTER_EN_Msk));
}


/*******************************************************************************
* Function Name: Cy_HPPASS_HWFILT3P3Z_GetFilterProcessing
****************************************************************************//**
*
* Reads back the filter processing configuration: the data source for DATA_IN1
* and which data input register triggers filter computation.
*
* \param filtIdx
* Filter instance index (0-3).
*
* \param *srcSel
* Pointer to store the data source selection for DATA_IN1.
* \ref cy_en_hppass_filter_src_sel_t.
*
* \param *data_in
* Pointer to store the data register trigger selection.
* \ref cy_en_hppass_filter_data_sel_t.
*
*******************************************************************************/
__STATIC_INLINE void Cy_HPPASS_HWFILT3P3Z_GetFilterProcessing(uint8_t filtIdx,
                                                               cy_en_hppass_filter_src_sel_t *srcSel,
                                                               cy_en_hppass_filter_data_sel_t *data_in)
{
    CY_ASSERT_L1(CY_HPPASS_HWFILT3P3Z_INDEX_VALID(filtIdx));
    CY_ASSERT_L1(CY_IS_HWFILTER_PARAM_VALID(srcSel));
    CY_ASSERT_L1(CY_IS_HWFILTER_PARAM_VALID(data_in));
    uint32_t cnfg = HPPASS_HWFILT3P3Z_CNFG(HPPASS_BASE, filtIdx);
    uint32_t srcSelVal = _FLD2VAL(HPPASS_MX3P3ZFILT_HWFILT3P3Z_CNFG_SRC_SEL, cnfg);
    *srcSel = (cy_en_hppass_filter_src_sel_t)srcSelVal;
    bool trig1 = (0UL != _FLD2VAL(HPPASS_MX3P3ZFILT_HWFILT3P3Z_CNFG_EN_TRIG1, cnfg));
    bool trig0 = (0UL != _FLD2VAL(HPPASS_MX3P3ZFILT_HWFILT3P3Z_CNFG_EN_TRIG0, cnfg));
    *data_in = trig1 ? CY_ENABLE_DATA_IN1 : (trig0 ? CY_ENABLE_DATA_IN0 : CY_DISABLE_DATA_IN);
}


/*******************************************************************************
* Function Name: Cy_HPPASS_HWFILT3P3Z_GetCoefficients
****************************************************************************//**
*
* Reads back all 7 filter coefficients (CX0-CX3 numerator / X coefficients and
* CY1-CY3 denominator / Y coefficients) from the hardware registers.
*
* \param filtIdx
* Filter instance index (0-3).
*
* \param *config
* Pointer to the coefficient structure to populate.
* \ref cy_stc_hppass_filter_coefficients_t.
*
*******************************************************************************/
__STATIC_INLINE void Cy_HPPASS_HWFILT3P3Z_GetCoefficients(uint8_t filtIdx, cy_stc_hppass_filter_coefficients_t *config)
{
    CY_ASSERT_L1(CY_HPPASS_HWFILT3P3Z_INDEX_VALID(filtIdx));
    CY_ASSERT_L1(CY_IS_HWFILTER_PARAM_VALID(config));
    config->cx0 = HPPASS_HWFILT3P3Z_CX0(HPPASS_BASE, filtIdx);
    config->cx1 = HPPASS_HWFILT3P3Z_CX1(HPPASS_BASE, filtIdx);
    config->cx2 = HPPASS_HWFILT3P3Z_CX2(HPPASS_BASE, filtIdx);
    config->cx3 = HPPASS_HWFILT3P3Z_CX3(HPPASS_BASE, filtIdx);
    config->cy1 = HPPASS_HWFILT3P3Z_CY1(HPPASS_BASE, filtIdx);
    config->cy2 = HPPASS_HWFILT3P3Z_CY2(HPPASS_BASE, filtIdx);
    config->cy3 = HPPASS_HWFILT3P3Z_CY3(HPPASS_BASE, filtIdx);
}


/*******************************************************************************
* Function Name: Cy_HPPASS_HWFILT3P3Z_GetOffset
****************************************************************************//**
*
* Reads back the additive output offset value from the hardware register.
*
* \param filtIdx
* Filter instance index (0-3).
*
* \return
* The signed offset value added to the filter output.
*
*******************************************************************************/
__STATIC_INLINE int32_t Cy_HPPASS_HWFILT3P3Z_GetOffset(uint8_t filtIdx)
{
    CY_ASSERT_L1(CY_HPPASS_HWFILT3P3Z_INDEX_VALID(filtIdx));
    return (int32_t)HPPASS_HWFILT3P3Z_OFFSET(HPPASS_BASE, filtIdx);
}


/*******************************************************************************
* Function Name: Cy_HPPASS_HWFILT3P3Z_GetFilterOutLimits
****************************************************************************//**
*
* Reads back the output saturation limits from the hardware registers.
*
* \param filtIdx
* Filter instance index (0-3).
*
* \param *lmax
* Pointer to store the maximum saturation limit.
*
* \param *lmin
* Pointer to store the minimum saturation limit.
*
*******************************************************************************/
__STATIC_INLINE void Cy_HPPASS_HWFILT3P3Z_GetFilterOutLimits(uint8_t filtIdx, int32_t *lmax, int32_t *lmin)
{
    CY_ASSERT_L1(CY_HPPASS_HWFILT3P3Z_INDEX_VALID(filtIdx));
    CY_ASSERT_L1(CY_IS_HWFILTER_PARAM_VALID(lmax));
    CY_ASSERT_L1(CY_IS_HWFILTER_PARAM_VALID(lmin));
    *lmax = (int32_t)HPPASS_HWFILT3P3Z_LIMMAX(HPPASS_BASE, filtIdx);
    *lmin = (int32_t)HPPASS_HWFILT3P3Z_LIMMIN(HPPASS_BASE, filtIdx);
}


/*******************************************************************************
* Function Name: Cy_HPPASS_HWFILT3P3Z_GetCoefficientScaleFactors
****************************************************************************//**
*
* Reads back the coefficient scaling factors from the hardware registers.
*
* \param filtIdx
* Filter instance index (0-3).
*
* \param *scaleCX
* Pointer to store the X (numerator) coefficient scale factor.
* \ref cy_en_hppass_filter_scale_factor_t.
*
* \param *scaleCY
* Pointer to store the Y (denominator) coefficient scale factor.
* \ref cy_en_hppass_filter_scale_factor_t.
*
*******************************************************************************/
__STATIC_INLINE void Cy_HPPASS_HWFILT3P3Z_GetCoefficientScaleFactors(uint8_t filtIdx,
                                                                      cy_en_hppass_filter_scale_factor_t *scaleCX,
                                                                      cy_en_hppass_filter_scale_factor_t *scaleCY)
{
    CY_ASSERT_L1(CY_HPPASS_HWFILT3P3Z_INDEX_VALID(filtIdx));
    CY_ASSERT_L1(CY_IS_HWFILTER_PARAM_VALID(scaleCX));
    CY_ASSERT_L1(CY_IS_HWFILTER_PARAM_VALID(scaleCY));
    *scaleCX = (cy_en_hppass_filter_scale_factor_t)HPPASS_HWFILT3P3Z_SCALECX(HPPASS_BASE, filtIdx);
    *scaleCY = (cy_en_hppass_filter_scale_factor_t)HPPASS_HWFILT3P3Z_SCALECY(HPPASS_BASE, filtIdx);
}


/*******************************************************************************
* Function Name: Cy_HPPASS_HWFILT3P3Z_GetGains
****************************************************************************//**
*
* Reads back the input amplification and output attenuation gain values from
* the hardware registers.
*
* \param filtIdx
* Filter instance index (0-3).
*
* \param *gIn
* Pointer to store the input gain (number of left-shift bits).
*
* \param *gOut
* Pointer to store the output gain (number of right-shift bits).
*
*******************************************************************************/
__STATIC_INLINE void Cy_HPPASS_HWFILT3P3Z_GetGains(uint8_t filtIdx, uint8_t *gIn, uint8_t *gOut)
{
    CY_ASSERT_L1(CY_HPPASS_HWFILT3P3Z_INDEX_VALID(filtIdx));
    CY_ASSERT_L1(CY_IS_HWFILTER_PARAM_VALID(gIn));
    CY_ASSERT_L1(CY_IS_HWFILTER_PARAM_VALID(gOut));
    *gIn  = (uint8_t)HPPASS_HWFILT3P3Z_GIN(HPPASS_BASE, filtIdx);
    *gOut = (uint8_t)HPPASS_HWFILT3P3Z_GOUT(HPPASS_BASE, filtIdx);
}


/*******************************************************************************
* Function Name: Cy_HPPASS_HWFILT3P3Z_GetAntiWindup
****************************************************************************//**
*
* Reads back the anti-windup parameters from the hardware registers.
*
* \param filtIdx
* Filter instance index (0-3).
*
* \param *awMax
* Pointer to store the anti-windup maximum limit value.
*
* \param *awMin
* Pointer to store the anti-windup minimum limit value.
*
* \param *awGain
* Pointer to store the anti-windup gain value.
*
*******************************************************************************/
__STATIC_INLINE void Cy_HPPASS_HWFILT3P3Z_GetAntiWindup(uint8_t filtIdx, uint32_t *awMax, uint32_t *awMin, uint32_t *awGain)
{
    CY_ASSERT_L1(CY_HPPASS_HWFILT3P3Z_INDEX_VALID(filtIdx));
    CY_ASSERT_L1(CY_IS_HWFILTER_PARAM_VALID(awMax));
    CY_ASSERT_L1(CY_IS_HWFILTER_PARAM_VALID(awMin));
    CY_ASSERT_L1(CY_IS_HWFILTER_PARAM_VALID(awGain));
    *awMax  = HPPASS_HWFILT3P3Z_AWMAX(HPPASS_BASE, filtIdx);
    *awMin  = HPPASS_HWFILT3P3Z_AWMIN(HPPASS_BASE, filtIdx);
    *awGain = HPPASS_HWFILT3P3Z_AWGAIN(HPPASS_BASE, filtIdx);
}


/*******************************************************************************
* Function Name: Cy_HPPASS_HWFILT3P3Z_GetFilterConfig
****************************************************************************//**
*
* Reads back the complete filter configuration from all hardware registers into
* a \ref cy_stc_hppass_hwfilt3p3z_config_t structure. This is the reverse of
* \ref Cy_HPPASS_HWFILT3P3Z_InitFilterConfig and is intended for save/restore
* use cases (e.g., STL self-test invocations).
*
* \note The CTRL FILTER_EN bit (enable state) is not part of
* cy_stc_hppass_hwfilt3p3z_config_t. Use \ref Cy_HPPASS_HWFILT3P3Z_GetFilterEnable
* separately to save/restore the enable state.
*
* \param filtIdx
* Filter instance index (0-3).
*
* \param *config
* Pointer to the configuration structure to populate with register readback values.
* See \ref cy_stc_hppass_hwfilt3p3z_config_t for field descriptions.
*
*******************************************************************************/
__STATIC_INLINE void Cy_HPPASS_HWFILT3P3Z_GetFilterConfig(uint8_t filtIdx, cy_stc_hppass_hwfilt3p3z_config_t *config)
{
    CY_ASSERT_L1(CY_HPPASS_HWFILT3P3Z_INDEX_VALID(filtIdx));
    CY_ASSERT_L1(CY_IS_HWFILTER_PARAM_VALID(config));

    uint32_t cnfg = HPPASS_HWFILT3P3Z_CNFG(HPPASS_BASE, filtIdx);
    uint32_t srcSelVal    = _FLD2VAL(HPPASS_MX3P3ZFILT_HWFILT3P3Z_CNFG_SRC_SEL, cnfg);
    config->srcSel        = (cy_en_hppass_filter_src_sel_t)srcSelVal;
    config->enTrig0       = (0UL != _FLD2VAL(HPPASS_MX3P3ZFILT_HWFILT3P3Z_CNFG_EN_TRIG0, cnfg));
    config->enTrig1       = (0UL != _FLD2VAL(HPPASS_MX3P3ZFILT_HWFILT3P3Z_CNFG_EN_TRIG1, cnfg));
    config->cx0           = HPPASS_HWFILT3P3Z_CX0(HPPASS_BASE, filtIdx);
    config->cx1           = HPPASS_HWFILT3P3Z_CX1(HPPASS_BASE, filtIdx);
    config->cx2           = HPPASS_HWFILT3P3Z_CX2(HPPASS_BASE, filtIdx);
    config->cx3           = HPPASS_HWFILT3P3Z_CX3(HPPASS_BASE, filtIdx);
    config->cy1           = HPPASS_HWFILT3P3Z_CY1(HPPASS_BASE, filtIdx);
    config->cy2           = HPPASS_HWFILT3P3Z_CY2(HPPASS_BASE, filtIdx);
    config->cy3           = HPPASS_HWFILT3P3Z_CY3(HPPASS_BASE, filtIdx);
    config->dataOutOffset = HPPASS_HWFILT3P3Z_OFFSET(HPPASS_BASE, filtIdx);
    config->limMax        = HPPASS_HWFILT3P3Z_LIMMAX(HPPASS_BASE, filtIdx);
    config->limMin        = HPPASS_HWFILT3P3Z_LIMMIN(HPPASS_BASE, filtIdx);
    config->scaleCX       = (uint8_t)HPPASS_HWFILT3P3Z_SCALECX(HPPASS_BASE, filtIdx);
    config->scaleCY       = (uint8_t)HPPASS_HWFILT3P3Z_SCALECY(HPPASS_BASE, filtIdx);
    config->gIn           = (uint8_t)HPPASS_HWFILT3P3Z_GIN(HPPASS_BASE, filtIdx);
    config->gOut          = (uint8_t)HPPASS_HWFILT3P3Z_GOUT(HPPASS_BASE, filtIdx);
    config->awMax         = HPPASS_HWFILT3P3Z_AWMAX(HPPASS_BASE, filtIdx);
    config->awMin         = HPPASS_HWFILT3P3Z_AWMIN(HPPASS_BASE, filtIdx);
    config->awGain        = HPPASS_HWFILT3P3Z_AWGAIN(HPPASS_BASE, filtIdx);

    /* HWFILT3P3Z_IND_CTRL only exists for instances 0..2 */
    if (filtIdx < 3U)
    {
        config->channelSel = (uint8_t)_FLD2VAL(HPPASS_SAR_CFG_HWFILT3P3Z_IND_CTRL_CHANNEL_SEL,
                                               HPPASS_SAR_HWFILT3P3Z_IND_CTRL(HPPASS_BASE, filtIdx));
    }
    else
    {
        config->channelSel = 0U;
    }
}


/** \} group_hppass_hwfilt3p3z_functions */

#if defined(__cplusplus)
}
#endif

#endif /* #if defined(CY_IP_MXS40MCPASS) && (CY_IP_MXS40MCPASS_VERSION >= 3u) */

#endif /* (CY_HPPASS_HWFILT3P3Z_H) */

/** \} group_hppass_hwfilt3p3z */

/* [] END OF FILE */
