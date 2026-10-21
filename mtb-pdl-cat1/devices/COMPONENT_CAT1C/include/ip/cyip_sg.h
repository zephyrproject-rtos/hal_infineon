/***************************************************************************//**
* \file cyip_sg.h
*
* \brief
* SG IP definitions
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

#ifndef _CYIP_SG_H_
#define _CYIP_SG_H_

#include "cyip_headers.h"

/*******************************************************************************
*                                      SG
*******************************************************************************/

#define SG_SG_STRUCT_SECTION_SIZE               0x00000100UL
#define SG_SECTION_SIZE                         0x00010000UL

/**
  * \brief Sound generator structure (SG_SG_STRUCT)
  */
typedef struct {
  __IOM uint32_t CTL;                           /*!< 0x00000000 Source control */
   __IM uint32_t RESERVED[3];
  __IOM uint32_t IF_CTL;                        /*!< 0x00000010 Interface control */
   __IM uint32_t RESERVED1[3];
  __IOM uint32_t TIME_CTL;                      /*!< 0x00000020 Time control */
  __IOM uint32_t TONE_CTL;                      /*!< 0x00000024 Tone control */
  __IOM uint32_t AMPL_CTL;                      /*!< 0x00000028 Amplitude control */
  __IOM uint32_t STEP_CTL;                      /*!< 0x0000002C Step control */
  __IOM uint32_t TIME_CTL_BUFF;                 /*!< 0x00000030 Buffered time control */
  __IOM uint32_t TONE_CTL_BUFF;                 /*!< 0x00000034 Buffered tone control */
  __IOM uint32_t AMPL_CTL_BUFF;                 /*!< 0x00000038 Buffered amplitude control */
  __IOM uint32_t STEP_CTL_BUFF;                 /*!< 0x0000003C Buffered step control */
   __IM uint32_t RESERVED2[32];
  __IOM uint32_t INTR_TX;                       /*!< 0x000000C0 Interrupt */
  __IOM uint32_t INTR_TX_SET;                   /*!< 0x000000C4 Interrupt set */
  __IOM uint32_t INTR_TX_MASK;                  /*!< 0x000000C8 Interrupt mask */
   __IM uint32_t INTR_TX_MASKED;                /*!< 0x000000CC Interrupt masked */
   __IM uint32_t RESERVED3[12];
} SG_SG_STRUCT_Type;                            /*!< Size = 256 (0x100) */

/**
  * \brief SG (SG)
  */
typedef struct {
   __IM uint32_t RESERVED[8192];
        SG_SG_STRUCT_Type SG_STRUCT[8];         /*!< 0x00008000 Sound generator structure */
} SG_Type;                                      /*!< Size = 34816 (0x8800) */


/* SG_SG_STRUCT.CTL */
#define SG_SG_STRUCT_CTL_FORMAT_Pos             0UL
#define SG_SG_STRUCT_CTL_FORMAT_Msk             0x1UL
#define SG_SG_STRUCT_CTL_ACTIVE_Pos             18UL
#define SG_SG_STRUCT_CTL_ACTIVE_Msk             0x40000UL
#define SG_SG_STRUCT_CTL_ENABLED_Pos            31UL
#define SG_SG_STRUCT_CTL_ENABLED_Msk            0x80000000UL
/* SG_SG_STRUCT.IF_CTL */
#define SG_SG_STRUCT_IF_CTL_CLOCK_DIV_Pos       0UL
#define SG_SG_STRUCT_IF_CTL_CLOCK_DIV_Msk       0xFFUL
#define SG_SG_STRUCT_IF_CTL_CLOCK_SEL_Pos       8UL
#define SG_SG_STRUCT_IF_CTL_CLOCK_SEL_Msk       0x700UL
/* SG_SG_STRUCT.TIME_CTL */
#define SG_SG_STRUCT_TIME_CTL_PERIOD8_Pos       0UL
#define SG_SG_STRUCT_TIME_CTL_PERIOD8_Msk       0xFFUL
#define SG_SG_STRUCT_TIME_CTL_NR_Pos            16UL
#define SG_SG_STRUCT_TIME_CTL_NR_Msk            0xFF0000UL
/* SG_SG_STRUCT.TONE_CTL */
#define SG_SG_STRUCT_TONE_CTL_PERIOD8_Pos       0UL
#define SG_SG_STRUCT_TONE_CTL_PERIOD8_Msk       0xFFUL
#define SG_SG_STRUCT_TONE_CTL_HIGH8_Pos         16UL
#define SG_SG_STRUCT_TONE_CTL_HIGH8_Msk         0xFF0000UL
/* SG_SG_STRUCT.AMPL_CTL */
#define SG_SG_STRUCT_AMPL_CTL_PERIOD16_Pos      0UL
#define SG_SG_STRUCT_AMPL_CTL_PERIOD16_Msk      0xFFFFUL
#define SG_SG_STRUCT_AMPL_CTL_HIGH16_Pos        16UL
#define SG_SG_STRUCT_AMPL_CTL_HIGH16_Msk        0xFFFF0000UL
/* SG_SG_STRUCT.STEP_CTL */
#define SG_SG_STRUCT_STEP_CTL_STEP_Pos          0UL
#define SG_SG_STRUCT_STEP_CTL_STEP_Msk          0xFFFFUL
#define SG_SG_STRUCT_STEP_CTL_VALID_Pos         31UL
#define SG_SG_STRUCT_STEP_CTL_VALID_Msk         0x80000000UL
/* SG_SG_STRUCT.TIME_CTL_BUFF */
#define SG_SG_STRUCT_TIME_CTL_BUFF_PERIOD8_Pos  0UL
#define SG_SG_STRUCT_TIME_CTL_BUFF_PERIOD8_Msk  0xFFUL
#define SG_SG_STRUCT_TIME_CTL_BUFF_NR_Pos       16UL
#define SG_SG_STRUCT_TIME_CTL_BUFF_NR_Msk       0xFF0000UL
/* SG_SG_STRUCT.TONE_CTL_BUFF */
#define SG_SG_STRUCT_TONE_CTL_BUFF_PERIOD8_Pos  0UL
#define SG_SG_STRUCT_TONE_CTL_BUFF_PERIOD8_Msk  0xFFUL
#define SG_SG_STRUCT_TONE_CTL_BUFF_HIGH8_Pos    16UL
#define SG_SG_STRUCT_TONE_CTL_BUFF_HIGH8_Msk    0xFF0000UL
/* SG_SG_STRUCT.AMPL_CTL_BUFF */
#define SG_SG_STRUCT_AMPL_CTL_BUFF_PERIOD16_Pos 0UL
#define SG_SG_STRUCT_AMPL_CTL_BUFF_PERIOD16_Msk 0xFFFFUL
#define SG_SG_STRUCT_AMPL_CTL_BUFF_HIGH16_Pos   16UL
#define SG_SG_STRUCT_AMPL_CTL_BUFF_HIGH16_Msk   0xFFFF0000UL
/* SG_SG_STRUCT.STEP_CTL_BUFF */
#define SG_SG_STRUCT_STEP_CTL_BUFF_STEP_Pos     0UL
#define SG_SG_STRUCT_STEP_CTL_BUFF_STEP_Msk     0xFFFFUL
#define SG_SG_STRUCT_STEP_CTL_BUFF_VALID_Pos    31UL
#define SG_SG_STRUCT_STEP_CTL_BUFF_VALID_Msk    0x80000000UL
/* SG_SG_STRUCT.INTR_TX */
#define SG_SG_STRUCT_INTR_TX_COMPLETE_Pos       0UL
#define SG_SG_STRUCT_INTR_TX_COMPLETE_Msk       0x1UL
#define SG_SG_STRUCT_INTR_TX_UNDERFLOW_Pos      2UL
#define SG_SG_STRUCT_INTR_TX_UNDERFLOW_Msk      0x4UL
#define SG_SG_STRUCT_INTR_TX_IF_UNDERFLOW_Pos   8UL
#define SG_SG_STRUCT_INTR_TX_IF_UNDERFLOW_Msk   0x100UL
/* SG_SG_STRUCT.INTR_TX_SET */
#define SG_SG_STRUCT_INTR_TX_SET_COMPLETE_Pos   0UL
#define SG_SG_STRUCT_INTR_TX_SET_COMPLETE_Msk   0x1UL
#define SG_SG_STRUCT_INTR_TX_SET_UNDERFLOW_Pos  2UL
#define SG_SG_STRUCT_INTR_TX_SET_UNDERFLOW_Msk  0x4UL
#define SG_SG_STRUCT_INTR_TX_SET_IF_UNDERFLOW_Pos 8UL
#define SG_SG_STRUCT_INTR_TX_SET_IF_UNDERFLOW_Msk 0x100UL
/* SG_SG_STRUCT.INTR_TX_MASK */
#define SG_SG_STRUCT_INTR_TX_MASK_COMPLETE_Pos  0UL
#define SG_SG_STRUCT_INTR_TX_MASK_COMPLETE_Msk  0x1UL
#define SG_SG_STRUCT_INTR_TX_MASK_UNDERFLOW_Pos 2UL
#define SG_SG_STRUCT_INTR_TX_MASK_UNDERFLOW_Msk 0x4UL
#define SG_SG_STRUCT_INTR_TX_MASK_IF_UNDERFLOW_Pos 8UL
#define SG_SG_STRUCT_INTR_TX_MASK_IF_UNDERFLOW_Msk 0x100UL
/* SG_SG_STRUCT.INTR_TX_MASKED */
#define SG_SG_STRUCT_INTR_TX_MASKED_COMPLETE_Pos 0UL
#define SG_SG_STRUCT_INTR_TX_MASKED_COMPLETE_Msk 0x1UL
#define SG_SG_STRUCT_INTR_TX_MASKED_UNDERFLOW_Pos 2UL
#define SG_SG_STRUCT_INTR_TX_MASKED_UNDERFLOW_Msk 0x4UL
#define SG_SG_STRUCT_INTR_TX_MASKED_IF_UNDERFLOW_Pos 8UL
#define SG_SG_STRUCT_INTR_TX_MASKED_IF_UNDERFLOW_Msk 0x100UL


#endif /* _CYIP_SG_H_ */


/* [] END OF FILE */
