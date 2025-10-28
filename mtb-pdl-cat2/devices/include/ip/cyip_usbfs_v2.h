/***************************************************************************//**
* \file cyip_usbfs_v2.h
*
* \brief
* USBFS IP definitions
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

#ifndef _CYIP_USBFS_V2_H_
#define _CYIP_USBFS_V2_H_

#include "cyip_headers.h"

/*******************************************************************************
*                                    USBFS
*******************************************************************************/

#define USBFS_BCD_SECTION_SIZE                  0x00001000UL
#define USBFS_SECTION_SIZE                      0x00010000UL

/**
  * \brief USB Device Controller Battery Charger Detect (USBFS_BCD)
  */
typedef struct {
  __IOM uint32_t POWER_CTRL;                    /*!< 0x00000000 Power Control Register */
  __IOM uint32_t CHGDET_CTRL;                   /*!< 0x00000004 Charger Detection Control Register */
  __IOM uint32_t USBIO_CTRL;                    /*!< 0x00000008 USB IO Control Register */
  __IOM uint32_t FLOW_CTRL;                     /*!< 0x0000000C Flow Control Register */
  __IOM uint32_t LPM_CTRL;                      /*!< 0x00000010 LPM Control Register */
   __IM uint32_t LPM_STAT;                      /*!< 0x00000014 LPM Status register */
   __IM uint32_t RESERVED[2];
  __IOM uint32_t INTR_SIE;                      /*!< 0x00000020 USB SOF, BUS RESET and EP0 Interrupt Status */
  __IOM uint32_t INTR_SIE_SET;                  /*!< 0x00000024 USB SOF, BUS RESET and EP0 Interrupt Set */
  __IOM uint32_t INTR_SIE_MASK;                 /*!< 0x00000028 USB SOF, BUS RESET and EP0 Interrupt Mask */
   __IM uint32_t INTR_SIE_MASKED;               /*!< 0x0000002C USB SOF, BUS RESET and EP0 Interrupt Masked */
  __IOM uint32_t INTR_LVL_SEL;                  /*!< 0x00000030 Select interrupt level for each interrupt source */
   __IM uint32_t INTR_CAUSE_HI;                 /*!< 0x00000034 High priority interrupt Cause register */
   __IM uint32_t INTR_CAUSE_MED;                /*!< 0x00000038 Medium priority interrupt Cause register */
   __IM uint32_t INTR_CAUSE_LO;                 /*!< 0x0000003C Low priority interrupt Cause register */
   __IM uint32_t RESERVED1[12];
  __IOM uint32_t DFT_CTRL;                      /*!< 0x00000070 DFT control */
   __IM uint32_t RESERVED2[931];
  __IOM uint32_t PHY_TRIM0;                     /*!< 0x00000F00 PHY trim control register. */
  __IOM uint32_t PHY_TRIM1;                     /*!< 0x00000F04 PHY trim control register. */
  __IOM uint32_t PHY_TRIM2;                     /*!< 0x00000F08 PHY trim control register. */
  __IOM uint32_t PHY_TRIM3;                     /*!< 0x00000F0C PHY trim control register. */
  __IOM uint32_t CHGDET_TRIM;                   /*!< 0x00000F10 Charger detect trim values */
  __IOM uint32_t TRIM;                          /*!< 0x00000F14 trim values */
  __IOM uint32_t USBIO_TRIM;                    /*!< 0x00000F18 trim values for IOs */
   __IM uint32_t RESERVED3[57];
} USBFS_BCD_Type;                               /*!< Size = 4096 (0x1000) */

/**
  * \brief USB Device Controller (USBFS)
  */
typedef struct {
  __IOM uint32_t EP0_DR[8];                     /*!< 0x00000000 Control End point EP0 Data Register */
  __IOM uint32_t CR0;                           /*!< 0x00000020 USB control 0 Register */
  __IOM uint32_t CR1;                           /*!< 0x00000024 USB control 1 Register */
  __IOM uint32_t SIE_EP_INT_EN;                 /*!< 0x00000028 USB SIE Data Endpoints Interrupt Enable Register */
  __IOM uint32_t SIE_EP_INT_SR;                 /*!< 0x0000002C USB SIE Data Endpoint Interrupt Status */
  __IOM uint32_t SIE_EP1_CNT0;                  /*!< 0x00000030 Non-control endpoint count register */
  __IOM uint32_t SIE_EP1_CNT1;                  /*!< 0x00000034 Non-control endpoint count register */
  __IOM uint32_t SIE_EP1_CR0;                   /*!< 0x00000038 Non-control endpoint's control Register */
   __IM uint32_t RESERVED;
  __IOM uint32_t USBIO_CR0;                     /*!< 0x00000040 USBIO Control 0 Register */
  __IOM uint32_t USBIO_CR2;                     /*!< 0x00000044 USBIO control 2 Register */
  __IOM uint32_t USBIO_CR1;                     /*!< 0x00000048 USBIO control 1 Register */
   __IM uint32_t RESERVED1;
  __IOM uint32_t DYN_RECONFIG;                  /*!< 0x00000050 USB Dynamic reconfiguration register */
   __IM uint32_t RESERVED2[3];
   __IM uint32_t SOF0;                          /*!< 0x00000060 Start Of Frame Register */
   __IM uint32_t SOF1;                          /*!< 0x00000064 Start Of Frame Register */
   __IM uint32_t RESERVED3[2];
  __IOM uint32_t SIE_EP2_CNT0;                  /*!< 0x00000070 Non-control endpoint count register */
  __IOM uint32_t SIE_EP2_CNT1;                  /*!< 0x00000074 Non-control endpoint count register */
  __IOM uint32_t SIE_EP2_CR0;                   /*!< 0x00000078 Non-control endpoint's control Register */
   __IM uint32_t RESERVED4;
   __IM uint32_t OSCLK_DR0;                     /*!< 0x00000080 Oscillator lock data register 0 */
   __IM uint32_t OSCLK_DR1;                     /*!< 0x00000084 Oscillator lock data register 1 */
   __IM uint32_t RESERVED5[6];
  __IOM uint32_t EP0_CR;                        /*!< 0x000000A0 Endpoint0 control Register */
  __IOM uint32_t EP0_CNT;                       /*!< 0x000000A4 Endpoint0 count Register */
   __IM uint32_t RESERVED6[2];
  __IOM uint32_t SIE_EP3_CNT0;                  /*!< 0x000000B0 Non-control endpoint count register */
  __IOM uint32_t SIE_EP3_CNT1;                  /*!< 0x000000B4 Non-control endpoint count register */
  __IOM uint32_t SIE_EP3_CR0;                   /*!< 0x000000B8 Non-control endpoint's control Register */
   __IM uint32_t RESERVED7[13];
  __IOM uint32_t SIE_EP4_CNT0;                  /*!< 0x000000F0 Non-control endpoint count register */
  __IOM uint32_t SIE_EP4_CNT1;                  /*!< 0x000000F4 Non-control endpoint count register */
  __IOM uint32_t SIE_EP4_CR0;                   /*!< 0x000000F8 Non-control endpoint's control Register */
   __IM uint32_t RESERVED8[13];
  __IOM uint32_t SIE_EP5_CNT0;                  /*!< 0x00000130 Non-control endpoint count register */
  __IOM uint32_t SIE_EP5_CNT1;                  /*!< 0x00000134 Non-control endpoint count register */
  __IOM uint32_t SIE_EP5_CR0;                   /*!< 0x00000138 Non-control endpoint's control Register */
   __IM uint32_t RESERVED9[13];
  __IOM uint32_t SIE_EP6_CNT0;                  /*!< 0x00000170 Non-control endpoint count register */
  __IOM uint32_t SIE_EP6_CNT1;                  /*!< 0x00000174 Non-control endpoint count register */
  __IOM uint32_t SIE_EP6_CR0;                   /*!< 0x00000178 Non-control endpoint's control Register */
   __IM uint32_t RESERVED10[13];
  __IOM uint32_t SIE_EP7_CNT0;                  /*!< 0x000001B0 Non-control endpoint count register */
  __IOM uint32_t SIE_EP7_CNT1;                  /*!< 0x000001B4 Non-control endpoint count register */
  __IOM uint32_t SIE_EP7_CR0;                   /*!< 0x000001B8 Non-control endpoint's control Register */
   __IM uint32_t RESERVED11[13];
  __IOM uint32_t SIE_EP8_CNT0;                  /*!< 0x000001F0 Non-control endpoint count register */
  __IOM uint32_t SIE_EP8_CNT1;                  /*!< 0x000001F4 Non-control endpoint count register */
  __IOM uint32_t SIE_EP8_CR0;                   /*!< 0x000001F8 Non-control endpoint's control Register */
   __IM uint32_t RESERVED12;
  __IOM uint32_t ARB_EP1_CFG;                   /*!< 0x00000200 Endpoint Configuration Register */
  __IOM uint32_t ARB_EP1_INT_EN;                /*!< 0x00000204 Endpoint Interrupt Enable Register */
  __IOM uint32_t ARB_EP1_SR;                    /*!< 0x00000208 Endpoint Interrupt Enable Register */
   __IM uint32_t RESERVED13;
  __IOM uint32_t ARB_RW1_WA;                    /*!< 0x00000210 Endpoint Write Address value */
  __IOM uint32_t ARB_RW1_WA_MSB;                /*!< 0x00000214 Endpoint Write Address value */
  __IOM uint32_t ARB_RW1_RA;                    /*!< 0x00000218 Endpoint Read Address value */
  __IOM uint32_t ARB_RW1_RA_MSB;                /*!< 0x0000021C Endpoint Read Address value */
  __IOM uint32_t ARB_RW1_DR;                    /*!< 0x00000220 Endpoint Data Register */
   __IM uint32_t RESERVED14[3];
  __IOM uint32_t BUF_SIZE;                      /*!< 0x00000230 Dedicated Endpoint Buffer Size Register */
   __IM uint32_t RESERVED15;
  __IOM uint32_t EP_ACTIVE;                     /*!< 0x00000238 Endpoint Active Indication Register */
  __IOM uint32_t EP_TYPE;                       /*!< 0x0000023C Endpoint Type (IN/OUT) Indication */
  __IOM uint32_t ARB_EP2_CFG;                   /*!< 0x00000240 Endpoint Configuration Register */
  __IOM uint32_t ARB_EP2_INT_EN;                /*!< 0x00000244 Endpoint Interrupt Enable Register */
  __IOM uint32_t ARB_EP2_SR;                    /*!< 0x00000248 Endpoint Interrupt Enable Register */
   __IM uint32_t RESERVED16;
  __IOM uint32_t ARB_RW2_WA;                    /*!< 0x00000250 Endpoint Write Address value */
  __IOM uint32_t ARB_RW2_WA_MSB;                /*!< 0x00000254 Endpoint Write Address value */
  __IOM uint32_t ARB_RW2_RA;                    /*!< 0x00000258 Endpoint Read Address value */
  __IOM uint32_t ARB_RW2_RA_MSB;                /*!< 0x0000025C Endpoint Read Address value */
  __IOM uint32_t ARB_RW2_DR;                    /*!< 0x00000260 Endpoint Data Register */
   __IM uint32_t RESERVED17[3];
  __IOM uint32_t ARB_CFG;                       /*!< 0x00000270 Arbiter Configuration Register */
  __IOM uint32_t USB_CLK_EN;                    /*!< 0x00000274 USB Block Clock Enable Register */
  __IOM uint32_t ARB_INT_EN;                    /*!< 0x00000278 Arbiter Interrupt Enable */
   __IM uint32_t ARB_INT_SR;                    /*!< 0x0000027C Arbiter Interrupt Status */
  __IOM uint32_t ARB_EP3_CFG;                   /*!< 0x00000280 Endpoint Configuration Register */
  __IOM uint32_t ARB_EP3_INT_EN;                /*!< 0x00000284 Endpoint Interrupt Enable Register */
  __IOM uint32_t ARB_EP3_SR;                    /*!< 0x00000288 Endpoint Interrupt Enable Register */
   __IM uint32_t RESERVED18;
  __IOM uint32_t ARB_RW3_WA;                    /*!< 0x00000290 Endpoint Write Address value */
  __IOM uint32_t ARB_RW3_WA_MSB;                /*!< 0x00000294 Endpoint Write Address value */
  __IOM uint32_t ARB_RW3_RA;                    /*!< 0x00000298 Endpoint Read Address value */
  __IOM uint32_t ARB_RW3_RA_MSB;                /*!< 0x0000029C Endpoint Read Address value */
  __IOM uint32_t ARB_RW3_DR;                    /*!< 0x000002A0 Endpoint Data Register */
   __IM uint32_t RESERVED19[3];
  __IOM uint32_t CWA;                           /*!< 0x000002B0 Common Area Write Address */
  __IOM uint32_t CWA_MSB;                       /*!< 0x000002B4 Endpoint Read Address value */
   __IM uint32_t RESERVED20[2];
  __IOM uint32_t ARB_EP4_CFG;                   /*!< 0x000002C0 Endpoint Configuration Register */
  __IOM uint32_t ARB_EP4_INT_EN;                /*!< 0x000002C4 Endpoint Interrupt Enable Register */
  __IOM uint32_t ARB_EP4_SR;                    /*!< 0x000002C8 Endpoint Interrupt Enable Register */
   __IM uint32_t RESERVED21;
  __IOM uint32_t ARB_RW4_WA;                    /*!< 0x000002D0 Endpoint Write Address value */
  __IOM uint32_t ARB_RW4_WA_MSB;                /*!< 0x000002D4 Endpoint Write Address value */
  __IOM uint32_t ARB_RW4_RA;                    /*!< 0x000002D8 Endpoint Read Address value */
  __IOM uint32_t ARB_RW4_RA_MSB;                /*!< 0x000002DC Endpoint Read Address value */
  __IOM uint32_t ARB_RW4_DR;                    /*!< 0x000002E0 Endpoint Data Register */
   __IM uint32_t RESERVED22[3];
  __IOM uint32_t DMA_THRES;                     /*!< 0x000002F0 DMA Burst / Threshold Configuration */
  __IOM uint32_t DMA_THRES_MSB;                 /*!< 0x000002F4 DMA Burst / Threshold Configuration */
   __IM uint32_t RESERVED23[2];
  __IOM uint32_t ARB_EP5_CFG;                   /*!< 0x00000300 Endpoint Configuration Register */
  __IOM uint32_t ARB_EP5_INT_EN;                /*!< 0x00000304 Endpoint Interrupt Enable Register */
  __IOM uint32_t ARB_EP5_SR;                    /*!< 0x00000308 Endpoint Interrupt Enable Register */
   __IM uint32_t RESERVED24;
  __IOM uint32_t ARB_RW5_WA;                    /*!< 0x00000310 Endpoint Write Address value */
  __IOM uint32_t ARB_RW5_WA_MSB;                /*!< 0x00000314 Endpoint Write Address value */
  __IOM uint32_t ARB_RW5_RA;                    /*!< 0x00000318 Endpoint Read Address value */
  __IOM uint32_t ARB_RW5_RA_MSB;                /*!< 0x0000031C Endpoint Read Address value */
  __IOM uint32_t ARB_RW5_DR;                    /*!< 0x00000320 Endpoint Data Register */
   __IM uint32_t RESERVED25[3];
  __IOM uint32_t BUS_RST_CNT;                   /*!< 0x00000330 Bus Reset Count Register */
   __IM uint32_t RESERVED26[3];
  __IOM uint32_t ARB_EP6_CFG;                   /*!< 0x00000340 Endpoint Configuration Register */
  __IOM uint32_t ARB_EP6_INT_EN;                /*!< 0x00000344 Endpoint Interrupt Enable Register */
  __IOM uint32_t ARB_EP6_SR;                    /*!< 0x00000348 Endpoint Interrupt Enable Register */
   __IM uint32_t RESERVED27;
  __IOM uint32_t ARB_RW6_WA;                    /*!< 0x00000350 Endpoint Write Address value */
  __IOM uint32_t ARB_RW6_WA_MSB;                /*!< 0x00000354 Endpoint Write Address value */
  __IOM uint32_t ARB_RW6_RA;                    /*!< 0x00000358 Endpoint Read Address value */
  __IOM uint32_t ARB_RW6_RA_MSB;                /*!< 0x0000035C Endpoint Read Address value */
  __IOM uint32_t ARB_RW6_DR;                    /*!< 0x00000360 Endpoint Data Register */
   __IM uint32_t RESERVED28[7];
  __IOM uint32_t ARB_EP7_CFG;                   /*!< 0x00000380 Endpoint Configuration Register */
  __IOM uint32_t ARB_EP7_INT_EN;                /*!< 0x00000384 Endpoint Interrupt Enable Register */
  __IOM uint32_t ARB_EP7_SR;                    /*!< 0x00000388 Endpoint Interrupt Enable Register */
   __IM uint32_t RESERVED29;
  __IOM uint32_t ARB_RW7_WA;                    /*!< 0x00000390 Endpoint Write Address value */
  __IOM uint32_t ARB_RW7_WA_MSB;                /*!< 0x00000394 Endpoint Write Address value */
  __IOM uint32_t ARB_RW7_RA;                    /*!< 0x00000398 Endpoint Read Address value */
  __IOM uint32_t ARB_RW7_RA_MSB;                /*!< 0x0000039C Endpoint Read Address value */
  __IOM uint32_t ARB_RW7_DR;                    /*!< 0x000003A0 Endpoint Data Register */
   __IM uint32_t RESERVED30[7];
  __IOM uint32_t ARB_EP8_CFG;                   /*!< 0x000003C0 Endpoint Configuration Register */
  __IOM uint32_t ARB_EP8_INT_EN;                /*!< 0x000003C4 Endpoint Interrupt Enable Register */
  __IOM uint32_t ARB_EP8_SR;                    /*!< 0x000003C8 Endpoint Interrupt Enable Register */
   __IM uint32_t RESERVED31;
  __IOM uint32_t ARB_RW8_WA;                    /*!< 0x000003D0 Endpoint Write Address value */
  __IOM uint32_t ARB_RW8_WA_MSB;                /*!< 0x000003D4 Endpoint Write Address value */
  __IOM uint32_t ARB_RW8_RA;                    /*!< 0x000003D8 Endpoint Read Address value */
  __IOM uint32_t ARB_RW8_RA_MSB;                /*!< 0x000003DC Endpoint Read Address value */
  __IOM uint32_t ARB_RW8_DR;                    /*!< 0x000003E0 Endpoint Data Register */
   __IM uint32_t RESERVED32[7];
  __IOM uint32_t MEM_DATA[512];                 /*!< 0x00000400 DATA */
   __IM uint32_t RESERVED33[280];
   __IM uint32_t SOF16;                         /*!< 0x00001060 Start Of Frame Register */
   __IM uint32_t RESERVED34[7];
   __IM uint32_t OSCLK_DR16;                    /*!< 0x00001080 Oscillator lock data register */
   __IM uint32_t RESERVED35[99];
  __IOM uint32_t ARB_RW1_WA16;                  /*!< 0x00001210 Endpoint Write Address value */
   __IM uint32_t RESERVED36;
  __IOM uint32_t ARB_RW1_RA16;                  /*!< 0x00001218 Endpoint Read Address value */
   __IM uint32_t RESERVED37;
  __IOM uint32_t ARB_RW1_DR16;                  /*!< 0x00001220 Endpoint Data Register */
   __IM uint32_t RESERVED38[11];
  __IOM uint32_t ARB_RW2_WA16;                  /*!< 0x00001250 Endpoint Write Address value */
   __IM uint32_t RESERVED39;
  __IOM uint32_t ARB_RW2_RA16;                  /*!< 0x00001258 Endpoint Read Address value */
   __IM uint32_t RESERVED40;
  __IOM uint32_t ARB_RW2_DR16;                  /*!< 0x00001260 Endpoint Data Register */
   __IM uint32_t RESERVED41[11];
  __IOM uint32_t ARB_RW3_WA16;                  /*!< 0x00001290 Endpoint Write Address value */
   __IM uint32_t RESERVED42;
  __IOM uint32_t ARB_RW3_RA16;                  /*!< 0x00001298 Endpoint Read Address value */
   __IM uint32_t RESERVED43;
  __IOM uint32_t ARB_RW3_DR16;                  /*!< 0x000012A0 Endpoint Data Register */
   __IM uint32_t RESERVED44[3];
  __IOM uint32_t CWA16;                         /*!< 0x000012B0 Common Area Write Address */
   __IM uint32_t RESERVED45[7];
  __IOM uint32_t ARB_RW4_WA16;                  /*!< 0x000012D0 Endpoint Write Address value */
   __IM uint32_t RESERVED46;
  __IOM uint32_t ARB_RW4_RA16;                  /*!< 0x000012D8 Endpoint Read Address value */
   __IM uint32_t RESERVED47;
  __IOM uint32_t ARB_RW4_DR16;                  /*!< 0x000012E0 Endpoint Data Register */
   __IM uint32_t RESERVED48[3];
  __IOM uint32_t DMA_THRES16;                   /*!< 0x000012F0 DMA Burst / Threshold Configuration */
   __IM uint32_t RESERVED49[7];
  __IOM uint32_t ARB_RW5_WA16;                  /*!< 0x00001310 Endpoint Write Address value */
   __IM uint32_t RESERVED50;
  __IOM uint32_t ARB_RW5_RA16;                  /*!< 0x00001318 Endpoint Read Address value */
   __IM uint32_t RESERVED51;
  __IOM uint32_t ARB_RW5_DR16;                  /*!< 0x00001320 Endpoint Data Register */
   __IM uint32_t RESERVED52[11];
  __IOM uint32_t ARB_RW6_WA16;                  /*!< 0x00001350 Endpoint Write Address value */
   __IM uint32_t RESERVED53;
  __IOM uint32_t ARB_RW6_RA16;                  /*!< 0x00001358 Endpoint Read Address value */
   __IM uint32_t RESERVED54;
  __IOM uint32_t ARB_RW6_DR16;                  /*!< 0x00001360 Endpoint Data Register */
   __IM uint32_t RESERVED55[11];
  __IOM uint32_t ARB_RW7_WA16;                  /*!< 0x00001390 Endpoint Write Address value */
   __IM uint32_t RESERVED56;
  __IOM uint32_t ARB_RW7_RA16;                  /*!< 0x00001398 Endpoint Read Address value */
   __IM uint32_t RESERVED57;
  __IOM uint32_t ARB_RW7_DR16;                  /*!< 0x000013A0 Endpoint Data Register */
   __IM uint32_t RESERVED58[11];
  __IOM uint32_t ARB_RW8_WA16;                  /*!< 0x000013D0 Endpoint Write Address value */
   __IM uint32_t RESERVED59;
  __IOM uint32_t ARB_RW8_RA16;                  /*!< 0x000013D8 Endpoint Read Address value */
   __IM uint32_t RESERVED60;
  __IOM uint32_t ARB_RW8_DR16;                  /*!< 0x000013E0 Endpoint Data Register */
   __IM uint32_t RESERVED61[775];
        USBFS_BCD_Type BCD;                     /*!< 0x00002000 USB Device Controller Battery Charger Detect */
} USBFS_Type;                                   /*!< Size = 12288 (0x3000) */


/* USBFS_BCD.POWER_CTRL */
#define USBFS_BCD_POWER_CTRL_VBUS_VALID_OVR_Pos 0UL
#define USBFS_BCD_POWER_CTRL_VBUS_VALID_OVR_Msk 0x3UL
#define USBFS_BCD_POWER_CTRL_SUSPEND_Pos        2UL
#define USBFS_BCD_POWER_CTRL_SUSPEND_Msk        0x4UL
#define USBFS_BCD_POWER_CTRL_SUSPEND_DEL_Pos    3UL
#define USBFS_BCD_POWER_CTRL_SUSPEND_DEL_Msk    0x8UL
#define USBFS_BCD_POWER_CTRL_ISOLATE_Pos        4UL
#define USBFS_BCD_POWER_CTRL_ISOLATE_Msk        0x10UL
#define USBFS_BCD_POWER_CTRL_CHDET_PWR_CTL_Pos  5UL
#define USBFS_BCD_POWER_CTRL_CHDET_PWR_CTL_Msk  0x60UL
#define USBFS_BCD_POWER_CTRL_ENABLE_DM_PULLDOWN_Pos 25UL
#define USBFS_BCD_POWER_CTRL_ENABLE_DM_PULLDOWN_Msk 0x2000000UL
#define USBFS_BCD_POWER_CTRL_ENABLE_VBUS_PULLDOWN_Pos 26UL
#define USBFS_BCD_POWER_CTRL_ENABLE_VBUS_PULLDOWN_Msk 0x4000000UL
#define USBFS_BCD_POWER_CTRL_ENABLE_RCVR_Pos    27UL
#define USBFS_BCD_POWER_CTRL_ENABLE_RCVR_Msk    0x8000000UL
#define USBFS_BCD_POWER_CTRL_ENABLE_DPO_Pos     28UL
#define USBFS_BCD_POWER_CTRL_ENABLE_DPO_Msk     0x10000000UL
#define USBFS_BCD_POWER_CTRL_ENABLE_DMO_Pos     29UL
#define USBFS_BCD_POWER_CTRL_ENABLE_DMO_Msk     0x20000000UL
#define USBFS_BCD_POWER_CTRL_ENABLE_CHGDET_Pos  30UL
#define USBFS_BCD_POWER_CTRL_ENABLE_CHGDET_Msk  0x40000000UL
#define USBFS_BCD_POWER_CTRL_ENABLE_Pos         31UL
#define USBFS_BCD_POWER_CTRL_ENABLE_Msk         0x80000000UL
/* USBFS_BCD.CHGDET_CTRL */
#define USBFS_BCD_CHGDET_CTRL_COMP_DP_Pos       0UL
#define USBFS_BCD_CHGDET_CTRL_COMP_DP_Msk       0x1UL
#define USBFS_BCD_CHGDET_CTRL_COMP_DM_Pos       1UL
#define USBFS_BCD_CHGDET_CTRL_COMP_DM_Msk       0x2UL
#define USBFS_BCD_CHGDET_CTRL_COMP_EN_Pos       2UL
#define USBFS_BCD_CHGDET_CTRL_COMP_EN_Msk       0x4UL
#define USBFS_BCD_CHGDET_CTRL_REF_DP_Pos        3UL
#define USBFS_BCD_CHGDET_CTRL_REF_DP_Msk        0x8UL
#define USBFS_BCD_CHGDET_CTRL_REF_DM_Pos        4UL
#define USBFS_BCD_CHGDET_CTRL_REF_DM_Msk        0x10UL
#define USBFS_BCD_CHGDET_CTRL_REF_EN_Pos        5UL
#define USBFS_BCD_CHGDET_CTRL_REF_EN_Msk        0x20UL
#define USBFS_BCD_CHGDET_CTRL_DCD_SRC_EN_Pos    6UL
#define USBFS_BCD_CHGDET_CTRL_DCD_SRC_EN_Msk    0x40UL
#define USBFS_BCD_CHGDET_CTRL_ADFT_CTRL_Pos     12UL
#define USBFS_BCD_CHGDET_CTRL_ADFT_CTRL_Msk     0x3000UL
#define USBFS_BCD_CHGDET_CTRL_COMP_OUT_Pos      31UL
#define USBFS_BCD_CHGDET_CTRL_COMP_OUT_Msk      0x80000000UL
/* USBFS_BCD.USBIO_CTRL */
#define USBFS_BCD_USBIO_CTRL_DM_P_Pos           0UL
#define USBFS_BCD_USBIO_CTRL_DM_P_Msk           0x7UL
#define USBFS_BCD_USBIO_CTRL_DM_M_Pos           3UL
#define USBFS_BCD_USBIO_CTRL_DM_M_Msk           0x38UL
/* USBFS_BCD.FLOW_CTRL */
#define USBFS_BCD_FLOW_CTRL_EP1_ERR_RESP_Pos    0UL
#define USBFS_BCD_FLOW_CTRL_EP1_ERR_RESP_Msk    0x1UL
#define USBFS_BCD_FLOW_CTRL_EP2_ERR_RESP_Pos    1UL
#define USBFS_BCD_FLOW_CTRL_EP2_ERR_RESP_Msk    0x2UL
#define USBFS_BCD_FLOW_CTRL_EP3_ERR_RESP_Pos    2UL
#define USBFS_BCD_FLOW_CTRL_EP3_ERR_RESP_Msk    0x4UL
#define USBFS_BCD_FLOW_CTRL_EP4_ERR_RESP_Pos    3UL
#define USBFS_BCD_FLOW_CTRL_EP4_ERR_RESP_Msk    0x8UL
#define USBFS_BCD_FLOW_CTRL_EP5_ERR_RESP_Pos    4UL
#define USBFS_BCD_FLOW_CTRL_EP5_ERR_RESP_Msk    0x10UL
#define USBFS_BCD_FLOW_CTRL_EP6_ERR_RESP_Pos    5UL
#define USBFS_BCD_FLOW_CTRL_EP6_ERR_RESP_Msk    0x20UL
#define USBFS_BCD_FLOW_CTRL_EP7_ERR_RESP_Pos    6UL
#define USBFS_BCD_FLOW_CTRL_EP7_ERR_RESP_Msk    0x40UL
#define USBFS_BCD_FLOW_CTRL_EP8_ERR_RESP_Pos    7UL
#define USBFS_BCD_FLOW_CTRL_EP8_ERR_RESP_Msk    0x80UL
/* USBFS_BCD.LPM_CTRL */
#define USBFS_BCD_LPM_CTRL_LPM_EN_Pos           0UL
#define USBFS_BCD_LPM_CTRL_LPM_EN_Msk           0x1UL
#define USBFS_BCD_LPM_CTRL_LPM_ACK_RESP_Pos     1UL
#define USBFS_BCD_LPM_CTRL_LPM_ACK_RESP_Msk     0x2UL
#define USBFS_BCD_LPM_CTRL_NYET_EN_Pos          2UL
#define USBFS_BCD_LPM_CTRL_NYET_EN_Msk          0x4UL
#define USBFS_BCD_LPM_CTRL_SUB_RESP_Pos         4UL
#define USBFS_BCD_LPM_CTRL_SUB_RESP_Msk         0x10UL
/* USBFS_BCD.LPM_STAT */
#define USBFS_BCD_LPM_STAT_LPM_BESL_Pos         0UL
#define USBFS_BCD_LPM_STAT_LPM_BESL_Msk         0xFUL
#define USBFS_BCD_LPM_STAT_LPM_REMOTEWAKE_Pos   4UL
#define USBFS_BCD_LPM_STAT_LPM_REMOTEWAKE_Msk   0x10UL
/* USBFS_BCD.INTR_SIE */
#define USBFS_BCD_INTR_SIE_SOF_INTR_Pos         0UL
#define USBFS_BCD_INTR_SIE_SOF_INTR_Msk         0x1UL
#define USBFS_BCD_INTR_SIE_BUS_RESET_INTR_Pos   1UL
#define USBFS_BCD_INTR_SIE_BUS_RESET_INTR_Msk   0x2UL
#define USBFS_BCD_INTR_SIE_EP0_INTR_Pos         2UL
#define USBFS_BCD_INTR_SIE_EP0_INTR_Msk         0x4UL
#define USBFS_BCD_INTR_SIE_LPM_INTR_Pos         3UL
#define USBFS_BCD_INTR_SIE_LPM_INTR_Msk         0x8UL
#define USBFS_BCD_INTR_SIE_RESUME_INTR_Pos      4UL
#define USBFS_BCD_INTR_SIE_RESUME_INTR_Msk      0x10UL
/* USBFS_BCD.INTR_SIE_SET */
#define USBFS_BCD_INTR_SIE_SET_SOF_INTR_SET_Pos 0UL
#define USBFS_BCD_INTR_SIE_SET_SOF_INTR_SET_Msk 0x1UL
#define USBFS_BCD_INTR_SIE_SET_BUS_RESET_INTR_SET_Pos 1UL
#define USBFS_BCD_INTR_SIE_SET_BUS_RESET_INTR_SET_Msk 0x2UL
#define USBFS_BCD_INTR_SIE_SET_EP0_INTR_SET_Pos 2UL
#define USBFS_BCD_INTR_SIE_SET_EP0_INTR_SET_Msk 0x4UL
#define USBFS_BCD_INTR_SIE_SET_LPM_INTR_SET_Pos 3UL
#define USBFS_BCD_INTR_SIE_SET_LPM_INTR_SET_Msk 0x8UL
#define USBFS_BCD_INTR_SIE_SET_RESUME_INTR_SET_Pos 4UL
#define USBFS_BCD_INTR_SIE_SET_RESUME_INTR_SET_Msk 0x10UL
/* USBFS_BCD.INTR_SIE_MASK */
#define USBFS_BCD_INTR_SIE_MASK_SOF_INTR_MASK_Pos 0UL
#define USBFS_BCD_INTR_SIE_MASK_SOF_INTR_MASK_Msk 0x1UL
#define USBFS_BCD_INTR_SIE_MASK_BUS_RESET_INTR_MASK_Pos 1UL
#define USBFS_BCD_INTR_SIE_MASK_BUS_RESET_INTR_MASK_Msk 0x2UL
#define USBFS_BCD_INTR_SIE_MASK_EP0_INTR_MASK_Pos 2UL
#define USBFS_BCD_INTR_SIE_MASK_EP0_INTR_MASK_Msk 0x4UL
#define USBFS_BCD_INTR_SIE_MASK_LPM_INTR_MASK_Pos 3UL
#define USBFS_BCD_INTR_SIE_MASK_LPM_INTR_MASK_Msk 0x8UL
#define USBFS_BCD_INTR_SIE_MASK_RESUME_INTR_MASK_Pos 4UL
#define USBFS_BCD_INTR_SIE_MASK_RESUME_INTR_MASK_Msk 0x10UL
/* USBFS_BCD.INTR_SIE_MASKED */
#define USBFS_BCD_INTR_SIE_MASKED_SOF_INTR_MASKED_Pos 0UL
#define USBFS_BCD_INTR_SIE_MASKED_SOF_INTR_MASKED_Msk 0x1UL
#define USBFS_BCD_INTR_SIE_MASKED_BUS_RESET_INTR_MASKED_Pos 1UL
#define USBFS_BCD_INTR_SIE_MASKED_BUS_RESET_INTR_MASKED_Msk 0x2UL
#define USBFS_BCD_INTR_SIE_MASKED_EP0_INTR_MASKED_Pos 2UL
#define USBFS_BCD_INTR_SIE_MASKED_EP0_INTR_MASKED_Msk 0x4UL
#define USBFS_BCD_INTR_SIE_MASKED_LPM_INTR_MASKED_Pos 3UL
#define USBFS_BCD_INTR_SIE_MASKED_LPM_INTR_MASKED_Msk 0x8UL
#define USBFS_BCD_INTR_SIE_MASKED_RESUME_INTR_MASKED_Pos 4UL
#define USBFS_BCD_INTR_SIE_MASKED_RESUME_INTR_MASKED_Msk 0x10UL
/* USBFS_BCD.INTR_LVL_SEL */
#define USBFS_BCD_INTR_LVL_SEL_SOF_LVL_SEL_Pos  0UL
#define USBFS_BCD_INTR_LVL_SEL_SOF_LVL_SEL_Msk  0x3UL
#define USBFS_BCD_INTR_LVL_SEL_BUS_RESET_LVL_SEL_Pos 2UL
#define USBFS_BCD_INTR_LVL_SEL_BUS_RESET_LVL_SEL_Msk 0xCUL
#define USBFS_BCD_INTR_LVL_SEL_EP0_LVL_SEL_Pos  4UL
#define USBFS_BCD_INTR_LVL_SEL_EP0_LVL_SEL_Msk  0x30UL
#define USBFS_BCD_INTR_LVL_SEL_LPM_LVL_SEL_Pos  6UL
#define USBFS_BCD_INTR_LVL_SEL_LPM_LVL_SEL_Msk  0xC0UL
#define USBFS_BCD_INTR_LVL_SEL_RESUME_LVL_SEL_Pos 8UL
#define USBFS_BCD_INTR_LVL_SEL_RESUME_LVL_SEL_Msk 0x300UL
#define USBFS_BCD_INTR_LVL_SEL_ARB_EP_LVL_SEL_Pos 14UL
#define USBFS_BCD_INTR_LVL_SEL_ARB_EP_LVL_SEL_Msk 0xC000UL
#define USBFS_BCD_INTR_LVL_SEL_EP1_LVL_SEL_Pos  16UL
#define USBFS_BCD_INTR_LVL_SEL_EP1_LVL_SEL_Msk  0x30000UL
#define USBFS_BCD_INTR_LVL_SEL_EP2_LVL_SEL_Pos  18UL
#define USBFS_BCD_INTR_LVL_SEL_EP2_LVL_SEL_Msk  0xC0000UL
#define USBFS_BCD_INTR_LVL_SEL_EP3_LVL_SEL_Pos  20UL
#define USBFS_BCD_INTR_LVL_SEL_EP3_LVL_SEL_Msk  0x300000UL
#define USBFS_BCD_INTR_LVL_SEL_EP4_LVL_SEL_Pos  22UL
#define USBFS_BCD_INTR_LVL_SEL_EP4_LVL_SEL_Msk  0xC00000UL
#define USBFS_BCD_INTR_LVL_SEL_EP5_LVL_SEL_Pos  24UL
#define USBFS_BCD_INTR_LVL_SEL_EP5_LVL_SEL_Msk  0x3000000UL
#define USBFS_BCD_INTR_LVL_SEL_EP6_LVL_SEL_Pos  26UL
#define USBFS_BCD_INTR_LVL_SEL_EP6_LVL_SEL_Msk  0xC000000UL
#define USBFS_BCD_INTR_LVL_SEL_EP7_LVL_SEL_Pos  28UL
#define USBFS_BCD_INTR_LVL_SEL_EP7_LVL_SEL_Msk  0x30000000UL
#define USBFS_BCD_INTR_LVL_SEL_EP8_LVL_SEL_Pos  30UL
#define USBFS_BCD_INTR_LVL_SEL_EP8_LVL_SEL_Msk  0xC0000000UL
/* USBFS_BCD.INTR_CAUSE_HI */
#define USBFS_BCD_INTR_CAUSE_HI_SOF_INTR_Pos    0UL
#define USBFS_BCD_INTR_CAUSE_HI_SOF_INTR_Msk    0x1UL
#define USBFS_BCD_INTR_CAUSE_HI_BUS_RESET_INTR_Pos 1UL
#define USBFS_BCD_INTR_CAUSE_HI_BUS_RESET_INTR_Msk 0x2UL
#define USBFS_BCD_INTR_CAUSE_HI_EP0_INTR_Pos    2UL
#define USBFS_BCD_INTR_CAUSE_HI_EP0_INTR_Msk    0x4UL
#define USBFS_BCD_INTR_CAUSE_HI_LPM_INTR_Pos    3UL
#define USBFS_BCD_INTR_CAUSE_HI_LPM_INTR_Msk    0x8UL
#define USBFS_BCD_INTR_CAUSE_HI_RESUME_INTR_Pos 4UL
#define USBFS_BCD_INTR_CAUSE_HI_RESUME_INTR_Msk 0x10UL
#define USBFS_BCD_INTR_CAUSE_HI_ARB_EP_INTR_Pos 7UL
#define USBFS_BCD_INTR_CAUSE_HI_ARB_EP_INTR_Msk 0x80UL
#define USBFS_BCD_INTR_CAUSE_HI_EP1_INTR_Pos    8UL
#define USBFS_BCD_INTR_CAUSE_HI_EP1_INTR_Msk    0x100UL
#define USBFS_BCD_INTR_CAUSE_HI_EP2_INTR_Pos    9UL
#define USBFS_BCD_INTR_CAUSE_HI_EP2_INTR_Msk    0x200UL
#define USBFS_BCD_INTR_CAUSE_HI_EP3_INTR_Pos    10UL
#define USBFS_BCD_INTR_CAUSE_HI_EP3_INTR_Msk    0x400UL
#define USBFS_BCD_INTR_CAUSE_HI_EP4_INTR_Pos    11UL
#define USBFS_BCD_INTR_CAUSE_HI_EP4_INTR_Msk    0x800UL
#define USBFS_BCD_INTR_CAUSE_HI_EP5_INTR_Pos    12UL
#define USBFS_BCD_INTR_CAUSE_HI_EP5_INTR_Msk    0x1000UL
#define USBFS_BCD_INTR_CAUSE_HI_EP6_INTR_Pos    13UL
#define USBFS_BCD_INTR_CAUSE_HI_EP6_INTR_Msk    0x2000UL
#define USBFS_BCD_INTR_CAUSE_HI_EP7_INTR_Pos    14UL
#define USBFS_BCD_INTR_CAUSE_HI_EP7_INTR_Msk    0x4000UL
#define USBFS_BCD_INTR_CAUSE_HI_EP8_INTR_Pos    15UL
#define USBFS_BCD_INTR_CAUSE_HI_EP8_INTR_Msk    0x8000UL
/* USBFS_BCD.INTR_CAUSE_MED */
#define USBFS_BCD_INTR_CAUSE_MED_SOF_INTR_Pos   0UL
#define USBFS_BCD_INTR_CAUSE_MED_SOF_INTR_Msk   0x1UL
#define USBFS_BCD_INTR_CAUSE_MED_BUS_RESET_INTR_Pos 1UL
#define USBFS_BCD_INTR_CAUSE_MED_BUS_RESET_INTR_Msk 0x2UL
#define USBFS_BCD_INTR_CAUSE_MED_EP0_INTR_Pos   2UL
#define USBFS_BCD_INTR_CAUSE_MED_EP0_INTR_Msk   0x4UL
#define USBFS_BCD_INTR_CAUSE_MED_LPM_INTR_Pos   3UL
#define USBFS_BCD_INTR_CAUSE_MED_LPM_INTR_Msk   0x8UL
#define USBFS_BCD_INTR_CAUSE_MED_RESUME_INTR_Pos 4UL
#define USBFS_BCD_INTR_CAUSE_MED_RESUME_INTR_Msk 0x10UL
#define USBFS_BCD_INTR_CAUSE_MED_ARB_EP_INTR_Pos 7UL
#define USBFS_BCD_INTR_CAUSE_MED_ARB_EP_INTR_Msk 0x80UL
#define USBFS_BCD_INTR_CAUSE_MED_EP1_INTR_Pos   8UL
#define USBFS_BCD_INTR_CAUSE_MED_EP1_INTR_Msk   0x100UL
#define USBFS_BCD_INTR_CAUSE_MED_EP2_INTR_Pos   9UL
#define USBFS_BCD_INTR_CAUSE_MED_EP2_INTR_Msk   0x200UL
#define USBFS_BCD_INTR_CAUSE_MED_EP3_INTR_Pos   10UL
#define USBFS_BCD_INTR_CAUSE_MED_EP3_INTR_Msk   0x400UL
#define USBFS_BCD_INTR_CAUSE_MED_EP4_INTR_Pos   11UL
#define USBFS_BCD_INTR_CAUSE_MED_EP4_INTR_Msk   0x800UL
#define USBFS_BCD_INTR_CAUSE_MED_EP5_INTR_Pos   12UL
#define USBFS_BCD_INTR_CAUSE_MED_EP5_INTR_Msk   0x1000UL
#define USBFS_BCD_INTR_CAUSE_MED_EP6_INTR_Pos   13UL
#define USBFS_BCD_INTR_CAUSE_MED_EP6_INTR_Msk   0x2000UL
#define USBFS_BCD_INTR_CAUSE_MED_EP7_INTR_Pos   14UL
#define USBFS_BCD_INTR_CAUSE_MED_EP7_INTR_Msk   0x4000UL
#define USBFS_BCD_INTR_CAUSE_MED_EP8_INTR_Pos   15UL
#define USBFS_BCD_INTR_CAUSE_MED_EP8_INTR_Msk   0x8000UL
/* USBFS_BCD.INTR_CAUSE_LO */
#define USBFS_BCD_INTR_CAUSE_LO_SOF_INTR_Pos    0UL
#define USBFS_BCD_INTR_CAUSE_LO_SOF_INTR_Msk    0x1UL
#define USBFS_BCD_INTR_CAUSE_LO_BUS_RESET_INTR_Pos 1UL
#define USBFS_BCD_INTR_CAUSE_LO_BUS_RESET_INTR_Msk 0x2UL
#define USBFS_BCD_INTR_CAUSE_LO_EP0_INTR_Pos    2UL
#define USBFS_BCD_INTR_CAUSE_LO_EP0_INTR_Msk    0x4UL
#define USBFS_BCD_INTR_CAUSE_LO_LPM_INTR_Pos    3UL
#define USBFS_BCD_INTR_CAUSE_LO_LPM_INTR_Msk    0x8UL
#define USBFS_BCD_INTR_CAUSE_LO_RESUME_INTR_Pos 4UL
#define USBFS_BCD_INTR_CAUSE_LO_RESUME_INTR_Msk 0x10UL
#define USBFS_BCD_INTR_CAUSE_LO_ARB_EP_INTR_Pos 7UL
#define USBFS_BCD_INTR_CAUSE_LO_ARB_EP_INTR_Msk 0x80UL
#define USBFS_BCD_INTR_CAUSE_LO_EP1_INTR_Pos    8UL
#define USBFS_BCD_INTR_CAUSE_LO_EP1_INTR_Msk    0x100UL
#define USBFS_BCD_INTR_CAUSE_LO_EP2_INTR_Pos    9UL
#define USBFS_BCD_INTR_CAUSE_LO_EP2_INTR_Msk    0x200UL
#define USBFS_BCD_INTR_CAUSE_LO_EP3_INTR_Pos    10UL
#define USBFS_BCD_INTR_CAUSE_LO_EP3_INTR_Msk    0x400UL
#define USBFS_BCD_INTR_CAUSE_LO_EP4_INTR_Pos    11UL
#define USBFS_BCD_INTR_CAUSE_LO_EP4_INTR_Msk    0x800UL
#define USBFS_BCD_INTR_CAUSE_LO_EP5_INTR_Pos    12UL
#define USBFS_BCD_INTR_CAUSE_LO_EP5_INTR_Msk    0x1000UL
#define USBFS_BCD_INTR_CAUSE_LO_EP6_INTR_Pos    13UL
#define USBFS_BCD_INTR_CAUSE_LO_EP6_INTR_Msk    0x2000UL
#define USBFS_BCD_INTR_CAUSE_LO_EP7_INTR_Pos    14UL
#define USBFS_BCD_INTR_CAUSE_LO_EP7_INTR_Msk    0x4000UL
#define USBFS_BCD_INTR_CAUSE_LO_EP8_INTR_Pos    15UL
#define USBFS_BCD_INTR_CAUSE_LO_EP8_INTR_Msk    0x8000UL
/* USBFS_BCD.DFT_CTRL */
#define USBFS_BCD_DFT_CTRL_DDFT_SEL_Pos         0UL
#define USBFS_BCD_DFT_CTRL_DDFT_SEL_Msk         0x7UL
#define USBFS_BCD_DFT_CTRL_ADFT_VREFOUT_SEL_Pos 8UL
#define USBFS_BCD_DFT_CTRL_ADFT_VREFOUT_SEL_Msk 0x300UL
/* USBFS_BCD.PHY_TRIM0 */
#define USBFS_BCD_PHY_TRIM0_TRIM_DP_R_REG_Pos   0UL
#define USBFS_BCD_PHY_TRIM0_TRIM_DP_R_REG_Msk   0x3FUL
/* USBFS_BCD.PHY_TRIM1 */
#define USBFS_BCD_PHY_TRIM1_TRIM_DM_R_REG_Pos   0UL
#define USBFS_BCD_PHY_TRIM1_TRIM_DM_R_REG_Msk   0x3FUL
/* USBFS_BCD.PHY_TRIM2 */
#define USBFS_BCD_PHY_TRIM2_TRIM_DP_R_BYPASS_Pos 0UL
#define USBFS_BCD_PHY_TRIM2_TRIM_DP_R_BYPASS_Msk 0x3FUL
/* USBFS_BCD.PHY_TRIM3 */
#define USBFS_BCD_PHY_TRIM3_TRIM_DM_R_BYPASS_Pos 0UL
#define USBFS_BCD_PHY_TRIM3_TRIM_DM_R_BYPASS_Msk 0x3FUL
/* USBFS_BCD.CHGDET_TRIM */
#define USBFS_BCD_CHGDET_TRIM_V325M_TRIM_Pos    0UL
#define USBFS_BCD_CHGDET_TRIM_V325M_TRIM_Msk    0x3UL
#define USBFS_BCD_CHGDET_TRIM_V600M_TRIM_Pos    4UL
#define USBFS_BCD_CHGDET_TRIM_V600M_TRIM_Msk    0x70UL
/* USBFS_BCD.TRIM */
#define USBFS_BCD_TRIM_DM_PD_VAL_Pos            0UL
#define USBFS_BCD_TRIM_DM_PD_VAL_Msk            0x3UL
/* USBFS_BCD.USBIO_TRIM */
#define USBFS_BCD_USBIO_TRIM_TRIM_Pos           0UL
#define USBFS_BCD_USBIO_TRIM_TRIM_Msk           0x3UL
#define USBFS_BCD_USBIO_TRIM_MDEC_Pos           2UL
#define USBFS_BCD_USBIO_TRIM_MDEC_Msk           0x4UL
#define USBFS_BCD_USBIO_TRIM_MINC_Pos           3UL
#define USBFS_BCD_USBIO_TRIM_MINC_Msk           0x8UL
#define USBFS_BCD_USBIO_TRIM_X_INC_Pos          4UL
#define USBFS_BCD_USBIO_TRIM_X_INC_Msk          0x10UL
#define USBFS_BCD_USBIO_TRIM_X_DEC_Pos          5UL
#define USBFS_BCD_USBIO_TRIM_X_DEC_Msk          0x20UL


/* USBFS.EP0_DR */
#define USBFS_EP0_DR_DATA_BYTE_Pos              0UL
#define USBFS_EP0_DR_DATA_BYTE_Msk              0xFFUL
/* USBFS.CR0 */
#define USBFS_CR0_DEVICE_ADDRESS_Pos            0UL
#define USBFS_CR0_DEVICE_ADDRESS_Msk            0x7FUL
#define USBFS_CR0_USB_ENABLE_Pos                7UL
#define USBFS_CR0_USB_ENABLE_Msk                0x80UL
/* USBFS.CR1 */
#define USBFS_CR1_REG_ENABLE_Pos                0UL
#define USBFS_CR1_REG_ENABLE_Msk                0x1UL
#define USBFS_CR1_ENABLE_LOCK_Pos               1UL
#define USBFS_CR1_ENABLE_LOCK_Msk               0x2UL
#define USBFS_CR1_BUS_ACTIVITY_Pos              2UL
#define USBFS_CR1_BUS_ACTIVITY_Msk              0x4UL
#define USBFS_CR1_TRIM_OFFSET_MSB_Pos           3UL
#define USBFS_CR1_TRIM_OFFSET_MSB_Msk           0x8UL
/* USBFS.SIE_EP_INT_EN */
#define USBFS_SIE_EP_INT_EN_EP1_INTR_EN_Pos     0UL
#define USBFS_SIE_EP_INT_EN_EP1_INTR_EN_Msk     0x1UL
#define USBFS_SIE_EP_INT_EN_EP2_INTR_EN_Pos     1UL
#define USBFS_SIE_EP_INT_EN_EP2_INTR_EN_Msk     0x2UL
#define USBFS_SIE_EP_INT_EN_EP3_INTR_EN_Pos     2UL
#define USBFS_SIE_EP_INT_EN_EP3_INTR_EN_Msk     0x4UL
#define USBFS_SIE_EP_INT_EN_EP4_INTR_EN_Pos     3UL
#define USBFS_SIE_EP_INT_EN_EP4_INTR_EN_Msk     0x8UL
#define USBFS_SIE_EP_INT_EN_EP5_INTR_EN_Pos     4UL
#define USBFS_SIE_EP_INT_EN_EP5_INTR_EN_Msk     0x10UL
#define USBFS_SIE_EP_INT_EN_EP6_INTR_EN_Pos     5UL
#define USBFS_SIE_EP_INT_EN_EP6_INTR_EN_Msk     0x20UL
#define USBFS_SIE_EP_INT_EN_EP7_INTR_EN_Pos     6UL
#define USBFS_SIE_EP_INT_EN_EP7_INTR_EN_Msk     0x40UL
#define USBFS_SIE_EP_INT_EN_EP8_INTR_EN_Pos     7UL
#define USBFS_SIE_EP_INT_EN_EP8_INTR_EN_Msk     0x80UL
/* USBFS.SIE_EP_INT_SR */
#define USBFS_SIE_EP_INT_SR_EP1_INTR_Pos        0UL
#define USBFS_SIE_EP_INT_SR_EP1_INTR_Msk        0x1UL
#define USBFS_SIE_EP_INT_SR_EP2_INTR_Pos        1UL
#define USBFS_SIE_EP_INT_SR_EP2_INTR_Msk        0x2UL
#define USBFS_SIE_EP_INT_SR_EP3_INTR_Pos        2UL
#define USBFS_SIE_EP_INT_SR_EP3_INTR_Msk        0x4UL
#define USBFS_SIE_EP_INT_SR_EP4_INTR_Pos        3UL
#define USBFS_SIE_EP_INT_SR_EP4_INTR_Msk        0x8UL
#define USBFS_SIE_EP_INT_SR_EP5_INTR_Pos        4UL
#define USBFS_SIE_EP_INT_SR_EP5_INTR_Msk        0x10UL
#define USBFS_SIE_EP_INT_SR_EP6_INTR_Pos        5UL
#define USBFS_SIE_EP_INT_SR_EP6_INTR_Msk        0x20UL
#define USBFS_SIE_EP_INT_SR_EP7_INTR_Pos        6UL
#define USBFS_SIE_EP_INT_SR_EP7_INTR_Msk        0x40UL
#define USBFS_SIE_EP_INT_SR_EP8_INTR_Pos        7UL
#define USBFS_SIE_EP_INT_SR_EP8_INTR_Msk        0x80UL
/* USBFS.SIE_EP1_CNT0 */
#define USBFS_SIE_EP1_CNT0_DATA_COUNT_MSB_Pos   0UL
#define USBFS_SIE_EP1_CNT0_DATA_COUNT_MSB_Msk   0x7UL
#define USBFS_SIE_EP1_CNT0_DATA_VALID_Pos       6UL
#define USBFS_SIE_EP1_CNT0_DATA_VALID_Msk       0x40UL
#define USBFS_SIE_EP1_CNT0_DATA_TOGGLE_Pos      7UL
#define USBFS_SIE_EP1_CNT0_DATA_TOGGLE_Msk      0x80UL
/* USBFS.SIE_EP1_CNT1 */
#define USBFS_SIE_EP1_CNT1_DATA_COUNT_Pos       0UL
#define USBFS_SIE_EP1_CNT1_DATA_COUNT_Msk       0xFFUL
/* USBFS.SIE_EP1_CR0 */
#define USBFS_SIE_EP1_CR0_MODE_Pos              0UL
#define USBFS_SIE_EP1_CR0_MODE_Msk              0xFUL
#define USBFS_SIE_EP1_CR0_ACKED_TXN_Pos         4UL
#define USBFS_SIE_EP1_CR0_ACKED_TXN_Msk         0x10UL
#define USBFS_SIE_EP1_CR0_NAK_INT_EN_Pos        5UL
#define USBFS_SIE_EP1_CR0_NAK_INT_EN_Msk        0x20UL
#define USBFS_SIE_EP1_CR0_ERR_IN_TXN_Pos        6UL
#define USBFS_SIE_EP1_CR0_ERR_IN_TXN_Msk        0x40UL
#define USBFS_SIE_EP1_CR0_STALL_Pos             7UL
#define USBFS_SIE_EP1_CR0_STALL_Msk             0x80UL
/* USBFS.USBIO_CR0 */
#define USBFS_USBIO_CR0_RD_Pos                  0UL
#define USBFS_USBIO_CR0_RD_Msk                  0x1UL
#define USBFS_USBIO_CR0_TD_Pos                  5UL
#define USBFS_USBIO_CR0_TD_Msk                  0x20UL
#define USBFS_USBIO_CR0_TSE0_Pos                6UL
#define USBFS_USBIO_CR0_TSE0_Msk                0x40UL
#define USBFS_USBIO_CR0_TEN_Pos                 7UL
#define USBFS_USBIO_CR0_TEN_Msk                 0x80UL
/* USBFS.USBIO_CR2 */
#define USBFS_USBIO_CR2_RESERVED_Pos            0UL
#define USBFS_USBIO_CR2_RESERVED_Msk            0x3FUL
#define USBFS_USBIO_CR2_TEST_PKT_Pos            6UL
#define USBFS_USBIO_CR2_TEST_PKT_Msk            0x40UL
#define USBFS_USBIO_CR2_TEST_RES_Pos            7UL
#define USBFS_USBIO_CR2_TEST_RES_Msk            0x80UL
/* USBFS.USBIO_CR1 */
#define USBFS_USBIO_CR1_DMO_Pos                 0UL
#define USBFS_USBIO_CR1_DMO_Msk                 0x1UL
#define USBFS_USBIO_CR1_DPO_Pos                 1UL
#define USBFS_USBIO_CR1_DPO_Msk                 0x2UL
#define USBFS_USBIO_CR1_USBPUEN_Pos             2UL
#define USBFS_USBIO_CR1_USBPUEN_Msk             0x4UL
#define USBFS_USBIO_CR1_IOMODE_Pos              5UL
#define USBFS_USBIO_CR1_IOMODE_Msk              0x20UL
/* USBFS.DYN_RECONFIG */
#define USBFS_DYN_RECONFIG_DYN_CONFIG_EN_Pos    0UL
#define USBFS_DYN_RECONFIG_DYN_CONFIG_EN_Msk    0x1UL
#define USBFS_DYN_RECONFIG_DYN_RECONFIG_EPNO_Pos 1UL
#define USBFS_DYN_RECONFIG_DYN_RECONFIG_EPNO_Msk 0xEUL
#define USBFS_DYN_RECONFIG_DYN_RECONFIG_RDY_STS_Pos 4UL
#define USBFS_DYN_RECONFIG_DYN_RECONFIG_RDY_STS_Msk 0x10UL
/* USBFS.SOF0 */
#define USBFS_SOF0_FRAME_NUMBER_Pos             0UL
#define USBFS_SOF0_FRAME_NUMBER_Msk             0xFFUL
/* USBFS.SOF1 */
#define USBFS_SOF1_FRAME_NUMBER_MSB_Pos         0UL
#define USBFS_SOF1_FRAME_NUMBER_MSB_Msk         0x7UL
/* USBFS.SIE_EP2_CNT0 */
#define USBFS_SIE_EP2_CNT0_DATA_COUNT_MSB_Pos   0UL
#define USBFS_SIE_EP2_CNT0_DATA_COUNT_MSB_Msk   0x7UL
#define USBFS_SIE_EP2_CNT0_DATA_VALID_Pos       6UL
#define USBFS_SIE_EP2_CNT0_DATA_VALID_Msk       0x40UL
#define USBFS_SIE_EP2_CNT0_DATA_TOGGLE_Pos      7UL
#define USBFS_SIE_EP2_CNT0_DATA_TOGGLE_Msk      0x80UL
/* USBFS.SIE_EP2_CNT1 */
#define USBFS_SIE_EP2_CNT1_DATA_COUNT_Pos       0UL
#define USBFS_SIE_EP2_CNT1_DATA_COUNT_Msk       0xFFUL
/* USBFS.SIE_EP2_CR0 */
#define USBFS_SIE_EP2_CR0_MODE_Pos              0UL
#define USBFS_SIE_EP2_CR0_MODE_Msk              0xFUL
#define USBFS_SIE_EP2_CR0_ACKED_TXN_Pos         4UL
#define USBFS_SIE_EP2_CR0_ACKED_TXN_Msk         0x10UL
#define USBFS_SIE_EP2_CR0_NAK_INT_EN_Pos        5UL
#define USBFS_SIE_EP2_CR0_NAK_INT_EN_Msk        0x20UL
#define USBFS_SIE_EP2_CR0_ERR_IN_TXN_Pos        6UL
#define USBFS_SIE_EP2_CR0_ERR_IN_TXN_Msk        0x40UL
#define USBFS_SIE_EP2_CR0_STALL_Pos             7UL
#define USBFS_SIE_EP2_CR0_STALL_Msk             0x80UL
/* USBFS.OSCLK_DR0 */
#define USBFS_OSCLK_DR0_ADDER_Pos               0UL
#define USBFS_OSCLK_DR0_ADDER_Msk               0xFFUL
/* USBFS.OSCLK_DR1 */
#define USBFS_OSCLK_DR1_ADDER_MSB_Pos           0UL
#define USBFS_OSCLK_DR1_ADDER_MSB_Msk           0x7FUL
/* USBFS.EP0_CR */
#define USBFS_EP0_CR_MODE_Pos                   0UL
#define USBFS_EP0_CR_MODE_Msk                   0xFUL
#define USBFS_EP0_CR_ACKED_TXN_Pos              4UL
#define USBFS_EP0_CR_ACKED_TXN_Msk              0x10UL
#define USBFS_EP0_CR_OUT_RCVD_Pos               5UL
#define USBFS_EP0_CR_OUT_RCVD_Msk               0x20UL
#define USBFS_EP0_CR_IN_RCVD_Pos                6UL
#define USBFS_EP0_CR_IN_RCVD_Msk                0x40UL
#define USBFS_EP0_CR_SETUP_RCVD_Pos             7UL
#define USBFS_EP0_CR_SETUP_RCVD_Msk             0x80UL
/* USBFS.EP0_CNT */
#define USBFS_EP0_CNT_BYTE_COUNT_Pos            0UL
#define USBFS_EP0_CNT_BYTE_COUNT_Msk            0xFUL
#define USBFS_EP0_CNT_DATA_VALID_Pos            6UL
#define USBFS_EP0_CNT_DATA_VALID_Msk            0x40UL
#define USBFS_EP0_CNT_DATA_TOGGLE_Pos           7UL
#define USBFS_EP0_CNT_DATA_TOGGLE_Msk           0x80UL
/* USBFS.SIE_EP3_CNT0 */
#define USBFS_SIE_EP3_CNT0_DATA_COUNT_MSB_Pos   0UL
#define USBFS_SIE_EP3_CNT0_DATA_COUNT_MSB_Msk   0x7UL
#define USBFS_SIE_EP3_CNT0_DATA_VALID_Pos       6UL
#define USBFS_SIE_EP3_CNT0_DATA_VALID_Msk       0x40UL
#define USBFS_SIE_EP3_CNT0_DATA_TOGGLE_Pos      7UL
#define USBFS_SIE_EP3_CNT0_DATA_TOGGLE_Msk      0x80UL
/* USBFS.SIE_EP3_CNT1 */
#define USBFS_SIE_EP3_CNT1_DATA_COUNT_Pos       0UL
#define USBFS_SIE_EP3_CNT1_DATA_COUNT_Msk       0xFFUL
/* USBFS.SIE_EP3_CR0 */
#define USBFS_SIE_EP3_CR0_MODE_Pos              0UL
#define USBFS_SIE_EP3_CR0_MODE_Msk              0xFUL
#define USBFS_SIE_EP3_CR0_ACKED_TXN_Pos         4UL
#define USBFS_SIE_EP3_CR0_ACKED_TXN_Msk         0x10UL
#define USBFS_SIE_EP3_CR0_NAK_INT_EN_Pos        5UL
#define USBFS_SIE_EP3_CR0_NAK_INT_EN_Msk        0x20UL
#define USBFS_SIE_EP3_CR0_ERR_IN_TXN_Pos        6UL
#define USBFS_SIE_EP3_CR0_ERR_IN_TXN_Msk        0x40UL
#define USBFS_SIE_EP3_CR0_STALL_Pos             7UL
#define USBFS_SIE_EP3_CR0_STALL_Msk             0x80UL
/* USBFS.SIE_EP4_CNT0 */
#define USBFS_SIE_EP4_CNT0_DATA_COUNT_MSB_Pos   0UL
#define USBFS_SIE_EP4_CNT0_DATA_COUNT_MSB_Msk   0x7UL
#define USBFS_SIE_EP4_CNT0_DATA_VALID_Pos       6UL
#define USBFS_SIE_EP4_CNT0_DATA_VALID_Msk       0x40UL
#define USBFS_SIE_EP4_CNT0_DATA_TOGGLE_Pos      7UL
#define USBFS_SIE_EP4_CNT0_DATA_TOGGLE_Msk      0x80UL
/* USBFS.SIE_EP4_CNT1 */
#define USBFS_SIE_EP4_CNT1_DATA_COUNT_Pos       0UL
#define USBFS_SIE_EP4_CNT1_DATA_COUNT_Msk       0xFFUL
/* USBFS.SIE_EP4_CR0 */
#define USBFS_SIE_EP4_CR0_MODE_Pos              0UL
#define USBFS_SIE_EP4_CR0_MODE_Msk              0xFUL
#define USBFS_SIE_EP4_CR0_ACKED_TXN_Pos         4UL
#define USBFS_SIE_EP4_CR0_ACKED_TXN_Msk         0x10UL
#define USBFS_SIE_EP4_CR0_NAK_INT_EN_Pos        5UL
#define USBFS_SIE_EP4_CR0_NAK_INT_EN_Msk        0x20UL
#define USBFS_SIE_EP4_CR0_ERR_IN_TXN_Pos        6UL
#define USBFS_SIE_EP4_CR0_ERR_IN_TXN_Msk        0x40UL
#define USBFS_SIE_EP4_CR0_STALL_Pos             7UL
#define USBFS_SIE_EP4_CR0_STALL_Msk             0x80UL
/* USBFS.SIE_EP5_CNT0 */
#define USBFS_SIE_EP5_CNT0_DATA_COUNT_MSB_Pos   0UL
#define USBFS_SIE_EP5_CNT0_DATA_COUNT_MSB_Msk   0x7UL
#define USBFS_SIE_EP5_CNT0_DATA_VALID_Pos       6UL
#define USBFS_SIE_EP5_CNT0_DATA_VALID_Msk       0x40UL
#define USBFS_SIE_EP5_CNT0_DATA_TOGGLE_Pos      7UL
#define USBFS_SIE_EP5_CNT0_DATA_TOGGLE_Msk      0x80UL
/* USBFS.SIE_EP5_CNT1 */
#define USBFS_SIE_EP5_CNT1_DATA_COUNT_Pos       0UL
#define USBFS_SIE_EP5_CNT1_DATA_COUNT_Msk       0xFFUL
/* USBFS.SIE_EP5_CR0 */
#define USBFS_SIE_EP5_CR0_MODE_Pos              0UL
#define USBFS_SIE_EP5_CR0_MODE_Msk              0xFUL
#define USBFS_SIE_EP5_CR0_ACKED_TXN_Pos         4UL
#define USBFS_SIE_EP5_CR0_ACKED_TXN_Msk         0x10UL
#define USBFS_SIE_EP5_CR0_NAK_INT_EN_Pos        5UL
#define USBFS_SIE_EP5_CR0_NAK_INT_EN_Msk        0x20UL
#define USBFS_SIE_EP5_CR0_ERR_IN_TXN_Pos        6UL
#define USBFS_SIE_EP5_CR0_ERR_IN_TXN_Msk        0x40UL
#define USBFS_SIE_EP5_CR0_STALL_Pos             7UL
#define USBFS_SIE_EP5_CR0_STALL_Msk             0x80UL
/* USBFS.SIE_EP6_CNT0 */
#define USBFS_SIE_EP6_CNT0_DATA_COUNT_MSB_Pos   0UL
#define USBFS_SIE_EP6_CNT0_DATA_COUNT_MSB_Msk   0x7UL
#define USBFS_SIE_EP6_CNT0_DATA_VALID_Pos       6UL
#define USBFS_SIE_EP6_CNT0_DATA_VALID_Msk       0x40UL
#define USBFS_SIE_EP6_CNT0_DATA_TOGGLE_Pos      7UL
#define USBFS_SIE_EP6_CNT0_DATA_TOGGLE_Msk      0x80UL
/* USBFS.SIE_EP6_CNT1 */
#define USBFS_SIE_EP6_CNT1_DATA_COUNT_Pos       0UL
#define USBFS_SIE_EP6_CNT1_DATA_COUNT_Msk       0xFFUL
/* USBFS.SIE_EP6_CR0 */
#define USBFS_SIE_EP6_CR0_MODE_Pos              0UL
#define USBFS_SIE_EP6_CR0_MODE_Msk              0xFUL
#define USBFS_SIE_EP6_CR0_ACKED_TXN_Pos         4UL
#define USBFS_SIE_EP6_CR0_ACKED_TXN_Msk         0x10UL
#define USBFS_SIE_EP6_CR0_NAK_INT_EN_Pos        5UL
#define USBFS_SIE_EP6_CR0_NAK_INT_EN_Msk        0x20UL
#define USBFS_SIE_EP6_CR0_ERR_IN_TXN_Pos        6UL
#define USBFS_SIE_EP6_CR0_ERR_IN_TXN_Msk        0x40UL
#define USBFS_SIE_EP6_CR0_STALL_Pos             7UL
#define USBFS_SIE_EP6_CR0_STALL_Msk             0x80UL
/* USBFS.SIE_EP7_CNT0 */
#define USBFS_SIE_EP7_CNT0_DATA_COUNT_MSB_Pos   0UL
#define USBFS_SIE_EP7_CNT0_DATA_COUNT_MSB_Msk   0x7UL
#define USBFS_SIE_EP7_CNT0_DATA_VALID_Pos       6UL
#define USBFS_SIE_EP7_CNT0_DATA_VALID_Msk       0x40UL
#define USBFS_SIE_EP7_CNT0_DATA_TOGGLE_Pos      7UL
#define USBFS_SIE_EP7_CNT0_DATA_TOGGLE_Msk      0x80UL
/* USBFS.SIE_EP7_CNT1 */
#define USBFS_SIE_EP7_CNT1_DATA_COUNT_Pos       0UL
#define USBFS_SIE_EP7_CNT1_DATA_COUNT_Msk       0xFFUL
/* USBFS.SIE_EP7_CR0 */
#define USBFS_SIE_EP7_CR0_MODE_Pos              0UL
#define USBFS_SIE_EP7_CR0_MODE_Msk              0xFUL
#define USBFS_SIE_EP7_CR0_ACKED_TXN_Pos         4UL
#define USBFS_SIE_EP7_CR0_ACKED_TXN_Msk         0x10UL
#define USBFS_SIE_EP7_CR0_NAK_INT_EN_Pos        5UL
#define USBFS_SIE_EP7_CR0_NAK_INT_EN_Msk        0x20UL
#define USBFS_SIE_EP7_CR0_ERR_IN_TXN_Pos        6UL
#define USBFS_SIE_EP7_CR0_ERR_IN_TXN_Msk        0x40UL
#define USBFS_SIE_EP7_CR0_STALL_Pos             7UL
#define USBFS_SIE_EP7_CR0_STALL_Msk             0x80UL
/* USBFS.SIE_EP8_CNT0 */
#define USBFS_SIE_EP8_CNT0_DATA_COUNT_MSB_Pos   0UL
#define USBFS_SIE_EP8_CNT0_DATA_COUNT_MSB_Msk   0x7UL
#define USBFS_SIE_EP8_CNT0_DATA_VALID_Pos       6UL
#define USBFS_SIE_EP8_CNT0_DATA_VALID_Msk       0x40UL
#define USBFS_SIE_EP8_CNT0_DATA_TOGGLE_Pos      7UL
#define USBFS_SIE_EP8_CNT0_DATA_TOGGLE_Msk      0x80UL
/* USBFS.SIE_EP8_CNT1 */
#define USBFS_SIE_EP8_CNT1_DATA_COUNT_Pos       0UL
#define USBFS_SIE_EP8_CNT1_DATA_COUNT_Msk       0xFFUL
/* USBFS.SIE_EP8_CR0 */
#define USBFS_SIE_EP8_CR0_MODE_Pos              0UL
#define USBFS_SIE_EP8_CR0_MODE_Msk              0xFUL
#define USBFS_SIE_EP8_CR0_ACKED_TXN_Pos         4UL
#define USBFS_SIE_EP8_CR0_ACKED_TXN_Msk         0x10UL
#define USBFS_SIE_EP8_CR0_NAK_INT_EN_Pos        5UL
#define USBFS_SIE_EP8_CR0_NAK_INT_EN_Msk        0x20UL
#define USBFS_SIE_EP8_CR0_ERR_IN_TXN_Pos        6UL
#define USBFS_SIE_EP8_CR0_ERR_IN_TXN_Msk        0x40UL
#define USBFS_SIE_EP8_CR0_STALL_Pos             7UL
#define USBFS_SIE_EP8_CR0_STALL_Msk             0x80UL
/* USBFS.ARB_EP1_CFG */
#define USBFS_ARB_EP1_CFG_IN_DATA_RDY_Pos       0UL
#define USBFS_ARB_EP1_CFG_IN_DATA_RDY_Msk       0x1UL
#define USBFS_ARB_EP1_CFG_DMA_REQ_Pos           1UL
#define USBFS_ARB_EP1_CFG_DMA_REQ_Msk           0x2UL
#define USBFS_ARB_EP1_CFG_CRC_BYPASS_Pos        2UL
#define USBFS_ARB_EP1_CFG_CRC_BYPASS_Msk        0x4UL
#define USBFS_ARB_EP1_CFG_RESET_PTR_Pos         3UL
#define USBFS_ARB_EP1_CFG_RESET_PTR_Msk         0x8UL
/* USBFS.ARB_EP1_INT_EN */
#define USBFS_ARB_EP1_INT_EN_IN_BUF_FULL_EN_Pos 0UL
#define USBFS_ARB_EP1_INT_EN_IN_BUF_FULL_EN_Msk 0x1UL
#define USBFS_ARB_EP1_INT_EN_DMA_GNT_EN_Pos     1UL
#define USBFS_ARB_EP1_INT_EN_DMA_GNT_EN_Msk     0x2UL
#define USBFS_ARB_EP1_INT_EN_BUF_OVER_EN_Pos    2UL
#define USBFS_ARB_EP1_INT_EN_BUF_OVER_EN_Msk    0x4UL
#define USBFS_ARB_EP1_INT_EN_BUF_UNDER_EN_Pos   3UL
#define USBFS_ARB_EP1_INT_EN_BUF_UNDER_EN_Msk   0x8UL
#define USBFS_ARB_EP1_INT_EN_ERR_INT_EN_Pos     4UL
#define USBFS_ARB_EP1_INT_EN_ERR_INT_EN_Msk     0x10UL
#define USBFS_ARB_EP1_INT_EN_DMA_TERMIN_EN_Pos  5UL
#define USBFS_ARB_EP1_INT_EN_DMA_TERMIN_EN_Msk  0x20UL
/* USBFS.ARB_EP1_SR */
#define USBFS_ARB_EP1_SR_IN_BUF_FULL_Pos        0UL
#define USBFS_ARB_EP1_SR_IN_BUF_FULL_Msk        0x1UL
#define USBFS_ARB_EP1_SR_DMA_GNT_Pos            1UL
#define USBFS_ARB_EP1_SR_DMA_GNT_Msk            0x2UL
#define USBFS_ARB_EP1_SR_BUF_OVER_Pos           2UL
#define USBFS_ARB_EP1_SR_BUF_OVER_Msk           0x4UL
#define USBFS_ARB_EP1_SR_BUF_UNDER_Pos          3UL
#define USBFS_ARB_EP1_SR_BUF_UNDER_Msk          0x8UL
#define USBFS_ARB_EP1_SR_DMA_TERMIN_Pos         5UL
#define USBFS_ARB_EP1_SR_DMA_TERMIN_Msk         0x20UL
/* USBFS.ARB_RW1_WA */
#define USBFS_ARB_RW1_WA_WA_Pos                 0UL
#define USBFS_ARB_RW1_WA_WA_Msk                 0xFFUL
/* USBFS.ARB_RW1_WA_MSB */
#define USBFS_ARB_RW1_WA_MSB_WA_MSB_Pos         0UL
#define USBFS_ARB_RW1_WA_MSB_WA_MSB_Msk         0x1UL
/* USBFS.ARB_RW1_RA */
#define USBFS_ARB_RW1_RA_RA_Pos                 0UL
#define USBFS_ARB_RW1_RA_RA_Msk                 0xFFUL
/* USBFS.ARB_RW1_RA_MSB */
#define USBFS_ARB_RW1_RA_MSB_RA_MSB_Pos         0UL
#define USBFS_ARB_RW1_RA_MSB_RA_MSB_Msk         0x1UL
/* USBFS.ARB_RW1_DR */
#define USBFS_ARB_RW1_DR_DR_Pos                 0UL
#define USBFS_ARB_RW1_DR_DR_Msk                 0xFFUL
/* USBFS.BUF_SIZE */
#define USBFS_BUF_SIZE_IN_BUF_Pos               0UL
#define USBFS_BUF_SIZE_IN_BUF_Msk               0xFUL
#define USBFS_BUF_SIZE_OUT_BUF_Pos              4UL
#define USBFS_BUF_SIZE_OUT_BUF_Msk              0xF0UL
/* USBFS.EP_ACTIVE */
#define USBFS_EP_ACTIVE_EP1_ACT_Pos             0UL
#define USBFS_EP_ACTIVE_EP1_ACT_Msk             0x1UL
#define USBFS_EP_ACTIVE_EP2_ACT_Pos             1UL
#define USBFS_EP_ACTIVE_EP2_ACT_Msk             0x2UL
#define USBFS_EP_ACTIVE_EP3_ACT_Pos             2UL
#define USBFS_EP_ACTIVE_EP3_ACT_Msk             0x4UL
#define USBFS_EP_ACTIVE_EP4_ACT_Pos             3UL
#define USBFS_EP_ACTIVE_EP4_ACT_Msk             0x8UL
#define USBFS_EP_ACTIVE_EP5_ACT_Pos             4UL
#define USBFS_EP_ACTIVE_EP5_ACT_Msk             0x10UL
#define USBFS_EP_ACTIVE_EP6_ACT_Pos             5UL
#define USBFS_EP_ACTIVE_EP6_ACT_Msk             0x20UL
#define USBFS_EP_ACTIVE_EP7_ACT_Pos             6UL
#define USBFS_EP_ACTIVE_EP7_ACT_Msk             0x40UL
#define USBFS_EP_ACTIVE_EP8_ACT_Pos             7UL
#define USBFS_EP_ACTIVE_EP8_ACT_Msk             0x80UL
/* USBFS.EP_TYPE */
#define USBFS_EP_TYPE_EP1_TYP_Pos               0UL
#define USBFS_EP_TYPE_EP1_TYP_Msk               0x1UL
#define USBFS_EP_TYPE_EP2_TYP_Pos               1UL
#define USBFS_EP_TYPE_EP2_TYP_Msk               0x2UL
#define USBFS_EP_TYPE_EP3_TYP_Pos               2UL
#define USBFS_EP_TYPE_EP3_TYP_Msk               0x4UL
#define USBFS_EP_TYPE_EP4_TYP_Pos               3UL
#define USBFS_EP_TYPE_EP4_TYP_Msk               0x8UL
#define USBFS_EP_TYPE_EP5_TYP_Pos               4UL
#define USBFS_EP_TYPE_EP5_TYP_Msk               0x10UL
#define USBFS_EP_TYPE_EP6_TYP_Pos               5UL
#define USBFS_EP_TYPE_EP6_TYP_Msk               0x20UL
#define USBFS_EP_TYPE_EP7_TYP_Pos               6UL
#define USBFS_EP_TYPE_EP7_TYP_Msk               0x40UL
#define USBFS_EP_TYPE_EP8_TYP_Pos               7UL
#define USBFS_EP_TYPE_EP8_TYP_Msk               0x80UL
/* USBFS.ARB_EP2_CFG */
#define USBFS_ARB_EP2_CFG_IN_DATA_RDY_Pos       0UL
#define USBFS_ARB_EP2_CFG_IN_DATA_RDY_Msk       0x1UL
#define USBFS_ARB_EP2_CFG_DMA_REQ_Pos           1UL
#define USBFS_ARB_EP2_CFG_DMA_REQ_Msk           0x2UL
#define USBFS_ARB_EP2_CFG_CRC_BYPASS_Pos        2UL
#define USBFS_ARB_EP2_CFG_CRC_BYPASS_Msk        0x4UL
#define USBFS_ARB_EP2_CFG_RESET_PTR_Pos         3UL
#define USBFS_ARB_EP2_CFG_RESET_PTR_Msk         0x8UL
/* USBFS.ARB_EP2_INT_EN */
#define USBFS_ARB_EP2_INT_EN_IN_BUF_FULL_EN_Pos 0UL
#define USBFS_ARB_EP2_INT_EN_IN_BUF_FULL_EN_Msk 0x1UL
#define USBFS_ARB_EP2_INT_EN_DMA_GNT_EN_Pos     1UL
#define USBFS_ARB_EP2_INT_EN_DMA_GNT_EN_Msk     0x2UL
#define USBFS_ARB_EP2_INT_EN_BUF_OVER_EN_Pos    2UL
#define USBFS_ARB_EP2_INT_EN_BUF_OVER_EN_Msk    0x4UL
#define USBFS_ARB_EP2_INT_EN_BUF_UNDER_EN_Pos   3UL
#define USBFS_ARB_EP2_INT_EN_BUF_UNDER_EN_Msk   0x8UL
#define USBFS_ARB_EP2_INT_EN_ERR_INT_EN_Pos     4UL
#define USBFS_ARB_EP2_INT_EN_ERR_INT_EN_Msk     0x10UL
#define USBFS_ARB_EP2_INT_EN_DMA_TERMIN_EN_Pos  5UL
#define USBFS_ARB_EP2_INT_EN_DMA_TERMIN_EN_Msk  0x20UL
/* USBFS.ARB_EP2_SR */
#define USBFS_ARB_EP2_SR_IN_BUF_FULL_Pos        0UL
#define USBFS_ARB_EP2_SR_IN_BUF_FULL_Msk        0x1UL
#define USBFS_ARB_EP2_SR_DMA_GNT_Pos            1UL
#define USBFS_ARB_EP2_SR_DMA_GNT_Msk            0x2UL
#define USBFS_ARB_EP2_SR_BUF_OVER_Pos           2UL
#define USBFS_ARB_EP2_SR_BUF_OVER_Msk           0x4UL
#define USBFS_ARB_EP2_SR_BUF_UNDER_Pos          3UL
#define USBFS_ARB_EP2_SR_BUF_UNDER_Msk          0x8UL
#define USBFS_ARB_EP2_SR_DMA_TERMIN_Pos         5UL
#define USBFS_ARB_EP2_SR_DMA_TERMIN_Msk         0x20UL
/* USBFS.ARB_RW2_WA */
#define USBFS_ARB_RW2_WA_WA_Pos                 0UL
#define USBFS_ARB_RW2_WA_WA_Msk                 0xFFUL
/* USBFS.ARB_RW2_WA_MSB */
#define USBFS_ARB_RW2_WA_MSB_WA_MSB_Pos         0UL
#define USBFS_ARB_RW2_WA_MSB_WA_MSB_Msk         0x1UL
/* USBFS.ARB_RW2_RA */
#define USBFS_ARB_RW2_RA_RA_Pos                 0UL
#define USBFS_ARB_RW2_RA_RA_Msk                 0xFFUL
/* USBFS.ARB_RW2_RA_MSB */
#define USBFS_ARB_RW2_RA_MSB_RA_MSB_Pos         0UL
#define USBFS_ARB_RW2_RA_MSB_RA_MSB_Msk         0x1UL
/* USBFS.ARB_RW2_DR */
#define USBFS_ARB_RW2_DR_DR_Pos                 0UL
#define USBFS_ARB_RW2_DR_DR_Msk                 0xFFUL
/* USBFS.ARB_CFG */
#define USBFS_ARB_CFG_AUTO_MEM_Pos              4UL
#define USBFS_ARB_CFG_AUTO_MEM_Msk              0x10UL
#define USBFS_ARB_CFG_DMA_CFG_Pos               5UL
#define USBFS_ARB_CFG_DMA_CFG_Msk               0x60UL
#define USBFS_ARB_CFG_CFG_CMP_Pos               7UL
#define USBFS_ARB_CFG_CFG_CMP_Msk               0x80UL
/* USBFS.USB_CLK_EN */
#define USBFS_USB_CLK_EN_CSR_CLK_EN_Pos         0UL
#define USBFS_USB_CLK_EN_CSR_CLK_EN_Msk         0x1UL
/* USBFS.ARB_INT_EN */
#define USBFS_ARB_INT_EN_EP1_INTR_EN_Pos        0UL
#define USBFS_ARB_INT_EN_EP1_INTR_EN_Msk        0x1UL
#define USBFS_ARB_INT_EN_EP2_INTR_EN_Pos        1UL
#define USBFS_ARB_INT_EN_EP2_INTR_EN_Msk        0x2UL
#define USBFS_ARB_INT_EN_EP3_INTR_EN_Pos        2UL
#define USBFS_ARB_INT_EN_EP3_INTR_EN_Msk        0x4UL
#define USBFS_ARB_INT_EN_EP4_INTR_EN_Pos        3UL
#define USBFS_ARB_INT_EN_EP4_INTR_EN_Msk        0x8UL
#define USBFS_ARB_INT_EN_EP5_INTR_EN_Pos        4UL
#define USBFS_ARB_INT_EN_EP5_INTR_EN_Msk        0x10UL
#define USBFS_ARB_INT_EN_EP6_INTR_EN_Pos        5UL
#define USBFS_ARB_INT_EN_EP6_INTR_EN_Msk        0x20UL
#define USBFS_ARB_INT_EN_EP7_INTR_EN_Pos        6UL
#define USBFS_ARB_INT_EN_EP7_INTR_EN_Msk        0x40UL
#define USBFS_ARB_INT_EN_EP8_INTR_EN_Pos        7UL
#define USBFS_ARB_INT_EN_EP8_INTR_EN_Msk        0x80UL
/* USBFS.ARB_INT_SR */
#define USBFS_ARB_INT_SR_EP1_INTR_Pos           0UL
#define USBFS_ARB_INT_SR_EP1_INTR_Msk           0x1UL
#define USBFS_ARB_INT_SR_EP2_INTR_Pos           1UL
#define USBFS_ARB_INT_SR_EP2_INTR_Msk           0x2UL
#define USBFS_ARB_INT_SR_EP3_INTR_Pos           2UL
#define USBFS_ARB_INT_SR_EP3_INTR_Msk           0x4UL
#define USBFS_ARB_INT_SR_EP4_INTR_Pos           3UL
#define USBFS_ARB_INT_SR_EP4_INTR_Msk           0x8UL
#define USBFS_ARB_INT_SR_EP5_INTR_Pos           4UL
#define USBFS_ARB_INT_SR_EP5_INTR_Msk           0x10UL
#define USBFS_ARB_INT_SR_EP6_INTR_Pos           5UL
#define USBFS_ARB_INT_SR_EP6_INTR_Msk           0x20UL
#define USBFS_ARB_INT_SR_EP7_INTR_Pos           6UL
#define USBFS_ARB_INT_SR_EP7_INTR_Msk           0x40UL
#define USBFS_ARB_INT_SR_EP8_INTR_Pos           7UL
#define USBFS_ARB_INT_SR_EP8_INTR_Msk           0x80UL
/* USBFS.ARB_EP3_CFG */
#define USBFS_ARB_EP3_CFG_IN_DATA_RDY_Pos       0UL
#define USBFS_ARB_EP3_CFG_IN_DATA_RDY_Msk       0x1UL
#define USBFS_ARB_EP3_CFG_DMA_REQ_Pos           1UL
#define USBFS_ARB_EP3_CFG_DMA_REQ_Msk           0x2UL
#define USBFS_ARB_EP3_CFG_CRC_BYPASS_Pos        2UL
#define USBFS_ARB_EP3_CFG_CRC_BYPASS_Msk        0x4UL
#define USBFS_ARB_EP3_CFG_RESET_PTR_Pos         3UL
#define USBFS_ARB_EP3_CFG_RESET_PTR_Msk         0x8UL
/* USBFS.ARB_EP3_INT_EN */
#define USBFS_ARB_EP3_INT_EN_IN_BUF_FULL_EN_Pos 0UL
#define USBFS_ARB_EP3_INT_EN_IN_BUF_FULL_EN_Msk 0x1UL
#define USBFS_ARB_EP3_INT_EN_DMA_GNT_EN_Pos     1UL
#define USBFS_ARB_EP3_INT_EN_DMA_GNT_EN_Msk     0x2UL
#define USBFS_ARB_EP3_INT_EN_BUF_OVER_EN_Pos    2UL
#define USBFS_ARB_EP3_INT_EN_BUF_OVER_EN_Msk    0x4UL
#define USBFS_ARB_EP3_INT_EN_BUF_UNDER_EN_Pos   3UL
#define USBFS_ARB_EP3_INT_EN_BUF_UNDER_EN_Msk   0x8UL
#define USBFS_ARB_EP3_INT_EN_ERR_INT_EN_Pos     4UL
#define USBFS_ARB_EP3_INT_EN_ERR_INT_EN_Msk     0x10UL
#define USBFS_ARB_EP3_INT_EN_DMA_TERMIN_EN_Pos  5UL
#define USBFS_ARB_EP3_INT_EN_DMA_TERMIN_EN_Msk  0x20UL
/* USBFS.ARB_EP3_SR */
#define USBFS_ARB_EP3_SR_IN_BUF_FULL_Pos        0UL
#define USBFS_ARB_EP3_SR_IN_BUF_FULL_Msk        0x1UL
#define USBFS_ARB_EP3_SR_DMA_GNT_Pos            1UL
#define USBFS_ARB_EP3_SR_DMA_GNT_Msk            0x2UL
#define USBFS_ARB_EP3_SR_BUF_OVER_Pos           2UL
#define USBFS_ARB_EP3_SR_BUF_OVER_Msk           0x4UL
#define USBFS_ARB_EP3_SR_BUF_UNDER_Pos          3UL
#define USBFS_ARB_EP3_SR_BUF_UNDER_Msk          0x8UL
#define USBFS_ARB_EP3_SR_DMA_TERMIN_Pos         5UL
#define USBFS_ARB_EP3_SR_DMA_TERMIN_Msk         0x20UL
/* USBFS.ARB_RW3_WA */
#define USBFS_ARB_RW3_WA_WA_Pos                 0UL
#define USBFS_ARB_RW3_WA_WA_Msk                 0xFFUL
/* USBFS.ARB_RW3_WA_MSB */
#define USBFS_ARB_RW3_WA_MSB_WA_MSB_Pos         0UL
#define USBFS_ARB_RW3_WA_MSB_WA_MSB_Msk         0x1UL
/* USBFS.ARB_RW3_RA */
#define USBFS_ARB_RW3_RA_RA_Pos                 0UL
#define USBFS_ARB_RW3_RA_RA_Msk                 0xFFUL
/* USBFS.ARB_RW3_RA_MSB */
#define USBFS_ARB_RW3_RA_MSB_RA_MSB_Pos         0UL
#define USBFS_ARB_RW3_RA_MSB_RA_MSB_Msk         0x1UL
/* USBFS.ARB_RW3_DR */
#define USBFS_ARB_RW3_DR_DR_Pos                 0UL
#define USBFS_ARB_RW3_DR_DR_Msk                 0xFFUL
/* USBFS.CWA */
#define USBFS_CWA_CWA_Pos                       0UL
#define USBFS_CWA_CWA_Msk                       0xFFUL
/* USBFS.CWA_MSB */
#define USBFS_CWA_MSB_CWA_MSB_Pos               0UL
#define USBFS_CWA_MSB_CWA_MSB_Msk               0x1UL
/* USBFS.ARB_EP4_CFG */
#define USBFS_ARB_EP4_CFG_IN_DATA_RDY_Pos       0UL
#define USBFS_ARB_EP4_CFG_IN_DATA_RDY_Msk       0x1UL
#define USBFS_ARB_EP4_CFG_DMA_REQ_Pos           1UL
#define USBFS_ARB_EP4_CFG_DMA_REQ_Msk           0x2UL
#define USBFS_ARB_EP4_CFG_CRC_BYPASS_Pos        2UL
#define USBFS_ARB_EP4_CFG_CRC_BYPASS_Msk        0x4UL
#define USBFS_ARB_EP4_CFG_RESET_PTR_Pos         3UL
#define USBFS_ARB_EP4_CFG_RESET_PTR_Msk         0x8UL
/* USBFS.ARB_EP4_INT_EN */
#define USBFS_ARB_EP4_INT_EN_IN_BUF_FULL_EN_Pos 0UL
#define USBFS_ARB_EP4_INT_EN_IN_BUF_FULL_EN_Msk 0x1UL
#define USBFS_ARB_EP4_INT_EN_DMA_GNT_EN_Pos     1UL
#define USBFS_ARB_EP4_INT_EN_DMA_GNT_EN_Msk     0x2UL
#define USBFS_ARB_EP4_INT_EN_BUF_OVER_EN_Pos    2UL
#define USBFS_ARB_EP4_INT_EN_BUF_OVER_EN_Msk    0x4UL
#define USBFS_ARB_EP4_INT_EN_BUF_UNDER_EN_Pos   3UL
#define USBFS_ARB_EP4_INT_EN_BUF_UNDER_EN_Msk   0x8UL
#define USBFS_ARB_EP4_INT_EN_ERR_INT_EN_Pos     4UL
#define USBFS_ARB_EP4_INT_EN_ERR_INT_EN_Msk     0x10UL
#define USBFS_ARB_EP4_INT_EN_DMA_TERMIN_EN_Pos  5UL
#define USBFS_ARB_EP4_INT_EN_DMA_TERMIN_EN_Msk  0x20UL
/* USBFS.ARB_EP4_SR */
#define USBFS_ARB_EP4_SR_IN_BUF_FULL_Pos        0UL
#define USBFS_ARB_EP4_SR_IN_BUF_FULL_Msk        0x1UL
#define USBFS_ARB_EP4_SR_DMA_GNT_Pos            1UL
#define USBFS_ARB_EP4_SR_DMA_GNT_Msk            0x2UL
#define USBFS_ARB_EP4_SR_BUF_OVER_Pos           2UL
#define USBFS_ARB_EP4_SR_BUF_OVER_Msk           0x4UL
#define USBFS_ARB_EP4_SR_BUF_UNDER_Pos          3UL
#define USBFS_ARB_EP4_SR_BUF_UNDER_Msk          0x8UL
#define USBFS_ARB_EP4_SR_DMA_TERMIN_Pos         5UL
#define USBFS_ARB_EP4_SR_DMA_TERMIN_Msk         0x20UL
/* USBFS.ARB_RW4_WA */
#define USBFS_ARB_RW4_WA_WA_Pos                 0UL
#define USBFS_ARB_RW4_WA_WA_Msk                 0xFFUL
/* USBFS.ARB_RW4_WA_MSB */
#define USBFS_ARB_RW4_WA_MSB_WA_MSB_Pos         0UL
#define USBFS_ARB_RW4_WA_MSB_WA_MSB_Msk         0x1UL
/* USBFS.ARB_RW4_RA */
#define USBFS_ARB_RW4_RA_RA_Pos                 0UL
#define USBFS_ARB_RW4_RA_RA_Msk                 0xFFUL
/* USBFS.ARB_RW4_RA_MSB */
#define USBFS_ARB_RW4_RA_MSB_RA_MSB_Pos         0UL
#define USBFS_ARB_RW4_RA_MSB_RA_MSB_Msk         0x1UL
/* USBFS.ARB_RW4_DR */
#define USBFS_ARB_RW4_DR_DR_Pos                 0UL
#define USBFS_ARB_RW4_DR_DR_Msk                 0xFFUL
/* USBFS.DMA_THRES */
#define USBFS_DMA_THRES_DMA_THS_Pos             0UL
#define USBFS_DMA_THRES_DMA_THS_Msk             0xFFUL
/* USBFS.DMA_THRES_MSB */
#define USBFS_DMA_THRES_MSB_DMA_THS_MSB_Pos     0UL
#define USBFS_DMA_THRES_MSB_DMA_THS_MSB_Msk     0x1UL
/* USBFS.ARB_EP5_CFG */
#define USBFS_ARB_EP5_CFG_IN_DATA_RDY_Pos       0UL
#define USBFS_ARB_EP5_CFG_IN_DATA_RDY_Msk       0x1UL
#define USBFS_ARB_EP5_CFG_DMA_REQ_Pos           1UL
#define USBFS_ARB_EP5_CFG_DMA_REQ_Msk           0x2UL
#define USBFS_ARB_EP5_CFG_CRC_BYPASS_Pos        2UL
#define USBFS_ARB_EP5_CFG_CRC_BYPASS_Msk        0x4UL
#define USBFS_ARB_EP5_CFG_RESET_PTR_Pos         3UL
#define USBFS_ARB_EP5_CFG_RESET_PTR_Msk         0x8UL
/* USBFS.ARB_EP5_INT_EN */
#define USBFS_ARB_EP5_INT_EN_IN_BUF_FULL_EN_Pos 0UL
#define USBFS_ARB_EP5_INT_EN_IN_BUF_FULL_EN_Msk 0x1UL
#define USBFS_ARB_EP5_INT_EN_DMA_GNT_EN_Pos     1UL
#define USBFS_ARB_EP5_INT_EN_DMA_GNT_EN_Msk     0x2UL
#define USBFS_ARB_EP5_INT_EN_BUF_OVER_EN_Pos    2UL
#define USBFS_ARB_EP5_INT_EN_BUF_OVER_EN_Msk    0x4UL
#define USBFS_ARB_EP5_INT_EN_BUF_UNDER_EN_Pos   3UL
#define USBFS_ARB_EP5_INT_EN_BUF_UNDER_EN_Msk   0x8UL
#define USBFS_ARB_EP5_INT_EN_ERR_INT_EN_Pos     4UL
#define USBFS_ARB_EP5_INT_EN_ERR_INT_EN_Msk     0x10UL
#define USBFS_ARB_EP5_INT_EN_DMA_TERMIN_EN_Pos  5UL
#define USBFS_ARB_EP5_INT_EN_DMA_TERMIN_EN_Msk  0x20UL
/* USBFS.ARB_EP5_SR */
#define USBFS_ARB_EP5_SR_IN_BUF_FULL_Pos        0UL
#define USBFS_ARB_EP5_SR_IN_BUF_FULL_Msk        0x1UL
#define USBFS_ARB_EP5_SR_DMA_GNT_Pos            1UL
#define USBFS_ARB_EP5_SR_DMA_GNT_Msk            0x2UL
#define USBFS_ARB_EP5_SR_BUF_OVER_Pos           2UL
#define USBFS_ARB_EP5_SR_BUF_OVER_Msk           0x4UL
#define USBFS_ARB_EP5_SR_BUF_UNDER_Pos          3UL
#define USBFS_ARB_EP5_SR_BUF_UNDER_Msk          0x8UL
#define USBFS_ARB_EP5_SR_DMA_TERMIN_Pos         5UL
#define USBFS_ARB_EP5_SR_DMA_TERMIN_Msk         0x20UL
/* USBFS.ARB_RW5_WA */
#define USBFS_ARB_RW5_WA_WA_Pos                 0UL
#define USBFS_ARB_RW5_WA_WA_Msk                 0xFFUL
/* USBFS.ARB_RW5_WA_MSB */
#define USBFS_ARB_RW5_WA_MSB_WA_MSB_Pos         0UL
#define USBFS_ARB_RW5_WA_MSB_WA_MSB_Msk         0x1UL
/* USBFS.ARB_RW5_RA */
#define USBFS_ARB_RW5_RA_RA_Pos                 0UL
#define USBFS_ARB_RW5_RA_RA_Msk                 0xFFUL
/* USBFS.ARB_RW5_RA_MSB */
#define USBFS_ARB_RW5_RA_MSB_RA_MSB_Pos         0UL
#define USBFS_ARB_RW5_RA_MSB_RA_MSB_Msk         0x1UL
/* USBFS.ARB_RW5_DR */
#define USBFS_ARB_RW5_DR_DR_Pos                 0UL
#define USBFS_ARB_RW5_DR_DR_Msk                 0xFFUL
/* USBFS.BUS_RST_CNT */
#define USBFS_BUS_RST_CNT_BUS_RST_CNT_Pos       0UL
#define USBFS_BUS_RST_CNT_BUS_RST_CNT_Msk       0xFUL
/* USBFS.ARB_EP6_CFG */
#define USBFS_ARB_EP6_CFG_IN_DATA_RDY_Pos       0UL
#define USBFS_ARB_EP6_CFG_IN_DATA_RDY_Msk       0x1UL
#define USBFS_ARB_EP6_CFG_DMA_REQ_Pos           1UL
#define USBFS_ARB_EP6_CFG_DMA_REQ_Msk           0x2UL
#define USBFS_ARB_EP6_CFG_CRC_BYPASS_Pos        2UL
#define USBFS_ARB_EP6_CFG_CRC_BYPASS_Msk        0x4UL
#define USBFS_ARB_EP6_CFG_RESET_PTR_Pos         3UL
#define USBFS_ARB_EP6_CFG_RESET_PTR_Msk         0x8UL
/* USBFS.ARB_EP6_INT_EN */
#define USBFS_ARB_EP6_INT_EN_IN_BUF_FULL_EN_Pos 0UL
#define USBFS_ARB_EP6_INT_EN_IN_BUF_FULL_EN_Msk 0x1UL
#define USBFS_ARB_EP6_INT_EN_DMA_GNT_EN_Pos     1UL
#define USBFS_ARB_EP6_INT_EN_DMA_GNT_EN_Msk     0x2UL
#define USBFS_ARB_EP6_INT_EN_BUF_OVER_EN_Pos    2UL
#define USBFS_ARB_EP6_INT_EN_BUF_OVER_EN_Msk    0x4UL
#define USBFS_ARB_EP6_INT_EN_BUF_UNDER_EN_Pos   3UL
#define USBFS_ARB_EP6_INT_EN_BUF_UNDER_EN_Msk   0x8UL
#define USBFS_ARB_EP6_INT_EN_ERR_INT_EN_Pos     4UL
#define USBFS_ARB_EP6_INT_EN_ERR_INT_EN_Msk     0x10UL
#define USBFS_ARB_EP6_INT_EN_DMA_TERMIN_EN_Pos  5UL
#define USBFS_ARB_EP6_INT_EN_DMA_TERMIN_EN_Msk  0x20UL
/* USBFS.ARB_EP6_SR */
#define USBFS_ARB_EP6_SR_IN_BUF_FULL_Pos        0UL
#define USBFS_ARB_EP6_SR_IN_BUF_FULL_Msk        0x1UL
#define USBFS_ARB_EP6_SR_DMA_GNT_Pos            1UL
#define USBFS_ARB_EP6_SR_DMA_GNT_Msk            0x2UL
#define USBFS_ARB_EP6_SR_BUF_OVER_Pos           2UL
#define USBFS_ARB_EP6_SR_BUF_OVER_Msk           0x4UL
#define USBFS_ARB_EP6_SR_BUF_UNDER_Pos          3UL
#define USBFS_ARB_EP6_SR_BUF_UNDER_Msk          0x8UL
#define USBFS_ARB_EP6_SR_DMA_TERMIN_Pos         5UL
#define USBFS_ARB_EP6_SR_DMA_TERMIN_Msk         0x20UL
/* USBFS.ARB_RW6_WA */
#define USBFS_ARB_RW6_WA_WA_Pos                 0UL
#define USBFS_ARB_RW6_WA_WA_Msk                 0xFFUL
/* USBFS.ARB_RW6_WA_MSB */
#define USBFS_ARB_RW6_WA_MSB_WA_MSB_Pos         0UL
#define USBFS_ARB_RW6_WA_MSB_WA_MSB_Msk         0x1UL
/* USBFS.ARB_RW6_RA */
#define USBFS_ARB_RW6_RA_RA_Pos                 0UL
#define USBFS_ARB_RW6_RA_RA_Msk                 0xFFUL
/* USBFS.ARB_RW6_RA_MSB */
#define USBFS_ARB_RW6_RA_MSB_RA_MSB_Pos         0UL
#define USBFS_ARB_RW6_RA_MSB_RA_MSB_Msk         0x1UL
/* USBFS.ARB_RW6_DR */
#define USBFS_ARB_RW6_DR_DR_Pos                 0UL
#define USBFS_ARB_RW6_DR_DR_Msk                 0xFFUL
/* USBFS.ARB_EP7_CFG */
#define USBFS_ARB_EP7_CFG_IN_DATA_RDY_Pos       0UL
#define USBFS_ARB_EP7_CFG_IN_DATA_RDY_Msk       0x1UL
#define USBFS_ARB_EP7_CFG_DMA_REQ_Pos           1UL
#define USBFS_ARB_EP7_CFG_DMA_REQ_Msk           0x2UL
#define USBFS_ARB_EP7_CFG_CRC_BYPASS_Pos        2UL
#define USBFS_ARB_EP7_CFG_CRC_BYPASS_Msk        0x4UL
#define USBFS_ARB_EP7_CFG_RESET_PTR_Pos         3UL
#define USBFS_ARB_EP7_CFG_RESET_PTR_Msk         0x8UL
/* USBFS.ARB_EP7_INT_EN */
#define USBFS_ARB_EP7_INT_EN_IN_BUF_FULL_EN_Pos 0UL
#define USBFS_ARB_EP7_INT_EN_IN_BUF_FULL_EN_Msk 0x1UL
#define USBFS_ARB_EP7_INT_EN_DMA_GNT_EN_Pos     1UL
#define USBFS_ARB_EP7_INT_EN_DMA_GNT_EN_Msk     0x2UL
#define USBFS_ARB_EP7_INT_EN_BUF_OVER_EN_Pos    2UL
#define USBFS_ARB_EP7_INT_EN_BUF_OVER_EN_Msk    0x4UL
#define USBFS_ARB_EP7_INT_EN_BUF_UNDER_EN_Pos   3UL
#define USBFS_ARB_EP7_INT_EN_BUF_UNDER_EN_Msk   0x8UL
#define USBFS_ARB_EP7_INT_EN_ERR_INT_EN_Pos     4UL
#define USBFS_ARB_EP7_INT_EN_ERR_INT_EN_Msk     0x10UL
#define USBFS_ARB_EP7_INT_EN_DMA_TERMIN_EN_Pos  5UL
#define USBFS_ARB_EP7_INT_EN_DMA_TERMIN_EN_Msk  0x20UL
/* USBFS.ARB_EP7_SR */
#define USBFS_ARB_EP7_SR_IN_BUF_FULL_Pos        0UL
#define USBFS_ARB_EP7_SR_IN_BUF_FULL_Msk        0x1UL
#define USBFS_ARB_EP7_SR_DMA_GNT_Pos            1UL
#define USBFS_ARB_EP7_SR_DMA_GNT_Msk            0x2UL
#define USBFS_ARB_EP7_SR_BUF_OVER_Pos           2UL
#define USBFS_ARB_EP7_SR_BUF_OVER_Msk           0x4UL
#define USBFS_ARB_EP7_SR_BUF_UNDER_Pos          3UL
#define USBFS_ARB_EP7_SR_BUF_UNDER_Msk          0x8UL
#define USBFS_ARB_EP7_SR_DMA_TERMIN_Pos         5UL
#define USBFS_ARB_EP7_SR_DMA_TERMIN_Msk         0x20UL
/* USBFS.ARB_RW7_WA */
#define USBFS_ARB_RW7_WA_WA_Pos                 0UL
#define USBFS_ARB_RW7_WA_WA_Msk                 0xFFUL
/* USBFS.ARB_RW7_WA_MSB */
#define USBFS_ARB_RW7_WA_MSB_WA_MSB_Pos         0UL
#define USBFS_ARB_RW7_WA_MSB_WA_MSB_Msk         0x1UL
/* USBFS.ARB_RW7_RA */
#define USBFS_ARB_RW7_RA_RA_Pos                 0UL
#define USBFS_ARB_RW7_RA_RA_Msk                 0xFFUL
/* USBFS.ARB_RW7_RA_MSB */
#define USBFS_ARB_RW7_RA_MSB_RA_MSB_Pos         0UL
#define USBFS_ARB_RW7_RA_MSB_RA_MSB_Msk         0x1UL
/* USBFS.ARB_RW7_DR */
#define USBFS_ARB_RW7_DR_DR_Pos                 0UL
#define USBFS_ARB_RW7_DR_DR_Msk                 0xFFUL
/* USBFS.ARB_EP8_CFG */
#define USBFS_ARB_EP8_CFG_IN_DATA_RDY_Pos       0UL
#define USBFS_ARB_EP8_CFG_IN_DATA_RDY_Msk       0x1UL
#define USBFS_ARB_EP8_CFG_DMA_REQ_Pos           1UL
#define USBFS_ARB_EP8_CFG_DMA_REQ_Msk           0x2UL
#define USBFS_ARB_EP8_CFG_CRC_BYPASS_Pos        2UL
#define USBFS_ARB_EP8_CFG_CRC_BYPASS_Msk        0x4UL
#define USBFS_ARB_EP8_CFG_RESET_PTR_Pos         3UL
#define USBFS_ARB_EP8_CFG_RESET_PTR_Msk         0x8UL
/* USBFS.ARB_EP8_INT_EN */
#define USBFS_ARB_EP8_INT_EN_IN_BUF_FULL_EN_Pos 0UL
#define USBFS_ARB_EP8_INT_EN_IN_BUF_FULL_EN_Msk 0x1UL
#define USBFS_ARB_EP8_INT_EN_DMA_GNT_EN_Pos     1UL
#define USBFS_ARB_EP8_INT_EN_DMA_GNT_EN_Msk     0x2UL
#define USBFS_ARB_EP8_INT_EN_BUF_OVER_EN_Pos    2UL
#define USBFS_ARB_EP8_INT_EN_BUF_OVER_EN_Msk    0x4UL
#define USBFS_ARB_EP8_INT_EN_BUF_UNDER_EN_Pos   3UL
#define USBFS_ARB_EP8_INT_EN_BUF_UNDER_EN_Msk   0x8UL
#define USBFS_ARB_EP8_INT_EN_ERR_INT_EN_Pos     4UL
#define USBFS_ARB_EP8_INT_EN_ERR_INT_EN_Msk     0x10UL
#define USBFS_ARB_EP8_INT_EN_DMA_TERMIN_EN_Pos  5UL
#define USBFS_ARB_EP8_INT_EN_DMA_TERMIN_EN_Msk  0x20UL
/* USBFS.ARB_EP8_SR */
#define USBFS_ARB_EP8_SR_IN_BUF_FULL_Pos        0UL
#define USBFS_ARB_EP8_SR_IN_BUF_FULL_Msk        0x1UL
#define USBFS_ARB_EP8_SR_DMA_GNT_Pos            1UL
#define USBFS_ARB_EP8_SR_DMA_GNT_Msk            0x2UL
#define USBFS_ARB_EP8_SR_BUF_OVER_Pos           2UL
#define USBFS_ARB_EP8_SR_BUF_OVER_Msk           0x4UL
#define USBFS_ARB_EP8_SR_BUF_UNDER_Pos          3UL
#define USBFS_ARB_EP8_SR_BUF_UNDER_Msk          0x8UL
#define USBFS_ARB_EP8_SR_DMA_TERMIN_Pos         5UL
#define USBFS_ARB_EP8_SR_DMA_TERMIN_Msk         0x20UL
/* USBFS.ARB_RW8_WA */
#define USBFS_ARB_RW8_WA_WA_Pos                 0UL
#define USBFS_ARB_RW8_WA_WA_Msk                 0xFFUL
/* USBFS.ARB_RW8_WA_MSB */
#define USBFS_ARB_RW8_WA_MSB_WA_MSB_Pos         0UL
#define USBFS_ARB_RW8_WA_MSB_WA_MSB_Msk         0x1UL
/* USBFS.ARB_RW8_RA */
#define USBFS_ARB_RW8_RA_RA_Pos                 0UL
#define USBFS_ARB_RW8_RA_RA_Msk                 0xFFUL
/* USBFS.ARB_RW8_RA_MSB */
#define USBFS_ARB_RW8_RA_MSB_RA_MSB_Pos         0UL
#define USBFS_ARB_RW8_RA_MSB_RA_MSB_Msk         0x1UL
/* USBFS.ARB_RW8_DR */
#define USBFS_ARB_RW8_DR_DR_Pos                 0UL
#define USBFS_ARB_RW8_DR_DR_Msk                 0xFFUL
/* USBFS.MEM_DATA */
#define USBFS_MEM_DATA_DR_Pos                   0UL
#define USBFS_MEM_DATA_DR_Msk                   0xFFUL
/* USBFS.SOF16 */
#define USBFS_SOF16_FRAME_NUMBER16_Pos          0UL
#define USBFS_SOF16_FRAME_NUMBER16_Msk          0x7FFUL
/* USBFS.OSCLK_DR16 */
#define USBFS_OSCLK_DR16_ADDER16_Pos            0UL
#define USBFS_OSCLK_DR16_ADDER16_Msk            0x7FFFUL
/* USBFS.ARB_RW1_WA16 */
#define USBFS_ARB_RW1_WA16_WA16_Pos             0UL
#define USBFS_ARB_RW1_WA16_WA16_Msk             0x1FFUL
/* USBFS.ARB_RW1_RA16 */
#define USBFS_ARB_RW1_RA16_RA16_Pos             0UL
#define USBFS_ARB_RW1_RA16_RA16_Msk             0x1FFUL
/* USBFS.ARB_RW1_DR16 */
#define USBFS_ARB_RW1_DR16_DR16_Pos             0UL
#define USBFS_ARB_RW1_DR16_DR16_Msk             0xFFFFUL
/* USBFS.ARB_RW2_WA16 */
#define USBFS_ARB_RW2_WA16_WA16_Pos             0UL
#define USBFS_ARB_RW2_WA16_WA16_Msk             0x1FFUL
/* USBFS.ARB_RW2_RA16 */
#define USBFS_ARB_RW2_RA16_RA16_Pos             0UL
#define USBFS_ARB_RW2_RA16_RA16_Msk             0x1FFUL
/* USBFS.ARB_RW2_DR16 */
#define USBFS_ARB_RW2_DR16_DR16_Pos             0UL
#define USBFS_ARB_RW2_DR16_DR16_Msk             0xFFFFUL
/* USBFS.ARB_RW3_WA16 */
#define USBFS_ARB_RW3_WA16_WA16_Pos             0UL
#define USBFS_ARB_RW3_WA16_WA16_Msk             0x1FFUL
/* USBFS.ARB_RW3_RA16 */
#define USBFS_ARB_RW3_RA16_RA16_Pos             0UL
#define USBFS_ARB_RW3_RA16_RA16_Msk             0x1FFUL
/* USBFS.ARB_RW3_DR16 */
#define USBFS_ARB_RW3_DR16_DR16_Pos             0UL
#define USBFS_ARB_RW3_DR16_DR16_Msk             0xFFFFUL
/* USBFS.CWA16 */
#define USBFS_CWA16_CWA16_Pos                   0UL
#define USBFS_CWA16_CWA16_Msk                   0x1FFUL
/* USBFS.ARB_RW4_WA16 */
#define USBFS_ARB_RW4_WA16_WA16_Pos             0UL
#define USBFS_ARB_RW4_WA16_WA16_Msk             0x1FFUL
/* USBFS.ARB_RW4_RA16 */
#define USBFS_ARB_RW4_RA16_RA16_Pos             0UL
#define USBFS_ARB_RW4_RA16_RA16_Msk             0x1FFUL
/* USBFS.ARB_RW4_DR16 */
#define USBFS_ARB_RW4_DR16_DR16_Pos             0UL
#define USBFS_ARB_RW4_DR16_DR16_Msk             0xFFFFUL
/* USBFS.DMA_THRES16 */
#define USBFS_DMA_THRES16_DMA_THS16_Pos         0UL
#define USBFS_DMA_THRES16_DMA_THS16_Msk         0x1FFUL
/* USBFS.ARB_RW5_WA16 */
#define USBFS_ARB_RW5_WA16_WA16_Pos             0UL
#define USBFS_ARB_RW5_WA16_WA16_Msk             0x1FFUL
/* USBFS.ARB_RW5_RA16 */
#define USBFS_ARB_RW5_RA16_RA16_Pos             0UL
#define USBFS_ARB_RW5_RA16_RA16_Msk             0x1FFUL
/* USBFS.ARB_RW5_DR16 */
#define USBFS_ARB_RW5_DR16_DR16_Pos             0UL
#define USBFS_ARB_RW5_DR16_DR16_Msk             0xFFFFUL
/* USBFS.ARB_RW6_WA16 */
#define USBFS_ARB_RW6_WA16_WA16_Pos             0UL
#define USBFS_ARB_RW6_WA16_WA16_Msk             0x1FFUL
/* USBFS.ARB_RW6_RA16 */
#define USBFS_ARB_RW6_RA16_RA16_Pos             0UL
#define USBFS_ARB_RW6_RA16_RA16_Msk             0x1FFUL
/* USBFS.ARB_RW6_DR16 */
#define USBFS_ARB_RW6_DR16_DR16_Pos             0UL
#define USBFS_ARB_RW6_DR16_DR16_Msk             0xFFFFUL
/* USBFS.ARB_RW7_WA16 */
#define USBFS_ARB_RW7_WA16_WA16_Pos             0UL
#define USBFS_ARB_RW7_WA16_WA16_Msk             0x1FFUL
/* USBFS.ARB_RW7_RA16 */
#define USBFS_ARB_RW7_RA16_RA16_Pos             0UL
#define USBFS_ARB_RW7_RA16_RA16_Msk             0x1FFUL
/* USBFS.ARB_RW7_DR16 */
#define USBFS_ARB_RW7_DR16_DR16_Pos             0UL
#define USBFS_ARB_RW7_DR16_DR16_Msk             0xFFFFUL
/* USBFS.ARB_RW8_WA16 */
#define USBFS_ARB_RW8_WA16_WA16_Pos             0UL
#define USBFS_ARB_RW8_WA16_WA16_Msk             0x1FFUL
/* USBFS.ARB_RW8_RA16 */
#define USBFS_ARB_RW8_RA16_RA16_Pos             0UL
#define USBFS_ARB_RW8_RA16_RA16_Msk             0x1FFUL
/* USBFS.ARB_RW8_DR16 */
#define USBFS_ARB_RW8_DR16_DR16_Pos             0UL
#define USBFS_ARB_RW8_DR16_DR16_Msk             0xFFFFUL


#endif /* _CYIP_USBFS_V2_H_ */


/* [] END OF FILE */
