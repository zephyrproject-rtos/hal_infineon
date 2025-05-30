/***************************************************************************//**
* \file cy_crypto_core_sha_v2.h
* \version 2.150
*
* \brief
*  This file provides constants and function prototypes
*  for the API for the SHA method in the Crypto block driver.
*
********************************************************************************
* \copyright
* Copyright (c) (2020-2024), Cypress Semiconductor Corporation (an Infineon company) or
* an affiliate of Cypress Semiconductor Corporation.
* SPDX-License-Identifier: Apache-2.0
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*    http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/


#if !defined (CY_CRYPTO_CORE_SHA_V2_H)
#define CY_CRYPTO_CORE_SHA_V2_H

#include "cy_crypto_common.h"

#if defined(CY_IP_MXCRYPTO) && defined(CY_CRYPTO_CFG_HW_V2_ENABLE)

#if defined(__cplusplus)
extern "C" {
#endif

#if (CPUSS_CRYPTO_SHA == 1) && defined(CY_CRYPTO_CFG_SHA_C)

/** \cond INTERNAL */

#if (CPUSS_CRYPTO_SHA1 == 1) && defined(CY_CRYPTO_CFG_SHA1_ENABLED)
typedef struct
{
    /* Allocates CRYPTO_MAX_BLOCK_SIZE Bytes for the block. */
    uint32_t block[CY_CRYPTO_ALIGN_CACHE_LINE_WORD(CY_CRYPTO_SHA1_BLOCK_SIZE / 4u)];
    /* Allocates CRYPTO_MAX_HASH_SIZE Bytes for the hash. */
     uint32_t hash[CY_CRYPTO_ALIGN_CACHE_LINE_WORD(CY_CRYPTO_SHA1_HASH_SIZE / 4u)];
} cy_stc_crypto_v2_sha1_buffers_t;
#endif /* (CPUSS_CRYPTO_SHA1 == 1) && defined(CY_CRYPTO_CFG_SHA1_ENABLED) */

#if (CPUSS_CRYPTO_SHA256 == 1) && defined(CY_CRYPTO_CFG_SHA2_256_ENABLED)
typedef struct
{
    /* Allocates CRYPTO_MAX_BLOCK_SIZE Bytes for the block. */
    uint32_t block[CY_CRYPTO_ALIGN_CACHE_LINE_WORD(CY_CRYPTO_SHA256_BLOCK_SIZE / 4u)];
    /* Allocates CRYPTO_MAX_HASH_SIZE Bytes for the hash. */
    uint32_t hash[CY_CRYPTO_ALIGN_CACHE_LINE_WORD(CY_CRYPTO_SHA256_HASH_SIZE / 4u)];
} cy_stc_crypto_v2_sha256_buffers_t;
#endif /* (CPUSS_CRYPTO_SHA256 == 1) && defined(CY_CRYPTO_CFG_SHA2_256_ENABLED) */

#if (CPUSS_CRYPTO_SHA512 == 1) && defined(CY_CRYPTO_CFG_SHA2_512_ENABLED)
 typedef struct
{
    /* Allocates CRYPTO_MAX_BLOCK_SIZE Bytes for the block. */
    uint32_t block[CY_CRYPTO_ALIGN_CACHE_LINE_WORD(CY_CRYPTO_SHA512_BLOCK_SIZE / 4u)];
    /* Allocates CRYPTO_MAX_HASH_SIZE Bytes for the hash. */
    uint32_t hash[CY_CRYPTO_ALIGN_CACHE_LINE_WORD(CY_CRYPTO_SHA512_HASH_SIZE / 4u)];
} cy_stc_crypto_v2_sha512_buffers_t;
#endif /* (CPUSS_CRYPTO_SHA512 == 1) && defined(CY_CRYPTO_CFG_SHA2_512_ENABLED) */

#if (CPUSS_CRYPTO_SHA3 == 1) && defined(CY_CRYPTO_CFG_SHA3_ENABLED)
typedef struct
{
    /* Allocates CY_CRYPTO_SHA3_STATE_SIZE for the hash state. */
    uint8_t hash[CY_CRYPTO_ALIGN_CACHE_LINE(CY_CRYPTO_SHA3_STATE_SIZE)];
} cy_stc_crypto_v2_sha3_buffers_t;
#endif /* (CPUSS_CRYPTO_SHA3 == 1) && defined(CY_CRYPTO_CFG_SHA3_ENABLED) */

 typedef struct
{
    /* Allocates CRYPTO_MAX_BLOCK_SIZE Bytes for the block. */
    uint32_t block[CY_CRYPTO_ALIGN_CACHE_LINE_WORD(CY_CRYPTO_SHA_MAX_BLOCK_SIZE / 4u)];
    uint32_t hash[CY_CRYPTO_ALIGN_CACHE_LINE_WORD(CY_CRYPTO_SHA_MAX_HASH_SIZE / 4u)];
} cy_stc_crypto_v2_sha_buffers_t;


cy_en_crypto_status_t Cy_Crypto_Core_V2_Sha_Init(CRYPTO_Type *base,
                                cy_stc_crypto_sha_state_t *hashState,
                                cy_en_crypto_sha_mode_t mode,
                                void *shaBuffers);

cy_en_crypto_status_t Cy_Crypto_Core_V2_Sha_Start(CRYPTO_Type *base, cy_stc_crypto_sha_state_t *hashState);

cy_en_crypto_status_t Cy_Crypto_Core_V2_Sha_Update(CRYPTO_Type *base,
                                cy_stc_crypto_sha_state_t *hashState,
                                uint8_t const *message,
                                uint32_t messageSize);

cy_en_crypto_status_t Cy_Crypto_Core_V2_Sha_Finish(CRYPTO_Type *base,
                                cy_stc_crypto_sha_state_t *hashState,
                                uint8_t *digest);

cy_en_crypto_status_t Cy_Crypto_Core_V2_Sha_Free(CRYPTO_Type *base, cy_stc_crypto_sha_state_t *hashState);

cy_en_crypto_status_t Cy_Crypto_Core_V2_Sha(CRYPTO_Type *base,
                                uint8_t const *message,
                                uint32_t messageSize,
                                uint8_t *digest,
                                cy_en_crypto_sha_mode_t mode);

/** \endcond */


#endif /* (CPUSS_CRYPTO_SHA == 1) && defined(CY_CRYPTO_CFG_SHA_C) */

#if defined(__cplusplus)
}
#endif

#endif /* defined(CY_IP_MXCRYPTO) && defined(CY_CRYPTO_CFG_HW_V2_ENABLE) */

#endif /* #if !defined (CY_CRYPTO_CORE_SHA_V2_H) */


/* [] END OF FILE */
