/***************************************************************************//**
* \file cy8c4148lds_s563.h
*
* \brief
* CY8C4148LDS-S563 device header
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

#ifndef _CY8C4148LDS_S563_H_
#define _CY8C4148LDS_S563_H_

/**
* \addtogroup group_device CY8C4148LDS-S563
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
  /* CY8C4148LDS-S563 Peripheral Interrupt Numbers */
  ioss_interrupts_gpio_0_IRQn       =   0,      /*!<   0 [DeepSleep] GPIO P0 */
  ioss_interrupts_gpio_1_IRQn       =   1,      /*!<   1 [DeepSleep] GPIO P1 */
  ioss_interrupts_gpio_2_IRQn       =   2,      /*!<   2 [DeepSleep] GPIO P2 */
  ioss_interrupts_gpio_3_IRQn       =   3,      /*!<   3 [DeepSleep] GPIO P3 */
  ioss_interrupt_gpio_IRQn          =   4,      /*!<   4 [DeepSleep] GPIO All Ports */
  lpcomp_interrupt_IRQn             =   5,      /*!<   5 [DeepSleep] LPCOMP trigger interrupt */
  srss_interrupt_wdt_IRQn           =   6,      /*!<   6 [DeepSleep] WDT */
  scb_0_interrupt_IRQn              =   7,      /*!<   7 [DeepSleep] SCB #0 */
  scb_1_interrupt_IRQn              =   8,      /*!<   8 [DeepSleep] SCB #1 */
  scb_2_interrupt_IRQn              =   9,      /*!<   9 [DeepSleep] SCB #2 */
  scb_3_interrupt_IRQn              =  10,      /*!<  10 [DeepSleep] SCB #3 */
  scb_4_interrupt_IRQn              =  11,      /*!<  11 [DeepSleep] SCB #4 */
  pass_0_interrupt_ctbs_IRQn        =  12,      /*!<  12 [DeepSleep] CTBm Interrupt (all CTBms) */
  wco_interrupt_IRQn                =  13,      /*!<  13 [DeepSleep] WCO WDT Interrupt */
  cpuss_interrupt_dma_IRQn          =  14,      /*!<  14 [Active] DMA Interrupt */
  cpuss_interrupt_spcif_IRQn        =  15,      /*!<  15 [Active] SPCIF interrupt */
  msc_0_interrupt_IRQn              =  16,      /*!<  16 [Active] CSD #0 (Primarily Capsense) */
  tcpwm_interrupts_0_IRQn           =  17,      /*!<  17 [Active] TCPWM #0, Counter #0 */
  tcpwm_interrupts_1_IRQn           =  18,      /*!<  18 [Active] TCPWM #0, Counter #1 */
  tcpwm_interrupts_2_IRQn           =  19,      /*!<  19 [Active] TCPWM #0, Counter #2 */
  tcpwm_interrupts_3_IRQn           =  20,      /*!<  20 [Active] TCPWM #0, Counter #3 */
  tcpwm_interrupts_4_IRQn           =  21,      /*!<  21 [Active] TCPWM #0, Counter #4 */
  tcpwm_interrupts_5_IRQn           =  22,      /*!<  22 [Active] TCPWM #0, Counter #5 */
  tcpwm_interrupts_6_IRQn           =  23,      /*!<  23 [Active] TCPWM #0, Counter #6 */
  tcpwm_interrupts_7_IRQn           =  24,      /*!<  24 [Active] TCPWM #0, Counter #7 */
  pass_0_interrupt_sar_IRQn         =  25,      /*!<  25 [Active] SAR */
  canfd_interrupts0_0_IRQn          =  26,      /*!<  26 [Active] CAN Interrupt */
  canfd_interrupts1_0_IRQn          =  27,      /*!<  27 [Active] CAN Interrupt */
  crypto_interrupt_IRQn             =  28,      /*!<  28 [Active] Crypto Interrupt */
  msc_1_interrupt_IRQn              =  29,      /*!<  29 [Active] CSD #0 (Primarily Capsense) */
  exco_interrupt_IRQn               =  30,      /*!<  30 [Active] EXCO */
  audioss_interrupt_i2s_IRQn        =  31,      /*!<  31 [Active] I2S Interrupt */
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
#define CY_SRAM_SIZE                    0x00008000UL
#define CY_FLASH_BASE                   0x00000000UL
#define CY_FLASH_SIZE                   0x00040000UL
#define CY_SFLASH_BASE                  0x0FFFE000UL
#define CY_SFLASH_SIZE                  0x00001800UL
#define CY_ROM_BASE                     0x10000000UL
#define CY_ROM_SIZE                     0x00002000UL
#define CY_CAN0MRAM_BASE                0x40410000UL
#define CY_CAN0MRAM_SIZE                0x00010000UL


/* IP List */
#define CY_IP_MXTTCANFD                 1u
#define CY_IP_MXTTCANFD_INSTANCES       1u
#define CY_IP_MXTTCANFD_VERSION         2u
#define CY_IP_ARMCM0P                   1u
#define CY_IP_ARMCM0P_INSTANCES         0u
#define CY_IP_ARMCM0P_VERSION           1u
#define CY_IP_M0S8CPUSSV3               1u
#define CY_IP_M0S8CPUSSV3_INSTANCES     1u
#define CY_IP_M0S8CPUSSV3_VERSION       3u
#define CY_IP_M0S8CPUSSV3_DMAC          1u
#define CY_IP_M0S8CPUSSV3_DMAC_INSTANCES 1u
#define CY_IP_M0S8CPUSSV3_DMAC_VERSION  3u
#define CY_IP_M0S8MSCV3                 1u
#define CY_IP_M0S8MSCV3_INSTANCES       2u
#define CY_IP_M0S8MSCV3_VERSION         1u
#define CY_IP_M0S8EXCO                  1u
#define CY_IP_M0S8EXCO_INSTANCES        1u
#define CY_IP_M0S8EXCO_VERSION          2u
#define CY_IP_M0S8IOSS                  1u
#define CY_IP_M0S8IOSS_INSTANCES        1u
#define CY_IP_M0S8IOSS_VERSION          1u
#define CY_IP_M0S8IOSS_SMARTIO          1u
#define CY_IP_M0S8IOSS_SMARTIO_INSTANCES 3u
#define CY_IP_M0S8IOSS_SMARTIO_VERSION  1u
#define CY_IP_M0S8LCD                   1u
#define CY_IP_M0S8LCD_INSTANCES         1u
#define CY_IP_M0S8LCD_VERSION           2u
#define CY_IP_M0S8LPCOMP                1u
#define CY_IP_M0S8LPCOMP_INSTANCES      1u
#define CY_IP_M0S8LPCOMP_VERSION        2u
#define CY_IP_M0S8PASS4A                1u
#define CY_IP_M0S8PASS4A_INSTANCES      1u
#define CY_IP_M0S8PASS4A_VERSION        2u
#define CY_IP_M0S8PASS4A_SAR            1u
#define CY_IP_M0S8PASS4A_SAR_INSTANCES  1u
#define CY_IP_M0S8PASS4A_SAR_VERSION    2u
#define CY_IP_M0S8PASS4A_CTB            1u
#define CY_IP_M0S8PASS4A_CTB_INSTANCES  1u
#define CY_IP_M0S8PASS4A_CTB_VERSION    2u
#define CY_IP_M0S8PERI                  1u
#define CY_IP_M0S8PERI_INSTANCES        1u
#define CY_IP_M0S8PERI_VERSION          1u
#define CY_IP_M0S8PERI_TR               1u
#define CY_IP_M0S8PERI_TR_INSTANCES     1u
#define CY_IP_M0S8PERI_TR_VERSION       1u
#define CY_IP_MXSCB                     1u
#define CY_IP_MXSCB_INSTANCES           5u
#define CY_IP_MXSCB_VERSION             3u
#define CY_IP_S8SRSSLT                  1u
#define CY_IP_S8SRSSLT_INSTANCES        1u
#define CY_IP_S8SRSSLT_VERSION          1u
#define CY_IP_M0S8TCPWM                 1u
#define CY_IP_M0S8TCPWM_INSTANCES       1u
#define CY_IP_M0S8TCPWM_VERSION         2u
#define CY_IP_M0S8WCO                   1u
#define CY_IP_M0S8WCO_INSTANCES         1u
#define CY_IP_M0S8WCO_VERSION           1u

#define CY_DEVICE_PSOC4AS4
#define CY_DEVICE_SERIES_PSOC_4100S_MAX
#define CY_SILICON_ID                   0x2EA711BEUL
#define CY_HF_CLK_MAX_FREQ              48000000UL


#include "system_cat2.h"

#include "psoc4100smax_config.h"
#include "gpio_psoc4100smax_48_qfn_auto.h"

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
#define HSIOM_PRT3                              ((HSIOM_PRT_Type*) &HSIOM->PRT[3])                                /* 0x40020300 */
#define HSIOM_PRT4                              ((HSIOM_PRT_Type*) &HSIOM->PRT[4])                                /* 0x40020400 */
#define HSIOM_PRT5                              ((HSIOM_PRT_Type*) &HSIOM->PRT[5])                                /* 0x40020500 */
#define HSIOM_PRT6                              ((HSIOM_PRT_Type*) &HSIOM->PRT[6])                                /* 0x40020600 */
#define HSIOM_PRT7                              ((HSIOM_PRT_Type*) &HSIOM->PRT[7])                                /* 0x40020700 */
#define HSIOM_PRT8                              ((HSIOM_PRT_Type*) &HSIOM->PRT[8])                                /* 0x40020800 */
#define HSIOM_PRT9                              ((HSIOM_PRT_Type*) &HSIOM->PRT[9])                                /* 0x40020900 */
#define HSIOM_PRT10                             ((HSIOM_PRT_Type*) &HSIOM->PRT[10])                               /* 0x40020A00 */
#define HSIOM_PRT11                             ((HSIOM_PRT_Type*) &HSIOM->PRT[11])                               /* 0x40020B00 */
#define HSIOM_PRT12                             ((HSIOM_PRT_Type*) &HSIOM->PRT[12])                               /* 0x40020C00 */

/*******************************************************************************
*                                    SRSSLT
*******************************************************************************/

#define SRSSLT_BASE                             0x40030000UL
#define SRSSLT                                  ((SRSSLT_Type*) SRSSLT_BASE)                                      /* 0x40030000 */

/*******************************************************************************
*                                     GPIO
*******************************************************************************/

#define GPIO_BASE                               0x40040000UL
#define GPIO                                    ((GPIO_Type*) GPIO_BASE)                                          /* 0x40040000 */
#define GPIO_PRT0                               ((GPIO_PRT_Type*) &GPIO->PRT[0])                                  /* 0x40040000 */
#define GPIO_PRT1                               ((GPIO_PRT_Type*) &GPIO->PRT[1])                                  /* 0x40040100 */
#define GPIO_PRT2                               ((GPIO_PRT_Type*) &GPIO->PRT[2])                                  /* 0x40040200 */
#define GPIO_PRT3                               ((GPIO_PRT_Type*) &GPIO->PRT[3])                                  /* 0x40040300 */
#define GPIO_PRT4                               ((GPIO_PRT_Type*) &GPIO->PRT[4])                                  /* 0x40040400 */
#define GPIO_PRT5                               ((GPIO_PRT_Type*) &GPIO->PRT[5])                                  /* 0x40040500 */
#define GPIO_PRT6                               ((GPIO_PRT_Type*) &GPIO->PRT[6])                                  /* 0x40040600 */
#define GPIO_PRT7                               ((GPIO_PRT_Type*) &GPIO->PRT[7])                                  /* 0x40040700 */
#define GPIO_PRT8                               ((GPIO_PRT_Type*) &GPIO->PRT[8])                                  /* 0x40040800 */
#define GPIO_PRT9                               ((GPIO_PRT_Type*) &GPIO->PRT[9])                                  /* 0x40040900 */
#define GPIO_PRT10                              ((GPIO_PRT_Type*) &GPIO->PRT[10])                                 /* 0x40040A00 */
#define GPIO_PRT11                              ((GPIO_PRT_Type*) &GPIO->PRT[11])                                 /* 0x40040B00 */
#define GPIO_PRT12                              ((GPIO_PRT_Type*) &GPIO->PRT[12])                                 /* 0x40040C00 */

/*******************************************************************************
*                                    PRGIO
*******************************************************************************/

#define PRGIO_BASE                              0x40050000UL
#define PRGIO                                   ((PRGIO_Type*) PRGIO_BASE)                                        /* 0x40050000 */
#define PRGIO_PRT0                              ((PRGIO_PRT_Type*) &PRGIO->PRT[0])                                /* 0x40050000 */
#define PRGIO_PRT1                              ((PRGIO_PRT_Type*) &PRGIO->PRT[1])                                /* 0x40050100 */
#define PRGIO_PRT2                              ((PRGIO_PRT_Type*) &PRGIO->PRT[2])                                /* 0x40050200 */

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
#define DMAC_DESCR8                             ((DMAC_DESCR_Type*) &DMAC->DESCR[8])                              /* 0x40101900 */
#define DMAC_DESCR9                             ((DMAC_DESCR_Type*) &DMAC->DESCR[9])                              /* 0x40101920 */
#define DMAC_DESCR10                            ((DMAC_DESCR_Type*) &DMAC->DESCR[10])                             /* 0x40101940 */
#define DMAC_DESCR11                            ((DMAC_DESCR_Type*) &DMAC->DESCR[11])                             /* 0x40101960 */
#define DMAC_DESCR12                            ((DMAC_DESCR_Type*) &DMAC->DESCR[12])                             /* 0x40101980 */
#define DMAC_DESCR13                            ((DMAC_DESCR_Type*) &DMAC->DESCR[13])                             /* 0x401019A0 */
#define DMAC_DESCR14                            ((DMAC_DESCR_Type*) &DMAC->DESCR[14])                             /* 0x401019C0 */
#define DMAC_DESCR15                            ((DMAC_DESCR_Type*) &DMAC->DESCR[15])                             /* 0x401019E0 */

/*******************************************************************************
*                                    SPCIF
*******************************************************************************/

#define SPCIF_BASE                              0x40110000UL
#define SPCIF                                   ((SPCIF_Type*) SPCIF_BASE)                                        /* 0x40110000 */

/*******************************************************************************
*                                    TCPWM
*******************************************************************************/

#define TCPWM_BASE                              0x40200000UL
#define TCPWM                                   ((TCPWM_Type*) TCPWM_BASE)                                        /* 0x40200000 */
#define TCPWM_CNT0                              ((TCPWM_CNT_Type*) &TCPWM->CNT[0])                                /* 0x40200100 */
#define TCPWM_CNT1                              ((TCPWM_CNT_Type*) &TCPWM->CNT[1])                                /* 0x40200140 */
#define TCPWM_CNT2                              ((TCPWM_CNT_Type*) &TCPWM->CNT[2])                                /* 0x40200180 */
#define TCPWM_CNT3                              ((TCPWM_CNT_Type*) &TCPWM->CNT[3])                                /* 0x402001C0 */
#define TCPWM_CNT4                              ((TCPWM_CNT_Type*) &TCPWM->CNT[4])                                /* 0x40200200 */
#define TCPWM_CNT5                              ((TCPWM_CNT_Type*) &TCPWM->CNT[5])                                /* 0x40200240 */
#define TCPWM_CNT6                              ((TCPWM_CNT_Type*) &TCPWM->CNT[6])                                /* 0x40200280 */
#define TCPWM_CNT7                              ((TCPWM_CNT_Type*) &TCPWM->CNT[7])                                /* 0x402002C0 */

/*******************************************************************************
*                                     LCD
*******************************************************************************/

#define LCD_BASE                                0x40210000UL
#define LCD                                     ((LCD_Type*) LCD_BASE)                                            /* 0x40210000 */

/*******************************************************************************
*                                     WCO
*******************************************************************************/

#define WCO_BASE                                0x40220000UL
#define WCO                                     ((WCO_Type*) WCO_BASE)                                            /* 0x40220000 */

/*******************************************************************************
*                                     SCB
*******************************************************************************/

#define SCB0_BASE                               0x40240000UL
#define SCB1_BASE                               0x40250000UL
#define SCB2_BASE                               0x40260000UL
#define SCB3_BASE                               0x40270000UL
#define SCB4_BASE                               0x40280000UL
#define SCB0                                    ((CySCB_Type*) SCB0_BASE)                                         /* 0x40240000 */
#define SCB1                                    ((CySCB_Type*) SCB1_BASE)                                         /* 0x40250000 */
#define SCB2                                    ((CySCB_Type*) SCB2_BASE)                                         /* 0x40260000 */
#define SCB3                                    ((CySCB_Type*) SCB3_BASE)                                         /* 0x40270000 */
#define SCB4                                    ((CySCB_Type*) SCB4_BASE)                                         /* 0x40280000 */

/*******************************************************************************
*                                     MSC
*******************************************************************************/

#define MSC0_BASE                               0x40290000UL
#define MSC1_BASE                               0x402A0000UL
#define MSC0                                    ((MSC_Type*) MSC0_BASE)                                           /* 0x40290000 */
#define MSC1                                    ((MSC_Type*) MSC1_BASE)                                           /* 0x402A0000 */
#define MSC0_MODE0                              ((MSC_MODE_Type*) &MSC0->MODE[0])                                 /* 0x40290500 */
#define MSC0_MODE1                              ((MSC_MODE_Type*) &MSC0->MODE[1])                                 /* 0x40290520 */
#define MSC0_MODE2                              ((MSC_MODE_Type*) &MSC0->MODE[2])                                 /* 0x40290540 */
#define MSC1_MODE0                              ((MSC_MODE_Type*) &MSC1->MODE[0])                                 /* 0x402A0500 */
#define MSC1_MODE1                              ((MSC_MODE_Type*) &MSC1->MODE[1])                                 /* 0x402A0520 */
#define MSC1_MODE2                              ((MSC_MODE_Type*) &MSC1->MODE[2])                                 /* 0x402A0540 */

/*******************************************************************************
*                                    LPCOMP
*******************************************************************************/

#define LPCOMP_BASE                             0x402B0000UL
#define LPCOMP                                  ((LPCOMP_Type*) LPCOMP_BASE)                                      /* 0x402B0000 */

/*******************************************************************************
*                                     EXCO
*******************************************************************************/

#define EXCO_BASE                               0x402F0000UL
#define EXCO                                    ((EXCO_Type*) EXCO_BASE)                                          /* 0x402F0000 */

/*******************************************************************************
*                                     CTBM
*******************************************************************************/

#define CTBM0_BASE                              0x40300000UL
#define CTBM0                                   ((CTBM_Type*) CTBM0_BASE)                                         /* 0x40300000 */

/*******************************************************************************
*                                     SAR
*******************************************************************************/

#define SAR0_BASE                               0x403A0000UL
#define SAR0                                    ((SAR_Type*) SAR0_BASE)                                           /* 0x403A0000 */

/*******************************************************************************
*                                     PASS
*******************************************************************************/

#define PASS0_BASE                              0x403F0000UL
#define PASS0                                   ((PASS_Type*) PASS0_BASE)                                         /* 0x403F0000 */
#define PASS0_DSAB                              ((PASS_DSAB_Type*) &PASS0->DSAB)                                  /* 0x403F0E00 */

/*******************************************************************************
*                                    CANFD
*******************************************************************************/

#define CANFD0_BASE                             0x40400000UL
#define CANFD0                                  ((CANFD_Type*) CANFD0_BASE)                                       /* 0x40400000 */
#define CANFD0_CH0                              ((CANFD_CH_Type*) &CANFD0->CH[0])                                 /* 0x40400000 */
#define CANFD0_CH0_M_TTCAN                      ((CANFD_CH_M_TTCAN_Type*) &CANFD0->CH[0].M_TTCAN)                 /* 0x40400000 */

/** \} CY8C4148LDS-S563 */

#endif /* _CY8C4148LDS_S563_H_ */


/* [] END OF FILE */
