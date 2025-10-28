/***************************************************************************//**
* \file cy_crypto_aes.c
* \version 1.0.1
*
* \brief
*  This file provides the source code for the API for the AES method
*  in the Crypto driver.
*
*******************************************************************************
* \copyright
* (c) (2016-2021), Cypress Semiconductor Corporation (an Infineon company) or
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

#if (defined (CY_IP_M0S8CRYPTO) && defined (CRYPTO_AES))

#include "cy_crypto_aes.h"
#include "cy_crypto_hw.h"

#if defined(__cplusplus)
extern "C" {
#endif

#include <string.h>

#define CRYPTO_AES_MESSAGE_BLOCK_OFFSET     0x00 /* Beginning of memory buffer. */
#define CRYPTO_AES_KEY_OFFSET               0x04 /* AES key offset in memory buffer in 32-bit words. */
#define CRYPTO_AES_ROUND_KEY_OFFSET         0x0C /* Round key offset in memory buffer in 32-bit words. */
#define CY_CRYPTO_AES_CTR_CNT_POS           12   /* Counter position in the nonce counter buffer used in aes-ctr mode*/

/*******************************************************************************
* Function Name: Cy_Crypto_Aes_ProcessBlock
****************************************************************************//**
*
* Performs the AES block cipher.
*
*******************************************************************************/
static void Cy_Crypto_Aes_ProcessBlock(CRYPTO_Type *base,
                                       cy_stc_crypto_aes_context_t const *aesContext,
                                       cy_en_crypto_dir_mode_t dirMode,
                                       uint8_t *dstBlock,
                                       uint8_t const *srcBlock)
{
    uint16_t keySize = 0;

    keySize = CY_CRYPTO_AES_128_KEY_SIZE + ((uint16_t)aesContext->keyLength * 8U);

    /* Wait for Crypto IP to be ready */
    Cy_Crypto_WaitForReady(base);

    /* Copy message block to crypto memory buffer */
    (void) memcpy((char *)REG_CRYPTO_MEM_BUFF(base) + (CRYPTO_AES_MESSAGE_BLOCK_OFFSET * 4), (const char *)srcBlock, CY_CRYPTO_AES_BLOCK_SIZE);

    /* Copy key to crypto memory buffer */
    if (dirMode == CY_CRYPTO_ENCRYPT)
    {
        (void) memcpy((char *)REG_CRYPTO_MEM_BUFF(base) + (CRYPTO_AES_KEY_OFFSET * 4), (const char *)aesContext->key, keySize);
    }
    else
    {
        (void) memcpy((char *)REG_CRYPTO_MEM_BUFF(base) + (CRYPTO_AES_KEY_OFFSET * 4), (const char *)aesContext->keyInv, keySize);
    }

    /* Clear the OPCODE field in REG_CRYPTO_CTL */
    REG_CRYPTO_CTL(base) &= ~(_VAL2FLD(CRYPTO_CTL_OPCODE, CRYPTO_CTL_OPCODE_Msk));

    /* Set OPCODE to specify the operation. Value 0 specifies AES forward block cipher, 1 specifies AES inverse block cipher */
    REG_CRYPTO_CTL(base) |= _VAL2FLD(CRYPTO_CTL_OPCODE, dirMode);

    /* Specify the offset of the AES key in memory buffer. */
    REG_CRYPTO_SRC_CTL0(base) = _VAL2FLD(CRYPTO_SRC_CTL0_OFFSET, CRYPTO_AES_KEY_OFFSET);

    /* Specify the offset of the message block in memory buffer. */
    REG_CRYPTO_SRC_CTL1(base) = _VAL2FLD(CRYPTO_SRC_CTL1_OFFSET, CRYPTO_AES_MESSAGE_BLOCK_OFFSET);

    /* Specify the offset for round key in memory buffer.*/
    REG_CRYPTO_DST_CTL0(base) = _VAL2FLD(CRYPTO_DST_CTL0_OFFSET, CRYPTO_AES_ROUND_KEY_OFFSET);

    /* Specify the offset for the cipher text in memory buffer. */
    REG_CRYPTO_DST_CTL1(base) = _VAL2FLD(CRYPTO_DST_CTL1_OFFSET, CRYPTO_AES_MESSAGE_BLOCK_OFFSET);

    /* Set the key mode: 128, 192 or 256 Bit */
    REG_CRYPTO_AES_CTL(base) = _VAL2FLD(CRYPTO_AES_CTL_KEY_SIZE, aesContext->keyLength);

    /* Start the crypto operation */
    REG_CRYPTO_CMD(base) |= _VAL2FLD(CRYPTO_CMD_START, 0x1);

    /* Wait for crypto operation completion. */
    while ((REG_CRYPTO_CMD(base) & (0x1U << 0)) != 0U)
    {
    }

    /* Copy the output to the user provided buffer. */
    (void) memcpy((char *)dstBlock, (const char *)REG_CRYPTO_MEM_BUFF(base) + (CRYPTO_AES_MESSAGE_BLOCK_OFFSET * 4), CY_CRYPTO_AES_BLOCK_SIZE);
}


/*******************************************************************************
* Function Name: Cy_Crypto_Aes_InvKey
****************************************************************************//**
*
* Calculates an inverse block cipher key from the block cipher key.
*
*******************************************************************************/
static void Cy_Crypto_Aes_InvKey(CRYPTO_Type *base, cy_stc_crypto_aes_context_t const *aesContext)
{
    uint16_t keySize = 0;

    keySize = CY_CRYPTO_AES_128_KEY_SIZE + ((uint16_t)aesContext->keyLength * 8U);

    /* Wait for Crypto IP to be ready */
    Cy_Crypto_WaitForReady(base);

    (void) memcpy((char *)REG_CRYPTO_MEM_BUFF(base) + (CRYPTO_AES_KEY_OFFSET * 4), (const char *)aesContext->key, keySize);

    /* Clear the OPCODE field in REG_CRYPTO_CTL */
    REG_CRYPTO_CTL(base) &= ~(_VAL2FLD(CRYPTO_CTL_OPCODE, CRYPTO_CTL_OPCODE_Msk));

    /* Set OPCODE to specify the operation. Value 0 specifies AES forward block cipher, 1 specifies AES inverse block cipher */
    REG_CRYPTO_CTL(base) |= _VAL2FLD(CRYPTO_CTL_OPCODE, CY_CRYPTO_ENCRYPT);

    /* Specify the offset of the AES key in memory buffer. */
    REG_CRYPTO_SRC_CTL0(base) = _VAL2FLD(CRYPTO_SRC_CTL0_OFFSET, CRYPTO_AES_KEY_OFFSET);

    /* Specify the offset of the message block in memory buffer. */
    REG_CRYPTO_SRC_CTL1(base) = _VAL2FLD(CRYPTO_SRC_CTL1_OFFSET, CRYPTO_AES_MESSAGE_BLOCK_OFFSET);

    /* Specify the offset for round key in memory buffer.*/
    REG_CRYPTO_DST_CTL0(base) = _VAL2FLD(CRYPTO_DST_CTL0_OFFSET, CRYPTO_AES_ROUND_KEY_OFFSET);

    /* Specify the offset for the cipher text in memory buffer. */
    REG_CRYPTO_DST_CTL1(base) = _VAL2FLD(CRYPTO_DST_CTL1_OFFSET, CRYPTO_AES_MESSAGE_BLOCK_OFFSET);

    /* Set the key mode: 128, 192 or 256 Bit */
    REG_CRYPTO_AES_CTL(base) = _VAL2FLD(CRYPTO_AES_CTL_KEY_SIZE, aesContext->keyLength);

    /* Start the crypto operation */
    REG_CRYPTO_CMD(base) = 0x1;

    /* Wait for crypto operation completion. */
    while ((REG_CRYPTO_CMD(base) & (0x1U << 0)) != 0U)
    {
    }

    /* Copy the start round key for inverse block cipher. */
    (void) memcpy((char *)aesContext->keyInv, (const char *)REG_CRYPTO_MEM_BUFF(base) + (CRYPTO_AES_ROUND_KEY_OFFSET * 4), keySize);
}

/*******************************************************************************
* Function Name: Cy_Crypto_Aes_Init
****************************************************************************//**
*
* Sets AES mode and prepares an inverse key.
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Aes_Init(CRYPTO_Type *base,
                                         uint8_t const *key,
                                         cy_en_crypto_aes_key_length_t keyLength,
                                         cy_stc_crypto_aes_context_t *aesContext)
{
    uint16_t keySize = CY_CRYPTO_AES_128_KEY_SIZE + ((uint16_t)keyLength * 8U);

    if (NULL == base || NULL == key || NULL == aesContext)
    {
        return (CY_CRYPTO_BAD_PARAMS);
    }

    if ((keyLength != CY_CRYPTO_KEY_AES_128) && (keyLength != CY_CRYPTO_KEY_AES_192) && (keyLength != CY_CRYPTO_KEY_AES_256))
    {
        return (CY_CRYPTO_BAD_PARAMS);
    }

    if (!Cy_Crypto_IsEnabled(base))
    {
        return (CY_CRYPTO_HW_NOT_ENABLED);
    }

    aesContext->keyLength = keyLength;

    (void) memcpy((char *)aesContext->key, (const char *)key, keySize);

    /* Generate invert key used for inverse block cipher(Decryption) operation */
    Cy_Crypto_Aes_InvKey(base, aesContext);

    return (CY_CRYPTO_SUCCESS);
}

/*******************************************************************************
* Function Name: Cy_Crypto_Aes_Free
****************************************************************************//**
*
* Clears AES operation context.
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Aes_Free(CRYPTO_Type *base, cy_stc_crypto_aes_context_t *aesContext)
{
    if (NULL == base || NULL == aesContext)
    {
        return (CY_CRYPTO_BAD_PARAMS);
    }

    if (!Cy_Crypto_IsEnabled(base))
    {
        return (CY_CRYPTO_HW_NOT_ENABLED);
    }

    (void) memset((char *)aesContext, 0, sizeof(cy_stc_crypto_aes_context_t));

    /* Clear the memory buffer */
    (void) memset( (char *)REG_CRYPTO_MEM_BUFF(base) + CRYPTO_AES_MESSAGE_BLOCK_OFFSET, 0x00,  CY_CRYPTO_AES_BLOCK_SIZE + 2U * CY_CRYPTO_AES_MAX_KEY_SIZE);

    return (CY_CRYPTO_SUCCESS);
}

/*******************************************************************************
* Function Name: Cy_Crypto_Aes_Ecb
****************************************************************************//**
*
* Performs an AES operation on one block.
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Aes_Ecb(CRYPTO_Type *base,
                                        cy_en_crypto_dir_mode_t dirMode,
                                        uint8_t *dst,
                                        uint8_t const *src,
                                        cy_stc_crypto_aes_context_t *aesContext)
{
    if (NULL == base || NULL == dst || NULL == src || NULL == aesContext)
    {
        return (CY_CRYPTO_BAD_PARAMS);
    }

    if ((CY_CRYPTO_ENCRYPT != dirMode) && (CY_CRYPTO_DECRYPT != dirMode))
    {
        return (CY_CRYPTO_BAD_PARAMS);
    }

    if (!Cy_Crypto_IsEnabled(base))
    {
        return (CY_CRYPTO_HW_NOT_ENABLED);
    }

    Cy_Crypto_Aes_ProcessBlock(base, aesContext, dirMode, dst, src);

    return (CY_CRYPTO_SUCCESS);
}


/*******************************************************************************
* Function Name: Cy_Crypto_Aes_Cbc
****************************************************************************//**
*
* Performs AES operation on a plain text with Cipher Block Chaining (CBC) method.
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Aes_Cbc(CRYPTO_Type *base,
                                        cy_en_crypto_dir_mode_t dirMode,
                                        uint32_t srcSize,
                                        uint8_t *ivPtr,
                                        uint8_t *dst,
                                        uint8_t const *src,
                                        cy_stc_crypto_aes_context_t *aesContext)
{
    uint32_t size = srcSize;
    uint32_t i = 0;
    cy_en_crypto_status_t result = CY_CRYPTO_SIZE_NOT_X16;

    if (NULL == base || NULL == ivPtr || NULL == dst || NULL == src || NULL == aesContext)
    {
        return (CY_CRYPTO_BAD_PARAMS);
    }

    if ((CY_CRYPTO_ENCRYPT != dirMode) && (CY_CRYPTO_DECRYPT != dirMode))
    {
        return (CY_CRYPTO_BAD_PARAMS);
    }

    if (!Cy_Crypto_IsEnabled(base))
    {
        return (CY_CRYPTO_HW_NOT_ENABLED);
    }

    /* Check whether the data size is multiple of CY_CRYPTO_AES_BLOCK_SIZE */
    if (0UL == (uint32_t)(size & (CY_CRYPTO_AES_BLOCK_SIZE - 1U)))
    {
        if (CY_CRYPTO_DECRYPT == dirMode)
        {
            while (size != 0UL)
            {
                /* Decrypt the AES block */
                Cy_Crypto_Aes_ProcessBlock(base, aesContext, dirMode, dst, src);

                /* In AES-CBC mode decrypted source block need to exclusive OR'ed with IV */
                for (i = 0; i < CY_CRYPTO_AES_BLOCK_SIZE; i++)
                {
                    dst[i] = (unsigned char)( dst[i] ^ ivPtr[i] );
                }

                /* The current input block is used as IV for the next input block */
                (void) memcpy(ivPtr, src, CY_CRYPTO_AES_BLOCK_SIZE);

                src  += CY_CRYPTO_AES_BLOCK_SIZE;
                dst  += CY_CRYPTO_AES_BLOCK_SIZE;
                size -= CY_CRYPTO_AES_BLOCK_SIZE;
            }
        }
        else
        {
            while (size != 0UL)
            {
                /* In AES-CBC mode source block need to exclusive OR'ed with IV before the encryption operation. */
                for ( i = 0; i < CY_CRYPTO_AES_BLOCK_SIZE; i++ )
                {
                    dst[i] = (unsigned char)( src[i] ^ ivPtr[i] );
                }

                /* Encrypt the AES block on which exclusive OR is applied with IV */
                Cy_Crypto_Aes_ProcessBlock(base, aesContext, dirMode, dst, dst);

                /* The output of the current input block is used as IV for the next input block */
                (void) memcpy( ivPtr, dst, CY_CRYPTO_AES_BLOCK_SIZE );

                src  += CY_CRYPTO_AES_BLOCK_SIZE;
                dst  += CY_CRYPTO_AES_BLOCK_SIZE;
                size -= CY_CRYPTO_AES_BLOCK_SIZE;
            }
        }

        result = CY_CRYPTO_SUCCESS;
    }

    return (result);
}

/*******************************************************************************
* Function Name: Cy_Crypto_Aes_Cfb
********************************************************************************
*
* Performs AES operation on a plain text with the Cipher Feedback Block (CFB)
* method.
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Aes_Cfb(CRYPTO_Type *base,
                                        cy_en_crypto_dir_mode_t dirMode,
                                        uint32_t srcSize,
                                        uint8_t *ivOffset,
                                        uint8_t *ivPtr,
                                        uint8_t *dst,
                                        uint8_t const *src,
                                        cy_stc_crypto_aes_context_t *aesContext)
{
    uint8_t _ivOffset = 0;
    cy_en_crypto_status_t result = CY_CRYPTO_SUCCESS;

    if (NULL == base || srcSize == 0uL || NULL == ivOffset|| NULL == dst || NULL == src || NULL == aesContext)
    {
        return (CY_CRYPTO_BAD_PARAMS);
    }

    if ((CY_CRYPTO_ENCRYPT != dirMode) && (CY_CRYPTO_DECRYPT != dirMode))
    {
        return (CY_CRYPTO_BAD_PARAMS);
    }

    if (!Cy_Crypto_IsEnabled(base))
    {
        return (CY_CRYPTO_HW_NOT_ENABLED);
    }

    _ivOffset = *ivOffset;

    if (_ivOffset > CY_CRYPTO_AES_BLOCK_SIZE - 1U)
    {
        return (CY_CRYPTO_BAD_PARAMS);
    }

    if (dirMode == CY_CRYPTO_DECRYPT)
    {
        while (srcSize > 0U)
        {
            if (_ivOffset == 0U)
            {
                /* In AES-CFB mode iv is encrypted with the key */
                Cy_Crypto_Aes_ProcessBlock(base, aesContext, CY_CRYPTO_ENCRYPT, ivPtr, ivPtr);
            }

            /* Input data is exclusive OR'ed with IV */
            *dst = (unsigned char)(*src ^ ivPtr[_ivOffset]);

            /* Current source block is used as IV for the next block. */
            ivPtr[_ivOffset] = *src;

            src++;
            dst++;
            _ivOffset = ( _ivOffset + 1U ) & (CY_CRYPTO_AES_BLOCK_SIZE - 1U);

            srcSize--;
        }
    }
    else
    {
        while (srcSize > 0U)
        {
            if (_ivOffset == 0U)
            {
                /* In AES-CFB mode iv is encrypted with the key */
                Cy_Crypto_Aes_ProcessBlock(base, aesContext, CY_CRYPTO_ENCRYPT, ivPtr, ivPtr);
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
    }

    *ivOffset = _ivOffset;

    return (result);
}

/*******************************************************************************
* Function Name: Cy_Crypto_Aes_Ctr
********************************************************************************
*
* Performs an AES operation on a plain text using the counter method (CTR).
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Aes_Ctr(CRYPTO_Type *base,
                                        uint32_t srcSize,
                                        uint32_t *ncOffset,
                                        uint8_t  *nonceCounter,
                                        uint8_t  *streamBlock,
                                        uint8_t  *dst,
                                        uint8_t  const *src,
                                        cy_stc_crypto_aes_context_t *aesContext)
{
    uint32_t _ncOffset;
    uint32_t counter;

    if (NULL == base || srcSize == 0U || NULL == ncOffset || NULL == nonceCounter || NULL == dst || NULL == src || NULL == aesContext)
    {
        return (CY_CRYPTO_BAD_PARAMS);
    }

    if (!Cy_Crypto_IsEnabled(base))
    {
        return (CY_CRYPTO_HW_NOT_ENABLED);
    }

    _ncOffset = *ncOffset;

    if (_ncOffset > (CY_CRYPTO_AES_BLOCK_SIZE - 1U))
    {
        return (CY_CRYPTO_BAD_PARAMS);
    }

    /* In the nonce counter last 4 bytes are used as counter for AES-CTR crypto operation.
     * The counter value filled by user in last 4-bytes is in big endian format, so swap the bytes. */
    CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 11.3','Intentional pointer type conversion');
    counter = CY_SWAP_ENDIAN32(*((uint32_t *)(nonceCounter + CY_CRYPTO_AES_CTR_CNT_POS)));

    while (srcSize > 0U)
    {
        if (_ncOffset == 0U)
        {
            Cy_Crypto_Aes_ProcessBlock(base, aesContext, CY_CRYPTO_ENCRYPT, streamBlock, nonceCounter);

            /* Increment the counter value so that for the next block, the key stream is different */
            counter++;

            /* Update the incremented counter value */
            CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 11.3','Intentional pointer type conversion');
            *((uint32_t *)(nonceCounter + CY_CRYPTO_AES_CTR_CNT_POS)) = CY_SWAP_ENDIAN32(counter);

        }
        *dst++ = (unsigned char)( *src++ ^ streamBlock[_ncOffset] );

        _ncOffset = ( _ncOffset + 1U ) & (CY_CRYPTO_AES_BLOCK_SIZE - 1U);

        srcSize = srcSize - 1U;
    }

    *ncOffset = _ncOffset;

    return (CY_CRYPTO_SUCCESS);
}

#if defined(__cplusplus)
}
#endif

#endif /* CY_IP_MXCRYPTO */


/* [] END OF FILE */
