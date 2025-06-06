/***************************************************************************//**
* \file psc3p5fds2abq1.h
*
* \brief
* PSC3P5FDS2ABQ1 device header
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

#ifndef _PSC3P5FDS2ABQ1_H_
#define _PSC3P5FDS2ABQ1_H_

/**
* \addtogroup group_device PSC3P5FDS2ABQ1
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
  /* ARM Cortex-M33 Core Interrupt Numbers */
  Reset_IRQn                        = -15,      /*!< -15 Reset Vector, invoked on Power up and warm reset */
  NonMaskableInt_IRQn               = -14,      /*!< -14 Non maskable Interrupt, cannot be stopped or preempted */
  HardFault_IRQn                    = -13,      /*!< -13 Hard Fault, all classes of Fault */
  MemoryManagement_IRQn             = -12,      /*!< -12 Memory Management, MPU mismatch, including Access Violation and No Match */
  BusFault_IRQn                     = -11,      /*!< -11 Bus Fault, Pre-Fetch-, Memory Access Fault, other address/memory related Fault */
  UsageFault_IRQn                   = -10,      /*!< -10 Usage Fault, i.e. Undef Instruction, Illegal State Transition */
  SecureFault_IRQn                  =  -9,      /*!<  -9 Secure Fault Interrupt */
  SVCall_IRQn                       =  -5,      /*!<  -5 System Service Call via SVC instruction */
  DebugMonitor_IRQn                 =  -4,      /*!<  -4 Debug Monitor */
  PendSV_IRQn                       =  -2,      /*!<  -2 Pendable request for system service */
  SysTick_IRQn                      =  -1,      /*!<  -1 System Tick Timer */
  /* PSC3P5FDS2ABQ1 Peripheral Interrupt Numbers */
  ioss_interrupts_gpio_0_IRQn       =   0,      /*!<   0 [DeepSleep] GPIO Port Interrupt #0 */
  ioss_interrupts_gpio_1_IRQn       =   1,      /*!<   1 [DeepSleep] GPIO Port Interrupt #1 */
  ioss_interrupts_gpio_2_IRQn       =   2,      /*!<   2 [DeepSleep] GPIO Port Interrupt #2 */
  ioss_interrupts_gpio_3_IRQn       =   3,      /*!<   3 [DeepSleep] GPIO Port Interrupt #3 */
  ioss_interrupts_gpio_4_IRQn       =   4,      /*!<   4 [DeepSleep] GPIO Port Interrupt #4 */
  ioss_interrupts_gpio_5_IRQn       =   5,      /*!<   5 [DeepSleep] GPIO Port Interrupt #5 */
  ioss_interrupts_gpio_6_IRQn       =   6,      /*!<   6 [DeepSleep] GPIO Port Interrupt #6 */
  ioss_interrupts_gpio_7_IRQn       =   7,      /*!<   7 [DeepSleep] GPIO Port Interrupt #7 */
  ioss_interrupts_gpio_8_IRQn       =   8,      /*!<   8 [DeepSleep] GPIO Port Interrupt #8 */
  ioss_interrupts_gpio_9_IRQn       =   9,      /*!<   9 [DeepSleep] GPIO Port Interrupt #9 */
  ioss_interrupts_sec_gpio_0_IRQn   =  10,      /*!<  10 [DeepSleep] GPIO Port Secure Interrupt #0 */
  ioss_interrupts_sec_gpio_1_IRQn   =  11,      /*!<  11 [DeepSleep] GPIO Port Secure Interrupt #1 */
  ioss_interrupts_sec_gpio_2_IRQn   =  12,      /*!<  12 [DeepSleep] GPIO Port Secure Interrupt #2 */
  ioss_interrupts_sec_gpio_3_IRQn   =  13,      /*!<  13 [DeepSleep] GPIO Port Secure Interrupt #3 */
  ioss_interrupts_sec_gpio_4_IRQn   =  14,      /*!<  14 [DeepSleep] GPIO Port Secure Interrupt #4 */
  ioss_interrupts_sec_gpio_5_IRQn   =  15,      /*!<  15 [DeepSleep] GPIO Port Secure Interrupt #5 */
  ioss_interrupts_sec_gpio_6_IRQn   =  16,      /*!<  16 [DeepSleep] GPIO Port Secure Interrupt #6 */
  ioss_interrupts_sec_gpio_7_IRQn   =  17,      /*!<  17 [DeepSleep] GPIO Port Secure Interrupt #7 */
  ioss_interrupts_sec_gpio_8_IRQn   =  18,      /*!<  18 [DeepSleep] GPIO Port Secure Interrupt #8 */
  ioss_interrupts_sec_gpio_9_IRQn   =  19,      /*!<  19 [DeepSleep] GPIO Port Secure Interrupt #9 */
  ioss_interrupt_vdd_IRQn           =  20,      /*!<  20 [DeepSleep] GPIO Supply Detect Interrupt */
  ioss_interrupt_gpio_IRQn          =  21,      /*!<  21 [DeepSleep] GPIO All Ports - Interrupts */
  ioss_interrupt_sec_gpio_IRQn      =  22,      /*!<  22 [DeepSleep] GPIO All Ports  - Secure  Interrupts */
  scb_0_interrupt_IRQn              =  23,      /*!<  23 [DeepSleep] Serial Communication Block #0 (DeepSleep capable) */
  srss_interrupt_mcwdt_0_IRQn       =  24,      /*!<  24 [DeepSleep] Multi Counter Watchdog Timer interrupt */
  srss_interrupt_backup_IRQn        =  25,      /*!<  25 [DeepSleep] Backup domain interrupt */
  cpuss_interrupts_ipc_dpslp_0_IRQn =  26,      /*!<  26 [DeepSleep] cpuss Inter Process Communication Interrupt #0 */
  cpuss_interrupts_ipc_dpslp_1_IRQn =  27,      /*!<  27 [DeepSleep] cpuss Inter Process Communication Interrupt #1 */
  srss_interrupt_wdt_IRQn           =  28,      /*!<  28 [DeepSleep] Interrupt from WDT */
  lpcomp_interrupt_IRQn             =  29,      /*!<  29 [DeepSleep] LPCOMP */
  srss_interrupt_IRQn               =  30,      /*!<  30 [Active] Other combined Interrupts for srss (LVD and CLKCAL, CLKCAL only supported in Active mode) */
  scb_1_interrupt_IRQn              =  31,      /*!<  31 [Active] Serial Communication Block #1 */
  scb_2_interrupt_IRQn              =  32,      /*!<  32 [Active] Serial Communication Block #2 */
  scb_3_interrupt_IRQn              =  33,      /*!<  33 [Active] Serial Communication Block #3 */
  scb_4_interrupt_IRQn              =  34,      /*!<  34 [Active] Serial Communication Block #4 */
  scb_5_interrupt_IRQn              =  35,      /*!<  35 [Active] Serial Communication Block #5 */
  cpuss_interrupt_fm_cbus_IRQn      =  36,      /*!<  36 [Active] FLASH Macro interrupt */
  cpuss_interrupts_dw0_0_IRQn       =  37,      /*!<  37 [Active] cpuss DataWire #0, Channel #0 */
  cpuss_interrupts_dw0_1_IRQn       =  38,      /*!<  38 [Active] cpuss DataWire #0, Channel #1 */
  cpuss_interrupts_dw0_2_IRQn       =  39,      /*!<  39 [Active] cpuss DataWire #0, Channel #2 */
  cpuss_interrupts_dw0_3_IRQn       =  40,      /*!<  40 [Active] cpuss DataWire #0, Channel #3 */
  cpuss_interrupts_dw0_4_IRQn       =  41,      /*!<  41 [Active] cpuss DataWire #0, Channel #4 */
  cpuss_interrupts_dw0_5_IRQn       =  42,      /*!<  42 [Active] cpuss DataWire #0, Channel #5 */
  cpuss_interrupts_dw0_6_IRQn       =  43,      /*!<  43 [Active] cpuss DataWire #0, Channel #6 */
  cpuss_interrupts_dw0_7_IRQn       =  44,      /*!<  44 [Active] cpuss DataWire #0, Channel #7 */
  cpuss_interrupts_dw0_8_IRQn       =  45,      /*!<  45 [Active] cpuss DataWire #0, Channel #8 */
  cpuss_interrupts_dw0_9_IRQn       =  46,      /*!<  46 [Active] cpuss DataWire #0, Channel #9 */
  cpuss_interrupts_dw0_10_IRQn      =  47,      /*!<  47 [Active] cpuss DataWire #0, Channel #10 */
  cpuss_interrupts_dw0_11_IRQn      =  48,      /*!<  48 [Active] cpuss DataWire #0, Channel #11 */
  cpuss_interrupts_dw0_12_IRQn      =  49,      /*!<  49 [Active] cpuss DataWire #0, Channel #12 */
  cpuss_interrupts_dw0_13_IRQn      =  50,      /*!<  50 [Active] cpuss DataWire #0, Channel #13 */
  cpuss_interrupts_dw0_14_IRQn      =  51,      /*!<  51 [Active] cpuss DataWire #0, Channel #14 */
  cpuss_interrupts_dw0_15_IRQn      =  52,      /*!<  52 [Active] cpuss DataWire #0, Channel #15 */
  cpuss_interrupts_dw1_0_IRQn       =  53,      /*!<  53 [Active] cpuss DataWire #1, Channel #0 */
  cpuss_interrupts_dw1_1_IRQn       =  54,      /*!<  54 [Active] cpuss DataWire #1, Channel #1 */
  cpuss_interrupts_dw1_2_IRQn       =  55,      /*!<  55 [Active] cpuss DataWire #1, Channel #2 */
  cpuss_interrupts_dw1_3_IRQn       =  56,      /*!<  56 [Active] cpuss DataWire #1, Channel #3 */
  cpuss_interrupts_dw1_4_IRQn       =  57,      /*!<  57 [Active] cpuss DataWire #1, Channel #4 */
  cpuss_interrupts_dw1_5_IRQn       =  58,      /*!<  58 [Active] cpuss DataWire #1, Channel #5 */
  cpuss_interrupts_dw1_6_IRQn       =  59,      /*!<  59 [Active] cpuss DataWire #1, Channel #6 */
  cpuss_interrupts_dw1_7_IRQn       =  60,      /*!<  60 [Active] cpuss DataWire #1, Channel #7 */
  cpuss_interrupts_dw1_8_IRQn       =  61,      /*!<  61 [Active] cpuss DataWire #1, Channel #8 */
  cpuss_interrupts_dw1_9_IRQn       =  62,      /*!<  62 [Active] cpuss DataWire #1, Channel #9 */
  cpuss_interrupts_dw1_10_IRQn      =  63,      /*!<  63 [Active] cpuss DataWire #1, Channel #10 */
  cpuss_interrupts_dw1_11_IRQn      =  64,      /*!<  64 [Active] cpuss DataWire #1, Channel #11 */
  cpuss_interrupts_dw1_12_IRQn      =  65,      /*!<  65 [Active] cpuss DataWire #1, Channel #12 */
  cpuss_interrupts_dw1_13_IRQn      =  66,      /*!<  66 [Active] cpuss DataWire #1, Channel #13 */
  cpuss_interrupts_dw1_14_IRQn      =  67,      /*!<  67 [Active] cpuss DataWire #1, Channel #14 */
  cpuss_interrupts_dw1_15_IRQn      =  68,      /*!<  68 [Active] cpuss DataWire #1, Channel #15 */
  cpuss_interrupt_ppu_sramc0_IRQn   =  69,      /*!<  69 [Active] PPU SRAM0 */
  cpuss_interrupt_cm33_0_fp_IRQn    =  70,      /*!<  70 [Active] CM33 0 Floating Point Interrupt */
  cpuss_interrupts_cm33_0_cti_0_IRQn =  71,     /*!<  71 [Active] CM33-0 CTI interrupt outputs */
  cpuss_interrupts_cm33_0_cti_1_IRQn =  72,     /*!<  72 [Active] CM33-1 CTI interrupt outputs */
  cpuss_interrupts_fault_0_IRQn     =  73,      /*!<  73 [Active] cpuss Faults interrupt */
  cpuss_interrupt_ppu_cpuss_IRQn    =  74,      /*!<  74 [Active] cpuss PPU Interrupt */
  cpuss_interrupt_msc_IRQn          =  75,      /*!<  75 [Active] cpuss Master Security Controller Interrupt */
  tcpwm_0_interrupts_0_IRQn         =  76,      /*!<  76 [Active] TCPWM #0, Counter #0 */
  tcpwm_0_interrupts_1_IRQn         =  77,      /*!<  77 [Active] TCPWM #0, Counter #1 */
  tcpwm_0_interrupts_2_IRQn         =  78,      /*!<  78 [Active] TCPWM #0, Counter #2 */
  tcpwm_0_interrupts_3_IRQn         =  79,      /*!<  79 [Active] TCPWM #0, Counter #3 */
  tcpwm_0_interrupts_256_IRQn       =  80,      /*!<  80 [Active] TCPWM #0, Counter #256 */
  tcpwm_0_interrupts_257_IRQn       =  81,      /*!<  81 [Active] TCPWM #0, Counter #257 */
  tcpwm_0_interrupts_258_IRQn       =  82,      /*!<  82 [Active] TCPWM #0, Counter #258 */
  tcpwm_0_interrupts_259_IRQn       =  83,      /*!<  83 [Active] TCPWM #0, Counter #259 */
  tcpwm_0_interrupts_260_IRQn       =  84,      /*!<  84 [Active] TCPWM #0, Counter #260 */
  tcpwm_0_interrupts_261_IRQn       =  85,      /*!<  85 [Active] TCPWM #0, Counter #261 */
  tcpwm_0_interrupts_262_IRQn       =  86,      /*!<  86 [Active] TCPWM #0, Counter #262 */
  tcpwm_0_interrupts_263_IRQn       =  87,      /*!<  87 [Active] TCPWM #0, Counter #263 */
  tcpwm_0_interrupts_512_IRQn       =  88,      /*!<  88 [Active] TCPWM #0, Counter #512 */
  tcpwm_0_interrupts_513_IRQn       =  89,      /*!<  89 [Active] TCPWM #0, Counter #513 */
  tcpwm_0_interrupts_514_IRQn       =  90,      /*!<  90 [Active] TCPWM #0, Counter #514 */
  tcpwm_0_interrupts_515_IRQn       =  91,      /*!<  91 [Active] TCPWM #0, Counter #515 */
  tcpwm_0_interrupts_516_IRQn       =  92,      /*!<  92 [Active] TCPWM #0, Counter #516 */
  tcpwm_0_interrupts_517_IRQn       =  93,      /*!<  93 [Active] TCPWM #0, Counter #517 */
  tcpwm_0_interrupts_518_IRQn       =  94,      /*!<  94 [Active] TCPWM #0, Counter #518 */
  tcpwm_0_interrupts_519_IRQn       =  95,      /*!<  95 [Active] TCPWM #0, Counter #519 */
  srss_interrupt_main_ppu_IRQn      =  96,      /*!<  96 [Active] SRSS Main PPU Interrupt */
  cryptolite_interrupt_error_IRQn   =  97,      /*!<  97 [Active] Crypto Interrupt */
  cryptolite_interrupt_trng_IRQn    =  98,      /*!<  98 [Active] TRNG interrupt */
  canfd_0_interrupts0_0_IRQn        =  99,      /*!<  99 [Active] CAN #0, Interrupt #0, Channel #0 */
  canfd_0_interrupts1_0_IRQn        = 100,      /*!< 100 [Active] CAN #0, Interrupt #1, Channel #0 */
  canfd_0_interrupts0_1_IRQn        = 101,      /*!< 101 [Active] CAN #0, Interrupt #0, Channel #1 */
  canfd_0_interrupts1_1_IRQn        = 102,      /*!< 102 [Active] CAN #0, Interrupt #1, Channel #1 */
  canfd_0_interrupt0_IRQn           = 103,      /*!< 103 [Active] Can #0, Consolidated interrupt #0 */
  canfd_0_interrupt1_IRQn           = 104,      /*!< 104 [Active] Can #0, Consolidated interrupt #1 */
  cordic_interrupt_mxcordic_IRQn    = 105,      /*!< 105 [Active] CORDIC */
  tcpwm_0_motif_interrupt_64_IRQn   = 106,      /*!< 106 [Active] TCPWM #0, MOTIF #1 SR0 */
  tcpwm_0_motif_interrupt_65_IRQn   = 107,      /*!< 107 [Active] TCPWM #0, MOTIF #1 SR1 */
  pass_interrupt_mcpass_IRQn        = 108,      /*!< 108 [Active] Combined MCPASS interrupt, AC, Error conditions */
  pass_interrupt_sar_results_IRQn   = 109,      /*!< 109 [Active] Combined SAR Entry and FIR results interrupt */
  pass_interrupt_sar_entry_done_0_IRQn = 110,   /*!< 110 [Active] Individual SAR Entry result interrupts [0] */
  pass_interrupt_sar_entry_done_1_IRQn = 111,   /*!< 111 [Active] Individual SAR Entry result interrupts [1] */
  pass_interrupt_sar_entry_done_2_IRQn = 112,   /*!< 112 [Active] Individual SAR Entry result interrupts [2] */
  pass_interrupt_sar_entry_done_3_IRQn = 113,   /*!< 113 [Active] Individual SAR Entry result interrupts [3] */
  pass_interrupt_sar_entry_done_4_IRQn = 114,   /*!< 114 [Active] Individual SAR Entry result interrupts [4] */
  pass_interrupt_sar_entry_done_5_IRQn = 115,   /*!< 115 [Active] Individual SAR Entry result interrupts [5] */
  pass_interrupt_sar_entry_done_6_IRQn = 116,   /*!< 116 [Active] Individual SAR Entry result interrupts [6] */
  pass_interrupt_sar_entry_done_7_IRQn = 117,   /*!< 117 [Active] Individual SAR Entry result interrupts [7] */
  pass_interrupt_sar_fir_done_0_IRQn = 118,     /*!< 118 [Active] Individual FIR result interrupts[0] */
  pass_interrupt_sar_fir_done_1_IRQn = 119,     /*!< 119 [Active] Individual FIR result interrupts[1] */
  pass_interrupt_sar_ranges_IRQn    = 120,      /*!< 120 [Active] Combined SAR range interrupt */
  pass_interrupt_sar_range_0_IRQn   = 121,      /*!< 121 [Active] Individual SAR range interrupts[0] */
  pass_interrupt_sar_range_1_IRQn   = 122,      /*!< 122 [Active] Individual SAR range interrupts[1] */
  pass_interrupt_sar_range_2_IRQn   = 123,      /*!< 123 [Active] Individual SAR range interrupts[2] */
  pass_interrupt_sar_range_3_IRQn   = 124,      /*!< 124 [Active] Individual SAR range interrupts[3] */
  pass_interrupt_sar_range_4_IRQn   = 125,      /*!< 125 [Active] Individual SAR range interrupts[4] */
  pass_interrupt_sar_range_5_IRQn   = 126,      /*!< 126 [Active] Individual SAR range interrupts[5] */
  pass_interrupt_sar_range_6_IRQn   = 127,      /*!< 127 [Active] Individual SAR range interrupts[6] */
  pass_interrupt_sar_range_7_IRQn   = 128,      /*!< 128 [Active] Individual SAR range interrupts[7] */
  pass_interrupt_csg_dacs_IRQn      = 129,      /*!< 129 [Active] Combined CSG DAC interrupt */
  pass_interrupt_csg_dac_0_IRQn     = 130,      /*!< 130 [Active] Individual CSG DAC interrupts ( 5 in PSOC C3 )[0] */
  pass_interrupt_csg_dac_1_IRQn     = 131,      /*!< 131 [Active] Individual CSG DAC interrupts ( 5 in PSOC C3 )[1] */
  pass_interrupt_csg_dac_2_IRQn     = 132,      /*!< 132 [Active] Individual CSG DAC interrupts ( 5 in PSOC C3 )[2] */
  pass_interrupt_csg_dac_3_IRQn     = 133,      /*!< 133 [Active] Individual CSG DAC interrupts ( 5 in PSOC C3 )[3] */
  pass_interrupt_csg_dac_4_IRQn     = 134,      /*!< 134 [Active] Individual CSG DAC interrupts ( 5 in PSOC C3 )[4] */
  pass_interrupt_csg_dac_5_IRQn     = 135,      /*!< 135 [Active] Individual CSG DAC interrupts ( 5 in PSOC C3 )[5] */
  pass_interrupt_csg_dac_6_IRQn     = 136,      /*!< 136 [Active] Individual CSG DAC interrupts ( 5 in PSOC C3 )[6] */
  pass_interrupt_csg_dac_7_IRQn     = 137,      /*!< 137 [Active] Individual CSG DAC interrupts ( 5 in PSOC C3 )[7] */
  pass_interrupt_csg_cmps_IRQn      = 138,      /*!< 138 [Active] Combined CSG CMP interrupts */
  pass_interrupt_fifos_IRQn         = 139,      /*!< 139 [Active] Combined FIFO interrupts */
  unconnected_IRQn                  = 240       /*!< 240 Unconnected */
} IRQn_Type;


/*******************************************************************************
*                    Processor and Core Peripheral Section
*******************************************************************************/

/* Configuration of the ARM Cortex-M33 Processor and Core Peripherals */
#define __CM33_REV                      0x0001U /*!< CM33 Core Revision */
#define __NVIC_PRIO_BITS                3       /*!< Number of Bits used for Priority Levels */
#define __Vendor_SysTickConfig          0       /*!< Set to 1 if different SysTick Config is used */
#define __VTOR_PRESENT                  1       /*!< Set to 1 if CPU supports Vector Table Offset Register */
#define __MPU_PRESENT                   1       /*!< MPU present or not */
#define __FPU_PRESENT                   1       /*!< FPU present or not */
#define __CM0P_PRESENT                  0       /*!< CM0P present or not */
#define __DTCM_PRESENT                  0       /*!< Data Tightly Coupled Memory is present or not */
#define __ICACHE_PRESENT                0       /*!< Instruction Cache present or not */
#define __DCACHE_PRESENT                0       /*!< Data Cache present or not */
#define __DSP_PRESENT                   1       /*!< DSP extension present or not */
#define __SAUREGION_PRESENT             1       /*!< SAU regions present or not */

/** \} Configuration_of_CMSIS */

#include "core_cm33.h"                          /*!< ARM Cortex-M33 processor and core peripherals */


/* Memory Blocks */
#define CY_ROM_BASE                     0x00800000UL
#define CY_ROM_CBUS_BASE                0x00800000UL
#define CY_ROM_SIZE                     0x00010000UL
#define CY_ROM_NS_SBUS_BASE             0x00800000UL
#define CY_ROM_NS_CBUS_BASE             0x00800000UL
#define CY_ROM_S_SBUS_BASE              0x10800000UL
#define CY_ROM_S_CBUS_BASE              0x10800000UL
#define CY_SRAM_BASE                    0x24000000UL
#define CY_SRAM_CBUS_BASE               0x04000000UL
#define CY_SRAM_SIZE                    0x00010000UL
#define CY_SRAM_NS_SBUS_BASE            0x24000000UL
#define CY_SRAM_NS_CBUS_BASE            0x04000000UL
#define CY_SRAM_S_SBUS_BASE             0x34000000UL
#define CY_SRAM_S_CBUS_BASE             0x14000000UL
#define CY_FLASH_BASE                   0x22000000UL
#define CY_FLASH_CBUS_BASE              0x02000000UL
#define CY_FLASH_SIZE                   0x00040000UL
#define CY_FLASH_NS_SBUS_BASE           0x22000000UL
#define CY_FLASH_NS_CBUS_BASE           0x02000000UL
#define CY_FLASH_S_SBUS_BASE            0x32000000UL
#define CY_FLASH_S_CBUS_BASE            0x12000000UL
#define CY_FLASH_REFRESH_NS_CBUS_BASE   0x03800000UL
#define CY_FLASH_REFRESH_NS_SBUS_BASE   0x13800000UL
#define CY_FLASH_REFRESH_S_CBUS_BASE    0x23800000UL
#define CY_FLASH_REFRESH_S_SBUS_BASE    0x33800000UL
#define CY_FLASH_COLUMN33_NS_CBUS_BASE  0x03A00000UL
#define CY_FLASH_COLUMN33_NS_SBUS_BASE  0x13A00000UL
#define CY_FLASH_COLUMN33_S_CBUS_BASE   0x23A00000UL
#define CY_FLASH_COLUMN33_S_SBUS_BASE   0x33A00000UL
#define CY_SFLASH_BASE                  0x23400000UL
#define CY_SFLASH_CBUS_BASE             0x03400000UL
#define CY_SFLASH_SIZE                  0x00008000UL
#define CY_SFLASH_NS_SBUS_BASE          0x23400000UL
#define CY_SFLASH_NS_CBUS_BASE          0x03400000UL
#define CY_SFLASH_S_SBUS_BASE           0x33400000UL
#define CY_SFLASH_S_CBUS_BASE           0x13400000UL
#define CY_EFUSE_BASE                   0x42610800UL
#define CY_EFUSE_CBUS_BASE              0x42610800UL
#define CY_EFUSE_SIZE                   0x00000200UL
#define CY_EFUSE_NS_SBUS_BASE           0x42610800UL
#define CY_EFUSE_NS_CBUS_BASE           0x42610800UL
#define CY_EFUSE_S_SBUS_BASE            0x52610800UL
#define CY_EFUSE_S_CBUS_BASE            0x52610800UL
#define CY_CAN0MRAM_BASE                0x42810000UL
#define CY_CAN0MRAM_CBUS_BASE           0x42810000UL
#define CY_CAN0MRAM_SIZE                0x00010000UL
#define CY_CAN0MRAM_NS_SBUS_BASE        0x42810000UL
#define CY_CAN0MRAM_NS_CBUS_BASE        0x42810000UL
#define CY_CAN0MRAM_S_SBUS_BASE         0x52810000UL
#define CY_CAN0MRAM_S_CBUS_BASE         0x52810000UL


/* IP List */
#define CY_IP_MXTTCANFD                 1u
#define CY_IP_MXTTCANFD_INSTANCES       1u
#define CY_IP_MXTTCANFD_VERSION         3u
#define CY_IP_MXTTCANFD_VERSION_MINOR   0u
#define CY_IP_M33SYSCPUSS               1u
#define CY_IP_M33SYSCPUSS_INSTANCES     1u
#define CY_IP_M33SYSCPUSS_VERSION       2u
#define CY_IP_M33SYSCPUSS_VERSION_MINOR 1u
#define CY_IP_MXCRYPTOLITE              1u
#define CY_IP_MXCRYPTOLITE_INSTANCES    1u
#define CY_IP_MXCRYPTOLITE_VERSION      1u
#define CY_IP_MXCRYPTOLITE_VERSION_MINOR 0u
#define CY_IP_MXDEBUG600                1u
#define CY_IP_MXDEBUG600_INSTANCES      1u
#define CY_IP_MXDEBUG600_VERSION        1u
#define CY_IP_MXDEBUG600_VERSION_MINOR  1u
#define CY_IP_MXDFT                     1u
#define CY_IP_MXDFT_INSTANCES           1u
#define CY_IP_MXDFT_VERSION             2u
#define CY_IP_MXDFT_VERSION_MINOR       1u
#define CY_IP_MXEFUSE                   1u
#define CY_IP_MXEFUSE_INSTANCES         1u
#define CY_IP_MXEFUSE_VERSION           3u
#define CY_IP_MXEFUSE_VERSION_MINOR     1u
#define CY_IP_MXS40FLASHC               1u
#define CY_IP_MXS40FLASHC_INSTANCES     1u
#define CY_IP_MXS40FLASHC_VERSION       1u
#define CY_IP_MXS40FLASHC_VERSION_MINOR 0u
#define CY_IP_MXS40SIOSS                1u
#define CY_IP_MXS40SIOSS_INSTANCES      1u
#define CY_IP_MXS40SIOSS_VERSION        1u
#define CY_IP_MXS40SIOSS_VERSION_MINOR  0u
#define CY_IP_MXS40LPCOMP               1u
#define CY_IP_MXS40LPCOMP_INSTANCES     1u
#define CY_IP_MXS40LPCOMP_VERSION       2u
#define CY_IP_MXS40LPCOMP_VERSION_MINOR 0u
#define CY_IP_MXCM33                    1u
#define CY_IP_MXCM33_INSTANCES          1u
#define CY_IP_MXCM33_VERSION            2u
#define CY_IP_MXCM33_VERSION_MINOR      1u
#define CY_IP_MXDW                      1u
#define CY_IP_MXDW_INSTANCES            2u
#define CY_IP_MXDW_VERSION              1u
#define CY_IP_MXDW_VERSION_MINOR        0u
#define CY_IP_MXFAULT                   1u
#define CY_IP_MXFAULT_INSTANCES         1u
#define CY_IP_MXFAULT_VERSION           1u
#define CY_IP_MXFAULT_VERSION_MINOR     0u
#define CY_IP_MXIPC                     1u
#define CY_IP_MXIPC_INSTANCES           1u
#define CY_IP_MXIPC_VERSION             1u
#define CY_IP_MXIPC_VERSION_MINOR       0u
#define CY_IP_MXPROMC                   1u
#define CY_IP_MXPROMC_INSTANCES         1u
#define CY_IP_MXPROMC_VERSION           2u
#define CY_IP_MXPROMC_VERSION_MINOR     0u
#define CY_IP_MXSRAMC                   1u
#define CY_IP_MXSRAMC_INSTANCES         1u
#define CY_IP_MXSRAMC_VERSION           2u
#define CY_IP_MXSRAMC_VERSION_MINOR     0u
#define CY_IP_MXS40MCPASS               1u
#define CY_IP_MXS40MCPASS_INSTANCES     1u
#define CY_IP_MXS40MCPASS_VERSION       1u
#define CY_IP_MXS40MCPASS_VERSION_MINOR 0u
#define CY_IP_MXSPERI                   1u
#define CY_IP_MXSPERI_INSTANCES         1u
#define CY_IP_MXSPERI_VERSION           2u
#define CY_IP_MXSPERI_VERSION_MINOR     0u
#define CY_IP_MXSPERI_TR                1u
#define CY_IP_MXSPERI_TR_INSTANCES      1u
#define CY_IP_MXSPERI_TR_VERSION        2u
#define CY_IP_MXSPERI_TR_VERSION_MINOR  0u
#define CY_IP_MXSCB                     1u
#define CY_IP_MXSCB_INSTANCES           6u
#define CY_IP_MXSCB_VERSION             4u
#define CY_IP_MXSCB_VERSION_MINOR       2u
#define CY_IP_MXS40SSRSS                1u
#define CY_IP_MXS40SSRSS_INSTANCES      1u
#define CY_IP_MXS40SSRSS_VERSION        1u
#define CY_IP_MXS40SSRSS_VERSION_MINOR  2u
#define CY_IP_MXS40TCPWM                1u
#define CY_IP_MXS40TCPWM_INSTANCES      1u
#define CY_IP_MXS40TCPWM_VERSION        1u
#define CY_IP_MXS40TCPWM_VERSION_MINOR  0u

#define CY_DEVICE_PSC3
#define CY_DEVICE_SERIES_PSC3P5
#define CY_SILICON_ID                   0xEE511118UL
#define CY_HF_CLK_MAX_FREQ              180000000UL


#include "system_cat1b.h"

#include "psc3_config.h"
#include "gpio_psc3_e_lqfp_48.h"

/*******************************************************************************
*                                    SFLASH
*******************************************************************************/

#define SFLASH_BASE                             0x03400000UL
#define SFLASH                                  ((SFLASH_Type*) SFLASH_BASE)                                      /* 0x03400000 */

/*******************************************************************************
*                                     PERI
*******************************************************************************/

#define PERI_BASE                               0x42000000UL
#define PERI                                    ((PERI_Type*) PERI_BASE)                                          /* 0x42000000 */
#define PERI_GR0                                ((PERI_GR_Type*) &PERI->GR[0])                                    /* 0x42004000 */
#define PERI_GR1                                ((PERI_GR_Type*) &PERI->GR[1])                                    /* 0x42004040 */
#define PERI_GR2                                ((PERI_GR_Type*) &PERI->GR[2])                                    /* 0x42004080 */
#define PERI_GR3                                ((PERI_GR_Type*) &PERI->GR[3])                                    /* 0x420040C0 */
#define PERI_GR4                                ((PERI_GR_Type*) &PERI->GR[4])                                    /* 0x42004100 */
#define PERI_GR5                                ((PERI_GR_Type*) &PERI->GR[5])                                    /* 0x42004140 */
#define PERI_TR_GR0                             ((PERI_TR_GR_Type*) &PERI->TR_GR[0])                              /* 0x42008000 */
#define PERI_TR_GR1                             ((PERI_TR_GR_Type*) &PERI->TR_GR[1])                              /* 0x42008400 */
#define PERI_TR_GR2                             ((PERI_TR_GR_Type*) &PERI->TR_GR[2])                              /* 0x42008800 */
#define PERI_TR_GR3                             ((PERI_TR_GR_Type*) &PERI->TR_GR[3])                              /* 0x42008C00 */
#define PERI_TR_GR4                             ((PERI_TR_GR_Type*) &PERI->TR_GR[4])                              /* 0x42009000 */
#define PERI_TR_GR5                             ((PERI_TR_GR_Type*) &PERI->TR_GR[5])                              /* 0x42009400 */
#define PERI_TR_GR6                             ((PERI_TR_GR_Type*) &PERI->TR_GR[6])                              /* 0x42009800 */
#define PERI_TR_GR7                             ((PERI_TR_GR_Type*) &PERI->TR_GR[7])                              /* 0x42009C00 */
#define PERI_TR_GR8                             ((PERI_TR_GR_Type*) &PERI->TR_GR[8])                              /* 0x4200A000 */
#define PERI_TR_GR9                             ((PERI_TR_GR_Type*) &PERI->TR_GR[9])                              /* 0x4200A400 */
#define PERI_TR_GR10                            ((PERI_TR_GR_Type*) &PERI->TR_GR[10])                             /* 0x4200A800 */
#define PERI_TR_GR11                            ((PERI_TR_GR_Type*) &PERI->TR_GR[11])                             /* 0x4200AC00 */
#define PERI_TR_GR12                            ((PERI_TR_GR_Type*) &PERI->TR_GR[12])                             /* 0x4200B000 */
#define PERI_TR_GR13                            ((PERI_TR_GR_Type*) &PERI->TR_GR[13])                             /* 0x4200B400 */
#define PERI_TR_GR14                            ((PERI_TR_GR_Type*) &PERI->TR_GR[14])                             /* 0x4200B800 */
#define PERI_TR_1TO1_GR0                        ((PERI_TR_1TO1_GR_Type*) &PERI->TR_1TO1_GR[0])                    /* 0x4200C000 */
#define PERI_TR_1TO1_GR1                        ((PERI_TR_1TO1_GR_Type*) &PERI->TR_1TO1_GR[1])                    /* 0x4200C400 */
#define PERI_TR_1TO1_GR2                        ((PERI_TR_1TO1_GR_Type*) &PERI->TR_1TO1_GR[2])                    /* 0x4200C800 */

/*******************************************************************************
*                                     PPC
*******************************************************************************/

#define PPC_BASE                                0x42020000UL
#define PPC                                     ((PPC_Type*) PPC_BASE)                                            /* 0x42020000 */
#define PPC_PPC                                 ((PPC_PPC_Type*) &PPC->PPC)                                       /* 0x42020000 */
#define PPC_PPC_R_ADDR0                         ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[0])                      /* 0x42025000 */
#define PPC_PPC_R_ADDR1                         ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[1])                      /* 0x42025004 */
#define PPC_PPC_R_ADDR2                         ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[2])                      /* 0x42025008 */
#define PPC_PPC_R_ADDR3                         ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[3])                      /* 0x4202500C */
#define PPC_PPC_R_ADDR4                         ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[4])                      /* 0x42025010 */
#define PPC_PPC_R_ADDR5                         ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[5])                      /* 0x42025014 */
#define PPC_PPC_R_ADDR6                         ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[6])                      /* 0x42025018 */
#define PPC_PPC_R_ADDR7                         ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[7])                      /* 0x4202501C */
#define PPC_PPC_R_ADDR8                         ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[8])                      /* 0x42025020 */
#define PPC_PPC_R_ADDR9                         ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[9])                      /* 0x42025024 */
#define PPC_PPC_R_ADDR10                        ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[10])                     /* 0x42025028 */
#define PPC_PPC_R_ADDR11                        ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[11])                     /* 0x4202502C */
#define PPC_PPC_R_ADDR12                        ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[12])                     /* 0x42025030 */
#define PPC_PPC_R_ADDR13                        ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[13])                     /* 0x42025034 */
#define PPC_PPC_R_ADDR14                        ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[14])                     /* 0x42025038 */
#define PPC_PPC_R_ADDR15                        ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[15])                     /* 0x4202503C */
#define PPC_PPC_R_ADDR16                        ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[16])                     /* 0x42025040 */
#define PPC_PPC_R_ADDR17                        ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[17])                     /* 0x42025044 */
#define PPC_PPC_R_ADDR18                        ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[18])                     /* 0x42025048 */
#define PPC_PPC_R_ADDR19                        ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[19])                     /* 0x4202504C */
#define PPC_PPC_R_ADDR20                        ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[20])                     /* 0x42025050 */
#define PPC_PPC_R_ADDR21                        ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[21])                     /* 0x42025054 */
#define PPC_PPC_R_ADDR22                        ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[22])                     /* 0x42025058 */
#define PPC_PPC_R_ADDR23                        ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[23])                     /* 0x4202505C */
#define PPC_PPC_R_ADDR24                        ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[24])                     /* 0x42025060 */
#define PPC_PPC_R_ADDR25                        ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[25])                     /* 0x42025064 */
#define PPC_PPC_R_ADDR26                        ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[26])                     /* 0x42025068 */
#define PPC_PPC_R_ADDR27                        ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[27])                     /* 0x4202506C */
#define PPC_PPC_R_ADDR28                        ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[28])                     /* 0x42025070 */
#define PPC_PPC_R_ADDR29                        ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[29])                     /* 0x42025074 */
#define PPC_PPC_R_ADDR30                        ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[30])                     /* 0x42025078 */
#define PPC_PPC_R_ADDR31                        ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[31])                     /* 0x4202507C */
#define PPC_PPC_R_ADDR32                        ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[32])                     /* 0x42025080 */
#define PPC_PPC_R_ADDR33                        ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[33])                     /* 0x42025084 */
#define PPC_PPC_R_ADDR34                        ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[34])                     /* 0x42025088 */
#define PPC_PPC_R_ADDR35                        ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[35])                     /* 0x4202508C */
#define PPC_PPC_R_ADDR36                        ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[36])                     /* 0x42025090 */
#define PPC_PPC_R_ADDR37                        ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[37])                     /* 0x42025094 */
#define PPC_PPC_R_ADDR38                        ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[38])                     /* 0x42025098 */
#define PPC_PPC_R_ADDR39                        ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[39])                     /* 0x4202509C */
#define PPC_PPC_R_ADDR40                        ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[40])                     /* 0x420250A0 */
#define PPC_PPC_R_ADDR41                        ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[41])                     /* 0x420250A4 */
#define PPC_PPC_R_ADDR42                        ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[42])                     /* 0x420250A8 */
#define PPC_PPC_R_ADDR43                        ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[43])                     /* 0x420250AC */
#define PPC_PPC_R_ADDR44                        ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[44])                     /* 0x420250B0 */
#define PPC_PPC_R_ADDR45                        ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[45])                     /* 0x420250B4 */
#define PPC_PPC_R_ADDR46                        ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[46])                     /* 0x420250B8 */
#define PPC_PPC_R_ADDR47                        ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[47])                     /* 0x420250BC */
#define PPC_PPC_R_ADDR48                        ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[48])                     /* 0x420250C0 */
#define PPC_PPC_R_ADDR49                        ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[49])                     /* 0x420250C4 */
#define PPC_PPC_R_ADDR50                        ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[50])                     /* 0x420250C8 */
#define PPC_PPC_R_ADDR51                        ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[51])                     /* 0x420250CC */
#define PPC_PPC_R_ADDR52                        ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[52])                     /* 0x420250D0 */
#define PPC_PPC_R_ADDR53                        ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[53])                     /* 0x420250D4 */
#define PPC_PPC_R_ADDR54                        ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[54])                     /* 0x420250D8 */
#define PPC_PPC_R_ADDR55                        ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[55])                     /* 0x420250DC */
#define PPC_PPC_R_ADDR56                        ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[56])                     /* 0x420250E0 */
#define PPC_PPC_R_ADDR57                        ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[57])                     /* 0x420250E4 */
#define PPC_PPC_R_ADDR58                        ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[58])                     /* 0x420250E8 */
#define PPC_PPC_R_ADDR59                        ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[59])                     /* 0x420250EC */
#define PPC_PPC_R_ADDR60                        ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[60])                     /* 0x420250F0 */
#define PPC_PPC_R_ADDR61                        ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[61])                     /* 0x420250F4 */
#define PPC_PPC_R_ADDR62                        ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[62])                     /* 0x420250F8 */
#define PPC_PPC_R_ADDR63                        ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[63])                     /* 0x420250FC */
#define PPC_PPC_R_ADDR64                        ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[64])                     /* 0x42025100 */
#define PPC_PPC_R_ADDR65                        ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[65])                     /* 0x42025104 */
#define PPC_PPC_R_ADDR66                        ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[66])                     /* 0x42025108 */
#define PPC_PPC_R_ADDR67                        ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[67])                     /* 0x4202510C */
#define PPC_PPC_R_ADDR68                        ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[68])                     /* 0x42025110 */
#define PPC_PPC_R_ADDR69                        ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[69])                     /* 0x42025114 */
#define PPC_PPC_R_ADDR70                        ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[70])                     /* 0x42025118 */
#define PPC_PPC_R_ADDR71                        ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[71])                     /* 0x4202511C */
#define PPC_PPC_R_ADDR72                        ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[72])                     /* 0x42025120 */
#define PPC_PPC_R_ADDR73                        ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[73])                     /* 0x42025124 */
#define PPC_PPC_R_ADDR74                        ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[74])                     /* 0x42025128 */
#define PPC_PPC_R_ADDR75                        ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[75])                     /* 0x4202512C */
#define PPC_PPC_R_ADDR76                        ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[76])                     /* 0x42025130 */
#define PPC_PPC_R_ADDR77                        ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[77])                     /* 0x42025134 */
#define PPC_PPC_R_ADDR78                        ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[78])                     /* 0x42025138 */
#define PPC_PPC_R_ADDR79                        ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[79])                     /* 0x4202513C */
#define PPC_PPC_R_ADDR80                        ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[80])                     /* 0x42025140 */
#define PPC_PPC_R_ADDR81                        ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[81])                     /* 0x42025144 */
#define PPC_PPC_R_ADDR82                        ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[82])                     /* 0x42025148 */
#define PPC_PPC_R_ADDR83                        ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[83])                     /* 0x4202514C */
#define PPC_PPC_R_ADDR84                        ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[84])                     /* 0x42025150 */
#define PPC_PPC_R_ADDR85                        ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[85])                     /* 0x42025154 */
#define PPC_PPC_R_ADDR86                        ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[86])                     /* 0x42025158 */
#define PPC_PPC_R_ADDR87                        ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[87])                     /* 0x4202515C */
#define PPC_PPC_R_ADDR88                        ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[88])                     /* 0x42025160 */
#define PPC_PPC_R_ADDR89                        ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[89])                     /* 0x42025164 */
#define PPC_PPC_R_ADDR90                        ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[90])                     /* 0x42025168 */
#define PPC_PPC_R_ADDR91                        ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[91])                     /* 0x4202516C */
#define PPC_PPC_R_ADDR92                        ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[92])                     /* 0x42025170 */
#define PPC_PPC_R_ADDR93                        ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[93])                     /* 0x42025174 */
#define PPC_PPC_R_ADDR94                        ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[94])                     /* 0x42025178 */
#define PPC_PPC_R_ADDR95                        ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[95])                     /* 0x4202517C */
#define PPC_PPC_R_ADDR96                        ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[96])                     /* 0x42025180 */
#define PPC_PPC_R_ADDR97                        ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[97])                     /* 0x42025184 */
#define PPC_PPC_R_ADDR98                        ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[98])                     /* 0x42025188 */
#define PPC_PPC_R_ADDR99                        ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[99])                     /* 0x4202518C */
#define PPC_PPC_R_ADDR100                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[100])                    /* 0x42025190 */
#define PPC_PPC_R_ADDR101                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[101])                    /* 0x42025194 */
#define PPC_PPC_R_ADDR102                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[102])                    /* 0x42025198 */
#define PPC_PPC_R_ADDR103                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[103])                    /* 0x4202519C */
#define PPC_PPC_R_ADDR104                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[104])                    /* 0x420251A0 */
#define PPC_PPC_R_ADDR105                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[105])                    /* 0x420251A4 */
#define PPC_PPC_R_ADDR106                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[106])                    /* 0x420251A8 */
#define PPC_PPC_R_ADDR107                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[107])                    /* 0x420251AC */
#define PPC_PPC_R_ADDR108                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[108])                    /* 0x420251B0 */
#define PPC_PPC_R_ADDR109                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[109])                    /* 0x420251B4 */
#define PPC_PPC_R_ADDR110                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[110])                    /* 0x420251B8 */
#define PPC_PPC_R_ADDR111                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[111])                    /* 0x420251BC */
#define PPC_PPC_R_ADDR112                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[112])                    /* 0x420251C0 */
#define PPC_PPC_R_ADDR113                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[113])                    /* 0x420251C4 */
#define PPC_PPC_R_ADDR114                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[114])                    /* 0x420251C8 */
#define PPC_PPC_R_ADDR115                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[115])                    /* 0x420251CC */
#define PPC_PPC_R_ADDR116                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[116])                    /* 0x420251D0 */
#define PPC_PPC_R_ADDR117                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[117])                    /* 0x420251D4 */
#define PPC_PPC_R_ADDR118                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[118])                    /* 0x420251D8 */
#define PPC_PPC_R_ADDR119                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[119])                    /* 0x420251DC */
#define PPC_PPC_R_ADDR120                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[120])                    /* 0x420251E0 */
#define PPC_PPC_R_ADDR121                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[121])                    /* 0x420251E4 */
#define PPC_PPC_R_ADDR122                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[122])                    /* 0x420251E8 */
#define PPC_PPC_R_ADDR123                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[123])                    /* 0x420251EC */
#define PPC_PPC_R_ADDR124                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[124])                    /* 0x420251F0 */
#define PPC_PPC_R_ADDR125                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[125])                    /* 0x420251F4 */
#define PPC_PPC_R_ADDR126                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[126])                    /* 0x420251F8 */
#define PPC_PPC_R_ADDR127                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[127])                    /* 0x420251FC */
#define PPC_PPC_R_ADDR128                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[128])                    /* 0x42025200 */
#define PPC_PPC_R_ADDR129                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[129])                    /* 0x42025204 */
#define PPC_PPC_R_ADDR130                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[130])                    /* 0x42025208 */
#define PPC_PPC_R_ADDR131                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[131])                    /* 0x4202520C */
#define PPC_PPC_R_ADDR132                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[132])                    /* 0x42025210 */
#define PPC_PPC_R_ADDR133                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[133])                    /* 0x42025214 */
#define PPC_PPC_R_ADDR134                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[134])                    /* 0x42025218 */
#define PPC_PPC_R_ADDR135                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[135])                    /* 0x4202521C */
#define PPC_PPC_R_ADDR136                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[136])                    /* 0x42025220 */
#define PPC_PPC_R_ADDR137                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[137])                    /* 0x42025224 */
#define PPC_PPC_R_ADDR138                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[138])                    /* 0x42025228 */
#define PPC_PPC_R_ADDR139                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[139])                    /* 0x4202522C */
#define PPC_PPC_R_ADDR140                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[140])                    /* 0x42025230 */
#define PPC_PPC_R_ADDR141                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[141])                    /* 0x42025234 */
#define PPC_PPC_R_ADDR142                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[142])                    /* 0x42025238 */
#define PPC_PPC_R_ADDR143                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[143])                    /* 0x4202523C */
#define PPC_PPC_R_ADDR144                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[144])                    /* 0x42025240 */
#define PPC_PPC_R_ADDR145                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[145])                    /* 0x42025244 */
#define PPC_PPC_R_ADDR146                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[146])                    /* 0x42025248 */
#define PPC_PPC_R_ADDR147                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[147])                    /* 0x4202524C */
#define PPC_PPC_R_ADDR148                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[148])                    /* 0x42025250 */
#define PPC_PPC_R_ADDR149                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[149])                    /* 0x42025254 */
#define PPC_PPC_R_ADDR150                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[150])                    /* 0x42025258 */
#define PPC_PPC_R_ADDR151                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[151])                    /* 0x4202525C */
#define PPC_PPC_R_ADDR152                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[152])                    /* 0x42025260 */
#define PPC_PPC_R_ADDR153                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[153])                    /* 0x42025264 */
#define PPC_PPC_R_ADDR154                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[154])                    /* 0x42025268 */
#define PPC_PPC_R_ADDR155                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[155])                    /* 0x4202526C */
#define PPC_PPC_R_ADDR156                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[156])                    /* 0x42025270 */
#define PPC_PPC_R_ADDR157                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[157])                    /* 0x42025274 */
#define PPC_PPC_R_ADDR158                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[158])                    /* 0x42025278 */
#define PPC_PPC_R_ADDR159                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[159])                    /* 0x4202527C */
#define PPC_PPC_R_ADDR160                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[160])                    /* 0x42025280 */
#define PPC_PPC_R_ADDR161                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[161])                    /* 0x42025284 */
#define PPC_PPC_R_ADDR162                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[162])                    /* 0x42025288 */
#define PPC_PPC_R_ADDR163                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[163])                    /* 0x4202528C */
#define PPC_PPC_R_ADDR164                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[164])                    /* 0x42025290 */
#define PPC_PPC_R_ADDR165                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[165])                    /* 0x42025294 */
#define PPC_PPC_R_ADDR166                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[166])                    /* 0x42025298 */
#define PPC_PPC_R_ADDR167                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[167])                    /* 0x4202529C */
#define PPC_PPC_R_ADDR168                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[168])                    /* 0x420252A0 */
#define PPC_PPC_R_ADDR169                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[169])                    /* 0x420252A4 */
#define PPC_PPC_R_ADDR170                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[170])                    /* 0x420252A8 */
#define PPC_PPC_R_ADDR171                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[171])                    /* 0x420252AC */
#define PPC_PPC_R_ADDR172                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[172])                    /* 0x420252B0 */
#define PPC_PPC_R_ADDR173                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[173])                    /* 0x420252B4 */
#define PPC_PPC_R_ADDR174                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[174])                    /* 0x420252B8 */
#define PPC_PPC_R_ADDR175                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[175])                    /* 0x420252BC */
#define PPC_PPC_R_ADDR176                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[176])                    /* 0x420252C0 */
#define PPC_PPC_R_ADDR177                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[177])                    /* 0x420252C4 */
#define PPC_PPC_R_ADDR178                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[178])                    /* 0x420252C8 */
#define PPC_PPC_R_ADDR179                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[179])                    /* 0x420252CC */
#define PPC_PPC_R_ADDR180                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[180])                    /* 0x420252D0 */
#define PPC_PPC_R_ADDR181                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[181])                    /* 0x420252D4 */
#define PPC_PPC_R_ADDR182                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[182])                    /* 0x420252D8 */
#define PPC_PPC_R_ADDR183                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[183])                    /* 0x420252DC */
#define PPC_PPC_R_ADDR184                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[184])                    /* 0x420252E0 */
#define PPC_PPC_R_ADDR185                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[185])                    /* 0x420252E4 */
#define PPC_PPC_R_ADDR186                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[186])                    /* 0x420252E8 */
#define PPC_PPC_R_ADDR187                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[187])                    /* 0x420252EC */
#define PPC_PPC_R_ADDR188                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[188])                    /* 0x420252F0 */
#define PPC_PPC_R_ADDR189                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[189])                    /* 0x420252F4 */
#define PPC_PPC_R_ADDR190                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[190])                    /* 0x420252F8 */
#define PPC_PPC_R_ADDR191                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[191])                    /* 0x420252FC */
#define PPC_PPC_R_ADDR192                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[192])                    /* 0x42025300 */
#define PPC_PPC_R_ADDR193                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[193])                    /* 0x42025304 */
#define PPC_PPC_R_ADDR194                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[194])                    /* 0x42025308 */
#define PPC_PPC_R_ADDR195                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[195])                    /* 0x4202530C */
#define PPC_PPC_R_ADDR196                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[196])                    /* 0x42025310 */
#define PPC_PPC_R_ADDR197                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[197])                    /* 0x42025314 */
#define PPC_PPC_R_ADDR198                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[198])                    /* 0x42025318 */
#define PPC_PPC_R_ADDR199                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[199])                    /* 0x4202531C */
#define PPC_PPC_R_ADDR200                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[200])                    /* 0x42025320 */
#define PPC_PPC_R_ADDR201                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[201])                    /* 0x42025324 */
#define PPC_PPC_R_ADDR202                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[202])                    /* 0x42025328 */
#define PPC_PPC_R_ADDR203                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[203])                    /* 0x4202532C */
#define PPC_PPC_R_ADDR204                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[204])                    /* 0x42025330 */
#define PPC_PPC_R_ADDR205                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[205])                    /* 0x42025334 */
#define PPC_PPC_R_ADDR206                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[206])                    /* 0x42025338 */
#define PPC_PPC_R_ADDR207                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[207])                    /* 0x4202533C */
#define PPC_PPC_R_ADDR208                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[208])                    /* 0x42025340 */
#define PPC_PPC_R_ADDR209                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[209])                    /* 0x42025344 */
#define PPC_PPC_R_ADDR210                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[210])                    /* 0x42025348 */
#define PPC_PPC_R_ADDR211                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[211])                    /* 0x4202534C */
#define PPC_PPC_R_ADDR212                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[212])                    /* 0x42025350 */
#define PPC_PPC_R_ADDR213                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[213])                    /* 0x42025354 */
#define PPC_PPC_R_ADDR214                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[214])                    /* 0x42025358 */
#define PPC_PPC_R_ADDR215                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[215])                    /* 0x4202535C */
#define PPC_PPC_R_ADDR216                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[216])                    /* 0x42025360 */
#define PPC_PPC_R_ADDR217                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[217])                    /* 0x42025364 */
#define PPC_PPC_R_ADDR218                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[218])                    /* 0x42025368 */
#define PPC_PPC_R_ADDR219                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[219])                    /* 0x4202536C */
#define PPC_PPC_R_ADDR220                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[220])                    /* 0x42025370 */
#define PPC_PPC_R_ADDR221                       ((PPC_PPC_R_ADDR_Type*) &PPC->PPC.R_ADDR[221])                    /* 0x42025374 */
#define PPC_PPC_R_ATT0                          ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[0])                        /* 0x42026000 */
#define PPC_PPC_R_ATT1                          ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[1])                        /* 0x42026004 */
#define PPC_PPC_R_ATT2                          ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[2])                        /* 0x42026008 */
#define PPC_PPC_R_ATT3                          ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[3])                        /* 0x4202600C */
#define PPC_PPC_R_ATT4                          ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[4])                        /* 0x42026010 */
#define PPC_PPC_R_ATT5                          ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[5])                        /* 0x42026014 */
#define PPC_PPC_R_ATT6                          ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[6])                        /* 0x42026018 */
#define PPC_PPC_R_ATT7                          ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[7])                        /* 0x4202601C */
#define PPC_PPC_R_ATT8                          ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[8])                        /* 0x42026020 */
#define PPC_PPC_R_ATT9                          ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[9])                        /* 0x42026024 */
#define PPC_PPC_R_ATT10                         ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[10])                       /* 0x42026028 */
#define PPC_PPC_R_ATT11                         ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[11])                       /* 0x4202602C */
#define PPC_PPC_R_ATT12                         ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[12])                       /* 0x42026030 */
#define PPC_PPC_R_ATT13                         ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[13])                       /* 0x42026034 */
#define PPC_PPC_R_ATT14                         ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[14])                       /* 0x42026038 */
#define PPC_PPC_R_ATT15                         ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[15])                       /* 0x4202603C */
#define PPC_PPC_R_ATT16                         ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[16])                       /* 0x42026040 */
#define PPC_PPC_R_ATT17                         ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[17])                       /* 0x42026044 */
#define PPC_PPC_R_ATT18                         ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[18])                       /* 0x42026048 */
#define PPC_PPC_R_ATT19                         ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[19])                       /* 0x4202604C */
#define PPC_PPC_R_ATT20                         ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[20])                       /* 0x42026050 */
#define PPC_PPC_R_ATT21                         ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[21])                       /* 0x42026054 */
#define PPC_PPC_R_ATT22                         ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[22])                       /* 0x42026058 */
#define PPC_PPC_R_ATT23                         ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[23])                       /* 0x4202605C */
#define PPC_PPC_R_ATT24                         ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[24])                       /* 0x42026060 */
#define PPC_PPC_R_ATT25                         ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[25])                       /* 0x42026064 */
#define PPC_PPC_R_ATT26                         ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[26])                       /* 0x42026068 */
#define PPC_PPC_R_ATT27                         ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[27])                       /* 0x4202606C */
#define PPC_PPC_R_ATT28                         ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[28])                       /* 0x42026070 */
#define PPC_PPC_R_ATT29                         ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[29])                       /* 0x42026074 */
#define PPC_PPC_R_ATT30                         ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[30])                       /* 0x42026078 */
#define PPC_PPC_R_ATT31                         ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[31])                       /* 0x4202607C */
#define PPC_PPC_R_ATT32                         ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[32])                       /* 0x42026080 */
#define PPC_PPC_R_ATT33                         ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[33])                       /* 0x42026084 */
#define PPC_PPC_R_ATT34                         ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[34])                       /* 0x42026088 */
#define PPC_PPC_R_ATT35                         ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[35])                       /* 0x4202608C */
#define PPC_PPC_R_ATT36                         ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[36])                       /* 0x42026090 */
#define PPC_PPC_R_ATT37                         ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[37])                       /* 0x42026094 */
#define PPC_PPC_R_ATT38                         ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[38])                       /* 0x42026098 */
#define PPC_PPC_R_ATT39                         ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[39])                       /* 0x4202609C */
#define PPC_PPC_R_ATT40                         ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[40])                       /* 0x420260A0 */
#define PPC_PPC_R_ATT41                         ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[41])                       /* 0x420260A4 */
#define PPC_PPC_R_ATT42                         ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[42])                       /* 0x420260A8 */
#define PPC_PPC_R_ATT43                         ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[43])                       /* 0x420260AC */
#define PPC_PPC_R_ATT44                         ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[44])                       /* 0x420260B0 */
#define PPC_PPC_R_ATT45                         ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[45])                       /* 0x420260B4 */
#define PPC_PPC_R_ATT46                         ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[46])                       /* 0x420260B8 */
#define PPC_PPC_R_ATT47                         ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[47])                       /* 0x420260BC */
#define PPC_PPC_R_ATT48                         ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[48])                       /* 0x420260C0 */
#define PPC_PPC_R_ATT49                         ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[49])                       /* 0x420260C4 */
#define PPC_PPC_R_ATT50                         ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[50])                       /* 0x420260C8 */
#define PPC_PPC_R_ATT51                         ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[51])                       /* 0x420260CC */
#define PPC_PPC_R_ATT52                         ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[52])                       /* 0x420260D0 */
#define PPC_PPC_R_ATT53                         ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[53])                       /* 0x420260D4 */
#define PPC_PPC_R_ATT54                         ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[54])                       /* 0x420260D8 */
#define PPC_PPC_R_ATT55                         ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[55])                       /* 0x420260DC */
#define PPC_PPC_R_ATT56                         ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[56])                       /* 0x420260E0 */
#define PPC_PPC_R_ATT57                         ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[57])                       /* 0x420260E4 */
#define PPC_PPC_R_ATT58                         ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[58])                       /* 0x420260E8 */
#define PPC_PPC_R_ATT59                         ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[59])                       /* 0x420260EC */
#define PPC_PPC_R_ATT60                         ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[60])                       /* 0x420260F0 */
#define PPC_PPC_R_ATT61                         ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[61])                       /* 0x420260F4 */
#define PPC_PPC_R_ATT62                         ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[62])                       /* 0x420260F8 */
#define PPC_PPC_R_ATT63                         ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[63])                       /* 0x420260FC */
#define PPC_PPC_R_ATT64                         ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[64])                       /* 0x42026100 */
#define PPC_PPC_R_ATT65                         ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[65])                       /* 0x42026104 */
#define PPC_PPC_R_ATT66                         ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[66])                       /* 0x42026108 */
#define PPC_PPC_R_ATT67                         ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[67])                       /* 0x4202610C */
#define PPC_PPC_R_ATT68                         ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[68])                       /* 0x42026110 */
#define PPC_PPC_R_ATT69                         ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[69])                       /* 0x42026114 */
#define PPC_PPC_R_ATT70                         ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[70])                       /* 0x42026118 */
#define PPC_PPC_R_ATT71                         ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[71])                       /* 0x4202611C */
#define PPC_PPC_R_ATT72                         ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[72])                       /* 0x42026120 */
#define PPC_PPC_R_ATT73                         ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[73])                       /* 0x42026124 */
#define PPC_PPC_R_ATT74                         ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[74])                       /* 0x42026128 */
#define PPC_PPC_R_ATT75                         ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[75])                       /* 0x4202612C */
#define PPC_PPC_R_ATT76                         ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[76])                       /* 0x42026130 */
#define PPC_PPC_R_ATT77                         ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[77])                       /* 0x42026134 */
#define PPC_PPC_R_ATT78                         ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[78])                       /* 0x42026138 */
#define PPC_PPC_R_ATT79                         ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[79])                       /* 0x4202613C */
#define PPC_PPC_R_ATT80                         ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[80])                       /* 0x42026140 */
#define PPC_PPC_R_ATT81                         ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[81])                       /* 0x42026144 */
#define PPC_PPC_R_ATT82                         ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[82])                       /* 0x42026148 */
#define PPC_PPC_R_ATT83                         ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[83])                       /* 0x4202614C */
#define PPC_PPC_R_ATT84                         ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[84])                       /* 0x42026150 */
#define PPC_PPC_R_ATT85                         ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[85])                       /* 0x42026154 */
#define PPC_PPC_R_ATT86                         ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[86])                       /* 0x42026158 */
#define PPC_PPC_R_ATT87                         ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[87])                       /* 0x4202615C */
#define PPC_PPC_R_ATT88                         ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[88])                       /* 0x42026160 */
#define PPC_PPC_R_ATT89                         ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[89])                       /* 0x42026164 */
#define PPC_PPC_R_ATT90                         ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[90])                       /* 0x42026168 */
#define PPC_PPC_R_ATT91                         ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[91])                       /* 0x4202616C */
#define PPC_PPC_R_ATT92                         ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[92])                       /* 0x42026170 */
#define PPC_PPC_R_ATT93                         ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[93])                       /* 0x42026174 */
#define PPC_PPC_R_ATT94                         ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[94])                       /* 0x42026178 */
#define PPC_PPC_R_ATT95                         ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[95])                       /* 0x4202617C */
#define PPC_PPC_R_ATT96                         ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[96])                       /* 0x42026180 */
#define PPC_PPC_R_ATT97                         ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[97])                       /* 0x42026184 */
#define PPC_PPC_R_ATT98                         ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[98])                       /* 0x42026188 */
#define PPC_PPC_R_ATT99                         ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[99])                       /* 0x4202618C */
#define PPC_PPC_R_ATT100                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[100])                      /* 0x42026190 */
#define PPC_PPC_R_ATT101                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[101])                      /* 0x42026194 */
#define PPC_PPC_R_ATT102                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[102])                      /* 0x42026198 */
#define PPC_PPC_R_ATT103                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[103])                      /* 0x4202619C */
#define PPC_PPC_R_ATT104                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[104])                      /* 0x420261A0 */
#define PPC_PPC_R_ATT105                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[105])                      /* 0x420261A4 */
#define PPC_PPC_R_ATT106                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[106])                      /* 0x420261A8 */
#define PPC_PPC_R_ATT107                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[107])                      /* 0x420261AC */
#define PPC_PPC_R_ATT108                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[108])                      /* 0x420261B0 */
#define PPC_PPC_R_ATT109                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[109])                      /* 0x420261B4 */
#define PPC_PPC_R_ATT110                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[110])                      /* 0x420261B8 */
#define PPC_PPC_R_ATT111                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[111])                      /* 0x420261BC */
#define PPC_PPC_R_ATT112                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[112])                      /* 0x420261C0 */
#define PPC_PPC_R_ATT113                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[113])                      /* 0x420261C4 */
#define PPC_PPC_R_ATT114                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[114])                      /* 0x420261C8 */
#define PPC_PPC_R_ATT115                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[115])                      /* 0x420261CC */
#define PPC_PPC_R_ATT116                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[116])                      /* 0x420261D0 */
#define PPC_PPC_R_ATT117                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[117])                      /* 0x420261D4 */
#define PPC_PPC_R_ATT118                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[118])                      /* 0x420261D8 */
#define PPC_PPC_R_ATT119                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[119])                      /* 0x420261DC */
#define PPC_PPC_R_ATT120                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[120])                      /* 0x420261E0 */
#define PPC_PPC_R_ATT121                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[121])                      /* 0x420261E4 */
#define PPC_PPC_R_ATT122                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[122])                      /* 0x420261E8 */
#define PPC_PPC_R_ATT123                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[123])                      /* 0x420261EC */
#define PPC_PPC_R_ATT124                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[124])                      /* 0x420261F0 */
#define PPC_PPC_R_ATT125                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[125])                      /* 0x420261F4 */
#define PPC_PPC_R_ATT126                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[126])                      /* 0x420261F8 */
#define PPC_PPC_R_ATT127                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[127])                      /* 0x420261FC */
#define PPC_PPC_R_ATT128                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[128])                      /* 0x42026200 */
#define PPC_PPC_R_ATT129                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[129])                      /* 0x42026204 */
#define PPC_PPC_R_ATT130                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[130])                      /* 0x42026208 */
#define PPC_PPC_R_ATT131                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[131])                      /* 0x4202620C */
#define PPC_PPC_R_ATT132                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[132])                      /* 0x42026210 */
#define PPC_PPC_R_ATT133                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[133])                      /* 0x42026214 */
#define PPC_PPC_R_ATT134                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[134])                      /* 0x42026218 */
#define PPC_PPC_R_ATT135                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[135])                      /* 0x4202621C */
#define PPC_PPC_R_ATT136                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[136])                      /* 0x42026220 */
#define PPC_PPC_R_ATT137                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[137])                      /* 0x42026224 */
#define PPC_PPC_R_ATT138                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[138])                      /* 0x42026228 */
#define PPC_PPC_R_ATT139                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[139])                      /* 0x4202622C */
#define PPC_PPC_R_ATT140                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[140])                      /* 0x42026230 */
#define PPC_PPC_R_ATT141                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[141])                      /* 0x42026234 */
#define PPC_PPC_R_ATT142                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[142])                      /* 0x42026238 */
#define PPC_PPC_R_ATT143                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[143])                      /* 0x4202623C */
#define PPC_PPC_R_ATT144                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[144])                      /* 0x42026240 */
#define PPC_PPC_R_ATT145                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[145])                      /* 0x42026244 */
#define PPC_PPC_R_ATT146                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[146])                      /* 0x42026248 */
#define PPC_PPC_R_ATT147                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[147])                      /* 0x4202624C */
#define PPC_PPC_R_ATT148                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[148])                      /* 0x42026250 */
#define PPC_PPC_R_ATT149                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[149])                      /* 0x42026254 */
#define PPC_PPC_R_ATT150                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[150])                      /* 0x42026258 */
#define PPC_PPC_R_ATT151                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[151])                      /* 0x4202625C */
#define PPC_PPC_R_ATT152                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[152])                      /* 0x42026260 */
#define PPC_PPC_R_ATT153                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[153])                      /* 0x42026264 */
#define PPC_PPC_R_ATT154                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[154])                      /* 0x42026268 */
#define PPC_PPC_R_ATT155                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[155])                      /* 0x4202626C */
#define PPC_PPC_R_ATT156                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[156])                      /* 0x42026270 */
#define PPC_PPC_R_ATT157                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[157])                      /* 0x42026274 */
#define PPC_PPC_R_ATT158                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[158])                      /* 0x42026278 */
#define PPC_PPC_R_ATT159                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[159])                      /* 0x4202627C */
#define PPC_PPC_R_ATT160                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[160])                      /* 0x42026280 */
#define PPC_PPC_R_ATT161                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[161])                      /* 0x42026284 */
#define PPC_PPC_R_ATT162                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[162])                      /* 0x42026288 */
#define PPC_PPC_R_ATT163                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[163])                      /* 0x4202628C */
#define PPC_PPC_R_ATT164                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[164])                      /* 0x42026290 */
#define PPC_PPC_R_ATT165                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[165])                      /* 0x42026294 */
#define PPC_PPC_R_ATT166                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[166])                      /* 0x42026298 */
#define PPC_PPC_R_ATT167                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[167])                      /* 0x4202629C */
#define PPC_PPC_R_ATT168                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[168])                      /* 0x420262A0 */
#define PPC_PPC_R_ATT169                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[169])                      /* 0x420262A4 */
#define PPC_PPC_R_ATT170                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[170])                      /* 0x420262A8 */
#define PPC_PPC_R_ATT171                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[171])                      /* 0x420262AC */
#define PPC_PPC_R_ATT172                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[172])                      /* 0x420262B0 */
#define PPC_PPC_R_ATT173                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[173])                      /* 0x420262B4 */
#define PPC_PPC_R_ATT174                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[174])                      /* 0x420262B8 */
#define PPC_PPC_R_ATT175                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[175])                      /* 0x420262BC */
#define PPC_PPC_R_ATT176                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[176])                      /* 0x420262C0 */
#define PPC_PPC_R_ATT177                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[177])                      /* 0x420262C4 */
#define PPC_PPC_R_ATT178                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[178])                      /* 0x420262C8 */
#define PPC_PPC_R_ATT179                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[179])                      /* 0x420262CC */
#define PPC_PPC_R_ATT180                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[180])                      /* 0x420262D0 */
#define PPC_PPC_R_ATT181                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[181])                      /* 0x420262D4 */
#define PPC_PPC_R_ATT182                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[182])                      /* 0x420262D8 */
#define PPC_PPC_R_ATT183                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[183])                      /* 0x420262DC */
#define PPC_PPC_R_ATT184                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[184])                      /* 0x420262E0 */
#define PPC_PPC_R_ATT185                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[185])                      /* 0x420262E4 */
#define PPC_PPC_R_ATT186                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[186])                      /* 0x420262E8 */
#define PPC_PPC_R_ATT187                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[187])                      /* 0x420262EC */
#define PPC_PPC_R_ATT188                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[188])                      /* 0x420262F0 */
#define PPC_PPC_R_ATT189                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[189])                      /* 0x420262F4 */
#define PPC_PPC_R_ATT190                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[190])                      /* 0x420262F8 */
#define PPC_PPC_R_ATT191                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[191])                      /* 0x420262FC */
#define PPC_PPC_R_ATT192                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[192])                      /* 0x42026300 */
#define PPC_PPC_R_ATT193                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[193])                      /* 0x42026304 */
#define PPC_PPC_R_ATT194                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[194])                      /* 0x42026308 */
#define PPC_PPC_R_ATT195                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[195])                      /* 0x4202630C */
#define PPC_PPC_R_ATT196                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[196])                      /* 0x42026310 */
#define PPC_PPC_R_ATT197                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[197])                      /* 0x42026314 */
#define PPC_PPC_R_ATT198                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[198])                      /* 0x42026318 */
#define PPC_PPC_R_ATT199                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[199])                      /* 0x4202631C */
#define PPC_PPC_R_ATT200                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[200])                      /* 0x42026320 */
#define PPC_PPC_R_ATT201                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[201])                      /* 0x42026324 */
#define PPC_PPC_R_ATT202                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[202])                      /* 0x42026328 */
#define PPC_PPC_R_ATT203                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[203])                      /* 0x4202632C */
#define PPC_PPC_R_ATT204                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[204])                      /* 0x42026330 */
#define PPC_PPC_R_ATT205                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[205])                      /* 0x42026334 */
#define PPC_PPC_R_ATT206                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[206])                      /* 0x42026338 */
#define PPC_PPC_R_ATT207                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[207])                      /* 0x4202633C */
#define PPC_PPC_R_ATT208                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[208])                      /* 0x42026340 */
#define PPC_PPC_R_ATT209                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[209])                      /* 0x42026344 */
#define PPC_PPC_R_ATT210                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[210])                      /* 0x42026348 */
#define PPC_PPC_R_ATT211                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[211])                      /* 0x4202634C */
#define PPC_PPC_R_ATT212                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[212])                      /* 0x42026350 */
#define PPC_PPC_R_ATT213                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[213])                      /* 0x42026354 */
#define PPC_PPC_R_ATT214                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[214])                      /* 0x42026358 */
#define PPC_PPC_R_ATT215                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[215])                      /* 0x4202635C */
#define PPC_PPC_R_ATT216                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[216])                      /* 0x42026360 */
#define PPC_PPC_R_ATT217                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[217])                      /* 0x42026364 */
#define PPC_PPC_R_ATT218                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[218])                      /* 0x42026368 */
#define PPC_PPC_R_ATT219                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[219])                      /* 0x4202636C */
#define PPC_PPC_R_ATT220                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[220])                      /* 0x42026370 */
#define PPC_PPC_R_ATT221                        ((PPC_PPC_R_ATT_Type*) &PPC->PPC.R_ATT[221])                      /* 0x42026374 */

/*******************************************************************************
*                                  PERI_PCLK
*******************************************************************************/

#define PERI_PCLK_BASE                          0x42040000UL
#define PERI_PCLK                               ((PERI_PCLK_Type*) PERI_PCLK_BASE)                                /* 0x42040000 */
#define PERI_PCLK_GR0                           ((PERI_PCLK_GR_Type*) &PERI_PCLK->GR[0])                          /* 0x42040000 */
#define PERI_PCLK_GR1                           ((PERI_PCLK_GR_Type*) &PERI_PCLK->GR[1])                          /* 0x42042000 */
#define PERI_PCLK_GR2                           ((PERI_PCLK_GR_Type*) &PERI_PCLK->GR[2])                          /* 0x42044000 */
#define PERI_PCLK_GR3                           ((PERI_PCLK_GR_Type*) &PERI_PCLK->GR[3])                          /* 0x42046000 */
#define PERI_PCLK_GR4                           ((PERI_PCLK_GR_Type*) &PERI_PCLK->GR[4])                          /* 0x42048000 */
#define PERI_PCLK_GR5                           ((PERI_PCLK_GR_Type*) &PERI_PCLK->GR[5])                          /* 0x4204A000 */
#define PERI_PCLK_GR6                           ((PERI_PCLK_GR_Type*) &PERI_PCLK->GR[6])                          /* 0x4204C000 */

/*******************************************************************************
*                                   RAMC_PPU
*******************************************************************************/

#define RAMC_PPU0_BASE                          0x42100000UL
#define RAMC_PPU0                               ((RAMC_PPU_Type*) RAMC_PPU0_BASE)                                 /* 0x42100000 */

/*******************************************************************************
*                                    ICACHE
*******************************************************************************/

#define ICACHE0_BASE                            0x42103000UL
#define ICACHE0                                 ((ICACHE_Type*) ICACHE0_BASE)                                     /* 0x42103000 */

/*******************************************************************************
*                                  CPUSS_PPU
*******************************************************************************/

#define CPUSS_PPU_BASE                          0x42105000UL
#define CPUSS_PPU                               ((CPUSS_PPU_Type*) CPUSS_PPU_BASE)                                /* 0x42105000 */

/*******************************************************************************
*                                     RAMC
*******************************************************************************/

#define RAMC0_BASE                              0x42110000UL
#define RAMC0                                   ((RAMC_Type*) RAMC0_BASE)                                         /* 0x42110000 */
#define RAMC0_MPC0                              ((RAMC_MPC_Type*) &RAMC0->MPC[0])                                 /* 0x42114000 */

/*******************************************************************************
*                                    PROMC
*******************************************************************************/

#define PROMC_BASE                              0x42140000UL
#define PROMC                                   ((PROMC_Type*) PROMC_BASE)                                        /* 0x42140000 */
#define PROMC_MPC0                              ((PROMC_MPC_Type*) &PROMC->MPC[0])                                /* 0x42141000 */

/*******************************************************************************
*                                    FLASHC
*******************************************************************************/

#define FLASHC_BASE                             0x42150000UL
#define FLASHC                                  ((FLASHC_Type*) FLASHC_BASE)                                      /* 0x42150000 */
#define FLASHC_MPC0                             ((FLASHC_MPC_Type*) &FLASHC->MPC[0])                              /* 0x42151000 */
#define FLASHC_FM_CTL                           ((FLASHC_FM_CTL_Type*) &FLASHC->FM_CTL)                           /* 0x42152000 */

/*******************************************************************************
*                                    MXCM33
*******************************************************************************/

#define MXCM33_BASE                             0x42160000UL
#define MXCM33                                  ((MXCM33_Type*) MXCM33_BASE)                                      /* 0x42160000 */

/*******************************************************************************
*                                      DW
*******************************************************************************/

#define DW0_BASE                                0x42180000UL
#define DW1_BASE                                0x42190000UL
#define DW0                                     ((DW_Type*) DW0_BASE)                                             /* 0x42180000 */
#define DW1                                     ((DW_Type*) DW1_BASE)                                             /* 0x42190000 */
#define DW0_CH_STRUCT0                          ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[0])                         /* 0x42188000 */
#define DW0_CH_STRUCT1                          ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[1])                         /* 0x42188040 */
#define DW0_CH_STRUCT2                          ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[2])                         /* 0x42188080 */
#define DW0_CH_STRUCT3                          ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[3])                         /* 0x421880C0 */
#define DW0_CH_STRUCT4                          ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[4])                         /* 0x42188100 */
#define DW0_CH_STRUCT5                          ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[5])                         /* 0x42188140 */
#define DW0_CH_STRUCT6                          ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[6])                         /* 0x42188180 */
#define DW0_CH_STRUCT7                          ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[7])                         /* 0x421881C0 */
#define DW0_CH_STRUCT8                          ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[8])                         /* 0x42188200 */
#define DW0_CH_STRUCT9                          ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[9])                         /* 0x42188240 */
#define DW0_CH_STRUCT10                         ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[10])                        /* 0x42188280 */
#define DW0_CH_STRUCT11                         ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[11])                        /* 0x421882C0 */
#define DW0_CH_STRUCT12                         ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[12])                        /* 0x42188300 */
#define DW0_CH_STRUCT13                         ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[13])                        /* 0x42188340 */
#define DW0_CH_STRUCT14                         ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[14])                        /* 0x42188380 */
#define DW0_CH_STRUCT15                         ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[15])                        /* 0x421883C0 */
#define DW1_CH_STRUCT0                          ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[0])                         /* 0x42198000 */
#define DW1_CH_STRUCT1                          ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[1])                         /* 0x42198040 */
#define DW1_CH_STRUCT2                          ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[2])                         /* 0x42198080 */
#define DW1_CH_STRUCT3                          ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[3])                         /* 0x421980C0 */
#define DW1_CH_STRUCT4                          ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[4])                         /* 0x42198100 */
#define DW1_CH_STRUCT5                          ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[5])                         /* 0x42198140 */
#define DW1_CH_STRUCT6                          ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[6])                         /* 0x42198180 */
#define DW1_CH_STRUCT7                          ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[7])                         /* 0x421981C0 */
#define DW1_CH_STRUCT8                          ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[8])                         /* 0x42198200 */
#define DW1_CH_STRUCT9                          ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[9])                         /* 0x42198240 */
#define DW1_CH_STRUCT10                         ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[10])                        /* 0x42198280 */
#define DW1_CH_STRUCT11                         ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[11])                        /* 0x421982C0 */
#define DW1_CH_STRUCT12                         ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[12])                        /* 0x42198300 */
#define DW1_CH_STRUCT13                         ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[13])                        /* 0x42198340 */
#define DW1_CH_STRUCT14                         ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[14])                        /* 0x42198380 */
#define DW1_CH_STRUCT15                         ((DW_CH_STRUCT_Type*) &DW1->CH_STRUCT[15])                        /* 0x421983C0 */

/*******************************************************************************
*                                    CPUSS
*******************************************************************************/

#define CPUSS_BASE                              0x421C0000UL
#define CPUSS                                   ((CPUSS_Type*) CPUSS_BASE)                                        /* 0x421C0000 */

/*******************************************************************************
*                                  MS_CTL_2_1
*******************************************************************************/

#define MS_CTL_2_1_BASE                         0x421C4000UL
#define MS_CTL_2_1                              ((MS_CTL_2_1_Type*) MS_CTL_2_1_BASE)                              /* 0x421C4000 */
#define MS0                                     ((MS_Type*) &MS_CTL_2_1->MS[0])                                   /* 0x421C4000 */
#define MS4                                     ((MS_Type*) &MS_CTL_2_1->MS[4])                                   /* 0x421C4040 */
#define MS5                                     ((MS_Type*) &MS_CTL_2_1->MS[5])                                   /* 0x421C4050 */
#define MS7                                     ((MS_Type*) &MS_CTL_2_1->MS[7])                                   /* 0x421C4070 */
#define MS31                                    ((MS_Type*) &MS_CTL_2_1->MS[31])                                  /* 0x421C41F0 */
#define MS_PC0                                  ((MS_PC_Type*) &MS_CTL_2_1->MS_PC[0])                             /* 0x421C5000 */
#define MS_PC4                                  ((MS_PC_Type*) &MS_CTL_2_1->MS_PC[4])                             /* 0x421C5040 */
#define MS_PC5                                  ((MS_PC_Type*) &MS_CTL_2_1->MS_PC[5])                             /* 0x421C5050 */
#define MS_PC7                                  ((MS_PC_Type*) &MS_CTL_2_1->MS_PC[7])                             /* 0x421C5070 */
#define MS_PC31                                 ((MS_PC_Type*) &MS_CTL_2_1->MS_PC[31])                            /* 0x421C51F0 */

/*******************************************************************************
*                                 CPUSS_SL_CTL
*******************************************************************************/

#define CPUSS_SL_CTL_BASE                       0x421C8000UL
#define CPUSS_SL_CTL                            ((CPUSS_SL_CTL_Type*) CPUSS_SL_CTL_BASE)                          /* 0x421C8000 */

/*******************************************************************************
*                                     IPC
*******************************************************************************/

#define IPC_BASE                                0x421D0000UL
#define IPC                                     ((IPC_Type*) IPC_BASE)                                            /* 0x421D0000 */
#define IPC_STRUCT0                             ((IPC_STRUCT_Type*) &IPC->STRUCT[0])                              /* 0x421D0000 */
#define IPC_STRUCT1                             ((IPC_STRUCT_Type*) &IPC->STRUCT[1])                              /* 0x421D0020 */
#define IPC_STRUCT2                             ((IPC_STRUCT_Type*) &IPC->STRUCT[2])                              /* 0x421D0040 */
#define IPC_STRUCT3                             ((IPC_STRUCT_Type*) &IPC->STRUCT[3])                              /* 0x421D0060 */
#define IPC_INTR_STRUCT0                        ((IPC_INTR_STRUCT_Type*) &IPC->INTR_STRUCT[0])                    /* 0x421D1000 */
#define IPC_INTR_STRUCT1                        ((IPC_INTR_STRUCT_Type*) &IPC->INTR_STRUCT[1])                    /* 0x421D1020 */

/*******************************************************************************
*                                    FAULT
*******************************************************************************/

#define FAULT_BASE                              0x421E0000UL
#define FAULT                                   ((FAULT_Type*) FAULT_BASE)                                        /* 0x421E0000 */
#define FAULT_STRUCT0                           ((FAULT_STRUCT_Type*) &FAULT->STRUCT[0])                          /* 0x421E0000 */

/*******************************************************************************
*                                     SRSS
*******************************************************************************/

#define SRSS_BASE                               0x42200000UL
#define SRSS                                    ((SRSS_Type*) SRSS_BASE)                                          /* 0x42200000 */
#define CSV_HF                                  ((CSV_HF_Type*) &SRSS->CSV_HF_STRUCT)                             /* 0x42201400 */
#define CSV_HF_CSV0                             ((CSV_HF_CSV_Type*) &SRSS->CSV_HF_STRUCT.CSV[0])                  /* 0x42201400 */
#define CSV_HF_CSV1                             ((CSV_HF_CSV_Type*) &SRSS->CSV_HF_STRUCT.CSV[1])                  /* 0x42201410 */
#define CSV_HF_CSV2                             ((CSV_HF_CSV_Type*) &SRSS->CSV_HF_STRUCT.CSV[2])                  /* 0x42201420 */
#define CSV_HF_CSV3                             ((CSV_HF_CSV_Type*) &SRSS->CSV_HF_STRUCT.CSV[3])                  /* 0x42201430 */
#define CSV_HF_CSV4                             ((CSV_HF_CSV_Type*) &SRSS->CSV_HF_STRUCT.CSV[4])                  /* 0x42201440 */
#define CSV_HF_CSV5                             ((CSV_HF_CSV_Type*) &SRSS->CSV_HF_STRUCT.CSV[5])                  /* 0x42201450 */
#define CSV_HF_CSV6                             ((CSV_HF_CSV_Type*) &SRSS->CSV_HF_STRUCT.CSV[6])                  /* 0x42201460 */
#define CSV_REF                                 ((CSV_REF_Type*) &SRSS->CSV_REF_STRUCT)                           /* 0x42201710 */
#define CSV_REF_CSV                             ((CSV_REF_CSV_Type*) &SRSS->CSV_REF_STRUCT.CSV)                   /* 0x42201710 */
#define CSV_LF                                  ((CSV_LF_Type*) &SRSS->CSV_LF_STRUCT)                             /* 0x42201720 */
#define CSV_LF_CSV                              ((CSV_LF_CSV_Type*) &SRSS->CSV_LF_STRUCT.CSV)                     /* 0x42201720 */
#define CSV_ILO                                 ((CSV_ILO_Type*) &SRSS->CSV_ILO_STRUCT)                           /* 0x42201730 */
#define CSV_ILO_CSV                             ((CSV_ILO_CSV_Type*) &SRSS->CSV_ILO_STRUCT.CSV)                   /* 0x42201730 */
#define CLK_DPLL_LP0                            ((CLK_DPLL_LP_Type*) &SRSS->CLK_DPLL_LP[0])                       /* 0x42201A00 */
#define CLK_DPLL_LP1                            ((CLK_DPLL_LP_Type*) &SRSS->CLK_DPLL_LP[1])                       /* 0x42201A20 */
#define RAM_TRIM                                ((RAM_TRIM_Type*) &SRSS->RAM_TRIM_STRUCT)                         /* 0x42204000 */
#define CLK_TRIM_DPLL_LP0                       ((CLK_TRIM_DPLL_LP_Type*) &SRSS->CLK_TRIM_DPLL_LP[0])             /* 0x42204200 */
#define CLK_TRIM_DPLL_LP1                       ((CLK_TRIM_DPLL_LP_Type*) &SRSS->CLK_TRIM_DPLL_LP[1])             /* 0x42204220 */
#define MCWDT_STRUCT0                           ((MCWDT_STRUCT_Type*) &SRSS->MCWDT_STRUCT[0])                     /* 0x4220D000 */

/*******************************************************************************
*                                   PWRMODE
*******************************************************************************/

#define PWRMODE_BASE                            0x42210000UL
#define PWRMODE                                 ((PWRMODE_Type*) PWRMODE_BASE)                                    /* 0x42210000 */
#define PWRMODE_PD0                             ((PWRMODE_PD_Type*) &PWRMODE->PD[0])                              /* 0x42210000 */
#define PWRMODE_PD1                             ((PWRMODE_PD_Type*) &PWRMODE->PD[1])                              /* 0x42210010 */
#define PWRMODE_PD2                             ((PWRMODE_PD_Type*) &PWRMODE->PD[2])                              /* 0x42210020 */
#define PWRMODE_PD3                             ((PWRMODE_PD_Type*) &PWRMODE->PD[3])                              /* 0x42210030 */
#define PWRMODE_PD4                             ((PWRMODE_PD_Type*) &PWRMODE->PD[4])                              /* 0x42210040 */
#define PWRMODE_PD5                             ((PWRMODE_PD_Type*) &PWRMODE->PD[5])                              /* 0x42210050 */
#define PWRMODE_PD6                             ((PWRMODE_PD_Type*) &PWRMODE->PD[6])                              /* 0x42210060 */
#define PWRMODE_PD7                             ((PWRMODE_PD_Type*) &PWRMODE->PD[7])                              /* 0x42210070 */
#define PWRMODE_PD8                             ((PWRMODE_PD_Type*) &PWRMODE->PD[8])                              /* 0x42210080 */
#define PWRMODE_PD9                             ((PWRMODE_PD_Type*) &PWRMODE->PD[9])                              /* 0x42210090 */
#define PWRMODE_PD10                            ((PWRMODE_PD_Type*) &PWRMODE->PD[10])                             /* 0x422100A0 */
#define PWRMODE_PD11                            ((PWRMODE_PD_Type*) &PWRMODE->PD[11])                             /* 0x422100B0 */
#define PWRMODE_PD12                            ((PWRMODE_PD_Type*) &PWRMODE->PD[12])                             /* 0x422100C0 */
#define PWRMODE_PD13                            ((PWRMODE_PD_Type*) &PWRMODE->PD[13])                             /* 0x422100D0 */
#define PWRMODE_PD14                            ((PWRMODE_PD_Type*) &PWRMODE->PD[14])                             /* 0x422100E0 */
#define PWRMODE_PD15                            ((PWRMODE_PD_Type*) &PWRMODE->PD[15])                             /* 0x422100F0 */
#define PWRMODE_PPU_MAIN                        ((PWRMODE_PPU_MAIN_Type*) &PWRMODE->PPU_MAIN)                     /* 0x42211000 */
#define PWRMODE_PPU_MAIN_PPU_MAIN               ((PWRMODE_PPU_MAIN_PPU_MAIN_Type*) &PWRMODE->PPU_MAIN.PPU_MAIN)   /* 0x42211000 */

/*******************************************************************************
*                                    BACKUP
*******************************************************************************/

#define BACKUP_BASE                             0x42220000UL
#define BACKUP                                  ((BACKUP_Type*) BACKUP_BASE)                                      /* 0x42220000 */

/*******************************************************************************
*                                  CRYPTOLITE
*******************************************************************************/

#define CRYPTOLITE_BASE                         0x42230000UL
#define CRYPTOLITE                              ((CRYPTOLITE_Type*) CRYPTOLITE_BASE)                              /* 0x42230000 */

/*******************************************************************************
*                                   DEBUG600
*******************************************************************************/

#define DEBUG600_BASE                           0x42250000UL
#define DEBUG600                                ((DEBUG600_Type*) DEBUG600_BASE)                                  /* 0x42250000 */

/*******************************************************************************
*                                    HSIOM
*******************************************************************************/

#define HSIOM_BASE                              0x42400000UL
#define HSIOM                                   ((HSIOM_Type*) HSIOM_BASE)                                        /* 0x42400000 */
#define HSIOM_PRT0                              ((HSIOM_PRT_Type*) &HSIOM->PRT[0])                                /* 0x42400000 */
#define HSIOM_PRT1                              ((HSIOM_PRT_Type*) &HSIOM->PRT[1])                                /* 0x42400010 */
#define HSIOM_PRT2                              ((HSIOM_PRT_Type*) &HSIOM->PRT[2])                                /* 0x42400020 */
#define HSIOM_PRT3                              ((HSIOM_PRT_Type*) &HSIOM->PRT[3])                                /* 0x42400030 */
#define HSIOM_PRT4                              ((HSIOM_PRT_Type*) &HSIOM->PRT[4])                                /* 0x42400040 */
#define HSIOM_PRT5                              ((HSIOM_PRT_Type*) &HSIOM->PRT[5])                                /* 0x42400050 */
#define HSIOM_PRT6                              ((HSIOM_PRT_Type*) &HSIOM->PRT[6])                                /* 0x42400060 */
#define HSIOM_PRT7                              ((HSIOM_PRT_Type*) &HSIOM->PRT[7])                                /* 0x42400070 */
#define HSIOM_PRT8                              ((HSIOM_PRT_Type*) &HSIOM->PRT[8])                                /* 0x42400080 */
#define HSIOM_PRT9                              ((HSIOM_PRT_Type*) &HSIOM->PRT[9])                                /* 0x42400090 */
#define HSIOM_SECURE_PRT0                       ((HSIOM_SECURE_PRT_Type*) &HSIOM->SECURE_PRT[0])                  /* 0x42401000 */
#define HSIOM_SECURE_PRT1                       ((HSIOM_SECURE_PRT_Type*) &HSIOM->SECURE_PRT[1])                  /* 0x42401010 */
#define HSIOM_SECURE_PRT2                       ((HSIOM_SECURE_PRT_Type*) &HSIOM->SECURE_PRT[2])                  /* 0x42401020 */
#define HSIOM_SECURE_PRT3                       ((HSIOM_SECURE_PRT_Type*) &HSIOM->SECURE_PRT[3])                  /* 0x42401030 */
#define HSIOM_SECURE_PRT4                       ((HSIOM_SECURE_PRT_Type*) &HSIOM->SECURE_PRT[4])                  /* 0x42401040 */
#define HSIOM_SECURE_PRT5                       ((HSIOM_SECURE_PRT_Type*) &HSIOM->SECURE_PRT[5])                  /* 0x42401050 */
#define HSIOM_SECURE_PRT6                       ((HSIOM_SECURE_PRT_Type*) &HSIOM->SECURE_PRT[6])                  /* 0x42401060 */
#define HSIOM_SECURE_PRT7                       ((HSIOM_SECURE_PRT_Type*) &HSIOM->SECURE_PRT[7])                  /* 0x42401070 */
#define HSIOM_SECURE_PRT8                       ((HSIOM_SECURE_PRT_Type*) &HSIOM->SECURE_PRT[8])                  /* 0x42401080 */
#define HSIOM_SECURE_PRT9                       ((HSIOM_SECURE_PRT_Type*) &HSIOM->SECURE_PRT[9])                  /* 0x42401090 */

/*******************************************************************************
*                                     GPIO
*******************************************************************************/

#define GPIO_BASE                               0x42410000UL
#define GPIO                                    ((GPIO_Type*) GPIO_BASE)                                          /* 0x42410000 */
#define GPIO_PRT0                               ((GPIO_PRT_Type*) &GPIO->PRT[0])                                  /* 0x42410000 */
#define GPIO_PRT1                               ((GPIO_PRT_Type*) &GPIO->PRT[1])                                  /* 0x42410080 */
#define GPIO_PRT2                               ((GPIO_PRT_Type*) &GPIO->PRT[2])                                  /* 0x42410100 */
#define GPIO_PRT3                               ((GPIO_PRT_Type*) &GPIO->PRT[3])                                  /* 0x42410180 */
#define GPIO_PRT4                               ((GPIO_PRT_Type*) &GPIO->PRT[4])                                  /* 0x42410200 */
#define GPIO_PRT5                               ((GPIO_PRT_Type*) &GPIO->PRT[5])                                  /* 0x42410280 */
#define GPIO_PRT6                               ((GPIO_PRT_Type*) &GPIO->PRT[6])                                  /* 0x42410300 */
#define GPIO_PRT7                               ((GPIO_PRT_Type*) &GPIO->PRT[7])                                  /* 0x42410380 */
#define GPIO_PRT8                               ((GPIO_PRT_Type*) &GPIO->PRT[8])                                  /* 0x42410400 */
#define GPIO_PRT9                               ((GPIO_PRT_Type*) &GPIO->PRT[9])                                  /* 0x42410480 */

/*******************************************************************************
*                                   SMARTIO
*******************************************************************************/

#define SMARTIO_BASE                            0x42420000UL
#define SMARTIO                                 ((SMARTIO_Type*) SMARTIO_BASE)                                    /* 0x42420000 */
#define SMARTIO_PRT0                            ((SMARTIO_PRT_Type*) &SMARTIO->PRT[0])                            /* 0x42420000 */
#define SMARTIO_PRT1                            ((SMARTIO_PRT_Type*) &SMARTIO->PRT[1])                            /* 0x42420100 */
#define SMARTIO_PRT2                            ((SMARTIO_PRT_Type*) &SMARTIO->PRT[2])                            /* 0x42420200 */
#define SMARTIO_PRT3                            ((SMARTIO_PRT_Type*) &SMARTIO->PRT[3])                            /* 0x42420300 */
#define SMARTIO_PRT5                            ((SMARTIO_PRT_Type*) &SMARTIO->PRT[5])                            /* 0x42420500 */
#define SMARTIO_PRT6                            ((SMARTIO_PRT_Type*) &SMARTIO->PRT[6])                            /* 0x42420600 */
#define SMARTIO_PRT9                            ((SMARTIO_PRT_Type*) &SMARTIO->PRT[9])                            /* 0x42420900 */

/*******************************************************************************
*                                    LPCOMP
*******************************************************************************/

#define LPCOMP_BASE                             0x42430000UL
#define LPCOMP                                  ((LPCOMP_Type*) LPCOMP_BASE)                                      /* 0x42430000 */

/*******************************************************************************
*                                    EFUSE
*******************************************************************************/

#define EFUSE_BASE                              0x42610000UL
#define EFUSE                                   ((EFUSE_Type*) EFUSE_BASE)                                        /* 0x42610000 */

/*******************************************************************************
*                                    CANFD
*******************************************************************************/

#define CANFD0_BASE                             0x42800000UL
#define CANFD0                                  ((CANFD_Type*) CANFD0_BASE)                                       /* 0x42800000 */
#define CANFD0_CH0                              ((CANFD_CH_Type*) &CANFD0->CH[0])                                 /* 0x42800000 */
#define CANFD0_CH1                              ((CANFD_CH_Type*) &CANFD0->CH[1])                                 /* 0x42800200 */
#define CANFD0_CH0_M_TTCAN                      ((CANFD_CH_M_TTCAN_Type*) &CANFD0->CH[0].M_TTCAN)                 /* 0x42800000 */
#define CANFD0_CH1_M_TTCAN                      ((CANFD_CH_M_TTCAN_Type*) &CANFD0->CH[1].M_TTCAN)                 /* 0x42800200 */

/*******************************************************************************
*                                     SCB
*******************************************************************************/

#define SCB0_BASE                               0x42820000UL
#define SCB1_BASE                               0x42840000UL
#define SCB2_BASE                               0x42850000UL
#define SCB3_BASE                               0x42860000UL
#define SCB0                                    ((CySCB_Type*) SCB0_BASE)                                         /* 0x42820000 */
#define SCB1                                    ((CySCB_Type*) SCB1_BASE)                                         /* 0x42840000 */
#define SCB2                                    ((CySCB_Type*) SCB2_BASE)                                         /* 0x42850000 */
#define SCB3                                    ((CySCB_Type*) SCB3_BASE)                                         /* 0x42860000 */

/*******************************************************************************
*                                    TCPWM
*******************************************************************************/

#define TCPWM0_BASE                             0x42A00000UL
#define TCPWM0                                  ((TCPWM_Type*) TCPWM0_BASE)                                       /* 0x42A00000 */
#define TCPWM0_GRP0                             ((TCPWM_GRP_Type*) &TCPWM0->GRP[0])                               /* 0x42A00000 */
#define TCPWM0_GRP1                             ((TCPWM_GRP_Type*) &TCPWM0->GRP[1])                               /* 0x42A10000 */
#define TCPWM0_GRP2                             ((TCPWM_GRP_Type*) &TCPWM0->GRP[2])                               /* 0x42A20000 */
#define TCPWM0_GRP0_CNT0                        ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[0].CNT[0])                    /* 0x42A00000 */
#define TCPWM0_GRP0_CNT1                        ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[0].CNT[1])                    /* 0x42A00100 */
#define TCPWM0_GRP0_CNT2                        ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[0].CNT[2])                    /* 0x42A00200 */
#define TCPWM0_GRP0_CNT3                        ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[0].CNT[3])                    /* 0x42A00300 */
#define TCPWM0_GRP1_CNT0                        ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[1].CNT[0])                    /* 0x42A10000 */
#define TCPWM0_GRP1_CNT1                        ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[1].CNT[1])                    /* 0x42A10100 */
#define TCPWM0_GRP1_CNT2                        ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[1].CNT[2])                    /* 0x42A10200 */
#define TCPWM0_GRP1_CNT3                        ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[1].CNT[3])                    /* 0x42A10300 */
#define TCPWM0_GRP1_CNT4                        ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[1].CNT[4])                    /* 0x42A10400 */
#define TCPWM0_GRP1_CNT5                        ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[1].CNT[5])                    /* 0x42A10500 */
#define TCPWM0_GRP1_CNT6                        ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[1].CNT[6])                    /* 0x42A10600 */
#define TCPWM0_GRP1_CNT7                        ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[1].CNT[7])                    /* 0x42A10700 */
#define TCPWM0_GRP2_CNT0                        ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[2].CNT[0])                    /* 0x42A20000 */
#define TCPWM0_GRP2_CNT1                        ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[2].CNT[1])                    /* 0x42A20100 */
#define TCPWM0_GRP2_CNT2                        ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[2].CNT[2])                    /* 0x42A20200 */
#define TCPWM0_GRP2_CNT3                        ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[2].CNT[3])                    /* 0x42A20300 */
#define TCPWM0_GRP2_CNT4                        ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[2].CNT[4])                    /* 0x42A20400 */
#define TCPWM0_GRP2_CNT5                        ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[2].CNT[5])                    /* 0x42A20500 */
#define TCPWM0_GRP2_CNT6                        ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[2].CNT[6])                    /* 0x42A20600 */
#define TCPWM0_GRP2_CNT7                        ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[2].CNT[7])                    /* 0x42A20700 */
#define TCPWM0_TR_ALL_GF                        ((TCPWM_TR_ALL_GF_Type*) &TCPWM0->TR_ALL_GF)                      /* 0x42A80000 */
#define TCPWM0_TR_ALL_SYNC_BYPASS               ((TCPWM_TR_ALL_SYNC_BYPASS_Type*) &TCPWM0->TR_ALL_SYNC_BYPASS)    /* 0x42A90000 */
#define TCPWM0_MOTIF_GRP0                       ((TCPWM_MOTIF_GRP_Type*) &TCPWM0->MOTIF_GRP[0])                   /* 0x42AA0000 */
#define TCPWM0_MOTIF_GRP1                       ((TCPWM_MOTIF_GRP_Type*) &TCPWM0->MOTIF_GRP[1])                   /* 0x42AA4000 */
#define TCPWM0_MOTIF_GRP2                       ((TCPWM_MOTIF_GRP_Type*) &TCPWM0->MOTIF_GRP[2])                   /* 0x42AA8000 */
#define TCPWM0_MOTIF_GRP1_MOTIF0                ((TCPWM_MOTIF_GRP_MOTIF_Type*) &TCPWM0->MOTIF_GRP[1].MOTIF[0])    /* 0x42AA4000 */

/*******************************************************************************
*                                    HPPASS
*******************************************************************************/

#define HPPASS_BASE                             0x42B00000UL
#define HPPASS                                  ((HPPASS_Type*) HPPASS_BASE)                                      /* 0x42B00000 */
#define HPPASS_SARADC                           ((HPPASS_SARADC_Type*) &HPPASS->SARADC)                           /* 0x42B70000 */
#define HPPASS_SAR                              ((HPPASS_SAR_Type*) &HPPASS->SAR)                                 /* 0x42B80000 */
#define HPPASS_SAR_CFG                          ((HPPASS_SAR_CFG_Type*) &HPPASS->SAR.CFG)                         /* 0x42B80400 */
#define HPPASS_SAR_FIR0                         ((HPPASS_SAR_FIR_Type*) &HPPASS->SAR.FIR[0])                      /* 0x42B80800 */
#define HPPASS_SAR_FIR1                         ((HPPASS_SAR_FIR_Type*) &HPPASS->SAR.FIR[1])                      /* 0x42B80880 */
#define HPPASS_CSG                              ((HPPASS_CSG_Type*) &HPPASS->CSG)                                 /* 0x42BB0000 */
#define HPPASS_CSG_SLICE0                       ((HPPASS_CSG_SLICE_Type*) &HPPASS->CSG.SLICE[0])                  /* 0x42BB0000 */
#define HPPASS_CSG_SLICE1                       ((HPPASS_CSG_SLICE_Type*) &HPPASS->CSG.SLICE[1])                  /* 0x42BB0040 */
#define HPPASS_CSG_SLICE2                       ((HPPASS_CSG_SLICE_Type*) &HPPASS->CSG.SLICE[2])                  /* 0x42BB0080 */
#define HPPASS_CSG_SLICE3                       ((HPPASS_CSG_SLICE_Type*) &HPPASS->CSG.SLICE[3])                  /* 0x42BB00C0 */
#define HPPASS_CSG_SLICE4                       ((HPPASS_CSG_SLICE_Type*) &HPPASS->CSG.SLICE[4])                  /* 0x42BB0100 */
#define HPPASS_CSG_LUT_CFG0                     ((HPPASS_CSG_LUT_CFG_Type*) &HPPASS->CSG.LUT_CFG[0])              /* 0x42BB0400 */
#define HPPASS_CSG_LUT_CFG1                     ((HPPASS_CSG_LUT_CFG_Type*) &HPPASS->CSG.LUT_CFG[1])              /* 0x42BB0600 */
#define HPPASS_ACTRLR                           ((HPPASS_ACTRLR_Type*) &HPPASS->ACTRLR)                           /* 0x42BD0000 */
#define HPPASS_ACTRLR_TTCFG0                    ((HPPASS_ACTRLR_TTCFG_Type*) &HPPASS->ACTRLR.TTCFG[0])            /* 0x42BD0800 */
#define HPPASS_ACTRLR_TTCFG1                    ((HPPASS_ACTRLR_TTCFG_Type*) &HPPASS->ACTRLR.TTCFG[1])            /* 0x42BD0810 */
#define HPPASS_ACTRLR_TTCFG2                    ((HPPASS_ACTRLR_TTCFG_Type*) &HPPASS->ACTRLR.TTCFG[2])            /* 0x42BD0820 */
#define HPPASS_ACTRLR_TTCFG3                    ((HPPASS_ACTRLR_TTCFG_Type*) &HPPASS->ACTRLR.TTCFG[3])            /* 0x42BD0830 */
#define HPPASS_ACTRLR_TTCFG4                    ((HPPASS_ACTRLR_TTCFG_Type*) &HPPASS->ACTRLR.TTCFG[4])            /* 0x42BD0840 */
#define HPPASS_ACTRLR_TTCFG5                    ((HPPASS_ACTRLR_TTCFG_Type*) &HPPASS->ACTRLR.TTCFG[5])            /* 0x42BD0850 */
#define HPPASS_ACTRLR_TTCFG6                    ((HPPASS_ACTRLR_TTCFG_Type*) &HPPASS->ACTRLR.TTCFG[6])            /* 0x42BD0860 */
#define HPPASS_ACTRLR_TTCFG7                    ((HPPASS_ACTRLR_TTCFG_Type*) &HPPASS->ACTRLR.TTCFG[7])            /* 0x42BD0870 */
#define HPPASS_ACTRLR_TTCFG8                    ((HPPASS_ACTRLR_TTCFG_Type*) &HPPASS->ACTRLR.TTCFG[8])            /* 0x42BD0880 */
#define HPPASS_ACTRLR_TTCFG9                    ((HPPASS_ACTRLR_TTCFG_Type*) &HPPASS->ACTRLR.TTCFG[9])            /* 0x42BD0890 */
#define HPPASS_ACTRLR_TTCFG10                   ((HPPASS_ACTRLR_TTCFG_Type*) &HPPASS->ACTRLR.TTCFG[10])           /* 0x42BD08A0 */
#define HPPASS_ACTRLR_TTCFG11                   ((HPPASS_ACTRLR_TTCFG_Type*) &HPPASS->ACTRLR.TTCFG[11])           /* 0x42BD08B0 */
#define HPPASS_ACTRLR_TTCFG12                   ((HPPASS_ACTRLR_TTCFG_Type*) &HPPASS->ACTRLR.TTCFG[12])           /* 0x42BD08C0 */
#define HPPASS_ACTRLR_TTCFG13                   ((HPPASS_ACTRLR_TTCFG_Type*) &HPPASS->ACTRLR.TTCFG[13])           /* 0x42BD08D0 */
#define HPPASS_ACTRLR_TTCFG14                   ((HPPASS_ACTRLR_TTCFG_Type*) &HPPASS->ACTRLR.TTCFG[14])           /* 0x42BD08E0 */
#define HPPASS_ACTRLR_TTCFG15                   ((HPPASS_ACTRLR_TTCFG_Type*) &HPPASS->ACTRLR.TTCFG[15])           /* 0x42BD08F0 */
#define HPPASS_INFRA                            ((HPPASS_INFRA_Type*) &HPPASS->INFRA)                             /* 0x42BE0000 */
#define HPPASS_INFRA_AREFV2                     ((HPPASS_INFRA_AREFV2_Type*) &HPPASS->INFRA.AREFV2)               /* 0x42BE0E00 */
#define HPPASS_MMIO                             ((HPPASS_MMIO_Type*) &HPPASS->MMIO)                               /* 0x42BF0000 */
#define HPPASS_MMIO_FIFO                        ((HPPASS_MMIO_FIFO_Type*) &HPPASS->MMIO.FIFO)                     /* 0x42BF0100 */

/*******************************************************************************
*                                     CM33
*******************************************************************************/

#define CM33_BASE                               0xE0000000UL
#define CM33                                    ((CM33_Type*) CM33_BASE)                                          /* 0xE0000000 */
#define CM33_CTI                                ((CM33_CTI_Type*) &CM33->CTI)                                     /* 0xE0042000 */
#define CM33_TRC                                ((CM33_TRC_Type*) &CM33->TRC)                                     /* 0xE0080000 */
#define CM33_TRC_CTI                            ((CM33_TRC_CTI_Type*) &CM33->TRC.CTI)                             /* 0xE0080000 */

/** \} PSC3P5FDS2ABQ1 */

#endif /* _PSC3P5FDS2ABQ1_H_ */


/* [] END OF FILE */
