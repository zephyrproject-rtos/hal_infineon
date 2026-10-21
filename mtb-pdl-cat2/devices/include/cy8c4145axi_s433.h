/***************************************************************************//**
* \file cy8c4145axi_s433.h
*
* \brief
* CY8C4145AXI-S433 device header
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

#ifndef _CY8C4145AXI_S433_H_
#define _CY8C4145AXI_S433_H_

/**
* \addtogroup group_device CY8C4145AXI-S433
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
  /* CY8C4145AXI-S433 Peripheral Interrupt Numbers */
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
  pass_0_interrupt_ctbs_IRQn        =  10,      /*!<  10 [DeepSleep] CTBm Interrupt (all CTBms) */
  wco_interrupt_IRQn                =  11,      /*!<  11 [DeepSleep] WCO WDT Interrupt */
  cpuss_interrupt_spcif_IRQn        =  12,      /*!<  12 [Active] SPCIF interrupt */
  csd_interrupt_IRQn                =  13,      /*!<  13 [Active] CSD #0 (Primarily Capsense) */
  tcpwm_interrupts_0_IRQn           =  14,      /*!<  14 [Active] TCPWM #0, Counter #0 */
  tcpwm_interrupts_1_IRQn           =  15,      /*!<  15 [Active] TCPWM #0, Counter #1 */
  tcpwm_interrupts_2_IRQn           =  16,      /*!<  16 [Active] TCPWM #0, Counter #2 */
  tcpwm_interrupts_3_IRQn           =  17,      /*!<  17 [Active] TCPWM #0, Counter #3 */
  tcpwm_interrupts_4_IRQn           =  18,      /*!<  18 [Active] TCPWM #0, Counter #4 */
  pass_0_interrupt_sar_IRQn         =  19,      /*!<  19 [Active] SAR */
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
#define CY_FLASH_SIZE                   0x00008000UL
#define CY_SFLASH_BASE                  0x0FFFF000UL
#define CY_SFLASH_SIZE                  0x00000400UL
#define CY_ROM_BASE                     0x10000000UL
#define CY_ROM_SIZE                     0x00002000UL


/* IP List */
#define CY_IP_ARMCM0P                   1u
#define CY_IP_ARMCM0P_INSTANCES         0u
#define CY_IP_ARMCM0P_VERSION           1u
#define CY_IP_M0S8CPUSSV3               1u
#define CY_IP_M0S8CPUSSV3_INSTANCES     1u
#define CY_IP_M0S8CPUSSV3_VERSION       3u
#define CY_IP_M0S8CSDV2                 1u
#define CY_IP_M0S8CSDV2_INSTANCES       1u
#define CY_IP_M0S8CSDV2_VERSION         1u
#define CY_IP_M0S8IOSS                  1u
#define CY_IP_M0S8IOSS_INSTANCES        1u
#define CY_IP_M0S8IOSS_VERSION          1u
#define CY_IP_M0S8IOSS_SMARTIO          1u
#define CY_IP_M0S8IOSS_SMARTIO_INSTANCES 2u
#define CY_IP_M0S8IOSS_SMARTIO_VERSION  1u
#define CY_IP_M0S8LCD                   1u
#define CY_IP_M0S8LCD_INSTANCES         1u
#define CY_IP_M0S8LCD_VERSION           2u
#define CY_IP_M0S8LPCOMP                1u
#define CY_IP_M0S8LPCOMP_INSTANCES      1u
#define CY_IP_M0S8LPCOMP_VERSION        2u
#define CY_IP_M0S8PASS4A                1u
#define CY_IP_M0S8PASS4A_INSTANCES      1u
#define CY_IP_M0S8PASS4A_VERSION        1u
#define CY_IP_M0S8PASS4A_SAR            1u
#define CY_IP_M0S8PASS4A_SAR_INSTANCES  1u
#define CY_IP_M0S8PASS4A_SAR_VERSION    1u
#define CY_IP_M0S8PASS4A_CTB            1u
#define CY_IP_M0S8PASS4A_CTB_INSTANCES  1u
#define CY_IP_M0S8PASS4A_CTB_VERSION    1u
#define CY_IP_M0S8PERI                  1u
#define CY_IP_M0S8PERI_INSTANCES        1u
#define CY_IP_M0S8PERI_VERSION          1u
#define CY_IP_M0S8PERI_TR               1u
#define CY_IP_M0S8PERI_TR_INSTANCES     1u
#define CY_IP_M0S8PERI_TR_VERSION       1u
#define CY_IP_M0S8SCB                   1u
#define CY_IP_M0S8SCB_INSTANCES         2u
#define CY_IP_M0S8SCB_VERSION           2u
#define CY_IP_S8SRSSLT                  1u
#define CY_IP_S8SRSSLT_INSTANCES        1u
#define CY_IP_S8SRSSLT_VERSION          1u
#define CY_IP_M0S8TCPWM                 1u
#define CY_IP_M0S8TCPWM_INSTANCES       1u
#define CY_IP_M0S8TCPWM_VERSION         2u
#define CY_IP_M0S8WCO                   1u
#define CY_IP_M0S8WCO_INSTANCES         1u
#define CY_IP_M0S8WCO_VERSION           1u

#define CY_DEVICE_PSOC4AS2
#define CY_DEVICE_SERIES_PSOC_4100S
#define CY_SILICON_ID                   0x1B2311ABUL
#define CY_HF_CLK_MAX_FREQ              48000000UL


#include "system_cat2.h"

#include "psoc4100s_config.h"
#include "gpio_psoc4100s_44_tqfp.h"

/*******************************************************************************
*                                    SFLASH
*******************************************************************************/

#define SFLASH_BASE                             0x0FFFF000UL
#define SFLASH                                  ((SFLASH_Type*) SFLASH_BASE)                                      /* 0x0FFFF000 */

/*******************************************************************************
*                                     PERI
*******************************************************************************/

#define PERI_BASE                               0x40010000UL
#define PERI                                    ((PERI_Type*) PERI_BASE)                                          /* 0x40010000 */
#define PERI_TR_GROUP0                          ((PERI_TR_GROUP_Type*) &PERI->TR_GROUP[0])                        /* 0x40012000 */
#define PERI_TR_GROUP1                          ((PERI_TR_GROUP_Type*) &PERI->TR_GROUP[1])                        /* 0x40012200 */

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

/*******************************************************************************
*                                    PRGIO
*******************************************************************************/

#define PRGIO_BASE                              0x40050000UL
#define PRGIO                                   ((PRGIO_Type*) PRGIO_BASE)                                        /* 0x40050000 */
#define PRGIO_PRT0                              ((PRGIO_PRT_Type*) &PRGIO->PRT[0])                                /* 0x40050000 */
#define PRGIO_PRT1                              ((PRGIO_PRT_Type*) &PRGIO->PRT[1])                                /* 0x40050100 */

/*******************************************************************************
*                                    TCPWM
*******************************************************************************/

#define TCPWM_BASE                              0x40060000UL
#define TCPWM                                   ((TCPWM_Type*) TCPWM_BASE)                                        /* 0x40060000 */
#define TCPWM_CNT0                              ((TCPWM_CNT_Type*) &TCPWM->CNT[0])                                /* 0x40060100 */
#define TCPWM_CNT1                              ((TCPWM_CNT_Type*) &TCPWM->CNT[1])                                /* 0x40060140 */
#define TCPWM_CNT2                              ((TCPWM_CNT_Type*) &TCPWM->CNT[2])                                /* 0x40060180 */
#define TCPWM_CNT3                              ((TCPWM_CNT_Type*) &TCPWM->CNT[3])                                /* 0x400601C0 */
#define TCPWM_CNT4                              ((TCPWM_CNT_Type*) &TCPWM->CNT[4])                                /* 0x40060200 */

/*******************************************************************************
*                                     WCO
*******************************************************************************/

#define WCO_BASE                                0x40070000UL
#define WCO                                     ((WCO_Type*) WCO_BASE)                                            /* 0x40070000 */

/*******************************************************************************
*                                     SCB
*******************************************************************************/

#define SCB1_BASE                               0x40090000UL
#define SCB2_BASE                               0x400A0000UL
#define SCB1                                    ((CySCB_Type*) SCB1_BASE)                                         /* 0x40090000 */
#define SCB2                                    ((CySCB_Type*) SCB2_BASE)                                         /* 0x400A0000 */

/*******************************************************************************
*                                     LCD
*******************************************************************************/

#define LCD_BASE                                0x400B0000UL
#define LCD                                     ((LCD_Type*) LCD_BASE)                                            /* 0x400B0000 */

/*******************************************************************************
*                                     CSD
*******************************************************************************/

#define CSD0_BASE                               0x400C0000UL
#define CSD0                                    ((CSD_Type*) CSD0_BASE)                                           /* 0x400C0000 */

/*******************************************************************************
*                                    LPCOMP
*******************************************************************************/

#define LPCOMP_BASE                             0x400D0000UL
#define LPCOMP                                  ((LPCOMP_Type*) LPCOMP_BASE)                                      /* 0x400D0000 */

/*******************************************************************************
*                                    CPUSS
*******************************************************************************/

#define CPUSS_BASE                              0x40100000UL
#define CPUSS                                   ((CPUSS_Type*) CPUSS_BASE)                                        /* 0x40100000 */

/*******************************************************************************
*                                    SPCIF
*******************************************************************************/

#define SPCIF_BASE                              0x40110000UL
#define SPCIF                                   ((SPCIF_Type*) SPCIF_BASE)                                        /* 0x40110000 */

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

/** \} CY8C4145AXI-S433 */

#endif /* _CY8C4145AXI_S433_H_ */


/* [] END OF FILE */
