/***********************************************************************************************//**
 * \file cyabs_rtos_impl.h
 *
 * \brief
 * Internal definitions for RTOS abstraction layer.
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

#include <stdint.h>
#include <stdbool.h>
#include "tx_api.h"

#ifdef __cplusplus
extern "C"
{
#endif

#if !defined (COMPONENT_CAT5)
#include <cmsis_compiler.h>
#else
#include "cyabs_rtos_impl_cat5.h"
#endif
#include "cyabs_rtos_types.h"


/******************************************************
*                 Constants
******************************************************/
#define CY_RTOS_MIN_STACK_SIZE  TX_MINIMUM_STACK /**< Minimum stack size in bytes */
#define CY_RTOS_ALIGNMENT       0x00000008UL     /**< Minimum alignment for RTOS objects */
#define CY_RTOS_ALIGNMENT_MASK  0x00000007UL     /**< Checks for 8-byte alignment */

#ifdef __cplusplus
} // extern "C"
#endif
