/***************************************************************************//**
* \file cy_crypto_prng.h
* \version 1.0.1
*
* \brief
*  This file provides PRNG API declaration of the Crypto driver
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


#if !defined(CY_CRYPTO_PRNG_H)
#define CY_CRYPTO_PRNG_H

#include "cy_device.h"

#if (defined (CY_IP_M0S8CRYPTO) && defined (CRYPTO_PR)) || defined (CY_DOXYGEN)

#include "cy_crypto_common.h"
#include "cy_crypto_hw.h"
#include "cy_crypto_trng.h"

#if defined(__cplusplus)
extern "C" {
#endif

#define PRNG_LFSR32_SEED_VALUE_MAX_BIT_SIZE    32U
#define PRNG_LFSR31_SEED_VALUE_MAX_BIT_SIZE    31U
#define PRNG_LFSR29_SEED_VALUE_MAX_BIT_SIZE    29U

/**
* \addtogroup group_crypto_lld_rng_functions
* \{
*/

/*******************************************************************************
* Function Name: Cy_Crypto_Prng_Init
****************************************************************************//**
*
* This function initializes the PRNG (Pseudo Random Number Generator) parameters.
* Invoking this function causes a restart of the pseudo-random sequence.
*
* \note  Invoking this function multiple times with the same set of seed values
*        results in the same sequence of random numbers with \ref Cy_Crypto_Prng
*        function. 
*        To obtain a different pseudo-random sequence, pass a different set of
*        seed values for the LFSR registers. It is recommended to use 
*        \ref Cy_Crypto_Trng() to generate random seed values for each
*        initialization.
*
* \param base
* Base address of the Crypto block registers
*
* \param lfsrSeedValues
* Pointer to an array of three seed values for the Linear Feedback Shift
* Registers - LFSR32, LFSR31 and LFSR29 respectively. Each seed value must
* be a non-zero, random number. Passing NULL will cause seed values to be
* generated internally, using the \ref Cy_Crypto_Trng() function. In this case,
* ensure that \ref Cy_Crypto_Trng() is not called from another thread until the
* this function returns.
*
* \return
* \ref cy_en_crypto_status_t
*
* \funcusage
* \snippet crypto_snippet.c snippet_myCryptoPrngUse
*
*******************************************************************************/
__STATIC_INLINE cy_en_crypto_status_t Cy_Crypto_Prng_Init(CRYPTO_Type *base,
                                                          uint32_t* lfsrSeedValues)
{
    uint32_t lfsr32InitState = 0UL;
    uint32_t lfsr31InitState = 0UL;
    uint32_t lfsr29InitState = 0UL;

    if (NULL == base)
    {
        return CY_CRYPTO_BAD_PARAMS;
    }

    if (!Cy_Crypto_IsEnabled(base))
    {
        return CY_CRYPTO_HW_NOT_ENABLED;
    }

    if (NULL == lfsrSeedValues)
    {
        (void)Cy_Crypto_Trng(base, PRNG_LFSR32_SEED_VALUE_MAX_BIT_SIZE, &lfsr32InitState);
        (void)Cy_Crypto_Trng(base, PRNG_LFSR31_SEED_VALUE_MAX_BIT_SIZE, &lfsr31InitState);
        (void)Cy_Crypto_Trng(base, PRNG_LFSR29_SEED_VALUE_MAX_BIT_SIZE, &lfsr29InitState);
    }
    else
    {
        lfsr32InitState = *lfsrSeedValues;
        lfsr31InitState = *(lfsrSeedValues + 1);
        lfsr29InitState = *(lfsrSeedValues + 2);

        if (0UL == lfsr32InitState || 0UL == lfsr31InitState || 0UL == lfsr29InitState)
        {
            return CY_CRYPTO_BAD_PARAMS;
        }
    }

    REG_CRYPTO_PR_LFSR_CTL0(base) = lfsr32InitState;
    REG_CRYPTO_PR_LFSR_CTL1(base) = lfsr31InitState;
    REG_CRYPTO_PR_LFSR_CTL2(base) = lfsr29InitState;

    return CY_CRYPTO_SUCCESS;
}

/*******************************************************************************
* Function Name: Cy_Crypto_Prng
****************************************************************************//**
*
* This function generates a Pseudo Random Number based on the initial seed
* values provided in \ref Cy_Crypto_Prng_Init().
*
* \param base
* Base address of the Crypto block registers
*
* \param max
* Maximum value of the generated pseudo random number. The range of the pseudo
* random number generated is [0, max]. The max value can be any integer between
* 1 and 2<sup>32</sup> - 1 (1 to 4294967295).
*
*
* \param randomNum
* Pointer to the generated pseudo random number. This must be a pointer to a
* 32-bit number.
*
* \return
* \ref cy_en_crypto_status_t
*
* \funcusage
* \snippet crypto_snippet.c snippet_myCryptoPrngUse
*
*******************************************************************************/
__STATIC_INLINE cy_en_crypto_status_t Cy_Crypto_Prng(CRYPTO_Type *base,
                                                     uint32_t max,
                                                     uint32_t *randomNum)
{
    if (NULL == base || NULL == randomNum || 0UL == max)
    {
        return CY_CRYPTO_BAD_PARAMS;
    }

    if(!Cy_Crypto_IsEnabled(base))
    {
        return CY_CRYPTO_HW_NOT_ENABLED;
    }

    REG_CRYPTO_PR_CTL(base) =  max;
    REG_CRYPTO_PR_CMD(base) =  1U << 0;

    /* Wait for crypto operation completion */
    while ((REG_CRYPTO_PR_CMD(base) & (1U << 0)) != 0U)
    {
    }

    /* Read the generated random number */
    *randomNum = REG_CRYPTO_PR_RESULT(base);

    return CY_CRYPTO_SUCCESS;
}

/** \} group_crypto_lld_rng_functions */

#if defined(__cplusplus)
}
#endif

#endif /* CY_IP_M0S8CRYPTO */

#endif /* #if !defined(CY_CRYPTO_PRNG_H) */


/* [] END OF FILE */
