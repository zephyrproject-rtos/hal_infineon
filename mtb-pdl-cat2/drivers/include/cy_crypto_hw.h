/***************************************************************************//**
* \file cy_crypto_hw.h
* \version 1.0.1
*
* \brief
*  This file provides Control and Status API declaration of the Crypto driver
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


#if !defined(CY_CRYPTO_HW_H)
#define CY_CRYPTO_HW_H

#include "cy_device.h"

#if defined(CY_IP_M0S8CRYPTO)

#include "cy_crypto_common.h"

#if defined(__cplusplus)
extern "C" {
#endif

/**
* \addtogroup group_crypto_lld_hw_functions
* \{
*/
/*******************************************************************************
* Function Name: Cy_Crypto_Enable
****************************************************************************//**
*
* This function enables (turns on) the Crypto hardware.
*
* \param base
* Base address of the Crypto block registers
*
* \return
* Crypto status \ref cy_en_crypto_status_t
*
* \funcusage
* \snippet crypto_snippet.c snippet_myCryptoStartCryptoUse
*
*******************************************************************************/
__STATIC_INLINE cy_en_crypto_status_t Cy_Crypto_Enable(CRYPTO_Type *base)
{
    if (NULL == base)
    {
        return (CY_CRYPTO_BAD_PARAMS);
    }

    REG_CRYPTO_CTL(base) |= _VAL2FLD(CRYPTO_CTL_ENABLED,  1uL);

    return (CY_CRYPTO_SUCCESS);
}

/*******************************************************************************
* Function Name: Cy_Crypto_Disable
****************************************************************************//**
*
* This function disables (turns off) the Crypto hardware.
*
* \param base
* Base address of the Crypto block registers
*
* \return
* Crypto status \ref cy_en_crypto_status_t
*
* \funcusage
* \snippet crypto_snippet.c snippet_myCryptoStopCryptoUse
*
*******************************************************************************/
__STATIC_INLINE cy_en_crypto_status_t Cy_Crypto_Disable(CRYPTO_Type *base)
{
    if (NULL == base)
    {
        return (CY_CRYPTO_BAD_PARAMS);
    }

    REG_CRYPTO_CTL(base) &= ~(_VAL2FLD(CRYPTO_CTL_ENABLED, 1uL));

    return (CY_CRYPTO_SUCCESS);
}

/*******************************************************************************
* Function Name: Cy_Crypto_IsEnabled
****************************************************************************//**
*
* The function checks whether the Crypto hardware is enabled.
*
* \param base
* Base address of the Crypto block registers
*
* \return
* Crypto hardware status. True if enabled; else false.
*
* \funcusage
* \snippet crypto_snippet.c snippet_myCryptoStopCryptoUse
*
*******************************************************************************/
__STATIC_INLINE bool Cy_Crypto_IsEnabled(CRYPTO_Type *base)
{
    if (NULL == base)
    {
        return false;
    }

    return (1uL == (uint32_t)_FLD2VAL(CRYPTO_CTL_ENABLED, REG_CRYPTO_CTL(base)));
}

/*******************************************************************************
* Function Name: Cy_Crypto_ClearState
****************************************************************************//**
*
* This function clears the current state of the Crypto block. All the Crypto
* block registers are set to their default (reset) values and the memory buffer
* is initialized with zeros.
*
* \param base
* Base address of the Crypto block registers
*
* \return
* Crypto status \ref cy_en_crypto_status_t
*
* \funcusage
* \snippet crypto_snippet.c snippet_myCryptoClearStateUse
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_ClearState(CRYPTO_Type *base);

/*******************************************************************************
* Function Name: Cy_Crypto_WaitForReady
****************************************************************************//**
*
* The function waits for any ongoing Crypto operation (AES, CRC, or SHA) to
* complete and returns when the hardware is no longer busy.
*
* \param base
* Base address of the Crypto block registers
*
* \funcusage
* \snippet crypto_snippet.c snippet_myCryptoWaitForReadyUse
*
*******************************************************************************/
__STATIC_INLINE void Cy_Crypto_WaitForReady(CRYPTO_Type *base)
{
    if (NULL == base)
    {
        return;
    }

    while ((REG_CRYPTO_STATUS(base) & (CRYPTO_STATUS_BUSY_Msk)) != 0UL)
    {
    }
}

/** \} group_crypto_lld_hw_functions */

#if defined(__cplusplus)
}
#endif

#endif /* CY_IP_M0S8CRYPTO */

#endif /* #if !defined(CY_CRYPTO_HW_H) */


/* [] END OF FILE */
