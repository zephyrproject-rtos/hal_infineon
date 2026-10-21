/***************************************************************************//**
* \file cyip_spcif_v6.h
*
* \brief
* SPCIF IP definitions
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

#ifndef _CYIP_SPCIF_V6_H_
#define _CYIP_SPCIF_V6_H_

#include "cyip_headers.h"

/*******************************************************************************
*                                    SPCIF
*******************************************************************************/

#define SPCIF_SECTION_SIZE                      0x00010000UL

/**
  * \brief Flash Control Interface (SPCIF)
  */
typedef struct {
  __IOM uint32_t GEOMETRY;                      /*!< 0x00000000 Flash/NVL geometry information */
   __IM uint32_t RESERVED[6];
  __IOM uint32_t NVL_WR_DATA;                   /*!< 0x0000001C NVL write data register */
   __IM uint32_t RESERVED1[500];
  __IOM uint32_t INTR;                          /*!< 0x000007F0 SPCIF interrupt request register */
  __IOM uint32_t INTR_SET;                      /*!< 0x000007F4 SPCIF interrupt set request register */
  __IOM uint32_t INTR_MASK;                     /*!< 0x000007F8 SPCIF interrupt mask register */
   __IM uint32_t INTR_MASKED;                   /*!< 0x000007FC SPCIF interrupt masked request register */
} SPCIF_Type;                                   /*!< Size = 2048 (0x800) */


/* SPCIF.GEOMETRY */
#define SPCIF_GEOMETRY_FLASH_Pos                0UL
#define SPCIF_GEOMETRY_FLASH_Msk                0x3FFFUL
#define SPCIF_GEOMETRY_SFLASH_Pos               14UL
#define SPCIF_GEOMETRY_SFLASH_Msk               0xFC000UL
#define SPCIF_GEOMETRY_NUM_FLASH_Pos            20UL
#define SPCIF_GEOMETRY_NUM_FLASH_Msk            0x300000UL
#define SPCIF_GEOMETRY_FLASH_ROW_Pos            22UL
#define SPCIF_GEOMETRY_FLASH_ROW_Msk            0xC00000UL
#define SPCIF_GEOMETRY_NVL_Pos                  24UL
#define SPCIF_GEOMETRY_NVL_Msk                  0x7F000000UL
#define SPCIF_GEOMETRY_DE_CPD_LP_Pos            31UL
#define SPCIF_GEOMETRY_DE_CPD_LP_Msk            0x80000000UL
/* SPCIF.NVL_WR_DATA */
#define SPCIF_NVL_WR_DATA_DATA_Pos              0UL
#define SPCIF_NVL_WR_DATA_DATA_Msk              0xFFUL
/* SPCIF.INTR */
#define SPCIF_INTR_TIMER_Pos                    0UL
#define SPCIF_INTR_TIMER_Msk                    0x1UL
/* SPCIF.INTR_SET */
#define SPCIF_INTR_SET_TIMER_Pos                0UL
#define SPCIF_INTR_SET_TIMER_Msk                0x1UL
/* SPCIF.INTR_MASK */
#define SPCIF_INTR_MASK_TIMER_Pos               0UL
#define SPCIF_INTR_MASK_TIMER_Msk               0x1UL
/* SPCIF.INTR_MASKED */
#define SPCIF_INTR_MASKED_TIMER_Pos             0UL
#define SPCIF_INTR_MASKED_TIMER_Msk             0x1UL


#endif /* _CYIP_SPCIF_V6_H_ */


/* [] END OF FILE */
