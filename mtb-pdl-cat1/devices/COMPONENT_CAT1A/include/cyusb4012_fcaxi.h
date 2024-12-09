/***************************************************************************//**
* \file cyusb4012_fcaxi.h
*
* \brief
* CYUSB4012-FCAXI device header
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

#ifndef _CYUSB4012_FCAXI_H_
#define _CYUSB4012_FCAXI_H_

/**
* \addtogroup group_device CYUSB4012-FCAXI
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
  /* CYUSB4012-FCAXI User Interrupt Numbers */
  NvicMux0_IRQn                     =   0,      /*!<   0 [DeepSleep] CPU User Interrupt #0 */
  NvicMux1_IRQn                     =   1,      /*!<   1 [DeepSleep] CPU User Interrupt #1 */
  NvicMux2_IRQn                     =   2,      /*!<   2 [DeepSleep] CPU User Interrupt #2 */
  NvicMux3_IRQn                     =   3,      /*!<   3 [DeepSleep] CPU User Interrupt #3 */
  NvicMux4_IRQn                     =   4,      /*!<   4 [DeepSleep] CPU User Interrupt #4 */
  NvicMux5_IRQn                     =   5,      /*!<   5 [DeepSleep] CPU User Interrupt #5 */
  NvicMux6_IRQn                     =   6,      /*!<   6 [DeepSleep] CPU User Interrupt #6 */
  NvicMux7_IRQn                     =   7,      /*!<   7 [DeepSleep] CPU User Interrupt #7 */
  /* CYUSB4012-FCAXI Internal SW Interrupt Numbers */
  Internal0_IRQn                    =   8,      /*!<   8 [Active] Internal SW Interrupt #0 */
  Internal1_IRQn                    =   9,      /*!<   9 [Active] Internal SW Interrupt #1 */
  Internal2_IRQn                    =  10,      /*!<  10 [Active] Internal SW Interrupt #2 */
  Internal3_IRQn                    =  11,      /*!<  11 [Active] Internal SW Interrupt #3 */
  Internal4_IRQn                    =  12,      /*!<  12 [Active] Internal SW Interrupt #4 */
  Internal5_IRQn                    =  13,      /*!<  13 [Active] Internal SW Interrupt #5 */
  Internal6_IRQn                    =  14,      /*!<  14 [Active] Internal SW Interrupt #6 */
  Internal7_IRQn                    =  15,      /*!<  15 [Active] Internal SW Interrupt #7 */
  unconnected_IRQn                  =1023       /*!< 1023 Unconnected */
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
  /* CYUSB4012-FCAXI Peripheral Interrupt Numbers */
  ioss_interrupts_gpio_dpslp_0_IRQn =   0,      /*!<   0 [DeepSleep] GPIO Port Interrupt #0 */
  ioss_interrupts_gpio_dpslp_1_IRQn =   1,      /*!<   1 [DeepSleep] GPIO Port Interrupt #1 */
  ioss_interrupts_gpio_dpslp_4_IRQn =   2,      /*!<   2 [DeepSleep] GPIO Port Interrupt #4 */
  ioss_interrupts_gpio_dpslp_5_IRQn =   3,      /*!<   3 [DeepSleep] GPIO Port Interrupt #5 */
  ioss_interrupts_gpio_dpslp_6_IRQn =   4,      /*!<   4 [DeepSleep] GPIO Port Interrupt #6 */
  ioss_interrupts_gpio_dpslp_7_IRQn =   5,      /*!<   5 [DeepSleep] GPIO Port Interrupt #7 */
  ioss_interrupts_gpio_dpslp_8_IRQn =   6,      /*!<   6 [DeepSleep] GPIO Port Interrupt #8 */
  ioss_interrupts_gpio_dpslp_9_IRQn =   7,      /*!<   7 [DeepSleep] GPIO Port Interrupt #9 */
  ioss_interrupts_gpio_dpslp_10_IRQn =   8,     /*!<   8 [DeepSleep] GPIO Port Interrupt #10 */
  ioss_interrupts_gpio_dpslp_11_IRQn =   9,     /*!<   9 [DeepSleep] GPIO Port Interrupt #11 */
  ioss_interrupts_gpio_dpslp_12_IRQn =  10,     /*!<  10 [DeepSleep] GPIO Port Interrupt #12 */
  ioss_interrupts_gpio_dpslp_13_IRQn =  11,     /*!<  11 [DeepSleep] GPIO Port Interrupt #13 */
  ioss_interrupt_gpio_dpslp_IRQn    =  12,      /*!<  12 [DeepSleep] GPIO All Ports */
  ioss_interrupt_vdd_IRQn           =  13,      /*!<  13 [DeepSleep] GPIO Supply Detect Interrupt */
  scb_0_interrupt_IRQn              =  14,      /*!<  14 [DeepSleep] Serial Communication Block #6 (DeepSleep capable) */
  srss_interrupt_mcwdt_0_IRQn       =  15,      /*!<  15 [DeepSleep] Multi Counter Watchdog Timer interrupt */
  srss_interrupt_mcwdt_1_IRQn       =  16,      /*!<  16 [DeepSleep] Multi Counter Watchdog Timer interrupt */
  usbhsdev_interrupt_u2d_dpslp_o_IRQn =  17,    /*!<  17 [DeepSleep] USBHS DEV interuupt */
  srss_interrupt_IRQn               =  18,      /*!<  18 [DeepSleep] Other combined Interrupts for SRSS (LVD, WDT, CLKCAL) */
  cpuss_interrupts_ipc_0_IRQn       =  19,      /*!<  19 [DeepSleep] CPUSS Inter Process Communication Interrupt #0 */
  cpuss_interrupts_ipc_1_IRQn       =  20,      /*!<  20 [DeepSleep] CPUSS Inter Process Communication Interrupt #1 */
  cpuss_interrupts_ipc_2_IRQn       =  21,      /*!<  21 [DeepSleep] CPUSS Inter Process Communication Interrupt #2 */
  cpuss_interrupts_ipc_3_IRQn       =  22,      /*!<  22 [DeepSleep] CPUSS Inter Process Communication Interrupt #3 */
  cpuss_interrupts_ipc_4_IRQn       =  23,      /*!<  23 [DeepSleep] CPUSS Inter Process Communication Interrupt #4 */
  cpuss_interrupts_ipc_5_IRQn       =  24,      /*!<  24 [DeepSleep] CPUSS Inter Process Communication Interrupt #5 */
  cpuss_interrupts_ipc_6_IRQn       =  25,      /*!<  25 [DeepSleep] CPUSS Inter Process Communication Interrupt #6 */
  cpuss_interrupts_ipc_7_IRQn       =  26,      /*!<  26 [DeepSleep] CPUSS Inter Process Communication Interrupt #7 */
  cpuss_interrupts_ipc_8_IRQn       =  27,      /*!<  27 [DeepSleep] CPUSS Inter Process Communication Interrupt #8 */
  cpuss_interrupts_ipc_9_IRQn       =  28,      /*!<  28 [DeepSleep] CPUSS Inter Process Communication Interrupt #9 */
  cpuss_interrupts_ipc_10_IRQn      =  29,      /*!<  29 [DeepSleep] CPUSS Inter Process Communication Interrupt #10 */
  cpuss_interrupts_ipc_11_IRQn      =  30,      /*!<  30 [DeepSleep] CPUSS Inter Process Communication Interrupt #11 */
  cpuss_interrupts_ipc_12_IRQn      =  31,      /*!<  31 [DeepSleep] CPUSS Inter Process Communication Interrupt #12 */
  cpuss_interrupts_ipc_13_IRQn      =  32,      /*!<  32 [DeepSleep] CPUSS Inter Process Communication Interrupt #13 */
  cpuss_interrupts_ipc_14_IRQn      =  33,      /*!<  33 [DeepSleep] CPUSS Inter Process Communication Interrupt #14 */
  cpuss_interrupts_ipc_15_IRQn      =  34,      /*!<  34 [DeepSleep] CPUSS Inter Process Communication Interrupt #15 */
  lvds2usb32ss_usb32_wakeup_int_o_IRQn =  35,   /*!<  35 [DeepSleep] usb32 deepslp interrupt */
  lvds2usb32ss_lvds_wakeup_int_o_IRQn =  36,    /*!<  36 [DeepSleep] lvds deepslp interrupt */
  scb_1_interrupt_IRQn              =  46,      /*!<  46 [Active] Serial Communication Block #1 */
  scb_2_interrupt_IRQn              =  47,      /*!<  47 [Active] Serial Communication Block #2 */
  scb_3_interrupt_IRQn              =  48,      /*!<  48 [Active] Serial Communication Block #3 */
  scb_4_interrupt_IRQn              =  49,      /*!<  49 [Active] Serial Communication Block #4 */
  scb_5_interrupt_IRQn              =  50,      /*!<  50 [Active] Serial Communication Block #5 */
  scb_6_interrupt_IRQn              =  51,      /*!<  51 [Active] Serial Communication Block #6 */
  cpuss_interrupts_dmac_0_IRQn      =  52,      /*!<  52 [Active] CPUSS DMAC, Channel #0 */
  cpuss_interrupts_dmac_1_IRQn      =  53,      /*!<  53 [Active] CPUSS DMAC, Channel #1 */
  cpuss_interrupts_dmac_2_IRQn      =  54,      /*!<  54 [Active] CPUSS DMAC, Channel #2 */
  cpuss_interrupts_dmac_3_IRQn      =  55,      /*!<  55 [Active] CPUSS DMAC, Channel #3 */
  cpuss_interrupts_dmac_4_IRQn      =  56,      /*!<  56 [Active] CPUSS DMAC, Channel #4 */
  cpuss_interrupts_dmac_5_IRQn      =  57,      /*!<  57 [Active] CPUSS DMAC, Channel #5 */
  cpuss_interrupts_dw0_0_IRQn       =  58,      /*!<  58 [Active] CPUSS DataWire #0, Channel #0 */
  cpuss_interrupts_dw0_1_IRQn       =  59,      /*!<  59 [Active] CPUSS DataWire #0, Channel #1 */
  cpuss_interrupts_dw0_2_IRQn       =  60,      /*!<  60 [Active] CPUSS DataWire #0, Channel #2 */
  cpuss_interrupts_dw0_3_IRQn       =  61,      /*!<  61 [Active] CPUSS DataWire #0, Channel #3 */
  cpuss_interrupts_dw0_4_IRQn       =  62,      /*!<  62 [Active] CPUSS DataWire #0, Channel #4 */
  cpuss_interrupts_dw0_5_IRQn       =  63,      /*!<  63 [Active] CPUSS DataWire #0, Channel #5 */
  cpuss_interrupts_dw0_6_IRQn       =  64,      /*!<  64 [Active] CPUSS DataWire #0, Channel #6 */
  cpuss_interrupts_dw0_7_IRQn       =  65,      /*!<  65 [Active] CPUSS DataWire #0, Channel #7 */
  cpuss_interrupts_dw0_8_IRQn       =  66,      /*!<  66 [Active] CPUSS DataWire #0, Channel #8 */
  cpuss_interrupts_dw0_9_IRQn       =  67,      /*!<  67 [Active] CPUSS DataWire #0, Channel #9 */
  cpuss_interrupts_dw0_10_IRQn      =  68,      /*!<  68 [Active] CPUSS DataWire #0, Channel #10 */
  cpuss_interrupts_dw0_11_IRQn      =  69,      /*!<  69 [Active] CPUSS DataWire #0, Channel #11 */
  cpuss_interrupts_dw0_12_IRQn      =  70,      /*!<  70 [Active] CPUSS DataWire #0, Channel #12 */
  cpuss_interrupts_dw0_13_IRQn      =  71,      /*!<  71 [Active] CPUSS DataWire #0, Channel #13 */
  cpuss_interrupts_dw0_14_IRQn      =  72,      /*!<  72 [Active] CPUSS DataWire #0, Channel #14 */
  cpuss_interrupts_dw0_15_IRQn      =  73,      /*!<  73 [Active] CPUSS DataWire #0, Channel #15 */
  cpuss_interrupts_dw0_16_IRQn      =  74,      /*!<  74 [Active] CPUSS DataWire #0, Channel #16 */
  cpuss_interrupts_dw0_17_IRQn      =  75,      /*!<  75 [Active] CPUSS DataWire #0, Channel #17 */
  cpuss_interrupts_dw0_18_IRQn      =  76,      /*!<  76 [Active] CPUSS DataWire #0, Channel #18 */
  cpuss_interrupts_dw0_19_IRQn      =  77,      /*!<  77 [Active] CPUSS DataWire #0, Channel #19 */
  cpuss_interrupts_dw0_20_IRQn      =  78,      /*!<  78 [Active] CPUSS DataWire #0, Channel #20 */
  cpuss_interrupts_dw0_21_IRQn      =  79,      /*!<  79 [Active] CPUSS DataWire #0, Channel #21 */
  cpuss_interrupts_dw0_22_IRQn      =  80,      /*!<  80 [Active] CPUSS DataWire #0, Channel #22 */
  cpuss_interrupts_dw0_23_IRQn      =  81,      /*!<  81 [Active] CPUSS DataWire #0, Channel #23 */
  cpuss_interrupts_dw1_0_IRQn       =  82,      /*!<  82 [Active] CPUSS DataWire #1, Channel #0 */
  cpuss_interrupts_dw1_1_IRQn       =  83,      /*!<  83 [Active] CPUSS DataWire #1, Channel #1 */
  cpuss_interrupts_dw1_2_IRQn       =  84,      /*!<  84 [Active] CPUSS DataWire #1, Channel #2 */
  cpuss_interrupts_dw1_3_IRQn       =  85,      /*!<  85 [Active] CPUSS DataWire #1, Channel #3 */
  cpuss_interrupts_dw1_4_IRQn       =  86,      /*!<  86 [Active] CPUSS DataWire #1, Channel #4 */
  cpuss_interrupts_dw1_5_IRQn       =  87,      /*!<  87 [Active] CPUSS DataWire #1, Channel #5 */
  cpuss_interrupts_dw1_6_IRQn       =  88,      /*!<  88 [Active] CPUSS DataWire #1, Channel #6 */
  cpuss_interrupts_dw1_7_IRQn       =  89,      /*!<  89 [Active] CPUSS DataWire #1, Channel #7 */
  cpuss_interrupts_dw1_8_IRQn       =  90,      /*!<  90 [Active] CPUSS DataWire #1, Channel #8 */
  cpuss_interrupts_dw1_9_IRQn       =  91,      /*!<  91 [Active] CPUSS DataWire #1, Channel #9 */
  cpuss_interrupts_dw1_10_IRQn      =  92,      /*!<  92 [Active] CPUSS DataWire #1, Channel #10 */
  cpuss_interrupts_dw1_11_IRQn      =  93,      /*!<  93 [Active] CPUSS DataWire #1, Channel #11 */
  cpuss_interrupts_dw1_12_IRQn      =  94,      /*!<  94 [Active] CPUSS DataWire #1, Channel #12 */
  cpuss_interrupts_dw1_13_IRQn      =  95,      /*!<  95 [Active] CPUSS DataWire #1, Channel #13 */
  cpuss_interrupts_dw1_14_IRQn      =  96,      /*!<  96 [Active] CPUSS DataWire #1, Channel #14 */
  cpuss_interrupts_dw1_15_IRQn      =  97,      /*!<  97 [Active] CPUSS DataWire #1, Channel #15 */
  cpuss_interrupts_dw1_16_IRQn      =  98,      /*!<  98 [Active] CPUSS DataWire #1, Channel #16 */
  cpuss_interrupts_dw1_17_IRQn      =  99,      /*!<  99 [Active] CPUSS DataWire #1, Channel #17 */
  cpuss_interrupts_dw1_18_IRQn      = 100,      /*!< 100 [Active] CPUSS DataWire #1, Channel #18 */
  cpuss_interrupts_dw1_19_IRQn      = 101,      /*!< 101 [Active] CPUSS DataWire #1, Channel #19 */
  cpuss_interrupts_dw1_20_IRQn      = 102,      /*!< 102 [Active] CPUSS DataWire #1, Channel #20 */
  cpuss_interrupts_dw1_21_IRQn      = 103,      /*!< 103 [Active] CPUSS DataWire #1, Channel #21 */
  cpuss_interrupts_dw1_22_IRQn      = 104,      /*!< 104 [Active] CPUSS DataWire #1, Channel #22 */
  cpuss_interrupts_dw1_23_IRQn      = 105,      /*!< 105 [Active] CPUSS DataWire #1, Channel #23 */
  cpuss_interrupts_fault_0_IRQn     = 106,      /*!< 106 [Active] CPUSS Fault Structure Interrupt #0 */
  cpuss_interrupts_fault_1_IRQn     = 107,      /*!< 107 [Active] CPUSS Fault Structure Interrupt #1 */
  cpuss_interrupt_crypto_IRQn       = 108,      /*!< 108 [Active] CRYPTO Accelerator Interrupt */
  cpuss_interrupt_fm_IRQn           = 109,      /*!< 109 [Active] FLASH Macro Interrupt */
  cpuss_interrupts_cm4_fp_IRQn      = 110,      /*!< 110 [Active] Floating Point operation fault */
  cpuss_interrupts_cm0_cti_0_IRQn   = 111,      /*!< 111 [Active] CM0+ CTI #0 */
  cpuss_interrupts_cm0_cti_1_IRQn   = 112,      /*!< 112 [Active] CM0+ CTI #1 */
  cpuss_interrupts_cm4_cti_0_IRQn   = 113,      /*!< 113 [Active] CM4 CTI #0 */
  cpuss_interrupts_cm4_cti_1_IRQn   = 114,      /*!< 114 [Active] CM4 CTI #1 */
  tcpwm_0_interrupts_0_IRQn         = 115,      /*!< 115 [Active] TCPWM #0, Counter #0 */
  tcpwm_0_interrupts_1_IRQn         = 116,      /*!< 116 [Active] TCPWM #0, Counter #1 */
  tcpwm_0_interrupts_2_IRQn         = 117,      /*!< 117 [Active] TCPWM #0, Counter #2 */
  tcpwm_0_interrupts_3_IRQn         = 118,      /*!< 118 [Active] TCPWM #0, Counter #3 */
  tcpwm_0_interrupts_4_IRQn         = 119,      /*!< 119 [Active] TCPWM #0, Counter #4 */
  tcpwm_0_interrupts_5_IRQn         = 120,      /*!< 120 [Active] TCPWM #0, Counter #5 */
  tcpwm_0_interrupts_6_IRQn         = 121,      /*!< 121 [Active] TCPWM #0, Counter #6 */
  tcpwm_0_interrupts_7_IRQn         = 122,      /*!< 122 [Active] TCPWM #0, Counter #7 */
  tdm_0_interrupts_rx_0_IRQn        = 123,      /*!< 123 [Active] TDM0 Audio interrupt RX */
  tdm_0_interrupts_tx_0_IRQn        = 124,      /*!< 124 [Active] TDM0 Audio interrupt TX */
  smif_interrupt_IRQn               = 125,      /*!< 125 [Active] Serial Memory Interface interrupt */
  usb_interrupt_hi_IRQn             = 126,      /*!< 126 [Active] USB Interrupt */
  usb_interrupt_med_IRQn            = 127,      /*!< 127 [Active] USB Interrupt */
  usb_interrupt_lo_IRQn             = 128,      /*!< 128 [Active] USB Interrupt */
  usbhsdev_interrupt_u2d_active_o_IRQn = 129,   /*!< 129 [Active] USB HS dev Interrupt */
  canfd_0_interrupt0_IRQn           = 130,      /*!< 130 [Active] Can #0, Consolidated interrupt #0 */
  canfd_0_interrupts0_0_IRQn        = 131,      /*!< 131 [Active] CAN #0, Interrupt #0, Channel #0 */
  canfd_0_interrupts1_0_IRQn        = 132,      /*!< 132 [Active] CAN #0, Interrupt #1, Channel #0 */
  pdm_0_interrupts_0_IRQn           = 133,      /*!< 133 [Active] PDM interrupt */
  pdm_0_interrupts_1_IRQn           = 134,      /*!< 134 [Active] PDM interrupt */
  lvds2usb32ss_lvds_int_o_IRQn      = 135,      /*!< 135 [Active]  */
  lvds2usb32ss_tra_int_o_IRQn       = 136,      /*!< 136 [Active]  */
  lvds2usb32ss_usb32_egrs_dma_int_o_IRQn = 137, /*!< 137 [Active]  */
  lvds2usb32ss_usb32_ingrs_dma_int_o_IRQn = 138, /*!< 138 [Active]  */
  lvds2usb32ss_usb32_int_o_IRQn     = 139,      /*!< 139 [Active]  */
  lvds2usb32ss_lvds_dma_adap0_int_o_IRQn = 140, /*!< 140 [Active]  */
  lvds2usb32ss_lvds_dma_adap1_int_o_IRQn = 141, /*!< 141 [Active]  */
  unconnected_IRQn                  =1023       /*!< 1023 Unconnected */
#endif
} IRQn_Type;


#if ((defined(__GNUC__)        && (__ARM_ARCH == 6) && (__ARM_ARCH_6M__ == 1)) || \
     (defined(__ICCARM__)      && (__CORE__ == __ARM6M__)) || \
     (defined(__ARMCC_VERSION) && defined(__TARGET_ARCH_THUMB) && (__TARGET_ARCH_THUMB == 3)) || \
     (defined(__ghs__)         && defined(__CORE_CORTEXM0PLUS__)))

/* CYUSB4012-FCAXI interrupts that can be routed to the CM0+ NVIC */
typedef enum {
  ioss_interrupts_gpio_dpslp_0_IRQn =   0,      /*!<   0 [DeepSleep] GPIO Port Interrupt #0 */
  ioss_interrupts_gpio_dpslp_1_IRQn =   1,      /*!<   1 [DeepSleep] GPIO Port Interrupt #1 */
  ioss_interrupts_gpio_dpslp_4_IRQn =   2,      /*!<   2 [DeepSleep] GPIO Port Interrupt #4 */
  ioss_interrupts_gpio_dpslp_5_IRQn =   3,      /*!<   3 [DeepSleep] GPIO Port Interrupt #5 */
  ioss_interrupts_gpio_dpslp_6_IRQn =   4,      /*!<   4 [DeepSleep] GPIO Port Interrupt #6 */
  ioss_interrupts_gpio_dpslp_7_IRQn =   5,      /*!<   5 [DeepSleep] GPIO Port Interrupt #7 */
  ioss_interrupts_gpio_dpslp_8_IRQn =   6,      /*!<   6 [DeepSleep] GPIO Port Interrupt #8 */
  ioss_interrupts_gpio_dpslp_9_IRQn =   7,      /*!<   7 [DeepSleep] GPIO Port Interrupt #9 */
  ioss_interrupts_gpio_dpslp_10_IRQn =   8,     /*!<   8 [DeepSleep] GPIO Port Interrupt #10 */
  ioss_interrupts_gpio_dpslp_11_IRQn =   9,     /*!<   9 [DeepSleep] GPIO Port Interrupt #11 */
  ioss_interrupts_gpio_dpslp_12_IRQn =  10,     /*!<  10 [DeepSleep] GPIO Port Interrupt #12 */
  ioss_interrupts_gpio_dpslp_13_IRQn =  11,     /*!<  11 [DeepSleep] GPIO Port Interrupt #13 */
  ioss_interrupt_gpio_dpslp_IRQn    =  12,      /*!<  12 [DeepSleep] GPIO All Ports */
  ioss_interrupt_vdd_IRQn           =  13,      /*!<  13 [DeepSleep] GPIO Supply Detect Interrupt */
  scb_0_interrupt_IRQn              =  14,      /*!<  14 [DeepSleep] Serial Communication Block #6 (DeepSleep capable) */
  srss_interrupt_mcwdt_0_IRQn       =  15,      /*!<  15 [DeepSleep] Multi Counter Watchdog Timer interrupt */
  srss_interrupt_mcwdt_1_IRQn       =  16,      /*!<  16 [DeepSleep] Multi Counter Watchdog Timer interrupt */
  usbhsdev_interrupt_u2d_dpslp_o_IRQn =  17,    /*!<  17 [DeepSleep] USBHS DEV interuupt */
  srss_interrupt_IRQn               =  18,      /*!<  18 [DeepSleep] Other combined Interrupts for SRSS (LVD, WDT, CLKCAL) */
  cpuss_interrupts_ipc_0_IRQn       =  19,      /*!<  19 [DeepSleep] CPUSS Inter Process Communication Interrupt #0 */
  cpuss_interrupts_ipc_1_IRQn       =  20,      /*!<  20 [DeepSleep] CPUSS Inter Process Communication Interrupt #1 */
  cpuss_interrupts_ipc_2_IRQn       =  21,      /*!<  21 [DeepSleep] CPUSS Inter Process Communication Interrupt #2 */
  cpuss_interrupts_ipc_3_IRQn       =  22,      /*!<  22 [DeepSleep] CPUSS Inter Process Communication Interrupt #3 */
  cpuss_interrupts_ipc_4_IRQn       =  23,      /*!<  23 [DeepSleep] CPUSS Inter Process Communication Interrupt #4 */
  cpuss_interrupts_ipc_5_IRQn       =  24,      /*!<  24 [DeepSleep] CPUSS Inter Process Communication Interrupt #5 */
  cpuss_interrupts_ipc_6_IRQn       =  25,      /*!<  25 [DeepSleep] CPUSS Inter Process Communication Interrupt #6 */
  cpuss_interrupts_ipc_7_IRQn       =  26,      /*!<  26 [DeepSleep] CPUSS Inter Process Communication Interrupt #7 */
  cpuss_interrupts_ipc_8_IRQn       =  27,      /*!<  27 [DeepSleep] CPUSS Inter Process Communication Interrupt #8 */
  cpuss_interrupts_ipc_9_IRQn       =  28,      /*!<  28 [DeepSleep] CPUSS Inter Process Communication Interrupt #9 */
  cpuss_interrupts_ipc_10_IRQn      =  29,      /*!<  29 [DeepSleep] CPUSS Inter Process Communication Interrupt #10 */
  cpuss_interrupts_ipc_11_IRQn      =  30,      /*!<  30 [DeepSleep] CPUSS Inter Process Communication Interrupt #11 */
  cpuss_interrupts_ipc_12_IRQn      =  31,      /*!<  31 [DeepSleep] CPUSS Inter Process Communication Interrupt #12 */
  cpuss_interrupts_ipc_13_IRQn      =  32,      /*!<  32 [DeepSleep] CPUSS Inter Process Communication Interrupt #13 */
  cpuss_interrupts_ipc_14_IRQn      =  33,      /*!<  33 [DeepSleep] CPUSS Inter Process Communication Interrupt #14 */
  cpuss_interrupts_ipc_15_IRQn      =  34,      /*!<  34 [DeepSleep] CPUSS Inter Process Communication Interrupt #15 */
  lvds2usb32ss_usb32_wakeup_int_o_IRQn =  35,   /*!<  35 [DeepSleep] usb32 deepslp interrupt */
  lvds2usb32ss_lvds_wakeup_int_o_IRQn =  36,    /*!<  36 [DeepSleep] lvds deepslp interrupt */
  scb_1_interrupt_IRQn              =  46,      /*!<  46 [Active] Serial Communication Block #1 */
  scb_2_interrupt_IRQn              =  47,      /*!<  47 [Active] Serial Communication Block #2 */
  scb_3_interrupt_IRQn              =  48,      /*!<  48 [Active] Serial Communication Block #3 */
  scb_4_interrupt_IRQn              =  49,      /*!<  49 [Active] Serial Communication Block #4 */
  scb_5_interrupt_IRQn              =  50,      /*!<  50 [Active] Serial Communication Block #5 */
  scb_6_interrupt_IRQn              =  51,      /*!<  51 [Active] Serial Communication Block #6 */
  cpuss_interrupts_dmac_0_IRQn      =  52,      /*!<  52 [Active] CPUSS DMAC, Channel #0 */
  cpuss_interrupts_dmac_1_IRQn      =  53,      /*!<  53 [Active] CPUSS DMAC, Channel #1 */
  cpuss_interrupts_dmac_2_IRQn      =  54,      /*!<  54 [Active] CPUSS DMAC, Channel #2 */
  cpuss_interrupts_dmac_3_IRQn      =  55,      /*!<  55 [Active] CPUSS DMAC, Channel #3 */
  cpuss_interrupts_dmac_4_IRQn      =  56,      /*!<  56 [Active] CPUSS DMAC, Channel #4 */
  cpuss_interrupts_dmac_5_IRQn      =  57,      /*!<  57 [Active] CPUSS DMAC, Channel #5 */
  cpuss_interrupts_dw0_0_IRQn       =  58,      /*!<  58 [Active] CPUSS DataWire #0, Channel #0 */
  cpuss_interrupts_dw0_1_IRQn       =  59,      /*!<  59 [Active] CPUSS DataWire #0, Channel #1 */
  cpuss_interrupts_dw0_2_IRQn       =  60,      /*!<  60 [Active] CPUSS DataWire #0, Channel #2 */
  cpuss_interrupts_dw0_3_IRQn       =  61,      /*!<  61 [Active] CPUSS DataWire #0, Channel #3 */
  cpuss_interrupts_dw0_4_IRQn       =  62,      /*!<  62 [Active] CPUSS DataWire #0, Channel #4 */
  cpuss_interrupts_dw0_5_IRQn       =  63,      /*!<  63 [Active] CPUSS DataWire #0, Channel #5 */
  cpuss_interrupts_dw0_6_IRQn       =  64,      /*!<  64 [Active] CPUSS DataWire #0, Channel #6 */
  cpuss_interrupts_dw0_7_IRQn       =  65,      /*!<  65 [Active] CPUSS DataWire #0, Channel #7 */
  cpuss_interrupts_dw0_8_IRQn       =  66,      /*!<  66 [Active] CPUSS DataWire #0, Channel #8 */
  cpuss_interrupts_dw0_9_IRQn       =  67,      /*!<  67 [Active] CPUSS DataWire #0, Channel #9 */
  cpuss_interrupts_dw0_10_IRQn      =  68,      /*!<  68 [Active] CPUSS DataWire #0, Channel #10 */
  cpuss_interrupts_dw0_11_IRQn      =  69,      /*!<  69 [Active] CPUSS DataWire #0, Channel #11 */
  cpuss_interrupts_dw0_12_IRQn      =  70,      /*!<  70 [Active] CPUSS DataWire #0, Channel #12 */
  cpuss_interrupts_dw0_13_IRQn      =  71,      /*!<  71 [Active] CPUSS DataWire #0, Channel #13 */
  cpuss_interrupts_dw0_14_IRQn      =  72,      /*!<  72 [Active] CPUSS DataWire #0, Channel #14 */
  cpuss_interrupts_dw0_15_IRQn      =  73,      /*!<  73 [Active] CPUSS DataWire #0, Channel #15 */
  cpuss_interrupts_dw0_16_IRQn      =  74,      /*!<  74 [Active] CPUSS DataWire #0, Channel #16 */
  cpuss_interrupts_dw0_17_IRQn      =  75,      /*!<  75 [Active] CPUSS DataWire #0, Channel #17 */
  cpuss_interrupts_dw0_18_IRQn      =  76,      /*!<  76 [Active] CPUSS DataWire #0, Channel #18 */
  cpuss_interrupts_dw0_19_IRQn      =  77,      /*!<  77 [Active] CPUSS DataWire #0, Channel #19 */
  cpuss_interrupts_dw0_20_IRQn      =  78,      /*!<  78 [Active] CPUSS DataWire #0, Channel #20 */
  cpuss_interrupts_dw0_21_IRQn      =  79,      /*!<  79 [Active] CPUSS DataWire #0, Channel #21 */
  cpuss_interrupts_dw0_22_IRQn      =  80,      /*!<  80 [Active] CPUSS DataWire #0, Channel #22 */
  cpuss_interrupts_dw0_23_IRQn      =  81,      /*!<  81 [Active] CPUSS DataWire #0, Channel #23 */
  cpuss_interrupts_dw1_0_IRQn       =  82,      /*!<  82 [Active] CPUSS DataWire #1, Channel #0 */
  cpuss_interrupts_dw1_1_IRQn       =  83,      /*!<  83 [Active] CPUSS DataWire #1, Channel #1 */
  cpuss_interrupts_dw1_2_IRQn       =  84,      /*!<  84 [Active] CPUSS DataWire #1, Channel #2 */
  cpuss_interrupts_dw1_3_IRQn       =  85,      /*!<  85 [Active] CPUSS DataWire #1, Channel #3 */
  cpuss_interrupts_dw1_4_IRQn       =  86,      /*!<  86 [Active] CPUSS DataWire #1, Channel #4 */
  cpuss_interrupts_dw1_5_IRQn       =  87,      /*!<  87 [Active] CPUSS DataWire #1, Channel #5 */
  cpuss_interrupts_dw1_6_IRQn       =  88,      /*!<  88 [Active] CPUSS DataWire #1, Channel #6 */
  cpuss_interrupts_dw1_7_IRQn       =  89,      /*!<  89 [Active] CPUSS DataWire #1, Channel #7 */
  cpuss_interrupts_dw1_8_IRQn       =  90,      /*!<  90 [Active] CPUSS DataWire #1, Channel #8 */
  cpuss_interrupts_dw1_9_IRQn       =  91,      /*!<  91 [Active] CPUSS DataWire #1, Channel #9 */
  cpuss_interrupts_dw1_10_IRQn      =  92,      /*!<  92 [Active] CPUSS DataWire #1, Channel #10 */
  cpuss_interrupts_dw1_11_IRQn      =  93,      /*!<  93 [Active] CPUSS DataWire #1, Channel #11 */
  cpuss_interrupts_dw1_12_IRQn      =  94,      /*!<  94 [Active] CPUSS DataWire #1, Channel #12 */
  cpuss_interrupts_dw1_13_IRQn      =  95,      /*!<  95 [Active] CPUSS DataWire #1, Channel #13 */
  cpuss_interrupts_dw1_14_IRQn      =  96,      /*!<  96 [Active] CPUSS DataWire #1, Channel #14 */
  cpuss_interrupts_dw1_15_IRQn      =  97,      /*!<  97 [Active] CPUSS DataWire #1, Channel #15 */
  cpuss_interrupts_dw1_16_IRQn      =  98,      /*!<  98 [Active] CPUSS DataWire #1, Channel #16 */
  cpuss_interrupts_dw1_17_IRQn      =  99,      /*!<  99 [Active] CPUSS DataWire #1, Channel #17 */
  cpuss_interrupts_dw1_18_IRQn      = 100,      /*!< 100 [Active] CPUSS DataWire #1, Channel #18 */
  cpuss_interrupts_dw1_19_IRQn      = 101,      /*!< 101 [Active] CPUSS DataWire #1, Channel #19 */
  cpuss_interrupts_dw1_20_IRQn      = 102,      /*!< 102 [Active] CPUSS DataWire #1, Channel #20 */
  cpuss_interrupts_dw1_21_IRQn      = 103,      /*!< 103 [Active] CPUSS DataWire #1, Channel #21 */
  cpuss_interrupts_dw1_22_IRQn      = 104,      /*!< 104 [Active] CPUSS DataWire #1, Channel #22 */
  cpuss_interrupts_dw1_23_IRQn      = 105,      /*!< 105 [Active] CPUSS DataWire #1, Channel #23 */
  cpuss_interrupts_fault_0_IRQn     = 106,      /*!< 106 [Active] CPUSS Fault Structure Interrupt #0 */
  cpuss_interrupts_fault_1_IRQn     = 107,      /*!< 107 [Active] CPUSS Fault Structure Interrupt #1 */
  cpuss_interrupt_crypto_IRQn       = 108,      /*!< 108 [Active] CRYPTO Accelerator Interrupt */
  cpuss_interrupt_fm_IRQn           = 109,      /*!< 109 [Active] FLASH Macro Interrupt */
  cpuss_interrupts_cm4_fp_IRQn      = 110,      /*!< 110 [Active] Floating Point operation fault */
  cpuss_interrupts_cm0_cti_0_IRQn   = 111,      /*!< 111 [Active] CM0+ CTI #0 */
  cpuss_interrupts_cm0_cti_1_IRQn   = 112,      /*!< 112 [Active] CM0+ CTI #1 */
  cpuss_interrupts_cm4_cti_0_IRQn   = 113,      /*!< 113 [Active] CM4 CTI #0 */
  cpuss_interrupts_cm4_cti_1_IRQn   = 114,      /*!< 114 [Active] CM4 CTI #1 */
  tcpwm_0_interrupts_0_IRQn         = 115,      /*!< 115 [Active] TCPWM #0, Counter #0 */
  tcpwm_0_interrupts_1_IRQn         = 116,      /*!< 116 [Active] TCPWM #0, Counter #1 */
  tcpwm_0_interrupts_2_IRQn         = 117,      /*!< 117 [Active] TCPWM #0, Counter #2 */
  tcpwm_0_interrupts_3_IRQn         = 118,      /*!< 118 [Active] TCPWM #0, Counter #3 */
  tcpwm_0_interrupts_4_IRQn         = 119,      /*!< 119 [Active] TCPWM #0, Counter #4 */
  tcpwm_0_interrupts_5_IRQn         = 120,      /*!< 120 [Active] TCPWM #0, Counter #5 */
  tcpwm_0_interrupts_6_IRQn         = 121,      /*!< 121 [Active] TCPWM #0, Counter #6 */
  tcpwm_0_interrupts_7_IRQn         = 122,      /*!< 122 [Active] TCPWM #0, Counter #7 */
  tdm_0_interrupts_rx_0_IRQn        = 123,      /*!< 123 [Active] TDM0 Audio interrupt RX */
  tdm_0_interrupts_tx_0_IRQn        = 124,      /*!< 124 [Active] TDM0 Audio interrupt TX */
  smif_interrupt_IRQn               = 125,      /*!< 125 [Active] Serial Memory Interface interrupt */
  usb_interrupt_hi_IRQn             = 126,      /*!< 126 [Active] USB Interrupt */
  usb_interrupt_med_IRQn            = 127,      /*!< 127 [Active] USB Interrupt */
  usb_interrupt_lo_IRQn             = 128,      /*!< 128 [Active] USB Interrupt */
  usbhsdev_interrupt_u2d_active_o_IRQn = 129,   /*!< 129 [Active] USB HS dev Interrupt */
  canfd_0_interrupt0_IRQn           = 130,      /*!< 130 [Active] Can #0, Consolidated interrupt #0 */
  canfd_0_interrupts0_0_IRQn        = 131,      /*!< 131 [Active] CAN #0, Interrupt #0, Channel #0 */
  canfd_0_interrupts1_0_IRQn        = 132,      /*!< 132 [Active] CAN #0, Interrupt #1, Channel #0 */
  pdm_0_interrupts_0_IRQn           = 133,      /*!< 133 [Active] PDM interrupt */
  pdm_0_interrupts_1_IRQn           = 134,      /*!< 134 [Active] PDM interrupt */
  lvds2usb32ss_lvds_int_o_IRQn      = 135,      /*!< 135 [Active]  */
  lvds2usb32ss_tra_int_o_IRQn       = 136,      /*!< 136 [Active]  */
  lvds2usb32ss_usb32_egrs_dma_int_o_IRQn = 137, /*!< 137 [Active]  */
  lvds2usb32ss_usb32_ingrs_dma_int_o_IRQn = 138, /*!< 138 [Active]  */
  lvds2usb32ss_usb32_int_o_IRQn     = 139,      /*!< 139 [Active]  */
  lvds2usb32ss_lvds_dma_adap0_int_o_IRQn = 140, /*!< 140 [Active]  */
  lvds2usb32ss_lvds_dma_adap1_int_o_IRQn = 141, /*!< 141 [Active]  */
  disconnected_IRQn                 =1023       /*!< 1023 Disconnected */
} cy_en_intr_t;

#endif

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
#define CY_ROM_SIZE                     0x00020000UL
#define CY_SRAM_BASE                    0x08000000UL
#define CY_SRAM_SIZE                    0x00020000UL
#define CY_FLASH_BASE                   0x10000000UL
#define CY_FLASH_SIZE                   0x00040000UL
#define CY_EM_EEPROM_BASE               0x14000000UL
#define CY_EM_EEPROM_SIZE               0x00008000UL
#define CY_SFLASH_BASE                  0x16000000UL
#define CY_SFLASH_SIZE                  0x00008000UL
#define CY_XIP_BASE                     0x18000000UL
#define CY_XIP_SIZE                     0x04000000UL
#define CY_LVDS2USB32SS_BASE            0x1C000000UL
#define CY_LVDS2USB32SS_SIZE            0x00100000UL
#define CY_USBHSDEV_SL_BASE             0x30000000UL
#define CY_USBHSDEV_SL_SIZE             0x01000000UL
#define CY_EFUSE_BASE                   0x402C0800UL
#define CY_EFUSE_SIZE                   0x00000200UL
#define CY_CAN0MRAM_BASE                0x40590000UL
#define CY_CAN0MRAM_SIZE                0x00010000UL


/* IP List */
#define CY_IP_MXTTCANFD                 1u
#define CY_IP_MXTTCANFD_INSTANCES       1u
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
#define CY_IP_MXEFUSE                   1u
#define CY_IP_MXEFUSE_INSTANCES         1u
#define CY_IP_MXEFUSE_VERSION           1u
#define CY_IP_MXEFUSE_VERSION_MINOR     0u
#define CY_IP_MXS40IOSS                 1u
#define CY_IP_MXS40IOSS_INSTANCES       1u
#define CY_IP_MXS40IOSS_VERSION         5u
#define CY_IP_MXS40IOSS_VERSION_MINOR   0u
#define CY_IP_MXS40LVDS2USB32SS         1u
#define CY_IP_MXS40LVDS2USB32SS_INSTANCES 1u
#define CY_IP_MXS40LVDS2USB32SS_VERSION 1u
#define CY_IP_MXS40LVDS2USB32SS_VERSION_MINOR 0u
#define CY_IP_MXPDM                     1u
#define CY_IP_MXPDM_INSTANCES           1u
#define CY_IP_MXPDM_VERSION             1u
#define CY_IP_MXPDM_VERSION_MINOR       0u
#define CY_IP_MXPERI                    1u
#define CY_IP_MXPERI_INSTANCES          1u
#define CY_IP_MXPERI_VERSION            2u
#define CY_IP_MXPERI_VERSION_MINOR      0u
#define CY_IP_MXPERI_TR                 1u
#define CY_IP_MXPERI_TR_INSTANCES       1u
#define CY_IP_MXPERI_TR_VERSION         2u
#define CY_IP_MXPERI_TR_VERSION_MINOR   0u
#define CY_IP_MXSCB                     1u
#define CY_IP_MXSCB_INSTANCES           7u
#define CY_IP_MXSCB_VERSION             1u
#define CY_IP_MXSCB_VERSION_MINOR       0u
#define CY_IP_MXS40SRSS                 1u
#define CY_IP_MXS40SRSS_INSTANCES       1u
#define CY_IP_MXS40SRSS_VERSION         1u
#define CY_IP_MXS40SRSS_VERSION_MINOR   3u
#define CY_IP_MXS40SRSS_MCWDT           1u
#define CY_IP_MXS40SRSS_MCWDT_INSTANCES 2u
#define CY_IP_MXS40SRSS_MCWDT_VERSION   1u
#define CY_IP_MXS40SRSS_MCWDT_VERSION_MINOR 3u
#define CY_IP_MXTCPWM                   1u
#define CY_IP_MXTCPWM_INSTANCES         1u
#define CY_IP_MXTCPWM_VERSION           1u
#define CY_IP_MXTCPWM_VERSION_MINOR     0u
#define CY_IP_MXTDM                     1u
#define CY_IP_MXTDM_INSTANCES           1u
#define CY_IP_MXTDM_VERSION             2u
#define CY_IP_MXTDM_VERSION_MINOR       0u
#define CY_IP_MXUSBFS                   1u
#define CY_IP_MXUSBFS_INSTANCES         1u
#define CY_IP_MXUSBFS_VERSION           1u
#define CY_IP_MXUSBFS_VERSION_MINOR     0u
#define CY_IP_MXS40USBHSDEV             1u
#define CY_IP_MXS40USBHSDEV_INSTANCES   1u
#define CY_IP_MXS40USBHSDEV_VERSION     1u
#define CY_IP_MXS40USBHSDEV_VERSION_MINOR 0u

#define CY_DEVICE_FX3G2
#define CY_DEVICE_SERIES_FX3G2
#define CY_SILICON_ID                   0xED61111CUL
#define CY_HF_CLK_MAX_FREQ              150000000UL

#define CPUSS_FLASHC_PA_SIZE_LOG2       0x7UL

#include "system_psoc6.h"                       /*!< PSoC6 System */

#include "fx3g2_config.h"
#include "gpio_fx3g2_169_bga.h"

/*******************************************************************************
*                                    SFLASH
*******************************************************************************/

#define SFLASH_BASE                             0x16000000UL
#define SFLASH                                  ((SFLASH_Type*) SFLASH_BASE)                                      /* 0x16000000 */

/*******************************************************************************
*                                     PERI
*******************************************************************************/

#define PERI_BASE                               0x40000000UL
#define PERI                                    ((PERI_Type*) PERI_BASE)                                          /* 0x40000000 */
#define PERI_GR0                                ((PERI_GR_Type*) &PERI->GR[0])                                    /* 0x40004000 */
#define PERI_GR1                                ((PERI_GR_Type*) &PERI->GR[1])                                    /* 0x40004020 */
#define PERI_GR2                                ((PERI_GR_Type*) &PERI->GR[2])                                    /* 0x40004040 */
#define PERI_GR3                                ((PERI_GR_Type*) &PERI->GR[3])                                    /* 0x40004060 */
#define PERI_GR4                                ((PERI_GR_Type*) &PERI->GR[4])                                    /* 0x40004080 */
#define PERI_GR5                                ((PERI_GR_Type*) &PERI->GR[5])                                    /* 0x400040A0 */
#define PERI_GR6                                ((PERI_GR_Type*) &PERI->GR[6])                                    /* 0x400040C0 */
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
#define PERI_TR_1TO1_GR0                        ((PERI_TR_1TO1_GR_Type*) &PERI->TR_1TO1_GR[0])                    /* 0x4000C000 */
#define PERI_TR_1TO1_GR1                        ((PERI_TR_1TO1_GR_Type*) &PERI->TR_1TO1_GR[1])                    /* 0x4000C400 */
#define PERI_TR_1TO1_GR2                        ((PERI_TR_1TO1_GR_Type*) &PERI->TR_1TO1_GR[2])                    /* 0x4000C800 */
#define PERI_TR_1TO1_GR3                        ((PERI_TR_1TO1_GR_Type*) &PERI->TR_1TO1_GR[3])                    /* 0x4000CC00 */
#define PERI_TR_1TO1_GR4                        ((PERI_TR_1TO1_GR_Type*) &PERI->TR_1TO1_GR[4])                    /* 0x4000D000 */
#define PERI_TR_1TO1_GR5                        ((PERI_TR_1TO1_GR_Type*) &PERI->TR_1TO1_GR[5])                    /* 0x4000D400 */

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
#define PERI_MS_PPU_FX_PERI_MAIN                ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[0])                      /* 0x40010800 */
#define PERI_MS_PPU_FX_PERI_GR0_GROUP           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[1])                      /* 0x40010840 */
#define PERI_MS_PPU_FX_PERI_GR1_GROUP           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[2])                      /* 0x40010880 */
#define PERI_MS_PPU_FX_PERI_GR2_GROUP           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[3])                      /* 0x400108C0 */
#define PERI_MS_PPU_FX_PERI_GR3_GROUP           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[4])                      /* 0x40010900 */
#define PERI_MS_PPU_FX_PERI_GR4_GROUP           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[5])                      /* 0x40010940 */
#define PERI_MS_PPU_FX_PERI_GR5_GROUP           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[6])                      /* 0x40010980 */
#define PERI_MS_PPU_FX_PERI_GR6_GROUP           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[7])                      /* 0x400109C0 */
#define PERI_MS_PPU_FX_PERI_TR                  ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[8])                      /* 0x40010A00 */
#define PERI_MS_PPU_FX_CRYPTO_MAIN              ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[9])                      /* 0x40010A40 */
#define PERI_MS_PPU_FX_CRYPTO_CRYPTO            ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[10])                     /* 0x40010A80 */
#define PERI_MS_PPU_FX_CRYPTO_BOOT              ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[11])                     /* 0x40010AC0 */
#define PERI_MS_PPU_FX_CRYPTO_KEY0              ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[12])                     /* 0x40010B00 */
#define PERI_MS_PPU_FX_CRYPTO_KEY1              ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[13])                     /* 0x40010B40 */
#define PERI_MS_PPU_FX_CRYPTO_BUF               ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[14])                     /* 0x40010B80 */
#define PERI_MS_PPU_FX_CPUSS_CM4                ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[15])                     /* 0x40010BC0 */
#define PERI_MS_PPU_FX_CPUSS_CM0                ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[16])                     /* 0x40010C00 */
#define PERI_MS_PPU_FX_CPUSS_BOOT               ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[17])                     /* 0x40010C40 */
#define PERI_MS_PPU_FX_CPUSS_CM0_INT            ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[18])                     /* 0x40010C80 */
#define PERI_MS_PPU_FX_CPUSS_CM4_INT            ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[19])                     /* 0x40010CC0 */
#define PERI_MS_PPU_FX_IPC_STRUCT0_IPC          ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[20])                     /* 0x40010D00 */
#define PERI_MS_PPU_FX_IPC_STRUCT1_IPC          ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[21])                     /* 0x40010D40 */
#define PERI_MS_PPU_FX_IPC_STRUCT2_IPC          ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[22])                     /* 0x40010D80 */
#define PERI_MS_PPU_FX_IPC_STRUCT3_IPC          ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[23])                     /* 0x40010DC0 */
#define PERI_MS_PPU_FX_IPC_STRUCT4_IPC          ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[24])                     /* 0x40010E00 */
#define PERI_MS_PPU_FX_IPC_STRUCT5_IPC          ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[25])                     /* 0x40010E40 */
#define PERI_MS_PPU_FX_IPC_STRUCT6_IPC          ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[26])                     /* 0x40010E80 */
#define PERI_MS_PPU_FX_IPC_STRUCT7_IPC          ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[27])                     /* 0x40010EC0 */
#define PERI_MS_PPU_FX_IPC_STRUCT8_IPC          ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[28])                     /* 0x40010F00 */
#define PERI_MS_PPU_FX_IPC_STRUCT9_IPC          ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[29])                     /* 0x40010F40 */
#define PERI_MS_PPU_FX_IPC_STRUCT10_IPC         ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[30])                     /* 0x40010F80 */
#define PERI_MS_PPU_FX_IPC_STRUCT11_IPC         ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[31])                     /* 0x40010FC0 */
#define PERI_MS_PPU_FX_IPC_STRUCT12_IPC         ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[32])                     /* 0x40011000 */
#define PERI_MS_PPU_FX_IPC_STRUCT13_IPC         ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[33])                     /* 0x40011040 */
#define PERI_MS_PPU_FX_IPC_STRUCT14_IPC         ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[34])                     /* 0x40011080 */
#define PERI_MS_PPU_FX_IPC_STRUCT15_IPC         ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[35])                     /* 0x400110C0 */
#define PERI_MS_PPU_FX_IPC_INTR_STRUCT0_INTR    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[36])                     /* 0x40011100 */
#define PERI_MS_PPU_FX_IPC_INTR_STRUCT1_INTR    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[37])                     /* 0x40011140 */
#define PERI_MS_PPU_FX_IPC_INTR_STRUCT2_INTR    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[38])                     /* 0x40011180 */
#define PERI_MS_PPU_FX_IPC_INTR_STRUCT3_INTR    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[39])                     /* 0x400111C0 */
#define PERI_MS_PPU_FX_IPC_INTR_STRUCT4_INTR    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[40])                     /* 0x40011200 */
#define PERI_MS_PPU_FX_IPC_INTR_STRUCT5_INTR    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[41])                     /* 0x40011240 */
#define PERI_MS_PPU_FX_IPC_INTR_STRUCT6_INTR    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[42])                     /* 0x40011280 */
#define PERI_MS_PPU_FX_IPC_INTR_STRUCT7_INTR    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[43])                     /* 0x400112C0 */
#define PERI_MS_PPU_FX_IPC_INTR_STRUCT8_INTR    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[44])                     /* 0x40011300 */
#define PERI_MS_PPU_FX_IPC_INTR_STRUCT9_INTR    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[45])                     /* 0x40011340 */
#define PERI_MS_PPU_FX_IPC_INTR_STRUCT10_INTR   ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[46])                     /* 0x40011380 */
#define PERI_MS_PPU_FX_IPC_INTR_STRUCT11_INTR   ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[47])                     /* 0x400113C0 */
#define PERI_MS_PPU_FX_IPC_INTR_STRUCT12_INTR   ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[48])                     /* 0x40011400 */
#define PERI_MS_PPU_FX_IPC_INTR_STRUCT13_INTR   ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[49])                     /* 0x40011440 */
#define PERI_MS_PPU_FX_IPC_INTR_STRUCT14_INTR   ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[50])                     /* 0x40011480 */
#define PERI_MS_PPU_FX_IPC_INTR_STRUCT15_INTR   ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[51])                     /* 0x400114C0 */
#define PERI_MS_PPU_FX_PROT_SMPU_MAIN           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[52])                     /* 0x40011500 */
#define PERI_MS_PPU_FX_PROT_MPU0_MAIN           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[53])                     /* 0x40011540 */
#define PERI_MS_PPU_FX_PROT_MPU14_MAIN          ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[54])                     /* 0x40011580 */
#define PERI_MS_PPU_FX_PROT_MPU15_MAIN          ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[55])                     /* 0x400115C0 */
#define PERI_MS_PPU_FX_FLASHC_MAIN              ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[56])                     /* 0x40011600 */
#define PERI_MS_PPU_FX_FLASHC_CMD               ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[57])                     /* 0x40011640 */
#define PERI_MS_PPU_FX_FLASHC_DFT               ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[58])                     /* 0x40011680 */
#define PERI_MS_PPU_FX_FLASHC_CM0               ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[59])                     /* 0x400116C0 */
#define PERI_MS_PPU_FX_FLASHC_CM4               ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[60])                     /* 0x40011700 */
#define PERI_MS_PPU_FX_FLASHC_CRYPTO            ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[61])                     /* 0x40011740 */
#define PERI_MS_PPU_FX_FLASHC_DW0               ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[62])                     /* 0x40011780 */
#define PERI_MS_PPU_FX_FLASHC_DW1               ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[63])                     /* 0x400117C0 */
#define PERI_MS_PPU_FX_FLASHC_DMAC              ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[64])                     /* 0x40011800 */
#define PERI_MS_PPU_FX_FLASHC_FM                ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[65])                     /* 0x40011840 */
#define PERI_MS_PPU_FX_SRSS_MAIN1               ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[66])                     /* 0x40011880 */
#define PERI_MS_PPU_FX_SRSS_MAIN2               ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[67])                     /* 0x400118C0 */
#define PERI_MS_PPU_FX_WDT                      ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[68])                     /* 0x40011900 */
#define PERI_MS_PPU_FX_MAIN                     ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[69])                     /* 0x40011940 */
#define PERI_MS_PPU_FX_SRSS_MAIN3               ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[70])                     /* 0x40011980 */
#define PERI_MS_PPU_FX_SRSS_MAIN4               ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[71])                     /* 0x400119C0 */
#define PERI_MS_PPU_FX_SRSS_MAIN5               ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[72])                     /* 0x40011A00 */
#define PERI_MS_PPU_FX_SRSS_MAIN6               ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[73])                     /* 0x40011A40 */
#define PERI_MS_PPU_FX_SRSS_MAIN7               ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[74])                     /* 0x40011A80 */
#define PERI_MS_PPU_FX_DW0_DW                   ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[75])                     /* 0x40011AC0 */
#define PERI_MS_PPU_FX_DW1_DW                   ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[76])                     /* 0x40011B00 */
#define PERI_MS_PPU_FX_DW0_DW_CRC               ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[77])                     /* 0x40011B40 */
#define PERI_MS_PPU_FX_DW1_DW_CRC               ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[78])                     /* 0x40011B80 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT0_CH        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[79])                     /* 0x40011BC0 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT1_CH        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[80])                     /* 0x40011C00 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT2_CH        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[81])                     /* 0x40011C40 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT3_CH        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[82])                     /* 0x40011C80 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT4_CH        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[83])                     /* 0x40011CC0 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT5_CH        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[84])                     /* 0x40011D00 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT6_CH        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[85])                     /* 0x40011D40 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT7_CH        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[86])                     /* 0x40011D80 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT8_CH        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[87])                     /* 0x40011DC0 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT9_CH        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[88])                     /* 0x40011E00 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT10_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[89])                     /* 0x40011E40 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT11_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[90])                     /* 0x40011E80 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT12_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[91])                     /* 0x40011EC0 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT13_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[92])                     /* 0x40011F00 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT14_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[93])                     /* 0x40011F40 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT15_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[94])                     /* 0x40011F80 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT16_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[95])                     /* 0x40011FC0 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT17_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[96])                     /* 0x40012000 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT18_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[97])                     /* 0x40012040 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT19_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[98])                     /* 0x40012080 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT20_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[99])                     /* 0x400120C0 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT21_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[100])                    /* 0x40012100 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT22_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[101])                    /* 0x40012140 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT23_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[102])                    /* 0x40012180 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT24_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[103])                    /* 0x400121C0 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT25_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[104])                    /* 0x40012200 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT26_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[105])                    /* 0x40012240 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT27_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[106])                    /* 0x40012280 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT28_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[107])                    /* 0x400122C0 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT29_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[108])                    /* 0x40012300 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT30_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[109])                    /* 0x40012340 */
#define PERI_MS_PPU_FX_DW0_CH_STRUCT31_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[110])                    /* 0x40012380 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT0_CH        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[111])                    /* 0x400123C0 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT1_CH        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[112])                    /* 0x40012400 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT2_CH        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[113])                    /* 0x40012440 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT3_CH        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[114])                    /* 0x40012480 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT4_CH        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[115])                    /* 0x400124C0 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT5_CH        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[116])                    /* 0x40012500 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT6_CH        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[117])                    /* 0x40012540 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT7_CH        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[118])                    /* 0x40012580 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT8_CH        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[119])                    /* 0x400125C0 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT9_CH        ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[120])                    /* 0x40012600 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT10_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[121])                    /* 0x40012640 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT11_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[122])                    /* 0x40012680 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT12_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[123])                    /* 0x400126C0 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT13_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[124])                    /* 0x40012700 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT14_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[125])                    /* 0x40012740 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT15_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[126])                    /* 0x40012780 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT16_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[127])                    /* 0x400127C0 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT17_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[128])                    /* 0x40012800 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT18_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[129])                    /* 0x40012840 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT19_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[130])                    /* 0x40012880 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT20_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[131])                    /* 0x400128C0 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT21_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[132])                    /* 0x40012900 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT22_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[133])                    /* 0x40012940 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT23_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[134])                    /* 0x40012980 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT24_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[135])                    /* 0x400129C0 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT25_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[136])                    /* 0x40012A00 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT26_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[137])                    /* 0x40012A40 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT27_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[138])                    /* 0x40012A80 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT28_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[139])                    /* 0x40012AC0 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT29_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[140])                    /* 0x40012B00 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT30_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[141])                    /* 0x40012B40 */
#define PERI_MS_PPU_FX_DW1_CH_STRUCT31_CH       ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[142])                    /* 0x40012B80 */
#define PERI_MS_PPU_FX_DMAC_TOP                 ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[143])                    /* 0x40012BC0 */
#define PERI_MS_PPU_FX_DMAC_CH0_CH              ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[144])                    /* 0x40012C00 */
#define PERI_MS_PPU_FX_DMAC_CH1_CH              ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[145])                    /* 0x40012C40 */
#define PERI_MS_PPU_FX_DMAC_CH2_CH              ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[146])                    /* 0x40012C80 */
#define PERI_MS_PPU_FX_DMAC_CH3_CH              ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[147])                    /* 0x40012CC0 */
#define PERI_MS_PPU_FX_DMAC_CH4_CH              ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[148])                    /* 0x40012D00 */
#define PERI_MS_PPU_FX_DMAC_CH5_CH              ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[149])                    /* 0x40012D40 */
#define PERI_MS_PPU_FX_EFUSE_CTL                ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[150])                    /* 0x40012D80 */
#define PERI_MS_PPU_FX_EFUSE_DATA               ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[151])                    /* 0x40012DC0 */
#define PERI_MS_PPU_FX_HSIOM_PRT0_PRT           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[152])                    /* 0x40012E00 */
#define PERI_MS_PPU_FX_HSIOM_PRT1_PRT           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[153])                    /* 0x40012E40 */
#define PERI_MS_PPU_FX_HSIOM_PRT2_PRT           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[154])                    /* 0x40012E80 */
#define PERI_MS_PPU_FX_HSIOM_PRT3_PRT           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[155])                    /* 0x40012EC0 */
#define PERI_MS_PPU_FX_HSIOM_PRT4_PRT           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[156])                    /* 0x40012F00 */
#define PERI_MS_PPU_FX_HSIOM_PRT5_PRT           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[157])                    /* 0x40012F40 */
#define PERI_MS_PPU_FX_HSIOM_PRT6_PRT           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[158])                    /* 0x40012F80 */
#define PERI_MS_PPU_FX_HSIOM_PRT7_PRT           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[159])                    /* 0x40012FC0 */
#define PERI_MS_PPU_FX_HSIOM_PRT8_PRT           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[160])                    /* 0x40013000 */
#define PERI_MS_PPU_FX_HSIOM_PRT9_PRT           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[161])                    /* 0x40013040 */
#define PERI_MS_PPU_FX_HSIOM_PRT10_PRT          ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[162])                    /* 0x40013080 */
#define PERI_MS_PPU_FX_HSIOM_PRT11_PRT          ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[163])                    /* 0x400130C0 */
#define PERI_MS_PPU_FX_HSIOM_PRT12_PRT          ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[164])                    /* 0x40013100 */
#define PERI_MS_PPU_FX_HSIOM_PRT13_PRT          ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[165])                    /* 0x40013140 */
#define PERI_MS_PPU_FX_HSIOM_AMUX               ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[166])                    /* 0x40013180 */
#define PERI_MS_PPU_FX_HSIOM_MON                ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[167])                    /* 0x400131C0 */
#define PERI_MS_PPU_FX_GPIO_PRT0_PRT            ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[168])                    /* 0x40013200 */
#define PERI_MS_PPU_FX_GPIO_PRT1_PRT            ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[169])                    /* 0x40013240 */
#define PERI_MS_PPU_FX_GPIO_PRT2_PRT            ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[170])                    /* 0x40013280 */
#define PERI_MS_PPU_FX_GPIO_PRT3_PRT            ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[171])                    /* 0x400132C0 */
#define PERI_MS_PPU_FX_GPIO_PRT4_PRT            ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[172])                    /* 0x40013300 */
#define PERI_MS_PPU_FX_GPIO_PRT5_PRT            ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[173])                    /* 0x40013340 */
#define PERI_MS_PPU_FX_GPIO_PRT6_PRT            ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[174])                    /* 0x40013380 */
#define PERI_MS_PPU_FX_GPIO_PRT7_PRT            ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[175])                    /* 0x400133C0 */
#define PERI_MS_PPU_FX_GPIO_PRT8_PRT            ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[176])                    /* 0x40013400 */
#define PERI_MS_PPU_FX_GPIO_PRT9_PRT            ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[177])                    /* 0x40013440 */
#define PERI_MS_PPU_FX_GPIO_PRT10_PRT           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[178])                    /* 0x40013480 */
#define PERI_MS_PPU_FX_GPIO_PRT11_PRT           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[179])                    /* 0x400134C0 */
#define PERI_MS_PPU_FX_GPIO_PRT12_PRT           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[180])                    /* 0x40013500 */
#define PERI_MS_PPU_FX_GPIO_PRT13_PRT           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[181])                    /* 0x40013540 */
#define PERI_MS_PPU_FX_GPIO_PRT0_CFG            ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[182])                    /* 0x40013580 */
#define PERI_MS_PPU_FX_GPIO_PRT1_CFG            ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[183])                    /* 0x400135C0 */
#define PERI_MS_PPU_FX_GPIO_PRT2_CFG            ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[184])                    /* 0x40013600 */
#define PERI_MS_PPU_FX_GPIO_PRT3_CFG            ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[185])                    /* 0x40013640 */
#define PERI_MS_PPU_FX_GPIO_PRT4_CFG            ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[186])                    /* 0x40013680 */
#define PERI_MS_PPU_FX_GPIO_PRT5_CFG            ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[187])                    /* 0x400136C0 */
#define PERI_MS_PPU_FX_GPIO_PRT6_CFG            ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[188])                    /* 0x40013700 */
#define PERI_MS_PPU_FX_GPIO_PRT7_CFG            ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[189])                    /* 0x40013740 */
#define PERI_MS_PPU_FX_GPIO_PRT8_CFG            ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[190])                    /* 0x40013780 */
#define PERI_MS_PPU_FX_GPIO_PRT9_CFG            ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[191])                    /* 0x400137C0 */
#define PERI_MS_PPU_FX_GPIO_PRT10_CFG           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[192])                    /* 0x40013800 */
#define PERI_MS_PPU_FX_GPIO_PRT11_CFG           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[193])                    /* 0x40013840 */
#define PERI_MS_PPU_FX_GPIO_PRT12_CFG           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[194])                    /* 0x40013880 */
#define PERI_MS_PPU_FX_GPIO_PRT13_CFG           ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[195])                    /* 0x400138C0 */
#define PERI_MS_PPU_FX_GPIO_GPIO                ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[196])                    /* 0x40013900 */
#define PERI_MS_PPU_FX_GPIO_TEST                ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[197])                    /* 0x40013940 */
#define PERI_MS_PPU_FX_PDM0_MAIN                ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[198])                    /* 0x40013980 */
#define PERI_MS_PPU_FX_PDM0_CH0_RX              ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[199])                    /* 0x400139C0 */
#define PERI_MS_PPU_FX_PDM0_CH1_RX              ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[200])                    /* 0x40013A00 */
#define PERI_MS_PPU_FX_TCPWM0                   ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[201])                    /* 0x40013A40 */
#define PERI_MS_PPU_FX_SMIF0                    ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[202])                    /* 0x40013A80 */
#define PERI_MS_PPU_FX_USBFS0                   ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[203])                    /* 0x40013AC0 */
#define PERI_MS_PPU_FX_MXS40USBHSDEV            ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[204])                    /* 0x40013B00 */
#define PERI_MS_PPU_FX_SCB0                     ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[205])                    /* 0x40013B40 */
#define PERI_MS_PPU_FX_SCB1                     ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[206])                    /* 0x40013B80 */
#define PERI_MS_PPU_FX_SCB2                     ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[207])                    /* 0x40013BC0 */
#define PERI_MS_PPU_FX_SCB3                     ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[208])                    /* 0x40013C00 */
#define PERI_MS_PPU_FX_SCB4                     ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[209])                    /* 0x40013C40 */
#define PERI_MS_PPU_FX_SCB5                     ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[210])                    /* 0x40013C80 */
#define PERI_MS_PPU_FX_SCB6                     ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[211])                    /* 0x40013CC0 */
#define PERI_MS_PPU_FX_CANFD0_CH0_CH            ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[212])                    /* 0x40013D00 */
#define PERI_MS_PPU_FX_CANFD0_MAIN              ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[213])                    /* 0x40013D40 */
#define PERI_MS_PPU_FX_CANFD0_BUF               ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[214])                    /* 0x40013D80 */
#define PERI_MS_PPU_FX_TDM0_TDM_STRUCT0_TDM_TX_STRUCT_TX ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[215])           /* 0x40013DC0 */
#define PERI_MS_PPU_FX_TDM0_TDM_STRUCT0_TDM_RX_STRUCT_RX ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[216])           /* 0x40013E00 */
#define PERI_MS_PPU_FX_MAIN_REG                 ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[217])                    /* 0x40013E40 */
#define PERI_MS_PPU_FX_USB32DEV                 ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[218])                    /* 0x40013E80 */
#define PERI_MS_PPU_FX_LVDSSS                   ((PERI_MS_PPU_FX_Type*) &PERI_MS->PPU_FX[219])                    /* 0x40013EC0 */

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
#define IPC_STRUCT8                             ((IPC_STRUCT_Type*) &IPC->STRUCT[8])                              /* 0x40220100 */
#define IPC_STRUCT9                             ((IPC_STRUCT_Type*) &IPC->STRUCT[9])                              /* 0x40220120 */
#define IPC_STRUCT10                            ((IPC_STRUCT_Type*) &IPC->STRUCT[10])                             /* 0x40220140 */
#define IPC_STRUCT11                            ((IPC_STRUCT_Type*) &IPC->STRUCT[11])                             /* 0x40220160 */
#define IPC_STRUCT12                            ((IPC_STRUCT_Type*) &IPC->STRUCT[12])                             /* 0x40220180 */
#define IPC_STRUCT13                            ((IPC_STRUCT_Type*) &IPC->STRUCT[13])                             /* 0x402201A0 */
#define IPC_STRUCT14                            ((IPC_STRUCT_Type*) &IPC->STRUCT[14])                             /* 0x402201C0 */
#define IPC_STRUCT15                            ((IPC_STRUCT_Type*) &IPC->STRUCT[15])                             /* 0x402201E0 */
#define IPC_INTR_STRUCT0                        ((IPC_INTR_STRUCT_Type*) &IPC->INTR_STRUCT[0])                    /* 0x40221000 */
#define IPC_INTR_STRUCT1                        ((IPC_INTR_STRUCT_Type*) &IPC->INTR_STRUCT[1])                    /* 0x40221020 */
#define IPC_INTR_STRUCT2                        ((IPC_INTR_STRUCT_Type*) &IPC->INTR_STRUCT[2])                    /* 0x40221040 */
#define IPC_INTR_STRUCT3                        ((IPC_INTR_STRUCT_Type*) &IPC->INTR_STRUCT[3])                    /* 0x40221060 */
#define IPC_INTR_STRUCT4                        ((IPC_INTR_STRUCT_Type*) &IPC->INTR_STRUCT[4])                    /* 0x40221080 */
#define IPC_INTR_STRUCT5                        ((IPC_INTR_STRUCT_Type*) &IPC->INTR_STRUCT[5])                    /* 0x402210A0 */
#define IPC_INTR_STRUCT6                        ((IPC_INTR_STRUCT_Type*) &IPC->INTR_STRUCT[6])                    /* 0x402210C0 */
#define IPC_INTR_STRUCT7                        ((IPC_INTR_STRUCT_Type*) &IPC->INTR_STRUCT[7])                    /* 0x402210E0 */
#define IPC_INTR_STRUCT8                        ((IPC_INTR_STRUCT_Type*) &IPC->INTR_STRUCT[8])                    /* 0x40221100 */
#define IPC_INTR_STRUCT9                        ((IPC_INTR_STRUCT_Type*) &IPC->INTR_STRUCT[9])                    /* 0x40221120 */
#define IPC_INTR_STRUCT10                       ((IPC_INTR_STRUCT_Type*) &IPC->INTR_STRUCT[10])                   /* 0x40221140 */
#define IPC_INTR_STRUCT11                       ((IPC_INTR_STRUCT_Type*) &IPC->INTR_STRUCT[11])                   /* 0x40221160 */
#define IPC_INTR_STRUCT12                       ((IPC_INTR_STRUCT_Type*) &IPC->INTR_STRUCT[12])                   /* 0x40221180 */
#define IPC_INTR_STRUCT13                       ((IPC_INTR_STRUCT_Type*) &IPC->INTR_STRUCT[13])                   /* 0x402211A0 */
#define IPC_INTR_STRUCT14                       ((IPC_INTR_STRUCT_Type*) &IPC->INTR_STRUCT[14])                   /* 0x402211C0 */
#define IPC_INTR_STRUCT15                       ((IPC_INTR_STRUCT_Type*) &IPC->INTR_STRUCT[15])                   /* 0x402211E0 */

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
#define FLASHC_FM_CTL                           ((FLASHC_FM_CTL_Type*) &FLASHC->FM_CTL)                           /* 0x4024F000 */

/*******************************************************************************
*                                     SRSS
*******************************************************************************/

#define SRSS_BASE                               0x40260000UL
#define SRSS                                    ((SRSS_Type*) SRSS_BASE)                                          /* 0x40260000 */
#define MCWDT_STRUCT0                           ((MCWDT_STRUCT_Type*) &SRSS->MCWDT_STRUCT[0])                     /* 0x40260200 */
#define MCWDT_STRUCT1                           ((MCWDT_STRUCT_Type*) &SRSS->MCWDT_STRUCT[1])                     /* 0x40260240 */

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

/*******************************************************************************
*                                     PDM
*******************************************************************************/

#define PDM0_BASE                               0x40320000UL
#define PDM0                                    ((PDM_Type*) PDM0_BASE)                                           /* 0x40320000 */
#define PDM0_CH0                                ((PDM_CH_Type*) &PDM0->CH[0])                                     /* 0x40328000 */
#define PDM0_CH1                                ((PDM_CH_Type*) &PDM0->CH[1])                                     /* 0x40328100 */

/*******************************************************************************
*                                    TCPWM
*******************************************************************************/

#define TCPWM0_BASE                             0x40400000UL
#define TCPWM0                                  ((TCPWM_Type*) TCPWM0_BASE)                                       /* 0x40400000 */
#define TCPWM0_CNT0                             ((TCPWM_CNT_Type*) &TCPWM0->CNT[0])                               /* 0x40400100 */
#define TCPWM0_CNT1                             ((TCPWM_CNT_Type*) &TCPWM0->CNT[1])                               /* 0x40400140 */
#define TCPWM0_CNT2                             ((TCPWM_CNT_Type*) &TCPWM0->CNT[2])                               /* 0x40400180 */
#define TCPWM0_CNT3                             ((TCPWM_CNT_Type*) &TCPWM0->CNT[3])                               /* 0x404001C0 */
#define TCPWM0_CNT4                             ((TCPWM_CNT_Type*) &TCPWM0->CNT[4])                               /* 0x40400200 */
#define TCPWM0_CNT5                             ((TCPWM_CNT_Type*) &TCPWM0->CNT[5])                               /* 0x40400240 */
#define TCPWM0_CNT6                             ((TCPWM_CNT_Type*) &TCPWM0->CNT[6])                               /* 0x40400280 */
#define TCPWM0_CNT7                             ((TCPWM_CNT_Type*) &TCPWM0->CNT[7])                               /* 0x404002C0 */

/*******************************************************************************
*                                    USBFS
*******************************************************************************/

#define USBFS0_BASE                             0x40420000UL
#define USBFS0                                  ((USBFS_Type*) USBFS0_BASE)                                       /* 0x40420000 */
#define USBFS0_USBDEV                           ((USBFS_USBDEV_Type*) &USBFS0->USBDEV)                            /* 0x40420000 */
#define USBFS0_USBLPM                           ((USBFS_USBLPM_Type*) &USBFS0->USBLPM)                            /* 0x40422000 */
#define USBFS0_USBHOST                          ((USBFS_USBHOST_Type*) &USBFS0->USBHOST)                          /* 0x40424000 */

/*******************************************************************************
*                                MXS40USBHSDEV
*******************************************************************************/

#define MXS40USBHSDEV_BASE                      0x40430000UL
#define MXS40USBHSDEV                           ((MXS40USBHSDEV_Type*) MXS40USBHSDEV_BASE)                        /* 0x40430000 */
#define MXS40USBHSDEV_USBHSDEV                  ((USBHSDEV_Type*) &MXS40USBHSDEV->USBHSDEV)         /* 0x40430000 */
#define MXS40USBHSDEV_USBHSPHY                  ((USBHSPHY_Type*) &MXS40USBHSDEV->USBHSPHY)         /* 0x40439800 */

/*******************************************************************************
*                                     SCB
*******************************************************************************/

#define SCB0_BASE                               0x40500000UL
#define SCB1_BASE                               0x40510000UL
#define SCB2_BASE                               0x40520000UL
#define SCB3_BASE                               0x40530000UL
#define SCB4_BASE                               0x40540000UL
#define SCB5_BASE                               0x40550000UL
#define SCB6_BASE                               0x40560000UL
#define SCB0                                    ((CySCB_Type*) SCB0_BASE)                                         /* 0x40500000 */
#define SCB1                                    ((CySCB_Type*) SCB1_BASE)                                         /* 0x40510000 */
#define SCB2                                    ((CySCB_Type*) SCB2_BASE)                                         /* 0x40520000 */
#define SCB3                                    ((CySCB_Type*) SCB3_BASE)                                         /* 0x40530000 */
#define SCB4                                    ((CySCB_Type*) SCB4_BASE)                                         /* 0x40540000 */
#define SCB5                                    ((CySCB_Type*) SCB5_BASE)                                         /* 0x40550000 */
#define SCB6                                    ((CySCB_Type*) SCB6_BASE)                                         /* 0x40560000 */

/*******************************************************************************
*                                    CANFD
*******************************************************************************/

#define CANFD0_BASE                             0x40580000UL
#define CANFD0                                  ((CANFD_Type*) CANFD0_BASE)                                       /* 0x40580000 */
#define CANFD0_CH0                              ((CANFD_CH_Type*) &CANFD0->CH[0])                                 /* 0x40580000 */
#define CANFD0_CH0_M_TTCAN                      ((CANFD_CH_M_TTCAN_Type*) &CANFD0->CH[0].M_TTCAN)                 /* 0x40580000 */

/*******************************************************************************
*                                     TDM
*******************************************************************************/

#define TDM0_BASE                               0x405A0000UL
#define TDM0                                    ((TDM_Type*) TDM0_BASE)                                           /* 0x405A0000 */
#define TDM0_TDM_STRUCT0                        ((TDM_TDM_STRUCT_Type*) &TDM0->TDM_STRUCT[0])                     /* 0x405A8000 */
#define TDM0_TDM_STRUCT0_TDM_TX_STRUCT          ((TDM_TDM_STRUCT_TDM_TX_STRUCT_Type*) &TDM0->TDM_STRUCT[0].TDM_TX_STRUCT) /* 0x405A8000 */
#define TDM0_TDM_STRUCT0_TDM_RX_STRUCT          ((TDM_TDM_STRUCT_TDM_RX_STRUCT_Type*) &TDM0->TDM_STRUCT[0].TDM_RX_STRUCT) /* 0x405A8100 */

/*******************************************************************************
*                                   MAIN_REG
*******************************************************************************/

#define MAIN_REG_BASE                           0x40640000UL
#define MAIN_REG                                ((MAIN_REG_Type*) MAIN_REG_BASE)                                  /* 0x40640000 */
#define MAIN_REG_TR_GR0                         ((MAIN_REG_TR_GR_Type*) &MAIN_REG->TR_GR[0])                      /* 0x40640400 */
#define MAIN_REG_TR_ASSIST_GR0                  ((MAIN_REG_TR_ASSIST_GR_Type*) &MAIN_REG->TR_ASSIST_GR[0])        /* 0x40640800 */

/*******************************************************************************
*                                   USB32DEV
*******************************************************************************/

#define USB32DEV_BASE                           0x40680000UL
#define USB32DEV                                ((USB32DEV_Type*) USB32DEV_BASE)                                  /* 0x40680000 */
#define USB32DEV_USB32DEV_MAIN         ((USB32DEV_MAIN_Type*) &USB32DEV->USB32DEV_MAIN) /* 0x40680000 */
#define USB32DEV_USB32DEV_EPM          ((USB32DEV_EPM_Type*) &USB32DEV->USB32DEV_EPM) /* 0x40681000 */
#define USB32DEV_USB32DEV_LNK          ((USB32DEV_LNK_Type*) &USB32DEV->USB32DEV_LNK) /* 0x40682000 */
#define USB32DEV_USB32DEV_PROT         ((USB32DEV_PROT_Type*) &USB32DEV->USB32DEV_PROT) /* 0x40683000 */
#define USB32DEV_USB32DEV_PHYSS        ((USB32DEV_PHYSS_Type*) &USB32DEV->USB32DEV_PHYSS) /* 0x40684000 */
#define USB32DEV_PHYSS_USB40PHY0 ((USB32DEV_PHYSS_USB40PHY_Type*) &USB32DEV->USB32DEV_PHYSS.USB40PHY[0]) /* 0x40684000 */
#define USB32DEV_PHYSS_USB40PHY1 ((USB32DEV_PHYSS_USB40PHY_Type*) &USB32DEV->USB32DEV_PHYSS.USB40PHY[1]) /* 0x40685000 */
#define USB32DEV_PHYSS_USB40PHY0_USB40PHY_TOP ((USB32DEV_PHYSS_USB40PHY_TOP_Type*) &USB32DEV->USB32DEV_PHYSS.USB40PHY[0].USB40PHY_TOP) /* 0x40684000 */
#define USB32DEV_PHYSS_USB40PHY1_USB40PHY_TOP ((USB32DEV_PHYSS_USB40PHY_TOP_Type*) &USB32DEV->USB32DEV_PHYSS.USB40PHY[1].USB40PHY_TOP) /* 0x40685000 */
#define USB32DEV_PHYSS_USB40PHY0_USB40PHY_RX ((USB32DEV_PHYSS_USB40PHY_RX_Type*) &USB32DEV->USB32DEV_PHYSS.USB40PHY[0].USB40PHY_RX) /* 0x40684800 */
#define USB32DEV_PHYSS_USB40PHY1_USB40PHY_RX ((USB32DEV_PHYSS_USB40PHY_RX_Type*) &USB32DEV->USB32DEV_PHYSS.USB40PHY[1].USB40PHY_RX) /* 0x40685800 */
#define USB32DEV_PHYSS_USB40PHY0_USB40PHY_PLL_SYS ((USB32DEV_PHYSS_USB40PHY_PLL_SYS_Type*) &USB32DEV->USB32DEV_PHYSS.USB40PHY[0].USB40PHY_PLL_SYS) /* 0x40684900 */
#define USB32DEV_PHYSS_USB40PHY1_USB40PHY_PLL_SYS ((USB32DEV_PHYSS_USB40PHY_PLL_SYS_Type*) &USB32DEV->USB32DEV_PHYSS.USB40PHY[1].USB40PHY_PLL_SYS) /* 0x40685900 */
#define USB32DEV_ADAPTER_DMA0 ((USB32DEV_ADAPTER_DMA_Type*) &USB32DEV->USB32DEV_ADAPTER[0]) /* 0x40690000 */
#define USB32DEV_ADAPTER_DMA1 ((USB32DEV_ADAPTER_DMA_Type*) &USB32DEV->USB32DEV_ADAPTER[1]) /* 0x406A0000 */
#define USB32DEV_ADAPTER_DMA0_SCK0 ((USB32DEV_ADAPTER_DMA_SCK_Type*) &USB32DEV->USB32DEV_ADAPTER[0].SCK[0]) /* 0x40698000 */
#define USB32DEV_ADAPTER_DMA0_SCK1 ((USB32DEV_ADAPTER_DMA_SCK_Type*) &USB32DEV->USB32DEV_ADAPTER[0].SCK[1]) /* 0x40698080 */
#define USB32DEV_ADAPTER_DMA0_SCK2 ((USB32DEV_ADAPTER_DMA_SCK_Type*) &USB32DEV->USB32DEV_ADAPTER[0].SCK[2]) /* 0x40698100 */
#define USB32DEV_ADAPTER_DMA0_SCK3 ((USB32DEV_ADAPTER_DMA_SCK_Type*) &USB32DEV->USB32DEV_ADAPTER[0].SCK[3]) /* 0x40698180 */
#define USB32DEV_ADAPTER_DMA0_SCK4 ((USB32DEV_ADAPTER_DMA_SCK_Type*) &USB32DEV->USB32DEV_ADAPTER[0].SCK[4]) /* 0x40698200 */
#define USB32DEV_ADAPTER_DMA0_SCK5 ((USB32DEV_ADAPTER_DMA_SCK_Type*) &USB32DEV->USB32DEV_ADAPTER[0].SCK[5]) /* 0x40698280 */
#define USB32DEV_ADAPTER_DMA0_SCK6 ((USB32DEV_ADAPTER_DMA_SCK_Type*) &USB32DEV->USB32DEV_ADAPTER[0].SCK[6]) /* 0x40698300 */
#define USB32DEV_ADAPTER_DMA0_SCK7 ((USB32DEV_ADAPTER_DMA_SCK_Type*) &USB32DEV->USB32DEV_ADAPTER[0].SCK[7]) /* 0x40698380 */
#define USB32DEV_ADAPTER_DMA0_SCK8 ((USB32DEV_ADAPTER_DMA_SCK_Type*) &USB32DEV->USB32DEV_ADAPTER[0].SCK[8]) /* 0x40698400 */
#define USB32DEV_ADAPTER_DMA0_SCK9 ((USB32DEV_ADAPTER_DMA_SCK_Type*) &USB32DEV->USB32DEV_ADAPTER[0].SCK[9]) /* 0x40698480 */
#define USB32DEV_ADAPTER_DMA0_SCK10 ((USB32DEV_ADAPTER_DMA_SCK_Type*) &USB32DEV->USB32DEV_ADAPTER[0].SCK[10]) /* 0x40698500 */
#define USB32DEV_ADAPTER_DMA0_SCK11 ((USB32DEV_ADAPTER_DMA_SCK_Type*) &USB32DEV->USB32DEV_ADAPTER[0].SCK[11]) /* 0x40698580 */
#define USB32DEV_ADAPTER_DMA0_SCK12 ((USB32DEV_ADAPTER_DMA_SCK_Type*) &USB32DEV->USB32DEV_ADAPTER[0].SCK[12]) /* 0x40698600 */
#define USB32DEV_ADAPTER_DMA0_SCK13 ((USB32DEV_ADAPTER_DMA_SCK_Type*) &USB32DEV->USB32DEV_ADAPTER[0].SCK[13]) /* 0x40698680 */
#define USB32DEV_ADAPTER_DMA0_SCK14 ((USB32DEV_ADAPTER_DMA_SCK_Type*) &USB32DEV->USB32DEV_ADAPTER[0].SCK[14]) /* 0x40698700 */
#define USB32DEV_ADAPTER_DMA0_SCK15 ((USB32DEV_ADAPTER_DMA_SCK_Type*) &USB32DEV->USB32DEV_ADAPTER[0].SCK[15]) /* 0x40698780 */
#define USB32DEV_ADAPTER_DMA1_SCK0 ((USB32DEV_ADAPTER_DMA_SCK_Type*) &USB32DEV->USB32DEV_ADAPTER[1].SCK[0]) /* 0x406A8000 */
#define USB32DEV_ADAPTER_DMA1_SCK1 ((USB32DEV_ADAPTER_DMA_SCK_Type*) &USB32DEV->USB32DEV_ADAPTER[1].SCK[1]) /* 0x406A8080 */
#define USB32DEV_ADAPTER_DMA1_SCK2 ((USB32DEV_ADAPTER_DMA_SCK_Type*) &USB32DEV->USB32DEV_ADAPTER[1].SCK[2]) /* 0x406A8100 */
#define USB32DEV_ADAPTER_DMA1_SCK3 ((USB32DEV_ADAPTER_DMA_SCK_Type*) &USB32DEV->USB32DEV_ADAPTER[1].SCK[3]) /* 0x406A8180 */
#define USB32DEV_ADAPTER_DMA1_SCK4 ((USB32DEV_ADAPTER_DMA_SCK_Type*) &USB32DEV->USB32DEV_ADAPTER[1].SCK[4]) /* 0x406A8200 */
#define USB32DEV_ADAPTER_DMA1_SCK5 ((USB32DEV_ADAPTER_DMA_SCK_Type*) &USB32DEV->USB32DEV_ADAPTER[1].SCK[5]) /* 0x406A8280 */
#define USB32DEV_ADAPTER_DMA1_SCK6 ((USB32DEV_ADAPTER_DMA_SCK_Type*) &USB32DEV->USB32DEV_ADAPTER[1].SCK[6]) /* 0x406A8300 */
#define USB32DEV_ADAPTER_DMA1_SCK7 ((USB32DEV_ADAPTER_DMA_SCK_Type*) &USB32DEV->USB32DEV_ADAPTER[1].SCK[7]) /* 0x406A8380 */
#define USB32DEV_ADAPTER_DMA1_SCK8 ((USB32DEV_ADAPTER_DMA_SCK_Type*) &USB32DEV->USB32DEV_ADAPTER[1].SCK[8]) /* 0x406A8400 */
#define USB32DEV_ADAPTER_DMA1_SCK9 ((USB32DEV_ADAPTER_DMA_SCK_Type*) &USB32DEV->USB32DEV_ADAPTER[1].SCK[9]) /* 0x406A8480 */
#define USB32DEV_ADAPTER_DMA1_SCK10 ((USB32DEV_ADAPTER_DMA_SCK_Type*) &USB32DEV->USB32DEV_ADAPTER[1].SCK[10]) /* 0x406A8500 */
#define USB32DEV_ADAPTER_DMA1_SCK11 ((USB32DEV_ADAPTER_DMA_SCK_Type*) &USB32DEV->USB32DEV_ADAPTER[1].SCK[11]) /* 0x406A8580 */
#define USB32DEV_ADAPTER_DMA1_SCK12 ((USB32DEV_ADAPTER_DMA_SCK_Type*) &USB32DEV->USB32DEV_ADAPTER[1].SCK[12]) /* 0x406A8600 */
#define USB32DEV_ADAPTER_DMA1_SCK13 ((USB32DEV_ADAPTER_DMA_SCK_Type*) &USB32DEV->USB32DEV_ADAPTER[1].SCK[13]) /* 0x406A8680 */
#define USB32DEV_ADAPTER_DMA1_SCK14 ((USB32DEV_ADAPTER_DMA_SCK_Type*) &USB32DEV->USB32DEV_ADAPTER[1].SCK[14]) /* 0x406A8700 */
#define USB32DEV_ADAPTER_DMA1_SCK15 ((USB32DEV_ADAPTER_DMA_SCK_Type*) &USB32DEV->USB32DEV_ADAPTER[1].SCK[15]) /* 0x406A8780 */
#define USB32DEV_ADAPTER_DMA0_SCK_GBL ((USB32DEV_ADAPTER_DMA_SCK_GBL_Type*) &USB32DEV->USB32DEV_ADAPTER[0].SCK_GBL) /* 0x4069FF00 */
#define USB32DEV_ADAPTER_DMA1_SCK_GBL ((USB32DEV_ADAPTER_DMA_SCK_GBL_Type*) &USB32DEV->USB32DEV_ADAPTER[1].SCK_GBL) /* 0x406AFF00 */

/*******************************************************************************
*                                    LVDSSS
*******************************************************************************/

#define LVDSSS_BASE                             0x406C0000UL
#define LVDSSS                                  ((LVDSSS_Type*) LVDSSS_BASE)                                      /* 0x406C0000 */
#define LVDSSS_LVDS                             ((LVDSSS_LVDS_Type*) &LVDSSS->LVDS)                               /* 0x406C0000 */
#define LVDSSS_LVDS_LVDS_LOW_PWR_INTR           ((LVDSSS_LVDS_LVDS_LOW_PWR_INTR_Type*) &LVDSSS->LVDS.LVDS_LOW_PWR_INTR) /* 0x406C00C0 */
#define LVDSSS_LVDS_THREAD0                     ((LVDSSS_LVDS_THREAD_Type*) &LVDSSS->LVDS.THREAD[0])              /* 0x406C0400 */
#define LVDSSS_LVDS_THREAD1                     ((LVDSSS_LVDS_THREAD_Type*) &LVDSSS->LVDS.THREAD[1])              /* 0x406C0600 */
#define LVDSSS_LVDS_THREAD2                     ((LVDSSS_LVDS_THREAD_Type*) &LVDSSS->LVDS.THREAD[2])              /* 0x406C0800 */
#define LVDSSS_LVDS_THREAD3                     ((LVDSSS_LVDS_THREAD_Type*) &LVDSSS->LVDS.THREAD[3])              /* 0x406C0A00 */
#define LVDSSS_LVDS_GPIF0                       ((LVDSSS_LVDS_GPIF_Type*) &LVDSSS->LVDS.GPIF[0])                  /* 0x406C1000 */
#define LVDSSS_LVDS_GPIF1                       ((LVDSSS_LVDS_GPIF_Type*) &LVDSSS->LVDS.GPIF[1])                  /* 0x406C4000 */
#define LVDSSS_LVDS_GPIF0_LEFT                  ((LVDSSS_LVDS_GPIF_LEFT_Type*) &LVDSSS->LVDS.GPIF[0].LEFT)        /* 0x406C2000 */
#define LVDSSS_LVDS_GPIF1_LEFT                  ((LVDSSS_LVDS_GPIF_LEFT_Type*) &LVDSSS->LVDS.GPIF[1].LEFT)        /* 0x406C5000 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM0        ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[0]) /* 0x406C2000 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM1        ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[1]) /* 0x406C2010 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM2        ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[2]) /* 0x406C2020 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM3        ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[3]) /* 0x406C2030 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM4        ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[4]) /* 0x406C2040 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM5        ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[5]) /* 0x406C2050 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM6        ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[6]) /* 0x406C2060 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM7        ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[7]) /* 0x406C2070 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM8        ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[8]) /* 0x406C2080 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM9        ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[9]) /* 0x406C2090 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM10       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[10]) /* 0x406C20A0 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM11       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[11]) /* 0x406C20B0 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM12       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[12]) /* 0x406C20C0 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM13       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[13]) /* 0x406C20D0 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM14       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[14]) /* 0x406C20E0 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM15       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[15]) /* 0x406C20F0 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM16       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[16]) /* 0x406C2100 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM17       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[17]) /* 0x406C2110 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM18       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[18]) /* 0x406C2120 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM19       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[19]) /* 0x406C2130 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM20       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[20]) /* 0x406C2140 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM21       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[21]) /* 0x406C2150 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM22       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[22]) /* 0x406C2160 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM23       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[23]) /* 0x406C2170 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM24       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[24]) /* 0x406C2180 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM25       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[25]) /* 0x406C2190 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM26       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[26]) /* 0x406C21A0 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM27       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[27]) /* 0x406C21B0 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM28       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[28]) /* 0x406C21C0 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM29       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[29]) /* 0x406C21D0 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM30       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[30]) /* 0x406C21E0 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM31       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[31]) /* 0x406C21F0 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM32       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[32]) /* 0x406C2200 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM33       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[33]) /* 0x406C2210 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM34       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[34]) /* 0x406C2220 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM35       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[35]) /* 0x406C2230 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM36       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[36]) /* 0x406C2240 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM37       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[37]) /* 0x406C2250 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM38       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[38]) /* 0x406C2260 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM39       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[39]) /* 0x406C2270 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM40       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[40]) /* 0x406C2280 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM41       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[41]) /* 0x406C2290 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM42       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[42]) /* 0x406C22A0 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM43       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[43]) /* 0x406C22B0 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM44       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[44]) /* 0x406C22C0 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM45       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[45]) /* 0x406C22D0 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM46       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[46]) /* 0x406C22E0 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM47       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[47]) /* 0x406C22F0 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM48       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[48]) /* 0x406C2300 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM49       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[49]) /* 0x406C2310 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM50       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[50]) /* 0x406C2320 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM51       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[51]) /* 0x406C2330 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM52       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[52]) /* 0x406C2340 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM53       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[53]) /* 0x406C2350 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM54       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[54]) /* 0x406C2360 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM55       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[55]) /* 0x406C2370 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM56       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[56]) /* 0x406C2380 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM57       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[57]) /* 0x406C2390 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM58       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[58]) /* 0x406C23A0 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM59       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[59]) /* 0x406C23B0 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM60       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[60]) /* 0x406C23C0 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM61       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[61]) /* 0x406C23D0 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM62       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[62]) /* 0x406C23E0 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM63       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[63]) /* 0x406C23F0 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM64       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[64]) /* 0x406C2400 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM65       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[65]) /* 0x406C2410 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM66       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[66]) /* 0x406C2420 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM67       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[67]) /* 0x406C2430 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM68       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[68]) /* 0x406C2440 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM69       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[69]) /* 0x406C2450 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM70       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[70]) /* 0x406C2460 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM71       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[71]) /* 0x406C2470 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM72       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[72]) /* 0x406C2480 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM73       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[73]) /* 0x406C2490 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM74       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[74]) /* 0x406C24A0 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM75       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[75]) /* 0x406C24B0 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM76       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[76]) /* 0x406C24C0 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM77       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[77]) /* 0x406C24D0 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM78       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[78]) /* 0x406C24E0 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM79       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[79]) /* 0x406C24F0 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM80       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[80]) /* 0x406C2500 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM81       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[81]) /* 0x406C2510 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM82       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[82]) /* 0x406C2520 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM83       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[83]) /* 0x406C2530 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM84       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[84]) /* 0x406C2540 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM85       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[85]) /* 0x406C2550 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM86       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[86]) /* 0x406C2560 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM87       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[87]) /* 0x406C2570 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM88       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[88]) /* 0x406C2580 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM89       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[89]) /* 0x406C2590 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM90       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[90]) /* 0x406C25A0 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM91       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[91]) /* 0x406C25B0 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM92       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[92]) /* 0x406C25C0 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM93       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[93]) /* 0x406C25D0 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM94       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[94]) /* 0x406C25E0 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM95       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[95]) /* 0x406C25F0 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM96       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[96]) /* 0x406C2600 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM97       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[97]) /* 0x406C2610 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM98       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[98]) /* 0x406C2620 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM99       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[99]) /* 0x406C2630 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM100      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[100]) /* 0x406C2640 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM101      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[101]) /* 0x406C2650 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM102      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[102]) /* 0x406C2660 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM103      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[103]) /* 0x406C2670 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM104      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[104]) /* 0x406C2680 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM105      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[105]) /* 0x406C2690 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM106      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[106]) /* 0x406C26A0 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM107      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[107]) /* 0x406C26B0 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM108      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[108]) /* 0x406C26C0 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM109      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[109]) /* 0x406C26D0 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM110      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[110]) /* 0x406C26E0 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM111      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[111]) /* 0x406C26F0 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM112      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[112]) /* 0x406C2700 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM113      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[113]) /* 0x406C2710 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM114      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[114]) /* 0x406C2720 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM115      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[115]) /* 0x406C2730 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM116      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[116]) /* 0x406C2740 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM117      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[117]) /* 0x406C2750 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM118      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[118]) /* 0x406C2760 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM119      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[119]) /* 0x406C2770 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM120      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[120]) /* 0x406C2780 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM121      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[121]) /* 0x406C2790 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM122      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[122]) /* 0x406C27A0 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM123      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[123]) /* 0x406C27B0 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM124      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[124]) /* 0x406C27C0 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM125      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[125]) /* 0x406C27D0 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM126      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[126]) /* 0x406C27E0 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM127      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[127]) /* 0x406C27F0 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM128      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[128]) /* 0x406C2800 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM129      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[129]) /* 0x406C2810 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM130      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[130]) /* 0x406C2820 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM131      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[131]) /* 0x406C2830 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM132      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[132]) /* 0x406C2840 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM133      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[133]) /* 0x406C2850 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM134      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[134]) /* 0x406C2860 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM135      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[135]) /* 0x406C2870 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM136      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[136]) /* 0x406C2880 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM137      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[137]) /* 0x406C2890 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM138      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[138]) /* 0x406C28A0 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM139      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[139]) /* 0x406C28B0 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM140      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[140]) /* 0x406C28C0 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM141      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[141]) /* 0x406C28D0 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM142      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[142]) /* 0x406C28E0 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM143      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[143]) /* 0x406C28F0 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM144      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[144]) /* 0x406C2900 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM145      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[145]) /* 0x406C2910 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM146      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[146]) /* 0x406C2920 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM147      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[147]) /* 0x406C2930 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM148      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[148]) /* 0x406C2940 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM149      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[149]) /* 0x406C2950 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM150      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[150]) /* 0x406C2960 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM151      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[151]) /* 0x406C2970 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM152      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[152]) /* 0x406C2980 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM153      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[153]) /* 0x406C2990 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM154      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[154]) /* 0x406C29A0 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM155      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[155]) /* 0x406C29B0 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM156      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[156]) /* 0x406C29C0 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM157      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[157]) /* 0x406C29D0 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM158      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[158]) /* 0x406C29E0 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM159      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[159]) /* 0x406C29F0 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM160      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[160]) /* 0x406C2A00 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM161      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[161]) /* 0x406C2A10 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM162      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[162]) /* 0x406C2A20 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM163      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[163]) /* 0x406C2A30 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM164      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[164]) /* 0x406C2A40 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM165      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[165]) /* 0x406C2A50 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM166      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[166]) /* 0x406C2A60 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM167      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[167]) /* 0x406C2A70 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM168      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[168]) /* 0x406C2A80 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM169      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[169]) /* 0x406C2A90 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM170      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[170]) /* 0x406C2AA0 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM171      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[171]) /* 0x406C2AB0 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM172      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[172]) /* 0x406C2AC0 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM173      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[173]) /* 0x406C2AD0 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM174      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[174]) /* 0x406C2AE0 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM175      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[175]) /* 0x406C2AF0 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM176      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[176]) /* 0x406C2B00 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM177      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[177]) /* 0x406C2B10 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM178      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[178]) /* 0x406C2B20 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM179      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[179]) /* 0x406C2B30 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM180      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[180]) /* 0x406C2B40 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM181      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[181]) /* 0x406C2B50 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM182      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[182]) /* 0x406C2B60 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM183      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[183]) /* 0x406C2B70 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM184      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[184]) /* 0x406C2B80 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM185      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[185]) /* 0x406C2B90 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM186      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[186]) /* 0x406C2BA0 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM187      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[187]) /* 0x406C2BB0 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM188      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[188]) /* 0x406C2BC0 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM189      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[189]) /* 0x406C2BD0 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM190      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[190]) /* 0x406C2BE0 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM191      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[191]) /* 0x406C2BF0 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM192      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[192]) /* 0x406C2C00 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM193      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[193]) /* 0x406C2C10 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM194      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[194]) /* 0x406C2C20 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM195      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[195]) /* 0x406C2C30 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM196      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[196]) /* 0x406C2C40 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM197      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[197]) /* 0x406C2C50 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM198      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[198]) /* 0x406C2C60 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM199      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[199]) /* 0x406C2C70 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM200      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[200]) /* 0x406C2C80 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM201      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[201]) /* 0x406C2C90 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM202      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[202]) /* 0x406C2CA0 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM203      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[203]) /* 0x406C2CB0 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM204      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[204]) /* 0x406C2CC0 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM205      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[205]) /* 0x406C2CD0 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM206      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[206]) /* 0x406C2CE0 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM207      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[207]) /* 0x406C2CF0 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM208      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[208]) /* 0x406C2D00 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM209      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[209]) /* 0x406C2D10 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM210      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[210]) /* 0x406C2D20 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM211      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[211]) /* 0x406C2D30 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM212      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[212]) /* 0x406C2D40 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM213      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[213]) /* 0x406C2D50 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM214      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[214]) /* 0x406C2D60 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM215      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[215]) /* 0x406C2D70 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM216      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[216]) /* 0x406C2D80 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM217      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[217]) /* 0x406C2D90 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM218      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[218]) /* 0x406C2DA0 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM219      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[219]) /* 0x406C2DB0 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM220      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[220]) /* 0x406C2DC0 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM221      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[221]) /* 0x406C2DD0 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM222      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[222]) /* 0x406C2DE0 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM223      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[223]) /* 0x406C2DF0 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM224      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[224]) /* 0x406C2E00 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM225      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[225]) /* 0x406C2E10 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM226      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[226]) /* 0x406C2E20 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM227      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[227]) /* 0x406C2E30 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM228      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[228]) /* 0x406C2E40 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM229      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[229]) /* 0x406C2E50 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM230      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[230]) /* 0x406C2E60 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM231      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[231]) /* 0x406C2E70 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM232      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[232]) /* 0x406C2E80 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM233      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[233]) /* 0x406C2E90 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM234      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[234]) /* 0x406C2EA0 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM235      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[235]) /* 0x406C2EB0 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM236      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[236]) /* 0x406C2EC0 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM237      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[237]) /* 0x406C2ED0 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM238      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[238]) /* 0x406C2EE0 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM239      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[239]) /* 0x406C2EF0 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM240      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[240]) /* 0x406C2F00 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM241      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[241]) /* 0x406C2F10 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM242      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[242]) /* 0x406C2F20 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM243      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[243]) /* 0x406C2F30 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM244      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[244]) /* 0x406C2F40 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM245      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[245]) /* 0x406C2F50 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM246      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[246]) /* 0x406C2F60 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM247      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[247]) /* 0x406C2F70 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM248      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[248]) /* 0x406C2F80 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM249      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[249]) /* 0x406C2F90 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM250      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[250]) /* 0x406C2FA0 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM251      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[251]) /* 0x406C2FB0 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM252      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[252]) /* 0x406C2FC0 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM253      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[253]) /* 0x406C2FD0 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM254      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[254]) /* 0x406C2FE0 */
#define LVDSSS_LVDS_GPIF0_LEFT_WAVEFORM255      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].LEFT.WAVEFORM[255]) /* 0x406C2FF0 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM0        ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[0]) /* 0x406C5000 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM1        ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[1]) /* 0x406C5010 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM2        ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[2]) /* 0x406C5020 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM3        ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[3]) /* 0x406C5030 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM4        ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[4]) /* 0x406C5040 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM5        ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[5]) /* 0x406C5050 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM6        ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[6]) /* 0x406C5060 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM7        ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[7]) /* 0x406C5070 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM8        ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[8]) /* 0x406C5080 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM9        ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[9]) /* 0x406C5090 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM10       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[10]) /* 0x406C50A0 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM11       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[11]) /* 0x406C50B0 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM12       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[12]) /* 0x406C50C0 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM13       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[13]) /* 0x406C50D0 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM14       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[14]) /* 0x406C50E0 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM15       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[15]) /* 0x406C50F0 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM16       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[16]) /* 0x406C5100 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM17       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[17]) /* 0x406C5110 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM18       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[18]) /* 0x406C5120 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM19       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[19]) /* 0x406C5130 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM20       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[20]) /* 0x406C5140 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM21       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[21]) /* 0x406C5150 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM22       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[22]) /* 0x406C5160 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM23       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[23]) /* 0x406C5170 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM24       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[24]) /* 0x406C5180 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM25       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[25]) /* 0x406C5190 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM26       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[26]) /* 0x406C51A0 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM27       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[27]) /* 0x406C51B0 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM28       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[28]) /* 0x406C51C0 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM29       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[29]) /* 0x406C51D0 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM30       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[30]) /* 0x406C51E0 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM31       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[31]) /* 0x406C51F0 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM32       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[32]) /* 0x406C5200 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM33       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[33]) /* 0x406C5210 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM34       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[34]) /* 0x406C5220 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM35       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[35]) /* 0x406C5230 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM36       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[36]) /* 0x406C5240 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM37       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[37]) /* 0x406C5250 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM38       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[38]) /* 0x406C5260 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM39       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[39]) /* 0x406C5270 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM40       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[40]) /* 0x406C5280 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM41       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[41]) /* 0x406C5290 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM42       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[42]) /* 0x406C52A0 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM43       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[43]) /* 0x406C52B0 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM44       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[44]) /* 0x406C52C0 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM45       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[45]) /* 0x406C52D0 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM46       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[46]) /* 0x406C52E0 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM47       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[47]) /* 0x406C52F0 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM48       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[48]) /* 0x406C5300 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM49       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[49]) /* 0x406C5310 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM50       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[50]) /* 0x406C5320 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM51       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[51]) /* 0x406C5330 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM52       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[52]) /* 0x406C5340 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM53       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[53]) /* 0x406C5350 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM54       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[54]) /* 0x406C5360 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM55       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[55]) /* 0x406C5370 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM56       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[56]) /* 0x406C5380 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM57       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[57]) /* 0x406C5390 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM58       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[58]) /* 0x406C53A0 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM59       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[59]) /* 0x406C53B0 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM60       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[60]) /* 0x406C53C0 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM61       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[61]) /* 0x406C53D0 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM62       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[62]) /* 0x406C53E0 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM63       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[63]) /* 0x406C53F0 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM64       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[64]) /* 0x406C5400 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM65       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[65]) /* 0x406C5410 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM66       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[66]) /* 0x406C5420 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM67       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[67]) /* 0x406C5430 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM68       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[68]) /* 0x406C5440 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM69       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[69]) /* 0x406C5450 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM70       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[70]) /* 0x406C5460 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM71       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[71]) /* 0x406C5470 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM72       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[72]) /* 0x406C5480 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM73       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[73]) /* 0x406C5490 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM74       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[74]) /* 0x406C54A0 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM75       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[75]) /* 0x406C54B0 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM76       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[76]) /* 0x406C54C0 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM77       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[77]) /* 0x406C54D0 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM78       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[78]) /* 0x406C54E0 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM79       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[79]) /* 0x406C54F0 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM80       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[80]) /* 0x406C5500 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM81       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[81]) /* 0x406C5510 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM82       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[82]) /* 0x406C5520 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM83       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[83]) /* 0x406C5530 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM84       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[84]) /* 0x406C5540 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM85       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[85]) /* 0x406C5550 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM86       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[86]) /* 0x406C5560 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM87       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[87]) /* 0x406C5570 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM88       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[88]) /* 0x406C5580 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM89       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[89]) /* 0x406C5590 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM90       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[90]) /* 0x406C55A0 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM91       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[91]) /* 0x406C55B0 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM92       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[92]) /* 0x406C55C0 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM93       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[93]) /* 0x406C55D0 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM94       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[94]) /* 0x406C55E0 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM95       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[95]) /* 0x406C55F0 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM96       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[96]) /* 0x406C5600 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM97       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[97]) /* 0x406C5610 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM98       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[98]) /* 0x406C5620 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM99       ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[99]) /* 0x406C5630 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM100      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[100]) /* 0x406C5640 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM101      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[101]) /* 0x406C5650 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM102      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[102]) /* 0x406C5660 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM103      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[103]) /* 0x406C5670 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM104      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[104]) /* 0x406C5680 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM105      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[105]) /* 0x406C5690 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM106      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[106]) /* 0x406C56A0 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM107      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[107]) /* 0x406C56B0 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM108      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[108]) /* 0x406C56C0 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM109      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[109]) /* 0x406C56D0 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM110      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[110]) /* 0x406C56E0 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM111      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[111]) /* 0x406C56F0 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM112      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[112]) /* 0x406C5700 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM113      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[113]) /* 0x406C5710 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM114      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[114]) /* 0x406C5720 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM115      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[115]) /* 0x406C5730 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM116      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[116]) /* 0x406C5740 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM117      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[117]) /* 0x406C5750 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM118      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[118]) /* 0x406C5760 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM119      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[119]) /* 0x406C5770 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM120      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[120]) /* 0x406C5780 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM121      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[121]) /* 0x406C5790 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM122      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[122]) /* 0x406C57A0 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM123      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[123]) /* 0x406C57B0 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM124      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[124]) /* 0x406C57C0 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM125      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[125]) /* 0x406C57D0 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM126      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[126]) /* 0x406C57E0 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM127      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[127]) /* 0x406C57F0 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM128      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[128]) /* 0x406C5800 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM129      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[129]) /* 0x406C5810 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM130      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[130]) /* 0x406C5820 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM131      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[131]) /* 0x406C5830 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM132      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[132]) /* 0x406C5840 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM133      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[133]) /* 0x406C5850 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM134      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[134]) /* 0x406C5860 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM135      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[135]) /* 0x406C5870 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM136      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[136]) /* 0x406C5880 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM137      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[137]) /* 0x406C5890 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM138      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[138]) /* 0x406C58A0 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM139      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[139]) /* 0x406C58B0 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM140      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[140]) /* 0x406C58C0 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM141      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[141]) /* 0x406C58D0 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM142      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[142]) /* 0x406C58E0 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM143      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[143]) /* 0x406C58F0 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM144      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[144]) /* 0x406C5900 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM145      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[145]) /* 0x406C5910 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM146      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[146]) /* 0x406C5920 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM147      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[147]) /* 0x406C5930 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM148      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[148]) /* 0x406C5940 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM149      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[149]) /* 0x406C5950 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM150      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[150]) /* 0x406C5960 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM151      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[151]) /* 0x406C5970 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM152      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[152]) /* 0x406C5980 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM153      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[153]) /* 0x406C5990 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM154      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[154]) /* 0x406C59A0 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM155      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[155]) /* 0x406C59B0 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM156      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[156]) /* 0x406C59C0 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM157      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[157]) /* 0x406C59D0 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM158      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[158]) /* 0x406C59E0 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM159      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[159]) /* 0x406C59F0 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM160      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[160]) /* 0x406C5A00 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM161      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[161]) /* 0x406C5A10 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM162      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[162]) /* 0x406C5A20 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM163      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[163]) /* 0x406C5A30 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM164      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[164]) /* 0x406C5A40 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM165      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[165]) /* 0x406C5A50 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM166      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[166]) /* 0x406C5A60 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM167      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[167]) /* 0x406C5A70 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM168      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[168]) /* 0x406C5A80 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM169      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[169]) /* 0x406C5A90 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM170      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[170]) /* 0x406C5AA0 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM171      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[171]) /* 0x406C5AB0 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM172      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[172]) /* 0x406C5AC0 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM173      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[173]) /* 0x406C5AD0 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM174      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[174]) /* 0x406C5AE0 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM175      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[175]) /* 0x406C5AF0 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM176      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[176]) /* 0x406C5B00 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM177      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[177]) /* 0x406C5B10 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM178      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[178]) /* 0x406C5B20 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM179      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[179]) /* 0x406C5B30 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM180      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[180]) /* 0x406C5B40 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM181      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[181]) /* 0x406C5B50 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM182      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[182]) /* 0x406C5B60 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM183      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[183]) /* 0x406C5B70 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM184      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[184]) /* 0x406C5B80 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM185      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[185]) /* 0x406C5B90 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM186      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[186]) /* 0x406C5BA0 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM187      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[187]) /* 0x406C5BB0 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM188      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[188]) /* 0x406C5BC0 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM189      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[189]) /* 0x406C5BD0 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM190      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[190]) /* 0x406C5BE0 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM191      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[191]) /* 0x406C5BF0 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM192      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[192]) /* 0x406C5C00 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM193      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[193]) /* 0x406C5C10 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM194      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[194]) /* 0x406C5C20 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM195      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[195]) /* 0x406C5C30 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM196      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[196]) /* 0x406C5C40 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM197      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[197]) /* 0x406C5C50 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM198      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[198]) /* 0x406C5C60 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM199      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[199]) /* 0x406C5C70 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM200      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[200]) /* 0x406C5C80 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM201      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[201]) /* 0x406C5C90 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM202      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[202]) /* 0x406C5CA0 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM203      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[203]) /* 0x406C5CB0 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM204      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[204]) /* 0x406C5CC0 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM205      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[205]) /* 0x406C5CD0 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM206      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[206]) /* 0x406C5CE0 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM207      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[207]) /* 0x406C5CF0 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM208      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[208]) /* 0x406C5D00 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM209      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[209]) /* 0x406C5D10 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM210      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[210]) /* 0x406C5D20 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM211      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[211]) /* 0x406C5D30 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM212      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[212]) /* 0x406C5D40 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM213      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[213]) /* 0x406C5D50 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM214      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[214]) /* 0x406C5D60 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM215      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[215]) /* 0x406C5D70 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM216      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[216]) /* 0x406C5D80 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM217      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[217]) /* 0x406C5D90 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM218      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[218]) /* 0x406C5DA0 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM219      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[219]) /* 0x406C5DB0 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM220      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[220]) /* 0x406C5DC0 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM221      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[221]) /* 0x406C5DD0 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM222      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[222]) /* 0x406C5DE0 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM223      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[223]) /* 0x406C5DF0 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM224      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[224]) /* 0x406C5E00 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM225      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[225]) /* 0x406C5E10 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM226      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[226]) /* 0x406C5E20 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM227      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[227]) /* 0x406C5E30 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM228      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[228]) /* 0x406C5E40 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM229      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[229]) /* 0x406C5E50 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM230      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[230]) /* 0x406C5E60 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM231      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[231]) /* 0x406C5E70 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM232      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[232]) /* 0x406C5E80 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM233      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[233]) /* 0x406C5E90 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM234      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[234]) /* 0x406C5EA0 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM235      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[235]) /* 0x406C5EB0 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM236      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[236]) /* 0x406C5EC0 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM237      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[237]) /* 0x406C5ED0 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM238      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[238]) /* 0x406C5EE0 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM239      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[239]) /* 0x406C5EF0 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM240      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[240]) /* 0x406C5F00 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM241      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[241]) /* 0x406C5F10 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM242      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[242]) /* 0x406C5F20 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM243      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[243]) /* 0x406C5F30 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM244      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[244]) /* 0x406C5F40 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM245      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[245]) /* 0x406C5F50 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM246      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[246]) /* 0x406C5F60 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM247      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[247]) /* 0x406C5F70 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM248      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[248]) /* 0x406C5F80 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM249      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[249]) /* 0x406C5F90 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM250      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[250]) /* 0x406C5FA0 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM251      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[251]) /* 0x406C5FB0 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM252      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[252]) /* 0x406C5FC0 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM253      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[253]) /* 0x406C5FD0 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM254      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[254]) /* 0x406C5FE0 */
#define LVDSSS_LVDS_GPIF1_LEFT_WAVEFORM255      ((LVDSSS_LVDS_GPIF_LEFT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].LEFT.WAVEFORM[255]) /* 0x406C5FF0 */
#define LVDSSS_LVDS_GPIF0_RIGHT                 ((LVDSSS_LVDS_GPIF_RIGHT_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT)      /* 0x406C3000 */
#define LVDSSS_LVDS_GPIF1_RIGHT                 ((LVDSSS_LVDS_GPIF_RIGHT_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT)      /* 0x406C6000 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM0       ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[0]) /* 0x406C3000 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM1       ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[1]) /* 0x406C3010 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM2       ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[2]) /* 0x406C3020 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM3       ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[3]) /* 0x406C3030 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM4       ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[4]) /* 0x406C3040 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM5       ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[5]) /* 0x406C3050 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM6       ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[6]) /* 0x406C3060 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM7       ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[7]) /* 0x406C3070 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM8       ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[8]) /* 0x406C3080 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM9       ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[9]) /* 0x406C3090 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM10      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[10]) /* 0x406C30A0 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM11      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[11]) /* 0x406C30B0 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM12      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[12]) /* 0x406C30C0 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM13      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[13]) /* 0x406C30D0 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM14      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[14]) /* 0x406C30E0 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM15      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[15]) /* 0x406C30F0 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM16      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[16]) /* 0x406C3100 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM17      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[17]) /* 0x406C3110 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM18      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[18]) /* 0x406C3120 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM19      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[19]) /* 0x406C3130 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM20      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[20]) /* 0x406C3140 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM21      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[21]) /* 0x406C3150 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM22      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[22]) /* 0x406C3160 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM23      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[23]) /* 0x406C3170 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM24      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[24]) /* 0x406C3180 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM25      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[25]) /* 0x406C3190 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM26      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[26]) /* 0x406C31A0 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM27      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[27]) /* 0x406C31B0 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM28      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[28]) /* 0x406C31C0 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM29      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[29]) /* 0x406C31D0 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM30      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[30]) /* 0x406C31E0 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM31      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[31]) /* 0x406C31F0 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM32      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[32]) /* 0x406C3200 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM33      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[33]) /* 0x406C3210 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM34      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[34]) /* 0x406C3220 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM35      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[35]) /* 0x406C3230 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM36      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[36]) /* 0x406C3240 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM37      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[37]) /* 0x406C3250 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM38      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[38]) /* 0x406C3260 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM39      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[39]) /* 0x406C3270 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM40      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[40]) /* 0x406C3280 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM41      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[41]) /* 0x406C3290 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM42      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[42]) /* 0x406C32A0 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM43      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[43]) /* 0x406C32B0 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM44      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[44]) /* 0x406C32C0 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM45      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[45]) /* 0x406C32D0 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM46      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[46]) /* 0x406C32E0 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM47      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[47]) /* 0x406C32F0 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM48      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[48]) /* 0x406C3300 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM49      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[49]) /* 0x406C3310 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM50      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[50]) /* 0x406C3320 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM51      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[51]) /* 0x406C3330 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM52      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[52]) /* 0x406C3340 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM53      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[53]) /* 0x406C3350 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM54      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[54]) /* 0x406C3360 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM55      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[55]) /* 0x406C3370 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM56      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[56]) /* 0x406C3380 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM57      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[57]) /* 0x406C3390 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM58      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[58]) /* 0x406C33A0 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM59      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[59]) /* 0x406C33B0 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM60      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[60]) /* 0x406C33C0 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM61      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[61]) /* 0x406C33D0 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM62      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[62]) /* 0x406C33E0 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM63      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[63]) /* 0x406C33F0 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM64      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[64]) /* 0x406C3400 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM65      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[65]) /* 0x406C3410 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM66      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[66]) /* 0x406C3420 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM67      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[67]) /* 0x406C3430 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM68      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[68]) /* 0x406C3440 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM69      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[69]) /* 0x406C3450 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM70      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[70]) /* 0x406C3460 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM71      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[71]) /* 0x406C3470 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM72      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[72]) /* 0x406C3480 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM73      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[73]) /* 0x406C3490 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM74      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[74]) /* 0x406C34A0 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM75      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[75]) /* 0x406C34B0 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM76      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[76]) /* 0x406C34C0 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM77      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[77]) /* 0x406C34D0 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM78      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[78]) /* 0x406C34E0 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM79      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[79]) /* 0x406C34F0 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM80      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[80]) /* 0x406C3500 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM81      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[81]) /* 0x406C3510 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM82      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[82]) /* 0x406C3520 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM83      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[83]) /* 0x406C3530 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM84      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[84]) /* 0x406C3540 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM85      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[85]) /* 0x406C3550 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM86      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[86]) /* 0x406C3560 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM87      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[87]) /* 0x406C3570 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM88      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[88]) /* 0x406C3580 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM89      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[89]) /* 0x406C3590 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM90      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[90]) /* 0x406C35A0 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM91      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[91]) /* 0x406C35B0 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM92      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[92]) /* 0x406C35C0 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM93      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[93]) /* 0x406C35D0 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM94      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[94]) /* 0x406C35E0 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM95      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[95]) /* 0x406C35F0 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM96      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[96]) /* 0x406C3600 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM97      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[97]) /* 0x406C3610 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM98      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[98]) /* 0x406C3620 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM99      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[99]) /* 0x406C3630 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM100     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[100]) /* 0x406C3640 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM101     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[101]) /* 0x406C3650 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM102     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[102]) /* 0x406C3660 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM103     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[103]) /* 0x406C3670 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM104     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[104]) /* 0x406C3680 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM105     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[105]) /* 0x406C3690 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM106     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[106]) /* 0x406C36A0 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM107     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[107]) /* 0x406C36B0 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM108     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[108]) /* 0x406C36C0 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM109     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[109]) /* 0x406C36D0 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM110     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[110]) /* 0x406C36E0 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM111     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[111]) /* 0x406C36F0 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM112     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[112]) /* 0x406C3700 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM113     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[113]) /* 0x406C3710 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM114     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[114]) /* 0x406C3720 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM115     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[115]) /* 0x406C3730 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM116     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[116]) /* 0x406C3740 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM117     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[117]) /* 0x406C3750 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM118     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[118]) /* 0x406C3760 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM119     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[119]) /* 0x406C3770 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM120     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[120]) /* 0x406C3780 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM121     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[121]) /* 0x406C3790 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM122     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[122]) /* 0x406C37A0 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM123     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[123]) /* 0x406C37B0 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM124     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[124]) /* 0x406C37C0 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM125     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[125]) /* 0x406C37D0 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM126     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[126]) /* 0x406C37E0 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM127     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[127]) /* 0x406C37F0 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM128     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[128]) /* 0x406C3800 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM129     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[129]) /* 0x406C3810 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM130     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[130]) /* 0x406C3820 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM131     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[131]) /* 0x406C3830 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM132     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[132]) /* 0x406C3840 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM133     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[133]) /* 0x406C3850 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM134     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[134]) /* 0x406C3860 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM135     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[135]) /* 0x406C3870 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM136     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[136]) /* 0x406C3880 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM137     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[137]) /* 0x406C3890 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM138     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[138]) /* 0x406C38A0 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM139     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[139]) /* 0x406C38B0 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM140     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[140]) /* 0x406C38C0 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM141     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[141]) /* 0x406C38D0 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM142     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[142]) /* 0x406C38E0 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM143     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[143]) /* 0x406C38F0 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM144     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[144]) /* 0x406C3900 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM145     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[145]) /* 0x406C3910 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM146     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[146]) /* 0x406C3920 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM147     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[147]) /* 0x406C3930 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM148     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[148]) /* 0x406C3940 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM149     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[149]) /* 0x406C3950 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM150     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[150]) /* 0x406C3960 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM151     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[151]) /* 0x406C3970 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM152     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[152]) /* 0x406C3980 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM153     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[153]) /* 0x406C3990 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM154     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[154]) /* 0x406C39A0 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM155     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[155]) /* 0x406C39B0 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM156     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[156]) /* 0x406C39C0 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM157     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[157]) /* 0x406C39D0 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM158     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[158]) /* 0x406C39E0 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM159     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[159]) /* 0x406C39F0 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM160     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[160]) /* 0x406C3A00 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM161     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[161]) /* 0x406C3A10 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM162     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[162]) /* 0x406C3A20 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM163     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[163]) /* 0x406C3A30 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM164     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[164]) /* 0x406C3A40 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM165     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[165]) /* 0x406C3A50 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM166     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[166]) /* 0x406C3A60 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM167     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[167]) /* 0x406C3A70 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM168     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[168]) /* 0x406C3A80 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM169     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[169]) /* 0x406C3A90 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM170     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[170]) /* 0x406C3AA0 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM171     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[171]) /* 0x406C3AB0 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM172     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[172]) /* 0x406C3AC0 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM173     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[173]) /* 0x406C3AD0 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM174     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[174]) /* 0x406C3AE0 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM175     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[175]) /* 0x406C3AF0 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM176     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[176]) /* 0x406C3B00 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM177     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[177]) /* 0x406C3B10 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM178     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[178]) /* 0x406C3B20 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM179     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[179]) /* 0x406C3B30 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM180     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[180]) /* 0x406C3B40 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM181     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[181]) /* 0x406C3B50 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM182     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[182]) /* 0x406C3B60 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM183     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[183]) /* 0x406C3B70 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM184     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[184]) /* 0x406C3B80 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM185     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[185]) /* 0x406C3B90 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM186     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[186]) /* 0x406C3BA0 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM187     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[187]) /* 0x406C3BB0 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM188     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[188]) /* 0x406C3BC0 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM189     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[189]) /* 0x406C3BD0 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM190     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[190]) /* 0x406C3BE0 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM191     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[191]) /* 0x406C3BF0 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM192     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[192]) /* 0x406C3C00 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM193     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[193]) /* 0x406C3C10 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM194     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[194]) /* 0x406C3C20 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM195     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[195]) /* 0x406C3C30 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM196     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[196]) /* 0x406C3C40 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM197     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[197]) /* 0x406C3C50 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM198     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[198]) /* 0x406C3C60 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM199     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[199]) /* 0x406C3C70 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM200     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[200]) /* 0x406C3C80 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM201     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[201]) /* 0x406C3C90 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM202     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[202]) /* 0x406C3CA0 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM203     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[203]) /* 0x406C3CB0 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM204     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[204]) /* 0x406C3CC0 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM205     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[205]) /* 0x406C3CD0 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM206     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[206]) /* 0x406C3CE0 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM207     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[207]) /* 0x406C3CF0 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM208     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[208]) /* 0x406C3D00 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM209     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[209]) /* 0x406C3D10 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM210     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[210]) /* 0x406C3D20 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM211     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[211]) /* 0x406C3D30 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM212     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[212]) /* 0x406C3D40 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM213     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[213]) /* 0x406C3D50 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM214     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[214]) /* 0x406C3D60 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM215     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[215]) /* 0x406C3D70 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM216     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[216]) /* 0x406C3D80 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM217     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[217]) /* 0x406C3D90 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM218     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[218]) /* 0x406C3DA0 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM219     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[219]) /* 0x406C3DB0 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM220     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[220]) /* 0x406C3DC0 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM221     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[221]) /* 0x406C3DD0 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM222     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[222]) /* 0x406C3DE0 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM223     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[223]) /* 0x406C3DF0 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM224     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[224]) /* 0x406C3E00 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM225     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[225]) /* 0x406C3E10 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM226     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[226]) /* 0x406C3E20 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM227     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[227]) /* 0x406C3E30 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM228     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[228]) /* 0x406C3E40 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM229     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[229]) /* 0x406C3E50 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM230     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[230]) /* 0x406C3E60 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM231     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[231]) /* 0x406C3E70 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM232     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[232]) /* 0x406C3E80 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM233     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[233]) /* 0x406C3E90 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM234     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[234]) /* 0x406C3EA0 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM235     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[235]) /* 0x406C3EB0 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM236     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[236]) /* 0x406C3EC0 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM237     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[237]) /* 0x406C3ED0 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM238     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[238]) /* 0x406C3EE0 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM239     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[239]) /* 0x406C3EF0 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM240     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[240]) /* 0x406C3F00 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM241     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[241]) /* 0x406C3F10 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM242     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[242]) /* 0x406C3F20 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM243     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[243]) /* 0x406C3F30 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM244     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[244]) /* 0x406C3F40 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM245     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[245]) /* 0x406C3F50 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM246     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[246]) /* 0x406C3F60 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM247     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[247]) /* 0x406C3F70 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM248     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[248]) /* 0x406C3F80 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM249     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[249]) /* 0x406C3F90 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM250     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[250]) /* 0x406C3FA0 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM251     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[251]) /* 0x406C3FB0 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM252     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[252]) /* 0x406C3FC0 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM253     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[253]) /* 0x406C3FD0 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM254     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[254]) /* 0x406C3FE0 */
#define LVDSSS_LVDS_GPIF0_RIGHT_WAVEFORM255     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[0].RIGHT.WAVEFORM[255]) /* 0x406C3FF0 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM0       ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[0]) /* 0x406C6000 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM1       ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[1]) /* 0x406C6010 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM2       ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[2]) /* 0x406C6020 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM3       ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[3]) /* 0x406C6030 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM4       ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[4]) /* 0x406C6040 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM5       ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[5]) /* 0x406C6050 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM6       ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[6]) /* 0x406C6060 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM7       ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[7]) /* 0x406C6070 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM8       ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[8]) /* 0x406C6080 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM9       ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[9]) /* 0x406C6090 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM10      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[10]) /* 0x406C60A0 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM11      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[11]) /* 0x406C60B0 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM12      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[12]) /* 0x406C60C0 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM13      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[13]) /* 0x406C60D0 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM14      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[14]) /* 0x406C60E0 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM15      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[15]) /* 0x406C60F0 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM16      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[16]) /* 0x406C6100 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM17      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[17]) /* 0x406C6110 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM18      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[18]) /* 0x406C6120 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM19      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[19]) /* 0x406C6130 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM20      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[20]) /* 0x406C6140 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM21      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[21]) /* 0x406C6150 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM22      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[22]) /* 0x406C6160 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM23      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[23]) /* 0x406C6170 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM24      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[24]) /* 0x406C6180 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM25      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[25]) /* 0x406C6190 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM26      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[26]) /* 0x406C61A0 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM27      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[27]) /* 0x406C61B0 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM28      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[28]) /* 0x406C61C0 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM29      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[29]) /* 0x406C61D0 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM30      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[30]) /* 0x406C61E0 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM31      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[31]) /* 0x406C61F0 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM32      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[32]) /* 0x406C6200 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM33      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[33]) /* 0x406C6210 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM34      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[34]) /* 0x406C6220 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM35      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[35]) /* 0x406C6230 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM36      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[36]) /* 0x406C6240 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM37      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[37]) /* 0x406C6250 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM38      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[38]) /* 0x406C6260 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM39      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[39]) /* 0x406C6270 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM40      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[40]) /* 0x406C6280 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM41      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[41]) /* 0x406C6290 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM42      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[42]) /* 0x406C62A0 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM43      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[43]) /* 0x406C62B0 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM44      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[44]) /* 0x406C62C0 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM45      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[45]) /* 0x406C62D0 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM46      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[46]) /* 0x406C62E0 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM47      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[47]) /* 0x406C62F0 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM48      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[48]) /* 0x406C6300 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM49      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[49]) /* 0x406C6310 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM50      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[50]) /* 0x406C6320 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM51      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[51]) /* 0x406C6330 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM52      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[52]) /* 0x406C6340 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM53      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[53]) /* 0x406C6350 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM54      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[54]) /* 0x406C6360 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM55      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[55]) /* 0x406C6370 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM56      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[56]) /* 0x406C6380 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM57      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[57]) /* 0x406C6390 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM58      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[58]) /* 0x406C63A0 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM59      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[59]) /* 0x406C63B0 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM60      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[60]) /* 0x406C63C0 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM61      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[61]) /* 0x406C63D0 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM62      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[62]) /* 0x406C63E0 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM63      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[63]) /* 0x406C63F0 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM64      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[64]) /* 0x406C6400 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM65      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[65]) /* 0x406C6410 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM66      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[66]) /* 0x406C6420 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM67      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[67]) /* 0x406C6430 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM68      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[68]) /* 0x406C6440 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM69      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[69]) /* 0x406C6450 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM70      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[70]) /* 0x406C6460 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM71      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[71]) /* 0x406C6470 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM72      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[72]) /* 0x406C6480 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM73      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[73]) /* 0x406C6490 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM74      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[74]) /* 0x406C64A0 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM75      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[75]) /* 0x406C64B0 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM76      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[76]) /* 0x406C64C0 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM77      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[77]) /* 0x406C64D0 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM78      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[78]) /* 0x406C64E0 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM79      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[79]) /* 0x406C64F0 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM80      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[80]) /* 0x406C6500 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM81      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[81]) /* 0x406C6510 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM82      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[82]) /* 0x406C6520 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM83      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[83]) /* 0x406C6530 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM84      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[84]) /* 0x406C6540 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM85      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[85]) /* 0x406C6550 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM86      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[86]) /* 0x406C6560 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM87      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[87]) /* 0x406C6570 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM88      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[88]) /* 0x406C6580 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM89      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[89]) /* 0x406C6590 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM90      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[90]) /* 0x406C65A0 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM91      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[91]) /* 0x406C65B0 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM92      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[92]) /* 0x406C65C0 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM93      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[93]) /* 0x406C65D0 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM94      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[94]) /* 0x406C65E0 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM95      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[95]) /* 0x406C65F0 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM96      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[96]) /* 0x406C6600 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM97      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[97]) /* 0x406C6610 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM98      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[98]) /* 0x406C6620 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM99      ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[99]) /* 0x406C6630 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM100     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[100]) /* 0x406C6640 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM101     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[101]) /* 0x406C6650 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM102     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[102]) /* 0x406C6660 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM103     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[103]) /* 0x406C6670 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM104     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[104]) /* 0x406C6680 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM105     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[105]) /* 0x406C6690 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM106     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[106]) /* 0x406C66A0 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM107     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[107]) /* 0x406C66B0 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM108     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[108]) /* 0x406C66C0 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM109     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[109]) /* 0x406C66D0 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM110     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[110]) /* 0x406C66E0 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM111     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[111]) /* 0x406C66F0 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM112     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[112]) /* 0x406C6700 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM113     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[113]) /* 0x406C6710 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM114     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[114]) /* 0x406C6720 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM115     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[115]) /* 0x406C6730 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM116     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[116]) /* 0x406C6740 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM117     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[117]) /* 0x406C6750 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM118     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[118]) /* 0x406C6760 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM119     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[119]) /* 0x406C6770 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM120     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[120]) /* 0x406C6780 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM121     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[121]) /* 0x406C6790 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM122     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[122]) /* 0x406C67A0 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM123     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[123]) /* 0x406C67B0 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM124     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[124]) /* 0x406C67C0 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM125     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[125]) /* 0x406C67D0 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM126     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[126]) /* 0x406C67E0 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM127     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[127]) /* 0x406C67F0 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM128     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[128]) /* 0x406C6800 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM129     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[129]) /* 0x406C6810 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM130     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[130]) /* 0x406C6820 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM131     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[131]) /* 0x406C6830 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM132     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[132]) /* 0x406C6840 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM133     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[133]) /* 0x406C6850 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM134     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[134]) /* 0x406C6860 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM135     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[135]) /* 0x406C6870 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM136     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[136]) /* 0x406C6880 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM137     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[137]) /* 0x406C6890 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM138     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[138]) /* 0x406C68A0 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM139     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[139]) /* 0x406C68B0 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM140     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[140]) /* 0x406C68C0 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM141     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[141]) /* 0x406C68D0 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM142     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[142]) /* 0x406C68E0 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM143     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[143]) /* 0x406C68F0 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM144     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[144]) /* 0x406C6900 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM145     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[145]) /* 0x406C6910 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM146     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[146]) /* 0x406C6920 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM147     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[147]) /* 0x406C6930 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM148     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[148]) /* 0x406C6940 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM149     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[149]) /* 0x406C6950 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM150     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[150]) /* 0x406C6960 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM151     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[151]) /* 0x406C6970 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM152     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[152]) /* 0x406C6980 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM153     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[153]) /* 0x406C6990 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM154     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[154]) /* 0x406C69A0 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM155     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[155]) /* 0x406C69B0 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM156     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[156]) /* 0x406C69C0 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM157     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[157]) /* 0x406C69D0 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM158     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[158]) /* 0x406C69E0 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM159     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[159]) /* 0x406C69F0 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM160     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[160]) /* 0x406C6A00 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM161     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[161]) /* 0x406C6A10 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM162     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[162]) /* 0x406C6A20 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM163     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[163]) /* 0x406C6A30 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM164     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[164]) /* 0x406C6A40 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM165     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[165]) /* 0x406C6A50 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM166     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[166]) /* 0x406C6A60 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM167     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[167]) /* 0x406C6A70 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM168     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[168]) /* 0x406C6A80 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM169     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[169]) /* 0x406C6A90 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM170     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[170]) /* 0x406C6AA0 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM171     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[171]) /* 0x406C6AB0 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM172     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[172]) /* 0x406C6AC0 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM173     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[173]) /* 0x406C6AD0 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM174     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[174]) /* 0x406C6AE0 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM175     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[175]) /* 0x406C6AF0 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM176     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[176]) /* 0x406C6B00 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM177     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[177]) /* 0x406C6B10 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM178     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[178]) /* 0x406C6B20 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM179     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[179]) /* 0x406C6B30 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM180     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[180]) /* 0x406C6B40 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM181     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[181]) /* 0x406C6B50 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM182     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[182]) /* 0x406C6B60 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM183     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[183]) /* 0x406C6B70 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM184     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[184]) /* 0x406C6B80 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM185     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[185]) /* 0x406C6B90 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM186     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[186]) /* 0x406C6BA0 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM187     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[187]) /* 0x406C6BB0 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM188     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[188]) /* 0x406C6BC0 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM189     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[189]) /* 0x406C6BD0 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM190     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[190]) /* 0x406C6BE0 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM191     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[191]) /* 0x406C6BF0 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM192     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[192]) /* 0x406C6C00 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM193     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[193]) /* 0x406C6C10 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM194     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[194]) /* 0x406C6C20 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM195     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[195]) /* 0x406C6C30 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM196     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[196]) /* 0x406C6C40 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM197     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[197]) /* 0x406C6C50 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM198     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[198]) /* 0x406C6C60 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM199     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[199]) /* 0x406C6C70 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM200     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[200]) /* 0x406C6C80 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM201     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[201]) /* 0x406C6C90 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM202     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[202]) /* 0x406C6CA0 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM203     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[203]) /* 0x406C6CB0 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM204     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[204]) /* 0x406C6CC0 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM205     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[205]) /* 0x406C6CD0 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM206     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[206]) /* 0x406C6CE0 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM207     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[207]) /* 0x406C6CF0 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM208     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[208]) /* 0x406C6D00 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM209     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[209]) /* 0x406C6D10 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM210     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[210]) /* 0x406C6D20 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM211     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[211]) /* 0x406C6D30 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM212     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[212]) /* 0x406C6D40 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM213     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[213]) /* 0x406C6D50 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM214     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[214]) /* 0x406C6D60 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM215     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[215]) /* 0x406C6D70 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM216     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[216]) /* 0x406C6D80 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM217     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[217]) /* 0x406C6D90 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM218     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[218]) /* 0x406C6DA0 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM219     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[219]) /* 0x406C6DB0 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM220     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[220]) /* 0x406C6DC0 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM221     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[221]) /* 0x406C6DD0 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM222     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[222]) /* 0x406C6DE0 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM223     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[223]) /* 0x406C6DF0 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM224     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[224]) /* 0x406C6E00 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM225     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[225]) /* 0x406C6E10 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM226     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[226]) /* 0x406C6E20 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM227     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[227]) /* 0x406C6E30 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM228     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[228]) /* 0x406C6E40 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM229     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[229]) /* 0x406C6E50 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM230     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[230]) /* 0x406C6E60 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM231     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[231]) /* 0x406C6E70 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM232     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[232]) /* 0x406C6E80 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM233     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[233]) /* 0x406C6E90 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM234     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[234]) /* 0x406C6EA0 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM235     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[235]) /* 0x406C6EB0 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM236     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[236]) /* 0x406C6EC0 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM237     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[237]) /* 0x406C6ED0 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM238     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[238]) /* 0x406C6EE0 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM239     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[239]) /* 0x406C6EF0 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM240     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[240]) /* 0x406C6F00 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM241     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[241]) /* 0x406C6F10 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM242     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[242]) /* 0x406C6F20 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM243     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[243]) /* 0x406C6F30 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM244     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[244]) /* 0x406C6F40 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM245     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[245]) /* 0x406C6F50 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM246     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[246]) /* 0x406C6F60 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM247     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[247]) /* 0x406C6F70 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM248     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[248]) /* 0x406C6F80 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM249     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[249]) /* 0x406C6F90 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM250     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[250]) /* 0x406C6FA0 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM251     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[251]) /* 0x406C6FB0 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM252     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[252]) /* 0x406C6FC0 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM253     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[253]) /* 0x406C6FD0 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM254     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[254]) /* 0x406C6FE0 */
#define LVDSSS_LVDS_GPIF1_RIGHT_WAVEFORM255     ((LVDSSS_LVDS_GPIF_RIGHT_WAVEFORM_Type*) &LVDSSS->LVDS.GPIF[1].RIGHT.WAVEFORM[255]) /* 0x406C6FF0 */
#define LVDSSS_LVDS_AFE0                        ((LVDSSS_LVDS_AFE_Type*) &LVDSSS->LVDS.AFE[0])                    /* 0x406C7000 */
#define LVDSSS_LVDS_AFE1                        ((LVDSSS_LVDS_AFE_Type*) &LVDSSS->LVDS.AFE[1])                    /* 0x406C7800 */
#define LVDSSS_LVDS_ADAPTER_DMA0                ((LVDSSS_LVDS_ADAPTER_DMA_Type*) &LVDSSS->LVDS.ADAPTER_DMA[0])    /* 0x406D0000 */
#define LVDSSS_LVDS_ADAPTER_DMA1                ((LVDSSS_LVDS_ADAPTER_DMA_Type*) &LVDSSS->LVDS.ADAPTER_DMA[1])    /* 0x406E0000 */
#define LVDSSS_LVDS_ADAPTER_DMA0_SCK0           ((LVDSSS_LVDS_ADAPTER_DMA_SCK_Type*) &LVDSSS->LVDS.ADAPTER_DMA[0].SCK[0]) /* 0x406D8000 */
#define LVDSSS_LVDS_ADAPTER_DMA0_SCK1           ((LVDSSS_LVDS_ADAPTER_DMA_SCK_Type*) &LVDSSS->LVDS.ADAPTER_DMA[0].SCK[1]) /* 0x406D8080 */
#define LVDSSS_LVDS_ADAPTER_DMA0_SCK2           ((LVDSSS_LVDS_ADAPTER_DMA_SCK_Type*) &LVDSSS->LVDS.ADAPTER_DMA[0].SCK[2]) /* 0x406D8100 */
#define LVDSSS_LVDS_ADAPTER_DMA0_SCK3           ((LVDSSS_LVDS_ADAPTER_DMA_SCK_Type*) &LVDSSS->LVDS.ADAPTER_DMA[0].SCK[3]) /* 0x406D8180 */
#define LVDSSS_LVDS_ADAPTER_DMA0_SCK4           ((LVDSSS_LVDS_ADAPTER_DMA_SCK_Type*) &LVDSSS->LVDS.ADAPTER_DMA[0].SCK[4]) /* 0x406D8200 */
#define LVDSSS_LVDS_ADAPTER_DMA0_SCK5           ((LVDSSS_LVDS_ADAPTER_DMA_SCK_Type*) &LVDSSS->LVDS.ADAPTER_DMA[0].SCK[5]) /* 0x406D8280 */
#define LVDSSS_LVDS_ADAPTER_DMA0_SCK6           ((LVDSSS_LVDS_ADAPTER_DMA_SCK_Type*) &LVDSSS->LVDS.ADAPTER_DMA[0].SCK[6]) /* 0x406D8300 */
#define LVDSSS_LVDS_ADAPTER_DMA0_SCK7           ((LVDSSS_LVDS_ADAPTER_DMA_SCK_Type*) &LVDSSS->LVDS.ADAPTER_DMA[0].SCK[7]) /* 0x406D8380 */
#define LVDSSS_LVDS_ADAPTER_DMA0_SCK8           ((LVDSSS_LVDS_ADAPTER_DMA_SCK_Type*) &LVDSSS->LVDS.ADAPTER_DMA[0].SCK[8]) /* 0x406D8400 */
#define LVDSSS_LVDS_ADAPTER_DMA0_SCK9           ((LVDSSS_LVDS_ADAPTER_DMA_SCK_Type*) &LVDSSS->LVDS.ADAPTER_DMA[0].SCK[9]) /* 0x406D8480 */
#define LVDSSS_LVDS_ADAPTER_DMA0_SCK10          ((LVDSSS_LVDS_ADAPTER_DMA_SCK_Type*) &LVDSSS->LVDS.ADAPTER_DMA[0].SCK[10]) /* 0x406D8500 */
#define LVDSSS_LVDS_ADAPTER_DMA0_SCK11          ((LVDSSS_LVDS_ADAPTER_DMA_SCK_Type*) &LVDSSS->LVDS.ADAPTER_DMA[0].SCK[11]) /* 0x406D8580 */
#define LVDSSS_LVDS_ADAPTER_DMA0_SCK12          ((LVDSSS_LVDS_ADAPTER_DMA_SCK_Type*) &LVDSSS->LVDS.ADAPTER_DMA[0].SCK[12]) /* 0x406D8600 */
#define LVDSSS_LVDS_ADAPTER_DMA0_SCK13          ((LVDSSS_LVDS_ADAPTER_DMA_SCK_Type*) &LVDSSS->LVDS.ADAPTER_DMA[0].SCK[13]) /* 0x406D8680 */
#define LVDSSS_LVDS_ADAPTER_DMA0_SCK14          ((LVDSSS_LVDS_ADAPTER_DMA_SCK_Type*) &LVDSSS->LVDS.ADAPTER_DMA[0].SCK[14]) /* 0x406D8700 */
#define LVDSSS_LVDS_ADAPTER_DMA0_SCK15          ((LVDSSS_LVDS_ADAPTER_DMA_SCK_Type*) &LVDSSS->LVDS.ADAPTER_DMA[0].SCK[15]) /* 0x406D8780 */
#define LVDSSS_LVDS_ADAPTER_DMA1_SCK0           ((LVDSSS_LVDS_ADAPTER_DMA_SCK_Type*) &LVDSSS->LVDS.ADAPTER_DMA[1].SCK[0]) /* 0x406E8000 */
#define LVDSSS_LVDS_ADAPTER_DMA1_SCK1           ((LVDSSS_LVDS_ADAPTER_DMA_SCK_Type*) &LVDSSS->LVDS.ADAPTER_DMA[1].SCK[1]) /* 0x406E8080 */
#define LVDSSS_LVDS_ADAPTER_DMA1_SCK2           ((LVDSSS_LVDS_ADAPTER_DMA_SCK_Type*) &LVDSSS->LVDS.ADAPTER_DMA[1].SCK[2]) /* 0x406E8100 */
#define LVDSSS_LVDS_ADAPTER_DMA1_SCK3           ((LVDSSS_LVDS_ADAPTER_DMA_SCK_Type*) &LVDSSS->LVDS.ADAPTER_DMA[1].SCK[3]) /* 0x406E8180 */
#define LVDSSS_LVDS_ADAPTER_DMA1_SCK4           ((LVDSSS_LVDS_ADAPTER_DMA_SCK_Type*) &LVDSSS->LVDS.ADAPTER_DMA[1].SCK[4]) /* 0x406E8200 */
#define LVDSSS_LVDS_ADAPTER_DMA1_SCK5           ((LVDSSS_LVDS_ADAPTER_DMA_SCK_Type*) &LVDSSS->LVDS.ADAPTER_DMA[1].SCK[5]) /* 0x406E8280 */
#define LVDSSS_LVDS_ADAPTER_DMA1_SCK6           ((LVDSSS_LVDS_ADAPTER_DMA_SCK_Type*) &LVDSSS->LVDS.ADAPTER_DMA[1].SCK[6]) /* 0x406E8300 */
#define LVDSSS_LVDS_ADAPTER_DMA1_SCK7           ((LVDSSS_LVDS_ADAPTER_DMA_SCK_Type*) &LVDSSS->LVDS.ADAPTER_DMA[1].SCK[7]) /* 0x406E8380 */
#define LVDSSS_LVDS_ADAPTER_DMA1_SCK8           ((LVDSSS_LVDS_ADAPTER_DMA_SCK_Type*) &LVDSSS->LVDS.ADAPTER_DMA[1].SCK[8]) /* 0x406E8400 */
#define LVDSSS_LVDS_ADAPTER_DMA1_SCK9           ((LVDSSS_LVDS_ADAPTER_DMA_SCK_Type*) &LVDSSS->LVDS.ADAPTER_DMA[1].SCK[9]) /* 0x406E8480 */
#define LVDSSS_LVDS_ADAPTER_DMA1_SCK10          ((LVDSSS_LVDS_ADAPTER_DMA_SCK_Type*) &LVDSSS->LVDS.ADAPTER_DMA[1].SCK[10]) /* 0x406E8500 */
#define LVDSSS_LVDS_ADAPTER_DMA1_SCK11          ((LVDSSS_LVDS_ADAPTER_DMA_SCK_Type*) &LVDSSS->LVDS.ADAPTER_DMA[1].SCK[11]) /* 0x406E8580 */
#define LVDSSS_LVDS_ADAPTER_DMA1_SCK12          ((LVDSSS_LVDS_ADAPTER_DMA_SCK_Type*) &LVDSSS->LVDS.ADAPTER_DMA[1].SCK[12]) /* 0x406E8600 */
#define LVDSSS_LVDS_ADAPTER_DMA1_SCK13          ((LVDSSS_LVDS_ADAPTER_DMA_SCK_Type*) &LVDSSS->LVDS.ADAPTER_DMA[1].SCK[13]) /* 0x406E8680 */
#define LVDSSS_LVDS_ADAPTER_DMA1_SCK14          ((LVDSSS_LVDS_ADAPTER_DMA_SCK_Type*) &LVDSSS->LVDS.ADAPTER_DMA[1].SCK[14]) /* 0x406E8700 */
#define LVDSSS_LVDS_ADAPTER_DMA1_SCK15          ((LVDSSS_LVDS_ADAPTER_DMA_SCK_Type*) &LVDSSS->LVDS.ADAPTER_DMA[1].SCK[15]) /* 0x406E8780 */
#define LVDSSS_LVDS_ADAPTER_DMA0_SCK_GBL        ((LVDSSS_LVDS_ADAPTER_DMA_SCK_GBL_Type*) &LVDSSS->LVDS.ADAPTER_DMA[0].SCK_GBL) /* 0x406DFF00 */
#define LVDSSS_LVDS_ADAPTER_DMA1_SCK_GBL        ((LVDSSS_LVDS_ADAPTER_DMA_SCK_GBL_Type*) &LVDSSS->LVDS.ADAPTER_DMA[1].SCK_GBL) /* 0x406EFF00 */

/** \} CYUSB4012-FCAXI */

#endif /* _CYUSB4012_FCAXI_H_ */


/* [] END OF FILE */
