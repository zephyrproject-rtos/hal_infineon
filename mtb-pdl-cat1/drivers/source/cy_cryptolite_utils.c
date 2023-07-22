/***************************************************************************//**
* \file cy_cryptolite_utils.c
* \version 2.30
*
* \brief
*  Provides utility functions.
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
#include "cy_device.h"

#if defined(CY_IP_MXCRYPTOLITE)

#include "cy_cryptolite_vu.h"
#include "cy_cryptolite_utils.h"
#include <string.h>
#include <stdlib.h>

void Crypto_String2ByteArray ( uint8_t* p_dst,
                            int8_t*  p_number_string,
                            int      byte_size)
{
   int      i;
   int      len  = (int)strlen ((char const *)p_number_string);
   uint8_t  character;
   uint8_t  nibble;
   uint8_t  byte = 0;
   uint32_t nibble_pos = 0;
   int      byte_idx;
   bool     valid;
   for (byte_idx = byte_size - 1; byte_idx > 0; byte_idx--){
      p_dst[byte_idx] = 0x00;
   }
   p_dst[byte_idx] = 0x00;
   for (i = len - 1; i >= 0; i--) {
      character = (uint8_t)p_number_string[i];
      if ((character >= (uint8_t)'0') && (character <= (uint8_t)'9')) {
         nibble = (uint8_t) character - (uint8_t)'0';
         valid  = true;
      }
      else if ((character >= (uint8_t)'a') && (character <= (uint8_t)'f')) {
         nibble = (uint8_t) (character - (uint8_t)'a') + (uint8_t)10;
         valid  = true;
      }
      else if ((character >= (uint8_t)'A') && (character <= (uint8_t)'F')) {
         nibble = (uint8_t) (character - (uint8_t)'A') + (uint8_t)10;
         valid  = true;
      }
      else {
         valid  = false;
      }
      if (valid) {
         byte |= (nibble << (4U*(nibble_pos)));
         nibble_pos++;
      }
      if (nibble_pos == 2U) {
         p_dst[byte_idx] = byte;
         byte_idx   += 1;
         nibble_pos = 0;
         byte       = 0;
      }
   }
   if (nibble_pos != 0U)
   {
      p_dst[byte_idx] = byte;
   }
}

void Crypto_SetNumber( uint8_t* rdst,
                        uint8_t* p_number,
                        uint32_t size)
{
  uint32_t i;

  for(i=0; i < size; i++)
  {
      rdst[i] = p_number[i];
  }
}

void Cy_Cryptolite_InvertEndianness(void *inArrPtr, uint32_t byteSize)
{
    int32_t limit;
    int32_t i;
    int32_t j = 0;
    uint8_t temp;
    uint8_t *tempPtr = NULL;


    if((inArrPtr == NULL) && (byteSize > 0u))
    {
      return;
    }

    tempPtr = (uint8_t*)inArrPtr;
    
    if (byteSize > 1u)
    {
        limit = (int32_t)byteSize / 2;
        if (0u == (byteSize % 2u))
        {
            --limit;
        }

        j = 0;
        i = (int32_t)byteSize - 1;
        while ( i > limit)
        {
            temp = tempPtr[j];
            tempPtr[j] = tempPtr[i];
            tempPtr[i] = temp;

            --i;
            ++j;
        }
    }
}
#endif /*defined(CY_IP_MXCRYPTOLITE)*/
