/***************************************************************************//**
* \file cyip_peri.h
*
* \brief
* PERI IP definitions
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

#ifndef _CYIP_PERI_H_
#define _CYIP_PERI_H_

#include "cyip_headers.h"

/*******************************************************************************
*                                     PERI
*******************************************************************************/

#define PERI_TR_GROUP_SECTION_SIZE              0x00000200UL
#define PERI_SECTION_SIZE                       0x00010000UL

/**
  * \brief Peripheral Interconnect trigger group control registers (PERI_TR_GROUP)
  */
typedef struct {
  __IOM uint32_t TR_OUT_CTL[128];               /*!< 0x00000000 Trigger control register */
} PERI_TR_GROUP_Type;                           /*!< Size = 512 (0x200) */

/**
  * \brief Peripheral Interconnect (PERI)
  */
typedef struct {
  __IOM uint32_t DIV_CMD;                       /*!< 0x00000000 Divider command register */
   __IM uint32_t RESERVED[63];
  __IOM uint32_t PCLK_CTL[64];                  /*!< 0x00000100 Programmable clock control register */
  __IOM uint32_t DIV_8_CTL[64];                 /*!< 0x00000200 Divider control register (for 8.0 divider) */
  __IOM uint32_t DIV_16_CTL[64];                /*!< 0x00000300 Divider control register (for 16.0 divider) */
  __IOM uint32_t DIV_16_5_CTL[64];              /*!< 0x00000400 Divider control register (for 16.5 divider) */
  __IOM uint32_t DIV_24_5_CTL[63];              /*!< 0x00000500 Divider control register (for 24.5 divider) */
   __IM uint32_t RESERVED1;
  __IOM uint32_t TR_CTL;                        /*!< 0x00000600 Trigger control register */
   __IM uint32_t RESERVED2[1663];
        PERI_TR_GROUP_Type TR_GROUP[16];        /*!< 0x00002000 Peripheral Interconnect trigger group control registers */
} PERI_Type;                                    /*!< Size = 16384 (0x4000) */


/* PERI_TR_GROUP.TR_OUT_CTL */
#define PERI_TR_GROUP_TR_OUT_CTL_SEL_Pos        0UL
#define PERI_TR_GROUP_TR_OUT_CTL_SEL_Msk        0x7FUL


/* PERI.DIV_CMD */
#define PERI_DIV_CMD_SEL_DIV_Pos                0UL
#define PERI_DIV_CMD_SEL_DIV_Msk                0x3FUL
#define PERI_DIV_CMD_SEL_TYPE_Pos               6UL
#define PERI_DIV_CMD_SEL_TYPE_Msk               0xC0UL
#define PERI_DIV_CMD_PA_SEL_DIV_Pos             8UL
#define PERI_DIV_CMD_PA_SEL_DIV_Msk             0x3F00UL
#define PERI_DIV_CMD_PA_SEL_TYPE_Pos            14UL
#define PERI_DIV_CMD_PA_SEL_TYPE_Msk            0xC000UL
#define PERI_DIV_CMD_DISABLE_Pos                30UL
#define PERI_DIV_CMD_DISABLE_Msk                0x40000000UL
#define PERI_DIV_CMD_ENABLE_Pos                 31UL
#define PERI_DIV_CMD_ENABLE_Msk                 0x80000000UL
/* PERI.PCLK_CTL */
#define PERI_PCLK_CTL_SEL_DIV_Pos               0UL
#define PERI_PCLK_CTL_SEL_DIV_Msk               0x3FUL
#define PERI_PCLK_CTL_SEL_TYPE_Pos              6UL
#define PERI_PCLK_CTL_SEL_TYPE_Msk              0xC0UL
/* PERI.DIV_8_CTL */
#define PERI_DIV_8_CTL_EN_Pos                   0UL
#define PERI_DIV_8_CTL_EN_Msk                   0x1UL
#define PERI_DIV_8_CTL_INT8_DIV_Pos             8UL
#define PERI_DIV_8_CTL_INT8_DIV_Msk             0xFF00UL
/* PERI.DIV_16_CTL */
#define PERI_DIV_16_CTL_EN_Pos                  0UL
#define PERI_DIV_16_CTL_EN_Msk                  0x1UL
#define PERI_DIV_16_CTL_INT16_DIV_Pos           8UL
#define PERI_DIV_16_CTL_INT16_DIV_Msk           0xFFFF00UL
/* PERI.DIV_16_5_CTL */
#define PERI_DIV_16_5_CTL_EN_Pos                0UL
#define PERI_DIV_16_5_CTL_EN_Msk                0x1UL
#define PERI_DIV_16_5_CTL_FRAC5_DIV_Pos         3UL
#define PERI_DIV_16_5_CTL_FRAC5_DIV_Msk         0xF8UL
#define PERI_DIV_16_5_CTL_INT16_DIV_Pos         8UL
#define PERI_DIV_16_5_CTL_INT16_DIV_Msk         0xFFFF00UL
/* PERI.DIV_24_5_CTL */
#define PERI_DIV_24_5_CTL_EN_Pos                0UL
#define PERI_DIV_24_5_CTL_EN_Msk                0x1UL
#define PERI_DIV_24_5_CTL_FRAC5_DIV_Pos         3UL
#define PERI_DIV_24_5_CTL_FRAC5_DIV_Msk         0xF8UL
#define PERI_DIV_24_5_CTL_INT24_DIV_Pos         8UL
#define PERI_DIV_24_5_CTL_INT24_DIV_Msk         0xFFFFFF00UL
/* PERI.TR_CTL */
#define PERI_TR_CTL_TR_SEL_Pos                  0UL
#define PERI_TR_CTL_TR_SEL_Msk                  0x7FUL
#define PERI_TR_CTL_TR_GROUP_Pos                8UL
#define PERI_TR_CTL_TR_GROUP_Msk                0xF00UL
#define PERI_TR_CTL_TR_COUNT_Pos                16UL
#define PERI_TR_CTL_TR_COUNT_Msk                0xFF0000UL
#define PERI_TR_CTL_TR_OUT_Pos                  30UL
#define PERI_TR_CTL_TR_OUT_Msk                  0x40000000UL
#define PERI_TR_CTL_TR_ACT_Pos                  31UL
#define PERI_TR_CTL_TR_ACT_Msk                  0x80000000UL


#endif /* _CYIP_PERI_H_ */


/* [] END OF FILE */
