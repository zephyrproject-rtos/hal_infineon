/***************************************************************************//**
* \file cy_cryptolite_ecc_key_gen.c
* \version 2.80
*
* \brief
*  This file provides API for generating ECC key.
*
********************************************************************************
* Copyright 2023 Cypress Semiconductor Corporation
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

#if defined(__cplusplus)
extern "C" {
#endif

#include "cy_cryptolite_ecc_key_gen.h"
#include "cy_cryptolite_trng.h"

#if (CRYPTOLITE_VU_PRESENT == 1)

#include "cy_cryptolite_utils.h"
#include "cy_cryptolite_nist_p.h"

/*******************************************************************************
* Function Name: Cy_Cryptolite_ECC_MakeKeyPair
****************************************************************************//*
*
* Generate a Private & Public Key pair.
*
* \param base
* The pointer to a Cryptolite instance.
*
* \param cfContext
* The pointer to the cy_stc_cryptolite_context_ecdsa_t.
*
* \param curveID
* The ECC curve id.
*
* \param key
* The ECC key. See \ref cy_stc_cryptolite_ecc_key.
*
* \param GetRandomDataFunc
* See \ref cy_func_get_random_data_t.
*
* \param randomDataInfo
*
* \return status code. See \ref cy_en_cryptolite_status_t.
*
*******************************************************************************/
cy_en_cryptolite_status_t Cy_Cryptolite_ECC_MakeKeyPair(CRYPTOLITE_Type *base,
        cy_stc_cryptolite_context_ecdsa_t *cfContext,
        cy_en_cryptolite_ecc_curve_id_t curveID,
        cy_stc_cryptolite_ecc_key *key,
        cy_func_get_random_data_t GetRandomDataFunc, void *randomDataInfo)
{
    cy_en_cryptolite_status_t tmpResult = CY_CRYPTOLITE_BAD_PARAMS;

    if ((key != NULL) && (key->k != NULL) && (key->pubkey.x != NULL) && (key->pubkey.y != NULL))
    {
        tmpResult = Cy_Cryptolite_ECC_MakePrivateKey(base, cfContext, curveID, key->k, GetRandomDataFunc, randomDataInfo);
    }

    if (CY_CRYPTOLITE_SUCCESS == tmpResult)
    {
        tmpResult = Cy_Cryptolite_ECC_MakePublicKey(base, cfContext, curveID, key->k, key);
        key->type = PK_PRIVATE;
    }

    return (tmpResult);
}

/*******************************************************************************
* Function Name: Cy_Cryptolite_ECC_MakePrivateKey
****************************************************************************//*
*
* Generate a Private key.
*
* \param base
* The pointer to a Cryptolite instance.
*
* \param cfContext
* The pointer to the cy_stc_cryptolite_context_ecdsa_t.
*
* \param curveID
* The ECC curve id.
*
* \param privateKey
* The pointer to the ECC private key.
*
* \param GetRandomDataFunc
* See \ref cy_func_get_random_data_t.
*
* \param randomDataInfo
*
* \return status code. See \ref cy_en_cryptolite_status_t.
*
*******************************************************************************/
cy_en_cryptolite_status_t Cy_Cryptolite_ECC_MakePrivateKey(CRYPTOLITE_Type *base,
        cy_stc_cryptolite_context_ecdsa_t *cfContext,
        cy_en_cryptolite_ecc_curve_id_t curveID,
        const uint8_t *privateKey,
        cy_func_get_random_data_t GetRandomDataFunc, void *randomDataInfo)
{
    cy_en_cryptolite_status_t result = CY_CRYPTOLITE_BAD_PARAMS;
    const cy_stc_cryptolite_ecc_dp_type *eccDp;
    uint8_t *temp_ptr = NULL;

    /* NULL parameters checking */
     if ((base != NULL) && (cfContext != NULL) && (privateKey != NULL))
    {
        result = CY_CRYPTOLITE_NOT_SUPPORTED;
        eccDp = Cy_Cryptolite_ECC_GetCurveParams(curveID);

        if (eccDp != NULL)
        {
            uint8_t *p_u1 = cfContext->p_u1;
            uint8_t *p_o = cfContext->p_o;
            uint8_t *my_P = cfContext->my_P;
            uint8_t *my_BARRETT_U = cfContext->my_BARRETT_U;
            cy_stc_cryptolite_descr_t *vu_struct1 = &cfContext->vu_desptr[1];
            cy_stc_cryptolite_descr_t *vu_struct0 = &cfContext->vu_desptr[0];
            CY_ALIGN(4) uint8_t temp[VU_BITS_TO_BYTES(VU_TEST_EQUAL_LESS_SIZE+1U)]={0};
            uint32_t bitsize  = eccDp->size;
            uint32_t bytesize = VU_BITS_TO_BYTES(eccDp->size);
            cfContext->bitsize = bitsize;

            // Initialize point multiplication
            // load prime, order and barrett coefficient
            Cy_Cryptolite_Setnumber(my_P, (uint8_t *) eccDp->prime, bytesize);
            Cy_Cryptolite_Setnumber(p_o, (uint8_t *) eccDp->order, bytesize);
            Cy_Cryptolite_Setnumber(my_BARRETT_U, (uint8_t *) eccDp->barrett_p, VU_BITS_TO_BYTES(bitsize+1U));

            if (GetRandomDataFunc != NULL)
            {
                result = CY_CRYPTOLITE_HW_ERROR;
                if (GetRandomDataFunc( randomDataInfo, (uint8_t *)privateKey, bytesize ) == 0)
                {
                    Cy_Cryptolite_Vu_memcpy ((void *)p_u1, privateKey, bytesize);
                    result = CY_CRYPTOLITE_SUCCESS;
                }
            }
            else
            {
                temp_ptr = p_u1;

                #if (CRYPTOLITE_TRNG_PRESENT == 1) && defined(CY_CRYPTOLITE_CFG_TRNG_C)
                int32_t randomsize = (int32_t)bytesize;
                result = Cy_Cryptolite_Trng_Init(base, NULL);

                if(CY_CRYPTOLITE_SUCCESS != result)
                {
                    return result;
                }

                result = Cy_Cryptolite_Trng_Enable(base);

                while ((randomsize > 0) && (CY_CRYPTOLITE_SUCCESS == result))
                {
                    CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 11.3','Intentional pointer type conversion');
                    result = Cy_Cryptolite_Trng_ReadData(base, (uint32_t *)temp_ptr);
                    temp_ptr += 4u;
                    randomsize -= 4; 

                    if (CY_CRYPTOLITE_SUCCESS != result)
                    {
                        break;
                    }
                }

                Cy_Cryptolite_Vu_memcpy ((void *)privateKey, p_u1, bytesize);

                (void)Cy_Cryptolite_Trng_Disable(base);
                (void)Cy_Cryptolite_Trng_DeInit(base);
                #else
                (void)temp_ptr;
                result = CY_CRYPTOLITE_NOT_SUPPORTED;
                #endif
            }

            if(CY_CRYPTOLITE_SUCCESS == result)
            {
                if (Cy_Cryptolite_Vu_test_less_than(base, vu_struct1, p_u1, p_o, (uint16_t)bitsize) == false)
                {
                    (void)Cy_Cryptolite_Vu_mov_hw (base, vu_struct0, temp, VU_BITS_TO_WORDS(bitsize+1U), p_u1, VU_BITS_TO_WORDS(bitsize));
                    Cy_Cryptolite_EC_Bar_MulRed( base, cfContext, p_u1, temp, bitsize);
                }
                Cy_Cryptolite_Setnumber((uint8_t *)privateKey, p_u1, bytesize);
            }
        }
    }

    return result;
}

/*******************************************************************************
* Function Name: Cy_Cryptolite_ECC_MakePublicKey
****************************************************************************//*
*
* Generate a public key.
*
* \param base
* The pointer to a Cryptolite instance.
*
* \param cfContext
* The pointer to the cy_stc_cryptolite_context_ecdsa_t.
*
* \param curveID
* The ECC curve id.
*
* \param privateKey
* The pointer to the ECC private key.
*
* \param publicKey
* The generated public ECC key. See \ref cy_stc_cryptolite_ecc_key.
*
* \return status code. See \ref cy_en_cryptolite_status_t.
*
*******************************************************************************/
cy_en_cryptolite_status_t Cy_Cryptolite_ECC_MakePublicKey(CRYPTOLITE_Type *base,
        cy_stc_cryptolite_context_ecdsa_t *cfContext,
        cy_en_cryptolite_ecc_curve_id_t curveID,
        const uint8_t *privateKey,
        cy_stc_cryptolite_ecc_key *publicKey)
{

    cy_en_cryptolite_status_t result = CY_CRYPTOLITE_BAD_PARAMS;
    const cy_stc_cryptolite_ecc_dp_type *eccDp;

    /* NULL parameters checking */
     if ((base != NULL) && (cfContext != NULL) && (privateKey != NULL) && (publicKey != NULL) &&
        (publicKey->pubkey.x != NULL) && (publicKey->pubkey.y != NULL))
    {

        result = CY_CRYPTOLITE_NOT_SUPPORTED;
        eccDp = Cy_Cryptolite_ECC_GetCurveParams(curveID);

        if (eccDp != NULL)
        {
            uint8_t *p_u1 = cfContext->p_u1;
            uint8_t *p_o = cfContext->p_o;
            uint8_t *p_gx = cfContext->p_gx;
            uint8_t *p_gy = cfContext->p_gy;
            uint8_t *my_P = cfContext->my_P;
            uint8_t *my_BARRETT_U = cfContext->my_BARRETT_U;

            uint32_t bitsize  = eccDp->size;
            uint32_t bytesize = VU_BITS_TO_BYTES(eccDp->size);

            cfContext->bitsize = bitsize;

        
            // Initialize point multiplication
            // load prime, order and barrett coefficient
            Cy_Cryptolite_Setnumber(my_P, (uint8_t *) eccDp->prime, bytesize);
            Cy_Cryptolite_Setnumber(p_o, (uint8_t *) eccDp->order, bytesize);
            Cy_Cryptolite_Setnumber(my_BARRETT_U, (uint8_t *) eccDp->barrett_p, VU_BITS_TO_BYTES(bitsize+1U));

            // load base Point G
            Cy_Cryptolite_Setnumber(p_gx, (uint8_t *) eccDp->Gx, bytesize);
            Cy_Cryptolite_Setnumber(p_gy, (uint8_t *) eccDp->Gy, bytesize);            
            Cy_Cryptolite_Setnumber(p_u1, (uint8_t *)privateKey, bytesize);


            Cy_Cryptolite_EC_NistP_PointMul(base, cfContext, p_gx, p_gy, p_u1, p_o, (int)bitsize);

            Cy_Cryptolite_Setnumber((uint8_t *)publicKey->pubkey.x, (uint8_t *) p_gx, bytesize);
            Cy_Cryptolite_Setnumber((uint8_t *)publicKey->pubkey.y, (uint8_t *) p_gy, bytesize);

            result = CY_CRYPTOLITE_SUCCESS;

        }
        else 
        {
            result = CY_CRYPTOLITE_NOT_SUPPORTED;
        } 
    }
    return result;

}

#endif /* #if (CPUSS_CRYPTOLITE_VU == 1) */

#if defined(__cplusplus)
}
#endif

#endif /* CY_IP_MXCRYPTOLITE */
