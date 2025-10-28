/***************************************************************************//**
* \file cy_crypto_trng.h
* \version 1.0.1
*
* \brief
*  This file provides TRNG API declaration of the Crypto driver
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

#if !defined(CY_CRYPTO_TRNG_H)
#define CY_CRYPTO_TRNG_H

#include "cy_device.h"

#if (defined (CY_IP_M0S8CRYPTO) && defined (CRYPTO_TR)) || defined (CY_DOXYGEN)

#include "cy_crypto_common.h"

#if defined(__cplusplus)
extern "C" {
#endif

#include "cy_crypto_hw.h"

/**
* \addtogroup group_crypto_lld_rng_functions
* \{
*/

/*******************************************************************************
* Function Name: Cy_Crypto_Trng
****************************************************************************//**
*
* This function generates a True Random Number.
*
* \note  True random number generation is slower than pseudo random number
*        generation. For generating a large number of random numbers, it is
*        recommended to use this function to obtain random seed values for PRNG
*        and generate the random numbers by using the \ref Cy_Crypto_Prng()
*        function.
*
* \param base
* Base address of the Crypto block registers
*
* \param max
* Maximum length of a random number, in the range of [1, 32] bits. The generated
* random number is in the range of [1, 2<sup>max</sup>].
*
* \param randomNum
* Pointer to the generated true random number. This must be a pointer to a
* 32-bit number.
*
* \return
* \ref cy_en_crypto_status_t
*
* \funcusage
* \snippet crypto_snippet.c snippet_myCryptoTrngUse
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Trng(CRYPTO_Type *base,
                                     uint32_t  max,
                                     uint32_t *randomNum);

/** \} group_crypto_lld_rng_functions */

#if defined(__cplusplus)
}
#endif

#endif /* CY_IP_M0S8CRYPTO */

#endif /* #if !defined(CY_CRYPTO_TRNG_H) */


/* [] END OF FILE */
