/***************************************************************************//**
* \file ifx_se_syscall_builtin.c
* \version 1.4.1
*
* \brief
* This is the source code file for low-level syscall builtin functions.
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
#include "cy_ipc_drv.h"

/** SysCall timeout values */
#define IFX_SE_SYSCALL_TIMEOUT_SHORT      (15000UL)
#define IFX_SE_SYSCALL_TIMEOUT_LONG       (2000000000UL)

CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 8.13', 4, \
    'User context "ctx" designed for customer implementations and currently not used.')
CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Directive 4.9', 8, \
    'Use function-like macro as simple inline functions.')

__WEAK ifx_se_status_t ifx_se_hal_syscall_lock(void *ctx)
{
    /* ctx is unused in default implementation */
    (void)ctx;

    return IFX_SE_SUCCESS;
}

__WEAK ifx_se_status_t ifx_se_hal_syscall_start(void *ctx)
{
    /* ctx is unused in default implementation */
    (void)ctx;

    uint32_t timeout = 0U;

    /* Get IPC base register address */
    IPC_STRUCT_Type const *ipc_struct = Cy_IPC_Drv_GetIpcBaseAddress(IFX_SE_IPC_SYSCALL);

    while ((timeout < IFX_SE_SYSCALL_TIMEOUT_SHORT) &&
           (CY_IPC_DRV_SUCCESS != Cy_IPC_Drv_LockAcquire(ipc_struct)))
    {
        ++timeout;
    }

    return (timeout < IFX_SE_SYSCALL_TIMEOUT_SHORT) ? IFX_SE_SUCCESS : IFX_SE_SYSCALL_TIMEOUT_ERROR;
}

__WEAK ifx_se_status_t ifx_se_hal_syscall_wait_response(void *ctx)
{
    /* ctx is unused in default implementation */
    (void)ctx;

    uint32_t timeout = 0U;

    /* Get IPC base register address */
    IPC_STRUCT_Type const *ipc_struct = Cy_IPC_Drv_GetIpcBaseAddress(IFX_SE_IPC_SYSCALL);

    /* Wait for SE RT Services response ready */
    CY_MISRA_FP_LINE('MISRA C-2012 Rule 13.5', 'use IPC driver to check IPC lock status');
    while ((timeout < IFX_SE_SYSCALL_TIMEOUT_LONG) && Cy_IPC_Drv_IsLockAcquired(ipc_struct))
    {
        ++timeout;
    }

    return (timeout < IFX_SE_SYSCALL_TIMEOUT_LONG) ? IFX_SE_SUCCESS : IFX_SE_SYSCALL_TIMEOUT_ERROR;
}

__WEAK void ifx_se_hal_syscall_release(void *ctx)
{
    /* ctx is unused in default implementation */
    (void)ctx;
}

ifx_se_status_t ifx_se_syscall_builtin(ifx_se_fih_ptr_t ipc_packet, void *ctx)
{
    ifx_se_status_t status = IFX_SE_INVALID;
    ifx_se_fih_uint ipc_packet_addr = ifx_se_fih_ptr_to_uint(ipc_packet);

    /* Acquire syscall IPC structure.
     * Optinally lock access to syscall (example: use mutex for RTOS). */
    status = ifx_se_hal_syscall_lock(ctx);

    if (IFX_SE_IS_STATUS_SUCCESS(status))
    {
        status = ifx_se_hal_syscall_start(ctx);

        if (IFX_SE_IS_STATUS_SUCCESS(status))
        {
            /* Get IPC base register address */
            IPC_STRUCT_Type *ipc_struct = Cy_IPC_Drv_GetIpcBaseAddress(IFX_SE_IPC_SYSCALL);

            /* Use direct access to registers instead of call to Cy_IPC_Drv_WriteDDataValue() */
            REG_IPC_STRUCT_DATA(ipc_struct)  = ipc_packet_addr.val;
            REG_IPC_STRUCT_DATA1(ipc_struct) = ipc_packet_addr.msk;

            /* Add barriers to assure the syscall data is updated
             * before start SE RT Services syscall execution. */
            __DMB();
            __DSB();
            __ISB();

            Cy_IPC_Drv_AcquireNotify(ipc_struct, ((uint32_t)1U << IFX_SE_IPC_INTR_ACQ));

            /* Wait for syscall IPC Release event. */
            status = ifx_se_hal_syscall_wait_response(ctx);

            if (IFX_SE_IS_STATUS_SUCCESS(status))
            {
                /* Use direct access to registers instead of call to Cy_IPC_Drv_ReadDDataValue() */
                status.val = REG_IPC_STRUCT_DATA(ipc_struct);
                status.msk = REG_IPC_STRUCT_DATA1(ipc_struct);

                /* Check if packed processed */
                if (ifx_se_fih_uint_eq(status, ipc_packet_addr))
                {
                    status = IFX_SE_SYSCALL_INVALID_ARGUMENT;
                }
            }
        }

        /* Release previously acquired lock to syscall
         * (Example: release mutex for RTOS). */
        ifx_se_hal_syscall_release(ctx);
    }

    return status;
}

CY_MISRA_BLOCK_END('MISRA C-2012 Rule 8.13')
CY_MISRA_BLOCK_END('MISRA C-2012 Directive 4.9')
