/***************************************************************************//**
* \file ifx_se_config_template.h
* \version 1.4.1
*
* \brief
* This is a template of configuration header file which can be used to redefine
* default values set in source code.
*
* To use this file simply rename it to your preference and pass to build system
* or Makefile in a following way:
*   -DIFX_SE_CONFIG_FILE="\"ifx_se_user_config.h\""
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

#ifndef IFX_SE_CONFIG_H
#define IFX_SE_CONFIG_H

/* IPC channel to transfer data to SE RT Services */
/* #define IFX_SE_IPC_SYSCALL                     (0U) */

/* IPC interrupt channel to notify SE RT Services for new request */
/* #define IFX_SE_IPC_INTR_ACQ                    (0U) */

/* IPC interrupt channel to notify client from SE RT Services for processed request */
/* #define IFX_SE_IPC_INTR_REL                    (1U) */

#endif /* IFX_SE_CONFIG_H */
