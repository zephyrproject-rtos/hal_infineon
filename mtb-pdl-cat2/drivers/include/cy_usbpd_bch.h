/***************************************************************************//**
* \file cy_usbpd_bch.h
* \version 2.110
*
* Header file for legacy charging feature of USBPD PDL.
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

#ifndef _CY_USBPD_BCH_H_
#define _CY_USBPD_BCH_H_

#include <cy_usbpd_common.h>

/**
* \addtogroup group_usbpd_legacy
* \{
* USBPD Legacy Charging driver.
*
* \defgroup group_usbpd_legacy_macros Macros
* \defgroup group_usbpd_legacy_enums Enumerated Types
* \defgroup group_usbpd_legacy_functions Functions
*/
#if (defined(CY_IP_MXUSBPD) || defined(CY_IP_M0S8USBPD))

/*******************************************************************************
 * MACRO Definition
 ******************************************************************************/

/**
* \addtogroup group_usbpd_legacy_macros
* \{
*/
#define BC_EVT_NONE                             (0x00000000u)
/**< No legacy charging events pending. */

#define BC_EVT_ENTRY                            (0x00000001u)
/**< Legacy charging state change pending. */

#define BC_EVT_CMP1_FIRE                        (0x00000002u)
/**< Charger detect comparator-1 interrupt raised. */

#define BC_EVT_CMP2_FIRE                        (0x00000004u)
/**< Charger detect comparator-2 interrupt raised. */

#define BC_EVT_QC_CHANGE                        (0x00000008u)
/**< Qualcomm charging state change. */

#define BC_EVT_QC_CONT                          (0x00000010u)
/**< QC charging continuous mode entry. */

#define BC_EVT_AFC_RESET_RCVD                   (0x00000020u)
/**< Adaptive Fast Charging Reset received. */

#define BC_EVT_AFC_MSG_RCVD                     (0x00000040u)
/**< Adaptive Fast Charging message received. */

#define BC_EVT_AFC_MSG_SENT                     (0x00000080u)
/**< Adaptive Fast Charging message sent. */

#define BC_EVT_AFC_MSG_SEND_FAIL                (0x00000100u)
/**< Adaptive Fast Charging message sending failed. */

#define BC_EVT_TIMEOUT1                         (0x00000200u)
/**< Charger detect state machine timeout #1. */

#define BC_EVT_TIMEOUT2                         (0x00000400u)
/**< Charger detect state machine timeout #1. */

#define BC_EVT_DISCONNECT                       (0x00000800u)
/**< Disconnect detected by charger detect state machine. */

#define BC_EVT_ALL_MASK                         (0xFFFFFFFFu)
/**< Mask all charger detect states. */

#define BCH_PORT_0_CMP1_INTR_MASK               (0x1UL)
/**< Interrupt mask for charger detect comparator #1 on port 0. */

#define BCH_PORT_0_CMP2_INTR_MASK               (0x2UL)
/**< Interrupt mask for charger detect comparator #2 on port 0. */

#define BCH_PORT_0_CMP1_2_INTR_MASK             (BCH_PORT_0_CMP1_INTR_MASK | BCH_PORT_0_CMP2_INTR_MASK)
/**< Interrupt mask for both charger detect comparators on port 0. */

#define BCH_PORT_1_CMP1_INTR_MASK               (0x4UL)
/**< Interrupt mask for charger detect comparator #1 on port 1. */

#define BCH_PORT_1_CMP2_INTR_MASK               (0x8UL)
/**< Interrupt mask for charger detect comparator #1 on port 1. */

#define BCH_PORT_1_CMP1_2_INTR_MASK             (0xcUL)
/**< Interrupt mask for both charger detect comparators on port 1. */

#define QC3_PORT_0_DP_PULSE_MASK                (0x01UL)
/**< Interrupt mask for QC 3.0 pulse on D+ pin of port 0. */

#define QC3_PORT_0_DM_PULSE_MASK                (0x10UL)
/**< Interrupt mask for QC 3.0 pulse on D- pin of port 0. */

#define QC3_PORT_0_DP_DM_PULSE_MASK             (0x11UL)
/**< Interrupt mask for QC 3.0 pulse on D+/D- pin of port 0. */

#define QC3_PORT_1_DP_PULSE_MASK                (0x02UL)
/**< Interrupt mask for QC 3.0 pulse on D+ pin of port 1. */

#define QC3_PORT_1_DM_PULSE_MASK                (0x20UL)
/**< Interrupt mask for QC 3.0 pulse on D- pin of port 1. */

#define QC3_PORT_1_DP_DM_PULSE_MASK             (0x22UL)
/**< Interrupt mask for QC 3.0 pulse on D+/D- pin of port 1. */

#define QC3_DP_DM_PULSE_FILTER_CLOCK_SEL        (160UL)
/**< QC 3.0 D+/D- pulse filter setting: 160us assuming 1MHz clock. */

#define AFC_UI_CLK_CYCLE_COUNT                  (160UL)
/**< AFC UI (160us) in terms of number of 1MHz clock cycles. */

#define AFC_IDLE_OPCODE                         (0UL)
/**< AFC state machine idle. */

#define AFC_TX_PING_OPCODE                      (1UL)
/**< AFC transmitter ping opcode. */

#define AFC_RX_PING_OPCODE                      (2UL)
/**< AFC receiver ping opcode. */

#define AFC_TX_DATA_M_OPCODE                    (3UL)
/**< AFC master data transmit opcode. */

#define AFC_TX_DATA_S_OPCODE                    (4UL)
/**< AFC slave data transmit opcode. */

#define AFC_RX_DATA_OPCODE                      (5UL)
/**< AFC receive data opcode. */

#define AFC_SOURCE_OPCODE                       ((AFC_RX_PING_OPCODE << 0) | (AFC_TX_PING_OPCODE << 3) | \
                                                (AFC_RX_DATA_OPCODE << 6) | (AFC_TX_PING_OPCODE << 9) | \
                                                (AFC_TX_DATA_S_OPCODE << 12) | (AFC_RX_PING_OPCODE << 15) | \
                                                (AFC_TX_PING_OPCODE << 18) | (AFC_IDLE_OPCODE << 21))
/**< AFC source opcode selection. */

#define AFC_SINK_OPCODE                         ((AFC_TX_PING_OPCODE << 0) | (AFC_RX_PING_OPCODE << 3) | \
                                                (AFC_TX_DATA_M_OPCODE << 6) | (AFC_RX_PING_OPCODE << 9) |(AFC_RX_DATA_OPCODE << 12) | \
                                                (AFC_TX_PING_OPCODE << 15) | (AFC_RX_PING_OPCODE << 18) | \
                                                (AFC_IDLE_OPCODE << 21))
/**< AFC sink opcode selection. */

#define AFC_SINK_OPCODE_PING                    ((AFC_TX_PING_OPCODE << 0) | (AFC_RX_PING_OPCODE << 3) | \
                                                (AFC_IDLE_OPCODE << 6))
/**< AFC sink ping opcode selection. */

#define AFC_MAX_BYTES                           (16u)
/**< Maximum number of bytes in an AFC message. */

#define AFC_BASE_VOLT                           (5000u)
/**< Base voltage level during AFC negotiation. */

#define AFC_VOLT_STEP                           (1000u)
/**< AFC voltage unit increment. */

#define AFC_BASE_AMP                            (75u)
/**< Minimum AFC current level in 10 mA units. */

#define AFC_AMP_STEP                            (15u)
/**< AFC current level unit increment in 10 mA units. */

#define AFC_MAX_AMP                             (0x0Fu)
/**< Max current bit value for AFC VI message */

#define CDP_CHGDET_VREF_325mV                   (0u)     /**< VRef selection: 325 mV */
#define CDP_CHGDET_VREF_600mV                   (1u)     /**< VRef selection: 700 mV */
#define CDP_CHGDET_VREF_850mV                   (2u)     /**< VRef selection: 850 mV */

#define CDP_CHGDET_COMP_INP_DM                  (0u)     /**< Chg.Det. comparator input selection: D- */
#define CDP_CHGDET_COMP_INP_VREF                (1u)     /**< Chg.Det. comparator input selection: VRef */
#define CDP_CHGDET_COMP_INP_DP                  (2u)     /**< Chg.Det. comparator input selection: D+ */


#define BC_SINK_1_2_MODE_ENABLE_MASK        (0x01UL)
/**< BC 1.2 sink mode enable mask for config table parameter. */

#define BC_SINK_APPLE_MODE_ENABLE_MASK      (0x02UL)
/**< Apple sink mode enable mask for config table parameter. */

#define BC_SINK_QC_MODE_ENABLE_MASK         (0x04UL)
/**< QC 2.0 sink mode enable mask for config table parameter. */

#define BC_SINK_AFC_MODE_ENABLE_MASK        (0x08UL)
/**< AFC sink mode enable mask for config table parameter. */

#define BC_SINK_ALL_MODES_DISABLED          (0x00UL)
/**< all legacy sink modes are disabled for config table parameter. */

#define BC_SRC_1_2_MODE_ENABLE_MASK         (0x01UL)
/**< BC 1.2 Source mode enable mask for config table parameter. */

#define BC_SRC_APPLE_MODE_ENABLE_MASK       (0x02UL)
/**< Apple source mode enable mask for config table parameter. */

#define BC_SRC_QC_MODE_ENABLE_MASK          (0x04UL)
/**< QC source mode enable mask for config table parameter. */

#define BC_SRC_AFC_MODE_ENABLE_MASK         (0x08UL)
/**< AFC source mode enable mask for config table parameter. */

#define BC_SRC_QC_4_0_MODE_ENABLE_MASK      (0x10UL)
/**< QC 4.0 mode enable mask for config table parameter. */

#define BC_SRC_QC_VER_2_CLASS_A_VAL         (0UL)
/**< QC source Version and class mask for config table parameter. */

#define BC_SRC_QC_VER_2_CLASS_B_VAL         (1UL)
/**< QC source Version and class mask for config table parameter. */

#define BC_SRC_QC_VER_3_CLASS_A_VAL         (2UL)
/**< QC source Version and class mask for config table parameter. */

#define BC_SRC_QC_VER_3_CLASS_B_VAL         (3UL)
/**< QC source Version and class mask for config table parameter. */

#define BC_CMP_0_IDX                    (0u)    /**< Battery charger comparator #1. */
#define BC_CMP_1_IDX                    (1u)    /**< Battery charger comparator #2. */

#define  BC_PORT_0_IDX                      (0u)
/**< BC PORT 0 INDEX. */

#define  BC_PORT_1_IDX                      (1u)
/**< BC PORT 1 INDEX. */

#define CY_FLIPPED_DP_DM                    (0u)
/**< Flipped DP and DM Enable. */

#define CY_TYPE_A_PORT_ENABLE               (0u)
/**< Enable TYPE-A support. */

#define BC_AMP_LIMIT                    (300)   /**< Maximum current across various BC modes: 3.0 A. */
#define APPLE_AMP_1A                    (100)   /**< Current limit for Apple 1.0A brick. */
#define APPLE_AMP_2_1A                  (210)   /**< Current limit for Apple 2.1A brick. */
#define APPLE_AMP_2_4A                  (240)   /**< Current limit for Apple 2.4A brick. */
#define APPLE_AMP_3A                    (300)   /**< Current limit for Apple 3.0A brick. */
#define QC_AMP_5V                       (300)   /**< Current limit for Quick Charge at 5 V. */
#define QC_AMP_9V                       (300)   /**< Current limit for Quick Charge at 9 V. */
#define QC_AMP_12V                      (300)   /**< Current limit for Quick Charge at 12 V. */
#define QC_AMP_20V                      (300)   /**< Current limit for Quick Charge at 20 V. */
#define QC_AMP_CONT                     (300)   /**< Current limit for Quick Charge continuous mode. */
#define QC_CONT_VOLT_CHANGE_PER_PULSE   (200u)  /**< Quick Charge continuous mode voltage change per pulse received. */
#define QC3_MIN_VOLT                    (3400u) /**< Minimum supply voltage used in QC charging. */


#ifndef PDSS_INTR4_AFC_PING_RECVD
#define PDSS_INTR4_AFC_PING_RECVD       (1UL << 0UL)    /**< AFC interrupt status bit. */
#endif /* PDSS_INTR4_AFC_PING_RECVD */

#ifndef PDSS_INTR4_AFC_SM_IDLE
#define PDSS_INTR4_AFC_SM_IDLE          (1UL << 12UL)   /**< AFC interrupt status bit. */
#endif /* PDSS_INTR4_AFC_SM_IDLE */

#ifndef PDSS_INTR4_AFC_TIMEOUT
#define PDSS_INTR4_AFC_TIMEOUT          (1UL << 16UL)   /**< AFC interrupt status bit. */
#endif /* PDSS_INTR4_AFC_TIMEOUT */

#ifndef PDSS_INTR4_AFC_RX_RESET
#define PDSS_INTR4_AFC_RX_RESET         (1UL << 20UL)   /**< AFC interrupt status bit. */
#endif /* PDSS_INTR4_AFC_RX_RESET */

#ifndef PDSS_INTR4_UPDATE_PING_PONG
#define PDSS_INTR4_UPDATE_PING_PONG     (1UL << 24UL)   /**< AFC interrupt status bit. */
#endif /* PDSS_INTR4_UPDATE_PING_PONG */

#ifndef PDSS_INTR4_AFC_ERROR
#define PDSS_INTR4_AFC_ERROR            (1UL << 28UL)   /**< AFC interrupt status bit. */
#endif /* PDSS_INTR4_AFC_ERROR */

#ifndef PDSS_CTRL_AFC_ENABLED
#define PDSS_CTRL_AFC_ENABLED           (1UL << 25UL)   /**< AFC enable bit value. */
#endif /* PDSS_CTRL_AFC_ENABLED */

#define CDP_DX_VOLTAGE_CHECK_PERIOD             (15u)    /**< Frequency of D+/D- voltage checks in CDP state machine. */
#define CDP_VDMSRC_FAULT_CHECK_PERIOD           (2u)     /**< Frequency of D- voltage checks once a fault has been detected. */
#define MAX_CDP_VDMSRC_FAULT_COUNT              (3u)     /**< Max. number of faulty D- voltage readings allowed. */

/** \} group_usbpd_legacy_macros */

/*******************************************************************************
*                              Function Prototypes
*******************************************************************************/

/**
* \addtogroup group_usbpd_legacy_functions
* \{
* The functions provide a set of APIs to handle battery charging operations
*
*/

cy_en_usbpd_status_t Cy_USBPD_Bch_Phy_Init(cy_stc_usbpd_context_t *context,
                                           cy_cb_bc_phy_events_t bcPhyCbk);

cy_en_usbpd_status_t Cy_USBPD_Bch_Phy_En(cy_stc_usbpd_context_t *context);

cy_en_usbpd_status_t Cy_USBPD_Bch_Phy_Dis(cy_stc_usbpd_context_t *context);

cy_en_usbpd_status_t Cy_USBPD_Bch_Phy_ConfigSrcTerm(cy_stc_usbpd_context_t *context,
                                                    cy_en_usbpd_bch_src_term_t chargerTerm);

cy_en_usbpd_status_t Cy_USBPD_Bch_Phy_ConfigSnkTerm(cy_stc_usbpd_context_t *context,
                                                    cy_en_usbpd_bch_snk_term_t chargerTerm);

cy_en_usbpd_status_t Cy_USBPD_Bch_Phy_RemoveTerm(cy_stc_usbpd_context_t *context);

bool Cy_USBPD_Bch_Phy_Config_Comp(cy_stc_usbpd_context_t *context,
                                  uint8_t compIdx,
                                  cy_en_usbpd_bch_comp_pinput_t pInput,
                                  cy_en_usbpd_bch_comp_ninput_t mInput,
                                  cy_en_usbpd_bch_vref_t vref,
                                  cy_en_usbpd_bch_comp_edge_t edge);

cy_en_usbpd_status_t Cy_USBPD_Bch_Phy_DisableComp(cy_stc_usbpd_context_t *context,
                                                  uint8_t compIdx);

cy_en_usbpd_status_t Cy_USBPD_Bch_Phy_Isolate_DpDm(cy_stc_usbpd_context_t *context);

bool Cy_USBPD_Bch_Phy_CompResult(cy_stc_usbpd_context_t *context, uint8_t compIdx);

cy_en_usbpd_status_t Cy_USBPD_Bch_ApplyDpPd(cy_stc_usbpd_context_t *context);

cy_en_usbpd_status_t Cy_USBPD_Bch_RemoveDpPd(cy_stc_usbpd_context_t *context);

cy_en_usbpd_status_t Cy_USBPD_Bch_ApplyDmPd(cy_stc_usbpd_context_t *context);

cy_en_usbpd_status_t Cy_USBPD_Bch_RemoveDmPd(cy_stc_usbpd_context_t *context);

cy_en_usbpd_status_t Cy_USBPD_Bch_ApplyDpPu(cy_stc_usbpd_context_t *context);

cy_en_usbpd_status_t Cy_USBPD_Bch_RemoveDpPu(cy_stc_usbpd_context_t *context);

void Cy_USBPD_Bch_ApplyRdatLkgDp(cy_stc_usbpd_context_t *context);

void Cy_USBPD_Bch_ApplyRdatLkgDm(cy_stc_usbpd_context_t *context);

void Cy_USBPD_Bch_RemoveRdatLkgDp(cy_stc_usbpd_context_t *context);

void Cy_USBPD_Bch_RemoveRdatLkgDm(cy_stc_usbpd_context_t *context);

void Cy_USBPD_Bch_Apply_AppleTermDp(cy_stc_usbpd_context_t *context,
                                       cy_en_usbpd_bch_src_term_t appleTermId);

void Cy_USBPD_Bch_Apply_AppleTermDm(cy_stc_usbpd_context_t *context,
                                       cy_en_usbpd_bch_src_term_t appleTermId);

void Cy_USBPD_Bch_Apply_VdmSrc(cy_stc_usbpd_context_t *context);

void Cy_USBPD_Bch_Remove_VdmSrc(cy_stc_usbpd_context_t *context);

bool Cy_USBPD_Bch_Is_VdmSrc_On(cy_stc_usbpd_context_t *context);

void Cy_USBPD_Bch_Remove_AppleSrcDp(cy_stc_usbpd_context_t *context);

void Cy_USBPD_Bch_Remove_AppleSrcDm(cy_stc_usbpd_context_t *context);

void Cy_USBPD_Bch_Enable_AppleDet(cy_stc_usbpd_context_t *context);

void Cy_USBPD_Bch_Disable_AppleDet(cy_stc_usbpd_context_t *context);

bool Cy_USBPD_Bch_Phy_DpStat(cy_stc_usbpd_context_t *context);

bool Cy_USBPD_Bch_Phy_DmStat(cy_stc_usbpd_context_t *context);

void Cy_USBPD_Bch_Phy_Config_DeepSleep(cy_stc_usbpd_context_t *context);

void Cy_USBPD_Bch_Phy_Config_Wakeup(cy_stc_usbpd_context_t *context);

void Cy_USBPD_Bch_Intr1Handler(cy_stc_usbpd_context_t *context);

#if (!QC_AFC_CHARGING_DISABLED)
cy_en_usbpd_status_t Cy_USBPD_Bch_QcSrcInit(cy_stc_usbpd_context_t *context);

cy_en_usbpd_status_t Cy_USBPD_Bch_QcSrcStop(cy_stc_usbpd_context_t *context);

cy_en_usbpd_status_t Cy_USBPD_Bch_QcSrcMasterSenseEn(cy_stc_usbpd_context_t *context);

cy_en_usbpd_status_t Cy_USBPD_Bch_QcSrcMasterSenseDis(cy_stc_usbpd_context_t *context);

cy_en_usbpd_status_t Cy_USBPD_Bch_QcSrcContModeStart(cy_stc_usbpd_context_t *context);

cy_en_usbpd_status_t Cy_USBPD_Bch_QcSrcContModeStop(cy_stc_usbpd_context_t *context);

cy_en_usbpd_status_t Cy_USBPD_Bch_AfcSrcInit(cy_stc_usbpd_context_t *context);

cy_en_usbpd_status_t Cy_USBPD_Bch_AfcSrcStart(cy_stc_usbpd_context_t *context);

cy_en_usbpd_status_t Cy_USBPD_Bch_AfcSrcStop(cy_stc_usbpd_context_t *context);

void Cy_USBPD_Bch_Afc_Set_Tx_Data(cy_stc_usbpd_context_t *context, uint8_t* dataPtr, uint8_t count);

cy_en_usbpd_status_t Cy_USBPD_Bch_AfcSinkInit(cy_stc_usbpd_context_t *context);

cy_en_usbpd_status_t Cy_USBPD_Bch_AfcSinkStartPing(cy_stc_usbpd_context_t *context);

cy_en_usbpd_status_t Cy_USBPD_Bch_AfcSinkStart(cy_stc_usbpd_context_t *context);

cy_en_usbpd_status_t Cy_USBPD_Bch_AfcSinkStop(cy_stc_usbpd_context_t *context);

uint8_t * Cy_USBPD_Bch_AfcGetRxDataPtr(cy_stc_usbpd_context_t *context);

uint8_t Cy_USBPD_Bch_AfcGetRxDataCount(cy_stc_usbpd_context_t *context);

void Cy_USBPD_Bch_AfcLoadTxData(cy_stc_usbpd_context_t *context);

void Cy_USBPD_Bch_QC3_IntrHandler(cy_stc_usbpd_context_t *context);

void Cy_USBPD_Bch_AfcPingPong_IntrHandler(cy_stc_usbpd_context_t *context);

void Cy_USBPD_Bch_AfcIdle_IntrHandler(cy_stc_usbpd_context_t *context);

void Cy_USBPD_Bch_AfcReset_IntrHandler(cy_stc_usbpd_context_t *context);

void Cy_USBPD_Bch_Intr0Handler(cy_stc_usbpd_context_t *context);

#endif /* (!QC_AFC_CHARGING_DISABLED) */

#if (defined(CCG_CDP_EN) && BATTERY_CHARGING_ENABLE)
bool Cy_USBPD_Bch_CompareVolt(cy_stc_usbpd_context_t *context, uint8_t inp, uint8_t vref);

void Cy_USBPD_Bch_Dm_VoltPoll(cy_stc_usbpd_context_t *context);

void Cy_USBPD_Bch_BcDis(cy_stc_usbpd_context_t *context);

bool Cy_USBPD_Bch_CdpSm(cy_stc_usbpd_context_t *context);

void Cy_USBPD_Bch_CdpEn(cy_stc_usbpd_context_t *context);

bool Cy_USBPD_Bch_Is_Cdp_SmBusy(cy_stc_usbpd_context_t *context);

#endif /* (defined(CCG_CDP_EN) && BATTERY_CHARGING_ENABLE) */
/*******************************************************************************
* Function Name: Cy_USBPD_Bch_Get_QcPulseCount
****************************************************************************//**
*
* This function returns the QC3 pulse count stored in the context variable 
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \return
* QC3 pulse count
*
*******************************************************************************/
__STATIC_INLINE int Cy_USBPD_Bch_Get_QcPulseCount(cy_stc_usbpd_context_t *context)
{
    uint32_t intr_state = Cy_SysLib_EnterCriticalSection();
    int count = context->bcQcPulseCount;
    Cy_SysLib_ExitCriticalSection(intr_state);

    return count;
}

/*******************************************************************************
* Function Name: Cy_USBPD_Bch_Update_QcPulseCount
****************************************************************************//**
*
* This function update the QC3 pulse count in the context variable 
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \param new_count
* New QC3 pulse count received
*
* \return
* None
*
*******************************************************************************/
__STATIC_INLINE void Cy_USBPD_Bch_Update_QcPulseCount(cy_stc_usbpd_context_t *context, int new_count)
{
    uint32_t intr_state = Cy_SysLib_EnterCriticalSection();
    context->bcQcPulseCount = context->bcQcPulseCount - new_count;
    Cy_SysLib_ExitCriticalSection(intr_state);
}

/*******************************************************************************
* Function Name: Cy_USBPD_Bch_Get_AfcDataPtr
****************************************************************************//**
*
* This function returns the USBPD context AFC received data pointer.
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \return
* AFC received data pointer
*
*******************************************************************************/
__STATIC_INLINE uint8_t* Cy_USBPD_Bch_Get_AfcDataPtr(cy_stc_usbpd_context_t *context)
{
    return context->bcAfcRxBuf;
}

/*******************************************************************************
* Function Name: Cy_USBPD_Bch_Get_AfcDataCount
****************************************************************************//**
*
* This function returns the USBPD context AFC received data count.
*
* \param context
* Pointer to the context structure \ref cy_stc_usbpd_context_t.
*
* \return
* AFC received data count
*
*******************************************************************************/
__STATIC_INLINE uint8_t Cy_USBPD_Bch_Get_AfcDataCount(cy_stc_usbpd_context_t *context)
{
    return context->bcAfcRxIdx;
}

/** \} group_usbpd_legacy_functions */

#endif /* (defined(CY_IP_MXUSBPD) || defined(CY_IP_M0S8USBPD)) */

#endif /* _CY_USBPD_BCH_H_ */

/** \} group_usbpd_legacy */

/* [] End of File */
