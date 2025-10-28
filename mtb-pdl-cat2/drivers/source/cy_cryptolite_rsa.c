/***************************************************************************//**
* \file cy_cryptolite_rsa.c
* \version 1.40
*
* \brief
* This file implements various RSA functionalities such as
* calculating Montgomery and Barrett coefficients, performing
* modular exponentiations etc.
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
#include "cy_device.h"

#if (defined(CY_IP_M0S8CRYPTOLITE) && defined (CRYPTOLITE_VU_PRESENT))

#if defined(__cplusplus)
extern "C" {
#endif
#include <string.h>
#include "cy_cryptolite_rsa.h"
#include "cy_cryptolite_vu.h"
#include "cy_cryptolite_sha.h"

/*******************************************************************************
* Function Name: Cy_Cryptolite_Rsa_TestEven (for internal use)
****************************************************************************//**
*
* This function checks for Input number is Even or not
*
* \param dataPtr
* The pointer to data structure.
*
* \return
* TRUE  - Input number is Even number \n
* FALSE - Input number is Odd number
*
*******************************************************************************/
ATTRIBUTES_CRYPTOLITE_RSA __STATIC_FORCEINLINE bool Cy_Cryptolite_Rsa_TestEven (uint8_t* dataPtr)
{
    uint32_t* dataPtrUint32 = (uint32_t *)(void *)dataPtr;
    uint32_t  word  = *dataPtrUint32;

    return ((word & 1UL) == 0UL);
}

/*******************************************************************************
* Function Name: Cy_Cryptolite_Rsa_ClrBit (for internal use)
****************************************************************************//**
*
* This function clears the bit at given bit position in data structure.
*
* \param dataPtr
* The pointer to data structure.
*
* \param bitPos
* Bit position to be cleared in the given data structure.
*
* \return
* None
*
*******************************************************************************/
ATTRIBUTES_CRYPTOLITE_RSA __STATIC_FORCEINLINE void Cy_Cryptolite_Rsa_ClrBit (uint8_t* dataPtr, uint32_t bitPos)
{
    uint32_t byteOffset = bitPos >> 3UL;
    uint32_t bitOffset  = bitPos & 7UL;

    dataPtr[byteOffset] = dataPtr[byteOffset] & ((uint8_t)~(1UL << bitOffset));
}

/*******************************************************************************
* Function Name: Cy_Cryptolite_Rsa_SetBit (for internal use)
****************************************************************************//**
*
* This function sets the bit at given bit position in data structure.
*
* \param dataPtr
* The pointer to data structure.
*
* \param bitPos
* Bit position to be set in the given data structure.
*
* \return
* None
*
*******************************************************************************/
ATTRIBUTES_CRYPTOLITE_RSA __STATIC_FORCEINLINE void Cy_Cryptolite_Rsa_SetBit (uint8_t* dataPtr, uint32_t bitPos)
{
    uint32_t byteOffset = bitPos >> 3UL;
    uint32_t bitOffset  = bitPos & 7UL;

    dataPtr[byteOffset] = dataPtr[byteOffset] | ((uint8_t)(1UL << bitOffset));
}

/*******************************************************************************
* Function Name: Cy_Cryptolite_Rsa_GetBit (for internal use)
****************************************************************************//**
*
* This function gets the bit value at given bit position in data structure.
*
* \param dataPtr
* The pointer to data structure.
*
* \param bitPos
* Bit position for which the value need to be returned from the given data structure.
*
* \return
* uint32_t bit value either 0 or 1.
*
*******************************************************************************/
ATTRIBUTES_CRYPTOLITE_RSA __STATIC_FORCEINLINE uint32_t Cy_Cryptolite_Rsa_GetBit (uint8_t* dataPtr, uint32_t bitPos)
{
    uint32_t byteOffset = bitPos >> 3UL;
    uint32_t bitOffset  = bitPos & 7UL;

    return (((uint32_t)dataPtr[byteOffset] >> bitOffset) & 1UL);
}

/*******************************************************************************
* Function Name: Cy_Cryptolite_Rsa_Lsl (for internal use)
****************************************************************************//**
*
* This function logical shift left (LSL) operation.
*
* \param dataOutputPtr
* The pointer to output array.
*
* \param outputSize
* Size of the output array.
*
* \param dataInputPtr
* The pointer to input array.
*
* \param bitShift
* No of bits to be shifted in the given data structure.
*
* \return
* None
*
*******************************************************************************/
ATTRIBUTES_CRYPTOLITE_RSA static void Cy_Cryptolite_Rsa_Lsl (uint8_t* dataOutputPtr, uint32_t outputSize, uint8_t* dataInputPtr, uint32_t bitShift)
{
    uint32_t  wordShift            = bitShift >> 5UL;
    uint32_t  bitOffset            = bitShift & 31UL;
    uint32_t* dataOutputPtrUint32  = (uint32_t *) (void *)dataOutputPtr;
    uint32_t* dataInputPtrUint32   = (uint32_t *) (void *)dataInputPtr;
    uint32_t  saved = 0UL;
    uint32_t  word;

    while (dataOutputPtrUint32 < (((uint32_t *) (void *)dataOutputPtr) + wordShift))
    {
        *dataOutputPtrUint32++ = 0UL;
    }

    while (dataOutputPtrUint32 < (((uint32_t *) (void *)dataOutputPtr) + outputSize))
    {
        word = *dataInputPtrUint32++;
        *dataOutputPtrUint32++ = (word <<  bitOffset) | saved;
        saved = (word >> (32UL - wordShift));
    }
}

#if (!CY_CRYPTOLITE_RSA_PRE_CALC_COEFF_ENABLE)
/*******************************************************************************
* Function Name: Cy_Cryptolite_Rsa_Clr (for internal use)
****************************************************************************//**
*
* This function is used to clear the input data of given size.
*
* \param dataPtr
* The pointer to data structure.
*
* \param dataSize
* Size of data to be cleared in 32bit word in the given data structure.
*
* \return
* None
*
*******************************************************************************/
ATTRIBUTES_CRYPTOLITE_RSA static void Cy_Cryptolite_Rsa_Clr (uint8_t* dataPtr, uint32_t dataSize)
{
    uint32_t* dataPtrUint32 = (uint32_t *) (void *)dataPtr;
    uint32_t  i = 0UL;

    do
    {
        *dataPtrUint32++ = 0UL;
        i++;
    } while (i < dataSize);
}
#endif /*(!CY_CRYPTOLITE_RSA_PRE_CALC_COEFF_ENABLE) */

/*******************************************************************************
* Function Name: Cy_Cryptolite_Rsa_MontInvTransform (for internal use)
****************************************************************************//**
*
* This function transforms from Montgomery domain back to regular domain.
*
* \param base
* Cryptolite Base address.
*
* \param rsaSignaturePtr
* Pointer to RSA signature.
*
* \param p_t1_2n1
* Pointer to internal buffer.
*
* \param p_t2_2n1
* Pointer to internal buffer.
*
* \param key
* Pointer to Public key and RSA coefficients.
*
* \return
* None
*
*******************************************************************************/
ATTRIBUTES_CRYPTOLITE_RSA static void Cy_Cryptolite_Rsa_MontInvTransform (
    CRYPTOLITE_Type *base,
    uint8_t* rsaSignaturePtr,
    uint8_t* p_t1_2n1,
    uint8_t* p_t2_2n1,
    cy_stc_cryptolite_rsa_pub_key_t *key
)
{
    uint32_t bitSize = key->moduloLength;

    Cy_Cryptolite_Vu_Mul_Hw (base, rsaSignaturePtr, VU_BITS_TO_WORDS(bitSize), key->inverseModuloPtr, VU_BITS_TO_WORDS(bitSize), p_t1_2n1, VU_BITS_TO_WORDS(2UL*bitSize));
    Cy_Cryptolite_Vu_WaitForComplete (base);
    Cy_Cryptolite_Vu_Lsr_Hw (base, p_t1_2n1, VU_BITS_TO_WORDS(2UL*bitSize), bitSize, rsaSignaturePtr, VU_BITS_TO_WORDS(bitSize));
    Cy_Cryptolite_Vu_WaitForComplete (base);
    Cy_Cryptolite_Vu_Mul_Hw (base, rsaSignaturePtr, VU_BITS_TO_WORDS(bitSize), key->barretCoefPtr, VU_BITS_TO_WORDS(bitSize+1UL), p_t2_2n1, VU_BITS_TO_WORDS(2UL*bitSize));
    Cy_Cryptolite_Vu_WaitForComplete (base);
    Cy_Cryptolite_Vu_Lsr_Hw (base, p_t2_2n1, VU_BITS_TO_WORDS(2UL*bitSize), bitSize, rsaSignaturePtr, VU_BITS_TO_WORDS(bitSize));
    Cy_Cryptolite_Vu_WaitForComplete (base);
    Cy_Cryptolite_Vu_Mul_Hw (base, rsaSignaturePtr, VU_BITS_TO_WORDS(bitSize), key->moduloPtr, VU_BITS_TO_WORDS(bitSize), p_t2_2n1, VU_BITS_TO_WORDS(2UL*bitSize));
    Cy_Cryptolite_Vu_WaitForComplete (base);
    Cy_Cryptolite_Vu_Sub_Hw (base, p_t1_2n1, VU_BITS_TO_WORDS(bitSize+2UL), p_t2_2n1, VU_BITS_TO_WORDS(bitSize+2UL), p_t1_2n1, VU_BITS_TO_WORDS(bitSize+2UL));
    Cy_Cryptolite_Vu_WaitForComplete (base);
    /* Reduction. */
    Cy_Cryptolite_Vu_Cond_Sub_Hw (base, p_t1_2n1, VU_BITS_TO_WORDS(bitSize+2UL), key->moduloPtr, VU_BITS_TO_WORDS(bitSize), p_t2_2n1, VU_BITS_TO_WORDS(bitSize+1UL));
    Cy_Cryptolite_Vu_WaitForComplete (base);
    Cy_Cryptolite_Vu_Cond_Sub_Hw (base, p_t2_2n1, VU_BITS_TO_WORDS(bitSize+1UL), key->moduloPtr, VU_BITS_TO_WORDS(bitSize), rsaSignaturePtr, VU_BITS_TO_WORDS(bitSize));
    Cy_Cryptolite_Vu_WaitForComplete (base);
}

/*******************************************************************************
* Function Name: Cy_Cryptolite_Rsa_MontTransform (for internal use)
****************************************************************************//**
*
* This function performs transformation into Montgomery domain.
*
* \param base
* Cryptolite Base address.
*
* \param rsaSignaturePtr
* Pointer to RSA signature.
*
* \param p_t1_2n1
* Pointer to internal buffer.
*
* \param p_t2_2n1
* Pointer to internal buffer.
*
* \param key
* Pointer to Public key and RSA coefficients.
*
* \return
* None
*
*******************************************************************************/
ATTRIBUTES_CRYPTOLITE_RSA static void Cy_Cryptolite_Rsa_MontTransform (
    CRYPTOLITE_Type *base,
    uint8_t* rsaSignaturePtr,
    uint8_t* p_t1_2n1,
    uint8_t* p_t2_2n1,
    cy_stc_cryptolite_rsa_pub_key_t *key
)
{
    uint32_t bitSize = key->moduloLength;

    Cy_Cryptolite_Rsa_Lsl (p_t1_2n1, VU_BITS_TO_WORDS(2UL*bitSize), rsaSignaturePtr, bitSize);

    Cy_Cryptolite_Vu_Mul_Hw (base, rsaSignaturePtr, VU_BITS_TO_WORDS(bitSize), key->barretCoefPtr, VU_BITS_TO_WORDS(bitSize+1UL), p_t2_2n1, VU_BITS_TO_WORDS(2UL*bitSize));
    Cy_Cryptolite_Vu_WaitForComplete (base);
    Cy_Cryptolite_Vu_Lsr_Hw (base, p_t2_2n1, VU_BITS_TO_WORDS(2UL*bitSize), bitSize, rsaSignaturePtr, VU_BITS_TO_WORDS(bitSize));
    Cy_Cryptolite_Vu_WaitForComplete (base);
    Cy_Cryptolite_Vu_Mul_Hw (base, rsaSignaturePtr, VU_BITS_TO_WORDS(bitSize), key->moduloPtr, VU_BITS_TO_WORDS(bitSize), p_t2_2n1, VU_BITS_TO_WORDS(2UL*bitSize));
    Cy_Cryptolite_Vu_WaitForComplete (base);
    Cy_Cryptolite_Vu_Sub_Hw (base, p_t1_2n1, VU_BITS_TO_WORDS(bitSize+2UL), p_t2_2n1, VU_BITS_TO_WORDS(bitSize+2UL), p_t1_2n1, VU_BITS_TO_WORDS(bitSize+2UL));
    Cy_Cryptolite_Vu_WaitForComplete (base);
    /* Reduction. */
    Cy_Cryptolite_Vu_Cond_Sub_Hw (base, p_t1_2n1, VU_BITS_TO_WORDS(bitSize+2UL), key->moduloPtr, VU_BITS_TO_WORDS(bitSize), p_t2_2n1, VU_BITS_TO_WORDS(bitSize+1UL));
    Cy_Cryptolite_Vu_WaitForComplete (base);
    Cy_Cryptolite_Vu_Cond_Sub_Hw (base, p_t2_2n1, VU_BITS_TO_WORDS(bitSize+1UL), key->moduloPtr, VU_BITS_TO_WORDS(bitSize), rsaSignaturePtr, VU_BITS_TO_WORDS(bitSize));
    Cy_Cryptolite_Vu_WaitForComplete (base);
}

/*******************************************************************************
* Function Name: Cy_Cryptolite_Rsa_MontMul (for internal use)
****************************************************************************//**
*
* This function performs Multiplications in Montgomery domain.
*
* \param base
* Cryptolite Base address.
*
* \param destPtr
* Pointer to destination data structure.
*
* \param srcPtr1
* Pointer to source data structure.
*
* \param srcPtr2
* Pointer to source data structure.
*
* \param p_t1_2n1
* Pointer to internal buffer.
*
* \param p_t2_2n1
* Pointer to internal buffer.
*
* \param key
* Pointer to Public key and RSA coefficients.
*
* \return
* None
*
*******************************************************************************/
ATTRIBUTES_CRYPTOLITE_RSA static void Cy_Cryptolite_Rsa_MontMul (
    CRYPTOLITE_Type *base,
    uint8_t* destPtr,
    uint8_t* srcPtr1,
    uint8_t* srcPtr2,
    uint8_t* p_t1_2n1,
    uint8_t* p_t2_2n1,
    cy_stc_cryptolite_rsa_pub_key_t *key
)
{
    uint32_t bitSize = key->moduloLength;

    Cy_Cryptolite_Vu_Mul_Hw (base, srcPtr1, VU_BITS_TO_WORDS(bitSize), srcPtr2, VU_BITS_TO_WORDS(bitSize), p_t1_2n1, VU_BITS_TO_WORDS(2UL*bitSize));
    Cy_Cryptolite_Vu_WaitForComplete (base);
    Cy_Cryptolite_Vu_Mul_Hw (base, p_t1_2n1, VU_BITS_TO_WORDS(bitSize), key->rBarPtr, VU_BITS_TO_WORDS(bitSize), destPtr, VU_BITS_TO_WORDS(bitSize));
    Cy_Cryptolite_Vu_WaitForComplete (base);
    Cy_Cryptolite_Vu_Mul_Hw (base, destPtr, VU_BITS_TO_WORDS(bitSize), key->moduloPtr, VU_BITS_TO_WORDS(bitSize), p_t2_2n1, VU_BITS_TO_WORDS(2UL*bitSize));
    Cy_Cryptolite_Vu_WaitForComplete (base);
    Cy_Cryptolite_Vu_Add_Hw (base, p_t2_2n1, VU_BITS_TO_WORDS(2UL*bitSize), p_t1_2n1, VU_BITS_TO_WORDS(2UL*bitSize), p_t1_2n1, VU_BITS_TO_WORDS(2UL*bitSize+1UL));
    Cy_Cryptolite_Vu_WaitForComplete (base);
    /* Reduction */
    Cy_Cryptolite_Vu_Cond_Sub_Hw (base, &(p_t1_2n1[VU_BITS_TO_BYTES(bitSize)]), VU_BITS_TO_WORDS(bitSize+1UL), key->moduloPtr, VU_BITS_TO_WORDS(bitSize), destPtr, VU_BITS_TO_WORDS(bitSize));
    Cy_Cryptolite_Vu_WaitForComplete (base);
}

/*******************************************************************************
* Function Name: Cy_Cryptolite_Rsa_Exp (for internal use)
****************************************************************************//**
*
* This function perform modular exponentiation using coefficients.
*
* \param base
* Cryptolite Base address.
*
* \param processedDigestPtr
* Pointer to store decrypted digest data.
*
* \param rsaSignaturePtr
* Pointer to RSA signature.
*
* \param key
* Pointer to Public key and RSA coefficients.
*
* \return
* None
*
*******************************************************************************/
ATTRIBUTES_CRYPTOLITE_RSA static void Cy_Cryptolite_Rsa_Exp ( CRYPTOLITE_Type *base, uint8_t* processedDigestPtr,
                                    uint8_t* rsaSignaturePtr, cy_stc_cryptolite_rsa_pub_key_t *key)
{
    int         idx;
    uint8_t*    p;
    uint32_t    bitSize = key->moduloLength;
    uint32_t    expBitSize = key->pubExpLength;
    uint8_t*    localDigestPtr = processedDigestPtr;
    uint8_t*    p_t1_2n1  = &key->privateBuffer[0UL];
    uint8_t*    p_t2_2n1  = &key->privateBuffer[4UL*VU_BITS_TO_WORDS(2UL*bitSize+1UL)];
    uint8_t*    p_t3_n    = &key->privateBuffer[4UL*VU_BITS_TO_WORDS(2UL*bitSize+1UL) + 4UL*VU_BITS_TO_WORDS(2UL*bitSize+1UL)];

    /* Converting RSA Signature to Montgomery domain. */
    Cy_Cryptolite_Rsa_MontTransform (base, rsaSignaturePtr, p_t1_2n1, p_t2_2n1, key);

    /* Copying Converted RSA signature to output digest buffer. */
    Cy_Cryptolite_Vu_Mov_Hw (base, rsaSignaturePtr, VU_BITS_TO_WORDS(bitSize), processedDigestPtr, VU_BITS_TO_WORDS(bitSize));
    Cy_Cryptolite_Vu_WaitForComplete (base);

    if (expBitSize != 1UL)
    {
        for (idx = ((int)expBitSize-2); idx >= 0; idx--)
        {
            /* SHA digest extraction using Montgomery multiplications using public key and RSA signature. */
            Cy_Cryptolite_Rsa_MontMul (base, p_t3_n, processedDigestPtr, processedDigestPtr, p_t1_2n1, p_t2_2n1, key);

            if (0UL != Cy_Cryptolite_Rsa_GetBit (key->pubExpPtr, (uint32_t)idx))
            {
                Cy_Cryptolite_Rsa_MontMul (base, processedDigestPtr, p_t3_n, rsaSignaturePtr, p_t1_2n1, p_t2_2n1, key);
            }
            else
            {
                /* Update the processed digest pointer location. */
                p = p_t3_n; p_t3_n = processedDigestPtr; processedDigestPtr = p;
            }
        }

        /* If Montgomery based RSA signature pointer (processed digest pointer) is updated to new location
         * in previous operations, copy the updated data to local digest pointer.
         */
        if (localDigestPtr != processedDigestPtr)
        {
            Cy_Cryptolite_Vu_Mov_Hw (base, processedDigestPtr, VU_BITS_TO_WORDS(bitSize), localDigestPtr, VU_BITS_TO_WORDS(bitSize));
            Cy_Cryptolite_Vu_WaitForComplete (base);
        }
    }

    /* Converting extracted SHA digest from Montgomery domain to normal domain */
    Cy_Cryptolite_Rsa_MontInvTransform (base, localDigestPtr, p_t1_2n1, p_t2_2n1, key);
}
#if (!CY_CRYPTOLITE_RSA_PRE_CALC_COEFF_ENABLE)
/*******************************************************************************
* Function Name: Cy_Cryptolite_Rsa_Coeff (for internal use)
****************************************************************************//**
*
* This function is used to calculate Montgomery and Barrett coefficients.
*
* \param base
* Cryptolite Base address.
*
* \param key
* Pointer to Public key and RSA coefficients.
*
* \return
* None
*
*******************************************************************************/
ATTRIBUTES_CRYPTOLITE_RSA void Cy_Cryptolite_Rsa_Coeff (CRYPTOLITE_Type *base, cy_stc_cryptolite_rsa_pub_key_t *key)
{
    int         idx;
    uint8_t*    p;
    uint32_t    bitSize = key->moduloLength;
    uint8_t*    p_t1_n1    = &key->privateBuffer[0UL];
    uint8_t*    p_t2_n1    = &key->privateBuffer[4UL*VU_BITS_TO_WORDS(bitSize+1UL)];
    uint8_t*    p_dividend = p_t1_n1;
    uint32_t    sign;
    bool        even;

    Cy_Cryptolite_Rsa_Clr (p_dividend, VU_BITS_TO_WORDS(bitSize+1UL));
    Cy_Cryptolite_Rsa_SetBit (p_dividend, bitSize);
    Cy_Cryptolite_Rsa_Clr (key->barretCoefPtr, VU_BITS_TO_WORDS(bitSize+1UL));
    Cy_Cryptolite_Rsa_Clr (key->inverseModuloPtr, VU_BITS_TO_WORDS(bitSize+1UL));
    Cy_Cryptolite_Rsa_SetBit (key->inverseModuloPtr, 0UL);
    Cy_Cryptolite_Rsa_Clr (key->rBarPtr, VU_BITS_TO_WORDS(bitSize));
    Cy_Cryptolite_Vu_Sub_Hw (base, p_dividend, VU_BITS_TO_WORDS(bitSize+1UL), key->moduloPtr, VU_BITS_TO_WORDS(bitSize), p_dividend, VU_BITS_TO_WORDS(bitSize+1UL));
    Cy_Cryptolite_Vu_WaitForComplete (base);
    Cy_Cryptolite_Rsa_SetBit (key->barretCoefPtr, bitSize);
    /* Drop top bit */
    Cy_Cryptolite_Rsa_ClrBit (p_dividend, bitSize);
    Cy_Cryptolite_Vu_Lsl1_Hw (base, p_dividend, VU_BITS_TO_WORDS(bitSize+1UL), p_dividend, VU_BITS_TO_WORDS(bitSize+1UL));
    Cy_Cryptolite_Vu_WaitForComplete (base);
    for (idx = ((int)bitSize-1); idx >= 0; idx--)
    {
        Cy_Cryptolite_Vu_Sub_Hw (base, p_dividend, VU_BITS_TO_WORDS(bitSize+1UL), key->moduloPtr, VU_BITS_TO_WORDS(bitSize), p_t2_n1, VU_BITS_TO_WORDS(bitSize+1UL));
        Cy_Cryptolite_Vu_WaitForComplete (base);
        Cy_Cryptolite_Vu_Lsr1_Hw (base, key->rBarPtr, VU_BITS_TO_WORDS(bitSize), key->rBarPtr, VU_BITS_TO_WORDS(bitSize));
        Cy_Cryptolite_Vu_WaitForComplete (base);
        even = Cy_Cryptolite_Rsa_TestEven (key->inverseModuloPtr);
        if (even)
        {
            Cy_Cryptolite_Vu_Lsr1_Hw (base, key->inverseModuloPtr, VU_BITS_TO_WORDS(bitSize), key->inverseModuloPtr, VU_BITS_TO_WORDS(bitSize));
            Cy_Cryptolite_Vu_WaitForComplete (base);
        }
        else
        {
            Cy_Cryptolite_Vu_Add_Hw (base, key->inverseModuloPtr, VU_BITS_TO_WORDS(bitSize), key->moduloPtr, VU_BITS_TO_WORDS(bitSize), key->inverseModuloPtr,  VU_BITS_TO_WORDS(bitSize+1UL));
            Cy_Cryptolite_Vu_WaitForComplete (base);
            Cy_Cryptolite_Vu_Lsr1_Hw (base, key->inverseModuloPtr, VU_BITS_TO_WORDS(bitSize+1UL), key->inverseModuloPtr, VU_BITS_TO_WORDS(bitSize+1UL));
            Cy_Cryptolite_Vu_WaitForComplete (base);
            Cy_Cryptolite_Rsa_SetBit (key->rBarPtr, bitSize-1UL);
        }
        /* sign = (dividend < mod) */
        sign = Cy_Cryptolite_Rsa_GetBit (p_t2_n1, bitSize);
        if (0UL == sign)
        {
            Cy_Cryptolite_Rsa_SetBit (key->barretCoefPtr, (uint32_t)idx);
            p = p_t2_n1; p_t2_n1 = p_dividend; p_dividend = p;
        }
        /* Drop top bit */
        Cy_Cryptolite_Rsa_ClrBit (p_dividend, bitSize);
        Cy_Cryptolite_Vu_Lsl1_Hw (base, p_dividend, VU_BITS_TO_WORDS(bitSize+1UL), p_dividend, VU_BITS_TO_WORDS(bitSize+1UL));
        Cy_Cryptolite_Vu_WaitForComplete (base);
    }
}
#endif /*(!CY_CRYPTOLITE_RSA_PRE_CALC_COEFF_ENABLE) */


/*******************************************************************************
* Function Name: Cy_Cryptolite_Rsa_ChangeEndian
********************************************************************************
*
* This function is used to change the endian order of the given order.
*
* \param ptrData
* data buffer which requires endian order change.
*
* \param size
* data length.
*
* \param ptrTempBuf
* Temporary buffer to be used to change the endian order.
*
* \return
* None
*******************************************************************************/
ATTRIBUTES_CRYPTOLITE_RSA static void Cy_Cryptolite_Rsa_ChangeEndian(uint8_t *ptrData, uint32_t size, uint8_t *ptrTempBuf)
{
    uint32_t index = 0u;

    (void)memset(ptrTempBuf, 0x00, size);
    /* Copy data in reverse order from ptrData. */
    for(index = 0u; index < size; index++)
    {
        ptrTempBuf[index] = ptrData[size - 1u - index];
    }

    /* Copy back the reversed data to source. */
    for(index = 0u; index < size; index++)
    {
        ptrData[index] = ptrTempBuf[index];
    }
}

/*******************************************************************************
* Function Name: Cy_Cryptolite_Rsa_MgfMask
********************************************************************************
*
* Generate and apply the MGF1 operation (from PKCS#1 v2.1) to a buffer.
*
* \param base
* cryptolite base address.
*
* \param dst
* buffer to mask (destination buffer).
*
* \param dlen
* length of destination buffer.
*
* \param src
* source of the mask generation.
*
* \param slen
* length of the source buffer.
*
* \param shaMode
* SHA selection mode(SHA256, SHA384, SHA512).
*
* \param digestLength
* digest length for given SHA mode.
*
* \param ptrIntBuf
* Internal buffer pointer.
*
* \return
* cy_en_cryptolite_status_t Cryptolite operation status
*******************************************************************************/
ATTRIBUTES_CRYPTOLITE_RSA static cy_en_cryptolite_status_t Cy_Cryptolite_Rsa_MgfMask(
                        CRYPTOLITE_Type *base,
                        uint8_t *dst, int32_t dlen,
                        uint8_t *src, int32_t slen,
                        cy_en_cryptolite_sha_mode_t shaMode,
                        int32_t digestLength, uint8_t *ptrIntBuf
#if SW_HASHING_ALG
                        ,cy_stc_cryptolite_rsa_sw_sha_cbk_t *ptrSwShaCbk
#endif /* SW_HASHING_ALG */
                        )
{
    uint8_t counter[4] = {0u};
    uint8_t *ptrBuf;
    int32_t index, useLength;
    cy_en_cryptolite_status_t cryptoStatus = CY_CRYPTOLITE_UNKNOWN;
#if !SW_HASHING_ALG
    /* Coverity warning deviation. */
    CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 11.3', 1, 'Intentional type conversion.');
    cy_stc_cryptolite_sha_context_t *ptrShaContext = (cy_stc_cryptolite_sha_context_t *)ptrIntBuf;
    CY_MISRA_BLOCK_END('MISRA C-2012 Rule 11.3');
#endif /* !SW_HASHING_ALG */
    uint8_t mask[CY_CRYPTOLITE_SHA512_HASH_SIZE] = {0u};

    /* Generate and apply dbMask */
    ptrBuf = dst;
    while (dlen > 0)
    {
        /* Update the length to be used for hash calculation. */
        useLength = digestLength;
        /* Check whether remaining destination buffer length is less than actual digest length.
         * Update the useLength with remaining length if it is less than digest length. */
        if (dlen < digestLength)
        {
            useLength = dlen;
        }

#if !SW_HASHING_ALG
        /* Reset the intermediate buffer data to zero. */
        (void)memset((uint8_t *)ptrShaContext, 0x00, sizeof(cy_stc_cryptolite_sha_context_t));

        /* Set SHA mode. */
        cryptoStatus  = CRYPTOLITE_SHA_CALL_MAP(Cy_Cryptolite_Sha_SetMode)(shaMode, ptrShaContext);

        /* SHA block initialization. */
        if(CY_CRYPTOLITE_SUCCESS == cryptoStatus)
        {
            cryptoStatus = CRYPTOLITE_SHA_CALL_MAP(Cy_Cryptolite_Sha_Init) (base, ptrShaContext);
        }

        /* Start SHA calculation process. */
        if(CY_CRYPTOLITE_SUCCESS == cryptoStatus)
        {
            cryptoStatus = CRYPTOLITE_SHA_CALL_MAP(Cy_Cryptolite_Sha_Start) (base, ptrShaContext);
        }

        /* Calculate the hash for source data. */
        if(CY_CRYPTOLITE_SUCCESS == cryptoStatus)
        {
            cryptoStatus = CRYPTOLITE_SHA_CALL_MAP(Cy_Cryptolite_Sha_Update) (base,
                                                                            src,
                                                                            (uint32_t)slen,
                                                                            ptrShaContext);
        }

        /* Calculate the hash for counter data. */
        if(CY_CRYPTOLITE_SUCCESS == cryptoStatus)
        {
            cryptoStatus = CRYPTOLITE_SHA_CALL_MAP(Cy_Cryptolite_Sha_Update) (base,
                                                                            counter,
                                                                            4u,
                                                                            ptrShaContext);
        }

        /* Finish the SHA calculation process. */
        if(CY_CRYPTOLITE_SUCCESS == cryptoStatus)
        {
            cryptoStatus = CRYPTOLITE_SHA_CALL_MAP(Cy_Cryptolite_Sha_Finish) (base, mask,
                                                                            ptrShaContext);
        }
        /* Reset internal buffers in SHA context. */
        if(CY_CRYPTOLITE_SUCCESS == cryptoStatus)
        {
            cryptoStatus = CRYPTOLITE_SHA_CALL_MAP(Cy_Cryptolite_Sha_Free) (base, ptrShaContext);
        }
#else /* SW_HASHING_ALG */
        /* Initialize SHA Block and Start SHA Operation. */
        ptrSwShaCbk->sw_sha_init (ptrIntBuf);

        /* Calculate the hash for source data. */
        ptrSwShaCbk->sw_sha_update (ptrIntBuf, src, (uint32_t)slen);

        /* Calculate the hash for counter data. */
        ptrSwShaCbk->sw_sha_update (ptrIntBuf, counter, 4u);

        /* Finish SHA Calculation process and Reset internal buffers in SHA context. */
        ptrSwShaCbk->sw_sha_finish (ptrIntBuf, mask);

        /* Update Status Variable */
        cryptoStatus = CY_CRYPTOLITE_SUCCESS;
#endif /* !SW_HASHING_ALG */

        /* Update the destination buffer with MGF data. */
        if(CY_CRYPTOLITE_SUCCESS == cryptoStatus)
        {
            for (index = 0; index < useLength; ++index)
            {
                *ptrBuf++ ^= mask[index];
            }

            /* Increment the counter. */
            counter[3]++;
            /* Decrease the destination length by utilized length in previous hash calculation. */
            dlen -= useLength;
        }
        /* Stop the process if Cryptolite operation is failed. */
        else
        {
            break;
        }
    }

    /* Return Cryptolite status */
    return cryptoStatus;
}

/*******************************************************************************
* Function Name: Cy_Cryptolite_Rsa_HashMprime
********************************************************************************
*
* Generate Hash(M') as in RFC 8017 page 43 points 5 and 6.
*
* \param base
* cryptolite base address.
*
* \param hash
* the input hash.
*
* \param hlen
* length of the input hash.
*
* \param salt
* the input salt.
*
* \param slen
* length of the input salt.
*
* \param hashOutput
* output buffer to copy calculated hash value.
*
* \param shaMode
* SHA selection mode(SHA256, SHA384, SHA512).
*
* \param ptrIntBuf
* Internal buffer pointer.
*
* \return
* cy_en_cryptolite_status_t Cryptolite operation status
*******************************************************************************/
ATTRIBUTES_CRYPTOLITE_RSA static cy_en_cryptolite_status_t Cy_Cryptolite_Rsa_HashMprime(
                        CRYPTOLITE_Type *base,
                        const uint8_t *hash, uint32_t hlen,
                        const uint8_t *salt, uint32_t slen,
                        uint8_t *hashOutput, cy_en_cryptolite_sha_mode_t shaMode,
                        uint8_t *ptrIntBuf
#if SW_HASHING_ALG
                        ,cy_stc_cryptolite_rsa_sw_sha_cbk_t *ptrSwShaCbk
#endif /* SW_HASHING_ALG */
                        )
{
    const uint8_t zeros[8] = { 0u };
    cy_en_cryptolite_status_t cryptoStatus;
#if !SW_HASHING_ALG
    /* Coverity warning deviation. */
    CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 11.3', 1, 'Intentional type conversion.');
    cy_stc_cryptolite_sha_context_t *ptrShaContext = (cy_stc_cryptolite_sha_context_t *)ptrIntBuf;
    CY_MISRA_BLOCK_END('MISRA C-2012 Rule 11.3');
    
    /* Reset the intermediate buffer data to zero. */
    (void)memset((uint8_t *)ptrShaContext, 0x00, sizeof(cy_stc_cryptolite_sha_context_t));

    /* Set SHA mode. */
    cryptoStatus  = CRYPTOLITE_SHA_CALL_MAP(Cy_Cryptolite_Sha_SetMode)(shaMode, ptrShaContext);

    /* SHA block initialization. */
    if(CY_CRYPTOLITE_SUCCESS == cryptoStatus)
    {
        cryptoStatus = CRYPTOLITE_SHA_CALL_MAP(Cy_Cryptolite_Sha_Init) (base, ptrShaContext);
    }

    /* Start SHA calculation process. */
    if(CY_CRYPTOLITE_SUCCESS == cryptoStatus)
    {
        cryptoStatus = CRYPTOLITE_SHA_CALL_MAP(Cy_Cryptolite_Sha_Start) (base, ptrShaContext);
    }

    /* Calculate the hash for zero data. */
    if(CY_CRYPTOLITE_SUCCESS == cryptoStatus)
    {
        cryptoStatus = CRYPTOLITE_SHA_CALL_MAP(Cy_Cryptolite_Sha_Update) (base,
                                                                        zeros,
                                                                        (uint32_t)sizeof(zeros),
                                                                        ptrShaContext);
    }
    /* Calculate the hash for hash input data. */
    if(CY_CRYPTOLITE_SUCCESS == cryptoStatus)
    {
        cryptoStatus = CRYPTOLITE_SHA_CALL_MAP(Cy_Cryptolite_Sha_Update) (base,
                                                                        hash,
                                                                        hlen,
                                                                        ptrShaContext);
    }
    /* Calculate the hash for salt. */
    if(CY_CRYPTOLITE_SUCCESS == cryptoStatus)
    {
        cryptoStatus = CRYPTOLITE_SHA_CALL_MAP(Cy_Cryptolite_Sha_Update) (base,
                                                                        salt,
                                                                        slen,
                                                                        ptrShaContext);
    }
    /* Finish the SHA calculation process. */
    if(CY_CRYPTOLITE_SUCCESS == cryptoStatus)
    {
        cryptoStatus = CRYPTOLITE_SHA_CALL_MAP(Cy_Cryptolite_Sha_Finish) (CRYPTOLITE, hashOutput, ptrShaContext);
    }
    
    /* Reset internal buffers in SHA context. */
    if(CY_CRYPTOLITE_SUCCESS == cryptoStatus)
    {
        cryptoStatus = CRYPTOLITE_SHA_CALL_MAP(Cy_Cryptolite_Sha_Free) (CRYPTOLITE, ptrShaContext);
    }
#else /* SW_HASHING_ALG */

    /* Initialize SHA Block and Start SHA Operation. */
    ptrSwShaCbk->sw_sha_init (ptrIntBuf);

    /* Calculate the hash for zero data. */
    ptrSwShaCbk->sw_sha_update (ptrIntBuf, zeros, (uint32_t)sizeof(zeros));

    /* Calculate the hash for hash input data. */
    ptrSwShaCbk->sw_sha_update (ptrIntBuf, hash, hlen);

    /* Calculate the hash for salt. */
    ptrSwShaCbk->sw_sha_update (ptrIntBuf, salt, slen);

    /* Finish SHA Calculation process and Reset internal buffers in SHA context. */
    ptrSwShaCbk->sw_sha_finish (ptrIntBuf, hashOutput);

    /* Update Status Variable */
    cryptoStatus = CY_CRYPTOLITE_SUCCESS;

#endif /* !SW_HASHING_ALG */
    
    /* Return Cryptolite status */
    return cryptoStatus;
}

/*******************************************************************************
* Function Name: Cy_Cryptolite_Rsa_PssVerifyExt
********************************************************************************
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
* digest length for given SHA mode.
*
* \param digest
* digest buffer pointer.
*
* \param rsaLength
* RSA Signature length.
*
* \param key
* Pointer to Public key and RSA coefficients.
*
* \param processedDigest
* Processed RSA signature using public key.
*
* \return
* cy_en_cryptolite_status_t Cryptolite operation status
*******************************************************************************/
ATTRIBUTES_CRYPTOLITE_RSA cy_en_cryptolite_status_t Cy_Cryptolite_Rsa_PssVerifyExt(
        CRYPTOLITE_Type *base,
        uint16_t digestLength,
        uint8_t *digest,
        uint16_t rsaLength,
        cy_stc_cryptolite_rsa_pub_key_t *key,
        uint8_t *processedDigest
    )
{
    uint8_t *ptrBuf;
    uint16_t bitIndex;
    uint8_t *hashStart;
    uint8_t result[CY_CRYPTOLITE_SHA512_HASH_SIZE] = {0u};

    /* Change the endian back to Little-endian. */
    Cy_Cryptolite_Rsa_ChangeEndian(processedDigest, rsaLength, key->privateBuffer);

    /* Assign the RSA verified data to local pointer. */
    ptrBuf = processedDigest;

    /* Verify padding scheme. */
    if (0xBCu != processedDigest[rsaLength - 1u])
    {
        return CY_CRYPTOLITE_RSA_VERIFY_FAILURE;
    }

    /* EMSA-PSS verification is over the length of N - 1 bits */
    bitIndex = (uint16_t)(key->moduloLength - 1u);
    /* Check the non-zero value. */
    if (0u != (processedDigest[0] >> (8u - rsaLength * 8u + bitIndex)))
    {
        return CY_CRYPTOLITE_RSA_VERIFY_FAILURE;
    }
    /* Compensate for boundary condition when applying mask. */
    if (bitIndex % 8u == 0u)
    {
        ptrBuf++;
        rsaLength = rsaLength - 1u;
    }
    /* RSA Length and digest length boundary check. */
    if (rsaLength < (digestLength + 2u))
    {
        return CY_CRYPTOLITE_RSA_VERIFY_FAILURE;
    }

    /* Address of the RSA verified data to be used for MGF. */
    hashStart = ptrBuf + rsaLength - digestLength - 1u;
    /* Coverity warning deviation. */
    CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 10.8', 1, 'Intentional type conversion.');
    /* Generate and Apply MGF1 operation. */
    if(CY_CRYPTOLITE_SUCCESS != Cy_Cryptolite_Rsa_MgfMask(base, ptrBuf, (int32_t)(rsaLength - digestLength - 1u), hashStart,
            (int32_t)digestLength, (cy_en_cryptolite_sha_mode_t)key->shaAlgorithm , (int32_t)digestLength, key->privateBuffer
#if SW_HASHING_ALG
             , key->ptrSwShaCbk
#endif /* SW_HASHING_ALG */
            ))
    {
        return CY_CRYPTOLITE_RSA_VERIFY_FAILURE;
    }
    CY_MISRA_BLOCK_END('MISRA C-2012 Rule 10.8');
    
    processedDigest[0] &= 0xFFu >> (rsaLength * 8u - bitIndex);

    /* Adjust the local pointer to skip zero data. */
    while (ptrBuf < hashStart - 1u && *ptrBuf  == 0u){
        ptrBuf++;
    }

    /* After zero data, the next byte should be 0x01. */
    if (*ptrBuf++ != 0x01u)
    {
        return CY_CRYPTOLITE_RSA_VERIFY_FAILURE;
    }

    /* Determine the observed salt length. Note that current implementation only supports 
     * salt length argument as -1 during RSA signature generation. */
    int32_t observedSaltLen = (hashStart - ptrBuf);
    if (observedSaltLen < 0)
    {
        return CY_CRYPTOLITE_RSA_VERIFY_FAILURE;
    }
    
    /* Generate H = Hash( M' ) */
    if (CY_CRYPTOLITE_SUCCESS != Cy_Cryptolite_Rsa_HashMprime(base, digest, digestLength, ptrBuf, (uint32_t)observedSaltLen,
                      result, (cy_en_cryptolite_sha_mode_t)key->shaAlgorithm, key->privateBuffer
#if SW_HASHING_ALG
                      , key->ptrSwShaCbk
#endif /* SW_HASHING_ALG */
                      ))
    {
        return CY_CRYPTOLITE_RSA_VERIFY_FAILURE;
    }

    if (memcmp(hashStart, result, digestLength) != 0) {
        return CY_CRYPTOLITE_RSA_VERIFY_FAILURE;
    }
    return CY_CRYPTOLITE_SUCCESS;
}

/*
 * This function is called from the boot loader to verify if the given signature
 * matches with the input hash (SHA digest) or not. RSA coefficient are first calculated
 * using public key modulus after which RSA exponentiation is performed.
 * RSA coefficient can be pre-calculated to save time for application validation.
 */
ATTRIBUTES_CRYPTOLITE_RSA cy_en_cryptolite_status_t Cy_Cryptolite_Rsa_Verify (
    CRYPTOLITE_Type *base,
    uint16_t digestLength,
    uint8_t *digest,
    uint8_t *rsaSignature,
    uint16_t rsaLength,
    cy_stc_cryptolite_rsa_pub_key_t *key,
    uint8_t *processedDigest
)
{
    uint32_t index;

    if ((NULL == base) || (NULL == digest) || (NULL == rsaSignature) || (NULL == key) || (NULL == processedDigest)
    #if SW_HASHING_ALG
        || (NULL == key->ptrSwShaCbk)
    #endif /* SW_HASHING_ALG */ 
    )
    {
        return CY_CRYPTOLITE_BAD_PARAMS;
    }

    if ((NULL == key->pubExpPtr) || (NULL == key->barretCoefPtr) || (NULL == key->inverseModuloPtr) ||
        (NULL == key->rBarPtr) || (NULL == key->moduloPtr) || (NULL == key->privateBuffer) ||
        (0UL == key->pubExpLength) || (0UL == key->moduloLength)
#if SW_HASHING_ALG
        || (NULL == key->ptrSwShaCbk->sw_sha_init) || (NULL == key->ptrSwShaCbk->sw_sha_update)
        || (NULL == key->ptrSwShaCbk->sw_sha_finish)
#endif /* SW_HASHING_ALG */
        )
    {
        return CY_CRYPTOLITE_BAD_PARAMS;
    }

    if(VU_BITS_TO_BYTES(key->moduloLength) != rsaLength)
    {
        return  CY_CRYPTOLITE_BAD_PARAMS;
    }

#if (!CY_CRYPTOLITE_RSA_PRE_CALC_COEFF_ENABLE)
    /* Coefficient calculation. */
    if (true == key->calculateCoeff)
    {
        CRYPTOLITE_RSA_CALL_MAP(Cy_Cryptolite_Rsa_Coeff) (base, key);

        /* Set the Coefficients calculated flag to false as coefficients are calculated in previous step. */
        key->calculateCoeff = false;
    }
#endif /* (!CY_CRYPTOLITE_RSA_PRE_CALC_COEFF_ENABLE) */

    /* Modular exponent calculation using coefficients */
    Cy_Cryptolite_Rsa_Exp (base, processedDigest, rsaSignature, key);

#if RSA_PADDING_PKCS1_PSS_SIG_SCHEME
    if ((uint8_t)CY_CRYPTOLITE_RSA_SSA_PSS == key->rsaSigScheme)
    {
        /* Handle rest of PKCS#1 V2.2 implementation. */

        return Cy_Cryptolite_Rsa_PssVerifyExt(base, digestLength, digest,
                    rsaLength, key, processedDigest);
    }
    else
#endif /* RSA_PADDING_PKCS1_PSS_SIG_SCHEME */
    {
        /*
         * Perform digest verification to validate the decrypted digest from RSA signature.
         * The output digest from SHA calculation is in BE format and output digest from
         * RSA decryption is in LE format. Hence, the processed digest is compared in reverse order
         * with input digest.
         */
        for(index = 0UL; index < digestLength; index++)
        {
            if(processedDigest[index] != (digest[digestLength - 1UL - index]))
            {
                return CY_CRYPTOLITE_RSA_VERIFY_FAILURE;
            }
        }
    }
    return CY_CRYPTOLITE_SUCCESS;
}

#if defined(__cplusplus)
}
#endif

#endif /* (defined(CY_IP_M0S8CRYPTOLITE) && defined (CRYPTOLITE_VU_PRESENT)) */


/* [] END OF FILE */
