/***************************************************************************//**
* \file cyip_fpu_v6.h
*
* \brief
* FPU IP definitions
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

#ifndef _CYIP_FPU_V6_H_
#define _CYIP_FPU_V6_H_

#include "cyip_headers.h"

/*******************************************************************************
*                                     FPU
*******************************************************************************/

#define FPU_SECTION_SIZE                        0x00010000UL

/**
  * \brief FPU interface (FPU)
  */
typedef struct {
  __IOM uint32_t INTR;                          /*!< 0x00000000 FPU interrupt request register */
  __IOM uint32_t INTR_SET;                      /*!< 0x00000004 FPU interrupt set request register */
  __IOM uint32_t INTR_MASK;                     /*!< 0x00000008 FPU interrupt mask register */
   __IM uint32_t INTR_MASKED;                   /*!< 0x0000000C FPU interrupt masked request register */
   __IM uint32_t FPU_INFO;                      /*!< 0x00000010 FPU configuration info register */
   __IM uint32_t RESERVED[3];
  __IOM uint32_t FPU_REGION[16];                /*!< 0x00000020 FPU region register */
  __IOM uint32_t FPU_PROTECTION;                /*!< 0x00000060 SRAM execute disable register */
} FPU_Type;                                     /*!< Size = 100 (0x64) */


/* FPU.INTR */
#define FPU_INTR_FPU_INTR_Pos                   0UL
#define FPU_INTR_FPU_INTR_Msk                   0xFFFFUL
#define FPU_INTR_BULK_OPERATION_DIS_INTR_Pos    16UL
#define FPU_INTR_BULK_OPERATION_DIS_INTR_Msk    0x10000UL
#define FPU_INTR_SFLASH_PGM_ER_DIS_INTR_Pos     17UL
#define FPU_INTR_SFLASH_PGM_ER_DIS_INTR_Msk     0x20000UL
/* FPU.INTR_SET */
#define FPU_INTR_SET_FPU_INTR_SET_Pos           0UL
#define FPU_INTR_SET_FPU_INTR_SET_Msk           0x3FFFFUL
/* FPU.INTR_MASK */
#define FPU_INTR_MASK_FPU_INTR_MASK_Pos         0UL
#define FPU_INTR_MASK_FPU_INTR_MASK_Msk         0x3FFFFUL
/* FPU.INTR_MASKED */
#define FPU_INTR_MASKED_FPU_INTR_MASKED_Pos     0UL
#define FPU_INTR_MASKED_FPU_INTR_MASKED_Msk     0x3FFFFUL
/* FPU.FPU_INFO */
#define FPU_FPU_INFO_FPU_INFO_Pos               0UL
#define FPU_FPU_INFO_FPU_INFO_Msk               0x1FUL
/* FPU.FPU_REGION */
#define FPU_FPU_REGION_LOCK_Pos                 0UL
#define FPU_FPU_REGION_LOCK_Msk                 0x1UL
#define FPU_FPU_REGION_PE_PROTECT_Pos           1UL
#define FPU_FPU_REGION_PE_PROTECT_Msk           0x2UL
#define FPU_FPU_REGION_ROW_COUNT_Pos            2UL
#define FPU_FPU_REGION_ROW_COUNT_Msk            0xFFCUL
#define FPU_FPU_REGION_RES0_Pos                 12UL
#define FPU_FPU_REGION_RES0_Msk                 0xF000UL
#define FPU_FPU_REGION_START_ROW_Pos            16UL
#define FPU_FPU_REGION_START_ROW_Msk            0x3FF0000UL
#define FPU_FPU_REGION_RES1_Pos                 26UL
#define FPU_FPU_REGION_RES1_Msk                 0xFC000000UL
/* FPU.FPU_PROTECTION */
#define FPU_FPU_PROTECTION_SRAM_EXEC_DIS_Pos    0UL
#define FPU_FPU_PROTECTION_SRAM_EXEC_DIS_Msk    0x1UL
#define FPU_FPU_PROTECTION_BULK_OPERATION_DIS_Pos 1UL
#define FPU_FPU_PROTECTION_BULK_OPERATION_DIS_Msk 0x2UL
#define FPU_FPU_PROTECTION_SFLASH_PGM_ER_DIS_Pos 2UL
#define FPU_FPU_PROTECTION_SFLASH_PGM_ER_DIS_Msk 0x4UL


#endif /* _CYIP_FPU_V6_H_ */


/* [] END OF FILE */
