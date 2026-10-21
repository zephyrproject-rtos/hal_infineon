/***************************************************************************//**
* \file cyip_lpcomp_v2.h
*
* \brief
* LPCOMP IP definitions
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

#ifndef _CYIP_LPCOMP_V2_H_
#define _CYIP_LPCOMP_V2_H_

#include "cyip_headers.h"

/*******************************************************************************
*                                    LPCOMP
*******************************************************************************/

#define LPCOMP_SECTION_SIZE                     0x00010000UL

/**
  * \brief Low Power Comparators (LPCOMP)
  */
typedef struct {
   __IM uint32_t ID;                            /*!< 0x00000000 ID & Revision */
  __IOM uint32_t CONFIG;                        /*!< 0x00000004 LPCOMP Configuration Register */
   __IM uint32_t RESERVED[2];
  __IOM uint32_t INTR;                          /*!< 0x00000010 LPCOMP Interrupt request register */
  __IOM uint32_t INTR_SET;                      /*!< 0x00000014 LPCOMP Interrupt set register */
  __IOM uint32_t INTR_MASK;                     /*!< 0x00000018 LPCOMP Interrupt request mask */
   __IM uint32_t INTR_MASKED;                   /*!< 0x0000001C LPCOMP Interrupt request masked */
   __IM uint32_t RESERVED1[16312];
  __IOM uint32_t TRIM1;                         /*!< 0x0000FF00 LPCOMP Trim Register */
  __IOM uint32_t TRIM2;                         /*!< 0x0000FF04 LPCOMP Trim Register */
  __IOM uint32_t TRIM3;                         /*!< 0x0000FF08 LPCOMP Trim Register */
  __IOM uint32_t TRIM4;                         /*!< 0x0000FF0C LPCOMP Trim Register */
} LPCOMP_Type;                                  /*!< Size = 65296 (0xFF10) */


/* LPCOMP.ID */
#define LPCOMP_ID_ID_Pos                        0UL
#define LPCOMP_ID_ID_Msk                        0xFFFFUL
#define LPCOMP_ID_REVISION_Pos                  16UL
#define LPCOMP_ID_REVISION_Msk                  0xFFFF0000UL
/* LPCOMP.CONFIG */
#define LPCOMP_CONFIG_MODE1_Pos                 0UL
#define LPCOMP_CONFIG_MODE1_Msk                 0x3UL
#define LPCOMP_CONFIG_HYST1_Pos                 2UL
#define LPCOMP_CONFIG_HYST1_Msk                 0x4UL
#define LPCOMP_CONFIG_FILTER1_Pos               3UL
#define LPCOMP_CONFIG_FILTER1_Msk               0x8UL
#define LPCOMP_CONFIG_INTTYPE1_Pos              4UL
#define LPCOMP_CONFIG_INTTYPE1_Msk              0x30UL
#define LPCOMP_CONFIG_OUT1_Pos                  6UL
#define LPCOMP_CONFIG_OUT1_Msk                  0x40UL
#define LPCOMP_CONFIG_ENABLE1_Pos               7UL
#define LPCOMP_CONFIG_ENABLE1_Msk               0x80UL
#define LPCOMP_CONFIG_MODE2_Pos                 8UL
#define LPCOMP_CONFIG_MODE2_Msk                 0x300UL
#define LPCOMP_CONFIG_HYST2_Pos                 10UL
#define LPCOMP_CONFIG_HYST2_Msk                 0x400UL
#define LPCOMP_CONFIG_FILTER2_Pos               11UL
#define LPCOMP_CONFIG_FILTER2_Msk               0x800UL
#define LPCOMP_CONFIG_INTTYPE2_Pos              12UL
#define LPCOMP_CONFIG_INTTYPE2_Msk              0x3000UL
#define LPCOMP_CONFIG_OUT2_Pos                  14UL
#define LPCOMP_CONFIG_OUT2_Msk                  0x4000UL
#define LPCOMP_CONFIG_ENABLE2_Pos               15UL
#define LPCOMP_CONFIG_ENABLE2_Msk               0x8000UL
#define LPCOMP_CONFIG_DSI_BYPASS1_Pos           16UL
#define LPCOMP_CONFIG_DSI_BYPASS1_Msk           0x10000UL
#define LPCOMP_CONFIG_DSI_LEVEL1_Pos            17UL
#define LPCOMP_CONFIG_DSI_LEVEL1_Msk            0x20000UL
#define LPCOMP_CONFIG_DSI_BYPASS2_Pos           20UL
#define LPCOMP_CONFIG_DSI_BYPASS2_Msk           0x100000UL
#define LPCOMP_CONFIG_DSI_LEVEL2_Pos            21UL
#define LPCOMP_CONFIG_DSI_LEVEL2_Msk            0x200000UL
/* LPCOMP.INTR */
#define LPCOMP_INTR_COMP1_Pos                   0UL
#define LPCOMP_INTR_COMP1_Msk                   0x1UL
#define LPCOMP_INTR_COMP2_Pos                   1UL
#define LPCOMP_INTR_COMP2_Msk                   0x2UL
/* LPCOMP.INTR_SET */
#define LPCOMP_INTR_SET_COMP1_Pos               0UL
#define LPCOMP_INTR_SET_COMP1_Msk               0x1UL
#define LPCOMP_INTR_SET_COMP2_Pos               1UL
#define LPCOMP_INTR_SET_COMP2_Msk               0x2UL
/* LPCOMP.INTR_MASK */
#define LPCOMP_INTR_MASK_COMP1_MASK_Pos         0UL
#define LPCOMP_INTR_MASK_COMP1_MASK_Msk         0x1UL
#define LPCOMP_INTR_MASK_COMP2_MASK_Pos         1UL
#define LPCOMP_INTR_MASK_COMP2_MASK_Msk         0x2UL
/* LPCOMP.INTR_MASKED */
#define LPCOMP_INTR_MASKED_COMP1_MASKED_Pos     0UL
#define LPCOMP_INTR_MASKED_COMP1_MASKED_Msk     0x1UL
#define LPCOMP_INTR_MASKED_COMP2_MASKED_Pos     1UL
#define LPCOMP_INTR_MASKED_COMP2_MASKED_Msk     0x2UL
/* LPCOMP.TRIM1 */
#define LPCOMP_TRIM1_COMP1_TRIMA_Pos            0UL
#define LPCOMP_TRIM1_COMP1_TRIMA_Msk            0x1FUL
/* LPCOMP.TRIM2 */
#define LPCOMP_TRIM2_COMP1_TRIMB_Pos            0UL
#define LPCOMP_TRIM2_COMP1_TRIMB_Msk            0x1FUL
/* LPCOMP.TRIM3 */
#define LPCOMP_TRIM3_COMP2_TRIMA_Pos            0UL
#define LPCOMP_TRIM3_COMP2_TRIMA_Msk            0x1FUL
/* LPCOMP.TRIM4 */
#define LPCOMP_TRIM4_COMP2_TRIMB_Pos            0UL
#define LPCOMP_TRIM4_COMP2_TRIMB_Msk            0x1FUL


#endif /* _CYIP_LPCOMP_V2_H_ */


/* [] END OF FILE */
