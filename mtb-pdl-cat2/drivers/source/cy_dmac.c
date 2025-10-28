/***************************************************************************//**
* \file cy_dmac.c
* \version 1.20
*
* \brief
* The source code file for the DMAC driver.
*
********************************************************************************
* \copyright
* (c) (2020-2021), Cypress Semiconductor Corporation (an Infineon company) or
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

#include "cy_dmac.h"

#if defined(CY_IP_M0S8CPUSSV3_DMAC)


/*******************************************************************************
* Function Name: Cy_DMAC_Descriptor_Init
****************************************************************************//**
*
* Initializes the descriptor structure from a pre-initialized
* configuration structure.
* This function initializes only one ping/pong descriptor and not the channel.
*
* \param base
* The pointer to the hardware DMAC block.
*
* \param channel
* A channel number.
*
* \param descriptor
* The ping/pong descriptor.
*
* \param config
* This is a configuration structure that has all initialization information for
* the descriptor.
*
* \return
* The status /ref cy_en_dmac_status_t.
*
* \funcusage
* \snippet dmac_snippet.c snippet_Cy_DMAC_Enable
*
*******************************************************************************/
cy_en_dmac_status_t Cy_DMAC_Descriptor_Init(DMAC_Type * base,
                                            uint32_t channel,
                                            cy_en_dmac_descriptor_t descriptor,
                                            const cy_stc_dmac_descriptor_config_t * config)
{
    CY_ASSERT_L3(CY_DMAC_IS_RETRIGGER_VALID(config->retrigger));
    CY_ASSERT_L3(CY_DMAC_IS_XFER_SIZE_VALID(config->srcTransferSize));
    CY_ASSERT_L3(CY_DMAC_IS_XFER_SIZE_VALID(config->dstTransferSize));
    CY_ASSERT_L3(CY_DMAC_IS_DATA_SIZE_VALID(config->dataSize));
    CY_ASSERT_L1(CY_DMAC_IS_DATA_CNT_VALID(config->dataCount));
    CY_ASSERT_L3(CY_DMAC_IS_TRIG_TYPE_VALID(config->triggerType));

    cy_en_dmac_status_t ret = CY_DMAC_BAD_PARAM;

    if ((NULL != base) && (NULL != config))
    {
        uint32_t ctlReg = _VAL2FLD(DMAC_DESCR_PING_CTL_DATA_NR,           config->dataCount - 1UL) |
                          _VAL2FLD(DMAC_DESCR_PING_CTL_DATA_SIZE,         config->dataSize)        |
                          _VAL2FLD(DMAC_DESCR_PING_CTL_DST_TRANSFER_SIZE, config->dstTransferSize) |
                         _BOOL2FLD(DMAC_DESCR_PING_CTL_DST_ADDR_INCR,     config->dstAddrIncrement)|
                          _VAL2FLD(DMAC_DESCR_PING_CTL_SRC_TRANSFER_SIZE, config->srcTransferSize) |
                         _BOOL2FLD(DMAC_DESCR_PING_CTL_SRC_ADDR_INCR,     config->srcAddrIncrement)|
                          _VAL2FLD(DMAC_DESCR_PING_CTL_WAIT_FOR_DEACT,    config->retrigger)       |
                         _BOOL2FLD(DMAC_DESCR_PING_CTL_INV_DESCR,         config->cpltState)       |
                         _BOOL2FLD(DMAC_DESCR_PING_CTL_SET_CAUSE,         config->interrupt)       |
                         _BOOL2FLD(DMAC_DESCR_PING_CTL_PREEMPTABLE,       config->preemptable)     |
                         _BOOL2FLD(DMAC_DESCR_PING_CTL_FLIPPING,          config->flipping)        |
                          _VAL2FLD(DMAC_DESCR_PING_CTL_OPCODE,            config->triggerType);

        if (CY_DMAC_DESCRIPTOR_PING == descriptor)
        {
            DMAC_DESCR_PING_STATUS(base, channel) = 0UL; /* Invalidate descriptor, also clear CURR_DATA_NR and RESPONSE */
            DMAC_DESCR_PING_CTL(base, channel) = ctlReg;
CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 11.6', 4, 'Casting void* to uint32_t \
is used only for set DMAC HW registers. The address must to be valid and value will always fit in unit32_t.');
            DMAC_DESCR_PING_SRC(base, channel) = (uint32_t)config->srcAddress;
            DMAC_DESCR_PING_DST(base, channel) = (uint32_t)config->dstAddress;
            DMAC_DESCR_PING_STATUS(base, channel) = DMAC_DESCR_PING_STATUS_VALID_Msk; /* Validate descriptor */
        }
        else
        {
            DMAC_DESCR_PONG_STATUS(base, channel) = 0UL; /* Invalidate descriptor, also clear CURR_DATA_NR and RESPONSE */
            DMAC_DESCR_PONG_CTL(base, channel) = ctlReg;
            DMAC_DESCR_PONG_SRC(base, channel) = (uint32_t)config->srcAddress;
            DMAC_DESCR_PONG_DST(base, channel) = (uint32_t)config->dstAddress;
CY_MISRA_BLOCK_END('MISRA C-2012 Rule 11.6');
            DMAC_DESCR_PONG_STATUS(base, channel) = DMAC_DESCR_PONG_STATUS_VALID_Msk; /* Validate descriptor */
        }

        ret = CY_DMAC_SUCCESS;
    }

    return (ret);
}


/*******************************************************************************
* Function Name: Cy_DMAC_Descriptor_DeInit
****************************************************************************//**
*
* Clears the content of the specified descriptor.
*
* \param base
* The pointer to the hardware DMAC block.
*
* \param channel
* The channel number.
*
* \param descriptor
* The descriptor structure instance.
*
* \funcusage
* \snippet dmac_snippet.c snippet_Cy_DMAC_Descriptor_Deinit
*
*******************************************************************************/
void Cy_DMAC_Descriptor_DeInit(DMAC_Type * base,
                               uint32_t channel,
                               cy_en_dmac_descriptor_t descriptor)
{
    DMAC_DESCR_SET_SRC(base, channel, descriptor, 0UL);
    DMAC_DESCR_SET_DST(base, channel, descriptor, 0UL);
    DMAC_DESCR_SET_CTL(base, channel, descriptor, 0UL);
    DMAC_DESCR_SET_STATUS(base, channel, descriptor, 0UL);
}


/*******************************************************************************
* Function Name: Cy_DMAC_Channel_Init
****************************************************************************//**
*
* Initializes the DMAC channel with an active descriptor and other parameters.
*
* \param base
* The pointer to the hardware DMAC block.
*
* \param channel
* The channel number.
*
* \param config
* The structure that has the initialization information for the
* channel.
*
* \return
* The status /ref cy_en_dmac_status_t.
*
* \funcusage
* \snippet dmac_snippet.c snippet_Cy_DMAC_Enable
*
*******************************************************************************/
cy_en_dmac_status_t Cy_DMAC_Channel_Init(DMAC_Type * base,
                                         uint32_t channel,
                                         cy_stc_dmac_channel_config_t const * config)
{
    cy_en_dmac_status_t ret = CY_DMAC_BAD_PARAM;

     if ((NULL != base) && (CY_DMAC_IS_CH_NR_VALID(channel)) && (NULL != config))
     {
         CY_ASSERT_L2(CY_DMAC_IS_PRIORITY_VALID(config->priority));
         CY_ASSERT_L1(CY_DMAC_IS_CH_NR_VALID(channel));

         /* Set the channel configuration */
         DMAC_CH_CTL(base, channel) = _VAL2FLD(DMAC_CH_CTL_PRIO,      config->priority)  |
                                     _BOOL2FLD(DMAC_CH_CTL_ENABLED,   config->enable)    |
                                     _BOOL2FLD(DMAC_CH_CTL_PING_PONG, config->descriptor);
         ret = CY_DMAC_SUCCESS;
     }

     return (ret);
}


/*******************************************************************************
* Function Name: Cy_DMAC_Channel_DeInit
****************************************************************************//**
*
* Clears the content of registers corresponding to the channel.
*
* \param base
* The pointer to the hardware DMAC block.
*
* \param channel
* The channel number.
*
* \funcusage
* \snippet dmac_snippet.c snippet_Cy_DMAC_Disable
*
*******************************************************************************/
void Cy_DMAC_Channel_DeInit(DMAC_Type * base, uint32_t channel)
{
    CY_ASSERT_L1(CY_DMAC_IS_CH_NR_VALID(channel));

    DMAC_CH_CTL(base, channel) = 0UL;
}


#endif /* defined(CY_IP_M0S8CPUSSV3_DMAC) */

/* [] END OF FILE */
