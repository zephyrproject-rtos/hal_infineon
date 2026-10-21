/***************************************************************************//**
* \file ifx_se_platform.c
* \version 1.4.1
*
* \brief
* This is the source code file for utility syscall functions.
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

#include "ifx_se_platform.h"
#include "ifx_se_psacrypto_values.h"
#include "ifx_se_psacrypto_struct.h"

#include "cy_utils.h"

CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 5.1', 1, \
    'IFX SE Utilities library uses objects naming scheme with more then 32 symbols.')
CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 11.3', 13, \
    'Intentional typecast of "ipc_packet[]" to "ifx_se_fih_uint *" type.')
CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 11.4', 13, \
    'Intentional typecast of "ipc_packet" to an integer type.')
CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Directive 4.9', 4, \
    'Use function-like macro as simple inline functions.')

ifx_se_status_t ifx_se_get_rollback_counter(ifx_se_fih_t number, ifx_se_fih_ptr_t value, void *ctx)
{
    ifx_se_status_t status = IFX_SE_SYSCALL_CORRUPTION_DETECTED;

    /* 2 parameters */
    uint32_t ipc_packet[SE_RT_PACKET_CALC_SIZE(2u)]; /* in 32-bit words (4 bytes) */
    ifx_se_fih_uint *ipc_params = SE_RT_PARAMS_GET_PTR(ipc_packet);

    ipc_params[0] = IFX_SE_SYSCALL_GET_ROLLBACK_COUNTER;
    ipc_params[1] = number;
    ipc_params[2] = ifx_se_fih_ptr_to_uint(value);

    SE_RT_PACKET_FINALIZE(ipc_packet);

    status = ifx_se_syscall(ifx_se_fih_ptr_encode(ipc_packet), ifx_se_fih_uint_encode(sizeof(ipc_packet)), ctx);

    return status;
}

ifx_se_status_t ifx_se_update_rollback_counter(ifx_se_fih_t number, ifx_se_fih_t value, void *ctx)
{
    ifx_se_status_t status = IFX_SE_SYSCALL_CORRUPTION_DETECTED;

    /* 2 parameters */
    uint32_t ipc_packet[SE_RT_PACKET_CALC_SIZE(2u)]; /* in 32-bit words (4 bytes) */
    ifx_se_fih_uint *ipc_params = SE_RT_PARAMS_GET_PTR(ipc_packet);

    ipc_params[0] = IFX_SE_SYSCALL_UPDATE_ROLLBACK_COUNTER;
    ipc_params[1] = number;
    ipc_params[2] = value;

    SE_RT_PACKET_FINALIZE(ipc_packet);

    status = ifx_se_syscall(ifx_se_fih_ptr_encode(ipc_packet), ifx_se_fih_uint_encode(sizeof(ipc_packet)), ctx);

    return status;
}

ifx_se_status_t ifx_se_get_usage_limit_counter(ifx_se_key_id_fih_t key, ifx_se_fih_ptr_t value, void *ctx)
{
    ifx_se_status_t status = IFX_SE_SYSCALL_CORRUPTION_DETECTED;

    /* 3 parameters */
    uint32_t ipc_packet[SE_RT_PACKET_CALC_SIZE(3u)]; /* in 32-bit words (4 bytes) */
    ifx_se_fih_uint *ipc_params = SE_RT_PARAMS_GET_PTR(ipc_packet);

    ipc_params[0] = IFX_SE_SYSCALL_GET_USAGE_LIMIT_COUNTER;
    ipc_params[1] = key.key_id;
    ipc_params[2] = key.owner;
    ipc_params[3] = ifx_se_fih_ptr_to_uint(value);

    SE_RT_PACKET_FINALIZE(ipc_packet);

    status = ifx_se_syscall(ifx_se_fih_ptr_encode(ipc_packet), ifx_se_fih_uint_encode(sizeof(ipc_packet)), ctx);

    return status;
}

ifx_se_status_t ifx_se_disable(void *ctx)
{
    ifx_se_status_t status = IFX_SE_SYSCALL_CORRUPTION_DETECTED;

    /* 0 parameters */
    uint32_t ipc_packet[SE_RT_PACKET_CALC_SIZE(0u)]; /* in 32-bit words (4 bytes) */
    ifx_se_fih_uint *ipc_params = SE_RT_PARAMS_GET_PTR(ipc_packet);

    ipc_params[0] = IFX_SE_SYSCALL_DISABLE;

    SE_RT_PACKET_FINALIZE(ipc_packet);

    status = ifx_se_syscall(ifx_se_fih_ptr_encode(ipc_packet), ifx_se_fih_uint_encode(sizeof(ipc_packet)), ctx);

    return status;
}

ifx_se_status_t ifx_se_enable(void *ctx)
{
    ifx_se_status_t status = IFX_SE_SYSCALL_CORRUPTION_DETECTED;

    /* 0 parameters */
    uint32_t ipc_packet[SE_RT_PACKET_CALC_SIZE(0u)]; /* in 32-bit words (4 bytes) */
    ifx_se_fih_uint *ipc_params = SE_RT_PARAMS_GET_PTR(ipc_packet);

    ipc_params[0] = IFX_SE_SYSCALL_ENABLE;

    SE_RT_PACKET_FINALIZE(ipc_packet);

    status = ifx_se_syscall(ifx_se_fih_ptr_encode(ipc_packet), ifx_se_fih_uint_encode(sizeof(ipc_packet)), ctx);

    return status;
}

ifx_se_status_t ifx_se_set_lpm(ifx_se_en_power_mode_t mode, void *ctx)
{
    ifx_se_status_t status = IFX_SE_SYSCALL_CORRUPTION_DETECTED;

    /* 1 parameters */
    uint32_t ipc_packet[SE_RT_PACKET_CALC_SIZE(1u)]; /* in 32-bit words (4 bytes) */
    ifx_se_fih_uint *ipc_params = SE_RT_PARAMS_GET_PTR(ipc_packet);

    ipc_params[0] = IFX_SE_SYSCALL_SET_LPM;
    ipc_params[1] = ifx_se_fih_uint_encode((uint32_t)mode);

    SE_RT_PACKET_FINALIZE(ipc_packet);

    status = ifx_se_syscall(ifx_se_fih_ptr_encode(ipc_packet), ifx_se_fih_uint_encode(sizeof(ipc_packet)), ctx);

    return status;
}


ifx_se_status_t ifx_se_get_info(ifx_se_rt_info_t *output, size_t output_size, void *ctx)
{
    ifx_se_status_t status = IFX_SE_SYSCALL_CORRUPTION_DETECTED;

    /* 2 parameters */
    uint32_t ipc_packet[SE_RT_PACKET_CALC_SIZE(2u)]; /* in 32-bit words (4 bytes) */
    ifx_se_fih_uint *ipc_params = SE_RT_PARAMS_GET_PTR(ipc_packet);

    ipc_params[0] = IFX_SE_SYSCALL_GET_INFO;
    ipc_params[1] = ifx_se_fih_ptr_to_uint(ifx_se_fih_ptr_encode(output));
    ipc_params[2] = ifx_se_fih_uint_encode((uint32_t)output_size);

    SE_RT_PACKET_FINALIZE(ipc_packet);

    status = ifx_se_syscall(ifx_se_fih_ptr_encode(ipc_packet), ifx_se_fih_uint_encode(sizeof(ipc_packet)), ctx);

    return status;
}

ifx_se_status_t ifx_se_set_shared_data(ifx_se_fih_t image_id, const ifx_se_fih_ptr_t data, ifx_se_fih_t data_size, void *ctx)
{
    ifx_se_status_t status = IFX_SE_SYSCALL_CORRUPTION_DETECTED;

    /* 3 parameters */
    uint32_t ipc_packet[SE_RT_PACKET_CALC_SIZE(3u)]; /* in 32-bit words (4 bytes) */
    ifx_se_fih_uint *ipc_params = SE_RT_PARAMS_GET_PTR(ipc_packet);

    ipc_params[0] = IFX_SE_SYSCALL_SET_SHARED_DATA;
    ipc_params[1] = image_id;
    ipc_params[2] = ifx_se_fih_ptr_to_uint(data);
    ipc_params[3] = data_size;

    SE_RT_PACKET_FINALIZE(ipc_packet);

    status = ifx_se_syscall(ifx_se_fih_ptr_encode(ipc_packet), ifx_se_fih_uint_encode(sizeof(ipc_packet)), ctx);

    return status;
}

ifx_se_status_t ifx_se_lock_shared_data(void *ctx)
{
    ifx_se_status_t status = IFX_SE_SYSCALL_CORRUPTION_DETECTED;

    /* 0 parameters */
    uint32_t ipc_packet[SE_RT_PACKET_CALC_SIZE(0u)]; /* in 32-bit words (4 bytes) */
    ifx_se_fih_uint *ipc_params = SE_RT_PARAMS_GET_PTR(ipc_packet);

    ipc_params[0] = IFX_SE_SYSCALL_LOCK_SHARED_DATA;

    SE_RT_PACKET_FINALIZE(ipc_packet);

    status = ifx_se_syscall(ifx_se_fih_ptr_encode(ipc_packet), ifx_se_fih_uint_encode(sizeof(ipc_packet)), ctx);

    return status;
}

ifx_se_status_t ifx_se_initial_attest_get_token(const ifx_se_fih_ptr_t challenge,
                                                ifx_se_fih_t challenge_size,
                                                ifx_se_fih_t client_id,
                                                const ifx_se_fih_ptr_t verify_svc,
                                                ifx_se_fih_t verify_svc_size,
                                                const ifx_se_fih_ptr_t hardware_ver,
                                                ifx_se_fih_t hardware_ver_size,
                                                ifx_se_fih_ptr_t token_data,
                                                ifx_se_fih_t token_size,
                                                ifx_se_fih_ptr_t token_length,
                                                void *ctx)
{
    ifx_se_status_t status = IFX_SE_SYSCALL_CORRUPTION_DETECTED;

    /* 10 parameters */
    uint32_t ipc_packet[SE_RT_PACKET_CALC_SIZE(10u)]; /* in 32-bit words (4 bytes) */
    ifx_se_fih_uint *ipc_params = SE_RT_PARAMS_GET_PTR(ipc_packet);

    ipc_params[0] = IFX_SE_SYSCALL_INIT_ATTEST_GET_TOKEN;
    ipc_params[1] = ifx_se_fih_ptr_to_uint(challenge);
    ipc_params[2] = challenge_size;
    ipc_params[3] = client_id;
    ipc_params[4] = ifx_se_fih_ptr_to_uint(verify_svc);
    ipc_params[5] = verify_svc_size;
    ipc_params[6] = ifx_se_fih_ptr_to_uint(hardware_ver);
    ipc_params[7] = hardware_ver_size;
    ipc_params[8] = ifx_se_fih_ptr_to_uint(token_data);
    ipc_params[9] = token_size;
    ipc_params[10] = ifx_se_fih_ptr_to_uint(token_length);

    SE_RT_PACKET_FINALIZE(ipc_packet);

    status = ifx_se_syscall(ifx_se_fih_ptr_encode(ipc_packet), ifx_se_fih_uint_encode(sizeof(ipc_packet)), ctx);

    return status;
}

ifx_se_status_t ifx_se_initial_attest_get_token_size(ifx_se_fih_t challenge_size,
                                                     ifx_se_fih_ptr_t token_length, void *ctx)
{
    ifx_se_status_t status = IFX_SE_SYSCALL_CORRUPTION_DETECTED;

    /* 2 parameters */
    uint32_t ipc_packet[SE_RT_PACKET_CALC_SIZE(2u)]; /* in 32-bit words (2 bytes) */
    ifx_se_fih_uint *ipc_params = SE_RT_PARAMS_GET_PTR(ipc_packet);

    ipc_params[0] = IFX_SE_SYSCALL_INIT_ATTEST_GET_TOKEN_SIZE;
    ipc_params[1] = challenge_size;
    ipc_params[2] = ifx_se_fih_ptr_to_uint(token_length);

    SE_RT_PACKET_FINALIZE(ipc_packet);

    status = ifx_se_syscall(ifx_se_fih_ptr_encode(ipc_packet), ifx_se_fih_uint_encode(sizeof(ipc_packet)), ctx);

    return status;
}

ifx_se_status_t ifx_se_mpc_config_rot_mpc_struct(const ifx_se_mpc_rot_cfg_crc_t *mpc_config, void *ctx)
{
    ifx_se_status_t status = IFX_SE_SYSCALL_CORRUPTION_DETECTED;

    /* 1 parameter */
    uint32_t ipc_packet[SE_RT_PACKET_CALC_SIZE(1u)]; /* in 32-bit words (4 bytes) */
    ifx_se_fih_uint *ipc_params = SE_RT_PARAMS_GET_PTR(ipc_packet);

    ipc_params[0] = IFX_SE_SYSCALL_MPC_CONFIG_ROT_MPC_STRUCT;
    ipc_params[1] = ifx_se_fih_ptr_to_uint(ifx_se_fih_ptr_encode(mpc_config));

    SE_RT_PACKET_FINALIZE(ipc_packet);

    status = ifx_se_syscall(ifx_se_fih_ptr_encode(ipc_packet), ifx_se_fih_uint_encode(sizeof(ipc_packet)), ctx);

    return status;
}

ifx_se_status_t ifx_se_mpc_lock(void *ctx)
{
    ifx_se_status_t status = IFX_SE_SYSCALL_CORRUPTION_DETECTED;

    /* none user parameters, just control fields */
    uint32_t ipc_packet[SE_RT_PACKET_CALC_SIZE(0u)]; /* in 32-bit words (4 bytes) */
    ifx_se_fih_uint *ipc_params = SE_RT_PARAMS_GET_PTR(ipc_packet);

    ipc_params[0] = IFX_SE_SYSCALL_MPC_LOCK;

    SE_RT_PACKET_FINALIZE(ipc_packet);

    status = ifx_se_syscall(ifx_se_fih_ptr_encode(ipc_packet), ifx_se_fih_uint_encode(sizeof(ipc_packet)), ctx);

    return status;
}

ifx_se_status_t ifx_se_ppc_config(const ifx_se_ppc_config_t *ppc_config, void *ctx)
{
    ifx_se_status_t status = IFX_SE_SYSCALL_CORRUPTION_DETECTED;

    /* 1 parameter */
    uint32_t ipc_packet[SE_RT_PACKET_CALC_SIZE(1u)]; /* in 32-bit words (4 bytes) */
    ifx_se_fih_uint *ipc_params = SE_RT_PARAMS_GET_PTR(ipc_packet);

    ipc_params[0] = IFX_SE_SYSCALL_PPC_CONFIG;
    ipc_params[1] = ifx_se_fih_ptr_to_uint(ifx_se_fih_ptr_encode(ppc_config));

    SE_RT_PACKET_FINALIZE(ipc_packet);

    status = ifx_se_syscall(ifx_se_fih_ptr_encode(ipc_packet), ifx_se_fih_uint_encode(sizeof(ipc_packet)), ctx);

    return status;
}

ifx_se_status_t ifx_se_set_image_hash(ifx_se_fih_t image_id,
                                      const ifx_se_fih_ptr_t hash, ifx_se_fih_t hash_size, void *ctx)
{
    ifx_se_status_t status = IFX_SE_SYSCALL_CORRUPTION_DETECTED;

    /* 3 parameters */
    uint32_t ipc_packet[SE_RT_PACKET_CALC_SIZE(3u)]; /* in 32-bit words (4 bytes) */
    ifx_se_fih_uint *ipc_params = SE_RT_PARAMS_GET_PTR(ipc_packet);

    ipc_params[0] = IFX_SE_SYSCALL_SET_IMAGE_HASH;
    ipc_params[1] = image_id;
    ipc_params[2] = ifx_se_fih_ptr_to_uint(hash);
    ipc_params[3] = hash_size;

    SE_RT_PACKET_FINALIZE(ipc_packet);

    status = ifx_se_syscall(ifx_se_fih_ptr_encode(ipc_packet), ifx_se_fih_uint_encode(sizeof(ipc_packet)), ctx);

    return status;
}

ifx_se_status_t ifx_se_get_image_hash(ifx_se_fih_t image_id,
                                      ifx_se_fih_ptr_t hash, ifx_se_fih_t hash_size, ifx_se_fih_ptr_t hash_length,
                                      void *ctx)
{
    ifx_se_status_t status = IFX_SE_SYSCALL_CORRUPTION_DETECTED;

    /* 4 parameters */
    uint32_t ipc_packet[SE_RT_PACKET_CALC_SIZE(4u)]; /* in 32-bit words (4 bytes) */
    ifx_se_fih_uint *ipc_params = SE_RT_PARAMS_GET_PTR(ipc_packet);

    ipc_params[0] = IFX_SE_SYSCALL_GET_IMAGE_HASH;
    ipc_params[1] = image_id;
    ipc_params[2] = ifx_se_fih_ptr_to_uint(hash);
    ipc_params[3] = hash_size;
    ipc_params[4] = ifx_se_fih_ptr_to_uint(hash_length);

    SE_RT_PACKET_FINALIZE(ipc_packet);

    status = ifx_se_syscall(ifx_se_fih_ptr_encode(ipc_packet), ifx_se_fih_uint_encode(sizeof(ipc_packet)), ctx);

    return status;
}

ifx_se_status_t ifx_se_verify_image_hash(ifx_se_fih_t image_id,
                                         const ifx_se_fih_ptr_t hash, ifx_se_fih_t hash_size, void *ctx)
{
    ifx_se_status_t status = IFX_SE_SYSCALL_CORRUPTION_DETECTED;

    /* 3 parameters */
    uint32_t ipc_packet[SE_RT_PACKET_CALC_SIZE(3u)]; /* in 32-bit words (4 bytes) */
    ifx_se_fih_uint *ipc_params = SE_RT_PARAMS_GET_PTR(ipc_packet);

    ipc_params[0] = IFX_SE_SYSCALL_VERIFY_IMAGE_HASH;
    ipc_params[1] = image_id;
    ipc_params[2] = ifx_se_fih_ptr_to_uint(hash);
    ipc_params[3] = hash_size;

    SE_RT_PACKET_FINALIZE(ipc_packet);

    status = ifx_se_syscall(ifx_se_fih_ptr_encode(ipc_packet), ifx_se_fih_uint_encode(sizeof(ipc_packet)), ctx);

    return status;
}

ifx_se_status_t ifx_se_lock_image_hash(ifx_se_fih_t image_id, void *ctx)
{
    ifx_se_status_t status = IFX_SE_SYSCALL_CORRUPTION_DETECTED;

    /* 1 parameters */
    uint32_t ipc_packet[SE_RT_PACKET_CALC_SIZE(1u)]; /* in 32-bit words (4 bytes) */
    ifx_se_fih_uint *ipc_params = SE_RT_PARAMS_GET_PTR(ipc_packet);

    ipc_params[0] = IFX_SE_SYSCALL_LOCK_IMAGE_HASH;
    ipc_params[1] = image_id;

    SE_RT_PACKET_FINALIZE(ipc_packet);

    status = ifx_se_syscall(ifx_se_fih_ptr_encode(ipc_packet), ifx_se_fih_uint_encode(sizeof(ipc_packet)), ctx);

    return status;
}

CY_MISRA_BLOCK_END('MISRA C-2012 Rule 5.1')
CY_MISRA_BLOCK_END('MISRA C-2012 Rule 11.3')
CY_MISRA_BLOCK_END('MISRA C-2012 Rule 11.4')
CY_MISRA_BLOCK_END('MISRA C-2012 Directive 4.9')
