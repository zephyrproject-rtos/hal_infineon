/***************************************************************************//**
* \file cy_cryptolite_utils.c
* \version 2.80
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

void Cy_Cryptolite_String2ByteArray ( uint8_t* p_dst,
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
   for (i = 0 ; i <= len - 1; i++) {
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
        if(nibble_pos != 0u)
        {
            byte |= nibble;
        }
        else
        {
            byte |= nibble << 4U;
        }
         nibble_pos++;
      }
      if (nibble_pos == 2U) {
         p_dst[byte_idx] = byte;
         byte_idx   += 1;
         nibble_pos = 0;
         byte       = 0;
      }
   }

}

cy_en_cryptolite_status_t Cy_Cryptolite_Memcpy(CRYPTOLITE_Type *base, uint8_t* dst,
                        uint8_t* src,
                        uint32_t size)
{
    uint32_t i;
    cy_en_cryptolite_status_t status = CY_CRYPTOLITE_SUCCESS;

    #if (CRYPTOLITE_VU_PRESENT == 1)
    cy_stc_cryptolite_descr_t p_struct;
    uint8_t *srcRemap;

    srcRemap =  (uint8_t *)CY_REMAP_ADDRESS_CRYPTOLITE(src);

    if((((uint32_t)dst & 0x3UL) == 0UL) && (((uint32_t)srcRemap & 0x3UL) == 0UL))
    {
        status = Cy_Cryptolite_Vu_mov_hw(base, &p_struct, dst, CY_CRYPTOLITE_WORD_SIZE_OF_BYTES(size) , srcRemap, CY_CRYPTOLITE_WORD_SIZE_OF_BYTES(size));
    }
    else
    #endif
    {
        (void)base;
        for(i=0; i < size; i++)
        {
            dst[i] = src[i];
        }
    }

    return status;
}


void Cy_Cryptolite_Memset (void  *dest, uint8_t data, uint32_t size)
{
   uint32_t i;
   uint8_t  *dest_P = (uint8_t *)dest;

   for(i=0u; i < size; i++)
   {
      dest_P[i] = data;
   }

}

void Cy_Cryptolite_Setnumber( uint8_t* rdst,
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

uint32_t Cy_Cryptolite_GetCLSAME(uint8_t* src, uint32_t bytesize)
{
    uint32_t clsame = 0u;

    for (uint32_t i = bytesize; i > 0u; i--) {
        uint8_t byte = src[i-1u];
        if (byte == 0u) {
            clsame += 8u;
        } else {
            for (uint32_t j = 8u; j > 0u; j--) {
                if (((uint8_t)byte & (uint8_t)(1u << (j-1u))) != (uint8_t)0u) {
                    clsame += (7u - (uint32_t)(j-1u));
                    return clsame;
                }
            }
        }
    }

    return clsame;
}

#endif /*defined(CY_IP_MXCRYPTOLITE)*/
