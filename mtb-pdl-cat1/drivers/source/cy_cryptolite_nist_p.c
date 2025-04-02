/*******************************************************************************
* \file cy_cryptolite_nist_p.c
* \version 2.80
*
* \brief
*  This file provides Elliptic Curve (EC) Scalar Multiplication using (X,Y)-only,
*  Co-Z arithmetic in the Crypto driver.
*
********************************************************************************
* Copyright 2022 Cypress Semiconductor Corporation
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

#include "cy_cryptolite_vu.h"
#include "cy_cryptolite_nist_p.h"

#if (CRYPTOLITE_VU_PRESENT == 1)
#if defined(CY_CRYPTOLITE_CFG_ECP_C)

/*******************************************************************************
* Elliptic Curve (EC) Scalar Multiplication using (X,Y)-only, Co-Z arithmetic
*
* Theoretic and algorithmic references:
* Algorithms and Co-Z arithmetic theory: 'Fast and Regular Algorithms for Scalar
* Multiplication over Elliptic Curves', Matthieu Rivain NIST P-curves
* (parameters and curve-specific modular reduction):
* 'RECOMMENDED ELLIPTIC CURVES FOR FEDERAL GOVERNMENT USE', NIST, 1999
*
* Useful resources:
* Large number calculator and converter:
* - http://www.mobilefish.com/services/big_number/big_number.php
* - https://www.mobilefish.com/services/big_number_equation/big_number_equation.php
*
* - ECC curves and test vectors: http://point-at-infinity.org/ecc/nisttv
*
* Valid values for scalar multiplier, 2 < d < (order-1)
*
*******************************************************************************/
#include "cy_cryptolite_vu.h"

/***************************************************************
*                   Global Variables
***************************************************************/
// static cy_en_cryptolite_ecc_curve_id_t cryptolite_eccMode;
//static cy_en_cryptolite_ecc_red_mul_algs_t cryptolite_mul_red_alg_select = CY_CRYPTOLITE_NIST_P_BARRETT_RED_ALG;

/* Barrett reduction z = x % mod */
void Cy_Cryptolite_EC_Bar_MulRed ( CRYPTOLITE_Type *base,
                                cy_stc_cryptolite_context_ecdsa_t *cfContext,
                                uint8_t* p_z,         //   bit_size
                                uint8_t* p_x,         //   bit_size
                                uint32_t bit_size )
{
    uint32_t sign;
    CY_ALIGN(4) uint8_t p_t_double[VU_BITS_TO_BYTES(2U*BIT_SIZE)];       // 2*bit_size
    CY_ALIGN(4) uint8_t t2_plus2[VU_BITS_TO_BYTES(BIT_SIZE+2U+1U)];       //   bit_size + 3

    uint8_t *p_temp_plus2;//temp_plus2;
    uint8_t *p_t1_plus2 = p_t_double;//t1_plus2;
    uint8_t *p_t2_plus2 = t2_plus2;
    uint8_t *my_P = cfContext->my_P;
    uint8_t *my_BARRETT_U = cfContext->my_BARRETT_U;
    uint8_t *p_t1 = p_t2_plus2;

    cy_stc_cryptolite_descr_t *vu_struct0 = &cfContext->vu_desptr[0];
    cy_stc_cryptolite_descr_t *vu_struct1 = &cfContext->vu_desptr[1];

    (void)Cy_Cryptolite_Vu_lsr_hw (base, vu_struct0, p_z, VU_BITS_TO_WORDS(bit_size), p_x, VU_BITS_TO_WORDS(2U*bit_size), bit_size);

    (void)Cy_Cryptolite_Vu_mul_hw (base, vu_struct1, p_t_double, VU_BITS_TO_WORDS(2U*bit_size), p_z, VU_BITS_TO_WORDS(bit_size), my_BARRETT_U, VU_BITS_TO_WORDS(bit_size+1U));
    (void)Cy_Cryptolite_Vu_lsr_hw (base, vu_struct0, p_t1, VU_BITS_TO_WORDS(bit_size), p_t_double, VU_BITS_TO_WORDS(2U*bit_size), bit_size);
    (void)Cy_Cryptolite_Vu_mul_hw (base, vu_struct1, p_t_double, VU_BITS_TO_WORDS(2U*bit_size), p_t1, VU_BITS_TO_WORDS(bit_size), my_P, VU_BITS_TO_WORDS(bit_size));

    (void)Cy_Cryptolite_Vu_sub_hw (base, vu_struct0, p_t2_plus2, VU_BITS_TO_WORDS(bit_size+2U+1U), p_x, VU_BITS_TO_WORDS(bit_size+2U+1U), p_t_double, VU_BITS_TO_WORDS(bit_size+2U+1U));
    (void)Cy_Cryptolite_Vu_sub_hw (base, vu_struct1, p_t1_plus2, VU_BITS_TO_WORDS(bit_size+2U+1U), p_t2_plus2, VU_BITS_TO_WORDS(bit_size+2U), my_P, VU_BITS_TO_WORDS(bit_size));
    Cy_Cryptolite_Vu_wait_hw(base);
    sign =  Cy_Cryptolite_Vu_get_bit(p_t1_plus2, bit_size+2U);

    if ((bool)sign)
    {
        p_temp_plus2 = p_t2_plus2;
        p_t2_plus2 = p_t1_plus2;
        p_t1_plus2 = p_temp_plus2;
    }
    (void)Cy_Cryptolite_Vu_cond_sub_hw (base, vu_struct1, p_z, VU_BITS_TO_WORDS(bit_size), p_t1_plus2, VU_BITS_TO_WORDS(bit_size+3U), my_P, VU_BITS_TO_WORDS(bit_size));
}

/*------------------------------------------------------
// Multiplication reduction algorithm select
//------------------------------------------------------
*/
void Cryptolite_EC_MulRed( CRYPTOLITE_Type *base,
                            cy_stc_cryptolite_context_ecdsa_t *cfContext,
                            uint8_t *z,
                            uint8_t *x,
                            int size);
void Cryptolite_EC_MulRed( CRYPTOLITE_Type *base,
                            cy_stc_cryptolite_context_ecdsa_t *cfContext,
                            uint8_t *z,
                            uint8_t *x,
                            int size)
{

    Cy_Cryptolite_EC_Bar_MulRed(base, cfContext, z, x, (uint32_t)size);
}

/*
 @brief Modular multiplication in GF(p).
 z = a * b % mod

 Leaf function.

 @param[in] z Register index for product value.
 @param[in] a Register index for multiplicand value.
 @param[in] b Register index for multiplier value.
 @param[in] barrett_u Register index for Barrett reduction value.
 @param[in] mod Register index for modulo value.
 @param[in] size Bit size.
*/
void Cy_Cryptolite_EC_MulMod ( CRYPTOLITE_Type *base,
                            cy_stc_cryptolite_context_ecdsa_t *cfContext,
                            uint8_t * z,
                            uint8_t * a,
                            uint8_t * b,
                            int size )
{

    CY_ALIGN(4) uint8_t ab_double[VU_BITS_TO_BYTES(2U * BIT_SIZE)]; // the variable size is ignored
    cy_stc_cryptolite_descr_t *vu_struct0 = &cfContext->vu_desptr[0];

    (void)Cy_Cryptolite_Vu_mul_hw (base, vu_struct0, ab_double, VU_BITS_TO_WORDS(2U*(uint32_t)size), a, VU_BITS_TO_WORDS((uint32_t)size), b, VU_BITS_TO_WORDS((uint32_t)size));
    /* Modular Reduction: Barrett reduction or curve-specific or shift-multiply */
    Cryptolite_EC_MulRed (base, cfContext, z, ab_double, (int)size);
}

/*
 @brief Modular squaring in GF(p).
 z = a * a % mod

 @param[in] z Register index for product value.
 @param[in] a Register index for multiplicand and multiplier value.
 @param[in] barrett_u Register index for Barrett reduction value.
 @param[in] mod Register index for modulo value.
 @param[in] size Bit size.
*/
void Cy_Cryptolite_EC_SquareMod( CRYPTOLITE_Type *base,
                            cy_stc_cryptolite_context_ecdsa_t *cfContext,
                            uint8_t * z,
                            uint8_t * a,
                            int size )
{
    Cy_Cryptolite_EC_MulMod (base, cfContext, z, a, a, size);
}

/*
 @brief Modular division in GF(p).
 z = a / b % mod

 This algorithm works when "dividend" and "divisor" are relatively prime,
 Reference: "From Euclid's GCD to Montgomery Multiplication to the Great Divide", S.C. Schantz
 @param[in] z Register index for quotient value.
 @param[in] a Register index for dividend value.
 @param[in] b Register index for divisor value.
 @param[in] mod Register index for modulo value.
 @param[in] size Bit size.
*/
void Cy_Cryptolite_EC_DivMod( CRYPTOLITE_Type *base,
                            cy_stc_cryptolite_context_ecdsa_t *cfContext,
                            uint8_t * z,
                            uint8_t * a,
                            uint8_t * b,
                            int size )
{
    //uint16_t status;
    bool zero;
    bool sign;
    bool a_even;
    bool b_even;
    uint16_t wordsize = VU_BITS_TO_WORDS((uint16_t)size);
    uint16_t wordsize1 = VU_BITS_TO_WORDS((uint16_t)size+1U);

    CY_ALIGN(4) uint8_t my_a[VU_BITS_TO_BYTES(BIT_SIZE)];
    CY_ALIGN(4) uint8_t my_b[VU_BITS_TO_BYTES(BIT_SIZE)];
    CY_ALIGN(4) uint8_t my_v[VU_BITS_TO_BYTES(BIT_SIZE)];
    CY_ALIGN(4) uint8_t temp[VU_BITS_TO_BYTES(BIT_SIZE+1U)];

    cy_stc_cryptolite_descr_t *vu_struct0 = &cfContext->vu_desptr[0];
    cy_stc_cryptolite_descr_t *vu_struct1 = &cfContext->vu_desptr[1];
    uint8_t *my_P = cfContext->my_P;

    (void)Cy_Cryptolite_Vu_mov_hw (base,vu_struct0, my_a, wordsize, b, wordsize);
    (void)Cy_Cryptolite_Vu_mov_hw (base,vu_struct1, my_b, wordsize, my_P, wordsize);
    (void)Cy_Cryptolite_Vu_mov_hw (base,vu_struct0, z, wordsize, a, wordsize);

    Cy_Cryptolite_Vu_wait_hw(base);
    Cy_Cryptolite_Vu_clr(my_v, wordsize);

    while ((bool)1)
    {
        (void)Cy_Cryptolite_Vu_sub_hw (base, vu_struct0, temp, wordsize1, my_a, wordsize, my_b, wordsize);
        Cy_Cryptolite_Vu_wait_hw(base);

        sign = (bool)Cy_Cryptolite_Vu_get_bit(temp, (uint32_t)size);
        zero = Cy_Cryptolite_Vu_test_zero (base, vu_struct1, temp, (uint16_t)size);

        a_even = Cy_Cryptolite_Vu_test_even (my_a);
        b_even = Cy_Cryptolite_Vu_test_even (my_b);



        if (zero)
        {
            break;
        }

        if (a_even)
        {
            (void)Cy_Cryptolite_Vu_lsr1_hw (base, vu_struct1, my_a, wordsize, my_a, wordsize);
            Cy_Cryptolite_EC_HalfMod (base, cfContext, z, z);

        }
        else if (b_even)
        {
            (void)Cy_Cryptolite_Vu_lsr1_hw (base, vu_struct0, my_b, wordsize, my_b, wordsize);
            Cy_Cryptolite_EC_HalfMod (base, cfContext, my_v, my_v);

        }
        else if (!sign)
        { // (a >= b)
            (void)Cy_Cryptolite_Vu_sub_hw (base, vu_struct1, my_a, wordsize, my_a, wordsize, my_b, wordsize);
            (void)Cy_Cryptolite_Vu_lsr1_hw (base, vu_struct0, my_a, wordsize, my_a, wordsize);
            Cy_Cryptolite_EC_SubMod(base, cfContext, z, z, my_v);
            Cy_Cryptolite_EC_HalfMod (base, cfContext, z, z);

        }
        else
        {
            (void)Cy_Cryptolite_Vu_sub_hw (base, vu_struct1, my_b, wordsize, my_b, wordsize, my_a, wordsize);
            (void)Cy_Cryptolite_Vu_lsr1_hw (base, vu_struct0, my_b, wordsize, my_b, wordsize);
            Cy_Cryptolite_EC_SubMod (base, cfContext, my_v, my_v, z);
            Cy_Cryptolite_EC_HalfMod (base, cfContext, my_v, my_v);

        }

    }
}

/*
 @brief (X,Y)-only co-Z addition with update: Calculate P+Q and P' (co-Z with P+Q)
 Algorithm 5, "Fast and regular algorithms for scalar multiplication over elliptic curves"

 @param[in, out] x1/x3  : input X-coordinate of P (Jacobian, projective coordinate) and output X-coordinate of P+Q
 @param[in, out] y1/y3  : input Y-coordinate of P (Jacobian, projective coordinate) and output Y-coordinate of P+Q
 @param[in, out] x2/x1' : input X-coordinate of Q (Jacobian, projective coordinate) and output X-coordinate of P'
 @param[in, out] y2/y1' : input Y-coordinate of Q (Jacobian, projective coordinate) and output Y-coordinate of P'
 where P = (x1, y1, z), Q = (x2, y2, z), P+Q = (x3,y3,z3) and P' = (x1',y1',z3), for some z3 on the elliptic curve

 @param[in] barrett_u :  Register index for Barrett reduction value.
 @param[in] mod :        Register index for modulo value.
 @param[in] size :       Bit size.
*/
void Cy_Cryptolite_EC_XYCZ_ADD( CRYPTOLITE_Type *base,
                            cy_stc_cryptolite_context_ecdsa_t *cfContext,
                            int carry,
                            uint8_t * x1,
                            uint8_t * y1,
                            uint8_t * x2,
                            uint8_t * y2,
                            int size );
void Cy_Cryptolite_EC_XYCZ_ADD( CRYPTOLITE_Type *base,
                            cy_stc_cryptolite_context_ecdsa_t *cfContext,
                            int carry,
                            uint8_t * x1,
                            uint8_t * y1,
                            uint8_t * x2,
                            uint8_t * y2,
                            int size )
{
    CY_ALIGN(4) uint8_t t1[VU_BITS_TO_BYTES(BIT_SIZE)];
    CY_ALIGN(4) uint8_t t2[VU_BITS_TO_BYTES(BIT_SIZE)];
    uint8_t *temp;

    Cy_Cryptolite_Vu_wait_hw(base);
    // Swap if carry set, b = 1 : (R0, R1) <- ADDC(R1, R0)
    if ((bool)carry)
    {
        temp = x1;
        x1 = x2;
        x2 = temp;

        temp = y1;
        y1 = y2;
        y2 = temp;
    }

    Cy_Cryptolite_EC_SubMod( base, cfContext, t1, x1, x2);
    Cy_Cryptolite_EC_SquareMod(base, cfContext, t1, t1, size);
    Cy_Cryptolite_EC_MulMod(base, cfContext, t2, x1, t1, size);
    Cy_Cryptolite_EC_MulMod(base, cfContext, x2, x2, t1, size);
    Cy_Cryptolite_EC_SubMod(base, cfContext, t1, y1, y2);
    Cy_Cryptolite_EC_SubMod(base, cfContext, x1, t2, x2);
    Cy_Cryptolite_EC_MulMod(base, cfContext, y2, y2, x1, size);
    Cy_Cryptolite_EC_AddMod(base, cfContext, x1, x2, t2);
    Cy_Cryptolite_EC_SquareMod(base, cfContext, t2, t1, size);
    Cy_Cryptolite_EC_SubMod(base, cfContext, x1, t2, x1);
    Cy_Cryptolite_EC_SubMod(base, cfContext, t2, x2, x1);
    Cy_Cryptolite_EC_MulMod(base, cfContext, t1, t1, t2, size);
    Cy_Cryptolite_EC_SubMod(base, cfContext, y1, t1, y2);
}

/*
 @brief (X,Y)-only co-Z conjugate addition with update: Calculate P+Q and P-Q, which are co-Z
 Algorithm 6, "Fast and regular algorithms for scalar multiplication over elliptic curves"

 @param[in]      carry  : input carry flag, value = element of {0,1}
 @param[in, out] x1,x3  : input X-coordinate of R0, my_r0_x (Jacobian, projective coordinate) and output X-coordinate of P+Q
 @param[in, out] y1,y3  : input Y-coordinate of R0, my_r0_y (Jacobian, projective coordinate) and output Y-coordinate of P+Q
 @param[in, out] x2,x3' : input X-coordinate of R1, my_r1_x (Jacobian, projective coordinate) and output X-coordinate of P-Q
 @param[in, out] y2,y3' : input Y-coordinate of R1, my_r1_y (Jacobian, projective coordinate) and output Y-coordinate of P-Q
 where P = (x1, y1, z), Q = (x2, y2, z), P+Q = (x3,y3,z3) and P-Q = (x3',y3',z3), for some z3 on the elliptic curve

 @param[in] barrett_u :  Register index for Barrett reduction value.
 @param[in] mod :        Register index for modulo value.
 @param[in] size :       Bit size.
*/
void Cy_Cryptolite_EC_XYCZ_ADDC( CRYPTOLITE_Type *base,
                            cy_stc_cryptolite_context_ecdsa_t *cfContext,
                            int carry,
                            uint8_t *x1,
                            uint8_t *y1,
                            uint8_t *x2,
                            uint8_t *y2,
                            int size );
void Cy_Cryptolite_EC_XYCZ_ADDC( CRYPTOLITE_Type *base,
                            cy_stc_cryptolite_context_ecdsa_t *cfContext,
                            int carry,
                            uint8_t *x1,
                            uint8_t *y1,
                            uint8_t *x2,
                            uint8_t *y2,
                            int size )
{
    CY_ALIGN(4) uint8_t t1[VU_BITS_TO_BYTES(BIT_SIZE)];
    CY_ALIGN(4) uint8_t t2[VU_BITS_TO_BYTES(BIT_SIZE)];
    CY_ALIGN(4) uint8_t t3[VU_BITS_TO_BYTES(BIT_SIZE)];
    CY_ALIGN(4) uint8_t t4[VU_BITS_TO_BYTES(BIT_SIZE)];
    CY_ALIGN(4) uint8_t t5[VU_BITS_TO_BYTES(BIT_SIZE)];
    uint8_t *temp;

    Cy_Cryptolite_Vu_wait_hw(base);
    // Swap if carry set, b = 1 : (R0, R1) <- ADDC(R1, R0)
    if ((bool)carry)
    {
        temp = x1;
        x1 = x2;
        x2 = temp;

        temp = y1;
        y1 = y2;
        y2 = temp;
    }

    Cy_Cryptolite_EC_SubMod( base, cfContext, t1, x2, x1);
    Cy_Cryptolite_EC_SquareMod( base, cfContext, t1, t1, size);
    Cy_Cryptolite_EC_MulMod( base, cfContext, t2, x2, t1, size);
    Cy_Cryptolite_EC_MulMod( base, cfContext, t3, x1, t1, size);
    Cy_Cryptolite_EC_SubMod( base, cfContext, t1, y2, y1);
    Cy_Cryptolite_EC_AddMod( base, cfContext, t5, y1, y2);
    Cy_Cryptolite_EC_SubMod( base, cfContext, x2, t2, t3);
    Cy_Cryptolite_EC_MulMod( base, cfContext, y1, y1, x2, size);
    Cy_Cryptolite_EC_AddMod( base, cfContext, t2, t3, t2);
    Cy_Cryptolite_EC_SquareMod( base, cfContext, x2, t1, size);

    

    Cy_Cryptolite_EC_SubMod( base, cfContext, x2, x2, t2);
    Cy_Cryptolite_EC_SquareMod( base, cfContext, t4, t5, size);
    Cy_Cryptolite_EC_SubMod( base, cfContext, x1, t3, x2);
    Cy_Cryptolite_EC_MulMod( base, cfContext, x1, t1, x1, size);
    Cy_Cryptolite_EC_SubMod( base, cfContext, y2, x1, y1);
    Cy_Cryptolite_EC_SubMod( base, cfContext, x1, t4, t2);
    Cy_Cryptolite_EC_SubMod( base, cfContext, t1, x1, t3);
    Cy_Cryptolite_EC_MulMod( base, cfContext, t3, t5, t1, size);
    Cy_Cryptolite_EC_SubMod( base, cfContext, y1, t3, y1);

    Cy_Cryptolite_Vu_wait_hw(base);
    temp = y1;
    y1 = y2;
    y2 = temp;
}

/* @brief Elliptic curve point multiplication, in GF(p), using (X,Y)-only, co-Z arithmetic.
 @param[in] s_x          Register index for affine X coordinate of base point.
 @param[in] s_y          Register index for affine Y coordinate of base point.
 @param[in] d            Register index for multiplication/exponentiation value.
 @param[in] barrett_u        Register index for Barrett reduction value.
 @param[in] mod          Register index for modulo value.
 @param[in] size             Bit size.
*/
void Cy_Cryptolite_EC_JacobianEcScalarMul_coZ( CRYPTOLITE_Type *base,
                            cy_stc_cryptolite_context_ecdsa_t *cfContext,
                            uint8_t * px,
                            uint8_t * py,
                            uint8_t * pd,
                            int size,  // bit size
                            uint8_t * porder);
void Cy_Cryptolite_EC_JacobianEcScalarMul_coZ( CRYPTOLITE_Type *base,
                            cy_stc_cryptolite_context_ecdsa_t *cfContext,
                            uint8_t * px,
                            uint8_t * py,
                            uint8_t * pd,
                            int size,  // bit size
                            uint8_t * porder)
{
    int i;
    uint8_t carry;
    uint8_t carry_sizeplus1;
    uint8_t carry_size;
    uint8_t carry_sizeminus1;
    bool carry_combination;
    CY_ALIGN(4) uint8_t dc[VU_BITS_TO_BYTES(BIT_SIZE+2)];
    CY_ALIGN(4) uint8_t lambda[VU_BITS_TO_BYTES(BIT_SIZE)];
    CY_ALIGN(4) uint8_t my_r1_x[VU_BITS_TO_BYTES(BIT_SIZE)];
    CY_ALIGN(4) uint8_t my_r1_y[VU_BITS_TO_BYTES(BIT_SIZE)];
    CY_ALIGN(4) uint8_t my_p_x[VU_BITS_TO_BYTES(BIT_SIZE)];
    CY_ALIGN(4) uint8_t my_p_y[VU_BITS_TO_BYTES(BIT_SIZE)];
    CY_ALIGN(4) uint8_t t1[VU_BITS_TO_BYTES(BIT_SIZE)];
    CY_ALIGN(4) uint8_t t2[VU_BITS_TO_BYTES(BIT_SIZE)];
    CY_ALIGN(4) uint8_t t3[VU_BITS_TO_BYTES(BIT_SIZE)];

    uint8_t *p_my_r1_x = my_r1_x;
    uint8_t *p_my_r1_y = my_r1_y;
    uint8_t *p_t1 = t1;
    uint8_t *p_t2 = t2;

    uint8_t *p_t3 = t3;
    uint8_t *t4 = porder;
    uint8_t *p_t4 = t4;

    uint8_t *temp;
    int even_size;
    uint32_t bitsize = cfContext->bitsize;
    cy_stc_cryptolite_descr_t *vu_struct0 = &cfContext->vu_desptr[0];
    cy_stc_cryptolite_descr_t *vu_struct1 = &cfContext->vu_desptr[1];


    (void)Cy_Cryptolite_Vu_mov_hw (base, vu_struct0, my_p_x, VU_BITS_TO_WORDS(bitsize), px, VU_BITS_TO_WORDS(bitsize));
    (void)Cy_Cryptolite_Vu_mov_hw (base, vu_struct1, my_p_y, VU_BITS_TO_WORDS(bitsize), py, VU_BITS_TO_WORDS(bitsize));
    (void)Cy_Cryptolite_Vu_mov_hw (base, vu_struct0, dc, VU_BITS_TO_WORDS(bitsize+2U), pd, VU_BITS_TO_WORDS(bitsize));

    Cy_Cryptolite_Vu_wait_hw(base);

    if (Cy_Cryptolite_Vu_test_even(dc) == false)
    {
        (void)Cy_Cryptolite_Vu_add_hw (base, vu_struct0, dc, VU_BITS_TO_WORDS(bitsize+2U), dc, VU_BITS_TO_WORDS(bitsize + 2U), porder, VU_BITS_TO_WORDS(bitsize));
    }

    (void)Cy_Cryptolite_Vu_add_hw (base, vu_struct1, dc, VU_BITS_TO_WORDS(bitsize+2U), dc, VU_BITS_TO_WORDS(bitsize + 2U), porder, VU_BITS_TO_WORDS(bitsize));




    /*------------------------------------------------
    * Montgomery ladder with (X,Y)-only co-Z addition
    *------------------------------------------------
    * Initialization function
    * Calculate 2P, corresponding to leading 1 in dc
    * Ensures constant timing looping over all bits in dc, which can vary in the number of bits over the range [size, size_2]
    *Crypto_EC_CoZ_Init    (dc, my_p_x, my_p_y, px, py, p_my_r1_x, my_r1_y, size);
    */

    /*--------------------------------
    * IDBL: 2P and P*
    *---------------------------------
    */


    Cy_Cryptolite_EC_SquareMod (base, cfContext, p_my_r1_y, my_p_y, size);
    Cy_Cryptolite_EC_AddMod (base, cfContext, p_my_r1_y, p_my_r1_y,    p_my_r1_y);
    Cy_Cryptolite_EC_SquareMod (base, cfContext, py, p_my_r1_y, size);
    Cy_Cryptolite_EC_AddMod (base, cfContext, py, py, py);
    Cy_Cryptolite_EC_AddMod (base, cfContext, px, p_my_r1_y, p_my_r1_y);
    Cy_Cryptolite_EC_MulMod (base, cfContext, px, px, my_p_x, size);
    Cy_Cryptolite_EC_SquareMod (base, cfContext, p_my_r1_x, my_p_x, size);
    Cy_Cryptolite_EC_AddMod (base, cfContext, p_my_r1_y, p_my_r1_x, p_my_r1_x);
    Cy_Cryptolite_EC_AddMod (base, cfContext, p_my_r1_x, p_my_r1_y, p_my_r1_x);
    Cy_Cryptolite_Vu_wait_hw(base);
    Cy_Cryptolite_Vu_clr (p_t1, VU_BITS_TO_WORDS(bitsize));
    Cy_Cryptolite_Vu_set_bit (p_t1, 0);
    Cy_Cryptolite_Vu_set_bit (p_t1, 1);



    Cy_Cryptolite_EC_SubMod (base, cfContext, p_my_r1_y, p_my_r1_x, p_t1);
    Cy_Cryptolite_EC_SquareMod (base, cfContext, p_my_r1_x, p_my_r1_y, size);
    Cy_Cryptolite_EC_SubMod (base, cfContext, p_my_r1_x, p_my_r1_x, px);
    Cy_Cryptolite_EC_SubMod (base, cfContext, p_my_r1_x, p_my_r1_x, px);
    Cy_Cryptolite_EC_SubMod (base, cfContext, p_t1, px, p_my_r1_x);
    Cy_Cryptolite_EC_MulMod (base, cfContext, p_my_r1_y, p_my_r1_y, p_t1, size);
    Cy_Cryptolite_EC_SubMod (base, cfContext, p_my_r1_y, p_my_r1_y, py);
    (void)Cy_Cryptolite_Vu_mov_hw (base, vu_struct0, p_t1, VU_BITS_TO_WORDS(bitsize), p_my_r1_x, VU_BITS_TO_WORDS(bitsize));
    (void)Cy_Cryptolite_Vu_mov_hw (base, vu_struct1, p_t2, VU_BITS_TO_WORDS(bitsize), p_my_r1_y, VU_BITS_TO_WORDS(bitsize));
    (void)Cy_Cryptolite_Vu_mov_hw (base, vu_struct0, p_t3, VU_BITS_TO_WORDS(bitsize), px, VU_BITS_TO_WORDS(bitsize));
    (void)Cy_Cryptolite_Vu_mov_hw (base, vu_struct1, p_t4, VU_BITS_TO_WORDS(bitsize), py, VU_BITS_TO_WORDS(bitsize));



    /*--------------------------------
    * b_{s+1}
    *--------------------------------
    */
    carry_sizeplus1 = (dc[VU_BITS_TO_BYTES(bitsize+2U)-4U] & (0x2U)) >> 1;
    (void)Cy_Cryptolite_Vu_lsl1_hw (base, vu_struct0, dc, VU_BITS_TO_WORDS(bitsize+2U), dc, VU_BITS_TO_WORDS(bitsize+2U));


    /*--------------------------------
    * b_{s}
    *--------------------------------
    */

    if (!(bool)carry_sizeplus1)
    {
        temp = px;
        px = p_t1;
        p_t1 = temp;

        temp = py;
        py = p_t2;
        p_t2 = temp;

        temp = p_my_r1_x;
        p_my_r1_x = p_t3;
        p_t3 = temp;

        temp = p_my_r1_y;
        p_my_r1_y = p_t4;
        p_t4 = temp;
    }

    Cy_Cryptolite_Vu_wait_hw(base);
    carry_size = (dc[VU_BITS_TO_BYTES(bitsize+2U)-4U] & (0x2U)) >> 1;
    (void)Cy_Cryptolite_Vu_lsl1_hw (base, vu_struct1, dc, VU_BITS_TO_WORDS(bitsize+2U), dc, VU_BITS_TO_WORDS(bitsize+2U));

    

    Cy_Cryptolite_EC_XYCZ_ADDC(base, cfContext, (int)carry_size, px, py, p_my_r1_x, p_my_r1_y, size);



    Cy_Cryptolite_EC_XYCZ_ADD(base, cfContext, (int)carry_size, px, py, p_my_r1_x, p_my_r1_y, size);



    carry_combination = ((!(bool)carry_sizeplus1) && (bool)carry_size);

    if (carry_combination)
    {
        temp = px;
        px = p_t1;
        p_t1 = temp;

        temp = py;
        py = p_t2;
        p_t2 = temp;

        temp = p_my_r1_x;
        p_my_r1_x = p_t3;
        p_t3 = temp;

        temp = p_my_r1_y;
        p_my_r1_y = p_t4;
        p_t4 = temp;
    }

    carry_sizeminus1 = (dc[VU_BITS_TO_BYTES(bitsize+2U)-4U] & (0x2U)) >> 1U;
    (void)Cy_Cryptolite_Vu_lsl1_hw (base, vu_struct0, dc, VU_BITS_TO_WORDS(bitsize+2U), dc, VU_BITS_TO_WORDS(bitsize+2U));
    Cy_Cryptolite_EC_XYCZ_ADDC(base, cfContext, (int)carry_sizeminus1, px, py, p_my_r1_x, p_my_r1_y, size);
    Cy_Cryptolite_EC_XYCZ_ADD(base, cfContext, (int)carry_sizeminus1, px, py, p_my_r1_x, p_my_r1_y, size);

    carry_combination = !(bool)carry_sizeplus1 && !(bool)carry_size && (bool)carry_sizeminus1;

    if (carry_combination)
    {
        temp = px;
        px = p_t1;
        p_t1 = temp;

        temp = py;
        py = p_t2;
        p_t2 = temp;

        temp = p_my_r1_x;
        p_my_r1_x = p_t3;
        p_t3 = temp;

        temp = p_my_r1_y;
        p_my_r1_y = p_t4;
        p_t4 = temp;
    }

    even_size = (bool)(size % 2) ? (size -1) : size;
    for (i = 0; i < (even_size-2); i+=2)
    {
        carry = (dc[VU_BITS_TO_BYTES(bitsize+2U)-4U] & (0x2U)) >> 1;
        (void)Cy_Cryptolite_Vu_lsl1_hw (base, vu_struct1, dc, VU_BITS_TO_WORDS(bitsize+2U), dc, VU_BITS_TO_WORDS(bitsize+2U));
        Cy_Cryptolite_EC_XYCZ_ADDC (base, cfContext, (int)carry, px, py, p_my_r1_x, p_my_r1_y, size);
        Cy_Cryptolite_EC_XYCZ_ADD  (base, cfContext, (int)carry, px, py, p_my_r1_x, p_my_r1_y, size);

        carry = (dc[VU_BITS_TO_BYTES(bitsize+2U)-4U] & (0x2U)) >> 1;
        (void)Cy_Cryptolite_Vu_lsl1_hw (base, vu_struct0, dc, VU_BITS_TO_WORDS(bitsize+2U), dc, VU_BITS_TO_WORDS(bitsize+2U));
        Cy_Cryptolite_EC_XYCZ_ADDC (base, cfContext, (int)carry, px, py, p_my_r1_x, p_my_r1_y, size);
        Cy_Cryptolite_EC_XYCZ_ADD  (base, cfContext, (int)carry, px, py, p_my_r1_x, p_my_r1_y, size);
    }

    if (!(bool)even_size)
    {
        carry = (dc[VU_BITS_TO_BYTES(bitsize+2U)-4U] & (0x2U)) >> 1;
        (void)Cy_Cryptolite_Vu_lsl1_hw (base, vu_struct1, dc, VU_BITS_TO_WORDS(bitsize+2U), dc, VU_BITS_TO_WORDS(bitsize+2U));
        Cy_Cryptolite_EC_XYCZ_ADDC (base, cfContext, (int)carry, px, py, p_my_r1_x, p_my_r1_y, size);
        Cy_Cryptolite_EC_XYCZ_ADD  (base, cfContext, (int)carry, px, py, p_my_r1_x, p_my_r1_y, size);
    }

    carry = (dc[VU_BITS_TO_BYTES(bitsize+2U)-4U] & (0x2U)) >> 1;
    (void)Cy_Cryptolite_Vu_lsl1_hw (base, vu_struct0, dc, VU_BITS_TO_WORDS(bitsize+2U), dc, VU_BITS_TO_WORDS(bitsize+2U));

    Cy_Cryptolite_EC_XYCZ_ADDC (base, cfContext, (int)carry, px, py, p_my_r1_x, p_my_r1_y, size);
    Cy_Cryptolite_EC_SubMod (base, cfContext, p_t1, p_my_r1_x, px);
    Cy_Cryptolite_EC_MulMod (base, cfContext, p_t1, p_t1, my_p_x, size);

    (void)Cy_Cryptolite_Vu_mov_hw (base, vu_struct0, p_t2, VU_BITS_TO_WORDS(bitsize), px, VU_BITS_TO_WORDS(bitsize));
    (void)Cy_Cryptolite_Vu_mov_hw (base, vu_struct1, p_t3, VU_BITS_TO_WORDS(bitsize), py, VU_BITS_TO_WORDS(bitsize));

    /* Swap values if carry bit is set to 1 */
    if ((bool)carry)
    {
        p_t2 = p_my_r1_x;
        p_t3 = p_my_r1_y;
    }

    Cy_Cryptolite_EC_MulMod( base, cfContext, p_t3, p_t1, p_t3, size);
    Cy_Cryptolite_Vu_wait_hw(base);

    Cy_Cryptolite_Vu_clr(p_t1, VU_BITS_TO_WORDS(bitsize));
    Cy_Cryptolite_Vu_set_bit(p_t1, 0);

    Cy_Cryptolite_EC_DivMod(base, cfContext, p_t3, p_t1, p_t3, (int)size);
    Cy_Cryptolite_EC_MulMod(base, cfContext, p_t1, my_p_y, p_t3, size);
    Cy_Cryptolite_EC_MulMod(base, cfContext, lambda, p_t2, p_t1, size);
    Cy_Cryptolite_EC_XYCZ_ADD(base, cfContext, (int)carry, px, py, p_my_r1_x, p_my_r1_y, size);

    Cy_Cryptolite_EC_SquareMod(base, cfContext, my_p_x, lambda, size);
    Cy_Cryptolite_EC_MulMod(base, cfContext, lambda, my_p_x, lambda, size);
    Cy_Cryptolite_EC_MulMod(base, cfContext, px, px, my_p_x, size);
    Cy_Cryptolite_EC_MulMod(base, cfContext, py, py, lambda, size);
}

/**
* @brief Elliptic curve point multiplication in GF(p)
* @param[in] p_x        Register index for affine X coordinate of base point.
* @param[in] p_y        Register index for affine Y coordinate of base point.
* @param[in] p_d        Register index for multiplication value.
* @param[in] p_order    Register index for order value.
* @param[in] bitsize    Bit size of the used curve.
*/
void Cy_Cryptolite_EC_NistP_PointMul(CRYPTOLITE_Type *base,
                            cy_stc_cryptolite_context_ecdsa_t *cfContext,
                            uint8_t *p_x, uint8_t *p_y,
                            uint8_t *p_d, uint8_t *p_order,
                            int bitsize)
{
    Cy_Cryptolite_EC_JacobianEcScalarMul_coZ(base, cfContext, p_x, p_y, p_d, bitsize, p_order);
    Cy_Cryptolite_Vu_wait_hw(base);
}


#endif /* #if defined(CY_CRYPTOLITE_CFG_ECP_C) */
#endif /* #if (CPUSS_CRYPTOLITE_VU == 1) */

#if defined(__cplusplus)
}
#endif

#endif /* CY_IP_MXCRYPTOLITE */


