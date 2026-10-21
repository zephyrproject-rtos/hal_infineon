/***************************************************************************//**
* \file cy_crypto.h
* \version 1.0
*
* \brief
*  This file provides an API declaration of the Crypto driver
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

/**
* \addtogroup group_crypto
* \{
* The Crypto driver provides a public API to perform cryptographic and hash
* operations, as well as generate both true and pseudo random numbers.
*
* It uses a hardware IP block to accelerate operations.
*
* The functions and other declarations used in this driver are in cy_crypto.h.
* You can also include cy_pdl.h to get access to all functions and declarations
* in the PDL.
*
* The Crypto driver supports these standards: AES (128, 192, and 256 bits),
* SHA (160, 224, and 256 bits hash), CRC (upto 32-bit), PRNG, and TRNG.
********************************************************************************
* \section group_crypto_configuration_considerations Configuration considerations
*
* Firmware sets up a cryptographic operation by passing the required data as
* parameters in the function calls.
*
* All Crypto functions require a context. A context is a data
* structure that the driver uses for its operations. Firmware declares a
* context (allocates memory), but does not write or read the values in that
* context. In effect, the context is a scratchpad you provide to the driver.
* The driver uses the context to store and manipulate the data during
* cryptographic operations.
*
* Crypto functions are not thread-safe. Applications must use its own locking
* mechanism to ensure that functions in this driver are called by only one
* thread at a time.
*
* Crypto TRNG and PRNG functions can execute in parallel with AES, SHA, and CRC
* functions.
*
* \section group_crypto_definitions Definitions
*
* <table class="doxtable">
*   <tr>
*     <th>Term</th>
*     <th>Definition</th>
*   </tr>
*
*   <tr>
*     <td>Plaintext</td>
*     <td>An unencrypted message</td>
*   </tr>
*
*   <tr>
*     <td>Ciphertext</td>
*     <td>An encrypted message</td>
*   </tr>
*
*   <tr>
*     <td>Block cipher</td>
*     <td>An encryption function for fixed-size blocks of data.
*     This function takes a fixed-size key and a block of plain text data from
*     the message and encrypts it to generate the cipher text. Block ciphers are
*     reversible. The function performed on a block of encrypted data will
*     decrypt that data.</td>
*   </tr>
*
*   <tr>
*     <td>Block Cipher mode</td>
*     <td>A mode of encrypting a message using block ciphers for messages of an
*     arbitrary length. The message is padded so that its length is an integer
*     multiple of the block size. Electronic code book (ECB), cipher block
*     chaining (CBC), and cipher feedback (CFB) are modes of using block ciphers
*     to create an encrypted message of an arbitrary length.
*     </td>
*   </tr>
*
*   <tr>
*     <td>Advanced Encryption Standard (AES)</td>
*     <td>The [AES standard] (https://nvlpubs.nist.gov/nistpubs/fips/nist.fips.197.pdf)
*     specifies the Rijndael algorithm, a symmetric block
*     cipher that can process 128-bit data blocks using cipher keys with
*     128-, 192-, and 256-bit lengths. Rijndael was designed to handle
*     additional block sizes and key lengths. However, they are not adopted in
*     this standard. AES is also used for message authentication.
*     </td>
*   </tr>
*
*   <tr>
*     <td>Secure Hash Algorithm (SHA)</td>
*     <td>A cryptographic hash function.
*     This function takes a message of an arbitrary length and reduces it to a
*     fixed-length residue or message digest after performing a series of
*     mathematically defined operations that practically guarantee that any
*     change in the message will change the hash value. It is used for message
*     authentication by transmitting a message with a hash value appended to it
*     and recalculating the message hash value using the same algorithm at the
*     recipient's end. If the hashes differ, it indicates that the message is corrupted.
*     For more information see [Secure Hash standard description]
*     (https://csrc.nist.gov/csrc/media/publications/fips/180/2/archive/2002-08-01/documents/fips180-2.pdf).
*     </td>
*   </tr>
*
*   <tr>
*     <td>Pseudo Random Number Generator (PRNG)</td>
*     <td>An algorithm based on linear feedback shift registers for generating a
*     sequence of numbers starting from a non-zero seed.</td>
*   </tr>
*
*   <tr>
*     <td>True Random Number Generator (TRNG)</td>
*     <td>A block that generates a number that is statistically random and based
*     on some physical random variation. The number cannot be duplicated by
*     running the process again.</td>
*   </tr>
*
*   <tr>
*     <td>Symmetric Key Cryptography</td>
*     <td>Uses a common, known key to encrypt and decrypt messages (a shared
*     secret between the sender and the receiver). An efficient method used for
*     encrypting and decrypting messages after the authenticity of the other
*     party has been established. DES (now obsolete), 3DES, and AES (currently
*     used) are well-known symmetric cryptography methods.</td>
*   </tr>
*
* \section group_crypto_changelog Changelog
* <table class="doxtable">
*   <tr><th>Version</th><th>Changes</th><th>Reason for Change</th></tr>
*   <tr>
*     <td>1.0.1</td>
*     <td>Update the paths to the code snippets.</td>
*     <td>PDL structure update.</td>
*   </tr>
*   <tr>
*     <td>1.0</td>
*     <td>Initial version</td>
*     <td></td>
*   </tr>
* </table>
*
* \defgroup group_crypto_macros Macros
* \defgroup group_crypto_enums Enums
* \defgroup group_crypto_structures Structures
* \defgroup group_crypto_functions Functions
* \{
*      \defgroup group_crypto_lld_hw_functions Control and status
*      \defgroup group_crypto_lld_symmetric_functions Symmetric key algorithms (AES)
*      \defgroup group_crypto_lld_sha_functions Hash operations (SHA)
*      \defgroup group_crypto_lld_crc_functions Cyclic redundancy code (CRC)
*      \defgroup group_crypto_lld_rng_functions Random number generation (TRNG, PRNG)
*  \}
*
* \section group_crypto_lld_common_use_cases Common use-cases
*
* \subsection group_crypto_lld_crypto_enable  Crypto hardware enable
*
* Use \ref Cy_Crypto_Enable to enable the Crypto IP block. After this
* call, the Crypto driver is ready to execute crypto functions.
*
* Code example:
* \snippet crypto_snippet.c snippet_myCryptoStartCryptoUse
*
* \subsection group_crypto_lld_crypto_disable  Crypto hardware disable
*
* Use \ref Cy_Crypto_Disable to disable the Crypto IP block. After this
* call, No crypto function should be executed.
*
* Code example:
* \snippet crypto_snippet.c snippet_myCryptoStopCryptoUse
*
* \subsection group_crypto_lld_Use_AES AES encryption
*
* The Crypto driver provides four AES encryption algorithms (ECB, CBC, CFB,
* and CTR) that are used similarly.
*
* To encrypt a message using the AES ECB algorithm (as example):
*   - Place AES key into an array of appropriate size.
*   - Use \ref Cy_Crypto_Aes_Init to configure the operation.
*   - Call \ref Cy_Crypto_Aes_Ecb (\ref Cy_Crypto_Aes_Cbc,
*     \ref Cy_Crypto_Aes_Cfb, or \ref Cy_Crypto_Aes_Ctr) with appropriate
*     parameters to perform an operation.
*
* Code example:
* \snippet crypto_snippet.c snippet_myCryptoAesEcbUse
*
* \subsection group_crypto_lld_Use_CRC CRC calculation
*
* To calculate the CRC of a data image:
*   - Use \ref Cy_Crypto_Crc_CalcInit to set parameters for the selected CRC mode.
*   - Call \ref Cy_Crypto_Crc_Calc to calculate the CRC for a data image.
*
* Code example:
* \snippet crypto_snippet.c snippet_myCryptoCrcUse
*
* \subsection group_crypto_lld_Use_SHA SHA digest calculation
*
* To calculate a SHA digest of a message:
*   - Call \ref Cy_Crypto_Sha with appropriate parameters to perform an
*     operation.
*
* Code example:
* \snippet crypto_snippet.c snippet_myCryptoSha256Use
*
* \subsection group_crypto_lld_Use_PRNG Pseudo random number generation
*
* To generate a pseudo random number:
*   - Use \ref Cy_Crypto_Prng_Init to set the required parameters.
*   - Call \ref Cy_Crypto_Prng.
*
* Code example:
* \snippet crypto_snippet.c snippet_myCryptoPrngUse
*
* \subsection group_crypto_lld_Use_TRNG True random number generation
*
* To generate a true random number:
*   - Call \ref Cy_Crypto_Trng with the required parameters.
*
* Code example:
* \snippet crypto_snippet.c snippet_myCryptoTrngUse
*
* \} */

#if !defined(CY_CRYPTO_H)
#define CY_CRYPTO_H

#include "cy_crypto_aes.h"
#include "cy_crypto_crc.h"
#include "cy_crypto_hw.h"
#include "cy_crypto_prng.h"
#include "cy_crypto_sha.h"
#include "cy_crypto_trng.h"

#endif /* #if !defined(CY_CRYPTO_H) */

/* [] END OF FILE */
