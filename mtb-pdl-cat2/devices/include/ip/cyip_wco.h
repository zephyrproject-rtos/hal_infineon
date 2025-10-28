/***************************************************************************//**
* \file cyip_wco.h
*
* \brief
* WCO IP definitions
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

#ifndef _CYIP_WCO_H_
#define _CYIP_WCO_H_

#include "cyip_headers.h"

/*******************************************************************************
*                                     WCO
*******************************************************************************/

#define WCO_SECTION_SIZE                        0x00010000UL

/**
  * \brief 32KHz Oscillator (WCO)
  */
typedef struct {
  __IOM uint32_t CONFIG;                        /*!< 0x00000000 WCO Configuration Register */
   __IM uint32_t STATUS;                        /*!< 0x00000004 WCO Status Register */
  __IOM uint32_t DPLL;                          /*!< 0x00000008 WCO DPLL Register */
   __IM uint32_t RESERVED[125];
   __IM uint32_t WDT_CTRLOW;                    /*!< 0x00000200 Watchdog Counters 0/1 */
   __IM uint32_t WDT_CTRHIGH;                   /*!< 0x00000204 Watchdog Counter 2 */
  __IOM uint32_t WDT_MATCH;                     /*!< 0x00000208 Watchdog counter match values */
  __IOM uint32_t WDT_CONFIG;                    /*!< 0x0000020C Watchdog Counters Configuration */
  __IOM uint32_t WDT_CONTROL;                   /*!< 0x00000210 Watchdog Counters Control */
  __IOM uint32_t WDT_CLKEN;                     /*!< 0x00000214 Watchdog Counters Clock Enable */
   __IM uint32_t RESERVED1[826];
  __IOM uint32_t TRIM;                          /*!< 0x00000F00 WCO Trim Register */
} WCO_Type;                                     /*!< Size = 3844 (0xF04) */


/* WCO.CONFIG */
#define WCO_CONFIG_LPM_EN_Pos                   0UL
#define WCO_CONFIG_LPM_EN_Msk                   0x1UL
#define WCO_CONFIG_LPM_AUTO_Pos                 1UL
#define WCO_CONFIG_LPM_AUTO_Msk                 0x2UL
#define WCO_CONFIG_EXT_INPUT_EN_Pos             2UL
#define WCO_CONFIG_EXT_INPUT_EN_Msk             0x4UL
#define WCO_CONFIG_ENBUS_Pos                    16UL
#define WCO_CONFIG_ENBUS_Msk                    0xFF0000UL
#define WCO_CONFIG_DPLL_ENABLE_Pos              30UL
#define WCO_CONFIG_DPLL_ENABLE_Msk              0x40000000UL
#define WCO_CONFIG_IP_ENABLE_Pos                31UL
#define WCO_CONFIG_IP_ENABLE_Msk                0x80000000UL
/* WCO.STATUS */
#define WCO_STATUS_OUT_BLNK_A_Pos               0UL
#define WCO_STATUS_OUT_BLNK_A_Msk               0x1UL
/* WCO.DPLL */
#define WCO_DPLL_DPLL_MULT_Pos                  0UL
#define WCO_DPLL_DPLL_MULT_Msk                  0x7FFUL
#define WCO_DPLL_DPLL_LF_IGAIN_Pos              16UL
#define WCO_DPLL_DPLL_LF_IGAIN_Msk              0x70000UL
#define WCO_DPLL_DPLL_LF_PGAIN_Pos              19UL
#define WCO_DPLL_DPLL_LF_PGAIN_Msk              0x380000UL
#define WCO_DPLL_DPLL_LF_LIMIT_Pos              22UL
#define WCO_DPLL_DPLL_LF_LIMIT_Msk              0x3FC00000UL
/* WCO.WDT_CTRLOW */
#define WCO_WDT_CTRLOW_WDT_CTR0_Pos             0UL
#define WCO_WDT_CTRLOW_WDT_CTR0_Msk             0xFFFFUL
#define WCO_WDT_CTRLOW_WDT_CTR1_Pos             16UL
#define WCO_WDT_CTRLOW_WDT_CTR1_Msk             0xFFFF0000UL
/* WCO.WDT_CTRHIGH */
#define WCO_WDT_CTRHIGH_WDT_CTR2_Pos            0UL
#define WCO_WDT_CTRHIGH_WDT_CTR2_Msk            0xFFFFFFFFUL
/* WCO.WDT_MATCH */
#define WCO_WDT_MATCH_WDT_MATCH0_Pos            0UL
#define WCO_WDT_MATCH_WDT_MATCH0_Msk            0xFFFFUL
#define WCO_WDT_MATCH_WDT_MATCH1_Pos            16UL
#define WCO_WDT_MATCH_WDT_MATCH1_Msk            0xFFFF0000UL
/* WCO.WDT_CONFIG */
#define WCO_WDT_CONFIG_WDT_MODE0_Pos            0UL
#define WCO_WDT_CONFIG_WDT_MODE0_Msk            0x3UL
#define WCO_WDT_CONFIG_WDT_CLEAR0_Pos           2UL
#define WCO_WDT_CONFIG_WDT_CLEAR0_Msk           0x4UL
#define WCO_WDT_CONFIG_WDT_CASCADE0_1_Pos       3UL
#define WCO_WDT_CONFIG_WDT_CASCADE0_1_Msk       0x8UL
#define WCO_WDT_CONFIG_WDT_MODE1_Pos            8UL
#define WCO_WDT_CONFIG_WDT_MODE1_Msk            0x300UL
#define WCO_WDT_CONFIG_WDT_CLEAR1_Pos           10UL
#define WCO_WDT_CONFIG_WDT_CLEAR1_Msk           0x400UL
#define WCO_WDT_CONFIG_WDT_CASCADE1_2_Pos       11UL
#define WCO_WDT_CONFIG_WDT_CASCADE1_2_Msk       0x800UL
#define WCO_WDT_CONFIG_WDT_MODE2_Pos            16UL
#define WCO_WDT_CONFIG_WDT_MODE2_Msk            0x10000UL
#define WCO_WDT_CONFIG_WDT_BITS2_Pos            24UL
#define WCO_WDT_CONFIG_WDT_BITS2_Msk            0x1F000000UL
#define WCO_WDT_CONFIG_LFCLK_SEL_Pos            30UL
#define WCO_WDT_CONFIG_LFCLK_SEL_Msk            0xC0000000UL
/* WCO.WDT_CONTROL */
#define WCO_WDT_CONTROL_WDT_ENABLE0_Pos         0UL
#define WCO_WDT_CONTROL_WDT_ENABLE0_Msk         0x1UL
#define WCO_WDT_CONTROL_WDT_ENABLED0_Pos        1UL
#define WCO_WDT_CONTROL_WDT_ENABLED0_Msk        0x2UL
#define WCO_WDT_CONTROL_WDT_INT0_Pos            2UL
#define WCO_WDT_CONTROL_WDT_INT0_Msk            0x4UL
#define WCO_WDT_CONTROL_WDT_RESET0_Pos          3UL
#define WCO_WDT_CONTROL_WDT_RESET0_Msk          0x8UL
#define WCO_WDT_CONTROL_WDT_ENABLE1_Pos         8UL
#define WCO_WDT_CONTROL_WDT_ENABLE1_Msk         0x100UL
#define WCO_WDT_CONTROL_WDT_ENABLED1_Pos        9UL
#define WCO_WDT_CONTROL_WDT_ENABLED1_Msk        0x200UL
#define WCO_WDT_CONTROL_WDT_INT1_Pos            10UL
#define WCO_WDT_CONTROL_WDT_INT1_Msk            0x400UL
#define WCO_WDT_CONTROL_WDT_RESET1_Pos          11UL
#define WCO_WDT_CONTROL_WDT_RESET1_Msk          0x800UL
#define WCO_WDT_CONTROL_WDT_ENABLE2_Pos         16UL
#define WCO_WDT_CONTROL_WDT_ENABLE2_Msk         0x10000UL
#define WCO_WDT_CONTROL_WDT_ENABLED2_Pos        17UL
#define WCO_WDT_CONTROL_WDT_ENABLED2_Msk        0x20000UL
#define WCO_WDT_CONTROL_WDT_INT2_Pos            18UL
#define WCO_WDT_CONTROL_WDT_INT2_Msk            0x40000UL
#define WCO_WDT_CONTROL_WDT_RESET2_Pos          19UL
#define WCO_WDT_CONTROL_WDT_RESET2_Msk          0x80000UL
/* WCO.WDT_CLKEN */
#define WCO_WDT_CLKEN_CLK_WCO_EN_FOR_WDT_Pos    0UL
#define WCO_WDT_CLKEN_CLK_WCO_EN_FOR_WDT_Msk    0x1UL
#define WCO_WDT_CLKEN_CLK_ILO_EN_FOR_WDT_Pos    1UL
#define WCO_WDT_CLKEN_CLK_ILO_EN_FOR_WDT_Msk    0x2UL
/* WCO.TRIM */
#define WCO_TRIM_XGM_Pos                        0UL
#define WCO_TRIM_XGM_Msk                        0x7UL
#define WCO_TRIM_LPM_GM_Pos                     4UL
#define WCO_TRIM_LPM_GM_Msk                     0x30UL


#endif /* _CYIP_WCO_H_ */


/* [] END OF FILE */
