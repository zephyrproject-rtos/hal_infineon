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

#include <FreeRTOS.h>
#include <semphr.h>
#include <task.h>
#include <event_groups.h>
#include <timers.h>
#include "stdbool.h"
#if !defined (COMPONENT_CAT5)
#include <cmsis_compiler.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************
*                   Enumerations
******************************************************/

typedef enum cy_thread_priority
{
    CY_RTOS_PRIORITY_MIN         = 0,
    CY_RTOS_PRIORITY_LOW         = (configMAX_PRIORITIES * 1 / 7),
    CY_RTOS_PRIORITY_BELOWNORMAL = (configMAX_PRIORITIES * 2 / 7),
    CY_RTOS_PRIORITY_NORMAL      = (configMAX_PRIORITIES * 3 / 7),
    CY_RTOS_PRIORITY_ABOVENORMAL = (configMAX_PRIORITIES * 4 / 7),
    CY_RTOS_PRIORITY_HIGH        = (configMAX_PRIORITIES * 5 / 7),
    CY_RTOS_PRIORITY_REALTIME    = (configMAX_PRIORITIES * 6 / 7),
    CY_RTOS_PRIORITY_MAX         = configMAX_PRIORITIES - 1
} cy_thread_priority_t;

/******************************************************
*                 Type Definitions
******************************************************/

typedef struct
{
    SemaphoreHandle_t mutex_handle;
    bool              is_recursive;
} cy_mutex_t;

typedef QueueHandle_t      cy_queue_t;
typedef SemaphoreHandle_t  cy_semaphore_t;
typedef TaskHandle_t       cy_thread_t;
typedef EventGroupHandle_t cy_event_t;
typedef TimerHandle_t      cy_timer_t;
typedef uint32_t           cy_timer_callback_arg_t;
typedef void*              cy_thread_arg_t;
typedef uint32_t           cy_time_t;
typedef BaseType_t         cy_rtos_error_t;

#ifdef __cplusplus
} // extern "C"
#endif
