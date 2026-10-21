/***************************************************************************//**
* \file cyip_pass_v2.h
*
* \brief
* PASS IP definitions
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

#ifndef _CYIP_PASS_V2_H_
#define _CYIP_PASS_V2_H_

#include "cyip_headers.h"

/*******************************************************************************
*                                     PASS
*******************************************************************************/

#define PASS_DSAB_SECTION_SIZE                  0x00000100UL
#define PASS_SECTION_SIZE                       0x00010000UL

/**
  * \brief DSAB configuration (PASS_DSAB)
  */
typedef struct {
  __IOM uint32_t DSAB_CTRL;                     /*!< 0x00000000 global DSAB control */
  __IOM uint32_t DSAB_DFT;                      /*!< 0x00000004 DFT bits */
   __IM uint32_t RESERVED[62];
} PASS_DSAB_Type;                               /*!< Size = 256 (0x100) */

/**
  * \brief PASS top-level MMIO (DSABv2, INTR) (PASS)
  */
typedef struct {
   __IM uint32_t INTR_CAUSE;                    /*!< 0x00000000 Interrupt cause register */
   __IM uint32_t RESERVED[11];
  __IOM uint32_t DFT_CTRL;                      /*!< 0x00000030 DFT control register */
   __IM uint32_t RESERVED1[53];
  __IOM uint32_t PASS_CTRL;                     /*!< 0x00000108 PASS Control */
   __IM uint32_t RESERVED2[829];
        PASS_DSAB_Type DSAB;                    /*!< 0x00000E00 DSAB configuration */
  __IOM uint32_t DSAB_TRIM;                     /*!< 0x00000F00 DSAB Trim bits */
} PASS_Type;                                    /*!< Size = 3844 (0xF04) */


/* PASS_DSAB.DSAB_CTRL */
#define PASS_DSAB_DSAB_CTRL_CURRENT_SEL_Pos     0UL
#define PASS_DSAB_DSAB_CTRL_CURRENT_SEL_Msk     0x3FUL
#define PASS_DSAB_DSAB_CTRL_SEL_OUT_Pos         8UL
#define PASS_DSAB_DSAB_CTRL_SEL_OUT_Msk         0xF00UL
#define PASS_DSAB_DSAB_CTRL_REF_SWAP_EN_Pos     16UL
#define PASS_DSAB_DSAB_CTRL_REF_SWAP_EN_Msk     0xF0000UL
#define PASS_DSAB_DSAB_CTRL_BYPASS_MODE_EN_Pos  24UL
#define PASS_DSAB_DSAB_CTRL_BYPASS_MODE_EN_Msk  0x1000000UL
#define PASS_DSAB_DSAB_CTRL_STARTUP_RM_Pos      28UL
#define PASS_DSAB_DSAB_CTRL_STARTUP_RM_Msk      0x10000000UL
#define PASS_DSAB_DSAB_CTRL_ENABLED_Pos         31UL
#define PASS_DSAB_DSAB_CTRL_ENABLED_Msk         0x80000000UL
/* PASS_DSAB.DSAB_DFT */
#define PASS_DSAB_DSAB_DFT_EN_DFT_Pos           0UL
#define PASS_DSAB_DSAB_DFT_EN_DFT_Msk           0xFUL


/* PASS.INTR_CAUSE */
#define PASS_INTR_CAUSE_CTB0_INT_Pos            0UL
#define PASS_INTR_CAUSE_CTB0_INT_Msk            0x1UL
#define PASS_INTR_CAUSE_CTB1_INT_Pos            1UL
#define PASS_INTR_CAUSE_CTB1_INT_Msk            0x2UL
#define PASS_INTR_CAUSE_CTB2_INT_Pos            2UL
#define PASS_INTR_CAUSE_CTB2_INT_Msk            0x4UL
#define PASS_INTR_CAUSE_CTB3_INT_Pos            3UL
#define PASS_INTR_CAUSE_CTB3_INT_Msk            0x8UL
/* PASS.DFT_CTRL */
#define PASS_DFT_CTRL_DSAB_ADFT_RES_EN_Pos      0UL
#define PASS_DFT_CTRL_DSAB_ADFT_RES_EN_Msk      0x1UL
/* PASS.PASS_CTRL */
#define PASS_PASS_CTRL_PMPCLK_BYP_Pos           0UL
#define PASS_PASS_CTRL_PMPCLK_BYP_Msk           0x1UL
#define PASS_PASS_CTRL_PMPCLK_SRC_Pos           1UL
#define PASS_PASS_CTRL_PMPCLK_SRC_Msk           0x2UL
#define PASS_PASS_CTRL_RMB_BITS_Pos             8UL
#define PASS_PASS_CTRL_RMB_BITS_Msk             0xFF00UL
/* PASS.DSAB_TRIM */
#define PASS_DSAB_TRIM_IBIAS_TRIM_Pos           0UL
#define PASS_DSAB_TRIM_IBIAS_TRIM_Msk           0xFUL
#define PASS_DSAB_TRIM_DSAB_RMB_BITS_Pos        4UL
#define PASS_DSAB_TRIM_DSAB_RMB_BITS_Msk        0x30UL


#endif /* _CYIP_PASS_V2_H_ */


/* [] END OF FILE */
