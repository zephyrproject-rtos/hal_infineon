/***************************************************************************//**
* \file cy_cryptolite_common.h
* \version 1.40
*
* \brief
*  This file provides common constants and parameters for the Cryptolite driver.
*
*******************************************************************************
* \copyright
* (c) (2021-2025), Cypress Semiconductor Corporation (an Infineon company) or
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

#if !defined(CY_CRYPTOLITE_COMMON_H)
#define CY_CRYPTOLITE_COMMON_H

#include "cy_device.h"

#if defined(CY_IP_M0S8CRYPTOLITE)

#include "cy_syslib.h"

#if defined(__cplusplus)
extern "C" {
#endif

/**
* \addtogroup group_cryptolite_common
* \{
* Cryptolite Common.
* This file contains all the necessary Macros, Structure and Enum definition required
* by the cryptolite driver.
*
* \defgroup group_cryptolite_common_macros Macros
* \defgroup group_cryptolite_common_enums Enums
*
* */

/** \} group_cryptolite_common */

/** @cond DOXYGEN_HIDE */
/* SROM Code specific macros. */
#ifndef ATTRIBUTES_CRYPTOLITE_SHA
#define ATTRIBUTES_CRYPTOLITE_SHA
#endif /* ATTRIBUTES_CRYPTOLITE_SHA */

#ifndef CRYPTOLITE_SHA_CONST
#define CRYPTOLITE_SHA_CONST
#endif /* CRYPTOLITE_SHA_CONST */

#ifndef CRYPTOLITE_SHA_CALL_MAP
#define CRYPTOLITE_SHA_CALL_MAP(func_name)  func_name
#endif /* CRYPTOLITE_SHA_CALL_MAP */

#ifndef ATTRIBUTES_CRYPTOLITE_RSA
#define ATTRIBUTES_CRYPTOLITE_RSA
#endif /* ATTRIBUTES_CRYPTOLITE_RSA */

#ifndef CRYPTOLITE_RSA_CALL_MAP
#define CRYPTOLITE_RSA_CALL_MAP(func_name)  func_name
#endif /* CRYPTOLITE_RSA_CALL_MAP */

#ifndef SW_HASHING_ALG
#define SW_HASHING_ALG                 (0u)
#endif /* SW_HASHING_ALG */
/** @endcond */

/**
* \addtogroup group_cryptolite_common_macros
* \{
*/

/** Driver major version */
#define CY_CRYPTOLITE_DRV_VERSION_MAJOR         1

/** Driver minor version */
#define CY_CRYPTOLITE_DRV_VERSION_MINOR         40

/** \} group_cryptolite_common_macros */

#if defined (CRYPTOLITE_AES_PRESENT) || defined (CY_DOXYGEN)
/**
* \addtogroup group_cryptolite_aes_macros
* \{
*/

/** Crypto AES block size (in bytes) */
#define CY_CRYPTOLITE_AES_BLOCK_SIZE          (16U)

/** Crypto AES_128 key size (in bytes) */
#define CY_CRYPTOLITE_AES_128_KEY_SIZE        (16U)

/** Crypto AES maximum key size (in bytes) */
#define CY_CRYPTOLITE_AES_MAX_KEY_SIZE        (CY_CRYPTOLITE_AES_128_KEY_SIZE)

/** Crypto AES maximum key size (in four-byte words) */
#define CY_CRYPTOLITE_AES_MAX_KEY_SIZE_U32    (uint32_t)(CY_CRYPTOLITE_AES_MAX_KEY_SIZE / 4UL)

/** AES block size in four-byte words */
#define CY_CRYPTOLITE_AES_BLOCK_SIZE_U32      (uint32_t)(CY_CRYPTOLITE_AES_BLOCK_SIZE / 4UL)

/** \} group_cryptolite_aes_macros */

#endif /* defined (CRYPTOLITE_AES_PRESENT) || defined (CY_DOXYGEN) */

#if defined (CRYPTOLITE_SHA_PRESENT) || defined (CY_DOXYGEN)
/**
* \addtogroup group_cryptolite_sha_macros
* \{
*/
/* Defines for the SHA algorithm */
/** PAD size for the SHA256(in bytes)    */
#define CY_CRYPTOLITE_SHA256_PAD_SIZE           (56UL)
/** PAD size for the SHA384(in bytes)    */
#define CY_CRYPTOLITE_SHA384_PAD_SIZE           (112UL)
/** PAD size for the SHA512(in bytes)    */
#define CY_CRYPTOLITE_SHA512_PAD_SIZE           (112UL)

/** Hash size for SHA256 mode (in bytes) */
#define CY_CRYPTOLITE_SHA256_DIGEST_SIZE        (32UL)
/** Hash size for SHA384 mode (in bytes) */
#define CY_CRYPTOLITE_SHA384_DIGEST_SIZE        (48UL)
/** Hash size for SHA512 mode (in bytes) */
#define CY_CRYPTOLITE_SHA512_DIGEST_SIZE        (64UL)

/** Block size for SHA256 mode (in bytes)   */
#define CY_CRYPTOLITE_SHA256_BLOCK_SIZE         (64UL)
/** Block size for SHA384 mode (in bytes)   */
#define CY_CRYPTOLITE_SHA384_BLOCK_SIZE         (128UL)
/** Block size for SHA512 mode (in bytes)   */
#define CY_CRYPTOLITE_SHA512_BLOCK_SIZE         (128UL)

/** Maximal block size for SHA modes (in bytes)   */
#if ((defined (CRYPTOLITE_SHA512_PRESENT) && (CRYPTOLITE_SHA512_PRESENT)) || \
     (defined (CRYPTOLITE_SHA384_PRESENT) && (CRYPTOLITE_SHA384_PRESENT)))
#define CY_CRYPTOLITE_SHA_MAX_BLOCK_SIZE       (CY_CRYPTOLITE_SHA512_BLOCK_SIZE)
#else
#define CY_CRYPTOLITE_SHA_MAX_BLOCK_SIZE       (CY_CRYPTOLITE_SHA256_BLOCK_SIZE)
#endif /* ((defined (CRYPTOLITE_SHA512_PRESENT) && (CRYPTOLITE_SHA512_PRESENT)) || \
           (defined (CRYPTOLITE_SHA384_PRESENT) && (CRYPTOLITE_SHA384_PRESENT))) */

/** Block size for SHA modes (in 4-bytes word)   */
#define CY_CRYPTOLITE_SHA_MAX_BLOCK_SIZE_U32    (CY_CRYPTOLITE_SHA_MAX_BLOCK_SIZE / 4UL)

/** Hash size for SHA256 mode (in bytes)  */
#define CY_CRYPTOLITE_SHA256_HASH_SIZE          (32UL)
/** Hash size for SHA384 mode (in bytes)  */
#define CY_CRYPTOLITE_SHA384_HASH_SIZE          (64UL)
/** Hash size for SHA512 mode (in bytes)  */
#define CY_CRYPTOLITE_SHA512_HASH_SIZE          (64UL)

/** Maximal hash size for SHA modes (in bytes)   */
#if ((defined (CRYPTOLITE_SHA512_PRESENT) && (CRYPTOLITE_SHA512_PRESENT)) || \
     (defined (CRYPTOLITE_SHA384_PRESENT) && (CRYPTOLITE_SHA384_PRESENT)))
#define CY_CRYPTOLITE_SHA_MAX_HASH_SIZE         (CY_CRYPTOLITE_SHA512_HASH_SIZE)
#else
#define CY_CRYPTOLITE_SHA_MAX_HASH_SIZE         (CY_CRYPTOLITE_SHA256_HASH_SIZE)
#endif /* ((defined (CRYPTOLITE_SHA512_PRESENT) && (CRYPTOLITE_SHA512_PRESENT)) || \
           (defined (CRYPTOLITE_SHA384_PRESENT) && (CRYPTOLITE_SHA384_PRESENT))) */

/** Maximal hash size for SHA modes (in 4-bytes word)  */
#define CY_CRYPTOLITE_SHA_MAX_HASH_SIZE_U32     (CY_CRYPTOLITE_SHA_MAX_HASH_SIZE / 4UL)

/** Schedule buffer size for the SHA256(in 32-bit word)    */
#define CY_CRYPTOLITE_SHA256_SCHEDULE_SIZE  (64UL)
/** Schedule buffer size for the SHA384(in 32-bit word)    */
#define CY_CRYPTOLITE_SHA384_SCHEDULE_SIZE  (160UL)
/** Schedule buffer size for the SHA512(in 32-bit word)    */
#define CY_CRYPTOLITE_SHA512_SCHEDULE_SIZE  (160UL)

/** Max schedule buffer size for SHA (in 32-bit word)      */
#if ((defined (CRYPTOLITE_SHA512_PRESENT) && (CRYPTOLITE_SHA512_PRESENT)) || \
     (defined (CRYPTOLITE_SHA384_PRESENT) && (CRYPTOLITE_SHA384_PRESENT)))
#define CY_CRYPTOLITE_SHA_MAX_SCHEDULE_SIZE  (CY_CRYPTOLITE_SHA512_SCHEDULE_SIZE)
#else
#define CY_CRYPTOLITE_SHA_MAX_SCHEDULE_SIZE  (CY_CRYPTOLITE_SHA256_SCHEDULE_SIZE)
#endif /* ((defined (CRYPTOLITE_SHA512_PRESENT) && (CRYPTOLITE_SHA512_PRESENT)) || \
           (defined (CRYPTOLITE_SHA384_PRESENT) && (CRYPTOLITE_SHA384_PRESENT))) */

/** SHA message schedule function bit value. */
#define CY_CRYPTOLITE_MSG_SCH_CTLWD             (0UL << 28U)
/** SHA message process function bit value. */
#define CY_CRYPTOLITE_PROCESS_CTLWD             (1UL << 28U)

/** \} group_cryptolite_sha_macros */
#endif /* defined (CRYPTOLITE_SHA_PRESENT) || defined (CY_DOXYGEN) */

#if defined (CRYPTOLITE_VU_PRESENT) || defined (CY_DOXYGEN)
/**
* \addtogroup group_cryptolite_vu_macros
* \{
*/

/** Vector unit multiplication operation opcode. */
#define CY_CRYPTOLITE_VU_OPCODE_MUL                 (0UL)
/** Vector unit addition operation opcode. */
#define CY_CRYPTOLITE_VU_OPCODE_ADD                 (1UL)
/** Vector unit subtraction operation opcode. */
#define CY_CRYPTOLITE_VU_OPCODE_SUB                 (2UL)
/** Vector unit XOR operation opcode. */
#define CY_CRYPTOLITE_VU_OPCODE_XOR                 (3UL)
/** Vector unit long integer multiplication operation opcode. */
#define CY_CRYPTOLITE_VU_OPCODE_XMUL                (4UL)
/** Vector unit right shift by one bit operation opcode. */
#define CY_CRYPTOLITE_VU_OPCODE_LSR1                (5UL)
/** Vector unit left shift by one bit operation opcode. */
#define CY_CRYPTOLITE_VU_OPCODE_LSL1                (6UL)
/** Vector unit left shift operation on a given value opcode. */
#define CY_CRYPTOLITE_VU_OPCODE_LSR                 (7UL)
/** Vector unit conditional operation operation opcode. */
#define CY_CRYPTOLITE_VU_OPCODE_COND_SUB            (8UL)
/** Vector unit move/copy operation opcode. */
#define CY_CRYPTOLITE_VU_OPCODE_MOV                 (9UL)

/** Vector unit opcode bit position. */
#define CY_CRYPTOLITE_VU_BIT_POS_OPCODE             (28U)
/** Vector unit destination/result bit position. */
#define CY_CRYPTOLITE_VU_BIT_POS_DEST_OPERAND       (16U)
/** Vector unit arithmetic/logic operation first operand bit position. */
#define CY_CRYPTOLITE_VU_BIT_POS_OPERAND1           (8U)
/** Vector unit arithmetic/logic operation second operand bit position. */
#define CY_CRYPTOLITE_VU_BIT_POS_OPERAND0           (0U)

/** \} group_cryptolite_vu_macros */
#endif /* defined (CRYPTOLITE_VU_PRESENT) || defined (CY_DOXYGEN) */

#if defined(CRYPTOLITE_TRNG_PRESENT) || defined(CY_DOXYGEN)
/**
* \addtogroup group_cryptolite_trng_macros
* \{
*/

/** TRNG health monitor DAS bit stream selection. */
#define CY_CRYPTOLITE_TRNG_BITSTREAM_DAS            (0UL)
/** TRNG health monitor RED bit stream selection. */
#define CY_CRYPTOLITE_TRNG_BITSTREAM_RED            (1UL)
/** TRNG health monitor TR bit stream selection. */
#define CY_CRYPTOLITE_TRNG_BITSTREAM_TR             (2UL)

/** TRNG Adaptive Proportion (AP) test enable bit. */
#define CY_CRYPTOLITE_TRNG_AP_EN                    (1UL)
/** TRNG Repetition Count test enable bit. */
#define CY_CRYPTOLITE_TRNG_RC_EN                    (1UL)

/** \} group_cryptolite_trng_macros */

#endif /* defined(CRYPTOLITE_TRNG_PRESENT) || define(CY_DOXYGEN) */


/** \cond INTERNAL */

/* Width of the Crypto hardware registers values in bits */
#define CY_CRYPTOLITE_HW_REGS_WIDTH             (32UL)

/* Calculates the actual size in bytes of the bits value */
#define CY_CRYPTOLITE_BYTE_SIZE_OF_BITS(x)      (uint32_t)(((uint32_t)(x) + 7U) >> 3U)

/* Calculates the actual size in 32-bit words of the bits value */
#define CY_CRYPTOLITE_WORD_SIZE_OF_BITS(x)      (uint32_t)(((uint32_t)(x) + 31U) >> 5U)

/** \endcond */


/**
* \addtogroup group_cryptolite_common_macros
* \{
*/
/** Crypto Driver PDL ID */
#define CY_CRYPTOLITE_ID                        CY_PDL_DRV_ID(0x74U)

/** \} group_cryptolite_common_macros */
/**
* \addtogroup group_cryptolite_common_enums
* \{
*/

/** Crypto block errors */
typedef enum
{
    /** Operation completed successfully */
    CY_CRYPTOLITE_SUCCESS             = 0x00U,

    /** A hardware error occurred */
    CY_CRYPTOLITE_BUS_ERROR           = CY_CRYPTOLITE_ID | CY_PDL_STATUS_ERROR | 0x01U,

    /** Crypto operation parameters are incorrect */
    CY_CRYPTOLITE_BAD_PARAMS          = CY_CRYPTOLITE_ID | CY_PDL_STATUS_ERROR | 0x02U,

    /** Crypto operation is invalid **/
    CY_CRYPTOLITE_INVALID_OPERATION   = CY_CRYPTOLITE_ID | CY_PDL_STATUS_ERROR | 0x03U,

    /** Cryptolite HW block is busy **/
    CY_CRYPTOLITE_HW_BUSY             = CY_CRYPTOLITE_ID | CY_PDL_STATUS_WARNING | 0x04U,

    /** Cryptolite TRNG HW block AP or RC detected **/
    CY_CRYPTOLITE_TRNG_AP_RC_DETECTED = CY_CRYPTOLITE_ID | CY_PDL_STATUS_ERROR | 0x05U,
    
    /** Cryptolite RSA FW Signature verification failure **/
    CY_CRYPTOLITE_RSA_VERIFY_FAILURE  = CY_CRYPTOLITE_ID | CY_PDL_STATUS_ERROR | 0x06U,

    /** Unknown error */
    CY_CRYPTOLITE_UNKNOWN             = CY_CRYPTOLITE_ID | CY_PDL_STATUS_ERROR | 0xFFU
} cy_en_cryptolite_status_t;

/** \} group_cryptolite_common_enums */

#if defined (CRYPTOLITE_SHA_PRESENT) || defined (CY_DOXYGEN)
/**
* \addtogroup group_cryptolite_sha_enums
* \{
*/
/** SHA method modes */
typedef enum
{
    CY_CRYPTOLITE_SHA_MODE_SHA256           = 0x01U,   /**< Sets SHA256 mode */
    CY_CRYPTOLITE_SHA_MODE_SHA384           = 0x02U,   /**< Sets SHA384 mode */
    CY_CRYPTOLITE_SHA_MODE_SHA512           = 0x03U,   /**< Sets SHA512 mode */
} cy_en_cryptolite_sha_mode_t;

/** SHA internal operation states. */
typedef enum
{
    /** \cond INTERNAL */
    CY_CRYPTOLITE_SHA_PROCESS_INITIALIZED   = 0x01U,   /**< SHA operation is initialized */
    CY_CRYPTOLITE_SHA_PROCESS_STARTED       = 0x02U,   /**< SHA descriptor structure initialized. */
    CY_CRYPTOLITE_SHA_PROCESS_PARTIALLY     = 0x03U,   /**< SHA operation partially completed */
    CY_CRYPTOLITE_SHA_PROCESS_FINISHED      = 0x04U,   /**< SHA operation is completed */
    /** \endcond */
}cy_en_cryptolite_sha_process_state_t;
/** \} group_cryptolite_sha_enums */
#endif /* (CRYPTOLITE_SHA_PRESENT) || defined (CY_DOXYGEN) */

/** RSA PKCS#1 signature scheme encoding selection */
typedef enum
{
    CY_CRYPTOLITE_RSA_SSA_PKCS1_V15         = 0x00U,   /**< RSA SSA with PKCS#1 V1.5 Encoding */
    CY_CRYPTOLITE_RSA_SSA_PSS               = 0x01U,   /**< RSA SSA with PSS Encoding */
} cy_en_cryptolite_rsa_ssa_encoding_t;

#if defined (CRYPTOLITE_AES_PRESENT) || defined (CY_DOXYGEN)
/**
* \addtogroup group_cryptolite_aes_data_structures
* \{
*/
/** Structure for storing the AES descriptor.
* Pointer stored in this must be 4B aligned. This structure is used for
* Cryptolite IP only.
*/
typedef struct
{
    /** \cond INTERNAL */
    /** AES key pointer*/
    uint32_t keyAddr;
    /** AES source/plaintext pointer */
    uint32_t srcAddr;
    /** AES dest/plaintext pointer */
    uint32_t dstAddr;
    /** \endcond */
} cy_stc_cryptolite_aes_desc_t;

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
    /** AES key */
    uint32_t key[CY_CRYPTOLITE_AES_MAX_KEY_SIZE_U32];
    /** AES descriptor */
    cy_stc_cryptolite_aes_desc_t desc;
    /** \endcond */
} cy_stc_cryptolite_aes_context_t;

/** \} group_cryptolite_aes_data_structures */
#endif /* defined (CRYPTOLITE_AES_PRESENT) || defined (CY_DOXYGEN) */

#if defined (CRYPTOLITE_SHA_PRESENT) || defined (CY_DOXYGEN)
/**
* \addtogroup group_cryptolite_sha_data_structures
* \{
*/
/** The Cryptolite SHA256 IP descriptor structure.
* All fields for the structure are internal. Firmware never reads or
* writes these values.
*/
typedef struct
{
    /** \cond INTERNAL */
    /** Control word. */
    uint32_t data0;
    /** Pointer to message chunk (input) or current hash value (input) and new hash value (output)
      * based on Control Word (Schedule or Process control).
      */
    uint32_t data1;
    /** Pointer to message schedule array (output/input). */
    uint32_t data2;
   /** \endcond */
} cy_stc_cryptolite_sha_desc_t;

/** The structure for storing the SHA256 context.
* All fields for the context structure are internal. Firmware never reads or
* writes these values. Firmware allocates the structure and provides the
* address of the structure to the driver in the function calls. Firmware must
* ensure that the defined instance of this structure remains in scope
* while the drive is in use.
*/
typedef struct
{
    /** \cond INTERNAL */
    /** Internal buffer used in case of unaligned processing. */
    uint32_t block[CY_CRYPTOLITE_SHA_MAX_BLOCK_SIZE_U32];
    /** block size to be processed at each time. */
    uint32_t blockSize;
    /** Hash buffer used for storing Hash value during SHA calculation. */
    uint32_t hash[CY_CRYPTOLITE_SHA_MAX_HASH_SIZE_U32];
    /** Hash size to be used during the SHA calculation. */
    uint32_t hashSize;
    /** Buffer required by SHA module for processing. */
    uint32_t schedule[CY_CRYPTOLITE_SHA_MAX_SCHEDULE_SIZE];
    /** processed input message size. */
    uint32_t messageSize;
    /** processed input message index with in the message block. */
    uint32_t msgIdx;
    /** PAD size required as per SHA standard. */
    uint32_t paddSize;
    /** Actual Hash digest size. */
    uint32_t digestSize;
    /* Pointer to internal block in SHA driver to use in case of unaligned processing. */
    uint8_t *message;
    /** Pointer to initial Hash values required as per SHA standard. */
    uint8_t *initialHash;
    /** Operation data descriptor for message schedule function. */
    cy_stc_cryptolite_sha_desc_t message_schedule_struct;
    /** Operation data descriptor for process function. */
    cy_stc_cryptolite_sha_desc_t message_process_struct;
    /** SHA mode of operation. */
    cy_en_cryptolite_sha_mode_t shaMode;
    /** Internal process state. */
    cy_en_cryptolite_sha_process_state_t processState;
    /** \endcond */
} cy_stc_cryptolite_sha_context_t;

/** \} group_cryptolite_sha_data_structures */
#endif /* defined (CRYPTOLITE_SHA_PRESENT) || defined (CY_DOXYGEN) */

#if defined (CRYPTOLITE_VU_PRESENT) || defined (CY_DOXYGEN)
/**
* \addtogroup group_cryptolite_vu_data_structures
* \{
*/
/** The Cryptolite Vector Unit (VU) IP descriptor structure.
* All fields for the structure are internal. Firmware never reads or
* writes these values.
*/
typedef struct {
    /** opcode and size(s) */
    uint32_t data0;     
    /** Source 0 */
    uint32_t data1;
    /** Source 1 */
    uint32_t data2;
    /** Destination */
    uint32_t data3;
} cy_stc_cryptolite_vu_desc_t;

/** \} group_cryptolite_vu_data_structures */
#endif /* defined (CRYPTOLITE_VU_PRESENT) || defined (CY_DOXYGEN) */
/** \} group_cryptolite_data_structures */

#if defined (CRYPTOLITE_VU_PRESENT) || defined (CY_DOXYGEN)
/**
* \addtogroup group_cryptolite_rsa_data_structures
* \{
*/

#if SW_HASHING_ALG
/** Structure to hold the Callback Structure for SW Based Hashing Functions.
 * The application is expected to fill the structure with pointers to functions
 * that are needed to for Software Based Hash Computation Process
 *
 */
typedef struct
{
    void (*sw_sha_init) (
            uint8_t *ptrIntBuf          /**< Internal buffer pointer. */
            ); /**< The function to initialize the SHA384 operation and initial Hash vector. */

    void (*sw_sha_update) (
            uint8_t *ptrIntBuf,         /**< Internal buffer pointer. */
            uint8_t const *input,       /**< The pointer to the message whose Hash is being computed. */
            uint32_t ilen               /**< The size of the message whose Hash is being computed. */
            ); /**< Performs the SHA calculation on one message. */

    void (*sw_sha_finish) (
            uint8_t *ptrIntBuf,         /**< Internal buffer pointer. */
            uint8_t output[64]          /**< The pointer to the calculated Hash digest. */
            ); /**< Completes the SHA calculation and Clears the used memory and context data. */
}cy_stc_cryptolite_rsa_sw_sha_cbk_t;
#endif /* SW_HASHING_ALG */

/**
* All fields for the context structure are internal. Firmware never reads or
* writes these values. Firmware allocates the structure and provides the
* address of the structure to the driver in the function calls. Firmware must
* ensure that the defined instance of this structure remains in scope
* while the drive is in use.
*
* The driver uses this structure to store and manipulate the RSA public key and
* additional coefficients to accelerate RSA calculation.
*
*  RSA key contained from two fields:
*  - n - modulus part of the key
*  - e - exponent part of the key.
*
* Other fields are accelerating coefficients and can be calculated internally
*
* If the RSA coefficients are pre-calculated, the corresponding buffers can be 
* const and defined in Flash memory. The private buffer must be defined in RAM.
* \note All the buffers must be 4 byte aligned.
* \ref cy_stc_cryptolite_rsa_pub_key_t and must also be in little-endian order.<br>
* 
*/
CY_ALIGN(4)
typedef struct
{
    /** The pointer to the modulus part of public key (in little-endian format). */
    uint8_t *moduloPtr;
    /** The modulus length, in bits, maximum supported size is 4096 Bits */
    uint32_t moduloLength;

    /** The pointer to the exponent part of public key */
    uint8_t *pubExpPtr;
    /** The exponent length, in bits, maximum supported size is 256Bit */
    uint32_t pubExpLength;

    /** The pointer to the Barrett coefficient. Memory for it should be
        allocated by user with size moduloLength + 1. */
    uint8_t *barretCoefPtr;

    /** The pointer to the binary inverse of the modulo. Memory for it
        should be allocated by user with size moduloLength + 1. */
    uint8_t *inverseModuloPtr;

    /** The pointer to the (2^moduloLength mod modulo). Memory for it should
        be allocated by user with size moduloLength */
    uint8_t *rBarPtr;

    /** The pointer to the private buffer and used by RSA decryption calculations.
        Memory for it should be allocated by user with size
        privateBufferSize = 4*VU_BITS_TO_WORDS(2*CY_CRYPTOLITE_RSA_BIT_SIZE+1)
                          + 4*VU_BITS_TO_WORDS(2*CY_CRYPTOLITE_RSA_BIT_SIZE+1)
                          + 4*VU_BITS_TO_WORDS(CY_CRYPTOLITE_RSA_BIT_SIZE) */
    uint8_t *privateBuffer;
    
    /** when set to 'false', pre-calculated coefficients must be provided in 'barretCoefPtr, 'inverseModuloPtr' and 'rBarPtr'.
        When set to 'true', all the acceleration step coefficients will be calculated as part of \ref Cy_Cryptolite_Rsa_Verify */
    bool calculateCoeff;

    /** RSA Padding scheme selection. */
    uint8_t rsaSigScheme;

    /** SHA Algorithm used. */
    uint8_t shaAlgorithm;

#if SW_HASHING_ALG

    /** SW SHA Function Pointer */
    cy_stc_cryptolite_rsa_sw_sha_cbk_t *ptrSwShaCbk;

#endif /* SW_HASHING_ALG */
} cy_stc_cryptolite_rsa_pub_key_t;

/** \} group_cryptolite_rsa_data_structures */
#endif /* defined (CRYPTOLITE_VU_PRESENT) || defined (CY_DOXYGEN) */

#if defined(__cplusplus)
}
#endif

#endif /* defined(CY_IP_M0S8CRYPTOLITE) */

#endif /* !defined(CY_CRYPTOLITE_COMMON_H) */


/* [] END OF FILE */
