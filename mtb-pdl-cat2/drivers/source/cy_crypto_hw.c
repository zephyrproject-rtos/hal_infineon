/***************************************************************************//**
* \file cy_crypto_hw.c
* \version 1.0.1
*
* \brief
*  This file provides the source code for Crypto driver clear state function
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

#if defined (CY_IP_M0S8CRYPTO)

#include "cy_crypto_hw.h"

#if defined(__cplusplus)
extern "C" {
#endif

#include "string.h"

#define CY_CRYPTO_CTL_DEFAULT_VALUE              0x0000001F
#define CY_CRYPTO_SRC_CTL0_DEFAULT_VALUE         0x00000000
#define CY_CRYPTO_SRC_CTL1_DEFAULT_VALUE         0x00000000
#define CY_CRYPTO_DST_CTL0_DEFAULT_VALUE         0x00000000
#define CY_CRYPTO_DST_CTL1_DEFAULT_VALUE         0x00000000
#define CY_CRYPTO_AES_CTL_DEFAULT_VALUE          0x00000000
#define CY_CRYPTO_PR_CTL_DEFAULT_VALUE           0x00000000
#define CY_CRYPTO_PR_LFSR_CTL0_DEFAULT_VALUE     0x00000000
#define CY_CRYPTO_PR_LFSR_CTL1_DEFAULT_VALUE     0x00000000
#define CY_CRYPTO_PR_LFSR_CTL2_DEFAULT_VALUE     0x00000000
#define CY_CRYPTO_TR_CTL0_DEFAULT_VALUE          0x00030000
#define CY_CRYPTO_TR_CTL1_DEFAULT_VALUE          0x00000020
#define CY_CRYPTO_TR_GARO_CTL_DEFAULT_VALUE      0x00000000
#define CY_CRYPTO_TR_FIRO_CTL_DEFAULT_VALUE      0x00000000
#define CY_CRYPTO_TR_MON_CTL_DEFAULT_VALUE       0x00000002
#define CY_CRYPTO_TR_MON_RC_CTL_DEFAULT_VALUE    0x000000FF
#define CY_CRYPTO_TR_MON_AP_CTL_DEFAULT_VALUE    0xFFFFFFFFu
#define CY_CRYPTO_SHA_CTL_DEFAULT_VALUE          0x00000000
#define CY_CRYPTO_CRC_DATA_CTL0_DEFAULT_VALUE    0x00000000
#define CY_CRYPTO_CRC_DATA_CTL1_DEFAULT_VALUE    0x00000000
#define CY_CRYPTO_CRC_POL_CTL_DEFAULT_VALUE      0x00000000
#define CY_CRYPTO_CRC_LFSR_CTL_DEFAULT_VALUE     0x00000000
#define CY_CRYPTO_CRC_REM_CTL0_DEFAULT_VALUE     0x00000000
#define CY_CRYPTO_CRC_REM_CTL1_DEFAULT_VALUE     0x00000000
#define CY_CRYPTO_INTR_MASK_DEFAULT_VALUE        0x00000000

/*******************************************************************************
* Function Name: Cy_Crypto_ClearState
****************************************************************************//**
*
* This function clears the current state of the Crypto block. All the Crypto
* block registers are set to their default (Reset) values and the memory buffer
* is initialized with zeros.
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_ClearState(CRYPTO_Type *base)
{
    if (NULL == base)
    {
        return (CY_CRYPTO_BAD_PARAMS);
    }

    /*
     * Writing default value to CTL register disables the crypto hardware and
     * all non-retained registers are set to their default values.
     */
    REG_CRYPTO_CTL(base) = CY_CRYPTO_CTL_DEFAULT_VALUE;

    /*
     * Set the default values of all retained registers.
     */
    REG_CRYPTO_SRC_CTL0(base) = CY_CRYPTO_SRC_CTL0_DEFAULT_VALUE;
    REG_CRYPTO_SRC_CTL1(base) = CY_CRYPTO_SRC_CTL1_DEFAULT_VALUE;
    REG_CRYPTO_DST_CTL0(base) = CY_CRYPTO_DST_CTL0_DEFAULT_VALUE;
    REG_CRYPTO_DST_CTL1(base) = CY_CRYPTO_DST_CTL1_DEFAULT_VALUE;
    REG_CRYPTO_AES_CTL(base) = CY_CRYPTO_AES_CTL_DEFAULT_VALUE;
    REG_CRYPTO_PR_CTL(base) = CY_CRYPTO_PR_CTL_DEFAULT_VALUE;
    REG_CRYPTO_PR_LFSR_CTL0(base) = CY_CRYPTO_PR_LFSR_CTL0_DEFAULT_VALUE;
    REG_CRYPTO_PR_LFSR_CTL1(base) = CY_CRYPTO_PR_LFSR_CTL1_DEFAULT_VALUE;
    REG_CRYPTO_PR_LFSR_CTL2(base) = CY_CRYPTO_PR_LFSR_CTL2_DEFAULT_VALUE;
    REG_CRYPTO_TR_CTL0(base) = CY_CRYPTO_TR_CTL0_DEFAULT_VALUE;
    REG_CRYPTO_TR_CTL1(base) = CY_CRYPTO_TR_CTL1_DEFAULT_VALUE;
    REG_CRYPTO_TR_GARO_CTL(base) = CY_CRYPTO_TR_GARO_CTL_DEFAULT_VALUE;
    REG_CRYPTO_TR_FIRO_CTL(base) = CY_CRYPTO_TR_FIRO_CTL_DEFAULT_VALUE;
    REG_CRYPTO_TR_MON_CTL(base) = CY_CRYPTO_TR_MON_CTL_DEFAULT_VALUE;
    REG_CRYPTO_TR_MON_RC_CTL(base) = CY_CRYPTO_TR_MON_RC_CTL_DEFAULT_VALUE;
    REG_CRYPTO_TR_MON_AP_CTL(base) = CY_CRYPTO_TR_MON_AP_CTL_DEFAULT_VALUE;
    REG_CRYPTO_SHA_CTL(base) = CY_CRYPTO_SHA_CTL_DEFAULT_VALUE;
    REG_CRYPTO_CRC_DATA_CTL0(base) = CY_CRYPTO_CRC_DATA_CTL0_DEFAULT_VALUE;
    REG_CRYPTO_CRC_DATA_CTL1(base) = CY_CRYPTO_CRC_DATA_CTL1_DEFAULT_VALUE;
    REG_CRYPTO_CRC_POL_CTL(base) = CY_CRYPTO_CRC_POL_CTL_DEFAULT_VALUE;
    REG_CRYPTO_CRC_LFSR_CTL(base) = CY_CRYPTO_CRC_LFSR_CTL_DEFAULT_VALUE;
    REG_CRYPTO_CRC_REM_CTL0(base) = CY_CRYPTO_CRC_REM_CTL0_DEFAULT_VALUE;
    REG_CRYPTO_CRC_REM_CTL1(base) = CY_CRYPTO_CRC_REM_CTL1_DEFAULT_VALUE;
    REG_CRYPTO_INTR_MASK(base) = CY_CRYPTO_INTR_MASK_DEFAULT_VALUE;

    /*
     * Set the memory buffer to zeros
     */
    (void) memset( (char *)REG_CRYPTO_MEM_BUFF(base), 0x00, sizeof(REG_CRYPTO_MEM_BUFF(base)) );

    return (CY_CRYPTO_SUCCESS);
}

#if defined(__cplusplus)
}
#endif

#endif /* CY_IP_MXCRYPTO */

/* [] END OF FILE */
