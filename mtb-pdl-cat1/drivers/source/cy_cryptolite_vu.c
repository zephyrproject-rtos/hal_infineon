/***************************************************************************//**
* \file cy_cryptolite_vu.h
* \version 2.80
*
* \brief
*  This file provides provides constant and parameters
*  and helper functions of the VU in the Cryptolite driver.
*
********************************************************************************
* Copyright 2020-2021 Cypress Semiconductor Corporation
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

#if defined (CY_IP_MXCRYPTOLITE)

#include "cy_cryptolite_common.h"
#include "cy_cryptolite_vu.h"

#if defined(__cplusplus)
extern "C" {
#endif

#if (CRYPTOLITE_VU_PRESENT == 1)

bool Cy_Cryptolite_Vu_test_zero(CRYPTOLITE_Type *base, cy_stc_cryptolite_descr_t* p_struct, uint8_t *psrc, uint16_t bitsize)
{
    uint32_t* p_a_uint32  = (uint32_t *) ((void *)psrc);
    uint32_t  word;
    (void)p_struct;
    (void)base;

    while (p_a_uint32 < (((uint32_t *) ((void *)psrc)) + VU_BITS_TO_WORDS(bitsize)))
    {
        word  = *p_a_uint32++;
        if (word != 0U){
          return false;
        }
    }
    return true;
}

// returns TRUE if rsrc0 contains the same value as rsrc1. FALSE otherwise
bool Cy_Cryptolite_Vu_test_equal(CRYPTOLITE_Type *base, cy_stc_cryptolite_descr_t* p_struct, uint8_t *rsrc0, uint8_t *rsrc1, uint16_t bitsize)
{
  CY_ALIGN(4) uint8_t temp[VU_BITS_TO_BYTES(VU_TEST_EQUAL_LESS_SIZE)];

  (void)Cy_Cryptolite_Vu_sub_hw(base, p_struct, temp, VU_BITS_TO_WORDS((uint32_t)bitsize), rsrc0, (uint32_t)VU_BITS_TO_WORDS((uint32_t)bitsize), rsrc1, (uint32_t)VU_BITS_TO_WORDS((uint32_t)bitsize));
  Cy_Cryptolite_Vu_wait_hw(base);

  if (Cy_Cryptolite_Vu_test_zero(base, p_struct, temp, VU_BITS_TO_WORDS(bitsize))) {
    return true;
  }
  else {
    return false;
  }
}

// returns TRUE if rsrc0 contains the value less than value of rsrc1. FALSE otherwise
bool Cy_Cryptolite_Vu_test_less_than(CRYPTOLITE_Type *base, cy_stc_cryptolite_descr_t* p_struct, uint8_t *rsrc0, uint8_t *rsrc1, uint16_t bitsize)
{
  CY_ALIGN(4) uint8_t temp[VU_BITS_TO_BYTES(VU_TEST_EQUAL_LESS_SIZE+1U)]={0};
  uint32_t  sign;

  (void)Cy_Cryptolite_Vu_sub_hw (base, p_struct, temp, VU_BITS_TO_WORDS((uint32_t)bitsize+1U), rsrc0, VU_BITS_TO_WORDS((uint32_t)bitsize), rsrc1, VU_BITS_TO_WORDS((uint32_t)bitsize));
  Cy_Cryptolite_Vu_wait_hw (base);

  sign = Cy_Cryptolite_Vu_get_bit(temp, bitsize);

  if (!(bool)sign) {
    return false;
  }
  else {
    return true;
  }
}

void Cy_Cryptolite_Vu_lsl (uint8_t* p_z, uint32_t word_size_z, uint8_t* p_a, uint32_t word_size_a, uint32_t bit_sh)
{
   uint32_t  word_sh     = bit_sh >> 5;
   uint32_t  bit_offset  = bit_sh & 31U;
   uint32_t* p_z_uint32  = (uint32_t *) (void *)p_z;
   uint32_t* p_a_uint32  = (uint32_t *) (void *)p_a;
   uint32_t  saved = 0;
   uint32_t  word;
   (void)word_size_a;
   // To be done.

   while (p_z_uint32 < (((uint32_t *) (void *)p_z) + word_sh)) {
      *p_z_uint32++ = 0;
   }

   while (p_z_uint32 < (((uint32_t *) (void *)p_z) + word_size_z)) {
      word = *p_a_uint32++;
      *p_z_uint32++ = (word <<  bit_offset) | saved;
      saved = (word >> (32U-bit_offset));
   }
}

// "p_z"       must be 32-bit word aligned.
// "word_size" must be not equal to "0"
void Cy_Cryptolite_Vu_clr (uint8_t* p_z, uint32_t word_size)
{
   uint32_t* p_z_uint32 = (uint32_t *) (void *)p_z;
   uint32_t  i          = 0;

   do {
      *p_z_uint32++ = 0;

      i++;
   } while (i < word_size);
}

cy_en_cryptolite_status_t Cy_Cryptolite_Vu_RunInstr(CRYPTOLITE_Type *base,
                            cy_stc_cryptolite_descr_t *p_struct)
{

    REG_CRYPTOLITE_VU_DESCR(base) = (uint32_t)p_struct;
    while((REG_CRYPTOLITE_STATUS(base) & CRYPTOLITE_STATUS_BUSY_Msk) != 0U){};

    if((REG_CRYPTOLITE_INTR_ERROR(base) & CRYPTOLITE_INTR_ERROR_BUS_ERROR_Msk) != 0U)
    {
        REG_CRYPTOLITE_INTR_ERROR(base) = CRYPTOLITE_INTR_ERROR_BUS_ERROR_Msk;
        return CY_CRYPTOLITE_BUS_ERROR;
    }

    return CY_CRYPTOLITE_SUCCESS;
}
#endif /* CPUSS_CRYPTOLITE_VU */

#if defined(__cplusplus)
}
#endif

#endif /* CY_IP_MXCRYPTOLITE */
