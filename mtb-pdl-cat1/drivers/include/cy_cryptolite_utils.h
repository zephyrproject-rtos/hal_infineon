/***************************************************************************//**
* \file cy_cryptolite_utils.h
* \version 2.30
*
* \brief
*  This file provides provides helper functions
*  for the Cryptolite driver.
*
********************************************************************************
* Copyright 2022 Cypress Semiconductor Corporation
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
#if !defined (CY_CRYPTOLITE_UTILS_H)
#define CY_CRYPTOLITE_UTILS_H

#include "cy_device.h"

#if defined(CY_IP_MXCRYPTOLITE)

#include "cy_cryptolite_common.h"

#if defined(__cplusplus)
extern "C" {
#endif



/*******************************************************************************
* Function Name: Crypto_String2ByteArray
****************************************************************************//**
*
* The function to convert hex string to byte array.
*
* \param p_dst
* The pointer to destination buffer where data to be copied.
*
* \param p_number_string
* The pointer to buffer containing the hex string.
*
* \param byteSize
* The size of the bytes to be converted.
*
*
*******************************************************************************/

void Crypto_String2ByteArray (
    uint8_t* p_dst,
    int8_t*  p_number_string,
    int      byte_size
);


/*******************************************************************************
* Function Name: Crypto_SetNumber
****************************************************************************//**
*
* The function to copy the data without any alignment and boundary restriction.
*
* \param rdst
* The pointer to destination buffer where data to be copied.
*
* \param p_number
* The pointer to buffer containing the data.
*
* \param byteSize
* The size of the bytes to be copied.
*
*
*******************************************************************************/
void Crypto_SetNumber (
    uint8_t* rdst,
    uint8_t* p_number,
    uint32_t size
);

/*******************************************************************************
* Function Name: Cy_Cryptolite_InvertEndianness
****************************************************************************//**
*
* The function performs endian conversion of the data.
*
* \param inArrPtr
* The pointer to buffer containing the data.
*
* \param byteSize
*  The size of the inArrPtr buffer.
*
*
*******************************************************************************/
void Cy_Cryptolite_InvertEndianness(void *inArrPtr, uint32_t byteSize);


#if defined(__cplusplus)
}
#endif

#endif /* CY_IP_MXCRYPTOLITE */

#endif
/* [] END OF FILE */
