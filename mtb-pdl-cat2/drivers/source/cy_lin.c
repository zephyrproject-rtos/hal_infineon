/***************************************************************************//**
* \file cy_lin.c
* \version 1.10
*
* \brief
* Provides the public functions for the API for the LIN driver.
*
********************************************************************************
* \copyright
* Copyright (2024-2025) Cypress Semiconductor Corporation
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
#include "cy_lin.h"

#if defined (CY_IP_MXLIN)

#if defined(__cplusplus)
extern "C" {
#endif

/*******************************************************************************
* Function Name: Cy_LIN_DeInit
****************************************************************************//**
*
* \brief Deinitialization of a LIN module.
* This function deinitializes the selected LIN channel.
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \param base
*  Pointer to LIN instance channel register
*
* \return Refer \ref cy_en_lin_status_t
*
* \funcusage
* \snippet lin_snippet.c snippet_Cy_LIN_DeInit
*
*******************************************************************************/
cy_en_lin_status_t Cy_LIN_DeInit(LIN_CH_Type* base)
{
    cy_en_lin_status_t ret = CY_LIN_SUCCESS;
    /* Check if pointers are valid */
    if (NULL == base)
    {
        ret = CY_LIN_BAD_PARAM;
    }
    else
    {
        /* Disable the LIN Channel and set the values to default. */
        LIN_CH_CTL0(base) = LIN_CH_CTL0_DEFAULT;

        /* Clear the data registers */
        LIN_CH_DATA0(base) = 0UL;
        LIN_CH_DATA0(base) = 0UL;

        /* Clear the PID filed */
        LIN_CH_PID_CHECKSUM(base) &= ~(LIN_CH_PID_CHECKSUM_PID_Msk);
    }

    return ret;
}

/*******************************************************************************
* Function Name: Cy_LIN_Init
****************************************************************************//**
*
* \brief Initializes the LIN module.
* This function initializes LIN according to the options setup in the
* passed Config Struct. Several checkings are done before that and an error
* is returned if invalid Modes are requested.
*
* \pre The Application must configure corresponding LIN pins (SIN, SOT)
*      according to requirements and settings of LIN instance.
*      And must set baud rate using SysClk. LIN interface(I/F) has internal
*      fixed oversampling value (16). Therefore, LIN clock / 16 is actual
*      baud rate.
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \param base
*  Pointer to LIN instance channel register
* \param pstcConfig
*  LIN module configuration. See \ref cy_stc_lin_config_t.
*
* \return Refer \ref cy_en_lin_status_t
*
* \funcusage
* \snippet lin_snippet.c snippet_Cy_LIN_Init
*
*******************************************************************************/
cy_en_lin_status_t Cy_LIN_Init(LIN_CH_Type* base, const cy_stc_lin_config_t *pstcConfig)
{
    cy_en_lin_status_t ret = CY_LIN_SUCCESS;

    /* Check if pointers are valid */
    if ((NULL == base) || (NULL == pstcConfig))
    {
        ret = CY_LIN_BAD_PARAM;
    }
    else if (pstcConfig->masterMode &&
             ((LIN_MASTER_BREAK_FILED_LENGTH_MIN > pstcConfig->breakFieldLength) ||
              (LIN_BREAK_WAKEUP_LENGTH_BITS_MAX < pstcConfig->breakFieldLength)))
    {
        ret = CY_LIN_BAD_PARAM;
    }
    else if (LIN_BREAK_WAKEUP_LENGTH_BITS_MAX < pstcConfig->breakFieldLength)
    {
        ret = CY_LIN_BAD_PARAM;
    }
    else
    {
        LIN_CH_CTL0(base) =  (_VAL2FLD(LIN_CH_CTL0_STOP_BITS, pstcConfig->stopBit) | \
                              _VAL2FLD(LIN_CH_CTL0_AUTO_EN,  pstcConfig->linTransceiverAutoEnable) | \
                              _VAL2FLD(LIN_CH_CTL0_BREAK_DELIMITER_LENGTH, pstcConfig->breakDelimiterLength) | \
                              _VAL2FLD(LIN_CH_CTL0_BREAK_WAKEUP_LENGTH, (((uint32_t)pstcConfig->breakFieldLength) - 1U)) | \
                              _VAL2FLD(LIN_CH_CTL0_MODE, LIN_CH_CTL0_MODE_DEFAULT) | \
                              _VAL2FLD(LIN_CH_CTL0_BIT_ERROR_IGNORE, LIN_CH_CTL0_BIT_ERROR_IGNORE_DEFAULT) | \
                              _VAL2FLD(LIN_CH_CTL0_PARITY, LIN_CH_CTL0_PARITY_DEFAULT) | \
                              _VAL2FLD(LIN_CH_CTL0_PARITY_EN, LIN_CH_CTL0_PARITY_EN_DEFAULT) | \
                              _VAL2FLD(LIN_CH_CTL0_FILTER_EN, pstcConfig->filterEnable) | \
                              _VAL2FLD(LIN_CH_CTL0_ENABLED, 1U));

    }

    return ret;
}

/*******************************************************************************
* Function Name: Cy_LIN_ReadData
****************************************************************************//**
*
* \brief Reads response data.
* Data is read in Bytes. Maximum data length is 8-bytes.
*
* \pre Must be run after RX_RESPONSE_DONE.
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \param base
*  Pointer to LIN instance channel register
* \param data
*  Pointer to received data.
*  Must have enough space for current Rx data.
*
* \return Refer \ref cy_en_lin_status_t
*
* \funcusage
* \snippet lin_snippet.c snippet_Cy_LIN_ISR
*
*******************************************************************************/
cy_en_lin_status_t Cy_LIN_ReadData(const LIN_CH_Type* base, uint8_t *data)
{
    cy_en_lin_status_t ret = CY_LIN_SUCCESS;
    uint8_t cnt;
    uint8_t length;
    uint8_t data0[4];
    uint8_t data1[4];

    /* Check if pointers are valid */
    if((NULL == base) || (NULL == data))
    {
        ret = CY_LIN_BAD_PARAM;
    }
    /* Check if the response is received successfully */
    else if( ( 0U == _FLD2VAL(LIN_CH_CMD_TX_RESPONSE, LIN_CH_CMD(base)))  &&
             ( 0U == _FLD2VAL(LIN_CH_STATUS_RX_BUSY, LIN_CH_STATUS(base))))
    {
        length = (uint8_t)(_FLD2VAL(LIN_CH_CTL1_DATA_NR, LIN_CH_CTL1(base)) + 1U);
        /* Copy the data in to u8Data array */
        data0[0] = (uint8_t)_FLD2VAL(LIN_CH_DATA0_DATA1, LIN_CH_DATA0(base));
        data0[1] = (uint8_t)_FLD2VAL(LIN_CH_DATA0_DATA2, LIN_CH_DATA0(base));
        data0[2] = (uint8_t)_FLD2VAL(LIN_CH_DATA0_DATA3, LIN_CH_DATA0(base));
        data0[3] = (uint8_t)_FLD2VAL(LIN_CH_DATA0_DATA4, LIN_CH_DATA0(base));
        data1[0] = (uint8_t)_FLD2VAL(LIN_CH_DATA1_DATA5, LIN_CH_DATA1(base));
        data1[1] = (uint8_t)_FLD2VAL(LIN_CH_DATA1_DATA6, LIN_CH_DATA1(base));
        data1[2] = (uint8_t)_FLD2VAL(LIN_CH_DATA1_DATA7, LIN_CH_DATA1(base));
        data1[3] = (uint8_t)_FLD2VAL(LIN_CH_DATA1_DATA8, LIN_CH_DATA1(base));
        for ( cnt = 0; cnt < length; cnt++ )
        {
            if( 4U > cnt )
            {
                data[cnt] = data0[cnt];
            }
            else
            {
                data[cnt] = data1[cnt - 4U];
            }
        }
    }
    else
    {
        ret = CY_LIN_BUSY;
    }

    return ret;
}

/*******************************************************************************
* Function Name: Cy_LIN_WriteData
****************************************************************************//**
*
* \brief Writes response data.
* Data is written in Bytes. Maximum data length is 8-bytes.
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \param base
*  Pointer to LIN instance channel register
* \param  data
*  Pointer to response data.
* \param  dataLength
*  Data length in bytes.
*
* \return Refer \ref cy_en_lin_status_t
*
* \funcusage
* \snippet lin_snippet.c snippet_Cy_LIN_Sequence
*
*******************************************************************************/
cy_en_lin_status_t Cy_LIN_WriteData(LIN_CH_Type* base, const uint8_t *data, uint8_t dataLength)
{
    cy_en_lin_status_t ret = CY_LIN_SUCCESS;
    uint8_t data0[4U] = {0};
    uint8_t data1[4U] = {0};
    uint8_t cnt;

    /* Check if NULL pointer */
    if((NULL == base) || (NULL == data))
    {
        ret = CY_LIN_BAD_PARAM;
    }
    /* Check if data length is valid */
    else if( LIN_DATA_LENGTH_MAX < dataLength )
    {
        ret = CY_LIN_BAD_PARAM;
    }
    /* Check if the bus is free */
    else if( 0U == _FLD2VAL(LIN_CH_STATUS_TX_BUSY, LIN_CH_STATUS(base)) )
    {
        /* Write data in to the temp variables */
        for( cnt = 0U; cnt < dataLength; cnt++ )
        {
            if( 4U > cnt )
            {
                data0[cnt] = data[cnt];
            }
            else
            {
                data1[cnt - 4U] = data[cnt];
            }
        }
        /* Write data to HW FIFO */
        LIN_CH_DATA0(base) =   (_VAL2FLD(LIN_CH_DATA0_DATA1, data0[0]) | \
                                _VAL2FLD(LIN_CH_DATA0_DATA2, data0[1]) | \
                                _VAL2FLD(LIN_CH_DATA0_DATA3, data0[2]) | \
                                _VAL2FLD(LIN_CH_DATA0_DATA4, data0[3]));
        LIN_CH_DATA1(base) =   (_VAL2FLD(LIN_CH_DATA1_DATA5, data1[0]) | \
                                _VAL2FLD(LIN_CH_DATA1_DATA6, data1[1]) | \
                                _VAL2FLD(LIN_CH_DATA1_DATA7, data1[2]) | \
                                _VAL2FLD(LIN_CH_DATA1_DATA8, data1[3]));
    }
    else
    {
        ret = CY_LIN_BUSY;
        /* A requested operation could not be completed */
    }

    return ret;
}

/*******************************************************************************
* Function Name: Cy_LIN_Enable
****************************************************************************//**
*
* \brief Enables LIN channel.
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \param base
*  Pointer to LIN instance channel register
*
* \return Refer \ref cy_en_lin_status_t
*
* \funcusage
* \snippet lin_snippet.c snippet_Cy_LIN_Enable
*
*******************************************************************************/
cy_en_lin_status_t Cy_LIN_Enable(LIN_CH_Type* base)
{
    cy_en_lin_status_t ret = CY_LIN_SUCCESS;
    if (NULL == base)
    {
        ret = CY_LIN_BAD_PARAM;
    }
    else
    {
        LIN_CH_CTL0(base) |= _VAL2FLD(LIN_CH_CTL0_ENABLED, 1U);
    }

    return ret;
}

/*******************************************************************************
* Function Name: Cy_LIN_Disable
****************************************************************************//**
*
* \brief Disables LIN channel.
* Disabling LIN channel causes clearing of non retained registers.
* e.g) CMD register, INTR register, STATUS register.
* This behavior can be used for re-initialization, after error or
* abort RX operation.
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \param base
*  Pointer to LIN instance channel register
*
* \return Refer \ref cy_en_lin_status_t
*
* \funcusage
* \snippet lin_snippet.c snippet_Cy_LIN_Disable
*
*******************************************************************************/
cy_en_lin_status_t Cy_LIN_Disable(LIN_CH_Type* base)
{
    cy_en_lin_status_t ret = CY_LIN_SUCCESS;

    if (NULL == base)
    {
        ret = CY_LIN_BAD_PARAM;
    }
    else
    {
        LIN_CH_CTL0(base) &= ~(LIN_CH_CTL0_ENABLED_Msk);
    }

    return ret;
}

/*******************************************************************************
* Function Name: Cy_LIN_SetBreakWakeupFieldLength
****************************************************************************//**
*
* \brief Sets LIN break/wakeup field length.
* Normally this interface(I/F) is used for detection of the wakeup pulse.
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \param base
*  Pointer to LIN instance channel register
* \param  length
*  Bit length of the break/wakeup field. Value should be [1:31].
*  Zero and values bigger then 31 is incorrect.
*
*  \note To comply LIN standard wakeup length must be between
*  \ref LIN_MASTER_BREAK_FILED_LENGTH_MIN and \ref LIN_BREAK_WAKEUP_LENGTH_BITS_MAX
*
* \return Refer \ref cy_en_lin_status_t
*
*******************************************************************************/
cy_en_lin_status_t Cy_LIN_SetBreakWakeupFieldLength(LIN_CH_Type* base, uint8_t length)
{
    cy_en_lin_status_t ret = CY_LIN_SUCCESS;

    if (NULL == base)
    {
        ret = CY_LIN_BAD_PARAM;
    }
    else if ((LIN_BREAK_WAKEUP_LENGTH_BITS_MAX < length) || (0U == length))
    {
        ret = CY_LIN_BAD_PARAM;
    }
    else
    {
        CY_REG32_CLR_SET(LIN_CH_CTL0(base), LIN_CH_CTL0_BREAK_WAKEUP_LENGTH, (((uint32_t)length) - 1U));
    }

    return ret;
}

/*******************************************************************************
* Function Name: Cy_LIN_SetDataLength
****************************************************************************//**
*
* \brief Sets LIN response field data length.
* Data is in Bytes and maximum data length is 8-bytes.
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \param base
*  Pointer to LIN instance channel register
* \param  length
*  Data length in byte
*
* \return Refer \ref cy_en_lin_status_t
*
* \funcusage
* \snippet lin_snippet.c snippet_Cy_LIN_SetDataLength
*
*******************************************************************************/
cy_en_lin_status_t Cy_LIN_SetDataLength(LIN_CH_Type* base, uint8_t length)
{
    cy_en_lin_status_t ret = CY_LIN_SUCCESS;

    if ((NULL == base) ||
        (length > LIN_DATA_LENGTH_MAX) ||
        (length < LIN_DATA_LENGTH_MIN))
    {
        ret = CY_LIN_BAD_PARAM;
    }
    else
    {
        CY_REG32_CLR_SET(LIN_CH_CTL1(base), LIN_CH_CTL1_DATA_NR, (((uint32_t)length) - 1U));
    }

    return ret;
}

/*******************************************************************************
* Function Name: Cy_LIN_SetChecksumType
****************************************************************************//**
*
* \brief Sets LIN checksum type setting.
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \param base
*  Pointer to LIN instance channel register
* \param  type
* Checksum type. Refer \ref cy_en_lin_checksum_type_t
*
* \return Refer \ref cy_en_lin_status_t
*
* \funcusage
* \snippet lin_snippet.c snippet_Cy_LIN_SetChecksumType
*
*******************************************************************************/
cy_en_lin_status_t Cy_LIN_SetChecksumType(LIN_CH_Type* base, cy_en_lin_checksum_type_t type)
{
    cy_en_lin_status_t ret = CY_LIN_SUCCESS;

    if (NULL == base)
    {
        ret = CY_LIN_BAD_PARAM;
    }
    else
    {
        CY_REG32_CLR_SET(LIN_CH_CTL1(base), LIN_CH_CTL1_CHECKSUM_ENHANCED, type);
    }

    return ret;
}

/*******************************************************************************
* Function Name: Cy_LIN_SetCmd
****************************************************************************//**
*
* \brief Sets LIN operation command.
*
* \note As a normal usage, following combinations are used.
*       - Master
*         Header TX only          : LIN_CMD_TX_HEADER
*         Header TX & TX response : LIN_CMD_TX_HEADER_TX_RESPONSE
*         Header TX & RX response : LIN_CMD_TX_HEADER_RX_RESPONSE
*       - Slave
*         Header RX               : LIN_CMD_RX_HEADER_RX_RESPONSE
*         TX response             : LIN_CMD_TX_RESPONSE
*         RX response             : Already set when header RX
*         As a typical usage, RX response is always set at header RX phase.
*       - Wakeup frame            : LIN_CMD_TX_WAKEUP
*       Instead of above macro, you can use raw definition LIN_CH_CMD_*_Msk defined in IO header file.
*
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \param base
*  Pointer to LIN instance channel register
* \param  command
*  Required operation command. Refer \ref group_lin_cmd_macro
*
* \return Refer \ref cy_en_lin_status_t
*
* \funcusage
* \snippet lin_snippet.c snippet_Cy_LIN_SetCmd
*
*******************************************************************************/
cy_en_lin_status_t Cy_LIN_SetCmd(LIN_CH_Type* base, uint32_t command)
{
    cy_en_lin_status_t ret = CY_LIN_SUCCESS;

    if (NULL == base)
    {
        ret = CY_LIN_BAD_PARAM;
    }
    /* The command cannot have both TX_HEADER and RX_HEADER master set's TX_HEADER and slave sets RX_HEADER.
       If the Command is a wakeup command then TX_HEADER, RX_HEADER, TX_RESPONSE and RX_RESPONSE are not valid.
    */
    else if (((command & (LIN_CH_CMD_TX_HEADER_Msk | LIN_CH_CMD_RX_HEADER_Msk))
                == (LIN_CH_CMD_TX_HEADER_Msk | LIN_CH_CMD_RX_HEADER_Msk))   ||
            (((command & LIN_CH_CMD_TX_WAKEUP_Msk) != 0UL) &&
             ((command & (LIN_CH_CMD_TX_HEADER_Msk |
                          LIN_CH_CMD_TX_RESPONSE_Msk |
                          LIN_CH_CMD_RX_HEADER_Msk |
                          LIN_CH_CMD_RX_RESPONSE_Msk)) != 0UL)))
    {
        ret = CY_LIN_BAD_PARAM;
    }
    /* If software has already set the command and it is not complete then the channel must be busy processing the command.
       before setting the command make sure that hardware has already set the bit to 0 for the above cases.
    */
    else if (((_FLD2VAL(LIN_CH_CMD_TX_HEADER, LIN_CH_CMD(base)) != 0UL) && (command & LIN_CH_CMD_RX_HEADER_Msk) != 0UL) ||
             ((_FLD2VAL(LIN_CH_CMD_RX_HEADER, LIN_CH_CMD(base)) != 0UL) && (command & LIN_CH_CMD_TX_HEADER_Msk) != 0UL) ||
             ((_FLD2VAL(LIN_CH_CMD_TX_WAKEUP, LIN_CH_CMD(base)) != 0UL) &&
                            ((command & (LIN_CH_CMD_TX_HEADER_Msk |
                                         LIN_CH_CMD_TX_RESPONSE_Msk |
                                         LIN_CH_CMD_RX_HEADER_Msk |
                                         LIN_CH_CMD_RX_RESPONSE_Msk)) != 0UL)))
    {
        ret = CY_LIN_BUSY;
    }
    else
    {
        LIN_CH_CMD(base) = command;
    }

    return ret;
}
/** \cond INTERNAL */

/* Position of the 0th bit of the parity into the Header */
#define PARITY_BIT_0_Pos    (6U)

/* Position of the 1th bit of the parity into the Header */
#define PARITY_BIT_1_Pos    (7U)

/* Position of the two bit of the parity into the Header */
#define PARITY_Pos          PARITY_BIT_0_Pos

/** \endcond */

/*******************************************************************************
* Function Name: Cy_LIN_SetHeader
****************************************************************************//**
*
* \brief Sets LIN header for master tx header operation.
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \param base
*  Pointer to LIN instance channel register
* \param  id
*  ID value
*
* \return Refer \ref cy_en_lin_status_t
*
* \funcusage
* \snippet lin_snippet.c snippet_Cy_LIN_SetHeader
*
*******************************************************************************/
cy_en_lin_status_t Cy_LIN_SetHeader(LIN_CH_Type* base, uint8_t id)
{
    cy_en_lin_status_t ret = CY_LIN_SUCCESS;
    uint8_t tempPID;
    uint8_t parity_P1;
    uint8_t parity_P0;

    if ((NULL == base) ||
        (LIN_ID_MAX < id))
    {
        ret = CY_LIN_BAD_PARAM;
    }
    else
    {
        /* Calculate the Parity bits P0 & P1
           Parity is calculated as per the formula given
             - P[1] = ! (ID[5] ^ ID[4] ^ ID[3] ^ ID[1])
             - P[0] = (ID[4] ^ ID[2] ^ ID[1] ^ ID[0])
        */
        parity_P0 = ((id) ^ (id>>1U) ^
                     (id>>2U) ^ (id>>4U)) & 0x01U;
        parity_P1 = (~((id>>1U) ^ (id>>3U) ^
                       (id>>4U) ^ (id>>5U))) & 0x01U;
        /* Assign the Parity bits and the header values in to the tempPID */
        tempPID = 0;
        tempPID |= id;
        tempPID |= (uint8_t)(parity_P0 << PARITY_BIT_0_Pos);
        tempPID |= (uint8_t)(parity_P1 << PARITY_BIT_1_Pos);
        /* Write the TempID value in to the TX_HEADER register */
        LIN_CH_PID_CHECKSUM(base) = _VAL2FLD(LIN_CH_PID_CHECKSUM_PID, tempPID);
    }

    return ret;
}

/*******************************************************************************
* Function Name: Cy_LIN_GetHeader
****************************************************************************//**
*
* \brief Returns received LIN header.
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \param base
*  Pointer to LIN instance channel register
* \param  id
*  Received ID value.
* \param  parity
*  Pointer to received parity value.
* \note Note that parity check is always done by HW automatically.
*
* \return Refer \ref cy_en_lin_status_t
*
*******************************************************************************/
cy_en_lin_status_t Cy_LIN_GetHeader(const LIN_CH_Type* base, uint8_t *id, uint8_t *parity)
{
    cy_en_lin_status_t ret = CY_LIN_SUCCESS;

    if ((NULL == base) ||
        (NULL == id)   ||
        (NULL == parity))
    {
        ret = CY_LIN_BAD_PARAM;
    }
    else
    {
        /* Store received ID and parity bits */
        uint8_t temp = (uint8_t)_FLD2VAL(LIN_CH_PID_CHECKSUM_PID, LIN_CH_PID_CHECKSUM(base));
        *parity = (temp >> PARITY_Pos);
        *id = (temp & LIN_ID_MAX);
    }

    return ret;
}

/*******************************************************************************
* Function Name: Cy_LIN_SetInterruptMask
****************************************************************************//**
*
* \brief Sets interrupt source to be accepted
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \param base
*  Pointer to LIN instance channel register
* \param  mask
*  The mask with the OR of the interrupt source to be accepted.
*  See \ref group_lin_intr_mask_macro for the set of constants.
*
* \return Refer \ref cy_en_lin_status_t
*
* \funcusage
* \snippet lin_snippet.c snippet_Cy_LIN_Sequence
*
*******************************************************************************/
cy_en_lin_status_t Cy_LIN_SetInterruptMask(LIN_CH_Type* base, uint32_t mask)
{
    cy_en_lin_status_t ret = CY_LIN_SUCCESS;

    if (NULL == base)
    {
        ret = CY_LIN_BAD_PARAM;
    }
    else
    {
        LIN_CH_INTR_MASK(base) = mask;
    }

    return ret;
}

/*******************************************************************************
* Function Name: Cy_LIN_GetInterruptMask
****************************************************************************//**
*
* \brief Returns interrupt mask setting.
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \param base
*  Pointer to LIN instance channel register
* \param  mask
*  Pointer to the mask with the OR of the interrupt source which is masked.
*  See \ref group_lin_intr_mask_macro for the set of constants.
*
* \return Refer \ref cy_en_lin_status_t
*
* \funcusage
* \snippet lin_snippet.c snippet_Cy_LIN_Sequence
*
*******************************************************************************/
cy_en_lin_status_t Cy_LIN_GetInterruptMask(const LIN_CH_Type* base, uint32_t *mask)
{
    cy_en_lin_status_t ret = CY_LIN_SUCCESS;

    if ((NULL == base) || (NULL == mask))
    {
        ret = CY_LIN_BAD_PARAM;
    }
    else
    {
        *mask = LIN_CH_INTR_MASK(base);
    }

    return ret;
}

/*******************************************************************************
* Function Name: Cy_LIN_GetInterruptMaskedStatus
****************************************************************************//**
*
* \brief Returns interrupt masked status.
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \param base
*  Pointer to LIN instance channel register
* \param  status
*  Pointer to the mask with the OR of the interrupt source which occurs.
*  See \ref group_lin_intr_mask_macro for the set of constants.
*
* \return Refer \ref cy_en_lin_status_t
*
* \funcusage
* \snippet lin_snippet.c snippet_Cy_LIN_ISR
*
*******************************************************************************/
cy_en_lin_status_t Cy_LIN_GetInterruptMaskedStatus(const LIN_CH_Type* base, uint32_t *status)
{
    cy_en_lin_status_t ret = CY_LIN_SUCCESS;

    if ((NULL == base) || (NULL == status))
    {
        ret = CY_LIN_BAD_PARAM;
    }
    else
    {
        *status = LIN_CH_INTR_MASKED(base);
    }

    return ret;
}

/*******************************************************************************
* Function Name: Cy_LIN_GetInterruptStatus
****************************************************************************//**
*
* \brief Returns interrupt raw status.
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \param base
*  Pointer to LIN instance channel register
* \param  status
*  Pointer to the mask with the OR of the interrupt source which occurs.
*  See \ref group_lin_intr_mask_macro for the set of constants.
*
* \return Refer \ref cy_en_lin_status_t
*
* \funcusage
* \snippet lin_snippet.c snippet_Cy_LIN_ISR
*
*******************************************************************************/
cy_en_lin_status_t Cy_LIN_GetInterruptStatus(const LIN_CH_Type* base, uint32_t *status)
{
    cy_en_lin_status_t ret = CY_LIN_SUCCESS;

    if ((NULL == base) || (NULL == status))
    {
        ret = CY_LIN_BAD_PARAM;
    }
    else
    {
        *status = LIN_CH_INTR(base) ;
    }

    return ret;
}

/*******************************************************************************
* Function Name: Cy_LIN_ClearInterrupt
****************************************************************************//**
*
* \brief Clears interrupt status.
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \param base
*  Pointer to LIN instance channel register
* \param  mask
*  The mask with the OR of the interrupt source to be cleared.
*  See \ref group_lin_intr_mask_macro for the set of constants.
*
* \return Refer \ref cy_en_lin_status_t
*
* \funcusage
* \snippet lin_snippet.c snippet_Cy_LIN_ISR
*
*******************************************************************************/
cy_en_lin_status_t Cy_LIN_ClearInterrupt(LIN_CH_Type* base, uint32_t mask)
{
    cy_en_lin_status_t ret = CY_LIN_SUCCESS;

    if (NULL == base)
    {
        ret = CY_LIN_BAD_PARAM;
    }
    else
    {
        LIN_CH_INTR(base) = mask;
    }

    return ret;
}

/*******************************************************************************
* Function Name: Cy_LIN_GetStatus
****************************************************************************//**
*
* \brief
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \param base
*  Pointer to LIN instance channel register
* \param  status
*  LIN module status.
*
* \return Refer \ref cy_en_lin_status_t
*
* \funcusage
* \snippet lin_snippet.c snippet_Cy_LIN_ISR
*
*******************************************************************************/
cy_en_lin_status_t Cy_LIN_GetStatus(const LIN_CH_Type* base, uint32_t *status)
{
    cy_en_lin_status_t ret = CY_LIN_SUCCESS;

    if ((NULL == base) || (NULL == status))
    {
        ret = CY_LIN_BAD_PARAM;
    }
    else
    {
        *status = LIN_CH_STATUS(base);
    }

    return ret;
}

/*******************************************************************************
* Function Name: Cy_LIN_EnOut_Enable
****************************************************************************//**
*
* \brief Enables LIN channel 'en' out.
* If linTransceiverAutoEnable in \ref cy_stc_lin_config_t config structure is set to true
* then transceiver is set automatically and user need not call this function,
* else user has to enable LIN transceiver manually before sending a message,
* and disable it after sending the message.
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \param base
*  Pointer to LIN instance channel register
*
* \return Refer \ref cy_en_lin_status_t
*
* \funcusage
* \snippet lin_snippet.c snippet_Cy_LIN_Init_Example
*
*******************************************************************************/
cy_en_lin_status_t Cy_LIN_EnOut_Enable(LIN_CH_Type* base)
{
    cy_en_lin_status_t ret = CY_LIN_SUCCESS;
    bool auto_enable;

    if (NULL == base)
    {
        ret = CY_LIN_BAD_PARAM;
    }
    else
    {
        /* check if auto enabled is set or not */
        auto_enable = (_FLD2VAL(LIN_CH_CTL0_AUTO_EN, LIN_CH_CTL0(base)) != 0UL) ? true : false;
        if(!auto_enable)
        {
            /* Enable EN out  */
            LIN_CH_TX_RX_STATUS(base) |= _VAL2FLD(LIN_CH_TX_RX_STATUS_EN_OUT, 1U);
        }
    }

    return ret;
}

/*******************************************************************************
* Function Name: Cy_LIN_EnOut_Disable
****************************************************************************//**
*
* \brief Disables LIN channel 'en' out.
* If linTransceiverAutoEnable in cy_stc_lin_config_t config structure is set to true
* then transceiver is set automatically and user need not call this function,
* else user has to enable LIN transceiver manually before sending a message,
* and disable it after sending the message.
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \param base
*  Pointer to LIN instance channel register
*
* \return Refer \ref cy_en_lin_status_t
*
* \funcusage
* \snippet lin_snippet.c
*
*******************************************************************************/
cy_en_lin_status_t Cy_LIN_EnOut_Disable(LIN_CH_Type* base)
{
    cy_en_lin_status_t ret = CY_LIN_SUCCESS;
    bool auto_enable;

    if (NULL == base)
    {
        ret = CY_LIN_BAD_PARAM;
    }
    else
    {
        /* check if auto enabled is set or not */
        auto_enable = (_FLD2VAL(LIN_CH_CTL0_AUTO_EN, LIN_CH_CTL0(base)) != 0UL) ? true : false;
        if(!auto_enable)
        {
            /* Disable EN out  */
            LIN_CH_TX_RX_STATUS(base) &= ~LIN_CH_TX_RX_STATUS_EN_OUT_Msk;
        }
    }

    return ret;
}

/*******************************************************************************
* Function Name: Cy_LIN_TestMode_Enable
****************************************************************************//**
*
* \brief Enables LIN Testing mode.
* This testing functionality simplifies SW development,
* but may also be used in the field to verify correct channel functionality.
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \param base
*  Pointer to LIN instance channel register
* \param  linTestConfig
*  Pointer to Test configuration structure.
*
* \return Refer \ref cy_en_lin_status_t
*
* \funcusage
* \snippet lin_snippet.c snippet_Cy_LIN_Init_Example
*
*******************************************************************************/
cy_en_lin_status_t Cy_LIN_TestMode_Enable(LIN_Type* base, const cy_stc_lin_test_config_t* linTestConfig)
{
    cy_en_lin_status_t ret = CY_LIN_SUCCESS;

    if (NULL == base || NULL == linTestConfig)
    {
        ret = CY_LIN_BAD_PARAM;
    }
    else
    {
        CY_ASSERT_L3(CY_LIN_IS_TEST_CTL_CH_IDX_VALID(linTestConfig->chidx));
        /* Enable Test mode and set test configuration  */
        LIN_TEST_CTL(base) = (_VAL2FLD(LIN_TEST_CTL_CH_IDX, linTestConfig->chidx) | \
                              _VAL2FLD(LIN_TEST_CTL_MODE, linTestConfig->mode)    | \
                              _VAL2FLD(LIN_TEST_CTL_ENABLED, 1U));
    }

    return ret;
}

/*******************************************************************************
* Function Name: Cy_LIN_TestMode_Disable
****************************************************************************//**
*
* \brief Disables LIN Testing mode.
* This testing functionality simplifies SW development,
* but may also be used in the field to verify correct channel functionality.
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \param base
*  Pointer to LIN instance channel register
*
* \return Refer \ref cy_en_lin_status_t
*
*******************************************************************************/
cy_en_lin_status_t Cy_LIN_TestMode_Disable(LIN_Type* base)
{
    cy_en_lin_status_t ret = CY_LIN_SUCCESS;
    if (NULL == base)
    {
        ret = CY_LIN_BAD_PARAM;
    }
    else
    {
        /* Disable Test mode  */
        LIN_TEST_CTL(base) &= ~LIN_TEST_CTL_ENABLED_Msk;
    }

    return ret;
}

/*******************************************************************************
* Function Name: Cy_LIN_ErrCtl_Enable
****************************************************************************//**
*
* \brief Enables LIN ERROR CTL.
* Enables HW injected channel transmitter errors.
* The receiver should detect these errors and report these errors through activation
* of corresponding interrupt causes.
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \param base
*  Pointer to LIN instance channel register
* \param  testErrorConfig
*  Pointer to Test Error configuration structure.
*
* \return Refer \ref cy_en_lin_status_t
*
*******************************************************************************/
cy_en_lin_status_t Cy_LIN_ErrCtl_Enable(LIN_Type* base, cy_stc_lin_test_error_config_t* testErrorConfig)
{
    cy_en_lin_status_t ret = CY_LIN_SUCCESS;
    if (NULL == base)
    {
        ret = CY_LIN_BAD_PARAM;
    }
    else
    {
        /* LIN est Error CTL setting  */
        CY_ASSERT_L3(CY_LIN_IS_TEST_CTL_CH_IDX_VALID(testErrorConfig->chidx));
        LIN_ERROR_CTL(base) = (_VAL2FLD(LIN_ERROR_CTL_CH_IDX, testErrorConfig->chidx)                           | \
                               _VAL2FLD(LIN_ERROR_CTL_TX_SYNC_ERROR, testErrorConfig->txsync_error)             | \
                               _VAL2FLD(LIN_ERROR_CTL_TX_SYNC_STOP_ERROR, testErrorConfig->txsyncStop_error)    | \
                               _VAL2FLD(LIN_ERROR_CTL_TX_PARITY_ERROR, testErrorConfig->txParity_error)         | \
                               _VAL2FLD(LIN_ERROR_CTL_TX_PID_STOP_ERROR, testErrorConfig->txPIDStop_error)      | \
                               _VAL2FLD(LIN_ERROR_CTL_TX_DATA_STOP_ERROR, testErrorConfig->txDataStop_error)    | \
                               _VAL2FLD(LIN_ERROR_CTL_TX_CHECKSUM_ERROR, testErrorConfig->txChecksum_error)     | \
                               _VAL2FLD(LIN_ERROR_CTL_TX_CHECKSUM_STOP_ERROR, testErrorConfig->txChecksumStop_error) | \
                               _VAL2FLD(LIN_ERROR_CTL_ENABLED, 1U));
    }

    return ret;
}

/*******************************************************************************
* Function Name: Cy_LIN_ErrCtl_Disable
****************************************************************************//**
*
* \brief Disables LIN ERROR CTL.
* Disables HW injected channel transmitter errors.
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \param base
*  Pointer to LIN instance channel register
*
* \return Refer \ref cy_en_lin_status_t
*
* \funcusage
* \snippet lin_snippet.c
*
*******************************************************************************/
cy_en_lin_status_t Cy_LIN_ErrCtl_Disable(LIN_Type* base)
{
    cy_en_lin_status_t ret = CY_LIN_SUCCESS;
    if (NULL == base)
    {
        ret = CY_LIN_BAD_PARAM;
    }
    else
    {
        /* Disable Test Error Control mode  */
        LIN_ERROR_CTL(base) &= ~LIN_ERROR_CTL_ENABLED_Msk;
    }

    return ret;
}

#if defined(__cplusplus)
}
#endif

#endif /* (CY_IP_MXLIN) */

/* [] END OF FILE */

