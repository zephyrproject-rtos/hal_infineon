/***************************************************************************//**
* \file cyip_srsslt.h
*
* \brief
* SRSSLT IP definitions
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

#ifndef _CYIP_SRSSLT_H_
#define _CYIP_SRSSLT_H_

#include "cyip_headers.h"

/*******************************************************************************
*                                    SRSSLT
*******************************************************************************/

#define SRSSLT_SECTION_SIZE                     0x00010000UL

/**
  * \brief System Resources Lite Subsystem (SRSSLT)
  */
typedef struct {
  __IOM uint32_t PWR_CONTROL;                   /*!< 0x00000000 Power Mode Control */
  __IOM uint32_t PWR_KEY_DELAY;                 /*!< 0x00000004 Power System Key&Delay Register */
   __IM uint32_t RESERVED;
  __IOM uint32_t PWR_DDFT_SELECT;               /*!< 0x0000000C Power DDFT Mode Selection Register */
   __IM uint32_t RESERVED1;
  __IOM uint32_t TST_MODE;                      /*!< 0x00000014 Test Mode Control Register */
   __IM uint32_t RESERVED2[4];
  __IOM uint32_t CLK_SELECT;                    /*!< 0x00000028 Clock Select Register */
  __IOM uint32_t CLK_ILO_CONFIG;                /*!< 0x0000002C ILO Configuration */
  __IOM uint32_t CLK_IMO_CONFIG;                /*!< 0x00000030 IMO Configuration */
  __IOM uint32_t CLK_DFT_SELECT;                /*!< 0x00000034 Clock DFT Mode Selection Register */
  __IOM uint32_t WDT_DISABLE_KEY;               /*!< 0x00000038 Watchdog Disable Key Register */
   __IM uint32_t WDT_COUNTER;                   /*!< 0x0000003C Watchdog Counter Register */
  __IOM uint32_t WDT_MATCH;                     /*!< 0x00000040 Watchdog Match Register */
  __IOM uint32_t SRSS_INTR;                     /*!< 0x00000044 SRSS Interrupt Register */
  __IOM uint32_t SRSS_INTR_SET;                 /*!< 0x00000048 SRSS Interrupt Set Register */
  __IOM uint32_t SRSS_INTR_MASK;                /*!< 0x0000004C SRSS Interrupt Mask Register */
   __IM uint32_t RESERVED3;
  __IOM uint32_t RES_CAUSE;                     /*!< 0x00000054 Reset Cause Observation Register */
   __IM uint32_t RESERVED4[940];
  __IOM uint32_t CLK_IMO_SELECT;                /*!< 0x00000F08 IMO Frequency Select Register */
  __IOM uint32_t CLK_IMO_TRIM1;                 /*!< 0x00000F0C IMO Trim Register */
  __IOM uint32_t CLK_IMO_TRIM2;                 /*!< 0x00000F10 IMO Trim Register */
  __IOM uint32_t PWR_PWRSYS_TRIM1;              /*!< 0x00000F14 Power System Trim Register */
  __IOM uint32_t CLK_IMO_TRIM3;                 /*!< 0x00000F18 IMO Trim Register */
} SRSSLT_Type;                                  /*!< Size = 3868 (0xF1C) */


/* SRSSLT.PWR_CONTROL */
#define SRSSLT_PWR_CONTROL_POWER_MODE_Pos       0UL
#define SRSSLT_PWR_CONTROL_POWER_MODE_Msk       0xFUL
#define SRSSLT_PWR_CONTROL_DEBUG_SESSION_Pos    4UL
#define SRSSLT_PWR_CONTROL_DEBUG_SESSION_Msk    0x10UL
#define SRSSLT_PWR_CONTROL_LPM_READY_Pos        5UL
#define SRSSLT_PWR_CONTROL_LPM_READY_Msk        0x20UL
#define SRSSLT_PWR_CONTROL_OVER_TEMP_EN_Pos     16UL
#define SRSSLT_PWR_CONTROL_OVER_TEMP_EN_Msk     0x10000UL
#define SRSSLT_PWR_CONTROL_OVER_TEMP_THRESH_Pos 17UL
#define SRSSLT_PWR_CONTROL_OVER_TEMP_THRESH_Msk 0x20000UL
#define SRSSLT_PWR_CONTROL_SPARE_Pos            18UL
#define SRSSLT_PWR_CONTROL_SPARE_Msk            0xC0000UL
#define SRSSLT_PWR_CONTROL_EXT_VCCD_Pos         23UL
#define SRSSLT_PWR_CONTROL_EXT_VCCD_Msk         0x800000UL
/* SRSSLT.PWR_KEY_DELAY */
#define SRSSLT_PWR_KEY_DELAY_WAKEUP_HOLDOFF_Pos 0UL
#define SRSSLT_PWR_KEY_DELAY_WAKEUP_HOLDOFF_Msk 0x3FFUL
/* SRSSLT.PWR_DDFT_SELECT */
#define SRSSLT_PWR_DDFT_SELECT_DDFT0_SEL_Pos    0UL
#define SRSSLT_PWR_DDFT_SELECT_DDFT0_SEL_Msk    0xFUL
#define SRSSLT_PWR_DDFT_SELECT_DDFT1_SEL_Pos    4UL
#define SRSSLT_PWR_DDFT_SELECT_DDFT1_SEL_Msk    0xF0UL
/* SRSSLT.TST_MODE */
#define SRSSLT_TST_MODE_SWD_CONNECTED_Pos       2UL
#define SRSSLT_TST_MODE_SWD_CONNECTED_Msk       0x4UL
#define SRSSLT_TST_MODE_BLOCK_ALT_XRES_Pos      28UL
#define SRSSLT_TST_MODE_BLOCK_ALT_XRES_Msk      0x10000000UL
#define SRSSLT_TST_MODE_TEST_KEY_DFT_EN_Pos     30UL
#define SRSSLT_TST_MODE_TEST_KEY_DFT_EN_Msk     0x40000000UL
#define SRSSLT_TST_MODE_TEST_MODE_Pos           31UL
#define SRSSLT_TST_MODE_TEST_MODE_Msk           0x80000000UL
/* SRSSLT.CLK_SELECT */
#define SRSSLT_CLK_SELECT_HFCLK_SEL_Pos         0UL
#define SRSSLT_CLK_SELECT_HFCLK_SEL_Msk         0x3UL
#define SRSSLT_CLK_SELECT_HFCLK_DIV_Pos         2UL
#define SRSSLT_CLK_SELECT_HFCLK_DIV_Msk         0xCUL
#define SRSSLT_CLK_SELECT_PUMP_SEL_Pos          4UL
#define SRSSLT_CLK_SELECT_PUMP_SEL_Msk          0x30UL
#define SRSSLT_CLK_SELECT_SYSCLK_DIV_Pos        6UL
#define SRSSLT_CLK_SELECT_SYSCLK_DIV_Msk        0xC0UL
/* SRSSLT.CLK_ILO_CONFIG */
#define SRSSLT_CLK_ILO_CONFIG_ENABLE_Pos        31UL
#define SRSSLT_CLK_ILO_CONFIG_ENABLE_Msk        0x80000000UL
/* SRSSLT.CLK_IMO_CONFIG */
#define SRSSLT_CLK_IMO_CONFIG_ENABLE_Pos        31UL
#define SRSSLT_CLK_IMO_CONFIG_ENABLE_Msk        0x80000000UL
/* SRSSLT.CLK_DFT_SELECT */
#define SRSSLT_CLK_DFT_SELECT_DFT_SEL0_Pos      0UL
#define SRSSLT_CLK_DFT_SELECT_DFT_SEL0_Msk      0xFUL
#define SRSSLT_CLK_DFT_SELECT_DFT_DIV0_Pos      4UL
#define SRSSLT_CLK_DFT_SELECT_DFT_DIV0_Msk      0x30UL
#define SRSSLT_CLK_DFT_SELECT_DFT_EDGE0_Pos     6UL
#define SRSSLT_CLK_DFT_SELECT_DFT_EDGE0_Msk     0x40UL
#define SRSSLT_CLK_DFT_SELECT_DFT_SEL1_Pos      8UL
#define SRSSLT_CLK_DFT_SELECT_DFT_SEL1_Msk      0xF00UL
#define SRSSLT_CLK_DFT_SELECT_DFT_DIV1_Pos      12UL
#define SRSSLT_CLK_DFT_SELECT_DFT_DIV1_Msk      0x3000UL
#define SRSSLT_CLK_DFT_SELECT_DFT_EDGE1_Pos     14UL
#define SRSSLT_CLK_DFT_SELECT_DFT_EDGE1_Msk     0x4000UL
/* SRSSLT.WDT_DISABLE_KEY */
#define SRSSLT_WDT_DISABLE_KEY_KEY_Pos          0UL
#define SRSSLT_WDT_DISABLE_KEY_KEY_Msk          0xFFFFFFFFUL
/* SRSSLT.WDT_COUNTER */
#define SRSSLT_WDT_COUNTER_COUNTER_Pos          0UL
#define SRSSLT_WDT_COUNTER_COUNTER_Msk          0xFFFFUL
/* SRSSLT.WDT_MATCH */
#define SRSSLT_WDT_MATCH_MATCH_Pos              0UL
#define SRSSLT_WDT_MATCH_MATCH_Msk              0xFFFFUL
#define SRSSLT_WDT_MATCH_IGNORE_BITS_Pos        16UL
#define SRSSLT_WDT_MATCH_IGNORE_BITS_Msk        0xF0000UL
/* SRSSLT.SRSS_INTR */
#define SRSSLT_SRSS_INTR_WDT_MATCH_Pos          0UL
#define SRSSLT_SRSS_INTR_WDT_MATCH_Msk          0x1UL
#define SRSSLT_SRSS_INTR_TEMP_HIGH_Pos          1UL
#define SRSSLT_SRSS_INTR_TEMP_HIGH_Msk          0x2UL
/* SRSSLT.SRSS_INTR_SET */
#define SRSSLT_SRSS_INTR_SET_TEMP_HIGH_Pos      1UL
#define SRSSLT_SRSS_INTR_SET_TEMP_HIGH_Msk      0x2UL
/* SRSSLT.SRSS_INTR_MASK */
#define SRSSLT_SRSS_INTR_MASK_WDT_MATCH_Pos     0UL
#define SRSSLT_SRSS_INTR_MASK_WDT_MATCH_Msk     0x1UL
#define SRSSLT_SRSS_INTR_MASK_TEMP_HIGH_Pos     1UL
#define SRSSLT_SRSS_INTR_MASK_TEMP_HIGH_Msk     0x2UL
/* SRSSLT.RES_CAUSE */
#define SRSSLT_RES_CAUSE_RESET_WDT_Pos          0UL
#define SRSSLT_RES_CAUSE_RESET_WDT_Msk          0x1UL
#define SRSSLT_RES_CAUSE_RESET_PROT_FAULT_Pos   3UL
#define SRSSLT_RES_CAUSE_RESET_PROT_FAULT_Msk   0x8UL
#define SRSSLT_RES_CAUSE_RESET_SOFT_Pos         4UL
#define SRSSLT_RES_CAUSE_RESET_SOFT_Msk         0x10UL
/* SRSSLT.CLK_IMO_SELECT */
#define SRSSLT_CLK_IMO_SELECT_FREQ_Pos          0UL
#define SRSSLT_CLK_IMO_SELECT_FREQ_Msk          0x7UL
/* SRSSLT.CLK_IMO_TRIM1 */
#define SRSSLT_CLK_IMO_TRIM1_OFFSET_Pos         0UL
#define SRSSLT_CLK_IMO_TRIM1_OFFSET_Msk         0xFFUL
/* SRSSLT.CLK_IMO_TRIM2 */
#define SRSSLT_CLK_IMO_TRIM2_FSOFFSET_Pos       0UL
#define SRSSLT_CLK_IMO_TRIM2_FSOFFSET_Msk       0x7UL
/* SRSSLT.PWR_PWRSYS_TRIM1 */
#define SRSSLT_PWR_PWRSYS_TRIM1_DPSLP_REF_TRIM_Pos 0UL
#define SRSSLT_PWR_PWRSYS_TRIM1_DPSLP_REF_TRIM_Msk 0xFUL
#define SRSSLT_PWR_PWRSYS_TRIM1_SPARE_TRIM_Pos  4UL
#define SRSSLT_PWR_PWRSYS_TRIM1_SPARE_TRIM_Msk  0xF0UL
/* SRSSLT.CLK_IMO_TRIM3 */
#define SRSSLT_CLK_IMO_TRIM3_STEPSIZE_Pos       0UL
#define SRSSLT_CLK_IMO_TRIM3_STEPSIZE_Msk       0x1FUL
#define SRSSLT_CLK_IMO_TRIM3_TCTRIM_Pos         5UL
#define SRSSLT_CLK_IMO_TRIM3_TCTRIM_Msk         0x60UL


#endif /* _CYIP_SRSSLT_H_ */


/* [] END OF FILE */
