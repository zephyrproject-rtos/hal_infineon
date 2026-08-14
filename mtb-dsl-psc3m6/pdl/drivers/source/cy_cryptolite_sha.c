/***************************************************************************//**
* \file cy_cryptolite_sha.c
* \version 2.50
*
* \brief
*  Provides API implementation of the Cryptolite SHA256,384,512 PDL driver.
*
********************************************************************************
* \copyright
* (c) 2024-2026, Infineon Technologies AG or an affiliate of
* Infineon Technologies AG.
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
#if ((CY_IP_MXCRYPTOLITE_VERSION >=1) && (CY_IP_MXCRYPTOLITE_VERSION_MINOR >=2))

#include "cy_cryptolite_sha.h"
#include "cy_cryptolite_utils.h"

#if defined(__cplusplus)
extern "C" {
#endif

#if (CRYPTOLITE_SHA_PRESENT == 1)
#if defined(CY_CRYPTOLITE_CFG_SHA_C) && (defined(CY_CRYPTOLITE_CFG_SHA2_256_ENABLED) || defined(CY_CRYPTOLITE_CFG_SHA2_384_ENABLED) || defined(CY_CRYPTOLITE_CFG_SHA2_512_ENABLED))

#if defined(CY_CRYPTOLITE_CFG_SHA2_256_ENABLED)
/*Initial Hash*/
static const uint32_t sha256InitHash[] =
{
    0x6A09E667uL, 0xBB67AE85uL, 0x3C6EF372uL, 0xA54FF53AuL,
    0x510E527FuL, 0x9B05688CuL, 0x1F83D9ABuL, 0x5BE0CD19uL
};
#endif

#if defined(CY_CRYPTOLITE_CFG_SHA2_384_ENABLED)
static const uint32_t sha384InitHash[] =
{
    0xC1059ED8UL, 0xCBBB9D5DUL, 0x367CD507UL, 0x629A292AUL,
    0x3070DD17UL, 0x9159015AUL, 0xF70E5939UL, 0x152FECD8UL,
    0xFFC00B31UL, 0x67332667UL, 0x68581511UL, 0x8EB44A87UL,
    0x64F98FA7UL, 0xDB0C2E0DUL, 0xBEFA4FA4UL, 0x47B5481DUL

};
#endif

#if defined(CY_CRYPTOLITE_CFG_SHA2_512_ENABLED)
static const uint32_t sha512InitHash[] =
{
    0xF3BCC908UL, 0x6A09E667UL, 0x84CAA73BUL, 0xBB67AE85UL,
    0xFE94F82BUL, 0x3C6EF372UL, 0x5F1D36F1UL, 0xA54FF53AUL,
    0xADE682D1UL, 0x510E527FUL, 0x2B3E6C1FUL, 0x9B05688CUL,
    0xFB41BD6BUL, 0x1F83D9ABUL, 0x137E2179UL, 0x5BE0CD19UL
};
#endif

/*****************************************************************************
* Cy_Cryptolite_Sha_Process (for internal use)
******************************************************************************
*
* The function starts the hash calculation, blocks until finished.
*
*  base
* The pointer to the Cryptolite instance.
*
*  cfContext
* The pointer to the cy_stc_cryptolite_context_sha_t structure that stores all
* internal variables for Cryptolite driver.
*
* return
* cy_en_cryptolite_status_t
*
*******************************************************************************/
static cy_en_cryptolite_status_t Cy_Cryptolite_Sha_Process(CRYPTOLITE_Type *base,
                                        cy_stc_cryptolite_context_sha_t *cfContext)
{
    /*write to SHA DESCR REG starts process
      IP will block another write to SHA DESCR REG until its busy
      We poll for busy state and check for error before posting next
      descriptor */

    /*start message schedule*/
    /* DSB ensures all pending writes (descriptor fields,
       message buffer ) are committed before the IP engine reads them. */
    __DSB();

    REG_CRYPTOLITE_SHA_DESCR(base) = (uint32_t)&(cfContext->message_schedule_struct);
    while((REG_CRYPTOLITE_STATUS(base) & CRYPTOLITE_STATUS_BUSY_Msk) != 0UL) {};

    /*start process*/
    REG_CRYPTOLITE_SHA_DESCR(base) = (uint32_t)&(cfContext->message_process_struct);
    while((REG_CRYPTOLITE_STATUS(base) & CRYPTOLITE_STATUS_BUSY_Msk) != 0UL) {};

    if((REG_CRYPTOLITE_SHA_INTR_ERROR(base) & CRYPTOLITE_INTR_ERROR_BUS_ERROR_Msk) != 0UL)
    {
        REG_CRYPTOLITE_SHA_INTR_ERROR(base) = CRYPTOLITE_INTR_ERROR_BUS_ERROR_Msk;
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
*  cfContext
* The pointer to the cy_stc_cryptolite_context_sha_t structure that stores all
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
static cy_en_cryptolite_status_t Cy_Cryptolite_Sha_Process_aligned(CRYPTOLITE_Type *base,
                                        cy_stc_cryptolite_context_sha_t *cfContext,
                                        uint8_t const *message,
                                        uint32_t  *messageSize)
{
    cy_en_cryptolite_status_t err;
    uint32_t processed;

    /*point descriptor to message buffer*/
    cfContext->message_schedule_struct.data1 = (uint32_t)message;

    while(*messageSize >= cfContext->blockSize)
    {
        err = Cy_Cryptolite_Sha_Process(base, cfContext);
        if(CY_CRYPTOLITE_SUCCESS != err)
        {
            cfContext->message_schedule_struct.data1 = (uint32_t)cfContext->message;
            return err;
        }
        *messageSize -= cfContext->blockSize;
        cfContext->message_schedule_struct.data1 += cfContext->blockSize;
    }

    processed = cfContext->message_schedule_struct.data1 - (uint32_t)message;
    cfContext->messageSize += processed;

    /*restore descriptor to context buffer*/
    cfContext->message_schedule_struct.data1 = (uint32_t)cfContext->message;

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
*  cfContext
* The pointer to the cy_stc_cryptolite_context_sha_t structure that stores all
* internal variables for Cryptolite driver.
*
* return
* cy_en_cryptolite_status_t
*
*******************************************************************************/
cy_en_cryptolite_status_t Cy_Cryptolite_Sha_Init(CRYPTOLITE_Type *base, cy_en_cryptolite_sha_mode_t mode,
                                        cy_stc_cryptolite_context_sha_t *cfContext)
{
    /* Input parameters verification */
    if ((NULL == base) || (NULL == cfContext))
    {
        return CY_CRYPTOLITE_BAD_PARAMS;
    }

    cfContext->message = (uint8_t*)cfContext->msgblock;
    cfContext->message_schedule_struct.data0 = (uint32_t)CY_CRYPTOLITE_MSG_SCH_CTLWD;
    cfContext->message_schedule_struct.data1 = (uint32_t)cfContext->message;
    cfContext->message_schedule_struct.data2 = (uint32_t)cfContext->message_schedule;

    cfContext->message_process_struct.data0 = (uint32_t)CY_CRYPTOLITE_PROCESS_CTLWD;
    cfContext->message_process_struct.data1 = (uint32_t)cfContext->hash;
    cfContext->message_process_struct.data2 = (uint32_t)cfContext->message_schedule;

    cfContext->shaMode = mode;


    return (CY_CRYPTOLITE_SUCCESS);
}


static inline void Cy_Enable_Sha_Mode(CRYPTOLITE_Type *base, cy_stc_cryptolite_context_sha_t *cfContext)
{
    uint32_t shaSel = _FLD2VAL(CRYPTOLITE_CTL_SHA_SEL, REG_CRYPTOLITE_CTL(base));
    uint32_t shaSelUpdate =  (cfContext->shaMode == CY_CRYPTOLITE_MODE_SHA256) ? 0x01UL :
                                (cfContext->shaMode == CY_CRYPTOLITE_MODE_SHA384) ? 0x02UL :
                                (cfContext->shaMode == CY_CRYPTOLITE_MODE_SHA512) ? 0x03UL : 0x0UL;

    if ((shaSel != shaSelUpdate) && (shaSelUpdate != 0x0UL))
    {
        REG_CRYPTOLITE_CTL(base) = (REG_CRYPTOLITE_CTL(base) & ~CRYPTOLITE_CTL_SHA_SEL_Msk) | _VAL2FLD(CRYPTOLITE_CTL_SHA_SEL, shaSelUpdate);
    }

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
*  cfContext
* The pointer to the cy_stc_cryptolite_context_sha_t structure that stores all
* internal variables for Cryptolite driver.
*
* return
* cy_en_cryptolite_status_t
*
*******************************************************************************/
cy_en_cryptolite_status_t Cy_Cryptolite_Sha_Start(CRYPTOLITE_Type *base,
                                        cy_stc_cryptolite_context_sha_t *cfContext)
{
    cy_en_cryptolite_status_t status = CY_CRYPTOLITE_SUCCESS;
    uint32_t const * initialhash = NULL;

    /* Input parameters verification */
    if ((NULL == base) || (NULL == cfContext))
    {
        status = CY_CRYPTOLITE_BAD_PARAMS;
    }
    else
    {
        /* Check if IP is busy */
        if ((REG_CRYPTOLITE_STATUS(base) & CRYPTOLITE_STATUS_BUSY_Msk) != 0UL)
        {
            status = CY_CRYPTOLITE_HW_BUSY;
        }
    }

    if (status == CY_CRYPTOLITE_SUCCESS)
    {
        cfContext->msgIdx = 0U;
        cfContext->messageSize = 0U;
        switch(cfContext->shaMode)
        {
    #if defined(CY_CRYPTOLITE_CFG_SHA2_256_ENABLED)
            case CY_CRYPTOLITE_MODE_SHA256:
                    initialhash = sha256InitHash;
                    cfContext->blockSize = CY_CRYPTOLITE_SHA256_BLOCK_SIZE;
                    cfContext->hashSize = CY_CRYPTOLITE_SHA256_HASH_SIZE;
                    cfContext->padSize = CY_CRYPTOLITE_SHA256_PAD_SIZE;
                    cfContext->messageScheduleSize = CY_CRYPTOLITE_SHA256_MESSAGE_SCHEDULE_SIZE;
                    break;
    #endif
    #if defined(CY_CRYPTOLITE_CFG_SHA2_384_ENABLED)
            case CY_CRYPTOLITE_MODE_SHA384:
                    initialhash = sha384InitHash;
                    cfContext->blockSize = CY_CRYPTOLITE_SHA512_BLOCK_SIZE;
                    cfContext->hashSize = CY_CRYPTOLITE_SHA384_HASH_SIZE;
                    cfContext->padSize = CY_CRYPTOLITE_SHA512_PAD_SIZE;
                    cfContext->messageScheduleSize = CY_CRYPTOLITE_512_MESSAGE_SCHEDULE_SIZE;
                    break;
    #endif
    #if defined(CY_CRYPTOLITE_CFG_SHA2_512_ENABLED)
            case CY_CRYPTOLITE_MODE_SHA512:
                    initialhash = sha512InitHash;
                    cfContext->blockSize = CY_CRYPTOLITE_SHA512_BLOCK_SIZE;
                    cfContext->hashSize = CY_CRYPTOLITE_SHA512_HASH_SIZE;
                    cfContext->padSize = CY_CRYPTOLITE_SHA512_PAD_SIZE;
                    cfContext->messageScheduleSize = CY_CRYPTOLITE_512_MESSAGE_SCHEDULE_SIZE;
                    break;
    #endif
            default:
                    status = CY_CRYPTOLITE_BAD_PARAMS;
                    break;
        }
    }

    if (status == CY_CRYPTOLITE_SUCCESS)
    {
        /* Copy initial hash */
        for (uint32_t i = 0UL; i < (cfContext->blockSize/2UL) / 4UL; i++)
        {
            cfContext->hash[i] = initialhash[i];
        }
    }

    return status;
}


/*******************************************************************************
* Cy_Cryptolite_Sha_Update
********************************************************************************
*
* Performs the SHA256 calculation on one message.
*
*  base
* The pointer to the CRYPTOLITE instance.
*
*  cfContext
* The pointer to the cy_stc_cryptolite_context_sha_t structure that stores all
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
cy_en_cryptolite_status_t Cy_Cryptolite_Sha_Update(CRYPTOLITE_Type *base,
                                        uint8_t const *message,
                                        uint32_t  messageSize,
                                        cy_stc_cryptolite_context_sha_t *cfContext)
{
    cy_en_cryptolite_status_t err = CY_CRYPTOLITE_BAD_PARAMS;
    uint32_t readIdx = 0U;
    uint32_t msg_add = (uint32)message;
    uint32_t lmessageSize;
    uint8_t *messageRemap;

    if (0UL == messageSize)
    {
        return CY_CRYPTOLITE_SUCCESS;
    }

    /* Input parameters verification */
    if ((NULL == base) || (NULL == cfContext) || (NULL == message))
    {
        return err;
    }

    /* Check if IP is busy */
    if ((REG_CRYPTOLITE_STATUS(base) & CRYPTOLITE_STATUS_BUSY_Msk) != 0UL)
    {
        return CY_CRYPTOLITE_HW_BUSY;
    }

    Cy_Enable_Sha_Mode(base, cfContext);

    messageRemap =  (uint8_t *)CY_REMAP_ADDRESS_CRYPTOLITE(message);
    lmessageSize = messageSize;

    /* Check for 4 byte aligned buffer and process */
    if((msg_add & 0x3UL) == 0UL)
    {
        /* Check for fragmented message and size */
        if ((cfContext->msgIdx == 0UL) && (messageSize >= cfContext->blockSize))
        {
            err = Cy_Cryptolite_Sha_Process_aligned(base, cfContext, messageRemap, &lmessageSize);
            if(CY_CRYPTOLITE_SUCCESS != err)
            {
                return err;
            }
            readIdx = messageSize - lmessageSize;
        }
    }

    while((cfContext->msgIdx + lmessageSize) >= cfContext->blockSize)
    {
        uint32_t tocopy = cfContext->blockSize - cfContext->msgIdx;

        err = Cy_Cryptolite_Memcpy(base, &cfContext->message[cfContext->msgIdx], (uint8_t *)&messageRemap[readIdx], tocopy);

        if(CY_CRYPTOLITE_SUCCESS != err)
        {
            return err;
        }
        readIdx += tocopy;
        cfContext->msgIdx += tocopy;

        /* calculate message schedule and process */
        err = Cy_Cryptolite_Sha_Process(base, cfContext);
        if(CY_CRYPTOLITE_SUCCESS != err)
        {
            return err;
        }
        lmessageSize-= tocopy;
        cfContext->messageSize+= cfContext->blockSize;
        cfContext->msgIdx = 0U;
    }

    err = Cy_Cryptolite_Memcpy(base, &cfContext->message[cfContext->msgIdx], (uint8_t *)&messageRemap[readIdx], lmessageSize);

    if(CY_CRYPTOLITE_SUCCESS != err)
    {
        return err;
    }
    cfContext->msgIdx += lmessageSize;

    return CY_CRYPTOLITE_SUCCESS;
}

/*******************************************************************************
* Cy_Cryptolite_Sha_Finish
******************************************************************************
*
* Completes the SHA256 calculation.
*
*  base
* The pointer to the CRYPTOLITE instance.
*
*  cfContext
* the pointer to the cy_stc_cryptolite_context_sha_t structure that stores all
* internal variables for Cryptolite driver.
*
*  digest
* The pointer to the calculated Hash digest.
*
* return
* cy_en_cryptolite_status_t
*
*******************************************************************************/
cy_en_cryptolite_status_t Cy_Cryptolite_Sha_Finish(CRYPTOLITE_Type *base,
                                    uint8_t *digest,
                                    cy_stc_cryptolite_context_sha_t *cfContext)
{
    cy_en_cryptolite_status_t err = CY_CRYPTOLITE_BAD_PARAMS;
    uint8_t *hashptr;
    uint32_t idx,idx1, shaSwapLength;
    uint32_t idx2;
    uint64_t totalMessageSizeInBits;

    /* Input parameters verification */
    if ((NULL == base) || (NULL == cfContext) || (NULL == digest))
    {
        return err;
    }

    /*check if IP is busy*/
    if ((REG_CRYPTOLITE_STATUS(base) & CRYPTOLITE_STATUS_BUSY_Msk) != 0UL)
    {
        return CY_CRYPTOLITE_HW_BUSY;
    }

    Cy_Enable_Sha_Mode(base, cfContext);

    shaSwapLength = cfContext->blockSize/16UL;

    totalMessageSizeInBits = (cfContext->messageSize + (uint64_t)(cfContext->msgIdx)) * 8U;
    /*Append one bit to end and clear rest of block*/
    cfContext->message[cfContext->msgIdx] = 0x80U;
    idx = cfContext->msgIdx + 1U;

    for ( ; idx < cfContext->blockSize; idx++ )
    {
        cfContext->message[idx] = 0U;
    }

    /*if message size is more than pad size process the block*/
    if (cfContext->msgIdx >= cfContext->padSize)
    {
        err = Cy_Cryptolite_Sha_Process(base, cfContext);
        if(CY_CRYPTOLITE_SUCCESS != err)
        {
            return err;
        }
        /*clear the message block to finish*/
        for ( idx = 0; idx < cfContext->padSize; idx++ )
        {
            cfContext->message[idx] = 0U;
        }
    }

    for ( idx = 0; idx < shaSwapLength*2UL; idx++ )
    {
        cfContext->message[cfContext->blockSize - (idx + 1UL)] = (uint8_t)(totalMessageSizeInBits >> (idx*8UL));
    }

    /*Process the last block*/
    err = Cy_Cryptolite_Sha_Process(base, cfContext);
    if(CY_CRYPTOLITE_SUCCESS != err)
    {
        return err;
    }

    /* This implementation uses little endian ordering and SHA uses big endian,
       reverse all the bytes in 32bit word for sha256 and 64bit word for sha384/512 when copying the final output hash.*/
    hashptr = (uint8_t*)cfContext->hash;

    for(idx = (uint32_t)(cfContext->hashSize / shaSwapLength); idx != 0U; idx--)
    {
        idx2 = shaSwapLength-1UL;
        for(idx1=0UL; idx1<shaSwapLength; idx1++)
        {
            *(digest + idx1) = *(hashptr + idx2);
            idx2--;
        }

        digest  += shaSwapLength;
        hashptr += shaSwapLength;
    }

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
*  cfContext
* the pointer to the cy_stc_cryptolite_context_sha_t structure that stores all
* internal variables for Cryptolite driver.
*
* return
* cy_en_cryptolite_status_t
*
*******************************************************************************/
cy_en_cryptolite_status_t Cy_Cryptolite_Sha_Free(CRYPTOLITE_Type *base,
                                    cy_stc_cryptolite_context_sha_t *cfContext)
{
    uint32_t idx;
    (void)base;

    /* Input parameters verification */
    if (NULL != cfContext)
    {
        /* Clear the context memory */
        for ( idx = 0; idx < cfContext->messageScheduleSize; idx++ )
        {
            cfContext->message_schedule[idx] = 0U;
        }

        for ( idx = 0; idx < (cfContext->blockSize / 4u) + 1u ; idx++ )
        {
            cfContext->msgblock[idx] = 0U;
        }

        for ( idx = 0; idx < cfContext->hashSize/4U ; idx++ )
        {
            cfContext->hash[idx] = 0U;
        }
    }

    return CY_CRYPTOLITE_SUCCESS;
}

/*******************************************************************************
* Cy_Cryptolite_Sha_Run
******************************************************************************
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
*  cfContext
* the pointer to the cy_stc_cryptolite_context_sha_t structure that stores all
* internal variables for Cryptolite driver.
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
* return
* cy_en_cryptolite_status_t
*
*******************************************************************************/
cy_en_cryptolite_status_t Cy_Cryptolite_Sha_Run(CRYPTOLITE_Type *base, cy_en_cryptolite_sha_mode_t mode,
                                        uint8_t const *message,
                                        uint32_t  messageSize,
                                        uint8_t *digest,
                                        cy_stc_cryptolite_context_sha_t *cfContext)
{
    cy_en_cryptolite_status_t err = CY_CRYPTOLITE_BAD_PARAMS;
    /* Input parameters verification */
    if ((NULL == base) || (NULL == cfContext) || (NULL == digest) || ((NULL == message) && (0UL != messageSize)))
    {
        return err;
    }

    err = Cy_Cryptolite_Sha_Init (base, mode, cfContext);

    if (CY_CRYPTOLITE_SUCCESS == err)
    {
        err = Cy_Cryptolite_Sha_Start (base, cfContext);
    }
    if (CY_CRYPTOLITE_SUCCESS == err)
    {
        err = Cy_Cryptolite_Sha_Update (base, message, messageSize, cfContext);
    }
    if (CY_CRYPTOLITE_SUCCESS == err)
    {
        err = Cy_Cryptolite_Sha_Finish (base, digest, cfContext);
    }
    if (CY_CRYPTOLITE_SUCCESS == err)
    {
        err = Cy_Cryptolite_Sha_Free (base, cfContext);
    }

    return (err);
}

#endif
#endif

#if defined(__cplusplus)
}
#endif

#endif
#endif /* CY_IP_MXCRYPTOLITE */


/* [] END OF FILE */
