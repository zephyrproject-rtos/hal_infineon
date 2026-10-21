/***************************************************************************//**
* \file cy8c4147lde_hvs034.h
*
* \brief
* CY8C4147LDE-HVS034 device header
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

#ifndef _CY8C4147LDE_HVS034_H_
#define _CY8C4147LDE_HVS034_H_

/**
* \addtogroup group_device CY8C4147LDE-HVS034
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
  /* CY8C4147LDE-HVS034 Peripheral Interrupt Numbers */
  srss_interrupt_srss_IRQn          =   0,      /*!<   0 [DeepSleep] SRSS interrupts */
  srss_wdt_irq_IRQn                 =   1,      /*!<   1 [DeepSleep] WDT Interrupt */
  ioss_interrupt_gpio_IRQn          =   2,      /*!<   2 [DeepSleep] GPIO consolidated interrupt */
  ioss_interrupts_gpio_0_IRQn       =   3,      /*!<   3 [DeepSleep] GPIO P0 */
  ioss_interrupts_gpio_1_IRQn       =   4,      /*!<   4 [DeepSleep] GPIO P1 */
  ioss_interrupts_gpio_2_IRQn       =   5,      /*!<   5 [DeepSleep] GPIO P2 */
  hvss_interrupt_hvss_IRQn          =   6,      /*!<   6 [DeepSleep] HVSS interface interrupt */
  lpcomp_interrupt_IRQn             =   7,      /*!<   7 [DeepSleep] LPCOMP#0 trigger interrupt */
  scb_0_interrupt_IRQn              =   8,      /*!<   8 [DeepSleep] SCB #0 interrupt */
  scb_1_interrupt_IRQn              =   9,      /*!<   9 [DeepSleep] SCB #0 interrupt */
  pass_0_interrupt_ctbs_IRQn        =  10,      /*!<  10 [DeepSleep] CTBm */
  scb_2_interrupt_IRQn              =  11,      /*!<  11 [DeepSleep] SCB #2 interrupt */
  scb_3_interrupt_IRQn              =  12,      /*!<  12 [DeepSleep] SCB #3 interrupt */
  cpuss_interrupt_dma_IRQn          =  13,      /*!<  13 [Active] DMA Interrupt */
  cpuss_interrupt_spcif_IRQn        =  14,      /*!<  14 [Active] SPCIF interrupt */
  cpuss_interrupt_fault_0_IRQn      =  15,      /*!<  15 [Active] Fault structure 0 interrupt */
  cpuss_interrupt_fault_1_IRQn      =  16,      /*!<  16 [Active] Fault structure 1 interrupt */
  lin_interrupts_0_IRQn             =  17,      /*!<  17 [Active] LIN interrupt, channel #0 */
  lin_interrupts_1_IRQn             =  18,      /*!<  18 [Active] LIN interrupt, channel #1 */
  tcpwm_interrupts_0_IRQn           =  19,      /*!<  19 [Active] TCPWM #0, Counter #0 */
  tcpwm_interrupts_1_IRQn           =  20,      /*!<  20 [Active] TCPWM #0, Counter #1 */
  tcpwm_interrupts_2_IRQn           =  21,      /*!<  21 [Active] TCPWM #0, Counter #2 */
  tcpwm_interrupts_3_IRQn           =  22,      /*!<  22 [Active] TCPWM #0, Counter #3 */
  tcpwm_interrupts_4_IRQn           =  23,      /*!<  23 [Active] TCPWM #0, Counter #4 */
  pass_0_interrupt_sar_IRQn         =  24,      /*!<  24 [Active] SAR */
  msc_0_interrupt_IRQn              =  25,      /*!<  25 [Active] CSD */
  cxpi_interrupts_0_IRQn            =  26,      /*!<  26 [Active] CXPI interrupt, channel #0 */
  cxpi_interrupts_1_IRQn            =  27,      /*!<  27 [Active] CXPI interrupt, channel #1 */
  tcpwm_interrupts_5_IRQn           =  28,      /*!<  28 [Active] TCPWM #0, Counter #5 */
  tcpwm_interrupts_6_IRQn           =  29,      /*!<  29 [Active] TCPWM #0, Counter #6 */
  tcpwm_interrupts_7_IRQn           =  30,      /*!<  30 [Active] TCPWM #0, Counter #7 */
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
#define CY_SRAM_SIZE                    0x00004000UL
#define CY_FLASH_BASE                   0x00000000UL
#define CY_FLASH_SIZE                   0x00020000UL
#define CY_SFLASH_BASE                  0x0FFFE000UL
#define CY_SFLASH_SIZE                  0x00000800UL
#define CY_ROM_BASE                     0x10000000UL
#define CY_ROM_SIZE                     0x00004000UL


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
#define CY_IP_M0S8MSCV3                 1u
#define CY_IP_M0S8MSCV3_INSTANCES       1u
#define CY_IP_M0S8MSCV3_VERSION         1u
#define CY_IP_MXCXPI                    1u
#define CY_IP_MXCXPI_INSTANCES          1u
#define CY_IP_MXCXPI_VERSION            1u
#define CY_IP_M0S8HVSS                  1u
#define CY_IP_M0S8HVSS_INSTANCES        1u
#define CY_IP_M0S8HVSS_VERSION          2u
#define CY_IP_M0S8IOSS                  1u
#define CY_IP_M0S8IOSS_INSTANCES        1u
#define CY_IP_M0S8IOSS_VERSION          1u
#define CY_IP_M0S8IOSS_SMARTIO          1u
#define CY_IP_M0S8IOSS_SMARTIO_INSTANCES 2u
#define CY_IP_M0S8IOSS_SMARTIO_VERSION  1u
#define CY_IP_MXLIN                     1u
#define CY_IP_MXLIN_INSTANCES           1u
#define CY_IP_MXLIN_VERSION             1u
#define CY_IP_M0S8LPCOMP                1u
#define CY_IP_M0S8LPCOMP_INSTANCES      1u
#define CY_IP_M0S8LPCOMP_VERSION        2u
#define CY_IP_M0S8PASS4A                1u
#define CY_IP_M0S8PASS4A_INSTANCES      1u
#define CY_IP_M0S8PASS4A_VERSION        4u
#define CY_IP_M0S8PASS4A_SAR            1u
#define CY_IP_M0S8PASS4A_SAR_INSTANCES  1u
#define CY_IP_M0S8PASS4A_SAR_VERSION    4u
#define CY_IP_M0S8PASS4A_CTB            1u
#define CY_IP_M0S8PASS4A_CTB_INSTANCES  1u
#define CY_IP_M0S8PASS4A_CTB_VERSION    4u
#define CY_IP_M0S8PERI                  1u
#define CY_IP_M0S8PERI_INSTANCES        1u
#define CY_IP_M0S8PERI_VERSION          1u
#define CY_IP_M0S8PERI_TR               1u
#define CY_IP_M0S8PERI_TR_INSTANCES     1u
#define CY_IP_M0S8PERI_TR_VERSION       1u
#define CY_IP_M0S8SCB                   1u
#define CY_IP_M0S8SCB_INSTANCES         4u
#define CY_IP_M0S8SCB_VERSION           2u
#define CY_IP_M0S8SRSSHV                1u
#define CY_IP_M0S8SRSSHV_INSTANCES      1u
#define CY_IP_M0S8SRSSHV_VERSION        1u
#define CY_IP_M0S8TCPWM                 1u
#define CY_IP_M0S8TCPWM_INSTANCES       1u
#define CY_IP_M0S8TCPWM_VERSION         2u

#define CY_DEVICE_PSOC4HVMS128K
#define CY_DEVICE_SERIES_PSOC_4_HV_MS_128K
#define CY_SILICON_ID                   0x381211C8UL
#define CY_HF_CLK_MAX_FREQ              48000000UL


#include "system_cat2.h"

#include "psoc4hvms128k_config.h"
#include "gpio_psoc4hvms128k_48_qfn.h"

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
#define PERI_TR_GROUP4                          ((PERI_TR_GROUP_Type*) &PERI->TR_GROUP[4])                        /* 0x40012800 */
#define PERI_TR_GROUP5                          ((PERI_TR_GROUP_Type*) &PERI->TR_GROUP[5])                        /* 0x40012A00 */

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
#define GPIO_PRT3                               ((GPIO_PRT_Type*) &GPIO->PRT[3])                                  /* 0x40040300 */
#define GPIO_PRT4                               ((GPIO_PRT_Type*) &GPIO->PRT[4])                                  /* 0x40040400 */
#define GPIO_PRT5                               ((GPIO_PRT_Type*) &GPIO->PRT[5])                                  /* 0x40040500 */
#define GPIO_PRT6                               ((GPIO_PRT_Type*) &GPIO->PRT[6])                                  /* 0x40040600 */
#define GPIO_PRT7                               ((GPIO_PRT_Type*) &GPIO->PRT[7])                                  /* 0x40040700 */

/*******************************************************************************
*                                    PRGIO
*******************************************************************************/

#define PRGIO_BASE                              0x40050000UL
#define PRGIO                                   ((PRGIO_Type*) PRGIO_BASE)                                        /* 0x40050000 */
#define PRGIO_PRT0                              ((PRGIO_PRT_Type*) &PRGIO->PRT[0])                                /* 0x40050000 */
#define PRGIO_PRT1                              ((PRGIO_PRT_Type*) &PRGIO->PRT[1])                                /* 0x40050100 */

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
#define TCPWM_CNT4                              ((TCPWM_CNT_Type*) &TCPWM->CNT[4])                                /* 0x40200200 */
#define TCPWM_CNT5                              ((TCPWM_CNT_Type*) &TCPWM->CNT[5])                                /* 0x40200240 */
#define TCPWM_CNT6                              ((TCPWM_CNT_Type*) &TCPWM->CNT[6])                                /* 0x40200280 */
#define TCPWM_CNT7                              ((TCPWM_CNT_Type*) &TCPWM->CNT[7])                                /* 0x402002C0 */

/*******************************************************************************
*                                     SCB
*******************************************************************************/

#define SCB0_BASE                               0x40240000UL
#define SCB1_BASE                               0x40250000UL
#define SCB2_BASE                               0x40260000UL
#define SCB3_BASE                               0x40270000UL
#define SCB0                                    ((CySCB_Type*) SCB0_BASE)                                         /* 0x40240000 */
#define SCB1                                    ((CySCB_Type*) SCB1_BASE)                                         /* 0x40250000 */
#define SCB2                                    ((CySCB_Type*) SCB2_BASE)                                         /* 0x40260000 */
#define SCB3                                    ((CySCB_Type*) SCB3_BASE)                                         /* 0x40270000 */

/*******************************************************************************
*                                     MSC
*******************************************************************************/

#define MSC0_BASE                               0x40290000UL
#define MSC0                                    ((MSC_Type*) MSC0_BASE)                                           /* 0x40290000 */
#define MSC0_MODE0                              ((MSC_MODE_Type*) &MSC0->MODE[0])                                 /* 0x40290500 */
#define MSC0_MODE1                              ((MSC_MODE_Type*) &MSC0->MODE[1])                                 /* 0x40290520 */
#define MSC0_MODE2                              ((MSC_MODE_Type*) &MSC0->MODE[2])                                 /* 0x40290540 */

/*******************************************************************************
*                                    LPCOMP
*******************************************************************************/

#define LPCOMP_BASE                             0x402B0000UL
#define LPCOMP                                  ((LPCOMP_Type*) LPCOMP_BASE)                                      /* 0x402B0000 */

/*******************************************************************************
*                                     LIN
*******************************************************************************/

#define LIN0_BASE                               0x402D0000UL
#define LIN0                                    ((LIN_Type*) LIN0_BASE)                                           /* 0x402D0000 */
#define LIN0_CH0                                ((LIN_CH_Type*) &LIN0->CH[0])                                     /* 0x402D8000 */
#define LIN0_CH1                                ((LIN_CH_Type*) &LIN0->CH[1])                                     /* 0x402D8100 */

/*******************************************************************************
*                                     CXPI
*******************************************************************************/

#define CXPI0_BASE                              0x402E0000UL
#define CXPI0                                   ((CXPI_Type*) CXPI0_BASE)                                         /* 0x402E0000 */
#define CXPI0_CH0                               ((CXPI_CH_Type*) &CXPI0->CH[0])                                   /* 0x402E8000 */
#define CXPI0_CH1                               ((CXPI_CH_Type*) &CXPI0->CH[1])                                   /* 0x402E8100 */

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

/** \} CY8C4147LDE-HVS034 */

#endif /* _CY8C4147LDE_HVS034_H_ */


/* [] END OF FILE */
