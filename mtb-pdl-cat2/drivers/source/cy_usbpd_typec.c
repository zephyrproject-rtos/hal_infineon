/***************************************************************************//**
* \file cy_usbpd_typec.c
* \version 2.110
*
* The source file of the USBPD TypeC driver.
*
********************************************************************************
* \copyright
* (c) (2021-2025), Cypress Semiconductor Corporation (an Infineon company) or
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
#include "cy_device_headers.h"

#if (defined(CY_IP_MXUSBPD) || defined(CY_IP_M0S8USBPD))

#include "cy_usbpd_defines.h"
#include "cy_usbpd_common.h"
#include "cy_usbpd_typec.h"
#include "cy_usbpd_vbus_ctrl.h"
#include "cy_usbpd_bch.h"
#include "cy_usbpd_hpd.h"
#include "cy_usbpd_idac_ctrl.h"
#include "cy_usbpd_config_table.h"

#if defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)
#include "cy_usbpd_buck_boost.h"
#endif /* defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1) */

/* Safe level of VBUS (in mV) that is required for CCGx to operate based on VBUS power. */
#define VBUS_OPERATING_MINIMUM  (3200u)

/* No of Rd rows and entries per row, in the thresholds LUT. */
#define RD_ROW_NO                       (3u)
#define RD_COL_WIDTH                    (4u)

#define AMUX_CTRL_EA_TOP_REFGEN_SEL7_EN         (0x02U)

/* PMG1S0 enable VBUS_IN resistor divider for TYPE-C VBUS monitoring using ADC. */
#define AMUX_ADC_PMG1S0_VBUS_IN_8P_EN_POS        (7)
#define AMUX_ADC_PMG1S0_VBUS_IN_20P_EN_POS       (4)

/* PMG1S0 discharge drive strength settings. */
#define PMG1S0_DISCHG_DS_VBUS_C_00               (1U)
#define PMG1S0_DISCHG_DS_VBUS_IN_00              (1U)

/* TRIM0_TX_TRIM register needs to be overwritten by firmware. */
#define TRIM0_TX_TRIM_VALUE_3A                  (2U)
#define TRIM0_TX_TRIM_VALUE_900MA               (0U)

/* The TRIM6 and TRIM3 registers needs to be overwritten by firmware. */
#define SILICON_TRIM6_V1P575_TRIM_VALUE         (3U)
#define SILICON_TRIM3_V0P55_TRIM_VALUE          (2U)

#if defined(CY_DEVICE_PMG1S3)
#define SFLASH_SCP_RCP_VREF_TRIM_HOT            (0x0FFFF430u)
#define SFLASH_SCP_RCP_VREF_TRIM_COLD           (0x0FFFF446u)
#define SFLASH_SCP_RCP_VREF_TRIM_ROOM           (0x0FFFF45Cu)
#endif /* defined(CY_DEVICE_PMG1S3) */

#if defined(CY_DEVICE_CCG6)
#define CLK_LF_FILT_NUM (2UL)
#endif /* defined(CY_DEVICE_CCG6) */

#if defined(CY_DEVICE_PMG1S3)
#define CLK_LF_FILT_NUM (4UL)
#define CLK_LF_FILT_SBU1 (1UL)
#define CLK_LF_FILT_SBU2 (2UL)
#endif /* defined(CY_DEVICE_PMG1S3) */

/* SBU comparator reference set voltage (130 + 107*10 = 1200 mV)*/
#define SBU_COMP_VREF_1_2_V            107UL

/**
 * Type C voltage thresholds (in mV) as per Section 4.11.3 of Type C
 * specification Rev1.
 */
static const uint8_t thresholds[4][4] =
{
    {PD_CMP_VSEL_0_2_V, PD_CMP_VSEL_1_77_V, 0, 0}, /* Rp USB default row. */
    {PD_CMP_VSEL_0_4_V, PD_CMP_VSEL_1_77_V, 0, 0}, /* Rp 1.5A row. */
    {PD_CMP_VSEL_0_8_V, PD_CMP_VSEL_2_6_V, 0, 0}, /* Rp 3A row. */
    {PD_CMP_VSEL_0_2_V, PD_CMP_VSEL_0_655_V, PD_CMP_VSEL_1_235_V, PD_CMP_VSEL_2_6_V}, /* RD row. */
};

void Cy_USBPD_Phy_VbusDetachCbk (
        void *context,
        bool  compOut)
{
    /* Do nothing. */
    CY_UNUSED_PARAMETER(context);
    CY_UNUSED_PARAMETER(compOut);
}

/*******************************************************************************
* Function Name: Cy_USBPD_TypeC_GetRpRdStatus
****************************************************************************//**
* 
* This function returns the current status on the CC line
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \param channel
* Channel index, where CC1 = 0, CC2 = 1
* 
* \param rd_idx
* Rd termination index in sink mode
*
* \return uint8_t
* Rp status when Rp is asserted \ref cy_en_pd_rp_cc_status_t.
* Rd status when Rd is asserted \ref cy_en_pd_rd_cc_status_t.
*
*******************************************************************************/
uint8_t Cy_USBPD_TypeC_GetRpRdStatus (
        cy_stc_usbpd_context_t *context, 
        uint8_t channel, 
        bool rd_idx)
{
#if (!CY_PD_SINK_ONLY)
    cy_stc_pd_dpm_config_t *dpmConfig = context->dpmGetConfig();
    bool     isSrc = true;
#endif /* (!CY_PD_SINK_ONLY) */

    PPDSS_REGS_T pd = context->base;
    uint32_t rval = 0;
    uint32_t temp = 0;
    uint8_t  out = 0;
    uint8_t index = (uint8_t)rd_idx;
    uint32_t value = 0;

#if (!CY_PD_SINK_ONLY)
    /* Set default output. */
    if (dpmConfig->curPortRole == CY_PD_PRT_ROLE_SOURCE)
    {
        out = (uint8_t)CY_PD_RP_OPEN;
    }
    else
#endif /* (!CY_PD_SINK_ONLY) */
    {
        out = ((uint8_t)CY_PD_RD_RA + index);
#if (!CY_PD_SINK_ONLY)
        isSrc = false;
#endif /* (!CY_PD_SINK_ONLY) */

#if PSVP_FPGA_ENABLE
        /* Set the RP SEL value as 3A based on rd_idx to ensure that the AFE uses the correct value. */
        if (rd_idx == true)
        {
            pd->cc_ctrl_0 = (pd->cc_ctrl_0 & ~PDSS_CC_CTRL_0_RP_MODE_MASK) | (3UL << PDSS_CC_CTRL_0_RP_MODE_POS);
        }
        else
        {
            pd->cc_ctrl_0 = (pd->cc_ctrl_0 & ~PDSS_CC_CTRL_0_RP_MODE_MASK);
        }
#endif /* PSVP_FPGA_ENABLE */
    }

    /* Connect both the Up/Dn comparators to the active CC line. */
    if (channel == CY_PD_CC_CHANNEL_2)
    {
        rval = (PDSS_CC_CTRL_0_CMP_DN_CC1V2 | PDSS_CC_CTRL_0_CMP_UP_CC1V2);

#if PSVP_FPGA_ENABLE
        rval |= PDSS_CC_CTRL_0_CC_1V2;
#endif /* PSVP_FPGA_ENABLE */
    }
#if PSVP_FPGA_ENABLE
    else
    {
        rval &= ~PDSS_CC_CTRL_0_CC_1V2;
    }
#endif /* PSVP_FPGA_ENABLE */

#if (!CY_PD_SINK_ONLY)
    if (isSrc)
    {
        /*
         * Set the threshold of the Dn comparator to Ra level and the Up
         * comparator to Rp open level.
         */
        rval |= (((uint32_t)thresholds[dpmConfig->srcCurLevelLive][0]) << PDSS_CC_CTRL_0_CMP_DN_VSEL_POS) |
            (((uint32_t)thresholds[dpmConfig->srcCurLevelLive][1]) << PDSS_CC_CTRL_0_CMP_UP_VSEL_POS);
    }
    else
#endif /* (!CY_PD_SINK_ONLY) */
    {
        /* Set the Dn comparator to vRdUSB and the Up comparator to vRd1.5A. */
        rval |= (((uint32_t)thresholds[RD_ROW_NO][index]) << PDSS_CC_CTRL_0_CMP_DN_VSEL_POS) |
            (((uint32_t)thresholds[RD_ROW_NO][index + 1U]) << PDSS_CC_CTRL_0_CMP_UP_VSEL_POS);
    }

    value = (uint32_t)(
            PDSS_CC_CTRL_0_CMP_DN_CC1V2 |
            PDSS_CC_CTRL_0_CMP_UP_CC1V2 |
#if PSVP_FPGA_ENABLE
            PDSS_CC_CTRL_0_CC_1V2 |
#endif /* PSVP_FPGA_ENABLE */
            PDSS_CC_CTRL_0_CMP_DN_VSEL_MASK |
            PDSS_CC_CTRL_0_CMP_UP_VSEL_MASK
            );

    temp = (uint32_t)(pd->cc_ctrl_0 & value);
    if (temp != rval)
    {
#if PSVP_FPGA_ENABLE
#if (!CY_PD_SINK_ONLY)
        if (!isSrc)
#endif /* (!CY_PD_SINK_ONLY) */
        {
            if (rd_idx)
            {
                {
                    /* Set RP_SEL as 3A Rp to let HEB know that higher gl_thresholds should be used. */
                    pd->cc_ctrl_0 = (pd->cc_ctrl_0 & ~(PDSS_CC_CTRL_0_CMP_DN_CC1V2 | PDSS_CC_CTRL_0_CMP_UP_CC1V2 |
                                PDSS_CC_CTRL_0_CC_1V2 | PDSS_CC_CTRL_0_CMP_DN_VSEL_MASK |
                                PDSS_CC_CTRL_0_CMP_UP_VSEL_MASK | PDSS_CC_CTRL_0_RP_MODE_MASK)) |
                        (3 << PDSS_CC_CTRL_0_RP_MODE_POS) | rval;
                }
            }
            else
            {
                {
                    /* Set RP_SEL as Default Rp to let HEB know that lower gl_thresholds should be used. */
                    pd->cc_ctrl_0 = (pd->cc_ctrl_0 & ~(PDSS_CC_CTRL_0_CMP_DN_CC1V2 | PDSS_CC_CTRL_0_CMP_UP_CC1V2 |
                                PDSS_CC_CTRL_0_CC_1V2 | PDSS_CC_CTRL_0_CMP_DN_VSEL_MASK |
                                PDSS_CC_CTRL_0_CMP_UP_VSEL_MASK | PDSS_CC_CTRL_0_RP_MODE_MASK)) | rval;
                }
            }
        }
#if (!CY_PD_SINK_ONLY)
        else
        {
            pd->cc_ctrl_0 = (pd->cc_ctrl_0 & ~(PDSS_CC_CTRL_0_CMP_DN_CC1V2 | PDSS_CC_CTRL_0_CMP_UP_CC1V2 |
                        PDSS_CC_CTRL_0_CC_1V2 | PDSS_CC_CTRL_0_CMP_DN_VSEL_MASK |
                        PDSS_CC_CTRL_0_CMP_UP_VSEL_MASK)) | rval;
        }
#endif /* (!CY_PD_SINK_ONLY) */

        /* Delay to allow references to settle. */
        Cy_SysLib_DelayUs (125);
#else /* !PSVP_FPGA_ENABLE */
        pd->cc_ctrl_0 &= ~(value);
        pd->cc_ctrl_0 |= rval;

        /* Delay to allow references to settle. */
        Cy_SysLib_DelayUs (50);
#endif /* !PSVP_FPGA_ENABLE */
    }

#if defined(CY_IP_MXUSBPD)

    temp = (uint32_t)(pd->intr1_status & (PDSS_INTR1_STATUS_VCMP_DN_STATUS | PDSS_INTR1_STATUS_VCMP_UP_STATUS));
    if ((temp & PDSS_INTR1_STATUS_VCMP_UP_STATUS) != 0U)
    {
#if (!CY_PD_SINK_ONLY)
        if (!isSrc)
#endif /* (!CY_PD_SINK_ONLY) */
        {
            out = ((uint8_t)CY_PD_RD_1_5A + index);
        }
    }
    else
    {
        if ((temp & PDSS_INTR1_STATUS_VCMP_DN_STATUS) != 0U)
        {
#if (!CY_PD_SINK_ONLY)
            if (isSrc)
            {
                out = (uint8_t)(CY_PD_RP_RD);
            }
            else
#endif /* (!CY_PD_SINK_ONLY) */
            {
                out = ((uint8_t)CY_PD_RD_USB + index);
            }
        }
#if (!CY_PD_SINK_ONLY)
        else
        {
            if (isSrc)
            {
                out = (uint8_t)(CY_PD_RP_RA);
            }
        }
#endif /* (!CY_PD_SINK_ONLY) */
    }

#elif defined(CY_IP_M0S8USBPD)

    temp = pd->status;
    if ((temp & PDSS_STATUS_VCMP_UP_STATUS) != 0U)
    {
#if (!CY_PD_SINK_ONLY)
        if (!isSrc)
#endif /* (!CY_PD_SINK_ONLY) */
        {
            out = ((uint8_t)CY_PD_RD_1_5A + index);
        }
    }
    else
    {
        if ((temp & PDSS_STATUS_VCMP_DN_STATUS) != 0U)
        {
#if (!CY_PD_SINK_ONLY)
            if (isSrc)
            {
                out = (uint8_t)(CY_PD_RP_RD);
            }
            else
#endif /* (!CY_PD_SINK_ONLY) */
            {
                out = ((uint8_t)CY_PD_RD_USB + index);
            }
        }
#if (!CY_PD_SINK_ONLY)
        else
        {
            if (isSrc)
            {
                out = (uint8_t)CY_PD_RP_RA;
            }
        }
#endif /* (!CY_PD_SINK_ONLY) */
    }

#else
    #error "Unsupported IP"
#endif

    return out;
}


#if SYS_DEEPSLEEP_ENABLE
static void Cy_USBPD_TypeC_PhyDetectCCRise (
        cy_stc_usbpd_context_t *context,
        bool rpConnected)
{
    PPDSS_REGS_T pd = context->base;
    cy_stc_pd_dpm_config_t *dpmConfig = context->dpmGetConfig();
    uint8_t threshold_row = RD_ROW_NO;
    uint8_t threshold_col = 0;

    /* Connect UP comparator to CC1 and down comparator to CC2 */
    pd->cc_ctrl_0 = PDSS_CC_CTRL_0_CMP_DN_CC1V2 |
        (pd->cc_ctrl_0 &
         ~(PDSS_CC_CTRL_0_CMP_UP_CC1V2 | PDSS_CC_CTRL_0_CMP_UP_VSEL_MASK | PDSS_CC_CTRL_0_CMP_DN_VSEL_MASK));

    if (rpConnected)
    {
        /* Set the comparator voltage references based on the active Rp level applied by us. */
        threshold_row = dpmConfig->srcCurLevelLive;
        if (dpmConfig->attachedDev == CY_PD_DEV_DBG_ACC)
        {
            threshold_col = 1;
        }
    }

    pd->cc_ctrl_0 |= ((thresholds[threshold_row][threshold_col]) << PDSS_CC_CTRL_0_CMP_UP_VSEL_POS) |
        ((thresholds[threshold_row][threshold_col]) << PDSS_CC_CTRL_0_CMP_DN_VSEL_POS);

#if defined(CY_IP_MXUSBPD)
    pd->intr1_cfg_vcmp_up_down_ls &= ~(PDSS_INTR1_CFG_VCMP_UP_DOWN_LS_VCMP_UP_CFG_MASK |
            PDSS_INTR1_CFG_VCMP_UP_DOWN_LS_VCMP_UP_FILT_EN |
            PDSS_INTR1_CFG_VCMP_UP_DOWN_LS_VCMP_UP_FILT_BYPASS |
            PDSS_INTR1_CFG_VCMP_UP_DOWN_LS_VCMP_DN_CFG_MASK |
            PDSS_INTR1_CFG_VCMP_UP_DOWN_LS_VCMP_DN_FILT_EN |
            PDSS_INTR1_CFG_VCMP_UP_DOWN_LS_VCMP_DN_FILT_BYPASS);
    pd->intr1_cfg_vcmp_up_down_ls |= (((CY_USBPD_ADC_INT_RISING) << PDSS_INTR1_CFG_VCMP_UP_DOWN_LS_VCMP_UP_CFG_POS) |
            ((CY_USBPD_ADC_INT_RISING) << PDSS_INTR1_CFG_VCMP_UP_DOWN_LS_VCMP_DN_CFG_POS) |
            (PDSS_INTR1_CFG_VCMP_UP_DOWN_LS_VCMP_UP_FILT_EN | PDSS_INTR1_CFG_VCMP_UP_DOWN_LS_VCMP_DN_FILT_EN));
#elif defined(CY_IP_M0S8USBPD)
    pd->intr_1_cfg &= ~(PDSS_INTR_1_CFG_VCMP_UP_CFG_MASK | PDSS_INTR_1_CFG_VCMP_DN_CFG_MASK);
    pd->intr_1_cfg |= ((CY_USBPD_ADC_INT_RISING) << PDSS_INTR_1_CFG_VCMP_UP_CFG_POS) |
        ((CY_USBPD_ADC_INT_RISING) << PDSS_INTR_1_CFG_VCMP_DN_CFG_POS);
#endif /* defined(CY_IP_M0S8USBPD) */

    Cy_SysLib_DelayUs (10);
    pd->intr1 = (PDSS_INTR1_VCMP_UP_CHANGED | PDSS_INTR1_VCMP_DN_CHANGED | PDSS_INTR1_VCMP_LA_CHANGED);
    pd->intr1_mask |= (PDSS_INTR1_VCMP_UP_CHANGED | PDSS_INTR1_VCMP_DN_CHANGED);

    /* If comparators have already triggered, then set any one interrupt to ensure device does not go into sleep. */
#if defined(CY_IP_MXUSBPD)
    if (pd->intr1_status & (PDSS_INTR1_STATUS_VCMP_UP_STATUS | PDSS_INTR1_STATUS_VCMP_DN_STATUS))
    {
        pd->intr1_set |= PDSS_INTR1_VCMP_UP_CHANGED;
    }
#elif defined(CY_IP_M0S8USBPD)
    if (pd->status & (PDSS_STATUS_VCMP_UP_STATUS | PDSS_STATUS_VCMP_DN_STATUS))
    {
        pd->intr1_set |= PDSS_INTR1_VCMP_UP_CHANGED;
    }
#endif /* CY_IP */
}

#endif /* SYS_DEEPSLEEP_ENABLE */

/*******************************************************************************
* Function Name: Cy_USBPD_Pump_Disable
****************************************************************************//**
* 
* Disable the charge pump
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \param index
* Charge pump index
*
* \return
* None
*
*******************************************************************************/
void Cy_USBPD_Pump_Disable (
        cy_stc_usbpd_context_t *context, 
        uint8_t index)
{
#if (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP))
    context->base->pump5v_ctrl[index] |= PDSS_PUMP5V_CTRL_PUMP5V_BYPASS_LV;
    Cy_SysLib_DelayUs (10);
    context->base->pump5v_ctrl[index]  = PDSS_PUMP5V_CTRL_DEFAULT;
#elif (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
    CY_UNUSED_PARAMETER(index);
    context->base->pump5v_ctrl |= PDSS_PUMP5V_CTRL_PUMP5V_BYPASS_LV;
    Cy_SysLib_DelayUs (10);
    context->base->pump5v_ctrl = PDSS_PUMP5V_CTRL_DEFAULT;
#else /* CY_DEVICE_CCG3PA */
    CY_UNUSED_PARAMETER(index);
    context->base->pump_ctrl |= (PDSS_PUMP_CTRL_PD_PUMP | PDSS_PUMP_CTRL_BYPASS_LV);
#endif /* (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP)) */
}

/*******************************************************************************
* Function Name: Cy_USBPD_Pump_Enable
****************************************************************************//**
* 
* Enable the charge pump
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \param index
* Charge pump index
*
* \return
* None
*
*******************************************************************************/
void Cy_USBPD_Pump_Enable (
        cy_stc_usbpd_context_t *context,
        uint8_t index)
{
#if (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP))
    PPDSS_REGS_T pd = context->base;

    /* Enable the pump only if it is not already on. */
    if ((pd->pump5v_ctrl[index] & PDSS_PUMP5V_CTRL_PUMP5V_PUMP_EN) == 0u)
    {
        pd->pump5v_ctrl[index] = PDSS_PUMP5V_CTRL_PUMP5V_PUMP_EN | PDSS_PUMP5V_CTRL_PUMP5V_BYPASS_LV;
        Cy_SysLib_DelayUs (10);
        pd->pump5v_ctrl[index] = PDSS_PUMP5V_CTRL_PUMP5V_PUMP_EN;
        Cy_SysLib_DelayUs (40);
        pd->pump5v_ctrl[index] = PDSS_PUMP5V_CTRL_PUMP5V_PUMP_EN | PDSS_PUMP5V_CTRL_PUMP5V_DEL_PUMP_EN;
    }
#elif(defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
    /* Enable the pump only if it is not already on. */
    PPDSS_REGS_T pd = context->base;
    if ((pd->pump5v_ctrl & PDSS_PUMP5V_CTRL_PUMP5V_PUMP_EN) == 0u)
    {

#if defined(CY_DEVICE_SERIES_PMG1B1)
        pd->pump5v_ctrl = PDSS_PUMP5V_CTRL_PUMP5V_PUMP_EN;
        Cy_SysLib_DelayUs (10);
#else
        pd->pump5v_ctrl = PDSS_PUMP5V_CTRL_PUMP5V_PUMP_EN | PDSS_PUMP5V_CTRL_PUMP5V_BYPASS_LV;
        Cy_SysLib_DelayUs (10);
#endif /* #if defined(CY_DEVICE_SERIES_PMG1B1) */

    }
    CY_UNUSED_PARAMETER(index);
#else /* CY_DEVICE_CCG3PA */
    CY_UNUSED_PARAMETER(index);
    context->base->pump_ctrl &= ~(PDSS_PUMP_CTRL_PD_PUMP | PDSS_PUMP_CTRL_BYPASS_LV);
#endif /* (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP)) */
}
#if CY_USBPD_CGND_SHIFT_ENABLE
/*******************************************************************************
* Function Name: Cy_USBPD_TypeC_CgndWrapperEnable
****************************************************************************//**
* 
* Enables CC GND Wrapper
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
*
* \return
* None
*
*******************************************************************************/
void Cy_USBPD_TypeC_CgndWrapperEnable(cy_stc_usbpd_context_t *context)
{
    PPDSS_REGS_T pd = context->base;

    pd->cc_ctrl_2 |= PDSS_CC_CTRL_2_CC_EN_BIASGEN_WRAP;

    uint32_t regval = pd->cc_ctrl_2;

    regval |= PDSS_CC_CTRL_2_CC_EN_VCCDSH_REG_WRAP;
    regval |= PDSS_CC_CTRL_2_CC_EN_V0P74_BUFF_WRAP;
    regval |= PDSS_CC_CTRL_2_CC_EN_V1P1_BUFF_WRAP;
    regval &= ~PDSS_CC_CTRL_2_CC_BYP_BIASGEN_WRAP;

    pd->cc_ctrl_2 = regval;

    Cy_SysLib_DelayUs(100);
}
/*******************************************************************************
* Function Name: Cy_USBPD_TypeC_CgndWrapperDisable
****************************************************************************//**
* 
* Disables CC GND Wrapper
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
*
* \return
* None
*
*******************************************************************************/
void Cy_USBPD_TypeC_CgndWrapperDisable(cy_stc_usbpd_context_t *context)
{
    PPDSS_REGS_T pd = context->base;

    pd->cc_ctrl_2 = 0x00u;

    Cy_SysLib_DelayUs(100);
}
#endif /* CY_USBPD_CGND_SHIFT_ENABLE */

/*******************************************************************************
* Function Name: Cy_USBPD_TypeC_Init
****************************************************************************//**
* 
* This function initializes the Type-C registers in the PD block.
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \return
* CY_USBPD_STAT_SUCCESS if operation is successful, 
* CY_USBPD_STAT_BAD_PARAM if the context pointer is invalid.
*
*******************************************************************************/
cy_en_usbpd_status_t Cy_USBPD_TypeC_Init (
        cy_stc_usbpd_context_t *context)
{
    PPDSS_REGS_T pd = NULL;

    if (context == NULL)
    {
        return CY_USBPD_STAT_BAD_PARAM;
    }

    pd = context->base;

#if !defined(CY_DEVICE_CCG6DF_CFP)
    pd->cc_ctrl_0 &= ~(PDSS_CC_CTRL_0_HYST_MODE | PDSS_CC_CTRL_0_EN_HYST | PDSS_CC_CTRL_0_CMP_LA_VSEL_MASK);
    pd->cc_ctrl_0 |= (PDSS_CC_CTRL_0_CMP_LA_VSEL_CFG << PDSS_CC_CTRL_0_CMP_LA_VSEL_POS);
#endif /* !defined(CY_DEVICE_CCG6DF_CFP) */

#if defined(CY_IP_MXUSBPD)

#if defined(CY_DEVICE_CCG6DF_CFP)
    pd->pd_ref_gen_ctrl &= ~PDSS_PD_REF_GEN_CTRL_PD;
#else
    pd->dpslp_ref_ctrl &= ~PDSS_DPSLP_REF_CTRL_PD_DPSLP;
#endif /* defined(CY_DEVICE_CCG6DF_CFP) */

    /*
     * Up/Down comparators filter will only be enabled before going to
     * deepsleep and disabled after coming out of deepsleep.
     */
    pd->intr1_cfg_vcmp_up_down_ls &= ~(PDSS_INTR1_CFG_VCMP_UP_DOWN_LS_VCMP_DN_FILT_EN |
                                       PDSS_INTR1_CFG_VCMP_UP_DOWN_LS_VCMP_UP_FILT_EN);

#if defined(CY_DEVICE_CCG3PA)
    /* Disable filter on comparator 1 and comparator 2 outputs. */
    pd->intr3_cfg_adc_hs[0] &= ~(PDSS_INTR3_CFG_ADC_HS_FILT_EN);
    pd->intr3_cfg_adc_hs[1] &= ~(PDSS_INTR3_CFG_ADC_HS_FILT_EN);
#endif /* defined(CY_DEVICE_CCG3PA) */

#if (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP))
    /* Disable filter on comparator output. */
    pd->intr3_cfg_adc_hs &= ~(PDSS_INTR3_CFG_ADC_HS_FILT_EN);
    pd->intr3_cfg_adc_hs |= PDSS_INTR3_CFG_ADC_HS_FILT_BYPASS;
#endif /* (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP)) */

#if !(defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
    /* Leave the CC pump enabled. */
    Cy_USBPD_Pump_Enable (context, 0);
#endif /* !(defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) */

#if CY_USBPD_CGND_SHIFT_ENABLE
    Cy_USBPD_TypeC_CgndWrapperEnable(context);
#endif /* CY_USBPD_CGND_SHIFT_ENABLE */

#elif defined(CY_IP_M0S8USBPD)

    /*
     * Up/Down comparators filter will only be enabled before going to
     * deepsleep and disabled after coming out of deepsleep.
     */
    pd->intr_1_cfg &= ~(PDSS_INTR_1_CFG_VCMP_DN_FILT_EN | PDSS_INTR_1_CFG_VCMP_UP_FILT_EN);

    /* Disable filter on comparator 1 and comparator 2 outputs. */
    pd->intr_1_cfg &= ~(PDSS_INTR_1_CFG_CMP_OUT1_FILT_EN | PDSS_INTR_1_CFG_CMP_OUT2_FILT_EN);

    /* Leave the CC pump enabled. */
    pd->pump_ctrl &= ~(PDSS_PUMP_CTRL_PD_PUMP | PDSS_PUMP_CTRL_BYPASS_LV);

#else
    #error "Unsupported IP"
#endif

    return CY_USBPD_STAT_SUCCESS;
}

/*******************************************************************************
* Function Name: Cy_USBPD_TypeC_Start
****************************************************************************//**
* 
* This function starts the Type C Line comparators.
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \return
* CY_USBPD_STAT_SUCCESS if operation is successful, 
* CY_USBPD_STAT_BAD_PARAM if the context pointer is invalid.
*
*******************************************************************************/
cy_en_usbpd_status_t Cy_USBPD_TypeC_Start (
        cy_stc_usbpd_context_t *context)
{
    PPDSS_REGS_T pd = NULL;
#if defined(CY_IP_MXUSBPD)
    uint32_t regVal = 0;
#endif /* defined(CY_IP_MXUSBPD) */

    if (context == NULL)
    {
        return CY_USBPD_STAT_BAD_PARAM;
    }
    pd = context->base;

#if defined(CY_IP_MXUSBPD)
    /* Power up the block. */
    pd->cc_ctrl_0 &= ~PDSS_CC_CTRL_0_PWR_DISABLE;

#if (!CCG_PD_BLOCK_ALWAYS_ON)
    /* Turn off PHY deepsleep. References require 100us to stabilize. */
#if defined(CY_DEVICE_CCG6DF_CFP)
    pd->pd_ref_gen_ctrl &= ~PDSS_PD_REF_GEN_CTRL_PD;
#else
    pd->dpslp_ref_ctrl &= ~PDSS_DPSLP_REF_CTRL_PD_DPSLP;
#endif /* defined(CY_DEVICE_CCG6DF_CFP) */

#if PMG1_PD_DUALPORT_ENABLE
    if((NULL != context->altPortUsbPdCtx[TYPEC_PORT_0_IDX]) && (context->port == TYPEC_PORT_1_IDX))
    {
        /* Deep sleep reference has to be enabled on PD0 block. */
#if defined(CY_DEVICE_CCG6DF_CFP)
        context->altPortUsbPdCtx[TYPEC_PORT_0_IDX]->base->pd_ref_gen_ctrl &= ~PDSS_PD_REF_GEN_CTRL_PD;
#else
        context->altPortUsbPdCtx[TYPEC_PORT_0_IDX]->base->dpslp_ref_ctrl &= ~PDSS_DPSLP_REF_CTRL_PD_DPSLP;
#endif /* defined(CY_DEVICE_CCG6DF_CFP) */
    }
#endif

    /*
     * Enable deep-sleep current reference outputs.
     */
#if defined(CY_DEVICE_CCG6DF_CFP)
    pd->pd_bg_iref8_ctrl |= (0x03u << PDSS_PD_BG_IREF8_CTRL_BG_IREF_EN_POS);
#else
    pd->dpslp_ref_ctrl |= PDSS_DPSLP_REF_CTRL_IGEN_EN;
#endif /* defined(CY_DEVICE_CCG6DF_CFP) */
    Cy_SysLib_DelayUs(100);
#endif /* (!CCG_PD_BLOCK_ALWAYS_ON) */

    /* Enable PUMP */
    Cy_USBPD_Pump_Enable (context, 0);
#if !defined(CY_DEVICE_SERIES_PMG1B1)
    Cy_SysLib_DelayUs(50);
#endif /* !defined(CY_DEVICE_SERIES_PMG1B1) */

    pd->cc_ctrl_0  |= (PDSS_CC_CTRL_0_CMP_EN | PDSS_CC_CTRL_0_RX_EN);

    /* Use voltage reference from refgen to define CC tx_swing. */
    pd->cc_ctrl_1 |= PDSS_CC_CTRL_1_CC_VREF_1P1_SEL;

#if ((defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) && (VBUS_IN_DISCHARGE_EN))
    /* Set VBUS_IN discharge threshold to 5.5V */

    pd->dischg_shv_ctrl[1] |= PDSS_DISCHG_SHV_CTRL_DISCHG_EN_CFG;

    /* Resistor div on VBUS IN already set to 10% in HW */
    /* Configure Reference for comparator. */
    regVal = pd->refgen_4_ctrl;
    regVal &= ~(PDSS_REFGEN_4_CTRL_SEL11_MASK);
    regVal |= (PDSS_VBUS_IN_REF_SEL_VAL << PDSS_REFGEN_4_CTRL_SEL11_POS);
    pd->refgen_4_ctrl = regVal;

    /* Enable Comparator. */
    pd->comp_ctrl[CY_USBPD_VBUS_COMP_ID_VBUS_DISCHARGE] |= PDSS_COMP_CTRL_COMP_ISO_N;
#endif /* ((defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))&& (VBUS_IN_DISCHARGE_EN)) */

#if (defined(CY_DEVICE_PMG1S3)  && (SBU_LEVEL_DETECT_EN != 0))

    pd->refgen_0_ctrl &= ~PDSS_REFGEN_0_CTRL_REFGEN_PD;
    pd->refgen_0_ctrl  |= PDSS_REFGEN_0_CTRL_REFGEN_VREFIN_SEL |
                          PDSS_REFGEN_0_CTRL_REFGEN_VREFIN_MON_SEL;

    /* Configure Reference for comparator. */
    regVal = pd->refgen_2_ctrl;
    regVal &= ~(PDSS_REFGEN_2_CTRL_SEL7_MASK);
    regVal |= (SBU_COMP_VREF_1_2_V << PDSS_REFGEN_2_CTRL_SEL7_POS);
    pd->refgen_2_ctrl = regVal;

    regVal = pd->refgen_3_ctrl;
    regVal &= ~(PDSS_REFGEN_3_CTRL_SEL8_MASK);
    regVal |= (SBU_COMP_VREF_1_2_V << PDSS_REFGEN_3_CTRL_SEL8_POS);
    pd->refgen_3_ctrl = regVal;

    /* Enable Comparator. */
    pd->comp_ctrl[CY_USBPD_VBUS_COMP_ID_P0_SBU1] |= PDSS_COMP_CTRL_COMP_ISO_N;
    pd->comp_ctrl[CY_USBPD_VBUS_COMP_ID_P0_SBU2] |= PDSS_COMP_CTRL_COMP_ISO_N;

    Cy_SysLib_DelayUs(10);

    /* Filter configuration. */
    pd->intr7_filter_cfg[0] = (PDSS_INTR7_FILTER_CFG_CLK_LF_FILT_BYPASS |
                    PDSS_INTR7_FILTER_CFG_CLK_LF_FILT_RESET |
                    ((uint32_t)CY_USBPD_VBUS_FILTER_CFG_POS_EN_NEG_EN << PDSS_INTR7_FILTER_CFG_FILT_CFG_POS));

    pd->intr7_filter_cfg[1] = (PDSS_INTR7_FILTER_CFG_CLK_LF_FILT_BYPASS |
                    PDSS_INTR7_FILTER_CFG_CLK_LF_FILT_RESET |
                    ((uint32_t)CY_USBPD_VBUS_FILTER_CFG_POS_EN_NEG_EN << PDSS_INTR7_FILTER_CFG_FILT_CFG_POS));


    /* Clear interrupt. */
    pd->intr7 = (1U << CLK_LF_FILT_SBU1);
    pd->intr7 = (1U << CLK_LF_FILT_SBU2);

    /* Enable Interrupt. */
    pd->intr7_mask |= (1U << CLK_LF_FILT_SBU1);
    pd->intr7_mask |= (1U << CLK_LF_FILT_SBU2);
#endif /* (defined(CY_DEVICE_PMG1S3) && (SBU_LEVEL_DETECT_EN != 0)) */

#if (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
    pd->refgen_0_ctrl &= ~PDSS_REFGEN_0_CTRL_REFGEN_PD;
    pd->refgen_0_ctrl  |= PDSS_REFGEN_0_CTRL_REFGEN_VREFIN_SEL |
                          PDSS_REFGEN_0_CTRL_REFGEN_VREFIN_MON_SEL;

#if !(defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
    /* Set SEL7 reference (used by EA shunt regulator during deep sleep) to 1.2V */
    pd->refgen_2_ctrl &= ~PDSS_REFGEN_2_CTRL_SEL7_MASK;
    pd->refgen_2_ctrl |= (107UL << PDSS_REFGEN_2_CTRL_SEL7_POS);
#endif /* !(defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) */

    /* Set SEL14 reference (used by cc_shvt block for tx_swing to 1.12 V. */
    pd->refgen_4_ctrl &= ~PDSS_REFGEN_4_CTRL_SEL14_MASK;
    pd->refgen_4_ctrl |= (4UL << PDSS_REFGEN_4_CTRL_SEL14_POS);

    /* Give some delay for references to settle. */
    Cy_SysLib_DelayUs (50);
#endif /* defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1) */

    /* Disable and bypass all filters. */
    regVal = pd->intr1_cfg_cc1_cc2_ls;
    regVal &= ~(PDSS_INTR1_CFG_CC1_CC2_LS_CC1_FILT_EN | PDSS_INTR1_CFG_CC1_CC2_LS_CC2_FILT_EN);
    regVal |= (PDSS_INTR1_CFG_CC1_CC2_LS_CC1_FILT_BYPASS | PDSS_INTR1_CFG_CC1_CC2_LS_CC2_FILT_BYPASS);
    pd->intr1_cfg_cc1_cc2_ls = regVal;

    regVal = pd->intr1_cfg_vcmp_up_down_ls;
    regVal &= ~(PDSS_INTR1_CFG_VCMP_UP_DOWN_LS_VCMP_UP_FILT_EN | PDSS_INTR1_CFG_VCMP_UP_DOWN_LS_VCMP_DN_FILT_EN);
    regVal |= (PDSS_INTR1_CFG_VCMP_UP_DOWN_LS_VCMP_UP_FILT_BYPASS | PDSS_INTR1_CFG_VCMP_UP_DOWN_LS_VCMP_DN_FILT_BYPASS);
    pd->intr1_cfg_vcmp_up_down_ls = regVal;

    /* Set LA config for wakeup */
    pd->intr1_cfg |= PDSS_INTR1_CFG_VCMP_LA_CFG_MASK;

#if defined (CY_DEVICE_CCG6) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1) || defined (CY_DEVICE_PMG1S3) || defined (CY_DEVICE_CCG6DF_CFP)
#if (defined (CY_DEVICE_CCG6) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined (CY_DEVICE_SERIES_WLC1) || defined (CY_DEVICE_CCG6DF_CFP))
#if PDL_CC_OVP_ENABLE
    /* Enable the filter associated with CC1/2 OVP detection. */
#if defined (CY_DEVICE_SERIES_WLC1)
    /* Keep filter to maximum to avoid ground noise issues in WICG1 */
    pd->intr1_cfg_cc12_ovp_hs = (
            (31UL << PDSS_INTR1_CFG_CC12_OVP_HS_CC1_OVP_FILT_SEL_POS) |
            ((uint32_t)CY_USBPD_VBUS_FILTER_CFG_POS_EN_NEG_DIS << PDSS_INTR1_CFG_CC12_OVP_HS_CC1_OVP_FILT_CFG_POS) |
            (PDSS_INTR1_CFG_CC12_OVP_HS_CC1_OVP_DPSLP_MODE) |
            (31UL << PDSS_INTR1_CFG_CC12_OVP_HS_CC2_OVP_FILT_SEL_POS) |
            ((uint32_t)CY_USBPD_VBUS_FILTER_CFG_POS_EN_NEG_DIS << PDSS_INTR1_CFG_CC12_OVP_HS_CC2_OVP_FILT_CFG_POS) |
            (PDSS_INTR1_CFG_CC12_OVP_HS_CC2_OVP_DPSLP_MODE)
            );
#else /* !defined (CY_DEVICE_SERIES_WLC1) */
    pd->intr1_cfg_cc12_ovp_hs = (
            (4UL << PDSS_INTR1_CFG_CC12_OVP_HS_CC1_OVP_FILT_SEL_POS) |
            ((uint32_t)CY_USBPD_VBUS_FILTER_CFG_POS_EN_NEG_DIS << PDSS_INTR1_CFG_CC12_OVP_HS_CC1_OVP_FILT_CFG_POS) |
            (PDSS_INTR1_CFG_CC12_OVP_HS_CC1_OVP_DPSLP_MODE) |
            (4UL << PDSS_INTR1_CFG_CC12_OVP_HS_CC2_OVP_FILT_SEL_POS) |
            ((uint32_t)CY_USBPD_VBUS_FILTER_CFG_POS_EN_NEG_DIS << PDSS_INTR1_CFG_CC12_OVP_HS_CC2_OVP_FILT_CFG_POS) |
            (PDSS_INTR1_CFG_CC12_OVP_HS_CC2_OVP_DPSLP_MODE)
            );
#endif /* defined (CY_DEVICE_SERIES_WLC1) */

    pd->intr1_cfg_cc12_ovp_hs |= (
            PDSS_INTR1_CFG_CC12_OVP_HS_CC1_OVP_FILT_EN |
            PDSS_INTR1_CFG_CC12_OVP_HS_CC2_OVP_FILT_EN
            );

    /* Clear and Enable CC1/2 OVP change interrupt. */
    pd->intr1       = (PDSS_INTR1_CC1_OVP_CHANGED | PDSS_INTR1_CC2_OVP_CHANGED);
    pd->intr1_mask |= (PDSS_INTR1_MASK_CC1_OVP_CHANGED_MASK | PDSS_INTR1_MASK_CC2_OVP_CHANGED_MASK);

    /* If OVP condition is present, set the interrupt again. */
    if ((pd->intr1_status & PDSS_INTR1_STATUS_CC1_OVP_FILT) != 0U)
    {
        pd->intr1_set |= PDSS_INTR1_SET_CC1_OVP_CHANGED;
    }
    if ((pd->intr1_status & PDSS_INTR1_STATUS_CC2_OVP_FILT) != 0U)
    {
        pd->intr1_set |= PDSS_INTR1_SET_CC2_OVP_CHANGED;
    }

#endif /* PDL_CC_OVP_ENABLE */
#endif  /* (defined (CY_DEVICE_CCG6) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined (CY_DEVICE_SERIES_WLC1) || defined (CY_DEVICE_CCG6DF_CFP)) */

#if defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)

#if PDL_VBAT_GND_SCP_ENABLE
    /* Enable VBAT to Type-C GND short protection */
    Cy_USBPD_Fault_VbatGndScpEn(context, CCG_SRC_FET, VBAT_GND_SCP_MODE_INT_AUTOCTRL);
#else
    /* Remove the pulldown to free up the GPIO */
    CY_USBPD_REG_FIELD_UPDATE(pd->bb_bat2gnd_prot_cnfg, PDSS_BB_BAT2GND_PROT_CNFG_BAT2GND_PROT_SEL, 4u);
#endif /* PDL_VBAT_GND_SCP_ENABLE */

#else /* !(defined(CCG7D) || !defined(CCG7S) || !defined(WICG1)) */
#if (defined (CY_DEVICE_CCG6) || defined(CY_DEVICE_CCG6DF_CFP))
#if PDL_SBU_OVP_ENABLE
    /* Enable the SBU OVP filters. */
    pd->intr3_cfg_sbu20_ovp_hs = (
            (4UL << PDSS_INTR3_CFG_SBU20_OVP_HS_SBU1_FILT_SEL_POS) |
            ((uint32_t)CY_USBPD_VBUS_FILTER_CFG_POS_EN_NEG_DIS << PDSS_INTR3_CFG_SBU20_OVP_HS_SBU1_FILT_CFG_POS) |
            (PDSS_INTR3_CFG_SBU20_OVP_HS_SBU1_DPSLP_MODE) |
            (4UL << PDSS_INTR3_CFG_SBU20_OVP_HS_SBU2_FILT_SEL_POS) |
            ((uint32_t)CY_USBPD_VBUS_FILTER_CFG_POS_EN_NEG_DIS << PDSS_INTR3_CFG_SBU20_OVP_HS_SBU2_FILT_CFG_POS) |
            (PDSS_INTR3_CFG_SBU20_OVP_HS_SBU2_DPSLP_MODE)
            );
    pd->intr3_cfg_sbu20_ovp_hs |= (
            PDSS_INTR3_CFG_SBU20_OVP_HS_SBU1_FILT_EN |
            PDSS_INTR3_CFG_SBU20_OVP_HS_SBU2_FILT_EN
            );

    /* Enable OVP detection on the SBU pins. */
    pd->intr3       = PDSS_INTR3_SBU1_SBU2_OVP_CHANGED_MASK;
    pd->intr3_mask |= PDSS_INTR3_SBU1_SBU2_OVP_CHANGED_MASK;
#endif /* PDL_SBU_OVP_ENABLE */
#endif /* (defined (CY_DEVICE_CCG6) || defined(CY_DEVICE_CCG6DF_CFP)) */

#if PMG1_V5V_CHANGE_DETECT
#if defined(CY_DEVICE_CCG6DF_CFP)
    /* Enable the V5V detect comparator for CFP devices. */
    pd->pd_30vconn_ctrl |= PDSS_PD_30VCONN_CTRL_EN_V5V_DET_COMP;
#else
    /* Enable the V5V detect comparator. */
    pd->vconn20_ctrl |= PDSS_VCONN20_CTRL_EN_COMP;
#endif /* defined(CY_DEVICE_CCG6DF_CFP) */

    /* Enable the V5V detect filter. */
    pd->intr1_cfg     = (pd->intr1_cfg & ~(PDSS_INTR1_CFG_V5V_FILT_EN |
                PDSS_INTR1_CFG_V5V_CFG_MASK | PDSS_INTR1_CFG_V5V_FILT_BYPASS));
    pd->intr1_cfg    |= PDSS_INTR1_CFG_V5V_CFG_MASK;

    Cy_SysLib_DelayUs (10);

    pd->intr1_cfg    |= PDSS_INTR1_CFG_V5V_FILT_EN;

    /* Clear and enable the V5V change interrupt. */
    pd->intr1       = PDSS_INTR1_V5V_CHANGED;
    pd->intr1_mask |= PDSS_INTR1_MASK_V5V_CHANGED_MASK;
#endif /* PMG1_V5V_CHANGE_DETECT */

#endif /* !(defined(CCG7D) || defined(CCG7S) || defined(WICG1)) */

#if PMG1_PD_DUALPORT_ENABLE
    if(NULL != context->altPortUsbPdCtx[TYPEC_PORT_0_IDX])
    {
        context->altPortUsbPdCtx[TYPEC_PORT_0_IDX]->pdssActivePorts |= ((uint32_t)1u << context->port);
    }
#endif /* PMG1_PD_DUALPORT_ENABLE */

#endif /* defined (CY_DEVICE_CCG6) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP) */

#elif defined(CY_IP_M0S8USBPD)

    /* Power up the block. */
    pd->cc_ctrl_0 &= ~PDSS_CC_CTRL_0_PWR_DISABLE;

    /* Enable Deep sleep reference. */
    pd->dpslp_ref_ctrl &= ~PDSS_DPSLP_REF_CTRL_PD_DPSLP;

    /* Enable PUMP */
    pd->pump_ctrl &= ~(PDSS_PUMP_CTRL_PD_PUMP  | PDSS_PUMP_CTRL_BYPASS_LV);
    Cy_SysLib_DelayUs (50);

    /* Enable V5V change detect interrupt. */
    pd->intr1         = PDSS_INTR1_V5V_CHANGED;
    pd->intr1_mask   |= PDSS_INTR1_MASK_V5V_CHANGED_MASK;
    pd->pfet300_ctrl |= PDSS_PFET300_CTRL_EN_COMP;

    pd->cc_ctrl_0 |= (PDSS_CC_CTRL_0_CMP_EN | PDSS_CC_CTRL_0_RX_EN);

#endif /* defined(CY_IP_MXUSBPD) */

    return CY_USBPD_STAT_SUCCESS;
}

/*******************************************************************************
* Function Name: Cy_USBPD_TypeC_Stop
****************************************************************************//**
* 
* This function stops the Type C Line comparators.
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \return
* CY_USBPD_STAT_SUCCESS if operation is successful, 
* CY_USBPD_STAT_BAD_PARAM if the context pointer is invalid.
*
*******************************************************************************/
cy_en_usbpd_status_t Cy_USBPD_TypeC_Stop (
        cy_stc_usbpd_context_t *context)
{
    PPDSS_REGS_T pd = NULL;

    if (context == NULL)
    {
        return CY_USBPD_STAT_BAD_PARAM;
    }

    pd = context->base;

#if defined (CY_IP_MXUSBPD)

#if (defined (CY_DEVICE_CCG6) || defined (CY_DEVICE_CCG7D) || defined (CY_DEVICE_CCG7S) || defined (CY_DEVICE_PMG1S3) || defined (CY_DEVICE_CCG6DF_CFP))
#if PMG1_V5V_CHANGE_DETECT
    /* Clear and disable the V5V change detect interrupt. */
    pd->intr1       = PDSS_INTR1_V5V_CHANGED;
    pd->intr1_mask &= ~PDSS_INTR1_MASK_V5V_CHANGED_MASK;

    /* Disable and bypass the V5V detect filter. */
    pd->intr1_cfg = (pd->intr1_cfg & ~(PDSS_INTR1_CFG_V5V_FILT_EN |
                PDSS_INTR1_CFG_V5V_CFG_MASK | PDSS_INTR1_CFG_V5V_FILT_BYPASS));

    Cy_SysLib_DelayUs (10);
    
    pd->intr1     = PDSS_INTR1_V5V_CHANGED;
#endif /* PMG1_V5V_CHANGE_DETECT */
#if (defined (CY_DEVICE_CCG6) || defined (CY_DEVICE_CCG6DF_CFP))
#if PDL_SBU_OVP_ENABLE
    /* Clear and disable SBU OVP detect interrupts. */
    pd->intr3_mask &= ~(PDSS_INTR3_SBU1_SBU2_OVP_CHANGED_MASK);
    pd->intr3       = PDSS_INTR3_SBU1_SBU2_OVP_CHANGED_MASK;
    pd->intr3_cfg_sbu20_ovp_hs &= ~(
            PDSS_INTR3_CFG_SBU20_OVP_HS_SBU1_FILT_EN |
            PDSS_INTR3_CFG_SBU20_OVP_HS_SBU2_FILT_EN
            );
#endif /* PDL_SBU_OVP_ENABLE */
#endif /* (defined (CY_DEVICE_CCG6) || defined (CY_DEVICE_CCG6DF_CFP)) */

#if (defined (CY_DEVICE_CCG6) || defined (CY_DEVICE_CCG7D) || defined (CY_DEVICE_CCG7S) || defined (CY_DEVICE_CCG6DF_CFP))
#if PDL_CC_OVP_ENABLE
    /* Clear and disable CC1/2 OVP change interrupt. */
    pd->intr1       = (PDSS_INTR1_CC1_OVP_CHANGED | PDSS_INTR1_CC2_OVP_CHANGED);
    pd->intr1_mask &= ~(PDSS_INTR1_MASK_CC1_OVP_CHANGED_MASK | PDSS_INTR1_MASK_CC2_OVP_CHANGED_MASK);

    pd->intr1_cfg_cc12_ovp_hs &= ~(
            PDSS_INTR1_CFG_CC12_OVP_HS_CC1_OVP_FILT_EN |
            PDSS_INTR1_CFG_CC12_OVP_HS_CC2_OVP_FILT_EN
            );
#endif /* PDL_CC_OVP_ENABLE */
#endif /* (defined (CY_DEVICE_CCG6) || defined (CY_DEVICE_CCG7D) || defined (CY_DEVICE_CCG7S) || defined (CY_DEVICE_CCG6DF_CFP)) */

#endif /* (defined (CY_DEVICE_CCG6) || defined (CY_DEVICE_CCG7D) || defined (CY_DEVICE_CCG7S) || defined (CY_DEVICE_PMG1S3) || defined (CY_DEVICE_CCG6DF_CFP)) */

    /* Power down the block. */
    pd->cc_ctrl_0 |= PDSS_CC_CTRL_0_PWR_DISABLE;

    /* Disable PUMP */
    Cy_USBPD_Pump_Disable (context, 0);
#if (!CCG_PD_BLOCK_ALWAYS_ON)
#if (PMG1_PD_DUALPORT_ENABLE)
    if(NULL != context->altPortUsbPdCtx[TYPEC_PORT_0_IDX])
    {
        /* Clearing the PORT enable status bit. */
        context->altPortUsbPdCtx[TYPEC_PORT_0_IDX]->pdssActivePorts &= ~((uint32_t)1u << context->port);

        if (context->altPortUsbPdCtx[TYPEC_PORT_0_IDX]->pdssActivePorts == 0u)
        {
            /* Deep sleep reference has to be disabled on PD0 block. */
#if defined(CY_DEVICE_CCG6DF_CFP)
            context->altPortUsbPdCtx[TYPEC_PORT_0_IDX]->base->pd_ref_gen_ctrl |= PDSS_PD_REF_GEN_CTRL_PD;
#else
            context->altPortUsbPdCtx[TYPEC_PORT_0_IDX]->base->dpslp_ref_ctrl |= PDSS_DPSLP_REF_CTRL_PD_DPSLP;
#endif /* defined(CY_DEVICE_CCG6DF_CFP) */
        }
    }
    if (TYPEC_PORT_0_IDX != context->port)
#endif /* PMG1_PD_DUALPORT_ENABLE */
    {
        /* Deep sleep reference has to be disabled on current PD block. */
#if defined(CY_DEVICE_CCG6DF_CFP)
        pd->pd_ref_gen_ctrl |= PDSS_PD_REF_GEN_CTRL_PD;
#else
        pd->dpslp_ref_ctrl |= PDSS_DPSLP_REF_CTRL_PD_DPSLP;
#endif /* defined(CY_DEVICE_CCG6DF_CFP) */
    }
#endif /* !CCG_PD_BLOCK_ALWAYS_ON */
#elif defined(CY_IP_M0S8USBPD)

    /* Clear and disable the V5V changed detect interrupt. */
    pd->intr1       = PDSS_INTR1_V5V_CHANGED;
    pd->intr1_mask &= ~PDSS_INTR1_MASK_V5V_CHANGED_MASK;

    /* Power down the block. */
    pd->cc_ctrl_0 |= PDSS_CC_CTRL_0_PWR_DISABLE;

    /* Disable PUMP */
    pd->pump_ctrl |= (PDSS_PUMP_CTRL_PD_PUMP  | PDSS_PUMP_CTRL_BYPASS_LV);

    /* Turn off references. */
    pd->dpslp_ref_ctrl |= PDSS_DPSLP_REF_CTRL_PD_DPSLP;

    /* Turn off comparators. */
    pd->cc_ctrl_0 &= ~(PDSS_CC_CTRL_0_CMP_EN | PDSS_CC_CTRL_0_RX_EN);

#endif /* defined(CY_IP_MXUSBPD) */

    return CY_USBPD_STAT_SUCCESS;
}

/*******************************************************************************
* Function Name: Cy_USBPD_TypeC_RdEnable
****************************************************************************//**
* 
* This function enables the Rd termination without initializing the block
* completely. This is used in Type-C fault handling use cases.
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \return
* None
*
*******************************************************************************/
void Cy_USBPD_TypeC_RdEnable (
        cy_stc_usbpd_context_t *context)
{
    uint32_t temp = 0;
    PPDSS_REGS_T pd = NULL;

    if (context == NULL)
    {
        return;
    }

    pd = context->base;

    /* Deep sleep reference has to be enabled on PD0 block. */
#if defined(CY_DEVICE_CCG6DF_CFP)
    pd->pd_ref_gen_ctrl &= ~PDSS_PD_REF_GEN_CTRL_PD;
#else
    pd->dpslp_ref_ctrl &= ~PDSS_DPSLP_REF_CTRL_PD_DPSLP;
#endif /* defined(CY_DEVICE_CCG6DF_CFP) */

#if PMG1_PD_DUALPORT_ENABLE
    if((NULL != context->altPortUsbPdCtx[TYPEC_PORT_0_IDX]) && (context->port == TYPEC_PORT_1_IDX))
    {
        /* Deep sleep reference has to be enabled on PD0 block. */
#if defined(CY_DEVICE_CCG6DF_CFP)
        context->altPortUsbPdCtx[TYPEC_PORT_0_IDX]->base->pd_ref_gen_ctrl &= ~PDSS_PD_REF_GEN_CTRL_PD;
#else
        context->altPortUsbPdCtx[TYPEC_PORT_0_IDX]->base->dpslp_ref_ctrl &= ~PDSS_DPSLP_REF_CTRL_PD_DPSLP;
#endif /* defined(CY_DEVICE_CCG6DF_CFP) */
    }
#endif

    /* Power up the block. */
    pd->cc_ctrl_0 &= ~PDSS_CC_CTRL_0_PWR_DISABLE;
    pd->cc_ctrl_0 |= (PDSS_CC_CTRL_0_CMP_EN | PDSS_CC_CTRL_0_RX_EN);

    /* Enable Rd on both CC lines. */
    temp = pd->cc_ctrl_0;

#if defined(CY_DEVICE_SERIES_WLC1)
    /*
     * Since this solution requires dead battery Rd (unavailable in CCG7D),
     * external passive Rd is always present on the CC lines. So nothing 
     * needs to be done for Rd enable other than disabling dead battery Rd
     * bit.
     * Rd removal is implemented via VCONN; so we need to ensure 
     * VCONN is disabled. 
     *
     * This compile time macro needs to be re-named appropriately 
     * as a feature name instead of device name.
     */
    temp |= (PDSS_CC_CTRL_0_RD_CC1_DB_DIS);
    temp |= (PDSS_CC_CTRL_0_RD_CC2_DB_DIS);

    Cy_USBPD_Vconn_Disable(context, CY_PD_CC_CHANNEL_1);
    Cy_USBPD_Vconn_Disable(context, CY_PD_CC_CHANNEL_2);
#else
    temp |= (PDSS_CC_CTRL_0_RD_CC1_EN | PDSS_CC_CTRL_0_RD_CC1_DB_DIS);
    temp |= (PDSS_CC_CTRL_0_RD_CC2_EN | PDSS_CC_CTRL_0_RD_CC2_DB_DIS);
#endif /* defined(CY_DEVICE_SERIES_WLC1) */

    temp &= ~PDSS_CC_CTRL_0_DFP_EN;

    pd->cc_ctrl_0 = temp;
}

/*******************************************************************************
* Function Name: Cy_USBPD_TypeC_SnkUpdateTrim
****************************************************************************//**
* 
* This function updates the tx trim settings when in the sink role. It must be
* called whenever an Rp change on the port partner side is detected.  This is
* required to meet the CC transmitter characteristics defined by the USB-PD
* specification.
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \return
* None
*
*******************************************************************************/
void Cy_USBPD_TypeC_SnkUpdateTrim (
        cy_stc_usbpd_context_t *context)
{
#if defined(CY_IP_MXUSBPD)
#if defined (CY_DEVICE_CCG6)
    PPDSS_TRIMS_REGS_T trimRegs = NULL;
    cy_stc_pd_dpm_config_t *dpmConfig = NULL;

    if (context == NULL)
    {
        return;
    }

    trimRegs = context->trimsBase;
    dpmConfig = context->dpmGetConfig();

    if (dpmConfig->curPortRole == CY_PD_PRT_ROLE_SINK)
    {
        trimRegs->trim_cc_0 &= ~PDSS_TRIM_CC_0_TX_TRIM_MASK;

        if (dpmConfig->snkCurLevel == (uint8_t)CY_PD_RD_3A)
        {
            /* Use faster slew rate when 3A Rp is in use. */
            trimRegs->trim_cc_0 |= (TRIM0_TX_TRIM_VALUE_3A << PDSS_TRIM_CC_0_TX_TRIM_POS);
        }
    }
#else
    (void)context;
#endif /* defined (CY_DEVICE_CCG6) */
#elif defined(CY_IP_M0S8USBPD)

    PPDSS_REGS_T pd;
    cy_stc_pd_dpm_config_t *dpmConfig = NULL;

    if (context == NULL)
    {
        return;
    }

    pd = context->base;
    dpmConfig = context->dpmGetConfig();

    if (dpmConfig->curPortRole == CY_PD_PRT_ROLE_SINK)
    {
        pd->s8usbpd_trim_0 &= ~PDSS_S8USBPD_TRIM_0_TX_TRIM_MASK;
        if (dpmConfig->snkCurLevel == (uint8_t)CY_PD_RD_3A)
        {
            pd->s8usbpd_trim_0 |= (TRIM0_TX_TRIM_VALUE_3A << PDSS_S8USBPD_TRIM_0_TX_TRIM_POS);
        }
    }

#endif /* defined(CY_IP_M0S8USBPD) */
}

#if defined(CY_DEVICE_CCG3)
#define SFLASH_PDSS_PORT0_TRIM1_BASE            (0x0FFFF282u)
#define SFLASH_PDSS_PORT1_TRIM1_BASE            (0x0FFFF285u)
#elif defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP)
#define SFLASH_PDSS_PORT0_TRIM1_BASE            (0x0FFFF410u)
#define SFLASH_PDSS_PORT1_TRIM1_BASE            (0x0FFFF510u)
#elif defined(CY_DEVICE_CCG7D)
#define SFLASH_PDSS_PORT0_TRIM1_BASE            (0x0FFFF410u)
#define SFLASH_PDSS_PORT1_TRIM1_BASE            (0x0FFFF510u)
#elif defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)
#define SFLASH_PDSS_PORT0_TRIM1_BASE            (0x0FFFF410u)
#else
#define SFLASH_PDSS_PORT0_TRIM1_BASE            (0x0FFFF536u)
#define SFLASH_PDSS_PORT1_TRIM1_BASE            (0x0FFFF542u)
#endif /* defined(CY_DEVICE_CCG3) */

/*******************************************************************************
* Function Name: Cy_USBPD_TypeC_EnableRp
****************************************************************************//**
* 
* This function configures and enables Rp termination on the specified CC line.
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \param channel
* Channel index, where CC1 = 0, CC2 = 1
*
* \param rpVal
* Rp Value
*
* \return
* None
*
*******************************************************************************/
void Cy_USBPD_TypeC_EnableRp (
        cy_stc_usbpd_context_t *context, 
        uint8_t channel, 
        cy_en_pd_rp_term_t rpVal)
{
#if (!CY_PD_SINK_ONLY)
    PPDSS_REGS_T pd = NULL;
    uint32_t temp = 0;
    uint8_t rpMode = 0;
    uint8_t *pdss_rp_trim_db = (uint8_t *)SFLASH_PDSS_PORT0_TRIM1_BASE;

#if defined(CY_IP_MXUSBPD)
    PPDSS_TRIMS_REGS_T trimRegs = NULL;
#endif /* defined(CY_IP_MXUSBPD) */

#if (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP) || defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
    uint8_t cc_trim = 0;
#endif /* (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP) || defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) */

    if (context == NULL)
    {
        return;
    }

    pd = context->base;
    rpMode = (uint8_t)rpVal;

    /* Make sure the CC pump is enabled. */
    Cy_USBPD_Pump_Enable (context, 0);

#if defined(CY_IP_MXUSBPD)
#if (defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP) || defined(CY_DEVICE_CCG7D))
    if (context->port != TYPEC_PORT_0_IDX)
    {
        pdss_rp_trim_db = (uint8_t *)SFLASH_PDSS_PORT1_TRIM1_BASE;
    }
#endif /* (defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP) || defined(CY_DEVICE_CCG7D)) */

    trimRegs = context->trimsBase;
    cc_trim  = pdss_rp_trim_db[rpVal];

    /* Set cc trim from sflash */
    if (channel == CY_PD_CC_CHANNEL_1)
    {
        trimRegs->trim_cc_1 = cc_trim;
    }
    else
    {
        trimRegs->trim_cc_2 = cc_trim;
    }

    trimRegs->trim_cc_0 &= ~PDSS_TRIM_CC_0_TX_TRIM_MASK;
    if (rpVal == CY_PD_RP_TERM_RP_CUR_3A)
    {
        /* Actual value in HW register for 3A Rp is (CY_PD_RP_TERM_RP_CUR_3A + 1) */
        rpMode++;

        /* Use faster slew rate when 3A Rp is in use. */
        trimRegs->trim_cc_0 |= (TRIM0_TX_TRIM_VALUE_3A << PDSS_TRIM_CC_0_TX_TRIM_POS);
    }
#elif defined(CY_IP_M0S8USBPD)
    pd->s8usbpd_trim_0 &= ~PDSS_S8USBPD_TRIM_0_TX_TRIM_MASK;

    pd->s8usbpd_trim_1 &= ~PDSS_S8USBPD_TRIM_1_RP_CC1_TRIM_MASK;
    pd->s8usbpd_trim_2 &= ~PDSS_S8USBPD_TRIM_2_RP_CC2_TRIM_MASK;

    /* Set cc trim from sflash */
    pd->s8usbpd_trim_1 |= pdss_rp_trim_db[rpVal];
    pd->s8usbpd_trim_2 |= pdss_rp_trim_db[rpVal];

    if (rpVal == CY_PD_RP_TERM_RP_CUR_3A)
    {
        /* Use faster slew rate when 3A Rp is in use. */
        pd->s8usbpd_trim_0 |= (TRIM0_TX_TRIM_VALUE_3A << PDSS_S8USBPD_TRIM_0_TX_TRIM_POS);

        /* Actual value in HW register for 3A Rp is (CY_PD_RP_TERM_RP_CUR_3A + 1) */
        rpMode++;
    }
#endif /* defined(CY_IP_MXUSBPD) */

    /* Set Rp mode and enable references for source operation. */
    temp = pd->cc_ctrl_0;
    temp &= ~PDSS_CC_CTRL_0_RP_MODE_MASK;
    temp |= ((uint32_t)rpMode << PDSS_CC_CTRL_0_RP_MODE_POS) | PDSS_CC_CTRL_0_DFP_EN;

    if (channel == CY_PD_CC_CHANNEL_1)
    {
        temp |= PDSS_CC_CTRL_0_RP_CC1_EN;
    }
    else
    {
        temp |= PDSS_CC_CTRL_0_RP_CC2_EN;
    }

    pd->cc_ctrl_0 = temp;

#else
    CY_UNUSED_PARAMETER(context);
    CY_UNUSED_PARAMETER(channel);
    CY_UNUSED_PARAMETER(rpVal);
#endif /* (!CY_PD_SINK_ONLY) */
}

/*******************************************************************************
* Function Name: Cy_USBPD_TypeC_DisableRp
****************************************************************************//**
* 
* This function disables Rp termination on the specified CC line.
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \param channel
* Channel index, where CC1 = 0, CC2 = 1
*
* \return
* None
*
*******************************************************************************/
void Cy_USBPD_TypeC_DisableRp (
        cy_stc_usbpd_context_t *context, 
        uint8_t channel)
{
#if (!CY_PD_SINK_ONLY)
    PPDSS_REGS_T pd = NULL;
    if (context == NULL)
    {
        return;
    }

    pd = context->base;
    if (channel == CY_PD_CC_CHANNEL_1)
    {
        pd->cc_ctrl_0 &= ~PDSS_CC_CTRL_0_RP_CC1_EN;
    }
    else
    {
        pd->cc_ctrl_0 &= ~PDSS_CC_CTRL_0_RP_CC2_EN;
    }
#else
    CY_UNUSED_PARAMETER(context);
    CY_UNUSED_PARAMETER(channel);
#endif /* (!CY_PD_SINK_ONLY) */
}

/*******************************************************************************
* Function Name: Cy_USBPD_TypeC_EnDpSlpRp
****************************************************************************//**
* 
* This function enables a resistive Rp termination (not accurate to match any
* Type-C current levels) which can be used to save power while there is no
* Type-C connection and the PMG1 device is in sleep.
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \return
* None
*
*******************************************************************************/
void Cy_USBPD_TypeC_EnDpSlpRp(
        cy_stc_usbpd_context_t *context)
{
#if (!CY_PD_SINK_ONLY)
    if (context != NULL)
    {
        context->base->cc_ctrl_1 |= PDSS_CC_CTRL_1_DS_ATTACH_DET_EN;
    }
#else
    CY_UNUSED_PARAMETER(context);
#endif /* (!CY_PD_SINK_ONLY) */
}

/*******************************************************************************
* Function Name: Cy_USBPD_TypeC_DisDpSlpRp
****************************************************************************//**
* 
* This function disables the resistive Rp termination so that the accurate
* current source based Rp termination can be applied.
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \return
* None
*
*******************************************************************************/
void Cy_USBPD_TypeC_DisDpSlpRp(
        cy_stc_usbpd_context_t *context)
{
#if (!CY_PD_SINK_ONLY)
    if (context != NULL)
    {
        context->base->cc_ctrl_1 &= ~PDSS_CC_CTRL_1_DS_ATTACH_DET_EN;
    }
#else
    CY_UNUSED_PARAMETER(context);
#endif /* (!CY_PD_SINK_ONLY) */
}

/*******************************************************************************
* Function Name: Cy_USBPD_TypeC_ChangeRp
****************************************************************************//**
*
* This function changes Rp. If port is in a connected state, Rp will be changed
* only on the active channel. If port is not connected then Rp gets updated on
* both CC channels.
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \param rp
* Desired Rp value.
*
* \return
* None
*
*******************************************************************************/
void Cy_USBPD_TypeC_ChangeRp (cy_stc_usbpd_context_t *context, cy_en_pd_rp_term_t rp)
{
#if (!CY_PD_SINK_ONLY)
    cy_stc_pd_dpm_config_t *dpmConfig;
    
    if (context != NULL)
    {
        dpmConfig = context->dpmGetConfig();

        if(dpmConfig->curPortRole == CY_PD_PRT_ROLE_SOURCE)
        {
            dpmConfig->srcCurLevelLive = (uint8_t)rp;

            if (dpmConfig->connect == false)
            {
                Cy_USBPD_TypeC_EnableRp(context, CY_PD_CC_CHANNEL_1, rp);
                Cy_USBPD_TypeC_EnableRp(context, CY_PD_CC_CHANNEL_2, rp);
            }
            else
            {
                Cy_USBPD_TypeC_EnableRp(context, dpmConfig->polarity, rp);
            }

            /* Adding this delay for cc voltage to settle */
            Cy_SysLib_DelayUs(50);
        }
    }
#else
    CY_UNUSED_PARAMETER(context);
    CY_UNUSED_PARAMETER(rp);
#endif /* (!CY_PD_SINK_ONLY) */
}

/*******************************************************************************
* Function Name: Cy_USBPD_TypeC_EnableDeadBatRd
****************************************************************************//**
* 
* This function enables the dead battery Rd termination.
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \return
* None
*
*******************************************************************************/
void Cy_USBPD_TypeC_EnableDeadBatRd (
        cy_stc_usbpd_context_t *context)
{
    PPDSS_REGS_T pd;
    uint32_t temp = 0;

    if (context != NULL)
    {
        pd = context->base;
        temp = pd->cc_ctrl_0;

        /* Re-enable dead battery Rd */
        temp &= ~(PDSS_CC_CTRL_0_RD_CC1_DB_DIS | PDSS_CC_CTRL_0_RD_CC2_DB_DIS);

        /* Remove trimmed Rd */
        temp &= ~(PDSS_CC_CTRL_0_RD_CC1_EN | PDSS_CC_CTRL_0_RD_CC2_EN);

        pd->cc_ctrl_0 = temp;
    }
}

/*******************************************************************************
* Function Name: Cy_USBPD_TypeC_EnableRd
****************************************************************************//**
* 
* This function enables the Rd termination on the specified CC line.
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \param channel
* Channel index, where CC1 = 0, CC2 = 1
*
* \return
* None
*
*******************************************************************************/
void Cy_USBPD_TypeC_EnableRd (
        cy_stc_usbpd_context_t *context,
        uint8_t channel)
{
    PPDSS_REGS_T pd = NULL;
    uint32_t temp = 0;

    if (context == NULL)
    {
        return;
    }

    pd = context->base;

#if !CY_PD_EPR_36V_SUPP_EN
#if !PSVP_FPGA_ENABLE
    /* Disable PUMP */
    Cy_USBPD_Pump_Disable (context, 0);
#endif /* !PSVP_FPGA_ENABLE */
#endif /* CY_PD_EPR_36V_SUPP_EN */

    temp = pd->cc_ctrl_0;

#ifdef CY_DEVICE_SERIES_WLC1

    (void)Cy_USBPD_Vconn_Disable(context, channel);
    
#else 

    if (channel == CY_PD_CC_CHANNEL_1)
    {
        temp |= (PDSS_CC_CTRL_0_RD_CC1_EN | PDSS_CC_CTRL_0_RD_CC1_DB_DIS);
    }
    else
    {
        temp |= (PDSS_CC_CTRL_0_RD_CC2_EN | PDSS_CC_CTRL_0_RD_CC2_DB_DIS);
    }

#endif /* CY_DEVICE_SERIES_WLC1 */

    temp &= ~PDSS_CC_CTRL_0_DFP_EN;
    pd->cc_ctrl_0 = temp;
}

/*******************************************************************************
* Function Name: Cy_USBPD_TypeC_DisableRd
****************************************************************************//**
* 
* This function disables the Rd termination on the specified CC line.
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \param channel
* Channel index, where CC1 = 0, CC2 = 1
*
* \return
* None
*
*******************************************************************************/
void Cy_USBPD_TypeC_DisableRd (
        cy_stc_usbpd_context_t *context, 
        uint8_t channel)
{
    PPDSS_REGS_T pd = NULL;
    uint32_t regVal = 0;

    if (context == NULL)
    {
        return;
    }

    pd = context->base;
    regVal = pd->cc_ctrl_0;

    if (channel == CY_PD_CC_CHANNEL_1)
    {
        regVal &= ~PDSS_CC_CTRL_0_RD_CC1_EN;
        regVal |= PDSS_CC_CTRL_0_RD_CC1_DB_DIS;
    }
    else
    {
        regVal &= ~PDSS_CC_CTRL_0_RD_CC2_EN;
        regVal |= PDSS_CC_CTRL_0_RD_CC2_DB_DIS;
    }

    pd->cc_ctrl_0 = regVal;
#ifdef CY_DEVICE_SERIES_WLC1
    /* 
     * Simulate Rd removal by enabling VCONN. This is because the
     * Rd is permanently present on the CC lines outside the silicon.
     *
     * The only way to mimic Rd removal is by injecting a 
     * safe voltage >2.6V onto the CC line. Since VCONN is readily
     * available, we do about enabling VCONN with current limit mode.
     * This will ensure that we supply 5V on CC line where we want
     * to mimic Rd removal.
     *
     * But to avoid doing on both lines do only on active CC line.
     */
    if (context->dpmGetConfig()->polarity == channel)
    {
        (void)Cy_USBPD_Vconn_Enable(context, channel);
    }
#endif /* CY_DEVICE_SERIES_WLC1 */
}

/*******************************************************************************
* Function Name: Cy_USBPD_TypeC_GetCCStatus
****************************************************************************//**
* 
* This function returns current status of both CC lines. The function
* identifies the current termination (Rp or Rd) applied by the PMG1 device and
* interprets the voltage on the CC line based on the current use case.
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \return
* Returns the value of the CC state.
*
*******************************************************************************/
cy_pd_cc_state_t Cy_USBPD_TypeC_GetCCStatus (
        cy_stc_usbpd_context_t *context)
{
    cy_stc_pd_dpm_config_t *dpmConfig = NULL;
    PPDSS_REGS_T pd = NULL;
    uint8_t polarity = 0;
    cy_pd_cc_state_t newState;
    uint8_t i = 0;

    pd = context->base;
    dpmConfig = context->dpmGetConfig();
    polarity = dpmConfig->polarity;

    /* If the CC TX/RX is busy, retain previously detected CC status. */
    newState = dpmConfig->ccOldStatus;
    if (
            (dpmConfig->attach == true) && 
            ((pd->status & (PDSS_STATUS_TX_BUSY | PDSS_STATUS_CC_DATA_VALID)) != 0U)
       )
    {
        return newState;
    }

#if (!CY_PD_SINK_ONLY)
    if (dpmConfig->curPortRole == CY_PD_PRT_ROLE_SOURCE)
    {
#if PSVP_FPGA_ENABLE
        /* On PSVP, do not scan the inactive CC line when there is a Type-C connection. */
        if (dpmConfig->attach == false)
        {
            newState.cc[1u - polarity] = Cy_USBPD_TypeC_GetRpRdStatus(context, 1u - polarity, 0);
        }
        newState.cc[polarity]     = Cy_USBPD_TypeC_GetRpRdStatus(context, polarity, 0);
#else /* !PSVP_FPGA_ENABLE */

        /* Scan both CC lines: the active CC line should be scanned last. */
        newState.cc[1u - polarity] = Cy_USBPD_TypeC_GetRpRdStatus(context, 1u - polarity, 0);
        newState.cc[polarity]     = Cy_USBPD_TypeC_GetRpRdStatus(context, polarity, 0);
#if (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
        if (context->ccOvpPending != 0U)
        {
            if (newState.cc[polarity] == (uint8_t)CY_PD_RP_OPEN)
            {
                /* Keep returning RP_RD status while OVP is active. */
                newState.cc[polarity] = (uint8_t)CY_PD_RP_RD;
            }
            else
            {
                /* Re-enable the Rp termination and mark OVP not active. */
                Cy_USBPD_TypeC_EnableRp(context, polarity, (cy_en_pd_rp_term_t)dpmConfig->srcCurLevelLive);
                context->ccOvpPending = 0U;
            }
        }
#endif /* (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) */
#endif /* PSVP_FPGA_ENABLE */
    }
    else
#endif /* (!CY_PD_SINK_ONLY) */
    {
#if PSVP_FPGA_ENABLE
        if(dpmConfig->connect == true)
#else
        if(dpmConfig->attach == true)
#endif /* PSVP_FPGA_ENABLE */
        {
            if (newState.cc[polarity] > (uint8_t)CY_PD_RD_USB)
            {
                newState.cc[polarity] = Cy_USBPD_TypeC_GetRpRdStatus(context, polarity, 1);
            }

            /* If CC line voltage is below the 1.5 A Rp threshold, do another check for presence of Rp. */
            if (newState.cc[polarity] <= (uint8_t)CY_PD_RD_USB)
            {
                newState.cc[polarity] = Cy_USBPD_TypeC_GetRpRdStatus(context, polarity, 0);
            }

            /* Only the active CC line needs to be scanned. */
            newState.cc[dpmConfig->revPol] = (uint8_t)CY_PD_RD_RA;
        }
        else
        {
            for (i = 0U; i < 2U; i++)
            {
                /* Scan CC[i] with threshold vRa and vRdUsb. */
                newState.cc[i] = Cy_USBPD_TypeC_GetRpRdStatus(context, i, 0);
                if (newState.cc[i] != (uint8_t)CY_PD_RD_RA)
                {
                    /* Scan CC[i] again with vRdusb and vRd1.5A to determine correct Rp value. */
                    newState.cc[i] = Cy_USBPD_TypeC_GetRpRdStatus(context, i, 1);
                }
            }
        }
    }

    return newState;
}

/*******************************************************************************
* Function Name: Cy_USBPD_TypeC_SetPolarity
****************************************************************************//**
* 
* This function sets the CC polarity for the receiver circuit.
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \param polarity
* Type-C connection orientation: 0 when CC1 active and 1 when CC2 active.
*
* \return
* None
*
*******************************************************************************/
void Cy_USBPD_TypeC_SetPolarity (
        cy_stc_usbpd_context_t *context,
        uint8_t polarity)
{
    if (context != NULL)
    {
        if (polarity == 0U)
        {
            context->base->cc_ctrl_0 &= ~PDSS_CC_CTRL_0_CC_1V2;
        }
        else
        {
            context->base->cc_ctrl_0 |= PDSS_CC_CTRL_0_CC_1V2;
        }
    }
}

/*******************************************************************************
* Function Name: Cy_USBPD_TypeC_CfgAutoToggle
****************************************************************************//**
* 
* Enable/disable automatic hardware toggle operation as part of deep sleep cycle.
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \param enable
* Whether automatic toggle is to be enabled.
*
* \return
* None
*
*******************************************************************************/
void Cy_USBPD_TypeC_CfgAutoToggle (
        cy_stc_usbpd_context_t *context, 
        bool enable)
{
#if CY_PD_HW_DRP_TOGGLE_ENABLE
    if (context != NULL)
    {
        /* Abort auto toggle if it is in progress. */
        Cy_USBPD_TypeC_AbortAutoToggle (context);
        context->autoToggleEn = enable;
    }
#else
    (void)context;
    (void)enable;
#endif /* CY_PD_HW_DRP_TOGGLE_ENABLE */
}

/*******************************************************************************
* Function Name: Cy_USBPD_TypeC_AbortAutoToggle
****************************************************************************//**
* 
* This function aborts any ongoing automatic DRP toggle operation.
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \return
* None
*
*******************************************************************************/
void Cy_USBPD_TypeC_AbortAutoToggle (
        cy_stc_usbpd_context_t *context)
{
    if (context != NULL)
    {
#if CY_PD_HW_DRP_TOGGLE_ENABLE
        if (context->autoToggleAct)
        {
            PPDSS_REGS_T pd = context->base;
            /* Disable the RP-RD toggle and the attach interrupt. */
            pd->rp_rd_cfg1 &= ~(PDSS_RP_RD_CFG1_HW_RP_RD_AUTO_TOGGLE | PDSS_RP_RD_CFG1_START_TOGGLE);
            pd->intr1_mask &= ~PDSS_INTR1_DRP_ATTACHED_DETECTED;

            context->autoToggleAct = false;
            context->typecStartPending = false;
        }
#endif /* CY_PD_HW_DRP_TOGGLE_ENABLE */
    }
}

/*******************************************************************************
* Function Name: Cy_USBPD_TypeC_IsAutoToggleActive
****************************************************************************//**
* 
* This function checks if automatic DRP toggle operation is active.
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \return
* Returns true if DRP toggle operation is active, otherwise false.
*
*******************************************************************************/
bool Cy_USBPD_TypeC_IsAutoToggleActive (
        cy_stc_usbpd_context_t *context)
{
    if (context == NULL)
    {
        return false;
    }
#if CY_PD_HW_DRP_TOGGLE_ENABLE
    /* Don't run through Type-C state machine if auto toggle is active or has just been stopped. */
    return (((bool)context->autoToggleAct) || ((bool)context->typecStartPending));
#else
    return false;
#endif /* CY_PD_HW_DRP_TOGGLE_ENABLE */
}

/*******************************************************************************
* Function Name: Cy_USBPD_TypeC_SMRestart
****************************************************************************//**
* 
* Restart Type-C state machine once auto toggle operation is complete. This is
* normally required when the port has just exited the auto DRP toggle stage,
* and the state machine needs to handle further operations.
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \return
* None
*
*******************************************************************************/
void Cy_USBPD_TypeC_SMRestart (
        cy_stc_usbpd_context_t *context)
{
#if ((SYS_DEEPSLEEP_ENABLE) && (CY_PD_HW_DRP_TOGGLE_ENABLE))
    if (context)
    {
        if (context->typecStartPending)
        {
            Cy_USBPD_Resume(context);
        }
    }
#else
    (void)context;
#endif /* ((SYS_DEEPSLEEP_ENABLE) && (CY_PD_HW_DRP_TOGGLE_ENABLE)) */
}

/*******************************************************************************
* Function Name: Cy_USBPD_SetReference
****************************************************************************//**
* 
* This function facilitates to set deep sleep/bandgap reference. This should be
* called for setting deep sleep reference just before entry into deep sleep
* state. Function should be called with band gap reference just after exit from
* deep sleep state.
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \param flag
* If true signifies deep sleep reference, otherwise band gap reference.
*
* \return
* None
*
*******************************************************************************/
void Cy_USBPD_SetReference (
        cy_stc_usbpd_context_t *context,
        bool flag)
{
#if ((defined(CY_DEVICE_CCG3PA)) || (defined(CY_DEVICE_CCG3PA2)) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
    PPDSS_REGS_T pd = context->base;
    uint8_t port = context->port;
    CY_UNUSED_PARAMETER(port);
#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
    cy_stc_usbpd_context_t *usbpd_ctx_temp=context;
#if (NO_OF_TYPEC_PORTS > 1)
    uint8_t i;
    if(context->port != 0u)
    {
        usbpd_ctx_temp=context-(NO_OF_TYPEC_PORTS-1u);
    }
#endif /* (NO_OF_TYPEC_PORTS > 1) */
#endif /* (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S)) */
    if (true == flag)
    {
#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
        /* Take a backup of active configuration */
#if !PDL_VBAT_GND_SCP_ENABLE
        context->bbBat2gndProtCnfgActive = pd->bb_bat2gnd_prot_cnfg;
#endif /* !PDL_VBAT_GND_SCP_ENABLE */
        context->pump5vCtrlActive = pd->pump5v_ctrl;
        context->vconn20CtrlActive = pd->vconn20_ctrl;
        context->vregActive40 = pd->bb_40vreg_ctrl;

        /* Power down Buck-Boost module */
        Cy_USBPD_BB_PowerDown(context);

#if !PDL_VBAT_GND_SCP_ENABLE
        /* Remove CSN and CSP connection to CSA on GND sense path */
        CY_USBPD_REG_FIELD_UPDATE(pd->bb_bat2gnd_prot_cnfg,
            PDSS_BB_BAT2GND_PROT_CNFG_BAT2GND_PROT_SEL, (uint32_t)4u);
#endif /* !PDL_VBAT_GND_SCP_ENABLE */

        /*
         * By default both Deep Sleep and LPM are configured to use
         * DS1 register configuration.
         */
        pd->vconn20_ctrl = PDSS_VCONN20_CTRL_DEFAULT;
#if !defined(CY_DEVICE_SERIES_PMG1B1)
        /* Exclude disabling the pump in deepsleep mode for PMG1B1 */
        pd->pump5v_ctrl = PDSS_PUMP5V_CTRL_DEFAULT;
#endif

#if PDL_VREG_BROWN_OUT_DET_ENABLE
        /*
         * Disable Vddd brown out detection in deep sleep as reference
         * is set to deep sleep and clamp circuit is enabled.
         */
        Cy_USBPD_Fault_BrownOutDetDis(context);
#endif /* PDL_VREG_BROWN_OUT_DET_ENABLE */

        /*
         * Disable common hardware blocks or blocks which have
         * cross signaling between ports only once all ports are
         * disabled/powered down.
         */
        if (port == (NO_OF_TYPEC_PORTS - 1u))
        {
#if (NO_OF_TYPEC_PORTS > 1)
            for (i = TYPEC_PORT_0_IDX; i < NO_OF_TYPEC_PORTS; i++)
#endif /* (NO_OF_TYPEC_PORTS > 1) */
            {
                PPDSS_REGS_T pd_temp = usbpd_ctx_temp->base;
                /* Internal regulator deep sleep entry */
#if (!PDL_VREG_INRUSH_DET_ENABLE)
                pd_temp->bb_40vreg_ctrl = 0x0AD10003;
#else /* (PDL_VREG_INRUSH_DET_ENABLE) */
#if (PMG1B1_USB_CHARGER == 0)
                pd_temp->bb_40vreg_ctrl = 0x0A310003;
#endif /* PMG1B1_USB_CHARGER == 0 */
#endif /* (!PDL_VREG_INRUSH_DET_ENABLE) */
#if defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_SERIES_WLC1)
                /*
                 * For *A silicon.
                 */
                if (Cy_USBPD_Get_Silicon_Rev(context) != 0u)
#endif /* CY_DEVICE_CCG7D || CY_DEVICE_SERIES_WLC1 */
                {
                    pd_temp->bb_40vreg_ctrl |= ((uint32_t)1u <<
                        (3u + PDSS_BB_40VREG_CTRL_BB_40VREG_ACT_BIAS_DAC_POS));
                }

                /*
                 * Configure Refgen block to use Deepsleep Reference input instead of Bandgap
                 * reference which is not available in deep sleep.
                 */
                pd_temp->refgen_0_ctrl &= ~(PDSS_REFGEN_0_CTRL_REFGEN_VREFIN_SEL |
                    PDSS_REFGEN_0_CTRL_REFGEN_VREFIN_MON_SEL);
#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_SERIES_WLC1))
                /*
                 * For *A silicon.
                 * VBAT-GND SCP configuration for deep sleep entry.
                 */
                if (Cy_USBPD_Get_Silicon_Rev(context) != 0u)
#endif /* CY_DEVICE_CCG7D || CY_DEVICE_SERIES_WLC1 */
                {
#if !PDL_VBAT_GND_SCP_ENABLE
                    /* Power down Reference generator */
                    pd_temp->refgen_0_ctrl |= PDSS_REFGEN_0_CTRL_REFGEN_PD;
#else /* PDL_VBAT_GND_SCP_ENABLE */
                    pd_temp->csa_scp_1_ctrl |= PDSS_CSA_SCP_1_CTRL_CSA_EN_IBIAS;
                    usbpd_ctx_temp->bat2gndVrefActive = (uint8_t)CY_USBPD_REG_FIELD_GET(pd_temp->refgen_2_ctrl,
                        PDSS_REFGEN_2_CTRL_SEL4);
                    CY_USBPD_REG_FIELD_UPDATE((pd_temp->refgen_2_ctrl), PDSS_REFGEN_2_CTRL_SEL4, (107u));
                    Cy_SysLib_DelayUs(20);
                    CY_USBPD_REG_FIELD_UPDATE((pd_temp->csa_scp_0_ctrl), PDSS_CSA_SCP_0_CTRL_AV1_TR, ((uint32_t)1u));
#endif /* PDL_VBAT_GND_SCP_ENABLE */
                }
#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_SERIES_WLC1))
                else
                {
                    /* Power down Reference generator */
                    pd_temp->refgen_0_ctrl |= PDSS_REFGEN_0_CTRL_REFGEN_PD;
                }
#endif /* CY_DEVICE_CCG7D || CY_DEVICE_SERIES_WLC1 */
#if (NO_OF_TYPEC_PORTS > 1)
                usbpd_ctx_temp++;
#endif /* (NO_OF_TYPEC_PORTS > 1) */
            }
        }

        /*
         * Note: For Rp, we need 5V VDDD (DS1), otherwise for DS2 VDDD
         * of 3.3V can be set. But, keeping VDDD of 5V by default.
         */
#else /* CY_DEVICE_CCGx */
        /* Deep Sleep Reference requested */
        /*
         * Configure Refgen block to use Deepsleep Reference input instead of Bandgap
         * reference which is not available in deep sleep.
         */
        pd->refgen_0_ctrl &= ~(PDSS_REFGEN_0_CTRL_REFGEN_VREFIN_SEL |
            PDSS_REFGEN_0_CTRL_REFGEN_VREFIN_MON_SEL);

        /* Switch to using refgen_2_ctrl SEL7 for EA shunt regulator reference. */
        pd->amux_ctrl |= AMUX_CTRL_EA_TOP_REFGEN_SEL7_EN;
#endif /* CY_DEVICE_CCG7D || CY_DEVICE_CCG7S */
    }
    else
    {
#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
        /* Power up reference generator */
        pd->refgen_0_ctrl &= ~PDSS_REFGEN_0_CTRL_REFGEN_PD;
#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_SERIES_WLC1))
        /* Restore active configuration for VBAT-GND-SCP */
        /* For *A silicon */
        if (Cy_USBPD_Get_Silicon_Rev(context) != 0u)
#endif /* defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_SERIES_WLC1) */
        {
#if PDL_VBAT_GND_SCP_ENABLE
            /* VBAT-GND SCP configuration for deep sleep exit */
            CY_USBPD_REG_FIELD_UPDATE((pd->csa_scp_0_ctrl), PDSS_CSA_SCP_0_CTRL_AV1_TR, ((uint32_t)0u));
            /* QAC suppression 2985: REG_FEILD_UPDATE is a common functional macro that is used to
             * modify a register field without affecting any other bits of the register. When the field
             * starts from bit position 0, the left shift operation is redundant. Yet this operation is
             * retained to keep it generic and compatible for bitfields starting from other bit positions. */
            CY_USBPD_REG_FIELD_UPDATE((pd->refgen_2_ctrl), PDSS_REFGEN_2_CTRL_SEL4, /* PRQA S 2985 */
                (context->bat2gndVrefActive));
#endif /* PDL_VBAT_GND_SCP_ENABLE */
        }

        /*
         * Configure Refgen block to use Bandgap Reference input instead of Deep sleep
         * reference.
         */
        pd->refgen_0_ctrl |= (PDSS_REFGEN_0_CTRL_REFGEN_VREFIN_SEL |
            PDSS_REFGEN_0_CTRL_REFGEN_VREFIN_MON_SEL);
#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_SERIES_WLC1))
        /* Restore active configuration */
        /* For *A silicon */
        if (Cy_USBPD_Get_Silicon_Rev(context) != 0u)
#endif /* defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_SERIES_WLC1) */
        {
            pd->bb_40vreg_ctrl &= ~((uint32_t)1u <<
                (3u + PDSS_BB_40VREG_CTRL_BB_40VREG_ACT_BIAS_DAC_POS));
        }

        pd->bb_40vreg_ctrl = context->vregActive40;
        Cy_SysLib_DelayUs(20);

#if (PDL_VREG_BROWN_OUT_DET_ENABLE && (PMG1B1_USB_CHARGER == 0))
        /*
         * Re-enable Vddd brown out detection in firmware as
         * 40vreg is in active mode.
         */
        Cy_USBPD_Fault_BrownOutDetEn(context);
#endif /* PDL_VREG_BROWN_OUT_DET_ENABLE && PMG1B1_USB_CHARGER == 0 */

#if !PDL_VBAT_GND_SCP_ENABLE
        pd->bb_bat2gnd_prot_cnfg = context->bbBat2gndProtCnfgActive;
#endif  /* !PDL_VBAT_GND_SCP_ENABLE */
        pd->pump5v_ctrl = context->pump5vCtrlActive;
        pd->vconn20_ctrl = context->vconn20CtrlActive;

        /* Power up Buck-Boost module */
        Cy_USBPD_BB_PowerUp(context);
#else /* CY_DEVICE_CCGx */
        /* Bandgap Reference requested */
        /* Switch to using bandgap for EA shunt regulator reference. */
        pd->amux_ctrl &= ~AMUX_CTRL_EA_TOP_REFGEN_SEL7_EN;

        /*
         * Configure Refgen block to use Bandgap Reference input instead of Deep sleep
         * reference.
         */
        pd->refgen_0_ctrl |= (PDSS_REFGEN_0_CTRL_REFGEN_VREFIN_SEL |
            PDSS_REFGEN_0_CTRL_REFGEN_VREFIN_MON_SEL);
#endif /* CY_DEVICE_CCG7D || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1) */
    }
#else
    CY_UNUSED_PARAMETER(context);
    CY_UNUSED_PARAMETER(flag);
#endif /* ((defined(CY_DEVICE_CCG3PA)) || (defined(CY_DEVICE_CCG3PA2)) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) */
}

/*******************************************************************************
* Function Name: Cy_USBPD_DisableVsysReg
****************************************************************************//**
* 
* This function disables the internal VBus regulator.
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \return
* None
*
*******************************************************************************/
void Cy_USBPD_DisableVsysReg (
        cy_stc_usbpd_context_t *context)
{
    if (context != NULL)
    {
        /*
         * If system has external VDDD source, internal VBUS regulator shall
         * be turned off.
         */
#if (defined(CY_DEVICE_CCG3PA))
        context->base->vreg_vsys_ctrl &= ~(PDSS_VREG_VSYS_CTRL_VREG_EN);
#elif (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3))
        context->base->vreg_vsys_ctrl &= ~(PDSS_VREG_VSYS_CTRL_VREG20_1_EN);
#elif (defined(CY_DEVICE_CCG3) || defined(CY_DEVICE_CCG6DF_CFP))
        context->base->vreg_vsys_ctrl &= ~(PDSS_VREG_VSYS_CTRL_VREG20_EN);
#endif /* (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG6DF_CFP)) */
    }
}

/*******************************************************************************
* Function Name: Cy_USBPD_DisableVsysSwitch
****************************************************************************//**
*
* This function disables the VDDD-VSYS Switch.
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \return
* None
*
*******************************************************************************/
void Cy_USBPD_DisableVsysSwitch (
        cy_stc_usbpd_context_t *context)
{
    if (context != NULL)
    {
#if (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP))
        /*
         * If system has internal VBUS regulator, external VDDD source shall
         * be turned off.
         */
        PPDSS_REGS_T pd = NULL;
        pd = context->base;
        pd->vreg_vsys_ctrl &= ~(PDSS_VREG_VSYS_CTRL_ENABLE_VDDD_SWITCH);
#endif /* (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP)) */
    }
}

/*******************************************************************************
* Function Name: Cy_USBPD_IsVsysUp
****************************************************************************//**
* 
* This function enables the VSYS detect comparator and checks whether VSYS
* supply is up. If VSYS supply is up, the interrupt handler will switch the
* device from VBUS powered state to VSYS powered state. This function should
* be called periodically from the app_task().
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \return bool
* Returns true if Vsys is up.
*
*******************************************************************************/
bool Cy_USBPD_IsVsysUp (
        cy_stc_usbpd_context_t *context)
{
    uint32_t state = 0;
    bool retVal = false;
    PPDSS_REGS_T pd = NULL;
    
    if ((context == NULL) || (context->port != TYPEC_PORT_0_IDX))
    {
        return retVal;
    }
    pd = context->base;

#if (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP))
    if(context->pollForVsys == (uint8_t) CY_USBPD_POLL_VSYS_IDLE)
    {
    
        if ((pd->vreg_vsys_ctrl & PDSS_VREG_VSYS_CTRL_ENABLE_VDDD_SWITCH) == 0U)
        {
            /* Enable the VSYS detect comparator. */
            pd->comp_ctrl[CY_USBPD_VBUS_COMP_ID_VSYS_DET] |= PDSS_COMP_CTRL_COMP_ISO_N;
            pd->comp_ctrl[CY_USBPD_VBUS_COMP_ID_VSYS_DET] &= ~PDSS_COMP_CTRL_COMP_PD;

            /* Wait for a maximum of 200 us to allow VSYS detection to be completed. */
            Cy_SysLib_DelayUs (200);

            /* Disable interrupts while checking for status to prevent race conditions. */
            state = Cy_SysLib_EnterCriticalSection();           
            /* Check if VSYS up interrupt occurred after enabling the comparator. */
            if (context->pollForVsys == (uint8_t) CY_USBPD_POLL_VSYS_IDLE)
            {
                /* VSYS still not detected. Turn off the comparator again. */
                pd->comp_ctrl[CY_USBPD_VBUS_COMP_ID_VSYS_DET] |= PDSS_COMP_CTRL_COMP_PD;
            }
            Cy_SysLib_ExitCriticalSection(state);
        }
    }
    else 
    {
        if(context->pollForVsys == (uint8_t) CY_USBPD_POLL_VSYS_START_TIMER)
        {
            /* Notify app to start delay timer */
            retVal = true;
        }
    }
#elif defined(CY_DEVICE_CCG3)
    if ((pd->ncell_status & PDSS_NCELL_STATUS_VSYS_STATUS) != 0U)
    {
        uint32_t regVal;
        uint16_t vsys_level;
        uint8_t  adc_reading;
        uint16_t value;

        state = Cy_SysLib_EnterCriticalSection();

        regVal = pd->uvov_ctrl;

        /* Disconnect the UV/OV resistor divider from ADFT so that VSYS can be measured. */
        pd->uvov_ctrl &= ~(PDSS_UVOV_CTRL_UVOV_ADFT_EN | PDSS_UVOV_CTRL_UVOV_ADFT_CTRL_MASK);
        Cy_SysLib_DelayUs (100);

        /* Enable VSYS/2 connection to ADFT. */
        pd->vsys_ctrl |= (PDSS_VSYS_CTRL_ADFT_EN | (1UL << PDSS_VSYS_CTRL_ADFT_SEL_POS));
        Cy_SysLib_DelayUs (100);

        /* Measure VSYS voltage using ADC. If VSYS is above 3.2 V, we can switch
           to VSYS power for the device.
           */
        value = Cy_USBPD_Adc_Calibrate (context, CY_USBPD_ADC_ID_0);
        adc_reading = Cy_USBPD_Adc_Sample (context, CY_USBPD_ADC_ID_0, CY_USBPD_ADC_INPUT_AMUX_A);
        vsys_level  = ((uint16_t)adc_reading * context->adcVdddMv[CY_USBPD_ADC_ID_0] * 2U) >> 8u; 

        /* Restore the original ADFT settings. */
        pd->vsys_ctrl &= ~(PDSS_VSYS_CTRL_ADFT_EN | PDSS_VSYS_CTRL_ADFT_SEL_MASK);
        Cy_SysLib_DelayUs (10);
        pd->uvov_ctrl = regVal;

        Cy_SysLib_ExitCriticalSection(state);

        if (vsys_level > 3200u)
        {
            retVal = true;
        }
        CY_UNUSED_PARAMETER(value);
    }
#else
    CY_UNUSED_PARAMETER(state);
    CY_UNUSED_PARAMETER(retVal);
    CY_UNUSED_PARAMETER(pd);
    CY_UNUSED_PARAMETER(context);   
#endif /* defined(CY_DEVICE_CCG3) */

    return retVal;
}

/*******************************************************************************
* Function Name: Cy_USBPD_VsysCompStatus
****************************************************************************//**
* 
* Get the VSYS Comparator Status
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \return bool
* Returns comparator status.
*
*******************************************************************************/
bool Cy_USBPD_VsysCompStatus (
        cy_stc_usbpd_context_t *context)
{
    if (context != NULL)
    {
#if (defined(CY_DEVICE_CCG6) || defined (CY_DEVICE_PMG1S3))
        /* Return the status of the vsys comparator. */
        if ((context->base->intr7_status & (CLK_LF_FILT_NUM << PDSS_INTR7_STATUS_FILT_8_POS)) != 0U)
        {
            return true;
        }
#elif defined(CY_DEVICE_CCG6DF_CFP)
        if ( (context->base->intr7_status & PDSS_INTR7_STATUS_FILT_8) != 0U)
        {
            return true;
        }
#elif (defined(CY_DEVICE_CCG3))
        if ((context->base->ncell_status & PDSS_NCELL_STATUS_VSYS_STATUS) != 0U)
        {
            return true;
        }
#endif
    }

    return false;
}

/*******************************************************************************
* Function Name: Cy_USBPD_SwitchVsysToVbus
****************************************************************************//**
* 
* This function switches over from VSYS VDDD switch to VBUS regulator
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \return
* None
*
*******************************************************************************/
void Cy_USBPD_SwitchVsysToVbus (
        cy_stc_usbpd_context_t *context)
{
#if (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3))
    PPDSS_REGS_T pd = NULL;

    if (context != NULL)
    {
        pd = context->base;

        /* Turn the VBus LDO ON and then turn off the VSYS-VDDD switch. */
        pd->vreg_vsys_ctrl |= PDSS_VREG_VSYS_CTRL_VREG20_1_EN;
        Cy_SysLib_DelayUs (120);
        pd->vreg_vsys_ctrl &= ~PDSS_VREG_VSYS_CTRL_ENABLE_VDDD_SWITCH;
    }
#elif (defined(CY_DEVICE_CCG3) || defined(CY_DEVICE_CCG6DF_CFP))
    PPDSS_REGS_T pd = NULL;

    if (context != NULL)
    {
        pd = context->base;

        /* Turn the VBus LDO ON and then turn off the VSYS-VDDD switch. */
        pd->vreg_vsys_ctrl |= PDSS_VREG_VSYS_CTRL_VREG20_EN;
        Cy_SysLib_DelayUs (120);
        pd->vreg_vsys_ctrl &= ~PDSS_VREG_VSYS_CTRL_ENABLE_VDDD_SWITCH;
    }
#else
    (void)context;
#endif /* (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3)) */
}

/*******************************************************************************
* Function Name: Cy_USBPD_SwitchVbusToVsys
****************************************************************************//**
* 
* This function switches over from VBus Regulator to VSYS VDDD switch.
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \return
* None
*
*******************************************************************************/
void Cy_USBPD_SwitchVbusToVsys (
        cy_stc_usbpd_context_t *context)
{
#if (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3))
    PPDSS_REGS_T pd = NULL;

    if (context != NULL)
    {
        pd = context->base;

        pd->vreg_vsys_ctrl |= PDSS_VREG_VSYS_CTRL_ENABLE_VDDD_SWITCH;
        Cy_SysLib_DelayUs (100);
        pd->vreg_vsys_ctrl &= ~PDSS_VREG_VSYS_CTRL_VREG20_1_EN;
    }
#elif (defined(CY_DEVICE_CCG3) || defined(CY_DEVICE_CCG6DF_CFP))
    PPDSS_REGS_T pd = NULL;

    if (context != NULL)
    {
        pd = context->base;

        pd->vreg_vsys_ctrl |= PDSS_VREG_VSYS_CTRL_ENABLE_VDDD_SWITCH;
        Cy_SysLib_DelayUs (100);
        pd->vreg_vsys_ctrl &= ~PDSS_VREG_VSYS_CTRL_VREG20_EN;
    }
#else
    CY_UNUSED_PARAMETER(context);
#endif /* (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP)) */
}

#if defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)
#if ((!CCG_TEMP_BASED_VOLTAGE_THROTTLING) && (ADFT_DDFT_EN))
/*******************************************************************************
* Function Name: Cy_USBPD_AdftDdftEnable
****************************************************************************//**
* 
* This function enables DDFT or ADFT on GPIO Pin 3.2.
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \return
* None
*
*******************************************************************************/

void Cy_USBPD_AdftDdftEnable(cy_stc_usbpd_context_t *context)
{
    PPDSS_REGS_T pd = context->base;

#if DDFT 

    /* DDFT 0 configuration */
    SRSSLT_TST_DDFT_CTRL = (SRSSLT_TST_DDFT_CTRL & ~SRSSLT_TST_DDFT_CTRL_DFT_SEL0_Msk)
        | (4 << SRSSLT_TST_DDFT_CTRL_DFT_SEL0_Pos); /* 4 is for USBPD0 DDFT 0 */
    CY_USBPD_REG_FIELD_UPDATE(pd->ddft_mux, PDSS_DDFT_MUX_DDFT0_SEL, 40); /* 36/37 BBCTRL_DDFT 0/1, 38/39 NCELL DDFT 0/1 40 INTR_DDFT0*/
    CY_USBPD_REG_FIELD_UPDATE(pd->intr_ddft_mux, PDSS_INTR_DDFT_MUX_INTR_DDFT0_SEL, 188); /* VBUS SC filtered */
    CY_USBPD_REG_FIELD_UPDATE(pd->ncell_ddft_mux, PDSS_NCELL_DDFT_MUX_NCELL_DDFT0_SEL, 227); /* CCG7D NCELL DDFT MUX 0 */
    CY_USBPD_REG_FIELD_UPDATE(pd->ccg7d_ncell_ddft_mux,
        PDSS_CCG7D_NCELL_DDFT_MUX_CCG7D_NCELL_DDFT0_SEL, 19); /* vin_uvp_det_fx */
    CY_USBPD_REG_FIELD_UPDATE(pd->bbctrl_ddft_mux, PDSS_BBCTRL_DDFT_MUX_BBCTRL_DDFT0_SEL, 28); /* skip_mode_enter */
    gpio_hsiom_set_config(GPIO_PORT_1_PIN_4, HSIOM_MODE_GPIO,
        GPIO_DM_STRONG, false);

#if DDFT1_ENABLE
    /* DDFT 1 configuration */
    SRSSLT_TST_DDFT_CTRL = (SRSSLT_TST_DDFT_CTRL & ~SRSSLT_TST_DDFT_CTRL_DFT_SEL1_Msk)
        | (5 << SRSSLT_TST_DDFT_CTRL_DFT_SEL1_Pos); /* 5 is for USBPD0 DDFT 1 */
    CY_USBPD_REG_FIELD_UPDATE(pd->ddft_mux, PDSS_DDFT_MUX_DDFT1_SEL, 41); /* 36/37 BBCTRL_DDFT 0/1, 38/39 NCELL DDFT 0/1 41 INTR_DDFT1*/
    CY_USBPD_REG_FIELD_UPDATE(pd->intr_ddft_mux, PDSS_INTR_DDFT_MUX_INTR_DDFT1_SEL, 181); /* VBUS UV filtered */
    CY_USBPD_REG_FIELD_UPDATE(pd->ncell_ddft_mux, PDSS_NCELL_DDFT_MUX_NCELL_DDFT1_SEL, 228); /* NCELL DDFT MUX 1 */
    CY_USBPD_REG_FIELD_UPDATE(pd->ccg7d_ncell_ddft_mux,
        PDSS_CCG7D_NCELL_DDFT_MUX_CCG7D_NCELL_DDFT1_SEL, 66); /* cc1_ovp_fx */
    CY_USBPD_REG_FIELD_UPDATE(pd->bbctrl_ddft_mux, PDSS_BBCTRL_DDFT_MUX_BBCTRL_DDFT1_SEL, 27); /* skip_mode_exit */
    gpio_hsiom_set_config(GPIO_PORT_1_PIN_3, HSIOM_MODE_GPIO,
        GPIO_DM_STRONG, false);
#endif /* DDFT1_ENABLE */

    SRSSLT_TST_DDFT_CTRL |= (1u << 31);

#else /* ADFT */

    /* ADFT configuration */
    CY_USBPD_REG_FIELD_UPDATE(pd->csa_scp_0_ctrl, PDSS_CSA_SCP_0_CTRL_CSA_ADFT_CTRL, 13);
    CALL_MAP(gpio_hsiom_set_config)(GPIO_PORT_3_PIN_2, HSIOM_MODE_AMUXA, 
        GPIO_DM_HIZ_ANALOG, false);

#endif /* DDFT */
}

#endif /* ((ADFT_DDFT_EN) */

/*******************************************************************************
* Function Name: Cy_USBPD_CurrentTrimInit
****************************************************************************//**
* 
* This function loads trim values for trim initialization.
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \return
* None
*
*******************************************************************************/

static void Cy_USBPD_CurrentTrimInit(cy_stc_usbpd_context_t *context)
{
    uint8_t trim_cc_0p6_g80_2a;
    uint8_t trim_cc_0p6_g80_3a;

#if defined(CY_DEVICE_SERIES_WLC1)
    uint8_t trim_cc_0p6_g40_2a;
    uint8_t trim_cc_0p6_g40_3a;
#endif /* defined(CY_DEVICE_SERIES_WLC1) */
    uint8_t port = context->port;

#if !FG_PART
   /*
    * ** Silicon has room temperature trim values.
    * Whereas,
    * *A Silicon does not have any room temperature trims.
    */
   if(CC_TRIM_ROOM_FLAG((port)) != 0u)
   {

#if CY_USE_CONFIG_TABLE
        if (pd_get_ptr_auto_cfg_tbl(context)->max_current > CY_USBPD_I_3A)
#else
        if (context->usbpdConfig->autoConfig->max_current > CY_USBPD_I_3A)
#endif
        {
            context->trimsConfig.cc_trim_1a = CC_GAIN60_GM0P2_TRIM_1A_ROOM((port));
            context->trimsConfig.cc_trim_2a = CC_GAIN60_GM0P2_TRIM_2A_ROOM((port));
            context->trimsConfig.cc_trim_3a = CC_GAIN60_GM0P2_TRIM_3A_ROOM((port));
            context->trimsConfig.cc_trim_3a_g2 = CC_GAIN60_GM0P2_TRIM_3A_ROOM((port));
            context->trimsConfig.cc_trim_4a_g2 = CC_GAIN60_GM0P2_TRIM_4A_ROOM((port));
            context->trimsConfig.cc_trim_5a_g2 = CC_GAIN60_GM0P2_TRIM_5A_ROOM((port));
        }
        else
        {
            context->trimsConfig.cc_trim_1a = CC_GAIN80_GM0P2_TRIM_1A_ROOM((port));
            context->trimsConfig.cc_trim_2a = CC_GAIN80_GM0P2_TRIM_2A_ROOM((port));
            context->trimsConfig.cc_trim_3a = CC_GAIN80_GM0P2_TRIM_3A_ROOM((port));
            context->trimsConfig.cc_trim_3a_g2 = CC_VREF_VALUE_MAX;
            context->trimsConfig.cc_trim_4a_g2 = CC_VREF_VALUE_MAX;
            context->trimsConfig.cc_trim_5a_g2 = CC_VREF_VALUE_MAX; 
        }
#if PMG1B1_USB_CHARGER
        context->trimsConfig.cc_trim_1a_100 = CC_GAIN100_GM0P2_TRIM_1A_ROOM((port));
        context->trimsConfig.cc_trim_2a_100 = CC_GAIN100_GM0P2_TRIM_2A_ROOM((port));
        context->trimsConfig.cc_trim_1a_110 = CC_GAIN110_GM0P2_TRIM_1A_ROOM((port));
        context->trimsConfig.cc_trim_2a_110 = CC_GAIN110_GM0P2_TRIM_2A_ROOM((port));
#endif /* PMG1B1_USB_CHARGER */

    }
#else /* Temporary Offset */
    uint16_t trim_delta;
    uint16_t gm_diff;
    uint32_t trim_code_offset[3];
    uint8_t final_trim_code_offset;
    uint8_t final_trim_code_offset_g2;

    /* Use offset for trims */
    if(CC_TRIM_ROOM_FLAG(port) != 0)
    {
        trim_delta = (CC_GAIN80_GM0P6_TRIM_3A_ROOM(port) -  CC_GAIN80_GM0P6_TRIM_1A_ROOM(port));
        /* 1A */
        gm_diff = (CC_GAIN80_GM0P6_TRIM_1A_ROOM(port) - CC_GAIN80_GM0P2_TRIM_1A_ROOM(port));
        trim_code_offset[0] = ((((CC_GAIN80_GM0P6_TRIM_1A_ROOM(port) * 10) + 130) * 230) - 
            (1 * 2 * 575 * trim_delta) + (gm_diff * 12500));
        /* 2A */
        gm_diff = (CC_GAIN80_GM0P6_TRIM_2A_ROOM(port) - CC_GAIN80_GM0P2_TRIM_2A_ROOM(port));
        trim_code_offset[1] = ((((CC_GAIN80_GM0P6_TRIM_2A_ROOM(port) * 10) + 130) * 230) - 
            (2 * 2 * 575 * trim_delta) + (gm_diff * 12500));
        /* 3A */
        gm_diff = (CC_GAIN80_GM0P6_TRIM_3A_ROOM(port) - CC_GAIN80_GM0P2_TRIM_3A_ROOM(port));
        trim_code_offset[2] = ((((CC_GAIN80_GM0P6_TRIM_3A_ROOM(port) * 10) + 130) * 230) - 
            (3 * 2 * 575 * trim_delta) + (gm_diff * 12500));

        final_trim_code_offset  = ((((trim_code_offset[0] + trim_code_offset[1] + 
            trim_code_offset[2]) / 3) + 5000) / 10000) ;

        final_trim_code_offset_g2  = ((((trim_code_offset[0] + trim_code_offset[1] + 
            trim_code_offset[2]) / 4) + 5000) / 10000) ;

        /* 
         * Need dynamic CC/CF gain setting.
         * Gain = 80 for <=3A
         * Gain = 60 for >3A
         */
        context->trimsConfig.cc_trim_1a = (CC_GAIN80_GM0P2_TRIM_1A_ROOM(port) - final_trim_code_offset);
        context->trimsConfig.cc_trim_2a = (CC_GAIN80_GM0P2_TRIM_2A_ROOM(port) - final_trim_code_offset);
        context->trimsConfig.cc_trim_3a = (CC_GAIN80_GM0P2_TRIM_3A_ROOM(port) - final_trim_code_offset);
        context->trimsConfig.cc_trim_3a_g2 = (CC_GAIN60_GM0P2_TRIM_3A_ROOM(port) - final_trim_code_offset_g2);
        context->trimsConfig.cc_trim_4a_g2 = (CC_GAIN60_GM0P2_TRIM_4A_ROOM(port) - final_trim_code_offset_g2);
        context->trimsConfig.cc_trim_5a_g2 = (CC_GAIN60_GM0P2_TRIM_5A_ROOM(port) - final_trim_code_offset_g2);
    }
#endif /* !FG_PART */
    else
    {
#if CY_USE_CONFIG_TABLE
        if (pd_get_ptr_auto_cfg_tbl(context)->max_current > CY_USBPD_I_3A)
#else
        if (context->usbpdConfig->autoConfig->max_current > CY_USBPD_I_3A)
#endif
        {
            context->trimsConfig.cc_trim_1a = ((CC_GAIN60_GM0P2_TRIM_1A_H((port)) + 
                CC_GAIN60_GM0P2_TRIM_1A_C((port))) >> 1);
            context->trimsConfig.cc_trim_2a = ((CC_GAIN60_GM0P2_TRIM_2A_H((port)) + 
                CC_GAIN60_GM0P2_TRIM_2A_C((port))) >> 1);
            context->trimsConfig.cc_trim_3a = ((CC_GAIN60_GM0P2_TRIM_3A_H((port)) + 
                CC_GAIN60_GM0P2_TRIM_3A_C((port))) >> 1);
            context->trimsConfig.cc_trim_3a_g2 = ((CC_GAIN60_GM0P2_TRIM_3A_H((port)) + 
                CC_GAIN60_GM0P2_TRIM_3A_C((port))) >> 1);
            context->trimsConfig.cc_trim_4a_g2 = ((CC_GAIN60_GM0P2_TRIM_4A_H((port)) + 
                CC_GAIN60_GM0P2_TRIM_4A_C((port))) >> 1);
            context->trimsConfig.cc_trim_5a_g2 = ((CC_GAIN60_GM0P2_TRIM_5A_H((port)) + 
                CC_GAIN60_GM0P2_TRIM_5A_C((port))) >> 1);
        }
        else
        {
            context->trimsConfig.cc_trim_1a = ((CC_GAIN80_GM0P2_TRIM_1A_H((port)) + 
                CC_GAIN80_GM0P2_TRIM_1A_C((port))) >> 1);
            context->trimsConfig.cc_trim_2a = ((CC_GAIN80_GM0P2_TRIM_2A_H((port)) + 
                CC_GAIN80_GM0P2_TRIM_2A_C((port))) >> 1);
            context->trimsConfig.cc_trim_3a = ((CC_GAIN80_GM0P2_TRIM_3A_H((port)) + 
                CC_GAIN80_GM0P2_TRIM_3A_C((port))) >> 1);
            context->trimsConfig.cc_trim_3a_g2 = CC_VREF_VALUE_MAX;
            context->trimsConfig.cc_trim_4a_g2 = CC_VREF_VALUE_MAX;
            context->trimsConfig.cc_trim_5a_g2 = CC_VREF_VALUE_MAX;
        }
#if PMG1B1_USB_CHARGER
        context->trimsConfig.cc_trim_1a_100 = ((CC_GAIN100_GM0P2_TRIM_1A_H((port)) +
            CC_GAIN100_GM0P2_TRIM_1A_C((port))) >> 1);
        context->trimsConfig.cc_trim_2a_100 = ((CC_GAIN100_GM0P2_TRIM_2A_H((port)) +
            CC_GAIN100_GM0P2_TRIM_2A_C((port))) >> 1);
        context->trimsConfig.cc_trim_1a_110 = ((CC_GAIN110_GM0P2_TRIM_1A_H((port)) +
            CC_GAIN110_GM0P2_TRIM_1A_C((port))) >> 1);
        context->trimsConfig.cc_trim_2a_110 = ((CC_GAIN110_GM0P2_TRIM_2A_H((port)) +
            CC_GAIN110_GM0P2_TRIM_2A_C((port))) >> 1);
#endif /* PMG1B1_USB_CHARGER */
    }

    /* 20CSA trim calculation from CC trims */
    if(CC_TRIM_ROOM_FLAG((port)) != 0u)
    {
        trim_cc_0p6_g80_2a = CC_GAIN80_GM0P6_TRIM_2A_ROOM((port));
        trim_cc_0p6_g80_3a = CC_GAIN80_GM0P6_TRIM_3A_ROOM((port));
    }
    else
    {
        trim_cc_0p6_g80_2a = ((CC_GAIN80_GM0P6_TRIM_2A_H((port)) + 
            CC_GAIN80_GM0P6_TRIM_2A_C((port))) >> 1);
        trim_cc_0p6_g80_3a = ((CC_GAIN80_GM0P6_TRIM_3A_H((port)) + 
            CC_GAIN80_GM0P6_TRIM_3A_C((port))) >> 1);
    }

#if defined(CY_DEVICE_SERIES_WLC1)
    /* Use Gain 40 trims for better accuracy */
    trim_cc_0p6_g40_2a = CC_GAIN40_GM0P6_TRIM_2A_ROOM((port));
    trim_cc_0p6_g40_3a = CC_GAIN40_GM0P6_TRIM_3A_ROOM((port));
    context->trimsConfig.offset_20csa = ((((((trim_cc_0p6_g40_3a * 1000u) + 13000u) / 40u) - 1500u) + 
        ((((trim_cc_0p6_g40_2a * 1000u) + 13000u) / 40u) - 1000u)) >> 1u);
    CY_UNUSED_PARAMETER(trim_cc_0p6_g80_2a);
    CY_UNUSED_PARAMETER(trim_cc_0p6_g80_3a);

#else
    context->trimsConfig.offset_20csa = ((((((trim_cc_0p6_g80_3a * 1000u) + 13000u) / 80u) - 1500u) + 
        ((((trim_cc_0p6_g80_2a * 1000u) + 13000u) / 80u) - 1000u)) >> 1u);
#endif /* defined(CY_DEVICE_SERIES_WLC1) */
}

#endif /* defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1) */

/*******************************************************************************
* Function Name: Cy_USBPD_Init
****************************************************************************//**
* 
* This function initializes the PDSS IP with necessary clock and interrupt
* handlers.
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \param port
* Port index
*
* \param ptrPdBaseReg
* Base register address for PD block
* 
* \param ptrPdTrimsBaseReg
* Base register address for TRIMs
*
* \param ptrUsbpdConfig
* USBPD block configuration structure pointer
*
* \param dpmGetConfigCbk
* DPM status function callback 
*
* \return
* CY_USBPD_STAT_SUCCESS if operation is successful. 
* CY_USBPD_STAT_BAD_PARAM if the context pointer is invalid.
* CY_USBPD_STAT_FAILURE if the operation failed.
*
*******************************************************************************/
cy_en_usbpd_status_t Cy_USBPD_Init(
        cy_stc_usbpd_context_t *context,
        uint8_t port,
        void *ptrPdBaseReg,
        void *ptrPdTrimsBaseReg,
        cy_stc_usbpd_config_t *ptrUsbpdConfig,
        cy_cb_pd_dpm_get_config_t dpmGetConfigCbk)
{
    cy_en_usbpd_status_t status;
    PPDSS_REGS_T pd = NULL;
#if defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)
    PPDSS_TRIMS_REGS_T pdtrims;
#endif /* defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1) */
#if defined(CY_DEVICE_CCG3)
    uint32_t tmp;
#endif /* defined(CY_DEVICE_CCG3) */
#if defined(CY_DEVICE_PMG1S3)
    uint8_t vref = 0u;
#endif /* defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP) */

#if ((defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_CCG3PA)) && PMG1_FLIPPED_FET_CTRL)
#if VBUS_SLOW_DISCHARGE_EN
    cy_stc_usbpd_context_t *usbpd_ctx_temp=context;
#if (NO_OF_TYPEC_PORTS > 1)
    if(port != 0u)
    {
        usbpd_ctx_temp=context-(NO_OF_TYPEC_PORTS-1u);
    }
#endif /* (NO_OF_TYPEC_PORTS > 1) */
     PPDSS_REGS_T pd_temp = usbpd_ctx_temp->base;
#endif /* VBUS_SLOW_DISCHARGE_EN */
#endif /* ((defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_CCG3PA)) && PMG1_FLIPPED_FET_CTRL) */
    /* Validate the parameters. */
    if (
            (context != NULL) && (ptrPdBaseReg != NULL) &&
#if (!defined(CY_DEVICE_CCG3))
            /* PMG1S2 does not have a separate trim register space. */
            (ptrPdTrimsBaseReg != NULL) &&
#endif /* (!defined(CY_DEVICE_CCG3)) */
            (ptrUsbpdConfig != NULL) &&
            (dpmGetConfigCbk != NULL)
       )
    {

        /* Initialize the context members. */
        context->port = port;
        context->base = ptrPdBaseReg;
        context->trimsBase = ptrPdTrimsBaseReg;
        context->usbpdConfig = ptrUsbpdConfig;
        context->dpmGetConfig = dpmGetConfigCbk;

        pd = context->base;
#if defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)
        pdtrims = (PPDSS_TRIMS_REGS_T)context->trimsBase;
#endif /* defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1) */

        /* Enable the PD block. */
        pd->ctrl |= PDSS_CTRL_IP_ENABLED;

#if defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)

        CY_USBPD_REG_FIELD_UPDATE(pd->ngdo_ctrl, PDSS_NGDO_CTRL_NGDO_SLEW_CTRL, (uint32_t)0x03u);


#endif /* defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1) */

        /* Power up the block. */
        pd->cc_ctrl_0 &= ~PDSS_CC_CTRL_0_PWR_DISABLE;

        /* Turn ON PHY deepsleep. References require 100us to stabilize. */
#if !defined(CY_DEVICE_CCG6DF_CFP)
        pd->dpslp_ref_ctrl &= ~PDSS_DPSLP_REF_CTRL_PD_DPSLP;
#endif /* !defined(CY_DEVICE_CCG6DF_CFP) */

        /*
         * Enable deep-sleep current reference outputs.
         */
#if !defined(CY_DEVICE_CCG6DF_CFP)
        pd->dpslp_ref_ctrl |= PDSS_DPSLP_REF_CTRL_IGEN_EN;
#endif /* !defined(CY_DEVICE_CCG6DF_CFP) */
        Cy_SysLib_DelayUs(100);

#if defined(CY_DEVICE_CCG3)
        /* Settings as recommended by design */
        pd->vreg_ctrl |= PDSS_VREG_CTRL_VREG_ISO_N;
        pd->vsys_ctrl |= PDSS_VSYS_CTRL_VSYS_ISO_N;

        /* Set trim settings. */
        tmp = pd->s8usbpd_trim_6 & ~PDSS_S8USBPD_TRIM_6_V1P575_TRIM_MASK;
        tmp |= SILICON_TRIM6_V1P575_TRIM_VALUE;
        pd->s8usbpd_trim_6 = tmp;

        tmp = pd->s8usbpd_trim_3 & ~PDSS_S8USBPD_TRIM_3_V0P55_TRIM_MASK;
        tmp |= SILICON_TRIM3_V0P55_TRIM_VALUE;
        pd->s8usbpd_trim_3 = tmp;

        /*
         * Clearing of TX_TRIM field is enough for Rp = 1.5A or Default termination
         * at initialization time. Later TX_TRIM could be updated for Rp = 3A
         * termination.
         */
        pd->s8usbpd_trim_0 &= (~(PDSS_S8USBPD_TRIM_0_TX_TRIM_MASK));

        /*
         * The UVP comparator shall be reserved for VBUS internal divider. We expect to
         * use a 1/11 fraction of VBus for voltage measurements. Using 0.74 V as the voltage
         * reference, this results in a VBus equivalent voltage of 8.14 V.
         *
         * Rounding to the nearest voltage setting from RISH-183, we need to use UV_IN value
         * of 22. The same value is being loaded into OV_IN until it is corrected as part
         * of OVP configuration.
         */
        tmp = pd->uvov_ctrl & ~(PDSS_UVOV_CTRL_UV_IN_MASK | PDSS_UVOV_CTRL_OV_IN_MASK |
                PDSS_UVOV_CTRL_UVOV_ADFT_CTRL_MASK | PDSS_UVOV_CTRL_PD_UVOV);
        tmp |= ((22UL << PDSS_UVOV_CTRL_UV_IN_POS) | (22UL << PDSS_UVOV_CTRL_OV_IN_POS) |
                PDSS_UVOV_CTRL_UVOV_ISO_N | PDSS_UVOV_CTRL_UVOV_ADFT_EN |
                (1UL << PDSS_UVOV_CTRL_UVOV_ADFT_CTRL_POS));
        pd->uvov_ctrl = tmp;

        /*
         * CDT 264973: The clock divider to drive the charge pump should be the lowest
         * (fastest clock) so that the gate drivers are turned on quickly. This setting
         * corresponds to the timing specs for the device.
         */
        pd->ngdo_ctrl_0 &= ~(PDSS_NGDO_CTRL_0_NGDO_VBUS_C_CLKSEL_LV_MASK | PDSS_NGDO_CTRL_0_NGDO_VBUS_P_CLKSEL_LV_MASK);

        /*
         * Bypass the synchronizer for fault detection in CLK_LF domain, so that
         * spacing takes effect right after fault detection.
         */
        pd->ngdo_ctrl_p |= PDSS_NGDO_CTRL_P_BYPASS_2DFF;
        pd->ngdo_ctrl_c |= PDSS_NGDO_CTRL_C_BYPASS_2DFF;
#endif /* defined(CY_DEVICE_CCG3) */
#if (defined(CY_DEVICE_CCG6DF_CFP))
        /*
         * The Deep Sleep voltage reference is used as input to the refgen block at all times.
         * SEL0 & 1 - Not connected for CCG6DF_CFP.
         * SEL2 - VBUS UV
         * SEL3 - VBUS OV
         * SEL4 - VSYS DET
         * Each step is 10mV unit and on CCG6DF_CFP, minimum voltage is 130mV. Hence value 0x00 
         * corresponds to 130mV output.
         * (Output voltage in mV - 130mV)/10 gives the value in decimal. convert to hex and update.
         * E.g for 400mV --> (400 - 130)/10 --> 27 --> 0x1B.
         */
        pd->pd_ref_gen_ctrl     &= ~PDSS_PD_REF_GEN_CTRL_PD;
        pd->pd_ref_mux_ctrl_0   = 0x231B0000; /* SEL0=NC, SEL1=NC, SEL2=0x1B(400 mV), SEL3=0x23(480 mV) */
        pd->pd_ref_mux_ctrl_1   = 0x00006600; /* SEL4=0x66(1.15 V) */

        /* Give some delay for references to settle. */
        Cy_SysLib_DelayUs (50);

        /* Enable the VSYS_DET comparator. Corresponding LF filter also needs to be enabled.
           Look for both positive and negative edge interrupts.
           */
        /* Set the current reference used for VConn Over-Current detection. */
        /* Default value of the field is 2. so no need to update here. */
        /* pd->pd_reg_control = ((pd->pd_reg_control & ~PDSS_PD_REG_CONTROL_INRUSH_DET_SEL_MASK) |
                (2u << PDSS_PD_REG_CONTROL_INRUSH_DET_SEL_POS));*/
        if (context->port == TYPEC_PORT_0_IDX)
        {
            /* Enable interrupt on either positive or negative edge from the VSYS_DET comparator. */
            pd->comp_ctrl[CY_USBPD_VBUS_COMP_ID_VSYS_DET] |= PDSS_COMP_CTRL_COMP_ISO_N;
            pd->comp_ctrl[CY_USBPD_VBUS_COMP_ID_VSYS_DET] &= ~PDSS_COMP_CTRL_COMP_PD;
            pd->intr7_filter_cfg = (PDSS_INTR7_FILTER_CFG_CLK_LF_FILT_BYPASS |
                    PDSS_INTR7_FILTER_CFG_CLK_LF_FILT_RESET |
                    ((uint32_t)CY_USBPD_VBUS_FILTER_CFG_POS_EN_NEG_EN << PDSS_INTR7_FILTER_CFG_FILT_CFG_POS));

            /* Need to disable the bypass on VSYS good comparator. */
            pd->pd_reg_ctrl |= PDSS_PD_REG_CTRL_BYPASS_VSYS_GOOD_ACCB;

            /* Wait for some time and check VSYS status. */
            Cy_SysLib_Delay (1);
#if defined(PSVP_FPGA_ENABLE)
            /* Force notify application about presence of VSYS supply for PSVP. */
            if (context->supplyChangeCbk != NULL)
            {
                context->supplyChangeCbk (context, CY_USBPD_SUPPLY_VSYS, true);
            }
#else
            if ((pd->intr7_status & (PDSS_INTR7_STATUS_FILT_8)) == 0U)
            {
                /* Notify application layer about absence of VSYS supply. */
                if (context->supplyChangeCbk != NULL)
                {
                    context->supplyChangeCbk (context, CY_USBPD_SUPPLY_VSYS, false);
                }
                Cy_SysLib_Delay (1);

                /* VSYS is not present, disable VSYS switch. */
                pd->vreg_vsys_ctrl &= ~PDSS_VREG_VSYS_CTRL_ENABLE_VDDD_SWITCH;

                /* Leave the VSYS detect comparator disabled. We will enable this periodically to check for VSYS up. */
                pd->comp_ctrl[CY_USBPD_VBUS_COMP_ID_VSYS_DET] |= PDSS_COMP_CTRL_COMP_PD;
            }
            else
            {
                /* Notify application about presence of VSYS supply. */
                if (context->supplyChangeCbk != NULL)
                {
                    context->supplyChangeCbk (context, CY_USBPD_SUPPLY_VSYS, true);
                }
            }
#endif /* PSVP_FPGA_ENABLE */

            /* Enable interrupt for VSYS detection. */
            pd->intr7_mask |= (PDSS_INTR7_CLK_LF_EDGE_CHANGED);
            /* Enable polling for VSYS status change. */
            context->pollForVsys = (uint8_t) CY_USBPD_POLL_VSYS_IDLE;
        }

        /* Enable HF Clk as source for Fault protection filters. */
        pd->ctrl |= PDSS_CTRL_SEL_CLK_FILTER;


        /* amux_nhv[5]/amux_nhv[3] should be set for proper connection.
           amux_nhv[2] is used to select 6% divider instead of 8% divider.
         */    
        pd->amux_nhv_ctrl |= (1UL << 3) | (1UL << 2);
        /*
         * Connect 10% of VBUS_C to VBUS_MON comparator input. This has to be done at start to prevent errors on
         * the pct10 feedback lines.
         */
        pd->amux_denfet_ctrl |= PDSS_AMUX_DENFET_CTRL_SEL;
#endif /* (defined(CY_DEVICE_CCG6DF_CFP)) */

#if defined(CY_DEVICE_PMG1S3)
        /* Disable the keep off control circuit. */
        pd->v2_ngdo_0_ctrl |= PDSS_V2_NGDO_0_CTRL_KEEP_OFF_DISABLE;
#endif /* defined(CY_DEVICE_PMG1S3) */

#if (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3))
        /*
         * The Deep Sleep voltage reference is used as input to the refgen block at all times.
         */
        pd->refgen_0_ctrl &= ~PDSS_REFGEN_0_CTRL_REFGEN_PD;
        pd->refgen_1_ctrl  = 0x1C143636; /* SEL0=0x36(740 mV), SEL1=0x36(740 mV), SEL2=0x14(400 mV), SEL3=0x1C(480 mV) */
        pd->refgen_2_ctrl  = 0x003D6B5F; /* SEL4=0x5F(1.08 V), SEL5=0x6B(1.20 V), SEL6=0x3D(740 mV), SEL7=0x00(130 mV) */
        pd->refgen_3_ctrl  = 0x00003D14; /* SEL8=0x14(330 mV), SEL9=0x3D(740 mV), SEL10=0x00(130 mV) */
        pd->refgen_4_ctrl  = 0x00000900; /* SEL11=0x00(450 mV), SEL12=0x00(650 mV), SEL13=0x04(2.0 V), SEL14=0x04(1.12 V) */

#if defined(CY_DEVICE_PMG1S3)
        /* Set the threshold for SCP-RCP block to work */
        vref = (uint8_t)((*((volatile uint8_t *)(SFLASH_SCP_RCP_VREF_TRIM_HOT + (uint16_t)(port * 0x100u))) + 
                          *((volatile uint8_t *)(SFLASH_SCP_RCP_VREF_TRIM_COLD + (uint16_t)(port * 0x100u)))) / 2U);
    //    vref = *((volatile uint8_t *)SFLASH_SCP_RCP_VREF_TRIM_ROOM);  /* In case room trim is available */
        pd->refgen_2_ctrl  = Cy_USBPD_MmioRegUpdateField(pd->refgen_2_ctrl, (uint32_t)vref,
                    PDSS_REFGEN_2_CTRL_SEL5_MASK, (uint8_t)PDSS_REFGEN_2_CTRL_SEL5_POS);
#endif /* defined(CY_DEVICE_PMG1S3) */

        /* Give some delay for references to settle. */
        Cy_SysLib_DelayUs (50);

        /* Enable the VSYS_DET comparator. Corresponding LF filter also needs to be enabled.
           Look for both positive and negative edge interrupts.
           */
        /* Set the current reference used for VConn Over-Current detection. */
        pd->reg_control = ((pd->reg_control & ~PDSS_REG_CONTROL_T_REG_CONTROL_MASK) |
                (2u << PDSS_REG_CONTROL_T_REG_CONTROL_POS));

        if (*((volatile uint8_t *)SFLASH_VCONN_TRIM_ENABLE_ADDR) == 0u)
        {
#if defined(CY_DEVICE_CCG6)
            /* If optimal VConn OCP trims were not available in SFLASH, override with default value. */
            PPDSS_TRIMS_REGS_T trimRegs = (PPDSS_TRIMS_REGS_T)context->trimsBase;
            trimRegs->trim_vconn20_2 = 0x08u;
#endif /* defined(CY_DEVICE_CCG6) */
        }

        if (context->port == TYPEC_PORT_0_IDX)
        {
            /* Enable interrupt on either positive or negative edge from the VSYS_DET comparator. */
            pd->comp_ctrl[CY_USBPD_VBUS_COMP_ID_VSYS_DET] |= PDSS_COMP_CTRL_COMP_ISO_N;
            pd->comp_ctrl[CY_USBPD_VBUS_COMP_ID_VSYS_DET] &= ~PDSS_COMP_CTRL_COMP_PD;
#if defined(CY_DEVICE_CCG6)
            pd->intr7_filter_cfg[1] = (PDSS_INTR7_FILTER_CFG_CLK_LF_FILT_BYPASS |
                    PDSS_INTR7_FILTER_CFG_CLK_LF_FILT_RESET |
                    ((uint32_t)CY_USBPD_VBUS_FILTER_CFG_POS_EN_NEG_EN << PDSS_INTR7_FILTER_CFG_FILT_CFG_POS));
#endif /* defined(CY_DEVICE_CCG6) */
#if defined(CY_DEVICE_PMG1S3)
            pd->intr7_filter_cfg[2] = (PDSS_INTR7_FILTER_CFG_CLK_LF_FILT_BYPASS |
                    PDSS_INTR7_FILTER_CFG_CLK_LF_FILT_RESET |
                    ((uint32_t)CY_USBPD_VBUS_FILTER_CFG_POS_EN_NEG_EN << PDSS_INTR7_FILTER_CFG_FILT_CFG_POS));
#endif /* defined(CY_DEVICE_PMG1S3) */

            /* Need to disable the bypass on VSYS good comparator. */
            pd->reg_control |= PDSS_REG_CONTROL_BYPASS_VSYS_GOOD_ACC;

            /* Wait for some time and check VSYS status. */
            Cy_SysLib_Delay (1);
            if ((pd->intr7_status & (CLK_LF_FILT_NUM << PDSS_INTR7_STATUS_FILT_8_POS)) == 0U)
            {
                /* Notify application layer about absence of VSYS supply. */
                if (context->supplyChangeCbk != NULL)
                {
                    context->supplyChangeCbk (context, CY_USBPD_SUPPLY_VSYS, false);
                }
                Cy_SysLib_Delay (1);

                /* VSYS is not present, disable VSYS switch. */
                pd->vreg_vsys_ctrl &= ~PDSS_VREG_VSYS_CTRL_ENABLE_VDDD_SWITCH;

                /* Leave the VSYS detect comparator disabled. We will enable this periodically to check for VSYS up. */
                pd->comp_ctrl[CY_USBPD_VBUS_COMP_ID_VSYS_DET] |= PDSS_COMP_CTRL_COMP_PD;
            }
            else
            {
                /* Notify application about presence of VSYS supply. */
                if (context->supplyChangeCbk != NULL)
                {
                    context->supplyChangeCbk (context, CY_USBPD_SUPPLY_VSYS, true);
                }
            }

            /* Enable interrupt for VSYS detection. */
            pd->intr7_mask |= (CLK_LF_FILT_NUM << PDSS_INTR7_CLK_LF_EDGE_CHANGED_POS);
            /* Enable polling for VSYS status change. */
            context->pollForVsys = (uint8_t) CY_USBPD_POLL_VSYS_IDLE;
        }

        /* Enable HF Clk as source for Fault protection filters. */
        pd->ctrl |= PDSS_CTRL_SEL_CLK_FILTER;


#if defined(CY_DEVICE_CCG6)     
        /* amux_nhv[4]/amux_nhv[3] should be set for proper connection.
           amux_nhv[3]/amux_nhv[2] is used to select 8% divider instead of 10% divider.
         */
        pd->amux_nhv_ctrl |= (3UL << 3UL);
#else
        /* amux_nhv[5]/amux_nhv[3] should be set for proper connection.
           amux_nhv[2] is used to select 8% divider instead of 6% divider.
         */    
        pd->amux_nhv_ctrl |= (1UL << 3) | (1UL << 2);
#endif
        /*
         * Connect 10% of VBUS_C to VBUS_MON comparator input. This has to be done at start to prevent errors on
         * the pct10 feedback lines.
         */
        pd->amux_denfet_ctrl |= PDSS_AMUX_DENFET_CTRL_SEL;

        /* Disable RCP comparator which are enabled by default */
        pd->csa_rcp_1_ctrl &= ~((1UL<<7) | (1UL<<0)) ;
#endif /* (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP)) */

#if defined(CY_DEVICE_CCG3PA)

        context->vbusCsaRsense=LSCSA_DEF_RSENSE_P0;
        /* Enable HF Clk as source for Fault protection filters. */
        pd->ctrl |= PDSS_CTRL_SEL_CLK_FILTER;

        /* Update Refgen setting */
        pd->refgen_0_ctrl &= ~PDSS_REFGEN_0_CTRL_REFGEN_PD;
        pd->refgen_0_ctrl  |= PDSS_REFGEN_0_CTRL_REFGEN_VREFIN_SEL |
            PDSS_REFGEN_0_CTRL_REFGEN_VREFIN_MON_SEL;

        pd->ea_ctrl |= PDSS_EA_CTRL_EN_CC_CMPN;

        /*
         * Set the GM amplifier source current limit to maximum. This setting is
         * done based on feedback from the design team. Lower values can result
         * in saturation for higher voltage levels.
         */
        PPDSS_TRIMS_REGS_T trimRegs = (PPDSS_TRIMS_REGS_T)context->trimsBase;

        trimRegs->trim_ea1_1 = PDSS_TRIM_EA1_1_EA_IPD_CC_TRIM_MASK;

        /* Disable the shunt start opamp. */
        pd->ea_ctrl |= PDSS_EA_CTRL_SHNT_ST_OPAMP_ENB;

        /*
         * Silicon workaround. There seems to be a floating node for SR comparator
         * voltage reference and needs to be always turned ON and set AMP2 gain to
         * 150. These numbers are provided by the design team.
         */

        pd->lscsa_0_ctrl |= (((uint32_t)12u << PDSS_LSCSA_0_CTRL_AV_SR_ON_POS) |
                        PDSS_LSCSA_0_CTRL_AV_SEL_SR_ON);

        if (Cy_USBPD_Get_Silicon_Rev(context) != 0u)
        {
        /*
         * The LSCSA block has better accuracy when the chopper logic is enabled.
         * But this can be done only for *A revision of silicon or above.
         * Also load the discharge drive strength values.
         */
        pd->lscsa_0_ctrl |= (PDSS_LSCSA_0_CTRL_OS1_EN | PDSS_LSCSA_0_CTRL_OS2_EN);
        }

        pd->refgen_0_ctrl |= (PDSS_REFGEN_0_CTRL_REFGEN_CLK_SEL);

        if (Cy_USBPD_Get_Silicon_Rev(context) != 0u)
        {
#if VBUS_SLOW_DISCHARGE_EN
                /*
                 * If slow discharge is enabled, we will load the minimum
                 * drive strength for both the dischg_shv_ctrl instances.
                 * VBUS_C and VBUS_IN has dependency on CCG_FLIPPED_FET_CTRL value.
                 *
                 * Note: Slow Discharge control feature is only applicable for *A
                 * revision of silicon or above.
                 */
#if !PMG1_FLIPPED_FET_CTRL
                pd->dischg_shv_ctrl[0] = ((pd->dischg_shv_ctrl[0] & ~PDSS_DISCHG_SHV_CTRL_DISCHG_DS_MASK) |
                        (VBUS_C_DISCHG_DS_MIN << PDSS_DISCHG_SHV_CTRL_DISCHG_DS_POS));
                pd->dischg_shv_ctrl[1] = ((pd->dischg_shv_ctrl[1] & ~PDSS_DISCHG_SHV_CTRL_DISCHG_DS_MASK) |
                        (VBUS_IN_DISCHG_DS_MIN << PDSS_DISCHG_SHV_CTRL_DISCHG_DS_POS));
#else /* !PMG1_FLIPPED_FET_CTRLL */
                pd_temp->dischg_shv_ctrl[0] = ((pd_temp->dischg_shv_ctrl[0] & ~PDSS_DISCHG_SHV_CTRL_DISCHG_DS_MASK) |
                        (VBUS_IN_DISCHG_DS_MIN << PDSS_DISCHG_SHV_CTRL_DISCHG_DS_POS));
                pd_temp->dischg_shv_ctrl[1] = ((pd_temp->dischg_shv_ctrl[1] & ~PDSS_DISCHG_SHV_CTRL_DISCHG_DS_MASK) |
                        (VBUS_C_DISCHG_DS_MIN << PDSS_DISCHG_SHV_CTRL_DISCHG_DS_POS));
#endif /* PMG1_FLIPPED_FET_CTRL */

#else /* VBUS_SLOW_DISCHARGE_EN */
                pd->dischg_shv_ctrl[0] = ((pd->dischg_shv_ctrl[0] & ~PDSS_DISCHG_SHV_CTRL_DISCHG_DS_MASK) |
                        (VBUS_C_DISCHG_DS << PDSS_DISCHG_SHV_CTRL_DISCHG_DS_POS));
                pd->dischg_shv_ctrl[1] = ((pd->dischg_shv_ctrl[1] & ~PDSS_DISCHG_SHV_CTRL_DISCHG_DS_MASK) |
                        (VBUS_IN_DISCHG_DS << PDSS_DISCHG_SHV_CTRL_DISCHG_DS_POS));
#endif /* VBUS_SLOW_DISCHARGE_EN */
        }
        else
        {
            pd->dischg_shv_ctrl[0] = ((pd->dischg_shv_ctrl[0] & ~PDSS_DISCHG_SHV_CTRL_DISCHG_DS_MASK) |
                                        (PMG1S0_DISCHG_DS_VBUS_C_00 << PDSS_DISCHG_SHV_CTRL_DISCHG_DS_POS));
            pd->dischg_shv_ctrl[1] = ((pd->dischg_shv_ctrl[1] & ~PDSS_DISCHG_SHV_CTRL_DISCHG_DS_MASK) |
                                        (PMG1S0_DISCHG_DS_VBUS_IN_00 << PDSS_DISCHG_SHV_CTRL_DISCHG_DS_POS));
        }
#if (PMG1_FLIPPED_FET_CTRL)
        /*
        * In this case (applications like Power bank), VBUS_IN node of silicon is connected
        * to TYPE-C VBUS. Therefore, select VBUS_IN resistor divider to monitor TYPE-C VBUS
        */
        pd->amux_nhv_ctrl |= ((1U << AMUX_ADC_PMG1S0_VBUS_IN_8P_EN_POS) |
                                (1U << AMUX_ADC_PMG1S0_VBUS_IN_20P_EN_POS));
#endif /* (PMG1_FLIPPED_FET_CTRL) */

#endif /* defined(CY_DEVICE_CCG3PA) */

#if defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)
        /* Enable HF Clk as source for Fault protection filters. */
        pd->ctrl |= PDSS_CTRL_SEL_CLK_FILTER;

        /* Update Refgen setting */
        pd->refgen_0_ctrl &= ~PDSS_REFGEN_0_CTRL_REFGEN_PD;
        pd->refgen_0_ctrl  |= PDSS_REFGEN_0_CTRL_REFGEN_VREFIN_SEL |
                              PDSS_REFGEN_0_CTRL_REFGEN_VREFIN_MON_SEL;

#if defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)
            /* Configure trim values. */

            /* Configure 20vconn scp trims */
            CY_USBPD_REG_FIELD_UPDATE(pdtrims->trim_bb_20vconn_2, 
                PDSS_TRIM_BB_20VCONN_2_BB_20VCONN_SCP_TRIM, VCONN_SCP_TRIM_115_MA);

            /* Configure 40vreg Inrush trims */
            CY_USBPD_REG_FIELD_UPDATE(pdtrims->trim_bb_20vconn_3, 
                PDSS_TRIM_BB_20VCONN_3_BB_20VCONN_INRUSH, VCONN_INRUSH_TRIM_50_NA);

            /* Configure Trim values for CCLOOP and amplifier. */
            Cy_USBPD_CurrentTrimInit(context);
            CY_USBPD_REG_FIELD_UPDATE(pdtrims->trim_bb_20csa_2, 
                PDSS_TRIM_BB_20CSA_2_OS_EL, CSA_INPUT_OFFSET_NEG_6P1_MV);
            CY_USBPD_REG_FIELD_UPDATE(pdtrims->trim_bb_ea_1, 
                PDSS_TRIM_BB_EA_1_TRIM_GM_CV, GM_CV_1P4_MS);
            CY_USBPD_REG_FIELD_UPDATE(pdtrims->trim_bb_ea_2, 
                PDSS_TRIM_BB_EA_2_TRIM_GM_CC, GM_CC_0P2_MS);
            CY_USBPD_REG_FIELD_UPDATE(pd->bb_ea_1_ctrl, 
                PDSS_BB_EA_1_CTRL_TRIM_CC_FLAG, CC_FLAG_CUR_9P6_UA);
            CY_USBPD_REG_FIELD_UPDATE(pd->bb_ea_1_ctrl, 
                PDSS_BB_EA_1_CTRL_BB_EA_TRIM_PLOAD, EA_PLOAD_20_UA);
            CY_USBPD_REG_FIELD_UPDATE(pd->bb_ea_0_ctrl, 
                PDSS_BB_EA_0_CTRL_BB_EA_TRIM_GMBOOSTN_CC, GMBOOSTN_CC_NOBOOST);

#if CY_USE_CONFIG_TABLE
            if (pd_get_ptr_auto_cfg_tbl(context)->max_current > CY_USBPD_I_3A)
#else
            if (context->usbpdConfig->autoConfig->max_current > CY_USBPD_I_3A)
#endif
            {
                CY_USBPD_REG_FIELD_UPDATE(pd->bb_ea_1_ctrl, 
                    PDSS_BB_EA_1_CTRL_BB_EA_TRIM_BOOSTP_CC, GMBOOSTP_CC_3P5X);
            }
            else

            {
                CY_USBPD_REG_FIELD_UPDATE(pd->bb_ea_1_ctrl, 
                    PDSS_BB_EA_1_CTRL_BB_EA_TRIM_BOOSTP_CC, GMBOOSTP_CC_2X_WITH_OFFSET);
            }
            /* 
             * For *A silicon.
             */
#if defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_SERIES_WLC1)
            if (Cy_USBPD_Get_Silicon_Rev(context) != 0u)
#endif /* defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_SERIES_WLC1) */
            {
               /*
                * As register bits are re-purposed to enable independent control of 
                * offset with GM, following settings needs to be added to make it 
                * equivalent to A0 silicon.
                */
                CY_USBPD_REG_FIELD_UPDATE(pd->bb_ea_0_ctrl, PDSS_BB_EA_0_CTRL_BB_EA_TRIM_CVAMP_IBIAS, (uint32_t)1u);
                CY_USBPD_REG_FIELD_UPDATE(pd->bb_ea_0_ctrl, PDSS_BB_EA_0_CTRL_BB_EA_TRIM_CCAMP_IBIAS, (uint32_t)1u);
                CY_USBPD_REG_FIELD_UPDATE(pd->bb_ea_2_ctrl, PDSS_BB_EA_2_CTRL_BB_EA_T_EA, 0x1505Cu);

                /* 
                 * Improvement to BB modes switch. 
                 * These trims are present only for *A. 
                 */

                CY_USBPD_REG_FIELD_UPDATE(pd->bb_pwm_1_ctrl, 
                    PDSS_BB_PWM_1_CTRL_BB_PWM_TR_VOUT_RESDIV_SEL_BB_1,
                    BB_PWM_TRIP_BB_1_LH_TRIM(port));
                CY_USBPD_REG_FIELD_UPDATE(pd->bb_pwm_0_ctrl, 
                    PDSS_BB_PWM_0_CTRL_BB_PWM_TR_VOUT_RESDIV_SEL_BB_2,
                    BB_PWM_TRIP_BB_2_HL_TRIM(port));
                CY_USBPD_REG_FIELD_UPDATE(pd->bb_pwm_0_ctrl, 
                    PDSS_BB_PWM_0_CTRL_BB_PWM_TR_VOUT_RESDIV_SEL_BOOST_1,
                    BB_PWM_TRIP_BOOST_1_HL_TRIM(port));
                CY_USBPD_REG_FIELD_UPDATE(pd->bb_pwm_0_ctrl, 
                    PDSS_BB_PWM_0_CTRL_BB_PWM_TR_VOUT_RESDIV_SEL_BOOST_2,
                    BB_PWM_TRIP_BOOST_2_LH_TRIM(port));
            }
#if defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_SERIES_WLC1)
            else
            {
                /*
                 * The TRIM data for DAC needs to be loaded only for ** silicon. For *A silicon,
                 * the TRIM must be loaded with 0x20. This is being ensured via automatic TRIM load
                 * from ROM code.
                 */
                pdtrims->trim_bb_ea_0 = EA_IREF_GAIN_NDAC(port);
            }
#endif /* defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_SERIES_WLC1) */

            /* Configure VBST comparator trims.
             * new trim(for vtrip) = trim(from sflash)+(vtrip-1000mV)/40mV
             * Sort trimming is done for 4V BST, set it for 4.5V explicitly.
             */
            /* QAC suppression 2985: REG_FEILD_UPDATE is a common functional macro that is used to 
             * modify a register field without affecting any other bits of the register. When the field
             * starts from bit position 0, the left shift operation is redundant. Yet this operation is 
             * retained to keep it generic and compatible for bitfields starting from other bit positions. */
            CY_USBPD_REG_FIELD_UPDATE(pdtrims->trim_bb_gdrvo_0, /* PRQA S 2985 */
                PDSS_TRIM_BB_GDRVO_0_TRIM_VBST_COMP, 
                ((VBST_GDRVO_TRIM(port) > VBST_GDRVI_TRIM_OFFSET_0P5_V) ? 
                ((uint32_t)VBST_GDRVO_TRIM(port) - VBST_GDRVI_TRIM_OFFSET_0P5_V) : (uint32_t)0u));
            /* QAC suppression 2985: REG_FEILD_UPDATE is a common functional macro that is used to 
             * modify a register field without affecting any other bits of the register. When the field
             * starts from bit position 0, the left shift operation is redundant. Yet this operation is 
             * retained to keep it generic and compatible for bitfields starting from other bit positions. */
            CY_USBPD_REG_FIELD_UPDATE(pdtrims->trim_bb_gdrvi_0, /* PRQA S 2985 */
                PDSS_TRIM_BB_GDRVI_0_TRIM_VBST_COMP, 
                ((VBST_GDRVI_TRIM(port) > VBST_GDRVI_TRIM_OFFSET_0P5_V) ? 
                ((uint32_t)VBST_GDRVI_TRIM(port) - VBST_GDRVI_TRIM_OFFSET_0P5_V) : (uint32_t)0u));

            /* Keep a backup of LSZCD and HSRCP trim, which need to be changed dynamically. */
            context->trimsConfig.lszcd_trim = CY_USBPD_REG_FIELD_GET(pdtrims->trim_bb_gdrvi_1,
                PDSS_TRIM_BB_GDRVI_1_TRIM_LSZCD);
            context->trimsConfig.hsrcp_trim = CY_USBPD_REG_FIELD_GET(pdtrims->trim_bb_gdrvo_1,
                PDSS_TRIM_BB_GDRVO_1_TRIM_HSRCP);

            if (port == TYPEC_PORT_0_IDX)
            {
                /* 
                 * 40VREG configuration.
                 * 40VREG and related faults are common for device, 
                 * hence configure only once.
                 */

                /* Configure 40VREG for active 5V. */
                CY_USBPD_REG_FIELD_UPDATE(pd->refgen_4_ctrl, 
                    PDSS_REFGEN_4_CTRL_SEL12, BB_40VREG_5V_VREF_750_MV);

#if defined(CY_DEVICE_CCG7S)
#if (PMG1B1_USB_CHARGER == 0)
                /* Don't disable the secondary regulator for battery charging*/
                pd->bb_40vregld_ctrl &= ~(PDSS_BB_40VREGLD_CTRL_BB_40VREG_VBUSIN_REG_EN);
#endif /* (PMG1B1_USB_CHARGER == 0) */
#endif /* defined(CY_DEVICE_CCG7S) */

                pd->bb_40vreg_ctrl = ((pd->bb_40vreg_ctrl &
                    ~(PDSS_BB_40VREG_CTRL_BB_40VREG_T_VREG_3P3_MASK |
                        PDSS_BB_40VREG_CTRL_BB_40VREG_INRSH_DET_SEL_MASK |
                        PDSS_BB_40VREG_CTRL_BB_40VREG_T_INRSH_CLAMP_ON)) |
#if (PDL_VREG_BROWN_OUT_DET_ENABLE && (PMG1B1_USB_CHARGER == 0))
                        PDSS_BB_40VREG_CTRL_BB_40VREG_EN_VDDD_DET_COMP |
#endif /* PDL_VREG_BROWN_OUT_DET_ENABLE && PMG1B1_USB_CHARGER == 0 */
#if ((!PDL_VREG_INRUSH_DET_ENABLE) && (!PDL_VREG_BROWN_OUT_DET_ENABLE))
                        PDSS_BB_40VREG_CTRL_BB_40VREG_T_DIS_INRSH_CLAMP |
#endif /* ((!PDL_VREG_INRUSH_DET_ENABLE) && (!PDL_VREG_BROWN_OUT_DET_ENABLE)) */
                        ((uint32_t)BB_40VREG_DET_LIM_500_MA << 
                            PDSS_BB_40VREG_CTRL_BB_40VREG_INRSH_DET_SEL_POS) |
                        PDSS_BB_40VREG_CTRL_BB_40VREG_ISO_N |
                        PDSS_BB_40VREG_CTRL_BB_40VREG_VREG_ACT_EN);

                /* Wait for VDDD to settle for 5V and enable Brown Out Detect */
                Cy_SysLib_Delay(1);

#if (PDL_VREG_BROWN_OUT_DET_ENABLE && (PMG1B1_USB_CHARGER == 0))
                Cy_USBPD_Fault_BrownOutDetEn(context);
#endif /* PDL_VREG_BROWN_OUT_DET_ENABLE && PMG1B1_USB_CHARGER == 0 */

#if (PDL_VREG_INRUSH_DET_ENABLE && (PMG1B1_USB_CHARGER == 0))
                Cy_USBPD_Fault_VregInrushDetEn(context);
#endif /* PDL_VREG_INRUSH_DET_ENABLE && PMG1B1_USB_CHARGER == 0 */
            }

            /*
             * NOTE: NTC and the DDFT lines are same and so have to 
             * disable temperature throttling to enable DDFT.
             */
#if ((!CCG_TEMP_BASED_VOLTAGE_THROTTLING) && (ADFT_DDFT_EN))
            adft_ddft_enable(context);
#endif /* ((!CCG_TEMP_BASED_VOLTAGE_THROTTLING) && (ADFT_DDFT_EN)) */
#endif /* ADFT_DDFT_EN */
#if VBUS_SLOW_DISCHARGE_EN
        /*
         * If slow discharge is enabled, we will load the minimum
         * drive strength for both the dischg_shv_ctrl instances.
         * VBUS_C and VBUS_IN has dependency on CCG_FLIPPED_FET_CTRL value.
         *
         * Note: Slow Discharge control feature is only applicable for *A
         * revision of silicon or above.
         */
#if !PMG1_FLIPPED_FET_CTRL
        pd->dischg_shv_ctrl[0] = ((pd->dischg_shv_ctrl[0] & ~PDSS_DISCHG_SHV_CTRL_DISCHG_DS_MASK) |
                (VBUS_C_DISCHG_DS_MIN << PDSS_DISCHG_SHV_CTRL_DISCHG_DS_POS));
        pd->dischg_shv_ctrl[1] = ((pd->dischg_shv_ctrl[1] & ~PDSS_DISCHG_SHV_CTRL_DISCHG_DS_MASK) |
                (VBUS_IN_DISCHG_DS_MIN << PDSS_DISCHG_SHV_CTRL_DISCHG_DS_POS));
#else /* !PMG1_FLIPPED_FET_CTRL */
        pd_temp->dischg_shv_ctrl[0] = ((pd_temp->dischg_shv_ctrl[0] & ~PDSS_DISCHG_SHV_CTRL_DISCHG_DS_MASK) |
                (VBUS_IN_DISCHG_DS_MIN << PDSS_DISCHG_SHV_CTRL_DISCHG_DS_POS));
        pd_temp->dischg_shv_ctrl[1] = ((pd_temp->dischg_shv_ctrl[1] & ~PDSS_DISCHG_SHV_CTRL_DISCHG_DS_MASK) |
                (VBUS_C_DISCHG_DS_MIN << PDSS_DISCHG_SHV_CTRL_DISCHG_DS_POS));
#endif /* !PMG1_FLIPPED_FET_CTRL */

#else /* VBUS_SLOW_DISCHARGE_EN */
        pd->dischg_shv_ctrl[0] = ((pd->dischg_shv_ctrl[0] & ~PDSS_DISCHG_SHV_CTRL_DISCHG_DS_MASK) |
                (VBUS_C_DISCHG_DS << PDSS_DISCHG_SHV_CTRL_DISCHG_DS_POS));
        pd->dischg_shv_ctrl[1] = ((pd->dischg_shv_ctrl[1] & ~PDSS_DISCHG_SHV_CTRL_DISCHG_DS_MASK) |
                (VBUS_IN_DISCHG_DS << PDSS_DISCHG_SHV_CTRL_DISCHG_DS_POS));
#endif /* VBUS_SLOW_DISCHARGE_EN */

        CY_USBPD_REG_FIELD_UPDATE(pd->dischg_shv_1_ctrl[0], PDSS_DISCHG_SHV_1_CTRL_TIMER_VALUE, (uint32_t)0x10u);
        CY_USBPD_REG_FIELD_UPDATE(pd->dischg_shv_1_ctrl[1], PDSS_DISCHG_SHV_1_CTRL_TIMER_VALUE, (uint32_t)0x10u);
        /* Select VOUT_MON and VOUT_CBL default gain */
        pd->csa_scp_1_ctrl = (pd->csa_scp_1_ctrl &
                ~(CSA_VOUT_MON_CBL_GAIN_OPTIONS_MASK << PDSS_CSA_SCP_1_CTRL_T_CSA_SCP_POS)) |
                 (CSA_VOUT_MON_CBL_GAIN_OPTIONS_40_150 << PDSS_CSA_SCP_1_CTRL_T_CSA_SCP_POS);

        /* Configure SCP output through latch */
        pd->csa_scp_1_ctrl |= ((1u << 6u) << PDSS_CSA_SCP_1_CTRL_T_CSA_SCP_POS);
#endif /* defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1) */

#if ((PSVP_FPGA_ENABLE))
#if (!defined(CY_DEVICE_CCG6DF_CFP))
            /*
             * We need to wait for CCG3PA to be up. Then only we can read the TRIM data.
             * Since there is nothing to be done until the AFE board is up, wait for a
             * success response.
             */
            for (;;)
            {
                if (ctrl_inf_get_idac_trims() == CY_USBPD_STAT_SUCCESS)
                {
                    break;
                }
                Cy_SysLib_Delay(100);
            }
#endif /* (!defined(CY_DEVICE_CCG6DF_CFP)) */
#endif /* (PSVP_FPGA_ENABLE) */

#if (PDL_VBTR_ENABLE)
        context->vbtrIdle = true;
#if VBTR_MULTI_SLOPE_ENABLE
        context->vbtrSrcPending = false;
        context->vbtrSnkPending = false;
#endif  /* VBTR_MULTI_SLOPE_ENABLE */
#endif /* PDL_VBTR_ENABLE */

#if (PDL_IBTR_ENABLE)
        context->ibtrIdle = true;
#endif /* PDL_IBTR_ENABLE */

        /* Initialize ADCs. */
        status = Cy_USBPD_Adc_Init (context, CY_USBPD_ADC_ID_0);

#if (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3))
        /* PMG1S0 and PMG1S2 have two ADCs per PD block. */
        status = Cy_USBPD_Adc_Init (context, CY_USBPD_ADC_ID_1);

#elif (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
        if(context->port == 0u)
        {
            status = Cy_USBPD_Adc_Init (context, CY_USBPD_ADC_ID_1);
            /* JIRA: CCGX_PA-598 - ADC 1 to be using VDDD reference. */
            (void)Cy_USBPD_Adc_SelectVref(context, CY_USBPD_ADC_ID_1, CY_USBPD_ADC_VREF_VDDD);
        }
#endif /* (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3)) */

#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1) || defined(CY_DEVICE_CCG6DF_CFP))
#if PDL_CC_OVP_ENABLE
        Cy_USBPD_CcOvpControl(context, true);
#endif /* PDL_CC_OVP_ENABLE */
#endif /* (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1) || defined(CY_DEVICE_CCG6DF_CFP)) */

        (void)status;
        /* Init the VBUS regulator */
        Cy_USBPD_VBus_Regulator_Init(context);

        return CY_USBPD_STAT_SUCCESS;
    }
    else
    {
        return CY_USBPD_STAT_BAD_PARAM;
    }
}
/*******************************************************************************
* Function Name: Cy_USBPD_VBus_Regulator_Init
****************************************************************************//**
* 
* Does init of VBus Regulator.
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \return
* None
*
*******************************************************************************/

void Cy_USBPD_VBus_Regulator_Init(cy_stc_usbpd_context_t *context)
{
#if (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP))
    PPDSS_REGS_T pd = context->base;
    static PPDSS_REGS_T pd0 = NULL;

    if (context->port == TYPEC_PORT_0_IDX)
    {
        pd0 = context->base;
    }
    /* when all three power supplies are present then CCG takes the below priority.
     * 1. VSYS
     * 2. Port 0 VBUS
     * 3. Port 1 VBUS
     */

#if defined(CY_DEVICE_CCG6DF_CFP)
        if ((pd0->intr7_status & (PDSS_INTR7_STATUS_FILT_8)) == 0U)
#else
        if ((pd0->intr7_status & (CLK_LF_FILT_NUM << PDSS_INTR7_STATUS_FILT_8_POS)) == 0U)
#endif /* defined(CY_DEVICE_CCG6DF_CFP) */
        {
            /* VSYS is not present. Check if port 0 VBUS is present. */
            if (Cy_USBPD_Adc_MeasureVbus(context, CY_USBPD_ADC_ID_0,
                    CY_USBPD_ADC_INPUT_AMUX_B) >= VBUS_OPERATING_MINIMUM)
            {
                /* Check if CCG is dual port. */
#if (NO_OF_TYPEC_PORTS > 1u)
                if (context->port == TYPEC_PORT_0_IDX)
                {
                    /* Enable VBUS regulator. */
#if defined(CY_DEVICE_CCG6DF_CFP)
                    pd->vreg_vsys_ctrl |= PDSS_VREG_VSYS_CTRL_VREG20_EN;
#else
                    pd->vreg_vsys_ctrl |= PDSS_VREG_VSYS_CTRL_VREG20_1_EN;
#endif /* defined(CY_DEVICE_CCG6DF_CFP) */
                }
                else
                {
                    /* Check if other port's regulator enabled. */
#if defined(CY_DEVICE_CCG6DF_CFP)
                    if (0u == (pd0->vreg_vsys_ctrl & PDSS_VREG_VSYS_CTRL_VREG20_EN))
#else
                    if (0u == (pd0->vreg_vsys_ctrl & PDSS_VREG_VSYS_CTRL_VREG20_1_EN))
#endif /* defined(CY_DEVICE_CCG6DF_CFP) */
                    {
                        /* Other port's regulator is not enabled. enable VBUS regulator. */
#if defined(CY_DEVICE_CCG6DF_CFP)
                        pd->vreg_vsys_ctrl |= PDSS_VREG_VSYS_CTRL_VREG20_EN;
#else
                        pd->vreg_vsys_ctrl |= PDSS_VREG_VSYS_CTRL_VREG20_1_EN;
#endif /* defined(CY_DEVICE_CCG6DF_CFP) */
                    }
                }
#else
                /* Single port, hence enable the VBUS regulator. */
#if defined(CY_DEVICE_CCG6DF_CFP)
                pd->vreg_vsys_ctrl |= PDSS_VREG_VSYS_CTRL_VREG20_EN;
#else
                pd->vreg_vsys_ctrl |= PDSS_VREG_VSYS_CTRL_VREG20_1_EN;
#endif /* defined(CY_DEVICE_CCG6DF_CFP) */
#endif
            }
        }
#else
    CY_UNUSED_PARAMETER(context);
#endif /* (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP)) */

}
/*******************************************************************************
* Function Name: Cy_USBPD_PrepareDeepSleep
****************************************************************************//**
* 
* This function configures the PD block for deepsleep entry.
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \param voltage
*  VBUS comparator voltage for detach
*
* \param percentage
* Percentage threshold for VBUS detach comparator
* 
* \return bool
* Returns true if deepsleep is possible and configured or if the block was not
* enabled, otherwise false.
*
*******************************************************************************/
bool Cy_USBPD_PrepareDeepSleep (
        cy_stc_usbpd_context_t *context,
        uint16_t voltage,
        int8_t percentage)
{
#if SYS_DEEPSLEEP_ENABLE
    cy_stc_pd_dpm_config_t *dpmConfig = NULL;
    PPDSS_REGS_T pd = NULL;
#if (!(CY_PD_SOURCE_ONLY))
    uint8_t level = 0;
#endif /* (!(CY_PD_SOURCE_ONLY)) */
#if (!CY_PD_SINK_ONLY)
    uint32_t volatile status = 0;
#endif /* (!CY_PD_SINK_ONLY) */
#if defined(CY_IP_MXUSBPD)
    uint32_t regVal = 0;
#endif /* defined(CY_IP_MXUSBPD) */

    if (context == NULL)
    {
        return false;
    }

    dpmConfig = context->dpmGetConfig();
    pd = context->base;

    if (!(dpmConfig->dpmEnabled))
    {
        return true;
    }

    if (dpmConfig->connect == true)
    {
        /* Set LA comparator for wakeup. */
        pd->intr1 = PDSS_INTR1_VCMP_LA_CHANGED;
        pd->intr1_mask |= PDSS_INTR1_VCMP_LA_CHANGED;

#if (!CY_PD_SINK_ONLY)
        if (dpmConfig->curPortRole == CY_PD_PRT_ROLE_SOURCE)
        {
            if ((dpmConfig->attachedDev == CY_PD_DEV_RA_RA) || (dpmConfig->attachedDev == CY_PD_DEV_DBG_ACC))
            {
                Cy_USBPD_TypeC_PhyDetectCCRise (context, true);
            }
            else
            {
#if defined(CY_IP_MXUSBPD)
                regVal = pd->intr1_cfg_vcmp_up_down_ls;
                regVal &= ~(PDSS_INTR1_CFG_VCMP_UP_DOWN_LS_VCMP_UP_CFG_MASK |
                        PDSS_INTR1_CFG_VCMP_UP_DOWN_LS_VCMP_UP_FILT_EN);
                regVal |= (CY_USBPD_ADC_INT_RISING) << PDSS_INTR1_CFG_VCMP_UP_DOWN_LS_VCMP_UP_CFG_POS;
                pd->intr1_cfg_vcmp_up_down_ls = regVal;
#else
                pd->intr_1_cfg &= ~PDSS_INTR_1_CFG_VCMP_UP_CFG_MASK;
                pd->intr_1_cfg |= (CY_USBPD_ADC_INT_RISING) << PDSS_INTR_1_CFG_VCMP_UP_CFG_POS;
#endif /* CY_IP */

                pd->intr1 = PDSS_INTR1_VCMP_UP_CHANGED;
                pd->intr1_mask |= PDSS_INTR1_VCMP_UP_CHANGED;

                /* If the comparator has already triggered, set the interrupt and return. */
                if (
#if defined(CY_IP_MXUSBPD)
                        (pd->intr1_status & PDSS_INTR1_STATUS_VCMP_UP_STATUS)
#else
                        (pd->status & PDSS_STATUS_VCMP_UP_STATUS)
#endif /* CY_IP */
                   )
                {
                    pd->intr1_set |= PDSS_INTR1_VCMP_UP_CHANGED;
                }
            }
        }
        else
#endif /* (!CY_PD_SINK_ONLY) */
        {
#if (!(CY_PD_SOURCE_ONLY))
#if defined(CY_IP_MXUSBPD)
            regVal = pd->intr1_cfg_vcmp_up_down_ls;
            regVal &= ~ (PDSS_INTR1_CFG_VCMP_UP_DOWN_LS_VCMP_UP_FILT_EN |
                    PDSS_INTR1_CFG_VCMP_UP_DOWN_LS_VCMP_DN_FILT_EN);
            /* Set up/down for both edges */
            regVal |=  (PDSS_INTR1_CFG_VCMP_UP_DOWN_LS_VCMP_UP_CFG_MASK |
                    PDSS_INTR1_CFG_VCMP_UP_DOWN_LS_VCMP_DN_CFG_MASK);
            pd->intr1_cfg_vcmp_up_down_ls = regVal;
#else
            /* Set the Up comparator on Active CC line to signal a detach based on the Rp level. */
            pd->intr_1_cfg &= ~ (PDSS_INTR_1_CFG_VCMP_UP_CFG_MASK | PDSS_INTR_1_CFG_VCMP_DN_CFG_MASK);
            pd->intr_1_cfg |= (CY_USBPD_ADC_INT_BOTH << PDSS_INTR_1_CFG_VCMP_UP_CFG_POS) |
                (CY_USBPD_ADC_INT_BOTH << PDSS_INTR_1_CFG_VCMP_DN_CFG_POS);
#endif /* CY_IP */

            pd->intr1 = PDSS_INTR1_VCMP_UP_CHANGED | PDSS_INTR1_VCMP_DN_CHANGED;
            pd->intr1_mask |= PDSS_INTR1_VCMP_UP_CHANGED | PDSS_INTR1_VCMP_DN_CHANGED;

            /* Check old cc status if different then */
            if(dpmConfig->ccOldStatus.state != Cy_USBPD_TypeC_GetCCStatus(context).state)
            {
                /* Fire anyone interrupt to wakeup */
                pd->intr1_set |= PDSS_INTR1_VCMP_UP_CHANGED;
                return true;
            }

#if (!defined(CY_DEVICE_SERIES_WLC1))
            /*
             * WLC1 VBUS routing is custom and common detach cannot be used.
             * Instead of this, WLC1 uses VIN_UVP to detect detach in power saving mode.
             * Also, WLC1 is a bus powered device, hence VBUS removal results in board reset.
             */
            (void)level;

#if (!(CY_PD_USE_ADC_IN_DS))            
#if CY_PD_REV3_ENABLE
            if (dpmConfig->frRxEnLive == false)
#endif /* CY_PD_REV3_ENABLE */
            {
                /* Set the VBus detach comparator as per current detach threshold. */
                level = Cy_USBPD_Adc_GetVbusLevel (context, 
                        context->vbusDetachAdcId,
                        voltage,
                        percentage
                        );

                /*
                 * The following call will also check if the comparator has
                 * triggered and set the interrupt.
                 */
                Cy_USBPD_Adc_CompCtrl (context, 
                        context->vbusDetachAdcId, 
                        context->vbusDetachAdcInp, 
                        level,
                        CY_USBPD_ADC_INT_RISING,
                        Cy_USBPD_Phy_VbusDetachCbk);
            }
#endif /*(!(CY_PD_USE_ADC_IN_DS)) */
#endif /* (!defined(CY_DEVICE_SERIES_WLC1)) */

            CY_UNUSED_PARAMETER(level);

#endif /* (!(CY_PD_SOURCE_ONLY)) */
        }
    }
    else
    {
#if ((CY_PD_HW_DRP_TOGGLE_ENABLE) || (!CY_PD_SINK_ONLY))
        uint8_t cc1_edge = CY_USBPD_ADC_INT_RISING;
        uint8_t cc2_edge = CY_USBPD_ADC_INT_RISING;
#endif /* ((CY_PD_HW_DRP_TOGGLE_ENABLE) || (!CY_PD_SINK_ONLY)) */

#if CY_PD_HW_DRP_TOGGLE_ENABLE
        /* Don't do anything if auto toggle is already running. */
        if (context->autoToggleAct)
        {
            return true;
        }

        /* If connection interrupt just occurred, set an interrupt to cause the device to wake immediately. */
        if (context->typecStartPending)
        {
            pd->intr1_mask |= PDSS_INTR1_MASK_DRP_ATTACHED_DETECTED_MASK;
            pd->intr1_set |= PDSS_INTR1_DRP_ATTACHED_DETECTED;
            return true;
        }
#endif /* CY_PD_HW_DRP_TOGGLE_ENABLE */

        /* Connect UP comparator to CC1 and down comparator to CC2 */
        pd->cc_ctrl_0 = ((pd->cc_ctrl_0 & ~PDSS_CC_CTRL_0_CMP_UP_CC1V2) |
                PDSS_CC_CTRL_0_CMP_DN_CC1V2);

#if (!CY_PD_SINK_ONLY)
        if (dpmConfig->curPortRole == CY_PD_PRT_ROLE_SOURCE)
        {
#if defined(CY_IP_MXUSBPD)
            /*
             * If Ra is present on only 1 CC line, then set the Up comparator
             * on the Ra line for a rising edge as per the Rp level. Check if
             * the comparator has already triggered, then set the interrupt and
             * return.
             *
             * Set the Dn comparator on the other line for a falling edge as
             * per the Rp level. Check if the comparator has already triggered,
             * then set the interrupt and return.
             *
             * Otherwise,
             *
             * Set the Up comparator on CC1 for a falling edge as per the Rp
             * level. Set the Dn comparator on CC2 for a falling edge as per
             * the Rp level. If the comparators have already triggered, then
             * set the respective interrupt and return.
             */

            /* Set threshold to Ra level to check if Ra is present on single CC line. */
            pd->cc_ctrl_0 &= ~(PDSS_CC_CTRL_0_CMP_UP_VSEL_MASK | PDSS_CC_CTRL_0_CMP_DN_VSEL_MASK);
            pd->cc_ctrl_0 |= ((thresholds[dpmConfig->srcCurLevelLive][0]) << PDSS_CC_CTRL_0_CMP_UP_VSEL_POS) |
                ((thresholds[dpmConfig->srcCurLevelLive][0]) << PDSS_CC_CTRL_0_CMP_DN_VSEL_POS);
            Cy_SysLib_DelayUs(10);

            status = pd->intr1_status;

            /* Apply resistor based Rp and remove current source Rp */
            pd->cc_ctrl_1 |= PDSS_CC_CTRL_1_DS_ATTACH_DET_EN;
            pd->cc_ctrl_0 &= ~(PDSS_CC_CTRL_0_RP_CC1_EN | PDSS_CC_CTRL_0_RP_CC2_EN);

            if ((status & (PDSS_INTR1_STATUS_VCMP_UP_STATUS | PDSS_INTR1_STATUS_VCMP_DN_STATUS))
                    == PDSS_INTR1_STATUS_VCMP_DN_STATUS)
            {
                cc1_edge = CY_USBPD_ADC_INT_FALLING;
            }
            else if ((status & (PDSS_INTR1_STATUS_VCMP_UP_STATUS | PDSS_INTR1_STATUS_VCMP_DN_STATUS))
                    == PDSS_INTR1_STATUS_VCMP_UP_STATUS)
            {
                cc2_edge = CY_USBPD_ADC_INT_FALLING;
            }
            Cy_SysLib_DelayUs(10);

            /* Configure and enable the CC1/CC2 detect filter. */
            pd->intr1_cfg_cc1_cc2_ls &= ~ (PDSS_INTR1_CFG_CC1_CC2_LS_CC1_CFG_MASK |
                    PDSS_INTR1_CFG_CC1_CC2_LS_CC2_CFG_MASK |
                    PDSS_INTR1_CFG_CC1_CC2_LS_CC1_FILT_EN |
                    PDSS_INTR1_CFG_CC1_CC2_LS_CC2_FILT_EN |
                    PDSS_INTR1_CFG_CC1_CC2_LS_CC1_FILT_BYPASS |
                    PDSS_INTR1_CFG_CC1_CC2_LS_CC2_FILT_BYPASS);
            pd->intr1_cfg_cc1_cc2_ls |= (((cc1_edge) << PDSS_INTR1_CFG_CC1_CC2_LS_CC1_CFG_POS) |
                        ((cc2_edge) << PDSS_INTR1_CFG_CC1_CC2_LS_CC2_CFG_POS) |
                    (PDSS_INTR1_CFG_CC1_CC2_LS_CC1_FILT_EN | PDSS_INTR1_CFG_CC1_CC2_LS_CC2_FILT_EN));

            pd->intr1 = (PDSS_INTR1_VCMP_UP_CHANGED |
                    PDSS_INTR1_VCMP_DN_CHANGED |
                    PDSS_INTR1_VCMP_LA_CHANGED |
                    PDSS_INTR1_CC1_CHANGED |
                    PDSS_INTR1_CC2_CHANGED);
            pd->intr1_mask |= (PDSS_INTR1_CC1_CHANGED | PDSS_INTR1_CC2_CHANGED);
            status = pd->intr1_status;

            /* If the comparators have  already triggered, then set the interrupts and return. */
            if(((cc1_edge == CY_USBPD_ADC_INT_RISING) && ((status & PDSS_INTR1_STATUS_CC1_STATUS) != 0U)) ||
                    ((cc1_edge == CY_USBPD_ADC_INT_FALLING) && ((status & PDSS_INTR1_STATUS_CC1_STATUS) == 0U)) ||
                    ((cc2_edge == CY_USBPD_ADC_INT_RISING) && ((status & PDSS_INTR1_STATUS_CC2_STATUS) != 0U)) ||
                    ((cc2_edge == CY_USBPD_ADC_INT_FALLING) && ((status & PDSS_INTR1_STATUS_CC2_STATUS) == 0U)))
            {
                /* Fire anyone to wakeup*/
                pd->intr1_set |= PDSS_INTR1_CC1_CHANGED;
                return true;
            }
#else
            /*
             * If Ra is present on only 1 CC line, then set the Up comparator
             * on the Ra line for a rising edge as per the Rp level. Check if
             * the comparator has already triggered, then set the interrupt and
             * return.
             *
             * Set the Dn comparator on the other line for a falling edge as
             * per the Rp level. Check if the comparator has already triggered,
             * then set the interrupt and return.
             *
             * Otherwise,
             *
             * Set the Up comparator on CC1 for a falling edge as per the Rp
             * level. Set the Dn comparator on CC2 for a falling edge as per
             * the Rp level. If the comparators have already triggered, then
             * set the respective interrupt and return.
             */

            /* Connect  UP comparator to CC1 */
            pd->cc_ctrl_0 &= ~PDSS_CC_CTRL_0_CMP_UP_CC1V2;

            /* Connect Down comparator to CC2 */
            pd->cc_ctrl_0 |=  PDSS_CC_CTRL_0_CMP_DN_CC1V2;

            /* Set threshold to Ra level to check if Ra is present on single CC line. */
            pd->cc_ctrl_0 &= ~(PDSS_CC_CTRL_0_CMP_UP_VSEL_MASK | PDSS_CC_CTRL_0_CMP_DN_VSEL_MASK);
            pd->cc_ctrl_0 |= ((thresholds[dpmConfig->srcCurLevelLive][0]) << PDSS_CC_CTRL_0_CMP_UP_VSEL_POS) |
                ((thresholds[dpmConfig->srcCurLevelLive][0]) << PDSS_CC_CTRL_0_CMP_DN_VSEL_POS);
            Cy_SysLib_DelayUs(10);

            status = pd->status;

            cc1_edge = CY_USBPD_ADC_INT_DISABLED;
            cc2_edge = CY_USBPD_ADC_INT_DISABLED;

            /* Apply resistor based Rp and remove current source Rp */
            pd->cc_ctrl_1 |= PDSS_CC_CTRL_1_DS_ATTACH_DET_EN;
            pd->cc_ctrl_0 &= ~(PDSS_CC_CTRL_0_RP_CC1_EN | PDSS_CC_CTRL_0_RP_CC2_EN);
            pd->intr_1_cfg &= ~(PDSS_INTR_1_CFG_CC1_CFG_MASK | PDSS_INTR_1_CFG_CC2_CFG_MASK |
                    PDSS_INTR_1_CFG_VCMP_UP_CFG_MASK | PDSS_INTR_1_CFG_VCMP_DN_CFG_MASK);

            pd->cc_ctrl_0 &= ~(PDSS_CC_CTRL_0_CMP_UP_VSEL_MASK | PDSS_CC_CTRL_0_CMP_DN_VSEL_MASK);

            if ((status & (PDSS_STATUS_VCMP_UP_STATUS | PDSS_STATUS_VCMP_DN_STATUS)) == PDSS_STATUS_VCMP_DN_STATUS)
            {
                cc1_edge = CY_USBPD_ADC_INT_RISING;
                cc2_edge = CY_USBPD_ADC_INT_FALLING;

                /* Set threshold at Ra level on CC1 and Rd level on CC2. */
                pd->cc_ctrl_0 |= ((thresholds[dpmConfig->srcCurLevelLive][0]) << PDSS_CC_CTRL_0_CMP_UP_VSEL_POS) |
                    (PD_CMP_VSEL_1_77_V << PDSS_CC_CTRL_0_CMP_DN_VSEL_POS);
            }
            else if ((status & (PDSS_STATUS_VCMP_UP_STATUS | PDSS_STATUS_VCMP_DN_STATUS)) == PDSS_STATUS_VCMP_UP_STATUS)
            {
                cc1_edge = CY_USBPD_ADC_INT_FALLING;
                cc2_edge = CY_USBPD_ADC_INT_RISING;

                /* Set threshold at Rd level on CC1 and Ra level on CC2. */
                pd->cc_ctrl_0 |= (PD_CMP_VSEL_1_77_V << PDSS_CC_CTRL_0_CMP_UP_VSEL_POS) |
                    ((thresholds[dpmConfig->srcCurLevelLive][0]) << PDSS_CC_CTRL_0_CMP_DN_VSEL_POS);
            }
            else
            {
                cc1_edge = CY_USBPD_ADC_INT_FALLING;
                cc2_edge = CY_USBPD_ADC_INT_FALLING;

                /* Set threshold at Rd level on both CC1 and CC2. */
                pd->cc_ctrl_0 |= (PD_CMP_VSEL_1_77_V << PDSS_CC_CTRL_0_CMP_UP_VSEL_POS) |
                    (PD_CMP_VSEL_1_77_V << PDSS_CC_CTRL_0_CMP_DN_VSEL_POS);
            }
            Cy_SysLib_DelayUs(10);

            pd->intr_1_cfg |= ((cc1_edge) << PDSS_INTR_1_CFG_VCMP_UP_CFG_POS) |
                ((cc2_edge) << PDSS_INTR_1_CFG_VCMP_DN_CFG_POS);
            pd->intr1 = (PDSS_INTR1_VCMP_UP_CHANGED | PDSS_INTR1_VCMP_DN_CHANGED |
                    PDSS_INTR1_VCMP_LA_CHANGED | PDSS_INTR1_CC1_CHANGED | PDSS_INTR1_CC2_CHANGED);
            pd->intr1_mask |= (PDSS_INTR1_CC1_CHANGED | PDSS_INTR1_CC2_CHANGED |
                    PDSS_INTR1_VCMP_UP_CHANGED | PDSS_INTR1_VCMP_DN_CHANGED);

            /* If the comparators have  already triggered, then set the interrupts and return. */
            if (
                    ((cc1_edge == CY_USBPD_ADC_INT_RISING) && ((pd->status & PDSS_STATUS_VCMP_UP_STATUS) != 0)) ||
                    ((cc1_edge == CY_USBPD_ADC_INT_FALLING) && ((pd->status & PDSS_STATUS_VCMP_UP_STATUS) == 0)) ||
                    ((cc2_edge == CY_USBPD_ADC_INT_RISING) && ((pd->status & PDSS_STATUS_VCMP_DN_STATUS) != 0)) ||
                    ((cc2_edge == CY_USBPD_ADC_INT_FALLING) && ((pd->status & PDSS_STATUS_VCMP_DN_STATUS) == 0))
               )
            {
                /* Fire anyone to wakeup*/
                pd->intr1_set |= PDSS_INTR1_VCMP_UP_CHANGED;
                return true;
            }
#endif /* CY_IP */
        }
        else
#endif /* (!CY_PD_SINK_ONLY) */
        {
            Cy_USBPD_TypeC_PhyDetectCCRise (context, false);

            /* Auto toggle cannot be started in Unattached.SNK state. */
            return true;
        }

#if CY_PD_HW_DRP_TOGGLE_ENABLE
        /* We can only use auto toggle when we don't already have an Ra connected. */
        if(
                (dpmConfig->toggle == true) &&
                (context->autoToggleEn != 0U) &&
                ((cc1_edge == CY_USBPD_ADC_INT_RISING) && (cc2_edge == CY_USBPD_ADC_INT_RISING))
          )
        {
#if (CY_PDUTILS_TIMER_TYPE == CY_PDUTILS_TIMER_TYPE_WDT)
            uint16_t timerMultiplier = context->timerGetMultipliercbk(context);
#endif /* CY_PDUTILS_TIMER_TYPE == CY_PDUTILS_TIMER_TYPE_WDT */
            if (context->typecEventsCbk)
            {
                context->typecEventsCbk (context->pdStackContext, CY_PD_TYPEC_EVT_STOP_FSM);
            }

            /* Make sure trimmed Rp/Rd are disabled. */
            pd->cc_ctrl_0 &= 0xFC300000;

            pd->intr1_mask &= ~(PDSS_INTR1_VCMP_UP_CHANGED |
                    PDSS_INTR1_VCMP_DN_CHANGED |
                    PDSS_INTR1_CC1_CHANGED |
                    PDSS_INTR1_CC2_CHANGED |
                    PDSS_INTR1_VCMP_LA_CHANGED);
            pd->intr1 = (PDSS_INTR1_VCMP_UP_CHANGED |
                    PDSS_INTR1_VCMP_DN_CHANGED |
                    PDSS_INTR1_VCMP_LA_CHANGED |
                    PDSS_INTR1_CC1_CHANGED |
                    PDSS_INTR1_CC2_CHANGED);

            pd->rp_rd_cfg2 &= ~(PDSS_RP_RD_CFG2_OVERRIDE_HW_REF_CTRL |
                                PDSS_RP_RD_CFG2_VCMP_CC_OVERRIDE |
                                PDSS_RP_RD_CFG2_CC1_ATTACH_VALUE |
                                PDSS_RP_RD_CFG2_CC2_ATTACH_VALUE);
            /* Need to use firmware override of references to get expected voltage on the CC line. */
            pd->rp_rd_cfg2 |= PDSS_RP_RD_CFG2_VCMP_CC_OVERRIDE | PDSS_RP_RD_CFG2_OVERRIDE_HW_REF_CTRL;

            pd->rp_rd_cfg1 &= ~(PDSS_RP_RD_CFG1_TOGGLE_PERIOD_MASK |
                    PDSS_RP_RD_CFG1_BASE_HIGH_WIDTH_MASK |
                    PDSS_RP_RD_CFG1_CONTINUE_PREV);

#if (CY_PDUTILS_TIMER_TYPE == CY_PDUTILS_TIMER_TYPE_WDT)
            /* If WDT timer is being used, we can use a calibrated period setting. */
            pd->rp_rd_cfg1 |= (
                    ((PDSS_CY_PD_DRP_TOGGLE_PERIOD_MS * timerMultiplier) << PDSS_RP_RD_CFG1_TOGGLE_PERIOD_POS) |
                    ((PDSS_DRP_HIGH_PERIOD_MS * timerMultiplier) << PDSS_RP_RD_CFG1_BASE_HIGH_WIDTH_POS) |
                    PDSS_RP_RD_CFG1_HW_RP_RD_AUTO_TOGGLE |
                    PDSS_RP_RD_CFG1_RESET_COUNT
                    );
#else
            /* SYSTICK is used and LF CLK calibration is not done. */
            pd->rp_rd_cfg1 |= (
                    (PDSS_CY_PD_DRP_TOGGLE_PERIOD_VAL << PDSS_RP_RD_CFG1_TOGGLE_PERIOD_POS) |
                    (PDSS_DRP_HIGH_PERIOD_VAL << PDSS_RP_RD_CFG1_BASE_HIGH_WIDTH_POS) |
                    PDSS_RP_RD_CFG1_HW_RP_RD_AUTO_TOGGLE |
                    PDSS_RP_RD_CFG1_RESET_COUNT
                    );
#endif /* CY_PDUTILS_TIMER_TYPE */

            while(pd->rp_rd_cfg1 & PDSS_RP_RD_CFG1_RESET_COUNT);

            /* Setting cc1/cc2 filters */
            /* Configure filter clock cycles and disable the filter. */
            pd->intr1_cfg_cc1_cc2_ls &= ~(PDSS_INTR1_CFG_CC1_CC2_LS_CC1_FILT_SEL_MASK |
                    PDSS_INTR1_CFG_CC1_CC2_LS_CC2_FILT_SEL_MASK |
                    PDSS_INTR1_CFG_CC1_CC2_LS_CC1_FILT_EN |
                    PDSS_INTR1_CFG_CC1_CC2_LS_CC2_FILT_EN |
                    PDSS_INTR1_CFG_CC1_CC2_LS_CC1_FILT_RESET |
                    PDSS_INTR1_CFG_CC1_CC2_LS_CC2_FILT_RESET |
                    PDSS_INTR1_CFG_CC1_CC2_LS_CC1_FILT_BYPASS |
                    PDSS_INTR1_CFG_CC1_CC2_LS_CC2_FILT_BYPASS);

            pd->intr1_cfg_cc1_cc2_ls |= ((PDSS_CC_FILT_CYCLES << PDSS_INTR1_CFG_CC1_CC2_LS_CC1_FILT_SEL_POS) |
                    (PDSS_CC_FILT_CYCLES << PDSS_INTR1_CFG_CC1_CC2_LS_CC2_FILT_SEL_POS) |
                    (PDSS_INTR1_CFG_CC1_CC2_LS_CC1_FILT_EN | PDSS_INTR1_CFG_CC1_CC2_LS_CC2_FILT_EN));

            /*
             * Connect  up comparator to CC1 and down comparator to CC2. Also,
             * Set the up comparator on CC1 and the down comparator on CC2 for
             * rising threshold of 0.2V.
             */
            pd->cc_ctrl_0 = ((pd->cc_ctrl_0 & ~(PDSS_CC_CTRL_0_CMP_UP_CC1V2 |
                    PDSS_CC_CTRL_0_CMP_UP_VSEL_MASK | PDSS_CC_CTRL_0_CMP_DN_VSEL_MASK)) |
                    (PDSS_CC_CTRL_0_CMP_EN | PDSS_CC_CTRL_0_CMP_DN_CC1V2));

            /* Setting up/dn filters */
            pd->intr1_cfg_vcmp_up_down_ls &= ~(PDSS_INTR1_CFG_VCMP_UP_DOWN_LS_VCMP_UP_FILT_SEL_MASK |
                    PDSS_INTR1_CFG_VCMP_UP_DOWN_LS_VCMP_DN_FILT_SEL_MASK |
                    PDSS_INTR1_CFG_VCMP_UP_DOWN_LS_VCMP_UP_FILT_EN |
                    PDSS_INTR1_CFG_VCMP_UP_DOWN_LS_VCMP_DN_FILT_EN |
                    PDSS_INTR1_CFG_VCMP_UP_DOWN_LS_VCMP_UP_FILT_RESET |
                    PDSS_INTR1_CFG_VCMP_UP_DOWN_LS_VCMP_DN_FILT_RESET |
                    PDSS_INTR1_CFG_VCMP_UP_DOWN_LS_VCMP_UP_FILT_BYPASS |
                    PDSS_INTR1_CFG_VCMP_UP_DOWN_LS_VCMP_DN_FILT_BYPASS);
            pd->intr1_cfg_vcmp_up_down_ls |= (
                    (PDSS_CC_FILT_CYCLES << PDSS_INTR1_CFG_VCMP_UP_DOWN_LS_VCMP_UP_FILT_SEL_POS) |
                    (PDSS_CC_FILT_CYCLES << PDSS_INTR1_CFG_VCMP_UP_DOWN_LS_VCMP_DN_FILT_SEL_POS) |
                    (PDSS_INTR1_CFG_VCMP_UP_DOWN_LS_VCMP_UP_FILT_EN |
                     PDSS_INTR1_CFG_VCMP_UP_DOWN_LS_VCMP_DN_FILT_EN));

            /* Auto toggle is active. Prevent other changes from happening. */
            context->autoToggleAct = true;

            pd->intr1 = PDSS_INTR1_DRP_ATTACHED_DETECTED;
            pd->intr1_mask |= PDSS_INTR1_DRP_ATTACHED_DETECTED;

            pd->rp_rd_cfg1 |= PDSS_RP_RD_CFG1_START_TOGGLE;
        }
        else
        {
            /*
               Leave auto toggle disabled for now. It will get re-enabled when
               the Type-C state machine enters Unattached.SRC again.
             */
            context->autoToggleEn = false;
        }
#endif /* CY_PD_HW_DRP_TOGGLE_ENABLE */
    }

    return true;
#else /* !SYS_DEEPSLEEP_ENABLE */
    (void)context;
    (void)voltage;
    (void)percentage;
    return false;
#endif /* SYS_DEEPSLEEP_ENABLE */
}

/*******************************************************************************
* Function Name: Cy_USBPD_Resume
****************************************************************************//**
* 
* This function configures all PD blocks supported by the device after exiting
* deepsleep.
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \return
* Returns true if successful, otherwise false
*
*******************************************************************************/
bool Cy_USBPD_Resume(
        cy_stc_usbpd_context_t *context)
{
#if SYS_DEEPSLEEP_ENABLE
    PPDSS_REGS_T pd = NULL;
    cy_stc_pd_dpm_config_t *dpmConfig = NULL;
    uint32_t regVal = 0;
    uint32_t mask = 0;

    if (context == NULL)
    {
        return false;
    }

    pd = context->base;
    dpmConfig = context->dpmGetConfig();

    if (!(dpmConfig->dpmEnabled))
    {
        return false;
    }

    /* Clear and disable all deepsleep interrupts. */
    mask = (PDSS_INTR1_VCMP_UP_CHANGED | PDSS_INTR1_VCMP_DN_CHANGED | PDSS_INTR1_VCMP_LA_CHANGED |
            PDSS_INTR1_CC1_CHANGED | PDSS_INTR1_CC2_CHANGED);
    pd->intr1_mask &= ~mask;
    pd->intr1       = mask;

#if ((!(CY_PD_SOURCE_ONLY)) && (!(CY_PD_USE_ADC_IN_DS))) 
    if ((dpmConfig->connect == true) && (dpmConfig->curPortRole == CY_PD_PRT_ROLE_SINK))
    {
#if CY_PD_REV3_ENABLE
        if (dpmConfig->frRxEnLive == false)
#endif /* CY_PD_REV3_ENABLE */
        {
            /* Disable the detach detection comparator. */
            Cy_USBPD_Adc_CompCtrl (context, 
                    context->vbusDetachAdcId, 
                    CY_USBPD_ADC_INPUT_AMUX_A,
                    0,
                    CY_USBPD_ADC_INT_DISABLED,
                    NULL);
        }
    }
#else
    if (0)
    {

    }
#endif /* ((!(CY_PD_SOURCE_ONLY)) && (!(CY_PD_USE_ADC_IN_DS))) */
    else if(dpmConfig->connect == false)
    {
#if ((!(CY_PD_SOURCE_ONLY)) && (!CY_PD_SINK_ONLY))
        if (dpmConfig->toggle == true)
        {
#if CY_PD_HW_DRP_TOGGLE_ENABLE
            if ((context->autoToggleEn != 0U) || (context->typecStartPending != 0U))
            {
                if (context->autoToggleAct)
                {
                    /*
                       Auto toggle is active and attach has not been detected. Do nothing.
                     */
                    return true;
                }

                /* Type-C restart will be done below if required. */
                context->typecStartPending = false;

                /*
                   Type-C state machine will not be up-to-date when DRP toggle is being done by hardware.
                   We need to jump to the right Type-C state to resume operation.
                 */
                if ((pd->rp_rd_cfg1 & PDSS_RP_RD_CFG1_HW_RP_RD_AUTO_TOGGLE) != 0U)
                {
                    if (pd->status & PDSS_STATUS_RP_RD_STATUS)
                    {
                        Cy_USBPD_TypeC_EnableRp(context, CY_PD_CC_CHANNEL_1, (cy_en_pd_rp_term_t)dpmConfig->srcCurLevelLive);
                        Cy_USBPD_TypeC_EnableRp(context, CY_PD_CC_CHANNEL_2, (cy_en_pd_rp_term_t)dpmConfig->srcCurLevelLive);

                        /* Disable the deep sleep Rp. */
                        pd->cc_ctrl_1 &= ~PDSS_CC_CTRL_1_DS_ATTACH_DET_EN;

                        dpmConfig->curPortRole = CY_PD_PRT_ROLE_SOURCE;
                        dpmConfig->curPortType = CY_PD_PRT_TYPE_DFP;
                        if (context->typecEventsCbk)
                        {
                            context->typecEventsCbk(context->pdStackContext, CY_PD_TYPEC_EVT_UNATTACHED_SRC);
                        }
                    }
                    else
                    {
                        Cy_USBPD_TypeC_EnableRd(context, CY_PD_CC_CHANNEL_1);
                        Cy_USBPD_TypeC_EnableRd(context, CY_PD_CC_CHANNEL_2);
                        
                        /* Disable the deep sleep Rp. */
                        pd->cc_ctrl_1 &= ~PDSS_CC_CTRL_1_DS_ATTACH_DET_EN;

                        dpmConfig->curPortRole = CY_PD_PRT_ROLE_SINK;
                        dpmConfig->curPortType = CY_PD_PRT_TYPE_UFP;

                        if (context->typecEventsCbk)
                        {
                            context->typecEventsCbk(context->pdStackContext, CY_PD_TYPEC_EVT_UNATTACHED_SNK);
                        }
                    }

                    /* Disable the RP-RD toggle. Rp or Rd needs to be applied before this. */
                    pd->rp_rd_cfg1 &= ~(PDSS_RP_RD_CFG1_HW_RP_RD_AUTO_TOGGLE | PDSS_RP_RD_CFG1_START_TOGGLE);
                    pd->intr1_mask &= ~PDSS_INTR1_DRP_ATTACHED_DETECTED;

                    /* Leave auto toggle disabled until enabled again by Type-C module. */
                    context->autoToggleEn = false;

                    /* typec_gen_entry_event disables scanning so re-enable it */
                    dpmConfig->skipScan = false;

                    /* Type-C start is required to enable RX. */
                    Cy_USBPD_TypeC_Start(context);
                }
            }
#endif /* CY_PD_HW_DRP_TOGGLE_ENABLE */
        }
#endif /* ((!(CY_PD_SOURCE_ONLY)) && (!CY_PD_SINK_ONLY)) */

#if (!CY_PD_SINK_ONLY)
        if (dpmConfig->curPortRole == CY_PD_PRT_ROLE_SOURCE)
        {
            /* Re-enable the trimmed Rp. */
            Cy_USBPD_TypeC_EnableRp(context, CY_PD_CC_CHANNEL_1, (cy_en_pd_rp_term_t)dpmConfig->srcCurLevelLive);
            Cy_USBPD_TypeC_EnableRp(context, CY_PD_CC_CHANNEL_2, (cy_en_pd_rp_term_t)dpmConfig->srcCurLevelLive);
        }

        /* Disable the deep sleep Rp. */
        pd->cc_ctrl_1 &= ~PDSS_CC_CTRL_1_DS_ATTACH_DET_EN;

#endif /* (!CY_PD_SINK_ONLY) */

#if defined(CY_IP_MXUSBPD)
        /* Disable cc1/cc2/up/down filters */
        regVal = pd->intr1_cfg_cc1_cc2_ls;
        regVal &= ~(PDSS_INTR1_CFG_CC1_CC2_LS_CC1_FILT_EN |
                PDSS_INTR1_CFG_CC1_CC2_LS_CC2_FILT_EN);
        regVal |= PDSS_INTR1_CFG_CC1_CC2_LS_CC1_FILT_BYPASS |
            PDSS_INTR1_CFG_CC1_CC2_LS_CC2_FILT_BYPASS;
        pd->intr1_cfg_cc1_cc2_ls = regVal;

        regVal = pd->intr1_cfg_vcmp_up_down_ls;
        regVal &= ~(PDSS_INTR1_CFG_VCMP_UP_DOWN_LS_VCMP_UP_FILT_EN |
                PDSS_INTR1_CFG_VCMP_UP_DOWN_LS_VCMP_DN_FILT_EN);
        regVal |= (PDSS_INTR1_CFG_VCMP_UP_DOWN_LS_VCMP_UP_FILT_BYPASS |
                PDSS_INTR1_CFG_VCMP_UP_DOWN_LS_VCMP_DN_FILT_BYPASS);
        pd->intr1_cfg_vcmp_up_down_ls = regVal;
#else
        CY_UNUSED_PARAMETER(regVal);
#endif /* defined(CY_IP_MXUSBPD) */
    }

    return true;
#else
    CY_UNUSED_PARAMETER(context);
    return false;
#endif /* SYS_DEEPSLEEP_ENABLE */
}

/*******************************************************************************
* Function Name: Cy_USBPD_EnableSwitch
****************************************************************************//**
* 
* Enable's the VSYS/VBUS TO VDDD Switch.
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \return
* None
*
*******************************************************************************/
void Cy_USBPD_EnableSwitch(cy_stc_usbpd_context_t *context)
{
#if (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP)) 
    PPDSS_REGS_T pd = context->base;
    /* is VSYS is still present */
#if defined(CY_DEVICE_CCG6DF_CFP) 
    if ((pd->intr7_status & (PDSS_INTR7_STATUS_FILT_8)) != 0U)
#else
    if ((pd->intr7_status & (CLK_LF_FILT_NUM << PDSS_INTR7_STATUS_FILT_8_POS)) != 0U)
#endif /* defined(CY_DEVICE_CCG6DF_CFP) */
    {       
        /* VSYS is now present: Enable switch and disable regulator. */
        pd->vreg_vsys_ctrl |= PDSS_VREG_VSYS_CTRL_ENABLE_VDDD_SWITCH;
        Cy_SysLib_DelayUs (100);

        /* Disable the vbus regulator on port0 */
#if defined(CY_DEVICE_CCG6DF_CFP)
        pd->vreg_vsys_ctrl &= ~PDSS_VREG_VSYS_CTRL_VREG20_EN;
#else
        pd->vreg_vsys_ctrl &= ~PDSS_VREG_VSYS_CTRL_VREG20_1_EN;
#endif /* defined(CY_DEVICE_CCG6DF_CFP) */
#if PMG1_PD_DUALPORT_ENABLE
        /* Disable the vbus regulator on port1 */
        if((NULL != context->altPortUsbPdCtx[TYPEC_PORT_1_IDX]) && (context->port == TYPEC_PORT_0_IDX))
        {
            PPDSS_REGS_T pdPort1 = context->altPortUsbPdCtx[TYPEC_PORT_1_IDX]->base;
#if defined(CY_DEVICE_CCG6DF_CFP)
            pdPort1->vreg_vsys_ctrl &= ~(PDSS_VREG_VSYS_CTRL_VREG20_EN);
#else
            pdPort1->vreg_vsys_ctrl &= ~(PDSS_VREG_VSYS_CTRL_VREG20_1_EN);
#endif /* defined(CY_DEVICE_CCG6DF_CFP) */
        }
#endif /* PMG1_PD_DUALPORT_ENABLE */

        /* update vsys polling status */
        context->pollForVsys &= (uint8_t) (~((uint8_t)CY_USBPD_POLL_VSYS_INT_UP | (uint8_t)CY_USBPD_POLL_VSYS_STOP_TIMER));
    }
#else
    CY_UNUSED_PARAMETER(context);
#endif /* (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP)) */
}

/*******************************************************************************
* Function Name: Cy_USBPD_Intr1Handler
****************************************************************************//**
* 
* Handle all wake-up interrupt sources.
* INTR1/INTR3/INTR5 etc are mapped to the wake-up interrupt vector.
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \return
* None
*
*******************************************************************************/
void Cy_USBPD_Intr1Handler (
        cy_stc_usbpd_context_t *context)
{
    PPDSS_REGS_T pd = context->base;
    uint32_t intrCause = pd->intr1_masked;
#if (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP))
#if PDL_VBUS_RCP_ENABLE
    uint32_t mask = 0u;
#endif /* PDL_VBUS_RCP_ENABLE */
#endif /* (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP)) */

#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))

#if defined(CY_DEVICE_SERIES_WLC1)
    /* 
     * These are critical interrupts and to be handled at 
     * the beginning of interrupt handler.
     */
    /* PDS SCP interrupt handling. */
    if ((pd->intr15_masked & PDSS_INTR15_PDS_SCP_CHANGED) != 0u)
    {
        /* Clear interrupt, but do not disable. */
        pd->intr15 = PDSS_INTR15_PDS_SCP_CHANGED;
        if(context->pdsScpCbk != NULL)
        {
            context->pdsScpCbk(context, true);
        }
    }

    /* CC UP comp interrupt handling. */
    if ((intrCause & PDSS_INTR1_MASKED_VCMP_UP_CHANGED_MASKED) != 0u)
    {
        /* Clear interrupt. */
        pd->intr1 = PDSS_INTR1_VCMP_UP_CHANGED;

        if(context->ccUpCbk != NULL)
        {
            context->ccUpCbk(context, true);
        }
        else
        {
            /* Disable interrupt. */
            pd->intr1_mask &= ~PDSS_INTR1_MASKED_VCMP_UP_CHANGED_MASKED;
        }
    }

    /* CC DN comp interrupt handling. */
    if ((intrCause & PDSS_INTR1_MASKED_VCMP_DN_CHANGED_MASKED) != 0u)
    {
        /* Clear interrupt */
        pd->intr1 = PDSS_INTR1_VCMP_DN_CHANGED;

        if(context->ccDnCbk != NULL)
        {
            context->ccDnCbk(context, true);
        }
        else
        {
            /* Disable interrupt. */
            pd->intr1_mask &= ~PDSS_INTR1_MASKED_VCMP_DN_CHANGED_MASKED;
        }
    }
#endif /* defined(CY_DEVICE_SERIES_WLC1) */

#if PDL_VBUS_SCP_ENABLE
    if ((pd->intr13_masked & (PDSS_INTR13_MASKED_CSA_SCP_CHANGED_MASKED)) != 0u)
    {
        Cy_USBPD_Fault_Vbus_ScpIntrHandler(context);
    }
#endif /* PDL_VBUS_SCP_ENABLE */

#if PDL_VCONN_SCP_ENABLE
    /* CC1/2 SCP handler. */
    if ((pd->intr17_masked & (PDSS_INTR17_MASKED_PDBB_CC1_SCP_MASKED |
        PDSS_INTR17_MASKED_PDBB_CC2_SCP_MASKED)) != 0u)
    {
        /*
         * No need to check current status as we only enable positive edge on the interrupt.
         * Deliver callback to app layer.
         */
        if (context->vconnScpCbk != NULL)
        {
            context->vconnScpCbk(context, true);
        }

        /* Clear and disable the interrupts. */
        pd->intr17 = (PDSS_INTR17_PDBB_CC1_SCP | PDSS_INTR17_PDBB_CC2_SCP);
        pd->intr17_mask &= ~(PDSS_INTR17_MASK_PDBB_CC1_SCP_MASK |
            PDSS_INTR17_MASK_PDBB_CC2_SCP_MASK);
    }
#endif /* PDL_VCONN_SCP_ENABLE */

#if PDL_VIN_UVP_ENABLE
    if ((pd->intr17_masked & PDSS_INTR17_MASKED_PDBB_PWM_VIN_UV_DET_MASKED) != 0u)
    {
        /* Invoke OVP callback. */
        if (context->vinUvpCbk != NULL)
        {
            context->vinUvpCbk (context, false);
        }

        /* Disable and clear VIN OV interrupt. */
        pd->intr17_mask &= ~PDSS_INTR17_MASK_PDBB_PWM_VIN_UV_DET_MASK;
        pd->intr17 = PDSS_INTR17_PDBB_PWM_VIN_UV_DET;
    }
#endif /* PDL_VIN_UVP_ENABLE */
#endif /* (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) */

/* Moving OVP and UVP Intr handler to top as a fix for Ilimit feature wrong SCP fault. */
#if defined(CY_IP_MXUSBPD)
    if (pd->intr5_masked != 0U)
    {
#if PDL_VBUS_OVP_ENABLE
        if ((pd->intr5_masked & (1u << CY_USBPD_VBUS_FILTER_ID_OV)) != 0U)
        {
            Cy_USBPD_Fault_Vbus_OvpIntrHandler(context);
            pd->intr5_mask &= ~(1u << CY_USBPD_VBUS_FILTER_ID_OV);
            pd->intr5 = (1u << CY_USBPD_VBUS_FILTER_ID_OV);
        }
#endif /* PDL_VBUS_OVP_ENABLE */
#if (PDL_VBUS_UVP_ENABLE || CCG_PASC_LP_ENABLE)
        if ((pd->intr5_masked & (1UL << CY_USBPD_VBUS_FILTER_ID_UV)) != 0U)
        {
            Cy_USBPD_Fault_Vbus_UvpIntrHandler(context);
        }
#endif /* (PDL_VBUS_UVP_ENABLE || CCG_PASC_LP_ENABLE) */
    }
#endif /* defined(CY_IP_MXUSBPD) */

#if (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP))

#if PDL_VBUS_RCP_ENABLE
#if defined(CY_DEVICE_CCG6DF_CFP)
    mask = PDSS_INTR13_MASKED_CSA_COMP_OUT_CHANGED_MASKED;
#else
    mask = (PDSS_INTR13_MASKED_CSA_OUT_CHANGED_MASKED) | (PDSS_INTR13_MASKED_CSA_COMP_OUT_CHANGED_MASKED) | (PDSS_INTR13_MASKED_CSA_VBUS_OVP_CHANGED_MASKED);
#endif /* defined(CY_DEVICE_CCG6DF_CFP) */
    /*
     * RCP interrupt handling.
     * Provider FET would have been turned off. We only need to clear the interrupt and start recovery.
     * Note: On CCG6DF_CFP, SCP occurs when the FET turns off due to RCP. This causes DUT to report SCP instead of RCP.
     * Hence, handling RCP first if both RCP and SCP occurs in the same ISR.
     */
    if ((pd->intr13_masked & mask) != 0U)
    {
        Cy_USBPD_Fault_Vbus_RcpIntrHandler(context);
    }
#endif /* PDL_VBUS_RCP_ENABLE */

#if PDL_VBUS_SCP_ENABLE
    /*
     * SCP interrupt handling.
     * Provider FET would have been turned off. We only need to clear the interrupt and start recovery.
     */
    if ((pd->intr13_masked & (PDSS_INTR13_MASKED_CSA_SCP_CHANGED_MASKED)) != 0U)
    {
        Cy_USBPD_Fault_Vbus_ScpIntrHandler(context);
    }
#endif /* PDL_VBUS_SCP_ENABLE */

#endif /* defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP) */

#if (!CY_PD_SINK_ONLY)
#if (CY_PD_REV3_ENABLE && CY_PD_FRS_RX_ENABLE)
#if defined(CY_DEVICE_CCG6DF_CFP)
        if ((pd->intr20 & PDSS_INTR20_VSWAP_VBUS_LESS_5_DONE) != 0U)
        {
            pd->intr20_mask &= ~PDSS_INTR20_VSWAP_VBUS_LESS_5_DONE;
            pd->intr20 = PDSS_INTR20_VSWAP_VBUS_LESS_5_DONE;
            Cy_USBPD_Vbus_FrsRx_IntrHandler(context);
        }
#endif /* defined(CY_DEVICE_CCG6DF_CFP) */
#endif /* (CY_PD_REV3_ENABLE && CY_PD_FRS_RX_ENABLE) */
#endif /* (!CY_PD_SINK_ONLY) */

    /*
     * This routine expects all interrupts which are triggered to be disabled
     * once they are fired, otherwise it can cause problems.
     */
    if (intrCause != 0U)
    {
        /* Clear the CC1 and CC2 changed interrupts. */
        if ((intrCause & PDSS_INTR1_CC1_CHANGED) != 0U)
        {
            pd->intr1_mask &= ~PDSS_INTR1_CC1_CHANGED;
            pd->intr1       = PDSS_INTR1_CC1_CHANGED;
        }

        if ((intrCause & PDSS_INTR1_CC2_CHANGED) != 0U)
        {
            pd->intr1_mask &= ~PDSS_INTR1_CC2_CHANGED;
            pd->intr1       = PDSS_INTR1_CC2_CHANGED;
        }

#if PMG1_HPD_RX_ENABLE
        if ((intrCause & PDSS_INTR1_HPDIN_CHANGED) != 0U)
        {
            Cy_USBPD_Hpd_Intr1Handler(context);
        }
#endif /* PMG1_HPD_RX_ENABLE */

#if (!CY_PD_SINK_ONLY)
#if (CY_PD_REV3_ENABLE && CY_PD_FRS_RX_ENABLE)
#if !defined(CY_DEVICE_CCG6DF_CFP)
        if ((intrCause & PDSS_INTR1_VSWAP_VBUS_LESS_5_DONE) != 0U)
        {
            pd->intr1_mask &= ~PDSS_INTR1_VSWAP_VBUS_LESS_5_DONE;
            pd->intr1 = PDSS_INTR1_VSWAP_VBUS_LESS_5_DONE;
            Cy_USBPD_Vbus_FrsRx_IntrHandler(context);
        }
#endif /* defined(CY_DEVICE_CCG6DF_CFP) */
#endif /* (CY_PD_REV3_ENABLE && CY_PD_FRS_RX_ENABLE) */
#endif /* (!CY_PD_SINK_ONLY) */

#if ((SYS_DEEPSLEEP_ENABLE) && (CY_PD_HW_DRP_TOGGLE_ENABLE))
        if ((intrCause & PDSS_INTR1_DRP_ATTACHED_DETECTED) != 0U)
        {
            pd->intr1_mask &= ~PDSS_INTR1_DRP_ATTACHED_DETECTED;
            pd->intr1 = PDSS_INTR1_DRP_ATTACHED_DETECTED;

            /* Auto toggle has been stopped. Also, mark Type-C restart pending. */
            context->autoToggleAct = false;
            context->typecStartPending = true;
        }
#endif /* ((SYS_DEEPSLEEP_ENABLE) && (CY_PD_HW_DRP_TOGGLE_ENABLE)) */

#if (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
#if PDL_VCONN_OCP_ENABLE
        if ((intrCause & (PDSS_INTR1_CC1_OCP_CHANGED | PDSS_INTR1_CC2_OCP_CHANGED)) != 0U)
        {
            pd->intr1_mask &= ~(PDSS_INTR1_CC1_OCP_CHANGED | PDSS_INTR1_CC2_OCP_CHANGED);
            pd->intr1 = (PDSS_INTR1_CC1_OCP_CHANGED | PDSS_INTR1_CC2_OCP_CHANGED);
            Cy_USBPD_Fault_Vconn_OcpIntrHandler(context);
        }
#endif /* PDL_VCONN_OCP_ENABLE */

#if defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1) || defined(CY_DEVICE_CCG6DF_CFP)
#if PDL_CC_OVP_ENABLE
        /* CC1/2 OVP (VBus short) handler. */
        if ((intrCause & (PDSS_INTR1_CC1_OVP_CHANGED | PDSS_INTR1_CC2_OVP_CHANGED)) != 0U)
        {
            pd->intr1_mask &= ~(PDSS_INTR1_CC1_OVP_CHANGED | PDSS_INTR1_CC2_OVP_CHANGED);
            pd->intr1 = (PDSS_INTR1_CC1_OVP_CHANGED | PDSS_INTR1_CC2_OVP_CHANGED);
            Cy_USBPD_Fault_CcOvp_IntrHandler(context);
        }
#endif /* PDL_CC_OVP_ENABLE */
#endif /* defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1 || defined(CY_DEVICE_CCG6DF_CFP) */

#if PMG1_V5V_CHANGE_DETECT
        if ((intrCause & PDSS_INTR1_MASK_V5V_CHANGED_MASK) != 0U)
        {
            pd->intr1 = PDSS_INTR1_MASK_V5V_CHANGED_MASK;
            Cy_USBPD_Vbus_V5vChangeDetectHandler (context);
        }
#endif /* PMG1_V5V_CHANGE_DETECT */

#endif /* (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) */

#if defined(CY_DEVICE_CCG3)
        if ((intrCause & (PDSS_INTR1_CMP_OUT1_CHANGED | PDSS_INTR1_CMP_OUT2_CHANGED)) != 0U)
        {
            Cy_USBPD_Adc_IntrHandler(context);
            pd->intr1 = (PDSS_INTR1_CMP_OUT1_CHANGED | PDSS_INTR1_CMP_OUT2_CHANGED);
        }

#if PMG1_V5V_CHANGE_DETECT
        if ((intrCause & PDSS_INTR1_MASK_V5V_CHANGED_MASK) != 0U)
        {
            pd->intr1 = PDSS_INTR1_MASK_V5V_CHANGED_MASK;
            Cy_USBPD_Vbus_V5vChangeDetectHandler (context);
        }
#endif /* PMG1_V5V_CHANGE_DETECT */
#endif /* defined(CY_DEVICE_CCG3) */

        if ((intrCause & PDSS_INTR1_VCMP_LA_CHANGED) != 0U)
        {
            /* Disable the interrupt. */
            pd->intr1_mask &= ~PDSS_INTR1_VCMP_LA_CHANGED;
            pd->intr1 = PDSS_INTR1_VCMP_LA_CHANGED;
        }

#if !defined(CY_DEVICE_SERIES_WLC1)
        if ((intrCause & PDSS_INTR1_VCMP_UP_CHANGED) != 0U)
        {
            /* Disable the interrupt. */
            pd->intr1_mask &= ~PDSS_INTR1_VCMP_UP_CHANGED;
            pd->intr1 = PDSS_INTR1_VCMP_UP_CHANGED;
        }

        if ((intrCause & PDSS_INTR1_VCMP_DN_CHANGED) != 0U)
        {
            /* Disable the interrupt. */
            pd->intr1_mask &= ~PDSS_INTR1_VCMP_DN_CHANGED;
            pd->intr1 = PDSS_INTR1_VCMP_DN_CHANGED;
        }

        /* Clear all handled interrupts */
        pd->intr1 = intrCause ; 
#endif /* defined(CY_DEVICE_SERIES_WLC1) */
    }

#if defined(CY_DEVICE_CCG3PA)
    if ((pd->intr3_masked & (1u << PDSS_INTR3_CMP_OUT_CHANGED_POS)) != 0U)
    {
        Cy_USBPD_Adc_IntrHandler(context);
    }

    if ((pd->intr3_masked & ((1u << PDSS_INTR3_CMP_OUT_CHANGED_POS) << CY_USBPD_ADC_ID_1)) != 0U)
    {
        Cy_USBPD_Adc_IntrHandler(context);
    }

#endif /* defined(CY_DEVICE_CCG3PA) */
#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1) || defined(CY_DEVICE_CCG3PA))
    if ((pd->intr5_masked & (1u << (uint8_t)CY_USBPD_VBUS_FILTER_ID_LSCSA_PFC)) != 0u)
    {
        Cy_USBPD_PFC_Intr1Handler(context);
    }

    if ((pd->intr5_masked & (1u << (uint8_t)CY_USBPD_VBUS_FILTER_ID_LSCSA_SR)) != 0u)
    {
        Cy_USBPD_SR_Intr1Handler(context);
    }
#endif /* (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1) || defined(CY_DEVICE_CCG3PA)) */

#if defined(CY_DEVICE_CCG3)
    if ((pd->intr3_masked & PDSS_INTR3_VSYS_CHANGED) != 0U)
    {
        /* Clear the interrupt. */
        pd->intr3 = PDSS_INTR3_VSYS_CHANGED;

        /* Notify application about change in VSYS supply status. */
        if (context->supplyChangeCbk != NULL)
        {
            context->supplyChangeCbk (context, CY_USBPD_SUPPLY_VSYS,
                    ((pd->ncell_status & PDSS_NCELL_STATUS_VSYS_STATUS) != 0U));
        }
    }

    if ((pd->intr3_masked & PDSS_INTR3_POS_CSA_CHANGED) != 0U)
    {
#if PDL_VBUS_OCP_ENABLE
        Cy_USBPD_Fault_Vbus_OcpIntrHandler(context);
#else 
        /* Clear and disable the interrupt first. */
        pd->intr3_mask &= ~PDSS_INTR3_POS_CSA_CHANGED;
        pd->intr3 = PDSS_INTR3_POS_CSA_CHANGED;

#endif /* VBUS_OCP_ENABLE */
    }

    if ((pd->intr3_masked & PDSS_INTR3_NEG_CSA_CHANGED) != 0U)
    {
#if PDL_VBUS_OCP_ENABLE
        Cy_USBPD_Fault_Vbus_OcpIntrHandler(context);
#else
        /* Clear and disable the interrupt first. */
        pd->intr3_mask &= ~PDSS_INTR3_NEG_CSA_CHANGED;
        pd->intr3 = PDSS_INTR3_NEG_CSA_CHANGED;
#endif /* VBUS_OCP_ENABLE */
    }

    if ((pd->intr3_masked & PDSS_INTR3_POS_OV_CHANGED) != 0U)
    {
        /* Disable and clear the OV interrupt. */
        pd->intr3_mask &= ~PDSS_INTR3_POS_OV_CHANGED;
        pd->intr3 = PDSS_INTR3_POS_OV_CHANGED;

#if PDL_VBUS_OVP_ENABLE
        Cy_USBPD_Fault_Vbus_OvpIntrHandler(context);
#endif /* PDL_VBUS_OVP_ENABLE */
    }

    if ((pd->intr3_masked & PDSS_INTR3_POS_UV_CHANGED) != 0U)
    {
        /* Disable and clear the UV interrupt. */
        pd->intr3_mask &= ~PDSS_INTR3_POS_UV_CHANGED;
        pd->intr3 = PDSS_INTR3_POS_UV_CHANGED;

#if PDL_VBUS_UVP_ENABLE
        Cy_USBPD_Fault_Vbus_UvpIntrHandler(context);
#endif /* PDL_VBUS_UVP_ENABLE */
    }
#endif /* defined(CY_DEVICE_CCG3) */

#if defined(CY_DEVICE_SERIES_PMG1B1)
    if (pd->intr7_masked != 0U)
    {
        if ((pd->intr7_masked & (1u << CY_USBPD_VBUS_FILTER_ID_OV)) != 0U)
        {
            Cy_USBPD_Fault_Vbat_OvpIntrHandler(context);
        }

        if ((pd->intr7_masked & (1UL << CY_USBPD_VBUS_FILTER_ID_UV)) != 0U)
        {
            Cy_USBPD_Fault_Vbat_UvpIntrHandler(context);
        }
    }
#endif /* defined(CY_DEVICE_SERIES_PMG1B1) */

#if (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP))
    if (pd->intr7_masked != 0U)
    {
        uint32_t value = pd->intr7;
        /* Clear all interrupts. */
        pd->intr7 = value;

        /* VSYS detection interrupt. */
#if defined(CY_DEVICE_CCG6DF_CFP)
        if ((pd->intr7_status & (PDSS_INTR7_STATUS_FILT_8)) != 0U)
#else
        if ((pd->intr7_status & (CLK_LF_FILT_NUM << PDSS_INTR7_STATUS_FILT_8_POS)) != 0U)
#endif /* defined(CY_DEVICE_CCG6DF_CFP) */
        {
/* is auto switch enabled @compile time */
#if (CY_USBPD_AUTO_SWITCH_VDDD_TO_VSYS_ENABLE)
/* is auto switch delay disabled @compile time */
#if (!CY_USBPD_AUTO_SWITCH_VDDD_TO_VSYS_DELAY_MS)
            Cy_USBPD_EnableSwitch(context);
#endif /* (!CY_USBPD_AUTO_SWITCH_VDDD_TO_VSYS_DELAY_MS) */
            /* update vsys polling status */
            context->pollForVsys |= (uint8_t) CY_USBPD_POLL_VSYS_INT_UP;
#endif /* (CY_USBPD_AUTO_SWITCH_VDDD_TO_VSYS_ENABLE) */
            /* Notify application about presence of VSYS supply. */
            if (context->supplyChangeCbk != NULL)
            {
                context->supplyChangeCbk (context, CY_USBPD_SUPPLY_VSYS, true);
            }
        }
        else
        {             
/* is auto switch enabled @compile time */
#if (CY_USBPD_AUTO_SWITCH_VDDD_TO_VSYS_ENABLE)
            /* update vsys polling status */
            context->pollForVsys = (uint8_t) CY_USBPD_POLL_VSYS_IDLE;
   
            /* Check if CCG is powered from VSYS.*/
            if (0u != (pd->vreg_vsys_ctrl & PDSS_VREG_VSYS_CTRL_ENABLE_VDDD_SWITCH))
            {
                /* Disable the VSYS-VDDD Switch. */
                pd->vreg_vsys_ctrl &= ~PDSS_VREG_VSYS_CTRL_ENABLE_VDDD_SWITCH;
                /* Reset DUT as the drop on VDDD is already happened. */
                NVIC_SystemReset();
            }
#endif /* (CY_USBPD_AUTO_SWITCH_VDDD_TO_VSYS_ENABLE) */


            /* Notify application about absence of VSYS supply. */
            if (context->supplyChangeCbk != NULL)
            {
                context->supplyChangeCbk (context, CY_USBPD_SUPPLY_VSYS, false);
            }
        }

#if (defined(CY_DEVICE_PMG1S3) && (SBU_LEVEL_DETECT_EN != 0))
        if (((pd->intr7_status & (CLK_LF_FILT_SBU1 << PDSS_INTR7_STATUS_FILT_8_POS)) != 0U) ||
            ((pd->intr7_status & (CLK_LF_FILT_SBU2 << PDSS_INTR7_STATUS_FILT_8_POS)) != 0U))
        {
            bool sbu1Detect = ((pd->intr7_status & (CLK_LF_FILT_SBU1 << PDSS_INTR7_STATUS_FILT_8_POS)) != 0);
            bool sbu2Detect = ((pd->intr7_status & (CLK_LF_FILT_SBU2 << PDSS_INTR7_STATUS_FILT_8_POS)) != 0);

            if(context->sbuDetectCb != NULL)
            {
                context->sbuDetectCb(context, sbu1Detect, sbu2Detect);
            }
        }

#endif /* (defined(CY_DEVICE_PMG1S3) && (SBU_LEVEL_DETECT_EN != 0))) */
    }
#endif /* defined (CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP) */

#if defined(CY_DEVICE_CCG3PA)
    if (pd->intr5_masked != 0U)
    {
#if PDL_VBUS_OCP_ENABLE
        if ((pd->intr5_masked & (1u << (uint8_t)CY_USBPD_VBUS_FILTER_ID_LSCSA_OCP)) != 0u)
        {
            Cy_USBPD_Fault_Vbus_OcpIntrHandler(context);
        }
#endif /* PDL_VBUS_OCP_ENABLE */

#if (PDL_VBUS_SCP_ENABLE)
        if ((pd->intr5_masked & (1u << (uint8_t)CY_USBPD_VBUS_FILTER_ID_LSCSA_OCP)) != 0u)
        {
            Cy_USBPD_Fault_Vbus_ScpIntrHandler(context);
        }
#endif /* (PDL_VBUS_SCP_ENABLE) */
       }
#endif /* defined(CY_DEVICE_CCG3PA) */

#if BATTERY_CHARGING_ENABLE
#if (defined(CY_DEVICE_CCG3PA) && (!QC_AFC_CHARGING_DISABLED))
    if ((pd->intr9_masked & (PDSS_INTR9_QCOM_RCVR_DM_CHANGED_MASK | PDSS_INTR9_QCOM_RCVR_DP_CHANGED_MASK)) != 0u)
    {
        pd->intr9_mask &= ~(PDSS_INTR9_QCOM_RCVR_DM_CHANGED_MASK |
                PDSS_INTR9_QCOM_RCVR_DP_CHANGED_MASK);
        pd->intr9 = PDSS_INTR9_QCOM_RCVR_DM_CHANGED_MASK |
            PDSS_INTR9_QCOM_RCVR_DP_CHANGED_MASK;
    }
#elif ((defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) && (!QC_AFC_CHARGING_DISABLED))
    if(((pd->intr9_masked & (PDSS_INTR9_QCOM_RCVR_DM_CHANGED |
                   PDSS_INTR9_QCOM_RCVR_DP_CHANGED)) != 0u))
       {
           pd->intr9_mask &= ~(PDSS_INTR9_QCOM_RCVR_DM_CHANGED |
                   PDSS_INTR9_QCOM_RCVR_DP_CHANGED);
           pd->intr9 = PDSS_INTR9_QCOM_RCVR_DM_CHANGED |
               PDSS_INTR9_QCOM_RCVR_DP_CHANGED;
       }
#elif (defined(CY_DEVICE_CCG6) && (!QC_AFC_CHARGING_DISABLED))
    if ((pd->intr9_masked &
                (PDSS_INTR9_MASKED_QCOM_RCVR_DM_CHANGED_MASKED |PDSS_INTR9_MASKED_QCOM_RCVR_DP_CHANGED_MASKED)
        ) != 0u)
    {
        pd->intr9_mask &= ~(PDSS_INTR9_MASK_QCOM_RCVR_DM_CHANGED_MASK |
                PDSS_INTR9_MASK_QCOM_RCVR_DP_CHANGED_MASK);
        pd->intr9 = PDSS_INTR9_QCOM_RCVR_DM_CHANGED |
            PDSS_INTR9_QCOM_RCVR_DP_CHANGED;
    }
#elif (defined(CY_DEVICE_PMG1S3) && (!QC_AFC_CHARGING_DISABLED))
    if ((pd->intr9_masked & (PDSS_INTR9_MASK_QCOM_RCVR_DM_CHANGED_MASK | PDSS_INTR9_MASK_QCOM_RCVR_DP_CHANGED_MASK)) != 0u)
    {
        pd->intr9_mask &= ~(PDSS_INTR9_MASK_QCOM_RCVR_DM_CHANGED_MASK |
                PDSS_INTR9_MASK_QCOM_RCVR_DP_CHANGED_MASK);
        pd->intr9 = PDSS_INTR9_MASK_QCOM_RCVR_DM_CHANGED_MASK |
            PDSS_INTR9_MASK_QCOM_RCVR_DP_CHANGED_MASK;
    }
#endif /* (defined(CY_DEVICE_PMG1S3) && (!QC_AFC_CHARGING_DISABLED)) */

#if defined(CY_IP_MXUSBPD)
    if ((pd->intr9_masked & (BCH_PORT_0_CMP1_INTR_MASK | BCH_PORT_0_CMP2_INTR_MASK)) != 0u)
    {
        Cy_USBPD_Bch_Intr1Handler(context);
    }
#if !(defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
#if (NO_OF_BC_PORTS == 2)
    if ((pd->intr9_masked & (BCH_PORT_1_CMP1_INTR_MASK | BCH_PORT_1_CMP2_INTR_MASK)) != 0u)
    {
        Cy_USBPD_Bch_Intr1Handler(context);
    }
#endif /* (NO_OF_BC_PORTS == 2) */
#endif /* !(defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) */
#elif defined(CY_IP_M0S8USBPD)
    if ((pd->intr3_masked & PDSS_INTR3_MASKED_CHGDET_CHANGED_MASKED) != 0u)
    {
        Cy_USBPD_Bch_Intr1Handler(context);
    }
#endif /* CY_IP */

#endif /* BATTERY_CHARGING_ENABLE */

#if (defined (CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP))

#if (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_CCG6DF_CFP))
#if PDL_SBU_OVP_ENABLE
    /* SBU1/2 OVP change interrupt. */
    if ((pd->intr3_masked & PDSS_INTR3_SBU1_SBU2_OVP_CHANGED_MASK) != 0U)
    {
        Cy_USBPD_Fault_SbuOvp_IntrHandler (context);
    }
#endif /* PDL_SBU_OVP_ENABLE */
#endif /* defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_CCG6DF_CFP) */

    /* Comparator (ADC) output change interrupt. */
    if ((pd->intr3_masked & PDSS_INTR3_CMP_OUT_CHANGED) != 0U)
    {
        Cy_USBPD_Adc_IntrHandler(context);
    }
#if PDL_VBUS_OCP_ENABLE
    /*
     * INTR13.CSA_OCP_CHANGED interrupt is used to indicate OCP condition.
     */
    if ((pd->intr13_masked & PDSS_INTR13_CSA_OCP_CHANGED) != 0U)
    {
        Cy_USBPD_Fault_Vbus_OcpIntrHandler(context);
    }
#endif /* PDL_VBUS_OCP_ENABLE */

#endif /* defined (CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP) */

#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
#if CCG_CF_HW_DET_ENABLE
    if (pd->intr15_masked & PDSS_INTR15_CC_FLAG_CHANGED)
    {
        pd->intr15 = PDSS_INTR15_CC_FLAG_CHANGED;
        if (context->cfCbk)
        {
            context->cfCbk(context, Cy_USBPD_CF_GetStatus(context));
        }
    }
#endif /* CCG_CF_HW_DET_ENABLE */

#if PMG1B1_USB_CHARGER
    if ((pd->intr13_masked & (PDSS_INTR13_MASKED_CSA_OCP_CHANGED_MASKED)) != 0u)
    {
        Cy_USBPD_Fault_Vbat_OcpIntrHandler(context);
    }
#else
#if PDL_VBUS_OCP_ENABLE
    if ((pd->intr13_masked & (PDSS_INTR13_MASKED_CSA_OCP_CHANGED_MASKED)) != 0u)
    {
        Cy_USBPD_Fault_Vbus_OcpIntrHandler(context);
    }
#endif /* PDL_VBUS_OCP_ENABLE */
#endif /* PMG1B1_USB_CHARGER */

#if PDL_VIN_OVP_ENABLE
    if ((pd->intr17_masked & PDSS_INTR17_MASKED_PDBB_PWM_VIN_OV_DET_MASKED) != 0u)
    {
        /* Invoke OVP callback. */
        if (context->vinOvpCbk != NULL)
        {
            context->vinOvpCbk (context, true);
        }

        /* Disable and clear VIN OV interrupt. */
        pd->intr17_mask &= ~PDSS_INTR17_MASK_PDBB_PWM_VIN_OV_DET_MASK;
        pd->intr17 = PDSS_INTR17_PDBB_PWM_VIN_OV_DET;
    }
#endif /* PDL_VIN_OVP_ENABLE */

#if PDL_VBAT_GND_SCP_ENABLE
    if ((pd->intr15_masked & PDSS_INTR15_PDS_SCP_CHANGED) != 0u)
    {
        /* VBAT_GND SCP interrupt handling. */
        /* Clear and disable interrupt. */
        pd->intr15_mask &= ~PDSS_INTR15_PDS_SCP_CHANGED;
        pd->intr15 = PDSS_INTR15_PDS_SCP_CHANGED;

        if(context->vbatGndScpCb != NULL)
        {
            context->vbatGndScpCb(context, true);
        }
    }
#endif /* PDL_VBAT_GND_SCP_ENABLE */

#if PDL_BB_ILIM_DET_ENABLE
    /* Buck-Boost iLim fault handler. */
    if ((pd->intr17_masked & PDSS_INTR17_MASKED_PDBB_40CSA_ILIM_DIG_OUT_MASKED) != 0u)
    {
        if(context->bbIlimCbk != NULL)
        {
            context->bbIlimCbk(context, true);
        }
        /*
         * Clear the fault in buck-boost to allow
         * state machine to come out of IDLE state.
         */
        pd->bbctrl_func_ctrl3 |= PDSS_BBCTRL_FUNC_CTRL3_BBCTRL_ILIM_FAULT_DET_CLR;

        /* Disable and Clear the interrupt. */
        pd->intr17_mask &= ~PDSS_INTR17_MASK_PDBB_40CSA_ILIM_DIG_OUT_MASK;
        pd->intr17 |= PDSS_INTR17_PDBB_40CSA_ILIM_DIG_OUT;
    }
#endif /* PDL_BB_ILIM_DET_ENABLE */

#if PDL_VREG_BROWN_OUT_DET_ENABLE
    /* Device VDDD brown out detect fault handler. */
    if ((pd->intr17_masked & PDSS_INTR17_MASKED_PDBB_VREG_VDDD_BOD_MASKED) != 0u)
    {
        /* Disable and Clear the interrupt. */
        pd->intr17_mask &= ~PDSS_INTR17_MASK_PDBB_VREG_VDDD_BOD_MASK;
        pd->intr17 |= PDSS_INTR17_PDBB_VREG_VDDD_BOD;

        if(context->bodCbk != NULL)
        {
            context->bodCbk(context, true);
        }
    }
#endif /* PDL_VREG_BROWN_OUT_DET_ENABLE */

#if PDL_VREG_INRUSH_DET_ENABLE
    /* Vreg Inrush fault handler. */
    if ((pd->intr17_masked & PDSS_INTR17_MASKED_PDBB_40VREG_IN_RUSH_DET_MASKED) != 0u)
    {
        /* Disable and Clear the interrupt. */
        pd->intr17_mask &= ~PDSS_INTR17_MASK_PDBB_40VREG_IN_RUSH_DET_MASK;
        pd->intr17 |= PDSS_INTR17_PDBB_40VREG_IN_RUSH_DET;

        if(context->vregInrushCbk != NULL)
        {
            context->vregInrushCbk(context, true);
        }
    }
#endif /* PDL_VREG_INRUSH_DET_ENABLE */

#if PDL_VOUTBB_RCP_ENABLE
    if ((pd->intr17_masked & PDSS_INTR17_MASKED_PDBB_GDRVO_HSRCP_MASKED) != 0U)
    {
        /* Disable and Clear the interrupt. */
        pd->intr17_mask &= ~PDSS_INTR17_MASK_PDBB_GDRVO_HSRCP_MASK;
        pd->intr17 |= PDSS_INTR17_PDBB_GDRVO_HSRCP;

        if(context->voutRcpCbk != NULL)
        {
            context->voutRcpCbk(context, true);
        }
    }
#endif /* PDL_VOUTBB_RCP_ENABLE */


#endif /* (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) */
}

/*******************************************************************************
* Function Name: Cy_USBPD_SetSupplyChange_EvtCb
****************************************************************************//**
* 
* Register a callback that can be used for notification of power supply changes.
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \param cb
* Callback function pointer
*
* \return
* CY_USBPD_STAT_SUCCESS if operation is successful, 
* CY_USBPD_STAT_BAD_PARAM if the context pointer or cb is invalid.
*
*******************************************************************************/
cy_en_usbpd_status_t Cy_USBPD_SetSupplyChange_EvtCb(
        cy_stc_usbpd_context_t *context,
        cy_usbpd_supply_change_cbk_t cb)
{
    if (
            (context == NULL) || (cb == NULL)
       )
    {
        return CY_USBPD_STAT_BAD_PARAM;
    }

    context->supplyChangeCbk = cb;

    return CY_USBPD_STAT_SUCCESS;
}

/*******************************************************************************
* Function Name: Cy_USBPD_SetEvtCb
****************************************************************************//**
* 
* Register a callback that can be used for notification of USBPD driver events.
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \param cb
* Callback function pointer
*
* \return
* CY_USBPD_STAT_SUCCESS if operation is successful, 
* CY_USBPD_STAT_BAD_PARAM if the context pointer or cb is invalid.
*
*******************************************************************************/
cy_en_usbpd_status_t Cy_USBPD_SetEvtCb(
        cy_stc_usbpd_context_t *context,
        cy_usbpd_evt_cbk_t cb)
{
    if (
            (context == NULL) || (cb == NULL)
       )
    {
        return CY_USBPD_STAT_BAD_PARAM;
    }

    context->usbpdEventsCbk = cb;

    return CY_USBPD_STAT_SUCCESS;
}

/*******************************************************************************
* Function Name: Cy_USBPD_SetTypeCEvtCb
****************************************************************************//**
* 
* Register a callback that can be used for notification of Type C driver events.
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \param callerContext
* Pointer to the caller context
*
* \param cb
* Callback function pointer
*
* \return
* CY_USBPD_STAT_SUCCESS if operation is successful, 
* CY_USBPD_STAT_BAD_PARAM if the context pointer or cb is invalid.
*
*******************************************************************************/
cy_en_usbpd_status_t Cy_USBPD_SetTypeCEvtCb(
        cy_stc_usbpd_context_t *context,
        void *callerContext,
        cy_usbpd_typec_evt_cbk_t cb)
{
    if (
            (context == NULL) || (cb == NULL)
       )
    {
        return CY_USBPD_STAT_BAD_PARAM;
    }

    context->typecEventsCbk = cb;
    context->pdStackContext = callerContext;

    return CY_USBPD_STAT_SUCCESS;
}

/*******************************************************************************
* Function Name: Cy_USBPD_SetSbuLevelDetect_EvtCb
****************************************************************************//**
*
* Register a callback that can be used for notification of SBU level detection.
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \param cb
* Callback function pointer
*
* \return
* CY_USBPD_STAT_SUCCESS if operation is successful,
* CY_USBPD_STAT_BAD_PARAM if the context pointer or cb is invalid.
*
*******************************************************************************/
cy_en_usbpd_status_t Cy_USBPD_SetSbuLevelDetect_EvtCb(
        cy_stc_usbpd_context_t *context,
        cy_cb_sbu_level_detect_t cb)
{
    if (
            (context == NULL) || (cb == NULL)
       )
    {
        return CY_USBPD_STAT_BAD_PARAM;
    }

    context->sbuDetectCb = cb;

    return CY_USBPD_STAT_SUCCESS;
}
/*******************************************************************************
* Function Name: Cy_USBPD_TypeC_SetCC_to_0V
****************************************************************************//**
*
* This function sets CC1 line to 0V
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \return
* None
*
*******************************************************************************/
void Cy_USBPD_TypeC_SetCC_to_0V (cy_stc_usbpd_context_t *context)
{
    uint32_t intr_state;
    PPDSS_REGS_T pd = NULL;
    uint32_t regVal = 0;

    if (context == NULL)
    {
        return;
    }

    intr_state = Cy_SysLib_EnterCriticalSection();
    pd = context->base;
    
    
    /* Saving the last status of the registers before setting CC to 0
    to restore back when needed */
#if defined(CY_DEVICE_CCG6DF_CFP)
    context->ccRegisters[0] = pd->pd_ref_gen_ctrl;
#else
    context->ccRegisters[0] = pd->dpslp_ref_ctrl;
#endif /* defined(CY_DEVICE_CCG6DF_CFP) */
    context->ccRegisters[1] = pd->cc_ctrl_0;
    context->ccRegisters[2] = pd->tx_ctrl;
    context->ccRegisters[3] = pd->cc_ctrl_1;
    context->ccRegisters[4] = pd->debug_cc_0;
    
    /* Setting CC to 0 */

#if defined(CY_DEVICE_CCG6DF_CFP)
    regVal = pd->pd_ref_gen_ctrl;
    regVal &= ~PDSS_PD_REF_GEN_CTRL_PD;
    pd->pd_ref_gen_ctrl = regVal;
#else
    regVal = pd->dpslp_ref_ctrl;
    regVal |= PDSS_DPSLP_REF_CTRL_IGEN_EN;
    regVal &= ~PDSS_DPSLP_REF_CTRL_PD_DPSLP;
    pd->dpslp_ref_ctrl = regVal;
#endif /* defined(CY_DEVICE_CCG6DF_CFP) */

    regVal = pd->cc_ctrl_0;
    regVal |= PDSS_CC_CTRL_0_TX_EN;
    regVal &= ~PDSS_CC_CTRL_0_PWR_DISABLE;
    regVal &= ~PDSS_CC_CTRL_0_CC_1V2;
    pd->cc_ctrl_0 = regVal;

    regVal = pd->tx_ctrl;
    regVal |= PDSS_TX_CTRL_TX_REG_EN;
    pd->tx_ctrl = regVal;

    regVal = pd->cc_ctrl_1;
    regVal &= ~PDSS_CC_CTRL_1_VTX_SEL_MASK;
    pd->cc_ctrl_1 = regVal;

    regVal = pd->debug_cc_0;
    regVal |= PDSS_DEBUG_CC_0_TX_CC_DRIVE_SRC;
    regVal &= ~PDSS_DEBUG_CC_0_TX_CC_DATA;
    pd->debug_cc_0 = regVal;

    Cy_SysLib_ExitCriticalSection(intr_state);
}
/*******************************************************************************
* Function Name: Cy_USBPD_TypeC_SetCC_to_PrevState
****************************************************************************//**
*
* This function restores all the registers back. When Cy_USBPD_TypeC_SetCC_to_0V() call
* is made, cc registers are updated to put zero volt on cc lines and therefore after all that
* this function is called to restore registers back.
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \return
*  None
*******************************************************************************/
void Cy_USBPD_TypeC_SetCC_to_PrevState(cy_stc_usbpd_context_t *context)
{
    uint32_t intr_state;
    PPDSS_REGS_T pd = NULL;

    if (context == NULL)
    {
        return;
    }
    intr_state = Cy_SysLib_EnterCriticalSection();
    pd = context->base;
#if defined(CY_DEVICE_CCG6DF_CFP)
    pd->pd_ref_gen_ctrl = context->ccRegisters[0];
#else
#if (!defined(CY_DEVICE_CCG3))
    pd->dpslp_ref_ctrl = context->ccRegisters[0];
#endif /* (!defined(CY_DEVICE_CCG3)) */
#endif /* defined(CY_DEVICE_CCG6DF_CFP) */
    pd->cc_ctrl_0 = context->ccRegisters[1];
    pd->tx_ctrl = context->ccRegisters[2];
    pd->cc_ctrl_1 = context->ccRegisters[3];
    pd->debug_cc_0 = context->ccRegisters[4];
    Cy_SysLib_DelayUs(10);

    Cy_SysLib_ExitCriticalSection(intr_state);
}

#endif /* (defined(CY_IP_MXUSBPD) || defined(CY_IP_M0S8USBPD)) */


/* [] END OF FILE */
