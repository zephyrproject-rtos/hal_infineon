/***************************************************************************//**
* \file cy_crypto_core_hkdf_v2.h
* \version 2.150
*
* \brief
*  This file provides constants and function prototypes
*  for the API for the HKDF method in the Crypto block driver.
*
********************************************************************************
* \copyright
* Copyright (c) (2020-2024), Cypress Semiconductor Corporation (an Infineon company) or
* an affiliate of Cypress Semiconductor Corporation.
* SPDX-License-Identifier: Apache-2.0
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*    http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/


#if !defined (CY_CRYPTO_CORE_HKDF_V2_H)
#define CY_CRYPTO_CORE_HKDF_V2_H

#include "cy_crypto_common.h"

#if defined(CY_IP_MXCRYPTO) && defined(CY_CRYPTO_CFG_HW_V2_ENABLE)

#if defined(__cplusplus)
extern "C" {
#endif

#if (CPUSS_CRYPTO_SHA == 1) && defined(CY_CRYPTO_CFG_HKDF_C)

#include "cy_crypto_core_hmac_v2.h"


cy_en_crypto_status_t Cy_Crypto_Core_V2_Hkdf_Extract(CRYPTO_Type *base, cy_en_crypto_sha_mode_t mode,
                                          uint8_t  const *salt,
                                          uint32_t saltLength,
                                          uint8_t  const *ikm,
                                          uint32_t ikmLength,
                                          uint8_t *prk);

cy_en_crypto_status_t Cy_Crypto_Core_V2_Hkdf_Expand(CRYPTO_Type *base, cy_en_crypto_sha_mode_t mode,
                                          uint8_t  const *prk,
                                          uint32_t prkLength,
                                          uint8_t  const *info,
                                          uint32_t infoLength,
                                          uint8_t *okm,
                                          uint32_t okmLength);

cy_en_crypto_status_t Cy_Crypto_Core_V2_Hkdf(CRYPTO_Type *base, cy_en_crypto_sha_mode_t mode,
                                          uint8_t  const *salt,
                                          uint32_t saltLength,
                                          uint8_t  const *ikm,
                                          uint32_t ikmLength,
                                          uint8_t  const *info,
                                          uint32_t infoLength,
                                          uint8_t *okm,
                                          uint32_t okmLength);

#endif /* (CPUSS_CRYPTO_SHA == 1) && defined(CY_CRYPTO_CFG_HKDF_C) */

#if defined(__cplusplus)
}
#endif

#endif /* defined(CY_IP_MXCRYPTO) && defined(CY_CRYPTO_CFG_HW_V2_ENABLE) */

#endif /* #if !defined (CY_CRYPTO_CORE_HKDF_V2_H) */


/* [] END OF FILE */
