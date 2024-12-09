/***************************************************************************//**
* \file cyhal_ipc_impl.h
*
* \brief
* CAT1 specific implementation for IPC API.
*
********************************************************************************
* \copyright
* Copyright 2019-2021 Cypress Semiconductor Corporation (an Infineon company) or
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
*******************************************************************************/

#pragma once

#if (CYHAL_DRIVER_AVAILABLE_IPC)

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/**
 * \addtogroup group_hal_impl_ipc IPC
 * \ingroup group_hal_impl
 * \{
 * Implementation specific interface for using the IPC driver.
 *
 */

/**
* \cond INTERNAL
*/

#if defined(COMPONENT_CAT1A)
    /* On CAT1A devices CY_IPC_CHANNELS is not available at compile time,
       except for TVIIBE devices. */
    #if defined (CPUSS_IPC_IPC_NR) && (CPUSS_IPC_IPC_NR > 0)
        #define _CYHAL_IPC_DRV_CHANNELS     (CPUSS_IPC_IPC_NR)
    #else
        #define _CYHAL_IPC_DRV_CHANNELS     (16u)
    #endif
#elif defined(COMPONENT_CAT1D)
    /* Last channel is used by semaphores */
    #define _CYHAL_IPC_DRV_CHANNELS     (CY_IPC_IP1_CH - 1)
#else
    #define _CYHAL_IPC_DRV_CHANNELS     (CPUSS_IPC_IPC_NR)
#endif

/** Definition of _CYHAL_IPC_CHAN_USER which stands for first user-available IPC channel index */
#if defined(CY_IPC_CHAN_USER)
#if defined(COMPONENT_CAT1D)
    #define _CYHAL_IPC_CHAN_USER        (CY_IPC_CHAN_USER - IPC0_IPC_NR)
#else
    #define _CYHAL_IPC_CHAN_USER        (CY_IPC_CHAN_USER)
#endif
#else
    #if defined(COMPONENT_CAT1A)
        #define _CYHAL_IPC_CHAN_USER    (CY_IPC_CHAN_DDFT + 1)
    #elif defined(COMPONENT_CAT1B)
        #define _CYHAL_IPC_CHAN_USER    (0u)
    #else
        #error "Unhandled device"
    #endif /* defined(COMPONENT_CAT1A) or defined(COMPONENT_CAT1B) or other */
#endif /* !defined(CY_IPC_CHAN_USER) */

/** Number of available for IPC HAL user channels */
#define CYHAL_IPC_USR_CHANNELS                 ((_CYHAL_IPC_DRV_CHANNELS) - _CYHAL_IPC_CHAN_USER)

#if (CYHAL_IPC_USR_CHANNELS > 0)
    /** User IPC channel 0 */
    #define CYHAL_IPC_CHAN_0    (_CYHAL_IPC_CHAN_USER)
#endif /* CYHAL_IPC_USR_CHANNELS > 0 */
#if (CYHAL_IPC_USR_CHANNELS > 1)
    /** User IPC channel 1 */
    #define CYHAL_IPC_CHAN_1    (_CYHAL_IPC_CHAN_USER + 1)
#endif /* CYHAL_IPC_USR_CHANNELS > 1 */
#if (CYHAL_IPC_USR_CHANNELS > 2)
    /** User IPC channel 2 */
    #define CYHAL_IPC_CHAN_2    (_CYHAL_IPC_CHAN_USER + 2)
#endif /* CYHAL_IPC_USR_CHANNELS > 2 */
#if (CYHAL_IPC_USR_CHANNELS > 3)
    /** User IPC channel 3 */
    #define CYHAL_IPC_CHAN_3    (_CYHAL_IPC_CHAN_USER + 3)
#endif /* CYHAL_IPC_USR_CHANNELS > 3 */
#if (CYHAL_IPC_USR_CHANNELS > 4)
    /** User IPC channel 4 */
    #define CYHAL_IPC_CHAN_4    (_CYHAL_IPC_CHAN_USER + 4)
#endif /* CYHAL_IPC_USR_CHANNELS > 4 */
#if (CYHAL_IPC_USR_CHANNELS > 5)
    /** User IPC channel 5 */
    #define CYHAL_IPC_CHAN_5    (_CYHAL_IPC_CHAN_USER + 5)
#endif /* CYHAL_IPC_USR_CHANNELS > 5 */
#if (CYHAL_IPC_USR_CHANNELS > 6)
    /** User IPC channel 6 */
    #define CYHAL_IPC_CHAN_6    (_CYHAL_IPC_CHAN_USER + 6)
#endif /* CYHAL_IPC_USR_CHANNELS > 6 */
#if (CYHAL_IPC_USR_CHANNELS > 7)
    /** User IPC channel 7 */
    #define CYHAL_IPC_CHAN_7    (_CYHAL_IPC_CHAN_USER + 7)
#endif /* CYHAL_IPC_USR_CHANNELS > 7 */
#if (CYHAL_IPC_USR_CHANNELS > 8)
    /** User IPC channel 8 */
    #define CYHAL_IPC_CHAN_8    (_CYHAL_IPC_CHAN_USER + 8)
#endif /* CYHAL_IPC_USR_CHANNELS > 8 */
#if (CYHAL_IPC_USR_CHANNELS > 9)
    /** User IPC channel 9 */
    #define CYHAL_IPC_CHAN_9    (_CYHAL_IPC_CHAN_USER + 9)
#endif /* CYHAL_IPC_USR_CHANNELS > 9 */
#if (CYHAL_IPC_USR_CHANNELS > 10)
    /** User IPC channel 10 */
    #define CYHAL_IPC_CHAN_10    (_CYHAL_IPC_CHAN_USER + 10)
#endif /* CYHAL_IPC_USR_CHANNELS > 10 */
#if (CYHAL_IPC_USR_CHANNELS > 11)
    /** User IPC channel 11 */
    #define CYHAL_IPC_CHAN_11    (_CYHAL_IPC_CHAN_USER + 11)
#endif /* CYHAL_IPC_USR_CHANNELS > 11 */
#if (CYHAL_IPC_USR_CHANNELS > 12)
    /** User IPC channel 12 */
    #define CYHAL_IPC_CHAN_12    (_CYHAL_IPC_CHAN_USER + 12)
#endif /* CYHAL_IPC_USR_CHANNELS > 12 */
#if (CYHAL_IPC_USR_CHANNELS > 13)
    /** User IPC channel 13 */
    #define CYHAL_IPC_CHAN_13    (_CYHAL_IPC_CHAN_USER + 13)
#endif /* CYHAL_IPC_USR_CHANNELS > 13 */
#if (CYHAL_IPC_USR_CHANNELS > 14)
    /** User IPC channel 14 */
    #define CYHAL_IPC_CHAN_14    (_CYHAL_IPC_CHAN_USER + 14)
#endif /* CYHAL_IPC_USR_CHANNELS > 14 */
#if (CYHAL_IPC_USR_CHANNELS > 15)
    /** User IPC channel 15 */
    #define CYHAL_IPC_CHAN_15    (_CYHAL_IPC_CHAN_USER + 15)
#endif /* CYHAL_IPC_USR_CHANNELS > 15 */
#if (CYHAL_IPC_USR_CHANNELS > 16)
    #error "Unhandled number of free IPC channels"
#endif /* CYHAL_IPC_USR_CHANNELS > 16 */

/** Definition of _CYHAL_IPC_INTR_USER which stands for first user-available IPC interrupt structure index */
#if defined(CY_IPC_INTR_USER)
#if defined(COMPONENT_CAT1D)
#define _CYHAL_IPC_INTR_USER            (CY_IPC_INTR_USER - IPC0_IPC_IRQ_NR)
#else
#define _CYHAL_IPC_INTR_USER            (CY_IPC_INTR_USER)
#endif
#elif defined(CY_IPC_INTR_SPARE)
#define _CYHAL_IPC_INTR_USER            (CY_IPC_INTR_SPARE)
#else
#define _CYHAL_IPC_INTR_USER            (CYHAL_IPC_CHAN_0)
#endif

#define _CYHAL_IPC_CHAN_IDX_CORRECT(channel)    (((channel) >= CYHAL_IPC_CHAN_0) && ((channel) < (CYHAL_IPC_CHAN_0 + CYHAL_IPC_USR_CHANNELS)))

#ifdef CPUSS_IPC_IPC_IRQ_NR
#define _CYHAL_IPC_RELEASE_INTR_BITS            (CPUSS_IPC_IPC_IRQ_NR)
#else
#define _CYHAL_IPC_RELEASE_INTR_BITS            (16u)
#endif

#ifdef CY_IPC_CHAN_SEMA
#define _CYHAL_IPC_PDL_SEMA_CHAN                (CY_IPC_CHAN_SEMA)
#elif defined(COMPONENT_CAT1D)
/* Last available channel is used for semaphores */
#define _CYHAL_IPC_PDL_SEMA_CHAN                (CY_IPC_IP1_CH - 1)
#endif /* ifdef CY_IPC_CHAN_SEMA or other */

/** \endcond */

/** Number of semaphores, that can be used */
#ifdef CY_IPC_SEMA_COUNT
#define CYHAL_IPC_SEMA_COUNT               (CY_IPC_SEMA_COUNT)
#else
#define CYHAL_IPC_SEMA_COUNT               (128u)
#endif /* ifdef CY_IPC_SEMA_COUNT or other */

/** The round up of cacheline size MACRO */
#if defined (__DCACHE_PRESENT) && (__DCACHE_PRESENT == 1U)
#define L1_DCACHE_LINE_BYTES_MASK         (uint32_t)(__SCB_DCACHE_LINE_SIZE - 1)
#define L1_DCACHE_ROUND_UP_BYTES(a)       (((uint32_t)(a) + L1_DCACHE_LINE_BYTES_MASK) & ~(L1_DCACHE_LINE_BYTES_MASK))
#define L1_DCACHE_LINE_WORDS_MASK         (uint32_t)((__SCB_DCACHE_LINE_SIZE >> 2) - 1)
#define L1_DCACHE_ROUND_UP_WORDS(a)       (((uint32_t)(a) + L1_DCACHE_LINE_WORDS_MASK) & ~(L1_DCACHE_LINE_WORDS_MASK))
#endif /* defined (__DCACHE_PRESENT) && (__DCACHE_PRESENT == 1U) */

/** Macro for Queue pool shared memory allocation. Can be used only in function scope. Please use CY_SECTION_SHAREDMEM
 * instead if allocation in global scope is needed.
 * Params:
 * queue_pool - void pointer to point to the shared memory
 * NUM_ITEMS - number of items, that are expected to fit into the queue
 * ITEMSIZE - size of one queue item (in bytes)
 */
#if defined (__DCACHE_PRESENT) && (__DCACHE_PRESENT == 1U)
#define CYHAL_IPC_QUEUE_POOL_ALLOC(queue_pool, NUM_ITEMS, ITEMSIZE) \
    do { \
        CY_SECTION_SHAREDMEM static uint8_t _cyhal_ipc_queue_pool[L1_DCACHE_ROUND_UP_BYTES(ITEMSIZE * NUM_ITEMS)] CY_ALIGN(__SCB_DCACHE_LINE_SIZE); \
        queue_pool = (void*)&_cyhal_ipc_queue_pool; \
    } while (0)
#else
#define CYHAL_IPC_QUEUE_POOL_ALLOC(queue_pool, NUM_ITEMS, ITEMSIZE) \
    do { \
        CY_SECTION_SHAREDMEM static uint8_t _cyhal_ipc_queue_pool[ITEMSIZE * NUM_ITEMS]; \
        queue_pool = (void*)&_cyhal_ipc_queue_pool; \
    } while (0)
#endif /* defined (__DCACHE_PRESENT) && (__DCACHE_PRESENT == 1U) */

/** Macro for Queue handle shared memory allocation. Can be used only in function scope. Please use CY_SECTION_SHAREDMEM
 * instead if allocation in global scope is needed.
 * Params:
 * queue_handle - pointer to cyhal_ipc_queue_t data type, which will point to the shared memory
 */
#if defined (__DCACHE_PRESENT) && (__DCACHE_PRESENT == 1U)
#define CYHAL_IPC_QUEUE_HANDLE_ALLOC(queue_handle) \
    do { \
        CY_SECTION_SHAREDMEM static cyhal_ipc_queue_t _cyhal_ipc_queue_handle CY_ALIGN(__SCB_DCACHE_LINE_SIZE); \
        queue_handle = &_cyhal_ipc_queue_handle; \
    } while (0)
#else
#define CYHAL_IPC_QUEUE_HANDLE_ALLOC(queue_handle) \
    do { \
        CY_SECTION_SHAREDMEM static cyhal_ipc_queue_t _cyhal_ipc_queue_handle; \
        queue_handle = &_cyhal_ipc_queue_handle; \
    } while (0)
#endif /* defined (__DCACHE_PRESENT) && (__DCACHE_PRESENT == 1U) */

/** Polling interval, that will be used in blocking cyhal_ipc_* functions.
 * It is recommended to use value either below 1000 (e.g. 750) or multiple of 1000 (e.g. 1000, 2000, 3000, etc.)
 */
#ifndef CYHAL_IPC_POLLING_INTERVAL_uS
#define CYHAL_IPC_POLLING_INTERVAL_uS   (1000u)
#endif /* #ifndef CYHAL_IPC_POLLING_INTERVAL_uS */

/** This macro defines what device's core will initialize IPC PDL semaphores in scope of cyhal_ipc_semaphore_init call.
 * Please refer to implementation specific documentation for details.
 */
#ifndef CYHAL_IPC_INIT_CORE
#if defined(CY_DEVICE_TVIIBE)
#define CYHAL_IPC_INIT_CORE CORE_NAME_CM4_0
#elif defined(COMPONENT_CAT1C)
#define CYHAL_IPC_INIT_CORE CORE_NAME_CM7_0
#elif defined(COMPONENT_CAT1D)
#define CYHAL_IPC_INIT_CORE CORE_NAME_CM55
#endif /* defined(COMPONENT_CAT1C) or defined(COMPONENT_CAT1D) */
#endif /* not defined (CYHAL_IPC_INIT_CORE) */

/** Number of RTOS semaphores, that will be allocated and used by driver in RTOS environment
 * (CY_RTOS_AWARE or COMPONENT_RTOS_AWARE should be defined). Usage of RTOS semaphores in IPC semaphores implementation
 * helps to utilize waiting for semaphores times in RTOS environment more effectively. To achieve most effectiveness,
 * it is recommended to define CYHAL_IPC_RTOS_SEMA_NUM value to be greater-equal to the number of IPC semaphores, that
 * are planned to be used. Only semaphores with `semaphore_num`, that is less than _CYHAL_IPC_RELEASE_INTR_BITS can
 * benefit from this feature.
 * Value of this define can be 0. In this case, IPC HAL semaphores will not use RTOS semaphores.*/
#ifndef CYHAL_IPC_RTOS_SEMA_NUM
#define CYHAL_IPC_RTOS_SEMA_NUM         (4u)
#endif /* #ifndef CYHAL_IPC_RTOS_SEMA_NUM */

#if (CYHAL_IPC_RTOS_SEMA_NUM > _CYHAL_IPC_RELEASE_INTR_BITS)
#error "Cannot handle selected amount of RTOS semaphores. Please fix CYHAL_IPC_RTOS_SEMA_NUM value"
#endif /* CYHAL_IPC_RTOS_SEMA_NUM > _CYHAL_IPC_RELEASE_INTR_BITS */

/** \} group_hal_impl_ipc */

#if defined(__cplusplus)
}
#endif /* __cplusplus */

#endif /* CYHAL_DRIVER_AVAILABLE_IPC */
