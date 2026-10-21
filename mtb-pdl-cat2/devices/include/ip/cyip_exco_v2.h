/***************************************************************************//**
* \file cyip_exco_v2.h
*
* \brief
* EXCO IP definitions
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

#ifndef _CYIP_EXCO_V2_H_
#define _CYIP_EXCO_V2_H_

#include "cyip_headers.h"

/*******************************************************************************
*                                     EXCO
*******************************************************************************/

#define EXCO_SECTION_SIZE                       0x00010000UL

/**
  * \brief ECO+PLL as SRSSLT clk_eco external source (EXCO)
  */
typedef struct {
  __IOM uint32_t CLK_SELECT;                    /*!< 0x00000000 Clock Select Register */
   __IM uint32_t RESERVED;
  __IOM uint32_t ECO_CONFIG;                    /*!< 0x00000008 ECO Configuration Register */
   __IM uint32_t ECO_STATUS;                    /*!< 0x0000000C ECO Status Register */
   __IM uint32_t RESERVED1;
  __IOM uint32_t PLL_CONFIG;                    /*!< 0x00000014 PLL Configuration Register */
   __IM uint32_t PLL_STATUS;                    /*!< 0x00000018 PLL Status Register */
  __IOM uint32_t PLL_TEST;                      /*!< 0x0000001C PLL Test Register */
  __IOM uint32_t EXCO_PGM_CLK;                  /*!< 0x00000020 EXCO Program Clock */
   __IM uint32_t RESERVED2[3];
  __IOM uint32_t REF_CTL;                       /*!< 0x00000030 Clock Supervision Reference Contol */
  __IOM uint32_t REF_LIMIT;                     /*!< 0x00000034 Clock Supervision Reference Limits */
  __IOM uint32_t MON_CTL;                       /*!< 0x00000038 Clock Supervision Monitor Control */
   __IM uint32_t RESERVED3;
  __IOM uint32_t INTR;                          /*!< 0x00000040 Interrupt Request Register */
  __IOM uint32_t INTR_SET;                      /*!< 0x00000044 Interrupt Set Register */
  __IOM uint32_t INTR_MASK;                     /*!< 0x00000048 Interrupt Mask Register */
   __IM uint32_t INTR_MASKED;                   /*!< 0x0000004C Interrrupt Masked Register */
  __IOM uint32_t RSTDLY_CTL;                    /*!< 0x00000050 Programmable Delay Counter  Control */
  __IOM uint32_t RSTDLY;                        /*!< 0x00000054 Programmable Delay Counter Initial  Amount */
   __IM uint32_t RSTDLY_COUNT_VAL;              /*!< 0x00000058 Programmable Delay Counter Value */
   __IM uint32_t RESERVED4[16297];
  __IOM uint32_t ECO_TRIM0;                     /*!< 0x0000FF00 ECO Trim0 Register */
  __IOM uint32_t ECO_TRIM1;                     /*!< 0x0000FF04 ECO Trim1 Register */
  __IOM uint32_t ECO_TRIM2;                     /*!< 0x0000FF08 ECO Trim2 Register */
  __IOM uint32_t PLL_TRIM;                      /*!< 0x0000FF0C PLL Trim Register */
} EXCO_Type;                                    /*!< Size = 65296 (0xFF10) */


/* EXCO.CLK_SELECT */
#define EXCO_CLK_SELECT_CLK_SELECT_Pos          0UL
#define EXCO_CLK_SELECT_CLK_SELECT_Msk          0x1UL
#define EXCO_CLK_SELECT_REF_SEL_Pos             1UL
#define EXCO_CLK_SELECT_REF_SEL_Msk             0x6UL
/* EXCO.ECO_CONFIG */
#define EXCO_ECO_CONFIG_CLK_EN_Pos              0UL
#define EXCO_ECO_CONFIG_CLK_EN_Msk              0x1UL
#define EXCO_ECO_CONFIG_AGC_EN_Pos              1UL
#define EXCO_ECO_CONFIG_AGC_EN_Msk              0x2UL
#define EXCO_ECO_CONFIG_ENABLE_Pos              31UL
#define EXCO_ECO_CONFIG_ENABLE_Msk              0x80000000UL
/* EXCO.ECO_STATUS */
#define EXCO_ECO_STATUS_WATCHDOG_ERROR_Pos      0UL
#define EXCO_ECO_STATUS_WATCHDOG_ERROR_Msk      0x1UL
/* EXCO.PLL_CONFIG */
#define EXCO_PLL_CONFIG_FEEDBACK_DIV_Pos        0UL
#define EXCO_PLL_CONFIG_FEEDBACK_DIV_Msk        0xFFUL
#define EXCO_PLL_CONFIG_REFERENCE_DIV_Pos       8UL
#define EXCO_PLL_CONFIG_REFERENCE_DIV_Msk       0x3F00UL
#define EXCO_PLL_CONFIG_OUTPUT_DIV_Pos          14UL
#define EXCO_PLL_CONFIG_OUTPUT_DIV_Msk          0xC000UL
#define EXCO_PLL_CONFIG_ICP_SEL_Pos             16UL
#define EXCO_PLL_CONFIG_ICP_SEL_Msk             0x70000UL
#define EXCO_PLL_CONFIG_BYPASS_SEL_Pos          20UL
#define EXCO_PLL_CONFIG_BYPASS_SEL_Msk          0x300000UL
#define EXCO_PLL_CONFIG_ISOLATE_N_Pos           30UL
#define EXCO_PLL_CONFIG_ISOLATE_N_Msk           0x40000000UL
#define EXCO_PLL_CONFIG_ENABLE_Pos              31UL
#define EXCO_PLL_CONFIG_ENABLE_Msk              0x80000000UL
/* EXCO.PLL_STATUS */
#define EXCO_PLL_STATUS_LOCKED_Pos              0UL
#define EXCO_PLL_STATUS_LOCKED_Msk              0x1UL
/* EXCO.PLL_TEST */
#define EXCO_PLL_TEST_TEST_MODE_Pos             0UL
#define EXCO_PLL_TEST_TEST_MODE_Msk             0x7UL
#define EXCO_PLL_TEST_FAST_LOCK_EN_Pos          3UL
#define EXCO_PLL_TEST_FAST_LOCK_EN_Msk          0x8UL
#define EXCO_PLL_TEST_UNLOCK_OCCURRED_Pos       4UL
#define EXCO_PLL_TEST_UNLOCK_OCCURRED_Msk       0x10UL
/* EXCO.EXCO_PGM_CLK */
#define EXCO_EXCO_PGM_CLK_CLK_ECO_Pos           1UL
#define EXCO_EXCO_PGM_CLK_CLK_ECO_Msk           0x2UL
#define EXCO_EXCO_PGM_CLK_CLK_PLL0_IN_Pos       2UL
#define EXCO_EXCO_PGM_CLK_CLK_PLL0_IN_Msk       0x4UL
#define EXCO_EXCO_PGM_CLK_CLK_PLL0_OUT_Pos      3UL
#define EXCO_EXCO_PGM_CLK_CLK_PLL0_OUT_Msk      0x8UL
#define EXCO_EXCO_PGM_CLK_EN_CLK_PLL0_Pos       4UL
#define EXCO_EXCO_PGM_CLK_EN_CLK_PLL0_Msk       0x10UL
#define EXCO_EXCO_PGM_CLK_ENABLE_Pos            31UL
#define EXCO_EXCO_PGM_CLK_ENABLE_Msk            0x80000000UL
/* EXCO.REF_CTL */
#define EXCO_REF_CTL_STARTUP_Pos                0UL
#define EXCO_REF_CTL_STARTUP_Msk                0xFFFFUL
#define EXCO_REF_CTL_CSV_INT_EN_Pos             16UL
#define EXCO_REF_CTL_CSV_INT_EN_Msk             0x10000UL
#define EXCO_REF_CTL_CSV_TRIG_EN_Pos            17UL
#define EXCO_REF_CTL_CSV_TRIG_EN_Msk            0x20000UL
#define EXCO_REF_CTL_CSV_CLK_SW_EN_Pos          18UL
#define EXCO_REF_CTL_CSV_CLK_SW_EN_Msk          0x40000UL
#define EXCO_REF_CTL_CSV_EN_Pos                 31UL
#define EXCO_REF_CTL_CSV_EN_Msk                 0x80000000UL
/* EXCO.REF_LIMIT */
#define EXCO_REF_LIMIT_LOWER_Pos                0UL
#define EXCO_REF_LIMIT_LOWER_Msk                0xFFFFUL
#define EXCO_REF_LIMIT_UPPER_Pos                16UL
#define EXCO_REF_LIMIT_UPPER_Msk                0xFFFF0000UL
/* EXCO.MON_CTL */
#define EXCO_MON_CTL_PERIOD_Pos                 0UL
#define EXCO_MON_CTL_PERIOD_Msk                 0xFFFFUL
/* EXCO.INTR */
#define EXCO_INTR_PLL_LOCK_Pos                  0UL
#define EXCO_INTR_PLL_LOCK_Msk                  0x1UL
#define EXCO_INTR_WD_ERR_Pos                    1UL
#define EXCO_INTR_WD_ERR_Msk                    0x2UL
#define EXCO_INTR_CSV_CLK_SW_Pos                2UL
#define EXCO_INTR_CSV_CLK_SW_Msk                0x4UL
/* EXCO.INTR_SET */
#define EXCO_INTR_SET_PLL_LOCK_Pos              0UL
#define EXCO_INTR_SET_PLL_LOCK_Msk              0x1UL
#define EXCO_INTR_SET_WD_ERR_Pos                1UL
#define EXCO_INTR_SET_WD_ERR_Msk                0x2UL
#define EXCO_INTR_SET_CSV_CLK_SW_Pos            2UL
#define EXCO_INTR_SET_CSV_CLK_SW_Msk            0x4UL
/* EXCO.INTR_MASK */
#define EXCO_INTR_MASK_PLL_LOCK_Pos             0UL
#define EXCO_INTR_MASK_PLL_LOCK_Msk             0x1UL
#define EXCO_INTR_MASK_WD_ERR_Pos               1UL
#define EXCO_INTR_MASK_WD_ERR_Msk               0x2UL
#define EXCO_INTR_MASK_CSV_CLK_SW_Pos           2UL
#define EXCO_INTR_MASK_CSV_CLK_SW_Msk           0x4UL
/* EXCO.INTR_MASKED */
#define EXCO_INTR_MASKED_PLL_LOCK_Pos           0UL
#define EXCO_INTR_MASKED_PLL_LOCK_Msk           0x1UL
#define EXCO_INTR_MASKED_WD_ERR_Pos             1UL
#define EXCO_INTR_MASKED_WD_ERR_Msk             0x2UL
#define EXCO_INTR_MASKED_CSV_CLK_SW_Pos         2UL
#define EXCO_INTR_MASKED_CSV_CLK_SW_Msk         0x4UL
/* EXCO.RSTDLY_CTL */
#define EXCO_RSTDLY_CTL_LOAD_Pos                0UL
#define EXCO_RSTDLY_CTL_LOAD_Msk                0x1UL
#define EXCO_RSTDLY_CTL_EN_Pos                  31UL
#define EXCO_RSTDLY_CTL_EN_Msk                  0x80000000UL
/* EXCO.RSTDLY */
#define EXCO_RSTDLY_DLYCOUNT_Pos                0UL
#define EXCO_RSTDLY_DLYCOUNT_Msk                0xFFFFUL
/* EXCO.RSTDLY_COUNT_VAL */
#define EXCO_RSTDLY_COUNT_VAL_COUNT_VAL_Pos     0UL
#define EXCO_RSTDLY_COUNT_VAL_COUNT_VAL_Msk     0xFFFFUL
/* EXCO.ECO_TRIM0 */
#define EXCO_ECO_TRIM0_WDTRIM_Pos               0UL
#define EXCO_ECO_TRIM0_WDTRIM_Msk               0x3UL
#define EXCO_ECO_TRIM0_ATRIM_Pos                2UL
#define EXCO_ECO_TRIM0_ATRIM_Msk                0x1CUL
/* EXCO.ECO_TRIM1 */
#define EXCO_ECO_TRIM1_FTRIM_Pos                0UL
#define EXCO_ECO_TRIM1_FTRIM_Msk                0x3UL
#define EXCO_ECO_TRIM1_RTRIM_Pos                2UL
#define EXCO_ECO_TRIM1_RTRIM_Msk                0xCUL
#define EXCO_ECO_TRIM1_GTRIM_Pos                4UL
#define EXCO_ECO_TRIM1_GTRIM_Msk                0x30UL
/* EXCO.ECO_TRIM2 */
#define EXCO_ECO_TRIM2_ITRIM_Pos                0UL
#define EXCO_ECO_TRIM2_ITRIM_Msk                0x3FUL
/* EXCO.PLL_TRIM */
#define EXCO_PLL_TRIM_VCO_GAIN_Pos              0UL
#define EXCO_PLL_TRIM_VCO_GAIN_Msk              0x3UL
#define EXCO_PLL_TRIM_LOCK_WINDOW_Pos           2UL
#define EXCO_PLL_TRIM_LOCK_WINDOW_Msk           0xCUL
#define EXCO_PLL_TRIM_LOCK_DELAY_Pos            4UL
#define EXCO_PLL_TRIM_LOCK_DELAY_Msk            0x30UL


#endif /* _CYIP_EXCO_V2_H_ */


/* [] END OF FILE */
