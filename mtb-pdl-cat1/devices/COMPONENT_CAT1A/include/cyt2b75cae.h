/***************************************************************************//**
* \file cyt2b75cae.h
*
* \brief
* CYT2B75CAE device header
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

#ifndef _CYT2B75CAE_H_
#define _CYT2B75CAE_H_

/**
* \addtogroup group_device CYT2B75CAE
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
  /* ARM Cortex-M4 Core Interrupt Numbers */
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
  /* CYT2B75CAE User Interrupt Numbers */
  NvicMux0_IRQn                     =   0,      /*!<   0 [DeepSleep] CPU User Interrupt #0 */
  NvicMux1_IRQn                     =   1,      /*!<   1 [DeepSleep] CPU User Interrupt #1 */
  NvicMux2_IRQn                     =   2,      /*!<   2 [DeepSleep] CPU User Interrupt #2 */
  NvicMux3_IRQn                     =   3,      /*!<   3 [DeepSleep] CPU User Interrupt #3 */
  NvicMux4_IRQn                     =   4,      /*!<   4 [DeepSleep] CPU User Interrupt #4 */
  NvicMux5_IRQn                     =   5,      /*!<   5 [DeepSleep] CPU User Interrupt #5 */
  NvicMux6_IRQn                     =   6,      /*!<   6 [DeepSleep] CPU User Interrupt #6 */
  NvicMux7_IRQn                     =   7,      /*!<   7 [DeepSleep] CPU User Interrupt #7 */
  /* CYT2B75CAE Internal SW Interrupt Numbers */
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


/* CYT2B75CAE peripheral interrupts */
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
  srss_interrupt_wdt_IRQn           =  15,      /*!<  15 [DeepSleep] Hardware Watchdog Timer interrupt */
  srss_interrupt_IRQn               =  16,      /*!<  16 [DeepSleep] Other combined Interrupts for SRSS (LVD, CLKCAL) */
  scb_0_interrupt_IRQn              =  17,      /*!<  17 [DeepSleep] Serial Communication Block #0 (DeepSleep capable) */
  evtgen_0_interrupt_dpslp_IRQn     =  18,      /*!<  18 [DeepSleep] Event gen Deep-sleep domain interrupt */
  ioss_interrupt_vdd_IRQn           =  19,      /*!<  19 [DeepSleep] GPIO Supply Detect Interrupt */
  ioss_interrupt_gpio_IRQn          =  20,      /*!<  20 [DeepSleep] Consolidated Interrupt for GPIO, All Ports */
  ioss_interrupts_gpio_0_IRQn       =  21,      /*!<  21 [DeepSleep] GPIO Port Interrupt #0 */
  ioss_interrupts_gpio_1_IRQn       =  22,      /*!<  22 [DeepSleep] GPIO Port Interrupt #1 */
  ioss_interrupts_gpio_2_IRQn       =  23,      /*!<  23 [DeepSleep] GPIO Port Interrupt #2 */
  ioss_interrupts_gpio_3_IRQn       =  24,      /*!<  24 [DeepSleep] GPIO Port Interrupt #3 */
  ioss_interrupts_gpio_4_IRQn       =  25,      /*!<  25 [DeepSleep] GPIO Port Interrupt #4 */
  ioss_interrupts_gpio_5_IRQn       =  26,      /*!<  26 [DeepSleep] GPIO Port Interrupt #5 */
  ioss_interrupts_gpio_6_IRQn       =  27,      /*!<  27 [DeepSleep] GPIO Port Interrupt #6 */
  ioss_interrupts_gpio_7_IRQn       =  28,      /*!<  28 [DeepSleep] GPIO Port Interrupt #7 */
  ioss_interrupts_gpio_8_IRQn       =  29,      /*!<  29 [DeepSleep] GPIO Port Interrupt #8 */
  ioss_interrupts_gpio_9_IRQn       =  30,      /*!<  30 [DeepSleep] GPIO Port Interrupt #9 */
  ioss_interrupts_gpio_10_IRQn      =  31,      /*!<  31 [DeepSleep] GPIO Port Interrupt #10 */
  ioss_interrupts_gpio_11_IRQn      =  32,      /*!<  32 [DeepSleep] GPIO Port Interrupt #11 */
  ioss_interrupts_gpio_12_IRQn      =  33,      /*!<  33 [DeepSleep] GPIO Port Interrupt #12 */
  ioss_interrupts_gpio_13_IRQn      =  34,      /*!<  34 [DeepSleep] GPIO Port Interrupt #13 */
  ioss_interrupts_gpio_14_IRQn      =  35,      /*!<  35 [DeepSleep] GPIO Port Interrupt #14 */
  ioss_interrupts_gpio_15_IRQn      =  36,      /*!<  36 [DeepSleep] GPIO Port Interrupt #15 */
  ioss_interrupts_gpio_16_IRQn      =  37,      /*!<  37 [DeepSleep] GPIO Port Interrupt #16 */
  ioss_interrupts_gpio_17_IRQn      =  38,      /*!<  38 [DeepSleep] GPIO Port Interrupt #17 */
  ioss_interrupts_gpio_18_IRQn      =  39,      /*!<  39 [DeepSleep] GPIO Port Interrupt #18 */
  ioss_interrupts_gpio_19_IRQn      =  40,      /*!<  40 [DeepSleep] GPIO Port Interrupt #19 */
  ioss_interrupts_gpio_20_IRQn      =  41,      /*!<  41 [DeepSleep] GPIO Port Interrupt #20 */
  ioss_interrupts_gpio_21_IRQn      =  42,      /*!<  42 [DeepSleep] GPIO Port Interrupt #21 */
  ioss_interrupts_gpio_22_IRQn      =  43,      /*!<  43 [DeepSleep] GPIO Port Interrupt #22 */
  ioss_interrupts_gpio_23_IRQn      =  44,      /*!<  44 [DeepSleep] GPIO Port Interrupt #23 */
  cpuss_interrupt_crypto_IRQn       =  45,      /*!<  45 [Active] CRYPTO Accelerator Interrupt */
  cpuss_interrupt_fm_IRQn           =  46,      /*!<  46 [Active] FLASH Macro Interrupt */
  cpuss_interrupts_cm4_fp_IRQn      =  47,      /*!<  47 [Active] Floating Point operation fault */
  cpuss_interrupts_cm0_cti_0_IRQn   =  48,      /*!<  48 [Active] CM0+ CTI #0 */
  cpuss_interrupts_cm0_cti_1_IRQn   =  49,      /*!<  49 [Active] CM0+ CTI #1 */
  cpuss_interrupts_cm4_cti_0_IRQn   =  50,      /*!<  50 [Active] CM4 CTI #0 */
  cpuss_interrupts_cm4_cti_1_IRQn   =  51,      /*!<  51 [Active] CM4 CTI #1 */
  evtgen_0_interrupt_IRQn           =  52,      /*!<  52 [Active] Event gen Active domain interrupt */
  canfd_0_interrupt0_IRQn           =  53,      /*!<  53 [Active] Can #0, Consolidated interrupt #0 for all three channels */
  canfd_0_interrupt1_IRQn           =  54,      /*!<  54 [Active] Can #0, Consolidated interrupt #1 for all three channels */
  canfd_1_interrupt0_IRQn           =  55,      /*!<  55 [Active] Can #1, Consolidated interrupt #0 for all three channels */
  canfd_1_interrupt1_IRQn           =  56,      /*!<  56 [Active] Can #1, Consolidated interrupt #1 for all three channels */
  canfd_0_interrupts0_0_IRQn        =  57,      /*!<  57 [Active] CAN #0, Interrupt #0, Channel #0 */
  canfd_0_interrupts0_1_IRQn        =  58,      /*!<  58 [Active] CAN #0, Interrupt #0, Channel #1 */
  canfd_0_interrupts0_2_IRQn        =  59,      /*!<  59 [Active] CAN #0, Interrupt #0, Channel #2 */
  canfd_0_interrupts1_0_IRQn        =  60,      /*!<  60 [Active] CAN #0, Interrupt #1, Channel #0 */
  canfd_0_interrupts1_1_IRQn        =  61,      /*!<  61 [Active] CAN #0, Interrupt #1, Channel #1 */
  canfd_0_interrupts1_2_IRQn        =  62,      /*!<  62 [Active] CAN #0, Interrupt #1, Channel #2 */
  canfd_1_interrupts0_0_IRQn        =  63,      /*!<  63 [Active] CAN #1, Interrupt #0, Channel #0 */
  canfd_1_interrupts0_1_IRQn        =  64,      /*!<  64 [Active] CAN #1, Interrupt #0, Channel #1 */
  canfd_1_interrupts0_2_IRQn        =  65,      /*!<  65 [Active] CAN #1, Interrupt #0, Channel #2 */
  canfd_1_interrupts1_0_IRQn        =  66,      /*!<  66 [Active] CAN #1, Interrupt #1, Channel #0 */
  canfd_1_interrupts1_1_IRQn        =  67,      /*!<  67 [Active] CAN #1, Interrupt #1, Channel #1 */
  canfd_1_interrupts1_2_IRQn        =  68,      /*!<  68 [Active] CAN #1, Interrupt #1, Channel #2 */
  lin_0_interrupts_0_IRQn           =  69,      /*!<  69 [Active] LIN Interrupt, Channel #0 */
  lin_0_interrupts_1_IRQn           =  70,      /*!<  70 [Active] LIN Interrupt, Channel #1 */
  lin_0_interrupts_2_IRQn           =  71,      /*!<  71 [Active] LIN Interrupt, Channel #2 */
  lin_0_interrupts_3_IRQn           =  72,      /*!<  72 [Active] LIN Interrupt, Channel #3 */
  lin_0_interrupts_4_IRQn           =  73,      /*!<  73 [Active] LIN Interrupt, Channel #4 */
  lin_0_interrupts_5_IRQn           =  74,      /*!<  74 [Active] LIN Interrupt, Channel #5 */
  lin_0_interrupts_6_IRQn           =  75,      /*!<  75 [Active] LIN Interrupt, Channel #6 */
  lin_0_interrupts_7_IRQn           =  76,      /*!<  76 [Active] LIN Interrupt, Channel #7 */
  scb_1_interrupt_IRQn              =  77,      /*!<  77 [Active] Serial Communication Block #1 */
  scb_2_interrupt_IRQn              =  78,      /*!<  78 [Active] Serial Communication Block #2 */
  scb_3_interrupt_IRQn              =  79,      /*!<  79 [Active] Serial Communication Block #3 */
  scb_4_interrupt_IRQn              =  80,      /*!<  80 [Active] Serial Communication Block #4 */
  scb_5_interrupt_IRQn              =  81,      /*!<  81 [Active] Serial Communication Block #5 */
  scb_6_interrupt_IRQn              =  82,      /*!<  82 [Active] Serial Communication Block #6 */
  scb_7_interrupt_IRQn              =  83,      /*!<  83 [Active] Serial Communication Block #7 */
  pass_0_interrupts_sar_0_IRQn      =  84,      /*!<  84 [Active] PASS interrupts, ADC #0, Channel #0 */
  pass_0_interrupts_sar_1_IRQn      =  85,      /*!<  85 [Active] PASS interrupts, ADC #0, Channel #1 */
  pass_0_interrupts_sar_2_IRQn      =  86,      /*!<  86 [Active] PASS interrupts, ADC #0, Channel #2 */
  pass_0_interrupts_sar_3_IRQn      =  87,      /*!<  87 [Active] PASS interrupts, ADC #0, Channel #3 */
  pass_0_interrupts_sar_4_IRQn      =  88,      /*!<  88 [Active] PASS interrupts, ADC #0, Channel #4 */
  pass_0_interrupts_sar_5_IRQn      =  89,      /*!<  89 [Active] PASS interrupts, ADC #0, Channel #5 */
  pass_0_interrupts_sar_6_IRQn      =  90,      /*!<  90 [Active] PASS interrupts, ADC #0, Channel #6 */
  pass_0_interrupts_sar_7_IRQn      =  91,      /*!<  91 [Active] PASS interrupts, ADC #0, Channel #7 */
  pass_0_interrupts_sar_8_IRQn      =  92,      /*!<  92 [Active] PASS interrupts, ADC #0, Channel #8 */
  pass_0_interrupts_sar_9_IRQn      =  93,      /*!<  93 [Active] PASS interrupts, ADC #0, Channel #9 */
  pass_0_interrupts_sar_10_IRQn     =  94,      /*!<  94 [Active] PASS interrupts, ADC #0, Channel #10 */
  pass_0_interrupts_sar_11_IRQn     =  95,      /*!<  95 [Active] PASS interrupts, ADC #0, Channel #11 */
  pass_0_interrupts_sar_12_IRQn     =  96,      /*!<  96 [Active] PASS interrupts, ADC #0, Channel #12 */
  pass_0_interrupts_sar_13_IRQn     =  97,      /*!<  97 [Active] PASS interrupts, ADC #0, Channel #13 */
  pass_0_interrupts_sar_14_IRQn     =  98,      /*!<  98 [Active] PASS interrupts, ADC #0, Channel #14 */
  pass_0_interrupts_sar_15_IRQn     =  99,      /*!<  99 [Active] PASS interrupts, ADC #0, Channel #15 */
  pass_0_interrupts_sar_16_IRQn     = 100,      /*!< 100 [Active] PASS interrupts, ADC #0, Channel #16 */
  pass_0_interrupts_sar_17_IRQn     = 101,      /*!< 101 [Active] PASS interrupts, ADC #0, Channel #17 */
  pass_0_interrupts_sar_18_IRQn     = 102,      /*!< 102 [Active] PASS interrupts, ADC #0, Channel #18 */
  pass_0_interrupts_sar_19_IRQn     = 103,      /*!< 103 [Active] PASS interrupts, ADC #0, Channel #19 */
  pass_0_interrupts_sar_20_IRQn     = 104,      /*!< 104 [Active] PASS interrupts, ADC #0, Channel #20 */
  pass_0_interrupts_sar_21_IRQn     = 105,      /*!< 105 [Active] PASS interrupts, ADC #0, Channel #21 */
  pass_0_interrupts_sar_22_IRQn     = 106,      /*!< 106 [Active] PASS interrupts, ADC #0, Channel #22 */
  pass_0_interrupts_sar_23_IRQn     = 107,      /*!< 107 [Active] PASS interrupts, ADC #0, Channel #23 */
  pass_0_interrupts_sar_32_IRQn     = 108,      /*!< 108 [Active] PASS interrupts, ADC #1, Channel #0 */
  pass_0_interrupts_sar_33_IRQn     = 109,      /*!< 109 [Active] PASS interrupts, ADC #1, Channel #1 */
  pass_0_interrupts_sar_34_IRQn     = 110,      /*!< 110 [Active] PASS interrupts, ADC #1, Channel #2 */
  pass_0_interrupts_sar_35_IRQn     = 111,      /*!< 111 [Active] PASS interrupts, ADC #1, Channel #3 */
  pass_0_interrupts_sar_36_IRQn     = 112,      /*!< 112 [Active] PASS interrupts, ADC #1, Channel #4 */
  pass_0_interrupts_sar_37_IRQn     = 113,      /*!< 113 [Active] PASS interrupts, ADC #1, Channel #5 */
  pass_0_interrupts_sar_38_IRQn     = 114,      /*!< 114 [Active] PASS interrupts, ADC #1, Channel #6 */
  pass_0_interrupts_sar_39_IRQn     = 115,      /*!< 115 [Active] PASS interrupts, ADC #1, Channel #7 */
  pass_0_interrupts_sar_40_IRQn     = 116,      /*!< 116 [Active] PASS interrupts, ADC #1, Channel #8 */
  pass_0_interrupts_sar_41_IRQn     = 117,      /*!< 117 [Active] PASS interrupts, ADC #1, Channel #9 */
  pass_0_interrupts_sar_42_IRQn     = 118,      /*!< 118 [Active] PASS interrupts, ADC #1, Channel #10 */
  pass_0_interrupts_sar_43_IRQn     = 119,      /*!< 119 [Active] PASS interrupts, ADC #1, Channel #11 */
  pass_0_interrupts_sar_44_IRQn     = 120,      /*!< 120 [Active] PASS interrupts, ADC #1, Channel #12 */
  pass_0_interrupts_sar_45_IRQn     = 121,      /*!< 121 [Active] PASS interrupts, ADC #1, Channel #13 */
  pass_0_interrupts_sar_46_IRQn     = 122,      /*!< 122 [Active] PASS interrupts, ADC #1, Channel #14 */
  pass_0_interrupts_sar_47_IRQn     = 123,      /*!< 123 [Active] PASS interrupts, ADC #1, Channel #15 */
  pass_0_interrupts_sar_48_IRQn     = 124,      /*!< 124 [Active] PASS interrupts, ADC #1, Channel #16 */
  pass_0_interrupts_sar_49_IRQn     = 125,      /*!< 125 [Active] PASS interrupts, ADC #1, Channel #17 */
  pass_0_interrupts_sar_50_IRQn     = 126,      /*!< 126 [Active] PASS interrupts, ADC #1, Channel #18 */
  pass_0_interrupts_sar_51_IRQn     = 127,      /*!< 127 [Active] PASS interrupts, ADC #1, Channel #19 */
  pass_0_interrupts_sar_52_IRQn     = 128,      /*!< 128 [Active] PASS interrupts, ADC #1, Channel #20 */
  pass_0_interrupts_sar_53_IRQn     = 129,      /*!< 129 [Active] PASS interrupts, ADC #1, Channel #21 */
  pass_0_interrupts_sar_54_IRQn     = 130,      /*!< 130 [Active] PASS interrupts, ADC #1, Channel #22 */
  pass_0_interrupts_sar_55_IRQn     = 131,      /*!< 131 [Active] PASS interrupts, ADC #1, Channel #23 */
  pass_0_interrupts_sar_56_IRQn     = 132,      /*!< 132 [Active] PASS interrupts, ADC #1, Channel #24 */
  pass_0_interrupts_sar_57_IRQn     = 133,      /*!< 133 [Active] PASS interrupts, ADC #1, Channel #25 */
  pass_0_interrupts_sar_58_IRQn     = 134,      /*!< 134 [Active] PASS interrupts, ADC #1, Channel #26 */
  pass_0_interrupts_sar_59_IRQn     = 135,      /*!< 135 [Active] PASS interrupts, ADC #1, Channel #27 */
  pass_0_interrupts_sar_60_IRQn     = 136,      /*!< 136 [Active] PASS interrupts, ADC #1, Channel #28 */
  pass_0_interrupts_sar_61_IRQn     = 137,      /*!< 137 [Active] PASS interrupts, ADC #1, Channel #29 */
  pass_0_interrupts_sar_62_IRQn     = 138,      /*!< 138 [Active] PASS interrupts, ADC #1, Channel #30 */
  pass_0_interrupts_sar_63_IRQn     = 139,      /*!< 139 [Active] PASS interrupts, ADC #1, Channel #31 */
  pass_0_interrupts_sar_64_IRQn     = 140,      /*!< 140 [Active] PASS interrupts, ADC #2, Channel #0 */
  pass_0_interrupts_sar_65_IRQn     = 141,      /*!< 141 [Active] PASS interrupts, ADC #2, Channel #1 */
  pass_0_interrupts_sar_66_IRQn     = 142,      /*!< 142 [Active] PASS interrupts, ADC #2, Channel #2 */
  pass_0_interrupts_sar_67_IRQn     = 143,      /*!< 143 [Active] PASS interrupts, ADC #2, Channel #3 */
  pass_0_interrupts_sar_68_IRQn     = 144,      /*!< 144 [Active] PASS interrupts, ADC #2, Channel #4 */
  pass_0_interrupts_sar_69_IRQn     = 145,      /*!< 145 [Active] PASS interrupts, ADC #2, Channel #5 */
  pass_0_interrupts_sar_70_IRQn     = 146,      /*!< 146 [Active] PASS interrupts, ADC #2, Channel #6 */
  pass_0_interrupts_sar_71_IRQn     = 147,      /*!< 147 [Active] PASS interrupts, ADC #2, Channel #7 */
  cpuss_interrupts_dmac_0_IRQn      = 148,      /*!< 148 [Active] CPUSS DMAC, Channel #0 */
  cpuss_interrupts_dmac_1_IRQn      = 149,      /*!< 149 [Active] CPUSS DMAC, Channel #1 */
  cpuss_interrupts_dmac_2_IRQn      = 150,      /*!< 150 [Active] CPUSS DMAC, Channel #2 */
  cpuss_interrupts_dmac_3_IRQn      = 151,      /*!< 151 [Active] CPUSS DMAC, Channel #3 */
  cpuss_interrupts_dw0_0_IRQn       = 152,      /*!< 152 [Active] CPUSS DataWire #0, Channel #0 */
  cpuss_interrupts_dw0_1_IRQn       = 153,      /*!< 153 [Active] CPUSS DataWire #0, Channel #1 */
  cpuss_interrupts_dw0_2_IRQn       = 154,      /*!< 154 [Active] CPUSS DataWire #0, Channel #2 */
  cpuss_interrupts_dw0_3_IRQn       = 155,      /*!< 155 [Active] CPUSS DataWire #0, Channel #3 */
  cpuss_interrupts_dw0_4_IRQn       = 156,      /*!< 156 [Active] CPUSS DataWire #0, Channel #4 */
  cpuss_interrupts_dw0_5_IRQn       = 157,      /*!< 157 [Active] CPUSS DataWire #0, Channel #5 */
  cpuss_interrupts_dw0_6_IRQn       = 158,      /*!< 158 [Active] CPUSS DataWire #0, Channel #6 */
  cpuss_interrupts_dw0_7_IRQn       = 159,      /*!< 159 [Active] CPUSS DataWire #0, Channel #7 */
  cpuss_interrupts_dw0_8_IRQn       = 160,      /*!< 160 [Active] CPUSS DataWire #0, Channel #8 */
  cpuss_interrupts_dw0_9_IRQn       = 161,      /*!< 161 [Active] CPUSS DataWire #0, Channel #9 */
  cpuss_interrupts_dw0_10_IRQn      = 162,      /*!< 162 [Active] CPUSS DataWire #0, Channel #10 */
  cpuss_interrupts_dw0_11_IRQn      = 163,      /*!< 163 [Active] CPUSS DataWire #0, Channel #11 */
  cpuss_interrupts_dw0_12_IRQn      = 164,      /*!< 164 [Active] CPUSS DataWire #0, Channel #12 */
  cpuss_interrupts_dw0_13_IRQn      = 165,      /*!< 165 [Active] CPUSS DataWire #0, Channel #13 */
  cpuss_interrupts_dw0_14_IRQn      = 166,      /*!< 166 [Active] CPUSS DataWire #0, Channel #14 */
  cpuss_interrupts_dw0_15_IRQn      = 167,      /*!< 167 [Active] CPUSS DataWire #0, Channel #15 */
  cpuss_interrupts_dw0_16_IRQn      = 168,      /*!< 168 [Active] CPUSS DataWire #0, Channel #16 */
  cpuss_interrupts_dw0_17_IRQn      = 169,      /*!< 169 [Active] CPUSS DataWire #0, Channel #17 */
  cpuss_interrupts_dw0_18_IRQn      = 170,      /*!< 170 [Active] CPUSS DataWire #0, Channel #18 */
  cpuss_interrupts_dw0_19_IRQn      = 171,      /*!< 171 [Active] CPUSS DataWire #0, Channel #19 */
  cpuss_interrupts_dw0_20_IRQn      = 172,      /*!< 172 [Active] CPUSS DataWire #0, Channel #20 */
  cpuss_interrupts_dw0_21_IRQn      = 173,      /*!< 173 [Active] CPUSS DataWire #0, Channel #21 */
  cpuss_interrupts_dw0_22_IRQn      = 174,      /*!< 174 [Active] CPUSS DataWire #0, Channel #22 */
  cpuss_interrupts_dw0_23_IRQn      = 175,      /*!< 175 [Active] CPUSS DataWire #0, Channel #23 */
  cpuss_interrupts_dw0_24_IRQn      = 176,      /*!< 176 [Active] CPUSS DataWire #0, Channel #24 */
  cpuss_interrupts_dw0_25_IRQn      = 177,      /*!< 177 [Active] CPUSS DataWire #0, Channel #25 */
  cpuss_interrupts_dw0_26_IRQn      = 178,      /*!< 178 [Active] CPUSS DataWire #0, Channel #26 */
  cpuss_interrupts_dw0_27_IRQn      = 179,      /*!< 179 [Active] CPUSS DataWire #0, Channel #27 */
  cpuss_interrupts_dw0_28_IRQn      = 180,      /*!< 180 [Active] CPUSS DataWire #0, Channel #28 */
  cpuss_interrupts_dw0_29_IRQn      = 181,      /*!< 181 [Active] CPUSS DataWire #0, Channel #29 */
  cpuss_interrupts_dw0_30_IRQn      = 182,      /*!< 182 [Active] CPUSS DataWire #0, Channel #30 */
  cpuss_interrupts_dw0_31_IRQn      = 183,      /*!< 183 [Active] CPUSS DataWire #0, Channel #31 */
  cpuss_interrupts_dw0_32_IRQn      = 184,      /*!< 184 [Active] CPUSS DataWire #0, Channel #32 */
  cpuss_interrupts_dw0_33_IRQn      = 185,      /*!< 185 [Active] CPUSS DataWire #0, Channel #33 */
  cpuss_interrupts_dw0_34_IRQn      = 186,      /*!< 186 [Active] CPUSS DataWire #0, Channel #34 */
  cpuss_interrupts_dw0_35_IRQn      = 187,      /*!< 187 [Active] CPUSS DataWire #0, Channel #35 */
  cpuss_interrupts_dw0_36_IRQn      = 188,      /*!< 188 [Active] CPUSS DataWire #0, Channel #36 */
  cpuss_interrupts_dw0_37_IRQn      = 189,      /*!< 189 [Active] CPUSS DataWire #0, Channel #37 */
  cpuss_interrupts_dw0_38_IRQn      = 190,      /*!< 190 [Active] CPUSS DataWire #0, Channel #38 */
  cpuss_interrupts_dw0_39_IRQn      = 191,      /*!< 191 [Active] CPUSS DataWire #0, Channel #39 */
  cpuss_interrupts_dw0_40_IRQn      = 192,      /*!< 192 [Active] CPUSS DataWire #0, Channel #40 */
  cpuss_interrupts_dw0_41_IRQn      = 193,      /*!< 193 [Active] CPUSS DataWire #0, Channel #41 */
  cpuss_interrupts_dw0_42_IRQn      = 194,      /*!< 194 [Active] CPUSS DataWire #0, Channel #42 */
  cpuss_interrupts_dw0_43_IRQn      = 195,      /*!< 195 [Active] CPUSS DataWire #0, Channel #43 */
  cpuss_interrupts_dw0_44_IRQn      = 196,      /*!< 196 [Active] CPUSS DataWire #0, Channel #44 */
  cpuss_interrupts_dw0_45_IRQn      = 197,      /*!< 197 [Active] CPUSS DataWire #0, Channel #45 */
  cpuss_interrupts_dw0_46_IRQn      = 198,      /*!< 198 [Active] CPUSS DataWire #0, Channel #46 */
  cpuss_interrupts_dw0_47_IRQn      = 199,      /*!< 199 [Active] CPUSS DataWire #0, Channel #47 */
  cpuss_interrupts_dw0_48_IRQn      = 200,      /*!< 200 [Active] CPUSS DataWire #0, Channel #48 */
  cpuss_interrupts_dw0_49_IRQn      = 201,      /*!< 201 [Active] CPUSS DataWire #0, Channel #49 */
  cpuss_interrupts_dw0_50_IRQn      = 202,      /*!< 202 [Active] CPUSS DataWire #0, Channel #50 */
  cpuss_interrupts_dw0_51_IRQn      = 203,      /*!< 203 [Active] CPUSS DataWire #0, Channel #51 */
  cpuss_interrupts_dw0_52_IRQn      = 204,      /*!< 204 [Active] CPUSS DataWire #0, Channel #52 */
  cpuss_interrupts_dw0_53_IRQn      = 205,      /*!< 205 [Active] CPUSS DataWire #0, Channel #53 */
  cpuss_interrupts_dw0_54_IRQn      = 206,      /*!< 206 [Active] CPUSS DataWire #0, Channel #54 */
  cpuss_interrupts_dw0_55_IRQn      = 207,      /*!< 207 [Active] CPUSS DataWire #0, Channel #55 */
  cpuss_interrupts_dw0_56_IRQn      = 208,      /*!< 208 [Active] CPUSS DataWire #0, Channel #56 */
  cpuss_interrupts_dw0_57_IRQn      = 209,      /*!< 209 [Active] CPUSS DataWire #0, Channel #57 */
  cpuss_interrupts_dw0_58_IRQn      = 210,      /*!< 210 [Active] CPUSS DataWire #0, Channel #58 */
  cpuss_interrupts_dw0_59_IRQn      = 211,      /*!< 211 [Active] CPUSS DataWire #0, Channel #59 */
  cpuss_interrupts_dw0_60_IRQn      = 212,      /*!< 212 [Active] CPUSS DataWire #0, Channel #60 */
  cpuss_interrupts_dw0_61_IRQn      = 213,      /*!< 213 [Active] CPUSS DataWire #0, Channel #61 */
  cpuss_interrupts_dw0_62_IRQn      = 214,      /*!< 214 [Active] CPUSS DataWire #0, Channel #62 */
  cpuss_interrupts_dw0_63_IRQn      = 215,      /*!< 215 [Active] CPUSS DataWire #0, Channel #63 */
  cpuss_interrupts_dw0_64_IRQn      = 216,      /*!< 216 [Active] CPUSS DataWire #0, Channel #64 */
  cpuss_interrupts_dw0_65_IRQn      = 217,      /*!< 217 [Active] CPUSS DataWire #0, Channel #65 */
  cpuss_interrupts_dw0_66_IRQn      = 218,      /*!< 218 [Active] CPUSS DataWire #0, Channel #66 */
  cpuss_interrupts_dw0_67_IRQn      = 219,      /*!< 219 [Active] CPUSS DataWire #0, Channel #67 */
  cpuss_interrupts_dw0_68_IRQn      = 220,      /*!< 220 [Active] CPUSS DataWire #0, Channel #68 */
  cpuss_interrupts_dw0_69_IRQn      = 221,      /*!< 221 [Active] CPUSS DataWire #0, Channel #69 */
  cpuss_interrupts_dw0_70_IRQn      = 222,      /*!< 222 [Active] CPUSS DataWire #0, Channel #70 */
  cpuss_interrupts_dw0_71_IRQn      = 223,      /*!< 223 [Active] CPUSS DataWire #0, Channel #71 */
  cpuss_interrupts_dw0_72_IRQn      = 224,      /*!< 224 [Active] CPUSS DataWire #0, Channel #72 */
  cpuss_interrupts_dw0_73_IRQn      = 225,      /*!< 225 [Active] CPUSS DataWire #0, Channel #73 */
  cpuss_interrupts_dw0_74_IRQn      = 226,      /*!< 226 [Active] CPUSS DataWire #0, Channel #74 */
  cpuss_interrupts_dw0_75_IRQn      = 227,      /*!< 227 [Active] CPUSS DataWire #0, Channel #75 */
  cpuss_interrupts_dw0_76_IRQn      = 228,      /*!< 228 [Active] CPUSS DataWire #0, Channel #76 */
  cpuss_interrupts_dw0_77_IRQn      = 229,      /*!< 229 [Active] CPUSS DataWire #0, Channel #77 */
  cpuss_interrupts_dw0_78_IRQn      = 230,      /*!< 230 [Active] CPUSS DataWire #0, Channel #78 */
  cpuss_interrupts_dw0_79_IRQn      = 231,      /*!< 231 [Active] CPUSS DataWire #0, Channel #79 */
  cpuss_interrupts_dw0_80_IRQn      = 232,      /*!< 232 [Active] CPUSS DataWire #0, Channel #80 */
  cpuss_interrupts_dw0_81_IRQn      = 233,      /*!< 233 [Active] CPUSS DataWire #0, Channel #81 */
  cpuss_interrupts_dw0_82_IRQn      = 234,      /*!< 234 [Active] CPUSS DataWire #0, Channel #82 */
  cpuss_interrupts_dw0_83_IRQn      = 235,      /*!< 235 [Active] CPUSS DataWire #0, Channel #83 */
  cpuss_interrupts_dw0_84_IRQn      = 236,      /*!< 236 [Active] CPUSS DataWire #0, Channel #84 */
  cpuss_interrupts_dw0_85_IRQn      = 237,      /*!< 237 [Active] CPUSS DataWire #0, Channel #85 */
  cpuss_interrupts_dw0_86_IRQn      = 238,      /*!< 238 [Active] CPUSS DataWire #0, Channel #86 */
  cpuss_interrupts_dw0_87_IRQn      = 239,      /*!< 239 [Active] CPUSS DataWire #0, Channel #87 */
  cpuss_interrupts_dw0_88_IRQn      = 240,      /*!< 240 [Active] CPUSS DataWire #0, Channel #88 */
  cpuss_interrupts_dw1_0_IRQn       = 241,      /*!< 241 [Active] CPUSS DataWire #1, Channel #0 */
  cpuss_interrupts_dw1_1_IRQn       = 242,      /*!< 242 [Active] CPUSS DataWire #1, Channel #1 */
  cpuss_interrupts_dw1_2_IRQn       = 243,      /*!< 243 [Active] CPUSS DataWire #1, Channel #2 */
  cpuss_interrupts_dw1_3_IRQn       = 244,      /*!< 244 [Active] CPUSS DataWire #1, Channel #3 */
  cpuss_interrupts_dw1_4_IRQn       = 245,      /*!< 245 [Active] CPUSS DataWire #1, Channel #4 */
  cpuss_interrupts_dw1_5_IRQn       = 246,      /*!< 246 [Active] CPUSS DataWire #1, Channel #5 */
  cpuss_interrupts_dw1_6_IRQn       = 247,      /*!< 247 [Active] CPUSS DataWire #1, Channel #6 */
  cpuss_interrupts_dw1_7_IRQn       = 248,      /*!< 248 [Active] CPUSS DataWire #1, Channel #7 */
  cpuss_interrupts_dw1_8_IRQn       = 249,      /*!< 249 [Active] CPUSS DataWire #1, Channel #8 */
  cpuss_interrupts_dw1_9_IRQn       = 250,      /*!< 250 [Active] CPUSS DataWire #1, Channel #9 */
  cpuss_interrupts_dw1_10_IRQn      = 251,      /*!< 251 [Active] CPUSS DataWire #1, Channel #10 */
  cpuss_interrupts_dw1_11_IRQn      = 252,      /*!< 252 [Active] CPUSS DataWire #1, Channel #11 */
  cpuss_interrupts_dw1_12_IRQn      = 253,      /*!< 253 [Active] CPUSS DataWire #1, Channel #12 */
  cpuss_interrupts_dw1_13_IRQn      = 254,      /*!< 254 [Active] CPUSS DataWire #1, Channel #13 */
  cpuss_interrupts_dw1_14_IRQn      = 255,      /*!< 255 [Active] CPUSS DataWire #1, Channel #14 */
  cpuss_interrupts_dw1_15_IRQn      = 256,      /*!< 256 [Active] CPUSS DataWire #1, Channel #15 */
  cpuss_interrupts_dw1_16_IRQn      = 257,      /*!< 257 [Active] CPUSS DataWire #1, Channel #16 */
  cpuss_interrupts_dw1_17_IRQn      = 258,      /*!< 258 [Active] CPUSS DataWire #1, Channel #17 */
  cpuss_interrupts_dw1_18_IRQn      = 259,      /*!< 259 [Active] CPUSS DataWire #1, Channel #18 */
  cpuss_interrupts_dw1_19_IRQn      = 260,      /*!< 260 [Active] CPUSS DataWire #1, Channel #19 */
  cpuss_interrupts_dw1_20_IRQn      = 261,      /*!< 261 [Active] CPUSS DataWire #1, Channel #20 */
  cpuss_interrupts_dw1_21_IRQn      = 262,      /*!< 262 [Active] CPUSS DataWire #1, Channel #21 */
  cpuss_interrupts_dw1_22_IRQn      = 263,      /*!< 263 [Active] CPUSS DataWire #1, Channel #22 */
  cpuss_interrupts_dw1_23_IRQn      = 264,      /*!< 264 [Active] CPUSS DataWire #1, Channel #23 */
  cpuss_interrupts_dw1_24_IRQn      = 265,      /*!< 265 [Active] CPUSS DataWire #1, Channel #24 */
  cpuss_interrupts_dw1_25_IRQn      = 266,      /*!< 266 [Active] CPUSS DataWire #1, Channel #25 */
  cpuss_interrupts_dw1_26_IRQn      = 267,      /*!< 267 [Active] CPUSS DataWire #1, Channel #26 */
  cpuss_interrupts_dw1_27_IRQn      = 268,      /*!< 268 [Active] CPUSS DataWire #1, Channel #27 */
  cpuss_interrupts_dw1_28_IRQn      = 269,      /*!< 269 [Active] CPUSS DataWire #1, Channel #28 */
  cpuss_interrupts_dw1_29_IRQn      = 270,      /*!< 270 [Active] CPUSS DataWire #1, Channel #29 */
  cpuss_interrupts_dw1_30_IRQn      = 271,      /*!< 271 [Active] CPUSS DataWire #1, Channel #30 */
  cpuss_interrupts_dw1_31_IRQn      = 272,      /*!< 272 [Active] CPUSS DataWire #1, Channel #31 */
  cpuss_interrupts_dw1_32_IRQn      = 273,      /*!< 273 [Active] CPUSS DataWire #1, Channel #32 */
  tcpwm_0_interrupts_0_IRQn         = 274,      /*!< 274 [Active] TCPWM Group #0, Counter #0 */
  tcpwm_0_interrupts_1_IRQn         = 275,      /*!< 275 [Active] TCPWM Group #0, Counter #1 */
  tcpwm_0_interrupts_2_IRQn         = 276,      /*!< 276 [Active] TCPWM Group #0, Counter #2 */
  tcpwm_0_interrupts_3_IRQn         = 277,      /*!< 277 [Active] TCPWM Group #0, Counter #3 */
  tcpwm_0_interrupts_4_IRQn         = 278,      /*!< 278 [Active] TCPWM Group #0, Counter #4 */
  tcpwm_0_interrupts_5_IRQn         = 279,      /*!< 279 [Active] TCPWM Group #0, Counter #5 */
  tcpwm_0_interrupts_6_IRQn         = 280,      /*!< 280 [Active] TCPWM Group #0, Counter #6 */
  tcpwm_0_interrupts_7_IRQn         = 281,      /*!< 281 [Active] TCPWM Group #0, Counter #7 */
  tcpwm_0_interrupts_8_IRQn         = 282,      /*!< 282 [Active] TCPWM Group #0, Counter #8 */
  tcpwm_0_interrupts_9_IRQn         = 283,      /*!< 283 [Active] TCPWM Group #0, Counter #9 */
  tcpwm_0_interrupts_10_IRQn        = 284,      /*!< 284 [Active] TCPWM Group #0, Counter #10 */
  tcpwm_0_interrupts_11_IRQn        = 285,      /*!< 285 [Active] TCPWM Group #0, Counter #11 */
  tcpwm_0_interrupts_12_IRQn        = 286,      /*!< 286 [Active] TCPWM Group #0, Counter #12 */
  tcpwm_0_interrupts_13_IRQn        = 287,      /*!< 287 [Active] TCPWM Group #0, Counter #13 */
  tcpwm_0_interrupts_14_IRQn        = 288,      /*!< 288 [Active] TCPWM Group #0, Counter #14 */
  tcpwm_0_interrupts_15_IRQn        = 289,      /*!< 289 [Active] TCPWM Group #0, Counter #15 */
  tcpwm_0_interrupts_16_IRQn        = 290,      /*!< 290 [Active] TCPWM Group #0, Counter #16 */
  tcpwm_0_interrupts_17_IRQn        = 291,      /*!< 291 [Active] TCPWM Group #0, Counter #17 */
  tcpwm_0_interrupts_18_IRQn        = 292,      /*!< 292 [Active] TCPWM Group #0, Counter #18 */
  tcpwm_0_interrupts_19_IRQn        = 293,      /*!< 293 [Active] TCPWM Group #0, Counter #19 */
  tcpwm_0_interrupts_20_IRQn        = 294,      /*!< 294 [Active] TCPWM Group #0, Counter #20 */
  tcpwm_0_interrupts_21_IRQn        = 295,      /*!< 295 [Active] TCPWM Group #0, Counter #21 */
  tcpwm_0_interrupts_22_IRQn        = 296,      /*!< 296 [Active] TCPWM Group #0, Counter #22 */
  tcpwm_0_interrupts_23_IRQn        = 297,      /*!< 297 [Active] TCPWM Group #0, Counter #23 */
  tcpwm_0_interrupts_24_IRQn        = 298,      /*!< 298 [Active] TCPWM Group #0, Counter #24 */
  tcpwm_0_interrupts_25_IRQn        = 299,      /*!< 299 [Active] TCPWM Group #0, Counter #25 */
  tcpwm_0_interrupts_26_IRQn        = 300,      /*!< 300 [Active] TCPWM Group #0, Counter #26 */
  tcpwm_0_interrupts_27_IRQn        = 301,      /*!< 301 [Active] TCPWM Group #0, Counter #27 */
  tcpwm_0_interrupts_28_IRQn        = 302,      /*!< 302 [Active] TCPWM Group #0, Counter #28 */
  tcpwm_0_interrupts_29_IRQn        = 303,      /*!< 303 [Active] TCPWM Group #0, Counter #29 */
  tcpwm_0_interrupts_30_IRQn        = 304,      /*!< 304 [Active] TCPWM Group #0, Counter #30 */
  tcpwm_0_interrupts_31_IRQn        = 305,      /*!< 305 [Active] TCPWM Group #0, Counter #31 */
  tcpwm_0_interrupts_32_IRQn        = 306,      /*!< 306 [Active] TCPWM Group #0, Counter #32 */
  tcpwm_0_interrupts_33_IRQn        = 307,      /*!< 307 [Active] TCPWM Group #0, Counter #33 */
  tcpwm_0_interrupts_34_IRQn        = 308,      /*!< 308 [Active] TCPWM Group #0, Counter #34 */
  tcpwm_0_interrupts_35_IRQn        = 309,      /*!< 309 [Active] TCPWM Group #0, Counter #35 */
  tcpwm_0_interrupts_36_IRQn        = 310,      /*!< 310 [Active] TCPWM Group #0, Counter #36 */
  tcpwm_0_interrupts_37_IRQn        = 311,      /*!< 311 [Active] TCPWM Group #0, Counter #37 */
  tcpwm_0_interrupts_38_IRQn        = 312,      /*!< 312 [Active] TCPWM Group #0, Counter #38 */
  tcpwm_0_interrupts_39_IRQn        = 313,      /*!< 313 [Active] TCPWM Group #0, Counter #39 */
  tcpwm_0_interrupts_40_IRQn        = 314,      /*!< 314 [Active] TCPWM Group #0, Counter #40 */
  tcpwm_0_interrupts_41_IRQn        = 315,      /*!< 315 [Active] TCPWM Group #0, Counter #41 */
  tcpwm_0_interrupts_42_IRQn        = 316,      /*!< 316 [Active] TCPWM Group #0, Counter #42 */
  tcpwm_0_interrupts_43_IRQn        = 317,      /*!< 317 [Active] TCPWM Group #0, Counter #43 */
  tcpwm_0_interrupts_44_IRQn        = 318,      /*!< 318 [Active] TCPWM Group #0, Counter #44 */
  tcpwm_0_interrupts_45_IRQn        = 319,      /*!< 319 [Active] TCPWM Group #0, Counter #45 */
  tcpwm_0_interrupts_46_IRQn        = 320,      /*!< 320 [Active] TCPWM Group #0, Counter #46 */
  tcpwm_0_interrupts_47_IRQn        = 321,      /*!< 321 [Active] TCPWM Group #0, Counter #47 */
  tcpwm_0_interrupts_48_IRQn        = 322,      /*!< 322 [Active] TCPWM Group #0, Counter #48 */
  tcpwm_0_interrupts_49_IRQn        = 323,      /*!< 323 [Active] TCPWM Group #0, Counter #49 */
  tcpwm_0_interrupts_50_IRQn        = 324,      /*!< 324 [Active] TCPWM Group #0, Counter #50 */
  tcpwm_0_interrupts_51_IRQn        = 325,      /*!< 325 [Active] TCPWM Group #0, Counter #51 */
  tcpwm_0_interrupts_52_IRQn        = 326,      /*!< 326 [Active] TCPWM Group #0, Counter #52 */
  tcpwm_0_interrupts_53_IRQn        = 327,      /*!< 327 [Active] TCPWM Group #0, Counter #53 */
  tcpwm_0_interrupts_54_IRQn        = 328,      /*!< 328 [Active] TCPWM Group #0, Counter #54 */
  tcpwm_0_interrupts_55_IRQn        = 329,      /*!< 329 [Active] TCPWM Group #0, Counter #55 */
  tcpwm_0_interrupts_56_IRQn        = 330,      /*!< 330 [Active] TCPWM Group #0, Counter #56 */
  tcpwm_0_interrupts_57_IRQn        = 331,      /*!< 331 [Active] TCPWM Group #0, Counter #57 */
  tcpwm_0_interrupts_58_IRQn        = 332,      /*!< 332 [Active] TCPWM Group #0, Counter #58 */
  tcpwm_0_interrupts_59_IRQn        = 333,      /*!< 333 [Active] TCPWM Group #0, Counter #59 */
  tcpwm_0_interrupts_60_IRQn        = 334,      /*!< 334 [Active] TCPWM Group #0, Counter #60 */
  tcpwm_0_interrupts_61_IRQn        = 335,      /*!< 335 [Active] TCPWM Group #0, Counter #61 */
  tcpwm_0_interrupts_62_IRQn        = 336,      /*!< 336 [Active] TCPWM Group #0, Counter #62 */
  tcpwm_0_interrupts_256_IRQn       = 337,      /*!< 337 [Active] TCPWM Group #1, Counter #0 */
  tcpwm_0_interrupts_257_IRQn       = 338,      /*!< 338 [Active] TCPWM Group #1, Counter #1 */
  tcpwm_0_interrupts_258_IRQn       = 339,      /*!< 339 [Active] TCPWM Group #1, Counter #2 */
  tcpwm_0_interrupts_259_IRQn       = 340,      /*!< 340 [Active] TCPWM Group #1, Counter #3 */
  tcpwm_0_interrupts_260_IRQn       = 341,      /*!< 341 [Active] TCPWM Group #1, Counter #4 */
  tcpwm_0_interrupts_261_IRQn       = 342,      /*!< 342 [Active] TCPWM Group #1, Counter #5 */
  tcpwm_0_interrupts_262_IRQn       = 343,      /*!< 343 [Active] TCPWM Group #1, Counter #6 */
  tcpwm_0_interrupts_263_IRQn       = 344,      /*!< 344 [Active] TCPWM Group #1, Counter #7 */
  tcpwm_0_interrupts_264_IRQn       = 345,      /*!< 345 [Active] TCPWM Group #1, Counter #8 */
  tcpwm_0_interrupts_265_IRQn       = 346,      /*!< 346 [Active] TCPWM Group #1, Counter #9 */
  tcpwm_0_interrupts_266_IRQn       = 347,      /*!< 347 [Active] TCPWM Group #1, Counter #10 */
  tcpwm_0_interrupts_267_IRQn       = 348,      /*!< 348 [Active] TCPWM Group #1, Counter #11 */
  tcpwm_0_interrupts_512_IRQn       = 349,      /*!< 349 [Active] TCPWM Group #2, Counter #0 */
  tcpwm_0_interrupts_513_IRQn       = 350,      /*!< 350 [Active] TCPWM Group #2, Counter #1 */
  tcpwm_0_interrupts_514_IRQn       = 351,      /*!< 351 [Active] TCPWM Group #2, Counter #2 */
  tcpwm_0_interrupts_515_IRQn       = 352,      /*!< 352 [Active] TCPWM Group #2, Counter #3 */
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

/* Configuration of the ARM Cortex-M4 Processor and Core Peripherals */
#define __CM4_REV                       0x0001U /*!< CM4 Core Revision */
#define __NVIC_PRIO_BITS                3       /*!< Number of Bits used for Priority Levels */
#define __Vendor_SysTickConfig          0       /*!< Set to 1 if different SysTick Config is used */
#define __VTOR_PRESENT                  1       /*!< Set to 1 if CPU supports Vector Table Offset Register */
#define __MPU_PRESENT                   1       /*!< MPU present or not */
#define __FPU_PRESENT                   1       /*!< FPU present or not */
#define __CM0P_PRESENT                  1       /*!< CM0P present or not */
#define __DTCM_PRESENT                  0       /*!< Data Tightly Coupled Memory is present or not */
#define __ICACHE_PRESENT                0       /*!< Instruction Cache present or not */
#define __DCACHE_PRESENT                0       /*!< Data Cache present or not */

/** \} Configuration_of_CMSIS */

#include "core_cm4.h"                           /*!< ARM Cortex-M4 processor and core peripherals */

#endif

/* Memory Blocks */
#define CY_ROM_BASE                     0x00000000UL
#define CY_ROM_SIZE                     0x00008000UL
#define CY_FLASH_LG_SBM_BASE            0x10000000UL
#define CY_FLASH_LG_SBM_SIZE            0x000F0000UL
#define CY_FLASH_LG_DBM0_BASE           0x10000000UL
#define CY_FLASH_LG_DBM0_SIZE           0x00078000UL
#define CY_FLASH_SM_DBM0_BASE           0x10078000UL
#define CY_FLASH_SM_DBM0_SIZE           0x00010000UL
#define CY_FLASH_SM_SBM_BASE            0x100F0000UL
#define CY_FLASH_SM_SBM_SIZE            0x00020000UL
#define CY_FLASH_LG_DBM1_BASE           0x12000000UL
#define CY_FLASH_LG_DBM1_SIZE           0x00078000UL
#define CY_FLASH_SM_DBM1_BASE           0x12078000UL
#define CY_FLASH_SM_DBM1_SIZE           0x00010000UL
#define CY_WFLASH_LG_SBM_BASE           0x14000000UL
#define CY_WFLASH_LG_SBM_SIZE           0x00012000UL
#define CY_WFLASH_LG_DBM0_BASE          0x14000000UL
#define CY_WFLASH_LG_DBM0_SIZE          0x00009000UL
#define CY_WFLASH_SM_DBM0_BASE          0x14009000UL
#define CY_WFLASH_SM_DBM0_SIZE          0x00003000UL
#define CY_WFLASH_SM_SBM_BASE           0x14012000UL
#define CY_WFLASH_SM_SBM_SIZE           0x00006000UL
#define CY_WFLASH_LG_DBM1_BASE          0x15000000UL
#define CY_WFLASH_LG_DBM1_SIZE          0x00009000UL
#define CY_WFLASH_SM_DBM1_BASE          0x15009000UL
#define CY_WFLASH_SM_DBM1_SIZE          0x00003000UL
#define CY_OTPFLASH_BASE                0x16000000UL
#define CY_OTPFLASH_SIZE                0x00008000UL
#define CY_SFLASH_BASE                  0x17000000UL
#define CY_SFLASH_SIZE                  0x00008000UL
#define CY_SFLASH1_BASE                 0x17800000UL
#define CY_SFLASH1_SIZE                 0x00008000UL
#define CY_EFUSE_BASE                   0x402C0800UL
#define CY_EFUSE_SIZE                   0x00000200UL
#define CY_CAN0MRAM_BASE                0x40530000UL
#define CY_CAN0MRAM_SIZE                0x00010000UL
#define CY_CAN1MRAM_BASE                0x40550000UL
#define CY_CAN1MRAM_SIZE                0x00010000UL
#define CY_SRAM_BASE                    0x08000000UL
#define CY_SRAM_SIZE                    0x00020000UL


/* IP List */
#define CY_IP_MXTTCANFD                 1u
#define CY_IP_MXTTCANFD_INSTANCES       2u
#define CY_IP_MXTTCANFD_VERSION         1u
#define CY_IP_MXTTCANFD_VERSION_MINOR   0u
#define CY_IP_M4CPUSS                   1u
#define CY_IP_M4CPUSS_INSTANCES         1u
#define CY_IP_M4CPUSS_VERSION           2u
#define CY_IP_M4CPUSS_VERSION_MINOR     0u
#define CY_IP_M4CPUSS_DMAC              1u
#define CY_IP_M4CPUSS_DMAC_INSTANCES    1u
#define CY_IP_M4CPUSS_DMAC_VERSION      2u
#define CY_IP_M4CPUSS_DMAC_VERSION_MINOR 0u
#define CY_IP_M4CPUSS_DMA               1u
#define CY_IP_M4CPUSS_DMA_INSTANCES     2u
#define CY_IP_M4CPUSS_DMA_VERSION       2u
#define CY_IP_M4CPUSS_DMA_VERSION_MINOR 0u
#define CY_IP_MXCRYPTO                  1u
#define CY_IP_MXCRYPTO_INSTANCES        1u
#define CY_IP_MXCRYPTO_VERSION          2u
#define CY_IP_MXCRYPTO_VERSION_MINOR    0u
#define CY_IP_MXDFT                     1u
#define CY_IP_MXDFT_INSTANCES           1u
#define CY_IP_MXDFT_VERSION             1u
#define CY_IP_MXDFT_VERSION_MINOR       0u
#define CY_IP_MXEFUSE                   1u
#define CY_IP_MXEFUSE_INSTANCES         1u
#define CY_IP_MXEFUSE_VERSION           2u
#define CY_IP_MXEFUSE_VERSION_MINOR     0u
#define CY_IP_MXEVTGEN                  1u
#define CY_IP_MXEVTGEN_INSTANCES        1u
#define CY_IP_MXEVTGEN_VERSION          1u
#define CY_IP_MXEVTGEN_VERSION_MINOR    0u
#define CY_IP_MXS40IOSS                 1u
#define CY_IP_MXS40IOSS_INSTANCES       1u
#define CY_IP_MXS40IOSS_VERSION         2u
#define CY_IP_MXS40IOSS_VERSION_MINOR   0u
#define CY_IP_MXLIN                     1u
#define CY_IP_MXLIN_INSTANCES           1u
#define CY_IP_MXLIN_VERSION             1u
#define CY_IP_MXLIN_VERSION_MINOR       0u
#define CY_IP_MXS40EPASS                1u
#define CY_IP_MXS40EPASS_INSTANCES      1u
#define CY_IP_MXS40EPASS_VERSION        1u
#define CY_IP_MXS40EPASS_VERSION_MINOR  0u
#define CY_IP_MXS40EPASS_ESAR           1u
#define CY_IP_MXS40EPASS_ESAR_INSTANCES 3u
#define CY_IP_MXS40EPASS_ESAR_VERSION   1u
#define CY_IP_MXS40EPASS_ESAR_VERSION_MINOR 0u
#define CY_IP_MXPERI                    1u
#define CY_IP_MXPERI_INSTANCES          1u
#define CY_IP_MXPERI_VERSION            2u
#define CY_IP_MXPERI_VERSION_MINOR      0u
#define CY_IP_MXPERI_TR                 1u
#define CY_IP_MXPERI_TR_INSTANCES       1u
#define CY_IP_MXPERI_TR_VERSION         2u
#define CY_IP_MXPERI_TR_VERSION_MINOR   0u
#define CY_IP_MXSCB                     1u
#define CY_IP_MXSCB_INSTANCES           8u
#define CY_IP_MXSCB_VERSION             2u
#define CY_IP_MXSCB_VERSION_MINOR       0u
#define CY_IP_MXS40SRSS                 1u
#define CY_IP_MXS40SRSS_INSTANCES       1u
#define CY_IP_MXS40SRSS_VERSION         2u
#define CY_IP_MXS40SRSS_VERSION_MINOR   0u
#define CY_IP_MXS40SRSS_RTC             1u
#define CY_IP_MXS40SRSS_RTC_INSTANCES   1u
#define CY_IP_MXS40SRSS_RTC_VERSION     2u
#define CY_IP_MXS40SRSS_RTC_VERSION_MINOR 0u
#define CY_IP_MXS40SRSS_MCWDT           1u
#define CY_IP_MXS40SRSS_MCWDT_INSTANCES 2u
#define CY_IP_MXS40SRSS_MCWDT_VERSION   2u
#define CY_IP_MXS40SRSS_MCWDT_VERSION_MINOR 0u
#define CY_IP_MXTCPWM                   1u
#define CY_IP_MXTCPWM_INSTANCES         1u
#define CY_IP_MXTCPWM_VERSION           2u
#define CY_IP_MXTCPWM_VERSION_MINOR     0u

#define CY_DEVICE_TVIIBE1M
#define CY_DEVICE_SERIES_CYT2B7
#define CY_SILICON_ID                   0xE3DA2301UL
#define CY_HF_CLK_MAX_FREQ              160000000UL

#define CPUSS_FLASHC_PA_SIZE_LOG2       0x7UL

#include "system_psoc6.h"                       /*!< PSoC 6 System */

#include "tviibe1m_config.h"
#include "gpio_tviibe1m_100_lqfp.h"

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
#define PERI_GR1                                ((PERI_GR_Type*) &PERI->GR[1])                                    /* 0x40004020 */
#define PERI_GR2                                ((PERI_GR_Type*) &PERI->GR[2])                                    /* 0x40004040 */
#define PERI_GR3                                ((PERI_GR_Type*) &PERI->GR[3])                                    /* 0x40004060 */
#define PERI_GR5                                ((PERI_GR_Type*) &PERI->GR[5])                                    /* 0x400040A0 */
#define PERI_GR6                                ((PERI_GR_Type*) &PERI->GR[6])                                    /* 0x400040C0 */
#define PERI_GR9                                ((PERI_GR_Type*) &PERI->GR[9])                                    /* 0x40004120 */
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
#define PERI_TR_1TO1_GR0                        ((PERI_TR_1TO1_GR_Type*) &PERI->TR_1TO1_GR[0])                    /* 0x4000C000 */
#define PERI_TR_1TO1_GR1                        ((PERI_TR_1TO1_GR_Type*) &PERI->TR_1TO1_GR[1])                    /* 0x4000C400 */
#define PERI_TR_1TO1_GR2                        ((PERI_TR_1TO1_GR_Type*) &PERI->TR_1TO1_GR[2])                    /* 0x4000C800 */
#define PERI_TR_1TO1_GR3                        ((PERI_TR_1TO1_GR_Type*) &PERI->TR_1TO1_GR[3])                    /* 0x4000CC00 */
#define PERI_TR_1TO1_GR4                        ((PERI_TR_1TO1_GR_Type*) &PERI->TR_1TO1_GR[4])                    /* 0x4000D000 */
#define PERI_TR_1TO1_GR5                        ((PERI_TR_1TO1_GR_Type*) &PERI->TR_1TO1_GR[5])                    /* 0x4000D400 */
#define PERI_TR_1TO1_GR6                        ((PERI_TR_1TO1_GR_Type*) &PERI->TR_1TO1_GR[6])                    /* 0x4000D800 */
#define PERI_TR_1TO1_GR7                        ((PERI_TR_1TO1_GR_Type*) &PERI->TR_1TO1_GR[7])                    /* 0x4000DC00 */
#define PERI_TR_1TO1_GR8                        ((PERI_TR_1TO1_GR_Type*) &PERI->TR_1TO1_GR[8])                    /* 0x4000E000 */

/*******************************************************************************
*                                   PERI_MS
*******************************************************************************/

#define PERI_MS_BASE                            0x40010000UL
#define PERI_MS                                 ((PERI_MS_Type*) PERI_MS_BASE)                                    /* 0x40010000 */
#define PERI_MS_PPU_PR0                         ((PERI_MS_PPU_PR_Type*) &PERI_MS->PPU_PR[0])                      /* 0x40010000 */
#define PERI_MS_PPU_PR1                         ((PERI_MS_PPU_PR_Type*) &PERI_MS->PPU_PR[1])                      /* 0x40010040 */
#define PERI_MS_PPU_PR2                         ((PERI_MS_PPU_PR_Type*) &PERI_MS->PPU_PR[2])                      /* 0x40010080 */
#define PERI_MS_PPU_PR3                         ((PERI_MS_PPU_PR_Type*) &PERI_MS->PPU_PR[3])                      /* 0x400100C0 */
#define PERI_MS_PPU_PR4                         ((PERI_MS_PPU_PR_Type*) &PERI_MS->PPU_PR[4])                      /* 0x40010100 */
#define PERI_MS_PPU_PR5                         ((PERI_MS_PPU_PR_Type*) &PERI_MS->PPU_PR[5])                      /* 0x40010140 */
#define PERI_MS_PPU_PR6                         ((PERI_MS_PPU_PR_Type*) &PERI_MS->PPU_PR[6])                      /* 0x40010180 */
#define PERI_MS_PPU_PR7                         ((PERI_MS_PPU_PR_Type*) &PERI_MS->PPU_PR[7])                      /* 0x400101C0 */
#define PERI_MS_PPU_PR8                         ((PERI_MS_PPU_PR_Type*) &PERI_MS->PPU_PR[8])                      /* 0x40010200 */
#define PERI_MS_PPU_PR9                         ((PERI_MS_PPU_PR_Type*) &PERI_MS->PPU_PR[9])                      /* 0x40010240 */
#define PERI_MS_PPU_PR10                        ((PERI_MS_PPU_PR_Type*) &PERI_MS->PPU_PR[10])                     /* 0x40010280 */
#define PERI_MS_PPU_PR11                        ((PERI_MS_PPU_PR_Type*) &PERI_MS->PPU_PR[11])                     /* 0x400102C0 */
#define PERI_MS_PPU_PR12                        ((PERI_MS_PPU_PR_Type*) &PERI_MS->PPU_PR[12])                     /* 0x40010300 */
#define PERI_MS_PPU_PR13                        ((PERI_MS_PPU_PR_Type*) &PERI_MS->PPU_PR[13])                     /* 0x40010340 */
#define PERI_MS_PPU_PR14                        ((PERI_MS_PPU_PR_Type*) &PERI_MS->PPU_PR[14])                     /* 0x40010380 */
#define PERI_MS_PPU_PR15                        ((PERI_MS_PPU_PR_Type*) &PERI_MS->PPU_PR[15])                     /* 0x400103C0 */
#define PERI_MS_PPU_FX_PERI_MAIN                ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[0])                      /* 0x40010800 */
#define PERI_MS_PPU_FX_PERI_SECURE              ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[1])                      /* 0x40010840 */
#define PERI_MS_PPU_FX_PERI_GR0_GROUP           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[2])                      /* 0x40010880 */
#define PERI_MS_PPU_FX_PERI_GR1_GROUP           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[3])                      /* 0x400108C0 */
#define PERI_MS_PPU_FX_PERI_GR2_GROUP           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[4])                      /* 0x40010900 */
#define PERI_MS_PPU_FX_PERI_GR3_GROUP           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[5])                      /* 0x40010940 */
#define PERI_MS_PPU_FX_PERI_GR5_GROUP           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[6])                      /* 0x40010980 */
#define PERI_MS_PPU_FX_PERI_GR6_GROUP           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[7])                      /* 0x400109C0 */
#define PERI_MS_PPU_FX_PERI_GR9_GROUP           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[8])                      /* 0x40010A00 */
#define PERI_MS_PPU_FX_PERI_TR                  ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[9])                      /* 0x40010A40 */
#define PERI_MS_PPU_FX_CRYPTO_MAIN              ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[10])                     /* 0x40010A80 */
#define PERI_MS_PPU_FX_CRYPTO_CRYPTO            ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[11])                     /* 0x40010AC0 */
#define PERI_MS_PPU_FX_CRYPTO_BOOT              ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[12])                     /* 0x40010B00 */
#define PERI_MS_PPU_FX_CRYPTO_KEY0              ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[13])                     /* 0x40010B40 */
#define PERI_MS_PPU_FX_CRYPTO_KEY1              ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[14])                     /* 0x40010B80 */
#define PERI_MS_PPU_FX_CRYPTO_BUF               ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[15])                     /* 0x40010BC0 */
#define PERI_MS_PPU_FX_CPUSS_CM4                ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[16])                     /* 0x40010C00 */
#define PERI_MS_PPU_FX_CPUSS_CM0                ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[17])                     /* 0x40010C40 */
#define PERI_MS_PPU_FX_CPUSS_BOOT               ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[18])                     /* 0x40010C80 */
#define PERI_MS_PPU_FX_CPUSS_CM0_INT            ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[19])                     /* 0x40010CC0 */
#define PERI_MS_PPU_FX_CPUSS_CM4_INT            ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[20])                     /* 0x40010D00 */
#define PERI_MS_PPU_FX_FAULT_STRUCT0_MAIN       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[21])                     /* 0x40010D40 */
#define PERI_MS_PPU_FX_FAULT_STRUCT1_MAIN       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[22])                     /* 0x40010D80 */
#define PERI_MS_PPU_FX_FAULT_STRUCT2_MAIN       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[23])                     /* 0x40010DC0 */
#define PERI_MS_PPU_FX_FAULT_STRUCT3_MAIN       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[24])                     /* 0x40010E00 */
#define PERI_MS_PPU_FX_IPC_STRUCT0_IPC          ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[25])                     /* 0x40010E40 */
#define PERI_MS_PPU_FX_IPC_STRUCT1_IPC          ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[26])                     /* 0x40010E80 */
#define PERI_MS_PPU_FX_IPC_STRUCT2_IPC          ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[27])                     /* 0x40010EC0 */
#define PERI_MS_PPU_FX_IPC_STRUCT3_IPC          ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[28])                     /* 0x40010F00 */
#define PERI_MS_PPU_FX_IPC_STRUCT4_IPC          ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[29])                     /* 0x40010F40 */
#define PERI_MS_PPU_FX_IPC_STRUCT5_IPC          ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[30])                     /* 0x40010F80 */
#define PERI_MS_PPU_FX_IPC_STRUCT6_IPC          ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[31])                     /* 0x40010FC0 */
#define PERI_MS_PPU_FX_IPC_STRUCT7_IPC          ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[32])                     /* 0x40011000 */
#define PERI_MS_PPU_FX_IPC_INTR_STRUCT0_INTR    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[33])                     /* 0x40011040 */
#define PERI_MS_PPU_FX_IPC_INTR_STRUCT1_INTR    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[34])                     /* 0x40011080 */
#define PERI_MS_PPU_FX_IPC_INTR_STRUCT2_INTR    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[35])                     /* 0x400110C0 */
#define PERI_MS_PPU_FX_IPC_INTR_STRUCT3_INTR    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[36])                     /* 0x40011100 */
#define PERI_MS_PPU_FX_IPC_INTR_STRUCT4_INTR    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[37])                     /* 0x40011140 */
#define PERI_MS_PPU_FX_IPC_INTR_STRUCT5_INTR    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[38])                     /* 0x40011180 */
#define PERI_MS_PPU_FX_IPC_INTR_STRUCT6_INTR    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[39])                     /* 0x400111C0 */
#define PERI_MS_PPU_FX_IPC_INTR_STRUCT7_INTR    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[40])                     /* 0x40011200 */
#define PERI_MS_PPU_FX_PROT_SMPU_MAIN           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[41])                     /* 0x40011240 */
#define PERI_MS_PPU_FX_PROT_MPU0_MAIN           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[42])                     /* 0x40011280 */
#define PERI_MS_PPU_FX_PROT_MPU14_MAIN          ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[43])                     /* 0x400112C0 */
#define PERI_MS_PPU_FX_PROT_MPU15_MAIN          ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[44])                     /* 0x40011300 */
#define PERI_MS_PPU_FX_FLASHC_MAIN              ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[45])                     /* 0x40011340 */
#define PERI_MS_PPU_FX_FLASHC_CMD               ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[46])                     /* 0x40011380 */
#define PERI_MS_PPU_FX_FLASHC_DFT               ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[47])                     /* 0x400113C0 */
#define PERI_MS_PPU_FX_FLASHC_CM0               ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[48])                     /* 0x40011400 */
#define PERI_MS_PPU_FX_FLASHC_CM4               ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[49])                     /* 0x40011440 */
#define PERI_MS_PPU_FX_FLASHC_CRYPTO            ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[50])                     /* 0x40011480 */
#define PERI_MS_PPU_FX_FLASHC_DW0               ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[51])                     /* 0x400114C0 */
#define PERI_MS_PPU_FX_FLASHC_DW1               ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[52])                     /* 0x40011500 */
#define PERI_MS_PPU_FX_FLASHC_DMAC              ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[53])                     /* 0x40011540 */
#define PERI_MS_PPU_FX_FLASHC_FlashMgmt         ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[54])                     /* 0x40011580 */
#define PERI_MS_PPU_FX_FLASHC_MainSafety        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[55])                     /* 0x400115C0 */
#define PERI_MS_PPU_FX_FLASHC_WorkSafety        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[56])                     /* 0x40011600 */
#define PERI_MS_PPU_FX_SRSS_GENERAL             ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[57])                     /* 0x40011640 */
#define PERI_MS_PPU_FX_SRSS_MAIN                ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[58])                     /* 0x40011680 */
#define PERI_MS_PPU_FX_SRSS_SECURE              ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[59])                     /* 0x400116C0 */
#define PERI_MS_PPU_FX_MCWDT0_CONFIG            ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[60])                     /* 0x40011700 */
#define PERI_MS_PPU_FX_MCWDT1_CONFIG            ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[61])                     /* 0x40011740 */
#define PERI_MS_PPU_FX_MCWDT0_MAIN              ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[62])                     /* 0x40011780 */
#define PERI_MS_PPU_FX_MCWDT1_MAIN              ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[63])                     /* 0x400117C0 */
#define PERI_MS_PPU_FX_WDT_CONFIG               ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[64])                     /* 0x40011800 */
#define PERI_MS_PPU_FX_WDT_MAIN                 ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[65])                     /* 0x40011840 */
#define PERI_MS_PPU_FX_BACKUP_BACKUP            ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[66])                     /* 0x40011880 */
#define PERI_MS_PPU_FX_DW0_DW                   ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[67])                     /* 0x400118C0 */
#define PERI_MS_PPU_FX_DW1_DW                   ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[68])                     /* 0x40011900 */
#define PERI_MS_PPU_FX_DW0_DW_CRC               ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[69])                     /* 0x40011940 */
#define PERI_MS_PPU_FX_DW1_DW_CRC               ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[70])                     /* 0x40011980 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT0_CH        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[71])                     /* 0x400119C0 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT1_CH        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[72])                     /* 0x40011A00 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT2_CH        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[73])                     /* 0x40011A40 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT3_CH        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[74])                     /* 0x40011A80 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT4_CH        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[75])                     /* 0x40011AC0 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT5_CH        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[76])                     /* 0x40011B00 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT6_CH        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[77])                     /* 0x40011B40 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT7_CH        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[78])                     /* 0x40011B80 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT8_CH        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[79])                     /* 0x40011BC0 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT9_CH        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[80])                     /* 0x40011C00 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT10_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[81])                     /* 0x40011C40 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT11_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[82])                     /* 0x40011C80 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT12_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[83])                     /* 0x40011CC0 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT13_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[84])                     /* 0x40011D00 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT14_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[85])                     /* 0x40011D40 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT15_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[86])                     /* 0x40011D80 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT16_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[87])                     /* 0x40011DC0 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT17_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[88])                     /* 0x40011E00 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT18_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[89])                     /* 0x40011E40 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT19_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[90])                     /* 0x40011E80 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT20_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[91])                     /* 0x40011EC0 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT21_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[92])                     /* 0x40011F00 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT22_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[93])                     /* 0x40011F40 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT23_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[94])                     /* 0x40011F80 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT24_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[95])                     /* 0x40011FC0 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT25_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[96])                     /* 0x40012000 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT26_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[97])                     /* 0x40012040 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT27_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[98])                     /* 0x40012080 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT28_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[99])                     /* 0x400120C0 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT29_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[100])                    /* 0x40012100 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT30_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[101])                    /* 0x40012140 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT31_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[102])                    /* 0x40012180 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT32_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[103])                    /* 0x400121C0 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT33_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[104])                    /* 0x40012200 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT34_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[105])                    /* 0x40012240 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT35_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[106])                    /* 0x40012280 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT36_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[107])                    /* 0x400122C0 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT37_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[108])                    /* 0x40012300 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT38_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[109])                    /* 0x40012340 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT39_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[110])                    /* 0x40012380 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT40_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[111])                    /* 0x400123C0 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT41_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[112])                    /* 0x40012400 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT42_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[113])                    /* 0x40012440 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT43_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[114])                    /* 0x40012480 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT44_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[115])                    /* 0x400124C0 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT45_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[116])                    /* 0x40012500 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT46_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[117])                    /* 0x40012540 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT47_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[118])                    /* 0x40012580 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT48_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[119])                    /* 0x400125C0 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT49_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[120])                    /* 0x40012600 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT50_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[121])                    /* 0x40012640 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT51_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[122])                    /* 0x40012680 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT52_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[123])                    /* 0x400126C0 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT53_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[124])                    /* 0x40012700 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT54_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[125])                    /* 0x40012740 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT55_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[126])                    /* 0x40012780 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT56_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[127])                    /* 0x400127C0 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT57_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[128])                    /* 0x40012800 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT58_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[129])                    /* 0x40012840 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT59_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[130])                    /* 0x40012880 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT60_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[131])                    /* 0x400128C0 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT61_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[132])                    /* 0x40012900 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT62_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[133])                    /* 0x40012940 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT63_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[134])                    /* 0x40012980 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT64_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[135])                    /* 0x400129C0 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT65_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[136])                    /* 0x40012A00 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT66_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[137])                    /* 0x40012A40 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT67_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[138])                    /* 0x40012A80 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT68_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[139])                    /* 0x40012AC0 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT69_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[140])                    /* 0x40012B00 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT70_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[141])                    /* 0x40012B40 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT71_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[142])                    /* 0x40012B80 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT72_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[143])                    /* 0x40012BC0 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT73_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[144])                    /* 0x40012C00 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT74_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[145])                    /* 0x40012C40 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT75_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[146])                    /* 0x40012C80 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT76_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[147])                    /* 0x40012CC0 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT77_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[148])                    /* 0x40012D00 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT78_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[149])                    /* 0x40012D40 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT79_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[150])                    /* 0x40012D80 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT80_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[151])                    /* 0x40012DC0 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT81_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[152])                    /* 0x40012E00 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT82_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[153])                    /* 0x40012E40 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT83_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[154])                    /* 0x40012E80 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT84_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[155])                    /* 0x40012EC0 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT85_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[156])                    /* 0x40012F00 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT86_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[157])                    /* 0x40012F40 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT87_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[158])                    /* 0x40012F80 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT88_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[159])                    /* 0x40012FC0 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT0_CH        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[160])                    /* 0x40013000 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT1_CH        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[161])                    /* 0x40013040 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT2_CH        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[162])                    /* 0x40013080 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT3_CH        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[163])                    /* 0x400130C0 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT4_CH        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[164])                    /* 0x40013100 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT5_CH        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[165])                    /* 0x40013140 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT6_CH        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[166])                    /* 0x40013180 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT7_CH        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[167])                    /* 0x400131C0 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT8_CH        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[168])                    /* 0x40013200 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT9_CH        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[169])                    /* 0x40013240 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT10_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[170])                    /* 0x40013280 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT11_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[171])                    /* 0x400132C0 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT12_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[172])                    /* 0x40013300 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT13_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[173])                    /* 0x40013340 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT14_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[174])                    /* 0x40013380 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT15_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[175])                    /* 0x400133C0 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT16_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[176])                    /* 0x40013400 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT17_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[177])                    /* 0x40013440 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT18_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[178])                    /* 0x40013480 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT19_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[179])                    /* 0x400134C0 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT20_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[180])                    /* 0x40013500 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT21_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[181])                    /* 0x40013540 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT22_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[182])                    /* 0x40013580 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT23_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[183])                    /* 0x400135C0 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT24_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[184])                    /* 0x40013600 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT25_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[185])                    /* 0x40013640 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT26_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[186])                    /* 0x40013680 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT27_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[187])                    /* 0x400136C0 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT28_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[188])                    /* 0x40013700 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT29_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[189])                    /* 0x40013740 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT30_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[190])                    /* 0x40013780 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT31_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[191])                    /* 0x400137C0 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT32_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[192])                    /* 0x40013800 */
#define PERI_MS_PPU_FX_DMAC_TOP                 ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[193])                    /* 0x40013840 */
#define PERI_MS_PPU_FX_DMAC_CH0_CH              ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[194])                    /* 0x40013880 */
#define PERI_MS_PPU_FX_DMAC_CH1_CH              ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[195])                    /* 0x400138C0 */
#define PERI_MS_PPU_FX_DMAC_CH2_CH              ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[196])                    /* 0x40013900 */
#define PERI_MS_PPU_FX_DMAC_CH3_CH              ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[197])                    /* 0x40013940 */
#define PERI_MS_PPU_FX_EFUSE_CTL                ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[198])                    /* 0x40013980 */
#define PERI_MS_PPU_FX_EFUSE_DATA               ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[199])                    /* 0x400139C0 */
#define PERI_MS_PPU_FX_BIST                     ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[200])                    /* 0x40013A00 */
#define PERI_MS_PPU_FX_HSIOM_PRT0_PRT           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[201])                    /* 0x40013A40 */
#define PERI_MS_PPU_FX_HSIOM_PRT1_PRT           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[202])                    /* 0x40013A80 */
#define PERI_MS_PPU_FX_HSIOM_PRT2_PRT           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[203])                    /* 0x40013AC0 */
#define PERI_MS_PPU_FX_HSIOM_PRT3_PRT           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[204])                    /* 0x40013B00 */
#define PERI_MS_PPU_FX_HSIOM_PRT4_PRT           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[205])                    /* 0x40013B40 */
#define PERI_MS_PPU_FX_HSIOM_PRT5_PRT           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[206])                    /* 0x40013B80 */
#define PERI_MS_PPU_FX_HSIOM_PRT6_PRT           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[207])                    /* 0x40013BC0 */
#define PERI_MS_PPU_FX_HSIOM_PRT7_PRT           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[208])                    /* 0x40013C00 */
#define PERI_MS_PPU_FX_HSIOM_PRT8_PRT           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[209])                    /* 0x40013C40 */
#define PERI_MS_PPU_FX_HSIOM_PRT9_PRT           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[210])                    /* 0x40013C80 */
#define PERI_MS_PPU_FX_HSIOM_PRT10_PRT          ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[211])                    /* 0x40013CC0 */
#define PERI_MS_PPU_FX_HSIOM_PRT11_PRT          ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[212])                    /* 0x40013D00 */
#define PERI_MS_PPU_FX_HSIOM_PRT12_PRT          ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[213])                    /* 0x40013D40 */
#define PERI_MS_PPU_FX_HSIOM_PRT13_PRT          ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[214])                    /* 0x40013D80 */
#define PERI_MS_PPU_FX_HSIOM_PRT14_PRT          ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[215])                    /* 0x40013DC0 */
#define PERI_MS_PPU_FX_HSIOM_PRT15_PRT          ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[216])                    /* 0x40013E00 */
#define PERI_MS_PPU_FX_HSIOM_PRT16_PRT          ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[217])                    /* 0x40013E40 */
#define PERI_MS_PPU_FX_HSIOM_PRT17_PRT          ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[218])                    /* 0x40013E80 */
#define PERI_MS_PPU_FX_HSIOM_PRT18_PRT          ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[219])                    /* 0x40013EC0 */
#define PERI_MS_PPU_FX_HSIOM_PRT19_PRT          ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[220])                    /* 0x40013F00 */
#define PERI_MS_PPU_FX_HSIOM_PRT20_PRT          ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[221])                    /* 0x40013F40 */
#define PERI_MS_PPU_FX_HSIOM_PRT21_PRT          ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[222])                    /* 0x40013F80 */
#define PERI_MS_PPU_FX_HSIOM_PRT22_PRT          ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[223])                    /* 0x40013FC0 */
#define PERI_MS_PPU_FX_HSIOM_PRT23_PRT          ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[224])                    /* 0x40014000 */
#define PERI_MS_PPU_FX_HSIOM_AMUX               ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[225])                    /* 0x40014040 */
#define PERI_MS_PPU_FX_HSIOM_MON                ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[226])                    /* 0x40014080 */
#define PERI_MS_PPU_FX_HSIOM_ALTJTAG            ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[227])                    /* 0x400140C0 */
#define PERI_MS_PPU_FX_GPIO_PRT0_PRT            ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[228])                    /* 0x40014100 */
#define PERI_MS_PPU_FX_GPIO_PRT1_PRT            ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[229])                    /* 0x40014140 */
#define PERI_MS_PPU_FX_GPIO_PRT2_PRT            ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[230])                    /* 0x40014180 */
#define PERI_MS_PPU_FX_GPIO_PRT3_PRT            ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[231])                    /* 0x400141C0 */
#define PERI_MS_PPU_FX_GPIO_PRT4_PRT            ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[232])                    /* 0x40014200 */
#define PERI_MS_PPU_FX_GPIO_PRT5_PRT            ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[233])                    /* 0x40014240 */
#define PERI_MS_PPU_FX_GPIO_PRT6_PRT            ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[234])                    /* 0x40014280 */
#define PERI_MS_PPU_FX_GPIO_PRT7_PRT            ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[235])                    /* 0x400142C0 */
#define PERI_MS_PPU_FX_GPIO_PRT8_PRT            ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[236])                    /* 0x40014300 */
#define PERI_MS_PPU_FX_GPIO_PRT9_PRT            ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[237])                    /* 0x40014340 */
#define PERI_MS_PPU_FX_GPIO_PRT10_PRT           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[238])                    /* 0x40014380 */
#define PERI_MS_PPU_FX_GPIO_PRT11_PRT           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[239])                    /* 0x400143C0 */
#define PERI_MS_PPU_FX_GPIO_PRT12_PRT           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[240])                    /* 0x40014400 */
#define PERI_MS_PPU_FX_GPIO_PRT13_PRT           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[241])                    /* 0x40014440 */
#define PERI_MS_PPU_FX_GPIO_PRT14_PRT           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[242])                    /* 0x40014480 */
#define PERI_MS_PPU_FX_GPIO_PRT15_PRT           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[243])                    /* 0x400144C0 */
#define PERI_MS_PPU_FX_GPIO_PRT16_PRT           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[244])                    /* 0x40014500 */
#define PERI_MS_PPU_FX_GPIO_PRT17_PRT           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[245])                    /* 0x40014540 */
#define PERI_MS_PPU_FX_GPIO_PRT18_PRT           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[246])                    /* 0x40014580 */
#define PERI_MS_PPU_FX_GPIO_PRT19_PRT           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[247])                    /* 0x400145C0 */
#define PERI_MS_PPU_FX_GPIO_PRT20_PRT           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[248])                    /* 0x40014600 */
#define PERI_MS_PPU_FX_GPIO_PRT21_PRT           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[249])                    /* 0x40014640 */
#define PERI_MS_PPU_FX_GPIO_PRT22_PRT           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[250])                    /* 0x40014680 */
#define PERI_MS_PPU_FX_GPIO_PRT23_PRT           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[251])                    /* 0x400146C0 */
#define PERI_MS_PPU_FX_GPIO_PRT0_CFG            ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[252])                    /* 0x40014700 */
#define PERI_MS_PPU_FX_GPIO_PRT1_CFG            ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[253])                    /* 0x40014740 */
#define PERI_MS_PPU_FX_GPIO_PRT2_CFG            ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[254])                    /* 0x40014780 */
#define PERI_MS_PPU_FX_GPIO_PRT3_CFG            ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[255])                    /* 0x400147C0 */
#define PERI_MS_PPU_FX_GPIO_PRT4_CFG            ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[256])                    /* 0x40014800 */
#define PERI_MS_PPU_FX_GPIO_PRT5_CFG            ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[257])                    /* 0x40014840 */
#define PERI_MS_PPU_FX_GPIO_PRT6_CFG            ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[258])                    /* 0x40014880 */
#define PERI_MS_PPU_FX_GPIO_PRT7_CFG            ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[259])                    /* 0x400148C0 */
#define PERI_MS_PPU_FX_GPIO_PRT8_CFG            ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[260])                    /* 0x40014900 */
#define PERI_MS_PPU_FX_GPIO_PRT9_CFG            ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[261])                    /* 0x40014940 */
#define PERI_MS_PPU_FX_GPIO_PRT10_CFG           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[262])                    /* 0x40014980 */
#define PERI_MS_PPU_FX_GPIO_PRT11_CFG           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[263])                    /* 0x400149C0 */
#define PERI_MS_PPU_FX_GPIO_PRT12_CFG           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[264])                    /* 0x40014A00 */
#define PERI_MS_PPU_FX_GPIO_PRT13_CFG           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[265])                    /* 0x40014A40 */
#define PERI_MS_PPU_FX_GPIO_PRT14_CFG           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[266])                    /* 0x40014A80 */
#define PERI_MS_PPU_FX_GPIO_PRT15_CFG           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[267])                    /* 0x40014AC0 */
#define PERI_MS_PPU_FX_GPIO_PRT16_CFG           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[268])                    /* 0x40014B00 */
#define PERI_MS_PPU_FX_GPIO_PRT17_CFG           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[269])                    /* 0x40014B40 */
#define PERI_MS_PPU_FX_GPIO_PRT18_CFG           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[270])                    /* 0x40014B80 */
#define PERI_MS_PPU_FX_GPIO_PRT19_CFG           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[271])                    /* 0x40014BC0 */
#define PERI_MS_PPU_FX_GPIO_PRT20_CFG           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[272])                    /* 0x40014C00 */
#define PERI_MS_PPU_FX_GPIO_PRT21_CFG           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[273])                    /* 0x40014C40 */
#define PERI_MS_PPU_FX_GPIO_PRT22_CFG           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[274])                    /* 0x40014C80 */
#define PERI_MS_PPU_FX_GPIO_PRT23_CFG           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[275])                    /* 0x40014CC0 */
#define PERI_MS_PPU_FX_GPIO_GPIO                ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[276])                    /* 0x40014D00 */
#define PERI_MS_PPU_FX_GPIO_TEST                ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[277])                    /* 0x40014D40 */
#define PERI_MS_PPU_FX_SMARTIO_PRT12_PRT        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[278])                    /* 0x40014D80 */
#define PERI_MS_PPU_FX_SMARTIO_PRT13_PRT        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[279])                    /* 0x40014DC0 */
#define PERI_MS_PPU_FX_SMARTIO_PRT14_PRT        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[280])                    /* 0x40014E00 */
#define PERI_MS_PPU_FX_SMARTIO_PRT15_PRT        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[281])                    /* 0x40014E40 */
#define PERI_MS_PPU_FX_SMARTIO_PRT17_PRT        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[282])                    /* 0x40014E80 */
#define PERI_MS_PPU_FX_TCPWM0_GRP0_CNT0_CNT     ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[283])                    /* 0x40014EC0 */
#define PERI_MS_PPU_FX_TCPWM0_GRP0_CNT1_CNT     ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[284])                    /* 0x40014F00 */
#define PERI_MS_PPU_FX_TCPWM0_GRP0_CNT2_CNT     ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[285])                    /* 0x40014F40 */
#define PERI_MS_PPU_FX_TCPWM0_GRP0_CNT3_CNT     ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[286])                    /* 0x40014F80 */
#define PERI_MS_PPU_FX_TCPWM0_GRP0_CNT4_CNT     ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[287])                    /* 0x40014FC0 */
#define PERI_MS_PPU_FX_TCPWM0_GRP0_CNT5_CNT     ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[288])                    /* 0x40015000 */
#define PERI_MS_PPU_FX_TCPWM0_GRP0_CNT6_CNT     ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[289])                    /* 0x40015040 */
#define PERI_MS_PPU_FX_TCPWM0_GRP0_CNT7_CNT     ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[290])                    /* 0x40015080 */
#define PERI_MS_PPU_FX_TCPWM0_GRP0_CNT8_CNT     ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[291])                    /* 0x400150C0 */
#define PERI_MS_PPU_FX_TCPWM0_GRP0_CNT9_CNT     ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[292])                    /* 0x40015100 */
#define PERI_MS_PPU_FX_TCPWM0_GRP0_CNT10_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[293])                    /* 0x40015140 */
#define PERI_MS_PPU_FX_TCPWM0_GRP0_CNT11_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[294])                    /* 0x40015180 */
#define PERI_MS_PPU_FX_TCPWM0_GRP0_CNT12_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[295])                    /* 0x400151C0 */
#define PERI_MS_PPU_FX_TCPWM0_GRP0_CNT13_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[296])                    /* 0x40015200 */
#define PERI_MS_PPU_FX_TCPWM0_GRP0_CNT14_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[297])                    /* 0x40015240 */
#define PERI_MS_PPU_FX_TCPWM0_GRP0_CNT15_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[298])                    /* 0x40015280 */
#define PERI_MS_PPU_FX_TCPWM0_GRP0_CNT16_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[299])                    /* 0x400152C0 */
#define PERI_MS_PPU_FX_TCPWM0_GRP0_CNT17_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[300])                    /* 0x40015300 */
#define PERI_MS_PPU_FX_TCPWM0_GRP0_CNT18_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[301])                    /* 0x40015340 */
#define PERI_MS_PPU_FX_TCPWM0_GRP0_CNT19_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[302])                    /* 0x40015380 */
#define PERI_MS_PPU_FX_TCPWM0_GRP0_CNT20_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[303])                    /* 0x400153C0 */
#define PERI_MS_PPU_FX_TCPWM0_GRP0_CNT21_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[304])                    /* 0x40015400 */
#define PERI_MS_PPU_FX_TCPWM0_GRP0_CNT22_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[305])                    /* 0x40015440 */
#define PERI_MS_PPU_FX_TCPWM0_GRP0_CNT23_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[306])                    /* 0x40015480 */
#define PERI_MS_PPU_FX_TCPWM0_GRP0_CNT24_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[307])                    /* 0x400154C0 */
#define PERI_MS_PPU_FX_TCPWM0_GRP0_CNT25_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[308])                    /* 0x40015500 */
#define PERI_MS_PPU_FX_TCPWM0_GRP0_CNT26_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[309])                    /* 0x40015540 */
#define PERI_MS_PPU_FX_TCPWM0_GRP0_CNT27_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[310])                    /* 0x40015580 */
#define PERI_MS_PPU_FX_TCPWM0_GRP0_CNT28_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[311])                    /* 0x400155C0 */
#define PERI_MS_PPU_FX_TCPWM0_GRP0_CNT29_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[312])                    /* 0x40015600 */
#define PERI_MS_PPU_FX_TCPWM0_GRP0_CNT30_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[313])                    /* 0x40015640 */
#define PERI_MS_PPU_FX_TCPWM0_GRP0_CNT31_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[314])                    /* 0x40015680 */
#define PERI_MS_PPU_FX_TCPWM0_GRP0_CNT32_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[315])                    /* 0x400156C0 */
#define PERI_MS_PPU_FX_TCPWM0_GRP0_CNT33_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[316])                    /* 0x40015700 */
#define PERI_MS_PPU_FX_TCPWM0_GRP0_CNT34_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[317])                    /* 0x40015740 */
#define PERI_MS_PPU_FX_TCPWM0_GRP0_CNT35_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[318])                    /* 0x40015780 */
#define PERI_MS_PPU_FX_TCPWM0_GRP0_CNT36_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[319])                    /* 0x400157C0 */
#define PERI_MS_PPU_FX_TCPWM0_GRP0_CNT37_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[320])                    /* 0x40015800 */
#define PERI_MS_PPU_FX_TCPWM0_GRP0_CNT38_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[321])                    /* 0x40015840 */
#define PERI_MS_PPU_FX_TCPWM0_GRP0_CNT39_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[322])                    /* 0x40015880 */
#define PERI_MS_PPU_FX_TCPWM0_GRP0_CNT40_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[323])                    /* 0x400158C0 */
#define PERI_MS_PPU_FX_TCPWM0_GRP0_CNT41_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[324])                    /* 0x40015900 */
#define PERI_MS_PPU_FX_TCPWM0_GRP0_CNT42_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[325])                    /* 0x40015940 */
#define PERI_MS_PPU_FX_TCPWM0_GRP0_CNT43_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[326])                    /* 0x40015980 */
#define PERI_MS_PPU_FX_TCPWM0_GRP0_CNT44_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[327])                    /* 0x400159C0 */
#define PERI_MS_PPU_FX_TCPWM0_GRP0_CNT45_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[328])                    /* 0x40015A00 */
#define PERI_MS_PPU_FX_TCPWM0_GRP0_CNT46_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[329])                    /* 0x40015A40 */
#define PERI_MS_PPU_FX_TCPWM0_GRP0_CNT47_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[330])                    /* 0x40015A80 */
#define PERI_MS_PPU_FX_TCPWM0_GRP0_CNT48_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[331])                    /* 0x40015AC0 */
#define PERI_MS_PPU_FX_TCPWM0_GRP0_CNT49_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[332])                    /* 0x40015B00 */
#define PERI_MS_PPU_FX_TCPWM0_GRP0_CNT50_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[333])                    /* 0x40015B40 */
#define PERI_MS_PPU_FX_TCPWM0_GRP0_CNT51_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[334])                    /* 0x40015B80 */
#define PERI_MS_PPU_FX_TCPWM0_GRP0_CNT52_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[335])                    /* 0x40015BC0 */
#define PERI_MS_PPU_FX_TCPWM0_GRP0_CNT53_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[336])                    /* 0x40015C00 */
#define PERI_MS_PPU_FX_TCPWM0_GRP0_CNT54_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[337])                    /* 0x40015C40 */
#define PERI_MS_PPU_FX_TCPWM0_GRP0_CNT55_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[338])                    /* 0x40015C80 */
#define PERI_MS_PPU_FX_TCPWM0_GRP0_CNT56_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[339])                    /* 0x40015CC0 */
#define PERI_MS_PPU_FX_TCPWM0_GRP0_CNT57_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[340])                    /* 0x40015D00 */
#define PERI_MS_PPU_FX_TCPWM0_GRP0_CNT58_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[341])                    /* 0x40015D40 */
#define PERI_MS_PPU_FX_TCPWM0_GRP0_CNT59_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[342])                    /* 0x40015D80 */
#define PERI_MS_PPU_FX_TCPWM0_GRP0_CNT60_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[343])                    /* 0x40015DC0 */
#define PERI_MS_PPU_FX_TCPWM0_GRP0_CNT61_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[344])                    /* 0x40015E00 */
#define PERI_MS_PPU_FX_TCPWM0_GRP0_CNT62_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[345])                    /* 0x40015E40 */
#define PERI_MS_PPU_FX_TCPWM0_GRP1_CNT0_CNT     ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[346])                    /* 0x40015E80 */
#define PERI_MS_PPU_FX_TCPWM0_GRP1_CNT1_CNT     ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[347])                    /* 0x40015EC0 */
#define PERI_MS_PPU_FX_TCPWM0_GRP1_CNT2_CNT     ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[348])                    /* 0x40015F00 */
#define PERI_MS_PPU_FX_TCPWM0_GRP1_CNT3_CNT     ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[349])                    /* 0x40015F40 */
#define PERI_MS_PPU_FX_TCPWM0_GRP1_CNT4_CNT     ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[350])                    /* 0x40015F80 */
#define PERI_MS_PPU_FX_TCPWM0_GRP1_CNT5_CNT     ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[351])                    /* 0x40015FC0 */
#define PERI_MS_PPU_FX_TCPWM0_GRP1_CNT6_CNT     ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[352])                    /* 0x40016000 */
#define PERI_MS_PPU_FX_TCPWM0_GRP1_CNT7_CNT     ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[353])                    /* 0x40016040 */
#define PERI_MS_PPU_FX_TCPWM0_GRP1_CNT8_CNT     ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[354])                    /* 0x40016080 */
#define PERI_MS_PPU_FX_TCPWM0_GRP1_CNT9_CNT     ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[355])                    /* 0x400160C0 */
#define PERI_MS_PPU_FX_TCPWM0_GRP1_CNT10_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[356])                    /* 0x40016100 */
#define PERI_MS_PPU_FX_TCPWM0_GRP1_CNT11_CNT    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[357])                    /* 0x40016140 */
#define PERI_MS_PPU_FX_TCPWM0_GRP2_CNT0_CNT     ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[358])                    /* 0x40016180 */
#define PERI_MS_PPU_FX_TCPWM0_GRP2_CNT1_CNT     ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[359])                    /* 0x400161C0 */
#define PERI_MS_PPU_FX_TCPWM0_GRP2_CNT2_CNT     ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[360])                    /* 0x40016200 */
#define PERI_MS_PPU_FX_TCPWM0_GRP2_CNT3_CNT     ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[361])                    /* 0x40016240 */
#define PERI_MS_PPU_FX_EVTGEN0                  ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[362])                    /* 0x40016280 */
#define PERI_MS_PPU_FX_LIN0_MAIN                ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[363])                    /* 0x400162C0 */
#define PERI_MS_PPU_FX_LIN0_CH0_CH              ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[364])                    /* 0x40016300 */
#define PERI_MS_PPU_FX_LIN0_CH1_CH              ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[365])                    /* 0x40016340 */
#define PERI_MS_PPU_FX_LIN0_CH2_CH              ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[366])                    /* 0x40016380 */
#define PERI_MS_PPU_FX_LIN0_CH3_CH              ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[367])                    /* 0x400163C0 */
#define PERI_MS_PPU_FX_LIN0_CH4_CH              ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[368])                    /* 0x40016400 */
#define PERI_MS_PPU_FX_LIN0_CH5_CH              ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[369])                    /* 0x40016440 */
#define PERI_MS_PPU_FX_LIN0_CH6_CH              ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[370])                    /* 0x40016480 */
#define PERI_MS_PPU_FX_LIN0_CH7_CH              ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[371])                    /* 0x400164C0 */
#define PERI_MS_PPU_FX_CANFD0_CH0_CH            ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[372])                    /* 0x40016500 */
#define PERI_MS_PPU_FX_CANFD0_CH1_CH            ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[373])                    /* 0x40016540 */
#define PERI_MS_PPU_FX_CANFD0_CH2_CH            ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[374])                    /* 0x40016580 */
#define PERI_MS_PPU_FX_CANFD1_CH0_CH            ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[375])                    /* 0x400165C0 */
#define PERI_MS_PPU_FX_CANFD1_CH1_CH            ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[376])                    /* 0x40016600 */
#define PERI_MS_PPU_FX_CANFD1_CH2_CH            ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[377])                    /* 0x40016640 */
#define PERI_MS_PPU_FX_CANFD0_MAIN              ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[378])                    /* 0x40016680 */
#define PERI_MS_PPU_FX_CANFD1_MAIN              ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[379])                    /* 0x400166C0 */
#define PERI_MS_PPU_FX_CANFD0_BUF               ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[380])                    /* 0x40016700 */
#define PERI_MS_PPU_FX_CANFD1_BUF               ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[381])                    /* 0x40016740 */
#define PERI_MS_PPU_FX_SCB0                     ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[382])                    /* 0x40016780 */
#define PERI_MS_PPU_FX_SCB1                     ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[383])                    /* 0x400167C0 */
#define PERI_MS_PPU_FX_SCB2                     ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[384])                    /* 0x40016800 */
#define PERI_MS_PPU_FX_SCB3                     ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[385])                    /* 0x40016840 */
#define PERI_MS_PPU_FX_SCB4                     ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[386])                    /* 0x40016880 */
#define PERI_MS_PPU_FX_SCB5                     ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[387])                    /* 0x400168C0 */
#define PERI_MS_PPU_FX_SCB6                     ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[388])                    /* 0x40016900 */
#define PERI_MS_PPU_FX_SCB7                     ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[389])                    /* 0x40016940 */
#define PERI_MS_PPU_FX_PASS0_SAR0_SAR           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[390])                    /* 0x40016980 */
#define PERI_MS_PPU_FX_PASS0_SAR1_SAR           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[391])                    /* 0x400169C0 */
#define PERI_MS_PPU_FX_PASS0_SAR2_SAR           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[392])                    /* 0x40016A00 */
#define PERI_MS_PPU_FX_PASS0_SAR0_CH0_CH        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[393])                    /* 0x40016A40 */
#define PERI_MS_PPU_FX_PASS0_SAR0_CH1_CH        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[394])                    /* 0x40016A80 */
#define PERI_MS_PPU_FX_PASS0_SAR0_CH2_CH        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[395])                    /* 0x40016AC0 */
#define PERI_MS_PPU_FX_PASS0_SAR0_CH3_CH        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[396])                    /* 0x40016B00 */
#define PERI_MS_PPU_FX_PASS0_SAR0_CH4_CH        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[397])                    /* 0x40016B40 */
#define PERI_MS_PPU_FX_PASS0_SAR0_CH5_CH        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[398])                    /* 0x40016B80 */
#define PERI_MS_PPU_FX_PASS0_SAR0_CH6_CH        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[399])                    /* 0x40016BC0 */
#define PERI_MS_PPU_FX_PASS0_SAR0_CH7_CH        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[400])                    /* 0x40016C00 */
#define PERI_MS_PPU_FX_PASS0_SAR0_CH8_CH        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[401])                    /* 0x40016C40 */
#define PERI_MS_PPU_FX_PASS0_SAR0_CH9_CH        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[402])                    /* 0x40016C80 */
#define PERI_MS_PPU_FX_PASS0_SAR0_CH10_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[403])                    /* 0x40016CC0 */
#define PERI_MS_PPU_FX_PASS0_SAR0_CH11_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[404])                    /* 0x40016D00 */
#define PERI_MS_PPU_FX_PASS0_SAR0_CH12_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[405])                    /* 0x40016D40 */
#define PERI_MS_PPU_FX_PASS0_SAR0_CH13_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[406])                    /* 0x40016D80 */
#define PERI_MS_PPU_FX_PASS0_SAR0_CH14_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[407])                    /* 0x40016DC0 */
#define PERI_MS_PPU_FX_PASS0_SAR0_CH15_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[408])                    /* 0x40016E00 */
#define PERI_MS_PPU_FX_PASS0_SAR0_CH16_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[409])                    /* 0x40016E40 */
#define PERI_MS_PPU_FX_PASS0_SAR0_CH17_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[410])                    /* 0x40016E80 */
#define PERI_MS_PPU_FX_PASS0_SAR0_CH18_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[411])                    /* 0x40016EC0 */
#define PERI_MS_PPU_FX_PASS0_SAR0_CH19_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[412])                    /* 0x40016F00 */
#define PERI_MS_PPU_FX_PASS0_SAR0_CH20_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[413])                    /* 0x40016F40 */
#define PERI_MS_PPU_FX_PASS0_SAR0_CH21_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[414])                    /* 0x40016F80 */
#define PERI_MS_PPU_FX_PASS0_SAR0_CH22_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[415])                    /* 0x40016FC0 */
#define PERI_MS_PPU_FX_PASS0_SAR0_CH23_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[416])                    /* 0x40017000 */
#define PERI_MS_PPU_FX_PASS0_SAR1_CH0_CH        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[417])                    /* 0x40017040 */
#define PERI_MS_PPU_FX_PASS0_SAR1_CH1_CH        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[418])                    /* 0x40017080 */
#define PERI_MS_PPU_FX_PASS0_SAR1_CH2_CH        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[419])                    /* 0x400170C0 */
#define PERI_MS_PPU_FX_PASS0_SAR1_CH3_CH        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[420])                    /* 0x40017100 */
#define PERI_MS_PPU_FX_PASS0_SAR1_CH4_CH        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[421])                    /* 0x40017140 */
#define PERI_MS_PPU_FX_PASS0_SAR1_CH5_CH        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[422])                    /* 0x40017180 */
#define PERI_MS_PPU_FX_PASS0_SAR1_CH6_CH        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[423])                    /* 0x400171C0 */
#define PERI_MS_PPU_FX_PASS0_SAR1_CH7_CH        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[424])                    /* 0x40017200 */
#define PERI_MS_PPU_FX_PASS0_SAR1_CH8_CH        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[425])                    /* 0x40017240 */
#define PERI_MS_PPU_FX_PASS0_SAR1_CH9_CH        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[426])                    /* 0x40017280 */
#define PERI_MS_PPU_FX_PASS0_SAR1_CH10_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[427])                    /* 0x400172C0 */
#define PERI_MS_PPU_FX_PASS0_SAR1_CH11_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[428])                    /* 0x40017300 */
#define PERI_MS_PPU_FX_PASS0_SAR1_CH12_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[429])                    /* 0x40017340 */
#define PERI_MS_PPU_FX_PASS0_SAR1_CH13_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[430])                    /* 0x40017380 */
#define PERI_MS_PPU_FX_PASS0_SAR1_CH14_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[431])                    /* 0x400173C0 */
#define PERI_MS_PPU_FX_PASS0_SAR1_CH15_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[432])                    /* 0x40017400 */
#define PERI_MS_PPU_FX_PASS0_SAR1_CH16_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[433])                    /* 0x40017440 */
#define PERI_MS_PPU_FX_PASS0_SAR1_CH17_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[434])                    /* 0x40017480 */
#define PERI_MS_PPU_FX_PASS0_SAR1_CH18_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[435])                    /* 0x400174C0 */
#define PERI_MS_PPU_FX_PASS0_SAR1_CH19_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[436])                    /* 0x40017500 */
#define PERI_MS_PPU_FX_PASS0_SAR1_CH20_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[437])                    /* 0x40017540 */
#define PERI_MS_PPU_FX_PASS0_SAR1_CH21_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[438])                    /* 0x40017580 */
#define PERI_MS_PPU_FX_PASS0_SAR1_CH22_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[439])                    /* 0x400175C0 */
#define PERI_MS_PPU_FX_PASS0_SAR1_CH23_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[440])                    /* 0x40017600 */
#define PERI_MS_PPU_FX_PASS0_SAR1_CH24_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[441])                    /* 0x40017640 */
#define PERI_MS_PPU_FX_PASS0_SAR1_CH25_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[442])                    /* 0x40017680 */
#define PERI_MS_PPU_FX_PASS0_SAR1_CH26_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[443])                    /* 0x400176C0 */
#define PERI_MS_PPU_FX_PASS0_SAR1_CH27_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[444])                    /* 0x40017700 */
#define PERI_MS_PPU_FX_PASS0_SAR1_CH28_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[445])                    /* 0x40017740 */
#define PERI_MS_PPU_FX_PASS0_SAR1_CH29_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[446])                    /* 0x40017780 */
#define PERI_MS_PPU_FX_PASS0_SAR1_CH30_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[447])                    /* 0x400177C0 */
#define PERI_MS_PPU_FX_PASS0_SAR1_CH31_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[448])                    /* 0x40017800 */
#define PERI_MS_PPU_FX_PASS0_SAR2_CH0_CH        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[449])                    /* 0x40017840 */
#define PERI_MS_PPU_FX_PASS0_SAR2_CH1_CH        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[450])                    /* 0x40017880 */
#define PERI_MS_PPU_FX_PASS0_SAR2_CH2_CH        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[451])                    /* 0x400178C0 */
#define PERI_MS_PPU_FX_PASS0_SAR2_CH3_CH        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[452])                    /* 0x40017900 */
#define PERI_MS_PPU_FX_PASS0_SAR2_CH4_CH        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[453])                    /* 0x40017940 */
#define PERI_MS_PPU_FX_PASS0_SAR2_CH5_CH        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[454])                    /* 0x40017980 */
#define PERI_MS_PPU_FX_PASS0_SAR2_CH6_CH        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[455])                    /* 0x400179C0 */
#define PERI_MS_PPU_FX_PASS0_SAR2_CH7_CH        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[456])                    /* 0x40017A00 */
#define PERI_MS_PPU_FX_PASS0_TOP                ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[457])                    /* 0x40017A40 */

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
#define CSV_REF                                 ((CSV_REF_Type*) &SRSS->CSV_REF_STRUCT)                           /* 0x40261710 */
#define CSV_REF_CSV                             ((CSV_REF_CSV_Type*) &SRSS->CSV_REF_STRUCT.CSV)                   /* 0x40261710 */
#define CSV_LF                                  ((CSV_LF_Type*) &SRSS->CSV_LF_STRUCT)                             /* 0x40261720 */
#define CSV_LF_CSV                              ((CSV_LF_CSV_Type*) &SRSS->CSV_LF_STRUCT.CSV)                     /* 0x40261720 */
#define CSV_ILO                                 ((CSV_ILO_Type*) &SRSS->CSV_ILO_STRUCT)                           /* 0x40261730 */
#define CSV_ILO_CSV                             ((CSV_ILO_CSV_Type*) &SRSS->CSV_ILO_STRUCT.CSV)                   /* 0x40261730 */
#define MCWDT0                                  ((MCWDT_Type*) &SRSS->MCWDT[0])                                   /* 0x40268000 */
#define MCWDT1                                  ((MCWDT_Type*) &SRSS->MCWDT[1])                                   /* 0x40268100 */
#define MCWDT0_CTR0                             ((MCWDT_CTR_Type*) &SRSS->MCWDT[0].CTR[0])                        /* 0x40268000 */
#define MCWDT0_CTR1                             ((MCWDT_CTR_Type*) &SRSS->MCWDT[0].CTR[1])                        /* 0x40268020 */
#define MCWDT1_CTR0                             ((MCWDT_CTR_Type*) &SRSS->MCWDT[1].CTR[0])                        /* 0x40268100 */
#define MCWDT1_CTR1                             ((MCWDT_CTR_Type*) &SRSS->MCWDT[1].CTR[1])                        /* 0x40268120 */
#define WDT                                     ((WDT_Type*) &SRSS->WDT_STRUCT)                                   /* 0x4026C000 */

/*******************************************************************************
*                                    BACKUP
*******************************************************************************/

#define BACKUP_BASE                             0x40270000UL
#define BACKUP                                  ((BACKUP_Type*) BACKUP_BASE)                                      /* 0x40270000 */

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
#define DW0_CH_STRUCT76                         ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[76])                        /* 0x40289300 */
#define DW0_CH_STRUCT77                         ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[77])                        /* 0x40289340 */
#define DW0_CH_STRUCT78                         ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[78])                        /* 0x40289380 */
#define DW0_CH_STRUCT79                         ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[79])                        /* 0x402893C0 */
#define DW0_CH_STRUCT80                         ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[80])                        /* 0x40289400 */
#define DW0_CH_STRUCT81                         ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[81])                        /* 0x40289440 */
#define DW0_CH_STRUCT82                         ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[82])                        /* 0x40289480 */
#define DW0_CH_STRUCT83                         ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[83])                        /* 0x402894C0 */
#define DW0_CH_STRUCT84                         ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[84])                        /* 0x40289500 */
#define DW0_CH_STRUCT85                         ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[85])                        /* 0x40289540 */
#define DW0_CH_STRUCT86                         ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[86])                        /* 0x40289580 */
#define DW0_CH_STRUCT87                         ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[87])                        /* 0x402895C0 */
#define DW0_CH_STRUCT88                         ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[88])                        /* 0x40289600 */
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

/*******************************************************************************
*                                     DMAC
*******************************************************************************/

#define DMAC_BASE                               0x402A0000UL
#define DMAC                                    ((DMAC_Type*) DMAC_BASE)                                          /* 0x402A0000 */
#define DMAC_CH0                                ((DMAC_CH_Type*) &DMAC->CH[0])                                    /* 0x402A1000 */
#define DMAC_CH1                                ((DMAC_CH_Type*) &DMAC->CH[1])                                    /* 0x402A1100 */
#define DMAC_CH2                                ((DMAC_CH_Type*) &DMAC->CH[2])                                    /* 0x402A1200 */
#define DMAC_CH3                                ((DMAC_CH_Type*) &DMAC->CH[3])                                    /* 0x402A1300 */

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

/*******************************************************************************
*                                   SMARTIO
*******************************************************************************/

#define SMARTIO_BASE                            0x40320000UL
#define SMARTIO                                 ((SMARTIO_Type*) SMARTIO_BASE)                                    /* 0x40320000 */
#define SMARTIO_PRT12                           ((SMARTIO_PRT_Type*) &SMARTIO->PRT[12])                           /* 0x40320C00 */
#define SMARTIO_PRT13                           ((SMARTIO_PRT_Type*) &SMARTIO->PRT[13])                           /* 0x40320D00 */
#define SMARTIO_PRT14                           ((SMARTIO_PRT_Type*) &SMARTIO->PRT[14])                           /* 0x40320E00 */
#define SMARTIO_PRT15                           ((SMARTIO_PRT_Type*) &SMARTIO->PRT[15])                           /* 0x40320F00 */
#define SMARTIO_PRT17                           ((SMARTIO_PRT_Type*) &SMARTIO->PRT[17])                           /* 0x40321100 */

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
#define TCPWM0_GRP0_CNT38                       ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[0].CNT[38])                   /* 0x40381300 */
#define TCPWM0_GRP0_CNT39                       ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[0].CNT[39])                   /* 0x40381380 */
#define TCPWM0_GRP0_CNT40                       ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[0].CNT[40])                   /* 0x40381400 */
#define TCPWM0_GRP0_CNT41                       ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[0].CNT[41])                   /* 0x40381480 */
#define TCPWM0_GRP0_CNT42                       ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[0].CNT[42])                   /* 0x40381500 */
#define TCPWM0_GRP0_CNT43                       ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[0].CNT[43])                   /* 0x40381580 */
#define TCPWM0_GRP0_CNT44                       ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[0].CNT[44])                   /* 0x40381600 */
#define TCPWM0_GRP0_CNT45                       ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[0].CNT[45])                   /* 0x40381680 */
#define TCPWM0_GRP0_CNT46                       ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[0].CNT[46])                   /* 0x40381700 */
#define TCPWM0_GRP0_CNT47                       ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[0].CNT[47])                   /* 0x40381780 */
#define TCPWM0_GRP0_CNT48                       ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[0].CNT[48])                   /* 0x40381800 */
#define TCPWM0_GRP0_CNT49                       ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[0].CNT[49])                   /* 0x40381880 */
#define TCPWM0_GRP0_CNT50                       ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[0].CNT[50])                   /* 0x40381900 */
#define TCPWM0_GRP0_CNT51                       ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[0].CNT[51])                   /* 0x40381980 */
#define TCPWM0_GRP0_CNT52                       ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[0].CNT[52])                   /* 0x40381A00 */
#define TCPWM0_GRP0_CNT53                       ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[0].CNT[53])                   /* 0x40381A80 */
#define TCPWM0_GRP0_CNT54                       ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[0].CNT[54])                   /* 0x40381B00 */
#define TCPWM0_GRP0_CNT55                       ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[0].CNT[55])                   /* 0x40381B80 */
#define TCPWM0_GRP0_CNT56                       ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[0].CNT[56])                   /* 0x40381C00 */
#define TCPWM0_GRP0_CNT57                       ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[0].CNT[57])                   /* 0x40381C80 */
#define TCPWM0_GRP0_CNT58                       ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[0].CNT[58])                   /* 0x40381D00 */
#define TCPWM0_GRP0_CNT59                       ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[0].CNT[59])                   /* 0x40381D80 */
#define TCPWM0_GRP0_CNT60                       ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[0].CNT[60])                   /* 0x40381E00 */
#define TCPWM0_GRP0_CNT61                       ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[0].CNT[61])                   /* 0x40381E80 */
#define TCPWM0_GRP0_CNT62                       ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[0].CNT[62])                   /* 0x40381F00 */
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

/*******************************************************************************
*                                     LIN
*******************************************************************************/

#define LIN0_BASE                               0x40500000UL
#define LIN0                                    ((LIN_Type*) LIN0_BASE)                                           /* 0x40500000 */
#define LIN0_CH0                                ((LIN_CH_Type*) &LIN0->CH[0])                                     /* 0x40508000 */
#define LIN0_CH1                                ((LIN_CH_Type*) &LIN0->CH[1])                                     /* 0x40508100 */
#define LIN0_CH2                                ((LIN_CH_Type*) &LIN0->CH[2])                                     /* 0x40508200 */
#define LIN0_CH3                                ((LIN_CH_Type*) &LIN0->CH[3])                                     /* 0x40508300 */
#define LIN0_CH4                                ((LIN_CH_Type*) &LIN0->CH[4])                                     /* 0x40508400 */
#define LIN0_CH6                                ((LIN_CH_Type*) &LIN0->CH[6])                                     /* 0x40508600 */
#define LIN0_CH7                                ((LIN_CH_Type*) &LIN0->CH[7])                                     /* 0x40508700 */

/*******************************************************************************
*                                    CANFD
*******************************************************************************/

#define CANFD0_BASE                             0x40520000UL
#define CANFD1_BASE                             0x40540000UL
#define CANFD0                                  ((CANFD_Type*) CANFD0_BASE)                                       /* 0x40520000 */
#define CANFD1                                  ((CANFD_Type*) CANFD1_BASE)                                       /* 0x40540000 */
#define CANFD0_CH0                              ((CANFD_CH_Type*) &CANFD0->CH[0])                                 /* 0x40520000 */
#define CANFD0_CH1                              ((CANFD_CH_Type*) &CANFD0->CH[1])                                 /* 0x40520200 */
#define CANFD0_CH2                              ((CANFD_CH_Type*) &CANFD0->CH[2])                                 /* 0x40520400 */
#define CANFD1_CH0                              ((CANFD_CH_Type*) &CANFD1->CH[0])                                 /* 0x40540000 */
#define CANFD1_CH1                              ((CANFD_CH_Type*) &CANFD1->CH[1])                                 /* 0x40540200 */
#define CANFD1_CH2                              ((CANFD_CH_Type*) &CANFD1->CH[2])                                 /* 0x40540400 */
#define CANFD0_CH0_M_TTCAN                      ((CANFD_CH_M_TTCAN_Type*) &CANFD0->CH[0].M_TTCAN)                 /* 0x40520000 */
#define CANFD0_CH1_M_TTCAN                      ((CANFD_CH_M_TTCAN_Type*) &CANFD0->CH[1].M_TTCAN)                 /* 0x40520200 */
#define CANFD0_CH2_M_TTCAN                      ((CANFD_CH_M_TTCAN_Type*) &CANFD0->CH[2].M_TTCAN)                 /* 0x40520400 */
#define CANFD1_CH0_M_TTCAN                      ((CANFD_CH_M_TTCAN_Type*) &CANFD1->CH[0].M_TTCAN)                 /* 0x40540000 */
#define CANFD1_CH1_M_TTCAN                      ((CANFD_CH_M_TTCAN_Type*) &CANFD1->CH[1].M_TTCAN)                 /* 0x40540200 */
#define CANFD1_CH2_M_TTCAN                      ((CANFD_CH_M_TTCAN_Type*) &CANFD1->CH[2].M_TTCAN)                 /* 0x40540400 */

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
#define SCB0                                    ((CySCB_Type*) SCB0_BASE)                                         /* 0x40600000 */
#define SCB1                                    ((CySCB_Type*) SCB1_BASE)                                         /* 0x40610000 */
#define SCB2                                    ((CySCB_Type*) SCB2_BASE)                                         /* 0x40620000 */
#define SCB3                                    ((CySCB_Type*) SCB3_BASE)                                         /* 0x40630000 */
#define SCB4                                    ((CySCB_Type*) SCB4_BASE)                                         /* 0x40640000 */
#define SCB5                                    ((CySCB_Type*) SCB5_BASE)                                         /* 0x40650000 */
#define SCB6                                    ((CySCB_Type*) SCB6_BASE)                                         /* 0x40660000 */
#define SCB7                                    ((CySCB_Type*) SCB7_BASE)                                         /* 0x40670000 */

/*******************************************************************************
*                                     PASS
*******************************************************************************/

#define PASS0_BASE                              0x40900000UL
#define PASS0                                   ((PASS_Type*) PASS0_BASE)                                         /* 0x40900000 */
#define PASS0_SAR0                              ((PASS_SAR_Type*) &PASS0->SAR[0])                                 /* 0x40900000 */
#define PASS0_SAR1                              ((PASS_SAR_Type*) &PASS0->SAR[1])                                 /* 0x40901000 */
#define PASS0_SAR2                              ((PASS_SAR_Type*) &PASS0->SAR[2])                                 /* 0x40902000 */
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
#define PASS0_SAR1_CH0                          ((PASS_SAR_CH_Type*) &PASS0->SAR[1].CH[0])                        /* 0x40901800 */
#define PASS0_SAR1_CH1                          ((PASS_SAR_CH_Type*) &PASS0->SAR[1].CH[1])                        /* 0x40901840 */
#define PASS0_SAR1_CH2                          ((PASS_SAR_CH_Type*) &PASS0->SAR[1].CH[2])                        /* 0x40901880 */
#define PASS0_SAR1_CH3                          ((PASS_SAR_CH_Type*) &PASS0->SAR[1].CH[3])                        /* 0x409018C0 */
#define PASS0_SAR1_CH4                          ((PASS_SAR_CH_Type*) &PASS0->SAR[1].CH[4])                        /* 0x40901900 */
#define PASS0_SAR1_CH5                          ((PASS_SAR_CH_Type*) &PASS0->SAR[1].CH[5])                        /* 0x40901940 */
#define PASS0_SAR1_CH6                          ((PASS_SAR_CH_Type*) &PASS0->SAR[1].CH[6])                        /* 0x40901980 */
#define PASS0_SAR1_CH7                          ((PASS_SAR_CH_Type*) &PASS0->SAR[1].CH[7])                        /* 0x409019C0 */
#define PASS0_SAR1_CH8                          ((PASS_SAR_CH_Type*) &PASS0->SAR[1].CH[8])                        /* 0x40901A00 */
#define PASS0_SAR1_CH9                          ((PASS_SAR_CH_Type*) &PASS0->SAR[1].CH[9])                        /* 0x40901A40 */
#define PASS0_SAR1_CH10                         ((PASS_SAR_CH_Type*) &PASS0->SAR[1].CH[10])                       /* 0x40901A80 */
#define PASS0_SAR1_CH11                         ((PASS_SAR_CH_Type*) &PASS0->SAR[1].CH[11])                       /* 0x40901AC0 */
#define PASS0_SAR1_CH12                         ((PASS_SAR_CH_Type*) &PASS0->SAR[1].CH[12])                       /* 0x40901B00 */
#define PASS0_SAR1_CH13                         ((PASS_SAR_CH_Type*) &PASS0->SAR[1].CH[13])                       /* 0x40901B40 */
#define PASS0_SAR1_CH14                         ((PASS_SAR_CH_Type*) &PASS0->SAR[1].CH[14])                       /* 0x40901B80 */
#define PASS0_SAR1_CH15                         ((PASS_SAR_CH_Type*) &PASS0->SAR[1].CH[15])                       /* 0x40901BC0 */
#define PASS0_SAR1_CH16                         ((PASS_SAR_CH_Type*) &PASS0->SAR[1].CH[16])                       /* 0x40901C00 */
#define PASS0_SAR1_CH17                         ((PASS_SAR_CH_Type*) &PASS0->SAR[1].CH[17])                       /* 0x40901C40 */
#define PASS0_SAR1_CH18                         ((PASS_SAR_CH_Type*) &PASS0->SAR[1].CH[18])                       /* 0x40901C80 */
#define PASS0_SAR1_CH19                         ((PASS_SAR_CH_Type*) &PASS0->SAR[1].CH[19])                       /* 0x40901CC0 */
#define PASS0_SAR1_CH20                         ((PASS_SAR_CH_Type*) &PASS0->SAR[1].CH[20])                       /* 0x40901D00 */
#define PASS0_SAR1_CH21                         ((PASS_SAR_CH_Type*) &PASS0->SAR[1].CH[21])                       /* 0x40901D40 */
#define PASS0_SAR1_CH22                         ((PASS_SAR_CH_Type*) &PASS0->SAR[1].CH[22])                       /* 0x40901D80 */
#define PASS0_SAR1_CH23                         ((PASS_SAR_CH_Type*) &PASS0->SAR[1].CH[23])                       /* 0x40901DC0 */
#define PASS0_SAR1_CH24                         ((PASS_SAR_CH_Type*) &PASS0->SAR[1].CH[24])                       /* 0x40901E00 */
#define PASS0_SAR1_CH25                         ((PASS_SAR_CH_Type*) &PASS0->SAR[1].CH[25])                       /* 0x40901E40 */
#define PASS0_SAR1_CH26                         ((PASS_SAR_CH_Type*) &PASS0->SAR[1].CH[26])                       /* 0x40901E80 */
#define PASS0_SAR1_CH27                         ((PASS_SAR_CH_Type*) &PASS0->SAR[1].CH[27])                       /* 0x40901EC0 */
#define PASS0_SAR1_CH28                         ((PASS_SAR_CH_Type*) &PASS0->SAR[1].CH[28])                       /* 0x40901F00 */
#define PASS0_SAR1_CH29                         ((PASS_SAR_CH_Type*) &PASS0->SAR[1].CH[29])                       /* 0x40901F40 */
#define PASS0_SAR1_CH30                         ((PASS_SAR_CH_Type*) &PASS0->SAR[1].CH[30])                       /* 0x40901F80 */
#define PASS0_SAR1_CH31                         ((PASS_SAR_CH_Type*) &PASS0->SAR[1].CH[31])                       /* 0x40901FC0 */
#define PASS0_SAR2_CH0                          ((PASS_SAR_CH_Type*) &PASS0->SAR[2].CH[0])                        /* 0x40902800 */
#define PASS0_SAR2_CH1                          ((PASS_SAR_CH_Type*) &PASS0->SAR[2].CH[1])                        /* 0x40902840 */
#define PASS0_SAR2_CH2                          ((PASS_SAR_CH_Type*) &PASS0->SAR[2].CH[2])                        /* 0x40902880 */
#define PASS0_SAR2_CH3                          ((PASS_SAR_CH_Type*) &PASS0->SAR[2].CH[3])                        /* 0x409028C0 */
#define PASS0_SAR2_CH4                          ((PASS_SAR_CH_Type*) &PASS0->SAR[2].CH[4])                        /* 0x40902900 */
#define PASS0_SAR2_CH5                          ((PASS_SAR_CH_Type*) &PASS0->SAR[2].CH[5])                        /* 0x40902940 */
#define PASS0_SAR2_CH6                          ((PASS_SAR_CH_Type*) &PASS0->SAR[2].CH[6])                        /* 0x40902980 */
#define PASS0_SAR2_CH7                          ((PASS_SAR_CH_Type*) &PASS0->SAR[2].CH[7])                        /* 0x409029C0 */
#define PASS0_EPASS_MMIO                        ((PASS_EPASS_MMIO_Type*) &PASS0->EPASS_MMIO)                      /* 0x409F0000 */

/** \} CYT2B75CAE */

#endif /* _CYT2B75CAE_H_ */


/* [] END OF FILE */
