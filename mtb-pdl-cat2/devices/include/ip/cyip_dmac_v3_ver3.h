/***************************************************************************//**
* \file cyip_dmac_v3_ver3.h
*
* \brief
* DMAC IP definitions
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

#ifndef _CYIP_DMAC_V3_VER3_H_
#define _CYIP_DMAC_V3_VER3_H_

#include "cyip_headers.h"

/*******************************************************************************
*                                     DMAC
*******************************************************************************/

#define DMAC_DESCR_SECTION_SIZE                 0x00000020UL
#define DMAC_SECTION_SIZE                       0x00001000UL

/**
  * \brief Descriptors (DMAC_DESCR)
  */
typedef struct {
  __IOM uint32_t PING_SRC;                      /*!< 0x00000000 Ping source address */
  __IOM uint32_t PING_DST;                      /*!< 0x00000004 Ping destination address */
  __IOM uint32_t PING_CTL;                      /*!< 0x00000008 Ping control word */
  __IOM uint32_t PING_STATUS;                   /*!< 0x0000000C Ping status word */
  __IOM uint32_t PONG_SRC;                      /*!< 0x00000010 Pong source address */
  __IOM uint32_t PONG_DST;                      /*!< 0x00000014 Pong destination address */
  __IOM uint32_t PONG_CTL;                      /*!< 0x00000018 Pong control word */
  __IOM uint32_t PONG_STATUS;                   /*!< 0x0000001C Pong status word */
} DMAC_DESCR_Type;                              /*!< Size = 32 (0x20) */

/**
  * \brief DataWire/DMA Controller (DMAC)
  */
typedef struct {
  __IOM uint32_t CTL;                           /*!< 0x00000000 Control register */
   __IM uint32_t RESERVED[3];
   __IM uint32_t STATUS;                        /*!< 0x00000010 Status register */
   __IM uint32_t STATUS_SRC_ADDR;               /*!< 0x00000014 Source address status register */
   __IM uint32_t STATUS_DST_ADDR;               /*!< 0x00000018 Destination address register */
   __IM uint32_t STATUS_CH_ACT;                 /*!< 0x0000001C Channel activation status register */
   __IM uint32_t RESERVED1[24];
  __IOM uint32_t CH_CTL[32];                    /*!< 0x00000080 Channel control register */
   __IM uint32_t RESERVED2[444];
  __IOM uint32_t INTR;                          /*!< 0x000007F0 Interrupt register */
  __IOM uint32_t INTR_SET;                      /*!< 0x000007F4 Interrupt set register */
  __IOM uint32_t INTR_MASK;                     /*!< 0x000007F8 Interrupt mask register */
   __IM uint32_t INTR_MASKED;                   /*!< 0x000007FC Interrupt masked register */
        DMAC_DESCR_Type DESCR[32];              /*!< 0x00000800 Descriptors */
} DMAC_Type;                                    /*!< Size = 3072 (0xC00) */


/* DMAC_DESCR.PING_SRC */
#define DMAC_DESCR_PING_SRC_ADDR_Pos            0UL
#define DMAC_DESCR_PING_SRC_ADDR_Msk            0xFFFFFFFFUL
/* DMAC_DESCR.PING_DST */
#define DMAC_DESCR_PING_DST_ADDR_Pos            0UL
#define DMAC_DESCR_PING_DST_ADDR_Msk            0xFFFFFFFFUL
/* DMAC_DESCR.PING_CTL */
#define DMAC_DESCR_PING_CTL_DATA_NR_Pos         0UL
#define DMAC_DESCR_PING_CTL_DATA_NR_Msk         0xFFFFUL
#define DMAC_DESCR_PING_CTL_DATA_SIZE_Pos       16UL
#define DMAC_DESCR_PING_CTL_DATA_SIZE_Msk       0x30000UL
#define DMAC_DESCR_PING_CTL_DST_TRANSFER_SIZE_Pos 20UL
#define DMAC_DESCR_PING_CTL_DST_TRANSFER_SIZE_Msk 0x100000UL
#define DMAC_DESCR_PING_CTL_DST_ADDR_INCR_Pos   21UL
#define DMAC_DESCR_PING_CTL_DST_ADDR_INCR_Msk   0x200000UL
#define DMAC_DESCR_PING_CTL_SRC_TRANSFER_SIZE_Pos 22UL
#define DMAC_DESCR_PING_CTL_SRC_TRANSFER_SIZE_Msk 0x400000UL
#define DMAC_DESCR_PING_CTL_SRC_ADDR_INCR_Pos   23UL
#define DMAC_DESCR_PING_CTL_SRC_ADDR_INCR_Msk   0x800000UL
#define DMAC_DESCR_PING_CTL_WAIT_FOR_DEACT_Pos  24UL
#define DMAC_DESCR_PING_CTL_WAIT_FOR_DEACT_Msk  0x3000000UL
#define DMAC_DESCR_PING_CTL_INV_DESCR_Pos       26UL
#define DMAC_DESCR_PING_CTL_INV_DESCR_Msk       0x4000000UL
#define DMAC_DESCR_PING_CTL_SET_CAUSE_Pos       27UL
#define DMAC_DESCR_PING_CTL_SET_CAUSE_Msk       0x8000000UL
#define DMAC_DESCR_PING_CTL_PREEMPTABLE_Pos     28UL
#define DMAC_DESCR_PING_CTL_PREEMPTABLE_Msk     0x10000000UL
#define DMAC_DESCR_PING_CTL_FLIPPING_Pos        29UL
#define DMAC_DESCR_PING_CTL_FLIPPING_Msk        0x20000000UL
#define DMAC_DESCR_PING_CTL_OPCODE_Pos          30UL
#define DMAC_DESCR_PING_CTL_OPCODE_Msk          0xC0000000UL
/* DMAC_DESCR.PING_STATUS */
#define DMAC_DESCR_PING_STATUS_CURR_DATA_NR_Pos 0UL
#define DMAC_DESCR_PING_STATUS_CURR_DATA_NR_Msk 0xFFFFUL
#define DMAC_DESCR_PING_STATUS_RESPONSE_Pos     16UL
#define DMAC_DESCR_PING_STATUS_RESPONSE_Msk     0x70000UL
#define DMAC_DESCR_PING_STATUS_VALID_Pos        31UL
#define DMAC_DESCR_PING_STATUS_VALID_Msk        0x80000000UL
/* DMAC_DESCR.PONG_SRC */
#define DMAC_DESCR_PONG_SRC_ADDR_Pos            0UL
#define DMAC_DESCR_PONG_SRC_ADDR_Msk            0xFFFFFFFFUL
/* DMAC_DESCR.PONG_DST */
#define DMAC_DESCR_PONG_DST_ADDR_Pos            0UL
#define DMAC_DESCR_PONG_DST_ADDR_Msk            0xFFFFFFFFUL
/* DMAC_DESCR.PONG_CTL */
#define DMAC_DESCR_PONG_CTL_DATA_NR_Pos         0UL
#define DMAC_DESCR_PONG_CTL_DATA_NR_Msk         0xFFFFUL
#define DMAC_DESCR_PONG_CTL_DATA_SIZE_Pos       16UL
#define DMAC_DESCR_PONG_CTL_DATA_SIZE_Msk       0x30000UL
#define DMAC_DESCR_PONG_CTL_DST_TRANSFER_SIZE_Pos 20UL
#define DMAC_DESCR_PONG_CTL_DST_TRANSFER_SIZE_Msk 0x100000UL
#define DMAC_DESCR_PONG_CTL_DST_ADDR_INCR_Pos   21UL
#define DMAC_DESCR_PONG_CTL_DST_ADDR_INCR_Msk   0x200000UL
#define DMAC_DESCR_PONG_CTL_SRC_TRANSFER_SIZE_Pos 22UL
#define DMAC_DESCR_PONG_CTL_SRC_TRANSFER_SIZE_Msk 0x400000UL
#define DMAC_DESCR_PONG_CTL_SRC_ADDR_INCR_Pos   23UL
#define DMAC_DESCR_PONG_CTL_SRC_ADDR_INCR_Msk   0x800000UL
#define DMAC_DESCR_PONG_CTL_WAIT_FOR_DEACT_Pos  24UL
#define DMAC_DESCR_PONG_CTL_WAIT_FOR_DEACT_Msk  0x3000000UL
#define DMAC_DESCR_PONG_CTL_INV_DESCR_Pos       26UL
#define DMAC_DESCR_PONG_CTL_INV_DESCR_Msk       0x4000000UL
#define DMAC_DESCR_PONG_CTL_SET_CAUSE_Pos       27UL
#define DMAC_DESCR_PONG_CTL_SET_CAUSE_Msk       0x8000000UL
#define DMAC_DESCR_PONG_CTL_PREEMPTABLE_Pos     28UL
#define DMAC_DESCR_PONG_CTL_PREEMPTABLE_Msk     0x10000000UL
#define DMAC_DESCR_PONG_CTL_FLIPPING_Pos        29UL
#define DMAC_DESCR_PONG_CTL_FLIPPING_Msk        0x20000000UL
#define DMAC_DESCR_PONG_CTL_OPCODE_Pos          30UL
#define DMAC_DESCR_PONG_CTL_OPCODE_Msk          0xC0000000UL
/* DMAC_DESCR.PONG_STATUS */
#define DMAC_DESCR_PONG_STATUS_CURR_DATA_NR_Pos 0UL
#define DMAC_DESCR_PONG_STATUS_CURR_DATA_NR_Msk 0xFFFFUL
#define DMAC_DESCR_PONG_STATUS_RESPONSE_Pos     16UL
#define DMAC_DESCR_PONG_STATUS_RESPONSE_Msk     0x70000UL
#define DMAC_DESCR_PONG_STATUS_VALID_Pos        31UL
#define DMAC_DESCR_PONG_STATUS_VALID_Msk        0x80000000UL


/* DMAC.CTL */
#define DMAC_CTL_ENABLED_Pos                    31UL
#define DMAC_CTL_ENABLED_Msk                    0x80000000UL
/* DMAC.STATUS */
#define DMAC_STATUS_DATA_NR_Pos                 0UL
#define DMAC_STATUS_DATA_NR_Msk                 0xFFFFUL
#define DMAC_STATUS_CH_ADDR_Pos                 16UL
#define DMAC_STATUS_CH_ADDR_Msk                 0x1F0000UL
#define DMAC_STATUS_STATE_Pos                   24UL
#define DMAC_STATUS_STATE_Msk                   0x7000000UL
#define DMAC_STATUS_PRIO_Pos                    28UL
#define DMAC_STATUS_PRIO_Msk                    0x30000000UL
#define DMAC_STATUS_PING_PONG_Pos               30UL
#define DMAC_STATUS_PING_PONG_Msk               0x40000000UL
#define DMAC_STATUS_ACTIVE_Pos                  31UL
#define DMAC_STATUS_ACTIVE_Msk                  0x80000000UL
/* DMAC.STATUS_SRC_ADDR */
#define DMAC_STATUS_SRC_ADDR_ADDR_Pos           0UL
#define DMAC_STATUS_SRC_ADDR_ADDR_Msk           0xFFFFFFFFUL
/* DMAC.STATUS_DST_ADDR */
#define DMAC_STATUS_DST_ADDR_ADDR_Pos           0UL
#define DMAC_STATUS_DST_ADDR_ADDR_Msk           0xFFFFFFFFUL
/* DMAC.STATUS_CH_ACT */
#define DMAC_STATUS_CH_ACT_CH_Pos               0UL
#define DMAC_STATUS_CH_ACT_CH_Msk               0xFFFFFFFFUL
/* DMAC.CH_CTL */
#define DMAC_CH_CTL_PRIO_Pos                    28UL
#define DMAC_CH_CTL_PRIO_Msk                    0x30000000UL
#define DMAC_CH_CTL_PING_PONG_Pos               30UL
#define DMAC_CH_CTL_PING_PONG_Msk               0x40000000UL
#define DMAC_CH_CTL_ENABLED_Pos                 31UL
#define DMAC_CH_CTL_ENABLED_Msk                 0x80000000UL
/* DMAC.INTR */
#define DMAC_INTR_CH_Pos                        0UL
#define DMAC_INTR_CH_Msk                        0xFFFFFFFFUL
/* DMAC.INTR_SET */
#define DMAC_INTR_SET_CH_Pos                    0UL
#define DMAC_INTR_SET_CH_Msk                    0xFFFFFFFFUL
/* DMAC.INTR_MASK */
#define DMAC_INTR_MASK_CH_Pos                   0UL
#define DMAC_INTR_MASK_CH_Msk                   0xFFFFFFFFUL
/* DMAC.INTR_MASKED */
#define DMAC_INTR_MASKED_CH_Pos                 0UL
#define DMAC_INTR_MASKED_CH_Msk                 0xFFFFFFFFUL


#endif /* _CYIP_DMAC_V3_VER3_H_ */


/* [] END OF FILE */
