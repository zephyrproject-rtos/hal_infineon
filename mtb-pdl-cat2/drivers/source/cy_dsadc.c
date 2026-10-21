/***************************************************************************//**
* \file cy_dsadc.c
* \version 1.0
*
* \brief
* Provides an API implementation of the Delta-Sigma ADC driver
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

/*****************************************************************************/
/* Global private defines                                                    */
/*****************************************************************************/

/** \cond Internal */
/* Magic key to unlock protected registers */
#define CY_DSADC_PROT_MAGIC_KEY (0xF08169E7UL)
/* Magic key to lock protected registers */
#define CY_DSADC_PROT_LOCK_KEY (0x00000000UL)
/* Channel validation */
#define CY_CHANNEL_VALID(channel) ((1U) >= (channel))
/* Volts to mVolts */
#define CY_DSADC_VOLTS_TO_MV  (1000.0F)
/* Volts to uVolts */
#define CY_DSADC_VOLTS_TO_UV  (1000000.0F)

/* Sequencer must be enabled 1000 us before enabling any analog channels to
 * allow the reference voltages, in particular HPBGR, to settle.
 */
#define CY_DSADC_REFERENCE_DELAY_US               (1000U)
/* Analog Channel must be enabled for 3 us to allow the analog reference (AREF)
 * to settle before starting conversions
 */
#define CY_DSADC_ACHAN_DELAY_US                   (3U)

/* Modulate BIPOLAR (NPN/PNP) units */
#define CY_DSADC_TEMPERATURE_UNIT_MODE_BIPOLAR (1U)

/* Shift to scale the squared term */
#define CY_DSADC_TEMPERATURE_SQUARED_TERM_SHIFT (34U)
/* Shift to scale the linear term */
#define CY_DSADC_TEMPERATURE_LINEAR_TERM_SHIFT (9U)
/* Shift to scale the offset term */
#define CY_DSADC_TEMPERATURE_OFFSET_TERM_SHIFT (14U)

/* Shift to scale the current ratio one */
#define CY_DSADC_TEMPERATURE_CURRENT_RATIO_ONE_SHIFT (8U)
/* Shift to scale the current ratio unit */
#define CY_DSADC_TEMPERATURE_CURRENT_RATIO_UNIT_SHIFT (4U)

/* Slope term of linear approximation 0.0534*2^20 * -1 */
#define CY_DSADC_TEMPERATURE_NORMALIZATION_A      (55993U)
#define CY_DSADC_TEMPERATURE_NORMALIZATION_A_SIGN (-1)
/* TEMPERATURE_NORMALIZATION_A ratio(20) + current ratio one shift + current ratio unit shift + temp ratio */
#define CY_DSADC_TEMPERATURE_COEFFICIENT_RATIO ((20U + (CY_DSADC_TEMPERATURE_CURRENT_RATIO_ONE_SHIFT + \
                                                      CY_DSADC_TEMPERATURE_CURRENT_RATIO_UNIT_SHIFT)) - 1U)
/* Offset term of linear approximation 0.4804*2^CY_DSADC_TEMPERATURE_COEFFICIENT_RATIO */
#define CY_DSADC_TEMPERATURE_NORMALIZATION_B (1031651144)

/* Counts of voltage on 5Kohm register when IREF current 1x:
* ((9.6uA * 5Kohm / 1.2V) * 2^(29 - 1)) = 10737418
* Minimum counts of voltage when IREF current x1:(counts*(1-40%))
*/
#define CY_DSADC_TEMPERATURE_CURRENT_IREF_1X_COUNTS_MIN (6442450)
/* Maximum counts of voltage when IREF current x1:(counts*(1+40%)) */
#define CY_DSADC_TEMPERATURE_CURRENT_IREF_1X_COUNTS_MAX (15032385)
/* Counts of voltage on 5Kohm register when IREF current 9x:
* ((9.6uA * 9*5Kohm / 1.2V) * 2^(29 - 1)) = 96636764
* Minimum counts of voltage when IREF current x9:(counts*(1-40%))
*/
#define CY_DSADC_TEMPERATURE_CURRENT_IREF_9X_COUNTS_MIN (57982058)
/* Maximum counts of voltage when IREF current x9:(counts * (1 + 40%)) */
#define CY_DSADC_TEMPERATURE_CURRENT_IREF_9X_COUNTS_MAX (135291469)
/* Check if the counts of voltage when IREF current x1 is not out of range */
#define IS_OUT_OF_RANGE_1X(value)   (((value) > CY_DSADC_TEMPERATURE_CURRENT_IREF_1X_COUNTS_MIN) && \
                                     ((value) < CY_DSADC_TEMPERATURE_CURRENT_IREF_1X_COUNTS_MAX))
/* Check if the counts of voltage when IREF current x9 is not out of range */
#define IS_OUT_OF_RANGE_9X(value)   (((value) > CY_DSADC_TEMPERATURE_CURRENT_IREF_9X_COUNTS_MIN) && \
                                     ((value) < CY_DSADC_TEMPERATURE_CURRENT_IREF_9X_COUNTS_MAX))

/* Maximum ratio(10.0*2^(CY_DSADC_TEMPERATURE_CURRENT_RATIO_ONE_SHIFT+CY_DSADC_TEMPERATURE_CURRENT_RATIO_UNIT_SHIFT)) */
#define CY_DSADC_TEMPERATURE_RATIO_MAX (40960U)
/* Minimum ratio(8.0*2^(CY_DSADC_TEMPERATURE_CURRENT_RATIO_ONE_SHIFT+CY_DSADC_TEMPERATURE_CURRENT_RATIO_UNIT_SHIFT)) */
#define CY_DSADC_TEMPERATURE_RATIO_MIN (32768U)
/* Check if the RATION is not out of range */
#define IS_OUT_OF_RANGE_RATIO(value)   (((value) > CY_DSADC_TEMPERATURE_RATIO_MIN) && \
                                        ((value) < CY_DSADC_TEMPERATURE_RATIO_MAX))
/* Maximum VBE result(29 bit signed: 2^28) */
#define CY_DSADC_TEMPERATURE_DVBE_MAX (268435456)
/* Minimum VBE result(29 bit signed: -2^28) */
#define CY_DSADC_TEMPERATURE_DVBE_MIN (-268435456)
/* Check if the VBE is not out of range */
#define IS_OUT_OF_RANGE_VBE(value)   (((value) > (int32_t)CY_DSADC_TEMPERATURE_DVBE_MIN) && \
                                      ((value) < (int32_t)CY_DSADC_TEMPERATURE_DVBE_MAX))
/** \endcond */

/*==================[internal function definitions]===========================*/

/*******************************************************************************
* Function Name: Cy_DSADC_Agc_ConfigureGainLevel
****************************************************************************//**
*
* \brief
* Configure the Gain Level in Memory, given the input configuration.
* \param base
* The base address of the Gain level configuration structure MMIO_GAINLVL_STRUCT.
* \param gainLevel
* Gain Level configuration settings. See \ref cy_stc_dsadc_gain_level_config_t
*
*******************************************************************************/
static void Cy_DSADC_Agc_ConfigureGainLevel(PACSS_MMIO_GAINLVL_STRUCT_Type* base,
                                            const cy_stc_dsadc_gain_level_config_t* gainLevel)
{
    /* Set GAIN_CFG0 register */
    base->GAIN_CFG0 = (_VAL2FLD(PACSS_MMIO_GAINLVL_STRUCT_GAIN_CFG0_PGA_GAIN, (uint32_t)gainLevel->pgaGain) | \
                       _VAL2FLD(PACSS_MMIO_GAINLVL_STRUCT_GAIN_CFG0_SHIFT1, gainLevel->leftShift) | \
                       _VAL2FLD(PACSS_MMIO_GAINLVL_STRUCT_GAIN_CFG0_DACCAP, gainLevel->modCapConfig.dacCap) | \
                       _VAL2FLD(PACSS_MMIO_GAINLVL_STRUCT_GAIN_CFG0_IPCAP1, gainLevel->modCapConfig.ipCap1));

    /* Set GAIN_CFG1 register */
    base->GAIN_CFG1 = (_VAL2FLD(PACSS_DCHAN_CAP_CFG2_SUMCAPIN, gainLevel->modCapConfig.sumCapIn) | \
                       _VAL2FLD(PACSS_DCHAN_CAP_CFG2_SUMCAP1, gainLevel->modCapConfig.sumCap1) | \
                       _VAL2FLD(PACSS_DCHAN_CAP_CFG2_SUMCAP2, gainLevel->modCapConfig.sumCap2) | \
                       _VAL2FLD(PACSS_DCHAN_CAP_CFG2_SUMCAP3, gainLevel->modCapConfig.sumCap3) | \
                       _VAL2FLD(PACSS_DCHAN_CAP_CFG2_SUMCAPFB, gainLevel->modCapConfig.sumCapFb));

    /* Set offset correction */
    base->OFST_COR = (uint32_t)((uint16_t)gainLevel->offsetCorrection);
    /* Set gain correction */
    base->GAIN_COR = (uint32_t)gainLevel->gainCorrection;
}

/*******************************************************************************
* Function Name: Cy_DSADC_Agc_ConfigGainLevelAll
****************************************************************************//**
*
* \brief
* Configure the all Gain Level in Memory, given the input configuration.
* \param base
* The pointer to the MMIO instance of the PACSS.
* \param config
* Configuration options for the AGC. See \ref cy_stc_dsadc_agc_config_t
*
*******************************************************************************/
static void Cy_DSADC_Agc_ConfigGainLevelAll(PACSS_MMIO_Type* base,
                                            const cy_stc_dsadc_agc_config_t* config)
{
    /* Configure gain level parameters */
    for(uint32_t index = 0U; index < (uint32_t)config->numGainLevels; index++)
    {
        Cy_DSADC_Agc_ConfigureGainLevel(&(base->GAINLVL_STRUCT[index]), &(config->gainLevels[index]));
    }
}

/*****************************************************************************/
/* API                                                                       */
/*****************************************************************************/

/*******************************************************************************
* Function Name: Cy_DSADC_LockProtReg
****************************************************************************//**
*
* \brief
* Lock the protected registers.
* \param base
* The pointer to the MMIO instance of the PACSS.
* \warning
* There is no protection against locking registers from the threads or interrupts.
* Users should take care of critical sections if needed.
* \note Used to lock trim registers.
* \funcusage
* \snippet dsadc_snippet.c snippet_Cy_DSADC_LockUnlockRegisters
*
*******************************************************************************/
void Cy_DSADC_LockProtReg(PACSS_MMIO_Type* base)
{
    /* Lock protected register */
    base->REG_PROT = CY_DSADC_PROT_LOCK_KEY;
}

/*******************************************************************************
* Function Name: Cy_DSADC_UnlockProtReg
****************************************************************************//**
*
* \brief
* Unlock the protected registers.
* \param base
* The pointer to the MMIO instance of the PACSS.
* \note Used to unlock trim registers.
* \funcusage
* \snippet dsadc_snippet.c snippet_Cy_DSADC_LockUnlockRegisters
*
*******************************************************************************/
void Cy_DSADC_UnlockProtReg(PACSS_MMIO_Type* base)
{
    /* Unlock protected register */
    base->REG_PROT = CY_DSADC_PROT_MAGIC_KEY;
}

/*******************************************************************************
* Function Name: Cy_DSADC_GetLockStatus
****************************************************************************//**
*
* \brief
* Get the status of the protection register that is needed to be accessed to unlock Lock Protected Registers.
* \param base
* The pointer to the MMIO instance of the PACSS.
* \return
* Status of the protection register.
* - true  : if locked.
* - false : if unlocked.
* \note Used to check if trim registers is locked or unlocked.
* \funcusage
* \snippet dsadc_snippet.c snippet_Cy_DSADC_LockUnlockRegisters
*
*******************************************************************************/
bool Cy_DSADC_GetLockStatus(const PACSS_MMIO_Type* base)
{
    /* Get the protection register status */
    return (CY_DSADC_PROT_MAGIC_KEY != _FLD2VAL(PACSS_MMIO_REG_PROT_MAGIC, base->REG_PROT));
}


/*******************************************************************************
* Function Name: Cy_DSADC_EnableSequencer
****************************************************************************//**
*
* \brief
* Enable the ADC Sequencer and AREF.
* \param base
* The pointer to the MMIO instance of the PACSS.
*
*******************************************************************************/
void Cy_DSADC_EnableSequencer(PACSS_MMIO_Type* base)
{
    /* Disable low power mode */
    base->AREF_CTL = 0U;
    /* Enable AREF */
    base->PACSS_CTL |= PACSS_MMIO_PACSS_CTL_AREF_EN_Msk;
    /* Enable LDO */
    base->PACSS_CTL |= PACSS_MMIO_PACSS_CTL_LDO_EN_Msk;
    /* Enable PACSS */
    base->PACSS_CTL |= PACSS_MMIO_PACSS_CTL_ENABLE_Msk;
}

/*******************************************************************************
* Function Name: Cy_DSADC_DisableSequencer
****************************************************************************//**
*
* \brief
* Disable the ADC Sequencer.
* \param base
* The pointer to the MMIO instance of the PACSS.
*
*******************************************************************************/
void Cy_DSADC_DisableSequencer(PACSS_MMIO_Type* base)
{
    /* Disable sequencer */
    base->PACSS_CTL &= ~PACSS_MMIO_PACSS_CTL_ENABLE_Msk;
}

/*******************************************************************************
* Function Name: Cy_DSADC_GetSequencerBusy
****************************************************************************//**
*
* \brief
* Get the sequencer status.
* \param base
* The pointer to the MMIO instance of the PACSS.
* \param channel
* Analog channel index. Valid inputs are between 0 and 1.
* \return
* Sequencer busy. True if sequencer busy, False - otherwise.
*
*******************************************************************************/
bool Cy_DSADC_GetSequencerBusy(const PACSS_MMIO_Type* base, uint8_t channel)
{
    CY_ASSERT_L2(CY_CHANNEL_VALID(channel));

    return (0U < (base->STATUS0 & ((uint32_t)1U << (uint32_t)channel))) ? true : false;
}

/*******************************************************************************
* Function Name: Cy_DSADC_EnableHPBGR
****************************************************************************//**
*
* \brief
* Configure and enable the High Precision Band Gap Reference (HPBGR).
* \param base
* The pointer to the MMIO instance of the PACSS.
* \param config
* Configuration options for the HPBGR. See \ref cy_stc_dsadc_hpbgr_config_t.
*
*******************************************************************************/
void Cy_DSADC_EnableHPBGR(PACSS_MMIO_Type* base, const cy_stc_dsadc_hpbgr_config_t* config)
{
    base->HPBGR_CTL = (_VAL2FLD(PACSS_MMIO_HPBGR_CTL_CHOP_CLK_SEL, config->hpbgrChoppingPhase) | \
                       _VAL2FLD(PACSS_MMIO_HPBGR_CTL_HPBGR_FCHOP, config->hpbgrChoppingDivider) | \
                       _VAL2FLD(PACSS_MMIO_HPBGR_CTL_SEL_PHC, config->enableExternalCapacitor) | \
                       PACSS_MMIO_HPBGR_CTL_CHOP_EN_Msk);
    /* Enable HPBGR */
    base->PACSS_CTL |= PACSS_MMIO_PACSS_CTL_HPBGR_EN_Msk;
}

/*******************************************************************************
* Function Name: Cy_DSADC_DisableHPBGR
****************************************************************************//**
*
* \brief
* Disable the High Precision Band Gap Reference (HPBGR).
* \param base
* The pointer to the MMIO instance of the PACSS.
*
*******************************************************************************/
void Cy_DSADC_DisableHPBGR(PACSS_MMIO_Type* base)
{
    /* Disable HPBGR (High Precision Band Gap) */
    base->PACSS_CTL &= ~PACSS_MMIO_PACSS_CTL_HPBGR_EN_Msk;
}

/*******************************************************************************
* Function Name: Cy_DSADC_SetGroundReference
****************************************************************************//**
*
* \brief
* Set the ground connection for the high voltage divider.
* \param base
* The pointer to the MMIO instance of the PACSS.
* \param select
* Ground Reference Selection. see \ref cy_en_dsadc_ground_reference_t
*
*******************************************************************************/
void Cy_DSADC_SetGroundReference(PACSS_MMIO_Type* base, cy_en_dsadc_ground_reference_t select)
{
    /* Set ground reference */
    CY_REG32_CLR_SET(base->PACSS_CTL, PACSS_MMIO_PACSS_CTL_HVDIVG_MUX_SEL, (uint32_t)select);
}

/*******************************************************************************
* Function Name: Cy_DSADC_GetThresholdCount
****************************************************************************//**
*
* \brief
* Get the status counter value that indicates how many time low or high threshold is crossed.
* \param base
* The pointer to the MMIO instance of the PACSS.
* \param select
* Select to get low ot high threshold count value. See \ref cy_en_dsadc_threshold_select_t
* \return
* Threshold count status.
*
*******************************************************************************/
uint16_t Cy_DSADC_GetThresholdCount(const PACSS_MMIO_Type* base, cy_en_dsadc_threshold_select_t select)
{
    uint16_t count = 0U;
    if(select == CY_DSADC_LOW_THRESHHOLD_CNTR)
    {
        /* Get low threshold count */
        count = ((uint16_t)_FLD2VAL(PACSS_MMIO_STATUS1_LO_THRESH_CNTR, base->STATUS1));
    }
    else
    {
        /* Get high threshold count */
        count = ((uint16_t)_FLD2VAL(PACSS_MMIO_STATUS1_HI_THRESH_CNTR, base->STATUS1));
    }

    return count;
}

/*******************************************************************************
* Function Name: Cy_DSADC_SetChoppingPosition
****************************************************************************//**
*
* \brief
* Set the chopping position.
* \param base
* The pointer to the MMIO instance of the PACSS.
* \param select
* Chopping position select CY_DSADC_HPBGR_CHOPPING_PHASE_NORMAL or CY_DSADC_HPBGR_CHOPPING_PHASE_REVERSE.
* See \ref cy_en_dsadc_hpbgr_chopping_phase_t
* \note
* Only applies when CHOP_EN=0. Use this function before \ref Cy_DSADC_EnableHPBGR().
*
*******************************************************************************/
void Cy_DSADC_SetChoppingPosition(PACSS_MMIO_Type* base, cy_en_dsadc_hpbgr_chopping_phase_t select)
{
    /* Set the chopping position */
    base->HPBGR_CTL |= _BOOL2FLD(PACSS_MMIO_HPBGR_CTL_CHOP_POS, (uint32_t)select);
}

/*******************************************************************************
* Function Name: Cy_DSADC_GetChoppingPosition
****************************************************************************//**
*
* \brief
* Get the chopping position.
* \param base
* The pointer to the MMIO instance of the PACSS.
* \return
* Chopping position CY_DSADC_HPBGR_CHOPPING_PHASE_NORMAL or CY_DSADC_HPBGR_CHOPPING_PHASE_REVERSE.
* See \ref cy_en_dsadc_hpbgr_chopping_phase_t
*
*******************************************************************************/
cy_en_dsadc_hpbgr_chopping_phase_t Cy_DSADC_GetChoppingPosition(const PACSS_MMIO_Type* base)
{
    /* Get the chopping position */
    CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 10.8', 'The field values match the enumeration.');
    return ((cy_en_dsadc_hpbgr_chopping_phase_t)_FLD2VAL(PACSS_MMIO_HPBGR_CTL_CHOP_POS, base->HPBGR_CTL));
}

/*******************************************************************************
* Function Name: Cy_DSADC_AgcInit
****************************************************************************//**
*
* \brief
* Configure the Automatic Gain Correction (AGC).
* \param base
* The pointer to the MMIO instance of the PACSS.
* \param config
* Configuration options for the AGC. See \ref cy_stc_dsadc_agc_config_t
*
*******************************************************************************/
void Cy_DSADC_AgcInit(PACSS_MMIO_Type* base, const cy_stc_dsadc_agc_config_t* config)
{
    base->AGC_CTL0 = (_VAL2FLD(PACSS_MMIO_AGC_CTL0_LO_THRESH, config->lowerThreshold) | \
                      _VAL2FLD(PACSS_MMIO_AGC_CTL0_HI_THRESH, config->upperThreshold) | \
                      _VAL2FLD(PACSS_MMIO_AGC_CTL0_MIN_LVL, config->minGainLevel) | \
                      _VAL2FLD(PACSS_MMIO_AGC_CTL0_INIT_LVL, config->initialGainLevel) | \
                      _VAL2FLD(PACSS_MMIO_AGC_CTL0_MAX_LVL, config->maxGainLevel) | \
                      _VAL2FLD(PACSS_MMIO_AGC_CTL0_FAST_DEC_SCLR, (uint32_t)config->decimationScaler));

    base->AGC_CTL1 = (_VAL2FLD(PACSS_MMIO_AGC_CTL1_FAST_DR, config->decimationRatio) | \
                      _VAL2FLD(PACSS_MMIO_AGC_CTL1_AAF_BLANK_MODE, (uint32_t)config->aafBlankMode) | \
                      _VAL2FLD(PACSS_MMIO_AGC_CTL1_AAF_BLANK_CNT, config->aafBlankCount) | \
                      _VAL2FLD(PACSS_MMIO_AGC_CTL1_DEC_BLANK_CNT, config->decimatorBlankCount) | \
                      _VAL2FLD(PACSS_MMIO_AGC_CTL1_SCALER_BLANK_CNT, config->gainScalerBlankCount));

    base->AGC_CTL2 = (_VAL2FLD(PACSS_MMIO_AGC_CTL2_LO_THRESH_FLT_MODE, (uint32_t)config->lowerFilterMode) | \
                      _VAL2FLD(PACSS_MMIO_AGC_CTL2_LO_THRESH_CNT, config->lowerFilterCount));

    base->AGC_CTL3 = (_VAL2FLD(PACSS_MMIO_AGC_CTL3_HI_THRESH_FLT_MODE, (uint32_t)config->upperFilterMode) | \
                      _VAL2FLD(PACSS_MMIO_AGC_CTL3_HI_THRESH_CNT, config->upperFilterCount));
    /* Set all gain level */
    Cy_DSADC_Agc_ConfigGainLevelAll(base, config);
}

/*******************************************************************************
* Function Name: Cy_DSADC_AgcEnable
****************************************************************************//**
*
* \brief
* Enable Automatic Gain Correction (AGC).
* \param base
* The pointer to the MMIO instance of the PACSS.
*
*******************************************************************************/
void Cy_DSADC_AgcEnable(PACSS_MMIO_Type* base)
{
    /* Enable AGC */
    base->PACSS_CTL |= PACSS_MMIO_PACSS_CTL_AGC_EN_Msk;
}

/*******************************************************************************
* Function Name: Cy_DSADC_AgcDisable
****************************************************************************//**
*
* \brief
* Disable Automatic Gain Correction (AGC).
* \param base
* The pointer to the MMIO instance of the PACSS.
*
*******************************************************************************/
void Cy_DSADC_AgcDisable(PACSS_MMIO_Type* base)
{
    /* Disable AGC */
    base->PACSS_CTL &= ~PACSS_MMIO_PACSS_CTL_AGC_EN_Msk;
}

/*******************************************************************************
* Function Name: Cy_DSADC_AgcIsEnabled
****************************************************************************//**
*
* \brief
* Returns the AGC status register value.
* \param base
* The pointer to the MMIO instance of the PACSS.
* \return
* Current AGC status.
* - true  : AGC enabled.
* - false : AGC disabled.
*
*******************************************************************************/
bool Cy_DSADC_AgcIsEnabled(const PACSS_MMIO_Type* base)
{
    /* Get current AGC status */
    return (_FLD2BOOL(PACSS_MMIO_PACSS_CTL_AGC_EN, base->PACSS_CTL));
}

/*******************************************************************************
* Function Name: Cy_DSADC_AgcSetGainCorrection
****************************************************************************//**
*
* \brief
* Set the gain correction factor for the specified AGC gain level.
* \param base
* The pointer to the MMIO instance of the PACSS.
* \param index
* AGC gain level. Valid inputs are between 0 and 9.
* \param gain
* Gain correction factor.
*
*******************************************************************************/
void Cy_DSADC_AgcSetGainCorrection(PACSS_MMIO_Type* base, uint8_t index, uint16_t gain)
{
    /* Set gain correction */
    base->GAINLVL_STRUCT[index].GAIN_COR = (uint32_t)gain;
}

/*******************************************************************************
* Function Name: Cy_DSADC_AgcSetOffsetCorrection
****************************************************************************//**
*
* \brief
* Set the offset correction factor for the specified AGC gain level.
* \param base
* The pointer to the MMIO instance of the PACSS.
* \param index
* AGC gain level. Valid inputs are between 0 and 9.
* \param offset
* Offset correction factor. Valid inputs are between -32768 and 32767.
*
*******************************************************************************/
void Cy_DSADC_AgcSetOffsetCorrection(PACSS_MMIO_Type* base, uint8_t index, int16_t offset)
{
    /* Set offset correction */
    base->GAINLVL_STRUCT[index].OFST_COR = (uint32_t)((uint16_t)offset);
}

/*******************************************************************************
* Function Name: Cy_DSADC_AgcGetGainLevel
****************************************************************************//**
*
* \brief
* Get current gain level.
* \param base
* The pointer to the MMIO instance of the PACSS.
* \return
* Current gain level.
*
*******************************************************************************/
uint8_t Cy_DSADC_AgcGetGainLevel(const PACSS_MMIO_Type* base)
{
    /* Get current gain level */
    return (uint8_t)_FLD2VAL(PACSS_MMIO_STATUS0_AGC_CURR_GLVL, base->STATUS0);
}

/*******************************************************************************
* Function Name: Cy_DSADC_AgcGetFastDecimatorResult
****************************************************************************//**
*
* \brief
* Get the AGC Fast Decimator Result.
* \param base
* The pointer to the MMIO instance of the PACSS.
* \return
* AGC Fast Decimator Result.
*
*******************************************************************************/
uint16_t Cy_DSADC_AgcGetFastDecimatorResult(const PACSS_MMIO_Type* base)
{
    /* Get fast decimator result */
    return (uint16_t)_FLD2VAL(PACSS_MMIO_STATUS0_AGC_FAST_DEC_RESULT, base->STATUS0);
}

/*******************************************************************************
* Function Name: Cy_DSADC_Init
****************************************************************************//**
*
* \brief
* Full Init of the sigma-delta AGC
* \param base
* The base address for the PACSS.
* \param config
* Configuration options for the PACSS. See \ref cy_stc_dsadc_config_t.
*
* \note Init enable sequencer and internal HPBGR, wait for settle
* then enable all ACHANs, wait to stabilize analog part
* then enable all DCHANs and configure AGC if required.
*
*******************************************************************************/
void Cy_DSADC_Init(const PACSS_Type * base, cy_stc_dsadc_config_t* config)
{
    CY_ASSERT_L2(NULL != base);
    CY_ASSERT_L2(NULL != config);
    uint32_t iter = 0UL;

    /* Configure the PACSS */
    /* In order to enable any Analog Channel the Sequencer must be enabled first
     */
    Cy_DSADC_EnableSequencer((PACSS_MMIO_Type*) &base->MMIO);
    if(NULL != config->HPBGR)
    {
        Cy_DSADC_EnableHPBGR((PACSS_MMIO_Type*) &base->MMIO, config->HPBGR);
    }

    /* Sequencer must be enabled 1000us before enabling any analog channels to
     * allow the reference currents to settle
     */
    Cy_SysLib_DelayUs(CY_DSADC_REFERENCE_DELAY_US);

    /* Analog Channels */
    for (iter = 0UL; iter < PACSS_ACH_NR; iter ++)
    {
        if (NULL != config->ACHAN[iter])
        {
            Cy_DSADC_InitAchan(((PACSS_ACHAN_Type*) &base->ACHAN[iter]), config->ACHAN[iter]);
            if(NULL != config->ACHAN_CHOPPING[iter])
            {
                Cy_DSADC_InitAchanChannelChopping(((PACSS_ACHAN_Type*) &base->ACHAN[iter]), config->ACHAN_CHOPPING[iter]);
            }
            Cy_DSADC_EnableAchan(((PACSS_ACHAN_Type*) &base->ACHAN[iter]));
        }
    }

    /* Analog channel must be enabled for 3us before starting conversions */
    Cy_SysLib_DelayUs(CY_DSADC_ACHAN_DELAY_US);

    /* Digital Channels */
    for (iter = 0UL; iter < PACSS_DCH_NR; iter ++)
    {
        if(NULL != config->DCHAN[iter])
        {
            Cy_DSADC_InitDchan((PACSS_DCHAN_Type*) &base->DCHAN[iter], config->DCHAN[iter]);
            Cy_DSADC_EnableDchan((PACSS_DCHAN_Type*) &base->DCHAN[iter]);
        }
    }
    /* AGC */
    if (NULL != config->AGC)
    {
        Cy_DSADC_AgcInit((PACSS_MMIO_Type*) &base->MMIO, config->AGC);
        Cy_DSADC_AgcEnable((PACSS_MMIO_Type*) &base->MMIO);
    }
}

/*******************************************************************************
* Function Name: Cy_DSADC_Deinit
****************************************************************************//**
*
* \brief
* Full DeInit of the sigma-delta AGC
* \param base
* The base address for the PACSS.
*
* \note DeInit in opposite order to the Init \see Cy_DSADC_Init
*
*******************************************************************************/
void Cy_DSADC_Deinit(const PACSS_Type * base)
{
    uint32_t iter = 0UL;

    Cy_DSADC_AgcDisable((PACSS_MMIO_Type*) &base->MMIO);

    for (iter = 0UL; iter < PACSS_DCH_NR; iter++)
    {
        Cy_DSADC_DisableDchan((PACSS_DCHAN_Type*) &base->DCHAN[iter]);
    }

    for (iter = 0UL; iter < PACSS_ACH_NR; iter++)
    {
        Cy_DSADC_DisableAchan((PACSS_ACHAN_Type*) &base->ACHAN[iter]);
    }

    Cy_DSADC_DisableHPBGR((PACSS_MMIO_Type*) &base->MMIO);
    Cy_DSADC_DisableSequencer((PACSS_MMIO_Type*) &base->MMIO);
}

/*******************************************************************************
* Function Name: Cy_DSADC_Enable
****************************************************************************//**
*
* \brief
* Full Enable configured parts of the sigma-delta AGC
* \param base
* The base address for the PACSS.
* \param config
* Configuration options for the PACSS. See \ref cy_stc_dsadc_config_t.
*
* \note Sequencer and internal reference will be enabled always.
*
* \note Only those parts will be enabled for which
* pointers are not NULL in the config
*
*******************************************************************************/
void Cy_DSADC_Enable(const PACSS_Type * base, cy_stc_dsadc_config_t* config)
{
    CY_ASSERT_L2(NULL != base);
    uint32_t iter = 0UL;

    /* In order to enable any Analog Channel the Sequencer must be enabled first */
    Cy_DSADC_EnableSequencer((PACSS_MMIO_Type*) &base->MMIO);
    Cy_DSADC_EnableHPBGR((PACSS_MMIO_Type*) &base->MMIO, config->HPBGR);

    /* Sequencer must be enabled 1000us before enabling any analog channels to
     * allow the reference currents to settle
     */
    Cy_SysLib_DelayUs(CY_DSADC_REFERENCE_DELAY_US);

    /* Analog Channels */
    for (iter = 0UL; iter < PACSS_ACH_NR; iter ++)
    {
        if (NULL != config->ACHAN[iter])
        {
            Cy_DSADC_EnableAchan(((PACSS_ACHAN_Type*) &base->ACHAN[iter]));
        }
    }

    /* Analog channel must be enabled for 3us before starting conversions */
    Cy_SysLib_DelayUs(CY_DSADC_ACHAN_DELAY_US);

    /* Digital Channels */
    for (iter = 0UL; iter < PACSS_DCH_NR; iter ++)
    {
        if(NULL != config->DCHAN[iter])
        {
            Cy_DSADC_EnableDchan((PACSS_DCHAN_Type*) &base->DCHAN[iter]);
        }
    }
    /* AGC */
    if (NULL != config->AGC)
    {
        Cy_DSADC_AgcEnable((PACSS_MMIO_Type*) &base->MMIO);
    }
}

/*******************************************************************************
* Function Name: Cy_DSADC_Disable
****************************************************************************//**
*
* \brief
* Full Disable all parts of the sigma-delta ADC
* \param base
* The base address for the PACSS.
*
*******************************************************************************/
void Cy_DSADC_Disable(const PACSS_Type * base)
{
    CY_ASSERT_L2(NULL != base);
    Cy_DSADC_Deinit(base);
}

/*******************************************************************************
* Function Name: Cy_DSADC_StartConvert
****************************************************************************//**
*
* \brief
* Start convert selected source.
* \param base
* The base address for the PACSS.
* \param source
* Selected source to start convert \see cy_en_dsadc_convert_source_t
*
*******************************************************************************/
void Cy_DSADC_StartConvert(PACSS_Type* base, cy_en_dsadc_convert_source_t source)
{
    CY_ASSERT_L2(NULL != base);
    switch(source)
    {
        case CY_DSADC_ACHAN0:
        {
            Cy_DSADC_StartConversionAchan(&(base->ACHAN[0]));
            break;
        }

        case CY_DSADC_ACHAN1:
        {
            Cy_DSADC_StartConversionAchan(&(base->ACHAN[1]));
            break;
        }

        case CY_DSADC_ALL_PRIMARY:
        {
            Cy_DSADC_StartConversionAll(&(base->MMIO));
            break;
        }

        case CY_DSADC_ALL_SECONDARY:
        {
            Cy_DSADC_PendSecondConvAll(&(base->MMIO));
            break;
        }

        default:
        {
            /* Unknown state */
            break;
        }
    }
}

/*******************************************************************************
* Function Name: Cy_DSADC_StopConvert
****************************************************************************//**
*
* \brief
* Stop convert selected source.
* \param base
* The base address for the Digital Channel.
* \note
* One more measurements after call this function may occurs before full stop.
*
*******************************************************************************/
void Cy_DSADC_StopConvert(PACSS_DCHAN_Type* base)
{
    CY_ASSERT_L2(NULL != base);
    Cy_DSADC_SetSampleMode(base, CY_DSADC_DCHAN_SAMPLE_MODE_SINGLE_SHOT);
}

/*******************************************************************************
* Function Name: Cy_DSADC_CountsTo_Volts
****************************************************************************//**
*
* \brief
* Converts the input from raw DSADC counts to Volts.
* \param counts
* Conversion result from \ref Cy_DSADC_GetResult().
* \param vref
* Reference voltage in Volts.
* \param analogGain
* Analog gain value for the Digital Channel.
* \param dchan_config
* Configuration options for the Digital Channel. See \ref cy_stc_dsadc_dchan_config_t
* \return
* Result in volts.
* \funcusage
* \snippet dsadc_snippet.c snippet_Cy_DSADC_CountsTo_Volts
*
*******************************************************************************/
float32_t Cy_DSADC_CountsTo_Volts(int32_t counts,
                                  float32_t vref,
                                  float32_t analogGain,
                                  cy_stc_dsadc_dchan_config_t* dchan_config)
{
    CY_ASSERT_L2(NULL != dchan_config);
    CY_ASSERT_L2(0.0F != analogGain);

    float32_t result_Volts = 0.0F;
    uint32_t maxCounts = 0UL;

    maxCounts = Cy_DSADC_CalcMaxCount(dchan_config);
    result_Volts = (((float32_t)counts * vref) / ((float32_t)maxCounts * analogGain));

    return result_Volts;
}

/*******************************************************************************
* Function Name: Cy_DSADC_CountsTo_mVolts
****************************************************************************//**
*
* \brief
* Converts the input from raw DSADC counts to millivolts.
* \param counts
* Conversion result from \ref Cy_DSADC_GetResult().
* \param vref
* Reference voltage in Volts.
* \param analogGain
* Analog gain value for the Digital Channel.
* \param dchan_config
* Configuration options for the Digital Channel. See \ref cy_stc_dsadc_dchan_config_t
* \return
* Result in millivolts.
* \funcusage
* \snippet dsadc_snippet.c snippet_Cy_DSADC_CountsTo_mVolts
*
*******************************************************************************/
float32_t Cy_DSADC_CountsTo_mVolts(int32_t counts,
                                   float32_t vref,
                                   float32_t analogGain,
                                   cy_stc_dsadc_dchan_config_t* dchan_config)
{
    CY_ASSERT_L2(NULL != dchan_config);
    CY_ASSERT_L2(0.0F != analogGain);

    float32_t result_mVolts = 0.0F;
    uint32_t maxCounts = 0UL;

    maxCounts = Cy_DSADC_CalcMaxCount(dchan_config);
    result_mVolts = (((float32_t)counts * vref * CY_DSADC_VOLTS_TO_MV) / ((float32_t)maxCounts * analogGain));

    return result_mVolts;
}

/*******************************************************************************
* Function Name: Cy_DSADC_CountsTo_uVolts
****************************************************************************//**
*
* \brief
* Converts the input from raw DSADC counts to microvolts.
* \param counts
* Conversion result from \ref Cy_DSADC_GetResult().
* \param vref
* Reference voltage in Volts.
* \param analogGain
* Analog gain value for the Digital Channel.
* \param dchan_config
* Configuration options for the Digital Channel. See \ref cy_stc_dsadc_dchan_config_t
* \return
* Result in microvolts.
* \funcusage
* \snippet dsadc_snippet.c snippet_Cy_DSADC_CountsTo_uVolts
*
*******************************************************************************/
float32_t Cy_DSADC_CountsTo_uVolts(int32_t counts,
                                   float32_t vref,
                                   float32_t analogGain,
                                   cy_stc_dsadc_dchan_config_t* dchan_config)
{
    CY_ASSERT_L2(NULL != dchan_config);
    CY_ASSERT_L2(0.0F != analogGain);

    float32_t result_uVolts = 0.0F;
    uint32_t maxCounts = 0UL;

    maxCounts = Cy_DSADC_CalcMaxCount(dchan_config);
    result_uVolts = (((float32_t)counts * vref * CY_DSADC_VOLTS_TO_UV) / ((float32_t)maxCounts * analogGain));

    return result_uVolts;
}

/*******************************************************************************
* Function Name: Cy_DSADC_ConnectTemperature
****************************************************************************//**
*
* \brief
* Connects the specified pin to the parts of the on-die temperature sensor.
* \param base
* The pointer to the MMIO instance of the PACSS.
* \param selectMask
* Connect the specified signal to the temperature sensor. See \ref group_dsadc_macros_temperature_sensor
*
*******************************************************************************/
void Cy_DSADC_ConnectTemperature(PACSS_MMIO_Type* base, uint32_t selectMask)
{
    CY_ASSERT_L2(CY_DSADC_TMPS_MASK_VALID(selectMask));
    /* Connect temperature sensor */
    base->TMPS_CTL |= (selectMask & CY_DSADC_TMPS_SEL_MASK);
}

/*******************************************************************************
* Function Name: Cy_DSADC_DisconnectTemperature
****************************************************************************//**
*
* \brief
* Disconnects the specified pin from the parts of the on-die temperature sensor.
* \param base
* The pointer to the MMIO instance of the PACSS.
* \param selectMask
* Disconnect the specified signal from the temperature sensor. See \ref group_dsadc_macros_temperature_sensor
*
*******************************************************************************/
void Cy_DSADC_DisconnectTemperature(PACSS_MMIO_Type* base, uint32_t selectMask)
{
    CY_ASSERT_L2(CY_DSADC_TMPS_MASK_VALID(selectMask));
    /* Disconnect temperature sensor */
    base->TMPS_CTL &= ~(selectMask & CY_DSADC_TMPS_SEL_MASK);
}

/*******************************************************************************
* Function Name: Cy_DSADC_EnableTemperature
****************************************************************************//**
*
* \brief
* Enables the on-die temperature sensor.
* \param base
* The pointer to the MMIO instance of the PACSS.
*
*******************************************************************************/
void Cy_DSADC_EnableTemperature(PACSS_MMIO_Type* base)
{
    /* Enable temperature sensor */
    base->PACSS_CTL |= PACSS_MMIO_PACSS_CTL_TMPS_EN_Msk;
}

/*******************************************************************************
* Function Name: Cy_DSADC_DisableTemperature
****************************************************************************//**
*
* \brief
* Enables the on-die temperature sensor.
* \param base
* The pointer to the MMIO instance of the PACSS.
*
*******************************************************************************/
void Cy_DSADC_DisableTemperature(PACSS_MMIO_Type* base)
{
    /* Disable temperature sensor */
    base->PACSS_CTL &= ~PACSS_MMIO_PACSS_CTL_TMPS_EN_Msk;
}

/*******************************************************************************
* Function Name: Cy_DSADC_InitTemperature
****************************************************************************//**
*
* \brief
* Initializes the on-die temperature sensor.
* \param base
* The pointer to the MMIO instance of the PACSS.
* \param config
* Configuration options for the temperature sensor. See \ref cy_stc_dsadc_temperature_config_t.
* \note
* Before use, the structure should be initialized by using the \ref Cy_DSADC_InitializeDieTempConfigs function.
* \funcusage
* \snippet dsadc_snippet.c snippet_Cy_DSADC_InitOnDie
*
*******************************************************************************/
void Cy_DSADC_InitTemperature(PACSS_MMIO_Type* base, cy_stc_dsadc_temperature_config_t* config)
{
    CY_ASSERT_L1(NULL != config);

    base->TMPS_CTL = (_VAL2FLD(PACSS_MMIO_TMPS_CTL_IREF_SEL, config->currentSource) | \
                      _VAL2FLD(PACSS_MMIO_TMPS_CTL_IREF_UNIT, config->current) | \
                      _VAL2FLD(PACSS_MMIO_TMPS_CTL_LOAD_MODE, config->loadMode) | \
                      _VAL2FLD(PACSS_MMIO_TMPS_CTL_BIPOLAR_UNIT, config->bipolar));
}

/*******************************************************************************
* Function Name: Cy_DSADC_InitializeDieTempConfigs
****************************************************************************//**
*
* \brief
* Initialize the two configurations used for on-die temperature measurement with the
* value derived from the measurement conditions data stored in SFLASH.
* \param one
* On-die temperature configuration for the 1x(9.6 uA) current measurement.
* See \ref cy_stc_dsadc_temperature_config_t
* \param unit
* On-die temperature configuration for 9x(9.6 uA * 9 = 86.4 uA) current measurement.
* See \ref cy_stc_dsadc_temperature_config_t
* \param setup
* Primary or alternate temperature measurement parameters selection.
* See \ref cy_en_dsadc_temperature_setup_t
* \param target
* Across resistor or transistor temperature measurement selection.
* See \ref cy_en_dsadc_temp_volt_meas_t
* \funcusage
* \snippet dsadc_snippet.c snippet_Cy_DSADC_StructureInit
*
*******************************************************************************/
void Cy_DSADC_InitializeDieTempConfigs(cy_stc_dsadc_temperature_config_t* one,
                                       cy_stc_dsadc_temperature_config_t* unit,
                                       cy_en_dsadc_temperature_setup_t setup,
                                       cy_en_dsadc_temp_volt_meas_t target)
{
    CY_ASSERT_L1(NULL != one);
    CY_ASSERT_L1(NULL != unit);
    CY_ASSERT_L3(CY_DSADC_TEMPERATURE_CONFIG_ALTERNATE >= setup);
    CY_ASSERT_L3(CY_DSADC_TEMPERATURE_MEASUREMENT_TRANSISTOR >= target);

    if(CY_DSADC_TEMPERATURE_CONFIG_PRIMARY == setup)
    {
        if(CY_DSADC_TEMPERATURE_MEASUREMENT_RESISTOR == target)
        {
            one->loadMode = CY_DSADC_TEMPERATURE_LOAD_MODE_RESISTOR;
            unit->loadMode = CY_DSADC_TEMPERATURE_LOAD_MODE_RESISTOR;
        }
        else
        {
            one->loadMode = (0U != _FLD2VAL(SFLASH_PACSS_DIAG_TEMP_P_CAL_S_LOAD_MODE, \
                                            SFLASH->PACSS_DIAG_TEMP_P_CAL_S)) ? \
                                            CY_DSADC_TEMPERATURE_LOAD_MODE_NPN : \
                                            CY_DSADC_TEMPERATURE_LOAD_MODE_PNP;
            unit->loadMode = (0U != _FLD2VAL(SFLASH_PACSS_DIAG_TEMP_P_CAL_S_LOAD_MODE, \
                                             SFLASH->PACSS_DIAG_TEMP_P_CAL_S)) ? \
                                             CY_DSADC_TEMPERATURE_LOAD_MODE_NPN : \
                                             CY_DSADC_TEMPERATURE_LOAD_MODE_PNP;
        }

        one->currentSource = (0U != _FLD2VAL(SFLASH_PACSS_DIAG_TEMP_P_CAL_S_IREF_SEL, \
                                             SFLASH->PACSS_DIAG_TEMP_P_CAL_S)) ? \
                                             CY_DSADC_TEMPERATURE_CURRENT_SOURCE_SRSS : \
                                             CY_DSADC_TEMPERATURE_CURRENT_SOURCE_AREF;
        unit->currentSource = (0U != _FLD2VAL(SFLASH_PACSS_DIAG_TEMP_P_CAL_S_IREF_SEL, \
                                              SFLASH->PACSS_DIAG_TEMP_P_CAL_S)) ? \
                                              CY_DSADC_TEMPERATURE_CURRENT_SOURCE_SRSS : \
                                              CY_DSADC_TEMPERATURE_CURRENT_SOURCE_AREF;
        one->current = (uint16_t)_FLD2VAL(SFLASH_PACSS_DIAG_TEMP_P_CAL_S_IREF_1_MASK, \
                                          SFLASH->PACSS_DIAG_TEMP_P_CAL_S);
        one->bipolar = (uint16_t)_FLD2VAL(SFLASH_PACSS_DIAG_TEMP_P_CAL_S_BIPOLAR_1_MASK, \
                                          SFLASH->PACSS_DIAG_TEMP_P_CAL_S);

        if(CY_DSADC_TEMPERATURE_UNIT_MODE_BIPOLAR == _FLD2VAL(SFLASH_PACSS_DIAG_TEMP_P_CAL_S_UNIT_MODE, \
                                                              SFLASH->PACSS_DIAG_TEMP_P_CAL_S))
        {
            unit->current = (uint16_t)_FLD2VAL(SFLASH_PACSS_DIAG_TEMP_P_CAL_S_IREF_1_MASK, \
                                               SFLASH->PACSS_DIAG_TEMP_P_CAL_S);
            unit->bipolar = (uint16_t)_FLD2VAL(SFLASH_PACSS_DIAG_TEMP_P_CAL_S_IREF_BIPOLAR_UNIT_MASK, \
                                               SFLASH->PACSS_DIAG_TEMP_P_CAL_S);
        }
        else
        {
            unit->current = (uint16_t)_FLD2VAL(SFLASH_PACSS_DIAG_TEMP_P_CAL_S_IREF_BIPOLAR_UNIT_MASK, \
                                               SFLASH->PACSS_DIAG_TEMP_P_CAL_S);
            unit->bipolar = (uint16_t)_FLD2VAL(SFLASH_PACSS_DIAG_TEMP_P_CAL_S_BIPOLAR_1_MASK, \
                                               SFLASH->PACSS_DIAG_TEMP_P_CAL_S);
        }
    }
    else
    {
        if(CY_DSADC_TEMPERATURE_MEASUREMENT_RESISTOR == target)
        {
            one->loadMode = CY_DSADC_TEMPERATURE_LOAD_MODE_RESISTOR;
            unit->loadMode = CY_DSADC_TEMPERATURE_LOAD_MODE_RESISTOR;
        }
        else
        {
            one->loadMode = (0U != _FLD2VAL(SFLASH_PACSS_DIAG_TEMP_A_CAL_S_LOAD_MODE, \
                                            SFLASH->PACSS_DIAG_TEMP_A_CAL_S)) ? \
                                            CY_DSADC_TEMPERATURE_LOAD_MODE_NPN : \
                                            CY_DSADC_TEMPERATURE_LOAD_MODE_PNP;
            unit->loadMode = (0U != _FLD2VAL(SFLASH_PACSS_DIAG_TEMP_A_CAL_S_LOAD_MODE, \
                                             SFLASH->PACSS_DIAG_TEMP_A_CAL_S)) ? \
                                             CY_DSADC_TEMPERATURE_LOAD_MODE_NPN : \
                                             CY_DSADC_TEMPERATURE_LOAD_MODE_PNP;
        }

        one->currentSource = (0U != _FLD2VAL(SFLASH_PACSS_DIAG_TEMP_A_CAL_S_IREF_SEL, \
                                             SFLASH->PACSS_DIAG_TEMP_A_CAL_S)) ? \
                                             CY_DSADC_TEMPERATURE_CURRENT_SOURCE_SRSS : \
                                             CY_DSADC_TEMPERATURE_CURRENT_SOURCE_AREF;
        unit->currentSource = (0U != _FLD2VAL(SFLASH_PACSS_DIAG_TEMP_A_CAL_S_IREF_SEL, \
                                              SFLASH->PACSS_DIAG_TEMP_A_CAL_S)) ? \
                                              CY_DSADC_TEMPERATURE_CURRENT_SOURCE_SRSS : \
                                              CY_DSADC_TEMPERATURE_CURRENT_SOURCE_AREF;
        one->current = (uint16_t)_FLD2VAL(SFLASH_PACSS_DIAG_TEMP_A_CAL_S_IREF_1_MASK, \
                                          SFLASH->PACSS_DIAG_TEMP_A_CAL_S);
        one->bipolar = (uint16_t)_FLD2VAL(SFLASH_PACSS_DIAG_TEMP_A_CAL_S_BIPOLAR_1_MASK, \
                                          SFLASH->PACSS_DIAG_TEMP_A_CAL_S);

        if(CY_DSADC_TEMPERATURE_UNIT_MODE_BIPOLAR == _FLD2VAL(SFLASH_PACSS_DIAG_TEMP_A_CAL_S_UNIT_MODE, \
                                                              SFLASH->PACSS_DIAG_TEMP_A_CAL_S))
        {
            unit->current = (uint16_t)_FLD2VAL(SFLASH_PACSS_DIAG_TEMP_A_CAL_S_IREF_1_MASK, \
                                               SFLASH->PACSS_DIAG_TEMP_A_CAL_S);
            unit->bipolar = (uint16_t)_FLD2VAL(SFLASH_PACSS_DIAG_TEMP_A_CAL_S_IREF_BIPOLAR_UNIT_MASK, \
                                               SFLASH->PACSS_DIAG_TEMP_A_CAL_S);
        }
        else
        {
            unit->current = (uint16_t)_FLD2VAL(SFLASH_PACSS_DIAG_TEMP_A_CAL_S_IREF_BIPOLAR_UNIT_MASK, \
                                               SFLASH->PACSS_DIAG_TEMP_A_CAL_S);
            unit->bipolar = (uint16_t)_FLD2VAL(SFLASH_PACSS_DIAG_TEMP_A_CAL_S_BIPOLAR_1_MASK, \
                                               SFLASH->PACSS_DIAG_TEMP_A_CAL_S);
        }
    }
}

/*******************************************************************************
* Function Name: Cy_DSADC_CalcCurrentRatio
****************************************************************************//**
*
* \brief
* Initialize the two configurations used for on-die temperature measurement with the
* value derived from the measurement conditions data stored in SFLASH.
* \param currentOne
* The result of 1x(one) measurement across resistor.
* \param currentUnit
* The result of 9x(unit) measurement across resistor.
* \return
* The ratio of measurement results across resistor.
* \funcusage
* \snippet dsadc_snippet.c snippet_Cy_DSADC_InitOnDie
*
*******************************************************************************/
uint32_t Cy_DSADC_CalcCurrentRatio(int32_t currentOne, int32_t currentUnit)
{
    /* Check if the counts of voltage when IREF current x1 and x9 is not out of range */
    CY_ASSERT_L3(IS_OUT_OF_RANGE_1X(currentOne) && IS_OUT_OF_RANGE_9X(currentUnit));

    /* The ratio of two DSADC conversion results */
    const uint32_t numerator   = (uint32_t)currentUnit << CY_DSADC_TEMPERATURE_CURRENT_RATIO_UNIT_SHIFT;
    const uint32_t denominator = (uint32_t)currentOne >> CY_DSADC_TEMPERATURE_CURRENT_RATIO_ONE_SHIFT;

    return (numerator + (denominator >> 1U)) / denominator;
}

/*******************************************************************************
* Function Name: Cy_DSADC_CalcDieTemp
****************************************************************************//**
*
* \brief
* Calculate on-die temperature with delta VBE measurement and current ratio,
* normalize the Delta VBE measurement to the ratio of the current sources,
* converting the delta between two on-die temperature measurements to degree celsius.
* \param vbeOne
* The result of 1x(one) measurement across transistor.
* \param vbeUnit
* The result of 9x(unit) measurement across transistor.
* \param currentRatio
* The ratio of measurement results across resistor.
* \param setup
* Primary or alternate temperature measurement parameters selection. See \ref cy_en_dsadc_temperature_setup_t
* \return
* Calculated temperature in fixed point Q12.20 format.
* \note
* The ratio of current sources or transistors is usually 9/1 so normalization can be done with the equation:
* newDelta = delta*LN(9)/LN(ratio)
* Natural logarithm is processor intensive so we instead use the linear approximation:
* newDelta = delta+delta*(A*ratio+B), where:
* delta = ADC(UNIT)-ADC(1) (29 bit signed result)
* A = -0.0534
* B = 0.4804
* T = (a2 * x^2 * 2^(-34) + a1 * x * 2^(-9) + a0 * 2^14)
* where x = newDelta
* For the fixed point 12.20 format calculation(not performed):
* T = T/2^20
* \funcusage
* \snippet dsadc_snippet.c snippet_Cy_DSADC_PerformMeasurement
*
*******************************************************************************/
int32_t Cy_DSADC_CalcDieTemp(int32_t vbeOne,
                             int32_t vbeUnit,
                             uint32_t currentRatio,
                             cy_en_dsadc_temperature_setup_t setup)
{
    /* Validate input parameters */
    CY_ASSERT_L3(CY_DSADC_TEMPERATURE_CONFIG_ALTERNATE >= setup);
    CY_ASSERT_L3(IS_OUT_OF_RANGE_VBE(vbeOne) && IS_OUT_OF_RANGE_VBE(vbeUnit) && IS_OUT_OF_RANGE_RATIO(currentRatio));

    /* Calculate Delta VBE: difference between two DSADC measurements */
    const int32_t deltaVbe = vbeUnit - vbeOne;

    CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 10.8', 12, \
    'Casting uint32_t to int32_t, and uint64_t to int64_t will not result in overflow.');
    /* Normalize Delta VBE using the current ratio and linear approximation */
    int32_t coefficientTemp = (int32_t)(((uint32_t)CY_DSADC_TEMPERATURE_NORMALIZATION_A * currentRatio) >> 1U);
    coefficientTemp = coefficientTemp * CY_DSADC_TEMPERATURE_NORMALIZATION_A_SIGN;
    const int32_t coefficient = coefficientTemp + (int32_t)CY_DSADC_TEMPERATURE_NORMALIZATION_B;

    /* Adjust Delta VBE using the normalized coefficient */
    int64_t deltaTemp = ((int64_t)deltaVbe * (int64_t)coefficient) + \
                        (int64_t)(1ULL << (CY_DSADC_TEMPERATURE_COEFFICIENT_RATIO - 1U));

    int32_t sign = (0LL > deltaTemp) ? -1 : 1;
    deltaTemp = (0LL > deltaTemp) ? -deltaTemp : deltaTemp;

    int32_t delta = (int32_t)((uint64_t)deltaTemp >> CY_DSADC_TEMPERATURE_COEFFICIENT_RATIO);
    delta = delta * sign;
    delta = deltaVbe + delta;

    /* Get temperature calibration data polynomial (a0, a1, a2) */
    int16_t a2 = 0;
    int16_t a1 = 0;
    int16_t a0 = 0;

    if(CY_DSADC_TEMPERATURE_CONFIG_PRIMARY == setup)
    {
        a2 = CY_DSADC_GET_INT16(SFLASH_PACSS_DIAG_TEMP_P_CAL_A2_A2, SFLASH->PACSS_DIAG_TEMP_P_CAL_A2);
        a1 = CY_DSADC_GET_INT16(SFLASH_PACSS_DIAG_TEMP_P_CAL_A1_A1, SFLASH->PACSS_DIAG_TEMP_P_CAL_A1);
        a0 = CY_DSADC_GET_INT16(SFLASH_PACSS_DIAG_TEMP_P_CAL_A0_A0, SFLASH->PACSS_DIAG_TEMP_P_CAL_A0);
    }
    else
    {
        a2 = CY_DSADC_GET_INT16(SFLASH_PACSS_DIAG_TEMP_A_CAL_A2_A2, SFLASH->PACSS_DIAG_TEMP_A_CAL_A2);
        a1 = CY_DSADC_GET_INT16(SFLASH_PACSS_DIAG_TEMP_A_CAL_A1_A1, SFLASH->PACSS_DIAG_TEMP_A_CAL_A1);
        a0 = CY_DSADC_GET_INT16(SFLASH_PACSS_DIAG_TEMP_A_CAL_A0_A0, SFLASH->PACSS_DIAG_TEMP_A_CAL_A0);
    }

    /* Calculate the squared term: a2 * x^2 * 2^(-34) */
    int64_t sqrdTerm = (int64_t)delta * (int64_t)delta;
    sqrdTerm = (int64_t)(((uint64_t)sqrdTerm + (1ULL << (CY_DSADC_TEMPERATURE_SQUARED_TERM_SHIFT - 1U))) >> \
                CY_DSADC_TEMPERATURE_SQUARED_TERM_SHIFT);
    sqrdTerm = sqrdTerm * (int64_t)a2;

    /* Calculate the linear term: a1 * x * 2^(-9) */
    int32_t linearTerm = delta;
    sign = (0L > linearTerm) ? -1 : 1;
    linearTerm = (0L > linearTerm) ? -linearTerm : linearTerm;

    linearTerm = (int32_t)(((uint32_t)linearTerm + (1UL << (CY_DSADC_TEMPERATURE_LINEAR_TERM_SHIFT - 1U))) >> \
                  CY_DSADC_TEMPERATURE_LINEAR_TERM_SHIFT);
    linearTerm = linearTerm * sign;
    linearTerm = linearTerm * (int32_t)a1;

    /* Calculate the offset term: a0 * 2^14 */
    sign = (0L > a0) ? -1 : 1;
    a0 = (0L > a0) ? -a0 : a0;
    int32_t offset = (int32_t)((uint32_t)a0 << CY_DSADC_TEMPERATURE_OFFSET_TERM_SHIFT);
    CY_MISRA_BLOCK_END('MISRA C-2012 Rule 10.8');
    offset = offset * sign;

    return ((int32_t)sqrdTerm + linearTerm + offset);
}

/*******************************************************************************
* Function Name: Cy_DSADC_EnableLowDropoutRegulator
****************************************************************************//**
*
* \brief
* Enables the LDO, which provides voltage to the modulator.
* \param base
* The pointer to the MMIO instance of the PACSS.
* \warning
* The LDO must be enabled before enabling Analog Channel (ACHAN).
* Simply disabling and re-enabling the LDO will not work correctly.
* To ensure proper functionality, the LDO must be enabled before enabling the ACHAN,
* and the LDO should be disabled only after the ACHAN is disabled.
*
*******************************************************************************/
void Cy_DSADC_EnableLowDropoutRegulator(PACSS_MMIO_Type* base)
{
    /* Enable LDO */
    base->PACSS_CTL |= PACSS_MMIO_PACSS_CTL_LDO_EN_Msk;
}

/*******************************************************************************
* Function Name: Cy_DSADC_DisableLowDropoutRegulator
****************************************************************************//**
*
* \brief
* Disables the LDO, which provides voltage to the modulator
* \param base
* The pointer to the MMIO instance of the PACSS.
* \warning
* The LDO must be enabled before enabling Analog Channel (ACHAN).
* Simply disabling and re-enabling the LDO will not work correctly.
* To ensure proper functionality, the LDO must be enabled before enabling the ACHAN,
* and the LDO should be disabled only after the ACHAN is disabled.
*
*******************************************************************************/
void Cy_DSADC_DisableLowDropoutRegulator(PACSS_MMIO_Type* base)
{
    /* Disable LDO */
    base->PACSS_CTL &= ~PACSS_MMIO_PACSS_CTL_LDO_EN_Msk;
}

/*******************************************************************************
* Function Name: Cy_DSADC_EnableLowPowerMode
****************************************************************************//**
*
* \brief
* Enables the AREF lower power mode.
* \param base
* The pointer to the MMIO instance of the PACSS.
* \warning
* In deepsleep mode, AREF lower power mode is automatically enabled,
* so it must be disabled after exiting deepsleep.
*
*******************************************************************************/
void Cy_DSADC_EnableLowPowerMode(PACSS_MMIO_Type* base)
{
    /* Enable AREF lower power mode */
    base->AREF_CTL |= PACSS_MMIO_AREF_CTL_LP_MODE_Msk;
}

/*******************************************************************************
* Function Name: Cy_DSADC_DisableLowPowerMode
****************************************************************************//**
*
* \brief
* Disables the AREF lower power mode.
* \param base
* The pointer to the MMIO instance of the PACSS.
* \warning
* In deepsleep mode, AREF lower power mode is automatically enabled,
* so it must be disabled after exiting deepsleep.
*
*******************************************************************************/
void Cy_DSADC_DisableLowPowerMode(PACSS_MMIO_Type* base)
{
    /* Disables AREF lower power mode */
    base->AREF_CTL &= ~PACSS_MMIO_AREF_CTL_LP_MODE_Msk;
}

/*******************************************************************************
* Function Name: Cy_DSADC_SetAccumulatorThreshold
****************************************************************************//**
*
* \brief
* Sets the threshold for the accumulator.
* \param base
* The base address for the Digital Channel.
* \param threshold
* Accumulator Threshold valid value are between -2147483648 and 2147483647.
*
*******************************************************************************/
void Cy_DSADC_SetAccumulatorThreshold(PACSS_DCHAN_Type* base, int32_t threshold)
{
    /* Sets the threshold */
    base->ACC_THRESH = _VAL2FLD(PACSS_DCHAN_ACC_THRESH_ACC_THRESH, threshold);
}

/*******************************************************************************
* Function Name: Cy_DSADC_ResetAccumulator
****************************************************************************//**
*
* \brief
* Resets the accumulated result to zero.
* \param base
* The base address for the Digital Channel.
*
*******************************************************************************/
void Cy_DSADC_ResetAccumulator(PACSS_DCHAN_Type* base)
{
    /* Resets the accumulated result to zero */
    base->ACC_RESULT &= ~PACSS_DCHAN_ACC_RESULT_ACC_RESULT_Msk;
}

/*******************************************************************************
* Function Name: Cy_DSADC_StartConversionAll
****************************************************************************//**
*
* \brief
* Triggers the conversion for all enabled primary channels.
* \param base
* The pointer to the MMIO instance of the PACSS.
*
*******************************************************************************/
void Cy_DSADC_StartConversionAll(PACSS_MMIO_Type* base)
{
    /* Trigger conversion for all enabled primary channels*/
    base->START |= PACSS_MMIO_START_START_PRIM_Msk;
}

/*******************************************************************************
* Function Name: Cy_DSADC_PendSecondConvAll
****************************************************************************//**
*
* \brief
* Triggers the conversion for all enabled secondary channels.
* \param base
* The pointer to the MMIO instance of the PACSS.
*
*******************************************************************************/
void Cy_DSADC_PendSecondConvAll(PACSS_MMIO_Type* base)
{
    /* Trigger conversion for all enabled secondary channels */
    base->START |= PACSS_MMIO_START_PEND_SEC_Msk;
}

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* (CY_IP_M0S8PACSS) */

/* [] END OF FILE */
