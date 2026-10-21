/***********************************************************************************************//**
 * \file cyabs_rtos_impl_cat5.h
 *
 * \brief
 * Internal definitions for RTOS abstraction layer specific to CAT5.
 ***************************************************************************************************
 * \copyright
 * Copyright 2018-2022 Cypress Semiconductor Corporation (an Infineon company) or
 * an affiliate of Cypress Semiconductor Corporation
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
 **************************************************************************************************/

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include "tx_api.h"
#include "cyhal_system.h"


/******************************************************
*                 Type Definitions
******************************************************/
#if defined (CYW55500A0)
// RTOS thread priority. Main thread priority is 24.
typedef enum
{
    CY_RTOS_PRIORITY_MIN         = 0,   /**< Minimum allowable Thread priority */
    CY_RTOS_PRIORITY_LOW         = 1,   /**< A low priority Thread */
    CY_RTOS_PRIORITY_BELOWNORMAL = 2,   /**< A slightly below normal Thread priority */
    CY_RTOS_PRIORITY_NORMAL      = 3,   /**< The normal Thread priority */
    CY_RTOS_PRIORITY_ABOVENORMAL = 4,   /**< A slightly elevated Thread priority */
    CY_RTOS_PRIORITY_HIGH        = 5,   /**< A high priority Thread */
    CY_RTOS_PRIORITY_REALTIME    = 6,   /**< Realtime Thread priority */
    CY_RTOS_PRIORITY_MAX         = 7    /**< Maximum allowable Thread priority */
} cy_thread_priority_t;
#else // if defined (CYW55500A0)
#if defined (CYW55500A1) //Main thread priority is 24.Range from 24-31
#define MULTIPLY_FACTOR     (1U)
#else
#define MULTIPLY_FACTOR     (3U) //Main thread priority is 10.Range from 10-31
#endif
// RTOS thread priority.
typedef enum
{
    CY_RTOS_PRIORITY_MIN         = (TX_MAX_PRIORITIES-1),                           /**< Minimum
                                                                                       allowable
                                                                                       Thread
                                                                                        priority */
    CY_RTOS_PRIORITY_LOW         = ((TX_MAX_PRIORITIES-1) - (MULTIPLY_FACTOR*1)),   /**< A low
                                                                                       priority
                                                                                       Thread */
    CY_RTOS_PRIORITY_BELOWNORMAL = ((TX_MAX_PRIORITIES-1) - (MULTIPLY_FACTOR*2)),   /**< A slightly
                                                                                       below normal
                                                                                        Thread
                                                                                           priority
                                                                                     */
    CY_RTOS_PRIORITY_NORMAL      = ((TX_MAX_PRIORITIES-1) - (MULTIPLY_FACTOR*3)),   /**< The normal
                                                                                       Thread
                                                                                        priority */
    CY_RTOS_PRIORITY_ABOVENORMAL = ((TX_MAX_PRIORITIES-1) - (MULTIPLY_FACTOR*4)),   /**< A slightly
                                                                                       elevated
                                                                                        Thread
                                                                                           priority
                                                                                     */
    CY_RTOS_PRIORITY_HIGH        = ((TX_MAX_PRIORITIES-1) - (MULTIPLY_FACTOR*5)),   /**< A high
                                                                                       priority
                                                                                       Thread */
    CY_RTOS_PRIORITY_REALTIME    = ((TX_MAX_PRIORITIES-1) - (MULTIPLY_FACTOR*6)),   /**< Realtime
                                                                                       Thread
                                                                                       priority
                                                                                     */
    CY_RTOS_PRIORITY_MAX         = ((TX_MAX_PRIORITIES-1) - (MULTIPLY_FACTOR*7))    /**< Maximum
                                                                                       allowable
                                                                                       Thread
                                                                                        priority */
} cy_thread_priority_t;
#endif // if defined (CYW55500)

#if defined(__cplusplus)
}
#endif
