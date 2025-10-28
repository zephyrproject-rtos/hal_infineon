/***************************************************************************//**
* \file cyip_crypto_v2.h
*
* \brief
* CRYPTO IP definitions
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

#ifndef _CYIP_CRYPTO_V2_H_
#define _CYIP_CRYPTO_V2_H_

#include "cyip_headers.h"

/*******************************************************************************
*                                    CRYPTO
*******************************************************************************/

#define CRYPTO_SECTION_SIZE                     0x00010000UL

/**
  * \brief Cryptography component (CRYPTO)
  */
typedef struct {
  __IOM uint32_t CTL;                           /*!< 0x00000000 Control */
   __IM uint32_t STATUS;                        /*!< 0x00000004 Status */
  __IOM uint32_t CMD;                           /*!< 0x00000008 Command */
   __IM uint32_t RESERVED;
  __IOM uint32_t SRC_CTL0;                      /*!< 0x00000010 Source control 0 */
  __IOM uint32_t SRC_CTL1;                      /*!< 0x00000014 Source control 1 */
   __IM uint32_t RESERVED1[2];
  __IOM uint32_t DST_CTL0;                      /*!< 0x00000020 Destination control 0 */
  __IOM uint32_t DST_CTL1;                      /*!< 0x00000024 Destination control 1 */
   __IM uint32_t RESERVED2[54];
  __IOM uint32_t AES_CTL;                       /*!< 0x00000100 AES control */
   __IM uint32_t RESERVED3[63];
  __IOM uint32_t PR_CTL;                        /*!< 0x00000200 Pseudo random control */
   __IM uint32_t RESERVED4;
  __IOM uint32_t PR_CMD;                        /*!< 0x00000208 Pseudo random command */
   __IM uint32_t RESERVED5;
  __IOM uint32_t PR_LFSR_CTL0;                  /*!< 0x00000210 Pseudo random LFSR control 0 */
  __IOM uint32_t PR_LFSR_CTL1;                  /*!< 0x00000214 Pseudo random LFSR control 1 */
  __IOM uint32_t PR_LFSR_CTL2;                  /*!< 0x00000218 Pseudo random LFSR control 2 */
   __IM uint32_t RESERVED6;
  __IOM uint32_t PR_RESULT;                     /*!< 0x00000220 Pseudo random status */
   __IM uint32_t RESERVED7[23];
  __IOM uint32_t TR_CTL0;                       /*!< 0x00000280 True random control 0 */
  __IOM uint32_t TR_CTL1;                       /*!< 0x00000284 True random control 1 */
  __IOM uint32_t TR_RESULT0;                    /*!< 0x00000288 True random result 0 */
  __IOM uint32_t TR_RESULT1;                    /*!< 0x0000028C True random result 1 */
  __IOM uint32_t TR_CMD;                        /*!< 0x00000290 True random command */
   __IM uint32_t RESERVED8[3];
  __IOM uint32_t TR_GARO_CTL;                   /*!< 0x000002A0 True random GARO control */
  __IOM uint32_t TR_FIRO_CTL;                   /*!< 0x000002A4 True random FIRO control */
   __IM uint32_t RESERVED9[6];
  __IOM uint32_t TR_MON_CTL;                    /*!< 0x000002C0 True random monitor control */
   __IM uint32_t RESERVED10;
  __IOM uint32_t TR_MON_CMD;                    /*!< 0x000002C8 True random monitor command */
   __IM uint32_t RESERVED11;
  __IOM uint32_t TR_MON_RC_CTL;                 /*!< 0x000002D0 True random monitor RC control */
   __IM uint32_t RESERVED12;
   __IM uint32_t TR_MON_RC_STATUS0;             /*!< 0x000002D8 True random monitor RC status 0 */
   __IM uint32_t TR_MON_RC_STATUS1;             /*!< 0x000002DC True random monitor RC status 1 */
  __IOM uint32_t TR_MON_AP_CTL;                 /*!< 0x000002E0 True random monitor AP control */
   __IM uint32_t RESERVED13;
   __IM uint32_t TR_MON_AP_STATUS0;             /*!< 0x000002E8 True random monitor AP status 0 */
   __IM uint32_t TR_MON_AP_STATUS1;             /*!< 0x000002EC True random monitor AP status 1 */
   __IM uint32_t RESERVED14[4];
  __IOM uint32_t SHA_CTL;                       /*!< 0x00000300 SHA control */
   __IM uint32_t RESERVED15[63];
  __IOM uint32_t CRC_DATA_CTL0;                 /*!< 0x00000400 CRC data control 0 */
  __IOM uint32_t CRC_DATA_CTL1;                 /*!< 0x00000404 CRC data control 1 */
   __IM uint32_t RESERVED16[2];
  __IOM uint32_t CRC_POL_CTL;                   /*!< 0x00000410 CRC polynomial control */
  __IOM uint32_t CRC_LFSR_CTL;                  /*!< 0x00000414 CRC LFSR control */
   __IM uint32_t RESERVED17[2];
  __IOM uint32_t CRC_REM_CTL0;                  /*!< 0x00000420 CRC remainder control 0 */
  __IOM uint32_t CRC_REM_CTL1;                  /*!< 0x00000424 CRC remainder control 1 */
   __IM uint32_t CRC_REM;                       /*!< 0x00000428 CRC remainder status */
   __IM uint32_t RESERVED18[229];
  __IOM uint32_t INTR;                          /*!< 0x000007C0 Interrupt request */
  __IOM uint32_t INTR_SET;                      /*!< 0x000007C4 Interrupt set request */
  __IOM uint32_t INTR_MASK;                     /*!< 0x000007C8 Interrupt mask */
   __IM uint32_t INTR_MASKED;                   /*!< 0x000007CC Interrupt masked */
   __IM uint32_t RESERVED19[12];
  __IOM uint32_t MEM_BUFF[512];                 /*!< 0x00000800 Memory buffer */
   __IM uint32_t RESERVED20[15296];
  __IOM uint32_t PRIV_BUF;                      /*!< 0x0000FF00 Buffer Privilege register */
} CRYPTO_Type;                                  /*!< Size = 65284 (0xFF04) */


/* CRYPTO.CTL */
#define CRYPTO_CTL_OPCODE_Pos                   0UL
#define CRYPTO_CTL_OPCODE_Msk                   0x1FUL
#define CRYPTO_CTL_ENABLED_Pos                  31UL
#define CRYPTO_CTL_ENABLED_Msk                  0x80000000UL
/* CRYPTO.STATUS */
#define CRYPTO_STATUS_BUSY_Pos                  0UL
#define CRYPTO_STATUS_BUSY_Msk                  0x1UL
/* CRYPTO.CMD */
#define CRYPTO_CMD_START_Pos                    0UL
#define CRYPTO_CMD_START_Msk                    0x1UL
/* CRYPTO.SRC_CTL0 */
#define CRYPTO_SRC_CTL0_OFFSET_Pos              2UL
#define CRYPTO_SRC_CTL0_OFFSET_Msk              0x7FCUL
/* CRYPTO.SRC_CTL1 */
#define CRYPTO_SRC_CTL1_OFFSET_Pos              2UL
#define CRYPTO_SRC_CTL1_OFFSET_Msk              0x7FCUL
/* CRYPTO.DST_CTL0 */
#define CRYPTO_DST_CTL0_OFFSET_Pos              2UL
#define CRYPTO_DST_CTL0_OFFSET_Msk              0x7FCUL
/* CRYPTO.DST_CTL1 */
#define CRYPTO_DST_CTL1_OFFSET_Pos              2UL
#define CRYPTO_DST_CTL1_OFFSET_Msk              0x7FCUL
/* CRYPTO.AES_CTL */
#define CRYPTO_AES_CTL_KEY_SIZE_Pos             0UL
#define CRYPTO_AES_CTL_KEY_SIZE_Msk             0x3UL
/* CRYPTO.PR_CTL */
#define CRYPTO_PR_CTL_MAX_Pos                   0UL
#define CRYPTO_PR_CTL_MAX_Msk                   0xFFFFFFFFUL
/* CRYPTO.PR_CMD */
#define CRYPTO_PR_CMD_START_Pos                 0UL
#define CRYPTO_PR_CMD_START_Msk                 0x1UL
/* CRYPTO.PR_LFSR_CTL0 */
#define CRYPTO_PR_LFSR_CTL0_LFSR32_Pos          0UL
#define CRYPTO_PR_LFSR_CTL0_LFSR32_Msk          0xFFFFFFFFUL
/* CRYPTO.PR_LFSR_CTL1 */
#define CRYPTO_PR_LFSR_CTL1_LFSR31_Pos          0UL
#define CRYPTO_PR_LFSR_CTL1_LFSR31_Msk          0x7FFFFFFFUL
/* CRYPTO.PR_LFSR_CTL2 */
#define CRYPTO_PR_LFSR_CTL2_LFSR29_Pos          0UL
#define CRYPTO_PR_LFSR_CTL2_LFSR29_Msk          0x1FFFFFFFUL
/* CRYPTO.PR_RESULT */
#define CRYPTO_PR_RESULT_DATA32_Pos             0UL
#define CRYPTO_PR_RESULT_DATA32_Msk             0xFFFFFFFFUL
/* CRYPTO.TR_CTL0 */
#define CRYPTO_TR_CTL0_SAMPLE_CLOCK_DIV_Pos     0UL
#define CRYPTO_TR_CTL0_SAMPLE_CLOCK_DIV_Msk     0xFFUL
#define CRYPTO_TR_CTL0_RED_CLOCK_DIV_Pos        8UL
#define CRYPTO_TR_CTL0_RED_CLOCK_DIV_Msk        0xFF00UL
#define CRYPTO_TR_CTL0_INIT_DELAY_Pos           16UL
#define CRYPTO_TR_CTL0_INIT_DELAY_Msk           0xFF0000UL
#define CRYPTO_TR_CTL0_VON_NEUMANN_CORR_Pos     24UL
#define CRYPTO_TR_CTL0_VON_NEUMANN_CORR_Msk     0x1000000UL
#define CRYPTO_TR_CTL0_STOP_ON_AP_DETECT_Pos    28UL
#define CRYPTO_TR_CTL0_STOP_ON_AP_DETECT_Msk    0x10000000UL
#define CRYPTO_TR_CTL0_STOP_ON_RC_DETECT_Pos    29UL
#define CRYPTO_TR_CTL0_STOP_ON_RC_DETECT_Msk    0x20000000UL
/* CRYPTO.TR_CTL1 */
#define CRYPTO_TR_CTL1_DATA_BIT_SIZE_Pos        0UL
#define CRYPTO_TR_CTL1_DATA_BIT_SIZE_Msk        0x3FUL
/* CRYPTO.TR_RESULT0 */
#define CRYPTO_TR_RESULT0_DATA32_Pos            0UL
#define CRYPTO_TR_RESULT0_DATA32_Msk            0xFFFFFFFFUL
/* CRYPTO.TR_RESULT1 */
#define CRYPTO_TR_RESULT1_DATA_BIT_SIZE_Pos     0UL
#define CRYPTO_TR_RESULT1_DATA_BIT_SIZE_Msk     0x3FUL
/* CRYPTO.TR_CMD */
#define CRYPTO_TR_CMD_START_RO11_Pos            0UL
#define CRYPTO_TR_CMD_START_RO11_Msk            0x1UL
#define CRYPTO_TR_CMD_START_RO15_Pos            1UL
#define CRYPTO_TR_CMD_START_RO15_Msk            0x2UL
#define CRYPTO_TR_CMD_START_GARO15_Pos          2UL
#define CRYPTO_TR_CMD_START_GARO15_Msk          0x4UL
#define CRYPTO_TR_CMD_START_GARO31_Pos          3UL
#define CRYPTO_TR_CMD_START_GARO31_Msk          0x8UL
#define CRYPTO_TR_CMD_START_FIRO15_Pos          4UL
#define CRYPTO_TR_CMD_START_FIRO15_Msk          0x10UL
#define CRYPTO_TR_CMD_START_FIRO31_Pos          5UL
#define CRYPTO_TR_CMD_START_FIRO31_Msk          0x20UL
/* CRYPTO.TR_GARO_CTL */
#define CRYPTO_TR_GARO_CTL_POLYNOMIAL31_Pos     0UL
#define CRYPTO_TR_GARO_CTL_POLYNOMIAL31_Msk     0x7FFFFFFFUL
/* CRYPTO.TR_FIRO_CTL */
#define CRYPTO_TR_FIRO_CTL_POLYNOMIAL31_Pos     0UL
#define CRYPTO_TR_FIRO_CTL_POLYNOMIAL31_Msk     0x7FFFFFFFUL
/* CRYPTO.TR_MON_CTL */
#define CRYPTO_TR_MON_CTL_BITSTREAM_SEL_Pos     0UL
#define CRYPTO_TR_MON_CTL_BITSTREAM_SEL_Msk     0x3UL
/* CRYPTO.TR_MON_CMD */
#define CRYPTO_TR_MON_CMD_START_AP_Pos          0UL
#define CRYPTO_TR_MON_CMD_START_AP_Msk          0x1UL
#define CRYPTO_TR_MON_CMD_START_RC_Pos          1UL
#define CRYPTO_TR_MON_CMD_START_RC_Msk          0x2UL
/* CRYPTO.TR_MON_RC_CTL */
#define CRYPTO_TR_MON_RC_CTL_CUTOFF_COUNT8_Pos  0UL
#define CRYPTO_TR_MON_RC_CTL_CUTOFF_COUNT8_Msk  0xFFUL
/* CRYPTO.TR_MON_RC_STATUS0 */
#define CRYPTO_TR_MON_RC_STATUS0_BIT_Pos        0UL
#define CRYPTO_TR_MON_RC_STATUS0_BIT_Msk        0x1UL
/* CRYPTO.TR_MON_RC_STATUS1 */
#define CRYPTO_TR_MON_RC_STATUS1_REP_COUNT_Pos  0UL
#define CRYPTO_TR_MON_RC_STATUS1_REP_COUNT_Msk  0xFFUL
/* CRYPTO.TR_MON_AP_CTL */
#define CRYPTO_TR_MON_AP_CTL_CUTOFF_COUNT16_Pos 0UL
#define CRYPTO_TR_MON_AP_CTL_CUTOFF_COUNT16_Msk 0xFFFFUL
#define CRYPTO_TR_MON_AP_CTL_WINDOW_SIZE_Pos    16UL
#define CRYPTO_TR_MON_AP_CTL_WINDOW_SIZE_Msk    0xFFFF0000UL
/* CRYPTO.TR_MON_AP_STATUS0 */
#define CRYPTO_TR_MON_AP_STATUS0_BIT_Pos        0UL
#define CRYPTO_TR_MON_AP_STATUS0_BIT_Msk        0x1UL
/* CRYPTO.TR_MON_AP_STATUS1 */
#define CRYPTO_TR_MON_AP_STATUS1_OCC_COUNT_Pos  0UL
#define CRYPTO_TR_MON_AP_STATUS1_OCC_COUNT_Msk  0xFFFFUL
#define CRYPTO_TR_MON_AP_STATUS1_WINDOW_INDEX_Pos 16UL
#define CRYPTO_TR_MON_AP_STATUS1_WINDOW_INDEX_Msk 0xFFFF0000UL
/* CRYPTO.SHA_CTL */
#define CRYPTO_SHA_CTL_MODE_Pos                 0UL
#define CRYPTO_SHA_CTL_MODE_Msk                 0x7UL
/* CRYPTO.CRC_DATA_CTL0 */
#define CRYPTO_CRC_DATA_CTL0_DATA_REVERSE_Pos   0UL
#define CRYPTO_CRC_DATA_CTL0_DATA_REVERSE_Msk   0x1UL
#define CRYPTO_CRC_DATA_CTL0_DATA_SIZE_Pos      16UL
#define CRYPTO_CRC_DATA_CTL0_DATA_SIZE_Msk      0x7FF0000UL
/* CRYPTO.CRC_DATA_CTL1 */
#define CRYPTO_CRC_DATA_CTL1_DATA_XOR_Pos       0UL
#define CRYPTO_CRC_DATA_CTL1_DATA_XOR_Msk       0xFFUL
/* CRYPTO.CRC_POL_CTL */
#define CRYPTO_CRC_POL_CTL_POLYNOMIAL_Pos       0UL
#define CRYPTO_CRC_POL_CTL_POLYNOMIAL_Msk       0xFFFFFFFFUL
/* CRYPTO.CRC_LFSR_CTL */
#define CRYPTO_CRC_LFSR_CTL_LFSR32_Pos          0UL
#define CRYPTO_CRC_LFSR_CTL_LFSR32_Msk          0xFFFFFFFFUL
/* CRYPTO.CRC_REM_CTL0 */
#define CRYPTO_CRC_REM_CTL0_REM_REVERSE_Pos     0UL
#define CRYPTO_CRC_REM_CTL0_REM_REVERSE_Msk     0x1UL
/* CRYPTO.CRC_REM_CTL1 */
#define CRYPTO_CRC_REM_CTL1_REM_XOR_Pos         0UL
#define CRYPTO_CRC_REM_CTL1_REM_XOR_Msk         0xFFFFFFFFUL
/* CRYPTO.CRC_REM */
#define CRYPTO_CRC_REM_REM_Pos                  0UL
#define CRYPTO_CRC_REM_REM_Msk                  0xFFFFFFFFUL
/* CRYPTO.INTR */
#define CRYPTO_INTR_DONE_Pos                    0UL
#define CRYPTO_INTR_DONE_Msk                    0x1UL
#define CRYPTO_INTR_ACCESS_ERROR_Pos            1UL
#define CRYPTO_INTR_ACCESS_ERROR_Msk            0x2UL
#define CRYPTO_INTR_TR_INITIALIZED_Pos          6UL
#define CRYPTO_INTR_TR_INITIALIZED_Msk          0x40UL
#define CRYPTO_INTR_TR_DATA_AVAILABLE_Pos       7UL
#define CRYPTO_INTR_TR_DATA_AVAILABLE_Msk       0x80UL
#define CRYPTO_INTR_TR_AP_DETECT_Pos            8UL
#define CRYPTO_INTR_TR_AP_DETECT_Msk            0x100UL
#define CRYPTO_INTR_TR_RC_DETECT_Pos            9UL
#define CRYPTO_INTR_TR_RC_DETECT_Msk            0x200UL
/* CRYPTO.INTR_SET */
#define CRYPTO_INTR_SET_DONE_Pos                0UL
#define CRYPTO_INTR_SET_DONE_Msk                0x1UL
#define CRYPTO_INTR_SET_ACCESS_ERROR_Pos        1UL
#define CRYPTO_INTR_SET_ACCESS_ERROR_Msk        0x2UL
#define CRYPTO_INTR_SET_TR_INITIALIZED_Pos      6UL
#define CRYPTO_INTR_SET_TR_INITIALIZED_Msk      0x40UL
#define CRYPTO_INTR_SET_TR_DATA_AVAILABLE_Pos   7UL
#define CRYPTO_INTR_SET_TR_DATA_AVAILABLE_Msk   0x80UL
#define CRYPTO_INTR_SET_TR_AP_DETECT_Pos        8UL
#define CRYPTO_INTR_SET_TR_AP_DETECT_Msk        0x100UL
#define CRYPTO_INTR_SET_TR_RC_DETECT_Pos        9UL
#define CRYPTO_INTR_SET_TR_RC_DETECT_Msk        0x200UL
/* CRYPTO.INTR_MASK */
#define CRYPTO_INTR_MASK_DONE_Pos               0UL
#define CRYPTO_INTR_MASK_DONE_Msk               0x1UL
#define CRYPTO_INTR_MASK_ACCESS_ERROR_Pos       1UL
#define CRYPTO_INTR_MASK_ACCESS_ERROR_Msk       0x2UL
#define CRYPTO_INTR_MASK_TR_INITIALIZED_Pos     6UL
#define CRYPTO_INTR_MASK_TR_INITIALIZED_Msk     0x40UL
#define CRYPTO_INTR_MASK_TR_DATA_AVAILABLE_Pos  7UL
#define CRYPTO_INTR_MASK_TR_DATA_AVAILABLE_Msk  0x80UL
#define CRYPTO_INTR_MASK_TR_AP_DETECT_Pos       8UL
#define CRYPTO_INTR_MASK_TR_AP_DETECT_Msk       0x100UL
#define CRYPTO_INTR_MASK_TR_RC_DETECT_Pos       9UL
#define CRYPTO_INTR_MASK_TR_RC_DETECT_Msk       0x200UL
/* CRYPTO.INTR_MASKED */
#define CRYPTO_INTR_MASKED_DONE_Pos             0UL
#define CRYPTO_INTR_MASKED_DONE_Msk             0x1UL
#define CRYPTO_INTR_MASKED_ACCESS_ERROR_Pos     1UL
#define CRYPTO_INTR_MASKED_ACCESS_ERROR_Msk     0x2UL
#define CRYPTO_INTR_MASKED_TR_INITIALIZED_Pos   6UL
#define CRYPTO_INTR_MASKED_TR_INITIALIZED_Msk   0x40UL
#define CRYPTO_INTR_MASKED_TR_DATA_AVAILABLE_Pos 7UL
#define CRYPTO_INTR_MASKED_TR_DATA_AVAILABLE_Msk 0x80UL
#define CRYPTO_INTR_MASKED_TR_AP_DETECT_Pos     8UL
#define CRYPTO_INTR_MASKED_TR_AP_DETECT_Msk     0x100UL
#define CRYPTO_INTR_MASKED_TR_RC_DETECT_Pos     9UL
#define CRYPTO_INTR_MASKED_TR_RC_DETECT_Msk     0x200UL
/* CRYPTO.MEM_BUFF */
#define CRYPTO_MEM_BUFF_DATA32_Pos              0UL
#define CRYPTO_MEM_BUFF_DATA32_Msk              0xFFFFFFFFUL
/* CRYPTO.PRIV_BUF */
#define CRYPTO_PRIV_BUF_BUF_PRIV_LIMIT_Pos      0UL
#define CRYPTO_PRIV_BUF_BUF_PRIV_LIMIT_Msk      0x7UL


#endif /* _CYIP_CRYPTO_V2_H_ */


/* [] END OF FILE */
