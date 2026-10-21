/***************************************************************************//**
* \file cy_usbpd_idac_ctrl.c
* \version 2.110
*
* The source file of the USBPD IDAC Control driver.
*
********************************************************************************
* \copyright
* (c) (2022 - 2025), Cypress Semiconductor Corporation (an Infineon company) or
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
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either expressed or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

#include "cy_device.h"
#include "cy_pdl.h"

#if (defined(CY_IP_MXUSBPD) || defined(CY_IP_M0S8USBPD))

#include "cy_usbpd_config_table.h"
#include "cy_usbpd_common.h"
#include "cy_usbpd_defines.h"
#include "cy_usbpd_idac_ctrl.h"
#include "cy_usbpd_vbus_ctrl.h"
#include "cy_usbpd_typec.h"


#define CCG_SILICON_REV00_VALUE                 (0x11u)

/* Current threshold in 10mA units below which we detect it as CV mode. */
#define LSCSA_CF_CUR_THRES                       (5u)

#define LSCSA_CF_CUR_HIGH_LIMIT                  (300u)

#define LSCSA_CF_CUR_HIGH_THRES                  (10u)

/* Range of VSense supported by the LSCSA */
#define LSCSA_VSENSE_MIN                        (10u)
#define LSCSA_VSENSE_MAX                        (600u)
#define LSCSA_GAIN_150_VSENSE_MAX               (140u)
#define LSCSA_GAIN_35_VSENSE_MIN                (160u)

/* LSCSA measured error for 15mV Vsense location in SFLASH. */
#define LSCSA_AMP1_ERR_SIGN                     (*(volatile uint8_t *)(0x0ffff2a0u))
#define LSCSA_AMP1_ERR_VAL                      (*(volatile uint8_t *)(0x0ffff2a1u))
#define LSCSA_AMP2_ERR_SIGN                     (*(volatile uint8_t *)(0x0ffff2a2u))
#define LSCSA_AMP2_ERR_VAL                         (*(volatile uint8_t *)(0x0ffff2a3u))

/* Default RSENSE value is 5mOhm. */
#define LSCSA_DEF_RSENSE_P0                     (50u)

/* Default RSENSE value is 5mOhm. */
#define LSCSA_DEF_RSENSE_P1                     (50u)

/** VBus current usage = 1.0 A. */
#define CY_USBPD_I_1A                           (100u)

/** VBus current usage = 2.0 A. */
#define CY_USBPD_I_2A                           (200u)

/** VBus current usage = 3.0 A. */
#define CY_USBPD_I_3A                           (300u)

/** VBus current usage = 4.0 A. */
#define CY_USBPD_I_4A                           (400u)

/** VBus current usage = 5.0 A. */
#define CY_USBPD_I_5A                           (500u)

#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))

/* Maximum CC VREF value allowed*/
#define CC_VREF_VALUE_MAX                       (199u)

/* VREF voltage step size in mV. */
#define VREF_VOLT_STEP            (10u)

/* Minimum VREF allowed in mV */
#define VREF_VOLT_MIN             (130u)

/* 
 * Range of VSense supported by the CSA in 100uV units.
 * Keeping gain of 150 as max gain.
 * And gain of 40 as min gain for VOUT_MON and VOUT_CBL.
 * Vsense=75 with gain=150 corresponds to 1.5A.
 */
#define CSA_VSENSE_MIN            (10u)
#define CSA_VSENSE_MAX            (600u)
#define CSA_GAIN_150_VSENSE_MAX   (75u)

#define CSA_GAIN_VALUE_LOW                      (40u)
#define CSA_GAIN_VALUE_HIGH                     (150u)

/*
 * IBTR step width is in uS, each IBTR (refgen) step is 10mA.
 */
#define IBTR_STEP_WIDTH                         (200u)

/*
 *  CCG7D/CCG7S CC/CV entry/exit debounce window in ms.
 */
#define VBUS_CF_CC_CV_DEBOUNCE_MS           (3u)

/* CCG7D VBUS_MON selection from CSA to ADC */
#define AMUX_ADC_CCG7X_VBUS_MON_SEL         (4u)

#endif /*(defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) */

/*******************************************************************************
* Function Name: Cy_USBPD_Calc_Cabl_Gain
****************************************************************************//**
*
* Calculates cable gain
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \param cur
* Current
*
* \param gain_sel
*  Cable gain
*
*******************************************************************************/
void Cy_USBPD_Calc_Cabl_Gain(cy_stc_usbpd_context_t *context, uint32_t cur, uint8_t *gain_sel)
{
#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
    uint32_t vsense = ((cur * context->vbusCsaRsense) + (100u >> 1)) / 100u;
    PPDSS_REGS_T pd =  context->base;
    uint32_t state;
    uint8_t gain;

    state = Cy_SysLib_EnterCriticalSection();
    /*
     * Vsense is now stored in 100uV units as the Rsense value is in 0.1mOhms.
     * The scale value of 10X is retained for better accuracy without float.
     */

    /* Adjust Vsense against min and max. */
    vsense = CY_USBPD_GET_MIN(vsense, CSA_VSENSE_MAX);
    vsense = CY_USBPD_GET_MAX(vsense, CSA_VSENSE_MIN);

    /* Identify the gain settings. */
    if (vsense <= CSA_GAIN_150_VSENSE_MAX)
    {
        gain = CSA_GAIN_VALUE_HIGH;
        pd->csa_scp_1_ctrl = (pd->csa_scp_1_ctrl & 
                ~(CSA_VOUT_CBL_GAIN_MASK << PDSS_CSA_SCP_1_CTRL_T_CSA_SCP_EXT_POS)) |
                 (CSA_VOUT_CBL_GAIN_SEL_HIGH << PDSS_CSA_SCP_1_CTRL_T_CSA_SCP_EXT_POS);
    }
    else
    {
        gain = CSA_GAIN_VALUE_LOW;
        pd->csa_scp_1_ctrl = (pd->csa_scp_1_ctrl & 
                ~(CSA_VOUT_CBL_GAIN_MASK << PDSS_CSA_SCP_1_CTRL_T_CSA_SCP_EXT_POS)) |
                 (CSA_VOUT_CBL_GAIN_SEL_LOW << PDSS_CSA_SCP_1_CTRL_T_CSA_SCP_EXT_POS);
    }

    Cy_SysLib_ExitCriticalSection (state);

    *gain_sel = gain;

#else
    CY_UNUSED_PARAMETER(context);
    CY_UNUSED_PARAMETER(cur);
    CY_UNUSED_PARAMETER(gain_sel);
#endif /* (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) */
}
/*******************************************************************************
* Function Name: Cy_USBPD_CSA_Calc_Ref
****************************************************************************//**
*
* Calculates Vref Voltage
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \param cur_10mA
* Current
*
* \param gain
* Gain
*
* \param vref_sel
* VREF Voltage
*
* \param vin_rsense
* VIN Rsense
*
*******************************************************************************/
void Cy_USBPD_CSA_Calc_Ref(cy_stc_usbpd_context_t *context, uint32_t cur_10mA, uint8_t gain, uint32_t *vref_sel, bool vin_rsense)
{
#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
    uint32_t vref;
    uint32_t vsense;

    /*REVIEW */
    if (vin_rsense == true)
    {
        vsense = CY_USBPD_DIV_ROUND_NEAREST((cur_10mA * context->peak_current_sense_resistor), 100u);
    }
    else
    {
        vsense = CY_USBPD_DIV_ROUND_NEAREST((cur_10mA * context->vbusCsaRsense), 100u);
    }

    /*
     * Vsense is now stored in 100uV units as the Rsense value is in 0.1mOhms.
     * The scale value of 10X is retained for better accuracy without float.
     */

    /* 
     * Calculate ideal Vref. Considering 10x divider factor which was
     * maintained for accuracy.
     */
    vref = CY_USBPD_DIV_ROUND_NEAREST((vsense * gain), 10u);

    /* Minimum Vref allowed is 130mV. So adjust for it to prevent underflow. */
    vref = CY_USBPD_GET_MAX(vref, VREF_VOLT_MIN);

    *vref_sel = (uint8_t)CY_USBPD_DIV_ROUND_NEAREST((vref - VREF_VOLT_MIN), VREF_VOLT_STEP);
#else
    CY_UNUSED_PARAMETER(context);
    CY_UNUSED_PARAMETER(cur_10mA);
    CY_UNUSED_PARAMETER(gain);
    CY_UNUSED_PARAMETER(vref_sel);
    CY_UNUSED_PARAMETER(vin_rsense);
#endif /* (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) */
}

/*******************************************************************************
* Function Name: Cy_USBPD_PFC_StopComp
****************************************************************************//**
*
* Disables PFC Comparator
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
*******************************************************************************/
void Cy_USBPD_PFC_StopComp(cy_stc_usbpd_context_t *context)
{
#if (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
    PPDSS_REGS_T pd = context->base;
    uint32_t state;

    state = Cy_SysLib_EnterCriticalSection();

    /* Disable comparator and reference. */
    pd->comp_ctrl[CY_USBPD_VBUS_COMP_ID_LSCSA_PFC] = PDSS_COMP_CTRL_COMP_PD;
    pd->refgen_2_ctrl &= ~(PDSS_REFGEN_2_CTRL_SEL6_POS);

    /* Disable filter. */
    pd->intr5_filter_cfg[CY_USBPD_VBUS_FILTER_ID_LSCSA_PFC] &= ~(PDSS_INTR5_FILTER_CFG_FILT_EN |
        PDSS_INTR5_FILTER_CFG_FILT_CFG_MASK | PDSS_INTR5_FILTER_CFG_FILT_SEL_MASK |
        PDSS_INTR5_FILTER_CFG_FILT_BYPASS);

    /* Disable interrupt. */
    pd->intr5_mask &= ~(1u << CY_USBPD_VBUS_FILTER_ID_LSCSA_PFC);
    pd->intr5 = 1u << CY_USBPD_VBUS_FILTER_ID_LSCSA_PFC;

#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
    context->cableStat.vbusCblGain = 0;
#endif /* (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) */

    Cy_SysLib_ExitCriticalSection (state);
#else
    CY_UNUSED_PARAMETER(context);
#endif /* (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) */
}
/*******************************************************************************
* Function Name: Cy_USBPD_SR_StopComp
****************************************************************************//**
*
* Disables SR Comparator.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
*******************************************************************************/
void Cy_USBPD_SR_StopComp(cy_stc_usbpd_context_t *context)
{
#if (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
    PPDSS_REGS_T pd = context->base;
    uint32_t state;

    state = Cy_SysLib_EnterCriticalSection();

    /* Disable comparator and reference. */
#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
    pd->comp_ctrl[CY_USBPD_VBUS_FILTER_ID_LSCSA_SR] |= PDSS_COMP_CTRL_COMP_PD;
#else
    pd->comp_tr_ctrl = PDSS_COMP_CTRL_COMP_PD;
#endif /*(defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) */
    
    pd->refgen_3_ctrl &= ~(PDSS_REFGEN_3_CTRL_SEL8_POS);

    /* Disable filter. */
    pd->intr5_filter_cfg[CY_USBPD_VBUS_FILTER_ID_LSCSA_SR] &= ~(PDSS_INTR5_FILTER_CFG_FILT_EN |
        PDSS_INTR5_FILTER_CFG_FILT_CFG_MASK | PDSS_INTR5_FILTER_CFG_FILT_SEL_MASK |
        PDSS_INTR5_FILTER_CFG_FILT_BYPASS);

    /* Disable interrupt. */
    pd->intr5_mask &= ~(1u << CY_USBPD_VBUS_FILTER_ID_LSCSA_SR);
    pd->intr5 = 1u << CY_USBPD_VBUS_FILTER_ID_LSCSA_SR;

#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
    context->cableStat.vbusCblGain = 0;
#endif /* (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) */

    Cy_SysLib_ExitCriticalSection (state);
#else
    CY_UNUSED_PARAMETER(context);
#endif /* (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) */
}
/*******************************************************************************
* Function Name: Cy_USBPD_PFC_SetComp
****************************************************************************//**
*
* Sets PFC Comparator
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \param cur
* Current
*
* \param edge
* Edge detection interrupt
*
* \param cbk
* Callback
*
* \return bool
* Returns true if PFC comparator is set 
*
*******************************************************************************/
bool Cy_USBPD_PFC_SetComp(cy_stc_usbpd_context_t *context, uint32_t cur,
        cy_usbpd_vbus_filter_edge_detect_cfg_t edge, cy_pd_cmp_cbk_t cbk)
{
#if (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
    uint32_t regval;
#if  !(defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
    uint8_t gain_sel;
#endif /* (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) */
    uint32_t state,vref_sel;
    PPDSS_REGS_T pd = context->base;

    state = Cy_SysLib_EnterCriticalSection();

    context->pfcCmpCbk = cbk;

    /* Configure the comparator to always use refgen sel6 */
    pd->refgen_sel6_sel8_ctrl |= PDSS_REFGEN_SEL6_SEL8_CTRL_PFC_SEL6;

#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
    if(context->cableStat.vbusCblGain ==0u)
    {
        Cy_USBPD_Calc_Cabl_Gain(context,cur,&(context->cableStat.vbusCblGain));
    }
    Cy_USBPD_CSA_Calc_Ref(context, cur, context->cableStat.vbusCblGain, &vref_sel, false);

    /* Apply 20CSA trim */
    vref_sel += (uint8_t)(((context->trimsConfig.offset_20csa * context->cableStat.vbusCblGain) +
        (1000u >> 1)) / 1000u);
    
    /* Enable CSA */
    pd->csa_scp_0_ctrl &= ~PDSS_CSA_SCP_0_CTRL_PD_CSA;


#else
    /* Calculate the gain and reference settings based on the current. */
    Cy_USBPD_LSCSA_Calc_Cfg(context, cur, &gain_sel, &vref_sel);
    
    (void)Cy_USBPD_LSCSA_Config(context, CY_USBPD_VBUS_LSCSA_PFC_OFF_CONFIG, gain_sel);
     PDSS->lscsa_1_ctrl &= ~PDSS_LSCSA_1_CTRL_LSCSA_PD;
#endif /* (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) */

    /* Configure Reference for comparator. */
    regval = pd->refgen_2_ctrl;
    regval &= ~(PDSS_REFGEN_2_CTRL_SEL6_MASK);
    regval |= (((uint32_t)vref_sel) << PDSS_REFGEN_2_CTRL_SEL6_POS);
    pd->refgen_2_ctrl = regval;
    

    /* Enable Comparator. */
    regval = pd->comp_ctrl[CY_USBPD_VBUS_COMP_ID_LSCSA_PFC] & ~PDSS_COMP_CTRL_COMP_PD;
    regval |= PDSS_COMP_CTRL_COMP_ISO_N;
    pd->comp_ctrl[CY_USBPD_VBUS_COMP_ID_LSCSA_PFC] = regval;
    Cy_SysLib_DelayUs(10);

    /* Setup the filter. */
    pd->intr5_filter_cfg[CY_USBPD_VBUS_FILTER_ID_LSCSA_PFC] &= ~(
        PDSS_INTR5_FILTER_CFG_FILT_EN |
        PDSS_INTR5_FILTER_CFG_FILT_CFG_MASK |
        PDSS_INTR5_FILTER_CFG_FILT_RESET |
        PDSS_INTR5_FILTER_CFG_FILT_SEL_MASK |
        PDSS_INTR5_FILTER_CFG_FILT_BYPASS);

    /* Set edge detection. */
    regval = ((((uint32_t)edge) << PDSS_INTR5_FILTER_CFG_FILT_CFG_POS) |
            (31u << PDSS_INTR5_FILTER_CFG_FILT_SEL_POS) |
            PDSS_INTR5_FILTER_CFG_FILT_EN);
    if (edge == CY_USBPD_VBUS_FILTER_CFG_POS_DIS_NEG_EN)
    {
        regval |= PDSS_INTR5_FILTER_CFG_FILT_RESET;
    }
    pd->intr5_filter_cfg[CY_USBPD_VBUS_FILTER_ID_LSCSA_PFC] |= regval;

    /* Enable the interrupt only if the callback is registered. */
    if (cbk != NULL)
    {
        /* Clear interrupt. */
        pd->intr5 = (((uint32_t)1u) << CY_USBPD_VBUS_FILTER_ID_LSCSA_PFC);
        /* Enable interrupt. */
        pd->intr5_mask |= (((uint32_t)1u) << CY_USBPD_VBUS_FILTER_ID_LSCSA_PFC);
    }
    else
    {
        /* Disable interrupt. */
        pd->intr5_mask &= ~(((uint32_t)1u) << CY_USBPD_VBUS_FILTER_ID_LSCSA_PFC);
        /* Clear interrupt. */
        pd->intr5 = (((uint32_t)1u) << CY_USBPD_VBUS_FILTER_ID_LSCSA_PFC);
    }

    Cy_SysLib_ExitCriticalSection(state);

    return ((bool)((pd->intr5_status_0 >> CY_USBPD_VBUS_FILTER_ID_LSCSA_PFC) & 0x01u));
#else
    CY_UNUSED_PARAMETER(context);
    CY_UNUSED_PARAMETER(cur);
    CY_UNUSED_PARAMETER(edge);
   (void)(cy_pd_cmp_cbk_t)cbk;
    return false;
#endif /* (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))) */
}
/*******************************************************************************
* Function Name: Cy_USBPD_SR_SetComp
****************************************************************************//**
*
* Sets SR Comparator
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \param cur
* Current
*
* \param edge
* Edge detection interrupt
*
* \param cbk
* Callback
*
* \return bool
* Returns true if SR comparator is set 
*
*******************************************************************************/
bool Cy_USBPD_SR_SetComp(cy_stc_usbpd_context_t *context, uint32_t cur,
        cy_usbpd_vbus_filter_edge_detect_cfg_t edge, cy_pd_cmp_cbk_t cbk)
{
#if (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
    uint32_t regval;
#if  !(defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
    uint8_t gain_sel;
#endif /* (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) */
    uint32_t state, vref_sel;
    PPDSS_REGS_T pd = context->base;
    state = Cy_SysLib_EnterCriticalSection();

    context->srCmpCbk = cbk;

    /* Configure the comparator to always use refgen sel8 */
    pd->refgen_sel6_sel8_ctrl |= PDSS_REFGEN_SEL6_SEL8_CTRL_SR_SEL8;

#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
    /* Calculate the gain and reference settings based on the current. */
    if (context->cableStat.vbusCblGain==0u)
    {
        Cy_USBPD_Calc_Cabl_Gain(context, cur, &(context->cableStat.vbusCblGain));
    }
    Cy_USBPD_CSA_Calc_Ref(context, cur, context->cableStat.vbusCblGain, &vref_sel, false);

    /* Apply 20CSA trim */
   vref_sel += (uint8_t)(((context->trimsConfig.offset_20csa * context->cableStat.vbusCblGain) +
        (1000u >> 1)) / 1000u);
    
    /* Enable CSA */
    pd->csa_scp_0_ctrl &= ~PDSS_CSA_SCP_0_CTRL_PD_CSA;

    /* Enable Comparator. */
    regval = pd->comp_ctrl[CY_USBPD_VBUS_COMP_ID_LSCSA_SR] & ~PDSS_COMP_CTRL_COMP_PD;
    regval |= PDSS_COMP_CTRL_COMP_ISO_N;
    pd->comp_ctrl[CY_USBPD_VBUS_COMP_ID_LSCSA_SR] = regval;
    Cy_SysLib_DelayUs(10);
#else /* CCGx */

    /* Calculate the gain and reference settings based on the current. */
    Cy_USBPD_LSCSA_Calc_Cfg(context, cur, &gain_sel, &vref_sel);
    (void)Cy_USBPD_LSCSA_Config(context, CY_USBPD_VBUS_LSCSA_SR_OFF_CONFIG, gain_sel);
    
    /* Enable CSA */
    PDSS->lscsa_1_ctrl &= ~PDSS_LSCSA_1_CTRL_LSCSA_PD;

    /* Enable Comparator. */
    regval = pd->comp_tr_ctrl & ~PDSS_COMP_CTRL_COMP_PD;
    regval |= PDSS_COMP_CTRL_COMP_ISO_N;
    pd->comp_tr_ctrl = regval;
#endif /* (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) */

    /* Configure Reference for comparator. */
    CY_USBPD_REG_FIELD_UPDATE(pd->refgen_3_ctrl, PDSS_REFGEN_3_CTRL_SEL8, (uint32_t)vref_sel);
    
    /* Set up the filter. */
    pd->intr5_filter_cfg[CY_USBPD_VBUS_FILTER_ID_LSCSA_SR] &= ~(
        PDSS_INTR5_FILTER_CFG_FILT_EN |
        PDSS_INTR5_FILTER_CFG_FILT_CFG_MASK |
        PDSS_INTR5_FILTER_CFG_FILT_RESET |
        PDSS_INTR5_FILTER_CFG_FILT_SEL_MASK |
        PDSS_INTR5_FILTER_CFG_FILT_BYPASS);

    /* Set edge detection. */
    regval = ((((uint32_t)edge) << PDSS_INTR5_FILTER_CFG_FILT_CFG_POS) |
            (31u << PDSS_INTR5_FILTER_CFG_FILT_SEL_POS) |
            PDSS_INTR5_FILTER_CFG_FILT_EN);
    if (edge == CY_USBPD_VBUS_FILTER_CFG_POS_DIS_NEG_EN)
    {
        regval |= PDSS_INTR5_FILTER_CFG_FILT_RESET;
    }
    pd->intr5_filter_cfg[CY_USBPD_VBUS_FILTER_ID_LSCSA_SR] |= regval;
    Cy_SysLib_DelayUs(10);

    /* Enable the interrupt only if the callback is registered. */
    if (cbk != NULL)
    {
        /* Clear interrupt. */
        pd->intr5 = (((uint32_t)1u) << CY_USBPD_VBUS_FILTER_ID_LSCSA_SR);
        /* Enable interrupt. */
        pd->intr5_mask |= (((uint32_t)1u) << CY_USBPD_VBUS_FILTER_ID_LSCSA_SR);
    }
    else
    {
        /* Disable interrupt. */
        pd->intr5_mask &= ~(((uint32_t)1u) << CY_USBPD_VBUS_FILTER_ID_LSCSA_SR);
        /* Clear interrupt. */
        pd->intr5 = (((uint32_t)1u) << CY_USBPD_VBUS_FILTER_ID_LSCSA_SR);
    }

    Cy_SysLib_ExitCriticalSection (state);

    return ((bool)((pd->intr5_status_0 >> CY_USBPD_VBUS_FILTER_ID_LSCSA_SR) & 0x01u));
#else
    CY_UNUSED_PARAMETER(context);
    CY_UNUSED_PARAMETER(cur);
    CY_UNUSED_PARAMETER(edge);
   (void)(cy_pd_cmp_cbk_t)cbk;
    return false;
#endif /* (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) */
}
/*******************************************************************************
* Function Name: Cy_USBPD_Adc_VoltToLevel
****************************************************************************//**
*
* Sample the VBus current using ADC. 
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
*
* \return uint16_t
* Returns sampled current
*
*******************************************************************************/
uint16_t Cy_USBPD_Hal_MeasureCur(cy_stc_usbpd_context_t *context)
{
    uint16_t current = 0;
#if (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2) || defined(CY_DEVICE_PAG1S) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S))
    /* Sample the VBus current using ADC. */
    uint8_t gain;
    cy_en_usbpd_adc_id_t adc;
    PPDSS_REGS_T pd = context->base;
    uint32_t regval;
    uint32_t state;

    state = Cy_SysLib_EnterCriticalSection();

    /* Ensure that LSCSA block is enabled. */
#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S))
    pd->csa_scp_0_ctrl &= ~PDSS_CSA_SCP_0_CTRL_PD_CSA;
#else /* CCGx */
    pd->lscsa_1_ctrl &= ~PDSS_LSCSA_1_CTRL_LSCSA_PD;
#endif /* defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) */

    /* Connect the PFC_ON to ADC. */
#ifdef CY_DEVICE_PAG1S
    /* Connect ADC_0 to global AMUX_B having ADFT setting of PFC_ON signal */
    pd_disconnect_vbus_div_from_amux(port);
    adc = CY_USBPD_ADC_ID_0;
#elif (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S))
    /* Connect ADC_0 to internal AMUX having VBUS_MON signal */
    adc = CY_USBPD_ADC_ID_0;
#else /* CCG3PA, CCG3PA2 */
    /* 
     * ADC_0 does not have path for VOUT through any AMUX.
     * But, ADC_1 is hard wired to ADFT setting of PFC_ON signal.
     */
    adc = CY_USBPD_ADC_ID_1;
#endif /* CCGx */

#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S))
    /* Select VBUS_MON for ADC measurement */
    pd->amux_ctrl |= (1u << AMUX_ADC_CCG7X_VBUS_MON_SEL);

    /* By default, use the high gain setting. */
    gain = CSA_GAIN_VALUE_HIGH;
    pd->csa_scp_1_ctrl = (pd->csa_scp_1_ctrl & 
            ~(CSA_VOUT_MON_GAIN_MASK << PDSS_CSA_SCP_1_CTRL_T_CSA_SCP_EXT_POS)) |
             (CSA_VOUT_MON_GAIN_SEL_HIGH << PDSS_CSA_SCP_1_CTRL_T_CSA_SCP_EXT_POS);
#else /* CCGx */
    /* Setup the ADFT for measuring the out_pfc_on:
     * 1 = scp, 2 = ocp, 3 = pfc_on, 4 = pfc_off, 5 = sr_on, 6 sr_off, 7 ea
     * Since out_pfc_on is not used for any operation, it is best suited
     * for this.
     */
    CY_USBPD_REG_FIELD_UPDATE(pd->lscsa_1_ctrl, PDSS_LSCSA_1_CTRL_LSCSA_ATSTCFG, ((uint32_t)3u));

    /* By default, use the gain setting of 125. */
    gain = 125u;
    (void)Cy_USBPD_LSCSA_Config(context, CY_USBPD_VBUS_LSCSA_PFC_ON_CONFIG, LSCSA_AV_SEL_125);
#endif /* defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) */
    Cy_SysLib_DelayUs(50);

    /* Measure the amplified Vsense. */
    regval = (uint32_t)Cy_USBPD_Adc_Sample(context, adc, CY_USBPD_ADC_INPUT_AMUX_B);
    regval = (uint32_t)Cy_USBPD_Adc_LevelToVolt(context, adc, (uint8_t)regval);

    if (regval > LSCSA_GAIN_MAX_VALUE)
    {
#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S))
        gain = CSA_GAIN_VALUE_LOW;
        pd->csa_scp_1_ctrl = (pd->csa_scp_1_ctrl & 
                ~(CSA_VOUT_MON_GAIN_MASK << PDSS_CSA_SCP_1_CTRL_T_CSA_SCP_EXT_POS)) |
                 (CSA_VOUT_MON_GAIN_SEL_LOW << PDSS_CSA_SCP_1_CTRL_T_CSA_SCP_EXT_POS);
#else /* CCGx */
        gain = 35u;
        (void)Cy_USBPD_LSCSA_Config(context, CY_USBPD_VBUS_LSCSA_PFC_ON_CONFIG, LSCSA_AV_SEL_35);
#endif /* defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) */
        Cy_SysLib_DelayUs(50);
        regval = (uint32_t)Cy_USBPD_Adc_Sample(context, adc, CY_USBPD_ADC_INPUT_AMUX_B);
        regval = (uint32_t)Cy_USBPD_Adc_LevelToVolt(context, adc, (uint8_t)regval);
    }

#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S))
    /* Apply 20CSA trims */
    uint16_t offset = (((context->trimsConfig.offset_20csa * gain) + (100u >> 1)) / 100u);
    regval = (regval > offset) ? (regval - offset) : 0u;
#endif /* defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) */

    regval = (((regval * 1000u) + (((uint32_t)context->vbusCsaRsense * gain) >> 1)) / 
        ((uint32_t)context->vbusCsaRsense * gain));

    /* Revert the ADFT and MUX configurations. */
#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S))
    pd->amux_ctrl &= ~(1u << AMUX_ADC_CCG7X_VBUS_MON_SEL);
#else /* CCGx */
    CY_USBPD_REG_FIELD_UPDATE(pd->lscsa_1_ctrl, PDSS_LSCSA_1_CTRL_LSCSA_ATSTCFG, 0u);
#endif /* (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S)) */
#ifdef CY_DEVICE_PAG1S
    pd_connect_vbus_div_to_amux(port);
#endif /* PAG1S */
    Cy_SysLib_DelayUs(10);

    Cy_SysLib_ExitCriticalSection(state);

    current = (uint16_t)regval;

#else
    CY_UNUSED_PARAMETER(context);
#endif /* CCGx */
    return current;
}
/*******************************************************************************
* Function Name: Cy_USBPD_Hal_Disable_CV
****************************************************************************//**
*
* Disables CV
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
*
*******************************************************************************/
void Cy_USBPD_Hal_Disable_CV(cy_stc_usbpd_context_t *context)
{
#if defined(CY_DEVICE_CCG3PA)
    PPDSS_REGS_T pd = context->base;
    pd->ea_ctrl &= ~(PDSS_EA_CTRL_EN_CV | PDSS_EA_CTRL_ISRC_EN |
            PDSS_EA_CTRL_ISNK_EN | PDSS_EA_CTRL_ISRC_DAC_CTRL_MASK |
            PDSS_EA_CTRL_ISNK_DAC_CTRL_MASK);
#elif (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
    PPDSS_REGS_T pd = context->base;
    pd->bb_ea_3_ctrl &= ~(PDSS_BB_EA_3_CTRL_BB_ISNK_DAC_CTRL_MASK | PDSS_BB_EA_3_CTRL_BB_ISRC_DAC_CTRL_MASK);
    pd->bb_ea_0_ctrl &= ~(PDSS_BB_EA_0_CTRL_BB_EA_EN_CV | PDSS_BB_EA_0_CTRL_BB_EA_EN_CVAMP |
                          PDSS_BB_EA_0_CTRL_BB_EA_ISNK_EN | PDSS_BB_EA_0_CTRL_BB_EA_ISRC_EN);
#else
    CY_UNUSED_PARAMETER(context);
#endif /* defined(CY_DEVICE_CCG3PA) */

#if (PSVP_FPGA_ENABLE)
#if (!defined(CY_DEVICE_CCG6DF_CFP))
    /* Ensure that the voltage drops to 5V. */
    ctrl_inf_set_idac(0);
#endif /* (!defined(CY_DEVICE_CCG6DF_CFP)) */
#endif /* PSVP_FPGA_ENABLE */
}
/*******************************************************************************
* Function Name: Cy_USBPD_Hal_Enable_CV
****************************************************************************//**
*
* Enables CV
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
*
*******************************************************************************/
void Cy_USBPD_Hal_Enable_CV(cy_stc_usbpd_context_t *context)
{
#if defined(CY_DEVICE_CCG3PA)
    uint32_t regval;
    PPDSS_REGS_T pd = context->base;
    regval = pd->ea_ctrl & ~(PDSS_EA_CTRL_ISNK_EN | PDSS_EA_CTRL_ISRC_EN |
            PDSS_EA_CTRL_ISRC_DAC_CTRL_MASK | PDSS_EA_CTRL_ISNK_DAC_CTRL_MASK);
    pd->ea_ctrl = (regval | PDSS_EA_CTRL_EN_CV);
#elif (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
    uint32_t regval;
    PPDSS_REGS_T pd = context->base;

    pd->bb_ea_3_ctrl &= ~(PDSS_BB_EA_3_CTRL_BB_ISNK_DAC_CTRL_MASK |
        PDSS_BB_EA_3_CTRL_BB_ISRC_DAC_CTRL_MASK);
    regval = pd->bb_ea_0_ctrl & ~(PDSS_BB_EA_0_CTRL_BB_EA_ISRC_EN);

    /*
     * CCG7D has a shared node between PDAC and NDAC. So toggling NDAC results
     * in fluctuations in output voltages. Hence we need to keep this ON
     * all the time.
     */
    regval |= PDSS_BB_EA_0_CTRL_BB_EA_ISNK_EN;

    pd->bb_ea_0_ctrl = (regval | PDSS_BB_EA_0_CTRL_BB_EA_EN_CV |
        PDSS_BB_EA_0_CTRL_BB_EA_EN_CVAMP |
        PDSS_BB_EA_0_CTRL_BB_EA_EN_CCAMP);

    /*
     * CCAMP is enabled by default to make EA faster.
     * Hence, set CC reference to a maximum value while enabling CV.
     * In PPS mode, CC reference shall be set by CF enable.
     * and use minimum gain.
     */
    CY_USBPD_REG_FIELD_UPDATE(pd->refgen_3_ctrl, PDSS_REFGEN_3_CTRL_SEL10, (uint32_t)CC_VREF_VALUE_MAX);
    CY_USBPD_REG_FIELD_UPDATE(pd->csa_scp_0_ctrl, PDSS_CSA_SCP_0_CTRL_AV1, (uint32_t)1u);
#else    
    CY_UNUSED_PARAMETER(context);
#endif /* defined(CY_DEVICE_CCG3PA) */
}
/*******************************************************************************
* Function Name: Cy_USBPD_Get_Silicon_Rev
****************************************************************************//**
*
* Function to get silicon revision.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
*
* \return uint8_t
* Silicon revision
*
*******************************************************************************/
uint8_t Cy_USBPD_Get_Silicon_Rev(cy_stc_usbpd_context_t *context)
{
    CY_UNUSED_PARAMETER(context);
    uint8_t si_revision;
    /* Silicon revision is stored in core-sight tables.
    * Major revision = ROMTABLE_PID2(7:4)
    * Minor revision = ROMTABLE_PID3(7:4) */
    si_revision = (uint8_t)((ROMTABLE_PID2) & 0xF0u);
    si_revision |= (uint8_t)(((ROMTABLE_PID3) & 0xF0u) >> 4u);
    si_revision= si_revision-CCG_SILICON_REV00_VALUE;
    return (si_revision);
}
/*******************************************************************************
* Function Name: Cy_USBPD_Hal_Get_Fb_Dac
****************************************************************************//**
*
* Read Feedback DAC control of device.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \return int16_t
* Signed DAC value. Positive is sink and negative is source.
*
*******************************************************************************/
int16_t Cy_USBPD_Hal_Get_Fb_Dac(cy_stc_usbpd_context_t *context)
{
#if defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1) || defined(CY_DEVICE_CCG7D)    
    int16_t src_dac, snk_dac;
    PPDSS_REGS_T pd = context->base;
    uint32_t regval;

    regval = (pd->bb_ea_3_ctrl & PDSS_BB_EA_3_CTRL_BB_ISRC_DAC_CTRL_MASK) >>
        PDSS_BB_EA_3_CTRL_BB_ISRC_DAC_CTRL_POS;
    src_dac = (int16_t)regval;
    regval = (pd->bb_ea_3_ctrl & PDSS_BB_EA_3_CTRL_BB_ISNK_DAC_CTRL_MASK) >>
        PDSS_BB_EA_3_CTRL_BB_ISNK_DAC_CTRL_POS;
    snk_dac = (int16_t)regval;

    return (snk_dac - src_dac);
#else
    CY_UNUSED_PARAMETER(context);
    return 0;
#endif
}
/*******************************************************************************
* Function Name: Cy_USBPD_Hal_Set_Fb_Dac
****************************************************************************//**
*
* Configure Feedback DAC control of device.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \param dac_value
* Signed DAC value. Positive is sink and negative is source.
*
*
*******************************************************************************/
void Cy_USBPD_Hal_Set_Fb_Dac(cy_stc_usbpd_context_t *context, int16_t dac_value)
{
#if defined(CY_DEVICE_CCG3PA)    
    uint32_t tmp;
    int16_t ndac;    
    PPDSS_REGS_T pd = context->base;
    tmp = pd->ea_ctrl & ~(
            PDSS_EA_CTRL_ISRC_DAC_CTRL_MASK |
            PDSS_EA_CTRL_ISNK_DAC_CTRL_MASK |
            PDSS_EA_CTRL_ISRC_EN |
            PDSS_EA_CTRL_ISNK_EN);

#if (VBUS_CTRL_TYPE_P1 == VBUS_CTRL_DIR_FB)
    PPDSS_TRIMS_REGS_T trimRegs = context->trimsBase;
#endif /* (VBUS_CTRL_TYPE_P1 == VBUS_CTRL_DIR_FB) */

    if(dac_value >= 0)
    {
        tmp |= (((uint32_t)dac_value << PDSS_EA_CTRL_ISNK_DAC_CTRL_POS) &
                PDSS_EA_CTRL_ISNK_DAC_CTRL_MASK);

        /* Enable only for non-zero value. */
        if(dac_value != 0)
        {
            tmp |= PDSS_EA_CTRL_ISNK_EN;
        }

#if (VBUS_CTRL_TYPE_P1 == VBUS_CTRL_DIR_FB)
#ifndef PAG1S
        if (Cy_USBPD_Get_Silicon_Rev(context) != 0)
        {
            trimRegs->trim_ea1_0 = EA_IREF_GAIN_NDAC;
        }
#else
        trimRegs->trim_pds_ea = EA_IREF_GAIN_NDAC;
#endif /* !PAG1S */
#endif /* (VBUS_CTRL_TYPE_P1 == VBUS_CTRL_DIR_FB) */
    }
    else
    {
        ndac = dac_value * -1;
        tmp |= (((((uint32_t)ndac) << PDSS_EA_CTRL_ISRC_DAC_CTRL_POS) &
                PDSS_EA_CTRL_ISRC_DAC_CTRL_MASK) | PDSS_EA_CTRL_ISRC_EN);

#if (VBUS_CTRL_TYPE_P1 == VBUS_CTRL_DIR_FB)
#ifndef PAG1S

        if (Cy_USBPD_Get_Silicon_Rev(context) != 0)
        {
            trimRegs->trim_ea1_0 = EA_IREF_GAIN_PDAC;
        }
#else
        trimRegs->trim_pds_ea = EA_IREF_GAIN_PDAC;
#endif /* !PAG1S */

#endif /* (VBUS_CTRL_TYPE_P1 == VBUS_CTRL_DIR_FB) */
    }
    pd->ea_ctrl = tmp;
#elif (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
    uint32_t regval;
    uint32_t regval2;
    /* QAC suppression 2843: port parameter is ensured to be correct by the caller. */
    PPDSS_REGS_T pd = context->base; /* PRQA S 2843 */

    regval = pd->bb_ea_0_ctrl & ~(
            PDSS_BB_EA_0_CTRL_BB_EA_ISRC_EN);
    regval2 = pd->bb_ea_3_ctrl & ~(
            PDSS_BB_EA_3_CTRL_BB_ISRC_DAC_CTRL_MASK |
            PDSS_BB_EA_3_CTRL_BB_ISNK_DAC_CTRL_MASK);

    if(dac_value >= 0)
    {
        /* QAC suppression 2985: REG_FEILD_UPDATE is a common functional macro that is used to
         * modify a register field without affecting any other bits of the register. When the field
         * starts from bit position 0, the left shift operation is redundant. Yet this operation is
         * retained to keep it generic and compatible for bitfields starting from other bit positions. */
        CY_USBPD_REG_FIELD_UPDATE(regval2, PDSS_BB_EA_3_CTRL_BB_ISNK_DAC_CTRL, (uint32_t)dac_value); /* PRQA S 2985 */

        /* CCG7D needs to leave the ISNK always ON. */
    }
    else
    {
        dac_value = dac_value * -1;
        regval2 |= ((((uint32_t)dac_value) << PDSS_BB_EA_3_CTRL_BB_ISRC_DAC_CTRL_POS) &
                PDSS_BB_EA_3_CTRL_BB_ISRC_DAC_CTRL_MASK);
        regval |= PDSS_BB_EA_0_CTRL_BB_EA_ISRC_EN;
    }

    pd->bb_ea_0_ctrl = regval;
    pd->bb_ea_3_ctrl = regval2;
#else
    CY_UNUSED_PARAMETER(context);
    CY_UNUSED_PARAMETER(dac_value);
#endif /* defined(CY_DEVICE_CCG3PA) */

#if (PSVP_FPGA_ENABLE)
    /*
     * Leave IDAC setting through CTRL_INF as VBTR is taken care
     * through another SCB on AFE side. And CTRL_INF can be used to
     * set IDAC directly for SVS_DEBUG.
     */
#if (!defined(CY_DEVICE_CCG6DF_CFP))
    ctrl_inf_set_idac(dac_value);
#endif /* (!defined(CY_DEVICE_CCG6DF_CFP)) */
#endif /* (PSVP_FPGA_ENABLE) */
}
/*******************************************************************************
* Function Name: Cy_USBPD_LSCSA_Calc_Cfg
****************************************************************************//**
*
* Calculate the gain and reference settings for a specific current
* requirement. This function eliminates the pre-calculated table.
*
* \param context
* USB-PD port context.
*
* \param cur_10mA
* Current setting in 10mA unit for which CSA setting is required.
*
* \param gain_sel
* Pointer to variable where the gain setting code corresponding
* to the current setting needs to be stored.
*
* \param vref_sel
* Pointer to variable where the voltage reference code
* corresponding to the current setting needs to be stored.
*
* \return
* None
*
* <B>Applicable devices:</B> CCG3PA, CCG3PA2, PAG1S.
*
*******************************************************************************/
void Cy_USBPD_LSCSA_Calc_Cfg(cy_stc_usbpd_context_t *context, uint32_t cur_10mA, uint8_t *gain_sel, uint32_t *vref_sel)
{
#if defined(CY_DEVICE_CCG3PA)
    uint8_t gain;
    uint8_t av_sel;
    uint32_t vref;
    bool err_sign;
    uint32_t vsense = (cur_10mA * LSCSA_DEF_RSENSE_P0) / 100u;
    int32_t err_target;

    /*
     * Vsense is now stored in 100uV units as the Rsense value is in 0.1mOhms.
     * The scale value of 10X is retained for better accuracy without float.
     */

    /* Adjust Vsense against min and max. */
    vsense = CY_USBPD_GET_MIN(vsense, LSCSA_VSENSE_MAX);
    vsense = CY_USBPD_GET_MAX(vsense, LSCSA_VSENSE_MIN);

    /* Identify the gain and gain_sel settings. */
    if (vsense <= LSCSA_GAIN_150_VSENSE_MAX)
    {
        gain = 150;
        av_sel = LSCSA_AV_SEL_150;
    }
#if (!LSCSA_SKIP_125_GAIN)
    else if (vsense < LSCSA_GAIN_35_VSENSE_MIN)
    {
        gain = 125;
        av_sel = LSCSA_AV_SEL_125;
    }
#endif /* (!LSCSA_SKIP_125_GAIN) */
    else /* if (vsense >= LSCSA_GAIN_35_VSENSE_MIN) */
    {
        gain = 35;
        av_sel = LSCSA_AV_SEL_35;
    }

    if (gain_sel != NULL)
    {
        *gain_sel = av_sel;
    }

    if (vref_sel != NULL)
    {
        /* Calculate ideal Vref. */
        vref = (vsense * gain) / 10u;

        /* Now apply the error correction algorithm. */

        /*
         * The err_target variable is used for first calculating the error and then
         * calculating the error compensated vref value. The calculations done are
         * described at each step. float calculations are very code size sensitive
         * and so the calculations are done as int.
         */

        /*
         * For vsense < 15mV, the spec error is (20 - vsense); for vsense between 15mV
         * and 20mV, the error is 5%; for vsense between 20mV and 30mV, the error is
         * (7 - 0.1 * vsense)%; for vsense between 30mV and 50mV, the error is speed
         * to (5.5 - 0.05*vsense)%.
         *
         * The err_target is converted to 10X value to allow for division of 10 as int.
         * Since the error variation is very small post 30mV, it does not warrant
         * calculating for division with 20.
         */
        if (vsense < 150u)
        {
            err_target = (200 - (int32_t)vsense);
        }
        else if (vsense < 200u)
        {
            err_target = 50;
        }
        else if (vsense < 300u)
        {
            err_target = (70 - ((int32_t)vsense / 10));
        }
        else
        {
            err_target = 55 - ((int32_t)vsense / 20);
        }

        /*
         * The formulae for Vref_new is as follows:
         * Vref_new = Vref * [1 - (spec error @vsense / spec error at 15mV%) * err @15mV]
         * Since actual error at 15mV is stored in the SFLASH at the specified locations
         * along with the sign. The error % is now calculated based on the available
         * data.
         */
        if ((av_sel & 0x10u) == 0u)
        {
            err_target *= ((int32_t)LSCSA_AMP1_ERR_VAL);
            err_sign = (bool)((uint8_t)LSCSA_AMP1_ERR_SIGN);
        }
        else
        {
            err_target *= ((int32_t)LSCSA_AMP2_ERR_VAL);
            err_sign = (bool)((uint8_t)LSCSA_AMP2_ERR_SIGN);
        }
        if (err_sign)
        {
            err_target *= -1;
        }

        /*
         * To make the calculations better, the 5 (spec error at 15mV) and the divider
         * for % (100) are taken upto the numerator and divided at a higher value.
         * Also, an additional 10X is done to accommodate for the err_target being
         * made 10X in previous calculation.
         */
        err_target = (((50000 - err_target) * (int32_t)vref) / 50000);

        /* Minimum Vref allowed is 130mV. So adjust for it to prevent underflow. */
        err_target = CY_USBPD_GET_MAX(err_target, 130);

        /*
         * err_target now holds the vref_new value in mV. This has to be now converted
         * to register field encoding and returned to the calling function.
         * Vref value can be extracted from the register: vref_sel = (Vref - 130) / 10.
         */
        err_target = ((err_target - 130) / 10);
        *vref_sel = ((uint8_t)err_target);
    }
#else
    CY_UNUSED_PARAMETER(cur_10mA);
    CY_UNUSED_PARAMETER(gain_sel);
    CY_UNUSED_PARAMETER(vref_sel);
#endif /* defined(CY_DEVICE_CCG3PA) */
    CY_UNUSED_PARAMETER(context);
}
/*******************************************************************************
* Function Name: Cy_USBPD_LSCSA_Config
****************************************************************************//**
*
* Sets up LSCSA for specified application.
*
* \param context
* USB-PD port context.
*
* \param lscsa_app
* LSCSA application
*
* \param gain_sel_value
* Gain selection code to be used
*
* \return
* Status.
*
* <B>Applicable devices:</B> CCG3PA, CCG3PA2, PAG1S.
*
*******************************************************************************/
cy_en_usbpd_status_t Cy_USBPD_LSCSA_Config(cy_stc_usbpd_context_t *context, cy_en_usbpd_vbus_lscsa_app_config_t lscsa_app, uint32_t gain_sel_value)
{
#if defined(CY_DEVICE_CCG3PA)
    PPDSS_REGS_T pd = context->base;
    uint32_t regval;
    uint8_t bit_pos;

    /* Ensure LSCSA app value is not out of bounds. */
    if (lscsa_app >= CY_USBPD_VBUS_LSCSA_MAX_CONFIG_VALUE)
    {
        return CY_USBPD_STAT_BAD_PARAM;
    }

    /* Read the current value of register. */
    regval = pd->lscsa_0_ctrl;

    /*
     * lscsa_0_ctrl register contains gain sel values for all applications (lscsa_app).
     * Get the bit position of gain sel value.
     */
    bit_pos = (uint8_t)(((uint8_t)lscsa_app << 2) + (uint8_t)lscsa_app);
    /*
     * gain_sel_value is actually :
     * Bit 0:3: Gain selection code
     * Bit 4: Output Mux select bit
     */
    regval &= ~((uint32_t)0x1Fu << bit_pos);
    regval |= ((gain_sel_value & (uint32_t)0x1Fu) << bit_pos);
    pd->lscsa_0_ctrl = regval;
    return CY_USBPD_STAT_SUCCESS;

#else
    CY_UNUSED_PARAMETER(context);
    CY_UNUSED_PARAMETER(lscsa_app);
    CY_UNUSED_PARAMETER(gain_sel_value);
    return CY_USBPD_STAT_SUCCESS;    
#endif /* defined(CY_DEVICE_CCG3PA) */
}
/*******************************************************************************
* Function Name: Cy_USBPD_PFC_CompSample
****************************************************************************//**
*
* Samples the PFC comparator. The function samples against the
* requested current and restores the previous settings after sampling. This
* function is useful when the comparator is already configured for interrupt
* and needs to be multiplexed to sample at a different current.
*
* \param context
* USB-PD port context.
*
* \param cur
* Operating current in 10mA units.
*
* \return bool
* State of the comparator on sampling.
*
* <B>Applicable devices:</B> CCG3PA, CCG3PA2, PAG1S.
*
*******************************************************************************/
bool Cy_USBPD_PFC_CompSample(cy_stc_usbpd_context_t *context, uint32_t cur)
{
#if defined(CY_DEVICE_CCG3PA)
    uint8_t gain_sel;
    uint32_t vref_sel;
    bool retval = false;
    uint32_t regval, state;
    PPDSS_REGS_T pd = context->base;
    uint32_t reg_refgen_2_ctrl, reg_comp_ctrl;
    uint32_t reg_lscsa_0_ctrl;

    state = Cy_SysLib_EnterCriticalSection();

    /* Configure the comparator to always use refgen sel6 */
    pd->refgen_sel6_sel8_ctrl |= PDSS_REFGEN_SEL6_SEL8_CTRL_PFC_SEL6;
    reg_lscsa_0_ctrl = pd->lscsa_0_ctrl;

    /* Take backup of refgen and comparator settings */
    reg_refgen_2_ctrl = pd->refgen_2_ctrl;
    reg_comp_ctrl = pd->comp_ctrl[CY_USBPD_VBUS_COMP_ID_LSCSA_PFC];

    /* Calculate the gain and reference settings based on the current. */
    Cy_USBPD_LSCSA_Calc_Cfg(context, cur, &gain_sel, &vref_sel);
    (void)Cy_USBPD_LSCSA_Config(context, CY_USBPD_VBUS_LSCSA_PFC_OFF_CONFIG, gain_sel);

    /* Enable CSA */
    pd->lscsa_1_ctrl &= ~PDSS_LSCSA_1_CTRL_LSCSA_PD;

    /* Configure Reference for comparator. */
    regval = pd->refgen_2_ctrl;
    regval &= ~(PDSS_REFGEN_2_CTRL_SEL6_MASK);
    regval |= ((uint32_t)vref_sel << PDSS_REFGEN_2_CTRL_SEL6_POS);
    pd->refgen_2_ctrl = regval;

    /* Enable Comparator. */
    regval = pd->comp_ctrl[CY_USBPD_VBUS_COMP_ID_LSCSA_PFC] & ~PDSS_COMP_CTRL_COMP_PD;
    regval |= PDSS_COMP_CTRL_COMP_ISO_N;
    pd->comp_ctrl[CY_USBPD_VBUS_COMP_ID_LSCSA_PFC] = regval;

    /* Now sample the comparator after 50us. Need to wait one LF clock cycle. */
    Cy_SysLib_DelayUs(50u);
    if (((pd->intr5_status_0 >> (uint8_t)CY_USBPD_VBUS_FILTER_ID_LSCSA_PFC) & 0x01u) != 0u)
    {
        retval = true;
    }

    /* Restore the settings. */
    pd->lscsa_0_ctrl = reg_lscsa_0_ctrl;
    pd->refgen_2_ctrl = reg_refgen_2_ctrl;
    pd->comp_ctrl[CY_USBPD_VBUS_COMP_ID_LSCSA_PFC] = reg_comp_ctrl;
    Cy_SysLib_DelayUs(10);

    /* Reset the filter, if any interrupt was configured. */
    if (((pd->intr5_mask & (1u << (uint8_t)CY_USBPD_VBUS_FILTER_ID_LSCSA_PFC)) != 0u) &&
            ((pd->intr5_filter_cfg[(uint8_t)CY_USBPD_VBUS_FILTER_ID_LSCSA_PFC] & PDSS_INTR5_FILTER_CFG_FILT_EN) != 0u))
    {
        pd->intr5_filter_cfg[CY_USBPD_VBUS_FILTER_ID_LSCSA_PFC] &= ~(
                PDSS_INTR5_FILTER_CFG_FILT_EN |
                PDSS_INTR5_FILTER_CFG_FILT_RESET);

        /* Set edge detection. */
        regval = pd->intr5_filter_cfg[CY_USBPD_VBUS_FILTER_ID_LSCSA_PFC] |
            PDSS_INTR5_FILTER_CFG_FILT_EN;
        if (((regval & PDSS_INTR5_FILTER_CFG_FILT_CFG_MASK) >>
                PDSS_INTR5_FILTER_CFG_FILT_CFG_POS) == (uint32_t)CY_USBPD_VBUS_FILTER_CFG_POS_DIS_NEG_EN)
        {
            regval |= PDSS_INTR5_FILTER_CFG_FILT_RESET;
        }
        pd->intr5_filter_cfg[CY_USBPD_VBUS_FILTER_ID_LSCSA_PFC] |= regval;
    }

    Cy_SysLib_ExitCriticalSection(state);

    return retval;
#else
    CY_UNUSED_PARAMETER(context);
    CY_UNUSED_PARAMETER(cur);
    return false;
#endif /* defined(CY_DEVICE_CCG3PA) */

}
/*******************************************************************************
* Function Name: Cy_USBPD_CF_GetStatus
****************************************************************************//**
*
* Retrieves the status of the CF mode hardware.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
*
* \return uint8_t
* Whether the hardware module is in CF mode or not.
*
*******************************************************************************/
bool Cy_USBPD_CF_GetStatus(cy_stc_usbpd_context_t *context)
{
#if ((defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) && CY_PD_VBUS_CF_EN)
    uint32_t cur;
    PPDSS_REGS_T pd = context->base;

#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
    if (true == context->cfEnStatus)
#else /* !(defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) */
    if ((pd->ea_ctrl & PDSS_EA_CTRL_EN_CC) != 0u)
#endif /* !(defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) */
    {
#if !CCG_CF_HW_DET_ENABLE
        cur = context->cfCur;

        if (context->cfCur > LSCSA_CF_CUR_HIGH_LIMIT)
        {
            cur -= LSCSA_CF_CUR_HIGH_THRES;
        }
        else
        {
            cur -= LSCSA_CF_CUR_THRES;
        }
        return Cy_USBPD_PFC_CompSample(context, cur);
#else /* CCG_CF_HW_DET_ENABLE */
        cur = 0u;
        (void)cur;

        if (pd->intr15_status & PDSS_INTR15_STATUS_CC_FLAG_FILT)
        {
            return true;
        }

        return false;
#endif /* CCG_CF_HW_DET_ENABLE */
    }
    else
    {
        (void)pd;
        return false;
    }
#else
    CY_UNUSED_PARAMETER(context);
    return false;
#endif /* (defined(CY_DEVICE_CCG3PA) && CY_PD_VBUS_CF_EN) */
}
/*******************************************************************************
* Function Name: Cy_USBPD_CF_Mon_Enable
****************************************************************************//**
*
* Enables hardware monitoring for VBus Current foldback on the specified port.
* The function invokes the callback when a change happens from the current state.
* When the monitor is enabled, the calling function can specify the default state
* to allow for both high to low and low to high detection at enable. This avoids
* any race condition while enabling the monitoring. Monitoring should be enabled
* only when no VBUS transition is enabled.
*
* \param context
* USB-PD port context.
*
* \param reset_state
* Current CF state as expected by the calling function.
*
* \param cbk
* Function to be called when CF event is detected.
*
*
* <B>Applicable devices:</B> PAG1S.
*
*******************************************************************************/
void Cy_USBPD_CF_Mon_Enable(cy_stc_usbpd_context_t *context, bool reset_state, cy_vbus_cf_cbk_t cbk)
{
#if CCG_CF_HW_DET_ENABLE
    uint32_t state;
    uint32_t regval;
    PPDSS_REGS_T pd = context->base;

    state = Cy_SysLib_EnterCriticalSection();

    context->cfCbk = cbk;

    /* Configure only if CC mode is enabled. */
#if defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)
    if (true == context->cfEnStatus)
#else /* !(defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) */
    if (pd->ea_ctrl & PDSS_EA_CTRL_EN_CC)
#endif /* !(defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) */
    {
        pd->intr15_cfg_cc_flag &= ~(PDSS_INTR15_CFG_CC_FLAG_CC_FLAG_FILT_EN |
                PDSS_INTR15_CFG_CC_FLAG_CC_FLAG_FILT_RESET);
        regval = pd->intr15_cfg_cc_flag;
        if (reset_state)
        {
            regval |= PDSS_INTR15_CFG_CC_FLAG_CC_FLAG_FILT_RESET;
        }
        regval |= PDSS_INTR15_CFG_CC_FLAG_CC_FLAG_FILT_EN;
        pd->intr15_cfg_cc_flag |= regval;

        if (cbk)
        {
            /* If callback is registered, then enable the interrupt. */
            pd->intr15 = PDSS_INTR15_CC_FLAG_CHANGED;
            pd->intr15_mask |= PDSS_INTR15_CC_FLAG_CHANGED;
        }
    }

    Cy_SysLib_ExitCriticalSection(state);
#else
    CY_UNUSED_PARAMETER(context);
    CY_UNUSED_PARAMETER(reset_state);
    (void)(cy_vbus_cf_cbk_t)(cbk);
#endif /* CCG_CF_HW_DET_ENABLE */    
}
/*******************************************************************************
* Function Name: Cy_USBPD_CF_Mon_Disable
****************************************************************************//**
*
* Disables hardware monitoring for VBus Current foldback on the specified port.
* Monitoring should be disabled when there is VBUS transition as well as when not in
* PPS mode operation.
*
* \param context
* USB-PD port context.
*
* <B>Applicable devices:</B> PAG1S.
*
*******************************************************************************/
void Cy_USBPD_CF_Mon_Disable(cy_stc_usbpd_context_t *context)
{
#if CCG_CF_HW_DET_ENABLE    
    uint32_t state;
    PPDSS_REGS_T pd = context->base;

    state = Cy_SysLib_EnterCriticalSection();

    pd->intr15_mask &= ~PDSS_INTR15_CC_FLAG_CHANGED;
    pd->intr15 = PDSS_INTR15_CC_FLAG_CHANGED;

    context->cfCbk = NULL;

    Cy_SysLib_ExitCriticalSection(state);
#else
    CY_UNUSED_PARAMETER(context);
#endif /* CCG_CF_HW_DET_ENABLE */
}
/*******************************************************************************
* Function Name: Cy_USBPD_CF_Enable
****************************************************************************//**
*
* Enables VBus Current foldback on the specified port.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \param cur
* Operating current in 10mA units.
*
*
*******************************************************************************/
void Cy_USBPD_CF_Enable(cy_stc_usbpd_context_t *context, uint32_t cur)
{
#if ((defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) && CY_PD_VBUS_CF_EN)
    PPDSS_REGS_T pd = context->base;
    uint32_t vref_sel;
#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
    uint8_t vref_1;
    uint8_t vref_2;
    uint32_t cur_1;
    uint8_t vref_diff;
    uint32_t cur_diff;
    uint32_t offset;
    uint16_t max_current;
#else /* CCGx */
    uint8_t gain_sel;
#endif /* CCGx */
    uint32_t regval, state;

    state = Cy_SysLib_EnterCriticalSection();

    context->cfCur = cur;

#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
    /*
     * For 3A application, use fixed gain of 80 across 1A to 3A for accuracy.
     * For 5A application, use fixed gain of 60 across 1A to 5A for range.
     */
#if CY_USE_CONFIG_TABLE
    if (pd_get_ptr_auto_cfg_tbl(context)->max_current > CY_USBPD_I_3A)
#else
    if (context->usbpdConfig->autoConfig->max_current > CY_USBPD_I_3A)
#endif
    {
        CY_USBPD_REG_FIELD_UPDATE(pd->csa_scp_0_ctrl, PDSS_CSA_SCP_0_CTRL_AV1, CC_GAIN_60_AV1_VALUE);
    }
    else
    {
        CY_USBPD_REG_FIELD_UPDATE(pd->csa_scp_0_ctrl, PDSS_CSA_SCP_0_CTRL_AV1, CC_GAIN_80_AV1_VALUE);
    }
#else /* CCGx */

    Cy_USBPD_LSCSA_Calc_Cfg(context, cur, &gain_sel, &vref_sel);
    /* Configure the EA comparator for the current limit mode operation. */
    (void)Cy_USBPD_LSCSA_Config(context, CY_USBPD_VBUS_LSCSA_EA_CONFIG, gain_sel);

#endif /* CCGx */

#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))

#if CY_USE_CONFIG_TABLE
    max_current = pd_get_ptr_auto_cfg_tbl(context)->max_current;
#else
    max_current = context->usbpdConfig->autoConfig->max_current;
#endif

    /* Check if silicon has proper trims and then apply interpolation. */
    if((context->trimsConfig.cc_trim_1a != 0u) &&
       (context->trimsConfig.cc_trim_2a != 0u) &&
       (context->trimsConfig.cc_trim_3a != 0u) &&
       (context->trimsConfig.cc_trim_3a_g2 != 0u) &&
       (context->trimsConfig.cc_trim_4a_g2 != 0u) &&
       (context->trimsConfig.cc_trim_5a_g2 != 0u))
    {
        /* Calculate current for the actual Rsense */
        cur = ((cur * context->vbusCsaRsense) / CSA_IDEAL_RSENSE);

#if (PMG1B1_USB_CHARGER == 0)
        /* 1A is minimum CF reference */
        cur = CY_USBPD_GET_MAX(cur, CY_USBPD_I_1A);
#endif /* PMG1B1_USB_CHARGER == 0 */
        /*
         * Use the lower gain setting only for 5A usage mode. For 3A and below current
         * configuration, use higher gain setting.
         */
        if ((cur >= CY_USBPD_I_4A) && (max_current > CY_USBPD_I_3A))
        {
            vref_2 = context->trimsConfig.cc_trim_5a_g2;
            vref_1 = context->trimsConfig.cc_trim_4a_g2;
            cur_1 = CY_USBPD_I_4A;
        }
        else if ((cur > CY_USBPD_I_3A) && (max_current > CY_USBPD_I_3A))
        {
            vref_2 = context->trimsConfig.cc_trim_4a_g2;
            vref_1 = context->trimsConfig.cc_trim_3a_g2;
            cur_1 = CY_USBPD_I_3A;
        }
        else if (cur >= CY_USBPD_I_2A)
        {
            vref_2 = context->trimsConfig.cc_trim_3a;
            vref_1 = context->trimsConfig.cc_trim_2a;
            cur_1 = CY_USBPD_I_2A;
        }
#if (PMG1B1_USB_CHARGER == 0)
        else
        {
            /* 1A is minimum CF reference */
            vref_2 = context->trimsConfig.cc_trim_2a;
            vref_1 = context->trimsConfig.cc_trim_1a;
            cur_1 = CY_USBPD_I_1A;
        }
#else /* PMG1B1_USB_CHARGER */
        else if (cur >= CY_USBPD_I_1A)
        {
            vref_2 = context->trimsConfig.cc_trim_2a;
            vref_1 = context->trimsConfig.cc_trim_1a;
            cur_1 = CY_USBPD_I_1A;
        }
        else
        {
            /* 1A is minimum CF reference */
            vref_2 = context->trimsConfig.cc_trim_1a;
            vref_1 = 0;
            cur_1 = 0;
        }
#endif /* (PMG1B1_USB_CHARGER == 0) */


        /*
         * Calculate corrected reference with trim and rsense value.
         * Adjust for current in 10mA units.
         */
        vref_diff = (vref_2 - vref_1);
        cur_diff = (cur - cur_1);
        offset = ((vref_diff * cur_diff) / 100u);
        vref_sel = vref_1 + (uint8_t)offset;

#if defined(CY_DEVICE_CCG7D)
        if (Cy_USBPD_Get_Silicon_Rev(context) == 0u)
        {
            /*
             * CC/CF trimming is off by ~60-100mA in ** silicon.
             * Hence, adjust the same in CC/CF reference.
             */
            vref_sel = ((vref_sel - 2u) > 0u) ? (vref_sel - 2u) : 0u;
        }
#endif /* defined(CY_DEVICE_CCG7D) */

        /*
         * CC trims will give refgen value directly including
         * 13 steps (130mV) offset. So, no need to adjust refgen offset.
         */
    }
    else
    {
#if PMG1B1_USB_CHARGER
        Cy_USBPD_CSA_Calc_Ref(context, cur, CC_GAIN_60, &vref_sel, false);
#else
        if ((cur > CY_USBPD_I_3A) && (max_current > CY_USBPD_I_3A))
        {
            Cy_USBPD_CSA_Calc_Ref(context, cur, CC_GAIN_60, &vref_sel, false);
        }
        else
        {
            Cy_USBPD_CSA_Calc_Ref(context, cur, CC_GAIN_80, &vref_sel, false);
        }

        /*
         * pd_csa_calc_ref takes care of VREF_VOLT_MIN (130mV) offset.
         */
#endif /* PMG1B1_USB_CHARGER */
    }

    /* Reference rollover check */
    vref_sel = CY_USBPD_GET_MIN(vref_sel, CC_VREF_VALUE_MAX);
#endif /* CCGx */

#if PDL_IBTR_ENABLE
    /*
     * Set EA comparator refgen transition through IBTR.
     * Abort any ongoing IBTR operation before starting new.
     */
    Cy_USBPD_IBTR_Abort(context);
#if defined(CY_DEVICE_SERIES_PMG1B1)
    Cy_USBPD_IBTR_Set(context, vref_sel, context->ibtrCbk);
#else
    Cy_USBPD_IBTR_Set(context, vref_sel, NULL);
#endif /* #if defined(CY_DEVICE_SERIES_PMG1B1) */

#else /* !PDL_IBTR_ENABLE */
    regval = pd->refgen_3_ctrl;
    regval &= ~(PDSS_REFGEN_3_CTRL_SEL10_MASK);
    regval |= ((uint32_t)vref_sel << PDSS_REFGEN_3_CTRL_SEL10_POS);
    pd->refgen_3_ctrl = regval;
#endif /* !PDL_IBTR_ENABLE */

#if CCG_CF_HW_DET_ENABLE
    /* Configure the flags only if we are not already in CC mode. */
#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
    if (false == context->cfEnStatus)
#else /* CCGx */
    if ((pd->ea_ctrl & PDSS_EA_CTRL_EN_CC) == 0)
#endif /* (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) */
    {
        uint16_t filt;
        filt = 25 * VBUS_CF_CC_CV_DEBOUNCE_MS;

        /* Ensure that we do not overflow the counter. */
        if (filt > (PDSS_INTR15_CFG_CC_FLAG_CC_FLAG_FILT_SEL_MASK >>
                    PDSS_INTR15_CFG_CC_FLAG_CC_FLAG_FILT_SEL_POS))
        {
            filt = (PDSS_INTR15_CFG_CC_FLAG_CC_FLAG_FILT_SEL_MASK >>
                    PDSS_INTR15_CFG_CC_FLAG_CC_FLAG_FILT_SEL_POS);
        }
#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
        pd->bb_ea_0_ctrl |= (PDSS_BB_EA_0_CTRL_BB_EA_EN_CC_CV_FLAG |
            PDSS_BB_EA_0_CTRL_BB_EA_ISO_N);
#else /* CCGx */
        pd->pds_ea_1_ctrl |= PDSS_PDS_EA_1_CTRL_EN_CC_CV_FLAG |
            PDSS_PDS_EA_1_CTRL_EA_ISO_N;
#endif /* CCGx */

        pd->intr15_cfg_cc_flag &= ~(PDSS_INTR15_CFG_CC_FLAG_CC_FLAG_FILT_EN |
                PDSS_INTR15_CFG_CC_FLAG_CC_FLAG_FILT_CFG_MASK |
                PDSS_INTR15_CFG_CC_FLAG_CC_FLAG_FILT_RESET |
                PDSS_INTR15_CFG_CC_FLAG_CC_FLAG_FILT_SEL_MASK);
        regval = pd->intr15_cfg_cc_flag;
        regval |= (((uint32_t)filt << PDSS_INTR15_CFG_CC_FLAG_CC_FLAG_FILT_SEL_POS) |
                ((uint32_t)CY_USBPD_VBUS_FILTER_CFG_POS_EN_NEG_EN <<
                 PDSS_INTR15_CFG_CC_FLAG_CC_FLAG_FILT_CFG_POS) |
                PDSS_INTR15_CFG_CC_FLAG_CC_FLAG_FILT_EN);
        pd->intr15_cfg_cc_flag |= regval;
    }
#endif /* CCG_CF_HW_DET_ENABLE */

#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
    /* Enable CC mode hardware control. CCAMP is already enabled in enable CV. */
    pd->bb_ea_0_ctrl |= PDSS_BB_EA_0_CTRL_BB_EA_EN_CCAMP;
    pd->csa_scp_0_ctrl &= ~PDSS_CSA_SCP_0_CTRL_PD_CSA;
#else /* CCGx */
    /* Enable CC mode hardware control. */
    pd->ea_ctrl |= PDSS_EA_CTRL_EN_CC;
    pd->lscsa_1_ctrl &= ~PDSS_LSCSA_1_CTRL_LSCSA_PD;
#endif /* CCGx */

#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
    context->cfEnStatus = true;
#endif /* (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) */

    Cy_SysLib_ExitCriticalSection(state);
#else
    CY_UNUSED_PARAMETER(context);
    CY_UNUSED_PARAMETER(cur);
#if PSVP_FPGA_ENABLE
#if (!defined(CY_DEVICE_CCG6DF_CFP))
    ctrl_inf_cf_enable(cur);
#endif /* (!defined(CY_DEVICE_CCG6DF_CFP)) */
#endif /* PSVP_FPGA_ENABLE */
#endif /* (defined(CY_DEVICE_CCG3PA) && CY_PD_VBUS_CF_EN) */
}
/*******************************************************************************
* Function Name: Cy_USBPD_CF_Disable
****************************************************************************//**
*
* Disables hardware monitoring for VBus Current foldback on the specified port.
* Monitoring should be disabled when there is VBUS transition as well as when not in
* PPS mode operation.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
*
*******************************************************************************/
void Cy_USBPD_CF_Disable(cy_stc_usbpd_context_t *context)
{
#if ((defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) && CY_PD_VBUS_CF_EN)
    PPDSS_REGS_T pd = context->base;
    uint32_t state;

    state = Cy_SysLib_EnterCriticalSection();

#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
    /*
     * CCAMP is enabled by default to make EA faster.
     * Hence, set CC reference to a maximum value while enabling CV.
     * In PPS mode, CC reference shall be set by CF enable.
     * And, set CC gain to minimum.
     */
    CY_USBPD_REG_FIELD_UPDATE(pd->refgen_3_ctrl, PDSS_REFGEN_3_CTRL_SEL10,
        CC_VREF_VALUE_MAX);
    CY_USBPD_REG_FIELD_UPDATE(pd->csa_scp_0_ctrl, PDSS_CSA_SCP_0_CTRL_AV1,
        1u);
#else /* !(defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) */
    pd->ea_ctrl &= ~PDSS_EA_CTRL_EN_CC;
    /* Select CSA gain to initialized value */
    pd->lscsa_0_ctrl |= (LSCSA_AV_SEL_35 << PDSS_LSCSA_0_CTRL_AV_EA_POS);
#endif /* !(defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) */

#if CCG_CF_HW_DET_ENABLE
    pd->intr15_mask &= ~PDSS_INTR15_MASK_CC_FLAG_CHANGED_MASK;

    pd->intr15_cfg_cc_flag &= ~(PDSS_INTR15_CFG_CC_FLAG_CC_FLAG_FILT_EN |
            PDSS_INTR15_CFG_CC_FLAG_CC_FLAG_FILT_CFG_MASK |
            PDSS_INTR15_CFG_CC_FLAG_CC_FLAG_FILT_RESET |
            PDSS_INTR15_CFG_CC_FLAG_CC_FLAG_FILT_SEL_MASK);

#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
    pd->bb_ea_0_ctrl &= ~PDSS_BB_EA_0_CTRL_BB_EA_EN_CC_CV_FLAG;
#else /* !(defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) */
    pd->pds_ea_1_ctrl &= ~(PDSS_PDS_EA_1_CTRL_EN_CC_CV_FLAG |
        PDSS_PDS_EA_1_CTRL_EA_ISO_N);
#endif /* !(defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) */
#endif /* CCG_CF_HW_DET_ENABLE */

#if PDL_IBTR_ENABLE
    /* Abort any ongoing IBTR operation */
    Cy_USBPD_IBTR_Abort(context);
#endif /* PDL_IBTR_ENABLE */

    /* Reset global current variable to minimum supported current */
    context->cfCur = CY_USBPD_I_1A;

#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
    context->cfEnStatus = false;
#endif /* (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) */

#if PSVP_FPGA_ENABLE
    ctrl_inf_cf_disable();
#endif /* PSVP_FPGA_ENABLE */

    Cy_SysLib_ExitCriticalSection(state);
#else
    CY_UNUSED_PARAMETER(context);
#endif /* (CY_PD_VBUS_CF_EN) */
}
/*******************************************************************************
* Function Name: Cy_USBPD_Adc_VoltToLevel
****************************************************************************//**
*
* PFC Interrupt handler
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
*
*******************************************************************************/
void Cy_USBPD_PFC_Intr1Handler(cy_stc_usbpd_context_t *context)
{
#if (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
    bool state = false;
    PPDSS_REGS_T pd = context->base;
    uint32_t regval4 = (pd->intr5_status_0 >> PDSS_INTR5_STATUS_0_FILT_12_POS);
    if ((regval4 & (1u << (uint8_t)CY_USBPD_VBUS_FILTER_ID_LSCSA_PFC)) != 0u)
    {
        state = true;
    }
    pd->intr5 = (uint32_t)1u << (uint8_t)CY_USBPD_VBUS_FILTER_ID_LSCSA_PFC;

    /* Invoke callback. */
    if (context->pfcCmpCbk != NULL)
    {
        context->pfcCmpCbk(context->pdStackContext, state);
    }
#else
    CY_UNUSED_PARAMETER(context);
#endif /* (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) */
}
/*******************************************************************************
* Function Name: Cy_USBPD_SR_Intr1Handler
****************************************************************************//**
*
* SR Interrupt handler
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
*
*******************************************************************************/
void Cy_USBPD_SR_Intr1Handler(cy_stc_usbpd_context_t *context)
{
#if (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
    bool state = false;
    PPDSS_REGS_T pd = context->base;
    uint32_t regval3 = (pd->intr5_status_0 >> PDSS_INTR5_STATUS_0_FILT_12_POS);
    if ((regval3 & ((uint32_t)1u << (uint8_t)CY_USBPD_VBUS_FILTER_ID_LSCSA_SR)) != 0u)
    {
        state = true;
    }
    pd->intr5 = (uint32_t)1u << (uint8_t)CY_USBPD_VBUS_FILTER_ID_LSCSA_SR;

    /* Invoke callback. */
    if (context->srCmpCbk != NULL)
    {
        context->srCmpCbk(context->pdStackContext, state);
    }
#else
    CY_UNUSED_PARAMETER(context);
#endif /* (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))*/
}

#if (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2) || defined(CY_DEVICE_PAG1S) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
/*******************************************************************************
* Function Name: Cy_USBPD_Vbus_Slow_DischargeOnProcess
****************************************************************************//**
*
* Enables VBUS Slow discharge
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
*
*******************************************************************************/
void Cy_USBPD_Vbus_Slow_DischargeOnProcess(cy_stc_usbpd_context_t *context)
{
#if VBUS_SLOW_DISCHARGE_EN
    uint32_t reg_val;
    PPDSS_REGS_T pd = context->base;
#if !PMG1_FLIPPED_FET_CTRL

    /* We have obtained the current discharge strength in
     * pd_internal_vbus_discharge_on(). We should start
     * discharge from the next higher discharge strength value.
     */
    if (context->vbusSlowDischarge.vbus_discharge_ds0 != VBUS_C_DISCHG_DS)
    {
        if (context->vbusSlowDischarge.vbus_discharge_ds0 == 0u)
        {
            context->vbusSlowDischarge.vbus_discharge_ds0 = 1u;
        }
        else
        {
            context->vbusSlowDischarge.vbus_discharge_ds0 = (uint8_t)(context->vbusSlowDischarge.vbus_discharge_ds0 << 1);
        }

        if (context->vbusSlowDischarge.vbus_discharge_ds0 > VBUS_C_DISCHG_DS)
        {
            /* Set the discharge strength to maximum configured */
            context->vbusSlowDischarge.vbus_discharge_ds0 = VBUS_C_DISCHG_DS;
        }

        /* Enable VBUS_C discharge with calculated drive strength */
        reg_val = (PDSS_DISCHG_SHV_CTRL_DISCHG_EN | PDSS_DISCHG_SHV_CTRL_DISCHG_EN_CFG);
        reg_val = (reg_val & ~PDSS_DISCHG_SHV_CTRL_DISCHG_DS_MASK) |
                    ((uint32_t)context->vbusSlowDischarge.vbus_discharge_ds0 << PDSS_DISCHG_SHV_CTRL_DISCHG_DS_POS);

        pd->dischg_shv_ctrl[0] = reg_val;
    }

#if VBUS_IN_DISCHARGE_EN

#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
/* Proceed with the VBUS_IN discharge only if the enable flag has been set to true */
    if(context->vbusInDischargeEn == true)
    {
#endif /* defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1) */
    if (context->vbusSlowDischarge.vbus_discharge_ds1 != VBUS_IN_DISCHG_DS)
    {
        if (context->vbusSlowDischarge.vbus_discharge_ds1 == 0u)
        {
            context->vbusSlowDischarge.vbus_discharge_ds1 = 1u;
        }
        else
        {
            context->vbusSlowDischarge.vbus_discharge_ds1 = (uint8_t)(context->vbusSlowDischarge.vbus_discharge_ds1 << 1);
        }
        if (context->vbusSlowDischarge.vbus_discharge_ds1 > VBUS_IN_DISCHG_DS)
        {
            context->vbusSlowDischarge.vbus_discharge_ds1 = VBUS_IN_DISCHG_DS;
        }
#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
        /* CCG7D is VIN powered, so non comparator based discharge can be enabled */
        reg_val =  pd->dischg_shv_ctrl[1];
        reg_val = ((reg_val & ~(PDSS_DISCHG_SHV_CTRL_DISCHG_DS_MASK)) |
                    (context->vbusSlowDischarge.vbus_discharge_ds1 << PDSS_DISCHG_SHV_CTRL_DISCHG_DS_POS) |
                    PDSS_DISCHG_SHV_CTRL_DISCHG_EN_CFG |
                    PDSS_DISCHG_SHV_CTRL_DISCHG_EN);
        pd->dischg_shv_ctrl[1] = reg_val;
#else
#if VBUS_IN_DISCH_BELOW_5V_EN

        reg_val =  pd->dischg_shv_ctrl[1];
        reg_val = ((reg_val & ~(PDSS_DISCHG_SHV_CTRL_DISCHG_DS_MASK)) |
                    (context->vbusSlowDischarge.vbus_discharge_ds1 << PDSS_DISCHG_SHV_CTRL_DISCHG_DS_POS) |
                    PDSS_DISCHG_SHV_CTRL_DISCHG_EN_CFG |
                    PDSS_DISCHG_SHV_CTRL_DISCHG_EN );

        PDSS->dischg_shv_ctrl[1] = reg_val;
#else /* !VBUS_IN_DISCH_BELOW_5V_EN */
        /* Only discharge to 5V. */
        reg_val =  pd->dischg_shv_ctrl[1];
        reg_val = (reg_val & ~(PDSS_DISCHG_SHV_CTRL_DISCHG_EN_CFG | PDSS_DISCHG_SHV_CTRL_DISCHG_DS_MASK))
                    | ((uint32_t)context->vbusSlowDischarge.vbus_discharge_ds1 << PDSS_DISCHG_SHV_CTRL_DISCHG_DS_POS);

        pd->dischg_shv_ctrl[1] = reg_val;

        /* Discharge enable driven by comparator. Enable the comparator. */
        pd->comp_ctrl[CY_USBPD_VBUS_COMP_ID_VBUS_DISCHARGE] &= ~PDSS_COMP_CTRL_COMP_PD;
#endif  /* !VBUS_IN_DISCH_BELOW_5V_EN */
#endif /* !(defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) */
    }
#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) 
    }
#endif /* (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))  */
#endif /* VBUS_IN_DISCHARGE_EN */

    if (
        (context->vbusSlowDischarge.vbus_discharge_ds0  != VBUS_C_DISCHG_DS)
#if VBUS_IN_DISCHARGE_EN
        || (context->vbusSlowDischarge.vbus_discharge_ds1 != VBUS_IN_DISCHG_DS)
#endif /* VBUS_IN_DISCHARGE_EN */
        )
    {
        (void)context->timerStartcbk(context, context, (cy_en_usbpd_timer_id_t)CY_USBPD_VBUS_DISCHARGE_SCHEDULE_TIMER, VBUS_SLOW_DISCHARGE_TIME_MS, Cy_USBPD_Vbus_Slow_DischargeCbk);
    }
    else
    {
        context->vbusSlowDischarge.vbus_is_slow_dischargeOn = 0u;
    }
#else /* PMG1_FLIPPED_FET_CTRL */
#if !(defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
    if (context->vbusSlowDischarge.vbus_discharge_ds1 != VBUS_C_DISCHG_DS)
    {
        if (context->vbusSlowDischarge.vbus_discharge_ds1 == 0)
        {
            context->vbusSlowDischarge.vbus_discharge_ds1 = 1u;
        }
        else
        {
            context->vbusSlowDischarge.vbus_discharge_ds1 = gl_vbus_discharge_ds_1 << 1;
        }
        if (context->vbusSlowDischarge.vbus_discharge_ds1 > VBUS_C_DISCHG_DS)
        {
            context->vbusSlowDischarge.vbus_discharge_ds1 = VBUS_C_DISCHG_DS;
        }
        reg_val = pd->dischg_shv_ctrl[1];

        reg_val = (PDSS_DISCHG_SHV_CTRL_DISCHG_EN | PDSS_DISCHG_SHV_CTRL_DISCHG_EN_CFG);
        reg_val = (reg_val & ~PDSS_DISCHG_SHV_CTRL_DISCHG_DS_MASK) |
                    (context->vbusSlowDischarge.vbus_discharge_ds1 << PDSS_DISCHG_SHV_CTRL_DISCHG_DS_POS);

        /* VBUS_C discharge enable with drive strength */
        pd->dischg_shv_ctrl[1] = reg_val;
    }

#if VBUS_IN_DISCHARGE_EN
    if (context->vbusSlowDischarge.vbus_discharge_ds0 != VBUS_IN_DISCHG_DS)
    {
        if (context->vbusSlowDischarge.vbus_discharge_ds0 == 0)
        {
            context->vbusSlowDischarge.vbus_discharge_ds0 = 1u;
        }
        else
        {
            context->vbusSlowDischarge.vbus_discharge_ds0 = gl_vbus_discharge_ds_0 << 1;
        }
        if(context->vbusSlowDischarge.vbus_discharge_ds0 > VBUS_IN_DISCHG_DS)
        {
            context->vbusSlowDischarge.vbus_discharge_ds0 = VBUS_IN_DISCHG_DS;
        }
        reg_val = pd->dischg_shv_ctrl[0];

        reg_val = (PDSS_DISCHG_SHV_CTRL_DISCHG_EN | PDSS_DISCHG_SHV_CTRL_DISCHG_EN_CFG);
        reg_val = (reg_val & ~PDSS_DISCHG_SHV_CTRL_DISCHG_DS_MASK) |
                    (gl_vbus_discharge_ds_0 << PDSS_DISCHG_SHV_CTRL_DISCHG_DS_POS);

        pd->dischg_shv_ctrl[0] = reg_val;
    }
#endif /* VBUS_IN_DISCHARGE_EN */

    if (
        (context->vbusSlowDischarge.vbus_discharge_ds0 != VBUS_C_DISCHG_DS)
#if VBUS_IN_DISCHARGE_EN
        || (context->vbusSlowDischarge.vbus_discharge_ds0 != VBUS_IN_DISCHG_DS)
#endif /* VBUS_IN_DISCHARGE_EN */
        )
    {
        context->timerStartcbk(context, context, CY_USBPD_VBUS_DISCHARGE_SCHEDULE_TIMER, VBUS_SLOW_DISCHARGE_TIME_MS, Cy_USBPD_Vbus_Slow_DischargeCbk);
    }
    else
    {
        context->vbusSlowDischarge.vbus_is_slow_dischargeOn = false;
    }
#endif /* !(defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) */
#endif /* PMG1_FLIPPED_FET_CTRL */
#else /* !VBUS_SLOW_DISCHARGE_EN */
    CY_UNUSED_PARAMETER(context);
#endif /* !VBUS_SLOW_DISCHARGE_EN */
}
/*******************************************************************************
* Function Name: Cy_USBPD_Vbus_Slow_DischargeOffProcess
****************************************************************************//**
*
* Disables VBUS Slow discharge
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
*
*******************************************************************************/
void Cy_USBPD_Vbus_Slow_DischargeOffProcess(cy_stc_usbpd_context_t *context)
{
#if VBUS_SLOW_DISCHARGE_EN
    uint32_t reg_val;
    PPDSS_REGS_T pd = context->base;
#if !PMG1_FLIPPED_FET_CTRL
    /* We have obtained the current discharge strength in
     * pd_internal_vbus_discharge_off(). We should start
     * discharge from the next lower discharge strength value.
     */
    if(context->vbusSlowDischarge.vbus_discharge_ds0 != VBUS_C_DISCHG_DS_MIN)
    {
        context->vbusSlowDischarge.vbus_discharge_ds0 = context->vbusSlowDischarge.vbus_discharge_ds0 >> 1;

        if (context->vbusSlowDischarge.vbus_discharge_ds0 < VBUS_C_DISCHG_DS_MIN)
        {
            /* Set the discharge strength to minimum configured */
            context->vbusSlowDischarge.vbus_discharge_ds0 = VBUS_C_DISCHG_DS_MIN;
        }

        reg_val = pd->dischg_shv_ctrl[0];
        reg_val = (reg_val & ~PDSS_DISCHG_SHV_CTRL_DISCHG_DS_MASK) |
                    ((uint32_t)context->vbusSlowDischarge.vbus_discharge_ds0 << PDSS_DISCHG_SHV_CTRL_DISCHG_DS_POS);

        /* Load calculated discharge drive strength */
        pd->dischg_shv_ctrl[0] = reg_val;
    }

#if VBUS_IN_DISCHARGE_EN
#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
/* Proceed with the VBUS_IN discharge only if the enable flag has been set to true */
    if(context->vbusInDischargeEn == true)
    {
#endif /* defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1) */
    if(context->vbusSlowDischarge.vbus_discharge_ds1 != VBUS_IN_DISCHG_DS_MIN)
    {
        context->vbusSlowDischarge.vbus_discharge_ds1 = context->vbusSlowDischarge.vbus_discharge_ds1 >> 1;
        if (context->vbusSlowDischarge.vbus_discharge_ds1 < VBUS_IN_DISCHG_DS_MIN)
        {
            /* Set the discharge strength to minimum configured */
            context->vbusSlowDischarge.vbus_discharge_ds1 = VBUS_IN_DISCHG_DS_MIN;
        }

        reg_val = pd->dischg_shv_ctrl[1];
        reg_val = (reg_val & ~PDSS_DISCHG_SHV_CTRL_DISCHG_DS_MASK) |
                    ((uint32_t)context->vbusSlowDischarge.vbus_discharge_ds1 << PDSS_DISCHG_SHV_CTRL_DISCHG_DS_POS);

        /* Load calculated discharge drive strength */
        pd->dischg_shv_ctrl[1] = reg_val;
    }
#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) 
    }
#endif /* (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))  */
#endif /* VBUS_IN_DISCHARGE_EN */

    if (
        (context->vbusSlowDischarge.vbus_discharge_ds0 != VBUS_C_DISCHG_DS_MIN)
#if VBUS_IN_DISCHARGE_EN
        || (context->vbusSlowDischarge.vbus_discharge_ds1 != VBUS_IN_DISCHG_DS_MIN)
#endif /* VBUS_IN_DISCHARGE_EN */
        )
    {
        (void)context->timerStartcbk(context, context, (cy_en_usbpd_timer_id_t)CY_USBPD_VBUS_DISCHARGE_SCHEDULE_TIMER, VBUS_SLOW_DISCHARGE_TIME_MS, Cy_USBPD_Vbus_Slow_DischargeCbk);
    }
    else
    {
        /*
         * Done with discharge. Now disable discharge accordingly.
         */
        pd->dischg_shv_ctrl[0] = ((pd->dischg_shv_ctrl[0] & ~PDSS_DISCHG_SHV_CTRL_DISCHG_EN) |
            PDSS_DISCHG_SHV_CTRL_DISCHG_EN_CFG);
#if VBUS_IN_DISCHARGE_EN
#if !(defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
#if !VBUS_IN_DISCH_BELOW_5V_EN
        pd->comp_ctrl[CY_USBPD_VBUS_COMP_ID_VBUS_DISCHARGE] |= PDSS_COMP_CTRL_COMP_PD;
#endif /* !VBUS_IN_DISCH_BELOW_5V_EN */
#endif /* !(defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))  */
        pd->dischg_shv_ctrl[1] = ((pd->dischg_shv_ctrl[1] & ~PDSS_DISCHG_SHV_CTRL_DISCHG_EN) |
            PDSS_DISCHG_SHV_CTRL_DISCHG_EN_CFG);
#endif /* VBUS_IN_DISCHARGE_EN */

        context->vbusSlowDischarge.vbus_is_slow_dischargeOff = 0u;
  
#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) 
        /* Clear the VBUS_IN discharge enabled flag */
        context->vbusInDischargeEn = false;
#endif /* (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))  */
    }
#else
#if !(defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
    if(context->vbusSlowDischarge.vbus_discharge_ds1 != VBUS_C_DISCHG_DS_MIN)
    {
        context->vbusSlowDischarge.vbus_discharge_ds1 = context->vbusSlowDischarge.vbus_discharge_ds1 >> 1;

        if (context->vbusSlowDischarge.vbus_discharge_ds1 < VBUS_C_DISCHG_DS_MIN)
        {
            /* Set the discharge strength to minimum configured */
            context->vbusSlowDischarge.vbus_discharge_ds1 = VBUS_C_DISCHG_DS_MIN;
        }

        reg_val = pd->dischg_shv_ctrl[1];
        reg_val = (reg_val & ~PDSS_DISCHG_SHV_CTRL_DISCHG_DS_MASK) |
                    (context->vbusSlowDischarge.vbus_discharge_ds1 << PDSS_DISCHG_SHV_CTRL_DISCHG_DS_POS);

        /* Load calculated discharge drive strength */
        pd->dischg_shv_ctrl[1] = reg_val;
    }

#if VBUS_IN_DISCHARGE_EN

    if(context->vbusSlowDischarge.vbus_discharge_ds0 != VBUS_IN_DISCHG_DS_MIN)
    {
        context->vbusSlowDischarge.vbus_discharge_ds0 = context->vbusSlowDischarge.vbus_discharge_ds0 >> 1;
        if (context->vbusSlowDischarge.vbus_discharge_ds0 < VBUS_IN_DISCHG_DS_MIN)
        {
            /* Set the discharge strength to minimum configured */
            context->vbusSlowDischarge.vbus_discharge_ds0 = VBUS_IN_DISCHG_DS_MIN;
        }

        reg_val = pd->dischg_shv_ctrl[0];
        reg_val = (reg_val & ~PDSS_DISCHG_SHV_CTRL_DISCHG_DS_MASK) |
                    (context->vbusSlowDischarge.vbus_discharge_ds0 << PDSS_DISCHG_SHV_CTRL_DISCHG_DS_POS);

        /* Load calculated discharge drive strength */
        pd->dischg_shv_ctrl[0] = reg_val;
    }

#endif /* VBUS_IN_DISCHARGE_EN */

    if (
        (context->vbusSlowDischarge.vbus_discharge_ds1 != VBUS_C_DISCHG_DS_MIN)
#if VBUS_IN_DISCHARGE_EN
        || (context->vbusSlowDischarge.vbus_discharge_ds0 != VBUS_IN_DISCHG_DS_MIN)
#endif /* VBUS_IN_DISCHARGE_EN */
        )
    {
        context->timerStartcbk(context, context, CY_USBPD_VBUS_DISCHARGE_SCHEDULE_TIMER, VBUS_SLOW_DISCHARGE_TIME_MS, Cy_USBPD_Vbus_Slow_DischargeCbk);
    }
    else
    {
        /*
         * Done with discharge. Now disable discharge accordingly.
         */
#if VBUS_IN_DISCHARGE_EN
        pd->dischg_shv_ctrl[0] = ((pd->dischg_shv_ctrl[0] & ~PDSS_DISCHG_SHV_CTRL_DISCHG_EN) |
            PDSS_DISCHG_SHV_CTRL_DISCHG_EN_CFG);
#endif /* VBUS_IN_DISCHARGE_EN */

        pd->dischg_shv_ctrl[1] = ((pd->dischg_shv_ctrl[1] & ~PDSS_DISCHG_SHV_CTRL_DISCHG_EN) |
            PDSS_DISCHG_SHV_CTRL_DISCHG_EN_CFG);

        context->vbusSlowDischarge.vbus_is_slow_dischargeOff = false;
    }
#endif /* !(defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) */
#endif /* PMG1_FLIPPED_FET_CTRL */
#else /* !VBUS_SLOW_DISCHARGE_EN */
    CY_UNUSED_PARAMETER(context);
#endif /* !VBUS_SLOW_DISCHARGE_EN */
}

void Cy_USBPD_Vbus_Slow_DischargeCbk(uint16_t id, void *callbackContext)
{
#if VBUS_SLOW_DISCHARGE_EN
    cy_stc_usbpd_context_t *context = (cy_stc_usbpd_context_t *)callbackContext;
#if CCG_PD_DUALPORT_ENABLE
    if (context->port != 0u)
    {
        /* For Port 1, the 128 needs to be subtracted as port1 timer ids are offset by 128 */
        id = ((uint16_t)id - 128u);
    }
#endif /* CCG_PD_DUALPORT_ENABLE */
    if (CY_USBPD_VBUS_DISCHARGE_SCHEDULE_TIMER == (cy_en_usbpd_timer_id_t)id)
    {
        if (context->vbusSlowDischarge.vbus_is_slow_dischargeOn == 1u)
        {
            /* Process Slow discharge ON. gl_vbus_is_slow_discharge_on will be
             * updated inside Cy_USBPD_Vbus_Slow_DischargeOnProcess().
             */
            Cy_USBPD_Vbus_Slow_DischargeOnProcess(context);
        } /* vbus_slow_discharge_on == true */
        else if (context->vbusSlowDischarge.vbus_is_slow_dischargeOff  == 1u)
        {
            /* Process Slow discharge OFF. gl_vbus_is_slow_discharge_off will be
             * updated inside vbus_slow_discharge_off_process().
             */
            Cy_USBPD_Vbus_Slow_DischargeOffProcess(context);
        }
        else
        {
            /* Do nothing */
        }
    } /* VBUS_DISCHARGE_SCHEDULE_TIMER == id */
#else /* !VBUS_SLOW_DISCHARGE_EN */
    CY_UNUSED_PARAMETER(id);
    CY_UNUSED_PARAMETER(callbackContext);
#endif  /* !VBUS_SLOW_DISCHARGE_EN */
}
#endif /*CCGx */
/*******************************************************************************
* Function Name: Cy_USBPD_VBTR_Start
****************************************************************************//**
*
* This function triggers VBUS voltage transition. It expects that 
* configuration has been done already.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
*
*******************************************************************************/
void Cy_USBPD_VBTR_Start(cy_stc_usbpd_context_t *context)
{
#if PDL_VBTR_ENABLE
    PPDSS_REGS_T pd = context->base;
    /* Start VBTR for configured transition */

#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
#if BB_VBTR_IBTR_FCCM_DIS
    /* During VBTR/IBTR, FCCM must be disabled */
    Cy_USBPD_BB_SetMode(port, BB_MODE_PSM);
#endif /* BB_VBTR_IBTR_FCCM_DIS */
#endif /* !(defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) */

    context->vbtrIdle = false;
    pd->vbtr_ctrl |= PDSS_VBTR_CTRL_START;
#else /* !PDL_VBTR_ENABLE */
    CY_UNUSED_PARAMETER(context);
#endif /* !PDL_VBTR_ENABLE */
}
/*******************************************************************************
* Function Name: Cy_USBPD_VBTR_Config
****************************************************************************//**
*
* This function does blocking Vbus transition to VSAFE_5V from lower iDAC
* setting to zero. It assumes that the caller has already setup the iDAC to negative
* value. Calling the function with a positive iDAC setting shall result in EA
* being loaded directly to zero and CV mode disabled. If the VBUS is higher than
* 5V, the VBUS_IN safe voltage correction is expected to drop the voltage.
*
* The function is expected to be called only during HAL start / stop functions
* and should not be invoked while in attached state.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \param dac_cur
* Initial signed iDAC value for VBUS voltage transition. Negative for source and positive for sink.
*
* \param dac_req
* Final signed iDAC value for VBUS voltage transition. Negative for source and positive for sink.
*
* \param vbtr_cb
* Callback to notify vbtr events
*
*******************************************************************************/
void Cy_USBPD_VBTR_Config(cy_stc_usbpd_context_t *context, int16_t dac_cur, int16_t dac_req, cy_cb_adc_events_t vbtr_cb)
{
#if PDL_VBTR_ENABLE
    PPDSS_REGS_T pd = context->base;
#if (defined(CY_DEVICE_PAG1S))
    PPDSS_TRIMS_REGS_T pd_trims = (PPDSS_TRIMS_REGS_T)context->trimsBase;
#endif /* (defined(CY_DEVICE_PAG1S)) */
    uint32_t state;
    uint32_t cfg_val;
    uint32_t ea_ctrl_val;
#if (PSVP_FPGA_ENABLE)
    uint32_t hfclk_mhz = 26u;
#else /* !(PSVP_FPGA_ENABLE) */
    uint32_t hfclk_mhz = (Cy_SysClk_ClkHfGetFrequency() / 1000000);
#endif /* !(PSVP_FPGA_ENABLE) */
    uint16_t src_init = 0;
    uint16_t src_final = 0;
    uint16_t snk_init = 0;
    uint16_t snk_final = 0;
    int16_t src_init_signed;
    int16_t src_final_signed;
    uint8_t port = context->port;

    context->vbtrCbk = vbtr_cb;

#if CY_USE_CONFIG_TABLE
    pwr_params_t *pwr_cfg = pd_get_ptr_pwr_tbl(context);
#else
    cy_stc_buck_boost_cfg_t *pwr_cfg = context->usbpdConfig->buckBoostConfig;
#endif

    state  = Cy_SysLib_EnterCriticalSection();
    /* Reset the source and sink IDAC modules */
#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
    /*
     * CCG7D shares the node for PDAC and NDAC and toggling ISNK results in
     * fluctuations in output. Hence ISNK needs to be left ON all the time.
     */
    ea_ctrl_val = (pd->bb_ea_0_ctrl & ~(PDSS_BB_EA_0_CTRL_BB_EA_ISRC_EN));
#else /* !(defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) */
    ea_ctrl_val = pd->ea_ctrl & (~(
        PDSS_EA_CTRL_ISRC_EN |
        PDSS_EA_CTRL_ISNK_EN));
#endif /* !(defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) */
    cfg_val = pd->vbtr_cfg & (~(
        PDSS_VBTR_CFG_SRC_EN |
        PDSS_VBTR_CFG_SNK_EN |
        PDSS_VBTR_CFG_VBTR_SEL));
#if VBTR_MULTI_SLOPE_ENABLE
    context->vbtrSrcPending = false;
    context->vbtrSnkPending = false;
#endif  /* VBTR_MULTI_SLOPE_ENABLE */

    if(dac_req >= 0)
    {
        /*
         * Voltage request above VSAFE_5V margin.
         * Reset source IDAC if currently used for voltage less than VSAFE_5V
         * Use sink IDAC for transition above VSAFE_5V.
         */
        if(dac_cur < 0)
        {
            src_init = (uint16_t)(-dac_cur);
            src_final = 0;
            snk_init = 0;
#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
            ea_ctrl_val |= PDSS_BB_EA_0_CTRL_BB_EA_ISRC_EN;
#else /* !(defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) */
            ea_ctrl_val |= PDSS_EA_CTRL_ISRC_EN;
#endif /* !(defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) */
            cfg_val |= PDSS_VBTR_CFG_SRC_EN;
#if VBTR_MULTI_SLOPE_ENABLE
            context->vbtrSrcPending = true;
#endif /* VBTR_MULTI_SLOPE_ENABLE */

#if (VBUS_CTRL_TYPE_P1 == VBUS_CTRL_DIR_FB)
            /*
             * For transitions going from SRC to SNK DAC, load the gain TRIMs
             * before transition. This is because changing TRIMs at high voltage
             * is seen to show overshoots. For others, the TRIMs are anyway
             * loaded at the end of transition.
             */
#if (defined(CY_DEVICE_PAG1S))
        pd_trims->trim_pds_ea = EA_IREF_GAIN_NDAC;
#endif /* (defined(CY_DEVICE_PAG1S)) */
#endif /* (VBUS_CTRL_TYPE_P1 == VBUS_CTRL_DIR_FB) */
        }
        else
        {
            snk_init = (uint16_t)dac_cur;
        }
        snk_final = (uint16_t)dac_req;

        /* Enable sink idac only for non-zero value */
        if ((snk_init != 0u) || (snk_final != 0u))
        {
#if !(defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
            ea_ctrl_val |= PDSS_EA_CTRL_ISNK_EN;
#endif /* !(defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) */
            cfg_val |= PDSS_VBTR_CFG_SNK_EN;
#if VBTR_MULTI_SLOPE_ENABLE
            context->vbtrSnkPending = true;
#endif /* VBTR_MULTI_SLOPE_ENABLE */
        }
    }
    else
    {
        /*
         * Voltage request below VSAFE_5V margin.
         * Reset sink IDAC if currently used for voltage greater than VSAFE_5V.
         * Use source IDAC for transition below VSAFE_5V.
         */
        if(dac_cur > 0)
        {
            snk_init = (uint16_t)dac_cur;
            snk_final = 0;
            src_init = 0;
#if !(defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
            ea_ctrl_val |= PDSS_EA_CTRL_ISNK_EN;
#endif /* !(defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) */
            cfg_val |= PDSS_VBTR_CFG_SNK_EN;
#if VBTR_MULTI_SLOPE_ENABLE
            context->vbtrSnkPending = true;
#endif /* VBTR_MULTI_SLOPE_ENABLE */
        }
        else
        {
            src_init_signed = (dac_cur * -1);
            src_init = (uint16_t)src_init_signed;
        }
        src_final_signed = (dac_req * -1);
        src_final = (uint16_t)src_final_signed;

        /* Select the sequence of IDAC for transition */
#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
        ea_ctrl_val |= PDSS_BB_EA_0_CTRL_BB_EA_ISRC_EN;
#else /* CCGx */
        ea_ctrl_val |= PDSS_EA_CTRL_ISRC_EN;
#endif /* CCG7D */
        cfg_val |= (PDSS_VBTR_CFG_VBTR_SEL | PDSS_VBTR_CFG_SRC_EN);
#if VBTR_MULTI_SLOPE_ENABLE
        context->vbtrSrcPending = true;
#endif /* VBTR_MULTI_SLOPE_ENABLE */
    }

    /*
     * Set increment or decrement operation.
     * Adjust initial values of source and sink IDACs to the next value
     * (+1/-1) based on the direction of transition. This is needed to
     * start the VBTR operation from the required initial value instead
     * of the current final value.
     * Also configure VBTR step width for increment and decrement
     * operations as required.
     * Care should be taken to ensure start and stop are not same value. This
     * causes hardware to not give completion interrupt.
     */
    if(dac_req > dac_cur)
    {
        cfg_val |= PDSS_VBTR_CFG_SNK_UP_DOWN;
        cfg_val &= ~PDSS_VBTR_CFG_SRC_UP_DOWN;

        if ((snk_init != snk_final) && ((snk_init + 1) != snk_final))
        {
            snk_init++;
        }
        if ((src_init != src_final) && ((src_final + 1) != src_init))
        {
            src_init--;
        }

        if (port == 0u)
        {
            Cy_SysClk_PeriphSetDivider(CY_SYSCLK_DIV_16_BIT, 0U, (hfclk_mhz * (pwr_cfg->vbtr_up_step_width)));
#if VBTR_MULTI_SLOPE_ENABLE
            if (dac_cur < 0u)
            {
                Cy_SysClk_PeriphSetDivider(CY_SYSCLK_DIV_16_BIT, 0U, (hfclk_mhz * (pwr_cfg->vbtr_up_step_width_below_5v)));
            }
#endif /* VBTR_MULTI_SLOPE_ENABLE */
        }
#if (NO_OF_TYPEC_PORTS > 1)
        else if (port == 1u)
        {
            Cy_SysClk_PeriphSetDivider(CY_SYSCLK_DIV_16_BIT, 2U, (hfclk_mhz * (pwr_cfg->vbtr_up_step_width)));
        }
        else
        {
            /* Do nothing */
        }
#endif /* (NO_OF_TYPEC_PORTS > 1) */
    }
    else
    {
        cfg_val |= PDSS_VBTR_CFG_SRC_UP_DOWN;
        cfg_val &= ~PDSS_VBTR_CFG_SNK_UP_DOWN;

        if ((snk_init != snk_final) && ((snk_final + 1) != snk_init))
        {
            snk_init--;
        }
        if ((src_init != src_final) && ((src_init + 1) != src_final))
        {
            src_init++;
        }

        if (port == 0u)
        {
            Cy_SysClk_PeriphSetDivider(CY_SYSCLK_DIV_16_BIT, 0U, (hfclk_mhz * (pwr_cfg->vbtr_down_step_width)));
#if VBTR_MULTI_SLOPE_ENABLE
            if (dac_cur <= 0u)
            {
                Cy_SysClk_PeriphSetDivider(CY_SYSCLK_DIV_16_BIT, 0U, (hfclk_mhz * (pwr_cfg->vbtr_down_step_width_below_5V)));
            }
#endif /* VBTR_MULTI_SLOPE_ENABLE */
        }
#if (NO_OF_TYPEC_PORTS > 1)
        else if (port == 1u)
        {
            Cy_SysClk_PeriphSetDivider(CY_SYSCLK_DIV_16_BIT, 2U, (hfclk_mhz * (pwr_cfg->vbtr_down_step_width)));
        }
        else
        {
            /* Do nothing */
        }
#endif /* (NO_OF_TYPEC_PORTS > 1) */
    }

    /* Set initial and final values for source IDAC */
    /* QAC suppression 2985: REG_FEILD_UPDATE is a common functional macro that is used to 
     * modify a register field without affecting any other bits of the register. When the field
     * starts from bit position 0, the left shift operation is redundant. Yet this operation is 
     * retained to keep it generic and compatible for bitfields starting from other bit positions. */
    CY_USBPD_REG_FIELD_UPDATE(pd->vbtr_src_init_fin_value, PDSS_VBTR_SRC_INIT_FIN_VALUE_SRC_INIT, (uint32_t)src_init); /* PRQA S 2985 */
    CY_USBPD_REG_FIELD_UPDATE(pd->vbtr_src_init_fin_value, PDSS_VBTR_SRC_INIT_FIN_VALUE_SRC_FIN, (uint32_t)src_final);

    /* Set initial and final values for sink IDAC */
    /* QAC suppression 2985: REG_FEILD_UPDATE is a common functional macro that is used to 
     * modify a register field without affecting any other bits of the register. When the field
     * starts from bit position 0, the left shift operation is redundant. Yet this operation is 
     * retained to keep it generic and compatible for bitfields starting from other bit positions. */
    CY_USBPD_REG_FIELD_UPDATE(pd->vbtr_snk_init_fin_value, PDSS_VBTR_SNK_INIT_FIN_VALUE_SNK_INIT, (uint32_t)snk_init); /* PRQA S 2985 */
    CY_USBPD_REG_FIELD_UPDATE(pd->vbtr_snk_init_fin_value, PDSS_VBTR_SNK_INIT_FIN_VALUE_SNK_FIN, (uint32_t)snk_final);

#if VBTR_MULTI_SLOPE_ENABLE
    /*
     * Multi slope VBTR across SRC and SINK IDACs is needed only if both
     * SRC and SNK transitions are pending.
     * Initiate different VBTR SRC and SNK transitions if configured step width
     * or slope for above 5V and below 5V are different.
     * If above 5V and below 5V slopes are same, then do a single VBTR transition.
     */
    if ((context->vbtrSrcPending == true) && (context->vbtrSnkPending == true))
    {
        if (dac_req > dac_cur)
        {
            if (pwr_cfg->vbtr_up_step_width_below_5v != pwr_cfg->vbtr_up_step_width)
            {
                cfg_val &= ~PDSS_VBTR_CFG_SNK_EN;
            }
        }
        else
        {
            if (pwr_cfg->vbtr_down_step_width_below_5V != pwr_cfg->vbtr_down_step_width)
            {
                cfg_val &= ~PDSS_VBTR_CFG_SRC_EN;
            }
        }
    }
#endif /* VBTR_MULTI_SLOPE_ENABLE */

    /* Configure EA and VBTR */
#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
    pd->bb_ea_0_ctrl = ea_ctrl_val;
#else /* CCGx */
    pd->ea_ctrl = ea_ctrl_val;
#endif /* CCG7D */
    pd->vbtr_cfg = cfg_val;

    pd->vbtr_ctrl &= ~(PDSS_VBTR_CTRL_START | PDSS_VBTR_CTRL_EXIT);

    /* Clear and enable VBTR interrupt */
    pd->intr8 = (PDSS_INTR8_VBTR_OPR_DONE | PDSS_INTR8_VBTR_EXIT_DONE);
    pd->intr8_mask |= (PDSS_INTR8_VBTR_OPR_DONE);

    Cy_SysLib_ExitCriticalSection(state);
#else
    CY_UNUSED_PARAMETER(context);
    CY_UNUSED_PARAMETER(dac_cur);
    CY_UNUSED_PARAMETER(dac_req);
    (void)(cy_cb_adc_events_t)(vbtr_cb);
#endif /* PDL_VBTR_ENABLE */      
}
/*******************************************************************************
* Function Name: Cy_USBPD_VBTR_IsIdle
****************************************************************************//**
*
* Gets the current status of the VBTR module.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \return bool
* Idle state of the VBTR module. Returns False if VBTR Vbus voltage
* transition is in progress.
*
*******************************************************************************/
bool Cy_USBPD_VBTR_IsIdle(cy_stc_usbpd_context_t *context)
{
#if PDL_VBTR_ENABLE
    return context->vbtrIdle;
#else
    CY_UNUSED_PARAMETER(context);
    return true;
#endif /* PDL_VBTR_ENABLE */      
}
/*******************************************************************************
* Function Name: Cy_USBPD_VBTR_SetIdac
****************************************************************************//**
*
* Configures VBUS transition operation for the requested idac value.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \param dac_req
* Final signed iDAC value for VBUS voltage transition. Negative for source and positive for sink.
*
* \param vbtr_cb
* Callback to notify vbtr events
*
*******************************************************************************/
void Cy_USBPD_VBTR_SetIdac(cy_stc_usbpd_context_t *context, int16_t dac_req, cy_cb_adc_events_t vbtr_cb)
{
#if PDL_VBTR_ENABLE
    uint32_t state;
    int16_t dac_cur;

    state  = Cy_SysLib_EnterCriticalSection();

    /* Get the current IDAC value */
    dac_cur = Cy_USBPD_Hal_Get_Fb_Dac(context);

    /* Configure VBTR operation */
    Cy_USBPD_VBTR_Config(context, dac_cur, dac_req, vbtr_cb);

    /* Start VBTR operation */
    Cy_USBPD_VBTR_Start(context);

    Cy_SysLib_ExitCriticalSection(state);
#else
    CY_UNUSED_PARAMETER(context);
    CY_UNUSED_PARAMETER(dac_req);
    (void)(cy_cb_adc_events_t)(vbtr_cb);
#endif /* PDL_VBTR_ENABLE */      
}
/*******************************************************************************
* Function Name: Cy_USBPD_VBTR_Abort
****************************************************************************//**
*
* Aborts the ongoing VBUS transition operation.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
*
*******************************************************************************/
void Cy_USBPD_VBTR_Abort(cy_stc_usbpd_context_t *context)
{
#if PDL_VBTR_ENABLE
    PPDSS_REGS_T pd = context->base;
    uint32_t state;
    uint32_t src_dac_u32;
    uint32_t snk_dac_u32;
#if (PSVP_FPGA_ENABLE)
    uint32_t hfclk_mhz = 26u;
#else /* !(PSVP_FPGA_ENABLE) */
    uint32_t hfclk_mhz = (Cy_SysClk_ClkHfGetFrequency() / 1000000);
#endif /* !PSVP_FPGA_ENABLE */
    int16_t src_dac = 0;
    int16_t snk_dac = 0;
    uint8_t port = context->port;

    /*
     * Looking for 5 msec delay. Since the loop time is also roughly 1us, half
     * the count.
     */
    uint16_t timeout = 2500;

    state  = Cy_SysLib_EnterCriticalSection();

    if(false == context->vbtrIdle)
    {
        if ((pd->intr8 & PDSS_INTR8_VBTR_OPR_DONE) == 0u)
        {
            /* Abort the VBTR operation */
            pd->vbtr_ctrl |= PDSS_VBTR_CTRL_EXIT;

            /* Boost VBTR clock to 1MHz to speed up the abort operation */
            if (port == 0u)
            {
                Cy_SysClk_PeriphSetDivider(CY_SYSCLK_DIV_16_BIT, 0U, hfclk_mhz);
            }
#if (NO_OF_TYPEC_PORTS > 1)
            else if (port == 1u)
            {
                Cy_SysClk_PeriphSetDivider(CY_SYSCLK_DIV_16_BIT, 2U, hfclk_mhz);
            }
            else
            {
                /* Do nothing */
            }
#endif /* (NO_OF_TYPEC_PORTS > 1) */

            /*
             * Wait for Exit operation to complete. Since the slowest VBTR is
             * 1ms, we just need to wait for this time.
             */
            while (timeout-- != 0u)
            {
                if (((pd->intr8 & PDSS_INTR8_VBTR_EXIT_DONE)) != 0u)
                {
                    break;
                }

                Cy_SysLib_DelayUs(1u);
            }
        }

        if ((pd->intr8 & (PDSS_INTR8_VBTR_OPR_DONE | PDSS_INTR8_VBTR_EXIT_DONE)) != 0u)
        {
            /* Load latest VBTR source and sink IDAC values to EA control */
            if ((pd->vbtr_cfg & PDSS_VBTR_CFG_SRC_EN) != 0u)
            {
                src_dac_u32 = ((pd->vbtr_src_snk_opr_value & PDSS_VBTR_SRC_SNK_OPR_VALUE_SRC_DAC_MASK) >>
                        PDSS_VBTR_SRC_SNK_OPR_VALUE_SRC_DAC_POS);
                src_dac = (int16_t)src_dac_u32;
            }
            if ((pd->vbtr_cfg & PDSS_VBTR_CFG_SNK_EN) != 0u)
            {
                snk_dac_u32 = ((pd->vbtr_src_snk_opr_value & PDSS_VBTR_SRC_SNK_OPR_VALUE_SNK_DAC_MASK) >>
                        PDSS_VBTR_SRC_SNK_OPR_VALUE_SNK_DAC_POS);
                snk_dac = (int16_t)snk_dac_u32;
            }

            /* 
             * Load iDAC accordingly. We need to copy the value from the VBTR shadow register to 
             * main register. Also load the TRIMs based on the current iDAC as to where the abort happened.
             */
            Cy_USBPD_Hal_Set_Fb_Dac(context, (snk_dac - src_dac));
        }

        pd->vbtr_cfg = 0;
        pd->intr8 = (PDSS_INTR8_VBTR_EXIT_DONE | PDSS_INTR8_VBTR_OPR_DONE);
        pd->vbtr_ctrl &= ~(PDSS_VBTR_CTRL_START | PDSS_VBTR_CTRL_EXIT);

#if defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)
#if BB_VBTR_IBTR_FCCM_DIS
        /* Re-enable FCCM once VBTR/IBTR is done */
        Cy_USBPD_BB_SetMode(port, BB_MODE_FCCM);
#endif /* BB_VBTR_IBTR_FCCM_DIS */
#endif /* defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1) */

        /* Reset VBTR variables */
        context->vbtrIdle = true;
#if VBTR_MULTI_SLOPE_ENABLE
        context->vbtrSrcPending = false;
        context->vbtrSnkPending = false;
#endif  /* VBTR_MULTI_SLOPE_ENABLE */
    }
#if PSVP_FPGA_ENABLE
    ctrl_inf_vbtr_reset();
#endif /* PSVP_FPGA_ENABLE */
    Cy_SysLib_ExitCriticalSection(state);
#else
    CY_UNUSED_PARAMETER(context);
#endif /* PDL_VBTR_ENABLE */
}
/*******************************************************************************
* Function Name: Cy_USBPD_IBTR_IsIdle
****************************************************************************//**
*
* Gets the current status of the IBTR module.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \return
* Idle state of the IBTR module. Returns False if IBTR Vbus voltage
* transition is in progress.
*
*******************************************************************************/
bool Cy_USBPD_IBTR_IsIdle(cy_stc_usbpd_context_t *context)
{
#if PDL_IBTR_ENABLE    
    return context->ibtrIdle;
#else
    CY_UNUSED_PARAMETER(context);
    return true;
#endif /* PDL_IBTR_ENABLE */
}
/*******************************************************************************
* Function Name: Cy_USBPD_IBTR_Set
****************************************************************************//**
*
* Configures VBUS current transition operation for the requested idac value.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \param refgen_req
* Signed iDAC value. Negative for source and positive for sink.
*
* \param ibtr_cb
* Callback to notify IBTR events.
*
*
*******************************************************************************/
void Cy_USBPD_IBTR_Set(cy_stc_usbpd_context_t *context, uint16_t refgen_req, cy_cb_adc_events_t ibtr_cb)
{
#if PDL_IBTR_ENABLE    
    PPDSS_REGS_T pd = context->base;
    context->ibtrCbk = ibtr_cb;
    uint32_t state;
    int16_t refgen_cur = 0;
    uint32_t refgen;

    state  = Cy_SysLib_EnterCriticalSection();

    refgen_cur = (pd->refgen_3_ctrl & PDSS_REFGEN_3_CTRL_SEL10_MASK) >> PDSS_REFGEN_3_CTRL_SEL10_POS;

    /* Calculate reference setting required for 1A. */
    Cy_USBPD_CSA_Calc_Ref(context, CY_USBPD_I_1A, CC_GAIN_VALUE, &refgen, false);

    /*
     * If initial EA comparator refgen is less than 1A, do a direct refgen
     * jump to set 1A. Then IBTR can do the remaining transition.
     * This is to make sure, IBTR will not add delay for the transition
     * from the default 0A to 1A refgen.
     */
    if (refgen_cur < refgen)
    {
#if PSVP_FPGA_ENABLE
        ctrl_inf_cf_enable(CY_USBPD_I_1A);
#endif /* PSVP_FPGA_ENABLE */
        CY_USBPD_REG_FIELD_UPDATE(pd->refgen_3_ctrl, PDSS_REFGEN_3_CTRL_SEL10, refgen);
        refgen_cur = refgen;
    }

    /*
     * IBTR request is needed only if requested refgen value is different than
     * the current refgen value.
     */
    if(refgen_req != refgen_cur)
    {
        if(refgen_req > refgen_cur)
        {
            pd->ibtr_cfg |= PDSS_IBTR_CFG_IBTR_UP_DOWN;
        }
        else
        {
            pd->ibtr_cfg &= ~PDSS_IBTR_CFG_IBTR_UP_DOWN;
        }

        /* Set step width for IBTR. */
#if PSVP_FPGA_ENABLE
        Cy_SysClk_PeriphSetDivider(CY_SYSCLK_DIV_16_BIT, 1U, 24);
#else
        Cy_SysClk_PeriphSetDivider(CY_SYSCLK_DIV_16_BIT, 1U, ((Cy_SysClk_ClkHfGetFrequency() / 1000000) * IBTR_STEP_WIDTH));
#endif /* PSVP_FPGA_ENABLE */

        /* Set initial and final values */
        pd->ibtr_init_fin_value = (((refgen_cur << PDSS_IBTR_INIT_FIN_VALUE_IBTR_INIT_POS) &
                PDSS_IBTR_INIT_FIN_VALUE_IBTR_INIT_MASK) |
                ((refgen_req << PDSS_IBTR_INIT_FIN_VALUE_IBTR_FIN_POS) &
                PDSS_IBTR_INIT_FIN_VALUE_IBTR_FIN_MASK));

        /* Clear and enable IBTR interrupt */
        pd->intr8 = (PDSS_INTR8_IBTR_OPR_DONE | PDSS_INTR8_IBTR_EXIT_DONE);
        pd->intr8_mask |= (PDSS_INTR8_IBTR_OPR_DONE);

#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
#if BB_VBTR_IBTR_FCCM_DIS
        /* During VBTR/IBTR, FCCM must be disabled */
        bb_set_mode(port, BB_MODE_PSM);
#endif /* BB_VBTR_IBTR_FCCM_DIS */
#endif /* (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) */

        /* Start IBTR operation */
        context->ibtrIdle = false;
        pd->ibtr_cfg |= PDSS_IBTR_CFG_IBTR_EN;
        pd->ibtr_ctrl |= PDSS_IBTR_CTRL_START;
    }
    else
    {
        /* Do nothing */
    }

    Cy_SysLib_ExitCriticalSection(state);
#else
    CY_UNUSED_PARAMETER(context);
    CY_UNUSED_PARAMETER(refgen_req);
    (void)(cy_cb_adc_events_t)(ibtr_cb);
#endif /* PDL_IBTR_ENABLE */
}
/*******************************************************************************
* Function Name: Cy_USBPD_IBTR_Abort
****************************************************************************//**
*
* Aborts the ongoing VBUS current transition operation.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
*
*******************************************************************************/
void Cy_USBPD_IBTR_Abort(cy_stc_usbpd_context_t *context)
{
#if PDL_IBTR_ENABLE    
    PPDSS_REGS_T pd = context->base;
    uint32_t state = 0;
    uint16_t ibtr_dac = 0;
    /*
     * Looking for 5 msec delay. Since the loop time is also roughly 1us, half
     * the count.
     */
    uint16_t timeout = 2500;

    state  = Cy_SysLib_EnterCriticalSection();
    if (context->ibtrIdle == false)
    {
        if ((pd->intr8 & PDSS_INTR8_IBTR_OPR_DONE) == 0)
        {
            /* Abort the IBTR operation */
            pd->ibtr_ctrl |= PDSS_IBTR_CTRL_EXIT;

            /*
             * Boost clock to 1MHz to speed up the abort operation.
             */
#if PSVP_FPGA_ENABLE
            Cy_SysClk_PeriphSetDivider(CY_SYSCLK_DIV_16_BIT, 1U, 24);
#else
            Cy_SysClk_PeriphSetDivider(CY_SYSCLK_DIV_16_BIT, 1U, (Cy_SysClk_ClkHfGetFrequency() / 1000000));
#endif /* PSVP_FPGA_ENABLE */

            /*
             * Wait for Exit operation to complete. Since the slowest IBTR is
             * 1ms, we just need to wait for this time.
             */
            while (timeout-- != 0)
            {
                if ((pd->intr8 & PDSS_INTR8_IBTR_EXIT_DONE))
                {
                    break;
                }

                Cy_SysLib_DelayUs(1);
            }
        }

        if (pd->intr8 & (PDSS_INTR8_IBTR_OPR_DONE | PDSS_INTR8_IBTR_EXIT_DONE))
        {
            /* Load latest IBTR DAC values to EA comparator refgen */
            if (pd->ibtr_cfg & PDSS_IBTR_CFG_IBTR_EN)
            {
                ibtr_dac = ((pd->ibtr_opr_value & PDSS_IBTR_OPR_VALUE_IBTR_DAC_MASK) >>
                        PDSS_IBTR_OPR_VALUE_IBTR_DAC_POS);
                CY_USBPD_REG_FIELD_UPDATE(pd->refgen_3_ctrl, PDSS_REFGEN_3_CTRL_SEL10, ibtr_dac);
            }
        }

        pd->ibtr_cfg = 0;
        pd->intr8 = (PDSS_INTR8_IBTR_EXIT_DONE | PDSS_INTR8_IBTR_OPR_DONE);
        pd->ibtr_ctrl &= ~(PDSS_IBTR_CTRL_START | PDSS_IBTR_CTRL_EXIT);

#if defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)
#if BB_VBTR_IBTR_FCCM_DIS
        /* Re-enable FCCM once VBTR/IBTR is done */
        bb_set_mode(port, BB_MODE_FCCM);
#endif /* BB_VBTR_IBTR_FCCM_DIS */
#endif /* defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1) */

        context->ibtrIdle = true;
    }
    Cy_SysLib_ExitCriticalSection(state);
#else
    CY_UNUSED_PARAMETER(context);
#endif /* PDL_IBTR_ENABLE */
}
#endif /* (defined(CY_IP_MXUSBPD) || defined(CY_IP_M0S8USBPD)) */

/* [] END OF FILE */
