/***************************************************************************//**
* \file cy_crypto_crc.c
* \version 1.0.1
*
* \brief
*  This file provides the source code for the API for the CRC methods
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

#if (defined (CY_IP_M0S8CRYPTO) && defined (CRYPTO_CRC))

#if defined(__cplusplus)
extern "C" {
#endif

#include "cy_crypto_crc.h"
#include "cy_crypto_hw.h"
#include "string.h"


#define CY_CRYPTO_CRC_CHUNK_SIZE           (CRYPTO_MEM_SIZE * 4u)
#define CY_CRYPTO_CRC_MESSAGE_BLOCK_OFFSET 0x00
#define CY_CRYPTO_CRC_OPERATION_OPCODE     0x18


/*******************************************************************************
* Function Name: Cy_Crypto_Crc_ProcessBlock
****************************************************************************//**
*
* This function performs CRC calculation.
*
*******************************************************************************/
static void Cy_Crypto_Crc_ProcessBlock(CRYPTO_Type *base,
                                       void const *data,
                                       uint32_t dataSize,
                                       cy_stc_crypto_crc_context_t *crcContext)
{
    /* Wait for Crypto IP to be ready */
    Cy_Crypto_WaitForReady(base);

    /* Copy the message to crypto memory buffer */
    (void) memcpy((void *)REG_CRYPTO_MEM_BUFF(base), data, dataSize);

    /* Clear the OPCODE field in REG_CRYPTO_CTL */
    REG_CRYPTO_CTL(base) &= ~(_VAL2FLD(CRYPTO_CTL_OPCODE, CRYPTO_CTL_OPCODE_Msk));

    /* Set OPCODE to specify the operation. Value 0x18 specifies CRC operation. */
    REG_CRYPTO_CTL(base) |= _VAL2FLD(CRYPTO_CTL_OPCODE, CY_CRYPTO_CRC_OPERATION_OPCODE);

    /* Specify the offset of the message block in memory buffer. */
    REG_CRYPTO_SRC_CTL0(base) = _VAL2FLD(CRYPTO_SRC_CTL0_OFFSET, CY_CRYPTO_CRC_MESSAGE_BLOCK_OFFSET);

    /* Specify the message size and data reverse bit. */
    REG_CRYPTO_CRC_DATA_CTL0(base) = ((dataSize - 1U) << CRYPTO_CRC_DATA_CTL0_DATA_SIZE_Pos | (crcContext->dataReverse & 1U));

    /* Specifies a byte mask with which each data byte is XOR'd */
    REG_CRYPTO_CRC_DATA_CTL1(base) = _VAL2FLD(CRYPTO_CRC_DATA_CTL1_DATA_XOR, crcContext->dataXor);

    /* Specifies the CRC polynomial */
    REG_CRYPTO_CRC_POL_CTL(base) = _VAL2FLD(CRYPTO_CRC_POL_CTL_POLYNOMIAL, crcContext->polynomial << (CY_CRYPTO_HW_REGS_WIDTH - crcContext->width) );

    /* Specifies the LFSR value that is used to calculate CRC. */
    REG_CRYPTO_CRC_LFSR_CTL(base) =  _VAL2FLD(CRYPTO_CRC_LFSR_CTL_LFSR32, crcContext->lfsrInitState << (CY_CRYPTO_HW_REGS_WIDTH - crcContext->width) );

    /* Specify whether the remainder is bit reversed */
    REG_CRYPTO_CRC_REM_CTL0(base) =  _VAL2FLD(CRYPTO_CRC_REM_CTL0_REM_REVERSE, crcContext->remReverse & 0x1U);

    /* Specify a mask with which the LFSR register is XOR'd to produce a remainder */
    REG_CRYPTO_CRC_REM_CTL1(base) =  _VAL2FLD(CRYPTO_CRC_REM_CTL1_REM_XOR, crcContext->remXor << (CY_CRYPTO_HW_REGS_WIDTH - crcContext->width) );

    /* Start the crypto operation */
    REG_CRYPTO_CMD(base) |= _VAL2FLD(CRYPTO_CMD_START, 0x1);

    /* Wait for crypto operation completion. */
    while ((REG_CRYPTO_CMD(base) & (0x1U << 0)) != 0U)
    {
    }

    /* Store the CRC state for resuming */
    crcContext->lfsrInitState = REG_CRYPTO_CRC_LFSR_CTL(base) >> (CY_CRYPTO_HW_REGS_WIDTH - crcContext->width);

    /* Store the CRC */
    crcContext->crc = REG_CRYPTO_CRC_REM(base);
}

/*******************************************************************************
* Function Name: Cy_Crypto_Crc_CalcInit
****************************************************************************//**
*
* This function initializes the CRC calculation.
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Crc_CalcInit(CRYPTO_Type *base,
                                             uint32_t width,
                                             uint32_t polynomial,
                                             bool     dataReverse,
                                             uint8_t  dataXor,
                                             bool     remReverse,
                                             uint32_t remXor,
                                             uint32_t lfsrInitState,
                                             cy_stc_crypto_crc_context_t *crcContext)
{
    if (NULL == base || NULL == crcContext || width == 0U || width > 32U)
    {
        return (CY_CRYPTO_BAD_PARAMS);
    }

    if (!Cy_Crypto_IsEnabled(base))
    {
        return (CY_CRYPTO_HW_NOT_ENABLED);
    }

    crcContext->width = width;
    crcContext->polynomial = polynomial;
    crcContext->dataReverse = dataReverse ? 1U : 0U;
    crcContext->dataXor = dataXor;
    crcContext->remReverse = remReverse ? 1U : 0U;
    crcContext->remXor = remXor;
    crcContext->lfsrInitState = lfsrInitState;
    crcContext->processState = CY_CRYPTO_CRC_INITIALIZED;

    return (CY_CRYPTO_SUCCESS);
}

/*******************************************************************************
* Function Name: Cy_Crypto_Crc_Calc
****************************************************************************//**
*
* This function performs the CRC calculation on a message.
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Crc_Calc(CRYPTO_Type *base,
                                         uint32_t *crc,
                                         void const *data,
                                         uint32_t dataSize,
                                         cy_stc_crypto_crc_context_t *crcContext)
{
    uint32_t lfsrInitState = 0;
    cy_en_crypto_status_t status = CY_CRYPTO_SUCCESS;

    if (NULL == base || NULL == crc || NULL == data || 0U == dataSize || NULL == crcContext)
    {
        return (CY_CRYPTO_BAD_PARAMS);
    }

    if (CY_CRYPTO_CRC_INITIALIZED != crcContext->processState)
    {
        return (CY_CRYPTO_INVALID_OPERATION);
    }

    /* Store the the initial state provided by user to restore it back at the end
     * of the function, so that with one Cy_Crypto_Crc_CalcInit call user can invoke multiple
     * Cy_Crypto_Crc_Calc calls for multiple messages. */
    lfsrInitState = crcContext->lfsrInitState;

    status = Cy_Crypto_Crc_CalcPartial(base, data, dataSize, crcContext);
    if (status != CY_CRYPTO_SUCCESS)
    {
        crcContext->lfsrInitState = lfsrInitState;
        return status;
    }

    status = Cy_Crypto_Crc_CalcFinish(base, crc, crcContext);
    if (status != CY_CRYPTO_SUCCESS)
    {
        crcContext->lfsrInitState = lfsrInitState;
        return status;
    }

    /* Restore the initial state provided by user, so that with one Cy_Crypto_Crc_CalcInit call
     * user can invoke multiple Cy_Crypto_Crc_Calc calls for multiple messages. */
    crcContext->lfsrInitState = lfsrInitState;
    crcContext->processState = CY_CRYPTO_CRC_INITIALIZED;

    return (CY_CRYPTO_SUCCESS);
}

/*******************************************************************************
* Function Name: Cy_Crypto_Crc_CalcPartial
****************************************************************************//**
*
* This function performs the CRC calculation of a message part.
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Crc_CalcPartial(CRYPTO_Type *base,
                                                void const *data,
                                                uint32_t dataSize,
                                                cy_stc_crypto_crc_context_t *crcContext)
{
    uint32_t size = dataSize;

    if (NULL == base || NULL == data || 0U == dataSize || NULL == crcContext)
    {
        return (CY_CRYPTO_BAD_PARAMS);
    }

    if (!Cy_Crypto_IsEnabled(base))
    {
        return (CY_CRYPTO_HW_NOT_ENABLED);
    }

    if ((CY_CRYPTO_CRC_INITIALIZED != crcContext->processState) && (CY_CRYPTO_CRC_PARTIAL_PROCESSED != crcContext->processState))
    {
        return (CY_CRYPTO_INVALID_OPERATION);
    }

    while (dataSize != 0U)
    {
        if (dataSize >= CY_CRYPTO_CRC_CHUNK_SIZE)
        {
            size = CY_CRYPTO_CRC_CHUNK_SIZE;
        }
        else
        {
            size = dataSize;
        }
        Cy_Crypto_Crc_ProcessBlock(base, data, size, crcContext);

        data = (uint8_t *)data + size;
        dataSize = dataSize - size;
    }

    /* Set CRC internal processing state */
    crcContext->processState = CY_CRYPTO_CRC_PARTIAL_PROCESSED;

    return (CY_CRYPTO_SUCCESS);
}

/*******************************************************************************
* Function Name: Cy_Crypto_Crc_CalcFinish
****************************************************************************//**
*
* This function completes the CRC calculation and writes the computed CRC value
* to memory pointed by the crc parameter.
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Crc_CalcFinish(CRYPTO_Type *base,
                                               uint32_t *crc,
                                               cy_stc_crypto_crc_context_t *crcContext)
{
    if (NULL == base || NULL == crc || NULL == crcContext)
    {
        return (CY_CRYPTO_BAD_PARAMS);
    }

    if (!Cy_Crypto_IsEnabled(base))
    {
        return (CY_CRYPTO_HW_NOT_ENABLED);
    }

    if (CY_CRYPTO_CRC_PARTIAL_PROCESSED != crcContext->processState)
    {
        return (CY_CRYPTO_INVALID_OPERATION);
    }

    *crc = crcContext->crc;

    /* The calculated CRC value is MSB-aligned and should be shifted WHEN REM_REVERSE is zero. */
    if (crcContext->remReverse == 0U)
    {
        *crc = *crc >> (CY_CRYPTO_HW_REGS_WIDTH - crcContext->width);
    }

    crcContext->processState = CY_CRYPTO_CRC_FINISHED;

    return (CY_CRYPTO_SUCCESS);
}

/*******************************************************************************
* Function Name: Cy_Crypto_Crc_CalcFree
****************************************************************************//**
*
* This function clears the CRC operation context.
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Crc_CalcFree(CRYPTO_Type *base,
                                             cy_stc_crypto_crc_context_t *crcContext)
{
    if (NULL == base || NULL == crcContext)
    {
        return (CY_CRYPTO_BAD_PARAMS);
    }

    if (!Cy_Crypto_IsEnabled(base))
    {
        return (CY_CRYPTO_HW_NOT_ENABLED);
    }

    if ((CY_CRYPTO_CRC_INITIALIZED != crcContext->processState) &&
        (CY_CRYPTO_CRC_PARTIAL_PROCESSED != crcContext->processState) &&
        (CY_CRYPTO_CRC_FINISHED != crcContext->processState))
    {
        return (CY_CRYPTO_INVALID_OPERATION);
    }

    (void) memset((char *)crcContext, 0, sizeof(cy_stc_crypto_crc_context_t));

    /* Clear the registers those are configured with CRC parameters. */
    REG_CRYPTO_CRC_DATA_CTL0(base) = 0;
    REG_CRYPTO_CRC_DATA_CTL1(base) = 0;
    REG_CRYPTO_CRC_POL_CTL(base) = 0;
    REG_CRYPTO_CRC_LFSR_CTL(base) = 0;
    REG_CRYPTO_CRC_REM_CTL0(base) = 0;
    REG_CRYPTO_CRC_REM_CTL1(base) = 0;

    return (CY_CRYPTO_SUCCESS);
}
#if defined(__cplusplus)
}
#endif

#endif /* CY_IP_MXCRYPTO */


/* [] END OF FILE */
