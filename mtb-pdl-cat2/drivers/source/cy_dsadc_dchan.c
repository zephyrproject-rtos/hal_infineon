/***************************************************************************//**
* \file cy_dsadc_dchan.c
* \version 1.0
*
* \brief
* Provides an API implementation of the digital channels Delta-Sigma ADC
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

#if defined(CY_IP_M0S8PACSS)

#if defined(__cplusplus)
extern "C" {
#endif

/*==================[internal function definitions]===========================*/
/*******************************************************************************
* Function Name: Cy_DSADC_Dchan_SetupFIR
****************************************************************************//**
*
* \brief
* Enable FIR by updating coefficient value, or disable FIR.
* \param base
* The base address for the Digital Channel.
* \param config
* Non-null FIR Filter configuration
*
******************************************************l*************************/
static void Cy_DSADC_Dchan_SetupFIR(PACSS_DCHAN_Type* base,
                                    const cy_stc_dsadc_fir_config_t* config)
{
    /* Set num taps */
    CY_REG32_CLR_SET(base->DCHAN_CTL, PACSS_DCHAN_DCHAN_CTL_FIR_NUM_TAPS, config->numTaps);

    for(uint32_t iter = 0UL; iter <= (uint32_t)config->numTaps; iter++)
    {
        /* Set FIR coefficient */
        base->FCFG[iter].COEF = (uint16_t)config->coefficients[iter];
        base->FCFG[iter].TAP  = 0U; /* clear TAP value */
    }

    /* Enable FIR */
    base->DCHAN_CTL |= PACSS_DCHAN_DCHAN_CTL_FIR_EN_Msk;
}

/*******************************************************************************
* Function Name: Cy_DSADC_Dchan_ConfigureFIRFilter
****************************************************************************//**
*
* \brief
* Configure the Digital Channel FIR Filter Coefficients.
* \param base
* The base address for the Digital Channel.
* \param config
* Non-null FIR Filter configuration.
*
* \note call with config = NULL will disable FIR
*
*******************************************************************************/
static void Cy_DSADC_Dchan_ConfigureFIRFilter(PACSS_DCHAN_Type* base,
            const cy_stc_dsadc_fir_config_t* config)
{
    if(NULL == config)
    {
        /* Disable FIR */
        base->DCHAN_CTL &= ~PACSS_DCHAN_DCHAN_CTL_FIR_EN_Msk;
        /* no shift */
        base->PP_CTL &= ~PACSS_DCHAN_PP_CTL_PP_SHIFTR_Msk;
    }
    else
    {
        /* Set the number of taps */
        Cy_DSADC_Dchan_SetupFIR(base, config);
    }
}

/*==================[external function definitions]===========================*/
/*******************************************************************************
* Function Name: Cy_DSADC_DisableDchan
****************************************************************************//**
*
* \brief
* Disable the Digital Channel.
* \param base
* The base address for the Digital Channel.
*
*******************************************************************************/
void Cy_DSADC_DisableDchan(PACSS_DCHAN_Type* base)
{
    /* Disable DCHAN */
    base->DCHAN_CTL &= ~PACSS_DCHAN_DCHAN_CTL_ENABLE_Msk;
}

/*******************************************************************************
* Function Name: Cy_DSADC_DisablePullup
****************************************************************************//**
*
* \brief
* Disable the pull-up resistor connection.
* \param base
* The base address for the Digital Channel.
*
*******************************************************************************/
void Cy_DSADC_DisablePullup(PACSS_DCHAN_Type* base)
{
    /* Disable pull-up */
    base->SMP_REF_CTL &= ~PACSS_DCHAN_SMP_REF_CTL_RS_PULLUP_EN_Msk;
}

/*******************************************************************************
* Function Name: Cy_DSADC_EnableDchan
****************************************************************************//**
*
* \brief
* Enable the Digital Channel.
* \param base
* The base address for the Digital Channel.
*
*******************************************************************************/
void Cy_DSADC_EnableDchan(PACSS_DCHAN_Type* base)
{
    /* Enable DCHAN */
    base->DCHAN_CTL |= PACSS_DCHAN_DCHAN_CTL_ENABLE_Msk;
}

/*******************************************************************************
* Function Name: Cy_DSADC_EnablePullup
****************************************************************************//**
*
* \brief
* Enable the pull-up resistor connection.
* \param base
* The base address for the Digital Channel.
*
*******************************************************************************/
void Cy_DSADC_EnablePullup(PACSS_DCHAN_Type* base)
{
    /* Enable pull-up */
    base->SMP_REF_CTL |= PACSS_DCHAN_SMP_REF_CTL_RS_PULLUP_EN_Msk;
}

/*******************************************************************************
* Function Name: Cy_DSADC_InitDchan
****************************************************************************//**
*
* \brief
* Configure the Digital Channel
* \param base
* The base address for the Digital Channel.
* \param config
* Configuration options for the Digital Channel.
*
*******************************************************************************/
void Cy_DSADC_InitDchan(PACSS_DCHAN_Type* base, const cy_stc_dsadc_dchan_config_t* config)
{
    /* Set DCHAN_CTL register (AGC_GAIN_EN, SEC_EN) */
    CY_REG32_CLR_SET(base->DCHAN_CTL, PACSS_DCHAN_DCHAN_CTL_SEC_EN, config->priority);
    if (false != config->useAgc)
    {
        base->DCHAN_CTL |= PACSS_DCHAN_DCHAN_CTL_AGC_GAIN_EN_Msk;
    }
    else
    {
        base->DCHAN_CTL &= ~PACSS_DCHAN_DCHAN_CTL_AGC_GAIN_EN_Msk;
    }

    /* Set DEC_CTL register */
    base->DEC_CTL = (_VAL2FLD(PACSS_DCHAN_DEC_CTL_SINC_MODE, config->sincMode) | \
                     _VAL2FLD(PACSS_DCHAN_DEC_CTL_CONV_MODE, config->conversionMode) | \
                     _VAL2FLD(PACSS_DCHAN_DEC_CTL_DR, config->stage1DecimationRatio) | \
                     PACSS_DCHAN_DEC_CTL_SAT_EN_Msk | \
                     _VAL2FLD(PACSS_DCHAN_DEC_CTL_DR2, config->stage2DecimationRatio) | \
                     _VAL2FLD(PACSS_DCHAN_DEC_CTL_DEC_SHIFTR, config->rightShift) | \
                     _VAL2FLD(PACSS_DCHAN_DEC_CTL_RR_SHIFTR, config->rateReducerRightShift));
    if (false != config->enableOffsetCorrection)
    {
        Cy_DSADC_EnableOffsetCorrection(base);
    }
    else
    {
        Cy_DSADC_DisableOffsetCorrection(base);
    }
    if (false != config->enableGainCorrection)
    {
        Cy_DSADC_EnableGainCorrection(base);
    }
    else
    {
        Cy_DSADC_DisableGainCorrection(base);
    }
    /* Set SMP_CTL register */
    base->SMP_CTL = (_VAL2FLD(PACSS_DCHAN_SMP_CTL_ACHAN_SEL, config->achan) | \
                     _VAL2FLD(PACSS_DCHAN_SMP_CTL_POS_PIN_SEL, config->pinPositive) | \
                     _VAL2FLD(PACSS_DCHAN_SMP_CTL_NEG_PIN_SEL, config->pinNegative) | \
                     _VAL2FLD(PACSS_DCHAN_SMP_CTL_CH_SEL_DLY, config->channelSelectDelay) | \
                     _VAL2FLD(PACSS_DCHAN_SMP_CTL_MOV_SUM, config->averagingMode) | \
                     _VAL2FLD(PACSS_DCHAN_SMP_CTL_AVG_MODE, config->averagingSamples));
    if(CY_DSADC_AAF_BYPASS == config->aafMode)
    {
        base->SMP_CTL |= PACSS_DCHAN_SMP_CTL_BYPASS_AAF_Msk;
        base->SMP_CTL &= ~PACSS_DCHAN_SMP_CTL_AAF_SHORT_R_EN_Msk;
    }
    else if(CY_DSADC_AAF_ENABLE == config->aafMode)
    {
        base->SMP_CTL &= ~PACSS_DCHAN_SMP_CTL_BYPASS_AAF_Msk;
        base->SMP_CTL &= ~PACSS_DCHAN_SMP_CTL_AAF_SHORT_R_EN_Msk;
    }
    else
    {
        base->SMP_CTL &= ~PACSS_DCHAN_SMP_CTL_BYPASS_AAF_Msk;
        base->SMP_CTL |= PACSS_DCHAN_SMP_CTL_AAF_SHORT_R_EN_Msk;
    }

    /* Set SMP_REF_CTL register */
    Cy_DSADC_SetVref(base, config->vrefhSelect, config->vreflSelect);

    /* Set PP_CTL register (range detection) */
    base->PP_CTL = (_VAL2FLD(PACSS_DCHAN_PP_CTL_RANGE_DET_EN, config->rangeMode) | \
                    _VAL2FLD(PACSS_DCHAN_PP_CTL_RANGE_COND, config->rangeConditional) | \
                    _VAL2FLD(PACSS_DCHAN_PP_CTL_RANGE_CNT_VAL, config->rangeCount) | \
                    _VAL2FLD(PACSS_DCHAN_PP_CTL_PP_SHIFTR, config->ppRightShift));
    base->PP_CTL &= ~PACSS_DCHAN_PP_CTL_CLAMP_Msk; /* disable clamp result to 24 bits. Use 32 bits result */

    base->RANGE_LOW = (uint32_t)config->rangeLowerThreshold;
    base->RANGE_HIGH = (uint32_t)config->rangeUpperThreshold;
    /* Enable post processing */
    base->DCHAN_CTL |= PACSS_DCHAN_DCHAN_CTL_PP_EN_Msk;
    /* Set offset correction */
    CY_REG32_CLR_SET(base->OFST_COR, PACSS_DCHAN_OFST_COR_OCOR_SCLR, (((SFLASH_Type *) SFLASH)->PACSS_CHAN_OFFSET_SCLR));
    /* Set valid bits of the gain correction */
    CY_REG32_CLR_SET(base->GAIN_COR, PACSS_DCHAN_GAIN_COR_GVAL, config->validGcorBits);
    /* Configure gain level */
    Cy_DSADC_ConfigureGainLevel(base, config->gain);
    /* Configure FIR filter */
    Cy_DSADC_Dchan_ConfigureFIRFilter(base, config->fir);
}

/*******************************************************************************
* Function Name: Cy_DSADC_SetGainCorrection
****************************************************************************//**
*
* \brief
* Set the gain correction factor for the specified DCHAN.
* \param base
* The base address for the Digital Channel.
* \param gain
* Gain correction factor. Valid inputs are between 0 and 65535.
*
*******************************************************************************/
void Cy_DSADC_SetGainCorrection(PACSS_DCHAN_Type* base, uint16_t gain)
{
    /* Set gain correction */
    CY_REG32_CLR_SET(base->GAIN_COR, PACSS_DCHAN_GAIN_COR_GCOR, gain);
}

/*******************************************************************************
* Function Name: Cy_DSADC_SetOffsetCorrection
****************************************************************************//**
*
* \brief
* Set the offset correction factor for the specified DCHAN.
* \param base
* The base address for the Digital Channel.
* \param offset
* Offset correction factor. Valid inputs are between -32768 and 32767.
*
*******************************************************************************/
void Cy_DSADC_SetOffsetCorrection(PACSS_DCHAN_Type* base, int16_t offset)
{
    /* Set offset correction */
    CY_REG32_CLR_SET(base->OFST_COR, PACSS_DCHAN_OFST_COR_OCOR, (uint16_t)offset);
}

/*******************************************************************************
* Function Name: Cy_DSADC_SetInputPin
****************************************************************************//**
*
* \brief
* Set the input pin combination of the DCHAN.
* \param base
* The base address for the Digital Channel.
* \param pinPositive
* Positive input pin see \ref cy_en_dsadc_dchan_positive_pin_t
* \param pinNegative
* Negative input pin see \ref cy_en_dsadc_dchan_negative_pin_t
*
*******************************************************************************/
void Cy_DSADC_SetInputPin(PACSS_DCHAN_Type* base,
                          cy_en_dsadc_dchan_positive_pin_t pinPositive,
                          cy_en_dsadc_dchan_negative_pin_t pinNegative)
{
    /* Set positive and negative pin */
    CY_REG32_CLR_SET(base->SMP_CTL, PACSS_ACHAN_INMUX_CTL_POS_PIN_SEL, pinPositive);
    CY_REG32_CLR_SET(base->SMP_CTL, PACSS_ACHAN_INMUX_CTL_NEG_PIN_SEL, pinNegative);
}

/*******************************************************************************
* Function Name: Cy_DSADC_SetPullupSelect
****************************************************************************//**
*
* \brief
* Set the pull-up resistor for open wire detection based on the selection,
* the pin is pulled-up to VDDA via 4k-ohm resistor for open wire detection.
* \param base
* The base address for the Digital Channel.
* \param select
* Pull-up input selection see \ref cy_en_dsadc_dchan_reference_pullup_t
*
*******************************************************************************/
void Cy_DSADC_SetPullupSelect(PACSS_DCHAN_Type* base, cy_en_dsadc_dchan_reference_pullup_t select)
{
    /* Set pullup select */
    CY_REG32_CLR_SET(base->SMP_REF_CTL, PACSS_DCHAN_SMP_REF_CTL_RS_PULLUP_SEL, (uint32_t)select);
}

/*******************************************************************************
* Function Name: Cy_DSADC_SetSampleMode
****************************************************************************//**
*
* \brief
* Set the digital channel's sample mode.
* \param base
* The base address for the Digital Channel.
* \param mode
* The sample mode to be used are \ref cy_en_dsadc_dchan_sample_mode_t
*
*******************************************************************************/
void Cy_DSADC_SetSampleMode(PACSS_DCHAN_Type* base, cy_en_dsadc_dchan_sample_mode_t mode)
{
    /* Set sample mode */
    CY_REG32_CLR_SET(base->DEC_CTL, PACSS_DCHAN_DEC_CTL_CONV_MODE, (uint32_t)mode);
}

/*******************************************************************************
* Function Name: Cy_DSADC_SetVref
****************************************************************************//**
*
* \brief
* Set the voltage reference of the DCHAN.
* \param base
* The base address for the Digital Channel.
* \param vrefh
* High reference selection are \ref cy_en_dsadc_dchan_reference_vrefh_t
* \param vrefl
* Low reference selection are \ref cy_en_dsadc_dchan_reference_vrefl_t
*
*******************************************************************************/
void Cy_DSADC_SetVref(PACSS_DCHAN_Type* base,
                      cy_en_dsadc_dchan_reference_vrefh_t vrefh,
                      cy_en_dsadc_dchan_reference_vrefl_t vrefl)
{
    /* Set VREFH, VREFL and VREF buffer */
    CY_REG32_CLR_SET(base->SMP_REF_CTL, PACSS_DCHAN_SMP_REF_CTL_VREFH_SEL, vrefh);
    CY_REG32_CLR_SET(base->SMP_REF_CTL, PACSS_DCHAN_SMP_REF_CTL_VREFL_SEL, vrefl);
    if (CY_DSADC_DCHAN_REFERENCE_VREFH_DIRECT != vrefh)
    {
        base->SMP_REF_CTL |= PACSS_DCHAN_SMP_REF_CTL_VREF_BUF_EN_Msk;
    }
    else
    {
        base->SMP_REF_CTL &= ~PACSS_DCHAN_SMP_REF_CTL_VREF_BUF_EN_Msk;
    }
}

/*******************************************************************************
* Function Name: Cy_DSADC_DisableGainCorrection
****************************************************************************//**
*
* \brief
* Disable the gain correction.
* \param base
* The base address for the Digital Channel.
*
*******************************************************************************/
void Cy_DSADC_DisableGainCorrection(PACSS_DCHAN_Type* base)
{
    /* Disable gain correction */
    base->DEC_CTL &= ~PACSS_DCHAN_DEC_CTL_GCOR_EN_Msk;
}

/*******************************************************************************
* Function Name: Cy_DSADC_DisableOffsetCorrection
****************************************************************************//**
*
* \brief
* Disable the offset correction.
* \param base
* The base address for the Digital Channel.
*
*******************************************************************************/
void Cy_DSADC_DisableOffsetCorrection(PACSS_DCHAN_Type* base)
{
    /* Disable offset correction */
    base->DEC_CTL &= ~PACSS_DCHAN_DEC_CTL_OCOR_EN_Msk;
}

/*******************************************************************************
* Function Name: Cy_DSADC_EnableGainCorrection
****************************************************************************//**
*
* \brief
* Enable the gain correction.
* \param base
* The base address for the Digital Channel.
*
*******************************************************************************/
void Cy_DSADC_EnableGainCorrection(PACSS_DCHAN_Type* base)
{
    /* Enable gain correction */
    base->DEC_CTL |= PACSS_DCHAN_DEC_CTL_GCOR_EN_Msk;
}

/*******************************************************************************
* Function Name: Cy_DSADC_EnableOffsetCorrection
****************************************************************************//**
*
* \brief
* Enable the offset correction.
* \param base
* The base address for the Digital Channel.
*
*******************************************************************************/
void Cy_DSADC_EnableOffsetCorrection(PACSS_DCHAN_Type* base)
{
    /* Enable offset correction */
    base->DEC_CTL |= PACSS_DCHAN_DEC_CTL_OCOR_EN_Msk;
}

/*******************************************************************************
* Function Name: Cy_DSADC_ConfigureGainLevel
****************************************************************************//**
*
* \brief
* Configure gain level of the digital channel.
* \param base
* The base address for the Digital Channel.
* \param gain
* Configuration options for the \ref cy_stc_dsadc_gain_level_config_t
* of the digital channel
*
*******************************************************************************/
void Cy_DSADC_ConfigureGainLevel(PACSS_DCHAN_Type* base, const cy_stc_dsadc_gain_level_config_t* gain)
{
    /* Configure gain level */
    /* Set PGA gain */
    base->PGA_GAIN_CTL = (uint32_t)gain->pgaGain;
    /* Set left shift */
    CY_REG32_CLR_SET(base->DEC_CTL, PACSS_DCHAN_DEC_CTL_SHIFTL, gain->leftShift);
    /* Set gain correction */
    Cy_DSADC_SetGainCorrection(base, gain->gainCorrection);
    /* Set offset correction */
    Cy_DSADC_SetOffsetCorrection(base, gain->offsetCorrection);
    /* Set CAP_CFG0 register */
    base->CAP_CFG0 = (_VAL2FLD(PACSS_DCHAN_CAP_CFG0_FCAP1, gain->modCapConfig.fCap1) | \
                      _VAL2FLD(PACSS_DCHAN_CAP_CFG0_FCAP2, gain->modCapConfig.fCap2) | \
                      _VAL2FLD(PACSS_DCHAN_CAP_CFG0_FCAP3, gain->modCapConfig.fCap3));
    /* Set CAP_CFG1 register */
    base->CAP_CFG1 = (_VAL2FLD(PACSS_DCHAN_CAP_CFG1_DACCAP, gain->modCapConfig.dacCap) | \
                      _VAL2FLD(PACSS_DCHAN_CAP_CFG1_IPCAP1, gain->modCapConfig.ipCap1) | \
                      _VAL2FLD(PACSS_DCHAN_CAP_CFG1_IPCAP2, gain->modCapConfig.ipCap2) | \
                      _VAL2FLD(PACSS_DCHAN_CAP_CFG1_IPCAP3, gain->modCapConfig.ipCap3));
    /* Set CAP_CFG2 register */
    base->CAP_CFG2 = (_VAL2FLD(PACSS_DCHAN_CAP_CFG2_SUMCAPIN, gain->modCapConfig.sumCapIn) | \
                      _VAL2FLD(PACSS_DCHAN_CAP_CFG2_SUMCAP1, gain->modCapConfig.sumCap1) | \
                      _VAL2FLD(PACSS_DCHAN_CAP_CFG2_SUMCAP2, gain->modCapConfig.sumCap2) | \
                      _VAL2FLD(PACSS_DCHAN_CAP_CFG2_SUMCAP3, gain->modCapConfig.sumCap3) | \
                      _VAL2FLD(PACSS_DCHAN_CAP_CFG2_SUMCAPFB, gain->modCapConfig.sumCapFb));
}

/** \cond INTERNAL */
/* Base shift value for calculating the max count */
#define CY_DSADC_MAX_COUNT_SHIFT_BASE (2UL)
/* Max signed long value for long long */
#define CY_DSADC_MAX_SIGNED_LONG_FOR_LONG_LONG (0x7FFFFFFFULL)

#define DECIMATION_RATIO_STAGE1 ((uint32_t)config->stage1DecimationRatio + 1UL)
#define DECIMATION_RATIO_STAGE2 ((uint32_t)config->stage2DecimationRatio + 1UL)
#define SHIFT_PLUS (CY_DSADC_MAX_COUNT_SHIFT_BASE + (uint32_t)config->gain->leftShift)
#define SHIFT_MINUS ((uint32_t)config->rightShift + (uint32_t)config->rateReducerRightShift + (uint32_t)config->ppRightShift)
/** \endcond */

/*******************************************************************************
* Function Name: Cy_DSADC_CalcMaxCount
****************************************************************************//**
*
* \brief
* Calculate the maximum count value of the conversion result from the passed DCHAN configuration.
* The calculated value is used to convert A/D conversion result in count to voltage.
*
* \param config
* The configuration for the DCHAN
*
* \return
* The maximum count value of the conversion result calculated from the passed DCHAN configuration.
* \note
* This function assumes sum of FIR tap coefficients equals 1.
* This means, FIRADJ term is omitted from the equation.
* When FIR is used, sum of FIR tap coefficients must be 1.
* Based equation is as below:
*
*        COmax = M x U x 2^(SL + N1 log2(DR1) - SR + N2 * log2(DR2) - SRR + FIRADJ - SPP)
*
*        = M x U x DR1^N1 x DR2^N2 x 2^(SL - SR - SRR + FIRADJ - SPP)
*
*        = 4 x U x DR1^N1 x DR2^2  x 2^(SL - SR - SRR + 0      - SPP)
*
*        = U x DR1^N1 x DR2^2 x 2^(2 + SL - SR - SRR - SPP)
*
*        = U x DR2^2 x DR1^N1 x 2^(2 + SL - SR - SRR - SPP)
*
*  Where:
*    M = Maximum modulator output. (In this driver, fixed to 4)
*
*    U = Moving-sum averaging.
*
*    SL = SHIFTL value ([0, 9])
*
*    N1 = 1st decimation filter order (3 for Sinc3, 4 for Sinc4)
*
*    DR1 = 1st decimation ratio ([2, 128])
*
*    N2 = 2nd decimation filter order (sinc2, fix 2)
*
*    DR2 = 2nd decimation ratio ([1, 32])
*
*    SR = DEC_SHIFTR value ([0, 15])
*
*    SRR = RR_SHIFTR value ([0, 15])
*
*    SPP = PP_SHIFTR value ([0, 15])
*
*    FIRADJ = log2(sum(FIRcoeff)) (assumes fix 0)
*
*******************************************************************************/
uint32_t Cy_DSADC_CalcMaxCount(const cy_stc_dsadc_dchan_config_t* config)
{
    /* Set U (moving sum averaging) as a default return value */
    uint32_t result = 1U;
    /* U - moving sum */
    if(CY_DSADC_AVERAGING_MODE_ACCUMULATE == config->averagingMode)
    {
        result = (1UL << (uint32_t)config->averagingSamples);
    }

    /* x DR2^2, maximum value of result = 4096
     * where DR2 - Decimation ratio 2
     */
    result = result * DECIMATION_RATIO_STAGE2 * DECIMATION_RATIO_STAGE2;
    /* DR1^3 or DR1^4, maximum value = 268435456
     * where DR1 - Decimation ratio 1
     */
    uint32_t drPowerOfN = DECIMATION_RATIO_STAGE1 * DECIMATION_RATIO_STAGE1 * DECIMATION_RATIO_STAGE1;
    if(CY_DSADC_DCHAN_DECIMATOR_SINC_MODE_SINC4 == config->sincMode)
    {
        drPowerOfN = drPowerOfN * DECIMATION_RATIO_STAGE1;
    }

    /* x DR1^3 or 4
     * where DR1 - Decimation ratio 1
     */
    uint64_t result64 = (uint64_t)result * drPowerOfN;
    /* x 2^(2 + SL - SR - SRR - SPP)
     * SL = SHIFTL value
     * SR = DEC_SHIFTR value
     * SRR = RR_SHIFTR value
     * SPP = PP_SHIFTR value
     */

    if(SHIFT_PLUS > SHIFT_MINUS)
    {
        result64 = result64 << (SHIFT_PLUS - SHIFT_MINUS);
    }
    else
    {
        result64 = result64 >> (SHIFT_MINUS - SHIFT_PLUS);
        /* Underflow case (result64 = 0) is handled at below. */
    }
    /* If over 32bit signed range or 0, given parameter is wrong. */
    if((CY_DSADC_MAX_SIGNED_LONG_FOR_LONG_LONG < result64) || (0ULL == result64))
    {
        result = 1U; /* To avoid zero division of application side. */
    }
    else
    {
        result = (uint32_t)result64;
    }
    return result;
}

/*******************************************************************************
* Function Name: Cy_DSADC_GetResult
****************************************************************************//**
*
* \brief
* Read the value in the result register of the specified channel.
* \param base
* The base address for the Digital Channel.
* \return
* Conversion result
*
*******************************************************************************/
int32_t Cy_DSADC_GetResult(const PACSS_DCHAN_Type* base)
{
    return (int32_t)(base->RESULT);
}

/*******************************************************************************
* Function Name: Cy_DSADC_GetAccumulatorResult
****************************************************************************//**
*
* \brief
* Read the value in the accumulated result register of the specified channel.
* \param base
* The base address for the Digital Channel.
* \return
* Accumulated result
*
*******************************************************************************/
int32_t Cy_DSADC_GetAccumulatorResult(const PACSS_DCHAN_Type* base)
{
  return (int32_t)base->ACC_RESULT;
}

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* (CY_IP_M0S8PACSS) */

/* [] END OF FILE */
