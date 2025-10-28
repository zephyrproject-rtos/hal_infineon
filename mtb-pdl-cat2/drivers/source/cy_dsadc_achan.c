/***************************************************************************//**
* \file cy_dsadc.c
* \version 1.0
*
* \brief
* Provides an API implementation of the analog channels of the Delta-Sigma ADC
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

/*==================[macros]==================================================*/
/* Value of data source of the decimator input */
#define CY_DSADC_ACHAN_DPATH_CTL_MX_DIN_VALUE (0U)
/* Value of DSM data routed to the dbg_io output */
#define CY_DSADC_ACHAN_DPATH_CTL_MX_DOUT_VALUE (0U)
/* Value of quantization level of modulator */
#define CY_DSADC_ACHAN_DPATH_CTL_QLEV_VALUE (2U)
/* Value of negative pump power mode */
#define CY_DSADC_ACHAN_PUMP_CTL_VNEG_PWR_MODE_VALUE (3U)
/* Value of VCM selection */
#define CY_DSADC_ACHAN_REF_CTL_VCM_SEL_VALUE (0U)

/*==================[internal function definitions]===========================*/
/*******************************************************************************
* Function Name: Cy_DSADC_Achan_ConfigBuffer
****************************************************************************//**
*
* \brief Configure the Analog Channel Buffer.
*
* \note Applicable to PSOC4 HVPA only.
*
* \param base
* The base address for the Analog Channel.
*
* \param config
* ACHAN configuration. See \ref cy_stc_dsadc_achan_config_t.
*
*******************************************************************************/
static void Cy_DSADC_Achan_ConfigBuffer(PACSS_ACHAN_Type* base, const cy_stc_dsadc_achan_config_t* config)
{
    base->BUF_CTL = (_VAL2FLD(PACSS_ACHAN_BUF_CTL_BUF_PWR_LEVELS, config->bufferPowerLevel) | \
                     _VAL2FLD(PACSS_ACHAN_BUF_CTL_BUF_CHOP_EN, config->bufferPowerLevel) | \
                     _VAL2FLD(PACSS_ACHAN_BUF_CTL_BUF_IDAC_EN, config->bufferPowerLevel));
    /* Enable buffer */
    base->ACHAN_CTL |= PACSS_ACHAN_ACHAN_CTL_BUF_EN_Msk;
}

/*******************************************************************************
* Function Name: Cy_DSADC_Achan_ConfigModulator
****************************************************************************//**
*
* \brief Configure the Analog Channel Modulator.
*
* \note Applicable to PSOC4 HVPA only.
*
* \param base
* The base address for the Analog Channel.
*
* \param config
* ACHAN configuration. See \ref cy_stc_dsadc_achan_config_t.
*
*******************************************************************************/
static void Cy_DSADC_Achan_ConfigModulator(PACSS_ACHAN_Type* base, const cy_stc_dsadc_achan_config_t* config)
{
    /* Set MOD_CTL register */
    base->MOD_CTL = (_VAL2FLD(PACSS_ACHAN_MOD_CTL_POWER1, config->firstStagePower) | \
                     _VAL2FLD(PACSS_ACHAN_MOD_CTL_POWER2_3, config->secondThirdStagePower) | \
                     _VAL2FLD(PACSS_ACHAN_MOD_CTL_POWER_COMP, config->compPower) | \
                     _VAL2FLD(PACSS_ACHAN_MOD_CTL_POWER_SUM, config->summerPower) | \
                     _VAL2FLD(PACSS_ACHAN_MOD_CTL_MOD_FCHOP, config->modulatorChoppingDivider) | \
                     PACSS_ACHAN_MOD_CTL_MOD_CHOP_EN_Msk);

    /* Set DPATH_CTL (except overload detection) register */
    base->DPATH_CTL = (_VAL2FLD(PACSS_ACHAN_DPATH_CTL_QLEV, CY_DSADC_ACHAN_DPATH_CTL_QLEV_VALUE) | \
                     _VAL2FLD(PACSS_ACHAN_DPATH_CTL_NONOV, config->nonOverlapDelay) | \
                     _VAL2FLD(PACSS_ACHAN_DPATH_CTL_MX_DIN, CY_DSADC_ACHAN_DPATH_CTL_MX_DIN_VALUE) | \
                     _VAL2FLD(PACSS_ACHAN_DPATH_CTL_MX_DOUT, CY_DSADC_ACHAN_DPATH_CTL_MX_DOUT_VALUE) | \
                     _VAL2FLD(PACSS_ACHAN_DPATH_CTL_BUF_PGA_FCHOP, config->datapathChoppingDivider) | \
                     PACSS_ACHAN_DPATH_CTL_BUF_PGA_CHOP_CLK_EN_Msk);

    /* Set CHOP_CTL register */
    CY_REG32_CLR_SET(base->CHOP_CTL,PACSS_ACHAN_CHOP_CTL_CIRCUIT_CHOP,config->aafDisconnectCount);
    if (false != config->enableSecIntegrChopping)
    {
        base->CHOP_CTL |= PACSS_ACHAN_CHOP_CTL_CIRCUIT_2ND_EN_Msk;
    }
    else
    {
        base->CHOP_CTL &= ~PACSS_ACHAN_CHOP_CTL_CIRCUIT_2ND_EN_Msk;
    }

    /* Set DEM_CTL register */
    base->DEM_CTL = (uint32_t)config->demMode;
    /* Enable or disable DEM */
    if (false != config->enableDem)
    {
        base->DEM_CTL |= PACSS_ACHAN_DEM_CTL_DEM_EN_Msk;
    }
    else
    {
        base->DEM_CTL &= ~PACSS_ACHAN_DEM_CTL_DEM_EN_Msk;
    }
    /* Enable modulator */
    base->ACHAN_CTL |= PACSS_ACHAN_ACHAN_CTL_MOD_EN_Msk;
}

/*******************************************************************************
* Function Name: Cy_DSADC_Achan_ConfigPGA
****************************************************************************//**
*
* \brief Configure the Analog Channel Programmable Gain Array.
*
* \note Applicable to PSOC4 HVPA only.
*
* \param base
* The base address for the Analog Channel.
*
* \param config
* ACHAN configuration. See \ref cy_stc_dsadc_achan_config_t.
*
*******************************************************************************/
static void Cy_DSADC_Achan_ConfigPGA(PACSS_ACHAN_Type* base, const cy_stc_dsadc_achan_config_t* config)
{
    /* Set PGA_CTL register */
    base->PGA_CTL = (_VAL2FLD(PACSS_ACHAN_PGA_CTL_PGA_PWR_LEVELS, config->pgaPowerLevel) | \
                     PACSS_ACHAN_PGA_CTL_PGA_CHOP_EN_Msk | \
                     PACSS_ACHAN_PGA_CTL_PGA_IDAC_EN_Msk | \
                     PACSS_ACHAN_PGA_CTL_PGA_OVERLAP_EN_Msk);
    /* Enable PGA */
    base->ACHAN_CTL |= PACSS_ACHAN_ACHAN_CTL_PGA_EN_Msk;
}

/*******************************************************************************
* Function Name: Cy_DSADC_Achan_ConfigPrmTrigger
****************************************************************************//**
*
* \brief Configure the Analog Channel Primary Trigger.
*
* \note Applicable to PSOC4 HVPA only.
*
* \param base
* The base address for the Analog Channel.
*
* \param config
* ACHAN configuration. See \ref cy_stc_dsadc_achan_config_t.
*
*******************************************************************************/
static void Cy_DSADC_Achan_ConfigPrmTrigger(PACSS_ACHAN_Type* base, const cy_stc_dsadc_achan_config_t* config)
{
    if(CY_DSADC_ACHAN_TRIGGER_FW == config->primaryTrigger)
    {
        /* Disable HW trigger */
        base->TR_CTL &= PACSS_ACHAN_TR_CTL_PRIM_TR_EN_Msk;
    }
    else
    {
        /* Set HW trigger */
        base->TR_CTL = (_VAL2FLD(PACSS_ACHAN_TR_CTL_PRIM_TR_SEL, config->primaryTrigger) | \
                        _VAL2FLD(PACSS_ACHAN_TR_CTL_SYNC_PRIM_TR, config->syncPrimaryTrigger) | \
                        PACSS_ACHAN_TR_CTL_PRIM_TR_EN_Msk);
    }
}

/*******************************************************************************
* Function Name: Cy_DSADC_Achan_ConfigRef
****************************************************************************//**
*
* \brief Configure the Analog Channel Reference.
*
* \note Applicable to PSOC4 HVPA only.
*
* \param base
* The base address for the Analog Channel.
*
* \param config
* ACHAN configuration. See \ref cy_stc_dsadc_achan_config_t.
*
*******************************************************************************/
static void Cy_DSADC_Achan_ConfigRef(PACSS_ACHAN_Type* base, const cy_stc_dsadc_achan_config_t* config)
{
    /* Set REF_CTL register */
    base->REF_CTL = (_VAL2FLD(PACSS_ACHAN_REF_CTL_VREF_PWR, config->vrefPower) | \
                     _VAL2FLD(PACSS_ACHAN_REF_CTL_VCM_SEL, CY_DSADC_ACHAN_REF_CTL_VCM_SEL_VALUE) | \
                     _VAL2FLD(PACSS_ACHAN_REF_CTL_VCM_PWR, config->vcmPowerLevel));
    base->REF_CTL &= PACSS_ACHAN_REF_CTL_VREF_QTZ_SEL_Msk;
    /* Set ACHAN_CTL (reference) register */
    base->ACHAN_CTL = (PACSS_ACHAN_ACHAN_CTL_VCCA_RES_EN_Msk | \
                       PACSS_ACHAN_ACHAN_CTL_VDDA_RES_EN_Msk | \
                       PACSS_ACHAN_ACHAN_CTL_VCM_BUF_EN_Msk | \
                       PACSS_ACHAN_ACHAN_CTL_REF_EN_Msk);
}

/*******************************************************************************
* Function Name: Cy_DSADC_Achan_ConfigSecTrigger
****************************************************************************//**
*
* \brief Configure the Analog Channel Reference.
*
* \note Applicable to PSOC4 HVPA only.
*
* \param base
* The base address for the Analog Channel.
*
* \param config
* ACHAN configuration. See \ref cy_stc_dsadc_achan_config_t.
*
*******************************************************************************/
static void Cy_DSADC_Achan_ConfigSecTrigger(PACSS_ACHAN_Type* base, const cy_stc_dsadc_achan_config_t* config)
{
    if(CY_DSADC_ACHAN_TRIGGER_FW == config->secondaryTrigger)
    {
        /* Disable HW trigger */
        base->TR_CTL &= PACSS_ACHAN_TR_CTL_PEND_SEC_TR_EN_Msk;
    }
    else
    {
        /* Set HW trigger */
        base->TR_CTL = (_VAL2FLD(PACSS_ACHAN_TR_CTL_PEND_SEC_TR_SEL, config->secondaryTrigger) | \
                        _VAL2FLD(PACSS_ACHAN_TR_CTL_SYNC_SEC_TR, config->syncSecondaryTrigger) | \
                        PACSS_ACHAN_TR_CTL_PEND_SEC_TR_EN_Msk);
    }
}

/*******************************************************************************
* Function Name: Cy_DSADC_Achan_EnOverDet
****************************************************************************//**
*
* \brief Enable or disable overload detection
*
* \note Applicable to PSOC4 HVPA only.
*
* \param base
* The base address for the Analog Channel.
*
* \param config
* ACHAN configuration. See \ref cy_stc_dsadc_achan_config_t.
*
*******************************************************************************/
static void Cy_DSADC_Achan_EnOverDet(PACSS_ACHAN_Type* base, const cy_stc_dsadc_achan_config_t* config)
{
    if(false != config->useOverloadDetection)
    {
        /* Enable overload detection */
        CY_REG32_CLR_SET(base->DPATH_CTL, PACSS_ACHAN_DPATH_CTL_ODET_TH, config->overloadDetectThr);
        if (false != config->enableReset1)
        {
            base->DPATH_CTL |= PACSS_ACHAN_DPATH_CTL_RESET1_EN_Msk;
        }
        else
        {
            base->DPATH_CTL &= ~PACSS_ACHAN_DPATH_CTL_RESET1_EN_Msk;
        }
        if (false != config->enableReset2)
        {
            base->DPATH_CTL |= PACSS_ACHAN_DPATH_CTL_RESET2_EN_Msk;
        }
        else
        {
            base->DPATH_CTL &= ~PACSS_ACHAN_DPATH_CTL_RESET2_EN_Msk;
        }
        if (false != config->enableReset3)
        {
            base->DPATH_CTL |= PACSS_ACHAN_DPATH_CTL_RESET3_EN_Msk;
        }
        else
        {
            base->DPATH_CTL &= ~PACSS_ACHAN_DPATH_CTL_RESET3_EN_Msk;
        }
        base->DPATH_CTL |= PACSS_ACHAN_DPATH_CTL_OD_EN_Msk;
    }
    else
    {
        /* Disable overload detection */
        base->DPATH_CTL &= ~PACSS_ACHAN_DPATH_CTL_OD_EN_Msk;
        base->DPATH_CTL &= ~PACSS_ACHAN_DPATH_CTL_RESET1_EN_Msk;
        base->DPATH_CTL &= ~PACSS_ACHAN_DPATH_CTL_RESET2_EN_Msk;
        base->DPATH_CTL &= ~PACSS_ACHAN_DPATH_CTL_RESET3_EN_Msk;
    }
}

/*==================[external function definitions]===========================*/
/*******************************************************************************
* Function Name: Cy_DSADC_DisableAchan
****************************************************************************//**
*
* \brief Disable the Analog Channel.
*
* \note Applicable to PSOC4 HVPA only.
*
* \param base
* The base address for the Analog Channel.
*
*******************************************************************************/
void Cy_DSADC_DisableAchan(PACSS_ACHAN_Type* base)
{
    CY_ASSERT_L1(NULL != base);
    /* Disable ACHAN */
    base->ACHAN_CTL &= ~PACSS_ACHAN_ACHAN_CTL_ENABLE_Msk;
}

/*******************************************************************************
* Function Name: Cy_DSADC_EnableAchan
****************************************************************************//**
*
* \brief Enable the Analog Channel.
*
* \note Applicable to PSOC4 HVPA only.
*
* \param base
* The base address for the Analog Channel.
*
*******************************************************************************/
void Cy_DSADC_EnableAchan(PACSS_ACHAN_Type* base)
{
    CY_ASSERT_L1(NULL != base);
    /* Enable ACHAN */
    base->ACHAN_CTL |= PACSS_ACHAN_ACHAN_CTL_ENABLE_Msk;
}

/*******************************************************************************
* Function Name: Cy_DSADC_InitAchan
****************************************************************************//**
*
* \brief Configure the Analog Channel
*
* \note Applicable to PSOC4 HVPA only.
*
* \param base
* The base address for the Analog Channel.
*
* \param config
* ACHAN configuration. See \ref cy_stc_dsadc_achan_config_t.
*
*******************************************************************************/
void Cy_DSADC_InitAchan(PACSS_ACHAN_Type* base, const cy_stc_dsadc_achan_config_t* config)
{
    CY_ASSERT_L1(NULL != base);
    CY_ASSERT_L1(NULL != config);
    /* Set AAF cut-off frequency */
    CY_REG32_CLR_SET(base->ACHAN_CTL, PACSS_ACHAN_ACHAN_CTL_AAF_CUTOFF_FREQ, config->aafCutoffFreq);
    /* Configure primary Trigger */
    Cy_DSADC_Achan_ConfigPrmTrigger(base, config);
    /* Configure secondary Trigger */
    Cy_DSADC_Achan_ConfigSecTrigger(base, config);
    /* Set PUMP_CTL register */
    base->PUMP_CTL = (_VAL2FLD(PACSS_ACHAN_PUMP_CTL_CLOCK_SEL, config->pumpClock) | \
                      _VAL2FLD(PACSS_ACHAN_PUMP_CTL_VNEG_PWR_MODE, CY_DSADC_ACHAN_PUMP_CTL_VNEG_PWR_MODE_VALUE));
    /* Configure reference */
    Cy_DSADC_Achan_ConfigRef(base, config);
    /* Configure over load detection */
    Cy_DSADC_Achan_EnOverDet(base, config);
    /* Configure modulator */
    Cy_DSADC_Achan_ConfigModulator(base, config);
    /* Configure buffer */
    Cy_DSADC_Achan_ConfigBuffer(base, config);
    /* Configure PGA */
    Cy_DSADC_Achan_ConfigPGA(base, config);
}

/*******************************************************************************
* Function Name: Cy_DSADC_PendSecondConvAchan
****************************************************************************//**
*
* \brief Enable the Analog Channel.
*
* \note Applicable to PSOC4 HVPA only.
*
* \param base
* The base address for the Analog Channel.
*
*******************************************************************************/
void Cy_DSADC_PendSecondConvAchan(PACSS_ACHAN_Type* base)
{
    CY_ASSERT_L1(NULL != base);
    /* Trigger pend conversion of secondary channel */
    base->START |= PACSS_ACHAN_START_PEND_SEC_Msk;
}

/*******************************************************************************
* Function Name: Cy_DSADC_StartConversionAchan
****************************************************************************//**
*
* \brief Enable the Analog Channel.
*
* \note Applicable to PSOC4 HVPA only.
*
* \param base
* The base address for the Analog Channel.
*
*******************************************************************************/
void Cy_DSADC_StartConversionAchan(PACSS_ACHAN_Type* base)
{
    CY_ASSERT_L1(NULL != base);
    /* Trigger start conversion of primary channel */
    base->START |= PACSS_ACHAN_START_START_PRIM_Msk;
}

/*******************************************************************************
* Function Name: Cy_DSADC_InitAchanChannelChopping
****************************************************************************//**
*
* \brief
* Configure the selected Analog Channel to perform the channel chopping.
* \param base
* The base address for the Analog Channel.
* \param config
* Configuration options for the ACHAN channel chopping
*/
/******************************************************************************/
void Cy_DSADC_InitAchanChannelChopping(PACSS_ACHAN_Type* base, const cy_stc_dsadc_achan_channel_chopping_config_t* config)
{
    CY_ASSERT_L1(NULL != base);
    CY_ASSERT_L1(NULL != config);
    /* Set CHOP_CTL register */
    base->CHOP_CTL = (_VAL2FLD(PACSS_ACHAN_CHOP_CTL_SMP_CNT, config->modbitSampleCount) | \
                      _VAL2FLD(PACSS_ACHAN_CHOP_CTL_AAF_SHORT_R_CNT, config->aafShortCount) | \
                      _VAL2FLD(PACSS_ACHAN_CHOP_CTL_DEC_BLANK_CNT, config->decimatorBlankCount) | \
                      _VAL2FLD(PACSS_ACHAN_CHOP_CTL_CHOP_MODE, config->choppingType));
}

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* (CY_IP_M0S8PACSS) */

/* [] END OF FILE */
