/***************************************************************************//**
* \file cyip_pwm.h
*
* \brief
* PWM IP definitions
*
********************************************************************************
* \copyright
* (c) (2016-2024), Cypress Semiconductor Corporation (an Infineon company) or
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

#ifndef _CYIP_PWM_H_
#define _CYIP_PWM_H_

#include "cyip_headers.h"

/*******************************************************************************
*                                     PWM
*******************************************************************************/

#define PWM_TX_SECTION_SIZE                     0x00000100UL
#define PWM_SECTION_SIZE                        0x00010000UL

/**
  * \brief PWM structure (PWM_TX)
  */
typedef struct {
  __IOM uint32_t CTL;                           /*!< 0x00000000 Control */
   __IM uint32_t RESERVED[3];
  __IOM uint32_t IF_CTL;                        /*!< 0x00000010 Interface control */
  __IOM uint32_t DOUBLE_CTL;                    /*!< 0x00000014 Double control */
  __IOM uint32_t GAIN_CTL;                      /*!< 0x00000018 Gain control */
   __IM uint32_t RESERVED1;
  __IOM uint32_t PWM_CTL0;                      /*!< 0x00000020 PWM control 0 */
  __IOM uint32_t PWM_CTL1;                      /*!< 0x00000024 PWM control 1 */
  __IOM uint32_t PWM_CTL2;                      /*!< 0x00000028 PWM control 2 */
  __IOM uint32_t PWM_CTL3;                      /*!< 0x0000002C PWM control 3 */
   __IM uint32_t RESERVED2[20];
  __IOM uint32_t TX_FIFO_CTL;                   /*!< 0x00000080 TX FIFO control */
   __IM uint32_t TX_FIFO_STATUS;                /*!< 0x00000084 TX FIFO status */
   __OM uint32_t TX_FIFO_WR;                    /*!< 0x00000088 TX FIFO write */
   __IM uint32_t RESERVED3[13];
  __IOM uint32_t INTR_TX;                       /*!< 0x000000C0 Interrupt */
  __IOM uint32_t INTR_TX_SET;                   /*!< 0x000000C4 Interrupt set */
  __IOM uint32_t INTR_TX_MASK;                  /*!< 0x000000C8 Interrupt mask */
   __IM uint32_t INTR_TX_MASKED;                /*!< 0x000000CC Interrupt masked */
   __IM uint32_t RESERVED4[12];
} PWM_TX_Type;                                  /*!< Size = 256 (0x100) */

/**
  * \brief PWM (PWM)
  */
typedef struct {
  __IOM uint32_t CTL;                           /*!< 0x00000000 Control */
  __IOM uint32_t CTL_CLR;                       /*!< 0x00000004 Control clear */
  __IOM uint32_t CTL_SET;                       /*!< 0x00000008 Control set */
   __IM uint32_t RESERVED[8189];
        PWM_TX_Type TX[8];                      /*!< 0x00008000 PWM structure */
} PWM_Type;                                     /*!< Size = 34816 (0x8800) */


/* PWM_TX.CTL */
#define PWM_TX_CTL_WORD_SIZE_Pos                0UL
#define PWM_TX_CTL_WORD_SIZE_Msk                0xFUL
#define PWM_TX_CTL_ENABLED_Pos                  31UL
#define PWM_TX_CTL_ENABLED_Msk                  0x80000000UL
/* PWM_TX.IF_CTL */
#define PWM_TX_IF_CTL_CLOCK_DIV_Pos             0UL
#define PWM_TX_IF_CTL_CLOCK_DIV_Msk             0xFFUL
#define PWM_TX_IF_CTL_CLOCK_SEL_Pos             8UL
#define PWM_TX_IF_CTL_CLOCK_SEL_Msk             0x700UL
#define PWM_TX_IF_CTL_LINE_POLARITY_Pos         12UL
#define PWM_TX_IF_CTL_LINE_POLARITY_Msk         0xF000UL
/* PWM_TX.DOUBLE_CTL */
#define PWM_TX_DOUBLE_CTL_MODE_Pos              0UL
#define PWM_TX_DOUBLE_CTL_MODE_Msk              0x1UL
#define PWM_TX_DOUBLE_CTL_ENABLED_Pos           31UL
#define PWM_TX_DOUBLE_CTL_ENABLED_Msk           0x80000000UL
/* PWM_TX.GAIN_CTL */
#define PWM_TX_GAIN_CTL_CODE_Pos                0UL
#define PWM_TX_GAIN_CTL_CODE_Msk                0x7FUL
/* PWM_TX.PWM_CTL0 */
#define PWM_TX_PWM_CTL0_FORMAT_Pos              0UL
#define PWM_TX_PWM_CTL0_FORMAT_Msk              0x3UL
#define PWM_TX_PWM_CTL0_SCALE_Pos               16UL
#define PWM_TX_PWM_CTL0_SCALE_Msk               0xF0000UL
/* PWM_TX.PWM_CTL1 */
#define PWM_TX_PWM_CTL1_MIN_Pos                 0UL
#define PWM_TX_PWM_CTL1_MIN_Msk                 0xFFFFUL
#define PWM_TX_PWM_CTL1_MAX_Pos                 16UL
#define PWM_TX_PWM_CTL1_MAX_Msk                 0xFFFF0000UL
/* PWM_TX.PWM_CTL2 */
#define PWM_TX_PWM_CTL2_PERIOD_Pos              0UL
#define PWM_TX_PWM_CTL2_PERIOD_Msk              0xFFFFUL
#define PWM_TX_PWM_CTL2_OFFSET_Pos              16UL
#define PWM_TX_PWM_CTL2_OFFSET_Msk              0xFFFF0000UL
/* PWM_TX.PWM_CTL3 */
#define PWM_TX_PWM_CTL3_DT_Pos                  0UL
#define PWM_TX_PWM_CTL3_DT_Msk                  0xFFFFUL
/* PWM_TX.TX_FIFO_CTL */
#define PWM_TX_TX_FIFO_CTL_TRIGGER_LEVEL_Pos    0UL
#define PWM_TX_TX_FIFO_CTL_TRIGGER_LEVEL_Msk    0x3FUL
#define PWM_TX_TX_FIFO_CTL_MUTE_Pos             16UL
#define PWM_TX_TX_FIFO_CTL_MUTE_Msk             0x10000UL
#define PWM_TX_TX_FIFO_CTL_FREEZE_Pos           17UL
#define PWM_TX_TX_FIFO_CTL_FREEZE_Msk           0x20000UL
/* PWM_TX.TX_FIFO_STATUS */
#define PWM_TX_TX_FIFO_STATUS_USED_Pos          0UL
#define PWM_TX_TX_FIFO_STATUS_USED_Msk          0x7FUL
#define PWM_TX_TX_FIFO_STATUS_RD_PTR_Pos        16UL
#define PWM_TX_TX_FIFO_STATUS_RD_PTR_Msk        0x3F0000UL
#define PWM_TX_TX_FIFO_STATUS_WR_PTR_Pos        24UL
#define PWM_TX_TX_FIFO_STATUS_WR_PTR_Msk        0x3F000000UL
/* PWM_TX.TX_FIFO_WR */
#define PWM_TX_TX_FIFO_WR_DATA_Pos              0UL
#define PWM_TX_TX_FIFO_WR_DATA_Msk              0xFFFFFFFFUL
/* PWM_TX.INTR_TX */
#define PWM_TX_INTR_TX_FIFO_TRIGGER_Pos         0UL
#define PWM_TX_INTR_TX_FIFO_TRIGGER_Msk         0x1UL
#define PWM_TX_INTR_TX_FIFO_OVERFLOW_Pos        1UL
#define PWM_TX_INTR_TX_FIFO_OVERFLOW_Msk        0x2UL
#define PWM_TX_INTR_TX_FIFO_UNDERFLOW_Pos       2UL
#define PWM_TX_INTR_TX_FIFO_UNDERFLOW_Msk       0x4UL
#define PWM_TX_INTR_TX_IF_UNDERFLOW_Pos         8UL
#define PWM_TX_INTR_TX_IF_UNDERFLOW_Msk         0x100UL
/* PWM_TX.INTR_TX_SET */
#define PWM_TX_INTR_TX_SET_FIFO_TRIGGER_Pos     0UL
#define PWM_TX_INTR_TX_SET_FIFO_TRIGGER_Msk     0x1UL
#define PWM_TX_INTR_TX_SET_FIFO_OVERFLOW_Pos    1UL
#define PWM_TX_INTR_TX_SET_FIFO_OVERFLOW_Msk    0x2UL
#define PWM_TX_INTR_TX_SET_FIFO_UNDERFLOW_Pos   2UL
#define PWM_TX_INTR_TX_SET_FIFO_UNDERFLOW_Msk   0x4UL
#define PWM_TX_INTR_TX_SET_IF_UNDERFLOW_Pos     8UL
#define PWM_TX_INTR_TX_SET_IF_UNDERFLOW_Msk     0x100UL
/* PWM_TX.INTR_TX_MASK */
#define PWM_TX_INTR_TX_MASK_FIFO_TRIGGER_Pos    0UL
#define PWM_TX_INTR_TX_MASK_FIFO_TRIGGER_Msk    0x1UL
#define PWM_TX_INTR_TX_MASK_FIFO_OVERFLOW_Pos   1UL
#define PWM_TX_INTR_TX_MASK_FIFO_OVERFLOW_Msk   0x2UL
#define PWM_TX_INTR_TX_MASK_FIFO_UNDERFLOW_Pos  2UL
#define PWM_TX_INTR_TX_MASK_FIFO_UNDERFLOW_Msk  0x4UL
#define PWM_TX_INTR_TX_MASK_IF_UNDERFLOW_Pos    8UL
#define PWM_TX_INTR_TX_MASK_IF_UNDERFLOW_Msk    0x100UL
/* PWM_TX.INTR_TX_MASKED */
#define PWM_TX_INTR_TX_MASKED_FIFO_TRIGGER_Pos  0UL
#define PWM_TX_INTR_TX_MASKED_FIFO_TRIGGER_Msk  0x1UL
#define PWM_TX_INTR_TX_MASKED_FIFO_OVERFLOW_Pos 1UL
#define PWM_TX_INTR_TX_MASKED_FIFO_OVERFLOW_Msk 0x2UL
#define PWM_TX_INTR_TX_MASKED_FIFO_UNDERFLOW_Pos 2UL
#define PWM_TX_INTR_TX_MASKED_FIFO_UNDERFLOW_Msk 0x4UL
#define PWM_TX_INTR_TX_MASKED_IF_UNDERFLOW_Pos  8UL
#define PWM_TX_INTR_TX_MASKED_IF_UNDERFLOW_Msk  0x100UL


/* PWM.CTL */
#define PWM_CTL_ACTIVE_Pos                      0UL
#define PWM_CTL_ACTIVE_Msk                      0xFFUL
/* PWM.CTL_CLR */
#define PWM_CTL_CLR_ACTIVE_Pos                  0UL
#define PWM_CTL_CLR_ACTIVE_Msk                  0xFFUL
/* PWM.CTL_SET */
#define PWM_CTL_SET_ACTIVE_Pos                  0UL
#define PWM_CTL_SET_ACTIVE_Msk                  0xFFUL


#endif /* _CYIP_PWM_H_ */


/* [] END OF FILE */
