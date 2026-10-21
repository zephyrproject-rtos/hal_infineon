/***************************************************************************//**
* \file cyt4dnjbbs.h
*
* \brief
* CYT4DNJBBS device header
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

#ifndef _CYT4DNJBBS_H_
#define _CYT4DNJBBS_H_

/**
* \addtogroup group_device CYT4DNJBBS
* \{
*/

/**
* \addtogroup Configuration_of_CMSIS
* \{
*/

/*******************************************************************************
*                         Interrupt Number Definition
*******************************************************************************/

typedef enum {
#if ((defined(__GNUC__)        && (__ARM_ARCH == 6) && (__ARM_ARCH_6M__ == 1)) || \
     (defined(__ICCARM__)      && (__CORE__ == __ARM6M__)) || \
     (defined(__ARMCC_VERSION) && defined(__TARGET_ARCH_THUMB) && (__TARGET_ARCH_THUMB == 3)) || \
     (defined(__ghs__)         && defined(__CORE_CORTEXM0PLUS__)))
  /* ARM Cortex-M0+ Core Interrupt Numbers */
  Reset_IRQn                        = -15,      /*!< -15 Reset Vector, invoked on Power up and warm reset */
  NonMaskableInt_IRQn               = -14,      /*!< -14 Non maskable Interrupt, cannot be stopped or preempted */
  HardFault_IRQn                    = -13,      /*!< -13 Hard Fault, all classes of Fault */
  SVCall_IRQn                       =  -5,      /*!<  -5 System Service Call via SVC instruction */
  PendSV_IRQn                       =  -2,      /*!<  -2 Pendable request for system service */
  SysTick_IRQn                      =  -1,      /*!<  -1 System Tick Timer */
#else
  /* ARM Cortex-M7 Core Interrupt Numbers */
  Reset_IRQn                        = -15,      /*!< -15 Reset Vector, invoked on Power up and warm reset */
  NonMaskableInt_IRQn               = -14,      /*!< -14 Non maskable Interrupt, cannot be stopped or preempted */
  HardFault_IRQn                    = -13,      /*!< -13 Hard Fault, all classes of Fault */
  MemoryManagement_IRQn             = -12,      /*!< -12 Memory Management, MPU mismatch, including Access Violation and No Match */
  BusFault_IRQn                     = -11,      /*!< -11 Bus Fault, Pre-Fetch-, Memory Access Fault, other address/memory related Fault */
  UsageFault_IRQn                   = -10,      /*!< -10 Usage Fault, i.e. Undef Instruction, Illegal State Transition */
  SVCall_IRQn                       =  -5,      /*!<  -5 System Service Call via SVC instruction */
  DebugMonitor_IRQn                 =  -4,      /*!<  -4 Debug Monitor */
  PendSV_IRQn                       =  -2,      /*!<  -2 Pendable request for system service */
  SysTick_IRQn                      =  -1,      /*!<  -1 System Tick Timer */
#endif
  /* CYT4DNJBBS User Interrupt Numbers */
  NvicMux0_IRQn                     =   0,      /*!<   0 [DeepSleep] CPU User Interrupt #0 */
  NvicMux1_IRQn                     =   1,      /*!<   1 [DeepSleep] CPU User Interrupt #1 */
  NvicMux2_IRQn                     =   2,      /*!<   2 [DeepSleep] CPU User Interrupt #2 */
  NvicMux3_IRQn                     =   3,      /*!<   3 [DeepSleep] CPU User Interrupt #3 */
  NvicMux4_IRQn                     =   4,      /*!<   4 [DeepSleep] CPU User Interrupt #4 */
  NvicMux5_IRQn                     =   5,      /*!<   5 [DeepSleep] CPU User Interrupt #5 */
  NvicMux6_IRQn                     =   6,      /*!<   6 [DeepSleep] CPU User Interrupt #6 */
  NvicMux7_IRQn                     =   7,      /*!<   7 [DeepSleep] CPU User Interrupt #7 */
  /* CYT4DNJBBS Internal SW Interrupt Numbers */
  Internal0_IRQn                    =   8,      /*!<   8 [Active] Internal SW Interrupt #0 */
  Internal1_IRQn                    =   9,      /*!<   9 [Active] Internal SW Interrupt #1 */
  Internal2_IRQn                    =  10,      /*!<  10 [Active] Internal SW Interrupt #2 */
  Internal3_IRQn                    =  11,      /*!<  11 [Active] Internal SW Interrupt #3 */
  Internal4_IRQn                    =  12,      /*!<  12 [Active] Internal SW Interrupt #4 */
  Internal5_IRQn                    =  13,      /*!<  13 [Active] Internal SW Interrupt #5 */
  Internal6_IRQn                    =  14,      /*!<  14 [Active] Internal SW Interrupt #6 */
  Internal7_IRQn                    =  15,      /*!<  15 [Active] Internal SW Interrupt #7 */
  unconnected_IRQn                  =1023       /*!< 1023 Unconnected */
} IRQn_Type;


/* CYT4DNJBBS peripheral interrupts */
typedef enum {
  cpuss_interrupts_ipc_0_IRQn       =   0,      /*!<   0 [DeepSleep] CPUSS Inter Process Communication Interrupt #0 */
  cpuss_interrupts_ipc_1_IRQn       =   1,      /*!<   1 [DeepSleep] CPUSS Inter Process Communication Interrupt #1 */
  cpuss_interrupts_ipc_2_IRQn       =   2,      /*!<   2 [DeepSleep] CPUSS Inter Process Communication Interrupt #2 */
  cpuss_interrupts_ipc_3_IRQn       =   3,      /*!<   3 [DeepSleep] CPUSS Inter Process Communication Interrupt #3 */
  cpuss_interrupts_ipc_4_IRQn       =   4,      /*!<   4 [DeepSleep] CPUSS Inter Process Communication Interrupt #4 */
  cpuss_interrupts_ipc_5_IRQn       =   5,      /*!<   5 [DeepSleep] CPUSS Inter Process Communication Interrupt #5 */
  cpuss_interrupts_ipc_6_IRQn       =   6,      /*!<   6 [DeepSleep] CPUSS Inter Process Communication Interrupt #6 */
  cpuss_interrupts_ipc_7_IRQn       =   7,      /*!<   7 [DeepSleep] CPUSS Inter Process Communication Interrupt #7 */
  cpuss_interrupts_fault_0_IRQn     =   8,      /*!<   8 [DeepSleep] CPUSS Fault Structure Interrupt #0 */
  cpuss_interrupts_fault_1_IRQn     =   9,      /*!<   9 [DeepSleep] CPUSS Fault Structure Interrupt #1 */
  cpuss_interrupts_fault_2_IRQn     =  10,      /*!<  10 [DeepSleep] CPUSS Fault Structure Interrupt #2 */
  cpuss_interrupts_fault_3_IRQn     =  11,      /*!<  11 [DeepSleep] CPUSS Fault Structure Interrupt #3 */
  srss_interrupt_backup_IRQn        =  12,      /*!<  12 [DeepSleep] Interrupt for BACKUP domain */
  srss_interrupt_mcwdt_0_IRQn       =  13,      /*!<  13 [DeepSleep] Multi Counter Watchdog Timer interrupt */
  srss_interrupt_mcwdt_1_IRQn       =  14,      /*!<  14 [DeepSleep] Multi Counter Watchdog Timer interrupt */
  srss_interrupt_mcwdt_2_IRQn       =  15,      /*!<  15 [DeepSleep] Multi Counter Watchdog Timer interrupt */
  srss_interrupt_wdt_IRQn           =  17,      /*!<  17 [DeepSleep] Hardware Watchdog Timer interrupt */
  srss_interrupt_IRQn               =  18,      /*!<  18 [DeepSleep] Other combined Interrupts for SRSS (LVD, CLKCAL) */
  evtgen_0_interrupt_dpslp_IRQn     =  19,      /*!<  19 [DeepSleep] Event gen Deep-sleep domain interrupt */
  scb_0_interrupt_IRQn              =  20,      /*!<  20 [DeepSleep] Serial Communication Block #0 (DeepSleep capable) */
  ioss_interrupt_vdd_IRQn           =  22,      /*!<  22 [DeepSleep] GPIO Supply Detect Interrupt */
  ioss_interrupt_gpio_dpslp_IRQn    =  23,      /*!<  23 [DeepSleep] Consolidated Interrupt for deepsleep IO ports */
  ioss_interrupts_gpio_dpslp_0_IRQn =  24,      /*!<  24 [DeepSleep] GPIO Port Interrupt #0 */
  ioss_interrupts_gpio_dpslp_1_IRQn =  25,      /*!<  25 [DeepSleep] GPIO Port Interrupt #1 */
  ioss_interrupts_gpio_dpslp_2_IRQn =  26,      /*!<  26 [DeepSleep] GPIO Port Interrupt #2 */
  ioss_interrupts_gpio_dpslp_3_IRQn =  27,      /*!<  27 [DeepSleep] GPIO Port Interrupt #3 */
  ioss_interrupts_gpio_dpslp_4_IRQn =  28,      /*!<  28 [DeepSleep] GPIO Port Interrupt #4 */
  ioss_interrupts_gpio_dpslp_5_IRQn =  29,      /*!<  29 [DeepSleep] GPIO Port Interrupt #5 */
  ioss_interrupts_gpio_dpslp_6_IRQn =  30,      /*!<  30 [DeepSleep] GPIO Port Interrupt #6 */
  ioss_interrupts_gpio_dpslp_7_IRQn =  31,      /*!<  31 [DeepSleep] GPIO Port Interrupt #7 */
  ioss_interrupts_gpio_dpslp_8_IRQn =  32,      /*!<  32 [DeepSleep] GPIO Port Interrupt #8 */
  ioss_interrupts_gpio_dpslp_9_IRQn =  33,      /*!<  33 [DeepSleep] GPIO Port Interrupt #9 */
  ioss_interrupts_gpio_dpslp_10_IRQn =  34,     /*!<  34 [DeepSleep] GPIO Port Interrupt #10 */
  ioss_interrupts_gpio_dpslp_11_IRQn =  35,     /*!<  35 [DeepSleep] GPIO Port Interrupt #11 */
  ioss_interrupts_gpio_dpslp_12_IRQn =  36,     /*!<  36 [DeepSleep] GPIO Port Interrupt #12 */
  ioss_interrupts_gpio_dpslp_29_IRQn =  37,     /*!<  37 [DeepSleep] GPIO Port Interrupt #29 */
  ioss_interrupt_gpio_act_IRQn      =  50,      /*!<  50 [Active] Consolidated Interrupt for active IO ports */
  ioss_interrupts_gpio_act_13_IRQn  =  53,      /*!<  53 [Active] GPIO Port Interrupt #13 */
  ioss_interrupts_gpio_act_14_IRQn  =  54,      /*!<  54 [Active] GPIO Port Interrupt #14 */
  ioss_interrupts_gpio_act_15_IRQn  =  55,      /*!<  55 [Active] GPIO Port Interrupt #15 */
  ioss_interrupts_gpio_act_16_IRQn  =  56,      /*!<  56 [Active] GPIO Port Interrupt #16 */
  ioss_interrupts_gpio_act_17_IRQn  =  57,      /*!<  57 [Active] GPIO Port Interrupt #17 */
  ioss_interrupts_gpio_act_18_IRQn  =  58,      /*!<  58 [Active] GPIO Port Interrupt #18 */
  ioss_interrupts_gpio_act_19_IRQn  =  59,      /*!<  59 [Active] GPIO Port Interrupt #19 */
  ioss_interrupts_gpio_act_20_IRQn  =  60,      /*!<  60 [Active] GPIO Port Interrupt #20 */
  ioss_interrupts_gpio_act_21_IRQn  =  61,      /*!<  61 [Active] GPIO Port Interrupt #21 */
  ioss_interrupts_gpio_act_22_IRQn  =  62,      /*!<  62 [Active] GPIO Port Interrupt #22 */
  ioss_interrupts_gpio_act_23_IRQn  =  63,      /*!<  63 [Active] GPIO Port Interrupt #23 */
  ioss_interrupts_gpio_act_24_IRQn  =  64,      /*!<  64 [Active] GPIO Port Interrupt #24 */
  ioss_interrupts_gpio_act_25_IRQn  =  65,      /*!<  65 [Active] GPIO Port Interrupt #25 */
  ioss_interrupts_gpio_act_26_IRQn  =  66,      /*!<  66 [Active] GPIO Port Interrupt #26 */
  ioss_interrupts_gpio_act_27_IRQn  =  67,      /*!<  67 [Active] GPIO Port Interrupt #27 */
  ioss_interrupts_gpio_act_28_IRQn  =  68,      /*!<  68 [Active] GPIO Port Interrupt #28 */
  ioss_interrupts_gpio_act_30_IRQn  =  69,      /*!<  69 [Active] GPIO Port Interrupt #30 */
  cpuss_interrupt_crypto_IRQn       =  70,      /*!<  70 [Active] CRYPTO Accelerator Interrupt */
  cpuss_interrupt_fm_IRQn           =  71,      /*!<  71 [Active] FLASH Macro Interrupt */
  cpuss_interrupts_cm7_0_fp_IRQn    =  72,      /*!<  72 [Active] CM7 #0 Floating Point operation fault */
  cpuss_interrupts_cm7_1_fp_IRQn    =  73,      /*!<  73 [Active] CM7 #1 Floating Point operation fault */
  cpuss_interrupts_cm0_cti_0_IRQn   =  74,      /*!<  74 [Active] CM0+ CTI #0 */
  cpuss_interrupts_cm0_cti_1_IRQn   =  75,      /*!<  75 [Active] CM0+ CTI #1 */
  cpuss_interrupts_cm7_0_cti_0_IRQn =  76,      /*!<  76 [Active] CM7 #0 CTI #0 */
  cpuss_interrupts_cm7_0_cti_1_IRQn =  77,      /*!<  77 [Active] CM7 #0 CTI #1 */
  cpuss_interrupts_cm7_1_cti_0_IRQn =  78,      /*!<  78 [Active] CM7 #1 CTI #0 */
  cpuss_interrupts_cm7_1_cti_1_IRQn =  79,      /*!<  79 [Active] CM7 #1 CTI #1 */
  evtgen_0_interrupt_IRQn           =  80,      /*!<  80 [Active] Event gen Active domain interrupt */
  smif_0_smif0_interrupt_IRQn       =  81,      /*!<  81 [Active] SMIF #0 (QSPI) interrupt */
  smif_0_smif1_interrupt_IRQn       =  82,      /*!<  82 [Active] SMIF #1 (QSPI) interrupt */
  eth_0_interrupt_eth_0_IRQn        =  83,      /*!<  83 [Active] Ethernet #0 priority queue[0] */
  eth_0_interrupt_eth_1_IRQn        =  84,      /*!<  84 [Active] Ethernet #0 priority queue[1] */
  eth_0_interrupt_eth_2_IRQn        =  85,      /*!<  85 [Active] Ethernet #0 priority queue[2] */
  canfd_0_interrupt0_IRQn           =  86,      /*!<  86 [Active] Can #0, Consolidated interrupt #0 for all three channels */
  canfd_0_interrupt1_IRQn           =  87,      /*!<  87 [Active] Can #0, Consolidated interrupt #1 for all three channels */
  canfd_1_interrupt0_IRQn           =  88,      /*!<  88 [Active] Can #1, Consolidated interrupt #0 for all three channels */
  canfd_1_interrupt1_IRQn           =  89,      /*!<  89 [Active] Can #1, Consolidated interrupt #1 for all three channels */
  canfd_0_interrupts0_0_IRQn        =  90,      /*!<  90 [Active] CAN #0, Interrupt #0, Channel #0 */
  canfd_0_interrupts0_1_IRQn        =  91,      /*!<  91 [Active] CAN #0, Interrupt #0, Channel #1 */
  canfd_0_interrupts1_0_IRQn        =  96,      /*!<  96 [Active] CAN #0, Interrupt #1, Channel #0 */
  canfd_0_interrupts1_1_IRQn        =  97,      /*!<  97 [Active] CAN #0, Interrupt #1, Channel #1 */
  canfd_1_interrupts0_0_IRQn        = 102,      /*!< 102 [Active] CAN #1, Interrupt #0, Channel #0 */
  canfd_1_interrupts0_1_IRQn        = 103,      /*!< 103 [Active] CAN #1, Interrupt #0, Channel #1 */
  canfd_1_interrupts1_0_IRQn        = 108,      /*!< 108 [Active] CAN #1, Interrupt #1, Channel #0 */
  canfd_1_interrupts1_1_IRQn        = 109,      /*!< 109 [Active] CAN #1, Interrupt #1, Channel #1 */
  lin_0_interrupts_0_IRQn           = 114,      /*!< 114 [Active] LIN Interrupt, Channel #0 */
  lin_0_interrupts_1_IRQn           = 115,      /*!< 115 [Active] LIN Interrupt, Channel #1 */
  cxpi_0_interrupts_0_IRQn          = 130,      /*!< 130 [Active] CXPI Interrupt, Channel #0 */
  cxpi_0_interrupts_1_IRQn          = 131,      /*!< 131 [Active] CXPI Interrupt, Channel #1 */
  scb_1_interrupt_IRQn              = 135,      /*!< 135 [Active] Serial Communication Block #1 */
  scb_2_interrupt_IRQn              = 136,      /*!< 136 [Active] Serial Communication Block #2 */
  scb_3_interrupt_IRQn              = 137,      /*!< 137 [Active] Serial Communication Block #3 */
  scb_4_interrupt_IRQn              = 138,      /*!< 138 [Active] Serial Communication Block #4 */
  scb_5_interrupt_IRQn              = 139,      /*!< 139 [Active] Serial Communication Block #5 */
  scb_6_interrupt_IRQn              = 140,      /*!< 140 [Active] Serial Communication Block #6 */
  scb_7_interrupt_IRQn              = 141,      /*!< 141 [Active] Serial Communication Block #7 */
  scb_8_interrupt_IRQn              = 142,      /*!< 142 [Active] Serial Communication Block #8 */
  scb_9_interrupt_IRQn              = 143,      /*!< 143 [Active] Serial Communication Block #9 */
  scb_10_interrupt_IRQn             = 144,      /*!< 144 [Active] Serial Communication Block #10 */
  scb_11_interrupt_IRQn             = 145,      /*!< 145 [Active] Serial Communication Block #11 */
  videoss_0_interrupt_gfx2d_IRQn    = 150,      /*!< 150 [Active] GFX2D interrupt */
  videoss_0_interrupt_mipicsi_IRQn  = 151,      /*!< 151 [Active] MIPICSI interrupt */
  videoss_0_interrupt_videoio0_IRQn = 152,      /*!< 152 [Active] VIDEOIO interrupt 0 */
  videoss_0_interrupt_videoio1_IRQn = 153,      /*!< 153 [Active] VIDEOIO interrupt 1 */
  videoss_0_interrupt_videoio0_safety_IRQn = 154, /*!< 154 [Active] VIDEOIO safety interrupt 0 */
  videoss_0_interrupt_videoio1_safety_IRQn = 155, /*!< 155 [Active] VIDEOIO safety interrupt 1 */
  jpegdec_interrupt_jpeg_IRQn       = 156,      /*!< 156 [Active] JPEGDEC interrupt */
  pass_0_interrupts_sar_0_IRQn      = 160,      /*!< 160 [Active] PASS interrupts, ADC #0, Channel #0 */
  pass_0_interrupts_sar_1_IRQn      = 161,      /*!< 161 [Active] PASS interrupts, ADC #0, Channel #1 */
  pass_0_interrupts_sar_2_IRQn      = 162,      /*!< 162 [Active] PASS interrupts, ADC #0, Channel #2 */
  pass_0_interrupts_sar_3_IRQn      = 163,      /*!< 163 [Active] PASS interrupts, ADC #0, Channel #3 */
  pass_0_interrupts_sar_4_IRQn      = 164,      /*!< 164 [Active] PASS interrupts, ADC #0, Channel #4 */
  pass_0_interrupts_sar_5_IRQn      = 165,      /*!< 165 [Active] PASS interrupts, ADC #0, Channel #5 */
  pass_0_interrupts_sar_6_IRQn      = 166,      /*!< 166 [Active] PASS interrupts, ADC #0, Channel #6 */
  pass_0_interrupts_sar_7_IRQn      = 167,      /*!< 167 [Active] PASS interrupts, ADC #0, Channel #7 */
  pass_0_interrupts_sar_8_IRQn      = 168,      /*!< 168 [Active] PASS interrupts, ADC #0, Channel #8 */
  pass_0_interrupts_sar_9_IRQn      = 169,      /*!< 169 [Active] PASS interrupts, ADC #0, Channel #9 */
  pass_0_interrupts_sar_10_IRQn     = 170,      /*!< 170 [Active] PASS interrupts, ADC #0, Channel #10 */
  pass_0_interrupts_sar_11_IRQn     = 171,      /*!< 171 [Active] PASS interrupts, ADC #0, Channel #11 */
  pass_0_interrupts_sar_12_IRQn     = 172,      /*!< 172 [Active] PASS interrupts, ADC #0, Channel #12 */
  pass_0_interrupts_sar_13_IRQn     = 173,      /*!< 173 [Active] PASS interrupts, ADC #0, Channel #13 */
  pass_0_interrupts_sar_14_IRQn     = 174,      /*!< 174 [Active] PASS interrupts, ADC #0, Channel #14 */
  pass_0_interrupts_sar_15_IRQn     = 175,      /*!< 175 [Active] PASS interrupts, ADC #0, Channel #15 */
  pass_0_interrupts_sar_16_IRQn     = 176,      /*!< 176 [Active] PASS interrupts, ADC #0, Channel #16 */
  pass_0_interrupts_sar_17_IRQn     = 177,      /*!< 177 [Active] PASS interrupts, ADC #0, Channel #17 */
  pass_0_interrupts_sar_18_IRQn     = 178,      /*!< 178 [Active] PASS interrupts, ADC #0, Channel #18 */
  pass_0_interrupts_sar_19_IRQn     = 179,      /*!< 179 [Active] PASS interrupts, ADC #0, Channel #19 */
  pass_0_interrupts_sar_20_IRQn     = 180,      /*!< 180 [Active] PASS interrupts, ADC #0, Channel #20 */
  pass_0_interrupts_sar_21_IRQn     = 181,      /*!< 181 [Active] PASS interrupts, ADC #0, Channel #21 */
  pass_0_interrupts_sar_22_IRQn     = 182,      /*!< 182 [Active] PASS interrupts, ADC #0, Channel #22 */
  pass_0_interrupts_sar_23_IRQn     = 183,      /*!< 183 [Active] PASS interrupts, ADC #0, Channel #23 */
  pass_0_interrupts_sar_24_IRQn     = 184,      /*!< 184 [Active] PASS interrupts, ADC #0, Channel #24 */
  pass_0_interrupts_sar_25_IRQn     = 185,      /*!< 185 [Active] PASS interrupts, ADC #0, Channel #25 */
  pass_0_interrupts_sar_26_IRQn     = 186,      /*!< 186 [Active] PASS interrupts, ADC #0, Channel #26 */
  pass_0_interrupts_sar_27_IRQn     = 187,      /*!< 187 [Active] PASS interrupts, ADC #0, Channel #27 */
  pass_0_interrupts_sar_28_IRQn     = 188,      /*!< 188 [Active] PASS interrupts, ADC #0, Channel #28 */
  pass_0_interrupts_sar_29_IRQn     = 189,      /*!< 189 [Active] PASS interrupts, ADC #0, Channel #29 */
  pass_0_interrupts_sar_30_IRQn     = 190,      /*!< 190 [Active] PASS interrupts, ADC #0, Channel #30 */
  pass_0_interrupts_sar_31_IRQn     = 191,      /*!< 191 [Active] PASS interrupts, ADC #0, Channel #31 */
  axi_dmac_0_interrupts_0_IRQn      = 280,      /*!< 280 [Active] AXI DMAC, Channel #0 */
  axi_dmac_0_interrupts_1_IRQn      = 281,      /*!< 281 [Active] AXI DMAC, Channel #1 */
  axi_dmac_0_interrupts_2_IRQn      = 282,      /*!< 282 [Active] AXI DMAC, Channel #2 */
  axi_dmac_0_interrupts_3_IRQn      = 283,      /*!< 283 [Active] AXI DMAC, Channel #3 */
  cpuss_interrupts_dmac_0_IRQn      = 288,      /*!< 288 [Active] CPUSS DMAC, Channel #0 */
  cpuss_interrupts_dmac_1_IRQn      = 289,      /*!< 289 [Active] CPUSS DMAC, Channel #1 */
  cpuss_interrupts_dmac_2_IRQn      = 290,      /*!< 290 [Active] CPUSS DMAC, Channel #2 */
  cpuss_interrupts_dmac_3_IRQn      = 291,      /*!< 291 [Active] CPUSS DMAC, Channel #3 */
  cpuss_interrupts_dmac_4_IRQn      = 292,      /*!< 292 [Active] CPUSS DMAC, Channel #4 */
  cpuss_interrupts_dmac_5_IRQn      = 293,      /*!< 293 [Active] CPUSS DMAC, Channel #5 */
  cpuss_interrupts_dmac_6_IRQn      = 294,      /*!< 294 [Active] CPUSS DMAC, Channel #6 */
  cpuss_interrupts_dmac_7_IRQn      = 295,      /*!< 295 [Active] CPUSS DMAC, Channel #7 */
  cpuss_interrupts_dw0_0_IRQn       = 296,      /*!< 296 [Active] CPUSS DataWire #0, Channel #0 */
  cpuss_interrupts_dw0_1_IRQn       = 297,      /*!< 297 [Active] CPUSS DataWire #0, Channel #1 */
  cpuss_interrupts_dw0_2_IRQn       = 298,      /*!< 298 [Active] CPUSS DataWire #0, Channel #2 */
  cpuss_interrupts_dw0_3_IRQn       = 299,      /*!< 299 [Active] CPUSS DataWire #0, Channel #3 */
  cpuss_interrupts_dw0_4_IRQn       = 300,      /*!< 300 [Active] CPUSS DataWire #0, Channel #4 */
  cpuss_interrupts_dw0_5_IRQn       = 301,      /*!< 301 [Active] CPUSS DataWire #0, Channel #5 */
  cpuss_interrupts_dw0_6_IRQn       = 302,      /*!< 302 [Active] CPUSS DataWire #0, Channel #6 */
  cpuss_interrupts_dw0_7_IRQn       = 303,      /*!< 303 [Active] CPUSS DataWire #0, Channel #7 */
  cpuss_interrupts_dw0_8_IRQn       = 304,      /*!< 304 [Active] CPUSS DataWire #0, Channel #8 */
  cpuss_interrupts_dw0_9_IRQn       = 305,      /*!< 305 [Active] CPUSS DataWire #0, Channel #9 */
  cpuss_interrupts_dw0_10_IRQn      = 306,      /*!< 306 [Active] CPUSS DataWire #0, Channel #10 */
  cpuss_interrupts_dw0_11_IRQn      = 307,      /*!< 307 [Active] CPUSS DataWire #0, Channel #11 */
  cpuss_interrupts_dw0_12_IRQn      = 308,      /*!< 308 [Active] CPUSS DataWire #0, Channel #12 */
  cpuss_interrupts_dw0_13_IRQn      = 309,      /*!< 309 [Active] CPUSS DataWire #0, Channel #13 */
  cpuss_interrupts_dw0_14_IRQn      = 310,      /*!< 310 [Active] CPUSS DataWire #0, Channel #14 */
  cpuss_interrupts_dw0_15_IRQn      = 311,      /*!< 311 [Active] CPUSS DataWire #0, Channel #15 */
  cpuss_interrupts_dw0_16_IRQn      = 312,      /*!< 312 [Active] CPUSS DataWire #0, Channel #16 */
  cpuss_interrupts_dw0_17_IRQn      = 313,      /*!< 313 [Active] CPUSS DataWire #0, Channel #17 */
  cpuss_interrupts_dw0_18_IRQn      = 314,      /*!< 314 [Active] CPUSS DataWire #0, Channel #18 */
  cpuss_interrupts_dw0_19_IRQn      = 315,      /*!< 315 [Active] CPUSS DataWire #0, Channel #19 */
  cpuss_interrupts_dw0_20_IRQn      = 316,      /*!< 316 [Active] CPUSS DataWire #0, Channel #20 */
  cpuss_interrupts_dw0_21_IRQn      = 317,      /*!< 317 [Active] CPUSS DataWire #0, Channel #21 */
  cpuss_interrupts_dw0_22_IRQn      = 318,      /*!< 318 [Active] CPUSS DataWire #0, Channel #22 */
  cpuss_interrupts_dw0_23_IRQn      = 319,      /*!< 319 [Active] CPUSS DataWire #0, Channel #23 */
  cpuss_interrupts_dw0_24_IRQn      = 320,      /*!< 320 [Active] CPUSS DataWire #0, Channel #24 */
  cpuss_interrupts_dw0_25_IRQn      = 321,      /*!< 321 [Active] CPUSS DataWire #0, Channel #25 */
  cpuss_interrupts_dw0_26_IRQn      = 322,      /*!< 322 [Active] CPUSS DataWire #0, Channel #26 */
  cpuss_interrupts_dw0_27_IRQn      = 323,      /*!< 323 [Active] CPUSS DataWire #0, Channel #27 */
  cpuss_interrupts_dw0_28_IRQn      = 324,      /*!< 324 [Active] CPUSS DataWire #0, Channel #28 */
  cpuss_interrupts_dw0_29_IRQn      = 325,      /*!< 325 [Active] CPUSS DataWire #0, Channel #29 */
  cpuss_interrupts_dw0_30_IRQn      = 326,      /*!< 326 [Active] CPUSS DataWire #0, Channel #30 */
  cpuss_interrupts_dw0_31_IRQn      = 327,      /*!< 327 [Active] CPUSS DataWire #0, Channel #31 */
  cpuss_interrupts_dw0_32_IRQn      = 328,      /*!< 328 [Active] CPUSS DataWire #0, Channel #32 */
  cpuss_interrupts_dw0_33_IRQn      = 329,      /*!< 329 [Active] CPUSS DataWire #0, Channel #33 */
  cpuss_interrupts_dw0_34_IRQn      = 330,      /*!< 330 [Active] CPUSS DataWire #0, Channel #34 */
  cpuss_interrupts_dw0_35_IRQn      = 331,      /*!< 331 [Active] CPUSS DataWire #0, Channel #35 */
  cpuss_interrupts_dw0_36_IRQn      = 332,      /*!< 332 [Active] CPUSS DataWire #0, Channel #36 */
  cpuss_interrupts_dw0_37_IRQn      = 333,      /*!< 333 [Active] CPUSS DataWire #0, Channel #37 */
  cpuss_interrupts_dw0_38_IRQn      = 334,      /*!< 334 [Active] CPUSS DataWire #0, Channel #38 */
  cpuss_interrupts_dw0_39_IRQn      = 335,      /*!< 335 [Active] CPUSS DataWire #0, Channel #39 */
  cpuss_interrupts_dw0_40_IRQn      = 336,      /*!< 336 [Active] CPUSS DataWire #0, Channel #40 */
  cpuss_interrupts_dw0_41_IRQn      = 337,      /*!< 337 [Active] CPUSS DataWire #0, Channel #41 */
  cpuss_interrupts_dw0_42_IRQn      = 338,      /*!< 338 [Active] CPUSS DataWire #0, Channel #42 */
  cpuss_interrupts_dw0_43_IRQn      = 339,      /*!< 339 [Active] CPUSS DataWire #0, Channel #43 */
  cpuss_interrupts_dw0_44_IRQn      = 340,      /*!< 340 [Active] CPUSS DataWire #0, Channel #44 */
  cpuss_interrupts_dw0_45_IRQn      = 341,      /*!< 341 [Active] CPUSS DataWire #0, Channel #45 */
  cpuss_interrupts_dw0_46_IRQn      = 342,      /*!< 342 [Active] CPUSS DataWire #0, Channel #46 */
  cpuss_interrupts_dw0_47_IRQn      = 343,      /*!< 343 [Active] CPUSS DataWire #0, Channel #47 */
  cpuss_interrupts_dw0_48_IRQn      = 344,      /*!< 344 [Active] CPUSS DataWire #0, Channel #48 */
  cpuss_interrupts_dw0_49_IRQn      = 345,      /*!< 345 [Active] CPUSS DataWire #0, Channel #49 */
  cpuss_interrupts_dw0_50_IRQn      = 346,      /*!< 346 [Active] CPUSS DataWire #0, Channel #50 */
  cpuss_interrupts_dw0_51_IRQn      = 347,      /*!< 347 [Active] CPUSS DataWire #0, Channel #51 */
  cpuss_interrupts_dw0_52_IRQn      = 348,      /*!< 348 [Active] CPUSS DataWire #0, Channel #52 */
  cpuss_interrupts_dw0_53_IRQn      = 349,      /*!< 349 [Active] CPUSS DataWire #0, Channel #53 */
  cpuss_interrupts_dw0_54_IRQn      = 350,      /*!< 350 [Active] CPUSS DataWire #0, Channel #54 */
  cpuss_interrupts_dw0_55_IRQn      = 351,      /*!< 351 [Active] CPUSS DataWire #0, Channel #55 */
  cpuss_interrupts_dw0_56_IRQn      = 352,      /*!< 352 [Active] CPUSS DataWire #0, Channel #56 */
  cpuss_interrupts_dw0_57_IRQn      = 353,      /*!< 353 [Active] CPUSS DataWire #0, Channel #57 */
  cpuss_interrupts_dw0_58_IRQn      = 354,      /*!< 354 [Active] CPUSS DataWire #0, Channel #58 */
  cpuss_interrupts_dw0_59_IRQn      = 355,      /*!< 355 [Active] CPUSS DataWire #0, Channel #59 */
  cpuss_interrupts_dw0_60_IRQn      = 356,      /*!< 356 [Active] CPUSS DataWire #0, Channel #60 */
  cpuss_interrupts_dw0_61_IRQn      = 357,      /*!< 357 [Active] CPUSS DataWire #0, Channel #61 */
  cpuss_interrupts_dw0_62_IRQn      = 358,      /*!< 358 [Active] CPUSS DataWire #0, Channel #62 */
  cpuss_interrupts_dw0_63_IRQn      = 359,      /*!< 359 [Active] CPUSS DataWire #0, Channel #63 */
  cpuss_interrupts_dw0_64_IRQn      = 360,      /*!< 360 [Active] CPUSS DataWire #0, Channel #64 */
  cpuss_interrupts_dw0_65_IRQn      = 361,      /*!< 361 [Active] CPUSS DataWire #0, Channel #65 */
  cpuss_interrupts_dw0_66_IRQn      = 362,      /*!< 362 [Active] CPUSS DataWire #0, Channel #66 */
  cpuss_interrupts_dw0_67_IRQn      = 363,      /*!< 363 [Active] CPUSS DataWire #0, Channel #67 */
  cpuss_interrupts_dw0_68_IRQn      = 364,      /*!< 364 [Active] CPUSS DataWire #0, Channel #68 */
  cpuss_interrupts_dw0_69_IRQn      = 365,      /*!< 365 [Active] CPUSS DataWire #0, Channel #69 */
  cpuss_interrupts_dw0_70_IRQn      = 366,      /*!< 366 [Active] CPUSS DataWire #0, Channel #70 */
  cpuss_interrupts_dw0_71_IRQn      = 367,      /*!< 367 [Active] CPUSS DataWire #0, Channel #71 */
  cpuss_interrupts_dw0_72_IRQn      = 368,      /*!< 368 [Active] CPUSS DataWire #0, Channel #72 */
  cpuss_interrupts_dw0_73_IRQn      = 369,      /*!< 369 [Active] CPUSS DataWire #0, Channel #73 */
  cpuss_interrupts_dw0_74_IRQn      = 370,      /*!< 370 [Active] CPUSS DataWire #0, Channel #74 */
  cpuss_interrupts_dw0_75_IRQn      = 371,      /*!< 371 [Active] CPUSS DataWire #0, Channel #75 */
  cpuss_interrupts_dw1_0_IRQn       = 424,      /*!< 424 [Active] CPUSS DataWire #1, Channel #0 */
  cpuss_interrupts_dw1_1_IRQn       = 425,      /*!< 425 [Active] CPUSS DataWire #1, Channel #1 */
  cpuss_interrupts_dw1_2_IRQn       = 426,      /*!< 426 [Active] CPUSS DataWire #1, Channel #2 */
  cpuss_interrupts_dw1_3_IRQn       = 427,      /*!< 427 [Active] CPUSS DataWire #1, Channel #3 */
  cpuss_interrupts_dw1_4_IRQn       = 428,      /*!< 428 [Active] CPUSS DataWire #1, Channel #4 */
  cpuss_interrupts_dw1_5_IRQn       = 429,      /*!< 429 [Active] CPUSS DataWire #1, Channel #5 */
  cpuss_interrupts_dw1_6_IRQn       = 430,      /*!< 430 [Active] CPUSS DataWire #1, Channel #6 */
  cpuss_interrupts_dw1_7_IRQn       = 431,      /*!< 431 [Active] CPUSS DataWire #1, Channel #7 */
  cpuss_interrupts_dw1_8_IRQn       = 432,      /*!< 432 [Active] CPUSS DataWire #1, Channel #8 */
  cpuss_interrupts_dw1_9_IRQn       = 433,      /*!< 433 [Active] CPUSS DataWire #1, Channel #9 */
  cpuss_interrupts_dw1_10_IRQn      = 434,      /*!< 434 [Active] CPUSS DataWire #1, Channel #10 */
  cpuss_interrupts_dw1_11_IRQn      = 435,      /*!< 435 [Active] CPUSS DataWire #1, Channel #11 */
  cpuss_interrupts_dw1_12_IRQn      = 436,      /*!< 436 [Active] CPUSS DataWire #1, Channel #12 */
  cpuss_interrupts_dw1_13_IRQn      = 437,      /*!< 437 [Active] CPUSS DataWire #1, Channel #13 */
  cpuss_interrupts_dw1_14_IRQn      = 438,      /*!< 438 [Active] CPUSS DataWire #1, Channel #14 */
  cpuss_interrupts_dw1_15_IRQn      = 439,      /*!< 439 [Active] CPUSS DataWire #1, Channel #15 */
  cpuss_interrupts_dw1_16_IRQn      = 440,      /*!< 440 [Active] CPUSS DataWire #1, Channel #16 */
  cpuss_interrupts_dw1_17_IRQn      = 441,      /*!< 441 [Active] CPUSS DataWire #1, Channel #17 */
  cpuss_interrupts_dw1_18_IRQn      = 442,      /*!< 442 [Active] CPUSS DataWire #1, Channel #18 */
  cpuss_interrupts_dw1_19_IRQn      = 443,      /*!< 443 [Active] CPUSS DataWire #1, Channel #19 */
  cpuss_interrupts_dw1_20_IRQn      = 444,      /*!< 444 [Active] CPUSS DataWire #1, Channel #20 */
  cpuss_interrupts_dw1_21_IRQn      = 445,      /*!< 445 [Active] CPUSS DataWire #1, Channel #21 */
  cpuss_interrupts_dw1_22_IRQn      = 446,      /*!< 446 [Active] CPUSS DataWire #1, Channel #22 */
  cpuss_interrupts_dw1_23_IRQn      = 447,      /*!< 447 [Active] CPUSS DataWire #1, Channel #23 */
  cpuss_interrupts_dw1_24_IRQn      = 448,      /*!< 448 [Active] CPUSS DataWire #1, Channel #24 */
  cpuss_interrupts_dw1_25_IRQn      = 449,      /*!< 449 [Active] CPUSS DataWire #1, Channel #25 */
  cpuss_interrupts_dw1_26_IRQn      = 450,      /*!< 450 [Active] CPUSS DataWire #1, Channel #26 */
  cpuss_interrupts_dw1_27_IRQn      = 451,      /*!< 451 [Active] CPUSS DataWire #1, Channel #27 */
  cpuss_interrupts_dw1_28_IRQn      = 452,      /*!< 452 [Active] CPUSS DataWire #1, Channel #28 */
  cpuss_interrupts_dw1_29_IRQn      = 453,      /*!< 453 [Active] CPUSS DataWire #1, Channel #29 */
  cpuss_interrupts_dw1_30_IRQn      = 454,      /*!< 454 [Active] CPUSS DataWire #1, Channel #30 */
  cpuss_interrupts_dw1_31_IRQn      = 455,      /*!< 455 [Active] CPUSS DataWire #1, Channel #31 */
  cpuss_interrupts_dw1_32_IRQn      = 456,      /*!< 456 [Active] CPUSS DataWire #1, Channel #32 */
  cpuss_interrupts_dw1_33_IRQn      = 457,      /*!< 457 [Active] CPUSS DataWire #1, Channel #33 */
  cpuss_interrupts_dw1_34_IRQn      = 458,      /*!< 458 [Active] CPUSS DataWire #1, Channel #34 */
  cpuss_interrupts_dw1_35_IRQn      = 459,      /*!< 459 [Active] CPUSS DataWire #1, Channel #35 */
  cpuss_interrupts_dw1_36_IRQn      = 460,      /*!< 460 [Active] CPUSS DataWire #1, Channel #36 */
  cpuss_interrupts_dw1_37_IRQn      = 461,      /*!< 461 [Active] CPUSS DataWire #1, Channel #37 */
  cpuss_interrupts_dw1_38_IRQn      = 462,      /*!< 462 [Active] CPUSS DataWire #1, Channel #38 */
  cpuss_interrupts_dw1_39_IRQn      = 463,      /*!< 463 [Active] CPUSS DataWire #1, Channel #39 */
  cpuss_interrupts_dw1_40_IRQn      = 464,      /*!< 464 [Active] CPUSS DataWire #1, Channel #40 */
  cpuss_interrupts_dw1_41_IRQn      = 465,      /*!< 465 [Active] CPUSS DataWire #1, Channel #41 */
  cpuss_interrupts_dw1_42_IRQn      = 466,      /*!< 466 [Active] CPUSS DataWire #1, Channel #42 */
  cpuss_interrupts_dw1_43_IRQn      = 467,      /*!< 467 [Active] CPUSS DataWire #1, Channel #43 */
  cpuss_interrupts_dw1_44_IRQn      = 468,      /*!< 468 [Active] CPUSS DataWire #1, Channel #44 */
  cpuss_interrupts_dw1_45_IRQn      = 469,      /*!< 469 [Active] CPUSS DataWire #1, Channel #45 */
  cpuss_interrupts_dw1_46_IRQn      = 470,      /*!< 470 [Active] CPUSS DataWire #1, Channel #46 */
  cpuss_interrupts_dw1_47_IRQn      = 471,      /*!< 471 [Active] CPUSS DataWire #1, Channel #47 */
  cpuss_interrupts_dw1_48_IRQn      = 472,      /*!< 472 [Active] CPUSS DataWire #1, Channel #48 */
  cpuss_interrupts_dw1_49_IRQn      = 473,      /*!< 473 [Active] CPUSS DataWire #1, Channel #49 */
  cpuss_interrupts_dw1_50_IRQn      = 474,      /*!< 474 [Active] CPUSS DataWire #1, Channel #50 */
  cpuss_interrupts_dw1_51_IRQn      = 475,      /*!< 475 [Active] CPUSS DataWire #1, Channel #51 */
  cpuss_interrupts_dw1_52_IRQn      = 476,      /*!< 476 [Active] CPUSS DataWire #1, Channel #52 */
  cpuss_interrupts_dw1_53_IRQn      = 477,      /*!< 477 [Active] CPUSS DataWire #1, Channel #53 */
  cpuss_interrupts_dw1_54_IRQn      = 478,      /*!< 478 [Active] CPUSS DataWire #1, Channel #54 */
  cpuss_interrupts_dw1_55_IRQn      = 479,      /*!< 479 [Active] CPUSS DataWire #1, Channel #55 */
  cpuss_interrupts_dw1_56_IRQn      = 480,      /*!< 480 [Active] CPUSS DataWire #1, Channel #56 */
  cpuss_interrupts_dw1_57_IRQn      = 481,      /*!< 481 [Active] CPUSS DataWire #1, Channel #57 */
  cpuss_interrupts_dw1_58_IRQn      = 482,      /*!< 482 [Active] CPUSS DataWire #1, Channel #58 */
  cpuss_interrupts_dw1_59_IRQn      = 483,      /*!< 483 [Active] CPUSS DataWire #1, Channel #59 */
  cpuss_interrupts_dw1_60_IRQn      = 484,      /*!< 484 [Active] CPUSS DataWire #1, Channel #60 */
  cpuss_interrupts_dw1_61_IRQn      = 485,      /*!< 485 [Active] CPUSS DataWire #1, Channel #61 */
  cpuss_interrupts_dw1_62_IRQn      = 486,      /*!< 486 [Active] CPUSS DataWire #1, Channel #62 */
  cpuss_interrupts_dw1_63_IRQn      = 487,      /*!< 487 [Active] CPUSS DataWire #1, Channel #63 */
  cpuss_interrupts_dw1_64_IRQn      = 488,      /*!< 488 [Active] CPUSS DataWire #1, Channel #64 */
  cpuss_interrupts_dw1_65_IRQn      = 489,      /*!< 489 [Active] CPUSS DataWire #1, Channel #65 */
  cpuss_interrupts_dw1_66_IRQn      = 490,      /*!< 490 [Active] CPUSS DataWire #1, Channel #66 */
  cpuss_interrupts_dw1_67_IRQn      = 491,      /*!< 491 [Active] CPUSS DataWire #1, Channel #67 */
  cpuss_interrupts_dw1_68_IRQn      = 492,      /*!< 492 [Active] CPUSS DataWire #1, Channel #68 */
  cpuss_interrupts_dw1_69_IRQn      = 493,      /*!< 493 [Active] CPUSS DataWire #1, Channel #69 */
  cpuss_interrupts_dw1_70_IRQn      = 494,      /*!< 494 [Active] CPUSS DataWire #1, Channel #70 */
  cpuss_interrupts_dw1_71_IRQn      = 495,      /*!< 495 [Active] CPUSS DataWire #1, Channel #71 */
  cpuss_interrupts_dw1_72_IRQn      = 496,      /*!< 496 [Active] CPUSS DataWire #1, Channel #72 */
  cpuss_interrupts_dw1_73_IRQn      = 497,      /*!< 497 [Active] CPUSS DataWire #1, Channel #73 */
  cpuss_interrupts_dw1_74_IRQn      = 498,      /*!< 498 [Active] CPUSS DataWire #1, Channel #74 */
  cpuss_interrupts_dw1_75_IRQn      = 499,      /*!< 499 [Active] CPUSS DataWire #1, Channel #75 */
  cpuss_interrupts_dw1_76_IRQn      = 500,      /*!< 500 [Active] CPUSS DataWire #1, Channel #76 */
  cpuss_interrupts_dw1_77_IRQn      = 501,      /*!< 501 [Active] CPUSS DataWire #1, Channel #77 */
  cpuss_interrupts_dw1_78_IRQn      = 502,      /*!< 502 [Active] CPUSS DataWire #1, Channel #78 */
  cpuss_interrupts_dw1_79_IRQn      = 503,      /*!< 503 [Active] CPUSS DataWire #1, Channel #79 */
  cpuss_interrupts_dw1_80_IRQn      = 504,      /*!< 504 [Active] CPUSS DataWire #1, Channel #80 */
  cpuss_interrupts_dw1_81_IRQn      = 505,      /*!< 505 [Active] CPUSS DataWire #1, Channel #81 */
  cpuss_interrupts_dw1_82_IRQn      = 506,      /*!< 506 [Active] CPUSS DataWire #1, Channel #82 */
  cpuss_interrupts_dw1_83_IRQn      = 507,      /*!< 507 [Active] CPUSS DataWire #1, Channel #83 */
  tcpwm_0_interrupts_0_IRQn         = 552,      /*!< 552 [Active] TCPWM0 Group #0, Counter #0 */
  tcpwm_0_interrupts_1_IRQn         = 553,      /*!< 553 [Active] TCPWM0 Group #0, Counter #1 */
  tcpwm_0_interrupts_2_IRQn         = 554,      /*!< 554 [Active] TCPWM0 Group #0, Counter #2 */
  tcpwm_0_interrupts_3_IRQn         = 555,      /*!< 555 [Active] TCPWM0 Group #0, Counter #3 */
  tcpwm_0_interrupts_4_IRQn         = 556,      /*!< 556 [Active] TCPWM0 Group #0, Counter #4 */
  tcpwm_0_interrupts_5_IRQn         = 557,      /*!< 557 [Active] TCPWM0 Group #0, Counter #5 */
  tcpwm_0_interrupts_6_IRQn         = 558,      /*!< 558 [Active] TCPWM0 Group #0, Counter #6 */
  tcpwm_0_interrupts_7_IRQn         = 559,      /*!< 559 [Active] TCPWM0 Group #0, Counter #7 */
  tcpwm_0_interrupts_8_IRQn         = 560,      /*!< 560 [Active] TCPWM0 Group #0, Counter #8 */
  tcpwm_0_interrupts_9_IRQn         = 561,      /*!< 561 [Active] TCPWM0 Group #0, Counter #9 */
  tcpwm_0_interrupts_10_IRQn        = 562,      /*!< 562 [Active] TCPWM0 Group #0, Counter #10 */
  tcpwm_0_interrupts_11_IRQn        = 563,      /*!< 563 [Active] TCPWM0 Group #0, Counter #11 */
  tcpwm_0_interrupts_12_IRQn        = 564,      /*!< 564 [Active] TCPWM0 Group #0, Counter #12 */
  tcpwm_0_interrupts_13_IRQn        = 565,      /*!< 565 [Active] TCPWM0 Group #0, Counter #13 */
  tcpwm_0_interrupts_14_IRQn        = 566,      /*!< 566 [Active] TCPWM0 Group #0, Counter #14 */
  tcpwm_0_interrupts_15_IRQn        = 567,      /*!< 567 [Active] TCPWM0 Group #0, Counter #15 */
  tcpwm_0_interrupts_16_IRQn        = 568,      /*!< 568 [Active] TCPWM0 Group #0, Counter #16 */
  tcpwm_0_interrupts_17_IRQn        = 569,      /*!< 569 [Active] TCPWM0 Group #0, Counter #17 */
  tcpwm_0_interrupts_18_IRQn        = 570,      /*!< 570 [Active] TCPWM0 Group #0, Counter #18 */
  tcpwm_0_interrupts_19_IRQn        = 571,      /*!< 571 [Active] TCPWM0 Group #0, Counter #19 */
  tcpwm_0_interrupts_20_IRQn        = 572,      /*!< 572 [Active] TCPWM0 Group #0, Counter #20 */
  tcpwm_0_interrupts_21_IRQn        = 573,      /*!< 573 [Active] TCPWM0 Group #0, Counter #21 */
  tcpwm_0_interrupts_22_IRQn        = 574,      /*!< 574 [Active] TCPWM0 Group #0, Counter #22 */
  tcpwm_0_interrupts_23_IRQn        = 575,      /*!< 575 [Active] TCPWM0 Group #0, Counter #23 */
  tcpwm_0_interrupts_24_IRQn        = 576,      /*!< 576 [Active] TCPWM0 Group #0, Counter #24 */
  tcpwm_0_interrupts_25_IRQn        = 577,      /*!< 577 [Active] TCPWM0 Group #0, Counter #25 */
  tcpwm_0_interrupts_26_IRQn        = 578,      /*!< 578 [Active] TCPWM0 Group #0, Counter #26 */
  tcpwm_0_interrupts_27_IRQn        = 579,      /*!< 579 [Active] TCPWM0 Group #0, Counter #27 */
  tcpwm_0_interrupts_28_IRQn        = 580,      /*!< 580 [Active] TCPWM0 Group #0, Counter #28 */
  tcpwm_0_interrupts_29_IRQn        = 581,      /*!< 581 [Active] TCPWM0 Group #0, Counter #29 */
  tcpwm_0_interrupts_30_IRQn        = 582,      /*!< 582 [Active] TCPWM0 Group #0, Counter #30 */
  tcpwm_0_interrupts_31_IRQn        = 583,      /*!< 583 [Active] TCPWM0 Group #0, Counter #31 */
  tcpwm_0_interrupts_32_IRQn        = 584,      /*!< 584 [Active] TCPWM0 Group #0, Counter #32 */
  tcpwm_0_interrupts_33_IRQn        = 585,      /*!< 585 [Active] TCPWM0 Group #0, Counter #33 */
  tcpwm_0_interrupts_34_IRQn        = 586,      /*!< 586 [Active] TCPWM0 Group #0, Counter #34 */
  tcpwm_0_interrupts_35_IRQn        = 587,      /*!< 587 [Active] TCPWM0 Group #0, Counter #35 */
  tcpwm_0_interrupts_36_IRQn        = 588,      /*!< 588 [Active] TCPWM0 Group #0, Counter #36 */
  tcpwm_0_interrupts_37_IRQn        = 589,      /*!< 589 [Active] TCPWM0 Group #0, Counter #37 */
  tcpwm_0_interrupts_256_IRQn       = 616,      /*!< 616 [Active] TCPWM0 Group #1, Counter #0 */
  tcpwm_0_interrupts_257_IRQn       = 617,      /*!< 617 [Active] TCPWM0 Group #1, Counter #1 */
  tcpwm_0_interrupts_258_IRQn       = 618,      /*!< 618 [Active] TCPWM0 Group #1, Counter #2 */
  tcpwm_0_interrupts_259_IRQn       = 619,      /*!< 619 [Active] TCPWM0 Group #1, Counter #3 */
  tcpwm_0_interrupts_260_IRQn       = 620,      /*!< 620 [Active] TCPWM0 Group #1, Counter #4 */
  tcpwm_0_interrupts_261_IRQn       = 621,      /*!< 621 [Active] TCPWM0 Group #1, Counter #5 */
  tcpwm_0_interrupts_262_IRQn       = 622,      /*!< 622 [Active] TCPWM0 Group #1, Counter #6 */
  tcpwm_0_interrupts_263_IRQn       = 623,      /*!< 623 [Active] TCPWM0 Group #1, Counter #7 */
  tcpwm_0_interrupts_264_IRQn       = 624,      /*!< 624 [Active] TCPWM0 Group #1, Counter #8 */
  tcpwm_0_interrupts_265_IRQn       = 625,      /*!< 625 [Active] TCPWM0 Group #1, Counter #9 */
  tcpwm_0_interrupts_266_IRQn       = 626,      /*!< 626 [Active] TCPWM0 Group #1, Counter #10 */
  tcpwm_0_interrupts_267_IRQn       = 627,      /*!< 627 [Active] TCPWM0 Group #1, Counter #11 */
  tcpwm_0_interrupts_512_IRQn       = 680,      /*!< 680 [Active] TCPWM0 Group #2, Counter #0 */
  tcpwm_0_interrupts_513_IRQn       = 681,      /*!< 681 [Active] TCPWM0 Group #2, Counter #1 */
  tcpwm_0_interrupts_514_IRQn       = 682,      /*!< 682 [Active] TCPWM0 Group #2, Counter #2 */
  tcpwm_0_interrupts_515_IRQn       = 683,      /*!< 683 [Active] TCPWM0 Group #2, Counter #3 */
  tcpwm_0_interrupts_516_IRQn       = 684,      /*!< 684 [Active] TCPWM0 Group #2, Counter #4 */
  tcpwm_0_interrupts_517_IRQn       = 685,      /*!< 685 [Active] TCPWM0 Group #2, Counter #5 */
  tcpwm_0_interrupts_518_IRQn       = 686,      /*!< 686 [Active] TCPWM0 Group #2, Counter #6 */
  tcpwm_0_interrupts_519_IRQn       = 687,      /*!< 687 [Active] TCPWM0 Group #2, Counter #7 */
  tcpwm_0_interrupts_520_IRQn       = 688,      /*!< 688 [Active] TCPWM0 Group #2, Counter #8 */
  tcpwm_0_interrupts_521_IRQn       = 689,      /*!< 689 [Active] TCPWM0 Group #2, Counter #9 */
  tcpwm_0_interrupts_522_IRQn       = 690,      /*!< 690 [Active] TCPWM0 Group #2, Counter #10 */
  tcpwm_0_interrupts_523_IRQn       = 691,      /*!< 691 [Active] TCPWM0 Group #2, Counter #11 */
  tcpwm_0_interrupts_524_IRQn       = 692,      /*!< 692 [Active] TCPWM0 Group #2, Counter #12 */
  tcpwm_0_interrupts_525_IRQn       = 693,      /*!< 693 [Active] TCPWM0 Group #2, Counter #13 */
  tcpwm_0_interrupts_526_IRQn       = 694,      /*!< 694 [Active] TCPWM0 Group #2, Counter #14 */
  tcpwm_0_interrupts_527_IRQn       = 695,      /*!< 695 [Active] TCPWM0 Group #2, Counter #15 */
  tcpwm_0_interrupts_528_IRQn       = 696,      /*!< 696 [Active] TCPWM0 Group #2, Counter #16 */
  tcpwm_0_interrupts_529_IRQn       = 697,      /*!< 697 [Active] TCPWM0 Group #2, Counter #17 */
  tcpwm_0_interrupts_530_IRQn       = 698,      /*!< 698 [Active] TCPWM0 Group #2, Counter #18 */
  tcpwm_0_interrupts_531_IRQn       = 699,      /*!< 699 [Active] TCPWM0 Group #2, Counter #19 */
  tcpwm_0_interrupts_532_IRQn       = 700,      /*!< 700 [Active] TCPWM0 Group #2, Counter #20 */
  tcpwm_0_interrupts_533_IRQn       = 701,      /*!< 701 [Active] TCPWM0 Group #2, Counter #21 */
  tcpwm_0_interrupts_534_IRQn       = 702,      /*!< 702 [Active] TCPWM0 Group #2, Counter #22 */
  tcpwm_0_interrupts_535_IRQn       = 703,      /*!< 703 [Active] TCPWM0 Group #2, Counter #23 */
  tcpwm_0_interrupts_536_IRQn       = 704,      /*!< 704 [Active] TCPWM0 Group #2, Counter #24 */
  tcpwm_0_interrupts_537_IRQn       = 705,      /*!< 705 [Active] TCPWM0 Group #2, Counter #25 */
  tcpwm_0_interrupts_538_IRQn       = 706,      /*!< 706 [Active] TCPWM0 Group #2, Counter #26 */
  tcpwm_0_interrupts_539_IRQn       = 707,      /*!< 707 [Active] TCPWM0 Group #2, Counter #27 */
  tcpwm_0_interrupts_540_IRQn       = 708,      /*!< 708 [Active] TCPWM0 Group #2, Counter #28 */
  tcpwm_0_interrupts_541_IRQn       = 709,      /*!< 709 [Active] TCPWM0 Group #2, Counter #29 */
  tcpwm_0_interrupts_542_IRQn       = 710,      /*!< 710 [Active] TCPWM0 Group #2, Counter #30 */
  tcpwm_0_interrupts_543_IRQn       = 711,      /*!< 711 [Active] TCPWM0 Group #2, Counter #31 */
  tdm_0_interrupts_tx_0_IRQn        = 752,      /*!< 752 [Active] TDM#0 tx interrupt #0 */
  tdm_0_interrupts_rx_0_IRQn        = 753,      /*!< 753 [Active] TDM#0 rx interrupt #0 */
  tdm_0_interrupts_tx_1_IRQn        = 754,      /*!< 754 [Active] TDM#0 tx interrupt #1 */
  tdm_0_interrupts_rx_1_IRQn        = 755,      /*!< 755 [Active] TDM#0 rx interrupt #1 */
  tdm_0_interrupts_tx_2_IRQn        = 756,      /*!< 756 [Active] TDM#0 tx interrupt #2 */
  tdm_0_interrupts_rx_2_IRQn        = 757,      /*!< 757 [Active] TDM#0 rx interrupt #2 */
  tdm_0_interrupts_tx_3_IRQn        = 758,      /*!< 758 [Active] TDM#0 tx interrupt #3 */
  tdm_0_interrupts_rx_3_IRQn        = 759,      /*!< 759 [Active] TDM#0 rx interrupt #3 */
  sg_0_interrupts_0_IRQn            = 760,      /*!< 760 [Active] SG#0 interrupt #0 */
  sg_0_interrupts_1_IRQn            = 761,      /*!< 761 [Active] SG#0 interrupt #1 */
  sg_0_interrupts_2_IRQn            = 762,      /*!< 762 [Active] SG#0 interrupt #2 */
  sg_0_interrupts_3_IRQn            = 763,      /*!< 763 [Active] SG#0 interrupt #3 */
  sg_0_interrupts_4_IRQn            = 764,      /*!< 764 [Active] SG#0 interrupt #4 */
  pwm_0_interrupts_0_IRQn           = 768,      /*!< 768 [Active] PWM#0 interrupt #0 */
  pwm_0_interrupts_1_IRQn           = 769,      /*!< 769 [Active] PWM#0 interrupt #1 */
  dac_0_interrupt_IRQn              = 776,      /*!< 776 [Active] DAC interrupt */
  mixer_0_interrupt_dst_IRQn        = 780,      /*!< 780 [Active] MIXER#0 dst interrupt */
  mixer_0_interrupts_src_0_IRQn     = 781,      /*!< 781 [Active] MIXER#0 src interrupt #0 */
  mixer_0_interrupts_src_1_IRQn     = 782,      /*!< 782 [Active] MIXER#0 src interrupt #1 */
  mixer_0_interrupts_src_2_IRQn     = 783,      /*!< 783 [Active] MIXER#0 src interrupt #2 */
  mixer_0_interrupts_src_3_IRQn     = 784,      /*!< 784 [Active] MIXER#0 src interrupt #3 */
  mixer_0_interrupts_src_4_IRQn     = 785,      /*!< 785 [Active] MIXER#0 src interrupt #4 */
  mixer_1_interrupt_dst_IRQn        = 789,      /*!< 789 [Active] MIXER#1 dst interrupt */
  mixer_1_interrupts_src_0_IRQn     = 790,      /*!< 790 [Active] MIXER#1 src interrupt #0 */
  mixer_1_interrupts_src_1_IRQn     = 791,      /*!< 791 [Active] MIXER#1 src interrupt #1 */
  mixer_1_interrupts_src_2_IRQn     = 792,      /*!< 792 [Active] MIXER#1 src interrupt #2 */
  mixer_1_interrupts_src_3_IRQn     = 793,      /*!< 793 [Active] MIXER#1 src interrupt #3 */
  mixer_1_interrupts_src_4_IRQn     = 794,      /*!< 794 [Active] MIXER#1 src interrupt #4 */
  disconnected_IRQn                 =1023       /*!< 1023 Disconnected */
} cy_en_intr_t;

/*******************************************************************************
*                    Processor and Core Peripheral Section
*******************************************************************************/

#if ((defined(__GNUC__)        && (__ARM_ARCH == 6) && (__ARM_ARCH_6M__ == 1)) || \
     (defined(__ICCARM__)      && (__CORE__ == __ARM6M__)) || \
     (defined(__ARMCC_VERSION) && defined(__TARGET_ARCH_THUMB) && (__TARGET_ARCH_THUMB == 3)) || \
     (defined(__ghs__)         && defined(__CORE_CORTEXM0PLUS__)))

/* Configuration of the ARM Cortex-M0+ Processor and Core Peripherals */
#define __CM0PLUS_REV                   0x0001U /*!< CM0PLUS Core Revision */
#define __NVIC_PRIO_BITS                2       /*!< Number of Bits used for Priority Levels */
#define __Vendor_SysTickConfig          0       /*!< Set to 1 if different SysTick Config is used */
#define __VTOR_PRESENT                  1       /*!< Set to 1 if CPU supports Vector Table Offset Register */
#define __MPU_PRESENT                   1       /*!< MPU present or not */

/** \} Configuration_of_CMSIS */

#include "core_cm0plus.h"                       /*!< ARM Cortex-M0+ processor and core peripherals */

#else

/* Configuration of the ARM Cortex-M7 Processor and Core Peripherals */
#define __CM7_REV                       0x0001U /*!< CM7 Core Revision */
#define __NVIC_PRIO_BITS                3       /*!< Number of Bits used for Priority Levels */
#define __Vendor_SysTickConfig          0       /*!< Set to 1 if different SysTick Config is used */
#define __VTOR_PRESENT                  1       /*!< Set to 1 if CPU supports Vector Table Offset Register */
#define __MPU_PRESENT                   1       /*!< MPU present or not */
#define __FPU_PRESENT                   1       /*!< FPU present or not */
#define __CM0P_PRESENT                  1       /*!< CM0P present or not */
#define __CM7_0_PRESENT                 1       /*!< CM7_0 present or not */
#define __CM7_1_PRESENT                 1       /*!< CM7_1 present or not */
#define __DTCM_PRESENT                  1       /*!< Data Tightly Coupled Memory is present or not */
#define __ICACHE_PRESENT                1       /*!< Instruction Cache present or not */
#define __DCACHE_PRESENT                1       /*!< Data Cache present or not */

/** \} Configuration_of_CMSIS */

#include "core_cm7.h"                           /*!< ARM Cortex-M7 processor and core peripherals */

#endif

/* Memory Blocks */
#define CY_CM7_ITCM_INTERNAL_BASE       0x00000000UL
#define CY_CM7_ITCM_INTERNAL_SIZE       0x00010000UL
#define CY_ROM_BASE                     0x00000000UL
#define CY_ROM_SIZE                     0x00010000UL
#define CY_ROM_MIRROR_BASE              0x01000000UL
#define CY_ROM_MIRROR_SIZE              0x00010000UL
#define CY_FLASH_LG_SBM_BASE            0x10000000UL
#define CY_FLASH_LG_SBM_SIZE            0x005F0000UL
#define CY_FLASH_LG_DBM0_BASE           0x10000000UL
#define CY_FLASH_LG_DBM0_SIZE           0x002F8000UL
#define CY_FLASH_SM_DBM0_BASE           0x102F8000UL
#define CY_FLASH_SM_DBM0_SIZE           0x00020000UL
#define CY_FLASH_SM_SBM_BASE            0x105F0000UL
#define CY_FLASH_SM_SBM_SIZE            0x00040000UL
#define CY_FLASH_LG_DBM1_BASE           0x12000000UL
#define CY_FLASH_LG_DBM1_SIZE           0x002F8000UL
#define CY_FLASH_SM_DBM1_BASE           0x122F8000UL
#define CY_FLASH_SM_DBM1_SIZE           0x00020000UL
#define CY_WFLASH_LG_SBM_BASE           0x14000000UL
#define CY_WFLASH_LG_SBM_SIZE           0x00018000UL
#define CY_WFLASH_LG_DBM0_BASE          0x14000000UL
#define CY_WFLASH_LG_DBM0_SIZE          0x0000C000UL
#define CY_WFLASH_SM_DBM0_BASE          0x1400C000UL
#define CY_WFLASH_SM_DBM0_SIZE          0x00004000UL
#define CY_WFLASH_SM_SBM_BASE           0x14018000UL
#define CY_WFLASH_SM_SBM_SIZE           0x00008000UL
#define CY_WFLASH_LG_DBM1_BASE          0x15000000UL
#define CY_WFLASH_LG_DBM1_SIZE          0x0000C000UL
#define CY_WFLASH_SM_DBM1_BASE          0x1500C000UL
#define CY_WFLASH_SM_DBM1_SIZE          0x00004000UL
#define CY_OTPFLASH_BASE                0x16000000UL
#define CY_OTPFLASH_SIZE                0x00010000UL
#define CY_SFLASH_BASE                  0x17000000UL
#define CY_SFLASH_SIZE                  0x00008000UL
#define CY_SFLASH1_BASE                 0x17800000UL
#define CY_SFLASH1_SIZE                 0x00008000UL
#define CY_CM7_DTCM_INTERNAL_BASE       0x20000000UL
#define CY_CM7_DTCM_INTERNAL_SIZE       0x00010000UL
#define CY_VIDEOSS_VRAM_BASE            0x24000000UL
#define CY_VIDEOSS_VRAM_SIZE            0x00400000UL
#define CY_EFUSE_BASE                   0x402C0800UL
#define CY_EFUSE_SIZE                   0x00000200UL
#define CY_CAN0MRAM_BASE                0x40530000UL
#define CY_CAN0MRAM_SIZE                0x00010000UL
#define CY_CAN1MRAM_BASE                0x40550000UL
#define CY_CAN1MRAM_SIZE                0x00010000UL
#define CY_SMIF_PORT0_BASE              0x60000000UL
#define CY_SMIF_PORT0_SIZE              0x20000000UL
#define CY_SMIF_PORT1_BASE              0x80000000UL
#define CY_SMIF_PORT1_SIZE              0x20000000UL
#define CY_CM7_0_ITCM_BASE              0xA0000000UL
#define CY_CM7_0_ITCM_SIZE              0x00010000UL
#define CY_CM7_0_DTCM_BASE              0xA0010000UL
#define CY_CM7_0_DTCM_SIZE              0x00010000UL
#define CY_CM7_1_ITCM_BASE              0xA0100000UL
#define CY_CM7_1_ITCM_SIZE              0x00010000UL
#define CY_CM7_1_DTCM_BASE              0xA0110000UL
#define CY_CM7_1_DTCM_SIZE              0x00010000UL
#define CY_SRAM_BASE                    0x28000000UL
#define CY_SRAM_SIZE                    0x000A0000UL


/* IP List */
#define CY_IP_MXAXIDMAC                 1u
#define CY_IP_MXAXIDMAC_INSTANCES       1u
#define CY_IP_MXAXIDMAC_VERSION         1u
#define CY_IP_MXAXIDMAC_VERSION_MINOR   0u
#define CY_IP_MXTTCANFD                 1u
#define CY_IP_MXTTCANFD_INSTANCES       2u
#define CY_IP_MXTTCANFD_VERSION         1u
#define CY_IP_MXTTCANFD_VERSION_MINOR   0u
#define CY_IP_M7CPUSS                   1u
#define CY_IP_M7CPUSS_INSTANCES         1u
#define CY_IP_M7CPUSS_VERSION           1u
#define CY_IP_M7CPUSS_VERSION_MINOR     0u
#define CY_IP_MXS40FAULT                1u
#define CY_IP_MXS40FAULT_INSTANCES      1u
#define CY_IP_MXS40FAULT_VERSION        1u
#define CY_IP_MXS40FAULT_VERSION_MINOR  0u
#define CY_IP_M7CPUSS_DMAC              1u
#define CY_IP_M7CPUSS_DMAC_INSTANCES    1u
#define CY_IP_M7CPUSS_DMAC_VERSION      1u
#define CY_IP_M7CPUSS_DMAC_VERSION_MINOR 0u
#define CY_IP_M7CPUSS_DMA               1u
#define CY_IP_M7CPUSS_DMA_INSTANCES     2u
#define CY_IP_M7CPUSS_DMA_VERSION       1u
#define CY_IP_M7CPUSS_DMA_VERSION_MINOR 0u
#define CY_IP_MXCRYPTO                  1u
#define CY_IP_MXCRYPTO_INSTANCES        1u
#define CY_IP_MXCRYPTO_VERSION          2u
#define CY_IP_MXCRYPTO_VERSION_MINOR    0u
#define CY_IP_MXCXPI                    1u
#define CY_IP_MXCXPI_INSTANCES          1u
#define CY_IP_MXCXPI_VERSION            1u
#define CY_IP_MXCXPI_VERSION_MINOR      0u
#define CY_IP_MXS40EAUDIODAC            1u
#define CY_IP_MXS40EAUDIODAC_INSTANCES  1u
#define CY_IP_MXS40EAUDIODAC_VERSION    1u
#define CY_IP_MXS40EAUDIODAC_VERSION_MINOR 0u
#define CY_IP_MXDFT                     1u
#define CY_IP_MXDFT_INSTANCES           1u
#define CY_IP_MXDFT_VERSION             2u
#define CY_IP_MXDFT_VERSION_MINOR       0u
#define CY_IP_MXEFUSE                   1u
#define CY_IP_MXEFUSE_INSTANCES         1u
#define CY_IP_MXEFUSE_VERSION           2u
#define CY_IP_MXEFUSE_VERSION_MINOR     0u
#define CY_IP_MXETH                     1u
#define CY_IP_MXETH_INSTANCES           1u
#define CY_IP_MXETH_VERSION             2u
#define CY_IP_MXETH_VERSION_MINOR       0u
#define CY_IP_MXEVTGEN                  1u
#define CY_IP_MXEVTGEN_INSTANCES        1u
#define CY_IP_MXEVTGEN_VERSION          1u
#define CY_IP_MXEVTGEN_VERSION_MINOR    0u
#define CY_IP_MXS40IOSS                 1u
#define CY_IP_MXS40IOSS_INSTANCES       1u
#define CY_IP_MXS40IOSS_VERSION         5u
#define CY_IP_MXS40IOSS_VERSION_MINOR   0u
#define CY_IP_MXLIN                     1u
#define CY_IP_MXLIN_INSTANCES           1u
#define CY_IP_MXLIN_VERSION             1u
#define CY_IP_MXLIN_VERSION_MINOR       0u
#define CY_IP_MXMIXER                   1u
#define CY_IP_MXMIXER_INSTANCES         2u
#define CY_IP_MXMIXER_VERSION           1u
#define CY_IP_MXMIXER_VERSION_MINOR     0u
#define CY_IP_MXS40EPASS                1u
#define CY_IP_MXS40EPASS_INSTANCES      1u
#define CY_IP_MXS40EPASS_VERSION        1u
#define CY_IP_MXS40EPASS_VERSION_MINOR  0u
#define CY_IP_MXS40EPASS_ESAR           1u
#define CY_IP_MXS40EPASS_ESAR_INSTANCES 1u
#define CY_IP_MXS40EPASS_ESAR_VERSION   1u
#define CY_IP_MXS40EPASS_ESAR_VERSION_MINOR 0u
#define CY_IP_MXPERI                    1u
#define CY_IP_MXPERI_INSTANCES          1u
#define CY_IP_MXPERI_VERSION            3u
#define CY_IP_MXPERI_VERSION_MINOR      0u
#define CY_IP_MXPERI_TR                 1u
#define CY_IP_MXPERI_TR_INSTANCES       1u
#define CY_IP_MXPERI_TR_VERSION         3u
#define CY_IP_MXPERI_TR_VERSION_MINOR   0u
#define CY_IP_MXPWM                     1u
#define CY_IP_MXPWM_INSTANCES           1u
#define CY_IP_MXPWM_VERSION             1u
#define CY_IP_MXPWM_VERSION_MINOR       0u
#define CY_IP_MXSCB                     1u
#define CY_IP_MXSCB_INSTANCES           12u
#define CY_IP_MXSCB_VERSION             2u
#define CY_IP_MXSCB_VERSION_MINOR       0u
#define CY_IP_MXSG                      1u
#define CY_IP_MXSG_INSTANCES            1u
#define CY_IP_MXSG_VERSION              1u
#define CY_IP_MXSG_VERSION_MINOR        0u
#define CY_IP_MXSMIF                    1u
#define CY_IP_MXSMIF_INSTANCES          1u
#define CY_IP_MXSMIF_VERSION            4u
#define CY_IP_MXSMIF_VERSION_MINOR      0u
#define CY_IP_MXS40SRSS                 1u
#define CY_IP_MXS40SRSS_INSTANCES       1u
#define CY_IP_MXS40SRSS_VERSION         3u
#define CY_IP_MXS40SRSS_VERSION_MINOR   3u
#define CY_IP_MXS40SRSS_RTC             1u
#define CY_IP_MXS40SRSS_RTC_INSTANCES   1u
#define CY_IP_MXS40SRSS_RTC_VERSION     3u
#define CY_IP_MXS40SRSS_RTC_VERSION_MINOR 3u
#define CY_IP_MXS40SRSS_MCWDT           1u
#define CY_IP_MXS40SRSS_MCWDT_INSTANCES 3u
#define CY_IP_MXS40SRSS_MCWDT_VERSION   3u
#define CY_IP_MXS40SRSS_MCWDT_VERSION_MINOR 3u
#define CY_IP_MXTCPWM                   1u
#define CY_IP_MXTCPWM_INSTANCES         1u
#define CY_IP_MXTCPWM_VERSION           2u
#define CY_IP_MXTCPWM_VERSION_MINOR     0u
#define CY_IP_MXTDM                     1u
#define CY_IP_MXTDM_INSTANCES           1u
#define CY_IP_MXTDM_VERSION             1u
#define CY_IP_MXTDM_VERSION_MINOR       0u

#define CY_DEVICE_TVIIC2D6M
#define CY_DEVICE_SERIES_CYT4DN
#define CY_SILICON_ID                   0xE8122206UL
#define CY_HF_CLK_MAX_FREQ              320000000UL

#define CPUSS_FLASHC_PA_SIZE_LOG2       0x7UL

#include "system_cat1c.h"

#include "tviic2d6m_config.h"
#include "gpio_tviic2d6m_327_bga.h"

/*******************************************************************************
*                                    SFLASH
*******************************************************************************/

#define SFLASH_BASE                             0x17000000UL
#define SFLASH                                  ((SFLASH_Type*) SFLASH_BASE)                                      /* 0x17000000 */

/*******************************************************************************
*                                     PERI
*******************************************************************************/

#define PERI_BASE                               0x40000000UL
#define PERI                                    ((PERI_Type*) PERI_BASE)                                          /* 0x40000000 */
#define PERI_GR0                                ((PERI_GR_Type*) &PERI->GR[0])                                    /* 0x40004000 */
#define PERI_GR1                                ((PERI_GR_Type*) &PERI->GR[1])                                    /* 0x40004040 */
#define PERI_GR2                                ((PERI_GR_Type*) &PERI->GR[2])                                    /* 0x40004080 */
#define PERI_GR3                                ((PERI_GR_Type*) &PERI->GR[3])                                    /* 0x400040C0 */
#define PERI_GR4                                ((PERI_GR_Type*) &PERI->GR[4])                                    /* 0x40004100 */
#define PERI_GR5                                ((PERI_GR_Type*) &PERI->GR[5])                                    /* 0x40004140 */
#define PERI_GR6                                ((PERI_GR_Type*) &PERI->GR[6])                                    /* 0x40004180 */
#define PERI_GR8                                ((PERI_GR_Type*) &PERI->GR[8])                                    /* 0x40004200 */
#define PERI_GR9                                ((PERI_GR_Type*) &PERI->GR[9])                                    /* 0x40004240 */
#define PERI_GR10                               ((PERI_GR_Type*) &PERI->GR[10])                                   /* 0x40004280 */
#define PERI_TR_GR0                             ((PERI_TR_GR_Type*) &PERI->TR_GR[0])                              /* 0x40008000 */
#define PERI_TR_GR1                             ((PERI_TR_GR_Type*) &PERI->TR_GR[1])                              /* 0x40008400 */
#define PERI_TR_GR2                             ((PERI_TR_GR_Type*) &PERI->TR_GR[2])                              /* 0x40008800 */
#define PERI_TR_GR3                             ((PERI_TR_GR_Type*) &PERI->TR_GR[3])                              /* 0x40008C00 */
#define PERI_TR_GR4                             ((PERI_TR_GR_Type*) &PERI->TR_GR[4])                              /* 0x40009000 */
#define PERI_TR_GR5                             ((PERI_TR_GR_Type*) &PERI->TR_GR[5])                              /* 0x40009400 */
#define PERI_TR_GR6                             ((PERI_TR_GR_Type*) &PERI->TR_GR[6])                              /* 0x40009800 */
#define PERI_TR_GR7                             ((PERI_TR_GR_Type*) &PERI->TR_GR[7])                              /* 0x40009C00 */
#define PERI_TR_GR8                             ((PERI_TR_GR_Type*) &PERI->TR_GR[8])                              /* 0x4000A000 */
#define PERI_TR_GR9                             ((PERI_TR_GR_Type*) &PERI->TR_GR[9])                              /* 0x4000A400 */
#define PERI_TR_GR10                            ((PERI_TR_GR_Type*) &PERI->TR_GR[10])                             /* 0x4000A800 */
#define PERI_TR_GR11                            ((PERI_TR_GR_Type*) &PERI->TR_GR[11])                             /* 0x4000AC00 */
#define PERI_TR_GR12                            ((PERI_TR_GR_Type*) &PERI->TR_GR[12])                             /* 0x4000B000 */
#define PERI_TR_GR13                            ((PERI_TR_GR_Type*) &PERI->TR_GR[13])                             /* 0x4000B400 */
#define PERI_TR_1TO1_GR0                        ((PERI_TR_1TO1_GR_Type*) &PERI->TR_1TO1_GR[0])                    /* 0x4000C000 */
#define PERI_TR_1TO1_GR1                        ((PERI_TR_1TO1_GR_Type*) &PERI->TR_1TO1_GR[1])                    /* 0x4000C400 */
#define PERI_TR_1TO1_GR2                        ((PERI_TR_1TO1_GR_Type*) &PERI->TR_1TO1_GR[2])                    /* 0x4000C800 */
#define PERI_TR_1TO1_GR3                        ((PERI_TR_1TO1_GR_Type*) &PERI->TR_1TO1_GR[3])                    /* 0x4000CC00 */
#define PERI_TR_1TO1_GR4                        ((PERI_TR_1TO1_GR_Type*) &PERI->TR_1TO1_GR[4])                    /* 0x4000D000 */
#define PERI_TR_1TO1_GR5                        ((PERI_TR_1TO1_GR_Type*) &PERI->TR_1TO1_GR[5])                    /* 0x4000D400 */
#define PERI_TR_1TO1_GR6                        ((PERI_TR_1TO1_GR_Type*) &PERI->TR_1TO1_GR[6])                    /* 0x4000D800 */
#define PERI_TR_1TO1_GR7                        ((PERI_TR_1TO1_GR_Type*) &PERI->TR_1TO1_GR[7])                    /* 0x4000DC00 */

/*******************************************************************************
*                                   PERI_MS
*******************************************************************************/

#define PERI_MS_BASE                            0x40020000UL
#define PERI_MS                                 ((PERI_MS_Type*) PERI_MS_BASE)                                    /* 0x40020000 */
#define PERI_MS_PPU_PR0                         ((PERI_MS_PPU_PR_Type*) &PERI_MS->PPU_PR[0])                      /* 0x40020000 */
#define PERI_MS_PPU_PR1                         ((PERI_MS_PPU_PR_Type*) &PERI_MS->PPU_PR[1])                      /* 0x40020040 */
#define PERI_MS_PPU_PR2                         ((PERI_MS_PPU_PR_Type*) &PERI_MS->PPU_PR[2])                      /* 0x40020080 */
#define PERI_MS_PPU_PR3                         ((PERI_MS_PPU_PR_Type*) &PERI_MS->PPU_PR[3])                      /* 0x400200C0 */
#define PERI_MS_PPU_PR4                         ((PERI_MS_PPU_PR_Type*) &PERI_MS->PPU_PR[4])                      /* 0x40020100 */
#define PERI_MS_PPU_PR5                         ((PERI_MS_PPU_PR_Type*) &PERI_MS->PPU_PR[5])                      /* 0x40020140 */
#define PERI_MS_PPU_PR6                         ((PERI_MS_PPU_PR_Type*) &PERI_MS->PPU_PR[6])                      /* 0x40020180 */
#define PERI_MS_PPU_PR7                         ((PERI_MS_PPU_PR_Type*) &PERI_MS->PPU_PR[7])                      /* 0x400201C0 */
#define PERI_MS_PPU_PR8                         ((PERI_MS_PPU_PR_Type*) &PERI_MS->PPU_PR[8])                      /* 0x40020200 */
#define PERI_MS_PPU_PR9                         ((PERI_MS_PPU_PR_Type*) &PERI_MS->PPU_PR[9])                      /* 0x40020240 */
#define PERI_MS_PPU_PR10                        ((PERI_MS_PPU_PR_Type*) &PERI_MS->PPU_PR[10])                     /* 0x40020280 */
#define PERI_MS_PPU_PR11                        ((PERI_MS_PPU_PR_Type*) &PERI_MS->PPU_PR[11])                     /* 0x400202C0 */
#define PERI_MS_PPU_PR12                        ((PERI_MS_PPU_PR_Type*) &PERI_MS->PPU_PR[12])                     /* 0x40020300 */
#define PERI_MS_PPU_PR13                        ((PERI_MS_PPU_PR_Type*) &PERI_MS->PPU_PR[13])                     /* 0x40020340 */
#define PERI_MS_PPU_PR14                        ((PERI_MS_PPU_PR_Type*) &PERI_MS->PPU_PR[14])                     /* 0x40020380 */
#define PERI_MS_PPU_PR15                        ((PERI_MS_PPU_PR_Type*) &PERI_MS->PPU_PR[15])                     /* 0x400203C0 */
#define PERI_MS_PPU_FX_PERI_MAIN                ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[0])                      /* 0x40020800 */
#define PERI_MS_PPU_FX_PERI_SECURE              ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[1])                      /* 0x40020840 */
#define PERI_MS_PPU_FX_PERI_GR0_GROUP           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[2])                      /* 0x40020880 */
#define PERI_MS_PPU_FX_PERI_GR1_GROUP           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[3])                      /* 0x400208C0 */
#define PERI_MS_PPU_FX_PERI_GR2_GROUP           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[4])                      /* 0x40020900 */
#define PERI_MS_PPU_FX_PERI_GR3_GROUP           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[5])                      /* 0x40020940 */
#define PERI_MS_PPU_FX_PERI_GR4_GROUP           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[6])                      /* 0x40020980 */
#define PERI_MS_PPU_FX_PERI_GR5_GROUP           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[7])                      /* 0x400209C0 */
#define PERI_MS_PPU_FX_PERI_GR6_GROUP           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[8])                      /* 0x40020A00 */
#define PERI_MS_PPU_FX_PERI_GR8_GROUP           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[9])                      /* 0x40020A40 */
#define PERI_MS_PPU_FX_PERI_GR9_GROUP           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[10])                     /* 0x40020A80 */
#define PERI_MS_PPU_FX_PERI_GR10_GROUP          ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[11])                     /* 0x40020AC0 */
#define PERI_MS_PPU_FX_PERI_GR0_BOOT            ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[12])                     /* 0x40020B00 */
#define PERI_MS_PPU_FX_PERI_GR1_BOOT            ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[13])                     /* 0x40020B40 */
#define PERI_MS_PPU_FX_PERI_GR2_BOOT            ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[14])                     /* 0x40020B80 */
#define PERI_MS_PPU_FX_PERI_GR3_BOOT            ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[15])                     /* 0x40020BC0 */
#define PERI_MS_PPU_FX_PERI_GR4_BOOT            ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[16])                     /* 0x40020C00 */
#define PERI_MS_PPU_FX_PERI_GR5_BOOT            ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[17])                     /* 0x40020C40 */
#define PERI_MS_PPU_FX_PERI_GR6_BOOT            ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[18])                     /* 0x40020C80 */
#define PERI_MS_PPU_FX_PERI_GR8_BOOT            ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[19])                     /* 0x40020CC0 */
#define PERI_MS_PPU_FX_PERI_GR9_BOOT            ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[20])                     /* 0x40020D00 */
#define PERI_MS_PPU_FX_PERI_GR10_BOOT           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[21])                     /* 0x40020D40 */
#define PERI_MS_PPU_FX_PERI_TR                  ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[22])                     /* 0x40020D80 */
#define PERI_MS_PPU_FX_PERI_MS_BOOT             ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[23])                     /* 0x40020DC0 */
#define PERI_MS_PPU_FX_PERI_PCLK_MAIN           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[24])                     /* 0x40020E00 */
#define PERI_MS_PPU_FX_CRYPTO_MAIN              ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[25])                     /* 0x40020E40 */
#define PERI_MS_PPU_FX_CRYPTO_CRYPTO            ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[26])                     /* 0x40020E80 */
#define PERI_MS_PPU_FX_CRYPTO_BOOT              ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[27])                     /* 0x40020EC0 */
#define PERI_MS_PPU_FX_CRYPTO_KEY0              ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[28])                     /* 0x40020F00 */
#define PERI_MS_PPU_FX_CRYPTO_KEY1              ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[29])                     /* 0x40020F40 */
#define PERI_MS_PPU_FX_CRYPTO_BUF               ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[30])                     /* 0x40020F80 */
#define PERI_MS_PPU_FX_CPUSS_CM7_0              ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[31])                     /* 0x40020FC0 */
#define PERI_MS_PPU_FX_CPUSS_CM7_1              ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[32])                     /* 0x40021000 */
#define PERI_MS_PPU_FX_CPUSS_CM0                ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[33])                     /* 0x40021040 */
#define PERI_MS_PPU_FX_CPUSS_BOOT               ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[34])                     /* 0x40021080 */
#define PERI_MS_PPU_FX_CPUSS_CM0_INT            ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[35])                     /* 0x400210C0 */
#define PERI_MS_PPU_FX_CPUSS_CM7_0_INT          ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[36])                     /* 0x40021100 */
#define PERI_MS_PPU_FX_CPUSS_CM7_1_INT          ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[37])                     /* 0x40021140 */
#define PERI_MS_PPU_FX_FAULT_STRUCT0_MAIN       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[38])                     /* 0x40021180 */
#define PERI_MS_PPU_FX_FAULT_STRUCT1_MAIN       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[39])                     /* 0x400211C0 */
#define PERI_MS_PPU_FX_FAULT_STRUCT2_MAIN       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[40])                     /* 0x40021200 */
#define PERI_MS_PPU_FX_FAULT_STRUCT3_MAIN       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[41])                     /* 0x40021240 */
#define PERI_MS_PPU_FX_IPC_STRUCT0_IPC          ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[42])                     /* 0x40021280 */
#define PERI_MS_PPU_FX_IPC_STRUCT1_IPC          ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[43])                     /* 0x400212C0 */
#define PERI_MS_PPU_FX_IPC_STRUCT2_IPC          ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[44])                     /* 0x40021300 */
#define PERI_MS_PPU_FX_IPC_STRUCT3_IPC          ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[45])                     /* 0x40021340 */
#define PERI_MS_PPU_FX_IPC_STRUCT4_IPC          ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[46])                     /* 0x40021380 */
#define PERI_MS_PPU_FX_IPC_STRUCT5_IPC          ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[47])                     /* 0x400213C0 */
#define PERI_MS_PPU_FX_IPC_STRUCT6_IPC          ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[48])                     /* 0x40021400 */
#define PERI_MS_PPU_FX_IPC_STRUCT7_IPC          ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[49])                     /* 0x40021440 */
#define PERI_MS_PPU_FX_IPC_INTR_STRUCT0_INTR    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[50])                     /* 0x40021480 */
#define PERI_MS_PPU_FX_IPC_INTR_STRUCT1_INTR    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[51])                     /* 0x400214C0 */
#define PERI_MS_PPU_FX_IPC_INTR_STRUCT2_INTR    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[52])                     /* 0x40021500 */
#define PERI_MS_PPU_FX_IPC_INTR_STRUCT3_INTR    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[53])                     /* 0x40021540 */
#define PERI_MS_PPU_FX_IPC_INTR_STRUCT4_INTR    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[54])                     /* 0x40021580 */
#define PERI_MS_PPU_FX_IPC_INTR_STRUCT5_INTR    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[55])                     /* 0x400215C0 */
#define PERI_MS_PPU_FX_IPC_INTR_STRUCT6_INTR    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[56])                     /* 0x40021600 */
#define PERI_MS_PPU_FX_IPC_INTR_STRUCT7_INTR    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[57])                     /* 0x40021640 */
#define PERI_MS_PPU_FX_PROT_SMPU_MAIN           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[58])                     /* 0x40021680 */
#define PERI_MS_PPU_FX_PROT_MPU0_MAIN           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[59])                     /* 0x400216C0 */
#define PERI_MS_PPU_FX_PROT_MPU9_MAIN           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[60])                     /* 0x40021700 */
#define PERI_MS_PPU_FX_PROT_MPU10_MAIN          ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[61])                     /* 0x40021740 */
#define PERI_MS_PPU_FX_PROT_MPU11_MAIN          ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[62])                     /* 0x40021780 */
#define PERI_MS_PPU_FX_PROT_MPU12_MAIN          ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[63])                     /* 0x400217C0 */
#define PERI_MS_PPU_FX_PROT_MPU13_MAIN          ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[64])                     /* 0x40021800 */
#define PERI_MS_PPU_FX_PROT_MPU14_MAIN          ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[65])                     /* 0x40021840 */
#define PERI_MS_PPU_FX_PROT_MPU15_MAIN          ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[66])                     /* 0x40021880 */
#define PERI_MS_PPU_FX_FLASHC_MAIN              ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[67])                     /* 0x400218C0 */
#define PERI_MS_PPU_FX_FLASHC_CMD               ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[68])                     /* 0x40021900 */
#define PERI_MS_PPU_FX_FLASHC_DFT               ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[69])                     /* 0x40021940 */
#define PERI_MS_PPU_FX_FLASHC_CM0               ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[70])                     /* 0x40021980 */
#define PERI_MS_PPU_FX_FLASHC_CM7_0             ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[71])                     /* 0x400219C0 */
#define PERI_MS_PPU_FX_FLASHC_CM7_1             ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[72])                     /* 0x40021A00 */
#define PERI_MS_PPU_FX_FLASHC_CRYPTO            ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[73])                     /* 0x40021A40 */
#define PERI_MS_PPU_FX_FLASHC_DW0               ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[74])                     /* 0x40021A80 */
#define PERI_MS_PPU_FX_FLASHC_DW1               ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[75])                     /* 0x40021AC0 */
#define PERI_MS_PPU_FX_FLASHC_DMAC              ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[76])                     /* 0x40021B00 */
#define PERI_MS_PPU_FX_FLASHC_FlashMgmt         ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[77])                     /* 0x40021B40 */
#define PERI_MS_PPU_FX_FLASHC_MainSafety        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[78])                     /* 0x40021B80 */
#define PERI_MS_PPU_FX_FLASHC_WorkSafety        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[79])                     /* 0x40021BC0 */
#define PERI_MS_PPU_FX_SRSS_GENERAL             ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[80])                     /* 0x40021C00 */
#define PERI_MS_PPU_FX_SRSS_MAIN                ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[81])                     /* 0x40021C40 */
#define PERI_MS_PPU_FX_SRSS_SECURE              ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[82])                     /* 0x40021C80 */
#define PERI_MS_PPU_FX_MCWDT0_CONFIG            ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[83])                     /* 0x40021CC0 */
#define PERI_MS_PPU_FX_MCWDT1_CONFIG            ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[84])                     /* 0x40021D00 */
#define PERI_MS_PPU_FX_MCWDT2_CONFIG            ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[85])                     /* 0x40021D40 */
#define PERI_MS_PPU_FX_MCWDT0_MAIN              ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[86])                     /* 0x40021D80 */
#define PERI_MS_PPU_FX_MCWDT1_MAIN              ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[87])                     /* 0x40021DC0 */
#define PERI_MS_PPU_FX_MCWDT2_MAIN              ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[88])                     /* 0x40021E00 */
#define PERI_MS_PPU_FX_WDT_CONFIG               ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[89])                     /* 0x40021E40 */
#define PERI_MS_PPU_FX_WDT_MAIN                 ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[90])                     /* 0x40021E80 */
#define PERI_MS_PPU_FX_BACKUP_BACKUP            ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[91])                     /* 0x40021EC0 */
#define PERI_MS_PPU_FX_DW0_DW                   ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[92])                     /* 0x40021F00 */
#define PERI_MS_PPU_FX_DW1_DW                   ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[93])                     /* 0x40021F40 */
#define PERI_MS_PPU_FX_DW0_DW_CRC               ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[94])                     /* 0x40021F80 */
#define PERI_MS_PPU_FX_DW1_DW_CRC               ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[95])                     /* 0x40021FC0 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT0_CH        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[96])                     /* 0x40022000 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT1_CH        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[97])                     /* 0x40022040 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT2_CH        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[98])                     /* 0x40022080 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT3_CH        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[99])                     /* 0x400220C0 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT4_CH        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[100])                    /* 0x40022100 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT5_CH        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[101])                    /* 0x40022140 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT6_CH        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[102])                    /* 0x40022180 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT7_CH        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[103])                    /* 0x400221C0 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT8_CH        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[104])                    /* 0x40022200 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT9_CH        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[105])                    /* 0x40022240 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT10_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[106])                    /* 0x40022280 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT11_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[107])                    /* 0x400222C0 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT12_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[108])                    /* 0x40022300 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT13_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[109])                    /* 0x40022340 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT14_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[110])                    /* 0x40022380 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT15_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[111])                    /* 0x400223C0 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT16_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[112])                    /* 0x40022400 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT17_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[113])                    /* 0x40022440 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT18_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[114])                    /* 0x40022480 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT19_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[115])                    /* 0x400224C0 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT20_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[116])                    /* 0x40022500 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT21_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[117])                    /* 0x40022540 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT22_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[118])                    /* 0x40022580 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT23_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[119])                    /* 0x400225C0 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT24_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[120])                    /* 0x40022600 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT25_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[121])                    /* 0x40022640 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT26_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[122])                    /* 0x40022680 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT27_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[123])                    /* 0x400226C0 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT28_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[124])                    /* 0x40022700 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT29_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[125])                    /* 0x40022740 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT30_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[126])                    /* 0x40022780 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT31_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[127])                    /* 0x400227C0 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT32_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[128])                    /* 0x40022800 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT33_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[129])                    /* 0x40022840 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT34_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[130])                    /* 0x40022880 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT35_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[131])                    /* 0x400228C0 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT36_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[132])                    /* 0x40022900 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT37_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[133])                    /* 0x40022940 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT38_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[134])                    /* 0x40022980 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT39_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[135])                    /* 0x400229C0 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT40_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[136])                    /* 0x40022A00 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT41_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[137])                    /* 0x40022A40 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT42_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[138])                    /* 0x40022A80 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT43_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[139])                    /* 0x40022AC0 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT44_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[140])                    /* 0x40022B00 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT45_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[141])                    /* 0x40022B40 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT46_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[142])                    /* 0x40022B80 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT47_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[143])                    /* 0x40022BC0 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT48_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[144])                    /* 0x40022C00 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT49_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[145])                    /* 0x40022C40 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT50_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[146])                    /* 0x40022C80 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT51_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[147])                    /* 0x40022CC0 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT52_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[148])                    /* 0x40022D00 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT53_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[149])                    /* 0x40022D40 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT54_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[150])                    /* 0x40022D80 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT55_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[151])                    /* 0x40022DC0 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT56_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[152])                    /* 0x40022E00 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT57_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[153])                    /* 0x40022E40 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT58_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[154])                    /* 0x40022E80 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT59_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[155])                    /* 0x40022EC0 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT60_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[156])                    /* 0x40022F00 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT61_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[157])                    /* 0x40022F40 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT62_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[158])                    /* 0x40022F80 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT63_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[159])                    /* 0x40022FC0 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT64_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[160])                    /* 0x40023000 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT65_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[161])                    /* 0x40023040 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT66_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[162])                    /* 0x40023080 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT67_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[163])                    /* 0x400230C0 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT68_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[164])                    /* 0x40023100 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT69_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[165])                    /* 0x40023140 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT70_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[166])                    /* 0x40023180 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT71_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[167])                    /* 0x400231C0 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT72_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[168])                    /* 0x40023200 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT73_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[169])                    /* 0x40023240 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT74_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[170])                    /* 0x40023280 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT75_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[171])                    /* 0x400232C0 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT0_CH        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[172])                    /* 0x40023300 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT1_CH        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[173])                    /* 0x40023340 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT2_CH        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[174])                    /* 0x40023380 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT3_CH        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[175])                    /* 0x400233C0 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT4_CH        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[176])                    /* 0x40023400 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT5_CH        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[177])                    /* 0x40023440 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT6_CH        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[178])                    /* 0x40023480 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT7_CH        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[179])                    /* 0x400234C0 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT8_CH        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[180])                    /* 0x40023500 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT9_CH        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[181])                    /* 0x40023540 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT10_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[182])                    /* 0x40023580 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT11_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[183])                    /* 0x400235C0 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT12_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[184])                    /* 0x40023600 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT13_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[185])                    /* 0x40023640 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT14_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[186])                    /* 0x40023680 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT15_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[187])                    /* 0x400236C0 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT16_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[188])                    /* 0x40023700 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT17_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[189])                    /* 0x40023740 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT18_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[190])                    /* 0x40023780 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT19_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[191])                    /* 0x400237C0 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT20_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[192])                    /* 0x40023800 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT21_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[193])                    /* 0x40023840 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT22_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[194])                    /* 0x40023880 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT23_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[195])                    /* 0x400238C0 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT24_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[196])                    /* 0x40023900 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT25_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[197])                    /* 0x40023940 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT26_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[198])                    /* 0x40023980 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT27_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[199])                    /* 0x400239C0 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT28_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[200])                    /* 0x40023A00 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT29_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[201])                    /* 0x40023A40 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT30_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[202])                    /* 0x40023A80 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT31_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[203])                    /* 0x40023AC0 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT32_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[204])                    /* 0x40023B00 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT33_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[205])                    /* 0x40023B40 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT34_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[206])                    /* 0x40023B80 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT35_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[207])                    /* 0x40023BC0 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT36_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[208])                    /* 0x40023C00 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT37_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[209])                    /* 0x40023C40 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT38_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[210])                    /* 0x40023C80 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT39_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[211])                    /* 0x40023CC0 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT40_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[212])                    /* 0x40023D00 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT41_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[213])                    /* 0x40023D40 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT42_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[214])                    /* 0x40023D80 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT43_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[215])                    /* 0x40023DC0 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT44_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[216])                    /* 0x40023E00 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT45_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[217])                    /* 0x40023E40 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT46_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[218])                    /* 0x40023E80 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT47_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[219])                    /* 0x40023EC0 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT48_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[220])                    /* 0x40023F00 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT49_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[221])                    /* 0x40023F40 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT50_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[222])                    /* 0x40023F80 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT51_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[223])                    /* 0x40023FC0 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT52_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[224])                    /* 0x40024000 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT53_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[225])                    /* 0x40024040 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT54_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[226])                    /* 0x40024080 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT55_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[227])                    /* 0x400240C0 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT56_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[228])                    /* 0x40024100 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT57_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[229])                    /* 0x40024140 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT58_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[230])                    /* 0x40024180 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT59_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[231])                    /* 0x400241C0 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT60_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[232])                    /* 0x40024200 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT61_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[233])                    /* 0x40024240 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT62_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[234])                    /* 0x40024280 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT63_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[235])                    /* 0x400242C0 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT64_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[236])                    /* 0x40024300 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT65_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[237])                    /* 0x40024340 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT66_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[238])                    /* 0x40024380 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT67_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[239])                    /* 0x400243C0 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT68_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[240])                    /* 0x40024400 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT69_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[241])                    /* 0x40024440 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT70_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[242])                    /* 0x40024480 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT71_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[243])                    /* 0x400244C0 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT72_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[244])                    /* 0x40024500 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT73_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[245])                    /* 0x40024540 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT74_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[246])                    /* 0x40024580 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT75_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[247])                    /* 0x400245C0 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT76_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[248])                    /* 0x40024600 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT77_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[249])                    /* 0x40024640 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT78_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[250])                    /* 0x40024680 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT79_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[251])                    /* 0x400246C0 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT80_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[252])                    /* 0x40024700 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT81_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[253])                    /* 0x40024740 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT82_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[254])                    /* 0x40024780 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT83_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[255])                    /* 0x400247C0 */
#define PERI_MS_PPU_FX_DMAC_TOP                 ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[256])                    /* 0x40024800 */
#define PERI_MS_PPU_FX_DMAC_CH0_CH              ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[257])                    /* 0x40024840 */
#define PERI_MS_PPU_FX_DMAC_CH1_CH              ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[258])                    /* 0x40024880 */
#define PERI_MS_PPU_FX_DMAC_CH2_CH              ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[259])                    /* 0x400248C0 */
#define PERI_MS_PPU_FX_DMAC_CH3_CH              ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[260])                    /* 0x40024900 */
#define PERI_MS_PPU_FX_DMAC_CH4_CH              ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[261])                    /* 0x40024940 */
#define PERI_MS_PPU_FX_DMAC_CH5_CH              ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[262])                    /* 0x40024980 */
#define PERI_MS_PPU_FX_DMAC_CH6_CH              ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[263])                    /* 0x400249C0 */
#define PERI_MS_PPU_FX_DMAC_CH7_CH              ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[264])                    /* 0x40024A00 */
#define PERI_MS_PPU_FX_AXI_DMAC_TOP             ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[265])                    /* 0x40024A40 */
#define PERI_MS_PPU_FX_AXI_DMAC_SEC             ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[266])                    /* 0x40024A80 */
#define PERI_MS_PPU_FX_AXI_DMAC_NONSEC          ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[267])                    /* 0x40024AC0 */
#define PERI_MS_PPU_FX_AXI_DMAC_CH0_CH          ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[268])                    /* 0x40024B00 */
#define PERI_MS_PPU_FX_AXI_DMAC_CH1_CH          ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[269])                    /* 0x40024B40 */
#define PERI_MS_PPU_FX_AXI_DMAC_CH2_CH          ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[270])                    /* 0x40024B80 */
#define PERI_MS_PPU_FX_AXI_DMAC_CH3_CH          ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[271])                    /* 0x40024BC0 */
#define PERI_MS_PPU_FX_EFUSE_CTL                ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[272])                    /* 0x40024C00 */
#define PERI_MS_PPU_FX_EFUSE_DATA               ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[273])                    /* 0x40024C40 */
#define PERI_MS_PPU_FX_DFT                      ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[274])                    /* 0x40024C80 */
#define PERI_MS_PPU_FX_HSIOM_PRT0_PRT           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[275])                    /* 0x40024CC0 */
#define PERI_MS_PPU_FX_HSIOM_PRT1_PRT           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[276])                    /* 0x40024D00 */
#define PERI_MS_PPU_FX_HSIOM_PRT2_PRT           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[277])                    /* 0x40024D40 */
#define PERI_MS_PPU_FX_HSIOM_PRT3_PRT           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[278])                    /* 0x40024D80 */
#define PERI_MS_PPU_FX_HSIOM_PRT4_PRT           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[279])                    /* 0x40024DC0 */
#define PERI_MS_PPU_FX_HSIOM_PRT5_PRT           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[280])                    /* 0x40024E00 */
#define PERI_MS_PPU_FX_HSIOM_PRT6_PRT           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[281])                    /* 0x40024E40 */
#define PERI_MS_PPU_FX_HSIOM_PRT7_PRT           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[282])                    /* 0x40024E80 */
#define PERI_MS_PPU_FX_HSIOM_PRT8_PRT           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[283])                    /* 0x40024EC0 */
#define PERI_MS_PPU_FX_HSIOM_PRT9_PRT           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[284])                    /* 0x40024F00 */
#define PERI_MS_PPU_FX_HSIOM_PRT10_PRT          ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[285])                    /* 0x40024F40 */
#define PERI_MS_PPU_FX_HSIOM_PRT11_PRT          ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[286])                    /* 0x40024F80 */
#define PERI_MS_PPU_FX_HSIOM_PRT12_PRT          ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[287])                    /* 0x40024FC0 */
#define PERI_MS_PPU_FX_HSIOM_PRT13_PRT          ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[288])                    /* 0x40025000 */
#define PERI_MS_PPU_FX_HSIOM_PRT14_PRT          ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[289])                    /* 0x40025040 */
#define PERI_MS_PPU_FX_HSIOM_PRT15_PRT          ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[290])                    /* 0x40025080 */
#define PERI_MS_PPU_FX_HSIOM_PRT16_PRT          ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[291])                    /* 0x400250C0 */
#define PERI_MS_PPU_FX_HSIOM_PRT17_PRT          ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[292])                    /* 0x40025100 */
#define PERI_MS_PPU_FX_HSIOM_PRT18_PRT          ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[293])                    /* 0x40025140 */
#define PERI_MS_PPU_FX_HSIOM_PRT19_PRT          ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[294])                    /* 0x40025180 */
#define PERI_MS_PPU_FX_HSIOM_PRT20_PRT          ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[295])                    /* 0x400251C0 */
#define PERI_MS_PPU_FX_HSIOM_PRT21_PRT          ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[296])                    /* 0x40025200 */
#define PERI_MS_PPU_FX_HSIOM_PRT22_PRT          ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[297])                    /* 0x40025240 */
#define PERI_MS_PPU_FX_HSIOM_PRT23_PRT          ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[298])                    /* 0x40025280 */
#define PERI_MS_PPU_FX_HSIOM_PRT24_PRT          ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[299])                    /* 0x400252C0 */
#define PERI_MS_PPU_FX_HSIOM_PRT25_PRT          ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[300])                    /* 0x40025300 */
#define PERI_MS_PPU_FX_HSIOM_PRT26_PRT          ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[301])                    /* 0x40025340 */
#define PERI_MS_PPU_FX_HSIOM_PRT27_PRT          ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[302])                    /* 0x40025380 */
#define PERI_MS_PPU_FX_HSIOM_PRT28_PRT          ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[303])                    /* 0x400253C0 */
#define PERI_MS_PPU_FX_HSIOM_PRT29_PRT          ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[304])                    /* 0x40025400 */
#define PERI_MS_PPU_FX_HSIOM_PRT30_PRT          ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[305])                    /* 0x40025440 */
#define PERI_MS_PPU_FX_HSIOM_AMUX               ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[306])                    /* 0x40025480 */
#define PERI_MS_PPU_FX_HSIOM_MON                ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[307])                    /* 0x400254C0 */
#define PERI_MS_PPU_FX_GPIO_PRT0_PRT            ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[308])                    /* 0x40025500 */
#define PERI_MS_PPU_FX_GPIO_PRT1_PRT            ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[309])                    /* 0x40025540 */
#define PERI_MS_PPU_FX_GPIO_PRT2_PRT            ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[310])                    /* 0x40025580 */
#define PERI_MS_PPU_FX_GPIO_PRT3_PRT            ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[311])                    /* 0x400255C0 */
#define PERI_MS_PPU_FX_GPIO_PRT4_PRT            ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[312])                    /* 0x40025600 */
#define PERI_MS_PPU_FX_GPIO_PRT5_PRT            ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[313])                    /* 0x40025640 */
#define PERI_MS_PPU_FX_GPIO_PRT6_PRT            ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[314])                    /* 0x40025680 */
#define PERI_MS_PPU_FX_GPIO_PRT7_PRT            ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[315])                    /* 0x400256C0 */
#define PERI_MS_PPU_FX_GPIO_PRT8_PRT            ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[316])                    /* 0x40025700 */
#define PERI_MS_PPU_FX_GPIO_PRT9_PRT            ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[317])                    /* 0x40025740 */
#define PERI_MS_PPU_FX_GPIO_PRT10_PRT           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[318])                    /* 0x40025780 */
#define PERI_MS_PPU_FX_GPIO_PRT11_PRT           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[319])                    /* 0x400257C0 */
#define PERI_MS_PPU_FX_GPIO_PRT12_PRT           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[320])                    /* 0x40025800 */
#define PERI_MS_PPU_FX_GPIO_PRT13_PRT           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[321])                    /* 0x40025840 */
#define PERI_MS_PPU_FX_GPIO_PRT14_PRT           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[322])                    /* 0x40025880 */
#define PERI_MS_PPU_FX_GPIO_PRT15_PRT           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[323])                    /* 0x400258C0 */
#define PERI_MS_PPU_FX_GPIO_PRT16_PRT           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[324])                    /* 0x40025900 */
#define PERI_MS_PPU_FX_GPIO_PRT17_PRT           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[325])                    /* 0x40025940 */
#define PERI_MS_PPU_FX_GPIO_PRT18_PRT           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[326])                    /* 0x40025980 */
#define PERI_MS_PPU_FX_GPIO_PRT19_PRT           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[327])                    /* 0x400259C0 */
#define PERI_MS_PPU_FX_GPIO_PRT20_PRT           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[328])                    /* 0x40025A00 */
#define PERI_MS_PPU_FX_GPIO_PRT21_PRT           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[329])                    /* 0x40025A40 */
#define PERI_MS_PPU_FX_GPIO_PRT22_PRT           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[330])                    /* 0x40025A80 */
#define PERI_MS_PPU_FX_GPIO_PRT23_PRT           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[331])                    /* 0x40025AC0 */
#define PERI_MS_PPU_FX_GPIO_PRT24_PRT           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[332])                    /* 0x40025B00 */
#define PERI_MS_PPU_FX_GPIO_PRT25_PRT           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[333])                    /* 0x40025B40 */
#define PERI_MS_PPU_FX_GPIO_PRT26_PRT           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[334])                    /* 0x40025B80 */
#define PERI_MS_PPU_FX_GPIO_PRT27_PRT           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[335])                    /* 0x40025BC0 */
#define PERI_MS_PPU_FX_GPIO_PRT28_PRT           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[336])                    /* 0x40025C00 */
#define PERI_MS_PPU_FX_GPIO_PRT29_PRT           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[337])                    /* 0x40025C40 */
#define PERI_MS_PPU_FX_GPIO_PRT30_PRT           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[338])                    /* 0x40025C80 */
#define PERI_MS_PPU_FX_GPIO_PRT0_CFG            ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[339])                    /* 0x40025CC0 */
#define PERI_MS_PPU_FX_GPIO_PRT1_CFG            ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[340])                    /* 0x40025D00 */
#define PERI_MS_PPU_FX_GPIO_PRT2_CFG            ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[341])                    /* 0x40025D40 */
#define PERI_MS_PPU_FX_GPIO_PRT3_CFG            ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[342])                    /* 0x40025D80 */
#define PERI_MS_PPU_FX_GPIO_PRT4_CFG            ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[343])                    /* 0x40025DC0 */
#define PERI_MS_PPU_FX_GPIO_PRT5_CFG            ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[344])                    /* 0x40025E00 */
#define PERI_MS_PPU_FX_GPIO_PRT6_CFG            ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[345])                    /* 0x40025E40 */
#define PERI_MS_PPU_FX_GPIO_PRT7_CFG            ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[346])                    /* 0x40025E80 */
#define PERI_MS_PPU_FX_GPIO_PRT8_CFG            ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[347])                    /* 0x40025EC0 */
#define PERI_MS_PPU_FX_GPIO_PRT9_CFG            ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[348])                    /* 0x40025F00 */
#define PERI_MS_PPU_FX_GPIO_PRT10_CFG           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[349])                    /* 0x40025F40 */
#define PERI_MS_PPU_FX_GPIO_PRT11_CFG           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[350])                    /* 0x40025F80 */
#define PERI_MS_PPU_FX_GPIO_PRT12_CFG           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[351])                    /* 0x40025FC0 */
#define PERI_MS_PPU_FX_GPIO_PRT13_CFG           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[352])                    /* 0x40026000 */
#define PERI_MS_PPU_FX_GPIO_PRT14_CFG           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[353])                    /* 0x40026040 */
#define PERI_MS_PPU_FX_GPIO_PRT15_CFG           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[354])                    /* 0x40026080 */
#define PERI_MS_PPU_FX_GPIO_PRT16_CFG           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[355])                    /* 0x400260C0 */
#define PERI_MS_PPU_FX_GPIO_PRT17_CFG           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[356])                    /* 0x40026100 */
#define PERI_MS_PPU_FX_GPIO_PRT18_CFG           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[357])                    /* 0x40026140 */
#define PERI_MS_PPU_FX_GPIO_PRT19_CFG           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[358])                    /* 0x40026180 */
#define PERI_MS_PPU_FX_GPIO_PRT20_CFG           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[359])                    /* 0x400261C0 */
#define PERI_MS_PPU_FX_GPIO_PRT21_CFG           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[360])                    /* 0x40026200 */
#define PERI_MS_PPU_FX_GPIO_PRT22_CFG           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[361])                    /* 0x40026240 */
#define PERI_MS_PPU_FX_GPIO_PRT23_CFG           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[362])                    /* 0x40026280 */
#define PERI_MS_PPU_FX_GPIO_PRT24_CFG           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[363])                    /* 0x400262C0 */
#define PERI_MS_PPU_FX_GPIO_PRT25_CFG           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[364])                    /* 0x40026300 */
#define PERI_MS_PPU_FX_GPIO_PRT26_CFG           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[365])                    /* 0x40026340 */
#define PERI_MS_PPU_FX_GPIO_PRT27_CFG           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[366])                    /* 0x40026380 */
#define PERI_MS_PPU_FX_GPIO_PRT28_CFG           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[367])                    /* 0x400263C0 */
#define PERI_MS_PPU_FX_GPIO_PRT29_CFG           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[368])                    /* 0x40026400 */
#define PERI_MS_PPU_FX_GPIO_PRT30_CFG           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[369])                    /* 0x40026440 */
#define PERI_MS_PPU_FX_GPIO_GPIO                ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[370])                    /* 0x40026480 */
#define PERI_MS_PPU_FX_GPIO_TEST                ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[371])                    /* 0x400264C0 */
#define PERI_MS_PPU_FX_SMARTIO_PRT7_PRT         ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[372])                    /* 0x40026500 */
#define PERI_MS_PPU_FX_TCPWM0_GRP0_CNT0_CNT     ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[373])                    /* 0x40026540 */
#define PERI_MS_PPU_FX_TCPWM0_GRP0_CNT1_CNT     ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[374])                    /* 0x40026580 */
#define PERI_MS_PPU_FX_TCPWM0_GRP0_CNT2_CNT     ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[375])                    /* 0x400265C0 */
#define PERI_MS_PPU_FX_TCPWM0_GRP0_CNT3_CNT     ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[376])                    /* 0x40026600 */
#define PERI_MS_PPU_FX_TCPWM0_GRP0_CNT4_CNT     ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[377])                    /* 0x40026640 */
#define PERI_MS_PPU_FX_TCPWM0_GRP0_CNT5_CNT     ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[378])                    /* 0x40026680 */
#define PERI_MS_PPU_FX_TCPWM0_GRP0_CNT6_CNT     ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[379])                    /* 0x400266C0 */
#define PERI_MS_PPU_FX_TCPWM0_GRP0_CNT7_CNT     ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[380])                    /* 0x40026700 */
#define PERI_MS_PPU_FX_TCPWM0_GRP0_CNT8_CNT     ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[381])                    /* 0x40026740 */
#define PERI_MS_PPU_FX_TCPWM0_GRP0_CNT9_CNT     ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[382])                    /* 0x40026780 */
#define PERI_MS_PPU_FX_TCPWM0_GRP0_CNT10_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[383])                    /* 0x400267C0 */
#define PERI_MS_PPU_FX_TCPWM0_GRP0_CNT11_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[384])                    /* 0x40026800 */
#define PERI_MS_PPU_FX_TCPWM0_GRP0_CNT12_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[385])                    /* 0x40026840 */
#define PERI_MS_PPU_FX_TCPWM0_GRP0_CNT13_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[386])                    /* 0x40026880 */
#define PERI_MS_PPU_FX_TCPWM0_GRP0_CNT14_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[387])                    /* 0x400268C0 */
#define PERI_MS_PPU_FX_TCPWM0_GRP0_CNT15_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[388])                    /* 0x40026900 */
#define PERI_MS_PPU_FX_TCPWM0_GRP0_CNT16_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[389])                    /* 0x40026940 */
#define PERI_MS_PPU_FX_TCPWM0_GRP0_CNT17_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[390])                    /* 0x40026980 */
#define PERI_MS_PPU_FX_TCPWM0_GRP0_CNT18_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[391])                    /* 0x400269C0 */
#define PERI_MS_PPU_FX_TCPWM0_GRP0_CNT19_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[392])                    /* 0x40026A00 */
#define PERI_MS_PPU_FX_TCPWM0_GRP0_CNT20_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[393])                    /* 0x40026A40 */
#define PERI_MS_PPU_FX_TCPWM0_GRP0_CNT21_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[394])                    /* 0x40026A80 */
#define PERI_MS_PPU_FX_TCPWM0_GRP0_CNT22_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[395])                    /* 0x40026AC0 */
#define PERI_MS_PPU_FX_TCPWM0_GRP0_CNT23_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[396])                    /* 0x40026B00 */
#define PERI_MS_PPU_FX_TCPWM0_GRP0_CNT24_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[397])                    /* 0x40026B40 */
#define PERI_MS_PPU_FX_TCPWM0_GRP0_CNT25_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[398])                    /* 0x40026B80 */
#define PERI_MS_PPU_FX_TCPWM0_GRP0_CNT26_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[399])                    /* 0x40026BC0 */
#define PERI_MS_PPU_FX_TCPWM0_GRP0_CNT27_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[400])                    /* 0x40026C00 */
#define PERI_MS_PPU_FX_TCPWM0_GRP0_CNT28_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[401])                    /* 0x40026C40 */
#define PERI_MS_PPU_FX_TCPWM0_GRP0_CNT29_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[402])                    /* 0x40026C80 */
#define PERI_MS_PPU_FX_TCPWM0_GRP0_CNT30_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[403])                    /* 0x40026CC0 */
#define PERI_MS_PPU_FX_TCPWM0_GRP0_CNT31_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[404])                    /* 0x40026D00 */
#define PERI_MS_PPU_FX_TCPWM0_GRP0_CNT32_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[405])                    /* 0x40026D40 */
#define PERI_MS_PPU_FX_TCPWM0_GRP0_CNT33_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[406])                    /* 0x40026D80 */
#define PERI_MS_PPU_FX_TCPWM0_GRP0_CNT34_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[407])                    /* 0x40026DC0 */
#define PERI_MS_PPU_FX_TCPWM0_GRP0_CNT35_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[408])                    /* 0x40026E00 */
#define PERI_MS_PPU_FX_TCPWM0_GRP0_CNT36_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[409])                    /* 0x40026E40 */
#define PERI_MS_PPU_FX_TCPWM0_GRP0_CNT37_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[410])                    /* 0x40026E80 */
#define PERI_MS_PPU_FX_TCPWM0_GRP1_CNT0_CNT     ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[411])                    /* 0x40026EC0 */
#define PERI_MS_PPU_FX_TCPWM0_GRP1_CNT1_CNT     ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[412])                    /* 0x40026F00 */
#define PERI_MS_PPU_FX_TCPWM0_GRP1_CNT2_CNT     ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[413])                    /* 0x40026F40 */
#define PERI_MS_PPU_FX_TCPWM0_GRP1_CNT3_CNT     ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[414])                    /* 0x40026F80 */
#define PERI_MS_PPU_FX_TCPWM0_GRP1_CNT4_CNT     ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[415])                    /* 0x40026FC0 */
#define PERI_MS_PPU_FX_TCPWM0_GRP1_CNT5_CNT     ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[416])                    /* 0x40027000 */
#define PERI_MS_PPU_FX_TCPWM0_GRP1_CNT6_CNT     ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[417])                    /* 0x40027040 */
#define PERI_MS_PPU_FX_TCPWM0_GRP1_CNT7_CNT     ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[418])                    /* 0x40027080 */
#define PERI_MS_PPU_FX_TCPWM0_GRP1_CNT8_CNT     ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[419])                    /* 0x400270C0 */
#define PERI_MS_PPU_FX_TCPWM0_GRP1_CNT9_CNT     ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[420])                    /* 0x40027100 */
#define PERI_MS_PPU_FX_TCPWM0_GRP1_CNT10_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[421])                    /* 0x40027140 */
#define PERI_MS_PPU_FX_TCPWM0_GRP1_CNT11_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[422])                    /* 0x40027180 */
#define PERI_MS_PPU_FX_TCPWM0_GRP2_CNT0_CNT     ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[423])                    /* 0x400271C0 */
#define PERI_MS_PPU_FX_TCPWM0_GRP2_CNT1_CNT     ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[424])                    /* 0x40027200 */
#define PERI_MS_PPU_FX_TCPWM0_GRP2_CNT2_CNT     ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[425])                    /* 0x40027240 */
#define PERI_MS_PPU_FX_TCPWM0_GRP2_CNT3_CNT     ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[426])                    /* 0x40027280 */
#define PERI_MS_PPU_FX_TCPWM0_GRP2_CNT4_CNT     ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[427])                    /* 0x400272C0 */
#define PERI_MS_PPU_FX_TCPWM0_GRP2_CNT5_CNT     ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[428])                    /* 0x40027300 */
#define PERI_MS_PPU_FX_TCPWM0_GRP2_CNT6_CNT     ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[429])                    /* 0x40027340 */
#define PERI_MS_PPU_FX_TCPWM0_GRP2_CNT7_CNT     ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[430])                    /* 0x40027380 */
#define PERI_MS_PPU_FX_TCPWM0_GRP2_CNT8_CNT     ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[431])                    /* 0x400273C0 */
#define PERI_MS_PPU_FX_TCPWM0_GRP2_CNT9_CNT     ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[432])                    /* 0x40027400 */
#define PERI_MS_PPU_FX_TCPWM0_GRP2_CNT10_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[433])                    /* 0x40027440 */
#define PERI_MS_PPU_FX_TCPWM0_GRP2_CNT11_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[434])                    /* 0x40027480 */
#define PERI_MS_PPU_FX_TCPWM0_GRP2_CNT12_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[435])                    /* 0x400274C0 */
#define PERI_MS_PPU_FX_TCPWM0_GRP2_CNT13_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[436])                    /* 0x40027500 */
#define PERI_MS_PPU_FX_TCPWM0_GRP2_CNT14_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[437])                    /* 0x40027540 */
#define PERI_MS_PPU_FX_TCPWM0_GRP2_CNT15_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[438])                    /* 0x40027580 */
#define PERI_MS_PPU_FX_TCPWM0_GRP2_CNT16_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[439])                    /* 0x400275C0 */
#define PERI_MS_PPU_FX_TCPWM0_GRP2_CNT17_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[440])                    /* 0x40027600 */
#define PERI_MS_PPU_FX_TCPWM0_GRP2_CNT18_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[441])                    /* 0x40027640 */
#define PERI_MS_PPU_FX_TCPWM0_GRP2_CNT19_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[442])                    /* 0x40027680 */
#define PERI_MS_PPU_FX_TCPWM0_GRP2_CNT20_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[443])                    /* 0x400276C0 */
#define PERI_MS_PPU_FX_TCPWM0_GRP2_CNT21_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[444])                    /* 0x40027700 */
#define PERI_MS_PPU_FX_TCPWM0_GRP2_CNT22_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[445])                    /* 0x40027740 */
#define PERI_MS_PPU_FX_TCPWM0_GRP2_CNT23_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[446])                    /* 0x40027780 */
#define PERI_MS_PPU_FX_TCPWM0_GRP2_CNT24_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[447])                    /* 0x400277C0 */
#define PERI_MS_PPU_FX_TCPWM0_GRP2_CNT25_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[448])                    /* 0x40027800 */
#define PERI_MS_PPU_FX_TCPWM0_GRP2_CNT26_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[449])                    /* 0x40027840 */
#define PERI_MS_PPU_FX_TCPWM0_GRP2_CNT27_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[450])                    /* 0x40027880 */
#define PERI_MS_PPU_FX_TCPWM0_GRP2_CNT28_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[451])                    /* 0x400278C0 */
#define PERI_MS_PPU_FX_TCPWM0_GRP2_CNT29_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[452])                    /* 0x40027900 */
#define PERI_MS_PPU_FX_TCPWM0_GRP2_CNT30_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[453])                    /* 0x40027940 */
#define PERI_MS_PPU_FX_TCPWM0_GRP2_CNT31_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[454])                    /* 0x40027980 */
#define PERI_MS_PPU_FX_EVTGEN0                  ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[455])                    /* 0x400279C0 */
#define PERI_MS_PPU_FX_SMIF0_MAIN               ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[456])                    /* 0x40027A00 */
#define PERI_MS_PPU_FX_ETH0                     ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[457])                    /* 0x40027A40 */
#define PERI_MS_PPU_FX_LIN0_MAIN                ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[458])                    /* 0x40027A80 */
#define PERI_MS_PPU_FX_LIN0_CH0_CH              ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[459])                    /* 0x40027AC0 */
#define PERI_MS_PPU_FX_LIN0_CH1_CH              ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[460])                    /* 0x40027B00 */
#define PERI_MS_PPU_FX_CXPI0_MAIN               ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[461])                    /* 0x40027B40 */
#define PERI_MS_PPU_FX_CXPI0_CH0_CH             ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[462])                    /* 0x40027B80 */
#define PERI_MS_PPU_FX_CXPI0_CH1_CH             ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[463])                    /* 0x40027BC0 */
#define PERI_MS_PPU_FX_CANFD0_CH0_CH            ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[464])                    /* 0x40027C00 */
#define PERI_MS_PPU_FX_CANFD0_CH1_CH            ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[465])                    /* 0x40027C40 */
#define PERI_MS_PPU_FX_CANFD1_CH0_CH            ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[466])                    /* 0x40027C80 */
#define PERI_MS_PPU_FX_CANFD1_CH1_CH            ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[467])                    /* 0x40027CC0 */
#define PERI_MS_PPU_FX_CANFD0_MAIN              ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[468])                    /* 0x40027D00 */
#define PERI_MS_PPU_FX_CANFD1_MAIN              ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[469])                    /* 0x40027D40 */
#define PERI_MS_PPU_FX_CANFD0_BUF               ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[470])                    /* 0x40027D80 */
#define PERI_MS_PPU_FX_CANFD1_BUF               ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[471])                    /* 0x40027DC0 */
#define PERI_MS_PPU_FX_SCB0                     ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[472])                    /* 0x40027E00 */
#define PERI_MS_PPU_FX_SCB1                     ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[473])                    /* 0x40027E40 */
#define PERI_MS_PPU_FX_SCB2                     ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[474])                    /* 0x40027E80 */
#define PERI_MS_PPU_FX_SCB3                     ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[475])                    /* 0x40027EC0 */
#define PERI_MS_PPU_FX_SCB4                     ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[476])                    /* 0x40027F00 */
#define PERI_MS_PPU_FX_SCB5                     ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[477])                    /* 0x40027F40 */
#define PERI_MS_PPU_FX_SCB6                     ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[478])                    /* 0x40027F80 */
#define PERI_MS_PPU_FX_SCB7                     ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[479])                    /* 0x40027FC0 */
#define PERI_MS_PPU_FX_SCB8                     ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[480])                    /* 0x40028000 */
#define PERI_MS_PPU_FX_SCB9                     ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[481])                    /* 0x40028040 */
#define PERI_MS_PPU_FX_SCB10                    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[482])                    /* 0x40028080 */
#define PERI_MS_PPU_FX_SCB11                    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[483])                    /* 0x400280C0 */
#define PERI_MS_PPU_FX_TDM0_TDM_STRUCT0_TDM_TX_STRUCT_TX ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[484])           /* 0x40028100 */
#define PERI_MS_PPU_FX_TDM0_TDM_STRUCT1_TDM_TX_STRUCT_TX ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[485])           /* 0x40028140 */
#define PERI_MS_PPU_FX_TDM0_TDM_STRUCT2_TDM_TX_STRUCT_TX ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[486])           /* 0x40028180 */
#define PERI_MS_PPU_FX_TDM0_TDM_STRUCT3_TDM_TX_STRUCT_TX ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[487])           /* 0x400281C0 */
#define PERI_MS_PPU_FX_TDM0_TDM_STRUCT0_TDM_RX_STRUCT_RX ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[488])           /* 0x40028200 */
#define PERI_MS_PPU_FX_TDM0_TDM_STRUCT1_TDM_RX_STRUCT_RX ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[489])           /* 0x40028240 */
#define PERI_MS_PPU_FX_TDM0_TDM_STRUCT2_TDM_RX_STRUCT_RX ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[490])           /* 0x40028280 */
#define PERI_MS_PPU_FX_TDM0_TDM_STRUCT3_TDM_RX_STRUCT_RX ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[491])           /* 0x400282C0 */
#define PERI_MS_PPU_FX_SG0_SG_STRUCT0_TX        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[492])                    /* 0x40028300 */
#define PERI_MS_PPU_FX_SG0_SG_STRUCT1_TX        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[493])                    /* 0x40028340 */
#define PERI_MS_PPU_FX_SG0_SG_STRUCT2_TX        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[494])                    /* 0x40028380 */
#define PERI_MS_PPU_FX_SG0_SG_STRUCT3_TX        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[495])                    /* 0x400283C0 */
#define PERI_MS_PPU_FX_SG0_SG_STRUCT4_TX        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[496])                    /* 0x40028400 */
#define PERI_MS_PPU_FX_PWM0_MAIN                ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[497])                    /* 0x40028440 */
#define PERI_MS_PPU_FX_PWM0_TX0_TX              ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[498])                    /* 0x40028480 */
#define PERI_MS_PPU_FX_PWM0_TX1_TX              ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[499])                    /* 0x400284C0 */
#define PERI_MS_PPU_FX_DAC0_MAIN                ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[500])                    /* 0x40028500 */
#define PERI_MS_PPU_FX_MIXER0_MIXER_SRC_STRUCT0_SRC ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[501])                /* 0x40028540 */
#define PERI_MS_PPU_FX_MIXER0_MIXER_SRC_STRUCT1_SRC ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[502])                /* 0x40028580 */
#define PERI_MS_PPU_FX_MIXER0_MIXER_SRC_STRUCT2_SRC ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[503])                /* 0x400285C0 */
#define PERI_MS_PPU_FX_MIXER0_MIXER_SRC_STRUCT3_SRC ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[504])                /* 0x40028600 */
#define PERI_MS_PPU_FX_MIXER0_MIXER_SRC_STRUCT4_SRC ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[505])                /* 0x40028640 */
#define PERI_MS_PPU_FX_MIXER1_MIXER_SRC_STRUCT0_SRC ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[506])                /* 0x40028680 */
#define PERI_MS_PPU_FX_MIXER1_MIXER_SRC_STRUCT1_SRC ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[507])                /* 0x400286C0 */
#define PERI_MS_PPU_FX_MIXER1_MIXER_SRC_STRUCT2_SRC ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[508])                /* 0x40028700 */
#define PERI_MS_PPU_FX_MIXER1_MIXER_SRC_STRUCT3_SRC ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[509])                /* 0x40028740 */
#define PERI_MS_PPU_FX_MIXER1_MIXER_SRC_STRUCT4_SRC ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[510])                /* 0x40028780 */
#define PERI_MS_PPU_FX_MIXER0_MIXER_DST_STRUCT_DST ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[511])                 /* 0x400287C0 */
#define PERI_MS_PPU_FX_MIXER1_MIXER_DST_STRUCT_DST ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[512])                 /* 0x40028800 */
#define PERI_MS_PPU_FX_PASS0_SAR0_SAR           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[513])                    /* 0x40028840 */
#define PERI_MS_PPU_FX_PASS0_SAR1_SAR           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[514])                    /* 0x40028880 */
#define PERI_MS_PPU_FX_PASS0_SAR0_CH0_CH        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[515])                    /* 0x400288C0 */
#define PERI_MS_PPU_FX_PASS0_SAR0_CH1_CH        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[516])                    /* 0x40028900 */
#define PERI_MS_PPU_FX_PASS0_SAR0_CH2_CH        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[517])                    /* 0x40028940 */
#define PERI_MS_PPU_FX_PASS0_SAR0_CH3_CH        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[518])                    /* 0x40028980 */
#define PERI_MS_PPU_FX_PASS0_SAR0_CH4_CH        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[519])                    /* 0x400289C0 */
#define PERI_MS_PPU_FX_PASS0_SAR0_CH5_CH        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[520])                    /* 0x40028A00 */
#define PERI_MS_PPU_FX_PASS0_SAR0_CH6_CH        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[521])                    /* 0x40028A40 */
#define PERI_MS_PPU_FX_PASS0_SAR0_CH7_CH        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[522])                    /* 0x40028A80 */
#define PERI_MS_PPU_FX_PASS0_SAR0_CH8_CH        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[523])                    /* 0x40028AC0 */
#define PERI_MS_PPU_FX_PASS0_SAR0_CH9_CH        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[524])                    /* 0x40028B00 */
#define PERI_MS_PPU_FX_PASS0_SAR0_CH10_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[525])                    /* 0x40028B40 */
#define PERI_MS_PPU_FX_PASS0_SAR0_CH11_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[526])                    /* 0x40028B80 */
#define PERI_MS_PPU_FX_PASS0_SAR0_CH12_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[527])                    /* 0x40028BC0 */
#define PERI_MS_PPU_FX_PASS0_SAR0_CH13_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[528])                    /* 0x40028C00 */
#define PERI_MS_PPU_FX_PASS0_SAR0_CH14_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[529])                    /* 0x40028C40 */
#define PERI_MS_PPU_FX_PASS0_SAR0_CH15_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[530])                    /* 0x40028C80 */
#define PERI_MS_PPU_FX_PASS0_SAR0_CH16_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[531])                    /* 0x40028CC0 */
#define PERI_MS_PPU_FX_PASS0_SAR0_CH17_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[532])                    /* 0x40028D00 */
#define PERI_MS_PPU_FX_PASS0_SAR0_CH18_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[533])                    /* 0x40028D40 */
#define PERI_MS_PPU_FX_PASS0_SAR0_CH19_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[534])                    /* 0x40028D80 */
#define PERI_MS_PPU_FX_PASS0_SAR0_CH20_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[535])                    /* 0x40028DC0 */
#define PERI_MS_PPU_FX_PASS0_SAR0_CH21_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[536])                    /* 0x40028E00 */
#define PERI_MS_PPU_FX_PASS0_SAR0_CH22_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[537])                    /* 0x40028E40 */
#define PERI_MS_PPU_FX_PASS0_SAR0_CH23_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[538])                    /* 0x40028E80 */
#define PERI_MS_PPU_FX_PASS0_SAR0_CH24_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[539])                    /* 0x40028EC0 */
#define PERI_MS_PPU_FX_PASS0_SAR0_CH25_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[540])                    /* 0x40028F00 */
#define PERI_MS_PPU_FX_PASS0_SAR0_CH26_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[541])                    /* 0x40028F40 */
#define PERI_MS_PPU_FX_PASS0_SAR0_CH27_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[542])                    /* 0x40028F80 */
#define PERI_MS_PPU_FX_PASS0_SAR0_CH28_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[543])                    /* 0x40028FC0 */
#define PERI_MS_PPU_FX_PASS0_SAR0_CH29_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[544])                    /* 0x40029000 */
#define PERI_MS_PPU_FX_PASS0_SAR0_CH30_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[545])                    /* 0x40029040 */
#define PERI_MS_PPU_FX_PASS0_SAR0_CH31_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[546])                    /* 0x40029080 */
#define PERI_MS_PPU_FX_PASS0_TOP                ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[547])                    /* 0x400290C0 */
#define PERI_MS_PPU_FX_VIDEOSS0_VCFG_VIDEOSSCFG ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[548])                    /* 0x40029100 */
#define PERI_MS_PPU_FX_VIDEOSS0_VCFG_VRAM       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[549])                    /* 0x40029140 */
#define PERI_MS_PPU_FX_VIDEOSS0_GPU_GFX2D       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[550])                    /* 0x40029180 */
#define PERI_MS_PPU_FX_VIDEOSS0_VIDEOIOCFG_VIRQ_VIDEOIOCFG ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[551])         /* 0x400291C0 */
#define PERI_MS_PPU_FX_VIDEOSS0_CAPIFC0_FRAMEDUMP ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[552])                  /* 0x40029200 */
#define PERI_MS_PPU_FX_VIDEOSS0_CAPIFC0_CAPENG0 ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[553])                    /* 0x40029240 */
#define PERI_MS_PPU_FX_VIDEOSS0_DSPCFG_COMPENGCFG ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[554])                  /* 0x40029280 */
#define PERI_MS_PPU_FX_VIDEOSS0_DSPSEC0_CONSTFRAME0 ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[555])                /* 0x400292C0 */
#define PERI_MS_PPU_FX_VIDEOSS0_DSPSEC0_EXTDST0 ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[556])                    /* 0x40029300 */
#define PERI_MS_PPU_FX_VIDEOSS0_DSPPRIM0_CONSTFRAME4 ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[557])               /* 0x40029340 */
#define PERI_MS_PPU_FX_VIDEOSS0_DSPPRIM0_EXTDST4 ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[558])                   /* 0x40029380 */
#define PERI_MS_PPU_FX_VIDEOSS0_DSPSEC1_CONSTFRAME1 ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[559])                /* 0x400293C0 */
#define PERI_MS_PPU_FX_VIDEOSS0_DSPSEC1_EXTDST1 ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[560])                    /* 0x40029400 */
#define PERI_MS_PPU_FX_VIDEOSS0_DSPPRIM1_CONSTFRAME5 ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[561])               /* 0x40029440 */
#define PERI_MS_PPU_FX_VIDEOSS0_DSPPRIM1_EXTDST5 ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[562])                   /* 0x40029480 */
#define PERI_MS_PPU_FX_VIDEOSS0_CAPIFC0_EXTSRC4 ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[563])                    /* 0x400294C0 */
#define PERI_MS_PPU_FX_VIDEOSS0_CAPIFC0_STORE4  ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[564])                    /* 0x40029500 */
#define PERI_MS_PPU_FX_VIDEOSS0_DSPLAYER1_FETCHLAYER0 ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[565])              /* 0x40029540 */
#define PERI_MS_PPU_FX_VIDEOSS0_DSPLAYER2_FETCHDECODE4 ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[566])             /* 0x40029580 */
#define PERI_MS_PPU_FX_VIDEOSS0_DSPLAYER2_FETCHECO4 ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[567])                /* 0x400295C0 */
#define PERI_MS_PPU_FX_VIDEOSS0_DSPLAYER3_FETCHWARP1 ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[568])               /* 0x40029600 */
#define PERI_MS_PPU_FX_VIDEOSS0_DSPLAYER3_FETCHECO1 ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[569])                /* 0x40029640 */
#define PERI_MS_PPU_FX_VIDEOSS0_DSPLAYER4_FETCHLAYER1 ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[570])              /* 0x40029680 */
#define PERI_MS_PPU_FX_VIDEOSS0_DSPLAYER5_FETCHDECODE0 ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[571])             /* 0x400296C0 */
#define PERI_MS_PPU_FX_VIDEOSS0_DSPVPB_GAMMACOR4 ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[572])                   /* 0x40029700 */
#define PERI_MS_PPU_FX_VIDEOSS0_DSPVPB_MATRIX4  ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[573])                    /* 0x40029740 */
#define PERI_MS_PPU_FX_VIDEOSS0_DSPVPB_GPSCALER4 ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[574])                   /* 0x40029780 */
#define PERI_MS_PPU_FX_VIDEOSS0_DSPVPB_HISTOGRAM4 ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[575])                  /* 0x400297C0 */
#define PERI_MS_PPU_FX_VIDEOSS0_DSPBLEND1_LAYERBLEND1 ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[576])              /* 0x40029800 */
#define PERI_MS_PPU_FX_VIDEOSS0_DSPBLEND2_LAYERBLEND2 ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[577])              /* 0x40029840 */
#define PERI_MS_PPU_FX_VIDEOSS0_DSPBLEND3_LAYERBLEND3 ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[578])              /* 0x40029880 */
#define PERI_MS_PPU_FX_VIDEOSS0_DSPBLEND4_LAYERBLEND4 ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[579])              /* 0x400298C0 */
#define PERI_MS_PPU_FX_VIDEOSS0_DSPBLEND5_LAYERBLEND5 ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[580])              /* 0x40029900 */
#define PERI_MS_PPU_FX_VIDEOSS0_CAPIFC0_EXTSRC8 ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[581])                    /* 0x40029940 */
#define PERI_MS_PPU_FX_VIDEOSS0_DSPCFG0_DISENGCFG0 ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[582])                 /* 0x40029980 */
#define PERI_MS_PPU_FX_VIDEOSS0_DSPMON0_SIG0    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[583])                    /* 0x400299C0 */
#define PERI_MS_PPU_FX_VIDEOSS0_DSPCFG0_FRAMEGEN0 ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[584])                  /* 0x40029A00 */
#define PERI_MS_PPU_FX_VIDEOSS0_DSPCOL0_GAMMACOR0 ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[585])                  /* 0x40029A40 */
#define PERI_MS_PPU_FX_VIDEOSS0_DSPCOL0_DITHER0 ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[586])                    /* 0x40029A80 */
#define PERI_MS_PPU_FX_VIDEOSS0_DSPIFC0_TCON0   ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[587])                    /* 0x40029AC0 */
#define PERI_MS_PPU_FX_VIDEOSS0_DSPCFG1_DISENGCFG1 ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[588])                 /* 0x40029B00 */
#define PERI_MS_PPU_FX_VIDEOSS0_DSPMON1_SIG1    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[589])                    /* 0x40029B40 */
#define PERI_MS_PPU_FX_VIDEOSS0_DSPCFG1_FRAMEGEN1 ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[590])                  /* 0x40029B80 */
#define PERI_MS_PPU_FX_VIDEOSS0_DSPCOL1_GAMMACOR1 ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[591])                  /* 0x40029BC0 */
#define PERI_MS_PPU_FX_VIDEOSS0_DSPCOL1_DITHER1 ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[592])                    /* 0x40029C00 */
#define PERI_MS_PPU_FX_VIDEOSS0_DSPIFC1_TCON1   ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[593])                    /* 0x40029C40 */
#define PERI_MS_PPU_FX_VIDEOSS0_DSPIFC0_FPDLINK0 ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[594])                   /* 0x40029C80 */
#define PERI_MS_PPU_FX_VIDEOSS0_DSPIFC1_FPDLINK1 ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[595])                   /* 0x40029CC0 */
#define PERI_MS_PPU_FX_VIDEOSS0_MIPICSI0_MIPICSI_STRUCT_MIPICSI_WRAP_MAIN ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[596]) /* 0x40029D00 */
#define PERI_MS_PPU_FX_VIDEOSS0_MIPICSI0_MIPICSI_STRUCT_MIPICSI_CORE_3PIP ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[597]) /* 0x40029D40 */
#define PERI_MS_PPU_FX_VIDEOSS0_VRPU_MAIN       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[598])                    /* 0x40029D80 */
#define PERI_MS_PPU_FX_VIDEOSS0_GFX_MPU_RD0_MAIN ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[599])                   /* 0x40029DC0 */
#define PERI_MS_PPU_FX_VIDEOSS0_GFX_MPU_RD1_MAIN ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[600])                   /* 0x40029E00 */
#define PERI_MS_PPU_FX_VIDEOSS0_GFX_MPU_RD2_MAIN ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[601])                   /* 0x40029E40 */
#define PERI_MS_PPU_FX_VIDEOSS0_GFX_MPU_RD3_MAIN ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[602])                   /* 0x40029E80 */
#define PERI_MS_PPU_FX_VIDEOSS0_GFX_MPU_RD4_MAIN ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[603])                   /* 0x40029EC0 */
#define PERI_MS_PPU_FX_VIDEOSS0_GFX_MPU_RD5_MAIN ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[604])                   /* 0x40029F00 */
#define PERI_MS_PPU_FX_VIDEOSS0_GFX_MPU_RD6_MAIN ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[605])                   /* 0x40029F40 */
#define PERI_MS_PPU_FX_VIDEOSS0_GFX_MPU_RD7_MAIN ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[606])                   /* 0x40029F80 */
#define PERI_MS_PPU_FX_VIDEOSS0_GFX_MPU_RD8_MAIN ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[607])                   /* 0x40029FC0 */
#define PERI_MS_PPU_FX_VIDEOSS0_GFX_MPU_RD9_MAIN ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[608])                   /* 0x4002A000 */
#define PERI_MS_PPU_FX_VIDEOSS0_GFX_MPU_RD10_MAIN ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[609])                  /* 0x4002A040 */
#define PERI_MS_PPU_FX_VIDEOSS0_GFX_MPU_RD11_MAIN ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[610])                  /* 0x4002A080 */
#define PERI_MS_PPU_FX_VIDEOSS0_GFX_MPU_RD12_MAIN ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[611])                  /* 0x4002A0C0 */
#define PERI_MS_PPU_FX_VIDEOSS0_GFX_MPU_RD13_MAIN ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[612])                  /* 0x4002A100 */
#define PERI_MS_PPU_FX_VIDEOSS0_GFX_MPU_RD14_MAIN ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[613])                  /* 0x4002A140 */
#define PERI_MS_PPU_FX_VIDEOSS0_GFX_MPU_RD15_MAIN ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[614])                  /* 0x4002A180 */
#define PERI_MS_PPU_FX_VIDEOSS0_GFX_MPU_WR0_MAIN ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[615])                   /* 0x4002A1C0 */
#define PERI_MS_PPU_FX_VIDEOSS0_GFX_MPU_WR1_MAIN ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[616])                   /* 0x4002A200 */
#define PERI_MS_PPU_FX_VIDEOSS0_GFX_MPU_WR2_MAIN ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[617])                   /* 0x4002A240 */
#define PERI_MS_PPU_FX_VIDEOSS0_GFX_MPU_WR3_MAIN ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[618])                   /* 0x4002A280 */
#define PERI_MS_PPU_FX_VIDEOSS0_GFX_MPU_WR4_MAIN ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[619])                   /* 0x4002A2C0 */
#define PERI_MS_PPU_FX_VIDEOSS0_GFX_MPU_WR5_MAIN ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[620])                   /* 0x4002A300 */
#define PERI_MS_PPU_FX_VIDEOSS0_GFX_MPU_WR6_MAIN ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[621])                   /* 0x4002A340 */
#define PERI_MS_PPU_FX_VIDEOSS0_GFX_MPU_WR7_MAIN ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[622])                   /* 0x4002A380 */
#define PERI_MS_PPU_FX_VIDEOSS0_GFX_MPU_WR8_MAIN ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[623])                   /* 0x4002A3C0 */
#define PERI_MS_PPU_FX_VIDEOSS0_GFX_MPU_WR9_MAIN ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[624])                   /* 0x4002A400 */
#define PERI_MS_PPU_FX_VIDEOSS0_GFX_MPU_WR10_MAIN ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[625])                  /* 0x4002A440 */
#define PERI_MS_PPU_FX_VIDEOSS0_GFX_MPU_WR11_MAIN ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[626])                  /* 0x4002A480 */
#define PERI_MS_PPU_FX_VIDEOSS0_GFX_MPU_WR12_MAIN ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[627])                  /* 0x4002A4C0 */
#define PERI_MS_PPU_FX_VIDEOSS0_GFX_MPU_WR13_MAIN ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[628])                  /* 0x4002A500 */
#define PERI_MS_PPU_FX_VIDEOSS0_GFX_MPU_WR14_MAIN ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[629])                  /* 0x4002A540 */
#define PERI_MS_PPU_FX_VIDEOSS0_GFX_MPU_WR15_MAIN ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[630])                  /* 0x4002A580 */
#define PERI_MS_PPU_FX_PD_PD                    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[631])                    /* 0x4002A5C0 */
#define PERI_MS_PPU_FX_JPEGDEC_JPEGDEC          ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[632])                    /* 0x4002A600 */

/*******************************************************************************
*                                  PERI_PCLK
*******************************************************************************/

#define PERI_PCLK_BASE                          0x40040000UL
#define PERI_PCLK                               ((PERI_PCLK_Type*) PERI_PCLK_BASE)                                /* 0x40040000 */
#define PERI_PCLK_GR0                           ((PERI_PCLK_GR_Type*) &PERI_PCLK->GR[0])                          /* 0x40040000 */
#define PERI_PCLK_GR1                           ((PERI_PCLK_GR_Type*) &PERI_PCLK->GR[1])                          /* 0x40042000 */

/*******************************************************************************
*                                    CRYPTO
*******************************************************************************/

#define CRYPTO_BASE                             0x40100000UL
#define CRYPTO                                  ((CRYPTO_Type*) CRYPTO_BASE)                                      /* 0x40100000 */

/*******************************************************************************
*                                    CPUSS
*******************************************************************************/

#define CPUSS_BASE                              0x40200000UL
#define CPUSS                                   ((CPUSS_Type*) CPUSS_BASE)                                        /* 0x40200000 */

/*******************************************************************************
*                                    FAULT
*******************************************************************************/

#define FAULT_BASE                              0x40210000UL
#define FAULT                                   ((FAULT_Type*) FAULT_BASE)                                        /* 0x40210000 */
#define FAULT_STRUCT0                           ((FAULT_STRUCT_Type*) &FAULT->STRUCT[0])                          /* 0x40210000 */
#define FAULT_STRUCT1                           ((FAULT_STRUCT_Type*) &FAULT->STRUCT[1])                          /* 0x40210100 */
#define FAULT_STRUCT2                           ((FAULT_STRUCT_Type*) &FAULT->STRUCT[2])                          /* 0x40210200 */
#define FAULT_STRUCT3                           ((FAULT_STRUCT_Type*) &FAULT->STRUCT[3])                          /* 0x40210300 */

/*******************************************************************************
*                                     IPC
*******************************************************************************/

#define IPC_BASE                                0x40220000UL
#define IPC                                     ((IPC_Type*) IPC_BASE)                                            /* 0x40220000 */
#define IPC_STRUCT0                             ((IPC_STRUCT_Type*) &IPC->STRUCT[0])                              /* 0x40220000 */
#define IPC_STRUCT1                             ((IPC_STRUCT_Type*) &IPC->STRUCT[1])                              /* 0x40220020 */
#define IPC_STRUCT2                             ((IPC_STRUCT_Type*) &IPC->STRUCT[2])                              /* 0x40220040 */
#define IPC_STRUCT3                             ((IPC_STRUCT_Type*) &IPC->STRUCT[3])                              /* 0x40220060 */
#define IPC_STRUCT4                             ((IPC_STRUCT_Type*) &IPC->STRUCT[4])                              /* 0x40220080 */
#define IPC_STRUCT5                             ((IPC_STRUCT_Type*) &IPC->STRUCT[5])                              /* 0x402200A0 */
#define IPC_STRUCT6                             ((IPC_STRUCT_Type*) &IPC->STRUCT[6])                              /* 0x402200C0 */
#define IPC_STRUCT7                             ((IPC_STRUCT_Type*) &IPC->STRUCT[7])                              /* 0x402200E0 */
#define IPC_INTR_STRUCT0                        ((IPC_INTR_STRUCT_Type*) &IPC->INTR_STRUCT[0])                    /* 0x40221000 */
#define IPC_INTR_STRUCT1                        ((IPC_INTR_STRUCT_Type*) &IPC->INTR_STRUCT[1])                    /* 0x40221020 */
#define IPC_INTR_STRUCT2                        ((IPC_INTR_STRUCT_Type*) &IPC->INTR_STRUCT[2])                    /* 0x40221040 */
#define IPC_INTR_STRUCT3                        ((IPC_INTR_STRUCT_Type*) &IPC->INTR_STRUCT[3])                    /* 0x40221060 */
#define IPC_INTR_STRUCT4                        ((IPC_INTR_STRUCT_Type*) &IPC->INTR_STRUCT[4])                    /* 0x40221080 */
#define IPC_INTR_STRUCT5                        ((IPC_INTR_STRUCT_Type*) &IPC->INTR_STRUCT[5])                    /* 0x402210A0 */
#define IPC_INTR_STRUCT6                        ((IPC_INTR_STRUCT_Type*) &IPC->INTR_STRUCT[6])                    /* 0x402210C0 */
#define IPC_INTR_STRUCT7                        ((IPC_INTR_STRUCT_Type*) &IPC->INTR_STRUCT[7])                    /* 0x402210E0 */

/*******************************************************************************
*                                     PROT
*******************************************************************************/

#define PROT_BASE                               0x40230000UL
#define PROT                                    ((PROT_Type*) PROT_BASE)                                          /* 0x40230000 */
#define PROT_SMPU                               ((PROT_SMPU_Type*) &PROT->SMPU)                                   /* 0x40230000 */
#define PROT_SMPU_SMPU_STRUCT0                  ((PROT_SMPU_SMPU_STRUCT_Type*) &PROT->SMPU.SMPU_STRUCT[0])        /* 0x40232000 */
#define PROT_SMPU_SMPU_STRUCT1                  ((PROT_SMPU_SMPU_STRUCT_Type*) &PROT->SMPU.SMPU_STRUCT[1])        /* 0x40232040 */
#define PROT_SMPU_SMPU_STRUCT2                  ((PROT_SMPU_SMPU_STRUCT_Type*) &PROT->SMPU.SMPU_STRUCT[2])        /* 0x40232080 */
#define PROT_SMPU_SMPU_STRUCT3                  ((PROT_SMPU_SMPU_STRUCT_Type*) &PROT->SMPU.SMPU_STRUCT[3])        /* 0x402320C0 */
#define PROT_SMPU_SMPU_STRUCT4                  ((PROT_SMPU_SMPU_STRUCT_Type*) &PROT->SMPU.SMPU_STRUCT[4])        /* 0x40232100 */
#define PROT_SMPU_SMPU_STRUCT5                  ((PROT_SMPU_SMPU_STRUCT_Type*) &PROT->SMPU.SMPU_STRUCT[5])        /* 0x40232140 */
#define PROT_SMPU_SMPU_STRUCT6                  ((PROT_SMPU_SMPU_STRUCT_Type*) &PROT->SMPU.SMPU_STRUCT[6])        /* 0x40232180 */
#define PROT_SMPU_SMPU_STRUCT7                  ((PROT_SMPU_SMPU_STRUCT_Type*) &PROT->SMPU.SMPU_STRUCT[7])        /* 0x402321C0 */
#define PROT_SMPU_SMPU_STRUCT8                  ((PROT_SMPU_SMPU_STRUCT_Type*) &PROT->SMPU.SMPU_STRUCT[8])        /* 0x40232200 */
#define PROT_SMPU_SMPU_STRUCT9                  ((PROT_SMPU_SMPU_STRUCT_Type*) &PROT->SMPU.SMPU_STRUCT[9])        /* 0x40232240 */
#define PROT_SMPU_SMPU_STRUCT10                 ((PROT_SMPU_SMPU_STRUCT_Type*) &PROT->SMPU.SMPU_STRUCT[10])       /* 0x40232280 */
#define PROT_SMPU_SMPU_STRUCT11                 ((PROT_SMPU_SMPU_STRUCT_Type*) &PROT->SMPU.SMPU_STRUCT[11])       /* 0x402322C0 */
#define PROT_SMPU_SMPU_STRUCT12                 ((PROT_SMPU_SMPU_STRUCT_Type*) &PROT->SMPU.SMPU_STRUCT[12])       /* 0x40232300 */
#define PROT_SMPU_SMPU_STRUCT13                 ((PROT_SMPU_SMPU_STRUCT_Type*) &PROT->SMPU.SMPU_STRUCT[13])       /* 0x40232340 */
#define PROT_SMPU_SMPU_STRUCT14                 ((PROT_SMPU_SMPU_STRUCT_Type*) &PROT->SMPU.SMPU_STRUCT[14])       /* 0x40232380 */
#define PROT_SMPU_SMPU_STRUCT15                 ((PROT_SMPU_SMPU_STRUCT_Type*) &PROT->SMPU.SMPU_STRUCT[15])       /* 0x402323C0 */
#define PROT_MPU0                               ((PROT_MPU_Type*) &PROT->CYMPU[0])                                /* 0x40234000 */
#define PROT_MPU1                               ((PROT_MPU_Type*) &PROT->CYMPU[1])                                /* 0x40234400 */
#define PROT_MPU2                               ((PROT_MPU_Type*) &PROT->CYMPU[2])                                /* 0x40234800 */
#define PROT_MPU3                               ((PROT_MPU_Type*) &PROT->CYMPU[3])                                /* 0x40234C00 */
#define PROT_MPU4                               ((PROT_MPU_Type*) &PROT->CYMPU[4])                                /* 0x40235000 */
#define PROT_MPU5                               ((PROT_MPU_Type*) &PROT->CYMPU[5])                                /* 0x40235400 */
#define PROT_MPU6                               ((PROT_MPU_Type*) &PROT->CYMPU[6])                                /* 0x40235800 */
#define PROT_MPU7                               ((PROT_MPU_Type*) &PROT->CYMPU[7])                                /* 0x40235C00 */
#define PROT_MPU8                               ((PROT_MPU_Type*) &PROT->CYMPU[8])                                /* 0x40236000 */
#define PROT_MPU9                               ((PROT_MPU_Type*) &PROT->CYMPU[9])                                /* 0x40236400 */
#define PROT_MPU10                              ((PROT_MPU_Type*) &PROT->CYMPU[10])                               /* 0x40236800 */
#define PROT_MPU11                              ((PROT_MPU_Type*) &PROT->CYMPU[11])                               /* 0x40236C00 */
#define PROT_MPU12                              ((PROT_MPU_Type*) &PROT->CYMPU[12])                               /* 0x40237000 */
#define PROT_MPU13                              ((PROT_MPU_Type*) &PROT->CYMPU[13])                               /* 0x40237400 */
#define PROT_MPU14                              ((PROT_MPU_Type*) &PROT->CYMPU[14])                               /* 0x40237800 */
#define PROT_MPU15                              ((PROT_MPU_Type*) &PROT->CYMPU[15])                               /* 0x40237C00 */
#define PROT_MPU9_MPU_STRUCT0                   ((PROT_MPU_MPU_STRUCT_Type*) &PROT->CYMPU[9].MPU_STRUCT[0])       /* 0x40236600 */
#define PROT_MPU9_MPU_STRUCT1                   ((PROT_MPU_MPU_STRUCT_Type*) &PROT->CYMPU[9].MPU_STRUCT[1])       /* 0x40236620 */
#define PROT_MPU9_MPU_STRUCT2                   ((PROT_MPU_MPU_STRUCT_Type*) &PROT->CYMPU[9].MPU_STRUCT[2])       /* 0x40236640 */
#define PROT_MPU9_MPU_STRUCT3                   ((PROT_MPU_MPU_STRUCT_Type*) &PROT->CYMPU[9].MPU_STRUCT[3])       /* 0x40236660 */
#define PROT_MPU9_MPU_STRUCT4                   ((PROT_MPU_MPU_STRUCT_Type*) &PROT->CYMPU[9].MPU_STRUCT[4])       /* 0x40236680 */
#define PROT_MPU9_MPU_STRUCT5                   ((PROT_MPU_MPU_STRUCT_Type*) &PROT->CYMPU[9].MPU_STRUCT[5])       /* 0x402366A0 */
#define PROT_MPU9_MPU_STRUCT6                   ((PROT_MPU_MPU_STRUCT_Type*) &PROT->CYMPU[9].MPU_STRUCT[6])       /* 0x402366C0 */
#define PROT_MPU9_MPU_STRUCT7                   ((PROT_MPU_MPU_STRUCT_Type*) &PROT->CYMPU[9].MPU_STRUCT[7])       /* 0x402366E0 */
#define PROT_MPU10_MPU_STRUCT0                  ((PROT_MPU_MPU_STRUCT_Type*) &PROT->CYMPU[10].MPU_STRUCT[0])      /* 0x40236A00 */
#define PROT_MPU10_MPU_STRUCT1                  ((PROT_MPU_MPU_STRUCT_Type*) &PROT->CYMPU[10].MPU_STRUCT[1])      /* 0x40236A20 */
#define PROT_MPU10_MPU_STRUCT2                  ((PROT_MPU_MPU_STRUCT_Type*) &PROT->CYMPU[10].MPU_STRUCT[2])      /* 0x40236A40 */
#define PROT_MPU10_MPU_STRUCT3                  ((PROT_MPU_MPU_STRUCT_Type*) &PROT->CYMPU[10].MPU_STRUCT[3])      /* 0x40236A60 */
#define PROT_MPU10_MPU_STRUCT4                  ((PROT_MPU_MPU_STRUCT_Type*) &PROT->CYMPU[10].MPU_STRUCT[4])      /* 0x40236A80 */
#define PROT_MPU10_MPU_STRUCT5                  ((PROT_MPU_MPU_STRUCT_Type*) &PROT->CYMPU[10].MPU_STRUCT[5])      /* 0x40236AA0 */
#define PROT_MPU10_MPU_STRUCT6                  ((PROT_MPU_MPU_STRUCT_Type*) &PROT->CYMPU[10].MPU_STRUCT[6])      /* 0x40236AC0 */
#define PROT_MPU10_MPU_STRUCT7                  ((PROT_MPU_MPU_STRUCT_Type*) &PROT->CYMPU[10].MPU_STRUCT[7])      /* 0x40236AE0 */
#define PROT_MPU12_MPU_STRUCT0                  ((PROT_MPU_MPU_STRUCT_Type*) &PROT->CYMPU[12].MPU_STRUCT[0])      /* 0x40237200 */
#define PROT_MPU12_MPU_STRUCT1                  ((PROT_MPU_MPU_STRUCT_Type*) &PROT->CYMPU[12].MPU_STRUCT[1])      /* 0x40237220 */
#define PROT_MPU12_MPU_STRUCT2                  ((PROT_MPU_MPU_STRUCT_Type*) &PROT->CYMPU[12].MPU_STRUCT[2])      /* 0x40237240 */
#define PROT_MPU12_MPU_STRUCT3                  ((PROT_MPU_MPU_STRUCT_Type*) &PROT->CYMPU[12].MPU_STRUCT[3])      /* 0x40237260 */
#define PROT_MPU12_MPU_STRUCT4                  ((PROT_MPU_MPU_STRUCT_Type*) &PROT->CYMPU[12].MPU_STRUCT[4])      /* 0x40237280 */
#define PROT_MPU12_MPU_STRUCT5                  ((PROT_MPU_MPU_STRUCT_Type*) &PROT->CYMPU[12].MPU_STRUCT[5])      /* 0x402372A0 */
#define PROT_MPU12_MPU_STRUCT6                  ((PROT_MPU_MPU_STRUCT_Type*) &PROT->CYMPU[12].MPU_STRUCT[6])      /* 0x402372C0 */
#define PROT_MPU12_MPU_STRUCT7                  ((PROT_MPU_MPU_STRUCT_Type*) &PROT->CYMPU[12].MPU_STRUCT[7])      /* 0x402372E0 */
#define PROT_MPU15_MPU_STRUCT0                  ((PROT_MPU_MPU_STRUCT_Type*) &PROT->CYMPU[15].MPU_STRUCT[0])      /* 0x40237E00 */
#define PROT_MPU15_MPU_STRUCT1                  ((PROT_MPU_MPU_STRUCT_Type*) &PROT->CYMPU[15].MPU_STRUCT[1])      /* 0x40237E20 */
#define PROT_MPU15_MPU_STRUCT2                  ((PROT_MPU_MPU_STRUCT_Type*) &PROT->CYMPU[15].MPU_STRUCT[2])      /* 0x40237E40 */
#define PROT_MPU15_MPU_STRUCT3                  ((PROT_MPU_MPU_STRUCT_Type*) &PROT->CYMPU[15].MPU_STRUCT[3])      /* 0x40237E60 */
#define PROT_MPU15_MPU_STRUCT4                  ((PROT_MPU_MPU_STRUCT_Type*) &PROT->CYMPU[15].MPU_STRUCT[4])      /* 0x40237E80 */
#define PROT_MPU15_MPU_STRUCT5                  ((PROT_MPU_MPU_STRUCT_Type*) &PROT->CYMPU[15].MPU_STRUCT[5])      /* 0x40237EA0 */
#define PROT_MPU15_MPU_STRUCT6                  ((PROT_MPU_MPU_STRUCT_Type*) &PROT->CYMPU[15].MPU_STRUCT[6])      /* 0x40237EC0 */
#define PROT_MPU15_MPU_STRUCT7                  ((PROT_MPU_MPU_STRUCT_Type*) &PROT->CYMPU[15].MPU_STRUCT[7])      /* 0x40237EE0 */

/*******************************************************************************
*                                    FLASHC
*******************************************************************************/

#define FLASHC_BASE                             0x40240000UL
#define FLASHC                                  ((FLASHC_Type*) FLASHC_BASE)                                      /* 0x40240000 */
#define FLASHC_FM_CTL_ECT                       ((FLASHC_FM_CTL_ECT_Type*) &FLASHC->FM_CTL_ECT)                   /* 0x4024F000 */

/*******************************************************************************
*                                     SRSS
*******************************************************************************/

#define SRSS_BASE                               0x40260000UL
#define SRSS                                    ((SRSS_Type*) SRSS_BASE)                                          /* 0x40260000 */
#define CSV_HF                                  ((CSV_HF_Type*) &SRSS->CSV_HF_STRUCT)                             /* 0x40261400 */
#define CSV_HF_CSV0                             ((CSV_HF_CSV_Type*) &SRSS->CSV_HF_STRUCT.CSV[0])                  /* 0x40261400 */
#define CSV_HF_CSV1                             ((CSV_HF_CSV_Type*) &SRSS->CSV_HF_STRUCT.CSV[1])                  /* 0x40261410 */
#define CSV_HF_CSV2                             ((CSV_HF_CSV_Type*) &SRSS->CSV_HF_STRUCT.CSV[2])                  /* 0x40261420 */
#define CSV_HF_CSV3                             ((CSV_HF_CSV_Type*) &SRSS->CSV_HF_STRUCT.CSV[3])                  /* 0x40261430 */
#define CSV_HF_CSV4                             ((CSV_HF_CSV_Type*) &SRSS->CSV_HF_STRUCT.CSV[4])                  /* 0x40261440 */
#define CSV_HF_CSV5                             ((CSV_HF_CSV_Type*) &SRSS->CSV_HF_STRUCT.CSV[5])                  /* 0x40261450 */
#define CSV_HF_CSV6                             ((CSV_HF_CSV_Type*) &SRSS->CSV_HF_STRUCT.CSV[6])                  /* 0x40261460 */
#define CSV_HF_CSV7                             ((CSV_HF_CSV_Type*) &SRSS->CSV_HF_STRUCT.CSV[7])                  /* 0x40261470 */
#define CSV_HF_CSV8                             ((CSV_HF_CSV_Type*) &SRSS->CSV_HF_STRUCT.CSV[8])                  /* 0x40261480 */
#define CSV_HF_CSV9                             ((CSV_HF_CSV_Type*) &SRSS->CSV_HF_STRUCT.CSV[9])                  /* 0x40261490 */
#define CSV_HF_CSV10                            ((CSV_HF_CSV_Type*) &SRSS->CSV_HF_STRUCT.CSV[10])                 /* 0x402614A0 */
#define CSV_HF_CSV11                            ((CSV_HF_CSV_Type*) &SRSS->CSV_HF_STRUCT.CSV[11])                 /* 0x402614B0 */
#define CSV_HF_CSV12                            ((CSV_HF_CSV_Type*) &SRSS->CSV_HF_STRUCT.CSV[12])                 /* 0x402614C0 */
#define CSV_HF_CSV13                            ((CSV_HF_CSV_Type*) &SRSS->CSV_HF_STRUCT.CSV[13])                 /* 0x402614D0 */
#define CSV_REF                                 ((CSV_REF_Type*) &SRSS->CSV_REF_STRUCT)                           /* 0x40261710 */
#define CSV_REF_CSV                             ((CSV_REF_CSV_Type*) &SRSS->CSV_REF_STRUCT.CSV)                   /* 0x40261710 */
#define CSV_LF                                  ((CSV_LF_Type*) &SRSS->CSV_LF_STRUCT)                             /* 0x40261720 */
#define CSV_LF_CSV                              ((CSV_LF_CSV_Type*) &SRSS->CSV_LF_STRUCT.CSV)                     /* 0x40261720 */
#define CSV_ILO                                 ((CSV_ILO_Type*) &SRSS->CSV_ILO_STRUCT)                           /* 0x40261730 */
#define CSV_ILO_CSV                             ((CSV_ILO_CSV_Type*) &SRSS->CSV_ILO_STRUCT.CSV)                   /* 0x40261730 */
#define CLK_PLL400M0                            ((CLK_PLL400M_Type*) &SRSS->CLK_PLL400M[0])                       /* 0x40261900 */
#define CLK_PLL400M1                            ((CLK_PLL400M_Type*) &SRSS->CLK_PLL400M[1])                       /* 0x40261910 */
#define CLK_PLL400M2                            ((CLK_PLL400M_Type*) &SRSS->CLK_PLL400M[2])                       /* 0x40261920 */
#define CLK_PLL400M3                            ((CLK_PLL400M_Type*) &SRSS->CLK_PLL400M[3])                       /* 0x40261930 */
#define CLK_PLL400M4                            ((CLK_PLL400M_Type*) &SRSS->CLK_PLL400M[4])                       /* 0x40261940 */
#define MCWDT0                                  ((MCWDT_Type*) &SRSS->MCWDT[0])                                   /* 0x40268000 */
#define MCWDT1                                  ((MCWDT_Type*) &SRSS->MCWDT[1])                                   /* 0x40268100 */
#define MCWDT2                                  ((MCWDT_Type*) &SRSS->MCWDT[2])                                   /* 0x40268200 */
#define MCWDT0_CTR0                             ((MCWDT_CTR_Type*) &SRSS->MCWDT[0].CTR[0])                        /* 0x40268000 */
#define MCWDT0_CTR1                             ((MCWDT_CTR_Type*) &SRSS->MCWDT[0].CTR[1])                        /* 0x40268020 */
#define MCWDT1_CTR0                             ((MCWDT_CTR_Type*) &SRSS->MCWDT[1].CTR[0])                        /* 0x40268100 */
#define MCWDT1_CTR1                             ((MCWDT_CTR_Type*) &SRSS->MCWDT[1].CTR[1])                        /* 0x40268120 */
#define MCWDT2_CTR0                             ((MCWDT_CTR_Type*) &SRSS->MCWDT[2].CTR[0])                        /* 0x40268200 */
#define MCWDT2_CTR1                             ((MCWDT_CTR_Type*) &SRSS->MCWDT[2].CTR[1])                        /* 0x40268220 */
#define WDT                                     ((WDT_Type*) &SRSS->WDT_STRUCT)                                   /* 0x4026C000 */

/*******************************************************************************
*                                    BACKUP
*******************************************************************************/

#define BACKUP_BASE                             0x40270000UL
#define BACKUP                                  ((BACKUP_Type*) BACKUP_BASE)                                      /* 0x40270000 */
#define BACKUP_CSV_BAK                          ((BACKUP_CSV_BAK_Type*) &BACKUP->CSV_BAK)                         /* 0x40270100 */
#define BACKUP_CSV_BAK_CSV                      ((BACKUP_CSV_BAK_CSV_Type*) &BACKUP->CSV_BAK.CSV)                 /* 0x40270100 */

/*******************************************************************************
*                                      DW
*******************************************************************************/

#define DW0_BASE                                0x40280000UL
#define DW1_BASE                                0x40290000UL
#define DW0                                     ((DW_Type*) DW0_BASE)                                             /* 0x40280000 */
#define DW1                                     ((DW_Type*) DW1_BASE)                                             /* 0x40290000 */
#define DW0_CH_STRUCT0                          ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[0])                         /* 0x40288000 */
#define DW0_CH_STRUCT1                          ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[1])                         /* 0x40288040 */
#define DW0_CH_STRUCT2                          ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[2])                         /* 0x40288080 */
#define DW0_CH_STRUCT3                          ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[3])                         /* 0x402880C0 */
#define DW0_CH_STRUCT4                          ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[4])                         /* 0x40288100 */
#define DW0_CH_STRUCT5                          ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[5])                         /* 0x40288140 */
#define DW0_CH_STRUCT6                          ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[6])                         /* 0x40288180 */
#define DW0_CH_STRUCT7                          ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[7])                         /* 0x402881C0 */
#define DW0_CH_STRUCT8                          ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[8])                         /* 0x40288200 */
#define DW0_CH_STRUCT9                          ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[9])                         /* 0x40288240 */
#define DW0_CH_STRUCT10                         ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[10])                        /* 0x40288280 */
#define DW0_CH_STRUCT11                         ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[11])                        /* 0x402882C0 */
#define DW0_CH_STRUCT12                         ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[12])                        /* 0x40288300 */
#define DW0_CH_STRUCT13                         ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[13])                        /* 0x40288340 */
#define DW0_CH_STRUCT14                         ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[14])                        /* 0x40288380 */
#define DW0_CH_STRUCT15                         ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[15])                        /* 0x402883C0 */
#define DW0_CH_STRUCT16                         ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[16])                        /* 0x40288400 */
#define DW0_CH_STRUCT17                         ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[17])                        /* 0x40288440 */
#define DW0_CH_STRUCT18                         ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[18])                        /* 0x40288480 */
#define DW0_CH_STRUCT19                         ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[19])                        /* 0x402884C0 */
#define DW0_CH_STRUCT20                         ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[20])                        /* 0x40288500 */
#define DW0_CH_STRUCT21                         ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[21])                        /* 0x40288540 */
#define DW0_CH_STRUCT22                         ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[22])                        /* 0x40288580 */
#define DW0_CH_STRUCT23                         ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[23])                        /* 0x402885C0 */
#define DW0_CH_STRUCT24                         ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[24])                        /* 0x40288600 */
#define DW0_CH_STRUCT25                         ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[25])                        /* 0x40288640 */
#define DW0_CH_STRUCT26                         ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[26])                        /* 0x40288680 */
#define DW0_CH_STRUCT27                         ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[27])                        /* 0x402886C0 */
#define DW0_CH_STRUCT28                         ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[28])                        /* 0x40288700 */
#define DW0_CH_STRUCT29                         ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[29])                        /* 0x40288740 */
#define DW0_CH_STRUCT30                         ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[30])                        /* 0x40288780 */
#define DW0_CH_STRUCT31                         ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[31])                        /* 0x402887C0 */
#define DW0_CH_STRUCT32                         ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[32])                        /* 0x40288800 */
#define DW0_CH_STRUCT33                         ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[33])                        /* 0x40288840 */
#define DW0_CH_STRUCT34                         ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[34])                        /* 0x40288880 */
#define DW0_CH_STRUCT35                         ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[35])                        /* 0x402888C0 */
#define DW0_CH_STRUCT36                         ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[36])                        /* 0x40288900 */
#define DW0_CH_STRUCT37                         ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[37])                        /* 0x40288940 */
#define DW0_CH_STRUCT38                         ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[38])                        /* 0x40288980 */
#define DW0_CH_STRUCT39                         ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[39])                        /* 0x402889C0 */
#define DW0_CH_STRUCT40                         ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[40])                        /* 0x40288A00 */
#define DW0_CH_STRUCT41                         ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[41])                        /* 0x40288A40 */
#define DW0_CH_STRUCT42                         ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[42])                        /* 0x40288A80 */
#define DW0_CH_STRUCT43                         ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[43])                        /* 0x40288AC0 */
#define DW0_CH_STRUCT44                         ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[44])                        /* 0x40288B00 */
#define DW0_CH_STRUCT45                         ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[45])                        /* 0x40288B40 */
#define DW0_CH_STRUCT46                         ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[46])                        /* 0x40288B80 */
#define DW0_CH_STRUCT47                         ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[47])                        /* 0x40288BC0 */
#define DW0_CH_STRUCT48                         ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[48])                        /* 0x40288C00 */
#define DW0_CH_STRUCT49                         ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[49])                        /* 0x40288C40 */
#define DW0_CH_STRUCT50                         ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[50])                        /* 0x40288C80 */
#define DW0_CH_STRUCT51                         ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[51])                        /* 0x40288CC0 */
#define DW0_CH_STRUCT52                         ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[52])                        /* 0x40288D00 */
#define DW0_CH_STRUCT53                         ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[53])                        /* 0x40288D40 */
#define DW0_CH_STRUCT54                         ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[54])                        /* 0x40288D80 */
#define DW0_CH_STRUCT55                         ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[55])                        /* 0x40288DC0 */
#define DW0_CH_STRUCT56                         ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[56])                        /* 0x40288E00 */
#define DW0_CH_STRUCT57                         ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[57])                        /* 0x40288E40 */
#define DW0_CH_STRUCT58                         ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[58])                        /* 0x40288E80 */
#define DW0_CH_STRUCT59                         ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[59])                        /* 0x40288EC0 */
#define DW0_CH_STRUCT60                         ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[60])                        /* 0x40288F00 */
#define DW0_CH_STRUCT61                         ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[61])                        /* 0x40288F40 */
#define DW0_CH_STRUCT62                         ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[62])                        /* 0x40288F80 */
#define DW0_CH_STRUCT63                         ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[63])                        /* 0x40288FC0 */
#define DW0_CH_STRUCT64                         ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[64])                        /* 0x40289000 */
#define DW0_CH_STRUCT65                         ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[65])                        /* 0x40289040 */
#define DW0_CH_STRUCT66                         ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[66])                        /* 0x40289080 */
#define DW0_CH_STRUCT67                         ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[67])                        /* 0x402890C0 */
#define DW0_CH_STRUCT68                         ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[68])                        /* 0x40289100 */
#define DW0_CH_STRUCT69                         ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[69])                        /* 0x40289140 */
#define DW0_CH_STRUCT70                         ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[70])                        /* 0x40289180 */
#define DW0_CH_STRUCT71                         ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[71])                        /* 0x402891C0 */
#define DW0_CH_STRUCT72                         ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[72])                        /* 0x40289200 */
#define DW0_CH_STRUCT73                         ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[73])                        /* 0x40289240 */
#define DW0_CH_STRUCT74                         ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[74])                        /* 0x40289280 */
#define DW0_CH_STRUCT75                         ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[75])                        /* 0x402892C0 */
#define DW1_CH_STRUCT0                          ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[0])                         /* 0x40298000 */
#define DW1_CH_STRUCT1                          ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[1])                         /* 0x40298040 */
#define DW1_CH_STRUCT2                          ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[2])                         /* 0x40298080 */
#define DW1_CH_STRUCT3                          ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[3])                         /* 0x402980C0 */
#define DW1_CH_STRUCT4                          ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[4])                         /* 0x40298100 */
#define DW1_CH_STRUCT5                          ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[5])                         /* 0x40298140 */
#define DW1_CH_STRUCT6                          ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[6])                         /* 0x40298180 */
#define DW1_CH_STRUCT7                          ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[7])                         /* 0x402981C0 */
#define DW1_CH_STRUCT8                          ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[8])                         /* 0x40298200 */
#define DW1_CH_STRUCT9                          ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[9])                         /* 0x40298240 */
#define DW1_CH_STRUCT10                         ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[10])                        /* 0x40298280 */
#define DW1_CH_STRUCT11                         ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[11])                        /* 0x402982C0 */
#define DW1_CH_STRUCT12                         ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[12])                        /* 0x40298300 */
#define DW1_CH_STRUCT13                         ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[13])                        /* 0x40298340 */
#define DW1_CH_STRUCT14                         ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[14])                        /* 0x40298380 */
#define DW1_CH_STRUCT15                         ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[15])                        /* 0x402983C0 */
#define DW1_CH_STRUCT16                         ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[16])                        /* 0x40298400 */
#define DW1_CH_STRUCT17                         ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[17])                        /* 0x40298440 */
#define DW1_CH_STRUCT18                         ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[18])                        /* 0x40298480 */
#define DW1_CH_STRUCT19                         ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[19])                        /* 0x402984C0 */
#define DW1_CH_STRUCT20                         ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[20])                        /* 0x40298500 */
#define DW1_CH_STRUCT21                         ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[21])                        /* 0x40298540 */
#define DW1_CH_STRUCT22                         ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[22])                        /* 0x40298580 */
#define DW1_CH_STRUCT23                         ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[23])                        /* 0x402985C0 */
#define DW1_CH_STRUCT24                         ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[24])                        /* 0x40298600 */
#define DW1_CH_STRUCT25                         ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[25])                        /* 0x40298640 */
#define DW1_CH_STRUCT26                         ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[26])                        /* 0x40298680 */
#define DW1_CH_STRUCT27                         ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[27])                        /* 0x402986C0 */
#define DW1_CH_STRUCT28                         ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[28])                        /* 0x40298700 */
#define DW1_CH_STRUCT29                         ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[29])                        /* 0x40298740 */
#define DW1_CH_STRUCT30                         ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[30])                        /* 0x40298780 */
#define DW1_CH_STRUCT31                         ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[31])                        /* 0x402987C0 */
#define DW1_CH_STRUCT32                         ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[32])                        /* 0x40298800 */
#define DW1_CH_STRUCT33                         ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[33])                        /* 0x40298840 */
#define DW1_CH_STRUCT34                         ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[34])                        /* 0x40298880 */
#define DW1_CH_STRUCT35                         ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[35])                        /* 0x402988C0 */
#define DW1_CH_STRUCT36                         ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[36])                        /* 0x40298900 */
#define DW1_CH_STRUCT37                         ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[37])                        /* 0x40298940 */
#define DW1_CH_STRUCT38                         ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[38])                        /* 0x40298980 */
#define DW1_CH_STRUCT39                         ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[39])                        /* 0x402989C0 */
#define DW1_CH_STRUCT40                         ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[40])                        /* 0x40298A00 */
#define DW1_CH_STRUCT41                         ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[41])                        /* 0x40298A40 */
#define DW1_CH_STRUCT42                         ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[42])                        /* 0x40298A80 */
#define DW1_CH_STRUCT43                         ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[43])                        /* 0x40298AC0 */
#define DW1_CH_STRUCT44                         ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[44])                        /* 0x40298B00 */
#define DW1_CH_STRUCT45                         ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[45])                        /* 0x40298B40 */
#define DW1_CH_STRUCT46                         ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[46])                        /* 0x40298B80 */
#define DW1_CH_STRUCT47                         ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[47])                        /* 0x40298BC0 */
#define DW1_CH_STRUCT48                         ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[48])                        /* 0x40298C00 */
#define DW1_CH_STRUCT49                         ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[49])                        /* 0x40298C40 */
#define DW1_CH_STRUCT50                         ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[50])                        /* 0x40298C80 */
#define DW1_CH_STRUCT51                         ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[51])                        /* 0x40298CC0 */
#define DW1_CH_STRUCT52                         ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[52])                        /* 0x40298D00 */
#define DW1_CH_STRUCT53                         ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[53])                        /* 0x40298D40 */
#define DW1_CH_STRUCT54                         ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[54])                        /* 0x40298D80 */
#define DW1_CH_STRUCT55                         ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[55])                        /* 0x40298DC0 */
#define DW1_CH_STRUCT56                         ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[56])                        /* 0x40298E00 */
#define DW1_CH_STRUCT57                         ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[57])                        /* 0x40298E40 */
#define DW1_CH_STRUCT58                         ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[58])                        /* 0x40298E80 */
#define DW1_CH_STRUCT59                         ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[59])                        /* 0x40298EC0 */
#define DW1_CH_STRUCT60                         ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[60])                        /* 0x40298F00 */
#define DW1_CH_STRUCT61                         ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[61])                        /* 0x40298F40 */
#define DW1_CH_STRUCT62                         ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[62])                        /* 0x40298F80 */
#define DW1_CH_STRUCT63                         ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[63])                        /* 0x40298FC0 */
#define DW1_CH_STRUCT64                         ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[64])                        /* 0x40299000 */
#define DW1_CH_STRUCT65                         ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[65])                        /* 0x40299040 */
#define DW1_CH_STRUCT66                         ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[66])                        /* 0x40299080 */
#define DW1_CH_STRUCT67                         ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[67])                        /* 0x402990C0 */
#define DW1_CH_STRUCT68                         ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[68])                        /* 0x40299100 */
#define DW1_CH_STRUCT69                         ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[69])                        /* 0x40299140 */
#define DW1_CH_STRUCT70                         ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[70])                        /* 0x40299180 */
#define DW1_CH_STRUCT71                         ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[71])                        /* 0x402991C0 */
#define DW1_CH_STRUCT72                         ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[72])                        /* 0x40299200 */
#define DW1_CH_STRUCT73                         ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[73])                        /* 0x40299240 */
#define DW1_CH_STRUCT74                         ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[74])                        /* 0x40299280 */
#define DW1_CH_STRUCT75                         ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[75])                        /* 0x402992C0 */
#define DW1_CH_STRUCT76                         ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[76])                        /* 0x40299300 */
#define DW1_CH_STRUCT77                         ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[77])                        /* 0x40299340 */
#define DW1_CH_STRUCT78                         ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[78])                        /* 0x40299380 */
#define DW1_CH_STRUCT79                         ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[79])                        /* 0x402993C0 */
#define DW1_CH_STRUCT80                         ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[80])                        /* 0x40299400 */
#define DW1_CH_STRUCT81                         ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[81])                        /* 0x40299440 */
#define DW1_CH_STRUCT82                         ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[82])                        /* 0x40299480 */
#define DW1_CH_STRUCT83                         ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[83])                        /* 0x402994C0 */

/*******************************************************************************
*                                     DMAC
*******************************************************************************/

#define DMAC_BASE                               0x402A0000UL
#define DMAC                                    ((DMAC_Type*) DMAC_BASE)                                          /* 0x402A0000 */
#define DMAC_CH0                                ((DMAC_CH_Type*) &DMAC->CH[0])                                    /* 0x402A1000 */
#define DMAC_CH1                                ((DMAC_CH_Type*) &DMAC->CH[1])                                    /* 0x402A1100 */
#define DMAC_CH2                                ((DMAC_CH_Type*) &DMAC->CH[2])                                    /* 0x402A1200 */
#define DMAC_CH3                                ((DMAC_CH_Type*) &DMAC->CH[3])                                    /* 0x402A1300 */
#define DMAC_CH4                                ((DMAC_CH_Type*) &DMAC->CH[4])                                    /* 0x402A1400 */
#define DMAC_CH5                                ((DMAC_CH_Type*) &DMAC->CH[5])                                    /* 0x402A1500 */
#define DMAC_CH6                                ((DMAC_CH_Type*) &DMAC->CH[6])                                    /* 0x402A1600 */
#define DMAC_CH7                                ((DMAC_CH_Type*) &DMAC->CH[7])                                    /* 0x402A1700 */

/*******************************************************************************
*                                   AXI_DMAC
*******************************************************************************/

#define AXI_DMAC_BASE                           0x402B0000UL
#define AXI_DMAC                                ((AXI_DMAC_Type*) AXI_DMAC_BASE)                                  /* 0x402B0000 */
#define AXI_DMAC_CH0                            ((AXI_DMAC_CH_Type*) &AXI_DMAC->CH[0])                            /* 0x402B1000 */
#define AXI_DMAC_CH1                            ((AXI_DMAC_CH_Type*) &AXI_DMAC->CH[1])                            /* 0x402B1100 */
#define AXI_DMAC_CH2                            ((AXI_DMAC_CH_Type*) &AXI_DMAC->CH[2])                            /* 0x402B1200 */
#define AXI_DMAC_CH3                            ((AXI_DMAC_CH_Type*) &AXI_DMAC->CH[3])                            /* 0x402B1300 */

/*******************************************************************************
*                                    EFUSE
*******************************************************************************/

#define EFUSE_BASE                              0x402C0000UL
#define EFUSE                                   ((EFUSE_Type*) EFUSE_BASE)                                        /* 0x402C0000 */

/*******************************************************************************
*                                    HSIOM
*******************************************************************************/

#define HSIOM_BASE                              0x40300000UL
#define HSIOM                                   ((HSIOM_Type*) HSIOM_BASE)                                        /* 0x40300000 */
#define HSIOM_PRT0                              ((HSIOM_PRT_Type*) &HSIOM->PRT[0])                                /* 0x40300000 */
#define HSIOM_PRT1                              ((HSIOM_PRT_Type*) &HSIOM->PRT[1])                                /* 0x40300010 */
#define HSIOM_PRT2                              ((HSIOM_PRT_Type*) &HSIOM->PRT[2])                                /* 0x40300020 */
#define HSIOM_PRT3                              ((HSIOM_PRT_Type*) &HSIOM->PRT[3])                                /* 0x40300030 */
#define HSIOM_PRT4                              ((HSIOM_PRT_Type*) &HSIOM->PRT[4])                                /* 0x40300040 */
#define HSIOM_PRT5                              ((HSIOM_PRT_Type*) &HSIOM->PRT[5])                                /* 0x40300050 */
#define HSIOM_PRT6                              ((HSIOM_PRT_Type*) &HSIOM->PRT[6])                                /* 0x40300060 */
#define HSIOM_PRT7                              ((HSIOM_PRT_Type*) &HSIOM->PRT[7])                                /* 0x40300070 */
#define HSIOM_PRT8                              ((HSIOM_PRT_Type*) &HSIOM->PRT[8])                                /* 0x40300080 */
#define HSIOM_PRT9                              ((HSIOM_PRT_Type*) &HSIOM->PRT[9])                                /* 0x40300090 */
#define HSIOM_PRT10                             ((HSIOM_PRT_Type*) &HSIOM->PRT[10])                               /* 0x403000A0 */
#define HSIOM_PRT11                             ((HSIOM_PRT_Type*) &HSIOM->PRT[11])                               /* 0x403000B0 */
#define HSIOM_PRT12                             ((HSIOM_PRT_Type*) &HSIOM->PRT[12])                               /* 0x403000C0 */
#define HSIOM_PRT13                             ((HSIOM_PRT_Type*) &HSIOM->PRT[13])                               /* 0x403000D0 */
#define HSIOM_PRT14                             ((HSIOM_PRT_Type*) &HSIOM->PRT[14])                               /* 0x403000E0 */
#define HSIOM_PRT15                             ((HSIOM_PRT_Type*) &HSIOM->PRT[15])                               /* 0x403000F0 */
#define HSIOM_PRT16                             ((HSIOM_PRT_Type*) &HSIOM->PRT[16])                               /* 0x40300100 */
#define HSIOM_PRT17                             ((HSIOM_PRT_Type*) &HSIOM->PRT[17])                               /* 0x40300110 */
#define HSIOM_PRT18                             ((HSIOM_PRT_Type*) &HSIOM->PRT[18])                               /* 0x40300120 */
#define HSIOM_PRT19                             ((HSIOM_PRT_Type*) &HSIOM->PRT[19])                               /* 0x40300130 */
#define HSIOM_PRT20                             ((HSIOM_PRT_Type*) &HSIOM->PRT[20])                               /* 0x40300140 */
#define HSIOM_PRT21                             ((HSIOM_PRT_Type*) &HSIOM->PRT[21])                               /* 0x40300150 */
#define HSIOM_PRT22                             ((HSIOM_PRT_Type*) &HSIOM->PRT[22])                               /* 0x40300160 */
#define HSIOM_PRT23                             ((HSIOM_PRT_Type*) &HSIOM->PRT[23])                               /* 0x40300170 */
#define HSIOM_PRT24                             ((HSIOM_PRT_Type*) &HSIOM->PRT[24])                               /* 0x40300180 */
#define HSIOM_PRT25                             ((HSIOM_PRT_Type*) &HSIOM->PRT[25])                               /* 0x40300190 */
#define HSIOM_PRT26                             ((HSIOM_PRT_Type*) &HSIOM->PRT[26])                               /* 0x403001A0 */
#define HSIOM_PRT27                             ((HSIOM_PRT_Type*) &HSIOM->PRT[27])                               /* 0x403001B0 */
#define HSIOM_PRT28                             ((HSIOM_PRT_Type*) &HSIOM->PRT[28])                               /* 0x403001C0 */
#define HSIOM_PRT29                             ((HSIOM_PRT_Type*) &HSIOM->PRT[29])                               /* 0x403001D0 */
#define HSIOM_PRT30                             ((HSIOM_PRT_Type*) &HSIOM->PRT[30])                               /* 0x403001E0 */

/*******************************************************************************
*                                     GPIO
*******************************************************************************/

#define GPIO_BASE                               0x40310000UL
#define GPIO                                    ((GPIO_Type*) GPIO_BASE)                                          /* 0x40310000 */
#define GPIO_PRT0                               ((GPIO_PRT_Type*) &GPIO->PRT[0])                                  /* 0x40310000 */
#define GPIO_PRT1                               ((GPIO_PRT_Type*) &GPIO->PRT[1])                                  /* 0x40310080 */
#define GPIO_PRT2                               ((GPIO_PRT_Type*) &GPIO->PRT[2])                                  /* 0x40310100 */
#define GPIO_PRT3                               ((GPIO_PRT_Type*) &GPIO->PRT[3])                                  /* 0x40310180 */
#define GPIO_PRT4                               ((GPIO_PRT_Type*) &GPIO->PRT[4])                                  /* 0x40310200 */
#define GPIO_PRT5                               ((GPIO_PRT_Type*) &GPIO->PRT[5])                                  /* 0x40310280 */
#define GPIO_PRT6                               ((GPIO_PRT_Type*) &GPIO->PRT[6])                                  /* 0x40310300 */
#define GPIO_PRT7                               ((GPIO_PRT_Type*) &GPIO->PRT[7])                                  /* 0x40310380 */
#define GPIO_PRT8                               ((GPIO_PRT_Type*) &GPIO->PRT[8])                                  /* 0x40310400 */
#define GPIO_PRT9                               ((GPIO_PRT_Type*) &GPIO->PRT[9])                                  /* 0x40310480 */
#define GPIO_PRT10                              ((GPIO_PRT_Type*) &GPIO->PRT[10])                                 /* 0x40310500 */
#define GPIO_PRT11                              ((GPIO_PRT_Type*) &GPIO->PRT[11])                                 /* 0x40310580 */
#define GPIO_PRT12                              ((GPIO_PRT_Type*) &GPIO->PRT[12])                                 /* 0x40310600 */
#define GPIO_PRT13                              ((GPIO_PRT_Type*) &GPIO->PRT[13])                                 /* 0x40310680 */
#define GPIO_PRT14                              ((GPIO_PRT_Type*) &GPIO->PRT[14])                                 /* 0x40310700 */
#define GPIO_PRT15                              ((GPIO_PRT_Type*) &GPIO->PRT[15])                                 /* 0x40310780 */
#define GPIO_PRT16                              ((GPIO_PRT_Type*) &GPIO->PRT[16])                                 /* 0x40310800 */
#define GPIO_PRT17                              ((GPIO_PRT_Type*) &GPIO->PRT[17])                                 /* 0x40310880 */
#define GPIO_PRT18                              ((GPIO_PRT_Type*) &GPIO->PRT[18])                                 /* 0x40310900 */
#define GPIO_PRT19                              ((GPIO_PRT_Type*) &GPIO->PRT[19])                                 /* 0x40310980 */
#define GPIO_PRT20                              ((GPIO_PRT_Type*) &GPIO->PRT[20])                                 /* 0x40310A00 */
#define GPIO_PRT21                              ((GPIO_PRT_Type*) &GPIO->PRT[21])                                 /* 0x40310A80 */
#define GPIO_PRT22                              ((GPIO_PRT_Type*) &GPIO->PRT[22])                                 /* 0x40310B00 */
#define GPIO_PRT23                              ((GPIO_PRT_Type*) &GPIO->PRT[23])                                 /* 0x40310B80 */
#define GPIO_PRT24                              ((GPIO_PRT_Type*) &GPIO->PRT[24])                                 /* 0x40310C00 */
#define GPIO_PRT25                              ((GPIO_PRT_Type*) &GPIO->PRT[25])                                 /* 0x40310C80 */
#define GPIO_PRT26                              ((GPIO_PRT_Type*) &GPIO->PRT[26])                                 /* 0x40310D00 */
#define GPIO_PRT27                              ((GPIO_PRT_Type*) &GPIO->PRT[27])                                 /* 0x40310D80 */
#define GPIO_PRT28                              ((GPIO_PRT_Type*) &GPIO->PRT[28])                                 /* 0x40310E00 */
#define GPIO_PRT29                              ((GPIO_PRT_Type*) &GPIO->PRT[29])                                 /* 0x40310E80 */
#define GPIO_PRT30                              ((GPIO_PRT_Type*) &GPIO->PRT[30])                                 /* 0x40310F00 */

/*******************************************************************************
*                                   SMARTIO
*******************************************************************************/

#define SMARTIO_BASE                            0x40320000UL
#define SMARTIO                                 ((SMARTIO_Type*) SMARTIO_BASE)                                    /* 0x40320000 */
#define SMARTIO_PRT7                            ((SMARTIO_PRT_Type*) &SMARTIO->PRT[7])                            /* 0x40320700 */

/*******************************************************************************
*                                    TCPWM
*******************************************************************************/

#define TCPWM0_BASE                             0x40380000UL
#define TCPWM0                                  ((TCPWM_Type*) TCPWM0_BASE)                                       /* 0x40380000 */
#define TCPWM0_GRP0                             ((TCPWM_GRP_Type*) &TCPWM0->GRP[0])                               /* 0x40380000 */
#define TCPWM0_GRP1                             ((TCPWM_GRP_Type*) &TCPWM0->GRP[1])                               /* 0x40388000 */
#define TCPWM0_GRP2                             ((TCPWM_GRP_Type*) &TCPWM0->GRP[2])                               /* 0x40390000 */
#define TCPWM0_GRP0_CNT0                        ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[0].CNT[0])                    /* 0x40380000 */
#define TCPWM0_GRP0_CNT1                        ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[0].CNT[1])                    /* 0x40380080 */
#define TCPWM0_GRP0_CNT2                        ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[0].CNT[2])                    /* 0x40380100 */
#define TCPWM0_GRP0_CNT3                        ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[0].CNT[3])                    /* 0x40380180 */
#define TCPWM0_GRP0_CNT4                        ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[0].CNT[4])                    /* 0x40380200 */
#define TCPWM0_GRP0_CNT5                        ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[0].CNT[5])                    /* 0x40380280 */
#define TCPWM0_GRP0_CNT6                        ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[0].CNT[6])                    /* 0x40380300 */
#define TCPWM0_GRP0_CNT7                        ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[0].CNT[7])                    /* 0x40380380 */
#define TCPWM0_GRP0_CNT8                        ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[0].CNT[8])                    /* 0x40380400 */
#define TCPWM0_GRP0_CNT9                        ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[0].CNT[9])                    /* 0x40380480 */
#define TCPWM0_GRP0_CNT10                       ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[0].CNT[10])                   /* 0x40380500 */
#define TCPWM0_GRP0_CNT11                       ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[0].CNT[11])                   /* 0x40380580 */
#define TCPWM0_GRP0_CNT12                       ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[0].CNT[12])                   /* 0x40380600 */
#define TCPWM0_GRP0_CNT13                       ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[0].CNT[13])                   /* 0x40380680 */
#define TCPWM0_GRP0_CNT14                       ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[0].CNT[14])                   /* 0x40380700 */
#define TCPWM0_GRP0_CNT15                       ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[0].CNT[15])                   /* 0x40380780 */
#define TCPWM0_GRP0_CNT16                       ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[0].CNT[16])                   /* 0x40380800 */
#define TCPWM0_GRP0_CNT17                       ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[0].CNT[17])                   /* 0x40380880 */
#define TCPWM0_GRP0_CNT18                       ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[0].CNT[18])                   /* 0x40380900 */
#define TCPWM0_GRP0_CNT19                       ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[0].CNT[19])                   /* 0x40380980 */
#define TCPWM0_GRP0_CNT20                       ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[0].CNT[20])                   /* 0x40380A00 */
#define TCPWM0_GRP0_CNT21                       ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[0].CNT[21])                   /* 0x40380A80 */
#define TCPWM0_GRP0_CNT22                       ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[0].CNT[22])                   /* 0x40380B00 */
#define TCPWM0_GRP0_CNT23                       ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[0].CNT[23])                   /* 0x40380B80 */
#define TCPWM0_GRP0_CNT24                       ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[0].CNT[24])                   /* 0x40380C00 */
#define TCPWM0_GRP0_CNT25                       ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[0].CNT[25])                   /* 0x40380C80 */
#define TCPWM0_GRP0_CNT26                       ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[0].CNT[26])                   /* 0x40380D00 */
#define TCPWM0_GRP0_CNT27                       ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[0].CNT[27])                   /* 0x40380D80 */
#define TCPWM0_GRP0_CNT28                       ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[0].CNT[28])                   /* 0x40380E00 */
#define TCPWM0_GRP0_CNT29                       ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[0].CNT[29])                   /* 0x40380E80 */
#define TCPWM0_GRP0_CNT30                       ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[0].CNT[30])                   /* 0x40380F00 */
#define TCPWM0_GRP0_CNT31                       ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[0].CNT[31])                   /* 0x40380F80 */
#define TCPWM0_GRP0_CNT32                       ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[0].CNT[32])                   /* 0x40381000 */
#define TCPWM0_GRP0_CNT33                       ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[0].CNT[33])                   /* 0x40381080 */
#define TCPWM0_GRP0_CNT34                       ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[0].CNT[34])                   /* 0x40381100 */
#define TCPWM0_GRP0_CNT35                       ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[0].CNT[35])                   /* 0x40381180 */
#define TCPWM0_GRP0_CNT36                       ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[0].CNT[36])                   /* 0x40381200 */
#define TCPWM0_GRP0_CNT37                       ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[0].CNT[37])                   /* 0x40381280 */
#define TCPWM0_GRP1_CNT0                        ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[1].CNT[0])                    /* 0x40388000 */
#define TCPWM0_GRP1_CNT1                        ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[1].CNT[1])                    /* 0x40388080 */
#define TCPWM0_GRP1_CNT2                        ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[1].CNT[2])                    /* 0x40388100 */
#define TCPWM0_GRP1_CNT3                        ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[1].CNT[3])                    /* 0x40388180 */
#define TCPWM0_GRP1_CNT4                        ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[1].CNT[4])                    /* 0x40388200 */
#define TCPWM0_GRP1_CNT5                        ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[1].CNT[5])                    /* 0x40388280 */
#define TCPWM0_GRP1_CNT6                        ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[1].CNT[6])                    /* 0x40388300 */
#define TCPWM0_GRP1_CNT7                        ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[1].CNT[7])                    /* 0x40388380 */
#define TCPWM0_GRP1_CNT8                        ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[1].CNT[8])                    /* 0x40388400 */
#define TCPWM0_GRP1_CNT9                        ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[1].CNT[9])                    /* 0x40388480 */
#define TCPWM0_GRP1_CNT10                       ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[1].CNT[10])                   /* 0x40388500 */
#define TCPWM0_GRP1_CNT11                       ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[1].CNT[11])                   /* 0x40388580 */
#define TCPWM0_GRP2_CNT0                        ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[2].CNT[0])                    /* 0x40390000 */
#define TCPWM0_GRP2_CNT1                        ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[2].CNT[1])                    /* 0x40390080 */
#define TCPWM0_GRP2_CNT2                        ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[2].CNT[2])                    /* 0x40390100 */
#define TCPWM0_GRP2_CNT3                        ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[2].CNT[3])                    /* 0x40390180 */
#define TCPWM0_GRP2_CNT4                        ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[2].CNT[4])                    /* 0x40390200 */
#define TCPWM0_GRP2_CNT5                        ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[2].CNT[5])                    /* 0x40390280 */
#define TCPWM0_GRP2_CNT6                        ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[2].CNT[6])                    /* 0x40390300 */
#define TCPWM0_GRP2_CNT7                        ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[2].CNT[7])                    /* 0x40390380 */
#define TCPWM0_GRP2_CNT8                        ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[2].CNT[8])                    /* 0x40390400 */
#define TCPWM0_GRP2_CNT9                        ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[2].CNT[9])                    /* 0x40390480 */
#define TCPWM0_GRP2_CNT10                       ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[2].CNT[10])                   /* 0x40390500 */
#define TCPWM0_GRP2_CNT11                       ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[2].CNT[11])                   /* 0x40390580 */
#define TCPWM0_GRP2_CNT12                       ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[2].CNT[12])                   /* 0x40390600 */
#define TCPWM0_GRP2_CNT13                       ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[2].CNT[13])                   /* 0x40390680 */
#define TCPWM0_GRP2_CNT14                       ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[2].CNT[14])                   /* 0x40390700 */
#define TCPWM0_GRP2_CNT15                       ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[2].CNT[15])                   /* 0x40390780 */
#define TCPWM0_GRP2_CNT16                       ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[2].CNT[16])                   /* 0x40390800 */
#define TCPWM0_GRP2_CNT17                       ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[2].CNT[17])                   /* 0x40390880 */
#define TCPWM0_GRP2_CNT18                       ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[2].CNT[18])                   /* 0x40390900 */
#define TCPWM0_GRP2_CNT19                       ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[2].CNT[19])                   /* 0x40390980 */
#define TCPWM0_GRP2_CNT20                       ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[2].CNT[20])                   /* 0x40390A00 */
#define TCPWM0_GRP2_CNT21                       ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[2].CNT[21])                   /* 0x40390A80 */
#define TCPWM0_GRP2_CNT22                       ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[2].CNT[22])                   /* 0x40390B00 */
#define TCPWM0_GRP2_CNT23                       ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[2].CNT[23])                   /* 0x40390B80 */
#define TCPWM0_GRP2_CNT24                       ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[2].CNT[24])                   /* 0x40390C00 */
#define TCPWM0_GRP2_CNT25                       ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[2].CNT[25])                   /* 0x40390C80 */
#define TCPWM0_GRP2_CNT26                       ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[2].CNT[26])                   /* 0x40390D00 */
#define TCPWM0_GRP2_CNT27                       ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[2].CNT[27])                   /* 0x40390D80 */
#define TCPWM0_GRP2_CNT28                       ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[2].CNT[28])                   /* 0x40390E00 */
#define TCPWM0_GRP2_CNT29                       ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[2].CNT[29])                   /* 0x40390E80 */
#define TCPWM0_GRP2_CNT30                       ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[2].CNT[30])                   /* 0x40390F00 */
#define TCPWM0_GRP2_CNT31                       ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[2].CNT[31])                   /* 0x40390F80 */

/*******************************************************************************
*                                    EVTGEN
*******************************************************************************/

#define EVTGEN0_BASE                            0x403F0000UL
#define EVTGEN0                                 ((EVTGEN_Type*) EVTGEN0_BASE)                                     /* 0x403F0000 */
#define EVTGEN0_COMP_STRUCT0                    ((EVTGEN_COMP_STRUCT_Type*) &EVTGEN0->COMP_STRUCT[0])             /* 0x403F0800 */
#define EVTGEN0_COMP_STRUCT1                    ((EVTGEN_COMP_STRUCT_Type*) &EVTGEN0->COMP_STRUCT[1])             /* 0x403F0820 */
#define EVTGEN0_COMP_STRUCT2                    ((EVTGEN_COMP_STRUCT_Type*) &EVTGEN0->COMP_STRUCT[2])             /* 0x403F0840 */
#define EVTGEN0_COMP_STRUCT3                    ((EVTGEN_COMP_STRUCT_Type*) &EVTGEN0->COMP_STRUCT[3])             /* 0x403F0860 */
#define EVTGEN0_COMP_STRUCT4                    ((EVTGEN_COMP_STRUCT_Type*) &EVTGEN0->COMP_STRUCT[4])             /* 0x403F0880 */
#define EVTGEN0_COMP_STRUCT5                    ((EVTGEN_COMP_STRUCT_Type*) &EVTGEN0->COMP_STRUCT[5])             /* 0x403F08A0 */
#define EVTGEN0_COMP_STRUCT6                    ((EVTGEN_COMP_STRUCT_Type*) &EVTGEN0->COMP_STRUCT[6])             /* 0x403F08C0 */
#define EVTGEN0_COMP_STRUCT7                    ((EVTGEN_COMP_STRUCT_Type*) &EVTGEN0->COMP_STRUCT[7])             /* 0x403F08E0 */
#define EVTGEN0_COMP_STRUCT8                    ((EVTGEN_COMP_STRUCT_Type*) &EVTGEN0->COMP_STRUCT[8])             /* 0x403F0900 */
#define EVTGEN0_COMP_STRUCT9                    ((EVTGEN_COMP_STRUCT_Type*) &EVTGEN0->COMP_STRUCT[9])             /* 0x403F0920 */
#define EVTGEN0_COMP_STRUCT10                   ((EVTGEN_COMP_STRUCT_Type*) &EVTGEN0->COMP_STRUCT[10])            /* 0x403F0940 */
#define EVTGEN0_COMP_STRUCT11                   ((EVTGEN_COMP_STRUCT_Type*) &EVTGEN0->COMP_STRUCT[11])            /* 0x403F0960 */
#define EVTGEN0_COMP_STRUCT12                   ((EVTGEN_COMP_STRUCT_Type*) &EVTGEN0->COMP_STRUCT[12])            /* 0x403F0980 */
#define EVTGEN0_COMP_STRUCT13                   ((EVTGEN_COMP_STRUCT_Type*) &EVTGEN0->COMP_STRUCT[13])            /* 0x403F09A0 */
#define EVTGEN0_COMP_STRUCT14                   ((EVTGEN_COMP_STRUCT_Type*) &EVTGEN0->COMP_STRUCT[14])            /* 0x403F09C0 */
#define EVTGEN0_COMP_STRUCT15                   ((EVTGEN_COMP_STRUCT_Type*) &EVTGEN0->COMP_STRUCT[15])            /* 0x403F09E0 */

/*******************************************************************************
*                                     SMIF
*******************************************************************************/

#define SMIF0_BASE                              0x40400000UL
#define SMIF0                                   ((SMIF_STRUCT_Type*) SMIF0_BASE)                                  /* 0x40400000 */
#define SMIF0_SMIF_BRIDGE                       ((SMIF_SMIF_BRIDGE_Type*) &SMIF0->SMIF_BRIDGE)                    /* 0x40400000 */
#define SMIF0_SMIF_BRIDGE_SMIF_REMAP_REGION0    ((SMIF_SMIF_BRIDGE_SMIF_REMAP_REGION_Type*) &SMIF0->SMIF_BRIDGE.SMIF_REMAP_REGION[0]) /* 0x40401000 */
#define SMIF0_SMIF_BRIDGE_SMIF_REMAP_REGION1    ((SMIF_SMIF_BRIDGE_SMIF_REMAP_REGION_Type*) &SMIF0->SMIF_BRIDGE.SMIF_REMAP_REGION[1]) /* 0x40401100 */
#define SMIF0_SMIF_BRIDGE_SMIF_REMAP_REGION2    ((SMIF_SMIF_BRIDGE_SMIF_REMAP_REGION_Type*) &SMIF0->SMIF_BRIDGE.SMIF_REMAP_REGION[2]) /* 0x40401200 */
#define SMIF0_SMIF_BRIDGE_SMIF_REMAP_REGION3    ((SMIF_SMIF_BRIDGE_SMIF_REMAP_REGION_Type*) &SMIF0->SMIF_BRIDGE.SMIF_REMAP_REGION[3]) /* 0x40401300 */
#define SMIF0_SMIF_BRIDGE_SMIF_REMAP_REGION4    ((SMIF_SMIF_BRIDGE_SMIF_REMAP_REGION_Type*) &SMIF0->SMIF_BRIDGE.SMIF_REMAP_REGION[4]) /* 0x40401400 */
#define SMIF0_SMIF_BRIDGE_SMIF_REMAP_REGION5    ((SMIF_SMIF_BRIDGE_SMIF_REMAP_REGION_Type*) &SMIF0->SMIF_BRIDGE.SMIF_REMAP_REGION[5]) /* 0x40401500 */
#define SMIF0_SMIF_BRIDGE_SMIF_REMAP_REGION6    ((SMIF_SMIF_BRIDGE_SMIF_REMAP_REGION_Type*) &SMIF0->SMIF_BRIDGE.SMIF_REMAP_REGION[6]) /* 0x40401600 */
#define SMIF0_SMIF_BRIDGE_SMIF_REMAP_REGION7    ((SMIF_SMIF_BRIDGE_SMIF_REMAP_REGION_Type*) &SMIF0->SMIF_BRIDGE.SMIF_REMAP_REGION[7]) /* 0x40401700 */
#define SMIF0_CORE0                             ((SMIF_CORE_Type*) &SMIF0->CORE[0])                               /* 0x40420000 */
#define SMIF0_CORE1                             ((SMIF_CORE_Type*) &SMIF0->CORE[1])                               /* 0x40430000 */
#define SMIF0_CORE0_SMIF_CRYPTO0                ((SMIF_CORE_SMIF_CRYPTO_Type*) &SMIF0->CORE[0].SMIF_CRYPTO_BLOCK[0]) /* 0x40420200 */
#define SMIF0_CORE0_SMIF_CRYPTO1                ((SMIF_CORE_SMIF_CRYPTO_Type*) &SMIF0->CORE[0].SMIF_CRYPTO_BLOCK[1]) /* 0x40420280 */
#define SMIF0_CORE0_SMIF_CRYPTO2                ((SMIF_CORE_SMIF_CRYPTO_Type*) &SMIF0->CORE[0].SMIF_CRYPTO_BLOCK[2]) /* 0x40420300 */
#define SMIF0_CORE0_SMIF_CRYPTO3                ((SMIF_CORE_SMIF_CRYPTO_Type*) &SMIF0->CORE[0].SMIF_CRYPTO_BLOCK[3]) /* 0x40420380 */
#define SMIF0_CORE1_SMIF_CRYPTO0                ((SMIF_CORE_SMIF_CRYPTO_Type*) &SMIF0->CORE[1].SMIF_CRYPTO_BLOCK[0]) /* 0x40430200 */
#define SMIF0_CORE1_SMIF_CRYPTO1                ((SMIF_CORE_SMIF_CRYPTO_Type*) &SMIF0->CORE[1].SMIF_CRYPTO_BLOCK[1]) /* 0x40430280 */
#define SMIF0_CORE1_SMIF_CRYPTO2                ((SMIF_CORE_SMIF_CRYPTO_Type*) &SMIF0->CORE[1].SMIF_CRYPTO_BLOCK[2]) /* 0x40430300 */
#define SMIF0_CORE1_SMIF_CRYPTO3                ((SMIF_CORE_SMIF_CRYPTO_Type*) &SMIF0->CORE[1].SMIF_CRYPTO_BLOCK[3]) /* 0x40430380 */
#define SMIF0_CORE0_DEVICE0                     ((SMIF_CORE_DEVICE_Type*) &SMIF0->CORE[0].DEVICE[0])              /* 0x40420800 */
#define SMIF0_CORE0_DEVICE1                     ((SMIF_CORE_DEVICE_Type*) &SMIF0->CORE[0].DEVICE[1])              /* 0x40420880 */
#define SMIF0_CORE1_DEVICE0                     ((SMIF_CORE_DEVICE_Type*) &SMIF0->CORE[1].DEVICE[0])              /* 0x40430800 */
#define SMIF0_CORE1_DEVICE1                     ((SMIF_CORE_DEVICE_Type*) &SMIF0->CORE[1].DEVICE[1])              /* 0x40430880 */

/*******************************************************************************
*                                     ETH
*******************************************************************************/

#define ETH0_BASE                               0x40480000UL
#define ETH0                                    ((ETH_Type*) ETH0_BASE)                                           /* 0x40480000 */

/*******************************************************************************
*                                     LIN
*******************************************************************************/

#define LIN0_BASE                               0x40500000UL
#define LIN0                                    ((LIN_Type*) LIN0_BASE)                                           /* 0x40500000 */
#define LIN0_CH0                                ((LIN_CH_Type*) &LIN0->CH[0])                                     /* 0x40508000 */
#define LIN0_CH1                                ((LIN_CH_Type*) &LIN0->CH[1])                                     /* 0x40508100 */

/*******************************************************************************
*                                     CXPI
*******************************************************************************/

#define CXPI0_BASE                              0x40510000UL
#define CXPI0                                   ((CXPI_Type*) CXPI0_BASE)                                         /* 0x40510000 */
#define CXPI0_CH0                               ((CXPI_CH_Type*) &CXPI0->CH[0])                                   /* 0x40518000 */
#define CXPI0_CH1                               ((CXPI_CH_Type*) &CXPI0->CH[1])                                   /* 0x40518100 */

/*******************************************************************************
*                                    CANFD
*******************************************************************************/

#define CANFD0_BASE                             0x40520000UL
#define CANFD1_BASE                             0x40540000UL
#define CANFD0                                  ((CANFD_Type*) CANFD0_BASE)                                       /* 0x40520000 */
#define CANFD1                                  ((CANFD_Type*) CANFD1_BASE)                                       /* 0x40540000 */
#define CANFD0_CH0                              ((CANFD_CH_Type*) &CANFD0->CH[0])                                 /* 0x40520000 */
#define CANFD0_CH1                              ((CANFD_CH_Type*) &CANFD0->CH[1])                                 /* 0x40520200 */
#define CANFD1_CH0                              ((CANFD_CH_Type*) &CANFD1->CH[0])                                 /* 0x40540000 */
#define CANFD1_CH1                              ((CANFD_CH_Type*) &CANFD1->CH[1])                                 /* 0x40540200 */
#define CANFD0_CH0_M_TTCAN                      ((CANFD_CH_M_TTCAN_Type*) &CANFD0->CH[0].M_TTCAN)                 /* 0x40520000 */
#define CANFD0_CH1_M_TTCAN                      ((CANFD_CH_M_TTCAN_Type*) &CANFD0->CH[1].M_TTCAN)                 /* 0x40520200 */
#define CANFD1_CH0_M_TTCAN                      ((CANFD_CH_M_TTCAN_Type*) &CANFD1->CH[0].M_TTCAN)                 /* 0x40540000 */
#define CANFD1_CH1_M_TTCAN                      ((CANFD_CH_M_TTCAN_Type*) &CANFD1->CH[1].M_TTCAN)                 /* 0x40540200 */

/*******************************************************************************
*                                     SCB
*******************************************************************************/

#define SCB0_BASE                               0x40600000UL
#define SCB1_BASE                               0x40610000UL
#define SCB2_BASE                               0x40620000UL
#define SCB3_BASE                               0x40630000UL
#define SCB4_BASE                               0x40640000UL
#define SCB5_BASE                               0x40650000UL
#define SCB6_BASE                               0x40660000UL
#define SCB7_BASE                               0x40670000UL
#define SCB8_BASE                               0x40680000UL
#define SCB9_BASE                               0x40690000UL
#define SCB10_BASE                              0x406A0000UL
#define SCB11_BASE                              0x406B0000UL
#define SCB0                                    ((CySCB_Type*) SCB0_BASE)                                         /* 0x40600000 */
#define SCB1                                    ((CySCB_Type*) SCB1_BASE)                                         /* 0x40610000 */
#define SCB2                                    ((CySCB_Type*) SCB2_BASE)                                         /* 0x40620000 */
#define SCB3                                    ((CySCB_Type*) SCB3_BASE)                                         /* 0x40630000 */
#define SCB4                                    ((CySCB_Type*) SCB4_BASE)                                         /* 0x40640000 */
#define SCB5                                    ((CySCB_Type*) SCB5_BASE)                                         /* 0x40650000 */
#define SCB6                                    ((CySCB_Type*) SCB6_BASE)                                         /* 0x40660000 */
#define SCB7                                    ((CySCB_Type*) SCB7_BASE)                                         /* 0x40670000 */
#define SCB8                                    ((CySCB_Type*) SCB8_BASE)                                         /* 0x40680000 */
#define SCB9                                    ((CySCB_Type*) SCB9_BASE)                                         /* 0x40690000 */
#define SCB10                                   ((CySCB_Type*) SCB10_BASE)                                        /* 0x406A0000 */
#define SCB11                                   ((CySCB_Type*) SCB11_BASE)                                        /* 0x406B0000 */

/*******************************************************************************
*                                     TDM
*******************************************************************************/

#define TDM0_BASE                               0x40810000UL
#define TDM0                                    ((TDM_Type*) TDM0_BASE)                                           /* 0x40810000 */
#define TDM0_TDM_STRUCT0                        ((TDM_TDM_STRUCT_Type*) &TDM0->TDM_STRUCT[0])                     /* 0x40818000 */
#define TDM0_TDM_STRUCT1                        ((TDM_TDM_STRUCT_Type*) &TDM0->TDM_STRUCT[1])                     /* 0x40818200 */
#define TDM0_TDM_STRUCT2                        ((TDM_TDM_STRUCT_Type*) &TDM0->TDM_STRUCT[2])                     /* 0x40818400 */
#define TDM0_TDM_STRUCT3                        ((TDM_TDM_STRUCT_Type*) &TDM0->TDM_STRUCT[3])                     /* 0x40818600 */
#define TDM0_TDM_STRUCT0_TDM_TX_STRUCT          ((TDM_TDM_STRUCT_TDM_TX_STRUCT_Type*) &TDM0->TDM_STRUCT[0].TDM_TX_STRUCT) /* 0x40818000 */
#define TDM0_TDM_STRUCT1_TDM_TX_STRUCT          ((TDM_TDM_STRUCT_TDM_TX_STRUCT_Type*) &TDM0->TDM_STRUCT[1].TDM_TX_STRUCT) /* 0x40818200 */
#define TDM0_TDM_STRUCT2_TDM_TX_STRUCT          ((TDM_TDM_STRUCT_TDM_TX_STRUCT_Type*) &TDM0->TDM_STRUCT[2].TDM_TX_STRUCT) /* 0x40818400 */
#define TDM0_TDM_STRUCT3_TDM_TX_STRUCT          ((TDM_TDM_STRUCT_TDM_TX_STRUCT_Type*) &TDM0->TDM_STRUCT[3].TDM_TX_STRUCT) /* 0x40818600 */
#define TDM0_TDM_STRUCT0_TDM_RX_STRUCT          ((TDM_TDM_STRUCT_TDM_RX_STRUCT_Type*) &TDM0->TDM_STRUCT[0].TDM_RX_STRUCT) /* 0x40818100 */
#define TDM0_TDM_STRUCT1_TDM_RX_STRUCT          ((TDM_TDM_STRUCT_TDM_RX_STRUCT_Type*) &TDM0->TDM_STRUCT[1].TDM_RX_STRUCT) /* 0x40818300 */
#define TDM0_TDM_STRUCT2_TDM_RX_STRUCT          ((TDM_TDM_STRUCT_TDM_RX_STRUCT_Type*) &TDM0->TDM_STRUCT[2].TDM_RX_STRUCT) /* 0x40818500 */
#define TDM0_TDM_STRUCT3_TDM_RX_STRUCT          ((TDM_TDM_STRUCT_TDM_RX_STRUCT_Type*) &TDM0->TDM_STRUCT[3].TDM_RX_STRUCT) /* 0x40818700 */

/*******************************************************************************
*                                      SG
*******************************************************************************/

#define SG0_BASE                                0x40820000UL
#define SG0                                     ((SG_Type*) SG0_BASE)                                             /* 0x40820000 */
#define SG0_SG_STRUCT0                          ((SG_SG_STRUCT_Type*) &SG0->SG_STRUCT[0])                         /* 0x40828000 */
#define SG0_SG_STRUCT1                          ((SG_SG_STRUCT_Type*) &SG0->SG_STRUCT[1])                         /* 0x40828100 */
#define SG0_SG_STRUCT2                          ((SG_SG_STRUCT_Type*) &SG0->SG_STRUCT[2])                         /* 0x40828200 */
#define SG0_SG_STRUCT3                          ((SG_SG_STRUCT_Type*) &SG0->SG_STRUCT[3])                         /* 0x40828300 */
#define SG0_SG_STRUCT4                          ((SG_SG_STRUCT_Type*) &SG0->SG_STRUCT[4])                         /* 0x40828400 */

/*******************************************************************************
*                                     PWM
*******************************************************************************/

#define PWM0_BASE                               0x40830000UL
#define PWM0                                    ((PWM_Type*) PWM0_BASE)                                           /* 0x40830000 */
#define PWM0_TX0                                ((PWM_TX_Type*) &PWM0->TX[0])                                     /* 0x40838000 */
#define PWM0_TX1                                ((PWM_TX_Type*) &PWM0->TX[1])                                     /* 0x40838100 */

/*******************************************************************************
*                                     DAC
*******************************************************************************/

#define DAC0_BASE                               0x40840000UL
#define DAC0                                    ((DAC_Type*) DAC0_BASE)                                           /* 0x40840000 */

/*******************************************************************************
*                                    MIXER
*******************************************************************************/

#define MIXER0_BASE                             0x40880000UL
#define MIXER1_BASE                             0x40890000UL
#define MIXER0                                  ((MIXER_Type*) MIXER0_BASE)                                       /* 0x40880000 */
#define MIXER1                                  ((MIXER_Type*) MIXER1_BASE)                                       /* 0x40890000 */
#define MIXER0_MIXER_SRC_STRUCT0                ((MIXER_MIXER_SRC_STRUCT_Type*) &MIXER0->MIXER_SRC_STRUCT[0])     /* 0x40888000 */
#define MIXER0_MIXER_SRC_STRUCT1                ((MIXER_MIXER_SRC_STRUCT_Type*) &MIXER0->MIXER_SRC_STRUCT[1])     /* 0x40888100 */
#define MIXER0_MIXER_SRC_STRUCT2                ((MIXER_MIXER_SRC_STRUCT_Type*) &MIXER0->MIXER_SRC_STRUCT[2])     /* 0x40888200 */
#define MIXER0_MIXER_SRC_STRUCT3                ((MIXER_MIXER_SRC_STRUCT_Type*) &MIXER0->MIXER_SRC_STRUCT[3])     /* 0x40888300 */
#define MIXER0_MIXER_SRC_STRUCT4                ((MIXER_MIXER_SRC_STRUCT_Type*) &MIXER0->MIXER_SRC_STRUCT[4])     /* 0x40888400 */
#define MIXER1_MIXER_SRC_STRUCT0                ((MIXER_MIXER_SRC_STRUCT_Type*) &MIXER1->MIXER_SRC_STRUCT[0])     /* 0x40898000 */
#define MIXER1_MIXER_SRC_STRUCT1                ((MIXER_MIXER_SRC_STRUCT_Type*) &MIXER1->MIXER_SRC_STRUCT[1])     /* 0x40898100 */
#define MIXER1_MIXER_SRC_STRUCT2                ((MIXER_MIXER_SRC_STRUCT_Type*) &MIXER1->MIXER_SRC_STRUCT[2])     /* 0x40898200 */
#define MIXER1_MIXER_SRC_STRUCT3                ((MIXER_MIXER_SRC_STRUCT_Type*) &MIXER1->MIXER_SRC_STRUCT[3])     /* 0x40898300 */
#define MIXER1_MIXER_SRC_STRUCT4                ((MIXER_MIXER_SRC_STRUCT_Type*) &MIXER1->MIXER_SRC_STRUCT[4])     /* 0x40898400 */
#define MIXER0_MIXER_DST_STRUCT                 ((MIXER_MIXER_DST_STRUCT_Type*) &MIXER0->MIXER_DST_STRUCT)        /* 0x4088C000 */
#define MIXER1_MIXER_DST_STRUCT                 ((MIXER_MIXER_DST_STRUCT_Type*) &MIXER1->MIXER_DST_STRUCT)        /* 0x4089C000 */

/*******************************************************************************
*                                     PASS
*******************************************************************************/

#define PASS0_BASE                              0x40900000UL
#define PASS0                                   ((PASS_Type*) PASS0_BASE)                                         /* 0x40900000 */
#define PASS0_SAR0                              ((PASS_SAR_Type*) &PASS0->SAR[0])                                 /* 0x40900000 */
#define PASS0_SAR1                              ((PASS_SAR_Type*) &PASS0->SAR[1])                                 /* 0x40901000 */
#define PASS0_SAR0_CH0                          ((PASS_SAR_CH_Type*) &PASS0->SAR[0].CH[0])                        /* 0x40900800 */
#define PASS0_SAR0_CH1                          ((PASS_SAR_CH_Type*) &PASS0->SAR[0].CH[1])                        /* 0x40900840 */
#define PASS0_SAR0_CH2                          ((PASS_SAR_CH_Type*) &PASS0->SAR[0].CH[2])                        /* 0x40900880 */
#define PASS0_SAR0_CH3                          ((PASS_SAR_CH_Type*) &PASS0->SAR[0].CH[3])                        /* 0x409008C0 */
#define PASS0_SAR0_CH4                          ((PASS_SAR_CH_Type*) &PASS0->SAR[0].CH[4])                        /* 0x40900900 */
#define PASS0_SAR0_CH5                          ((PASS_SAR_CH_Type*) &PASS0->SAR[0].CH[5])                        /* 0x40900940 */
#define PASS0_SAR0_CH6                          ((PASS_SAR_CH_Type*) &PASS0->SAR[0].CH[6])                        /* 0x40900980 */
#define PASS0_SAR0_CH7                          ((PASS_SAR_CH_Type*) &PASS0->SAR[0].CH[7])                        /* 0x409009C0 */
#define PASS0_SAR0_CH8                          ((PASS_SAR_CH_Type*) &PASS0->SAR[0].CH[8])                        /* 0x40900A00 */
#define PASS0_SAR0_CH9                          ((PASS_SAR_CH_Type*) &PASS0->SAR[0].CH[9])                        /* 0x40900A40 */
#define PASS0_SAR0_CH10                         ((PASS_SAR_CH_Type*) &PASS0->SAR[0].CH[10])                       /* 0x40900A80 */
#define PASS0_SAR0_CH11                         ((PASS_SAR_CH_Type*) &PASS0->SAR[0].CH[11])                       /* 0x40900AC0 */
#define PASS0_SAR0_CH12                         ((PASS_SAR_CH_Type*) &PASS0->SAR[0].CH[12])                       /* 0x40900B00 */
#define PASS0_SAR0_CH13                         ((PASS_SAR_CH_Type*) &PASS0->SAR[0].CH[13])                       /* 0x40900B40 */
#define PASS0_SAR0_CH14                         ((PASS_SAR_CH_Type*) &PASS0->SAR[0].CH[14])                       /* 0x40900B80 */
#define PASS0_SAR0_CH15                         ((PASS_SAR_CH_Type*) &PASS0->SAR[0].CH[15])                       /* 0x40900BC0 */
#define PASS0_SAR0_CH16                         ((PASS_SAR_CH_Type*) &PASS0->SAR[0].CH[16])                       /* 0x40900C00 */
#define PASS0_SAR0_CH17                         ((PASS_SAR_CH_Type*) &PASS0->SAR[0].CH[17])                       /* 0x40900C40 */
#define PASS0_SAR0_CH18                         ((PASS_SAR_CH_Type*) &PASS0->SAR[0].CH[18])                       /* 0x40900C80 */
#define PASS0_SAR0_CH19                         ((PASS_SAR_CH_Type*) &PASS0->SAR[0].CH[19])                       /* 0x40900CC0 */
#define PASS0_SAR0_CH20                         ((PASS_SAR_CH_Type*) &PASS0->SAR[0].CH[20])                       /* 0x40900D00 */
#define PASS0_SAR0_CH21                         ((PASS_SAR_CH_Type*) &PASS0->SAR[0].CH[21])                       /* 0x40900D40 */
#define PASS0_SAR0_CH22                         ((PASS_SAR_CH_Type*) &PASS0->SAR[0].CH[22])                       /* 0x40900D80 */
#define PASS0_SAR0_CH23                         ((PASS_SAR_CH_Type*) &PASS0->SAR[0].CH[23])                       /* 0x40900DC0 */
#define PASS0_SAR0_CH24                         ((PASS_SAR_CH_Type*) &PASS0->SAR[0].CH[24])                       /* 0x40900E00 */
#define PASS0_SAR0_CH25                         ((PASS_SAR_CH_Type*) &PASS0->SAR[0].CH[25])                       /* 0x40900E40 */
#define PASS0_SAR0_CH26                         ((PASS_SAR_CH_Type*) &PASS0->SAR[0].CH[26])                       /* 0x40900E80 */
#define PASS0_SAR0_CH27                         ((PASS_SAR_CH_Type*) &PASS0->SAR[0].CH[27])                       /* 0x40900EC0 */
#define PASS0_SAR0_CH28                         ((PASS_SAR_CH_Type*) &PASS0->SAR[0].CH[28])                       /* 0x40900F00 */
#define PASS0_SAR0_CH29                         ((PASS_SAR_CH_Type*) &PASS0->SAR[0].CH[29])                       /* 0x40900F40 */
#define PASS0_SAR0_CH30                         ((PASS_SAR_CH_Type*) &PASS0->SAR[0].CH[30])                       /* 0x40900F80 */
#define PASS0_SAR0_CH31                         ((PASS_SAR_CH_Type*) &PASS0->SAR[0].CH[31])                       /* 0x40900FC0 */
#define PASS0_EPASS_MMIO                        ((PASS_EPASS_MMIO_Type*) &PASS0->EPASS_MMIO)                      /* 0x409F0000 */

/** \} CYT4DNJBBS */

#endif /* _CYT4DNJBBS_H_ */


/* [] END OF FILE */
