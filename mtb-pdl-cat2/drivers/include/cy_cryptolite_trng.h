/***************************************************************************//**
* \file cy_cryptolite_trng.h
* \version 1.40
*
* \brief
*  This file provides TRNG API declaration of the Crypto driver
*
*******************************************************************************
* \copyright
* (c) (2021-2025), Cypress Semiconductor Corporation (an Infineon company) or
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

#if !defined(CY_CRYPTOLITE_TRNG_H)
#define CY_CRYPTOLITE_TRNG_H

#include "cy_device.h"

#if (defined (CY_IP_M0S8CRYPTOLITE) && defined (CRYPTOLITE_TRNG_PRESENT)) || defined (CY_DOXYGEN)

#include "cy_cryptolite_common.h"

#if defined(__cplusplus)
extern "C" {
#endif

/**
* \addtogroup group_cryptolite_trng
* \{
* True Random Number Generator (TRNG)
*
* True Random Number Generator (TRNG) component based on a set of ring oscillators.
* The TRNG includes a HW health monitor. This component generates true random 
* numbers using up to 6 ring oscillators.
*
* \defgroup group_cryptolite_trng_macros Macros
* \defgroup group_cryptolite_trng_data_structures Structures
* \defgroup group_cryptolite_trng_functions Functions
*
* */

/**
* \addtogroup group_cryptolite_trng_functions
* \{
*/

/*******************************************************************************
* Function Name: Cy_Cryptolite_Trng
****************************************************************************//**
*
* This function generates a True Random Number.
*
* \note  True Number generator fixed to generate 32-bit width only.
*
* \param base
* Base address of the Crypto block registers
*
* \param randomNum
* Pointer to the generated true random number. This must be a pointer to a
* 32-bit number.
*
* \return
* \ref cy_en_cryptolite_status_t
*
* \funcusage
* \snippet cryptolite_sut.c snippet_myCryptoliteTrngUse
*
*******************************************************************************/
cy_en_cryptolite_status_t Cy_Cryptolite_Trng(CRYPTOLITE_Type *base,
                                     uint32_t *randomNum);

/** \} group_cryptolite_trng_functions */
/** \} group_cryptolite_trng */

#if defined(__cplusplus)
}
#endif

#endif /* (defined (CY_IP_M0S8CRYPTOLITE) && defined (CRYPTOLITE_TRNG_PRESENT)) || defined (CY_DOXYGEN) */

#endif /* #if !defined(CY_CRYPTOLITE_TRNG_H) */


/* [] END OF FILE */
