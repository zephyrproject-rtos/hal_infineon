/***************************************************************************//**
* \file cy_cryptolite_aes.c
* \version 2.30
*
* \brief
*  Provides API implementation of the Cryptolite AES PDL driver.
*
********************************************************************************
* \copyright
* Copyright (c) 2022, Cypress Semiconductor Corporation (an Infineon company) or
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

#include "cy_cryptolite_aes.h"
#include "cy_cryptolite_vu.h"

#if defined(__cplusplus)
extern "C" {
#endif


#if (CRYPTOLITE_AES_PRESENT == 1)
#if defined(CY_CRYPTOLITE_CFG_AES_C) 

/*******************************************************************************
* Function Name: Cy_Cryptolite_Aes_ProcessBlock
****************************************************************************//*
*
* Performs the AES block cipher.
*
* \param base
* The pointer to the CRYPTOLITE instance.
*
* \param aesState
* the pointer to the cy_stc_cryptolite_aes_state_t structure that stores all
* internal variables for Cryptolite driver.
*
* \param dstBlock
* The pointer to the cipher text.
*
* \param srcBlock
* The pointer to the plain text. Must be 4-Byte aligned!
*
* \return
* \ref cy_en_cryptolite_status_t
*******************************************************************************/
cy_en_cryptolite_status_t Cy_Cryptolite_Aes_ProcessBlock(CRYPTOLITE_Type *base,
                            cy_stc_cryptolite_aes_state_t *aesState,
                            uint32_t *dstBlock,
                            uint32_t const *srcBlock)
{

    aesState->message_encrypt_struct.plainText = (uint32_t)srcBlock;
    aesState->message_encrypt_struct.cipherText = (uint32_t)dstBlock;

    /*check if IP is busy*/
    if ((REG_CRYPTOLITE_STATUS(base) & CRYPTOLITE_STATUS_BUSY_Msk) == 1U)
    {
        return CY_CRYPTOLITE_HW_BUSY;
    }

    REG_CRYPTOLITE_AES_DESCR(base) = (uint32_t)&(aesState->message_encrypt_struct);
    while((REG_CRYPTOLITE_STATUS(base) & CRYPTOLITE_STATUS_BUSY_Msk) == 1U){};

    if((REG_CRYPTOLITE_INTR_ERROR(base) & CRYPTOLITE_INTR_ERROR_BUS_ERROR_Msk) == 1U)
    {
        REG_CRYPTOLITE_INTR_ERROR(base) = CRYPTOLITE_INTR_ERROR_BUS_ERROR_Msk;
        return CY_CRYPTOLITE_BUS_ERROR;
    }

    return CY_CRYPTOLITE_SUCCESS;
}


/*******************************************************************************
* Function Name: Cy_Cryptolite_Aes_Init
****************************************************************************//*
*
* Sets AES mode.
*
* \param base
* The pointer to the CRYPTOLITE instance.
*
* \param key
* The pointer to the encryption/decryption key.
*
* \param aesState
* The pointer to the AES state structure allocated by the user. The user
* must not modify anything in this structure.
*
* \param aesBuffers The buffers should be a SAHB mapped addresses.
* The pointer to the memory buffers storage.
*
* \return
* \ref cy_en_cryptolite_status_t
*
*******************************************************************************/
cy_en_cryptolite_status_t Cy_Cryptolite_Aes_Init(CRYPTOLITE_Type *base,
                                                 uint8_t const *key,
                                                 cy_stc_cryptolite_aes_state_t *aesState,
                                                 cy_stc_cryptolite_aes_buffers_t *aesBuffers)
{
    (void)base;
    cy_en_cryptolite_status_t err = CY_CRYPTOLITE_BAD_PARAMS;
    uint32_t address_offset=0u;

    /* Input parameters verification */
    if ((NULL == base) || (NULL == key) || (NULL == aesState) || (NULL == aesBuffers))
    {
        return err;
    }

    /*check if IP is busy*/
    if ((REG_CRYPTOLITE_STATUS(base) & CRYPTOLITE_STATUS_BUSY_Msk) != 0UL)
    {
        return CY_CRYPTOLITE_HW_BUSY;
    }

    /*Aligning the buffer address by 4 bytes*/
    if(((uint32_t)aesBuffers & 0x03U) != 0u)
    {
        address_offset = 4u - ((uint32_t)aesBuffers & 0x03U);
    }
 
    aesState->buffers = (cy_stc_cryptolite_aes_buffers_t *)((uint32_t)aesBuffers + address_offset);

    /* Copy the cipher block to the Initialization Vector */
    Cy_Cryptolite_Vu_memcpy((uint8_t *)aesState->buffers->key, key, CY_CRYPTOLITE_AES_128_KEY_SIZE);
    aesState->message_encrypt_struct.key = (uint32_t)aesState->buffers->key;

    return CY_CRYPTOLITE_SUCCESS;
}

/*******************************************************************************
* Function Name: Cy_Cryptolite_Aes_Free
****************************************************************************//*
*
* Clears AES operation context.
*
* \param base
* The pointer to the CRYPTOLITE instance.
*
* \param aesState
* The pointer to the AES state structure allocated by the user. The user
* must not modify anything in this structure.
*
* \return
* \ref cy_en_cryptolite_status_t
*
*******************************************************************************/
cy_en_cryptolite_status_t Cy_Cryptolite_Aes_Free(CRYPTOLITE_Type *base, cy_stc_cryptolite_aes_state_t *aesState)
{
    (void)base;

    if(NULL != aesState)
    {
        Cy_Cryptolite_Vu_memset((void *)aesState->buffers, 0u, sizeof(cy_stc_cryptolite_aes_buffers_t));
        Cy_Cryptolite_Vu_memset((void *)aesState, 0u, sizeof(cy_stc_cryptolite_aes_state_t));
    }

    return CY_CRYPTOLITE_SUCCESS;
}

/*******************************************************************************
* Function Name: Cy_Cryptolite_Aes_Ecb
****************************************************************************//*
*
* Performs an AES Encryption operation on one block.
*
* \param base
* The pointer to the CRYPTOLITE instance.
*
*
* \param dst
* The pointer to a destination cipher block, must be 4 byte aligned and should be a SAHB mapped addresses.
*
* \param src
* The pointer to a source block, must be 4 byte aligned and should be a SAHB mapped addresses
*
*
* \param aesState
* The pointer to the AES state structure allocated by the user. The user
* must not modify anything in this structure.
*
* \return
* \ref cy_en_cryptolite_status_t
*
*******************************************************************************/
cy_en_cryptolite_status_t Cy_Cryptolite_Aes_Ecb(CRYPTOLITE_Type *base,
                                            uint8_t *dst,
                                            uint8_t const *src,
                                            cy_stc_cryptolite_aes_state_t *aesState)
{

    cy_en_cryptolite_status_t status = CY_CRYPTOLITE_BAD_PARAMS;


    /* Input parameters verification */
    if ((NULL == base) || (NULL == dst) || (NULL == src) || (NULL == aesState))
    {
        return status;
    }

    /* Checking the address alignment */
    if((((uint32_t)dst & 0x03U) != 0u) || (((uint32_t)src & 0x03U) != 0u))
    {
        return CY_CRYPTOLITE_ALIGNMENT_ERROR;
    }

    /*check if IP is busy*/
    if ((REG_CRYPTOLITE_STATUS(base) & CRYPTOLITE_STATUS_BUSY_Msk) != 0UL)
    {
        return CY_CRYPTOLITE_HW_BUSY;
    }

    status = Cy_Cryptolite_Aes_ProcessBlock(base, aesState, (uint32_t*)((void*)dst), (uint32_t*)((void*)src));

    return status;
}


#if defined(CY_CRYPTOLITE_CFG_CIPHER_MODE_CBC)
/*******************************************************************************
* Function Name: Cy_Cryptolite_Aes_Cbc
****************************************************************************//*
*
* Performs AES Encryption operation on a plain text with Cipher Block Chaining (CBC).
*
* \param base
* The pointer to the CRYPTOLITE instance.
*
* \param srcSize
* The size of the source plain text.
*
* \param ivPtr
* The pointer to the initial vector.
*
* \param dst
* The pointer to a destination cipher text, must be 4 byte aligned and should be a SAHB mapped addresses.
*
* \param src
* The pointer to a source plain text.
*
* \param aesState
* The pointer to the AES state structure allocated by the user. The user
* must not modify anything in this structure.
*
* \return
* \ref cy_en_cryptolite_status_t
*
*******************************************************************************/
cy_en_cryptolite_status_t Cy_Cryptolite_Aes_Cbc(CRYPTOLITE_Type *base,
                                            uint32_t srcSize,
                                            uint8_t *ivPtr,
                                            uint8_t *dst,
                                            uint8_t const *src,
                                            cy_stc_cryptolite_aes_state_t *aesState)
{
    uint32_t size = srcSize;
    cy_stc_cryptolite_aes_buffers_t *aesBuffers = NULL;
    uint32_t *srcBuff = NULL;
    uint32_t *dstBuff = NULL;
    uint32_t *tempBuff = NULL;

    cy_en_cryptolite_status_t tmpResult = CY_CRYPTOLITE_BAD_PARAMS;

    /* Input parameters verification */
    if ((NULL == base) || (NULL == ivPtr) || (NULL == dst) || (NULL == src) || (NULL == aesState))
    {
        return tmpResult;
    }

    /* Checking the address alignment */
    if((((uint32_t)dst & 0x03U) != 0u) || (((uint32_t)src & 0x03U) != 0u))
    {
        return CY_CRYPTOLITE_ALIGNMENT_ERROR;
    }

    /*check if IP is busy*/
    if ((REG_CRYPTOLITE_STATUS(base) & CRYPTOLITE_STATUS_BUSY_Msk) != 0UL)
    {
        return CY_CRYPTOLITE_HW_BUSY;
    }

    aesBuffers = (cy_stc_cryptolite_aes_buffers_t*)aesState->buffers;
    srcBuff  = (uint32_t*)((void *)src);
    dstBuff  = (uint32_t*)((void *)dst);
    tempBuff = (uint32_t*)(aesBuffers->block0);

    tmpResult = CY_CRYPTOLITE_SIZE_NOT_X16;

    /* Check whether the data size is multiple of CY_CRYPTOLITE_AES_BLOCK_SIZE */
    if (0UL == (uint32_t)(size & (CY_CRYPTOLITE_AES_BLOCK_SIZE - 1U)))
    {
        /* Copy the Initialization Vector to the local buffer because it changes during calculation */
        Cy_Cryptolite_Vu_memcpy((uint8_t *)tempBuff, ivPtr, CY_CRYPTOLITE_AES_BLOCK_SIZE);

        while (size != 0UL)
        {

            tempBuff[0] = srcBuff[0] ^ tempBuff[0];
            tempBuff[1] = srcBuff[1] ^ tempBuff[1];
            tempBuff[2] = srcBuff[2] ^ tempBuff[2];
            tempBuff[3] = srcBuff[3] ^ tempBuff[3];

            tmpResult = Cy_Cryptolite_Aes_ProcessBlock(base, aesState, dstBuff, tempBuff);

            if(CY_CRYPTOLITE_SUCCESS != tmpResult){
                break;
            }
            /* temporary cipher block */
            Cy_Cryptolite_Vu_memcpy(tempBuff, dstBuff, CY_CRYPTOLITE_AES_BLOCK_SIZE);

            srcBuff  += CY_CRYPTOLITE_AES_MAX_KEY_SIZE_U32;
            dstBuff  += CY_CRYPTOLITE_AES_MAX_KEY_SIZE_U32;
            size -= CY_CRYPTOLITE_AES_BLOCK_SIZE;
        }

        if(CY_CRYPTOLITE_SUCCESS == tmpResult)
        {
            /* Copy the cipher block to the Initialization Vector */
            Cy_Cryptolite_Vu_memcpy(ivPtr, tempBuff, CY_CRYPTOLITE_AES_BLOCK_SIZE);
        }


    }

    return (tmpResult);
}
#endif /*CY_CRYPTOLITE_CFG_CIPHER_MODE_CBC*/


#if defined(CY_CRYPTOLITE_CFG_CIPHER_MODE_CFB)
/*******************************************************************************
* Function Name: Cy_Cryptolite_Aes_Cfb
********************************************************************************
*
* Performs AES Encryption/Decryption operation on a data with the Cipher Feedback Block method (CFB).
*
* \param base
* The pointer to the CRYPTOLITE instance.
*
*
* \param dirMode
* Can be \ref CY_CRYPTOLITE_ENCRYPT or \ref CY_CRYPTOLITE_DECRYPT
* (\ref cy_en_crypto_dir_mode_t)
*
* \param srcSize
* The size of the source plain text.
*
* \param ivPtr
* The pointer to the initial vector.
*
* \param dst
* The pointer to a destination cipher text.
*
* \param src
* The pointer to a source plain text.
*
* \param aesState
* The pointer to the AES state structure allocated by the user. The user must
* must not modify anything in this structure.
*
* \return
* \ref cy_en_cryptolite_status_t
*
*******************************************************************************/
cy_en_cryptolite_status_t Cy_Cryptolite_Aes_Cfb(CRYPTOLITE_Type *base,
                                             cy_en_cryptolite_dir_mode_t dirMode,
                                             uint32_t srcSize,
                                             uint8_t *ivPtr,
                                             uint8_t *dst,
                                             uint8_t const *src,
                                             cy_stc_cryptolite_aes_state_t *aesState)
{
    uint32_t size = srcSize;
    uint32_t *srcBuff = NULL;
    uint32_t *dstBuff = NULL;
    uint32_t *tempBuff = NULL;
    uint32_t *tempBuff1 = NULL;

    cy_stc_cryptolite_aes_buffers_t *aesBuffers = NULL;
    cy_en_cryptolite_status_t tmpResult = CY_CRYPTOLITE_BAD_PARAMS;

    /* Input parameters verification */
    if ((NULL == base) || (NULL == ivPtr) || (NULL == dst) || (NULL == src) || (NULL == aesState))
    {
        return tmpResult;
    }

    /* Checking the address alignment */
    if((((uint32_t)dst & 0x03U) != 0u) || (((uint32_t)src & 0x03U) != 0u))
    {
        return CY_CRYPTOLITE_ALIGNMENT_ERROR;
    }

    /*check if IP is busy*/
    if ((REG_CRYPTOLITE_STATUS(base) & CRYPTOLITE_STATUS_BUSY_Msk) != 0UL)
    {
        return CY_CRYPTOLITE_HW_BUSY;
    }
    
    tmpResult = CY_CRYPTOLITE_SIZE_NOT_X16;

    aesBuffers = (cy_stc_cryptolite_aes_buffers_t*)aesState->buffers;
    srcBuff  = (uint32_t*)((void *)src);
    dstBuff  = (uint32_t*)((void *)dst);
    tempBuff = (uint32_t*)(aesBuffers->block0);
    tempBuff1 = (uint32_t*)(aesBuffers->block1);

    /* Check whether the data size is multiple of CY_CRYPTOLITE_AES_BLOCK_SIZE */
    if (0UL == (size & (CY_CRYPTOLITE_AES_BLOCK_SIZE - 1U)))
    {

        /* Copies the Initialization Vector to the local encode buffer. */
        Cy_Cryptolite_Vu_memcpy(tempBuff, ivPtr, CY_CRYPTOLITE_AES_BLOCK_SIZE);

        while (size != 0UL)
        {
            /* In this mode, (CFB) is always an encryption! */
            tmpResult = Cy_Cryptolite_Aes_ProcessBlock(base, aesState, tempBuff1, tempBuff);

            if(CY_CRYPTOLITE_SUCCESS != tmpResult){
                break;
            }
            Cy_Cryptolite_Vu_memcpy(tempBuff, tempBuff1, CY_CRYPTOLITE_AES_BLOCK_SIZE);

            // Cy_Cryptolite_Aes_Xor(base, aesState, dstBuff, srcBuff, dstBuff);
            dstBuff[0] = srcBuff[0] ^ tempBuff[0];
            dstBuff[1] = srcBuff[1] ^ tempBuff[1];
            dstBuff[2] = srcBuff[2] ^ tempBuff[2];
            dstBuff[3] = srcBuff[3] ^ tempBuff[3];

            if (CY_CRYPTOLITE_DECRYPT == dirMode)
            {
                /* cipher text block */
                Cy_Cryptolite_Vu_memcpy(tempBuff, srcBuff, CY_CRYPTOLITE_AES_BLOCK_SIZE);
            }
            else
            {
                /* cipher text block */
                Cy_Cryptolite_Vu_memcpy(tempBuff, dstBuff, CY_CRYPTOLITE_AES_BLOCK_SIZE);
            }


            srcBuff  += CY_CRYPTOLITE_AES_MAX_KEY_SIZE_U32;
            dstBuff  += CY_CRYPTOLITE_AES_MAX_KEY_SIZE_U32;

            size -= CY_CRYPTOLITE_AES_BLOCK_SIZE;
        }

        if(CY_CRYPTOLITE_SUCCESS == tmpResult)
        {
            /* Copies the local encode buffer to the Initialization Vector. */
            Cy_Cryptolite_Vu_memcpy(ivPtr, tempBuff, CY_CRYPTOLITE_AES_BLOCK_SIZE);
        }


    }

    return (tmpResult);
}
#endif /*CY_CRYPTOLITE_CFG_CIPHER_MODE_CBC*/



#if defined(CY_CRYPTOLITE_CFG_CIPHER_MODE_CTR)
/*******************************************************************************
* Function Name: Cy_Cryptolite_Aes_Ctr
********************************************************************************
*
* Performs an AES Encryption/Decryption operation on a data using the counter method (CTR).
*
* \param base
* The pointer to the CRYPTOLITE instance.
*
* \param srcSize
* The size of a source plain text.
*
* \param srcOffset
* The size of an offset within the current block stream for resuming within the
* current cipher stream.
*
* \param ivPtr
* The 128-bit initial vector that contains a 64-bit nonce and 64-bit counter.
*
* \param dst
* The pointer to a destination cipher text.
*
* \param src
* The pointer to a source plain text.
*
* \param aesState
* The pointer to the AES state structure allocated by the user. The user must
* must not modify anything in this structure.
*
* \return
* \ref cy_en_cryptolite_status_t
*
*******************************************************************************/
cy_en_cryptolite_status_t Cy_Cryptolite_Aes_Ctr(CRYPTOLITE_Type *base,
                                            uint32_t srcSize,
                                            uint32_t *srcOffset,
                                            uint8_t  *ivPtr,
                                            uint8_t  *dst,
                                            uint8_t  const *src,
                                            cy_stc_cryptolite_aes_state_t *aesState)
{
    uint32_t i;
    uint32_t cnt;
    uint64_t counter;
    uint32_t *blockCounter = NULL;
    cy_stc_cryptolite_aes_buffers_t *aesBuffers = NULL;
    cy_en_cryptolite_status_t tmpResult = CY_CRYPTOLITE_BAD_PARAMS;
    uint32_t *srcBuff = NULL;
    uint32_t *dstBuff = NULL;
    uint32_t *streamBuff = NULL;

    /* Input parameters verification */
    if ((NULL == base) || (NULL == srcOffset) || (NULL == ivPtr) || (NULL == dst) || (NULL == src) || (NULL == aesState))
    {
        return tmpResult;
    }

    /* Checking the address alignment */
    if((((uint32_t)dst & 0x03U) != 0u) || (((uint32_t)src & 0x03U) != 0u))
    {
        return CY_CRYPTOLITE_ALIGNMENT_ERROR;
    }

    /*check if IP is busy*/
    if ((REG_CRYPTOLITE_STATUS(base) & CRYPTOLITE_STATUS_BUSY_Msk) != 0UL)
    {
        return CY_CRYPTOLITE_HW_BUSY;
    }

    aesBuffers = (cy_stc_cryptolite_aes_buffers_t*)aesState->buffers;
    srcBuff  = (uint32_t*)((void *)src);
    dstBuff  = (uint32_t*)((void *)dst);
    streamBuff = (uint32_t*)(aesBuffers->block2);
    blockCounter = (uint32_t*)(aesBuffers->block3);

    Cy_Cryptolite_Vu_memcpy(blockCounter, ivPtr, CY_CRYPTOLITE_AES_BLOCK_SIZE);

    CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 11.3','Intentional pointer type conversion');
    counter = CY_SWAP_ENDIAN64(*(uint64_t*)(blockCounter + CY_CRYPTO_AES_CTR_CNT_POS));

    cnt = (uint32_t)(srcSize / CY_CRYPTOLITE_AES_BLOCK_SIZE);

    for (i = 0UL; i < cnt; i++)
    {

        /* In this mode, (CTR) is always an encryption! */
        tmpResult = Cy_Cryptolite_Aes_ProcessBlock(base, aesState, (uint32_t*)((void*)streamBuff), (uint32_t*)((void*)blockCounter));

        if(CY_CRYPTOLITE_SUCCESS != tmpResult){
            break;
        }
        /* Increment the block counter, at least 64Bits (from 128) is the counter part */
        counter++;
        CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 11.3','Intentional pointer type conversion');
        *(uint64_t*)(blockCounter + CY_CRYPTO_AES_CTR_CNT_POS) = CY_SWAP_ENDIAN64(counter);

        // Cy_Cryptolite_Aes_Xor(base, aesState, dstBuff, srcBuff, streamBuff);
        dstBuff[0] = srcBuff[0] ^ streamBuff[0];
        dstBuff[1] = srcBuff[1] ^ streamBuff[1];
        dstBuff[2] = srcBuff[2] ^ streamBuff[2];
        dstBuff[3] = srcBuff[3] ^ streamBuff[3];

        srcBuff += CY_CRYPTOLITE_AES_MAX_KEY_SIZE_U32;
        dstBuff += CY_CRYPTOLITE_AES_MAX_KEY_SIZE_U32;
    }

    if(CY_CRYPTOLITE_SUCCESS == tmpResult)
    {

        Cy_Cryptolite_Vu_memcpy(ivPtr, blockCounter, CY_CRYPTOLITE_AES_BLOCK_SIZE);

        /* Save the reminder of the last non-complete block */
        *srcOffset = (uint32_t)(srcSize % CY_CRYPTOLITE_AES_BLOCK_SIZE);
    }


    return tmpResult;
}

/*******************************************************************************
* Function Name: Cy_Cryptolite_Aes_Ctr_Zeropad
********************************************************************************
*
* Performs an AES Encryption operation with zero bytes padding for the last block(Not multiple of Aes block size) using the counter method (CTR).
*
* \param base
* The pointer to the CRYPTOLITE instance.
*
* \param srcSize
* The size of a source plain text.
*
* \param srcOffset
* The size of an offset within the current block stream for resuming within the
* current cipher stream.
*
* \param ivPtr
* The 128-bit initial vector that contains a 64-bit nonce and 64-bit counter.
*
* \param dst
* The pointer to a destination cipher text.
*
* \param src
* The pointer to a source plain text.
*
* \param aesState
* The pointer to the AES state structure allocated by the user. The user must
* must not modify anything in this structure.
*
* \return
* \ref cy_en_cryptolite_status_t
*
*******************************************************************************/
cy_en_cryptolite_status_t Cy_Cryptolite_Aes_Ctr_Zeropad(CRYPTOLITE_Type *base,
                                            uint32_t srcSize,
                                            uint8_t  *ivPtr,
                                            uint8_t  *dst,
                                            uint8_t  const *src,
                                            cy_stc_cryptolite_aes_state_t *aesState)
{
    uint32_t i;
    uint32_t cnt;
    uint64_t counter;
    uint32_t *blockCounter = NULL;
    cy_stc_cryptolite_aes_buffers_t *aesBuffers = NULL;
    uint32_t *srcBuff = NULL;
    uint32_t *dstBuff = NULL;
    uint32_t *streamBuff = NULL;
    uint32_t *tempBuf = NULL;
    uint32_t *tempBuf1 = NULL;

    uint32_t srcRemainder = 0;

    cy_en_cryptolite_status_t tmpResult = CY_CRYPTOLITE_SUCCESS;

    /* Input parameters verification */
    if ((NULL == base) || (NULL == ivPtr) || (NULL == dst) || (NULL == src) || (NULL == aesState))
    {
        return CY_CRYPTOLITE_BAD_PARAMS;
    }

    /* Checking the address alignment */
    if((((uint32_t)dst & 0x03U) != 0u) || (((uint32_t)src & 0x03U) != 0u))
    {
        return CY_CRYPTOLITE_ALIGNMENT_ERROR;
    }

    /*check if IP is busy*/
    if ((REG_CRYPTOLITE_STATUS(base) & CRYPTOLITE_STATUS_BUSY_Msk) != 0UL)
    {
        return CY_CRYPTOLITE_HW_BUSY;
    }

    aesBuffers = (cy_stc_cryptolite_aes_buffers_t*)aesState->buffers;
    srcBuff      = (uint32_t*)((void*)src);
    dstBuff      = (uint32_t*)((void*)dst);
    streamBuff   = (uint32_t*)(aesBuffers->block0);
    tempBuf   = (uint32_t*)(aesBuffers->block1);
    tempBuf1   = (uint32_t*)(aesBuffers->block2);
    blockCounter = (uint32_t*)(aesBuffers->block3);

    Cy_Cryptolite_Vu_memcpy(blockCounter, ivPtr, CY_CRYPTOLITE_AES_BLOCK_SIZE);

    CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 11.3','Intentional pointer type conversion');
    counter = CY_SWAP_ENDIAN64(*(uint64_t*)(blockCounter + CY_CRYPTO_AES_CTR_CNT_POS));

    cnt = (uint32_t)(srcSize / CY_CRYPTOLITE_AES_BLOCK_SIZE);

    for (i = 0UL; i < cnt; i++)
    {
        /* source message block */
        Cy_Cryptolite_Vu_memcpy(srcBuff, src, CY_CRYPTOLITE_AES_BLOCK_SIZE);

        /* In this mode, (CTR) is always an encryption! */
        tmpResult = Cy_Cryptolite_Aes_ProcessBlock(base, aesState, streamBuff, blockCounter);

        if(CY_CRYPTOLITE_SUCCESS != tmpResult){
            break;
        }
        /* Increment the block counter, at least 64Bits (from 128) is the counter part */
        counter++;
        CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 11.3','Intentional pointer type conversion');
        *(uint64_t*)(blockCounter + CY_CRYPTO_AES_CTR_CNT_POS) = CY_SWAP_ENDIAN64(counter);

        // Cy_Cryptolite_Aes_Xor(base, aesState, dstBuff, srcBuff, streamBuff);
        dstBuff[0] = srcBuff[0] ^ streamBuff[0];
        dstBuff[1] = srcBuff[1] ^ streamBuff[1];
        dstBuff[2] = srcBuff[2] ^ streamBuff[2];
        dstBuff[3] = srcBuff[3] ^ streamBuff[3];

        srcBuff += CY_CRYPTOLITE_AES_MAX_KEY_SIZE_U32;
        dstBuff += CY_CRYPTOLITE_AES_MAX_KEY_SIZE_U32;
    }

    srcRemainder = (uint32_t)(srcSize % CY_CRYPTOLITE_AES_BLOCK_SIZE);

    if ((srcRemainder != 0u) && (CY_CRYPTOLITE_SUCCESS == tmpResult))
    {
        /* source message block */
        Cy_Cryptolite_Vu_memcpy(tempBuf, srcBuff, srcRemainder);

        /* zeropad source message block */
        Cy_Cryptolite_Vu_memset((uint8_t*)tempBuf + srcRemainder, 0u, CY_CRYPTOLITE_AES_BLOCK_SIZE - srcRemainder);

        /* In this mode, (CTR) is always an encryption! */
        tmpResult = Cy_Cryptolite_Aes_ProcessBlock(base, aesState, streamBuff, blockCounter);

        if(CY_CRYPTOLITE_SUCCESS == tmpResult)
        {
            /* Increment the block counter, at least 64Bits (from 128) is the counter part */
            counter++;
            CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 11.3','Intentional pointer type conversion');
            *(uint64_t*)(blockCounter + CY_CRYPTO_AES_CTR_CNT_POS) = CY_SWAP_ENDIAN64(counter);

            // Cy_Cryptolite_Aes_Xor(base, aesState, dstBuff, srcBuff, streamBuff);
            tempBuf1[0] = tempBuf[0] ^ streamBuff[0];
            tempBuf1[1] = tempBuf[1] ^ streamBuff[1];
            tempBuf1[2] = tempBuf[2] ^ streamBuff[2];
            tempBuf1[3] = tempBuf[3] ^ streamBuff[3];

            /* destination cipher text block */
            Cy_Cryptolite_Vu_memcpy(dstBuff, tempBuf1, srcRemainder);
        }

    }

    return tmpResult;
}

#endif /*CY_CRYPTOLITE_CFG_CIPHER_MODE_CBC*/

#endif
#endif

#if defined(__cplusplus)
}
#endif


#endif /* CY_IP_MXCRYPTOLITE */


/* [] END OF FILE */
