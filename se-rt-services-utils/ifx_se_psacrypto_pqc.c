/***************************************************************************//**
* \file ifx_se_psacrypto_pqc.c
* \version 1.4.1
*
* Provides IFX SE PQC layer implementation
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

#include "ifx_se_psacrypto.h"

#if defined(COMPONENT_MW_WOLFSSL)

#include "cy_syslib.h"

#include "wolfssl/wolfcrypt/dilithium.h"
#include "wolfssl/wolfcrypt/error-crypt.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define miscellaneous literal constants that are used inside implementation */
#define IFX_SE_STORAGE_INVALID_ID      (0u)
#define IFX_SE_STORAGE_NOT_IN_USE      (0u)

#define IFX_SE_STORAGE_OWNER_ID        (0u)

#define SE_RT_KEY_ID_TO_INDEX(key_id)  (uint32_t)((key_id) - IFX_SE_KEY_ID_PQC_MIN)
#define SE_RT_INDEX_TO_KEY_ID(idx)     (ifx_se_key_id_t)((idx) + IFX_SE_KEY_ID_PQC_MIN)

struct ifx_se_storage_key_slot_s {
    ifx_se_key_id_t id;
    ifx_se_key_attributes_t attributes;
    size_t data_size;
    uint8_t *data;
};
typedef struct ifx_se_storage_key_slot_s ifx_se_storage_key_slot_t;

static ifx_se_storage_key_slot_t key_slots[IFX_SE_STORAGE_SLOT_NUM] = {0};

__WEAK 
ifx_se_status_t ifx_se_pqc_get_random(
    ifx_se_fih_ptr_t output,
    ifx_se_fih_t output_size,
    void *ctx)
{
    return ifx_se_generate_random(output, output_size, ctx);
}

/**
 * \brief Allocate an key data in the local storage
 *
 * \param[out] slot    Pointer to the allocated slot
 *
 * \return Return values as described in \ref ifx_se_status_t
 */
static ifx_se_status_t ifx_se_storage_key_slot_alloc(ifx_se_storage_key_slot_t **slot)
{
    uint32_t i;
    ifx_se_status_t status = IFX_SE_ERROR_INVALID_ARGUMENT;

    if (slot != NULL)
    {
        *slot = NULL;
        status = IFX_SE_ERROR_INSUFFICIENT_STORAGE;

        for (i = 0u; i < IFX_SE_STORAGE_SLOT_NUM; i++)
        {
            if (key_slots[i].id == IFX_SE_STORAGE_NOT_IN_USE)
            {
                key_slots[i].id = SE_RT_INDEX_TO_KEY_ID(i);

                *slot = &key_slots[i];

                status = IFX_SE_SUCCESS;

                break;
            }
        }
    }

    return status;
}

/**
 * \brief Release an key data in the local storage
 *
 * \param[in]  key_id  Key ID to look up
 *
 * \return Return values as described in \ref ifx_se_status_t
 */
static ifx_se_status_t ifx_se_storage_key_slot_release(ifx_se_key_id_t key_id)
{
    ifx_se_status_t status = IFX_SE_ERROR_INVALID_ARGUMENT;

    if (key_id >= IFX_SE_KEY_ID_PQC_MIN)
    {
        uint32_t idx = SE_RT_KEY_ID_TO_INDEX(key_id);

        if (idx < IFX_SE_STORAGE_SLOT_NUM)
        {
            if (key_slots[idx].data != NULL)
            {
                free(key_slots[idx].data);
            }
            memset(&key_slots[idx], 0, sizeof(ifx_se_storage_key_slot_t));

            status = IFX_SE_SUCCESS;
        }
    }

    return status;
}

/**
 * \brief Look up an key data in the local storage
 *
 * \param[in]  key_id  Key ID to look up
 * \param[out] slot    Pointer to the found slot
 *
 * \return Return values as described in \ref ifx_se_status_t
 */
static ifx_se_status_t ifx_se_storage_key_slot_lookup(ifx_se_key_id_t key_id,
                                                  ifx_se_storage_key_slot_t **slot)
{
    ifx_se_status_t status = IFX_SE_ERROR_BAD_STATE;

    if (key_id >= IFX_SE_KEY_ID_PQC_MIN)
    {
        uint32_t idx = SE_RT_KEY_ID_TO_INDEX(key_id);

        if (idx < IFX_SE_STORAGE_SLOT_NUM)
        {
            *slot = &key_slots[idx];

            status = IFX_SE_SUCCESS;
        }
    }

    return status;
}

ifx_se_status_t ifx_se_storage_import_key(
    const ifx_se_key_attributes_t *attributes,
    const ifx_se_fih_ptr_t data,
    ifx_se_fih_t data_length, /* with CRC included */
    ifx_se_fih_ptr_t key)
{
    ifx_se_status_t status = IFX_SE_ERROR_INVALID_ARGUMENT;

    ifx_se_storage_key_slot_t *slot;

    uint8_t *key_data = (uint8_t *)ifx_se_fih_ptr_decode(data);
    size_t key_data_length = (size_t)ifx_se_fih_uint_decode(data_length);
    ifx_se_key_id_fih_t *key_out = (ifx_se_key_id_fih_t *)ifx_se_fih_ptr_decode(key);

    if ((key_data != NULL) && (key_data_length > 0u) && (key_out != NULL))
    {
        status = IFX_SE_SYSCALL_INTEGRITY_FAILURE;

        if (key_data_length > IFX_CRC32_CRC_SIZE)
        {
            uint32_t key_crc;

            key_data_length -= IFX_CRC32_CRC_SIZE;

            (void)memcpy(&key_crc, key_data + key_data_length, IFX_CRC32_CRC_SIZE);

            if (key_crc == IFX_CRC32_CALC(key_data, key_data_length))
            {
                /* Allocate the key context in the local storage */
                status = ifx_se_storage_key_slot_alloc(&slot);

                if (ifx_se_fih_uint_eq(status, IFX_SE_SUCCESS))
                {
                    uint8_t *slot_key_data = (uint8_t *)calloc(1, key_data_length);
                    if (slot_key_data != NULL)
                    {
                        (void)memcpy(slot_key_data, key_data, key_data_length);
                        slot->data = slot_key_data;
                        slot->data_size = key_data_length;
                        slot->attributes = *attributes;
                        slot->attributes.id = ifx_se_svc_key_id_make(IFX_SE_STORAGE_OWNER_ID, slot->id);

                        key_out->key_id = ifx_se_fih_uint_encode(slot->id);
                        key_out->owner = ifx_se_fih_uint_encode(IFX_SE_STORAGE_OWNER_ID);

                        status = IFX_SE_SUCCESS;
                    }
                }
            }
        }
    }

    return status;
}

ifx_se_status_t ifx_se_storage_export_key(ifx_se_key_id_fih_t key,
    ifx_se_fih_ptr_t data,
    ifx_se_fih_t data_size, /* with CRC included */
    ifx_se_fih_ptr_t data_length)
{
    ifx_se_status_t status = IFX_SE_ERROR_INVALID_HANDLE;
    ifx_se_storage_key_slot_t *slot;

    uint8_t *key_data = (uint8_t *)ifx_se_fih_ptr_decode(data);
    size_t *key_data_length = (size_t *)ifx_se_fih_ptr_decode(data_length);

    /* Look up the corresponding operation context */
    status = ifx_se_storage_key_slot_lookup(ifx_se_fih_uint_decode(key.key_id), &slot);

    if (ifx_se_fih_uint_eq(status, IFX_SE_SUCCESS))
    {
        status = IFX_SE_ERROR_NOT_PERMITTED;

        if ((slot->attributes.policy.usage & IFX_SE_KEY_USAGE_EXPORT) == IFX_SE_KEY_USAGE_EXPORT)
        {
            status = IFX_SE_ERROR_INSUFFICIENT_MEMORY;

            if (ifx_se_fih_uint_decode(data_size) >= slot->data_size)
            {
                memcpy(key_data, slot->data, slot->data_size);
                *key_data_length = slot->data_size;

                status = IFX_SE_SUCCESS;
            }
        }
    }

    return status;
}

ifx_se_status_t ifx_se_storage_destroy_key(ifx_se_key_id_fih_t key)
{
    /* Release the operation context. */
    return ifx_se_storage_key_slot_release(ifx_se_fih_uint_decode(key.key_id));
}

/**
 * \brief Finds a key in the storage and returns pointer to the key data.
 *
 * \param[in] key           Identifier of the key to export. It must allow the
 *                          usage #IFX_SE_KEY_USAGE_EXPORT, unless it is
 *                          a public key.
 * \param[out] data         Buffer where the key data is to be written
 *                          (encoded pointer to output buffer).
 * \param[out] data_length  On success, the number of bytes
 *                          that make up the key data
 *                          (encoded pointer to size_t variable).
 * \param[out] attributes   On success, the attributes of the key.
 *
 * \return Return values as described in \ref ifx_se_status_t
 */
static ifx_se_status_t ifx_se_storage_get_key(ifx_se_key_id_fih_t key,
    ifx_se_fih_ptr_t data,
    ifx_se_fih_ptr_t data_length,
    ifx_se_key_attributes_t *attributes)
{
    ifx_se_status_t status = IFX_SE_ERROR_INVALID_HANDLE;
    ifx_se_storage_key_slot_t *slot;

    uint8_t **key_data = (uint8_t **)ifx_se_fih_ptr_decode(data);
    size_t *key_data_length = (size_t *)ifx_se_fih_ptr_decode(data_length);

    /* Look up the corresponding operation context */
    status = ifx_se_storage_key_slot_lookup(ifx_se_fih_uint_decode(key.key_id), &slot);

    if (ifx_se_fih_uint_eq(status, IFX_SE_SUCCESS))
    {
        status = IFX_SE_ERROR_INSUFFICIENT_MEMORY;

        *key_data = slot->data;
        *key_data_length = slot->data_size;
        *attributes = slot->attributes;

        status = IFX_SE_SUCCESS;
    }

    return status;
}

static ifx_se_status_t ifx_se_pqc_get_wc_status(int wc_ret)
{
    ifx_se_status_t status = IFX_SE_ERROR_INVALID_ARGUMENT;

    switch (wc_ret)
    {
        case 0:
            status = IFX_SE_SUCCESS;
            break;
        case BUFFER_E:
            status = IFX_SE_ERROR_BUFFER_TOO_SMALL;
            break;
        case MEMORY_E:
            status = IFX_SE_ERROR_INSUFFICIENT_MEMORY;
            break;
        case NOT_COMPILED_IN:
            status = IFX_SE_ERROR_NOT_SUPPORTED;
            break;
        case BAD_STATE_E:
            status = IFX_SE_ERROR_BAD_STATE;
            break;
        case SIG_VERIFY_E:
            status = IFX_SE_ERROR_INVALID_SIGNATURE;
            break;
        default:
            break;
    }

    return status;
}

static int ifx_se_pqc_hash_to_wc_type(ifx_se_alg_fih_t alg)
{
    int hash_type = WC_HASH_TYPE_NONE;
    uint32_t my_alg = ifx_se_fih_uint_decode(alg);

    if (IFX_SE_ALG_IS_HASH_ML_DSA(my_alg))
    {
        switch (IFX_SE_ALG_HMAC_GET_HASH(my_alg))
        {
            case IFX_SE_ALG_SHA_256:
                hash_type = WC_HASH_TYPE_SHA256;
                break;
            case IFX_SE_ALG_SHA_384:
                hash_type = WC_HASH_TYPE_SHA384;
                break;
            case IFX_SE_ALG_SHA_512:
                hash_type = WC_HASH_TYPE_SHA512;
                break;
            case IFX_SE_ALG_SHA3_256:
                hash_type = WC_HASH_TYPE_SHA3_256;
                break;
            case IFX_SE_ALG_SHA3_384:
                hash_type = WC_HASH_TYPE_SHA3_384;
                break;
            case IFX_SE_ALG_SHA3_512:
                hash_type = WC_HASH_TYPE_SHA3_512;
                break;
            default:
                break;
        }
    }

    return hash_type;
}

static int ifx_se_pqc_get_mldsa_level(const ifx_se_key_attributes_t *attributes)
{
    int mldsa_key_level = WC_ML_DSA_87;

    switch (ifx_se_get_key_bits(attributes))
    {
        case 128:
            mldsa_key_level = WC_ML_DSA_44;
            break;
        case 192:
            mldsa_key_level = WC_ML_DSA_65;
            break;
        default:
            break;
    }

    return mldsa_key_level;
}

ifx_se_status_t ifx_se_pqc_export_public_key(
    ifx_se_key_id_fih_t key,
    ifx_se_fih_ptr_t data,
    ifx_se_fih_t data_size,
    ifx_se_fih_ptr_t data_length)
{
    ifx_se_status_t status = IFX_SE_ERROR_INVALID_HANDLE;
    ifx_se_storage_key_slot_t *slot;

    uint8_t *key_data = (uint8_t *)ifx_se_fih_ptr_decode(data);
    size_t *key_data_length = (size_t *)ifx_se_fih_ptr_decode(data_length);

    /* Look up the corresponding operation context */
    status = ifx_se_storage_key_slot_lookup(ifx_se_fih_uint_decode(key.key_id), &slot);

    if (ifx_se_fih_uint_eq(status, IFX_SE_SUCCESS))
    {
        status = IFX_SE_ERROR_NOT_PERMITTED;

        if ((slot->attributes.policy.usage & IFX_SE_KEY_USAGE_EXPORT) == IFX_SE_KEY_USAGE_EXPORT)
        {
            if (slot->attributes.type == IFX_SE_KEY_TYPE_ML_DSA_KEY_PAIR)
            {
                status = IFX_SE_ERROR_INSUFFICIENT_MEMORY;

                dilithium_key *mldsa_key = (dilithium_key *)calloc(1u, sizeof(dilithium_key));
                if (mldsa_key != NULL)
                {
                    size_t pub_key_size = DILITHIUM_LEVEL5_PUB_KEY_SIZE;
                    uint8_t *pub_key = (uint8_t *)calloc(1u, DILITHIUM_LEVEL5_PUB_KEY_SIZE);
                    if (pub_key != NULL)
                    {
                        status = ifx_se_pqc_get_wc_status(wc_dilithium_init(mldsa_key));
                        if (ifx_se_fih_uint_eq(status, IFX_SE_SUCCESS))
                        {
                            status = ifx_se_pqc_get_wc_status(wc_dilithium_set_level(mldsa_key,
                                                                                    (byte)ifx_se_pqc_get_mldsa_level(&slot->attributes)));
                        }
                        if (ifx_se_fih_uint_eq(status, IFX_SE_SUCCESS))
                        {
                            status = ifx_se_pqc_get_wc_status(wc_dilithium_make_key_from_seed(mldsa_key,
                                                                                              (const byte*)slot->data));
                        }
                        if (ifx_se_fih_uint_eq(status, IFX_SE_SUCCESS))
                        {
                            /* Export public key. */
                            status = ifx_se_pqc_get_wc_status(wc_dilithium_export_public(mldsa_key, pub_key, &pub_key_size));
                        }
                        if (ifx_se_fih_uint_eq(status, IFX_SE_SUCCESS))
                        {
                            if (ifx_se_fih_uint_decode(data_size) >= pub_key_size)
                            {
                                memcpy(key_data, pub_key, pub_key_size);
                                *key_data_length = pub_key_size;

                                status = IFX_SE_SUCCESS;
                            }
                        }
                        
                        free(pub_key);
                        wc_dilithium_free(mldsa_key);
                    }
                    
                    free(mldsa_key);
                }
            }
            else
            {
                status = ifx_se_storage_export_key(key, data, data_size, data_length);  
            }
        }
    }

    return status;
}

ifx_se_status_t ifx_se_pqc_generate_key(
    const ifx_se_key_attributes_t *attributes,
    ifx_se_fih_ptr_t key,
    void *ctx)
{
    ifx_se_status_t status = IFX_SE_ERROR_INVALID_ARGUMENT;

    if (attributes != NULL)
    {
        uint8_t seed[DILITHIUM_SEED_SZ + IFX_CRC32_CRC_SIZE];

        ifx_se_key_type_t key_type = ifx_se_get_key_type(attributes);
        if (key_type == IFX_SE_KEY_TYPE_ML_DSA_KEY_PAIR)
        {
            status = ifx_se_pqc_get_random(ifx_se_fih_ptr_encode(seed),
                                           ifx_se_fih_uint_encode(sizeof(seed)),
                                           ctx);

            if (ifx_se_fih_uint_eq(status, IFX_SE_SUCCESS))
            {
                status = ifx_se_storage_import_key(attributes,
                                                   ifx_se_fih_ptr_encode(seed),
                                                   ifx_se_fih_uint_encode(sizeof(seed)),
                                                   key);
            }
        }
    }

    return status;
}

bool ifx_se_is_key_type_pqc(const ifx_se_key_attributes_t *attributes)
{
    if (IFX_SE_KEY_TYPE_IS_ML_DSA(ifx_se_get_key_type(attributes)) &&
        IFX_SE_ALG_IS_HASH_ML_DSA(ifx_se_get_key_algorithm(attributes)))
    {
        return true;
    }

    return false;
}

bool ifx_se_is_key_id_pqc(ifx_se_key_id_fih_t key)
{
    if ((key.key_id.val >= IFX_SE_KEY_ID_PQC_MIN) &&
        (key.key_id.val <= IFX_SE_KEY_ID_PQC_MAX))
    {
        return true;
    }

    return false;
}

ifx_se_status_t ifx_se_pqc_sign_hash(
    ifx_se_key_id_fih_t key,
    ifx_se_alg_fih_t alg,
    const ifx_se_fih_ptr_t hash,
    ifx_se_fih_t hash_length,
    const ifx_se_fih_ptr_t signature,
    ifx_se_fih_t signature_size,
    ifx_se_fih_ptr_t signature_length,
    void *ctx)
{
    ifx_se_status_t status = IFX_SE_ERROR_INVALID_HANDLE;
    uint8_t *key_data;
    size_t key_data_length = 0u;
    ifx_se_key_attributes_t attributes = IFX_SE_KEY_ATTRIBUTES_INIT;

    status = ifx_se_storage_get_key(key, ifx_se_fih_ptr_encode(&key_data), ifx_se_fih_ptr_encode(&key_data_length), &attributes);

    if (ifx_se_fih_uint_eq(status, IFX_SE_SUCCESS))
    {
        int hash_type = ifx_se_pqc_hash_to_wc_type(alg);
        ifx_se_key_type_t key_type = ifx_se_get_key_type(&attributes);
        int mldsa_key_level = ifx_se_pqc_get_mldsa_level(&attributes);

        status = IFX_SE_ERROR_INVALID_ARGUMENT;

        if ((hash_type != WC_HASH_TYPE_NONE) &&
            (key_type == IFX_SE_KEY_TYPE_ML_DSA_KEY_PAIR) &&
            (key_data_length == DILITHIUM_SEED_SZ))
        {
            status = IFX_SE_ERROR_INSUFFICIENT_MEMORY;

            word32 sig_len = (word32)ifx_se_fih_uint_decode(signature_size);
            dilithium_key *mldsa_key = (dilithium_key *)calloc(1u, sizeof(dilithium_key));

            if (mldsa_key != NULL)
            {
                status = ifx_se_pqc_get_wc_status(wc_dilithium_init(mldsa_key));
                if (ifx_se_fih_uint_eq(status, IFX_SE_SUCCESS))
                {
                    status = ifx_se_pqc_get_wc_status(wc_dilithium_set_level(mldsa_key, (byte)mldsa_key_level));
                }
                if (ifx_se_fih_uint_eq(status, IFX_SE_SUCCESS))
                {
                    status = ifx_se_pqc_get_wc_status(wc_dilithium_make_key_from_seed(mldsa_key, (const byte *)key_data));
                }
                if (ifx_se_fih_uint_eq(status, IFX_SE_SUCCESS))
                {
                    uint8_t sign_seed[DILITHIUM_RND_SZ + IFX_CRC32_CRC_SIZE];

                    status = ifx_se_pqc_get_random(ifx_se_fih_ptr_encode(sign_seed),
                                                   ifx_se_fih_uint_encode(sizeof(sign_seed)),
                                                   ctx);

                    if (ifx_se_fih_uint_eq(status, IFX_SE_SUCCESS))
                    {
                        status = ifx_se_pqc_get_wc_status(wc_dilithium_sign_ctx_hash_with_seed(
                                NULL, 0u, hash_type,
                                (const byte *)ifx_se_fih_ptr_decode(hash),
                                (word32)ifx_se_fih_uint_decode(hash_length),
                                (byte *)ifx_se_fih_ptr_decode(signature),
                                &sig_len,
                                mldsa_key,
                                (const byte *)sign_seed));
                    }
                    if (ifx_se_fih_uint_eq(status, IFX_SE_SUCCESS))
                    {
                        size_t *sig_len_out = (size_t *)ifx_se_fih_ptr_decode(signature_length);
                        if (sig_len_out != NULL)
                        {
                            *sig_len_out = (size_t)sig_len;

                            status = IFX_SE_SUCCESS;
                        }
                    }
                }

                wc_dilithium_free(mldsa_key);
                free(mldsa_key);
            }
        }
    }

    return status;
}

ifx_se_status_t ifx_se_pqc_verify_hash(
    ifx_se_key_id_fih_t key,
    ifx_se_alg_fih_t alg,
    const ifx_se_fih_ptr_t hash,
    ifx_se_fih_t hash_length,
    const ifx_se_fih_ptr_t signature,
    ifx_se_fih_t signature_length)
{
    ifx_se_status_t status = IFX_SE_ERROR_INVALID_HANDLE;

    uint8_t *key_data;
    size_t key_data_length = 0u;
    ifx_se_key_attributes_t attributes = IFX_SE_KEY_ATTRIBUTES_INIT;

    status = ifx_se_storage_get_key(key, ifx_se_fih_ptr_encode(&key_data), ifx_se_fih_ptr_encode(&key_data_length), &attributes);

    if (ifx_se_fih_uint_eq(status, IFX_SE_SUCCESS))
    {
        int hash_type = ifx_se_pqc_hash_to_wc_type(alg);
        ifx_se_key_type_t key_type = ifx_se_get_key_type(&attributes);
        int mldsa_key_level = ifx_se_pqc_get_mldsa_level(&attributes);

        status = IFX_SE_ERROR_INVALID_ARGUMENT;

        if ((key_type == IFX_SE_KEY_TYPE_ML_DSA_KEY_PAIR) && (key_data_length != DILITHIUM_SEED_SZ))
        {
            hash_type = WC_HASH_TYPE_NONE;
        }

        if (hash_type != WC_HASH_TYPE_NONE)
        {
            status = IFX_SE_ERROR_INSUFFICIENT_MEMORY;

            volatile int res = -1;

            dilithium_key *mldsa_key = (dilithium_key *)calloc(1u, sizeof(dilithium_key));
            if (mldsa_key != NULL)
            {
                status = ifx_se_pqc_get_wc_status(wc_dilithium_init(mldsa_key));
                if (ifx_se_fih_uint_eq(status, IFX_SE_SUCCESS))
                {
                    status = ifx_se_pqc_get_wc_status(wc_dilithium_set_level(mldsa_key, (byte)mldsa_key_level));
                }
                if (ifx_se_fih_uint_eq(status, IFX_SE_SUCCESS))
                {
                    if (key_type == IFX_SE_KEY_TYPE_ML_DSA_KEY_PAIR)
                    {
                        status = ifx_se_pqc_get_wc_status(wc_dilithium_make_key_from_seed(mldsa_key,
                                                                (const byte*)key_data));
                    }
                    else
                    {
                        status = ifx_se_pqc_get_wc_status(wc_dilithium_import_public((const byte*)key_data,
                                                        (word32)key_data_length,
                                                        mldsa_key));
                    }
                }
                if (ifx_se_fih_uint_eq(status, IFX_SE_SUCCESS))
                {
                    status = ifx_se_pqc_get_wc_status(wc_dilithium_verify_ctx_hash(
                                (const byte*)ifx_se_fih_ptr_decode(signature),
                                (word32)ifx_se_fih_uint_decode(signature_length),
                                 NULL, 0, hash_type,
                                (const byte*)ifx_se_fih_ptr_decode(hash),
                                (word32)ifx_se_fih_uint_decode(hash_length),
                                (int *)&res, mldsa_key));
                }
                if (ifx_se_fih_uint_eq(status, IFX_SE_SUCCESS))
                {
                    status = IFX_SE_ERROR_INVALID_SIGNATURE;

                    if (res == 1)
                    {
                        (void)ifx_se_fih_delay();

                        if (res == 1)
                        {
                            status = IFX_SE_SUCCESS;
                        }
                    }
                }

                wc_dilithium_free(mldsa_key);
                free(mldsa_key);
            }
        }
    }

    return status;
}

#endif /* COMPONENT_MW_WOLFSSL */
