/***************************************************************************//**
* \file cy_cryptolite_aes.c
* \version 1.40
*
* \brief
* This file provides the source code for the API for the AES method in the 
* Cryptolite driver.
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

#if (defined(CY_IP_M0S8CRYPTOLITE) && defined (CRYPTOLITE_AES_PRESENT))

#include "cy_cryptolite_aes.h"

#if defined(__cplusplus)
extern "C" {
#endif

#include <string.h>

#define CRYPTOLITE_AES_MESSAGE_BLOCK_OFFSET     0x00 /* Beginning of memory buffer. */
#define CRYPTOLITE_AES_KEY_OFFSET               0x04 /* AES key offset in memory buffer in 32-bit words. */
#define CRYPTOLITE_AES_ROUND_KEY_OFFSET         0x0C /* Round key offset in memory buffer in 32-bit words. */
#define CY_CRYPTOLITE_AES_CTR_CNT_POS           12   /* Counter position in the nonce counter buffer used in aes-ctr mode*/

/*******************************************************************************
* Function Name: Cy_Cryptolite_Aes_ProcessBlock
****************************************************************************//**
*
* Performs the AES block cipher.
*
*******************************************************************************/
static cy_en_cryptolite_status_t Cy_Cryptolite_Aes_ProcessBlock(CRYPTOLITE_Type *base,
                                       uint8_t *dstBlock,
                                       uint8_t const *srcBlock,
                                       cy_stc_cryptolite_aes_context_t *aesContext)
{
    /* Wait for Cryptolite IP to be ready */
    if((REG_CRYPTOLITE_STATUS(base) & CRYPTOLITE_STATUS_BUSY_Msk) != 0UL)
    {
        return CY_CRYPTOLITE_HW_BUSY;
    }

    /* Copy message and key to AES descriptor structure */
    aesContext->desc.keyAddr = (uint32_t)aesContext->key;
    aesContext->desc.srcAddr = (uint32_t)srcBlock;
    aesContext->desc.dstAddr = (uint32_t)dstBlock;

    /* Copy descriptor data into crypto memory and start operation*/
    REG_CRYPTOLITE_AES_DESCR(base) = (uint32_t)&(aesContext->desc);

    /* Wait for crypto operation completion. */
    while((REG_CRYPTOLITE_STATUS(base) & CRYPTOLITE_STATUS_BUSY_Msk) != 0UL){}
    if((REG_CRYPTOLITE_INTR_ERROR(base) & CRYPTOLITE_INTR_ERROR_BUS_ERROR_Msk) != 0UL)
    {
        REG_CRYPTOLITE_INTR_ERROR(base) = CRYPTOLITE_INTR_ERROR_BUS_ERROR_Msk;
        return CY_CRYPTOLITE_BUS_ERROR;
    }

    return CY_CRYPTOLITE_SUCCESS;
}


/*******************************************************************************
* Function Name: Cy_Cryptolite_Aes_Init
****************************************************************************//**
*
* Sets AES mode and prepares an inverse key.
*
*******************************************************************************/
cy_en_cryptolite_status_t Cy_Cryptolite_Aes_Init(CRYPTOLITE_Type *base,
                                         uint8_t const *key,
                                         cy_stc_cryptolite_aes_context_t *aesContext)
{
    if (NULL == base || NULL == key || NULL == aesContext)
    {
        return (CY_CRYPTOLITE_BAD_PARAMS);
    }

    (void) memcpy((char *)aesContext->key, (const char *)key, CY_CRYPTOLITE_AES_128_KEY_SIZE);

    return (CY_CRYPTOLITE_SUCCESS);
}

/*******************************************************************************
* Function Name: Cy_Cryptolite_Aes_Free
****************************************************************************//**
*
* Clears AES operation context.
*
*******************************************************************************/
cy_en_cryptolite_status_t Cy_Cryptolite_Aes_Free(CRYPTOLITE_Type *base, cy_stc_cryptolite_aes_context_t *aesContext)
{
    if (NULL == base || NULL == aesContext)
    {
        return (CY_CRYPTOLITE_BAD_PARAMS);
    }

    (void) memset((char *)aesContext, 0, sizeof(cy_stc_cryptolite_aes_context_t));


    return (CY_CRYPTOLITE_SUCCESS);
}

/*******************************************************************************
* Function Name: Cy_Cryptolite_Aes_Ecb
****************************************************************************//**
*
* Performs an AES operation on given input message block.
*
*******************************************************************************/
cy_en_cryptolite_status_t Cy_Cryptolite_Aes_Ecb(CRYPTOLITE_Type *base,
                                        uint8_t *dst,
                                        uint8_t const *src,
                                        uint32_t srcSize,
                                        cy_stc_cryptolite_aes_context_t *aesContext)
{
    uint32_t size = srcSize;
    cy_en_cryptolite_status_t result = CY_CRYPTOLITE_UNKNOWN;

    if (NULL == base || NULL == dst || NULL == src || NULL == aesContext)
    {
        return (CY_CRYPTOLITE_BAD_PARAMS);
    }

    /* Check whether the data size is multiple of CY_CRYPTOLITE_AES_BLOCK_SIZE */
    if (0UL != (uint32_t)(size & (CY_CRYPTOLITE_AES_BLOCK_SIZE - 1U)))
    {
        return (CY_CRYPTOLITE_BAD_PARAMS);
    }

    while (size != 0UL)
    {
        /* Encrypt the AES block */
        result = Cy_Cryptolite_Aes_ProcessBlock(base, dst, src, aesContext);
        if(CY_CRYPTOLITE_SUCCESS != result)
        {
            return result;
        }

        src  += CY_CRYPTOLITE_AES_BLOCK_SIZE;
        dst  += CY_CRYPTOLITE_AES_BLOCK_SIZE;
        size -= CY_CRYPTOLITE_AES_BLOCK_SIZE;
    }

    return result;
}


/*******************************************************************************
* Function Name: Cy_Cryptolite_Aes_Cbc
****************************************************************************//**
*
* Performs AES operation on a plain text with Cipher Block Chaining (CBC) method.
*
*******************************************************************************/
cy_en_cryptolite_status_t Cy_Cryptolite_Aes_Cbc(CRYPTOLITE_Type *base,
                                        uint32_t srcSize,
                                        uint8_t *ivPtr,
                                        uint8_t *dst,
                                        uint8_t const *src,
                                        cy_stc_cryptolite_aes_context_t *aesContext)
{
    uint32_t size = srcSize;
    uint32_t i = 0;
    cy_en_cryptolite_status_t result = CY_CRYPTOLITE_UNKNOWN;

    if (NULL == base || NULL == ivPtr || NULL == dst || NULL == src || NULL == aesContext)
    {
        return (CY_CRYPTOLITE_BAD_PARAMS);
    }

    /* Check whether the data size is multiple of CY_CRYPTOLITE_AES_BLOCK_SIZE */
    if (0UL != (uint32_t)(size & (CY_CRYPTOLITE_AES_BLOCK_SIZE - 1U)))
    {
        return (CY_CRYPTOLITE_BAD_PARAMS);
    }

    while (size != 0UL)
    {
        /* In AES-CBC mode source block need to exclusive OR'ed with IV before the encryption operation. */
        for ( i = 0; i < CY_CRYPTOLITE_AES_BLOCK_SIZE; i++ )
        {
            dst[i] = (unsigned char)( src[i] ^ ivPtr[i] );
        }

        /* Encrypt the AES block on which exclusive OR is applied with IV */
        result = Cy_Cryptolite_Aes_ProcessBlock(base, dst, dst, aesContext);
        if(CY_CRYPTOLITE_SUCCESS != result)
        {
            return result;
        }
        /* The output of the current input block is used as IV for the next input block */
        (void) memcpy( ivPtr, dst, CY_CRYPTOLITE_AES_BLOCK_SIZE );

        src  += CY_CRYPTOLITE_AES_BLOCK_SIZE;
        dst  += CY_CRYPTOLITE_AES_BLOCK_SIZE;
        size -= CY_CRYPTOLITE_AES_BLOCK_SIZE;
    }

    return (result);
}

/*******************************************************************************
* Function Name: Cy_Cryptolite_Aes_Cfb
********************************************************************************
*
* Performs AES operation on a plain text with the Cipher Feedback Block (CFB)
* method.
*
*******************************************************************************/
cy_en_cryptolite_status_t Cy_Cryptolite_Aes_Cfb(CRYPTOLITE_Type *base,
                                        uint32_t srcSize,
                                        uint8_t *ivOffset,
                                        uint8_t *ivPtr,
                                        uint8_t *dst,
                                        uint8_t const *src,
                                        cy_stc_cryptolite_aes_context_t *aesContext)
{
    uint8_t _ivOffset = 0;
    cy_en_cryptolite_status_t result = CY_CRYPTOLITE_SUCCESS;

    if (NULL == base || srcSize == 0UL || NULL == ivOffset|| NULL == dst || NULL == src || NULL == aesContext)
    {
        return (CY_CRYPTOLITE_BAD_PARAMS);
    }


    _ivOffset = *ivOffset;

    if (_ivOffset > CY_CRYPTOLITE_AES_BLOCK_SIZE - 1U)
    {
        return (CY_CRYPTOLITE_BAD_PARAMS);
    }

    while (srcSize > 0U)
    {
        if (_ivOffset == 0U)
        {
            /* In AES-CFB mode iv is encrypted with the key */
            result = Cy_Cryptolite_Aes_ProcessBlock(base, ivPtr, ivPtr, aesContext);
            if(CY_CRYPTOLITE_SUCCESS != result)
            {
                return result;
            }
        }

        /* Source block is exclusive OR'ed with Encrypted IV.*/
        *dst = (unsigned char)(*src ^ ivPtr[_ivOffset]);

        /* The output of the current block is used as IV for the next input block */
        ivPtr[_ivOffset] = *dst;

        src++;
        dst++;
        _ivOffset = (_ivOffset + 1U) & 0x0FU;

        srcSize--;
    }

    *ivOffset = _ivOffset;

    return (result);
}

/*******************************************************************************
* Function Name: Cy_Cryptolite_Aes_Ofb
********************************************************************************
*
* Performs AES operation on a plain text with the Output Feedback Block (OFB)
* method.
*
*******************************************************************************/
cy_en_cryptolite_status_t Cy_Cryptolite_Aes_Ofb(CRYPTOLITE_Type *base,
                                        uint32_t srcSize,
                                        uint8_t *ivPtr,
                                        uint8_t *dst,
                                        uint8_t const *src,
                                        cy_stc_cryptolite_aes_context_t *aesContext)
{
    uint8_t ivOffset = 0;
    cy_en_cryptolite_status_t result = CY_CRYPTOLITE_SUCCESS;

    if (NULL == base || srcSize == 0UL || NULL == dst || NULL == src || NULL == aesContext)
    {
        return (CY_CRYPTOLITE_BAD_PARAMS);
    }

    while (srcSize > 0U)
    {
        if (ivOffset == 0U)
        {
            /* In AES-OFB mode iv is encrypted with the key */
            result = Cy_Cryptolite_Aes_ProcessBlock(base, ivPtr, ivPtr, aesContext);
            if(CY_CRYPTOLITE_SUCCESS != result)
            {
                return result;
            }
        }

        /* Source block is exclusive OR'ed with Encrypted IV.*/
        *dst = (unsigned char)(*src ^ ivPtr[ivOffset]);

        src++;
        dst++;
        ivOffset = (ivOffset + 1U) & 0x0FU;

        srcSize--;
    }

    return (result);
}

/*******************************************************************************
* Function Name: Cy_Cryptolite_Aes_Ctr
********************************************************************************
*
* Performs an AES operation on a plain text using the counter method (CTR).
*
*******************************************************************************/
cy_en_cryptolite_status_t Cy_Cryptolite_Aes_Ctr(CRYPTOLITE_Type *base,
                                        uint32_t srcSize,
                                        uint32_t *ncOffset,
                                        uint8_t  *nonceCounter,
                                        uint8_t  *streamBlock,
                                        uint8_t  *dst,
                                        uint8_t  const *src,
                                        cy_stc_cryptolite_aes_context_t *aesContext)
{
    cy_en_cryptolite_status_t result = CY_CRYPTOLITE_SUCCESS;
    uint32_t _ncOffset;
    uint32_t counter;

    if (NULL == base || srcSize == 0U || NULL == ncOffset || NULL == nonceCounter || NULL == dst || NULL == src || NULL == aesContext)
    {
        return (CY_CRYPTOLITE_BAD_PARAMS);
    }

    _ncOffset = *ncOffset;

    if (_ncOffset > (CY_CRYPTOLITE_AES_BLOCK_SIZE - 1U))
    {
        return (CY_CRYPTOLITE_BAD_PARAMS);
    }

    /* In the nonce counter last 4 bytes are used as counter for AES-CTR crypto operation.
     * The counter value filled by user in last 4-bytes is in big endian format, so swap the bytes. */
    CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 11.3','Intentional pointer type conversion');
    counter = CY_SWAP_ENDIAN32(*((uint32_t *)(nonceCounter + CY_CRYPTOLITE_AES_CTR_CNT_POS)));

    while (srcSize > 0U)
    {
        if (_ncOffset == 0U)
        {
            result = Cy_Cryptolite_Aes_ProcessBlock(base, streamBlock, nonceCounter, aesContext);
            if(CY_CRYPTOLITE_SUCCESS != result)
            {
                return result;
            }
            /* Increment the counter value so that for the next block, the key stream is different */
            counter++;

            /* Update the incremented counter value */
            CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 11.3','Intentional pointer type conversion');
            *((uint32_t *)(nonceCounter + CY_CRYPTOLITE_AES_CTR_CNT_POS)) = CY_SWAP_ENDIAN32(counter);

        }
        *dst++ = (unsigned char)( *src++ ^ streamBlock[_ncOffset] );

        _ncOffset = ( _ncOffset + 1U ) & (CY_CRYPTOLITE_AES_BLOCK_SIZE - 1U);

        srcSize = srcSize - 1U;
    }

    *ncOffset = _ncOffset;

    return (result);
}

#if defined(__cplusplus)
}
#endif

#endif /* (defined(CY_IP_M0S8CRYPTOLITE) && defined (CRYPTOLITE_AES_PRESENT)) */


/* [] END OF FILE */
