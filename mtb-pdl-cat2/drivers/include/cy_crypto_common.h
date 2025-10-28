/***************************************************************************//**
* \file cy_crypto_common.h
* \version 1.0.1
*
* \brief
*  This file provides common constants and parameters for the Crypto driver.
*
*******************************************************************************
* \copyright
* (c) (2016-2021), Cypress Semiconductor Corporation (an Infineon company) or
* an affiliate of Cypress Semiconductor Corporation.
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

#if !defined(CY_CRYPTO_COMMON_H)
#define CY_CRYPTO_COMMON_H

#include "cy_device.h"

#if defined(CY_IP_M0S8CRYPTO)

#include "cy_syslib.h"

#if defined(__cplusplus)
extern "C" {
#endif

/**
* \addtogroup group_crypto_macros
* \{
*/

/** Driver major version */
#define CY_CRYPTO_DRV_VERSION_MAJOR         1

/** Driver minor version */
#define CY_CRYPTO_DRV_VERSION_MINOR         0

#if defined (CRYPTO_AES) || defined (CY_DOXYGEN)
/** Crypto AES block size (in bytes) */
#define CY_CRYPTO_AES_BLOCK_SIZE          (16U)

/** Crypto AES_128 key size (in bytes) */
#define CY_CRYPTO_AES_128_KEY_SIZE        (16U)

/** Crypto AES_192 key size (in bytes) */
#define CY_CRYPTO_AES_192_KEY_SIZE        (24U)

/** Crypto AES_256 key size (in bytes) */
#define CY_CRYPTO_AES_256_KEY_SIZE        (32U)

/** Crypto AES maximum key size (in bytes) */
#define CY_CRYPTO_AES_MAX_KEY_SIZE        (CY_CRYPTO_AES_256_KEY_SIZE)

/** Crypto AES maximum key size (in four-byte words) */
#define CY_CRYPTO_AES_MAX_KEY_SIZE_U32    (uint32_t)(CY_CRYPTO_AES_MAX_KEY_SIZE / 4UL)

/** AES block size in four-byte words */
#define CY_CRYPTO_AES_BLOCK_SIZE_U32      (uint32_t)(CY_CRYPTO_AES_BLOCK_SIZE / 4UL)

#endif

#if defined (CRYPTO_SHA) || defined (CY_DOXYGEN)
/* Defines for the SHA algorithm */

/** Hash size for SHA1 mode (in bytes)   */
#define CY_CRYPTO_SHA1_DIGEST_SIZE          (20U)
/** Hash size for SHA224 mode (in bytes) */
#define CY_CRYPTO_SHA224_DIGEST_SIZE        (28U)
/** Hash size for SHA256 mode (in bytes) */
#define CY_CRYPTO_SHA256_DIGEST_SIZE        (32U)
/** Maximal hash size for SHA modes (in bytes) */
#define CY_CRYPTO_SHA_MAX_DIGEST_SIZE       (CY_CRYPTO_SHA256_DIGEST_SIZE)

/** Block size for SHA1 mode (in bytes)  */
#define CY_CRYPTO_SHA1_BLOCK_SIZE           (64U)
/** Block size for SHA256 mode (in bytes)   */
#define CY_CRYPTO_SHA256_BLOCK_SIZE         (64U)
/** Maximal block size for SHA modes (in bytes)   */
#define CY_CRYPTO_SHA_MAX_BLOCK_SIZE        (CY_CRYPTO_SHA256_BLOCK_SIZE)

/** Hash size for SHA1 mode (in bytes)  */
#define CY_CRYPTO_SHA1_HASH_SIZE            (20U)
/** Hash size for SHA256 mode (in bytes)  */
#define CY_CRYPTO_SHA256_HASH_SIZE          (32U)
/** Maximal hash size for SHA modes (in bytes)   */
#define CY_CRYPTO_SHA_MAX_HASH_SIZE         (CY_CRYPTO_SHA256_HASH_SIZE)

#endif

/** \cond INTERNAL */

/* Width of the Crypto hardware registers values in bits */
#define CY_CRYPTO_HW_REGS_WIDTH             (32UL)

/* Calculates the actual size in bytes of the bits value */
#define CY_CRYPTO_BYTE_SIZE_OF_BITS(x)      (uint32_t)(((uint32_t)(x) + 7U) >> 3U)

/* Calculates the actual size in 32-bit words of the bits value */
#define CY_CRYPTO_WORD_SIZE_OF_BITS(x)      (uint32_t)(((uint32_t)(x) + 31U) >> 5U)

/** \endcond */


/** Crypto Driver PDL ID */
#define CY_CRYPTO_ID                        CY_PDL_DRV_ID(0x0CU)

/** \} group_crypto_macros */

/**
* \addtogroup group_crypto_enums
* \{
*/

#if defined (CRYPTO_AES) || defined (CY_DOXYGEN)
/** Key length options for the AES method */
typedef enum
{
    CY_CRYPTO_KEY_AES_128   = 0x00U,   /**< The AES key size is 128 bits */
    CY_CRYPTO_KEY_AES_192   = 0x01U,   /**< The AES key size is 192 bits */
    CY_CRYPTO_KEY_AES_256   = 0x02U    /**< The AES key size is 256 bits */
} cy_en_crypto_aes_key_length_t;

/** Direction of Crypto methods */
typedef enum
{
    /** Forward mode; plain text will be encrypted into cipher text */
    CY_CRYPTO_ENCRYPT   = 0x00U,
    /** Reverse mode; cipher text will be decrypted into plain text */
    CY_CRYPTO_DECRYPT   = 0x01U
} cy_en_crypto_dir_mode_t;
#endif

#if defined (CRYPTO_SHA) || defined (CY_DOXYGEN)
/** SHA method modes */
typedef enum
{
    CY_CRYPTO_MODE_SHA1          = 0x00U,   /**< Sets SHA1 mode */
    CY_CRYPTO_MODE_SHA224        = 0x01U,   /**< Sets SHA224 mode */
    CY_CRYPTO_MODE_SHA256        = 0x02U,   /**< Sets SHA256 mode */
} cy_en_crypto_sha_mode_t;
#endif

/** Crypto block errors */
typedef enum
{
    /** Operation completed successfully */
    CY_CRYPTO_SUCCESS             = 0x00U,

    /** A hardware error occurred */
    CY_CRYPTO_HW_ERROR            = CY_CRYPTO_ID | CY_PDL_STATUS_ERROR | 0x01U,

    /** Size of input data is not multiple of 16 */
    CY_CRYPTO_SIZE_NOT_X16        = CY_CRYPTO_ID | CY_PDL_STATUS_ERROR | 0x02U,

    /** Crypto driver is not initialized */
    CY_CRYPTO_NOT_INITIALIZED     = CY_CRYPTO_ID | CY_PDL_STATUS_ERROR | 0x03U,

    /** Crypto hardware is not enabled */
    CY_CRYPTO_HW_NOT_ENABLED      = CY_CRYPTO_ID | CY_PDL_STATUS_ERROR | 0x04U,

    /** Crypto operation is not supported */
    CY_CRYPTO_NOT_SUPPORTED       = CY_CRYPTO_ID | CY_PDL_STATUS_ERROR | 0x05U,

    /** Crypto operation parameters are incorrect */
    CY_CRYPTO_BAD_PARAMS          = CY_CRYPTO_ID | CY_PDL_STATUS_ERROR | 0x06U,

    /** Crypto operation is invalid **/
    CY_CRYPTO_INVALID_OPERATION   = CY_CRYPTO_ID | CY_PDL_STATUS_WARNING | 0x08U,

    /** Unknown error */
    CY_CRYPTO_UNKNOWN             = CY_CRYPTO_ID | CY_PDL_STATUS_ERROR | 0xFFU
} cy_en_crypto_status_t;

#if defined (CRYPTO_CRC) || defined (CY_DOXYGEN)
/** \cond INTERNAL */
/** Internal processing states of the CRC operation */
typedef enum
{
    CY_CRYPTO_CRC_INITIALIZED          = 0x01U,   /**< CRC operation is initialized */
    CY_CRYPTO_CRC_PARTIAL_PROCESSED    = 0x02U,   /**< CRC message partially processed */
    CY_CRYPTO_CRC_FINISHED             = 0x03U,   /**< CRC operation is completed */
} cy_en_crypto_crc_process_state_t;
/** \endcond */
#endif

#if defined (CRYPTO_SHA) || defined (CY_DOXYGEN)
/** \cond INTERNAL */
/** Internal processing states of the SHA operation */
typedef enum
{
    CY_CRYPTO_SHA_INITIALIZED          = 0x01U,   /**< SHA operation is initialized */
    CY_CRYPTO_SHA_PARTIAL_PROCESSED    = 0x02U,   /**< SHA message partially processed */
    CY_CRYPTO_SHA_FINISHED             = 0x03U,   /**< SHA operation is completed */
} cy_en_crypto_sha_process_state_t;
/** \endcond */
#endif
/** \} group_crypto_enums */

/**
* \addtogroup group_crypto_structures
* \{
*/
#if defined (CRYPTO_AES) || defined (CY_DOXYGEN)
/** Structure for storing the AES context.
* All fields for this structure are internal. Firmware never reads or
* writes these values. Firmware allocates the structure and provides the
* address of the structure to the driver in the function calls. Firmware must
* ensure that the defined instance of this structure remains in the scope
* while the driver is in use.
*/

typedef struct
{
    /** \cond INTERNAL */
    /** AES key length */
    cy_en_crypto_aes_key_length_t keyLength;
    /** AES key */
    uint32_t key[CY_CRYPTO_AES_MAX_KEY_SIZE_U32];
    /** AES Invert key */
    uint32_t keyInv[CY_CRYPTO_AES_MAX_KEY_SIZE_U32];
    /** \endcond */
} cy_stc_crypto_aes_context_t;
#endif

#if defined (CRYPTO_SHA) || defined (CY_DOXYGEN)
/** Structure for storing the SHA context.
* All fields in this structure are internal. Firmware never reads or
* writes these values. Firmware allocates the structure and provides the
* address of the structure to the driver in the function calls. Firmware must
* ensure that the defined instance of this structure remains in the scope
* while the driver is in use.
*/
typedef struct
{
    /** \cond INTERNAL */
    uint32_t mode;
    uint32_t modeHw;
    uint8_t  block[CY_CRYPTO_SHA_MAX_BLOCK_SIZE];
    uint32_t blockSize;
    uint8_t  hash[CY_CRYPTO_SHA_MAX_HASH_SIZE];
    uint32_t hashSize;
    uint32_t messageSize;
    uint32_t digestSize;
    uint32_t blockIdx;
    uint8_t  const *initialHash;
    cy_en_crypto_sha_process_state_t processState;
    /** \endcond */
} cy_stc_crypto_sha_context_t;
#endif

#if defined (CRYPTO_CRC) || defined (CY_DOXYGEN)
/** Structure for storing the CRC context.
* All fields for this structure are internal. Firmware never reads or
* writes these values. Firmware allocates the structure and provides the
* address of the structure to the driver in the function calls. Firmware must
* ensure that the defined instance of this structure remains in the scope
* while the driver is in use.
*/

typedef struct
{
    /** \cond INTERNAL */
    uint32_t width;
    uint32_t polynomial;
    uint32_t dataReverse;
    uint32_t dataXor;
    uint32_t remReverse;
    uint32_t remXor;
    uint32_t lfsrInitState;
    uint32_t crc;
    cy_en_crypto_crc_process_state_t processState;
    /** \endcond */
} cy_stc_crypto_crc_context_t;
#endif
/** \} group_crypto_data_structures */

#if defined(__cplusplus)
}
#endif

#endif /* defined(CY_IP_M0S8CRYPTO) */

#endif /* #if !defined(CY_CRYPTO_COMMON_H) */


/* [] END OF FILE */
