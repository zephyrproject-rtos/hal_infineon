# SE RT Services Utilities Library - Secure Syscall and PSA Crypto Wrappers

## Overview
SE RT Services Utilities Library provides utility APIs to access SE RT Services syscalls, including PSA cryptographic operations, rollback management, and generic platform syscalls.

The library wraps SE-side functionality behind application-friendly APIs and follows Mbed TLS PSA definitions while exposing SE RT Services-specific constraints and capabilities.

## Features
- PSA Crypto API wrapper functions aligned with PSA Crypto API v1.1 and Mbed TLS interfaces.
- Generic platform/syscall wrappers for power, rollback, attestation, and MPC-related services.
- Key lifecycle support including generation, import, verification, destruction, and usage-limit handling.
- Documented supported algorithms, memory region constraints, key storage capacities, and benchmark data.
- Doxygen API documentation for platform, syscall, FIH, and PSA crypto groups.

## When to Use
Use this library when your application needs to:
- Call secure cryptographic services from the SE RT Services layer.
- Use secure key storage and key usage-limit tracking.
- Invoke platform-level secure services (power, rollback, attestation, MPC).
- Process crypto data under SE RT Services memory-region constraints.

## Prerequisites
### Hardware Requirements
- Hardware requirements depend on the selected target and platform integration.

### Software Requirements
- ModusToolbox environment with this middleware library added.
- PSA Crypto API v1.3 understanding for cryptographic workflows.
- Mbed TLS PSA compatibility awareness (SE RT Services aligns with Mbed TLS PSA interface usage).

### Read Documentation First
- [SE RT Services Utilities API documentation](https://infineon.github.io/se-rt-services-utils/html/index.html)
- [PSA crypto API (library group)](https://infineon.github.io/se-rt-services-utils/html/group__psacrypto.html)
- [FIH library API](https://infineon.github.io/se-rt-services-utils/html/group__fih.html)
- [Generic Syscall API](https://infineon.github.io/se-rt-services-utils/html/group__platform.html)
- [Low-level Syscall API](https://infineon.github.io/se-rt-services-utils/html/group__syscalls.html)
- [PSA Crypto API Reference Guide](https://arm-software.github.io/psa-api/crypto/1.1/index.html)
- [Mbed TLS PSA Cryptography API reference tree](https://github.com/Mbed-TLS/mbedtls/tree/v3.2.1#psa-cryptography-api)

### Choose Starting Template
- Start from an Empty application template and add this middleware library.

### Add Required Libraries
Add this library to your project by one of the following:
- Add a dependency file (MTB format) into the `deps` folder.
- Use Library Manager: Libraries -> Middleware -> se-rt-services-utils.

### Configure in the Tool (PPC Configuration)
The following PPC regions must be configured to Secure mode (S mode) by the secure application context so SE RT Services can access them:
- PROT_PERI0_RAMC0_MPC0_PPC_MPC_MAIN
- PROT_PERI0_RAMC0_MPC0_PPC_MPC_PC
- PROT_PERI0_RAMC0_MPC0_PPC_MPC_ROT
- PROT_PERI0_CPUSS_ALL_PC
- PROT_PERI0_IPC0_STRUCT0_IPC
- PROT_PERI0_IPC0_INTR_STRUCT0_INTR
- PROT_PERI0_SRSS_MAIN

Use Device Configurator to set these regions.
Reference: [Secure Code Example](https://github.com/Infineon/mtb-example-psoc-edge-secure-power-management/blob/master/docs/design_and_implementation.md)

### Add Headers
Typical headers used by applications:
- `ifx_se_psacrypto.h`
- `ifx_se_platform.h`
- `ifx_se_syscall.h`

## Quick Start
This quick start demonstrates common secure-crypto use cases: hashing, signature verification, symmetric encryption/decryption, and ECC signing/verification.

**Step 1:** Add the middleware library to your project.

**Step 2:** Configure PPC regions listed in Prerequisites.

**Step 3:** Include required SE RT Services headers and enable interrupts as needed.

**Step 4:** Add one of the sample flows below into your application code.

### Sample Code
#### Hash input data using SHA-256
```c
#include "ifx_se_psacrypto.h"
#include "ifx_se_platform.h"

int main(void)
{
        /* All data arrays should be 4-byte aligned for a better performance */

        /* Input data */
    CY_ALIGN(4) const uint8_t text[10] = "1234";

    /* Calculated SHA-256 hash */
        CY_ALIGN(4) uint8_t hash[IFX_SE_HASH_LENGTH(IFX_SE_ALG_SHA_256)] = {0};
        size_t hash_lenght;
        ifx_se_hash_operation_t psaOp = IFX_SE_HASH_OPERATION_INIT;
        ifx_se_status_t status;

        __enable_irq();

        /* Hash the message by SHA256 */
        status = ifx_se_hash_setup (&psaOp, ifx_se_fih_uint_encode(IFX_SE_ALG_SHA_256), IFX_SE_NULL_CTX);

        /* ... check for errors... */
        /* Use CY_REMAP_ADDRESS_CBUS_TO_SAHB macro to remap address if the input data are located in external flash */
        status = ifx_se_hash_update (&psaOp,
                                     ifx_se_fih_ptr_encode(CY_REMAP_ADDRESS_CBUS_TO_SAHB(text)),
                                     ifx_se_fih_uint_encode(sizeof(text)),
                                     IFX_SE_NULL_CTX);

        /* ... check for errors... */
        status = ifx_se_hash_finish (&psaOp,
                                     ifx_se_fih_ptr_encode(hash),
                                     ifx_se_fih_uint_encode(sizeof(hash)),
                                     ifx_se_fih_ptr_encode(&hash_lenght),
                                     IFX_SE_NULL_CTX);

        /* ... check for errors... */

    for (;;)
    {
    }
}
```

#### Verify signature based on NIST test vector
```c
{
    /* SigVer.rsp [P-384,SHA-256] csrc.nist.gov/CSRC/media/Projects/Cryptographic-Algorithm-Validation-Program/documents/dss/186-4ecdsatestvectors.zip */
    /* Input message from the NIST test vector */
    CY_ALIGN(4) uint8_t message[] =
    {
        0x86,0x2c,0xf1,0x4c,0x65,0xff,0x85,0xf4,0xfd,0xd8,0xa3,0x93,0x02,0x05,0x63,0x55,
        0xc8,0x9c,0x6e,0xa1,0x78,0x9c,0x05,0x62,0x62,0xb0,0x77,0xda,0xb3,0x3a,0xbb,0xfd,
        0xa0,0x07,0x0f,0xce,0x18,0x8c,0x63,0x30,0xde,0x84,0xdf,0xc5,0x12,0x74,0x4e,0x9f,
        0xa0,0xf7,0xb0,0x3c,0xe0,0xc1,0x48,0x58,0xdb,0x19,0x52,0x75,0x0d,0x7b,0xbe,0x6b,
        0xd9,0xc8,0x72,0x6c,0x0e,0xae,0x61,0xe6,0xcf,0x28,0x77,0xc6,0x55,0xb1,0xf0,0xe0,
        0xce,0x82,0x54,0x30,0xa9,0x79,0x6e,0x74,0x20,0xe5,0xc1,0x74,0xea,0xb7,0xa5,0x04,
        0x59,0xe2,0x91,0x51,0x0b,0xc5,0x15,0x14,0x17,0x38,0x90,0x0d,0x39,0x02,0x17,0xc5,
        0xa5,0x22,0xe4,0xbd,0xe5,0x47,0xe5,0x72,0x87,0xd8,0x13,0x9d,0xc9,0x16,0x50,0x4e
    };
    /* Signature from the NIST test vector */
    CY_ALIGN(4) uint8_t signature[] =
    {
        0x79,0x80,0x65,0xf1,0xd1,0xcb,0xd3,0xa1,0x89,0x77,0x94,0xf4,0xa0,0x25,0xed,0x47,
        0x56,0x5d,0xf7,0x73,0x84,0x3f,0x4f,0xa7,0x4c,0x85,0xfe,0x4d,0x30,0xe3,0xa3,0x94,
        0x78,0x3e,0xc5,0x72,0x3b,0x53,0x0f,0xc5,0xf5,0x79,0x06,0xf9,0x46,0xce,0x15,0xe8,
        0xb5,0x71,0x66,0x04,0x4c,0x57,0xc7,0xd9,0x58,0x20,0x66,0x80,0x5b,0x58,0x85,0xab,
        0xc0,0x6e,0x0b,0xfc,0x02,0x43,0x38,0x50,0xc2,0xb7,0x49,0x73,0x20,0x5c,0xa3,0x57,
        0xa2,0xda,0x94,0xa6,0x51,0x72,0x08,0x6f,0x5a,0x15,0x80,0xba,0xa6,0x97,0x40,0x0b
    };
    /* The public key from the NIST test vector is embedded in to SE_RT_SERVICES
       Qx = 86ac12dd0a7fe5b81fdae86b12435d316ef9392a3f50b307ab65d9c6079dd0d2d819dc09e22861459c2ed99fbab66fae
       Qy = ac8444077aaed6d6ccacbe67a4caacee0b5a094a3575ca12ea4b4774c030fe1c870c9249023f5dc4d9ad6e333668cc38
       S = b57166044c57c7d9582066805b5885abc06e0bfc02433850c2b74973205ca357a2da94a65172086f5a1580baa697400b
    */
    ifx_se_key_id_fih_t oem_custom_key = IFX_SE_KEY_ID_FIH_INIT_VALUE(0, IFX_SE_KEY_ID_BUILTIN_TEST_ECC384);

    status = ifx_se_verify_message(oem_custom_key,
                                   ifx_se_fih_uint_encode(IFX_SE_ALG_ECDSA(IFX_SE_ALG_SHA_256)),
                                   ifx_se_fih_ptr_encode(message),
                                   ifx_se_fih_uint_encode(sizeof(message)),
                                   ifx_se_fih_ptr_encode(signature),
                                   ifx_se_fih_uint_encode(sizeof(signature)),
                                   IFX_SE_NULL_CTX);
    /* ... check for errors... */
}
```

#### Generate random AES key, encrypt, decrypt, and destroy
```c
{
    #define AES_KEY_SIZE        (16)
    ifx_se_key_attributes_t aesAttributes = IFX_SE_KEY_ATTRIBUTES_INIT;
    ifx_se_key_id_fih_t aesKeyId;

    /* Set AES key attributes */
    ifx_se_set_key_usage_flags(&aesAttributes, IFX_SE_KEY_USAGE_DECRYPT | IFX_SE_KEY_USAGE_ENCRYPT);
    ifx_se_set_key_algorithm(&aesAttributes, IFX_SE_ALG_CBC_NO_PADDING);
    ifx_se_set_key_type(&aesAttributes, IFX_SE_KEY_TYPE_AES);
    ifx_se_set_key_bits(&aesAttributes, IFX_SE_BYTES_TO_BITS(AES_KEY_SIZE));
    ifx_se_set_key_lifetime(&aesAttributes, IFX_SE_KEY_LIFETIME_FROM_PERSISTENCE_AND_LOCATION(
                            IFX_SE_KEY_PERSISTENCE_VOLATILE, IFX_SE_KEY_LOCATION_SE));
    /* Generate AES key */
    status = ifx_se_generate_key(&aesAttributes,
                                 ifx_se_fih_ptr_encode(&aesKeyId),
                                 IFX_SE_NULL_CTX);
    /* ... check for errors after each API call ... */
    {
        #define DATA_LEN            (16)
        /* Input data */
        CY_ALIGN(4) const uint8_t inData[DATA_LEN] = "1234567890";
        /* Encrypted data buffer contains Initialization vector followed by the cipher text */
        uint8_t iv_and_encryptedData[IFX_SE_CIPHER_ENCRYPT_OUTPUT_SIZE(IFX_SE_KEY_TYPE_AES, IFX_SE_ALG_CBC_NO_PADDING, DATA_LEN)] = {0};

        /* Decrypted data */
        uint8_t decryptedData[IFX_SE_CIPHER_DECRYPT_OUTPUT_SIZE(IFX_SE_KEY_TYPE_AES, IFX_SE_ALG_CBC_NO_PADDING, DATA_LEN)] = {0};
        size_t outSize = 0;

        /* Generate random IV */
        status = ifx_se_generate_random(ifx_se_fih_ptr_encode(iv_and_encryptedData),
                                        ifx_se_fih_uint_encode(IFX_SE_CIPHER_IV_MAX_SIZE),
                                        IFX_SE_NULL_CTX);

        /* Encrypt Data */
        status = ifx_se_cipher_encrypt(aesKeyId,
                                       ifx_se_fih_uint_encode(IFX_SE_ALG_CBC_NO_PADDING),
                                       ifx_se_fih_ptr_encode(iv_and_encryptedData),
                                       ifx_se_fih_uint_encode(IFX_SE_CIPHER_IV_MAX_SIZE),
                                       ifx_se_fih_ptr_encode(inData),
                                       ifx_se_fih_uint_encode(sizeof(inData)),
                                       ifx_se_fih_ptr_encode(iv_and_encryptedData + IFX_SE_CIPHER_IV_MAX_SIZE),
                                       ifx_se_fih_uint_encode(sizeof(iv_and_encryptedData) - IFX_SE_CIPHER_IV_MAX_SIZE),
                                       ifx_se_fih_ptr_encode(&outSize),
                                       IFX_SE_NULL_CTX);

        /* Decrypt Data */
        status = ifx_se_cipher_decrypt(aesKeyId,
                                       ifx_se_fih_uint_encode(IFX_SE_ALG_CBC_NO_PADDING),
                                       ifx_se_fih_ptr_encode(iv_and_encryptedData),
                                       ifx_se_fih_uint_encode(sizeof(iv_and_encryptedData)),
                                       ifx_se_fih_ptr_encode(decryptedData),
                                       ifx_se_fih_uint_encode(sizeof(decryptedData)),
                                       ifx_se_fih_ptr_encode(&outSize),
                                       IFX_SE_NULL_CTX);

        /* Destroy old AES key */
        status = ifx_se_destroy_key(aesKeyId, IFX_SE_NULL_CTX);
    }
}
```

#### Generate random ECC P-256 key, sign hash, and verify
```c
{
    #define ECP_CURVE_BITS                (256u)
    ifx_se_key_id_fih_t eccKeyId;
    ifx_se_key_attributes_t eccAttributes = IFX_SE_KEY_ATTRIBUTES_INIT;
    /* Pre-calculated SHA-256 hash */
    CY_ALIGN(4) uint8_t hash[IFX_SE_HASH_LENGTH(IFX_SE_ALG_SHA_256)] = {0, 1, 2, 3, 4, 5};
    CY_ALIGN(4) uint8_t signature[IFX_SE_ECDSA_SIGNATURE_SIZE(ECP_CURVE_BITS)] = {0};
    uint32_t signature_length;

    /* Set ECC key attributes */
    ifx_se_set_key_usage_flags(&eccAttributes, IFX_SE_KEY_USAGE_SIGN_HASH | IFX_SE_KEY_USAGE_VERIFY_HASH);
    ifx_se_set_key_algorithm(&eccAttributes, IFX_SE_ALG_ECDSA(IFX_SE_ALG_SHA_256));
    ifx_se_set_key_type(&eccAttributes, IFX_SE_KEY_TYPE_ECC_KEY_PAIR(IFX_SE_ECC_FAMILY_SECP_R1));
    ifx_se_set_key_bits(&eccAttributes, ECP_CURVE_BITS);
    ifx_se_set_key_lifetime(&eccAttributes, IFX_SE_KEY_LIFETIME_FROM_PERSISTENCE_AND_LOCATION(
                                            IFX_SE_KEY_PERSISTENCE_VOLATILE, IFX_SE_KEY_LOCATION_SE));

    /* Generate ECC key */
    status = ifx_se_generate_key(&eccAttributes,
                                 ifx_se_fih_ptr_encode(&eccKeyId),
                                 IFX_SE_NULL_CTX);
    /* Sign existing hash */
    status = ifx_se_sign_hash(eccKeyId,
                              ifx_se_fih_uint_encode(IFX_SE_ALG_ECDSA(IFX_SE_ALG_SHA_256)),
                              ifx_se_fih_ptr_encode(hash),
                              ifx_se_fih_uint_encode(sizeof(hash)),
                              ifx_se_fih_ptr_encode(signature),
                              ifx_se_fih_uint_encode(sizeof(signature)),
                              ifx_se_fih_ptr_encode(&signature_length),
                              IFX_SE_NULL_CTX);
    /* Verify signature */
    status = ifx_se_verify_hash(eccKeyId,
                                ifx_se_fih_uint_encode(IFX_SE_ALG_ECDSA(IFX_SE_ALG_SHA_256)),
                                ifx_se_fih_ptr_encode(hash),
                                ifx_se_fih_uint_encode(sizeof(hash)),
                                ifx_se_fih_ptr_encode(signature),
                                ifx_se_fih_uint_encode(sizeof(signature)),
                                IFX_SE_NULL_CTX);
    /* ... check for errors ... */
}
```

### Expected Outcome
When configured correctly:
- Secure crypto API calls complete successfully for supported algorithms.
- Hash/sign/verify and encrypt/decrypt sample flows return success status.
- Key generation/import/usage/destroy operations follow key policy and storage limits.

## Troubleshooting
- Ensure PPC regions are configured to S mode for the secure application context.
- Ensure data buffers are 4-byte aligned where recommended.
- Remap external flash addresses using `CY_REMAP_ADDRESS_CBUS_TO_SAHB` for applicable input buffers.
- Verify key type/size/algorithm combinations against supported matrix.
- For persistent AES keys, monitor and manage usage-limit counters.

## Related Code Examples
- [Secure power management example](https://github.com/Infineon/mtb-example-psoc-edge-secure-power-management/blob/master/docs/design_and_implementation.md)

## Configuration Reference
### Supported algorithms
SE RT Services Utilities Library follows Mbed TLS PSA definitions and functions, with SE RT Services limits on key types and algorithms:

| Operation      | Algorithm                 | Key type                         |
|:---------------|:--------------------------|:---------------------------------|
| Hash           | SHA-256, SHA-512          |                                  |
| Symmetric      | AES-ECB, AES-CBC, AES-CTR | AES-128, AES-256                 |
| ^              | AEAD AES-CCM              | AES-128                          |
| MAC            | AES-CMAC                  | AES-128, AES-256                 |
| Asymmetric     | ECDSA sign / verify       | SECP-256R1                       |
| ^              | ECDSA verify              | SECP-384R1                       |
| ^              | RSA verify                | Up to 4096 bits                  |
| ^              | ML-DSA sign / verify      | ML-DSA-44, ML-DSA-65, ML-DSA-87  |
| Key derivation | CMAC-KDF                  | AES-128, AES-256                 |
| Key agreement  | ECDH                      | SECP-256R1                       |

### Generic syscall groups wrapped by this library
- \ref platform_power
- \ref platform_rollbacks
- \ref platform_attestation
- \ref platform_mpc

### Supported memory regions
SE RT Services can process input data from:

| Region     | Address            | Size               |
|:-----------|:-------------------|:-------------------|
| SRAM0      | SRAM0_S_SAHB_START | SRAM0_SIZE         |
| SRAM1      | SRAM1_S_SAHB_START | SRAM1_SIZE         |
| SOCMEM_RAM | CY_SOCMEM_RAM_BASE | CY_SOCMEM_RAM_SIZE |
| XIP0       | CY_XIP_PORT0_BASE  | CY_XIP_PORT0_SIZE  |
| XIP1       | CY_XIP_PORT1_BASE  | CY_XIP_PORT1_SIZE  |
| NVM        | CY_RRAM_CBUS_BASE  | RRAM_SIZE          |

Output data can be written to:

| Region     | Address            | Size               |
|:-----------|:-------------------|:-------------------|
| SRAM0      | SRAM0_S_SAHB_START | SRAM0_SIZE         |
| SRAM1      | SRAM1_S_SAHB_START | SRAM1_SIZE         |
| SOCMEM_RAM | CY_SOCMEM_RAM_BASE | CY_SOCMEM_RAM_SIZE |

### Key storage capacity
SE RT Services provides persistent key storage for keys with \ref IFX_SE_KEY_PERSISTENCE_DEFAULT lifetime.

Import phases by key ID range:
- User keys: \ref IFX_SE_KEY_ID_USER_MIN to \ref IFX_SE_KEY_ID_USER_MAX (runtime import via \ref ifx_se_import_key).
- Vendor keys: \ref IFX_SE_KEY_ID_VENDOR_MIN to \ref IFX_SE_KEY_ID_VENDOR_MAX (provisioning phase).

User key storage capacity by key/data type:

| Data/Key type                                     | count |
|:--------------------------------------------------|------:|
| \ref IFX_SE_KEY_TYPE_AES (AES-128)                |    12 |
| \ref IFX_SE_KEY_TYPE_AES (AES-256)                |     9 |
| \ref IFX_SE_KEY_TYPE_DERIVE (AES-128)             |    12 |
| \ref IFX_SE_KEY_TYPE_DERIVE (AES-256)             |     9 |
| \ref IFX_SE_KEY_TYPE_ECC_KEY_PAIR (SECP-256R1)    |     9 |
| \ref IFX_SE_KEY_TYPE_ECC_PUBLIC_KEY (SECP-256R1)  |    12 |
| \ref IFX_SE_KEY_TYPE_ECC_PUBLIC_KEY (SECP-384R1)  |     9 |
| \ref IFX_SE_KEY_TYPE_RSA_PUBLIC_KEY (1024 bits)   |     6 |
| \ref IFX_SE_KEY_TYPE_RSA_PUBLIC_KEY (2048 bits)   |     3 |
| \ref IFX_SE_KEY_TYPE_RSA_PUBLIC_KEY (3072 bits)   |     2 |
| \ref IFX_SE_KEY_TYPE_RSA_PUBLIC_KEY (4096 bits)   |     2 |
| \ref IFX_SE_KEY_TYPE_RAW_DATA (1 - 65 bytes)      |    12 |

- Maximum single \ref IFX_SE_KEY_TYPE_RAW_DATA object size: 564 bytes.
- Vendor key storage capacity: up to 16 provisioned keys.

Persistent AES key usage limits:
- Up to 100k uses per key, tracked using rollback counters (\ref ifx_se_get_usage_limit_counter).
- Key must be destroyed after limit (\ref ifx_se_destroy_key).
- Only 16 usage-limit counters exist for all AES keys.
- If 8 AES Vendor keys are provisioned, only 8 counters remain for imported AES User keys.
- For side-channel protection reasons, volatile key usage should also be limited to 100k operations or additional protections should be used.

### Performance
PSA Crypto API benchmark from a reference SE RT Services setup with SE core at 100 MHz:

| Algorithm       | Execution time       |
|:----------------|:---------------------|
| SHA-256         | 8 ms/100kB payload   |
| AES-CBC-128     | 202 ms/10kB payload  |
| AES-CBC-256     | 277 ms/10kB payload  |
| AES-CTR-128     | 200 ms/10kB payload  |
| AES-CTR-256     | 275 ms/10kB payload  |
| ECDSA-secp256r1 | 220 ms/sign          |
| ECDSA-secp256r1 | 170 ms/verify        |
| ECDSA-secp384r1 | 340 ms/verify        |
| ECDSA-secp521r1 | 700 ms/verify        |

## Compatible Software
- PSA Crypto API v1.3 semantics.
- Mbed TLS-compatible PSA API interface expectations as implemented by SE RT Services (aligned with Mbed TLS 3.6.0 interface usage noted in this library documentation).

## Industry Standards and Compliance
- PSA Cryptography API: Version 1.3 references are used for API compatibility and workflows.
- NIST test vectors are referenced for ECDSA signature verification example flows.

## Release Notes and Changelog
- [RELEASE.md](RELEASE.md) - Detailed release notes for all versions.

## More Information
- [SE RT Services Utilities Library API documentation](https://infineon.github.io/se-rt-services-utils/html/index.html)
- [ModusToolbox Software Environment, Quick Start Guide, Documentation, and Videos](https://www.infineon.com/cms/en/design-support/tools/sdk/modustoolbox-software/)
- [Infineon Technologies AG](http://www.infineon.com)

## Copyright
© Infineon Technologies AG, 2023-2026.
