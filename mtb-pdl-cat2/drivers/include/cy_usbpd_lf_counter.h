/***************************************************************************//**
* \file cy_usbpd_lf_counter.h
* \version 2.110
*
* Provides API declarations of the USBPD LF Counter driver.
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
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/
#ifndef _CY_USBPD_LF_COUNTER_H_
#define _CY_USBPD_LF_COUNTER_H_

#if (defined(CY_IP_MXUSBPD) || defined(CY_IP_M0S8USBPD))

/**
* \addtogroup group_usbpd_lf_counter
* \{
* USBPD LF Counter driver.
*
* \defgroup group_usbpd_lf_counter_functions Functions
*/

/*******************************************************************************
*       Function Constants
*******************************************************************************/

/** \cond Internal */
/** The LF Counter maximum match value */
#define USBPD_LF_MAX_MATCH_VALUE                      (PDSS_LF_CNTR_MATCH_MATCH_MASK >> PDSS_LF_CNTR_MATCH_MATCH_POS)

/** The LF Counter maximum ignore bit value */
#define USBPD_LF_MAX_IGNORE_BITS                      (PDSS_LF_CNTR_MATCH_IGNORE_BITS_MASK >> PDSS_LF_CNTR_MATCH_IGNORE_BITS_POS)

/* Internal macro to validate match value */
#define CY_USBPD_LF_IS_MATCH_VALID(match)             ((match) <= USBPD_LF_MAX_MATCH_VALUE)

/* Internal macro to validate match value */
#define CY_USBPD_LF_IS_IGNORE_BITS_VALID(bitsNum)     ((bitsNum) <= USBPD_LF_MAX_IGNORE_BITS)
/** \endcond */

/*******************************************************************************
*                            Function Prototypes
*******************************************************************************/

/**
* \addtogroup group_usbpd_lf_counter_functions
* \{
*/

/*******************************************************************************
* Function Name: Cy_LF_GetCount
****************************************************************************//**
*
* This function returns the current LF counter value.
*
* \param hwContext
* Pointer to the context structure of the LF counter hardware block.
*
* \return
* Live LF counter value
*
*******************************************************************************/
uint32_t Cy_LF_GetCount(void* hwContext);

/*******************************************************************************
* Function Name: Cy_LF_MaskInterrupt
****************************************************************************//**
*
* This function masks the interrupts from the LF counter. After masking interrupts, they
* are not passed to the CPU.
*
* \param hwContext
* Pointer to the context structure of the LF counter hardware block.
*
* \return
* None
*
*******************************************************************************/
void Cy_LF_MaskInterrupt(void* hwContext);

/*******************************************************************************
* Function Name: Cy_LF_UnmaskInterrupt
****************************************************************************//**
*
* This function unmasks the interrupts from the LF counter. After unmasking interrupts, they
* are passed to the CPU.
*
* \param hwContext
* Pointer to the context structure of the LF counter hardware block.
*
* \return
* None
*
*******************************************************************************/
void Cy_LF_UnmaskInterrupt(void* hwContext);

/*******************************************************************************
* Function Name: Cy_LF_SetMatch
****************************************************************************//**
*
* Configures the LF counter match comparison value.
*
* \param hwContext
* Pointer to the context structure of the LF counter hardware block.
*
* \param match
* The valid range is [0-65535]. The value to be used to match
* against the counter.
*
*******************************************************************************/
void Cy_LF_SetMatch(void* hwContext, uint32_t match);

/*******************************************************************************
* Function Name: Cy_LF_GetIgnoreBits
****************************************************************************//**
*
* This function reads the number of the most significant bits of the LF counter that
* are not checked against the match value. 
*
* \param hwContext
* Pointer to the context structure of the LF counter hardware block.
*
* \return
* The number of the most significant bits.
*
*******************************************************************************/
uint32_t Cy_LF_GetIgnoreBits(void* hwContext);

/*******************************************************************************
* Function Name: Cy_LF_ClearInterrupt
****************************************************************************//**
*
* This function clears the LF counter interrupt. 
*
* \param hwContext
* Pointer to the context structure of the LF counter hardware block.
*
* \return
* None
*
*******************************************************************************/
void Cy_LF_ClearInterrupt(void* hwContext);

/*******************************************************************************
* Function Name: Cy_LF_GetMatch
****************************************************************************//**
*
* This function reads the LF counter match comparison value. 
*
* \param hwContext
* Pointer to the context structure of the LF counter hardware block.
*
* \return
* LF counter match value.
*
*******************************************************************************/
uint32_t Cy_LF_GetMatch(void* hwContext);

/** \} group_usbpd_lf_counter_functions */

/** \} group_usbpd_lf_counter */
#endif /* (defined(CY_IP_MXUSBPD) || defined(CY_IP_M0S8USBPD)) */

#endif /* _CY_USBPD_LF_COUNTER_H_ */

/* [] END OF FILE */
