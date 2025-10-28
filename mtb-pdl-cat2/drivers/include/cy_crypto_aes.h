/***************************************************************************//**
* \file cy_crypto_aes.h
* \version 1.0.1
*
* \brief
*  This file provides AES API declaration of the Crypto driver
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

#if !defined(CY_CRYPTO_AES_H)
#define CY_CRYPTO_AES_H

#include "cy_device.h"

#if (defined (CY_IP_M0S8CRYPTO) && defined (CRYPTO_AES)) || defined (CY_DOXYGEN)

#include "cy_crypto_common.h"

#if defined(__cplusplus)
extern "C" {
#endif

#include "cy_crypto_hw.h"

/**
* \addtogroup group_crypto_lld_symmetric_functions
* \{
*/

/*******************************************************************************
* Function Name: Cy_Crypto_Aes_Init
****************************************************************************//**
*
* This function initializes the AES operation by setting the key and key length.
*
* \param base
* Base address of the Crypto block registers.
*
* \param key
* Pointer to the encryption/decryption key.
*
* \param keyLength
* AES key length \ref cy_en_crypto_aes_key_length_t
*
* \param aesContext
* The pointer to the context structure \ref cy_stc_crypto_aes_context_t
* allocated by the user. This structure is used by the Crypto driver for the
* AES operation. Do not modify the values of this structure.
*
* \return
* \ref cy_en_crypto_status_t
*
* \funcusage
* \snippet crypto_snippet.c snippet_myCryptoAesEcbUse
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Aes_Init(CRYPTO_Type *base,
                                         uint8_t const *key,
                                         cy_en_crypto_aes_key_length_t keyLength,
                                         cy_stc_crypto_aes_context_t *aesContext);

/*******************************************************************************
* Function Name: Cy_Crypto_Aes_Free
****************************************************************************//**
*
* This function clears the AES operation context.
*
* \param base
* Base address of the Crypto block registers.
*
* \param aesContext
* Pointer to the context structure \ref cy_stc_crypto_aes_context_t allocated
* by the user. The structure is used by the Crypto driver for the AES operation.
* Do not modify the values of this structure.
*
* \return
* \ref cy_en_crypto_status_t
*
* \funcusage
* \snippet crypto_snippet.c snippet_myCryptoAesEcbUse
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Aes_Free(CRYPTO_Type *base,
                                         cy_stc_crypto_aes_context_t *aesContext);

/*******************************************************************************
* Function Name: Cy_Crypto_Aes_Ecb
****************************************************************************//**
*
* This function performs an AES-ECB (Electronic Code Book) encryption/decryption
* operation on the input data. It performs the AES operation on a single block
* of size \ref CY_CRYPTO_AES_BLOCK_SIZE.
*
* The AES key must be set before by invoking \ref Cy_Crypto_Aes_Init().
*
* \param base
* Base address of the Crypto block registers.
*
* \param dirMode
* Can be \ref CY_CRYPTO_ENCRYPT or \ref CY_CRYPTO_DECRYPT
* (\ref cy_en_crypto_dir_mode_t).
*
* \param dst
* Pointer to a destination buffer to store the output data of the AES operation.
* The buffer must be at least \ref CY_CRYPTO_AES_BLOCK_SIZE bytes long.
*
* \param src
* Pointer to a source block holding the data to be encrypted/decrypted.
* It must have at least \ref CY_CRYPTO_AES_BLOCK_SIZE bytes of data.
*
* \param aesContext
* Pointer to the context structure \ref cy_stc_crypto_aes_context_t allocated
* by the user. The structure is used by the Crypto driver for the AES operation.
* Do not modify the values of this structure.
*
* \return
* \ref cy_en_crypto_status_t
*
* \funcusage
* \snippet crypto_snippet.c snippet_myCryptoAesEcbUse
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Aes_Ecb(CRYPTO_Type *base,
                                        cy_en_crypto_dir_mode_t dirMode,
                                        uint8_t *dst,
                                        uint8_t const *src,
                                        cy_stc_crypto_aes_context_t *aesContext);

/*******************************************************************************
* Function Name: Cy_Crypto_Aes_Cbc
****************************************************************************//**
*
* This function performs an AES-CBC (Cipher Block Chaining) encryption/decryption
* operation on the input data.
*
* The key must be set before by invoking \ref Cy_Crypto_Aes_Init().
*
* \note  The input size must be a multiple of the AES block size
*        \ref CY_CRYPTO_AES_BLOCK_SIZE. If not, this function returns an error.
*
* \note  On return of this function, the content of the ivPtr is updated so
*        that the user can call the same function again on the next block of
*        data and get the same result as if it was in one call. This allows a
*        "streaming" usage.
*
* \param base
* Base address of the Crypto block registers.
*
* \param dirMode
* Can be \ref CY_CRYPTO_ENCRYPT or \ref CY_CRYPTO_DECRYPT
* (\ref cy_en_crypto_dir_mode_t)
*
* \param srcSize
* Size of the input data in bytes. It should be a multiple of the AES block size
* \ref CY_CRYPTO_AES_BLOCK_SIZE.
*
* \param ivPtr
* Pointer to the initial vector of length \ref CY_CRYPTO_AES_BLOCK_SIZE bytes.
* On return of this function, the content of the ivPtr is updated. For AES-CBC
* operation on the next block, the user must provide the updated ivPtr without
* any modification.
*
* \param dst
* Pointer to a destination buffer to store the output data of the AES operation.
* This buffer must be at least as big as the source buffer.
*
* \param src
* Pointer to the source buffer holding the data to be encrypted/decrypted.
*
* \param aesContext
* Pointer to the context structure \ref cy_stc_crypto_aes_context_t allocated
* by the user. The structure is used by the Crypto driver for the AES operation.
* Do not modify the values of this structure.
*
* \return
* \ref cy_en_crypto_status_t
*
* \funcusage
* \snippet crypto_snippet.c snippet_myCryptoAesCbcUse
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Aes_Cbc(CRYPTO_Type *base,
                                        cy_en_crypto_dir_mode_t dirMode,
                                        uint32_t srcSize,
                                        uint8_t *ivPtr,
                                        uint8_t *dst,
                                        uint8_t const *src,
                                        cy_stc_crypto_aes_context_t *aesContext);

/*******************************************************************************
* Function Name: Cy_Crypto_Aes_Cfb
****************************************************************************//**
*
* This function performs the AES-CFB (Cipher FeedBack) encrypt/decrypt operation
* on the input data.
*
* The key must be set before by invoking \ref Cy_Crypto_Aes_Init().
*
* \note  The AES-CFB crypto operation is stream-based, so the input data size
*        doesn't need to be a multiple of \ref CY_CRYPTO_AES_BLOCK_SIZE.
*
* \note  On return of this function, the content of the ivPtr is updated so that
*        the user can call same function again on the next bytes of data and get
*        the same result as if it was in one call. This allows a "streaming"
*        usage.
*
* \param base
* Base address of the Crypto block registers.
*
* \param dirMode
* Can be \ref CY_CRYPTO_ENCRYPT or \ref CY_CRYPTO_DECRYPT
* (\ref cy_en_crypto_dir_mode_t)
*
* \param srcSize
* Size of the input data in bytes.
*
* \param ivPtr
* Pointer to the initial vector of length \ref CY_CRYPTO_AES_BLOCK_SIZE bytes.
* On return of this function, the content of the * ivPtr is updated. For AES-CFB
* operation on the next bytes of data, the user must provide the updated ivPtr
* without any modification.
*
* \param ivOffset
* Pointer holding the offset value in ivPtr. The pointer value should be 0 at
* the start of a stream. On return of this function, ivOffset value is updated.
* For AES-CFB operation on the next bytes in the stream, the user must provide
* the updated ivOffset without any modification.
*
* \param dst
* Pointer to a destination buffer to store the output data of the AES operation.
* This buffer must be at least as big as the source buffer.
*
* \param src
* Pointer to the source buffer holding the data to be encrypted/decrypted.
*
* \param aesContext
* Pointer to the context structure \ref cy_stc_crypto_aes_context_t allocated
* by the user. The structure is used by the Crypto driver for the AES operation.
* Do not modify the values of this structure.
*
* \return
* \ref cy_en_crypto_status_t
*
* \funcusage
* \snippet crypto_snippet.c snippet_myCryptoAesCfbUse
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Aes_Cfb(CRYPTO_Type *base,
                                        cy_en_crypto_dir_mode_t dirMode,
                                        uint32_t srcSize,
                                        uint8_t *ivOffset,
                                        uint8_t *ivPtr,
                                        uint8_t *dst,
                                        uint8_t const *src,
                                        cy_stc_crypto_aes_context_t *aesContext);

/*******************************************************************************
* Function Name: Cy_Crypto_Aes_Ctr
****************************************************************************//**
*
* This function performs the AES-CTR (Counter mode) operation on the input data.
*
* The key must be set before by invoking \ref Cy_Crypto_Aes_Init().
*
* \note  The AES-CTR crypto operation is stream-based, so the input data size
*        doesn't need to be a multiple of \ref CY_CRYPTO_AES_BLOCK_SIZE.
*
* \note  On a new message, the user must set the first 12 bytes of nonceCounter
*        with the chosen nonce value, the last 4 bytes to the counter value
*        (counter value can be zero), and ncOffset to 0.
*        On return, this function updates ncOffset, nonceCounter, and
*        streamBlock buffers.
*        User must preserve these updated values for successive calls of this
*        function with the partial data of the same message.
*
* \note  For AES-CTR crypto operation, each block is encrypted with the unique
*        key and key-stream combination. Key-stream is the AES-encrypted output
*        of the nonce counter. With the 4-bytes counter and incrementing it by
*        one for each block, 2<sup>32</sup> unique key streams can be generated.
*        Therefore, the the user can encrypt a message with a maximum of
*        2<sup>32</sup> blocks with the same key.
*
* \param base
* Base address of the Crypto block registers.
*
* \param srcSize
* Size of the input data in bytes.
*
* \param ncOffset
* Pointer holding the offset within the streamBlock buffer for resuming
* within the current cipher stream. The pointer value should be 0 at the start
* of a stream. If this function is called multiple times with partial data, the
* user must not modify the ncOffset value.
*
* \param nonceCounter
* Pointer holding the 128-bit nonce and counter. For a new message, the user
* should fill the first 12 bytes in this buffer with the per-message nonce, and
* the last 4 bytes with the initial counter value (initial counter value can be
* zero). The last 4 bytes are used internally and updated by the driver. For
* successive calls of this function with the partial data of a same message, the
* user must preserve the updated values and pass the same without any
* modification.
*
* \param streamBlock
* The saved stream-block for resuming. This is overwritten by the function. The
* user must provide the allocated buffer and it must be at least 16 bytes long.
* If this function is called multiple times with partial data, the user must not
* modify the contents.
*
* \param dst
* Pointer to a destination buffer to store the output data of the AES operation.
*
* \param src
* Pointer to the source buffer holding the data to be encrypted/decrypted.
*
* \param aesContext
* Pointer to the context structure \ref cy_stc_crypto_aes_context_t allocated
* by the user. The structure is used by the Crypto driver for the AES operation.
* Do not modify the values of this structure.
*
* \return
* \ref cy_en_crypto_status_t
*
* \funcusage
* \snippet crypto_snippet.c snippet_myCryptoAesCtrUse
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Aes_Ctr(CRYPTO_Type *base,
                                        uint32_t srcSize,
                                        uint32_t *ncOffset,
                                        uint8_t *nonceCounter,
                                        uint8_t *streamBlock,
                                        uint8_t *dst,
                                        uint8_t const *src,
                                        cy_stc_crypto_aes_context_t *aesContext);

/** \} group_crypto_lld_symmetric_functions */

#if defined(__cplusplus)
}
#endif

#endif /* CY_IP_M0S8CRYPTO */
#endif /* #if !defined(CY_CRYPTO_AES_H) */


/* [] END OF FILE */
