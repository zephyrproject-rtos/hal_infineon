/***************************************************************************//**
* \file cyip_prgio.h
*
* \brief
* PRGIO IP definitions
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

#ifndef _CYIP_PRGIO_H_
#define _CYIP_PRGIO_H_

#include "cyip_headers.h"

/*******************************************************************************
*                                    PRGIO
*******************************************************************************/

#define PRGIO_PRT_SECTION_SIZE                  0x00000100UL
#define PRGIO_SECTION_SIZE                      0x00001000UL

/**
  * \brief Programmable IO port registers (PRGIO_PRT)
  */
typedef struct {
  __IOM uint32_t CTL;                           /*!< 0x00000000 Control register */
   __IM uint32_t RESERVED[3];
  __IOM uint32_t SYNC_CTL;                      /*!< 0x00000010 Synchronization control register */
   __IM uint32_t RESERVED1[3];
  __IOM uint32_t LUT_SEL[8];                    /*!< 0x00000020 LUT component input selection */
  __IOM uint32_t LUT_CTL[8];                    /*!< 0x00000040 LUT component control register */
   __IM uint32_t RESERVED2[24];
  __IOM uint32_t DU_SEL;                        /*!< 0x000000C0 Data unit component input selection */
  __IOM uint32_t DU_CTL;                        /*!< 0x000000C4 Data unit component control register */
   __IM uint32_t RESERVED3[10];
  __IOM uint32_t DATA;                          /*!< 0x000000F0 Data register */
   __IM uint32_t RESERVED4[3];
} PRGIO_PRT_Type;                               /*!< Size = 256 (0x100) */

/**
  * \brief Programmable IO configuration (PRGIO)
  */
typedef struct {
        PRGIO_PRT_Type PRT[8];                  /*!< 0x00000000 Programmable IO port registers */
} PRGIO_Type;                                   /*!< Size = 2048 (0x800) */


/* PRGIO_PRT.CTL */
#define PRGIO_PRT_CTL_BYPASS_Pos                0UL
#define PRGIO_PRT_CTL_BYPASS_Msk                0xFFUL
#define PRGIO_PRT_CTL_CLOCK_SRC_Pos             8UL
#define PRGIO_PRT_CTL_CLOCK_SRC_Msk             0x1F00UL
#define PRGIO_PRT_CTL_HLD_OVR_Pos               24UL
#define PRGIO_PRT_CTL_HLD_OVR_Msk               0x1000000UL
#define PRGIO_PRT_CTL_PIPELINE_EN_Pos           25UL
#define PRGIO_PRT_CTL_PIPELINE_EN_Msk           0x2000000UL
#define PRGIO_PRT_CTL_ENABLED_Pos               31UL
#define PRGIO_PRT_CTL_ENABLED_Msk               0x80000000UL
/* PRGIO_PRT.SYNC_CTL */
#define PRGIO_PRT_SYNC_CTL_IO_SYNC_EN_Pos       0UL
#define PRGIO_PRT_SYNC_CTL_IO_SYNC_EN_Msk       0xFFUL
#define PRGIO_PRT_SYNC_CTL_CHIP_SYNC_EN_Pos     8UL
#define PRGIO_PRT_SYNC_CTL_CHIP_SYNC_EN_Msk     0xFF00UL
/* PRGIO_PRT.LUT_SEL */
#define PRGIO_PRT_LUT_SEL_LUT_TR0_SEL_Pos       0UL
#define PRGIO_PRT_LUT_SEL_LUT_TR0_SEL_Msk       0xFUL
#define PRGIO_PRT_LUT_SEL_LUT_TR1_SEL_Pos       8UL
#define PRGIO_PRT_LUT_SEL_LUT_TR1_SEL_Msk       0xF00UL
#define PRGIO_PRT_LUT_SEL_LUT_TR2_SEL_Pos       16UL
#define PRGIO_PRT_LUT_SEL_LUT_TR2_SEL_Msk       0xF0000UL
/* PRGIO_PRT.LUT_CTL */
#define PRGIO_PRT_LUT_CTL_LUT_Pos               0UL
#define PRGIO_PRT_LUT_CTL_LUT_Msk               0xFFUL
#define PRGIO_PRT_LUT_CTL_LUT_OPC_Pos           8UL
#define PRGIO_PRT_LUT_CTL_LUT_OPC_Msk           0x300UL
/* PRGIO_PRT.DU_SEL */
#define PRGIO_PRT_DU_SEL_DU_TR0_SEL_Pos         0UL
#define PRGIO_PRT_DU_SEL_DU_TR0_SEL_Msk         0xFUL
#define PRGIO_PRT_DU_SEL_DU_TR1_SEL_Pos         8UL
#define PRGIO_PRT_DU_SEL_DU_TR1_SEL_Msk         0xF00UL
#define PRGIO_PRT_DU_SEL_DU_TR2_SEL_Pos         16UL
#define PRGIO_PRT_DU_SEL_DU_TR2_SEL_Msk         0xF0000UL
#define PRGIO_PRT_DU_SEL_DU_DATA0_SEL_Pos       24UL
#define PRGIO_PRT_DU_SEL_DU_DATA0_SEL_Msk       0x3000000UL
#define PRGIO_PRT_DU_SEL_DU_DATA1_SEL_Pos       28UL
#define PRGIO_PRT_DU_SEL_DU_DATA1_SEL_Msk       0x30000000UL
/* PRGIO_PRT.DU_CTL */
#define PRGIO_PRT_DU_CTL_DU_SIZE_Pos            0UL
#define PRGIO_PRT_DU_CTL_DU_SIZE_Msk            0x7UL
#define PRGIO_PRT_DU_CTL_DU_OPC_Pos             8UL
#define PRGIO_PRT_DU_CTL_DU_OPC_Msk             0xF00UL
/* PRGIO_PRT.DATA */
#define PRGIO_PRT_DATA_DATA_Pos                 0UL
#define PRGIO_PRT_DATA_DATA_Msk                 0xFFUL


#endif /* _CYIP_PRGIO_H_ */


/* [] END OF FILE */
