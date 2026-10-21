/***************************************************************************//**
* \file ifx_se_memory.h
* \version 1.4.1
*
* Provides IFX SE memory abstraction layer
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

#if !defined(IFX_SE_MEMORY_H_)
#define IFX_SE_MEMORY_H_

#include "ifx_se_syscall.h"
#include "ifx_se_fih.h"
#include "cy_syslib.h"
#include <stdlib.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#define ifx_se_calloc(...)              calloc(__VA_ARGS__)
#define ifx_se_free(...)                free(__VA_ARGS__)

__STATIC_INLINE ifx_se_status_t ifx_se_memcpy(void *dst, const void *src, size_t len)
{
    (void)memcpy(dst, src, len);
    return IFX_SE_SUCCESS;
}
__STATIC_INLINE ifx_se_status_t ifx_se_memset(void *dst, int32_t val, size_t len)
{
    (void)memset(dst, val, len);
    return IFX_SE_SUCCESS;
}

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* IFX_SE_MEMORY_H_ */

