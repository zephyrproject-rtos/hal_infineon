/***************************************************************************//**
* \file cy_usbpd_hpd.h
* \version 2.110
*
* Provides API declarations of the USBPD Hot-Plug Detect driver.
*
********************************************************************************
* \copyright
* (c) (2022 - 2025), Cypress Semiconductor Corporation (an Infineon company) or
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

#ifndef _CY_USBPD_HPD_H_
#define _CY_USBPD_HPD_H_

#include "cy_device.h"
#include "cy_device_headers.h"
#include "cy_usbpd_common.h"

/**
* \addtogroup group_usbpd_hpd
* \{
* USBPD Hot-Plug Detect driver.
*
* \defgroup group_usbpd_hpd_macros Macros
* \defgroup group_usbpd_hpd_functions Functions
*/

#if (defined(CY_IP_MXUSBPD) || defined(CY_IP_M0S8USBPD))

/*******************************************************************************
 * MACRO Definition
 ******************************************************************************/

/**
* \addtogroup group_usbpd_hpd_macros
* \{
*/

/** HPD Input direction is used when sensing HPD output from a monitor. This is used in applications
     like video dongles and monitors. */
#define HPD_IP_DIRECTION                        (0)

/** HPD Output direction is used when driving HPD output to a DP source. This is used in applications
     like PD port controllers in PC/Mobile platforms. */
#define HPD_OP_DIRECTION                        (PDSS_CTRL_HPD_DIRECTION)

/** HPD HW register event mask. */
#define HPD_EVENT_MASK                          (3u)
/** HPD Event 0 bit position. */
#define HPD_EVENT_0_POS                         (0)
/** HPD Event 1 bit position. */
#define HPD_EVENT_1_POS                         (2)
/** HPD Event 2 bit position. */
#define HPD_EVENT_2_POS                         (4)
/** HPD Event 3 bit position. */
#define HPD_EVENT_3_POS                         (6)

/** Get the first HPD event from queue status. */
#define HPD_GET_EVENT_0(hpd_queue)              (((hpd_queue) >> HPD_EVENT_0_POS) & HPD_EVENT_MASK)

/** Get the second HPD event from queue status. */
#define HPD_GET_EVENT_1(hpd_queue)              (((hpd_queue) >> HPD_EVENT_1_POS) & HPD_EVENT_MASK)

/** Get the third HPD event from queue status. */
#define HPD_GET_EVENT_2(hpd_queue)              (((hpd_queue) >> HPD_EVENT_2_POS) & HPD_EVENT_MASK)

/** Get the fourth HPD event from queue status. */
#define HPD_GET_EVENT_3(hpd_queue)              (((hpd_queue) >> HPD_EVENT_3_POS) & HPD_EVENT_MASK)

/** \cond DOXYGEN_HIDE */
#if (defined (CY_DEVICE_CCG3))
#define HPD_P0_PORT_PIN                         0x33U    /* GPIO_PORT3_PIN_3 */
#define HPD_P1_PORT_PIN                         0x33U    /* GPIO_PORT3_PIN_3 */
#define HPD_P0_PORT                             (3U)
#define HPD_P1_PORT                             (3U)
#define HPD_P0_PIN                              (3U)
#define HPD_P1_PIN                              (3U)
#define HPD_HSIOM_SETTING_P0                    (12U)
#define HPD_HSIOM_SETTING_P1                    (12U)

#elif (defined(CY_DEVICE_CCG6))
#define HPD_P0_PORT_PIN                         0x30U    /* GPIO_PORT3_PIN_0 */
#define HPD_P1_PORT_PIN                         0x34U    /* GPIO_PORT3_PIN_4 */
#define HPD_P0_PORT                             (3U)
#define HPD_P1_PORT                             (3U)
#define HPD_P0_PIN                              (0U)
#define HPD_P1_PIN                              (4U)
#define HPD_HSIOM_SETTING_P0                    (12U)
#define HPD_HSIOM_SETTING_P1                    (12U)

#elif (defined(CY_DEVICE_CCG3PA))
/* HPD not supported in CCG3PA. Loading dummy values. */
#define HPD_P0_PORT_PIN                         (0U)
#define HPD_P1_PORT_PIN                         (1U)
#define HPD_P0_PORT                             (3U)
#define HPD_P1_PORT                             (3U)
#define HPD_P0_PIN                              (3U)
#define HPD_P1_PIN                              (3U)
#define HPD_HSIOM_SETTING_P0                    (12U)
#define HPD_HSIOM_SETTING_P1                    (12U)

#elif (defined(CY_DEVICE_PMG1S3))
#define HPD_P0_PORT_PIN                         0x14U    /* GPIO_PORT_1_PIN_4 */
#define HPD_P1_PORT_PIN                         0x71U    /* GPIO_PORT_7_PIN_1 */
#define HPD_P0_PORT                             (1U)
#define HPD_P1_PORT                             (7U)
#define HPD_P0_PIN                              (4U)
#define HPD_P1_PIN                              (1U)
#define HPD_HSIOM_SETTING_P0                    (13U)
#define HPD_HSIOM_SETTING_P1                    (13U)

#elif (defined(CY_DEVICE_CCG6DF_CFP))
#define HPD_P0_PORT_PIN                         0x50U    /* GPIO_PORT_5_PIN_0 */
#define HPD_P1_PORT_PIN                         0x51U    /* GPIO_PORT_5_PIN_1 */
#define HPD_P0_PORT                             (5U)
#define HPD_P1_PORT                             (5U)
#define HPD_P0_PIN                              (0U)
#define HPD_P1_PIN                              (1U)
#define HPD_HSIOM_SETTING_P0                    (13U)
#define HPD_HSIOM_SETTING_P1                    (15U)

#elif (defined(CY_DEVICE_CCG7D))
#define HPD_P0_PORT_PIN                         (0x00U)    /* GPIO_PORT_0_PIN_0 */
#define HPD_P1_PORT_PIN                         (0x16U)    /* GPIO_PORT_1_PIN_6 */
#define HPD_P0_PORT                             (0U)
#define HPD_P1_PORT                             (1U)
#define HPD_P0_PIN                              (0U)
#define HPD_P1_PIN                              (6U)
#define HPD_HSIOM_SETTING_P0                    (13U)
#define HPD_HSIOM_SETTING_P1                    (13U)

#elif (defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
#define HPD_P0_PORT_PIN                         (0x03U)    /* GPIO_PORT_0_PIN_3 */
#define HPD_P1_PORT_PIN                         (0x03U)    /* GPIO_PORT_0_PIN_3 */
#define HPD_P0_PORT                             (0U)
#define HPD_P1_PORT                             (0U)
#define HPD_P0_PIN                              (3U)
#define HPD_P1_PIN                              (3U)
#define HPD_HSIOM_SETTING_P0                    (13U)
#define HPD_HSIOM_SETTING_P1                    (13U)

#else
#error "Device not supported."
#endif
/** \endcond */

/** This is the default value to be used for HPD_CTRL1 register.
 * This value translates to:
 * 0x096: IRQ MIN time (0.25 ms)
 * 0x500: IRQ MAX time (2.2 ms)
 * 0: FLUSH_QUEUE
 * 0: LOOPBACK_EN
 * 1: RESET_HPD_STATE
 */
#define PDSS_HPD_CTRL1_DEFAULT_VALUE            (0x80530096UL)

/** This is the default value to be used for HPD_CTRL3 register.
 * This value translates to:
 * STABLE_HIGH = 0x4B (2 ms)
 * STABLE_LOW  = 0x53 (2.213 ms)
 */
#define PDSS_HPD_CTRL3_DEFAULT_VALUE            (0x0005304BUL)

/** This is the default value to be used for HPDT_CTRL2 register. This change is brought in
 * to meet the timings mentioned in the display port specification.
 * This value translates to:
 * SET_LOW_DELAY = 0x530 (2.21 ms)
 * SET_HIGH_DELAY  = 0x7bc (3.3 ms)
 * DEFAULT_OE = 1
 */
#define PDSS_HPDT_CTRL2_DEFAULT_VALUE           (0x017BC530UL)


/** \} group_usbpd_hpd_macros */

/*******************************************************************************
*                            Enumerated Types
*******************************************************************************/

/*******************************************************************************
*                              Type Definitions
*******************************************************************************/

/*******************************************************************************
*                            Function Prototypes
*******************************************************************************/

/**
* \addtogroup group_usbpd_hpd_functions
* \{
*/

cy_en_usbpd_status_t Cy_USBPD_Hpd_ReceiveInit(cy_stc_usbpd_context_t *context, 
                                              cy_cb_usbpd_hpd_events_t cbk);

cy_en_usbpd_status_t Cy_USBPD_Hpd_TransmitInit(cy_stc_usbpd_context_t *context, 
                                               cy_cb_usbpd_hpd_events_t cbk);

void Cy_USBPD_Hpd_SleepEntry(cy_stc_usbpd_context_t *context);

void Cy_USBPD_Hpd_Wakeup(cy_stc_usbpd_context_t *context, bool value);

bool Cy_USBPD_Hpd_ReceiveGetStatus(cy_stc_usbpd_context_t *context);

void Cy_USBPD_Hpd_RxSleepEntry(cy_stc_usbpd_context_t *context, bool hpdState);

void Cy_USBPD_Hpd_RxWakeup(cy_stc_usbpd_context_t *context);

cy_en_usbpd_status_t Cy_USBPD_Hpd_Deinit(cy_stc_usbpd_context_t *context);

bool Cy_USBPD_Hpdt_IsCommandActive(cy_stc_usbpd_context_t *context);

cy_en_usbpd_status_t Cy_USBPD_Hpd_TransmitSendevt(cy_stc_usbpd_context_t *context,
                                                  cy_en_usbpd_hpd_events_t evtype);

void Cy_USBPD_Hpd_Intr0Handler(cy_stc_usbpd_context_t *context) ; 

void Cy_USBPD_Hpd_Intr1Handler(cy_stc_usbpd_context_t *context);

/** \} group_usbpd_hpd_functions */

#endif /* (defined(CY_IP_MXUSBPD) || defined(CY_IP_M0S8USBPD)) */

#endif /* _CY_USBPD_HPD_H_ */

/** \} group_usbpd_hpd */

/* [] END OF FILE */
