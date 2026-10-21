/***************************************************************************//**
* \file cy8c4126lce_hv413.h
*
* \brief
* CY8C4126LCE-HV413 device header
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

#ifndef _CY8C4126LCE_HV413_H_
#define _CY8C4126LCE_HV413_H_

/**
* \addtogroup group_device CY8C4126LCE-HV413
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
  /* ARM Cortex-M0+ Core Interrupt Numbers */
  Reset_IRQn                        = -15,      /*!< -15 Reset Vector, invoked on Power up and warm reset */
  NonMaskableInt_IRQn               = -14,      /*!< -14 Non maskable Interrupt, cannot be stopped or preempted */
  HardFault_IRQn                    = -13,      /*!< -13 Hard Fault, all classes of Fault */
  SVCall_IRQn                       =  -5,      /*!<  -5 System Service Call via SVC instruction */
  PendSV_IRQn                       =  -2,      /*!<  -2 Pendable request for system service */
  SysTick_IRQn                      =  -1,      /*!<  -1 System Tick Timer */
  /* CY8C4126LCE-HV413 Peripheral Interrupt Numbers */
  srss_interrupt_srss_IRQn          =   0,      /*!<   0 [DeepSleep] SRSS interrupts */
  srss_wdt_irq_IRQn                 =   1,      /*!<   1 [DeepSleep] WDT Interrupt */
  ioss_interrupt_gpio_IRQn          =   2,      /*!<   2 [DeepSleep] GPIO consolidated interrupt */
  ioss_interrupts_gpio_0_IRQn       =   3,      /*!<   3 [DeepSleep] GPIO P0 */
  ioss_interrupts_gpio_1_IRQn       =   4,      /*!<   4 [DeepSleep] GPIO P1 */
  ioss_interrupts_gpio_2_IRQn       =   5,      /*!<   5 [DeepSleep] GPIO P2 */
  hvss_interrupt_lin_IRQn           =   6,      /*!<   6 [DeepSleep] HVSS LIN interface interrupt */
  scb_0_interrupt_IRQn              =   7,      /*!<   7 [DeepSleep] SCB #0 interrupt */
  cpuss_interrupt_dma_IRQn          =   8,      /*!<   8 [Active] DMA Interrupt */
  cpuss_interrupt_spcif_IRQn        =   9,      /*!<   9 [Active] SPCIF interrupt */
  cpuss_interrupt_spcif1_IRQn       =  10,      /*!<  10 [Active] SPCIF interrupt, controller 1 */
  cpuss_interrupt_fault_0_IRQn      =  11,      /*!<  11 [Active] Fault structure 0 interrupt */
  cpuss_interrupt_fault_1_IRQn      =  12,      /*!<  12 [Active] Fault structure 1 interrupt */
  lin_interrupts_0_IRQn             =  13,      /*!<  13 [Active] LIN interrupt, channel #0 */
  lin_interrupts_1_IRQn             =  14,      /*!<  14 [Active] LIN interrupt, channel #1 */
  tcpwm_interrupts_0_IRQn           =  15,      /*!<  15 [Active] TCPWM #0, Counter #0 */
  tcpwm_interrupts_1_IRQn           =  16,      /*!<  16 [Active] TCPWM #0, Counter #1 */
  tcpwm_interrupts_2_IRQn           =  17,      /*!<  17 [Active] TCPWM #0, Counter #2 */
  tcpwm_interrupts_3_IRQn           =  18,      /*!<  18 [Active] TCPWM #0, Counter #3 */
  pacss_interrupt_IRQn              =  19,      /*!<  19 [Active] PACSS consolidated interrupt */
  pacss_interrupts_dch_0_IRQn       =  20,      /*!<  20 [Active] PACSS digital channel #0 */
  pacss_interrupts_dch_1_IRQn       =  21,      /*!<  21 [Active] PACSS digital channel #1 */
  pacss_interrupts_dch_2_IRQn       =  22,      /*!<  22 [Active] PACSS digital channel #2 */
  pacss_interrupts_dch_3_IRQn       =  23,      /*!<  23 [Active] PACSS digital channel #3 */
  pacss_interrupt_mmio_IRQn         =  24,      /*!<  24 [Active] PACSS mmio */
  unconnected_IRQn                  = 240       /*!< 240 Unconnected */
} IRQn_Type;


/*******************************************************************************
*                    Processor and Core Peripheral Section
*******************************************************************************/

/* Configuration of the ARM Cortex-M0+ Processor and Core Peripherals */
#define __CM0PLUS_REV                   0x0001U /*!< CM0PLUS Core Revision */
#define __NVIC_PRIO_BITS                2       /*!< Number of Bits used for Priority Levels */
#define __Vendor_SysTickConfig          0       /*!< Set to 1 if different SysTick Config is used */
#define __VTOR_PRESENT                  1       /*!< Set to 1 if CPU supports Vector Table Offset Register */
#define __MPU_PRESENT                   1       /*!< MPU present or not */

/** \} Configuration_of_CMSIS */

#include "core_cm0plus.h"                       /*!< ARM Cortex-M0+ processor and core peripherals */


/* Memory Blocks */
#define CY_SRAM_BASE                    0x20000000UL
#define CY_SRAM_SIZE                    0x00001000UL
#define CY_FLASH_BASE                   0x00000000UL
#define CY_FLASH_SIZE                   0x00010000UL
#define CY_SFLASH_BASE                  0x0FFFE000UL
#define CY_SFLASH_SIZE                  0x00000800UL
#define CY_ROM_BASE                     0x10000000UL
#define CY_ROM_SIZE                     0x00008000UL
#define CY_FLASH1_BASE                  0x1F000000UL
#define CY_FLASH1_SIZE                  0x00002000UL
#define CY_SFLASH1_BASE                 0x1FFFE000UL
#define CY_SFLASH1_SIZE                 0x00000400UL


/* IP List */
#define CY_IP_ARMCM0P                   1u
#define CY_IP_ARMCM0P_INSTANCES         0u
#define CY_IP_ARMCM0P_VERSION           1u
#define CY_IP_M0S8CPUSSV3               1u
#define CY_IP_M0S8CPUSSV3_INSTANCES     1u
#define CY_IP_M0S8CPUSSV3_VERSION       3u
#define CY_IP_M0S8CPUSSV3_DMAC          1u
#define CY_IP_M0S8CPUSSV3_DMAC_INSTANCES 1u
#define CY_IP_M0S8CPUSSV3_DMAC_VERSION  3u
#define CY_IP_M0S8HVSS                  1u
#define CY_IP_M0S8HVSS_INSTANCES        1u
#define CY_IP_M0S8HVSS_VERSION          1u
#define CY_IP_M0S8IOSS                  1u
#define CY_IP_M0S8IOSS_INSTANCES        1u
#define CY_IP_M0S8IOSS_VERSION          1u
#define CY_IP_MXLIN                     1u
#define CY_IP_MXLIN_INSTANCES           1u
#define CY_IP_MXLIN_VERSION             1u
#define CY_IP_M0S8PACSS                 1u
#define CY_IP_M0S8PACSS_INSTANCES       1u
#define CY_IP_M0S8PACSS_VERSION         1u
#define CY_IP_M0S8PERI                  1u
#define CY_IP_M0S8PERI_INSTANCES        1u
#define CY_IP_M0S8PERI_VERSION          1u
#define CY_IP_M0S8PERI_TR               1u
#define CY_IP_M0S8PERI_TR_INSTANCES     1u
#define CY_IP_M0S8PERI_TR_VERSION       1u
#define CY_IP_M0S8SCB                   1u
#define CY_IP_M0S8SCB_INSTANCES         1u
#define CY_IP_M0S8SCB_VERSION           2u
#define CY_IP_M0S8SRSSHV                1u
#define CY_IP_M0S8SRSSHV_INSTANCES      1u
#define CY_IP_M0S8SRSSHV_VERSION        1u
#define CY_IP_M0S8TCPWM                 1u
#define CY_IP_M0S8TCPWM_INSTANCES       1u
#define CY_IP_M0S8TCPWM_VERSION         2u

#define CY_DEVICE_PSOC4HV144K
#define CY_DEVICE_SERIES_PSOC_4_HV_PA_144K
#define CY_SILICON_ID                   0x320111C2UL
#define CY_HF_CLK_MAX_FREQ              24000000UL


#include "system_cat2.h"

#include "psoc4hv144k_config.h"
#include "gpio_psoc4hv144k_32_qfn.h"

/*******************************************************************************
*                                    SFLASH
*******************************************************************************/

#define SFLASH_BASE                             0x0FFFE000UL
#define SFLASH                                  ((SFLASH_Type*) SFLASH_BASE)                                      /* 0x0FFFE000 */

/*******************************************************************************
*                                     PERI
*******************************************************************************/

#define PERI_BASE                               0x40010000UL
#define PERI                                    ((PERI_Type*) PERI_BASE)                                          /* 0x40010000 */
#define PERI_TR_GROUP0                          ((PERI_TR_GROUP_Type*) &PERI->TR_GROUP[0])                        /* 0x40012000 */
#define PERI_TR_GROUP1                          ((PERI_TR_GROUP_Type*) &PERI->TR_GROUP[1])                        /* 0x40012200 */
#define PERI_TR_GROUP2                          ((PERI_TR_GROUP_Type*) &PERI->TR_GROUP[2])                        /* 0x40012400 */
#define PERI_TR_GROUP3                          ((PERI_TR_GROUP_Type*) &PERI->TR_GROUP[3])                        /* 0x40012600 */

/*******************************************************************************
*                                    HSIOM
*******************************************************************************/

#define HSIOM_BASE                              0x40020000UL
#define HSIOM                                   ((HSIOM_Type*) HSIOM_BASE)                                        /* 0x40020000 */
#define HSIOM_PRT0                              ((HSIOM_PRT_Type*) &HSIOM->PRT[0])                                /* 0x40020000 */
#define HSIOM_PRT1                              ((HSIOM_PRT_Type*) &HSIOM->PRT[1])                                /* 0x40020100 */
#define HSIOM_PRT2                              ((HSIOM_PRT_Type*) &HSIOM->PRT[2])                                /* 0x40020200 */

/*******************************************************************************
*                                    SRSSHV
*******************************************************************************/

#define SRSSHV_BASE                             0x40030000UL
#define SRSSHV                                  ((SRSSHV_Type*) SRSSHV_BASE)                                      /* 0x40030000 */
#define WDT                                     ((WDT_Type*) &SRSSHV->WDT_STRUCT)                                 /* 0x40030100 */

/*******************************************************************************
*                                     GPIO
*******************************************************************************/

#define GPIO_BASE                               0x40040000UL
#define GPIO                                    ((GPIO_Type*) GPIO_BASE)                                          /* 0x40040000 */
#define GPIO_PRT0                               ((GPIO_PRT_Type*) &GPIO->PRT[0])                                  /* 0x40040000 */
#define GPIO_PRT1                               ((GPIO_PRT_Type*) &GPIO->PRT[1])                                  /* 0x40040100 */
#define GPIO_PRT2                               ((GPIO_PRT_Type*) &GPIO->PRT[2])                                  /* 0x40040200 */

/*******************************************************************************
*                                     HVSS
*******************************************************************************/

#define HVSS_BASE                               0x40060000UL
#define HVSS                                    ((HVSS_Type*) HVSS_BASE)                                          /* 0x40060000 */

/*******************************************************************************
*                                    CPUSS
*******************************************************************************/

#define CPUSS_BASE                              0x40100000UL
#define CPUSS                                   ((CPUSS_Type*) CPUSS_BASE)                                        /* 0x40100000 */

/*******************************************************************************
*                                     DMAC
*******************************************************************************/

#define DMAC_BASE                               0x40101000UL
#define DMAC                                    ((DMAC_Type*) DMAC_BASE)                                          /* 0x40101000 */
#define DMAC_DESCR0                             ((DMAC_DESCR_Type*) &DMAC->DESCR[0])                              /* 0x40101800 */
#define DMAC_DESCR1                             ((DMAC_DESCR_Type*) &DMAC->DESCR[1])                              /* 0x40101820 */
#define DMAC_DESCR2                             ((DMAC_DESCR_Type*) &DMAC->DESCR[2])                              /* 0x40101840 */
#define DMAC_DESCR3                             ((DMAC_DESCR_Type*) &DMAC->DESCR[3])                              /* 0x40101860 */
#define DMAC_DESCR4                             ((DMAC_DESCR_Type*) &DMAC->DESCR[4])                              /* 0x40101880 */
#define DMAC_DESCR5                             ((DMAC_DESCR_Type*) &DMAC->DESCR[5])                              /* 0x401018A0 */
#define DMAC_DESCR6                             ((DMAC_DESCR_Type*) &DMAC->DESCR[6])                              /* 0x401018C0 */
#define DMAC_DESCR7                             ((DMAC_DESCR_Type*) &DMAC->DESCR[7])                              /* 0x401018E0 */

/*******************************************************************************
*                                    SPCIF
*******************************************************************************/

#define SPCIF_BASE                              0x40110000UL
#define SPCIF                                   ((SPCIF_Type*) SPCIF_BASE)                                        /* 0x40110000 */

/*******************************************************************************
*                                    SPCIF1
*******************************************************************************/

#define SPCIF1_BASE                             0x40120000UL
#define SPCIF1                                  ((SPCIF1_Type*) SPCIF1_BASE)                                      /* 0x40120000 */

/*******************************************************************************
*                                    FAULT
*******************************************************************************/

#define FAULT_BASE                              0x40130000UL
#define FAULT                                   ((FAULT_Type*) FAULT_BASE)                                        /* 0x40130000 */
#define FAULT_STRUCT0                           ((FAULT_STRUCT_Type*) &FAULT->STRUCT[0])                          /* 0x40130000 */
#define FAULT_STRUCT1                           ((FAULT_STRUCT_Type*) &FAULT->STRUCT[1])                          /* 0x40130100 */

/*******************************************************************************
*                                    TCPWM
*******************************************************************************/

#define TCPWM_BASE                              0x40200000UL
#define TCPWM                                   ((TCPWM_Type*) TCPWM_BASE)                                        /* 0x40200000 */
#define TCPWM_CNT0                              ((TCPWM_CNT_Type*) &TCPWM->CNT[0])                                /* 0x40200100 */
#define TCPWM_CNT1                              ((TCPWM_CNT_Type*) &TCPWM->CNT[1])                                /* 0x40200140 */
#define TCPWM_CNT2                              ((TCPWM_CNT_Type*) &TCPWM->CNT[2])                                /* 0x40200180 */
#define TCPWM_CNT3                              ((TCPWM_CNT_Type*) &TCPWM->CNT[3])                                /* 0x402001C0 */

/*******************************************************************************
*                                     SCB
*******************************************************************************/

#define SCB0_BASE                               0x40240000UL
#define SCB0                                    ((CySCB_Type*) SCB0_BASE)                                         /* 0x40240000 */

/*******************************************************************************
*                                     LIN
*******************************************************************************/

#define LIN0_BASE                               0x402D0000UL
#define LIN0                                    ((LIN_Type*) LIN0_BASE)                                           /* 0x402D0000 */
#define LIN0_CH0                                ((LIN_CH_Type*) &LIN0->CH[0])                                     /* 0x402D8000 */
#define LIN0_CH1                                ((LIN_CH_Type*) &LIN0->CH[1])                                     /* 0x402D8100 */

/*******************************************************************************
*                                    PACSS
*******************************************************************************/

#define PACSS_BASE                              0x40300000UL
#define PACSS                                   ((PACSS_Type*) PACSS_BASE)                                        /* 0x40300000 */
#define PACSS_DCHAN0                            ((PACSS_DCHAN_Type*) &PACSS->DCHAN[0])                            /* 0x40300000 */
#define PACSS_DCHAN1                            ((PACSS_DCHAN_Type*) &PACSS->DCHAN[1])                            /* 0x40310000 */
#define PACSS_DCHAN2                            ((PACSS_DCHAN_Type*) &PACSS->DCHAN[2])                            /* 0x40320000 */
#define PACSS_DCHAN3                            ((PACSS_DCHAN_Type*) &PACSS->DCHAN[3])                            /* 0x40330000 */
#define PACSS_DCHAN0_FCFG0                      ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[0].FCFG[0])               /* 0x40300100 */
#define PACSS_DCHAN0_FCFG1                      ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[0].FCFG[1])               /* 0x40300110 */
#define PACSS_DCHAN0_FCFG2                      ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[0].FCFG[2])               /* 0x40300120 */
#define PACSS_DCHAN0_FCFG3                      ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[0].FCFG[3])               /* 0x40300130 */
#define PACSS_DCHAN0_FCFG4                      ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[0].FCFG[4])               /* 0x40300140 */
#define PACSS_DCHAN0_FCFG5                      ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[0].FCFG[5])               /* 0x40300150 */
#define PACSS_DCHAN0_FCFG6                      ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[0].FCFG[6])               /* 0x40300160 */
#define PACSS_DCHAN0_FCFG7                      ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[0].FCFG[7])               /* 0x40300170 */
#define PACSS_DCHAN0_FCFG8                      ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[0].FCFG[8])               /* 0x40300180 */
#define PACSS_DCHAN0_FCFG9                      ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[0].FCFG[9])               /* 0x40300190 */
#define PACSS_DCHAN0_FCFG10                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[0].FCFG[10])              /* 0x403001A0 */
#define PACSS_DCHAN0_FCFG11                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[0].FCFG[11])              /* 0x403001B0 */
#define PACSS_DCHAN0_FCFG12                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[0].FCFG[12])              /* 0x403001C0 */
#define PACSS_DCHAN0_FCFG13                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[0].FCFG[13])              /* 0x403001D0 */
#define PACSS_DCHAN0_FCFG14                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[0].FCFG[14])              /* 0x403001E0 */
#define PACSS_DCHAN0_FCFG15                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[0].FCFG[15])              /* 0x403001F0 */
#define PACSS_DCHAN0_FCFG16                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[0].FCFG[16])              /* 0x40300200 */
#define PACSS_DCHAN0_FCFG17                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[0].FCFG[17])              /* 0x40300210 */
#define PACSS_DCHAN0_FCFG18                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[0].FCFG[18])              /* 0x40300220 */
#define PACSS_DCHAN0_FCFG19                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[0].FCFG[19])              /* 0x40300230 */
#define PACSS_DCHAN0_FCFG20                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[0].FCFG[20])              /* 0x40300240 */
#define PACSS_DCHAN0_FCFG21                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[0].FCFG[21])              /* 0x40300250 */
#define PACSS_DCHAN0_FCFG22                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[0].FCFG[22])              /* 0x40300260 */
#define PACSS_DCHAN0_FCFG23                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[0].FCFG[23])              /* 0x40300270 */
#define PACSS_DCHAN0_FCFG24                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[0].FCFG[24])              /* 0x40300280 */
#define PACSS_DCHAN0_FCFG25                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[0].FCFG[25])              /* 0x40300290 */
#define PACSS_DCHAN0_FCFG26                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[0].FCFG[26])              /* 0x403002A0 */
#define PACSS_DCHAN0_FCFG27                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[0].FCFG[27])              /* 0x403002B0 */
#define PACSS_DCHAN0_FCFG28                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[0].FCFG[28])              /* 0x403002C0 */
#define PACSS_DCHAN0_FCFG29                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[0].FCFG[29])              /* 0x403002D0 */
#define PACSS_DCHAN0_FCFG30                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[0].FCFG[30])              /* 0x403002E0 */
#define PACSS_DCHAN0_FCFG31                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[0].FCFG[31])              /* 0x403002F0 */
#define PACSS_DCHAN0_FCFG32                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[0].FCFG[32])              /* 0x40300300 */
#define PACSS_DCHAN0_FCFG33                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[0].FCFG[33])              /* 0x40300310 */
#define PACSS_DCHAN0_FCFG34                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[0].FCFG[34])              /* 0x40300320 */
#define PACSS_DCHAN0_FCFG35                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[0].FCFG[35])              /* 0x40300330 */
#define PACSS_DCHAN0_FCFG36                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[0].FCFG[36])              /* 0x40300340 */
#define PACSS_DCHAN0_FCFG37                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[0].FCFG[37])              /* 0x40300350 */
#define PACSS_DCHAN0_FCFG38                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[0].FCFG[38])              /* 0x40300360 */
#define PACSS_DCHAN0_FCFG39                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[0].FCFG[39])              /* 0x40300370 */
#define PACSS_DCHAN0_FCFG40                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[0].FCFG[40])              /* 0x40300380 */
#define PACSS_DCHAN0_FCFG41                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[0].FCFG[41])              /* 0x40300390 */
#define PACSS_DCHAN0_FCFG42                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[0].FCFG[42])              /* 0x403003A0 */
#define PACSS_DCHAN0_FCFG43                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[0].FCFG[43])              /* 0x403003B0 */
#define PACSS_DCHAN0_FCFG44                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[0].FCFG[44])              /* 0x403003C0 */
#define PACSS_DCHAN0_FCFG45                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[0].FCFG[45])              /* 0x403003D0 */
#define PACSS_DCHAN0_FCFG46                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[0].FCFG[46])              /* 0x403003E0 */
#define PACSS_DCHAN0_FCFG47                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[0].FCFG[47])              /* 0x403003F0 */
#define PACSS_DCHAN0_FCFG48                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[0].FCFG[48])              /* 0x40300400 */
#define PACSS_DCHAN0_FCFG49                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[0].FCFG[49])              /* 0x40300410 */
#define PACSS_DCHAN0_FCFG50                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[0].FCFG[50])              /* 0x40300420 */
#define PACSS_DCHAN0_FCFG51                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[0].FCFG[51])              /* 0x40300430 */
#define PACSS_DCHAN0_FCFG52                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[0].FCFG[52])              /* 0x40300440 */
#define PACSS_DCHAN0_FCFG53                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[0].FCFG[53])              /* 0x40300450 */
#define PACSS_DCHAN0_FCFG54                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[0].FCFG[54])              /* 0x40300460 */
#define PACSS_DCHAN0_FCFG55                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[0].FCFG[55])              /* 0x40300470 */
#define PACSS_DCHAN0_FCFG56                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[0].FCFG[56])              /* 0x40300480 */
#define PACSS_DCHAN0_FCFG57                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[0].FCFG[57])              /* 0x40300490 */
#define PACSS_DCHAN0_FCFG58                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[0].FCFG[58])              /* 0x403004A0 */
#define PACSS_DCHAN0_FCFG59                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[0].FCFG[59])              /* 0x403004B0 */
#define PACSS_DCHAN0_FCFG60                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[0].FCFG[60])              /* 0x403004C0 */
#define PACSS_DCHAN0_FCFG61                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[0].FCFG[61])              /* 0x403004D0 */
#define PACSS_DCHAN0_FCFG62                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[0].FCFG[62])              /* 0x403004E0 */
#define PACSS_DCHAN0_FCFG63                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[0].FCFG[63])              /* 0x403004F0 */
#define PACSS_DCHAN1_FCFG0                      ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[1].FCFG[0])               /* 0x40310100 */
#define PACSS_DCHAN1_FCFG1                      ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[1].FCFG[1])               /* 0x40310110 */
#define PACSS_DCHAN1_FCFG2                      ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[1].FCFG[2])               /* 0x40310120 */
#define PACSS_DCHAN1_FCFG3                      ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[1].FCFG[3])               /* 0x40310130 */
#define PACSS_DCHAN1_FCFG4                      ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[1].FCFG[4])               /* 0x40310140 */
#define PACSS_DCHAN1_FCFG5                      ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[1].FCFG[5])               /* 0x40310150 */
#define PACSS_DCHAN1_FCFG6                      ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[1].FCFG[6])               /* 0x40310160 */
#define PACSS_DCHAN1_FCFG7                      ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[1].FCFG[7])               /* 0x40310170 */
#define PACSS_DCHAN1_FCFG8                      ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[1].FCFG[8])               /* 0x40310180 */
#define PACSS_DCHAN1_FCFG9                      ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[1].FCFG[9])               /* 0x40310190 */
#define PACSS_DCHAN1_FCFG10                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[1].FCFG[10])              /* 0x403101A0 */
#define PACSS_DCHAN1_FCFG11                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[1].FCFG[11])              /* 0x403101B0 */
#define PACSS_DCHAN1_FCFG12                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[1].FCFG[12])              /* 0x403101C0 */
#define PACSS_DCHAN1_FCFG13                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[1].FCFG[13])              /* 0x403101D0 */
#define PACSS_DCHAN1_FCFG14                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[1].FCFG[14])              /* 0x403101E0 */
#define PACSS_DCHAN1_FCFG15                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[1].FCFG[15])              /* 0x403101F0 */
#define PACSS_DCHAN1_FCFG16                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[1].FCFG[16])              /* 0x40310200 */
#define PACSS_DCHAN1_FCFG17                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[1].FCFG[17])              /* 0x40310210 */
#define PACSS_DCHAN1_FCFG18                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[1].FCFG[18])              /* 0x40310220 */
#define PACSS_DCHAN1_FCFG19                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[1].FCFG[19])              /* 0x40310230 */
#define PACSS_DCHAN1_FCFG20                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[1].FCFG[20])              /* 0x40310240 */
#define PACSS_DCHAN1_FCFG21                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[1].FCFG[21])              /* 0x40310250 */
#define PACSS_DCHAN1_FCFG22                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[1].FCFG[22])              /* 0x40310260 */
#define PACSS_DCHAN1_FCFG23                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[1].FCFG[23])              /* 0x40310270 */
#define PACSS_DCHAN1_FCFG24                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[1].FCFG[24])              /* 0x40310280 */
#define PACSS_DCHAN1_FCFG25                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[1].FCFG[25])              /* 0x40310290 */
#define PACSS_DCHAN1_FCFG26                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[1].FCFG[26])              /* 0x403102A0 */
#define PACSS_DCHAN1_FCFG27                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[1].FCFG[27])              /* 0x403102B0 */
#define PACSS_DCHAN1_FCFG28                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[1].FCFG[28])              /* 0x403102C0 */
#define PACSS_DCHAN1_FCFG29                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[1].FCFG[29])              /* 0x403102D0 */
#define PACSS_DCHAN1_FCFG30                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[1].FCFG[30])              /* 0x403102E0 */
#define PACSS_DCHAN1_FCFG31                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[1].FCFG[31])              /* 0x403102F0 */
#define PACSS_DCHAN1_FCFG32                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[1].FCFG[32])              /* 0x40310300 */
#define PACSS_DCHAN1_FCFG33                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[1].FCFG[33])              /* 0x40310310 */
#define PACSS_DCHAN1_FCFG34                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[1].FCFG[34])              /* 0x40310320 */
#define PACSS_DCHAN1_FCFG35                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[1].FCFG[35])              /* 0x40310330 */
#define PACSS_DCHAN1_FCFG36                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[1].FCFG[36])              /* 0x40310340 */
#define PACSS_DCHAN1_FCFG37                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[1].FCFG[37])              /* 0x40310350 */
#define PACSS_DCHAN1_FCFG38                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[1].FCFG[38])              /* 0x40310360 */
#define PACSS_DCHAN1_FCFG39                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[1].FCFG[39])              /* 0x40310370 */
#define PACSS_DCHAN1_FCFG40                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[1].FCFG[40])              /* 0x40310380 */
#define PACSS_DCHAN1_FCFG41                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[1].FCFG[41])              /* 0x40310390 */
#define PACSS_DCHAN1_FCFG42                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[1].FCFG[42])              /* 0x403103A0 */
#define PACSS_DCHAN1_FCFG43                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[1].FCFG[43])              /* 0x403103B0 */
#define PACSS_DCHAN1_FCFG44                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[1].FCFG[44])              /* 0x403103C0 */
#define PACSS_DCHAN1_FCFG45                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[1].FCFG[45])              /* 0x403103D0 */
#define PACSS_DCHAN1_FCFG46                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[1].FCFG[46])              /* 0x403103E0 */
#define PACSS_DCHAN1_FCFG47                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[1].FCFG[47])              /* 0x403103F0 */
#define PACSS_DCHAN1_FCFG48                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[1].FCFG[48])              /* 0x40310400 */
#define PACSS_DCHAN1_FCFG49                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[1].FCFG[49])              /* 0x40310410 */
#define PACSS_DCHAN1_FCFG50                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[1].FCFG[50])              /* 0x40310420 */
#define PACSS_DCHAN1_FCFG51                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[1].FCFG[51])              /* 0x40310430 */
#define PACSS_DCHAN1_FCFG52                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[1].FCFG[52])              /* 0x40310440 */
#define PACSS_DCHAN1_FCFG53                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[1].FCFG[53])              /* 0x40310450 */
#define PACSS_DCHAN1_FCFG54                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[1].FCFG[54])              /* 0x40310460 */
#define PACSS_DCHAN1_FCFG55                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[1].FCFG[55])              /* 0x40310470 */
#define PACSS_DCHAN1_FCFG56                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[1].FCFG[56])              /* 0x40310480 */
#define PACSS_DCHAN1_FCFG57                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[1].FCFG[57])              /* 0x40310490 */
#define PACSS_DCHAN1_FCFG58                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[1].FCFG[58])              /* 0x403104A0 */
#define PACSS_DCHAN1_FCFG59                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[1].FCFG[59])              /* 0x403104B0 */
#define PACSS_DCHAN1_FCFG60                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[1].FCFG[60])              /* 0x403104C0 */
#define PACSS_DCHAN1_FCFG61                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[1].FCFG[61])              /* 0x403104D0 */
#define PACSS_DCHAN1_FCFG62                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[1].FCFG[62])              /* 0x403104E0 */
#define PACSS_DCHAN1_FCFG63                     ((PACSS_DCHAN_FCFG_Type*) &PACSS->DCHAN[1].FCFG[63])              /* 0x403104F0 */
#define PACSS_ACHAN0                            ((PACSS_ACHAN_Type*) &PACSS->ACHAN[0])                            /* 0x40340000 */
#define PACSS_ACHAN1                            ((PACSS_ACHAN_Type*) &PACSS->ACHAN[1])                            /* 0x40350000 */
#define PACSS_MMIO                              ((PACSS_MMIO_Type*) &PACSS->MMIO)                                 /* 0x403F0000 */
#define PACSS_MMIO_GAINLVL_STRUCT0              ((PACSS_MMIO_GAINLVL_STRUCT_Type*) &PACSS->MMIO.GAINLVL_STRUCT[0]) /* 0x403F0100 */
#define PACSS_MMIO_GAINLVL_STRUCT1              ((PACSS_MMIO_GAINLVL_STRUCT_Type*) &PACSS->MMIO.GAINLVL_STRUCT[1]) /* 0x403F0110 */
#define PACSS_MMIO_GAINLVL_STRUCT2              ((PACSS_MMIO_GAINLVL_STRUCT_Type*) &PACSS->MMIO.GAINLVL_STRUCT[2]) /* 0x403F0120 */
#define PACSS_MMIO_GAINLVL_STRUCT3              ((PACSS_MMIO_GAINLVL_STRUCT_Type*) &PACSS->MMIO.GAINLVL_STRUCT[3]) /* 0x403F0130 */
#define PACSS_MMIO_GAINLVL_STRUCT4              ((PACSS_MMIO_GAINLVL_STRUCT_Type*) &PACSS->MMIO.GAINLVL_STRUCT[4]) /* 0x403F0140 */
#define PACSS_MMIO_GAINLVL_STRUCT5              ((PACSS_MMIO_GAINLVL_STRUCT_Type*) &PACSS->MMIO.GAINLVL_STRUCT[5]) /* 0x403F0150 */
#define PACSS_MMIO_GAINLVL_STRUCT6              ((PACSS_MMIO_GAINLVL_STRUCT_Type*) &PACSS->MMIO.GAINLVL_STRUCT[6]) /* 0x403F0160 */
#define PACSS_MMIO_GAINLVL_STRUCT7              ((PACSS_MMIO_GAINLVL_STRUCT_Type*) &PACSS->MMIO.GAINLVL_STRUCT[7]) /* 0x403F0170 */
#define PACSS_MMIO_GAINLVL_STRUCT8              ((PACSS_MMIO_GAINLVL_STRUCT_Type*) &PACSS->MMIO.GAINLVL_STRUCT[8]) /* 0x403F0180 */
#define PACSS_MMIO_GAINLVL_STRUCT9              ((PACSS_MMIO_GAINLVL_STRUCT_Type*) &PACSS->MMIO.GAINLVL_STRUCT[9]) /* 0x403F0190 */

/** \} CY8C4126LCE-HV413 */

#endif /* _CY8C4126LCE_HV413_H_ */


/* [] END OF FILE */
