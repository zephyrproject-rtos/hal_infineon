/***************************************************************************//**
* \file cyip_gpio_v2.h
*
* \brief
* GPIO IP definitions
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

#ifndef _CYIP_GPIO_V2_H_
#define _CYIP_GPIO_V2_H_

#include "cyip_headers.h"

/*******************************************************************************
*                                     GPIO
*******************************************************************************/

#define GPIO_PRT_SECTION_SIZE                   0x00000100UL
#define GPIO_SECTION_SIZE                       0x00004000UL

/**
  * \brief GPIO port registers (GPIO_PRT)
  */
typedef struct {
  __IOM uint32_t DR;                            /*!< 0x00000000 Port output data register */
   __IM uint32_t PS;                            /*!< 0x00000004 Port IO pad state register */
  __IOM uint32_t PC;                            /*!< 0x00000008 Port configuration register */
  __IOM uint32_t INTR_CFG;                      /*!< 0x0000000C Port interrupt configuration register */
  __IOM uint32_t INTR;                          /*!< 0x00000010 Port interrupt status register */
  __IOM uint32_t SIO;                           /*!< 0x00000014 Port SIO configuration register */
  __IOM uint32_t PC2;                           /*!< 0x00000018 Port configuration register 2 */
   __IM uint32_t RESERVED[9];
  __IOM uint32_t DR_SET;                        /*!< 0x00000040 Port output data set register */
  __IOM uint32_t DR_CLR;                        /*!< 0x00000044 Port output data clear register */
  __IOM uint32_t DR_INV;                        /*!< 0x00000048 Port output data invert register */
  __IOM uint32_t DS;                            /*!< 0x0000004C Port drive strength register */
  __IOM uint32_t FILT_CONFIG;                   /*!< 0x00000050 IO filter config register */
   __IM uint32_t RESERVED1[3];
  __IOM uint32_t DS_1P8_DVC;                    /*!< 0x00000060 GPIO with DVC drive strength adjustment register */
   __IM uint32_t RESERVED2[3];
  __IOM uint32_t DS_1P8_I2C_DVC;                /*!< 0x00000070 I2C with DVC drive strength adjustment register */
   __IM uint32_t RESERVED3[3];
  __IOM uint32_t VREFGEN;                       /*!< 0x00000080 Reference generator configuration register */
   __IM uint32_t RESERVED4[31];
} GPIO_PRT_Type;                                /*!< Size = 256 (0x100) */

/**
  * \brief GPIO port control/configuration (GPIO)
  */
typedef struct {
        GPIO_PRT_Type PRT[16];                  /*!< 0x00000000 GPIO port registers */
   __IM uint32_t INTR_CAUSE;                    /*!< 0x00001000 Interrupt port cause register */
   __IM uint32_t RESERVED[7];
   __IM uint32_t GPIOV1P2_DET;                  /*!< 0x00001020 GPIOV1P2 Detect output */
   __IM uint32_t RESERVED1[2999];
  __IOM uint32_t TRIM;                          /*!< 0x00003F00 TRIMS FOR GPIO and I2C DVC */
} GPIO_Type;                                    /*!< Size = 16132 (0x3F04) */


/* GPIO_PRT.DR */
#define GPIO_PRT_DR_DATA0_Pos                   0UL
#define GPIO_PRT_DR_DATA0_Msk                   0x1UL
#define GPIO_PRT_DR_DATA1_Pos                   1UL
#define GPIO_PRT_DR_DATA1_Msk                   0x2UL
#define GPIO_PRT_DR_DATA2_Pos                   2UL
#define GPIO_PRT_DR_DATA2_Msk                   0x4UL
#define GPIO_PRT_DR_DATA3_Pos                   3UL
#define GPIO_PRT_DR_DATA3_Msk                   0x8UL
#define GPIO_PRT_DR_DATA4_Pos                   4UL
#define GPIO_PRT_DR_DATA4_Msk                   0x10UL
#define GPIO_PRT_DR_DATA5_Pos                   5UL
#define GPIO_PRT_DR_DATA5_Msk                   0x20UL
#define GPIO_PRT_DR_DATA6_Pos                   6UL
#define GPIO_PRT_DR_DATA6_Msk                   0x40UL
#define GPIO_PRT_DR_DATA7_Pos                   7UL
#define GPIO_PRT_DR_DATA7_Msk                   0x80UL
/* GPIO_PRT.PS */
#define GPIO_PRT_PS_DATA0_Pos                   0UL
#define GPIO_PRT_PS_DATA0_Msk                   0x1UL
#define GPIO_PRT_PS_DATA1_Pos                   1UL
#define GPIO_PRT_PS_DATA1_Msk                   0x2UL
#define GPIO_PRT_PS_DATA2_Pos                   2UL
#define GPIO_PRT_PS_DATA2_Msk                   0x4UL
#define GPIO_PRT_PS_DATA3_Pos                   3UL
#define GPIO_PRT_PS_DATA3_Msk                   0x8UL
#define GPIO_PRT_PS_DATA4_Pos                   4UL
#define GPIO_PRT_PS_DATA4_Msk                   0x10UL
#define GPIO_PRT_PS_DATA5_Pos                   5UL
#define GPIO_PRT_PS_DATA5_Msk                   0x20UL
#define GPIO_PRT_PS_DATA6_Pos                   6UL
#define GPIO_PRT_PS_DATA6_Msk                   0x40UL
#define GPIO_PRT_PS_DATA7_Pos                   7UL
#define GPIO_PRT_PS_DATA7_Msk                   0x80UL
#define GPIO_PRT_PS_FLT_DATA_Pos                8UL
#define GPIO_PRT_PS_FLT_DATA_Msk                0x100UL
/* GPIO_PRT.PC */
#define GPIO_PRT_PC_DM0_Pos                     0UL
#define GPIO_PRT_PC_DM0_Msk                     0x7UL
#define GPIO_PRT_PC_DM1_Pos                     3UL
#define GPIO_PRT_PC_DM1_Msk                     0x38UL
#define GPIO_PRT_PC_DM2_Pos                     6UL
#define GPIO_PRT_PC_DM2_Msk                     0x1C0UL
#define GPIO_PRT_PC_DM3_Pos                     9UL
#define GPIO_PRT_PC_DM3_Msk                     0xE00UL
#define GPIO_PRT_PC_DM4_Pos                     12UL
#define GPIO_PRT_PC_DM4_Msk                     0x7000UL
#define GPIO_PRT_PC_DM5_Pos                     15UL
#define GPIO_PRT_PC_DM5_Msk                     0x38000UL
#define GPIO_PRT_PC_DM6_Pos                     18UL
#define GPIO_PRT_PC_DM6_Msk                     0x1C0000UL
#define GPIO_PRT_PC_DM7_Pos                     21UL
#define GPIO_PRT_PC_DM7_Msk                     0xE00000UL
#define GPIO_PRT_PC_PORT_VTRIP_SEL_Pos          24UL
#define GPIO_PRT_PC_PORT_VTRIP_SEL_Msk          0x1000000UL
#define GPIO_PRT_PC_PORT_SLOW_Pos               25UL
#define GPIO_PRT_PC_PORT_SLOW_Msk               0x2000000UL
#define GPIO_PRT_PC_PORT_HYST_TRIM_Pos          27UL
#define GPIO_PRT_PC_PORT_HYST_TRIM_Msk          0x8000000UL
#define GPIO_PRT_PC_PORT_SLEW_CTL_Pos           28UL
#define GPIO_PRT_PC_PORT_SLEW_CTL_Msk           0x30000000UL
#define GPIO_PRT_PC_PORT_IB_MODE_SEL_Pos        30UL
#define GPIO_PRT_PC_PORT_IB_MODE_SEL_Msk        0xC0000000UL
/* GPIO_PRT.INTR_CFG */
#define GPIO_PRT_INTR_CFG_EDGE0_SEL_Pos         0UL
#define GPIO_PRT_INTR_CFG_EDGE0_SEL_Msk         0x3UL
#define GPIO_PRT_INTR_CFG_EDGE1_SEL_Pos         2UL
#define GPIO_PRT_INTR_CFG_EDGE1_SEL_Msk         0xCUL
#define GPIO_PRT_INTR_CFG_EDGE2_SEL_Pos         4UL
#define GPIO_PRT_INTR_CFG_EDGE2_SEL_Msk         0x30UL
#define GPIO_PRT_INTR_CFG_EDGE3_SEL_Pos         6UL
#define GPIO_PRT_INTR_CFG_EDGE3_SEL_Msk         0xC0UL
#define GPIO_PRT_INTR_CFG_EDGE4_SEL_Pos         8UL
#define GPIO_PRT_INTR_CFG_EDGE4_SEL_Msk         0x300UL
#define GPIO_PRT_INTR_CFG_EDGE5_SEL_Pos         10UL
#define GPIO_PRT_INTR_CFG_EDGE5_SEL_Msk         0xC00UL
#define GPIO_PRT_INTR_CFG_EDGE6_SEL_Pos         12UL
#define GPIO_PRT_INTR_CFG_EDGE6_SEL_Msk         0x3000UL
#define GPIO_PRT_INTR_CFG_EDGE7_SEL_Pos         14UL
#define GPIO_PRT_INTR_CFG_EDGE7_SEL_Msk         0xC000UL
#define GPIO_PRT_INTR_CFG_FLT_EDGE_SEL_Pos      16UL
#define GPIO_PRT_INTR_CFG_FLT_EDGE_SEL_Msk      0x30000UL
#define GPIO_PRT_INTR_CFG_FLT_SEL_Pos           18UL
#define GPIO_PRT_INTR_CFG_FLT_SEL_Msk           0x1C0000UL
/* GPIO_PRT.INTR */
#define GPIO_PRT_INTR_DATA0_Pos                 0UL
#define GPIO_PRT_INTR_DATA0_Msk                 0x1UL
#define GPIO_PRT_INTR_DATA1_Pos                 1UL
#define GPIO_PRT_INTR_DATA1_Msk                 0x2UL
#define GPIO_PRT_INTR_DATA2_Pos                 2UL
#define GPIO_PRT_INTR_DATA2_Msk                 0x4UL
#define GPIO_PRT_INTR_DATA3_Pos                 3UL
#define GPIO_PRT_INTR_DATA3_Msk                 0x8UL
#define GPIO_PRT_INTR_DATA4_Pos                 4UL
#define GPIO_PRT_INTR_DATA4_Msk                 0x10UL
#define GPIO_PRT_INTR_DATA5_Pos                 5UL
#define GPIO_PRT_INTR_DATA5_Msk                 0x20UL
#define GPIO_PRT_INTR_DATA6_Pos                 6UL
#define GPIO_PRT_INTR_DATA6_Msk                 0x40UL
#define GPIO_PRT_INTR_DATA7_Pos                 7UL
#define GPIO_PRT_INTR_DATA7_Msk                 0x80UL
#define GPIO_PRT_INTR_FLT_DATA_Pos              8UL
#define GPIO_PRT_INTR_FLT_DATA_Msk              0x100UL
#define GPIO_PRT_INTR_PS_DATA0_Pos              16UL
#define GPIO_PRT_INTR_PS_DATA0_Msk              0x10000UL
#define GPIO_PRT_INTR_PS_DATA1_Pos              17UL
#define GPIO_PRT_INTR_PS_DATA1_Msk              0x20000UL
#define GPIO_PRT_INTR_PS_DATA2_Pos              18UL
#define GPIO_PRT_INTR_PS_DATA2_Msk              0x40000UL
#define GPIO_PRT_INTR_PS_DATA3_Pos              19UL
#define GPIO_PRT_INTR_PS_DATA3_Msk              0x80000UL
#define GPIO_PRT_INTR_PS_DATA4_Pos              20UL
#define GPIO_PRT_INTR_PS_DATA4_Msk              0x100000UL
#define GPIO_PRT_INTR_PS_DATA5_Pos              21UL
#define GPIO_PRT_INTR_PS_DATA5_Msk              0x200000UL
#define GPIO_PRT_INTR_PS_DATA6_Pos              22UL
#define GPIO_PRT_INTR_PS_DATA6_Msk              0x400000UL
#define GPIO_PRT_INTR_PS_DATA7_Pos              23UL
#define GPIO_PRT_INTR_PS_DATA7_Msk              0x800000UL
#define GPIO_PRT_INTR_PS_FLT_DATA_Pos           24UL
#define GPIO_PRT_INTR_PS_FLT_DATA_Msk           0x1000000UL
/* GPIO_PRT.SIO */
#define GPIO_PRT_SIO_PAIR_VREG01_EN_Pos         0UL
#define GPIO_PRT_SIO_PAIR_VREG01_EN_Msk         0x1UL
#define GPIO_PRT_SIO_PAIR_IBUF01_SEL_Pos        1UL
#define GPIO_PRT_SIO_PAIR_IBUF01_SEL_Msk        0x2UL
#define GPIO_PRT_SIO_PAIR_VTRIP01_SEL_Pos       2UL
#define GPIO_PRT_SIO_PAIR_VTRIP01_SEL_Msk       0x4UL
#define GPIO_PRT_SIO_PAIR_VREF01_SEL_Pos        3UL
#define GPIO_PRT_SIO_PAIR_VREF01_SEL_Msk        0x18UL
#define GPIO_PRT_SIO_PAIR_VOH01_SEL_Pos         5UL
#define GPIO_PRT_SIO_PAIR_VOH01_SEL_Msk         0xE0UL
#define GPIO_PRT_SIO_PAIR_VREG23_EN_Pos         8UL
#define GPIO_PRT_SIO_PAIR_VREG23_EN_Msk         0x100UL
#define GPIO_PRT_SIO_PAIR_IBUF23_SEL_Pos        9UL
#define GPIO_PRT_SIO_PAIR_IBUF23_SEL_Msk        0x200UL
#define GPIO_PRT_SIO_PAIR_VTRIP23_SEL_Pos       10UL
#define GPIO_PRT_SIO_PAIR_VTRIP23_SEL_Msk       0x400UL
#define GPIO_PRT_SIO_PAIR_VREF23_SEL_Pos        11UL
#define GPIO_PRT_SIO_PAIR_VREF23_SEL_Msk        0x1800UL
#define GPIO_PRT_SIO_PAIR_VOH23_SEL_Pos         13UL
#define GPIO_PRT_SIO_PAIR_VOH23_SEL_Msk         0xE000UL
#define GPIO_PRT_SIO_PAIR_VREG45_EN_Pos         16UL
#define GPIO_PRT_SIO_PAIR_VREG45_EN_Msk         0x10000UL
#define GPIO_PRT_SIO_PAIR_IBUF45_SEL_Pos        17UL
#define GPIO_PRT_SIO_PAIR_IBUF45_SEL_Msk        0x20000UL
#define GPIO_PRT_SIO_PAIR_VTRIP45_SEL_Pos       18UL
#define GPIO_PRT_SIO_PAIR_VTRIP45_SEL_Msk       0x40000UL
#define GPIO_PRT_SIO_PAIR_VREF45_SEL_Pos        19UL
#define GPIO_PRT_SIO_PAIR_VREF45_SEL_Msk        0x180000UL
#define GPIO_PRT_SIO_PAIR_VOH45_SEL_Pos         21UL
#define GPIO_PRT_SIO_PAIR_VOH45_SEL_Msk         0xE00000UL
#define GPIO_PRT_SIO_PAIR_VREG67_EN_Pos         24UL
#define GPIO_PRT_SIO_PAIR_VREG67_EN_Msk         0x1000000UL
#define GPIO_PRT_SIO_PAIR_IBUF67_SEL_Pos        25UL
#define GPIO_PRT_SIO_PAIR_IBUF67_SEL_Msk        0x2000000UL
#define GPIO_PRT_SIO_PAIR_VTRIP67_SEL_Pos       26UL
#define GPIO_PRT_SIO_PAIR_VTRIP67_SEL_Msk       0x4000000UL
#define GPIO_PRT_SIO_PAIR_VREF67_SEL_Pos        27UL
#define GPIO_PRT_SIO_PAIR_VREF67_SEL_Msk        0x18000000UL
#define GPIO_PRT_SIO_PAIR_VOH67_SEL_Pos         29UL
#define GPIO_PRT_SIO_PAIR_VOH67_SEL_Msk         0xE0000000UL
/* GPIO_PRT.PC2 */
#define GPIO_PRT_PC2_INP_DIS0_Pos               0UL
#define GPIO_PRT_PC2_INP_DIS0_Msk               0x1UL
#define GPIO_PRT_PC2_INP_DIS1_Pos               1UL
#define GPIO_PRT_PC2_INP_DIS1_Msk               0x2UL
#define GPIO_PRT_PC2_INP_DIS2_Pos               2UL
#define GPIO_PRT_PC2_INP_DIS2_Msk               0x4UL
#define GPIO_PRT_PC2_INP_DIS3_Pos               3UL
#define GPIO_PRT_PC2_INP_DIS3_Msk               0x8UL
#define GPIO_PRT_PC2_INP_DIS4_Pos               4UL
#define GPIO_PRT_PC2_INP_DIS4_Msk               0x10UL
#define GPIO_PRT_PC2_INP_DIS5_Pos               5UL
#define GPIO_PRT_PC2_INP_DIS5_Msk               0x20UL
#define GPIO_PRT_PC2_INP_DIS6_Pos               6UL
#define GPIO_PRT_PC2_INP_DIS6_Msk               0x40UL
#define GPIO_PRT_PC2_INP_DIS7_Pos               7UL
#define GPIO_PRT_PC2_INP_DIS7_Msk               0x80UL
/* GPIO_PRT.DR_SET */
#define GPIO_PRT_DR_SET_DATA_Pos                0UL
#define GPIO_PRT_DR_SET_DATA_Msk                0xFFUL
/* GPIO_PRT.DR_CLR */
#define GPIO_PRT_DR_CLR_DATA_Pos                0UL
#define GPIO_PRT_DR_CLR_DATA_Msk                0xFFUL
/* GPIO_PRT.DR_INV */
#define GPIO_PRT_DR_INV_DATA_Pos                0UL
#define GPIO_PRT_DR_INV_DATA_Msk                0xFFUL
/* GPIO_PRT.DS */
#define GPIO_PRT_DS_DS0_Pos                     0UL
#define GPIO_PRT_DS_DS0_Msk                     0x3UL
#define GPIO_PRT_DS_DS1_Pos                     2UL
#define GPIO_PRT_DS_DS1_Msk                     0xCUL
#define GPIO_PRT_DS_DS2_Pos                     4UL
#define GPIO_PRT_DS_DS2_Msk                     0x30UL
#define GPIO_PRT_DS_DS3_Pos                     6UL
#define GPIO_PRT_DS_DS3_Msk                     0xC0UL
#define GPIO_PRT_DS_DS4_Pos                     8UL
#define GPIO_PRT_DS_DS4_Msk                     0x300UL
#define GPIO_PRT_DS_DS5_Pos                     10UL
#define GPIO_PRT_DS_DS5_Msk                     0xC00UL
#define GPIO_PRT_DS_DS6_Pos                     12UL
#define GPIO_PRT_DS_DS6_Msk                     0x3000UL
#define GPIO_PRT_DS_DS7_Pos                     14UL
#define GPIO_PRT_DS_DS7_Msk                     0xC000UL
#define GPIO_PRT_DS_PORT_V1P2_VTRIP_SEL_Pos     16UL
#define GPIO_PRT_DS_PORT_V1P2_VTRIP_SEL_Msk     0x10000UL
#define GPIO_PRT_DS_PORT_V1P2_IB_MODE_SEL_Pos   17UL
#define GPIO_PRT_DS_PORT_V1P2_IB_MODE_SEL_Msk   0x20000UL
/* GPIO_PRT.FILT_CONFIG */
#define GPIO_PRT_FILT_CONFIG_TRIM0_Pos          0UL
#define GPIO_PRT_FILT_CONFIG_TRIM0_Msk          0x3UL
#define GPIO_PRT_FILT_CONFIG_TRIM1_Pos          2UL
#define GPIO_PRT_FILT_CONFIG_TRIM1_Msk          0xCUL
#define GPIO_PRT_FILT_CONFIG_TRIM2_Pos          4UL
#define GPIO_PRT_FILT_CONFIG_TRIM2_Msk          0x30UL
#define GPIO_PRT_FILT_CONFIG_TRIM3_Pos          6UL
#define GPIO_PRT_FILT_CONFIG_TRIM3_Msk          0xC0UL
#define GPIO_PRT_FILT_CONFIG_TRIM4_Pos          8UL
#define GPIO_PRT_FILT_CONFIG_TRIM4_Msk          0x300UL
#define GPIO_PRT_FILT_CONFIG_TRIM5_Pos          10UL
#define GPIO_PRT_FILT_CONFIG_TRIM5_Msk          0xC00UL
#define GPIO_PRT_FILT_CONFIG_TRIM6_Pos          12UL
#define GPIO_PRT_FILT_CONFIG_TRIM6_Msk          0x3000UL
#define GPIO_PRT_FILT_CONFIG_TRIM7_Pos          14UL
#define GPIO_PRT_FILT_CONFIG_TRIM7_Msk          0xC000UL
#define GPIO_PRT_FILT_CONFIG_FILT0_EN_Pos       16UL
#define GPIO_PRT_FILT_CONFIG_FILT0_EN_Msk       0x10000UL
#define GPIO_PRT_FILT_CONFIG_FILT1_EN_Pos       17UL
#define GPIO_PRT_FILT_CONFIG_FILT1_EN_Msk       0x20000UL
#define GPIO_PRT_FILT_CONFIG_FILT2_EN_Pos       18UL
#define GPIO_PRT_FILT_CONFIG_FILT2_EN_Msk       0x40000UL
#define GPIO_PRT_FILT_CONFIG_FILT3_EN_Pos       19UL
#define GPIO_PRT_FILT_CONFIG_FILT3_EN_Msk       0x80000UL
#define GPIO_PRT_FILT_CONFIG_FILT4_EN_Pos       20UL
#define GPIO_PRT_FILT_CONFIG_FILT4_EN_Msk       0x100000UL
#define GPIO_PRT_FILT_CONFIG_FILT5_EN_Pos       21UL
#define GPIO_PRT_FILT_CONFIG_FILT5_EN_Msk       0x200000UL
#define GPIO_PRT_FILT_CONFIG_FILT6_EN_Pos       22UL
#define GPIO_PRT_FILT_CONFIG_FILT6_EN_Msk       0x400000UL
#define GPIO_PRT_FILT_CONFIG_FILT7_EN_Pos       23UL
#define GPIO_PRT_FILT_CONFIG_FILT7_EN_Msk       0x800000UL
/* GPIO_PRT.DS_1P8_DVC */
#define GPIO_PRT_DS_1P8_DVC_DS0_Pos             0UL
#define GPIO_PRT_DS_1P8_DVC_DS0_Msk             0x3UL
#define GPIO_PRT_DS_1P8_DVC_DS1_Pos             2UL
#define GPIO_PRT_DS_1P8_DVC_DS1_Msk             0xCUL
#define GPIO_PRT_DS_1P8_DVC_DS2_Pos             4UL
#define GPIO_PRT_DS_1P8_DVC_DS2_Msk             0x30UL
#define GPIO_PRT_DS_1P8_DVC_DS3_Pos             6UL
#define GPIO_PRT_DS_1P8_DVC_DS3_Msk             0xC0UL
#define GPIO_PRT_DS_1P8_DVC_DS4_Pos             8UL
#define GPIO_PRT_DS_1P8_DVC_DS4_Msk             0x300UL
#define GPIO_PRT_DS_1P8_DVC_DS5_Pos             10UL
#define GPIO_PRT_DS_1P8_DVC_DS5_Msk             0xC00UL
#define GPIO_PRT_DS_1P8_DVC_DS6_Pos             12UL
#define GPIO_PRT_DS_1P8_DVC_DS6_Msk             0x3000UL
#define GPIO_PRT_DS_1P8_DVC_DS7_Pos             14UL
#define GPIO_PRT_DS_1P8_DVC_DS7_Msk             0xC000UL
#define GPIO_PRT_DS_1P8_DVC_INPUT_WEAK_RESISTOR_PU0_Pos 16UL
#define GPIO_PRT_DS_1P8_DVC_INPUT_WEAK_RESISTOR_PU0_Msk 0x10000UL
#define GPIO_PRT_DS_1P8_DVC_INPUT_WEAK_RESISTOR_PU1_Pos 17UL
#define GPIO_PRT_DS_1P8_DVC_INPUT_WEAK_RESISTOR_PU1_Msk 0x20000UL
#define GPIO_PRT_DS_1P8_DVC_INPUT_WEAK_RESISTOR_PU2_Pos 18UL
#define GPIO_PRT_DS_1P8_DVC_INPUT_WEAK_RESISTOR_PU2_Msk 0x40000UL
#define GPIO_PRT_DS_1P8_DVC_INPUT_WEAK_RESISTOR_PU3_Pos 19UL
#define GPIO_PRT_DS_1P8_DVC_INPUT_WEAK_RESISTOR_PU3_Msk 0x80000UL
#define GPIO_PRT_DS_1P8_DVC_INPUT_WEAK_RESISTOR_PU4_Pos 20UL
#define GPIO_PRT_DS_1P8_DVC_INPUT_WEAK_RESISTOR_PU4_Msk 0x100000UL
#define GPIO_PRT_DS_1P8_DVC_INPUT_WEAK_RESISTOR_PU5_Pos 21UL
#define GPIO_PRT_DS_1P8_DVC_INPUT_WEAK_RESISTOR_PU5_Msk 0x200000UL
#define GPIO_PRT_DS_1P8_DVC_INPUT_WEAK_RESISTOR_PU6_Pos 22UL
#define GPIO_PRT_DS_1P8_DVC_INPUT_WEAK_RESISTOR_PU6_Msk 0x400000UL
#define GPIO_PRT_DS_1P8_DVC_INPUT_WEAK_RESISTOR_PU7_Pos 23UL
#define GPIO_PRT_DS_1P8_DVC_INPUT_WEAK_RESISTOR_PU7_Msk 0x800000UL
#define GPIO_PRT_DS_1P8_DVC_PORT_GPIO_DVC_VTRIP_SEL_Pos 24UL
#define GPIO_PRT_DS_1P8_DVC_PORT_GPIO_DVC_VTRIP_SEL_Msk 0x1000000UL
/* GPIO_PRT.DS_1P8_I2C_DVC */
#define GPIO_PRT_DS_1P8_I2C_DVC_DS0_Pos         0UL
#define GPIO_PRT_DS_1P8_I2C_DVC_DS0_Msk         0x3UL
#define GPIO_PRT_DS_1P8_I2C_DVC_DS1_Pos         2UL
#define GPIO_PRT_DS_1P8_I2C_DVC_DS1_Msk         0xCUL
#define GPIO_PRT_DS_1P8_I2C_DVC_DS2_Pos         4UL
#define GPIO_PRT_DS_1P8_I2C_DVC_DS2_Msk         0x30UL
#define GPIO_PRT_DS_1P8_I2C_DVC_DS3_Pos         6UL
#define GPIO_PRT_DS_1P8_I2C_DVC_DS3_Msk         0xC0UL
#define GPIO_PRT_DS_1P8_I2C_DVC_DS4_Pos         8UL
#define GPIO_PRT_DS_1P8_I2C_DVC_DS4_Msk         0x300UL
#define GPIO_PRT_DS_1P8_I2C_DVC_DS5_Pos         10UL
#define GPIO_PRT_DS_1P8_I2C_DVC_DS5_Msk         0xC00UL
#define GPIO_PRT_DS_1P8_I2C_DVC_DS6_Pos         12UL
#define GPIO_PRT_DS_1P8_I2C_DVC_DS6_Msk         0x3000UL
#define GPIO_PRT_DS_1P8_I2C_DVC_DS7_Pos         14UL
#define GPIO_PRT_DS_1P8_I2C_DVC_DS7_Msk         0xC000UL
#define GPIO_PRT_DS_1P8_I2C_DVC_INPUT_WEAK_RESISTOR_PU0_Pos 16UL
#define GPIO_PRT_DS_1P8_I2C_DVC_INPUT_WEAK_RESISTOR_PU0_Msk 0x10000UL
#define GPIO_PRT_DS_1P8_I2C_DVC_INPUT_WEAK_RESISTOR_PU1_Pos 17UL
#define GPIO_PRT_DS_1P8_I2C_DVC_INPUT_WEAK_RESISTOR_PU1_Msk 0x20000UL
#define GPIO_PRT_DS_1P8_I2C_DVC_INPUT_WEAK_RESISTOR_PU2_Pos 18UL
#define GPIO_PRT_DS_1P8_I2C_DVC_INPUT_WEAK_RESISTOR_PU2_Msk 0x40000UL
#define GPIO_PRT_DS_1P8_I2C_DVC_INPUT_WEAK_RESISTOR_PU3_Pos 19UL
#define GPIO_PRT_DS_1P8_I2C_DVC_INPUT_WEAK_RESISTOR_PU3_Msk 0x80000UL
#define GPIO_PRT_DS_1P8_I2C_DVC_INPUT_WEAK_RESISTOR_PU4_Pos 20UL
#define GPIO_PRT_DS_1P8_I2C_DVC_INPUT_WEAK_RESISTOR_PU4_Msk 0x100000UL
#define GPIO_PRT_DS_1P8_I2C_DVC_INPUT_WEAK_RESISTOR_PU5_Pos 21UL
#define GPIO_PRT_DS_1P8_I2C_DVC_INPUT_WEAK_RESISTOR_PU5_Msk 0x200000UL
#define GPIO_PRT_DS_1P8_I2C_DVC_INPUT_WEAK_RESISTOR_PU6_Pos 22UL
#define GPIO_PRT_DS_1P8_I2C_DVC_INPUT_WEAK_RESISTOR_PU6_Msk 0x400000UL
#define GPIO_PRT_DS_1P8_I2C_DVC_INPUT_WEAK_RESISTOR_PU7_Pos 23UL
#define GPIO_PRT_DS_1P8_I2C_DVC_INPUT_WEAK_RESISTOR_PU7_Msk 0x800000UL
#define GPIO_PRT_DS_1P8_I2C_DVC_PORT_I2C_DVC_VTRIP_SEL_Pos 24UL
#define GPIO_PRT_DS_1P8_I2C_DVC_PORT_I2C_DVC_VTRIP_SEL_Msk 0x1000000UL
/* GPIO_PRT.VREFGEN */
#define GPIO_PRT_VREFGEN_REF_SEL_Pos            0UL
#define GPIO_PRT_VREFGEN_REF_SEL_Msk            0x1FUL
#define GPIO_PRT_VREFGEN_VREFGEN_EN_Pos         8UL
#define GPIO_PRT_VREFGEN_VREFGEN_EN_Msk         0x100UL


/* GPIO.INTR_CAUSE */
#define GPIO_INTR_CAUSE_PORT_INT_Pos            0UL
#define GPIO_INTR_CAUSE_PORT_INT_Msk            0xFFFFFFFFUL
/* GPIO.GPIOV1P2_DET */
#define GPIO_GPIOV1P2_DET_DET_Pos               0UL
#define GPIO_GPIOV1P2_DET_DET_Msk               0x1UL
/* GPIO.TRIM */
#define GPIO_TRIM_DS_PU_TRIM_Pos                0UL
#define GPIO_TRIM_DS_PU_TRIM_Msk                0x3FUL
#define GPIO_TRIM_DS_PD_TRIM_Pos                6UL
#define GPIO_TRIM_DS_PD_TRIM_Msk                0xFC0UL
#define GPIO_TRIM_DS_PURES_TRIM_Pos             12UL
#define GPIO_TRIM_DS_PURES_TRIM_Msk             0x3F000UL


#endif /* _CYIP_GPIO_V2_H_ */


/* [] END OF FILE */
