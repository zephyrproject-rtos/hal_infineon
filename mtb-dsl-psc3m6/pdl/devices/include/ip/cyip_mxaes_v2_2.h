/***************************************************************************//**
* MXAES IP definitions
*
********************************************************************************
* \copyright
* (c) 2016-2026, Infineon Technologies AG or an affiliate of
* Infineon Technologies AG.
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

#ifndef _CYIP_MXAES_V2_2_H_
#define _CYIP_MXAES_V2_2_H_

#include "cyip_headers.h"

/*******************************************************************************
*                                    MXAES
*******************************************************************************/

#define MXAES_UNMASKED_USER_RANGE_SECTION_SIZE  0x00000800UL
#define MXAES_MASKED_USER_RANGE_SECTION_SIZE    0x00000800UL
#define MXAES_SECTION_SIZE                      0x00002000UL

/**
  * \brief AES command and configuration registers (MXAES_UNMASKED_USER_RANGE)
  */
typedef struct {
  __IOM uint32_t CFG;                           /*!< 0x00000000 AES configuration register */
   __IM uint32_t RESERVED[2];
  __IOM uint32_t CMD;                           /*!< 0x0000000C AES command register */
   __IM uint32_t RESERVED1;
   __IM uint32_t STAT;                          /*!< 0x00000014 AES status register */
   __IM uint32_t RESERVED2[18];
  __IOM uint32_t CFG_2;                         /*!< 0x00000060 AES configuration register 2 */
   __IM uint32_t RESERVED3[7];
  __IOM uint32_t INTR;                          /*!< 0x00000080 AES interrupt cause register */
  __IOM uint32_t INTR_SET;                      /*!< 0x00000084 AES interrupt set register */
   __IM uint32_t RESERVED4;
  __IOM uint32_t INTR_MASK;                     /*!< 0x0000008C AES interrupt mask register */
   __IM uint32_t INTR_MASKED;                   /*!< 0x00000090 AES masked interrupt register */
   __IM uint32_t RESERVED5[11];
   __OM uint32_t CLEAR;                         /*!< 0x000000C0 AES clear register */
   __IM uint32_t RESERVED6[6];
  __IOM uint32_t BUS_COUNTER;                   /*!< 0x000000DC AES Bus counter register */
  __IOM uint32_t QCHAN_CTL;                     /*!< 0x000000E0 AES Q-channel control register */
   __IM uint32_t RESERVED7[455];
} MXAES_UNMASKED_USER_RANGE_Type;               /*!< Size = 2048 (0x800) */

/**
  * \brief AES data and key shares (MXAES_MASKED_USER_RANGE)
  */
typedef struct {
   __OM uint32_t SEED_U;                        /*!< 0x00000000 AES user seeding register */
   __IM uint32_t RESERVED[63];
   __OM uint32_t KEY_0_0;                       /*!< 0x00000100 AES share 0 word 0 key register */
   __IM uint32_t RESERVED1[2];
   __OM uint32_t KEY_0_1;                       /*!< 0x0000010C The key registers are write only and reads trigger a BusError.
                                                                When the module is busy (STAT.BSY = BSY) writes to the register
                                                                also trigger a BusError. */
   __IM uint32_t RESERVED2[2];
   __OM uint32_t KEY_0_2;                       /*!< 0x00000118 AES share 0 word 2 key register */
   __IM uint32_t RESERVED3[2];
   __OM uint32_t KEY_0_3;                       /*!< 0x00000124 AES share 0 word 3 key register */
   __IM uint32_t RESERVED4[2];
   __OM uint32_t KEY_0_4;                       /*!< 0x00000130 AES share 0 word 4 key register */
   __IM uint32_t RESERVED5[2];
   __OM uint32_t KEY_0_5;                       /*!< 0x0000013C AES share 0 word 5 key register */
   __IM uint32_t RESERVED6[2];
   __OM uint32_t KEY_0_6;                       /*!< 0x00000148 AES share 0 word 6 key register */
   __IM uint32_t RESERVED7[2];
   __OM uint32_t KEY_0_7;                       /*!< 0x00000154 AES share 0 word 7 key register */
   __IM uint32_t RESERVED8[2];
   __OM uint32_t KEY_1_0;                       /*!< 0x00000160 AES share 1 word 0 key register */
   __IM uint32_t RESERVED9[2];
   __OM uint32_t KEY_1_1;                       /*!< 0x0000016C AES share 1 word 1 key register */
   __IM uint32_t RESERVED10[2];
   __OM uint32_t KEY_1_2;                       /*!< 0x00000178 AES share 1 word 2 key register */
   __IM uint32_t RESERVED11[2];
   __OM uint32_t KEY_1_3;                       /*!< 0x00000184 AES share 1 word 3 key register */
   __IM uint32_t RESERVED12[2];
   __OM uint32_t KEY_1_4;                       /*!< 0x00000190 AES share 1 word 4 key register */
   __IM uint32_t RESERVED13[2];
   __OM uint32_t KEY_1_5;                       /*!< 0x0000019C AES share 1 word 5 key register */
   __IM uint32_t RESERVED14[2];
   __OM uint32_t KEY_1_6;                       /*!< 0x000001A8 AES share 1 word 6 key register */
   __IM uint32_t RESERVED15[2];
   __OM uint32_t KEY_1_7;                       /*!< 0x000001B4 AES share 1 word 7 data register */
   __IM uint32_t RESERVED16[146];
  __IOM uint32_t DATA_0_0;                      /*!< 0x00000400 AES share 0 word 0 data register */
   __IM uint32_t RESERVED17[2];
  __IOM uint32_t DATA_0_1;                      /*!< 0x0000040C AES share 0 word 1 data register */
   __IM uint32_t RESERVED18[2];
  __IOM uint32_t DATA_0_2;                      /*!< 0x00000418 AES share 0 word 2 data register */
   __IM uint32_t RESERVED19[2];
  __IOM uint32_t DATA_0_3;                      /*!< 0x00000424 AES share 0 word 3 data register */
   __IM uint32_t RESERVED20[2];
  __IOM uint32_t DATA_1_0;                      /*!< 0x00000430 AES share 1 word 0 data register */
   __IM uint32_t RESERVED21[2];
  __IOM uint32_t DATA_1_1;                      /*!< 0x0000043C AES share 1 word 1 data register */
   __IM uint32_t RESERVED22[2];
  __IOM uint32_t DATA_1_2;                      /*!< 0x00000448 AES share 1 word 2 data register */
   __IM uint32_t RESERVED23[2];
  __IOM uint32_t DATA_1_3;                      /*!< 0x00000454 AES share 1 word 3 data register */
   __IM uint32_t RESERVED24[14];
   __IM uint32_t DATA_RR_0_0;                   /*!< 0x00000490 AES share 0 word 0 data reread register */
   __IM uint32_t RESERVED25[2];
   __IM uint32_t DATA_RR_0_1;                   /*!< 0x0000049C AES share 0 word 1 data reread register */
   __IM uint32_t RESERVED26[2];
   __IM uint32_t DATA_RR_0_2;                   /*!< 0x000004A8 AES share 0 word 2 data reread register */
   __IM uint32_t RESERVED27[2];
   __IM uint32_t DATA_RR_0_3;                   /*!< 0x000004B4 AES share 0 word 3 data reread register */
   __IM uint32_t RESERVED28[2];
   __IM uint32_t DATA_RR_1_0;                   /*!< 0x000004C0 AES share 1 word 0 data reread register */
   __IM uint32_t RESERVED29[2];
   __IM uint32_t DATA_RR_1_1;                   /*!< 0x000004CC AES share 1 word 1 data reread register */
   __IM uint32_t RESERVED30[2];
   __IM uint32_t DATA_RR_1_2;                   /*!< 0x000004D8 AES share 1 word 2 data reread register */
   __IM uint32_t RESERVED31[2];
   __IM uint32_t DATA_RR_1_3;                   /*!< 0x000004E4 AES share 1 word 3 data reread register */
   __IM uint32_t RESERVED32[198];
} MXAES_MASKED_USER_RANGE_Type;                 /*!< Size = 2048 (0x800) */

/**
  * \brief MXAES
  */
typedef struct {
        MXAES_UNMASKED_USER_RANGE_Type UNMASKED_USER_RANGE; /*!< 0x00000000 AES command and configuration registers */
   __IM uint32_t RESERVED[512];
        MXAES_MASKED_USER_RANGE_Type MASKED_USER_RANGE; /*!< 0x00001000 AES data and key shares */
} MXAES_Type;                                   /*!< Size = 6144 (0x1800) */


/* MXAES_UNMASKED_USER_RANGE.CFG */
#define MXAES_UNMASKED_USER_RANGE_CFG_CALC_MODE_Pos 0UL
#define MXAES_UNMASKED_USER_RANGE_CFG_CALC_MODE_Msk 0x1FUL
#define MXAES_UNMASKED_USER_RANGE_CFG_CRYPT_MODE_Pos 8UL
#define MXAES_UNMASKED_USER_RANGE_CFG_CRYPT_MODE_Msk 0x1F00UL
/* MXAES_UNMASKED_USER_RANGE.CMD */
#define MXAES_UNMASKED_USER_RANGE_CMD_START_ENC_Pos 0UL
#define MXAES_UNMASKED_USER_RANGE_CMD_START_ENC_Msk 0x1UL
#define MXAES_UNMASKED_USER_RANGE_CMD_START_DEC_Pos 1UL
#define MXAES_UNMASKED_USER_RANGE_CMD_START_DEC_Msk 0x2UL
/* MXAES_UNMASKED_USER_RANGE.STAT */
#define MXAES_UNMASKED_USER_RANGE_STAT_DATA_Pos 0UL
#define MXAES_UNMASKED_USER_RANGE_STAT_DATA_Msk 0x1UL
#define MXAES_UNMASKED_USER_RANGE_STAT_AES_KEY_128LO_Pos 1UL
#define MXAES_UNMASKED_USER_RANGE_STAT_AES_KEY_128LO_Msk 0x2UL
#define MXAES_UNMASKED_USER_RANGE_STAT_AES_KEY_128HI_Pos 2UL
#define MXAES_UNMASKED_USER_RANGE_STAT_AES_KEY_128HI_Msk 0x4UL
#define MXAES_UNMASKED_USER_RANGE_STAT_AES_KEY_256_Pos 4UL
#define MXAES_UNMASKED_USER_RANGE_STAT_AES_KEY_256_Msk 0x10UL
#define MXAES_UNMASKED_USER_RANGE_STAT_SEC_LEVEL_RR_Pos 8UL
#define MXAES_UNMASKED_USER_RANGE_STAT_SEC_LEVEL_RR_Msk 0xF00UL
#define MXAES_UNMASKED_USER_RANGE_STAT_SEED_Pos 13UL
#define MXAES_UNMASKED_USER_RANGE_STAT_SEED_Msk 0x2000UL
#define MXAES_UNMASKED_USER_RANGE_STAT_RDY_Pos  14UL
#define MXAES_UNMASKED_USER_RANGE_STAT_RDY_Msk  0x4000UL
#define MXAES_UNMASKED_USER_RANGE_STAT_BSY_Pos  15UL
#define MXAES_UNMASKED_USER_RANGE_STAT_BSY_Msk  0x8000UL
#define MXAES_UNMASKED_USER_RANGE_STAT_CALC_MODE_RR_Pos 16UL
#define MXAES_UNMASKED_USER_RANGE_STAT_CALC_MODE_RR_Msk 0x1F0000UL
#define MXAES_UNMASKED_USER_RANGE_STAT_CRYPT_MODE_RR_Pos 24UL
#define MXAES_UNMASKED_USER_RANGE_STAT_CRYPT_MODE_RR_Msk 0x1F000000UL
#define MXAES_UNMASKED_USER_RANGE_STAT_START_ENC_RR_Pos 29UL
#define MXAES_UNMASKED_USER_RANGE_STAT_START_ENC_RR_Msk 0x20000000UL
#define MXAES_UNMASKED_USER_RANGE_STAT_START_DEC_RR_Pos 30UL
#define MXAES_UNMASKED_USER_RANGE_STAT_START_DEC_RR_Msk 0x40000000UL
/* MXAES_UNMASKED_USER_RANGE.CFG_2 */
#define MXAES_UNMASKED_USER_RANGE_CFG_2_SEC_LEVEL_Pos 0UL
#define MXAES_UNMASKED_USER_RANGE_CFG_2_SEC_LEVEL_Msk 0xFUL
/* MXAES_UNMASKED_USER_RANGE.INTR */
#define MXAES_UNMASKED_USER_RANGE_INTR_CALC_FINISHED_Pos 0UL
#define MXAES_UNMASKED_USER_RANGE_INTR_CALC_FINISHED_Msk 0x1UL
/* MXAES_UNMASKED_USER_RANGE.INTR_SET */
#define MXAES_UNMASKED_USER_RANGE_INTR_SET_CALC_FINISHED_Pos 0UL
#define MXAES_UNMASKED_USER_RANGE_INTR_SET_CALC_FINISHED_Msk 0x1UL
/* MXAES_UNMASKED_USER_RANGE.INTR_MASK */
#define MXAES_UNMASKED_USER_RANGE_INTR_MASK_CALC_FINISHED_Pos 0UL
#define MXAES_UNMASKED_USER_RANGE_INTR_MASK_CALC_FINISHED_Msk 0x1UL
/* MXAES_UNMASKED_USER_RANGE.INTR_MASKED */
#define MXAES_UNMASKED_USER_RANGE_INTR_MASKED_CALC_FINISHED_Pos 0UL
#define MXAES_UNMASKED_USER_RANGE_INTR_MASKED_CALC_FINISHED_Msk 0x1UL
/* MXAES_UNMASKED_USER_RANGE.CLEAR */
#define MXAES_UNMASKED_USER_RANGE_CLEAR_DATA_Pos 0UL
#define MXAES_UNMASKED_USER_RANGE_CLEAR_DATA_Msk 0x1UL
#define MXAES_UNMASKED_USER_RANGE_CLEAR_AES_KEY_128LO_Pos 1UL
#define MXAES_UNMASKED_USER_RANGE_CLEAR_AES_KEY_128LO_Msk 0x2UL
#define MXAES_UNMASKED_USER_RANGE_CLEAR_AES_KEY_128HI_Pos 2UL
#define MXAES_UNMASKED_USER_RANGE_CLEAR_AES_KEY_128HI_Msk 0x4UL
#define MXAES_UNMASKED_USER_RANGE_CLEAR_AES_KEY_256_Pos 4UL
#define MXAES_UNMASKED_USER_RANGE_CLEAR_AES_KEY_256_Msk 0x10UL
#define MXAES_UNMASKED_USER_RANGE_CLEAR_CLEAR_ALL_Pos 5UL
#define MXAES_UNMASKED_USER_RANGE_CLEAR_CLEAR_ALL_Msk 0x20UL
/* MXAES_UNMASKED_USER_RANGE.BUS_COUNTER */
#define MXAES_UNMASKED_USER_RANGE_BUS_COUNTER_CTR_Pos 0UL
#define MXAES_UNMASKED_USER_RANGE_BUS_COUNTER_CTR_Msk 0xFFUL
/* MXAES_UNMASKED_USER_RANGE.QCHAN_CTL */
#define MXAES_UNMASKED_USER_RANGE_QCHAN_CTL_QDENY_RESP_Pos 0UL
#define MXAES_UNMASKED_USER_RANGE_QCHAN_CTL_QDENY_RESP_Msk 0x1UL
#define MXAES_UNMASKED_USER_RANGE_QCHAN_CTL_QDENY_STATUS_Pos 1UL
#define MXAES_UNMASKED_USER_RANGE_QCHAN_CTL_QDENY_STATUS_Msk 0x2UL


/* MXAES_MASKED_USER_RANGE.SEED_U */
#define MXAES_MASKED_USER_RANGE_SEED_U_PRNG_SEED_Pos 0UL
#define MXAES_MASKED_USER_RANGE_SEED_U_PRNG_SEED_Msk 0xFFFFFFFFUL
/* MXAES_MASKED_USER_RANGE.KEY_0_0 */
#define MXAES_MASKED_USER_RANGE_KEY_0_0_KEY_Pos 0UL
#define MXAES_MASKED_USER_RANGE_KEY_0_0_KEY_Msk 0xFFFFFFFFUL
/* MXAES_MASKED_USER_RANGE.KEY_0_1 */
#define MXAES_MASKED_USER_RANGE_KEY_0_1_KEY_Pos 0UL
#define MXAES_MASKED_USER_RANGE_KEY_0_1_KEY_Msk 0xFFFFFFFFUL
/* MXAES_MASKED_USER_RANGE.KEY_0_2 */
#define MXAES_MASKED_USER_RANGE_KEY_0_2_KEY_Pos 0UL
#define MXAES_MASKED_USER_RANGE_KEY_0_2_KEY_Msk 0xFFFFFFFFUL
/* MXAES_MASKED_USER_RANGE.KEY_0_3 */
#define MXAES_MASKED_USER_RANGE_KEY_0_3_KEY_Pos 0UL
#define MXAES_MASKED_USER_RANGE_KEY_0_3_KEY_Msk 0xFFFFFFFFUL
/* MXAES_MASKED_USER_RANGE.KEY_0_4 */
#define MXAES_MASKED_USER_RANGE_KEY_0_4_KEY_Pos 0UL
#define MXAES_MASKED_USER_RANGE_KEY_0_4_KEY_Msk 0xFFFFFFFFUL
/* MXAES_MASKED_USER_RANGE.KEY_0_5 */
#define MXAES_MASKED_USER_RANGE_KEY_0_5_KEY_Pos 0UL
#define MXAES_MASKED_USER_RANGE_KEY_0_5_KEY_Msk 0xFFFFFFFFUL
/* MXAES_MASKED_USER_RANGE.KEY_0_6 */
#define MXAES_MASKED_USER_RANGE_KEY_0_6_KEY_Pos 0UL
#define MXAES_MASKED_USER_RANGE_KEY_0_6_KEY_Msk 0xFFFFFFFFUL
/* MXAES_MASKED_USER_RANGE.KEY_0_7 */
#define MXAES_MASKED_USER_RANGE_KEY_0_7_KEY_Pos 0UL
#define MXAES_MASKED_USER_RANGE_KEY_0_7_KEY_Msk 0xFFFFFFFFUL
/* MXAES_MASKED_USER_RANGE.KEY_1_0 */
#define MXAES_MASKED_USER_RANGE_KEY_1_0_KEY_Pos 0UL
#define MXAES_MASKED_USER_RANGE_KEY_1_0_KEY_Msk 0xFFFFFFFFUL
/* MXAES_MASKED_USER_RANGE.KEY_1_1 */
#define MXAES_MASKED_USER_RANGE_KEY_1_1_KEY_Pos 0UL
#define MXAES_MASKED_USER_RANGE_KEY_1_1_KEY_Msk 0xFFFFFFFFUL
/* MXAES_MASKED_USER_RANGE.KEY_1_2 */
#define MXAES_MASKED_USER_RANGE_KEY_1_2_KEY_Pos 0UL
#define MXAES_MASKED_USER_RANGE_KEY_1_2_KEY_Msk 0xFFFFFFFFUL
/* MXAES_MASKED_USER_RANGE.KEY_1_3 */
#define MXAES_MASKED_USER_RANGE_KEY_1_3_KEY_Pos 0UL
#define MXAES_MASKED_USER_RANGE_KEY_1_3_KEY_Msk 0xFFFFFFFFUL
/* MXAES_MASKED_USER_RANGE.KEY_1_4 */
#define MXAES_MASKED_USER_RANGE_KEY_1_4_KEY_Pos 0UL
#define MXAES_MASKED_USER_RANGE_KEY_1_4_KEY_Msk 0xFFFFFFFFUL
/* MXAES_MASKED_USER_RANGE.KEY_1_5 */
#define MXAES_MASKED_USER_RANGE_KEY_1_5_KEY_Pos 0UL
#define MXAES_MASKED_USER_RANGE_KEY_1_5_KEY_Msk 0xFFFFFFFFUL
/* MXAES_MASKED_USER_RANGE.KEY_1_6 */
#define MXAES_MASKED_USER_RANGE_KEY_1_6_KEY_Pos 0UL
#define MXAES_MASKED_USER_RANGE_KEY_1_6_KEY_Msk 0xFFFFFFFFUL
/* MXAES_MASKED_USER_RANGE.KEY_1_7 */
#define MXAES_MASKED_USER_RANGE_KEY_1_7_KEY_Pos 0UL
#define MXAES_MASKED_USER_RANGE_KEY_1_7_KEY_Msk 0xFFFFFFFFUL
/* MXAES_MASKED_USER_RANGE.DATA_0_0 */
#define MXAES_MASKED_USER_RANGE_DATA_0_0_DATA_Pos 0UL
#define MXAES_MASKED_USER_RANGE_DATA_0_0_DATA_Msk 0xFFFFFFFFUL
/* MXAES_MASKED_USER_RANGE.DATA_0_1 */
#define MXAES_MASKED_USER_RANGE_DATA_0_1_DATA_Pos 0UL
#define MXAES_MASKED_USER_RANGE_DATA_0_1_DATA_Msk 0xFFFFFFFFUL
/* MXAES_MASKED_USER_RANGE.DATA_0_2 */
#define MXAES_MASKED_USER_RANGE_DATA_0_2_DATA_Pos 0UL
#define MXAES_MASKED_USER_RANGE_DATA_0_2_DATA_Msk 0xFFFFFFFFUL
/* MXAES_MASKED_USER_RANGE.DATA_0_3 */
#define MXAES_MASKED_USER_RANGE_DATA_0_3_DATA_Pos 0UL
#define MXAES_MASKED_USER_RANGE_DATA_0_3_DATA_Msk 0xFFFFFFFFUL
/* MXAES_MASKED_USER_RANGE.DATA_1_0 */
#define MXAES_MASKED_USER_RANGE_DATA_1_0_DATA_Pos 0UL
#define MXAES_MASKED_USER_RANGE_DATA_1_0_DATA_Msk 0xFFFFFFFFUL
/* MXAES_MASKED_USER_RANGE.DATA_1_1 */
#define MXAES_MASKED_USER_RANGE_DATA_1_1_DATA_Pos 0UL
#define MXAES_MASKED_USER_RANGE_DATA_1_1_DATA_Msk 0xFFFFFFFFUL
/* MXAES_MASKED_USER_RANGE.DATA_1_2 */
#define MXAES_MASKED_USER_RANGE_DATA_1_2_DATA_Pos 0UL
#define MXAES_MASKED_USER_RANGE_DATA_1_2_DATA_Msk 0xFFFFFFFFUL
/* MXAES_MASKED_USER_RANGE.DATA_1_3 */
#define MXAES_MASKED_USER_RANGE_DATA_1_3_DATA_Pos 0UL
#define MXAES_MASKED_USER_RANGE_DATA_1_3_DATA_Msk 0xFFFFFFFFUL
/* MXAES_MASKED_USER_RANGE.DATA_RR_0_0 */
#define MXAES_MASKED_USER_RANGE_DATA_RR_0_0_DATA_Pos 0UL
#define MXAES_MASKED_USER_RANGE_DATA_RR_0_0_DATA_Msk 0xFFFFFFFFUL
/* MXAES_MASKED_USER_RANGE.DATA_RR_0_1 */
#define MXAES_MASKED_USER_RANGE_DATA_RR_0_1_DATA_Pos 0UL
#define MXAES_MASKED_USER_RANGE_DATA_RR_0_1_DATA_Msk 0xFFFFFFFFUL
/* MXAES_MASKED_USER_RANGE.DATA_RR_0_2 */
#define MXAES_MASKED_USER_RANGE_DATA_RR_0_2_DATA_Pos 0UL
#define MXAES_MASKED_USER_RANGE_DATA_RR_0_2_DATA_Msk 0xFFFFFFFFUL
/* MXAES_MASKED_USER_RANGE.DATA_RR_0_3 */
#define MXAES_MASKED_USER_RANGE_DATA_RR_0_3_DATA_Pos 0UL
#define MXAES_MASKED_USER_RANGE_DATA_RR_0_3_DATA_Msk 0xFFFFFFFFUL
/* MXAES_MASKED_USER_RANGE.DATA_RR_1_0 */
#define MXAES_MASKED_USER_RANGE_DATA_RR_1_0_DATA_Pos 0UL
#define MXAES_MASKED_USER_RANGE_DATA_RR_1_0_DATA_Msk 0xFFFFFFFFUL
/* MXAES_MASKED_USER_RANGE.DATA_RR_1_1 */
#define MXAES_MASKED_USER_RANGE_DATA_RR_1_1_DATA_Pos 0UL
#define MXAES_MASKED_USER_RANGE_DATA_RR_1_1_DATA_Msk 0xFFFFFFFFUL
/* MXAES_MASKED_USER_RANGE.DATA_RR_1_2 */
#define MXAES_MASKED_USER_RANGE_DATA_RR_1_2_DATA_Pos 0UL
#define MXAES_MASKED_USER_RANGE_DATA_RR_1_2_DATA_Msk 0xFFFFFFFFUL
/* MXAES_MASKED_USER_RANGE.DATA_RR_1_3 */
#define MXAES_MASKED_USER_RANGE_DATA_RR_1_3_DATA_Pos 0UL
#define MXAES_MASKED_USER_RANGE_DATA_RR_1_3_DATA_Msk 0xFFFFFFFFUL


#endif /* _CYIP_MXAES_V2_2_H_ */


/* [] END OF FILE */
