/***************************************************************************//**
* \file cy_cryptolite_hmac.c
* \version 2.80
*
* \brief
*  Provides API implementation of the Cryptolite HAMC-SHA256 PDL driver.
*
********************************************************************************
* Copyright 2020 Cypress Semiconductor Corporation
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

#include "cy_device.h"

#if defined (CY_IP_MXCRYPTOLITE)

#include "cy_cryptolite_hmac.h"

#if defined(__cplusplus)
extern "C" {
#endif

#if (CRYPTOLITE_SHA_PRESENT == 1)
#if defined(CY_CRYPTOLITE_CFG_HMAC_C) && defined(CY_CRYPTOLITE_CFG_SHA2_256_ENABLED)

CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Directive 4.7', 3, \
'Coverity does not seem to allow return of a error status without a check.')

/*****************************************************************************
* Cy_Cryptolite_Hmac_Sha256_Init
******************************************************************************
*
* The function to initialize the HMAC SHA256 operation.
*
*  base
* The pointer to the Cryptolite instance.
*
*  cfContext
* The pointer to the cy_stc_cryptolite_context_hmac_sha256_t structure that stores all
* internal variables for Cryptolite driver.
*
* return
* cy_en_cryptolite_status_t
*
*******************************************************************************/
cy_en_cryptolite_status_t Cy_Cryptolite_Hmac_Sha256_Init(CRYPTOLITE_Type *base,
                                        cy_stc_cryptolite_context_hmac_sha256_t *cfContext)
{
    cy_en_cryptolite_status_t status;

    /* Input parameters verification */
    if ((NULL == base) || (NULL == cfContext))
    {
        return CY_CRYPTOLITE_BAD_PARAMS;
    }

    cfContext->blocksize  = (uint16_t)CY_CRYPTOLITE_SHA256_BLOCK_SIZE;
    cfContext->digestsize = (uint16_t)CY_CRYPTOLITE_SHA256_HASH_SIZE;
    /*Init SHA 256*/
    status = Cy_Cryptolite_Sha256_Init( base, &cfContext->ctx_sha256);

    return status;
}

/*******************************************************************************
* Cy_Cryptolite_Hmac_Sha256_Start
******************************************************************************
*
* Initializes the initial Hash vector.
*
*  base
* The pointer to the CRYPTOLITE instance.
*
*  key
* The pointer to the HMAC key.
*
*  keyLength
* The length of the HMAC key.
*
*  cfContext
* The pointer to the cy_stc_cryptolite_context_hmac_sha256_t structure that stores all
* internal variables for Cryptolite driver.
*
* return
* cy_en_cryptolite_status_t
*
*******************************************************************************/
cy_en_cryptolite_status_t Cy_Cryptolite_Hmac_Sha256_Start(CRYPTOLITE_Type *base,
                                        uint8_t const *key,
                                        uint32_t keyLength,
                                        cy_stc_cryptolite_context_hmac_sha256_t *cfContext)
{
    uint32_t i;
    uint32_t blockSizeTmp;
    uint32_t digestSizeTmp;
    uint8_t *ipadPtrTmp;
    uint8_t *opadPtrTmp;
    uint8_t *m0KeyPtrTmp;

    cy_en_cryptolite_status_t status = CY_CRYPTOLITE_SUCCESS;

    /* Input parameters verification */
    if ((NULL == base) || (NULL == cfContext) || ((NULL == key) && (0UL != keyLength)) )
    {
        return CY_CRYPTOLITE_BAD_PARAMS;
    }

    blockSizeTmp    = cfContext->blocksize;
    digestSizeTmp   = cfContext->digestsize;
    ipadPtrTmp      = (uint8_t*)cfContext->ipad;
    opadPtrTmp      = (uint8_t*)cfContext->opad;
    m0KeyPtrTmp     = (uint8_t*)cfContext->m0Key;

    /*check if IP is busy*/
    if ((REG_CRYPTOLITE_STATUS(base) & CRYPTOLITE_STATUS_BUSY_Msk) != 0UL)
    {
        return CY_CRYPTOLITE_HW_BUSY;
    }

    for (i=0U; i < CY_CRYPTOLITE_SHA256_BLOCK_SIZE; i++)
    {
        cfContext->ipad[i]  = 0;
        cfContext->opad[i]  = 0;
        cfContext->m0Key[i] = 0;
    }

    /* Steps 1-3 according to FIPS 198-1 */
    if (keyLength > blockSizeTmp)
    {
        /* The key is larger than the block size. Do a hash on the key. */
        status = Cy_Cryptolite_Sha256_Start( base, &cfContext->ctx_sha256);

        if (CY_CRYPTOLITE_SUCCESS == status)
        {
            status = Cy_Cryptolite_Sha256_Update (base, key, keyLength, &cfContext->ctx_sha256);
        }
        if (CY_CRYPTOLITE_SUCCESS == status)
        {
            status = Cy_Cryptolite_Sha256_Finish (base, m0KeyPtrTmp, &cfContext->ctx_sha256);
        }
        /* Append zeros */
        for (i=0U; i < (uint32_t)(blockSizeTmp - digestSizeTmp); i++)
        {
            m0KeyPtrTmp[digestSizeTmp + i] = 0x00u;
        }
    }
    else /*(keyLength < blockSizeTmp)*/
    {
        /* If the key is shorter than the block, append zeros */
        for (i=0U; i < keyLength; i++)
        {
            m0KeyPtrTmp[i] = key[i];
        }
        /* Append zeros */
        for (i=0U; i < (uint32_t)(blockSizeTmp - keyLength); i++)
        {
            m0KeyPtrTmp[keyLength + i] = 0x00u;
        }
    }

    if (CY_CRYPTOLITE_SUCCESS == status)
    {
        /* Steps 4 and 7 according to FIPS 198-1 */
        for (i=0U; i < blockSizeTmp; i++)
        {
            ipadPtrTmp[i] = CY_CRYPTOLITE_HMAC_IPAD ^ m0KeyPtrTmp[i];
            opadPtrTmp[i] = CY_CRYPTOLITE_HMAC_0PAD ^ m0KeyPtrTmp[i];
        }

        /* Step 6 according to FIPS 198-1 */
        status = Cy_Cryptolite_Sha256_Start( base, &cfContext->ctx_sha256);

        if (CY_CRYPTOLITE_SUCCESS == status)
        {
            status = Cy_Cryptolite_Sha256_Update (base, ipadPtrTmp, blockSizeTmp, &cfContext->ctx_sha256);
        }
    }

    return status;
}

/*******************************************************************************
* Cy_Cryptolite_Hmac_Sha256_Update
********************************************************************************
*
* Performs the SHA256 calculation on one message.
*
*  base
* The pointer to the CRYPTOLITE instance.
*
*  cfContext
* The pointer to the cy_stc_cryptolite_context_hmac_sha256_t structure that stores all
* internal variables for Cryptolite driver.
*
*  message
* The pointer to the message whose Hash is being computed.
*
*  messageSize
* The size of the message whose Hash is being computed.
*
* return
* cy_en_cryptolite_status_t
*
*******************************************************************************/
cy_en_cryptolite_status_t Cy_Cryptolite_Hmac_Sha256_Update(CRYPTOLITE_Type *base,
                                        uint8_t const *message,
                                        uint32_t  messageSize,
                                        cy_stc_cryptolite_context_hmac_sha256_t *cfContext)
{
    cy_en_cryptolite_status_t status = CY_CRYPTOLITE_BAD_PARAMS;

    if (0UL == messageSize)
    {
        return CY_CRYPTOLITE_SUCCESS;
    }

    /* Input parameters verification */
    if ((NULL == base) || (NULL == cfContext) || (NULL == message))
    {
        return status;
    }

    /*check if IP is busy*/
    if ((REG_CRYPTOLITE_STATUS(base) & CRYPTOLITE_STATUS_BUSY_Msk) != 0UL)
    {
        return CY_CRYPTOLITE_HW_BUSY;
    }

    /* Append a message */
    status = Cy_Cryptolite_Sha256_Update (base,  message, messageSize, &cfContext->ctx_sha256);

    return status;
}

/*******************************************************************************
* Cy_Cryptolite_Hmac_Sha256_Finish
******************************************************************************
*
* Completes the SHA256 calculation.
*
*  base
* The pointer to the CRYPTOLITE instance.
*
*  cfContext
* the pointer to the cy_stc_cryptolite_context_hmac_sha256_t structure that stores all
* internal variables for Cryptolite driver.
*
*  hmac
* The pointer to the calculated Hash hmac.
*
* return
* cy_en_cryptolite_status_t
*
*******************************************************************************/
cy_en_cryptolite_status_t Cy_Cryptolite_Hmac_Sha256_Finish(CRYPTOLITE_Type *base,
                                    uint8_t *hmac,
                                    cy_stc_cryptolite_context_hmac_sha256_t *cfContext)
{
    uint32_t blockSizeTmp;
    uint32_t digestSizeTmp;
    uint8_t *ipadPtrTmp;
    uint8_t *opadPtrTmp;
    cy_en_cryptolite_status_t status = CY_CRYPTOLITE_BAD_PARAMS;

    /* Input parameters verification */
    if ((NULL == base) || (NULL == cfContext) || (NULL == hmac))
    {
        return status;
    }

    blockSizeTmp   = cfContext->blocksize;
    digestSizeTmp  = cfContext->digestsize;
    ipadPtrTmp  = (uint8_t*)cfContext->ipad;
    opadPtrTmp  = (uint8_t*)cfContext->opad;

    /*check if IP is busy*/
    if ((REG_CRYPTOLITE_STATUS(base) & CRYPTOLITE_STATUS_BUSY_Msk) != 0UL)
    {
        return CY_CRYPTOLITE_HW_BUSY;
    }

    /*Finish message hash and calculate hmac*/
    status = Cy_Cryptolite_Sha256_Finish (base, ipadPtrTmp, &cfContext->ctx_sha256);

    /* Here is the ready part of HASH: Hash((Key^ipad)||text) */
    if (CY_CRYPTOLITE_SUCCESS == status)
    {
        /* Steps 8, 9 according to FIPS 198-1 */
        status = Cy_Cryptolite_Sha256_Start( base, &cfContext->ctx_sha256);

        if (CY_CRYPTOLITE_SUCCESS == status)
        {
            status = Cy_Cryptolite_Sha256_Update (base, opadPtrTmp, blockSizeTmp, &cfContext->ctx_sha256);
        }
        /* Append HASH from Step 6 */
        if (CY_CRYPTOLITE_SUCCESS == status)
        {
            status = Cy_Cryptolite_Sha256_Update (base, ipadPtrTmp, digestSizeTmp, &cfContext->ctx_sha256);
        }
        if (CY_CRYPTOLITE_SUCCESS == status)
        {
            status = Cy_Cryptolite_Sha256_Finish (base, hmac, &cfContext->ctx_sha256);
        }
    }

    return status;
}

/*******************************************************************************
* Cy_Cryptolite_Hmac_Sha256_Free
******************************************************************************
*
* Clears the used memory and context data.
*
*  base
* The pointer to the CRYPTOLITE instance.
*
*  cfContext
* the pointer to the cy_stc_cryptolite_context_hmac_sha256_t structure that stores all
* internal variables for Cryptolite driver.
*
* return
* cy_en_cryptolite_status_t
*
*******************************************************************************/
cy_en_cryptolite_status_t Cy_Cryptolite_Hmac_Sha256_Free(CRYPTOLITE_Type *base,
                                    cy_stc_cryptolite_context_hmac_sha256_t *cfContext)
{
    uint32_t i;

    /* Input parameters verification */
    if (NULL != cfContext)
    {
        /* Clear the context memory */
        for (i=0U; i < CY_CRYPTOLITE_HMAC_MAX_PAD_SIZE; i++)
        {
            cfContext->ipad[i]  = 0;
            cfContext->opad[i]  = 0;
            cfContext->m0Key[i] = 0;
        }
        cfContext->blocksize = 0;
        cfContext->digestsize = 0;

        /*Clear hash context*/
        (void)Cy_Cryptolite_Sha256_Free (base, &cfContext->ctx_sha256);
    }

    return CY_CRYPTOLITE_SUCCESS;
}

/*******************************************************************************
* Cy_Cryptolite_Hmac_Sha256_Run
******************************************************************************
*
* This function performs the HAMC SHA256 MAC function.
* Provide the required parameters and the pointer
* to the context structure when making this function call.
* It is independent of the previous Crypto state because it already contains
* preparation, calculation, and finalization steps.
*
*  base
* The pointer to the CRYPTOLITE instance.
*
*  cfContext
* the pointer to the cy_stc_cryptolite_context_hmac_sha256_t structure that stores all
* internal variables for Cryptolite driver.
*
*  message
* The pointer to a message whose HMAC is being computed.
*
*  messageSize
* The size of a message in bytes.
*
*  hmac
* The pointer to the hmac.
*
* return
* cy_en_cryptolite_status_t
*
*******************************************************************************/
cy_en_cryptolite_status_t Cy_Cryptolite_Hmac_Sha256_Run(CRYPTOLITE_Type *base,
                                        uint8_t const *key,
                                        uint32_t keyLength,
                                        uint8_t const *message,
                                        uint32_t  messageSize,
                                        uint8_t *hmac,
                                        cy_stc_cryptolite_context_hmac_sha256_t *cfContext)
{
    cy_en_cryptolite_status_t status = CY_CRYPTOLITE_BAD_PARAMS;
    /* Input parameters verification */
    if ((NULL == base) || (NULL == cfContext) || (NULL == hmac) || ((NULL == message) && (0UL != messageSize))
        || ((NULL == key) && (0UL != keyLength)))
    {
        return status;
    }

    status = Cy_Cryptolite_Hmac_Sha256_Init (base, cfContext);

    if (CY_CRYPTOLITE_SUCCESS == status)
    {
        status = Cy_Cryptolite_Hmac_Sha256_Start (base, key, keyLength, cfContext);
    }
    if (CY_CRYPTOLITE_SUCCESS == status)
    {
        status = Cy_Cryptolite_Hmac_Sha256_Update (base, message, messageSize, cfContext);
    }
    if (CY_CRYPTOLITE_SUCCESS == status)
    {
        status = Cy_Cryptolite_Hmac_Sha256_Finish (base, hmac, cfContext);
    }
    if (CY_CRYPTOLITE_SUCCESS == status)
    {
        status = Cy_Cryptolite_Hmac_Sha256_Free (base, cfContext);
    }

    return status;
}
CY_MISRA_BLOCK_END('MISRA C-2012 Directive 4.7')

#endif
#endif /* CY_CRYPTOLITE_CFG_HMAC_C */

#if defined(__cplusplus)
}
#endif


#endif /* CY_IP_MXCRYPTOLITE */
/* [] END OF FILE */
