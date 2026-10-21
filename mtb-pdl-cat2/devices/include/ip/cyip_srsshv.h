/***************************************************************************//**
* \file cyip_srsshv.h
*
* \brief
* SRSSHV IP definitions
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

#ifndef _CYIP_SRSSHV_H_
#define _CYIP_SRSSHV_H_

#include "cyip_headers.h"

/*******************************************************************************
*                                    SRSSHV
*******************************************************************************/

#define WDT_SECTION_SIZE                        0x00000080UL
#define SRSSHV_SECTION_SIZE                     0x00010000UL

/**
  * \brief Watchdog Timer (WDT)
  */
typedef struct {
  __IOM uint32_t CTL;                           /*!< 0x00000000 WDT Control Register */
  __IOM uint32_t LOWER_LIMIT;                   /*!< 0x00000004 WDT Lower Limit Register */
  __IOM uint32_t UPPER_LIMIT;                   /*!< 0x00000008 WDT Upper Limit Register */
  __IOM uint32_t WARN_LIMIT;                    /*!< 0x0000000C WDT Warn Limit Register */
  __IOM uint32_t CONFIG;                        /*!< 0x00000010 WDT Configuration Register */
  __IOM uint32_t CNT;                           /*!< 0x00000014 WDT Count Register */
   __IM uint32_t RESERVED[10];
  __IOM uint32_t LOCK;                          /*!< 0x00000040 WDT Lock register */
  __IOM uint32_t SERVICE;                       /*!< 0x00000044 WDT Service register */
   __IM uint32_t RESERVED1[2];
  __IOM uint32_t INTR;                          /*!< 0x00000050 WDT Interrupt Register */
  __IOM uint32_t INTR_SET;                      /*!< 0x00000054 WDT Interrupt Set Register */
  __IOM uint32_t INTR_MASK;                     /*!< 0x00000058 WDT Interrupt Mask Register */
   __IM uint32_t INTR_MASKED;                   /*!< 0x0000005C WDT Interrupt Masked Register */
   __IM uint32_t RESERVED2[8];
} WDT_Type;                                     /*!< Size = 128 (0x80) */

/**
  * \brief System Resources High Voltage Subsystem (SRSSHV)
  */
typedef struct {
  __IOM uint32_t PWR_CONTROL;                   /*!< 0x00000000 Power Mode Control (Lock Protected) */
  __IOM uint32_t PWR_KEY_DELAY;                 /*!< 0x00000004 Power System Key&Delay Register (Lock Protected) */
   __IM uint32_t RESERVED[3];
  __IOM uint32_t TST_MODE;                      /*!< 0x00000014 Test Mode Control Register */
   __IM uint32_t RESERVED1;
  __IOM uint32_t CLK_CAL_CNT1;                  /*!< 0x0000001C Clock Calibration Counter 1 */
   __IM uint32_t CLK_CAL_CNT2;                  /*!< 0x00000020 Clock Calibration Counter 2 */
   __IM uint32_t RESERVED2;
  __IOM uint32_t CLK_SELECT;                    /*!< 0x00000028 Clock Select Register (Lock Protected) */
  __IOM uint32_t CLK_ILO_CONFIG;                /*!< 0x0000002C ILO Configuration (Lock Protected) */
  __IOM uint32_t CLK_IMO_CONFIG;                /*!< 0x00000030 IMO Configuration (Lock Protected) */
  __IOM uint32_t CLK_DFT_SELECT;                /*!< 0x00000034 Clock DFT Mode Selection Register */
   __IM uint32_t RESERVED3[2];
   __IM uint32_t SRSS_MASKED;                   /*!< 0x00000040 SRSS Interrupt Masked Register */
  __IOM uint32_t SRSS_INTR;                     /*!< 0x00000044 SRSS Interrupt Register */
  __IOM uint32_t SRSS_INTR_SET;                 /*!< 0x00000048 SRSS Interrupt Set Register */
  __IOM uint32_t SRSS_INTR_MASK;                /*!< 0x0000004C SRSS Interrupt Mask Register */
   __IM uint32_t RESERVED4;
  __IOM uint32_t RES_CAUSE;                     /*!< 0x00000054 Reset Cause Observation Register */
   __IM uint32_t RESERVED5[10];
  __IOM uint32_t REG_PROT;                      /*!< 0x00000080 Register Protection */
   __IM uint32_t RESERVED6[3];
  __IOM uint32_t CRWDT_CTL;                     /*!< 0x00000090 Challenge Response WatchDog Control (Lock Protected) */
   __IM uint32_t CRWDT_CHALLENGE;               /*!< 0x00000094 Challenge Response WatchDog Challenge Value */
  __IOM uint32_t CRWDT_RESPONSE;                /*!< 0x00000098 Challenge Response WatchDog Response Value */
   __IM uint32_t CRWDT_UPCNT;                   /*!< 0x0000009C Challenge Response  WatchDog Up Counter */
  __IOM uint32_t CRWDT_EARLY;                   /*!< 0x000000A0 Challenge Response  WatchDog Early Limit (Lock Protected) */
  __IOM uint32_t CRWDT_WARN;                    /*!< 0x000000A4 Challenge Response  WatchDog Warning Limit  (Lock Protected) */
  __IOM uint32_t CRWDT_LATE;                    /*!< 0x000000A8 Challenge Response  WatchDog Late Limit  (Lock Protected) */
  __IOM uint32_t CRWDT_CONFIG;                  /*!< 0x000000AC Challenge Response WatchDog Configuration */
  __IOM uint32_t LIFETIME_CTL;                  /*!< 0x000000B0 Liftetime Counter Control (Lock Protected) */
  __IOM uint32_t LIFETIME_WAKEUP;               /*!< 0x000000B4 Lifetime Wakeup Value */
  __IOM uint32_t LIFETIME_COUNTER;              /*!< 0x000000B8 Lifetime Counter Current Value */
   __IM uint32_t RESERVED7[9];
  __IOM uint32_t PWR_SSV_CTL;                   /*!< 0x000000E0 Supply Supervisory Control Register  (Lock Protected) */
   __IM uint32_t PWR_SSV_STATUS;                /*!< 0x000000E4 Supply Supervision Status Register */
   __IM uint32_t RESERVED8[6];
        WDT_Type WDT_STRUCT;                    /*!< 0x00000100 Watchdog Timer */
   __IM uint32_t RESERVED9[96];
  __IOM uint32_t HPOSC_CTL;                     /*!< 0x00000300 High Precision Oscillator Control  (Lock Protected) */
   __IM uint32_t RESERVED10[63];
  __IOM uint32_t PILO_CTL;                      /*!< 0x00000400 Precision Low Power Oscillator Control  (Lock Protected) */
   __IM uint32_t RESERVED11[16063];
  __IOM uint32_t PWR_BG_TRIM1;                  /*!< 0x0000FF00 Bandgap Trim Register  (Lock Protected) */
  __IOM uint32_t PWR_BG_TRIM2;                  /*!< 0x0000FF04 Bandgap Trim Register  (Lock Protected) */
  __IOM uint32_t CLK_IMO_SELECT;                /*!< 0x0000FF08 IMO Frequency Select Register  (Lock Protected) */
  __IOM uint32_t CLK_IMO_TRIM1;                 /*!< 0x0000FF0C IMO Trim Register  (Lock Protected) */
  __IOM uint32_t CLK_IMO_TRIM2;                 /*!< 0x0000FF10 IMO Trim Register  (Lock Protected) */
  __IOM uint32_t CLK_IMO_TRIM3;                 /*!< 0x0000FF14 IMO Trim Register  (Lock Protected) */
  __IOM uint32_t PWR_PWRSYS_TRIM1;              /*!< 0x0000FF18 Power System Trim Register  (Lock Protected) */
  __IOM uint32_t TRIM_BODVCCD;                  /*!< 0x0000FF1C Brown Out Detect Trim (VCCD)  (Lock Protected) */
  __IOM uint32_t TRIM_OVDVCCD;                  /*!< 0x0000FF20 Over Voltage Detect Trim (VCCD)  (Lock Protected) */
  __IOM uint32_t TRIM_HPOSC0_CTL;               /*!< 0x0000FF24 High Precision Oscillator Trim Control 0  (Lock Protected) */
  __IOM uint32_t TRIM_HPOSC1_CTL;               /*!< 0x0000FF28 High Precision Oscillator Trim Control 1  (Lock Protected) */
  __IOM uint32_t TRIM_HPOSC2_CTL;               /*!< 0x0000FF2C High Precision Oscillator Trim Control 2  (Lock Protected) */
  __IOM uint32_t TRIM_HPOSC3_CTL;               /*!< 0x0000FF30 High Precision Oscillator Trim Control 3  (Lock Protected) */
  __IOM uint32_t TRIM_HPOSC4_CTL;               /*!< 0x0000FF34 High Precision Oscillator Trim Control 4  (Lock Protected) */
  __IOM uint32_t TRIM_PILO0_CTL;                /*!< 0x0000FF38 Low Frequency Oscillator Trim Control 0   (Lock Protected) */
  __IOM uint32_t TRIM_PILO1_CTL;                /*!< 0x0000FF3C Low Frequency Oscillator Trim Control 1   (Lock Protected) */
  __IOM uint32_t TRIM_PILO2_CTL;                /*!< 0x0000FF40 Low Frequency Oscillator Trim Control 2  (Lock Protected) */
  __IOM uint32_t TRIM_PILO3_CTL;                /*!< 0x0000FF44 Low Frequency Oscillator Trim Control 3  (Lock Protected) */
  __IOM uint32_t TRIM_PILO4_CTL;                /*!< 0x0000FF48 Low Frequency Oscillator Trim Control 4  (Lock Protected) */
  __IOM uint32_t TRIM_PILO5_CTL;                /*!< 0x0000FF4C Low Frequency Oscillator Trim Control 5  (Lock Protected) */
  __IOM uint32_t TRIM_BODVDDD;                  /*!< 0x0000FF50 Brown Out Detect Trim (VDDD)  (Lock Protected) */
  __IOM uint32_t TRIM_OVDVDDD;                  /*!< 0x0000FF54 Over Voltage Detect Trim  (VDDD) (Lock Protected) */
} SRSSHV_Type;                                  /*!< Size = 65368 (0xFF58) */


/* WDT.CTL */
#define WDT_CTL_ENABLED_Pos                     0UL
#define WDT_CTL_ENABLED_Msk                     0x1UL
#define WDT_CTL_ENABLE_Pos                      31UL
#define WDT_CTL_ENABLE_Msk                      0x80000000UL
/* WDT.LOWER_LIMIT */
#define WDT_LOWER_LIMIT_LOWER_LIMIT_Pos         0UL
#define WDT_LOWER_LIMIT_LOWER_LIMIT_Msk         0xFFFFFFFFUL
/* WDT.UPPER_LIMIT */
#define WDT_UPPER_LIMIT_UPPER_LIMIT_Pos         0UL
#define WDT_UPPER_LIMIT_UPPER_LIMIT_Msk         0xFFFFFFFFUL
/* WDT.WARN_LIMIT */
#define WDT_WARN_LIMIT_WARN_LIMIT_Pos           0UL
#define WDT_WARN_LIMIT_WARN_LIMIT_Msk           0xFFFFFFFFUL
/* WDT.CONFIG */
#define WDT_CONFIG_LOWER_ACTION_Pos             0UL
#define WDT_CONFIG_LOWER_ACTION_Msk             0x1UL
#define WDT_CONFIG_UPPER_ACTION_Pos             4UL
#define WDT_CONFIG_UPPER_ACTION_Msk             0x10UL
#define WDT_CONFIG_WARN_ACTION_Pos              8UL
#define WDT_CONFIG_WARN_ACTION_Msk              0x100UL
#define WDT_CONFIG_AUTO_SERVICE_Pos             12UL
#define WDT_CONFIG_AUTO_SERVICE_Msk             0x1000UL
#define WDT_CONFIG_DEBUG_TRIGGER_EN_Pos         28UL
#define WDT_CONFIG_DEBUG_TRIGGER_EN_Msk         0x10000000UL
#define WDT_CONFIG_DPSLP_PAUSE_Pos              29UL
#define WDT_CONFIG_DPSLP_PAUSE_Msk              0x20000000UL
#define WDT_CONFIG_DEBUG_RUN_Pos                31UL
#define WDT_CONFIG_DEBUG_RUN_Msk                0x80000000UL
/* WDT.CNT */
#define WDT_CNT_CNT_Pos                         0UL
#define WDT_CNT_CNT_Msk                         0xFFFFFFFFUL
/* WDT.LOCK */
#define WDT_LOCK_WDT_LOCK_Pos                   0UL
#define WDT_LOCK_WDT_LOCK_Msk                   0x3UL
/* WDT.SERVICE */
#define WDT_SERVICE_SERVICE_Pos                 0UL
#define WDT_SERVICE_SERVICE_Msk                 0x1UL
/* WDT.INTR */
#define WDT_INTR_WDT_Pos                        0UL
#define WDT_INTR_WDT_Msk                        0x1UL
/* WDT.INTR_SET */
#define WDT_INTR_SET_WDT_Pos                    0UL
#define WDT_INTR_SET_WDT_Msk                    0x1UL
/* WDT.INTR_MASK */
#define WDT_INTR_MASK_WDT_Pos                   0UL
#define WDT_INTR_MASK_WDT_Msk                   0x1UL
/* WDT.INTR_MASKED */
#define WDT_INTR_MASKED_WDT_Pos                 0UL
#define WDT_INTR_MASKED_WDT_Msk                 0x1UL


/* SRSSHV.PWR_CONTROL */
#define SRSSHV_PWR_CONTROL_POWER_MODE_Pos       0UL
#define SRSSHV_PWR_CONTROL_POWER_MODE_Msk       0xFUL
#define SRSSHV_PWR_CONTROL_DEBUG_SESSION_Pos    4UL
#define SRSSHV_PWR_CONTROL_DEBUG_SESSION_Msk    0x10UL
#define SRSSHV_PWR_CONTROL_LPM_READY_Pos        5UL
#define SRSSHV_PWR_CONTROL_LPM_READY_Msk        0x20UL
#define SRSSHV_PWR_CONTROL_OVER_TEMP_EN_Pos     16UL
#define SRSSHV_PWR_CONTROL_OVER_TEMP_EN_Msk     0x10000UL
#define SRSSHV_PWR_CONTROL_OVER_TEMP_THRESH_Pos 17UL
#define SRSSHV_PWR_CONTROL_OVER_TEMP_THRESH_Msk 0x20000UL
#define SRSSHV_PWR_CONTROL_SPARE_Pos            18UL
#define SRSSHV_PWR_CONTROL_SPARE_Msk            0xC0000UL
#define SRSSHV_PWR_CONTROL_EXT_VCCD_Pos         23UL
#define SRSSHV_PWR_CONTROL_EXT_VCCD_Msk         0x800000UL
/* SRSSHV.PWR_KEY_DELAY */
#define SRSSHV_PWR_KEY_DELAY_WAKEUP_HOLDOFF_Pos 0UL
#define SRSSHV_PWR_KEY_DELAY_WAKEUP_HOLDOFF_Msk 0x3FFUL
/* SRSSHV.TST_MODE */
#define SRSSHV_TST_MODE_SWD_CONNECTED_Pos       2UL
#define SRSSHV_TST_MODE_SWD_CONNECTED_Msk       0x4UL
#define SRSSHV_TST_MODE_BLOCK_ALT_XRES_Pos      28UL
#define SRSSHV_TST_MODE_BLOCK_ALT_XRES_Msk      0x10000000UL
#define SRSSHV_TST_MODE_TEST_KEY_DFT_EN_Pos     30UL
#define SRSSHV_TST_MODE_TEST_KEY_DFT_EN_Msk     0x40000000UL
#define SRSSHV_TST_MODE_TEST_MODE_Pos           31UL
#define SRSSHV_TST_MODE_TEST_MODE_Msk           0x80000000UL
/* SRSSHV.CLK_CAL_CNT1 */
#define SRSSHV_CLK_CAL_CNT1_CAL_COUNTER1_Pos    0UL
#define SRSSHV_CLK_CAL_CNT1_CAL_COUNTER1_Msk    0xFFFFUL
#define SRSSHV_CLK_CAL_CNT1_CAL_COUNTER_DONE_Pos 31UL
#define SRSSHV_CLK_CAL_CNT1_CAL_COUNTER_DONE_Msk 0x80000000UL
/* SRSSHV.CLK_CAL_CNT2 */
#define SRSSHV_CLK_CAL_CNT2_CAL_COUNTER2_Pos    0UL
#define SRSSHV_CLK_CAL_CNT2_CAL_COUNTER2_Msk    0xFFFFUL
/* SRSSHV.CLK_SELECT */
#define SRSSHV_CLK_SELECT_HFCLK_SEL_Pos         0UL
#define SRSSHV_CLK_SELECT_HFCLK_SEL_Msk         0x3UL
#define SRSSHV_CLK_SELECT_HFCLK_DIV_Pos         2UL
#define SRSSHV_CLK_SELECT_HFCLK_DIV_Msk         0xCUL
#define SRSSHV_CLK_SELECT_PUMP_SEL_Pos          4UL
#define SRSSHV_CLK_SELECT_PUMP_SEL_Msk          0x30UL
#define SRSSHV_CLK_SELECT_SYSCLK_DIV_Pos        6UL
#define SRSSHV_CLK_SELECT_SYSCLK_DIV_Msk        0xC0UL
#define SRSSHV_CLK_SELECT_LFCLK_SEL_Pos         8UL
#define SRSSHV_CLK_SELECT_LFCLK_SEL_Msk         0x100UL
/* SRSSHV.CLK_ILO_CONFIG */
#define SRSSHV_CLK_ILO_CONFIG_ENABLE_Pos        31UL
#define SRSSHV_CLK_ILO_CONFIG_ENABLE_Msk        0x80000000UL
/* SRSSHV.CLK_IMO_CONFIG */
#define SRSSHV_CLK_IMO_CONFIG_ENABLE_Pos        31UL
#define SRSSHV_CLK_IMO_CONFIG_ENABLE_Msk        0x80000000UL
/* SRSSHV.CLK_DFT_SELECT */
#define SRSSHV_CLK_DFT_SELECT_DFT_SEL0_Pos      0UL
#define SRSSHV_CLK_DFT_SELECT_DFT_SEL0_Msk      0xFUL
#define SRSSHV_CLK_DFT_SELECT_DFT_DIV0_Pos      4UL
#define SRSSHV_CLK_DFT_SELECT_DFT_DIV0_Msk      0x30UL
#define SRSSHV_CLK_DFT_SELECT_DFT_EDGE0_Pos     6UL
#define SRSSHV_CLK_DFT_SELECT_DFT_EDGE0_Msk     0x40UL
#define SRSSHV_CLK_DFT_SELECT_DFT_SEL1_Pos      8UL
#define SRSSHV_CLK_DFT_SELECT_DFT_SEL1_Msk      0xF00UL
#define SRSSHV_CLK_DFT_SELECT_DFT_DIV1_Pos      12UL
#define SRSSHV_CLK_DFT_SELECT_DFT_DIV1_Msk      0x3000UL
#define SRSSHV_CLK_DFT_SELECT_DFT_EDGE1_Pos     14UL
#define SRSSHV_CLK_DFT_SELECT_DFT_EDGE1_Msk     0x4000UL
/* SRSSHV.SRSS_MASKED */
#define SRSSHV_SRSS_MASKED_TEMP_HIGH_Pos        1UL
#define SRSSHV_SRSS_MASKED_TEMP_HIGH_Msk        0x2UL
#define SRSSHV_SRSS_MASKED_LIFETIME_WAKEUP_Pos  2UL
#define SRSSHV_SRSS_MASKED_LIFETIME_WAKEUP_Msk  0x4UL
#define SRSSHV_SRSS_MASKED_CLK_CAL_Pos          3UL
#define SRSSHV_SRSS_MASKED_CLK_CAL_Msk          0x8UL
#define SRSSHV_SRSS_MASKED_CRWDT_Pos            4UL
#define SRSSHV_SRSS_MASKED_CRWDT_Msk            0x10UL
/* SRSSHV.SRSS_INTR */
#define SRSSHV_SRSS_INTR_TEMP_HIGH_Pos          1UL
#define SRSSHV_SRSS_INTR_TEMP_HIGH_Msk          0x2UL
#define SRSSHV_SRSS_INTR_LIFETIME_WAKEUP_Pos    2UL
#define SRSSHV_SRSS_INTR_LIFETIME_WAKEUP_Msk    0x4UL
#define SRSSHV_SRSS_INTR_CLK_CAL_Pos            3UL
#define SRSSHV_SRSS_INTR_CLK_CAL_Msk            0x8UL
#define SRSSHV_SRSS_INTR_CRWDT_Pos              4UL
#define SRSSHV_SRSS_INTR_CRWDT_Msk              0x10UL
/* SRSSHV.SRSS_INTR_SET */
#define SRSSHV_SRSS_INTR_SET_TEMP_HIGH_Pos      1UL
#define SRSSHV_SRSS_INTR_SET_TEMP_HIGH_Msk      0x2UL
#define SRSSHV_SRSS_INTR_SET_LIFETIME_WAKEUP_Pos 2UL
#define SRSSHV_SRSS_INTR_SET_LIFETIME_WAKEUP_Msk 0x4UL
#define SRSSHV_SRSS_INTR_SET_CLK_CAL_Pos        3UL
#define SRSSHV_SRSS_INTR_SET_CLK_CAL_Msk        0x8UL
#define SRSSHV_SRSS_INTR_SET_CRWDT_Pos          4UL
#define SRSSHV_SRSS_INTR_SET_CRWDT_Msk          0x10UL
/* SRSSHV.SRSS_INTR_MASK */
#define SRSSHV_SRSS_INTR_MASK_TEMP_HIGH_Pos     1UL
#define SRSSHV_SRSS_INTR_MASK_TEMP_HIGH_Msk     0x2UL
#define SRSSHV_SRSS_INTR_MASK_LIFETIME_WAKEUP_Pos 2UL
#define SRSSHV_SRSS_INTR_MASK_LIFETIME_WAKEUP_Msk 0x4UL
#define SRSSHV_SRSS_INTR_MASK_CLK_CAL_Pos       3UL
#define SRSSHV_SRSS_INTR_MASK_CLK_CAL_Msk       0x8UL
#define SRSSHV_SRSS_INTR_MASK_CRWDT_Pos         4UL
#define SRSSHV_SRSS_INTR_MASK_CRWDT_Msk         0x10UL
/* SRSSHV.RES_CAUSE */
#define SRSSHV_RES_CAUSE_RESET_WDT_Pos          0UL
#define SRSSHV_RES_CAUSE_RESET_WDT_Msk          0x1UL
#define SRSSHV_RES_CAUSE_RESET_ACT_FAULT_Pos    1UL
#define SRSSHV_RES_CAUSE_RESET_ACT_FAULT_Msk    0x2UL
#define SRSSHV_RES_CAUSE_RESET_PROT_FAULT_Pos   3UL
#define SRSSHV_RES_CAUSE_RESET_PROT_FAULT_Msk   0x8UL
#define SRSSHV_RES_CAUSE_RESET_SOFT_Pos         4UL
#define SRSSHV_RES_CAUSE_RESET_SOFT_Msk         0x10UL
#define SRSSHV_RES_CAUSE_RESET_CRWDT_Pos        9UL
#define SRSSHV_RES_CAUSE_RESET_CRWDT_Msk        0x200UL
#define SRSSHV_RES_CAUSE_RESET_XRES_Pos         16UL
#define SRSSHV_RES_CAUSE_RESET_XRES_Msk         0x10000UL
#define SRSSHV_RES_CAUSE_RESET_BODVDDD_Pos      17UL
#define SRSSHV_RES_CAUSE_RESET_BODVDDD_Msk      0x20000UL
#define SRSSHV_RES_CAUSE_RESET_BODVCCD_Pos      19UL
#define SRSSHV_RES_CAUSE_RESET_BODVCCD_Msk      0x80000UL
#define SRSSHV_RES_CAUSE_RESET_OVDVDDD_Pos      20UL
#define SRSSHV_RES_CAUSE_RESET_OVDVDDD_Msk      0x100000UL
#define SRSSHV_RES_CAUSE_RESET_OVDVCCD_Pos      22UL
#define SRSSHV_RES_CAUSE_RESET_OVDVCCD_Msk      0x400000UL
#define SRSSHV_RES_CAUSE_RESET_BODHVSS_Pos      24UL
#define SRSSHV_RES_CAUSE_RESET_BODHVSS_Msk      0x1000000UL
#define SRSSHV_RES_CAUSE_RESET_PORVDDD_Pos      30UL
#define SRSSHV_RES_CAUSE_RESET_PORVDDD_Msk      0x40000000UL
/* SRSSHV.REG_PROT */
#define SRSSHV_REG_PROT_MAGIC_Pos               0UL
#define SRSSHV_REG_PROT_MAGIC_Msk               0xFFFFFFFFUL
/* SRSSHV.CRWDT_CTL */
#define SRSSHV_CRWDT_CTL_STATUS_ENABLED_Pos     30UL
#define SRSSHV_CRWDT_CTL_STATUS_ENABLED_Msk     0x40000000UL
#define SRSSHV_CRWDT_CTL_ENABLED_Pos            31UL
#define SRSSHV_CRWDT_CTL_ENABLED_Msk            0x80000000UL
/* SRSSHV.CRWDT_CHALLENGE */
#define SRSSHV_CRWDT_CHALLENGE_CHALLENGE_Pos    0UL
#define SRSSHV_CRWDT_CHALLENGE_CHALLENGE_Msk    0xFFUL
/* SRSSHV.CRWDT_RESPONSE */
#define SRSSHV_CRWDT_RESPONSE_RESPONSE_Pos      0UL
#define SRSSHV_CRWDT_RESPONSE_RESPONSE_Msk      0xFFUL
/* SRSSHV.CRWDT_UPCNT */
#define SRSSHV_CRWDT_UPCNT_UPCNT_Pos            0UL
#define SRSSHV_CRWDT_UPCNT_UPCNT_Msk            0xFFFFFFUL
/* SRSSHV.CRWDT_EARLY */
#define SRSSHV_CRWDT_EARLY_EARLY_Pos            0UL
#define SRSSHV_CRWDT_EARLY_EARLY_Msk            0xFFFFFFUL
/* SRSSHV.CRWDT_WARN */
#define SRSSHV_CRWDT_WARN_WARNING_Pos           0UL
#define SRSSHV_CRWDT_WARN_WARNING_Msk           0xFFFFFFUL
/* SRSSHV.CRWDT_LATE */
#define SRSSHV_CRWDT_LATE_LATE_Pos              0UL
#define SRSSHV_CRWDT_LATE_LATE_Msk              0xFFFFFFUL
/* SRSSHV.CRWDT_CONFIG */
#define SRSSHV_CRWDT_CONFIG_EARLY_ACTION_Pos    0UL
#define SRSSHV_CRWDT_CONFIG_EARLY_ACTION_Msk    0x1UL
#define SRSSHV_CRWDT_CONFIG_LATE_ACTION_Pos     4UL
#define SRSSHV_CRWDT_CONFIG_LATE_ACTION_Msk     0x10UL
#define SRSSHV_CRWDT_CONFIG_WARN_ACTION_Pos     8UL
#define SRSSHV_CRWDT_CONFIG_WARN_ACTION_Msk     0x100UL
#define SRSSHV_CRWDT_CONFIG_CHALLENGE_FAIL_ACTION_Pos 11UL
#define SRSSHV_CRWDT_CONFIG_CHALLENGE_FAIL_ACTION_Msk 0x800UL
#define SRSSHV_CRWDT_CONFIG_DEBUG_RUN_Pos       31UL
#define SRSSHV_CRWDT_CONFIG_DEBUG_RUN_Msk       0x80000000UL
/* SRSSHV.LIFETIME_CTL */
#define SRSSHV_LIFETIME_CTL_PRESEL_Pos          0UL
#define SRSSHV_LIFETIME_CTL_PRESEL_Msk          0x7UL
#define SRSSHV_LIFETIME_CTL_STATUS_ENABLED_Pos  30UL
#define SRSSHV_LIFETIME_CTL_STATUS_ENABLED_Msk  0x40000000UL
#define SRSSHV_LIFETIME_CTL_ENABLED_Pos         31UL
#define SRSSHV_LIFETIME_CTL_ENABLED_Msk         0x80000000UL
/* SRSSHV.LIFETIME_WAKEUP */
#define SRSSHV_LIFETIME_WAKEUP_WAKEUP_Pos       0UL
#define SRSSHV_LIFETIME_WAKEUP_WAKEUP_Msk       0xFFFFFFFFUL
/* SRSSHV.LIFETIME_COUNTER */
#define SRSSHV_LIFETIME_COUNTER_COUNT_Pos       0UL
#define SRSSHV_LIFETIME_COUNTER_COUNT_Msk       0xFFFFFFFFUL
/* SRSSHV.PWR_SSV_CTL */
#define SRSSHV_PWR_SSV_CTL_BODVDDD_ENABLE_Pos   3UL
#define SRSSHV_PWR_SSV_CTL_BODVDDD_ENABLE_Msk   0x8UL
#define SRSSHV_PWR_SSV_CTL_BODVCCD_ENABLE_Pos   11UL
#define SRSSHV_PWR_SSV_CTL_BODVCCD_ENABLE_Msk   0x800UL
#define SRSSHV_PWR_SSV_CTL_OVDVDDD_ENABLE_Pos   19UL
#define SRSSHV_PWR_SSV_CTL_OVDVDDD_ENABLE_Msk   0x80000UL
#define SRSSHV_PWR_SSV_CTL_OVDVCCD_ENABLE_Pos   27UL
#define SRSSHV_PWR_SSV_CTL_OVDVCCD_ENABLE_Msk   0x8000000UL
#define SRSSHV_PWR_SSV_CTL_BODHVSS_ENABLE_Pos   31UL
#define SRSSHV_PWR_SSV_CTL_BODHVSS_ENABLE_Msk   0x80000000UL
/* SRSSHV.PWR_SSV_STATUS */
#define SRSSHV_PWR_SSV_STATUS_BODVDDD_OK_Pos    0UL
#define SRSSHV_PWR_SSV_STATUS_BODVDDD_OK_Msk    0x1UL
#define SRSSHV_PWR_SSV_STATUS_BODVCCD_OK_Pos    2UL
#define SRSSHV_PWR_SSV_STATUS_BODVCCD_OK_Msk    0x4UL
#define SRSSHV_PWR_SSV_STATUS_OVDVDDD_OK_Pos    8UL
#define SRSSHV_PWR_SSV_STATUS_OVDVDDD_OK_Msk    0x100UL
#define SRSSHV_PWR_SSV_STATUS_OVDVCCD_OK_Pos    10UL
#define SRSSHV_PWR_SSV_STATUS_OVDVCCD_OK_Msk    0x400UL
#define SRSSHV_PWR_SSV_STATUS_BODHVSS_OK_Pos    12UL
#define SRSSHV_PWR_SSV_STATUS_BODHVSS_OK_Msk    0x1000UL
/* SRSSHV.HPOSC_CTL */
#define SRSSHV_HPOSC_CTL_LEAKC_DIS_Pos          0UL
#define SRSSHV_HPOSC_CTL_LEAKC_DIS_Msk          0x1UL
#define SRSSHV_HPOSC_CTL_CTAT_SEL_Pos           1UL
#define SRSSHV_HPOSC_CTL_CTAT_SEL_Msk           0x2UL
#define SRSSHV_HPOSC_CTL_CTAT_SWB_Pos           4UL
#define SRSSHV_HPOSC_CTL_CTAT_SWB_Msk           0x10UL
#define SRSSHV_HPOSC_CTL_IMO_EN_Pos             31UL
#define SRSSHV_HPOSC_CTL_IMO_EN_Msk             0x80000000UL
/* SRSSHV.PILO_CTL */
#define SRSSHV_PILO_CTL_LEAKC_DIS_Pos           0UL
#define SRSSHV_PILO_CTL_LEAKC_DIS_Msk           0x1UL
#define SRSSHV_PILO_CTL_CTAT_SEL_Pos            1UL
#define SRSSHV_PILO_CTL_CTAT_SEL_Msk            0x2UL
#define SRSSHV_PILO_CTL_CTAT_SWB_Pos            4UL
#define SRSSHV_PILO_CTL_CTAT_SWB_Msk            0x10UL
#define SRSSHV_PILO_CTL_TR_CAP_Pos              8UL
#define SRSSHV_PILO_CTL_TR_CAP_Msk              0xFF00UL
#define SRSSHV_PILO_CTL_ILO_EN_Pos              31UL
#define SRSSHV_PILO_CTL_ILO_EN_Msk              0x80000000UL
/* SRSSHV.PWR_BG_TRIM1 */
#define SRSSHV_PWR_BG_TRIM1_REF_VTRIM_Pos       0UL
#define SRSSHV_PWR_BG_TRIM1_REF_VTRIM_Msk       0x3FUL
/* SRSSHV.PWR_BG_TRIM2 */
#define SRSSHV_PWR_BG_TRIM2_REF_ITRIM_Pos       0UL
#define SRSSHV_PWR_BG_TRIM2_REF_ITRIM_Msk       0x3FUL
/* SRSSHV.CLK_IMO_SELECT */
#define SRSSHV_CLK_IMO_SELECT_FREQ_Pos          0UL
#define SRSSHV_CLK_IMO_SELECT_FREQ_Msk          0x7UL
/* SRSSHV.CLK_IMO_TRIM1 */
#define SRSSHV_CLK_IMO_TRIM1_OFFSET_Pos         0UL
#define SRSSHV_CLK_IMO_TRIM1_OFFSET_Msk         0xFFUL
/* SRSSHV.CLK_IMO_TRIM2 */
#define SRSSHV_CLK_IMO_TRIM2_FSOFFSET_Pos       0UL
#define SRSSHV_CLK_IMO_TRIM2_FSOFFSET_Msk       0x7UL
#define SRSSHV_CLK_IMO_TRIM2_TCTRIM_Pos         4UL
#define SRSSHV_CLK_IMO_TRIM2_TCTRIM_Msk         0xF0UL
/* SRSSHV.CLK_IMO_TRIM3 */
#define SRSSHV_CLK_IMO_TRIM3_STEPSIZE_Pos       0UL
#define SRSSHV_CLK_IMO_TRIM3_STEPSIZE_Msk       0x1FUL
/* SRSSHV.PWR_PWRSYS_TRIM1 */
#define SRSSHV_PWR_PWRSYS_TRIM1_DPSLP_REF_TRIM_Pos 0UL
#define SRSSHV_PWR_PWRSYS_TRIM1_DPSLP_REF_TRIM_Msk 0xFUL
#define SRSSHV_PWR_PWRSYS_TRIM1_SPARE_TRIM_Pos  4UL
#define SRSSHV_PWR_PWRSYS_TRIM1_SPARE_TRIM_Msk  0xF0UL
/* SRSSHV.TRIM_BODVCCD */
#define SRSSHV_TRIM_BODVCCD_BOD_TRIPSEL_VCCD_Pos 0UL
#define SRSSHV_TRIM_BODVCCD_BOD_TRIPSEL_VCCD_Msk 0xFUL
#define SRSSHV_TRIM_BODVCCD_BOD_RANGE_SELECT_VCCD_Pos 4UL
#define SRSSHV_TRIM_BODVCCD_BOD_RANGE_SELECT_VCCD_Msk 0x10UL
/* SRSSHV.TRIM_OVDVCCD */
#define SRSSHV_TRIM_OVDVCCD_OVD_TRIPSEL_VCCD_Pos 0UL
#define SRSSHV_TRIM_OVDVCCD_OVD_TRIPSEL_VCCD_Msk 0xFUL
/* SRSSHV.TRIM_HPOSC0_CTL */
#define SRSSHV_TRIM_HPOSC0_CTL_CTATEF_Pos       0UL
#define SRSSHV_TRIM_HPOSC0_CTL_CTATEF_Msk       0x3UL
#define SRSSHV_TRIM_HPOSC0_CTL_PTATEF_Pos       2UL
#define SRSSHV_TRIM_HPOSC0_CTL_PTATEF_Msk       0xCUL
#define SRSSHV_TRIM_HPOSC0_CTL_CTATEC_Pos       4UL
#define SRSSHV_TRIM_HPOSC0_CTL_CTATEC_Msk       0x30UL
#define SRSSHV_TRIM_HPOSC0_CTL_PTATEC_Pos       6UL
#define SRSSHV_TRIM_HPOSC0_CTL_PTATEC_Msk       0xC0UL
/* SRSSHV.TRIM_HPOSC1_CTL */
#define SRSSHV_TRIM_HPOSC1_CTL_TCF_Pos          0UL
#define SRSSHV_TRIM_HPOSC1_CTL_TCF_Msk          0x1FUL
/* SRSSHV.TRIM_HPOSC2_CTL */
#define SRSSHV_TRIM_HPOSC2_CTL_PTAT_Pos         0UL
#define SRSSHV_TRIM_HPOSC2_CTL_PTAT_Msk         0xFFUL
/* SRSSHV.TRIM_HPOSC3_CTL */
#define SRSSHV_TRIM_HPOSC3_CTL_CTAT_Pos         0UL
#define SRSSHV_TRIM_HPOSC3_CTL_CTAT_Msk         0xFFUL
/* SRSSHV.TRIM_HPOSC4_CTL */
#define SRSSHV_TRIM_HPOSC4_CTL_TOC_Pos          0UL
#define SRSSHV_TRIM_HPOSC4_CTL_TOC_Msk          0x7UL
#define SRSSHV_TRIM_HPOSC4_CTL_HPOSC_LEAK_Pos   3UL
#define SRSSHV_TRIM_HPOSC4_CTL_HPOSC_LEAK_Msk   0xF8UL
/* SRSSHV.TRIM_PILO0_CTL */
#define SRSSHV_TRIM_PILO0_CTL_CTATEF_Pos        0UL
#define SRSSHV_TRIM_PILO0_CTL_CTATEF_Msk        0x3UL
#define SRSSHV_TRIM_PILO0_CTL_PTATEF_Pos        2UL
#define SRSSHV_TRIM_PILO0_CTL_PTATEF_Msk        0xCUL
#define SRSSHV_TRIM_PILO0_CTL_CTATEC_Pos        4UL
#define SRSSHV_TRIM_PILO0_CTL_CTATEC_Msk        0x30UL
#define SRSSHV_TRIM_PILO0_CTL_PTATEC_Pos        6UL
#define SRSSHV_TRIM_PILO0_CTL_PTATEC_Msk        0xC0UL
/* SRSSHV.TRIM_PILO1_CTL */
#define SRSSHV_TRIM_PILO1_CTL_TCF_Pos           0UL
#define SRSSHV_TRIM_PILO1_CTL_TCF_Msk           0x1FUL
/* SRSSHV.TRIM_PILO2_CTL */
#define SRSSHV_TRIM_PILO2_CTL_PTAT_Pos          0UL
#define SRSSHV_TRIM_PILO2_CTL_PTAT_Msk          0xFFUL
/* SRSSHV.TRIM_PILO3_CTL */
#define SRSSHV_TRIM_PILO3_CTL_CTAT_Pos          0UL
#define SRSSHV_TRIM_PILO3_CTL_CTAT_Msk          0xFFUL
/* SRSSHV.TRIM_PILO4_CTL */
#define SRSSHV_TRIM_PILO4_CTL_TCC_Pos           0UL
#define SRSSHV_TRIM_PILO4_CTL_TCC_Msk           0xFUL
/* SRSSHV.TRIM_PILO5_CTL */
#define SRSSHV_TRIM_PILO5_CTL_PILO_TR_LEAK_Pos  0UL
#define SRSSHV_TRIM_PILO5_CTL_PILO_TR_LEAK_Msk  0x1FUL
/* SRSSHV.TRIM_BODVDDD */
#define SRSSHV_TRIM_BODVDDD_BOD_TRIPSEL_VDDD_Pos 0UL
#define SRSSHV_TRIM_BODVDDD_BOD_TRIPSEL_VDDD_Msk 0xFUL
/* SRSSHV.TRIM_OVDVDDD */
#define SRSSHV_TRIM_OVDVDDD_OVD_TRIPSEL_VDDD_Pos 0UL
#define SRSSHV_TRIM_OVDVDDD_OVD_TRIPSEL_VDDD_Msk 0xFUL
#define SRSSHV_TRIM_OVDVDDD_OVD_RANGE_SELECT_VDDD_Pos 4UL
#define SRSSHV_TRIM_OVDVDDD_OVD_RANGE_SELECT_VDDD_Msk 0x10UL


#endif /* _CYIP_SRSSHV_H_ */


/* [] END OF FILE */
