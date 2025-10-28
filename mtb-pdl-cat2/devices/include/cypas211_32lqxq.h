/***************************************************************************//**
* \file cypas211_32lqxq.h
*
* \brief
* CYPAS211-32LQXQ device header
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

#ifndef _CYPAS211_32LQXQ_H_
#define _CYPAS211_32LQXQ_H_

/**
* \addtogroup group_device CYPAS211-32LQXQ
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
  /* CYPAS211-32LQXQ Peripheral Interrupt Numbers */
  srss_interrupt_srss_IRQn          =   0,      /*!<   0 [DeepSleep] SRSS interrupts */
  srss_wdt_irq_IRQn                 =   1,      /*!<   1 [DeepSleep] WDT Interrupt */
  ioss_interrupt_gpio_IRQn          =   2,      /*!<   2 [DeepSleep] GPIO consolidated interrupt */
  ioss_interrupts_gpio_0_IRQn       =   3,      /*!<   3 [DeepSleep] GPIO P0 */
  ioss_interrupts_gpio_1_IRQn       =   4,      /*!<   4 [DeepSleep] GPIO P1 */
  usbpd_0_interrupt_wakeup_IRQn     =   5,      /*!<   5 [DeepSleep] Ganged USBPD Interrupt */
  cpuss_interrupt_spcif_IRQn        =   6,      /*!<   6 [Active] SPCIF interrupt */
  cpuss_interrupt_fault_0_IRQn      =   7,      /*!<   7 [Active] Fault structure 0 interrupt */
  cpuss_interrupt_fault_1_IRQn      =   8,      /*!<   8 [Active] Fault structure 1 interrupt */
  usbpd_0_interrupt_IRQn            =   9,      /*!<   9 [Active] Synchronous USBPD Interrupts */
  tcpwm_interrupts_0_IRQn           =  10,      /*!<  10 [Active] TCPWM counter #0 */
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
#define CY_SRAM_SIZE                    0x00002000UL
#define CY_FLASH_BASE                   0x00000000UL
#define CY_FLASH_SIZE                   0x00010000UL
#define CY_SFLASH_BASE                  0x0FFFE000UL
#define CY_SFLASH_SIZE                  0x00000400UL
#define CY_ROM_BASE                     0x10000000UL
#define CY_ROM_SIZE                     0x00010000UL


/* IP List */
#define CY_IP_ARMCM0P                   1u
#define CY_IP_ARMCM0P_INSTANCES         0u
#define CY_IP_ARMCM0P_VERSION           1u
#define CY_IP_M0S8CPUSSV3               1u
#define CY_IP_M0S8CPUSSV3_INSTANCES     1u
#define CY_IP_M0S8CPUSSV3_VERSION       3u
#define CY_IP_M0S8IOSS                  1u
#define CY_IP_M0S8IOSS_INSTANCES        1u
#define CY_IP_M0S8IOSS_VERSION          1u
#define CY_IP_M0S8PERI                  1u
#define CY_IP_M0S8PERI_INSTANCES        1u
#define CY_IP_M0S8PERI_VERSION          1u
#define CY_IP_M0S8SRSSHV                1u
#define CY_IP_M0S8SRSSHV_INSTANCES      1u
#define CY_IP_M0S8SRSSHV_VERSION        1u
#define CY_IP_M0S8TCPWM                 1u
#define CY_IP_M0S8TCPWM_INSTANCES       1u
#define CY_IP_M0S8TCPWM_VERSION         2u
#define CY_IP_MXUSBPD                   1u
#define CY_IP_MXUSBPD_INSTANCES         1u
#define CY_IP_MXUSBPD_VERSION           1u

#define CY_DEVICE_PAG2S
#define CY_DEVICE_SERIES_PAG2S
#define CY_SILICON_ID                   0x3B1011CBUL
#define CY_HF_CLK_MAX_FREQ              48000000UL


#include "system_cat2.h"

#include "pag2s_config.h"
#include "gpio_pag2s_32_qfn.h"

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

/*******************************************************************************
*                                    HSIOM
*******************************************************************************/

#define HSIOM_BASE                              0x40020000UL
#define HSIOM                                   ((HSIOM_Type*) HSIOM_BASE)                                        /* 0x40020000 */
#define HSIOM_PRT0                              ((HSIOM_PRT_Type*) &HSIOM->PRT[0])                                /* 0x40020000 */
#define HSIOM_PRT1                              ((HSIOM_PRT_Type*) &HSIOM->PRT[1])                                /* 0x40020100 */

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

/*******************************************************************************
*                                    TCPWM
*******************************************************************************/

#define TCPWM_BASE                              0x40090000UL
#define TCPWM                                   ((TCPWM_Type*) TCPWM_BASE)                                        /* 0x40090000 */
#define TCPWM_CNT0                              ((TCPWM_CNT_Type*) &TCPWM->CNT[0])                                /* 0x40090100 */

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
*                                    FAULT
*******************************************************************************/

#define FAULT_BASE                              0x40130000UL
#define FAULT                                   ((FAULT_Type*) FAULT_BASE)                                        /* 0x40130000 */
#define FAULT_STRUCT0                           ((FAULT_STRUCT_Type*) &FAULT->STRUCT[0])                          /* 0x40130000 */
#define FAULT_STRUCT1                           ((FAULT_STRUCT_Type*) &FAULT->STRUCT[1])                          /* 0x40130100 */

/** \} CYPAS211-32LQXQ */

#endif /* _CYPAS211_32LQXQ_H_ */


/* [] END OF FILE */
