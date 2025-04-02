/***************************************************************************//**
* \file cy_cryptolite_ecc_ec25519.c
* \version 2.80
*
* \brief
*  This file provides constant and parameters for the API for the ECC EC25519
*  in the Cryptolite driver. EC25519 is used for ECDH.
*
********************************************************************************
* \copyright
* Copyright (c) (2020-2024), Cypress Semiconductor Corporation (an Infineon company) or
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
#include "stdio.h"

#if defined (CY_IP_MXCRYPTOLITE)

#include "cy_sysint.h"
#include "cy_cryptolite_ecdsa.h"
#include "cy_cryptolite_nist_p.h"

#if defined(__cplusplus)
extern "C" {
#endif

#if defined(CY_CRYPTOLITE_CFG_EC25519_C)

#include "cy_cryptolite_utils.h"

#if defined(CY_CRYPTOLITE_CFG_EC25519_GENKEY_C)
#include "cy_cryptolite_trng.h"
#endif

/* curve const a24 size in bits*/
#define CY_ECC_EC25519_CURVE_SIZE_A (17u)

cy_en_cryptolite_status_t Cy_Cryptolite_EC25519_Mont_ladder (CRYPTOLITE_Type *base, cy_stc_cryptolite_context_ecdsa_t *cfContext, cy_stc_cryptolite_ec25519_dp_type *eccDp, const uint8_t *p_gx, const uint8_t *p_d, uint8_t *p_x, uint8_t *p_z );

/*******************************************************************************
* Function Name: Cy_Cryptolite_EC25519_Mont_ladder
****************************************************************************//**
*
* EC 25519 multiplication with montgomery ladder
*
* \param base
* The pointer to a Cryptolite instance.
*
* \param cfContext
* The pointer to the cy_stc_cryptolite_context_ecdsa_t.
*
* \param eccDp
* Structure defining domain parameters
*
* \param p_gx
* curve base point x.
*
* \param p_d
* Scalar value.
*
* \param p_x
* output x buffer of bit size value.
*
* \param p_z
* output z buffer of bit size value.
*
* \return status code. See \ref cy_en_cryptolite_status_t.
*******************************************************************************/
cy_en_cryptolite_status_t Cy_Cryptolite_EC25519_Mont_ladder (CRYPTOLITE_Type *base,
                                        cy_stc_cryptolite_context_ecdsa_t *cfContext,
                                        cy_stc_cryptolite_ec25519_dp_type *eccDp,
                                        const uint8_t *p_gx,
                                        const uint8_t *p_d,
                                        uint8_t *p_x,
                                        uint8_t *p_z )
{
    uint32_t i;
    uint8_t bit_curr;
    uint8_t swap;
    uint32_t bitpos;
    const uint8_t *pd_ptr = p_d;
    uint32_t bitsize = eccDp->size;
    cy_stc_cryptolite_descr_t *vu_struct0 = &cfContext->vu_desptr[0];
    cy_en_cryptolite_status_t tmpResult = CY_CRYPTOLITE_NOT_SUPPORTED;

    CY_ALIGN(4) uint8_t t1[VU_BITS_TO_BYTES(CY_CRYPTOLITE_ECC_EC25519_SIZE)]={0,};
    CY_ALIGN(4) uint8_t t2[VU_BITS_TO_BYTES(CY_CRYPTOLITE_ECC_EC25519_SIZE)]={0,};
    CY_ALIGN(4) uint8_t a[VU_BITS_TO_BYTES(CY_CRYPTOLITE_ECC_EC25519_SIZE)]={0,};
    CY_ALIGN(4) uint8_t x3[VU_BITS_TO_BYTES(CY_CRYPTOLITE_ECC_EC25519_SIZE)]={0,};
    CY_ALIGN(4) uint8_t z3[VU_BITS_TO_BYTES(CY_CRYPTOLITE_ECC_EC25519_SIZE)]={0,};

    uint8_t *x2 = p_x;
    const uint8_t *x1 = p_gx;
    uint8_t *z2 = p_z;

    CY_ALIGN(4) uint8_t temp[VU_BITS_TO_BYTES(CY_CRYPTOLITE_ECC_EC25519_SIZE)]={0,};

    Cy_Cryptolite_Setnumber(a,  (uint8_t *)CY_REMAP_ADDRESS_CRYPTOLITE(eccDp->a), CY_CRYPTOLITE_BYTE_SIZE_OF_BITS(CY_ECC_EC25519_CURVE_SIZE_A));
    /* compute r = (u*d)mod p */
    /*x1 = u, x2=1, x3=u, z2=0, z3=1*/
    x2[0] = 1u;
    z2[0] = 0u;


    // store pgx to a buffer
    (void)Cy_Cryptolite_Vu_mov_hw (base, vu_struct0, x3, VU_BITS_TO_WORDS(bitsize), (uint8_t *)x1, VU_BITS_TO_WORDS(bitsize));
    z3[0] = 1u;

    swap = 0u;
    bitpos = CY_CRYPTOLITE_ECC_EC25519_SIZE-1u;

    for (i = CY_CRYPTOLITE_ECC_EC25519_SIZE; i > 0u; i--)
    {
        bit_curr = (pd_ptr[bitpos >> 3u] >> (bitpos & 7u)) & 1u;
        bitpos--;
        swap = bit_curr ^ swap;

        if (swap != 0u)
        {
            //swap p_x, p_gx
            Cy_Cryptolite_Setnumber(temp,  x2, VU_BITS_TO_BYTES(bitsize));
            Cy_Cryptolite_Setnumber(x2,  x3, VU_BITS_TO_BYTES(bitsize));
            Cy_Cryptolite_Setnumber(x3,  temp, VU_BITS_TO_BYTES(bitsize));

            Cy_Cryptolite_Setnumber(temp,  z2, VU_BITS_TO_BYTES(bitsize));
            Cy_Cryptolite_Setnumber(z2,  z3, VU_BITS_TO_BYTES(bitsize));
            Cy_Cryptolite_Setnumber(z3,  temp, VU_BITS_TO_BYTES(bitsize));
        }

        swap = bit_curr;
        /*A = x_2 + z_2*/
        Cy_Cryptolite_EC_AddMod(base, cfContext, t1, x2, z2);
        /*B = x_2 - z_2*/
        Cy_Cryptolite_EC_SubMod( base, cfContext, t2, x2, z2);
        /*C = x_3 + z_3*/
        Cy_Cryptolite_EC_AddMod( base, cfContext, x2, x3, z3);
        /*D = x_3 - z_3*/
        Cy_Cryptolite_EC_SubMod( base, cfContext, z2, x3, z3);
        /*DA = D * A*/
        (void)Cy_Cryptolite_ED25519_MulMod( base, cfContext, z3, t1, z2, bitsize);
        /*CB = C * B*/
        (void)Cy_Cryptolite_ED25519_MulMod( base, cfContext, x3, t2, x2, bitsize);
        /*BB = B * B*/
        (void)Cy_Cryptolite_ED25519_SquareMod( base, cfContext, z2, t2, bitsize);
        /*AA = A * A*/
        (void)Cy_Cryptolite_ED25519_SquareMod( base, cfContext, t2, t1, bitsize);
        /*x_2 = AA * BB*/
        (void)Cy_Cryptolite_ED25519_MulMod( base, cfContext, x2, t2, z2, bitsize);

        /*E = AA - BB*/
        Cy_Cryptolite_EC_SubMod (base, cfContext, t1, t2, z2);
        /*(DA + CB)*/
        Cy_Cryptolite_EC_AddMod( base, cfContext, z2, x3, z3);
        /*(DA - CB)*/
        Cy_Cryptolite_EC_SubMod (base, cfContext, z3, x3, z3);
        /*(DA + CB)^2*/
        (void)Cy_Cryptolite_ED25519_SquareMod(base, cfContext, x3, z2, bitsize);//x2 to 3
        /*(DA - CB)^2*/
        (void)Cy_Cryptolite_ED25519_SquareMod(base, cfContext, z2, z3, bitsize);
        /*z_3 = x_1 * (DA - CB)^2*/
        (void)Cy_Cryptolite_ED25519_MulMod(base, cfContext, z3, z2, (uint8_t *)x1, bitsize);
        /*z_2 = E * (AA + a24 * E)*/
        (void)Cy_Cryptolite_ED25519_MulMod( base, cfContext, z2, t1, a, bitsize);
        Cy_Cryptolite_EC_AddMod( base, cfContext, t2, t2, z2);
        tmpResult = Cy_Cryptolite_ED25519_MulMod( base, cfContext, z2, t1, t2, bitsize);
    }

    if (swap != 0u)
    {
        Cy_Cryptolite_Setnumber(temp,  x2, VU_BITS_TO_BYTES(bitsize));
        Cy_Cryptolite_Setnumber(x2,  x3, VU_BITS_TO_BYTES(bitsize));
        Cy_Cryptolite_Setnumber(x3,  temp, VU_BITS_TO_BYTES(bitsize));

        Cy_Cryptolite_Setnumber(temp,  z2, VU_BITS_TO_BYTES(bitsize));
        Cy_Cryptolite_Setnumber(z2,  z3, VU_BITS_TO_BYTES(bitsize));
        Cy_Cryptolite_Setnumber(z3,  temp, VU_BITS_TO_BYTES(bitsize));
    }

    return tmpResult;
}

/*******************************************************************************
* Function Name: Cy_Cryptolite_EC25519_PointMultiplication
****************************************************************************//**
*
* EC25519 Elliptic curve point multiplication in GF(p).
*
* \param base
* The pointer to a Cryptolite instance.
*
* \param cfContext
* The pointer to the cy_stc_cryptolite_context_ecdsa_t.
*
* \param p_r
* Pointer to result point.
*
* \param p_x
* Pointer to X coordinate of base point.
*
* \param p_d
* Pointer to Scalar multiplication value.
*
* \return status code. See \ref cy_en_cryptolite_status_t.
*******************************************************************************/
cy_en_cryptolite_status_t Cy_Cryptolite_EC25519_PointMultiplication(CRYPTOLITE_Type *base,
                                                                    cy_stc_cryptolite_context_ecdsa_t *cfContext,
                                                                    uint8_t *p_r,
                                                                    const uint8_t *p_x,
                                                                    const uint8_t *p_d)
{
    /* Note: Pre conditions 0 < px, py < p-1 (consider randomizing the base point)*/

    uint32_t bitsize;

    uint8_t *pr_Remap;
    uint8_t *px_Remap;
    uint8_t *pd_Remap;

    CY_ALIGN(4) uint8_t my_p_x[VU_BITS_TO_BYTES(CY_CRYPTOLITE_ECC_EC25519_SIZE)]={0,};
    CY_ALIGN(4) uint8_t my_d[VU_BITS_TO_BYTES(CY_CRYPTOLITE_ECC_EC25519_SIZE)]={0,};
    CY_ALIGN(4) uint8_t my_s_z[VU_BITS_TO_BYTES(CY_CRYPTOLITE_ECC_EC25519_SIZE)]={0,};
    CY_ALIGN(4) uint8_t my_t_x[VU_BITS_TO_BYTES(CY_CRYPTOLITE_ECC_EC25519_SIZE)]={0,};

    cy_stc_cryptolite_descr_t *vu_struct0 = &cfContext->vu_desptr[0];
    cy_stc_cryptolite_descr_t *vu_struct1 = &cfContext->vu_desptr[1];
    cy_en_cryptolite_status_t tmpResult = CY_CRYPTOLITE_BAD_PARAMS;
    cy_en_cryptolite_ecc_curve_id_t curveID = CY_CRYPTOLITE_ECC_ECP_EC25519;


    cy_stc_cryptolite_ec25519_dp_type * edwDp = Cy_Cryptolite_EC25519_GetCurveParams(curveID);
    if(NULL == edwDp)
    {
        return CY_CRYPTOLITE_BAD_PARAMS;
    }

    if( p_r == NULL || p_x == NULL || p_d == NULL )
    {
        return CY_CRYPTOLITE_BAD_PARAMS;
    }

    pr_Remap = (uint8_t *)CY_REMAP_ADDRESS_CRYPTOLITE(p_r);
    px_Remap = (uint8_t *)CY_REMAP_ADDRESS_CRYPTOLITE(p_x);
    pd_Remap = (uint8_t *)CY_REMAP_ADDRESS_CRYPTOLITE(p_d);

    bitsize = edwDp->size;

    (void)Cy_Cryptolite_Vu_mov_hw (base, vu_struct0, my_p_x, VU_BITS_TO_WORDS(bitsize), (uint8_t *)px_Remap, VU_BITS_TO_WORDS(bitsize));
    (void)Cy_Cryptolite_Vu_mov_hw (base, vu_struct1, my_d, VU_BITS_TO_WORDS(bitsize), (uint8_t *)pd_Remap, VU_BITS_TO_WORDS(bitsize));

    /* Decode scalar(RFC-7748 sec-5)*/
    /* For EC25519, in order to decode 32 random bytes as an integer scalar, set the three
    least significant bits of the first byte and the most significant bit of the last to zero,
    set the second most significant bit of the last byte to 1 and, finally, decode as little-endian.
    */
   my_d[31] &= 0xF8u;
   my_d[0]  &= 0x7Fu;
   my_d[0]  |= 0x40u;

    Cy_Cryptolite_InvertEndianness((void *)my_d, (uint32_t)CY_CRYPTOLITE_ECC_ED25519_BYTE_SIZE);

    /* load prime defining the curve as well as the barrett coefficient. */
    Cy_Cryptolite_Setnumber(cfContext->my_P, (uint8_t *)CY_REMAP_ADDRESS_CRYPTOLITE(edwDp->prime), VU_BITS_TO_BYTES(bitsize));
    Cy_Cryptolite_Setnumber(cfContext->my_BARRETT_U, (uint8_t *)CY_REMAP_ADDRESS_CRYPTOLITE(edwDp->barrett_p), VU_BITS_TO_BYTES(edwDp->barret_psize));
    cfContext->bitsize = bitsize;

    /*point mul using montgomery ladder*/
    tmpResult = Cy_Cryptolite_EC25519_Mont_ladder (base, cfContext, edwDp, my_p_x, my_d, my_t_x, my_s_z);

    if(CY_CRYPTOLITE_SUCCESS == tmpResult)
    {
        /* Inverse transform (re-uses my_d and my_p_x) */
        Cy_Cryptolite_Memset(my_p_x, 0u, VU_BITS_TO_BYTES(CY_CRYPTOLITE_ECC_EC25519_SIZE));
        Cy_Cryptolite_Memset(my_d, 0u, VU_BITS_TO_BYTES(CY_CRYPTOLITE_ECC_EC25519_SIZE));

         /* t1 = 1 */
        my_p_x[0] = 1u;

        /* t2 = 1/Z */
        Cy_Cryptolite_EC_DivMod( base, cfContext, my_d, my_p_x, my_s_z, (int)bitsize);
        /* my_p_x = X/Z */
        tmpResult = Cy_Cryptolite_ED25519_MulMod( base, cfContext, my_p_x, my_t_x, my_d, bitsize);

    }

    /* get result in p_r */
    (void)Cy_Cryptolite_Vu_mov_hw (base, vu_struct0, pr_Remap, VU_BITS_TO_WORDS(bitsize), my_p_x, VU_BITS_TO_WORDS(bitsize));

    return tmpResult;
}

#if defined (CY_CRYPTOLITE_CFG_EC25519_GENKEY_C)
/*******************************************************************************
* Function Name: Cy_Cryptolite_EC25519_MakePrivateKey
****************************************************************************//**
*
* Make a new EC25519 private key
*
*
* \param base
* The pointer to a Cryptolite instance.
*
* \param cfContext
* The pointer to the cy_stc_cryptolite_context_ecdsa_t.
*
* \param privateKey
* [out] Destination of the newly created key.
*
* \param GetRandomDataFunc
* See \ref cy_func_get_random_data_t.
*
* \param randomDataInfo
* Argument for GetRandomDataFunc.
*
* \return status code. See \ref cy_en_cryptolite_status_t.
*
*******************************************************************************/
cy_en_cryptolite_status_t Cy_Cryptolite_EC25519_MakePrivateKey(CRYPTOLITE_Type *base,
        cy_stc_cryptolite_context_ecdsa_t *cfContext,
        uint8_t *privateKey,
        cy_func_get_random_data_t GetRandomDataFunc, void *randomDataInfo)
{
    cy_en_cryptolite_status_t result = CY_CRYPTOLITE_BAD_PARAMS;
    cy_en_cryptolite_ecc_curve_id_t curveID = CY_CRYPTOLITE_ECC_ECP_EC25519;

    const cy_stc_cryptolite_ec25519_dp_type *eccDp;
    uint8_t *temp_ptr;
    uint8_t *keyRemap;

    /* NULL parameters checking */
     if ((base != NULL) && (privateKey != NULL))
    {
        result = CY_CRYPTOLITE_NOT_SUPPORTED;
        eccDp = Cy_Cryptolite_EC25519_GetCurveParams(curveID);

        if (eccDp != NULL)
        {
            uint32_t bitsize = eccDp->size;
            uint32_t bytesize = CY_CRYPTOLITE_BYTE_SIZE_OF_BITS(bitsize);
            keyRemap = (uint8_t *)CY_REMAP_ADDRESS_CRYPTOLITE(privateKey);

            CY_ALIGN(4) uint8_t p_key[CY_CRYPTOLITE_BYTE_SIZE_OF_BITS(CY_CRYPTOLITE_ECC_EC25519_SIZE)]={0,};
            uint8_t *keyRegPtr = p_key;

            if (GetRandomDataFunc != NULL)
            {
                if (GetRandomDataFunc( randomDataInfo, (uint8_t *)keyRegPtr, bytesize ) != 0)
                {
                    result = CY_CRYPTOLITE_HW_ERROR;
                }
            }
            else
            {
                #if (CRYPTOLITE_TRNG_PRESENT == 1) && defined(CY_CRYPTOLITE_CFG_TRNG_C)
                int32_t randomsize = (int32_t)bytesize;
                temp_ptr = keyRegPtr;
                result = Cy_Cryptolite_Trng_Init(base, NULL);

                if(CY_CRYPTOLITE_SUCCESS != result)
                {
                    /* memset privateKey to 0 */
                    Cy_Cryptolite_Vu_memset(temp_ptr, 0, bytesize);
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

                (void)Cy_Cryptolite_Trng_Disable(base);
                (void)Cy_Cryptolite_Trng_DeInit(base);

                #else
                (void)temp_ptr;
                result = CY_CRYPTOLITE_NOT_SUPPORTED;
                #endif
            }

            if (CY_CRYPTOLITE_SUCCESS == result)
            {
                uint8_t *pd_ptr = (uint8_t*)keyRegPtr;
                Cy_Cryptolite_InvertEndianness(p_key, CY_CRYPTOLITE_BYTE_SIZE_OF_BITS(CY_CRYPTOLITE_ECC_EC25519_SIZE));

                /* [Curve25519] page 5 */
                /* Generate a (bitsize+1)-bit random number by generating just enough
                * random bytes, then shifting out extra bits from the top (necessary
                * when (bitsize+1) is not a multiple of 8). */
                if ((bytesize * 8u) > bitsize)
                {
                    /* Shift random data right */
                    cy_stc_cryptolite_descr_t *vu_struct0 = &cfContext->vu_desptr[0];
                    (void)Cy_Cryptolite_Vu_lsr_hw (base, vu_struct0, p_key, VU_BITS_TO_WORDS(bitsize), p_key, VU_BITS_TO_WORDS(bitsize), (bytesize * 8u) - bitsize);
                }

                /* Make sure the 255 bit is set and least three bits are unset for Curve25519 */
                pd_ptr[0]  &= 0xF8u;
                pd_ptr[31] &= 0x7Fu;
                pd_ptr[31] |= 0x40u;

                Cy_Cryptolite_Vu_memcpy ((void *)keyRemap, p_key, bytesize);

                result = CY_CRYPTOLITE_SUCCESS;
            }
        }
        else
        {
            result = CY_CRYPTOLITE_HW_ERROR;
        }

    }

    return result;
}

/*******************************************************************************
* Function Name: Cy_Cryptolite_EC25519_MakePublicKey
****************************************************************************//**
*
* Make a new EC25519 public key
*
*
* \param base
* The pointer to a Cryptolite instance.
*
* \param cfContext
* The pointer to the cy_stc_cryptolite_context_ecdsa_t.
*
* \param privateKey
* [in] Private key.
*
* \param publicKey
* [out] Newly created Public key.
* See \ref cy_stc_cryptolite_ecc_key.
*
* \return status code. See \ref cy_en_cryptolite_status_t.
*
*******************************************************************************/
cy_en_cryptolite_status_t Cy_Cryptolite_EC25519_MakePublicKey(CRYPTOLITE_Type *base,
        cy_stc_cryptolite_context_ecdsa_t *cfContext,
        const uint8_t *privateKey,
        cy_stc_cryptolite_ecc_key *publicKey)
{
    cy_en_cryptolite_status_t tmpResult = CY_CRYPTOLITE_BAD_PARAMS;
    cy_en_cryptolite_ecc_curve_id_t curveID = CY_CRYPTOLITE_ECC_ECP_EC25519;
    cy_stc_cryptolite_ec25519_dp_type *edwDp;
    uint8_t * privateKeyRemap;
    uint8_t * publicKeyXRemap;
    uint8_t * curvebasexRemap;

    /* NULL parameters checking */
     if ((base != NULL) && (cfContext != NULL) && (privateKey != NULL) && (publicKey != NULL) && (publicKey->pubkey.x != NULL))
    {
        tmpResult = CY_CRYPTOLITE_NOT_SUPPORTED;
        edwDp = Cy_Cryptolite_EC25519_GetCurveParams(curveID);

        if (edwDp != NULL)
        {
            privateKeyRemap = (uint8_t *)CY_REMAP_ADDRESS_CRYPTOLITE(privateKey);
            publicKeyXRemap = (uint8_t *)CY_REMAP_ADDRESS_CRYPTOLITE(publicKey->pubkey.x);
            curvebasexRemap = (uint8_t *)CY_REMAP_ADDRESS_CRYPTOLITE(edwDp->Gx);
            cfContext->bitsize = edwDp->size;

            /* make the public key EC scalar multiplication - X-only co-Z arithmetic */
            tmpResult = Cy_Cryptolite_EC25519_PointMultiplication( base, cfContext, publicKeyXRemap, (uint8_t const *)curvebasexRemap, (const uint8_t *)privateKeyRemap);

            publicKey->type = PK_PUBLIC;
            publicKey->curveID = curveID;
        }
    }

    return tmpResult;
}
#endif /* defined (CY_CRYPTOLITE_CFG_EC25519_GENKEY_C) */

#endif /* defined(CY_CRYPTOLITE_CFG_EC25519_C) */

#if defined(__cplusplus)
}
#endif

#endif /* CY_IP_MXCRYPTOLITE */
