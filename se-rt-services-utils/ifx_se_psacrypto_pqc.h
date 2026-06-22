/***************************************************************************//**
* \file ifx_se_psacrypto_pqc.h
* \version 1.4.1
*
* \brief PSA cryptography module: PQC support extension.
*
* \note This file may not be included directly. Applications must
* include ifx_se_psacrypto.h.
*
*******************************************************************************
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

/*
 *  Copyright The Mbed TLS Contributors
 *  SPDX-License-Identifier: Apache-2.0
 *
 *  Licensed under the Apache License, Version 2.0 (the "License"); you may
 *  not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *  (http)www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 *  WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

#ifndef IFX_SE_PSACRYPTO_PQC_H
#define IFX_SE_PSACRYPTO_PQC_H

/** \addtogroup crypto_types
 * \{
 */

/**
 * @brief ML-DSA key pair: both the private and public keys.
 *
 * This key type identifies an ML-DSA key pair that can be used with
 * #IFX_SE_ALG_ML_DSA and #IFX_SE_ALG_HASH_ML_DSA(hash_alg).
 */
#define IFX_SE_KEY_TYPE_ML_DSA_KEY_PAIR ((ifx_se_key_type_t)0x7002)

/**
 * @brief ML-DSA public key.
 *
 * This key type identifies an ML-DSA public key that can be used with
 * #IFX_SE_ALG_ML_DSA and #IFX_SE_ALG_HASH_ML_DSA(hash_alg).
 */
#define IFX_SE_KEY_TYPE_ML_DSA_PUBLIC_KEY ((ifx_se_key_type_t)0x4002)

/** \} */

/** \cond INTERNAL */

/**
 * @brief Whether a key type is an ML-DSA key, either a key pair or a public
 *        key.
 *
 * @param type A key type: a value of type ifx_se_key_type_t.
 */
#define IFX_SE_KEY_TYPE_IS_ML_DSA(type) \
    (((type) == IFX_SE_KEY_TYPE_ML_DSA_KEY_PAIR) || \
     ((type) == IFX_SE_KEY_TYPE_ML_DSA_PUBLIC_KEY))

/** \endcond */

/** \addtogroup crypto_algs
 * \{
 */

/**
 * @brief Module lattice-based digital signature algorithm without pre-hashing
 *        (ML-DSA).
 *
 * Use this algorithm identifier with ML-DSA keys when the input is already in
 * the format expected by the algorithm and no pre-hash selection is required.
 */
#define IFX_SE_ALG_ML_DSA ((ifx_se_algorithm_t) 0x06004400)

/**
 * @brief Module lattice-based digital signature algorithm with pre-hashing
 *        (HashML-DSA).
 *
 * @param hash_alg A hash algorithm: a value of type ifx_se_algorithm_t such that
 *                 IFX_SE_ALG_IS_HASH(hash_alg) is true.
 *
 * @return The corresponding HashML-DSA signature algorithm, using hash_alg to
 *         pre-hash the message.
 */
#define IFX_SE_ALG_HASH_ML_DSA(hash_alg) \
    (IFX_SE_ALG_ML_DSA | ((hash_alg) & IFX_SE_ALG_HASH_MASK))

/** \} */

/** \cond INTERNAL */

/**
 * @brief Whether the specified algorithm is ML-DSA, without pre-hashing.
 *
 * @param alg An algorithm identifier: a value of type ifx_se_algorithm_t.
 *
 * @return 1 if alg is a pure ML-DSA algorithm, 0 otherwise.
 */
#define IFX_SE_ALG_IS_ML_DSA(alg) \
    (((alg) & ~IFX_SE_ALG_HASH_MASK) == IFX_SE_ALG_ML_DSA)
/**
 * @brief Whether the specified algorithm is HashML-DSA.
 *
 * @param alg An algorithm identifier: a value of type ifx_se_algorithm_t.
 *
 * @return 1 if alg is a HashML-DSA algorithm, 0 otherwise.
 */
#define IFX_SE_ALG_IS_HASH_ML_DSA(alg) \
    ((((alg) & ~IFX_SE_ALG_HASH_MASK) == IFX_SE_ALG_ML_DSA) && \
     (((alg) & IFX_SE_ALG_HASH_MASK) != 0))

/** \endcond */

#if defined(COMPONENT_MW_WOLFSSL)

#include <stdbool.h>

/** \cond INTERNAL */

/**
 * \def IFX_SE_STORAGE_SLOT_NUM
 *
 * \brief Default maximum number of locally stored PQC keys.
 *
 * \note Internal implementation detail used by the temporary PQC routing
 *       layer. Applications must not depend on this value.
 */
#ifndef IFX_SE_STORAGE_SLOT_NUM
#define IFX_SE_STORAGE_SLOT_NUM     (10u)
#endif

#define IFX_SE_KEY_ID_PQC_MIN      ((ifx_se_key_id_t)(IFX_SE_KEY_ID_VENDOR_MIN + 0x20000000u))
#define IFX_SE_KEY_ID_PQC_MAX      ((ifx_se_key_id_t)(IFX_SE_KEY_ID_PQC_MIN + IFX_SE_STORAGE_SLOT_NUM - 1u))

/**
 * \brief Check whether key attributes require the internal PQC storage path.
 *
 * \param[in] attributes    Key attributes to evaluate.
 *
 * \retval true             The attributes require internal PQC routing.
 * \retval false            The standard PSA crypto path can be used.
 *
 * \note Internal helper used by the temporary PQC implementation layer.
 *       Applications must not call this function directly.
 */
bool ifx_se_is_key_type_pqc(const ifx_se_key_attributes_t *attributes);

/**
 * \brief Check whether a key identifier belongs to the internal PQC range.
 *
 * \param[in] key           Key identifier to evaluate.
 *
 * \retval true             The key belongs to the internal PQC storage range.
 * \retval false            The key does not belong to the internal PQC
 *                          storage range.
 *
 * \note Internal helper used by the temporary PQC implementation layer.
 *       Applications must not call this function directly.
 */
bool ifx_se_is_key_id_pqc(ifx_se_key_id_fih_t key);

/**
 * \brief Generate a key or key pair using the internal PQC path.
 *
 * The key is generated randomly.
 * Its location, usage policy, type and size are taken from \p attributes.
 *
 * \param[in] attributes    The attributes for the new key.
 * \param[out] key          On success, a pointer to identifier
 *                          of newly created key
 *                          (encoded pointer to #ifx_se_key_id_fih_t variable).
 *                          For persistent keys, this is the key
 *                          identifier defined in \p attributes.
 *                          \c 0 on failure.
 * \param[in]  ctx          The pointer to the SE syscall context that
 *                          contain a special syscall data
 *                          (IPC release callback etc).
 *
 * \retval #IFX_SE_SUCCESS
 * \retval #IFX_SE_ERROR_ALREADY_EXISTS
 * \retval #IFX_SE_ERROR_NOT_SUPPORTED
 * \retval #IFX_SE_ERROR_INVALID_ARGUMENT
 * \retval #IFX_SE_ERROR_INSUFFICIENT_MEMORY
 * \retval #IFX_SE_ERROR_INSUFFICIENT_ENTROPY
 * \retval #IFX_SE_ERROR_COMMUNICATION_FAILURE
 * \retval #IFX_SE_ERROR_HARDWARE_FAILURE
 * \retval #IFX_SE_ERROR_CORRUPTION_DETECTED
 * \retval #IFX_SE_ERROR_INSUFFICIENT_STORAGE
 * \retval #IFX_SE_ERROR_DATA_INVALID
 * \retval #IFX_SE_ERROR_DATA_CORRUPT
 * \retval #IFX_SE_ERROR_STORAGE_FAILURE
 *
 * \note Internal helper used by the temporary PQC implementation layer.
 *       Applications must not call this function directly.
 */
ifx_se_status_t ifx_se_pqc_generate_key(
    const ifx_se_key_attributes_t *attributes,
    ifx_se_fih_ptr_t key,
    void *ctx);

/**
 * \brief Import a key in binary format into the internal PQC storage.
 *
 * The key data determines the key size.
 *
 * \param[in] attributes    The attributes for the new key.
 *                          The key size is always determined from the
 *                          \p data buffer.
 *                          If the key size in \p attributes is nonzero,
 *                          it must be equal to the size from \p data.
 * \param[in] data          Buffer containing the key data
 *                          (encoded pointer to input data). The content of this
 *                          buffer is interpreted according to the type declared
 *                          in \p attributes.
 * \param[in] data_length   Size of the \p data buffer with CRC included
 *                          in bytes (size_t).
 * \param[out] key          On success, an identifier to the newly created key
 *                          (encoded pointer to #ifx_se_key_id_fih_t variable).
 *
 * \retval #IFX_SE_SUCCESS
 *         Success.
 *         If the key is persistent, the key material and the key's metadata
 *         have been saved to persistent storage.
 * \retval #IFX_SE_ERROR_ALREADY_EXISTS
 *         This is an attempt to create a persistent key, and there is
 *         already a persistent key with the given identifier.
 * \retval #IFX_SE_ERROR_NOT_SUPPORTED
 *         The key type or key size is not supported, either by the
 *         implementation in general or in this particular persistent location.
 * \retval #IFX_SE_ERROR_INVALID_ARGUMENT
 *         The key attributes, as a whole, are invalid, or
 *         the key data is not correctly formatted, or
 *         the size in \p attributes is nonzero and does not match the size
 *         of the key data.
 * \retval #IFX_SE_ERROR_INSUFFICIENT_MEMORY
 * \retval #IFX_SE_ERROR_INSUFFICIENT_STORAGE
 * \retval #IFX_SE_ERROR_COMMUNICATION_FAILURE
 * \retval #IFX_SE_ERROR_DATA_CORRUPT
 * \retval #IFX_SE_ERROR_DATA_INVALID
 * \retval #IFX_SE_ERROR_STORAGE_FAILURE
 * \retval #IFX_SE_ERROR_HARDWARE_FAILURE
 * \retval #IFX_SE_ERROR_CORRUPTION_DETECTED
 *
 * \note Internal helper used by the temporary PQC implementation layer.
 *       Applications must not call this function directly.
 */
ifx_se_status_t ifx_se_storage_import_key(
    const ifx_se_key_attributes_t *attributes,
    const ifx_se_fih_ptr_t data,
    ifx_se_fih_t data_length, /* with CRC included */
    ifx_se_fih_ptr_t key);

/**
 * \brief Export a key in binary format.
 *
 * The output of this function can be passed to ifx_se_storage_import_key() to
 * create an equivalent object.
 *
 * The policy on the key must have the usage flag #IFX_SE_KEY_USAGE_EXPORT set.
 *
 * \param[in] key           Identifier of the key to export. It must allow the
 *                          usage #IFX_SE_KEY_USAGE_EXPORT, unless it is
 *                          a public key.
 * \param[out] data         Buffer where the key data is to be written
 *                          (encoded pointer to output buffer).
 * \param[in]  data_size    Size of the \p data buffer with CRC included
 *                          in bytes (size_t).
 * \param[out] data_length  On success, the number of bytes
 *                          that make up the key data
 *                          (encoded pointer to size_t variable).
 *
 * \retval #IFX_SE_SUCCESS
 * \retval #IFX_SE_ERROR_INVALID_HANDLE
 * \retval #IFX_SE_ERROR_NOT_PERMITTED
 *         The key does not have the #IFX_SE_KEY_USAGE_EXPORT flag.
 * \retval #IFX_SE_ERROR_NOT_SUPPORTED
 * \retval #IFX_SE_ERROR_BUFFER_TOO_SMALL
 *         The size of the \p data buffer is too small. You can determine a
 *         sufficient buffer size by calling
 *         #IFX_SE_EXPORT_KEY_OUTPUT_SIZE(\c type, \c bits)
 *         where \c type is the key type
 *         and \c bits is the key size in bits.
 * \retval #IFX_SE_ERROR_COMMUNICATION_FAILURE
 * \retval #IFX_SE_ERROR_HARDWARE_FAILURE
 * \retval #IFX_SE_ERROR_CORRUPTION_DETECTED
 * \retval #IFX_SE_ERROR_STORAGE_FAILURE
 * \retval #IFX_SE_ERROR_INSUFFICIENT_MEMORY
 *
 * \note Internal helper used by the temporary PQC implementation layer.
 *       Applications must not call this function directly.
 */
ifx_se_status_t ifx_se_storage_export_key(
    ifx_se_key_id_fih_t key,
    ifx_se_fih_ptr_t data,
    ifx_se_fih_t data_size,
    ifx_se_fih_ptr_t data_length);

/**
 * \brief Destroy a key.
 *
 * This function destroys a key from volatile storage.
 *
 * This function also erases any metadata such as policies and frees
 * resources associated with the key.
 *
 * If a key is currently in use in a multipart operation, then destroying the
 * key will cause the multipart operation to fail.
 *
 * \param[in] key     Identifier of the key to erase.
 *
 * \retval #IFX_SE_SUCCESS
 *         \p key was a valid identifier and the key material that it
 *         referred to has been erased.
 * \retval #IFX_SE_ERROR_INVALID_HANDLE
 *         \p key is not a valid identifier.
 * \retval #IFX_SE_ERROR_DATA_INVALID
 *         This error is typically a result of either storage corruption on a
 *         cleartext storage backend, or an attempt to read data that was
 *         written by an incompatible version of the library.
 * \retval #IFX_SE_ERROR_STORAGE_FAILURE
 *         The storage is corrupted. Implementations shall make a best effort
 *         to erase key material even in this stage, however applications
 *         should be aware that it may be impossible to guarantee that the
 *         key material is not recoverable in such cases.
 * \retval #IFX_SE_ERROR_CORRUPTION_DETECTED
 *         An unexpected condition which is not a storage corruption or
 *         a communication failure occurred. The cryptoprocessor may have
 *         been compromised.
 *
 * \note Internal helper used by the temporary PQC implementation layer.
 *       Applications must not call this function directly.
 */
ifx_se_status_t ifx_se_storage_destroy_key(ifx_se_key_id_fih_t key);

/**
 * \brief Export a public key or the public part of a key pair in binary format.
 *
 * The output of this function can be passed to ifx_se_import_key() to
 * create an object that is equivalent to the public key.
 *
 * Exporting a public key object or the public part of a key pair is
 * always permitted, regardless of the key's usage flags.
 *
 * \param[in] key               Identifier of the key to export.
 * \param[out] data             Buffer where the key data is to be written
 *                              (encoded pointer to output buffer).
 * \param[in]  data_size        Size of the \p data buffer with CRC included
 *                              in bytes (size_t).
 * \param[out] data_length      On success, the number of bytes
 *                              that make up the key data
 *                              (encoded pointer to size_t variable).
 * \param[in]  ctx              The pointer to the SE syscall context that
 *                              contain a special syscall data
 *                              (IPC release callback etc).
 *
 * \retval #IFX_SE_SUCCESS
 * \retval #IFX_SE_ERROR_INVALID_HANDLE
 * \retval #IFX_SE_ERROR_INVALID_ARGUMENT
 *         The key is neither a public key nor a key pair.
 * \retval #IFX_SE_ERROR_NOT_SUPPORTED
 * \retval #IFX_SE_ERROR_BUFFER_TOO_SMALL
 *         The size of the \p data buffer is too small. You can determine a
 *         sufficient buffer size by calling
 *         #IFX_SE_EXPORT_KEY_OUTPUT_SIZE(#IFX_SE_KEY_TYPE_PUBLIC_KEY_OF_KEY_PAIR(\c type), \c bits)
 *         where \c type is the key type
 *         and \c bits is the key size in bits.
 * \retval #IFX_SE_ERROR_COMMUNICATION_FAILURE
 * \retval #IFX_SE_ERROR_HARDWARE_FAILURE
 * \retval #IFX_SE_ERROR_CORRUPTION_DETECTED
 * \retval #IFX_SE_ERROR_STORAGE_FAILURE
 * \retval #IFX_SE_ERROR_INSUFFICIENT_MEMORY
 */
ifx_se_status_t ifx_se_pqc_export_public_key(ifx_se_key_id_fih_t key,
    ifx_se_fih_ptr_t data,
    ifx_se_fih_t data_size,
    ifx_se_fih_ptr_t data_length);

/**
 * \brief Sign a hash with a private key using the internal ML-DSA path.
 *
 * Note that to perform a hash-and-sign signature algorithm, callers must
 * first calculate the hash and pass it in \p hash. Use
 * #IFX_SE_ALG_SIGN_GET_HASH(\p alg) to determine the hash algorithm.
 *
 * \param[in] key               Identifier of the key to use for the operation.
 *                              It must be an asymmetric key pair. The key must
 *                              allow the usage #IFX_SE_KEY_USAGE_SIGN_HASH.
 * \param[in] alg               A signature algorithm (IFX_SE_ALG_XXX
 *                              value such that #IFX_SE_ALG_IS_SIGN_HASH(\p alg)
 *                              is true), that is compatible with
 *                              the type of \p key.
 * \param[in] hash              The hash to sign
 *                              (encoded pointer to input data).
 * \param[in] hash_length       Size of the \p hash buffer in bytes (size_t).
 * \param[out] signature        Buffer where the signature is to be written
 *                              (encoded pointer to output buffer).
 * \param[in] signature_size    Size of the \p signature buffer in bytes (size_t).
 * \param[out] signature_length On success, the number of bytes
 *                              that make up the returned signature value
 *                              (encoded pointer to size_t variable).
 * \param[in] ctx               The pointer to the SE syscall context that
 *                              contain a special syscall data
 *                              (IPC release callback etc).
 *
 * \retval #IFX_SE_SUCCESS
 * \retval #IFX_SE_ERROR_INVALID_HANDLE
 * \retval #IFX_SE_ERROR_NOT_PERMITTED
 * \retval #IFX_SE_ERROR_BUFFER_TOO_SMALL
 * \retval #IFX_SE_ERROR_NOT_SUPPORTED
 * \retval #IFX_SE_ERROR_INVALID_ARGUMENT
 * \retval #IFX_SE_ERROR_INSUFFICIENT_MEMORY
 * \retval #IFX_SE_ERROR_COMMUNICATION_FAILURE
 * \retval #IFX_SE_ERROR_HARDWARE_FAILURE
 * \retval #IFX_SE_ERROR_CORRUPTION_DETECTED
 * \retval #IFX_SE_ERROR_STORAGE_FAILURE
 * \retval #IFX_SE_ERROR_INSUFFICIENT_ENTROPY
 *
 * \note Internal helper used by the temporary PQC implementation layer until
 *       PQC support is provided natively by syscalls. Applications must not
 *       call this function directly.
 */
ifx_se_status_t ifx_se_pqc_sign_hash(
    ifx_se_key_id_fih_t key,
    ifx_se_alg_fih_t alg,
    const ifx_se_fih_ptr_t hash,
    ifx_se_fih_t hash_length,
    const ifx_se_fih_ptr_t signature,
    ifx_se_fih_t signature_size,
    ifx_se_fih_ptr_t signature_length,
    void *ctx);

/**
 * \brief Verify the signature of a hash using the internal ML-DSA path.
 *
 * \param[in] key               Identifier of the key to use for the operation.
 *                              It must be a public key or an asymmetric key
 *                              pair. The key must allow the usage
 *                              #IFX_SE_KEY_USAGE_VERIFY_HASH.
 * \param[in] alg               A signature algorithm (IFX_SE_ALG_XXX
 *                              value such that #IFX_SE_ALG_IS_SIGN_HASH(\p alg)
 *                              is true), that is compatible with
 *                              the type of \p key.
 * \param[in] hash              The hash whose signature is to be verified
 *                              (encoded pointer to input data).
 * \param[in] hash_length       Size of the \p hash buffer in bytes (size_t).
 * \param[in] signature         Buffer containing the signature to verify
 *                              (encoded pointer to input data).
 * \param[in] signature_length  Size of the \p signature buffer in bytes (size_t).
 *
 * \retval #IFX_SE_SUCCESS
 *         The signature is valid.
 * \retval #IFX_SE_ERROR_INVALID_HANDLE
 * \retval #IFX_SE_ERROR_INVALID_SIGNATURE
 *         The calculation was performed successfully, but the passed
 *         signature is not a valid signature.
 * \retval #IFX_SE_ERROR_NOT_SUPPORTED
 * \retval #IFX_SE_ERROR_INVALID_ARGUMENT
 * \retval #IFX_SE_ERROR_INSUFFICIENT_MEMORY
 * \retval #IFX_SE_ERROR_STORAGE_FAILURE
 *
 * \note Internal helper used by the temporary PQC implementation layer until
 *       PQC support is provided natively by syscalls. Applications must not
 *       call this function directly.
 */
ifx_se_status_t ifx_se_pqc_verify_hash(
    ifx_se_key_id_fih_t key,
    ifx_se_alg_fih_t alg,
    const ifx_se_fih_ptr_t hash,
    ifx_se_fih_t hash_length,
    const ifx_se_fih_ptr_t signature,
    ifx_se_fih_t signature_length);

/** \endcond */

#endif /* COMPONENT_MW_WOLFSSL */

#endif /* IFX_SE_PSACRYPTO_PQC_H */
