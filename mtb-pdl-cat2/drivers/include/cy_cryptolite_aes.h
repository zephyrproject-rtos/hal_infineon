/***************************************************************************//**
* \file cy_cryptolite_aes.h
* \version 1.40
*
* \brief
* This file provides AES API declaration of the Cryptolite driver
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

#if !defined(CY_CRYPTOLITE_AES_H)
#define CY_CRYPTOLITE_AES_H

#include "cy_device.h"
#include "cy_cryptolite_common.h"
#if (defined (CY_IP_M0S8CRYPTOLITE) && defined (CRYPTOLITE_AES_PRESENT)) || defined (CY_DOXYGEN)

#if defined(__cplusplus)
extern "C" {
#endif

/**
* \addtogroup group_cryptolite_aes
* \{
* Advanced Encryption Standard (AES)
*
* Cryptolite AES stack supports AES-128 block cipher function in a specific 
* configuration to provide message confidentiality and authenticity. This CRYPTOLITE
* component provides AES-128 forward encryption cipher function.
*
* \defgroup group_cryptolite_aes_macros Macros
* \defgroup group_cryptolite_aes_data_structures Structures
* \defgroup group_cryptolite_aes_functions Functions
*
* */

/**
* \addtogroup group_cryptolite_aes_functions
* \{
*/

/*******************************************************************************
* Function Name: Cy_Cryptolite_Aes_Init
****************************************************************************//**
*
* This function initializes the AES operation by setting the key.
*
* \param base
* Base address of the Cryptolite block registers.
*
* \param key
* Pointer to the encryption key.
*
* \param aesContext
* The pointer to the context structure \ref cy_stc_cryptolite_aes_context_t
* allocated by the user. This structure is used by the Crypto driver for the
* AES operation. Do not modify the values of this structure.
*
* \return
* \ref cy_en_cryptolite_status_t
*
* \funcusage
* \snippet cryptolite_sut.c snippet_myCryptoliteAesEcbUse
*******************************************************************************/
cy_en_cryptolite_status_t Cy_Cryptolite_Aes_Init(CRYPTOLITE_Type *base,
                                         uint8_t const *key,
                                         cy_stc_cryptolite_aes_context_t *aesContext);

/*******************************************************************************
* Function Name: Cy_Cryptolite_Aes_Free
****************************************************************************//**
*
* This function clears the AES operation context.
*
* \param base
* Base address of the Cryptolite block registers.
*
* \param aesContext
* Pointer to the context structure \ref cy_stc_cryptolite_aes_context_t allocated
* by the user. The structure is used by the Cryptolite driver for the AES operation.
* Do not modify the values of this structure.
*
* \return
* \ref cy_en_cryptolite_status_t
*
* \funcusage
* \snippet cryptolite_sut.c snippet_myCryptoliteAesEcbUse
*******************************************************************************/
cy_en_cryptolite_status_t Cy_Cryptolite_Aes_Free(CRYPTOLITE_Type *base,
                                         cy_stc_cryptolite_aes_context_t *aesContext);

/*******************************************************************************
* Function Name: Cy_Cryptolite_Aes_Ecb
****************************************************************************//**
*
* This function performs an AES-ECB (Electronic Code Book) encryption
* operation on the input data.
*
* The AES key must be set before by invoking \ref Cy_Cryptolite_Aes_Init().
*
* \param base
* Base address of the Cryptolite block registers.
*
* \param dst
* Pointer to a destination buffer to store the output data of the AES operation.
* The buffer must be at least \ref CY_CRYPTOLITE_AES_BLOCK_SIZE bytes long.
*
* \param src
* Pointer to a source block holding the data to be encrypted.
* It must have at least \ref CY_CRYPTOLITE_AES_BLOCK_SIZE bytes of data.
*
* \param srcSize
* Size of the input data in bytes. It should be a multiple of the AES block size
* \ref CY_CRYPTOLITE_AES_BLOCK_SIZE.
*
* \param aesContext
* Pointer to the context structure \ref cy_stc_cryptolite_aes_context_t allocated
* by the user. The structure is used by the Cryptolite driver for the AES operation.
* Do not modify the values of this structure.
*
* \return
* \ref cy_en_cryptolite_status_t
*
* \funcusage
* \snippet cryptolite_sut.c snippet_myCryptoliteAesEcbUse
*******************************************************************************/
cy_en_cryptolite_status_t Cy_Cryptolite_Aes_Ecb(CRYPTOLITE_Type *base,
                                        uint8_t *dst,
                                        uint8_t const *src,
                                        uint32_t srcSize,
                                        cy_stc_cryptolite_aes_context_t *aesContext);

/*******************************************************************************
* Function Name: Cy_Cryptolite_Aes_Cbc
****************************************************************************//**
*
* This function performs an AES-CBC (Cipher Block Chaining) encryption
* operation on the input data.
*
* The key must be set before by invoking \ref Cy_Cryptolite_Aes_Init().
*
* \note  The input size must be a multiple of the AES block size
*        \ref CY_CRYPTOLITE_AES_BLOCK_SIZE. If not, this function returns an error.
*
* \note  On return of this function, the content of the ivPtr is updated so
*        that the user can call the same function again on the next block of
*        data and get the same result as if it was in one call. This allows a
*        "streaming" usage.
*
* \param base
* Base address of the Cryptolite block registers.
*
* \param srcSize
* Size of the input data in bytes. It should be a multiple of the AES block size
* \ref CY_CRYPTOLITE_AES_BLOCK_SIZE.
*
* \param ivPtr
* Pointer to the initial vector of length \ref CY_CRYPTOLITE_AES_BLOCK_SIZE bytes.
* On return of this function, the content of the ivPtr is updated. For AES-CBC
* operation on the next block, the user must provide the updated ivPtr without
* any modification.
*
* \param dst
* Pointer to a destination buffer to store the output data of the AES operation.
* This buffer must be at least as big as the source buffer.
*
* \param src
* Pointer to the source buffer holding the data to be encrypted.
*
* \param aesContext
* Pointer to the context structure \ref cy_stc_cryptolite_aes_context_t allocated
* by the user. The structure is used by the Cryptolite driver for the AES operation.
* Do not modify the values of this structure.
*
* \return
* \ref cy_en_cryptolite_status_t
*
* \funcusage
* \snippet cryptolite_sut.c snippet_myCryptoliteAesCbcUse
*******************************************************************************/
cy_en_cryptolite_status_t Cy_Cryptolite_Aes_Cbc(CRYPTOLITE_Type *base,
                                        uint32_t srcSize,
                                        uint8_t *ivPtr,
                                        uint8_t *dst,
                                        uint8_t const *src,
                                        cy_stc_cryptolite_aes_context_t *aesContext);

/*******************************************************************************
* Function Name: Cy_Cryptolite_Aes_Cfb
****************************************************************************//**
*
* This function performs the AES-CFB (Cipher FeedBack) encrypt operation
* on the input data.
*
* The key must be set before by invoking \ref Cy_Cryptolite_Aes_Init().
*
* \note  The AES-CFB crypto operation is stream-based, so the input data size
*        doesn't need to be a multiple of \ref CY_CRYPTOLITE_AES_BLOCK_SIZE.
*
* \note  On return of this function, the content of the ivPtr is updated so that
*        the user can call same function again on the next bytes of data and get
*        the same result as if it was in one call. This allows a "streaming"
*        usage.
*
* \param base
* Base address of the Cryptolite block registers.
*
* \param srcSize
* Size of the input data in bytes.
*
* \param ivPtr
* Pointer to the initial vector of length \ref CY_CRYPTOLITE_AES_BLOCK_SIZE bytes.
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
* Pointer to the source buffer holding the data to be encrypted.
*
* \param aesContext
* Pointer to the context structure \ref cy_stc_cryptolite_aes_context_t allocated
* by the user. The structure is used by the Crypto driver for the AES operation.
* Do not modify the values of this structure.
*
* \return
* \ref cy_en_cryptolite_status_t
*
* \funcusage
* \snippet cryptolite_sut.c snippet_myCryptoliteAesCfbUse
*******************************************************************************/
cy_en_cryptolite_status_t Cy_Cryptolite_Aes_Cfb(CRYPTOLITE_Type *base,
                                        uint32_t srcSize,
                                        uint8_t *ivOffset,
                                        uint8_t *ivPtr,
                                        uint8_t *dst,
                                        uint8_t const *src,
                                        cy_stc_cryptolite_aes_context_t *aesContext);

/*******************************************************************************
* Function Name: Cy_Cryptolite_Aes_Ofb
****************************************************************************//**
*
* This function performs the AES-OFB (Output FeedBack) encrypt operation
* on the input data.
*
* The key must be set before by invoking \ref Cy_Cryptolite_Aes_Init().
*
* \note  The AES-OFB crypto operation is stream-based, so the input data size
*        doesn't need to be a multiple of \ref CY_CRYPTOLITE_AES_BLOCK_SIZE.
*
* \param base
* Base address of the Cryptolite block registers.
*
* \param srcSize
* Size of the input data in bytes.
*
* \param ivPtr
* Pointer to the initial vector of length \ref CY_CRYPTOLITE_AES_BLOCK_SIZE bytes.
*
* \param dst
* Pointer to a destination buffer to store the output data of the AES operation.
* This buffer must be at least as big as the source buffer.
*
* \param src
* Pointer to the source buffer holding the data to be encrypted.
*
* \param aesContext
* Pointer to the context structure \ref cy_stc_cryptolite_aes_context_t allocated
* by the user. The structure is used by the Crypto driver for the AES operation.
* Do not modify the values of this structure.
*
* \return
* \ref cy_en_cryptolite_status_t
*
* \funcusage
* \snippet cryptolite_sut.c snippet_myCryptoliteAesOfbUse
*******************************************************************************/
cy_en_cryptolite_status_t Cy_Cryptolite_Aes_Ofb(CRYPTOLITE_Type *base,
                                        uint32_t srcSize,
                                        uint8_t *ivPtr,
                                        uint8_t *dst,
                                        uint8_t const *src,
                                        cy_stc_cryptolite_aes_context_t *aesContext);

/*******************************************************************************
* Function Name: Cy_Cryptolite_Aes_Ctr
****************************************************************************//**
*
* This function performs the AES-CTR (Counter mode) operation on the input data.
*
* The key must be set before by invoking \ref Cy_Cryptolite_Aes_Init().
*
* \note  The AES-CTR crypto operation is stream-based, so the input data size
*        doesn't need to be a multiple of \ref CY_CRYPTOLITE_AES_BLOCK_SIZE.
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
* Base address of the Cryptolite block registers.
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
* Pointer to the source buffer holding the data to be encrypted.
*
* \param aesContext
* Pointer to the context structure \ref cy_stc_cryptolite_aes_context_t allocated
* by the user. The structure is used by the Cryptolite driver for the AES operation.
* Do not modify the values of this structure.
*
* \return
* \ref cy_en_cryptolite_status_t
*
* \funcusage
* \snippet cryptolite_sut.c snippet_myCryptoliteAesCtrUse
*
*******************************************************************************/
cy_en_cryptolite_status_t Cy_Cryptolite_Aes_Ctr(CRYPTOLITE_Type *base,
                                        uint32_t srcSize,
                                        uint32_t *ncOffset,
                                        uint8_t *nonceCounter,
                                        uint8_t *streamBlock,
                                        uint8_t *dst,
                                        uint8_t const *src,
                                        cy_stc_cryptolite_aes_context_t *aesContext);

/** \} group_cryptolite_aes_functions */

/** \} group_cryptolite_aes */

#if defined(__cplusplus)
}
#endif

#endif /* (defined (CY_IP_M0S8CRYPTOLITE)  && defined (CRYPTOLITE_AES_PRESENT)) || defined (CY_DOXYGEN) */
#endif /* #if !defined(CY_CRYPTOLITE_AES_H) */


/* [] END OF FILE */
