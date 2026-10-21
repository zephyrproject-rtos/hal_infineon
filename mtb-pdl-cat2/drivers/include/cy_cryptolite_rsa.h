/***************************************************************************//**
* \file cy_cryptolite_rsa.h
* \version 1.40
*
* \brief
*  This file defines function prototypes for the RSA functionality.
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
#ifndef _CY_CRYPTOLITE_RSA_H_
#define _CY_CRYPTOLITE_RSA_H_

#include "cy_device.h"

#if (defined (CY_IP_M0S8CRYPTOLITE) && defined (CRYPTOLITE_VU_PRESENT))  || defined (CY_DOXYGEN)

#if defined(__cplusplus)
extern "C" {
#endif

#include <stdint.h>
#include "cy_cryptolite_common.h"

/* RSA Coefficients pre-calculation control
 * Set this macro value to 1u to indicate the RSA coefficients are pre-calculated.
 * By default, the RSA coefficients are calculated as part of 
 * Cy_Cryptolite_Rsa_Verify function.
 */
#ifndef CY_CRYPTOLITE_RSA_PRE_CALC_COEFF_ENABLE
#define CY_CRYPTOLITE_RSA_PRE_CALC_COEFF_ENABLE             (0u)
#endif /* CY_CRYPTOLITE_RSA_PRE_CALC_COEFF_ENABLE */

#ifndef RSA_PADDING_PKCS1_PSS_SIG_SCHEME
#define RSA_PADDING_PKCS1_PSS_SIG_SCHEME                    (0u)
#endif /* RSA_PADDING_PKCS1_PSS_SIG_SCHEME */
/**
* \addtogroup group_cryptolite_rsa
* \{
* RSA algorithm which decrypts user data using public key provided.
* 
* \defgroup group_cryptolite_rsa_data_structures Structures
* \defgroup group_cryptolite_rsa_functions Functions
*
* */

/**
* \addtogroup group_cryptolite_rsa_functions
* \{
*/
/*******************************************************************************
* Function Name: Cy_Cryptolite_Rsa_Verify
****************************************************************************//**
*
* RSA verification with checks for content, padding and signature format.
* SHA digest of the message and decrypted message should be calculated before.
* Supports only PKCS1-v1_5 format, inside of this format supported padding
* using only SHA, cases with MD2 and MD5 are not supported.
*
* The digest and decryptedSignature buffers must be 4 byte aligned
*
* Returns the verification result
*
* \param base
* The pointer to the CRYPTOLITE instance.
*
* \param digestLength
* SHA digest length (in bytes).
*
* \param digest
* The pointer to the hash of the message or the message whose signature is to be verified.
*
* \param rsaSignature
* The pointer to the encrypted RSA signature which is required to be decrypted.
*
* \param rsaLength
* The length of the RSA signature (in bytes).
*
* \param key
* Pointer to RSA Public key and additional coefficients information.
*
* \param processedDigest
* Pointer to hold processed digest from RSA signature.
*
* \return
* \ref cy_en_cryptolite_status_t
*
* \funcusage
* \snippet cryptolite_sut.c snippet_myCryptoliteRsaVerification
*******************************************************************************/
cy_en_cryptolite_status_t Cy_Cryptolite_Rsa_Verify(CRYPTOLITE_Type *base,
                            uint16_t digestLength,
                            uint8_t *digest,
                            uint8_t *rsaSignature,
                            uint16_t rsaLength,
                            cy_stc_cryptolite_rsa_pub_key_t *key,
                            uint8_t *processedDigest);

/*******************************************************************************
* Function Name: Cy_Cryptolite_Rsa_Coeff
****************************************************************************//**
*
* This function calculates the RSA related coefficients.
*
* \param base
* The pointer to the CRYPTOLITE instance.
*
* \param key
* Pointer to RSA Public key and additional coefficients information.
*
* \return
* None
*
* \funcusage
* \snippet cryptolite_sut.c snippet_myCryptoliteRsaCoeffCalculation
*******************************************************************************/
void Cy_Cryptolite_Rsa_Coeff (CRYPTOLITE_Type *base, cy_stc_cryptolite_rsa_pub_key_t *key);

/*******************************************************************************
* Function Name: Cy_Cryptolite_Rsa_PssVerifyExt
****************************************************************************//**
*
* This function is an extension to do RSA signature verification using
* EMSA-PSS Encoding method (RSASSA-PSS). This function requires the processed
* RSA signature using public key.
*
* Reference: RFC 8017 (https://www.rfc-editor.org/rfc/rfc8017)
*
* \param base
* cryptolite base address.
*
* \param digestLength
* SHA digest length (in bytes).
*
* \param digest
* digest buffer pointer.
*
* \param rsaLength
* RSA Signature length (in bytes).
*
* \param key
* Pointer to Public key and RSA coefficients.
*
* \param processedDigest
* Processed RSA signature using public key.
*
* \return
* cy_en_cryptolite_status_t Cryptolite operation status
*
* \funcusage
* \snippet cryptolite_sut.c snippet_myCryptoliteRsaPssVerifyExt
*******************************************************************************/
cy_en_cryptolite_status_t Cy_Cryptolite_Rsa_PssVerifyExt(
                            CRYPTOLITE_Type *base,
                            uint16_t digestLength,
                            uint8_t *digest,
                            uint16_t rsaLength,
                            cy_stc_cryptolite_rsa_pub_key_t *key,
                            uint8_t *processedDigest);

/** \} group_cryptolite_rsa_functions */      
/** \} group_cryptolite_rsa */      

#if defined(__cplusplus)
}
#endif

#endif /* (defined (CY_IP_M0S8CRYPTOLITE) && defined (CRYPTOLITE_SHA_PRESENT)) || defined (CY_DOXYGEN) */

#endif /* _CY_CRYPTOLITE_RSA_H_ */

/* [] END OF FILE */
