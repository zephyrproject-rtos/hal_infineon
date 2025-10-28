/***************************************************************************//**
* \file cy_dsadc_calibration.c
* \version 1.0
*
* \brief
* Provides an API implementation of the calibrations for the Delta-Sigma ADC driver
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
*******************************************************************************/
#include "cy_dsadc.h"

#if defined (CY_IP_M0S8PACSS)

#if defined(__cplusplus)
extern "C" {
#endif

/** \cond INTERNAL */
/*==================[macros]==================================================*/
/* Max supported temperature in celsius degree */
#define CY_DSADC_MAX_TEMPERATURE                        (150)
/* Min supported temperature in celsius degree */
#define CY_DSADC_MIN_TEMPERATURE_ABS                    (40)
/* Min supported temperature in celsius degree */
#define CY_DSADC_MIN_TEMPERATURE                        (-1 * CY_DSADC_MIN_TEMPERATURE_ABS)
/* Supported temperature range in celsius degree */
#define CY_DSADC_TEMPERATURE_FIXED_RANGE                (CY_DSADC_MAX_TEMPERATURE - CY_DSADC_MIN_TEMPERATURE)
/* Temperature reduction format fraction bits num (Q4 format) */
#define CY_DSADC_TEMPERATURE_FRACTION_BITS_REDUCTION    (4U)
/* Convert to precision reduction format from Q20 format to limit bit length */
#define CY_DSADC_TEMPERATURE_TO_REDUCTION_FORMAT        (CY_DSADC_TEMPERATURE_FRACTION_BITS - \
                                                        CY_DSADC_TEMPERATURE_FRACTION_BITS_REDUCTION)
/* Max temperature in fixed point */
#define CY_DSADC_MAX_TEMPERATURE_IN_FP                  (int32_t)((uint32_t)CY_DSADC_MAX_TEMPERATURE << \
                                                        CY_DSADC_TEMPERATURE_FRACTION_BITS)
/* Min temperature in fixed point */
#define CY_DSADC_MIN_TEMPERATURE_IN_FP                  (-1 * (int32_t)((uint32_t)CY_DSADC_MIN_TEMPERATURE_ABS << \
                                                        CY_DSADC_TEMPERATURE_FRACTION_BITS))
/* Fixed point fraction bit number of (1 / fixed temperature range)
* -1 is for preventing overflow at max temperature.
*/
#define CY_DSADC_1_DIV_BY_TEMP_RANGE_FRACTION_BITS      (32U - CY_DSADC_TEMPERATURE_FRACTION_BITS_REDUCTION - 1U)
/* (1 / fixed temperature range) expression in fixed point format */
#define CY_DSADC_1_DIV_BY_TEMP_RANGE_IN_FP              ((uint32_t)(((1.0F / (float32_t)CY_DSADC_TEMPERATURE_FIXED_RANGE) * \
                                                        (float32_t)(1UL << CY_DSADC_1_DIV_BY_TEMP_RANGE_FRACTION_BITS)) + 0.5F))
/* Right shift to limit the result under uint16_t range */
#define CY_DSADC_RIGHT_SHIFT_TO_LIMIT_16BITS            (16U)
/* Convert to calculated correction in fixed point to integer */
#define CY_DSADC_CORRECTION_TO_INTEGER                  ((CY_DSADC_1_DIV_BY_TEMP_RANGE_FRACTION_BITS + \
                                                        CY_DSADC_TEMPERATURE_FRACTION_BITS_REDUCTION) - \
                                                        CY_DSADC_RIGHT_SHIFT_TO_LIMIT_16BITS)
/* Values in SFLASH are Ohms/32 */
#define CY_DSADC_SFLASH_PULLUP_TO_OHMS                  (32)
/* Max OCOR value */
#define CY_DSADC_MAX_OCOR                               (32767)
/* Min OCOR value */
#define CY_DSADC_MIN_OCOR                               (-32768)
/* Max GCOR value */
#define CY_DSADC_MAX_GCOR                               (0xFFFF)
/* Min GCOR value */
#define CY_DSADC_MIN_GCOR                               (0)
/* ACHAN1_3TEMP offset */
#define CY_DSADC_ACHAN1_3TEMP_OFFSET                    (3U)
#define CY_DSADC_ACHAN1_3TEMP_CENTER_OFFSET             (1U)
#define CY_DSADC_ACHAN1_3TEMP_HOT_OFFSET                (2U)
/* ACHAN1_2TEMP gain 1x offset */
#define CY_DSADC_ACHAN1_2TEMP_X1_COLD_OFFSET            (2U)
#define CY_DSADC_ACHAN1_2TEMP_X1_HOT_OFFSET             (3U)
/* Max gain level index */
#define CY_DSADC_MAX_GAIN_LEVEL_INDEX                   (9U)

/** \endcond */
/*==================[internal function definitions]===========================*/
/*******************************************************************************
* Function Name: Cy_DSADC_CalibCalcCorrection
****************************************************************************//**
*
* \brief Calculates a correction value by linear interpolation arithmetic.
*
* \note Applicable to PSOC4 HVPA only.
* This function uses 32 bits division inside, so slower than Cy_DSADC_CalibCalcCorrectionWithFixRange().
* Compared with floating point arithmetic results, interpolated result may have a error [-1, +1]
* when fraction in floating point arithmetic results is near by 0.5.
*
* \param minValue
* Value in interpolation range.
*
* \param maxValue
* Value in interpolation range.
*
* \param tempRange
* Temperature range of interpolation in integer format.
*
* \param deltaTempFromBase
* Delta temperature from lowest temperature in interpolation range.
*
* \return Interpolated value in integer.
*
*******************************************************************************/
static int32_t Cy_DSADC_CalibCalcCorrection(int32_t minValue,
                                            int32_t maxValue,
                                            uint32_t tempRange,
                                            uint32_t deltaTempFromBase)
{
    const int32_t diff = maxValue - minValue;
    uint32_t diffAbs = (uint32_t)(diff < 0 ? -diff : diff);
    int32_t sign = (diff < 0) ? -1 : 1;

    diffAbs = diffAbs * deltaTempFromBase;
    diffAbs = (diffAbs + (tempRange << (CY_DSADC_TEMPERATURE_FRACTION_BITS_REDUCTION - 1U))) / \
              (tempRange << CY_DSADC_TEMPERATURE_FRACTION_BITS_REDUCTION);

    return ((int32_t)diffAbs * sign) + minValue;
}

/*******************************************************************************
* Function Name: Cy_DSADC_CalibCalcCorrectionWithFixRange
****************************************************************************//**
*
* \brief Calculates a correction value by linear interpolation arithmetic in fixed temperature range.
*
* \note Applicable to PSOC4 HVPA only.
* This function is optimized for fixed temperature range to avoid division.
* Compared with floating point arithmetic results, interpolated result may have a error [-1, +1]
* when fraction in floating point arithmetic results is near by 0.5.
*
* \param minValue
* Value in interpolation range.
*
* \param maxValue
* Value in interpolation range.
*
* \param temperature
* Temperature in fixed point format Q12.20. \ref CY_DSADC_TEMPERATURE_FRACTION_BITS
*
* \return Interpolated value in integer.
*
*******************************************************************************/
static int32_t Cy_DSADC_CalibCalcCorrectionWithFixRange(int32_t minValue, int32_t maxValue, int32_t temperature)
{
    CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 10.8', 8, \
    'Casting uint32_t to int32_t will not result in overflow.');
    /* Saturate if given temperature over the range. */
    int32_t saturateTemp = (temperature > CY_DSADC_MAX_TEMPERATURE_IN_FP) ? CY_DSADC_MAX_TEMPERATURE_IN_FP : \
                           (temperature < CY_DSADC_MIN_TEMPERATURE_IN_FP) ? CY_DSADC_MIN_TEMPERATURE_IN_FP : \
                           temperature;

    const int32_t deltaTempFromBaseTemp = saturateTemp - CY_DSADC_MIN_TEMPERATURE_IN_FP;
    uint32_t deltaTempFromBase = (uint32_t)deltaTempFromBaseTemp >> CY_DSADC_TEMPERATURE_TO_REDUCTION_FORMAT;

    const int32_t diff = maxValue - minValue;
    uint32_t diffAbs = (uint32_t)(diff < 0 ? -diff : diff);
    int32_t sign = (diff < 0) ? -1 : 1;
    /* Calculate temperature div range */
    uint32_t tempDivByRange = deltaTempFromBase * CY_DSADC_1_DIV_BY_TEMP_RANGE_IN_FP;
    CY_MISRA_BLOCK_END('MISRA C-2012 Rule 10.8');
    /* To prevent overflow, shift right with round. The result will be in uint16_t range. */
    tempDivByRange = (tempDivByRange + (1UL << (CY_DSADC_RIGHT_SHIFT_TO_LIMIT_16BITS - 1U))) >> \
                     CY_DSADC_RIGHT_SHIFT_TO_LIMIT_16BITS;
    /* Calculate (temperature div range) mul (max - min) */
    const uint32_t uCorrection = ((tempDivByRange * diffAbs) + \
                                 (1UL << (CY_DSADC_CORRECTION_TO_INTEGER - 1U))) >> \
                                 CY_DSADC_CORRECTION_TO_INTEGER;

    return ((int32_t)uCorrection * sign) + minValue;
}

/*******************************************************************************
* Function Name: Cy_DSADC_CalibSaturateOffset
****************************************************************************//**
*
* \brief Return the saturated offset correction value if the input value is out of range.
*
* \note Applicable to PSOC4 HVPA only.
*
* \param offset32
* The offset correction value in 32-bit signed integer.
*
* \return The saturated offset correction value in 16-bit signed integer.
*
*******************************************************************************/
static int16_t Cy_DSADC_CalibSaturateOffset(int32_t offset32)
{
  return ((offset32 > (int32_t)CY_DSADC_MAX_OCOR) ? (int16_t)CY_DSADC_MAX_OCOR : \
          (offset32 < (int32_t)CY_DSADC_MIN_OCOR) ? (int16_t)CY_DSADC_MIN_OCOR : \
          (int16_t)offset32);
}

/*******************************************************************************
* Function Name: Cy_DSADC_CalibSaturateGain
****************************************************************************//**
*
* \brief Return the saturated gain correction value if the input value is out of range.
*
* \note Applicable to PSOC4 HVPA only.
*
* \param gain32
* The gain correction value in 32-bit signed integer.
*
* \return The saturated gain correction value in 16-bit unsigned integer.
*
*******************************************************************************/
static uint16_t Cy_DSADC_CalibSaturateGain(int32_t gain32)
{
    return ((gain32 > (int32_t)CY_DSADC_MAX_GCOR) ? (uint16_t)CY_DSADC_MAX_GCOR : \
            (gain32 < (int32_t)CY_DSADC_MIN_GCOR) ? (uint16_t)CY_DSADC_MIN_GCOR : \
            (uint16_t)gain32);
}

/*******************************************************************************
* Function Name: Cy_DSADC_CalibCalcAchan0_GainCorrection
****************************************************************************//**
*
* \brief Calculate the gain correction value for the ACHAN0.
*
* \note Applicable to PSOC4 HVPA only.
* The formula is following gcorHvCh0 = gcorCh0*gcorHvCh1/gcorCh1,
* if gcorCh1 is zero, then the return gain value is gcorCh0.
*
* \param gcorCh0
* The temperature corrected value of gain for the ACHAN0.
*
* \param gcorCh1
* The temperature corrected value of gain for the ACHAN1.
*
* \param gcorHvCh1
* The temperature corrected HV divider output of gain to refer
* to the three temperature trim values for the ACHAN1.
*
* \return The gain correction value for the ACHAN0.
*
*******************************************************************************/
static uint16_t Cy_DSADC_CalibCalcAchan0_GainCorrection(uint16_t gcorCh0, uint16_t gcorCh1, uint16_t gcorHvCh1)
{
    uint32_t saturateTemp;

    if(0U != gcorCh1)
    {
        saturateTemp = (uint32_t)gcorCh0 * (uint32_t)gcorHvCh1;
        saturateTemp = (saturateTemp + ((uint32_t)gcorCh1 >> 1U)) / (uint32_t)gcorCh1;
    }
    else
    {
        saturateTemp = (uint32_t)gcorCh0;
    }

    return (Cy_DSADC_CalibSaturateGain((int32_t)saturateTemp));
}

/*******************************************************************************
* Function Name: Cy_DSADC_CalibCalcAchan0_OffsetCorrection
****************************************************************************//**
*
* \brief Calculate the offset correction value for the ACHAN0.
*
* \note Applicable to PSOC4 HVPA only.
* The formula is following ocorHvCh0 = -gcorCh1*(ocorCh1-ocorHvCh1)/gcorCh0 + ocorCh0,
* if gcorCh0 is zero, then the return gain value is ocorCh0.
*
* \param gcorCh0
* The temperature corrected value of gain for the ACHAN0.
*
* \param gcorCh1
* The temperature corrected value of gain for the ACHAN1.
*
* \param ocorCh0
* The temperature corrected value of offset for the ACHAN0.
*
* \param ocorCh1
* The temperature corrected value of offset for the ACHAN1.
*
* \param ocorHvCh1
* The temperature corrected HV divider output of offset to refer
* to the three temperature trim values for the ACHAN1.
*
* \return The offset correction value for the ACHAN0.
*
*******************************************************************************/
static int16_t Cy_DSADC_CalibCalcAchan0_OffsetCorrection(uint16_t gcorCh0,
                                                         uint16_t gcorCh1,
                                                         int16_t ocorCh0,
                                                         int16_t ocorCh1,
                                                         int16_t ocorHvCh1)
{
    int32_t saturateTemp;

    if(0U != gcorCh0)
    {
        const int32_t diff = (int32_t)ocorHvCh1 - (int32_t)ocorCh1;
        int32_t sign = (diff < 0L) ? -1 : 1;
        int32_t diffAbs = ((diff < 0L) ? -diff : diff);

        saturateTemp = (int32_t)gcorCh1 * diffAbs;
        CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 10.8', 'Casting uint32_t to int32_t will not result in overflow.');
        saturateTemp = (saturateTemp + (int32_t)((uint32_t)gcorCh0 >> 1U)) / (int32_t)gcorCh0;
        saturateTemp = (saturateTemp * sign) + (int32_t)ocorCh0;
    }
    else
    {
        saturateTemp = (int32_t)ocorCh0;
    }

    return (Cy_DSADC_CalibSaturateOffset(saturateTemp));
}

/*******************************************************************************
* Function Name: Cy_DSADC_CalibCalcAchan0_2TempTrim
****************************************************************************//**
*
* \brief Calculate the gain and the offset correction values for the ACHAN0
* with the temperature and the calibration data stored in SFLASH.
*
* \note Applicable to PSOC4 HVPA only.
* If the temperature is out of range,
* then trim value is calculated with the minimum or the maximum temperature.
*
* \param gcor
*  The gain correction value.
*
* \param ocor
* The offset correction value.
*
* \param gain
* The gain value to refer to the two temperature trim values for the ACHAN0.
*
* \param temperature
* Temperature in fixed point format Q12.20. \ref CY_DSADC_TEMPERATURE_FRACTION_BITS
*
*******************************************************************************/
static void Cy_DSADC_CalibCalcAchan0_2TempTrim(uint16_t* gcor,
                                               int16_t* ocor,
                                               cy_en_dsadc_achan0_2temp_trim_gain_type_t gain,
                                               int32_t temperature)
{
    const uint32_t regIndex = (uint32_t)gain << 1U;
    CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 10.8', 2, \
    'Casting uint32_t to int32_t will not result in overflow.');
    /* Get gain and offset trim values */
    const int16_t offsetHot = CY_DSADC_GET_INT16(SFLASH_PACSS_CHAN0_2TEMP_TRIM_OFFSETADJ, \
                                                 SFLASH->PACSS_CHAN0_2TEMP_TRIM[regIndex + 1U]);
    const uint16_t gainHot = CY_DSADC_GET_UINT16(SFLASH_PACSS_CHAN0_2TEMP_TRIM_GAINADJ, \
                                                 SFLASH->PACSS_CHAN0_2TEMP_TRIM[regIndex + 1U]);
    const int16_t offsetCold = CY_DSADC_GET_INT16(SFLASH_PACSS_CHAN0_2TEMP_TRIM_OFFSETADJ, \
                                                  SFLASH->PACSS_CHAN0_2TEMP_TRIM[regIndex]);
    const uint16_t gainCold = CY_DSADC_GET_UINT16(SFLASH_PACSS_CHAN0_2TEMP_TRIM_GAINADJ, \
                                                  SFLASH->PACSS_CHAN0_2TEMP_TRIM[regIndex]);
    CY_MISRA_BLOCK_END('MISRA C-2012 Rule 10.8');

    const int32_t offset32 = Cy_DSADC_CalibCalcCorrectionWithFixRange((int32_t)offsetCold, (int32_t)offsetHot, temperature);
    const int32_t gain32 = Cy_DSADC_CalibCalcCorrectionWithFixRange((int32_t)gainCold, (int32_t)gainHot, temperature);

    *ocor = Cy_DSADC_CalibSaturateOffset(offset32);
    *gcor = Cy_DSADC_CalibSaturateGain(gain32);
}


/*******************************************************************************
* Function Name: Cy_DSADC_CalibCalcAchan1_2TempTrim
****************************************************************************//**
*
* \brief Calculate the gain and the offset correction values for the ACHAN1
* with the temperature and the calibration data stored in SFLASH.
*
* \note Applicable to PSOC4 HVPA only.
* If the temperature is out of range,
* then trim value is calculated with the minimum or the maximum temperature.
*
* \param gcor
* The gain correction value.
*
* \param ocor
* The offset correction value.
*
* \param gain
* The gain value to refer to the two temperature trim values for the ACHAN0.
*
* \param temperature
* Temperature in fixed point format Q12.20. \ref CY_DSADC_TEMPERATURE_FRACTION_BITS
*
*******************************************************************************/
static void Cy_DSADC_CalibCalcAchan1_2TempTrim(uint16_t* gcor,
                                               int16_t* ocor,
                                               cy_en_dsadc_achan1_2temp_trim_gain_type_t gain,
                                               int32_t temperature)
{
    const uint32_t regIndex = (uint32_t)gain << 1U;
    CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 10.8', 2, \
    'Casting uint32_t to int32_t will not result in overflow.');
    /* Get gain and offset trim values */
    const int16_t offsetHot = CY_DSADC_GET_INT16(SFLASH_PACSS_CHAN1_2TEMP_TRIM_OFFSETADJ, \
                                                 SFLASH->PACSS_CHAN1_2TEMP_TRIM[regIndex + 1U]);
    const uint16_t gainHot = CY_DSADC_GET_UINT16(SFLASH_PACSS_CHAN1_2TEMP_TRIM_GAINADJ, \
                                                 SFLASH->PACSS_CHAN1_2TEMP_TRIM[regIndex + 1U]);
    const int16_t offsetCold = CY_DSADC_GET_INT16(SFLASH_PACSS_CHAN1_2TEMP_TRIM_OFFSETADJ, \
                                                  SFLASH->PACSS_CHAN1_2TEMP_TRIM[regIndex]);
    const uint16_t gainCold = CY_DSADC_GET_UINT16(SFLASH_PACSS_CHAN1_2TEMP_TRIM_GAINADJ, \
                                                  SFLASH->PACSS_CHAN1_2TEMP_TRIM[regIndex]);
    CY_MISRA_BLOCK_END('MISRA C-2012 Rule 10.8');

    const int32_t offset32 = Cy_DSADC_CalibCalcCorrectionWithFixRange((int32_t)offsetCold, (int32_t)offsetHot, temperature);
    const int32_t gain32 = Cy_DSADC_CalibCalcCorrectionWithFixRange((int32_t)gainCold, (int32_t)gainHot, temperature);

    *ocor = Cy_DSADC_CalibSaturateOffset(offset32);
    *gcor = Cy_DSADC_CalibSaturateGain(gain32);
}

/*******************************************************************************
* Function Name: Cy_DSADC_CalibCalcAchan1_3TempTrim
****************************************************************************//**
*
* \brief Calculate the gain and the offset correction values for the ACHAN1
* with the temperature and the calibration data stored in SFLASH.
*
* \note Applicable to PSOC4 HVPA only.
* If the temperature is out of range,
* then trim value is calculated with the minimum or the maximum temperature.
*
* \param gcor
* The gain correction value.
*
* \param ocor
* The offset correction value.
*
* \param divider
* The HV divider output to refer to the three temperature trim values for the ACHAN1.
*
* \param temperature
* Temperature in fixed point format Q12.20. \ref CY_DSADC_TEMPERATURE_FRACTION_BITS
*
*******************************************************************************/
static void Cy_DSADC_CalibCalcAchan1_3TempTrim(uint16_t* gcor,
                                               int16_t* ocor,
                                               cy_en_dsadc_achan_3temp_trim_divider_type_t divider,
                                               int32_t temperature)
{
    CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 10.8', 9, \
    'Casting uint32_t to int32_t will not result in overflow.');
    /* Saturate if given temperature over the range. */
    int32_t saturateTemp = (temperature > CY_DSADC_MAX_TEMPERATURE_IN_FP) ? CY_DSADC_MAX_TEMPERATURE_IN_FP : \
                           (temperature < CY_DSADC_MIN_TEMPERATURE_IN_FP) ? CY_DSADC_MIN_TEMPERATURE_IN_FP : \
                           temperature;

    const uint32_t regIndex = (uint32_t)divider * CY_DSADC_ACHAN1_3TEMP_OFFSET;
    const uint32_t centerTemp = _FLD2VAL(SFLASH_PACSS_CHAN_3TEMP_CENTERTEMP_CENTERTEMP, \
                                         SFLASH->PACSS_CHAN_3TEMP_CENTERTEMP);
    const uint32_t centerTempFp = centerTemp << CY_DSADC_TEMPERATURE_FRACTION_BITS;

    uint32_t deltaTempFromBase;
    uint32_t tempRange;
    int16_t baseOffset;
    int16_t maxOffset;
    uint16_t baseGain;
    uint16_t maxGain;

    if(saturateTemp >= (int32_t)centerTempFp)
    {
        tempRange  = ((uint32_t)CY_DSADC_MAX_TEMPERATURE - centerTemp);
        const int32_t deltaTempFromBaseTemp = saturateTemp - (int32_t)centerTempFp;
        deltaTempFromBase = (uint32_t)deltaTempFromBaseTemp;
        deltaTempFromBase = deltaTempFromBase >> CY_DSADC_TEMPERATURE_TO_REDUCTION_FORMAT;
        /* Get gain and offset trim values */
        maxOffset = CY_DSADC_GET_INT16(SFLASH_PACSS_CHAN1_3TEMP_TRIM_OFFSETADJ, \
                                       SFLASH->PACSS_CHAN1_3TEMP_TRIM[regIndex + CY_DSADC_ACHAN1_3TEMP_HOT_OFFSET]);
        maxGain = CY_DSADC_GET_UINT16(SFLASH_PACSS_CHAN1_3TEMP_TRIM_GAINADJ, \
                                      SFLASH->PACSS_CHAN1_3TEMP_TRIM[regIndex + CY_DSADC_ACHAN1_3TEMP_HOT_OFFSET]);
        baseOffset = CY_DSADC_GET_INT16(SFLASH_PACSS_CHAN1_3TEMP_TRIM_OFFSETADJ, \
                                        SFLASH->PACSS_CHAN1_3TEMP_TRIM[regIndex + CY_DSADC_ACHAN1_3TEMP_CENTER_OFFSET]);
        baseGain = CY_DSADC_GET_UINT16(SFLASH_PACSS_CHAN1_3TEMP_TRIM_GAINADJ, \
                                       SFLASH->PACSS_CHAN1_3TEMP_TRIM[regIndex + CY_DSADC_ACHAN1_3TEMP_CENTER_OFFSET]);
    }
    else
    {
        int32_t deltaTempFromBaseTemp = (int32_t)centerTemp - CY_DSADC_MIN_TEMPERATURE;
        tempRange = (uint32_t)deltaTempFromBaseTemp;
        deltaTempFromBaseTemp = saturateTemp - CY_DSADC_MIN_TEMPERATURE_IN_FP;
        deltaTempFromBase = (uint32_t)deltaTempFromBaseTemp;
        deltaTempFromBase = deltaTempFromBase >> CY_DSADC_TEMPERATURE_TO_REDUCTION_FORMAT;
        /* Get gain and offset trim values */
        maxOffset = CY_DSADC_GET_INT16(SFLASH_PACSS_CHAN1_3TEMP_TRIM_OFFSETADJ, \
                                       SFLASH->PACSS_CHAN1_3TEMP_TRIM[regIndex + CY_DSADC_ACHAN1_3TEMP_CENTER_OFFSET]);
        maxGain = CY_DSADC_GET_UINT16(SFLASH_PACSS_CHAN1_3TEMP_TRIM_GAINADJ, \
                                      SFLASH->PACSS_CHAN1_3TEMP_TRIM[regIndex + CY_DSADC_ACHAN1_3TEMP_CENTER_OFFSET]);
        baseOffset = CY_DSADC_GET_INT16(SFLASH_PACSS_CHAN1_3TEMP_TRIM_OFFSETADJ, \
                                        SFLASH->PACSS_CHAN1_3TEMP_TRIM[regIndex]);
        baseGain = CY_DSADC_GET_UINT16(SFLASH_PACSS_CHAN1_3TEMP_TRIM_GAINADJ, \
                                       SFLASH->PACSS_CHAN1_3TEMP_TRIM[regIndex]);
    }
    CY_MISRA_BLOCK_END('MISRA C-2012 Rule 10.8');

    const int32_t offset32 = Cy_DSADC_CalibCalcCorrection((int32_t)baseOffset, (int32_t)maxOffset, tempRange, deltaTempFromBase);
    const int32_t gain32 = Cy_DSADC_CalibCalcCorrection((int32_t)baseGain, (int32_t)maxGain, tempRange, deltaTempFromBase);

    *ocor = Cy_DSADC_CalibSaturateOffset(offset32);
    *gcor = Cy_DSADC_CalibSaturateGain(gain32);
}

/*******************************************************************************
* Function Name: Cy_DSADC_CalibCalcAchan0_3TempTrim
****************************************************************************//**
*
* \brief Calculate the gain and the offset correction values for the HV divider on ACHAN0
* with the temperature and the calibration data stored in SFLASH.
*
* \note Applicable to PSOC4 HVPA only.
* If the temperature is out of range,
* then trim value is calculated with the minimum or the maximum temperature
*
* \param gcor
* The gain correction value.
*
* \param ocor
* The offset correction value.
*
* \param divider
* The HV divider output to refer to the three temperature trim values for the ACHAN1.
*
* \param temperature
* Temperature in fixed point format Q12.20. \ref CY_DSADC_TEMPERATURE_FRACTION_BITS
*
*******************************************************************************/
static void Cy_DSADC_CalibCalcAchan0_3TempTrim(uint16_t* gcor,
                                               int16_t* ocor,
                                               cy_en_dsadc_achan_3temp_trim_divider_type_t divider,
                                               int32_t temperature)
{
    uint16_t gcorCh0 = 0U;
    int16_t ocorCh0 = 0;
    uint16_t gcorCh1 = 0U;
    int16_t ocorCh1 = 0;
    uint16_t gcorHvCh1 = 0U;
    int16_t ocorHvCh1 = 0;

    Cy_DSADC_CalibCalcAchan0_2TempTrim(&gcorCh0, &ocorCh0, CY_DSADC_ACHAN0_2TEMP_GAIN_1X, temperature);
    Cy_DSADC_CalibCalcAchan1_2TempTrim(&gcorCh1, &ocorCh1, CY_DSADC_ACHAN1_2TEMP_GAIN_1X, temperature);
    Cy_DSADC_CalibCalcAchan1_3TempTrim(&gcorHvCh1, &ocorHvCh1, divider, temperature);

    *gcor = Cy_DSADC_CalibCalcAchan0_GainCorrection(gcorCh0, gcorCh1, gcorHvCh1);
    *ocor = Cy_DSADC_CalibCalcAchan0_OffsetCorrection(gcorCh0, gcorCh1, ocorCh0, ocorCh1, ocorHvCh1);
}

/*******************************************************************************
* Function Name: Cy_DSADC_CalibCalcAchan1_ExtTempTrim
****************************************************************************//**
*
* \brief Calculate the gain and the offset correction values for the ACHAN1 external
* temperature with the temperature and the calibration data stored in SFLASH.
*
* \note Applicable to PSOC4 HVPA only.
* If the temperature is out of range,
* then trim value is calculated with the minimum or the maximum temperature.
*
* \param gcor
* The gain correction value.
*
* \param ocor
* The offset correction value.
*
* \param temperature
* Temperature in fixed point format Q12.20. \ref CY_DSADC_TEMPERATURE_FRACTION_BITS
*
*******************************************************************************/
static void Cy_DSADC_CalibCalcAchan1_ExtTempTrim(uint16_t* gcor, int16_t* ocor, int32_t temperature)
{
    CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 10.8', 2, \
    'Casting uint32_t to int32_t will not result in overflow.');
    const int16_t offsetHot = CY_DSADC_GET_INT16(SFLASH_PACSS_CHAN1_2TEMP_TRIM_OFFSETADJ, \
                                                 SFLASH->PACSS_CHAN1_2TEMP_TRIM[CY_DSADC_ACHAN1_2TEMP_X1_HOT_OFFSET]);
    const int16_t offsetCold = CY_DSADC_GET_INT16(SFLASH_PACSS_CHAN1_2TEMP_TRIM_OFFSETADJ, \
                                                  SFLASH->PACSS_CHAN1_2TEMP_TRIM[CY_DSADC_ACHAN1_2TEMP_X1_COLD_OFFSET]);
    CY_MISRA_BLOCK_END('MISRA C-2012 Rule 10.8');
    const uint16_t gain = CY_DSADC_GET_UINT16(SFLASH_PACSS_CHAN1_ETEMP_TRIM_ETGAINADJ, SFLASH->PACSS_CHAN1_ETEMP_TRIM);
    const int32_t offset32 = Cy_DSADC_CalibCalcCorrectionWithFixRange((int32_t)offsetCold, (int32_t)offsetHot, temperature);

    *ocor = Cy_DSADC_CalibSaturateOffset(offset32);
    *gcor = gain;
}

/*==================[external function definitions]===========================*/
/*******************************************************************************
* Function Name: Cy_DSADC_CalibrateAchan0_2TempTrim
****************************************************************************//**
*
* \brief Calibrate the gain and the offset correction values for the ACHAN0
* with the value derived from the calibration data stored in SFLASH.
*
* \note Applicable to PSOC4 HVPA only.
* The accuracy of the correction values are [-1, 1].
* If the temperature value is out of range,
* then trim value is calculated with the minimum or the maximum temperature.
*
* \param base
* The base address for the Digital Channel.
*
* \param gain
* The gain value for the ACHAN0 see \ref cy_en_dsadc_achan0_2temp_trim_gain_type_t.
*
* \param temperature
* Temperature in fixed point format Q12.20. \ref CY_DSADC_TEMPERATURE_FRACTION_BITS
*
*******************************************************************************/
void Cy_DSADC_CalibrateAchan0_2TempTrim(PACSS_DCHAN_Type* base,
                                        cy_en_dsadc_achan0_2temp_trim_gain_type_t gain,
                                        int32_t temperature)
{
    CY_ASSERT_L1(NULL != base);
    CY_ASSERT_L1(CY_DSADC_ACHAN0_2TEMP_GAIN_512X >= gain);

    uint16_t gcor = 0U;
    int16_t ocor = 0;
    /* Calculate trim values */
    Cy_DSADC_CalibCalcAchan0_2TempTrim(&gcor, &ocor, gain, temperature);
    /* Set trim values */
    CY_REG32_CLR_SET(base->GAIN_COR, PACSS_DCHAN_GAIN_COR_GCOR, gcor);
    CY_REG32_CLR_SET(base->OFST_COR, PACSS_DCHAN_OFST_COR_OCOR, (uint16_t)ocor);
}

/*******************************************************************************
* Function Name: Cy_DSADC_CalibrateAchan1_2TempTrim
****************************************************************************//**
*
* \brief Calibrate the gain and the offset correction values for the ACHAN1
* with the value derived from the calibration data stored in SFLASH.
*
* \note Applicable to PSOC4 HVPA only.
* The accuracy of the correction values are [-1, 1].
* If the temperature value is out of range,
* then trim value is calculated with the minimum or the maximum temperature.
*
* \param base
* The base address for the Digital Channel.
*
* \param gain
* The gain value for the ACHAN1 see \ref cy_en_dsadc_achan1_2temp_trim_gain_type_t.
*
* \param temperature
* Temperature in fixed point format Q12.20. \ref CY_DSADC_TEMPERATURE_FRACTION_BITS
*
*******************************************************************************/
void Cy_DSADC_CalibrateAchan1_2TempTrim(PACSS_DCHAN_Type* base,
                                        cy_en_dsadc_achan1_2temp_trim_gain_type_t gain,
                                        int32_t temperature)
{
    CY_ASSERT_L1(NULL != base);
    CY_ASSERT_L1(CY_DSADC_ACHAN1_2TEMP_GAIN_512X >= gain);

    uint16_t gcor = 0U;
    int16_t ocor = 0;
    /* Calculate trim values */
    Cy_DSADC_CalibCalcAchan1_2TempTrim(&gcor, &ocor, gain, temperature);
    /* Set trim values */
    CY_REG32_CLR_SET(base->GAIN_COR, PACSS_DCHAN_GAIN_COR_GCOR, gcor);
    CY_REG32_CLR_SET(base->OFST_COR, PACSS_DCHAN_OFST_COR_OCOR, (uint16_t)ocor);
}

/*******************************************************************************
* Function Name: Cy_DSADC_CalibrateAchan1_3TempTrim
****************************************************************************//**
*
* \brief Calibrate the gain and the offset correction values for the ACHAN1
* with the value derived from the calibration data stored in SFLASH.
*
* \note Applicable to PSOC4 HVPA only.
* The accuracy of the correction values are [-1, 1].
* If the temperature value is out of range,
* then trim value is calculated with the minimum or the maximum temperature.
*
* \param base
* The base address for the Digital Channel.
*
* \param divider
* The HV divider output for the ACHAN1 see \ref cy_en_dsadc_achan_3temp_trim_divider_type_t.
*
* \param temperature
* Temperature in fixed point format Q12.20. \ref CY_DSADC_TEMPERATURE_FRACTION_BITS
*
*******************************************************************************/
void Cy_DSADC_CalibrateAchan1_3TempTrim(PACSS_DCHAN_Type* base,
                                        cy_en_dsadc_achan_3temp_trim_divider_type_t divider,
                                        int32_t temperature)
{
    CY_ASSERT_L1(NULL != base);
    CY_ASSERT_L1(CY_DSADC_ACHAN_3TEMP_VDIAG_24 >= divider);

    uint16_t gcor = 0U;
    int16_t ocor = 0;
    /* Calculate trim values */
    Cy_DSADC_CalibCalcAchan1_3TempTrim(&gcor, &ocor, divider, temperature);
    /* Set trim values */
    CY_REG32_CLR_SET(base->GAIN_COR, PACSS_DCHAN_GAIN_COR_GCOR, gcor);
    CY_REG32_CLR_SET(base->OFST_COR, PACSS_DCHAN_OFST_COR_OCOR, (uint16_t)ocor);
}

/*******************************************************************************
* Function Name: Cy_DSADC_CalibrateAchan0_3TempTrim
****************************************************************************//**
*
* \brief Calibrate the gain and the offset correction values for the HV divider on ACHAN0
* with the value derived from the calibration data stored in SFLASH.
*
* \note Applicable to PSOC4 HVPA only.
* The accuracy of the correction values are [-1, 1].
* If the temperature value is out of range,
* then trim value is calculated with the minimum or the maximum temperature.
*
* \param base
* The base address for the Digital Channel.
*
* \param divider
* The HV divider output for the ACHAN1 see \ref cy_en_dsadc_achan_3temp_trim_divider_type_t.
*
* \param temperature
* Temperature in fixed point format Q12.20. \ref CY_DSADC_TEMPERATURE_FRACTION_BITS
*
*******************************************************************************/
void Cy_DSADC_CalibrateAchan0_3TempTrim(PACSS_DCHAN_Type* base,
                                        cy_en_dsadc_achan_3temp_trim_divider_type_t divider,
                                        int32_t temperature)
{
    CY_ASSERT_L1(NULL != base);
    CY_ASSERT_L1(CY_DSADC_ACHAN_3TEMP_VDIAG_24 >= divider);

    uint16_t gcor = 0U;
    int16_t ocor = 0;
    /* Calculate trim values */
    Cy_DSADC_CalibCalcAchan0_3TempTrim(&gcor, &ocor, divider, temperature);
    /* Set trim values */
    CY_REG32_CLR_SET(base->GAIN_COR, PACSS_DCHAN_GAIN_COR_GCOR, gcor);
    CY_REG32_CLR_SET(base->OFST_COR, PACSS_DCHAN_OFST_COR_OCOR, (uint16_t)ocor);
}

/*******************************************************************************
* Function Name: Cy_DSADC_CalibrateAgcGainLevel
****************************************************************************//**
*
* \brief Calibrate the gain and the offset correction values for the AGC
* with the value derived from the calibration data stored in SFLASH.
*
* \note Applicable to PSOC4 HVPA only.
* The accuracy of the correction values are [-1, 1].
* If the temperature value is out of range,
* then trim value is calculated with the minimum or the maximum temperature.
*
* \param base
* The pointer to the MMIO instance of the PACSS.
*
* \param gain
* The gain value for the AGC see \ref cy_en_dsadc_achan0_2temp_trim_gain_type_t.
*
* \param index
* The AGC gain level to be calibrated.
*
* \param temperature
* Temperature in fixed point format Q12.20. \ref CY_DSADC_TEMPERATURE_FRACTION_BITS
*
*******************************************************************************/
void Cy_DSADC_CalibrateAgcGainLevel(PACSS_MMIO_Type* base,
                                    cy_en_dsadc_achan0_2temp_trim_gain_type_t gain,
                                    uint8_t index,
                                    int32_t temperature)
{
    CY_ASSERT_L1(NULL != base);
    CY_ASSERT_L1(CY_DSADC_ACHAN0_2TEMP_GAIN_512X >= gain);
    CY_ASSERT_L1(CY_DSADC_MAX_GAIN_LEVEL_INDEX >= (uint32_t)index);

    uint16_t gcor = 0U;
    int16_t ocor = 0;
    /* Calculate trim values */
    Cy_DSADC_CalibCalcAchan0_2TempTrim(&gcor, &ocor, gain, temperature);
    /* Set trim values */
    CY_REG32_CLR_SET(base->GAINLVL_STRUCT[index].GAIN_COR, PACSS_MMIO_GAINLVL_STRUCT_GAIN_COR_GCOR, (uint32_t)gcor);
    CY_REG32_CLR_SET(base->GAINLVL_STRUCT[index].OFST_COR,
                     PACSS_MMIO_GAINLVL_STRUCT_OFST_COR_OCOR,
                     (uint32_t)ocor);
}

/*******************************************************************************
* Function Name: Cy_DSADC_CalibrateAchan1_ExtTempTrim
****************************************************************************//**
*
* \brief Calibrate the gain and the offset correction values for the ACHAN1 external
* temperature with the value derived from the calibration data stored in SFLASH.
*
* \note Applicable to PSOC4 HVPA only.
* The accuracy of the correction values are [-1, 1].
* If the temperature value is out of range,
* then trim value is calculated with the minimum or the maximum temperature.
*
* \param base
* The base address for the Digital Channel.
*
* \param temperature
* Temperature in fixed point format Q12.20. \ref CY_DSADC_TEMPERATURE_FRACTION_BITS
*
*******************************************************************************/
void Cy_DSADC_CalibrateAchan1_ExtTempTrim(PACSS_DCHAN_Type* base, int32_t temperature)
{
    CY_ASSERT_L1(NULL != base);

    uint16_t gcor = 0U;
    int16_t ocor = 0;
    /* Calculate trim values */
    Cy_DSADC_CalibCalcAchan1_ExtTempTrim(&gcor, &ocor, temperature);
    /* Set trim values */
    CY_REG32_CLR_SET(base->GAIN_COR, PACSS_DCHAN_GAIN_COR_GCOR, gcor);
    CY_REG32_CLR_SET(base->OFST_COR, PACSS_DCHAN_OFST_COR_OCOR, (uint16_t)ocor);
}

/*******************************************************************************
* Function Name: Cy_DSADC_GetPullupResistance
****************************************************************************//**
*
* \brief
* Get the pull-up resistance value to suit the shunt pin and the current temperature.
* \param select
* Pull-up input selection. See \ref cy_en_dsadc_dchan_reference_pullup_t.
* \param temperature
* Temperature in fixed point format Q12.20. \ref CY_DSADC_TEMPERATURE_FRACTION_BITS
* \return
* The pull-up resistance value in Ohms.
* \note
* If the select value is out of range, the resistance values for cold and hot
* are set to 0, and the result is calculated based on these values.
*
*******************************************************************************/
uint16_t Cy_DSADC_GetPullupResistance(cy_en_dsadc_dchan_reference_pullup_t select, int32_t temperature)
{
    CY_ASSERT_L3(CY_DSADC_DCHAN_REFERENCE_PULLUP_RSL0 >= select);

    int32_t cold = 0;
    int32_t hot  = 0;

    CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 10.8', 8, \
    'Casting uint32_t to int32_t will not result in overflow.');
    switch (select)
    {
    case CY_DSADC_DCHAN_REFERENCE_PULLUP_RSH0:
        cold = (int32_t)_FLD2VAL(SFLASH_PACSS_DIAG_RSH_PURES_RES_COLD, SFLASH->PACSS_DIAG_RSH_PURES);
        hot  = (int32_t)_FLD2VAL(SFLASH_PACSS_DIAG_RSH_PURES_RES_HOT, SFLASH->PACSS_DIAG_RSH_PURES);
        break;

    case CY_DSADC_DCHAN_REFERENCE_PULLUP_RSL0:
        cold = (int32_t)_FLD2VAL(SFLASH_PACSS_DIAG_RSL_PURES_RES_COLD, SFLASH->PACSS_DIAG_RSL_PURES);
        hot  = (int32_t)_FLD2VAL(SFLASH_PACSS_DIAG_RSL_PURES_RES_HOT, SFLASH->PACSS_DIAG_RSL_PURES);
        break;

    case CY_DSADC_DCHAN_REFERENCE_PULLUP_RSH1:
        cold = (int32_t)_FLD2VAL(SFLASH_PACSS_DIAG_RSH2_PURES_RES_COLD, SFLASH->PACSS_DIAG_RSH2_PURES);
        hot  = (int32_t)_FLD2VAL(SFLASH_PACSS_DIAG_RSH2_PURES_RES_HOT, SFLASH->PACSS_DIAG_RSH2_PURES);
        break;

    case CY_DSADC_DCHAN_REFERENCE_PULLUP_RSL1:
        cold = (int32_t)_FLD2VAL(SFLASH_PACSS_DIAG_RSL2_PURES_RES_COLD, SFLASH->PACSS_DIAG_RSL2_PURES);
        hot  = (int32_t)_FLD2VAL(SFLASH_PACSS_DIAG_RSL2_PURES_RES_HOT, SFLASH->PACSS_DIAG_RSL2_PURES);
        break;

    default:
        /* Wrong reference pullup */
        break;
    }
    CY_MISRA_BLOCK_END('MISRA C-2012 Rule 10.8');

    /* Convert resistance values from Ohms/32 to Ohms */
    cold *= CY_DSADC_SFLASH_PULLUP_TO_OHMS;
    hot  *= CY_DSADC_SFLASH_PULLUP_TO_OHMS;

    return (uint16_t)Cy_DSADC_CalibCalcCorrectionWithFixRange(cold, hot, temperature);
}

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* (CY_IP_M0S8PACSS) */

/* [] END OF FILE */
