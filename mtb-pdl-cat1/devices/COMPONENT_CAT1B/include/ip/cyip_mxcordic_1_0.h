/***************************************************************************//**
* \file cyip_mxcordic_1_0.h
*
* \brief
* MXCORDIC_1_0 IP definitions
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

#ifndef _CYIP_MXCORDIC_1_0_H_
#define _CYIP_MXCORDIC_1_0_H_

#include "cyip_headers.h"

/*******************************************************************************
*                                 MXCORDIC_1_0
*******************************************************************************/

#define MXCORDIC_1_0_SECTION_SIZE               0x00010000UL

/**
  * \brief MXCORDIC_1_0
  */
typedef struct {
  __IOM uint32_t CTL;                           /*!< 0x00000000  */
   __IM uint32_t RESERVED;
   __IM uint32_t ID;                            /*!< 0x00000008 Module Identification Register */
   __IM uint32_t RESERVED1;
  __IOM uint32_t INTR;                          /*!< 0x00000010 Interrupt Cause Register */
  __IOM uint32_t INTR_SET;                      /*!< 0x00000014 Interrupt Set Register */
  __IOM uint32_t INTR_MASK;                     /*!< 0x00000018 Interrupt Mask Register */
   __IM uint32_t INTR_MASKED;                   /*!< 0x0000001C Interrupt Masked Register */
   __IM uint32_t RESERVED2[8];
  __IOM uint32_t KEEP;                          /*!< 0x00000040 CORDIC Keep Register */
  __IOM uint32_t CON;                           /*!< 0x00000044 CORDIC Control Register */
  __IOM uint32_t CORDX;                         /*!< 0x00000048 CORDIC X Data Register */
  __IOM uint32_t CORDY;                         /*!< 0x0000004C CORDIC Y Data Register */
  __IOM uint32_t CORDZ;                         /*!< 0x00000050 CORDIC Z Data Register */
   __IM uint32_t CORRX;                         /*!< 0x00000054 CORDIC X Result Register */
   __IM uint32_t CORRY;                         /*!< 0x00000058 CORDIC Y Result Register */
   __IM uint32_t CORRZ;                         /*!< 0x0000005C CORDIC Z Result Register */
   __IM uint32_t STAT;                          /*!< 0x00000060 CORDIC Status Register */
  __IOM uint32_t START_CMD;                     /*!< 0x00000064 CORDIC Start Command Register */
} MXCORDIC_1_0_Type;                            /*!< Size = 104 (0x68) */


/* MXCORDIC_1_0.CTL */
#define MXCORDIC_1_0_CTL_ENABLED_Pos            31UL
#define MXCORDIC_1_0_CTL_ENABLED_Msk            0x80000000UL
/* MXCORDIC_1_0.ID */
#define MXCORDIC_1_0_ID_MOD_REV_Pos             0UL
#define MXCORDIC_1_0_ID_MOD_REV_Msk             0xFFUL
#define MXCORDIC_1_0_ID_MOD_TYPE_Pos            8UL
#define MXCORDIC_1_0_ID_MOD_TYPE_Msk            0xFF00UL
#define MXCORDIC_1_0_ID_MOD_NUMBER_Pos          16UL
#define MXCORDIC_1_0_ID_MOD_NUMBER_Msk          0xFFFF0000UL
/* MXCORDIC_1_0.INTR */
#define MXCORDIC_1_0_INTR_CDEOC_Pos             2UL
#define MXCORDIC_1_0_INTR_CDEOC_Msk             0x4UL
#define MXCORDIC_1_0_INTR_CDERR_Pos             3UL
#define MXCORDIC_1_0_INTR_CDERR_Msk             0x8UL
/* MXCORDIC_1_0.INTR_SET */
#define MXCORDIC_1_0_INTR_SET_CDEOC_Pos         2UL
#define MXCORDIC_1_0_INTR_SET_CDEOC_Msk         0x4UL
#define MXCORDIC_1_0_INTR_SET_CDERR_Pos         3UL
#define MXCORDIC_1_0_INTR_SET_CDERR_Msk         0x8UL
/* MXCORDIC_1_0.INTR_MASK */
#define MXCORDIC_1_0_INTR_MASK_CDEOC_Pos        2UL
#define MXCORDIC_1_0_INTR_MASK_CDEOC_Msk        0x4UL
#define MXCORDIC_1_0_INTR_MASK_CDERR_Pos        3UL
#define MXCORDIC_1_0_INTR_MASK_CDERR_Msk        0x8UL
/* MXCORDIC_1_0.INTR_MASKED */
#define MXCORDIC_1_0_INTR_MASKED_CDEOC_Pos      2UL
#define MXCORDIC_1_0_INTR_MASKED_CDEOC_Msk      0x4UL
#define MXCORDIC_1_0_INTR_MASKED_CDERR_Pos      3UL
#define MXCORDIC_1_0_INTR_MASKED_CDERR_Msk      0x8UL
/* MXCORDIC_1_0.KEEP */
#define MXCORDIC_1_0_KEEP_KEEPX_Pos             5UL
#define MXCORDIC_1_0_KEEP_KEEPX_Msk             0x20UL
#define MXCORDIC_1_0_KEEP_KEEPY_Pos             6UL
#define MXCORDIC_1_0_KEEP_KEEPY_Msk             0x40UL
#define MXCORDIC_1_0_KEEP_KEEPZ_Pos             7UL
#define MXCORDIC_1_0_KEEP_KEEPZ_Msk             0x80UL
/* MXCORDIC_1_0.CON */
#define MXCORDIC_1_0_CON_MODE_Pos               1UL
#define MXCORDIC_1_0_CON_MODE_Msk               0x6UL
#define MXCORDIC_1_0_CON_ROTVEC_Pos             3UL
#define MXCORDIC_1_0_CON_ROTVEC_Msk             0x8UL
#define MXCORDIC_1_0_CON_ST_MODE_Pos            4UL
#define MXCORDIC_1_0_CON_ST_MODE_Msk            0x10UL
#define MXCORDIC_1_0_CON_X_USIGN_Pos            5UL
#define MXCORDIC_1_0_CON_X_USIGN_Msk            0x20UL
#define MXCORDIC_1_0_CON_MPS_Pos                6UL
#define MXCORDIC_1_0_CON_MPS_Msk                0xC0UL
#define MXCORDIC_1_0_CON_N_ITER_Pos             8UL
#define MXCORDIC_1_0_CON_N_ITER_Msk             0x700UL
/* MXCORDIC_1_0.CORDX */
#define MXCORDIC_1_0_CORDX_DATA_Pos             8UL
#define MXCORDIC_1_0_CORDX_DATA_Msk             0xFFFFFF00UL
/* MXCORDIC_1_0.CORDY */
#define MXCORDIC_1_0_CORDY_DATA_Pos             8UL
#define MXCORDIC_1_0_CORDY_DATA_Msk             0xFFFFFF00UL
/* MXCORDIC_1_0.CORDZ */
#define MXCORDIC_1_0_CORDZ_DATA_Pos             8UL
#define MXCORDIC_1_0_CORDZ_DATA_Msk             0xFFFFFF00UL
/* MXCORDIC_1_0.CORRX */
#define MXCORDIC_1_0_CORRX_RESULT_Pos           8UL
#define MXCORDIC_1_0_CORRX_RESULT_Msk           0xFFFFFF00UL
/* MXCORDIC_1_0.CORRY */
#define MXCORDIC_1_0_CORRY_RESULT_Pos           8UL
#define MXCORDIC_1_0_CORRY_RESULT_Msk           0xFFFFFF00UL
/* MXCORDIC_1_0.CORRZ */
#define MXCORDIC_1_0_CORRZ_RESULT_Pos           8UL
#define MXCORDIC_1_0_CORRZ_RESULT_Msk           0xFFFFFF00UL
/* MXCORDIC_1_0.STAT */
#define MXCORDIC_1_0_STAT_BSY_Pos               0UL
#define MXCORDIC_1_0_STAT_BSY_Msk               0x1UL
/* MXCORDIC_1_0.START_CMD */
#define MXCORDIC_1_0_START_CMD_ST_Pos           0UL
#define MXCORDIC_1_0_START_CMD_ST_Msk           0x1UL


#endif /* _CYIP_MXCORDIC_1_0_H_ */


/* [] END OF FILE */
