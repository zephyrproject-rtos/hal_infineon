/***************************************************************************//**
* \file cy_scb_common.c
* \version 3.30
*
* Provides common API implementation of the SCB driver.
*
********************************************************************************
* \copyright
* (c) 2016-2026, Infineon Technologies AG or an affiliate of
* Infineon Technologies AG.
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

#if (defined (CY_IP_MXSCB) || defined (CY_IP_MXS22SCB))

#include "cy_scb_common.h"

#if defined(__cplusplus)
extern "C" {
#endif

#ifdef AROM_SUPPORTED
/*******************************************************************************
* Function Name: Cy_SCB_GetNumInRxFifo
****************************************************************************//**
*
* Returns the number of data elements currently in the RX FIFO.
*
* \param base
* The pointer to the SCB instance.
*
* \return
* The number or data elements in RX FIFO.
*
*******************************************************************************/
uint32_t Cy_SCB_GetNumInRxFifo(CySCB_Type const *base)
{
    return _FLD2VAL(SCB_RX_FIFO_STATUS_USED, SCB_RX_FIFO_STATUS(base));
}

/*******************************************************************************
* Function Name: Cy_SCB_GetNumInTxFifo
****************************************************************************//**
*
* Returns the number of data elements currently in the TX FIFO.
*
* \param base
* The pointer to the SCB instance.
*
* \return
* The number or data elements in the TX FIFO.
*
*******************************************************************************/
uint32_t Cy_SCB_GetNumInTxFifo(CySCB_Type const *base)
{
    return _FLD2VAL(SCB_TX_FIFO_STATUS_USED, SCB_TX_FIFO_STATUS(base));
}

/** \cond INTERNAL */
/*******************************************************************************
* Function Name: Cy_SCB_GetFifoSize
****************************************************************************//**
*
* Returns the RX and TX FIFO depth.
*
* \param base
* The pointer to the SCB instance.
*
* \return
* FIFO depth.
*
*******************************************************************************/
uint32_t Cy_SCB_GetFifoSize(CySCB_Type const *base)
{
#if((defined (CY_IP_MXSCB_VERSION) && (CY_IP_MXSCB_VERSION>=2)) || defined (CY_IP_MXS22SCB))
    {return (((uint32_t)(CY_SCB_FIFO_SIZE)) >> _FLD2VAL(SCB_CTRL_MEM_WIDTH, SCB_CTRL(base)));}
#elif(defined (CY_IP_MXSCB_VERSION) && (CY_IP_MXSCB_VERSION==1))
    {return (_FLD2BOOL(SCB_CTRL_BYTE_MODE, SCB_CTRL(base)) ? (CY_SCB_FIFO_SIZE) : (CY_SCB_FIFO_SIZE / 2UL));}
#else
    return 0;
#endif /* ((CY_IP_MXSCB_VERSION>=2) || defined (CY_IP_MXS22SCB)) */

}
/** \endcond */
#endif

/*******************************************************************************
* Function Name: Cy_SCB_ReadArrayNoCheck
****************************************************************************//**
*
* Reads an array of data out of the SCB receive FIFO without checking if the
* receive FIFO has enough data elements.
* Before calling this function, make sure that the receive FIFO has enough data
* elements to be read.
*
* \param base
* The pointer to the SCB instance.
*
* \param buffer
* The pointer to location to place data read from the receive FIFO.
* The size of the data element defined by the configured data width.
*
* \param size
* The number of data elements read from the receive FIFO.
*
*******************************************************************************/
void Cy_SCB_ReadArrayNoCheck(CySCB_Type const *base, void *buffer, uint32_t size)
{
    uint32_t idx;
#if((defined (CY_IP_MXSCB_VERSION) && CY_IP_MXSCB_VERSION==1))
    if (Cy_SCB_IsRxDataWidthByte(base))
    {
        uint8_t *buf = (uint8_t *) buffer;

        /* Get data available in RX FIFO */
        for (idx = 0UL; idx < size; ++idx)
        {
            buf[idx] = (uint8_t) Cy_SCB_ReadRxFifo(base);
        }
    }
    else
    {
        uint16_t *buf = (uint16_t *) buffer;

        /* Get data available in RX FIFO */
        for (idx = 0UL; idx < size; ++idx)
        {
            buf[idx] = (uint16_t) Cy_SCB_ReadRxFifo(base);
        }
    }
#elif((defined (CY_IP_MXSCB_VERSION) && (CY_IP_MXSCB_VERSION>=2)) || defined (CY_IP_MXS22SCB))
    uint32_t datawidth = Cy_SCB_Get_RxDataWidth(base);

    if (datawidth <= CY_SCB_BYTE_WIDTH)
    {
        uint8_t *buf = (uint8_t *) buffer;

        /* Get data available in RX FIFO */
        for (idx = 0UL; idx < size; ++idx)
        {
            buf[idx] = (uint8_t) Cy_SCB_ReadRxFifo(base);
        }
    }
    else if(datawidth <= CY_SCB_HALF_WORD_WIDTH)
    {
        uint16_t *buf = (uint16_t *) buffer;

        /* Get data available in RX FIFO */
        for (idx = 0UL; idx < size; ++idx)
        {
            buf[idx] = (uint16_t) Cy_SCB_ReadRxFifo(base);
        }
    }
    else
    {
        uint32_t *buf = (uint32_t *) buffer;

        /* Get data available in RX FIFO */
        for (idx = 0UL; idx < size; ++idx)
        {
            buf[idx] = (uint32_t) Cy_SCB_ReadRxFifo(base);
        }
    }
#endif /* CY_IP_MXSCB_VERSION */
}


/*******************************************************************************
* Function Name: Cy_SCB_ReadArray
****************************************************************************//**
*
* Reads an array of data out of the SCB receive FIFO.
* This function does not block; it returns how many data elements are
* read from the receive FIFO.
*
* \param base
* The pointer to the SCB instance.
*
* \param buffer
* The pointer to location to place data read from receive FIFO.
* The item size is defined by the data type, which depends on the configured
* data width.
*
* \param size
* The number of data elements to read from the receive FIFO.
*
* \return
* The number of data elements read from the receive FIFO.
*
*******************************************************************************/
uint32_t Cy_SCB_ReadArray(CySCB_Type const *base, void *buffer, uint32_t size)
{
    /* Get available items in RX FIFO */
    uint32_t numToCopy = Cy_SCB_GetNumInRxFifo(base);

    /* Adjust items that will be read */
    if (numToCopy > size)
    {
        numToCopy = size;
    }

    /* Get data available in RX FIFO */
    Cy_SCB_ReadArrayNoCheck(base, buffer, numToCopy);

    return (numToCopy);
}


/*******************************************************************************
* Function Name: Cy_SCB_ReadArrayBlocking
****************************************************************************//**
*
* Reads an array of data out of the SCB receive FIFO.
* This function blocks until the number of data elements specified by the
* size has been read from the receive FIFO.
*
* \param base
* The pointer to the SCB instance.
*
* \param buffer
* The pointer to the location to place data read from the receive FIFO.
* The item size is defined by the data type, which depends on the configured
* data width.
*
* \param size
* The number of data elements to read from receive FIFO.
*
*******************************************************************************/
void Cy_SCB_ReadArrayBlocking(CySCB_Type const *base, void *buffer, uint32_t size)
{
    uint32_t numCopied;
    uint8_t  *buf = (uint8_t *) buffer;
#if((defined (CY_IP_MXSCB_VERSION) && (CY_IP_MXSCB_VERSION>=2)) || defined (CY_IP_MXS22SCB))
    uint32_t datawidth = Cy_SCB_Get_RxDataWidth(base);
#elif((defined (CY_IP_MXSCB_VERSION) && CY_IP_MXSCB_VERSION==1))
    bool     byteMode = Cy_SCB_IsRxDataWidthByte(base);
#endif /* CY_IP_MXSCB_VERSION */
    /* Get data from RX FIFO. Stop when the requested size is read. */
    while (size > 0UL)
    {
        numCopied = Cy_SCB_ReadArray(base, (void *) buf, size);
#if((defined (CY_IP_MXSCB_VERSION) && (CY_IP_MXSCB_VERSION>=2)) || defined (CY_IP_MXS22SCB))
        buf = &buf[((datawidth/8UL) * numCopied)];
#elif((defined (CY_IP_MXSCB_VERSION) && CY_IP_MXSCB_VERSION==1))
        buf = &buf[(byteMode ? (numCopied) : (2UL * numCopied))];
#endif /* CY_IP_MXSCB_VERSION */
        size -= numCopied;
    }
}


/*******************************************************************************
* Function Name: Cy_SCB_Write
****************************************************************************//**
*
* Places a single data element in the SCB transmit FIFO.
* This function does not block. It returns how many data elements are placed
* in the transmit FIFO.
*
* \param base
* The pointer to the SCB instance.
*
* \param data
* Data to put in the transmit FIFO.
* The item size is defined by the data type, which depends on the configured
* data width.
*
* \return
* The number of data elements placed in the transmit FIFO: 0 or 1.
*
*******************************************************************************/
uint32_t Cy_SCB_Write(CySCB_Type *base, uint32_t data)
{
    uint32_t numCopied = 0UL;

    if (Cy_SCB_GetFifoSize(base) != Cy_SCB_GetNumInTxFifo(base))
    {
        Cy_SCB_WriteTxFifo(base, data);

        numCopied = 1UL;
    }

    return (numCopied);
}


/*******************************************************************************
* Function Name: Cy_SCB_WriteArrayNoCheck
****************************************************************************//**
*
* Places an array of data in the SCB transmit FIFO without checking whether the
* transmit FIFO has enough space.
* Before calling this function, make sure that the transmit FIFO has enough
* space to put all requested data elements.
*
* \param base
* The pointer to the SCB instance.
*
* \param buffer
* The pointer to data to place in the transmit FIFO.
* The item size is defined by the data type, which depends on the configured
* TX data width.
*
* \param size
* The number of data elements to transmit.
*
* \return
* The number of data elements placed in the transmit FIFO.
*
*******************************************************************************/
void Cy_SCB_WriteArrayNoCheck(CySCB_Type *base, void *buffer, uint32_t size)
{
    uint32_t idx;
#if((defined (CY_IP_MXSCB_VERSION) && CY_IP_MXSCB_VERSION==1))
    if (Cy_SCB_IsTxDataWidthByte(base))
    {
        uint8_t *buf = (uint8_t *) buffer;

        /* Put data into TX FIFO */
        for (idx = 0UL; idx < size; ++idx)
        {
            Cy_SCB_WriteTxFifo(base, (uint32_t) buf[idx]);
        }
    }
    else
    {
        uint16_t *buf = (uint16_t *) buffer;

        /* Put data into TX FIFO */
        for (idx = 0UL; idx < size; ++idx)
        {
            Cy_SCB_WriteTxFifo(base, (uint32_t) buf[idx]);
        }
    }
#elif((defined (CY_IP_MXSCB_VERSION) && (CY_IP_MXSCB_VERSION>=2)) || defined (CY_IP_MXS22SCB))
    uint32_t datawidth = Cy_SCB_Get_TxDataWidth(base);

    if (datawidth <= CY_SCB_BYTE_WIDTH)
    {
        uint8_t *buf = (uint8_t *) buffer;

        /* Put data into TX FIFO */
        for (idx = 0UL; idx < size; ++idx)
        {
            Cy_SCB_WriteTxFifo(base, (uint32_t) buf[idx]);
        }
    }
    else if(datawidth <= CY_SCB_HALF_WORD_WIDTH)
    {
        uint16_t *buf = (uint16_t *) buffer;

        /* Put data into TX FIFO */
        for (idx = 0UL; idx < size; ++idx)
        {
            Cy_SCB_WriteTxFifo(base, (uint32_t) buf[idx]);
        }
    }
    else
    {
        uint32_t *buf = (uint32_t *) buffer;

        /* Put data into TX FIFO */
        for (idx = 0UL; idx < size; ++idx)
        {
            Cy_SCB_WriteTxFifo(base, (uint32_t) buf[idx]);
        }
    }
#endif /* CY_IP_MXSCB_VERSION */
}


/*******************************************************************************
* Function Name: Cy_SCB_WriteArray
****************************************************************************//**
*
* Places an array of data in the SCB transmit FIFO.
* This function does not block. It returns how many data elements were
* placed in the transmit FIFO.
*
* \param base
* The pointer to the SCB instance.
*
* \param buffer
* The pointer to data to place in the transmit FIFO.
* The item size is defined by the data type which depends on the configured
* TX data width.
*
* \param size
* The number of data elements to transmit.
*
* \return
* The number of data elements placed in the transmit FIFO.
*
*******************************************************************************/
uint32_t Cy_SCB_WriteArray(CySCB_Type *base, void *buffer, uint32_t size)
{
    /* Get free entries in TX FIFO */
    uint32_t numToCopy = Cy_SCB_GetFifoSize(base) - Cy_SCB_GetNumInTxFifo(base);

    /* Adjust the data elements to write */
    if (numToCopy > size)
    {
        numToCopy = size;
    }

    Cy_SCB_WriteArrayNoCheck(base, buffer, numToCopy);

    return (numToCopy);
}


/*******************************************************************************
* Function Name: Cy_SCB_WriteArrayBlocking
****************************************************************************//**
*
* Places an array of data in the transmit FIFO.
* This function blocks until the number of data elements specified by the size
* is placed in the transmit FIFO.
*
* \param base
* The pointer to the SCB instance.
*
* \param buffer
* The pointer to data to place in transmit FIFO.
* The item size is defined by the data type, which depends on the configured
* data width.
*
* \param size
* The number of data elements to write into the transmit FIFO.
*
*******************************************************************************/
void Cy_SCB_WriteArrayBlocking(CySCB_Type *base, void *buffer, uint32_t size)
{
    uint32_t numCopied;
    uint8_t  *buf = (uint8_t *) buffer;
#if((defined (CY_IP_MXSCB_VERSION) && (CY_IP_MXSCB_VERSION>=2)) || defined (CY_IP_MXS22SCB))
    uint32_t datawidth = Cy_SCB_Get_TxDataWidth(base);
#elif((defined (CY_IP_MXSCB_VERSION) && CY_IP_MXSCB_VERSION==1))
    bool     byteMode = Cy_SCB_IsTxDataWidthByte(base);
#endif /* CY_IP_MXSCB_VERSION */
    /* Get data from RX FIFO. Stop when the requested size is read. */
    while (size > 0UL)
    {
        numCopied = Cy_SCB_WriteArray(base, (void *) buf, size);
#if((defined (CY_IP_MXSCB_VERSION) && (CY_IP_MXSCB_VERSION>=2)) || defined (CY_IP_MXS22SCB))
        buf = &buf[((datawidth/8UL) * numCopied)];
#elif((defined (CY_IP_MXSCB_VERSION) && CY_IP_MXSCB_VERSION==1))
        buf = &buf[(byteMode ? (numCopied) : (2UL * numCopied))];
#endif /* CY_IP_MXSCB_VERSION */
        size -= numCopied;
    }
}


/*******************************************************************************
* Function Name: Cy_SCB_WriteString
****************************************************************************//**
*
* Places a NULL terminated string in the transmit FIFO.
* This function blocks until the entire string is placed in the transmit FIFO.
*
* \param base
* The pointer to the SCB instance.
*
* \param string
* The pointer to the null terminated string array.
*
*******************************************************************************/
void Cy_SCB_WriteString(CySCB_Type *base, char_t const string[])
{
    uint32_t idx = 0UL;
    uint32_t fifoSize = Cy_SCB_GetFifoSize(base);

    /* Put data from TX FIFO. Stop when string is terminated */
    while (((char_t) 0) != string[idx])
    {
        /* Wait for free space to be available */
        while (fifoSize == Cy_SCB_GetNumInTxFifo(base))
        {
        }

        Cy_SCB_WriteTxFifo(base, (uint32_t) string[idx]);
        ++idx;
    }
}


/*******************************************************************************
* Function Name: Cy_SCB_WriteDefaultArrayNoCheck
****************************************************************************//**
*
* Places a number of the same data elements in the SCB transmit FIFO without
* checking whether the transmit FIFO has enough space. The data elements is equal
* to txData parameter.
* Before calling this function, make sure that transmit FIFO has enough space
* to put all requested data elements.
*
* \param base
* The pointer to the SCB instance.
*
* \param txData
* The data element to transmit repeatedly.
*
* \param size
* The number of data elements to transmit.
*
*******************************************************************************/
void Cy_SCB_WriteDefaultArrayNoCheck(CySCB_Type *base, uint32_t txData, uint32_t size)
{
    while (size > 0UL)
    {
        Cy_SCB_WriteTxFifo(base, txData);
        --size;
    }
}


/*******************************************************************************
* Function Name: Cy_SCB_WriteDefaultArray
****************************************************************************//**
*
* Places a number of the same data elements in the SCB transmit FIFO.
* The data elements is equal to the txData parameter.
*
* \param base
* The pointer to the SCB instance.
*
* \param txData
* The data element to transmit repeatedly.
*
* \param size
* The number of data elements to transmit.
*
* \return
* The number of data elements placed in the transmit FIFO.
*
*******************************************************************************/
uint32_t Cy_SCB_WriteDefaultArray(CySCB_Type *base, uint32_t txData, uint32_t size)
{
    /* Get free entries in TX FIFO */
    uint32_t numToCopy = Cy_SCB_GetFifoSize(base) - Cy_SCB_GetNumInTxFifo(base);

    /* Adjust data elements to write */
    if (numToCopy > size)
    {
        numToCopy = size;
    }

    Cy_SCB_WriteDefaultArrayNoCheck(base, txData, numToCopy);

    return (numToCopy);
}

#if ((defined(CY_IP_MXSCB_VERSION) && (CY_IP_MXSCB_VERSION>=4) && (CY_IP_MXSCB_VERSION_MINOR>=4)) || defined (CY_DOXYGEN))

/*******************************************************************************
* Function Name: Cy_SCB_TGSx_Init
****************************************************************************//**
*
* Initializes the Timeout Generation support in SCB.
*
* \param base
* The pointer to the SCB instance.
*
* \param cntNum
* The counter number (0, 1, 2).
*
* \param config
* The pointer to the configuration structure \ref cy_stc_scb_tgs_config_t.
*
* \return
* \ref cy_en_scb_tgs_status_t
*
* \note
* If SCB is already enabled, ensure that the SCB block is disabled \ref Cy_SCB_I2C_Disable
* before calling this function.
*
* \note
* This API is only available for devices containing TGS functionality.
*
*******************************************************************************/
cy_en_scb_tgs_status_t Cy_SCB_TGSx_Init(CySCB_Type *base, uint8_t cntNum, cy_stc_scb_tgs_config_t const *config)
{
    if ((NULL == base) || (NULL == config) || (cntNum >= CY_SCB_TGS_CNT_MAX))
    {
        return CY_SCB_TGS_BAD_PARAM;
    }

    uint32_t tgs_ctl = _BOOL2FLD(SCB_TGS_CTL0_TR_TXFIFO, config->reloadTx) |
                        _BOOL2FLD(SCB_TGS_CTL0_TR_RXFIFO, config->reloadRx) |
                        _BOOL2FLD(SCB_TGS_CTL0_TR_FCLK, config->reloadClkFall) |
                        _BOOL2FLD(SCB_TGS_CTL0_TR_RCLK, config->reloadClkRise) |
                        _BOOL2FLD(SCB_TGS_CTL0_TR_UART_S, config->reloadUartStart) |
                        _BOOL2FLD(SCB_TGS_CTL0_TR_SPI_S, config->reloadSpiSel) |
                        _BOOL2FLD(SCB_TGS_CTL0_TR_I2C_S, config->reloadI2cStart) |
                        _BOOL2FLD(SCB_TGS_CTL0_TR_RI2CACK, config->reloadI2cAckRise) |
                        _BOOL2FLD(SCB_TGS_CTL0_TR_FI2CACK, config->reloadI2cAckFall) |
                        _BOOL2FLD(SCB_TGS_CTL0_TR_DPSLP2ACT, config->reloadWakeup) |
                        _BOOL2FLD(SCB_TGS_CTL0_TR_CLK_H, config->gateClkHigh) |
                        _BOOL2FLD(SCB_TGS_CTL0_TR_CLK_L, config->gateClkLow) |
                        _BOOL2FLD(SCB_TGS_CTL0_TR_FRAME, config->gateFrame) |
                        _BOOL2FLD(SCB_TGS_CTL0_TR_FRAME_N, config->gateFrameN) |
                        _BOOL2FLD(SCB_TGS_CTL0_TR_FCLK_P, config->stopClkFall) |
                        _BOOL2FLD(SCB_TGS_CTL0_TR_RCLK_P, config->stopClkRise) |
                        _BOOL2FLD(SCB_TGS_CTL0_TR_UART_P, config->stopUartStop) |
                        _BOOL2FLD(SCB_TGS_CTL0_TR_SPI_NS, config->stopSpiSel) |
                        _BOOL2FLD(SCB_TGS_CTL0_TR_I2C_P, config->stopI2cStop) |
                        _BOOL2FLD(SCB_TGS_CTL0_SEL_UART_TX, config->uartDirection) |
                        _BOOL2FLD(SCB_TGS_CTL0_STATE_RST, config->enableReset);

    switch (cntNum)
    {
        case 0u:
            SCB_TGS_CTL0(base) = tgs_ctl;
            SCB_TGS_CNT0(base) = config->count;
            SCB_TGS_REL0(base) = config->reload;
            break;
        case 1u:
            SCB_TGS_CTL1(base) = tgs_ctl;
            SCB_TGS_CNT1(base) = config->count;
            SCB_TGS_REL1(base) = config->reload;
            break;
        case 2u:
            SCB_TGS_CTL2(base) = tgs_ctl;
            SCB_TGS_CNT2(base) = config->count;
            SCB_TGS_REL2(base) = config->reload;
            break;
        default:
            /* Not supported counter number */
            break;
    }

    /* Enable interrupt source */
    SCB_INTR_TGS_MASK(base) |= 1UL << cntNum;

    return CY_SCB_TGS_SUCCESS;
}


/*******************************************************************************
*  Function Name: Cy_SCB_TGSx_DeInit
****************************************************************************//**
*
* De-initializes the Timeout Generation Support block and returns the register values to default.
*
* \param base
* The pointer to the SCB instance.
*
* \param cntNum
* The counter number (0, 1, 2).
*
* \note
* This API is only available for devices containing TGS functionality.
*
*******************************************************************************/
void Cy_SCB_TGSx_DeInit(CySCB_Type *base, uint8_t cntNum)
{
    /* Returns block registers into the default state */
    switch (cntNum)
    {
        case 0u:
            SCB_TGS_CTL0(base) = 0UL;
            SCB_TGS_CNT0(base) = 0UL;
            SCB_TGS_REL0(base) = 0UL;
            break;
        case 1u:
            SCB_TGS_CTL1(base) = 0UL;
            SCB_TGS_CNT1(base) = 0UL;
            SCB_TGS_REL1(base) = 0UL;
            break;
        case 2u:
            SCB_TGS_CTL2(base) = 0UL;
            SCB_TGS_CNT2(base) = 0UL;
            SCB_TGS_REL2(base) = 0UL;
            break;
        default:
            /* Not supported counter number */
            break;
    }

    /* Disable interrupt source */
    SCB_INTR_TGS_MASK(base) &= ~(1UL << cntNum);
}

#endif /* (((CY_IP_MXSCB_VERSION>=4) && (CY_IP_MXSCB_VERSION_MINOR>=4)) || defined (CY_DOXYGEN)) */

#if defined(__cplusplus)
}
#endif

#endif /* (defined (CY_IP_MXSCB) || defined (CY_IP_MXS22SCB)) */

/* [] END OF FILE */
