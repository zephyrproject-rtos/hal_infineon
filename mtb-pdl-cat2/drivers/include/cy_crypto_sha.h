/***************************************************************************//**
* \file cy_crypto_sha.h
* \version 1.0.1
*
* \brief
*  This file provides SHA API declaration of the Crypto driver
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


#if !defined(CY_CRYPTO_SHA_H)
#define CY_CRYPTO_SHA_H

#include "cy_device.h"

#if (defined (CY_IP_M0S8CRYPTO) && defined (CRYPTO_SHA)) || defined (CY_DOXYGEN)

#include "cy_crypto_common.h"

#if defined(__cplusplus)
extern "C" {
#endif

/**
* \addtogroup group_crypto_lld_sha_functions
* \{
*/

/*******************************************************************************
* Function Name: Cy_Crypto_Sha
****************************************************************************//**
*
* This function calculates the secure hash algorithm (SHA) hash for the given
* message. This function can be called without calling \ref Cy_Crypto_Sha_Init().
*
* \note  Use this function when the data to be hashed is available in
*        a contiguous block. For non-contiguous blocks of memory, use the
*        \ref Cy_Crypto_Sha_Partial() and \ref Cy_Crypto_Sha_Finish() functions.
*
* \param base
* Base address of the Crypto block registers
*
* \param mode
* SHA mode. \ref cy_en_crypto_sha_mode_t
*
* \param message
* Pointer to the message whose hash value is being computed
*
* \param messageSize
* Size of the message in bytes
*
* \param digest
* Pointer to store the calculated hash digest
*
* \return
* \ref cy_en_crypto_status_t
*
* \funcusage
* \snippet crypto_snippet.c snippet_myCryptoSha256Use
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Sha(CRYPTO_Type *base,
                                    uint8_t const *message,
                                    uint32_t messageSize,
                                    uint8_t *digest,
                                    cy_en_crypto_sha_mode_t mode);

/*******************************************************************************
* Function Name: Cy_Crypto_Sha_Init
****************************************************************************//**
*
* This function initializes the SHA operation.
*
* \note  This function must be called prior to the \ref Cy_Crypto_Sha_Partial()
*        function.
*
* \param base
* Base address of the Crypto block registers
*
* \param mode
* SHA mode. \ref cy_en_crypto_sha_mode_t
*
* \param shaContext
* Pointer to the SHA context structure \ref cy_stc_crypto_sha_context_t allocated
* by the user. This structure is used by the Crypto driver for the SHA hash
* calculation. Do not modify the values of this structure.
*
* \return
* \ref cy_en_crypto_status_t
*
* \funcusage
* \snippet crypto_snippet.c snippet_myCryptoSha256Use2
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Sha_Init(CRYPTO_Type *base,
                                         cy_en_crypto_sha_mode_t mode,
                                         cy_stc_crypto_sha_context_t *shaContext);

/*******************************************************************************
* Function name: Cy_Crypto_Sha_Partial
****************************************************************************//**
*
* This function performs the SHA Hash calculation on partial data which is part
* of a complete message.
*
* \ref Cy_Crypto_Sha_Init() must be called before calling this function.
* This function can be called multiple times with partial data and at the end,
* the user must call \ref Cy_Crypto_Sha_Finish() to get the final SHA hash
* digest.
*
* \param base
* Base address of the Crypto block registers
*
* \param shaContext
* Pointer to the SHA context structure \ref cy_stc_crypto_sha_context_t allocated
* by the user. This structure is used by the Crypto driver for the SHA hash
* calculation. Do not modify the values of this structure.
*
* \param message
* Pointer to the message whose Hash is being computed
*
* \param messageSize
* Size (in bytes) of the message whose Hash is being computed
*
* \return
* \ref cy_en_crypto_status_t
*
* \funcusage
* \snippet crypto_snippet.c snippet_myCryptoSha256Use2
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Sha_Partial(CRYPTO_Type *base,
                                            uint8_t const *message,
                                            uint32_t messageSize,
                                            cy_stc_crypto_sha_context_t *shaContext);

/*******************************************************************************
* Function Name: Cy_Crypto_Sha_Finish
****************************************************************************//**
*
* This function completes the SHA hash calculation for the message provided with
* \ref Cy_Crypto_Sha_Partial() function.
*
* \param base
* Base address of the Crypto block registers
*
* \param shaContext
* Pointer to the SHA context structure \ref cy_stc_crypto_sha_context_t allocated
* by the user. This structure is used by the Crypto driver for the SHA hash
* calculation. Do not modify the values of this structure.
*
* \param digest
* Pointer to store the calculated Hash digest
*
* \return
* \ref cy_en_crypto_status_t
*
* \funcusage
* \snippet crypto_snippet.c snippet_myCryptoSha256Use2
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Sha_Finish(CRYPTO_Type *base,
                                           uint8_t *digest,
                                           cy_stc_crypto_sha_context_t *shaContext);

/*******************************************************************************
* Function Name: Cy_Crypto_Sha_Free
****************************************************************************//**
*
* This function clears the SHA operation context.
*
* \param base
* Base address of the Crypto block registers
*
* \param shaContext
* Pointer to the SHA context structure \ref cy_stc_crypto_sha_context_t allocated
* by the user. This structure is used by the Crypto driver for the SHA hash
* calculation. Do not modify the values of this structure.
*
* \return
* \ref cy_en_crypto_status_t
*
* \funcusage
* \snippet crypto_snippet.c snippet_myCryptoSha256Use2
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Sha_Free(CRYPTO_Type *base,
                                         cy_stc_crypto_sha_context_t *shaContext);

/** \} group_crypto_lld_sha_functions */


#if defined(__cplusplus)
}
#endif

#endif /* CY_IP_M0S8CRYPTO */

#endif /* #if !defined(CY_CRYPTO_SHA_H) */


/* [] END OF FILE */
