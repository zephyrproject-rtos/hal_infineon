/***************************************************************************//**
* \file mtb_hal_dma_dmac_mxsaxidmac_v1.h
*
* \brief
* Provides IP Specific API declarations that is applicable for MXSAXIDMAC driver
*
********************************************************************************
* \copyright
* Copyright 2024 Cypress Semiconductor Corporation (an Infineon company) or
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

#pragma once

#include <stdlib.h>
#include "cy_pdl.h"


#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */


/*******************************************************************************
*                           Defines
*******************************************************************************/

#define _MTB_HAL_DMAC_MAX_EL_PER_TRANSFER      (CY_AXIDMAC_LOOP_COUNT_MAX)

/*******************************************************************************
*                           Typedefs
*******************************************************************************/


/*******************************************************************************
*                        Public Function Prototypes
*******************************************************************************/

/** Setup the configuration in the DMA Object */
__STATIC_INLINE void _mtb_hal_dma_dmac_config_setup(mtb_hal_dma_t* obj,
                                                    const mtb_hal_dma_configurator_t* config)
{
    obj->dma_type = config->dma_type;
    obj->channel = config->channel;
    obj->base.dmac_base = (AXI_DMAC_Type*)config->dmac_base;
    obj->descriptor.dmac = (cy_stc_axidmac_descriptor_t*)config->dmac_descriptor;
}


/** Check if the requested DMAC descriptor configuration is supported */
__STATIC_INLINE cy_rslt_t _mtb_hal_dma_dmac_supported(const mtb_hal_dma_configurator_t* config)
{
    cy_rslt_t result = CY_RSLT_SUCCESS;
    cy_en_axidmac_descriptor_type_t descr_type = Cy_AXIDMAC_Descriptor_GetDescriptorType(
        config->dmac_descriptor);
    cy_en_axidmac_trigger_type_t intr_type = Cy_AXIDMAC_Descriptor_GetInterruptType(
        config->dmac_descriptor);
    //Only 1-D memory copy and 2-D memory copy is supported
    if ((CY_AXIDMAC_2D_MEMORY_COPY != descr_type) && (CY_AXIDMAC_1D_MEMORY_COPY != descr_type))
    {
        result = MTB_HAL_DMA_RSLT_ERR_NOT_SUPPORTED;
    }
    //Only CY_AXIDMAC_DESCR and CY_AXIDMAC_M_LOOP interrupt types are supported
    else if ((CY_AXIDMAC_DESCR != intr_type) && (CY_AXIDMAC_M_LOOP != intr_type))
    {
        result = MTB_HAL_DMA_RSLT_ERR_NOT_SUPPORTED;
    }
    return result;
}


/** Set the source address */
__STATIC_INLINE void _mtb_hal_dma_dmac_descriptor_set_src_addr(mtb_hal_dma_t* obj,
                                                               uint32_t src_addr)
{
    Cy_AXIDMAC_Descriptor_SetSrcAddress(obj->descriptor.dmac, (void*)src_addr);
}


/** Set the destination address */
__STATIC_INLINE void _mtb_hal_dma_dmac_descriptor_set_dst_addr(mtb_hal_dma_t* obj,
                                                               uint32_t dst_addr)
{
    Cy_AXIDMAC_Descriptor_SetDstAddress(obj->descriptor.dmac, (void*)dst_addr);
}


/** Set the transfer length */
__STATIC_INLINE cy_rslt_t _mtb_hal_dma_dmac_descriptor_set_length(mtb_hal_dma_t* obj,
                                                                  uint32_t length)
{
    cy_en_axidmac_descriptor_type_t descr_type = Cy_AXIDMAC_Descriptor_GetDescriptorType(
        obj->descriptor.dmac);
    cy_rslt_t result = CY_RSLT_SUCCESS;
    if (CY_AXIDMAC_2D_MEMORY_COPY == descr_type)
    {
        //This is based on the assumption that user/app does not want to change the burst size.
        //Length in case of 2-D transfers need to be a mutiple of the burst size.TODO: check this
        uint32_t mloop_count = Cy_AXIDMAC_Descriptor_GetMloopDataCount(obj->descriptor.dmac);
        if ((length > (mloop_count * CY_AXIDMAC_LOOP_COUNT_MAX)) || (length % mloop_count))
        {
            result = MTB_HAL_DMA_RSLT_ERR_INVALID_TRANSFER_SIZE;
        }
        else
        {
            Cy_AXIDMAC_Descriptor_SetXloopDataCount(obj->descriptor.dmac, length/mloop_count);
        }
    }
    else if (CY_AXIDMAC_1D_MEMORY_COPY == descr_type)
    {
        if (length > CY_AXIDMAC_LOOP_COUNT_MAX)
        {
            result = MTB_HAL_DMA_RSLT_ERR_INVALID_TRANSFER_SIZE;
        }
        else
        {
            Cy_AXIDMAC_Descriptor_SetMloopDataCount(obj->descriptor.dmac, length);
        }
    }
    else
    {
        //Return not supported
        result = MTB_HAL_DMA_RSLT_ERR_NOT_SUPPORTED;
    }
    return result;
}


/** Get the expected bursts based on the descriptor configuration */
__STATIC_INLINE uint32_t _mtb_hal_dma_dmac_get_expected_bursts(mtb_hal_dma_t* obj)
{
    uint32_t expected_bursts = 1;
    cy_en_axidmac_trigger_type_t intr_type = Cy_AXIDMAC_Descriptor_GetInterruptType(
        obj->descriptor.dmac);
    if (CY_AXIDMAC_DESCR == intr_type)
    {
        expected_bursts = 1;
    }
    else if (CY_AXIDMAC_M_LOOP == intr_type)
    {
        expected_bursts = Cy_AXIDMAC_Descriptor_GetXloopDataCount(obj->descriptor.dmac);
    }
    return expected_bursts;
}


/** Enable the DMA channel */
__STATIC_INLINE void _mtb_hal_dma_dmac_channel_enable(mtb_hal_dma_t* obj)
{
    Cy_AXIDMAC_Channel_Enable(obj->base.dmac_base, obj->channel);
}


/** Disable the DMA channel */
__STATIC_INLINE void _mtb_hal_dma_dmac_channel_disable(mtb_hal_dma_t* obj)
{
    Cy_AXIDMAC_Channel_Disable(obj->base.dmac_base, obj->channel);
}


/** Get the active DMA channels */
__STATIC_INLINE uint32_t _mtb_hal_dma_dmac_get_active_channels(mtb_hal_dma_t* obj)
{
    return Cy_AXIDMAC_GetActiveChannel(obj->base.dmac_base);
}


/** Set the trigger to start the DMA transfer */
__STATIC_INLINE void _mtb_hal_dma_dmac_channel_set_swtrigger(mtb_hal_dma_t* obj)
{
    Cy_AXIDMAC_Channel_SetSwTrigger(obj->base.dmac_base, obj->channel);
}


/** Clear the interrupt */
__STATIC_INLINE void _mtb_hal_dma_dmac_channel_clear_interrupt(mtb_hal_dma_t* obj)
{
    Cy_AXIDMAC_Channel_ClearInterrupt(obj->base.dmac_base, obj->channel, CY_AXIDMAC_INTR_MASK);
}


/** Get the interrupt status masked */
__STATIC_INLINE uint32_t _mtb_hal_dma_dmac_channel_get_interrupt_status_masked(mtb_hal_dma_t* obj)
{
    return Cy_AXIDMAC_Channel_GetInterruptStatusMasked(obj->base.dmac_base, obj->channel);
}


#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */
