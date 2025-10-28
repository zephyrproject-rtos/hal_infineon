/***************************************************************************//**
* \file cy_cryptolite_trng.c
* \version 1.40
*
* \brief
*  This file provides TRNG API implementation of the Cryptolite driver.
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
#include "cy_device.h"

#if (defined (CY_IP_M0S8CRYPTOLITE) && defined (CRYPTOLITE_TRNG_PRESENT))

#include "cy_syslib.h"
#include "cy_cryptolite_trng.h"

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

/******************************************************************************
* Function Name: Cy_Cryptolite_GetInterruptStatus
***************************************************************************//**
*
* Reports states of multiple interrupt sources.
*
* \param base
* The pointer to the CRYPTOLITE instance.
*
* \return
* Source bits. See definitions above.
*
******************************************************************************/
__STATIC_INLINE uint32_t Cy_Cryptolite_GetInterruptStatus(CRYPTOLITE_Type *base)
{
    return (REG_CRYPTOLITE_INTR_TRNG(base));
}

/*******************************************************************************
* Function Name: Cy_Cryptolite_Trng_WaitForComplete
****************************************************************************//**
*
* Waits for TRNG random generation is complete.
*
* \param base
* The pointer to the CRYPTOLITE instance.
*
* \note
* After this call the Health Monitor status should be checked to ensure that
* random data is healthy.
*
*******************************************************************************/
__STATIC_INLINE void Cy_Cryptolite_Trng_WaitForComplete(CRYPTOLITE_Type *base)
{
    uint32_t status;
    /* Wait until the TRNG random generation is complete */
    do
    {
        status = Cy_Cryptolite_GetInterruptStatus(base) & (CRYPTOLITE_INTR_TRNG_DATA_AVAILABLE_Msk  |
                                                             CRYPTOLITE_INTR_TRNG_AP_DETECT_Msk |
                                                            CRYPTOLITE_INTR_TRNG_RC_DETECT_Msk);
    }
    while (status == 0U);
}

/*******************************************************************************
* Function Name: Cy_Cryptolite_Trng
****************************************************************************//**
* Generates a True Random Number based on the user input.
*******************************************************************************/
cy_en_cryptolite_status_t Cy_Cryptolite_Trng(CRYPTOLITE_Type *base,
                                     uint32_t *randomNum)
{
    uint32_t status = 0x00;

    if (NULL == base || NULL == randomNum)
    {
        return CY_CRYPTOLITE_BAD_PARAMS;
    }

    /* Set CTL registers */
    REG_CRYPTOLITE_TRNG_GARO_CTL(base) = (TRNG_GARO_CTL_DEF_VALUE & CRYPTOLITE_TRNG_GARO_CTL_POLYNOMIAL_Msk);
    REG_CRYPTOLITE_TRNG_FIRO_CTL(base) = (TRNG_FIRO_CTL_DEF_VALUE & CRYPTOLITE_TRNG_FIRO_CTL_POLYNOMIAL_Msk);
    REG_CRYPTOLITE_TRNG_CTL0(base) = TRNG_CTL0_DEF_VALUE;
    REG_CRYPTOLITE_TRNG_CTL1(base) = TRNG_CMD_START_RO;

    /* Enable AP and RC test */
    REG_CRYPTOLITE_TRNG_MON_CTL(base) = ((CY_CRYPTOLITE_TRNG_BITSTREAM_TR << CRYPTOLITE_TRNG_MON_CTL_BITSTREAM_SEL_Pos) |
                                        (CY_CRYPTOLITE_TRNG_AP_EN << CRYPTOLITE_TRNG_MON_CTL_AP_Pos) |
                                        (CY_CRYPTOLITE_TRNG_RC_EN << CRYPTOLITE_TRNG_MON_CTL_RC_Pos));

    /* Wait for TRNG crypto operation completion */
    Cy_Cryptolite_Trng_WaitForComplete(base);

    /* Get the AP and RC detection status */
    status = Cy_Cryptolite_GetInterruptStatus(base) & (CRYPTOLITE_INTR_TRNG_AP_DETECT_Msk
                                                     | CRYPTOLITE_INTR_TRNG_RC_DETECT_Msk);

    if(0UL != status)
    {
        return CY_CRYPTOLITE_TRNG_AP_RC_DETECTED;
    }

    /* Read the generated random number */
    *randomNum = REG_CRYPTOLITE_TRNG_RESULT(base);

    return CY_CRYPTOLITE_SUCCESS;
}


#if defined(__cplusplus)
}
#endif

#endif /* (defined (CY_IP_M0S8CRYPTOLITE) && defined (CRYPTOLITE_TRNG_PRESENT)) */


/* [] END OF FILE */
