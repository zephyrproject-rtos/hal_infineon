/***************************************************************************//**
* \file mtb_hal_hw_types_clock.h
*
*********************************************************************************
* \copyright
* Copyright 2024-2025 Cypress Semiconductor Corporation (an Infineon company) or
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

/**
 * \brief
 * Provides implementation specific values for types that are part of the
 * portable HAL Clock API.
 *
 * \addtogroup group_hal_impl_hw_types Specific Hardware Types
 * \{
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "mtb_hal_hw_types_clock_srss.h"

#if defined(MTB_HAL_DRIVER_AVAILABLE_CLOCK)
//! Implementation specific header for Clock
#define MTB_HAL_CLOCK_IMPL_HEADER         "mtb_hal_clock_impl.h"
#endif // defined(MTB_HAL_DRIVER_AVAILABLE_SYSTEM)

/** \} group_hal_impl_hw_types */


#ifdef __cplusplus
}
#endif
