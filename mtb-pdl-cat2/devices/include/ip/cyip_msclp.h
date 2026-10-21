/***************************************************************************//**
* \file cyip_msclp.h
*
* \brief
* MSCLP IP definitions
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

#ifndef _CYIP_MSCLP_H_
#define _CYIP_MSCLP_H_

#include "cyip_headers.h"

/*******************************************************************************
*                                    MSCLP
*******************************************************************************/

#define MSCLP_MODE_SECTION_SIZE                 0x00000040UL
#define MSCLP_SNS_SECTION_SIZE                  0x00002000UL
#define MSCLP_SECTION_SIZE                      0x00010000UL

/**
  * \brief Sense Mode Configuration Structure (MSCLP_MODE)
  */
typedef struct {
  __IOM uint32_t SENSE_DUTY_CTL;                /*!< 0x00000000 Sense Clock Duty Cycle Control */
  __IOM uint32_t SW_SEL_CDAC_FL;                /*!< 0x00000004 Flatspot/Dither CAPDAC Switch Control */
  __IOM uint32_t SW_SEL_TOP;                    /*!< 0x00000008 Top Level Switch Control */
  __IOM uint32_t SW_SEL_COMP;                   /*!< 0x0000000C MSC Comparator Switch Control */
  __IOM uint32_t SW_SEL_SH;                     /*!< 0x00000010 Shielding Switch Control */
  __IOM uint32_t SW_SEL_CMOD1;                  /*!< 0x00000014 CMOD Switch Control 1 */
  __IOM uint32_t SW_SEL_CMOD2;                  /*!< 0x00000018 CMOD Switch Control 2 */
   __IM uint32_t RESERVED;
  __IOM uint32_t SW_SEL_CMOD3;                  /*!< 0x00000020 CMOD Switch Control 3 */
  __IOM uint32_t SW_SEL_CMOD4;                  /*!< 0x00000024 CMOD Switch Control 4 */
   __IM uint32_t RESERVED1[6];
} MSCLP_MODE_Type;                              /*!< Size = 64 (0x40) */

/**
  * \brief Sensor Configuration Structure (clk_imo_msc domain) (MSCLP_SNS)
  */
typedef struct {
  __IOM uint32_t SENSOR_DATA[1024];             /*!< 0x00000000 Sensor Configuration Storage */
  __IOM uint32_t SNS_LP_AOS_SNS_CTL0;           /*!< 0x00001000 LP-AoS Sensor Control 0 */
  __IOM uint32_t SNS_LP_AOS_SNS_CTL1;           /*!< 0x00001004 LP-AoS Sensor Control 1 */
  __IOM uint32_t SNS_LP_AOS_SNS_CTL2;           /*!< 0x00001008 LP-AoS Sensor Control 2 */
  __IOM uint32_t SNS_LP_AOS_SNS_CTL3;           /*!< 0x0000100C LP-AoS Sensor Control 3 */
  __IOM uint32_t SNS_LP_AOS_SNS_CTL4;           /*!< 0x00001010 LP-AoS Sensor Control 4 */
  __IOM uint32_t SNS_SW_SEL_CSW_HI_MASK2;       /*!< 0x00001014 CAPSENSE Sensor Switch Function Select High Mask 2 */
  __IOM uint32_t SNS_SW_SEL_CSW_HI_MASK1;       /*!< 0x00001018 CAPSENSE Sensor Switch Function Select High Mask 1 */
  __IOM uint32_t SNS_SW_SEL_CSW_HI_MASK0;       /*!< 0x0000101C CAPSENSE Sensor Switch Function Select High Mask 0 */
  __IOM uint32_t SNS_SW_SEL_CSW_LO_MASK2;       /*!< 0x00001020 CAPSENSE Sensor Switch Function Select Low Mask 2 */
  __IOM uint32_t SNS_SW_SEL_CSW_LO_MASK1;       /*!< 0x00001024 CAPSENSE Sensor Switch Function Select Low Mask 1 */
  __IOM uint32_t SNS_SW_SEL_CSW_LO_MASK0;       /*!< 0x00001028 CAPSENSE Sensor Switch Function Select Low Mask 0 */
  __IOM uint32_t SNS_SCAN_CTL;                  /*!< 0x0000102C Sensor Scan Control */
  __IOM uint32_t SNS_CDAC_CTL;                  /*!< 0x00001030 Sensor CAPDAC Control */
  __IOM uint32_t SNS_CTL;                       /*!< 0x00001034 Sense Control and Command Register */
   __IM uint32_t RESERVED[114];
   __IM uint32_t RESULT_FIFO_RD;                /*!< 0x00001200 Result FIFO Pointer */
   __IM uint32_t RESERVED1[127];
   __IM uint32_t STATUS1;                       /*!< 0x00001400 General Status Register 1 */
   __IM uint32_t STATUS2;                       /*!< 0x00001404 General Status Register 2 */
   __IM uint32_t STATUS3;                       /*!< 0x00001408 General Status Register 3 */
   __IM uint32_t STATUS4;                       /*!< 0x0000140C General Status Register 4 */
   __IM uint32_t RESULT_FIFO_STATUS;            /*!< 0x00001410 Result FIFO Status */
   __IM uint32_t RESULT_FIFO_STATUS2;           /*!< 0x00001414 Result FIFO Status 2 */
   __IM uint32_t CE_STATUS;                     /*!< 0x00001418 Channel Engine Status */
   __IM uint32_t BRIDGE_STATUS;                 /*!< 0x0000141C AHB2AHB Bridge Status */
   __IM uint32_t RESERVED2[248];
  __IOM uint32_t FRAME_CMD;                     /*!< 0x00001800 Frame Command Register */
  __IOM uint32_t CE_CMD;                        /*!< 0x00001804 Channel Engine Command */
  __IOM uint32_t FIFO_CMD;                      /*!< 0x00001808 FIFO Command */
   __IM uint32_t RESERVED3[253];
  __IOM uint32_t CE_INIT_CTL;                   /*!< 0x00001C00 Channel Engine Initialisation Control */
   __IM uint32_t RESERVED4[255];
} MSCLP_SNS_Type;                               /*!< Size = 8192 (0x2000) */

/**
  * \brief Low Power MultiSense Converter (MSCLP)
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
  __IOM uint32_t MSCCMP_CTL;                    /*!< 0x00000038 MSC Comparator Control */
   __IM uint32_t RESERVED1[5];
  __IOM uint32_t OBS_CTL;                       /*!< 0x00000050 Observability Control */
   __IM uint32_t RESERVED2[7];
  __IOM uint32_t AOS_CTL;                       /*!< 0x00000070 Always On Scanning Control */
  __IOM uint32_t CE_CTL;                        /*!< 0x00000074 Channel Engine Control */
   __IM uint32_t RESERVED3[2];
  __IOM uint32_t PUMP_CTL;                      /*!< 0x00000080 Local MRSS Pump Control */
  __IOM uint32_t IMO_CTL;                       /*!< 0x00000084 Local MRSS IMO Control */
   __IM uint32_t RESERVED4[30];
  __IOM uint32_t INTR;                          /*!< 0x00000100 MSCv3 Interrupt Cause Register */
  __IOM uint32_t INTR_SET;                      /*!< 0x00000104 MSCv3 Interrupt Set Register */
  __IOM uint32_t INTR_MASK;                     /*!< 0x00000108 MSCv3 Interrupt Mask Register */
   __IM uint32_t INTR_MASKED;                   /*!< 0x0000010C MSCv3 Interrupt Masked Register */
   __IM uint32_t RESERVED5[4];
  __IOM uint32_t INTR_LP;                       /*!< 0x00000120 Low Power Interrupt Cause Register */
  __IOM uint32_t INTR_LP_SET;                   /*!< 0x00000124 Low Power Interrupt Set Register */
  __IOM uint32_t INTR_LP_MASK;                  /*!< 0x00000128 Low Power Interrupt Mask Register */
   __IM uint32_t INTR_LP_MASKED;                /*!< 0x0000012C Low Power Interrupt Masked Register */
   __IM uint32_t RESERVED6[4];
  __IOM uint32_t WAKEUP_CMD;                    /*!< 0x00000140 Wakeup Command Register */
  __IOM uint32_t MRSS_CMD;                      /*!< 0x00000144 MRSS Command Register */
   __IM uint32_t RESERVED7[14];
   __IM uint32_t MRSS_STATUS;                   /*!< 0x00000180 MRSS Status */
   __IM uint32_t AOS_STATUS;                    /*!< 0x00000184 AoS Status */
   __IM uint32_t RESERVED8[30];
  __IOM uint32_t SW_SEL_GPIO;                   /*!< 0x00000200 GPIO Switch Control */
  __IOM uint32_t SW_SEL_CDAC_RE;                /*!< 0x00000204 Reference CAPDAC Switch Control */
  __IOM uint32_t SW_SEL_CDAC_CO;                /*!< 0x00000208 Compensation CAPDAC Switch Control */
  __IOM uint32_t SW_SEL_CDAC_CF;                /*!< 0x0000020C Fine CAPDAC Switch Control */
   __IM uint32_t RESERVED9[4];
  __IOM uint32_t SW_SEL_BGR;                    /*!< 0x00000220 Bandgap Reference Switch Control */
   __IM uint32_t RESERVED10[55];
  __IOM uint32_t SW_SEL_CSW[64];                /*!< 0x00000300 CAPSENSE Sensor Switch Control */
  __IOM uint32_t SW_SEL_CSW_FUNC[8];            /*!< 0x00000400 CAPSENSE Sensor Switch Control Global Functions */
   __IM uint32_t RESERVED11[56];
  __IOM uint32_t CSW_CTL_LO;                    /*!< 0x00000500 CAPSENSE Sensor Switch Control Low */
  __IOM uint32_t CSW_CTL_HI;                    /*!< 0x00000504 CAPSENSE Sensor Switch Control High */
   __IM uint32_t RESERVED12[62];
        MSCLP_MODE_Type MODE[4];                /*!< 0x00000600 Sense Mode Configuration Structure */
   __IM uint32_t RESERVED13[1600];
        MSCLP_SNS_Type SNS;                     /*!< 0x00002000 Sensor Configuration Structure (clk_imo_msc domain) */
   __IM uint32_t RESERVED14[12224];
  __IOM uint32_t TRIM_CTL;                      /*!< 0x0000FF00 Trim Control */
  __IOM uint32_t CLK_IMO_TRIM1;                 /*!< 0x0000FF04 Local IMO Trim Register 1 */
  __IOM uint32_t CLK_IMO_TRIM2;                 /*!< 0x0000FF08 Local IMO Trim Register 2 */
  __IOM uint32_t CLK_IMO_TRIM3;                 /*!< 0x0000FF0C Local IMO Trim Register 3 */
  __IOM uint32_t PWR_BG_TRIM1;                  /*!< 0x0000FF10 Bandgap Trim Register 1 */
  __IOM uint32_t PWR_BG_TRIM2;                  /*!< 0x0000FF14 Bandgap Trim Register 2 */
  __IOM uint32_t PWR_BG_TRIM3;                  /*!< 0x0000FF18 Bandgap Trim Register 3 */
} MSCLP_Type;                                   /*!< Size = 65308 (0xFF1C) */


/* MSCLP_MODE.SENSE_DUTY_CTL */
#define MSCLP_MODE_SENSE_DUTY_CTL_PHASE_GAP_PH0_EN_Pos 0UL
#define MSCLP_MODE_SENSE_DUTY_CTL_PHASE_GAP_PH0_EN_Msk 0x1UL
#define MSCLP_MODE_SENSE_DUTY_CTL_PHASE_GAP_PH1_EN_Pos 1UL
#define MSCLP_MODE_SENSE_DUTY_CTL_PHASE_GAP_PH1_EN_Msk 0x2UL
#define MSCLP_MODE_SENSE_DUTY_CTL_PHASE_GAP_PH2_EN_Pos 2UL
#define MSCLP_MODE_SENSE_DUTY_CTL_PHASE_GAP_PH2_EN_Msk 0x4UL
#define MSCLP_MODE_SENSE_DUTY_CTL_PHASE_GAP_PH3_EN_Pos 3UL
#define MSCLP_MODE_SENSE_DUTY_CTL_PHASE_GAP_PH3_EN_Msk 0x8UL
#define MSCLP_MODE_SENSE_DUTY_CTL_PHASE_GAP_FS2_PH0_EN_Pos 4UL
#define MSCLP_MODE_SENSE_DUTY_CTL_PHASE_GAP_FS2_PH0_EN_Msk 0x10UL
#define MSCLP_MODE_SENSE_DUTY_CTL_PHASE_GAP_FS2_PH1_EN_Pos 5UL
#define MSCLP_MODE_SENSE_DUTY_CTL_PHASE_GAP_FS2_PH1_EN_Msk 0x20UL
#define MSCLP_MODE_SENSE_DUTY_CTL_PH_GAP_2CYCLE_EN_Pos 6UL
#define MSCLP_MODE_SENSE_DUTY_CTL_PH_GAP_2CYCLE_EN_Msk 0x40UL
#define MSCLP_MODE_SENSE_DUTY_CTL_PHASE_GAP_PH0X_EN_Pos 8UL
#define MSCLP_MODE_SENSE_DUTY_CTL_PHASE_GAP_PH0X_EN_Msk 0x100UL
#define MSCLP_MODE_SENSE_DUTY_CTL_PHASE_GAP_PH1X_EN_Pos 9UL
#define MSCLP_MODE_SENSE_DUTY_CTL_PHASE_GAP_PH1X_EN_Msk 0x200UL
#define MSCLP_MODE_SENSE_DUTY_CTL_PHX_GAP_2CYCLE_EN_Pos 10UL
#define MSCLP_MODE_SENSE_DUTY_CTL_PHX_GAP_2CYCLE_EN_Msk 0x400UL
#define MSCLP_MODE_SENSE_DUTY_CTL_PHASE_SHIFT_EN_Pos 24UL
#define MSCLP_MODE_SENSE_DUTY_CTL_PHASE_SHIFT_EN_Msk 0x1000000UL
#define MSCLP_MODE_SENSE_DUTY_CTL_PHASE_MODE_SEL_Pos 28UL
#define MSCLP_MODE_SENSE_DUTY_CTL_PHASE_MODE_SEL_Msk 0x10000000UL
/* MSCLP_MODE.SW_SEL_CDAC_FL */
#define MSCLP_MODE_SW_SEL_CDAC_FL_SW_FLTCA_Pos  0UL
#define MSCLP_MODE_SW_SEL_CDAC_FL_SW_FLTCA_Msk  0x7UL
#define MSCLP_MODE_SW_SEL_CDAC_FL_SW_FLCB_Pos   4UL
#define MSCLP_MODE_SW_SEL_CDAC_FL_SW_FLCB_Msk   0x70UL
#define MSCLP_MODE_SW_SEL_CDAC_FL_SW_FLTV_Pos   8UL
#define MSCLP_MODE_SW_SEL_CDAC_FL_SW_FLTV_Msk   0x300UL
#define MSCLP_MODE_SW_SEL_CDAC_FL_SW_FLTG_Pos   12UL
#define MSCLP_MODE_SW_SEL_CDAC_FL_SW_FLTG_Msk   0x7000UL
#define MSCLP_MODE_SW_SEL_CDAC_FL_SW_FLBV_Pos   16UL
#define MSCLP_MODE_SW_SEL_CDAC_FL_SW_FLBV_Msk   0x70000UL
#define MSCLP_MODE_SW_SEL_CDAC_FL_SW_FLBG_Pos   20UL
#define MSCLP_MODE_SW_SEL_CDAC_FL_SW_FLBG_Msk   0x700000UL
#define MSCLP_MODE_SW_SEL_CDAC_FL_ACTIVATION_MODE_Pos 31UL
#define MSCLP_MODE_SW_SEL_CDAC_FL_ACTIVATION_MODE_Msk 0x80000000UL
/* MSCLP_MODE.SW_SEL_TOP */
#define MSCLP_MODE_SW_SEL_TOP_CACB_Pos          0UL
#define MSCLP_MODE_SW_SEL_TOP_CACB_Msk          0x1UL
#define MSCLP_MODE_SW_SEL_TOP_CACC_Pos          2UL
#define MSCLP_MODE_SW_SEL_TOP_CACC_Msk          0x4UL
#define MSCLP_MODE_SW_SEL_TOP_CBCD_Pos          4UL
#define MSCLP_MODE_SW_SEL_TOP_CBCD_Msk          0x10UL
#define MSCLP_MODE_SW_SEL_TOP_AYA_CTL_Pos       8UL
#define MSCLP_MODE_SW_SEL_TOP_AYA_CTL_Msk       0x700UL
#define MSCLP_MODE_SW_SEL_TOP_AYA_EN_Pos        11UL
#define MSCLP_MODE_SW_SEL_TOP_AYA_EN_Msk        0x800UL
#define MSCLP_MODE_SW_SEL_TOP_AYB_CTL_Pos       12UL
#define MSCLP_MODE_SW_SEL_TOP_AYB_CTL_Msk       0x7000UL
#define MSCLP_MODE_SW_SEL_TOP_AYB_EN_Pos        15UL
#define MSCLP_MODE_SW_SEL_TOP_AYB_EN_Msk        0x8000UL
#define MSCLP_MODE_SW_SEL_TOP_BYB_Pos           16UL
#define MSCLP_MODE_SW_SEL_TOP_BYB_Msk           0x30000UL
#define MSCLP_MODE_SW_SEL_TOP_BGRF_Pos          20UL
#define MSCLP_MODE_SW_SEL_TOP_BGRF_Msk          0x100000UL
#define MSCLP_MODE_SW_SEL_TOP_RMF_Pos           24UL
#define MSCLP_MODE_SW_SEL_TOP_RMF_Msk           0x3000000UL
#define MSCLP_MODE_SW_SEL_TOP_MBF_Pos           31UL
#define MSCLP_MODE_SW_SEL_TOP_MBF_Msk           0x80000000UL
/* MSCLP_MODE.SW_SEL_COMP */
#define MSCLP_MODE_SW_SEL_COMP_CPCS1_Pos        0UL
#define MSCLP_MODE_SW_SEL_COMP_CPCS1_Msk        0x1UL
#define MSCLP_MODE_SW_SEL_COMP_CPCS3_Pos        2UL
#define MSCLP_MODE_SW_SEL_COMP_CPCS3_Msk        0x4UL
#define MSCLP_MODE_SW_SEL_COMP_CPMA_Pos         4UL
#define MSCLP_MODE_SW_SEL_COMP_CPMA_Msk         0x10UL
#define MSCLP_MODE_SW_SEL_COMP_CPCA_Pos         6UL
#define MSCLP_MODE_SW_SEL_COMP_CPCA_Msk         0x40UL
#define MSCLP_MODE_SW_SEL_COMP_CPCB_Pos         8UL
#define MSCLP_MODE_SW_SEL_COMP_CPCB_Msk         0x100UL
#define MSCLP_MODE_SW_SEL_COMP_CMCB_Pos         10UL
#define MSCLP_MODE_SW_SEL_COMP_CMCB_Msk         0x400UL
#define MSCLP_MODE_SW_SEL_COMP_CPF_Pos          12UL
#define MSCLP_MODE_SW_SEL_COMP_CPF_Msk          0x1000UL
#define MSCLP_MODE_SW_SEL_COMP_CMCS2_Pos        14UL
#define MSCLP_MODE_SW_SEL_COMP_CMCS2_Msk        0x4000UL
#define MSCLP_MODE_SW_SEL_COMP_CMCS4_Pos        16UL
#define MSCLP_MODE_SW_SEL_COMP_CMCS4_Msk        0x10000UL
#define MSCLP_MODE_SW_SEL_COMP_CMV_Pos          18UL
#define MSCLP_MODE_SW_SEL_COMP_CMV_Msk          0x40000UL
#define MSCLP_MODE_SW_SEL_COMP_CMG_Pos          20UL
#define MSCLP_MODE_SW_SEL_COMP_CMG_Msk          0x100000UL
#define MSCLP_MODE_SW_SEL_COMP_CMF_Pos          22UL
#define MSCLP_MODE_SW_SEL_COMP_CMF_Msk          0x400000UL
#define MSCLP_MODE_SW_SEL_COMP_HALF_WAVE_EN_Pos 31UL
#define MSCLP_MODE_SW_SEL_COMP_HALF_WAVE_EN_Msk 0x80000000UL
/* MSCLP_MODE.SW_SEL_SH */
#define MSCLP_MODE_SW_SEL_SH_SOMB_Pos           8UL
#define MSCLP_MODE_SW_SEL_SH_SOMB_Msk           0x100UL
#define MSCLP_MODE_SW_SEL_SH_CBSO_Pos           10UL
#define MSCLP_MODE_SW_SEL_SH_CBSO_Msk           0x400UL
#define MSCLP_MODE_SW_SEL_SH_SPCS1_Pos          12UL
#define MSCLP_MODE_SW_SEL_SH_SPCS1_Msk          0x1000UL
#define MSCLP_MODE_SW_SEL_SH_SPCS3_Pos          14UL
#define MSCLP_MODE_SW_SEL_SH_SPCS3_Msk          0x4000UL
#define MSCLP_MODE_SW_SEL_SH_FSP_Pos            16UL
#define MSCLP_MODE_SW_SEL_SH_FSP_Msk            0x10000UL
#define MSCLP_MODE_SW_SEL_SH_BUF_SEL_Pos        24UL
#define MSCLP_MODE_SW_SEL_SH_BUF_SEL_Msk        0xF000000UL
#define MSCLP_MODE_SW_SEL_SH_BUF_EN_Pos         31UL
#define MSCLP_MODE_SW_SEL_SH_BUF_EN_Msk         0x80000000UL
/* MSCLP_MODE.SW_SEL_CMOD1 */
#define MSCLP_MODE_SW_SEL_CMOD1_SW_AMUXA_Pos    0UL
#define MSCLP_MODE_SW_SEL_CMOD1_SW_AMUXA_Msk    0xFUL
#define MSCLP_MODE_SW_SEL_CMOD1_SW_C1CA_Pos     4UL
#define MSCLP_MODE_SW_SEL_CMOD1_SW_C1CA_Msk     0x10UL
#define MSCLP_MODE_SW_SEL_CMOD1_SW_C1CC_Pos     6UL
#define MSCLP_MODE_SW_SEL_CMOD1_SW_C1CC_Msk     0x40UL
#define MSCLP_MODE_SW_SEL_CMOD1_SW_AMUXB_Pos    8UL
#define MSCLP_MODE_SW_SEL_CMOD1_SW_AMUXB_Msk    0xF00UL
#define MSCLP_MODE_SW_SEL_CMOD1_SW_PU_Pos       16UL
#define MSCLP_MODE_SW_SEL_CMOD1_SW_PU_Msk       0xF0000UL
#define MSCLP_MODE_SW_SEL_CMOD1_SW_PD_Pos       24UL
#define MSCLP_MODE_SW_SEL_CMOD1_SW_PD_Msk       0xF000000UL
#define MSCLP_MODE_SW_SEL_CMOD1_REF_MODE_Pos    30UL
#define MSCLP_MODE_SW_SEL_CMOD1_REF_MODE_Msk    0x40000000UL
#define MSCLP_MODE_SW_SEL_CMOD1_DDRV_EN_Pos     31UL
#define MSCLP_MODE_SW_SEL_CMOD1_DDRV_EN_Msk     0x80000000UL
/* MSCLP_MODE.SW_SEL_CMOD2 */
#define MSCLP_MODE_SW_SEL_CMOD2_SW_AMUXA_Pos    0UL
#define MSCLP_MODE_SW_SEL_CMOD2_SW_AMUXA_Msk    0xFUL
#define MSCLP_MODE_SW_SEL_CMOD2_SW_AMUXB_Pos    8UL
#define MSCLP_MODE_SW_SEL_CMOD2_SW_AMUXB_Msk    0xF00UL
#define MSCLP_MODE_SW_SEL_CMOD2_SW_C2CB_Pos     12UL
#define MSCLP_MODE_SW_SEL_CMOD2_SW_C2CB_Msk     0x1000UL
#define MSCLP_MODE_SW_SEL_CMOD2_SW_C2CD_Pos     14UL
#define MSCLP_MODE_SW_SEL_CMOD2_SW_C2CD_Msk     0x4000UL
#define MSCLP_MODE_SW_SEL_CMOD2_SW_PU_Pos       16UL
#define MSCLP_MODE_SW_SEL_CMOD2_SW_PU_Msk       0xF0000UL
#define MSCLP_MODE_SW_SEL_CMOD2_SW_PD_Pos       24UL
#define MSCLP_MODE_SW_SEL_CMOD2_SW_PD_Msk       0xF000000UL
#define MSCLP_MODE_SW_SEL_CMOD2_REF_MODE_Pos    30UL
#define MSCLP_MODE_SW_SEL_CMOD2_REF_MODE_Msk    0x40000000UL
#define MSCLP_MODE_SW_SEL_CMOD2_DDRV_EN_Pos     31UL
#define MSCLP_MODE_SW_SEL_CMOD2_DDRV_EN_Msk     0x80000000UL
/* MSCLP_MODE.SW_SEL_CMOD3 */
#define MSCLP_MODE_SW_SEL_CMOD3_SW_AMUXA_Pos    0UL
#define MSCLP_MODE_SW_SEL_CMOD3_SW_AMUXA_Msk    0xFUL
#define MSCLP_MODE_SW_SEL_CMOD3_SW_C3CA_Pos     4UL
#define MSCLP_MODE_SW_SEL_CMOD3_SW_C3CA_Msk     0x10UL
#define MSCLP_MODE_SW_SEL_CMOD3_SW_C3CC_Pos     6UL
#define MSCLP_MODE_SW_SEL_CMOD3_SW_C3CC_Msk     0x40UL
#define MSCLP_MODE_SW_SEL_CMOD3_SW_AMUXB_Pos    8UL
#define MSCLP_MODE_SW_SEL_CMOD3_SW_AMUXB_Msk    0xF00UL
#define MSCLP_MODE_SW_SEL_CMOD3_SW_PU_Pos       16UL
#define MSCLP_MODE_SW_SEL_CMOD3_SW_PU_Msk       0xF0000UL
#define MSCLP_MODE_SW_SEL_CMOD3_SW_PD_Pos       24UL
#define MSCLP_MODE_SW_SEL_CMOD3_SW_PD_Msk       0xF000000UL
#define MSCLP_MODE_SW_SEL_CMOD3_REF_MODE_Pos    30UL
#define MSCLP_MODE_SW_SEL_CMOD3_REF_MODE_Msk    0x40000000UL
#define MSCLP_MODE_SW_SEL_CMOD3_DDRV_EN_Pos     31UL
#define MSCLP_MODE_SW_SEL_CMOD3_DDRV_EN_Msk     0x80000000UL
/* MSCLP_MODE.SW_SEL_CMOD4 */
#define MSCLP_MODE_SW_SEL_CMOD4_SW_AMUXA_Pos    0UL
#define MSCLP_MODE_SW_SEL_CMOD4_SW_AMUXA_Msk    0xFUL
#define MSCLP_MODE_SW_SEL_CMOD4_SW_AMUXB_Pos    8UL
#define MSCLP_MODE_SW_SEL_CMOD4_SW_AMUXB_Msk    0xF00UL
#define MSCLP_MODE_SW_SEL_CMOD4_SW_C4CB_Pos     12UL
#define MSCLP_MODE_SW_SEL_CMOD4_SW_C4CB_Msk     0x1000UL
#define MSCLP_MODE_SW_SEL_CMOD4_SW_C4CD_Pos     14UL
#define MSCLP_MODE_SW_SEL_CMOD4_SW_C4CD_Msk     0x4000UL
#define MSCLP_MODE_SW_SEL_CMOD4_SW_PU_Pos       16UL
#define MSCLP_MODE_SW_SEL_CMOD4_SW_PU_Msk       0xF0000UL
#define MSCLP_MODE_SW_SEL_CMOD4_SW_PD_Pos       24UL
#define MSCLP_MODE_SW_SEL_CMOD4_SW_PD_Msk       0xF000000UL
#define MSCLP_MODE_SW_SEL_CMOD4_REF_MODE_Pos    30UL
#define MSCLP_MODE_SW_SEL_CMOD4_REF_MODE_Msk    0x40000000UL
#define MSCLP_MODE_SW_SEL_CMOD4_DDRV_EN_Pos     31UL
#define MSCLP_MODE_SW_SEL_CMOD4_DDRV_EN_Msk     0x80000000UL


/* MSCLP_SNS.SENSOR_DATA */
#define MSCLP_SNS_SENSOR_DATA_DATA_Pos          0UL
#define MSCLP_SNS_SENSOR_DATA_DATA_Msk          0xFFFFFFFFUL
/* MSCLP_SNS.SNS_LP_AOS_SNS_CTL0 */
#define MSCLP_SNS_SNS_LP_AOS_SNS_CTL0_RC_COEFF_Pos 0UL
#define MSCLP_SNS_SNS_LP_AOS_SNS_CTL0_RC_COEFF_Msk 0xFUL
#define MSCLP_SNS_SNS_LP_AOS_SNS_CTL0_BL_COEFF_SLOW_Pos 4UL
#define MSCLP_SNS_SNS_LP_AOS_SNS_CTL0_BL_COEFF_SLOW_Msk 0xF0UL
#define MSCLP_SNS_SNS_LP_AOS_SNS_CTL0_BL_COEFF_FAST_Pos 8UL
#define MSCLP_SNS_SNS_LP_AOS_SNS_CTL0_BL_COEFF_FAST_Msk 0xF00UL
#define MSCLP_SNS_SNS_LP_AOS_SNS_CTL0_LOW_BL_RESET_Pos 16UL
#define MSCLP_SNS_SNS_LP_AOS_SNS_CTL0_LOW_BL_RESET_Msk 0x3F0000UL
#define MSCLP_SNS_SNS_LP_AOS_SNS_CTL0_BL_UPDATE_DELAY_Pos 24UL
#define MSCLP_SNS_SNS_LP_AOS_SNS_CTL0_BL_UPDATE_DELAY_Msk 0xFF000000UL
/* MSCLP_SNS.SNS_LP_AOS_SNS_CTL1 */
#define MSCLP_SNS_SNS_LP_AOS_SNS_CTL1_NOISE_THR_Pos 0UL
#define MSCLP_SNS_SNS_LP_AOS_SNS_CTL1_NOISE_THR_Msk 0xFFFFUL
#define MSCLP_SNS_SNS_LP_AOS_SNS_CTL1_NOISE_THR_NEG_Pos 16UL
#define MSCLP_SNS_SNS_LP_AOS_SNS_CTL1_NOISE_THR_NEG_Msk 0xFFFF0000UL
/* MSCLP_SNS.SNS_LP_AOS_SNS_CTL2 */
#define MSCLP_SNS_SNS_LP_AOS_SNS_CTL2_SIGNAL_THR_Pos 0UL
#define MSCLP_SNS_SNS_LP_AOS_SNS_CTL2_SIGNAL_THR_Msk 0xFFFFUL
#define MSCLP_SNS_SNS_LP_AOS_SNS_CTL2_DEBOUNCE_THRESHOLD_Pos 16UL
#define MSCLP_SNS_SNS_LP_AOS_SNS_CTL2_DEBOUNCE_THRESHOLD_Msk 0x70000UL
#define MSCLP_SNS_SNS_LP_AOS_SNS_CTL2_SIGNAL_TYPE_Pos 24UL
#define MSCLP_SNS_SNS_LP_AOS_SNS_CTL2_SIGNAL_TYPE_Msk 0x1000000UL
/* MSCLP_SNS.SNS_LP_AOS_SNS_CTL3 */
#define MSCLP_SNS_SNS_LP_AOS_SNS_CTL3_SNS_FRC_SCALED_Pos 0UL
#define MSCLP_SNS_SNS_LP_AOS_SNS_CTL3_SNS_FRC_SCALED_Msk 0xFFFFFFUL
#define MSCLP_SNS_SNS_LP_AOS_SNS_CTL3_BL_UPDATE_TMR_Pos 24UL
#define MSCLP_SNS_SNS_LP_AOS_SNS_CTL3_BL_UPDATE_TMR_Msk 0xFF000000UL
/* MSCLP_SNS.SNS_LP_AOS_SNS_CTL4 */
#define MSCLP_SNS_SNS_LP_AOS_SNS_CTL4_SNS_BL_Pos 0UL
#define MSCLP_SNS_SNS_LP_AOS_SNS_CTL4_SNS_BL_Msk 0xFFFFUL
#define MSCLP_SNS_SNS_LP_AOS_SNS_CTL4_BL_RESET_TMR_Pos 16UL
#define MSCLP_SNS_SNS_LP_AOS_SNS_CTL4_BL_RESET_TMR_Msk 0x3F0000UL
#define MSCLP_SNS_SNS_LP_AOS_SNS_CTL4_SIG_DEBOUNCE_TMR_Pos 24UL
#define MSCLP_SNS_SNS_LP_AOS_SNS_CTL4_SIG_DEBOUNCE_TMR_Msk 0x7000000UL
/* MSCLP_SNS.SNS_SW_SEL_CSW_HI_MASK2 */
#define MSCLP_SNS_SNS_SW_SEL_CSW_HI_MASK2_FUNC_MASK_Pos 0UL
#define MSCLP_SNS_SNS_SW_SEL_CSW_HI_MASK2_FUNC_MASK_Msk 0xFFFFFFFFUL
/* MSCLP_SNS.SNS_SW_SEL_CSW_HI_MASK1 */
#define MSCLP_SNS_SNS_SW_SEL_CSW_HI_MASK1_FUNC_MASK_Pos 0UL
#define MSCLP_SNS_SNS_SW_SEL_CSW_HI_MASK1_FUNC_MASK_Msk 0xFFFFFFFFUL
/* MSCLP_SNS.SNS_SW_SEL_CSW_HI_MASK0 */
#define MSCLP_SNS_SNS_SW_SEL_CSW_HI_MASK0_FUNC_MASK_Pos 0UL
#define MSCLP_SNS_SNS_SW_SEL_CSW_HI_MASK0_FUNC_MASK_Msk 0xFFFFFFFFUL
/* MSCLP_SNS.SNS_SW_SEL_CSW_LO_MASK2 */
#define MSCLP_SNS_SNS_SW_SEL_CSW_LO_MASK2_FUNC_MASK_Pos 0UL
#define MSCLP_SNS_SNS_SW_SEL_CSW_LO_MASK2_FUNC_MASK_Msk 0xFFFFFFFFUL
/* MSCLP_SNS.SNS_SW_SEL_CSW_LO_MASK1 */
#define MSCLP_SNS_SNS_SW_SEL_CSW_LO_MASK1_FUNC_MASK_Pos 0UL
#define MSCLP_SNS_SNS_SW_SEL_CSW_LO_MASK1_FUNC_MASK_Msk 0xFFFFFFFFUL
/* MSCLP_SNS.SNS_SW_SEL_CSW_LO_MASK0 */
#define MSCLP_SNS_SNS_SW_SEL_CSW_LO_MASK0_FUNC_MASK_Pos 0UL
#define MSCLP_SNS_SNS_SW_SEL_CSW_LO_MASK0_FUNC_MASK_Msk 0xFFFFFFFFUL
/* MSCLP_SNS.SNS_SCAN_CTL */
#define MSCLP_SNS_SNS_SCAN_CTL_NUM_SUB_CONVS_Pos 0UL
#define MSCLP_SNS_SNS_SCAN_CTL_NUM_SUB_CONVS_Msk 0x3FFFUL
#define MSCLP_SNS_SNS_SCAN_CTL_NUM_CONV_Pos     14UL
#define MSCLP_SNS_SNS_SCAN_CTL_NUM_CONV_Msk     0x4000UL
#define MSCLP_SNS_SNS_SCAN_CTL_INIT_BYPASS_Pos  15UL
#define MSCLP_SNS_SNS_SCAN_CTL_INIT_BYPASS_Msk  0x8000UL
#define MSCLP_SNS_SNS_SCAN_CTL_COMP_DIV_Pos     16UL
#define MSCLP_SNS_SNS_SCAN_CTL_COMP_DIV_Msk     0xFFF0000UL
#define MSCLP_SNS_SNS_SCAN_CTL_CIC2_SHIFT_Pos   28UL
#define MSCLP_SNS_SNS_SCAN_CTL_CIC2_SHIFT_Msk   0xF0000000UL
/* MSCLP_SNS.SNS_CDAC_CTL */
#define MSCLP_SNS_SNS_CDAC_CTL_SEL_RE_Pos       0UL
#define MSCLP_SNS_SNS_CDAC_CTL_SEL_RE_Msk       0xFFUL
#define MSCLP_SNS_SNS_CDAC_CTL_SEL_CO_Pos       8UL
#define MSCLP_SNS_SNS_CDAC_CTL_SEL_CO_Msk       0xFF00UL
#define MSCLP_SNS_SNS_CDAC_CTL_SEL_CF_Pos       16UL
#define MSCLP_SNS_SNS_CDAC_CTL_SEL_CF_Msk       0x1F0000UL
#define MSCLP_SNS_SNS_CDAC_CTL_FINE_MODE_Pos    21UL
#define MSCLP_SNS_SNS_CDAC_CTL_FINE_MODE_Msk    0x200000UL
#define MSCLP_SNS_SNS_CDAC_CTL_CLOCK_REF_RATE_Pos 22UL
#define MSCLP_SNS_SNS_CDAC_CTL_CLOCK_REF_RATE_Msk 0x400000UL
#define MSCLP_SNS_SNS_CDAC_CTL_FL_MODE_Pos      23UL
#define MSCLP_SNS_SNS_CDAC_CTL_FL_MODE_Msk      0x1800000UL
#define MSCLP_SNS_SNS_CDAC_CTL_COMP_BLANKING_EN_Pos 26UL
#define MSCLP_SNS_SNS_CDAC_CTL_COMP_BLANKING_EN_Msk 0x4000000UL
#define MSCLP_SNS_SNS_CDAC_CTL_LFSR_SCALE_FL_Pos 28UL
#define MSCLP_SNS_SNS_CDAC_CTL_LFSR_SCALE_FL_Msk 0x70000000UL
#define MSCLP_SNS_SNS_CDAC_CTL_LFSR_SCALE_TYPE_FL_Pos 31UL
#define MSCLP_SNS_SNS_CDAC_CTL_LFSR_SCALE_TYPE_FL_Msk 0x80000000UL
/* MSCLP_SNS.SNS_CTL */
#define MSCLP_SNS_SNS_CTL_START_SCAN_Pos        0UL
#define MSCLP_SNS_SNS_CTL_START_SCAN_Msk        0x1UL
#define MSCLP_SNS_SNS_CTL_VALID_Pos             1UL
#define MSCLP_SNS_SNS_CTL_VALID_Msk             0x2UL
#define MSCLP_SNS_SNS_CTL_LAST_Pos              2UL
#define MSCLP_SNS_SNS_CTL_LAST_Msk              0x4UL
#define MSCLP_SNS_SNS_CTL_MULTI_CH_MODE_Pos     4UL
#define MSCLP_SNS_SNS_CTL_MULTI_CH_MODE_Msk     0x30UL
#define MSCLP_SNS_SNS_CTL_SENSE_MODE_SEL_Pos    6UL
#define MSCLP_SNS_SNS_CTL_SENSE_MODE_SEL_Msk    0xC0UL
#define MSCLP_SNS_SNS_CTL_DECIM_RATE_Pos        8UL
#define MSCLP_SNS_SNS_CTL_DECIM_RATE_Msk        0xFF00UL
#define MSCLP_SNS_SNS_CTL_SENSE_DIV_Pos         16UL
#define MSCLP_SNS_SNS_CTL_SENSE_DIV_Msk         0xFFF0000UL
#define MSCLP_SNS_SNS_CTL_LFSR_MODE_Pos         28UL
#define MSCLP_SNS_SNS_CTL_LFSR_MODE_Msk         0x30000000UL
#define MSCLP_SNS_SNS_CTL_LFSR_BITS_Pos         30UL
#define MSCLP_SNS_SNS_CTL_LFSR_BITS_Msk         0xC0000000UL
/* MSCLP_SNS.RESULT_FIFO_RD */
#define MSCLP_SNS_RESULT_FIFO_RD_RAW_COUNT_Pos  0UL
#define MSCLP_SNS_RESULT_FIFO_RD_RAW_COUNT_Msk  0xFFFFUL
#define MSCLP_SNS_RESULT_FIFO_RD_OVERFLOW_Pos   16UL
#define MSCLP_SNS_RESULT_FIFO_RD_OVERFLOW_Msk   0x10000UL
#define MSCLP_SNS_RESULT_FIFO_RD_CIC2_ACC_OVERFLOW_Pos 17UL
#define MSCLP_SNS_RESULT_FIFO_RD_CIC2_ACC_OVERFLOW_Msk 0x20000UL
#define MSCLP_SNS_RESULT_FIFO_RD_CIC2_SUBSAMPLE_COUNT_OVERFLOW_Pos 18UL
#define MSCLP_SNS_RESULT_FIFO_RD_CIC2_SUBSAMPLE_COUNT_OVERFLOW_Msk 0x40000UL
#define MSCLP_SNS_RESULT_FIFO_RD_RESAMPLE_COUNT_Pos 20UL
#define MSCLP_SNS_RESULT_FIFO_RD_RESAMPLE_COUNT_Msk 0x700000UL
#define MSCLP_SNS_RESULT_FIFO_RD_BAD_CONV_COUNT_Pos 24UL
#define MSCLP_SNS_RESULT_FIFO_RD_BAD_CONV_COUNT_Msk 0x3000000UL
/* MSCLP_SNS.STATUS1 */
#define MSCLP_SNS_STATUS1_RAW_COUNT_Pos         0UL
#define MSCLP_SNS_STATUS1_RAW_COUNT_Msk         0xFFFFUL
#define MSCLP_SNS_STATUS1_RAW_COUNT_POS_Pos     16UL
#define MSCLP_SNS_STATUS1_RAW_COUNT_POS_Msk     0xFFFF0000UL
/* MSCLP_SNS.STATUS2 */
#define MSCLP_SNS_STATUS2_DEBUG_CONV_COUNT_Pos  0UL
#define MSCLP_SNS_STATUS2_DEBUG_CONV_COUNT_Msk  0xFFFFUL
/* MSCLP_SNS.STATUS3 */
#define MSCLP_SNS_STATUS3_NUM_SUB_CONVS_Pos     0UL
#define MSCLP_SNS_STATUS3_NUM_SUB_CONVS_Msk     0x3FFFUL
#define MSCLP_SNS_STATUS3_SEQ_STATE_Pos         16UL
#define MSCLP_SNS_STATUS3_SEQ_STATE_Msk         0x1F0000UL
#define MSCLP_SNS_STATUS3_FS_CLOCK_Pos          24UL
#define MSCLP_SNS_STATUS3_FS_CLOCK_Msk          0x1000000UL
#define MSCLP_SNS_STATUS3_MSC_CMP_OUT_Pos       28UL
#define MSCLP_SNS_STATUS3_MSC_CMP_OUT_Msk       0x10000000UL
/* MSCLP_SNS.STATUS4 */
#define MSCLP_SNS_STATUS4_NUM_CIC2_SUB_SAMPLES_Pos 0UL
#define MSCLP_SNS_STATUS4_NUM_CIC2_SUB_SAMPLES_Msk 0x1FFUL
/* MSCLP_SNS.RESULT_FIFO_STATUS */
#define MSCLP_SNS_RESULT_FIFO_STATUS_USED_Pos   0UL
#define MSCLP_SNS_RESULT_FIFO_STATUS_USED_Msk   0x7FFUL
#define MSCLP_SNS_RESULT_FIFO_STATUS_SCAN_IDX_Pos 16UL
#define MSCLP_SNS_RESULT_FIFO_STATUS_SCAN_IDX_Msk 0x3FF0000UL
/* MSCLP_SNS.RESULT_FIFO_STATUS2 */
#define MSCLP_SNS_RESULT_FIFO_STATUS2_WR_PTR_Pos 0UL
#define MSCLP_SNS_RESULT_FIFO_STATUS2_WR_PTR_Msk 0x3FFUL
#define MSCLP_SNS_RESULT_FIFO_STATUS2_RD_PTR_Pos 16UL
#define MSCLP_SNS_RESULT_FIFO_STATUS2_RD_PTR_Msk 0x3FF0000UL
#define MSCLP_SNS_RESULT_FIFO_STATUS2_FIFO_UNDERFLOW_Pos 30UL
#define MSCLP_SNS_RESULT_FIFO_STATUS2_FIFO_UNDERFLOW_Msk 0x40000000UL
#define MSCLP_SNS_RESULT_FIFO_STATUS2_FIFO_OVERFLOW_Pos 31UL
#define MSCLP_SNS_RESULT_FIFO_STATUS2_FIFO_OVERFLOW_Msk 0x80000000UL
/* MSCLP_SNS.CE_STATUS */
#define MSCLP_SNS_CE_STATUS_BL_DELTA_Pos        0UL
#define MSCLP_SNS_CE_STATUS_BL_DELTA_Msk        0x1FFFFUL
#define MSCLP_SNS_CE_STATUS_BL_STATE_Pos        20UL
#define MSCLP_SNS_CE_STATUS_BL_STATE_Msk        0x300000UL
#define MSCLP_SNS_CE_STATUS_SIG_STATE_Pos       24UL
#define MSCLP_SNS_CE_STATUS_SIG_STATE_Msk       0x1000000UL
/* MSCLP_SNS.BRIDGE_STATUS */
#define MSCLP_SNS_BRIDGE_STATUS_READY_Pos       0UL
#define MSCLP_SNS_BRIDGE_STATUS_READY_Msk       0x1UL
/* MSCLP_SNS.FRAME_CMD */
#define MSCLP_SNS_FRAME_CMD_START_FRAME_Pos     0UL
#define MSCLP_SNS_FRAME_CMD_START_FRAME_Msk     0x1UL
/* MSCLP_SNS.CE_CMD */
#define MSCLP_SNS_CE_CMD_TEST_RAW_COUNT_Pos     0UL
#define MSCLP_SNS_CE_CMD_TEST_RAW_COUNT_Msk     0xFFFFUL
#define MSCLP_SNS_CE_CMD_CE_START_Pos           16UL
#define MSCLP_SNS_CE_CMD_CE_START_Msk           0x10000UL
/* MSCLP_SNS.FIFO_CMD */
#define MSCLP_SNS_FIFO_CMD_FIFO_RESET_Pos       0UL
#define MSCLP_SNS_FIFO_CMD_FIFO_RESET_Msk       0x1UL
/* MSCLP_SNS.CE_INIT_CTL */
#define MSCLP_SNS_CE_INIT_CTL_SENSOR_INIT_Pos   0UL
#define MSCLP_SNS_CE_INIT_CTL_SENSOR_INIT_Msk   0x1UL


/* MSCLP.CTL */
#define MSCLP_CTL_SENSE_EN_Pos                  0UL
#define MSCLP_CTL_SENSE_EN_Msk                  0x1UL
#define MSCLP_CTL_MSCCMP_EN_Pos                 4UL
#define MSCLP_CTL_MSCCMP_EN_Msk                 0x10UL
#define MSCLP_CTL_CLK_SYNC_EN_Pos               8UL
#define MSCLP_CTL_CLK_SYNC_EN_Msk               0x100UL
#define MSCLP_CTL_EXT_FRAME_START_MODE_Pos      10UL
#define MSCLP_CTL_EXT_FRAME_START_MODE_Msk      0xC00UL
#define MSCLP_CTL_CFG_OFFSET_Pos                12UL
#define MSCLP_CTL_CFG_OFFSET_Msk                0xF000UL
#define MSCLP_CTL_OPERATING_MODE_Pos            16UL
#define MSCLP_CTL_OPERATING_MODE_Msk            0x30000UL
#define MSCLP_CTL_BUF_MODE_Pos                  20UL
#define MSCLP_CTL_BUF_MODE_Msk                  0x100000UL
#define MSCLP_CTL_CLK_MSC_RATIO_Pos             24UL
#define MSCLP_CTL_CLK_MSC_RATIO_Msk             0x1000000UL
#define MSCLP_CTL_DEBUG_EN_Pos                  26UL
#define MSCLP_CTL_DEBUG_EN_Msk                  0x4000000UL
#define MSCLP_CTL_ENABLED_Pos                   31UL
#define MSCLP_CTL_ENABLED_Msk                   0x80000000UL
/* MSCLP.SPARE */
#define MSCLP_SPARE_SPARE_Pos                   0UL
#define MSCLP_SPARE_SPARE_Msk                   0x3FUL
/* MSCLP.SCAN_CTL1 */
#define MSCLP_SCAN_CTL1_NUM_AUTO_RESAMPLE_Pos   0UL
#define MSCLP_SCAN_CTL1_NUM_AUTO_RESAMPLE_Msk   0x7UL
#define MSCLP_SCAN_CTL1_RESCAN_DEBUG_MODE_Pos   3UL
#define MSCLP_SCAN_CTL1_RESCAN_DEBUG_MODE_Msk   0x8UL
#define MSCLP_SCAN_CTL1_NUM_SAMPLES_Pos         4UL
#define MSCLP_SCAN_CTL1_NUM_SAMPLES_Msk         0x30UL
#define MSCLP_SCAN_CTL1_RAW_COUNT_MODE_Pos      8UL
#define MSCLP_SCAN_CTL1_RAW_COUNT_MODE_Msk      0x100UL
#define MSCLP_SCAN_CTL1_DEBUG_CONV_PH_SEL_Pos   12UL
#define MSCLP_SCAN_CTL1_DEBUG_CONV_PH_SEL_Msk   0x1000UL
#define MSCLP_SCAN_CTL1_FRAME_RES_START_ADDR_Pos 16UL
#define MSCLP_SCAN_CTL1_FRAME_RES_START_ADDR_Msk 0x3FF0000UL
#define MSCLP_SCAN_CTL1_RC_STORE_EN_Pos         28UL
#define MSCLP_SCAN_CTL1_RC_STORE_EN_Msk         0x10000000UL
#define MSCLP_SCAN_CTL1_RC_STORE_MODE_Pos       30UL
#define MSCLP_SCAN_CTL1_RC_STORE_MODE_Msk       0x40000000UL
/* MSCLP.SCAN_CTL2 */
#define MSCLP_SCAN_CTL2_NUM_EPI_KREF_DELAY_PRS_Pos 0UL
#define MSCLP_SCAN_CTL2_NUM_EPI_KREF_DELAY_PRS_Msk 0xFFUL
#define MSCLP_SCAN_CTL2_NUM_EPI_KREF_DELAY_Pos  8UL
#define MSCLP_SCAN_CTL2_NUM_EPI_KREF_DELAY_Msk  0xF00UL
#define MSCLP_SCAN_CTL2_CHOP_POL_Pos            12UL
#define MSCLP_SCAN_CTL2_CHOP_POL_Msk            0x1000UL
#define MSCLP_SCAN_CTL2_FRAME_CFG_START_ADDR_Pos 16UL
#define MSCLP_SCAN_CTL2_FRAME_CFG_START_ADDR_Msk 0x3FF0000UL
#define MSCLP_SCAN_CTL2_EXT_REF_CLK_EN_Pos      28UL
#define MSCLP_SCAN_CTL2_EXT_REF_CLK_EN_Msk      0x10000000UL
#define MSCLP_SCAN_CTL2_INFINITE_SCAN_MODE_Pos  30UL
#define MSCLP_SCAN_CTL2_INFINITE_SCAN_MODE_Msk  0x40000000UL
/* MSCLP.INIT_CTL1 */
#define MSCLP_INIT_CTL1_NUM_INIT_CMOD_12_RAIL_CYCLES_Pos 0UL
#define MSCLP_INIT_CTL1_NUM_INIT_CMOD_12_RAIL_CYCLES_Msk 0xFFFUL
#define MSCLP_INIT_CTL1_NUM_INIT_CMOD_12_SHORT_CYCLES_Pos 16UL
#define MSCLP_INIT_CTL1_NUM_INIT_CMOD_12_SHORT_CYCLES_Msk 0xFFF0000UL
#define MSCLP_INIT_CTL1_PER_SAMPLE_Pos          28UL
#define MSCLP_INIT_CTL1_PER_SAMPLE_Msk          0x10000000UL
/* MSCLP.INIT_CTL2 */
#define MSCLP_INIT_CTL2_NUM_INIT_CMOD_34_RAIL_CYCLES_Pos 0UL
#define MSCLP_INIT_CTL2_NUM_INIT_CMOD_34_RAIL_CYCLES_Msk 0xFFFUL
#define MSCLP_INIT_CTL2_NUM_INIT_CMOD_34_SHORT_CYCLES_Pos 16UL
#define MSCLP_INIT_CTL2_NUM_INIT_CMOD_34_SHORT_CYCLES_Msk 0xFFF0000UL
/* MSCLP.INIT_CTL3 */
#define MSCLP_INIT_CTL3_NUM_PRO_OFFSET_CYCLES_Pos 0UL
#define MSCLP_INIT_CTL3_NUM_PRO_OFFSET_CYCLES_Msk 0xFFUL
#define MSCLP_INIT_CTL3_NUM_PRO_OFFSET_TRIPS_Pos 8UL
#define MSCLP_INIT_CTL3_NUM_PRO_OFFSET_TRIPS_Msk 0x300UL
#define MSCLP_INIT_CTL3_CMOD_SEL_Pos            10UL
#define MSCLP_INIT_CTL3_CMOD_SEL_Msk            0xC00UL
#define MSCLP_INIT_CTL3_INIT_MODE_Pos           15UL
#define MSCLP_INIT_CTL3_INIT_MODE_Msk           0x8000UL
/* MSCLP.INIT_CTL4 */
#define MSCLP_INIT_CTL4_NUM_PRO_DUMMY_SUB_CONVS_Pos 0UL
#define MSCLP_INIT_CTL4_NUM_PRO_DUMMY_SUB_CONVS_Msk 0xFFUL
#define MSCLP_INIT_CTL4_NUM_PRO_WAIT_KREF_DELAY_PRS_Pos 8UL
#define MSCLP_INIT_CTL4_NUM_PRO_WAIT_KREF_DELAY_PRS_Msk 0x1F00UL
#define MSCLP_INIT_CTL4_NUM_PRO_WAIT_KREF_DELAY_Pos 16UL
#define MSCLP_INIT_CTL4_NUM_PRO_WAIT_KREF_DELAY_Msk 0xF0000UL
#define MSCLP_INIT_CTL4_PRO_BYPASS_Pos          24UL
#define MSCLP_INIT_CTL4_PRO_BYPASS_Msk          0x1000000UL
/* MSCLP.SENSE_DUTY_CTL */
#define MSCLP_SENSE_DUTY_CTL_PHASE_WIDTH_Pos    0UL
#define MSCLP_SENSE_DUTY_CTL_PHASE_WIDTH_Msk    0xFFFUL
#define MSCLP_SENSE_DUTY_CTL_PHASE_SHIFT_CYCLES_Pos 16UL
#define MSCLP_SENSE_DUTY_CTL_PHASE_SHIFT_CYCLES_Msk 0x3FF0000UL
#define MSCLP_SENSE_DUTY_CTL_PHASE_WIDTH_SEL_Pos 27UL
#define MSCLP_SENSE_DUTY_CTL_PHASE_WIDTH_SEL_Msk 0x8000000UL
/* MSCLP.SENSE_PERIOD_CTL */
#define MSCLP_SENSE_PERIOD_CTL_LFSR_POLY_Pos    0UL
#define MSCLP_SENSE_PERIOD_CTL_LFSR_POLY_Msk    0xFFFUL
#define MSCLP_SENSE_PERIOD_CTL_LFSR_SCALE_Pos   16UL
#define MSCLP_SENSE_PERIOD_CTL_LFSR_SCALE_Msk   0xF0000UL
/* MSCLP.FILTER_CTL */
#define MSCLP_FILTER_CTL_BIT_FORMAT_Pos         16UL
#define MSCLP_FILTER_CTL_BIT_FORMAT_Msk         0x10000UL
#define MSCLP_FILTER_CTL_FILTER_MODE_Pos        24UL
#define MSCLP_FILTER_CTL_FILTER_MODE_Msk        0x1000000UL
/* MSCLP.CCOMP_CDAC_CTL */
#define MSCLP_CCOMP_CDAC_CTL_SEL_CO_PRO_OFFSET_Pos 8UL
#define MSCLP_CCOMP_CDAC_CTL_SEL_CO_PRO_OFFSET_Msk 0xFF00UL
#define MSCLP_CCOMP_CDAC_CTL_COMP_BLANKING_MODE_Pos 24UL
#define MSCLP_CCOMP_CDAC_CTL_COMP_BLANKING_MODE_Msk 0x1000000UL
#define MSCLP_CCOMP_CDAC_CTL_EPILOGUE_EN_Pos    31UL
#define MSCLP_CCOMP_CDAC_CTL_EPILOGUE_EN_Msk    0x80000000UL
/* MSCLP.DITHER_CDAC_CTL */
#define MSCLP_DITHER_CDAC_CTL_SEL_FL_Pos        0UL
#define MSCLP_DITHER_CDAC_CTL_SEL_FL_Msk        0xFFUL
#define MSCLP_DITHER_CDAC_CTL_LFSR_POLY_FL_Pos  16UL
#define MSCLP_DITHER_CDAC_CTL_LFSR_POLY_FL_Msk  0xFF0000UL
/* MSCLP.MSCCMP_CTL */
#define MSCLP_MSCCMP_CTL_PWR_Pos                0UL
#define MSCLP_MSCCMP_CTL_PWR_Msk                0x3UL
#define MSCLP_MSCCMP_CTL_FILT_Pos               8UL
#define MSCLP_MSCCMP_CTL_FILT_Msk               0x300UL
/* MSCLP.OBS_CTL */
#define MSCLP_OBS_CTL_OBSERVE0_Pos              0UL
#define MSCLP_OBS_CTL_OBSERVE0_Msk              0xFUL
#define MSCLP_OBS_CTL_OBSERVE1_Pos              8UL
#define MSCLP_OBS_CTL_OBSERVE1_Msk              0xF00UL
#define MSCLP_OBS_CTL_OBSERVE2_Pos              16UL
#define MSCLP_OBS_CTL_OBSERVE2_Msk              0xF0000UL
#define MSCLP_OBS_CTL_OBSERVE3_Pos              24UL
#define MSCLP_OBS_CTL_OBSERVE3_Msk              0xF000000UL
/* MSCLP.AOS_CTL */
#define MSCLP_AOS_CTL_WAKEUP_TIMER_Pos          0UL
#define MSCLP_AOS_CTL_WAKEUP_TIMER_Msk          0xFFFFUL
#define MSCLP_AOS_CTL_FR_TIMEOUT_INTERVAL_Pos   16UL
#define MSCLP_AOS_CTL_FR_TIMEOUT_INTERVAL_Msk   0x3FFF0000UL
#define MSCLP_AOS_CTL_STOP_ON_SD_Pos            30UL
#define MSCLP_AOS_CTL_STOP_ON_SD_Msk            0x40000000UL
#define MSCLP_AOS_CTL_MRSS_PWR_CYCLE_EN_Pos     31UL
#define MSCLP_AOS_CTL_MRSS_PWR_CYCLE_EN_Msk     0x80000000UL
/* MSCLP.CE_CTL */
#define MSCLP_CE_CTL_RCF_EN_Pos                 0UL
#define MSCLP_CE_CTL_RCF_EN_Msk                 0x1UL
#define MSCLP_CE_CTL_BLSD_EN_Pos                8UL
#define MSCLP_CE_CTL_BLSD_EN_Msk                0x100UL
#define MSCLP_CE_CTL_CE_TEST_MODE_Pos           24UL
#define MSCLP_CE_CTL_CE_TEST_MODE_Msk           0x1000000UL
#define MSCLP_CE_CTL_ENABLED_Pos                31UL
#define MSCLP_CE_CTL_ENABLED_Msk                0x80000000UL
/* MSCLP.PUMP_CTL */
#define MSCLP_PUMP_CTL_PUMP_MODE_Pos            0UL
#define MSCLP_PUMP_CTL_PUMP_MODE_Msk            0x1UL
/* MSCLP.IMO_CTL */
#define MSCLP_IMO_CTL_FREQ_Pos                  0UL
#define MSCLP_IMO_CTL_FREQ_Msk                  0x7UL
#define MSCLP_IMO_CTL_CLOCK_SYNC_DIV_Pos        8UL
#define MSCLP_IMO_CTL_CLOCK_SYNC_DIV_Msk        0x700UL
#define MSCLP_IMO_CTL_CLOCK_MSC_DIV_Pos         16UL
#define MSCLP_IMO_CTL_CLOCK_MSC_DIV_Msk         0x3FF0000UL
/* MSCLP.INTR */
#define MSCLP_INTR_SUB_SAMPLE_Pos               0UL
#define MSCLP_INTR_SUB_SAMPLE_Msk               0x1UL
#define MSCLP_INTR_SAMPLE_Pos                   4UL
#define MSCLP_INTR_SAMPLE_Msk                   0x10UL
#define MSCLP_INTR_SCAN_Pos                     8UL
#define MSCLP_INTR_SCAN_Msk                     0x100UL
#define MSCLP_INTR_INIT_Pos                     12UL
#define MSCLP_INTR_INIT_Msk                     0x1000UL
#define MSCLP_INTR_FRAME_Pos                    16UL
#define MSCLP_INTR_FRAME_Msk                    0x10000UL
#define MSCLP_INTR_CONFIG_REQ_Pos               24UL
#define MSCLP_INTR_CONFIG_REQ_Msk               0x1000000UL
#define MSCLP_INTR_FIFO_UNDERFLOW_Pos           30UL
#define MSCLP_INTR_FIFO_UNDERFLOW_Msk           0x40000000UL
#define MSCLP_INTR_FIFO_OVERFLOW_Pos            31UL
#define MSCLP_INTR_FIFO_OVERFLOW_Msk            0x80000000UL
/* MSCLP.INTR_SET */
#define MSCLP_INTR_SET_SUB_SAMPLE_Pos           0UL
#define MSCLP_INTR_SET_SUB_SAMPLE_Msk           0x1UL
#define MSCLP_INTR_SET_SAMPLE_Pos               4UL
#define MSCLP_INTR_SET_SAMPLE_Msk               0x10UL
#define MSCLP_INTR_SET_SCAN_Pos                 8UL
#define MSCLP_INTR_SET_SCAN_Msk                 0x100UL
#define MSCLP_INTR_SET_INIT_Pos                 12UL
#define MSCLP_INTR_SET_INIT_Msk                 0x1000UL
#define MSCLP_INTR_SET_FRAME_Pos                16UL
#define MSCLP_INTR_SET_FRAME_Msk                0x10000UL
#define MSCLP_INTR_SET_CONFIG_REQ_Pos           24UL
#define MSCLP_INTR_SET_CONFIG_REQ_Msk           0x1000000UL
#define MSCLP_INTR_SET_FIFO_UNDERFLOW_Pos       30UL
#define MSCLP_INTR_SET_FIFO_UNDERFLOW_Msk       0x40000000UL
#define MSCLP_INTR_SET_FIFO_OVERFLOW_Pos        31UL
#define MSCLP_INTR_SET_FIFO_OVERFLOW_Msk        0x80000000UL
/* MSCLP.INTR_MASK */
#define MSCLP_INTR_MASK_SUB_SAMPLE_Pos          0UL
#define MSCLP_INTR_MASK_SUB_SAMPLE_Msk          0x1UL
#define MSCLP_INTR_MASK_SAMPLE_Pos              4UL
#define MSCLP_INTR_MASK_SAMPLE_Msk              0x10UL
#define MSCLP_INTR_MASK_SCAN_Pos                8UL
#define MSCLP_INTR_MASK_SCAN_Msk                0x100UL
#define MSCLP_INTR_MASK_INIT_Pos                12UL
#define MSCLP_INTR_MASK_INIT_Msk                0x1000UL
#define MSCLP_INTR_MASK_FRAME_Pos               16UL
#define MSCLP_INTR_MASK_FRAME_Msk               0x10000UL
#define MSCLP_INTR_MASK_CONFIG_REQ_Pos          24UL
#define MSCLP_INTR_MASK_CONFIG_REQ_Msk          0x1000000UL
#define MSCLP_INTR_MASK_FIFO_UNDERFLOW_Pos      30UL
#define MSCLP_INTR_MASK_FIFO_UNDERFLOW_Msk      0x40000000UL
#define MSCLP_INTR_MASK_FIFO_OVERFLOW_Pos       31UL
#define MSCLP_INTR_MASK_FIFO_OVERFLOW_Msk       0x80000000UL
/* MSCLP.INTR_MASKED */
#define MSCLP_INTR_MASKED_SUB_SAMPLE_Pos        0UL
#define MSCLP_INTR_MASKED_SUB_SAMPLE_Msk        0x1UL
#define MSCLP_INTR_MASKED_SAMPLE_Pos            4UL
#define MSCLP_INTR_MASKED_SAMPLE_Msk            0x10UL
#define MSCLP_INTR_MASKED_SCAN_Pos              8UL
#define MSCLP_INTR_MASKED_SCAN_Msk              0x100UL
#define MSCLP_INTR_MASKED_INIT_Pos              12UL
#define MSCLP_INTR_MASKED_INIT_Msk              0x1000UL
#define MSCLP_INTR_MASKED_FRAME_Pos             16UL
#define MSCLP_INTR_MASKED_FRAME_Msk             0x10000UL
#define MSCLP_INTR_MASKED_CONFIG_REQ_Pos        24UL
#define MSCLP_INTR_MASKED_CONFIG_REQ_Msk        0x1000000UL
#define MSCLP_INTR_MASKED_FIFO_UNDERFLOW_Pos    30UL
#define MSCLP_INTR_MASKED_FIFO_UNDERFLOW_Msk    0x40000000UL
#define MSCLP_INTR_MASKED_FIFO_OVERFLOW_Pos     31UL
#define MSCLP_INTR_MASKED_FIFO_OVERFLOW_Msk     0x80000000UL
/* MSCLP.INTR_LP */
#define MSCLP_INTR_LP_SIG_DET_Pos               0UL
#define MSCLP_INTR_LP_SIG_DET_Msk               0x1UL
#define MSCLP_INTR_LP_FR_TIMEOUT_Pos            4UL
#define MSCLP_INTR_LP_FR_TIMEOUT_Msk            0x10UL
#define MSCLP_INTR_LP_FRAME_Pos                 16UL
#define MSCLP_INTR_LP_FRAME_Msk                 0x10000UL
#define MSCLP_INTR_LP_CE_DONE_Pos               20UL
#define MSCLP_INTR_LP_CE_DONE_Msk               0x100000UL
#define MSCLP_INTR_LP_IMO_UP_Pos                24UL
#define MSCLP_INTR_LP_IMO_UP_Msk                0x1000000UL
/* MSCLP.INTR_LP_SET */
#define MSCLP_INTR_LP_SET_SIG_DET_Pos           0UL
#define MSCLP_INTR_LP_SET_SIG_DET_Msk           0x1UL
#define MSCLP_INTR_LP_SET_FR_TIMEOUT_Pos        4UL
#define MSCLP_INTR_LP_SET_FR_TIMEOUT_Msk        0x10UL
#define MSCLP_INTR_LP_SET_FRAME_Pos             16UL
#define MSCLP_INTR_LP_SET_FRAME_Msk             0x10000UL
#define MSCLP_INTR_LP_SET_CE_DONE_Pos           20UL
#define MSCLP_INTR_LP_SET_CE_DONE_Msk           0x100000UL
#define MSCLP_INTR_LP_SET_IMO_UP_Pos            24UL
#define MSCLP_INTR_LP_SET_IMO_UP_Msk            0x1000000UL
/* MSCLP.INTR_LP_MASK */
#define MSCLP_INTR_LP_MASK_SIG_DET_Pos          0UL
#define MSCLP_INTR_LP_MASK_SIG_DET_Msk          0x1UL
#define MSCLP_INTR_LP_MASK_FR_TIMEOUT_Pos       4UL
#define MSCLP_INTR_LP_MASK_FR_TIMEOUT_Msk       0x10UL
#define MSCLP_INTR_LP_MASK_FRAME_Pos            16UL
#define MSCLP_INTR_LP_MASK_FRAME_Msk            0x10000UL
#define MSCLP_INTR_LP_MASK_CE_DONE_Pos          20UL
#define MSCLP_INTR_LP_MASK_CE_DONE_Msk          0x100000UL
#define MSCLP_INTR_LP_MASK_IMO_UP_Pos           24UL
#define MSCLP_INTR_LP_MASK_IMO_UP_Msk           0x1000000UL
/* MSCLP.INTR_LP_MASKED */
#define MSCLP_INTR_LP_MASKED_SIG_DET_Pos        0UL
#define MSCLP_INTR_LP_MASKED_SIG_DET_Msk        0x1UL
#define MSCLP_INTR_LP_MASKED_FR_TIMEOUT_Pos     4UL
#define MSCLP_INTR_LP_MASKED_FR_TIMEOUT_Msk     0x10UL
#define MSCLP_INTR_LP_MASKED_FRAME_Pos          16UL
#define MSCLP_INTR_LP_MASKED_FRAME_Msk          0x10000UL
#define MSCLP_INTR_LP_MASKED_CE_DONE_Pos        20UL
#define MSCLP_INTR_LP_MASKED_CE_DONE_Msk        0x100000UL
#define MSCLP_INTR_LP_MASKED_IMO_UP_Pos         24UL
#define MSCLP_INTR_LP_MASKED_IMO_UP_Msk         0x1000000UL
/* MSCLP.WAKEUP_CMD */
#define MSCLP_WAKEUP_CMD_START_FRAME_AOS_Pos    0UL
#define MSCLP_WAKEUP_CMD_START_FRAME_AOS_Msk    0x1UL
/* MSCLP.MRSS_CMD */
#define MSCLP_MRSS_CMD_MRSS_START_Pos           0UL
#define MSCLP_MRSS_CMD_MRSS_START_Msk           0x1UL
#define MSCLP_MRSS_CMD_MRSS_STOP_Pos            8UL
#define MSCLP_MRSS_CMD_MRSS_STOP_Msk            0x100UL
#define MSCLP_MRSS_CMD_MRSS_PUMP_STOP_Pos       16UL
#define MSCLP_MRSS_CMD_MRSS_PUMP_STOP_Msk       0x10000UL
/* MSCLP.MRSS_STATUS */
#define MSCLP_MRSS_STATUS_MRSS_UP_Pos           0UL
#define MSCLP_MRSS_STATUS_MRSS_UP_Msk           0x1UL
#define MSCLP_MRSS_STATUS_IMO_UP_Pos            24UL
#define MSCLP_MRSS_STATUS_IMO_UP_Msk            0x1000000UL
/* MSCLP.AOS_STATUS */
#define MSCLP_AOS_STATUS_FRAME_TIMER_STATE_Pos  0UL
#define MSCLP_AOS_STATUS_FRAME_TIMER_STATE_Msk  0x7UL
#define MSCLP_AOS_STATUS_MRSS_BOOT_STATE_Pos    8UL
#define MSCLP_AOS_STATUS_MRSS_BOOT_STATE_Msk    0x300UL
#define MSCLP_AOS_STATUS_FRAME_EXE_STATE_Pos    16UL
#define MSCLP_AOS_STATUS_FRAME_EXE_STATE_Msk    0x10000UL
/* MSCLP.SW_SEL_GPIO */
#define MSCLP_SW_SEL_GPIO_SW_CSD_SENSE_Pos      0UL
#define MSCLP_SW_SEL_GPIO_SW_CSD_SENSE_Msk      0x7UL
#define MSCLP_SW_SEL_GPIO_SW_CSD_SHIELD_Pos     4UL
#define MSCLP_SW_SEL_GPIO_SW_CSD_SHIELD_Msk     0x70UL
#define MSCLP_SW_SEL_GPIO_SW_CSD_MUTUAL_Pos     8UL
#define MSCLP_SW_SEL_GPIO_SW_CSD_MUTUAL_Msk     0x100UL
#define MSCLP_SW_SEL_GPIO_SW_CSD_POLARITY_Pos   12UL
#define MSCLP_SW_SEL_GPIO_SW_CSD_POLARITY_Msk   0x3000UL
#define MSCLP_SW_SEL_GPIO_SW_CSD_CHARGE_Pos     16UL
#define MSCLP_SW_SEL_GPIO_SW_CSD_CHARGE_Msk     0x10000UL
#define MSCLP_SW_SEL_GPIO_SW_DSI_CMOD_Pos       20UL
#define MSCLP_SW_SEL_GPIO_SW_DSI_CMOD_Msk       0x700000UL
#define MSCLP_SW_SEL_GPIO_SW_DSI_CSH_TANK_Pos   24UL
#define MSCLP_SW_SEL_GPIO_SW_DSI_CSH_TANK_Msk   0x7000000UL
/* MSCLP.SW_SEL_CDAC_RE */
#define MSCLP_SW_SEL_CDAC_RE_SW_RETCC_Pos       0UL
#define MSCLP_SW_SEL_CDAC_RE_SW_RETCC_Msk       0x7UL
#define MSCLP_SW_SEL_CDAC_RE_SW_RECD_Pos        4UL
#define MSCLP_SW_SEL_CDAC_RE_SW_RECD_Msk        0x70UL
#define MSCLP_SW_SEL_CDAC_RE_SW_RETV_Pos        8UL
#define MSCLP_SW_SEL_CDAC_RE_SW_RETV_Msk        0x700UL
#define MSCLP_SW_SEL_CDAC_RE_SW_RETG_Pos        12UL
#define MSCLP_SW_SEL_CDAC_RE_SW_RETG_Msk        0x7000UL
#define MSCLP_SW_SEL_CDAC_RE_SW_REBV_Pos        16UL
#define MSCLP_SW_SEL_CDAC_RE_SW_REBV_Msk        0x70000UL
#define MSCLP_SW_SEL_CDAC_RE_SW_REBG_Pos        20UL
#define MSCLP_SW_SEL_CDAC_RE_SW_REBG_Msk        0x700000UL
/* MSCLP.SW_SEL_CDAC_CO */
#define MSCLP_SW_SEL_CDAC_CO_SW_COTCA_Pos       0UL
#define MSCLP_SW_SEL_CDAC_CO_SW_COTCA_Msk       0x7UL
#define MSCLP_SW_SEL_CDAC_CO_SW_COCB_Pos        4UL
#define MSCLP_SW_SEL_CDAC_CO_SW_COCB_Msk        0x70UL
#define MSCLP_SW_SEL_CDAC_CO_SW_COTV_Pos        8UL
#define MSCLP_SW_SEL_CDAC_CO_SW_COTV_Msk        0x700UL
#define MSCLP_SW_SEL_CDAC_CO_SW_COTG_Pos        12UL
#define MSCLP_SW_SEL_CDAC_CO_SW_COTG_Msk        0x7000UL
#define MSCLP_SW_SEL_CDAC_CO_SW_COBV_Pos        16UL
#define MSCLP_SW_SEL_CDAC_CO_SW_COBV_Msk        0x70000UL
#define MSCLP_SW_SEL_CDAC_CO_SW_COBG_Pos        20UL
#define MSCLP_SW_SEL_CDAC_CO_SW_COBG_Msk        0x700000UL
/* MSCLP.SW_SEL_CDAC_CF */
#define MSCLP_SW_SEL_CDAC_CF_SW_CFTCA_Pos       0UL
#define MSCLP_SW_SEL_CDAC_CF_SW_CFTCA_Msk       0x7UL
#define MSCLP_SW_SEL_CDAC_CF_SW_CFTCB_Pos       4UL
#define MSCLP_SW_SEL_CDAC_CF_SW_CFTCB_Msk       0x70UL
#define MSCLP_SW_SEL_CDAC_CF_SW_CFTV_Pos        8UL
#define MSCLP_SW_SEL_CDAC_CF_SW_CFTV_Msk        0x700UL
#define MSCLP_SW_SEL_CDAC_CF_SW_CFTG_Pos        12UL
#define MSCLP_SW_SEL_CDAC_CF_SW_CFTG_Msk        0x7000UL
#define MSCLP_SW_SEL_CDAC_CF_SW_CFBV_Pos        16UL
#define MSCLP_SW_SEL_CDAC_CF_SW_CFBV_Msk        0x70000UL
#define MSCLP_SW_SEL_CDAC_CF_SW_CFBG_Pos        20UL
#define MSCLP_SW_SEL_CDAC_CF_SW_CFBG_Msk        0x700000UL
/* MSCLP.SW_SEL_BGR */
#define MSCLP_SW_SEL_BGR_SW_BGRCM_Pos           0UL
#define MSCLP_SW_SEL_BGR_SW_BGRCM_Msk           0x1UL
#define MSCLP_SW_SEL_BGR_SW_IGMA_Pos            4UL
#define MSCLP_SW_SEL_BGR_SW_IGMA_Msk            0x10UL
#define MSCLP_SW_SEL_BGR_SW_BGRMA_Pos           8UL
#define MSCLP_SW_SEL_BGR_SW_BGRMA_Msk           0x100UL
/* MSCLP.SW_SEL_CSW */
#define MSCLP_SW_SEL_CSW_SW_AMUXA_Pos           0UL
#define MSCLP_SW_SEL_CSW_SW_AMUXA_Msk           0xFUL
#define MSCLP_SW_SEL_CSW_SW_AMUXB_Pos           8UL
#define MSCLP_SW_SEL_CSW_SW_AMUXB_Msk           0xF00UL
#define MSCLP_SW_SEL_CSW_SW_PU_Pos              16UL
#define MSCLP_SW_SEL_CSW_SW_PU_Msk              0xF0000UL
#define MSCLP_SW_SEL_CSW_SW_PD_Pos              24UL
#define MSCLP_SW_SEL_CSW_SW_PD_Msk              0xF000000UL
#define MSCLP_SW_SEL_CSW_REF_MODE_Pos           30UL
#define MSCLP_SW_SEL_CSW_REF_MODE_Msk           0x40000000UL
#define MSCLP_SW_SEL_CSW_DDRV_EN_Pos            31UL
#define MSCLP_SW_SEL_CSW_DDRV_EN_Msk            0x80000000UL
/* MSCLP.SW_SEL_CSW_FUNC */
#define MSCLP_SW_SEL_CSW_FUNC_SW_AMUXA_Pos      0UL
#define MSCLP_SW_SEL_CSW_FUNC_SW_AMUXA_Msk      0xFUL
#define MSCLP_SW_SEL_CSW_FUNC_SW_AMUXB_Pos      8UL
#define MSCLP_SW_SEL_CSW_FUNC_SW_AMUXB_Msk      0xF00UL
#define MSCLP_SW_SEL_CSW_FUNC_SW_PU_Pos         16UL
#define MSCLP_SW_SEL_CSW_FUNC_SW_PU_Msk         0xF0000UL
#define MSCLP_SW_SEL_CSW_FUNC_SW_PD_Pos         24UL
#define MSCLP_SW_SEL_CSW_FUNC_SW_PD_Msk         0xF000000UL
#define MSCLP_SW_SEL_CSW_FUNC_REF_MODE_Pos      30UL
#define MSCLP_SW_SEL_CSW_FUNC_REF_MODE_Msk      0x40000000UL
#define MSCLP_SW_SEL_CSW_FUNC_DDRV_EN_Pos       31UL
#define MSCLP_SW_SEL_CSW_FUNC_DDRV_EN_Msk       0x80000000UL
/* MSCLP.CSW_CTL_LO */
#define MSCLP_CSW_CTL_LO_CSW_FUNC_MODE_Pos      0UL
#define MSCLP_CSW_CTL_LO_CSW_FUNC_MODE_Msk      0xFFFFFFFFUL
/* MSCLP.CSW_CTL_HI */
#define MSCLP_CSW_CTL_HI_CSW_FUNC_MODE_Pos      0UL
#define MSCLP_CSW_CTL_HI_CSW_FUNC_MODE_Msk      0xFFFFFFFFUL
/* MSCLP.TRIM_CTL */
#define MSCLP_TRIM_CTL_TRIM_IN_Pos              0UL
#define MSCLP_TRIM_CTL_TRIM_IN_Msk              0xFUL
#define MSCLP_TRIM_CTL_TRIM_EN_Pos              4UL
#define MSCLP_TRIM_CTL_TRIM_EN_Msk              0x10UL
#define MSCLP_TRIM_CTL_TRIM_POLARITY_Pos        5UL
#define MSCLP_TRIM_CTL_TRIM_POLARITY_Msk        0x20UL
/* MSCLP.CLK_IMO_TRIM1 */
#define MSCLP_CLK_IMO_TRIM1_OFFSET_Pos          0UL
#define MSCLP_CLK_IMO_TRIM1_OFFSET_Msk          0xFFUL
/* MSCLP.CLK_IMO_TRIM2 */
#define MSCLP_CLK_IMO_TRIM2_FSOFFSET_Pos        0UL
#define MSCLP_CLK_IMO_TRIM2_FSOFFSET_Msk        0x7UL
/* MSCLP.CLK_IMO_TRIM3 */
#define MSCLP_CLK_IMO_TRIM3_TCTRIM_Pos          0UL
#define MSCLP_CLK_IMO_TRIM3_TCTRIM_Msk          0x3UL
/* MSCLP.PWR_BG_TRIM1 */
#define MSCLP_PWR_BG_TRIM1_REF_VTRIM_Pos        0UL
#define MSCLP_PWR_BG_TRIM1_REF_VTRIM_Msk        0x3FUL
/* MSCLP.PWR_BG_TRIM2 */
#define MSCLP_PWR_BG_TRIM2_REF_ITRIM_Pos        0UL
#define MSCLP_PWR_BG_TRIM2_REF_ITRIM_Msk        0x3FUL
/* MSCLP.PWR_BG_TRIM3 */
#define MSCLP_PWR_BG_TRIM3_REF_TCTRIM_Pos       0UL
#define MSCLP_PWR_BG_TRIM3_REF_TCTRIM_Msk       0xFUL


#endif /* _CYIP_MSCLP_H_ */


/* [] END OF FILE */
