/***************************************************************************//**
* \file mtb_hal_pwm_impl.h
*
* Description:
* Provides a high level interface for interacting with the Infineon PWM.
*
********************************************************************************
* \copyright
* Copyright 2019-2024 Cypress Semiconductor Corporation (an Infineon company) or
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

#if (MTB_HAL_DRIVER_AVAILABLE_PWM)

#if (defined(CY_IP_M0S8TCPWM) && (CY_IP_M0S8TCPWM_VERSION == 2))
#include "mtb_hal_pwm_m0s8tcpwm_v2.h"
#elif (defined(CY_IP_MXTCPWM) && (CY_IP_MXTCPWM_VERSION == 1))
#include "mtb_hal_pwm_mxtcpwm_v1.h"
#elif (defined(CY_IP_MXTCPWM) && (CY_IP_MXTCPWM_VERSION == 2))
#include "mtb_hal_pwm_mxtcpwm_v2.h"
#elif ((defined(CY_IP_MXS40TCPWM) && (CY_IP_MXS40TCPWM_VERSION == 1)) || (defined(CY_IP_MXTCPWM) && \
    (CY_IP_MXTCPWM_VERSION == 3)))
#include "mtb_hal_pwm_mxs40tcpwm_v1.h"
#else
#error "Unhandled version"
#endif

#endif // (MTB_HAL_DRIVER_AVAILABLE_PWM)

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/*******************************************************************************
*       Defines
*******************************************************************************/

/*******************************************************************************
*       Functions
*******************************************************************************/

/** Get the PWM killed state
 *
 * @param[in] obj             The PWM object
 * @param[out] killed         The killed status (false means no kill event. true means there is
 * active kill event)
 * @return                    The status of the clear request
 */
__STATIC_INLINE cy_rslt_t mtb_hal_pwm_get_killed_state(mtb_hal_pwm_t* obj, bool* killed)
{
    CY_ASSERT(NULL != obj);
    return _mtb_hal_pwm_get_killed_state(obj, killed);
}


#if defined(__cplusplus)
}
#endif /* __cplusplus */
