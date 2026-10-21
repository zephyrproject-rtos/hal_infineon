/***************************************************************************//**
* \file cy_crypto_trng.c
* \version 1.0.1
*
* \brief
*  This file provides TRNG API implementation of the Crypto driver.
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
#include "cy_device.h"

#if (defined (CY_IP_M0S8CRYPTO) && defined (CRYPTO_TR))

#include "cy_syslib.h"
#include "cy_crypto_trng.h"

#if defined(__cplusplus)
extern "C" {
#endif

#define TRNG_CTL0_DEF_VALUE             0x01FF4040
#define TRNG_CMD_START_RO               0x3F         /* Enable all ring oscillators */

/**
* The polynomial for programmable Galois ring oscillator. The polynomial is represented
* WITHOUT the high order bit (this bit is always assumed '1'). The polynomial should be aligned
* so that the more significant bits (bit 30 and down) contain the polynomial and the less
* significant bits (bit 0 and up) contain padding '0's.
*/
#define TRNG_GARO_CTL_DEF_VALUE         (0x6c740b8dU)

/**
* The polynomial for the programmable Fibonacci ring oscillator. The polynomial is represented
* WITHOUT the high order bit (this bit is always assumed '1'). The polynomial should
* be aligned so that the more significant bits (bit 30 and down) contain the polynomial
* and the less significant bits (bit 0 and up) contain padding '0's.
*/
#define TRNG_FIRO_CTL_DEF_VALUE         (0x52d246e1U)

#define TRNG_DATA_BIT_SIZE_MIN          1U
#define TRNG_DATA_BIT_SIZE_MAX          32U

/******************************************************************************
* Function Name: Cy_Crypto_GetInterruptStatus
***************************************************************************//**
*
* Reports states of multiple interrupt sources.
*
* \param base
* The pointer to the CRYPTO instance.
*
* \return
* Source bits. See definitions above.
*
******************************************************************************/
__STATIC_INLINE uint32_t Cy_Crypto_GetInterruptStatus(CRYPTO_Type *base)
{
    return (REG_CRYPTO_INTR(base));
}

/*******************************************************************************
* Function Name: Cy_Crypto_Trng_WaitForComplete
****************************************************************************//**
*
* Waits for TRNG random generation is complete.
*
* \param base
* The pointer to the CRYPTO instance.
*
* \note
* After this call the Health Monitor status should be checked to ensure that
* random data is healthy.
*
*******************************************************************************/
__STATIC_INLINE void Cy_Crypto_Trng_WaitForComplete(CRYPTO_Type *base)
{
    uint32_t status;
    /* Wait until the TRNG random generation is complete */
    do
    {
        status = Cy_Crypto_GetInterruptStatus(base) & (CRYPTO_INTR_TR_DATA_AVAILABLE_Msk  |
                                                             CRYPTO_INTR_TR_AP_DETECT_Msk |
                                                            CRYPTO_INTR_TR_RC_DETECT_Msk);
    }
    while (status == 0U);
}

/*******************************************************************************
* Function Name: Cy_Crypto_Trng
****************************************************************************//**
* Generates a True Random Number based on the user input.
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Trng(CRYPTO_Type *base,
                                     uint32_t  max,
                                     uint32_t *randomNum)
{
    if (NULL == base || NULL == randomNum)
    {
        return CY_CRYPTO_BAD_PARAMS;
    }

    if ((max < TRNG_DATA_BIT_SIZE_MIN) || (max > TRNG_DATA_BIT_SIZE_MAX))
    {
        return CY_CRYPTO_BAD_PARAMS;
    }

    if (!Cy_Crypto_IsEnabled(base))
    {
        return CY_CRYPTO_HW_NOT_ENABLED;
    }

    /* Set CTL registers */
    REG_CRYPTO_TR_GARO_CTL(base) = (TRNG_GARO_CTL_DEF_VALUE & CRYPTO_TR_GARO_CTL_POLYNOMIAL31_Msk);
    REG_CRYPTO_TR_FIRO_CTL(base) = (TRNG_FIRO_CTL_DEF_VALUE & CRYPTO_TR_FIRO_CTL_POLYNOMIAL31_Msk);
    REG_CRYPTO_TR_CTL0(base) = TRNG_CTL0_DEF_VALUE;
    REG_CRYPTO_TR_CTL1(base) = max;

    /* Enable required ring oscillators */
    REG_CRYPTO_TR_CMD(base) =  TRNG_CMD_START_RO;

    /* Wait for TRNG crypto operation completion */
    Cy_Crypto_Trng_WaitForComplete(base);

    /* Read the generated random number */
    *randomNum = REG_CRYPTO_TR_RESULT0(base);

    /* Stop the ring oscillators */
    REG_CRYPTO_TR_CMD(base) =  0;

    /* Clear the consumed bits */
    REG_CRYPTO_TR_RESULT0(base) = 0;

    /* Decrement TR_RESULT1 by the number of consumed bits */
    REG_CRYPTO_TR_RESULT1(base) = REG_CRYPTO_TR_RESULT1(base) - max;

    /* Clear TR_DATA_AVAILABLE interrupt */
    REG_CRYPTO_INTR(base) = 0x00000080;

    /* For data length less than Maximum bit size, apply mask and provide only max bits from the randomly generated number. */
    if (max < TRNG_DATA_BIT_SIZE_MAX)
    {
        *randomNum &= ((1UL << max) - 1U);
    }

    return CY_CRYPTO_SUCCESS;
}

#if defined(__cplusplus)
}
#endif

#endif /* defined(CY_IP_M0S8CRYPTO) */


/* [] END OF FILE */
