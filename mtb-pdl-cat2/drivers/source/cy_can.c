/*******************************************************************************
* \file cy_can.c
* \version 1.0
*
* \brief
* Provides an API implementation of the CAN driver.
*
********************************************************************************
* \copyright
* (c) (2025), Cypress Semiconductor Corporation (an Infineon company) or
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

#include "cy_can.h"

#if defined (CY_IP_M0S8CAN)

#if defined(__cplusplus)
extern "C" {
#endif

#define CY_CAN_INTERRUPT_ENABLE_DEFAULT ( \
    CAN_INT_EBL_GLOBAL_INT_ENBL_Msk | \
    CAN_INT_EBL_TX_MSG_ENBL_Msk | \
    CAN_INT_EBL_RX_MSG_ENBL_Msk \
)

#define CY_CAN_ERRORS_MASK ( \
    CAN_INT_STATUS_ARB_LOSS_Msk | \
    CAN_INT_STATUS_OVR_LOAD_Msk | \
    CAN_INT_STATUS_BIT_ERR_Msk | \
    CAN_INT_STATUS_STUFF_ERR_Msk | \
    CAN_INT_STATUS_ACK_ERR_Msk | \
    CAN_INT_STATUS_FORM_ERR_Msk | \
    CAN_INT_STATUS_CRC_ERR_Msk | \
    CAN_INT_STATUS_BUS_OFF_Msk | \
    CAN_INT_STATUS_RX_MSG_LOSS_Msk | \
    CAN_INT_STATUS_STUCK_AT_0_Msk | \
    CAN_INT_STATUS_SST_FAILURE_Msk \
)

#define CY_CAN_RX_MASK ( \
    CAN_INT_STATUS_RX_MSG_Msk | \
    CAN_INT_STATUS_RTR_MSG_Msk \
)

#define CY_CAN_STD_ID_Pos           (21UL)
#define CY_CAN_STD_ID_Msk           (0xFFE00000UL)
#define CY_CAN_XTD_ID_Pos           (3UL)
#define CY_CAN_XTD_ID_Msk           (0xFFFFFFF8UL)

/* In case of 11bit identifiers, lower 18bits should be all ones (dont care) */
#define AMR_STD_DONT_CARE           (0x001FFFF8UL)

/*******************************************************************************
* Function Name: Cy_CAN_Init
****************************************************************************//**
*
* Initializes the CAN module.
*
* \note The function enables the "Message was received" and
* "Message was sent" interrupt events only.
* Other interrupts can be configured with the Cy_CAN_SetInterruptMask() function.
*
* \param *base
* The pointer to a CAN instance.
*
* \param *config
* The pointer to the CAN configuration structure.
*
* \param *context
* The pointer to the context structure \ref cy_stc_can_context_t allocated
* by the user. The structure is used during the CAN operation for internal
* configuration and data retention. User must not modify anything in this
* structure.
*
* \return
* \ref cy_en_can_status_t
*
* \funcusage
* \snippet can_snippet.c snippet_Cy_CAN_Init
*
* \note After initialization CAN started with \ref CY_CAN_TEST_MODE_DISABLE
*
*******************************************************************************/
cy_en_can_status_t Cy_CAN_Init(CAN_Type *base,
                               const cy_stc_can_config_t *config,
                               cy_stc_can_context_t *context)
{
    cy_en_can_status_t ret = CY_CAN_BAD_PARAM;

    /* Checks for NULL pointers */
    if ((NULL != base) &&
        (NULL != context) &&
        (NULL != config) &&
        (NULL != config->bitrate) &&
        (NULL != config->rxBuffer)
       )
    {
        CY_ASSERT_L3(CY_CAN_IS_ARBITER_VALID(config->arbiter));
        CY_ASSERT_L3(CY_CAN_IS_ENDIAN_VALID(config->swapEndian));
        CY_ASSERT_L3(CY_CAN_IS_AUTO_RESTART_VALID(config->busOffRestart));
        CY_ASSERT_L2(CY_CAN_IS_RX_CFG_SIZE_VALID(config->numOfRxBuffers));

        /* Sets the notification callback functions */
        context->canTxInterruptFunction = config->txCallback;
        context->canRxInterruptFunction = config->rxCallback;
        context->canErrorInterruptFunction = config->errorCallback;

        /* Enables the CAN IP Block */
        CY_REG32_CLR_SET(base->CNTL, CAN_CNTL_IP_ENABLE, 1u);

        /* Sets the CAN controller to stop mode */
        (void) Cy_CAN_Stop(base);

        /* Sets the Test mode configuration */
        Cy_CAN_SetTestMode(CAN, CY_CAN_TEST_MODE_DISABLE);

        /* Sets transmit buffer arbiter */
        Cy_CAN_SetArbiter(base, config->arbiter);

        /* Sets the swap endian */
        Cy_CAN_SetSwapEndian(base, config->swapEndian);

        /* Sets prescaler and bit timing */
        Cy_CAN_SetBitrate(base, config->bitrate);

        /* Sets bus-off auto restart */
        Cy_CAN_SetBusOffAutoRestart(base, config->busOffRestart);

        /* Sets ECR mode to Capture mode */
        CY_REG32_CLR_SET(base->CONFIG, CAN_CONFIG_ECR_MODE, 1u);

        /* Sets Rx buffer configuration */
        {
            uint8_t index;
            cy_stc_can_rx_buffer_config_t dummy =
            {
                .enable = false
            };

            for (index = 0u; index < config->numOfRxBuffers; index++)
            {
                (void) Cy_CAN_UpdateRxBufferConfig(base, index, &(config->rxBuffer[index]), NULL);
            }
            for (; index < CY_CAN_MESSAGE_RX_BUFFERS_MAX_CNT; index++)
            {
                (void) Cy_CAN_UpdateRxBufferConfig(base, index, &dummy, NULL);
            }
        }

        /* Set interrupt enable */
        Cy_CAN_SetInterruptMask(base, CY_CAN_INTERRUPT_ENABLE_DEFAULT);

        /* Sets the CAN controller to start mode */
        (void) Cy_CAN_Start(base);

        ret = CY_CAN_SUCCESS;
    }

    return ret;
}


/*******************************************************************************
* Function Name: Cy_CAN_DeInit
****************************************************************************//**
*
* De-initializes the CAN module, returns registers values to default.
*
* \param *base
* The pointer to a CAN instance.
*
* \param *context
* The pointer to the context structure \ref cy_stc_can_context_t allocated
* by the user. The structure is used during the CAN operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \return
* \ref cy_en_can_status_t
*
* \funcusage
* \snippet can_snippet.c snippet_Cy_CAN_DeInit
*
*******************************************************************************/
cy_en_can_status_t Cy_CAN_DeInit(CAN_Type *base, cy_stc_can_context_t *context)
{
    cy_en_can_status_t ret;

    /* Resets the notification callback functions */
    context->canTxInterruptFunction = NULL;
    context->canRxInterruptFunction = NULL;
    context->canErrorInterruptFunction = NULL;

    /* Sets CAN controller to stop mode */
    ret = Cy_CAN_Stop(base);

    if (ret == CY_CAN_SUCCESS)
    {
        uint32_t index;

        /* De-initializes general registers */
        base->INT_STATUS        = 0x0000FFFCUL;
        base->INT_EBL           = 0UL;
        base->COMMAND           = 0UL;
        base->CONFIG            = 0UL;
        base->ECR               = 0UL;
        CY_REG32_CLR_SET(base->CNTL, CAN_CNTL_TT_ENABLE, 0U);   /* Keep IP_Enable = 1 */
        base->TTCAN_COUNTER     = 0UL;
        base->TTCAN_COMPARE     = 0xFFFF0000UL;
        base->TTCAN_TIMING      = 0UL;
        base->INTR_CAN          = (CAN_INTR_CAN_TT_CAPTURE_Msk |
                                   CAN_INTR_CAN_TT_COMPARE_Msk |
                                   CAN_INTR_CAN_INT_STATUS_Msk);
        base->INTR_CAN_MASK     = 0UL;

        /* De-initializes receive registers */
        for (index = 0u; index < CY_CAN_MESSAGE_RX_BUFFERS_MAX_CNT; index++)
        {
            base->RX[index].CONTROL     = (CAN_RX_CONTROL_WPNH_Msk |
                                           CAN_RX_CONTROL_WPNL_Msk |
                                           CAN_RX_CONTROL_MSG_AV_RTRSENT_Msk);
            base->RX[index].ID          = 0UL;
            base->RX[index].DATA_HIGH   = 0UL;
            base->RX[index].DATA_LOW    = 0UL;
            base->RX[index].AMR         = 0UL;
            base->RX[index].ACR         = 0UL;
            base->RX[index].AMR_DATA    = 0UL;
            base->RX[index].ACR_DATA    = 0UL;
        }

        /* De-initializes transmit registers */
        for (index = 0u; index < CY_CAN_MESSAGE_TX_BUFFERS_MAX_CNT; index++)
        {
            base->TX[index].CONTROL     = (CAN_TX_CONTROL_WPNH_Msk |
                                           CAN_TX_CONTROL_WPNL_Msk);
            base->TX[index].ID          = 0UL;
            base->TX[index].DATA_HIGH   = 0UL;
            base->TX[index].DATA_LOW    = 0UL;
        }

        /* Disables the CAN IP */
        CY_REG32_CLR_SET(base->CNTL, CAN_CNTL_IP_ENABLE, 0U);
    }

    return ret;
}


/*******************************************************************************
* Function Name: Cy_CAN_GetRxBufferStatus
****************************************************************************//**
*
* Gets the status of the CAN Rx buffer.
*
* \param *base
* The pointer to a CAN instance.
*
* \param index
* Rx Message buffer index (0-15).
*
* \return \ref cy_en_can_rx_buffer_status_t
*
* \funcusage
* \snippet can_snippet.c snippet_Cy_CAN_GetRxBufferStatus
*
*******************************************************************************/
cy_en_can_rx_buffer_status_t Cy_CAN_GetRxBufferStatus(CAN_Type const *base, uint32_t index)
{
    cy_en_can_rx_buffer_status_t enRxBufferStatus = CY_CAN_RX_BUFFER_EMPTY;
    
    CY_ASSERT_L2(CY_CAN_IS_MESSAGE_RX_BUFFER_IDX_VALID(index));

    if (0UL != ((base->BUFFER_STATUS >> index) & 1UL))
    {
        enRxBufferStatus = CY_CAN_RX_BUFFER_FILLED;
    }
    
    return enRxBufferStatus;
}


/*******************************************************************************
* Function Name: Cy_CAN_GetRxBuffer
****************************************************************************//**
*
* Reads the received message from Rx buffer.
*
* \note Remember to clear the MSG_AV_RTRSENT bit of CAN_CAN_RXn_CONTROL after
* the Rx buffer is read.
*
* \param *base
* The pointer to a CAN instance.
*
* \param index
* Rx Message buffer index (0-15).
*
* \param *rxMsg
* The pointer to a message structure to be stored.
*
* \return
* \ref cy_en_can_status_t
*
* \funcusage
* \snippet can_snippet.c snippet_Cy_CAN_GetRxBuffer
*
*******************************************************************************/
cy_en_can_status_t Cy_CAN_GetRxBuffer(CAN_Type *base, uint8_t index,
                                      cy_stc_can_message_frame_t *rxMsg)
{
    cy_en_can_status_t ret = CY_CAN_BAD_PARAM;

    /* Checks for the NULL pointers */
    if (NULL != rxMsg)
    {
        CY_ASSERT_L2(CY_CAN_IS_MESSAGE_RX_BUFFER_IDX_VALID(index));

        rxMsg->ide          = _FLD2BOOL(CAN_RX_CONTROL_IDE_FMT, base->RX[index].CONTROL);
        rxMsg->rtr          = _FLD2BOOL(CAN_RX_CONTROL_RTR_MSG, base->RX[index].CONTROL);
        rxMsg->length       = (uint8_t) _FLD2VAL(CAN_RX_CONTROL_DLC, base->RX[index].CONTROL);
        rxMsg->id           = (rxMsg->ide ?
                                _FLD2VAL(CY_CAN_XTD_ID, base->RX[index].ID) :
                                _FLD2VAL(CY_CAN_STD_ID, base->RX[index].ID));
        rxMsg->data[0u]     = base->RX[index].DATA_HIGH;
        rxMsg->data[1u]     = base->RX[index].DATA_LOW;
        ret = CY_CAN_SUCCESS;
    }

    return ret;
}


/*******************************************************************************
* Function Name: Cy_CAN_ExtractMsgFromRxBuffer
****************************************************************************//**
*
* Extracts the message data in the lowest numbered Rx buffer being received.
*
* \param *base
* The pointer to a CAN instance.
*
* \param *rxMsg
* The pointer to a message structure to be stored.
*
* \param context
* The pointer to the context structure \ref cy_stc_can_context_t allocated
* by the user. The structure is used during the CAN operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \return
* \ref cy_en_can_status_t
*
* \funcusage
* \snippet can_snippet.c snippet_Cy_CAN_ExtractMsgFromRxBuffer
*
*******************************************************************************/
cy_en_can_status_t Cy_CAN_ExtractMsgFromRxBuffer(CAN_Type *base,
                                                 cy_stc_can_message_frame_t *rxMsg,
                                                 const cy_stc_can_context_t *context)
{
    cy_en_can_status_t ret = CY_CAN_BAD_PARAM;
    uint8_t index;

    /* Checks for the NULL pointers */
    if ((NULL != rxMsg) && (NULL != context))
    {
        for (index = 0u; index < CY_CAN_MESSAGE_RX_BUFFERS_MAX_CNT; index++)
        {
            if (CY_CAN_RX_BUFFER_FILLED == Cy_CAN_GetRxBufferStatus(base, index))
            {
                ret = Cy_CAN_GetRxBuffer(base, index, rxMsg);

                if (CY_CAN_SUCCESS == ret)
                {
                    Cy_CAN_AckRxBuffer(base, index);
                    break;
                }
            }
        }
    }

    return ret;
}


/*******************************************************************************
* Function Name: Cy_CAN_IrqHandler
****************************************************************************//**
*
* CAN (Status/Error/Rx/Tx) interrupt ISR.
*
* \param *base
* The pointer to a CAN instance.
*
* \param *context
* The pointer to the context structure \ref cy_stc_can_context_t allocated
* by the user. The structure is used during the CAN operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
*******************************************************************************/
void Cy_CAN_IrqHandler(CAN_Type *base, const cy_stc_can_context_t *context)
{
    uint32_t intrStatus;
    uint8_t index;
    cy_stc_can_message_frame_t rxMsg;

    intrStatus = Cy_CAN_GetInterruptStatus(base);

    /* Other than a Tx/Rx interrupt occurred */
    if (0UL != (intrStatus & CY_CAN_ERRORS_MASK))
    {
        Cy_CAN_ClearInterrupt(base, (intrStatus & CY_CAN_ERRORS_MASK));

        /* Calls the callback function if it was set previously */
        if (NULL != context->canErrorInterruptFunction)
        {
            context->canErrorInterruptFunction(intrStatus);
        }
    }
    
    /* At least one received message must be stored into the Rx Buffer */
    if (0UL != (intrStatus & CY_CAN_RX_MASK))
    {
        Cy_CAN_ClearInterrupt(base, (intrStatus & CY_CAN_RX_MASK));

        for (index = 0u; index < CY_CAN_MESSAGE_RX_BUFFERS_MAX_CNT; index++)
        {
            if (CY_CAN_RX_BUFFER_FILLED == Cy_CAN_GetRxBufferStatus(base, index))
            {
                (void)Cy_CAN_GetRxBuffer(base, index, &rxMsg);

                Cy_CAN_AckRxBuffer(base, index);
                
                /* After a CAN message is received, checks if there is a callback function */
                /* Calls the callback function if it was set previously */
                if (NULL != context->canRxInterruptFunction)
                {
                    context->canRxInterruptFunction(index, &rxMsg);
                }
            }
        }
    }

    /* The CAN message is successfully transmitted */
    if (0UL != (intrStatus & CAN_INT_STATUS_TX_MSG_Msk))
    {
        Cy_CAN_ClearInterrupt(base, (intrStatus & CAN_INT_STATUS_TX_MSG_Msk));

        /* Calls the callback function if it was set previously */
        if (NULL != context->canTxInterruptFunction)
        {
            context->canTxInterruptFunction();
        }
    }
}


/*******************************************************************************
* Function Name: Cy_CAN_Transmit
****************************************************************************//**
*
* Stores the specified frame data in the Tx buffer and begins transmitting
* it immediately. And returns without waiting for transmission to
* complete.
*
* \param *base
* The pointer to a CAN instance.
*
* \param index
* Tx Message buffer index (0-15).
*
* \param *frameData
* The pointer to the frame data to be transmitted.
*
* \param interruptEnabled
* Specifies whether to interrupt when the message is transmitted successfully.
*
* \param singleShot
* Specifies whether to perform single shot transmission. In this case, even
* if the transmission fails, there will be no automatic retry.
*
* \param *context
* The pointer to the context structure \ref cy_stc_can_context_t allocated
* by the user. The structure is used during the CAN operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \return \ref cy_en_can_status_t
*
* \funcusage
* \snippet can_snippet.c snippet_Cy_CAN_Transmit
*
*******************************************************************************/
cy_en_can_status_t Cy_CAN_Transmit(CAN_Type *base, uint8_t index,
                                   const cy_stc_can_message_frame_t *frameData,
                                   bool interruptEnabled, bool singleShot,
                                   const cy_stc_can_context_t *context)
{
    cy_en_can_status_t ret = CY_CAN_BAD_PARAM;

    if ((NULL != frameData) && (NULL != context))
    {
        /* Check parameters */
        CY_ASSERT_L2(CY_CAN_IS_MESSAGE_TX_BUFFER_IDX_VALID(index));
        CY_ASSERT_L2(CY_CAN_IS_DLC_VALID(frameData->length));
        if (frameData->ide)
        {
            CY_ASSERT_L2(CY_CAN_IS_XTD_ID_VALID(frameData->id));
        }
        else
        {
            CY_ASSERT_L2(CY_CAN_IS_STD_ID_VALID(frameData->id));
        }

        /* Check that the CAN controller is running */
        if (!_FLD2BOOL(CAN_COMMAND_RUN, base->COMMAND))
        {
            ret = CY_CAN_NOT_STARTED;
        }
        /* Check that the Tx buffer is idle */
        else if (CY_CAN_TX_BUFFER_IDLE != Cy_CAN_GetTxBufferStatus(base, index))
        {
            ret = CY_CAN_BUSY;
        }
        else
        {
            /* Set frame data to Tx buffer */
            base->TX[index].CONTROL = _VAL2FLD(CAN_TX_CONTROL_WPNH, 1u) |
                                      _VAL2FLD(CAN_TX_CONTROL_RTR, frameData->rtr) |
                                      _VAL2FLD(CAN_TX_CONTROL_IDE, frameData->ide) |
                                      _VAL2FLD(CAN_TX_CONTROL_DLC, frameData->length) |
                                      _VAL2FLD(CAN_TX_CONTROL_WPNL, 1u) |
                                      _VAL2FLD(CAN_TX_CONTROL_TX_INT_EBL, interruptEnabled);

            base->TX[index].ID     = (frameData->ide ?
                                      _VAL2FLD(CY_CAN_XTD_ID, frameData->id) :
                                      _VAL2FLD(CY_CAN_STD_ID, frameData->id));

            base->TX[index].DATA_HIGH = frameData->data[0u];
            base->TX[index].DATA_LOW  = frameData->data[1u];

            /* Start to transmit */
            base->TX[index].CONTROL = (singleShot ? _VAL2FLD(CAN_TX_CONTROL_TX_ABORT, 1u) : 0u) |
                                       _VAL2FLD(CAN_TX_CONTROL_TX_REQ, 1u);

            ret = CY_CAN_SUCCESS;
        }
    }

    return ret;
}

/*******************************************************************************
* Function Name: Cy_CAN_GetTxBufferStatus
****************************************************************************//**
*
* Gets the status of the CAN Tx buffer.
*
* \param *base
* The pointer to a CAN instance.
*
* \param index
* Tx Message buffer index (0-7).
*
* \return \ref cy_en_can_tx_buffer_status_t
*
* \funcusage
* \snippet can_snippet.c snippet_Cy_CAN_GetTxBufferStatus
*
*******************************************************************************/
cy_en_can_tx_buffer_status_t Cy_CAN_GetTxBufferStatus(CAN_Type const *base, uint8_t index)
{
    cy_en_can_tx_buffer_status_t enTxBufferStatus = CY_CAN_TX_BUFFER_IDLE;

    CY_ASSERT_L2(CY_CAN_IS_MESSAGE_TX_BUFFER_IDX_VALID(index));

    if (0UL != (base->BUFFER_STATUS & (1UL << (index + CY_CAN_BUFFER_STATUS_TX_OFFSET))))
    {
        enTxBufferStatus = CY_CAN_TX_BUFFER_PENDING;
    }

    return enTxBufferStatus;
}


/*******************************************************************************
* Function Name: Cy_CAN_SetBitrate
****************************************************************************//**
*
* Sets Bit Timing and Prescaler Register parameters:
* -Time segment after sample point;
* -Time segment before sample point;
* -Baud Rate Prescaler;
* -Synchronization Jump Width.
*
* \note Before calling the Cy_CAN_SetBitrate() function,
* the \ref Cy_CAN_Stop() function must be called to stop
* the CAN controller.
*
* \param *base
* The pointer to a CAN instance.
*
* \param *bitrate \ref cy_stc_can_bitrate_t
*
* \funcusage
* \snippet can_snippet.c snippet_Cy_CAN_SetBitrate
*
*******************************************************************************/
void Cy_CAN_SetBitrate(CAN_Type *base, const cy_stc_can_bitrate_t *bitrate)
{
    uint32_t work;

    if (NULL != bitrate)
    {
        CY_ASSERT_L2(CY_CAN_IS_PRESCALER_VALID(bitrate->prescaler));
        CY_ASSERT_L2(CY_CAN_IS_TIME_SEG_1_VALID(bitrate->timeSegment1));
        CY_ASSERT_L2(CY_CAN_IS_TIME_SEG_2_VALID(bitrate->timeSegment2));
        CY_ASSERT_L2(CY_CAN_IS_SYNC_JUMP_WIDTH_VALID(bitrate->syncJumpWidth));

        work = base->CONFIG;
        work = _CLR_SET_FLD32U(work, CAN_CONFIG_CFG_TSEG2, bitrate->timeSegment2);
        work = _CLR_SET_FLD32U(work, CAN_CONFIG_CFG_TSEG1, bitrate->timeSegment1);
        work = _CLR_SET_FLD32U(work, CAN_CONFIG_CFG_BITRATE, bitrate->prescaler);
        work = _CLR_SET_FLD32U(work, CAN_CONFIG_CFG_SJW, bitrate->syncJumpWidth);
        base->CONFIG = work;
    }
}


/*******************************************************************************
* Function Name: Cy_CAN_Start
****************************************************************************//**
*
* Sets the CAN controller into run mode. If the Test Mode has been set
* beforehand by \ref Cy_CAN_SetTestMode, the controller will start
* operating in that mode.
*
* \param *base
* The pointer to a CAN instance.
*
* \return
* \ref cy_en_can_status_t
*
* \funcusage
* \snippet can_snippet.c snippet_Cy_CAN_Start
*
*******************************************************************************/
cy_en_can_status_t Cy_CAN_Start(CAN_Type *base)
{
    cy_en_can_status_t ret = CY_CAN_ERROR_TIMEOUT;
    uint32_t retry = CY_CAN_RETRY_COUNT;

    CY_REG32_CLR_SET(base->COMMAND, CAN_COMMAND_RUN, 1u);

    while ((retry > 0UL) && !_FLD2BOOL(CAN_COMMAND_RUN, base->COMMAND))
    {
        Cy_SysLib_DelayUs(CY_CAN_STOP_TIMEOUT_US);
        retry--;
    }

    if (0UL < retry )
    {
        ret = CY_CAN_SUCCESS;
    }

    return ret;
}


/*******************************************************************************
* Function Name: Cy_CAN_Stop
****************************************************************************//**
*
* Sets the CAN controller into stop mode.
*
* \param *base
* The pointer to a CAN instance.
*
* \return
* \ref cy_en_can_status_t
*
* \funcusage
* \snippet can_snippet.c snippet_Cy_CAN_Stop
*
*******************************************************************************/
cy_en_can_status_t Cy_CAN_Stop(CAN_Type *base)
{
    cy_en_can_status_t ret = CY_CAN_ERROR_TIMEOUT;
    uint32_t retry = CY_CAN_RETRY_COUNT;

    CY_REG32_CLR_SET(base->COMMAND, CAN_COMMAND_RUN, 0u);

    while ((retry > 0UL) && _FLD2BOOL(CAN_COMMAND_RUN, base->COMMAND))
    {
        Cy_SysLib_DelayUs(CY_CAN_STOP_TIMEOUT_US);
        retry--;
    }

    if (0UL < retry)
    {
        ret = CY_CAN_SUCCESS;
    }

    return ret;
}


/*******************************************************************************
* Function Name: Cy_CAN_UpdateRxBufferConfig
****************************************************************************//**
*
* Updates the specified Rx buffer configuration.
*
* \param *base
* The pointer to a CAN instance.
*
* \param index
* Rx Message buffer index (0-31).
*
* \param *config
* The pointer to the configuration data.
*
* \param *remoteFrame
* The pointer to the remote frame data. Sets to NULL if not used.
*
* \return \ref cy_en_can_status_t
*
* \funcusage
* \snippet can_snippet.c snippet_Cy_CAN_UpdateRxBufferConfig
*
*******************************************************************************/
cy_en_can_status_t Cy_CAN_UpdateRxBufferConfig(CAN_Type *base, uint8_t index,
                                               const cy_stc_can_rx_buffer_config_t *config,
                                               const cy_stc_can_message_frame_t *remoteFrame)
{
    cy_en_can_status_t ret = CY_CAN_BAD_PARAM;
    uint32_t work;

    if (NULL != config)
    {
        if (config->enable)
        {
            /* Check parameters */
            CY_ASSERT_L2(CY_CAN_IS_MESSAGE_RX_BUFFER_IDX_VALID(index));
            CY_ASSERT_L3(CY_CAN_IS_ID_TYPE_VALID(config->acceptanceMask.idType));
            CY_ASSERT_L3(CY_CAN_IS_ID_TYPE_VALID(config->acceptanceCode.idType));
            CY_ASSERT_L3(config->acceptanceCode.idType == config->acceptanceMask.idType);
            if (config->acceptanceMask.idType == CY_CAN_IDE_EXTENDED_ID)
            {
                CY_ASSERT_L2(CY_CAN_IS_XTD_ID_VALID(config->acceptanceMask.id));
            }
            else
            {
                CY_ASSERT_L2(CY_CAN_IS_STD_ID_VALID(config->acceptanceMask.id));
            }
            if (config->acceptanceCode.idType == CY_CAN_IDE_EXTENDED_ID)
            {
                CY_ASSERT_L2(CY_CAN_IS_XTD_ID_VALID(config->acceptanceCode.id));
            }
            else
            {
                CY_ASSERT_L2(CY_CAN_IS_STD_ID_VALID(config->acceptanceCode.id));
            }

            /* Disable the Rx buffer temporarily */
            work = base->RX[index].CONTROL;
            work &= (~CAN_RX_CONTROL_BUFFER_EN_Msk);
            work |= CAN_RX_CONTROL_WPNL_Msk;
            base->RX[index].CONTROL = work;

            /* Update acceptance filter setting */
            base->RX[index].AMR =   (config->acceptanceMask.idType == CY_CAN_IDE_EXTENDED_ID ?
                                     _VAL2FLD(CY_CAN_XTD_ID, config->acceptanceMask.id) :
                                     (_VAL2FLD(CY_CAN_STD_ID, config->acceptanceMask.id) | AMR_STD_DONT_CARE)) |
                                     _VAL2FLD(CAN_RX_AMR_IDE, config->acceptanceMask.ide) |
                                     _VAL2FLD(CAN_RX_AMR_RTR, config->acceptanceMask.rtr);
            base->RX[index].ACR =   (config->acceptanceCode.idType == CY_CAN_IDE_EXTENDED_ID ?
                                     _VAL2FLD(CY_CAN_XTD_ID, config->acceptanceCode.id) :
                                     _VAL2FLD(CY_CAN_STD_ID, config->acceptanceCode.id)) |
                                     _VAL2FLD(CAN_RX_ACR_IDE, config->acceptanceCode.ide) |
                                     _VAL2FLD(CAN_RX_ACR_RTR, config->acceptanceCode.rtr);
            base->RX[index].AMR_DATA = config->acceptanceMask.data;
            base->RX[index].ACR_DATA = config->acceptanceCode.data;

            /* Update the Rx buffer configuration */
            base->RX[index].CONTROL =   _VAL2FLD(CAN_RX_CONTROL_WPNH, 1u) |
                                        _VAL2FLD(CAN_RX_CONTROL_WPNL, 1u) |
                                        _VAL2FLD(CAN_RX_CONTROL_LINK_FLAG, config->linked) |
                                        _VAL2FLD(CAN_RX_CONTROL_RX_INT_EBL, config->interruptEnabled) |
                                        _VAL2FLD(CAN_RX_CONTROL_RTR_REPLY, config->autoReplyRtr) |
                                        CAN_RX_CONTROL_MSG_AV_RTRSENT_Msk;

            base->RX[index].ID        = 0UL;
            base->RX[index].DATA_HIGH = 0UL;
            base->RX[index].DATA_LOW  = 0UL;

            /* Update remote frame data if needed */
            if (NULL != remoteFrame)
            {
                CY_ASSERT_L2(CY_CAN_IS_DLC_VALID(remoteFrame->length));
                if (remoteFrame->ide)
                {
                    CY_ASSERT_L2(CY_CAN_IS_XTD_ID_VALID(remoteFrame->id));
                    base->RX[index].ID = _VAL2FLD(CY_CAN_XTD_ID, remoteFrame->id);
                }
                else
                {
                    CY_ASSERT_L2(CY_CAN_IS_STD_ID_VALID(remoteFrame->id));
                    base->RX[index].ID = _VAL2FLD(CY_CAN_STD_ID, remoteFrame->id);
                }

                base->RX[index].CONTROL = _VAL2FLD(CAN_RX_CONTROL_WPNH, 1u) |
                                          _VAL2FLD(CAN_RX_CONTROL_IDE_FMT, remoteFrame->ide) |
                                          _VAL2FLD(CAN_RX_CONTROL_DLC, remoteFrame->length);

                base->RX[index].DATA_HIGH = remoteFrame->data[0u];
                base->RX[index].DATA_LOW  = remoteFrame->data[1u];
            }

            /* Enable the Rx buffer */
            work = base->RX[index].CONTROL;
            work |= (CAN_RX_CONTROL_WPNL_Msk | CAN_RX_CONTROL_BUFFER_EN_Msk);
            base->RX[index].CONTROL = work;
        }
        else
        {
            /* If the Rx buffer is disabled, registers are set to default
               regardless of the parameter */
            base->RX[index].CONTROL     = (CAN_RX_CONTROL_WPNH_Msk |
                                           CAN_RX_CONTROL_WPNL_Msk |
                                           CAN_RX_CONTROL_MSG_AV_RTRSENT_Msk);
            base->RX[index].ID          = 0UL;
            base->RX[index].DATA_HIGH   = 0UL;
            base->RX[index].DATA_LOW    = 0UL;
            base->RX[index].AMR         = 0UL;
            base->RX[index].ACR         = 0UL;
            base->RX[index].AMR_DATA    = 0UL;
            base->RX[index].ACR_DATA    = 0UL;
        }

        ret = CY_CAN_SUCCESS;
    }

    return ret;
}

#if defined(__cplusplus)
}
#endif

#endif /* CY_IP_M0S8CAN */

/* [] END OF FILE */
