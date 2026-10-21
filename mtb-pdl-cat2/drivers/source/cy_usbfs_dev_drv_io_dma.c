/***************************************************************************//**
* \file cy_usbfs_dev_drv_io_dma.c
* \version 2.20
*
* Provides data transfer API implementation of the USBFS driver.
*
********************************************************************************
* \copyright
* (c) (2021-2023), Cypress Semiconductor Corporation (an Infineon company) or
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

#include <string.h>
#include "cy_usbfs_dev_drv_pvt.h"

#if defined(__cplusplus)
extern "C" {
#endif


#ifdef CY_IP_M0S8USBDSS

/*******************************************************************************
*                        Internal Constants
*******************************************************************************/

/* Arbiter interrupt sources for OUT and IN endpoints when mode is
* CY_USBFS_DEV_DRV_EP_MANAGEMENT_DMA_AUTO.
*/
#define IN_ENDPOINT_ARB_INTR_SOURCES    (USBFS_USBDEV_ARB_EP_IN_BUF_FULL_Msk | \
                                         USBFS_USBDEV_ARB_EP_BUF_OVER_Msk    | \
                                         USBFS_USBDEV_ARB_EP_BUF_UNDER_Msk   | \
                                         USBFS_USBDEV_ARB_EP_ERR_Msk)

#define OUT_ENDPOINT_ARB_INTR_SOURCES   (USBFS_USBDEV_ARB_EP_DMA_TERMIN_Msk | \
                                         USBFS_USBDEV_ARB_EP_BUF_OVER_Msk   | \
                                         USBFS_USBDEV_ARB_EP_BUF_UNDER_Msk  | \
                                         USBFS_USBDEV_ARB_EP_ERR_Msk)

/* DMA configuration defines */

#define DMA_INCREMENT                  (1U)
#define DMA_NO_INCREMENT               (0U)
#define DMAC_INVALID_CHANNEL           (0xFFFFFFFFU)

/* USBFS DMA defines */
#define USBFS_DMA_BYTES_PER_BURST      (32U)
#define USBFS_DMA_HALFWORDS_PER_BURST  (16U)

#define USBFS_DMA_DESCR0_MASK          (false)
#define USBFS_DMA_DESCR1_MASK          (true)
#define USBFS_DMA_DESCR_REVERT         (0x40U)
#define USBFS_DMA_DESCR_16BITS         (0x20U)
#define USBFS_DMA_DESCR_SHIFT          (7U)
#define USBFS_DMA_CHANNEL_MASK         (0x07U)

#define USBFS_DMA_GET_BURST_CNT(dmaBurstCnt) \
            (((dmaBurstCnt) > 2U)? ((dmaBurstCnt) - 2U) : 0U)

#define GET_SIZE(useReg16,size) ((useReg16) ? GET_SIZE16((size)): (size))

#define USBFS_DMA_GET_MAX_ELEM_PER_BURST(dmaLastBurstEl) \
                    ((0U != ((dmaLastBurstEl) & USBFS_DMA_DESCR_16BITS)) ? \
                                (USBFS_DMA_HALFWORDS_PER_BURST - 1U) : (USBFS_DMA_BYTES_PER_BURST - 1U))

/* Timeout for dynamic reconfiguration */
#define DYN_RECONFIG_ONE_TICK         (1U)      /* 1 tick = 1 us */
#define DYN_RECONFIG_TIMEOUT          (25000UL) /* (25000 * tick)us = 25 ms ( TDRQCMPLTND / 2 ) */

/* Timeout for DMA read operation */
#define DMA_READ_REQUEST_ONE_TICK     (1U)      /* 1 tick = 1 us */
#define DMA_READ_REQUEST_TIMEOUT      (25000UL) /* (25000 * tick)us = 25 ms ( TDRQCMPLTND / 2 ) */

#define DMA_WRITE_REQUEST_ONE_TICK    (1U)      /* 1 tick = 1 us */
#define DMA_WRITE_REQUEST_TIMEOUT     (25000UL) /* (25000 * tick)us = 25 ms ( TDRQCMPLTND / 2 ) */

#if (defined(CY_IP_M0S8CPUSSV3_DMAC) && (CY_USBFS_DRV_DMA_ENABLE == 1))

#include "cy_trigmux.h"
/*******************************************************************************
*                        Internal Functions Prototypes
*******************************************************************************/

static void DmaEndpointInit1D(DMAC_Type * base, uint32_t channel,
                              bool inDirection,
                              cy_en_dmac_descriptor_t descr, 
                              cy_en_dmac_data_size_t dataSize,
                              volatile uint32_t const *dataReg);

static void DmaEndpointSetLength(bool inDirection,
                                 uint32_t size,
                                 cy_stc_usbfs_dev_drv_endpoint_data_t *endpoint);

/*******************************************************************************
* Function Name: DmaInit
****************************************************************************//**
*
* Initializes all DMAC channels used by the USBFS Device.
*
* \param config
* The pointer to the driver configuration structure \ref cy_stc_usbfs_dev_drv_config_t.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbfs_dev_drv_context_t
* allocated by the user. The structure is used during the USBFS Device
* operation for internal configuration and data retention. The user must not
* modify anything in this structure.
*
* \return
* Status code of the function execution \ref cy_en_usbfs_dev_drv_status_t.
*
*******************************************************************************/
cy_en_usbfs_dev_drv_status_t DmaInit(cy_stc_usbfs_dev_drv_config_t const *config, cy_stc_usbfs_dev_drv_context_t *context)
{
    cy_en_usbfs_dev_drv_status_t retStatus = CY_USBFS_DEV_DRV_DMA_CFG_FAILED;

    uint32_t endpoint;

    /* Configure DMA descriptors and channels for data endpoints */
    for (endpoint = 0UL; endpoint < CY_USBFS_DEV_DRV_NUM_EPS_MAX; ++endpoint)
    {
        /* DMA configuration status for endpoint */
        retStatus = CY_USBFS_DEV_DRV_DMA_CFG_FAILED;

        /* Get pointer to endpoint data */
        cy_stc_usbfs_dev_drv_endpoint_data_t *endpointData = &context->epPool[endpoint];

        if (config->dmaConfig[endpoint] != NULL)
        {
            cy_en_usbfs_dev_drv_status_t locStatus = CY_USBFS_DEV_DRV_DMA_CFG_FAILED;

            cy_stc_dmac_channel_config_t chConfig;

            /* Descriptors configurations */
            const cy_stc_dmac_descriptor_config_t DmaDescr1DCfg =
            {
                     /* .srcAddress         = */ NULL,
                     /* .dstAddress         = */ NULL,
                     /* .dataCount          = */ 1UL,
                     /* .dataSize           = */ CY_DMAC_BYTE,
                     /* .srcTransferSize    = */ CY_DMAC_TRANSFER_SIZE_DATA,
                     /* .srcAddrIncrement   = */ true,
                     /* .dstTransferSize    = */ CY_DMAC_TRANSFER_SIZE_WORD,
                     /* .dstAddrIncrement   = */ 0,
                     /* .retrigger          = */ CY_DMAC_RETRIG_IM,
                     /* .cpltState          = */ true,
                     /* .interrupt          = */ false,
                     /* .preemptable        = */ config->dmaConfig[endpoint]->preemptable,
                     /* .flipping           = */ 0,
                     /* .triggerType        = */ CY_DMAC_SINGLE_DESCR,

            };

            /* Store DMA configuration required for operation */
            endpointData->base   = config->dmaConfig[endpoint]->base;
            endpointData->chNum  = config->dmaConfig[endpoint]->chNum;
            endpointData->outTrigMux = config->dmaConfig[endpoint]->outTrigMux;
            endpointData->copyData   = NULL;

            if (CY_USBFS_DEV_DRV_EP_MANAGEMENT_DMA == context->mode)
            {
                
                /* Initialize DMA descriptor 0 (PING) */
                if(CY_DMAC_SUCCESS == Cy_DMAC_Descriptor_Init(endpointData->base,endpointData->chNum, CY_DMAC_DESCRIPTOR_PING, &DmaDescr1DCfg))
                {
                    locStatus = CY_USBFS_DEV_DRV_SUCCESS;
                }
            }

            else
            {
                /* Descriptors configurations */
                const cy_stc_dmac_descriptor_config_t DmaDescr2DCfg =
                {
                        /* .srcAddress          = */ NULL,
                        /* .dstAddress          = */ NULL,
                        /* .dataCount           = */ 1UL,
                        /* .dataSize            = */ CY_DMAC_BYTE,
                        /* .srcTransferSize     = */ CY_DMAC_TRANSFER_SIZE_DATA,
                        /* .srcAddrIncrement    = */ true,
                        /* .dstTransferSize     = */ CY_DMAC_TRANSFER_SIZE_WORD,
                        /* .dstAddrIncrement    = */ 0,
                        /* .retrigger           = */ CY_DMAC_RETRIG_IM,
                        /* .cpltState           = */ true,
                        /* .interrupt           = */ true,
                        /* .preemptable         = */ config->dmaConfig[endpoint]->preemptable,
                        /* .flipping            = */ true,
                        /* .triggerType         = */ CY_DMAC_SINGLE_DESCR,
                };
               
                /* Initialize DMA descriptor 0 (PING) and 1 (PONG) */
                cy_en_dmac_status_t descr0Stat = Cy_DMAC_Descriptor_Init(endpointData->base,endpointData->chNum, CY_DMAC_DESCRIPTOR_PING, &DmaDescr2DCfg); 
                cy_en_dmac_status_t descr1Stat = Cy_DMAC_Descriptor_Init(endpointData->base,endpointData->chNum, CY_DMAC_DESCRIPTOR_PONG, &DmaDescr2DCfg); 

                if((CY_DMAC_SUCCESS == descr0Stat) && (CY_DMAC_SUCCESS == descr1Stat))
                {
                    locStatus = CY_USBFS_DEV_DRV_SUCCESS;
                }
            }

            /* Set DMA channel configuration */
            chConfig.enable      = false;
            chConfig.descriptor  = CY_DMAC_DESCRIPTOR_PING;
            chConfig.priority    = config->dmaConfig[endpoint]->priority;

            /* Initialize DMA channel */
            if ((CY_DMAC_SUCCESS != Cy_DMAC_Channel_Init(endpointData->base, endpointData->chNum, &chConfig)) ||
                            (CY_USBFS_DEV_DRV_SUCCESS != locStatus))
            {
                break;
            }

            /* Enable DMA block */
            Cy_DMAC_Enable(endpointData->base);
        }

        else
        {
            endpointData->chNum = DMAC_INVALID_CHANNEL;
        }

        /* Configuration complete successfully */
        retStatus = CY_USBFS_DEV_DRV_SUCCESS;
    }

    /* Disable all DMAs if any configuration failed */
    if (CY_USBFS_DEV_DRV_SUCCESS != retStatus)
    {
        DmaDisable(context);
    }

    return retStatus;
}


/*******************************************************************************
* Function Name: DmaDisable
****************************************************************************//**
*
* Disables all DMA channels used by the USBFS Device.
* The channel state is not verified before being disabled.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbfs_dev_drv_context_t
* allocated by the user. The structure is used during the USBFS Device
* operation for internal configuration and data retention. The user must not
* modify anything in this structure.
*
*******************************************************************************/
void DmaDisable(cy_stc_usbfs_dev_drv_context_t *context)
{
    uint32_t endpoint;

    /* Disable DMA channels for data endpoints */
    for (endpoint = 0UL; endpoint < CY_USBFS_DEV_DRV_NUM_EPS_MAX; ++endpoint)
    {
        /* Get pointer to endpoint data */
        cy_stc_usbfs_dev_drv_endpoint_data_t *endpointData = &context->epPool[endpoint];

        if (endpointData->chNum != DMAC_INVALID_CHANNEL)
        {
            Cy_DMAC_Channel_Disable(endpointData->base, endpointData->chNum);
        }
    }
}

/*******************************************************************************
* Function Name: DmaEndpointInit1D
****************************************************************************//**
*
* Configures DMA 1D descriptor used in DMA modes.
*
* \param base
* The pointer to the DMAC base address.
* 
* \param channel
* The DMAC channel number associated with the Endpoint.
*
* \param inDirection
* Endpoint direction associated with DMA descriptor \ref cy_en_dmac_descriptor_t,
*
* \param descr
* The descriptors to be used for endpoint transfers.
*
* \param dataSize
* The DMA transfer data size \ref cy_en_dmac_data_size_t.
*
* \param dataReg
* The pointer to the data endpoint data register.
*
*******************************************************************************/
static void DmaEndpointInit1D(DMAC_Type * base, uint32_t channel, bool inDirection, cy_en_dmac_descriptor_t descr, 
                              cy_en_dmac_data_size_t dataSize, volatile uint32_t const *dataReg)
{
    Cy_DMAC_Descriptor_SetDataSize(base, channel,  descr, dataSize);

    if (inDirection)
    {
        Cy_DMAC_Descriptor_SetSrcTransferSize(base, channel, descr, CY_DMAC_TRANSFER_SIZE_DATA);
        Cy_DMAC_Descriptor_SetDstTransferSize(base, channel, descr, CY_DMAC_TRANSFER_SIZE_WORD);
    
        Cy_DMAC_Descriptor_SetSrcIncrement(base, channel, descr, DMA_INCREMENT);
        Cy_DMAC_Descriptor_SetDstIncrement(base, channel, descr, DMA_NO_INCREMENT);
        
        Cy_DMAC_Descriptor_SetDstAddress (base, channel, descr, (void *) dataReg);
    }

    else
    {
        Cy_DMAC_Descriptor_SetSrcTransferSize(base, channel, descr, CY_DMAC_TRANSFER_SIZE_WORD);
        Cy_DMAC_Descriptor_SetDstTransferSize(base, channel, descr, CY_DMAC_TRANSFER_SIZE_DATA);

        Cy_DMAC_Descriptor_SetSrcIncrement(base, channel, descr, DMA_NO_INCREMENT);
        Cy_DMAC_Descriptor_SetDstIncrement(base, channel, descr, DMA_INCREMENT);

        Cy_DMAC_Descriptor_SetSrcAddress (base, channel, descr, (void *) dataReg);
    }
}


/*******************************************************************************
* Function Name: DmaEndpointSetLength
****************************************************************************//**
*
* Completes DMA initialization for the OUT data endpoint.
* Applicable only when mode is \ref CY_USBFS_DEV_DRV_EP_MANAGEMENT_DMA_AUTO.
*
* \param inDirection
* Endpoint direction associated with DMA descriptor.
*
* \param size
* The number of bytes to load into endpoint.
* This value must be less than or equal to the endpoint maximum packet size.
*
* \param endpoint
* The pointer to the structure that stores endpoint information.
*
*******************************************************************************/
static void DmaEndpointSetLength(bool inDirection, uint32_t size,
                                 cy_stc_usbfs_dev_drv_endpoint_data_t *endpoint)
{
    uint8_t *buf = endpoint->buffer;

    uint32_t lengthDescr0;
    uint32_t lengthDescr1;

    /* Get number of full bursts. Num Y loops*/
    endpoint->DmaEpBurstCount = (uint32_t) (size / USBFS_DMA_BYTES_PER_BURST);

    /* Get number of elements in the last burst. Num X Loops*/
    endpoint->DmaEpLastBurst = (uint32_t) (size % USBFS_DMA_BYTES_PER_BURST);

    /* Get total number of bursts. */
    endpoint->DmaEpBurstCount += (0U != endpoint->DmaEpLastBurst) ? 1U : 0U;

    /* Adjust number of data elements transferred in last burst. */
    endpoint->DmaEpLastBurst = (0U != endpoint->DmaEpLastBurst) ?
                                          (endpoint->DmaEpLastBurst) :
                                          (USBFS_DMA_BYTES_PER_BURST);

    /* Get number of data elements to transfer for descriptor 0 and 1. */
    lengthDescr0 = (1U == endpoint->DmaEpBurstCount) ? endpoint->DmaEpLastBurst : (USBFS_DMA_BYTES_PER_BURST);

    lengthDescr1 = (2U == endpoint->DmaEpBurstCount) ? endpoint->DmaEpLastBurst : (USBFS_DMA_BYTES_PER_BURST);


    /* Mark which descriptor is last one to execute. */
    endpoint->LastDescr = (bool)((0U != (endpoint->DmaEpBurstCount & 0x1U)) ? USBFS_DMA_DESCR0_MASK : USBFS_DMA_DESCR1_MASK);

    /* Disable DMA channel: start configuration. */
    Cy_DMAC_Channel_Disable(endpoint->base, endpoint->chNum);

    /* Configure */
    if (inDirection)
    {
        endpoint->startBuf = (uint16_t) size;  /* Store DMA transfer size */
        Cy_DMAC_Descriptor_SetSrcAddress(endpoint->base, endpoint->chNum, CY_DMAC_DESCRIPTOR_PING, buf);
        Cy_DMAC_Descriptor_SetSrcAddress(endpoint->base, endpoint->chNum, CY_DMAC_DESCRIPTOR_PONG, (buf + USBFS_DMA_BYTES_PER_BURST));
    }
    else
    {
        Cy_DMAC_Descriptor_SetDstAddress(endpoint->base, endpoint->chNum, CY_DMAC_DESCRIPTOR_PING, buf);
        Cy_DMAC_Descriptor_SetDstAddress(endpoint->base, endpoint->chNum, CY_DMAC_DESCRIPTOR_PONG, (buf + USBFS_DMA_BYTES_PER_BURST));
    }

    Cy_DMAC_Descriptor_SetDataCount(endpoint->base, endpoint->chNum, CY_DMAC_DESCRIPTOR_PING, lengthDescr0);
    Cy_DMAC_Descriptor_SetDataCount(endpoint->base, endpoint->chNum, CY_DMAC_DESCRIPTOR_PONG, lengthDescr1);
   
    /* Enable DMA to execute transfer as it was disabled because there were no valid descriptor. */
    Cy_DMAC_Descriptor_SetState(endpoint->base, endpoint->chNum, CY_DMAC_DESCRIPTOR_PING, true);

    /* Set first descriptor to execute */
    Cy_DMAC_Channel_SetCurrentDescriptor(endpoint->base, endpoint->chNum, CY_DMAC_DESCRIPTOR_PING);

    if(endpoint->DmaEpBurstCount > 1U)
    {
        /* Validate the PONG descriptor */
        Cy_DMAC_Descriptor_SetState(endpoint->base, endpoint->chNum, CY_DMAC_DESCRIPTOR_PONG, true);
    }

    Cy_DMAC_Channel_Enable(endpoint->base, endpoint->chNum);
}


/*******************************************************************************
* Function Name: DmaOutEndpointRestore
****************************************************************************//**
*
* Restores the DMA channel after transfer is completed for the the OUT data endpoint.
* Applicable only when mode is \ref CY_USBFS_DEV_DRV_EP_MANAGEMENT_DMA_AUTO.
*
* \param endpointData
* The pointer to the structure that stores endpoint information.
*
* \param useReg16
* Defines which endpoint registers to use: 8-bits or 16-bits.
*
*******************************************************************************/
void DmaOutEndpointRestore(cy_stc_usbfs_dev_drv_endpoint_data_t *endpointData, bool useReg16)
{
   
    /* Wait for the DMA Transfer Complete */
    while (0u != (Cy_DMAC_GetActiveChannel(endpointData->base) & (uint32_t)(1UL << endpointData->chNum))) {}

    /* Number of clocks for DMA completion pulse */
    const uint32_t CY_USBFS_DEV_DRV_TRIG_CYCLES = 2UL;

    /* Restore burst counter for endpoint. */
    endpointData->DmaEpBurstCount = USBFS_DMA_GET_BURST_CNT(endpointData->DmaOutEpBurstCountRestore);

    /* Disable DMA channel to restore descriptor configuration. The on-going transfer is aborted. */
    Cy_DMAC_Channel_Disable(endpointData->base, endpointData->chNum);

    /* Generate DMA tr_out signal to notify USB IP that DMA is done. This signal is not generated
    * when transfer was aborted (it occurs when host writes less bytes than buffer size).
    * Send a pulse to UBSFS IP to indicate end of DMA transfer */
    (void) Cy_TrigMux_SwTrigger(endpointData->outTrigMux, CY_USBFS_DEV_DRV_TRIG_CYCLES);

    /* Restore destination address for output endpoint. */
    Cy_DMAC_Descriptor_SetDstAddress(endpointData->base, endpointData->chNum , CY_DMAC_DESCRIPTOR_PING, (void*)endpointData->buffer);
    Cy_DMAC_Descriptor_SetDstAddress(endpointData->base, endpointData->chNum , CY_DMAC_DESCRIPTOR_PING, 
                                    (void*)(endpointData->buffer + USBFS_DMA_BYTES_PER_BURST));

    /* Restore number of data elements to transfer which was adjusted for last burst. */
    if (true == (endpointData->RevertDescr))
    {
        Cy_DMAC_Descriptor_SetDataCount(endpointData->base, endpointData->chNum, 
                                        (cy_en_dmac_descriptor_t)(endpointData->LastDescr),
                                        (GET_SIZE(useReg16, USBFS_DMA_BYTES_PER_BURST)));
    }

    /* Validate descriptor 0 and 1 (also reset current state). Command to start with descriptor 0. */
    Cy_DMAC_Descriptor_SetState(endpointData->base, endpointData->chNum, CY_DMAC_DESCRIPTOR_PING, true);

    if (endpointData->DmaOutEpBurstCountRestore > 1U)
    {
        Cy_DMAC_Descriptor_SetState(endpointData->base, endpointData->chNum, CY_DMAC_DESCRIPTOR_PONG, true);
    }
    
    Cy_DMAC_Channel_SetCurrentDescriptor(endpointData->base, endpointData->chNum, CY_DMAC_DESCRIPTOR_PING);

    /* Enable DMA channel: configuration complete. */
    Cy_DMAC_Channel_Enable(endpointData->base, endpointData->chNum);

}


/*******************************************************************************
* Function Name: DmaEndpointInit
****************************************************************************//**
*
* Initializes DMA descriptor for a certain data endpoint.
*
* \param base
* The pointer to the USBFS instance.
*
* \param mode
* The endpoint management mode.
*
* \param useReg16
* Defines which endpoint registers to use: 8-bits or 16-bits.
*
* \param endpointData
* The pointer to the endpoint data structure.
*
* \return
* Status code of the function execution \ref cy_en_usbfs_dev_drv_status_t.
*
*******************************************************************************/
cy_en_usbfs_dev_drv_status_t DmaEndpointInit(USBFS_Type *base,
                                             cy_en_usbfs_dev_drv_ep_management_mode_t mode,
                                             bool useReg16,
                                             cy_stc_usbfs_dev_drv_endpoint_data_t *endpointData)
{
    cy_en_dmac_data_size_t regSize;
    uint32_t volatile *dataReg;

    /* Get direction and endpoint number */
    bool inDirection  = IS_EP_DIR_IN(endpointData->address);
    uint32_t endpoint = EPADDR2PHY(endpointData->address);

    if (DMAC_INVALID_CHANNEL == endpointData->chNum)
    {
        return CY_USBFS_DEV_DRV_DMA_CFG_FAILED;
    }

    /* Set configuration variables depending on access type */
    if (useReg16)
    {
        dataReg     = Cy_USBFS_Dev_Drv_GetDataReg16Addr(base, endpoint);
        regSize     = CY_DMAC_HALFWORD;
    }

    else
    {
        dataReg     = Cy_USBFS_Dev_Drv_GetDataRegAddr(base, endpoint);
        regSize     = CY_DMAC_BYTE;
    }

    /* Disable channel before configuration */
    Cy_DMAC_Channel_Disable(endpointData->base, endpointData->chNum);

    /* Configure Descriptor 0 for 1D operation */
    DmaEndpointInit1D(endpointData->base, endpointData->chNum, inDirection, CY_DMAC_DESCRIPTOR_PING, regSize, dataReg);

    if (CY_USBFS_DEV_DRV_EP_MANAGEMENT_DMA_AUTO == mode)
    {
        /* Configure both descriptors for the endpoint */ 
        DmaEndpointInit1D(endpointData->base, endpointData->chNum, inDirection, CY_DMAC_DESCRIPTOR_PING, regSize, dataReg);
        DmaEndpointInit1D(endpointData->base, endpointData->chNum, inDirection, CY_DMAC_DESCRIPTOR_PONG, regSize, dataReg);

        /* Set descriptor chaining */
        Cy_DMAC_Descriptor_SetFlipping(endpointData->base, endpointData->chNum, CY_DMAC_DESCRIPTOR_PING, true);
        Cy_DMAC_Descriptor_SetFlipping(endpointData->base, endpointData->chNum, CY_DMAC_DESCRIPTOR_PONG, true);

        /* Enable DMA Interrupt Source */
        Cy_DMAC_SetInterruptMask(endpointData->base, 1UL<<(uint32_t)endpointData->chNum);

        /* Configure descriptors to access buffer */
        DmaEndpointSetLength(inDirection, (uint32_t) endpointData->bufferSize, endpointData);
    }

    return CY_USBFS_DEV_DRV_SUCCESS;
}


/*******************************************************************************
* Function Name: DynamicEndpointReConfiguration
****************************************************************************//**
*
* Changes endpoint direction (IN -> OUT or OUT -> IN).
* This function is also used to flush IN or OUT endpoint buffer.
* Applicable only when mode is \ref CY_USBFS_DEV_DRV_EP_MANAGEMENT_DMA_AUTO.
*
* \param base
* The pointer to the USBFS instance.
*
* \param inDirection
* True - endpoint direction is IN; False - endpoint direction is OUT.
*
* \param endpoint
* The data endpoint number.
*
* \return
* Status code of the function execution \ref cy_en_usbfs_dev_drv_status_t.
*
*******************************************************************************/
cy_en_usbfs_dev_drv_status_t DynamicEndpointReConfiguration(USBFS_Type *base,
                                                            bool        inDirection,
                                                            uint32_t    endpoint)
{
    cy_en_usbfs_dev_drv_status_t retStatus = CY_USBFS_DEV_DRV_EP_DYN_RECONFIG_TIMEOUT;

    uint32_t timeout = DYN_RECONFIG_TIMEOUT;

    /* Only enabled endpoint can be re-configured */
    if (0U == (USBFS_DEV_EP_ACTIVE(base) & EP2MASK(endpoint)))
    {
        return CY_USBFS_DEV_DRV_BUF_ALLOC_FAILED;
    }

    /* Request reconfiguration for endpoint */
    USBFS_DEV_DYN_RECONFIG(base) = (USBFS_USBDEV_DYN_RECONFIG_EN_Msk |
                                    _VAL2FLD(USBFS_USBDEV_DYN_RECONFIG_EPNO, endpoint));

    /* ID#295549: execute dummy read */
    (void) USBFS_DEV_DYN_RECONFIG(base);

    /* Wait for dynamic re-configuration completion */
    while ((0U == (USBFS_DEV_DYN_RECONFIG(base) & USBFS_USBDEV_DYN_RECONFIG_RDY_STS_Msk)) &&
           (timeout > 0U))
    {
        Cy_SysLib_DelayUs(DYN_RECONFIG_ONE_TICK);
        --timeout;
    }

    /* Verify operation result */
    if (timeout > 0U)
    {
        Cy_USBFS_Dev_Drv_SetEpType(base, inDirection, endpoint);
        retStatus = CY_USBFS_DEV_DRV_SUCCESS;
    }

    /* Complete endpoint reconfiguration: clear request */
    USBFS_DEV_DYN_RECONFIG(base) &= ~USBFS_USBDEV_DYN_RECONFIG_EN_Msk;
    (void) USBFS_DEV_DYN_RECONFIG(base);

    /* Clear register for next re-configuration */
    USBFS_DEV_DYN_RECONFIG(base) = 0U;

    return retStatus;
}


/*******************************************************************************
* Function Name: AddEndpointRamBuffer
****************************************************************************//**
*
* Implements \ref Cy_USBFS_Dev_Drv_AddEndpoint for
* \ref CY_USBFS_DEV_DRV_EP_MANAGEMENT_DMA_AUTO mode.
*
* \param base
* The pointer to the USBFS instance.
*
* \param config
* The pointer to data endpoint configuration \ref cy_stc_usb_dev_ep_config_t.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbfs_dev_drv_context_t
* allocated by the user. The structure is used during the USBFS Device
* operation for internal configuration and data retention. The user must not
* modify anything in this structure.
*
* \return
* Status code of the function execution \ref cy_en_usbfs_dev_drv_status_t.
*
*******************************************************************************/
cy_en_usbfs_dev_drv_status_t AddEndpointRamBuffer(USBFS_Type *base,
                                                  cy_stc_usb_dev_ep_config_t const *config,
                                                  cy_stc_usbfs_dev_drv_context_t   *context)
{
    cy_en_usbfs_dev_drv_status_t retStatus = CY_USBFS_DEV_DRV_BAD_PARAM;

    uint32_t endpoint = EPADDR2PHY(config->endpointAddr);

    /* Get pointer to endpoint data */
    cy_stc_usbfs_dev_drv_endpoint_data_t *endpointData = &context->epPool[endpoint];

    /* Get buffer for endpoint using buffer allocated by the user */
    if (config->allocBuffer)
    {
        uint32_t startBufIdx;

        /* Configure active endpoint */
        context->activeEpMask    |= (uint8_t) EP2MASK(endpoint);
        USBFS_DEV_EP_ACTIVE(base) = context->activeEpMask;

        /* Allocate buffer for endpoint */
        retStatus = GetEndpointBuffer((uint32_t) config->bufferSize, &startBufIdx, context);
        if (CY_USBFS_DEV_DRV_SUCCESS != retStatus)
        {
            return retStatus;
        }

        /* Store pointer to buffer for this endpoint */
        endpointData->buffer = &context->epSharedBuf[startBufIdx];
    }

    /* Enable endpoint for operation */
    if (config->enableEndpoint)
    {
        bool inDirection = IS_EP_DIR_IN(config->endpointAddr);

        /* Clear variables related to endpoint */
        endpointData->state   = CY_USB_DEV_EP_IDLE;
        endpointData->address = config->endpointAddr;
        endpointData->toggle  = 0U;
        endpointData->bufferSize = config->maxPacketSize;
        endpointData->sieMode    = GetEndpointActiveMode(inDirection, config->attributes);
        endpointData->isPending  = false;

        /* Set arbiter configuration (clears DMA requests) */
        Cy_USBFS_Dev_Drv_SetArbEpConfig(base, endpoint, (USBFS_ARB_EP1_CFG_CRC_BYPASS_Msk |
                                                         USBFS_ARB_EP1_CFG_RESET_PTR_Msk));

        /* Performs dynamic reconfiguration to make sure that the DMA has completed the data transfer.
        * Also it flushes endpoint pre-fetch buffer (useful for IN endpoints).
        */
        retStatus = DynamicEndpointReConfiguration(base, inDirection, endpoint);
        if (CY_USBFS_DEV_DRV_SUCCESS != retStatus)
        {
            return retStatus;
        }

        /* Configure DMA for endpoint */
        retStatus = DmaEndpointInit(base, context->mode, context->useReg16, endpointData);
        if (CY_USBFS_DEV_DRV_SUCCESS != retStatus)
        {
            return retStatus;
        }

        /* Enable Arbiter interrupt sources for endpoint */
        Cy_USBFS_Dev_Drv_SetArbEpInterruptMask(base, endpoint,(inDirection ?
                                                             IN_ENDPOINT_ARB_INTR_SOURCES :
                                                             OUT_ENDPOINT_ARB_INTR_SOURCES));

        /* Enable SIE and arbiter interrupt for endpoint */
        Cy_USBFS_Dev_Drv_EnableSieEpInterrupt(base, endpoint);
        Cy_USBFS_Dev_Drv_EnableArbEpInterrupt(base, endpoint);

        /* Set SIE mode to respond to host */
        Cy_USBFS_Dev_Drv_SetSieEpMode(base, endpoint, GetEndpointInactiveMode((uint32_t) endpointData->sieMode));
    }

    return retStatus;
}

/*******************************************************************************
* Function Name: RestoreEndpointRamBuffer
****************************************************************************//**
*
* Restores endpoint active configuration for
* \ref CY_USBFS_DEV_DRV_EP_MANAGEMENT_DMA_AUTO mode.
*
* \param base
* The pointer to the USBFS instance.
*
* \param endpointData
* The pointer to the endpoint data structure.
*
*******************************************************************************/
void RestoreEndpointRamBuffer(USBFS_Type *base,
                              cy_stc_usbfs_dev_drv_endpoint_data_t *endpointData)
{
    bool inDirection  = IS_EP_DIR_IN(endpointData->address);
    uint32_t endpoint = EPADDR2PHY(endpointData->address);

    /* Clear state */
    endpointData->state = CY_USB_DEV_EP_IDLE;

    /* Configure active endpoint */
    USBFS_DEV_EP_ACTIVE(base) |= EP2MASK(endpoint);

    /* Configure endpoint type: OUT - 1, IN - 0 */
    Cy_USBFS_Dev_Drv_SetEpType(base, inDirection, endpoint);

    /* Enable Arbiter interrupt sources for endpoint */
    Cy_USBFS_Dev_Drv_SetArbEpInterruptMask(base, endpoint, (inDirection ?
                                                            IN_ENDPOINT_ARB_INTR_SOURCES :
                                                            OUT_ENDPOINT_ARB_INTR_SOURCES));

    /* Enable SIE and arbiter interrupt for endpoint */
    Cy_USBFS_Dev_Drv_EnableSieEpInterrupt(base, endpoint);
    Cy_USBFS_Dev_Drv_EnableArbEpInterrupt(base, endpoint);

    if (false == inDirection)
    {
        /* OUT Endpoint: enable DMA channel endpoint ready for operation.
        * IN Endpoint: keep disabled, it is enabled in LoadInEndpointDmaAuto.
        */
        Cy_DMAC_Channel_Enable(endpointData->base, endpointData->chNum);
    }

    /* Sets an arbiter configuration */
    Cy_USBFS_Dev_Drv_SetArbEpConfig(base, endpoint, (USBFS_ARB_EP1_CFG_CRC_BYPASS_Msk |
                                                     USBFS_ARB_EP1_CFG_RESET_PTR_Msk));

    /* Set SIE mode to respond to host */
    Cy_USBFS_Dev_Drv_SetSieEpMode(base, endpoint, GetEndpointInactiveMode((uint32_t) endpointData->sieMode));
}


/*******************************************************************************
* Function Name: LoadInEndpointDma
****************************************************************************//**
*
* Implements \ref Cy_USBFS_Dev_Drv_LoadInEndpoint for
* \ref CY_USBFS_DEV_DRV_EP_MANAGEMENT_DMA mode.
*
* \param base
* The pointer to the USBFS instance.
*
* \param endpoint
* The IN data endpoint number.
*
* \param buffer
* The pointer to the buffer containing data bytes to load.
*
* \param size
* The number of bytes to load into the endpoint.
* This value must be less than or equal to the endpoint maximum packet size.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbfs_dev_drv_context_t
* allocated by the user. The structure is used during the USBFS Device
* operation for internal configuration and data retention. The user must not
* modify anything in this structure.
*
* \return
* Status code of the function execution \ref cy_en_usbfs_dev_drv_status_t.
*
*******************************************************************************/
cy_en_usbfs_dev_drv_status_t LoadInEndpointDma(USBFS_Type    *base,
                                               uint32_t      endpoint,
                                               uint8_t const *buffer,
                                               uint32_t      size,
                                               cy_stc_usbfs_dev_drv_context_t *context)
{
    cy_en_usbfs_dev_drv_status_t retStatus = CY_USBFS_DEV_DRV_EP_DMA_WRITE_TIMEOUT;

    /* Get pointer to endpoint data */
    cy_stc_usbfs_dev_drv_endpoint_data_t *endpointData = &context->epPool[endpoint];

    /* Request to load more bytes than endpoint buffer */
    if (size > endpointData->bufferSize)
    {
        return CY_USBFS_DEV_DRV_BAD_PARAM;
    }

    /* Clears the abort mask for the endpoint (there is no transfer during abort) */
    context->epAbortMask &= (uint8_t) ~EP2MASK(endpoint);

    /* Set count and data toggle */
    Cy_USBFS_Dev_Drv_SetSieEpCount(base, endpoint, size, (uint32_t) endpointData->toggle);

    if (0U == size)
    {
        /* Endpoint pending: Waits for the host read data after exiting this function */
        endpointData->state = CY_USB_DEV_EP_PENDING;

        /* Arm endpoint: Host is allowed to read data */
        Cy_USBFS_Dev_Drv_SetSieEpMode(base, endpoint, (uint32_t) endpointData->sieMode);

        retStatus = CY_USBFS_DEV_DRV_SUCCESS;
    }
    else
    {
        /* Channel is disabled after initialization or descriptor completion  */

        uint32_t timeout = DMA_WRITE_REQUEST_TIMEOUT;

        /* Get number of data elements to transfer */
        size = context->useReg16 ? GET_SIZE16(size) : size;

        /* Descriptor: Configure source address and length */
        Cy_DMAC_Descriptor_SetSrcAddress(endpointData->base, endpointData->chNum , CY_DMAC_DESCRIPTOR_PING, (void*)buffer);
        Cy_DMAC_Descriptor_SetDataCount(endpointData->base, endpointData->chNum , CY_DMAC_DESCRIPTOR_PING, size);

        /* Validate the descriptor */
        Cy_DMAC_Descriptor_SetState(endpointData->base, endpointData->chNum, CY_DMAC_DESCRIPTOR_PING, true);

        /* Enable DMA channel: configuration complete */
        Cy_DMAC_Channel_Enable(endpointData->base, endpointData->chNum);

        /* Generate DMA request: the endpoint will be armed when the DMA is
        * finished in the Arbiter interrupt
        */
        Cy_USBFS_Dev_Drv_TriggerArbCfgEpDmaReq(base, endpoint);

        /* Waits until DMA completes the write operation. The current endpoint state is
        * idle or completed and DMA completion interrupt changes state to pending
        * (endpoint waits for the host read data).
        */
        while ((CY_USB_DEV_EP_PENDING != endpointData->state) &&
               (timeout > 0U))
        {
            Cy_SysLib_DelayUs(DMA_WRITE_REQUEST_ONE_TICK);
            --timeout;
        }

        /* Check timeout */
        if (timeout > 0U)
        {
            retStatus = CY_USBFS_DEV_DRV_SUCCESS;
        }
    }

    return retStatus;
}

/*******************************************************************************
* Function Name: ReadOutEndpointDma
****************************************************************************//**
*
* Implements \ref Cy_USBFS_Dev_Drv_ReadOutEndpoint for
* \ref CY_USBFS_DEV_DRV_EP_MANAGEMENT_DMA mode.
*
* \param base
* The pointer to the USBFS instance.
*
* \param endpoint
* The OUT data endpoint number.
*
* \param buffer
* Pointer to buffer that stores data that was read.
*
* \param size
* The number of bytes to read from endpoint.
* This value must be less than or equal to the endpoint maximum packet size.
*
* \param actSize
* The number of bytes that were actually read.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbfs_dev_drv_context_t
* allocated by the user. The structure is used during the USBFS Device
* operation for internal configuration and data retention. The user must not
* modify anything in this structure.
*
* \return
* Status code of the function execution \ref cy_en_usbfs_dev_drv_status_t.
*
*******************************************************************************/
cy_en_usbfs_dev_drv_status_t ReadOutEndpointDma(USBFS_Type *base,
                                                uint32_t   endpoint,
                                                uint8_t    *buffer,
                                                uint32_t   size,
                                                uint32_t   *actSize,
                                                cy_stc_usbfs_dev_drv_context_t *context)
{
    cy_en_usbfs_dev_drv_status_t retStatus = CY_USBFS_DEV_DRV_EP_DMA_READ_TIMEOUT;

    /* Get pointer to endpoint data */
    cy_stc_usbfs_dev_drv_endpoint_data_t *endpointData = &context->epPool[endpoint];

    uint32_t timeout = DMA_READ_REQUEST_TIMEOUT;

    /* Get number of received bytes */
    uint32_t numToCopy = Cy_USBFS_Dev_Drv_GetSieEpCount(base, endpoint);
    uint32_t actCopied = numToCopy;

    /* Initialize actual number of copied bytes */
    *actSize = 0U;

    /* Endpoint received more bytes than provided buffer */
    if (numToCopy > size)
    {
        return CY_USBFS_DEV_DRV_BAD_PARAM;
    }

    /* Nothing to copy; return success */
    if (0U == numToCopy)
    {
        return CY_USBFS_DEV_DRV_SUCCESS;
    }

    /* Channel is disabled after initialization or descriptor completion  */
    Cy_DMAC_Channel_Disable(endpointData->base, endpointData->chNum);

    /* Get number of data elements to transfer */
    numToCopy = context->useReg16 ? GET_SIZE16(numToCopy) : numToCopy;

    /* Descriptor: Configure destination address and length */
    Cy_DMAC_Descriptor_SetDstAddress(endpointData->base, endpointData->chNum , CY_DMAC_DESCRIPTOR_PING, (void*)buffer);
    Cy_DMAC_Descriptor_SetDataCount(endpointData->base, endpointData->chNum , CY_DMAC_DESCRIPTOR_PING, numToCopy);

    /* Validate the descriptor */
    Cy_DMAC_Descriptor_SetState(endpointData->base, endpointData->chNum, CY_DMAC_DESCRIPTOR_PING, true);

    /* Enable DMA channel: configuration complete */
    Cy_DMAC_Channel_Enable(endpointData->base, endpointData->chNum);

    /* The current endpoint state is completed, changes the state to pending to
    * track DMA read completion.
    */
    endpointData->state = CY_USB_DEV_EP_PENDING;

    /* Generate DMA request to read data from hardware buffer */
    Cy_USBFS_Dev_Drv_TriggerArbCfgEpDmaReq(base, endpoint);

    /* Waits until DMA completes the read operation */
    while ((CY_USB_DEV_EP_COMPLETED != endpointData->state) &&
           (timeout > 0U))
    {
        Cy_SysLib_DelayUs(DMA_READ_REQUEST_ONE_TICK);
        --timeout;
    }

    /* Check timeout */
    if (timeout > 0U)
    {
        /* Update number of copied bytes */
        *actSize = actCopied;
        retStatus = CY_USBFS_DEV_DRV_SUCCESS;
    }

    return retStatus;
}


/*******************************************************************************
* Function Name: LoadInEndpointDmaAuto
****************************************************************************//**
*
* Implements \ref Cy_USBFS_Dev_Drv_LoadInEndpoint for
* \ref CY_USBFS_DEV_DRV_EP_MANAGEMENT_DMA_AUTO mode.
*
* \param base
* The pointer to the USBFS instance.
*
* \param endpoint
* The IN data endpoint number.
*
* \param buffer
* The pointer to the buffer containing data bytes to load.
*
* \param size
* The number of bytes to load into endpoint.
* This value must be less than or equal to the endpoint maximum packet size.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbfs_dev_drv_context_t
* allocated by the user. The structure is used during the USBFS Device
* operation for internal configuration and data retention. The user must not
* modify anything in this structure.
*
* \return
* Status code of the function execution \ref cy_en_usbfs_dev_drv_status_t.
*
*******************************************************************************/
cy_en_usbfs_dev_drv_status_t LoadInEndpointDmaAuto(USBFS_Type    *base,
                                                   uint32_t      endpoint,
                                                   uint8_t const *buffer,
                                                   uint32_t      size,
                                                   cy_stc_usbfs_dev_drv_context_t *context)
{
    /* Get pointer to endpoint data */
    cy_stc_usbfs_dev_drv_endpoint_data_t *endpointData = &context->epPool[endpoint];
    
    uint8_t *buf = endpointData->buffer;
      
    uint32_t lengthDescr0;
    uint32_t lengthDescr1;
      

    /* Request to load more bytes than endpoint buffer */
    if (size > endpointData->bufferSize)
    {
        return CY_USBFS_DEV_DRV_BAD_PARAM;
    }

    /* Clears the abort mask for the endpoint (there is no transfer during abort) */
    context->epAbortMask &= (uint8_t) ~EP2MASK(endpoint);

    /* Endpoint pending: Waits for the host read data after exiting this function */
    endpointData->state = CY_USB_DEV_EP_PENDING;

    /* Set count and data toggle */
    Cy_USBFS_Dev_Drv_SetSieEpCount(base, endpoint, size, (uint32_t) endpointData->toggle);

    if (0U == size)
    {
        /* Arm endpoint: Host is allowed to read data */
        Cy_USBFS_Dev_Drv_SetSieEpMode(base, endpoint, (uint32_t) endpointData->sieMode);
    }
    else
    {
        /* Copy data from user buffer to internal endpoint buffer */
        if (NULL != endpointData->copyData)
        {
            (void) endpointData->copyData(endpointData->buffer, buffer, size);
        }
        else
        {
            (void) memcpy(endpointData->buffer, buffer, size);
        }

        /* Get number of full bursts. */
        endpointData->DmaEpBurstCount = (uint32_t) (size / USBFS_DMA_BYTES_PER_BURST);
      
        /* Get number of elements in the last burst. */
        endpointData->DmaEpLastBurst = (uint32_t) (size % USBFS_DMA_BYTES_PER_BURST);
      
        /* Get total number of bursts. */
        endpointData->DmaEpBurstCount += (0U != endpointData->DmaEpLastBurst) ? 1U : 0U;
      
        /* Adjust number of data elements transferred in last burst. */
        endpointData->DmaEpLastBurst = (0U != endpointData->DmaEpLastBurst) ?
                                              (GET_SIZE(context->useReg16, endpointData->DmaEpLastBurst)) :
                                              (GET_SIZE(context->useReg16,USBFS_DMA_BYTES_PER_BURST));

        /* Get number of data elements to transfer for descriptor 0 and 1. */
        lengthDescr0 = (1U == endpointData->DmaEpBurstCount) ? endpointData->DmaEpLastBurst : 
                                                                GET_SIZE(context->useReg16, USBFS_DMA_BYTES_PER_BURST);
      
        lengthDescr1 = (2U == endpointData->DmaEpBurstCount) ? endpointData->DmaEpLastBurst :
                                                                GET_SIZE(context->useReg16, USBFS_DMA_BYTES_PER_BURST);

      
      
        /* Mark which descriptor is last one to execute. */
        endpointData->LastDescr = (bool)((0U != (endpointData->DmaEpBurstCount & 0x1U)) ? USBFS_DMA_DESCR0_MASK : USBFS_DMA_DESCR1_MASK);
      
        Cy_DMAC_Channel_Disable(endpointData->base, endpointData->chNum);

        /* Restore destination address for input endpoint. */
        Cy_DMAC_Descriptor_SetSrcAddress(endpointData->base, endpointData->chNum, CY_DMAC_DESCRIPTOR_PING, buf);
        Cy_DMAC_Descriptor_SetSrcAddress(endpointData->base, endpointData->chNum, CY_DMAC_DESCRIPTOR_PONG, (buf + USBFS_DMA_BYTES_PER_BURST));
        
        /* Set number of elements to transfer. */
        Cy_DMAC_Descriptor_SetDataCount(endpointData->base, endpointData->chNum , CY_DMAC_DESCRIPTOR_PING, lengthDescr0);
        Cy_DMAC_Descriptor_SetDataCount(endpointData->base, endpointData->chNum , CY_DMAC_DESCRIPTOR_PONG, lengthDescr1);

        /* Validate the PING descriptor */
        Cy_DMAC_Descriptor_SetState(endpointData->base, endpointData->chNum, CY_DMAC_DESCRIPTOR_PING, true);
        
        Cy_DMAC_Channel_SetCurrentDescriptor(endpointData->base, endpointData->chNum, CY_DMAC_DESCRIPTOR_PING);
        
        if(endpointData->DmaEpBurstCount > 1U)
        {
            /* Validate the PONG descriptor */
            Cy_DMAC_Descriptor_SetState(endpointData->base, endpointData->chNum, CY_DMAC_DESCRIPTOR_PONG, true);
        }
        
        /* Adjust burst counter taking to account: 2 valid descriptors and interrupt trigger after valid descriptor were executed. */
        endpointData->DmaEpBurstCount = USBFS_DMA_GET_BURST_CNT(endpointData->DmaEpBurstCount);

        Cy_DMAC_Channel_Enable(endpointData->base, endpointData->chNum);
      
        /* Start generation of DMA requests to pre-load data into endpoint buffer */
        Cy_USBFS_Dev_Drv_SetArbCfgEpInReady(base, endpoint);

        /* IN endpoint will be armed in the Arbiter interrupt (source: IN_BUF_FULL)
        * after DMA pre-load data buffer.
        */
    }

    return CY_USBFS_DEV_DRV_SUCCESS;
}

/*******************************************************************************
* Function Name: Cy_USBFS_Dev_Drv_EP_DmaDone
****************************************************************************//**
*
* Endpoint DMA Done Interrupt handler.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbfs_dev_drv_context_t
* allocated by the user. The structure is used during the USBFS Device
* operation for internal configuration and data retention. The user must not
* modify anything in this structure.
* 
* \param intrMask
* The DMAC Interrupt Status Mask.
*
*******************************************************************************/
void Cy_USBFS_Dev_Drv_EP_DmaDone(cy_stc_usbfs_dev_drv_context_t* context, uint32_t intrMask)
{
    uint32_t endpoint=0UL;

    /* Configure active endpoint DMA channels after completion of a transfer */
    for (endpoint = 0UL; endpoint < CY_USBFS_DEV_DRV_NUM_EPS_MAX; ++endpoint)
    {
        /* Get pointer to endpoint data */
        cy_stc_usbfs_dev_drv_endpoint_data_t *endpointData = &context->epPool[endpoint];
        
        /* Check for the endpoint corresponding to interrupt source */
        if(0U != (intrMask & 1UL<<endpointData->chNum))
        {
            uint32_t nextAddr;
            /* Manage data elements which remain to transfer. */
            if (0U != endpointData->DmaEpBurstCount)
            {
                if(endpointData->DmaEpBurstCount <= 2U)
                {
                    /* Adjust length of last burst. */
                    Cy_DMAC_Descriptor_SetDataCount(endpointData->base, 
                                                   endpointData->chNum, 
                                                   (cy_en_dmac_descriptor_t)(endpointData->LastDescr),
                                                   endpointData->DmaEpLastBurst); 
                }
    
                /* Advance source for input endpoint or destination for output endpoint. */
                if(CY_USBFS_DEV_DRV_IS_EP_DIR_IN(context->epPool[endpoint].address))                       
                {
                    /* Change source for descriptor 0. */
                    uint32_t* SrcAddr = Cy_DMAC_Descriptor_GetSrcAddress(endpointData->base, endpointData->chNum, CY_DMAC_DESCRIPTOR_PING);
                    nextAddr = (uint32_t)SrcAddr;
                    nextAddr += (2U * USBFS_DMA_BYTES_PER_BURST);
                    SrcAddr = (uint32_t *)nextAddr;
                    Cy_DMAC_Descriptor_SetSrcAddress(endpointData->base, endpointData->chNum, CY_DMAC_DESCRIPTOR_PING, (void *) SrcAddr);

                    /* Change source for descriptor 1. */
                    nextAddr += USBFS_DMA_BYTES_PER_BURST;
                    SrcAddr = (uint32_t *)nextAddr;
                    Cy_DMAC_Descriptor_SetSrcAddress(endpointData->base, endpointData->chNum, CY_DMAC_DESCRIPTOR_PONG, (void *) SrcAddr);
                }

                else
                {
                    /* Change destination for descriptor 0. */
                    uint32_t* DstAddr = Cy_DMAC_Descriptor_GetDstAddress(endpointData->base, endpointData->chNum, CY_DMAC_DESCRIPTOR_PING);
                    nextAddr = (uint32_t)DstAddr;
                    nextAddr += (2U * USBFS_DMA_BYTES_PER_BURST);
                    DstAddr = (uint32_t *)nextAddr;
                    Cy_DMAC_Descriptor_SetDstAddress(endpointData->base, endpointData->chNum, CY_DMAC_DESCRIPTOR_PING, (void *) DstAddr);
  
                    /* Change destination for descriptor 1. */
                    nextAddr += USBFS_DMA_BYTES_PER_BURST;
                    DstAddr = (uint32_t *)nextAddr;
                    Cy_DMAC_Descriptor_SetDstAddress(endpointData->base, endpointData->chNum, CY_DMAC_DESCRIPTOR_PONG, (void *) DstAddr);
    
                }
    
                /* Setup DMA to execute transfer as it was disabled because there were no valid descriptor. */
                Cy_DMAC_Descriptor_SetState(endpointData->base, endpointData->chNum, CY_DMAC_DESCRIPTOR_PING, true);
                
                /* Adjust burst count as per one PING descriptor burst */
                endpointData->DmaEpBurstCount -= 1U; 
                
                /* Check for the need of PONG descriptor */ 
                if (0U != endpointData->DmaEpBurstCount)
                {
                    /* Validate the PONG Descriptor */
                    Cy_DMAC_Descriptor_SetState(endpointData->base, endpointData->chNum, CY_DMAC_DESCRIPTOR_PONG, true);
                    
                    /* Adjust burst count as per one PONG descriptor burst */
                    endpointData->DmaEpBurstCount -= 1U; 
                }
    
                /* Enable the DMA channel */
                Cy_DMAC_Channel_Enable(endpointData->base, endpointData->chNum);
                
                uint32_t trigLine = (endpointData->chNum & USBFS_DMA_CHANNEL_MASK); 
                trigLine = ((uint32_t)TRIG1_OUT_CPUSS_DMAC_TR_IN8 | trigLine);
                
                /* Number of clocks for DMA completion pulse */
                const uint32_t CY_USBFS_DEV_DRV_TRIG_CYCLES = 2UL;

                /* Trigger the DMA request on the relevant channel */
                (void)Cy_TrigMux_SwTrigger(trigLine, CY_USBFS_DEV_DRV_TRIG_CYCLES);
            }
     
            else
            {
                /* No data to transfer. False DMA trig. Ignore.  */
            }
       }

    }
}

/*******************************************************************************
* Function Name: ReadOutEndpointDmaAuto
****************************************************************************//**
*
* Implements \ref Cy_USBFS_Dev_Drv_ReadOutEndpoint for
* \ref CY_USBFS_DEV_DRV_EP_MANAGEMENT_DMA_AUTO mode.
*
* \param base
* The pointer to the USBFS instance.
*
* \param endpoint
* The OUT data endpoint number.
*
* \param buffer
* Pointer to buffer that stores data that was read.
*
* \param size
* The number of bytes to read from the endpoint.
* This value must be less than or equal to the endpoint maximum packet size.
*
* \param actSize
* The number of bytes which were actually read.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbfs_dev_drv_context_t
* allocated by the user. The structure is used during the USBFS Device
* operation for internal configuration and data retention. The user must not
* modify anything in this structure.
*
* \return
* Status code of the function execution \ref cy_en_usbfs_dev_drv_status_t.
*
*******************************************************************************/
cy_en_usbfs_dev_drv_status_t ReadOutEndpointDmaAuto(USBFS_Type *base,
                                                    uint32_t   endpoint,
                                                    uint8_t    *buffer,
                                                    uint32_t   size,
                                                    uint32_t   *actSize,
                                                    cy_stc_usbfs_dev_drv_context_t *context)
{
    /* Get pointer to endpoint data */
    cy_stc_usbfs_dev_drv_endpoint_data_t *endpointData = &context->epPool[endpoint];

    /* Get number of received bytes */
    uint32_t numToCopy = Cy_USBFS_Dev_Drv_GetSieEpCount(base, endpoint);

    /* Initialize actual number of copied bytes */
    *actSize = 0U;

    /* Endpoint received more bytes than provided buffer */
    if (numToCopy > size)
    {
        return CY_USBFS_DEV_DRV_BAD_PARAM;
    }

    /* Nothing to copy (zero length packet) return success */
    if (0U == numToCopy)
    {
        return CY_USBFS_DEV_DRV_SUCCESS;
    }

    /* Copy data from user buffer to internal endpoint buffer */
    if (NULL != endpointData->copyData)
    {
        (void) endpointData->copyData(buffer, endpointData->buffer, numToCopy);
    }
    else
    {
        (void) memcpy(buffer, endpointData->buffer, numToCopy);
    }

    /* Update number of copied bytes */
    *actSize = numToCopy;

    uint32_t lengthDescr0, lengthDescr1;
    
    if(context->useReg16)
    {
        /* Adjust requested length: 2 bytes are handled at one data register access. */    
        size = size + (size & 0x01U);
    }

    /* Get number of full bursts. */
    endpointData->DmaEpBurstCount = (uint8_t) (size / USBFS_DMA_BYTES_PER_BURST);
   
    /* Get number of elements in the last burst. */
    endpointData->DmaEpLastBurst = (uint8_t) (size % USBFS_DMA_BYTES_PER_BURST);

    /* Get total number of bursts. */
    endpointData->DmaEpBurstCount += (0U !=  endpointData->DmaEpLastBurst) ? 1U : 0U;

    /* Adjust number of the data elements transferred in last burst. */
    endpointData->DmaEpLastBurst = (0U != endpointData->DmaEpLastBurst) ?
                                                          (GET_SIZE(context->useReg16, endpointData->DmaEpLastBurst)) :
                                                          (GET_SIZE(context->useReg16, USBFS_DMA_BYTES_PER_BURST));

    /* Get number of data elements to transfer for descriptor 0 and 1. */
    lengthDescr0 = (1U == endpointData->DmaEpBurstCount) ? endpointData->DmaEpLastBurst : 
                                                           (GET_SIZE(context->useReg16,USBFS_DMA_BYTES_PER_BURST));

    lengthDescr1 = (2U == endpointData->DmaEpBurstCount) ? endpointData->DmaEpLastBurst : 
                                                           (GET_SIZE(context->useReg16,USBFS_DMA_BYTES_PER_BURST));

    /* Mark if revert number of data elements in descriptor after transfer completion. */
    if(endpointData->DmaEpBurstCount > 2U) 
    {
        endpointData->RevertDescr = true; 
    }
    else
    {
        endpointData->RevertDescr = false; 
    }

    /* Mark last descriptor to be executed. */
    endpointData->LastDescr = (0U != (endpointData->DmaEpBurstCount & 0x1U)) ? USBFS_DMA_DESCR0_MASK : USBFS_DMA_DESCR1_MASK;

    /* Store the burst counter for endpoint. */
    endpointData->DmaOutEpBurstCountRestore = endpointData->DmaEpBurstCount;

    /* Adjust burst counter taking to account: 2 valid descriptors and interrupt trigger after valid descriptor were executed. */
    endpointData->DmaEpBurstCount = USBFS_DMA_GET_BURST_CNT(endpointData->DmaEpBurstCount);

    /* Disable DMA channel: start configuration. */
    Cy_DMAC_Channel_Disable(endpointData->base, endpointData->chNum);

    Cy_DMAC_Descriptor_SetDstAddress(endpointData->base, endpointData->chNum, CY_DMAC_DESCRIPTOR_PING, (void *)endpointData->buffer);
    Cy_DMAC_Descriptor_SetDstAddress(endpointData->base, endpointData->chNum, CY_DMAC_DESCRIPTOR_PONG, (void *)(endpointData->buffer + USBFS_DMA_BYTES_PER_BURST));

    /* Set number of elements to transfer. */
    Cy_DMAC_Descriptor_SetDataCount(endpointData->base, endpointData->chNum , CY_DMAC_DESCRIPTOR_PING, lengthDescr0);
    Cy_DMAC_Descriptor_SetDataCount(endpointData->base, endpointData->chNum , CY_DMAC_DESCRIPTOR_PONG, lengthDescr1);

    /* Validate the PING descriptor */
    Cy_DMAC_Descriptor_SetState(endpointData->base, endpointData->chNum, CY_DMAC_DESCRIPTOR_PING, true);
    
    /* Set first descriptor to execute */
    Cy_DMAC_Channel_SetCurrentDescriptor(endpointData->base, endpointData->chNum, CY_DMAC_DESCRIPTOR_PING);
 
    if(endpointData->DmaOutEpBurstCountRestore > 1U)
    {
        /* Validate the PONG descriptor */
        Cy_DMAC_Descriptor_SetState(endpointData->base, endpointData->chNum, CY_DMAC_DESCRIPTOR_PONG, true);
    }
    
    Cy_DMAC_Channel_Enable(endpointData->base, endpointData->chNum);

    return CY_USBFS_DEV_DRV_SUCCESS;
}

#endif /* (defined(CY_IP_M0S8CPUSSV3_DMAC) && (CY_USBFS_DRV_DMA_ENABLE == 1)) */

#endif /* CY_IP_M0S8USBDSS */

#if defined(__cplusplus)
}
#endif



/* [] END OF FILE */

