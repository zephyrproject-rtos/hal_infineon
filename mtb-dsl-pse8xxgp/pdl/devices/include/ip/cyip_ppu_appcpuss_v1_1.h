/***************************************************************************//**
* \file cyip_ppu_appcpuss_v1_1.h
*
* \brief
* PPU_APPCPUSS IP definitions
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

#ifndef _CYIP_PPU_APPCPUSS_V1_1_H_
#define _CYIP_PPU_APPCPUSS_V1_1_H_

#include "cyip_headers.h"

/*******************************************************************************
*                                 PPU_APPCPUSS
*******************************************************************************/

#define PPU_APPCPUSS_SECTION_SIZE               0x00001000UL

/**
  * \brief Power Policy Unit Registers for APPCPUSS PPU (PPU_APPCPUSS)
  */
typedef struct {
  __IOM uint32_t PWPR;                          /*!< 0x00000000 Power Policy Register */
  __IOM uint32_t PMER;                          /*!< 0x00000004 Power Mode Emulation Register */
   __IM uint32_t PWSR;                          /*!< 0x00000008 Power Status Register */
   __IM uint32_t RESERVED;
   __IM uint32_t DISR;                          /*!< 0x00000010 Device Interface Input Current Status Register */
   __IM uint32_t MISR;                          /*!< 0x00000014 Miscellaneous Input Current Status Register */
   __IM uint32_t STSR;                          /*!< 0x00000018 Stored Status Register */
  __IOM uint32_t UNLK;                          /*!< 0x0000001C Unlock register */
  __IOM uint32_t PWCR;                          /*!< 0x00000020 Power Configuration Register */
  __IOM uint32_t PTCR;                          /*!< 0x00000024 Power Mode Transition Configuration Register */
   __IM uint32_t RESERVED1[2];
  __IOM uint32_t IMR;                           /*!< 0x00000030 Interrupt Mask Register */
  __IOM uint32_t AIMR;                          /*!< 0x00000034 Additional Interrupt Mask Register */
  __IOM uint32_t ISR;                           /*!< 0x00000038 Interrupt Status Register */
  __IOM uint32_t AISR;                          /*!< 0x0000003C Additional Interrupt Status Register */
  __IOM uint32_t IESR;                          /*!< 0x00000040 Input Edge Sensitivity Register */
  __IOM uint32_t OPSR;                          /*!< 0x00000044 Operating Mode Active Edge Sensitivity Register */
   __IM uint32_t RESERVED2[2];
  __IOM uint32_t FUNRR;                         /*!< 0x00000050 Functional Retention RAM Configuration Register */
  __IOM uint32_t FULRR;                         /*!< 0x00000054 Full Retention RAM Configuration Register */
  __IOM uint32_t MEMRR;                         /*!< 0x00000058 Memory Retention RAM Configuration Register */
   __IM uint32_t RESERVED3[65];
  __IOM uint32_t EDTR0;                         /*!< 0x00000160 Power Mode Entry Delay Register 0 */
  __IOM uint32_t EDTR1;                         /*!< 0x00000164 Power Mode Entry Delay Register 1 */
   __IM uint32_t RESERVED4[2];
   __IM uint32_t DCDR0;                         /*!< 0x00000170 Device Control Delay Configuration Register 0 */
   __IM uint32_t DCDR1;                         /*!< 0x00000174 Device Control Delay Configuration Register 1 */
   __IM uint32_t RESERVED5[910];
   __IM uint32_t IDR0;                          /*!< 0x00000FB0 PPU Identification Register 0 */
   __IM uint32_t IDR1;                          /*!< 0x00000FB4 PPU Identification Register 1 */
   __IM uint32_t RESERVED6[4];
   __IM uint32_t IIDR;                          /*!< 0x00000FC8 Implementation Identification Register */
   __IM uint32_t AIDR;                          /*!< 0x00000FCC Architecture Identification Register */
   __IM uint32_t PID4;                          /*!< 0x00000FD0 Implementation Defined Identification Register (PID4) */
   __IM uint32_t RESERVED7[3];
   __IM uint32_t PID0;                          /*!< 0x00000FE0 Implementation Defined Identification Register (PID0) */
   __IM uint32_t PID1;                          /*!< 0x00000FE4 Implementation Defined Identification Register (PID1) */
   __IM uint32_t PID2;                          /*!< 0x00000FE8 Implementation Defined Identification Register (PID2) */
   __IM uint32_t PID3;                          /*!< 0x00000FEC Implementation Defined Identification Register (PID3) */
   __IM uint32_t ID0;                           /*!< 0x00000FF0 Implementation Defined Identification Register (ID0) */
   __IM uint32_t ID1;                           /*!< 0x00000FF4 Implementation Defined Identification Register (ID1) */
   __IM uint32_t ID2;                           /*!< 0x00000FF8 Implementation Defined Identification Register (ID2) */
   __IM uint32_t ID3;                           /*!< 0x00000FFC Implementation Defined Identification Register (ID3) */
} PPU_APPCPUSS_Type;                            /*!< Size = 4096 (0x1000) */


/* PPU_APPCPUSS.PWPR */
#define PPU_APPCPUSS_PWPR_PWR_POLICY_Pos        0UL
#define PPU_APPCPUSS_PWPR_PWR_POLICY_Msk        0xFUL
#define PPU_APPCPUSS_PWPR_PWR_DYN_EN_Pos        8UL
#define PPU_APPCPUSS_PWPR_PWR_DYN_EN_Msk        0x100UL
#define PPU_APPCPUSS_PWPR_LOCK_EN_Pos           12UL
#define PPU_APPCPUSS_PWPR_LOCK_EN_Msk           0x1000UL
#define PPU_APPCPUSS_PWPR_OP_POLICY_Pos         16UL
#define PPU_APPCPUSS_PWPR_OP_POLICY_Msk         0xF0000UL
#define PPU_APPCPUSS_PWPR_OP_DYN_EN_Pos         24UL
#define PPU_APPCPUSS_PWPR_OP_DYN_EN_Msk         0x1000000UL
/* PPU_APPCPUSS.PMER */
#define PPU_APPCPUSS_PMER_EMU_EN_Pos            0UL
#define PPU_APPCPUSS_PMER_EMU_EN_Msk            0x1UL
/* PPU_APPCPUSS.PWSR */
#define PPU_APPCPUSS_PWSR_PWR_STATUS_Pos        0UL
#define PPU_APPCPUSS_PWSR_PWR_STATUS_Msk        0xFUL
#define PPU_APPCPUSS_PWSR_PWR_DYN_STATUS_Pos    8UL
#define PPU_APPCPUSS_PWSR_PWR_DYN_STATUS_Msk    0x100UL
#define PPU_APPCPUSS_PWSR_LOCK_STATUS_Pos       12UL
#define PPU_APPCPUSS_PWSR_LOCK_STATUS_Msk       0x1000UL
#define PPU_APPCPUSS_PWSR_OP_STATUS_Pos         16UL
#define PPU_APPCPUSS_PWSR_OP_STATUS_Msk         0xF0000UL
#define PPU_APPCPUSS_PWSR_OP_DYN_STATUS_Pos     24UL
#define PPU_APPCPUSS_PWSR_OP_DYN_STATUS_Msk     0x1000000UL
/* PPU_APPCPUSS.DISR */
#define PPU_APPCPUSS_DISR_PWR_DEVACTIVE_STATUS_Pos 0UL
#define PPU_APPCPUSS_DISR_PWR_DEVACTIVE_STATUS_Msk 0x7FFUL
#define PPU_APPCPUSS_DISR_OP_DEVACTIVE_STATUS_Pos 24UL
#define PPU_APPCPUSS_DISR_OP_DEVACTIVE_STATUS_Msk 0xFF000000UL
/* PPU_APPCPUSS.MISR */
#define PPU_APPCPUSS_MISR_PCSMPACCEPT_STATUS_Pos 0UL
#define PPU_APPCPUSS_MISR_PCSMPACCEPT_STATUS_Msk 0x1UL
#define PPU_APPCPUSS_MISR_DEVACCEPT_STATUS_Pos  8UL
#define PPU_APPCPUSS_MISR_DEVACCEPT_STATUS_Msk  0xFF00UL
#define PPU_APPCPUSS_MISR_DEVDENY_STATUS_Pos    16UL
#define PPU_APPCPUSS_MISR_DEVDENY_STATUS_Msk    0xFF0000UL
/* PPU_APPCPUSS.STSR */
#define PPU_APPCPUSS_STSR_STORED_DEVDENY_Pos    0UL
#define PPU_APPCPUSS_STSR_STORED_DEVDENY_Msk    0xFFUL
/* PPU_APPCPUSS.UNLK */
#define PPU_APPCPUSS_UNLK_UNLOCK_Pos            0UL
#define PPU_APPCPUSS_UNLK_UNLOCK_Msk            0x1UL
/* PPU_APPCPUSS.PWCR */
#define PPU_APPCPUSS_PWCR_DEVREQEN_Pos          0UL
#define PPU_APPCPUSS_PWCR_DEVREQEN_Msk          0xFFUL
#define PPU_APPCPUSS_PWCR_PWR_DEVACTIVEEN_Pos   8UL
#define PPU_APPCPUSS_PWCR_PWR_DEVACTIVEEN_Msk   0x7FF00UL
#define PPU_APPCPUSS_PWCR_OP_DEVACTIVEEN_Pos    24UL
#define PPU_APPCPUSS_PWCR_OP_DEVACTIVEEN_Msk    0xFF000000UL
/* PPU_APPCPUSS.PTCR */
#define PPU_APPCPUSS_PTCR_WARM_RST_DEVREQEN_Pos 0UL
#define PPU_APPCPUSS_PTCR_WARM_RST_DEVREQEN_Msk 0x1UL
#define PPU_APPCPUSS_PTCR_DBG_RECOV_PORST_EN_Pos 1UL
#define PPU_APPCPUSS_PTCR_DBG_RECOV_PORST_EN_Msk 0x2UL
/* PPU_APPCPUSS.IMR */
#define PPU_APPCPUSS_IMR_STA_POLICY_TRN_IRQ_MASK_Pos 0UL
#define PPU_APPCPUSS_IMR_STA_POLICY_TRN_IRQ_MASK_Msk 0x1UL
#define PPU_APPCPUSS_IMR_STA_ACCEPT_IRQ_MASK_Pos 1UL
#define PPU_APPCPUSS_IMR_STA_ACCEPT_IRQ_MASK_Msk 0x2UL
#define PPU_APPCPUSS_IMR_STA_DENY_IRQ_MASK_Pos  2UL
#define PPU_APPCPUSS_IMR_STA_DENY_IRQ_MASK_Msk  0x4UL
#define PPU_APPCPUSS_IMR_EMU_ACCEPT_IRQ_MASK_Pos 3UL
#define PPU_APPCPUSS_IMR_EMU_ACCEPT_IRQ_MASK_Msk 0x8UL
#define PPU_APPCPUSS_IMR_EMU_DENY_IRQ_MASK_Pos  4UL
#define PPU_APPCPUSS_IMR_EMU_DENY_IRQ_MASK_Msk  0x10UL
#define PPU_APPCPUSS_IMR_LOCKED_IRQ_MASK_Pos    5UL
#define PPU_APPCPUSS_IMR_LOCKED_IRQ_MASK_Msk    0x20UL
/* PPU_APPCPUSS.AIMR */
#define PPU_APPCPUSS_AIMR_UNSPT_POLICY_IRQ_MASK_Pos 0UL
#define PPU_APPCPUSS_AIMR_UNSPT_POLICY_IRQ_MASK_Msk 0x1UL
#define PPU_APPCPUSS_AIMR_DYN_ACCEPT_IRQ_MASK_Pos 1UL
#define PPU_APPCPUSS_AIMR_DYN_ACCEPT_IRQ_MASK_Msk 0x2UL
#define PPU_APPCPUSS_AIMR_DYN_DENY_IRQ_MASK_Pos 2UL
#define PPU_APPCPUSS_AIMR_DYN_DENY_IRQ_MASK_Msk 0x4UL
#define PPU_APPCPUSS_AIMR_STA_POLICY_PWR_IRQ_MASK_Pos 3UL
#define PPU_APPCPUSS_AIMR_STA_POLICY_PWR_IRQ_MASK_Msk 0x8UL
#define PPU_APPCPUSS_AIMR_STA_POLICY_OP_IRQ_MASK_Pos 4UL
#define PPU_APPCPUSS_AIMR_STA_POLICY_OP_IRQ_MASK_Msk 0x10UL
/* PPU_APPCPUSS.ISR */
#define PPU_APPCPUSS_ISR_STA_POLICY_TRN_IRQ_Pos 0UL
#define PPU_APPCPUSS_ISR_STA_POLICY_TRN_IRQ_Msk 0x1UL
#define PPU_APPCPUSS_ISR_STA_ACCEPT_IRQ_Pos     1UL
#define PPU_APPCPUSS_ISR_STA_ACCEPT_IRQ_Msk     0x2UL
#define PPU_APPCPUSS_ISR_STA_DENY_IRQ_Pos       2UL
#define PPU_APPCPUSS_ISR_STA_DENY_IRQ_Msk       0x4UL
#define PPU_APPCPUSS_ISR_EMU_ACCEPT_IRQ_Pos     3UL
#define PPU_APPCPUSS_ISR_EMU_ACCEPT_IRQ_Msk     0x8UL
#define PPU_APPCPUSS_ISR_EMU_DENY_IRQ_Pos       4UL
#define PPU_APPCPUSS_ISR_EMU_DENY_IRQ_Msk       0x10UL
#define PPU_APPCPUSS_ISR_LOCKED_IRQ_Pos         5UL
#define PPU_APPCPUSS_ISR_LOCKED_IRQ_Msk         0x20UL
#define PPU_APPCPUSS_ISR_OTHER_IRQ_Pos          7UL
#define PPU_APPCPUSS_ISR_OTHER_IRQ_Msk          0x80UL
#define PPU_APPCPUSS_ISR_PWR_ACTIVE_EDGE_IRQ_Pos 8UL
#define PPU_APPCPUSS_ISR_PWR_ACTIVE_EDGE_IRQ_Msk 0x7FF00UL
#define PPU_APPCPUSS_ISR_OP_ACTIVE_EDGE_IRQ_Pos 24UL
#define PPU_APPCPUSS_ISR_OP_ACTIVE_EDGE_IRQ_Msk 0xFF000000UL
/* PPU_APPCPUSS.AISR */
#define PPU_APPCPUSS_AISR_UNSPT_POLICY_IRQ_Pos  0UL
#define PPU_APPCPUSS_AISR_UNSPT_POLICY_IRQ_Msk  0x1UL
#define PPU_APPCPUSS_AISR_DYN_ACCEPT_IRQ_Pos    1UL
#define PPU_APPCPUSS_AISR_DYN_ACCEPT_IRQ_Msk    0x2UL
#define PPU_APPCPUSS_AISR_DYN_DENY_IRQ_Pos      2UL
#define PPU_APPCPUSS_AISR_DYN_DENY_IRQ_Msk      0x4UL
#define PPU_APPCPUSS_AISR_STA_POLICY_PWR_IRQ_Pos 3UL
#define PPU_APPCPUSS_AISR_STA_POLICY_PWR_IRQ_Msk 0x8UL
#define PPU_APPCPUSS_AISR_STA_POLICY_OP_IRQ_Pos 4UL
#define PPU_APPCPUSS_AISR_STA_POLICY_OP_IRQ_Msk 0x10UL
/* PPU_APPCPUSS.IESR */
#define PPU_APPCPUSS_IESR_DEVACTIVE00_EDGE_Pos  0UL
#define PPU_APPCPUSS_IESR_DEVACTIVE00_EDGE_Msk  0x3UL
#define PPU_APPCPUSS_IESR_DEVACTIVE01_EDGE_Pos  2UL
#define PPU_APPCPUSS_IESR_DEVACTIVE01_EDGE_Msk  0xCUL
#define PPU_APPCPUSS_IESR_DEVACTIVE02_EDGE_Pos  4UL
#define PPU_APPCPUSS_IESR_DEVACTIVE02_EDGE_Msk  0x30UL
#define PPU_APPCPUSS_IESR_DEVACTIVE03_EDGE_Pos  6UL
#define PPU_APPCPUSS_IESR_DEVACTIVE03_EDGE_Msk  0xC0UL
#define PPU_APPCPUSS_IESR_DEVACTIVE04_EDGE_Pos  8UL
#define PPU_APPCPUSS_IESR_DEVACTIVE04_EDGE_Msk  0x300UL
#define PPU_APPCPUSS_IESR_DEVACTIVE05_EDGE_Pos  10UL
#define PPU_APPCPUSS_IESR_DEVACTIVE05_EDGE_Msk  0xC00UL
#define PPU_APPCPUSS_IESR_DEVACTIVE06_EDGE_Pos  12UL
#define PPU_APPCPUSS_IESR_DEVACTIVE06_EDGE_Msk  0x3000UL
#define PPU_APPCPUSS_IESR_DEVACTIVE07_EDGE_Pos  14UL
#define PPU_APPCPUSS_IESR_DEVACTIVE07_EDGE_Msk  0xC000UL
#define PPU_APPCPUSS_IESR_DEVACTIVE08_EDGE_Pos  16UL
#define PPU_APPCPUSS_IESR_DEVACTIVE08_EDGE_Msk  0x30000UL
#define PPU_APPCPUSS_IESR_DEVACTIVE09_EDGE_Pos  18UL
#define PPU_APPCPUSS_IESR_DEVACTIVE09_EDGE_Msk  0xC0000UL
#define PPU_APPCPUSS_IESR_DEVACTIVE10_EDGE_Pos  20UL
#define PPU_APPCPUSS_IESR_DEVACTIVE10_EDGE_Msk  0x300000UL
/* PPU_APPCPUSS.OPSR */
#define PPU_APPCPUSS_OPSR_DEVACTIVE16_EDGE_Pos  0UL
#define PPU_APPCPUSS_OPSR_DEVACTIVE16_EDGE_Msk  0x3UL
#define PPU_APPCPUSS_OPSR_DEVACTIVE17_EDGE_Pos  2UL
#define PPU_APPCPUSS_OPSR_DEVACTIVE17_EDGE_Msk  0xCUL
#define PPU_APPCPUSS_OPSR_DEVACTIVE18_EDGE_Pos  4UL
#define PPU_APPCPUSS_OPSR_DEVACTIVE18_EDGE_Msk  0x30UL
#define PPU_APPCPUSS_OPSR_DEVACTIVE19_EDGE_Pos  6UL
#define PPU_APPCPUSS_OPSR_DEVACTIVE19_EDGE_Msk  0xC0UL
#define PPU_APPCPUSS_OPSR_DEVACTIVE20_EDGE_Pos  8UL
#define PPU_APPCPUSS_OPSR_DEVACTIVE20_EDGE_Msk  0x300UL
#define PPU_APPCPUSS_OPSR_DEVACTIVE21_EDGE_Pos  10UL
#define PPU_APPCPUSS_OPSR_DEVACTIVE21_EDGE_Msk  0xC00UL
#define PPU_APPCPUSS_OPSR_DEVACTIVE22_EDGE_Pos  12UL
#define PPU_APPCPUSS_OPSR_DEVACTIVE22_EDGE_Msk  0x3000UL
#define PPU_APPCPUSS_OPSR_DEVACTIVE23_EDGE_Pos  14UL
#define PPU_APPCPUSS_OPSR_DEVACTIVE23_EDGE_Msk  0xC000UL
/* PPU_APPCPUSS.FUNRR */
#define PPU_APPCPUSS_FUNRR_FUNC_RET_RAM_CFG_Pos 0UL
#define PPU_APPCPUSS_FUNRR_FUNC_RET_RAM_CFG_Msk 0xFFUL
/* PPU_APPCPUSS.FULRR */
#define PPU_APPCPUSS_FULRR_FULL_RET_RAM_CFG_Pos 0UL
#define PPU_APPCPUSS_FULRR_FULL_RET_RAM_CFG_Msk 0xFFUL
/* PPU_APPCPUSS.MEMRR */
#define PPU_APPCPUSS_MEMRR_MEM_RET_RAM_CFG_Pos  0UL
#define PPU_APPCPUSS_MEMRR_MEM_RET_RAM_CFG_Msk  0xFFUL
/* PPU_APPCPUSS.EDTR0 */
#define PPU_APPCPUSS_EDTR0_OFF_DEL_Pos          0UL
#define PPU_APPCPUSS_EDTR0_OFF_DEL_Msk          0xFFUL
#define PPU_APPCPUSS_EDTR0_MEM_RET_DEL_Pos      8UL
#define PPU_APPCPUSS_EDTR0_MEM_RET_DEL_Msk      0xFF00UL
#define PPU_APPCPUSS_EDTR0_LOGIC_RET_DEL_Pos    16UL
#define PPU_APPCPUSS_EDTR0_LOGIC_RET_DEL_Msk    0xFF0000UL
#define PPU_APPCPUSS_EDTR0_FULL_RET_DEL_Pos     24UL
#define PPU_APPCPUSS_EDTR0_FULL_RET_DEL_Msk     0xFF000000UL
/* PPU_APPCPUSS.EDTR1 */
#define PPU_APPCPUSS_EDTR1_MEM_OFF_DEL_Pos      0UL
#define PPU_APPCPUSS_EDTR1_MEM_OFF_DEL_Msk      0xFFUL
#define PPU_APPCPUSS_EDTR1_FUNC_RET_DEL_Pos     8UL
#define PPU_APPCPUSS_EDTR1_FUNC_RET_DEL_Msk     0xFF00UL
/* PPU_APPCPUSS.DCDR0 */
#define PPU_APPCPUSS_DCDR0_CLKEN_RST_DLY_Pos    0UL
#define PPU_APPCPUSS_DCDR0_CLKEN_RST_DLY_Msk    0xFFUL
#define PPU_APPCPUSS_DCDR0_ISO_CLKEN_DLY_Pos    8UL
#define PPU_APPCPUSS_DCDR0_ISO_CLKEN_DLY_Msk    0xFF00UL
#define PPU_APPCPUSS_DCDR0_RST_HWSTAT_DLY_Pos   16UL
#define PPU_APPCPUSS_DCDR0_RST_HWSTAT_DLY_Msk   0xFF0000UL
/* PPU_APPCPUSS.DCDR1 */
#define PPU_APPCPUSS_DCDR1_ISO_RST_DLY_Pos      0UL
#define PPU_APPCPUSS_DCDR1_ISO_RST_DLY_Msk      0xFFUL
#define PPU_APPCPUSS_DCDR1_CLKEN_ISO_DLY_Pos    8UL
#define PPU_APPCPUSS_DCDR1_CLKEN_ISO_DLY_Msk    0xFF00UL
/* PPU_APPCPUSS.IDR0 */
#define PPU_APPCPUSS_IDR0_DEVCHAN_Pos           0UL
#define PPU_APPCPUSS_IDR0_DEVCHAN_Msk           0xFUL
#define PPU_APPCPUSS_IDR0_NUM_OPMODE_Pos        4UL
#define PPU_APPCPUSS_IDR0_NUM_OPMODE_Msk        0xF0UL
#define PPU_APPCPUSS_IDR0_STA_OFF_SPT_Pos       8UL
#define PPU_APPCPUSS_IDR0_STA_OFF_SPT_Msk       0x100UL
#define PPU_APPCPUSS_IDR0_STA_OFF_EMU_SPT_Pos   9UL
#define PPU_APPCPUSS_IDR0_STA_OFF_EMU_SPT_Msk   0x200UL
#define PPU_APPCPUSS_IDR0_STA_MEM_RET_SPT_Pos   10UL
#define PPU_APPCPUSS_IDR0_STA_MEM_RET_SPT_Msk   0x400UL
#define PPU_APPCPUSS_IDR0_STA_MEM_RET_EMU_SPT_Pos 11UL
#define PPU_APPCPUSS_IDR0_STA_MEM_RET_EMU_SPT_Msk 0x800UL
#define PPU_APPCPUSS_IDR0_STA_LGC_RET_SPT_Pos   12UL
#define PPU_APPCPUSS_IDR0_STA_LGC_RET_SPT_Msk   0x1000UL
#define PPU_APPCPUSS_IDR0_STA_MEM_OFF_SPT_Pos   13UL
#define PPU_APPCPUSS_IDR0_STA_MEM_OFF_SPT_Msk   0x2000UL
#define PPU_APPCPUSS_IDR0_STA_FULL_RET_SPT_Pos  14UL
#define PPU_APPCPUSS_IDR0_STA_FULL_RET_SPT_Msk  0x4000UL
#define PPU_APPCPUSS_IDR0_STA_FUNC_RET_SPT_Pos  15UL
#define PPU_APPCPUSS_IDR0_STA_FUNC_RET_SPT_Msk  0x8000UL
#define PPU_APPCPUSS_IDR0_STA_ON_SPT_Pos        16UL
#define PPU_APPCPUSS_IDR0_STA_ON_SPT_Msk        0x10000UL
#define PPU_APPCPUSS_IDR0_STA_WRM_RST_SPT_Pos   17UL
#define PPU_APPCPUSS_IDR0_STA_WRM_RST_SPT_Msk   0x20000UL
#define PPU_APPCPUSS_IDR0_STA_DBG_RECOV_SPT_Pos 18UL
#define PPU_APPCPUSS_IDR0_STA_DBG_RECOV_SPT_Msk 0x40000UL
#define PPU_APPCPUSS_IDR0_DYN_OFF_SPT_Pos       20UL
#define PPU_APPCPUSS_IDR0_DYN_OFF_SPT_Msk       0x100000UL
#define PPU_APPCPUSS_IDR0_DYN_OFF_EMU_SPT_Pos   21UL
#define PPU_APPCPUSS_IDR0_DYN_OFF_EMU_SPT_Msk   0x200000UL
#define PPU_APPCPUSS_IDR0_DYN_MEM_RET_SPT_Pos   22UL
#define PPU_APPCPUSS_IDR0_DYN_MEM_RET_SPT_Msk   0x400000UL
#define PPU_APPCPUSS_IDR0_DYN_MEM_RET_EMU_SPT_Pos 23UL
#define PPU_APPCPUSS_IDR0_DYN_MEM_RET_EMU_SPT_Msk 0x800000UL
#define PPU_APPCPUSS_IDR0_DYN_LGC_RET_SPT_Pos   24UL
#define PPU_APPCPUSS_IDR0_DYN_LGC_RET_SPT_Msk   0x1000000UL
#define PPU_APPCPUSS_IDR0_DYN_MEM_OFF_SPT_Pos   25UL
#define PPU_APPCPUSS_IDR0_DYN_MEM_OFF_SPT_Msk   0x2000000UL
#define PPU_APPCPUSS_IDR0_DYN_FULL_RET_SPT_Pos  26UL
#define PPU_APPCPUSS_IDR0_DYN_FULL_RET_SPT_Msk  0x4000000UL
#define PPU_APPCPUSS_IDR0_DYN_FUNC_RET_SPT_Pos  27UL
#define PPU_APPCPUSS_IDR0_DYN_FUNC_RET_SPT_Msk  0x8000000UL
#define PPU_APPCPUSS_IDR0_DYN_ON_SPT_Pos        28UL
#define PPU_APPCPUSS_IDR0_DYN_ON_SPT_Msk        0x10000000UL
#define PPU_APPCPUSS_IDR0_DYN_WRM_RST_SPT_Pos   29UL
#define PPU_APPCPUSS_IDR0_DYN_WRM_RST_SPT_Msk   0x20000000UL
/* PPU_APPCPUSS.IDR1 */
#define PPU_APPCPUSS_IDR1_PWR_MODE_ENTRY_DEL_SPT_Pos 0UL
#define PPU_APPCPUSS_IDR1_PWR_MODE_ENTRY_DEL_SPT_Msk 0x1UL
#define PPU_APPCPUSS_IDR1_SW_DEV_DEL_SPT_Pos    1UL
#define PPU_APPCPUSS_IDR1_SW_DEV_DEL_SPT_Msk    0x2UL
#define PPU_APPCPUSS_IDR1_LOCK_SPT_Pos          2UL
#define PPU_APPCPUSS_IDR1_LOCK_SPT_Msk          0x4UL
#define PPU_APPCPUSS_IDR1_MEM_RET_RAM_REG_Pos   4UL
#define PPU_APPCPUSS_IDR1_MEM_RET_RAM_REG_Msk   0x10UL
#define PPU_APPCPUSS_IDR1_FULL_RET_RAM_REG_Pos  5UL
#define PPU_APPCPUSS_IDR1_FULL_RET_RAM_REG_Msk  0x20UL
#define PPU_APPCPUSS_IDR1_FUNC_RET_RAM_REG_Pos  6UL
#define PPU_APPCPUSS_IDR1_FUNC_RET_RAM_REG_Msk  0x40UL
#define PPU_APPCPUSS_IDR1_STA_POLICY_PWR_IRQ_SPT_Pos 8UL
#define PPU_APPCPUSS_IDR1_STA_POLICY_PWR_IRQ_SPT_Msk 0x100UL
#define PPU_APPCPUSS_IDR1_STA_POLICY_OP_IRQ_SPT_Pos 9UL
#define PPU_APPCPUSS_IDR1_STA_POLICY_OP_IRQ_SPT_Msk 0x200UL
#define PPU_APPCPUSS_IDR1_OP_ACTIVE_Pos         10UL
#define PPU_APPCPUSS_IDR1_OP_ACTIVE_Msk         0x400UL
#define PPU_APPCPUSS_IDR1_OFF_MEM_RET_TRANS_Pos 12UL
#define PPU_APPCPUSS_IDR1_OFF_MEM_RET_TRANS_Msk 0x1000UL
/* PPU_APPCPUSS.IIDR */
#define PPU_APPCPUSS_IIDR_IMPLEMENTER_Pos       0UL
#define PPU_APPCPUSS_IIDR_IMPLEMENTER_Msk       0xFFFUL
#define PPU_APPCPUSS_IIDR_REVISION_Pos          12UL
#define PPU_APPCPUSS_IIDR_REVISION_Msk          0xF000UL
#define PPU_APPCPUSS_IIDR_VARIANT_Pos           16UL
#define PPU_APPCPUSS_IIDR_VARIANT_Msk           0xF0000UL
#define PPU_APPCPUSS_IIDR_PRODUCT_ID_Pos        20UL
#define PPU_APPCPUSS_IIDR_PRODUCT_ID_Msk        0xFFF00000UL
/* PPU_APPCPUSS.AIDR */
#define PPU_APPCPUSS_AIDR_ARCH_REV_MINOR_Pos    0UL
#define PPU_APPCPUSS_AIDR_ARCH_REV_MINOR_Msk    0xFUL
#define PPU_APPCPUSS_AIDR_ARCH_REV_MAJOR_Pos    4UL
#define PPU_APPCPUSS_AIDR_ARCH_REV_MAJOR_Msk    0xF0UL
/* PPU_APPCPUSS.PID4 */
#define PPU_APPCPUSS_PID4_IMPLEMENTER_11_8_Pos  0UL
#define PPU_APPCPUSS_PID4_IMPLEMENTER_11_8_Msk  0xFUL
/* PPU_APPCPUSS.PID0 */
#define PPU_APPCPUSS_PID0_PRODUCT_ID_7_0_Pos    0UL
#define PPU_APPCPUSS_PID0_PRODUCT_ID_7_0_Msk    0xFFUL
/* PPU_APPCPUSS.PID1 */
#define PPU_APPCPUSS_PID1_PRODUCT_ID_11_8_Pos   0UL
#define PPU_APPCPUSS_PID1_PRODUCT_ID_11_8_Msk   0xFUL
#define PPU_APPCPUSS_PID1_IMPLEMENTER_3_0_Pos   4UL
#define PPU_APPCPUSS_PID1_IMPLEMENTER_3_0_Msk   0xF0UL
/* PPU_APPCPUSS.PID2 */
#define PPU_APPCPUSS_PID2_IMPLEMENTER_6_4_Pos   0UL
#define PPU_APPCPUSS_PID2_IMPLEMENTER_6_4_Msk   0x7UL
#define PPU_APPCPUSS_PID2_CONST_HIGH_Pos        3UL
#define PPU_APPCPUSS_PID2_CONST_HIGH_Msk        0x8UL
#define PPU_APPCPUSS_PID2_REV_CONST_Pos         4UL
#define PPU_APPCPUSS_PID2_REV_CONST_Msk         0xF0UL
/* PPU_APPCPUSS.PID3 */
#define PPU_APPCPUSS_PID3_PID3_REV_CONST_Pos    0UL
#define PPU_APPCPUSS_PID3_PID3_REV_CONST_Msk    0xFUL
#define PPU_APPCPUSS_PID3_PID3_REVISION_Pos     4UL
#define PPU_APPCPUSS_PID3_PID3_REVISION_Msk     0xF0UL
/* PPU_APPCPUSS.ID0 */
#define PPU_APPCPUSS_ID0_ID0_Pos                0UL
#define PPU_APPCPUSS_ID0_ID0_Msk                0xFFUL
/* PPU_APPCPUSS.ID1 */
#define PPU_APPCPUSS_ID1_ID1_Pos                0UL
#define PPU_APPCPUSS_ID1_ID1_Msk                0xFFUL
/* PPU_APPCPUSS.ID2 */
#define PPU_APPCPUSS_ID2_ID2_Pos                0UL
#define PPU_APPCPUSS_ID2_ID2_Msk                0xFFUL
/* PPU_APPCPUSS.ID3 */
#define PPU_APPCPUSS_ID3_ID3_Pos                0UL
#define PPU_APPCPUSS_ID3_ID3_Msk                0xFFUL


#endif /* _CYIP_PPU_APPCPUSS_V1_1_H_ */


/* [] END OF FILE */
