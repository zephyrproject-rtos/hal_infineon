/***************************************************************************//**
* \file cy_usbpd_lf_counter.c
* \version 2.110
*
* The source file of the USBPD LF Counter Driver.
*
********************************************************************************
* \copyright
* (c) (2023-2025), Cypress Semiconductor Corporation (an Infineon company) or
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
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either expressed or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

#include "cy_device.h"
#include "cy_device_headers.h"

#if (defined(CY_IP_MXUSBPD) || defined(CY_IP_M0S8USBPD))

#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP)|| defined(CY_DEVICE_PAG2S))

#include "cy_usbpd_lf_counter.h"
#include "cy_usbpd_common.h"
#include "cy_usbpd_defines.h"

uint32_t Cy_LF_GetCount(void* hwContext)
{
    cy_stc_usbpd_context_t *context = (cy_stc_usbpd_context_t *)hwContext;
    return (context->base->lf_cntr & PDSS_LF_CNTR_MATCH_MATCH_MASK);
}

void Cy_LF_MaskInterrupt(void* hwContext)
{
    cy_stc_usbpd_context_t *context = (cy_stc_usbpd_context_t *)hwContext;
#if defined(CY_DEVICE_CCG6DF_CFP)
    context->base->intr20_mask &= ~PDSS_INTR20_LF_CNTR_MATCH;
#else
    context->base->intr1_mask &= ~PDSS_INTR1_LF_CNTR_MATCH;
#endif /* defined(CY_DEVICE_CCG6DF_CFP) */
}

void Cy_LF_UnmaskInterrupt(void* hwContext)
{
    cy_stc_usbpd_context_t *context = (cy_stc_usbpd_context_t *)hwContext;    
#if defined(CY_DEVICE_CCG6DF_CFP)
    context->base->intr20_mask |= PDSS_INTR20_LF_CNTR_MATCH;
#else
    context->base->intr1_mask |= PDSS_INTR1_LF_CNTR_MATCH;
#endif /* defined(CY_DEVICE_CCG6DF_CFP) */
}

void Cy_LF_SetMatch(void* hwContext, uint32_t match)
{
    CY_ASSERT_L2(CY_USBPD_LF_IS_MATCH_VALID(match));
    cy_stc_usbpd_context_t *context = (cy_stc_usbpd_context_t *)hwContext;
    context->base->lf_cntr_match = match;
}

uint32_t Cy_LF_GetIgnoreBits(void* hwContext)
{
    cy_stc_usbpd_context_t *context = (cy_stc_usbpd_context_t *)hwContext;
    return (context->base->lf_cntr_match & PDSS_LF_CNTR_MATCH_IGNORE_BITS_MASK);    
}

void Cy_LF_ClearInterrupt(void* hwContext)
{
    cy_stc_usbpd_context_t *context = (cy_stc_usbpd_context_t *)hwContext;
#if defined(CY_DEVICE_CCG6DF_CFP)
    context->base->intr20 = PDSS_INTR20_LF_CNTR_MATCH;
#else
    context->base->intr1 = PDSS_INTR1_LF_CNTR_MATCH;
#endif /* defined(CY_DEVICE_CCG6DF_CFP) */
}

uint32_t Cy_LF_GetMatch(void* hwContext)
{
    cy_stc_usbpd_context_t *context = (cy_stc_usbpd_context_t *)hwContext;
    return (context->base->lf_cntr_match & PDSS_LF_CNTR_MATCH_MATCH_MASK);
}
#endif /* (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP)|| defined(CY_DEVICE_PAG2S)) */

#endif /* (defined(CY_IP_MXUSBPD) || defined(CY_IP_M0S8USBPD)) */

/* [] END OF FILE */
