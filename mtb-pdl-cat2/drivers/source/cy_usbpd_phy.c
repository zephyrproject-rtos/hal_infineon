/***************************************************************************//**
* \file cy_usbpd_phy.c
* \version 2.110
*
* The source file of the USBPD Transceiver driver.
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
#include "cy_device_headers.h"

#if (defined(CY_IP_MXUSBPD) || defined(CY_IP_M0S8USBPD))

#include "cy_usbpd_common.h"
#include "cy_usbpd_defines.h"
#include "cy_usbpd_phy.h"
#include "cy_usbpd_bch.h"
#include "cy_usbpd_hpd.h"
#if PDL_VBTR_ENABLE
#include "cy_usbpd_idac_ctrl.h"
#endif /* PDL_VBTR_ENABLE */

/* Select types of PD control messages for which GoodCRC response should be sent. All except
     GoodCRC are enabled. */
#define AUTO_CTRL_MESSAGE_GOODCRC_MASK_CFG      (0xFFFFFFFDU)

/* Select types of PD data messages for which GoodCRC response should be sent. */
#define AUTO_DATA_MESSAGE_GOODCRC_MASK_CFG      (0xFFFFFFFFU)

/* Select types of PD extended data messages for which GoodCRC response should be sent. */
#define AUTO_EXTD_MESSAGE_GOODCRC_MASK_CFG      (0xFFFFFFFFU)

/* Mask representing bits that should be ignored in a PD 2.0 message header. */
#define PD_MSG_HDR_REV2_IGNORE_MASK             (0x8010U)

/* Mask representing header bits that should be matched for expected GoodCRC detection. */
#define EXPECTED_GOOD_CRC_HDR_MASK              (0x7E0FUL)

/* Mask representing additional header bits that should be matched for expected GoodCRC detection
     during PD 3.0 operation. */
#define EXPECTED_GOOD_CRC_HDR_DIFF_MASK_REV3    (PD_MSG_HDR_REV2_IGNORE_MASK)

/* Mask to clear expected GoodCRC header field. */
#define EXPECTED_GOOD_CRC_CLEAR_MASK            (0xF1FFU)

/* 1/16 of the number of RX clock cycles required by CC receiver to detect idle state. */
#define RX_CNT_MAX_VAL                          (0x0FUL)

/* CC receiver voltage threshold selection. Must be set to 2 for a 12 MHz RX CLK. */
#define RX_UI_BOUNDARY_DELTA_VAL                (0x02UL)


/* Recommended CC transceiver settings for various PMG1 devices. */
#if defined(CY_DEVICE_CCG3)

#define RX_CNT_MAX_CFG                  (RX_CNT_MAX_VAL << PDSS_RX_CC_RX_CNT_MAX_POS)
#define RX_UI_BOUNDARY_DELTA_CFG        (RX_UI_BOUNDARY_DELTA_VAL << PDSS_RX_CC_RX_UI_BOUNDARY_DELTA_POS)
#define RX_CC_CFG                       (RX_CNT_MAX_CFG | RX_UI_BOUNDARY_DELTA_CFG | PDSS_RX_CC_DELAY_AUTO)

#define RX_SOP_GOOD_CRC_EN_CTRL_CFG     (PDSS_RX_SOP_GOOD_CRC_EN_CTRL_TX_SEND_DEFAULT_SOP_GOOD_CRC_EN | \
                                         PDSS_RX_SOP_GOOD_CRC_EN_CTRL_TX_SEND_PRIME_SOP_GOOD_CRC_EN |   \
                                         PDSS_RX_SOP_GOOD_CRC_EN_CTRL_TX_SEND_DBL_PRIME_SOP_GOOD_CRC_EN)

#define RX_SOP_GOOD_CRC_EN_CTRL_REV3_CFG (PDSS_RX_SOP_GOOD_CRC_EN_CTRL_TX_SEND_DEFAULT_SOP_GOOD_CRC_EN |        \
                                          PDSS_RX_SOP_GOOD_CRC_EN_CTRL_TX_SEND_PRIME_SOP_GOOD_CRC_EN |          \
                                          PDSS_RX_SOP_GOOD_CRC_EN_CTRL_TX_SEND_DBL_PRIME_SOP_GOOD_CRC_EN |      \
                                          PDSS_RX_SOP_GOOD_CRC_EN_CTRL_EXT_TX_SEND_DEFAULT_SOP_GOOD_CRC_EN |    \
                                          PDSS_RX_SOP_GOOD_CRC_EN_CTRL_EXT_TX_SEND_PRIME_SOP_GOOD_CRC_EN |      \
                                          PDSS_RX_SOP_GOOD_CRC_EN_CTRL_EXT_TX_SEND_DBL_PRIME_SOP_GOOD_CRC_EN)

#endif /* defined(CY_DEVICE_CCG3) */

#if (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))

#define RX_CNT_MAX_CFG                  (RX_CNT_MAX_VAL << PDSS_RX_CC_0_CFG_RX_CNT_MAX_POS)
#define RX_UI_BOUNDARY_DELTA_CFG        (RX_UI_BOUNDARY_DELTA_VAL << PDSS_RX_CC_0_CFG_RX_UI_BOUNDARY_DELTA_POS)
#define RX_CC_CFG                       (RX_CNT_MAX_CFG | RX_UI_BOUNDARY_DELTA_CFG)

#define RX_SOP_GOOD_CRC_EN_CTRL_CFG     (0u)
#define RX_SOP_GOOD_CRC_EN_CTRL_REV3_CFG (0u)

#endif /* CY_DEVICE */

/* RX_ORDER_SET_CTRL register configuration. */
#define RX_ORDER_SET_CTRL_CFG           (PDSS_RX_ORDER_SET_CTRL_SOP_CMP_OPT |           \
                                         PDSS_RX_ORDER_SET_CTRL_RST_CMP_OPT |           \
                                         PDSS_RX_ORDER_SET_CTRL_PREAMBLE_SOP_EN |       \
                                         PDSS_RX_ORDER_SET_CTRL_PREAMBLE_RST_EN)

/* CRC_COUNTER register configuration, 1ms. */
#define CRC_COUNTER_CFG                 (300u)

/* Bus Idle Configurations */
#define BUS_IDLE_CNT_VAL                (10UL)
#define IDLE_COUNTER_VAL                (40UL)
#define IFG_COUNTER_VAL                 (10UL)
#define BUS_IDLE_CNT_CFG                (BUS_IDLE_CNT_VAL << PDSS_INTER_PACKET_COUNTER_BUS_IDLE_CNT_POS)
#define IDLE_COUNTER_CFG                (IDLE_COUNTER_VAL << PDSS_INTER_PACKET_COUNTER_IDLE_COUNTER_POS)
#define IFG_COUNTER_CFG                 (IFG_COUNTER_VAL << PDSS_INTER_PACKET_COUNTER_IFG_COUNTER_POS)

/* INTER_PACKET_COUNTER register configuration. */
#define INTER_PACKET_COUNTER_CFG        (BUS_IDLE_CNT_CFG | IDLE_COUNTER_CFG | IFG_COUNTER_CFG)


#define EXTENDED_DATA_BIT_LOC_VAL                    (15UL)      /* Location of extended bit in header. */
#define EXTENDED_DATA_BYTE_FIRST_BIT_LOCATION_VAL    (16UL)      /* Location of first data byte in extended message. */
#define EXTENDED_DATA_BYTE_LAST_BIT_LOCATION_VAL     (24UL)      /* Location of second data byte in extended message. */
#define CHUNK_BIT_LOCATION_VAL                       (15UL)      /* Location of chunked bit in extended header. */

/* PD Header Info Configuration */
#define HEADER_INFO_CFG                          ((EXTENDED_DATA_BIT_LOC_VAL << 8) |                     \
                                                 (EXTENDED_DATA_BYTE_FIRST_BIT_LOCATION_VAL << 12) |    \
                                                 (EXTENDED_DATA_BYTE_LAST_BIT_LOCATION_VAL << 17) |     \
                                                 (CHUNK_BIT_LOCATION_VAL << 22))


#define PDSS_MAX_TX_MEM_SIZE                    (16u)   /* PD transmit FIFO size in 4-byte words. */
#define PDSS_MAX_TX_MEM_HALF_SIZE               (8u)    /* Half of PD transmit FIFO size in 4-byte words. */

#define PDSS_MAX_RX_MEM_SIZE                    (16u)   /* PD receive FIFO size in 4-byte words. */
#define PDSS_MAX_RX_MEM_HALF_SIZE               (8u)    /* Half of PD receive FIFO size in 4-byte words. */

/* Defines for different SOP RST Values */
#define EN_DEFAULT_SOP_DET_VAL              (1UL << PDSS_RX_ORDER_SET_CTRL_SOP_RST_EN_POS)
#define EN_PRIME_SOP_DET_VAL                (2UL << PDSS_RX_ORDER_SET_CTRL_SOP_RST_EN_POS)
#define EN_DBL_SOP_DET_VAL                  (4UL << PDSS_RX_ORDER_SET_CTRL_SOP_RST_EN_POS)
#define EN_DEBUG_PRIME_DET_VAL              (8UL << PDSS_RX_ORDER_SET_CTRL_SOP_RST_EN_POS)
#define EN_DEBUG_DBL_DET_VAL                (16UL << PDSS_RX_ORDER_SET_CTRL_SOP_RST_EN_POS)
#define EN_RX_CABLE_RESET_DET_VAL           (32UL << PDSS_RX_ORDER_SET_CTRL_SOP_RST_EN_POS)
#define EN_RX_HARD_RESET_DET_VAL            (64UL << PDSS_RX_ORDER_SET_CTRL_SOP_RST_EN_POS)

/* Mask for PD Interrupt Register */
#define PD_INTR_MASK                        (0x3FF7FBFFu)

#define RX_INTERRUPTS       (PDSS_INTR0_TX_GOODCRC_MSG_DONE | \
                             PDSS_INTR0_RX_STATE_IDLE       | \
                             PDSS_INTR0_RCV_RST             | \
                             PDSS_INTR0_RX_SRAM_HALF_END    | \
                             PDSS_INTR0_COLLISION_TYPE3)

/* PD Receiver Interrupt Mask */
#define RCV_INTR_MASK       (PDSS_INTR0_RX_STATE_IDLE                 | \
                             PDSS_INTR0_EOP_ERROR                     | \
                             PDSS_INTR0_RCV_GOOD_PACKET_COMPLETE      | \
                             PDSS_INTR0_RCV_BAD_PACKET_COMPLETE       | \
                             PDSS_INTR0_RCV_GOODCRC_MSG_COMPLETE      | \
                             PDSS_INTR0_RCV_EXPT_GOODCRC_MSG_COMPLETE | \
                             PDSS_INTR0_RX_SOP                        | \
                             PDSS_INTR0_RX_SRAM_HALF_END              | \
                             PDSS_INTR0_RX_OVER_RUN)

/* PD Transmitter Interrupts */
#define TX_INTERRUPTS       (PDSS_INTR0_RCV_GOODCRC_MSG_COMPLETE | \
                             PDSS_INTR0_CRC_RX_TIMER_EXP         | \
                             PDSS_INTR0_COLLISION_TYPE1          | \
                             PDSS_INTR0_TX_PACKET_DONE           | \
                             PDSS_INTR0_COLLISION_TYPE2)

/* PD Transmitter RESET Interrupts */
#define RST_TX_INTERRUPTS   (PDSS_INTR0_TX_HARD_RST_DONE | PDSS_INTR0_COLLISION_TYPE4)


/* Ordered sets for transmission. */
ROM_CONSTANT static const uint32_t sopTable[CY_PD_SOP_INVALID] =
{
    0x8E318u,      /**< SOP Default. */
    0x31B18u,      /**< SOP Prime. */
    0x360D8u,      /**< SOP Double Prime. */
    0x36738u,      /**< SOP Prime Debug. */
    0x89B38u,      /**< SOP Double Prime Debug. */
    0xE7393u,      /**< Hard Reset. */
    0xE0F8Cu       /**< Cable Reset. */
};

/*******************************************************************************
* Function Name: Cy_USBPD_Phy_Init
****************************************************************************//**
*
* Initializes the PD phy registers and registers a callback (provided by the PD
* protocol state machine of the PDSTACK Middleware) which will be called when
* interrupts associated with the PD transceiver are received.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \param phyCbk 
* The phy event handler callback.
*
* \return
* CY_USBPD_STAT_SUCCESS if operation is successful,
* CY_USBPD_STAT_BAD_PARAM if the context pointer or phyCbk is invalid.
*
*******************************************************************************/
PDL_ATTRIBUTES cy_en_usbpd_status_t Cy_USBPD_Phy_Init(cy_stc_usbpd_context_t *context, cy_cb_usbpd_phy_handle_events_t phyCbk)
{
    PPDSS_REGS_T pd = NULL;

    if((NULL == context) || (NULL == phyCbk))
    {
        return CY_USBPD_STAT_BAD_PARAM;
    }

    pd = context->base;
    context->pdPhyCbk = phyCbk;

#if CY_PD_REV3_ENABLE
    /* Configure RX_SOP_GOOD_CRC_EN_CTRL */
    pd->rx_sop_good_crc_en_ctrl = RX_SOP_GOOD_CRC_EN_CTRL_REV3_CFG;
    /* Configure Extended Header Info register */
    pd->header_info = HEADER_INFO_CFG;
#else
    /* Configure RX_SOP_GOOD_CRC_EN_CTRL */
    pd->rx_sop_good_crc_en_ctrl = RX_SOP_GOOD_CRC_EN_CTRL_CFG;
#endif /* CY_PD_REV3_ENABLE */

#if defined(CY_IP_MXUSBPD)
    /* Configure RX_CC reg */
    pd->rx_cc_0_cfg = RX_CC_CFG;

    /* Configure RX_ORDER_SET_CTRL */
    pd->rx_order_set_ctrl = RX_ORDER_SET_CTRL_CFG;

    /* Configure CRC_COUNTER reg */
    pd->crc_counter = CRC_COUNTER_CFG;

    /* Configure INTER_PACKET_COUNTER reg */
    pd->inter_packet_counter = INTER_PACKET_COUNTER_CFG;

    /* Disable all PD interrupts */
    pd->intr0_mask &= ~PD_INTR_MASK;

    /* Configure DEBUG_CC_2 reg to disable cc monitoring during idle gap before
     * transmitting goodcrc and set expected goodrc message header mask */
    pd->debug_cc_2 = PDSS_DEBUG_CC_2_DIS_CC_MON_AUTO_CRC | Cy_USBPD_MmioRegUpdateField (pd->debug_cc_2,
            EXPECTED_GOOD_CRC_HDR_MASK, PDSS_DEBUG_CC_2_EXPECTED_HEADER_MASK_MASK,
            (uint8_t)PDSS_DEBUG_CC_2_EXPECTED_HEADER_MASK_POS);

    /* Configure SOP_PRIME and SOP_DPRIME Auto Goodrc Header */
    pd->tx_goodcrc_msg_order_set = CY_PD_TX_SOP_PRIME_DPRIME_GD_CRC_HDR_DFLT;

#elif defined(CY_IP_M0S8USBPD)

    /* Enable Auto Good CRC for all messages except goodcrc */
    pd->rx_default_sop_goodcrc_ctrl_0 = AUTO_CTRL_MESSAGE_GOODCRC_MASK_CFG;
    pd->rx_default_sop_goodcrc_ctrl_1 = AUTO_DATA_MESSAGE_GOODCRC_MASK_CFG;

    pd->rx_dbl_prime_sop_goodcrc_ctrl_0 = AUTO_CTRL_MESSAGE_GOODCRC_MASK_CFG;
    pd->rx_dbl_prime_sop_goodcrc_ctrl_1 = AUTO_DATA_MESSAGE_GOODCRC_MASK_CFG;

    pd->rx_prime_sop_goodcrc_ctrl_0 = AUTO_CTRL_MESSAGE_GOODCRC_MASK_CFG;
    pd->rx_prime_sop_goodcrc_ctrl_1 = AUTO_DATA_MESSAGE_GOODCRC_MASK_CFG;

#if CY_PD_REV3_ENABLE
    /* Configure Extended Header Info register */
    pd->rx_default_sop_goodcrc_ctrl_2 = AUTO_EXTD_MESSAGE_GOODCRC_MASK_CFG;
    pd->rx_dbl_prime_sop_goodcrc_ctrl_2 = AUTO_EXTD_MESSAGE_GOODCRC_MASK_CFG;
    pd->rx_prime_sop_goodcrc_ctrl_2 = AUTO_EXTD_MESSAGE_GOODCRC_MASK_CFG;
#endif /* CY_PD_REV3_ENABLE */

    /* Configure RX_CC reg */
    pd->rx_cc = RX_CC_CFG;

    /* Configure RX_ORDER_SET_CTRL */
    pd->rx_order_set_ctrl = RX_ORDER_SET_CTRL_CFG;

    /* Configure CRC_COUNTER reg */
    pd->crc_counter = CRC_COUNTER_CFG;

    /* Configure INTER_PACKET_COUNTER reg */
    pd->inter_packet_counter = INTER_PACKET_COUNTER_CFG;

    /* Disable all PD interrupts */
    pd->intr0_mask &= ~PD_INTR_MASK;

    /*Configure DEBUG_CC_2 reg to disable cc monitoring during idle gap before
     * transmitting goodcrc and set expected goodrc message header mask*/
    pd->debug_cc_2 &= ~PDSS_DEBUG_CC_2_EXPECTED_HEADER_MASK_MASK;
    pd->debug_cc_2 |= (EXPECTED_GOOD_CRC_HDR_MASK << PDSS_DEBUG_CC_2_EXPECTED_HEADER_MASK_POS) |
        PDSS_DEBUG_CC_2_DIS_CC_MON_AUTO_CRC;

    /*Configure SOP_PRIME and SOP_DPRIME Auto Goodrc Header*/
    pd->tx_goodcrc_msg_order_set = CY_PD_TX_SOP_PRIME_DPRIME_GD_CRC_HDR_DFLT;

#endif

    return CY_USBPD_STAT_SUCCESS;
}


/*******************************************************************************
* Function Name: Cy_USBPD_Phy_RefreshRoles
****************************************************************************//**
*
* Configures the PD phy based on the current power role, data role and contract
* status of the specified port. This API does not enable the receiver.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \return
* None
*
*******************************************************************************/
PDL_ATTRIBUTES void Cy_USBPD_Phy_RefreshRoles(cy_stc_usbpd_context_t *context)
{
    PPDSS_REGS_T pd = context->base;
    cy_stc_pd_dpm_config_t* dpmConfig = context->dpmGetConfig();
    uint32_t temp;

#if CY_PD_REV3_ENABLE
    bool rev3 = false;

    if (dpmConfig->specRevSopLive >= CY_PD_REV3)
    {
        rev3 = true;
    }

    temp = pd->rx_order_set_ctrl;
    temp &= ~PDSS_RX_ORDER_SET_CTRL_SOP_RST_EN_MASK;
    temp |= (EN_DEFAULT_SOP_DET_VAL | EN_RX_HARD_RESET_DET_VAL);

    if (rev3)
    {
        /* Update goodcrc mask */
        pd->debug_cc_2 |= ((uint32_t)EXPECTED_GOOD_CRC_HDR_DIFF_MASK_REV3 << PDSS_DEBUG_CC_2_EXPECTED_HEADER_MASK_POS);

        /* Enable Extended RX */
        pd->header_info |= PDSS_HEADER_INFO_EN_RX_EXTENDED_DATA;
    }
    else
    {
        /* Update goodcrc mask */
        pd->debug_cc_2 &= ~((uint32_t)EXPECTED_GOOD_CRC_HDR_DIFF_MASK_REV3 << PDSS_DEBUG_CC_2_EXPECTED_HEADER_MASK_POS);

        /* Disable Extended RX/TX */
        pd->header_info &= ~(PDSS_HEADER_INFO_EN_RX_EXTENDED_DATA | PDSS_HEADER_INFO_EN_TX_EXTENDED_DATA);
    }

    /* Start off with cable communication disallowed. */
    temp &= ~(EN_PRIME_SOP_DET_VAL | EN_DBL_SOP_DET_VAL);

    /* If cable discovery is disabled, never allow SOP'/SOP'' communication. */
    if (dpmConfig->cblDsc != false)
    {
        if (dpmConfig->contractExist == false)
        {
            /*
             * While in implicit contract, only source can talk to cable (SOP' only allowed).
             * Also, only VConn Source is allowed when the spec revision is PD 3.0.
             */
            if (
                    (dpmConfig->curPortRole == CY_PD_PRT_ROLE_SOURCE) &&
                    ((!rev3) || (dpmConfig->vconnLogical != false))
               )
            {
                /* Enable SOP_PRIME only */
                temp |= EN_PRIME_SOP_DET_VAL;
            }
        }
        else
        {
            /*
             * Only VConn Source can talk to cable during a PD REV3 contract.
             * Only DFP can talk to cable during a PD 2.0 contract.
             */
            if (
                    ((rev3) && (dpmConfig->vconnLogical != false)) ||
                    ((!rev3) && (dpmConfig->curPortType == CY_PD_PRT_TYPE_DFP))
               )
            {
                /* Enable SOP_PRIME GoodCRC. */
                temp |= EN_PRIME_SOP_DET_VAL;

                /* If cable has been discovered, enabled SOP_DPRIME GoodCRC. */
                if (dpmConfig->emcaPresent)
                {
                    temp |= EN_DBL_SOP_DET_VAL;
                }
            }
        }
    }

    pd->rx_order_set_ctrl = temp;

    temp = pd->tx_ctrl;
    temp &= ~PDSS_TX_CTRL_GOODCRC_MSG_BITS_MASK;
    temp |= ((uint32_t)CY_PD_CTRL_MSG_GOOD_CRC | CY_PD_DR_PR_ROLE((uint32_t)(dpmConfig->curPortType), (uint32_t)(dpmConfig->curPortRole)));
    temp |= ((uint32_t)CY_PD_REV2 << CY_PD_REV_POS);
    pd->tx_ctrl = temp;

    /* Configure SOP_PRIME and SOP_DPRIME Auto Goodrc Header */
    temp = (uint32_t)CY_PD_CTRL_MSG_GOOD_CRC;
    temp |= ((uint32_t)CY_PD_REV2 << CY_PD_REV_POS);
    pd->tx_goodcrc_msg_order_set = (temp << 16)| temp;

#else /* !CY_PD_REV3_ENABLE */

    temp = pd->rx_order_set_ctrl;
    temp &= ~PDSS_RX_ORDER_SET_CTRL_SOP_RST_EN_MASK;
    temp |= (EN_DEFAULT_SOP_DET_VAL | EN_RX_HARD_RESET_DET_VAL);

    /* Start off with cable communication disallowed. */
    temp &= ~(EN_PRIME_SOP_DET_VAL | EN_DBL_SOP_DET_VAL);

    /* If cable discovery is disabled, never allow SOP'/SOP'' communication. */
    if (dpmConfig->cblDsc != false)
    {
        if (dpmConfig->contractExist == false)
        {
            /* While in implicit contract, only source can talk to cable (SOP' only allowed). */
            if (dpmConfig->curPortRole == CY_PD_PRT_ROLE_SOURCE)
            {
                /* Enable SOP_PRIME only */
                temp |= EN_PRIME_SOP_DET_VAL;
            }
        }
        else
        {
            /* Only DFP can talk to cable during a PD 2.0 contract. */
            if (dpmConfig->curPortType == CY_PD_PRT_TYPE_DFP)
            {
                /* Enable SOP_PRIME GoodCRC. */
                temp |= EN_PRIME_SOP_DET_VAL;

                /* If cable has been discovered, enabled SOP_DPRIME GoodCRC. */
                if (dpmConfig->emcaPresent)
                {
                    temp |= EN_DBL_SOP_DET_VAL;
                }
            }
        }
    }

    pd->rx_order_set_ctrl = temp;

    temp = pd->tx_ctrl;
    temp &= (uint32_t)(~PDSS_TX_CTRL_GOODCRC_MSG_BITS_MASK);
    temp |= (CY_PD_TX_SOP_GD_CRC_HDR_DFLT | (CY_PD_DR_PR_ROLE((uint32_t)(dpmConfig->curPortType), (uint32_t)(dpmConfig->curPortRole))));
    pd->tx_ctrl = temp;

#endif /* CY_PD_REV3_ENABLE */
}


/*******************************************************************************
* Function Name: Cy_USBPD_Phy_LoadMsg
****************************************************************************//**
*
* Loads the PD message in FIFO and configures the necessary registers in
* preparation to sending the message out. The actual message sending has to be
* triggered by calling Cy_USBPD_Phy_SendMsg().
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \param sop 
* SOP Type.
*
* \param retries
* Number of retries.
*
* \param dobjCount
* No of data objects(each 32 bit) in data.
*
* \param header
* PD Header in lower 16 bits and optional unchunked extended header in upper 16 bits.
*
* \param unchunked
* Unchunked message if true.
*
* \param buf
* Pointer to message. Message buffer is a DWORD array that holds the data
* associated with data and extended data messages.
*
* \return 
* Returns true if successful, false otherwise.
*
*******************************************************************************/
PDL_ATTRIBUTES bool Cy_USBPD_Phy_LoadMsg(cy_stc_usbpd_context_t *context, cy_en_pd_sop_t sop, uint8_t retries,
        uint8_t dobjCount, uint32_t header, bool unchunked, uint32_t* buf)
{
    PPDSS_REGS_T pd = NULL;
    uint16_t expHdr;

    /* Check for input parameters */
    if((NULL == context) || (NULL == buf))
    {
        return false;
    }

    pd = context->base;
    context->txDatPtr = buf;
    context->txDobjCount = dobjCount;
    context->txUnchunked = (uint8_t)unchunked;

    /* Make sure GoodCRC response to SOP'' messages is enabled where required. */
    if (sop == CY_PD_SOP_DPRIME)
    {
        pd->rx_order_set_ctrl |= EN_DBL_SOP_DET_VAL;
    }

    /* Configure SOP ordered set. */
    pd->tx_sop_order_set = sopTable[sop];

    /*
     * Configure the expected sop type and expected GoodCRC. Expected GoodCRC
     * mask was already set by Cy_USBPD_Phy_Init(). SOP type in hardware is sop + 1.
     */
    expHdr = (uint16_t)(header & (~EXPECTED_GOOD_CRC_CLEAR_MASK));
    expHdr |= (uint16_t)CY_PD_CTRL_MSG_GOOD_CRC;
    pd->rx_expect_goodcrc_msg = ((uint32_t)expHdr | (((uint32_t)sop + 1UL) << PDSS_RX_EXPECT_GOODCRC_MSG_EXPECTED_SOP_POS));

    /* Load the header in the Tx header register. */
    pd->tx_header = header;

    /* Save the number of requested retries. */
    context->retryCnt = (int8_t)retries;
    return true;
}


/*******************************************************************************
* Function Name: Cy_USBPD_Phy_Reset_RxTx_SM
****************************************************************************//**
*
* Reset the PD receive and transmit state machines.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \return
* None
*
*******************************************************************************/
PDL_ATTRIBUTES void Cy_USBPD_Phy_Reset_RxTx_SM(cy_stc_usbpd_context_t *context)
{
    PPDSS_REGS_T pd = context->base;

    /* Stop any ongoing transmission */
    pd->debug_ctrl |= (PDSS_DEBUG_CTRL_RESET_TX | PDSS_DEBUG_CTRL_RESET_RX);
    CALL_MAP(Cy_SysLib_DelayUs)(5);
    pd->debug_ctrl &= ~(PDSS_DEBUG_CTRL_RESET_TX | PDSS_DEBUG_CTRL_RESET_RX);
}


/*******************************************************************************
* Function Name: Cy_USBPD_Phy_DisRxTx
****************************************************************************//**
*
* Disables the PD receive and transmit PHY.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \return
* None
*
*******************************************************************************/
PDL_ATTRIBUTES void Cy_USBPD_Phy_DisRxTx(cy_stc_usbpd_context_t *context)
{
    PPDSS_REGS_T pd = context->base;

    CALL_MAP(Cy_USBPD_Phy_DisRx)(context, 0u);
    CALL_MAP(Cy_USBPD_Phy_Reset_RxTx_SM) (context);

    pd->intr0_mask &= ~(TX_INTERRUPTS | RST_TX_INTERRUPTS |
            PDSS_INTR0_TX_RETRY_ENABLE_CLRD |
            PDSS_INTR0_CC_NO_VALID_DATA_DETECTED|
            PDSS_INTR0_TX_SRAM_HALF_END);
    pd->intr0 = (TX_INTERRUPTS | RST_TX_INTERRUPTS |
            PDSS_INTR0_TX_RETRY_ENABLE_CLRD |
            PDSS_INTR0_CC_NO_VALID_DATA_DETECTED|
            PDSS_INTR0_TX_SRAM_HALF_END);    
}


PDL_ATTRIBUTES static bool Cy_USBPD_Phy_LoadDataInMem(cy_stc_usbpd_context_t *context, bool start)
{
    PPDSS_REGS_T pd = context->base;
    uint8_t i;
    uint8_t txPtr = (uint8_t)(pd->sram_ptr & PDSS_SRAM_PTR_TX_FUNC_RD_PTR_MASK);
    uint8_t index = 0;
    uint8_t size = 0;

    if(context->txDobjCount == 0u)
    {
        return false;
    }

    if(start == true)
    {
        size = PDSS_MAX_TX_MEM_SIZE;
    }
    else
    {
        size = PDSS_MAX_TX_MEM_HALF_SIZE;
        if(txPtr < PDSS_MAX_TX_MEM_HALF_SIZE)
        {
            index = PDSS_MAX_TX_MEM_HALF_SIZE;
        }
    }

    /* Copy the data into the Tx memory. */
    for (i = index; i < (index+ size); i++)
    {
        pd->tx_mem_data[i] = context->txDatPtr[context->txObjSent];
        context->txObjSent++;
        if(context->txObjSent >= context->txDobjCount)
        {
            return false;
        }
    }

    return true;
}

#if CY_PD_REV3_ENABLE
PDL_ATTRIBUTES static void pd_phy_read_data_from_mem(cy_stc_usbpd_context_t *context)
{
    PPDSS_REGS_T pd = context->base;
    uint8_t i;
    uint8_t index = context->rxReadLocation;
    uint8_t size = PDSS_MAX_RX_MEM_HALF_SIZE;

    /* Copy the data from rx memory. */
    for (i = index; i < (index + size); i++)
    {
        if(context->rxUnchunkCount >= context->rxUnchunkLen)
        {
            return;
        }
        context->rxPkt.dat[context->rxUnchunkCount].val = pd->rx_mem_data[i];
        context->rxUnchunkCount++;
    }

    /* Flip to the other half of the SRAM for the next read. */
    context->rxReadLocation = (context->rxReadLocation == 0U) ?
        PDSS_MAX_RX_MEM_HALF_SIZE: 0U;
}
#endif /* CY_PD_REV3_ENABLE */


/*******************************************************************************
* Function Name: Cy_USBPD_Phy_SendMsg
****************************************************************************//**
*
* Starts the transmission of a PD message already loaded in FIFO.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \return
* Returns true if successful, false otherwise.
*
*******************************************************************************/
PDL_ATTRIBUTES bool Cy_USBPD_Phy_SendMsg(cy_stc_usbpd_context_t *context)
{
    PPDSS_REGS_T pd = NULL;
    uint32_t regVal;

    if(NULL == context)
    {
        return false;
    }

    pd = context->base;

    pd->intr0_mask &= ~PDSS_INTR0_CC_NO_VALID_DATA_DETECTED;

    /* Clear Tx interrupts. */
    pd->intr0 = (TX_INTERRUPTS | PDSS_INTR0_RCV_EXPT_GOODCRC_MSG_COMPLETE |
        PDSS_INTR0_TX_RETRY_ENABLE_CLRD | PDSS_INTR0_CC_NO_VALID_DATA_DETECTED |
        PDSS_INTR0_TX_SRAM_HALF_END);

    if (context->retryCnt < 0)
    {
        /* Create this interrupt to stop transmission. */
        pd->intr0_set |= PDSS_INTR0_CRC_RX_TIMER_EXP;
        return true;
    }

    if ((pd->status & (PDSS_STATUS_RX_BUSY | PDSS_STATUS_SENDING_GOODCRC_MSG)) != 0u)
    {
        context->retryCnt--;

        pd->intr0_mask |= PDSS_INTR0_CC_NO_VALID_DATA_DETECTED;

        /*
         * Notify the protocol layer so that it can start a timer so as to
         * avoid an infinite wait on the channel going idle.
         */
        context->pdPhyCbk((void *)(context->pdStackContext), CY_USBPD_PHY_EVT_TX_MSG_COLLISION);

        return true;
    }

    context->txObjSent = 0;
    if(Cy_USBPD_Phy_LoadDataInMem(context, true) == true)
    {
        /* Enable TX SRAM HALF END interrupt */
        pd->intr0_mask |= PDSS_INTR0_TX_SRAM_HALF_END;
    }
    /* Enable Tx interrupts. */
    pd->intr0_mask |= TX_INTERRUPTS;

    /* Checks if unchunked TX need to be enabled */
    if(context->txUnchunked != 0U)
    {
        pd->header_info |= PDSS_HEADER_INFO_EN_TX_EXTENDED_DATA;
    }
    else
    {
        pd->header_info &= ~PDSS_HEADER_INFO_EN_TX_EXTENDED_DATA;
    }

    regVal = pd->tx_ctrl;
    if (context->retryCnt != 0)
    {
        regVal |= PDSS_TX_CTRL_TX_RETRY_ENABLE;
    }
    else
    {
        /* No retries. */
        regVal &= ~PDSS_TX_CTRL_TX_RETRY_ENABLE;
    }
    regVal |= PDSS_TX_CTRL_TX_GO;

    context->txDone = 0;
    context->retryCnt--;

    /* Begin transmission. */
    pd->tx_ctrl = regVal;

    return true;
}


/*******************************************************************************
* Function Name: Cy_USBPD_Phy_EnRx
****************************************************************************//**
*
* Enables the Phy Receiver.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \return
* None
*
*******************************************************************************/
PDL_ATTRIBUTES void Cy_USBPD_Phy_EnRx(cy_stc_usbpd_context_t *context)
{
    PPDSS_REGS_T pd = context->base;
#if CY_PD_REV3_ENABLE
    cy_stc_pd_dpm_config_t* dpmConfig = context->dpmGetConfig();
#endif /* CY_PD_REV3_ENABLE */

    context->rxUnchunked = false;

    /* Clear and enable RX interrupts. */
    pd->intr0 = (RX_INTERRUPTS |RCV_INTR_MASK);

#if CY_PD_REV3_ENABLE
    pd->intr2 = PDSS_INTR2_EXTENDED_MSG_DET | PDSS_INTR2_CHUNK_DET | PDSS_INTR2_RX_SRAM_OVER_FLOW;
    if(dpmConfig->specRevSopLive >= CY_PD_REV3)
    {
        pd->intr2_mask |= PDSS_INTR2_EXTENDED_MSG_DET;
    }
#endif /* CY_PD_REV3_ENABLE */

    pd->intr0_mask |= RX_INTERRUPTS;

#if CY_PD_CRC_ERR_HANDLING_ENABLE
    pd->intr0_mask |= PDSS_INTR0_RCV_BAD_PACKET_COMPLETE;
#endif /* CY_PD_CRC_ERR_HANDLING_ENABLE */
}


/*******************************************************************************
* Function Name: Cy_USBPD_Phy_DisRx
****************************************************************************//**
*
* Disables the Phy Receiver.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
* 
* \param hardResetEn
* Receiver completely disabled if 0, Hard Reset can be received if set to 1.
*
*******************************************************************************/
PDL_ATTRIBUTES void Cy_USBPD_Phy_DisRx (cy_stc_usbpd_context_t *context, uint8_t hardResetEn)
{
    uint32_t temp;
    PPDSS_REGS_T pd = context->base;

#if CY_PD_REV3_ENABLE

    pd->intr2_mask &= ~(PDSS_INTR2_EXTENDED_MSG_DET | PDSS_INTR2_CHUNK_DET);
    pd->intr2 = (PDSS_INTR2_EXTENDED_MSG_DET | PDSS_INTR2_CHUNK_DET |
            PDSS_INTR2_RX_SRAM_OVER_FLOW);

#endif /* CY_PD_REV3_ENABLE */

    if (hardResetEn == 0U)
    {
        /* Disable Rx.*/
        pd->rx_order_set_ctrl &= ~PDSS_RX_ORDER_SET_CTRL_SOP_RST_EN_MASK;

        /* Disable and clear all Rx interrupts.*/
        pd->intr0_mask &= ~RX_INTERRUPTS;
    }
    else
    {
        /* Enable only Hard Reset reception. */
        temp = pd->rx_order_set_ctrl;
        temp &= ~PDSS_RX_ORDER_SET_CTRL_SOP_RST_EN_MASK;
        temp |= EN_RX_HARD_RESET_DET_VAL;
        pd->rx_order_set_ctrl = temp;

        /* Enable only the Hard Reset received interrupt. */
        temp = pd->intr0_mask;
        temp &= ~RX_INTERRUPTS;
        temp |=  PDSS_INTR0_RCV_RST;
        pd->intr0_mask = temp;
    }

    pd->intr0 = RX_INTERRUPTS;
}


/*******************************************************************************
* Function Name: Cy_USBPD_Phy_EnUnchunkedTx
****************************************************************************//**
*
* Enables the Phy to transmit Unchunked messages.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \return
* None
*
*******************************************************************************/
void Cy_USBPD_Phy_EnUnchunkedTx (cy_stc_usbpd_context_t *context)
{
    PPDSS_REGS_T pd = context->base;
    pd->header_info |= PDSS_HEADER_INFO_EN_TX_EXTENDED_DATA;
}


/*******************************************************************************
* Function Name: Cy_USBPD_Phy_DisUnchunkedTx
****************************************************************************//**
*
* Disables the Phy to transmit Unchunked messages.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \return
* None
*
*******************************************************************************/
void Cy_USBPD_Phy_DisUnchunkedTx (cy_stc_usbpd_context_t *context)
{
    PPDSS_REGS_T pd = context->base;
    pd->header_info &= ~PDSS_HEADER_INFO_EN_TX_EXTENDED_DATA;
}


/*******************************************************************************
* Function Name: Cy_USBPD_Phy_SendBIST_Cm2
****************************************************************************//**
*
* Starts transmission of BIST Carrier Mode 2. Once this API
* returns successfully, the PHY continues to send the CM2 pattern until
* Cy_USBPD_Phy_AbortBIST_Cm2() is called.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \return
* CY_USBPD_STAT_SUCCESS if operation is successful,
* CY_USBPD_STAT_BAD_PARAM if the context pointer is invalid.
*
*******************************************************************************/
PDL_ATTRIBUTES cy_en_usbpd_status_t Cy_USBPD_Phy_SendBIST_Cm2(cy_stc_usbpd_context_t *context)
{
    PPDSS_REGS_T pd = NULL;

    if(NULL == context)
    {
        return CY_USBPD_STAT_BAD_PARAM;
    }

    pd = context->base;

    /* Enable Tx regulator. */
    pd->tx_ctrl |= PDSS_TX_CTRL_TX_REG_EN;

    /* Delay to let the Tx regulator turn on. */
    CALL_MAP(Cy_SysLib_DelayUs)(50);

    /* Start BIST CM2. */
    pd->tx_ctrl |= PDSS_TX_CTRL_EN_TX_BIST_CM2;

    return CY_USBPD_STAT_SUCCESS;
}


/*******************************************************************************
* Function Name: Cy_USBPD_Phy_AbortBIST_Cm2
****************************************************************************//**
*
* Stops transmission of BIST Carrier Mode 2 pattern.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \return
* CY_USBPD_STAT_SUCCESS if operation is successful,
* CY_USBPD_STAT_BAD_PARAM if the context pointer is invalid.
*
*******************************************************************************/
PDL_ATTRIBUTES cy_en_usbpd_status_t Cy_USBPD_Phy_AbortBIST_Cm2(cy_stc_usbpd_context_t *context)
{
    PPDSS_REGS_T pd = NULL;

    if(NULL == context)
    {
        return CY_USBPD_STAT_BAD_PARAM;
    }

    pd = context->base;

    /* Stop BIST CM2. */
    pd->tx_ctrl &= ~PDSS_TX_CTRL_EN_TX_BIST_CM2;

    /* Disable Tx regulator. */
    pd->tx_ctrl &= ~PDSS_TX_CTRL_TX_REG_EN;

    return CY_USBPD_STAT_SUCCESS;
}


/*******************************************************************************
* Function Name: Cy_USBPD_Phy_AbortTxMsg
****************************************************************************//**
*
* Stops transmission of any ongoing PD message.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \return
* CY_USBPD_STAT_SUCCESS if operation is successful,
* CY_USBPD_STAT_BAD_PARAM if the context pointer is invalid.
*
*******************************************************************************/
PDL_ATTRIBUTES cy_en_usbpd_status_t Cy_USBPD_Phy_AbortTxMsg(cy_stc_usbpd_context_t *context)
{
    PPDSS_REGS_T pd = NULL;

    if(NULL == context)
    {
        return CY_USBPD_STAT_BAD_PARAM;
    }

    pd = context->base;

    context->txDone = 0;

    pd->intr0_mask &= ~(TX_INTERRUPTS | PDSS_INTR0_TX_RETRY_ENABLE_CLRD |
                        PDSS_INTR0_CC_NO_VALID_DATA_DETECTED | PDSS_INTR0_TX_SRAM_HALF_END);
    pd->intr0 = (TX_INTERRUPTS | PDSS_INTR0_TX_RETRY_ENABLE_CLRD |
                 PDSS_INTR0_CC_NO_VALID_DATA_DETECTED |PDSS_INTR0_TX_SRAM_HALF_END);

    return CY_USBPD_STAT_SUCCESS;
}


/*******************************************************************************
* Function Name: Cy_USBPD_Phy_SendReset
****************************************************************************//**
*
* Starts transmission of a cable reset or a hard reset
* as requested.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \param sop
* SOP Type.
*
* \return
* CY_USBPD_STAT_SUCCESS if operation is successful,
* CY_USBPD_STAT_BAD_PARAM if the context pointer is invalid.
* CY_USBPD_STAT_BUSY if the USBPD operation is still in progress
*
*******************************************************************************/
PDL_ATTRIBUTES cy_en_usbpd_status_t Cy_USBPD_Phy_SendReset(cy_stc_usbpd_context_t *context, cy_en_pd_sop_t sop)
{
    PPDSS_REGS_T pd = NULL;
    uint8_t loopCount = 10;

    if(NULL == context)
    {
        return CY_USBPD_STAT_BAD_PARAM;
    }

    pd = context->base;

    /* If this is a hard reset, we should reset the TX and RX state machine for this port. */
    if (sop == CY_PD_HARD_RESET)
    {
        CALL_MAP(Cy_USBPD_Phy_Reset_RxTx_SM)(context);
    }

    /* Send a Hard Reset or Cable Reset. */
    pd->intr0 = RST_TX_INTERRUPTS;
    pd->intr0_mask |= RST_TX_INTERRUPTS;

    pd->tx_hard_cable_order_set = sopTable[sop];

    /* Wait while there is valid data on the CC line. */
    if (sop == CY_PD_HARD_RESET)
    {
        /* Wait while there is valid data on the CC line. */
        while ((loopCount > 0u) &&
                ((pd->status & (
                                PDSS_STATUS_CC_DATA_VALID |
                                PDSS_STATUS_RX_BUSY |
                                PDSS_STATUS_TX_BUSY |
                                PDSS_STATUS_SENDING_GOODCRC_MSG
                               )
                 ) != 0u)
              )
        {
            loopCount--;
            CALL_MAP(Cy_SysLib_DelayUs) (10);
        }

        if (
                (pd->status & (
                               PDSS_STATUS_CC_DATA_VALID |
                               PDSS_STATUS_RX_BUSY |
                               PDSS_STATUS_TX_BUSY |
                               PDSS_STATUS_SENDING_GOODCRC_MSG
                              )
                ) != 0u)
        {
            /* Return busy so that the reset gets attempted again at a later time. */
            return CY_USBPD_STAT_BUSY;
        }
    }

    pd->tx_ctrl |= PDSS_TX_CTRL_TX_SEND_RST;
    return CY_USBPD_STAT_SUCCESS;
}


/*******************************************************************************
* Function Name: Cy_USBPD_Phy_GetRxPacket
****************************************************************************//**
*
* Returns the received packet. Since the interrupt handlers
* uses the same buffer to receive all incoming messages, the caller of this
* function needs to copy the data out before a new message is received.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \return
* \ref cy_stc_pd_packet_extd_t received PD message.
*
*******************************************************************************/
cy_stc_pd_packet_extd_t *Cy_USBPD_Phy_GetRxPacket(cy_stc_usbpd_context_t *context)
{
    return &(context->rxPkt);
}


/*******************************************************************************
* Function Name: Cy_USBPD_Phy_IsBusy
****************************************************************************//**
*
* Checks if the PD Phy is busy for the specified port based on passed context.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \return
* Returns true if busy, otherwise false.
*
*******************************************************************************/
PDL_ATTRIBUTES bool Cy_USBPD_Phy_IsBusy(cy_stc_usbpd_context_t *context)
{
    PPDSS_REGS_T pd = context->base;

    if (((pd->status & (PDSS_STATUS_CC_DATA_VALID |
                        PDSS_STATUS_RX_BUSY |
                        PDSS_STATUS_TX_BUSY |
                        PDSS_STATUS_SENDING_GOODCRC_MSG
                       )) != 0U ) ||
        ((pd->intr0 & PDSS_INTR0_RCV_RST) != 0U))
    {
        return true;
    }

    return false;
}


/*******************************************************************************
* Function Name: Cy_USBPD_Intr0RxTxHandler
****************************************************************************//**
*
* Interrupt Handler function for USBPD Transceiver interrupts.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \return
* None
*
*******************************************************************************/
PDL_ATTRIBUTES void Cy_USBPD_Intr0RxTxHandler(cy_stc_usbpd_context_t *context)
{
    PPDSS_REGS_T pd = context->base;
    uint32_t rval, intr_msk = 0;
    uint32_t i = 0;
    bool phy_busy_flag;

    CY_UNUSED_PARAMETER(i);

#if CY_PD_REV3_ENABLE
    cy_stc_pd_dpm_config_t* dpmConfig = context->dpmGetConfig();
    cy_pd_pd_hdr_t msgHdr;
#endif /* CY_PD_REV3_ENABLE */

    intr_msk = pd->intr0_masked;
    /*
     * Receive interrupt handling.
     */
    if ((intr_msk & PDSS_INTR0_RCV_RST) != 0u)
    {
        context->txDone = 0;
        context->pdPhyCbk((void *)(context->pdStackContext), CY_USBPD_PHY_EVT_RX_RST);
        pd->intr0 = (PDSS_INTR0_RCV_RST | PDSS_INTR0_EOP_ERROR);
    }

    if ((intr_msk & PDSS_INTR0_TX_PACKET_DONE) != 0u)
    {
        pd->intr0 = PDSS_INTR0_TX_PACKET_DONE;
        context->txDone = 1;
    }

#if CY_PD_REV3_ENABLE
        if ((pd->intr2_masked & PDSS_INTR2_EXTENDED_MSG_DET) != 0u)
        {
            if ((pd->intr2 & PDSS_INTR2_CHUNK_DET) != 0u)
            {
                context->rxUnchunked = false;
            }
            else
            {
                context->rxUnchunked = true;

                /* Store total byte count and initialize bytes received. */
                msgHdr.val = pd->rx_header;
                context->rxUnchunkLen = (uint8_t)((msgHdr.hdr.dataSize + 3U) >> 2U);
                if(context->rxUnchunkLen > CY_PD_MAX_EXTD_PKT_WORDS)
                {
                    context->rxUnchunkLen = CY_PD_MAX_EXTD_PKT_WORDS;
                }

                context->rxUnchunkCount = 0;
                context->rxReadLocation = 0;
            }

            /* Extended message detected */
            /* Clear interrupt */
            pd->intr2 = PDSS_INTR2_CHUNK_DET | PDSS_INTR2_EXTENDED_MSG_DET;
        }
#endif /* CY_PD_REV3_ENABLE */
        if ((intr_msk & PDSS_INTR0_RX_SRAM_HALF_END) != 0u)
        {
#if CY_PD_REV3_ENABLE
            /* Store data in extended buf and update count*/
            pd_phy_read_data_from_mem(context);
#endif /* CY_PD_REV3_ENABLE */
            pd->intr0 = PDSS_INTR0_RX_SRAM_HALF_END;
        }

        if ((intr_msk & PDSS_INTR0_RX_STATE_IDLE) != 0u)
        {
            rval =  pd->intr0;

            if ((rval & PDSS_INTR0_RCV_GOODCRC_MSG_COMPLETE) != 0u)
            {
                if ((rval & (PDSS_INTR0_RCV_EXPT_GOODCRC_MSG_COMPLETE | PDSS_INTR0_EOP_ERROR)) ==
                        PDSS_INTR0_RCV_EXPT_GOODCRC_MSG_COMPLETE)
                {
                    if (context->txDone != 0U)
                    {
                        context->txDone = 0U;

                        /* Stop retries due to CRC countdown expiry. */
                        pd->rx_expect_goodcrc_msg |= PDSS_RX_EXPECT_GOODCRC_MSG_DISABLE_RX_CRC_TIMER;

                        pd->intr0_mask &= ~TX_INTERRUPTS;
                        pd->intr0 = TX_INTERRUPTS;

                        /* Successful transmission notification. */
                        context->pdPhyCbk((void *)(context->pdStackContext), CY_USBPD_PHY_EVT_TX_MSG_SUCCESS);
                    }
                }
            }

            if ((rval & PDSS_INTR0_RCV_GOOD_PACKET_COMPLETE) != 0u)
            {
                if ((rval & PDSS_INTR0_EOP_ERROR) == 0u)
                {
                    context->txDone = 0;

                    /* Disable and clear PDSS_INTR0_CC_NO_VALID_DATA_DETECTED. */
                    pd->intr0_mask &= ~PDSS_INTR0_CC_NO_VALID_DATA_DETECTED;
                    pd->intr0 = PDSS_INTR0_CC_NO_VALID_DATA_DETECTED;

                    /*
                     * Copy the received packet and analyze it. If the packet
                     * is valid with good msg id and if a Tx message is active,
                     * stop the Tx message and send a tx discard response to the
                     * upper layer. Also do not create a packet received event
                     * just now.
                     */
                    context->rxPkt.sop = (cy_en_pd_sop_t)((uint8_t)(((pd->status & PDSS_STATUS_SOP_TYPE_DETECTED_MASK) >>
                                PDSS_STATUS_SOP_TYPE_DETECTED_POS) - 1U));

                    /* Copy out the header from the PD hardware. */
                    context->rxPkt.hdr.val = pd->rx_header;

#if CY_PD_REV3_ENABLE
                    if (dpmConfig->specRevSopLive <= CY_PD_REV2)
                    {
                        /* Ignore reserved bits */
                        context->rxPkt.hdr.val &= ~(PD_MSG_HDR_REV2_IGNORE_MASK);
                    }
#else
                    context->rxPkt.hdr.val &= ~((uint32_t)PD_MSG_HDR_REV2_IGNORE_MASK);
#endif /* CY_PD_REV3_ENABLE */

                    /* Copy the data from the hardware buffer to the software buffer. */
                    context->rxPkt.len = (uint8_t)(context->rxPkt.hdr.hdr.len);
                    context->rxPkt.msg = (uint8_t)(context->rxPkt.hdr.hdr.msgType);
                    context->rxPkt.dataRole = (cy_en_pd_port_role_t)(context->rxPkt.hdr.hdr.dataRole);

#if CY_PD_REV3_ENABLE
                    if(context->rxUnchunked == false)
                    {
                        for (i = 0; i < context->rxPkt.len; i++)
                        {
                            context->rxPkt.dat[i].val = pd->rx_mem_data[i];
                        }
                    }
                    else
                    {
                        pd_phy_read_data_from_mem(context);
                    }
#else
                    for (i = 0; i < context->rxPkt.len; i++)
                    {
                        context->rxPkt.dat[i].val = pd->rx_mem_data[i];
                    }
#endif /* CY_PD_REV3_ENABLE */

                    context->pdPhyCbk((void *)(context->pdStackContext), CY_USBPD_PHY_EVT_RX_MSG);
                }
            }

            pd->intr0 = RCV_INTR_MASK;

#if CY_PD_REV3_ENABLE
            context->rxUnchunked = false;
            pd->intr2 = PDSS_INTR2_EXTENDED_MSG_DET | PDSS_INTR2_CHUNK_DET | PDSS_INTR2_RX_SRAM_OVER_FLOW;
#endif /* CY_PD_REV3_ENABLE */
        }

        if ((intr_msk & PDSS_INTR0_TX_GOODCRC_MSG_DONE) != 0u)
        {
            /* Create a packet received event. */
            context->pdPhyCbk((void *)(context->pdStackContext), CY_USBPD_PHY_EVT_RX_MSG_CMPLT);

            /* Clear the interrupt. */
            pd->intr0 = PDSS_INTR0_TX_GOODCRC_MSG_DONE;
        }

        if ((intr_msk & PDSS_INTR0_COLLISION_TYPE3) != 0u)
        {
            /* Create a packet received event. */
            context->pdPhyCbk((void *)(context->pdStackContext), CY_USBPD_PHY_EVT_RX_MSG_CMPLT);
            pd->intr0 = PDSS_INTR0_COLLISION_TYPE3;
        }

        if ((intr_msk & PDSS_INTR0_CC_NO_VALID_DATA_DETECTED) != 0u)
        {
            /* Disable the interrupt. */
            pd->intr0_mask &= ~PDSS_INTR0_CC_NO_VALID_DATA_DETECTED;
            pd->intr0 = PDSS_INTR0_CC_NO_VALID_DATA_DETECTED;

            /* Notify the protocol layer to stop the phy busy max limit timer. */
            context->pdPhyCbk((void *)(context->pdStackContext), CY_USBPD_PHY_EVT_TX_MSG_PHY_IDLE);
        }
#if CY_PD_CRC_ERR_HANDLING_ENABLE
        if ((intr_msk & PDSS_INTR0_RCV_BAD_PACKET_COMPLETE) != 0u)
        {
            /* Create a bad packet received event. */
            context->pdPhyCbk((void *)(context->pdStackContext), CY_USBPD_PHY_EVT_CRC_ERROR);
            /* Clear the interrupt. */
            pd->intr0 = PDSS_INTR0_RCV_BAD_PACKET_COMPLETE;
        }
#endif /* CY_PD_CRC_ERR_HANDLING_ENABLE */

        /*
         * Tx interrupt handling.
         */

        if ((intr_msk & PDSS_INTR0_TX_SRAM_HALF_END) != 0u)
        {
#if CY_PD_REV3_ENABLE
            if (Cy_USBPD_Phy_LoadDataInMem(context, false) == false)
            {
                pd->intr0_mask &= ~PDSS_INTR0_TX_SRAM_HALF_END;
            }
#endif /* CY_PD_REV3_ENABLE */

            pd->intr0 = PDSS_INTR0_TX_SRAM_HALF_END;
        }

        if ((intr_msk & PDSS_INTR0_CRC_RX_TIMER_EXP) != 0u)
        {
            context->txDone = 0;

            phy_busy_flag = CALL_MAP(Cy_USBPD_Phy_IsBusy)(context);
            if ((context->retryCnt < 0) ||
                    ((phy_busy_flag == false) && ((pd->tx_ctrl & PDSS_TX_CTRL_TX_RETRY_ENABLE) == 0u)))

            {
                /* Transmission failed. */
                pd->intr0_mask &= ~TX_INTERRUPTS;
                context->pdPhyCbk((void *)(context->pdStackContext), CY_USBPD_PHY_EVT_TX_MSG_FAILED);
            }
            else
            {
                if (context->retryCnt != 0)
                {
                    /* Clear and enable the TX retry enable cleared interrupt if required */
                    pd->intr0 = PDSS_INTR0_TX_RETRY_ENABLE_CLRD;
                    /* Delay to remove any race */
                    CALL_MAP(Cy_SysLib_DelayUs)(5);

                    if ((pd->tx_ctrl & PDSS_TX_CTRL_TX_RETRY_ENABLE) != 0U)
                    {
                        pd->intr0_mask |= PDSS_INTR0_TX_RETRY_ENABLE_CLRD;
                    }
                    else
                    {
                        /* Delay so that IP works otherwise if clear and set is too fast
                         * retry can fail */
                        CALL_MAP(Cy_SysLib_DelayUs)(5);
                        pd->tx_ctrl |= PDSS_TX_CTRL_TX_RETRY_ENABLE;
                    }
                }
                context->retryCnt--;
            }
            pd->intr0 = PDSS_INTR0_CRC_RX_TIMER_EXP;
        }

        if ((intr_msk & PDSS_INTR0_TX_RETRY_ENABLE_CLRD) != 0u)
        {
            if (CALL_MAP(Cy_USBPD_Phy_IsBusy)(context) == false)
            {
                /*
                 * In cases where there is a delayed response to PD CRC timer expiry interrupt, force the
                 * firmware to move to TX message fail state (PD_PHY_EVT_TX_MSG_FAILED) to restart PD state machine.
                 */
                context->retryCnt = -1;
                pd->intr0_set |= PDSS_INTR0_CRC_RX_TIMER_EXP;

            }
            else
            {
                CALL_MAP(Cy_SysLib_DelayUs)(5);
                /* Enable retry. */
                pd->tx_ctrl |= PDSS_TX_CTRL_TX_RETRY_ENABLE;

                /* Disable interrupts. */
                pd->intr0_mask &= ~PDSS_INTR0_TX_RETRY_ENABLE_CLRD;
                pd->intr0 = PDSS_INTR0_TX_RETRY_ENABLE_CLRD;
            }
        }

        if ((intr_msk& (PDSS_INTR0_COLLISION_TYPE1 | PDSS_INTR0_COLLISION_TYPE2)) != 0u)
        {
            /* Clear interrupts and enable the channel idle interrupt. */
            pd->intr0 = (PDSS_INTR0_COLLISION_TYPE1 | PDSS_INTR0_COLLISION_TYPE2 |
                         PDSS_INTR0_CC_NO_VALID_DATA_DETECTED);
            pd->intr0_mask |= PDSS_INTR0_CC_NO_VALID_DATA_DETECTED;

            CALL_MAP(Cy_SysLib_DelayUs) (10);

            /*
             * If the interrupt handler is delayed, the bus may already be idle.
             * In this case, we will not get any additional interrupt. Check for
             * bus idle condition and then trigger force trigger the interrupt
             * if required. This can happen if you get a delayed GOOD_CRC message
             * causing the RX_GOODCRC interrupt and collision interrupt to fire
             * together. Before handling these, the bus may have turned idle.
             * This will cause us to not retry the failed message.
             */
            if ((pd->status & (
                                PDSS_STATUS_CC_DATA_VALID |
                                PDSS_STATUS_RX_BUSY |
                                PDSS_STATUS_TX_BUSY |
                                PDSS_STATUS_SENDING_GOODCRC_MSG
                               )
                 ) == 0u)
            {
                pd->intr0_set = PDSS_INTR0_CC_NO_VALID_DATA_DETECTED;
            }


            /* The DUT sends a message, which triggers the PHY to start a GOOD_CRC
             * timer for 1 ms. However, instead of sending a GOOD_CRC message, the
             * port partner sends a different message aprx. ~470us after the DUT has
             * sent the message. As a result, both RX packet received and TX retry
             * events are triggered simultaneously, leading to a collision. In this
             * scenario, the PHY's TX state machine is stuck in the SENDING_GOOD_CRC
             * state and fails to send the GOOD_CRC message. Resetting the TX state
             * machine to resolve this issue.
             */
            if ((intr_msk & PDSS_INTR0_COLLISION_TYPE2) != 0u)
            {
                pd->debug_ctrl |= (PDSS_DEBUG_CTRL_RESET_TX);
                CALL_MAP(Cy_SysLib_DelayUs)(5);
                pd->debug_ctrl &= ~(PDSS_DEBUG_CTRL_RESET_TX);
            }

            /*
             * Notify the protocol layer so that it can start a timer so as to
             * avoid an infinite wait on the channel going idle.
             */
            context->pdPhyCbk((void *)(context->pdStackContext), CY_USBPD_PHY_EVT_TX_MSG_COLLISION);
        }

        /*
         * Reset interrupt handling.
         */
        if ((intr_msk & PDSS_INTR0_TX_HARD_RST_DONE) != 0u)
        {
            context->txDone = 0;
            context->pdPhyCbk((void *)(context->pdStackContext), CY_USBPD_PHY_EVT_TX_RST_SUCCESS);
            pd->intr0_mask &= ~RST_TX_INTERRUPTS;
            pd->intr0 = RST_TX_INTERRUPTS;
        }

        if ((intr_msk & PDSS_INTR0_COLLISION_TYPE4) != 0u)
        {
            context->txDone = 0;
            pd->intr0_mask &= ~RST_TX_INTERRUPTS;
            pd->intr0 = RST_TX_INTERRUPTS;
            context->pdPhyCbk((void *)(context->pdStackContext), CY_USBPD_PHY_EVT_TX_RST_COLLISION);
        }
}


/*******************************************************************************
* Function Name: Cy_USBPD_Intr0Handler
****************************************************************************//**
*
* Interrupt Handler function for USBPD Transceiver and HPD interrupts.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \return
* None
*
*******************************************************************************/
void Cy_USBPD_Intr0Handler(cy_stc_usbpd_context_t *context)
{
    PPDSS_REGS_T pd = context->base;
    uint32_t i = 0;

#if VBTR_MULTI_SLOPE_ENABLE
    pwr_params_t *pwr_cfg = pd_get_ptr_pwr_tbl(context->port);
    uint32_t hfclk_mhz = (Cy_SysClk_ClkHfGetFrequency() / 1000000);
#endif /* VBTR_MULTI_SLOPE_ENABLE */

#if (!(CY_PD_SOURCE_ONLY))
#if (CY_PD_REV3_ENABLE && (CY_PD_FRS_RX_ENABLE || CY_PD_FRS_TX_ENABLE))
    cy_stc_pd_dpm_config_t* dpmConfig = context->dpmGetConfig();
#endif /* (CY_PD_REV3_ENABLE && (CY_PD_FRS_RX_ENABLE || CY_PD_FRS_TX_ENABLE)) */
#endif /* (!(CY_PD_SOURCE_ONLY)) */
    CY_UNUSED_PARAMETER(i);

    if (pd->intr0_masked != 0u)
    {
        CALL_MAP(Cy_USBPD_Intr0RxTxHandler)(context);
    }
    if (pd->intr2_masked != 0u)
    {
#if (CY_HPD_ENABLE)
        /* Handle the queue interrupt, instead of specific plug/unplug/irq interrupts. */
        if (((pd->intr2_masked & PDSS_INTR2_HPD_QUEUE) != 0u) || ((pd->intr2_masked & PDSS_INTR2_HPDT_COMMAND_DONE) != 0u))
        {
            /* Call the Hpd Interrupt Handler function */
            Cy_USBPD_Hpd_Intr0Handler(context);
        }
#endif /* CY_HPD_ENABLE */

#if (!(CY_PD_SOURCE_ONLY))
#if (CY_PD_REV3_ENABLE && CY_PD_FRS_RX_ENABLE)
        if ((pd->intr2_masked & (PDSS_INTR2_SWAP_RCVD | PDSS_INTR2_SWAP_DISCONNECT)) != 0u)
        {
            /* Disable frs receive interrupts as we cannot clear them here. */
            pd->intr2_mask &= ~(PDSS_INTR2_SWAP_RCVD | PDSS_INTR2_SWAP_DISCONNECT);

            /* Disable the swap controller */
            pd->swap_ctrl1 |= PDSS_SWAP_CTRL1_RESET_SWAP_STATE;

            /* Stop any ongoing transmission */
            CALL_MAP(Cy_USBPD_Phy_Reset_RxTx_SM)(context);

            /* Clear pending rx interrupts */
            pd->intr0 = RCV_INTR_MASK | PDSS_INTR0_COLLISION_TYPE3 | PDSS_INTR0_TX_GOODCRC_MSG_DONE;

            context->rxUnchunked = false;
            pd->intr2 = PDSS_INTR2_EXTENDED_MSG_DET | PDSS_INTR2_CHUNK_DET | PDSS_INTR2_RX_SRAM_OVER_FLOW;

            /* Turn off the consumer fet */
            if (NULL != context->usbpdEventsCbk)
            {
                context->usbpdEventsCbk (context, CY_USBPD_EVT_FRS_SIGNAL_RCVD, (void *)(context->pdStackContext));
            }
            dpmConfig->skipScan = true;

            if(context->pdPhyCbk != NULL)
            {
                context->pdPhyCbk((void *)(context->pdStackContext), CY_USBPD_PHY_EVT_FRS_SIG_RCVD);
            }

            /* Cannot clear interrupt here as this will cause auto fet turn on to assume no FRS signal */
            NVIC_ClearPendingIRQ(usbpd_0_interrupt_IRQn + context->port);

            /* Enable the SWAP_VBUS_LESS_5_DONE interrupt so that we can identify when the power swap is done. */
#if defined(CY_DEVICE_CCG6DF_CFP)
            pd->intr20_mask |= PDSS_INTR20_VSWAP_VBUS_LESS_5_DONE;
#else
            pd->intr1_mask |= PDSS_INTR1_VSWAP_VBUS_LESS_5_DONE;
#endif /* defined(CY_DEVICE_CCG6DF_CFP) */
        }
#endif /* (CY_PD_REV3_ENABLE && CY_PD_FRS_RX_ENABLE) */

#if (CY_PD_REV3_ENABLE && CY_PD_FRS_TX_ENABLE)
        if ((pd->intr2_masked & PDSS_INTR2_SWAP_COMMAND_DONE) != 0u)
        {
            Cy_USBPD_Vbus_FrsTxDisable(context);
            dpmConfig->frTxEnLive = false;

            CALL_MAP(Cy_USBPD_Phy_Reset_RxTx_SM)(context);

            /* Change Rp to allow sink to initiate AMS */
            Cy_USBPD_TypeC_ChangeRp(context, CY_PD_RP_TERM_RP_CUR_3A);

            /* Turn On the sink fet and stop sourcing the power. */
            if (NULL != context->usbpdEventsCbk)
            {
                context->usbpdEventsCbk (context, CY_USBPD_EVT_FRS_SIGNAL_SENT, NULL);
            }

            if(context->pdPhyCbk != NULL)
            {
                context->pdPhyCbk((void *)(context->pdStackContext), CY_USBPD_PHY_EVT_FRS_SIG_SENT);
            }
        }
#endif /* (CY_PD_REV3_ENABLE && CY_PD_FRS_TX_ENABLE) */
#endif /* (!(CY_PD_SOURCE_ONLY)) */
    }
    
#if ((defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP) || defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) && (!QC_AFC_CHARGING_DISABLED))
    if(pd->intr4_masked != 0u)
    {
        Cy_USBPD_Bch_Intr0Handler(context);
    }
    
    if(pd->intr6_masked != 0u)
    {
        Cy_USBPD_Bch_Intr0Handler(context);
    }
#endif /* ((defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP) || defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) && (!QC_AFC_CHARGING_DISABLED)) */
#if PDL_VBTR_ENABLE
    if ((pd->intr8_masked & (PDSS_INTR8_VBTR_OPR_DONE)) != 0u)
    {
        /* Load latest VBTR source and sink IDAC values to EA control */
        uint32_t src_dac_u32;
        uint32_t snk_dac_u32;
        int16_t src_dac = 0;
        int16_t snk_dac = 0;

        if ((pd->vbtr_cfg & PDSS_VBTR_CFG_SRC_EN) != 0u)
        {
            src_dac_u32 = ((pd->vbtr_src_snk_opr_value & PDSS_VBTR_SRC_SNK_OPR_VALUE_SRC_DAC_MASK) >>
                    PDSS_VBTR_SRC_SNK_OPR_VALUE_SRC_DAC_POS);
            src_dac = (int16_t)src_dac_u32;
#if VBTR_MULTI_SLOPE_ENABLE
            context->vbtrSrcPending = false;
#endif /* VBTR_MULTI_SLOPE_ENABLE */
        }
        if ((pd->vbtr_cfg & PDSS_VBTR_CFG_SNK_EN) != 0u)
        {
            snk_dac_u32 = ((pd->vbtr_src_snk_opr_value & PDSS_VBTR_SRC_SNK_OPR_VALUE_SNK_DAC_MASK) >>
                    PDSS_VBTR_SRC_SNK_OPR_VALUE_SNK_DAC_POS);
            snk_dac = (int16_t)snk_dac_u32;
#if VBTR_MULTI_SLOPE_ENABLE
            context->vbtrSnkPending = false;
#endif /* VBTR_MULTI_SLOPE_ENABLE */
        }

        /*
         * Load the DAC register with the final data. We have to copy the data from
         * the VBTR shadow register to main register. Also, by calling the set function,
         * the TRIM will be loaded according to the DAC used.
         */
        Cy_USBPD_Hal_Set_Fb_Dac(context, (snk_dac - src_dac));

        /*
         * It is must to load the ea_ctrl with latest VBTR source
         * and sink values and then clear the interrupt flags.
         * This sequence is a must because once the interrupt is cleared, DAC
         * control signal to EA will be driven and EA gets triggered for the
         * old IDAC values.
         */
        pd->intr8 = (PDSS_INTR8_VBTR_OPR_DONE | PDSS_INTR8_VBTR_EXIT_DONE);

#if defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)
#if BB_VBTR_IBTR_FCCM_DIS
        /* Re-enable FCCM once VBTR/IBTR is done */
        Cy_USBPD_BB_SetMode(port, BB_MODE_FCCM);
#endif /* BB_VBTR_IBTR_FCCM_DIS */
#endif /* defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1) */

#if VBTR_MULTI_SLOPE_ENABLE
        /*
         * If it is a multi slope VBTR transition across SRC and SINK,
         * then initiate the pending SRC or SINK transition with a different
         * step size or slope value.
         */
        if ((context->vbtrSrcPending == true) || (context->vbtrSnkPending == true))
        {
            if(context->vbtrSnkPending == true)
            {
                pd->vbtr_cfg &= ~PDSS_VBTR_CFG_SRC_EN;
                pd->vbtr_cfg |= PDSS_VBTR_CFG_SNK_EN;
                Cy_SysClk_PeriphSetDivider(CY_SYSCLK_DIV_16_BIT, 0U, (hfclk_mhz * (pwr_cfg->vbtr_up_step_width)));
            }
            else
            {
                pd->vbtr_cfg &= ~PDSS_VBTR_CFG_SNK_EN;
                pd->vbtr_cfg |= PDSS_VBTR_CFG_SRC_EN;
                Cy_SysClk_PeriphSetDivider(CY_SYSCLK_DIV_16_BIT, 0U, (hfclk_mhz * (pwr_cfg->vbtr_down_step_width_below_5V)));
            }

            /* Clear and enable VBTR interrupt */
            pd->intr8 = (PDSS_INTR8_VBTR_OPR_DONE | PDSS_INTR8_VBTR_EXIT_DONE);
            pd->intr8_mask |= (PDSS_INTR8_VBTR_OPR_DONE);

            /* Start idac operation */
            pd->vbtr_ctrl |= PDSS_VBTR_CTRL_START;
        }
        else
#endif /* VBTR_MULTI_SLOPE_ENABLE */
        {
            /* Reset VBTR configuration */
            pd->vbtr_cfg = 0;

            /* Invoke callback. */
            context->vbtrIdle = true;
            if (context->vbtrCbk != NULL)
            {
                context->vbtrCbk (context, true);
            }
        }
    }
#endif /* PDL_VBTR_ENABLE */

#if PDL_IBTR_ENABLE
    if(pd->intr8_masked & (PDSS_INTR8_IBTR_OPR_DONE))
    {
        uint16_t ibtr_dac = 0;

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

        /*
         * It is must to load the refgen with latest IBTR value and
         * then clear the interrupt flags.
         * This sequence is a must because once the interrupt is cleared, refgen
         * control signal EA will be driven and EA gets triggered for the
         * old refgen values.
         */
        pd->ibtr_cfg = 0;
        pd->intr8 = (PDSS_INTR8_IBTR_OPR_DONE | PDSS_INTR8_IBTR_EXIT_DONE);

#if defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)
#if BB_VBTR_IBTR_FCCM_DIS
        /* Re-enable FCCM once VBTR/IBTR is done */
        Cy_USBPD_BB_SetMode(port, BB_MODE_FCCM);
#endif /* BB_VBTR_IBTR_FCCM_DIS */
#endif /* defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1) */

        /* Invoke callback. */
        context->ibtrIdle = true;

        if (context->ibtrCbk != NULL)
        {
            context->ibtrCbk (context, true);
        }
    }
#endif /* PDL_IBTR_ENABLE */
#if defined(CY_DEVICE_CCG6DF_CFP)
    if (pd->intr21_masked != 0)
    {
        /* Save current SBU<->DBG connection status */
        if (pd->intr21 & PDSS_INTR21_SBU_DBG_CONNECTION)
        {
            /* Enable SBU OVP */
            pd->intr3_cfg_sbu20_ovp_hs =
                PDSS_INTR3_CFG_SBU20_OVP_HS_SBU1_FILT_EN                |
                0x02UL << PDSS_INTR3_CFG_SBU20_OVP_HS_SBU1_FILT_CFG_POS |
                0x01UL << PDSS_INTR3_CFG_SBU20_OVP_HS_SBU1_FILT_SEL_POS |
                PDSS_INTR3_CFG_SBU20_OVP_HS_SBU2_FILT_EN                |
                0x02UL << PDSS_INTR3_CFG_SBU20_OVP_HS_SBU2_FILT_CFG_POS |
                0x01UL << PDSS_INTR3_CFG_SBU20_OVP_HS_SBU2_FILT_SEL_POS;
        }

        /* Clear the SBU debug connection interrupt.*/
        pd->intr21 = pd->intr21_masked;
    }
#endif /* defined(CY_DEVICE_CCG6DF_CFP) */
}

#endif /* (defined(CY_IP_MXUSBPD) || defined(CY_IP_M0S8USBPD)) */

/* [] END OF FILE */
