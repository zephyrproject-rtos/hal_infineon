/***************************************************************************//**
* \file cy_cryptolite_aes_ccm.c
* \version 2.80
*
* \brief
*  Provides API implementation of the Cryptolite AES CCM PDL driver.
*
********************************************************************************
* \copyright
* Copyright (c) 2023, Cypress Semiconductor Corporation (an Infineon company) or
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

#include "cy_cryptolite_aes_ccm.h"

#if defined(__cplusplus)
extern "C" {
#endif


#if (CRYPTOLITE_AES_PRESENT == 1)
#if defined(CY_CRYPTOLITE_CFG_CIPHER_MODE_CCM)

/*******************************************************************************
* Function Name: Cy_Cryptolite_Aes_Ccm_Init
****************************************************************************//*
*
* Performs an AES CCM Init operation.
*
* \param base
* The pointer to the CRYPTOLITE instance.
*
* \param aesCcm_buffer The buffers should be a SAHB mapped addresses.
* The pointer to the memory buffers storage.
*
* \param aesState
* The pointer to the AES CCM state structure allocated by the user. The user
* must not modify anything in this structure.
*
* \return
* \ref cy_en_cryptolite_status_t
*
*******************************************************************************/

cy_en_cryptolite_status_t Cy_Cryptolite_Aes_Ccm_Init(CRYPTOLITE_Type *base,
                                            cy_stc_cryptolite_aes_ccm_buffers_t * aesCcm_buffer, cy_stc_cryptolite_aes_ccm_state_t *aesCcmState)
{
    /* Input parameters verification */
    if ((NULL == base) || (NULL == aesCcm_buffer) || (NULL == aesCcmState))
    {
        return CY_CRYPTOLITE_BAD_PARAMS;
    }

    Cy_Cryptolite_Vu_memset((void *)aesCcm_buffer, 0u, sizeof(cy_stc_cryptolite_aes_ccm_buffers_t));
    Cy_Cryptolite_Vu_memset((void *)aesCcmState, 0u, sizeof(cy_stc_cryptolite_aes_ccm_state_t));

    aesCcmState->aesCbcMacState.buffers = &aesCcm_buffer->aesCbcMac_buffer;
    aesCcmState->aesCtrState.buffers = &aesCcm_buffer->aesCtr_buffer;
    aesCcmState->temp = aesCcm_buffer->temp_buffer;
    aesCcmState->ctr = aesCcm_buffer->ctr;
    aesCcmState->y = aesCcm_buffer->y;

    return CY_CRYPTOLITE_SUCCESS;
}



/*******************************************************************************
* Function Name: Cy_Cryptolite_Aes_Ccm_SetKey
****************************************************************************//*
*
* Sets AES CCM Key for the operation.
*
* \param base
* The pointer to the CRYPTOLITE instance.
*
* \param key
* The pointer to the CCM key.
*
* \param aesCcmState
* The pointer to the AES CCM state structure allocated by the user. The user
* must not modify anything in this structure.
*
*
* \return
* \ref cy_en_cryptolite_status_t
*
*******************************************************************************/
cy_en_cryptolite_status_t Cy_Cryptolite_Aes_Ccm_SetKey(CRYPTOLITE_Type *base,
                                            uint8_t const *key, cy_stc_cryptolite_aes_ccm_state_t *aesCcmState)
{
    cy_en_cryptolite_status_t status = CY_CRYPTOLITE_BAD_PARAMS;
    uint8_t *keyRemap;

    /* Input parameters verification */
    if ((NULL == base) || (NULL == key) || (NULL == aesCcmState))
    {
        return CY_CRYPTOLITE_BAD_PARAMS;
    }

    keyRemap =  (uint8_t *)CY_REMAP_ADDRESS_CRYPTOLITE(key);

    // Sets the AES Key for the CBC MAC operation
    status = Cy_Cryptolite_Aes_Init(base, keyRemap, &aesCcmState->aesCbcMacState, aesCcmState->aesCbcMacState.buffers);
    if(CY_CRYPTOLITE_SUCCESS != status)
    {
        return status;
    }

    // Sets the AES Key for the CTR operation
    status = Cy_Cryptolite_Aes_Init(base, keyRemap, &aesCcmState->aesCtrState, aesCcmState->aesCtrState.buffers);
    if(CY_CRYPTOLITE_SUCCESS != status)
    {
        return status;
    }

    return CY_CRYPTOLITE_SUCCESS;
}



/*******************************************************************************
* Function Name: Cy_Cryptolite_Aes_Ccm_Initial_Block
****************************************************************************//*
*
*  Performs the Initial CCM calculation.
*
* \param base
* The pointer to the CRYPTOLITE instance.
*
* \param aesCcmState
* The pointer to the AES CCM state structure allocated by the user. The user
* must not modify anything in this structure.
*
* \return
* \ref cy_en_cryptolite_status_t
*
*******************************************************************************/
static cy_en_cryptolite_status_t Cy_Cryptolite_Aes_Ccm_Initial_Block(CRYPTOLITE_Type *base,
                                            cy_stc_cryptolite_aes_ccm_state_t *aesCcmState)
{
    cy_en_cryptolite_status_t status = CY_CRYPTOLITE_BAD_PARAMS;
    uint32_t size_left = 0u;

    if(aesCcmState->isIvSet == false || aesCcmState->isLengthSet == false)
    {
        return CY_CRYPTOLITE_SUCCESS;
    }

    status = Cy_Cryptolite_Aes_CbcMac_Setup(base, &aesCcmState->aesCbcMacState);
    if(CY_CRYPTOLITE_SUCCESS != status)
    {
        return status;
    }

    aesCcmState->y[0] |= (uint8_t)(aesCcmState->aadLength > 0u) << 6u;
    aesCcmState->y[0] |= ((aesCcmState->tagLength - 2u) / 2u) << 3u;
    aesCcmState->y[0] |= (uint8_t)aesCcmState->L - 1u;

    size_left = aesCcmState->textLength;
    for (uint32_t i = 0u; i < aesCcmState->L; i++)
    {
        aesCcmState->y[15u - i] = (uint8_t)size_left & 0xffu ;
         size_left >>= 8u;
    }

    // Performs the CBC MAC update operation for the Initial Block data formatted with flags and length
    status = Cy_Cryptolite_Aes_CbcMac_Update(base, CY_CRYPTOLITE_AES_BLOCK_SIZE, aesCcmState->y, &aesCcmState->aesCbcMacState);
    if(CY_CRYPTOLITE_SUCCESS != status)
    {
        return status;
    }

    if (aesCcmState->aadLength > 0u)
    {
        aesCcmState->temp[0] = (uint8_t)(aesCcmState->aadLength >> 8u) & 0xffu;
        aesCcmState->temp[1] = (uint8_t)(aesCcmState->aadLength & 0xffu);
        status = Cy_Cryptolite_Aes_CbcMac_Update(base, 2u, aesCcmState->temp, &aesCcmState->aesCbcMacState);

        if(CY_CRYPTOLITE_SUCCESS != status)
        {
            return status;
        }

        aesCcmState->aadLengthProcessed += 2u;
    }

    return CY_CRYPTOLITE_SUCCESS;
}   

/*******************************************************************************
* Function Name: Cy_Cryptolite_Aes_Ccm_Set_Length
****************************************************************************//*
*
* Sets the length for Additional authentication data, plain text and Tag for AES CCM operation.
*
* \param base
* The pointer to the CRYPTOLITE instance.
*
* \param aadSize
* The Size of the Additional Authentication Data.
*
* \param textSize
* The Size of the Text.
*
* \param tagLength
* The Size of the Tag.
*
* \param aesCcmState
* The pointer to the AES CCM state structure allocated by the user. The user
* must not modify anything in this structure.
*
*
* \return
* \ref cy_en_cryptolite_status_t
*
*******************************************************************************/
cy_en_cryptolite_status_t Cy_Cryptolite_Aes_Ccm_Set_Length(CRYPTOLITE_Type *base,
                                            uint32_t aadSize,  uint32_t textSize, uint32_t tagLength,
                                            cy_stc_cryptolite_aes_ccm_state_t *aesCcmState)
{
    /* Input parameters verification */
    if ((NULL == base) || (NULL == aesCcmState))
    {
        return CY_CRYPTOLITE_BAD_PARAMS;
    }

    if (tagLength < 3u || tagLength > CY_CRYPTOLITE_AES_BLOCK_SIZE || (tagLength % 2u != 0u))
    {
        return CY_CRYPTOLITE_BAD_PARAMS;
    }

    if( aadSize >= 0xFF00UL )
    {
        return CY_CRYPTOLITE_BAD_PARAMS;
    }

    aesCcmState->textLength = textSize;
    aesCcmState->aadLength = aadSize;
    aesCcmState->tagLength = (uint8_t)tagLength;
    aesCcmState->aadLengthProcessed = 0u;
    aesCcmState->isAadProcessed = false; 
    aesCcmState->isLengthSet = true; 

    return Cy_Cryptolite_Aes_Ccm_Initial_Block(base, aesCcmState);
}


/*******************************************************************************
* Function Name: Cy_Cryptolite_Aes_Ccm_Start
****************************************************************************//*
*
* Function to set IV for the AES CCM operation.
*
* \param base
* The pointer to the CRYPTOLITE instance.
*
* \param dirMode
* Can be \ref CY_CRYPTOLITE_ENCRYPT or \ref CY_CRYPTOLITE_DECRYPT
* (\ref cy_en_cryptolite_dir_mode_t)
*
* \param ivSize
* The size of the IV.
*
* \param iv
* The pointer to the IV.
*
* \param aesCcmState
* The pointer to the AES CCM state structure allocated by the user. The user
* must not modify anything in this structure.
*
* \return
* \ref cy_en_cryptolite_status_t
*
*******************************************************************************/

cy_en_cryptolite_status_t Cy_Cryptolite_Aes_Ccm_Start(CRYPTOLITE_Type *base,
                                            cy_en_cryptolite_dir_mode_t dirMode,    
                                             uint32_t ivSize, uint8_t const * iv,
                                            cy_stc_cryptolite_aes_ccm_state_t *aesCcmState)
{
    cy_en_cryptolite_status_t status = CY_CRYPTOLITE_BAD_PARAMS;
    uint8_t *ivRemap;

    /* Input parameters verification */
    if ((NULL == base) || (NULL == iv) || (NULL == aesCcmState))
    {
        return status;
    }

    if (ivSize < 7u || ivSize > 13u)
    {
        return status;
    }

    ivRemap =  (uint8_t *)CY_REMAP_ADDRESS_CRYPTOLITE(iv);

    aesCcmState->dirMode = dirMode;
    aesCcmState->L = CY_CRYPTOLITE_AES_BLOCK_SIZE - ivSize - 1u;
    aesCcmState->isIvSet = true; 

    Cy_Cryptolite_Vu_memset (aesCcmState->ctr, 0u, CY_CRYPTOLITE_AES_BLOCK_SIZE);
    aesCcmState->ctr[0] = (uint8_t)aesCcmState->L - 1u;
    aesCcmState->ctr[15] = 1u;
    Cy_Cryptolite_Vu_memcpy((void*)&aesCcmState->ctr[1], (void*)ivRemap, (uint16_t)ivSize);

    Cy_Cryptolite_Vu_memset (aesCcmState->y, 0u, CY_CRYPTOLITE_AES_BLOCK_SIZE);
    Cy_Cryptolite_Vu_memcpy((void*)&aesCcmState->y[1], (void*)ivRemap, (uint16_t)ivSize);


    // Sets the IV for the AES CTR operation
    status = Cy_Cryptolite_Aes_Ctr_Setup(base, &aesCcmState->aesCtrState);
    if(CY_CRYPTOLITE_SUCCESS != status)
    {
        return status;
    }

    status = Cy_Cryptolite_Aes_Ctr_Set_IV(base, aesCcmState->ctr, &aesCcmState->aesCtrState);
    if(CY_CRYPTOLITE_SUCCESS != status)
    {
        return status;
    }

    return Cy_Cryptolite_Aes_Ccm_Initial_Block(base, aesCcmState);
}



/*******************************************************************************
* Function Name: Cy_Cryptolite_Aes_Ccm_Update_Aad
****************************************************************************//*
*
* Performs an AES CCM update AAD Multistage  operation.
*
* \param base
* The pointer to the CRYPTOLITE instance.
*
* \param aadSize
* The size of the AAD.
*
* \param aad
* The pointer to a AAD.
*
* \param aesCcmState
* The pointer to the AES CCM state structure allocated by the user. The user
* must not modify anything in this structure.
*
* \return
* \ref cy_en_cryptolite_status_t
*
*******************************************************************************/
cy_en_cryptolite_status_t Cy_Cryptolite_Aes_Ccm_Update_Aad(CRYPTOLITE_Type *base,
                                            uint32_t aadSize,
                                            uint8_t const *aad,
                                            cy_stc_cryptolite_aes_ccm_state_t *aesCcmState)


{
    cy_en_cryptolite_status_t status = CY_CRYPTOLITE_BAD_PARAMS;
    uint8_t *aadRemap;

    if(0u == aadSize)
    {
        return CY_CRYPTOLITE_SUCCESS;
    }

    if( aadSize >= 0xFF00UL )
    {
        return CY_CRYPTOLITE_BAD_PARAMS;
    }
    
        /* Input parameters verification */
    if ((NULL == base) || (NULL == aesCcmState) || (NULL == aad))
    {
        return CY_CRYPTOLITE_BAD_PARAMS;
    }

    aadRemap =  (uint8_t *)CY_REMAP_ADDRESS_CRYPTOLITE(aad);

    status = Cy_Cryptolite_Aes_CbcMac_Update(base, aadSize, aadRemap, &aesCcmState->aesCbcMacState);
    if(CY_CRYPTOLITE_SUCCESS != status)
    {
        return status;
    }

    aesCcmState->aadLengthProcessed += aadSize;

    return status;
}


/*******************************************************************************
* Function Name: Cy_Cryptolite_Aes_Ccm_Update
****************************************************************************//*
*
* Performs an AES CCM Update Multistage update operation.
*
* \param base
* The pointer to the CRYPTOLITE instance.
*
* \param srcSize
* The size of the source block.
*
* \param dst
* The pointer to a destination block.
*
* \param src
* The pointer to a source block.
*
* \param aesCcmState
* The pointer to the AES CCM state structure allocated by the user. The user
* must not modify anything in this structure.
*
* \return
* \ref cy_en_cryptolite_status_t
*
*******************************************************************************/
cy_en_cryptolite_status_t Cy_Cryptolite_Aes_Ccm_Update(CRYPTOLITE_Type *base,
                                            uint32_t srcSize,
                                            uint8_t *dst,
                                            uint8_t const *src,
                                            cy_stc_cryptolite_aes_ccm_state_t *aesCcmState)


{
    cy_en_cryptolite_status_t status = CY_CRYPTOLITE_BAD_PARAMS;
    uint8_t *temp = NULL;
    uint8_t *cipherText_ptr;
    uint8_t *srcRemap;

    if(0u == srcSize)
    {
        return CY_CRYPTOLITE_SUCCESS;
    }

        /* Input parameters verification */
    if ((NULL == base) || (NULL == aesCcmState) || (NULL == dst) || (NULL == src))
    {
        return CY_CRYPTOLITE_BAD_PARAMS;
    }

    temp = aesCcmState->temp;


    srcRemap =  (uint8_t *)CY_REMAP_ADDRESS_CRYPTOLITE(src);

    Cy_Cryptolite_Vu_memset (temp, 0u, CY_CRYPTOLITE_AES_BLOCK_SIZE);

    if( aesCcmState->aadLengthProcessed % CY_CRYPTOLITE_AES_BLOCK_SIZE != 0u && aesCcmState->isAadProcessed == false)
    {
        status = Cy_Cryptolite_Aes_CbcMac_Update(base,  CY_CRYPTOLITE_AES_BLOCK_SIZE - aesCcmState->aadLengthProcessed % CY_CRYPTOLITE_AES_BLOCK_SIZE, temp, &aesCcmState->aesCbcMacState);
        if(CY_CRYPTOLITE_SUCCESS != status)
        {
            return status;
        }

        aesCcmState->isAadProcessed = true;
    }
    
    status =  Cy_Cryptolite_Aes_Ctr_Update(base, srcSize, dst, srcRemap, &aesCcmState->aesCtrState);
    if(CY_CRYPTOLITE_SUCCESS != status)
    {
        return status;
    }
        
    if(aesCcmState->dirMode == CY_CRYPTOLITE_ENCRYPT)
    {
        cipherText_ptr = (uint8_t *)srcRemap;
    }
    else
    {
        cipherText_ptr = dst;
    }
    
    status = Cy_Cryptolite_Aes_CbcMac_Update(base, srcSize, cipherText_ptr, &aesCcmState->aesCbcMacState);

    return status;
}



/*******************************************************************************
* Function Name: Cy_Cryptolite_Aes_Ccm_Finish
****************************************************************************//*
*
* Performs an AES CCM finish operation.
*
* \param base
* The pointer to the CRYPTOLITE instance.
*
* \param mac
* The pointer to the CCM Tag.
*
* \param aesCcmState
* The pointer to the AES CCM state structure allocated by the user. The user
* must not modify anything in this structure.
*
* \return
* \ref cy_en_cryptolite_status_t
*
*******************************************************************************/
cy_en_cryptolite_status_t Cy_Cryptolite_Aes_Ccm_Finish(CRYPTOLITE_Type *base, uint8_t *tag, cy_stc_cryptolite_aes_ccm_state_t *aesCcmState)
{
    uint8_t *temp = NULL;
    uint8_t y[CY_CRYPTOLITE_AES_BLOCK_SIZE] = {0u};
    cy_en_cryptolite_status_t status = CY_CRYPTOLITE_BAD_PARAMS;

    /* Input parameters verification */
    if ((NULL == base) || (NULL == aesCcmState))
    {
        return CY_CRYPTOLITE_BAD_PARAMS;
    }

    temp = aesCcmState->temp;

    Cy_Cryptolite_Vu_memset (temp, 0u, CY_CRYPTOLITE_AES_BLOCK_SIZE);
    Cy_Cryptolite_Vu_memset (y, 0u, CY_CRYPTOLITE_AES_BLOCK_SIZE);

    if( aesCcmState->aadLengthProcessed % CY_CRYPTOLITE_AES_BLOCK_SIZE != 0u && aesCcmState->isAadProcessed == false)
    {
        status = Cy_Cryptolite_Aes_CbcMac_Update(base,  CY_CRYPTOLITE_AES_BLOCK_SIZE - aesCcmState->aadLengthProcessed % CY_CRYPTOLITE_AES_BLOCK_SIZE, temp, &aesCcmState->aesCbcMacState);
        if(CY_CRYPTOLITE_SUCCESS != status)
        {
            return status;
        }
    }

    if (aesCcmState->textLength % CY_CRYPTOLITE_AES_BLOCK_SIZE  != 0u)
    {
        status = Cy_Cryptolite_Aes_CbcMac_Update(base, CY_CRYPTOLITE_AES_BLOCK_SIZE - aesCcmState->textLength % CY_CRYPTOLITE_AES_BLOCK_SIZE, temp, &aesCcmState->aesCbcMacState);
        if(CY_CRYPTOLITE_SUCCESS != status)
        {
            return status;
        }
    }

    status = Cy_Cryptolite_Aes_CbcMac_Finish(base, temp, &aesCcmState->aesCbcMacState);
    if(CY_CRYPTOLITE_SUCCESS != status)
    {
        return status;
    }

    for (uint32_t i = 0u; i < aesCcmState->L; i++)
    {
        aesCcmState->aesCtrState.buffers->iv[15u-i] = 0u;
    }

    aesCcmState->aesCtrState.unProcessedBytes = 0u;

    status = Cy_Cryptolite_Aes_Ctr_Update(base, CY_CRYPTOLITE_AES_BLOCK_SIZE,
                                            y,
                                            temp,
                                            &aesCcmState->aesCtrState);

    if(CY_CRYPTOLITE_SUCCESS != status)
    {
        return status;
    }

    Cy_Cryptolite_Vu_memcpy((void*)tag, (void*)y, aesCcmState->tagLength);
    Cy_Cryptolite_Vu_memset (aesCcmState->ctr, 0u, CY_CRYPTOLITE_AES_BLOCK_SIZE);
    Cy_Cryptolite_Vu_memset (aesCcmState->y, 0u, CY_CRYPTOLITE_AES_BLOCK_SIZE);
    aesCcmState->isIvSet = false; 
    aesCcmState->isAadProcessed = false; 

    return status;
}



/*******************************************************************************
* Function Name: Cy_Cryptolite_Aes_Ccm
****************************************************************************//*
*
* Performs an AES CCM operation.
* \note Cy_Cryptolite_Aes_Ccm_Init() and Cy_Cryptolite_Aes_Ccm_SetKey() should be called before calling this function.
*
* \param base
* The pointer to the CRYPTOLITE instance.
*
* \param dirMode
* Can be \ref CY_CRYPTOLITE_ENCRYPT or \ref CY_CRYPTOLITE_DECRYPT
* (\ref cy_en_cryptolite_dir_mode_t)
*
* \param ivSize
* The size of the IV.
*
* \param iv
* The pointer to the IV.
*
* \param aadSize
* The size of the AAD.
*
* \param aad
* The pointer to a AAD.
*
* \param srcSize
* The size of the source block.
*
* \param dst
* The pointer to a destination block.
*
* \param src
* The pointer to a source block.
*
* \param tagSize
* The size of the Tag.
*
* \param tag
* The pointer to the tags.
*
* \param aesCcmState
* The pointer to the AES CCM state structure allocated by the user. The user
* must not modify anything in this structure.
*
* \return
* \ref cy_en_cryptolite_status_t
*
*******************************************************************************/
static cy_en_cryptolite_status_t Cy_Cryptolite_Aes_Ccm(CRYPTOLITE_Type *base,
                                            cy_en_cryptolite_dir_mode_t dirMode,    
                                            uint32_t ivSize, uint8_t const * iv,
                                            uint32_t aadSize, uint8_t const *aad,
                                            uint32_t srcSize, uint8_t *dst, uint8_t const *src,
                                            uint32_t tagSize, uint8_t *tag,
                                            cy_stc_cryptolite_aes_ccm_state_t *aesCcmState)

{
    cy_en_cryptolite_status_t status = CY_CRYPTOLITE_BAD_PARAMS;
    uint8_t *ivRemap;
    uint8_t *aadRemap;
    uint8_t *srcRemap;

     /* Input parameters verification */
    if ((NULL == base) || ((NULL == iv) && (ivSize > 0u)) || ((NULL == aad) && (aadSize > 0u)) || 
     ((srcSize > 0u) && ((NULL == dst) || (NULL == src)))|| (NULL == aesCcmState) || (NULL == tag))
    {
        return status;
    }

    ivRemap =  (uint8_t *)CY_REMAP_ADDRESS_CRYPTOLITE(iv);
    aadRemap =  (uint8_t *)CY_REMAP_ADDRESS_CRYPTOLITE(aad);
    srcRemap =  (uint8_t *)CY_REMAP_ADDRESS_CRYPTOLITE(src);

    status = Cy_Cryptolite_Aes_Ccm_Set_Length(base, aadSize,  srcSize, tagSize, aesCcmState);   
    
    if(CY_CRYPTOLITE_SUCCESS != status)
    {
        return status;
    }

    status = Cy_Cryptolite_Aes_Ccm_Start(base, dirMode, ivSize, ivRemap, aesCcmState);    

    if(CY_CRYPTOLITE_SUCCESS != status)
    {
        return status;
    }

    status = Cy_Cryptolite_Aes_Ccm_Update_Aad(base, aadSize, aadRemap, aesCcmState);

    if(CY_CRYPTOLITE_SUCCESS != status)
    {
        return status;
    }

    status = Cy_Cryptolite_Aes_Ccm_Update(base, srcSize, dst, srcRemap, aesCcmState);

    if(CY_CRYPTOLITE_SUCCESS != status)
    {
        return status;
    }

    status = Cy_Cryptolite_Aes_Ccm_Finish(base, tag, aesCcmState);

    return status;
}




/*******************************************************************************
* Function Name: Cy_Cryptolite_Aes_Ccm_Encrypt_Tag
****************************************************************************//*
*
* Performs an AES CCM Encrypt operation.
* \note Cy_Cryptolite_Aes_Ccm_Init() and Cy_Cryptolite_Aes_Ccm_SetKey() should be called before calling this function
*
* \param base
* The pointer to the CRYPTOLITE instance.
*
* \param ivSize
* The size of the IV.
*
* \param iv
* The pointer to the IV.
*
* \param aadSize
* The size of the AAD.
*
* \param aad
* The pointer to a AAD.
*
* \param srcSize
* The size of the source block.
*
* \param cipherTxt
* The pointer to a cipher text block.
*
* \param plainTxt
* The pointer to a plain text block.
*
* \param tagSize
* The size of the Tag.
*
* \param tag
* The pointer to the tags.
*
* \param aesCcmState
* The pointer to the AES CCM state structure allocated by the user. The user
* must not modify anything in this structure.
*
* \return
* \ref cy_en_cryptolite_status_t
*
*******************************************************************************/
cy_en_cryptolite_status_t Cy_Cryptolite_Aes_Ccm_Encrypt_Tag(CRYPTOLITE_Type *base,
                                            uint32_t ivSize, uint8_t const * iv,
                                            uint32_t aadSize, uint8_t const *aad,
                                            uint32_t srcSize, uint8_t *cipherTxt, uint8_t const *plainTxt,
                                            uint32_t tagSize, uint8_t *tag,
                                            cy_stc_cryptolite_aes_ccm_state_t *aesCcmState)

{

return Cy_Cryptolite_Aes_Ccm(base, CY_CRYPTOLITE_ENCRYPT, ivSize, iv, aadSize, aad,
                                             srcSize, cipherTxt, plainTxt, tagSize, tag,
                                            aesCcmState);
}


/*******************************************************************************
* Function Name: Cy_Cryptolite_Aes_Ccm_Decrypt
****************************************************************************//*
*
* Performs an AES CCM Decrypt operation.
* \note Cy_Cryptolite_Aes_Ccm_Init() and Cy_Cryptolite_Aes_Ccm_SetKey() should be called before calling this function
*
* \param base
* The pointer to the CRYPTOLITE instance.
*
* \param ivSize
* The size of the IV.
*
* \param iv
* The pointer to the IV.
*
* \param aadSize
* The size of the AAD.
*
* \param aad
* The pointer to a AAD.
*
* \param srcSize
* The size of the source block.
*
* \param plainTxt
* The pointer to a plain text block.
*
* \param cipherTxt
* The pointer to a cipher text block.
*
* \param tagSize
* The size of the Tag.
*
* \param tag
* The pointer to the tags.
*
* \param isValid
* The pointer Store the authentication status.
*
* \param aesCcmState
* The pointer to the AES CCM state structure allocated by the user. The user
* must not modify anything in this structure.
*
* \return
* \ref cy_en_cryptolite_status_t
*
*******************************************************************************/
cy_en_cryptolite_status_t Cy_Cryptolite_Aes_Ccm_Decrypt(CRYPTOLITE_Type *base,
                                            uint32_t ivSize, uint8_t const * iv,
                                            uint32_t aadSize, uint8_t const *aad,
                                            uint32_t srcSize, uint8_t *plainTxt, uint8_t const *cipherTxt,
                                            uint32_t tagSize, uint8_t *tag, cy_en_cryptolite_ccm_auth_result_t *isValid,
                                            cy_stc_cryptolite_aes_ccm_state_t *aesCcmState)

{
    cy_en_cryptolite_status_t status = CY_CRYPTOLITE_BAD_PARAMS;
    uint8_t TagCal[CY_CRYPTOLITE_AES_BLOCK_SIZE] = {0u};
    *isValid = CY_CRYPTOLITE_TAG_INVALID;

    status = Cy_Cryptolite_Aes_Ccm(base, CY_CRYPTOLITE_DECRYPT, ivSize, iv, aadSize, aad,
                                                srcSize, (uint8_t *)plainTxt, cipherTxt, tagSize, TagCal,
                                                aesCcmState);
    if(CY_CRYPTOLITE_SUCCESS != status)
    {
        return status;
    }

    if(Cy_Cryptolite_Vu_memcmp (tag, TagCal, tagSize) == 0u)
    {
        *isValid = CY_CRYPTOLITE_TAG_VALID;
    }

    return CY_CRYPTOLITE_SUCCESS;
}



/*******************************************************************************
* Function Name: Cy_Cryptolite_Aes_Ccm_Free
****************************************************************************//*
*
* Clears AES CCM operation context.
*
* \param base
* The pointer to the CRYPTOLITE instance.
*
* \param aesCcmState
* The pointer to the AES CCM state structure allocated by the user. The user
* must not modify anything in this structure.
*
* \return
* \ref cy_en_cryptolite_status_t
*
*******************************************************************************/
cy_en_cryptolite_status_t Cy_Cryptolite_Aes_Ccm_Free(CRYPTOLITE_Type *base, cy_stc_cryptolite_aes_ccm_state_t *aesCcmState)
{
    (void)base;

    if(NULL != aesCcmState)
    {
        if(NULL != aesCcmState->aesCbcMacState.buffers)
        {
            Cy_Cryptolite_Vu_memset((void *)aesCcmState->aesCbcMacState.buffers, 0u, sizeof(cy_stc_cryptolite_aes_buffers_t));
        }

        if(NULL != aesCcmState->aesCtrState.buffers)
        {
            Cy_Cryptolite_Vu_memset((void *)aesCcmState->aesCtrState.buffers, 0u, sizeof(cy_stc_cryptolite_aes_buffers_t));
        }

        Cy_Cryptolite_Vu_memset((void *)aesCcmState, 0u, sizeof(cy_stc_cryptolite_aes_ccm_state_t));
    }

    return CY_CRYPTOLITE_SUCCESS;
}


#endif /*CY_CRYPTOLITE_CFG_CIPHER_MODE_CCM*/
#endif /*CRYPTOLITE_AES_PRESENT*/

#if defined(__cplusplus)
}
#endif


#endif /* CY_IP_MXCRYPTOLITE */


/* [] END OF FILE */
