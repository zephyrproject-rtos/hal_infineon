/***************************************************************************//**
* \file ifx_se_ss_wifi.h
* \version 1.4.1
*
* \brief
* This is the header file for utility syscall functions, related to wifi subsystem
*
********************************************************************************
* \copyright
* Copyright (c) 2022-2026, Infineon Technologies AG, or an affiliate of
* Infineon Technologies AG. All rights reserved.
* SPDX-License-Identifier: Apache-2.0
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
******************************************************************************/
#ifndef IFX_SE_SS_WIFI_H_
#define IFX_SE_SS_WIFI_H_

#include "ifx_se_platform.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/** \addtogroup platform_wifi
 * \{
 */

/*******************************************************************************
 * Function Name: ifx_se_enable_wifi
 ***************************************************************************//**
 *
 * Performs HASH validation for RRAM WiFiSS FW Image and if success starts the
 * WIFI FW.
 *
 * \param[in] ctx           The pointer to the SE syscall context that contain
 *                          a special syscall data (IPC release callback etc).
 *
 * \return    \ref IFX_SE_SUCCESS for success or error code
 *
 ******************************************************************************/
ifx_se_status_t ifx_se_enable_wifi(void *ctx);

/*******************************************************************************
 * Function Name: ifx_se_disable_wifi
 ***************************************************************************//**
 *
 * Disables WiFiSS and power off the WIFI SS.
 *
 * \param[in] ctx           The pointer to the SE syscall context that contain
 *                          a special syscall data (IPC release callback etc).
 *
 * \return    \ref IFX_SE_SUCCESS for success or error code
 *
 ******************************************************************************/
ifx_se_status_t ifx_se_disable_wifi(void *ctx);

/*******************************************************************************
 * Function Name: ifx_se_enable_wifi_sram_access
 ***************************************************************************//**
 *
 * Enables only Wi-Fi SS SRAM for staging of RAM_APPs and allows CPUSS access
 *  to this memory.
 * WIFI SS needs to be turned off before calling this API.
 *
 * \param[in] ctx           The pointer to the SE syscall context that contain
 *                          a special syscall data (IPC release callback etc).
 *
 * \return    \ref IFX_SE_SUCCESS for success or error code
 *
 ******************************************************************************/
ifx_se_status_t ifx_se_enable_wifi_sram_access(void *ctx);

/** \} */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* IFX_SE_SS_WIFI_H_*/
