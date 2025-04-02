/***************************************************************************//**
* \file cy_cryptolite_hkdf.c
* \version 2.80
*
* \brief
*  This file provides the source code to the API for the HKDF method
*  in the CRYPTOLITE block driver.
*
********************************************************************************
* \copyright
* Copyright (c) (2020-2023), Cypress Semiconductor Corporation (an Infineon company) or
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

#include "cy_device.h"

#if defined(CY_IP_MXCRYPTOLITE)

#include "cy_cryptolite_hkdf.h"

#if defined(__cplusplus)
extern "C" {
#endif

#if (CRYPTOLITE_SHA_PRESENT == 1)
#if defined(CY_CRYPTOLITE_CFG_HKDF_C) && defined(CY_CRYPTOLITE_CFG_HMAC_C)

#include "cy_cryptolite_utils.h"
#include "cy_cryptolite_vu.h"

/*******************************************************************************
* Function Name: Cy_Cryptolite_Hkdf_Extract
****************************************************************************//**
*
* Performs HKDF Extract calculation.
*
* \param base
* The pointer to the CRYPTOLITE instance.
*
* \param salt
* The pointer to salt.
*
* \param saltLength
* The size of a salt.
*
* \param ikm
* The pointer to the Input Key material.
*
* \param ikmLength
* The length of the IKM.
*
* \param prk
* The pointer to store the generated prk.
*
* \return
* \ref cy_en_cryptolite_status_t
*
*******************************************************************************/
cy_en_cryptolite_status_t Cy_Cryptolite_Hkdf_Extract(CRYPTOLITE_Type *base,        
                                          uint8_t  const *salt,
                                          uint32_t saltLength,
                                          uint8_t  const *ikm,
                                          uint32_t ikmLength,
                                          uint8_t *prk)
{
    cy_en_cryptolite_status_t status = CY_CRYPTOLITE_BAD_PARAMS;
    CY_ALIGN(4) uint8_t nullSalt[CY_CRYPTOLITE_SHA256_HASH_SIZE] = {0u};
    uint8_t *saltptr;
    uint32_t  saltlen;
    cy_stc_cryptolite_context_hmac_sha256_t hmac_ctx;

    /* Input parameters verification */
    if ((NULL == base) || (NULL == prk) || ((NULL == salt) && (0UL != saltLength))
        ||((NULL == ikm) && (0UL != ikmLength)))
    {
        return status;
    }

    saltptr = (uint8_t  *)salt;
    saltlen = saltLength;

    if(NULL == salt)
    {
        Cy_Cryptolite_Memset (nullSalt, 0u, CY_CRYPTOLITE_SHA256_HASH_SIZE);
        saltlen = CY_CRYPTOLITE_SHA256_HASH_SIZE;
        saltptr = nullSalt;
    }

    return Cy_Cryptolite_Hmac_Sha256_Run(base, saltptr, saltlen, ikm, ikmLength, prk, &hmac_ctx);
}


/*******************************************************************************
* Function Name: Cy_Cryptolite_Hkdf_Expand
****************************************************************************//**
*
* Performs HKDF Expand calculation.
*
* \param base
* The pointer to the CRYPTOLITE instance.
*
* \param prk
* The pointer to the pseudo random key.
*
* \param prkLength
* The length of the prk.
*
* \param info
* The pointer to info.
*
* \param infoLength
* The length of the info.
*
* \param okm
* The pointer to Output key material.
*
* \param okmLength
* The length of okm to be generated.
*
* \return
* \ref cy_en_cryptolite_status_t
*
*******************************************************************************/
cy_en_cryptolite_status_t Cy_Cryptolite_Hkdf_Expand(CRYPTOLITE_Type *base,      
                                          uint8_t  const *prk,
                                          uint32_t prkLength,
                                          uint8_t  const *info,
                                          uint32_t infoLength,
                                          uint8_t *okm,
                                          uint32_t okmLength)
{
    cy_en_cryptolite_status_t status = CY_CRYPTOLITE_BAD_PARAMS;
    uint32_t  hashlen = CY_CRYPTOLITE_SHA256_HASH_SIZE;
    uint32_t  n,i;
    uint8_t  counter=0u;
    uint32_t tLength=0u;
    uint32_t bytesCopy=0u;
    uint32_t offset=0u;
    uint8_t t[CY_CRYPTOLITE_SHA256_HASH_SIZE]  = {0u};
    cy_stc_cryptolite_context_hmac_sha256_t cfContext;


    /* Input parameters verification */
    if ((NULL == base) || ((NULL == prk) && (0UL != prkLength)) || ((NULL == info) && (0UL != infoLength))
        ||((NULL == okm) && (0UL != okmLength)))
    {
        return status;
    }

    n = (okmLength + (hashlen - 1u))/ hashlen;

    if( n > 255u)
    {
        return CY_CRYPTOLITE_BAD_PARAMS;
    }

    for(i=1u; i<=n; i++)
    {
        counter++;

        status = Cy_Cryptolite_Hmac_Sha256_Init (base, &cfContext);
        if(status != CY_CRYPTOLITE_SUCCESS)
        {
            break;
        }

        status = Cy_Cryptolite_Hmac_Sha256_Start (base, prk, prkLength, &cfContext);
        if(status != CY_CRYPTOLITE_SUCCESS)
        {
            break;
        }

        status = Cy_Cryptolite_Hmac_Sha256_Update (base, t, tLength, &cfContext);
        if(status != CY_CRYPTOLITE_SUCCESS)
        {
            break;
        }

        status = Cy_Cryptolite_Hmac_Sha256_Update (base, info, infoLength, &cfContext);
        if(status != CY_CRYPTOLITE_SUCCESS)
        {
            break;
        }

        status = Cy_Cryptolite_Hmac_Sha256_Update (base, &counter, 1u, &cfContext);
        if(status != CY_CRYPTOLITE_SUCCESS)
        {
            break;
        }

        status = Cy_Cryptolite_Hmac_Sha256_Finish (base, t, &cfContext);
        if(status != CY_CRYPTOLITE_SUCCESS)
        {
            break;
        }

        status =  Cy_Cryptolite_Hmac_Sha256_Free(base, &cfContext);
        if(status != CY_CRYPTOLITE_SUCCESS)
        {
            break;
        } 

        if(i != n)
        {
            bytesCopy = hashlen;
        }
        else
        {
            bytesCopy = okmLength - offset;
        }

        status =  Cy_Cryptolite_Memcpy(base, (okm + offset), t, bytesCopy);
        if(status != CY_CRYPTOLITE_SUCCESS)
        {
            break;
        } 

        offset += hashlen;
        tLength = hashlen;
    }

    return status;
}



/*******************************************************************************
* Function Name: Cy_Cryptolite_Hkdf
****************************************************************************//**
*
* Performs HKDF calculation.
*
* \param base
* The pointer to the CRYPTOLITE instance.
*
* \param salt
* The pointer to salt.
*
* \param saltLength
* The size of a salt.
*
* \param ikm
* The pointer to the Input Key material.
*
* \param ikmLength
* The length of the IKM.
*
* \param info
* The pointer to info.
*
* \param infoLength
* The length of the info.
*
* \param okm
* The pointer to Output key material.
*
* \param okmLength
* The length of okm to be generated.
*
* \return
* \ref cy_en_cryptolite_status_t
*
*******************************************************************************/
cy_en_cryptolite_status_t Cy_Cryptolite_Hkdf(CRYPTOLITE_Type *base,       
                                          uint8_t  const *salt,
                                          uint32_t saltLength,
                                          uint8_t  const *ikm,
                                          uint32_t ikmLength,
                                          uint8_t  const *info,
                                          uint32_t infoLength,
                                          uint8_t *okm,
                                          uint32_t okmLength)
{
    cy_en_cryptolite_status_t status = CY_CRYPTOLITE_BAD_PARAMS;
    CY_ALIGN(4) uint8_t prk[CY_CRYPTOLITE_SHA256_HASH_SIZE]  = {0u};

    /* Input parameters verification */
    if ((NULL == base) || ((NULL == salt) && (0UL != saltLength))
        ||((NULL == ikm) && (0UL != ikmLength)) || ((NULL == info) && (0UL != infoLength))
        ||((NULL == okm) && (0UL != okmLength)))
    {
        return status;
    }

    Cy_Cryptolite_Memset (prk, 0u, CY_CRYPTOLITE_SHA256_HASH_SIZE); 

    status = Cy_Cryptolite_Hkdf_Extract(base, salt, saltLength, ikm, ikmLength, prk);
    if(status != CY_CRYPTOLITE_SUCCESS)
    {
        return status;
    }

    status = Cy_Cryptolite_Hkdf_Expand(base, prk, CY_CRYPTOLITE_SHA256_HASH_SIZE, info, infoLength, okm, okmLength);

    Cy_Cryptolite_Memset ( prk, 0u, CY_CRYPTOLITE_SHA256_HASH_SIZE);

    return status;
}   


#endif /* CRYPTOLITE_SHA_PRESENT */
#endif  /* defined(CY_CRYPTOLITE_CFG_HKDF_C) && defined(CY_CRYPTOLITE_CFG_HMAC_C) */

#if defined(__cplusplus)
}
#endif


#endif /* defined(CY_IP_MXCRYPTOLITE) */


/* [] END OF FILE */
