/***************************************************************************//**
* \file cy_cryptolite.h
* \version 1.40
*
* \brief
*  This file provides an API declaration of the Cryptolite driver
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
/**
* \addtogroup group_cryptolite
* \{
* The Cryptolite driver provides a public API to configure the Cryptolite IP block 
* and perform cryptographic and hash operations, as well as generate true random 
* numbers and perform arithmetic/logical operations.
*
* The driver uses a hardware (Cryptolite IP) block to accelerate operations.
*
* The functions and other declarations used in this driver are in cy_cryptolite.h.
*
* The Cryptolite driver supports these standards: AES-128 bit, SHA-256 bits hash,
* TRNG (True Number Generator) and VU (Vector Unit)
********************************************************************************
* \section group_cryptolite_configuration_considerations Configuration considerations
*
* Firmware sets up a cryptographic operation by passing the required data as
* parameters in the function calls.
*
* All Crypto functions require a context and base address. A context is a data
* structure that the driver uses for its operations. Firmware declares a
* context (allocates memory), but does not write or read the values in that
* context. In effect, the context is a scratch-pad you provide to the driver.
* The driver uses the context to store and manipulate the data during
* cryptographic operations. Base is a address of the Cryptolite IP registers.
*
* Crypto functions are not thread-safe. Applications must use its own locking
* mechanism to ensure that functions in this driver are called by only one
* thread at a time.
*
* Cryptolite TRNG functions can execute in parallel with AES, SHA, and VU.
* functions.
*
* \section group_cryptolite_definitions Definitions
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
*     <td>True Random Number Generator (TRNG)</td>
*     <td>A block that generates a number that is statistically random and based
*     on some physical random variation. The number cannot be duplicated by
*     running the process again.</td>
*   </tr>
*
*   <tr>
*     <td>Vector Unit (VU)</td>
*     <td>Vector Unit accelerates the larger integer arithmetic operations. It can be used to accelerate the
*     asymmetric key cryptography (e.g. RSA and ECC). The driver supports addition, subtraction,
*     multiplication, shift etc. </td>
*   </tr>
*
*   <tr>
*     <td>RSA Algorithm</td>
*     <td>A cryptographic RSA decryption function.
*     This function takes encrypted RSA signature of given RSA-bit size and decrypts the 
*     SHA digest. The output SHA digest extracted from RSA signature is compared with input SHA 
*     digest and returns status TRUE if both digests are same.
*     This function uses Montgomery modular multiplication. Montgomery
*     multiplication requires two Montgomery coefficients. In addition, Montgomery
*     transformation is accelerated using Barrett reduction which requires one Barrett coefficient.
*     With the help of above calculated coefficients, the function decrypts the RSA signature and
*     extracts the SHA digest. The coefficients can be pre-calculated and kept in non-volatile memory
*     to improve the timing.
*     </td>
*   </tr>
* 
* \section group_cryptolite_changelog Changelog
* <table class="doxtable">
*   <tr><th>Version</th><th>Changes</th><th>Reason for Change</th></tr>
*   <tr>
*     <td rowspan="2">1.40</td>
*     <td>Added RSA signature verification using RSA PSS signature scheme.</td>
*     <td>New feature support</td>
*   </tr>
*   <tr>
*     <td>Fixed endianness conversion issue in hash calculation for SHA-384 and SHA-512.</td>
*     <td>Defect fix</td>
*   </tr>
*   <tr>
*     <td rowspan="2">1.30</td>
*     <td>Added support for SHA-384 and SHA-512.</td>
*     <td>New feature support.</td>
*   </tr>
*   <tr>
*     <td>Added RSA driver for signature verification using the provided public key.</td>
*     <td>New feature support.</td>
*   </tr>
*   <tr>
*     <td>1.20</td>
*     <td>Corrected variable type name.</td>
*     <td>Defect fix.</td>
*   </tr>
*   <tr>
*     <td>1.10</td>
*     <td>Fixed optimization issue in Cryptolite VU driver and updated VU_BITS_TO_WORDS macro logic.</td>
*     <td>Defect fix.</td>
*   </tr>
*   <tr>
*     <td>1.0</td>
*     <td>Initial version</td>
*     <td></td>
*   </tr>
* </table>
*
* \defgroup group_cryptolite_common Common
* \defgroup group_cryptolite_sha SHA
* \defgroup group_cryptolite_aes AES
* \defgroup group_cryptolite_vu VU
* \defgroup group_cryptolite_trng TRNG
* \defgroup group_cryptolite_rsa RSA
*
* \} */

#if !defined(CY_CRYPTOLITE_H)
#define CY_CRYPTOLITE_H

#include "cy_cryptolite_common.h"
#include "cy_cryptolite_aes.h"
#include "cy_cryptolite_vu.h"
#include "cy_cryptolite_sha.h"
#include "cy_cryptolite_trng.h"
#include "cy_cryptolite_rsa.h"

#endif /* #if !defined(CY_CRYPTOLITE_H) */

/* [] END OF FILE */
