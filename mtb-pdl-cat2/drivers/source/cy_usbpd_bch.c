/***************************************************************************//**
* \file cy_usbpd_bch.c
* \version 2.110
*
* Provides implementation of legacy battery charging support functions using
* the USBPD IP.
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
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

#include "cy_device.h"
#include "cy_device_headers.h"

#if (defined(CY_IP_MXUSBPD) || defined(CY_IP_M0S8USBPD))

#if (!defined(CY_DEVICE_CCG6DF_CFP))
#include <cy_usbpd_defines.h>
#include <cy_usbpd_bch.h>
#include <cy_usbpd_common.h>

#define CHGB_AFC_INTR4_PORT0_ALL_INTR_BIT_MASK      (0x11111001u)
#define CHGB_AFC_INTR4_PORT1_ALL_INTR_BIT_MASK      (0x22222002u)

/*******************************************************************************
* Function Name: Cy_USBPD_Bch_Phy_Init
****************************************************************************//**
*
* This function initializes the charger detect block and registers a callback
* function with the charger detect PHY layer.
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \param bcPhyCbk
* Battery Charging Event Callback function pointer. Must be non-NULL.
*
* \return
* \ref cy_en_usbpd_status_t
*
*******************************************************************************/
cy_en_usbpd_status_t Cy_USBPD_Bch_Phy_Init(cy_stc_usbpd_context_t *context, cy_cb_bc_phy_events_t bcPhyCbk)
{
    cy_en_usbpd_status_t stat = CY_USBPD_STAT_BAD_PARAM;
    if (context == NULL)
    {
        return stat;
    }
#if (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2))
    /* Defines which DP/DM lines to be routed to */
    uint8_t chgb_id = context->port;
#if CY_FLIPPED_DP_DM
    /* For CCG3PA applications which require the block to be routed to DP1/DM1 */
    chgb_id = (chgb_id == 0u) ? 1u : 0u;
#endif /* CY_FLIPPED_DP_DM */
#else /* !(defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2)) */
    uint8_t chgb_id = 0;
    (void)chgb_id;
#endif /* (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2)) */

#if (CCG_TYPE_A_PORT_ENABLE == 0)
    if (context->port < NO_OF_TYPEC_PORTS)
#else
    if (context->port < 2)
#endif
    {
        PPDSS_REGS_T pd;

            if (bcPhyCbk != NULL)
            {
                pd = context->base;
                context->bcPhyCbk = bcPhyCbk;

#if defined(CY_IP_MXUSBPD)
                pd->intr9_cfg_bch_det[chgb_id] &= ~(PDSS_INTR9_CFG_BCH_DET_BCH_DET_COMP0_FILT_EN |
                    PDSS_INTR9_CFG_BCH_DET_BCH_DET_COMP0_CFG_MASK |
                    PDSS_INTR9_CFG_BCH_DET_BCH_DET_COMP0_FILT_SEL_MASK |
                    PDSS_INTR9_CFG_BCH_DET_BCH_DET_COMP1_FILT_EN  |
                    PDSS_INTR9_CFG_BCH_DET_BCH_DET_COMP1_CFG_MASK |
                    PDSS_INTR9_CFG_BCH_DET_BCH_DET_COMP1_FILT_SEL_MASK);
            stat = CY_USBPD_STAT_SUCCESS;
#elif defined(CY_IP_M0S8USBPD)
            pd->intr3_cfg_0 &= ~(PDSS_INTR3_CFG_0_CHGDET_FILT_EN |
                    PDSS_INTR3_CFG_0_CHGDET_CFG_MASK |
                    PDSS_INTR3_CFG_0_CHGDET_FILT_SEL_MASK);
            stat = CY_USBPD_STAT_SUCCESS;
#else
            stat = CY_USBPD_STAT_NOT_SUPPORTED;
#endif /* defined(CY_IP_MXUSBPD) */
        }
    }

    return stat;
}

/*******************************************************************************
* Function Name: Cy_USBPD_Bch_Phy_En
****************************************************************************//**
*
* This function enables the charging block hardware. The Cy_USBPD_Bch_Phy_Init
* function should previously have been called to initialize the block.
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \return
* \ref cy_en_usbpd_status_t
*
*******************************************************************************/
cy_en_usbpd_status_t Cy_USBPD_Bch_Phy_En(cy_stc_usbpd_context_t *context)
{
    cy_en_usbpd_status_t stat = CY_USBPD_STAT_NOT_SUPPORTED;
    uint8_t cport=context->port;
#if (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2))
    /* Defines which DP/DM lines to be routed to */
    uint8_t chgb_id = cport;
#if CY_FLIPPED_DP_DM
    /* For CCG3PA applications which require the block to be routed to DP1/DM1 */
    chgb_id = (chgb_id == 0u) ? 1u : 0u;
#endif /* CY_FLIPPED_DP_DM */
#else /* !(defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2)) */
    uint8_t chgb_id = 0;
    (void)chgb_id;
#endif /* (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2)) */

#if (CCG_TYPE_A_PORT_ENABLE == 0)
    if (cport < NO_OF_TYPEC_PORTS)
#else
    if (cport < 2u)
#endif
    {
#if defined(CY_IP_MXUSBPD)
    PPDSS_REGS_T pd = context->base ;

    /* Enable Charger detect block */
    pd->bch_det_0_ctrl[chgb_id] = PDSS_BCH_DET_0_CTRL_EN_CHGDET;
    pd->bch_det_1_ctrl[chgb_id] = PDSS_BCH_DET_1_CTRL_CHGDET_ISO_N;

#if (defined(CY_DEVICE_CCG6))
    /* Connect the charger detect block to the D+/D- signals on the appropriate side of the Type-C connector. */
    if ((context->dpmGetConfig())->polarity != 0u)
    {
        pd->dpdm_ctrl = (pd->dpdm_ctrl & ~((uint32_t)PDSS_DPDM_CTRL_DPDM_T_DPDM_MASK)) |
            (2UL << PDSS_DPDM_CTRL_DPDM_T_DPDM_POS);
    }
    else
    {
        pd->dpdm_ctrl = (pd->dpdm_ctrl & ~((uint32_t)PDSS_DPDM_CTRL_DPDM_T_DPDM_MASK)) |
            (8UL << PDSS_DPDM_CTRL_DPDM_T_DPDM_POS);
    }
#endif /* (defined(CY_DEVICE_CCG6)) */

#if (!(QC_SRC_AFC_CHARGING_DISABLED || QC_AFC_CHARGING_DISABLED))
#if (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2))
    pd->ctrl |= (1u << (PDSS_CTRL_AFC_ENABLED_POS + cport));
#else
#if (!defined(CY_DEVICE_PMG1S3))
    pd->ctrl |= (uint32_t)PDSS_CTRL_AFC_ENABLED;
#endif /* (!defined(CY_DEVICE_PMG1S3)) */
#endif /* defined(CY_DEVICE_CCG3PA) */
#endif /* !QC_AFC_CHARGING_DISABLED */

    Cy_SysLib_DelayUs(50);
    stat = CY_USBPD_STAT_SUCCESS;

#elif defined(CY_IP_M0S8USBPD)
    PPDSS_REGS_T pd = context->base;

    pd->chgdet_ctrl_0 = PDSS_CHGDET_CTRL_0_EN_CHGDET;
    pd->chgdet_ctrl_1 = PDSS_CHGDET_CTRL_1_CHGDET_ISO_N;
    stat = CY_USBPD_STAT_SUCCESS;
#else
    CY_UNUSED_PARAMETER(context);
#endif /* CY_IP */
    }

    return stat;
}

/*******************************************************************************
* Function Name: Cy_USBPD_Bch_Phy_Dis
****************************************************************************//**
*
* This function disables the charging block hardware in the USB-PD IP.
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \return
* \ref cy_en_usbpd_status_t
*
*******************************************************************************/
cy_en_usbpd_status_t Cy_USBPD_Bch_Phy_Dis(cy_stc_usbpd_context_t *context)
{
    cy_en_usbpd_status_t stat = CY_USBPD_STAT_NOT_SUPPORTED;
    uint8_t cport=context->port;
#if (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2))
    /* Defines which DP/DM lines to be routed to */
    uint8_t chgb_id = cport;
#if CY_FLIPPED_DP_DM
    /* For CCG3PA applications which require the block to be routed to DP1/DM1 */
    chgb_id = (chgb_id == 0u) ? 1u : 0u;
#endif /* CY_FLIPPED_DP_DM */
#else /* !(defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2)) */
    uint8_t chgb_id = 0;
    (void)chgb_id;
#endif /* (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2)) */

#if (CCG_TYPE_A_PORT_ENABLE == 0)
    if (cport < NO_OF_TYPEC_PORTS)
#else
    if (cport < 2u)
#endif
    {
#if defined(CY_IP_MXUSBPD)
    PPDSS_REGS_T pd = context->base;

    /* Power down the charger detect block. */
    pd->bch_det_1_ctrl[chgb_id] = 0;
    pd->bch_det_0_ctrl[chgb_id] = PDSS_BCH_DET_0_CTRL_PD;

    /* Disable and clear all interrupts */
    pd->intr9_mask &= ~((uint32_t)BCH_PORT_0_CMP1_2_INTR_MASK << (chgb_id << 1u));
    pd->intr9 = (uint32_t)BCH_PORT_0_CMP1_2_INTR_MASK << (chgb_id << 1u);

#if (!QC_AFC_CHARGING_DISABLED)
        (void)Cy_USBPD_Bch_QcSrcContModeStop(context);
        (void)Cy_USBPD_Bch_AfcSrcStop(context);
#endif /* (!QC_AFC_CHARGING_DISABLED) */

#if (defined(CY_DEVICE_CCG6))
    /* Isolate the charge detect block from the DP DM lines */
    pd->dpdm_ctrl &= ~((uint32_t)(PDSS_DPDM_CTRL_DPDM_T_DPDM_MASK | PDSS_DPDM_CTRL_DCP_SHORT_DPDM_TOP |
            PDSS_DPDM_CTRL_DCP_SHORT_DPDM_BOTTOM));
#else
#if !QC_AFC_CHARGING_DISABLED
#if (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2))
        pd->ctrl &= ~(1 << (PDSS_CTRL_AFC_ENABLED_POS + cport));
#else /* !(defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2)) */
        pd->ctrl &= ~(PDSS_CTRL_AFC_ENABLED);
#endif /* (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2)) */
#endif /* !QC_AFC_CHARGING_DISABLED  */
#endif /* (defined(CCG6) || defined(CCG5C)) */

    stat = CY_USBPD_STAT_SUCCESS;

#elif defined(CY_IP_M0S8USBPD)
    PPDSS_REGS_T pd = context->base;

    /* Disable and clear charger detect interrupts. */
    pd->intr3_mask &= ~(PDSS_INTR3_MASK_CHGDET_CHANGED_MASK);
    pd->intr3 = PDSS_INTR3_CHGDET_CHANGED;

    /* Disable the charger detect block. */
    pd->chgdet_ctrl_1 = PDSS_CHGDET_CTRL_1_DEFAULT;
    pd->chgdet_ctrl_0 = PDSS_CHGDET_CTRL_0_DEFAULT;

    stat = CY_USBPD_STAT_SUCCESS;
#else
    CY_UNUSED_PARAMETER(context);
#endif /* CY_IP */
    }
    else
     {
        CY_UNUSED_PARAMETER(context);
     }
    return stat;
}

/*******************************************************************************
* Function Name: Cy_USBPD_Bch_Phy_ConfigSrcTerm
****************************************************************************//**
*
* This function applies the desired source terminations on D+/D- lines.
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \param chargerTerm
* Charger Terminations as per the required protocol
*
* \return
* \ref cy_en_usbpd_status_t
*
*******************************************************************************/
cy_en_usbpd_status_t Cy_USBPD_Bch_Phy_ConfigSrcTerm(cy_stc_usbpd_context_t *context,
        cy_en_usbpd_bch_src_term_t chargerTerm)
{
    cy_en_usbpd_status_t status = CY_USBPD_STAT_SUCCESS;

#if (defined(CY_IP_MXUSBPD) && (!CY_PD_SINK_ONLY))
#if (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2))
    /* Defines which DP/DM lines to be routed to */
    uint8_t chgb_id = context->port;
#if CY_FLIPPED_DP_DM
    chgb_id = (chgb_id == 0u) ? 1u : 0u;
#endif /* CY_FLIPPED_DP_DM */
#else /* !(defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2)) */
    uint8_t chgb_id = 0;
#endif /* (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2)) */
    PPDSS_REGS_T pd = context->base;

    /* Remove any existing terminations. */
    (void)Cy_USBPD_Bch_Phy_RemoveTerm(context);

#if (defined(CY_DEVICE_CCG6))
    uint32_t regval = pd->dpdm_ctrl & ~PDSS_DPDM_CTRL_DPDM_T_DPDM_MASK;

    /* Make sure DP/DM connection to SYS side is disabled in all modes other than SDP/CDP. */
    if ((chargerTerm != CHGB_SRC_TERM_CDP) && (chargerTerm != CHGB_SRC_TERM_SDP))
    {
        regval &= ~(PDSS_DPDM_CTRL_DPDM_ISO_N | PDSS_DPDM_CTRL_DPDM_SWITCH_CTRL_MASK);
    }

    /* Make sure that charger detect block is connected to the correct set of D+/D- lines. */
    if ((context->dpmGetConfig())->polarity != 0u)
    {
        pd->dpdm_ctrl = regval | (uint32_t)(2UL << PDSS_DPDM_CTRL_DPDM_T_DPDM_POS);
    }
    else
    {
        pd->dpdm_ctrl = regval | (uint32_t)(8UL << PDSS_DPDM_CTRL_DPDM_T_DPDM_POS);
    }

    Cy_SysLib_DelayUs(10);
#endif /* (CY_DEVICE_CCG6) */

    switch(chargerTerm)
    {
        case CHGB_SRC_TERM_APPLE_1A:
            pd->bch_det_1_ctrl[chgb_id] |= ((1UL << PDSS_BCH_DET_1_CTRL_CHGDET_APPLE_MODE_DP_POS) |
                (2UL << PDSS_BCH_DET_1_CTRL_CHGDET_APPLE_MODE_DM_POS) |
                PDSS_BCH_DET_1_CTRL_CHGDET_APP_DET);
            pd->bch_det_0_ctrl[chgb_id] |= (PDSS_BCH_DET_0_CTRL_VDM_SRC_EN);
            break;

        case CHGB_SRC_TERM_APPLE_2_1A:
            pd->bch_det_1_ctrl[chgb_id] |= ((2UL << PDSS_BCH_DET_1_CTRL_CHGDET_APPLE_MODE_DP_POS) |
                (1UL << PDSS_BCH_DET_1_CTRL_CHGDET_APPLE_MODE_DM_POS) |
                PDSS_BCH_DET_1_CTRL_CHGDET_APP_DET);
            pd->bch_det_0_ctrl[chgb_id] |= (PDSS_BCH_DET_0_CTRL_VDP_SRC_EN);
            break;

        case CHGB_SRC_TERM_APPLE_2_4A:
            pd->bch_det_1_ctrl[chgb_id] |= ((2UL << PDSS_BCH_DET_1_CTRL_CHGDET_APPLE_MODE_DP_POS) |
#if (defined(CY_DEVICE_PAG1S) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
#if ENABLE_APPLE_BC12_SUPPORT
                ((uint32_t)1u << PDSS_BCH_DET_1_CTRL_APPLE_TERM_POS) |
#endif /* ENABLE_APPLE_BC12_SUPPORT */
#endif /* (defined(CY_DEVICE_PAG1S) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) */
                    (2UL << PDSS_BCH_DET_1_CTRL_CHGDET_APPLE_MODE_DM_POS) |
                 PDSS_BCH_DET_1_CTRL_CHGDET_APP_DET);
            pd->bch_det_0_ctrl[chgb_id] |= (PDSS_BCH_DET_0_CTRL_VDP_SRC_EN |
                    PDSS_BCH_DET_0_CTRL_VDM_SRC_EN);
            break;

#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
        case CHGB_SRC_TERM_APPLE_3A:
                pd->bch_det_1_ctrl[chgb_id] |= (((uint32_t)2u << PDSS_BCH_DET_1_CTRL_CHGDET_APPLE_MODE_DP_POS)
#if ENABLE_APPLE_BC12_SUPPORT
                | ((uint32_t)1u << PDSS_BCH_DET_1_CTRL_APPLE_TERM_POS)
#endif /* ENABLE_APPLE_BC12_SUPPORT */
                );
                pd->bch_det_0_ctrl[chgb_id] |= (PDSS_BCH_DET_0_CTRL_VDP_SRC_EN |
                    PDSS_BCH_DET_0_CTRL_RDM_PD_EN | PDSS_BCH_DET_0_CTRL_RDM_PU_EN);
            break;
#endif /* (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) */


#if (!QC_AFC_CHARGING_DISABLED)
        case CHGB_SRC_TERM_QC:
        case CHGB_SRC_TERM_AFC:
            pd->bch_det_0_ctrl[chgb_id] |= (PDSS_BCH_DET_0_CTRL_RDM_PD_EN |
                PDSS_BCH_DET_0_CTRL_RDAT_LKG_DP_EN);
            break;
#endif /* (!QC_AFC_CHARGING_DISABLED) */

        case CHGB_SRC_TERM_DCP:
#if (defined(CY_DEVICE_CCG6))
            if ((context->dpmGetConfig())->polarity != 0u)
            {
                pd->dpdm_ctrl |= PDSS_DPDM_CTRL_DCP_SHORT_DPDM_BOTTOM;
            }
            else
            {
                pd->dpdm_ctrl |= PDSS_DPDM_CTRL_DCP_SHORT_DPDM_TOP;
            }
#endif /* (defined(CY_DEVICE_CCG6)) */
            pd->bch_det_0_ctrl[chgb_id] |= (PDSS_BCH_DET_0_CTRL_DCP_EN | PDSS_BCH_DET_0_CTRL_RDAT_LKG_DP_EN);
            break;

        case CHGB_SRC_TERM_SDP:
            pd->bch_det_0_ctrl[chgb_id] |= (PDSS_BCH_DET_0_CTRL_RDP_PD_EN | PDSS_BCH_DET_0_CTRL_RDM_PD_EN);
            break;

        case CHGB_SRC_TERM_CDP:
            pd->bch_det_0_ctrl[chgb_id] |= (PDSS_BCH_DET_0_CTRL_RDP_PD_EN | PDSS_BCH_DET_0_CTRL_RDM_PD_EN | PDSS_BCH_DET_0_CTRL_IDP_SNK_EN);
            break;

        default:
            status = CY_USBPD_STAT_BAD_PARAM;
            break;
    }

#elif (defined(CY_IP_M0S8USBPD) && (!CY_PD_SINK_ONLY))

    PPDSS_REGS_T pd = context->base;

    /* Remove any existing terminations. */
    (void)Cy_USBPD_Bch_Phy_RemoveTerm(context);

    switch(chargerTerm)
    {
        case CHGB_SRC_TERM_APPLE_1A:
            pd->chgdet_ctrl_1 |= ((1UL << PDSS_CHGDET_CTRL_1_CHGDET_APPLE_MODE_DP_POS) |
                    (2UL << PDSS_CHGDET_CTRL_1_CHGDET_APPLE_MODE_DM_POS) |
                    PDSS_CHGDET_CTRL_1_CHGDET_APP_DET);
            pd->chgdet_ctrl_0 |= PDSS_CHGDET_CTRL_0_VDM_SRC_EN;
            break;

        case CHGB_SRC_TERM_APPLE_2_1A:
            pd->chgdet_ctrl_1 |= ((2UL << PDSS_CHGDET_CTRL_1_CHGDET_APPLE_MODE_DP_POS) |
                    (1UL << PDSS_CHGDET_CTRL_1_CHGDET_APPLE_MODE_DM_POS) |
                    PDSS_CHGDET_CTRL_1_CHGDET_APP_DET);
            pd->chgdet_ctrl_0 |= PDSS_CHGDET_CTRL_0_VDP_SRC_EN;
            break;

        case CHGB_SRC_TERM_APPLE_2_4A:
            pd->chgdet_ctrl_1 |= ((2UL << PDSS_CHGDET_CTRL_1_CHGDET_APPLE_MODE_DP_POS) |
                    (2UL << PDSS_CHGDET_CTRL_1_CHGDET_APPLE_MODE_DM_POS) |
                    PDSS_CHGDET_CTRL_1_CHGDET_APP_DET);
            pd->chgdet_ctrl_0 |= PDSS_CHGDET_CTRL_0_VDP_SRC_EN | PDSS_CHGDET_CTRL_0_VDM_SRC_EN;
            break;

        case CHGB_SRC_TERM_DCP:
            pd->chgdet_ctrl_0 |= (PDSS_CHGDET_CTRL_0_DCP_EN | PDSS_CHGDET_CTRL_0_RDAT_LKG_DP_EN);
            break;

        case CHGB_SRC_TERM_SDP:
            pd->chgdet_ctrl_0 |= (PDSS_CHGDET_CTRL_0_RDP_PD_EN | PDSS_CHGDET_CTRL_0_RDM_PD_EN);
            break;

        case CHGB_SRC_TERM_CDP:
            pd->chgdet_ctrl_0 |= PDSS_CHGDET_CTRL_0_IDP_SNK_EN;
            break;

        default:
            status = CY_USBPD_STAT_BAD_PARAM;
            break;
    }
#else
    CY_UNUSED_PARAMETER(context);
    CY_UNUSED_PARAMETER(chargerTerm);
    status = CY_USBPD_STAT_NOT_SUPPORTED;
#endif /* CY_IP */

    return status;
}

/*******************************************************************************
* Function Name: Cy_USBPD_Bch_Phy_ConfigSnkTerm
****************************************************************************//**
*
* This function applies the desired sink terminations on D+/D- lines.
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \param chargerTerm
* Sink Terminations to be applied.
*
* \return
* \ref cy_en_usbpd_status_t
*
*******************************************************************************/
cy_en_usbpd_status_t Cy_USBPD_Bch_Phy_ConfigSnkTerm(cy_stc_usbpd_context_t *context,
        cy_en_usbpd_bch_snk_term_t chargerTerm)
{
    cy_en_usbpd_status_t status = CY_USBPD_STAT_SUCCESS;

#if defined(CY_IP_MXUSBPD)
#if (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2))
    /* Defines which DP/DM lines to be routed to */
    uint8_t chgb_id = context->port;
#if CY_FLIPPED_DP_DM
    chgb_id = (chgb_id == 0u) ? 1u : 0u;
#endif /* CY_FLIPPED_DP_DM */
#else /* !(defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2)) */
    uint8_t chgb_id = 0;
#endif /* (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2)) */
    PPDSS_REGS_T pd = context->base ;

#ifdef CY_DEVICE_CCG6
    /* Connect the charger detect block to the D+/D- pins from the active side of the Type-C connector. */
    if ((context->dpmGetConfig())->polarity != 0u)
    {
        pd->dpdm_ctrl = (pd->dpdm_ctrl & ~((uint32_t)PDSS_DPDM_CTRL_DPDM_T_DPDM_MASK)) |
            (2UL << PDSS_DPDM_CTRL_DPDM_T_DPDM_POS);
    }
    else
    {
        pd->dpdm_ctrl = (pd->dpdm_ctrl & ~((uint32_t)PDSS_DPDM_CTRL_DPDM_T_DPDM_MASK)) |
            (8UL << PDSS_DPDM_CTRL_DPDM_T_DPDM_POS);
    }
    Cy_SysLib_DelayUs(10);
#endif /* CY_DEVICE_CCG6 */

    switch(chargerTerm)
    {
        case CHGB_SINK_TERM_SPD:
            /* Pull up on D+ */
            pd->bch_det_0_ctrl[chgb_id] |= PDSS_BCH_DET_0_CTRL_RDP_PU_EN;
            break;

        case CHGB_SINK_TERM_PCD:
            /* Connect VDP_SRC and IDM_SINK. */
            pd->bch_det_0_ctrl[chgb_id] |= (PDSS_BCH_DET_0_CTRL_VDP_SRC_EN | PDSS_BCH_DET_0_CTRL_IDM_SNK_EN);
            break;

        case CHGB_SINK_TERM_SCD:
            /* Connect VDM_SRC and IDP_SINK. */
            pd->bch_det_0_ctrl[chgb_id] |= (PDSS_BCH_DET_0_CTRL_VDM_SRC_EN | PDSS_BCH_DET_0_CTRL_IDP_SNK_EN);
            break;

#if (!QC_AFC_CHARGING_DISABLED)
        case CHGB_SINK_TERM_AFC:
        case CHGB_SINK_TERM_QC_5V:
            /* 0.6 on D+, D- HiZ */
            pd->bch_det_0_ctrl[chgb_id] |= PDSS_BCH_DET_0_CTRL_VDP_SRC_EN;
            /* Remove other terms */
            pd->bch_det_0_ctrl[chgb_id] &= ~ (PDSS_BCH_DET_0_CTRL_RDP_PU_EN |
                    PDSS_BCH_DET_0_CTRL_RDM_PU_EN |
                    PDSS_BCH_DET_0_CTRL_VDM_SRC_EN |
                    PDSS_BCH_DET_0_CTRL_IDM_SNK_EN);
            break;
        case CHGB_SINK_TERM_QC_9V:
            /* 3.3V on D+, 0.6 on D- */
            pd->bch_det_0_ctrl[chgb_id] |= PDSS_BCH_DET_0_CTRL_RDP_PU_EN | PDSS_BCH_DET_0_CTRL_VDM_SRC_EN ;

            /* Remove other terms */
            pd->bch_det_0_ctrl[chgb_id] &= ~ ( PDSS_BCH_DET_0_CTRL_RDM_PU_EN |
                                   PDSS_BCH_DET_0_CTRL_RDM_PD_EN |
                                   PDSS_BCH_DET_0_CTRL_VDP_SRC_EN |
                                   PDSS_BCH_DET_0_CTRL_IDM_SNK_EN);
            break;
        case CHGB_SINK_TERM_QC_12V:            /* 0.6 on D+, 0.6 on D- */
            pd->bch_det_0_ctrl[chgb_id] |= (PDSS_BCH_DET_0_CTRL_VDP_SRC_EN | PDSS_BCH_DET_0_CTRL_VDM_SRC_EN);

            /* Remove other terms */
            pd->bch_det_0_ctrl[chgb_id] &= ~ (PDSS_BCH_DET_0_CTRL_RDP_PU_EN |
                                    PDSS_BCH_DET_0_CTRL_RDM_PU_EN);
            break;
        case CHGB_SINK_TERM_QC_20V:
            /* 3.3V on D+, 3.3V on D- */
            pd->bch_det_0_ctrl[chgb_id] |= (PDSS_BCH_DET_0_CTRL_RDP_PU_EN | PDSS_BCH_DET_0_CTRL_RDM_PU_EN);

            /* Remove other terms */
            pd->bch_det_0_ctrl[chgb_id] &= ~ ( PDSS_BCH_DET_0_CTRL_VDM_SRC_EN |
                                    PDSS_BCH_DET_0_CTRL_VDP_SRC_EN);
            break;
#endif /* (!QC_AFC_CHARGING_DISABLED) */

        case CHGB_SINK_TERM_APPLE:
            (void)Cy_USBPD_Bch_Phy_RemoveTerm(context);
            break;

        default:
            status = CY_USBPD_STAT_BAD_PARAM;
            break;
    }

#elif defined(CY_IP_M0S8USBPD)

    PPDSS_REGS_T pd = context->base ;

    switch(chargerTerm)
    {
        case CHGB_SINK_TERM_SPD:
            pd->chgdet_ctrl_0 |= PDSS_CHGDET_CTRL_0_RDP_PU_EN;
            break;

        case CHGB_SINK_TERM_PCD:
            pd->chgdet_ctrl_0 |= PDSS_CHGDET_CTRL_0_VDP_SRC_EN | PDSS_CHGDET_CTRL_0_IDM_SNK_EN;
            break;

        case CHGB_SINK_TERM_SCD:
            pd->chgdet_ctrl_0 |= PDSS_CHGDET_CTRL_0_VDM_SRC_EN | PDSS_CHGDET_CTRL_0_IDP_SNK_EN;
            break;

        case CHGB_SINK_TERM_APPLE:
            (void)Cy_USBPD_Bch_Phy_RemoveTerm(context);
            break;

        default:
            status = CY_USBPD_STAT_BAD_PARAM;
            break;
    }
#else
    CY_UNUSED_PARAMETER(context);
    CY_UNUSED_PARAMETER(chargerTerm);
    status = CY_USBPD_STAT_NOT_SUPPORTED;
#endif /* CY_IP */

    return status;
}

/*******************************************************************************
* Function Name: Cy_USBPD_Bch_Phy_RemoveTerm
****************************************************************************//**
*
* This function removes all terminations/voltage sources from D+/D- lines.
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \return
* \ref cy_en_usbpd_status_t
*
*******************************************************************************/
cy_en_usbpd_status_t Cy_USBPD_Bch_Phy_RemoveTerm(cy_stc_usbpd_context_t *context)
{
    cy_en_usbpd_status_t status = CY_USBPD_STAT_SUCCESS;

#if defined(CY_IP_MXUSBPD)
#if (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2))
    /* Defines which DP/DM lines to be routed to */
    uint8_t chgb_id = context->port;
#if CY_FLIPPED_DP_DM
    chgb_id = (chgb_id == 0u) ? 1u : 0u;
#endif /* CY_FLIPPED_DP_DM */
#else /* !(defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2)) */
    uint8_t chgb_id = 0;
#endif /* (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2)) */

    PPDSS_REGS_T pd = context->base;

    pd->bch_det_0_ctrl[chgb_id] &= ~(PDSS_BCH_DET_0_CTRL_IDP_SNK_EN |
            PDSS_BCH_DET_0_CTRL_IDM_SNK_EN |
            PDSS_BCH_DET_0_CTRL_VDP_SRC_EN |
            PDSS_BCH_DET_0_CTRL_VDM_SRC_EN |
            PDSS_BCH_DET_0_CTRL_IDP_SRC_EN |
            PDSS_BCH_DET_0_CTRL_DCP_EN |
            PDSS_BCH_DET_0_CTRL_RDM_PD_EN |
            PDSS_BCH_DET_0_CTRL_RDM_PU_EN |
            PDSS_BCH_DET_0_CTRL_RDP_PD_EN |
            PDSS_BCH_DET_0_CTRL_RDP_PU_EN |
            PDSS_BCH_DET_0_CTRL_RDAT_LKG_DP_EN |
            PDSS_BCH_DET_0_CTRL_RDAT_LKG_DM_EN );
    pd->bch_det_1_ctrl[chgb_id] = PDSS_BCH_DET_1_CTRL_CHGDET_ISO_N;

#if (defined(CY_DEVICE_CCG6))
    /* Make sure D+/D- short is removed. */
    pd->dpdm_ctrl &= ~(PDSS_DPDM_CTRL_DCP_SHORT_DPDM_BOTTOM | PDSS_DPDM_CTRL_DCP_SHORT_DPDM_BOTTOM);
#endif /* (defined(CY_DEVICE_CCG6)) */

#elif defined(CY_IP_M0S8USBPD)
    PPDSS_REGS_T pd = context->base;

    pd->chgdet_ctrl_0 &= ~(PDSS_CHGDET_CTRL_0_IDP_SNK_EN |
            PDSS_CHGDET_CTRL_0_IDM_SNK_EN |
            PDSS_CHGDET_CTRL_0_VDP_SRC_EN |
            PDSS_CHGDET_CTRL_0_VDM_SRC_EN |
            PDSS_CHGDET_CTRL_0_IDP_SRC_EN |
            PDSS_CHGDET_CTRL_0_DCP_EN |
            PDSS_CHGDET_CTRL_0_RDM_PD_EN |
            PDSS_CHGDET_CTRL_0_RDM_PU_EN |
            PDSS_CHGDET_CTRL_0_RDP_PD_EN |
            PDSS_CHGDET_CTRL_0_RDP_PU_EN |
            PDSS_CHGDET_CTRL_0_RDAT_LKG_DP_EN |
            PDSS_CHGDET_CTRL_0_RDAT_LKG_DM_EN);
    pd->chgdet_ctrl_1 &= ~(PDSS_CHGDET_CTRL_1_CHGDET_APP_DET |
            PDSS_CHGDET_CTRL_1_CHGDET_APPLE_MODE_DM_MASK |
            PDSS_CHGDET_CTRL_1_CHGDET_APPLE_MODE_DP_MASK);
#else
    CY_UNUSED_PARAMETER(context);
    status = CY_USBPD_STAT_NOT_SUPPORTED;
#endif /* CY_IP */

    return status;
}

/*******************************************************************************
* Function Name: Cy_USBPD_Bch_Phy_Config_Comp
****************************************************************************//**
*
* This function configures and enables one of the charger detect comparators.
* This can be used for a quick comparator state check or to configure the PHY to
* provide an interrupt callback when the comparator state changes
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \param compIdx
* Comparator index(0 or 1).
*
* \param pInput
* Positive input signal selection
*
* \param mInput
* Negative input signal selection
*
* \param vref
* Vref value to be used when either input selection is vref.
*
* \param edge
* Edge selection. If edge is selected, then callback registered in \ref
* Cy_USBPD_Bch_Phy_Init will be called when event fires. If edge is no
* interrupt, then this function will revert the comparator to its previous
* settings after comparison is done.
*
* \return Comparator output value.
*
*******************************************************************************/
bool Cy_USBPD_Bch_Phy_Config_Comp(cy_stc_usbpd_context_t *context,
                                  uint8_t compIdx,
                                  cy_en_usbpd_bch_comp_pinput_t pInput,
                                  cy_en_usbpd_bch_comp_ninput_t mInput,
                                  cy_en_usbpd_bch_vref_t vref,
                                  cy_en_usbpd_bch_comp_edge_t edge)
{
#if defined(CY_IP_MXUSBPD)
    uint8_t chgb_id = context->port;
#if defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2)
#if CY_FLIPPED_DP_DM
    chgb_id = (chgb_id == 0u) ? 1u : 0u;
#endif /* CY_FLIPPED_DP_DM */
#else
    chgb_id = 0;
#endif /* !(defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2)) */

    PPDSS_REGS_T pd = context->base ;
    uint32_t volatile *bch_ctrl_p;
    uint32_t volatile *cfg_bch_det_p;
    uint32_t regVal;
    uint32_t temp_bch_ctrl;
    uint32_t temp_intr_cfg;
    uint32_t temp_intr_mask;
    uint32_t intr_mask = ((uint32_t)BCH_PORT_0_CMP1_INTR_MASK << compIdx) << (chgb_id << 1);
    uint32_t cfg_clr_mask;
    uint32_t cfg_pos;
    uint32_t intr_state;
    uint32_t filt_bypass_bit_mask;
    uint32_t cfg_set_mask;
    bool result = false;

    intr_state = Cy_SysLib_EnterCriticalSection();

    cfg_bch_det_p = &pd->intr9_cfg_bch_det[chgb_id];

    if (compIdx == 0u)
    {
        bch_ctrl_p = &pd->bch_det_0_ctrl[chgb_id];
        cfg_clr_mask = PDSS_INTR9_CFG_BCH_DET_BCH_DET_COMP0_FILT_EN |
            PDSS_INTR9_CFG_BCH_DET_BCH_DET_COMP0_CFG_MASK |
            PDSS_INTR9_CFG_BCH_DET_BCH_DET_COMP0_FILT_SEL_MASK |
            PDSS_INTR9_CFG_BCH_DET_BCH_DET_COMP0_FILT_RESET;
        filt_bypass_bit_mask = PDSS_INTR9_CFG_BCH_DET_BCH_DET_COMP0_FILT_BYPASS;
        cfg_set_mask = PDSS_INTR9_CFG_BCH_DET_BCH_DET_COMP0_FILT_EN |
            (2UL << PDSS_INTR9_CFG_BCH_DET_BCH_DET_COMP0_FILT_SEL_POS);

        if (edge == CHGB_COMP_EDGE_FALLING)
        {
            cfg_set_mask |= PDSS_INTR9_CFG_BCH_DET_BCH_DET_COMP0_FILT_RESET;
        }
        cfg_pos = PDSS_INTR9_CFG_BCH_DET_BCH_DET_COMP0_CFG_POS;

    }
    else
    {
        bch_ctrl_p = &pd->bch_det_1_ctrl[chgb_id];
        cfg_clr_mask = PDSS_INTR9_CFG_BCH_DET_BCH_DET_COMP1_FILT_EN  |
                   PDSS_INTR9_CFG_BCH_DET_BCH_DET_COMP1_CFG_MASK |
                   PDSS_INTR9_CFG_BCH_DET_BCH_DET_COMP1_FILT_SEL_MASK |
                   PDSS_INTR9_CFG_BCH_DET_BCH_DET_COMP1_FILT_RESET;
        filt_bypass_bit_mask = PDSS_INTR9_CFG_BCH_DET_BCH_DET_COMP1_FILT_BYPASS;
        cfg_set_mask = PDSS_INTR9_CFG_BCH_DET_BCH_DET_COMP1_FILT_EN |
            (2UL << PDSS_INTR9_CFG_BCH_DET_BCH_DET_COMP1_FILT_SEL_POS);

        if (edge == CHGB_COMP_EDGE_FALLING)
        {
            cfg_set_mask |= PDSS_INTR9_CFG_BCH_DET_BCH_DET_COMP1_FILT_RESET;
        }
        cfg_pos = PDSS_INTR9_CFG_BCH_DET_BCH_DET_COMP1_CFG_POS;
    }

    temp_bch_ctrl = *bch_ctrl_p;
    temp_intr_cfg = *cfg_bch_det_p;
    temp_intr_mask =  pd->intr9_mask;

    regVal = temp_bch_ctrl;
    regVal &= ~(PDSS_BCH_DET_0_CTRL_CMP1_INN_SEL_MASK |
                PDSS_BCH_DET_0_CTRL_CMP1_INP_SEL_MASK |
                PDSS_BCH_DET_0_CTRL_CMP1_VREF_SEL_MASK |
                PDSS_BCH_DET_0_CTRL_CMP1_OFFSET_SEL_MASK |
                PDSS_BCH_DET_0_CTRL_CMP1_OFFSET_EN);
    regVal |= (((uint32_t)mInput << PDSS_BCH_DET_0_CTRL_CMP1_INN_SEL_POS) |
               ((uint32_t)pInput << PDSS_BCH_DET_0_CTRL_CMP1_INP_SEL_POS) |
               ((uint32_t)vref << PDSS_BCH_DET_0_CTRL_CMP1_VREF_SEL_POS) |
               (uint32_t)PDSS_BCH_DET_0_CTRL_EN_COMP1_CHGDET);

    if (vref == CHGB_VREF_0_325V)
    {
        /* The actual voltage needs to be 425 mV. Enable +100mV offset to get the desired voltage. */
        regVal |= ((5UL << PDSS_BCH_DET_0_CTRL_CMP1_OFFSET_SEL_POS) |
                (uint32_t)PDSS_BCH_DET_0_CTRL_CMP1_OFFSET_EN);
    }

    /* Enable comparator */
    *bch_ctrl_p = regVal;
    Cy_SysLib_DelayUs(10);

    if ((pd->intr9_status_0 & intr_mask) != 0u)
    {
        result = true;
    }

    /* Enable Interrupt and check if condition already exists */
    if(edge == CHGB_COMP_NO_INTR)
    {
        *bch_ctrl_p = temp_bch_ctrl;
        *cfg_bch_det_p &= ~cfg_clr_mask;
        *cfg_bch_det_p = temp_intr_cfg;
        Cy_SysLib_DelayUs(10);
        pd->intr9_mask = temp_intr_mask;
    }
    else
    {
        /* Configure edge detection. */
        *cfg_bch_det_p &= ~(cfg_clr_mask | filt_bypass_bit_mask);
        *cfg_bch_det_p |= ((uint32_t)edge << cfg_pos);
        *cfg_bch_det_p |= cfg_set_mask;

        /* Enable comparator interrupts. */
        pd->intr9_mask |= intr_mask;
    }

    /* Clear comparator interrupt. */
    pd->intr9 = intr_mask;

    Cy_SysLib_ExitCriticalSection(intr_state);
    return result;

#elif defined(CY_IP_M0S8USBPD)
    PPDSS_REGS_T pd = context->base ;
    bool result = false;
    uint32_t intr_state, regVal;

    CY_UNUSED_PARAMETER(compIdx);

    intr_state = Cy_SysLib_EnterCriticalSection();

    /* Disable all comparator interrupt configuration. */
    pd->intr3_cfg_0 &= ~(PDSS_INTR3_CFG_0_CHGDET_FILT_SEL_MASK |
            PDSS_INTR3_CFG_0_CHGDET_FILT_EN |
            PDSS_INTR3_CFG_0_CHGDET_CFG_MASK);

    pd->chgdet_ctrl_0 &= ~(PDSS_CHGDET_CTRL_0_CMP_INN_SEL_MASK |
            PDSS_CHGDET_CTRL_0_CMP_INP_SEL_MASK |
            PDSS_CHGDET_CTRL_0_VREF_SEL_MASK |
            PDSS_CHGDET_CTRL_0_CMP_OFFSET_SEL_MASK |
            PDSS_CHGDET_CTRL_0_CMPP_OFFSET_EN |
            PDSS_CHGDET_CTRL_0_EN_COMP_CHGDET);

    /* Configure the comparator inputs. */
    regVal = pd->chgdet_ctrl_0;
    regVal |= (((uint32_t)mInput << PDSS_CHGDET_CTRL_0_CMP_INN_SEL_POS) |
            ((uint32_t)pInput << PDSS_CHGDET_CTRL_0_CMP_INP_SEL_POS) |
            ((uint32_t)vref << PDSS_CHGDET_CTRL_0_VREF_SEL_POS) |
            (uint32_t)PDSS_CHGDET_CTRL_0_EN_COMP_CHGDET);
    if (vref == CHGB_VREF_0_325V)
    {
        regVal |= ((5UL << PDSS_CHGDET_CTRL_0_CMP_OFFSET_SEL_POS) |
                (uint32_t)PDSS_CHGDET_CTRL_0_CMPP_OFFSET_EN);
    }
    else
    {
        regVal |= ((4UL << PDSS_CHGDET_CTRL_0_CMP_OFFSET_SEL_POS) |
                (uint32_t)PDSS_CHGDET_CTRL_0_CMPP_OFFSET_EN);
    }

    /* Enable the comparator and apply a delay for checking. */
    pd->chgdet_ctrl_0 = regVal;
    Cy_SysLib_DelayUs(10);

    if ((pd->ncell_status & PDSS_NCELL_STATUS_CHGDET_STATUS) != 0u)
    {
        result = true;
    }

    if (edge != CHGB_COMP_NO_INTR)
    {
        /* Enable charger detect comparator interrupt. */
        pd->intr3_mask |= PDSS_INTR3_MASK_CHGDET_CHANGED_MASK;

        /* Enable detection of desired edge with 2 LF cycles of filtering. */
        pd->intr3_cfg_0 |= (PDSS_INTR3_CFG_0_CHGDET_FILT_EN |
                (2UL << PDSS_INTR3_CFG_0_CHGDET_FILT_SEL_POS) |
                ((uint32_t)edge << PDSS_INTR3_CFG_0_CHGDET_CFG_POS));
    }

    /* Clear any previous comparator interrupts. */
    pd->intr3 = PDSS_INTR3_CHGDET_CHANGED;

    Cy_SysLib_ExitCriticalSection(intr_state);
    return result;

#else
    CY_UNUSED_PARAMETER(context);
    CY_UNUSED_PARAMETER(compIdx);
    CY_UNUSED_PARAMETER(pInput);
    CY_UNUSED_PARAMETER(mInput);
    CY_UNUSED_PARAMETER(vref);
    CY_UNUSED_PARAMETER(edge);

    return false;
#endif /* CY_IP */
}

/*******************************************************************************
* Function Name: Cy_USBPD_Bch_Phy_DisableComp
****************************************************************************//**
*
* This function disables one of the charger detect comparators.
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \param compIdx
* Comparator index.
*
* \return
* \ref cy_en_usbpd_status_t
*
*******************************************************************************/
cy_en_usbpd_status_t Cy_USBPD_Bch_Phy_DisableComp(cy_stc_usbpd_context_t *context,
        uint8_t compIdx )
{
#if defined(CY_IP_MXUSBPD)
    uint8_t chgb_id = context->port;
#if defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2)
#if CY_FLIPPED_DP_DM
    chgb_id = (chgb_id == 0u) ? 1u : 0u;
#endif /* CY_FLIPPED_DP_DM */
#else /* !(defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2)) */
    chgb_id = 0;
#endif /* !(defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2)) */

    PPDSS_REGS_T pd = context->base;

    if(compIdx == 0u)
    {
        pd->bch_det_0_ctrl[chgb_id] &= ~PDSS_BCH_DET_0_CTRL_EN_COMP1_CHGDET;
        pd->intr9_mask &= ~(BCH_PORT_0_CMP1_INTR_MASK);
        pd->intr9 = BCH_PORT_0_CMP1_INTR_MASK;
        pd->intr9_cfg_bch_det[chgb_id] &= ~PDSS_INTR9_CFG_BCH_DET_BCH_DET_COMP0_FILT_EN;
    }
    else
    {
        pd->bch_det_1_ctrl[chgb_id] &= ~PDSS_BCH_DET_1_CTRL_EN_COMP2_CHGDET;
        pd->intr9_mask &= ~(BCH_PORT_0_CMP2_INTR_MASK);
        pd->intr9 = BCH_PORT_0_CMP2_INTR_MASK;
        pd->intr9_cfg_bch_det[chgb_id] &= ~PDSS_INTR9_CFG_BCH_DET_BCH_DET_COMP1_FILT_EN;
    }
#elif defined(CY_IP_M0S8USBPD)
    PPDSS_REGS_T pd = context->base;

    CY_UNUSED_PARAMETER(compIdx);
    pd->chgdet_ctrl_0 &= ~(PDSS_CHGDET_CTRL_0_EN_COMP_CHGDET);
    pd->intr3          = PDSS_INTR3_CHGDET_CHANGED;
    pd->intr3_mask    &= ~(PDSS_INTR3_MASK_CHGDET_CHANGED_MASK);
    pd->intr3_cfg_0   &= ~(PDSS_INTR3_CFG_0_CHGDET_FILT_EN);
#else
    CY_UNUSED_PARAMETER(context);
    CY_UNUSED_PARAMETER(compIdx);
#endif /* CY_IP */

    return CY_USBPD_STAT_SUCCESS;
}

/*******************************************************************************
* Function Name: Cy_USBPD_Bch_Phy_Isolate_DpDm
****************************************************************************//**
*
* This function isolates the charge detect block from D+/D- lines.
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \return
* \ref cy_en_usbpd_status_t
*
*******************************************************************************/
cy_en_usbpd_status_t Cy_USBPD_Bch_Phy_Isolate_DpDm(cy_stc_usbpd_context_t *context)
{
#if (defined(CY_DEVICE_CCG6))
    PPDSS_REGS_T pd = context->base ;

    /* Isolate charge detect block from DP and DM lines */
    pd->dpdm_ctrl &= ~((uint32_t)PDSS_DPDM_CTRL_DPDM_T_DPDM_MASK);

    return CY_USBPD_STAT_SUCCESS;
#else
    CY_UNUSED_PARAMETER(context);
    return CY_USBPD_STAT_NOT_SUPPORTED;
#endif /* (defined(CY_DEVICE_CCG6)) */
}

/*******************************************************************************
* Function Name: Cy_USBPD_Bch_Phy_CompResult
****************************************************************************//**
*
* This function checks and returns the comparator output.
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \param compIdx
* Comparator index.
*
* \return
* Comparator Output
*
*******************************************************************************/
bool Cy_USBPD_Bch_Phy_CompResult(cy_stc_usbpd_context_t *context, uint8_t compIdx)
{
    bool retVal = false;
#if (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2))
    uint8_t chgb_id = context->port;
#if CY_FLIPPED_DP_DM
    chgb_id = (chgb_id == 0u) ? 1u : 0u;
#endif /* CY_FLIPPED_DP_DM */
#endif /* (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2)) */

#if defined(CY_IP_MXUSBPD)
    PPDSS_REGS_T pd = context->base ;

    if(compIdx == 0u)
    {
#if (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2))
        if ((pd->intr9_status_0 & ((uint32_t)BCH_PORT_0_CMP1_INTR_MASK << (chgb_id << 1))) != 0u)
#else
        if ((pd->intr9_status_0 & (uint32_t)(BCH_PORT_0_CMP1_INTR_MASK)) != 0u)
#endif /* (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2)) */
        {
            retVal = true;
        }
    }
    else
    {
#if (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2))
        if ((pd->intr9_status_0 & ((uint32_t)BCH_PORT_0_CMP2_INTR_MASK << (chgb_id << 1))) != 0u)
#else
        if ((pd->intr9_status_0 & (uint32_t)(BCH_PORT_0_CMP2_INTR_MASK)) != 0u)
#endif /* (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2)) */
        {
            retVal = true;
        }
    }
#elif defined(CY_IP_M0S8USBPD)
    PPDSS_REGS_T pd = context->base ;

    CY_UNUSED_PARAMETER(compIdx);
    if ((pd->ncell_status & PDSS_NCELL_STATUS_CHGDET_STATUS) != 0u)
    {
        retVal = true;
    }
#else
    CY_UNUSED_PARAMETER(context);
    CY_UNUSED_PARAMETER(compIdx);
#endif /* CY_IP */

    return retVal;
}

/*******************************************************************************
* Function Name: Cy_USBPD_Bch_ApplyDpPd
****************************************************************************//**
*
* This function applies pulldown on D+.
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \return
* \ref cy_en_usbpd_status_t
*
*******************************************************************************/
cy_en_usbpd_status_t Cy_USBPD_Bch_ApplyDpPd(cy_stc_usbpd_context_t *context)
{
#if defined(CY_IP_MXUSBPD)
#if (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2))
    uint8_t chgb_id = context->port;
#if CY_FLIPPED_DP_DM
    chgb_id = (chgb_id == 0u) ? 1u : 0u;
#endif /* CY_FLIPPED_DP_DM */
#else /* !(defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2)) */
    uint8_t chgb_id = 0;
#endif /* (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2)) */
    context->base->bch_det_0_ctrl[chgb_id] |= PDSS_BCH_DET_0_CTRL_RDP_PD_EN;
#elif defined(CY_IP_M0S8USBPD)
    context->base->chgdet_ctrl_0 |= PDSS_CHGDET_CTRL_0_RDP_PD_EN;
#else
    CY_UNUSED_PARAMETER(context);
#endif /* CY_IP */

    return CY_USBPD_STAT_SUCCESS;
}

/*******************************************************************************
* Function Name: Cy_USBPD_Bch_RemoveDpPd
****************************************************************************//**
*
* This function removes pulldown on D+.
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \return
* \ref cy_en_usbpd_status_t
*
*******************************************************************************/
cy_en_usbpd_status_t Cy_USBPD_Bch_RemoveDpPd(cy_stc_usbpd_context_t *context)
{
#if defined(CY_IP_MXUSBPD)
#if (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2))
    uint8_t chgb_id = context->port;
#if CY_FLIPPED_DP_DM
    chgb_id = (chgb_id == 0u) ? 1u : 0u;
#endif /* CY_FLIPPED_DP_DM */
#else /* !(defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2)) */
    uint8_t chgb_id = 0;
#endif /* (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2)) */
    context->base->bch_det_0_ctrl[chgb_id] &= ~PDSS_BCH_DET_0_CTRL_RDP_PD_EN;
#elif defined(CY_IP_M0S8USBPD)
    context->base->chgdet_ctrl_0 &= ~PDSS_CHGDET_CTRL_0_RDP_PD_EN;
#else
    CY_UNUSED_PARAMETER(context);
#endif /* CY_IP */

    return CY_USBPD_STAT_SUCCESS;
}
/*******************************************************************************
* Function Name: Cy_USBPD_Bch_ApplyDmPd
****************************************************************************//**
*
* This function applies pulldown on D-.
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \return
* \ref cy_en_usbpd_status_t
*
*******************************************************************************/
cy_en_usbpd_status_t Cy_USBPD_Bch_ApplyDmPd(cy_stc_usbpd_context_t *context)
{
#if defined(CY_IP_MXUSBPD)
#if (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2))
    uint8_t chgb_id = context->port;
#if CY_FLIPPED_DP_DM
    chgb_id = (chgb_id == 0u) ? 1u : 0u;
#endif /* CY_FLIPPED_DP_DM */
#else /* !(defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2)) */
    uint8_t chgb_id = 0;
#endif /* (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2)) */
    context->base->bch_det_0_ctrl[chgb_id] |= PDSS_BCH_DET_0_CTRL_RDM_PD_EN;
#elif defined(CY_IP_M0S8USBPD)
    context->base->chgdet_ctrl_0 |= PDSS_CHGDET_CTRL_0_RDM_PD_EN;
#else
    CY_UNUSED_PARAMETER(context);
#endif /* CY_IP */

    return CY_USBPD_STAT_SUCCESS;
}
/*******************************************************************************
* Function Name: Cy_USBPD_Bch_RemoveDmPd
****************************************************************************//**
*
* This function removes pulldown on D-.
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \return
* \ref cy_en_usbpd_status_t
*
*******************************************************************************/
cy_en_usbpd_status_t Cy_USBPD_Bch_RemoveDmPd(cy_stc_usbpd_context_t *context)
{
#if defined(CY_IP_MXUSBPD)
#if (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2))
    uint8_t chgb_id = context->port;
#else /* !(defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2)) */
    uint8_t chgb_id = 0;
#endif /* (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2)) */
    context->base->bch_det_0_ctrl[chgb_id] &= ~PDSS_BCH_DET_0_CTRL_RDM_PD_EN;
#elif defined(CY_IP_M0S8USBPD)
    context->base->chgdet_ctrl_0 &= ~PDSS_CHGDET_CTRL_0_RDM_PD_EN;
#else
    CY_UNUSED_PARAMETER(context);
#endif /* CY_IP */

    return CY_USBPD_STAT_SUCCESS;
}

/*******************************************************************************
* Function Name: Cy_USBPD_Bch_ApplyDpPu
****************************************************************************//**
*
* This function applies pullup on D+.
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \return
* \ref cy_en_usbpd_status_t
*
*******************************************************************************/
cy_en_usbpd_status_t Cy_USBPD_Bch_ApplyDpPu(cy_stc_usbpd_context_t *context)
{
#if defined(CY_IP_MXUSBPD)
#if (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2))
    uint8_t chgb_id = context->port;
#if CY_FLIPPED_DP_DM
    chgb_id = (chgb_id == 0u) ? 1u : 0u;
#endif /* CY_FLIPPED_DP_DM */
#else /* !(defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2)) */
    uint8_t chgb_id = 0;
#endif /* (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2)) */
    context->base->bch_det_0_ctrl[chgb_id] |= PDSS_BCH_DET_0_CTRL_RDP_PU_EN;
#elif defined(CY_IP_M0S8USBPD)
    context->base->chgdet_ctrl_0 |= PDSS_CHGDET_CTRL_0_RDP_PU_EN;
#else
    CY_UNUSED_PARAMETER(context);
#endif /* CY_IP */

    return CY_USBPD_STAT_SUCCESS;
}

/*******************************************************************************
* Function Name: Cy_USBPD_Bch_RemoveDpPu
****************************************************************************//**
*
* This function removes pullup on D+.
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \return
* \ref cy_en_usbpd_status_t
*
*******************************************************************************/
cy_en_usbpd_status_t Cy_USBPD_Bch_RemoveDpPu(cy_stc_usbpd_context_t *context)
{
#if defined(CY_IP_MXUSBPD)
#if (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2))
    uint8_t chgb_id = context->port;
#if CY_FLIPPED_DP_DM
    chgb_id = (chgb_id == 0u) ? 1u : 0u;
#endif /* CY_FLIPPED_DP_DM */
#else /* !(defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2)) */
    uint8_t chgb_id = 0;
#endif /* (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2)) */
    context->base->bch_det_0_ctrl[chgb_id] &= ~PDSS_BCH_DET_0_CTRL_RDP_PU_EN;
#elif defined(CY_IP_M0S8USBPD)
    context->base->chgdet_ctrl_0 &= ~PDSS_CHGDET_CTRL_0_RDP_PU_EN;
#else
    CY_UNUSED_PARAMETER(context);
#endif /* CY_IP */

    return CY_USBPD_STAT_SUCCESS;
}

/*******************************************************************************
* Function Name: Cy_USBPD_Bch_ApplyRdatLkgDp
****************************************************************************//**
*
* This function applies RDAT_LKG resistance on D+.
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \return
*  None
*
*******************************************************************************/
void Cy_USBPD_Bch_ApplyRdatLkgDp(cy_stc_usbpd_context_t *context)
{
#if defined(CY_IP_MXUSBPD)
#if (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2))
    uint8_t chgb_id = context->port;
#if CY_FLIPPED_DP_DM
    chgb_id = (chgb_id == 0u) ? 1u : 0u;
#endif /* CY_FLIPPED_DP_DM */
#endif /* (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2)) */

#if (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2))
    context->base->bch_det_0_ctrl[chgb_id] |= PDSS_BCH_DET_0_CTRL_RDAT_LKG_DP_EN;
#else
    context->base->bch_det_0_ctrl[0] |= PDSS_BCH_DET_0_CTRL_RDAT_LKG_DP_EN;
#endif /* (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2)) */

#elif defined(CY_IP_M0S8USBPD)
    context->base->chgdet_ctrl_0 |= PDSS_CHGDET_CTRL_0_RDAT_LKG_DP_EN;
#else
    CY_UNUSED_PARAMETER(context);
#endif /* CY_IP */
}

/*******************************************************************************
* Function Name: Cy_USBPD_Bch_ApplyRdatLkgDm
****************************************************************************//**
*
* This function applies RDAT_LKG resistance on D-.
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \return
* None
*
*******************************************************************************/
void Cy_USBPD_Bch_ApplyRdatLkgDm(cy_stc_usbpd_context_t *context)
{
#if defined(CY_IP_MXUSBPD)
#if (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2))
    uint8_t chgb_id = context->port;
#if CY_FLIPPED_DP_DM
    chgb_id = (chgb_id == 0u) ? 1u : 0u;
#endif /* CY_FLIPPED_DP_DM */
#endif /* (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2)) */

#if (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2))
    context->base->bch_det_0_ctrl[chgb_id] |= PDSS_BCH_DET_0_CTRL_RDAT_LKG_DM_EN;
#else
    context->base->bch_det_0_ctrl[0] |= PDSS_BCH_DET_0_CTRL_RDAT_LKG_DM_EN;
#endif /* (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2)) */

#elif defined(CY_IP_M0S8USBPD)
    context->base->chgdet_ctrl_0 |= PDSS_CHGDET_CTRL_0_RDAT_LKG_DM_EN;
#else
    CY_UNUSED_PARAMETER(context);
#endif /* CY_IP */
}

/*******************************************************************************
* Function Name: Cy_USBPD_Bch_RemoveRdatLkgDp
****************************************************************************//**
*
* This function removes RDAT_LKG resistance on D+.
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \return
*  None
*
*******************************************************************************/
void Cy_USBPD_Bch_RemoveRdatLkgDp(cy_stc_usbpd_context_t *context)
{
#if defined(CY_IP_MXUSBPD)
#if (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2))
    uint8_t chgb_id = context->port;
#if CY_FLIPPED_DP_DM
    chgb_id = (chgb_id == 0u) ? 1u : 0u;
#endif /* CY_FLIPPED_DP_DM */
#endif /* (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2)) */

#if (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2))
    context->base->bch_det_0_ctrl[chgb_id] &= ~PDSS_BCH_DET_0_CTRL_RDAT_LKG_DP_EN;
#else
    context->base->bch_det_0_ctrl[0] &= ~PDSS_BCH_DET_0_CTRL_RDAT_LKG_DP_EN;
#endif /* (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2)) */
#elif defined(CY_IP_M0S8USBPD)
    context->base->chgdet_ctrl_0 &= ~PDSS_CHGDET_CTRL_0_RDAT_LKG_DP_EN;
#else
    CY_UNUSED_PARAMETER(context);
#endif /* CY_IP */
}

/*******************************************************************************
* Function Name: Cy_USBPD_Bch_RemoveRdatLkgDm
****************************************************************************//**
*
* This function removes RDAT_LKG resistance on D-.
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \return
*  None
*
*******************************************************************************/
void Cy_USBPD_Bch_RemoveRdatLkgDm(cy_stc_usbpd_context_t *context)
{
#if defined(CY_IP_MXUSBPD)
#if (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2))
    uint8_t chgb_id = context->port;
#if CY_FLIPPED_DP_DM
    chgb_id = (chgb_id == 0u) ? 1u : 0u;
#endif /* CY_FLIPPED_DP_DM */
#endif /* (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2)) */

#if (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2))
    context->base->bch_det_0_ctrl[chgb_id] &= ~PDSS_BCH_DET_0_CTRL_RDAT_LKG_DM_EN;
#else
    context->base->bch_det_0_ctrl[0] &= ~PDSS_BCH_DET_0_CTRL_RDAT_LKG_DM_EN;
#endif /* (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2)) */

#elif defined(CY_IP_M0S8USBPD)
    context->base->chgdet_ctrl_0 &= ~PDSS_CHGDET_CTRL_0_RDAT_LKG_DM_EN;
#else
    CY_UNUSED_PARAMETER(context);
#endif /* CY_IP */
}

/*******************************************************************************
* Function Name: Cy_USBPD_Bch_Apply_AppleTermDp
* **************************************************************************//**
*
* This function applies Apple source terminations on D+.
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \param appleTermId
* Apple termination ID
*
* \return
*  None
*
*******************************************************************************/
void Cy_USBPD_Bch_Apply_AppleTermDp(cy_stc_usbpd_context_t *context,
                                       cy_en_usbpd_bch_src_term_t appleTermId)
{
#if defined(CY_IP_MXUSBPD)
#if (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2))
    /* Defines which DP/DM lines to be routed to */
    uint8_t chgb_id = context->port;
#if CY_FLIPPED_DP_DM
    chgb_id = (chgb_id == 0u) ? 1u : 0u;
#endif /* CY_FLIPPED_DP_DM */
#else /* !(defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2)) */
    uint8_t chgb_id = 0;
#endif /* (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2)) */

    PPDSS_REGS_T pd = context->base ;

#if (defined(CY_DEVICE_PAG1S) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
    pd->bch_det_0_ctrl[chgb_id] |= PDSS_BCH_DET_0_CTRL_VDP_SRC_EN;
    pd->bch_det_1_ctrl[chgb_id] |= PDSS_BCH_DET_1_CTRL_CHGDET_APP_DET;
#endif /* (defined(CY_DEVICE_PAG1S) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) */

    switch(appleTermId)
    {
        case CHGB_SRC_TERM_APPLE_1A:
            pd->bch_det_1_ctrl[chgb_id] |= (uint32_t)(1UL << PDSS_BCH_DET_1_CTRL_CHGDET_APPLE_MODE_DP_POS);
            break;
        case CHGB_SRC_TERM_APPLE_2_1A:
            pd->bch_det_1_ctrl[chgb_id] |= (uint32_t)(2UL << PDSS_BCH_DET_1_CTRL_CHGDET_APPLE_MODE_DP_POS);
            break;
        case CHGB_SRC_TERM_APPLE_2_4A:
            pd->bch_det_1_ctrl[chgb_id] |= ((uint32_t)2u << PDSS_BCH_DET_1_CTRL_CHGDET_APPLE_MODE_DP_POS
#if (defined(CY_DEVICE_PAG1S) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
                    | ((uint32_t)1u << PDSS_BCH_DET_1_CTRL_APPLE_TERM_POS)
#endif /* (defined(CY_DEVICE_PAG1S) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) */
                    );
            break;
#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
        case CHGB_SRC_TERM_APPLE_3A:
            pd->bch_det_1_ctrl[chgb_id] |= ((uint32_t)2u << PDSS_BCH_DET_1_CTRL_CHGDET_APPLE_MODE_DP_POS
                    | ((uint32_t)1u << PDSS_BCH_DET_1_CTRL_APPLE_TERM_POS));
            break;
#endif /* (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))    */

        default:
            Cy_SysLib_DelayUs (1);
            break;
    }
#elif defined(CY_IP_M0S8USBPD)
    PPDSS_REGS_T pd = context->base ;

    switch(appleTermId)
    {
        case CHGB_SRC_TERM_APPLE_1A:
            pd->chgdet_ctrl_1 |= (uint32_t)(1UL << PDSS_CHGDET_CTRL_1_CHGDET_APPLE_MODE_DP_POS);
            break;
        case CHGB_SRC_TERM_APPLE_2_1A:
            pd->chgdet_ctrl_1 |= (uint32_t)(2UL << PDSS_CHGDET_CTRL_1_CHGDET_APPLE_MODE_DP_POS);
            break;
        case CHGB_SRC_TERM_APPLE_2_4A:
            pd->chgdet_ctrl_1 |= (uint32_t)(2UL << PDSS_CHGDET_CTRL_1_CHGDET_APPLE_MODE_DP_POS);
            break;
        default:
            Cy_SysLib_DelayUs (1);
            break;
    }
#else
    CY_UNUSED_PARAMETER(context);
    CY_UNUSED_PARAMETER(appleTermId);
#endif /* CY_IP */
}

/*******************************************************************************
* Function Name: Cy_USBPD_Bch_Apply_AppleTermDm
* **************************************************************************//**
*
* This function applies Apple source terminations on D-.
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \param appleTermId
* Apple termination ID
*
* \return
*  None
*
*******************************************************************************/
void Cy_USBPD_Bch_Apply_AppleTermDm(cy_stc_usbpd_context_t *context,
                                       cy_en_usbpd_bch_src_term_t appleTermId)
{
#if defined(CY_IP_MXUSBPD)
#if (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2))
    /* Defines which DP/DM lines to be routed to */
    uint8_t chgb_id = context->port;
#if CY_FLIPPED_DP_DM
    chgb_id = (chgb_id == 0u) ? 1u : 0u;
#endif /* CY_FLIPPED_DP_DM */
#else /* !(defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2)) */
    uint8_t chgb_id = 0;
#endif /* (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2)) */

    PPDSS_REGS_T pd = context->base ;

#if (defined(CY_DEVICE_PAG1S) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
    pd->bch_det_0_ctrl[chgb_id] |= PDSS_BCH_DET_0_CTRL_VDM_SRC_EN;
    pd->bch_det_1_ctrl[chgb_id] |= PDSS_BCH_DET_1_CTRL_CHGDET_APP_DET;
#endif /*(defined(CY_DEVICE_PAG1S) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) */

    switch(appleTermId)
    {
        case CHGB_SRC_TERM_APPLE_1A:
            pd->bch_det_1_ctrl[chgb_id] |= (2u << PDSS_BCH_DET_1_CTRL_CHGDET_APPLE_MODE_DM_POS);
            break;
        case CHGB_SRC_TERM_APPLE_2_1A:
            pd->bch_det_1_ctrl[chgb_id] |= (1u << PDSS_BCH_DET_1_CTRL_CHGDET_APPLE_MODE_DM_POS);
            break;
        case CHGB_SRC_TERM_APPLE_2_4A:
            pd->bch_det_1_ctrl[chgb_id] |= (2u << PDSS_BCH_DET_1_CTRL_CHGDET_APPLE_MODE_DM_POS);
            break;
#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
        case CHGB_SRC_TERM_APPLE_3A:
             pd->bch_det_0_ctrl[chgb_id] |= (PDSS_BCH_DET_0_CTRL_RDM_PD_EN | PDSS_BCH_DET_0_CTRL_RDM_PU_EN);
             break;
#endif /* (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) */
        default:
            Cy_SysLib_DelayUs (1);
            break;
    }
#elif defined(CY_IP_M0S8USBPD)
    PPDSS_REGS_T pd = context->base ;

    switch(appleTermId)
    {
        case CHGB_SRC_TERM_APPLE_1A:
            pd->chgdet_ctrl_1 |= (2u << PDSS_CHGDET_CTRL_1_CHGDET_APPLE_MODE_DM_POS);
            break;
        case CHGB_SRC_TERM_APPLE_2_1A:
            pd->chgdet_ctrl_1 |= (1u << PDSS_CHGDET_CTRL_1_CHGDET_APPLE_MODE_DM_POS);
            break;
        case CHGB_SRC_TERM_APPLE_2_4A:
            pd->chgdet_ctrl_1 |= (2u << PDSS_CHGDET_CTRL_1_CHGDET_APPLE_MODE_DM_POS);
            break;
        default:
            Cy_SysLib_DelayUs (1);
            break;
    }
#else
    CY_UNUSED_PARAMETER(context);
    CY_UNUSED_PARAMETER(appleTermId);
#endif /* CY_IP */
}

/*******************************************************************************
* Function Name: Cy_USBPD_Bch_Apply_VdmSrc
****************************************************************************//**
*
* This function applies VDM_SRC on DM.
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \return
*  None
*
*******************************************************************************/
void Cy_USBPD_Bch_Apply_VdmSrc(cy_stc_usbpd_context_t *context)
{
#if defined(CY_IP_MXUSBPD)
#if (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2))
    /* Defines which DP/DM lines to be routed to */
    uint8_t chgb_id = context->port;
#if CY_FLIPPED_DP_DM
    chgb_id = (chgb_id == 0u) ? 1u : 0u;
#endif /* CY_FLIPPED_DP_DM */
    context->base->bch_det_0_ctrl[chgb_id] |= PDSS_BCH_DET_0_CTRL_VDM_SRC_EN;
#else /* !(defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2)) */
    context->base->bch_det_0_ctrl[0] |= PDSS_BCH_DET_0_CTRL_VDM_SRC_EN;
#endif /* (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2)) */
#elif defined(CY_IP_M0S8USBPD)
    context->base->chgdet_ctrl_0 |= PDSS_CHGDET_CTRL_0_VDM_SRC_EN;
#else
    CY_UNUSED_PARAMETER(context);
#endif /* CY_IP */
}

/*******************************************************************************
* Function Name: Cy_USBPD_Bch_Remove_VdmSrc
****************************************************************************//**
*
* This function removes VDM_SRC on DM.
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \return
*  None
*
*******************************************************************************/
void Cy_USBPD_Bch_Remove_VdmSrc(cy_stc_usbpd_context_t *context)
{
#if defined(CY_IP_MXUSBPD)
#if (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2))
    /* Defines which DP/DM lines to be routed to */
    uint8_t chgb_id = context->port;
#if CY_FLIPPED_DP_DM
    chgb_id = (chgb_id == 0u) ? 1u : 0u;
#endif /* CY_FLIPPED_DP_DM */
    context->base->bch_det_0_ctrl[chgb_id] &= ~(PDSS_BCH_DET_0_CTRL_VDM_SRC_EN);
#else /* !(defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2)) */
    context->base->bch_det_0_ctrl[0] &= ~PDSS_BCH_DET_0_CTRL_VDM_SRC_EN;
#endif /* (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2)) */
#elif defined(CY_IP_M0S8USBPD)
    context->base->chgdet_ctrl_0 &= ~PDSS_CHGDET_CTRL_0_VDM_SRC_EN;
#else
    CY_UNUSED_PARAMETER(context);
#endif /* CY_IP */
}

/*******************************************************************************
* Function Name: Cy_USBPD_Bch_Is_VdmSrc_On
****************************************************************************//**
*
* Function to check whether VDM_SRC supply is enabled.
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \return
* True if VDM_SRC supply is ON, false otherwise.
*
*******************************************************************************/
bool Cy_USBPD_Bch_Is_VdmSrc_On(cy_stc_usbpd_context_t *context)
{
#if defined(CY_IP_MXUSBPD)
#if (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2))
    /* Defines which DP/DM lines to be routed to */
    uint8_t chgb_id = context->port;
#if CY_FLIPPED_DP_DM
    chgb_id = (chgb_id == 0u) ? 1u : 0u;
#endif /* CY_FLIPPED_DP_DM */
    return ((bool)((context->base->bch_det_0_ctrl[chgb_id] & PDSS_BCH_DET_0_CTRL_VDM_SRC_EN) != 0u));
#else /* !(defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2)) */
    return ((bool)((context->base->bch_det_0_ctrl[0] & PDSS_BCH_DET_0_CTRL_VDM_SRC_EN) != 0UL));
#endif /* (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2)) */
#elif defined(CY_IP_M0S8USBPD)
    return ((bool)((context->base->chgdet_ctrl_0 & PDSS_CHGDET_CTRL_0_VDM_SRC_EN) != 0UL));
#else
    CY_UNUSED_PARAMETER(context);
    return false;
#endif /* CY_IP */
}

/*******************************************************************************
* Function Name: Cy_USBPD_Bch_Remove_AppleSrcDp
****************************************************************************//**
*
* This function removes Apple source terminations from D+
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \return
*  None
*
*******************************************************************************/
void Cy_USBPD_Bch_Remove_AppleSrcDp(cy_stc_usbpd_context_t *context)
{
#if defined(CY_IP_MXUSBPD)
    PPDSS_REGS_T pd = context->base;
#if (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2))
    /* Defines which DP/DM lines to be routed to */
    uint8_t chgb_id = context->port;
#if CY_FLIPPED_DP_DM
    chgb_id = (chgb_id == 0u) ? 1u : 0u;
#endif /* CY_FLIPPED_DP_DM */
#else /* !(defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2)) */
    uint8_t chgb_id = 0;
#endif /* (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2)) */
    pd->bch_det_1_ctrl[chgb_id] &=
                ~(PDSS_BCH_DET_1_CTRL_CHGDET_APPLE_MODE_DP_MASK
#if (defined(CY_DEVICE_PAG1S) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
                 | PDSS_BCH_DET_1_CTRL_APPLE_TERM_MASK
                 | PDSS_BCH_DET_1_CTRL_CHGDET_APP_DET
#endif /* (defined(CY_DEVICE_PAG1S) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) */
                 );
#if (defined(CY_DEVICE_PAG1S) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
        pd->bch_det_0_ctrl[chgb_id] &= ~PDSS_BCH_DET_0_CTRL_VDP_SRC_EN;
#endif /* (defined(CY_DEVICE_PAG1S) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))*/
#elif defined(CY_IP_M0S8USBPD)
    context->base->chgdet_ctrl_1 &= ~(PDSS_CHGDET_CTRL_1_CHGDET_APPLE_MODE_DP_MASK);
#else
    CY_UNUSED_PARAMETER(context);
#endif /* CY_IP */
}

/*******************************************************************************
* Function Name: Cy_USBPD_Bch_Remove_AppleSrcDm
****************************************************************************//**
*
* This function removes Apple source terminations from D-
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \return
* None
*
*******************************************************************************/
void Cy_USBPD_Bch_Remove_AppleSrcDm(cy_stc_usbpd_context_t *context)
{
#if defined(CY_IP_MXUSBPD)
    PPDSS_REGS_T pd = context->base;
#if (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2))
    /* Defines which DP/DM lines to be routed to */
    uint8_t chgb_id = context->port;
#if CY_FLIPPED_DP_DM
    chgb_id = (chgb_id == 0u) ? 1u : 0u;
#endif /* CY_FLIPPED_DP_DM */
#else /* !(defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2)) */
    uint8_t chgb_id = 0;
#endif /* (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2)) */

pd->bch_det_1_ctrl[chgb_id] &=
                ~(PDSS_BCH_DET_1_CTRL_CHGDET_APPLE_MODE_DM_MASK
#if (defined(CY_DEVICE_PAG1S) || defined(CY_DEVICE_CCG7D))
                 | PDSS_BCH_DET_1_CTRL_CHGDET_APP_DET
#endif /* (defined(CY_DEVICE_PAG1S) || defined(CY_DEVICE_CCG7D)) */
                 );
#if (defined(CY_DEVICE_PAG1S) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
        pd->bch_det_0_ctrl[chgb_id] &= ~PDSS_BCH_DET_0_CTRL_VDP_SRC_EN;
#endif /* (defined(CY_DEVICE_PAG1S) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) */
#elif defined(CY_IP_M0S8USBPD)
    context->base->chgdet_ctrl_1 &= ~(PDSS_CHGDET_CTRL_1_CHGDET_APPLE_MODE_DM_MASK);
#else
    CY_UNUSED_PARAMETER(context);
#endif /* CY_IP */
}

/*******************************************************************************
* Function Name: Cy_USBPD_Bch_Enable_AppleDet
****************************************************************************//**
*
* This function enables Apple Brick ID detection.
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \return
*  None
*
*******************************************************************************/
void Cy_USBPD_Bch_Enable_AppleDet(cy_stc_usbpd_context_t *context)
{
#if defined(CY_IP_MXUSBPD)
#if (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2))
    uint8_t chgb_id = context->port;
#if CY_FLIPPED_DP_DM
    chgb_id = (chgb_id == 0u) ? 1u : 0u;
#endif /* CY_FLIPPED_DP_DM */
#else /* !(defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2)) */
    uint8_t chgb_id = 0;
#endif /* (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2)) */
    context->base->bch_det_1_ctrl[chgb_id] |= PDSS_BCH_DET_1_CTRL_CHGDET_APP_DET;
#elif defined(CY_IP_M0S8USBPD)
    context->base->chgdet_ctrl_1 |= PDSS_CHGDET_CTRL_1_CHGDET_APP_DET;
#else
    CY_UNUSED_PARAMETER(context);
#endif /* CY_IP */
}

/*******************************************************************************
* Function Name: Cy_USBPD_Bch_Disable_AppleDet
****************************************************************************//**
*
* This function disables Apple Brick ID detection.
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \return
* None
*
*******************************************************************************/
void Cy_USBPD_Bch_Disable_AppleDet(cy_stc_usbpd_context_t *context)
{
#if defined(CY_IP_MXUSBPD)
#if (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2)) 
    uint8_t chgb_id = context->port;
#if CY_FLIPPED_DP_DM
    chgb_id = (chgb_id == 0u) ? 1u : 0u;
#endif /* CY_FLIPPED_DP_DM */
#else /* !(defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2)) */
    uint8_t chgb_id = 0;
#endif /* (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2)) */
    context->base->bch_det_1_ctrl[chgb_id] &= ~PDSS_BCH_DET_1_CTRL_CHGDET_APP_DET;
#elif defined(CY_IP_M0S8USBPD)
    context->base->chgdet_ctrl_1 &= ~PDSS_CHGDET_CTRL_1_CHGDET_APP_DET;
#else
    CY_UNUSED_PARAMETER(context);
#endif /* CY_IP */
}

/*******************************************************************************
* Function Name: Cy_USBPD_Bch_Phy_DpStat
****************************************************************************//**
*
* This function checks status of DP line.
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \return
* True if DP is high, false otherwise.
*
*******************************************************************************/
bool Cy_USBPD_Bch_Phy_DpStat(cy_stc_usbpd_context_t *context)
{
#if defined(CY_IP_MXUSBPD)
    PPDSS_REGS_T pd = context->base ;
#if (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2))
    uint8_t chgb_id = context->port;
#if CY_FLIPPED_DP_DM
    chgb_id = (chgb_id == 0u) ? 1u : 0u;
#endif /* CY_FLIPPED_DP_DM */
    if ((pd->intr9_status_1 & (1UL << (PDSS_INTR9_STATUS_1_QCOM_RCVR_DP_STATUS_POS + chgb_id))) != 0UL)
#elif (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1) || defined(CY_DEVICE_PAG2S))
    if ((pd->intr9_status_1 & (PDSS_INTR9_STATUS_1_QCOM_RCVR_DP_STATUS)) != 0u)
#endif /* CCGx */
    {
        return true;
    }
    else
    {
        return false;
    }
#else
    CY_UNUSED_PARAMETER(context);
    return false;
#endif /* CY_IP */
}

/*******************************************************************************
* Function Name: Cy_USBPD_Bch_Phy_DmStat
****************************************************************************//**
*
* This function checks status of DM line.
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \return
* True if DM is high, false otherwise.
*
*******************************************************************************/
bool Cy_USBPD_Bch_Phy_DmStat(cy_stc_usbpd_context_t *context)
{
#if defined(CY_IP_MXUSBPD)
    PPDSS_REGS_T pd = context->base ;
#if (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2))
    uint8_t chgb_id = context->port;
#if CY_FLIPPED_DP_DM
    chgb_id = (chgb_id == 0u) ? 1u : 0u;
#endif /* CY_FLIPPED_DP_DM */
    if ((pd->intr9_status_1 & (1UL << (PDSS_INTR9_STATUS_1_QCOM_RCVR_DM_STATUS_POS + chgb_id))) != 0UL)
#elif (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1) || defined(CY_DEVICE_PAG2S))
     if ((pd->intr9_status_1 & (PDSS_INTR9_STATUS_1_QCOM_RCVR_DM_STATUS)) != 0u)
#endif /* CCGx */
    {
        return true;
    }
    else
    {
        return false;
    }
#else
    CY_UNUSED_PARAMETER(context);
    return false;
#endif /* CY_IP */
}

/*******************************************************************************
* Function Name: Cy_USBPD_Bch_Phy_Config_DeepSleep
****************************************************************************//**
*
* This function configures the charger detect block for deepsleep entry.
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \return
* None
*
*******************************************************************************/
void Cy_USBPD_Bch_Phy_Config_DeepSleep(cy_stc_usbpd_context_t *context)
{
#if defined(CY_IP_MXUSBPD)
#if (CCG_TYPE_A_PORT_ENABLE == 0)
    if (context->port < NO_OF_TYPEC_PORTS)
#else
    if (context->port < 2u)
#endif
    {
    PPDSS_REGS_T pd = context->base ;
#if (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2))
    /* Defines which DP/DM lines to be routed to */
    uint8_t chgb_id;
#if CY_FLIPPED_DP_DM
    /* For CCG3PA applications which require the block to be routed to DP1/DM1 */
    /* QAC suppression 2995, 2997: When NO_OF_TYPEC_PORTS is 1, the check port == 0 is redundant.
     * Yet the check is retained for applications where NO_OF_TYPEC_PORTS is other than 1 */
    chgb_id = (context->port == 0u) ? 1u : 0u; /* PRQA S 2995, 2997 */
#else
    chgb_id = context->port;
#endif /* !CY_FLIPPED_DP_DM */
#else /* !(defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2)) */
    uint8_t chgb_id = 0;
#endif /* (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2)) */

    /* Configuring both edge detection. */
    pd->intr9_cfg_bch_det[chgb_id] |= (PDSS_INTR9_CFG_BCH_DET_QCOM_RCVR_DM_CFG_MASK |
            PDSS_INTR9_CFG_BCH_DET_QCOM_RCVR_DP_CFG_MASK);

#if (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2))
    pd->intr9_mask |= (((1UL << PDSS_INTR9_QCOM_RCVR_DM_CHANGED_POS) |
                (1UL << PDSS_INTR9_QCOM_RCVR_DP_CHANGED_POS)) << chgb_id);
#else
    pd->intr9_mask |= (PDSS_INTR9_QCOM_RCVR_DM_CHANGED |
            PDSS_INTR9_QCOM_RCVR_DP_CHANGED);
#endif /* (defined(CY_DEVICE_CCG3PA)) */
     }
#else
    CY_UNUSED_PARAMETER(context);
#endif /* CY_IP */
}

/*******************************************************************************
* Function Name: Cy_USBPD_Bch_Phy_Config_Wakeup
****************************************************************************//**
*
* This function configures the charger detect block after deepsleep exit.
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \return
* None
*
*******************************************************************************/
void Cy_USBPD_Bch_Phy_Config_Wakeup(cy_stc_usbpd_context_t *context)
{
    /* Nothing to do. */
    (void)context;
}

#if (!QC_AFC_CHARGING_DISABLED)
/*******************************************************************************
* Function Name: Cy_USBPD_Bch_QcSrcInit
****************************************************************************//**
*
* This function initialize QC source block.
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \return
* cy_en_usbpd_status_t
*
*******************************************************************************/    
cy_en_usbpd_status_t Cy_USBPD_Bch_QcSrcInit(cy_stc_usbpd_context_t *context)
{
    /* Nothing to do for now */
    CY_UNUSED_PARAMETER(context);
    return CY_USBPD_STAT_SUCCESS;
}

/*******************************************************************************
* Function Name: Cy_USBPD_Bch_QcSrcStop
****************************************************************************//**
*
* This function deselect the QC source block.
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \return
* cy_en_usbpd_status_t
*
*******************************************************************************/
cy_en_usbpd_status_t Cy_USBPD_Bch_QcSrcStop(cy_stc_usbpd_context_t *context)
{
    /* Nothing to do for now */
    CY_UNUSED_PARAMETER(context);
    return CY_USBPD_STAT_SUCCESS;
}

/*******************************************************************************
* Function Name: Cy_USBPD_Bch_QcSrcMasterSenseEn
****************************************************************************//**
*
* This function enable master for hardware to start sensing the pulses on Dplus
* and Dminus.
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \return
* cy_en_usbpd_status_t
*
*******************************************************************************/
cy_en_usbpd_status_t Cy_USBPD_Bch_QcSrcMasterSenseEn(cy_stc_usbpd_context_t *context)
{
    uint8_t chgb_id = context->port;
#if (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2))
#if CY_FLIPPED_DP_DM
    chgb_id = (chgb_id == 0u) ? 1u : 0u;
#endif /* CY_FLIPPED_DP_DM */
#else
    chgb_id = 0u;
#endif /* (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2)) */
    PPDSS_REGS_T pd = context->base;
    
#if (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2) || defined(CY_DEVICE_PAG1S) || defined(CY_DEVICE_CCG6))
    /* Sense changes on DM/DP lines */
    pd->qc3_chrger_ctrl[chgb_id] |= PDSS_QC3_CHRGER_CTRL_QC3_0_CHG_EN;
#else /* (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2) || defined(CY_DEVICE_PAG1S) || defined(CY_DEVICE_CCG6)) */
    pd->qc3_chrger_ctrl |= PDSS_QC3_CHRGER_CTRL_QC3_0_CHG_EN;
    CY_UNUSED_PARAMETER(chgb_id);
#endif /* CCGx */
    return CY_USBPD_STAT_SUCCESS;
}

/*******************************************************************************
* Function Name: Cy_USBPD_Bch_QcSrcMasterSenseDis
****************************************************************************//**
*
* This function disable master for hardware to stop sensing the pulses on Dplus
* and Dminus.
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \return
* cy_en_usbpd_status_t
*
*******************************************************************************/
cy_en_usbpd_status_t Cy_USBPD_Bch_QcSrcMasterSenseDis(cy_stc_usbpd_context_t *context)
{
    uint8_t chgb_id = context->port;
#if (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2))
#if CY_FLIPPED_DP_DM
    chgb_id = (chgb_id == 0u) ? 1u : 0u;
#endif /* CY_FLIPPED_DP_DM */
#else
    chgb_id = 0u;
#endif /* (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2)) */
    PPDSS_REGS_T pd = context->base;

#if (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2) || defined(CY_DEVICE_PAG1S) || defined(CY_DEVICE_CCG6))
    pd->qc3_chrger_ctrl[chgb_id] &= ~PDSS_QC3_CHRGER_CTRL_QC3_0_CHG_EN;
#else
    pd->qc3_chrger_ctrl &= ~PDSS_QC3_CHRGER_CTRL_QC3_0_CHG_EN;
    CY_UNUSED_PARAMETER(chgb_id);
#endif /* CCGx */

    return CY_USBPD_STAT_SUCCESS;
}

/*******************************************************************************
* Function Name: Cy_USBPD_Bch_QcSrcContModeStart
****************************************************************************//**
*
* This function configures the QC3 block, enable QC interrupts and enables 
* master for DP and DM sensing.
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \return
* cy_en_usbpd_status_t
*
*******************************************************************************/
cy_en_usbpd_status_t Cy_USBPD_Bch_QcSrcContModeStart(cy_stc_usbpd_context_t *context)
{
#if (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) 
    PPDSS_REGS_T pd = context->base;
    uint32_t regval;
    volatile uint32_t *qc3_chrger_ctrl = NULL;
    volatile uint32_t *afc_hs_filter_cfg = NULL;

#if (defined(CY_DEVICE_CCG3PA))
    uint8_t chgb_id = context->port;
#if CY_FLIPPED_DP_DM
    chgb_id = (chgb_id == 0u) ? 1u : 0u;
#endif /* CY_FLIPPED_DP_DM */
#else
    uint8_t chgb_id = 0;
#endif /* (defined(CY_DEVICE_CCG3PA) */

    context->bcQcPulseCount = 0;
    
#if (defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
    qc3_chrger_ctrl = &pd->qc3_chrger_ctrl;
    afc_hs_filter_cfg = &pd->afc_hs_filter_cfg;
    CY_UNUSED_PARAMETER(chgb_id);
#else
    qc3_chrger_ctrl = &pd->qc3_chrger_ctrl[chgb_id];
    afc_hs_filter_cfg = &pd->afc_hs_filter_cfg[chgb_id];
#endif /* (defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1) || defined(CY_DEVICE_PAG2S)) */
    
    /*
     * Enable pulse count and filter. DP filter should look for rising edge
     * and DM filter should look for falling edge.
     */
    *qc3_chrger_ctrl |= PDSS_QC3_CHRGER_CTRL_QC3_0_CHG_EN;

    /* Clear the DP/DM Count. */
    *qc3_chrger_ctrl |= PDSS_QC3_CHRGER_CTRL_READ_DPDM_COUNT;
    while (((*qc3_chrger_ctrl & PDSS_QC3_CHRGER_CTRL_READ_DPDM_COUNT) != 0u)) {}

    regval = *afc_hs_filter_cfg;

    regval &= ~(PDSS_AFC_HS_FILTER_CFG_DP_FILT_SEL_MASK |
        PDSS_AFC_HS_FILTER_CFG_DM_FILT_SEL_MASK | PDSS_AFC_HS_FILTER_CFG_DP_FILT_EN
        | PDSS_AFC_HS_FILTER_CFG_DM_FILT_EN |
        PDSS_AFC_HS_FILTER_CFG_DP_FILT_RESET);
    *afc_hs_filter_cfg = regval;

    regval |= ((QC3_DP_DM_PULSE_FILTER_CLOCK_SEL <<
        PDSS_AFC_HS_FILTER_CFG_DP_FILT_SEL_POS) | (QC3_DP_DM_PULSE_FILTER_CLOCK_SEL
        << PDSS_AFC_HS_FILTER_CFG_DM_FILT_SEL_POS) | PDSS_AFC_HS_FILTER_CFG_DM_FILT_RESET |
            (PDSS_AFC_HS_FILTER_CFG_DP_FILT_EN | PDSS_AFC_HS_FILTER_CFG_DM_FILT_EN));

    *afc_hs_filter_cfg = regval;

    /* Enable D+/D- pulse interrupts */
    pd->intr6 = QC3_PORT_0_DP_DM_PULSE_MASK;
    pd->intr6_mask |= QC3_PORT_0_DP_DM_PULSE_MASK;
  
    return CY_USBPD_STAT_SUCCESS;

#else
    CY_UNUSED_PARAMETER(context);
    return CY_USBPD_STAT_NOT_SUPPORTED;
#endif /* (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3) (defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)))  */
}

/*******************************************************************************
* Function Name: Cy_USBPD_Bch_QcSrcContModeStop
****************************************************************************//**
*
* This function disables QC3 block and interrupts, and also disables the DP/DM
* master sensing.
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \return
* cy_en_usbpd_status_t
*
*******************************************************************************/
cy_en_usbpd_status_t Cy_USBPD_Bch_QcSrcContModeStop(cy_stc_usbpd_context_t *context)
{
#if (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) 
    PPDSS_REGS_T pd = context->base;
#if (defined(CY_DEVICE_CCG3PA))
    uint8_t chgb_id = context->port;
#if CY_FLIPPED_DP_DM
    chgb_id = (chgb_id == 0u) ? 1u : 0u;
#endif /* CY_FLIPPED_DP_DM */
#else
    uint8_t chgb_id = 0;
#endif /* (defined(CY_DEVICE_CCG3PA) */
    context->bcQcPulseCount = 0;
#if (defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
    pd->qc3_chrger_ctrl &= ~PDSS_QC3_CHRGER_CTRL_QC3_0_CHG_EN;
    CY_UNUSED_PARAMETER(chgb_id);
#else
    pd->qc3_chrger_ctrl[chgb_id] &= ~PDSS_QC3_CHRGER_CTRL_QC3_0_CHG_EN;
#endif /* defined(CY_DEVICE_PMG1S3) */

    /* Disable D+/D- pulse interrupts */
    pd->intr6_mask &= ~(QC3_PORT_0_DP_DM_PULSE_MASK);
    pd->intr6 = QC3_PORT_0_DP_DM_PULSE_MASK;

    return CY_USBPD_STAT_SUCCESS;

#else
    CY_UNUSED_PARAMETER(context);
    return CY_USBPD_STAT_NOT_SUPPORTED;
#endif /* (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1) || defined(CY_DEVICE_PAG2S)) */
}

/*******************************************************************************
* Function Name: Cy_USBPD_Bch_AfcSrcInit
****************************************************************************//**
*
* This function enables the AFC source clock, filters and other configurations.
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \return
* cy_en_usbpd_status_t
*
*******************************************************************************/
cy_en_usbpd_status_t Cy_USBPD_Bch_AfcSrcInit(cy_stc_usbpd_context_t *context)
{
#if (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) 
    PPDSS_REGS_T pd = context->base;
    volatile uint32_t *afc_1_ctrl = NULL;
    volatile uint32_t *afc_2_ctrl = NULL;
    volatile uint32_t *afc_hs_filter_cfg = NULL;
    uint32_t regval = 0;

#if (defined(CY_DEVICE_CCG3PA))
    uint8_t chgb_id = context->port;
#if CY_FLIPPED_DP_DM
    chgb_id = (chgb_id == 0u) ? 1u : 0u;
#endif /* CY_FLIPPED_DP_DM */
#else
    uint8_t chgb_id = 0;
#endif /* (defined(CY_DEVICE_CCG3PA) */

#if (defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1) || defined(CY_DEVICE_PAG2S))
    afc_1_ctrl = &pd->afc_1_ctrl;
    afc_2_ctrl = &pd->afc_2_ctrl;
    afc_hs_filter_cfg = &pd->afc_hs_filter_cfg;
    CY_UNUSED_PARAMETER(chgb_id);
#else
    afc_1_ctrl = &pd->afc_1_ctrl[chgb_id];
    afc_2_ctrl = &pd->afc_2_ctrl[chgb_id];
    afc_hs_filter_cfg = &pd->afc_hs_filter_cfg[chgb_id];
#endif /* defined(CY_DEVICE_PMG1S3) */
    
    regval = *afc_1_ctrl;

    regval &= ~(PDSS_AFC_1_CTRL_TX_RESET |
            PDSS_AFC_1_CTRL_NO_OF_BYTES_TX_MASK);
    regval |= PDSS_AFC_1_CTRL_UPDATE_TXCLK;

    *afc_1_ctrl = regval;


    regval = *afc_2_ctrl;
    /* Update UI clock cycle count for 125kHz clock. */
    regval &= ~PDSS_AFC_2_CTRL_UI_COUNT_MASK;
    regval |= (QC3_DP_DM_PULSE_FILTER_CLOCK_SEL <<
        PDSS_AFC_2_CTRL_UI_COUNT_POS);
    *afc_2_ctrl = regval;

    /* Enable filter. */
    *afc_hs_filter_cfg &= ~(PDSS_AFC_HS_FILTER_CFG_DM_FILT_SEL_MASK);
    *afc_hs_filter_cfg |= (PDSS_AFC_HS_FILTER_CFG_DM_FILT_EN);

#if (defined(CY_DEVICE_PMG1S3))
    /* Enable clock */
    pd->ctrl |= (uint32_t)PDSS_CTRL_AFC_ENABLED;
#endif /* (defined(CY_DEVICE_PMG1S3)) */

    return CY_USBPD_STAT_SUCCESS;

#else
    CY_UNUSED_PARAMETER(context);
    return CY_USBPD_STAT_NOT_SUPPORTED;
#endif /* (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))  */
}

/*******************************************************************************
* Function Name: Cy_USBPD_Bch_AfcSrcStart
****************************************************************************//**
*
* This function starts the AFC source state machine operations. Cy_USBPD_Bch_AfcSrcInit
* function must be called before this function call.
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \return
* cy_en_usbpd_status_t
*
*******************************************************************************/
cy_en_usbpd_status_t Cy_USBPD_Bch_AfcSrcStart(cy_stc_usbpd_context_t *context)
{
#if (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) 
    PPDSS_REGS_T pd = context->base;
    volatile uint32_t *afc_opcode_ctrl = NULL;

#if (defined(CY_DEVICE_CCG3PA))
    uint8_t chgb_id = context->port;
#if CY_FLIPPED_DP_DM
    chgb_id = (chgb_id == 0u) ? 1u : 0u;
#endif /* CY_FLIPPED_DP_DM */
#else
    uint8_t chgb_id = 0;
#endif /* (defined(CY_DEVICE_CCG3PA) */

#if (defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
    afc_opcode_ctrl = &pd->afc_opcode_ctrl;
    CY_UNUSED_PARAMETER(chgb_id);
#else
    afc_opcode_ctrl = &pd->afc_opcode_ctrl[chgb_id];
#endif /* defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1) || defined(CY_DEVICE_PAG2S) */
    
    /* Set opcode for afc source operation */
    *afc_opcode_ctrl = AFC_SOURCE_OPCODE | (1UL << 29u);
    
    Cy_SysLib_DelayUs (10);

    /* Enable Interrupts */ 
#if defined(CY_DEVICE_CCG3PA)
    if (chgb_id == 0)
    {
        pd->intr4 = CHGB_AFC_INTR4_PORT0_ALL_INTR_BIT_MASK;
    }
    else
    {
        pd->intr4 = CHGB_AFC_INTR4_PORT1_ALL_INTR_BIT_MASK;
    }

    pd->intr4_mask |= (((1 << PDSS_INTR4_AFC_SM_IDLE_POS) |
            (1 << PDSS_INTR4_UPDATE_PING_PONG_POS) |
            (1 << PDSS_INTR4_AFC_RX_RESET_POS)) << chgb_id);
#else
    pd->intr4 = (PDSS_INTR4_AFC_PING_RECVD | PDSS_INTR4_AFC_SM_IDLE |
                 PDSS_INTR4_AFC_TIMEOUT | PDSS_INTR4_AFC_RX_RESET |
                 PDSS_INTR4_UPDATE_PING_PONG | PDSS_INTR4_AFC_ERROR);

    pd->intr4_mask |= ((PDSS_INTR4_AFC_SM_IDLE) |
                (PDSS_INTR4_UPDATE_PING_PONG) |
                (PDSS_INTR4_AFC_RX_RESET));
#endif /* defined(CY_DEVICE_CCG3PA) */

    context->bcAfcRxIdx = 0;

    /* Start operation */
    *afc_opcode_ctrl |= PDSS_AFC_OPCODE_CTRL_OP_CODE_START;

    return CY_USBPD_STAT_SUCCESS;
    
#else
    CY_UNUSED_PARAMETER(context);
    return CY_USBPD_STAT_NOT_SUPPORTED;
#endif /* (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))  */
}

/*******************************************************************************
* Function Name: Cy_USBPD_Bch_AfcSrcStop
****************************************************************************//**
*
* This function stops the AFC source state machine operations.
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \return
* cy_en_usbpd_status_t
*
*******************************************************************************/
cy_en_usbpd_status_t Cy_USBPD_Bch_AfcSrcStop(cy_stc_usbpd_context_t *context)
{
    PPDSS_REGS_T pd = context->base;
    uint8_t cport=context->port;
    cy_en_usbpd_status_t stat = CY_USBPD_STAT_BAD_PARAM;

#if (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2) || defined(CY_DEVICE_PAG1S))
    uint32_t intr_mask;
    uint8_t chgb_id = cport;
#if ((defined(CY_DEVICE_CCG3PA)) && (CY_FLIPPED_DP_DM))
    chgb_id = (cport == 0) ? 1 : 0;
#endif /* (defined(CY_DEVICE_CCG3PA)) && (CY_FLIPPED_DP_DM) */

    intr_mask = CHGB_AFC_INTR4_PORT0_ALL_INTR_BIT_MASK << chgb_id;
    /* Disable Interrupts */
    pd->intr4_mask &= ~(intr_mask);
    pd->intr4 = intr_mask;
#else
    uint32_t intr_mask;
    intr_mask = (PDSS_INTR4_AFC_PING_RECVD | PDSS_INTR4_AFC_SM_IDLE |
                PDSS_INTR4_AFC_TIMEOUT | PDSS_INTR4_AFC_RX_RESET |
                PDSS_INTR4_UPDATE_PING_PONG | PDSS_INTR4_AFC_ERROR);
    
    /* Disable Interrupts */
    pd->intr4_mask &= ~(intr_mask);
    pd->intr4 = intr_mask;

    CY_UNUSED_PARAMETER(cport);
#endif /* CCGx */
    stat = CY_USBPD_STAT_SUCCESS;
    return stat;
}

/*******************************************************************************
* Function Name: Cy_USBPD_Bch_AfcGetRxDataPtr
****************************************************************************//**
*
* This function returns the AFC (Adaptive Fast Charging) received data pointer
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \return
* Received data pointer
*
*******************************************************************************/
uint8_t * Cy_USBPD_Bch_AfcGetRxDataPtr(cy_stc_usbpd_context_t *context)
{
    return context->bcAfcRxBuf;
}

/*******************************************************************************
* Function Name: Cy_USBPD_Bch_AfcGetRxDataCount
****************************************************************************//**
*
* This function returns the AFC(Adaptive Fast Charging) received data count
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \return
* received data count
*
*******************************************************************************/
uint8_t Cy_USBPD_Bch_AfcGetRxDataCount(cy_stc_usbpd_context_t *context)
{
#if (!BCR) && (!QC_AFC_SNK_EN)
    return context->bcAfcRxIdx + 1u;
#else
    return context->bcAfcRxIdx;
#endif
}

/*******************************************************************************
* Function Name: Cy_USBPD_Bch_AfcLoadTxData
****************************************************************************//**
*
* This function load the USBPD context AFC (Adaptive Fast Charging) tx data into AFC ping pong buffer.
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \return
* None
*
*******************************************************************************/
void Cy_USBPD_Bch_AfcLoadTxData(cy_stc_usbpd_context_t *context)
{
    uint8_t cport = context->port;
    PPDSS_REGS_T pd = context->base;
    uint16_t data;
#if defined(CY_DEVICE_CCG3PA)
    uint8_t chgb_id = cport;
#if CY_FLIPPED_DP_DM
    chgb_id = (chgb_id == 0) ? 1 : 0;
#endif /* CY_FLIPPED_DP_DM */
#endif /* defined(CY_DEVICE_CCG3PA) */

#if (TYPE_A_PORT_ENABLE == 0)
    if (cport < NO_OF_TYPEC_PORTS)
#else
    if (cport < 2u)
#endif /* TYPE_A_PORT_ENABLE == 0 */
    {
        if(context->bcAfcTxIdx < context->bcAfcTxSize)
        {
            data = context->bcAfcTxBuf[context->bcAfcTxIdx++];

        if(context->bcAfcTxIdx < context->bcAfcTxSize)
        {
            data |= (uint16_t)(context->bcAfcTxBuf[context->bcAfcTxIdx++]) << 8u;
        }
#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1) || defined(CY_DEVICE_PMG1S3))
            pd->afc_ping_pong = data;
#elif defined(CY_DEVICE_PAG1S)
            pd->afc_ping_pong[cport] = data;
#elif defined(CY_DEVICE_CCG3PA)
            pd->afc_ping_pong[chgb_id] = data;
#endif /* CCGx */
            Cy_SysLib_DelayUs(2);
        }
    }
    else
    {
        /* Do Nothing */
    }
}

/*******************************************************************************
* Function Name: Cy_USBPD_Bch_Afc_Set_Tx_Data
****************************************************************************//**
*
* This function transmits AFC (Adaptive Fast Charging) data buffer provided.
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \param dataPtr
* Transmit data buffer pointer
*
* \param count
* Transmit data count
*
* \return
* None
*
*******************************************************************************/
void Cy_USBPD_Bch_Afc_Set_Tx_Data(cy_stc_usbpd_context_t *context, uint8_t* dataPtr, uint8_t count)
{
#if (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) 
    PPDSS_REGS_T pd = context->base;
    uint32_t regval;
    uint8_t index = 0;
    volatile uint32_t *afc_1_ctrl = NULL;

#if (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG6))
    uint8_t cport=context->port;
    uint8_t chgb_id = cport;
#endif /* (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG6)) */
    
    context->bcAfcTxSize = count;
    context->bcAfcTxIdx = 0;
#if ((defined(CY_DEVICE_CCG3PA)) && (CY_FLIPPED_DP_DM))
    chgb_id = (cport == 0) ? 1 : 0;
#endif /* (defined(CY_DEVICE_CCG3PA)) && (CY_FLIPPED_DP_DM) */
    
#if (defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
    afc_1_ctrl = &pd->afc_1_ctrl;
#else
    afc_1_ctrl = &pd->afc_1_ctrl[chgb_id];
#endif /* (defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) */

    regval = *afc_1_ctrl & ~PDSS_AFC_1_CTRL_NO_OF_BYTES_TX_MASK;

    regval |= (uint32_t)count << PDSS_AFC_1_CTRL_NO_OF_BYTES_TX_POS;

    *afc_1_ctrl = regval;
    
    /* Copy data into AFC tx buffer */
    for (index = 0; index < count; index++)
    {
        context->bcAfcTxBuf[index]= *(dataPtr++);
    }

    Cy_USBPD_Bch_AfcLoadTxData(context);
    
#else
    CY_UNUSED_PARAMETER(context);
    CY_UNUSED_PARAMETER(dataPtr);
    CY_UNUSED_PARAMETER(count);
#endif /* (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))  */  
}

/*******************************************************************************
* Function Name: Cy_USBPD_Bch_AfcSinkInit
****************************************************************************//**
*
* This function initialize the AFC (Adaptive Fast Charging) clock, filters and enables block for sink 
* operations. 
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \return
* cy_en_usbpd_status_t
*
*******************************************************************************/
cy_en_usbpd_status_t Cy_USBPD_Bch_AfcSinkInit(cy_stc_usbpd_context_t *context)
{
#if (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_SERIES_WLC1) || defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3)) 
    PPDSS_REGS_T pd = context->base;
    volatile uint32_t *afc_1_ctrl = NULL;
    volatile uint32_t *afc_2_ctrl = NULL;
    volatile uint32_t *afc_hs_filter_cfg = NULL;
#if (defined(CY_DEVICE_CCG3PA))
    uint8_t chgb_id = context->port;
#if CY_FLIPPED_DP_DM
    chgb_id = (chgb_id == 0) ? 1 : 0;
#endif /* CY_FLIPPED_DP_DM */
#else
    uint8_t chgb_id = 0;
#endif /* (defined(CY_DEVICE_CCG3PA) */

#if defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_SERIES_WLC1)
    afc_1_ctrl = &pd->afc_1_ctrl;
    afc_2_ctrl = &pd->afc_2_ctrl;
    afc_hs_filter_cfg = &pd->afc_hs_filter_cfg;
    CY_UNUSED_PARAMETER(chgb_id);
#else
    afc_1_ctrl = &pd->afc_1_ctrl[chgb_id];
    afc_2_ctrl = &pd->afc_2_ctrl[chgb_id];
    afc_hs_filter_cfg = &pd->afc_hs_filter_cfg[chgb_id];
#endif /* defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_SERIES_WLC1) */

    *afc_1_ctrl &= ~(PDSS_AFC_1_CTRL_TX_RESET |
                     PDSS_AFC_1_CTRL_NO_OF_BYTES_TX_MASK);

    *afc_1_ctrl |= PDSS_AFC_1_CTRL_UPDATE_TXCLK;

    /* Update UI clock cycle count for 125kHz clock. */
    *afc_2_ctrl &= ~PDSS_AFC_2_CTRL_UI_COUNT_MASK;
    *afc_2_ctrl |= (QC3_DP_DM_PULSE_FILTER_CLOCK_SEL <<
                    PDSS_AFC_2_CTRL_UI_COUNT_POS);

    *afc_2_ctrl |= PDSS_AFC_2_CTRL_DISABLE_SYNC_ON_RX_BY_4_UI;

    /* Enable filter. */
    *afc_hs_filter_cfg &= ~(PDSS_AFC_HS_FILTER_CFG_DM_FILT_SEL_MASK);
    *afc_hs_filter_cfg |= (PDSS_AFC_HS_FILTER_CFG_DM_FILT_EN);

    /* Enable Clock */
    pd->ctrl |= PDSS_CTRL_AFC_ENABLED;

    return CY_USBPD_STAT_SUCCESS;

#else
    CY_UNUSED_PARAMETER(context);
    return CY_USBPD_STAT_NOT_SUPPORTED;
#endif /* (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_SERIES_WLC1) || defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3))  */
}

/*******************************************************************************
* Function Name: Cy_USBPD_Bch_AfcSinkStartPing
****************************************************************************//**
*
* This function sends a ping request to AFC (Adaptive Fast Charging) source.
* operations. 
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \return
* cy_en_usbpd_status_t
*
*******************************************************************************/
cy_en_usbpd_status_t Cy_USBPD_Bch_AfcSinkStartPing(cy_stc_usbpd_context_t *context)
{
#if (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_SERIES_WLC1) || defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3)) 
    PPDSS_REGS_T pd = context->base;
    volatile uint32_t *afc_opcode_ctrl = NULL;
#if (defined(CY_DEVICE_CCG3PA))
    uint8_t chgb_id = context->port;
#if CY_FLIPPED_DP_DM
    chgb_id = (chgb_id == 0) ? 1 : 0;
#endif /* CY_FLIPPED_DP_DM */
#else
    uint8_t chgb_id = 0;
#endif /* (defined(CY_DEVICE_CCG3PA) */

#if defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_SERIES_WLC1)
    afc_opcode_ctrl = &pd->afc_opcode_ctrl;
    CY_UNUSED_PARAMETER(chgb_id);
#else
    afc_opcode_ctrl = &pd->afc_opcode_ctrl[chgb_id];
#endif /* defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_SERIES_WLC1) */

    /* Set opcode for afc sink operation */
    *afc_opcode_ctrl = AFC_SINK_OPCODE_PING;

    /* Enable Interrupts */
#if defined(CY_DEVICE_CCG3PA)
    if (chgb_id == 0)
    {
        PDSS->intr4 = CHGB_AFC_INTR4_PORT0_ALL_INTR_BIT_MASK;
    }
    else
    {
        PDSS->intr4 = CHGB_AFC_INTR4_PORT1_ALL_INTR_BIT_MASK;
    }

    PDSS->intr4_mask |= (((1 << PDSS_INTR4_AFC_SM_IDLE_POS) |
                        (1 << PDSS_INTR4_UPDATE_PING_PONG_POS) |
                        (1 << PDSS_INTR4_AFC_RX_RESET_POS)) << chgb_id);
#else
    pd->intr4 = CHGB_AFC_INTR4_PORT0_ALL_INTR_BIT_MASK;

    pd->intr4_mask |= (PDSS_INTR4_AFC_SM_IDLE
                        | PDSS_INTR4_UPDATE_PING_PONG
                        | PDSS_INTR4_AFC_RX_RESET);
#endif /* defined(CY_DEVICE_CCG3PA) */

    context->bcAfcRxIdx = 0;

    /* Start operation */
    *afc_opcode_ctrl |= PDSS_AFC_OPCODE_CTRL_OP_CODE_START;

    return CY_USBPD_STAT_SUCCESS;

#else
    CY_UNUSED_PARAMETER(context);
    return CY_USBPD_STAT_NOT_SUPPORTED;
#endif /* (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_SERIES_WLC1) || defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3))  */
}

/*******************************************************************************
* Function Name: Cy_USBPD_Bch_AfcSinkStart
****************************************************************************//**
*
* This function configures the AFC (Adaptive Fast Charging) state machine, interrupts and stats the AFC
* sink operations. 
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \return
* cy_en_usbpd_status_t
*
*******************************************************************************/
cy_en_usbpd_status_t Cy_USBPD_Bch_AfcSinkStart(cy_stc_usbpd_context_t *context)
{
#if (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_SERIES_WLC1) || defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3)) 
    PPDSS_REGS_T pd = context->base;
    volatile uint32_t *afc_opcode_ctrl = NULL; 
#if (defined(CY_DEVICE_CCG3PA))
    uint8_t chgb_id = context->port;
#if CY_FLIPPED_DP_DM
    chgb_id = (chgb_id == 0) ? 1 : 0;
#endif /* CY_FLIPPED_DP_DM */
#else
    uint8_t chgb_id = 0;
#endif /* (defined(CY_DEVICE_CCG3PA) */

    /* Set opcode for afc sink operation */
#if defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_SERIES_WLC1)
    afc_opcode_ctrl = &pd->afc_opcode_ctrl;
    CY_UNUSED_PARAMETER(chgb_id);
#else
    afc_opcode_ctrl = &pd->afc_opcode_ctrl[chgb_id];
#endif /* defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_SERIES_WLC1) */

    /* Set opcode for afc sink operation */
    *afc_opcode_ctrl = AFC_SINK_OPCODE;

    /* Enable Interrupts */
#if defined(CY_DEVICE_CCG3PA)
    if (chgb_id == 0)
    {
        PDSS->intr4 = CHGB_AFC_INTR4_PORT0_ALL_INTR_BIT_MASK;
    }
    else
    {
        PDSS->intr4 = CHGB_AFC_INTR4_PORT1_ALL_INTR_BIT_MASK;
    }

    PDSS->intr4_mask |= (((1 << PDSS_INTR4_AFC_SM_IDLE_POS) |
                        (1 << PDSS_INTR4_UPDATE_PING_PONG_POS) |
                        /* Not used. Errors are handled in AFC sink state machine */
#if BC_AFC_SINK_ERROR_INT_ENABLE
                        (1 << PDSS_INTR4_AFC_ERROR_POS) |
                        (1 << PDSS_INTR4_AFC_TIMEOUT_POS) |
#endif /* BC_AFC_SINK_ERROR_INT_ENABLE */
                        (1 << PDSS_INTR4_AFC_RX_RESET_POS)) << chgb_id);
#else
    pd->intr4 = CHGB_AFC_INTR4_PORT0_ALL_INTR_BIT_MASK;
    
    pd->intr4_mask = ( PDSS_INTR4_AFC_SM_IDLE | PDSS_INTR4_UPDATE_PING_PONG |
                        /* Not used. Errors are handled in AFC sink state machine */
#if BC_AFC_SINK_ERROR_INT_ENABLE
                       PDSS_INTR4_AFC_ERROR | PDSS_INTR4_AFC_TIMEOUT |
#endif /* BC_AFC_SINK_ERROR_INT_ENABLE */
                       PDSS_INTR4_AFC_RX_RESET);
#endif /* CY_DEVICE_CCG3PA */

    context->bcAfcRxIdx = 0U;

    /* Start operation */
    *afc_opcode_ctrl |= PDSS_AFC_OPCODE_CTRL_OP_CODE_START;

    return CY_USBPD_STAT_SUCCESS;

#else
    CY_UNUSED_PARAMETER(context);
    return CY_USBPD_STAT_NOT_SUPPORTED;
#endif /* (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_SERIES_WLC1) || defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3))  */
}

/*******************************************************************************
* Function Name: Cy_USBPD_Bch_AfcSinkStop
****************************************************************************//**
*
* This function disables all AFC (Adaptive Fast Charging) interrupt.
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \return
* cy_en_usbpd_status_t
*
*******************************************************************************/
cy_en_usbpd_status_t Cy_USBPD_Bch_AfcSinkStop(cy_stc_usbpd_context_t *context)
{
#if (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_SERIES_WLC1) || defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3)) 
    PPDSS_REGS_T pd = context->base;
#if (defined(CY_DEVICE_CCG3PA))
    uint8_t chgb_id = context->port;
#if CY_FLIPPED_DP_DM
    chgb_id = (chgb_id == 0) ? 1 : 0;
#endif /* CY_FLIPPED_DP_DM */
#else
    uint8_t chgb_id = 0;
#endif /* (defined(CY_DEVICE_CCG3PA) */

    /* Disable Interrupts */
    pd->intr4_mask = 0;

#if defined(CY_DEVICE_CCG3PA)
    if (chgb_id == 0)
    {
        PDSS->intr4 = CHGB_AFC_INTR4_PORT0_ALL_INTR_BIT_MASK;
    }
    else
    {
        PDSS->intr4 = CHGB_AFC_INTR4_PORT1_ALL_INTR_BIT_MASK;
    }
#else
    pd->intr4 = CHGB_AFC_INTR4_PORT0_ALL_INTR_BIT_MASK;
    CY_UNUSED_PARAMETER(chgb_id);
#endif /* defined(CY_DEVICE_CCG3PA) */
    return CY_USBPD_STAT_SUCCESS;

#else
    CY_UNUSED_PARAMETER(context);
    return CY_USBPD_STAT_NOT_SUPPORTED;
#endif /* (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_SERIES_WLC1) || defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3))  */
}    

/*******************************************************************************
* Function Name: Cy_USBPD_Bch_QC3_IntrHandler
****************************************************************************//**
*
* This function handles the QC3 interrupts.
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \return
* None
*
*******************************************************************************/
void Cy_USBPD_Bch_QC3_IntrHandler(cy_stc_usbpd_context_t *context)
{
#if (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
    uint32_t dp_pulse, dm_pulse;
    uint32_t regval;
    uint8_t cport=context->port;
    
#if defined(CY_DEVICE_CCG3PA)
    uint8_t chgb_id = cport;
#if CY_FLIPPED_DP_DM
    chgb_id = (chgb_id == 0) ? 1 : 0;
#endif /* CY_FLIPPED_DP_DM */
#endif /* defined(CY_DEVICE_CCG3PA) */

#if (CCG_TYPE_A_PORT_ENABLE == 0)
    if (cport < NO_OF_TYPEC_PORTS)
#else
    if (cport < 2u)
#endif /* CCG_TYPE_A_PORT_ENABLE == 0 */
    {
        PPDSS_REGS_T pd = context->base;

        /* Clear interrupts */
#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1) || defined(CY_DEVICE_PMG1S3))
        pd->intr6 = QC3_PORT_0_DP_DM_PULSE_MASK;
#elif defined(PAG1S)
        pd->intr6 = QC3_PORT_0_DP_DM_PULSE_MASK << cport;
#else
        pd->intr6 = QC3_PORT_0_DP_DM_PULSE_MASK << chgb_id;
#endif /* CCGx */

        /* Read count */
#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1) || defined(CY_DEVICE_PMG1S3))
        pd->qc3_chrger_ctrl |= PDSS_QC3_CHRGER_CTRL_READ_DPDM_COUNT;
        while(((pd->qc3_chrger_ctrl & PDSS_QC3_CHRGER_CTRL_READ_DPDM_COUNT) != 0u)) {};
        regval = pd->qc3_chrger_ctrl;
#elif defined(CY_DEVICE_PAG1S)
        pd->qc3_chrger_ctrl[cport] |= PDSS_QC3_CHRGER_CTRL_READ_DPDM_COUNT;
        while(gl_PDSS->qc3_chrger_ctrl[cport] & PDSS_QC3_CHRGER_CTRL_READ_DPDM_COUNT);
        regval = pd->qc3_chrger_ctrl[cport];
#else
        pd->qc3_chrger_ctrl[chgb_id] |= PDSS_QC3_CHRGER_CTRL_READ_DPDM_COUNT;
        while(pd->qc3_chrger_ctrl[chgb_id] & PDSS_QC3_CHRGER_CTRL_READ_DPDM_COUNT);
        regval = pd->qc3_chrger_ctrl[chgb_id];
#endif /* CCGx */

    dp_pulse = (regval & PDSS_QC3_CHRGER_CTRL_DP_PULSE_COUNT_MASK)
    >> PDSS_QC3_CHRGER_CTRL_DP_PULSE_COUNT_POS;
    dm_pulse = (regval & PDSS_QC3_CHRGER_CTRL_DM_PULSE_COUNT_MASK)
                    >> PDSS_QC3_CHRGER_CTRL_DM_PULSE_COUNT_POS;
    context->bcQcPulseCount += ((int32_t)dp_pulse - (int32_t)dm_pulse);

    /* Report an QC continuous event. */
    if (context->bcPhyCbk != NULL)
    {
        context->bcPhyCbk(context, BC_EVT_QC_CONT);
    }
    }
    else
    {
        /* Do Nothing */
    }

#else
    CY_UNUSED_PARAMETER(context);
#endif /* (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3)  || (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))  */    
}

/*******************************************************************************
* Function Name: Cy_USBPD_Bch_AfcPingPong_IntrHandler
****************************************************************************//**
*
* This function handles the AFC ping pong interrupts and copies data into context
* buffer. 
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \return
* None
*
*******************************************************************************/
void Cy_USBPD_Bch_AfcPingPong_IntrHandler(cy_stc_usbpd_context_t *context)
{
#if (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) 
    PPDSS_REGS_T pd = context->base;
    volatile uint32_t *afc_sm_status = NULL;
    volatile uint32_t *afc_ping_pong = NULL;
#if defined(CY_DEVICE_CCG3PA)
    uint8_t cport = context->port;
    uint8_t chgb_id = cport;
#if CY_FLIPPED_DP_DM
    chgb_id = (chgb_id == 0) ? 1 : 0;
#endif /* CY_FLIPPED_DP_DM */

#if (BCR == 1)
    /* Note: BCR2 uses BC_block 1 so chgb_id (index of IP block) is set to 1 while cport(index of pd_status and timer structures)
     * is forced to 0. BCR2 has only one PD port and this trick decreases SRAM usage.
     */
    cport = 0;
#endif /* (BCR == 1) */
#endif /* defined(CY_DEVICE_CCG3PA) */

#if (defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
    afc_sm_status = &pd->afc_sm_status;
    afc_ping_pong = &pd->afc_ping_pong;
#else
    afc_sm_status = &pd->afc_sm_status[chgb_id];
    afc_ping_pong = &pd->afc_ping_pong[chgb_id];
#endif /* defined(CY_DEVICE_PMG1S3) */

    if(((*afc_sm_status & PDSS_AFC_SM_STATUS_CURR_OP_CODE_MASK)
         >> PDSS_AFC_SM_STATUS_CURR_OP_CODE_POS) == AFC_TX_DATA_S_OPCODE)
    {
        /* TX going on */
        Cy_USBPD_Bch_AfcLoadTxData(context);
    }
        /* Reset received message index on parity error.*/
#if ((BCR == 1) || QC_AFC_SNK_EN) && (AFC_PARITY_CHECK_ENABLE)
        else if(((*afc_sm_status & PDSS_AFC_SM_STATUS_MASTER_PARITY_ERROR_STATUS_MASK)
             >> PDSS_AFC_SM_STATUS_MASTER_PARITY_ERROR_STATUS_POS) )
        {
                context->bcAfcRxIdx =0;
        }
#endif /* ((BCR == 1) ||  || QC_AFC_SNK_EN) && (AFC_PARITY_CHECK_ENABLE) */
    else
    {
        /* RX going on */
        if(context->bcAfcRxIdx < AFC_MAX_BYTES)
        {
            context->bcAfcRxBuf[context->bcAfcRxIdx++] = CY_USBPD_DWORD_GET_BYTE0(*afc_ping_pong);
        }
        
        if((context->bcAfcRxIdx < AFC_MAX_BYTES)
#if BCR || QC_AFC_SNK_EN
               && (context->bcAfcRxIdx < (*afc_sm_status &
               PDSS_AFC_SM_STATUS_MASTER_NUM_OF_SLAVE_BYTES_RCVD_MASK)>>
               PDSS_AFC_SM_STATUS_MASTER_NUM_OF_SLAVE_BYTES_RCVD_POS)
#endif  /* BCR || QC_AFC_SNK_EN */
            )
        {
            context->bcAfcRxBuf[context->bcAfcRxIdx++] = CY_USBPD_DWORD_GET_BYTE1(*afc_ping_pong);
        }

#if (!QC_SRC_AFC_CHARGING_DISABLED)
        /* For AFC source, only 1 byte will be received so creating this event here.
         * Later when AFC sink is to be implemented then we need to put a check if source
         * only then create event
         */
        if (context->bcPhyCbk != NULL)
        {
            context->bcPhyCbk(context, BC_EVT_AFC_MSG_RCVD);
        }
#endif /* (!QC_SRC_AFC_CHARGING_DISABLED) */
    }
    
#else
    CY_UNUSED_PARAMETER(context);
#endif /* (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))  */
}

/*******************************************************************************
* Function Name: Cy_USBPD_Bch_AfcIdle_IntrHandler
****************************************************************************//**
*
* This function handles the AFC idle interrupt.
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \return
* None
*
*******************************************************************************/
void Cy_USBPD_Bch_AfcIdle_IntrHandler(cy_stc_usbpd_context_t *context)
{
#if (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) 
#if defined(CY_DEVICE_CCG3PA)
    uint8_t cport=context->port;
    uint8_t chgb_id = cport;
#if CY_FLIPPED_DP_DM
    chgb_id = (chgb_id == 0) ? 1 : 0;
#endif /* CY_FLIPPED_DP_DM */

#if (BCR == 1)
    /* Note: BCR2 uses BC_block 1 so chgb_id (index of IP block) is set to 1 while cport(index of pd_status and timer structures)
     * is forced to 0. BCR2 has only one PD port and this trick decreases SRAM usage.
     */
    cport = 0;
#endif /* (BCR == 1) */
#endif /* defined(CY_DEVICE_CCG3PA) */
    PPDSS_REGS_T pd = context->base;
    uint32_t event;

#if (defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1) || defined(CY_DEVICE_PAG2S))
    if((pd->intr4 & (PDSS_INTR4_AFC_ERROR | PDSS_INTR4_AFC_TIMEOUT)) != 0UL)
#else /* CCG3PA */
    if((pd->intr4 & (1 << (PDSS_INTR4_AFC_ERROR_POS + chgb_id) | (1 << (PDSS_INTR4_AFC_TIMEOUT_POS + chgb_id)))) != 0UL)
#endif /* (defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1) || defined(CY_DEVICE_PAG2S)) */
    {
        event = BC_EVT_AFC_MSG_SEND_FAIL;
    }
    else
    {
        event = BC_EVT_AFC_MSG_SENT;
    }
    
    if (context->bcPhyCbk != NULL)
    {
        context->bcPhyCbk(context, event);
    }
    
#else
    CY_UNUSED_PARAMETER(context);
#endif /* (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3)  || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))  */
}

/*******************************************************************************
* Function Name: Cy_USBPD_Bch_AfcReset_IntrHandler
****************************************************************************//**
*
* This function handles the AFC reset interrupt.
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \return
* None
*
*******************************************************************************/
void Cy_USBPD_Bch_AfcReset_IntrHandler(cy_stc_usbpd_context_t *context)
{
    uint8_t cport=context->port;
#if (BCR == 1)
    /* Note: BCR2 uses BC_block 1 so chgb_id (index of IP block) is set to 1 while cport(index of pd_status and timer structures)
     * is forced to 0. BCR2 has only one PD port and this trick decreases SRAM usage.
     */
    cport = 0u;
#endif /* (BCR == 1) */

#if (CCG_TYPE_A_PORT_ENABLE == 0)
    if (cport < NO_OF_TYPEC_PORTS)
#else
    if (cport < 2u)
#endif /* CCG_TYPE_A_PORT_ENABLE==0 */
    {
        /* Report reset received event. */
        if (context->bcPhyCbk != NULL)
        {
            context->bcPhyCbk(context, BC_EVT_AFC_RESET_RCVD);
        }
    }
    else
    {
        /* No Statement */
    }
}


/*******************************************************************************
* Function Name: Cy_USBPD_Bch_Intr0Handler
****************************************************************************//**
*
* This function handles the Battery Charging interrupts related to AFC and QC.
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \return
* None
*
*******************************************************************************/
void Cy_USBPD_Bch_Intr0Handler(cy_stc_usbpd_context_t *context)
{
#if (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) 
    PPDSS_REGS_T pd = context->base;
#if (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2))
    if(pd->intr4_masked != 0)
    {
        if (pd->intr4_masked & (1 << PDSS_INTR4_UPDATE_PING_PONG_POS))
        {
            Cy_USBPD_Bch_AfcPingPong_IntrHandler(context);
            pd->intr4 = 1 << PDSS_INTR4_UPDATE_PING_PONG_POS;
        }

        if (pd->intr4_masked & (1 << (PDSS_INTR4_UPDATE_PING_PONG_POS + 1)))
        {
            Cy_USBPD_Bch_AfcPingPong_IntrHandler(context->altPortUsbPdCtx[0]);
            pd->intr4 = 1 << (PDSS_INTR4_UPDATE_PING_PONG_POS + 1);
        }

        if (pd->intr4_masked & (1 << PDSS_INTR4_AFC_SM_IDLE_POS))
        {
            Cy_USBPD_Bch_AfcIdle_IntrHandler(context);
            pd->intr4 = (
                       (1 << PDSS_INTR4_AFC_SM_IDLE_POS)
#if BCR || QC_AFC_SNK_EN
                       |(1 << PDSS_INTR4_AFC_ERROR_POS) |
                       (1 << PDSS_INTR4_AFC_TIMEOUT_POS)
#endif /* BCR || QC_AFC_SNK_EN */
);
        }

        if (pd->intr4_masked & (1 << (PDSS_INTR4_AFC_SM_IDLE_POS + 1)))
        {
            Cy_USBPD_Bch_AfcIdle_IntrHandler(context->altPortUsbPdCtx[0]);
            pd->intr4 = ((1 << (PDSS_INTR4_AFC_SM_IDLE_POS + 1))
#if BCR || QC_AFC_SNK_EN
                       |(1 << (PDSS_INTR4_AFC_ERROR_POS + 1)) |
                       (1 << (PDSS_INTR4_AFC_TIMEOUT_POS + 1))
#endif /* BCR || QC_AFC_SNK_EN */
                    );
        }

        if (pd->intr4_masked & (1 << PDSS_INTR4_AFC_RX_RESET_POS))
        {
            Cy_USBPD_Bch_AfcReset_IntrHandler(context);
            pd->intr4 = 1 << PDSS_INTR4_AFC_RX_RESET_POS;
        }

        if (pd->intr4_masked & (1 << (PDSS_INTR4_AFC_RX_RESET_POS + 1)))
        {
            Cy_USBPD_Bch_AfcReset_IntrHandler(context->altPortUsbPdCtx[0]);
            pd->intr4 = 1 << (PDSS_INTR4_AFC_RX_RESET_POS + 1);
        }
    }
    if(pd->intr6_masked != 0)
    {
        if (pd->intr6_masked & QC3_PORT_0_DP_DM_PULSE_MASK)
        {
            Cy_USBPD_Bch_QC3_IntrHandler(context);

        }
        if (pd->intr6_masked & QC3_PORT_1_DP_DM_PULSE_MASK)
        {
            Cy_USBPD_Bch_QC3_IntrHandler(context->altPortUsbPdCtx[0]);
        }
    }
#else /* defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2) */
    if(pd->intr4_masked != 0u)
    {
        if ((pd->intr4_masked & (PDSS_INTR4_UPDATE_PING_PONG)) != 0u)
        {
            Cy_USBPD_Bch_AfcPingPong_IntrHandler(context);
            pd->intr4 = PDSS_INTR4_UPDATE_PING_PONG;
        }
        if ((pd->intr4_masked & (PDSS_INTR4_AFC_SM_IDLE)) != 0u)
        {
            Cy_USBPD_Bch_AfcIdle_IntrHandler(context);
            pd->intr4 = (PDSS_INTR4_AFC_SM_IDLE); 
        }
        if ((pd->intr4_masked & (PDSS_INTR4_AFC_RX_RESET)) != 0u)
        {
            Cy_USBPD_Bch_AfcReset_IntrHandler(context);
            pd->intr4 = PDSS_INTR4_AFC_RX_RESET;
        }
#if QC_AFC_SNK_EN
        pd->intr4 = (PDSS_INTR4_AFC_ERROR |
            PDSS_INTR4_AFC_TIMEOUT);
#endif /* QC_AFC_SNK_EN */
    }

    if(pd->intr6_masked != 0u)
    {
        if ((pd->intr6_masked & QC3_PORT_0_DP_DM_PULSE_MASK) != 0u)
        {
            Cy_USBPD_Bch_QC3_IntrHandler(context);

        }
    }
#endif /* (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2)) */
#else
    CY_UNUSED_PARAMETER(context);
#endif /* (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))  */
}
#endif /* (!QC_AFC_CHARGING_DISABLED) */
/*******************************************************************************
* Function Name: Cy_USBPD_Bch_Intr1Handler
****************************************************************************//**
*
* This function handles the Battery Charging interrupts.
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \return
* None
*
*******************************************************************************/
void Cy_USBPD_Bch_Intr1Handler(cy_stc_usbpd_context_t *context)
{
    PPDSS_REGS_T pd = context->base ;

#if defined(CY_IP_MXUSBPD)
    if ((pd->intr9_masked & BCH_PORT_0_CMP1_INTR_MASK) != 0u)
    {
        /* Disable and clear interrupts. */
        pd->intr9_mask &= ~BCH_PORT_0_CMP1_INTR_MASK;
        pd->intr9 = BCH_PORT_0_CMP1_INTR_MASK;

        /* Report an CMP1 fire event. */
        if (context->bcPhyCbk != NULL)
        {
            context->bcPhyCbk(context, BC_EVT_CMP1_FIRE);
        }
    }

    if ((pd->intr9_masked & BCH_PORT_0_CMP2_INTR_MASK) != 0u)
    {
        /* Disable and clear interrupts. */
        pd->intr9_mask &= ~BCH_PORT_0_CMP2_INTR_MASK;
        pd->intr9 = BCH_PORT_0_CMP2_INTR_MASK;

        /* Report an CMP2 fire event. */
        if (context->bcPhyCbk != NULL)
        {
            context->bcPhyCbk(context, BC_EVT_CMP2_FIRE);
        }
    }

#if (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2))
#if ((NO_OF_BC_PORTS == 2) || (CY_FLIPPED_DP_DM))
    if ((pd->intr9_masked & BCH_PORT_1_CMP1_INTR_MASK) != 0u)
    {
        /* Disable and clear interrupts. */
        pd->intr9_mask &= ~BCH_PORT_1_CMP1_INTR_MASK;
        pd->intr9 = BCH_PORT_1_CMP1_INTR_MASK;

        /* Report an CMP1 fire event. */
        if (context->bcPhyCbk != NULL)
        {
            context->bcPhyCbk(context->altPortUsbPdCtx[0], BC_EVT_CMP1_FIRE);
        }
    }

    if ((pd->intr9_masked & BCH_PORT_1_CMP2_INTR_MASK) != 0u)
    {
        /* Disable and clear interrupts. */
        pd->intr9_mask &= ~BCH_PORT_1_CMP2_INTR_MASK;
        pd->intr9 = BCH_PORT_1_CMP2_INTR_MASK;

        /* Report an CMP2 fire event. */
        if (context->bcPhyCbk != NULL)
        {
            context->bcPhyCbk(context->altPortUsbPdCtx[0], BC_EVT_CMP2_FIRE);
        }
    }
#endif /* ((NO_OF_BC_PORTS == 2) || (CY_FLIPPED_DP_DM)) */
#endif /* (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2)) */

#elif defined(CY_IP_M0S8USBPD)

    if ((pd->intr3_masked & PDSS_INTR3_MASKED_CHGDET_CHANGED_MASKED) != 0u)
    {
        /* Disable and clear interrupt. */
        pd->intr3_mask &= ~PDSS_INTR3_MASK_CHGDET_CHANGED_MASK;
        pd->intr3 = PDSS_INTR3_CHGDET_CHANGED;

        /* Report comparator fired. */
        if (context->bcPhyCbk != NULL)
        {
            context->bcPhyCbk(context, BC_EVT_CMP1_FIRE);
        }
    }

#else
    CY_UNUSED_PARAMETER(context);
#endif /* CY_IP */
}

#if (defined(CCG_CDP_EN) && BATTERY_CHARGING_ENABLE)

/*******************************************************************************
* Function Name: Cy_USBPD_Bch_CompareVolt
****************************************************************************//**
*
* This function compares input voltage with reference voltage.
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \param inp
* Input voltage \ref uint8_t
*
* \param vref
* Reference Voltage \ref uint8_t
*
* \return
* \ref bool
*
*******************************************************************************/

bool Cy_USBPD_Bch_CompareVolt(cy_stc_usbpd_context_t *context, uint8_t inp, uint8_t vref)
{
    bool stat = false;
    /* Defines which DP/DM lines to be routed to */
    uint8_t chgb_id;

#if (CCG_TYPE_A_PORT_ENABLE == 0)
    if (context->port < NO_OF_TYPEC_PORTS)
#else
    if (context->port < 2)
#endif
    {
        PPDSS_REGS_T pd = context->base;
#if CY_FLIPPED_DP_DM
        /* For applications which require the block to be routed to DP1/DM1 */
        /* QAC suppression 2995, 2997: When NO_OF_TYPEC_PORTS is 1, the check port == 0 is redundant.
         * Yet the check is retained for applications where NO_OF_TYPEC_PORTS is other than 1 */
        chgb_id = (context->port == 0u) ? 1u : 0u; /* PRQA S 2995, 2997 */
#else
#if (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2))
        chgb_id = context->port;
#else /* !(defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2)) */
        chgb_id = 0;
#endif /* (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2)) */
#endif /* !CY_FLIPPED_DP_DM */
        uint32_t val;

        uint32_t  intr_state = Cy_SysLib_EnterCriticalSection ();

        /* Configure the comparator for voltage measurement. */
        val = pd->bch_det_0_ctrl[chgb_id];

        val &= ~(PDSS_BCH_DET_0_CTRL_CMP1_INP_SEL_MASK | PDSS_BCH_DET_0_CTRL_CMP1_INN_SEL_MASK |
                PDSS_BCH_DET_0_CTRL_CMP1_OFFSET_EN | PDSS_BCH_DET_0_CTRL_CMP1_VREF_SEL_MASK | PDSS_BCH_DET_0_CTRL_EN_COMP1_CHGDET);
        val |= (
                ((uint32_t)inp << PDSS_BCH_DET_0_CTRL_CMP1_INP_SEL_POS) |
                ((uint32_t)CDP_CHGDET_COMP_INP_VREF << PDSS_BCH_DET_0_CTRL_CMP1_INN_SEL_POS) |
                ((uint32_t)vref << PDSS_BCH_DET_0_CTRL_CMP1_VREF_SEL_POS)
               );

        pd->bch_det_0_ctrl[chgb_id] = val | PDSS_BCH_DET_0_CTRL_EN_CHGDET | PDSS_BCH_DET_0_CTRL_EN_COMP1_CHGDET;

        /* Wait for 5 us and read the comparator output. */
        Cy_SysLib_DelayUs(5);
        val = pd->intr9_status_0;

#if (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2))
        stat = ((val & ((uint32_t)BCH_PORT_0_CMP1_INTR_MASK << ((uint32_t)chgb_id << 1))) != 0u);
#else /* !(defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2)) */
        stat = ((val & (BCH_PORT_0_CMP1_INTR_MASK)) != 0u);
#endif /* (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2)) */

        Cy_SysLib_ExitCriticalSection (intr_state);
    }
    else
    {
        /* Do nothing */
    }

    return stat;
}

/*******************************************************************************
* Function Name: Cy_USBPD_Bch_Dm_VoltPoll
****************************************************************************//**
*
* This function polls voltage on DM line.
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \return
* \ref void
*
*******************************************************************************/
void Cy_USBPD_Bch_Dm_VoltPoll(cy_stc_usbpd_context_t *context)
{
    PPDSS_REGS_T pd = context->base;;
    /* Defines which DP/DM lines to be routed to */
#if (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2))
    uint8_t chgb_id = context->port;
#if CY_FLIPPED_DP_DM
    /* For CCG3PA applications which require the block to be routed to DP1/DM1 */
    chgb_id = (chgb_id == 0u) ? 1u : 0u;
#endif /* CY_FLIPPED_DP_DM */
#else /* !(defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2)) */
    uint8_t chgb_id = 0;
#endif /* (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2)) */

    if ((pd->bch_det_0_ctrl[chgb_id] & PDSS_BCH_DET_0_CTRL_VDM_SRC_EN) != 0u)
    {
        /* Make sure that D- voltage is actually above 325 mV. Otherwise, turn off VDM-SRC supply. */
        if ((!Cy_USBPD_Bch_CompareVolt(context, CDP_CHGDET_COMP_INP_DM, CDP_CHGDET_VREF_325mV)))
        {
            context->cdpState.vdmsrcLvCnt++;
            if (context->cdpState.vdmsrcLvCnt >= MAX_CDP_VDMSRC_FAULT_COUNT)
            {
                /* Not updating the vdmsrc_on variable here to prevent repeated OFF/ON activity. */
                pd->bch_det_0_ctrl[chgb_id] &= ~PDSS_BCH_DET_0_CTRL_VDM_SRC_EN;
                context->cdpState.vdmsrcLvCnt = 0;
            }
        }
        else
        {
            context->cdpState.vdmsrcLvCnt = 0;
        }
    }
}

/*******************************************************************************
* Function Name: Cy_USBPD_Bch_BcDis
****************************************************************************//**
*
* This function disables CDP BC 1.2 operation.
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \return
* \ref void
*
*******************************************************************************/

void Cy_USBPD_Bch_BcDis(cy_stc_usbpd_context_t *context)
{
    PPDSS_REGS_T pd = context->base;
#if (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2))
    /* Defines which DP/DM lines to be routed to */
    uint8_t chgb_id = context->port;
#if CY_FLIPPED_DP_DM
    /* For CCG3PA applications which require the block to be routed to DP1/DM1 */
    chgb_id = (chgb_id == 0u) ? 1u : 0u;
#endif /* CY_FLIPPED_DP_DM */
#else /* !(defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2)) */
    uint8_t chgb_id = 0;
#endif /* (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2)) */

    /* Disable charger detect interrupt. */
    pd->intr9_mask &= ~PDSS_INTR9_MASK_BCH_DET_CHANGED_MASK_MASK;

    /* Disable outputs from the CHGDET block. */
    pd->bch_det_1_ctrl[chgb_id] = 0;

    /* Disable voltage source of D- pin. */
    pd->bch_det_0_ctrl[chgb_id] &= ~PDSS_BCH_DET_0_CTRL_VDM_SRC_EN;

    /* Disable current sink on the D+ pin. */
    pd->bch_det_0_ctrl[chgb_id] &= ~PDSS_BCH_DET_0_CTRL_IDP_SNK_EN;

    pd->bch_det_0_ctrl[chgb_id] = 0;
    pd->bch_det_0_ctrl[chgb_id] = PDSS_BCH_DET_0_CTRL_PD;

    /* Move all state machines to idle state. */
    context->cdpState.isActive     = false;
    context->cdpState.vdmsrcOn     = false;
    context->cdpState.vdmsrcLvCnt = 0;
}

/*******************************************************************************
* Function Name: Cy_USBPD_Bch_CdpSm
****************************************************************************//**
*
* This function defines BC 1.2 CDP State Machine
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \return
* \ref void
*
*******************************************************************************/

bool Cy_USBPD_Bch_CdpSm(cy_stc_usbpd_context_t *context)
{
    PPDSS_REGS_T pd = context->base;
#if (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2))
    /* Defines which DP/DM lines to be routed to */
    uint8_t chgb_id = context->port;
#if CY_FLIPPED_DP_DM
    /* For CCG3PA applications which require the block to be routed to DP1/DM1 */
    chgb_id = (chgb_id == 0u) ? 1u : 0u;
#endif /* CY_FLIPPED_DP_DM */
#else /* !(defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2)) */
    uint8_t chgb_id = 0;
#endif /* (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2)) */

    if (context->cdpState.isActive  == true)
    {
        /* Clear any pending charger detect block interrupt. */
        pd->intr9 = ((uint32_t)BCH_PORT_0_CMP1_INTR_MASK << ((uint32_t)chgb_id << 1));
        /* Check whether D+ voltage is in the 0.325 - 0.85 V window. */
        if (Cy_USBPD_Bch_CompareVolt(context, CDP_CHGDET_COMP_INP_DP, CDP_CHGDET_VREF_325mV))
        {
            /* D+ voltage is within 0.825 V window */
            if (!Cy_USBPD_Bch_CompareVolt(context, CDP_CHGDET_COMP_INP_DP, CDP_CHGDET_VREF_850mV))
            {
                /* D+ voltage is in the correct window. Enable voltage source on D-. */
                if (!context->cdpState.vdmsrcOn )
                {
                    pd->bch_det_0_ctrl[chgb_id] |= PDSS_BCH_DET_0_CTRL_VDM_SRC_EN;
                    context->cdpState.vdmsrcOn  = true;
                    context->cdpState.vdmsrcLvCnt = 0;

                    /* Make sure the first D- voltage check is done 15 ms later. */
                    context->timerStopcbk(context, CY_USBPD_APP_BC_GENERIC_TIMER1);
                }
            }
            else
            {
                /* Voltage has gone beyond 0.8 V. Turn off Vdm_src, and return to idle state. */
                Cy_USBPD_Bch_BcDis(context);
                return false;
            }
        }
        else
        {
            /* D+ Voltage has fallen below 0.325 V again. Disable voltage source on D-. */
            if (context->cdpState.vdmsrcOn)
            {
                pd->bch_det_0_ctrl[chgb_id] &= ~PDSS_BCH_DET_0_CTRL_VDM_SRC_EN;
                context->cdpState.vdmsrcOn = false;
            }
        }

        /* Leave the comparator configured for D+ comparison against 325 mV. */
        pd->intr9 = ((uint32_t)BCH_PORT_0_CMP1_INTR_MASK << ((uint32_t)chgb_id << 1));
        (void)Cy_USBPD_Bch_CompareVolt(context, CDP_CHGDET_COMP_INP_DP, CDP_CHGDET_VREF_325mV);

        /* Configure the charger detect interrupt to fire on any change in voltage. */
        pd->intr9_cfg_bch_det[chgb_id] |= ((uint32_t)CHGB_COMP_EDGE_BOTH << PDSS_INTR9_CFG_BCH_DET_BCH_DET_COMP0_CFG_POS);
        pd->intr9_mask |= ((uint32_t)BCH_PORT_0_CMP1_INTR_MASK << ((uint32_t)chgb_id << 1));

        /* State machine has more work to do. */
        return true;
    }
    else
    {
        return false;
    }
}

/*******************************************************************************
* Function Name: Cy_USBPD_Bch_CdpEn
****************************************************************************//**
*
* This function starts BC CDP operation
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \return
* \ref void
*
*******************************************************************************/
void Cy_USBPD_Bch_CdpEn(cy_stc_usbpd_context_t *context)
{
    PPDSS_REGS_T pd = context->base;
#if (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2))
    /* Defines which DP/DM lines to be routed to */
    uint8_t chgb_id = context->port;
#if CY_FLIPPED_DP_DM
    /* For CCG3PA applications which require the block to be routed to DP1/DM1 */
    chgb_id = (chgb_id == 0u) ? 1u : 0u;
#endif /* CY_FLIPPED_DP_DM */
#else /* !(defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2)) */
    uint8_t chgb_id = 0;
#endif /* (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2)) */

    /* Enable the charger detect block. */
    pd->bch_det_0_ctrl[chgb_id] = 0;
    pd->bch_det_0_ctrl[chgb_id] = PDSS_BCH_DET_0_CTRL_EN_CHGDET;
    pd->bch_det_1_ctrl[chgb_id] = PDSS_BCH_DET_1_CTRL_CHGDET_ISO_N;

    /* Enable current sink on the D+ pin. */
    pd->bch_det_0_ctrl[chgb_id] |= PDSS_BCH_DET_0_CTRL_IDP_SNK_EN;

    /* Disable the filtering of the chgdet comparator output and enable bypass. */
    pd->intr9_cfg_bch_det[chgb_id] &= ~PDSS_INTR9_CFG_BCH_DET_BCH_DET_COMP0_FILT_EN;
    pd->intr9_cfg_bch_det[chgb_id] |= PDSS_INTR9_CFG_BCH_DET_BCH_DET_COMP0_FILT_BYPASS;

    /* Configure the comparator to check whether D+ voltage is higher than 325 mV. */
    (void)Cy_USBPD_Bch_CompareVolt(context, CDP_CHGDET_COMP_INP_DP, CDP_CHGDET_VREF_325mV);

    context->cdpState.isActive = true;
    Cy_SysLib_DelayUs (1);
    (void)Cy_USBPD_Bch_CdpSm(context);
}

/*******************************************************************************
* Function Name: Cy_USBPD_Cdp_Cbk_Wrapper
****************************************************************************//**
*
* This function checks if CDP state machine is busy.
*
* \param callbackContext
* Pointer to the callback context structure.
*
* \param id
* Timer instance used for the CDP debounce.
*
* \return
* \ref void
*
*******************************************************************************/

static void Cy_USBPD_Cdp_Cbk_Wrapper(cy_en_usbpd_timer_id_t id, void *callbackContext)
{
    cy_stc_usbpd_context_t *context=callbackContext;
     /* CDP debounced. Invoke callback. */
    Cy_USBPD_Bch_Dm_VoltPoll(context);
    CY_UNUSED_PARAMETER(id);
}

/*******************************************************************************
* Function Name: Cy_USBPD_Bch_Is_Cdp_SmBusy
****************************************************************************//**
*
* This function checks if CDP state machine is busy.
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \return
* \ref void
*
*******************************************************************************/

bool Cy_USBPD_Bch_Is_Cdp_SmBusy(cy_stc_usbpd_context_t *context)
{
    PPDSS_REGS_T pd = context->base;
    bool cdp_busy = false;
#if (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2))
    /* Defines which DP/DM lines to be routed to */
    uint8_t chgb_id = context->port;
#if CY_FLIPPED_DP_DM
    /* For CCG3PA applications which require the block to be routed to DP1/DM1 */
    chgb_id = (chgb_id == 0u) ? 1u : 0u;
#endif /* CY_FLIPPED_DP_DM */
#else /* !(defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2)) */
    uint8_t chgb_id = 0;
#endif /* (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2)) */

    if (context->cdpState.isActive)
    {
        if ((pd->bch_det_0_ctrl[chgb_id] & PDSS_BCH_DET_0_CTRL_VDM_SRC_EN) != 0u)
        {
            /* We cannot go to sleep while VDM_SRC supply is enabled. */
            cdp_busy = true;
        }

        /* Wake periodically to check voltage while the CDP state machine is running. */
        if (!context->timerIsRunningcbk(context, CY_USBPD_APP_BC_GENERIC_TIMER1))
        {
            if (context->cdpState.vdmsrcLvCnt != 0u)
            {
                (void)context->timerStartcbk(context, context, CY_USBPD_APP_BC_GENERIC_TIMER1, CDP_VDMSRC_FAULT_CHECK_PERIOD, Cy_USBPD_Cdp_Cbk_Wrapper);
            }
            else
            {
                (void)context->timerStartcbk(context, context, CY_USBPD_APP_BC_GENERIC_TIMER1, CDP_DX_VOLTAGE_CHECK_PERIOD, Cy_USBPD_Cdp_Cbk_Wrapper);
            }
        }
    }

    return (cdp_busy);
}
#endif /* (defined(CCG_CDP_EN) && BATTERY_CHARGING_ENABLE) */
#endif /* (!defined(CY_DEVICE_CCG6DF_CFP)) */
#endif /* (defined(CY_IP_MXUSBPD) || defined(CY_IP_M0S8USBPD)) */
/* [] END OF FILE */
