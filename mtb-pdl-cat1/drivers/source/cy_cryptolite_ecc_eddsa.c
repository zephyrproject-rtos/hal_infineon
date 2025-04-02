/***************************************************************************//**
* \file cy_cryptolite_ecc_eddsa.c
* \version 2.80
*
* \brief
*  This file provides constant and parameters for the API for the ECC EDDSA
*  in the Cryptolite driver.
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

#if defined (CY_IP_MXCRYPTOLITE)

#include "cy_sysint.h"
#include "cy_cryptolite_ecdsa.h"
#include "cy_cryptolite_nist_p.h"

#if defined(__cplusplus)
extern "C" {
#endif

#if defined(CY_CRYPTOLITE_CFG_EDDSA_C) || defined(CY_CRYPTOLITE_CFG_EC25519_C)
#include "cy_cryptolite_utils.h"

cy_en_cryptolite_status_t Cy_Cryptolite_EDDSA_Bar_MulRed(CRYPTOLITE_Type *base, cy_stc_cryptolite_context_ecdsa_t *cfContext, uint8_t *p_z, uint32_t out_size, uint8_t *p_x, uint32_t in_size);
cy_en_cryptolite_status_t Cy_Cryptolite_ED25519_ExpMod(CRYPTOLITE_Type *base, cy_stc_cryptolite_context_ecdsa_t *cfContext, uint8_t *p_x, uint8_t *p_y, uint8_t *p_e, uint32_t bitsize);
cy_en_cryptolite_status_t Cy_Cryptolite_ED25519Add(CRYPTOLITE_Type *base,
                                    cy_stc_cryptolite_context_ecdsa_t *cfContext,
                                    cy_stc_cryptolite_ec25519_dp_type *edwDp,
                                    uint8_t *s_x, uint8_t *s_y, uint8_t *s_z,
                                    uint8_t *t_x, uint8_t *t_y, uint32_t size);
cy_en_cryptolite_status_t Cy_Cryptolite_ED25519Double(CRYPTOLITE_Type *base,
                                    cy_stc_cryptolite_context_ecdsa_t *cfContext,
                                    cy_stc_cryptolite_ec25519_dp_type *edwDp,
                                    uint8_t *s_x, uint8_t *s_y, uint8_t *s_z, uint32_t size);
cy_en_cryptolite_status_t Cy_Cryptolite_ED25519InvTransform(CRYPTOLITE_Type *base,
                                    cy_stc_cryptolite_context_ecdsa_t *cfContext,
                                    uint8_t *s_x, uint8_t *s_y, uint8_t *s_z, uint32_t size);
cy_en_cryptolite_status_t Cy_Cryptolite_ED25519_PointMul(CRYPTOLITE_Type *base,
                                    cy_stc_cryptolite_context_ecdsa_t *cfContext,
                                    cy_stc_cryptolite_ec25519_dp_type *edwDp,
                                    uint8_t *p_x, uint8_t *p_y, uint8_t *p_d, uint32_t bitsize);
cy_en_cryptolite_status_t Cy_Cryptolite_ED25519_PointMulAdd(CRYPTOLITE_Type *base,
                                    cy_stc_cryptolite_context_ecdsa_t *cfContext,
                                    cy_stc_cryptolite_ec25519_dp_type *edwDp,
                                    uint8_t *p_x, uint8_t *p_y, uint8_t *s,
                                    uint8_t *q_x, uint8_t *q_y, uint8_t *h,
                                    uint32_t bitsize);

#define CY_ED25519SIG_VERIFY_PASS (0xA1A1A1A1u)
#define CY_ED25519SIG_VERIFY_FAIL (0x00BADBADu)


/*******************************************************************************
* Function Name: Cy_Cryptolite_ED25519_Init
****************************************************************************//**
*
* Init ED25519 Context.
*
* \param base
* The pointer to a Cryptolite instance.
*
* \param cfContext
* The pointer to the cy_stc_cryptolite_context_ecdsa_t.
*
* \param eccBuffer
* The pointer to the cy_stc_cryptolite_ecc_buffer_t.
*
* \param shaFunctions
* The pointer to the cy_stc_cryptolite_ed25519_sha512_t.
*
* \return status code. See \ref cy_en_cryptolite_status_t.
*
*******************************************************************************/
cy_en_cryptolite_status_t Cy_Cryptolite_ED25519_Init(CRYPTOLITE_Type *base,
                                cy_stc_cryptolite_context_ecdsa_t *cfContext,
                                cy_stc_cryptolite_ecc_buffer_t *eccBuffer,
                                cy_stc_cryptolite_ed25519_sha512_t *shaFunctions)
{
    cy_en_cryptolite_status_t status;

    if ((base == NULL) || (cfContext == NULL) || (eccBuffer == NULL) || (shaFunctions == NULL))
    {
        return CY_CRYPTOLITE_BAD_PARAMS;
    }

    if ((shaFunctions->shactx == NULL) || (shaFunctions->sha_init == NULL) || (shaFunctions->sha_start == NULL) ||
        (shaFunctions->sha_update == NULL) || (shaFunctions->sha_finish == NULL) || (shaFunctions->sha_free == NULL))
    {
        return CY_CRYPTOLITE_BAD_PARAMS;
    }

    status = Cy_Cryptolite_ECC_Init(base, cfContext, eccBuffer);
    if (status != CY_CRYPTOLITE_SUCCESS)
    {
        return status;
    }

    cfContext->ed25519_sha = shaFunctions;

    return status;
}


/*******************************************************************************
* Function Name: Cy_Cryptolite_ED25519_Free
****************************************************************************//**
*
* Free ED25519 Context.
*
* \param base
* The pointer to a Cryptolite instance.
*
* \param cfContext
* The pointer to the cy_stc_cryptolite_context_ecdsa_t.
*
* \return status code. See \ref cy_en_cryptolite_status_t.
*
*******************************************************************************/
cy_en_cryptolite_status_t Cy_Cryptolite_ED25519_Free(CRYPTOLITE_Type *base,
                                cy_stc_cryptolite_context_ecdsa_t *cfContext)
{
    cy_stc_cryptolite_ed25519_sha512_t *ed25519_sha;
    cy_en_cryptolite_status_t status = Cy_Cryptolite_ECC_Free(base, cfContext);
    if (status != CY_CRYPTOLITE_SUCCESS)
    {
        return status;
    }
    else
    {
        ed25519_sha = cfContext->ed25519_sha;
        status = ed25519_sha->sha_free(ed25519_sha->shactx);
        cfContext->ed25519_sha = NULL;

        return status;
    }

}


/*******************************************************************************
* Function Name: Cy_Cryptolite_EDDSA_Bar_MulRed
****************************************************************************//**
*
* Barrett multiplication modular reduction.
* r = t mod p for known value of p
* r = t - (floor[t * 1/p]*p)
* VR_BARRET = | (1 << 2*bitsize)/ p |
* q = floor([t * VR_BARRETT] >> 2*bitsize)
* r = t - p*q
*
* r = IF (r >= p) r = r - p           - reduce r using mod
* r = IF (r >= p) r = r - p
*
* \param base
* The pointer to a Cryptolite instance.
*
* \param cfContext
* The pointer to the cy_stc_cryptolite_context_ecdsa_t.
*
* \param p_z
* Buffer pointer for Barrett reduced value.
*
* \param out_size
* Output buffer size in bits.
*
* \param p_x
* Buffer pointer for non reduced value.
*
* \param in_size
* Input buffer size in bits.
*
* \return status code. See \ref cy_en_cryptolite_status_t.
*******************************************************************************/
cy_en_cryptolite_status_t Cy_Cryptolite_EDDSA_Bar_MulRed(CRYPTOLITE_Type *base,
                                    cy_stc_cryptolite_context_ecdsa_t *cfContext,
                                    uint8_t *p_z,
                                    uint32_t out_size,
                                    uint8_t *p_x,
                                    uint32_t in_size)
{
    CY_ALIGN(4) uint8_t t_double[VU_BITS_TO_BYTES((CY_CRYPTOLITE_ECC_ED25519_SIZE*3u)+7u)]={0,};
    CY_ALIGN(4) uint8_t t1[VU_BITS_TO_BYTES(CY_CRYPTOLITE_ECC_ED25519_SIZE+4u)]={0,};
    CY_ALIGN(4) uint8_t t1_plus2[VU_BITS_TO_BYTES(CY_CRYPTOLITE_ECC_ED25519_SIZE+2u)]={0,};
    CY_ALIGN(4) uint8_t t2_plus2[VU_BITS_TO_BYTES(CY_CRYPTOLITE_ECC_ED25519_SIZE+2u)]={0,};

    uint8_t *z_double = p_x;
    uint8_t *my_z = p_z;
    uint16_t sh = 512u;

    uint8_t *my_P = cfContext->my_P;
    uint8_t *my_BARRETT_U = cfContext->my_BARRETT_U;

    cy_stc_cryptolite_descr_t *vu_struct0 = &cfContext->vu_desptr[0U];
    cy_stc_cryptolite_descr_t *vu_struct1 = &cfContext->vu_desptr[1U];


    /* x*factor */
    (void)Cy_Cryptolite_Vu_mul_hw (base, vu_struct0, t_double, VU_BITS_TO_WORDS((out_size*3u)+7u), (uint8_t *)z_double, VU_BITS_TO_WORDS(in_size), my_BARRETT_U, VU_BITS_TO_WORDS(out_size+8u));

    /* (x * self.factor) >> self.shift) */
    (void)Cy_Cryptolite_Vu_lsr_hw (base, vu_struct1, t1, VU_BITS_TO_WORDS(out_size+4u), t_double, VU_BITS_TO_WORDS((out_size*3u)+7u), sh);

    /* (x * self.factor) >> self.shift) * mod */
    (void)Cy_Cryptolite_Vu_mul_hw (base, vu_struct0, t_double, VU_BITS_TO_WORDS((out_size*3u)+7u), t1, VU_BITS_TO_WORDS(out_size+4u), my_P, VU_BITS_TO_WORDS(out_size));

    /* t = (x - ((x * self.factor) >> self.shift) * mod) */
    (void)Cy_Cryptolite_Vu_sub_hw(base, vu_struct1, t2_plus2, VU_BITS_TO_WORDS(out_size+2u), (uint8_t *)z_double, VU_BITS_TO_WORDS(in_size), t_double, VU_BITS_TO_WORDS((out_size*3u)+7u));

    /* check if t < mod, then result = t. else result = t-mod */
    if (Cy_Cryptolite_Vu_test_less_than(base, vu_struct1, t2_plus2, my_P, (uint16_t)out_size))
    {
        Cy_Cryptolite_Setnumber(my_z, t2_plus2, VU_BITS_TO_BYTES(out_size));
    }
    else
    {
        /* t1_plus2 = t - mod */
        (void)Cy_Cryptolite_Vu_sub_hw(base, vu_struct0, t1_plus2, VU_BITS_TO_WORDS(out_size+2u), t2_plus2, VU_BITS_TO_WORDS(out_size+2u), my_P, VU_BITS_TO_WORDS(out_size));
        Cy_Cryptolite_Setnumber(my_z, t1_plus2, VU_BITS_TO_BYTES(out_size));
    }

    return CY_CRYPTOLITE_SUCCESS;

}


/*******************************************************************************
* Function Name: Cy_Cryptolite_ED25519_MulMod
****************************************************************************//**
*
* Modular multiplication in GF(VR_P).
* Leaf function.
*
* \param base
* The pointer to a Cryptolite instance.
*
* \param cfContext
* The pointer to the cy_stc_cryptolite_context_ecdsa_t.
*
* \param z
* Result = a * b % mod. The pointer to product value.
*
* \param a
* The pointer to multiplicand value.
*
* \param b
* The pointer to multiplier value.
*
* \param size
* Bit size.
*
* \return status code. See \ref cy_en_cryptolite_status_t.
*******************************************************************************/
cy_en_cryptolite_status_t Cy_Cryptolite_ED25519_MulMod( CRYPTOLITE_Type *base,
                                    cy_stc_cryptolite_context_ecdsa_t *cfContext,
                                    uint8_t *p_z,
                                    uint8_t *p_a,
                                    uint8_t *p_b,
                                    uint32_t size)
{
    cy_en_cryptolite_status_t tmpResult = CY_CRYPTOLITE_NOT_SUPPORTED;
    CY_ALIGN(4) uint8_t ab_double[VU_BITS_TO_BYTES(CY_CRYPTOLITE_ECC_ED25519_SIZE*2u)]={0,};
    cy_stc_cryptolite_descr_t *vu_struct0 = &cfContext->vu_desptr[0U];
    uint8_t *my_z = p_z;
    uint8_t *my_a = p_a;
    uint8_t *my_b = p_b;

    (void)Cy_Cryptolite_Vu_mul_hw (base, vu_struct0, ab_double, VU_BITS_TO_WORDS(2U*size), my_a, VU_BITS_TO_WORDS(size), my_b, VU_BITS_TO_WORDS(size));

    /* Barrett reduction result stored in p_z */
    tmpResult = Cy_Cryptolite_EDDSA_Bar_MulRed(base, cfContext, my_z, size, ab_double, (CY_CRYPTOLITE_ECC_ED25519_SIZE*2u));

    return tmpResult;
}

/*******************************************************************************
* Function Name: Cy_Cryptolite_ED25519_SquareMod
****************************************************************************//**
*
* Modular squaring in GF(VR_P).
*
* \param base
* The pointer to a Cryptolite instance.
*
* \param cfContext
* The pointer to the cy_stc_cryptolite_context_ecdsa_t.
*
* \param z
* Result = a * a % mod. The pointer to product value.
*
* \param a
* The pointer to multiplicand and multiplier value.
*
* \param size
* Bit size.
*
* \return status code. See \ref cy_en_cryptolite_status_t.
*******************************************************************************/
cy_en_cryptolite_status_t Cy_Cryptolite_ED25519_SquareMod( CRYPTOLITE_Type *base,
                                    cy_stc_cryptolite_context_ecdsa_t *cfContext,
                                    uint8_t *p_z,
                                    uint8_t *p_a,
                                    uint32_t size)
{
    return Cy_Cryptolite_ED25519_MulMod( base, cfContext, p_z, p_a, p_a, size);
}

#if defined(CY_CRYPTOLITE_CFG_EDDSA_C)
static void Cy_Cryptolite_ED25519_dom2_ctx(CRYPTOLITE_Type *base,
                                            cy_stc_cryptolite_context_ecdsa_t *cfContext,
                                            cy_en_cryptolite_eddsa_sig_type_t sigType,
                                            const uint8_t *ctx,
                                            uint32_t ctx_len )
{
    uint8_t ct_init_string[] = "SigEd25519 no Ed25519 collisions";
    uint8_t ct_flag;
    uint8_t ct_ctx_len = (uint8_t)(ctx_len & 0xffu);
    cy_stc_cryptolite_ed25519_sha512_t *ed25519_sha = cfContext->ed25519_sha;

    (void)base;

    ct_flag = (sigType == CY_CRYPTOLITE_EDDSA_CTX)? (uint8_t)0: (uint8_t)1;
    /*Note: Can merge to one update call*/
    (void)ed25519_sha->sha_update(ed25519_sha->shactx, (uint8_t const*)ct_init_string, 32u);
    (void)ed25519_sha->sha_update(ed25519_sha->shactx, (uint8_t const*)&ct_flag, 1u);
    (void)ed25519_sha->sha_update(ed25519_sha->shactx, (uint8_t const*)&ct_ctx_len,1u);

    if( ctx != NULL && ctx_len > 0u)
    {
        (void)ed25519_sha->sha_update(ed25519_sha->shactx, ctx, ctx_len);
    }

}

/*******************************************************************************
* Function Name: Cy_Cryptolite_ED25519Add
****************************************************************************//**
* ED25519 (Edwards and Twisted Edwards) point add on projective coordinates in GF(VR_P).
*
* Add for: R = P + Q
*
* https://hyperelliptic.org/EFD/g1p/auto-code/twisted/projective/addition/add-2008-bbjlp.op3
* with
* P = (X1, Z1)
* Q = (X2, Z2)
* R = (X3, Z3)
* and eliminating temporary variables t0, t3, ..., t9.
*
* Cost: 10M + 1S
*
* \param base
* The pointer to a Cryptolite instance.
*
* \param cfContext
* The pointer to the cy_stc_cryptolite_context_ecdsa_t.
*
* \param s_x
* The pointer to projective X coordinate.
*
* \param s_y
* The pointer to projective Y coordinate.
*
* \param s_z
* The pointer to projective Z coordinate.
*
* \param t_x
* The pointer to affine X coordinate.
*
* \param t_y
* The pointer to affine Y coordinate.
*
* \param size
* Bit size.
*
* \return status code. See \ref cy_en_cryptolite_status_t.
*******************************************************************************/
cy_en_cryptolite_status_t Cy_Cryptolite_ED25519Add(CRYPTOLITE_Type *base,
                            cy_stc_cryptolite_context_ecdsa_t *cfContext,
                            cy_stc_cryptolite_ec25519_dp_type *edwDp,
                            uint8_t *s_x,
                            uint8_t *s_y,
                            uint8_t *s_z,
                            uint8_t *t_x,
                            uint8_t *t_y,
                            uint32_t size)
{
    CY_ALIGN(4) uint8_t t1[VU_BITS_TO_BYTES(CY_CRYPTOLITE_ECC_ED25519_SIZE)]={0,};
    CY_ALIGN(4) uint8_t b[VU_BITS_TO_BYTES(CY_CRYPTOLITE_ECC_ED25519_SIZE)]={0,};
    CY_ALIGN(4) uint8_t c[VU_BITS_TO_BYTES(CY_CRYPTOLITE_ECC_ED25519_SIZE)]={0,};
    CY_ALIGN(4) uint8_t d[VU_BITS_TO_BYTES(CY_CRYPTOLITE_ECC_ED25519_SIZE)]={0,};
    CY_ALIGN(4) uint8_t e[VU_BITS_TO_BYTES(CY_CRYPTOLITE_ECC_ED25519_SIZE)]={0,};
    CY_ALIGN(4) uint8_t f[VU_BITS_TO_BYTES(CY_CRYPTOLITE_ECC_ED25519_SIZE)]={0,};
    CY_ALIGN(4) uint8_t g[VU_BITS_TO_BYTES(CY_CRYPTOLITE_ECC_ED25519_SIZE)]={0,};
    uint8_t *my_s_x = s_x;
    uint8_t *my_s_y = s_y;
    uint8_t *my_s_z = s_z;
    uint8_t *my_t_x = t_x;
    uint8_t *my_t_y = t_y;
    uint8_t *t2;

    cy_en_cryptolite_status_t tmpResult = CY_CRYPTOLITE_NOT_SUPPORTED;

    /* A = Z1*Z2 */
    /* Z2 = 1 skip first step
    Note: Revisit if we randomize the base points*/
    /* B = A^2 */
    tmpResult = Cy_Cryptolite_ED25519_SquareMod( base, cfContext, b, my_s_z, size);
    if(CY_CRYPTOLITE_SUCCESS != tmpResult)
    {
        return tmpResult;
    }
    /* C = X1*X2 */
    tmpResult =Cy_Cryptolite_ED25519_MulMod( base, cfContext, c, my_s_x, my_t_x, size);
    if(CY_CRYPTOLITE_SUCCESS != tmpResult)
    {
        return tmpResult;
    }
    /* D = Y1*Y2 */
    tmpResult =Cy_Cryptolite_ED25519_MulMod( base, cfContext, d, my_s_y, my_t_y, size);
    if(CY_CRYPTOLITE_SUCCESS != tmpResult)
    {
        return tmpResult;
    }
    /* E = d*C*D */
    (void)Cy_Cryptolite_Memcpy(base, t1, (uint8_t *)edwDp->d, VU_BITS_TO_BYTES(size));
    tmpResult =Cy_Cryptolite_ED25519_MulMod( base, cfContext, f, c, d, size);
    if(CY_CRYPTOLITE_SUCCESS != tmpResult)
    {
        return tmpResult;
    }

    tmpResult =Cy_Cryptolite_ED25519_MulMod( base, cfContext, e, f, t1, size);
    if(CY_CRYPTOLITE_SUCCESS != tmpResult)
    {
        return tmpResult;
    }
    /* F = B-E */
    Cy_Cryptolite_EC_SubMod( base, cfContext, f, b, e);
    /* G = B+E */
    Cy_Cryptolite_EC_AddMod( base, cfContext, g, b, e);
    /* X3 = A*F*((X1+Y1)*(X2+Y2)-C-D) */
    t2 = b;
    Cy_Cryptolite_EC_AddMod( base, cfContext, t1, my_s_x, my_s_y);
    Cy_Cryptolite_EC_AddMod( base, cfContext, t2, my_t_x, my_t_y);

    tmpResult =Cy_Cryptolite_ED25519_MulMod( base, cfContext, my_s_x, t1, t2, size);
    if(CY_CRYPTOLITE_SUCCESS != tmpResult)
    {
        return tmpResult;
    }

    Cy_Cryptolite_EC_SubMod( base, cfContext, my_s_x, my_s_x, c);
    Cy_Cryptolite_EC_SubMod( base, cfContext, my_s_x, my_s_x, d);

    tmpResult = Cy_Cryptolite_ED25519_MulMod( base, cfContext, t1, my_s_z, f, size);
    if(CY_CRYPTOLITE_SUCCESS != tmpResult)
    {
        return tmpResult;
    }

    tmpResult = Cy_Cryptolite_ED25519_MulMod( base, cfContext, my_s_x, my_s_x, t1, size);
    if(CY_CRYPTOLITE_SUCCESS != tmpResult)
    {
        return tmpResult;
    }

    /* Y3 = A*G*(D-a*C) */
    (void)Cy_Cryptolite_Memcpy(base, t1, (uint8_t *)edwDp->a, VU_BITS_TO_BYTES(size));
    tmpResult =Cy_Cryptolite_ED25519_MulMod( base, cfContext, t2, my_s_z, g, size);
    if(CY_CRYPTOLITE_SUCCESS != tmpResult)
    {
        return tmpResult;
    }

    tmpResult =Cy_Cryptolite_ED25519_MulMod( base, cfContext, t1, t1, c, size);
    if(CY_CRYPTOLITE_SUCCESS != tmpResult)
    {
        return tmpResult;
    }

    Cy_Cryptolite_EC_SubMod( base, cfContext, my_s_y, d, t1);
    tmpResult =Cy_Cryptolite_ED25519_MulMod( base, cfContext, my_s_y, my_s_y, t2, size);
    if(CY_CRYPTOLITE_SUCCESS != tmpResult)
    {
        return tmpResult;
    }

    /* Z3 = F*G */
    tmpResult = Cy_Cryptolite_ED25519_MulMod( base, cfContext, my_s_z, f, g, size);

    return tmpResult;

}

/*******************************************************************************
* Function Name: Cy_Cryptolite_ED25519Double
****************************************************************************//**
*
* ED25519 (Edwards and Twisted Edwards) point doubling on projective coordinates in GF(VR_P).
*
* Double for: R = 2 * P for both Edwards and Twisted Edwards curves in projective
* coordinates.
*
* https://hyperelliptic.org/EFD/g1p/auto-code/twisted/projective/doubling/dbl-2008-bbjlp.op3
* with
* P = (X1, Z1)
* R = (X3, Z3)
* and eliminating H and temporary variables t0, ..., t4.
*
* Cost: 3M + 4S
*
* \param base
* The pointer to a Cryptolite instance.
*
* \param cfContext
* The pointer to the cy_stc_cryptolite_context_ecdsa_t.
*
* \param s_x
* The pointer to projective X coordinate.
*
* \param s_y
* The pointer to projective Y coordinate.
*
* \param s_z
* The pointer to projective Z coordinate.
*
* \param size
* Bit size.
*
* \return status code. See \ref cy_en_cryptolite_status_t.
*******************************************************************************/
cy_en_cryptolite_status_t Cy_Cryptolite_ED25519Double(CRYPTOLITE_Type *base,
                                cy_stc_cryptolite_context_ecdsa_t *cfContext,
                                cy_stc_cryptolite_ec25519_dp_type *edwDp,
                                uint8_t *s_x,
                                uint8_t *s_y,
                                uint8_t *s_z,
                                uint32_t size)
/* 3M + 4S */
{
    CY_ALIGN(4) uint8_t b[VU_BITS_TO_BYTES(CY_CRYPTOLITE_ECC_ED25519_SIZE)]={0,};
    CY_ALIGN(4) uint8_t c[VU_BITS_TO_BYTES(CY_CRYPTOLITE_ECC_ED25519_SIZE)]={0,};
    CY_ALIGN(4) uint8_t d[VU_BITS_TO_BYTES(CY_CRYPTOLITE_ECC_ED25519_SIZE)]={0,};
    CY_ALIGN(4) uint8_t e[VU_BITS_TO_BYTES(CY_CRYPTOLITE_ECC_ED25519_SIZE)]={0,};
    CY_ALIGN(4) uint8_t f[VU_BITS_TO_BYTES(CY_CRYPTOLITE_ECC_ED25519_SIZE)]={0,};
    CY_ALIGN(4) uint8_t j[VU_BITS_TO_BYTES(CY_CRYPTOLITE_ECC_ED25519_SIZE)]={0,};
    uint8_t *my_s_x = s_x;
    uint8_t *my_s_y = s_y;
    uint8_t *my_s_z = s_z;

    cy_en_cryptolite_status_t tmpResult = CY_CRYPTOLITE_BAD_PARAMS;

    (void)Cy_Cryptolite_Memcpy(base, f, (uint8_t *)edwDp->a, VU_BITS_TO_BYTES(size));
    /* B = (X1 + Y1)^2 */
    Cy_Cryptolite_EC_AddMod( base, cfContext, b, my_s_x, my_s_y);
    tmpResult = Cy_Cryptolite_ED25519_SquareMod( base, cfContext, b, b, size);
    if(CY_CRYPTOLITE_SUCCESS != tmpResult)
    {
        return tmpResult;
    }
    /* C = X1^2 */
    tmpResult = Cy_Cryptolite_ED25519_SquareMod( base, cfContext, c, my_s_x, size);
    if(CY_CRYPTOLITE_SUCCESS != tmpResult)
    {
        return tmpResult;
    }
    /* D = Y1^2 */
    tmpResult = Cy_Cryptolite_ED25519_SquareMod( base, cfContext, d, my_s_y, size);
    if(CY_CRYPTOLITE_SUCCESS != tmpResult)
    {
        return tmpResult;
    }
    /* E = eddp->a*C */
    tmpResult = Cy_Cryptolite_ED25519_MulMod( base, cfContext, e, f, c, size);
    if(CY_CRYPTOLITE_SUCCESS != tmpResult)
    {
        return tmpResult;
    }
    /* F = E+D */
    Cy_Cryptolite_EC_AddMod( base, cfContext, f, e, d);
    /* J = F - 2*(Z1^2) */
    tmpResult = Cy_Cryptolite_ED25519_SquareMod( base, cfContext, j, my_s_z, size);
    if(CY_CRYPTOLITE_SUCCESS != tmpResult)
    {
        return tmpResult;
    }
    /*2*(Z1^2) mod p*/
    Cy_Cryptolite_EC_AddMod( base, cfContext, j, j, j);
    Cy_Cryptolite_EC_SubMod (base, cfContext, j, f, j);
    /* X3 = (B-C-D)*J */
    Cy_Cryptolite_EC_SubMod (base, cfContext, b, b, c);
    Cy_Cryptolite_EC_SubMod (base, cfContext, b, b, d);
    tmpResult = Cy_Cryptolite_ED25519_MulMod( base, cfContext, my_s_x, b, j, size);
    if(CY_CRYPTOLITE_SUCCESS != tmpResult)
    {
        return tmpResult;
    }
    /* Y3 = F*(E-D) */
    Cy_Cryptolite_EC_SubMod (base, cfContext, e, e, d);
    tmpResult = Cy_Cryptolite_ED25519_MulMod( base, cfContext, my_s_y, f, e, size);
    if(CY_CRYPTOLITE_SUCCESS != tmpResult)
    {
        return tmpResult;
    }
    /* Z3 = F*J */
    tmpResult = Cy_Cryptolite_ED25519_MulMod( base, cfContext, my_s_z, f, j, size);

    return tmpResult;
}

/*******************************************************************************
* Function Name: Cy_Cryptolite_ED25519InvTransform
****************************************************************************//**
*
* Transformation from projective coordinates to affine coordinates in GF(VR_P).
* (s_x, s_y, s_z) -> (p_x, p_y), where p_x = s_x/s_z, p_y = s_y/s_z
*
* \param base
* The pointer to a Cryptolite instance.
*
* \param cfContext
* The pointer to the cy_stc_cryptolite_context_ecdsa_t.
*
* \param s_x
* Pointer to affine X coordinate and projective X coordinate.
*
* \param s_y
* Pointer to affine Y coordinate and projective Y coordinate.
*
* \param s_z
* Pointer to projective Z coordinate.
*
* \param size
* Bit size.
*
* \return status code. See \ref cy_en_cryptolite_status_t.
*******************************************************************************/
cy_en_cryptolite_status_t Cy_Cryptolite_ED25519InvTransform(CRYPTOLITE_Type *base,
                                                            cy_stc_cryptolite_context_ecdsa_t *cfContext,
                                                            uint8_t *s_x,
                                                            uint8_t *s_y,
                                                            uint8_t *s_z,
                                                            uint32_t size)
{
    CY_ALIGN(4) uint8_t t1[VU_BITS_TO_BYTES(CY_CRYPTOLITE_ECC_ED25519_SIZE)]={0,};
    CY_ALIGN(4) uint8_t t2[VU_BITS_TO_BYTES(CY_CRYPTOLITE_ECC_ED25519_SIZE)]={0,};
    cy_en_cryptolite_status_t tmpResult = CY_CRYPTOLITE_BAD_PARAMS;
    uint8_t *my_s_x = s_x;
    uint8_t *my_s_y = s_y;
    uint8_t *my_s_z = s_z;

    t1[0] = 1u;

    Cy_Cryptolite_EC_DivMod( base, cfContext, t2, t1, my_s_z, (int)size);  /* t2 = 1/Z */

    tmpResult = Cy_Cryptolite_ED25519_MulMod( base, cfContext, my_s_x, my_s_x, t2, size);  /* my_s_x = X/Z */
    if(CY_CRYPTOLITE_SUCCESS != tmpResult)
    {
        return tmpResult;
    }

    tmpResult = Cy_Cryptolite_ED25519_MulMod( base, cfContext, my_s_y, my_s_y, t2, size);  /* t3 = Y/Z */
    if(CY_CRYPTOLITE_SUCCESS != tmpResult)
    {
        return tmpResult;
    }

    return CY_CRYPTOLITE_SUCCESS;
}

/*******************************************************************************
* Function Name: Cy_Cryptolite_ED25519_PointMulAdd
****************************************************************************//**
*
* Edward 25519 Elliptic curve point multiply-Add in GF(p).
*
* R = s*P + h*Q
*
* \param base
* The pointer to a Cryptolite instance.
*
* \param cfContext
* The pointer to the cy_stc_cryptolite_context_ecdsa_t.
*
* \param p_x
* Pointer to affine X coordinate of point.
*
* \param p_y
* Pointer to affine Y coordinate of point.
*
* \param s
* Pointer to multiplication value.
*
* \param q_x
* Pointer to affine X coordinate of point.
*
* \param q_y
* Pointer to affine Y coordinate of point.
*
* \param h
* Pointer to for multiplication value.
*
* \param bitsize
* Bit size of the used curve.
*
* \return status code. See \ref cy_en_cryptolite_status_t.
*******************************************************************************/
cy_en_cryptolite_status_t Cy_Cryptolite_ED25519_PointMulAdd(CRYPTOLITE_Type *base,
                                    cy_stc_cryptolite_context_ecdsa_t *cfContext,
                                    cy_stc_cryptolite_ec25519_dp_type *edwDp,
                                    uint8_t *p_x, uint8_t *p_y, uint8_t *s,
                                    uint8_t *q_x, uint8_t *q_y, uint8_t *h,
                                    uint32_t bitsize)
{
    /* Note: Pre conditions 0 < (px,py)(qx,qy) < N-1 */
    CY_ALIGN(4) uint8_t p_z[VU_BITS_TO_BYTES(CY_CRYPTOLITE_ECC_ED25519_SIZE)]={0,};
    uint8_t *my_s = s;
    uint8_t *my_P = cfContext->my_P;
    uint8_t *my_BARRETT_U = cfContext->my_BARRETT_U;
    cy_en_cryptolite_status_t tmpResult = CY_CRYPTOLITE_BAD_PARAMS;

    /* load prime defining the curve as well as the barrett coefficient. */
    (void)Cy_Cryptolite_Memcpy(base, my_P, (uint8_t *)edwDp->prime, VU_BITS_TO_BYTES(bitsize));
    (void)Cy_Cryptolite_Memcpy(base, my_BARRETT_U, (uint8_t *)edwDp->barrett_p, VU_BITS_TO_BYTES(edwDp->barret_psize));

    /* init point->z to 1. */
    p_z[0] = 1u;

    /*sB = point_mul(s, G)*/
    tmpResult = Cy_Cryptolite_ED25519_PointMul( base, cfContext, edwDp, p_x, p_y, my_s, bitsize);
    if(CY_CRYPTOLITE_SUCCESS != tmpResult)
    {
        return tmpResult;
    }
    /*hA = point_mul(h, A)*/
    tmpResult = Cy_Cryptolite_ED25519_PointMul(base, cfContext, edwDp, q_x, q_y, h, bitsize);
    if(CY_CRYPTOLITE_SUCCESS != tmpResult)
    {
        return tmpResult;
    }
    /* R = point_add(sB, hA) */
    /* RFC Sec 5.1.7 Check the group equation [S]B = R + [k]A'.  It's sufficient.
       We perform fast single-signature verification by computing R = [s]B + [-k]A'. compressing 'R' and comparing with Sig[R] without
       decompressing it.
    */
    tmpResult = Cy_Cryptolite_ED25519Add (base, cfContext, edwDp, p_x, p_y, p_z, q_x, q_y, bitsize);
    if(CY_CRYPTOLITE_SUCCESS != tmpResult)
    {
        return tmpResult;
    }
    /* Inverse transform */
    tmpResult = Cy_Cryptolite_ED25519InvTransform(base, cfContext, p_x, p_y, p_z, bitsize);

    return tmpResult;
}

/*******************************************************************************
* Function Name: Cy_Cryptolite_ED25519_PointMul
****************************************************************************//**
*
* Edward 25519 Elliptic curve point multiplication in GF(p).
*
* \param base
* The pointer to a Cryptolite instance.
*
* \param cfContext
* The pointer to the cy_stc_cryptolite_context_ecdsa_t.
*
* \param p_x
* Pointer to affine X coordinate of base point.
*
* \param p_y
* Pointer to affine Y coordinate of base point.
*
* \param p_d
* Pointer to multiplication value.
*
* \param bitsize
* Bit size of the used curve.
*
* \return status code. See \ref cy_en_cryptolite_status_t.
*******************************************************************************/
cy_en_cryptolite_status_t Cy_Cryptolite_ED25519_PointMul(CRYPTOLITE_Type *base,
                                                        cy_stc_cryptolite_context_ecdsa_t *cfContext,
                                                        cy_stc_cryptolite_ec25519_dp_type *edwDp,
                                                        uint8_t *p_x,
                                                        uint8_t *p_y,
                                                        uint8_t *p_d,
                                                        uint32_t bitsize)
{
    /* Note: Pre conditions 0 < px, py < p-1 (consider randomizing the base point)*/

    uint32_t i;
    uint32_t carry;
    uint32_t clsame;
    uint32_t loop;

    CY_ALIGN(4) uint8_t my_t_x[VU_BITS_TO_BYTES(CY_CRYPTOLITE_ECC_ED25519_SIZE)]={0,};
    CY_ALIGN(4) uint8_t my_t_y[VU_BITS_TO_BYTES(CY_CRYPTOLITE_ECC_ED25519_SIZE)]={0,};
    CY_ALIGN(4) uint8_t my_s_z[VU_BITS_TO_BYTES(CY_CRYPTOLITE_ECC_ED25519_SIZE)]={0,};
    CY_ALIGN(4) uint8_t my_d[VU_BITS_TO_BYTES(CY_CRYPTOLITE_ECC_ED25519_SIZE)]={0,};
    uint8_t *my_s_x = p_x;
    uint8_t *my_s_y = p_y;

    uint8_t *my_P = cfContext->my_P;
    uint8_t *my_BARRETT_U = cfContext->my_BARRETT_U;
    cy_stc_cryptolite_descr_t *vu_struct0 = &cfContext->vu_desptr[0];
    cy_en_cryptolite_status_t tmpResult = CY_CRYPTOLITE_BAD_PARAMS;

    /* load prime defining the curve as well as the barrett coefficient. */
    Cy_Cryptolite_Setnumber(my_P, (uint8_t *) edwDp->prime, VU_BITS_TO_BYTES(bitsize));
    Cy_Cryptolite_Setnumber(my_BARRETT_U, (uint8_t *) edwDp->barrett_p, VU_BITS_TO_BYTES(edwDp->barret_psize));
    cfContext->bitsize = bitsize;

    Cy_Cryptolite_Setnumber(my_t_x, my_s_x, VU_BITS_TO_BYTES(bitsize)); // move my_s_x -> my_t_x
    Cy_Cryptolite_Setnumber(my_t_y, my_s_y, VU_BITS_TO_BYTES(bitsize)); // move my_s_y -> my_t_y
    Cy_Cryptolite_Setnumber(my_d, p_d, VU_BITS_TO_BYTES(bitsize)); // move p_d -> my_d

    /* init point->z to 1. */
    my_s_z[0] = 1u;

    clsame = Cy_Cryptolite_GetCLSAME (my_d, VU_BITS_TO_BYTES(bitsize));

    /* Get rid of leading '0's and '1' */
    Cy_Cryptolite_Vu_lsl (my_d, VU_BITS_TO_WORDS(bitsize), p_d, VU_BITS_TO_WORDS(bitsize), clsame+1u);

    /* Binary left-to-right algorithm
    * Perform point addition and point doubling to implement scalar multiplication
    * Scan the bits of the scalar from left to right; perform point doubling for each bit,
    * and perform point addition when the bit is set.
    * Carry set if current bit is equal to 1 (hence, perform point addition - point
    * doubling is always performed)
    */
    if( bitsize >= clsame)
    {
        loop = (uint32_t)(bitsize - clsame);
    }
    else
    {
        return CY_CRYPTOLITE_HW_ERROR;
    }

    for (i = 0; i < (loop); i++)
    {
        /* Carry set if current bit is equal to 1 (hence, perform point addition - point
        * doubling is always performed)
        */
        carry =  Cy_Cryptolite_Vu_get_bit(my_d, bitsize);
        (void)Cy_Cryptolite_Vu_lsl1_hw (base, vu_struct0, my_d, VU_BITS_TO_WORDS(bitsize), my_d, VU_BITS_TO_WORDS(bitsize));


        tmpResult = Cy_Cryptolite_ED25519Double (base, cfContext, edwDp, my_s_x, my_s_y, my_s_z, bitsize);

        if(CY_CRYPTOLITE_SUCCESS != tmpResult)
        {
            return tmpResult;
        }

        if (carry != 0u)
        {
            tmpResult = Cy_Cryptolite_ED25519Add (base, cfContext, edwDp, my_s_x, my_s_y, my_s_z, my_t_x, my_t_y, bitsize);

            if(CY_CRYPTOLITE_SUCCESS != tmpResult)
            {
                return tmpResult;
            }
        }

    }

    /* Inverse transform */
    tmpResult = Cy_Cryptolite_ED25519InvTransform(base, cfContext, my_s_x, my_s_y, my_s_z, bitsize);

    return tmpResult;
}

/*******************************************************************************
* Function Name: Cy_Cryptolite_ED25519_PointMultiplication
****************************************************************************//**
*
* Edwards 25519 elliptic curve point multiplication in GF(p).
*
* \param base
* The pointer to a Cryptolite instance.
*
* \param cfContext
* The pointer to the cy_stc_cryptolite_context_ecdsa_t.
*
* \param ecpGX
* X coordinate of base point.
*
* \param ecpGY
* Y coordinate of base point.
*
* \param ecpD
* multiplication scalar value.
*
* \param ecpQX
* X coordinate of result point.
*
* \param ecpQY
* Y coordinate of result point.
*
* \return status code. See \ref cy_en_cryptolite_status_t.
*
*******************************************************************************/
cy_en_cryptolite_status_t Cy_Cryptolite_ED25519_PointMultiplication(CRYPTOLITE_Type *base,
                                        cy_stc_cryptolite_context_ecdsa_t *cfContext,
                                        const uint8_t *ecpGX,
                                        const uint8_t *ecpGY,
                                        const uint8_t *ecpD,
                                        uint8_t *ecpQX,
                                        uint8_t *ecpQY)
{
    cy_en_cryptolite_status_t tmpResult = CY_CRYPTOLITE_NOT_SUPPORTED;
    cy_stc_cryptolite_ec25519_dp_type *edwDp;
    CY_ALIGN(4) uint8_t VR_S_X[VU_BITS_TO_BYTES(CY_CRYPTOLITE_ECC_ED25519_SIZE)]={0,};
    CY_ALIGN(4) uint8_t VR_S_Y[VU_BITS_TO_BYTES(CY_CRYPTOLITE_ECC_ED25519_SIZE)]={0,};
    CY_ALIGN(4) uint8_t VR_D[VU_BITS_TO_BYTES(CY_CRYPTOLITE_ECC_ED25519_SIZE)]={0,};

    cy_en_cryptolite_ecc_curve_id_t curveID = CY_CRYPTOLITE_ECC_ECP_ED25519;

    edwDp = Cy_Cryptolite_EC25519_GetCurveParams(curveID);
    if (edwDp != NULL)
    {
        uint32_t bitsize;

        bitsize   = edwDp->size;
        tmpResult = CY_CRYPTOLITE_BAD_PARAMS;
        cfContext->bitsize = bitsize;

        if ((NULL != ecpGX) && (NULL != ecpGY) && (NULL != ecpD) && (NULL != ecpQX) && (NULL != ecpQY))
        {
            Cy_Cryptolite_Setnumber(VR_S_X, (uint8_t *)ecpGX, VU_BITS_TO_BYTES(bitsize));
            Cy_Cryptolite_Setnumber(VR_S_Y, (uint8_t *)ecpGY, VU_BITS_TO_BYTES(bitsize));
            Cy_Cryptolite_Setnumber(VR_D, (uint8_t *)ecpD, VU_BITS_TO_BYTES(bitsize));

            /* Public parameters and characteristics of elliptic curve */
            /* ECC calculation: d * G mod p */
            tmpResult = Cy_Cryptolite_ED25519_PointMul(base, cfContext, edwDp, VR_S_X, VR_S_Y, VR_D, bitsize);
            if(CY_CRYPTOLITE_SUCCESS != tmpResult)
            {
                return tmpResult;
            }
            /* Get result P = (X,Y) = d.G from Ed25519 scalar multiplication */
            (void)Cy_Cryptolite_Memcpy (base, ecpQX, VR_S_X, VU_BITS_TO_BYTES(bitsize));
            (void)Cy_Cryptolite_Memcpy (base, ecpQY, VR_S_Y, VU_BITS_TO_BYTES(bitsize));

            tmpResult = CY_CRYPTOLITE_SUCCESS;
        }
    }
    return tmpResult;
}

#endif /* defined(CY_CRYPTOLITE_CFG_EDDSA_C) */

#if defined (CY_CRYPTOLITE_CFG_EDDSA_GENKEY_C)

/*******************************************************************************
* Function Name: Cy_Cryptolite_ED25519_MakePublicKey
****************************************************************************//**
*
* Make a new ED25519 public key
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
cy_en_cryptolite_status_t Cy_Cryptolite_ED25519_MakePublicKey(CRYPTOLITE_Type *base,
                                                            cy_stc_cryptolite_context_ecdsa_t *cfContext,
                                                            const uint8_t *privateKey,
                                                            cy_stc_cryptolite_ecc_key *publicKey)
{
    cy_en_cryptolite_status_t tmpResult = CY_CRYPTOLITE_NOT_SUPPORTED;
    cy_stc_cryptolite_ec25519_dp_type *eccDp;
    cy_en_cryptolite_ecc_curve_id_t curveID = CY_CRYPTOLITE_ECC_ECP_ED25519;

    if ((base != NULL) && (cfContext != NULL) && (cfContext->ed25519_sha != NULL) && (privateKey != NULL) && (publicKey != NULL) &&
    (publicKey->pubkey.x != NULL) && (publicKey->pubkey.y != NULL))
    {
        eccDp = Cy_Cryptolite_EC25519_GetCurveParams(curveID);
        if (eccDp != NULL)
        {
            uint8_t *p_u1 = cfContext->p_u1;
            uint8_t *p_o = cfContext->p_o;
            uint8_t *p_gx = cfContext->p_gx;
            uint8_t *p_gy = cfContext->p_gy;
            uint8_t *my_P = cfContext->my_P;
            uint8_t *my_BARRETT_U = cfContext->my_BARRETT_U;
            CY_ALIGN(4) uint8_t p_sha[CY_CRYPTOLITE_SHA512_HASH_SIZE];
            CY_ALIGN(4) uint8_t p_d[VU_BITS_TO_BYTES(CY_CRYPTOLITE_ECC_ED25519_SIZE+1)];
            cy_stc_cryptolite_ed25519_sha512_t *ed25519_sha = cfContext->ed25519_sha;

            uint32_t bitsize  = eccDp->size;
            uint32_t bytesize = VU_BITS_TO_BYTES(eccDp->size);

            cfContext->bitsize = bitsize;

            tmpResult = ed25519_sha->sha_init(ed25519_sha->shactx);
            if (CY_CRYPTOLITE_SUCCESS == tmpResult)
            {
                tmpResult = ed25519_sha->sha_start(ed25519_sha->shactx);
                if(CY_CRYPTOLITE_SUCCESS != tmpResult)
                {
                    return tmpResult;
                }
            }
            else
            {
                return tmpResult;
            }

            // Initialize point multiplication
            // load prime, order and barrett coefficient
            Cy_Cryptolite_Setnumber(my_P, (uint8_t *) eccDp->prime, bytesize);
            Cy_Cryptolite_Setnumber(p_o, (uint8_t *) eccDp->order, bytesize);
            Cy_Cryptolite_Setnumber(my_BARRETT_U, (uint8_t *) eccDp->barrett_p, VU_BITS_TO_BYTES(bitsize+1U));

            // load base Point G
            Cy_Cryptolite_Setnumber(p_gx, (uint8_t *) eccDp->Gx, bytesize);
            Cy_Cryptolite_Setnumber(p_gy, (uint8_t *) eccDp->Gy, bytesize);
            Cy_Cryptolite_Setnumber(p_u1, (uint8_t *)privateKey, bytesize);

            /*step1: Compute secret scalar 's' and prefix*/
            /*SHA expects big-endian input*/
            tmpResult = ed25519_sha->sha_update(ed25519_sha->shactx, (uint8_t const*)privateKey, bytesize);
            if(CY_CRYPTOLITE_SUCCESS == tmpResult)
            {
                tmpResult = ed25519_sha->sha_finish(ed25519_sha->shactx, p_sha); // output in p_sha
                if(CY_CRYPTOLITE_SUCCESS != tmpResult)
                {
                    return tmpResult;
                }
            }
            else
            {
                return tmpResult;
            }


            /*Prune the buffer: The lowest three bits of the first octet are cleared, the highest bit of the last octet is cleared,
            and the second highest bit of the last octet is set.*/
            p_sha[0]  &= ~((uint8_t)0x7);
            p_sha[31] &= ~((uint8_t)0x80);
            p_sha[31] |= (uint8_t)0x40;

            Cy_Cryptolite_Setnumber(p_d, (uint8_t *)&p_sha[0], VU_BITS_TO_BYTES(bitsize+1u));

            /*s = p_sha[0-31] prefix = p_sha[32-63]*/
            tmpResult = Cy_Cryptolite_ED25519_PointMul(base, cfContext, eccDp, p_gx, p_gy, p_d, bitsize);
            if(CY_CRYPTOLITE_SUCCESS != tmpResult)
            {
                return tmpResult;
            }

            Cy_Cryptolite_Setnumber((uint8_t *)publicKey->pubkey.x, (uint8_t *) p_gx, bytesize);
            Cy_Cryptolite_Setnumber((uint8_t *)publicKey->pubkey.y, (uint8_t *) p_gy, bytesize);
            publicKey->type = PK_PUBLIC;
            publicKey->curveID = curveID;

            tmpResult = CY_CRYPTOLITE_SUCCESS;
        }

    }
    return (tmpResult);
}

#endif /* defined (CY_CRYPTOLITE_CFG_EDDSA_GENKEY_C) */

#if defined(CY_CRYPTOLITE_CFG_EDDSA_SIGN_C)

/*******************************************************************************
* Function Name: Cy_Cryptolite_ED25519_Sign
****************************************************************************//**
*
* Sign a message.
*
* \param base
* The pointer to a Cryptolite instance.
*
* \param cfContext
* The pointer to the cy_stc_cryptolite_context_ecdsa_t.
*
* \param hash
* The message to sign. Provided as is in data buffer. This is usually the hash of
* the original data to be signed.
*
* \param hashlen
* The length of the message in bytes.
*
* \param sig
* [out] The destination for the signature, 'r' followed by 's'.
*
* \param key
* Key (Little Endian) used for signature generation. See \ref cy_stc_cryptolite_ecc_key.
*
* \param sigType
* signature Type. CY_CRYPTOLITE_EDDSA_PURE,CY_CRYPTOLITE_EDDSA_CTX or CY_CRYPTOLITE_EDDSA_PREHASH
*
* \param sigctx
* signature context. can be NULL if EDDSA_PURE is used or if no context is provided.
*
* \param sigctx_len
* The length of the signature context
*
* \return status code. See \ref cy_en_cryptolite_status_t.
*
* \funcusage
* \snippet cryptolite/snippet/main.c snippet_Cy_Cryptolite_Ed25519_sign_verify
*
*******************************************************************************/
cy_en_cryptolite_status_t Cy_Cryptolite_ED25519_Sign(CRYPTOLITE_Type *base,
                                                    cy_stc_cryptolite_context_ecdsa_t *cfContext,
                                                    const uint8_t *hash,
                                                    uint32_t hashlen,
                                                    uint8_t *sig,
                                                    const cy_stc_cryptolite_ecc_key *key,
                                                    cy_en_cryptolite_eddsa_sig_type_t sigType,
                                                    const uint8_t *sigctx,
                                                    uint32_t sigctx_len)
{
    cy_en_cryptolite_status_t tmpResult = CY_CRYPTOLITE_BAD_PARAMS;
    cy_stc_cryptolite_ec25519_dp_type *eccDp;

    /* input param validation */
    if ( hash == NULL && 0u != hashlen )
    {
        return CY_CRYPTOLITE_BAD_PARAMS;
    }
    /*
    Value of context is set by the signer and verifier (maximum of 255
    octets; the default is empty string, except for Ed25519, which can't
    have context) and has to match octet by octet for verification to be
    successful.
    */
    if(sigType != CY_CRYPTOLITE_EDDSA_PURE)
    {
        if(sigType == CY_CRYPTOLITE_EDDSA_CTX)
        {
            if( sigctx == NULL  || sigctx_len == 0u || sigctx_len > 255u)
            {
                return CY_CRYPTOLITE_BAD_PARAMS;
            }
        }
        else
        {
            if (sigType == CY_CRYPTOLITE_EDDSA_PREHASH && hashlen != CY_CRYPTOLITE_SHA512_HASH_SIZE)
            {
                return CY_CRYPTOLITE_BAD_PARAMS;
            }
        }
    }

    if ((cfContext->ed25519_sha != NULL) && (sig != NULL) && (key != NULL) && (sigType < CY_CRYPTOLITE_EDDSA_NONE))
    {
        tmpResult = CY_CRYPTOLITE_NOT_SUPPORTED;
        eccDp = Cy_Cryptolite_EC25519_GetCurveParams(key->curveID);
        if (eccDp != NULL)
        {
            CY_ALIGN(4) uint8_t p_sha[CY_CRYPTOLITE_SHA512_HASH_SIZE]={0,};

            CY_ALIGN(4) uint8_t p_temp[CY_CRYPTOLITE_ECC_ED25519_BYTE_SIZE]={0,};
            CY_ALIGN(4) uint8_t p_x[CY_CRYPTOLITE_ECC_ED25519_BYTE_SIZE]={0,};
            CY_ALIGN(4) uint8_t p_y[CY_CRYPTOLITE_ECC_ED25519_BYTE_SIZE]={0,};

            //uint8_t *p_temp = cfContext->p_buf;
            uint8_t *p_r = cfContext->p_r;
            uint8_t *p_s = cfContext->p_s;
            uint8_t *p_gx = cfContext->p_gx;
            uint8_t *p_gy = cfContext->p_gy;
            uint8_t *my_P = cfContext->my_P;
            uint8_t *my_BARRETT_U = cfContext->my_BARRETT_U;

            uint8_t *digest;
            uint8_t *scalar;
            uint8_t *prefix;
            uint8_t *pubkey_x;
            uint8_t *pubkey_y;
            uint8_t *r_x;
            uint8_t *r_y;
            cy_stc_cryptolite_descr_t *vu_struct0 = &cfContext->vu_desptr[0];
            cy_stc_cryptolite_descr_t *vu_struct1 = &cfContext->vu_desptr[1];
            cy_stc_cryptolite_ed25519_sha512_t *ed25519_sha = cfContext->ed25519_sha;
            uint32_t bitsize  = eccDp->size;
            uint32_t bytesize = VU_BITS_TO_BYTES(eccDp->size);

            // load prime, order and barrett coefficient
            Cy_Cryptolite_Setnumber(my_P, (uint8_t *) eccDp->order, bytesize);
            Cy_Cryptolite_Setnumber(my_BARRETT_U, (uint8_t *) eccDp->barrett_o, VU_BITS_TO_BYTES(eccDp->barret_osize));
            cfContext->bitsize = bitsize;

            // load base Point G
            Cy_Cryptolite_Setnumber(p_gx, (uint8_t *) eccDp->Gx, bytesize);
            Cy_Cryptolite_Setnumber(p_gy, (uint8_t *) eccDp->Gy, bytesize);
            Cy_Cryptolite_Setnumber(p_x, (uint8_t *) eccDp->Gx, bytesize);
            Cy_Cryptolite_Setnumber(p_y, (uint8_t *) eccDp->Gy, bytesize);

            Cy_Cryptolite_Vu_memset(p_r, 0, bytesize);

            digest = p_sha; // digest points to sha memory location

            //sha init
            tmpResult = ed25519_sha->sha_init(ed25519_sha->shactx);
            if (CY_CRYPTOLITE_SUCCESS != tmpResult)
            {
                return tmpResult;
            }
            //sha start
            tmpResult = ed25519_sha->sha_start(ed25519_sha->shactx);
            if (CY_CRYPTOLITE_SUCCESS != tmpResult)
            {
                return tmpResult;
            }

            /*step1: Compute secret scalar 's' and prefix*/
            /*SHA expects big-endian*/
            //sha update
            tmpResult = ed25519_sha->sha_update(ed25519_sha->shactx, (uint8_t const*)key->k, bytesize);
            if (CY_CRYPTOLITE_SUCCESS != tmpResult)
            {
                return tmpResult;
            }
            tmpResult = ed25519_sha->sha_finish(ed25519_sha->shactx, digest);
            if (CY_CRYPTOLITE_SUCCESS != tmpResult)
            {
                return tmpResult;
            }

            /*Prune the buffer: The lowest three bits of the first octet are cleared, the highest bit of the last octet is cleared,
            and the second highest bit of the last octet is set.*/
            digest[0]  &= ~((uint8_t)0x7);
            digest[31] &= ~((uint8_t)0x80);
            digest[31] |= (uint8_t)0x40;

            /*s = digest[0-31] prefix = digest[32-63]*/
            scalar = &digest[0];
            prefix = &digest[32];

            /* store scalar value in p_s */
            Cy_Cryptolite_Setnumber(p_s, (uint8_t *)scalar, (CY_CRYPTOLITE_SHA512_HASH_SIZE >> 1u));

            /* generate pubKey A = [s]B */
            tmpResult =  Cy_Cryptolite_ED25519_PointMul(base, cfContext, eccDp, p_gx, p_gy, p_s, bitsize);
            if(CY_CRYPTOLITE_SUCCESS != tmpResult)
            {
                return tmpResult;
            }

            //update pubkey_x and pubkey_y
            pubkey_x = p_gx;
            pubkey_y = p_gy;

            /* step2: 'r' computation */
            tmpResult = ed25519_sha->sha_init(ed25519_sha->shactx);
            if (tmpResult != CY_CRYPTOLITE_SUCCESS)
            {
                return tmpResult;
            }
            //sha start
            tmpResult = ed25519_sha->sha_start(ed25519_sha->shactx);
            if (tmpResult != CY_CRYPTOLITE_SUCCESS)
            {
                return tmpResult;
            }

            /* EDDSA sig mode as per 5.1 RFC 8032 */
            if(sigType != CY_CRYPTOLITE_EDDSA_PURE)
            {
                Cy_Cryptolite_ED25519_dom2_ctx( base, cfContext, sigType, sigctx, sigctx_len);
            }
            /*update prefix and input hash */
            tmpResult = ed25519_sha->sha_update(ed25519_sha->shactx, (uint8_t const*)prefix, (CY_CRYPTOLITE_SHA512_HASH_SIZE >> 1u));
            if (tmpResult != CY_CRYPTOLITE_SUCCESS)
            {
                return tmpResult;
            }
            tmpResult = ed25519_sha->sha_update(ed25519_sha->shactx, (uint8_t const*)hash, hashlen);
            if (tmpResult != CY_CRYPTOLITE_SUCCESS)
            {
                return tmpResult;
            }
            tmpResult = ed25519_sha->sha_finish(ed25519_sha->shactx, digest);
            if (tmpResult != CY_CRYPTOLITE_SUCCESS)
            {
                return tmpResult;
            }

            /* reload prime, order and barrett coefficient incase it is overridden */
            Cy_Cryptolite_Setnumber(my_P, (uint8_t *) eccDp->order, bytesize);
            Cy_Cryptolite_Setnumber(my_BARRETT_U, (uint8_t *) eccDp->barrett_o, VU_BITS_TO_BYTES(eccDp->barret_osize));

            /* Mod reduction modulo n (order of the base point in VR_P and barret_o in VR_BARRET) */
            if ( CY_CRYPTOLITE_SUCCESS != Cy_Cryptolite_EDDSA_Bar_MulRed(base, cfContext, p_r, bitsize, p_sha, (CY_CRYPTOLITE_SHA512_HASH_SIZE*8u)) )
            {
                return CY_CRYPTOLITE_BAD_PARAMS;
            }

            /* Step 3 */
            tmpResult = Cy_Cryptolite_ED25519_PointMul(base, cfContext, eccDp, p_x, p_y, p_r, bitsize);
            if(CY_CRYPTOLITE_SUCCESS != tmpResult)
            {
                return tmpResult;
            }

            /*Note: key encode/decode can be a separate function helps verify */
            /* encode point: From RFC 5.1.2, we shall copy LSB of x to the MSB of y */
            /* Test p_x for odd */
            r_x = p_x;
            r_y = p_y;
            if((bool)(((uint8_t*)r_x)[0] & (uint8_t)0x01))
            {
                ((uint8_t*)r_y)[31] = ((uint8_t*)r_y)[31] | (uint8_t)0x80;
            }
            /* Copy r to sig result */
            Cy_Cryptolite_Setnumber((uint8_t *)&sig[0], (uint8_t *) p_y, bytesize);


            /* Step4: 's' computation */
            tmpResult = ed25519_sha->sha_init(ed25519_sha->shactx);
            if (tmpResult != CY_CRYPTOLITE_SUCCESS)
            {
                return tmpResult;
            }
            tmpResult = ed25519_sha->sha_start(ed25519_sha->shactx);
            if (tmpResult != CY_CRYPTOLITE_SUCCESS)
            {
                return tmpResult;
            }
            /* EDDSA sig mode as per 5.1 RFC 8032 */
            if(sigType != CY_CRYPTOLITE_EDDSA_PURE)
            {
                Cy_Cryptolite_ED25519_dom2_ctx( base, cfContext, sigType, sigctx, sigctx_len);
            }
            tmpResult = ed25519_sha->sha_update(ed25519_sha->shactx, (uint8_t const*)r_y, bytesize);
            if (tmpResult != CY_CRYPTOLITE_SUCCESS)
            {
                return tmpResult;
            }
            /*Note: key encode/decode can be a separate function */
            /* encode point: From RFC 5.1.2, we shall copy LSB of x to the MSB of y */
            if((bool)(((uint8_t*)pubkey_x)[0] & (uint8_t)0x01))
            {
                ((uint8_t*)pubkey_y)[31] = ((uint8_t*)pubkey_y)[31] | (uint8_t)0x80;
            }
            tmpResult = ed25519_sha->sha_update(ed25519_sha->shactx, (uint8_t const*)pubkey_y, bytesize);
            if (tmpResult != CY_CRYPTOLITE_SUCCESS)
            {
                return tmpResult;
            }
            tmpResult = ed25519_sha->sha_update(ed25519_sha->shactx, (uint8_t const*)hash, hashlen);
            if (tmpResult != CY_CRYPTOLITE_SUCCESS)
            {
                return tmpResult;
            }
            tmpResult = ed25519_sha->sha_finish(ed25519_sha->shactx, digest);
            if (tmpResult != CY_CRYPTOLITE_SUCCESS)
            {
                return tmpResult;
            }


            /* reload prime, order and barrett coefficient incase it is overridden */
            Cy_Cryptolite_Setnumber(my_P, (uint8_t *) eccDp->order, bytesize);
            Cy_Cryptolite_Setnumber(my_BARRETT_U, (uint8_t *) eccDp->barrett_o, VU_BITS_TO_BYTES(eccDp->barret_osize));
            /* step5 */
            /* Mod reduction modulo n (order of the base point in VR_P and barret_o in VR_BARRET) */
            if ( CY_CRYPTOLITE_SUCCESS != Cy_Cryptolite_EDDSA_Bar_MulRed(base, cfContext, p_temp, bitsize, p_sha, (CY_CRYPTOLITE_SHA512_HASH_SIZE*8u)) )
            {
                return CY_CRYPTOLITE_BAD_PARAMS;
            }

            (void)Cy_Cryptolite_Vu_mul_hw(base, vu_struct0, p_sha, VU_BYTES_TO_WORDS(CY_CRYPTOLITE_SHA512_HASH_SIZE), p_temp, VU_BITS_TO_WORDS(bitsize), p_s, VU_BITS_TO_WORDS(bitsize));
            (void)Cy_Cryptolite_Vu_add_hw(base, vu_struct1, p_sha, VU_BYTES_TO_WORDS(CY_CRYPTOLITE_SHA512_HASH_SIZE), p_sha, VU_BYTES_TO_WORDS(CY_CRYPTOLITE_SHA512_HASH_SIZE), p_r, VU_BITS_TO_WORDS(bitsize));

            /* Mod reduction modulo n (order of the base point in VR_P and barret_o in VR_BARRET) */
            if ( CY_CRYPTOLITE_SUCCESS != Cy_Cryptolite_EDDSA_Bar_MulRed(base, cfContext, p_s, bitsize, p_sha, (CY_CRYPTOLITE_SHA512_HASH_SIZE*8u)))
            {
                return CY_CRYPTOLITE_HW_ERROR;
            }

            /* copy s to sig buffer*/
            if ((Cy_Cryptolite_Vu_test_zero(base, vu_struct0, p_s, (uint16_t)bitsize) != true))
            {
                /* S is not zero!!! */
                Cy_Cryptolite_Setnumber((uint8_t *)&sig[bytesize], (uint8_t *) p_s, bytesize);
            }
            else
            {
                tmpResult = CY_CRYPTOLITE_HW_ERROR;
            }

        }
    }
    return (tmpResult);
}

#endif /* defined(CY_CRYPTOLITE_CFG_EDDSA_SIGN_C) */

/*******************************************************************************
* Function Name: Cy_Cryptolite_ED25519_ExpMod
****************************************************************************//**
*
* Modular exponentiation x = y^e mod p.
*
* \param base
* The pointer to a Cryptolite instance.
*
* \param cfContext
* The pointer to the cy_stc_cryptolite_context_ecdsa_t.
*
* \param p_x
* Pointer to result X .
*
* \param p_y
* Input integer Y.
*
* \param p_e
* Exponent.
*
* \param bitsize
* Bit size of the input Y.
*
* \return status code. See \ref cy_en_cryptolite_status_t.
*******************************************************************************/
cy_en_cryptolite_status_t Cy_Cryptolite_ED25519_ExpMod(CRYPTOLITE_Type *base,
                                    cy_stc_cryptolite_context_ecdsa_t *cfContext,
                                    uint8_t *p_x, uint8_t *p_y, uint8_t *p_e, uint32_t bitsize)
{
    uint32_t clsame;
    uint32_t carry;
    uint32_t i;
    uint32_t loop;
    uint8_t my_p_e[VU_BITS_TO_BYTES(CY_CRYPTOLITE_ECC_ED25519_SIZE)]={0,};
    uint32_t bytesize = VU_BITS_TO_BYTES(bitsize);
    cy_stc_cryptolite_descr_t *vu_struct0 = &cfContext->vu_desptr[0];

    cy_en_cryptolite_status_t tmpResult = CY_CRYPTOLITE_BAD_PARAMS;

    if (p_y == NULL || p_e == NULL || bitsize == 0u)
    {
        return CY_CRYPTOLITE_BAD_PARAMS;
    }

    /* normalize expression */
    //move the content from s_y to s_x
    Cy_Cryptolite_Setnumber((uint8_t *)p_x, (uint8_t *) p_y, bytesize);
    Cy_Cryptolite_Setnumber((uint8_t *)my_p_e, (uint8_t *) p_e, bytesize);

    clsame = Cy_Cryptolite_GetCLSAME(my_p_e, bytesize);

    /* Get rid of leading '0's and '1' */
    Cy_Cryptolite_Vu_lsl (my_p_e, VU_BITS_TO_WORDS(bitsize), p_e, VU_BITS_TO_WORDS(bitsize), clsame+1u);

    /* Binary left-to-right algorithm
    * Perform mul and squaring to implement exponential mod multiplication
    * Scan the bits of the exponent from left to right; perform squaring for each bit,
    * and perform mul when the bit is set. Carry set if current bit is equal to 1
    * (hence perform mul, squaring is always performed)
    */
    if( bitsize >= clsame)
    {
        loop = (uint32_t)(bitsize - clsame);
    }
    else
    {
        return CY_CRYPTOLITE_HW_ERROR;
    }

    for (i = 0; i < (loop); i++)
    {
        /* Carry set if current bit is equal to 1 (hence, perform multiply,
        * squaring is always performed)
        */
        // check is 1 was there in msb
        carry = Cy_Cryptolite_Vu_get_bit(my_p_e, bitsize);
        (void)Cy_Cryptolite_Vu_lsl1_hw (base, vu_struct0, my_p_e, VU_BITS_TO_WORDS(bitsize), my_p_e, VU_BITS_TO_WORDS(bitsize));

        tmpResult = Cy_Cryptolite_ED25519_SquareMod( base, cfContext, p_x, p_x, bitsize);

        if(CY_CRYPTOLITE_SUCCESS != tmpResult)
        {
            return tmpResult;
        }

        // if carry was set then do multiply
        if (carry != 0u)
        {
            (void)Cy_Cryptolite_ED25519_MulMod (base, cfContext, p_x, p_x, p_y, bitsize);
        }
    }

    return tmpResult;
}

#if defined(CY_CRYPTOLITE_CFG_EDDSA_VERIFY_C)
/*******************************************************************************
* Function Name: Cy_Cryptolite_ED25519_PointDecode
****************************************************************************//**
*
* Decode ED25519 encoded public key in to x and y
*
* \param base
* The pointer to a Cryptolite instance.
*
* \param cfContext
* The pointer to the cy_stc_cryptolite_context_ecdsa_t.
*
* \param publicKey
* [in] encoded 32 byte Public key.
*
* \param pubKey_x
* [out] Decoded 32 bytes Public key x in little-endian format.
*
* \param pubKey_y
* [out] Decoded 32 bytes Public key y in little-endian format.
*
* \return status code. See \ref cy_en_cryptolite_status_t.
*
*******************************************************************************/
cy_en_cryptolite_status_t Cy_Cryptolite_ED25519_PointDecode(CRYPTOLITE_Type *base,
    cy_stc_cryptolite_context_ecdsa_t *cfContext,
        const uint8_t *publicKey,
        uint8_t *pubKey_x, uint8_t *pubKey_y)
{
    cy_stc_cryptolite_ec25519_dp_type *edwDp;

    uint8_t x_0;

    uint8_t p_buff[CY_CRYPTOLITE_ECC_ED25519_BYTE_SIZE] = {0,};
    uint8_t *p_a = cfContext->p_r;
    uint8_t *p_d = cfContext->p_s;
    uint8_t *p_uv = cfContext->p_o;
    uint8_t *p_x = p_buff;
    uint8_t *p_y = cfContext->p_u2;
    uint8_t *my_P = cfContext->my_P;
    uint8_t *my_BARRETT_U = cfContext->my_BARRETT_U;
    cy_stc_cryptolite_descr_t *vu_struct0 = &cfContext->vu_desptr[0];
    cy_stc_cryptolite_descr_t *vu_struct1 = &cfContext->vu_desptr[1];

    cy_en_cryptolite_status_t tmpResult = CY_CRYPTOLITE_SUCCESS;
    cy_en_cryptolite_ecc_curve_id_t curveId = CY_CRYPTOLITE_ECC_ECP_ED25519;

    /* (p-5)/8 */
    CY_ALIGN(4) static const uint8_t  ed25519_pb8_exp[CY_CRYPTOLITE_ECC_ED25519_BYTE_SIZE] =
    {
        0xfd, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0f
    };
    /* 2^((p-1)/4) */
    CY_ALIGN(4)static const uint8_t ed25519_sqrt_m1[] =
    {
        0xB0, 0xA0, 0x0E, 0x4A, 0x27, 0x1B, 0xEE, 0xC4, 0x78, 0xE4, 0x2F, 0xAD,
        0x06, 0x18, 0x43, 0x2F, 0xA7, 0xD7, 0xFB, 0x3D, 0x99, 0x00, 0x4D, 0x2B,
        0x0B, 0xDF, 0xC1, 0x4F, 0x80, 0x24, 0x83, 0x2B
    };

    edwDp = Cy_Cryptolite_EC25519_GetCurveParams(curveId);
    if (edwDp != NULL)
    {
        if ((publicKey != NULL) && (pubKey_x != NULL) && (pubKey_y != NULL))
        {
            uint32_t bitsize  = edwDp->size;
            uint32_t bytesize = CY_CRYPTOLITE_BYTE_SIZE_OF_BITS(edwDp->size);

            Cy_Cryptolite_Setnumber((uint8_t *)p_a, (uint8_t *)edwDp->a, bytesize);
            Cy_Cryptolite_Setnumber((uint8_t *)p_d, (uint8_t *)edwDp->d, bytesize);
            // load prime and barrett coefficient
            Cy_Cryptolite_Setnumber(my_P, (uint8_t *) edwDp->prime, bytesize);
            Cy_Cryptolite_Setnumber(my_BARRETT_U, (uint8_t *) edwDp->barrett_p, VU_BITS_TO_BYTES(edwDp->barret_psize));
            cfContext->bitsize = bitsize;

            /* Recover x_0 and generate p_y*/
            Cy_Cryptolite_Vu_memcpy((void*)pubKey_y, (void const *)publicKey, bytesize);

            x_0 = pubKey_y[31] >> (uint8_t)0x07;
            pubKey_y[31] &= (uint8_t)0x7F;

            /* If the resulting y >= grp->P, decoding fails. */
            Cy_Cryptolite_Vu_memcpy((void*)p_y, (void const *)pubKey_y, bytesize);

            if (!Cy_Cryptolite_Vu_test_less_than(base, vu_struct0, p_y, my_P, (uint16_t)bitsize))
            {
                /* p_y is not less than P!!! */
                tmpResult = CY_CRYPTOLITE_BAD_PARAMS;
            }

            /*
            To recover the x-coordinates, the curve equation implies x^2 = (y^2 - 1) / (d y^2 - a) (mod p).
            The denominator is always non-zero mod p. Let u = y^2 - 1 and v = d y^2 - a.
            We compute the square root of (u/v) depending on p (mod 8),for ED25519 its 5. The candidate root is
            x = sqrt(u/v) = u (u v)^((p-5)/8)
            */
           if (CY_CRYPTOLITE_SUCCESS == tmpResult)
           {
                /*y^2*/
                tmpResult = Cy_Cryptolite_ED25519_SquareMod(base, cfContext, p_y, p_y, bitsize);
                if(CY_CRYPTOLITE_SUCCESS != tmpResult)
                {
                    return tmpResult;
                }
                /* dy^2*/
                tmpResult = Cy_Cryptolite_ED25519_MulMod(base, cfContext, p_d, p_d, p_y, bitsize);
                if(CY_CRYPTOLITE_SUCCESS != tmpResult)
                {
                    return tmpResult;
                }
                /* v = (dy^2 - a) */
                Cy_Cryptolite_EC_SubMod (base, cfContext, p_d, p_d, p_a);
                /* u = y^2 - 1 */
                p_x[0] = 1u;

                (void)Cy_Cryptolite_Vu_sub_hw(base, vu_struct0, p_y, VU_BITS_TO_WORDS(bitsize), p_y, VU_BITS_TO_WORDS(bitsize), p_x, VU_BITS_TO_WORDS(bitsize));
                /* compute u*((uv)^((p-5)/8)) mod p */
                Cy_Cryptolite_Setnumber(p_x, (uint8_t *)ed25519_pb8_exp, VU_BITS_TO_BYTES(bitsize));
                tmpResult = Cy_Cryptolite_ED25519_MulMod( base, cfContext, p_a, p_d, p_y, bitsize);
                if(CY_CRYPTOLITE_SUCCESS != tmpResult)
                {
                    return tmpResult;
                }
                tmpResult = Cy_Cryptolite_ED25519_ExpMod( base, cfContext, p_uv, p_a, p_x, bitsize);
                if(CY_CRYPTOLITE_SUCCESS != tmpResult)
                {
                    return tmpResult;
                }

                tmpResult = Cy_Cryptolite_ED25519_MulMod( base, cfContext, p_uv, p_uv, p_y, bitsize);
                if(CY_CRYPTOLITE_SUCCESS != tmpResult)
                {
                    return tmpResult;
                }
                /* If v * x^2 = u (mod p), x is a square root. */
                tmpResult = Cy_Cryptolite_ED25519_SquareMod( base, cfContext, p_x, p_uv, bitsize);
                if(CY_CRYPTOLITE_SUCCESS != tmpResult)
                {
                    return tmpResult;
                }
                tmpResult = Cy_Cryptolite_ED25519_MulMod( base, cfContext, p_x, p_x, p_d, bitsize);
                if(CY_CRYPTOLITE_SUCCESS != tmpResult)
                {
                    return tmpResult;
                }

                if (Cy_Cryptolite_Vu_test_equal(base, vu_struct0, p_x, p_y, (uint16_t)bitsize) != true)
                {
                    /* Otherwise if v x^2 = -u (mod p), x * 2^((p-1)/4) is a square
                    * root. */
                    Cy_Cryptolite_EC_SubMod(base, cfContext, p_x, my_P, p_x);
                    if (Cy_Cryptolite_Vu_test_equal(base, vu_struct1, p_x, p_y, (uint16_t)bitsize) != true)
                    {
                        return CY_CRYPTOLITE_BAD_PARAMS;
                    }
                    /* x *= 2^((p-1)/4) */
                    Cy_Cryptolite_Setnumber(p_y, (uint8_t *)ed25519_sqrt_m1, VU_BITS_TO_BYTES(bitsize));
                    tmpResult = Cy_Cryptolite_ED25519_MulMod( base, cfContext, p_x, p_uv, p_y, bitsize);
                    if(CY_CRYPTOLITE_SUCCESS != tmpResult)
                    {
                        return tmpResult;
                    }
                }
                else
                {
                    p_x = p_uv;
                }

                /* Use the x_0 bit to select the right square root. */
                if (Cy_Cryptolite_Vu_test_zero(base, vu_struct0, p_x, (uint16_t)bitsize) && (x_0 == 1u))
                {
                    return CY_CRYPTOLITE_BAD_PARAMS;
                }
                else
                {
                    if( (p_x[0] & 0x1u) != x_0)
                    {
                        Cy_Cryptolite_EC_SubMod(base, cfContext, p_x, my_P, p_x);
                    }
                }

                Cy_Cryptolite_Setnumber (pubKey_x, p_x, VU_BITS_TO_BYTES(bitsize));
           }

        }
    }
    return (tmpResult);
}

/*******************************************************************************
* Function Name: Cy_Cryptolite_ED25519_Verify
****************************************************************************//**
*
* Verify ED25519 signed message. On successful verification, CY_CRYPTOLITE_SUCCESS is returned and stat is 0xA1A1A1A1.
*
* \param base
* The pointer to a Cryptolite instance.
*
* \param cfContext
* The pointer to the cy_stc_cryptolite_context_ecdsa_t.
*
* \param sig
* The signature to verify, 'R' followed by 'S'.
*
* \param hash
* The hash or message that was signed.
*
* \param hashlen
* The length of the hash or message (octets).
*
* \param stat
* Result of signature verification, 0xA1A1A1A1==valid, 0x00BADBAD==invalid.
*
* \param key
* The corresponding uncompressed public key to use (little-endian). See \ref cy_stc_cryptolite_ecc_key.
*
* \param sigType
* signature Type. CY_CRYPTOLITE_EDDSA_PURE,CY_CRYPTOLITE_EDDSA_CTX or CY_CRYPTOLITE_EDDSA_PREHASH
*
* \param sigctx
* signature context. can be NULL if EDDSA_PURE is used or if no context is provided.
*
* \param sigctx_len
* The length of the signature context
*
* \return status code. See \ref cy_en_cryptolite_status_t.
*
* \funcusage
* \snippet cryptolite/snippet/main.c snippet_Cy_Cryptolite_Ed25519_sign_verify
*
*******************************************************************************/
cy_en_cryptolite_status_t Cy_Cryptolite_ED25519_Verify(CRYPTOLITE_Type *base,
                                                        cy_stc_cryptolite_context_ecdsa_t *cfContext,
                                                        uint8_t *sig,
                                                        const uint8_t *hash, uint32_t hashlen,
                                                        const cy_stc_cryptolite_ecc_key *key,
                                                        uint32_t *stat,
                                                        cy_en_cryptolite_eddsa_sig_type_t sigType,
                                                        const uint8_t *sigctx, uint32_t sigctx_len)
{
    cy_en_cryptolite_status_t tmpResult = CY_CRYPTOLITE_BAD_PARAMS;
    cy_stc_cryptolite_ec25519_dp_type *eccDp;
    cy_stc_cryptolite_ed25519_sha512_t *ed25519_sha;

    /* input parameters validation */
    if ((hash == NULL) && (0u != hashlen))
    {
        return CY_CRYPTOLITE_BAD_PARAMS;
    }

    if ((sig != NULL) && (stat != NULL) && (key != NULL) && (cfContext != NULL) && (sigType < CY_CRYPTOLITE_EDDSA_NONE))
    {
        /*
        Value of context is set by the signer and verifier (maximum of 255
        octets; the default is empty string, except for Ed25519, which can't
        have context) and has to match octet by octet for verification to be
        successful.
        */
        if(sigType == CY_CRYPTOLITE_EDDSA_CTX)
        {
            if( sigctx == NULL  || sigctx_len == 0u || sigctx_len > 255u)
            {
                return CY_CRYPTOLITE_BAD_PARAMS;
            }
        }

        if (cfContext->ed25519_sha == NULL)
        {
            return CY_CRYPTOLITE_BAD_PARAMS;
        }

        tmpResult = CY_CRYPTOLITE_NOT_SUPPORTED;
        *stat = CY_ED25519SIG_VERIFY_FAIL;
        ed25519_sha = cfContext->ed25519_sha;

        eccDp = Cy_Cryptolite_EC25519_GetCurveParams(key->curveID);
        if (eccDp != NULL)
        {
            //sha init
            tmpResult = ed25519_sha->sha_init(ed25519_sha->shactx);
            if (tmpResult != CY_CRYPTOLITE_SUCCESS)
            {
                return tmpResult;
            }

            tmpResult = ed25519_sha->sha_start(ed25519_sha->shactx);

            if (CY_CRYPTOLITE_SUCCESS == tmpResult)
            {
                CY_ALIGN(4) uint8_t p_temp[VU_BITS_TO_BYTES(CY_CRYPTOLITE_ECC_ED25519_SIZE)]={0,};
                CY_ALIGN(4) uint8_t p_sha[CY_CRYPTOLITE_SHA512_HASH_SIZE]={0,};
                cy_stc_cryptolite_descr_t *vu_struct0 = &cfContext->vu_desptr[0];
                uint8_t *p_r = cfContext->p_r;
                uint8_t *p_s = cfContext->p_s;



                uint8_t *S_X = cfContext->p_gx;
                uint8_t *S_Y = cfContext->p_gy;
                uint8_t *pubkey_x = cfContext->p_qx;
                uint8_t *pubkey_y = cfContext->p_qy;
                uint8_t *my_P = cfContext->my_P;
                uint8_t *my_BARRETT_U = cfContext->my_BARRETT_U;

                uint32_t bitsize  = eccDp->size;
                uint32_t bytesize = VU_BITS_TO_BYTES(eccDp->size);

                cfContext->bitsize = bitsize;
                /* load values needed for reduction modulo order of the base point */
                Cy_Cryptolite_Setnumber (my_P, (uint8_t *)eccDp->order, VU_BITS_TO_BYTES(bitsize));
                Cy_Cryptolite_Setnumber (my_BARRETT_U, (uint8_t *)eccDp->barrett_o, VU_BITS_TO_BYTES(eccDp->barret_osize));

                /* check that R and S are within the valid range, i.e. 0 < R < n and 0 < S < n */
                Cy_Cryptolite_Setnumber(p_r, (uint8_t *)sig, bytesize);
                Cy_Cryptolite_Setnumber(p_s, (uint8_t *)&sig[VU_BITS_TO_BYTES(bitsize)], bytesize);

                if (Cy_Cryptolite_Vu_test_zero(base, vu_struct0, p_r, (uint16_t)bitsize) == true) {
                    return CY_CRYPTOLITE_BAD_PARAMS;
                }

                if (Cy_Cryptolite_Vu_test_zero(base, vu_struct0, p_s, (uint16_t)bitsize) == true) {
                    return CY_CRYPTOLITE_BAD_PARAMS;
                }

                // load base Point G
                Cy_Cryptolite_Setnumber(S_X, (uint8_t *) eccDp->Gx, bytesize);
                Cy_Cryptolite_Setnumber(S_Y, (uint8_t *) eccDp->Gy, bytesize);

                // load public key Qa
                Cy_Cryptolite_Setnumber(pubkey_x, (uint8_t *)key->pubkey.x, bytesize);
                Cy_Cryptolite_Setnumber(pubkey_y, (uint8_t *)key->pubkey.y, bytesize);

                /* step1 */
                /*SHA expects big-endian*/
                if(sigType != CY_CRYPTOLITE_EDDSA_PURE)
                {
                    Cy_Cryptolite_ED25519_dom2_ctx( base, cfContext, sigType, sigctx, sigctx_len);
                }

                /* step2: h = sha512(Rs + public + msg) mod N */
                tmpResult = ed25519_sha->sha_update(ed25519_sha->shactx, (uint8_t const*)p_r, bytesize);
                if (tmpResult != CY_CRYPTOLITE_SUCCESS)
                {
                    return tmpResult;
                }
                /* compress public key */
                if((bool)(((uint8_t*)pubkey_x)[0] & (uint8_t)0x01))
                {
                    ((uint8_t*)pubkey_y)[31] |= (uint8_t)0x80;
                }
                tmpResult = ed25519_sha->sha_update(ed25519_sha->shactx, (uint8_t const*)pubkey_y, bytesize);
                if (tmpResult != CY_CRYPTOLITE_SUCCESS)
                {
                    return tmpResult;
                }
                /* For EDDSA_PREHASH, buf should contain the SHA512 hash. It contains the whole message otherwise */
                tmpResult = ed25519_sha->sha_update(ed25519_sha->shactx, (uint8_t const*)hash, hashlen);
                if (tmpResult != CY_CRYPTOLITE_SUCCESS)
                {
                    return tmpResult;
                }
                tmpResult = ed25519_sha->sha_finish(ed25519_sha->shactx, p_sha);
                if(CY_CRYPTOLITE_SUCCESS != tmpResult)
                {
                    return tmpResult;
                }

                /* Mod reduction modulo n (order of the base point in VR_P and barret_o in VR_BARRET) */
                if ( CY_CRYPTOLITE_SUCCESS != Cy_Cryptolite_EDDSA_Bar_MulRed(base, cfContext, p_temp, bitsize, p_sha, (CY_CRYPTOLITE_SHA512_HASH_SIZE*8u)) )
                {
                    return CY_CRYPTOLITE_BAD_PARAMS;
                }

                /* Step 3 */
                /* We perform fast single-signature verification by compressing sB-hA and comparing with r without decompressing it */
                ((uint8_t*)pubkey_y)[31] &= (uint8_t)0x7F;

                (void)Cy_Cryptolite_Vu_sub_hw (base, vu_struct0,
                                            p_temp, VU_BITS_TO_WORDS(bitsize+1u),
                                            my_P, VU_BITS_TO_WORDS(bitsize),
                                            p_temp, VU_BITS_TO_WORDS(bitsize+1u));

                /* R = sG + hA */
                tmpResult =  Cy_Cryptolite_ED25519_PointMulAdd(base, cfContext, eccDp, S_X, S_Y, p_s, pubkey_x, pubkey_y, p_temp, bitsize);
                if(CY_CRYPTOLITE_SUCCESS != tmpResult)
                {
                    return tmpResult;
                }

                /* Compress R (we re-use pubkey_x & y)*/
                if((bool)(((uint8_t*)S_X)[0] & (uint8_t)0x01))
                {
                    ((uint8_t*)S_Y)[31] |= (uint8_t)0x80;
                }

                /* since its compressed we are free to compare with r without decompressing it */
                if (Cy_Cryptolite_Vu_test_equal(base, vu_struct0, S_Y, p_r, (uint16_t)bitsize))
                {
                    *stat = CY_ED25519SIG_VERIFY_PASS;
                }
                else
                {
                    *stat = CY_ED25519SIG_VERIFY_FAIL;
                }
            }
        }
    }

    return (tmpResult);
}

#endif /* defined(CY_CRYPTOLITE_CFG_EDDSA_VERIFY_C) */
#endif /* defined(CY_CRYPTOLITE_CFG_EDDSA_C) || defined(CY_CRYPTOLITE_CFG_EC25519_C) */

#if defined(__cplusplus)
}
#endif

#endif /* CY_IP_MXCRYPTOLITE */
