/***************************************************************************//**
* \file cy_cryptolite_sha.h
* \version 1.40
*
* \brief
*  This file provides an API declaration of the Cryptolite SHA driver.
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
#if !defined (CY_CRYPTOLITE_SHA_H)
#define CY_CRYPTOLITE_SHA_H

#include "cy_device.h"

#if (defined (CY_IP_M0S8CRYPTOLITE) && (defined (CRYPTOLITE_SHA_PRESENT) || \
     defined (CRYPTOLITE_SHA384_PRESENT) || defined (CRYPTOLITE_SHA512_PRESENT)))  || defined (CY_DOXYGEN)

#include "cy_syslib.h"

#if defined(__cplusplus)
extern "C" {
#endif

#include <stddef.h>
#include <stdbool.h>
#include "cy_sysint.h"
#include "cy_cryptolite_common.h"

/**
* \addtogroup group_cryptolite_sha
* \{
* Secure Hash Algorithm (SHA)
*
* SHA generates an almost-unique 256-bit/384-bit/512-bit signature for a text. The
* applications of SHA include hash tables, integrity verification, challenge 
* handshake authentication, digital signatures, etc.
*
* \defgroup group_cryptolite_sha_macros Macros
* \defgroup group_cryptolite_sha_enums Enums
* \defgroup group_cryptolite_sha_data_structures Structures
* \defgroup group_cryptolite_sha_functions Functions
*
* */

/**
* \addtogroup group_cryptolite_sha_functions
* \{
*/

/*****************************************************************************
* Function Name: Cy_Cryptolite_Sha_SetMode
**************************************************************************//**
*
* The function sets the SHA mode of operation.
* \note This function is only applicable for CCG6xF_CFP devices, and this 
*       must be called before the \ref Cy_Cryptolite_Sha_Init function call.
*
* \param mode
* SHA selection mode(SHA256, SHA384, SHA512).
*
* \param shaContext
* The pointer to the \ref cy_stc_cryptolite_sha_context_t structure that stores all
* internal variables for Cryptolite driver.
*
* \return
* \ref cy_en_cryptolite_status_t
*
* \funcusage
* \snippet cryptolite_sut.c snippet_myCryptoliteShaUse2
*
*******************************************************************************/
cy_en_cryptolite_status_t Cy_Cryptolite_Sha_SetMode( cy_en_cryptolite_sha_mode_t mode,
                                        cy_stc_cryptolite_sha_context_t *shaContext);

/*******************************************************************************
* Function Name: Cy_Cryptolite_Sha_Init
****************************************************************************//**
*
* The function to initialize the SHA operation.
*
* \param base
* The pointer to the Cryptolite instance.
*
* \param shaContext
* The pointer to the \ref cy_stc_cryptolite_sha_context_t structure that stores all
* internal variables for Cryptolite driver.
*
* \return
* \ref cy_en_cryptolite_status_t
*
* \funcusage
* \snippet cryptolite_sut.c snippet_myCryptoliteShaUse2
*******************************************************************************/
cy_en_cryptolite_status_t Cy_Cryptolite_Sha_Init(CRYPTOLITE_Type *base,
                                        cy_stc_cryptolite_sha_context_t *shaContext);

/*******************************************************************************
* Function Name: Cy_Cryptolite_Sha_Start
****************************************************************************//**
*
* Initializes the initial Hash vector.
*
* \param base
* The pointer to the CRYPTOLITE instance.
*
* \param shaContext
* The pointer to the \ref cy_stc_cryptolite_sha_context_t structure that stores all
* internal variables for Cryptolite driver.
*
* \return
* \ref cy_en_cryptolite_status_t
*
* \funcusage
* \snippet cryptolite_sut.c snippet_myCryptoliteShaUse2
*******************************************************************************/
cy_en_cryptolite_status_t Cy_Cryptolite_Sha_Start(CRYPTOLITE_Type *base,
                                        cy_stc_cryptolite_sha_context_t *shaContext);

/*******************************************************************************
* Function Name: Cy_Cryptolite_Sha_Update
****************************************************************************//**
*
* Performs the SHA calculation on one message based on the selected SHA mode.
*
* \param base
* The pointer to the CRYPTOLITE instance.
*
* \param message
* The pointer to the message whose Hash is being computed.
*
* \param messageSize
* The size of the message whose Hash is being computed.
*
* \param shaContext
* The pointer to the \ref cy_stc_cryptolite_sha_context_t structure that stores all
* internal variables for Cryptolite driver.
*
* \return
* \ref cy_en_cryptolite_status_t
* 
* \note There is no alignment or size restriction for message buffer, However providing
* a four byte aligned buffer with size in multiple of \ref CY_CRYPTOLITE_SHA_MAX_BLOCK_SIZE,
* will result in best execution time.
*
* \funcusage
* \snippet cryptolite_sut.c snippet_myCryptoliteShaUse2
*******************************************************************************/
cy_en_cryptolite_status_t Cy_Cryptolite_Sha_Update(CRYPTOLITE_Type *base,
                                                    uint8_t const *message,
                                                    uint32_t  messageSize,
                                                    cy_stc_cryptolite_sha_context_t *shaContext);

/*******************************************************************************
* Function Name: Cy_Cryptolite_Sha_Finish
****************************************************************************//**
*
* Completes the SHA calculation.
*
* \param base
* The pointer to the CRYPTOLITE instance.
*
* \param digest
* The pointer to the calculated Hash digest.
*
* \param shaContext
* The pointer to the \ref cy_stc_cryptolite_sha_context_t structure that stores all
* internal variables for Cryptolite driver.
*
* \return
* \ref cy_en_cryptolite_status_t
*
* \funcusage
* \snippet cryptolite_sut.c snippet_myCryptoliteShaUse2
*******************************************************************************/
cy_en_cryptolite_status_t Cy_Cryptolite_Sha_Finish(CRYPTOLITE_Type *base,
                               uint8_t *digest,
                               cy_stc_cryptolite_sha_context_t *shaContext);

/*******************************************************************************
* Function Name: Cy_Cryptolite_Sha_Free
****************************************************************************//**
*
* Clears the used memory and context data.
*
* \param base
* The pointer to the CRYPTOLITE instance.
*
* \param shaContext
* The pointer to the \ref cy_stc_cryptolite_sha_context_t structure that stores all
* internal variables for Cryptolite driver.
*
* \return
* \ref cy_en_cryptolite_status_t
*
* \funcusage
* \snippet cryptolite_sut.c snippet_myCryptoliteShaUse2
*******************************************************************************/
cy_en_cryptolite_status_t Cy_Cryptolite_Sha_Free(CRYPTOLITE_Type *base,
                                                    cy_stc_cryptolite_sha_context_t *shaContext);


/*******************************************************************************
* Function Name: Cy_Cryptolite_Sha
****************************************************************************//**
*
* This function performs the SHA256, SHA384 or SHA512 Hash function based on the
* SHA mode selected.
* Provide the required parameters and the pointer to the context structure when
* making this function call.
* It is independent of the previous Crypto state because it already contains
* preparation, calculation, and finalization steps.
*
* \param base
* The pointer to the CRYPTOLITE instance.
*
* \param message
* The pointer to a message whose hash value is being computed.
*
* \param messageSize
* The size of a message in bytes.
*
* \param digest
* The pointer to the hash digest.
*
* \param shaContext
* The pointer to the \ref cy_stc_cryptolite_sha_context_t structure that stores all
* internal variables for Cryptolite driver.
*
* \return
* \ref cy_en_cryptolite_status_t
*
* \note There is no alignment or size restriction for message buffer, However providing
* a four byte aligned buffer with size in multiple of \ref CY_CRYPTOLITE_SHA_MAX_BLOCK_SIZE,
* will result in best execution time.
*
* \funcusage
* \snippet cryptolite_sut.c snippet_myCryptoliteShaUse
*
* Note: Don't use this function in CCGx_CFP as the code is in ROM needs update.
* Hence, it is requested to use same flow defined in this function.
*******************************************************************************/
cy_en_cryptolite_status_t Cy_Cryptolite_Sha(CRYPTOLITE_Type *base,
                                        uint8_t const *message,
                                        uint32_t  messageSize,
                                        uint8_t *digest,
                                        cy_stc_cryptolite_sha_context_t *shaContext);

/** \} group_cryptolite_sha_functions */
/** \} group_cryptolite_sha */

#if defined(__cplusplus)
}
#endif

#endif /* (defined (CY_IP_M0S8CRYPTOLITE) && (defined (CRYPTOLITE_SHA_PRESENT) || \
           defined (CRYPTOLITE_SHA384_PRESENT) || defined (CRYPTOLITE_SHA512_PRESENT)))  || defined (CY_DOXYGEN) */

#endif /* #if !defined (CY_CRYPTOLITE_SHA_H) */

/* [] END OF FILE */
