/***************************************************************************//**
* \file cyip_pacss.h
*
* \brief
* PACSS IP definitions
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

#ifndef _CYIP_PACSS_H_
#define _CYIP_PACSS_H_

#include "cyip_headers.h"

/*******************************************************************************
*                                    PACSS
*******************************************************************************/

#define PACSS_DCHAN_FCFG_SECTION_SIZE           0x00000010UL
#define PACSS_DCHAN_SECTION_SIZE                0x00010000UL
#define PACSS_ACHAN_SECTION_SIZE                0x00010000UL
#define PACSS_MMIO_GAINLVL_STRUCT_SECTION_SIZE  0x00000010UL
#define PACSS_MMIO_OCD_STRUCT_SECTION_SIZE      0x00000010UL
#define PACSS_MMIO_SECTION_SIZE                 0x00010000UL
#define PACSS_SECTION_SIZE                      0x00100000UL

/**
  * \brief FIR Configuration (PACSS_DCHAN_FCFG)
  */
typedef struct {
  __IOM uint32_t COEF;                          /*!< 0x00000000 Coefficient Value */
   __IM uint32_t RESERVED;
  __IOM uint32_t TAP;                           /*!< 0x00000008 Tap Value */
   __IM uint32_t RESERVED1;
} PACSS_DCHAN_FCFG_Type;                        /*!< Size = 16 (0x10) */

/**
  * \brief Digital Channel Configuration (PACSS_DCHAN)
  */
typedef struct {
  __IOM uint32_t DCHAN_CTL;                     /*!< 0x00000000 Digital Channel Control */
  __IOM uint32_t SMP_CTL;                       /*!< 0x00000004 Sample Control */
  __IOM uint32_t SMP_REF_CTL;                   /*!< 0x00000008 Sample Reference Control */
  __IOM uint32_t DEC_CTL;                       /*!< 0x0000000C Decimator Control */
  __IOM uint32_t PP_CTL;                        /*!< 0x00000010 Post Processing Control */
  __IOM uint32_t OFST_COR;                      /*!< 0x00000014 Offset Correction register */
  __IOM uint32_t GAIN_COR;                      /*!< 0x00000018 Gain Correction register */
  __IOM uint32_t RANGE_LOW;                     /*!< 0x0000001C Range Detect low value register. */
  __IOM uint32_t RANGE_HIGH;                    /*!< 0x00000020 Range detect high value register. */
  __IOM uint32_t PGA_GAIN_CTL;                  /*!< 0x00000024 PGA Gain Control register */
  __IOM uint32_t CAP_CFG0;                      /*!< 0x00000028 Capacitor Configuration 0 register */
  __IOM uint32_t CAP_CFG1;                      /*!< 0x0000002C Capacitor Configuration 1 register */
  __IOM uint32_t CAP_CFG2;                      /*!< 0x00000030 Capacitor Configuration 2 register */
  __IOM uint32_t ACC_THRESH;                    /*!< 0x00000034 Accumulated Data Threshold */
   __IM uint32_t RESERVED[2];
   __IM uint32_t RESULT;                        /*!< 0x00000040 Channel result data register, updated at the end of each
                                                                completed conversion */
   __IM uint32_t RESULT_TAG;                    /*!< 0x00000044 Tag register associated and updated simultaneously with the
                                                                RESULT register */
  __IOM uint32_t ACC_RESULT;                    /*!< 0x00000048 Channel Accumulated result data register */
   __IM uint32_t RESERVED1;
  __IOM uint32_t INTR;                          /*!< 0x00000050 Interrupt request register */
  __IOM uint32_t INTR_SET;                      /*!< 0x00000054 Interrupt set request register */
  __IOM uint32_t INTR_MASK;                     /*!< 0x00000058 Interrupt mask register */
   __IM uint32_t INTR_MASKED;                   /*!< 0x0000005C Interrupt masked request register */
   __IM uint32_t STATUS;                        /*!< 0x00000060 Status registesr */
   __IM uint32_t RESERVED2[39];
        PACSS_DCHAN_FCFG_Type FCFG[64];         /*!< 0x00000100 FIR Configuration */
   __IM uint32_t RESERVED3[16064];
} PACSS_DCHAN_Type;                             /*!< Size = 65536 (0x10000) */

/**
  * \brief Analog Channel Configuration (PACSS_ACHAN)
  */
typedef struct {
  __IOM uint32_t ACHAN_CTL;                     /*!< 0x00000000 Analog Channel Control */
  __IOM uint32_t TR_CTL;                        /*!< 0x00000004 Trigger Control for Sequencer */
  __IOM uint32_t CHOP_CTL;                      /*!< 0x00000008 Chopping Control for Sequencer */
  __IOM uint32_t PGA_CTL;                       /*!< 0x0000000C Programmable Gain Amplifier Control */
  __IOM uint32_t MOD_CTL;                       /*!< 0x00000010 Modulator Control */
  __IOM uint32_t DPATH_CTL;                     /*!< 0x00000014 Datapath Control */
  __IOM uint32_t BUF_CTL;                       /*!< 0x00000018 Buffer Control */
   __IM uint32_t RESERVED;
  __IOM uint32_t PUMP_CTL;                      /*!< 0x00000020 Pump Control */
  __IOM uint32_t REF_CTL;                       /*!< 0x00000024 Reference Control */
  __IOM uint32_t START;                         /*!< 0x00000028 Start Conversion */
  __IOM uint32_t INMUX_CTL;                     /*!< 0x0000002C INMUX Control */
  __IOM uint32_t DEM_CTL;                       /*!< 0x00000030 Dynamic Element Matching Control */
  __IOM uint32_t SWITCH;                        /*!< 0x00000034 Firmware Switch Control */
  __IOM uint32_t SWITCH_CLEAR;                  /*!< 0x00000038 Firmware Switch Control Clear */
  __IOM uint32_t SWITCH_SQ_CTL;                 /*!< 0x0000003C Switch Sequencer Control */
   __IM uint32_t SWITCH_STATUS;                 /*!< 0x00000040 Switch Status */
  __IOM uint32_t DFT_CTL;                       /*!< 0x00000044 DFT Control Register */
   __IM uint32_t DFT_STATUS;                    /*!< 0x00000048 DFT Status Register */
   __IM uint32_t RESERVED1[16301];
  __IOM uint32_t TRIM_PGA0_CTL;                 /*!< 0x0000FF00 PGA Trim 0 (lock protected) */
  __IOM uint32_t TRIM_PGA1_CTL;                 /*!< 0x0000FF04 PGA Trim 1 (lock protected) */
  __IOM uint32_t TRIM_PGA2_CTL;                 /*!< 0x0000FF08 PGA Trim 2 (lock protected) */
  __IOM uint32_t TRIM_PGA3_CTL;                 /*!< 0x0000FF0C PGA Trim 3 (lock protected) */
  __IOM uint32_t TRIM_PGA4_CTL;                 /*!< 0x0000FF10 PGA Trim 4 (lock protected) */
  __IOM uint32_t TRIM_BUF0_CTL;                 /*!< 0x0000FF14 Buffer Trim 0 (lock protected) */
  __IOM uint32_t TRIM_BUF1_CTL;                 /*!< 0x0000FF18 Buffer Trim 1 (lock protected) */
  __IOM uint32_t TRIM_BUF2_CTL;                 /*!< 0x0000FF1C Buffer Trim 2 (lock protected) */
  __IOM uint32_t TRIM_BUF3_CTL;                 /*!< 0x0000FF20 Buffer Trim 3 (lock protected) */
   __IM uint32_t RESERVED2[55];
} PACSS_ACHAN_Type;                             /*!< Size = 65536 (0x10000) */

/**
  * \brief Gain Level Configuration (PACSS_MMIO_GAINLVL_STRUCT)
  */
typedef struct {
  __IOM uint32_t GAIN_CFG0;                     /*!< 0x00000000 Gain configuration register 0 */
  __IOM uint32_t GAIN_CFG1;                     /*!< 0x00000004 Gain configuration register 1 */
  __IOM uint32_t OFST_COR;                      /*!< 0x00000008 Offset Correction register */
  __IOM uint32_t GAIN_COR;                      /*!< 0x0000000C Gain Correction register */
} PACSS_MMIO_GAINLVL_STRUCT_Type;               /*!< Size = 16 (0x10) */

/**
  * \brief Over Current Detector Configuration (PACSS_MMIO_OCD_STRUCT)
  */
typedef struct {
  __IOM uint32_t OCD_CTL;                       /*!< 0x00000000 Over Current Detector Control */
  __IOM uint32_t OCD_FILT_LIMIT;                /*!< 0x00000004 Glitch Filter Comparator Settings */
  __IOM uint32_t OCD_STATUS;                    /*!< 0x00000008 Over Current Detector Status */
  __IOM uint32_t OCD_DFT;                       /*!< 0x0000000C Over Current Detector DFT Control */
} PACSS_MMIO_OCD_STRUCT_Type;                   /*!< Size = 16 (0x10) */

/**
  * \brief PACSS Global MMIO (PACSS_MMIO)
  */
typedef struct {
  __IOM uint32_t PACSS_CTL;                     /*!< 0x00000000 Precision Analog Channel Control */
  __IOM uint32_t AGC_CTL0;                      /*!< 0x00000004 Auto-Gain Correction Control 0 */
  __IOM uint32_t AGC_CTL1;                      /*!< 0x00000008 Auto-Gain Correction Control 1 */
  __IOM uint32_t AGC_CTL2;                      /*!< 0x0000000C Auto-Gain Correction Control 2 */
  __IOM uint32_t AGC_CTL3;                      /*!< 0x00000010 Auto-Gain Correction Control 3 */
   __IM uint32_t RESERVED[3];
  __IOM uint32_t TMPS_CTL;                      /*!< 0x00000020 Temperature Sensor Control */
  __IOM uint32_t VPOS_PUMP_CTL;                 /*!< 0x00000024 Positive Pump Control */
   __IM uint32_t RESERVED1[2];
  __IOM uint32_t START;                         /*!< 0x00000030 Start Conversion */
   __IM uint32_t RESERVED2[3];
  __IOM uint32_t INTR;                          /*!< 0x00000040 System Interrupt request register */
  __IOM uint32_t INTR_SET;                      /*!< 0x00000044 System Interrupt set request register */
  __IOM uint32_t INTR_MASK;                     /*!< 0x00000048 System Interrupt mask register */
   __IM uint32_t INTR_MASKED;                   /*!< 0x0000004C System Interrupt masked request register */
   __IM uint32_t INTR_CAUSE;                    /*!< 0x00000050 Interrupt Cause Register */
   __IM uint32_t RESERVED3[3];
   __IM uint32_t STATUS0;                       /*!< 0x00000060 Status Register 0 */
   __IM uint32_t STATUS1;                       /*!< 0x00000064 Status Register 1 */
   __IM uint32_t RESERVED4[38];
        PACSS_MMIO_GAINLVL_STRUCT_Type GAINLVL_STRUCT[10]; /*!< 0x00000100 Gain Level Configuration */
   __IM uint32_t RESERVED5[216];
  __IOM uint32_t HPBGR_CTL;                     /*!< 0x00000500 High Precision Bandgap Reference Control */
   __IM uint32_t RESERVED6[3];
  __IOM uint32_t HPBGR_DFT_CTL;                 /*!< 0x00000510 High Precision Bandgap Reference DFT Control */
   __IM uint32_t RESERVED7[59];
  __IOM uint32_t AREF_CTL;                      /*!< 0x00000600 Analog Reference Control */
   __IM uint32_t RESERVED8[3];
  __IOM uint32_t AREF_DFT_CTL;                  /*!< 0x00000610 Analog Reference DFT Control */
   __IM uint32_t RESERVED9[59];
        PACSS_MMIO_OCD_STRUCT_Type OCD_STRUCT[2]; /*!< 0x00000700 Over Current Detector Configuration */
   __IM uint32_t RESERVED10[56];
  __IOM uint32_t REG_PROT;                      /*!< 0x00000800 Register Protection */
   __IM uint32_t RESERVED11[63];
  __IOM uint32_t PDFT_CTL;                      /*!< 0x00000900 PACSS DFT Control */
   __IM uint32_t RESERVED12[15743];
  __IOM uint32_t TRIM_REGL0_CTL;                /*!< 0x0000FF00 Regulator (LDO) Trim 0 (lock protected) */
  __IOM uint32_t TRIM_HPBGR0_CTL;               /*!< 0x0000FF04 High Precision Bandgap Reference Trim Control 0 (lock
                                                                protected) */
  __IOM uint32_t TRIM_HPBGR1_CTL;               /*!< 0x0000FF08 High Precision Bandgap Reference Trim Control 1 (lock
                                                                protected) */
  __IOM uint32_t TRIM_HPBGR2_CTL;               /*!< 0x0000FF0C High Precision Bandgap Reference Trim Control 2 (lock
                                                                protected) */
  __IOM uint32_t TRIM_HPBGR3_CTL;               /*!< 0x0000FF10 High Precision Bandgap Reference Trim Control 3 (lock
                                                                protected) */
  __IOM uint32_t TRIM_HPBGR4_CTL;               /*!< 0x0000FF14 High Precision Bandgap Reference Trim Control 4 (lock
                                                                protected) */
  __IOM uint32_t TRIM_AREF0_CTL;                /*!< 0x0000FF18 Analog Reference Trim Control 0 (lock protected) */
  __IOM uint32_t TRIM_AREF1_CTL;                /*!< 0x0000FF1C Analog Reference Trim Control 1 (lock protected) */
  __IOM uint32_t TRIM_AREF2_CTL;                /*!< 0x0000FF20 Analog Reference Trim Control 2 (lock protected) */
  __IOM uint32_t TRIM_AREF3_CTL;                /*!< 0x0000FF24 Analog Reference Trim Control 3 (lock protected) */
  __IOM uint32_t TRIM_AREF4_CTL;                /*!< 0x0000FF28 Analog Reference Trim Control 4 (lock protected) */
  __IOM uint32_t TRIM_AREF5_CTL;                /*!< 0x0000FF2C Analog Reference Trim Control 5 (lock protected) */
  __IOM uint32_t TRIM_AREF6_CTL;                /*!< 0x0000FF30 Analog Reference Trim Control 6 (lock protected) */
  __IOM uint32_t TRIM_OCD00_CTL;                /*!< 0x0000FF34 Trim Control 0 for Over Current Detector 0 (lock protected) */
  __IOM uint32_t TRIM_OCD01_CTL;                /*!< 0x0000FF38 Trim Control 0 for Over Current Detector 1 (lock protected) */
  __IOM uint32_t TRIM_OCD10_CTL;                /*!< 0x0000FF3C Trim Control 1 for Over Current Detector 0 (lock protected)) */
  __IOM uint32_t TRIM_OCD11_CTL;                /*!< 0x0000FF40 Trim Control 1 for Over Current Detector 1 (lock protected) */
   __IM uint32_t RESERVED13[47];
} PACSS_MMIO_Type;                              /*!< Size = 65536 (0x10000) */

/**
  * \brief Programmable Analog Channel Sub-System (PACSS)
  */
typedef struct {
        PACSS_DCHAN_Type DCHAN[4];              /*!< 0x00000000 Digital Channel Configuration */
        PACSS_ACHAN_Type ACHAN[2];              /*!< 0x00040000 Analog Channel Configuration */
   __IM uint32_t RESERVED[147456];
        PACSS_MMIO_Type MMIO;                   /*!< 0x000F0000 PACSS Global MMIO */
} PACSS_Type;                                   /*!< Size = 1048576 (0x100000) */


/* PACSS_DCHAN_FCFG.COEF */
#define PACSS_DCHAN_FCFG_COEF_COEF_Pos          0UL
#define PACSS_DCHAN_FCFG_COEF_COEF_Msk          0xFFFFUL
/* PACSS_DCHAN_FCFG.TAP */
#define PACSS_DCHAN_FCFG_TAP_TAP_Pos            0UL
#define PACSS_DCHAN_FCFG_TAP_TAP_Msk            0xFFFFFFFFUL


/* PACSS_DCHAN.DCHAN_CTL */
#define PACSS_DCHAN_DCHAN_CTL_AGC_GAIN_EN_Pos   0UL
#define PACSS_DCHAN_DCHAN_CTL_AGC_GAIN_EN_Msk   0x1UL
#define PACSS_DCHAN_DCHAN_CTL_PP_EN_Pos         1UL
#define PACSS_DCHAN_DCHAN_CTL_PP_EN_Msk         0x2UL
#define PACSS_DCHAN_DCHAN_CTL_FIR_EN_Pos        2UL
#define PACSS_DCHAN_DCHAN_CTL_FIR_EN_Msk        0x4UL
#define PACSS_DCHAN_DCHAN_CTL_FIR_NUM_TAPS_Pos  4UL
#define PACSS_DCHAN_DCHAN_CTL_FIR_NUM_TAPS_Msk  0x3F0UL
#define PACSS_DCHAN_DCHAN_CTL_SEC_EN_Pos        30UL
#define PACSS_DCHAN_DCHAN_CTL_SEC_EN_Msk        0x40000000UL
#define PACSS_DCHAN_DCHAN_CTL_ENABLE_Pos        31UL
#define PACSS_DCHAN_DCHAN_CTL_ENABLE_Msk        0x80000000UL
/* PACSS_DCHAN.SMP_CTL */
#define PACSS_DCHAN_SMP_CTL_ACHAN_SEL_Pos       0UL
#define PACSS_DCHAN_SMP_CTL_ACHAN_SEL_Msk       0x1UL
#define PACSS_DCHAN_SMP_CTL_POS_PIN_SEL_Pos     4UL
#define PACSS_DCHAN_SMP_CTL_POS_PIN_SEL_Msk     0x7F0UL
#define PACSS_DCHAN_SMP_CTL_NEG_PIN_SEL_Pos     12UL
#define PACSS_DCHAN_SMP_CTL_NEG_PIN_SEL_Msk     0x1F000UL
#define PACSS_DCHAN_SMP_CTL_BYPASS_AAF_Pos      18UL
#define PACSS_DCHAN_SMP_CTL_BYPASS_AAF_Msk      0x40000UL
#define PACSS_DCHAN_SMP_CTL_AAF_SHORT_R_EN_Pos  19UL
#define PACSS_DCHAN_SMP_CTL_AAF_SHORT_R_EN_Msk  0x80000UL
#define PACSS_DCHAN_SMP_CTL_CH_SEL_DLY_Pos      20UL
#define PACSS_DCHAN_SMP_CTL_CH_SEL_DLY_Msk      0xFF00000UL
#define PACSS_DCHAN_SMP_CTL_AVG_MODE_Pos        28UL
#define PACSS_DCHAN_SMP_CTL_AVG_MODE_Msk        0x30000000UL
#define PACSS_DCHAN_SMP_CTL_MOV_SUM_Pos         30UL
#define PACSS_DCHAN_SMP_CTL_MOV_SUM_Msk         0x40000000UL
/* PACSS_DCHAN.SMP_REF_CTL */
#define PACSS_DCHAN_SMP_REF_CTL_VREFH_SEL_Pos   0UL
#define PACSS_DCHAN_SMP_REF_CTL_VREFH_SEL_Msk   0x7UL
#define PACSS_DCHAN_SMP_REF_CTL_VREFL_SEL_Pos   4UL
#define PACSS_DCHAN_SMP_REF_CTL_VREFL_SEL_Msk   0x30UL
#define PACSS_DCHAN_SMP_REF_CTL_VREF_BUF_EN_Pos 8UL
#define PACSS_DCHAN_SMP_REF_CTL_VREF_BUF_EN_Msk 0x100UL
#define PACSS_DCHAN_SMP_REF_CTL_RS_PULLUP_SEL_Pos 16UL
#define PACSS_DCHAN_SMP_REF_CTL_RS_PULLUP_SEL_Msk 0x30000UL
#define PACSS_DCHAN_SMP_REF_CTL_RS_PULLUP_EN_Pos 18UL
#define PACSS_DCHAN_SMP_REF_CTL_RS_PULLUP_EN_Msk 0x40000UL
/* PACSS_DCHAN.DEC_CTL */
#define PACSS_DCHAN_DEC_CTL_SINC_MODE_Pos       0UL
#define PACSS_DCHAN_DEC_CTL_SINC_MODE_Msk       0x1UL
#define PACSS_DCHAN_DEC_CTL_CONV_MODE_Pos       1UL
#define PACSS_DCHAN_DEC_CTL_CONV_MODE_Msk       0x2UL
#define PACSS_DCHAN_DEC_CTL_OCOR_EN_Pos         2UL
#define PACSS_DCHAN_DEC_CTL_OCOR_EN_Msk         0x4UL
#define PACSS_DCHAN_DEC_CTL_GCOR_EN_Pos         3UL
#define PACSS_DCHAN_DEC_CTL_GCOR_EN_Msk         0x8UL
#define PACSS_DCHAN_DEC_CTL_DR_Pos              4UL
#define PACSS_DCHAN_DEC_CTL_DR_Msk              0x7F0UL
#define PACSS_DCHAN_DEC_CTL_SAT_EN_Pos          11UL
#define PACSS_DCHAN_DEC_CTL_SAT_EN_Msk          0x800UL
#define PACSS_DCHAN_DEC_CTL_DR2_Pos             12UL
#define PACSS_DCHAN_DEC_CTL_DR2_Msk             0x1F000UL
#define PACSS_DCHAN_DEC_CTL_SHIFTL_Pos          20UL
#define PACSS_DCHAN_DEC_CTL_SHIFTL_Msk          0xF00000UL
#define PACSS_DCHAN_DEC_CTL_DEC_SHIFTR_Pos      24UL
#define PACSS_DCHAN_DEC_CTL_DEC_SHIFTR_Msk      0xF000000UL
#define PACSS_DCHAN_DEC_CTL_RR_SHIFTR_Pos       28UL
#define PACSS_DCHAN_DEC_CTL_RR_SHIFTR_Msk       0xF0000000UL
/* PACSS_DCHAN.PP_CTL */
#define PACSS_DCHAN_PP_CTL_PP_SHIFTR_Pos        0UL
#define PACSS_DCHAN_PP_CTL_PP_SHIFTR_Msk        0xFUL
#define PACSS_DCHAN_PP_CTL_CLAMP_Pos            8UL
#define PACSS_DCHAN_PP_CTL_CLAMP_Msk            0x100UL
#define PACSS_DCHAN_PP_CTL_RANGE_DET_EN_Pos     16UL
#define PACSS_DCHAN_PP_CTL_RANGE_DET_EN_Msk     0x30000UL
#define PACSS_DCHAN_PP_CTL_RANGE_COND_Pos       20UL
#define PACSS_DCHAN_PP_CTL_RANGE_COND_Msk       0x300000UL
#define PACSS_DCHAN_PP_CTL_RANGE_CNT_VAL_Pos    24UL
#define PACSS_DCHAN_PP_CTL_RANGE_CNT_VAL_Msk    0xFF000000UL
/* PACSS_DCHAN.OFST_COR */
#define PACSS_DCHAN_OFST_COR_OCOR_Pos           0UL
#define PACSS_DCHAN_OFST_COR_OCOR_Msk           0xFFFFUL
#define PACSS_DCHAN_OFST_COR_OCOR_SCLR_Pos      16UL
#define PACSS_DCHAN_OFST_COR_OCOR_SCLR_Msk      0xF0000UL
/* PACSS_DCHAN.GAIN_COR */
#define PACSS_DCHAN_GAIN_COR_GCOR_Pos           0UL
#define PACSS_DCHAN_GAIN_COR_GCOR_Msk           0xFFFFUL
#define PACSS_DCHAN_GAIN_COR_GVAL_Pos           16UL
#define PACSS_DCHAN_GAIN_COR_GVAL_Msk           0xF0000UL
/* PACSS_DCHAN.RANGE_LOW */
#define PACSS_DCHAN_RANGE_LOW_RANGE_LOW_Pos     0UL
#define PACSS_DCHAN_RANGE_LOW_RANGE_LOW_Msk     0xFFFFFFFFUL
/* PACSS_DCHAN.RANGE_HIGH */
#define PACSS_DCHAN_RANGE_HIGH_RANGE_HIGH_Pos   0UL
#define PACSS_DCHAN_RANGE_HIGH_RANGE_HIGH_Msk   0xFFFFFFFFUL
/* PACSS_DCHAN.PGA_GAIN_CTL */
#define PACSS_DCHAN_PGA_GAIN_CTL_GAIN_Pos       0UL
#define PACSS_DCHAN_PGA_GAIN_CTL_GAIN_Msk       0x7UL
/* PACSS_DCHAN.CAP_CFG0 */
#define PACSS_DCHAN_CAP_CFG0_FCAP1_Pos          0UL
#define PACSS_DCHAN_CAP_CFG0_FCAP1_Msk          0x7FUL
#define PACSS_DCHAN_CAP_CFG0_FCAP2_Pos          12UL
#define PACSS_DCHAN_CAP_CFG0_FCAP2_Msk          0xF000UL
#define PACSS_DCHAN_CAP_CFG0_FCAP3_Pos          20UL
#define PACSS_DCHAN_CAP_CFG0_FCAP3_Msk          0xF00000UL
#define PACSS_DCHAN_CAP_CFG0_RESCAP_Pos         28UL
#define PACSS_DCHAN_CAP_CFG0_RESCAP_Msk         0x70000000UL
/* PACSS_DCHAN.CAP_CFG1 */
#define PACSS_DCHAN_CAP_CFG1_DACCAP_Pos         0UL
#define PACSS_DCHAN_CAP_CFG1_DACCAP_Msk         0x3FUL
#define PACSS_DCHAN_CAP_CFG1_IPCAP1_Pos         8UL
#define PACSS_DCHAN_CAP_CFG1_IPCAP1_Msk         0x3F00UL
#define PACSS_DCHAN_CAP_CFG1_IPCAP2_Pos         20UL
#define PACSS_DCHAN_CAP_CFG1_IPCAP2_Msk         0x700000UL
#define PACSS_DCHAN_CAP_CFG1_IPCAP3_Pos         24UL
#define PACSS_DCHAN_CAP_CFG1_IPCAP3_Msk         0x7000000UL
/* PACSS_DCHAN.CAP_CFG2 */
#define PACSS_DCHAN_CAP_CFG2_SUMCAPIN_Pos       0UL
#define PACSS_DCHAN_CAP_CFG2_SUMCAPIN_Msk       0x1FUL
#define PACSS_DCHAN_CAP_CFG2_SUMCAP1_Pos        8UL
#define PACSS_DCHAN_CAP_CFG2_SUMCAP1_Msk        0x700UL
#define PACSS_DCHAN_CAP_CFG2_SUMCAP2_Pos        12UL
#define PACSS_DCHAN_CAP_CFG2_SUMCAP2_Msk        0x7000UL
#define PACSS_DCHAN_CAP_CFG2_SUMCAP3_Pos        16UL
#define PACSS_DCHAN_CAP_CFG2_SUMCAP3_Msk        0x70000UL
#define PACSS_DCHAN_CAP_CFG2_SUMCAPFB_Pos       20UL
#define PACSS_DCHAN_CAP_CFG2_SUMCAPFB_Msk       0xF00000UL
/* PACSS_DCHAN.ACC_THRESH */
#define PACSS_DCHAN_ACC_THRESH_ACC_THRESH_Pos   0UL
#define PACSS_DCHAN_ACC_THRESH_ACC_THRESH_Msk   0xFFFFFFFFUL
/* PACSS_DCHAN.RESULT */
#define PACSS_DCHAN_RESULT_RESULT_Pos           0UL
#define PACSS_DCHAN_RESULT_RESULT_Msk           0xFFFFFFFFUL
/* PACSS_DCHAN.RESULT_TAG */
#define PACSS_DCHAN_RESULT_TAG_RESULT_PARITY_Pos 0UL
#define PACSS_DCHAN_RESULT_TAG_RESULT_PARITY_Msk 0x7FUL
#define PACSS_DCHAN_RESULT_TAG_SMP_COUNT_Pos    8UL
#define PACSS_DCHAN_RESULT_TAG_SMP_COUNT_Msk    0x3F00UL
#define PACSS_DCHAN_RESULT_TAG_DCH_ID_Pos       16UL
#define PACSS_DCHAN_RESULT_TAG_DCH_ID_Msk       0x30000UL
#define PACSS_DCHAN_RESULT_TAG_DATA_TYPE_Pos    20UL
#define PACSS_DCHAN_RESULT_TAG_DATA_TYPE_Msk    0x7F00000UL
/* PACSS_DCHAN.ACC_RESULT */
#define PACSS_DCHAN_ACC_RESULT_ACC_RESULT_Pos   0UL
#define PACSS_DCHAN_ACC_RESULT_ACC_RESULT_Msk   0xFFFFFFFFUL
/* PACSS_DCHAN.INTR */
#define PACSS_DCHAN_INTR_DATA_VAL_INTR_Pos      0UL
#define PACSS_DCHAN_INTR_DATA_VAL_INTR_Msk      0x1UL
#define PACSS_DCHAN_INTR_OVERFLOW_INTR_Pos      1UL
#define PACSS_DCHAN_INTR_OVERFLOW_INTR_Msk      0x2UL
#define PACSS_DCHAN_INTR_FWT_COLLISION_INTR_Pos 2UL
#define PACSS_DCHAN_INTR_FWT_COLLISION_INTR_Msk 0x4UL
#define PACSS_DCHAN_INTR_HWT_COLLISION_INTR_Pos 3UL
#define PACSS_DCHAN_INTR_HWT_COLLISION_INTR_Msk 0x8UL
#define PACSS_DCHAN_INTR_OVERLOAD_INTR_Pos      4UL
#define PACSS_DCHAN_INTR_OVERLOAD_INTR_Msk      0x10UL
#define PACSS_DCHAN_INTR_SATURATE_INTR_Pos      5UL
#define PACSS_DCHAN_INTR_SATURATE_INTR_Msk      0x20UL
#define PACSS_DCHAN_INTR_ACC_THRESH_INTR_Pos    6UL
#define PACSS_DCHAN_INTR_ACC_THRESH_INTR_Msk    0x40UL
#define PACSS_DCHAN_INTR_RANGE_INTR_Pos         7UL
#define PACSS_DCHAN_INTR_RANGE_INTR_Msk         0x80UL
/* PACSS_DCHAN.INTR_SET */
#define PACSS_DCHAN_INTR_SET_DATA_VAL_SET_Pos   0UL
#define PACSS_DCHAN_INTR_SET_DATA_VAL_SET_Msk   0x1UL
#define PACSS_DCHAN_INTR_SET_OVERFLOW_SET_Pos   1UL
#define PACSS_DCHAN_INTR_SET_OVERFLOW_SET_Msk   0x2UL
#define PACSS_DCHAN_INTR_SET_FWT_COLLISION_SET_Pos 2UL
#define PACSS_DCHAN_INTR_SET_FWT_COLLISION_SET_Msk 0x4UL
#define PACSS_DCHAN_INTR_SET_HWT_COLLISION_SET_Pos 3UL
#define PACSS_DCHAN_INTR_SET_HWT_COLLISION_SET_Msk 0x8UL
#define PACSS_DCHAN_INTR_SET_OVERLOAD_SET_Pos   4UL
#define PACSS_DCHAN_INTR_SET_OVERLOAD_SET_Msk   0x10UL
#define PACSS_DCHAN_INTR_SET_SATURATE_SET_Pos   5UL
#define PACSS_DCHAN_INTR_SET_SATURATE_SET_Msk   0x20UL
#define PACSS_DCHAN_INTR_SET_ACC_THRESH_SET_Pos 6UL
#define PACSS_DCHAN_INTR_SET_ACC_THRESH_SET_Msk 0x40UL
#define PACSS_DCHAN_INTR_SET_RANGE_SET_Pos      7UL
#define PACSS_DCHAN_INTR_SET_RANGE_SET_Msk      0x80UL
/* PACSS_DCHAN.INTR_MASK */
#define PACSS_DCHAN_INTR_MASK_DATA_VAL_MASK_Pos 0UL
#define PACSS_DCHAN_INTR_MASK_DATA_VAL_MASK_Msk 0x1UL
#define PACSS_DCHAN_INTR_MASK_OVERFLOW_MASK_Pos 1UL
#define PACSS_DCHAN_INTR_MASK_OVERFLOW_MASK_Msk 0x2UL
#define PACSS_DCHAN_INTR_MASK_FWT_COLLISION_MASK_Pos 2UL
#define PACSS_DCHAN_INTR_MASK_FWT_COLLISION_MASK_Msk 0x4UL
#define PACSS_DCHAN_INTR_MASK_HWT_COLLISION_MASK_Pos 3UL
#define PACSS_DCHAN_INTR_MASK_HWT_COLLISION_MASK_Msk 0x8UL
#define PACSS_DCHAN_INTR_MASK_OVERLOAD_MASK_Pos 4UL
#define PACSS_DCHAN_INTR_MASK_OVERLOAD_MASK_Msk 0x10UL
#define PACSS_DCHAN_INTR_MASK_SATURATE_MASK_Pos 5UL
#define PACSS_DCHAN_INTR_MASK_SATURATE_MASK_Msk 0x20UL
#define PACSS_DCHAN_INTR_MASK_ACC_THRESH_MASK_Pos 6UL
#define PACSS_DCHAN_INTR_MASK_ACC_THRESH_MASK_Msk 0x40UL
#define PACSS_DCHAN_INTR_MASK_RANGE_MASK_Pos    7UL
#define PACSS_DCHAN_INTR_MASK_RANGE_MASK_Msk    0x80UL
/* PACSS_DCHAN.INTR_MASKED */
#define PACSS_DCHAN_INTR_MASKED_DATA_VAL_MASKED_Pos 0UL
#define PACSS_DCHAN_INTR_MASKED_DATA_VAL_MASKED_Msk 0x1UL
#define PACSS_DCHAN_INTR_MASKED_OVERFLOW_MASKED_Pos 1UL
#define PACSS_DCHAN_INTR_MASKED_OVERFLOW_MASKED_Msk 0x2UL
#define PACSS_DCHAN_INTR_MASKED_FWT_COLLISION_MASKED_Pos 2UL
#define PACSS_DCHAN_INTR_MASKED_FWT_COLLISION_MASKED_Msk 0x4UL
#define PACSS_DCHAN_INTR_MASKED_HWT_COLLISION_MASKED_Pos 3UL
#define PACSS_DCHAN_INTR_MASKED_HWT_COLLISION_MASKED_Msk 0x8UL
#define PACSS_DCHAN_INTR_MASKED_OVERLOAD_MASKED_Pos 4UL
#define PACSS_DCHAN_INTR_MASKED_OVERLOAD_MASKED_Msk 0x10UL
#define PACSS_DCHAN_INTR_MASKED_SATURATE_MASKED_Pos 5UL
#define PACSS_DCHAN_INTR_MASKED_SATURATE_MASKED_Msk 0x20UL
#define PACSS_DCHAN_INTR_MASKED_ACC_THRESH_MASKED_Pos 6UL
#define PACSS_DCHAN_INTR_MASKED_ACC_THRESH_MASKED_Msk 0x40UL
#define PACSS_DCHAN_INTR_MASKED_RANGE_MASKED_Pos 7UL
#define PACSS_DCHAN_INTR_MASKED_RANGE_MASKED_Msk 0x80UL
/* PACSS_DCHAN.STATUS */
#define PACSS_DCHAN_STATUS_OVERLOAD_CAUSE_Pos   0UL
#define PACSS_DCHAN_STATUS_OVERLOAD_CAUSE_Msk   0x1UL


/* PACSS_ACHAN.ACHAN_CTL */
#define PACSS_ACHAN_ACHAN_CTL_MOD_EN_Pos        0UL
#define PACSS_ACHAN_ACHAN_CTL_MOD_EN_Msk        0x1UL
#define PACSS_ACHAN_ACHAN_CTL_PGA_EN_Pos        1UL
#define PACSS_ACHAN_ACHAN_CTL_PGA_EN_Msk        0x2UL
#define PACSS_ACHAN_ACHAN_CTL_BUF_EN_Pos        2UL
#define PACSS_ACHAN_ACHAN_CTL_BUF_EN_Msk        0x4UL
#define PACSS_ACHAN_ACHAN_CTL_REF_EN_Pos        3UL
#define PACSS_ACHAN_ACHAN_CTL_REF_EN_Msk        0x8UL
#define PACSS_ACHAN_ACHAN_CTL_VCCA_RES_EN_Pos   8UL
#define PACSS_ACHAN_ACHAN_CTL_VCCA_RES_EN_Msk   0x100UL
#define PACSS_ACHAN_ACHAN_CTL_VDDA_RES_EN_Pos   9UL
#define PACSS_ACHAN_ACHAN_CTL_VDDA_RES_EN_Msk   0x200UL
#define PACSS_ACHAN_ACHAN_CTL_VCM_BUF_EN_Pos    10UL
#define PACSS_ACHAN_ACHAN_CTL_VCM_BUF_EN_Msk    0x400UL
#define PACSS_ACHAN_ACHAN_CTL_AAF_CUTOFF_FREQ_Pos 16UL
#define PACSS_ACHAN_ACHAN_CTL_AAF_CUTOFF_FREQ_Msk 0x30000UL
#define PACSS_ACHAN_ACHAN_CTL_ENABLE_Pos        31UL
#define PACSS_ACHAN_ACHAN_CTL_ENABLE_Msk        0x80000000UL
/* PACSS_ACHAN.TR_CTL */
#define PACSS_ACHAN_TR_CTL_PRIM_TR_SEL_Pos      0UL
#define PACSS_ACHAN_TR_CTL_PRIM_TR_SEL_Msk      0x3UL
#define PACSS_ACHAN_TR_CTL_SYNC_PRIM_TR_Pos     2UL
#define PACSS_ACHAN_TR_CTL_SYNC_PRIM_TR_Msk     0x4UL
#define PACSS_ACHAN_TR_CTL_PRIM_TR_EN_Pos       3UL
#define PACSS_ACHAN_TR_CTL_PRIM_TR_EN_Msk       0x8UL
#define PACSS_ACHAN_TR_CTL_PEND_SEC_TR_SEL_Pos  4UL
#define PACSS_ACHAN_TR_CTL_PEND_SEC_TR_SEL_Msk  0x30UL
#define PACSS_ACHAN_TR_CTL_SYNC_SEC_TR_Pos      6UL
#define PACSS_ACHAN_TR_CTL_SYNC_SEC_TR_Msk      0x40UL
#define PACSS_ACHAN_TR_CTL_PEND_SEC_TR_EN_Pos   7UL
#define PACSS_ACHAN_TR_CTL_PEND_SEC_TR_EN_Msk   0x80UL
/* PACSS_ACHAN.CHOP_CTL */
#define PACSS_ACHAN_CHOP_CTL_SMP_CNT_Pos        0UL
#define PACSS_ACHAN_CHOP_CTL_SMP_CNT_Msk        0xFUL
#define PACSS_ACHAN_CHOP_CTL_AAF_SHORT_R_CNT_Pos 8UL
#define PACSS_ACHAN_CHOP_CTL_AAF_SHORT_R_CNT_Msk 0xFF00UL
#define PACSS_ACHAN_CHOP_CTL_DEC_BLANK_CNT_Pos  16UL
#define PACSS_ACHAN_CHOP_CTL_DEC_BLANK_CNT_Msk  0xFF0000UL
#define PACSS_ACHAN_CHOP_CTL_CHOP_MODE_Pos      24UL
#define PACSS_ACHAN_CHOP_CTL_CHOP_MODE_Msk      0x3000000UL
#define PACSS_ACHAN_CHOP_CTL_CIRCUIT_CHOP_Pos   28UL
#define PACSS_ACHAN_CHOP_CTL_CIRCUIT_CHOP_Msk   0x30000000UL
#define PACSS_ACHAN_CHOP_CTL_CIRCUIT_2ND_EN_Pos 30UL
#define PACSS_ACHAN_CHOP_CTL_CIRCUIT_2ND_EN_Msk 0x40000000UL
#define PACSS_ACHAN_CHOP_CTL_CHOP_RST_EN_Pos    31UL
#define PACSS_ACHAN_CHOP_CTL_CHOP_RST_EN_Msk    0x80000000UL
/* PACSS_ACHAN.PGA_CTL */
#define PACSS_ACHAN_PGA_CTL_PGA_PWR_LEVELS_Pos  0UL
#define PACSS_ACHAN_PGA_CTL_PGA_PWR_LEVELS_Msk  0x3UL
#define PACSS_ACHAN_PGA_CTL_PGA_CHOP_EN_Pos     4UL
#define PACSS_ACHAN_PGA_CTL_PGA_CHOP_EN_Msk     0x10UL
#define PACSS_ACHAN_PGA_CTL_PGA_IDAC_EN_Pos     5UL
#define PACSS_ACHAN_PGA_CTL_PGA_IDAC_EN_Msk     0x20UL
#define PACSS_ACHAN_PGA_CTL_PGA_OVERLAP_EN_Pos  8UL
#define PACSS_ACHAN_PGA_CTL_PGA_OVERLAP_EN_Msk  0x100UL
#define PACSS_ACHAN_PGA_CTL_PGA_DYN_DIODE_BIAS_Pos 9UL
#define PACSS_ACHAN_PGA_CTL_PGA_DYN_DIODE_BIAS_Msk 0x200UL
#define PACSS_ACHAN_PGA_CTL_PGA_BW_BOOST_EN_Pos 10UL
#define PACSS_ACHAN_PGA_CTL_PGA_BW_BOOST_EN_Msk 0x400UL
/* PACSS_ACHAN.MOD_CTL */
#define PACSS_ACHAN_MOD_CTL_POWER1_Pos          0UL
#define PACSS_ACHAN_MOD_CTL_POWER1_Msk          0x7UL
#define PACSS_ACHAN_MOD_CTL_POWER2_3_Pos        4UL
#define PACSS_ACHAN_MOD_CTL_POWER2_3_Msk        0x70UL
#define PACSS_ACHAN_MOD_CTL_POWER_COMP_Pos      8UL
#define PACSS_ACHAN_MOD_CTL_POWER_COMP_Msk      0x300UL
#define PACSS_ACHAN_MOD_CTL_POWER_SUM_Pos       12UL
#define PACSS_ACHAN_MOD_CTL_POWER_SUM_Msk       0x7000UL
#define PACSS_ACHAN_MOD_CTL_MOD_FCHOP_Pos       24UL
#define PACSS_ACHAN_MOD_CTL_MOD_FCHOP_Msk       0x7000000UL
#define PACSS_ACHAN_MOD_CTL_MOD_CHOP_EN_Pos     27UL
#define PACSS_ACHAN_MOD_CTL_MOD_CHOP_EN_Msk     0x8000000UL
/* PACSS_ACHAN.DPATH_CTL */
#define PACSS_ACHAN_DPATH_CTL_QLEV_Pos          0UL
#define PACSS_ACHAN_DPATH_CTL_QLEV_Msk          0x3UL
#define PACSS_ACHAN_DPATH_CTL_NONOV_Pos         2UL
#define PACSS_ACHAN_DPATH_CTL_NONOV_Msk         0xCUL
#define PACSS_ACHAN_DPATH_CTL_ODET_TH_Pos       8UL
#define PACSS_ACHAN_DPATH_CTL_ODET_TH_Msk       0x1F00UL
#define PACSS_ACHAN_DPATH_CTL_OD_EN_Pos         13UL
#define PACSS_ACHAN_DPATH_CTL_OD_EN_Msk         0x2000UL
#define PACSS_ACHAN_DPATH_CTL_MX_DIN_Pos        14UL
#define PACSS_ACHAN_DPATH_CTL_MX_DIN_Msk        0x4000UL
#define PACSS_ACHAN_DPATH_CTL_BUF_PGA_FCHOP_Pos 16UL
#define PACSS_ACHAN_DPATH_CTL_BUF_PGA_FCHOP_Msk 0x70000UL
#define PACSS_ACHAN_DPATH_CTL_BUF_PGA_CHOP_CLK_EN_Pos 19UL
#define PACSS_ACHAN_DPATH_CTL_BUF_PGA_CHOP_CLK_EN_Msk 0x80000UL
#define PACSS_ACHAN_DPATH_CTL_RESET1_EN_Pos     20UL
#define PACSS_ACHAN_DPATH_CTL_RESET1_EN_Msk     0x100000UL
#define PACSS_ACHAN_DPATH_CTL_RESET2_EN_Pos     21UL
#define PACSS_ACHAN_DPATH_CTL_RESET2_EN_Msk     0x200000UL
#define PACSS_ACHAN_DPATH_CTL_RESET3_EN_Pos     22UL
#define PACSS_ACHAN_DPATH_CTL_RESET3_EN_Msk     0x400000UL
#define PACSS_ACHAN_DPATH_CTL_MX_DOUT_Pos       24UL
#define PACSS_ACHAN_DPATH_CTL_MX_DOUT_Msk       0x3000000UL
#define PACSS_ACHAN_DPATH_CTL_FCLOCK_EN_Pos     28UL
#define PACSS_ACHAN_DPATH_CTL_FCLOCK_EN_Msk     0x10000000UL
/* PACSS_ACHAN.BUF_CTL */
#define PACSS_ACHAN_BUF_CTL_BUF_PWR_LEVELS_Pos  0UL
#define PACSS_ACHAN_BUF_CTL_BUF_PWR_LEVELS_Msk  0x3UL
#define PACSS_ACHAN_BUF_CTL_BUF_CHOP_EN_Pos     4UL
#define PACSS_ACHAN_BUF_CTL_BUF_CHOP_EN_Msk     0x10UL
#define PACSS_ACHAN_BUF_CTL_BUF_IDAC_EN_Pos     5UL
#define PACSS_ACHAN_BUF_CTL_BUF_IDAC_EN_Msk     0x20UL
/* PACSS_ACHAN.PUMP_CTL */
#define PACSS_ACHAN_PUMP_CTL_VNEG_PWR_MODE_Pos  0UL
#define PACSS_ACHAN_PUMP_CTL_VNEG_PWR_MODE_Msk  0x3UL
#define PACSS_ACHAN_PUMP_CTL_CLOCK_SEL_Pos      4UL
#define PACSS_ACHAN_PUMP_CTL_CLOCK_SEL_Msk      0x30UL
/* PACSS_ACHAN.REF_CTL */
#define PACSS_ACHAN_REF_CTL_VREF_PWR_Pos        0UL
#define PACSS_ACHAN_REF_CTL_VREF_PWR_Msk        0x3UL
#define PACSS_ACHAN_REF_CTL_VCM_PWR_Pos         2UL
#define PACSS_ACHAN_REF_CTL_VCM_PWR_Msk         0xCUL
#define PACSS_ACHAN_REF_CTL_VCM_SEL_Pos         4UL
#define PACSS_ACHAN_REF_CTL_VCM_SEL_Msk         0x30UL
#define PACSS_ACHAN_REF_CTL_VREF_QTZ_SEL_Pos    6UL
#define PACSS_ACHAN_REF_CTL_VREF_QTZ_SEL_Msk    0x40UL
/* PACSS_ACHAN.START */
#define PACSS_ACHAN_START_START_PRIM_Pos        0UL
#define PACSS_ACHAN_START_START_PRIM_Msk        0x1UL
#define PACSS_ACHAN_START_PEND_SEC_Pos          8UL
#define PACSS_ACHAN_START_PEND_SEC_Msk          0x100UL
/* PACSS_ACHAN.INMUX_CTL */
#define PACSS_ACHAN_INMUX_CTL_POS_PIN_SEL_Pos   0UL
#define PACSS_ACHAN_INMUX_CTL_POS_PIN_SEL_Msk   0x7FUL
#define PACSS_ACHAN_INMUX_CTL_NEG_PIN_SEL_Pos   8UL
#define PACSS_ACHAN_INMUX_CTL_NEG_PIN_SEL_Msk   0x1F00UL
#define PACSS_ACHAN_INMUX_CTL_DECODE_EN_Pos     16UL
#define PACSS_ACHAN_INMUX_CTL_DECODE_EN_Msk     0x10000UL
/* PACSS_ACHAN.DEM_CTL */
#define PACSS_ACHAN_DEM_CTL_SCRAM0_EN_Pos       0UL
#define PACSS_ACHAN_DEM_CTL_SCRAM0_EN_Msk       0x1UL
#define PACSS_ACHAN_DEM_CTL_SCRAM1_EN_Pos       1UL
#define PACSS_ACHAN_DEM_CTL_SCRAM1_EN_Msk       0x2UL
#define PACSS_ACHAN_DEM_CTL_DEM_EN_Pos          2UL
#define PACSS_ACHAN_DEM_CTL_DEM_EN_Msk          0x4UL
/* PACSS_ACHAN.SWITCH */
#define PACSS_ACHAN_SWITCH_INMUX_ABUSA_VPLUS_Pos 0UL
#define PACSS_ACHAN_SWITCH_INMUX_ABUSA_VPLUS_Msk 0x1UL
#define PACSS_ACHAN_SWITCH_INMUX_ABUSB_VPLUS_Pos 1UL
#define PACSS_ACHAN_SWITCH_INMUX_ABUSB_VPLUS_Msk 0x2UL
#define PACSS_ACHAN_SWITCH_INMUX_ABUSA_VMINUS_Pos 2UL
#define PACSS_ACHAN_SWITCH_INMUX_ABUSA_VMINUS_Msk 0x4UL
#define PACSS_ACHAN_SWITCH_INMUX_ABUSB_VMINUS_Pos 3UL
#define PACSS_ACHAN_SWITCH_INMUX_ABUSB_VMINUS_Msk 0x8UL
#define PACSS_ACHAN_SWITCH_AAF_SW1_Pos          4UL
#define PACSS_ACHAN_SWITCH_AAF_SW1_Msk          0x10UL
#define PACSS_ACHAN_SWITCH_AAF_SW2_Pos          5UL
#define PACSS_ACHAN_SWITCH_AAF_SW2_Msk          0x20UL
#define PACSS_ACHAN_SWITCH_AAF_SW3_Pos          6UL
#define PACSS_ACHAN_SWITCH_AAF_SW3_Msk          0x40UL
#define PACSS_ACHAN_SWITCH_AAF_SW4_Pos          7UL
#define PACSS_ACHAN_SWITCH_AAF_SW4_Msk          0x80UL
/* PACSS_ACHAN.SWITCH_CLEAR */
#define PACSS_ACHAN_SWITCH_CLEAR_INMUX_ABUSA_VPLUS_Pos 0UL
#define PACSS_ACHAN_SWITCH_CLEAR_INMUX_ABUSA_VPLUS_Msk 0x1UL
#define PACSS_ACHAN_SWITCH_CLEAR_INMUX_ABUSB_VPLUS_Pos 1UL
#define PACSS_ACHAN_SWITCH_CLEAR_INMUX_ABUSB_VPLUS_Msk 0x2UL
#define PACSS_ACHAN_SWITCH_CLEAR_INMUX_ABUSA_VMINUS_Pos 2UL
#define PACSS_ACHAN_SWITCH_CLEAR_INMUX_ABUSA_VMINUS_Msk 0x4UL
#define PACSS_ACHAN_SWITCH_CLEAR_INMUX_ABUSB_VMINUS_Pos 3UL
#define PACSS_ACHAN_SWITCH_CLEAR_INMUX_ABUSB_VMINUS_Msk 0x8UL
#define PACSS_ACHAN_SWITCH_CLEAR_AAF_SW1_Pos    4UL
#define PACSS_ACHAN_SWITCH_CLEAR_AAF_SW1_Msk    0x10UL
#define PACSS_ACHAN_SWITCH_CLEAR_AAF_SW2_Pos    5UL
#define PACSS_ACHAN_SWITCH_CLEAR_AAF_SW2_Msk    0x20UL
#define PACSS_ACHAN_SWITCH_CLEAR_AAF_SW3_Pos    6UL
#define PACSS_ACHAN_SWITCH_CLEAR_AAF_SW3_Msk    0x40UL
#define PACSS_ACHAN_SWITCH_CLEAR_AAF_SW4_Pos    7UL
#define PACSS_ACHAN_SWITCH_CLEAR_AAF_SW4_Msk    0x80UL
/* PACSS_ACHAN.SWITCH_SQ_CTL */
#define PACSS_ACHAN_SWITCH_SQ_CTL_INMUX_Pos     0UL
#define PACSS_ACHAN_SWITCH_SQ_CTL_INMUX_Msk     0x1UL
#define PACSS_ACHAN_SWITCH_SQ_CTL_AAF_Pos       4UL
#define PACSS_ACHAN_SWITCH_SQ_CTL_AAF_Msk       0x10UL
/* PACSS_ACHAN.SWITCH_STATUS */
#define PACSS_ACHAN_SWITCH_STATUS_INMUX_ABUSA_VPLUS_Pos 0UL
#define PACSS_ACHAN_SWITCH_STATUS_INMUX_ABUSA_VPLUS_Msk 0x1UL
#define PACSS_ACHAN_SWITCH_STATUS_INMUX_ABUSB_VPLUS_Pos 1UL
#define PACSS_ACHAN_SWITCH_STATUS_INMUX_ABUSB_VPLUS_Msk 0x2UL
#define PACSS_ACHAN_SWITCH_STATUS_INMUX_ABUSA_VMINUS_Pos 2UL
#define PACSS_ACHAN_SWITCH_STATUS_INMUX_ABUSA_VMINUS_Msk 0x4UL
#define PACSS_ACHAN_SWITCH_STATUS_INMUX_ABUSB_VMINUS_Pos 3UL
#define PACSS_ACHAN_SWITCH_STATUS_INMUX_ABUSB_VMINUS_Msk 0x8UL
#define PACSS_ACHAN_SWITCH_STATUS_AAF_SW1_Pos   4UL
#define PACSS_ACHAN_SWITCH_STATUS_AAF_SW1_Msk   0x10UL
#define PACSS_ACHAN_SWITCH_STATUS_AAF_SW2_Pos   5UL
#define PACSS_ACHAN_SWITCH_STATUS_AAF_SW2_Msk   0x20UL
#define PACSS_ACHAN_SWITCH_STATUS_AAF_SW3_Pos   6UL
#define PACSS_ACHAN_SWITCH_STATUS_AAF_SW3_Msk   0x40UL
#define PACSS_ACHAN_SWITCH_STATUS_AAF_SW4_Pos   7UL
#define PACSS_ACHAN_SWITCH_STATUS_AAF_SW4_Msk   0x80UL
/* PACSS_ACHAN.DFT_CTL */
#define PACSS_ACHAN_DFT_CTL_MUXA_SEL_Pos        0UL
#define PACSS_ACHAN_DFT_CTL_MUXA_SEL_Msk        0x7UL
#define PACSS_ACHAN_DFT_CTL_MUXB_SEL_Pos        4UL
#define PACSS_ACHAN_DFT_CTL_MUXB_SEL_Msk        0x70UL
#define PACSS_ACHAN_DFT_CTL_MUX_EN_Pos          7UL
#define PACSS_ACHAN_DFT_CTL_MUX_EN_Msk          0x80UL
#define PACSS_ACHAN_DFT_CTL_PGA_TEST_EN_Pos     12UL
#define PACSS_ACHAN_DFT_CTL_PGA_TEST_EN_Msk     0x1000UL
#define PACSS_ACHAN_DFT_CTL_VNEG_PMP_TEST_EN_Pos 13UL
#define PACSS_ACHAN_DFT_CTL_VNEG_PMP_TEST_EN_Msk 0x2000UL
#define PACSS_ACHAN_DFT_CTL_FRC_ANA_EN_LOW_Pos  16UL
#define PACSS_ACHAN_DFT_CTL_FRC_ANA_EN_LOW_Msk  0x10000UL
#define PACSS_ACHAN_DFT_CTL_RS0_PULLDOWN_Pos    17UL
#define PACSS_ACHAN_DFT_CTL_RS0_PULLDOWN_Msk    0x20000UL
#define PACSS_ACHAN_DFT_CTL_RS1_PULLDOWN_Pos    18UL
#define PACSS_ACHAN_DFT_CTL_RS1_PULLDOWN_Msk    0x40000UL
#define PACSS_ACHAN_DFT_CTL_CHOP_PHASE_CTL_Pos  19UL
#define PACSS_ACHAN_DFT_CTL_CHOP_PHASE_CTL_Msk  0x80000UL
#define PACSS_ACHAN_DFT_CTL_SPARE_CTL_Pos       20UL
#define PACSS_ACHAN_DFT_CTL_SPARE_CTL_Msk       0x1F00000UL
/* PACSS_ACHAN.DFT_STATUS */
#define PACSS_ACHAN_DFT_STATUS_OBSVR_LS_OUT_Pos 0UL
#define PACSS_ACHAN_DFT_STATUS_OBSVR_LS_OUT_Msk 0x1UL
/* PACSS_ACHAN.TRIM_PGA0_CTL */
#define PACSS_ACHAN_TRIM_PGA0_CTL_OFST_P_Pos    0UL
#define PACSS_ACHAN_TRIM_PGA0_CTL_OFST_P_Msk    0x3FUL
/* PACSS_ACHAN.TRIM_PGA1_CTL */
#define PACSS_ACHAN_TRIM_PGA1_CTL_OFST_SLOPE_P_Pos 0UL
#define PACSS_ACHAN_TRIM_PGA1_CTL_OFST_SLOPE_P_Msk 0x3FUL
/* PACSS_ACHAN.TRIM_PGA2_CTL */
#define PACSS_ACHAN_TRIM_PGA2_CTL_OFST_M_Pos    0UL
#define PACSS_ACHAN_TRIM_PGA2_CTL_OFST_M_Msk    0x3FUL
/* PACSS_ACHAN.TRIM_PGA3_CTL */
#define PACSS_ACHAN_TRIM_PGA3_CTL_OFST_SLOPE_M_Pos 0UL
#define PACSS_ACHAN_TRIM_PGA3_CTL_OFST_SLOPE_M_Msk 0x3FUL
/* PACSS_ACHAN.TRIM_PGA4_CTL */
#define PACSS_ACHAN_TRIM_PGA4_CTL_CM_Pos        0UL
#define PACSS_ACHAN_TRIM_PGA4_CTL_CM_Msk        0x7UL
/* PACSS_ACHAN.TRIM_BUF0_CTL */
#define PACSS_ACHAN_TRIM_BUF0_CTL_OFST_P_Pos    0UL
#define PACSS_ACHAN_TRIM_BUF0_CTL_OFST_P_Msk    0x3FUL
/* PACSS_ACHAN.TRIM_BUF1_CTL */
#define PACSS_ACHAN_TRIM_BUF1_CTL_OFST_PTAT_P_Pos 0UL
#define PACSS_ACHAN_TRIM_BUF1_CTL_OFST_PTAT_P_Msk 0x3FUL
/* PACSS_ACHAN.TRIM_BUF2_CTL */
#define PACSS_ACHAN_TRIM_BUF2_CTL_OFST_M_Pos    0UL
#define PACSS_ACHAN_TRIM_BUF2_CTL_OFST_M_Msk    0x3FUL
/* PACSS_ACHAN.TRIM_BUF3_CTL */
#define PACSS_ACHAN_TRIM_BUF3_CTL_OFST_PTAT_M_Pos 0UL
#define PACSS_ACHAN_TRIM_BUF3_CTL_OFST_PTAT_M_Msk 0x3FUL


/* PACSS_MMIO_GAINLVL_STRUCT.GAIN_CFG0 */
#define PACSS_MMIO_GAINLVL_STRUCT_GAIN_CFG0_PGA_GAIN_Pos 0UL
#define PACSS_MMIO_GAINLVL_STRUCT_GAIN_CFG0_PGA_GAIN_Msk 0x7UL
#define PACSS_MMIO_GAINLVL_STRUCT_GAIN_CFG0_SHIFT1_Pos 4UL
#define PACSS_MMIO_GAINLVL_STRUCT_GAIN_CFG0_SHIFT1_Msk 0xF0UL
#define PACSS_MMIO_GAINLVL_STRUCT_GAIN_CFG0_DACCAP_Pos 16UL
#define PACSS_MMIO_GAINLVL_STRUCT_GAIN_CFG0_DACCAP_Msk 0x3F0000UL
#define PACSS_MMIO_GAINLVL_STRUCT_GAIN_CFG0_IPCAP1_Pos 24UL
#define PACSS_MMIO_GAINLVL_STRUCT_GAIN_CFG0_IPCAP1_Msk 0x3F000000UL
/* PACSS_MMIO_GAINLVL_STRUCT.GAIN_CFG1 */
#define PACSS_MMIO_GAINLVL_STRUCT_GAIN_CFG1_SUMCAPIN_Pos 0UL
#define PACSS_MMIO_GAINLVL_STRUCT_GAIN_CFG1_SUMCAPIN_Msk 0x1FUL
#define PACSS_MMIO_GAINLVL_STRUCT_GAIN_CFG1_SUMCAP1_Pos 8UL
#define PACSS_MMIO_GAINLVL_STRUCT_GAIN_CFG1_SUMCAP1_Msk 0x700UL
#define PACSS_MMIO_GAINLVL_STRUCT_GAIN_CFG1_SUMCAP2_Pos 12UL
#define PACSS_MMIO_GAINLVL_STRUCT_GAIN_CFG1_SUMCAP2_Msk 0x7000UL
#define PACSS_MMIO_GAINLVL_STRUCT_GAIN_CFG1_SUMCAP3_Pos 16UL
#define PACSS_MMIO_GAINLVL_STRUCT_GAIN_CFG1_SUMCAP3_Msk 0x70000UL
#define PACSS_MMIO_GAINLVL_STRUCT_GAIN_CFG1_SUMCAPFB_Pos 20UL
#define PACSS_MMIO_GAINLVL_STRUCT_GAIN_CFG1_SUMCAPFB_Msk 0xF00000UL
/* PACSS_MMIO_GAINLVL_STRUCT.OFST_COR */
#define PACSS_MMIO_GAINLVL_STRUCT_OFST_COR_OCOR_Pos 0UL
#define PACSS_MMIO_GAINLVL_STRUCT_OFST_COR_OCOR_Msk 0xFFFFUL
/* PACSS_MMIO_GAINLVL_STRUCT.GAIN_COR */
#define PACSS_MMIO_GAINLVL_STRUCT_GAIN_COR_GCOR_Pos 0UL
#define PACSS_MMIO_GAINLVL_STRUCT_GAIN_COR_GCOR_Msk 0xFFFFUL


/* PACSS_MMIO_OCD_STRUCT.OCD_CTL */
#define PACSS_MMIO_OCD_STRUCT_OCD_CTL_OCD_THRESH_Pos 0UL
#define PACSS_MMIO_OCD_STRUCT_OCD_CTL_OCD_THRESH_Msk 0x1FUL
#define PACSS_MMIO_OCD_STRUCT_OCD_CTL_ST_MODE_Pos 12UL
#define PACSS_MMIO_OCD_STRUCT_OCD_CTL_ST_MODE_Msk 0x3000UL
#define PACSS_MMIO_OCD_STRUCT_OCD_CTL_ST_POS_Pos 14UL
#define PACSS_MMIO_OCD_STRUCT_OCD_CTL_ST_POS_Msk 0x4000UL
#define PACSS_MMIO_OCD_STRUCT_OCD_CTL_ST_NEG_Pos 15UL
#define PACSS_MMIO_OCD_STRUCT_OCD_CTL_ST_NEG_Msk 0x8000UL
#define PACSS_MMIO_OCD_STRUCT_OCD_CTL_CLOCK_DIV_Pos 16UL
#define PACSS_MMIO_OCD_STRUCT_OCD_CTL_CLOCK_DIV_Msk 0xF0000UL
#define PACSS_MMIO_OCD_STRUCT_OCD_CTL_CLOCK_EDGE_Pos 20UL
#define PACSS_MMIO_OCD_STRUCT_OCD_CTL_CLOCK_EDGE_Msk 0x100000UL
#define PACSS_MMIO_OCD_STRUCT_OCD_CTL_GLITCH_FILTER_MODE_Pos 24UL
#define PACSS_MMIO_OCD_STRUCT_OCD_CTL_GLITCH_FILTER_MODE_Msk 0x1000000UL
#define PACSS_MMIO_OCD_STRUCT_OCD_CTL_IO_POLARITY_Pos 25UL
#define PACSS_MMIO_OCD_STRUCT_OCD_CTL_IO_POLARITY_Msk 0x2000000UL
#define PACSS_MMIO_OCD_STRUCT_OCD_CTL_OCD_MODE_Pos 28UL
#define PACSS_MMIO_OCD_STRUCT_OCD_CTL_OCD_MODE_Msk 0x30000000UL
#define PACSS_MMIO_OCD_STRUCT_OCD_CTL_NEG_EN_Pos 30UL
#define PACSS_MMIO_OCD_STRUCT_OCD_CTL_NEG_EN_Msk 0x40000000UL
#define PACSS_MMIO_OCD_STRUCT_OCD_CTL_POS_EN_Pos 31UL
#define PACSS_MMIO_OCD_STRUCT_OCD_CTL_POS_EN_Msk 0x80000000UL
/* PACSS_MMIO_OCD_STRUCT.OCD_FILT_LIMIT */
#define PACSS_MMIO_OCD_STRUCT_OCD_FILT_LIMIT_NEG_LIMIT_Pos 0UL
#define PACSS_MMIO_OCD_STRUCT_OCD_FILT_LIMIT_NEG_LIMIT_Msk 0xFFFFUL
#define PACSS_MMIO_OCD_STRUCT_OCD_FILT_LIMIT_POS_LIMIT_Pos 16UL
#define PACSS_MMIO_OCD_STRUCT_OCD_FILT_LIMIT_POS_LIMIT_Msk 0xFFFF0000UL
/* PACSS_MMIO_OCD_STRUCT.OCD_STATUS */
#define PACSS_MMIO_OCD_STRUCT_OCD_STATUS_OCD_Pos 0UL
#define PACSS_MMIO_OCD_STRUCT_OCD_STATUS_OCD_Msk 0x1UL
#define PACSS_MMIO_OCD_STRUCT_OCD_STATUS_OCD_NEG_COMP_Pos 4UL
#define PACSS_MMIO_OCD_STRUCT_OCD_STATUS_OCD_NEG_COMP_Msk 0x10UL
#define PACSS_MMIO_OCD_STRUCT_OCD_STATUS_OCD_POS_COMP_Pos 5UL
#define PACSS_MMIO_OCD_STRUCT_OCD_STATUS_OCD_POS_COMP_Msk 0x20UL
#define PACSS_MMIO_OCD_STRUCT_OCD_STATUS_OCD_NEG_HELD_Pos 8UL
#define PACSS_MMIO_OCD_STRUCT_OCD_STATUS_OCD_NEG_HELD_Msk 0x100UL
#define PACSS_MMIO_OCD_STRUCT_OCD_STATUS_OCD_POS_HELD_Pos 9UL
#define PACSS_MMIO_OCD_STRUCT_OCD_STATUS_OCD_POS_HELD_Msk 0x200UL
#define PACSS_MMIO_OCD_STRUCT_OCD_STATUS_GLITCH_FILTER_COUNT_Pos 16UL
#define PACSS_MMIO_OCD_STRUCT_OCD_STATUS_GLITCH_FILTER_COUNT_Msk 0xFFFF0000UL
/* PACSS_MMIO_OCD_STRUCT.OCD_DFT */
#define PACSS_MMIO_OCD_STRUCT_OCD_DFT_OCD_ADFT_SEL_Pos 0UL
#define PACSS_MMIO_OCD_STRUCT_OCD_DFT_OCD_ADFT_SEL_Msk 0x3UL
#define PACSS_MMIO_OCD_STRUCT_OCD_DFT_OCD_DDFT_SEL_Pos 4UL
#define PACSS_MMIO_OCD_STRUCT_OCD_DFT_OCD_DDFT_SEL_Msk 0xF0UL
#define PACSS_MMIO_OCD_STRUCT_OCD_DFT_OCD_SPARE_Pos 8UL
#define PACSS_MMIO_OCD_STRUCT_OCD_DFT_OCD_SPARE_Msk 0xF00UL
#define PACSS_MMIO_OCD_STRUCT_OCD_DFT_OCD_EN_LS_Pos 12UL
#define PACSS_MMIO_OCD_STRUCT_OCD_DFT_OCD_EN_LS_Msk 0x1000UL


/* PACSS_MMIO.PACSS_CTL */
#define PACSS_MMIO_PACSS_CTL_AGC_EN_Pos         0UL
#define PACSS_MMIO_PACSS_CTL_AGC_EN_Msk         0x1UL
#define PACSS_MMIO_PACSS_CTL_LDO_EN_Pos         1UL
#define PACSS_MMIO_PACSS_CTL_LDO_EN_Msk         0x2UL
#define PACSS_MMIO_PACSS_CTL_TMPS_EN_Pos        2UL
#define PACSS_MMIO_PACSS_CTL_TMPS_EN_Msk        0x4UL
#define PACSS_MMIO_PACSS_CTL_AREF_EN_Pos        3UL
#define PACSS_MMIO_PACSS_CTL_AREF_EN_Msk        0x8UL
#define PACSS_MMIO_PACSS_CTL_HPBGR_EN_Pos       4UL
#define PACSS_MMIO_PACSS_CTL_HPBGR_EN_Msk       0x10UL
#define PACSS_MMIO_PACSS_CTL_VPOS_PMP_EN_Pos    5UL
#define PACSS_MMIO_PACSS_CTL_VPOS_PMP_EN_Msk    0x20UL
#define PACSS_MMIO_PACSS_CTL_OCD0_EN_Pos        6UL
#define PACSS_MMIO_PACSS_CTL_OCD0_EN_Msk        0x40UL
#define PACSS_MMIO_PACSS_CTL_OCD1_EN_Pos        7UL
#define PACSS_MMIO_PACSS_CTL_OCD1_EN_Msk        0x80UL
#define PACSS_MMIO_PACSS_CTL_HVDIVG_MUX_SEL_Pos 8UL
#define PACSS_MMIO_PACSS_CTL_HVDIVG_MUX_SEL_Msk 0x300UL
#define PACSS_MMIO_PACSS_CTL_ENABLE_Pos         31UL
#define PACSS_MMIO_PACSS_CTL_ENABLE_Msk         0x80000000UL
/* PACSS_MMIO.AGC_CTL0 */
#define PACSS_MMIO_AGC_CTL0_LO_THRESH_Pos       0UL
#define PACSS_MMIO_AGC_CTL0_LO_THRESH_Msk       0xFFUL
#define PACSS_MMIO_AGC_CTL0_HI_THRESH_Pos       8UL
#define PACSS_MMIO_AGC_CTL0_HI_THRESH_Msk       0xFF00UL
#define PACSS_MMIO_AGC_CTL0_INIT_LVL_Pos        16UL
#define PACSS_MMIO_AGC_CTL0_INIT_LVL_Msk        0xF0000UL
#define PACSS_MMIO_AGC_CTL0_MIN_LVL_Pos         20UL
#define PACSS_MMIO_AGC_CTL0_MIN_LVL_Msk         0xF00000UL
#define PACSS_MMIO_AGC_CTL0_MAX_LVL_Pos         24UL
#define PACSS_MMIO_AGC_CTL0_MAX_LVL_Msk         0xF000000UL
#define PACSS_MMIO_AGC_CTL0_FAST_DEC_SCLR_Pos   28UL
#define PACSS_MMIO_AGC_CTL0_FAST_DEC_SCLR_Msk   0x30000000UL
/* PACSS_MMIO.AGC_CTL1 */
#define PACSS_MMIO_AGC_CTL1_FAST_DR_Pos         0UL
#define PACSS_MMIO_AGC_CTL1_FAST_DR_Msk         0x1FUL
#define PACSS_MMIO_AGC_CTL1_AAF_BLANK_MODE_Pos  7UL
#define PACSS_MMIO_AGC_CTL1_AAF_BLANK_MODE_Msk  0x80UL
#define PACSS_MMIO_AGC_CTL1_AAF_BLANK_CNT_Pos   8UL
#define PACSS_MMIO_AGC_CTL1_AAF_BLANK_CNT_Msk   0xFF00UL
#define PACSS_MMIO_AGC_CTL1_DEC_BLANK_CNT_Pos   16UL
#define PACSS_MMIO_AGC_CTL1_DEC_BLANK_CNT_Msk   0xFF0000UL
#define PACSS_MMIO_AGC_CTL1_SCALER_BLANK_CNT_Pos 24UL
#define PACSS_MMIO_AGC_CTL1_SCALER_BLANK_CNT_Msk 0xFF000000UL
/* PACSS_MMIO.AGC_CTL2 */
#define PACSS_MMIO_AGC_CTL2_LO_THRESH_FLT_MODE_Pos 0UL
#define PACSS_MMIO_AGC_CTL2_LO_THRESH_FLT_MODE_Msk 0x1UL
#define PACSS_MMIO_AGC_CTL2_LO_THRESH_CNT_Pos   16UL
#define PACSS_MMIO_AGC_CTL2_LO_THRESH_CNT_Msk   0xFFFF0000UL
/* PACSS_MMIO.AGC_CTL3 */
#define PACSS_MMIO_AGC_CTL3_HI_THRESH_FLT_MODE_Pos 0UL
#define PACSS_MMIO_AGC_CTL3_HI_THRESH_FLT_MODE_Msk 0x1UL
#define PACSS_MMIO_AGC_CTL3_HI_THRESH_CNT_Pos   16UL
#define PACSS_MMIO_AGC_CTL3_HI_THRESH_CNT_Msk   0xFFFF0000UL
/* PACSS_MMIO.TMPS_CTL */
#define PACSS_MMIO_TMPS_CTL_IREF_UNIT_Pos       0UL
#define PACSS_MMIO_TMPS_CTL_IREF_UNIT_Msk       0x1FFUL
#define PACSS_MMIO_TMPS_CTL_IREF_SEL_Pos        11UL
#define PACSS_MMIO_TMPS_CTL_IREF_SEL_Msk        0x800UL
#define PACSS_MMIO_TMPS_CTL_BIPOLAR_UNIT_Pos    12UL
#define PACSS_MMIO_TMPS_CTL_BIPOLAR_UNIT_Msk    0x1FF000UL
#define PACSS_MMIO_TMPS_CTL_LOAD_MODE_Pos       24UL
#define PACSS_MMIO_TMPS_CTL_LOAD_MODE_Msk       0x3000000UL
#define PACSS_MMIO_TMPS_CTL_AMUXA_SEL_Pos       27UL
#define PACSS_MMIO_TMPS_CTL_AMUXA_SEL_Msk       0x8000000UL
#define PACSS_MMIO_TMPS_CTL_AMUXB_SEL_Pos       28UL
#define PACSS_MMIO_TMPS_CTL_AMUXB_SEL_Msk       0x10000000UL
#define PACSS_MMIO_TMPS_CTL_VTEMP_SUP_SEL_Pos   29UL
#define PACSS_MMIO_TMPS_CTL_VTEMP_SUP_SEL_Msk   0x20000000UL
#define PACSS_MMIO_TMPS_CTL_VTEMP_SEL_Pos       30UL
#define PACSS_MMIO_TMPS_CTL_VTEMP_SEL_Msk       0x40000000UL
#define PACSS_MMIO_TMPS_CTL_VTEMP_RET_SEL_Pos   31UL
#define PACSS_MMIO_TMPS_CTL_VTEMP_RET_SEL_Msk   0x80000000UL
/* PACSS_MMIO.VPOS_PUMP_CTL */
#define PACSS_MMIO_VPOS_PUMP_CTL_VPOS_PWR_MODE_Pos 0UL
#define PACSS_MMIO_VPOS_PUMP_CTL_VPOS_PWR_MODE_Msk 0x7UL
#define PACSS_MMIO_VPOS_PUMP_CTL_VPOS_BYPASS_EN_Pos 3UL
#define PACSS_MMIO_VPOS_PUMP_CTL_VPOS_BYPASS_EN_Msk 0x8UL
#define PACSS_MMIO_VPOS_PUMP_CTL_CLOCK_SEL_Pos  4UL
#define PACSS_MMIO_VPOS_PUMP_CTL_CLOCK_SEL_Msk  0x30UL
/* PACSS_MMIO.START */
#define PACSS_MMIO_START_START_PRIM_Pos         0UL
#define PACSS_MMIO_START_START_PRIM_Msk         0x1UL
#define PACSS_MMIO_START_PEND_SEC_Pos           8UL
#define PACSS_MMIO_START_PEND_SEC_Msk           0x100UL
/* PACSS_MMIO.INTR */
#define PACSS_MMIO_INTR_AGC_GLVL_CHG_Pos        0UL
#define PACSS_MMIO_INTR_AGC_GLVL_CHG_Msk        0x1UL
#define PACSS_MMIO_INTR_OCD0_TRIGGER_Pos        8UL
#define PACSS_MMIO_INTR_OCD0_TRIGGER_Msk        0x100UL
#define PACSS_MMIO_INTR_OCD0_UNFILTERED_Pos     9UL
#define PACSS_MMIO_INTR_OCD0_UNFILTERED_Msk     0x200UL
#define PACSS_MMIO_INTR_OCD0_FAULT_Pos          10UL
#define PACSS_MMIO_INTR_OCD0_FAULT_Msk          0x400UL
#define PACSS_MMIO_INTR_OCD1_TRIGGER_Pos        12UL
#define PACSS_MMIO_INTR_OCD1_TRIGGER_Msk        0x1000UL
#define PACSS_MMIO_INTR_OCD1_UNFILTERED_Pos     13UL
#define PACSS_MMIO_INTR_OCD1_UNFILTERED_Msk     0x2000UL
#define PACSS_MMIO_INTR_OCD1_FAULT_Pos          14UL
#define PACSS_MMIO_INTR_OCD1_FAULT_Msk          0x4000UL
/* PACSS_MMIO.INTR_SET */
#define PACSS_MMIO_INTR_SET_AGC_GLVL_CHG_SET_Pos 0UL
#define PACSS_MMIO_INTR_SET_AGC_GLVL_CHG_SET_Msk 0x1UL
#define PACSS_MMIO_INTR_SET_OCD0_TRIGGER_SET_Pos 8UL
#define PACSS_MMIO_INTR_SET_OCD0_TRIGGER_SET_Msk 0x100UL
#define PACSS_MMIO_INTR_SET_OCD0_UNFILTERED_SET_Pos 9UL
#define PACSS_MMIO_INTR_SET_OCD0_UNFILTERED_SET_Msk 0x200UL
#define PACSS_MMIO_INTR_SET_OCD0_FAULT_SET_Pos  10UL
#define PACSS_MMIO_INTR_SET_OCD0_FAULT_SET_Msk  0x400UL
#define PACSS_MMIO_INTR_SET_OCD1_TRIGGER_SET_Pos 12UL
#define PACSS_MMIO_INTR_SET_OCD1_TRIGGER_SET_Msk 0x1000UL
#define PACSS_MMIO_INTR_SET_OCD1_UNFILTERED_SET_Pos 13UL
#define PACSS_MMIO_INTR_SET_OCD1_UNFILTERED_SET_Msk 0x2000UL
#define PACSS_MMIO_INTR_SET_OCD1_FAULT_SET_Pos  14UL
#define PACSS_MMIO_INTR_SET_OCD1_FAULT_SET_Msk  0x4000UL
/* PACSS_MMIO.INTR_MASK */
#define PACSS_MMIO_INTR_MASK_AGC_GLVL_CHG_MASK_Pos 0UL
#define PACSS_MMIO_INTR_MASK_AGC_GLVL_CHG_MASK_Msk 0x1UL
#define PACSS_MMIO_INTR_MASK_OCD0_TRIGGER_MASK_Pos 8UL
#define PACSS_MMIO_INTR_MASK_OCD0_TRIGGER_MASK_Msk 0x100UL
#define PACSS_MMIO_INTR_MASK_OCD0_UNFILTERED_MASK_Pos 9UL
#define PACSS_MMIO_INTR_MASK_OCD0_UNFILTERED_MASK_Msk 0x200UL
#define PACSS_MMIO_INTR_MASK_OCD0_FAULT_MASK_Pos 10UL
#define PACSS_MMIO_INTR_MASK_OCD0_FAULT_MASK_Msk 0x400UL
#define PACSS_MMIO_INTR_MASK_OCD1_TRIGGER_MASK_Pos 12UL
#define PACSS_MMIO_INTR_MASK_OCD1_TRIGGER_MASK_Msk 0x1000UL
#define PACSS_MMIO_INTR_MASK_OCD1_UNFILTERED_MASK_Pos 13UL
#define PACSS_MMIO_INTR_MASK_OCD1_UNFILTERED_MASK_Msk 0x2000UL
#define PACSS_MMIO_INTR_MASK_OCD1_FAULT_MASK_Pos 14UL
#define PACSS_MMIO_INTR_MASK_OCD1_FAULT_MASK_Msk 0x4000UL
/* PACSS_MMIO.INTR_MASKED */
#define PACSS_MMIO_INTR_MASKED_AGC_GLVL_CHG_MASKED_Pos 0UL
#define PACSS_MMIO_INTR_MASKED_AGC_GLVL_CHG_MASKED_Msk 0x1UL
#define PACSS_MMIO_INTR_MASKED_OCD0_TRIGGER_MASKED_Pos 8UL
#define PACSS_MMIO_INTR_MASKED_OCD0_TRIGGER_MASKED_Msk 0x100UL
#define PACSS_MMIO_INTR_MASKED_OCD0_UNFILTERED_MASKED_Pos 9UL
#define PACSS_MMIO_INTR_MASKED_OCD0_UNFILTERED_MASKED_Msk 0x200UL
#define PACSS_MMIO_INTR_MASKED_OCD0_FAULT_MASKED_Pos 10UL
#define PACSS_MMIO_INTR_MASKED_OCD0_FAULT_MASKED_Msk 0x400UL
#define PACSS_MMIO_INTR_MASKED_OCD1_TRIGGER_MASKED_Pos 12UL
#define PACSS_MMIO_INTR_MASKED_OCD1_TRIGGER_MASKED_Msk 0x1000UL
#define PACSS_MMIO_INTR_MASKED_OCD1_UNFILTERED_MASKED_Pos 13UL
#define PACSS_MMIO_INTR_MASKED_OCD1_UNFILTERED_MASKED_Msk 0x2000UL
#define PACSS_MMIO_INTR_MASKED_OCD1_FAULT_MASKED_Pos 14UL
#define PACSS_MMIO_INTR_MASKED_OCD1_FAULT_MASKED_Msk 0x4000UL
/* PACSS_MMIO.INTR_CAUSE */
#define PACSS_MMIO_INTR_CAUSE_DCH0_INT_Pos      0UL
#define PACSS_MMIO_INTR_CAUSE_DCH0_INT_Msk      0x1UL
#define PACSS_MMIO_INTR_CAUSE_DCH1_INT_Pos      1UL
#define PACSS_MMIO_INTR_CAUSE_DCH1_INT_Msk      0x2UL
#define PACSS_MMIO_INTR_CAUSE_DCH2_INT_Pos      2UL
#define PACSS_MMIO_INTR_CAUSE_DCH2_INT_Msk      0x4UL
#define PACSS_MMIO_INTR_CAUSE_DCH3_INT_Pos      3UL
#define PACSS_MMIO_INTR_CAUSE_DCH3_INT_Msk      0x8UL
#define PACSS_MMIO_INTR_CAUSE_PACSS_INT_Pos     4UL
#define PACSS_MMIO_INTR_CAUSE_PACSS_INT_Msk     0x10UL
/* PACSS_MMIO.STATUS0 */
#define PACSS_MMIO_STATUS0_SEQ_BUSY_Pos         0UL
#define PACSS_MMIO_STATUS0_SEQ_BUSY_Msk         0x3UL
#define PACSS_MMIO_STATUS0_AGC_CURR_GLVL_Pos    4UL
#define PACSS_MMIO_STATUS0_AGC_CURR_GLVL_Msk    0xF0UL
#define PACSS_MMIO_STATUS0_AGC_FAST_DEC_RESULT_Pos 8UL
#define PACSS_MMIO_STATUS0_AGC_FAST_DEC_RESULT_Msk 0xFFF00UL
/* PACSS_MMIO.STATUS1 */
#define PACSS_MMIO_STATUS1_LO_THRESH_CNTR_Pos   0UL
#define PACSS_MMIO_STATUS1_LO_THRESH_CNTR_Msk   0xFFFFUL
#define PACSS_MMIO_STATUS1_HI_THRESH_CNTR_Pos   16UL
#define PACSS_MMIO_STATUS1_HI_THRESH_CNTR_Msk   0xFFFF0000UL
/* PACSS_MMIO.HPBGR_CTL */
#define PACSS_MMIO_HPBGR_CTL_CHOP_EN_Pos        0UL
#define PACSS_MMIO_HPBGR_CTL_CHOP_EN_Msk        0x1UL
#define PACSS_MMIO_HPBGR_CTL_CHOP_CLK_SEL_Pos   1UL
#define PACSS_MMIO_HPBGR_CTL_CHOP_CLK_SEL_Msk   0x2UL
#define PACSS_MMIO_HPBGR_CTL_CHOP_POS_Pos       2UL
#define PACSS_MMIO_HPBGR_CTL_CHOP_POS_Msk       0x4UL
#define PACSS_MMIO_HPBGR_CTL_SEL_PHC_Pos        4UL
#define PACSS_MMIO_HPBGR_CTL_SEL_PHC_Msk        0x10UL
#define PACSS_MMIO_HPBGR_CTL_HPBGR_FCHOP_Pos    8UL
#define PACSS_MMIO_HPBGR_CTL_HPBGR_FCHOP_Msk    0x700UL
/* PACSS_MMIO.HPBGR_DFT_CTL */
#define PACSS_MMIO_HPBGR_DFT_CTL_ADFT_MODE_Pos  0UL
#define PACSS_MMIO_HPBGR_DFT_CTL_ADFT_MODE_Msk  0x7UL
/* PACSS_MMIO.AREF_CTL */
#define PACSS_MMIO_AREF_CTL_LP_MODE_Pos         0UL
#define PACSS_MMIO_AREF_CTL_LP_MODE_Msk         0x1UL
/* PACSS_MMIO.AREF_DFT_CTL */
#define PACSS_MMIO_AREF_DFT_CTL_DFT_SOURCE_Pos  0UL
#define PACSS_MMIO_AREF_DFT_CTL_DFT_SOURCE_Msk  0x7UL
#define PACSS_MMIO_AREF_DFT_CTL_DFT_SUM_Pos     4UL
#define PACSS_MMIO_AREF_DFT_CTL_DFT_SUM_Msk     0x10UL
#define PACSS_MMIO_AREF_DFT_CTL_DFT_CURR_SEL_Pos 8UL
#define PACSS_MMIO_AREF_DFT_CTL_DFT_CURR_SEL_Msk 0xF00UL
#define PACSS_MMIO_AREF_DFT_CTL_DFT_RSEL_Pos    12UL
#define PACSS_MMIO_AREF_DFT_CTL_DFT_RSEL_Msk    0x3000UL
#define PACSS_MMIO_AREF_DFT_CTL_DFT_OUT_SEL_Pos 16UL
#define PACSS_MMIO_AREF_DFT_CTL_DFT_OUT_SEL_Msk 0x10000UL
#define PACSS_MMIO_AREF_DFT_CTL_AREF_SPARE_Pos  20UL
#define PACSS_MMIO_AREF_DFT_CTL_AREF_SPARE_Msk  0x700000UL
/* PACSS_MMIO.REG_PROT */
#define PACSS_MMIO_REG_PROT_MAGIC_Pos           0UL
#define PACSS_MMIO_REG_PROT_MAGIC_Msk           0xFFFFFFFFUL
/* PACSS_MMIO.PDFT_CTL */
#define PACSS_MMIO_PDFT_CTL_DDFT0_MUX_SEL_Pos   0UL
#define PACSS_MMIO_PDFT_CTL_DDFT0_MUX_SEL_Msk   0xFUL
#define PACSS_MMIO_PDFT_CTL_DDFT1_MUX_SEL_Pos   4UL
#define PACSS_MMIO_PDFT_CTL_DDFT1_MUX_SEL_Msk   0xF0UL
#define PACSS_MMIO_PDFT_CTL_LDO_BYPASS_Pos      16UL
#define PACSS_MMIO_PDFT_CTL_LDO_BYPASS_Msk      0x10000UL
#define PACSS_MMIO_PDFT_CTL_VPOS_PMP_TEST_EN_Pos 17UL
#define PACSS_MMIO_PDFT_CTL_VPOS_PMP_TEST_EN_Msk 0x20000UL
/* PACSS_MMIO.TRIM_REGL0_CTL */
#define PACSS_MMIO_TRIM_REGL0_CTL_FINE_Pos      0UL
#define PACSS_MMIO_TRIM_REGL0_CTL_FINE_Msk      0x7UL
#define PACSS_MMIO_TRIM_REGL0_CTL_COARSE_Pos    4UL
#define PACSS_MMIO_TRIM_REGL0_CTL_COARSE_Msk    0x10UL
/* PACSS_MMIO.TRIM_HPBGR0_CTL */
#define PACSS_MMIO_TRIM_HPBGR0_CTL_VREF_OS_Pos  0UL
#define PACSS_MMIO_TRIM_HPBGR0_CTL_VREF_OS_Msk  0xFFUL
/* PACSS_MMIO.TRIM_HPBGR1_CTL */
#define PACSS_MMIO_TRIM_HPBGR1_CTL_VREF_TC_Pos  0UL
#define PACSS_MMIO_TRIM_HPBGR1_CTL_VREF_TC_Msk  0x7FUL
/* PACSS_MMIO.TRIM_HPBGR2_CTL */
#define PACSS_MMIO_TRIM_HPBGR2_CTL_VREF_NL1_Pos 0UL
#define PACSS_MMIO_TRIM_HPBGR2_CTL_VREF_NL1_Msk 0xFUL
#define PACSS_MMIO_TRIM_HPBGR2_CTL_VREF_NL2_Pos 4UL
#define PACSS_MMIO_TRIM_HPBGR2_CTL_VREF_NL2_Msk 0xF0UL
/* PACSS_MMIO.TRIM_HPBGR3_CTL */
#define PACSS_MMIO_TRIM_HPBGR3_CTL_VREF_AMP_Pos 0UL
#define PACSS_MMIO_TRIM_HPBGR3_CTL_VREF_AMP_Msk 0x1FUL
#define PACSS_MMIO_TRIM_HPBGR3_CTL_NL_COREC_DIS_Pos 7UL
#define PACSS_MMIO_TRIM_HPBGR3_CTL_NL_COREC_DIS_Msk 0x80UL
/* PACSS_MMIO.TRIM_HPBGR4_CTL */
#define PACSS_MMIO_TRIM_HPBGR4_CTL_NL1TEMP_Pos  0UL
#define PACSS_MMIO_TRIM_HPBGR4_CTL_NL1TEMP_Msk  0x3UL
#define PACSS_MMIO_TRIM_HPBGR4_CTL_NL1GAIN_Pos  2UL
#define PACSS_MMIO_TRIM_HPBGR4_CTL_NL1GAIN_Msk  0xCUL
#define PACSS_MMIO_TRIM_HPBGR4_CTL_NL2TEMP_Pos  4UL
#define PACSS_MMIO_TRIM_HPBGR4_CTL_NL2TEMP_Msk  0x30UL
#define PACSS_MMIO_TRIM_HPBGR4_CTL_NL2GAIN_Pos  6UL
#define PACSS_MMIO_TRIM_HPBGR4_CTL_NL2GAIN_Msk  0xC0UL
/* PACSS_MMIO.TRIM_AREF0_CTL */
#define PACSS_MMIO_TRIM_AREF0_CTL_ICTAT_Pos     0UL
#define PACSS_MMIO_TRIM_AREF0_CTL_ICTAT_Msk     0x1FUL
/* PACSS_MMIO.TRIM_AREF1_CTL */
#define PACSS_MMIO_TRIM_AREF1_CTL_IPTAT_COARSE_Pos 0UL
#define PACSS_MMIO_TRIM_AREF1_CTL_IPTAT_COARSE_Msk 0xFUL
/* PACSS_MMIO.TRIM_AREF2_CTL */
#define PACSS_MMIO_TRIM_AREF2_CTL_IPTAT_FINE_Pos 0UL
#define PACSS_MMIO_TRIM_AREF2_CTL_IPTAT_FINE_Msk 0x1FUL
/* PACSS_MMIO.TRIM_AREF3_CTL */
#define PACSS_MMIO_TRIM_AREF3_CTL_PTAT_DAC_Pos  0UL
#define PACSS_MMIO_TRIM_AREF3_CTL_PTAT_DAC_Msk  0x7UL
/* PACSS_MMIO.TRIM_AREF4_CTL */
#define PACSS_MMIO_TRIM_AREF4_CTL_ZTAT_COARSE_Pos 0UL
#define PACSS_MMIO_TRIM_AREF4_CTL_ZTAT_COARSE_Msk 0xFUL
/* PACSS_MMIO.TRIM_AREF5_CTL */
#define PACSS_MMIO_TRIM_AREF5_CTL_ZTAT_FINE_Pos 0UL
#define PACSS_MMIO_TRIM_AREF5_CTL_ZTAT_FINE_Msk 0x1FUL
/* PACSS_MMIO.TRIM_AREF6_CTL */
#define PACSS_MMIO_TRIM_AREF6_CTL_CTAT_COARSE_Pos 0UL
#define PACSS_MMIO_TRIM_AREF6_CTL_CTAT_COARSE_Msk 0xFUL
/* PACSS_MMIO.TRIM_OCD00_CTL */
#define PACSS_MMIO_TRIM_OCD00_CTL_TRIM0_Pos     0UL
#define PACSS_MMIO_TRIM_OCD00_CTL_TRIM0_Msk     0xFFUL
/* PACSS_MMIO.TRIM_OCD01_CTL */
#define PACSS_MMIO_TRIM_OCD01_CTL_TRIM1_Pos     0UL
#define PACSS_MMIO_TRIM_OCD01_CTL_TRIM1_Msk     0xFFUL
/* PACSS_MMIO.TRIM_OCD10_CTL */
#define PACSS_MMIO_TRIM_OCD10_CTL_TRIM0_Pos     0UL
#define PACSS_MMIO_TRIM_OCD10_CTL_TRIM0_Msk     0xFFUL
/* PACSS_MMIO.TRIM_OCD11_CTL */
#define PACSS_MMIO_TRIM_OCD11_CTL_TRIM1_Pos     0UL
#define PACSS_MMIO_TRIM_OCD11_CTL_TRIM1_Msk     0xFFUL


#endif /* _CYIP_PACSS_H_ */


/* [] END OF FILE */
