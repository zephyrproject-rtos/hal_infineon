/***************************************************************************//**
* \file mtb_hal_hw_types_syspm.h
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
 * portable HAL SysPm API.
 *
 * \addtogroup group_hal_impl_hw_types Specific Hardware Types
 * \{
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "mtb_hal_hw_types_syspm_mxs22srss.h"

#if defined(MTB_HAL_DRIVER_AVAILABLE_SYSPM)

//! Implementation specific header for SysPm
#define MTB_HAL_SYSPM_IMPL_HEADER        "mtb_hal_syspm_impl.h"

/**
 * @brief SysPm callback data object
 *
 * Application code should not rely on the specific contents of this struct.
 * They are considered an implementation detail which is subject to change
 * between platforms and/or HAL releases.
 */
typedef struct
{
    cy_stc_syspm_callback_t        pdl_cb;
    cy_stc_syspm_callback_params_t cb_params;
    /* Actually a mtb_hal_syspm_callback_state_t, store as uint to avoid circular includes */
    uint32_t                       state;
    void*                          user_arg;
} mtb_hal_syspm_callback_data_t;


#endif // defined(MTB_HAL_DRIVER_AVAILABLE_SYSPM)

/** \} group_hal_impl_hw_types */


#ifdef __cplusplus
}
#endif
