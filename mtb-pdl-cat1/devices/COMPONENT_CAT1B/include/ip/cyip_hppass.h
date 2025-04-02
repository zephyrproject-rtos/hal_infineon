/***************************************************************************//**
* \file cyip_hppass.h
*
* \brief
* HPPASS IP definitions
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

#ifndef _CYIP_HPPASS_H_
#define _CYIP_HPPASS_H_

#include "cyip_headers.h"

/*******************************************************************************
*                                    HPPASS
*******************************************************************************/

#define HPPASS_SARADC_SECTION_SIZE              0x00010000UL
#define HPPASS_SAR_CFG_SECTION_SIZE             0x00000400UL
#define HPPASS_SAR_FIR_SECTION_SIZE             0x00000080UL
#define HPPASS_SAR_SECTION_SIZE                 0x00010000UL
#define HPPASS_CSG_SLICE_SECTION_SIZE           0x00000040UL
#define HPPASS_CSG_LUT_CFG_SECTION_SIZE         0x00000200UL
#define HPPASS_CSG_SECTION_SIZE                 0x00010000UL
#define HPPASS_ACTRLR_TTCFG_SECTION_SIZE        0x00000010UL
#define HPPASS_ACTRLR_SECTION_SIZE              0x00010000UL
#define HPPASS_INFRA_AREFV2_SECTION_SIZE        0x00000100UL
#define HPPASS_INFRA_SECTION_SIZE               0x00010000UL
#define HPPASS_MMIO_FIFO_SECTION_SIZE           0x00000100UL
#define HPPASS_MMIO_SECTION_SIZE                0x00010000UL
#define HPPASS_SECTION_SIZE                     0x00100000UL

/**
  * \brief SAR ADC Core (Calibration and Test)
NOTE: IP must be ENABLED to write and read these registers.  When the block is disabled these registers are reset (HPPASS_SARADC)
  */
typedef struct {
   __IM uint32_t RESERVED[4];
  __IOM uint32_t CALOFFST[4];                   /*!< 0x00000010 SARADC Offset Calibration Values */
  __IOM uint32_t CALLIN[16];                    /*!< 0x00000020 SARADC Linearity Calibration Values */
  __IOM uint32_t CALGAINC;                      /*!< 0x00000060 SARADC Coarse-grained Gain Calibration Values */
  __IOM uint32_t CALGAINF;                      /*!< 0x00000064 SARADC Fine-grained Gain Calibration Values */
   __IM uint32_t RESERVED1[16358];
} HPPASS_SARADC_Type;                           /*!< Size = 65536 (0x10000) */

/**
  * \brief SAR configuration and result registers (HPPASS_SAR_CFG)
  */
typedef struct {
  __IOM uint32_t CTRL;                          /*!< 0x00000000 Control register */
  __IOM uint32_t SAMP_EN;                       /*!< 0x00000004 Sampler static enable configuration register */
  __IOM uint32_t SAMP_GAIN;                     /*!< 0x00000008 Sampler gain configuration register */
   __IM uint32_t RESERVED;
  __IOM uint32_t SAMPLE_TIME[3];                /*!< 0x00000010 Sample Time configuration register */
   __IM uint32_t RESERVED1;
  __IOM uint32_t FIR_CFG[2];                    /*!< 0x00000020 FIR configuration register */
   __IM uint32_t RESERVED2[2];
  __IOM uint32_t CHAN_CFG[28];                  /*!< 0x00000030 SAR Channel configuration register */
   __IM uint32_t RESERVED3[4];
  __IOM uint32_t RANGE_CFG[8];                  /*!< 0x000000B0 Range detect configuration register. */
  __IOM uint32_t RANGE_LOW[8];                  /*!< 0x000000D0 Range detect low value register. */
  __IOM uint32_t RANGE_HIGH[8];                 /*!< 0x000000F0 Range detect high value register. */
   __IM uint32_t CHAN_RESULT[28];               /*!< 0x00000110 Channel result register */
   __IM uint32_t FIR_RESULT[2];                 /*!< 0x00000180 FIR result register */
   __IM uint32_t RESERVED4[2];
  __IOM uint32_t RESULT_MASK;                   /*!< 0x00000190 Channel result mask */
  __IOM uint32_t RESULT_UPDATED;                /*!< 0x00000194 Channel result register status */
  __IOM uint32_t RANGE_STATUS;                  /*!< 0x00000198 Range status register */
   __IM uint32_t SAR_STATUS;                    /*!< 0x0000019C SAR status register */
  __IOM uint32_t RESULT_OVERFLOW;               /*!< 0x000001A0 Entry overflow status */
  __IOM uint32_t ENTRY_TR_COLLISION;            /*!< 0x000001A4 Entry trigger collision status */
  __IOM uint32_t ENTRY_HOLD_VIOLATION;          /*!< 0x000001A8 Entry hold violation status */
  __IOM uint32_t ENTRY_HOLD_CNT;                /*!< 0x000001AC Entry hold violation count */
   __IM uint32_t RESERVED5[20];
  __IOM uint32_t SAR_RESULT_INTR;               /*!< 0x00000200 SAR Interrupt register */
  __IOM uint32_t SAR_RESULT_INTR_SET;           /*!< 0x00000204 SAR Interrupt request set register */
  __IOM uint32_t SAR_RESULT_INTR_MASK;          /*!< 0x00000208 SAR Interrupt request mask */
   __IM uint32_t SAR_RESULT_INTR_MASKED;        /*!< 0x0000020C SAR Interrupt request masked */
  __IOM uint32_t SAR_RANGE_INTR;                /*!< 0x00000210 SAR Range Interrupt register */
  __IOM uint32_t SAR_RANGE_INTR_SET;            /*!< 0x00000214 SAR Range Interrupt request set register */
  __IOM uint32_t SAR_RANGE_INTR_MASK;           /*!< 0x00000218 SAR Range Interrupt request mask */
   __IM uint32_t SAR_RANGE_INTR_MASKED;         /*!< 0x0000021C SAR Range Interrupt request masked */
   __IM uint32_t RESERVED6[4];
   __IM uint32_t CHAN_RESULT_PACKED[14];        /*!< 0x00000230 Channel result register packed with 2 results per register */
   __IM uint32_t RESERVED7[38];
  __IOM uint32_t AROUTE_CTRL_MODE;              /*!< 0x00000300 AROUTE control mode */
  __IOM uint32_t AROUTE_FW_CTRL;                /*!< 0x00000304 AROUTE firmware switch control set (individual) */
  __IOM uint32_t AROUTE_FW_CTRL_CLR;            /*!< 0x00000308 AROUTE firmware switch control clear (individual) */
   __IM uint32_t AROUTE_STATUS;                 /*!< 0x0000030C AROUTE switch status */
  __IOM uint32_t TEMPSENSE_CTRL;                /*!< 0x00000310 Temperture Sensor Control */
   __IM uint32_t RESERVED8[59];
} HPPASS_SAR_CFG_Type;                          /*!< Size = 1024 (0x400) */

/**
  * \brief SAR FIR coefficient and tap registers (HPPASS_SAR_FIR)
  */
typedef struct {
  __IOM uint32_t FIR_COEFS[16];                 /*!< 0x00000000 FIR Coeffecients */
  __IOM uint32_t FIR_TAPS[16];                  /*!< 0x00000040 FIR Taps */
} HPPASS_SAR_FIR_Type;                          /*!< Size = 128 (0x80) */

/**
  * \brief SAR ADC Controller (HPPASS_SAR)
  */
typedef struct {
   __IM uint32_t RESERVED[64];
  __IOM uint32_t SEQ_ENTRY[8];                  /*!< 0x00000100 SAR Sequencer Table Entries */
   __IM uint32_t RESERVED1[56];
  __IOM uint32_t ENTRY_MUX_SEL_ALIAS[8];        /*!< 0x00000200 SAR Sequencer MUX select alias registers */
   __IM uint32_t RESERVED2[120];
        HPPASS_SAR_CFG_Type CFG;                /*!< 0x00000400 SAR configuration and result registers */
        HPPASS_SAR_FIR_Type FIR[2];             /*!< 0x00000800 SAR FIR coefficient and tap registers */
   __IM uint32_t RESERVED3[15808];
} HPPASS_SAR_Type;                              /*!< Size = 65536 (0x10000) */

/**
  * \brief CSG Slice configuration registers (HPPASS_CSG_SLICE)
  */
typedef struct {
  __IOM uint32_t CMP_CFG;                       /*!< 0x00000000 Comparator Control Register */
  __IOM uint32_t DAC_CFG;                       /*!< 0x00000004 DAC Control Register */
  __IOM uint32_t DAC_PARAM_SYNC;                /*!< 0x00000008 DAC Parameter Synchronized Update */
  __IOM uint32_t DAC_MODE_START;                /*!< 0x0000000C DAC Mode Start */
  __IOM uint32_t DAC_VAL_A;                     /*!< 0x00000010 DAC Vaue A Buffer */
  __IOM uint32_t DAC_VAL_B;                     /*!< 0x00000014 DAC Value B Buffer */
  __IOM uint32_t DAC_PERIOD;                    /*!< 0x00000018 DAC Period Buffer */
  __IOM uint32_t DAC_VAL;                       /*!< 0x0000001C DAC FW write */
   __IM uint32_t DAC_STATUS;                    /*!< 0x00000020 Read of Current DAC Value */
   __IM uint32_t CMP_STATUS;                    /*!< 0x00000024 Read of Comparator Value */
   __IM uint32_t RESERVED[6];
} HPPASS_CSG_SLICE_Type;                        /*!< Size = 64 (0x40) */

/**
  * \brief DAC LUT waveform data (HPPASS_CSG_LUT_CFG)
  */
typedef struct {
  __IOM uint32_t LUT_DATA[128];                 /*!< 0x00000000 LUT Waveform Data */
} HPPASS_CSG_LUT_CFG_Type;                      /*!< Size = 512 (0x200) */

/**
  * \brief Comparator Slope Generator (HPPASS_CSG)
  */
typedef struct {
        HPPASS_CSG_SLICE_Type SLICE[5];         /*!< 0x00000000 CSG Slice configuration registers */
   __IM uint32_t RESERVED[176];
        HPPASS_CSG_LUT_CFG_Type LUT_CFG[2];     /*!< 0x00000400 DAC LUT waveform data */
   __IM uint32_t RESERVED1[128];
  __IOM uint32_t CSG_CTRL;                      /*!< 0x00000A00 CSG control register */
   __IM uint32_t RESERVED2[63];
  __IOM uint32_t DAC_INTR;                      /*!< 0x00000B00 DAC Interrupt register */
  __IOM uint32_t DAC_INTR_SET;                  /*!< 0x00000B04 DAC Interrupt request set register */
  __IOM uint32_t DAC_INTR_MASK;                 /*!< 0x00000B08 DAC Interrupt request mask */
   __IM uint32_t DAC_INTR_MASKED;               /*!< 0x00000B0C DAC Interrupt request masked */
  __IOM uint32_t CMP_INTR;                      /*!< 0x00000B10 CMP Interrupt register */
  __IOM uint32_t CMP_INTR_SET;                  /*!< 0x00000B14 CMP Interrupt request set register */
  __IOM uint32_t CMP_INTR_MASK;                 /*!< 0x00000B18 CMP Interrupt request mask */
   __IM uint32_t CMP_INTR_MASKED;               /*!< 0x00000B1C CMP Interrupt request masked */
  __IOM uint32_t VDAC_OUT_BLANK;                /*!< 0x00000B20 Blanking control for DAC Observability */
   __IM uint32_t RESERVED3[3];
  __IOM uint32_t CSG_SYNC;                      /*!< 0x00000B30 CSG Sync Enable register */
   __IM uint32_t RESERVED4[15667];
} HPPASS_CSG_Type;                              /*!< Size = 65536 (0x10000) */

/**
  * \brief Timer Table Structure (HPPASS_ACTRLR_TTCFG)
  */
typedef struct {
  __IOM uint32_t TT_CFG0;                       /*!< 0x00000000 AC Configuration 0 */
  __IOM uint32_t TT_CFG1;                       /*!< 0x00000004 AC Configuration 1 */
  __IOM uint32_t TT_CFG2;                       /*!< 0x00000008 AC Configuration 2 */
  __IOM uint32_t TT_CFG3;                       /*!< 0x0000000C AC Configuration 3 */
} HPPASS_ACTRLR_TTCFG_Type;                     /*!< Size = 16 (0x10) */

/**
  * \brief Autonomnous Controller (HPPASS_ACTRLR)
  */
typedef struct {
  __IOM uint32_t CTRL;                          /*!< 0x00000000 Control register */
  __IOM uint32_t CMD_RUN;                       /*!< 0x00000004 Run Command register */
  __IOM uint32_t CMD_STATE;                     /*!< 0x00000008 State Override register */
   __IM uint32_t RESERVED;
   __IM uint32_t BLOCK_STATUS;                  /*!< 0x00000010 Block Ready status register */
   __IM uint32_t RESERVED1[3];
   __IM uint32_t STATUS;                        /*!< 0x00000020 AC Status register */
  __IOM uint32_t CFG;                           /*!< 0x00000024 AC Config register */
   __IM uint32_t RESERVED2[54];
   __IM uint32_t CNTR_STATUS[2];                /*!< 0x00000100 Loop/Interval counter status register */
   __IM uint32_t RESERVED3[446];
        HPPASS_ACTRLR_TTCFG_Type TTCFG[16];     /*!< 0x00000800 Timer Table Structure */
   __IM uint32_t RESERVED4[15808];
} HPPASS_ACTRLR_Type;                           /*!< Size = 65536 (0x10000) */

/**
  * \brief AREF Configuration (HPPASS_INFRA_AREFV2)
  */
typedef struct {
  __IOM uint32_t AREF_CTRL;                     /*!< 0x00000000 AREF control */
   __IM uint32_t RESERVED[63];
} HPPASS_INFRA_AREFV2_Type;                     /*!< Size = 256 (0x100) */

/**
  * \brief MCPASS infrastructure (HPPASS_INFRA)
  */
typedef struct {
  __IOM uint32_t TR_IN_SEL;                     /*!< 0x00000000 Trigger Input Select */
  __IOM uint32_t HW_TR_MODE;                    /*!< 0x00000004 HW Trigger Mode */
  __IOM uint32_t FW_TR_PULSE;                   /*!< 0x00000008 FW Pulse Mode Trigger */
  __IOM uint32_t FW_TR_LEVEL;                   /*!< 0x0000000C FW Level Mode Trigger */
   __IM uint32_t RESERVED[4];
  __IOM uint32_t CLOCK_STARTUP_DIV;             /*!< 0x00000020 Startup Clock Divder */
   __IM uint32_t RESERVED1[3];
  __IOM uint32_t STARTUP_CFG[4];                /*!< 0x00000030 Startup configuration */
   __IM uint32_t RESERVED2[4];
   __IM uint32_t VDDA_STATUS;                   /*!< 0x00000050 Analog Voltage Status */
   __IM uint32_t RESERVED3[7];
  __IOM uint32_t ANA_CTRL;                      /*!< 0x00000070 Analog Control */
   __IM uint32_t RESERVED4[867];
        HPPASS_INFRA_AREFV2_Type AREFV2;        /*!< 0x00000E00 AREF Configuration */
  __IOM uint32_t VREF_TRIM0;                    /*!< 0x00000F00 VREF Trim bits */
  __IOM uint32_t VREF_TRIM1;                    /*!< 0x00000F04 VREF Trim bits */
  __IOM uint32_t VREF_TRIM2;                    /*!< 0x00000F08 VREF Trim bits */
  __IOM uint32_t VREF_TRIM3;                    /*!< 0x00000F0C VREF Trim bits */
  __IOM uint32_t IZTAT_TRIM0;                   /*!< 0x00000F10 IZTAT Trim bits */
  __IOM uint32_t IZTAT_TRIM1;                   /*!< 0x00000F14 IZTAT Trim bits */
  __IOM uint32_t IPTAT_TRIM0;                   /*!< 0x00000F18 IPTAT Trim bits */
  __IOM uint32_t ICTAT_TRIM0;                   /*!< 0x00000F1C ICTAT Trim bits */
   __IM uint32_t RESERVED5[15416];
} HPPASS_INFRA_Type;                            /*!< Size = 65536 (0x10000) */

/**
  * \brief FIFO Configuration (HPPASS_MMIO_FIFO)
  */
typedef struct {
  __IOM uint32_t CFG;                           /*!< 0x00000000 FIFO configuration register. */
  __IOM uint32_t CLR;                           /*!< 0x00000004 FIFO FW clear register */
   __IM uint32_t RESERVED[2];
  __IOM uint32_t LEVEL[4];                      /*!< 0x00000010 FIFO level register. */
   __IM uint32_t RESERVED1[4];
   __IM uint32_t RD_DATA[4];                    /*!< 0x00000030 FIFO 32-bit read data register */
   __IM uint32_t RESERVED2[4];
   __IM uint32_t USED[4];                       /*!< 0x00000050 FIFO used register */
   __IM uint32_t RESERVED3[4];
   __IM uint32_t STATUS[4];                     /*!< 0x00000070 FIFO status register */
   __IM uint32_t RESERVED4[32];
} HPPASS_MMIO_FIFO_Type;                        /*!< Size = 256 (0x100) */

/**
  * \brief MCPASS top-level MMIO (HPPASS_MMIO)
  */
typedef struct {
   __IM uint32_t FIFO_INTR;                     /*!< 0x00000000 FIFO Interrupt request register */
   __IM uint32_t RESERVED[3];
  __IOM uint32_t FIFO_INTR_SET;                 /*!< 0x00000010 FIFO Interrupt set request register */
   __IM uint32_t RESERVED1[3];
  __IOM uint32_t FIFO_INTR_MASK;                /*!< 0x00000020 FIFO Interrupt mask register */
   __IM uint32_t RESERVED2[3];
   __IM uint32_t FIFO_INTR_MASKED;              /*!< 0x00000030 FIFO Interrupt masked request register */
   __IM uint32_t RESERVED3[3];
  __IOM uint32_t HPPASS_INTR;                   /*!< 0x00000040 MCPASS Interrupt request register */
  __IOM uint32_t HPPASS_INTR_SET;               /*!< 0x00000044 MCPASS Interrupt set request register */
  __IOM uint32_t HPPASS_INTR_MASK;              /*!< 0x00000048 MCPASS Interrupt mask register */
   __IM uint32_t HPPASS_INTR_MASKED;            /*!< 0x0000004C MCPASS Interrupt masked request register */
  __IOM uint32_t TR_LEVEL_CFG;                  /*!< 0x00000050 LEVEL Trigger out configuration */
   __IM uint32_t RESERVED4[3];
  __IOM uint32_t TR_LEVEL_OUT[8];               /*!< 0x00000060 LEVEL Trigger out select register */
  __IOM uint32_t TR_PULSE_OUT[8];               /*!< 0x00000080 PULSE Trigger out select register */
   __IM uint32_t RESERVED5[24];
        HPPASS_MMIO_FIFO_Type FIFO;             /*!< 0x00000100 FIFO Configuration */
   __IM uint32_t RESERVED6[16256];
} HPPASS_MMIO_Type;                             /*!< Size = 65536 (0x10000) */

/**
  * \brief Top Level of MCPASS IP (HPPASS)
  */
typedef struct {
   __IM uint32_t RESERVED[114688];
        HPPASS_SARADC_Type SARADC;              /*!< 0x00070000 SAR ADC Core (Calibration and Test) NOTE: IP must be ENABLED to
                                                                write and read these registers. When the block is disabled these
                                                                registers are reset */
        HPPASS_SAR_Type SAR;                    /*!< 0x00080000 SAR ADC Controller */
   __IM uint32_t RESERVED1[32768];
        HPPASS_CSG_Type CSG;                    /*!< 0x000B0000 Comparator Slope Generator */
   __IM uint32_t RESERVED2[16384];
        HPPASS_ACTRLR_Type ACTRLR;              /*!< 0x000D0000 Autonomnous Controller */
        HPPASS_INFRA_Type INFRA;                /*!< 0x000E0000 MCPASS infrastructure */
        HPPASS_MMIO_Type MMIO;                  /*!< 0x000F0000 MCPASS top-level MMIO */
} HPPASS_Type;                                  /*!< Size = 1048576 (0x100000) */


/* HPPASS_SARADC.CALOFFST */
#define HPPASS_SARADC_CALOFFST_OFFSET_4N_0_Pos  0UL
#define HPPASS_SARADC_CALOFFST_OFFSET_4N_0_Msk  0x7FUL
#define HPPASS_SARADC_CALOFFST_OFFSET_4N_1_Pos  8UL
#define HPPASS_SARADC_CALOFFST_OFFSET_4N_1_Msk  0x7F00UL
#define HPPASS_SARADC_CALOFFST_OFFSET_4N_2_Pos  16UL
#define HPPASS_SARADC_CALOFFST_OFFSET_4N_2_Msk  0x7F0000UL
#define HPPASS_SARADC_CALOFFST_OFFSET_4N_3_Pos  24UL
#define HPPASS_SARADC_CALOFFST_OFFSET_4N_3_Msk  0x7F000000UL
/* HPPASS_SARADC.CALLIN */
#define HPPASS_SARADC_CALLIN_LIN9_Pos           0UL
#define HPPASS_SARADC_CALLIN_LIN9_Msk           0x7FUL
#define HPPASS_SARADC_CALLIN_LIIN10_Pos         8UL
#define HPPASS_SARADC_CALLIN_LIIN10_Msk         0x7F00UL
#define HPPASS_SARADC_CALLIN_LIN11_Pos          16UL
#define HPPASS_SARADC_CALLIN_LIN11_Msk          0x7F0000UL
#define HPPASS_SARADC_CALLIN_LIN12_Pos          24UL
#define HPPASS_SARADC_CALLIN_LIN12_Msk          0x7F000000UL
/* HPPASS_SARADC.CALGAINC */
#define HPPASS_SARADC_CALGAINC_GAINC3_Pos       0UL
#define HPPASS_SARADC_CALGAINC_GAINC3_Msk       0xFUL
#define HPPASS_SARADC_CALGAINC_GAINC6_Pos       8UL
#define HPPASS_SARADC_CALGAINC_GAINC6_Msk       0xF00UL
#define HPPASS_SARADC_CALGAINC_GAINC12_Pos      16UL
#define HPPASS_SARADC_CALGAINC_GAINC12_Msk      0xF0000UL
/* HPPASS_SARADC.CALGAINF */
#define HPPASS_SARADC_CALGAINF_GAINF3_Pos       0UL
#define HPPASS_SARADC_CALGAINF_GAINF3_Msk       0x7FUL
#define HPPASS_SARADC_CALGAINF_GAINF6_Pos       8UL
#define HPPASS_SARADC_CALGAINF_GAINF6_Msk       0x7F00UL
#define HPPASS_SARADC_CALGAINF_GAINF12_Pos      16UL
#define HPPASS_SARADC_CALGAINF_GAINF12_Msk      0x7F0000UL


/* HPPASS_SAR_CFG.CTRL */
#define HPPASS_SAR_CFG_CTRL_VREF_SEL_Pos        0UL
#define HPPASS_SAR_CFG_CTRL_VREF_SEL_Msk        0x3UL
#define HPPASS_SAR_CFG_CTRL_LOW_SUPPLY_MODE_Pos 2UL
#define HPPASS_SAR_CFG_CTRL_LOW_SUPPLY_MODE_Msk 0x4UL
#define HPPASS_SAR_CFG_CTRL_STARTUP_CAL_OFFSET_EN_Pos 4UL
#define HPPASS_SAR_CFG_CTRL_STARTUP_CAL_OFFSET_EN_Msk 0x10UL
#define HPPASS_SAR_CFG_CTRL_STARTUP_CAL_LINEARITY_EN_Pos 5UL
#define HPPASS_SAR_CFG_CTRL_STARTUP_CAL_LINEARITY_EN_Msk 0x20UL
#define HPPASS_SAR_CFG_CTRL_STARTUP_CAL_GAIN_EN_Pos 6UL
#define HPPASS_SAR_CFG_CTRL_STARTUP_CAL_GAIN_EN_Msk 0x40UL
#define HPPASS_SAR_CFG_CTRL_CHAN_ID_EN_Pos      8UL
#define HPPASS_SAR_CFG_CTRL_CHAN_ID_EN_Msk      0x100UL
/* HPPASS_SAR_CFG.SAMP_EN */
#define HPPASS_SAR_CFG_SAMP_EN_DIRECT_SAMP_EN_Pos 0UL
#define HPPASS_SAR_CFG_SAMP_EN_DIRECT_SAMP_EN_Msk 0xFFFUL
#define HPPASS_SAR_CFG_SAMP_EN_MUXED_SAMP_EN_Pos 12UL
#define HPPASS_SAR_CFG_SAMP_EN_MUXED_SAMP_EN_Msk 0xF000UL
/* HPPASS_SAR_CFG.SAMP_GAIN */
#define HPPASS_SAR_CFG_SAMP_GAIN_SAMP_GAIN_Pos  0UL
#define HPPASS_SAR_CFG_SAMP_GAIN_SAMP_GAIN_Msk  0xFFFFFFFFUL
/* HPPASS_SAR_CFG.SAMPLE_TIME */
#define HPPASS_SAR_CFG_SAMPLE_TIME_SAMPLE_TIME_Pos 0UL
#define HPPASS_SAR_CFG_SAMPLE_TIME_SAMPLE_TIME_Msk 0x3FFUL
/* HPPASS_SAR_CFG.FIR_CFG */
#define HPPASS_SAR_CFG_FIR_CFG_CHANNEL_SEL_Pos  0UL
#define HPPASS_SAR_CFG_FIR_CFG_CHANNEL_SEL_Msk  0x1FUL
#define HPPASS_SAR_CFG_FIR_CFG_WAIT_TAP_INIT_Pos 8UL
#define HPPASS_SAR_CFG_FIR_CFG_WAIT_TAP_INIT_Msk 0x100UL
#define HPPASS_SAR_CFG_FIR_CFG_RANGE_SEL_Pos    20UL
#define HPPASS_SAR_CFG_FIR_CFG_RANGE_SEL_Msk    0xF00000UL
#define HPPASS_SAR_CFG_FIR_CFG_FIFO_SEL_Pos     28UL
#define HPPASS_SAR_CFG_FIR_CFG_FIFO_SEL_Msk     0x70000000UL
/* HPPASS_SAR_CFG.CHAN_CFG */
#define HPPASS_SAR_CFG_CHAN_CFG_DIFFERENTIAL_EN_Pos 0UL
#define HPPASS_SAR_CFG_CHAN_CFG_DIFFERENTIAL_EN_Msk 0x1UL
#define HPPASS_SAR_CFG_CHAN_CFG_SIGNED_Pos      1UL
#define HPPASS_SAR_CFG_CHAN_CFG_SIGNED_Msk      0x2UL
#define HPPASS_SAR_CFG_CHAN_CFG_RESERVED_11_8_Pos 8UL
#define HPPASS_SAR_CFG_CHAN_CFG_RESERVED_11_8_Msk 0xF00UL
#define HPPASS_SAR_CFG_CHAN_CFG_RESERVED_15_12_Pos 12UL
#define HPPASS_SAR_CFG_CHAN_CFG_RESERVED_15_12_Msk 0xF000UL
#define HPPASS_SAR_CFG_CHAN_CFG_RANGE_SEL_Pos   20UL
#define HPPASS_SAR_CFG_CHAN_CFG_RANGE_SEL_Msk   0xF00000UL
#define HPPASS_SAR_CFG_CHAN_CFG_AVG_SEL_Pos     24UL
#define HPPASS_SAR_CFG_CHAN_CFG_AVG_SEL_Msk     0x7000000UL
#define HPPASS_SAR_CFG_CHAN_CFG_FIFO_SEL_Pos    28UL
#define HPPASS_SAR_CFG_CHAN_CFG_FIFO_SEL_Msk    0x70000000UL
/* HPPASS_SAR_CFG.RANGE_CFG */
#define HPPASS_SAR_CFG_RANGE_CFG_RANGE_COND_Pos 0UL
#define HPPASS_SAR_CFG_RANGE_CFG_RANGE_COND_Msk 0x3UL
/* HPPASS_SAR_CFG.RANGE_LOW */
#define HPPASS_SAR_CFG_RANGE_LOW_RANGE_LOW_Pos  0UL
#define HPPASS_SAR_CFG_RANGE_LOW_RANGE_LOW_Msk  0xFFFFUL
/* HPPASS_SAR_CFG.RANGE_HIGH */
#define HPPASS_SAR_CFG_RANGE_HIGH_RANGE_HIGH_Pos 0UL
#define HPPASS_SAR_CFG_RANGE_HIGH_RANGE_HIGH_Msk 0xFFFFUL
/* HPPASS_SAR_CFG.CHAN_RESULT */
#define HPPASS_SAR_CFG_CHAN_RESULT_RESULT_Pos   0UL
#define HPPASS_SAR_CFG_CHAN_RESULT_RESULT_Msk   0xFFFFUL
/* HPPASS_SAR_CFG.FIR_RESULT */
#define HPPASS_SAR_CFG_FIR_RESULT_RESULT_Pos    0UL
#define HPPASS_SAR_CFG_FIR_RESULT_RESULT_Msk    0xFFFFUL
/* HPPASS_SAR_CFG.RESULT_MASK */
#define HPPASS_SAR_CFG_RESULT_MASK_CHAN_RESULT_MASK_Pos 0UL
#define HPPASS_SAR_CFG_RESULT_MASK_CHAN_RESULT_MASK_Msk 0xFFFFFFFUL
#define HPPASS_SAR_CFG_RESULT_MASK_FIR_RESULT_MASK_Pos 30UL
#define HPPASS_SAR_CFG_RESULT_MASK_FIR_RESULT_MASK_Msk 0xC0000000UL
/* HPPASS_SAR_CFG.RESULT_UPDATED */
#define HPPASS_SAR_CFG_RESULT_UPDATED_CHAN_RESULT_UPDATED_Pos 0UL
#define HPPASS_SAR_CFG_RESULT_UPDATED_CHAN_RESULT_UPDATED_Msk 0xFFFFFFFUL
#define HPPASS_SAR_CFG_RESULT_UPDATED_FIR_RESULT_UPDATED_Pos 30UL
#define HPPASS_SAR_CFG_RESULT_UPDATED_FIR_RESULT_UPDATED_Msk 0xC0000000UL
/* HPPASS_SAR_CFG.RANGE_STATUS */
#define HPPASS_SAR_CFG_RANGE_STATUS_CHAN_RANGE_Pos 0UL
#define HPPASS_SAR_CFG_RANGE_STATUS_CHAN_RANGE_Msk 0xFFFFFFFUL
#define HPPASS_SAR_CFG_RANGE_STATUS_FIR_RANGE_Pos 30UL
#define HPPASS_SAR_CFG_RANGE_STATUS_FIR_RANGE_Msk 0xC0000000UL
/* HPPASS_SAR_CFG.SAR_STATUS */
#define HPPASS_SAR_CFG_SAR_STATUS_BUSY_Pos      31UL
#define HPPASS_SAR_CFG_SAR_STATUS_BUSY_Msk      0x80000000UL
/* HPPASS_SAR_CFG.RESULT_OVERFLOW */
#define HPPASS_SAR_CFG_RESULT_OVERFLOW_ENTRY_RESULT_OVF_Pos 0UL
#define HPPASS_SAR_CFG_RESULT_OVERFLOW_ENTRY_RESULT_OVF_Msk 0xFFUL
#define HPPASS_SAR_CFG_RESULT_OVERFLOW_FIR_RESULT_OVF_Pos 16UL
#define HPPASS_SAR_CFG_RESULT_OVERFLOW_FIR_RESULT_OVF_Msk 0x30000UL
/* HPPASS_SAR_CFG.ENTRY_TR_COLLISION */
#define HPPASS_SAR_CFG_ENTRY_TR_COLLISION_ENTRY_COL_Pos 0UL
#define HPPASS_SAR_CFG_ENTRY_TR_COLLISION_ENTRY_COL_Msk 0xFFUL
/* HPPASS_SAR_CFG.ENTRY_HOLD_VIOLATION */
#define HPPASS_SAR_CFG_ENTRY_HOLD_VIOLATION_HOLD_VIOL_Pos 0UL
#define HPPASS_SAR_CFG_ENTRY_HOLD_VIOLATION_HOLD_VIOL_Msk 0xFFUL
/* HPPASS_SAR_CFG.ENTRY_HOLD_CNT */
#define HPPASS_SAR_CFG_ENTRY_HOLD_CNT_HOLD_CNT_Pos 0UL
#define HPPASS_SAR_CFG_ENTRY_HOLD_CNT_HOLD_CNT_Msk 0xFFUL
/* HPPASS_SAR_CFG.SAR_RESULT_INTR */
#define HPPASS_SAR_CFG_SAR_RESULT_INTR_ENTRY_DONE_Pos 0UL
#define HPPASS_SAR_CFG_SAR_RESULT_INTR_ENTRY_DONE_Msk 0xFFUL
#define HPPASS_SAR_CFG_SAR_RESULT_INTR_FIR_DONE_Pos 16UL
#define HPPASS_SAR_CFG_SAR_RESULT_INTR_FIR_DONE_Msk 0x30000UL
/* HPPASS_SAR_CFG.SAR_RESULT_INTR_SET */
#define HPPASS_SAR_CFG_SAR_RESULT_INTR_SET_ENTRY_DONE_SET_Pos 0UL
#define HPPASS_SAR_CFG_SAR_RESULT_INTR_SET_ENTRY_DONE_SET_Msk 0xFFUL
#define HPPASS_SAR_CFG_SAR_RESULT_INTR_SET_FIR_DONE_SET_Pos 16UL
#define HPPASS_SAR_CFG_SAR_RESULT_INTR_SET_FIR_DONE_SET_Msk 0x30000UL
/* HPPASS_SAR_CFG.SAR_RESULT_INTR_MASK */
#define HPPASS_SAR_CFG_SAR_RESULT_INTR_MASK_ENTRY_DONE_MASK_Pos 0UL
#define HPPASS_SAR_CFG_SAR_RESULT_INTR_MASK_ENTRY_DONE_MASK_Msk 0xFFUL
#define HPPASS_SAR_CFG_SAR_RESULT_INTR_MASK_FIR_DONE_MASK_Pos 16UL
#define HPPASS_SAR_CFG_SAR_RESULT_INTR_MASK_FIR_DONE_MASK_Msk 0x30000UL
/* HPPASS_SAR_CFG.SAR_RESULT_INTR_MASKED */
#define HPPASS_SAR_CFG_SAR_RESULT_INTR_MASKED_ENTRY_DONE_MASKED_Pos 0UL
#define HPPASS_SAR_CFG_SAR_RESULT_INTR_MASKED_ENTRY_DONE_MASKED_Msk 0xFFUL
#define HPPASS_SAR_CFG_SAR_RESULT_INTR_MASKED_FIR_DONE_MASKED_Pos 16UL
#define HPPASS_SAR_CFG_SAR_RESULT_INTR_MASKED_FIR_DONE_MASKED_Msk 0x30000UL
/* HPPASS_SAR_CFG.SAR_RANGE_INTR */
#define HPPASS_SAR_CFG_SAR_RANGE_INTR_RANGE_Pos 0UL
#define HPPASS_SAR_CFG_SAR_RANGE_INTR_RANGE_Msk 0xFFUL
/* HPPASS_SAR_CFG.SAR_RANGE_INTR_SET */
#define HPPASS_SAR_CFG_SAR_RANGE_INTR_SET_RANGE_SET_Pos 0UL
#define HPPASS_SAR_CFG_SAR_RANGE_INTR_SET_RANGE_SET_Msk 0xFFUL
/* HPPASS_SAR_CFG.SAR_RANGE_INTR_MASK */
#define HPPASS_SAR_CFG_SAR_RANGE_INTR_MASK_RANGE_SET_MASK_Pos 0UL
#define HPPASS_SAR_CFG_SAR_RANGE_INTR_MASK_RANGE_SET_MASK_Msk 0xFFUL
/* HPPASS_SAR_CFG.SAR_RANGE_INTR_MASKED */
#define HPPASS_SAR_CFG_SAR_RANGE_INTR_MASKED_RANGE_SET_MASKED_Pos 0UL
#define HPPASS_SAR_CFG_SAR_RANGE_INTR_MASKED_RANGE_SET_MASKED_Msk 0xFFUL
/* HPPASS_SAR_CFG.CHAN_RESULT_PACKED */
#define HPPASS_SAR_CFG_CHAN_RESULT_PACKED_RESULT_EVEN_Pos 0UL
#define HPPASS_SAR_CFG_CHAN_RESULT_PACKED_RESULT_EVEN_Msk 0xFFFFUL
#define HPPASS_SAR_CFG_CHAN_RESULT_PACKED_RESULT_ODD_Pos 16UL
#define HPPASS_SAR_CFG_CHAN_RESULT_PACKED_RESULT_ODD_Msk 0xFFFF0000UL
/* HPPASS_SAR_CFG.AROUTE_CTRL_MODE */
#define HPPASS_SAR_CFG_AROUTE_CTRL_MODE_MUX0_CTRL_Pos 0UL
#define HPPASS_SAR_CFG_AROUTE_CTRL_MODE_MUX0_CTRL_Msk 0x3UL
#define HPPASS_SAR_CFG_AROUTE_CTRL_MODE_MUX1_CTRL_Pos 2UL
#define HPPASS_SAR_CFG_AROUTE_CTRL_MODE_MUX1_CTRL_Msk 0xCUL
#define HPPASS_SAR_CFG_AROUTE_CTRL_MODE_MUX2_CTRL_Pos 4UL
#define HPPASS_SAR_CFG_AROUTE_CTRL_MODE_MUX2_CTRL_Msk 0x30UL
#define HPPASS_SAR_CFG_AROUTE_CTRL_MODE_MUX3_CTRL_Pos 6UL
#define HPPASS_SAR_CFG_AROUTE_CTRL_MODE_MUX3_CTRL_Msk 0xC0UL
#define HPPASS_SAR_CFG_AROUTE_CTRL_MODE_TEMPSENSE_ENABLED_Pos 30UL
#define HPPASS_SAR_CFG_AROUTE_CTRL_MODE_TEMPSENSE_ENABLED_Msk 0x40000000UL
#define HPPASS_SAR_CFG_AROUTE_CTRL_MODE_AROUTE_ENABLED_Pos 31UL
#define HPPASS_SAR_CFG_AROUTE_CTRL_MODE_AROUTE_ENABLED_Msk 0x80000000UL
/* HPPASS_SAR_CFG.AROUTE_FW_CTRL */
#define HPPASS_SAR_CFG_AROUTE_FW_CTRL_MUX0_SW0_Pos 0UL
#define HPPASS_SAR_CFG_AROUTE_FW_CTRL_MUX0_SW0_Msk 0x1UL
#define HPPASS_SAR_CFG_AROUTE_FW_CTRL_MUX0_SW1_Pos 1UL
#define HPPASS_SAR_CFG_AROUTE_FW_CTRL_MUX0_SW1_Msk 0x2UL
#define HPPASS_SAR_CFG_AROUTE_FW_CTRL_MUX0_SW2_Pos 2UL
#define HPPASS_SAR_CFG_AROUTE_FW_CTRL_MUX0_SW2_Msk 0x4UL
#define HPPASS_SAR_CFG_AROUTE_FW_CTRL_MUX0_SW3_Pos 3UL
#define HPPASS_SAR_CFG_AROUTE_FW_CTRL_MUX0_SW3_Msk 0x8UL
#define HPPASS_SAR_CFG_AROUTE_FW_CTRL_MUX1_SW0_Pos 4UL
#define HPPASS_SAR_CFG_AROUTE_FW_CTRL_MUX1_SW0_Msk 0x10UL
#define HPPASS_SAR_CFG_AROUTE_FW_CTRL_MUX1_SW1_Pos 5UL
#define HPPASS_SAR_CFG_AROUTE_FW_CTRL_MUX1_SW1_Msk 0x20UL
#define HPPASS_SAR_CFG_AROUTE_FW_CTRL_MUX1_SW2_Pos 6UL
#define HPPASS_SAR_CFG_AROUTE_FW_CTRL_MUX1_SW2_Msk 0x40UL
#define HPPASS_SAR_CFG_AROUTE_FW_CTRL_MUX1_SW3_Pos 7UL
#define HPPASS_SAR_CFG_AROUTE_FW_CTRL_MUX1_SW3_Msk 0x80UL
#define HPPASS_SAR_CFG_AROUTE_FW_CTRL_MUX2_SW0_Pos 8UL
#define HPPASS_SAR_CFG_AROUTE_FW_CTRL_MUX2_SW0_Msk 0x100UL
#define HPPASS_SAR_CFG_AROUTE_FW_CTRL_MUX2_SW1_Pos 9UL
#define HPPASS_SAR_CFG_AROUTE_FW_CTRL_MUX2_SW1_Msk 0x200UL
#define HPPASS_SAR_CFG_AROUTE_FW_CTRL_MUX2_SW2_Pos 10UL
#define HPPASS_SAR_CFG_AROUTE_FW_CTRL_MUX2_SW2_Msk 0x400UL
#define HPPASS_SAR_CFG_AROUTE_FW_CTRL_MUX2_SW3_Pos 11UL
#define HPPASS_SAR_CFG_AROUTE_FW_CTRL_MUX2_SW3_Msk 0x800UL
#define HPPASS_SAR_CFG_AROUTE_FW_CTRL_MUX3_SW0_Pos 12UL
#define HPPASS_SAR_CFG_AROUTE_FW_CTRL_MUX3_SW0_Msk 0x1000UL
#define HPPASS_SAR_CFG_AROUTE_FW_CTRL_MUX3_SW1_Pos 13UL
#define HPPASS_SAR_CFG_AROUTE_FW_CTRL_MUX3_SW1_Msk 0x2000UL
#define HPPASS_SAR_CFG_AROUTE_FW_CTRL_MUX3_SW2_Pos 14UL
#define HPPASS_SAR_CFG_AROUTE_FW_CTRL_MUX3_SW2_Msk 0x4000UL
#define HPPASS_SAR_CFG_AROUTE_FW_CTRL_MUX3_SW3_Pos 15UL
#define HPPASS_SAR_CFG_AROUTE_FW_CTRL_MUX3_SW3_Msk 0x8000UL
/* HPPASS_SAR_CFG.AROUTE_FW_CTRL_CLR */
#define HPPASS_SAR_CFG_AROUTE_FW_CTRL_CLR_MUX0_SW0_Pos 0UL
#define HPPASS_SAR_CFG_AROUTE_FW_CTRL_CLR_MUX0_SW0_Msk 0x1UL
#define HPPASS_SAR_CFG_AROUTE_FW_CTRL_CLR_MUX0_SW1_Pos 1UL
#define HPPASS_SAR_CFG_AROUTE_FW_CTRL_CLR_MUX0_SW1_Msk 0x2UL
#define HPPASS_SAR_CFG_AROUTE_FW_CTRL_CLR_MUX0_SW2_Pos 2UL
#define HPPASS_SAR_CFG_AROUTE_FW_CTRL_CLR_MUX0_SW2_Msk 0x4UL
#define HPPASS_SAR_CFG_AROUTE_FW_CTRL_CLR_MUX0_SW3_Pos 3UL
#define HPPASS_SAR_CFG_AROUTE_FW_CTRL_CLR_MUX0_SW3_Msk 0x8UL
#define HPPASS_SAR_CFG_AROUTE_FW_CTRL_CLR_MUX1_SW0_Pos 4UL
#define HPPASS_SAR_CFG_AROUTE_FW_CTRL_CLR_MUX1_SW0_Msk 0x10UL
#define HPPASS_SAR_CFG_AROUTE_FW_CTRL_CLR_MUX1_SW1_Pos 5UL
#define HPPASS_SAR_CFG_AROUTE_FW_CTRL_CLR_MUX1_SW1_Msk 0x20UL
#define HPPASS_SAR_CFG_AROUTE_FW_CTRL_CLR_MUX1_SW2_Pos 6UL
#define HPPASS_SAR_CFG_AROUTE_FW_CTRL_CLR_MUX1_SW2_Msk 0x40UL
#define HPPASS_SAR_CFG_AROUTE_FW_CTRL_CLR_MUX1_SW3_Pos 7UL
#define HPPASS_SAR_CFG_AROUTE_FW_CTRL_CLR_MUX1_SW3_Msk 0x80UL
#define HPPASS_SAR_CFG_AROUTE_FW_CTRL_CLR_MUX2_SW0_Pos 8UL
#define HPPASS_SAR_CFG_AROUTE_FW_CTRL_CLR_MUX2_SW0_Msk 0x100UL
#define HPPASS_SAR_CFG_AROUTE_FW_CTRL_CLR_MUX2_SW1_Pos 9UL
#define HPPASS_SAR_CFG_AROUTE_FW_CTRL_CLR_MUX2_SW1_Msk 0x200UL
#define HPPASS_SAR_CFG_AROUTE_FW_CTRL_CLR_MUX2_SW2_Pos 10UL
#define HPPASS_SAR_CFG_AROUTE_FW_CTRL_CLR_MUX2_SW2_Msk 0x400UL
#define HPPASS_SAR_CFG_AROUTE_FW_CTRL_CLR_MUX2_SW3_Pos 11UL
#define HPPASS_SAR_CFG_AROUTE_FW_CTRL_CLR_MUX2_SW3_Msk 0x800UL
#define HPPASS_SAR_CFG_AROUTE_FW_CTRL_CLR_MUX3_SW0_Pos 12UL
#define HPPASS_SAR_CFG_AROUTE_FW_CTRL_CLR_MUX3_SW0_Msk 0x1000UL
#define HPPASS_SAR_CFG_AROUTE_FW_CTRL_CLR_MUX3_SW1_Pos 13UL
#define HPPASS_SAR_CFG_AROUTE_FW_CTRL_CLR_MUX3_SW1_Msk 0x2000UL
#define HPPASS_SAR_CFG_AROUTE_FW_CTRL_CLR_MUX3_SW2_Pos 14UL
#define HPPASS_SAR_CFG_AROUTE_FW_CTRL_CLR_MUX3_SW2_Msk 0x4000UL
#define HPPASS_SAR_CFG_AROUTE_FW_CTRL_CLR_MUX3_SW3_Pos 15UL
#define HPPASS_SAR_CFG_AROUTE_FW_CTRL_CLR_MUX3_SW3_Msk 0x8000UL
/* HPPASS_SAR_CFG.AROUTE_STATUS */
#define HPPASS_SAR_CFG_AROUTE_STATUS_MUX0_SW0_Pos 0UL
#define HPPASS_SAR_CFG_AROUTE_STATUS_MUX0_SW0_Msk 0x1UL
#define HPPASS_SAR_CFG_AROUTE_STATUS_MUX0_SW1_Pos 1UL
#define HPPASS_SAR_CFG_AROUTE_STATUS_MUX0_SW1_Msk 0x2UL
#define HPPASS_SAR_CFG_AROUTE_STATUS_MUX0_SW2_Pos 2UL
#define HPPASS_SAR_CFG_AROUTE_STATUS_MUX0_SW2_Msk 0x4UL
#define HPPASS_SAR_CFG_AROUTE_STATUS_MUX0_SW3_Pos 3UL
#define HPPASS_SAR_CFG_AROUTE_STATUS_MUX0_SW3_Msk 0x8UL
#define HPPASS_SAR_CFG_AROUTE_STATUS_MUX1_SW0_Pos 4UL
#define HPPASS_SAR_CFG_AROUTE_STATUS_MUX1_SW0_Msk 0x10UL
#define HPPASS_SAR_CFG_AROUTE_STATUS_MUX1_SW1_Pos 5UL
#define HPPASS_SAR_CFG_AROUTE_STATUS_MUX1_SW1_Msk 0x20UL
#define HPPASS_SAR_CFG_AROUTE_STATUS_MUX1_SW2_Pos 6UL
#define HPPASS_SAR_CFG_AROUTE_STATUS_MUX1_SW2_Msk 0x40UL
#define HPPASS_SAR_CFG_AROUTE_STATUS_MUX1_SW3_Pos 7UL
#define HPPASS_SAR_CFG_AROUTE_STATUS_MUX1_SW3_Msk 0x80UL
#define HPPASS_SAR_CFG_AROUTE_STATUS_MUX2_SW0_Pos 8UL
#define HPPASS_SAR_CFG_AROUTE_STATUS_MUX2_SW0_Msk 0x100UL
#define HPPASS_SAR_CFG_AROUTE_STATUS_MUX2_SW1_Pos 9UL
#define HPPASS_SAR_CFG_AROUTE_STATUS_MUX2_SW1_Msk 0x200UL
#define HPPASS_SAR_CFG_AROUTE_STATUS_MUX2_SW2_Pos 10UL
#define HPPASS_SAR_CFG_AROUTE_STATUS_MUX2_SW2_Msk 0x400UL
#define HPPASS_SAR_CFG_AROUTE_STATUS_MUX2_SW3_Pos 11UL
#define HPPASS_SAR_CFG_AROUTE_STATUS_MUX2_SW3_Msk 0x800UL
#define HPPASS_SAR_CFG_AROUTE_STATUS_MUX3_SW0_Pos 12UL
#define HPPASS_SAR_CFG_AROUTE_STATUS_MUX3_SW0_Msk 0x1000UL
#define HPPASS_SAR_CFG_AROUTE_STATUS_MUX3_SW1_Pos 13UL
#define HPPASS_SAR_CFG_AROUTE_STATUS_MUX3_SW1_Msk 0x2000UL
#define HPPASS_SAR_CFG_AROUTE_STATUS_MUX3_SW2_Pos 14UL
#define HPPASS_SAR_CFG_AROUTE_STATUS_MUX3_SW2_Msk 0x4000UL
#define HPPASS_SAR_CFG_AROUTE_STATUS_MUX3_SW3_Pos 15UL
#define HPPASS_SAR_CFG_AROUTE_STATUS_MUX3_SW3_Msk 0x8000UL
/* HPPASS_SAR_CFG.TEMPSENSE_CTRL */
#define HPPASS_SAR_CFG_TEMPSENSE_CTRL_TEMPSENSE_CURRENT_SEL_Pos 0UL
#define HPPASS_SAR_CFG_TEMPSENSE_CTRL_TEMPSENSE_CURRENT_SEL_Msk 0x1UL


/* HPPASS_SAR_FIR.FIR_COEFS */
#define HPPASS_SAR_FIR_FIR_COEFS_COEF_Pos       0UL
#define HPPASS_SAR_FIR_FIR_COEFS_COEF_Msk       0xFFFFUL
/* HPPASS_SAR_FIR.FIR_TAPS */
#define HPPASS_SAR_FIR_FIR_TAPS_TAP_Pos         0UL
#define HPPASS_SAR_FIR_FIR_TAPS_TAP_Msk         0xFFFFUL


/* HPPASS_SAR.SEQ_ENTRY */
#define HPPASS_SAR_SEQ_ENTRY_DIRECT_SAMPLER_EN_Pos 0UL
#define HPPASS_SAR_SEQ_ENTRY_DIRECT_SAMPLER_EN_Msk 0xFFFUL
#define HPPASS_SAR_SEQ_ENTRY_MUXED_SAMPLER_EN_Pos 12UL
#define HPPASS_SAR_SEQ_ENTRY_MUXED_SAMPLER_EN_Msk 0xF000UL
#define HPPASS_SAR_SEQ_ENTRY_MUX0_SEL_Pos       16UL
#define HPPASS_SAR_SEQ_ENTRY_MUX0_SEL_Msk       0x30000UL
#define HPPASS_SAR_SEQ_ENTRY_MUX1_SEL_Pos       18UL
#define HPPASS_SAR_SEQ_ENTRY_MUX1_SEL_Msk       0xC0000UL
#define HPPASS_SAR_SEQ_ENTRY_MUX2_SEL_Pos       20UL
#define HPPASS_SAR_SEQ_ENTRY_MUX2_SEL_Msk       0x300000UL
#define HPPASS_SAR_SEQ_ENTRY_MUX3_SEL_Pos       22UL
#define HPPASS_SAR_SEQ_ENTRY_MUX3_SEL_Msk       0xC00000UL
#define HPPASS_SAR_SEQ_ENTRY_TR_SEL_Pos         24UL
#define HPPASS_SAR_SEQ_ENTRY_TR_SEL_Msk         0xF000000UL
#define HPPASS_SAR_SEQ_ENTRY_SAMP_TIME_SEL_Pos  28UL
#define HPPASS_SAR_SEQ_ENTRY_SAMP_TIME_SEL_Msk  0x30000000UL
#define HPPASS_SAR_SEQ_ENTRY_PRIORITY_Pos       30UL
#define HPPASS_SAR_SEQ_ENTRY_PRIORITY_Msk       0x40000000UL
#define HPPASS_SAR_SEQ_ENTRY_CONT_Pos           31UL
#define HPPASS_SAR_SEQ_ENTRY_CONT_Msk           0x80000000UL
/* HPPASS_SAR.ENTRY_MUX_SEL_ALIAS */
#define HPPASS_SAR_ENTRY_MUX_SEL_ALIAS_MUX0_SEL_Pos 16UL
#define HPPASS_SAR_ENTRY_MUX_SEL_ALIAS_MUX0_SEL_Msk 0x30000UL
#define HPPASS_SAR_ENTRY_MUX_SEL_ALIAS_MUX1_SEL_Pos 18UL
#define HPPASS_SAR_ENTRY_MUX_SEL_ALIAS_MUX1_SEL_Msk 0xC0000UL
#define HPPASS_SAR_ENTRY_MUX_SEL_ALIAS_MUX2_SEL_Pos 20UL
#define HPPASS_SAR_ENTRY_MUX_SEL_ALIAS_MUX2_SEL_Msk 0x300000UL
#define HPPASS_SAR_ENTRY_MUX_SEL_ALIAS_MUX3_SEL_Pos 22UL
#define HPPASS_SAR_ENTRY_MUX_SEL_ALIAS_MUX3_SEL_Msk 0xC00000UL


/* HPPASS_CSG_SLICE.CMP_CFG */
#define HPPASS_CSG_SLICE_CMP_CFG_CMP_POS_SEL_Pos 0UL
#define HPPASS_CSG_SLICE_CMP_CFG_CMP_POS_SEL_Msk 0x1UL
#define HPPASS_CSG_SLICE_CMP_CFG_CMP_NEG_SEL_Pos 2UL
#define HPPASS_CSG_SLICE_CMP_CFG_CMP_NEG_SEL_Msk 0xCUL
#define HPPASS_CSG_SLICE_CMP_CFG_CMP_BLANK_MODE_Pos 4UL
#define HPPASS_CSG_SLICE_CMP_CFG_CMP_BLANK_MODE_Msk 0x30UL
#define HPPASS_CSG_SLICE_CMP_CFG_CMP_BLANK_TR_SEL_Pos 8UL
#define HPPASS_CSG_SLICE_CMP_CFG_CMP_BLANK_TR_SEL_Msk 0xF00UL
#define HPPASS_CSG_SLICE_CMP_CFG_CMP_EDGE_MODE_Pos 12UL
#define HPPASS_CSG_SLICE_CMP_CFG_CMP_EDGE_MODE_Msk 0x3000UL
#define HPPASS_CSG_SLICE_CMP_CFG_CMP_POLARITY_Pos 16UL
#define HPPASS_CSG_SLICE_CMP_CFG_CMP_POLARITY_Msk 0x10000UL
/* HPPASS_CSG_SLICE.DAC_CFG */
#define HPPASS_CSG_SLICE_DAC_CFG_DAC_TR_START_SEL_Pos 0UL
#define HPPASS_CSG_SLICE_DAC_CFG_DAC_TR_START_SEL_Msk 0xFUL
#define HPPASS_CSG_SLICE_DAC_CFG_DAC_TR_UPDATE_SEL_Pos 4UL
#define HPPASS_CSG_SLICE_DAC_CFG_DAC_TR_UPDATE_SEL_Msk 0xF0UL
#define HPPASS_CSG_SLICE_DAC_CFG_DAC_MODE_Pos   8UL
#define HPPASS_CSG_SLICE_DAC_CFG_DAC_MODE_Msk   0x700UL
#define HPPASS_CSG_SLICE_DAC_CFG_DAC_CONT_Pos   12UL
#define HPPASS_CSG_SLICE_DAC_CFG_DAC_CONT_Msk   0x1000UL
#define HPPASS_CSG_SLICE_DAC_CFG_DAC_SKIP_TR_EN_Pos 13UL
#define HPPASS_CSG_SLICE_DAC_CFG_DAC_SKIP_TR_EN_Msk 0x2000UL
#define HPPASS_CSG_SLICE_DAC_CFG_DAC_CASCADE_EN_Pos 14UL
#define HPPASS_CSG_SLICE_DAC_CFG_DAC_CASCADE_EN_Msk 0x4000UL
#define HPPASS_CSG_SLICE_DAC_CFG_DAC_PARAM_SYNC_EN_Pos 15UL
#define HPPASS_CSG_SLICE_DAC_CFG_DAC_PARAM_SYNC_EN_Msk 0x8000UL
#define HPPASS_CSG_SLICE_DAC_CFG_DAC_STEP_Pos   20UL
#define HPPASS_CSG_SLICE_DAC_CFG_DAC_STEP_Msk   0x3F00000UL
#define HPPASS_CSG_SLICE_DAC_CFG_DAC_DEGLITCH_Pos 28UL
#define HPPASS_CSG_SLICE_DAC_CFG_DAC_DEGLITCH_Msk 0x70000000UL
/* HPPASS_CSG_SLICE.DAC_PARAM_SYNC */
#define HPPASS_CSG_SLICE_DAC_PARAM_SYNC_READY_Pos 0UL
#define HPPASS_CSG_SLICE_DAC_PARAM_SYNC_READY_Msk 0x1UL
/* HPPASS_CSG_SLICE.DAC_MODE_START */
#define HPPASS_CSG_SLICE_DAC_MODE_START_BUSY_Pos 0UL
#define HPPASS_CSG_SLICE_DAC_MODE_START_BUSY_Msk 0x1UL
#define HPPASS_CSG_SLICE_DAC_MODE_START_HW_START_Pos 30UL
#define HPPASS_CSG_SLICE_DAC_MODE_START_HW_START_Msk 0x40000000UL
#define HPPASS_CSG_SLICE_DAC_MODE_START_FW_START_Pos 31UL
#define HPPASS_CSG_SLICE_DAC_MODE_START_FW_START_Msk 0x80000000UL
/* HPPASS_CSG_SLICE.DAC_VAL_A */
#define HPPASS_CSG_SLICE_DAC_VAL_A_VALUE_Pos    0UL
#define HPPASS_CSG_SLICE_DAC_VAL_A_VALUE_Msk    0x3FFUL
/* HPPASS_CSG_SLICE.DAC_VAL_B */
#define HPPASS_CSG_SLICE_DAC_VAL_B_VALUE_Pos    0UL
#define HPPASS_CSG_SLICE_DAC_VAL_B_VALUE_Msk    0x3FFUL
/* HPPASS_CSG_SLICE.DAC_PERIOD */
#define HPPASS_CSG_SLICE_DAC_PERIOD_PERIOD_FRAC_Pos 3UL
#define HPPASS_CSG_SLICE_DAC_PERIOD_PERIOD_FRAC_Msk 0xF8UL
#define HPPASS_CSG_SLICE_DAC_PERIOD_PERIOD_INT_Pos 8UL
#define HPPASS_CSG_SLICE_DAC_PERIOD_PERIOD_INT_Msk 0xFFF00UL
/* HPPASS_CSG_SLICE.DAC_VAL */
#define HPPASS_CSG_SLICE_DAC_VAL_VALUE_Pos      0UL
#define HPPASS_CSG_SLICE_DAC_VAL_VALUE_Msk      0x3FFUL
/* HPPASS_CSG_SLICE.DAC_STATUS */
#define HPPASS_CSG_SLICE_DAC_STATUS_DAC_VAL_Pos 0UL
#define HPPASS_CSG_SLICE_DAC_STATUS_DAC_VAL_Msk 0x3FFUL
/* HPPASS_CSG_SLICE.CMP_STATUS */
#define HPPASS_CSG_SLICE_CMP_STATUS_CMP_VAL_Pos 0UL
#define HPPASS_CSG_SLICE_CMP_STATUS_CMP_VAL_Msk 0x1UL


/* HPPASS_CSG_LUT_CFG.LUT_DATA */
#define HPPASS_CSG_LUT_CFG_LUT_DATA_DATA_Pos    0UL
#define HPPASS_CSG_LUT_CFG_LUT_DATA_DATA_Msk    0x3FFUL


/* HPPASS_CSG.CSG_CTRL */
#define HPPASS_CSG_CSG_CTRL_VDAC_OUT_SEL_Pos    0UL
#define HPPASS_CSG_CSG_CTRL_VDAC_OUT_SEL_Msk    0xFUL
#define HPPASS_CSG_CSG_CTRL_CSG_CLK_DIV_BYP_Pos 8UL
#define HPPASS_CSG_CSG_CTRL_CSG_CLK_DIV_BYP_Msk 0x100UL
/* HPPASS_CSG.DAC_INTR */
#define HPPASS_CSG_DAC_INTR_DAC_HW_START_Pos    0UL
#define HPPASS_CSG_DAC_INTR_DAC_HW_START_Msk    0xFFUL
#define HPPASS_CSG_DAC_INTR_DAC_SLOPE_DONE_Pos  8UL
#define HPPASS_CSG_DAC_INTR_DAC_SLOPE_DONE_Msk  0xFF00UL
#define HPPASS_CSG_DAC_INTR_DAC_BUF_EMPTY_Pos   16UL
#define HPPASS_CSG_DAC_INTR_DAC_BUF_EMPTY_Msk   0xFF0000UL
/* HPPASS_CSG.DAC_INTR_SET */
#define HPPASS_CSG_DAC_INTR_SET_DAC_HW_START_Pos 0UL
#define HPPASS_CSG_DAC_INTR_SET_DAC_HW_START_Msk 0xFFUL
#define HPPASS_CSG_DAC_INTR_SET_DAC_SLOPE_DONE_Pos 8UL
#define HPPASS_CSG_DAC_INTR_SET_DAC_SLOPE_DONE_Msk 0xFF00UL
#define HPPASS_CSG_DAC_INTR_SET_DAC_BUF_EMPTY_Pos 16UL
#define HPPASS_CSG_DAC_INTR_SET_DAC_BUF_EMPTY_Msk 0xFF0000UL
/* HPPASS_CSG.DAC_INTR_MASK */
#define HPPASS_CSG_DAC_INTR_MASK_DAC_HW_START_Pos 0UL
#define HPPASS_CSG_DAC_INTR_MASK_DAC_HW_START_Msk 0xFFUL
#define HPPASS_CSG_DAC_INTR_MASK_DAC_SLOPE_DONE_Pos 8UL
#define HPPASS_CSG_DAC_INTR_MASK_DAC_SLOPE_DONE_Msk 0xFF00UL
#define HPPASS_CSG_DAC_INTR_MASK_DAC_BUF_EMPTY_Pos 16UL
#define HPPASS_CSG_DAC_INTR_MASK_DAC_BUF_EMPTY_Msk 0xFF0000UL
/* HPPASS_CSG.DAC_INTR_MASKED */
#define HPPASS_CSG_DAC_INTR_MASKED_DAC_HW_START_Pos 0UL
#define HPPASS_CSG_DAC_INTR_MASKED_DAC_HW_START_Msk 0xFFUL
#define HPPASS_CSG_DAC_INTR_MASKED_DAC_SLOPE_DONE_Pos 8UL
#define HPPASS_CSG_DAC_INTR_MASKED_DAC_SLOPE_DONE_Msk 0xFF00UL
#define HPPASS_CSG_DAC_INTR_MASKED_DAC_BUF_EMPTY_Pos 16UL
#define HPPASS_CSG_DAC_INTR_MASKED_DAC_BUF_EMPTY_Msk 0xFF0000UL
/* HPPASS_CSG.CMP_INTR */
#define HPPASS_CSG_CMP_INTR_CMP_Pos             0UL
#define HPPASS_CSG_CMP_INTR_CMP_Msk             0xFFUL
/* HPPASS_CSG.CMP_INTR_SET */
#define HPPASS_CSG_CMP_INTR_SET_CMP_Pos         0UL
#define HPPASS_CSG_CMP_INTR_SET_CMP_Msk         0xFFUL
/* HPPASS_CSG.CMP_INTR_MASK */
#define HPPASS_CSG_CMP_INTR_MASK_CMP_Pos        0UL
#define HPPASS_CSG_CMP_INTR_MASK_CMP_Msk        0xFFUL
/* HPPASS_CSG.CMP_INTR_MASKED */
#define HPPASS_CSG_CMP_INTR_MASKED_CMP_Pos      0UL
#define HPPASS_CSG_CMP_INTR_MASKED_CMP_Msk      0xFFUL
/* HPPASS_CSG.VDAC_OUT_BLANK */
#define HPPASS_CSG_VDAC_OUT_BLANK_BLANK_CNT_Pos 0UL
#define HPPASS_CSG_VDAC_OUT_BLANK_BLANK_CNT_Msk 0x1FUL
/* HPPASS_CSG.CSG_SYNC */
#define HPPASS_CSG_CSG_SYNC_SYNC_EN_Pos         0UL
#define HPPASS_CSG_CSG_SYNC_SYNC_EN_Msk         0x1UL


/* HPPASS_ACTRLR_TTCFG.TT_CFG0 */
#define HPPASS_ACTRLR_TTCFG_TT_CFG0_SAR_UNLOCK_Pos 4UL
#define HPPASS_ACTRLR_TTCFG_TT_CFG0_SAR_UNLOCK_Msk 0x10UL
#define HPPASS_ACTRLR_TTCFG_TT_CFG0_CSG_UNLOCK_Pos 8UL
#define HPPASS_ACTRLR_TTCFG_TT_CFG0_CSG_UNLOCK_Msk 0xFF00UL
#define HPPASS_ACTRLR_TTCFG_TT_CFG0_DOUT_UNLOCK_Pos 16UL
#define HPPASS_ACTRLR_TTCFG_TT_CFG0_DOUT_UNLOCK_Msk 0x10000UL
#define HPPASS_ACTRLR_TTCFG_TT_CFG0_DOUT_Pos    20UL
#define HPPASS_ACTRLR_TTCFG_TT_CFG0_DOUT_Msk    0x1F00000UL
/* HPPASS_ACTRLR_TTCFG.TT_CFG1 */
#define HPPASS_ACTRLR_TTCFG_TT_CFG1_BR_ADDR_Pos 0UL
#define HPPASS_ACTRLR_TTCFG_TT_CFG1_BR_ADDR_Msk 0xFUL
#define HPPASS_ACTRLR_TTCFG_TT_CFG1_NC_7_4_Pos  4UL
#define HPPASS_ACTRLR_TTCFG_TT_CFG1_NC_7_4_Msk  0xF0UL
#define HPPASS_ACTRLR_TTCFG_TT_CFG1_COND_Pos    8UL
#define HPPASS_ACTRLR_TTCFG_TT_CFG1_COND_Msk    0x3F00UL
#define HPPASS_ACTRLR_TTCFG_TT_CFG1_NC_15_14_Pos 14UL
#define HPPASS_ACTRLR_TTCFG_TT_CFG1_NC_15_14_Msk 0xC000UL
#define HPPASS_ACTRLR_TTCFG_TT_CFG1_ACTION_Pos  16UL
#define HPPASS_ACTRLR_TTCFG_TT_CFG1_ACTION_Msk  0x70000UL
#define HPPASS_ACTRLR_TTCFG_TT_CFG1_INTR_SET_Pos 19UL
#define HPPASS_ACTRLR_TTCFG_TT_CFG1_INTR_SET_Msk 0x80000UL
#define HPPASS_ACTRLR_TTCFG_TT_CFG1_CNT_Pos     20UL
#define HPPASS_ACTRLR_TTCFG_TT_CFG1_CNT_Msk     0xFFF00000UL
/* HPPASS_ACTRLR_TTCFG.TT_CFG2 */
#define HPPASS_ACTRLR_TTCFG_TT_CFG2_CSG_EN_Pos  0UL
#define HPPASS_ACTRLR_TTCFG_TT_CFG2_CSG_EN_Msk  0xFFUL
#define HPPASS_ACTRLR_TTCFG_TT_CFG2_CSG_DAC_TR_Pos 8UL
#define HPPASS_ACTRLR_TTCFG_TT_CFG2_CSG_DAC_TR_Msk 0xFF00UL
#define HPPASS_ACTRLR_TTCFG_TT_CFG2_NC_31_16_Pos 16UL
#define HPPASS_ACTRLR_TTCFG_TT_CFG2_NC_31_16_Msk 0xFFFF0000UL
/* HPPASS_ACTRLR_TTCFG.TT_CFG3 */
#define HPPASS_ACTRLR_TTCFG_TT_CFG3_SAR_TR_Pos  0UL
#define HPPASS_ACTRLR_TTCFG_TT_CFG3_SAR_TR_Msk  0xFFUL
#define HPPASS_ACTRLR_TTCFG_TT_CFG3_SAR_EN_Pos  8UL
#define HPPASS_ACTRLR_TTCFG_TT_CFG3_SAR_EN_Msk  0x100UL
#define HPPASS_ACTRLR_TTCFG_TT_CFG3_NC_11_9_Pos 9UL
#define HPPASS_ACTRLR_TTCFG_TT_CFG3_NC_11_9_Msk 0xE00UL
#define HPPASS_ACTRLR_TTCFG_TT_CFG3_SAR_AROUTE_TR_Pos 12UL
#define HPPASS_ACTRLR_TTCFG_TT_CFG3_SAR_AROUTE_TR_Msk 0xF000UL
#define HPPASS_ACTRLR_TTCFG_TT_CFG3_SAR_AROUTE_SEL_Pos 16UL
#define HPPASS_ACTRLR_TTCFG_TT_CFG3_SAR_AROUTE_SEL_Msk 0xFF0000UL
#define HPPASS_ACTRLR_TTCFG_TT_CFG3_NC_31_24_Pos 24UL
#define HPPASS_ACTRLR_TTCFG_TT_CFG3_NC_31_24_Msk 0xFF000000UL


/* HPPASS_ACTRLR.CTRL */
#define HPPASS_ACTRLR_CTRL_ENABLED_Pos          31UL
#define HPPASS_ACTRLR_CTRL_ENABLED_Msk          0x80000000UL
/* HPPASS_ACTRLR.CMD_RUN */
#define HPPASS_ACTRLR_CMD_RUN_RUN_Pos           0UL
#define HPPASS_ACTRLR_CMD_RUN_RUN_Msk           0x1UL
/* HPPASS_ACTRLR.CMD_STATE */
#define HPPASS_ACTRLR_CMD_STATE_STATE_Pos       0UL
#define HPPASS_ACTRLR_CMD_STATE_STATE_Msk       0xFUL
/* HPPASS_ACTRLR.BLOCK_STATUS */
#define HPPASS_ACTRLR_BLOCK_STATUS_READY_Pos    0UL
#define HPPASS_ACTRLR_BLOCK_STATUS_READY_Msk    0x1UL
/* HPPASS_ACTRLR.STATUS */
#define HPPASS_ACTRLR_STATUS_CUR_STATE_Pos      0UL
#define HPPASS_ACTRLR_STATUS_CUR_STATE_Msk      0xFUL
#define HPPASS_ACTRLR_STATUS_STATUS_Pos         8UL
#define HPPASS_ACTRLR_STATUS_STATUS_Msk         0x300UL
/* HPPASS_ACTRLR.CFG */
#define HPPASS_ACTRLR_CFG_DOUT_EN_Pos           0UL
#define HPPASS_ACTRLR_CFG_DOUT_EN_Msk           0x1FUL
/* HPPASS_ACTRLR.CNTR_STATUS */
#define HPPASS_ACTRLR_CNTR_STATUS_CUR_STATE_Pos 0UL
#define HPPASS_ACTRLR_CNTR_STATUS_CUR_STATE_Msk 0xFUL
#define HPPASS_ACTRLR_CNTR_STATUS_CUR_CNT_Pos   8UL
#define HPPASS_ACTRLR_CNTR_STATUS_CUR_CNT_Msk   0xFFF00UL
#define HPPASS_ACTRLR_CNTR_STATUS_BUSY_Pos      31UL
#define HPPASS_ACTRLR_CNTR_STATUS_BUSY_Msk      0x80000000UL


/* HPPASS_INFRA_AREFV2.AREF_CTRL */
#define HPPASS_INFRA_AREFV2_AREF_CTRL_AREF_MODE_Pos 0UL
#define HPPASS_INFRA_AREFV2_AREF_CTRL_AREF_MODE_Msk 0x1UL
#define HPPASS_INFRA_AREFV2_AREF_CTRL_AREF_BIAS_SCALE_Pos 2UL
#define HPPASS_INFRA_AREFV2_AREF_CTRL_AREF_BIAS_SCALE_Msk 0xCUL
#define HPPASS_INFRA_AREFV2_AREF_CTRL_AREF_RMB_Pos 4UL
#define HPPASS_INFRA_AREFV2_AREF_CTRL_AREF_RMB_Msk 0x70UL
#define HPPASS_INFRA_AREFV2_AREF_CTRL_CTB_IPTAT_SCALE_Pos 7UL
#define HPPASS_INFRA_AREFV2_AREF_CTRL_CTB_IPTAT_SCALE_Msk 0x80UL
#define HPPASS_INFRA_AREFV2_AREF_CTRL_CTB_IPTAT_REDIRECT_Pos 8UL
#define HPPASS_INFRA_AREFV2_AREF_CTRL_CTB_IPTAT_REDIRECT_Msk 0xFF00UL
#define HPPASS_INFRA_AREFV2_AREF_CTRL_IZTAT_SEL_Pos 16UL
#define HPPASS_INFRA_AREFV2_AREF_CTRL_IZTAT_SEL_Msk 0x10000UL
#define HPPASS_INFRA_AREFV2_AREF_CTRL_VREF_SEL_Pos 20UL
#define HPPASS_INFRA_AREFV2_AREF_CTRL_VREF_SEL_Msk 0x300000UL
#define HPPASS_INFRA_AREFV2_AREF_CTRL_ENABLED_Pos 31UL
#define HPPASS_INFRA_AREFV2_AREF_CTRL_ENABLED_Msk 0x80000000UL


/* HPPASS_INFRA.TR_IN_SEL */
#define HPPASS_INFRA_TR_IN_SEL_TR0_SEL_Pos      0UL
#define HPPASS_INFRA_TR_IN_SEL_TR0_SEL_Msk      0x7UL
#define HPPASS_INFRA_TR_IN_SEL_TR1_SEL_Pos      4UL
#define HPPASS_INFRA_TR_IN_SEL_TR1_SEL_Msk      0x70UL
#define HPPASS_INFRA_TR_IN_SEL_TR2_SEL_Pos      8UL
#define HPPASS_INFRA_TR_IN_SEL_TR2_SEL_Msk      0x700UL
#define HPPASS_INFRA_TR_IN_SEL_TR3_SEL_Pos      12UL
#define HPPASS_INFRA_TR_IN_SEL_TR3_SEL_Msk      0x7000UL
#define HPPASS_INFRA_TR_IN_SEL_TR4_SEL_Pos      16UL
#define HPPASS_INFRA_TR_IN_SEL_TR4_SEL_Msk      0x70000UL
#define HPPASS_INFRA_TR_IN_SEL_TR5_SEL_Pos      20UL
#define HPPASS_INFRA_TR_IN_SEL_TR5_SEL_Msk      0x700000UL
#define HPPASS_INFRA_TR_IN_SEL_TR6_SEL_Pos      24UL
#define HPPASS_INFRA_TR_IN_SEL_TR6_SEL_Msk      0x7000000UL
#define HPPASS_INFRA_TR_IN_SEL_TR7_SEL_Pos      28UL
#define HPPASS_INFRA_TR_IN_SEL_TR7_SEL_Msk      0x70000000UL
/* HPPASS_INFRA.HW_TR_MODE */
#define HPPASS_INFRA_HW_TR_MODE_HW_TR0_MODE_Pos 0UL
#define HPPASS_INFRA_HW_TR_MODE_HW_TR0_MODE_Msk 0xFUL
#define HPPASS_INFRA_HW_TR_MODE_HW_TR1_MODE_Pos 4UL
#define HPPASS_INFRA_HW_TR_MODE_HW_TR1_MODE_Msk 0xF0UL
#define HPPASS_INFRA_HW_TR_MODE_HW_TR2_MODE_Pos 8UL
#define HPPASS_INFRA_HW_TR_MODE_HW_TR2_MODE_Msk 0xF00UL
#define HPPASS_INFRA_HW_TR_MODE_HW_TR3_MODE_Pos 12UL
#define HPPASS_INFRA_HW_TR_MODE_HW_TR3_MODE_Msk 0xF000UL
#define HPPASS_INFRA_HW_TR_MODE_HW_TR4_MODE_Pos 16UL
#define HPPASS_INFRA_HW_TR_MODE_HW_TR4_MODE_Msk 0xF0000UL
#define HPPASS_INFRA_HW_TR_MODE_HW_TR5_MODE_Pos 20UL
#define HPPASS_INFRA_HW_TR_MODE_HW_TR5_MODE_Msk 0xF00000UL
#define HPPASS_INFRA_HW_TR_MODE_HW_TR6_MODE_Pos 24UL
#define HPPASS_INFRA_HW_TR_MODE_HW_TR6_MODE_Msk 0xF000000UL
#define HPPASS_INFRA_HW_TR_MODE_HW_TR7_MODE_Pos 28UL
#define HPPASS_INFRA_HW_TR_MODE_HW_TR7_MODE_Msk 0xF0000000UL
/* HPPASS_INFRA.FW_TR_PULSE */
#define HPPASS_INFRA_FW_TR_PULSE_FW_TR_PULSE_Pos 0UL
#define HPPASS_INFRA_FW_TR_PULSE_FW_TR_PULSE_Msk 0xFFUL
/* HPPASS_INFRA.FW_TR_LEVEL */
#define HPPASS_INFRA_FW_TR_LEVEL_FW_TR_LEVEL_Pos 0UL
#define HPPASS_INFRA_FW_TR_LEVEL_FW_TR_LEVEL_Msk 0xFFUL
/* HPPASS_INFRA.CLOCK_STARTUP_DIV */
#define HPPASS_INFRA_CLOCK_STARTUP_DIV_DIV_VAL_Pos 0UL
#define HPPASS_INFRA_CLOCK_STARTUP_DIV_DIV_VAL_Msk 0xFFUL
/* HPPASS_INFRA.STARTUP_CFG */
#define HPPASS_INFRA_STARTUP_CFG_COUNT_VAL_Pos  0UL
#define HPPASS_INFRA_STARTUP_CFG_COUNT_VAL_Msk  0xFFUL
#define HPPASS_INFRA_STARTUP_CFG_SAR_EN_Pos     8UL
#define HPPASS_INFRA_STARTUP_CFG_SAR_EN_Msk     0x100UL
#define HPPASS_INFRA_STARTUP_CFG_CSG_CH_EN_Pos  9UL
#define HPPASS_INFRA_STARTUP_CFG_CSG_CH_EN_Msk  0x200UL
#define HPPASS_INFRA_STARTUP_CFG_CSG_PWR_EN_SLICE_Pos 10UL
#define HPPASS_INFRA_STARTUP_CFG_CSG_PWR_EN_SLICE_Msk 0x400UL
#define HPPASS_INFRA_STARTUP_CFG_CSG_READY_Pos  11UL
#define HPPASS_INFRA_STARTUP_CFG_CSG_READY_Msk  0x800UL
/* HPPASS_INFRA.VDDA_STATUS */
#define HPPASS_INFRA_VDDA_STATUS_VDDA_OK_Pos    0UL
#define HPPASS_INFRA_VDDA_STATUS_VDDA_OK_Msk    0x1UL
/* HPPASS_INFRA.ANA_CTRL */
#define HPPASS_INFRA_ANA_CTRL_FORCE_POR_0_Pos   0UL
#define HPPASS_INFRA_ANA_CTRL_FORCE_POR_0_Msk   0x1UL
#define HPPASS_INFRA_ANA_CTRL_FORCE_POR_1_Pos   1UL
#define HPPASS_INFRA_ANA_CTRL_FORCE_POR_1_Msk   0x2UL
#define HPPASS_INFRA_ANA_CTRL_FORCE_OVERLOAD_EN_0_Pos 2UL
#define HPPASS_INFRA_ANA_CTRL_FORCE_OVERLOAD_EN_0_Msk 0x4UL
#define HPPASS_INFRA_ANA_CTRL_FORCE_OVERLOAD_EN_1_Pos 3UL
#define HPPASS_INFRA_ANA_CTRL_FORCE_OVERLOAD_EN_1_Msk 0x8UL
/* HPPASS_INFRA.VREF_TRIM0 */
#define HPPASS_INFRA_VREF_TRIM0_VREF_ABS_TRIM_Pos 0UL
#define HPPASS_INFRA_VREF_TRIM0_VREF_ABS_TRIM_Msk 0xFFUL
/* HPPASS_INFRA.VREF_TRIM1 */
#define HPPASS_INFRA_VREF_TRIM1_VREF_TEMPCO_TRIM_Pos 0UL
#define HPPASS_INFRA_VREF_TRIM1_VREF_TEMPCO_TRIM_Msk 0xFFUL
/* HPPASS_INFRA.VREF_TRIM2 */
#define HPPASS_INFRA_VREF_TRIM2_VREF_CURV_TRIM_Pos 0UL
#define HPPASS_INFRA_VREF_TRIM2_VREF_CURV_TRIM_Msk 0xFFUL
/* HPPASS_INFRA.VREF_TRIM3 */
#define HPPASS_INFRA_VREF_TRIM3_VREF_ATTEN_TRIM_Pos 0UL
#define HPPASS_INFRA_VREF_TRIM3_VREF_ATTEN_TRIM_Msk 0xFUL
/* HPPASS_INFRA.IZTAT_TRIM0 */
#define HPPASS_INFRA_IZTAT_TRIM0_IZTAT_ABS_TRIM_Pos 0UL
#define HPPASS_INFRA_IZTAT_TRIM0_IZTAT_ABS_TRIM_Msk 0xFFUL
/* HPPASS_INFRA.IZTAT_TRIM1 */
#define HPPASS_INFRA_IZTAT_TRIM1_IZTAT_TC_TRIM_Pos 0UL
#define HPPASS_INFRA_IZTAT_TRIM1_IZTAT_TC_TRIM_Msk 0xFFUL
/* HPPASS_INFRA.IPTAT_TRIM0 */
#define HPPASS_INFRA_IPTAT_TRIM0_IPTAT_CORE_TRIM_Pos 0UL
#define HPPASS_INFRA_IPTAT_TRIM0_IPTAT_CORE_TRIM_Msk 0xFUL
#define HPPASS_INFRA_IPTAT_TRIM0_IPTAT_CTBM_TRIM_Pos 4UL
#define HPPASS_INFRA_IPTAT_TRIM0_IPTAT_CTBM_TRIM_Msk 0xF0UL
/* HPPASS_INFRA.ICTAT_TRIM0 */
#define HPPASS_INFRA_ICTAT_TRIM0_ICTAT_TRIM_Pos 0UL
#define HPPASS_INFRA_ICTAT_TRIM0_ICTAT_TRIM_Msk 0xFUL


/* HPPASS_MMIO_FIFO.CFG */
#define HPPASS_MMIO_FIFO_CFG_SEL_Pos            0UL
#define HPPASS_MMIO_FIFO_CFG_SEL_Msk            0x3UL
#define HPPASS_MMIO_FIFO_CFG_FIFO_TR_EN_Pos     4UL
#define HPPASS_MMIO_FIFO_CFG_FIFO_TR_EN_Msk     0xF0UL
/* HPPASS_MMIO_FIFO.CLR */
#define HPPASS_MMIO_FIFO_CLR_CLR_Pos            0UL
#define HPPASS_MMIO_FIFO_CLR_CLR_Msk            0xFUL
/* HPPASS_MMIO_FIFO.LEVEL */
#define HPPASS_MMIO_FIFO_LEVEL_LEVEL_Pos        0UL
#define HPPASS_MMIO_FIFO_LEVEL_LEVEL_Msk        0x1FUL
/* HPPASS_MMIO_FIFO.RD_DATA */
#define HPPASS_MMIO_FIFO_RD_DATA_RESULT_Pos     0UL
#define HPPASS_MMIO_FIFO_RD_DATA_RESULT_Msk     0x1FFFFFUL
/* HPPASS_MMIO_FIFO.USED */
#define HPPASS_MMIO_FIFO_USED_USED_Pos          0UL
#define HPPASS_MMIO_FIFO_USED_USED_Msk          0x3FUL
/* HPPASS_MMIO_FIFO.STATUS */
#define HPPASS_MMIO_FIFO_STATUS_RD_PTR_Pos      0UL
#define HPPASS_MMIO_FIFO_STATUS_RD_PTR_Msk      0x1FUL
#define HPPASS_MMIO_FIFO_STATUS_WR_PTR_Pos      16UL
#define HPPASS_MMIO_FIFO_STATUS_WR_PTR_Msk      0x1F0000UL


/* HPPASS_MMIO.FIFO_INTR */
#define HPPASS_MMIO_FIFO_INTR_FIFO_LEVEL_Pos    0UL
#define HPPASS_MMIO_FIFO_INTR_FIFO_LEVEL_Msk    0xFUL
/* HPPASS_MMIO.FIFO_INTR_SET */
#define HPPASS_MMIO_FIFO_INTR_SET_FIFO_LEVEL_SET_Pos 0UL
#define HPPASS_MMIO_FIFO_INTR_SET_FIFO_LEVEL_SET_Msk 0xFUL
/* HPPASS_MMIO.FIFO_INTR_MASK */
#define HPPASS_MMIO_FIFO_INTR_MASK_FIFO_LEVEL_MASK_Pos 0UL
#define HPPASS_MMIO_FIFO_INTR_MASK_FIFO_LEVEL_MASK_Msk 0xFUL
/* HPPASS_MMIO.FIFO_INTR_MASKED */
#define HPPASS_MMIO_FIFO_INTR_MASKED_FIFO_LEVEL_MASKED_Pos 0UL
#define HPPASS_MMIO_FIFO_INTR_MASKED_FIFO_LEVEL_MASKED_Msk 0xFUL
/* HPPASS_MMIO.HPPASS_INTR */
#define HPPASS_MMIO_HPPASS_INTR_FIFO_OVERFLOW_Pos 0UL
#define HPPASS_MMIO_HPPASS_INTR_FIFO_OVERFLOW_Msk 0xFUL
#define HPPASS_MMIO_HPPASS_INTR_FIFO_UNDERFLOW_Pos 4UL
#define HPPASS_MMIO_HPPASS_INTR_FIFO_UNDERFLOW_Msk 0xF0UL
#define HPPASS_MMIO_HPPASS_INTR_RESULT_OVERFLOW_Pos 8UL
#define HPPASS_MMIO_HPPASS_INTR_RESULT_OVERFLOW_Msk 0x100UL
#define HPPASS_MMIO_HPPASS_INTR_ENTRY_TR_COLLISION_Pos 9UL
#define HPPASS_MMIO_HPPASS_INTR_ENTRY_TR_COLLISION_Msk 0x200UL
#define HPPASS_MMIO_HPPASS_INTR_ENTRY_HOLD_VIOLATION_Pos 10UL
#define HPPASS_MMIO_HPPASS_INTR_ENTRY_HOLD_VIOLATION_Msk 0x400UL
#define HPPASS_MMIO_HPPASS_INTR_AC_INT_Pos      12UL
#define HPPASS_MMIO_HPPASS_INTR_AC_INT_Msk      0x1000UL
/* HPPASS_MMIO.HPPASS_INTR_SET */
#define HPPASS_MMIO_HPPASS_INTR_SET_FIFO_OVERFLOW_SET_Pos 0UL
#define HPPASS_MMIO_HPPASS_INTR_SET_FIFO_OVERFLOW_SET_Msk 0xFUL
#define HPPASS_MMIO_HPPASS_INTR_SET_FIFO_UNDERFLOW_SET_Pos 4UL
#define HPPASS_MMIO_HPPASS_INTR_SET_FIFO_UNDERFLOW_SET_Msk 0xF0UL
#define HPPASS_MMIO_HPPASS_INTR_SET_RESULT_OVERFLOW_SET_Pos 8UL
#define HPPASS_MMIO_HPPASS_INTR_SET_RESULT_OVERFLOW_SET_Msk 0x100UL
#define HPPASS_MMIO_HPPASS_INTR_SET_ENTRY_TR_COLLISION_SET_Pos 9UL
#define HPPASS_MMIO_HPPASS_INTR_SET_ENTRY_TR_COLLISION_SET_Msk 0x200UL
#define HPPASS_MMIO_HPPASS_INTR_SET_ENTRY_HOLD_VIOLATION_SET_Pos 10UL
#define HPPASS_MMIO_HPPASS_INTR_SET_ENTRY_HOLD_VIOLATION_SET_Msk 0x400UL
#define HPPASS_MMIO_HPPASS_INTR_SET_AC_INT_SET_Pos 12UL
#define HPPASS_MMIO_HPPASS_INTR_SET_AC_INT_SET_Msk 0x1000UL
/* HPPASS_MMIO.HPPASS_INTR_MASK */
#define HPPASS_MMIO_HPPASS_INTR_MASK_FIFO_OVERFLOW_MASK_Pos 0UL
#define HPPASS_MMIO_HPPASS_INTR_MASK_FIFO_OVERFLOW_MASK_Msk 0xFUL
#define HPPASS_MMIO_HPPASS_INTR_MASK_FIFO_UNDERFLOW_MASK_Pos 4UL
#define HPPASS_MMIO_HPPASS_INTR_MASK_FIFO_UNDERFLOW_MASK_Msk 0xF0UL
#define HPPASS_MMIO_HPPASS_INTR_MASK_RESULT_OVERFLOW_MASK_Pos 8UL
#define HPPASS_MMIO_HPPASS_INTR_MASK_RESULT_OVERFLOW_MASK_Msk 0x100UL
#define HPPASS_MMIO_HPPASS_INTR_MASK_ENTRY_TR_COLLISION_MASK_Pos 9UL
#define HPPASS_MMIO_HPPASS_INTR_MASK_ENTRY_TR_COLLISION_MASK_Msk 0x200UL
#define HPPASS_MMIO_HPPASS_INTR_MASK_ENTRY_HOLD_VIOLATION_MASK_Pos 10UL
#define HPPASS_MMIO_HPPASS_INTR_MASK_ENTRY_HOLD_VIOLATION_MASK_Msk 0x400UL
#define HPPASS_MMIO_HPPASS_INTR_MASK_AC_INT_MASK_Pos 12UL
#define HPPASS_MMIO_HPPASS_INTR_MASK_AC_INT_MASK_Msk 0x1000UL
/* HPPASS_MMIO.HPPASS_INTR_MASKED */
#define HPPASS_MMIO_HPPASS_INTR_MASKED_FIFO_OVERFLOW_MASKED_Pos 0UL
#define HPPASS_MMIO_HPPASS_INTR_MASKED_FIFO_OVERFLOW_MASKED_Msk 0xFUL
#define HPPASS_MMIO_HPPASS_INTR_MASKED_FIFO_UNDERFLOW_MASKED_Pos 4UL
#define HPPASS_MMIO_HPPASS_INTR_MASKED_FIFO_UNDERFLOW_MASKED_Msk 0xF0UL
#define HPPASS_MMIO_HPPASS_INTR_MASKED_RESULT_OVERFLOW_MASKED_Pos 8UL
#define HPPASS_MMIO_HPPASS_INTR_MASKED_RESULT_OVERFLOW_MASKED_Msk 0x100UL
#define HPPASS_MMIO_HPPASS_INTR_MASKED_ENTRY_TR_COLLISION_MASKED_Pos 9UL
#define HPPASS_MMIO_HPPASS_INTR_MASKED_ENTRY_TR_COLLISION_MASKED_Msk 0x200UL
#define HPPASS_MMIO_HPPASS_INTR_MASKED_ENTRY_HOLD_VIOLATION_MASKED_Pos 10UL
#define HPPASS_MMIO_HPPASS_INTR_MASKED_ENTRY_HOLD_VIOLATION_MASKED_Msk 0x400UL
#define HPPASS_MMIO_HPPASS_INTR_MASKED_AC_INT_MASKED_Pos 12UL
#define HPPASS_MMIO_HPPASS_INTR_MASKED_AC_INT_MASKED_Msk 0x1000UL
/* HPPASS_MMIO.TR_LEVEL_CFG */
#define HPPASS_MMIO_TR_LEVEL_CFG_BYPASS_SYNC_Pos 0UL
#define HPPASS_MMIO_TR_LEVEL_CFG_BYPASS_SYNC_Msk 0xFFUL
/* HPPASS_MMIO.TR_LEVEL_OUT */
#define HPPASS_MMIO_TR_LEVEL_OUT_CMP_TR_Pos     0UL
#define HPPASS_MMIO_TR_LEVEL_OUT_CMP_TR_Msk     0xFFUL
#define HPPASS_MMIO_TR_LEVEL_OUT_SAR_RANGE_TR_Pos 8UL
#define HPPASS_MMIO_TR_LEVEL_OUT_SAR_RANGE_TR_Msk 0xFF00UL
/* HPPASS_MMIO.TR_PULSE_OUT */
#define HPPASS_MMIO_TR_PULSE_OUT_SEL_Pos        0UL
#define HPPASS_MMIO_TR_PULSE_OUT_SEL_Msk        0xFUL


#endif /* _CYIP_HPPASS_H_ */


/* [] END OF FILE */
