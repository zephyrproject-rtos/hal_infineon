/***************************************************************************//**
* \file cyip_dac.h
*
* \brief
* DAC IP definitions
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

#ifndef _CYIP_DAC_H_
#define _CYIP_DAC_H_

#include "cyip_headers.h"

/*******************************************************************************
*                                     DAC
*******************************************************************************/

#define DAC_SECTION_SIZE                        0x00000100UL

/**
  * \brief DAC (DAC)
  */
typedef struct {
  __IOM uint32_t CTL;                           /*!< 0x00000000 Control */
  __IOM uint32_t IF_CTL;                        /*!< 0x00000004 Interface Control */
  __IOM uint32_t COUNT;                         /*!< 0x00000008 Count */
   __IM uint32_t RESERVED;
   __IM uint32_t STATUS;                        /*!< 0x00000010 Status */
   __IM uint32_t RESERVED1[27];
  __IOM uint32_t TX_FIFO_CTL;                   /*!< 0x00000080 TX FIFO control */
   __IM uint32_t TX_FIFO_STATUS;                /*!< 0x00000084 TX FIFO status */
   __OM uint32_t TX_FIFO_WR;                    /*!< 0x00000088 TX FIFO write */
   __IM uint32_t RESERVED2[13];
  __IOM uint32_t INTR_TX;                       /*!< 0x000000C0 Interrupt */
  __IOM uint32_t INTR_TX_SET;                   /*!< 0x000000C4 Interrupt set */
  __IOM uint32_t INTR_TX_MASK;                  /*!< 0x000000C8 Interrupt mask */
   __IM uint32_t INTR_TX_MASKED;                /*!< 0x000000CC Interrupt masked */
} DAC_Type;                                     /*!< Size = 208 (0xD0) */


/* DAC.CTL */
#define DAC_CTL_ENABLED_Pos                     31UL
#define DAC_CTL_ENABLED_Msk                     0x80000000UL
/* DAC.IF_CTL */
#define DAC_IF_CTL_CLOCK_DIV_Pos                0UL
#define DAC_IF_CTL_CLOCK_DIV_Msk                0xFFUL
#define DAC_IF_CTL_CLOCK_SEL_Pos                8UL
#define DAC_IF_CTL_CLOCK_SEL_Msk                0x700UL
#define DAC_IF_CTL_FS_SEL_Pos                   16UL
#define DAC_IF_CTL_FS_SEL_Msk                   0x30000UL
#define DAC_IF_CTL_LDATA_POLARITY_Pos           24UL
#define DAC_IF_CTL_LDATA_POLARITY_Msk           0x1000000UL
#define DAC_IF_CTL_RDATA_POLARITY_Pos           25UL
#define DAC_IF_CTL_RDATA_POLARITY_Msk           0x2000000UL
#define DAC_IF_CTL_LDATA_SEL_Pos                26UL
#define DAC_IF_CTL_LDATA_SEL_Msk                0x4000000UL
#define DAC_IF_CTL_RDATA_SEL_Pos                27UL
#define DAC_IF_CTL_RDATA_SEL_Msk                0x8000000UL
#define DAC_IF_CTL_SW_OVERRIDE_FAST_RAMP_EN_Pos 30UL
#define DAC_IF_CTL_SW_OVERRIDE_FAST_RAMP_EN_Msk 0x40000000UL
#define DAC_IF_CTL_DAC_EN_Pos                   31UL
#define DAC_IF_CTL_DAC_EN_Msk                   0x80000000UL
/* DAC.COUNT */
#define DAC_COUNT_COUNT_1MS_Pos                 0UL
#define DAC_COUNT_COUNT_1MS_Msk                 0xFFFFUL
#define DAC_COUNT_FAST_RAMP_COUNT_IN_MS_Pos     16UL
#define DAC_COUNT_FAST_RAMP_COUNT_IN_MS_Msk     0xFF0000UL
#define DAC_COUNT_COMP_RAMP_COUNT_IN_MS_Pos     24UL
#define DAC_COUNT_COMP_RAMP_COUNT_IN_MS_Msk     0xFF000000UL
/* DAC.STATUS */
#define DAC_STATUS_DAC_BUSY_Pos                 0UL
#define DAC_STATUS_DAC_BUSY_Msk                 0x1UL
#define DAC_STATUS_FAST_RAMP_DONE_Pos           16UL
#define DAC_STATUS_FAST_RAMP_DONE_Msk           0x10000UL
#define DAC_STATUS_COMP_RAMP_DONE_Pos           17UL
#define DAC_STATUS_COMP_RAMP_DONE_Msk           0x20000UL
/* DAC.TX_FIFO_CTL */
#define DAC_TX_FIFO_CTL_TRIGGER_LEVEL_Pos       0UL
#define DAC_TX_FIFO_CTL_TRIGGER_LEVEL_Msk       0x3FUL
#define DAC_TX_FIFO_CTL_MUTE_Pos                16UL
#define DAC_TX_FIFO_CTL_MUTE_Msk                0x10000UL
#define DAC_TX_FIFO_CTL_FREEZE_Pos              17UL
#define DAC_TX_FIFO_CTL_FREEZE_Msk              0x20000UL
#define DAC_TX_FIFO_CTL_ACTIVE_Pos              18UL
#define DAC_TX_FIFO_CTL_ACTIVE_Msk              0x40000UL
/* DAC.TX_FIFO_STATUS */
#define DAC_TX_FIFO_STATUS_USED_Pos             0UL
#define DAC_TX_FIFO_STATUS_USED_Msk             0x7FUL
#define DAC_TX_FIFO_STATUS_RD_PTR_Pos           16UL
#define DAC_TX_FIFO_STATUS_RD_PTR_Msk           0x3F0000UL
#define DAC_TX_FIFO_STATUS_WR_PTR_Pos           24UL
#define DAC_TX_FIFO_STATUS_WR_PTR_Msk           0x3F000000UL
/* DAC.TX_FIFO_WR */
#define DAC_TX_FIFO_WR_DATA_Pos                 0UL
#define DAC_TX_FIFO_WR_DATA_Msk                 0xFFFFFFFFUL
/* DAC.INTR_TX */
#define DAC_INTR_TX_FIFO_TRIGGER_Pos            0UL
#define DAC_INTR_TX_FIFO_TRIGGER_Msk            0x1UL
#define DAC_INTR_TX_FIFO_OVERFLOW_Pos           1UL
#define DAC_INTR_TX_FIFO_OVERFLOW_Msk           0x2UL
#define DAC_INTR_TX_FIFO_UNDERFLOW_Pos          2UL
#define DAC_INTR_TX_FIFO_UNDERFLOW_Msk          0x4UL
#define DAC_INTR_TX_FAST_RAMP_COMPLETE_Pos      16UL
#define DAC_INTR_TX_FAST_RAMP_COMPLETE_Msk      0x10000UL
#define DAC_INTR_TX_RAMP_COMPLETE_Pos           17UL
#define DAC_INTR_TX_RAMP_COMPLETE_Msk           0x20000UL
/* DAC.INTR_TX_SET */
#define DAC_INTR_TX_SET_FIFO_TRIGGER_Pos        0UL
#define DAC_INTR_TX_SET_FIFO_TRIGGER_Msk        0x1UL
#define DAC_INTR_TX_SET_FIFO_OVERFLOW_Pos       1UL
#define DAC_INTR_TX_SET_FIFO_OVERFLOW_Msk       0x2UL
#define DAC_INTR_TX_SET_FIFO_UNDERFLOW_Pos      2UL
#define DAC_INTR_TX_SET_FIFO_UNDERFLOW_Msk      0x4UL
#define DAC_INTR_TX_SET_FAST_RAMP_COMPLETE_Pos  16UL
#define DAC_INTR_TX_SET_FAST_RAMP_COMPLETE_Msk  0x10000UL
#define DAC_INTR_TX_SET_RAMP_COMPLETE_Pos       17UL
#define DAC_INTR_TX_SET_RAMP_COMPLETE_Msk       0x20000UL
/* DAC.INTR_TX_MASK */
#define DAC_INTR_TX_MASK_FIFO_TRIGGER_Pos       0UL
#define DAC_INTR_TX_MASK_FIFO_TRIGGER_Msk       0x1UL
#define DAC_INTR_TX_MASK_FIFO_OVERFLOW_Pos      1UL
#define DAC_INTR_TX_MASK_FIFO_OVERFLOW_Msk      0x2UL
#define DAC_INTR_TX_MASK_FIFO_UNDERFLOW_Pos     2UL
#define DAC_INTR_TX_MASK_FIFO_UNDERFLOW_Msk     0x4UL
#define DAC_INTR_TX_MASK_FAST_RAMP_COMPLETE_Pos 16UL
#define DAC_INTR_TX_MASK_FAST_RAMP_COMPLETE_Msk 0x10000UL
#define DAC_INTR_TX_MASK_RAMP_COMPLETE_Pos      17UL
#define DAC_INTR_TX_MASK_RAMP_COMPLETE_Msk      0x20000UL
/* DAC.INTR_TX_MASKED */
#define DAC_INTR_TX_MASKED_FIFO_TRIGGER_Pos     0UL
#define DAC_INTR_TX_MASKED_FIFO_TRIGGER_Msk     0x1UL
#define DAC_INTR_TX_MASKED_FIFO_OVERFLOW_Pos    1UL
#define DAC_INTR_TX_MASKED_FIFO_OVERFLOW_Msk    0x2UL
#define DAC_INTR_TX_MASKED_FIFO_UNDERFLOW_Pos   2UL
#define DAC_INTR_TX_MASKED_FIFO_UNDERFLOW_Msk   0x4UL
#define DAC_INTR_TX_MASKED_FAST_RAMP_COMPLETE_Pos 16UL
#define DAC_INTR_TX_MASKED_FAST_RAMP_COMPLETE_Msk 0x10000UL
#define DAC_INTR_TX_MASKED_RAMP_COMPLETE_Pos    17UL
#define DAC_INTR_TX_MASKED_RAMP_COMPLETE_Msk    0x20000UL


#endif /* _CYIP_DAC_H_ */


/* [] END OF FILE */
