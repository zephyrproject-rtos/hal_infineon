/***************************************************************************//**
* \file cyip_mca.h
*
* \brief
* MCA IP definitions
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

#ifndef _CYIP_MCA_H_
#define _CYIP_MCA_H_

#include "cyip_headers.h"

/*******************************************************************************
*                                     MCA
*******************************************************************************/

#define MCA_SECTION_SIZE                        0x00001000UL

/**
  * \brief Motor Control Accellerator (MCA)
  */
typedef struct {
  __IOM uint32_t CONFIG;                        /*!< 0x00000000 IP Configuration Register */
  __IOM uint32_t CTL;                           /*!< 0x00000004 IP Control Register */
   __IM uint32_t STAT;                          /*!< 0x00000008 IP Status Register */
   __IM uint32_t RESERVED;
  __IOM uint32_t DIV_DIVIDEND;                  /*!< 0x00000010 32 bit Dividend */
  __IOM uint32_t DIV_DIVISOR;                   /*!< 0x00000014 32 bit Divisor */
   __IM uint32_t DIV_QUOTIENT;                  /*!< 0x00000018 32 bit Quotient */
   __IM uint32_t DIV_REMAINDER;                 /*!< 0x0000001C 32 bit Remainder */
  __IOM uint32_t SQRT_RADICAND;                 /*!< 0x00000020 Square Root Source Value */
   __IM uint32_t SQRT_ROOT;                     /*!< 0x00000024 Square Root Result */
} MCA_Type;                                     /*!< Size = 40 (0x28) */


/* MCA.CONFIG */
#define MCA_CONFIG_BLOCK_Pos                    0UL
#define MCA_CONFIG_BLOCK_Msk                    0x1UL
#define MCA_CONFIG_ENABLED_Pos                  31UL
#define MCA_CONFIG_ENABLED_Msk                  0x80000000UL
/* MCA.CTL */
#define MCA_CTL_START_DIVIDE_LEVEL_Pos          0UL
#define MCA_CTL_START_DIVIDE_LEVEL_Msk          0x1UL
#define MCA_CTL_START_DIVIDE_PULSE_Pos          1UL
#define MCA_CTL_START_DIVIDE_PULSE_Msk          0x2UL
#define MCA_CTL_HOLD_DIVIDE_Pos                 2UL
#define MCA_CTL_HOLD_DIVIDE_Msk                 0x4UL
#define MCA_CTL_START_SQRT_LEVEL_Pos            4UL
#define MCA_CTL_START_SQRT_LEVEL_Msk            0x10UL
#define MCA_CTL_START_SQRT_PULSE_Pos            5UL
#define MCA_CTL_START_SQRT_PULSE_Msk            0x20UL
#define MCA_CTL_HOLD_SQRT_Pos                   6UL
#define MCA_CTL_HOLD_SQRT_Msk                   0x40UL
/* MCA.STAT */
#define MCA_STAT_DIVIDE_COMPLETE_Pos            0UL
#define MCA_STAT_DIVIDE_COMPLETE_Msk            0x1UL
#define MCA_STAT_DIVIDE_BY_0_Pos                1UL
#define MCA_STAT_DIVIDE_BY_0_Msk                0x2UL
#define MCA_STAT_SQRT_COMPLETE_Pos              4UL
#define MCA_STAT_SQRT_COMPLETE_Msk              0x10UL
/* MCA.DIV_DIVIDEND */
#define MCA_DIV_DIVIDEND_DIVIDEND_Pos           0UL
#define MCA_DIV_DIVIDEND_DIVIDEND_Msk           0xFFFFFFFFUL
/* MCA.DIV_DIVISOR */
#define MCA_DIV_DIVISOR_DIVISOR_Pos             0UL
#define MCA_DIV_DIVISOR_DIVISOR_Msk             0xFFFFFFFFUL
/* MCA.DIV_QUOTIENT */
#define MCA_DIV_QUOTIENT_QUOTIENT_Pos           0UL
#define MCA_DIV_QUOTIENT_QUOTIENT_Msk           0xFFFFFFFFUL
/* MCA.DIV_REMAINDER */
#define MCA_DIV_REMAINDER_REMAINDER_Pos         0UL
#define MCA_DIV_REMAINDER_REMAINDER_Msk         0xFFFFFFFFUL
/* MCA.SQRT_RADICAND */
#define MCA_SQRT_RADICAND_RADICAND_Pos          0UL
#define MCA_SQRT_RADICAND_RADICAND_Msk          0xFFFFFFFFUL
/* MCA.SQRT_ROOT */
#define MCA_SQRT_ROOT_ROOT_Pos                  0UL
#define MCA_SQRT_ROOT_ROOT_Msk                  0xFFFFUL


#endif /* _CYIP_MCA_H_ */


/* [] END OF FILE */
