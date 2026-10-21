/***************************************************************************//**
* \file cy_cryptolite_sha.c
* \version 1.40
*
* \brief
* Provides API implementation of the Cryptolite PDL driver.
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

#if (defined(CY_IP_M0S8CRYPTOLITE) && (defined (CRYPTOLITE_SHA_PRESENT) || \
     defined (CRYPTOLITE_SHA384_PRESENT) || defined (CRYPTOLITE_SHA512_PRESENT)))
#include "cy_cryptolite_sha.h"

#if defined(__cplusplus)
extern "C" {
#endif

#include <string.h>

#include "cy_sysint.h"
#include "cy_syslib.h"

/* Initial Hash as per SHA standard. */
#if defined (CRYPTOLITE_SHA_PRESENT)
#if (CRYPTOLITE_SHA_PRESENT)
CRYPTOLITE_SHA_CONST static const uint32_t sha256InitHash[] =
{
    0x6A09E667UL, 0xBB67AE85UL, 0x3C6EF372UL, 0xA54FF53AUL,
    0x510E527FUL, 0x9B05688CUL, 0x1F83D9ABUL, 0x5BE0CD19UL
};
#endif /* (CRYPTOLITE_SHA_PRESENT) */
#endif /* defined (CRYPTOLITE_SHA_PRESENT) */

#if defined (CRYPTOLITE_SHA384_PRESENT)
#if (CRYPTOLITE_SHA384_PRESENT)
CRYPTOLITE_SHA_CONST static const uint32_t sha384InitHash[] =
{
    0xC1059ED8UL, 0xCBBB9D5DUL, 0x367CD507UL, 0x629A292AUL,
    0x3070DD17UL, 0x9159015AUL, 0xF70E5939UL, 0x152FECD8UL,
    0xFFC00B31UL, 0x67332667UL, 0x68581511UL, 0x8EB44A87UL,
    0x64F98FA7UL, 0xDB0C2E0DUL, 0xBEFA4FA4UL, 0x47B5481DUL
};
#endif /* (CRYPTOLITE_SHA384_PRESENT) */
#endif /* defined (CRYPTOLITE_SHA384_PRESENT) */

#if defined (CRYPTOLITE_SHA512_PRESENT)
#if (CRYPTOLITE_SHA512_PRESENT)
CRYPTOLITE_SHA_CONST static const uint32_t sha512InitHash[] =
{
    0XF3BCC908UL, 0X6A09E667UL, 0X84CAA73BUL, 0XBB67AE85UL,
    0XFE94F82BUL, 0X3C6EF372UL, 0X5F1D36F1UL, 0XA54FF53AUL,
    0XADE682D1UL, 0X510E527FUL, 0X2B3E6C1FUL, 0X9B05688CUL,
    0XFB41BD6BUL, 0X1F83D9ABUL, 0X137E2179UL, 0X5BE0CD19UL
};
#endif /* (CRYPTOLITE_SHA512_PRESENT) */
#endif /* defined (CRYPTOLITE_SHA512_PRESENT) */

/*****************************************************************************
* Cy_Cryptolite_Sha_Process (for internal use)
******************************************************************************
*
* The function starts the hash calculation, blocks until finished.
*
*  base
* The pointer to the Cryptolite instance.
*
*  shaContext
* The pointer to the cy_stc_cryptolite_sha_context_t structure that stores all
* internal variables for Cryptolite driver.
*
* return
* cy_en_cryptolite_status_t
*
*******************************************************************************/
ATTRIBUTES_CRYPTOLITE_SHA static cy_en_cryptolite_status_t Cy_Cryptolite_Sha_Process(CRYPTOLITE_Type *base,
                                        cy_stc_cryptolite_sha_context_t *shaContext)
{
    /* Check if IP is busy. */
    if((REG_CRYPTOLITE_STATUS(base) & CRYPTOLITE_STATUS_BUSY_Msk) != 0UL)
    {
        return CY_CRYPTOLITE_HW_BUSY;
    }

    /*write to SHA DESCR REG starts process
      IP will block another write to SHA DESCR REG until its busy
      We poll for busy state and check for error before posting next
      descriptor. */

    /* Start message schedule. */
    REG_CRYPTOLITE_SHA_DESCR(base) = (uint32_t)&(shaContext->message_schedule_struct);
    while((REG_CRYPTOLITE_STATUS(base) & CRYPTOLITE_STATUS_BUSY_Msk) != 0UL){}
    if((REG_CRYPTOLITE_INTR_ERROR(base) & CRYPTOLITE_INTR_ERROR_BUS_ERROR_Msk) != 0UL)
    {
        REG_CRYPTOLITE_INTR_ERROR(base) = CRYPTOLITE_INTR_ERROR_BUS_ERROR_Msk;
        return CY_CRYPTOLITE_BUS_ERROR;
    }

    /* Start process. */
    REG_CRYPTOLITE_SHA_DESCR(base) = (uint32_t)&(shaContext->message_process_struct);
    while((REG_CRYPTOLITE_STATUS(base) & CRYPTOLITE_STATUS_BUSY_Msk) != 0UL){}
    if((REG_CRYPTOLITE_INTR_ERROR(base) & CRYPTOLITE_INTR_ERROR_BUS_ERROR_Msk) != 0UL)
    {
        REG_CRYPTOLITE_INTR_ERROR(base) = CRYPTOLITE_INTR_ERROR_BUS_ERROR_Msk;
        return CY_CRYPTOLITE_BUS_ERROR;
    }

    return CY_CRYPTOLITE_SUCCESS;
}

/*****************************************************************************
* Cy_Cryptolite_Sha_Process_aligned (for internal use)
******************************************************************************
*
* The function starts the hash calculation for 4 byte aligned data blocks
* until finished.
*
*  base
* The pointer to the Cryptolite instance.
*
*  shaContext
* The pointer to the cy_stc_cryptolite_sha_context_t structure that stores all
* internal variables for Cryptolite driver.
*
*  message
* The pointer to the message whose Hash is being computed.
*
*  messageSize
* The pointer to size of the message whose Hash is being computed.
* returns the remaining message size after process
*
* return
* cy_en_cryptolite_status_t
*
*******************************************************************************/
ATTRIBUTES_CRYPTOLITE_SHA static cy_en_cryptolite_status_t Cy_Cryptolite_Sha_Process_aligned(CRYPTOLITE_Type *base,
                                        cy_stc_cryptolite_sha_context_t *shaContext,
                                        uint8_t const *message,
                                        uint32_t  *messageSize)
{
    cy_en_cryptolite_status_t err;

    /* Point descriptor to message buffer. */
    shaContext->message_schedule_struct.data1 = (uint32_t)message;

    /* Process the input message till the message size is greater than block size. */
    while(*messageSize >= shaContext->blockSize)
    {
        /* Perform SHA calculation. */
        err = Cy_Cryptolite_Sha_Process(base, shaContext);
        /* If SHA calculation process is failed, reset the descriptor to context buffer.  */
        if(CY_CRYPTOLITE_SUCCESS != err)
        {
            shaContext->message_schedule_struct.data1 = (uint32_t)shaContext->message;
            return err;
        }

        /* Update the parameters. */
        *messageSize-=shaContext->blockSize;
        shaContext->messageSize+= shaContext->blockSize;
        shaContext->message_schedule_struct.data1+= shaContext->blockSize;
    }
    /* Restore descriptor to context buffer. */
    shaContext->message_schedule_struct.data1 = (uint32_t)shaContext->message;

    return CY_CRYPTOLITE_SUCCESS;
}

/*****************************************************************************
* Cy_Cryptolite_Sha_SetMode
******************************************************************************
*
* The function sets the SHA mode of operation.
*
* mode
* SHA selection mode(SHA256, SHA384, SHA512).
*
* shaContext
* The pointer to the cy_stc_cryptolite_sha_context_t structure that stores all
* internal variables for Cryptolite driver.
*
* return
* cy_en_cryptolite_status_t
*
*******************************************************************************/
ATTRIBUTES_CRYPTOLITE_SHA cy_en_cryptolite_status_t Cy_Cryptolite_Sha_SetMode( cy_en_cryptolite_sha_mode_t mode,
                                        cy_stc_cryptolite_sha_context_t *shaContext)
{
    /* Input parameters verification. */
    if (NULL == shaContext)
    {
        return CY_CRYPTOLITE_BAD_PARAMS;
    }

    /* Set the received SHA mode in SHA context. */
    shaContext->shaMode = mode;

    return CY_CRYPTOLITE_SUCCESS;
}

/*****************************************************************************
* Cy_Cryptolite_Sha_Init
******************************************************************************
*
* The function to initialize the SHA256 operation.
*
*  base
* The pointer to the Cryptolite instance.
*
*  shaContext
* The pointer to the cy_stc_cryptolite_sha_context_t structure that stores all
* internal variables for Cryptolite driver.
*
* return
* cy_en_cryptolite_status_t
*
*******************************************************************************/
ATTRIBUTES_CRYPTOLITE_SHA cy_en_cryptolite_status_t Cy_Cryptolite_Sha_Init(CRYPTOLITE_Type *base,
                                        cy_stc_cryptolite_sha_context_t *shaContext)
{
    cy_en_cryptolite_status_t retStatus = CY_CRYPTOLITE_SUCCESS;
#if (defined (CRYPTOLITE_SHA384_PRESENT) || defined (CRYPTOLITE_SHA512_PRESENT))
#if ((CRYPTOLITE_SHA384_PRESENT) || (CRYPTOLITE_SHA512_PRESENT))
    uint32_t regData = 0x00UL;
#endif /* ((CRYPTOLITE_SHA384_PRESENT) || (CRYPTOLITE_SHA512_PRESENT)) */
#endif /* (defined (CRYPTOLITE_SHA384_PRESENT) || defined (CRYPTOLITE_SHA512_PRESENT)) */

    /* Input parameters verification. */
    if ((NULL == base) || (NULL == shaContext))
    {
        return CY_CRYPTOLITE_BAD_PARAMS;
    }
    
#if defined(CY_DEVICE_PMG1S3)
    /* PMG1S3 devices supports only SHA256. */
    shaContext->shaMode = CY_CRYPTOLITE_SHA_MODE_SHA256;
#endif /* defined(CY_DEVICE_PMG1S3) */
    
    /* Initialize SHA parameters based on SHA mode set. */
    switch(shaContext->shaMode)
    {
#if defined (CRYPTOLITE_SHA_PRESENT)
#if (CRYPTOLITE_SHA_PRESENT)
        case CY_CRYPTOLITE_SHA_MODE_SHA256:
            shaContext->blockSize = CY_CRYPTOLITE_SHA256_BLOCK_SIZE;
            shaContext->hashSize = CY_CRYPTOLITE_SHA256_HASH_SIZE;
            shaContext->paddSize = CY_CRYPTOLITE_SHA256_PAD_SIZE;
            shaContext->digestSize = CY_CRYPTOLITE_SHA256_DIGEST_SIZE;
            shaContext->initialHash = (uint8_t *)sha256InitHash;
            break;
#endif /* (CRYPTOLITE_SHA_PRESENT) */
#endif /* defined (CRYPTOLITE_SHA_PRESENT) */
#if defined (CRYPTOLITE_SHA384_PRESENT)
#if (CRYPTOLITE_SHA384_PRESENT)
        case CY_CRYPTOLITE_SHA_MODE_SHA384:
            shaContext->blockSize = CY_CRYPTOLITE_SHA384_BLOCK_SIZE;
            shaContext->hashSize = CY_CRYPTOLITE_SHA384_HASH_SIZE;
            shaContext->paddSize = CY_CRYPTOLITE_SHA384_PAD_SIZE;
            shaContext->digestSize = CY_CRYPTOLITE_SHA384_DIGEST_SIZE;
            shaContext->initialHash = (uint8_t *)sha384InitHash;
            break;
#endif /* (CRYPTOLITE_SHA384_PRESENT) */
#endif /* defined (CRYPTOLITE_SHA384_PRESENT) */
#if defined (CRYPTOLITE_SHA512_PRESENT)
#if (CRYPTOLITE_SHA512_PRESENT)
        case CY_CRYPTOLITE_SHA_MODE_SHA512:
            shaContext->blockSize = CY_CRYPTOLITE_SHA512_BLOCK_SIZE;
            shaContext->hashSize = CY_CRYPTOLITE_SHA512_HASH_SIZE;
            shaContext->paddSize = CY_CRYPTOLITE_SHA512_PAD_SIZE;
            shaContext->digestSize = CY_CRYPTOLITE_SHA512_DIGEST_SIZE;
            shaContext->initialHash = (uint8_t *)sha512InitHash;
            break;
#endif /* (CRYPTOLITE_SHA512_PRESENT) */
#endif /* defined (CRYPTOLITE_SHA512_PRESENT) */
        default:
            retStatus = CY_CRYPTOLITE_BAD_PARAMS;
            break;
    }

    if(retStatus == CY_CRYPTOLITE_SUCCESS)
    {
        /* Initialize internal block buffer to SHA context message pointer. */
        shaContext->message = (uint8_t*)shaContext->block;

#if (defined (CRYPTOLITE_SHA384_PRESENT) || defined (CRYPTOLITE_SHA512_PRESENT))
#if ((CRYPTOLITE_SHA384_PRESENT) || (CRYPTOLITE_SHA512_PRESENT))
        /* Select SHA mode using SHA_SEL register. */
        regData = REG_CRYPTOLITE_CTL(base) & (~(CRYPTOLITE_CTL_SHA_SEL_Msk));
        REG_CRYPTOLITE_CTL(base) = (regData | _VAL2FLD(CRYPTOLITE_CTL_SHA_SEL, shaContext->shaMode));
#endif /* ((CRYPTOLITE_SHA384_PRESENT) || (CRYPTOLITE_SHA512_PRESENT)) */
#endif /* (defined (CRYPTOLITE_SHA384_PRESENT) || defined (CRYPTOLITE_SHA512_PRESENT)) */

        /* Set SHA driver internal processing state. */
        shaContext->processState = CY_CRYPTOLITE_SHA_PROCESS_INITIALIZED;
    }

    return (retStatus);
}

/*******************************************************************************
* Cy_Cryptolite_Sha_Start
******************************************************************************
*
* Initializes the initial Hash vector.
*
*  base
* The pointer to the CRYPTOLITE instance.
*
*  shaContext
* The pointer to the cy_stc_cryptolite_sha_context_t structure that stores all
* internal variables for Cryptolite driver.
*
* return
* cy_en_cryptolite_status_t
*
*******************************************************************************/
ATTRIBUTES_CRYPTOLITE_SHA cy_en_cryptolite_status_t Cy_Cryptolite_Sha_Start(CRYPTOLITE_Type *base,
                                        cy_stc_cryptolite_sha_context_t *shaContext)
{
    /* Input parameters verification. */
    if ((NULL == base) || (NULL == shaContext))
    {
        return CY_CRYPTOLITE_BAD_PARAMS;
    }

    /* SHA Process state verification. */
    if(shaContext->processState != CY_CRYPTOLITE_SHA_PROCESS_INITIALIZED)
    {
        return CY_CRYPTOLITE_INVALID_OPERATION;
    }

    /* Check if IP is busy. */
    if ((REG_CRYPTOLITE_STATUS(base) & CRYPTOLITE_STATUS_BUSY_Msk) != 0UL)
    {
        return CY_CRYPTOLITE_HW_BUSY;
    }

    /* Initialize SHA Context members to start with SHA calculation. */
    shaContext->msgIdx = 0U;
    shaContext->messageSize = 0U;

    /* Initialize SHA schedule descriptor with message input. */
    shaContext->message_schedule_struct.data0 = (uint32_t)CY_CRYPTOLITE_MSG_SCH_CTLWD;
    shaContext->message_schedule_struct.data1 = (uint32_t)shaContext->message;
    shaContext->message_schedule_struct.data2 = (uint32_t)shaContext->schedule;

    /* Initialize SHA process descriptor with hash input. */
    shaContext->message_process_struct.data0 = (uint32_t)CY_CRYPTOLITE_PROCESS_CTLWD;
    shaContext->message_process_struct.data1 = (uint32_t)shaContext->hash;
    shaContext->message_process_struct.data2 = (uint32_t)shaContext->schedule;

    /*copy initial hash*/
    (void)memcpy((char *)shaContext->hash, (const char *)shaContext->initialHash, (uint16_t)shaContext->hashSize);

    /* Set SHA driver internal processing state. */
    shaContext->processState = CY_CRYPTOLITE_SHA_PROCESS_STARTED;

    return CY_CRYPTOLITE_SUCCESS;
}

/*******************************************************************************
* Cy_Cryptolite_Sha_Update
********************************************************************************
*
* Performs the SHA calculation on one message.
*
*  base
* The pointer to the CRYPTOLITE instance.
*
*  shaContext
* The pointer to the cy_stc_cryptolite_sha_context_t structure that stores all
* internal variables for Cryptolite driver.
*
*  message
* The pointer to the message whose Hash is being computed.
*
*  messageSize
* The size of the message whose Hash is being computed.
*
* return
* cy_en_cryptolite_status_t
*
*******************************************************************************/
ATTRIBUTES_CRYPTOLITE_SHA cy_en_cryptolite_status_t Cy_Cryptolite_Sha_Update(CRYPTOLITE_Type *base,
                                        uint8_t const *message,
                                        uint32_t  messageSize,
                                        cy_stc_cryptolite_sha_context_t *shaContext)
{
    cy_en_cryptolite_status_t err = CY_CRYPTOLITE_BAD_PARAMS;
    uint32_t readIdx = 0U;
    uint32_t idx = 0U;
    uint32_t msg_add = (uint32_t)message;
    uint32_t lmessageSize;

    /* Input parameters verification. */
    if (0UL == messageSize)
    {
        return CY_CRYPTOLITE_SUCCESS;
    }

    /* Input parameters verification. */
    if ((NULL == base) || (NULL == shaContext) || (NULL == message))
    {
        return err;
    }

    /* SHA Process state verification. */
    if((shaContext->processState != CY_CRYPTOLITE_SHA_PROCESS_STARTED) &&
       (shaContext->processState != CY_CRYPTOLITE_SHA_PROCESS_PARTIALLY))
    {
        return CY_CRYPTOLITE_INVALID_OPERATION;
    }

    /* Check if IP is busy. */
    if ((REG_CRYPTOLITE_STATUS(base) & CRYPTOLITE_STATUS_BUSY_Msk) != 0UL)
    {
        return CY_CRYPTOLITE_HW_BUSY;
    }

    lmessageSize = messageSize;

    /* Check for 4 byte aligned buffer and process. */
    if((msg_add & 0x3UL) == 0UL)
    {
        /* Check for fragmented message and size. */
        if (shaContext->msgIdx == 0UL && messageSize >= shaContext->blockSize)
        {
            /* SHA Processing for 4B aligned message. */
            err = Cy_Cryptolite_Sha_Process_aligned(base, shaContext, message, &lmessageSize);
            if(CY_CRYPTOLITE_SUCCESS != err)
            {
                return err;
            }
            readIdx = messageSize - lmessageSize;
        }
    }

    /* Unaligned input message SHA calculation by copying the input message to
     * aligned buffer i.e., SHA context buffer.
     */
    while((shaContext->msgIdx + lmessageSize) >= shaContext->blockSize)
    {
        uint32_t toCopy = shaContext->blockSize - shaContext->msgIdx;
        /* Create a message block. */
        for ( idx = 0; idx < toCopy; idx++ )
        {
            shaContext->message[shaContext->msgIdx] = message[readIdx++];
            shaContext->msgIdx++;
        }
        /* SHA Processing for unaligned message. */
        err = Cy_Cryptolite_Sha_Process(base, shaContext);
        if(CY_CRYPTOLITE_SUCCESS != err)
        {
            return err;
        }
        /* Update parameters. */
        lmessageSize-= toCopy;
        shaContext->messageSize+= shaContext->blockSize;
        shaContext->msgIdx = 0U;
    }

    /* Copy message fragment. */
    for ( idx = 0; idx < lmessageSize; idx++ )
    {
        shaContext->message[shaContext->msgIdx] = message[readIdx++];
        shaContext->msgIdx++;
    }

    /* Set SHA driver internal processing state. */
    shaContext->processState = CY_CRYPTOLITE_SHA_PROCESS_PARTIALLY;

    return CY_CRYPTOLITE_SUCCESS;
}

/*******************************************************************************
* Cy_Cryptolite_Sha_Finish
********************************************************************************
*
* Completes the SHA calculation.
*
*  base
* The pointer to the CRYPTOLITE instance.
*
*  shaContext
* the pointer to the cy_stc_cryptolite_sha_context_t structure that stores all
* internal variables for Cryptolite driver.
*
*  digest
* The pointer to the calculated Hash digest.
*
* return
* cy_en_cryptolite_status_t
*
*******************************************************************************/
ATTRIBUTES_CRYPTOLITE_SHA cy_en_cryptolite_status_t Cy_Cryptolite_Sha_Finish(CRYPTOLITE_Type *base,
                                    uint8_t *digest,
                                    cy_stc_cryptolite_sha_context_t *shaContext)
{
    cy_en_cryptolite_status_t err = CY_CRYPTOLITE_SUCCESS;
    uint8_t *hashPtr;
    uint32_t idx;
    uint32_t byteIdx;
    uint32_t wordSize;
    uint64_t totalMessageSizeInBits;

    /* Input parameters verification. */
    if ((NULL == base) || (NULL == shaContext) || (NULL == digest))
    {
        return err;
    }

    /* SHA Process state verification. */
    if((shaContext->processState != CY_CRYPTOLITE_SHA_PROCESS_STARTED) &&
       (shaContext->processState != CY_CRYPTOLITE_SHA_PROCESS_PARTIALLY))
    {
        return CY_CRYPTOLITE_INVALID_OPERATION;
    }

    /* Check if IP is busy. */
    if ((REG_CRYPTOLITE_STATUS(base) & CRYPTOLITE_STATUS_BUSY_Msk) != 0UL)
    {
        return CY_CRYPTOLITE_HW_BUSY;
    }

    totalMessageSizeInBits = ((uint64_t)(shaContext->messageSize) + (uint64_t)(shaContext->msgIdx)) * 8U;
    /* Append one bit to end and clear rest of block. */
    shaContext->message[shaContext->msgIdx] = 0x80U;
    idx = shaContext->msgIdx + 1U;

    /* Padding with zeros for remaining SHA block size. */
    for ( ; idx < shaContext->blockSize; idx++ )
    {
        shaContext->message[idx] = 0U;
    }

    /* If message size is more than pad size process the block. */
    if (shaContext->msgIdx >= shaContext->paddSize)
    {
        err = Cy_Cryptolite_Sha_Process(base, shaContext);
        if(CY_CRYPTOLITE_SUCCESS != err)
        {
            return err;
        }
        /* Clear the message block to finish. */
        for ( idx = 0; idx < shaContext->paddSize; idx++ )
        {
            shaContext->message[idx] = 0U;
        }
    }

    /* Append total message size in bits from 57 to 64 bytes for SHA256 and from 113 to 128 bytes. */
    for(idx=0; idx < (shaContext->blockSize - shaContext->paddSize); idx++)
    {
        shaContext->message[(shaContext->blockSize - (idx + 1UL))] = (uint8_t)(totalMessageSizeInBits >> (idx*8UL));
    }

    /* Process the last block. */
    err = Cy_Cryptolite_Sha_Process(base, shaContext);
    if(CY_CRYPTOLITE_SUCCESS != err)
    {
        return err;
    }

    /* This implementation uses little endian ordering and SHA uses big endian,
       reverse all the bytes in 32bit word for SHA256 and 64bit word for
       SHA384/SHA512 when copying the final output hash.
       For SHA256, word size is: 32/8 = 4 (32bit)
       For SHA384/512, word size is: 64/8 = 8 (64bit) */
    hashPtr = (uint8_t*)shaContext->hash;
    wordSize = (uint32_t)(shaContext->hashSize >> 3u);

    /* Update the calculated digest value to the output buffer as per actual digest size. */
    for (idx = 0U; idx < shaContext->digestSize; idx += wordSize)
    {
        /* Changing endian ordering for for given word size. */
        for(byteIdx=0; byteIdx < wordSize; byteIdx++)
        {
            *(digest + byteIdx) = *(hashPtr + (wordSize - (byteIdx + 1UL)));
        }

        digest  += wordSize;
        hashPtr += wordSize;
    }

    /* Protection check for unaligned digest size with word size. */
    if (idx != shaContext->digestSize)
    {
        return CY_CRYPTOLITE_INVALID_OPERATION;
    }

    shaContext->processState = CY_CRYPTOLITE_SHA_PROCESS_FINISHED;
    return CY_CRYPTOLITE_SUCCESS;
}

/*******************************************************************************
* Cy_Cryptolite_Sha_Free
******************************************************************************
*
* Clears the used memory and context data.
*
*  base
* The pointer to the CRYPTOLITE instance.
*
*  shaContext
* the pointer to the cy_stc_cryptolite_sha_context_t structure that stores all
* internal variables for Cryptolite driver.
*
* return
* cy_en_cryptolite_status_t
*
*******************************************************************************/
ATTRIBUTES_CRYPTOLITE_SHA cy_en_cryptolite_status_t Cy_Cryptolite_Sha_Free(CRYPTOLITE_Type *base,
                                    cy_stc_cryptolite_sha_context_t *shaContext)
{
    CY_UNUSED_PARAMETER(base);

    /* Input parameters verification. */
    if (NULL == shaContext)
    {
        return CY_CRYPTOLITE_BAD_PARAMS;
    }

    /* SHA Process state verification. */
    if((shaContext->processState != CY_CRYPTOLITE_SHA_PROCESS_INITIALIZED) &&
        (shaContext->processState != CY_CRYPTOLITE_SHA_PROCESS_STARTED) &&
        (shaContext->processState != CY_CRYPTOLITE_SHA_PROCESS_PARTIALLY)&&
        (shaContext->processState != CY_CRYPTOLITE_SHA_PROCESS_FINISHED))
    {
        return CY_CRYPTOLITE_INVALID_OPERATION;
    }

    /* Clear the context memory. */
    (void)memset(shaContext->message, 0x00, CY_CRYPTOLITE_SHA_MAX_BLOCK_SIZE);
    (void)memset(shaContext->schedule, 0x00, (CY_CRYPTOLITE_SHA_MAX_SCHEDULE_SIZE*4UL));
    (void)memset(shaContext->hash, 0x00, CY_CRYPTOLITE_SHA_MAX_HASH_SIZE);

    return CY_CRYPTOLITE_SUCCESS;
}

/*******************************************************************************
* Cy_Cryptolite_Sha
********************************************************************************
*
* This function performs the SHA256 Hash function.
* Provide the required parameters and the pointer
* to the context structure when making this function call.
* It is independent of the previous Crypto state because it already contains
* preparation, calculation, and finalization steps.
*
*  base
* The pointer to the CRYPTOLITE instance.
*
*  message
* The pointer to a message whose hash value is being computed.
*
*  messageSize
* The size of a message in bytes.
*
*  digest
* The pointer to the hash digest.
*
*  shaContext
* the pointer to the cy_stc_cryptolite_sha_context_t structure that stores all
* internal variables for Cryptolite driver.
*
* return
* cy_en_cryptolite_status_t
*
* Note: Don't use this function in CCGx_CFP as the code is in ROM needs update.
* Hence, it is requested to use same flow defined in this function.
*******************************************************************************/
ATTRIBUTES_CRYPTOLITE_SHA cy_en_cryptolite_status_t Cy_Cryptolite_Sha(CRYPTOLITE_Type *base,
                                        uint8_t const *message,
                                        uint32_t  messageSize,
                                        uint8_t *digest,
                                        cy_stc_cryptolite_sha_context_t *shaContext)
{
    cy_en_cryptolite_status_t err = CY_CRYPTOLITE_BAD_PARAMS;
    /* Input parameters verification. */
    if ((NULL == base) || (NULL == shaContext) || (NULL == digest) ||
         ((NULL == message) && (0UL == messageSize)))
    {
        return err;
    }

    /* SHA block initialization. */
    err = CRYPTOLITE_SHA_CALL_MAP(Cy_Cryptolite_Sha_Init) (base, shaContext);

    if (CY_CRYPTOLITE_SUCCESS == err)
    {
        /* Start SHA calculation process. */
        err = CRYPTOLITE_SHA_CALL_MAP(Cy_Cryptolite_Sha_Start) (base, shaContext);
    }
    if (CY_CRYPTOLITE_SUCCESS == err)
    {
        /* Calculate the SHA for given input message. */
        err = CRYPTOLITE_SHA_CALL_MAP(Cy_Cryptolite_Sha_Update) (base, message, messageSize, shaContext);
    }
    if (CY_CRYPTOLITE_SUCCESS == err)
    {
        /* Finish the SHA calculation process. */
        err = CRYPTOLITE_SHA_CALL_MAP(Cy_Cryptolite_Sha_Finish) (base, digest, shaContext);
    }
    if (CY_CRYPTOLITE_SUCCESS == err)
    {
        /* Reset internal buffers in SHA context.  */
        err = CRYPTOLITE_SHA_CALL_MAP(Cy_Cryptolite_Sha_Free) (base, shaContext);
    }

    return (err);
}

#if defined(__cplusplus)
}
#endif


#endif /* (defined(CY_IP_M0S8CRYPTOLITE) && (defined (CRYPTOLITE_SHA_PRESENT) || \
     defined (CRYPTOLITE_SHA384_PRESENT) || defined (CRYPTOLITE_SHA512_PRESENT))) */


/* [] END OF FILE */
