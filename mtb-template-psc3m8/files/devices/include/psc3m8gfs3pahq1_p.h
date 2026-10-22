/***************************************************************************//**
* PSC3M8GFS3PAHQ1 device header with PPCA MMIO offsets
*
********************************************************************************
* \copyright
* (c) (2016-2026), Cypress Semiconductor Corporation (an Infineon company) or
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

#ifndef _PSC3M8GFS3PAHQ1_P_H_
#define _PSC3M8GFS3PAHQ1_P_H_

/**
* \addtogroup group_device PSC3M8GFS3PAHQ1
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
  /* PSC3M8GFS3PAHQ1 Peripheral Interrupt Numbers */
  ppca_epu_0_IRQn                   =   5,      /*!<   5 [Active] PPCA interrupt #5 */
  ppca_epu_1_IRQn                   =   6,      /*!<   6 [Active] PPCA interrupt #6 */
  ppca_epu_2_IRQn                   =   7,      /*!<   7 [Active] PPCA interrupt #7 */
  ppca_epu_3_IRQn                   =   8,      /*!<   8 [Active] PPCA interrupt #8 */
  ppca_epu_4_IRQn                   =   9,      /*!<   9 [Active] PPCA interrupt #9 */
  ppca_epu_5_IRQn                   =  10,      /*!<  10 [Active] PPCA interrupt #10 */
  ppca_epu_6_IRQn                   =  11,      /*!<  11 [Active] PPCA interrupt #11 */
  ppca_epu_7_IRQn                   =  12,      /*!<  12 [Active] PPCA interrupt #12 */
  ppca_pwm_0_grp_0_cnt_0_IRQn       =  13,      /*!<  13 [Active] PPCA interrupt #13 */
  ppca_pwm_0_grp_0_cnt_1_IRQn       =  14,      /*!<  14 [Active] PPCA interrupt #14 */
  ppca_pwm_0_grp_0_cnt_2_IRQn       =  15,      /*!<  15 [Active] PPCA interrupt #15 */
  ppca_pwm_0_grp_0_cnt_3_IRQn       =  16,      /*!<  16 [Active] PPCA interrupt #16 */
  ppca_pwm_0_grp_1_cnt_0_IRQn       =  17,      /*!<  17 [Active] PPCA interrupt #17 */
  ppca_pwm_0_grp_1_cnt_1_IRQn       =  18,      /*!<  18 [Active] PPCA interrupt #18 */
  ppca_pwm_0_grp_1_cnt_2_IRQn       =  19,      /*!<  19 [Active] PPCA interrupt #19 */
  ppca_pwm_0_grp_1_cnt_3_IRQn       =  20,      /*!<  20 [Active] PPCA interrupt #20 */
  ppca_pwm_0_grp_2_cnt_0_IRQn       =  21,      /*!<  21 [Active] PPCA interrupt #21 */
  ppca_pwm_0_grp_2_cnt_1_IRQn       =  22,      /*!<  22 [Active] PPCA interrupt #22 */
  ppca_pwm_0_grp_2_cnt_2_IRQn       =  23,      /*!<  23 [Active] PPCA interrupt #23 */
  ppca_pwm_0_grp_2_cnt_3_IRQn       =  24,      /*!<  24 [Active] PPCA interrupt #24 */
  ppca_pwm_1_grp_0_cnt_0_IRQn       =  25,      /*!<  25 [Active] PPCA interrupt #25 */
  ppca_pwm_1_grp_0_cnt_1_IRQn       =  26,      /*!<  26 [Active] PPCA interrupt #26 */
  ppca_pwm_1_grp_1_cnt_0_IRQn       =  27,      /*!<  27 [Active] PPCA interrupt #27 */
  ppca_pwm_1_grp_1_cnt_1_IRQn       =  28,      /*!<  28 [Active] PPCA interrupt #28 */
  ppca_pwm_1_grp_2_cnt_0_IRQn       =  29,      /*!<  29 [Active] PPCA interrupt #29 */
  ppca_pwm_1_grp_2_cnt_1_IRQn       =  30,      /*!<  30 [Active] PPCA interrupt #30 */
  ppca_pwm_1_grp_2_cnt_2_IRQn       =  31,      /*!<  31 [Active] PPCA interrupt #31 */
  ppca_pwm_1_grp_2_cnt_3_IRQn       =  32,      /*!<  32 [Active] PPCA interrupt #32 */
  ppca_pwm_2_grp_0_cnt_0_IRQn       =  33,      /*!<  33 [Active] PPCA interrupt #33 */
  ppca_pwm_2_grp_0_cnt_1_IRQn       =  34,      /*!<  34 [Active] PPCA interrupt #34 */
  ppca_pwm_2_grp_0_cnt_2_IRQn       =  35,      /*!<  35 [Active] PPCA interrupt #35 */
  ppca_pwm_2_grp_0_cnt_3_IRQn       =  36,      /*!<  36 [Active] PPCA interrupt #36 */
  ppca_pwm_3_grp_0_cnt_0_IRQn       =  37,      /*!<  37 [Active] PPCA interrupt #37 */
  ppca_pwm_3_grp_0_cnt_1_IRQn       =  38,      /*!<  38 [Active] PPCA interrupt #38 */
  ppca_clb_IRQn                     =  39,      /*!<  39 [Active] PPCA interrupt #39 */
  ppca_atop_0_IRQn                  =  40,      /*!<  40 [Active] PPCA interrupt #40 */
  ppca_atop_1_IRQn                  =  41,      /*!<  41 [Active] PPCA interrupt #41 */
  ppca_atop_2_IRQn                  =  42,      /*!<  42 [Active] PPCA interrupt #42 */
  ppca_atop_3_IRQn                  =  43,      /*!<  43 [Active] PPCA interrupt #43 */
  ppca_cordic_0_IRQn                =  44,      /*!<  44 [Active] PPCA interrupt #44 */
  ppca_cordic_1_IRQn                =  45,      /*!<  45 [Active] PPCA interrupt #45 */
  ppca_ipc_0_IRQn                   =  47,      /*!<  47 [Active] PPCA interrupt #47 */
  ppca_ipc_1_IRQn                   =  48,      /*!<  48 [Active] PPCA interrupt #48 */
  ppca_ipc_2_IRQn                   =  49,      /*!<  49 [Active] PPCA interrupt #49 */
  ppca_ipc_3_IRQn                   =  50,      /*!<  50 [Active] PPCA interrupt #50 */
  ppca_pwm_0_motif_0_IRQn           =  51,      /*!<  51 [Active] PPCA interrupt #51 */
  ppca_pwm_0_motif_1_IRQn           =  52,      /*!<  52 [Active] PPCA interrupt #52 */
  ppca_pwm_1_motif_0_IRQn           =  53,      /*!<  53 [Active] PPCA interrupt #53 */
  ppca_pwm_1_motif_1_IRQn           =  54,      /*!<  54 [Active] PPCA interrupt #54 */
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
#define CY_SRAM_BASE                    0x64000000UL
#define CY_SRAM_CBUS_BASE               0x62000000UL
#define CY_SRAM_SIZE                    0x00020000UL
#define CY_SRAM_NS_SBUS_BASE            0x24000000UL
#define CY_SRAM_NS_CBUS_BASE            0x04000000UL
#define CY_SRAM_S_SBUS_BASE             0x34000000UL
#define CY_SRAM_S_CBUS_BASE             0x14000000UL
#define CY_FLASH_BASE                   0x22000000UL
#define CY_FLASH_CBUS_BASE              0x60000000UL
#define CY_FLASH_SIZE                   0x00080000UL
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
#define CY_SFLASH_CBUS_BASE             0x61400000UL
#define CY_SFLASH_SIZE                  0x00008000UL
#define CY_SFLASH_NS_SBUS_BASE          0x23400000UL
#define CY_SFLASH_NS_CBUS_BASE          0x03400000UL
#define CY_SFLASH_S_SBUS_BASE           0x33400000UL
#define CY_SFLASH_S_CBUS_BASE           0x13400000UL
#define CY_EFUSE_BASE                   0x68610800UL
#define CY_EFUSE_CBUS_BASE              0x68610800UL
#define CY_EFUSE_SIZE                   0x00000200UL
#define CY_EFUSE_NS_SBUS_BASE           0x42610800UL
#define CY_EFUSE_NS_CBUS_BASE           0x42610800UL
#define CY_EFUSE_S_SBUS_BASE            0x52610800UL
#define CY_EFUSE_S_CBUS_BASE            0x52610800UL
#define CY_CAN0MRAM_BASE                0x68810000UL
#define CY_CAN0MRAM_CBUS_BASE           0x68810000UL
#define CY_CAN0MRAM_SIZE                0x00010000UL
#define CY_CAN0MRAM_NS_SBUS_BASE        0x42810000UL
#define CY_CAN0MRAM_NS_CBUS_BASE        0x42810000UL
#define CY_CAN0MRAM_S_SBUS_BASE         0x52810000UL
#define CY_CAN0MRAM_S_CBUS_BASE         0x52810000UL
#define CY_PPCA_CPU0_CODE_SRAM_BASE     0x00000000UL
#define CY_PPCA_CPU0_CODE_SRAM_SIZE     0x00008000UL
#define CY_PPCA_CPU0_DATA_SRAM_BASE     0x20000000UL
#define CY_PPCA_CPU0_DATA_SRAM_SIZE     0x00004000UL
#define CY_PPCA_CPU1_CODE_SRAM_BASE     0x00000000UL
#define CY_PPCA_CPU1_CODE_SRAM_SIZE     0x00008000UL
#define CY_PPCA_CPU1_DATA_SRAM_BASE     0x20000000UL
#define CY_PPCA_CPU1_DATA_SRAM_SIZE     0x00004000UL
#define CY_PPCA_SHARED_DATA_SRAM_BASE   0x20040000UL
#define CY_PPCA_SHARED_DATA_SRAM_SIZE   0x00004000UL


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
#define CY_IP_MXCRYPTOLITE_VERSION_MINOR 2u
#define CY_IP_MXDEBUG600                1u
#define CY_IP_MXDEBUG600_INSTANCES      1u
#define CY_IP_MXDEBUG600_VERSION        1u
#define CY_IP_MXDEBUG600_VERSION_MINOR  2u
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
#define CY_IP_MXAES                     1u
#define CY_IP_MXAES_INSTANCES           1u
#define CY_IP_MXAES_VERSION             2u
#define CY_IP_MXAES_VERSION_MINOR       0u
#define CY_IP_MXCM33                    1u
#define CY_IP_MXCM33_INSTANCES          1u
#define CY_IP_MXCM33_VERSION            2u
#define CY_IP_MXCM33_VERSION_MINOR      1u
#define CY_IP_MXDW                      1u
#define CY_IP_MXDW_INSTANCES            1u
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
#define CY_IP_MXSRAMC_INSTANCES         2u
#define CY_IP_MXSRAMC_VERSION           2u
#define CY_IP_MXSRAMC_VERSION_MINOR     0u
#define CY_IP_MXWOUND                   1u
#define CY_IP_MXWOUND_INSTANCES         1u
#define CY_IP_MXWOUND_VERSION           1u
#define CY_IP_MXWOUND_VERSION_MINOR     0u
#define CY_IP_MXSPERI                   1u
#define CY_IP_MXSPERI_INSTANCES         1u
#define CY_IP_MXSPERI_VERSION           2u
#define CY_IP_MXSPERI_VERSION_MINOR     0u
#define CY_IP_MXSPERI_TR                1u
#define CY_IP_MXSPERI_TR_INSTANCES      1u
#define CY_IP_MXSPERI_TR_VERSION        2u
#define CY_IP_MXSPERI_TR_VERSION_MINOR  0u
#define CY_IP_MXS40PPSS                 1u
#define CY_IP_MXS40PPSS_INSTANCES       1u
#define CY_IP_MXS40PPSS_VERSION         1u
#define CY_IP_MXS40PPSS_VERSION_MINOR   0u
#define CY_IP_MXSCB                     1u
#define CY_IP_MXSCB_INSTANCES           7u
#define CY_IP_MXSCB_VERSION             4u
#define CY_IP_MXSCB_VERSION_MINOR       4u
#define CY_IP_MXS40SSRSS                1u
#define CY_IP_MXS40SSRSS_INSTANCES      1u
#define CY_IP_MXS40SSRSS_VERSION        1u
#define CY_IP_MXS40SSRSS_VERSION_MINOR  3u
#define CY_IP_MXS40SVGS                 1u
#define CY_IP_MXS40SVGS_INSTANCES       1u
#define CY_IP_MXS40SVGS_VERSION         1u
#define CY_IP_MXS40SVGS_VERSION_MINOR   0u
#define CY_IP_MXS40TCPWM                1u
#define CY_IP_MXS40TCPWM_INSTANCES      1u
#define CY_IP_MXS40TCPWM_VERSION        1u
#define CY_IP_MXS40TCPWM_VERSION_MINOR  1u

#define CY_DEVICE_PSC3_P8
#define CY_DEVICE_SERIES_PSC3M8
#define CY_DEVICE_IFX_SECURITY_EPC3
#define CY_SILICON_ID                   0xEE801119UL
#define CY_HF_CLK_MAX_FREQ              180000000UL


#include "system_cat1b.h"

#include "psc3_p8_config.h"
#include "gpio_psc3_p8_pg_e_lqfp100l.h"

/*******************************************************************************
*                                    SFLASH
*******************************************************************************/

#define SFLASH_BASE                             0x61400000UL
#define SFLASH                                  ((SFLASH_Type*) SFLASH_BASE)                                      /* 0x61400000 */

/*******************************************************************************
*                                     PERI
*******************************************************************************/

#define PERI_BASE                               0x68000000UL
#define PERI                                    ((PERI_Type*) PERI_BASE)                                          /* 0x68000000 */
#define PERI_GR0                                ((PERI_GR_Type*) &PERI->GR[0])                                    /* 0x68004000 */
#define PERI_GR1                                ((PERI_GR_Type*) &PERI->GR[1])                                    /* 0x68004040 */
#define PERI_GR2                                ((PERI_GR_Type*) &PERI->GR[2])                                    /* 0x68004080 */
#define PERI_GR3                                ((PERI_GR_Type*) &PERI->GR[3])                                    /* 0x680040C0 */
#define PERI_GR4                                ((PERI_GR_Type*) &PERI->GR[4])                                    /* 0x68004100 */
#define PERI_GR5                                ((PERI_GR_Type*) &PERI->GR[5])                                    /* 0x68004140 */
#define PERI_TR_GR0                             ((PERI_TR_GR_Type*) &PERI->TR_GR[0])                              /* 0x68008000 */
#define PERI_TR_GR1                             ((PERI_TR_GR_Type*) &PERI->TR_GR[1])                              /* 0x68008400 */
#define PERI_TR_GR2                             ((PERI_TR_GR_Type*) &PERI->TR_GR[2])                              /* 0x68008800 */
#define PERI_TR_GR3                             ((PERI_TR_GR_Type*) &PERI->TR_GR[3])                              /* 0x68008C00 */
#define PERI_TR_GR4                             ((PERI_TR_GR_Type*) &PERI->TR_GR[4])                              /* 0x68009000 */
#define PERI_TR_GR5                             ((PERI_TR_GR_Type*) &PERI->TR_GR[5])                              /* 0x68009400 */
#define PERI_TR_GR6                             ((PERI_TR_GR_Type*) &PERI->TR_GR[6])                              /* 0x68009800 */
#define PERI_TR_GR7                             ((PERI_TR_GR_Type*) &PERI->TR_GR[7])                              /* 0x68009C00 */
#define PERI_TR_1TO1_GR0                        ((PERI_TR_1TO1_GR_Type*) &PERI->TR_1TO1_GR[0])                    /* 0x6800C000 */

/*******************************************************************************
*                                     PPC
*******************************************************************************/

#define PPC_BASE                                0x68020000UL
#define PPC                                     ((PPC_Type*) PPC_BASE)                                            /* 0x68020000 */
#define PPC_R_ADDR0                             ((PPC_R_ADDR_Type*) &PPC->R_ADDR[0])                              /* 0x68025000 */
#define PPC_R_ADDR1                             ((PPC_R_ADDR_Type*) &PPC->R_ADDR[1])                              /* 0x68025004 */
#define PPC_R_ADDR2                             ((PPC_R_ADDR_Type*) &PPC->R_ADDR[2])                              /* 0x68025008 */
#define PPC_R_ADDR3                             ((PPC_R_ADDR_Type*) &PPC->R_ADDR[3])                              /* 0x6802500C */
#define PPC_R_ADDR4                             ((PPC_R_ADDR_Type*) &PPC->R_ADDR[4])                              /* 0x68025010 */
#define PPC_R_ADDR5                             ((PPC_R_ADDR_Type*) &PPC->R_ADDR[5])                              /* 0x68025014 */
#define PPC_R_ADDR6                             ((PPC_R_ADDR_Type*) &PPC->R_ADDR[6])                              /* 0x68025018 */
#define PPC_R_ADDR7                             ((PPC_R_ADDR_Type*) &PPC->R_ADDR[7])                              /* 0x6802501C */
#define PPC_R_ADDR8                             ((PPC_R_ADDR_Type*) &PPC->R_ADDR[8])                              /* 0x68025020 */
#define PPC_R_ADDR9                             ((PPC_R_ADDR_Type*) &PPC->R_ADDR[9])                              /* 0x68025024 */
#define PPC_R_ADDR10                            ((PPC_R_ADDR_Type*) &PPC->R_ADDR[10])                             /* 0x68025028 */
#define PPC_R_ADDR11                            ((PPC_R_ADDR_Type*) &PPC->R_ADDR[11])                             /* 0x6802502C */
#define PPC_R_ADDR12                            ((PPC_R_ADDR_Type*) &PPC->R_ADDR[12])                             /* 0x68025030 */
#define PPC_R_ADDR13                            ((PPC_R_ADDR_Type*) &PPC->R_ADDR[13])                             /* 0x68025034 */
#define PPC_R_ADDR14                            ((PPC_R_ADDR_Type*) &PPC->R_ADDR[14])                             /* 0x68025038 */
#define PPC_R_ADDR15                            ((PPC_R_ADDR_Type*) &PPC->R_ADDR[15])                             /* 0x6802503C */
#define PPC_R_ADDR16                            ((PPC_R_ADDR_Type*) &PPC->R_ADDR[16])                             /* 0x68025040 */
#define PPC_R_ADDR17                            ((PPC_R_ADDR_Type*) &PPC->R_ADDR[17])                             /* 0x68025044 */
#define PPC_R_ADDR18                            ((PPC_R_ADDR_Type*) &PPC->R_ADDR[18])                             /* 0x68025048 */
#define PPC_R_ADDR19                            ((PPC_R_ADDR_Type*) &PPC->R_ADDR[19])                             /* 0x6802504C */
#define PPC_R_ADDR20                            ((PPC_R_ADDR_Type*) &PPC->R_ADDR[20])                             /* 0x68025050 */
#define PPC_R_ADDR21                            ((PPC_R_ADDR_Type*) &PPC->R_ADDR[21])                             /* 0x68025054 */
#define PPC_R_ADDR22                            ((PPC_R_ADDR_Type*) &PPC->R_ADDR[22])                             /* 0x68025058 */
#define PPC_R_ADDR23                            ((PPC_R_ADDR_Type*) &PPC->R_ADDR[23])                             /* 0x6802505C */
#define PPC_R_ADDR24                            ((PPC_R_ADDR_Type*) &PPC->R_ADDR[24])                             /* 0x68025060 */
#define PPC_R_ADDR25                            ((PPC_R_ADDR_Type*) &PPC->R_ADDR[25])                             /* 0x68025064 */
#define PPC_R_ADDR26                            ((PPC_R_ADDR_Type*) &PPC->R_ADDR[26])                             /* 0x68025068 */
#define PPC_R_ADDR27                            ((PPC_R_ADDR_Type*) &PPC->R_ADDR[27])                             /* 0x6802506C */
#define PPC_R_ADDR28                            ((PPC_R_ADDR_Type*) &PPC->R_ADDR[28])                             /* 0x68025070 */
#define PPC_R_ADDR29                            ((PPC_R_ADDR_Type*) &PPC->R_ADDR[29])                             /* 0x68025074 */
#define PPC_R_ADDR30                            ((PPC_R_ADDR_Type*) &PPC->R_ADDR[30])                             /* 0x68025078 */
#define PPC_R_ADDR31                            ((PPC_R_ADDR_Type*) &PPC->R_ADDR[31])                             /* 0x6802507C */
#define PPC_R_ADDR32                            ((PPC_R_ADDR_Type*) &PPC->R_ADDR[32])                             /* 0x68025080 */
#define PPC_R_ADDR33                            ((PPC_R_ADDR_Type*) &PPC->R_ADDR[33])                             /* 0x68025084 */
#define PPC_R_ADDR34                            ((PPC_R_ADDR_Type*) &PPC->R_ADDR[34])                             /* 0x68025088 */
#define PPC_R_ADDR35                            ((PPC_R_ADDR_Type*) &PPC->R_ADDR[35])                             /* 0x6802508C */
#define PPC_R_ADDR36                            ((PPC_R_ADDR_Type*) &PPC->R_ADDR[36])                             /* 0x68025090 */
#define PPC_R_ADDR37                            ((PPC_R_ADDR_Type*) &PPC->R_ADDR[37])                             /* 0x68025094 */
#define PPC_R_ADDR38                            ((PPC_R_ADDR_Type*) &PPC->R_ADDR[38])                             /* 0x68025098 */
#define PPC_R_ADDR39                            ((PPC_R_ADDR_Type*) &PPC->R_ADDR[39])                             /* 0x6802509C */
#define PPC_R_ADDR40                            ((PPC_R_ADDR_Type*) &PPC->R_ADDR[40])                             /* 0x680250A0 */
#define PPC_R_ADDR41                            ((PPC_R_ADDR_Type*) &PPC->R_ADDR[41])                             /* 0x680250A4 */
#define PPC_R_ADDR42                            ((PPC_R_ADDR_Type*) &PPC->R_ADDR[42])                             /* 0x680250A8 */
#define PPC_R_ADDR43                            ((PPC_R_ADDR_Type*) &PPC->R_ADDR[43])                             /* 0x680250AC */
#define PPC_R_ADDR44                            ((PPC_R_ADDR_Type*) &PPC->R_ADDR[44])                             /* 0x680250B0 */
#define PPC_R_ADDR45                            ((PPC_R_ADDR_Type*) &PPC->R_ADDR[45])                             /* 0x680250B4 */
#define PPC_R_ADDR46                            ((PPC_R_ADDR_Type*) &PPC->R_ADDR[46])                             /* 0x680250B8 */
#define PPC_R_ADDR47                            ((PPC_R_ADDR_Type*) &PPC->R_ADDR[47])                             /* 0x680250BC */
#define PPC_R_ADDR48                            ((PPC_R_ADDR_Type*) &PPC->R_ADDR[48])                             /* 0x680250C0 */
#define PPC_R_ADDR49                            ((PPC_R_ADDR_Type*) &PPC->R_ADDR[49])                             /* 0x680250C4 */
#define PPC_R_ADDR50                            ((PPC_R_ADDR_Type*) &PPC->R_ADDR[50])                             /* 0x680250C8 */
#define PPC_R_ADDR51                            ((PPC_R_ADDR_Type*) &PPC->R_ADDR[51])                             /* 0x680250CC */
#define PPC_R_ADDR52                            ((PPC_R_ADDR_Type*) &PPC->R_ADDR[52])                             /* 0x680250D0 */
#define PPC_R_ADDR53                            ((PPC_R_ADDR_Type*) &PPC->R_ADDR[53])                             /* 0x680250D4 */
#define PPC_R_ADDR54                            ((PPC_R_ADDR_Type*) &PPC->R_ADDR[54])                             /* 0x680250D8 */
#define PPC_R_ADDR55                            ((PPC_R_ADDR_Type*) &PPC->R_ADDR[55])                             /* 0x680250DC */
#define PPC_R_ADDR56                            ((PPC_R_ADDR_Type*) &PPC->R_ADDR[56])                             /* 0x680250E0 */
#define PPC_R_ADDR57                            ((PPC_R_ADDR_Type*) &PPC->R_ADDR[57])                             /* 0x680250E4 */
#define PPC_R_ADDR58                            ((PPC_R_ADDR_Type*) &PPC->R_ADDR[58])                             /* 0x680250E8 */
#define PPC_R_ADDR59                            ((PPC_R_ADDR_Type*) &PPC->R_ADDR[59])                             /* 0x680250EC */
#define PPC_R_ADDR60                            ((PPC_R_ADDR_Type*) &PPC->R_ADDR[60])                             /* 0x680250F0 */
#define PPC_R_ADDR61                            ((PPC_R_ADDR_Type*) &PPC->R_ADDR[61])                             /* 0x680250F4 */
#define PPC_R_ADDR62                            ((PPC_R_ADDR_Type*) &PPC->R_ADDR[62])                             /* 0x680250F8 */
#define PPC_R_ADDR63                            ((PPC_R_ADDR_Type*) &PPC->R_ADDR[63])                             /* 0x680250FC */
#define PPC_R_ADDR64                            ((PPC_R_ADDR_Type*) &PPC->R_ADDR[64])                             /* 0x68025100 */
#define PPC_R_ADDR65                            ((PPC_R_ADDR_Type*) &PPC->R_ADDR[65])                             /* 0x68025104 */
#define PPC_R_ADDR66                            ((PPC_R_ADDR_Type*) &PPC->R_ADDR[66])                             /* 0x68025108 */
#define PPC_R_ADDR67                            ((PPC_R_ADDR_Type*) &PPC->R_ADDR[67])                             /* 0x6802510C */
#define PPC_R_ADDR68                            ((PPC_R_ADDR_Type*) &PPC->R_ADDR[68])                             /* 0x68025110 */
#define PPC_R_ADDR69                            ((PPC_R_ADDR_Type*) &PPC->R_ADDR[69])                             /* 0x68025114 */
#define PPC_R_ADDR70                            ((PPC_R_ADDR_Type*) &PPC->R_ADDR[70])                             /* 0x68025118 */
#define PPC_R_ADDR71                            ((PPC_R_ADDR_Type*) &PPC->R_ADDR[71])                             /* 0x6802511C */
#define PPC_R_ADDR72                            ((PPC_R_ADDR_Type*) &PPC->R_ADDR[72])                             /* 0x68025120 */
#define PPC_R_ADDR73                            ((PPC_R_ADDR_Type*) &PPC->R_ADDR[73])                             /* 0x68025124 */
#define PPC_R_ADDR74                            ((PPC_R_ADDR_Type*) &PPC->R_ADDR[74])                             /* 0x68025128 */
#define PPC_R_ADDR75                            ((PPC_R_ADDR_Type*) &PPC->R_ADDR[75])                             /* 0x6802512C */
#define PPC_R_ADDR76                            ((PPC_R_ADDR_Type*) &PPC->R_ADDR[76])                             /* 0x68025130 */
#define PPC_R_ADDR77                            ((PPC_R_ADDR_Type*) &PPC->R_ADDR[77])                             /* 0x68025134 */
#define PPC_R_ADDR78                            ((PPC_R_ADDR_Type*) &PPC->R_ADDR[78])                             /* 0x68025138 */
#define PPC_R_ADDR79                            ((PPC_R_ADDR_Type*) &PPC->R_ADDR[79])                             /* 0x6802513C */
#define PPC_R_ADDR80                            ((PPC_R_ADDR_Type*) &PPC->R_ADDR[80])                             /* 0x68025140 */
#define PPC_R_ADDR81                            ((PPC_R_ADDR_Type*) &PPC->R_ADDR[81])                             /* 0x68025144 */
#define PPC_R_ADDR82                            ((PPC_R_ADDR_Type*) &PPC->R_ADDR[82])                             /* 0x68025148 */
#define PPC_R_ADDR83                            ((PPC_R_ADDR_Type*) &PPC->R_ADDR[83])                             /* 0x6802514C */
#define PPC_R_ADDR84                            ((PPC_R_ADDR_Type*) &PPC->R_ADDR[84])                             /* 0x68025150 */
#define PPC_R_ADDR85                            ((PPC_R_ADDR_Type*) &PPC->R_ADDR[85])                             /* 0x68025154 */
#define PPC_R_ADDR86                            ((PPC_R_ADDR_Type*) &PPC->R_ADDR[86])                             /* 0x68025158 */
#define PPC_R_ADDR87                            ((PPC_R_ADDR_Type*) &PPC->R_ADDR[87])                             /* 0x6802515C */
#define PPC_R_ADDR88                            ((PPC_R_ADDR_Type*) &PPC->R_ADDR[88])                             /* 0x68025160 */
#define PPC_R_ADDR89                            ((PPC_R_ADDR_Type*) &PPC->R_ADDR[89])                             /* 0x68025164 */
#define PPC_R_ADDR90                            ((PPC_R_ADDR_Type*) &PPC->R_ADDR[90])                             /* 0x68025168 */
#define PPC_R_ADDR91                            ((PPC_R_ADDR_Type*) &PPC->R_ADDR[91])                             /* 0x6802516C */
#define PPC_R_ADDR92                            ((PPC_R_ADDR_Type*) &PPC->R_ADDR[92])                             /* 0x68025170 */
#define PPC_R_ADDR93                            ((PPC_R_ADDR_Type*) &PPC->R_ADDR[93])                             /* 0x68025174 */
#define PPC_R_ADDR94                            ((PPC_R_ADDR_Type*) &PPC->R_ADDR[94])                             /* 0x68025178 */
#define PPC_R_ADDR95                            ((PPC_R_ADDR_Type*) &PPC->R_ADDR[95])                             /* 0x6802517C */
#define PPC_R_ADDR96                            ((PPC_R_ADDR_Type*) &PPC->R_ADDR[96])                             /* 0x68025180 */
#define PPC_R_ADDR97                            ((PPC_R_ADDR_Type*) &PPC->R_ADDR[97])                             /* 0x68025184 */
#define PPC_R_ADDR98                            ((PPC_R_ADDR_Type*) &PPC->R_ADDR[98])                             /* 0x68025188 */
#define PPC_R_ADDR99                            ((PPC_R_ADDR_Type*) &PPC->R_ADDR[99])                             /* 0x6802518C */
#define PPC_R_ADDR100                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[100])                            /* 0x68025190 */
#define PPC_R_ADDR101                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[101])                            /* 0x68025194 */
#define PPC_R_ADDR102                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[102])                            /* 0x68025198 */
#define PPC_R_ADDR103                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[103])                            /* 0x6802519C */
#define PPC_R_ADDR104                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[104])                            /* 0x680251A0 */
#define PPC_R_ADDR105                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[105])                            /* 0x680251A4 */
#define PPC_R_ADDR106                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[106])                            /* 0x680251A8 */
#define PPC_R_ADDR107                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[107])                            /* 0x680251AC */
#define PPC_R_ADDR108                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[108])                            /* 0x680251B0 */
#define PPC_R_ADDR109                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[109])                            /* 0x680251B4 */
#define PPC_R_ADDR110                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[110])                            /* 0x680251B8 */
#define PPC_R_ADDR111                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[111])                            /* 0x680251BC */
#define PPC_R_ADDR112                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[112])                            /* 0x680251C0 */
#define PPC_R_ADDR113                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[113])                            /* 0x680251C4 */
#define PPC_R_ADDR114                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[114])                            /* 0x680251C8 */
#define PPC_R_ADDR115                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[115])                            /* 0x680251CC */
#define PPC_R_ADDR116                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[116])                            /* 0x680251D0 */
#define PPC_R_ADDR117                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[117])                            /* 0x680251D4 */
#define PPC_R_ADDR118                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[118])                            /* 0x680251D8 */
#define PPC_R_ADDR119                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[119])                            /* 0x680251DC */
#define PPC_R_ADDR120                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[120])                            /* 0x680251E0 */
#define PPC_R_ADDR121                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[121])                            /* 0x680251E4 */
#define PPC_R_ADDR122                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[122])                            /* 0x680251E8 */
#define PPC_R_ADDR123                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[123])                            /* 0x680251EC */
#define PPC_R_ADDR124                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[124])                            /* 0x680251F0 */
#define PPC_R_ADDR125                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[125])                            /* 0x680251F4 */
#define PPC_R_ADDR126                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[126])                            /* 0x680251F8 */
#define PPC_R_ADDR127                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[127])                            /* 0x680251FC */
#define PPC_R_ADDR128                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[128])                            /* 0x68025200 */
#define PPC_R_ADDR129                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[129])                            /* 0x68025204 */
#define PPC_R_ADDR130                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[130])                            /* 0x68025208 */
#define PPC_R_ADDR131                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[131])                            /* 0x6802520C */
#define PPC_R_ADDR132                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[132])                            /* 0x68025210 */
#define PPC_R_ADDR133                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[133])                            /* 0x68025214 */
#define PPC_R_ADDR134                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[134])                            /* 0x68025218 */
#define PPC_R_ADDR135                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[135])                            /* 0x6802521C */
#define PPC_R_ADDR136                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[136])                            /* 0x68025220 */
#define PPC_R_ADDR137                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[137])                            /* 0x68025224 */
#define PPC_R_ADDR138                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[138])                            /* 0x68025228 */
#define PPC_R_ADDR139                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[139])                            /* 0x6802522C */
#define PPC_R_ADDR140                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[140])                            /* 0x68025230 */
#define PPC_R_ADDR141                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[141])                            /* 0x68025234 */
#define PPC_R_ADDR142                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[142])                            /* 0x68025238 */
#define PPC_R_ADDR143                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[143])                            /* 0x6802523C */
#define PPC_R_ADDR144                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[144])                            /* 0x68025240 */
#define PPC_R_ADDR145                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[145])                            /* 0x68025244 */
#define PPC_R_ADDR146                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[146])                            /* 0x68025248 */
#define PPC_R_ADDR147                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[147])                            /* 0x6802524C */
#define PPC_R_ADDR148                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[148])                            /* 0x68025250 */
#define PPC_R_ADDR149                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[149])                            /* 0x68025254 */
#define PPC_R_ADDR150                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[150])                            /* 0x68025258 */
#define PPC_R_ADDR151                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[151])                            /* 0x6802525C */
#define PPC_R_ADDR152                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[152])                            /* 0x68025260 */
#define PPC_R_ADDR153                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[153])                            /* 0x68025264 */
#define PPC_R_ADDR154                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[154])                            /* 0x68025268 */
#define PPC_R_ADDR155                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[155])                            /* 0x6802526C */
#define PPC_R_ADDR156                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[156])                            /* 0x68025270 */
#define PPC_R_ADDR157                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[157])                            /* 0x68025274 */
#define PPC_R_ADDR158                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[158])                            /* 0x68025278 */
#define PPC_R_ADDR159                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[159])                            /* 0x6802527C */
#define PPC_R_ADDR160                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[160])                            /* 0x68025280 */
#define PPC_R_ADDR161                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[161])                            /* 0x68025284 */
#define PPC_R_ADDR162                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[162])                            /* 0x68025288 */
#define PPC_R_ADDR163                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[163])                            /* 0x6802528C */
#define PPC_R_ADDR164                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[164])                            /* 0x68025290 */
#define PPC_R_ADDR165                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[165])                            /* 0x68025294 */
#define PPC_R_ADDR166                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[166])                            /* 0x68025298 */
#define PPC_R_ADDR167                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[167])                            /* 0x6802529C */
#define PPC_R_ADDR168                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[168])                            /* 0x680252A0 */
#define PPC_R_ADDR169                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[169])                            /* 0x680252A4 */
#define PPC_R_ADDR170                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[170])                            /* 0x680252A8 */
#define PPC_R_ADDR171                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[171])                            /* 0x680252AC */
#define PPC_R_ADDR172                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[172])                            /* 0x680252B0 */
#define PPC_R_ADDR173                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[173])                            /* 0x680252B4 */
#define PPC_R_ADDR174                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[174])                            /* 0x680252B8 */
#define PPC_R_ADDR175                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[175])                            /* 0x680252BC */
#define PPC_R_ADDR176                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[176])                            /* 0x680252C0 */
#define PPC_R_ADDR177                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[177])                            /* 0x680252C4 */
#define PPC_R_ADDR178                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[178])                            /* 0x680252C8 */
#define PPC_R_ADDR179                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[179])                            /* 0x680252CC */
#define PPC_R_ADDR180                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[180])                            /* 0x680252D0 */
#define PPC_R_ADDR181                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[181])                            /* 0x680252D4 */
#define PPC_R_ADDR182                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[182])                            /* 0x680252D8 */
#define PPC_R_ADDR183                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[183])                            /* 0x680252DC */
#define PPC_R_ADDR184                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[184])                            /* 0x680252E0 */
#define PPC_R_ADDR185                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[185])                            /* 0x680252E4 */
#define PPC_R_ADDR186                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[186])                            /* 0x680252E8 */
#define PPC_R_ADDR187                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[187])                            /* 0x680252EC */
#define PPC_R_ADDR188                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[188])                            /* 0x680252F0 */
#define PPC_R_ADDR189                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[189])                            /* 0x680252F4 */
#define PPC_R_ADDR190                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[190])                            /* 0x680252F8 */
#define PPC_R_ADDR191                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[191])                            /* 0x680252FC */
#define PPC_R_ADDR192                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[192])                            /* 0x68025300 */
#define PPC_R_ADDR193                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[193])                            /* 0x68025304 */
#define PPC_R_ADDR194                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[194])                            /* 0x68025308 */
#define PPC_R_ADDR195                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[195])                            /* 0x6802530C */
#define PPC_R_ADDR196                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[196])                            /* 0x68025310 */
#define PPC_R_ADDR197                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[197])                            /* 0x68025314 */
#define PPC_R_ADDR198                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[198])                            /* 0x68025318 */
#define PPC_R_ADDR199                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[199])                            /* 0x6802531C */
#define PPC_R_ADDR200                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[200])                            /* 0x68025320 */
#define PPC_R_ADDR201                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[201])                            /* 0x68025324 */
#define PPC_R_ADDR202                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[202])                            /* 0x68025328 */
#define PPC_R_ADDR203                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[203])                            /* 0x6802532C */
#define PPC_R_ADDR204                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[204])                            /* 0x68025330 */
#define PPC_R_ADDR205                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[205])                            /* 0x68025334 */
#define PPC_R_ADDR206                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[206])                            /* 0x68025338 */
#define PPC_R_ADDR207                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[207])                            /* 0x6802533C */
#define PPC_R_ADDR208                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[208])                            /* 0x68025340 */
#define PPC_R_ADDR209                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[209])                            /* 0x68025344 */
#define PPC_R_ADDR210                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[210])                            /* 0x68025348 */
#define PPC_R_ADDR211                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[211])                            /* 0x6802534C */
#define PPC_R_ADDR212                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[212])                            /* 0x68025350 */
#define PPC_R_ADDR213                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[213])                            /* 0x68025354 */
#define PPC_R_ADDR214                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[214])                            /* 0x68025358 */
#define PPC_R_ADDR215                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[215])                            /* 0x6802535C */
#define PPC_R_ADDR216                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[216])                            /* 0x68025360 */
#define PPC_R_ADDR217                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[217])                            /* 0x68025364 */
#define PPC_R_ADDR218                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[218])                            /* 0x68025368 */
#define PPC_R_ADDR219                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[219])                            /* 0x6802536C */
#define PPC_R_ADDR220                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[220])                            /* 0x68025370 */
#define PPC_R_ADDR221                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[221])                            /* 0x68025374 */
#define PPC_R_ADDR222                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[222])                            /* 0x68025378 */
#define PPC_R_ADDR223                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[223])                            /* 0x6802537C */
#define PPC_R_ADDR224                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[224])                            /* 0x68025380 */
#define PPC_R_ADDR225                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[225])                            /* 0x68025384 */
#define PPC_R_ADDR226                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[226])                            /* 0x68025388 */
#define PPC_R_ADDR227                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[227])                            /* 0x6802538C */
#define PPC_R_ADDR228                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[228])                            /* 0x68025390 */
#define PPC_R_ADDR229                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[229])                            /* 0x68025394 */
#define PPC_R_ADDR230                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[230])                            /* 0x68025398 */
#define PPC_R_ADDR231                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[231])                            /* 0x6802539C */
#define PPC_R_ADDR232                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[232])                            /* 0x680253A0 */
#define PPC_R_ADDR233                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[233])                            /* 0x680253A4 */
#define PPC_R_ADDR234                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[234])                            /* 0x680253A8 */
#define PPC_R_ADDR235                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[235])                            /* 0x680253AC */
#define PPC_R_ADDR236                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[236])                            /* 0x680253B0 */
#define PPC_R_ADDR237                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[237])                            /* 0x680253B4 */
#define PPC_R_ADDR238                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[238])                            /* 0x680253B8 */
#define PPC_R_ADDR239                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[239])                            /* 0x680253BC */
#define PPC_R_ADDR240                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[240])                            /* 0x680253C0 */
#define PPC_R_ADDR241                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[241])                            /* 0x680253C4 */
#define PPC_R_ADDR242                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[242])                            /* 0x680253C8 */
#define PPC_R_ADDR243                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[243])                            /* 0x680253CC */
#define PPC_R_ADDR244                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[244])                            /* 0x680253D0 */
#define PPC_R_ADDR245                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[245])                            /* 0x680253D4 */
#define PPC_R_ADDR246                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[246])                            /* 0x680253D8 */
#define PPC_R_ADDR247                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[247])                            /* 0x680253DC */
#define PPC_R_ADDR248                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[248])                            /* 0x680253E0 */
#define PPC_R_ADDR249                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[249])                            /* 0x680253E4 */
#define PPC_R_ADDR250                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[250])                            /* 0x680253E8 */
#define PPC_R_ADDR251                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[251])                            /* 0x680253EC */
#define PPC_R_ADDR252                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[252])                            /* 0x680253F0 */
#define PPC_R_ADDR253                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[253])                            /* 0x680253F4 */
#define PPC_R_ADDR254                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[254])                            /* 0x680253F8 */
#define PPC_R_ADDR255                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[255])                            /* 0x680253FC */
#define PPC_R_ADDR256                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[256])                            /* 0x68025400 */
#define PPC_R_ADDR257                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[257])                            /* 0x68025404 */
#define PPC_R_ADDR258                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[258])                            /* 0x68025408 */
#define PPC_R_ADDR259                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[259])                            /* 0x6802540C */
#define PPC_R_ADDR260                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[260])                            /* 0x68025410 */
#define PPC_R_ADDR261                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[261])                            /* 0x68025414 */
#define PPC_R_ADDR262                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[262])                            /* 0x68025418 */
#define PPC_R_ADDR263                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[263])                            /* 0x6802541C */
#define PPC_R_ADDR264                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[264])                            /* 0x68025420 */
#define PPC_R_ADDR265                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[265])                            /* 0x68025424 */
#define PPC_R_ADDR266                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[266])                            /* 0x68025428 */
#define PPC_R_ADDR267                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[267])                            /* 0x6802542C */
#define PPC_R_ADDR268                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[268])                            /* 0x68025430 */
#define PPC_R_ADDR269                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[269])                            /* 0x68025434 */
#define PPC_R_ADDR270                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[270])                            /* 0x68025438 */
#define PPC_R_ADDR271                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[271])                            /* 0x6802543C */
#define PPC_R_ADDR272                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[272])                            /* 0x68025440 */
#define PPC_R_ADDR273                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[273])                            /* 0x68025444 */
#define PPC_R_ADDR274                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[274])                            /* 0x68025448 */
#define PPC_R_ADDR275                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[275])                            /* 0x6802544C */
#define PPC_R_ADDR276                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[276])                            /* 0x68025450 */
#define PPC_R_ADDR277                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[277])                            /* 0x68025454 */
#define PPC_R_ADDR278                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[278])                            /* 0x68025458 */
#define PPC_R_ADDR279                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[279])                            /* 0x6802545C */
#define PPC_R_ADDR280                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[280])                            /* 0x68025460 */
#define PPC_R_ADDR281                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[281])                            /* 0x68025464 */
#define PPC_R_ADDR282                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[282])                            /* 0x68025468 */
#define PPC_R_ADDR283                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[283])                            /* 0x6802546C */
#define PPC_R_ADDR284                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[284])                            /* 0x68025470 */
#define PPC_R_ADDR285                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[285])                            /* 0x68025474 */
#define PPC_R_ADDR286                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[286])                            /* 0x68025478 */
#define PPC_R_ADDR287                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[287])                            /* 0x6802547C */
#define PPC_R_ADDR288                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[288])                            /* 0x68025480 */
#define PPC_R_ADDR289                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[289])                            /* 0x68025484 */
#define PPC_R_ADDR290                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[290])                            /* 0x68025488 */
#define PPC_R_ADDR291                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[291])                            /* 0x6802548C */
#define PPC_R_ADDR292                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[292])                            /* 0x68025490 */
#define PPC_R_ADDR293                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[293])                            /* 0x68025494 */
#define PPC_R_ADDR294                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[294])                            /* 0x68025498 */
#define PPC_R_ADDR295                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[295])                            /* 0x6802549C */
#define PPC_R_ADDR296                           ((PPC_R_ADDR_Type*) &PPC->R_ADDR[296])                            /* 0x680254A0 */
#define PPC_R_ATT0                              ((PPC_R_ATT_Type*) &PPC->R_ATT[0])                                /* 0x68026000 */
#define PPC_R_ATT1                              ((PPC_R_ATT_Type*) &PPC->R_ATT[1])                                /* 0x68026004 */
#define PPC_R_ATT2                              ((PPC_R_ATT_Type*) &PPC->R_ATT[2])                                /* 0x68026008 */
#define PPC_R_ATT3                              ((PPC_R_ATT_Type*) &PPC->R_ATT[3])                                /* 0x6802600C */
#define PPC_R_ATT4                              ((PPC_R_ATT_Type*) &PPC->R_ATT[4])                                /* 0x68026010 */
#define PPC_R_ATT5                              ((PPC_R_ATT_Type*) &PPC->R_ATT[5])                                /* 0x68026014 */
#define PPC_R_ATT6                              ((PPC_R_ATT_Type*) &PPC->R_ATT[6])                                /* 0x68026018 */
#define PPC_R_ATT7                              ((PPC_R_ATT_Type*) &PPC->R_ATT[7])                                /* 0x6802601C */
#define PPC_R_ATT8                              ((PPC_R_ATT_Type*) &PPC->R_ATT[8])                                /* 0x68026020 */
#define PPC_R_ATT9                              ((PPC_R_ATT_Type*) &PPC->R_ATT[9])                                /* 0x68026024 */
#define PPC_R_ATT10                             ((PPC_R_ATT_Type*) &PPC->R_ATT[10])                               /* 0x68026028 */
#define PPC_R_ATT11                             ((PPC_R_ATT_Type*) &PPC->R_ATT[11])                               /* 0x6802602C */
#define PPC_R_ATT12                             ((PPC_R_ATT_Type*) &PPC->R_ATT[12])                               /* 0x68026030 */
#define PPC_R_ATT13                             ((PPC_R_ATT_Type*) &PPC->R_ATT[13])                               /* 0x68026034 */
#define PPC_R_ATT14                             ((PPC_R_ATT_Type*) &PPC->R_ATT[14])                               /* 0x68026038 */
#define PPC_R_ATT15                             ((PPC_R_ATT_Type*) &PPC->R_ATT[15])                               /* 0x6802603C */
#define PPC_R_ATT16                             ((PPC_R_ATT_Type*) &PPC->R_ATT[16])                               /* 0x68026040 */
#define PPC_R_ATT17                             ((PPC_R_ATT_Type*) &PPC->R_ATT[17])                               /* 0x68026044 */
#define PPC_R_ATT18                             ((PPC_R_ATT_Type*) &PPC->R_ATT[18])                               /* 0x68026048 */
#define PPC_R_ATT19                             ((PPC_R_ATT_Type*) &PPC->R_ATT[19])                               /* 0x6802604C */
#define PPC_R_ATT20                             ((PPC_R_ATT_Type*) &PPC->R_ATT[20])                               /* 0x68026050 */
#define PPC_R_ATT21                             ((PPC_R_ATT_Type*) &PPC->R_ATT[21])                               /* 0x68026054 */
#define PPC_R_ATT22                             ((PPC_R_ATT_Type*) &PPC->R_ATT[22])                               /* 0x68026058 */
#define PPC_R_ATT23                             ((PPC_R_ATT_Type*) &PPC->R_ATT[23])                               /* 0x6802605C */
#define PPC_R_ATT24                             ((PPC_R_ATT_Type*) &PPC->R_ATT[24])                               /* 0x68026060 */
#define PPC_R_ATT25                             ((PPC_R_ATT_Type*) &PPC->R_ATT[25])                               /* 0x68026064 */
#define PPC_R_ATT26                             ((PPC_R_ATT_Type*) &PPC->R_ATT[26])                               /* 0x68026068 */
#define PPC_R_ATT27                             ((PPC_R_ATT_Type*) &PPC->R_ATT[27])                               /* 0x6802606C */
#define PPC_R_ATT28                             ((PPC_R_ATT_Type*) &PPC->R_ATT[28])                               /* 0x68026070 */
#define PPC_R_ATT29                             ((PPC_R_ATT_Type*) &PPC->R_ATT[29])                               /* 0x68026074 */
#define PPC_R_ATT30                             ((PPC_R_ATT_Type*) &PPC->R_ATT[30])                               /* 0x68026078 */
#define PPC_R_ATT31                             ((PPC_R_ATT_Type*) &PPC->R_ATT[31])                               /* 0x6802607C */
#define PPC_R_ATT32                             ((PPC_R_ATT_Type*) &PPC->R_ATT[32])                               /* 0x68026080 */
#define PPC_R_ATT33                             ((PPC_R_ATT_Type*) &PPC->R_ATT[33])                               /* 0x68026084 */
#define PPC_R_ATT34                             ((PPC_R_ATT_Type*) &PPC->R_ATT[34])                               /* 0x68026088 */
#define PPC_R_ATT35                             ((PPC_R_ATT_Type*) &PPC->R_ATT[35])                               /* 0x6802608C */
#define PPC_R_ATT36                             ((PPC_R_ATT_Type*) &PPC->R_ATT[36])                               /* 0x68026090 */
#define PPC_R_ATT37                             ((PPC_R_ATT_Type*) &PPC->R_ATT[37])                               /* 0x68026094 */
#define PPC_R_ATT38                             ((PPC_R_ATT_Type*) &PPC->R_ATT[38])                               /* 0x68026098 */
#define PPC_R_ATT39                             ((PPC_R_ATT_Type*) &PPC->R_ATT[39])                               /* 0x6802609C */
#define PPC_R_ATT40                             ((PPC_R_ATT_Type*) &PPC->R_ATT[40])                               /* 0x680260A0 */
#define PPC_R_ATT41                             ((PPC_R_ATT_Type*) &PPC->R_ATT[41])                               /* 0x680260A4 */
#define PPC_R_ATT42                             ((PPC_R_ATT_Type*) &PPC->R_ATT[42])                               /* 0x680260A8 */
#define PPC_R_ATT43                             ((PPC_R_ATT_Type*) &PPC->R_ATT[43])                               /* 0x680260AC */
#define PPC_R_ATT44                             ((PPC_R_ATT_Type*) &PPC->R_ATT[44])                               /* 0x680260B0 */
#define PPC_R_ATT45                             ((PPC_R_ATT_Type*) &PPC->R_ATT[45])                               /* 0x680260B4 */
#define PPC_R_ATT46                             ((PPC_R_ATT_Type*) &PPC->R_ATT[46])                               /* 0x680260B8 */
#define PPC_R_ATT47                             ((PPC_R_ATT_Type*) &PPC->R_ATT[47])                               /* 0x680260BC */
#define PPC_R_ATT48                             ((PPC_R_ATT_Type*) &PPC->R_ATT[48])                               /* 0x680260C0 */
#define PPC_R_ATT49                             ((PPC_R_ATT_Type*) &PPC->R_ATT[49])                               /* 0x680260C4 */
#define PPC_R_ATT50                             ((PPC_R_ATT_Type*) &PPC->R_ATT[50])                               /* 0x680260C8 */
#define PPC_R_ATT51                             ((PPC_R_ATT_Type*) &PPC->R_ATT[51])                               /* 0x680260CC */
#define PPC_R_ATT52                             ((PPC_R_ATT_Type*) &PPC->R_ATT[52])                               /* 0x680260D0 */
#define PPC_R_ATT53                             ((PPC_R_ATT_Type*) &PPC->R_ATT[53])                               /* 0x680260D4 */
#define PPC_R_ATT54                             ((PPC_R_ATT_Type*) &PPC->R_ATT[54])                               /* 0x680260D8 */
#define PPC_R_ATT55                             ((PPC_R_ATT_Type*) &PPC->R_ATT[55])                               /* 0x680260DC */
#define PPC_R_ATT56                             ((PPC_R_ATT_Type*) &PPC->R_ATT[56])                               /* 0x680260E0 */
#define PPC_R_ATT57                             ((PPC_R_ATT_Type*) &PPC->R_ATT[57])                               /* 0x680260E4 */
#define PPC_R_ATT58                             ((PPC_R_ATT_Type*) &PPC->R_ATT[58])                               /* 0x680260E8 */
#define PPC_R_ATT59                             ((PPC_R_ATT_Type*) &PPC->R_ATT[59])                               /* 0x680260EC */
#define PPC_R_ATT60                             ((PPC_R_ATT_Type*) &PPC->R_ATT[60])                               /* 0x680260F0 */
#define PPC_R_ATT61                             ((PPC_R_ATT_Type*) &PPC->R_ATT[61])                               /* 0x680260F4 */
#define PPC_R_ATT62                             ((PPC_R_ATT_Type*) &PPC->R_ATT[62])                               /* 0x680260F8 */
#define PPC_R_ATT63                             ((PPC_R_ATT_Type*) &PPC->R_ATT[63])                               /* 0x680260FC */
#define PPC_R_ATT64                             ((PPC_R_ATT_Type*) &PPC->R_ATT[64])                               /* 0x68026100 */
#define PPC_R_ATT65                             ((PPC_R_ATT_Type*) &PPC->R_ATT[65])                               /* 0x68026104 */
#define PPC_R_ATT66                             ((PPC_R_ATT_Type*) &PPC->R_ATT[66])                               /* 0x68026108 */
#define PPC_R_ATT67                             ((PPC_R_ATT_Type*) &PPC->R_ATT[67])                               /* 0x6802610C */
#define PPC_R_ATT68                             ((PPC_R_ATT_Type*) &PPC->R_ATT[68])                               /* 0x68026110 */
#define PPC_R_ATT69                             ((PPC_R_ATT_Type*) &PPC->R_ATT[69])                               /* 0x68026114 */
#define PPC_R_ATT70                             ((PPC_R_ATT_Type*) &PPC->R_ATT[70])                               /* 0x68026118 */
#define PPC_R_ATT71                             ((PPC_R_ATT_Type*) &PPC->R_ATT[71])                               /* 0x6802611C */
#define PPC_R_ATT72                             ((PPC_R_ATT_Type*) &PPC->R_ATT[72])                               /* 0x68026120 */
#define PPC_R_ATT73                             ((PPC_R_ATT_Type*) &PPC->R_ATT[73])                               /* 0x68026124 */
#define PPC_R_ATT74                             ((PPC_R_ATT_Type*) &PPC->R_ATT[74])                               /* 0x68026128 */
#define PPC_R_ATT75                             ((PPC_R_ATT_Type*) &PPC->R_ATT[75])                               /* 0x6802612C */
#define PPC_R_ATT76                             ((PPC_R_ATT_Type*) &PPC->R_ATT[76])                               /* 0x68026130 */
#define PPC_R_ATT77                             ((PPC_R_ATT_Type*) &PPC->R_ATT[77])                               /* 0x68026134 */
#define PPC_R_ATT78                             ((PPC_R_ATT_Type*) &PPC->R_ATT[78])                               /* 0x68026138 */
#define PPC_R_ATT79                             ((PPC_R_ATT_Type*) &PPC->R_ATT[79])                               /* 0x6802613C */
#define PPC_R_ATT80                             ((PPC_R_ATT_Type*) &PPC->R_ATT[80])                               /* 0x68026140 */
#define PPC_R_ATT81                             ((PPC_R_ATT_Type*) &PPC->R_ATT[81])                               /* 0x68026144 */
#define PPC_R_ATT82                             ((PPC_R_ATT_Type*) &PPC->R_ATT[82])                               /* 0x68026148 */
#define PPC_R_ATT83                             ((PPC_R_ATT_Type*) &PPC->R_ATT[83])                               /* 0x6802614C */
#define PPC_R_ATT84                             ((PPC_R_ATT_Type*) &PPC->R_ATT[84])                               /* 0x68026150 */
#define PPC_R_ATT85                             ((PPC_R_ATT_Type*) &PPC->R_ATT[85])                               /* 0x68026154 */
#define PPC_R_ATT86                             ((PPC_R_ATT_Type*) &PPC->R_ATT[86])                               /* 0x68026158 */
#define PPC_R_ATT87                             ((PPC_R_ATT_Type*) &PPC->R_ATT[87])                               /* 0x6802615C */
#define PPC_R_ATT88                             ((PPC_R_ATT_Type*) &PPC->R_ATT[88])                               /* 0x68026160 */
#define PPC_R_ATT89                             ((PPC_R_ATT_Type*) &PPC->R_ATT[89])                               /* 0x68026164 */
#define PPC_R_ATT90                             ((PPC_R_ATT_Type*) &PPC->R_ATT[90])                               /* 0x68026168 */
#define PPC_R_ATT91                             ((PPC_R_ATT_Type*) &PPC->R_ATT[91])                               /* 0x6802616C */
#define PPC_R_ATT92                             ((PPC_R_ATT_Type*) &PPC->R_ATT[92])                               /* 0x68026170 */
#define PPC_R_ATT93                             ((PPC_R_ATT_Type*) &PPC->R_ATT[93])                               /* 0x68026174 */
#define PPC_R_ATT94                             ((PPC_R_ATT_Type*) &PPC->R_ATT[94])                               /* 0x68026178 */
#define PPC_R_ATT95                             ((PPC_R_ATT_Type*) &PPC->R_ATT[95])                               /* 0x6802617C */
#define PPC_R_ATT96                             ((PPC_R_ATT_Type*) &PPC->R_ATT[96])                               /* 0x68026180 */
#define PPC_R_ATT97                             ((PPC_R_ATT_Type*) &PPC->R_ATT[97])                               /* 0x68026184 */
#define PPC_R_ATT98                             ((PPC_R_ATT_Type*) &PPC->R_ATT[98])                               /* 0x68026188 */
#define PPC_R_ATT99                             ((PPC_R_ATT_Type*) &PPC->R_ATT[99])                               /* 0x6802618C */
#define PPC_R_ATT100                            ((PPC_R_ATT_Type*) &PPC->R_ATT[100])                              /* 0x68026190 */
#define PPC_R_ATT101                            ((PPC_R_ATT_Type*) &PPC->R_ATT[101])                              /* 0x68026194 */
#define PPC_R_ATT102                            ((PPC_R_ATT_Type*) &PPC->R_ATT[102])                              /* 0x68026198 */
#define PPC_R_ATT103                            ((PPC_R_ATT_Type*) &PPC->R_ATT[103])                              /* 0x6802619C */
#define PPC_R_ATT104                            ((PPC_R_ATT_Type*) &PPC->R_ATT[104])                              /* 0x680261A0 */
#define PPC_R_ATT105                            ((PPC_R_ATT_Type*) &PPC->R_ATT[105])                              /* 0x680261A4 */
#define PPC_R_ATT106                            ((PPC_R_ATT_Type*) &PPC->R_ATT[106])                              /* 0x680261A8 */
#define PPC_R_ATT107                            ((PPC_R_ATT_Type*) &PPC->R_ATT[107])                              /* 0x680261AC */
#define PPC_R_ATT108                            ((PPC_R_ATT_Type*) &PPC->R_ATT[108])                              /* 0x680261B0 */
#define PPC_R_ATT109                            ((PPC_R_ATT_Type*) &PPC->R_ATT[109])                              /* 0x680261B4 */
#define PPC_R_ATT110                            ((PPC_R_ATT_Type*) &PPC->R_ATT[110])                              /* 0x680261B8 */
#define PPC_R_ATT111                            ((PPC_R_ATT_Type*) &PPC->R_ATT[111])                              /* 0x680261BC */
#define PPC_R_ATT112                            ((PPC_R_ATT_Type*) &PPC->R_ATT[112])                              /* 0x680261C0 */
#define PPC_R_ATT113                            ((PPC_R_ATT_Type*) &PPC->R_ATT[113])                              /* 0x680261C4 */
#define PPC_R_ATT114                            ((PPC_R_ATT_Type*) &PPC->R_ATT[114])                              /* 0x680261C8 */
#define PPC_R_ATT115                            ((PPC_R_ATT_Type*) &PPC->R_ATT[115])                              /* 0x680261CC */
#define PPC_R_ATT116                            ((PPC_R_ATT_Type*) &PPC->R_ATT[116])                              /* 0x680261D0 */
#define PPC_R_ATT117                            ((PPC_R_ATT_Type*) &PPC->R_ATT[117])                              /* 0x680261D4 */
#define PPC_R_ATT118                            ((PPC_R_ATT_Type*) &PPC->R_ATT[118])                              /* 0x680261D8 */
#define PPC_R_ATT119                            ((PPC_R_ATT_Type*) &PPC->R_ATT[119])                              /* 0x680261DC */
#define PPC_R_ATT120                            ((PPC_R_ATT_Type*) &PPC->R_ATT[120])                              /* 0x680261E0 */
#define PPC_R_ATT121                            ((PPC_R_ATT_Type*) &PPC->R_ATT[121])                              /* 0x680261E4 */
#define PPC_R_ATT122                            ((PPC_R_ATT_Type*) &PPC->R_ATT[122])                              /* 0x680261E8 */
#define PPC_R_ATT123                            ((PPC_R_ATT_Type*) &PPC->R_ATT[123])                              /* 0x680261EC */
#define PPC_R_ATT124                            ((PPC_R_ATT_Type*) &PPC->R_ATT[124])                              /* 0x680261F0 */
#define PPC_R_ATT125                            ((PPC_R_ATT_Type*) &PPC->R_ATT[125])                              /* 0x680261F4 */
#define PPC_R_ATT126                            ((PPC_R_ATT_Type*) &PPC->R_ATT[126])                              /* 0x680261F8 */
#define PPC_R_ATT127                            ((PPC_R_ATT_Type*) &PPC->R_ATT[127])                              /* 0x680261FC */
#define PPC_R_ATT128                            ((PPC_R_ATT_Type*) &PPC->R_ATT[128])                              /* 0x68026200 */
#define PPC_R_ATT129                            ((PPC_R_ATT_Type*) &PPC->R_ATT[129])                              /* 0x68026204 */
#define PPC_R_ATT130                            ((PPC_R_ATT_Type*) &PPC->R_ATT[130])                              /* 0x68026208 */
#define PPC_R_ATT131                            ((PPC_R_ATT_Type*) &PPC->R_ATT[131])                              /* 0x6802620C */
#define PPC_R_ATT132                            ((PPC_R_ATT_Type*) &PPC->R_ATT[132])                              /* 0x68026210 */
#define PPC_R_ATT133                            ((PPC_R_ATT_Type*) &PPC->R_ATT[133])                              /* 0x68026214 */
#define PPC_R_ATT134                            ((PPC_R_ATT_Type*) &PPC->R_ATT[134])                              /* 0x68026218 */
#define PPC_R_ATT135                            ((PPC_R_ATT_Type*) &PPC->R_ATT[135])                              /* 0x6802621C */
#define PPC_R_ATT136                            ((PPC_R_ATT_Type*) &PPC->R_ATT[136])                              /* 0x68026220 */
#define PPC_R_ATT137                            ((PPC_R_ATT_Type*) &PPC->R_ATT[137])                              /* 0x68026224 */
#define PPC_R_ATT138                            ((PPC_R_ATT_Type*) &PPC->R_ATT[138])                              /* 0x68026228 */
#define PPC_R_ATT139                            ((PPC_R_ATT_Type*) &PPC->R_ATT[139])                              /* 0x6802622C */
#define PPC_R_ATT140                            ((PPC_R_ATT_Type*) &PPC->R_ATT[140])                              /* 0x68026230 */
#define PPC_R_ATT141                            ((PPC_R_ATT_Type*) &PPC->R_ATT[141])                              /* 0x68026234 */
#define PPC_R_ATT142                            ((PPC_R_ATT_Type*) &PPC->R_ATT[142])                              /* 0x68026238 */
#define PPC_R_ATT143                            ((PPC_R_ATT_Type*) &PPC->R_ATT[143])                              /* 0x6802623C */
#define PPC_R_ATT144                            ((PPC_R_ATT_Type*) &PPC->R_ATT[144])                              /* 0x68026240 */
#define PPC_R_ATT145                            ((PPC_R_ATT_Type*) &PPC->R_ATT[145])                              /* 0x68026244 */
#define PPC_R_ATT146                            ((PPC_R_ATT_Type*) &PPC->R_ATT[146])                              /* 0x68026248 */
#define PPC_R_ATT147                            ((PPC_R_ATT_Type*) &PPC->R_ATT[147])                              /* 0x6802624C */
#define PPC_R_ATT148                            ((PPC_R_ATT_Type*) &PPC->R_ATT[148])                              /* 0x68026250 */
#define PPC_R_ATT149                            ((PPC_R_ATT_Type*) &PPC->R_ATT[149])                              /* 0x68026254 */
#define PPC_R_ATT150                            ((PPC_R_ATT_Type*) &PPC->R_ATT[150])                              /* 0x68026258 */
#define PPC_R_ATT151                            ((PPC_R_ATT_Type*) &PPC->R_ATT[151])                              /* 0x6802625C */
#define PPC_R_ATT152                            ((PPC_R_ATT_Type*) &PPC->R_ATT[152])                              /* 0x68026260 */
#define PPC_R_ATT153                            ((PPC_R_ATT_Type*) &PPC->R_ATT[153])                              /* 0x68026264 */
#define PPC_R_ATT154                            ((PPC_R_ATT_Type*) &PPC->R_ATT[154])                              /* 0x68026268 */
#define PPC_R_ATT155                            ((PPC_R_ATT_Type*) &PPC->R_ATT[155])                              /* 0x6802626C */
#define PPC_R_ATT156                            ((PPC_R_ATT_Type*) &PPC->R_ATT[156])                              /* 0x68026270 */
#define PPC_R_ATT157                            ((PPC_R_ATT_Type*) &PPC->R_ATT[157])                              /* 0x68026274 */
#define PPC_R_ATT158                            ((PPC_R_ATT_Type*) &PPC->R_ATT[158])                              /* 0x68026278 */
#define PPC_R_ATT159                            ((PPC_R_ATT_Type*) &PPC->R_ATT[159])                              /* 0x6802627C */
#define PPC_R_ATT160                            ((PPC_R_ATT_Type*) &PPC->R_ATT[160])                              /* 0x68026280 */
#define PPC_R_ATT161                            ((PPC_R_ATT_Type*) &PPC->R_ATT[161])                              /* 0x68026284 */
#define PPC_R_ATT162                            ((PPC_R_ATT_Type*) &PPC->R_ATT[162])                              /* 0x68026288 */
#define PPC_R_ATT163                            ((PPC_R_ATT_Type*) &PPC->R_ATT[163])                              /* 0x6802628C */
#define PPC_R_ATT164                            ((PPC_R_ATT_Type*) &PPC->R_ATT[164])                              /* 0x68026290 */
#define PPC_R_ATT165                            ((PPC_R_ATT_Type*) &PPC->R_ATT[165])                              /* 0x68026294 */
#define PPC_R_ATT166                            ((PPC_R_ATT_Type*) &PPC->R_ATT[166])                              /* 0x68026298 */
#define PPC_R_ATT167                            ((PPC_R_ATT_Type*) &PPC->R_ATT[167])                              /* 0x6802629C */
#define PPC_R_ATT168                            ((PPC_R_ATT_Type*) &PPC->R_ATT[168])                              /* 0x680262A0 */
#define PPC_R_ATT169                            ((PPC_R_ATT_Type*) &PPC->R_ATT[169])                              /* 0x680262A4 */
#define PPC_R_ATT170                            ((PPC_R_ATT_Type*) &PPC->R_ATT[170])                              /* 0x680262A8 */
#define PPC_R_ATT171                            ((PPC_R_ATT_Type*) &PPC->R_ATT[171])                              /* 0x680262AC */
#define PPC_R_ATT172                            ((PPC_R_ATT_Type*) &PPC->R_ATT[172])                              /* 0x680262B0 */
#define PPC_R_ATT173                            ((PPC_R_ATT_Type*) &PPC->R_ATT[173])                              /* 0x680262B4 */
#define PPC_R_ATT174                            ((PPC_R_ATT_Type*) &PPC->R_ATT[174])                              /* 0x680262B8 */
#define PPC_R_ATT175                            ((PPC_R_ATT_Type*) &PPC->R_ATT[175])                              /* 0x680262BC */
#define PPC_R_ATT176                            ((PPC_R_ATT_Type*) &PPC->R_ATT[176])                              /* 0x680262C0 */
#define PPC_R_ATT177                            ((PPC_R_ATT_Type*) &PPC->R_ATT[177])                              /* 0x680262C4 */
#define PPC_R_ATT178                            ((PPC_R_ATT_Type*) &PPC->R_ATT[178])                              /* 0x680262C8 */
#define PPC_R_ATT179                            ((PPC_R_ATT_Type*) &PPC->R_ATT[179])                              /* 0x680262CC */
#define PPC_R_ATT180                            ((PPC_R_ATT_Type*) &PPC->R_ATT[180])                              /* 0x680262D0 */
#define PPC_R_ATT181                            ((PPC_R_ATT_Type*) &PPC->R_ATT[181])                              /* 0x680262D4 */
#define PPC_R_ATT182                            ((PPC_R_ATT_Type*) &PPC->R_ATT[182])                              /* 0x680262D8 */
#define PPC_R_ATT183                            ((PPC_R_ATT_Type*) &PPC->R_ATT[183])                              /* 0x680262DC */
#define PPC_R_ATT184                            ((PPC_R_ATT_Type*) &PPC->R_ATT[184])                              /* 0x680262E0 */
#define PPC_R_ATT185                            ((PPC_R_ATT_Type*) &PPC->R_ATT[185])                              /* 0x680262E4 */
#define PPC_R_ATT186                            ((PPC_R_ATT_Type*) &PPC->R_ATT[186])                              /* 0x680262E8 */
#define PPC_R_ATT187                            ((PPC_R_ATT_Type*) &PPC->R_ATT[187])                              /* 0x680262EC */
#define PPC_R_ATT188                            ((PPC_R_ATT_Type*) &PPC->R_ATT[188])                              /* 0x680262F0 */
#define PPC_R_ATT189                            ((PPC_R_ATT_Type*) &PPC->R_ATT[189])                              /* 0x680262F4 */
#define PPC_R_ATT190                            ((PPC_R_ATT_Type*) &PPC->R_ATT[190])                              /* 0x680262F8 */
#define PPC_R_ATT191                            ((PPC_R_ATT_Type*) &PPC->R_ATT[191])                              /* 0x680262FC */
#define PPC_R_ATT192                            ((PPC_R_ATT_Type*) &PPC->R_ATT[192])                              /* 0x68026300 */
#define PPC_R_ATT193                            ((PPC_R_ATT_Type*) &PPC->R_ATT[193])                              /* 0x68026304 */
#define PPC_R_ATT194                            ((PPC_R_ATT_Type*) &PPC->R_ATT[194])                              /* 0x68026308 */
#define PPC_R_ATT195                            ((PPC_R_ATT_Type*) &PPC->R_ATT[195])                              /* 0x6802630C */
#define PPC_R_ATT196                            ((PPC_R_ATT_Type*) &PPC->R_ATT[196])                              /* 0x68026310 */
#define PPC_R_ATT197                            ((PPC_R_ATT_Type*) &PPC->R_ATT[197])                              /* 0x68026314 */
#define PPC_R_ATT198                            ((PPC_R_ATT_Type*) &PPC->R_ATT[198])                              /* 0x68026318 */
#define PPC_R_ATT199                            ((PPC_R_ATT_Type*) &PPC->R_ATT[199])                              /* 0x6802631C */
#define PPC_R_ATT200                            ((PPC_R_ATT_Type*) &PPC->R_ATT[200])                              /* 0x68026320 */
#define PPC_R_ATT201                            ((PPC_R_ATT_Type*) &PPC->R_ATT[201])                              /* 0x68026324 */
#define PPC_R_ATT202                            ((PPC_R_ATT_Type*) &PPC->R_ATT[202])                              /* 0x68026328 */
#define PPC_R_ATT203                            ((PPC_R_ATT_Type*) &PPC->R_ATT[203])                              /* 0x6802632C */
#define PPC_R_ATT204                            ((PPC_R_ATT_Type*) &PPC->R_ATT[204])                              /* 0x68026330 */
#define PPC_R_ATT205                            ((PPC_R_ATT_Type*) &PPC->R_ATT[205])                              /* 0x68026334 */
#define PPC_R_ATT206                            ((PPC_R_ATT_Type*) &PPC->R_ATT[206])                              /* 0x68026338 */
#define PPC_R_ATT207                            ((PPC_R_ATT_Type*) &PPC->R_ATT[207])                              /* 0x6802633C */
#define PPC_R_ATT208                            ((PPC_R_ATT_Type*) &PPC->R_ATT[208])                              /* 0x68026340 */
#define PPC_R_ATT209                            ((PPC_R_ATT_Type*) &PPC->R_ATT[209])                              /* 0x68026344 */
#define PPC_R_ATT210                            ((PPC_R_ATT_Type*) &PPC->R_ATT[210])                              /* 0x68026348 */
#define PPC_R_ATT211                            ((PPC_R_ATT_Type*) &PPC->R_ATT[211])                              /* 0x6802634C */
#define PPC_R_ATT212                            ((PPC_R_ATT_Type*) &PPC->R_ATT[212])                              /* 0x68026350 */
#define PPC_R_ATT213                            ((PPC_R_ATT_Type*) &PPC->R_ATT[213])                              /* 0x68026354 */
#define PPC_R_ATT214                            ((PPC_R_ATT_Type*) &PPC->R_ATT[214])                              /* 0x68026358 */
#define PPC_R_ATT215                            ((PPC_R_ATT_Type*) &PPC->R_ATT[215])                              /* 0x6802635C */
#define PPC_R_ATT216                            ((PPC_R_ATT_Type*) &PPC->R_ATT[216])                              /* 0x68026360 */
#define PPC_R_ATT217                            ((PPC_R_ATT_Type*) &PPC->R_ATT[217])                              /* 0x68026364 */
#define PPC_R_ATT218                            ((PPC_R_ATT_Type*) &PPC->R_ATT[218])                              /* 0x68026368 */
#define PPC_R_ATT219                            ((PPC_R_ATT_Type*) &PPC->R_ATT[219])                              /* 0x6802636C */
#define PPC_R_ATT220                            ((PPC_R_ATT_Type*) &PPC->R_ATT[220])                              /* 0x68026370 */
#define PPC_R_ATT221                            ((PPC_R_ATT_Type*) &PPC->R_ATT[221])                              /* 0x68026374 */
#define PPC_R_ATT222                            ((PPC_R_ATT_Type*) &PPC->R_ATT[222])                              /* 0x68026378 */
#define PPC_R_ATT223                            ((PPC_R_ATT_Type*) &PPC->R_ATT[223])                              /* 0x6802637C */
#define PPC_R_ATT224                            ((PPC_R_ATT_Type*) &PPC->R_ATT[224])                              /* 0x68026380 */
#define PPC_R_ATT225                            ((PPC_R_ATT_Type*) &PPC->R_ATT[225])                              /* 0x68026384 */
#define PPC_R_ATT226                            ((PPC_R_ATT_Type*) &PPC->R_ATT[226])                              /* 0x68026388 */
#define PPC_R_ATT227                            ((PPC_R_ATT_Type*) &PPC->R_ATT[227])                              /* 0x6802638C */
#define PPC_R_ATT228                            ((PPC_R_ATT_Type*) &PPC->R_ATT[228])                              /* 0x68026390 */
#define PPC_R_ATT229                            ((PPC_R_ATT_Type*) &PPC->R_ATT[229])                              /* 0x68026394 */
#define PPC_R_ATT230                            ((PPC_R_ATT_Type*) &PPC->R_ATT[230])                              /* 0x68026398 */
#define PPC_R_ATT231                            ((PPC_R_ATT_Type*) &PPC->R_ATT[231])                              /* 0x6802639C */
#define PPC_R_ATT232                            ((PPC_R_ATT_Type*) &PPC->R_ATT[232])                              /* 0x680263A0 */
#define PPC_R_ATT233                            ((PPC_R_ATT_Type*) &PPC->R_ATT[233])                              /* 0x680263A4 */
#define PPC_R_ATT234                            ((PPC_R_ATT_Type*) &PPC->R_ATT[234])                              /* 0x680263A8 */
#define PPC_R_ATT235                            ((PPC_R_ATT_Type*) &PPC->R_ATT[235])                              /* 0x680263AC */
#define PPC_R_ATT236                            ((PPC_R_ATT_Type*) &PPC->R_ATT[236])                              /* 0x680263B0 */
#define PPC_R_ATT237                            ((PPC_R_ATT_Type*) &PPC->R_ATT[237])                              /* 0x680263B4 */
#define PPC_R_ATT238                            ((PPC_R_ATT_Type*) &PPC->R_ATT[238])                              /* 0x680263B8 */
#define PPC_R_ATT239                            ((PPC_R_ATT_Type*) &PPC->R_ATT[239])                              /* 0x680263BC */
#define PPC_R_ATT240                            ((PPC_R_ATT_Type*) &PPC->R_ATT[240])                              /* 0x680263C0 */
#define PPC_R_ATT241                            ((PPC_R_ATT_Type*) &PPC->R_ATT[241])                              /* 0x680263C4 */
#define PPC_R_ATT242                            ((PPC_R_ATT_Type*) &PPC->R_ATT[242])                              /* 0x680263C8 */
#define PPC_R_ATT243                            ((PPC_R_ATT_Type*) &PPC->R_ATT[243])                              /* 0x680263CC */
#define PPC_R_ATT244                            ((PPC_R_ATT_Type*) &PPC->R_ATT[244])                              /* 0x680263D0 */
#define PPC_R_ATT245                            ((PPC_R_ATT_Type*) &PPC->R_ATT[245])                              /* 0x680263D4 */
#define PPC_R_ATT246                            ((PPC_R_ATT_Type*) &PPC->R_ATT[246])                              /* 0x680263D8 */
#define PPC_R_ATT247                            ((PPC_R_ATT_Type*) &PPC->R_ATT[247])                              /* 0x680263DC */
#define PPC_R_ATT248                            ((PPC_R_ATT_Type*) &PPC->R_ATT[248])                              /* 0x680263E0 */
#define PPC_R_ATT249                            ((PPC_R_ATT_Type*) &PPC->R_ATT[249])                              /* 0x680263E4 */
#define PPC_R_ATT250                            ((PPC_R_ATT_Type*) &PPC->R_ATT[250])                              /* 0x680263E8 */
#define PPC_R_ATT251                            ((PPC_R_ATT_Type*) &PPC->R_ATT[251])                              /* 0x680263EC */
#define PPC_R_ATT252                            ((PPC_R_ATT_Type*) &PPC->R_ATT[252])                              /* 0x680263F0 */
#define PPC_R_ATT253                            ((PPC_R_ATT_Type*) &PPC->R_ATT[253])                              /* 0x680263F4 */
#define PPC_R_ATT254                            ((PPC_R_ATT_Type*) &PPC->R_ATT[254])                              /* 0x680263F8 */
#define PPC_R_ATT255                            ((PPC_R_ATT_Type*) &PPC->R_ATT[255])                              /* 0x680263FC */
#define PPC_R_ATT256                            ((PPC_R_ATT_Type*) &PPC->R_ATT[256])                              /* 0x68026400 */
#define PPC_R_ATT257                            ((PPC_R_ATT_Type*) &PPC->R_ATT[257])                              /* 0x68026404 */
#define PPC_R_ATT258                            ((PPC_R_ATT_Type*) &PPC->R_ATT[258])                              /* 0x68026408 */
#define PPC_R_ATT259                            ((PPC_R_ATT_Type*) &PPC->R_ATT[259])                              /* 0x6802640C */
#define PPC_R_ATT260                            ((PPC_R_ATT_Type*) &PPC->R_ATT[260])                              /* 0x68026410 */
#define PPC_R_ATT261                            ((PPC_R_ATT_Type*) &PPC->R_ATT[261])                              /* 0x68026414 */
#define PPC_R_ATT262                            ((PPC_R_ATT_Type*) &PPC->R_ATT[262])                              /* 0x68026418 */
#define PPC_R_ATT263                            ((PPC_R_ATT_Type*) &PPC->R_ATT[263])                              /* 0x6802641C */
#define PPC_R_ATT264                            ((PPC_R_ATT_Type*) &PPC->R_ATT[264])                              /* 0x68026420 */
#define PPC_R_ATT265                            ((PPC_R_ATT_Type*) &PPC->R_ATT[265])                              /* 0x68026424 */
#define PPC_R_ATT266                            ((PPC_R_ATT_Type*) &PPC->R_ATT[266])                              /* 0x68026428 */
#define PPC_R_ATT267                            ((PPC_R_ATT_Type*) &PPC->R_ATT[267])                              /* 0x6802642C */
#define PPC_R_ATT268                            ((PPC_R_ATT_Type*) &PPC->R_ATT[268])                              /* 0x68026430 */
#define PPC_R_ATT269                            ((PPC_R_ATT_Type*) &PPC->R_ATT[269])                              /* 0x68026434 */
#define PPC_R_ATT270                            ((PPC_R_ATT_Type*) &PPC->R_ATT[270])                              /* 0x68026438 */
#define PPC_R_ATT271                            ((PPC_R_ATT_Type*) &PPC->R_ATT[271])                              /* 0x6802643C */
#define PPC_R_ATT272                            ((PPC_R_ATT_Type*) &PPC->R_ATT[272])                              /* 0x68026440 */
#define PPC_R_ATT273                            ((PPC_R_ATT_Type*) &PPC->R_ATT[273])                              /* 0x68026444 */
#define PPC_R_ATT274                            ((PPC_R_ATT_Type*) &PPC->R_ATT[274])                              /* 0x68026448 */
#define PPC_R_ATT275                            ((PPC_R_ATT_Type*) &PPC->R_ATT[275])                              /* 0x6802644C */
#define PPC_R_ATT276                            ((PPC_R_ATT_Type*) &PPC->R_ATT[276])                              /* 0x68026450 */
#define PPC_R_ATT277                            ((PPC_R_ATT_Type*) &PPC->R_ATT[277])                              /* 0x68026454 */
#define PPC_R_ATT278                            ((PPC_R_ATT_Type*) &PPC->R_ATT[278])                              /* 0x68026458 */
#define PPC_R_ATT279                            ((PPC_R_ATT_Type*) &PPC->R_ATT[279])                              /* 0x6802645C */
#define PPC_R_ATT280                            ((PPC_R_ATT_Type*) &PPC->R_ATT[280])                              /* 0x68026460 */
#define PPC_R_ATT281                            ((PPC_R_ATT_Type*) &PPC->R_ATT[281])                              /* 0x68026464 */
#define PPC_R_ATT282                            ((PPC_R_ATT_Type*) &PPC->R_ATT[282])                              /* 0x68026468 */
#define PPC_R_ATT283                            ((PPC_R_ATT_Type*) &PPC->R_ATT[283])                              /* 0x6802646C */
#define PPC_R_ATT284                            ((PPC_R_ATT_Type*) &PPC->R_ATT[284])                              /* 0x68026470 */
#define PPC_R_ATT285                            ((PPC_R_ATT_Type*) &PPC->R_ATT[285])                              /* 0x68026474 */
#define PPC_R_ATT286                            ((PPC_R_ATT_Type*) &PPC->R_ATT[286])                              /* 0x68026478 */
#define PPC_R_ATT287                            ((PPC_R_ATT_Type*) &PPC->R_ATT[287])                              /* 0x6802647C */
#define PPC_R_ATT288                            ((PPC_R_ATT_Type*) &PPC->R_ATT[288])                              /* 0x68026480 */
#define PPC_R_ATT289                            ((PPC_R_ATT_Type*) &PPC->R_ATT[289])                              /* 0x68026484 */
#define PPC_R_ATT290                            ((PPC_R_ATT_Type*) &PPC->R_ATT[290])                              /* 0x68026488 */
#define PPC_R_ATT291                            ((PPC_R_ATT_Type*) &PPC->R_ATT[291])                              /* 0x6802648C */
#define PPC_R_ATT292                            ((PPC_R_ATT_Type*) &PPC->R_ATT[292])                              /* 0x68026490 */
#define PPC_R_ATT293                            ((PPC_R_ATT_Type*) &PPC->R_ATT[293])                              /* 0x68026494 */
#define PPC_R_ATT294                            ((PPC_R_ATT_Type*) &PPC->R_ATT[294])                              /* 0x68026498 */
#define PPC_R_ATT295                            ((PPC_R_ATT_Type*) &PPC->R_ATT[295])                              /* 0x6802649C */
#define PPC_R_ATT296                            ((PPC_R_ATT_Type*) &PPC->R_ATT[296])                              /* 0x680264A0 */

/*******************************************************************************
*                                  PERI_PCLK
*******************************************************************************/

#define PERI_PCLK_BASE                          0x68040000UL
#define PERI_PCLK                               ((PERI_PCLK_Type*) PERI_PCLK_BASE)                                /* 0x68040000 */
#define PERI_PCLK_GR0                           ((PERI_PCLK_GR_Type*) &PERI_PCLK->GR[0])                          /* 0x68040000 */
#define PERI_PCLK_GR1                           ((PERI_PCLK_GR_Type*) &PERI_PCLK->GR[1])                          /* 0x68042000 */
#define PERI_PCLK_GR2                           ((PERI_PCLK_GR_Type*) &PERI_PCLK->GR[2])                          /* 0x68044000 */
#define PERI_PCLK_GR3                           ((PERI_PCLK_GR_Type*) &PERI_PCLK->GR[3])                          /* 0x68046000 */
#define PERI_PCLK_GR4                           ((PERI_PCLK_GR_Type*) &PERI_PCLK->GR[4])                          /* 0x68048000 */
#define PERI_PCLK_GR5                           ((PERI_PCLK_GR_Type*) &PERI_PCLK->GR[5])                          /* 0x6804A000 */

/*******************************************************************************
*                                   RAMC_PPU
*******************************************************************************/

#define RAMC_PPU0_BASE                          0x68100000UL
#define RAMC_PPU1_BASE                          0x68101000UL
#define RAMC_PPU0                               ((RAMC_PPU_Type*) RAMC_PPU0_BASE)                                 /* 0x68100000 */
#define RAMC_PPU1                               ((RAMC_PPU_Type*) RAMC_PPU1_BASE)                                 /* 0x68101000 */

/*******************************************************************************
*                                    ICACHE
*******************************************************************************/

#define ICACHE0_BASE                            0x68103000UL
#define ICACHE0                                 ((ICACHE_Type*) ICACHE0_BASE)                                     /* 0x68103000 */

/*******************************************************************************
*                                  CPUSS_PPU
*******************************************************************************/

#define CPUSS_PPU_BASE                          0x68105000UL
#define CPUSS_PPU                               ((CPUSS_PPU_Type*) CPUSS_PPU_BASE)                                /* 0x68105000 */

/*******************************************************************************
*                                     RAMC
*******************************************************************************/

#define RAMC0_BASE                              0x68110000UL
#define RAMC1_BASE                              0x68120000UL
#define RAMC0                                   ((RAMC_Type*) RAMC0_BASE)                                         /* 0x68110000 */
#define RAMC1                                   ((RAMC_Type*) RAMC1_BASE)                                         /* 0x68120000 */
#define RAMC0_MPC0                              ((RAMC_MPC_Type*) &RAMC0->MPC[0])                                 /* 0x68114000 */
#define RAMC1_MPC0                              ((RAMC_MPC_Type*) &RAMC1->MPC[0])                                 /* 0x68124000 */

/*******************************************************************************
*                                    PROMC
*******************************************************************************/

#define PROMC_BASE                              0x68140000UL
#define PROMC                                   ((PROMC_Type*) PROMC_BASE)                                        /* 0x68140000 */
#define PROMC_MPC0                              ((PROMC_MPC_Type*) &PROMC->MPC[0])                                /* 0x68141000 */

/*******************************************************************************
*                                    FLASHC
*******************************************************************************/

#define FLASHC_BASE                             0x68150000UL
#define FLASHC                                  ((FLASHC_Type*) FLASHC_BASE)                                      /* 0x68150000 */
#define FLASHC_MPC0                             ((FLASHC_MPC_Type*) &FLASHC->MPC[0])                              /* 0x68151000 */
#define FLASHC_FM_CTL                           ((FLASHC_FM_CTL_Type*) &FLASHC->FM_CTL)                           /* 0x68152000 */

/*******************************************************************************
*                                    MXCM33
*******************************************************************************/

#define MXCM33_BASE                             0x68160000UL
#define MXCM33                                  ((MXCM33_Type*) MXCM33_BASE)                                      /* 0x68160000 */

/*******************************************************************************
*                                      DW
*******************************************************************************/

#define DW0_BASE                                0x68180000UL
#define DW0                                     ((DW_Type*) DW0_BASE)                                             /* 0x68180000 */
#define DW0_CH_STRUCT0                          ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[0])                         /* 0x68188000 */
#define DW0_CH_STRUCT1                          ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[1])                         /* 0x68188040 */
#define DW0_CH_STRUCT2                          ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[2])                         /* 0x68188080 */
#define DW0_CH_STRUCT3                          ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[3])                         /* 0x681880C0 */
#define DW0_CH_STRUCT4                          ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[4])                         /* 0x68188100 */
#define DW0_CH_STRUCT5                          ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[5])                         /* 0x68188140 */
#define DW0_CH_STRUCT6                          ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[6])                         /* 0x68188180 */
#define DW0_CH_STRUCT7                          ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[7])                         /* 0x681881C0 */
#define DW0_CH_STRUCT8                          ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[8])                         /* 0x68188200 */
#define DW0_CH_STRUCT9                          ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[9])                         /* 0x68188240 */
#define DW0_CH_STRUCT10                         ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[10])                        /* 0x68188280 */
#define DW0_CH_STRUCT11                         ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[11])                        /* 0x681882C0 */
#define DW0_CH_STRUCT12                         ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[12])                        /* 0x68188300 */
#define DW0_CH_STRUCT13                         ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[13])                        /* 0x68188340 */
#define DW0_CH_STRUCT14                         ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[14])                        /* 0x68188380 */
#define DW0_CH_STRUCT15                         ((DW_CH_STRUCT_Type*) &DW0->CH_STRUCT[15])                        /* 0x681883C0 */

/*******************************************************************************
*                                    CPUSS
*******************************************************************************/

#define CPUSS_BASE                              0x681C0000UL
#define CPUSS                                   ((CPUSS_Type*) CPUSS_BASE)                                        /* 0x681C0000 */

/*******************************************************************************
*                                  MS_CTL_2_1
*******************************************************************************/

#define MS_CTL_2_1_BASE                         0x681C4000UL
#define MS_CTL_2_1                              ((MS_CTL_2_1_Type*) MS_CTL_2_1_BASE)                              /* 0x681C4000 */
#define MS0                                     ((MS_Type*) &MS_CTL_2_1->MS[0])                                   /* 0x681C4000 */
#define MS4                                     ((MS_Type*) &MS_CTL_2_1->MS[4])                                   /* 0x681C4040 */
#define MS7                                     ((MS_Type*) &MS_CTL_2_1->MS[7])                                   /* 0x681C4070 */
#define MS9                                     ((MS_Type*) &MS_CTL_2_1->MS[9])                                   /* 0x681C4090 */
#define MS31                                    ((MS_Type*) &MS_CTL_2_1->MS[31])                                  /* 0x681C41F0 */
#define MS_PC0                                  ((MS_PC_Type*) &MS_CTL_2_1->MS_PC[0])                             /* 0x681C5000 */
#define MS_PC4                                  ((MS_PC_Type*) &MS_CTL_2_1->MS_PC[4])                             /* 0x681C5040 */
#define MS_PC7                                  ((MS_PC_Type*) &MS_CTL_2_1->MS_PC[7])                             /* 0x681C5070 */
#define MS_PC9                                  ((MS_PC_Type*) &MS_CTL_2_1->MS_PC[9])                             /* 0x681C5090 */
#define MS_PC31                                 ((MS_PC_Type*) &MS_CTL_2_1->MS_PC[31])                            /* 0x681C51F0 */

/*******************************************************************************
*                                 CPUSS_SL_CTL
*******************************************************************************/

#define CPUSS_SL_CTL_BASE                       0x681C8000UL
#define CPUSS_SL_CTL                            ((CPUSS_SL_CTL_Type*) CPUSS_SL_CTL_BASE)                          /* 0x681C8000 */

/*******************************************************************************
*                                     IPC
*******************************************************************************/

#define IPC_BASE                                0x681D0000UL
#define IPC                                     ((IPC_Type*) IPC_BASE)                                            /* 0x681D0000 */
#define IPC_STRUCT0                             ((IPC_STRUCT_Type*) &IPC->STRUCT[0])                              /* 0x681D0000 */
#define IPC_STRUCT1                             ((IPC_STRUCT_Type*) &IPC->STRUCT[1])                              /* 0x681D0020 */
#define IPC_STRUCT2                             ((IPC_STRUCT_Type*) &IPC->STRUCT[2])                              /* 0x681D0040 */
#define IPC_STRUCT3                             ((IPC_STRUCT_Type*) &IPC->STRUCT[3])                              /* 0x681D0060 */
#define IPC_STRUCT4                             ((IPC_STRUCT_Type*) &IPC->STRUCT[4])                              /* 0x681D0080 */
#define IPC_STRUCT5                             ((IPC_STRUCT_Type*) &IPC->STRUCT[5])                              /* 0x681D00A0 */
#define IPC_STRUCT6                             ((IPC_STRUCT_Type*) &IPC->STRUCT[6])                              /* 0x681D00C0 */
#define IPC_STRUCT7                             ((IPC_STRUCT_Type*) &IPC->STRUCT[7])                              /* 0x681D00E0 */
#define IPC_INTR_STRUCT0                        ((IPC_INTR_STRUCT_Type*) &IPC->INTR_STRUCT[0])                    /* 0x681D1000 */
#define IPC_INTR_STRUCT1                        ((IPC_INTR_STRUCT_Type*) &IPC->INTR_STRUCT[1])                    /* 0x681D1020 */
#define IPC_INTR_STRUCT2                        ((IPC_INTR_STRUCT_Type*) &IPC->INTR_STRUCT[2])                    /* 0x681D1040 */
#define IPC_INTR_STRUCT3                        ((IPC_INTR_STRUCT_Type*) &IPC->INTR_STRUCT[3])                    /* 0x681D1060 */

/*******************************************************************************
*                                    FAULT
*******************************************************************************/

#define FAULT_BASE                              0x681E0000UL
#define FAULT                                   ((FAULT_Type*) FAULT_BASE)                                        /* 0x681E0000 */
#define FAULT_STRUCT0                           ((FAULT_STRUCT_Type*) &FAULT->STRUCT[0])                          /* 0x681E0000 */

/*******************************************************************************
*                                     SRSS
*******************************************************************************/

#define SRSS_BASE                               0x68200000UL
#define SRSS                                    ((SRSS_Type*) SRSS_BASE)                                          /* 0x68200000 */
#define CSV_HF                                  ((CSV_HF_Type*) &SRSS->CSV_HF_STRUCT)                             /* 0x68201400 */
#define CSV_HF_CSV0                             ((CSV_HF_CSV_Type*) &SRSS->CSV_HF_STRUCT.CSV[0])                  /* 0x68201400 */
#define CSV_HF_CSV1                             ((CSV_HF_CSV_Type*) &SRSS->CSV_HF_STRUCT.CSV[1])                  /* 0x68201410 */
#define CSV_HF_CSV2                             ((CSV_HF_CSV_Type*) &SRSS->CSV_HF_STRUCT.CSV[2])                  /* 0x68201420 */
#define CSV_HF_CSV3                             ((CSV_HF_CSV_Type*) &SRSS->CSV_HF_STRUCT.CSV[3])                  /* 0x68201430 */
#define CSV_HF_CSV4                             ((CSV_HF_CSV_Type*) &SRSS->CSV_HF_STRUCT.CSV[4])                  /* 0x68201440 */
#define CSV_HF_CSV5                             ((CSV_HF_CSV_Type*) &SRSS->CSV_HF_STRUCT.CSV[5])                  /* 0x68201450 */
#define CSV_HF_CSV6                             ((CSV_HF_CSV_Type*) &SRSS->CSV_HF_STRUCT.CSV[6])                  /* 0x68201460 */
#define CSV_REF                                 ((CSV_REF_Type*) &SRSS->CSV_REF_STRUCT)                           /* 0x68201710 */
#define CSV_REF_CSV                             ((CSV_REF_CSV_Type*) &SRSS->CSV_REF_STRUCT.CSV)                   /* 0x68201710 */
#define CSV_LF                                  ((CSV_LF_Type*) &SRSS->CSV_LF_STRUCT)                             /* 0x68201720 */
#define CSV_LF_CSV                              ((CSV_LF_CSV_Type*) &SRSS->CSV_LF_STRUCT.CSV)                     /* 0x68201720 */
#define CSV_ILO                                 ((CSV_ILO_Type*) &SRSS->CSV_ILO_STRUCT)                           /* 0x68201730 */
#define CSV_ILO_CSV                             ((CSV_ILO_CSV_Type*) &SRSS->CSV_ILO_STRUCT.CSV)                   /* 0x68201730 */
#define CLK_DPLL_LP0                            ((CLK_DPLL_LP_Type*) &SRSS->CLK_DPLL_LP[0])                       /* 0x68201A00 */
#define CLK_DPLL_LP1                            ((CLK_DPLL_LP_Type*) &SRSS->CLK_DPLL_LP[1])                       /* 0x68201A20 */
#define RAM_TRIM                                ((RAM_TRIM_Type*) &SRSS->RAM_TRIM_STRUCT)                         /* 0x68204000 */
#define CLK_TRIM_DPLL_LP0                       ((CLK_TRIM_DPLL_LP_Type*) &SRSS->CLK_TRIM_DPLL_LP[0])             /* 0x68204200 */
#define CLK_TRIM_DPLL_LP1                       ((CLK_TRIM_DPLL_LP_Type*) &SRSS->CLK_TRIM_DPLL_LP[1])             /* 0x68204220 */
#define MCWDT_STRUCT0                           ((MCWDT_STRUCT_Type*) &SRSS->MCWDT_STRUCT[0])                     /* 0x6820D000 */

/*******************************************************************************
*                                   PWRMODE
*******************************************************************************/

#define PWRMODE_BASE                            0x68210000UL
#define PWRMODE                                 ((PWRMODE_Type*) PWRMODE_BASE)                                    /* 0x68210000 */
#define PWRMODE_PD0                             ((PWRMODE_PD_Type*) &PWRMODE->PD[0])                              /* 0x68210000 */
#define PWRMODE_PD1                             ((PWRMODE_PD_Type*) &PWRMODE->PD[1])                              /* 0x68210010 */
#define PWRMODE_PD2                             ((PWRMODE_PD_Type*) &PWRMODE->PD[2])                              /* 0x68210020 */
#define PWRMODE_PD3                             ((PWRMODE_PD_Type*) &PWRMODE->PD[3])                              /* 0x68210030 */
#define PWRMODE_PD4                             ((PWRMODE_PD_Type*) &PWRMODE->PD[4])                              /* 0x68210040 */
#define PWRMODE_PD5                             ((PWRMODE_PD_Type*) &PWRMODE->PD[5])                              /* 0x68210050 */
#define PWRMODE_PD6                             ((PWRMODE_PD_Type*) &PWRMODE->PD[6])                              /* 0x68210060 */
#define PWRMODE_PD7                             ((PWRMODE_PD_Type*) &PWRMODE->PD[7])                              /* 0x68210070 */
#define PWRMODE_PD8                             ((PWRMODE_PD_Type*) &PWRMODE->PD[8])                              /* 0x68210080 */
#define PWRMODE_PD9                             ((PWRMODE_PD_Type*) &PWRMODE->PD[9])                              /* 0x68210090 */
#define PWRMODE_PD10                            ((PWRMODE_PD_Type*) &PWRMODE->PD[10])                             /* 0x682100A0 */
#define PWRMODE_PD11                            ((PWRMODE_PD_Type*) &PWRMODE->PD[11])                             /* 0x682100B0 */
#define PWRMODE_PD12                            ((PWRMODE_PD_Type*) &PWRMODE->PD[12])                             /* 0x682100C0 */
#define PWRMODE_PD13                            ((PWRMODE_PD_Type*) &PWRMODE->PD[13])                             /* 0x682100D0 */
#define PWRMODE_PD14                            ((PWRMODE_PD_Type*) &PWRMODE->PD[14])                             /* 0x682100E0 */
#define PWRMODE_PD15                            ((PWRMODE_PD_Type*) &PWRMODE->PD[15])                             /* 0x682100F0 */
#define PWRMODE_PPU_MAIN                        ((PWRMODE_PPU_MAIN_Type*) &PWRMODE->PPU_MAIN)                     /* 0x68211000 */
#define PWRMODE_PPU_MAIN_PPU_MAIN               ((PWRMODE_PPU_MAIN_PPU_MAIN_Type*) &PWRMODE->PPU_MAIN.PPU_MAIN)   /* 0x68211000 */

/*******************************************************************************
*                                    BACKUP
*******************************************************************************/

#define BACKUP_BASE                             0x68220000UL
#define BACKUP                                  ((BACKUP_Type*) BACKUP_BASE)                                      /* 0x68220000 */

/*******************************************************************************
*                                  CRYPTOLITE
*******************************************************************************/

#define CRYPTOLITE_BASE                         0x68230000UL
#define CRYPTOLITE                              ((CRYPTOLITE_Type*) CRYPTOLITE_BASE)                              /* 0x68230000 */

/*******************************************************************************
*                                   MXWOUND
*******************************************************************************/

#define MXWOUND_BASE                            0x68240000UL
#define MXWOUND                                 ((MXWOUND_Type*) MXWOUND_BASE)                                    /* 0x68240000 */
#define MXWOUND_MXWOUND_PROP0                   ((MXWOUND_MXWOUND_PROP_Type*) &MXWOUND->MXWOUND_PROP[0])          /* 0x68240100 */

/*******************************************************************************
*                                   DEBUG600
*******************************************************************************/

#define DEBUG600_BASE                           0x68250000UL
#define DEBUG600                                ((DEBUG600_Type*) DEBUG600_BASE)                                  /* 0x68250000 */

/*******************************************************************************
*                                     SVGS
*******************************************************************************/

#define SVGS_BASE                               0x68260000UL
#define SVGS                                    ((SVGS_Type*) SVGS_BASE)                                          /* 0x68260000 */
#define SVGS_SVGS_MAIN                          ((SVGS_SVGS_MAIN_Type*) &SVGS->SVGS_MAIN)                         /* 0x68260000 */

/*******************************************************************************
*                                    MXAES
*******************************************************************************/

#define MXAES_BASE                              0x68270000UL
#define MXAES                                   ((MXAES_Type*) MXAES_BASE)                                        /* 0x68270000 */
#define MXAES_UNMASKED_USER_RANGE               ((MXAES_UNMASKED_USER_RANGE_Type*) &MXAES->UNMASKED_USER_RANGE)   /* 0x68270000 */
#define MXAES_UNMASKED_INTERNAL_RANGE           ((MXAES_UNMASKED_INTERNAL_RANGE_Type*) &MXAES->UNMASKED_INTERNAL_RANGE) /* 0x68270800 */
#define MXAES_MASKED_USER_RANGE                 ((MXAES_MASKED_USER_RANGE_Type*) &MXAES->MASKED_USER_RANGE)       /* 0x68271000 */
#define MXAES_MASKED_INTERNAL_RANGE             ((MXAES_MASKED_INTERNAL_RANGE_Type*) &MXAES->MASKED_INTERNAL_RANGE) /* 0x68271800 */

/*******************************************************************************
*                                    HSIOM
*******************************************************************************/

#define HSIOM_BASE                              0x68400000UL
#define HSIOM                                   ((HSIOM_Type*) HSIOM_BASE)                                        /* 0x68400000 */
#define HSIOM_PRT0                              ((HSIOM_PRT_Type*) &HSIOM->PRT[0])                                /* 0x68400000 */
#define HSIOM_PRT1                              ((HSIOM_PRT_Type*) &HSIOM->PRT[1])                                /* 0x68400010 */
#define HSIOM_PRT2                              ((HSIOM_PRT_Type*) &HSIOM->PRT[2])                                /* 0x68400020 */
#define HSIOM_PRT3                              ((HSIOM_PRT_Type*) &HSIOM->PRT[3])                                /* 0x68400030 */
#define HSIOM_PRT4                              ((HSIOM_PRT_Type*) &HSIOM->PRT[4])                                /* 0x68400040 */
#define HSIOM_PRT5                              ((HSIOM_PRT_Type*) &HSIOM->PRT[5])                                /* 0x68400050 */
#define HSIOM_PRT6                              ((HSIOM_PRT_Type*) &HSIOM->PRT[6])                                /* 0x68400060 */
#define HSIOM_PRT7                              ((HSIOM_PRT_Type*) &HSIOM->PRT[7])                                /* 0x68400070 */
#define HSIOM_PRT8                              ((HSIOM_PRT_Type*) &HSIOM->PRT[8])                                /* 0x68400080 */
#define HSIOM_PRT9                              ((HSIOM_PRT_Type*) &HSIOM->PRT[9])                                /* 0x68400090 */
#define HSIOM_SECURE_PRT0                       ((HSIOM_SECURE_PRT_Type*) &HSIOM->SECURE_PRT[0])                  /* 0x68401000 */
#define HSIOM_SECURE_PRT1                       ((HSIOM_SECURE_PRT_Type*) &HSIOM->SECURE_PRT[1])                  /* 0x68401010 */
#define HSIOM_SECURE_PRT2                       ((HSIOM_SECURE_PRT_Type*) &HSIOM->SECURE_PRT[2])                  /* 0x68401020 */
#define HSIOM_SECURE_PRT3                       ((HSIOM_SECURE_PRT_Type*) &HSIOM->SECURE_PRT[3])                  /* 0x68401030 */
#define HSIOM_SECURE_PRT4                       ((HSIOM_SECURE_PRT_Type*) &HSIOM->SECURE_PRT[4])                  /* 0x68401040 */
#define HSIOM_SECURE_PRT5                       ((HSIOM_SECURE_PRT_Type*) &HSIOM->SECURE_PRT[5])                  /* 0x68401050 */
#define HSIOM_SECURE_PRT6                       ((HSIOM_SECURE_PRT_Type*) &HSIOM->SECURE_PRT[6])                  /* 0x68401060 */
#define HSIOM_SECURE_PRT7                       ((HSIOM_SECURE_PRT_Type*) &HSIOM->SECURE_PRT[7])                  /* 0x68401070 */
#define HSIOM_SECURE_PRT8                       ((HSIOM_SECURE_PRT_Type*) &HSIOM->SECURE_PRT[8])                  /* 0x68401080 */
#define HSIOM_SECURE_PRT9                       ((HSIOM_SECURE_PRT_Type*) &HSIOM->SECURE_PRT[9])                  /* 0x68401090 */

/*******************************************************************************
*                                     GPIO
*******************************************************************************/

#define GPIO_BASE                               0x68410000UL
#define GPIO                                    ((GPIO_Type*) GPIO_BASE)                                          /* 0x68410000 */
#define GPIO_PRT0                               ((GPIO_PRT_Type*) &GPIO->PRT[0])                                  /* 0x68410000 */
#define GPIO_PRT1                               ((GPIO_PRT_Type*) &GPIO->PRT[1])                                  /* 0x68410080 */
#define GPIO_PRT2                               ((GPIO_PRT_Type*) &GPIO->PRT[2])                                  /* 0x68410100 */
#define GPIO_PRT3                               ((GPIO_PRT_Type*) &GPIO->PRT[3])                                  /* 0x68410180 */
#define GPIO_PRT4                               ((GPIO_PRT_Type*) &GPIO->PRT[4])                                  /* 0x68410200 */
#define GPIO_PRT5                               ((GPIO_PRT_Type*) &GPIO->PRT[5])                                  /* 0x68410280 */
#define GPIO_PRT6                               ((GPIO_PRT_Type*) &GPIO->PRT[6])                                  /* 0x68410300 */
#define GPIO_PRT7                               ((GPIO_PRT_Type*) &GPIO->PRT[7])                                  /* 0x68410380 */
#define GPIO_PRT8                               ((GPIO_PRT_Type*) &GPIO->PRT[8])                                  /* 0x68410400 */
#define GPIO_PRT9                               ((GPIO_PRT_Type*) &GPIO->PRT[9])                                  /* 0x68410480 */

/*******************************************************************************
*                                    LPCOMP
*******************************************************************************/

#define LPCOMP_BASE                             0x68430000UL
#define LPCOMP                                  ((LPCOMP_Type*) LPCOMP_BASE)                                      /* 0x68430000 */

/*******************************************************************************
*                                    TCPWM
*******************************************************************************/

#define TCPWM0_BASE                             0x68500000UL
#define TCPWM0                                  ((TCPWM_Type*) TCPWM0_BASE)                                       /* 0x68500000 */
#define TCPWM0_GRP0                             ((TCPWM_GRP_Type*) &TCPWM0->GRP[0])                               /* 0x68500000 */
#define TCPWM0_GRP1                             ((TCPWM_GRP_Type*) &TCPWM0->GRP[1])                               /* 0x68510000 */
#define TCPWM0_GRP0_CNT0                        ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[0].CNT[0])                    /* 0x68500000 */
#define TCPWM0_GRP0_CNT1                        ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[0].CNT[1])                    /* 0x68500100 */
#define TCPWM0_GRP1_CNT0                        ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[1].CNT[0])                    /* 0x68510000 */
#define TCPWM0_GRP1_CNT1                        ((TCPWM_GRP_CNT_Type*) &TCPWM0->GRP[1].CNT[1])                    /* 0x68510100 */
#define TCPWM0_TR_ALL_GF                        ((TCPWM_TR_ALL_GF_Type*) &TCPWM0->TR_ALL_GF)                      /* 0x68580000 */
#define TCPWM0_TR_ALL_SYNC_BYPASS               ((TCPWM_TR_ALL_SYNC_BYPASS_Type*) &TCPWM0->TR_ALL_SYNC_BYPASS)    /* 0x68590000 */
#define TCPWM0_MOTIF_GRP0                       ((TCPWM_MOTIF_GRP_Type*) &TCPWM0->MOTIF_GRP[0])                   /* 0x685A0000 */
#define TCPWM0_MOTIF_GRP1                       ((TCPWM_MOTIF_GRP_Type*) &TCPWM0->MOTIF_GRP[1])                   /* 0x685A4000 */

/*******************************************************************************
*                                    EFUSE
*******************************************************************************/

#define EFUSE_BASE                              0x68610000UL
#define EFUSE                                   ((EFUSE_Type*) EFUSE_BASE)                                        /* 0x68610000 */

/*******************************************************************************
*                                    CANFD
*******************************************************************************/

#define CANFD0_BASE                             0x68800000UL
#define CANFD0                                  ((CANFD_Type*) CANFD0_BASE)                                       /* 0x68800000 */
#define CANFD0_CH0                              ((CANFD_CH_Type*) &CANFD0->CH[0])                                 /* 0x68800000 */
#define CANFD0_CH1                              ((CANFD_CH_Type*) &CANFD0->CH[1])                                 /* 0x68800200 */
#define CANFD0_CH0_M_TTCAN                      ((CANFD_CH_M_TTCAN_Type*) &CANFD0->CH[0].M_TTCAN)                 /* 0x68800000 */
#define CANFD0_CH1_M_TTCAN                      ((CANFD_CH_M_TTCAN_Type*) &CANFD0->CH[1].M_TTCAN)                 /* 0x68800200 */

/*******************************************************************************
*                                     SCB
*******************************************************************************/

#define SCB0_BASE                               0x68820000UL
#define SCB1_BASE                               0x68840000UL
#define SCB2_BASE                               0x68850000UL
#define SCB3_BASE                               0x68860000UL
#define SCB4_BASE                               0x68870000UL
#define SCB5_BASE                               0x69800000UL
#define SCB6_BASE                               0x69810000UL
#define SCB0                                    ((CySCB_Type*) SCB0_BASE)                                         /* 0x68820000 */
#define SCB1                                    ((CySCB_Type*) SCB1_BASE)                                         /* 0x68840000 */
#define SCB2                                    ((CySCB_Type*) SCB2_BASE)                                         /* 0x68850000 */
#define SCB3                                    ((CySCB_Type*) SCB3_BASE)                                         /* 0x68860000 */
#define SCB4                                    ((CySCB_Type*) SCB4_BASE)                                         /* 0x68870000 */
#define SCB5                                    ((CySCB_Type*) SCB5_BASE)                                         /* 0x69800000 */
#define SCB6                                    ((CySCB_Type*) SCB6_BASE)                                         /* 0x69810000 */

/*******************************************************************************
*                                     PPCA
*******************************************************************************/

#define PPCA_BASE                               0x43000000UL
#define PPCA                                    ((PPCA_Type*) PPCA_BASE)                                          /* 0x43000000 */
#define PPCA_CNFG                               ((PPCA_CNFG_Type*) &PPCA->CNFG)                                   /* 0x43000000 */
#define PPCA_CNFG_CNFG                          ((PPCA_CNFG_CNFG_Type*) &PPCA->CNFG.CNFG)                         /* 0x43000100 */
#define PPCA_CNFG_S2IRQ0                        ((PPCA_CNFG_S2IRQ_Type*) &PPCA->CNFG.S2IRQ[0])                    /* 0x43000300 */
#define PPCA_CNFG_S2IRQ1                        ((PPCA_CNFG_S2IRQ_Type*) &PPCA->CNFG.S2IRQ[1])                    /* 0x43000310 */
#define PPCA_CNFG_S2IRQ2                        ((PPCA_CNFG_S2IRQ_Type*) &PPCA->CNFG.S2IRQ[2])                    /* 0x43000320 */
#define PPCA_CNFG_S2IRQ3                        ((PPCA_CNFG_S2IRQ_Type*) &PPCA->CNFG.S2IRQ[3])                    /* 0x43000330 */
#define PPCA_CNFG_S2IRQ4                        ((PPCA_CNFG_S2IRQ_Type*) &PPCA->CNFG.S2IRQ[4])                    /* 0x43000340 */
#define PPCA_CNFG_S2IRQ5                        ((PPCA_CNFG_S2IRQ_Type*) &PPCA->CNFG.S2IRQ[5])                    /* 0x43000350 */
#define PPCA_CNFG_S2IRQ6                        ((PPCA_CNFG_S2IRQ_Type*) &PPCA->CNFG.S2IRQ[6])                    /* 0x43000360 */
#define PPCA_CNFG_ADCM                          ((PPCA_CNFG_ADCM_Type*) &PPCA->CNFG.ADCM)                         /* 0x43000400 */
#define PPCA_CNFG_DISPERI                       ((PPCA_CNFG_DISPERI_Type*) &PPCA->CNFG.DISPERI)                   /* 0x43000800 */
#define PPCA_EPU                                ((PPCA_EPU_Type*) &PPCA->EPU)                                     /* 0x43004000 */
#define PPCA_EPU_EPU_IRQ0                       ((PPCA_EPU_EPU_IRQ_Type*) &PPCA->EPU.EPU_IRQ[0])                  /* 0x43004100 */
#define PPCA_EPU_EPU_IRQ1                       ((PPCA_EPU_EPU_IRQ_Type*) &PPCA->EPU.EPU_IRQ[1])                  /* 0x43004120 */
#define PPCA_EPU_EPU_IRQ2                       ((PPCA_EPU_EPU_IRQ_Type*) &PPCA->EPU.EPU_IRQ[2])                  /* 0x43004140 */
#define PPCA_EPU_EPU_IRQ3                       ((PPCA_EPU_EPU_IRQ_Type*) &PPCA->EPU.EPU_IRQ[3])                  /* 0x43004160 */
#define PPCA_EPU_EPU_IRQ4                       ((PPCA_EPU_EPU_IRQ_Type*) &PPCA->EPU.EPU_IRQ[4])                  /* 0x43004180 */
#define PPCA_EPU_EPU_IRQ5                       ((PPCA_EPU_EPU_IRQ_Type*) &PPCA->EPU.EPU_IRQ[5])                  /* 0x430041A0 */
#define PPCA_EPU_EPU_IRQ6                       ((PPCA_EPU_EPU_IRQ_Type*) &PPCA->EPU.EPU_IRQ[6])                  /* 0x430041C0 */
#define PPCA_EPU_EPU_IRQ7                       ((PPCA_EPU_EPU_IRQ_Type*) &PPCA->EPU.EPU_IRQ[7])                  /* 0x430041E0 */
#define PPCA_EPU_EPU                            ((PPCA_EPU_EPU_Type*) &PPCA->EPU.EPU)                             /* 0x43004400 */
#define PPCA_IPC0                               ((IPC_Type*) &PPCA->PPCA_IPC)                                     /* 0x43060000 */
#define PPCA_IPC_STRUCT0                        ((IPC_STRUCT_Type*) &PPCA->PPCA_IPC.STRUCT[0])                    /* 0x43060000 */
#define PPCA_IPC_STRUCT1                        ((IPC_STRUCT_Type*) &PPCA->PPCA_IPC.STRUCT[1])                    /* 0x43060020 */
#define PPCA_IPC_STRUCT2                        ((IPC_STRUCT_Type*) &PPCA->PPCA_IPC.STRUCT[2])                    /* 0x43060040 */
#define PPCA_IPC_STRUCT3                        ((IPC_STRUCT_Type*) &PPCA->PPCA_IPC.STRUCT[3])                    /* 0x43060060 */
#define PPCA_IPC_INTR_STRUCT0                   ((IPC_INTR_STRUCT_Type*) &PPCA->PPCA_IPC.INTR_STRUCT[0])          /* 0x43061000 */
#define PPCA_IPC_INTR_STRUCT1                   ((IPC_INTR_STRUCT_Type*) &PPCA->PPCA_IPC.INTR_STRUCT[1])          /* 0x43061020 */
#define PPCA_IPC_INTR_STRUCT2                   ((IPC_INTR_STRUCT_Type*) &PPCA->PPCA_IPC.INTR_STRUCT[2])          /* 0x43061040 */
#define PPCA_IPC_INTR_STRUCT3                   ((IPC_INTR_STRUCT_Type*) &PPCA->PPCA_IPC.INTR_STRUCT[3])          /* 0x43061060 */
#define PPCA_CPUSS_CNFG                         ((PPCA_CPUSS_CNFG_Type*) &PPCA->CPUSS_CNFG)                       /* 0x43080000 */
#define PPCA_CPUSS_CNFG_MXCM330                 ((PPCA_CPUSS_CNFG_MXCM33_Type*) &PPCA->CPUSS_CNFG.PPCA_MXCM33[0]) /* 0x43080000 */
#define PPCA_CPUSS_CNFG_MXCM331                 ((PPCA_CPUSS_CNFG_MXCM33_Type*) &PPCA->CPUSS_CNFG.PPCA_MXCM33[1]) /* 0x43090000 */
#define PPCA_CPUSS_CNFG_RAMC0                   ((PPCA_CPUSS_CNFG_RAMC_Type*) &PPCA->CPUSS_CNFG.RAMC[0])          /* 0x430A0000 */
#define PPCA_CPUSS_CNFG_RAMC1                   ((PPCA_CPUSS_CNFG_RAMC_Type*) &PPCA->CPUSS_CNFG.RAMC[1])          /* 0x430B0000 */
#define PPCA_CPUSS_CNFG_RAMC2                   ((PPCA_CPUSS_CNFG_RAMC_Type*) &PPCA->CPUSS_CNFG.RAMC[2])          /* 0x430C0000 */
#define PPCA_CPUSS_CNFG_RAMC3                   ((PPCA_CPUSS_CNFG_RAMC_Type*) &PPCA->CPUSS_CNFG.RAMC[3])          /* 0x430D0000 */
#define PPCA_CPUSS_CNFG_RAMC4                   ((PPCA_CPUSS_CNFG_RAMC_Type*) &PPCA->CPUSS_CNFG.RAMC[4])          /* 0x430E0000 */
#define PPCA_CPUSS_CNFG_RAMC0_MPC0              ((PPCA_CPUSS_CNFG_RAMC_MPC_Type*) &PPCA->CPUSS_CNFG.RAMC[0].MPC[0]) /* 0x430A4000 */
#define PPCA_CPUSS_CNFG_RAMC1_MPC0              ((PPCA_CPUSS_CNFG_RAMC_MPC_Type*) &PPCA->CPUSS_CNFG.RAMC[1].MPC[0]) /* 0x430B4000 */
#define PPCA_CPUSS_CNFG_RAMC2_MPC0              ((PPCA_CPUSS_CNFG_RAMC_MPC_Type*) &PPCA->CPUSS_CNFG.RAMC[2].MPC[0]) /* 0x430C4000 */
#define PPCA_CPUSS_CNFG_RAMC3_MPC0              ((PPCA_CPUSS_CNFG_RAMC_MPC_Type*) &PPCA->CPUSS_CNFG.RAMC[3].MPC[0]) /* 0x430D4000 */
#define PPCA_CPUSS_CNFG_RAMC4_MPC0              ((PPCA_CPUSS_CNFG_RAMC_MPC_Type*) &PPCA->CPUSS_CNFG.RAMC[4].MPC[0]) /* 0x430E4000 */
#define PPCA_CPUSS_CNFG_RAMC_PPU0               ((PPCA_CPUSS_CNFG_RAMC_PPU_Type*) &PPCA->CPUSS_CNFG.RAMC_PPU[0])  /* 0x430F8000 */
#define PPCA_CPUSS_CNFG_RAMC_PPU1               ((PPCA_CPUSS_CNFG_RAMC_PPU_Type*) &PPCA->CPUSS_CNFG.RAMC_PPU[1])  /* 0x430F9000 */
#define PPCA_CPUSS_CNFG_RAMC_PPU2               ((PPCA_CPUSS_CNFG_RAMC_PPU_Type*) &PPCA->CPUSS_CNFG.RAMC_PPU[2])  /* 0x430FA000 */
#define PPCA_CPUSS_CNFG_RAMC_PPU3               ((PPCA_CPUSS_CNFG_RAMC_PPU_Type*) &PPCA->CPUSS_CNFG.RAMC_PPU[3])  /* 0x430FB000 */
#define PPCA_CPUSS_CNFG_RAMC_PPU4               ((PPCA_CPUSS_CNFG_RAMC_PPU_Type*) &PPCA->CPUSS_CNFG.RAMC_PPU[4])  /* 0x430FC000 */
#define PPCA_TCPWM0                             ((TCPWM_Type*) &PPCA->TCPWM[0])                                   /* 0x43100000 */
#define PPCA_TCPWM1                             ((TCPWM_Type*) &PPCA->TCPWM[1])                                   /* 0x43200000 */
#define PPCA_TCPWM2                             ((TCPWM_Type*) &PPCA->TCPWM[2])                                   /* 0x43300000 */
#define PPCA_TCPWM3                             ((TCPWM_Type*) &PPCA->TCPWM[3])                                   /* 0x43400000 */
#define PPCA_TCPWM0_GRP0                        ((TCPWM_GRP_Type*) &PPCA->TCPWM[0].GRP[0])                        /* 0x43100000 */
#define PPCA_TCPWM0_GRP1                        ((TCPWM_GRP_Type*) &PPCA->TCPWM[0].GRP[1])                        /* 0x43110000 */
#define PPCA_TCPWM0_GRP2                        ((TCPWM_GRP_Type*) &PPCA->TCPWM[0].GRP[2])                        /* 0x43120000 */
#define PPCA_TCPWM1_GRP0                        ((TCPWM_GRP_Type*) &PPCA->TCPWM[1].GRP[0])                        /* 0x43200000 */
#define PPCA_TCPWM1_GRP1                        ((TCPWM_GRP_Type*) &PPCA->TCPWM[1].GRP[1])                        /* 0x43210000 */
#define PPCA_TCPWM1_GRP2                        ((TCPWM_GRP_Type*) &PPCA->TCPWM[1].GRP[2])                        /* 0x43220000 */
#define PPCA_TCPWM2_GRP0                        ((TCPWM_GRP_Type*) &PPCA->TCPWM[2].GRP[0])                        /* 0x43300000 */
#define PPCA_TCPWM3_GRP0                        ((TCPWM_GRP_Type*) &PPCA->TCPWM[3].GRP[0])                        /* 0x43400000 */
#define PPCA_TCPWM0_GRP0_CNT0                   ((TCPWM_GRP_CNT_Type*) &PPCA->TCPWM[0].GRP[0].CNT[0])             /* 0x43100000 */
#define PPCA_TCPWM0_GRP0_CNT1                   ((TCPWM_GRP_CNT_Type*) &PPCA->TCPWM[0].GRP[0].CNT[1])             /* 0x43100100 */
#define PPCA_TCPWM0_GRP0_CNT2                   ((TCPWM_GRP_CNT_Type*) &PPCA->TCPWM[0].GRP[0].CNT[2])             /* 0x43100200 */
#define PPCA_TCPWM0_GRP0_CNT3                   ((TCPWM_GRP_CNT_Type*) &PPCA->TCPWM[0].GRP[0].CNT[3])             /* 0x43100300 */
#define PPCA_TCPWM0_GRP1_CNT0                   ((TCPWM_GRP_CNT_Type*) &PPCA->TCPWM[0].GRP[1].CNT[0])             /* 0x43110000 */
#define PPCA_TCPWM0_GRP1_CNT1                   ((TCPWM_GRP_CNT_Type*) &PPCA->TCPWM[0].GRP[1].CNT[1])             /* 0x43110100 */
#define PPCA_TCPWM0_GRP1_CNT2                   ((TCPWM_GRP_CNT_Type*) &PPCA->TCPWM[0].GRP[1].CNT[2])             /* 0x43110200 */
#define PPCA_TCPWM0_GRP1_CNT3                   ((TCPWM_GRP_CNT_Type*) &PPCA->TCPWM[0].GRP[1].CNT[3])             /* 0x43110300 */
#define PPCA_TCPWM0_GRP2_CNT0                   ((TCPWM_GRP_CNT_Type*) &PPCA->TCPWM[0].GRP[2].CNT[0])             /* 0x43120000 */
#define PPCA_TCPWM0_GRP2_CNT1                   ((TCPWM_GRP_CNT_Type*) &PPCA->TCPWM[0].GRP[2].CNT[1])             /* 0x43120100 */
#define PPCA_TCPWM0_GRP2_CNT2                   ((TCPWM_GRP_CNT_Type*) &PPCA->TCPWM[0].GRP[2].CNT[2])             /* 0x43120200 */
#define PPCA_TCPWM0_GRP2_CNT3                   ((TCPWM_GRP_CNT_Type*) &PPCA->TCPWM[0].GRP[2].CNT[3])             /* 0x43120300 */
#define PPCA_TCPWM1_GRP0_CNT0                   ((TCPWM_GRP_CNT_Type*) &PPCA->TCPWM[1].GRP[0].CNT[0])             /* 0x43200000 */
#define PPCA_TCPWM1_GRP0_CNT1                   ((TCPWM_GRP_CNT_Type*) &PPCA->TCPWM[1].GRP[0].CNT[1])             /* 0x43200100 */
#define PPCA_TCPWM1_GRP1_CNT0                   ((TCPWM_GRP_CNT_Type*) &PPCA->TCPWM[1].GRP[1].CNT[0])             /* 0x43210000 */
#define PPCA_TCPWM1_GRP1_CNT1                   ((TCPWM_GRP_CNT_Type*) &PPCA->TCPWM[1].GRP[1].CNT[1])             /* 0x43210100 */
#define PPCA_TCPWM1_GRP2_CNT0                   ((TCPWM_GRP_CNT_Type*) &PPCA->TCPWM[1].GRP[2].CNT[0])             /* 0x43220000 */
#define PPCA_TCPWM1_GRP2_CNT1                   ((TCPWM_GRP_CNT_Type*) &PPCA->TCPWM[1].GRP[2].CNT[1])             /* 0x43220100 */
#define PPCA_TCPWM1_GRP2_CNT2                   ((TCPWM_GRP_CNT_Type*) &PPCA->TCPWM[1].GRP[2].CNT[2])             /* 0x43220200 */
#define PPCA_TCPWM1_GRP2_CNT3                   ((TCPWM_GRP_CNT_Type*) &PPCA->TCPWM[1].GRP[2].CNT[3])             /* 0x43220300 */
#define PPCA_TCPWM2_GRP0_CNT0                   ((TCPWM_GRP_CNT_Type*) &PPCA->TCPWM[2].GRP[0].CNT[0])             /* 0x43300000 */
#define PPCA_TCPWM2_GRP0_CNT1                   ((TCPWM_GRP_CNT_Type*) &PPCA->TCPWM[2].GRP[0].CNT[1])             /* 0x43300100 */
#define PPCA_TCPWM2_GRP0_CNT2                   ((TCPWM_GRP_CNT_Type*) &PPCA->TCPWM[2].GRP[0].CNT[2])             /* 0x43300200 */
#define PPCA_TCPWM2_GRP0_CNT3                   ((TCPWM_GRP_CNT_Type*) &PPCA->TCPWM[2].GRP[0].CNT[3])             /* 0x43300300 */
#define PPCA_TCPWM3_GRP0_CNT0                   ((TCPWM_GRP_CNT_Type*) &PPCA->TCPWM[3].GRP[0].CNT[0])             /* 0x43400000 */
#define PPCA_TCPWM3_GRP0_CNT1                   ((TCPWM_GRP_CNT_Type*) &PPCA->TCPWM[3].GRP[0].CNT[1])             /* 0x43400100 */
#define PPCA_TCPWM0_TR_ALL_GF                   ((TCPWM_TR_ALL_GF_Type*) &PPCA->TCPWM[0].TR_ALL_GF)               /* 0x43180000 */
#define PPCA_TCPWM1_TR_ALL_GF                   ((TCPWM_TR_ALL_GF_Type*) &PPCA->TCPWM[1].TR_ALL_GF)               /* 0x43280000 */
#define PPCA_TCPWM2_TR_ALL_GF                   ((TCPWM_TR_ALL_GF_Type*) &PPCA->TCPWM[2].TR_ALL_GF)               /* 0x43380000 */
#define PPCA_TCPWM3_TR_ALL_GF                   ((TCPWM_TR_ALL_GF_Type*) &PPCA->TCPWM[3].TR_ALL_GF)               /* 0x43480000 */
#define PPCA_TCPWM0_TR_ALL_SYNC_BYPASS          ((TCPWM_TR_ALL_SYNC_BYPASS_Type*) &PPCA->TCPWM[0].TR_ALL_SYNC_BYPASS) /* 0x43190000 */
#define PPCA_TCPWM1_TR_ALL_SYNC_BYPASS          ((TCPWM_TR_ALL_SYNC_BYPASS_Type*) &PPCA->TCPWM[1].TR_ALL_SYNC_BYPASS) /* 0x43290000 */
#define PPCA_TCPWM2_TR_ALL_SYNC_BYPASS          ((TCPWM_TR_ALL_SYNC_BYPASS_Type*) &PPCA->TCPWM[2].TR_ALL_SYNC_BYPASS) /* 0x43390000 */
#define PPCA_TCPWM3_TR_ALL_SYNC_BYPASS          ((TCPWM_TR_ALL_SYNC_BYPASS_Type*) &PPCA->TCPWM[3].TR_ALL_SYNC_BYPASS) /* 0x43490000 */
#define PPCA_TCPWM0_MOTIF_GRP0                  ((TCPWM_MOTIF_GRP_Type*) &PPCA->TCPWM[0].MOTIF_GRP[0])            /* 0x431A0000 */
#define PPCA_TCPWM0_MOTIF_GRP1                  ((TCPWM_MOTIF_GRP_Type*) &PPCA->TCPWM[0].MOTIF_GRP[1])            /* 0x431A4000 */
#define PPCA_TCPWM0_MOTIF_GRP2                  ((TCPWM_MOTIF_GRP_Type*) &PPCA->TCPWM[0].MOTIF_GRP[2])            /* 0x431A8000 */
#define PPCA_TCPWM1_MOTIF_GRP0                  ((TCPWM_MOTIF_GRP_Type*) &PPCA->TCPWM[1].MOTIF_GRP[0])            /* 0x432A0000 */
#define PPCA_TCPWM1_MOTIF_GRP1                  ((TCPWM_MOTIF_GRP_Type*) &PPCA->TCPWM[1].MOTIF_GRP[1])            /* 0x432A4000 */
#define PPCA_TCPWM1_MOTIF_GRP2                  ((TCPWM_MOTIF_GRP_Type*) &PPCA->TCPWM[1].MOTIF_GRP[2])            /* 0x432A8000 */
#define PPCA_TCPWM2_MOTIF_GRP0                  ((TCPWM_MOTIF_GRP_Type*) &PPCA->TCPWM[2].MOTIF_GRP[0])            /* 0x433A0000 */
#define PPCA_TCPWM3_MOTIF_GRP0                  ((TCPWM_MOTIF_GRP_Type*) &PPCA->TCPWM[3].MOTIF_GRP[0])            /* 0x434A0000 */
#define PPCA_TCPWM0_MOTIF_GRP2_MOTIF0           ((TCPWM_MOTIF_GRP_MOTIF_Type*) &PPCA->TCPWM[0].MOTIF_GRP[2].MOTIF[0]) /* 0x431A8000 */
#define PPCA_TCPWM1_MOTIF_GRP2_MOTIF0           ((TCPWM_MOTIF_GRP_MOTIF_Type*) &PPCA->TCPWM[1].MOTIF_GRP[2].MOTIF[0]) /* 0x432A8000 */
#define PPCA_HWFILT3P3Z_SS_0                    ((PPCA_HWFILT3P3Z_SS_0_Type*) &PPCA->HWFILT3P3Z_SS_0)             /* 0x43500000 */
#define PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z0        ((PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z_Type*) &PPCA->HWFILT3P3Z_SS_0.HWFILT3P3Z[0]) /* 0x43500100 */
#define PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z1        ((PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z_Type*) &PPCA->HWFILT3P3Z_SS_0.HWFILT3P3Z[1]) /* 0x43500200 */
#define PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z2        ((PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z_Type*) &PPCA->HWFILT3P3Z_SS_0.HWFILT3P3Z[2]) /* 0x43500300 */
#define PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z3        ((PPCA_HWFILT3P3Z_SS_0_HWFILT3P3Z_Type*) &PPCA->HWFILT3P3Z_SS_0.HWFILT3P3Z[3]) /* 0x43500400 */
#define PPCA_HWFILT3P3Z_SS_1                    ((PPCA_HWFILT3P3Z_SS_1_Type*) &PPCA->HWFILT3P3Z_SS_1)             /* 0x43510000 */
#define PPCA_HWFILT3P3Z_SS_1_HWFILT3P3Z0        ((PPCA_HWFILT3P3Z_SS_1_HWFILT3P3Z_Type*) &PPCA->HWFILT3P3Z_SS_1.HWFILT3P3Z[0]) /* 0x43510100 */
#define PPCA_HWFILT3P3Z_SS_1_HWFILT3P3Z1        ((PPCA_HWFILT3P3Z_SS_1_HWFILT3P3Z_Type*) &PPCA->HWFILT3P3Z_SS_1.HWFILT3P3Z[1]) /* 0x43510200 */
#define PPCA_ADCM                               ((PPCA_ADCM_Type*) &PPCA->ADCM)                                   /* 0x43520000 */
#define PPCA_ADCM_ADCM                          ((PPCA_ADCM_ADCM_Type*) &PPCA->ADCM.ADCM)                         /* 0x43520000 */
#define PPCA_CLB                                ((PPCA_CLB_Type*) &PPCA->CLB)                                     /* 0x43530000 */
#define PPCA_CLB_DICO                           ((PPCA_CLB_DICO_Type*) &PPCA->CLB.DICO)                           /* 0x43532000 */
#define PPCA_CLB_MACO                           ((PPCA_CLB_MACO_Type*) &PPCA->CLB.MACO)                           /* 0x43534000 */
#define PPCA_MXCORDIC0                          ((MXCORDIC_Type*) &PPCA->MXCORDIC[0])                             /* 0x43540000 */
#define PPCA_MXCORDIC1                          ((MXCORDIC_Type*) &PPCA->MXCORDIC[1])                             /* 0x43550000 */
#define PPCA_ATOPSS                             ((PPCA_ATOPSS_Type*) &PPCA->ATOPSS)                               /* 0x43580000 */
#define PPCA_ATOPSS_ADC_GRP0                    ((PPCA_ATOPSS_ADC_GRP_Type*) &PPCA->ATOPSS.ADC_GRP[0])            /* 0x43580000 */
#define PPCA_ATOPSS_ADC_GRP1                    ((PPCA_ATOPSS_ADC_GRP_Type*) &PPCA->ATOPSS.ADC_GRP[1])            /* 0x43582000 */
#define PPCA_ATOPSS_ADC_GRP2                    ((PPCA_ATOPSS_ADC_GRP_Type*) &PPCA->ATOPSS.ADC_GRP[2])            /* 0x43584000 */
#define PPCA_ATOPSS_ADC_GRP3                    ((PPCA_ATOPSS_ADC_GRP_Type*) &PPCA->ATOPSS.ADC_GRP[3])            /* 0x43586000 */
#define PPCA_ATOPSS_ADC_GRP0_SLICE0             ((PPCA_ATOPSS_ADC_GRP_SLICE_Type*) &PPCA->ATOPSS.ADC_GRP[0].SLICE[0]) /* 0x43580000 */
#define PPCA_ATOPSS_ADC_GRP1_SLICE0             ((PPCA_ATOPSS_ADC_GRP_SLICE_Type*) &PPCA->ATOPSS.ADC_GRP[1].SLICE[0]) /* 0x43582000 */
#define PPCA_ATOPSS_ADC_GRP2_SLICE0             ((PPCA_ATOPSS_ADC_GRP_SLICE_Type*) &PPCA->ATOPSS.ADC_GRP[2].SLICE[0]) /* 0x43584000 */
#define PPCA_ATOPSS_ADC_GRP3_SLICE0             ((PPCA_ATOPSS_ADC_GRP_SLICE_Type*) &PPCA->ATOPSS.ADC_GRP[3].SLICE[0]) /* 0x43586000 */
#define PPCA_ATOPSS_ADC_GRP0_SLICE0_ADC         ((PPCA_ATOPSS_ADC_GRP_SLICE_ADC_Type*) &PPCA->ATOPSS.ADC_GRP[0].SLICE[0].ADC) /* 0x43580000 */
#define PPCA_ATOPSS_ADC_GRP1_SLICE0_ADC         ((PPCA_ATOPSS_ADC_GRP_SLICE_ADC_Type*) &PPCA->ATOPSS.ADC_GRP[1].SLICE[0].ADC) /* 0x43582000 */
#define PPCA_ATOPSS_ADC_GRP2_SLICE0_ADC         ((PPCA_ATOPSS_ADC_GRP_SLICE_ADC_Type*) &PPCA->ATOPSS.ADC_GRP[2].SLICE[0].ADC) /* 0x43584000 */
#define PPCA_ATOPSS_ADC_GRP3_SLICE0_ADC         ((PPCA_ATOPSS_ADC_GRP_SLICE_ADC_Type*) &PPCA->ATOPSS.ADC_GRP[3].SLICE[0].ADC) /* 0x43586000 */
#define PPCA_ATOPSS_ADC_GRP0_SLICE0_AFE         ((PPCA_ATOPSS_ADC_GRP_SLICE_AFE_Type*) &PPCA->ATOPSS.ADC_GRP[0].SLICE[0].AFE) /* 0x43580200 */
#define PPCA_ATOPSS_ADC_GRP1_SLICE0_AFE         ((PPCA_ATOPSS_ADC_GRP_SLICE_AFE_Type*) &PPCA->ATOPSS.ADC_GRP[1].SLICE[0].AFE) /* 0x43582200 */
#define PPCA_ATOPSS_ADC_GRP2_SLICE0_AFE         ((PPCA_ATOPSS_ADC_GRP_SLICE_AFE_Type*) &PPCA->ATOPSS.ADC_GRP[2].SLICE[0].AFE) /* 0x43584200 */
#define PPCA_ATOPSS_ADC_GRP3_SLICE0_AFE         ((PPCA_ATOPSS_ADC_GRP_SLICE_AFE_Type*) &PPCA->ATOPSS.ADC_GRP[3].SLICE[0].AFE) /* 0x43586200 */
#define PPCA_ATOPSS_ADC_GRP0_AFLT0              ((PPCA_ATOPSS_ADC_GRP_AFLT_Type*) &PPCA->ATOPSS.ADC_GRP[0].AFLT[0]) /* 0x43581000 */
#define PPCA_ATOPSS_ADC_GRP0_AFLT1              ((PPCA_ATOPSS_ADC_GRP_AFLT_Type*) &PPCA->ATOPSS.ADC_GRP[0].AFLT[1]) /* 0x43581100 */
#define PPCA_ATOPSS_ADC_GRP1_AFLT0              ((PPCA_ATOPSS_ADC_GRP_AFLT_Type*) &PPCA->ATOPSS.ADC_GRP[1].AFLT[0]) /* 0x43583000 */
#define PPCA_ATOPSS_ADC_GRP2_AFLT0              ((PPCA_ATOPSS_ADC_GRP_AFLT_Type*) &PPCA->ATOPSS.ADC_GRP[2].AFLT[0]) /* 0x43585000 */
#define PPCA_ATOPSS_ADC_GRP3_AFLT0              ((PPCA_ATOPSS_ADC_GRP_AFLT_Type*) &PPCA->ATOPSS.ADC_GRP[3].AFLT[0]) /* 0x43587000 */
#define PPCA_ATOPSS_ADC_GRP3_AFLT1              ((PPCA_ATOPSS_ADC_GRP_AFLT_Type*) &PPCA->ATOPSS.ADC_GRP[3].AFLT[1]) /* 0x43587100 */
#define PPCA_ATOPSS_ADC_GRP0_DCMP0              ((PPCA_ATOPSS_ADC_GRP_DCMP_Type*) &PPCA->ATOPSS.ADC_GRP[0].DCMP[0]) /* 0x43581400 */
#define PPCA_ATOPSS_ADC_GRP0_DCMP1              ((PPCA_ATOPSS_ADC_GRP_DCMP_Type*) &PPCA->ATOPSS.ADC_GRP[0].DCMP[1]) /* 0x43581500 */
#define PPCA_ATOPSS_ADC_GRP0_DCMP2              ((PPCA_ATOPSS_ADC_GRP_DCMP_Type*) &PPCA->ATOPSS.ADC_GRP[0].DCMP[2]) /* 0x43581600 */
#define PPCA_ATOPSS_ADC_GRP0_DCMP3              ((PPCA_ATOPSS_ADC_GRP_DCMP_Type*) &PPCA->ATOPSS.ADC_GRP[0].DCMP[3]) /* 0x43581700 */
#define PPCA_ATOPSS_ADC_GRP1_DCMP0              ((PPCA_ATOPSS_ADC_GRP_DCMP_Type*) &PPCA->ATOPSS.ADC_GRP[1].DCMP[0]) /* 0x43583400 */
#define PPCA_ATOPSS_ADC_GRP1_DCMP1              ((PPCA_ATOPSS_ADC_GRP_DCMP_Type*) &PPCA->ATOPSS.ADC_GRP[1].DCMP[1]) /* 0x43583500 */
#define PPCA_ATOPSS_ADC_GRP2_DCMP0              ((PPCA_ATOPSS_ADC_GRP_DCMP_Type*) &PPCA->ATOPSS.ADC_GRP[2].DCMP[0]) /* 0x43585400 */
#define PPCA_ATOPSS_ADC_GRP2_DCMP1              ((PPCA_ATOPSS_ADC_GRP_DCMP_Type*) &PPCA->ATOPSS.ADC_GRP[2].DCMP[1]) /* 0x43585500 */
#define PPCA_ATOPSS_ADC_GRP3_DCMP0              ((PPCA_ATOPSS_ADC_GRP_DCMP_Type*) &PPCA->ATOPSS.ADC_GRP[3].DCMP[0]) /* 0x43587400 */
#define PPCA_ATOPSS_ADC_GRP3_DCMP1              ((PPCA_ATOPSS_ADC_GRP_DCMP_Type*) &PPCA->ATOPSS.ADC_GRP[3].DCMP[1]) /* 0x43587500 */
#define PPCA_ATOPSS_ADC_GRP3_DCMP2              ((PPCA_ATOPSS_ADC_GRP_DCMP_Type*) &PPCA->ATOPSS.ADC_GRP[3].DCMP[2]) /* 0x43587600 */
#define PPCA_ATOPSS_ADC_GRP3_DCMP3              ((PPCA_ATOPSS_ADC_GRP_DCMP_Type*) &PPCA->ATOPSS.ADC_GRP[3].DCMP[3]) /* 0x43587700 */
#define PPCA_ATOPSS_ADC_GRP0_IDAC               ((PPCA_ATOPSS_ADC_GRP_IDAC_Type*) &PPCA->ATOPSS.ADC_GRP[0].IDAC)  /* 0x43581800 */
#define PPCA_ATOPSS_ADC_GRP0_AREF               ((PPCA_ATOPSS_ADC_GRP_AREF_Type*) &PPCA->ATOPSS.ADC_GRP[0].AREF)  /* 0x43581900 */
#define PPCA_ATOPSS_ADC_GRP0_GPI                ((PPCA_ATOPSS_ADC_GRP_GPI_Type*) &PPCA->ATOPSS.ADC_GRP[0].GPI)    /* 0x43581A00 */
#define PPCA_ATOPSS_DCSG_GRP0                   ((PPCA_ATOPSS_DCSG_GRP_Type*) &PPCA->ATOPSS.DCSG_GRP[0])          /* 0x43588000 */
#define PPCA_ATOPSS_DCSG_GRP1                   ((PPCA_ATOPSS_DCSG_GRP_Type*) &PPCA->ATOPSS.DCSG_GRP[1])          /* 0x4358A000 */
#define PPCA_ATOPSS_DCSG_GRP0_DCSG              ((PPCA_ATOPSS_DCSG_GRP_DCSG_Type*) &PPCA->ATOPSS.DCSG_GRP[0].DCSG) /* 0x43588000 */
#define PPCA_ATOPSS_DCSG_GRP1_DCSG              ((PPCA_ATOPSS_DCSG_GRP_DCSG_Type*) &PPCA->ATOPSS.DCSG_GRP[1].DCSG) /* 0x4358A000 */
#define PPCA_ATOPSS_DCSG_GRP0_DCSG_SLICE0       ((PPCA_ATOPSS_DCSG_GRP_DCSG_SLICE_Type*) &PPCA->ATOPSS.DCSG_GRP[0].DCSG.SLICE[0]) /* 0x43588000 */
#define PPCA_ATOPSS_DCSG_GRP0_DCSG_SLICE1       ((PPCA_ATOPSS_DCSG_GRP_DCSG_SLICE_Type*) &PPCA->ATOPSS.DCSG_GRP[0].DCSG.SLICE[1]) /* 0x43588100 */
#define PPCA_ATOPSS_DCSG_GRP0_DCSG_SLICE2       ((PPCA_ATOPSS_DCSG_GRP_DCSG_SLICE_Type*) &PPCA->ATOPSS.DCSG_GRP[0].DCSG.SLICE[2]) /* 0x43588200 */
#define PPCA_ATOPSS_DCSG_GRP0_DCSG_SLICE3       ((PPCA_ATOPSS_DCSG_GRP_DCSG_SLICE_Type*) &PPCA->ATOPSS.DCSG_GRP[0].DCSG.SLICE[3]) /* 0x43588300 */
#define PPCA_ATOPSS_DCSG_GRP0_DCSG_SLICE4       ((PPCA_ATOPSS_DCSG_GRP_DCSG_SLICE_Type*) &PPCA->ATOPSS.DCSG_GRP[0].DCSG.SLICE[4]) /* 0x43588400 */
#define PPCA_ATOPSS_DCSG_GRP0_DCSG_SLICE5       ((PPCA_ATOPSS_DCSG_GRP_DCSG_SLICE_Type*) &PPCA->ATOPSS.DCSG_GRP[0].DCSG.SLICE[5]) /* 0x43588500 */
#define PPCA_ATOPSS_DCSG_GRP1_DCSG_SLICE0       ((PPCA_ATOPSS_DCSG_GRP_DCSG_SLICE_Type*) &PPCA->ATOPSS.DCSG_GRP[1].DCSG.SLICE[0]) /* 0x4358A000 */
#define PPCA_ATOPSS_DCSG_GRP1_DCSG_SLICE1       ((PPCA_ATOPSS_DCSG_GRP_DCSG_SLICE_Type*) &PPCA->ATOPSS.DCSG_GRP[1].DCSG.SLICE[1]) /* 0x4358A100 */
#define PPCA_ATOPSS_DCSG_GRP1_DCSG_SLICE2       ((PPCA_ATOPSS_DCSG_GRP_DCSG_SLICE_Type*) &PPCA->ATOPSS.DCSG_GRP[1].DCSG.SLICE[2]) /* 0x4358A200 */
#define PPCA_ATOPSS_DCSG_GRP0_DCSG_SLGEN0       ((PPCA_ATOPSS_DCSG_GRP_DCSG_SLGEN_Type*) &PPCA->ATOPSS.DCSG_GRP[0].DCSG.SLGEN[0]) /* 0x43588600 */
#define PPCA_ATOPSS_DCSG_GRP0_DCSG_SLGEN1       ((PPCA_ATOPSS_DCSG_GRP_DCSG_SLGEN_Type*) &PPCA->ATOPSS.DCSG_GRP[0].DCSG.SLGEN[1]) /* 0x43588700 */
#define PPCA_ATOPSS_DCSG_GRP1_DCSG_SLGEN0       ((PPCA_ATOPSS_DCSG_GRP_DCSG_SLGEN_Type*) &PPCA->ATOPSS.DCSG_GRP[1].DCSG.SLGEN[0]) /* 0x4358A600 */
#define PPCA_ATOPSS_DCSG_GRP0_DCSG_BLANK        ((PPCA_ATOPSS_DCSG_GRP_DCSG_BLANK_Type*) &PPCA->ATOPSS.DCSG_GRP[0].DCSG.BLANK) /* 0x43588C00 */
#define PPCA_ATOPSS_DCSG_GRP1_DCSG_BLANK        ((PPCA_ATOPSS_DCSG_GRP_DCSG_BLANK_Type*) &PPCA->ATOPSS.DCSG_GRP[1].DCSG.BLANK) /* 0x4358AC00 */
#define PPCA_ATOPSS_DCSG_GRP0_DAC_R2R           ((PPCA_ATOPSS_DCSG_GRP_DAC_R2R_Type*) &PPCA->ATOPSS.DCSG_GRP[0].DAC_R2R) /* 0x43589000 */
#define PPCA_ATOPSS_DCSG_GRP1_DAC_R2R           ((PPCA_ATOPSS_DCSG_GRP_DAC_R2R_Type*) &PPCA->ATOPSS.DCSG_GRP[1].DAC_R2R) /* 0x4358B000 */

/*******************************************************************************
*                                     CM33
*******************************************************************************/

#define CM33_BASE                               0xE0000000UL
#define CM33                                    ((CM33_Type*) CM33_BASE)                                          /* 0xE0000000 */
#define CM33_CTI                                ((CM33_CTI_Type*) &CM33->CTI)                                     /* 0xE0042000 */
#define CM33_TRC                                ((CM33_TRC_Type*) &CM33->TRC)                                     /* 0xE0080000 */
#define CM33_TRC_CTI                            ((CM33_TRC_CTI_Type*) &CM33->TRC.CTI)                             /* 0xE0080000 */

/** \} PSC3M8GFS3PAHQ1 */

#endif /* _PSC3M8GFS3PAHQ1_P_H_ */


/* [] END OF FILE */
