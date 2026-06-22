/***************************************************************************//**
* \file ifx_se_syscall.c
* \version 1.4.1
*
* \brief
* This is the source code file for syscall caller function.
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

#include "ifx_se_syscall.h"

#include "cy_syslib.h"

__WEAK ifx_se_status_t ifx_se_syscall(ifx_se_fih_ptr_t ipc_packet, ifx_se_fih_t ipc_packet_size, void *ctx)
{
    /* ipc_packet_size is unused in default implementation */
    (void)ipc_packet_size;

    return ifx_se_syscall_builtin(ipc_packet, ctx);
}
