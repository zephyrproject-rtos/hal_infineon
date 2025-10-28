/***************************************************************************//**
* \file wlc1250_68lqxq.h
*
* \brief
* WLC1250-68LQXQ device header
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

#ifndef _WLC1250_68LQXQ_H_
#define _WLC1250_68LQXQ_H_

/**
* \addtogroup group_device WLC1250-68LQXQ
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
  /* ARM Cortex-M0 Core Interrupt Numbers */
  Reset_IRQn                        = -15,      /*!< -15 Reset Vector, invoked on Power up and warm reset */
  NonMaskableInt_IRQn               = -14,      /*!< -14 Non maskable Interrupt, cannot be stopped or preempted */
  HardFault_IRQn                    = -13,      /*!< -13 Hard Fault, all classes of Fault */
  SVCall_IRQn                       =  -5,      /*!<  -5 System Service Call via SVC instruction */
  PendSV_IRQn                       =  -2,      /*!<  -2 Pendable request for system service */
  SysTick_IRQn                      =  -1,      /*!<  -1 System Tick Timer */
  /* WLC1250-68LQXQ Peripheral Interrupt Numbers */
  ioss_interrupts_gpio_0_IRQn       =   0,      /*!<   0 [DeepSleep] GPIO P0 */
  ioss_interrupts_gpio_1_IRQn       =   1,      /*!<   1 [DeepSleep] GPIO P1 */
  ioss_interrupts_gpio_2_IRQn       =   2,      /*!<   2 [DeepSleep] GPIO P2 */
  ioss_interrupts_gpio_3_IRQn       =   3,      /*!<   3 [DeepSleep] GPIO P3 */
  ioss_interrupt_gpio_IRQn          =   4,      /*!<   4 [DeepSleep] GPIO All ports */
  usbpd_0_interrupt_wakeup_IRQn     =   5,      /*!<   5 [DeepSleep] Ganged USBPD[0] Interrupt */
  usbpd_1_interrupt_wakeup_IRQn     =   6,      /*!<   6 [DeepSleep] Ganged USBPD[1] Interrupt */
  srss_interrupt_wdt_IRQn           =   7,      /*!<   7 [DeepSleep] WDT or Temp (WDT only in DeepSleep) */
  scb_0_interrupt_IRQn              =   8,      /*!<   8 [DeepSleep] SCB[0] */
  scb_1_interrupt_IRQn              =   9,      /*!<   9 [DeepSleep] SCB[1] */
  scb_2_interrupt_IRQn              =  10,      /*!<  10 [DeepSleep] SCB[2] */
  scb_3_interrupt_IRQn              =  11,      /*!<  11 [DeepSleep] SCB[3] */
  cpuss_interrupt_spcif_IRQn        =  12,      /*!<  12 [Active] SPC */
  usbpd_0_interrupt_IRQn            =  13,      /*!<  13 [Active] Synchronous USBPD[0] Interrupts */
  usbpd_1_interrupt_IRQn            =  14,      /*!<  14 [Active] Synchronous USBPD[1] Interrupts */
  tcpwm_interrupts_0_IRQn           =  15,      /*!<  15 [Active] TCPWM counter #0 */
  tcpwm_interrupts_1_IRQn           =  16,      /*!<  16 [Active] TCPWM counter #1 */
  tcpwm_interrupts_2_IRQn           =  17,      /*!<  17 [Active] TCPWM counter #2 */
  tcpwm_interrupts_3_IRQn           =  18,      /*!<  18 [Active] TCPWM counter #3 */
  crypto_interrupt_IRQn             =  19,      /*!<  19 [Active] Crypto block */
  unconnected_IRQn                  = 240       /*!< 240 Unconnected */
} IRQn_Type;


/*******************************************************************************
*                    Processor and Core Peripheral Section
*******************************************************************************/

/* Configuration of the ARM Cortex-M0 Processor and Core Peripherals */
#define __CM0_REV                       0x0000U /*!< CM0 Core Revision */
#define __NVIC_PRIO_BITS                2       /*!< Number of Bits used for Priority Levels */
#define __Vendor_SysTickConfig          0       /*!< Set to 1 if different SysTick Config is used */
#define __VTOR_PRESENT                  0       /*!< Set to 1 if CPU supports Vector Table Offset Register */
#define __MPU_PRESENT                   0       /*!< MPU present or not */

/** \} Configuration_of_CMSIS */

#include "core_cm0.h"                           /*!< ARM Cortex-M0 processor and core peripherals */


/* Memory Blocks */
#define CY_SRAM_BASE                    0x20000000UL
#define CY_SRAM_SIZE                    0x00004000UL
#define CY_FLASH_BASE                   0x00000000UL
#define CY_FLASH_SIZE                   0x00020000UL
#define CY_SFLASH_BASE                  0x0FFFF000UL
#define CY_SFLASH_SIZE                  0x00000800UL
#define CY_ROM_BASE                     0x10000000UL
#define CY_ROM_SIZE                     0x00008000UL


/* IP List */
#define CY_IP_ARMCM0                    1u
#define CY_IP_ARMCM0_INSTANCES          0u
#define CY_IP_ARMCM0_VERSION            1u
#define CY_IP_M0S8CPUSSV3               1u
#define CY_IP_M0S8CPUSSV3_INSTANCES     1u
#define CY_IP_M0S8CPUSSV3_VERSION       3u
#define CY_IP_M0S8CRYPTO                1u
#define CY_IP_M0S8CRYPTO_INSTANCES      1u
#define CY_IP_M0S8CRYPTO_VERSION        2u
#define CY_IP_M0S8IOSS                  1u
#define CY_IP_M0S8IOSS_INSTANCES        1u
#define CY_IP_M0S8IOSS_VERSION          1u
#define CY_IP_M0S8PERI                  1u
#define CY_IP_M0S8PERI_INSTANCES        1u
#define CY_IP_M0S8PERI_VERSION          1u
#define CY_IP_M0S8SCB                   1u
#define CY_IP_M0S8SCB_INSTANCES         4u
#define CY_IP_M0S8SCB_VERSION           2u
#define CY_IP_S8SRSSLT                  1u
#define CY_IP_S8SRSSLT_INSTANCES        1u
#define CY_IP_S8SRSSLT_VERSION          1u
#define CY_IP_M0S8TCPWM                 1u
#define CY_IP_M0S8TCPWM_INSTANCES       1u
#define CY_IP_M0S8TCPWM_VERSION         2u
#define CY_IP_MXUSBPD                   1u
#define CY_IP_MXUSBPD_INSTANCES         2u
#define CY_IP_MXUSBPD_VERSION           1u

#define CY_DEVICE_CCG7D
#define CY_DEVICE_SERIES_WLC1
#define CY_SILICON_ID                   0x31C011C1UL
#define CY_HF_CLK_MAX_FREQ              48000000UL


#include "system_cat2.h"

#include "ccg7d_config.h"
#include "gpio_ccg7d_68_qfn_wlc_50w_rx.h"

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

/*******************************************************************************
*                                    HSIOM
*******************************************************************************/

#define HSIOM_BASE                              0x40020000UL
#define HSIOM                                   ((HSIOM_Type*) HSIOM_BASE)                                        /* 0x40020000 */
#define HSIOM_PRT0                              ((HSIOM_PRT_Type*) &HSIOM->PRT[0])                                /* 0x40020000 */
#define HSIOM_PRT1                              ((HSIOM_PRT_Type*) &HSIOM->PRT[1])                                /* 0x40020100 */
#define HSIOM_PRT2                              ((HSIOM_PRT_Type*) &HSIOM->PRT[2])                                /* 0x40020200 */
#define HSIOM_PRT3                              ((HSIOM_PRT_Type*) &HSIOM->PRT[3])                                /* 0x40020300 */

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

/*******************************************************************************
*                                     SCB
*******************************************************************************/

#define SCB0_BASE                               0x40050000UL
#define SCB1_BASE                               0x40060000UL
#define SCB2_BASE                               0x40070000UL
#define SCB3_BASE                               0x40080000UL
#define SCB0                                    ((CySCB_Type*) SCB0_BASE)                                         /* 0x40050000 */
#define SCB1                                    ((CySCB_Type*) SCB1_BASE)                                         /* 0x40060000 */
#define SCB2                                    ((CySCB_Type*) SCB2_BASE)                                         /* 0x40070000 */
#define SCB3                                    ((CySCB_Type*) SCB3_BASE)                                         /* 0x40080000 */

/*******************************************************************************
*                                    TCPWM
*******************************************************************************/

#define TCPWM_BASE                              0x40090000UL
#define TCPWM                                   ((TCPWM_Type*) TCPWM_BASE)                                        /* 0x40090000 */
#define TCPWM_CNT0                              ((TCPWM_CNT_Type*) &TCPWM->CNT[0])                                /* 0x40090100 */
#define TCPWM_CNT1                              ((TCPWM_CNT_Type*) &TCPWM->CNT[1])                                /* 0x40090140 */
#define TCPWM_CNT2                              ((TCPWM_CNT_Type*) &TCPWM->CNT[2])                                /* 0x40090180 */
#define TCPWM_CNT3                              ((TCPWM_CNT_Type*) &TCPWM->CNT[3])                                /* 0x400901C0 */

/*******************************************************************************
*                                    CRYPTO
*******************************************************************************/

#define CRYPTO_BASE                             0x400C0000UL
#define CRYPTO                                  ((CRYPTO_Type*) CRYPTO_BASE)                                      /* 0x400C0000 */

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

/** \} WLC1250-68LQXQ */

#endif /* _WLC1250_68LQXQ_H_ */


/* [] END OF FILE */
