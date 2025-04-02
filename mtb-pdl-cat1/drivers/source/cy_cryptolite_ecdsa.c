/***************************************************************************//**
* \file cy_cryptolite_ecdsa.c
* \version 2.80
*
* \brief
*  This file provides constant and parameters
*  for the API of the ECDSA in the Cryptolite driver.
*
********************************************************************************
* Copyright 2020-2021 Cypress Semiconductor Corporation
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

#include "cy_sysint.h"
#include "cy_cryptolite_ecdsa.h"
#include "cy_cryptolite_nist_p.h"

#if (CRYPTOLITE_VU_PRESENT == 1)
#if defined(CY_CRYPTOLITE_CFG_ECDSA_C)

#include "cy_cryptolite_utils.h"
#include "cy_cryptolite_ecc_key_gen.h"

/*******************************************************************************
* Function Name: Cy_Cryptolite_ECC_GetCurveParams
****************************************************************************//**
*
* Get curve domain parameters if this curve is supported.
*
* \param curveId
* See \ref cy_en_cryptolite_ecc_curve_id_t.
*
* \return
* Pointer to curve domain parameters. See \ref cy_stc_cryptolite_ecc_dp_type.
*
*******************************************************************************/
cy_stc_cryptolite_ecc_dp_type *Cy_Cryptolite_ECC_GetCurveParams(cy_en_cryptolite_ecc_curve_id_t curveId)
{
    /* P192 CURVE PARAMETERS */
#ifdef CY_CRYPTOLITE_CFG_ECP_DP_SECP192R1_ENABLED
    CY_ALIGN(4) static const uint8_t  eccP192Polynomial[CY_CRYPTOLITE_ECC_P192_BYTE_SIZE] =
    {
       0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu,
       0xfeu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu,
       0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu,
    };

    CY_ALIGN(4) static const uint8_t  eccP192PolyBarrett[CY_CRYPTOLITE_ECC_P192_BYTE_SIZE + 1u] =
    {  /* pre-calculated */
       0x01u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
       0x01u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
       0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
       0x01u
    };
    CY_ALIGN(4) static const uint8_t  eccP192Order[CY_CRYPTOLITE_ECC_P192_BYTE_SIZE] =
    {
        0x31u, 0x28u, 0xD2u, 0xB4u, 0xB1u, 0xC9u, 0x6Bu, 0x14u,
        0x36u, 0xF8u, 0xDEu, 0x99u, 0xffu, 0xffu, 0xffu, 0xffu,
        0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu
    };

    /* barrett_o: "1000000000000000000000000662107c9eb94364e4b2dd7cf" */
    CY_ALIGN(4) static const uint8_t  eccP192OrderBarrett[CY_CRYPTOLITE_ECC_P192_BYTE_SIZE + 1u] =
    {   /* pre-calculated */
        0xcfu, 0xd7u, 0x2du, 0x4bu, 0x4eu, 0x36u, 0x94u, 0xebu,
        0xc9u, 0x07u, 0x21u, 0x66u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x01u
    };

    /* base point x: "188DA80EB03090F67CBF20EB43A18800F4FF0AFD82FF1012" */
    CY_ALIGN(4) static const uint8_t  eccP192BasePointX[CY_CRYPTOLITE_ECC_P192_BYTE_SIZE] =
    {
        0x12u, 0x10u, 0xffu, 0x82u, 0xfdu, 0x0au, 0xffu, 0xf4u,
        0x00u, 0x88u, 0xa1u, 0x43u, 0xebu, 0x20u, 0xbfu, 0x7cu,
        0xf6u, 0x90u, 0x30u, 0xb0u, 0x0eu, 0xa8u, 0x8du, 0x18u
    };

    /* base point y: "07192B95FFC8DA78631011ED6B24CDD573F977A11E794811" */
    CY_ALIGN(4) static const uint8_t  eccP192BasePointY[CY_CRYPTOLITE_ECC_P192_BYTE_SIZE] =
    {
        0x11u, 0x48u, 0x79u, 0x1eu, 0xa1u, 0x77u, 0xf9u, 0x73u,
        0xd5u, 0xcdu, 0x24u, 0x6bu, 0xedu, 0x11u, 0x10u, 0x63u,
        0x78u, 0xdau, 0xc8u, 0xffu, 0x95u, 0x2bu, 0x19u, 0x07u
    };
#endif
    /* P224 CURVE PARAMETERS */
#ifdef CY_CRYPTOLITE_CFG_ECP_DP_SECP224R1_ENABLED
    CY_ALIGN(4) static const uint8_t  eccP224Polynomial[CY_CRYPTOLITE_ECC_P224_BYTE_SIZE] =
    {
       0x01u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
       0x00u, 0x00u, 0x00u, 0x00u, 0xffu, 0xffu, 0xffu, 0xffu,
       0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu,
       0xffu, 0xffu, 0xffu, 0xffu
    };

    CY_ALIGN(4) static const uint8_t  eccP224PolyBarrett[CY_CRYPTOLITE_ECC_P224_BYTE_SIZE + 1u] =
    {  /* pre-calculated */
       0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu,
       0xffu, 0xffu, 0xffu, 0xffu, 0x00u, 0x00u, 0x00u, 0x00u,
       0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
       0x00u, 0x00u, 0x00u, 0x00u, 0x01u
    };

    CY_ALIGN(4) static const uint8_t  eccP224Order[CY_CRYPTOLITE_ECC_P224_BYTE_SIZE] =
    {
        0x3Du, 0x2Au, 0x5Cu, 0x5Cu, 0x45u, 0x29u, 0xDDu, 0x13u,
        0x3Eu, 0xF0u, 0xB8u, 0xE0u, 0xA2u, 0x16u, 0xffu, 0xffu,
        0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu,
        0xffu, 0xffu, 0xffu, 0xffu
    };
    /* barrett_o: "10000000000000000000000000000e95d1f470fc1ec22d6baa3a3d5c3" */
    CY_ALIGN(4) static const uint8_t  eccP224OrderBarrett[CY_CRYPTOLITE_ECC_P224_BYTE_SIZE + 1u] =
    {   /* pre-calculated */
        0xc3u, 0xd5u, 0xa3u, 0xa3u, 0xbau, 0xd6u, 0x22u, 0xecu,
        0xc1u, 0x0fu, 0x47u, 0x1fu, 0x5du, 0xe9u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x01u
    };

    /* Gx - base point x: "B70E0CBD6BB4BF7F321390B94A03C1D356C21122343280D6115C1D21" */
    CY_ALIGN(4) static const uint8_t  eccP224BasePointX[CY_CRYPTOLITE_ECC_P224_BYTE_SIZE] =
    {
        0x21u, 0x1du, 0x5cu, 0x11u, 0xd6u, 0x80u, 0x32u, 0x34u,
        0x22u, 0x11u, 0xc2u, 0x56u, 0xd3u, 0xc1u, 0x03u, 0x4au,
        0xb9u, 0x90u, 0x13u, 0x32u, 0x7fu, 0xbfu, 0xb4u, 0x6bu,
        0xbdu, 0x0cu, 0x0eu, 0xb7u
    };

    /* Gy - base point y: "BD376388B5F723FB4C22DFE6CD4375A05A07476444D5819985007E34" */
    CY_ALIGN(4) static const uint8_t  eccP224BasePointY[CY_CRYPTOLITE_ECC_P224_BYTE_SIZE] =
    {
        0x34u, 0x7eu, 0x00u, 0x85u, 0x99u, 0x81u, 0xd5u, 0x44u,
        0x64u, 0x47u, 0x07u, 0x5au, 0xa0u, 0x75u, 0x43u, 0xcdu,
        0xe6u, 0xdfu, 0x22u, 0x4cu, 0xfbu, 0x23u, 0xf7u, 0xb5u,
        0x88u, 0x63u, 0x37u, 0xbdu
    };
#endif
    /* P256 CURVE PARAMETERS */
#ifdef CY_CRYPTOLITE_CFG_ECP_DP_SECP256R1_ENABLED
    /* prime: "FFFFFFFF00000001000000000000000000000000FFFFFFFFFFFFFFFFFFFFFFFF" */
    CY_ALIGN(4) static const uint8_t  eccP256Polynomial[CY_CRYPTOLITE_ECC_P256_BYTE_SIZE] =
    {
       0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu,
       0xffu, 0xffu, 0xffu, 0xffu, 0x00u, 0x00u, 0x00u, 0x00u,
       0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
       0x01u, 0x00u, 0x00u, 0x00u, 0xffu, 0xffu, 0xffu, 0xffu
    };

    /* barrett_p: "100000000fffffffffffffffefffffffefffffffeffffffff0000000000000003" */
    CY_ALIGN(4) static const uint8_t  eccP256PolyBarrett[CY_CRYPTOLITE_ECC_P256_BYTE_SIZE + 1u] =
    {  /* pre-calculated! */
       0x03u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
       0xffu, 0xffu, 0xffu, 0xffu, 0xfeu, 0xffu, 0xffu, 0xffu,
       0xfeu, 0xffu, 0xffu, 0xffu, 0xfeu, 0xffu, 0xffu, 0xffu,
       0xffu, 0xffu, 0xffu, 0xffu, 0x00u, 0x00u, 0x00u, 0x00u,
       0x01u
    };

    /* order: "FFFFFFFF00000000FFFFFFFFFFFFFFFFBCE6FAADA7179E84F3B9CAC2FC632551" */
    CY_ALIGN(4) static const uint8_t  eccP256Order[CY_CRYPTOLITE_ECC_P256_BYTE_SIZE] =
    {
        0x51u, 0x25u, 0x63u, 0xfcu, 0xc2u, 0xcau, 0xb9u, 0xf3u,
        0x84u, 0x9eu, 0x17u, 0xa7u, 0xadu, 0xfau, 0xe6u, 0xbcu,
        0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu,
        0x00u, 0x00u, 0x00u, 0x00u, 0xffu, 0xffu, 0xffu, 0xffu
    };

    /* barrett_o: 100000000fffffffffffffffeffffffff43190552df1a6c21012ffd85eedf9bfe" */
    CY_ALIGN(4) static const uint8_t  eccP256OrderBarrett[CY_CRYPTOLITE_ECC_P256_BYTE_SIZE + 1u] =
    {   /* pre-calculated */
        0xfeu, 0x9bu, 0xdfu, 0xeeu, 0x85u, 0xfdu, 0x2fu, 0x01u,
        0x21u, 0x6cu, 0x1au, 0xdfu, 0x52u, 0x05u, 0x19u, 0x43u,
        0xffu, 0xffu, 0xffu, 0xffu, 0xfeu, 0xffu, 0xffu, 0xffu,
        0xffu, 0xffu, 0xffu, 0xffu, 0x00u, 0x00u, 0x00u, 0x00u,
        0x01u
    };

    /* base point x: "6B17D1F2E12C4247F8BCE6E563A440F277037D812DEB33A0F4A13945D898C296" */
    CY_ALIGN(4) static const uint8_t  eccP256BasePointX[CY_CRYPTOLITE_ECC_P256_BYTE_SIZE] =
    {
        0x96u, 0xc2u, 0x98u, 0xd8u, 0x45u, 0x39u, 0xa1u, 0xf4u,
        0xa0u, 0x33u, 0xebu, 0x2du, 0x81u, 0x7du, 0x03u, 0x77u,
        0xf2u, 0x40u, 0xa4u, 0x63u, 0xe5u, 0xe6u, 0xbcu, 0xf8u,
        0x47u, 0x42u, 0x2cu, 0xe1u, 0xf2u, 0xd1u, 0x17u, 0x6bu
    };

    /* base point y: "4FE342E2FE1A7F9B8EE7EB4A7C0F9E162BCE33576B315ECECBB6406837BF51F5" */
    CY_ALIGN(4) static const uint8_t  eccP256BasePointY[CY_CRYPTOLITE_ECC_P256_BYTE_SIZE] =
    {
        0xf5u, 0x51u, 0xbfu, 0x37u, 0x68u, 0x40u, 0xb6u, 0xcbu,
        0xceu, 0x5eu, 0x31u, 0x6bu, 0x57u, 0x33u, 0xceu, 0x2bu,
        0x16u, 0x9eu, 0x0fu, 0x7cu, 0x4au, 0xebu, 0xe7u, 0x8eu,
        0x9bu, 0x7fu, 0x1au, 0xfeu, 0xe2u, 0x42u, 0xe3u, 0x4fu,
    };
#endif
    /* P384 CURVE PARAMETERS */
#ifdef CY_CRYPTOLITE_CFG_ECP_DP_SECP384R1_ENABLED
    /* prime: "FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFFFFFFFF0000000000000000FFFFFFFF" */
    CY_ALIGN(4) static const uint8_t  eccP384Polynomial[CY_CRYPTOLITE_ECC_P384_BYTE_SIZE] =
    {
        0xffu, 0xffu, 0xffu, 0xffu, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0xffu, 0xffu, 0xffu, 0xffu,
        0xfeu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu,
        0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu,
        0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu,
        0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu
    };

    /* barrett_p: "1000000000000000000000000000000000000000000000000000000000000000100000000ffffffffffffffff00000001" */
    CY_ALIGN(4) static const uint8_t  eccP384PolyBarrett[CY_CRYPTOLITE_ECC_P384_BYTE_SIZE + 1u] =
    {   /* pre-calculated */
        0x01u, 0x00u, 0x00u, 0x00u, 0xffu, 0xffu, 0xffu, 0xffu,
        0xffu, 0xffu, 0xffu, 0xffu, 0x00u, 0x00u, 0x00u, 0x00u,
        0x01u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x01u
    };

    /* order: "FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFC7634D81F4372DDF581A0DB248B0A77AECEC196ACCC52973" */
    CY_ALIGN(4) static const uint8_t  eccP384Order[CY_CRYPTOLITE_ECC_P384_BYTE_SIZE] =
    {
        0x73u, 0x29u, 0xC5u, 0xCCu, 0x6Au, 0x19u, 0xECu, 0xECu,
        0x7Au, 0xA7u, 0xB0u, 0x48u, 0xB2u, 0x0Du, 0x1Au, 0x58u,
        0xDFu, 0x2Du, 0x37u, 0xF4u, 0x81u, 0x4Du, 0x63u, 0xC7u,
        0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu,
        0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu,
        0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu
    };

    /* barrett_o: "1000000000000000000000000000000000000000000000000389cb27e0bc8d220a7e5f24db74f58851313e695333ad68d" */
    CY_ALIGN(4) static const uint8_t  eccP384OrderBarrett[CY_CRYPTOLITE_ECC_P384_BYTE_SIZE + 1u] =
    {   /* pre-calculated */
        0x8du, 0xd6u, 0x3au, 0x33u, 0x95u, 0xe6u, 0x13u, 0x13u,
        0x85u, 0x58u, 0x4fu, 0xb7u, 0x4du, 0xf2u, 0xe5u, 0xa7u,
        0x20u, 0xd2u, 0xc8u, 0x0bu, 0x7eu, 0xb2u, 0x9cu, 0x38u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x01u
    };

    /* base point x: "AA87CA22BE8B05378EB1C71EF320AD746E1D3B628BA79B9859F741E082542A385502F25DBF55296C3A545E3872760AB7" */
    CY_ALIGN(4) static const uint8_t  eccP384BasePointX[CY_CRYPTOLITE_ECC_P384_BYTE_SIZE] =
    {
        0xb7u, 0x0au, 0x76u, 0x72u, 0x38u, 0x5eu, 0x54u, 0x3au,
        0x6cu, 0x29u, 0x55u, 0xbfu, 0x5du, 0xf2u, 0x02u, 0x55u,
        0x38u, 0x2au, 0x54u, 0x82u, 0xe0u, 0x41u, 0xf7u, 0x59u,
        0x98u, 0x9bu, 0xa7u, 0x8bu, 0x62u, 0x3bu, 0x1du, 0x6eu,
        0x74u, 0xadu, 0x20u, 0xf3u, 0x1eu, 0xc7u, 0xb1u, 0x8eu,
        0x37u, 0x05u, 0x8bu, 0xbeu, 0x22u, 0xcau, 0x87u, 0xaau
    };

    /* base point y: "3617DE4A96262C6F5D9E98BF9292DC29F8F41DBD289A147CE9DA3113B5F0B8C00A60B1CE1D7E819D7A431D7C90EA0E5F" */
    CY_ALIGN(4) static const uint8_t  eccP384BasePointY[CY_CRYPTOLITE_ECC_P384_BYTE_SIZE] =
    {
        0x5fu, 0x0eu, 0xeau, 0x90u, 0x7cu, 0x1du, 0x43u, 0x7au,
        0x9du, 0x81u, 0x7eu, 0x1du, 0xceu, 0xb1u, 0x60u, 0x0au,
        0xc0u, 0xb8u, 0xf0u, 0xb5u, 0x13u, 0x31u, 0xdau, 0xe9u,
        0x7cu, 0x14u, 0x9au, 0x28u, 0xbdu, 0x1du, 0xf4u, 0xf8u,
        0x29u, 0xdcu, 0x92u, 0x92u, 0xbfu, 0x98u, 0x9eu, 0x5du,
        0x6fu, 0x2cu, 0x26u, 0x96u, 0x4au, 0xdeu, 0x17u, 0x36u
    };
#endif
    /* P521 CURVE PARAMETERS */
#ifdef CY_CRYPTOLITE_CFG_ECP_DP_SECP521R1_ENABLED
    CY_ALIGN(4) static const uint8_t  eccP521Polynomial[CY_CRYPTOLITE_ECC_P521_BYTE_SIZE] =
    {
       0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu,
       0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu,
       0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu,
       0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu,
       0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu,
       0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu,
       0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu,
       0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu,
       0xffu, 0x01u, 0x00u, 0x00u
    };

    CY_ALIGN(4) static const uint8_t  eccP521PolyBarrett[CY_CRYPTOLITE_ECC_P521_BYTE_SIZE] =
    {  /* pre-calculated */
       0x01u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
       0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
       0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
       0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
       0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
       0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
       0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
       0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
       0x00u, 0x02u, 0x00u, 0x00u
    };

    CY_ALIGN(4) static const uint8_t  eccP521Order[CY_CRYPTOLITE_ECC_P521_BYTE_SIZE] =
    {
        0x09u, 0x64u, 0x38u, 0x91u, 0x1Eu, 0xB7u, 0x6Fu, 0xBBu,
        0xAEu, 0x47u, 0x9Cu, 0x89u, 0xB8u, 0xC9u, 0xB5u, 0x3Bu,
        0xD0u, 0xA5u, 0x09u, 0xF7u, 0x48u, 0x01u, 0xCCu, 0x7Fu,
        0x6Bu, 0x96u, 0x2Fu, 0xBFu, 0x83u, 0x87u, 0x86u, 0x51u,
        0xFAu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu,
        0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu,
        0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu,
        0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu,
        0xffu, 0x01u, 0x00u, 0x00u
    };

    /* barrett_o: "2000000000000000000000000000000000000000000000000000000000000000005ae79787c40d069948033feb708f65a2fc44a36477663b851449048e16ec79bf7" */
    CY_ALIGN(4) static const uint8_t  eccP521OrderBarrett[CY_CRYPTOLITE_ECC_P521_BYTE_SIZE] =
    {   /* pre-calculated */
        0xf7u, 0x9bu, 0xc7u, 0x6eu, 0xe1u, 0x48u, 0x90u, 0x44u,
        0x51u, 0xb8u, 0x63u, 0x76u, 0x47u, 0x36u, 0x4au, 0xc4u,
        0x2fu, 0x5au, 0xf6u, 0x08u, 0xb7u, 0xfeu, 0x33u, 0x80u,
        0x94u, 0x69u, 0xd0u, 0x40u, 0x7cu, 0x78u, 0x79u, 0xaeu,
        0x05u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x02u, 0x00u, 0x00u
    };

    /* base point x: "00C6858E06B70404E9CD9E3ECB662395B4429C648139053FB521F828AF606B4D3DBAA14B5E77EFE75928FE1DC127A2FFA8DE3348B3C1856A429BF97E7E31C2E5BD66" */
    CY_ALIGN(4) static const uint8_t  eccP521BasePointX[CY_CRYPTOLITE_ECC_P521_BYTE_SIZE] =
    {
        0x66u, 0xbdu, 0xe5u, 0xc2u, 0x31u, 0x7eu, 0x7eu, 0xf9u,
        0x9bu, 0x42u, 0x6au, 0x85u, 0xc1u, 0xb3u, 0x48u, 0x33u,
        0xdeu, 0xa8u, 0xffu, 0xa2u, 0x27u, 0xc1u, 0x1du, 0xfeu,
        0x28u, 0x59u, 0xe7u, 0xefu, 0x77u, 0x5eu, 0x4bu, 0xa1u,
        0xbau, 0x3du, 0x4du, 0x6bu, 0x60u, 0xafu, 0x28u, 0xf8u,
        0x21u, 0xb5u, 0x3fu, 0x05u, 0x39u, 0x81u, 0x64u, 0x9cu,
        0x42u, 0xb4u, 0x95u, 0x23u, 0x66u, 0xcbu, 0x3eu, 0x9eu,
        0xcdu, 0xe9u, 0x04u, 0x04u, 0xb7u, 0x06u, 0x8eu, 0x85u,
        0xc6u, 0x00u, 0x00u, 0x00u
    };

    /* base point y: "011839296A789A3BC0045C8A5FB42C7D1BD998F54449579B446817AFBD17273E662C97EE72995EF42640C550B9013FAD0761353C7086A272C24088BE94769FD16650" */
    CY_ALIGN(4) static const uint8_t  eccP521BasePointY[CY_CRYPTOLITE_ECC_P521_BYTE_SIZE] =
    {
        0x50u, 0x66u, 0xd1u, 0x9fu, 0x76u, 0x94u, 0xbeu, 0x88u,
        0x40u, 0xc2u, 0x72u, 0xa2u, 0x86u, 0x70u, 0x3cu, 0x35u,
        0x61u, 0x07u, 0xadu, 0x3fu, 0x01u, 0xb9u, 0x50u, 0xc5u,
        0x40u, 0x26u, 0xf4u, 0x5eu, 0x99u, 0x72u, 0xeeu, 0x97u,
        0x2cu, 0x66u, 0x3eu, 0x27u, 0x17u, 0xbdu, 0xafu, 0x17u,
        0x68u, 0x44u, 0x9bu, 0x57u, 0x49u, 0x44u, 0xf5u, 0x98u,
        0xd9u, 0x1bu, 0x7du, 0x2cu, 0xb4u, 0x5fu, 0x8au, 0x5cu,
        0x04u, 0xc0u, 0x3bu, 0x9au, 0x78u, 0x6au, 0x29u, 0x39u,
        0x18u, 0x01u, 0x00u, 0x00u
    };
#endif

    static const cy_stc_cryptolite_ecc_dp_type eccDomainParams[] =
    {
        {
            CY_CRYPTOLITE_ECC_ECP_NONE,
            0u,
            NULL,
            CY_CRYPTOLITE_NIST_P_CURVE_SPECIFIC_RED_ALG,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL
        },
#ifdef CY_CRYPTOLITE_CFG_ECP_DP_SECP192R1_ENABLED
        {
            CY_CRYPTOLITE_ECC_ECP_SECP192R1,
            CY_CRYPTOLITE_ECC_P192_SIZE,
            "NIST P-192",
            CY_CRYPTOLITE_NIST_P_CURVE_SPECIFIC_RED_ALG,
            /* prime: "FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFFFFFFFFFFFFFFFF" */
            eccP192Polynomial,
            /* barrett_p: "1000000000000000000000000000000010000000000000001" */
            eccP192PolyBarrett,
            /* order: "FFFFFFFFFFFFFFFFFFFFFFFF99DEF836146BC9B1B4D22831" */
            eccP192Order,
            /* barrett_o: "1000000000000000000000000662107c9eb94364e4b2dd7cf" */
            eccP192OrderBarrett,
            /* base point x: "188DA80EB03090F67CBF20EB43A18800F4FF0AFD82FF1012" */
            eccP192BasePointX,
            /* base point y: "07192B95FFC8DA78631011ED6B24CDD573F977A11E794811" */
            eccP192BasePointY
        },
#endif
#ifdef CY_CRYPTOLITE_CFG_ECP_DP_SECP224R1_ENABLED
        {
            CY_CRYPTOLITE_ECC_ECP_SECP224R1,
            CY_CRYPTOLITE_ECC_P224_SIZE,
            "NIST P-224",
            CY_CRYPTOLITE_NIST_P_CURVE_SPECIFIC_RED_ALG,
            /* prime: "FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000000000000000000001" */
            eccP224Polynomial,
            /* barrett_p: "100000000000000000000000000000000ffffffffffffffffffffffff" */
            eccP224PolyBarrett,
            /* order: "FFFFFFFFFFFFFFFFFFFFFFFFFFFF16A2E0B8F03E13DD29455C5C2A3D" */
            eccP224Order,
            /* barrett_o: "10000000000000000000000000000e95d1f470fc1ec22d6baa3a3d5c3" */
            eccP224OrderBarrett,
            /* Gx - base point x: "B70E0CBD6BB4BF7F321390B94A03C1D356C21122343280D6115C1D21" */
            eccP224BasePointX,
            /* Gy - base point y: "BD376388B5F723FB4C22DFE6CD4375A05A07476444D5819985007E34" */
            eccP224BasePointY
        },
#endif
#ifdef CY_CRYPTOLITE_CFG_ECP_DP_SECP256R1_ENABLED
        {
            CY_CRYPTOLITE_ECC_ECP_SECP256R1,
            CY_CRYPTOLITE_ECC_P256_SIZE,
            "NIST P-256",
            CY_CRYPTOLITE_NIST_P_BARRETT_RED_ALG,
            /* prime: "FFFFFFFF00000001000000000000000000000000FFFFFFFFFFFFFFFFFFFFFFFF" */
            eccP256Polynomial,
            /* barrett_p: "100000000fffffffffffffffefffffffefffffffeffffffff0000000000000003" */
            eccP256PolyBarrett,
            /* order: "FFFFFFFF00000000FFFFFFFFFFFFFFFFBCE6FAADA7179E84F3B9CAC2FC632551" */
            eccP256Order,
            /* barrett_o: "100000000fffffffffffffffeffffffff43190552df1a6c21012ffd85eedf9bfe" */
            eccP256OrderBarrett,
            /* Gx - base point x: "6B17D1F2E12C4247F8BCE6E563A440F277037D812DEB33A0F4A13945D898C296" */
            eccP256BasePointX,
            /* Gy - base point y: "4FE342E2FE1A7F9B8EE7EB4A7C0F9E162BCE33576B315ECECBB6406837BF51F5" */
            eccP256BasePointY
        },
#endif
#ifdef CY_CRYPTOLITE_CFG_ECP_DP_SECP384R1_ENABLED
        {
            CY_CRYPTOLITE_ECC_ECP_SECP384R1,
            CY_CRYPTOLITE_ECC_P384_SIZE,
            "NIST P-384",
            CY_CRYPTOLITE_NIST_P_BARRETT_RED_ALG,
            /* prime: "FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFFFFFFFF0000000000000000FFFFFFFF" */
            eccP384Polynomial,
            /* barrett_p: "1000000000000000000000000000000000000000000000000000000000000000100000000ffffffffffffffff00000001" */
            eccP384PolyBarrett,
            /* order: "FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFC7634D81F4372DDF581A0DB248B0A77AECEC196ACCC52973" */
            eccP384Order,
            /* barrett_o: "1000000000000000000000000000000000000000000000000389cb27e0bc8d220a7e5f24db74f58851313e695333ad68d" */
            eccP384OrderBarrett,
            /* base point x: "AA87CA22BE8B05378EB1C71EF320AD746E1D3B628BA79B9859F741E082542A385502F25DBF55296C3A545E3872760AB7" */
            eccP384BasePointX,
            /* base point y: "3617DE4A96262C6F5D9E98BF9292DC29F8F41DBD289A147CE9DA3113B5F0B8C00A60B1CE1D7E819D7A431D7C90EA0E5F" */
            eccP384BasePointY
        },
#endif
#ifdef CY_CRYPTOLITE_CFG_ECP_DP_SECP521R1_ENABLED
        {
            CY_CRYPTOLITE_ECC_ECP_SECP521R1,
            CY_CRYPTOLITE_ECC_P521_SIZE,
            "NIST P-521",
            CY_CRYPTOLITE_NIST_P_CURVE_SPECIFIC_RED_ALG,
            /* prime: "1FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF" */
            eccP521Polynomial,
            /* barrett_p: "20000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001" */
            eccP521PolyBarrett,
            /* order: "1FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFA51868783BF2F966B7FCC0148F709A5D03BB5C9B8899C47AEBB6FB71E91386409" */
            eccP521Order,
            /* barrett_o: "2000000000000000000000000000000000000000000000000000000000000000005ae79787c40d069948033feb708f65a2fc44a36477663b851449048e16ec79bf7" */
            eccP521OrderBarrett,
            /* base point x: "0C6858E06B70404E9CD9E3ECB662395B4429C648139053FB521F828AF606B4D3DBAA14B5E77EFE75928FE1DC127A2FFA8DE3348B3C1856A429BF97E7E31C2E5BD66" */
            eccP521BasePointX,
            /* base point y: "11839296A789A3BC0045C8A5FB42C7D1BD998F54449579B446817AFBD17273E662C97EE72995EF42640C550B9013FAD0761353C7086A272C24088BE94769FD16650" */
            eccP521BasePointY
        },
#endif
#if defined(CY_CRYPTOLITE_CFG_ECP_DP_ED25519_ENABLED)
        /* This is a NULL entry to fix coverity */
        {
            CY_CRYPTOLITE_ECC_ECP_NONE,
            0u,
            NULL,
            CY_CRYPTOLITE_NIST_P_CURVE_SPECIFIC_RED_ALG,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL
        },
#endif /* defined(CY_CRYPTOLITE_CFG_ECP_DP_ED25519_ENABLED) */
#if defined(CY_CRYPTOLITE_CFG_ECP_DP_EC25519_ENABLED)
        /* This is a NULL entry to fix coverity */
        {
            CY_CRYPTOLITE_ECC_ECP_NONE,
            0u,
            NULL,
            CY_CRYPTOLITE_NIST_P_CURVE_SPECIFIC_RED_ALG,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL
        }
#endif /* defined(CY_CRYPTOLITE_CFG_ECP_DP_EC25519_ENABLED) */

    };

    cy_stc_cryptolite_ecc_dp_type *tmpResult = NULL;

    if ((curveId > CY_CRYPTOLITE_ECC_ECP_NONE) && (curveId < CY_CRYPTOLITE_ECC_ECP_CURVES_CNT))
    {
#if defined(CY_CRYPTOLITE_CFG_ECP_DP_ED25519_ENABLED)
        if (CY_CRYPTOLITE_ECC_ECP_ED25519 == curveId)
        {
            return tmpResult;
        }
#endif /* defined(CY_CRYPTOLITE_CFG_ECP_DP_ED25519_ENABLED) */

#if defined(CY_CRYPTOLITE_CFG_ECP_DP_EC25519_ENABLED)
        if (CY_CRYPTOLITE_ECC_ECP_EC25519 == curveId)
        {
            return tmpResult;
        }
#endif /* defined(CY_CRYPTOLITE_CFG_ECP_DP_EC25519_ENABLED) */
        tmpResult = (cy_stc_cryptolite_ecc_dp_type *)&eccDomainParams[curveId];
    }

    return tmpResult;
}


/*******************************************************************************
* Function Name: Cy_Cryptolite_EC25519_GetCurveParams
****************************************************************************//**
*
* Get curve domain parameters if this curve is supported.
*
* \param curveId
* See \ref cy_en_cryptolite_ecc_curve_id_t.
*
* \return
* Pointer to curve domain parameters. See \ref cy_stc_cryptolite_ec25519_dp_type.
*
*******************************************************************************/
cy_stc_cryptolite_ec25519_dp_type *Cy_Cryptolite_EC25519_GetCurveParams(cy_en_cryptolite_ecc_curve_id_t curveId)
{
#if defined(CY_CRYPTOLITE_CFG_ECP_DP_ED25519_ENABLED) || defined(CY_CRYPTOLITE_CFG_ECP_DP_EC25519_ENABLED)
    /* ED25519 CURVE PARAMETERS */
    /* prime: "2^255 - 19" */
    /* prime: "7FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFED" */
    CY_ALIGN(4) static const uint8_t  ed25519Prime[CY_CRYPTOLITE_ECC_ED25519_BYTE_SIZE] =
    {
        0xedu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu,
        0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu,
        0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu,
        0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0x7fu
    };

    /* barrett_p: "2000000000000000000000000000000000000000000000000000000000000004C" */
    CY_ALIGN(4) static const uint8_t  ed25519PrimeBarrett[CY_CRYPTOLITE_ECC_ED25519_BYTE_SIZE + 1u] =
    {  /* pre-calculated! */
        0x4cu, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x02u,
    };
#endif /* defined(CY_CRYPTOLITE_CFG_ECP_DP_ED25519_ENABLED) || defined(CY_CRYPTOLITE_CFG_ECP_DP_EC25519_ENABLED) */

#if defined(CY_CRYPTOLITE_CFG_ECP_DP_ED25519_ENABLED)
    /* order: "2^252 + 0x14def9dea2f79cd65812631a5cf5d3ed" */
    /* order: "1000000000000000000000000000000014DEF9DEA2F79CD65812631A5CF5D3ED" */
    CY_ALIGN(4) static const uint8_t  ed25519Order[CY_CRYPTOLITE_ECC_ED25519_BYTE_SIZE] =
    {
        0xedu, 0xd3u, 0xf5u, 0x5cu, 0x1au, 0x63u, 0x12u, 0x58u,
        0xd6u, 0x9cu, 0xf7u, 0xa2u, 0xdeu, 0xf9u, 0xdeu, 0x14u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x10u
    };

    /* barrett_o: FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEB2106215D086329A7ED9CE5A30A2C131B" */
    CY_ALIGN(4) static const uint8_t  ed25519OrderBarrett[CY_CRYPTOLITE_ECC_ED25519_BYTE_SIZE + 1u] =
    {   /* pre-calculated */
        0x1bu, 0x13u, 0x2cu, 0x0au, 0xa3u, 0xe5u, 0x9cu, 0xedu,
        0xa7u, 0x29u, 0x63u, 0x08u, 0x5du, 0x21u, 0x06u, 0x21u,
        0xebu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu,
        0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu,
        0x0fu,
    };

    /*A: "7FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEC" */
    CY_ALIGN(4) static const uint8_t  ed25519A[CY_CRYPTOLITE_ECC_ED25519_BYTE_SIZE] =
    {
        0xecu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu,
        0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu,
        0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu,
        0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0x7fu
    };
    /*D: "52036cee2b6ffe738cc740797779e89800700a4d4141d8ab75eb4dca135978a3" */
    CY_ALIGN(4) static const uint8_t  ed25519D[CY_CRYPTOLITE_ECC_ED25519_BYTE_SIZE] =
    {
        0xa3u, 0x78u, 0x59u, 0x13u, 0xcau, 0x4du, 0xebu, 0x75u,
        0xabu, 0xd8u, 0x41u, 0x41u, 0x4du, 0x0au, 0x70u, 0x00u,
        0x98u, 0xe8u, 0x79u, 0x77u, 0x79u, 0x40u, 0xc7u, 0x8cu,
        0x73u, 0xfeu, 0x6fu, 0x2bu, 0xeeu, 0x6cu, 0x03u, 0x52u
    };

    /*(X(P),Y(P)) of edwards25519 in RFC7748*/
    /* base point x: "151122213495354007725011514095885315114540126930418572060461132
      83949847762202" */
    CY_ALIGN(4) static const uint8_t  ed25519BasePointX[CY_CRYPTOLITE_ECC_ED25519_BYTE_SIZE] =
    {
        0x1au, 0xd5u, 0x25u, 0x8fu, 0x60u, 0x2du, 0x56u, 0xc9u,
        0xb2u, 0xa7u, 0x25u, 0x95u, 0x60u, 0xc7u, 0x2cu, 0x69u,
        0x5cu, 0xdcu, 0xd6u, 0xfdu, 0x31u, 0xe2u, 0xa4u, 0xc0u,
        0xfeu, 0x53u, 0x6eu, 0xcdu, 0xd3u, 0x36u, 0x69u, 0x21u,
    };

    /* base point y: "463168356949264781694283940034751631413079938662562256157830336
      03165251855960" */
    CY_ALIGN(4) static const uint8_t  ed25519BasePointY[CY_CRYPTOLITE_ECC_ED25519_BYTE_SIZE] =
    {
        0x58u, 0x66u, 0x66u, 0x66u, 0x66u, 0x66u, 0x66u, 0x66u,
        0x66u, 0x66u, 0x66u, 0x66u, 0x66u, 0x66u, 0x66u, 0x66u,
        0x66u, 0x66u, 0x66u, 0x66u, 0x66u, 0x66u, 0x66u, 0x66u,
        0x66u, 0x66u, 0x66u, 0x66u, 0x66u, 0x66u, 0x66u, 0x66u,
    };

    if (curveId == CY_CRYPTOLITE_ECC_ECP_ED25519)
    {
        static cy_stc_cryptolite_ec25519_dp_type g_dp;
        cy_stc_cryptolite_ec25519_dp_type *dp = &g_dp;
        dp->id          = CY_CRYPTOLITE_ECC_ECP_ED25519;
        dp->size        = CY_CRYPTOLITE_ECC_ED25519_SIZE;
        dp->name        = "Edward's ED25519";
        dp->algo        = CY_CRYPTOLITE_NIST_P_BARRETT_RED_ALG;
        dp->prime       = ed25519Prime;
        dp->barrett_p   = ed25519PrimeBarrett;
        dp->order       = ed25519Order;
        dp->barrett_o   = ed25519OrderBarrett;
        dp->d           = ed25519D;
        dp->a           = ed25519A;
        dp->Gx          = ed25519BasePointX;
        dp->Gy          = ed25519BasePointY;
        dp->barret_osize = 260u;                     /* barret_o = (2^512(513 bits)/ed25519Order(253 bits) */
        dp->barret_psize = 258u;                     /* barret_p = (2^512(513 bits)/ed25519Prime(255 bits) */

        return dp;
    }

#endif /* defined(CY_CRYPTOLITE_CFG_ECP_DP_ED25519_ENABLED) */

#if defined(CY_CRYPTOLITE_CFG_ECP_DP_EC25519_ENABLED)
    /*A24: "(486662 + 2)/4 = 121665" */
    CY_ALIGN(4) static const uint8_t  ec25519A[3] =
    {
        0x41u, 0xDBu, 0x01u
    };
    /* base point x: "9" */
    CY_ALIGN(4) static const uint8_t  ec25519BasePointX[CY_CRYPTOLITE_ECC_EC25519_BYTE_SIZE] =
    {
        0x09u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u
    };

    if (curveId == CY_CRYPTOLITE_ECC_ECP_EC25519)
    {
        static cy_stc_cryptolite_ec25519_dp_type g_dp;
        cy_stc_cryptolite_ec25519_dp_type *dp = &g_dp;
        dp->id          = CY_CRYPTOLITE_ECC_ECP_EC25519;
        dp->size        = CY_CRYPTOLITE_ECC_EC25519_SIZE;
        dp->name        = "ECC EC25519";
        dp->algo        = CY_CRYPTOLITE_NIST_P_BARRETT_RED_ALG;
        dp->prime       = ed25519Prime;
        dp->barrett_p   = ed25519PrimeBarrett;
        dp->order       = NULL;
        dp->barrett_o   = NULL;
        dp->d           = NULL;
        dp->a           = ec25519A;
        dp->Gx          = ec25519BasePointX;
        dp->Gy          = NULL;
        dp->barret_osize = 0;
        dp->barret_psize = 258u;                   /* barret_p = (2^512(513 bits)/ed25519Prime(255 bits) */

        return dp;
    }

#endif /*defined(CY_CRYPTOLITE_CFG_ECP_DP_EC25519_ENABLED)*/

    (void)curveId;
    return NULL;
}

/*******************************************************************************
* Function Name: Cy_Cryptolite_ECC_Init
****************************************************************************//*
*
* Init ECC Context.
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
* \return status code. See \ref cy_en_cryptolite_status_t.
*
*******************************************************************************/
cy_en_cryptolite_status_t Cy_Cryptolite_ECC_Init(CRYPTOLITE_Type *base,
                            cy_stc_cryptolite_context_ecdsa_t *cfContext,
                            cy_stc_cryptolite_ecc_buffer_t *eccBuffer)
{
    if(base == NULL || cfContext == NULL || eccBuffer == NULL)
    {
        return CY_CRYPTOLITE_BAD_PARAMS;
    }

    cfContext->my_BARRETT_U = eccBuffer->my_BARRETT_U;
    cfContext->my_P         = eccBuffer->my_P;
    cfContext->dividend     = eccBuffer->dividend;
    cfContext->p_r          = eccBuffer->p_r;
    cfContext->p_s          = eccBuffer->p_s;
    cfContext->p_u1         = eccBuffer->p_u1;
    cfContext->p_u2         = eccBuffer->p_u2;
    cfContext->p_o          = eccBuffer->p_o;
    cfContext->p_gx         = eccBuffer->p_gx;
    cfContext->p_gy         = eccBuffer->p_gy;
    cfContext->p_qx         = eccBuffer->p_qx;
    cfContext->p_qy         = eccBuffer->p_qy;
    cfContext->p_buf         = eccBuffer->p_buf;

    return CY_CRYPTOLITE_SUCCESS;
}

/*******************************************************************************
* Function Name: Cy_Cryptolite_ECC_Free
****************************************************************************//*
*
* Clean up ECC Context.
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
cy_en_cryptolite_status_t Cy_Cryptolite_ECC_Free(CRYPTOLITE_Type *base,
                            cy_stc_cryptolite_context_ecdsa_t *cfContext)
{
    if(base == NULL || cfContext == NULL)
    {
        return CY_CRYPTOLITE_BAD_PARAMS;
    }

    if(cfContext->my_BARRETT_U != NULL)
    {
        Cy_Cryptolite_Vu_clr(cfContext->my_BARRETT_U, VU_BITS_TO_WORDS(BIT_SIZE+1U));
        cfContext->my_BARRETT_U = NULL;
    }
    if(cfContext->my_P != NULL)
    {
        Cy_Cryptolite_Vu_clr(cfContext->my_P, VU_BITS_TO_WORDS(BIT_SIZE));
        cfContext->my_P = NULL;
    }
    if(cfContext->dividend != NULL)
    {
        Cy_Cryptolite_Vu_clr(cfContext->dividend, VU_BITS_TO_WORDS(BIT_SIZE));
        cfContext->dividend = NULL;
    }
    if(cfContext->p_r != NULL)
    {
        Cy_Cryptolite_Vu_clr(cfContext->p_r, VU_BITS_TO_WORDS(BIT_SIZE));
        cfContext->p_r = NULL;
    }
    if(cfContext->p_s != NULL)
    {
        Cy_Cryptolite_Vu_clr(cfContext->p_s, VU_BITS_TO_WORDS(BIT_SIZE));
        cfContext->p_s = NULL;
    }
    if(cfContext->p_u1 != NULL)
    {
        Cy_Cryptolite_Vu_clr(cfContext->p_u1, VU_BITS_TO_WORDS(BIT_SIZE));
        cfContext->p_u1 = NULL;
    }
    if(cfContext->p_u2 != NULL)
    {
        Cy_Cryptolite_Vu_clr(cfContext->p_u2, VU_BITS_TO_WORDS(BIT_SIZE));
        cfContext->p_u2 = NULL;
    }
    if(cfContext->p_o != NULL)
    {
        Cy_Cryptolite_Vu_clr(cfContext->p_o, VU_BITS_TO_WORDS(BIT_SIZE));
        cfContext->p_o = NULL;
    }
    if(cfContext->p_gx != NULL)
    {
        Cy_Cryptolite_Vu_clr(cfContext->p_gx, VU_BITS_TO_WORDS(BIT_SIZE));
        cfContext->p_gx = NULL;
    }
    if(cfContext->p_gy != NULL)
    {
        Cy_Cryptolite_Vu_clr(cfContext->p_gy, VU_BITS_TO_WORDS(BIT_SIZE));
        cfContext->p_gy = NULL;
    }
    if(cfContext->p_qx != NULL)
    {
        Cy_Cryptolite_Vu_clr(cfContext->p_qx, VU_BITS_TO_WORDS(BIT_SIZE));
        cfContext->p_qx = NULL;
    }
    if(cfContext->p_qy != NULL)
    {
        Cy_Cryptolite_Vu_clr(cfContext->p_qy, VU_BITS_TO_WORDS(BIT_SIZE));
        cfContext->p_qy = NULL;
    }
    if(cfContext->p_buf != NULL)
    {
        Cy_Cryptolite_Vu_clr(cfContext->p_buf, VU_BITS_TO_WORDS(BIT_SIZE+1U));
        cfContext->p_buf = NULL;
    }
    return CY_CRYPTOLITE_SUCCESS;
}


/*******************************************************************************
* Function Name: Cy_Cryptolite_ECC_SharedSecret
****************************************************************************//**
*
* Generate a Shared Secret key from one private key and others public key.
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
* \param key
* The generated public ECC key. See \ref cy_stc_cryptolite_ecc_key.
*
* \param sharedSecret
* The pointer to store the generated shared Secret.
*
* \return status code. See \ref cy_en_cryptolite_status_t.
*
****************************************************************************/
cy_en_cryptolite_status_t Cy_Cryptolite_ECC_SharedSecret(CRYPTOLITE_Type *base,
                            cy_stc_cryptolite_context_ecdsa_t *cfContext,
                            cy_en_cryptolite_ecc_curve_id_t curveID,const uint8_t *privateKey,
                            const cy_stc_cryptolite_ecc_key *key,
                            uint8_t const *sharedSecret)
{

    cy_en_cryptolite_status_t result = CY_CRYPTOLITE_BAD_PARAMS;
    const cy_stc_cryptolite_ecc_dp_type *eccDp;

    /* NULL parameters checking */
     if ((base != NULL) && (cfContext != NULL) && (privateKey != NULL) && (key != NULL) &&
        (key->pubkey.x != NULL) && (key->pubkey.y != NULL) && (sharedSecret != NULL))
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
            Cy_Cryptolite_Setnumber(p_gx, (uint8_t *) key->pubkey.x, bytesize);
            Cy_Cryptolite_Setnumber(p_gy, (uint8_t *) key->pubkey.y, bytesize);
            Cy_Cryptolite_Setnumber(p_u1, (uint8_t *)privateKey, bytesize);


            Cy_Cryptolite_EC_NistP_PointMul(base, cfContext, p_gx, p_gy, p_u1, p_o, (int)bitsize);

            Cy_Cryptolite_Setnumber((uint8_t *)sharedSecret, (uint8_t *) p_gx, bytesize);
            result = CY_CRYPTOLITE_SUCCESS;

        }
        else
        {
            result = CY_CRYPTOLITE_NOT_SUPPORTED;
        }
    }
    return result;
}

#if defined(CY_CRYPTOLITE_CFG_ECDSA_SIGN_C)
/*******************************************************************************
* Function Name: Cy_Cryptolite_ECC_SignHash
****************************************************************************//*
*
* Function to generate an ECC signature.
* key, hash and messageKey must be in little endian.
* Cy_Cryptolite_InvertEndianness() function is used for converting the endianness.
*
* \param base
* The pointer to a Cryptolite instance.
*
* \param cfContext
* The pointer to the cy_stc_cryptolite_context_ecdsa_t.
*
* \param hash
* The hash (message digest) to be signed.
*
* \param hashlen
* The length of the hash (octets).
*
* \param sig
* The pointer to the buffer to store the generated signature 'R' followed by 'S'.
*
* \param key
* The  private ECC key to sign the hash. See \ref cy_stc_cryptolite_ecc_key.
*
* \param messageKey
* The random number for generating the signature.
*
* \return status code. See \ref cy_en_cryptolite_status_t.
*
*******************************************************************************/
cy_en_cryptolite_status_t Cy_Cryptolite_ECC_SignHash(CRYPTOLITE_Type *base,
cy_stc_cryptolite_context_ecdsa_t *cfContext, const uint8_t *hash, uint32_t hashlen, uint8_t *sig,
        const cy_stc_cryptolite_ecc_key *key, const uint8_t *messageKey)
{
    cy_en_cryptolite_status_t result = CY_CRYPTOLITE_BAD_PARAMS;
    const cy_stc_cryptolite_ecc_dp_type *eccDp;

    /* NULL parameters checking */
    if ((base != NULL) && (sig != NULL) && (hash != NULL) && (0u != hashlen) && (key != NULL) && (messageKey != NULL))
    {
        cy_stc_cryptolite_descr_t *vu_struct0 = &cfContext->vu_desptr[0];
        cy_stc_cryptolite_descr_t *vu_struct1 = &cfContext->vu_desptr[1];

        result = CY_CRYPTOLITE_NOT_SUPPORTED;
        eccDp = Cy_Cryptolite_ECC_GetCurveParams(key->curveID);

        if (eccDp != NULL)
        {
            uint8_t *p_r = cfContext->p_r;
            uint8_t *p_s = cfContext->p_s;
            uint8_t *p_u1 = cfContext->p_u1;
            uint8_t *p_u2 = cfContext->p_u2;
            uint8_t *my_P = cfContext->my_P;
            uint8_t *my_BARRETT_U = cfContext->my_BARRETT_U;
            uint32_t bytesize = VU_BITS_TO_BYTES(eccDp->size);
            uint32_t bitsize  = eccDp->size;
            CY_ALIGN(4) uint8_t temp[VU_BITS_TO_BYTES(VU_TEST_EQUAL_LESS_SIZE+1U)]={0};
            cy_stc_cryptolite_ecc_key publicKey;
            uint8_t pubkey[128];

            publicKey.pubkey.x = pubkey;
            publicKey.pubkey.y = &pubkey[bytesize];

            //Generate the public key
            result = Cy_Cryptolite_ECC_MakePublicKey(base, cfContext, key->curveID,  //(x1, y1) = k * G.
                messageKey, &publicKey);

            if(CY_CRYPTOLITE_SUCCESS != result)
            {
                return result;
            }

            // load prime, order and barrett coefficient
            Cy_Cryptolite_Setnumber(my_P, (uint8_t *) eccDp->order, bytesize);
            Cy_Cryptolite_Setnumber(my_BARRETT_U, (uint8_t *) eccDp->barrett_o, VU_BITS_TO_BYTES(bitsize+1U));

            Cy_Cryptolite_Setnumber(p_r, (uint8_t *)publicKey.pubkey.x, bytesize);

            if (Cy_Cryptolite_Vu_test_zero(base, vu_struct0, p_r, (uint16_t)bitsize) == true)
            {
                return CY_CRYPTOLITE_BAD_PARAMS;
            }

            // Setting the R component of the signature  // r = x1
            if (Cy_Cryptolite_Vu_test_less_than(base, vu_struct1, p_r, my_P, (uint16_t)bitsize) == false)
            {
                (void)Cy_Cryptolite_Vu_mov_hw (base, vu_struct0, temp, VU_BITS_TO_WORDS(bitsize+1U), p_r, VU_BITS_TO_WORDS(bitsize));
                Cy_Cryptolite_EC_Bar_MulRed( base, cfContext, p_r, temp, bitsize);
                if (Cy_Cryptolite_Vu_test_zero(base, vu_struct0, p_r, (uint16_t)bitsize) == true)
                {
                    return CY_CRYPTOLITE_BAD_PARAMS;
                }
                Cy_Cryptolite_Setnumber(sig, (uint8_t *)p_r, bytesize);
            }
            else
            {
                Cy_Cryptolite_Setnumber(sig, (uint8_t *)publicKey.pubkey.x, bytesize);
            }

            // d*r mod n
            Cy_Cryptolite_Setnumber(p_u2, (uint8_t *)key->k, bytesize);
            Cy_Cryptolite_EC_MulMod(base, cfContext, p_s, p_u2, p_r, (int)bitsize);

            // load message hash, truncate it if needed
            Cy_Cryptolite_Vu_wait_hw(base);
            Cy_Cryptolite_Vu_clr(p_u1, VU_BITS_TO_WORDS(bitsize));
            if (hashlen * 8U > bitsize)
            {
                Cy_Cryptolite_Setnumber(p_u1, (uint8_t *)(&hash[hashlen - CY_CRYPTOLITE_BYTE_SIZE_OF_BITS(bitsize)]), CY_CRYPTOLITE_BYTE_SIZE_OF_BITS(bitsize));
            }
            else
            {
                Cy_Cryptolite_Setnumber(p_u1, (uint8_t *)hash, hashlen);
            }

            // e + d*r mod n
            Cy_Cryptolite_EC_AddMod (base, cfContext, p_s, p_u1, p_s);

            // z = a / b % mod
            Cy_Cryptolite_Vu_wait_hw(base);
            (void)Cy_Cryptolite_Vu_mov_hw (base, vu_struct0, temp, VU_BITS_TO_WORDS(bitsize+1U), p_s, VU_BITS_TO_WORDS(bitsize));

            Cy_Cryptolite_Setnumber(p_u1, (uint8_t *)messageKey, bytesize);

            // (e + d*r)/k  mod n
            Cy_Cryptolite_EC_DivMod(base, cfContext, p_s, temp, p_u1, (int)bitsize);

            if (Cy_Cryptolite_Vu_test_zero(base, vu_struct0, p_s, (uint16_t)bitsize) == true)
            {
                return CY_CRYPTOLITE_BAD_PARAMS;
            }

            Cy_Cryptolite_Setnumber(&sig[bytesize], (uint8_t *)p_s, bytesize);
            result = CY_CRYPTOLITE_SUCCESS;
        }
    }

    return result;
}
#endif

#if defined(CY_CRYPTOLITE_CFG_ECDSA_VERIFY_C)
/*******************************************************************************
* Function Name: Cy_Cryptolite_Core_ECC_VerifyHash
****************************************************************************//*
*
* Verify an ECC signature.
* sig, hash and key must be in little endian.
* Cy_Cryptolite_InvertEndianness() function is used for converting the endianness.
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
* \param siglen
* The length of signature.
*
* \param hash
* The hash (message digest) that was signed.
*
* \param hashlen
* The length of the hash (octets).
*
* \param stat
* Result of signature, 0xAAAAAAAA = invalid, 0x55555555 = valid.
*
* \param key
* The corresponding public ECC key. See \ref cy_stc_cryptolite_ecc_key.
*
* \return status code. See \ref cy_en_cryptolite_status_t.
*
*******************************************************************************/
cy_en_cryptolite_status_t Cy_Cryptolite_ECC_VerifyHash(CRYPTOLITE_Type *base,
                            cy_stc_cryptolite_context_ecdsa_t *cfContext,
                            const uint8_t *sig, uint32_t siglen, const uint8_t *hash, uint32_t hashlen,
                            cy_en_cryptolite_sig_verify_result_t *stat, const cy_stc_cryptolite_ecc_key *key)
{

    cy_en_cryptolite_status_t result = CY_CRYPTOLITE_BAD_PARAMS;
    const cy_stc_cryptolite_ecc_dp_type *eccDp;
    (void)siglen;


    /* NULL parameters checking */
    if ((sig != NULL) && (hash != NULL) && (0u != hashlen) && (stat != NULL) && (key != NULL) && (cfContext != NULL))
    {
        cy_stc_cryptolite_descr_t *vu_struct0 = &cfContext->vu_desptr[0];
        cy_stc_cryptolite_descr_t *vu_struct1 = &cfContext->vu_desptr[1];

        result = CY_CRYPTOLITE_NOT_SUPPORTED;
        eccDp = Cy_Cryptolite_ECC_GetCurveParams(key->curveID);

        if (eccDp != NULL)
        {
            uint8_t *dividend = cfContext->dividend;
            uint8_t *p_r = cfContext->p_r;
            uint8_t *p_s = cfContext->p_s;
            uint8_t *p_u1 = cfContext->p_u1;
            uint8_t *p_u2 = cfContext->p_u2;
            uint8_t *p_o = cfContext->p_o;
            uint8_t *p_gx = cfContext->p_gx;
            uint8_t *p_gy = cfContext->p_gy;
            uint8_t *p_qx = cfContext->p_qx;
            uint8_t *p_qy = cfContext->p_qy;
            uint8_t *my_P = cfContext->my_P;
            uint8_t *my_BARRETT_U = cfContext->my_BARRETT_U;

            uint32_t bitsize  = eccDp->size;
            uint32_t bytesize = VU_BITS_TO_BYTES(eccDp->size);
            bool isHashZero = false;

            *stat = CY_CRYPTOLITE_SIG_INVALID;
            cfContext->bitsize = bitsize;
            /* load values needed for reduction modulo order of the base point */
            Cy_Cryptolite_Setnumber (my_P, (uint8_t *)eccDp->order, VU_BITS_TO_BYTES(bitsize));
            Cy_Cryptolite_Setnumber (my_BARRETT_U, (uint8_t *)eccDp->barrett_o, VU_BITS_TO_BYTES(bitsize+1U));

            /* check that R and S are within the valid range, i.e. 0 < R < n and 0 < S < n */
            Cy_Cryptolite_Setnumber(p_r, (uint8_t *)sig, bytesize);
            Cy_Cryptolite_Setnumber(p_s, (uint8_t *)&sig[VU_BITS_TO_BYTES(bitsize)], bytesize);

            if (Cy_Cryptolite_Vu_test_zero(base, vu_struct0, p_r, (uint16_t)bitsize) == true) {
                return CY_CRYPTOLITE_BAD_PARAMS;
            }
            if (Cy_Cryptolite_Vu_test_less_than(base, vu_struct1, p_r, my_P, (uint16_t)bitsize) == false) {
                return CY_CRYPTOLITE_BAD_PARAMS;
            }
            if (Cy_Cryptolite_Vu_test_zero(base, vu_struct0, p_s, (uint16_t)bitsize) == true) {
                return CY_CRYPTOLITE_BAD_PARAMS;
            }
            if (Cy_Cryptolite_Vu_test_less_than(base, vu_struct1, p_s, my_P, (uint16_t)bitsize) == false) {
                return CY_CRYPTOLITE_BAD_PARAMS;
            }
            // load message hash, truncate it if needed
            Cy_Cryptolite_Vu_wait_hw(base);
            Cy_Cryptolite_Vu_clr(p_u1, VU_BITS_TO_WORDS(bitsize));
            if (hashlen * 8U > bitsize)
            {
                Cy_Cryptolite_Setnumber(p_u1, (uint8_t *)(&hash[hashlen - CY_CRYPTOLITE_BYTE_SIZE_OF_BITS(bitsize)]), CY_CRYPTOLITE_BYTE_SIZE_OF_BITS(bitsize));
            }
            else
            {
                Cy_Cryptolite_Setnumber(p_u1, (uint8_t *)hash, hashlen);
            }
            /* Check if message hash is zero */
            if(Cy_Cryptolite_Vu_test_zero(base, vu_struct1, p_u1, (uint16_t)bitsize))
            {
                isHashZero = true;
            }
            // w = s^-1 mod n
            Cy_Cryptolite_Vu_wait_hw(base);
            Cy_Cryptolite_Vu_clr(dividend, VU_BITS_TO_WORDS(bitsize));
            Cy_Cryptolite_Vu_set_bit(dividend, 0);

            Cy_Cryptolite_EC_DivMod(base, cfContext, p_s, dividend, p_s, (int)bitsize);

            // u1 = e*w mod n
            Cy_Cryptolite_EC_MulMod(base, cfContext, p_u1, p_u1, p_s, (int)bitsize);
            // u2 = r*w mod n
            Cy_Cryptolite_EC_MulMod(base, cfContext, p_u2, p_r, p_s, (int)bitsize);

            //-----------------------------------------------------------------------------
            // Initialize point multiplication
            //
            // load prime, order and barrett coefficient
            Cy_Cryptolite_Setnumber(my_P, (uint8_t *) eccDp->prime, bytesize);
            Cy_Cryptolite_Setnumber(p_o, (uint8_t *) eccDp->order, bytesize);
            Cy_Cryptolite_Setnumber(my_BARRETT_U, (uint8_t *) eccDp->barrett_p, VU_BITS_TO_BYTES(bitsize+1U));
            // load base Point G
            Cy_Cryptolite_Setnumber(p_gx, (uint8_t *) eccDp->Gx, bytesize);
            Cy_Cryptolite_Setnumber(p_gy, (uint8_t *) eccDp->Gy, bytesize);
            // load public key Qa
            Cy_Cryptolite_Setnumber(p_qx, (uint8_t *)key->pubkey.x, bytesize);
            Cy_Cryptolite_Setnumber(p_qy, (uint8_t *)key->pubkey.y, bytesize);
            // u1 * G
            if(!isHashZero)
            {
                Cy_Cryptolite_EC_NistP_PointMul(base, cfContext, p_gx, p_gy, p_u1, p_o, (int)bitsize);
            }

            // reload order since p_o is modified by Crypto_EC_JacobianEcScalarMul_coZ (!!!!)
            Cy_Cryptolite_Setnumber(p_o, (uint8_t *) eccDp->order, bytesize);

            // u2 * Qa
            Cy_Cryptolite_EC_NistP_PointMul(base, cfContext, p_qx, p_qy, p_u2, p_o, (int)bitsize);

            //-----------------------------------------------------------------------------
            // P = u1 * G + u2 * Qa. Only Px is needed

            if(isHashZero)
            {
                /* GECC 3.22 */
                Cy_Cryptolite_Setnumber(p_s, p_qx, bytesize);
            }
            else
            {
                Cy_Cryptolite_EC_SubMod(base, cfContext, dividend, p_qy, p_gy);     // (y2-y1)
                Cy_Cryptolite_EC_SubMod(base, cfContext, p_s, p_qx, p_gx);          // (x2-x1)
                Cy_Cryptolite_EC_DivMod(base, cfContext, p_s, dividend, p_s, (int)bitsize);  // s = (y2-y1)/(x2-x1)

                Cy_Cryptolite_EC_SquareMod(base, cfContext, p_s, p_s, (int)bitsize);     // s^2
                Cy_Cryptolite_EC_SubMod(base, cfContext, p_s, p_s, p_gx);           // s^2 - x1
                Cy_Cryptolite_EC_SubMod(base, cfContext, p_s, p_s, p_qx);           // s^2 - x1 - x2 which is Px mod n
            }

            if (Cy_Cryptolite_Vu_test_equal(base, vu_struct0, p_s, p_r, (uint16_t)bitsize))
            {
                *stat = CY_CRYPTOLITE_SIG_VALID;
            }
            else
            {
                *stat = CY_CRYPTOLITE_SIG_INVALID;
            }

            result = CY_CRYPTOLITE_SUCCESS;
        }
    }
    return result;
}
#endif

#endif /*#if (CY_CRYPTOLITE_CFG_ECDSA_C)*/
#endif /* #if (CPUSS_CRYPTOLITE_VU == 1) */

#if defined(__cplusplus)
}
#endif

#endif /* CY_IP_MXCRYPTOLITE */
