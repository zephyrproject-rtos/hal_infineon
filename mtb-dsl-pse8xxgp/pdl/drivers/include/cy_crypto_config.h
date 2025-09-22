/***************************************************************************//**
* \file cy_crypto_config.h
* \version 2.150
*
* \brief
*  This file provides default configuration parameters
*  for the Crypto driver.
*
********************************************************************************
* Copyright 2016-2024 Cypress Semiconductor Corporation
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


#if !defined(CY_CRYPTO_CONFIG_H)
#define CY_CRYPTO_CONFIG_H

#include "cy_device.h"
#include "cy_device_headers.h"

#if defined (CY_IP_MXCRYPTO)

#include "cy_syslib.h"

CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 20.5', 2, \
'Since hardware configurations are decided by CRYPTO hardware IP version, use of #undef will not make it ambiguous that which macros exist at a particular point within a translation unit.')

/* v1 and v2 IP feature defines flags are defined slightly different
   adjust the definitions*/

/* Enable SHA functionality */
#if !defined(CPUSS_CRYPTO_SHA)
#if ( CPUSS_CRYPTO_SHA1 == 1u || CPUSS_CRYPTO_SHA2 == 1u || CPUSS_CRYPTO_SHA3 == 1u )
    #define CPUSS_CRYPTO_SHA                (1u)

    #if (CPUSS_CRYPTO_SHA2 == 1u) && !defined(CPUSS_CRYPTO_SHA256)
    #define CPUSS_CRYPTO_SHA256             (1u)
    #endif

    #if (CPUSS_CRYPTO_SHA2 == 1u) && !defined(CPUSS_CRYPTO_SHA512)
    #define CPUSS_CRYPTO_SHA512             (1u)
    #endif
#endif
#endif /* !defined(CPUSS_CRYPTO_SHA) */

#if !defined(CPUSS_CRYPTO_STR)
    #define CPUSS_CRYPTO_STR                (1u)
#endif

#if (CY_IP_MXCRYPTO_VERSION == 1u)
#if (CPUSS_CRYPTO_SHA256 == 1u || CPUSS_CRYPTO_SHA512 == 1u)
#define CPUSS_CRYPTO_SHA2   (1u)
#else
#define CPUSS_CRYPTO_SHA2   (0u)
#endif
#endif

#if !defined(CPUSS_CRYPTO_CHACHA) && (CY_IP_MXCRYPTO_VERSION == 1u)
#define CPUSS_CRYPTO_CHACHA (0u)
#endif

#if !defined(CPUSS_CRYPTO_GCM) && (CY_IP_MXCRYPTO_VERSION == 1u)
#define CPUSS_CRYPTO_GCM (0u)
#endif

#if !defined(CPUSS_CRYPTO_SHA3) && (CY_IP_MXCRYPTO_VERSION == 1u)
#define CPUSS_CRYPTO_SHA3 (0u)
#endif

/* Include user defined Crypto config header. By default all device supported features enabled*/
#if defined(CY_CRYPTO_USER_CONFIG_FILE)
#include CY_CRYPTO_USER_CONFIG_FILE
#else

/*
 * Use hardware specific model instead of PDL device agnostic model.
 *   Disabled by default.
 */
#define CY_CRYPTO_CFG_HW_USE_MPN_SPECIFIC

/* CRYPTO hardware version 1 support */
#define CY_CRYPTO_CFG_HW_V1_ENABLE

/* CRYPTO hardware version 2 support */
#define CY_CRYPTO_CFG_HW_V2_ENABLE

/* Default configuration:
 *
 * - SHA1
 * - SHA256
 * - SHA512
 * - HMAC
 * - AES ECB
 * - AES CBC
 * - AES CFB
 * - AES CTR
 * - CMAC
 * - CRC
 * - PRNG
 * - TRNG
 * - DES/TDES
 * - RSA encrypt/decrypt
 * - RSA PKCS#1.l5 verification
 * - ECP multiplication
 * - ECDSA key generation
 * - ECDSA sign
 * - ECDSA verification
 */
#if (CPUSS_CRYPTO_CRC == 1u)
#define CY_CRYPTO_CFG_CRC_C
#endif /* defined(CPUSS_CRYPTO_CRC == 1u) */

#if (CPUSS_CRYPTO_DES == 1u)
#define CY_CRYPTO_CFG_DES_C
#endif /* defined(CPUSS_CRYPTO_DES == 1u) */

#if (CPUSS_CRYPTO_PR == 1u)
#define CY_CRYPTO_CFG_PRNG_C
#endif /* defined(CPUSS_CRYPTO_PR == 1u) */

#if (CPUSS_CRYPTO_TR == 1u)
#define CY_CRYPTO_CFG_TRNG_C
#endif /* defined(CPUSS_CRYPTO_TR == 1u) */

/* Currently this driver supports CBC, CFB, CTR cipher modes */
#if (CPUSS_CRYPTO_AES == 1u)
#define CY_CRYPTO_CFG_AES_C
#define CY_CRYPTO_CFG_CMAC_C

#if (CPUSS_CRYPTO_GCM == 1u)
#define CY_CRYPTO_CFG_GCM_C
#endif /* defined(CPUSS_CRYPTO_AES_ECB == 1u) */

#define CY_CRYPTO_CFG_CCM_C
#define CY_CRYPTO_CFG_CBC_MAC_C
/* AES Cipher modes */
#define CY_CRYPTO_CFG_CIPHER_MODE_CBC
#define CY_CRYPTO_CFG_CIPHER_MODE_CFB
#define CY_CRYPTO_CFG_CIPHER_MODE_CTR
/* Currently OFB, XTS cipher modes are not implemented */
// #define CY_CRYPTO_CFG_CIPHER_MODE_OFB
// #define CY_CRYPTO_CFG_CIPHER_MODE_XTS
#endif /* defined(CPUSS_CRYPTO_AES == 1u) */

#if ((CPUSS_CRYPTO_SHA1 == 1u) || (CPUSS_CRYPTO_SHA2 == 1u) || (CPUSS_CRYPTO_SHA3 == 1u))
#define CY_CRYPTO_CFG_SHA_C
#define CY_CRYPTO_CFG_HMAC_C
#define CY_CRYPTO_CFG_HKDF_C

#if (CPUSS_CRYPTO_SHA1 == 1u)
#define CY_CRYPTO_CFG_SHA1_ENABLED
#endif /* defined(CPUSS_CRYPTO_SHA1 == 1u) */
#if (CPUSS_CRYPTO_SHA2 == 1u || CPUSS_CRYPTO_SHA256 == 1u || CPUSS_CRYPTO_SHA512 == 1u)
#define CY_CRYPTO_CFG_SHA2_256_ENABLED
#define CY_CRYPTO_CFG_SHA2_512_ENABLED
#endif /* defined(CPUSS_CRYPTO_SHA2 == 1u) */
#if (CPUSS_CRYPTO_SHA3 == 1u)
#define CY_CRYPTO_CFG_SHA3_ENABLED
#endif /* defined(CPUSS_CRYPTO_SHA3 == 1u) */

#endif /* defined(CPUSS_CRYPTO_SHA1 == 1u) || defined(CPUSS_CRYPTO_SHA2 == 1u) || defined(CPUSS_CRYPTO_SHA3 == 1u) */


#if (CPUSS_CRYPTO_VU == 1u)
/* RSA functionality */
#define CY_CRYPTO_CFG_RSA_C
/* RSA PKCS 1.5 verification */
#define CY_CRYPTO_CFG_RSA_VERIFY_ENABLED

/* RSA PKCS 1.5 signing */
#define CY_CRYPTO_CFG_RSA_SIGN_ENABLED

/* Only NIST-P curves are currently supported */
#define CY_CRYPTO_CFG_ECP_C

#define CY_CRYPTO_CFG_ECP_DP_SECP192R1_ENABLED
#define CY_CRYPTO_CFG_ECP_DP_SECP224R1_ENABLED
#define CY_CRYPTO_CFG_ECP_DP_SECP256R1_ENABLED
#define CY_CRYPTO_CFG_ECP_DP_SECP384R1_ENABLED
#define CY_CRYPTO_CFG_ECP_DP_SECP521R1_ENABLED
#define CY_CRYPTO_CFG_ECP_DP_ED25519_ENABLED
#define CY_CRYPTO_CFG_ECP_DP_EC25519_ENABLED

/* ECDSA functionality */
#define CY_CRYPTO_CFG_ECDSA_C
/* ECDSA key generation */
#define CY_CRYPTO_CFG_ECDSA_GENKEY_C
/* ECDSA sign */
#define CY_CRYPTO_CFG_ECDSA_SIGN_C
/* ECDSA verification */
#define CY_CRYPTO_CFG_ECDSA_VERIFY_C
/* EC25519 functionality */
#define CY_CRYPTO_CFG_EC25519_C
/* EC25519 key generation */
#define CY_CRYPTO_CFG_EC25519_GENKEY_C

/* EDDSA functionality */
#define CY_CRYPTO_CFG_EDDSA_C
/* EDDSA sign */
#define CY_CRYPTO_CFG_EDDSA_SIGN_C
/* EDDSA verify */
#define CY_CRYPTO_CFG_EDDSA_VERIFY_C
/* EDDSA key generation */
#define CY_CRYPTO_CFG_EDDSA_GENKEY_C
#endif /* (CPUSS_CRYPTO_VU == 1u) */

/* External memory use */
//#define CY_CRYPTO_CFG_EXTERNAL_MEMORY_ENABLE

#if (CY_IP_MXCRYPTO_VERSION == 2u)
#if (CPUSS_CRYPTO_CHACHA == 1u || CRYPTO_CHACHA == 1u)
/* Disabled chacha20 functionality */
//#define CY_CRYPTO_CFG_CHACHA_ENABLED
#endif /* (CPUSS_CRYPTO_CHACHA == 1u || CRYPTO_CHACHA == 1u) */
/* Disabled poly1305 functionality */
//#define CY_CRYPTO_CFG_POLY1305_ENABLED
#endif

#endif

/* Check hardware configuration */
#if defined(CY_CRYPTO_CFG_HW_USE_MPN_SPECIFIC)
     #undef CY_CRYPTO_CFG_HW_V1_ENABLE
     #undef CY_CRYPTO_CFG_HW_V2_ENABLE

     #if (CY_IP_MXCRYPTO_VERSION == 1u)
     /* CRYPTO hardware version 1 support */
     #define CY_CRYPTO_CFG_HW_V1_ENABLE
     #endif

     #if (CY_IP_MXCRYPTO_VERSION == 2u)
     /* CRYPTO hardware version 2 support */
     #define CY_CRYPTO_CFG_HW_V2_ENABLE
     #endif
#else
     #if !defined(CY_CRYPTO_CFG_HW_V1_ENABLE) && !defined(CY_CRYPTO_CFG_HW_V2_ENABLE)
     #error "Select proper hardware configuration (CY_CRYPTO_CFG_HW_V1_ENABLE or CY_CRYPTO_CFG_HW_V2_ENABLE)"
     #endif /* !defined(CY_CRYPTO_CFG_HW_V1_ENABLE) && !defined(CY_CRYPTO_CFG_HW_V2_ENABLE) */

#endif

/* Check AES configuration */
#if (defined(CY_CRYPTO_CFG_CIPHER_MODE_CBC) || \
     defined(CY_CRYPTO_CFG_CIPHER_MODE_CFB) || \
     defined(CY_CRYPTO_CFG_CIPHER_MODE_CTR)) \
     && !defined(CY_CRYPTO_CFG_AES_C)
#error "CY_CRYPTO_CFG_AES_C is not defined to use any AES ciphers"
#endif

/* Check CMAC configuration */
#if defined(CY_CRYPTO_CFG_CMAC_C) && !defined(CY_CRYPTO_CFG_AES_C)
#error "CY_CRYPTO_CFG_AES_C is not defined to use CMAC calculation"
#endif /* defined(CY_CRYPTO_CFG_CMAC_C) && !defined(CY_CRYPTO_CFG_AES_C) */

/* Check CBC-MAC configuration */
#if defined(CY_CRYPTO_CFG_CBC_MAC_C) && !defined(CY_CRYPTO_CFG_CIPHER_MODE_CBC)
#error "CY_CRYPTO_CFG_CIPHER_MODE_CBC is not defined to use CBC-MAC calculation"
#endif /* defined(CY_CRYPTO_CFG_CBC_MAC_C) && !defined(CY_CRYPTO_CFG_CIPHER_MODE_CBC) */

/* Check GCM configuration */
#if defined(CY_CRYPTO_CFG_GCM_C) && !defined(CY_CRYPTO_CFG_AES_C)
#error "CY_CRYPTO_CFG_AES_C is not defined to use GCM calculation"
#endif /* defined(CY_CRYPTO_CFG_GCM_C) && !defined(CY_CRYPTO_CFG_AES_C) */

/* Check SHA configuration */
#if (defined(CY_CRYPTO_CFG_SHA1_ENABLED) || \
     defined(CY_CRYPTO_CFG_SHA2_256_ENABLED) || \
     defined(CY_CRYPTO_CFG_SHA2_512_ENABLED) || \
     defined(CY_CRYPTO_CFG_SHA3_ENABLED)) \
     && !defined(CY_CRYPTO_CFG_SHA_C)
#error "CY_CRYPTO_CFG_SHA_C is not defined to use SHA digests"
#endif

#if defined(CY_CRYPTO_CFG_SHA_C) && (!defined(CY_CRYPTO_CFG_SHA1_ENABLED) && \
     !defined(CY_CRYPTO_CFG_SHA2_256_ENABLED) && !defined(CY_CRYPTO_CFG_SHA3_ENABLED)  &&\
     !defined(CY_CRYPTO_CFG_SHA2_512_ENABLED))
#error "CY_CRYPTO_CFG_SHA_C is defined but no SHA mode is selected"
#endif


/* Check HMAC configuration */
#if defined(CY_CRYPTO_CFG_HMAC_C) && !defined(CY_CRYPTO_CFG_SHA_C)
#error "CY_CRYPTO_CFG_SHA_C is not defined to use HMAC calculation"
#endif /* defined(CY_CRYPTO_CFG_HMAC_C) && !defined(CY_CRYPTO_CFG_SHA_C) */

/* Check HKDF configuration */
#if defined(CY_CRYPTO_CFG_HKDF_C) && (!defined(CY_CRYPTO_CFG_HMAC_C) || !defined(CY_CRYPTO_CFG_SHA_C))
#error "CY_CRYPTO_CFG_HMAC_C & CY_CRYPTO_CFG_SHA_C is not defined to use HKDF calculation"
#endif /* defined(CY_CRYPTO_CFG_HKDF_C) && (!defined(CY_CRYPTO_CFG_HMAC_C) || !defined(CY_CRYPTO_CFG_SHA_C)) */

/* Check RSA verify configuration */
#if defined(CY_CRYPTO_CFG_RSA_VERIFY_ENABLED) && !defined(CY_CRYPTO_CFG_RSA_C)
#error "CY_CRYPTO_CFG_RSA_C is not defined to use RSA verification functionality"
#endif

#if defined(CY_CRYPTO_CFG_RSA_VERIFY_ENABLED) && !defined(CY_CRYPTO_CFG_SHA_C)
#error "CY_CRYPTO_CFG_SHA_C is not defined to use RSA verification functionality"
#endif

/* Check ECDSA configuration */
#if (defined(CY_CRYPTO_CFG_ECDSA_GENKEY_C) || defined(CY_CRYPTO_CFG_ECDSA_SIGN_C) || \
     defined(CY_CRYPTO_CFG_ECDSA_VERIFY_C)) && !defined(CY_CRYPTO_CFG_ECDSA_C)
#error "CY_CRYPTO_CFG_ECDSA_C is not defined to use ECDSA functionalities"
#endif

#if !(defined(CY_CRYPTO_CFG_ECDSA_GENKEY_C) || defined(CY_CRYPTO_CFG_ECDSA_SIGN_C) || \
     defined(CY_CRYPTO_CFG_ECDSA_VERIFY_C)) && defined(CY_CRYPTO_CFG_ECDSA_C)
#error "CY_CRYPTO_CFG_ECDSA_C is defined but no ECDSA functionality is selected"
#endif

#if defined(CY_CRYPTO_CFG_ECDSA_C) && !defined(CY_CRYPTO_CFG_ECP_C)
#define CY_CRYPTO_CFG_ECP_C
#endif /* defined(CY_CRYPTO_CFG_ECDSA_C) && !defined(CY_CRYPTO_CFG_ECP_C) */

/* Check ECP configuration */
#if !(defined(CY_CRYPTO_CFG_ECP_DP_SECP192R1_ENABLED) || \
     defined(CY_CRYPTO_CFG_ECP_DP_SECP224R1_ENABLED) || \
     defined(CY_CRYPTO_CFG_ECP_DP_SECP256R1_ENABLED) || \
     defined(CY_CRYPTO_CFG_ECP_DP_SECP384R1_ENABLED) || \
     defined(CY_CRYPTO_CFG_ECP_DP_SECP521R1_ENABLED)) \
     && defined(CY_CRYPTO_CFG_ECP_C)
#error "CY_CRYPTO_CFG_ECP_C is defined but no curve is selected"
#endif

#if (defined(CY_CRYPTO_CFG_ECP_DP_SECP192R1_ENABLED) || \
     defined(CY_CRYPTO_CFG_ECP_DP_SECP224R1_ENABLED) || \
     defined(CY_CRYPTO_CFG_ECP_DP_SECP256R1_ENABLED) || \
     defined(CY_CRYPTO_CFG_ECP_DP_SECP384R1_ENABLED) || \
     defined(CY_CRYPTO_CFG_ECP_DP_SECP521R1_ENABLED)) \
     && !defined(CY_CRYPTO_CFG_ECP_C)
#error "CY_CRYPTO_CFG_ECP_C is not defined to use ECP functionality"
#endif

#if !(defined(CY_CRYPTO_CFG_ECP_DP_ED25519_ENABLED)) \
     && defined(CY_CRYPTO_CFG_EDDSA_C)
#error "CY_CRYPTO_CFG_EDDSA_C is defined but no curve is selected"
#endif

#if (defined(CY_CRYPTO_CFG_ECP_DP_ED25519_ENABLED)) \
     && !defined(CY_CRYPTO_CFG_EDDSA_C)
#error "CY_CRYPTO_CFG_EDDSA_C is not defined to use EDDSA functionality"
#endif

#if !(defined(CY_CRYPTO_CFG_ECP_DP_EC25519_ENABLED)) \
     && defined(CY_CRYPTO_CFG_EC25519_C)
#error "CY_CRYPTO_CFG_EC25519_C is defined but no curve is selected"
#endif

#if (defined(CY_CRYPTO_CFG_ECP_DP_EC25519_ENABLED)) \
     && !defined(CY_CRYPTO_CFG_EC25519_C)
#error "CY_CRYPTO_CFG_EC25519_C is not defined to use EC25519 functionality"
#endif

#if (defined(CY_CRYPTO_CFG_EC25519_GENKEY_C)) \
     && !defined(CY_CRYPTO_CFG_EC25519_C)
#error "CY_CRYPTO_CFG_EC25519_C is not defined to use EC25519 functionality"
#endif

#if defined(CY_CRYPTO_CFG_CHACHA_ENABLED) && defined(CY_CRYPTO_CFG_HW_V1_ENABLE)
#error "CHACHA functionality is not available in HW_V1"
#endif

CY_MISRA_BLOCK_END('MISRA C-2012 Rule 20.5')

#endif /* CY_IP_MXCRYPTO */

#endif /* #if !defined(CY_CRYPTO_CONFIG_H) */

/* [] END OF FILE */
