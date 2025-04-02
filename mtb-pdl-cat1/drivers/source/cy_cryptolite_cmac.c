/***************************************************************************//**
* \file cy_cryptolite_cmac.c
* \version 2.80
*
* \brief
*  This file provides the source code to the API for the CMAC method
*  in the Cryptolite block driver.
*
*  Implementation is done in accordance with information from this weblink:
*  nvlpubs.nist.gov/nistpubs/Legacy/SP/nistspecialpublication800-38b.pdf
*
********************************************************************************
* \copyright
* Copyright (c) (2020-2022), Cypress Semiconductor Corporation (an Infineon company) or
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

#if defined(CY_IP_MXCRYPTOLITE)

#if defined(__cplusplus)
extern "C" {
#endif

#include "cy_cryptolite_cmac.h"

#if (CRYPTOLITE_AES_PRESENT == 1)
#if defined(CY_CRYPTOLITE_CFG_CMAC_C)

#include "cy_cryptolite_vu.h"

/* The bit string used to generate sub-keys */
#define CY_CRYPTOLITE_CMAC_RB  (0x87u)

static void Cy_Cryptolite_Cmac_CalcSubKey(uint8_t *srcDstPtr);

/*******************************************************************************
* Function Name: Cy_Cryptolite_Cmac_CalcSubKey
****************************************************************************//**
*
* Calculates the sub-key for the CMAC algorithm
* according to the NIST publication 800-38B, page 7.
*
* \param srcDstPtr
* The pointer to the source data for sub-key calculation, see 800-38B.
*
*******************************************************************************/
static void Cy_Cryptolite_Cmac_CalcSubKey(uint8_t *srcDstPtr)
{
    int32_t i;
    uint32_t c;
    uint32_t msb = 0UL;

    for (i = (int32_t)((int32_t)CY_CRYPTOLITE_AES_BLOCK_SIZE - 1); i >= 0; i--)
    {
        c = (uint32_t)srcDstPtr[i];
        c = (c << 1U) | msb;
        srcDstPtr[i] = (uint8_t) c;
        msb = (c >> 8U) & 1UL;
    }

    if (0UL != msb)
    {
        /* Just one byte is valuable, the rest are zeros */
        srcDstPtr[(uint8_t)(CY_CRYPTOLITE_AES_BLOCK_SIZE - 1U)] ^= CY_CRYPTOLITE_CMAC_RB;
    }
}


/*******************************************************************************
* Function Name: Cy_Cryptolite_Cmac_Init
****************************************************************************//*
*
* The function for initialization of CMAC operation.
*
* \param base
* The pointer to the CRYPTOLITE instance.
*
* \param key
* The pointer to the CMAC key.
*
* \param cmacState
* The pointer to the AES state structure allocated by the user. The user
* must not modify anything in this structure.
*
* \param aesBuffers The buffers should be a SAHB mapped addresses.
* The pointer to the memory buffers storage.
*
* \return
* \ref cy_en_cryptolite_status_t
*******************************************************************************/
cy_en_cryptolite_status_t Cy_Cryptolite_Cmac_Init(CRYPTOLITE_Type *base,
                                                 uint8_t const *key,
                                                 cy_stc_cryptolite_aes_state_t *cmacState,
                                                 cy_stc_cryptolite_aes_buffers_t *aesBuffers)
{
    cy_en_cryptolite_status_t status = CY_CRYPTOLITE_BAD_PARAMS;
    uint8_t *keyRemap;

    /* Input parameters verification */
    if ((NULL == base) || (NULL == key) || (NULL == cmacState) || (NULL == aesBuffers))
    {
        return status;
    }


    keyRemap =  (uint8_t *)CY_REMAP_ADDRESS_CRYPTOLITE(key);

    status =  Cy_Cryptolite_Aes_Init(base, keyRemap, cmacState, aesBuffers);
    if(CY_CRYPTOLITE_SUCCESS != status)
    {
        return status;
    }

    return CY_CRYPTOLITE_SUCCESS;
}



/*******************************************************************************
* Function Name: Cy_Cryptolite_Cmac_Start
****************************************************************************//*
*
* Starts CMAC calculation.
*
* \param base
* The pointer to the CRYPTOLITE instance.
*
* \param cmacState
* The pointer to the structure which stores the CMAC context.
*
* \return
* \ref cy_en_cryptolite_status_t
*******************************************************************************/
cy_en_cryptolite_status_t Cy_Cryptolite_Cmac_Start(CRYPTOLITE_Type *base, cy_stc_cryptolite_aes_state_t *cmacState)
{
    /* Input parameters verification */
    if ((NULL == base) || (NULL == cmacState))
    {
        return CY_CRYPTOLITE_BAD_PARAMS;
    }

    return Cy_Cryptolite_Aes_CbcMac_Setup(base, cmacState);
}


/*******************************************************************************
* Function Name: Cy_Cryptolite_Cmac_Update
****************************************************************************//*
*
* Performs cmac update for multi stage operation.
*
* \param base
* The pointer to the CRYPTOLITE instance.
*
* \param message
* The pointer to the message whose CMAC is being computed.
*
* \param messageSize
* The size of the message whose CMAC is being computed.
*
* \param cmacState
* The pointer to the structure which stores the CMAC context.
*
* \return
* \ref cy_en_cryptolite_status_t
*******************************************************************************/
cy_en_cryptolite_status_t Cy_Cryptolite_Cmac_Update(CRYPTOLITE_Type *base,
                                                    uint8_t const *message,
                                                    uint32_t  messageSize,
                                                    cy_stc_cryptolite_aes_state_t *cmacState)
{
    uint32_t count = 0u;
    uint32_t cnt=0u;
    cy_en_cryptolite_status_t status = CY_CRYPTOLITE_BAD_PARAMS;
    uint8_t *messageRemap;
    uint32_t processBytesCount = 0u;

    if(messageSize == 0u)
    {
        return CY_CRYPTOLITE_SUCCESS;
    }

    /* Input parameters verification */
    if ((NULL == base) || (NULL == message) || (NULL == cmacState))
    {
        return CY_CRYPTOLITE_BAD_PARAMS;
    }

    messageRemap =  (uint8_t *)CY_REMAP_ADDRESS_CRYPTOLITE(message);

    if(cmacState->unProcessedBytes == 16u)
    {
        // The size passed here has no significance as it uses the unProcessedBytes size for processing the data
        status = Cy_Cryptolite_Aes_CbcMac_Update(base, 1u, (uint8_t const *)cmacState->buffers->unProcessedData, cmacState);

        if(CY_CRYPTOLITE_SUCCESS != status)
        {
            return status;
        }
        cmacState->unProcessedBytes = 0u;
    }

    if(cmacState->unProcessedBytes > 0u && messageSize > CY_CRYPTOLITE_AES_BLOCK_SIZE-cmacState->unProcessedBytes)
    {
        processBytesCount = CY_CRYPTOLITE_AES_BLOCK_SIZE-cmacState->unProcessedBytes;
        status = Cy_Cryptolite_Aes_CbcMac_Update(base, processBytesCount, messageRemap, cmacState);

        if(CY_CRYPTOLITE_SUCCESS != status)
        {
            return status;
        }

        messageSize -= processBytesCount;
        messageRemap += processBytesCount;
    }
        
    cnt = (uint32_t)((messageSize + CY_CRYPTOLITE_AES_BLOCK_SIZE -1u) / CY_CRYPTOLITE_AES_BLOCK_SIZE);

    if(cnt > 1u)
    {
        --cnt;
        count =  cnt*CY_CRYPTOLITE_AES_BLOCK_SIZE;

        status = Cy_Cryptolite_Aes_CbcMac_Update(base, count, messageRemap, cmacState);

        if(CY_CRYPTOLITE_SUCCESS != status)
        {
            return status;
        }

        messageSize -= cnt*CY_CRYPTOLITE_AES_BLOCK_SIZE;
        messageRemap += cnt*CY_CRYPTOLITE_AES_BLOCK_SIZE;
    }

    if(messageSize > 0u)
    {
        status = CY_CRYPTOLITE_SUCCESS;
        Cy_Cryptolite_Vu_memcpy((void*)&cmacState->buffers->unProcessedData[cmacState->unProcessedBytes], messageRemap, messageSize);
        cmacState->unProcessedBytes += messageSize;
    }
    
    return status;
}



/*******************************************************************************
* Function Name: Cy_Cryptolite_Cmac_Finish
****************************************************************************//*
*
* Completes CMAC calculation.
*
* \param base
* The pointer to the CRYPTOLITE instance.
*
* \param cmac
* The pointer to the computed CMAC value.
*
* \param cmacState
* The pointer to the structure which stores the CMAC context.
*
* \return
* \ref cy_en_cryptolite_status_t
*******************************************************************************/
cy_en_cryptolite_status_t Cy_Cryptolite_Cmac_Finish(CRYPTOLITE_Type *base,  uint8_t* cmac, cy_stc_cryptolite_aes_state_t *cmacState)
{    
    CY_ALIGN(4) uint8_t subkey[16];
    CY_ALIGN(4) uint8_t zeromsg[16];
    uint32_t *keyPtr = NULL;
    uint32_t *finalMsgPtr = NULL;
    uint32_t *tempBuff = NULL;
    uint8_t *paddingRemap;

    /* Input parameters verification */
    if ((NULL == base) || (NULL == cmac) || (NULL == cmacState))
    {
        return CY_CRYPTOLITE_BAD_PARAMS;
    }

    uint8_t const p_padding[16] =
    {
        0x80u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u
    };


    paddingRemap =  (uint8_t *)CY_REMAP_ADDRESS_CRYPTOLITE(p_padding);

    cy_en_cryptolite_status_t status = CY_CRYPTOLITE_BAD_PARAMS;

    Cy_Cryptolite_Vu_memset((void *)zeromsg, 0u, sizeof(zeromsg));

    keyPtr  = (uint32_t*)((void *)subkey);
    tempBuff  = (uint32_t*)((void *)cmacState->buffers->iv);
    finalMsgPtr  = (uint32_t*)((void *)cmacState->buffers->unProcessedData);

    if(cmacState->unProcessedBytes != 16u)
    {
        Cy_Cryptolite_Vu_memcpy((void*)&cmacState->buffers->unProcessedData[cmacState->unProcessedBytes], paddingRemap, CY_CRYPTOLITE_AES_BLOCK_SIZE - cmacState->unProcessedBytes);
    }

    status = Cy_Cryptolite_Aes_Ecb(base, subkey, zeromsg, cmacState);
    if(CY_CRYPTOLITE_SUCCESS != status)
    {
        return status;
    }

    // Calculate subkey k1
    Cy_Cryptolite_Cmac_CalcSubKey(subkey);

    if(cmacState->unProcessedBytes < 16u)
    {
        // Calculate subkey k2
        Cy_Cryptolite_Cmac_CalcSubKey(subkey);
    }

    tempBuff[0] = tempBuff[0] ^ keyPtr[0] ^ finalMsgPtr[0];
    tempBuff[1] = tempBuff[1] ^ keyPtr[1] ^ finalMsgPtr[1];
    tempBuff[2] = tempBuff[2] ^ keyPtr[2] ^ finalMsgPtr[2];
    tempBuff[3] = tempBuff[3] ^ keyPtr[3] ^ finalMsgPtr[3];

    status = Cy_Cryptolite_Aes_Ecb(base, cmac, (uint8_t *)tempBuff, cmacState);

    return status;
}



/*******************************************************************************
* Function Name: Cy_Cryptolite_Cmac_Free
****************************************************************************//*
*
* Clears CMAC operation context.
*
* \param base
* The pointer to the CRYPTOLITE instance.
*
* \param cmacState
* The pointer to the AES state structure allocated by the user. The user
* must not modify anything in this structure.
*
* \return
* \ref cy_en_cryptolite_status_t
*******************************************************************************/
cy_en_cryptolite_status_t Cy_Cryptolite_Cmac_Free(CRYPTOLITE_Type *base, cy_stc_cryptolite_aes_state_t *cmacState)

{
    return Cy_Cryptolite_Aes_Free(base, cmacState);

}


/*******************************************************************************
* Function Name: Cy_Cryptolite_Cmac
****************************************************************************//*
*
* Performs CMAC(Cipher-based Message Authentication Code) operation
* on a message to produce message authentication code using AES.
**
* \param base
* The pointer to the CRYPTOLITE instance.
*
* \param message
* The pointer to a source plain text.
*
* \param messageSize
* The size of a source plain text.
*
* \param key
* The pointer to the encryption key.
*
* \param cmac
* The pointer to the calculated CMAC.
*
* \param aesState
* The pointer to the AES state structure allocated by the user. The user
* must not modify anything in this structure.
*
* \return
* \ref cy_en_cryptolite_status_t
*
*******************************************************************************/
cy_en_cryptolite_status_t Cy_Cryptolite_Cmac(CRYPTOLITE_Type *base,
                                          uint8_t  const *key,
                                          uint8_t const *message,
                                          uint32_t messageSize,
                                          uint8_t *cmac,
                                          cy_stc_cryptolite_aes_state_t *cmacState)
{

    cy_en_cryptolite_status_t status = CY_CRYPTOLITE_BAD_PARAMS;
    cy_stc_cryptolite_aes_buffers_t cmacBuffersData;
    uint8_t *keyRemap;
    uint8_t *messageRemap;

    /* Input parameters verification */
    if ((NULL == base) || (NULL == key) || ((NULL == message) && (messageSize>0u)) || (NULL == cmac) || (NULL == cmacState))
    {
        return CY_CRYPTOLITE_BAD_PARAMS;
    }

    keyRemap =  (uint8_t *)CY_REMAP_ADDRESS_CRYPTOLITE(key);
    messageRemap =  (uint8_t *)CY_REMAP_ADDRESS_CRYPTOLITE(message);

    status = Cy_Cryptolite_Cmac_Init  (base, keyRemap, cmacState, &cmacBuffersData);

    if(CY_CRYPTOLITE_SUCCESS == status)
    {
        status = Cy_Cryptolite_Cmac_Start (base, cmacState);
    }

    if(CY_CRYPTOLITE_SUCCESS == status)
    {
        status = Cy_Cryptolite_Cmac_Update(base, messageRemap, messageSize, cmacState);
    }
    
    if(CY_CRYPTOLITE_SUCCESS == status)
    {
        status = Cy_Cryptolite_Cmac_Finish(base, cmac, cmacState);
    }

    if(CY_CRYPTOLITE_SUCCESS == status)
    {
        status = Cy_Cryptolite_Cmac_Free(base, cmacState);
    }

    return (CY_CRYPTOLITE_SUCCESS);
}

#endif /* defined(CY_CRYPTOLITE_CFG_CMAC_C) */
#endif /* (CRYPTOLITE_AES_PRESENT == 1) */

#if defined(__cplusplus)
}
#endif


#endif /* defined(CY_IP_MXCRYPTOLITE) */


/* [] END OF FILE */
