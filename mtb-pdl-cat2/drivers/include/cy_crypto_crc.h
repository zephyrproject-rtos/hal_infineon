/***************************************************************************//**
* \file cy_crypto_crc.h
* \version 1.0.1
*
* \brief
*  This file provides CRC API declaration of the Crypto driver
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

#if !defined(CY_CRYPTO_CRC_H)
#define CY_CRYPTO_CRC_H

#include "cy_device.h"

#if (defined (CY_IP_M0S8CRYPTO) && defined (CRYPTO_CRC)) || defined (CY_DOXYGEN)

#include "cy_crypto_common.h"

#if defined(__cplusplus)
extern "C" {
#endif

/**
* \addtogroup group_crypto_lld_crc_functions
* \{
*/

/*******************************************************************************
* Function name: Cy_Crypto_Crc_CalcInit
****************************************************************************//**
*
* This function initializes the CRC (Cyclic Redundancy Check) calculation.
*
* The following table lists known polynomials with different parameters and their
* calculated CRCs from the string <b>"123456789"</b>:
* | Name               | Width | Poly       | Init       | Data Rev | Data XOR | Rem Rev | Rem XOR    | Expected CRC |
* |:-------------------|:-----:|:----------:|:----------:|:--------:|:--------:|:-------:|:----------:|:------------:|
* | CRC-3 / ROHC       |     3 |        0x3 |        0x7 |        1 |        0 |       1 |        0x0 |          0x6 |
* | CRC-4 / ITU        |     4 |        0x3 |        0x0 |        1 |        0 |       1 |        0x0 |          0x7 |
* | CRC-5 / EPC        |     5 |        0x9 |        0x9 |        0 |        0 |       0 |        0x0 |          0x0 |
* | CRC-5 / ITU        |     5 |       0x15 |        0x0 |        1 |        0 |       1 |        0x0 |          0x7 |
* | CRC-5 / USB        |     5 |        0x5 |       0x1F |        1 |        0 |       1 |       0x1F |         0x19 |
* | CRC-6 / CDMA2000-A |     6 |       0x27 |       0x3F |        0 |        0 |       0 |        0x0 |          0xD |
* | CRC-6 / CDMA2000-B |     6 |        0x7 |       0x3F |        0 |        0 |       0 |        0x0 |         0x3B |
* | CRC-6 / DARC       |     6 |       0x19 |        0x0 |        1 |        0 |       1 |        0x0 |         0x26 |
* | CRC-6 / ITU        |     6 |        0x3 |        0x0 |        1 |        0 |       1 |        0x0 |          0x6 |
* | CRC-7              |     7 |        0x9 |        0x0 |        0 |        0 |       0 |        0x0 |         0x75 |
* | CRC-7 / ROHC       |     7 |       0x4F |       0x7F |        1 |        0 |       1 |        0x0 |         0x53 |
* | CRC-8              |     8 |        0x7 |        0x0 |        0 |        0 |       0 |        0x0 |         0xF4 |
* | CRC-8 / CDMA2000   |     8 |       0x9B |       0xFF |        0 |        0 |       0 |        0x0 |         0xDA |
* | CRC-8 / DARC       |     8 |       0x39 |        0x0 |        1 |        0 |       1 |        0x0 |         0x15 |
* | CRC-8 / DVB-S2     |     8 |       0xD5 |        0x0 |        0 |        0 |       0 |        0x0 |         0xBC |
* | CRC-8 / EBU        |     8 |       0x1D |       0xFF |        1 |        0 |       1 |        0x0 |         0x97 |
* | CRC-8 / I-CODE     |     8 |       0x1D |       0xFD |        0 |        0 |       0 |        0x0 |         0x7E |
* | CRC-8 / ITU        |     8 |        0x7 |        0x0 |        0 |        0 |       0 |       0x55 |         0xA1 |
* | CRC-8 / MAXIM      |     8 |       0x31 |        0x0 |        1 |        0 |       1 |        0x0 |         0xA1 |
* | CRC-8 / ROHC       |     8 |        0x7 |       0xFF |        1 |        0 |       1 |        0x0 |         0xD0 |
* | CRC-8 / WCDMA      |     8 |       0x9B |        0x0 |        1 |        0 |       1 |        0x0 |         0x25 |
* | CRC-10             |    10 |      0x233 |        0x0 |        0 |        0 |       0 |        0x0 |        0x199 |
* | CRC-10 / CDMA2000  |    10 |      0x3D9 |      0x3FF |        0 |        0 |       0 |        0x0 |        0x233 |
* | CRC-11             |    11 |      0x385 |       0x1A |        0 |        0 |       0 |        0x0 |        0x5A3 |
* | CRC-12 / 3GPP      |    12 |      0x80F |        0x0 |        0 |        0 |       1 |        0x0 |        0xDAF |
* | CRC-12 / CDMA2000  |    12 |      0xF13 |      0xFFF |        0 |        0 |       0 |        0x0 |        0xD4D |
* | CRC-12 / DECT      |    12 |      0x80F |        0x0 |        0 |        0 |       0 |        0x0 |        0xF5B |
* | CRC-13 / BBC       |    13 |     0x1CF5 |        0x0 |        0 |        0 |       0 |        0x0 |        0x4FA |
* | CRC-14 / DARC      |    14 |      0x805 |        0x0 |        1 |        0 |       1 |        0x0 |        0x82D |
* | CRC-15             |    15 |     0x4599 |        0x0 |        0 |        0 |       0 |        0x0 |        0x59E |
* | CRC-15 / MPT1327   |    15 |     0x6815 |        0x0 |        0 |        0 |       0 |        0x1 |       0x2566 |
* | CRC-24             |    24 |  0x0864CFB | 0x00B704CE |        0 |        0 |       0 |        0x0 |     0x21CF02 |
* | CRC-24 / FLEXRAY-A |    24 |  0x05D6DCB | 0x00FEDCBA |        0 |        0 |       0 |        0x0 |     0x7979BD |
* | CRC-24 / FLEXRAY-B |    24 |  0x05D6DCB | 0x00ABCDEF |        0 |        0 |       0 |        0x0 |     0x1F23B8 |
* | CRC-31 / PHILIPS   |    31 |  0x4C11DB7 | 0x7FFFFFFF |        0 |        0 |       0 | 0x7FFFFFFF |    0xCE9E46C |
* | CRC-16 / ARC       |    16 |     0x8005 |     0x0000 |        1 |        0 |       1 |     0x0000 |       0xBB3D |
* | CRC-16 / AUG-CCITT |    16 |     0x1021 |     0x1D0F |        0 |        0 |       0 |     0x0000 |       0xE5CC |
* | CRC-16 / BUYPASS   |    16 |     0x8005 |     0x0000 |        0 |        0 |       0 |     0x0000 |       0xFEE8 |
* | CRC-16 / CCITT-0   |    16 |     0x1021 |     0xFFFF |        0 |        0 |       0 |     0x0000 |       0x29B1 |
* | CRC-16 / CDMA2000  |    16 |     0xC867 |     0xFFFF |        0 |        0 |       0 |     0x0000 |       0x4C06 |
* | CRC-16 / DDS-110   |    16 |     0x8005 |     0x800D |        0 |        0 |       0 |     0x0000 |       0x9ECF |
* | CRC-16 / DECT-R    |    16 |     0x0589 |     0x0000 |        0 |        0 |       0 |     0x0001 |       0x007E |
* | CRC-16 / DECT-X    |    16 |     0x0589 |     0x0000 |        0 |        0 |       0 |     0x0000 |       0x007F |
* | CRC-16 / DNP       |    16 |     0x3D65 |     0x0000 |        1 |        0 |       1 |     0xFFFF |       0xEA82 |
* | CRC-16 / EN-13757  |    16 |     0x3D65 |     0x0000 |        0 |        0 |       0 |     0xFFFF |       0xC2B7 |
* | CRC-16 / GENIBUS   |    16 |     0x1021 |     0xFFFF |        0 |        0 |       0 |     0xFFFF |       0xD64E |
* | CRC-16 / MAXIM     |    16 |     0x8005 |     0x0000 |        1 |        0 |       1 |     0xFFFF |       0x44C2 |
* | CRC-16 / MCRF4XX   |    16 |     0x1021 |     0xFFFF |        1 |        0 |       1 |     0x0000 |       0x6F91 |
* | CRC-16 / RIELLO    |    16 |     0x1021 |     0xB2AA |        1 |        0 |       1 |     0x0000 |       0x63D0 |
* | CRC-16 / T10-DIF   |    16 |     0x8BB7 |     0x0000 |        0 |        0 |       0 |     0x0000 |       0xD0DB |
* | CRC-16 / TELEDISK  |    16 |     0xA097 |     0x0000 |        0 |        0 |       0 |     0x0000 |       0x0FB3 |
* | CRC-16 / TMS37157  |    16 |     0x1021 |     0x89EC |        1 |        0 |       1 |     0x0000 |       0x26B1 |
* | CRC-16 / USB       |    16 |     0x8005 |     0xFFFF |        1 |        0 |       1 |     0xFFFF |       0xB4C8 |
* | CRC-A              |    16 |     0x1021 |     0xC6C6 |        1 |        0 |       1 |     0x0000 |       0xBF05 |
* | CRC-16 / KERMIT    |    16 |     0x1021 |     0x0000 |        1 |        0 |       1 |     0x0000 |       0x2189 |
* | CRC-16 / MODBUS    |    16 |     0x8005 |     0xFFFF |        1 |        0 |       1 |     0x0000 |       0x4B37 |
* | CRC-16 / X-25      |    16 |     0x1021 |     0xFFFF |        1 |        0 |       1 |     0xFFFF |       0x906E |
* | CRC-16 / XMODEM    |    16 |     0x1021 |     0x0000 |        0 |        0 |       0 |     0x0000 |       0x31C3 |
* | CRC-32             |    32 | 0x04C11DB7 | 0xFFFFFFFF |        1 |        0 |       1 | 0xFFFFFFFF |   0xCBF43926 |
* | CRC-32 / BZIP2     |    32 | 0x04C11DB7 | 0xFFFFFFFF |        0 |        0 |       0 | 0xFFFFFFFF |   0xFC891918 |
* | CRC-32C            |    32 | 0x1EDC6F41 | 0xFFFFFFFF |        1 |        0 |       1 | 0xFFFFFFFF |   0xE3069283 |
* | CRC-32D            |    32 | 0xA833982B | 0xFFFFFFFF |        1 |        0 |       1 | 0xFFFFFFFF |   0x87315576 |
* | CRC-32 / MPEG-2    |    32 | 0x04C11DB7 | 0xFFFFFFFF |        0 |        0 |       0 | 0x00000000 |   0x0376E6E7 |
* | CRC-32 / POSIX     |    32 | 0x04C11DB7 | 0x00000000 |        0 |        0 |       0 | 0xFFFFFFFF |   0x765E7680 |
* | CRC-32Q            |    32 | 0x814141AB | 0x00000000 |        0 |        0 |       0 | 0x00000000 |   0x3010BF7F |
* | CRC-32 / JAMCRC    |    32 | 0x04C11DB7 | 0xFFFFFFFF |        1 |        0 |       1 | 0x00000000 |   0x340BC6D9 |
* | CRC-32 / XFER      |    32 | 0x000000AF | 0x00000000 |        0 |        0 |       0 | 0x00000000 |   0xBD0BE338 |
*
* \param base
* Base address of the Crypto block registers
*
* \param width
* Width of the CRC value to be calculated in bits. Max width supported is
* 32-bits.
*
* \param polynomial
* Polynomial value to be used in computing the CRC. The size of the polynomial
* value should be based on the width of the CRC value to be calculated.
*
* \param dataReverse
* Bit order in which each data byte is processed. 0 - MSB first; 1 - LSB first.
*
* \param dataXor
* Byte mask with which each data byte is XORed.
*
* \param remReverse
* Specifies whether the remainder should be bit reversed.
* 0 - Remainder is not reversed; 1 - Remainder is reversed.
*
* \param remXor
* Mask with which the LFSR32 register is XORed to produce a remainder.
*
* \param lfsrInitState
* CRC seed value used as the initial state of a 32-bit
* Linear Feedback Shift Register (LFSR).
*
* \param crcContext
* Pointer to the CRC context structure \ref cy_stc_crypto_crc_context_t allocated
* by the user. This structure is used by the Crypto driver for the CRC
* calculation. Do not modify the values of this structure.
*
* \return
* \ref cy_en_crypto_status_t
*
* \funcusage
* \snippet crypto_snippet.c snippet_myCryptoCrcCalcUse
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Crc_CalcInit(CRYPTO_Type *base,
                                             uint32_t width,
                                             uint32_t polynomial,
                                             bool     dataReverse,
                                             uint8_t  dataXor,
                                             bool     remReverse,
                                             uint32_t remXor,
                                             uint32_t lfsrInitState,
                                             cy_stc_crypto_crc_context_t *crcContext);

/*******************************************************************************
* Function Name: Cy_Crypto_Crc_Calc
****************************************************************************//**
*
* This function performs the CRC calculation on a message.
*
* The polynomial and other CRC parameters must be set before by invoking
* \ref Cy_Crypto_Crc_CalcInit().
*
* \note  This function is to be used when the data is in one contiguous block of
*        memory. For non-contiguous blocks of memory, use 
*        \ref Cy_Crypto_Crc_CalcPartial() and \ref Cy_Crypto_Crc_CalcFinish().
*
* \param base
* Base address of the Crypto block registers
*
* \param crc
* Pointer to store the computed CRC value
*
* \param data
* Pointer to the message whose CRC is being computed
*
* \param dataSize
* Size of the message in bytes
*
* \param crcContext
* Pointer to the CRC context structure \ref cy_stc_crypto_crc_context_t allocated
* by the user. This structure is used by the Crypto driver for the CRC
* calculation. Do not modify the values of this structure.
*
* \return
* \ref cy_en_crypto_status_t
*
* \funcusage
* \snippet crypto_snippet.c snippet_myCryptoCrcCalcUse
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Crc_Calc(CRYPTO_Type *base,
                                         uint32_t *crc,
                                         void const *data,
                                         uint32_t dataSize,
                                         cy_stc_crypto_crc_context_t *crcContext);

/*******************************************************************************
* Function Name: Cy_Crypto_Crc_CalcPartial
****************************************************************************//**
*
* This function performs the CRC calculation on partial data which is part of a
* complete message.
*
* The polynomial and other CRC parameters must be set before by invoking
* \ref Cy_Crypto_Crc_CalcInit(). This function can be called multiple times with
* partial data and at the end, the user must call \ref Cy_Crypto_Crc_CalcFinish()
* to get the computed CRC value.
*
* \param base
* Base address of the Crypto block registers
*
* \param data
* Pointer to the message whose CRC is being computed
*
* \param dataSize
* Size of the message in bytes
*
* \param crcContext
* Pointer to the CRC context structure \ref cy_stc_crypto_crc_context_t allocated
* by the user. This structure is used by the Crypto driver for the CRC
* calculation. Do not modify the values of this structure.
*
* \return
* \ref cy_en_crypto_status_t
*
* \funcusage
* \snippet crypto_snippet.c snippet_myCryptoCrcCalcUse2
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Crc_CalcPartial(CRYPTO_Type *base,
                                                void const *data,
                                                uint32_t dataSize,
                                                cy_stc_crypto_crc_context_t *crcContext);

/*******************************************************************************
* Function Name: Cy_Crypto_Crc_CalcFinish
****************************************************************************//**
*
* This function completes the CRC calculation for message provided with 
* \ref Cy_Crypto_Crc_CalcPartial() function. Once this function is called,
* call \ref Cy_Crypto_Crc_CalcFree to free the CRC context. 
*
* \param base
* Base address of the Crypto block registers
*
* \param crc
* Pointer to store the computed CRC value
*
* \param crcContext
* Pointer to the CRC context structure \ref cy_stc_crypto_crc_context_t allocated
* by the user. This structure is used by the Crypto driver for the CRC
* calculation. Do not modify the values of this structure.
*
* \return
* \ref cy_en_crypto_status_t
*
* \funcusage
* \snippet crypto_snippet.c snippet_myCryptoCrcCalcUse2
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Crc_CalcFinish(CRYPTO_Type *base,
                                               uint32_t *crc,
                                               cy_stc_crypto_crc_context_t *crcContext);

/*******************************************************************************
* Function Name: Cy_Crypto_Crc_CalcFree
****************************************************************************//**
*
* This function clears the CRC context.
*
* \note  To start a new CRC calculation, call \ref Cy_Crypto_Crc_CalcInit()
*        again after this function call.
*
* \param base
* Base address of the Crypto block registers.
*
* \param crcContext
* Pointer to the CRC context structure \ref cy_stc_crypto_crc_context_t allocated
* by the user. This structure is used by the Crypto driver for the CRC
* calculation. Do not modify the values of this structure.
*
* \return
* \ref cy_en_crypto_status_t
*
* \funcusage
* \snippet crypto_snippet.c snippet_myCryptoCrcCalcUse
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Crc_CalcFree(CRYPTO_Type *base,
                                              cy_stc_crypto_crc_context_t *crcContext);
/** \} group_crypto_lld_crc_functions */

#if defined(__cplusplus)
}
#endif

#endif /* CY_IP_M0S8CRYPTO */

#endif /* #if !defined(CY_CRYPTO_CRC_H) */



/* [] END OF FILE */
