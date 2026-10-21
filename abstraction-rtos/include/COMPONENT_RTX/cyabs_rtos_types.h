/***********************************************************************************************//**
 * \file cyabs_rtos_types.h
 *
 * \brief
 * Internal type definitions for RTOS abstraction layer
 *
 ***************************************************************************************************
 * \copyright
 * Copyright 2019-2025 Cypress Semiconductor Corporation (an Infineon company) or
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

#include "cmsis_os2.h"
#include "rtx_os.h"
#if !defined (COMPONENT_CAT5)
#include <cmsis_compiler.h>
#endif

#ifdef __cplusplus
extern "C"
{
#endif

/******************************************************
*                 Type Definitions
******************************************************/

// RTOS thread priority
typedef enum
{
    CY_RTOS_PRIORITY_MIN         = osPriorityNone,
    CY_RTOS_PRIORITY_LOW         = osPriorityLow,
    CY_RTOS_PRIORITY_BELOWNORMAL = osPriorityBelowNormal,
    CY_RTOS_PRIORITY_NORMAL      = osPriorityNormal,
    CY_RTOS_PRIORITY_ABOVENORMAL = osPriorityAboveNormal,
    CY_RTOS_PRIORITY_HIGH        = osPriorityHigh,
    CY_RTOS_PRIORITY_REALTIME    = osPriorityRealtime,
    CY_RTOS_PRIORITY_MAX         = osPriorityRealtime7
} cy_thread_priority_t;

typedef osThreadId_t       cy_thread_t;             /** CMSIS definition of a thread handle */
typedef void*              cy_thread_arg_t;         /** Argument passed to the entry function of
                                                        a thread */
typedef osMutexId_t        cy_mutex_t;              /** CMSIS definition of a mutex */
typedef osSemaphoreId_t    cy_semaphore_t;          /** CMSIS definition of a semaphore */
typedef osEventFlagsId_t   cy_event_t;              /** CMSIS definition of an event */
typedef osMessageQueueId_t cy_queue_t;              /** CMSIS definition of a message queue */
typedef osTimerId_t        cy_timer_t;              /** CMSIS definition of a timer */
typedef void*              cy_timer_callback_arg_t; /** Argument passed to the timer callback
                                                        function */
typedef uint32_t           cy_time_t;               /** Time in milliseconds */
typedef osStatus_t         cy_rtos_error_t;         /** CMSIS definition of a error status */


#ifdef __cplusplus
} // extern "C"
#endif
