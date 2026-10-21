/***************************************************************************//**
* \file cyip_can.h
*
* \brief
* CAN IP definitions
*
********************************************************************************
* \copyright
* (c) (2016-2025), Cypress Semiconductor Corporation (an Infineon company) or
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

#ifndef _CYIP_CAN_H_
#define _CYIP_CAN_H_

#include "cyip_headers.h"

/*******************************************************************************
*                                     CAN
*******************************************************************************/

#define CAN_TX_SECTION_SIZE                     0x00000010UL
#define CAN_RX_SECTION_SIZE                     0x00000020UL
#define CAN_SECTION_SIZE                        0x00010000UL

/**
  * \brief TxMessage Buffer control/command (CAN_TX)
  */
typedef struct {
  __IOM uint32_t CONTROL;                       /*!< 0x00000000 TxMessage Buffer control/command */
  __IOM uint32_t ID;                            /*!< 0x00000004 TxMessage Buffer Identifier */
  __IOM uint32_t DATA_HIGH;                     /*!< 0x00000008 TxMessage Buffer Data high */
  __IOM uint32_t DATA_LOW;                      /*!< 0x0000000C TxMessageBuffer Data low */
} CAN_TX_Type;                                  /*!< Size = 16 (0x10) */

/**
  * \brief RxMessage buffer control/command (CAN_RX)
  */
typedef struct {
  __IOM uint32_t CONTROL;                       /*!< 0x00000000 RxMessage Buffer control/command */
  __IOM uint32_t ID;                            /*!< 0x00000004 Identifier */
  __IOM uint32_t DATA_HIGH;                     /*!< 0x00000008 RxMessage Data high */
  __IOM uint32_t DATA_LOW;                      /*!< 0x0000000C RxMessage Data low */
  __IOM uint32_t AMR;                           /*!< 0x00000010 Acceptance Mask Register */
  __IOM uint32_t ACR;                           /*!< 0x00000014 Acceptance Code Register */
  __IOM uint32_t AMR_DATA;                      /*!< 0x00000018 Acceptance Mask Register - Data */
  __IOM uint32_t ACR_DATA;                      /*!< 0x0000001C Acceptance Code Register - Data */
} CAN_RX_Type;                                  /*!< Size = 32 (0x20) */

/**
  * \brief CAN Controller (CAN)
  */
typedef struct {
  __IOM uint32_t INT_STATUS;                    /*!< 0x00000000 Interrupt Status */
  __IOM uint32_t INT_EBL;                       /*!< 0x00000004 Interrupt Enable */
   __IM uint32_t BUFFER_STATUS;                 /*!< 0x00000008 RxMessage and TxMessage Buffer Status */
   __IM uint32_t ERROR_STATUS;                  /*!< 0x0000000C CAN Error Status */
  __IOM uint32_t COMMAND;                       /*!< 0x00000010 CAN Command Register */
  __IOM uint32_t CONFIG;                        /*!< 0x00000014 CAN Configuration */
  __IOM uint32_t ECR;                           /*!< 0x00000018 Error Capture Register */
   __IM uint32_t RESERVED;
        CAN_TX_Type TX[8];                      /*!< 0x00000020 TxMessage Buffer control/command */
        CAN_RX_Type RX[16];                     /*!< 0x000000A0 RxMessage buffer control/command */
   __IM uint32_t RESERVED1[88];
  __IOM uint32_t CNTL;                          /*!< 0x00000400 Control */
  __IOM uint32_t TTCAN_COUNTER;                 /*!< 0x00000404 TTCAN Level1 16-Bit local time counter */
  __IOM uint32_t TTCAN_COMPARE;                 /*!< 0x00000408 TTCAN Level1 compare configuration */
   __IM uint32_t TTCAN_CAPTURE;                 /*!< 0x0000040C TTCAN Level1 capture configuration */
  __IOM uint32_t TTCAN_TIMING;                  /*!< 0x00000410 TTCAN Level1 timing configuration, duplicate of CONFIG fields */
  __IOM uint32_t INTR_CAN;                      /*!< 0x00000414 CAN Interrupt Cause (TTCAN + INT_STATUS Or) */
  __IOM uint32_t INTR_CAN_SET;                  /*!< 0x00000418 CAN Interrupt Set (TTCAN + INT_STATUS Or) */
  __IOM uint32_t INTR_CAN_MASK;                 /*!< 0x0000041C CAN Interrupt Mask (TTCAN + INT_STATUS Or) */
   __IM uint32_t INTR_CAN_MASKED;               /*!< 0x00000420 Can Interrupt Masked (TTCAN + INT_STATUS Or) */
} CAN_Type;                                     /*!< Size = 1060 (0x424) */


/* CAN_TX.CONTROL */
#define CAN_TX_CONTROL_TX_REQ_Pos               0UL
#define CAN_TX_CONTROL_TX_REQ_Msk               0x1UL
#define CAN_TX_CONTROL_TX_ABORT_Pos             1UL
#define CAN_TX_CONTROL_TX_ABORT_Msk             0x2UL
#define CAN_TX_CONTROL_TX_INT_EBL_Pos           2UL
#define CAN_TX_CONTROL_TX_INT_EBL_Msk           0x4UL
#define CAN_TX_CONTROL_WPNL_Pos                 3UL
#define CAN_TX_CONTROL_WPNL_Msk                 0x8UL
#define CAN_TX_CONTROL_DLC_Pos                  16UL
#define CAN_TX_CONTROL_DLC_Msk                  0xF0000UL
#define CAN_TX_CONTROL_IDE_Pos                  20UL
#define CAN_TX_CONTROL_IDE_Msk                  0x100000UL
#define CAN_TX_CONTROL_RTR_Pos                  21UL
#define CAN_TX_CONTROL_RTR_Msk                  0x200000UL
#define CAN_TX_CONTROL_WPNH_Pos                 23UL
#define CAN_TX_CONTROL_WPNH_Msk                 0x800000UL
/* CAN_TX.ID */
#define CAN_TX_ID_ID_Pos                        3UL
#define CAN_TX_ID_ID_Msk                        0xFFFFFFF8UL
/* CAN_TX.DATA_HIGH */
#define CAN_TX_DATA_HIGH_DATA_Pos               0UL
#define CAN_TX_DATA_HIGH_DATA_Msk               0xFFFFFFFFUL
/* CAN_TX.DATA_LOW */
#define CAN_TX_DATA_LOW_DATA_Pos                0UL
#define CAN_TX_DATA_LOW_DATA_Msk                0xFFFFFFFFUL


/* CAN_RX.CONTROL */
#define CAN_RX_CONTROL_MSG_AV_RTRSENT_Pos       0UL
#define CAN_RX_CONTROL_MSG_AV_RTRSENT_Msk       0x1UL
#define CAN_RX_CONTROL_RTR_REPLY_PEND_Pos       1UL
#define CAN_RX_CONTROL_RTR_REPLY_PEND_Msk       0x2UL
#define CAN_RX_CONTROL_RTR_ABORT_Pos            2UL
#define CAN_RX_CONTROL_RTR_ABORT_Msk            0x4UL
#define CAN_RX_CONTROL_BUFFER_EN_Pos            3UL
#define CAN_RX_CONTROL_BUFFER_EN_Msk            0x8UL
#define CAN_RX_CONTROL_RTR_REPLY_Pos            4UL
#define CAN_RX_CONTROL_RTR_REPLY_Msk            0x10UL
#define CAN_RX_CONTROL_RX_INT_EBL_Pos           5UL
#define CAN_RX_CONTROL_RX_INT_EBL_Msk           0x20UL
#define CAN_RX_CONTROL_LINK_FLAG_Pos            6UL
#define CAN_RX_CONTROL_LINK_FLAG_Msk            0x40UL
#define CAN_RX_CONTROL_WPNL_Pos                 7UL
#define CAN_RX_CONTROL_WPNL_Msk                 0x80UL
#define CAN_RX_CONTROL_DLC_Pos                  16UL
#define CAN_RX_CONTROL_DLC_Msk                  0xF0000UL
#define CAN_RX_CONTROL_IDE_FMT_Pos              20UL
#define CAN_RX_CONTROL_IDE_FMT_Msk              0x100000UL
#define CAN_RX_CONTROL_RTR_MSG_Pos              21UL
#define CAN_RX_CONTROL_RTR_MSG_Msk              0x200000UL
#define CAN_RX_CONTROL_WPNH_Pos                 23UL
#define CAN_RX_CONTROL_WPNH_Msk                 0x800000UL
/* CAN_RX.ID */
#define CAN_RX_ID_ID_Pos                        3UL
#define CAN_RX_ID_ID_Msk                        0xFFFFFFF8UL
/* CAN_RX.DATA_HIGH */
#define CAN_RX_DATA_HIGH_DATA_Pos               0UL
#define CAN_RX_DATA_HIGH_DATA_Msk               0xFFFFFFFFUL
/* CAN_RX.DATA_LOW */
#define CAN_RX_DATA_LOW_DATA_Pos                0UL
#define CAN_RX_DATA_LOW_DATA_Msk                0xFFFFFFFFUL
/* CAN_RX.AMR */
#define CAN_RX_AMR_RTR_Pos                      1UL
#define CAN_RX_AMR_RTR_Msk                      0x2UL
#define CAN_RX_AMR_IDE_Pos                      2UL
#define CAN_RX_AMR_IDE_Msk                      0x4UL
#define CAN_RX_AMR_ID_Pos                       3UL
#define CAN_RX_AMR_ID_Msk                       0xFFFFFFF8UL
/* CAN_RX.ACR */
#define CAN_RX_ACR_RTR_Pos                      1UL
#define CAN_RX_ACR_RTR_Msk                      0x2UL
#define CAN_RX_ACR_IDE_Pos                      2UL
#define CAN_RX_ACR_IDE_Msk                      0x4UL
#define CAN_RX_ACR_ID_Pos                       3UL
#define CAN_RX_ACR_ID_Msk                       0xFFFFFFF8UL
/* CAN_RX.AMR_DATA */
#define CAN_RX_AMR_DATA_DATAL_Pos               0UL
#define CAN_RX_AMR_DATA_DATAL_Msk               0xFFFFUL
/* CAN_RX.ACR_DATA */
#define CAN_RX_ACR_DATA_DATAL_Pos               0UL
#define CAN_RX_ACR_DATA_DATAL_Msk               0xFFFFUL


/* CAN.INT_STATUS */
#define CAN_INT_STATUS_ARB_LOSS_Pos             2UL
#define CAN_INT_STATUS_ARB_LOSS_Msk             0x4UL
#define CAN_INT_STATUS_OVR_LOAD_Pos             3UL
#define CAN_INT_STATUS_OVR_LOAD_Msk             0x8UL
#define CAN_INT_STATUS_BIT_ERR_Pos              4UL
#define CAN_INT_STATUS_BIT_ERR_Msk              0x10UL
#define CAN_INT_STATUS_STUFF_ERR_Pos            5UL
#define CAN_INT_STATUS_STUFF_ERR_Msk            0x20UL
#define CAN_INT_STATUS_ACK_ERR_Pos              6UL
#define CAN_INT_STATUS_ACK_ERR_Msk              0x40UL
#define CAN_INT_STATUS_FORM_ERR_Pos             7UL
#define CAN_INT_STATUS_FORM_ERR_Msk             0x80UL
#define CAN_INT_STATUS_CRC_ERR_Pos              8UL
#define CAN_INT_STATUS_CRC_ERR_Msk              0x100UL
#define CAN_INT_STATUS_BUS_OFF_Pos              9UL
#define CAN_INT_STATUS_BUS_OFF_Msk              0x200UL
#define CAN_INT_STATUS_RX_MSG_LOSS_Pos          10UL
#define CAN_INT_STATUS_RX_MSG_LOSS_Msk          0x400UL
#define CAN_INT_STATUS_TX_MSG_Pos               11UL
#define CAN_INT_STATUS_TX_MSG_Msk               0x800UL
#define CAN_INT_STATUS_RX_MSG_Pos               12UL
#define CAN_INT_STATUS_RX_MSG_Msk               0x1000UL
#define CAN_INT_STATUS_RTR_MSG_Pos              13UL
#define CAN_INT_STATUS_RTR_MSG_Msk              0x2000UL
#define CAN_INT_STATUS_STUCK_AT_0_Pos           14UL
#define CAN_INT_STATUS_STUCK_AT_0_Msk           0x4000UL
#define CAN_INT_STATUS_SST_FAILURE_Pos          15UL
#define CAN_INT_STATUS_SST_FAILURE_Msk          0x8000UL
/* CAN.INT_EBL */
#define CAN_INT_EBL_GLOBAL_INT_ENBL_Pos         0UL
#define CAN_INT_EBL_GLOBAL_INT_ENBL_Msk         0x1UL
#define CAN_INT_EBL_ARB_LOSS_ENBL_Pos           2UL
#define CAN_INT_EBL_ARB_LOSS_ENBL_Msk           0x4UL
#define CAN_INT_EBL_OVR_LOAD_ENBL_Pos           3UL
#define CAN_INT_EBL_OVR_LOAD_ENBL_Msk           0x8UL
#define CAN_INT_EBL_BIT_ERR_ENBL_Pos            4UL
#define CAN_INT_EBL_BIT_ERR_ENBL_Msk            0x10UL
#define CAN_INT_EBL_STUFF_ERR_ENBL_Pos          5UL
#define CAN_INT_EBL_STUFF_ERR_ENBL_Msk          0x20UL
#define CAN_INT_EBL_ACK_ERR_ENBL_Pos            6UL
#define CAN_INT_EBL_ACK_ERR_ENBL_Msk            0x40UL
#define CAN_INT_EBL_FORM_ERR_ENBL_Pos           7UL
#define CAN_INT_EBL_FORM_ERR_ENBL_Msk           0x80UL
#define CAN_INT_EBL_CRC_ERR_ENBL_Pos            8UL
#define CAN_INT_EBL_CRC_ERR_ENBL_Msk            0x100UL
#define CAN_INT_EBL_BUS_OFF_ENBL_Pos            9UL
#define CAN_INT_EBL_BUS_OFF_ENBL_Msk            0x200UL
#define CAN_INT_EBL_RX_MSG_LOSS_Pos             10UL
#define CAN_INT_EBL_RX_MSG_LOSS_Msk             0x400UL
#define CAN_INT_EBL_TX_MSG_ENBL_Pos             11UL
#define CAN_INT_EBL_TX_MSG_ENBL_Msk             0x800UL
#define CAN_INT_EBL_RX_MSG_ENBL_Pos             12UL
#define CAN_INT_EBL_RX_MSG_ENBL_Msk             0x1000UL
#define CAN_INT_EBL_RTR_MSG_ENBL_Pos            13UL
#define CAN_INT_EBL_RTR_MSG_ENBL_Msk            0x2000UL
#define CAN_INT_EBL_STUCK_AT_0_ENBL_Pos         14UL
#define CAN_INT_EBL_STUCK_AT_0_ENBL_Msk         0x4000UL
#define CAN_INT_EBL_SST_FAILURE_ENBL_Pos        15UL
#define CAN_INT_EBL_SST_FAILURE_ENBL_Msk        0x8000UL
/* CAN.BUFFER_STATUS */
#define CAN_BUFFER_STATUS_RX0_MSG_AV_Pos        0UL
#define CAN_BUFFER_STATUS_RX0_MSG_AV_Msk        0x1UL
#define CAN_BUFFER_STATUS_RX1_MSG_AV_Pos        1UL
#define CAN_BUFFER_STATUS_RX1_MSG_AV_Msk        0x2UL
#define CAN_BUFFER_STATUS_RX2_MSG_AV_Pos        2UL
#define CAN_BUFFER_STATUS_RX2_MSG_AV_Msk        0x4UL
#define CAN_BUFFER_STATUS_RX3_MSG_AV_Pos        3UL
#define CAN_BUFFER_STATUS_RX3_MSG_AV_Msk        0x8UL
#define CAN_BUFFER_STATUS_RX4_MSG_AV_Pos        4UL
#define CAN_BUFFER_STATUS_RX4_MSG_AV_Msk        0x10UL
#define CAN_BUFFER_STATUS_RX5_MSG_AV_Pos        5UL
#define CAN_BUFFER_STATUS_RX5_MSG_AV_Msk        0x20UL
#define CAN_BUFFER_STATUS_RX6_MSG_AV_Pos        6UL
#define CAN_BUFFER_STATUS_RX6_MSG_AV_Msk        0x40UL
#define CAN_BUFFER_STATUS_RX7_MSG_AV_Pos        7UL
#define CAN_BUFFER_STATUS_RX7_MSG_AV_Msk        0x80UL
#define CAN_BUFFER_STATUS_RX8_MSG_AV_Pos        8UL
#define CAN_BUFFER_STATUS_RX8_MSG_AV_Msk        0x100UL
#define CAN_BUFFER_STATUS_RX9_MSG_AV_Pos        9UL
#define CAN_BUFFER_STATUS_RX9_MSG_AV_Msk        0x200UL
#define CAN_BUFFER_STATUS_RX10_MSG_AV_Pos       10UL
#define CAN_BUFFER_STATUS_RX10_MSG_AV_Msk       0x400UL
#define CAN_BUFFER_STATUS_RX11_MSG_AV_Pos       11UL
#define CAN_BUFFER_STATUS_RX11_MSG_AV_Msk       0x800UL
#define CAN_BUFFER_STATUS_RX12_MSG_AV_Pos       12UL
#define CAN_BUFFER_STATUS_RX12_MSG_AV_Msk       0x1000UL
#define CAN_BUFFER_STATUS_RX13_MSG_AV_Pos       13UL
#define CAN_BUFFER_STATUS_RX13_MSG_AV_Msk       0x2000UL
#define CAN_BUFFER_STATUS_RX14_MSG_AV_Pos       14UL
#define CAN_BUFFER_STATUS_RX14_MSG_AV_Msk       0x4000UL
#define CAN_BUFFER_STATUS_RX15_MSG_AV_Pos       15UL
#define CAN_BUFFER_STATUS_RX15_MSG_AV_Msk       0x8000UL
#define CAN_BUFFER_STATUS_TX0_REQ_PEND_Pos      16UL
#define CAN_BUFFER_STATUS_TX0_REQ_PEND_Msk      0x10000UL
#define CAN_BUFFER_STATUS_TX1_REQ_PEND_Pos      17UL
#define CAN_BUFFER_STATUS_TX1_REQ_PEND_Msk      0x20000UL
#define CAN_BUFFER_STATUS_TX2_REQ_PEND_Pos      18UL
#define CAN_BUFFER_STATUS_TX2_REQ_PEND_Msk      0x40000UL
#define CAN_BUFFER_STATUS_TX3_REQ_PEND_Pos      19UL
#define CAN_BUFFER_STATUS_TX3_REQ_PEND_Msk      0x80000UL
#define CAN_BUFFER_STATUS_TX4_REQ_PEND_Pos      20UL
#define CAN_BUFFER_STATUS_TX4_REQ_PEND_Msk      0x100000UL
#define CAN_BUFFER_STATUS_TX5_REQ_PEND_Pos      21UL
#define CAN_BUFFER_STATUS_TX5_REQ_PEND_Msk      0x200000UL
#define CAN_BUFFER_STATUS_TX6_REQ_PEND_Pos      22UL
#define CAN_BUFFER_STATUS_TX6_REQ_PEND_Msk      0x400000UL
#define CAN_BUFFER_STATUS_TX7_REQ_PEND_Pos      23UL
#define CAN_BUFFER_STATUS_TX7_REQ_PEND_Msk      0x800000UL
/* CAN.ERROR_STATUS */
#define CAN_ERROR_STATUS_TX_ERR_CNT_Pos         0UL
#define CAN_ERROR_STATUS_TX_ERR_CNT_Msk         0xFFUL
#define CAN_ERROR_STATUS_RX_ERR_CNT_Pos         8UL
#define CAN_ERROR_STATUS_RX_ERR_CNT_Msk         0xFF00UL
#define CAN_ERROR_STATUS_ERROR_STATE_Pos        16UL
#define CAN_ERROR_STATUS_ERROR_STATE_Msk        0x30000UL
#define CAN_ERROR_STATUS_TXGTE96_Pos            18UL
#define CAN_ERROR_STATUS_TXGTE96_Msk            0x40000UL
#define CAN_ERROR_STATUS_RXGTE96_Pos            19UL
#define CAN_ERROR_STATUS_RXGTE96_Msk            0x80000UL
/* CAN.COMMAND */
#define CAN_COMMAND_RUN_Pos                     0UL
#define CAN_COMMAND_RUN_Msk                     0x1UL
#define CAN_COMMAND_LISTEN_Pos                  1UL
#define CAN_COMMAND_LISTEN_Msk                  0x2UL
#define CAN_COMMAND_LOOPBACK_TEST_Pos           2UL
#define CAN_COMMAND_LOOPBACK_TEST_Msk           0x4UL
#define CAN_COMMAND_SRAM_TEST_Pos               3UL
#define CAN_COMMAND_SRAM_TEST_Msk               0x8UL
#define CAN_COMMAND_IP_REV_NUMBER_Pos           16UL
#define CAN_COMMAND_IP_REV_NUMBER_Msk           0xFF0000UL
#define CAN_COMMAND_IP_MINOR_VERSION_Pos        24UL
#define CAN_COMMAND_IP_MINOR_VERSION_Msk        0xF000000UL
#define CAN_COMMAND_IP_MAJOR_VERSION_Pos        28UL
#define CAN_COMMAND_IP_MAJOR_VERSION_Msk        0xF0000000UL
/* CAN.CONFIG */
#define CAN_CONFIG_EDGE_MODE_Pos                0UL
#define CAN_CONFIG_EDGE_MODE_Msk                0x1UL
#define CAN_CONFIG_SAMPLING_MODE_Pos            1UL
#define CAN_CONFIG_SAMPLING_MODE_Msk            0x2UL
#define CAN_CONFIG_CFG_SJW_Pos                  2UL
#define CAN_CONFIG_CFG_SJW_Msk                  0xCUL
#define CAN_CONFIG_AUTO_RESTART_Pos             4UL
#define CAN_CONFIG_AUTO_RESTART_Msk             0x10UL
#define CAN_CONFIG_CFG_TSEG2_Pos                5UL
#define CAN_CONFIG_CFG_TSEG2_Msk                0xE0UL
#define CAN_CONFIG_CFG_TSEG1_Pos                8UL
#define CAN_CONFIG_CFG_TSEG1_Msk                0xF00UL
#define CAN_CONFIG_CFG_ARBITER_Pos              12UL
#define CAN_CONFIG_CFG_ARBITER_Msk              0x1000UL
#define CAN_CONFIG_SWAP_ENDIAN_Pos              13UL
#define CAN_CONFIG_SWAP_ENDIAN_Msk              0x2000UL
#define CAN_CONFIG_ECR_MODE_Pos                 14UL
#define CAN_CONFIG_ECR_MODE_Msk                 0x4000UL
#define CAN_CONFIG_CFG_BITRATE_Pos              16UL
#define CAN_CONFIG_CFG_BITRATE_Msk              0x7FFF0000UL
/* CAN.ECR */
#define CAN_ECR_ECR_STATUS_Pos                  0UL
#define CAN_ECR_ECR_STATUS_Msk                  0x1UL
#define CAN_ECR_ERROR_TYPE_Pos                  1UL
#define CAN_ECR_ERROR_TYPE_Msk                  0xEUL
#define CAN_ECR_RX_MODE_Pos                     4UL
#define CAN_ECR_RX_MODE_Msk                     0x10UL
#define CAN_ECR_TX_MODE_Pos                     5UL
#define CAN_ECR_TX_MODE_Msk                     0x20UL
#define CAN_ECR_BIT_Pos                         6UL
#define CAN_ECR_BIT_Msk                         0xFC0UL
#define CAN_ECR_FIELD_Pos                       12UL
#define CAN_ECR_FIELD_Msk                       0x1F000UL
/* CAN.CNTL */
#define CAN_CNTL_TT_ENABLE_Pos                  0UL
#define CAN_CNTL_TT_ENABLE_Msk                  0x1UL
#define CAN_CNTL_IP_ENABLE_Pos                  31UL
#define CAN_CNTL_IP_ENABLE_Msk                  0x80000000UL
/* CAN.TTCAN_COUNTER */
#define CAN_TTCAN_COUNTER_LOCAL_TIME_Pos        16UL
#define CAN_TTCAN_COUNTER_LOCAL_TIME_Msk        0xFFFF0000UL
/* CAN.TTCAN_COMPARE */
#define CAN_TTCAN_COMPARE_TIME_MARK_Pos         16UL
#define CAN_TTCAN_COMPARE_TIME_MARK_Msk         0xFFFF0000UL
/* CAN.TTCAN_CAPTURE */
#define CAN_TTCAN_CAPTURE_SYNC_MARK_Pos         16UL
#define CAN_TTCAN_CAPTURE_SYNC_MARK_Msk         0xFFFF0000UL
/* CAN.TTCAN_TIMING */
#define CAN_TTCAN_TIMING_SAMPLING_MODE_Pos      1UL
#define CAN_TTCAN_TIMING_SAMPLING_MODE_Msk      0x2UL
#define CAN_TTCAN_TIMING_CFG_TSEG2_Pos          5UL
#define CAN_TTCAN_TIMING_CFG_TSEG2_Msk          0xE0UL
#define CAN_TTCAN_TIMING_CFG_TSEG1_Pos          8UL
#define CAN_TTCAN_TIMING_CFG_TSEG1_Msk          0xF00UL
#define CAN_TTCAN_TIMING_CFG_BITRATE_Pos        16UL
#define CAN_TTCAN_TIMING_CFG_BITRATE_Msk        0x7FFF0000UL
/* CAN.INTR_CAN */
#define CAN_INTR_CAN_INT_STATUS_Pos             0UL
#define CAN_INTR_CAN_INT_STATUS_Msk             0x1UL
#define CAN_INTR_CAN_TT_COMPARE_Pos             1UL
#define CAN_INTR_CAN_TT_COMPARE_Msk             0x2UL
#define CAN_INTR_CAN_TT_CAPTURE_Pos             2UL
#define CAN_INTR_CAN_TT_CAPTURE_Msk             0x4UL
/* CAN.INTR_CAN_SET */
#define CAN_INTR_CAN_SET_INT_STATUS_Pos         0UL
#define CAN_INTR_CAN_SET_INT_STATUS_Msk         0x1UL
#define CAN_INTR_CAN_SET_TT_COMPARE_Pos         1UL
#define CAN_INTR_CAN_SET_TT_COMPARE_Msk         0x2UL
#define CAN_INTR_CAN_SET_TT_CAPTURE_Pos         2UL
#define CAN_INTR_CAN_SET_TT_CAPTURE_Msk         0x4UL
/* CAN.INTR_CAN_MASK */
#define CAN_INTR_CAN_MASK_INT_STATUS_Pos        0UL
#define CAN_INTR_CAN_MASK_INT_STATUS_Msk        0x1UL
#define CAN_INTR_CAN_MASK_TT_COMPARE_Pos        1UL
#define CAN_INTR_CAN_MASK_TT_COMPARE_Msk        0x2UL
#define CAN_INTR_CAN_MASK_TT_CAPTURE_Pos        2UL
#define CAN_INTR_CAN_MASK_TT_CAPTURE_Msk        0x4UL
/* CAN.INTR_CAN_MASKED */
#define CAN_INTR_CAN_MASKED_INT_STATUS_Pos      0UL
#define CAN_INTR_CAN_MASKED_INT_STATUS_Msk      0x1UL
#define CAN_INTR_CAN_MASKED_TT_COMPARE_Pos      1UL
#define CAN_INTR_CAN_MASKED_TT_COMPARE_Msk      0x2UL
#define CAN_INTR_CAN_MASKED_TT_CAPTURE_Pos      2UL
#define CAN_INTR_CAN_MASKED_TT_CAPTURE_Msk      0x4UL


#endif /* _CYIP_CAN_H_ */


/* [] END OF FILE */
