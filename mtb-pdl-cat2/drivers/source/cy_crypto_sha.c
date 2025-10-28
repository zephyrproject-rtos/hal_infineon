/***************************************************************************//**
* \file cy_crypto_sha.c
* \version 1.0.1
*
* \brief
*  This file provides SHA API implementation of the Crypto driver.
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

#if (defined (CY_IP_M0S8CRYPTO) && defined (CRYPTO_SHA))

#include "cy_syslib.h"
#include "cy_crypto_hw.h"
#include "cy_crypto_sha.h"

#if defined(__cplusplus)
extern "C" {
#endif

#include <string.h>

#define CRYPTO_SHA_OPERATION_OPCODE         0x10 /* 16 - SHA operation */
#define CRYPTO_OPERATION_ENABLE             0x01
#define CRYPTO_OPERATION_START              0x01

#define CRYPTO_SHA_MESSAGE_BLOCK_OFFSET     0x00 /* Beginning of memory buffer. */
#define CRYPTO_SHA_HASH_OFFSET              0x10 /* Byte 64. 64/4 = 16 (0x10) in 32-bit words. */
#define CRYPTO_SHA_ROUND_KEY_OFFSET         0x20 /* Byte 128. 128/4 = 32 (0x20) in 32-bit words. */

#define CRYPTO_SHA_MESSAGE_BLOCK_SIZE       (64)  /* 64 bytes (0x40 in hex) (512 bits) */
#define CRYPTO_SHA_HASH_SIZE_MAX            (32)  /* 32 bytes (0x20 in hex) (256 bits) */
#define CRYPTO_SHA_ROUND_KEY_SIZE_MAX       (320) /* 320 bytes (0x140 in hex) */

#define CY_CRYPTO_SHA256_PAD_SIZE           (56UL)

#define CY_CRYPTO_SHA1_ROUND_MEM_SIZE       (320UL)
#define CY_CRYPTO_SHA256_ROUND_MEM_SIZE     (256UL)
#define CY_CRYPTO_SHA_MAX_ROUND_MEM_SIZE    (CY_CRYPTO_SHA256_ROUND_MEM_SIZE)
/*******************************************************************************
* Function Name: Cy_Crypto_Sha_ProcessBlock
****************************************************************************//**
*
* This function performs SHA operation on a single block of message.
*
*******************************************************************************/
static void Cy_Crypto_Sha_ProcessBlock(CRYPTO_Type *base,
                                       cy_stc_crypto_sha_context_t *shaContext,
                                       uint8_t const *block)
{
    /* Wait for Crypto IP to be ready */
    Cy_Crypto_WaitForReady(base);

    /* Clear the OPCODE field in REG_CRYPTO_CTL */
    REG_CRYPTO_CTL(base) &= ~(_VAL2FLD(CRYPTO_CTL_OPCODE, CRYPTO_CTL_OPCODE_Msk));

    /* Enable crypto with opcode 16 for SHA operation */
    REG_CRYPTO_CTL(base) |= _VAL2FLD(CRYPTO_CTL_OPCODE, CRYPTO_SHA_OPERATION_OPCODE);

    /* Write block to memory buffer at offset 0 */
    (void) memcpy((char *)REG_CRYPTO_MEM_BUFF(base) + (CRYPTO_SHA_MESSAGE_BLOCK_OFFSET * 4), (const char *)block, shaContext->blockSize);

    /* Write hash in memory buffer at offset 64 (byte) */
    (void) memcpy((char *)REG_CRYPTO_MEM_BUFF(base) + (CRYPTO_SHA_HASH_OFFSET * 4), (const char *)shaContext->hash, shaContext->hashSize);

    /* Set the message offset to SRC_CTL0 register.*/
    REG_CRYPTO_SRC_CTL0(base) = _VAL2FLD(CRYPTO_SRC_CTL0_OFFSET, CRYPTO_SHA_MESSAGE_BLOCK_OFFSET);

    /* Set the memory buffer offset for hash in SRC_CTL1 register.*/
    REG_CRYPTO_SRC_CTL1(base) = _VAL2FLD(CRYPTO_SRC_CTL1_OFFSET, CRYPTO_SHA_HASH_OFFSET);

    /* Set the memory buffer offset for round key in DST_CTL0 register. */
    REG_CRYPTO_DST_CTL0(base) = _VAL2FLD(CRYPTO_DST_CTL0_OFFSET, CRYPTO_SHA_ROUND_KEY_OFFSET);

    /* Set the DST_CTL1 with the offset to store the hash. Let the hardware override the initial hash. */
    REG_CRYPTO_DST_CTL1(base) = _VAL2FLD(CRYPTO_DST_CTL1_OFFSET, CRYPTO_SHA_HASH_OFFSET);

    /* Set SHA mode */
    REG_CRYPTO_SHA_CTL(base) = _VAL2FLD(CRYPTO_SHA_CTL_MODE, shaContext->modeHw);

    /* Tell crypto to start the operation */
    REG_CRYPTO_CMD(base) |= _VAL2FLD(CRYPTO_CMD_START, CRYPTO_OPERATION_START);

    /* Wait for crypto operation completion. */
    while ((REG_CRYPTO_CMD(base) & (0x1U << 0)) != 0U)
    {
    }

    /* Copy the generated hash */
    (void) memcpy((char *)shaContext->hash, (const char *)REG_CRYPTO_MEM_BUFF(base) + (CRYPTO_SHA_HASH_OFFSET * 4), shaContext->hashSize);
}

/*******************************************************************************
* Function Name: Cy_Crypto_Sha_Init
****************************************************************************//**
*
* This function initializes the SHA operation.
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Sha_Init(CRYPTO_Type *base,
                                         cy_en_crypto_sha_mode_t mode,
                                         cy_stc_crypto_sha_context_t *shaContext)
{
    cy_en_crypto_status_t result = CY_CRYPTO_SUCCESS;

    if (NULL == base || NULL == shaContext)
    {
        return CY_CRYPTO_BAD_PARAMS;
    }

    if (!Cy_Crypto_IsEnabled(base))
    {
        return CY_CRYPTO_HW_NOT_ENABLED;
    }

    /* Initialization vectors for different modes of the SHA algorithm */
    static const uint32_t sha1InitHash[] =
    {
        0x67452301uL, 0xEFCDAB89uL, 0x98BADCFEuL, 0x10325476uL,
        0xC3D2E1F0uL
    };

    static const uint32_t sha224InitHash[] =
    {
        0xC1059ED8uL, 0x367CD507uL, 0x3070DD17uL, 0xF70E5939uL,
        0xFFC00B31uL, 0x68581511uL, 0x64F98FA7uL, 0xBEFA4FA4uL
    };

    static const uint32_t sha256InitHash[] =
    {
        0x6A09E667uL, 0xBB67AE85uL, 0x3C6EF372uL, 0xA54FF53AuL,
        0x510E527FuL, 0x9B05688CuL, 0x1F83D9ABuL, 0x5BE0CD19uL
    };

    switch (mode)
    {
        case CY_CRYPTO_MODE_SHA1:
            shaContext->mode           = (uint32_t)mode;
            shaContext->modeHw         = (uint32_t)CY_CRYPTO_MODE_SHA1;
            shaContext->initialHash    = (const uint8_t*)sha1InitHash;
            shaContext->blockSize      = CY_CRYPTO_SHA1_BLOCK_SIZE;
            shaContext->hashSize       = CY_CRYPTO_SHA1_HASH_SIZE;
            shaContext->digestSize     = CY_CRYPTO_SHA1_DIGEST_SIZE;
            break;

        case CY_CRYPTO_MODE_SHA224:
            shaContext->mode           = (uint32_t)mode;
            shaContext->modeHw         = (uint32_t)CY_CRYPTO_MODE_SHA224;
            shaContext->initialHash    = (const uint8_t*)sha224InitHash;
            shaContext->blockSize      = CY_CRYPTO_SHA256_BLOCK_SIZE;
            shaContext->hashSize       = CY_CRYPTO_SHA256_HASH_SIZE;
            shaContext->digestSize     = CY_CRYPTO_SHA224_DIGEST_SIZE;
            break;

        case CY_CRYPTO_MODE_SHA256:
            shaContext->mode           = (uint32_t)mode;
            shaContext->modeHw         = (uint32_t)CY_CRYPTO_MODE_SHA224; /* In hardware, for both SHA-256 and SHA-224, SHA mode is set as 0x1 */
            shaContext->initialHash    = (const uint8_t*)sha256InitHash;
            shaContext->blockSize      = CY_CRYPTO_SHA256_BLOCK_SIZE;
            shaContext->hashSize       = CY_CRYPTO_SHA256_HASH_SIZE;
            shaContext->digestSize     = CY_CRYPTO_SHA256_DIGEST_SIZE;
            break;

        default:
            result = CY_CRYPTO_BAD_PARAMS;
            break;
    }

    if (CY_CRYPTO_SUCCESS == result)
    {
        shaContext->blockIdx = 0U;
        shaContext->messageSize = 0U;

        (void) memcpy(shaContext->hash, shaContext->initialHash, (uint16_t)shaContext->hashSize);

        /* Set SHA internal processing state */
        shaContext->processState = CY_CRYPTO_SHA_INITIALIZED;
    }

    return (result);
}

/*******************************************************************************
* Function Name: Cy_Crypto_Sha_Partial
****************************************************************************//**
*
* This function performs the SHA operation on a message part.
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Sha_Partial(CRYPTO_Type *base,
                                            uint8_t const *message,
                                            uint32_t  messageSize,
                                            cy_stc_crypto_sha_context_t *shaContext)
{
    uint32_t hashBlockIdx;
    uint32_t hashBlockSize;

    if (NULL == base || NULL == shaContext || 0U == shaContext->blockSize || (messageSize > 0U && NULL == message))
    {
        return CY_CRYPTO_BAD_PARAMS;
    }

    if (!Cy_Crypto_IsEnabled(base))
    {
        return CY_CRYPTO_HW_NOT_ENABLED;
    }

    if ((CY_CRYPTO_SHA_INITIALIZED != shaContext->processState) && (CY_CRYPTO_SHA_PARTIAL_PROCESSED != shaContext->processState))
    {
        return CY_CRYPTO_INVALID_OPERATION;
    }

    hashBlockIdx  = shaContext->blockIdx;
    hashBlockSize = shaContext->blockSize;

    shaContext->messageSize += messageSize;

    /* Processing the fully filled blocks with remaining buffer data */
    while ((hashBlockIdx + messageSize) >= hashBlockSize)
    {
        uint32_t tempBlockSize = hashBlockSize - hashBlockIdx;
        /*
        If a complete block size bytes of message is available and there is no previous partial block to be appended to,
        process it directly in Cy_Crypto_Sha_ProcessBlock without copying to shaContext->block.
        */
        if(tempBlockSize == hashBlockSize && hashBlockIdx == 0U)
        {
            Cy_Crypto_Sha_ProcessBlock(base, shaContext, message);
        }
        else
        {
            (void) memcpy((char *)shaContext->block + hashBlockIdx, (const char *)message, (uint16_t)tempBlockSize);
            Cy_Crypto_Sha_ProcessBlock(base, shaContext, shaContext->block);

            hashBlockIdx = 0U;
        }
        messageSize -= tempBlockSize;
        message += tempBlockSize;
    }

    /* The remaining block will be calculated in the Finish function. */
    shaContext->blockIdx = hashBlockIdx + messageSize;

    /* Copy the end of the message to the block */
    if (messageSize != 0U)
    {
        (void) memcpy((char *)shaContext->block + hashBlockIdx, (const char *)message, (uint16_t)messageSize);
    }

    /* Set SHA internal processing state */
    shaContext->processState = CY_CRYPTO_SHA_PARTIAL_PROCESSED;

    return CY_CRYPTO_SUCCESS;
}

/*******************************************************************************
* Function Name: Cy_Crypto_Sha_Finish
****************************************************************************//**
*
* This function completes the SHA operation and writes the computed Hash digest
* to memory pointed by the digest parameter.
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Sha_Finish(CRYPTO_Type *base,
                                           uint8_t *digest,
                                           cy_stc_crypto_sha_context_t *shaContext)
{
    uint8_t *hashPtr; 
    uint8_t *blockPtr;
    uint32_t hashBlockSize, hashBlockIdx;
    uint64_t finalMessageSizeInBits;
    uint32_t padSize = CY_CRYPTO_SHA256_PAD_SIZE; /* Pad size = 56 */

    if (NULL == base || NULL == digest || NULL == shaContext)
    {
        return CY_CRYPTO_BAD_PARAMS;
    }

    if (!Cy_Crypto_IsEnabled(base))
    {
        return CY_CRYPTO_HW_NOT_ENABLED;
    }

    if (CY_CRYPTO_SHA_PARTIAL_PROCESSED != shaContext->processState)
    {
        return CY_CRYPTO_INVALID_OPERATION;
    }

    hashPtr = shaContext->hash;
    blockPtr = shaContext->block;
    hashBlockSize = shaContext->blockSize;
    hashBlockIdx = shaContext->blockIdx;
    finalMessageSizeInBits = (uint64_t)shaContext->messageSize * 8U;

    /* Append 1 bit to the end of the message */
    blockPtr[hashBlockIdx] = 0x80U;

    /* Clear the rest of the block */
    (void) memset((void* )&blockPtr[hashBlockIdx + 1U], 0x00, (uint16_t)(hashBlockSize - hashBlockIdx - 1U));

    if (hashBlockIdx >= padSize)
    {
        /* Here we need one additional last block to calculate SHA, prepare it: */
        Cy_Crypto_Sha_ProcessBlock(base, shaContext, (uint8_t*)blockPtr);

        /* Clear the last block */
        (void) memset(blockPtr, 0x00, (uint16_t)hashBlockSize);
    }

    blockPtr[hashBlockSize - 4U] = (uint8_t)((finalMessageSizeInBits) >> 24U);
    blockPtr[hashBlockSize - 3U] = (uint8_t)((finalMessageSizeInBits) >> 16U);
    blockPtr[hashBlockSize - 2U] = (uint8_t)((finalMessageSizeInBits) >> 8U);
    blockPtr[hashBlockSize - 1U] = (uint8_t)(finalMessageSizeInBits);

    /* Process the last block */
    Cy_Crypto_Sha_ProcessBlock(base, shaContext, (uint8_t*)blockPtr);

    /* Invert endianness of the hash and copy it to digest, re-use the padSize variable */
    padSize = (uint32_t)(shaContext->digestSize / 4U);

    for (; padSize != 0U; padSize--)
    {
        *(digest)   = *(hashPtr+3);
        *(digest+1) = *(hashPtr+2);
        *(digest+2) = *(hashPtr+1);
        *(digest+3) = *(hashPtr);

        digest  += 4U;
        hashPtr += 4U;
    }

    /* Set SHA internal processing state */
    shaContext->processState = CY_CRYPTO_SHA_PARTIAL_PROCESSED;

    return CY_CRYPTO_SUCCESS;
}

/*******************************************************************************
* Function Name: Cy_Crypto_Sha_Free
****************************************************************************//**
*
* This function clears the SHA context and computed hash from memory buffer.
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Sha_Free(CRYPTO_Type *base, cy_stc_crypto_sha_context_t *shaContext)
{
    if (NULL == base || NULL == shaContext)
    {
        return CY_CRYPTO_BAD_PARAMS;
    }

    if (!Cy_Crypto_IsEnabled(base))
    {
        return CY_CRYPTO_HW_NOT_ENABLED;
    }

    if ((CY_CRYPTO_SHA_INITIALIZED != shaContext->processState) &&
        (CY_CRYPTO_SHA_PARTIAL_PROCESSED != shaContext->processState) &&
        (CY_CRYPTO_SHA_FINISHED != shaContext->processState))
    {
        return CY_CRYPTO_INVALID_OPERATION;
    }

    /* Clear the hash and block in sha hash context. */
    (void) memset((void *)shaContext->block, 0, CY_CRYPTO_SHA_MAX_BLOCK_SIZE);
    (void) memset((void *)shaContext->hash, 0, CY_CRYPTO_SHA_MAX_HASH_SIZE);

    return CY_CRYPTO_SUCCESS;
}

/*******************************************************************************
* Function Name: Cy_Crypto_Sha
****************************************************************************//**
*
* This function performs the SHA operation on a message.
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Sha(CRYPTO_Type *base,
                                    uint8_t const *message,
                                    uint32_t messageSize,
                                    uint8_t *digest,
                                    cy_en_crypto_sha_mode_t mode)
{
    cy_en_crypto_status_t result = CY_CRYPTO_BAD_PARAMS;
    cy_stc_crypto_sha_context_t myHashContext = { 0 };

    if (NULL == base || NULL == digest || (messageSize > 0U && NULL == message))
    {
        return CY_CRYPTO_BAD_PARAMS;
    }

    result = Cy_Crypto_Sha_Init(base, mode, &myHashContext);
    if (CY_CRYPTO_SUCCESS != result)
    {
        return result;
    }

    result = Cy_Crypto_Sha_Partial(base, message, messageSize, &myHashContext);
    if (CY_CRYPTO_SUCCESS != result)
    {
        (void) Cy_Crypto_Sha_Free(base, &myHashContext);
        return result;
    }

    result = Cy_Crypto_Sha_Finish(base, digest, &myHashContext);
    if (CY_CRYPTO_SUCCESS != result)
    {
        (void) Cy_Crypto_Sha_Free(base, &myHashContext);
        return result;
    }

    result = Cy_Crypto_Sha_Free(base, &myHashContext);

    return (result);
}

#if defined(__cplusplus)
}
#endif

#endif // CY_IP_M0S8CRYPTO
