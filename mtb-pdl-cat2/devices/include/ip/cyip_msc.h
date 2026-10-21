/***************************************************************************//**
* \file cyip_msc.h
*
* \brief
* MSC IP definitions
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

#ifndef _CYIP_MSC_H_
#define _CYIP_MSC_H_

#include "cyip_headers.h"

/*******************************************************************************
*                                     MSC
*******************************************************************************/

#define MSC_MODE_SECTION_SIZE                   0x00000020UL
#define MSC_SECTION_SIZE                        0x00010000UL

/**
  * \brief Sense Mode Configuration Structure (MSC_MODE)
  */
typedef struct {
  __IOM uint32_t SENSE_DUTY_CTL;                /*!< 0x00000000 Sense Clock Duty Cycle Control */
  __IOM uint32_t SW_SEL_CDAC_FL;                /*!< 0x00000004 Flatspot/Dither CAPDAC Switch Control */
  __IOM uint32_t SW_SEL_TOP;                    /*!< 0x00000008 Top Level Switch Control */
  __IOM uint32_t SW_SEL_COMP;                   /*!< 0x0000000C MSC Comparator Switch Control */
  __IOM uint32_t SW_SEL_SH;                     /*!< 0x00000010 Shielding Switch Control */
   __IM uint32_t RESERVED[3];
} MSC_MODE_Type;                                /*!< Size = 32 (0x20) */

/**
  * \brief MultiSense Controller (MSC)
  */
typedef struct {
  __IOM uint32_t CTL;                           /*!< 0x00000000 Configuration and Control */
  __IOM uint32_t SPARE;                         /*!< 0x00000004 Spare MMIO */
  __IOM uint32_t SCAN_CTL1;                     /*!< 0x00000008 Scan Control 1 */
  __IOM uint32_t SCAN_CTL2;                     /*!< 0x0000000C Scan Control 2 */
  __IOM uint32_t INIT_CTL1;                     /*!< 0x00000010 Initialisation Control 1 */
  __IOM uint32_t INIT_CTL2;                     /*!< 0x00000014 Initialisation Control 2 */
  __IOM uint32_t INIT_CTL3;                     /*!< 0x00000018 Initialisation Control 3 */
  __IOM uint32_t INIT_CTL4;                     /*!< 0x0000001C Initialisation Control 4 */
  __IOM uint32_t SENSE_DUTY_CTL;                /*!< 0x00000020 Sense Clock Duty Cycle Control */
  __IOM uint32_t SENSE_PERIOD_CTL;              /*!< 0x00000024 Sense Clock Period Control */
  __IOM uint32_t FILTER_CTL;                    /*!< 0x00000028 Filter Control */
   __IM uint32_t RESERVED;
  __IOM uint32_t CCOMP_CDAC_CTL;                /*!< 0x00000030 Compensation CAPDAC Control */
  __IOM uint32_t DITHER_CDAC_CTL;               /*!< 0x00000034 Flatspot/Dither CAPDAC Switch Control */
   __IM uint32_t RESERVED1[2];
  __IOM uint32_t CSW_CTL;                       /*!< 0x00000040 Control Mux Switch Control */
  __IOM uint32_t SW_SEL_GPIO;                   /*!< 0x00000044 GPIO Switch Control */
  __IOM uint32_t SW_SEL_CDAC_RE;                /*!< 0x00000048 Reference CAPDAC Switch Control */
  __IOM uint32_t SW_SEL_CDAC_CO;                /*!< 0x0000004C Compensation CAPDAC Switch Control */
  __IOM uint32_t SW_SEL_CDAC_CF;                /*!< 0x00000050 Fine CAPDAC Switch Control */
  __IOM uint32_t SW_SEL_CMOD1;                  /*!< 0x00000054 CMOD Switch Control 1 */
  __IOM uint32_t SW_SEL_CMOD2;                  /*!< 0x00000058 CMOD Switch Control 2 */
  __IOM uint32_t SW_SEL_CMOD3;                  /*!< 0x0000005C CMOD Switch Control 3 */
  __IOM uint32_t SW_SEL_CMOD4;                  /*!< 0x00000060 CMOD Switch Control 4 */
   __IM uint32_t RESERVED2[3];
  __IOM uint32_t OBS_CTL;                       /*!< 0x00000070 Observability Control */
   __IM uint32_t RESERVED3[3];
  __IOM uint32_t WAKEUP_CTL;                    /*!< 0x00000080 Wakeup Control */
  __IOM uint32_t LP_AOC_CTL;                    /*!< 0x00000084 LP-AoC Control */
   __IM uint32_t RESERVED4[30];
   __IM uint32_t STATUS1;                       /*!< 0x00000100 General Status Register 1 */
   __IM uint32_t STATUS2;                       /*!< 0x00000104 General Status Register 2 */
   __IM uint32_t STATUS3;                       /*!< 0x00000108 General Status Register 3 */
   __IM uint32_t RESULT_FIFO_STATUS;            /*!< 0x0000010C Result FIFO Status */
   __IM uint32_t RESULT_FIFO_RD;                /*!< 0x00000110 Result FIFO Pointer */
   __IM uint32_t RESERVED5[23];
  __IOM uint32_t INTR;                          /*!< 0x00000170 MSCv3 Interrupt Cause Register */
  __IOM uint32_t INTR_SET;                      /*!< 0x00000174 MSCv3 Interrupt Set Register */
  __IOM uint32_t INTR_MASK;                     /*!< 0x00000178 MSCv3 Interrupt Mask Register */
   __IM uint32_t INTR_MASKED;                   /*!< 0x0000017C MSCv3 Interrupt Masked Register */
  __IOM uint32_t INTR_LP;                       /*!< 0x00000180 Low Power Interrupt Cause Register */
  __IOM uint32_t INTR_LP_SET;                   /*!< 0x00000184 Low Power Interrupt Set Register */
  __IOM uint32_t INTR_LP_MASK;                  /*!< 0x00000188 Low Power Interrupt Mask Register */
   __IM uint32_t INTR_LP_MASKED;                /*!< 0x0000018C Low Power Interrupt Masked Register */
  __IOM uint32_t FRAME_CMD;                     /*!< 0x00000190 Frame Command Register */
   __IM uint32_t RESERVED6;
  __IOM uint32_t WAKEUP_CMD;                    /*!< 0x00000198 Wakeup Command Register */
   __IM uint32_t RESERVED7[25];
  __IOM uint32_t SNS_STRUCT_CTL;                /*!< 0x00000200 Sensor Struct Control */
  __IOM uint32_t SNS_LP_AOC_SENSOR_CTL1;        /*!< 0x00000204 LP-AoC Sensor Control 1 */
  __IOM uint32_t SNS_LP_AOC_SENSOR_CTL2;        /*!< 0x00000208 LP-AoC Sensor Control 2 */
  __IOM uint32_t SNS_SW_SEL_CSW_MASK2;          /*!< 0x0000020C Control MUX Function Select Mask 2 */
  __IOM uint32_t SNS_SW_SEL_CSW_MASK1;          /*!< 0x00000210 Control MUX Function Select Mask 1 */
  __IOM uint32_t SNS_SW_SEL_CSW_MASK0;          /*!< 0x00000214 Control MUX Function Select Mask 0 */
  __IOM uint32_t SNS_SCAN_CTL;                  /*!< 0x00000218 Sensor Scan Control */
  __IOM uint32_t SNS_CDAC_CTL;                  /*!< 0x0000021C Sensor CAPDAC Control */
  __IOM uint32_t SNS_CTL;                       /*!< 0x00000220 Sense Control and Command Register */
   __IM uint32_t RESERVED8[55];
  __IOM uint32_t SW_SEL_CSW[32];                /*!< 0x00000300 Control Switch MUX Switch Control */
   __IM uint32_t RESERVED9[32];
  __IOM uint32_t SW_SEL_CSW_FUNC[8];            /*!< 0x00000400 Control Switch MUX Switch Control Global Functions */
   __IM uint32_t RESERVED10[56];
        MSC_MODE_Type MODE[4];                  /*!< 0x00000500 Sense Mode Configuration Structure */
   __IM uint32_t RESERVED11[672];
  __IOM uint32_t SENSOR_DATA[4096];             /*!< 0x00001000 Sensor Configuration Storage */
   __IM uint32_t RESERVED12[11200];
  __IOM uint32_t TRIM_CTL;                      /*!< 0x0000FF00 Trim Control */
} MSC_Type;                                     /*!< Size = 65284 (0xFF04) */


/* MSC_MODE.SENSE_DUTY_CTL */
#define MSC_MODE_SENSE_DUTY_CTL_PHASE_GAP_PH0_EN_Pos 0UL
#define MSC_MODE_SENSE_DUTY_CTL_PHASE_GAP_PH0_EN_Msk 0x1UL
#define MSC_MODE_SENSE_DUTY_CTL_PHASE_GAP_PH1_EN_Pos 1UL
#define MSC_MODE_SENSE_DUTY_CTL_PHASE_GAP_PH1_EN_Msk 0x2UL
#define MSC_MODE_SENSE_DUTY_CTL_PHASE_GAP_PH2_EN_Pos 2UL
#define MSC_MODE_SENSE_DUTY_CTL_PHASE_GAP_PH2_EN_Msk 0x4UL
#define MSC_MODE_SENSE_DUTY_CTL_PHASE_GAP_PH3_EN_Pos 3UL
#define MSC_MODE_SENSE_DUTY_CTL_PHASE_GAP_PH3_EN_Msk 0x8UL
#define MSC_MODE_SENSE_DUTY_CTL_PHASE_GAP_FS2_PH0_EN_Pos 4UL
#define MSC_MODE_SENSE_DUTY_CTL_PHASE_GAP_FS2_PH0_EN_Msk 0x10UL
#define MSC_MODE_SENSE_DUTY_CTL_PHASE_GAP_FS2_PH1_EN_Pos 5UL
#define MSC_MODE_SENSE_DUTY_CTL_PHASE_GAP_FS2_PH1_EN_Msk 0x20UL
#define MSC_MODE_SENSE_DUTY_CTL_PH_GAP_2CYCLE_EN_Pos 6UL
#define MSC_MODE_SENSE_DUTY_CTL_PH_GAP_2CYCLE_EN_Msk 0x40UL
#define MSC_MODE_SENSE_DUTY_CTL_PHASE_GAP_PH0X_EN_Pos 8UL
#define MSC_MODE_SENSE_DUTY_CTL_PHASE_GAP_PH0X_EN_Msk 0x100UL
#define MSC_MODE_SENSE_DUTY_CTL_PHASE_GAP_PH1X_EN_Pos 9UL
#define MSC_MODE_SENSE_DUTY_CTL_PHASE_GAP_PH1X_EN_Msk 0x200UL
#define MSC_MODE_SENSE_DUTY_CTL_PHX_GAP_2CYCLE_EN_Pos 10UL
#define MSC_MODE_SENSE_DUTY_CTL_PHX_GAP_2CYCLE_EN_Msk 0x400UL
#define MSC_MODE_SENSE_DUTY_CTL_PHASE_SHIFT_EN_Pos 24UL
#define MSC_MODE_SENSE_DUTY_CTL_PHASE_SHIFT_EN_Msk 0x1000000UL
#define MSC_MODE_SENSE_DUTY_CTL_PHASE_MODE_SEL_Pos 28UL
#define MSC_MODE_SENSE_DUTY_CTL_PHASE_MODE_SEL_Msk 0x10000000UL
/* MSC_MODE.SW_SEL_CDAC_FL */
#define MSC_MODE_SW_SEL_CDAC_FL_SW_FLTCA_Pos    0UL
#define MSC_MODE_SW_SEL_CDAC_FL_SW_FLTCA_Msk    0x7UL
#define MSC_MODE_SW_SEL_CDAC_FL_SW_FLCB_Pos     4UL
#define MSC_MODE_SW_SEL_CDAC_FL_SW_FLCB_Msk     0x70UL
#define MSC_MODE_SW_SEL_CDAC_FL_SW_FLTV_Pos     8UL
#define MSC_MODE_SW_SEL_CDAC_FL_SW_FLTV_Msk     0x300UL
#define MSC_MODE_SW_SEL_CDAC_FL_SW_FLTG_Pos     12UL
#define MSC_MODE_SW_SEL_CDAC_FL_SW_FLTG_Msk     0x7000UL
#define MSC_MODE_SW_SEL_CDAC_FL_SW_FLBV_Pos     16UL
#define MSC_MODE_SW_SEL_CDAC_FL_SW_FLBV_Msk     0x70000UL
#define MSC_MODE_SW_SEL_CDAC_FL_SW_FLBG_Pos     20UL
#define MSC_MODE_SW_SEL_CDAC_FL_SW_FLBG_Msk     0x700000UL
#define MSC_MODE_SW_SEL_CDAC_FL_ACTIVATION_MODE_Pos 31UL
#define MSC_MODE_SW_SEL_CDAC_FL_ACTIVATION_MODE_Msk 0x80000000UL
/* MSC_MODE.SW_SEL_TOP */
#define MSC_MODE_SW_SEL_TOP_CACB_Pos            0UL
#define MSC_MODE_SW_SEL_TOP_CACB_Msk            0x1UL
#define MSC_MODE_SW_SEL_TOP_CACC_Pos            2UL
#define MSC_MODE_SW_SEL_TOP_CACC_Msk            0x4UL
#define MSC_MODE_SW_SEL_TOP_CBCC_Pos            4UL
#define MSC_MODE_SW_SEL_TOP_CBCC_Msk            0x10UL
#define MSC_MODE_SW_SEL_TOP_MBCC_Pos            6UL
#define MSC_MODE_SW_SEL_TOP_MBCC_Msk            0x40UL
#define MSC_MODE_SW_SEL_TOP_AYA_CTL_Pos         8UL
#define MSC_MODE_SW_SEL_TOP_AYA_CTL_Msk         0x700UL
#define MSC_MODE_SW_SEL_TOP_AYA_EN_Pos          11UL
#define MSC_MODE_SW_SEL_TOP_AYA_EN_Msk          0x800UL
#define MSC_MODE_SW_SEL_TOP_AYB_CTL_Pos         12UL
#define MSC_MODE_SW_SEL_TOP_AYB_CTL_Msk         0x7000UL
#define MSC_MODE_SW_SEL_TOP_AYB_EN_Pos          15UL
#define MSC_MODE_SW_SEL_TOP_AYB_EN_Msk          0x8000UL
#define MSC_MODE_SW_SEL_TOP_BYB_Pos             16UL
#define MSC_MODE_SW_SEL_TOP_BYB_Msk             0x30000UL
#define MSC_MODE_SW_SEL_TOP_SOSH_Pos            18UL
#define MSC_MODE_SW_SEL_TOP_SOSH_Msk            0xC0000UL
#define MSC_MODE_SW_SEL_TOP_SHV_Pos             20UL
#define MSC_MODE_SW_SEL_TOP_SHV_Msk             0xF00000UL
#define MSC_MODE_SW_SEL_TOP_SHG_Pos             24UL
#define MSC_MODE_SW_SEL_TOP_SHG_Msk             0xF000000UL
#define MSC_MODE_SW_SEL_TOP_BGRF_Pos            29UL
#define MSC_MODE_SW_SEL_TOP_BGRF_Msk            0x20000000UL
#define MSC_MODE_SW_SEL_TOP_RMF_Pos             30UL
#define MSC_MODE_SW_SEL_TOP_RMF_Msk             0x40000000UL
#define MSC_MODE_SW_SEL_TOP_MBF_Pos             31UL
#define MSC_MODE_SW_SEL_TOP_MBF_Msk             0x80000000UL
/* MSC_MODE.SW_SEL_COMP */
#define MSC_MODE_SW_SEL_COMP_CPCS1_Pos          0UL
#define MSC_MODE_SW_SEL_COMP_CPCS1_Msk          0x1UL
#define MSC_MODE_SW_SEL_COMP_CPCS3_Pos          2UL
#define MSC_MODE_SW_SEL_COMP_CPCS3_Msk          0x4UL
#define MSC_MODE_SW_SEL_COMP_CPMA_Pos           4UL
#define MSC_MODE_SW_SEL_COMP_CPMA_Msk           0x10UL
#define MSC_MODE_SW_SEL_COMP_CPCA_Pos           6UL
#define MSC_MODE_SW_SEL_COMP_CPCA_Msk           0x40UL
#define MSC_MODE_SW_SEL_COMP_CPCB_Pos           8UL
#define MSC_MODE_SW_SEL_COMP_CPCB_Msk           0x100UL
#define MSC_MODE_SW_SEL_COMP_CMCB_Pos           10UL
#define MSC_MODE_SW_SEL_COMP_CMCB_Msk           0x400UL
#define MSC_MODE_SW_SEL_COMP_CPF_Pos            12UL
#define MSC_MODE_SW_SEL_COMP_CPF_Msk            0x1000UL
#define MSC_MODE_SW_SEL_COMP_CMCS2_Pos          14UL
#define MSC_MODE_SW_SEL_COMP_CMCS2_Msk          0x4000UL
#define MSC_MODE_SW_SEL_COMP_CMCS4_Pos          16UL
#define MSC_MODE_SW_SEL_COMP_CMCS4_Msk          0x10000UL
#define MSC_MODE_SW_SEL_COMP_CMV_Pos            18UL
#define MSC_MODE_SW_SEL_COMP_CMV_Msk            0x40000UL
#define MSC_MODE_SW_SEL_COMP_CMG_Pos            20UL
#define MSC_MODE_SW_SEL_COMP_CMG_Msk            0x100000UL
#define MSC_MODE_SW_SEL_COMP_CMF_Pos            22UL
#define MSC_MODE_SW_SEL_COMP_CMF_Msk            0x400000UL
#define MSC_MODE_SW_SEL_COMP_HALF_WAVE_EN_Pos   31UL
#define MSC_MODE_SW_SEL_COMP_HALF_WAVE_EN_Msk   0x80000000UL
/* MSC_MODE.SW_SEL_SH */
#define MSC_MODE_SW_SEL_SH_C1SHG_Pos            0UL
#define MSC_MODE_SW_SEL_SH_C1SHG_Msk            0x1UL
#define MSC_MODE_SW_SEL_SH_C1SH_Pos             2UL
#define MSC_MODE_SW_SEL_SH_C1SH_Msk             0x4UL
#define MSC_MODE_SW_SEL_SH_C3SHG_Pos            4UL
#define MSC_MODE_SW_SEL_SH_C3SHG_Msk            0x10UL
#define MSC_MODE_SW_SEL_SH_C3SH_Pos             6UL
#define MSC_MODE_SW_SEL_SH_C3SH_Msk             0x40UL
#define MSC_MODE_SW_SEL_SH_SOMB_Pos             8UL
#define MSC_MODE_SW_SEL_SH_SOMB_Msk             0x100UL
#define MSC_MODE_SW_SEL_SH_CBSO_Pos             10UL
#define MSC_MODE_SW_SEL_SH_CBSO_Msk             0x400UL
#define MSC_MODE_SW_SEL_SH_SPCS1_Pos            12UL
#define MSC_MODE_SW_SEL_SH_SPCS1_Msk            0x1000UL
#define MSC_MODE_SW_SEL_SH_SPCS3_Pos            14UL
#define MSC_MODE_SW_SEL_SH_SPCS3_Msk            0x4000UL
#define MSC_MODE_SW_SEL_SH_FSP_Pos              16UL
#define MSC_MODE_SW_SEL_SH_FSP_Msk              0x10000UL
#define MSC_MODE_SW_SEL_SH_CCSO_Pos             18UL
#define MSC_MODE_SW_SEL_SH_CCSO_Msk             0x40000UL
#define MSC_MODE_SW_SEL_SH_BUF_SEL_Pos          24UL
#define MSC_MODE_SW_SEL_SH_BUF_SEL_Msk          0xF000000UL
#define MSC_MODE_SW_SEL_SH_BUF_EN_Pos           31UL
#define MSC_MODE_SW_SEL_SH_BUF_EN_Msk           0x80000000UL


/* MSC.CTL */
#define MSC_CTL_SENSE_EN_Pos                    0UL
#define MSC_CTL_SENSE_EN_Msk                    0x1UL
#define MSC_CTL_MSCCMP_EN_Pos                   4UL
#define MSC_CTL_MSCCMP_EN_Msk                   0x10UL
#define MSC_CTL_CLK_SYNC_EN_Pos                 8UL
#define MSC_CTL_CLK_SYNC_EN_Msk                 0x100UL
#define MSC_CTL_EXT_FRAME_START_EN_Pos          12UL
#define MSC_CTL_EXT_FRAME_START_EN_Msk          0x1000UL
#define MSC_CTL_OPERATING_MODE_Pos              16UL
#define MSC_CTL_OPERATING_MODE_Msk              0x30000UL
#define MSC_CTL_BUF_MODE_Pos                    20UL
#define MSC_CTL_BUF_MODE_Msk                    0x100000UL
#define MSC_CTL_CLK_MSC_RATIO_Pos               24UL
#define MSC_CTL_CLK_MSC_RATIO_Msk               0x1000000UL
#define MSC_CTL_ENABLED_Pos                     31UL
#define MSC_CTL_ENABLED_Msk                     0x80000000UL
/* MSC.SPARE */
#define MSC_SPARE_SPARE_Pos                     0UL
#define MSC_SPARE_SPARE_Msk                     0x3FUL
/* MSC.SCAN_CTL1 */
#define MSC_SCAN_CTL1_NUM_AUTO_RESAMPLE_Pos     0UL
#define MSC_SCAN_CTL1_NUM_AUTO_RESAMPLE_Msk     0x7UL
#define MSC_SCAN_CTL1_RESCAN_DEBUG_MODE_Pos     3UL
#define MSC_SCAN_CTL1_RESCAN_DEBUG_MODE_Msk     0x8UL
#define MSC_SCAN_CTL1_NUM_SAMPLES_Pos           4UL
#define MSC_SCAN_CTL1_NUM_SAMPLES_Msk           0x30UL
#define MSC_SCAN_CTL1_RAW_COUNT_MODE_Pos        8UL
#define MSC_SCAN_CTL1_RAW_COUNT_MODE_Msk        0x100UL
#define MSC_SCAN_CTL1_DEBUG_CONV_PH_SEL_Pos     12UL
#define MSC_SCAN_CTL1_DEBUG_CONV_PH_SEL_Msk     0x7000UL
#define MSC_SCAN_CTL1_FRAME_START_PTR_Pos       16UL
#define MSC_SCAN_CTL1_FRAME_START_PTR_Msk       0xFF0000UL
/* MSC.SCAN_CTL2 */
#define MSC_SCAN_CTL2_NUM_EPI_CYCLES_Pos        0UL
#define MSC_SCAN_CTL2_NUM_EPI_CYCLES_Msk        0x3FFUL
#define MSC_SCAN_CTL2_CHOP_POL_Pos              16UL
#define MSC_SCAN_CTL2_CHOP_POL_Msk              0x10000UL
#define MSC_SCAN_CTL2_CHOP_EVEN_HOLD_EN_Pos     24UL
#define MSC_SCAN_CTL2_CHOP_EVEN_HOLD_EN_Msk     0x1000000UL
/* MSC.INIT_CTL1 */
#define MSC_INIT_CTL1_NUM_INIT_CMOD_12_RAIL_CYCLES_Pos 0UL
#define MSC_INIT_CTL1_NUM_INIT_CMOD_12_RAIL_CYCLES_Msk 0xFFFUL
#define MSC_INIT_CTL1_NUM_INIT_CMOD_12_SHORT_CYCLES_Pos 16UL
#define MSC_INIT_CTL1_NUM_INIT_CMOD_12_SHORT_CYCLES_Msk 0xFFF0000UL
#define MSC_INIT_CTL1_PER_SAMPLE_Pos            28UL
#define MSC_INIT_CTL1_PER_SAMPLE_Msk            0x10000000UL
/* MSC.INIT_CTL2 */
#define MSC_INIT_CTL2_NUM_INIT_CMOD_34_RAIL_CYCLES_Pos 0UL
#define MSC_INIT_CTL2_NUM_INIT_CMOD_34_RAIL_CYCLES_Msk 0xFFFUL
#define MSC_INIT_CTL2_NUM_INIT_CMOD_34_SHORT_CYCLES_Pos 16UL
#define MSC_INIT_CTL2_NUM_INIT_CMOD_34_SHORT_CYCLES_Msk 0xFFF0000UL
/* MSC.INIT_CTL3 */
#define MSC_INIT_CTL3_NUM_PRO_OFFSET_CYCLES_Pos 0UL
#define MSC_INIT_CTL3_NUM_PRO_OFFSET_CYCLES_Msk 0xFFUL
#define MSC_INIT_CTL3_NUM_PRO_OFFSET_TRIPS_Pos  8UL
#define MSC_INIT_CTL3_NUM_PRO_OFFSET_TRIPS_Msk  0x300UL
#define MSC_INIT_CTL3_CMOD_SEL_Pos              10UL
#define MSC_INIT_CTL3_CMOD_SEL_Msk              0xC00UL
#define MSC_INIT_CTL3_INIT_MODE_Pos             15UL
#define MSC_INIT_CTL3_INIT_MODE_Msk             0x8000UL
/* MSC.INIT_CTL4 */
#define MSC_INIT_CTL4_NUM_PRO_DUMMY_SUB_CONVS_Pos 0UL
#define MSC_INIT_CTL4_NUM_PRO_DUMMY_SUB_CONVS_Msk 0xFFUL
#define MSC_INIT_CTL4_NUM_PRO_WAIT_CYCLES_Pos   16UL
#define MSC_INIT_CTL4_NUM_PRO_WAIT_CYCLES_Msk   0x3FF0000UL
/* MSC.SENSE_DUTY_CTL */
#define MSC_SENSE_DUTY_CTL_PHASE_WIDTH_Pos      0UL
#define MSC_SENSE_DUTY_CTL_PHASE_WIDTH_Msk      0xFFFUL
#define MSC_SENSE_DUTY_CTL_PHASE_SHIFT_CYCLES_Pos 16UL
#define MSC_SENSE_DUTY_CTL_PHASE_SHIFT_CYCLES_Msk 0x3FF0000UL
#define MSC_SENSE_DUTY_CTL_PHASE_WIDTH_SEL_Pos  27UL
#define MSC_SENSE_DUTY_CTL_PHASE_WIDTH_SEL_Msk  0x8000000UL
/* MSC.SENSE_PERIOD_CTL */
#define MSC_SENSE_PERIOD_CTL_LFSR_POLY_Pos      0UL
#define MSC_SENSE_PERIOD_CTL_LFSR_POLY_Msk      0xFFFUL
#define MSC_SENSE_PERIOD_CTL_LFSR_SCALE_Pos     16UL
#define MSC_SENSE_PERIOD_CTL_LFSR_SCALE_Msk     0xF0000UL
/* MSC.FILTER_CTL */
#define MSC_FILTER_CTL_BIT_FORMAT_Pos           16UL
#define MSC_FILTER_CTL_BIT_FORMAT_Msk           0x10000UL
#define MSC_FILTER_CTL_FILTER_MODE_Pos          24UL
#define MSC_FILTER_CTL_FILTER_MODE_Msk          0x1000000UL
/* MSC.CCOMP_CDAC_CTL */
#define MSC_CCOMP_CDAC_CTL_SEL_CO_PRO_OFFSET_Pos 8UL
#define MSC_CCOMP_CDAC_CTL_SEL_CO_PRO_OFFSET_Msk 0xFF00UL
#define MSC_CCOMP_CDAC_CTL_EPILOGUE_EN_Pos      31UL
#define MSC_CCOMP_CDAC_CTL_EPILOGUE_EN_Msk      0x80000000UL
/* MSC.DITHER_CDAC_CTL */
#define MSC_DITHER_CDAC_CTL_SEL_FL_Pos          0UL
#define MSC_DITHER_CDAC_CTL_SEL_FL_Msk          0xFFUL
#define MSC_DITHER_CDAC_CTL_LFSR_POLY_FL_Pos    16UL
#define MSC_DITHER_CDAC_CTL_LFSR_POLY_FL_Msk    0xFF0000UL
/* MSC.CSW_CTL */
#define MSC_CSW_CTL_CSW_FUNC_MODE_Pos           0UL
#define MSC_CSW_CTL_CSW_FUNC_MODE_Msk           0xFFFFFFFFUL
/* MSC.SW_SEL_GPIO */
#define MSC_SW_SEL_GPIO_SW_CSD_SENSE_Pos        0UL
#define MSC_SW_SEL_GPIO_SW_CSD_SENSE_Msk        0x7UL
#define MSC_SW_SEL_GPIO_SW_CSD_SHIELD_Pos       4UL
#define MSC_SW_SEL_GPIO_SW_CSD_SHIELD_Msk       0x70UL
#define MSC_SW_SEL_GPIO_SW_CSD_MUTUAL_Pos       8UL
#define MSC_SW_SEL_GPIO_SW_CSD_MUTUAL_Msk       0x100UL
#define MSC_SW_SEL_GPIO_SW_CSD_POLARITY_Pos     12UL
#define MSC_SW_SEL_GPIO_SW_CSD_POLARITY_Msk     0x3000UL
#define MSC_SW_SEL_GPIO_SW_CSD_CHARGE_Pos       16UL
#define MSC_SW_SEL_GPIO_SW_CSD_CHARGE_Msk       0x10000UL
#define MSC_SW_SEL_GPIO_SW_DSI_CMOD_Pos         20UL
#define MSC_SW_SEL_GPIO_SW_DSI_CMOD_Msk         0x700000UL
#define MSC_SW_SEL_GPIO_SW_DSI_CSH_TANK_Pos     24UL
#define MSC_SW_SEL_GPIO_SW_DSI_CSH_TANK_Msk     0x7000000UL
/* MSC.SW_SEL_CDAC_RE */
#define MSC_SW_SEL_CDAC_RE_SW_RETCA_Pos         0UL
#define MSC_SW_SEL_CDAC_RE_SW_RETCA_Msk         0x7UL
#define MSC_SW_SEL_CDAC_RE_SW_RECB_Pos          4UL
#define MSC_SW_SEL_CDAC_RE_SW_RECB_Msk          0x70UL
#define MSC_SW_SEL_CDAC_RE_SW_RETV_Pos          8UL
#define MSC_SW_SEL_CDAC_RE_SW_RETV_Msk          0x700UL
#define MSC_SW_SEL_CDAC_RE_SW_RETG_Pos          12UL
#define MSC_SW_SEL_CDAC_RE_SW_RETG_Msk          0x7000UL
#define MSC_SW_SEL_CDAC_RE_SW_REBV_Pos          16UL
#define MSC_SW_SEL_CDAC_RE_SW_REBV_Msk          0x30000UL
#define MSC_SW_SEL_CDAC_RE_SW_REBG_Pos          20UL
#define MSC_SW_SEL_CDAC_RE_SW_REBG_Msk          0x300000UL
/* MSC.SW_SEL_CDAC_CO */
#define MSC_SW_SEL_CDAC_CO_SW_COTCA_Pos         0UL
#define MSC_SW_SEL_CDAC_CO_SW_COTCA_Msk         0x7UL
#define MSC_SW_SEL_CDAC_CO_SW_COCB_Pos          4UL
#define MSC_SW_SEL_CDAC_CO_SW_COCB_Msk          0x70UL
#define MSC_SW_SEL_CDAC_CO_SW_COTV_Pos          8UL
#define MSC_SW_SEL_CDAC_CO_SW_COTV_Msk          0x700UL
#define MSC_SW_SEL_CDAC_CO_SW_COTG_Pos          12UL
#define MSC_SW_SEL_CDAC_CO_SW_COTG_Msk          0x7000UL
#define MSC_SW_SEL_CDAC_CO_SW_COBV_Pos          16UL
#define MSC_SW_SEL_CDAC_CO_SW_COBV_Msk          0x30000UL
#define MSC_SW_SEL_CDAC_CO_SW_COBG_Pos          20UL
#define MSC_SW_SEL_CDAC_CO_SW_COBG_Msk          0x300000UL
/* MSC.SW_SEL_CDAC_CF */
#define MSC_SW_SEL_CDAC_CF_SW_CFTCA_Pos         0UL
#define MSC_SW_SEL_CDAC_CF_SW_CFTCA_Msk         0x7UL
#define MSC_SW_SEL_CDAC_CF_SW_CFTCB_Pos         4UL
#define MSC_SW_SEL_CDAC_CF_SW_CFTCB_Msk         0x70UL
#define MSC_SW_SEL_CDAC_CF_SW_CFTV_Pos          8UL
#define MSC_SW_SEL_CDAC_CF_SW_CFTV_Msk          0x700UL
#define MSC_SW_SEL_CDAC_CF_SW_CFTG_Pos          12UL
#define MSC_SW_SEL_CDAC_CF_SW_CFTG_Msk          0x7000UL
#define MSC_SW_SEL_CDAC_CF_SW_CFBV_Pos          16UL
#define MSC_SW_SEL_CDAC_CF_SW_CFBV_Msk          0x30000UL
#define MSC_SW_SEL_CDAC_CF_SW_CFBG_Pos          20UL
#define MSC_SW_SEL_CDAC_CF_SW_CFBG_Msk          0x300000UL
/* MSC.SW_SEL_CMOD1 */
#define MSC_SW_SEL_CMOD1_SW_C1CA_Pos            0UL
#define MSC_SW_SEL_CMOD1_SW_C1CA_Msk            0xFUL
#define MSC_SW_SEL_CMOD1_SW_C1CB_Pos            8UL
#define MSC_SW_SEL_CMOD1_SW_C1CB_Msk            0xF00UL
#define MSC_SW_SEL_CMOD1_SW_C1CC_Pos            12UL
#define MSC_SW_SEL_CMOD1_SW_C1CC_Msk            0x3000UL
#define MSC_SW_SEL_CMOD1_SW_C1CV_Pos            16UL
#define MSC_SW_SEL_CMOD1_SW_C1CV_Msk            0xF0000UL
#define MSC_SW_SEL_CMOD1_SW_C1CG_Pos            24UL
#define MSC_SW_SEL_CMOD1_SW_C1CG_Msk            0xF000000UL
#define MSC_SW_SEL_CMOD1_REF_MODE_Pos           30UL
#define MSC_SW_SEL_CMOD1_REF_MODE_Msk           0x40000000UL
#define MSC_SW_SEL_CMOD1_ENABLED_Pos            31UL
#define MSC_SW_SEL_CMOD1_ENABLED_Msk            0x80000000UL
/* MSC.SW_SEL_CMOD2 */
#define MSC_SW_SEL_CMOD2_SW_C2CA_Pos            0UL
#define MSC_SW_SEL_CMOD2_SW_C2CA_Msk            0xFUL
#define MSC_SW_SEL_CMOD2_SW_C2CB_Pos            8UL
#define MSC_SW_SEL_CMOD2_SW_C2CB_Msk            0xF00UL
#define MSC_SW_SEL_CMOD2_SW_C2CC_Pos            12UL
#define MSC_SW_SEL_CMOD2_SW_C2CC_Msk            0x3000UL
#define MSC_SW_SEL_CMOD2_SW_C2CV_Pos            16UL
#define MSC_SW_SEL_CMOD2_SW_C2CV_Msk            0xF0000UL
#define MSC_SW_SEL_CMOD2_SW_C2CG_Pos            24UL
#define MSC_SW_SEL_CMOD2_SW_C2CG_Msk            0xF000000UL
#define MSC_SW_SEL_CMOD2_REF_MODE_Pos           30UL
#define MSC_SW_SEL_CMOD2_REF_MODE_Msk           0x40000000UL
#define MSC_SW_SEL_CMOD2_ENABLED_Pos            31UL
#define MSC_SW_SEL_CMOD2_ENABLED_Msk            0x80000000UL
/* MSC.SW_SEL_CMOD3 */
#define MSC_SW_SEL_CMOD3_SW_C3CA_Pos            0UL
#define MSC_SW_SEL_CMOD3_SW_C3CA_Msk            0xFUL
#define MSC_SW_SEL_CMOD3_SW_C3CB_Pos            8UL
#define MSC_SW_SEL_CMOD3_SW_C3CB_Msk            0xF00UL
#define MSC_SW_SEL_CMOD3_SW_C3CC_Pos            12UL
#define MSC_SW_SEL_CMOD3_SW_C3CC_Msk            0x3000UL
#define MSC_SW_SEL_CMOD3_SW_C3CV_Pos            16UL
#define MSC_SW_SEL_CMOD3_SW_C3CV_Msk            0xF0000UL
#define MSC_SW_SEL_CMOD3_SW_C3CG_Pos            24UL
#define MSC_SW_SEL_CMOD3_SW_C3CG_Msk            0xF000000UL
#define MSC_SW_SEL_CMOD3_REF_MODE_Pos           30UL
#define MSC_SW_SEL_CMOD3_REF_MODE_Msk           0x40000000UL
#define MSC_SW_SEL_CMOD3_ENABLED_Pos            31UL
#define MSC_SW_SEL_CMOD3_ENABLED_Msk            0x80000000UL
/* MSC.SW_SEL_CMOD4 */
#define MSC_SW_SEL_CMOD4_SW_C4CA_Pos            0UL
#define MSC_SW_SEL_CMOD4_SW_C4CA_Msk            0xFUL
#define MSC_SW_SEL_CMOD4_SW_C4CB_Pos            8UL
#define MSC_SW_SEL_CMOD4_SW_C4CB_Msk            0xF00UL
#define MSC_SW_SEL_CMOD4_SW_C4CC_Pos            12UL
#define MSC_SW_SEL_CMOD4_SW_C4CC_Msk            0x3000UL
#define MSC_SW_SEL_CMOD4_SW_C4CV_Pos            16UL
#define MSC_SW_SEL_CMOD4_SW_C4CV_Msk            0xF0000UL
#define MSC_SW_SEL_CMOD4_SW_C4CG_Pos            24UL
#define MSC_SW_SEL_CMOD4_SW_C4CG_Msk            0xF000000UL
#define MSC_SW_SEL_CMOD4_REF_MODE_Pos           30UL
#define MSC_SW_SEL_CMOD4_REF_MODE_Msk           0x40000000UL
#define MSC_SW_SEL_CMOD4_ENABLED_Pos            31UL
#define MSC_SW_SEL_CMOD4_ENABLED_Msk            0x80000000UL
/* MSC.OBS_CTL */
#define MSC_OBS_CTL_OBSERVE0_Pos                0UL
#define MSC_OBS_CTL_OBSERVE0_Msk                0xFUL
#define MSC_OBS_CTL_OBSERVE1_Pos                8UL
#define MSC_OBS_CTL_OBSERVE1_Msk                0xF00UL
#define MSC_OBS_CTL_OBSERVE2_Pos                16UL
#define MSC_OBS_CTL_OBSERVE2_Msk                0xF0000UL
#define MSC_OBS_CTL_OBSERVE3_Pos                24UL
#define MSC_OBS_CTL_OBSERVE3_Msk                0xF000000UL
/* MSC.WAKEUP_CTL */
#define MSC_WAKEUP_CTL_WAKEUP_TIMER_Pos         0UL
#define MSC_WAKEUP_CTL_WAKEUP_TIMER_Msk         0xFFFFUL
#define MSC_WAKEUP_CTL_ENABLED_Pos              31UL
#define MSC_WAKEUP_CTL_ENABLED_Msk              0x80000000UL
/* MSC.LP_AOC_CTL */
#define MSC_LP_AOC_CTL_BUCKET_THRESHOLD_Pos     0UL
#define MSC_LP_AOC_CTL_BUCKET_THRESHOLD_Msk     0xFFFFUL
#define MSC_LP_AOC_CTL_BUCKET_STEP_SIZE_Pos     16UL
#define MSC_LP_AOC_CTL_BUCKET_STEP_SIZE_Msk     0xFF0000UL
#define MSC_LP_AOC_CTL_DEBOUNCE_THRESHOLD_Pos   24UL
#define MSC_LP_AOC_CTL_DEBOUNCE_THRESHOLD_Msk   0xF000000UL
/* MSC.STATUS1 */
#define MSC_STATUS1_RAW_COUNT_Pos               0UL
#define MSC_STATUS1_RAW_COUNT_Msk               0xFFFFUL
#define MSC_STATUS1_RAW_COUNT_POS_Pos           16UL
#define MSC_STATUS1_RAW_COUNT_POS_Msk           0xFFFF0000UL
/* MSC.STATUS2 */
#define MSC_STATUS2_DEBUG_CONV_COUNT_Pos        0UL
#define MSC_STATUS2_DEBUG_CONV_COUNT_Msk        0xFFFFUL
/* MSC.STATUS3 */
#define MSC_STATUS3_NUM_SUB_CONVS_Pos           0UL
#define MSC_STATUS3_NUM_SUB_CONVS_Msk           0xFFFFUL
#define MSC_STATUS3_SEQ_STATE_Pos               16UL
#define MSC_STATUS3_SEQ_STATE_Msk               0xF0000UL
#define MSC_STATUS3_FS_CLOCK_Pos                24UL
#define MSC_STATUS3_FS_CLOCK_Msk                0x1000000UL
#define MSC_STATUS3_MSC_CMP_OUT_Pos             28UL
#define MSC_STATUS3_MSC_CMP_OUT_Msk             0x10000000UL
/* MSC.RESULT_FIFO_STATUS */
#define MSC_RESULT_FIFO_STATUS_USED_Pos         0UL
#define MSC_RESULT_FIFO_STATUS_USED_Msk         0x3FFUL
#define MSC_RESULT_FIFO_STATUS_WR_PTR_Pos       10UL
#define MSC_RESULT_FIFO_STATUS_WR_PTR_Msk       0xFFC00UL
#define MSC_RESULT_FIFO_STATUS_RD_PTR_Pos       20UL
#define MSC_RESULT_FIFO_STATUS_RD_PTR_Msk       0x3FF00000UL
#define MSC_RESULT_FIFO_STATUS_FIFO_UNDERFLOW_Pos 30UL
#define MSC_RESULT_FIFO_STATUS_FIFO_UNDERFLOW_Msk 0x40000000UL
#define MSC_RESULT_FIFO_STATUS_FIFO_OVERFLOW_Pos 31UL
#define MSC_RESULT_FIFO_STATUS_FIFO_OVERFLOW_Msk 0x80000000UL
/* MSC.RESULT_FIFO_RD */
#define MSC_RESULT_FIFO_RD_RAW_COUNT_Pos        0UL
#define MSC_RESULT_FIFO_RD_RAW_COUNT_Msk        0xFFFFUL
#define MSC_RESULT_FIFO_RD_OVERFLOW_Pos         16UL
#define MSC_RESULT_FIFO_RD_OVERFLOW_Msk         0x10000UL
#define MSC_RESULT_FIFO_RD_RESAMPLE_COUNT_Pos   20UL
#define MSC_RESULT_FIFO_RD_RESAMPLE_COUNT_Msk   0x700000UL
#define MSC_RESULT_FIFO_RD_BAD_CONV_COUNT_Pos   24UL
#define MSC_RESULT_FIFO_RD_BAD_CONV_COUNT_Msk   0xF000000UL
/* MSC.INTR */
#define MSC_INTR_SUB_SAMPLE_Pos                 0UL
#define MSC_INTR_SUB_SAMPLE_Msk                 0x1UL
#define MSC_INTR_SAMPLE_Pos                     4UL
#define MSC_INTR_SAMPLE_Msk                     0x10UL
#define MSC_INTR_SCAN_Pos                       8UL
#define MSC_INTR_SCAN_Msk                       0x100UL
#define MSC_INTR_INIT_Pos                       12UL
#define MSC_INTR_INIT_Msk                       0x1000UL
#define MSC_INTR_FRAME_Pos                      16UL
#define MSC_INTR_FRAME_Msk                      0x10000UL
#define MSC_INTR_CIC2_ERROR_Pos                 20UL
#define MSC_INTR_CIC2_ERROR_Msk                 0x100000UL
#define MSC_INTR_CONFIG_REQ_Pos                 24UL
#define MSC_INTR_CONFIG_REQ_Msk                 0x1000000UL
#define MSC_INTR_FIFO_UNDERFLOW_Pos             30UL
#define MSC_INTR_FIFO_UNDERFLOW_Msk             0x40000000UL
#define MSC_INTR_FIFO_OVERFLOW_Pos              31UL
#define MSC_INTR_FIFO_OVERFLOW_Msk              0x80000000UL
/* MSC.INTR_SET */
#define MSC_INTR_SET_SUB_SAMPLE_Pos             0UL
#define MSC_INTR_SET_SUB_SAMPLE_Msk             0x1UL
#define MSC_INTR_SET_SAMPLE_Pos                 4UL
#define MSC_INTR_SET_SAMPLE_Msk                 0x10UL
#define MSC_INTR_SET_SCAN_Pos                   8UL
#define MSC_INTR_SET_SCAN_Msk                   0x100UL
#define MSC_INTR_SET_INIT_Pos                   12UL
#define MSC_INTR_SET_INIT_Msk                   0x1000UL
#define MSC_INTR_SET_FRAME_Pos                  16UL
#define MSC_INTR_SET_FRAME_Msk                  0x10000UL
#define MSC_INTR_SET_CIC2_ERROR_Pos             20UL
#define MSC_INTR_SET_CIC2_ERROR_Msk             0x100000UL
#define MSC_INTR_SET_CONFIG_REQ_Pos             24UL
#define MSC_INTR_SET_CONFIG_REQ_Msk             0x1000000UL
#define MSC_INTR_SET_FIFO_UNDERFLOW_Pos         30UL
#define MSC_INTR_SET_FIFO_UNDERFLOW_Msk         0x40000000UL
#define MSC_INTR_SET_FIFO_OVERFLOW_Pos          31UL
#define MSC_INTR_SET_FIFO_OVERFLOW_Msk          0x80000000UL
/* MSC.INTR_MASK */
#define MSC_INTR_MASK_SUB_SAMPLE_Pos            0UL
#define MSC_INTR_MASK_SUB_SAMPLE_Msk            0x1UL
#define MSC_INTR_MASK_SAMPLE_Pos                4UL
#define MSC_INTR_MASK_SAMPLE_Msk                0x10UL
#define MSC_INTR_MASK_SCAN_Pos                  8UL
#define MSC_INTR_MASK_SCAN_Msk                  0x100UL
#define MSC_INTR_MASK_INIT_Pos                  12UL
#define MSC_INTR_MASK_INIT_Msk                  0x1000UL
#define MSC_INTR_MASK_FRAME_Pos                 16UL
#define MSC_INTR_MASK_FRAME_Msk                 0x10000UL
#define MSC_INTR_MASK_CIC2_ERROR_Pos            20UL
#define MSC_INTR_MASK_CIC2_ERROR_Msk            0x100000UL
#define MSC_INTR_MASK_CONFIG_REQ_Pos            24UL
#define MSC_INTR_MASK_CONFIG_REQ_Msk            0x1000000UL
#define MSC_INTR_MASK_FIFO_UNDERFLOW_Pos        30UL
#define MSC_INTR_MASK_FIFO_UNDERFLOW_Msk        0x40000000UL
#define MSC_INTR_MASK_FIFO_OVERFLOW_Pos         31UL
#define MSC_INTR_MASK_FIFO_OVERFLOW_Msk         0x80000000UL
/* MSC.INTR_MASKED */
#define MSC_INTR_MASKED_SUB_SAMPLE_Pos          0UL
#define MSC_INTR_MASKED_SUB_SAMPLE_Msk          0x1UL
#define MSC_INTR_MASKED_SAMPLE_Pos              4UL
#define MSC_INTR_MASKED_SAMPLE_Msk              0x10UL
#define MSC_INTR_MASKED_SCAN_Pos                8UL
#define MSC_INTR_MASKED_SCAN_Msk                0x100UL
#define MSC_INTR_MASKED_INIT_Pos                12UL
#define MSC_INTR_MASKED_INIT_Msk                0x1000UL
#define MSC_INTR_MASKED_FRAME_Pos               16UL
#define MSC_INTR_MASKED_FRAME_Msk               0x10000UL
#define MSC_INTR_MASKED_CIC2_ERROR_Pos          20UL
#define MSC_INTR_MASKED_CIC2_ERROR_Msk          0x100000UL
#define MSC_INTR_MASKED_CONFIG_REQ_Pos          24UL
#define MSC_INTR_MASKED_CONFIG_REQ_Msk          0x1000000UL
#define MSC_INTR_MASKED_FIFO_UNDERFLOW_Pos      30UL
#define MSC_INTR_MASKED_FIFO_UNDERFLOW_Msk      0x40000000UL
#define MSC_INTR_MASKED_FIFO_OVERFLOW_Pos       31UL
#define MSC_INTR_MASKED_FIFO_OVERFLOW_Msk       0x80000000UL
/* MSC.INTR_LP */
#define MSC_INTR_LP_WAKEUP_Pos                  0UL
#define MSC_INTR_LP_WAKEUP_Msk                  0x1UL
/* MSC.INTR_LP_SET */
#define MSC_INTR_LP_SET_WAKEUP_Pos              0UL
#define MSC_INTR_LP_SET_WAKEUP_Msk              0x1UL
/* MSC.INTR_LP_MASK */
#define MSC_INTR_LP_MASK_WAKEUP_Pos             0UL
#define MSC_INTR_LP_MASK_WAKEUP_Msk             0x1UL
/* MSC.INTR_LP_MASKED */
#define MSC_INTR_LP_MASKED_WAKEUP_Pos           0UL
#define MSC_INTR_LP_MASKED_WAKEUP_Msk           0x1UL
/* MSC.FRAME_CMD */
#define MSC_FRAME_CMD_START_FRAME_Pos           0UL
#define MSC_FRAME_CMD_START_FRAME_Msk           0x1UL
/* MSC.WAKEUP_CMD */
#define MSC_WAKEUP_CMD_WAIT_FOR_DS_Pos          0UL
#define MSC_WAKEUP_CMD_WAIT_FOR_DS_Msk          0x1UL
#define MSC_WAKEUP_CMD_ABORT_Pos                16UL
#define MSC_WAKEUP_CMD_ABORT_Msk                0x10000UL
/* MSC.SNS_STRUCT_CTL */
#define MSC_SNS_STRUCT_CTL_OFFSET_Pos           0UL
#define MSC_SNS_STRUCT_CTL_OFFSET_Msk           0xFUL
#define MSC_SNS_STRUCT_CTL_LENGTH_Pos           8UL
#define MSC_SNS_STRUCT_CTL_LENGTH_Msk           0xF00UL
/* MSC.SNS_LP_AOC_SENSOR_CTL1 */
#define MSC_SNS_LP_AOC_SENSOR_CTL1_P_BUCKET_Pos 0UL
#define MSC_SNS_LP_AOC_SENSOR_CTL1_P_BUCKET_Msk 0xFFFFUL
#define MSC_SNS_LP_AOC_SENSOR_CTL1_N_BUCKET_Pos 16UL
#define MSC_SNS_LP_AOC_SENSOR_CTL1_N_BUCKET_Msk 0xFFFF0000UL
/* MSC.SNS_LP_AOC_SENSOR_CTL2 */
#define MSC_SNS_LP_AOC_SENSOR_CTL2_SENSOR_BASELINE_Pos 0UL
#define MSC_SNS_LP_AOC_SENSOR_CTL2_SENSOR_BASELINE_Msk 0xFFFFUL
#define MSC_SNS_LP_AOC_SENSOR_CTL2_TOUCH_THRESHOLD_Pos 16UL
#define MSC_SNS_LP_AOC_SENSOR_CTL2_TOUCH_THRESHOLD_Msk 0xFFF0000UL
/* MSC.SNS_SW_SEL_CSW_MASK2 */
#define MSC_SNS_SW_SEL_CSW_MASK2_FUNC_MASK_Pos  0UL
#define MSC_SNS_SW_SEL_CSW_MASK2_FUNC_MASK_Msk  0xFFFFFFFFUL
/* MSC.SNS_SW_SEL_CSW_MASK1 */
#define MSC_SNS_SW_SEL_CSW_MASK1_FUNC_MASK_Pos  0UL
#define MSC_SNS_SW_SEL_CSW_MASK1_FUNC_MASK_Msk  0xFFFFFFFFUL
/* MSC.SNS_SW_SEL_CSW_MASK0 */
#define MSC_SNS_SW_SEL_CSW_MASK0_FUNC_MASK_Pos  0UL
#define MSC_SNS_SW_SEL_CSW_MASK0_FUNC_MASK_Msk  0xFFFFFFFFUL
/* MSC.SNS_SCAN_CTL */
#define MSC_SNS_SCAN_CTL_NUM_SUB_CONVS_Pos      0UL
#define MSC_SNS_SCAN_CTL_NUM_SUB_CONVS_Msk      0xFFFFUL
#define MSC_SNS_SCAN_CTL_COMP_DIV_Pos           16UL
#define MSC_SNS_SCAN_CTL_COMP_DIV_Msk           0xFFF0000UL
#define MSC_SNS_SCAN_CTL_NUM_CONV_Pos           28UL
#define MSC_SNS_SCAN_CTL_NUM_CONV_Msk           0x70000000UL
#define MSC_SNS_SCAN_CTL_INIT_BYPASS_Pos        31UL
#define MSC_SNS_SCAN_CTL_INIT_BYPASS_Msk        0x80000000UL
/* MSC.SNS_CDAC_CTL */
#define MSC_SNS_CDAC_CTL_SEL_RE_Pos             0UL
#define MSC_SNS_CDAC_CTL_SEL_RE_Msk             0xFFUL
#define MSC_SNS_CDAC_CTL_SEL_CO_Pos             8UL
#define MSC_SNS_CDAC_CTL_SEL_CO_Msk             0xFF00UL
#define MSC_SNS_CDAC_CTL_SEL_CF_Pos             16UL
#define MSC_SNS_CDAC_CTL_SEL_CF_Msk             0x1F0000UL
#define MSC_SNS_CDAC_CTL_FINE_MODE_Pos          21UL
#define MSC_SNS_CDAC_CTL_FINE_MODE_Msk          0x200000UL
#define MSC_SNS_CDAC_CTL_CLOCK_REF_RATE_Pos     22UL
#define MSC_SNS_CDAC_CTL_CLOCK_REF_RATE_Msk     0x400000UL
#define MSC_SNS_CDAC_CTL_FL_EN_Pos              23UL
#define MSC_SNS_CDAC_CTL_FL_EN_Msk              0x800000UL
#define MSC_SNS_CDAC_CTL_LFSR_SCALE_FL_Pos      24UL
#define MSC_SNS_CDAC_CTL_LFSR_SCALE_FL_Msk      0x7000000UL
#define MSC_SNS_CDAC_CTL_LFSR_SCALE_TYPE_FL_Pos 28UL
#define MSC_SNS_CDAC_CTL_LFSR_SCALE_TYPE_FL_Msk 0x10000000UL
/* MSC.SNS_CTL */
#define MSC_SNS_CTL_START_SCAN_Pos              0UL
#define MSC_SNS_CTL_START_SCAN_Msk              0x1UL
#define MSC_SNS_CTL_VALID_Pos                   1UL
#define MSC_SNS_CTL_VALID_Msk                   0x2UL
#define MSC_SNS_CTL_LAST_Pos                    2UL
#define MSC_SNS_CTL_LAST_Msk                    0x4UL
#define MSC_SNS_CTL_MULTI_CH_MODE_Pos           4UL
#define MSC_SNS_CTL_MULTI_CH_MODE_Msk           0x30UL
#define MSC_SNS_CTL_SENSE_MODE_SEL_Pos          6UL
#define MSC_SNS_CTL_SENSE_MODE_SEL_Msk          0xC0UL
#define MSC_SNS_CTL_DECIM_RATE_Pos              8UL
#define MSC_SNS_CTL_DECIM_RATE_Msk              0xFF00UL
#define MSC_SNS_CTL_SENSE_DIV_Pos               16UL
#define MSC_SNS_CTL_SENSE_DIV_Msk               0xFFF0000UL
#define MSC_SNS_CTL_LFSR_MODE_Pos               28UL
#define MSC_SNS_CTL_LFSR_MODE_Msk               0x30000000UL
#define MSC_SNS_CTL_LFSR_BITS_Pos               30UL
#define MSC_SNS_CTL_LFSR_BITS_Msk               0xC0000000UL
/* MSC.SW_SEL_CSW */
#define MSC_SW_SEL_CSW_SW_SNCA_Pos              0UL
#define MSC_SW_SEL_CSW_SW_SNCA_Msk              0xFUL
#define MSC_SW_SEL_CSW_SW_SNCB_Pos              8UL
#define MSC_SW_SEL_CSW_SW_SNCB_Msk              0xF00UL
#define MSC_SW_SEL_CSW_SW_SNCC_Pos              12UL
#define MSC_SW_SEL_CSW_SW_SNCC_Msk              0x3000UL
#define MSC_SW_SEL_CSW_SW_SNCV_Pos              16UL
#define MSC_SW_SEL_CSW_SW_SNCV_Msk              0xF0000UL
#define MSC_SW_SEL_CSW_SW_SNCG_Pos              24UL
#define MSC_SW_SEL_CSW_SW_SNCG_Msk              0xF000000UL
#define MSC_SW_SEL_CSW_REF_MODE_Pos             30UL
#define MSC_SW_SEL_CSW_REF_MODE_Msk             0x40000000UL
#define MSC_SW_SEL_CSW_ENABLED_Pos              31UL
#define MSC_SW_SEL_CSW_ENABLED_Msk              0x80000000UL
/* MSC.SW_SEL_CSW_FUNC */
#define MSC_SW_SEL_CSW_FUNC_SW_SNCA_Pos         0UL
#define MSC_SW_SEL_CSW_FUNC_SW_SNCA_Msk         0xFUL
#define MSC_SW_SEL_CSW_FUNC_SW_SNCB_Pos         8UL
#define MSC_SW_SEL_CSW_FUNC_SW_SNCB_Msk         0xF00UL
#define MSC_SW_SEL_CSW_FUNC_SW_SNCC_Pos         12UL
#define MSC_SW_SEL_CSW_FUNC_SW_SNCC_Msk         0x3000UL
#define MSC_SW_SEL_CSW_FUNC_SW_SNCV_Pos         16UL
#define MSC_SW_SEL_CSW_FUNC_SW_SNCV_Msk         0xF0000UL
#define MSC_SW_SEL_CSW_FUNC_SW_SNCG_Pos         24UL
#define MSC_SW_SEL_CSW_FUNC_SW_SNCG_Msk         0xF000000UL
#define MSC_SW_SEL_CSW_FUNC_REF_MODE_Pos        30UL
#define MSC_SW_SEL_CSW_FUNC_REF_MODE_Msk        0x40000000UL
#define MSC_SW_SEL_CSW_FUNC_ENABLED_Pos         31UL
#define MSC_SW_SEL_CSW_FUNC_ENABLED_Msk         0x80000000UL
/* MSC.SENSOR_DATA */
#define MSC_SENSOR_DATA_DATA_Pos                0UL
#define MSC_SENSOR_DATA_DATA_Msk                0xFFFFFFFFUL
/* MSC.TRIM_CTL */
#define MSC_TRIM_CTL_TRIM_IN_Pos                0UL
#define MSC_TRIM_CTL_TRIM_IN_Msk                0xFUL
#define MSC_TRIM_CTL_TRIM_EN_Pos                4UL
#define MSC_TRIM_CTL_TRIM_EN_Msk                0x10UL
#define MSC_TRIM_CTL_TRIM_POLARITY_Pos          5UL
#define MSC_TRIM_CTL_TRIM_POLARITY_Msk          0x20UL


#endif /* _CYIP_MSC_H_ */


/* [] END OF FILE */
