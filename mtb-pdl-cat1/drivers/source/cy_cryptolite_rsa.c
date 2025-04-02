/***************************************************************************//**
* \file cy_cryptolite_rsa.c
* \version 2.80
*
* \brief
*  This file provides provides constant and parameters
*  for the API of the RSA in the Cryptolite driver.
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

#include "cy_cryptolite_vu.h"
#include "cy_cryptolite_rsa.h"
#include "cy_cryptolite_utils.h"

#if defined(__cplusplus)
extern "C" {
#endif

#if (CRYPTOLITE_VU_PRESENT == 1)
#if defined(CY_CRYPTOLITE_CFG_RSA_C)

#define CY_CRYPTOLITE_SHA1_PADDING_SIZE        (15u)
#define CY_CRYPTOLITE_SHA256_512_PADDING_SIZE  (19u)
/* Defines for the SHA algorithm */
/** Hash size for the SHA1 mode (in bytes)   */
#define CY_CRYPTOLITE_SHA1_DIGEST_SIZE          (20u)
/** Hash size for the SHA224 mode (in bytes) */
#define CY_CRYPTOLITE_SHA224_DIGEST_SIZE        (28u)
/** Hash size for the SHA256 mode (in bytes) */
#define CY_CRYPTOLITE_SHA256_DIGEST_SIZE        (32u)
/** Hash size for the SHA384 mode (in bytes) */
#define CY_CRYPTOLITE_SHA384_DIGEST_SIZE        (48u)
/** Hash size for the SHA512 mode (in bytes) */
#define CY_CRYPTOLITE_SHA512_DIGEST_SIZE        (64u)
/** Hash size for the SHA512_224 mode (in bytes) */
#define CY_CRYPTOLITE_SHA512_224_DIGEST_SIZE    (28u)
/** Hash size for the SHA512_256 mode (in bytes) */
#define CY_CRYPTOLITE_SHA512_256_DIGEST_SIZE    (32u)
/** The maximal Hash size for the SHA modes (in bytes). */
#define CY_CRYPTOLITE_SHA_MAX_DIGEST_SIZE       (CY_CRYPTOLITE_SHA512_DIGEST_SIZE)

static void Cy_Cryptolite_Rsa_Mont_Inv_Transform (
                CRYPTOLITE_Type *base,
                cy_stc_cryptolite_context_rsa_t *cfContext,
                uint8_t* p_a,             // bit_size
                uint8_t* p_barrett_u,     // bit_size+1
                uint8_t* p_mont_r_inv,    // bit_size+1
                uint8_t* p_mod,           // bit_size
                uint8_t* p_t1_2n1,        // 2*bit_size+1
                uint8_t* p_t2_2n1,        // 2*bit_size+1
                uint32_t bit_size )
{
   uint32_t    bitsize_p1 = VU_BITS_TO_WORDS(bit_size+1U);
   uint32_t    bitsize    = VU_BITS_TO_WORDS(bit_size);
   cy_stc_cryptolite_descr_t *vu_struct0 = &cfContext->vu_desptr[0U];
   cy_stc_cryptolite_descr_t *vu_struct1 = &cfContext->vu_desptr[1U];

   (void)Cy_Cryptolite_Vu_mul_hw (base, vu_struct0, p_t1_2n1, VU_BITS_TO_WORDS(2U*bit_size), p_a, bitsize, p_mont_r_inv, bitsize);
   (void)Cy_Cryptolite_Vu_lsr_hw (base, vu_struct1, p_a, bitsize, p_t1_2n1, VU_BITS_TO_WORDS(2U*bit_size), bit_size);
   (void)Cy_Cryptolite_Vu_mul_hw (base, vu_struct0, p_t2_2n1, VU_BITS_TO_WORDS(2U*bit_size), p_a, bitsize, p_barrett_u, bitsize_p1);
   (void)Cy_Cryptolite_Vu_lsr_hw (base, vu_struct1, p_a, bitsize, p_t2_2n1, VU_BITS_TO_WORDS(2U*bit_size), bit_size);
   (void)Cy_Cryptolite_Vu_mul_hw (base, vu_struct0, p_t2_2n1, VU_BITS_TO_WORDS(2U*bit_size), p_a, bitsize, p_mod, bitsize);
   (void)Cy_Cryptolite_Vu_sub_hw (base, vu_struct1, p_t1_2n1, VU_BITS_TO_WORDS(bit_size+2U), p_t1_2n1, VU_BITS_TO_WORDS(bit_size+2U), p_t2_2n1, VU_BITS_TO_WORDS(bit_size+2U));
   // Reduction.
   (void)Cy_Cryptolite_Vu_cond_sub_hw (base, vu_struct0, p_t2_2n1, bitsize_p1, p_t1_2n1, VU_BITS_TO_WORDS(bit_size+2U), p_mod, bitsize);
   (void)Cy_Cryptolite_Vu_cond_sub_hw (base, vu_struct1, p_a, bitsize, p_t2_2n1, bitsize_p1, p_mod, bitsize);

   return;
}

static void Cy_Cryptolite_Rsa_Mont_Transform (
            CRYPTOLITE_Type *base,
            cy_stc_cryptolite_context_rsa_t *cfContext,
            uint8_t* p_a,             // bit_size
            uint8_t* p_barrett_u,     // bit_size+1
            uint8_t* p_mod,           // bit_size
            uint8_t* p_t1_2n1,        // 2*bit_size+1
            uint8_t* p_t2_2n1,        // 2*bit_size+1
            uint32_t bit_size )
{
   uint32_t    bitsize_p1 = VU_BITS_TO_WORDS(bit_size+1U);
   uint32_t    bitsize    = VU_BITS_TO_WORDS(bit_size);
   cy_stc_cryptolite_descr_t *vu_struct0 = &cfContext->vu_desptr[0U];
   cy_stc_cryptolite_descr_t *vu_struct1 = &cfContext->vu_desptr[1U];

   (void)Cy_Cryptolite_Vu_lsl ( p_t1_2n1, VU_BITS_TO_WORDS(2U*bit_size), p_a, bitsize, bit_size);

   (void)Cy_Cryptolite_Vu_mul_hw (base, vu_struct0, p_t2_2n1, VU_BITS_TO_WORDS(2U*bit_size), p_a, bitsize, p_barrett_u, bitsize_p1);
   (void)Cy_Cryptolite_Vu_lsr_hw (base, vu_struct1, p_a, bitsize, p_t2_2n1, VU_BITS_TO_WORDS(2U*bit_size), bit_size);
   (void)Cy_Cryptolite_Vu_mul_hw (base, vu_struct0, p_t2_2n1, VU_BITS_TO_WORDS(2U*bit_size), p_a, bitsize, p_mod, bitsize);
   (void)Cy_Cryptolite_Vu_sub_hw (base, vu_struct1, p_t1_2n1, VU_BITS_TO_WORDS(bit_size+2U), p_t1_2n1, VU_BITS_TO_WORDS(bit_size+2U), p_t2_2n1, VU_BITS_TO_WORDS(bit_size+2U));
   // Reduction.
   (void)Cy_Cryptolite_Vu_cond_sub_hw (base, vu_struct0, p_t2_2n1, bitsize_p1, p_t1_2n1, VU_BITS_TO_WORDS(bit_size+2U), p_mod, bitsize);
   (void)Cy_Cryptolite_Vu_cond_sub_hw (base, vu_struct1, p_a, bitsize, p_t2_2n1, bitsize_p1, p_mod, bitsize);

   return;
}

static void Cy_Cryptolite_Rsa_Mont_Mul (
                CRYPTOLITE_Type *base,
                cy_stc_cryptolite_context_rsa_t *cfContext,
                uint8_t* p_z,             //   bit_size
                uint8_t* p_a,             //   bit_size
                uint8_t* p_b,             //   bit_size
                uint8_t* p_mont_mod_der,  //   bit_size
                uint8_t* p_mod,           //   bit_size
                uint8_t* p_t1_2n1,        // 2*bit_size + 1
                uint8_t* p_t2_2n1,        // 2*bit_size + 1
                uint32_t bit_size )
{
   cy_stc_cryptolite_descr_t *vu_struct0 = &cfContext->vu_desptr[0U];
   cy_stc_cryptolite_descr_t *vu_struct1 = &cfContext->vu_desptr[1U];

   uint32_t    bitsize_p1 = VU_BITS_TO_WORDS(bit_size+1U);
   uint32_t    bitsize    = VU_BITS_TO_WORDS(bit_size);

   (void)Cy_Cryptolite_Vu_mul_hw (base, vu_struct0, p_t1_2n1, VU_BITS_TO_WORDS(2U*bit_size), p_a, bitsize, p_b, bitsize);
   (void)Cy_Cryptolite_Vu_mul_hw (base, vu_struct1, p_z, bitsize, p_t1_2n1, bitsize, p_mont_mod_der, bitsize);
   (void)Cy_Cryptolite_Vu_mul_hw (base, vu_struct0, p_t2_2n1, VU_BITS_TO_WORDS(2U*bit_size), p_z, bitsize, p_mod, bitsize);

   (void)Cy_Cryptolite_Vu_add_hw (base, vu_struct1, p_t1_2n1, VU_BITS_TO_WORDS(2U*bit_size+1U), p_t2_2n1, VU_BITS_TO_WORDS(2U*bit_size), p_t1_2n1, VU_BITS_TO_WORDS(2U*bit_size));
   // Reduction.
   (void)Cy_Cryptolite_Vu_cond_sub_hw (base, vu_struct0, p_z, bitsize, &(p_t1_2n1[VU_BITS_TO_BYTES(bit_size)]), bitsize_p1, p_mod, bitsize);

   return;
}

static uint32_t Cy_Cryptolite_Vu_Get_Msb_Bit(cy_stc_cryptolite_context_rsa_t *cfContext, uint8_t* p_z, uint32_t  exp_bit_size);
/*******************************************************************************
* Function Name: Cy_Cryptolite_Vu_Get_Msb_Bit
****************************************************************************//**
*
* Function to calculate the position of the most significant bit set.
*
* \param cfContext
* The pointer to the rsa context.
*
* \param p_z
* The pointer to the data.
*
* \param exp_bit_size
* The size of the data .
*
* \return
*  The position of the most significant bit set.
*
*******************************************************************************/
 static uint32_t Cy_Cryptolite_Vu_Get_Msb_Bit(cy_stc_cryptolite_context_rsa_t *cfContext, uint8_t* p_z, uint32_t  exp_bit_size)
{

   uint32_t i=0u;
   uint32_t total_bit_processed = 0u;
   uint32_t exp_byte_align_size  = 0u;
   uint32_t exp_word_align_size  = 0u;
   uint32_t bit_offset = 0u;

   exp_byte_align_size =  CY_CRYPTOLITE_BYTE_SIZE_OF_BITS(exp_bit_size);
   exp_word_align_size = VU_BITS_TO_WORDS(exp_bit_size);
   CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 11.3','Intentional pointer type conversion');
   uint32_t * exp_ptr = (uint32_t *)cfContext->p_buffer;

   Cy_Cryptolite_Vu_clr ((uint8_t*) exp_ptr, VU_BYTES_TO_WORDS(CY_CRYPTOLITE_RSA_BUFFER_SIZE));
   Cy_Cryptolite_Setnumber((uint8_t *)exp_ptr, p_z, exp_byte_align_size);
   exp_ptr += exp_word_align_size;

   for(i=0u; i<exp_word_align_size; i++)
   {
      exp_ptr--;

     CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 10.3','signed 32-bit int" to different or narrower essential type "unsigned 32-bit int');
      if((bit_offset = __CLZ(*exp_ptr)) != 32u)
      {
          total_bit_processed += bit_offset;

          return (exp_word_align_size * 32u) - total_bit_processed;
      }

      total_bit_processed += 32u;
   }

    return 0u;
}

static void Cy_Cryptolite_Rsa_Exp (
                CRYPTOLITE_Type *base,
                cy_stc_cryptolite_context_rsa_t *cfContext,
                uint8_t* p_z,             //   bit_size
                const uint8_t* p_a,       //   bit_size
                uint8_t* p_exp,           //   exp_bit_size
                uint8_t* p_barrett_u,     //   bit_size + 1
                uint8_t* p_mont_r_inv,    //   bit_size + 1      to allow for the addition
                uint8_t* p_mont_mod_der,  //   bit_size
                uint8_t* p_mod,           //   bit_size
                uint8_t* p_buffer,        // (2*bit_size + 1) + (2*bit_size + 1) + bit_size
                uint32_t bit_size,        // support 1024, 2048, 3072, 4096
                uint32_t exp_bit_size )   // most significant bit assumed to be '1'
{
   int         i;
   uint8_t*    p;
   uint8_t*    p_local_z = p_z;
   uint8_t*    p_t1_2n1  = &p_buffer[0U];
   uint8_t*    p_t2_2n1  = &p_buffer[4U*VU_BITS_TO_WORDS(2U*bit_size+1U)];
   uint8_t*    p_t3_n    = &p_buffer[4U*VU_BITS_TO_WORDS(2U*bit_size+1U) + 4U*VU_BITS_TO_WORDS(2U*bit_size+1U)];
   uint8_t*    p_msg     = &p_buffer[4U*VU_BITS_TO_WORDS(2U*bit_size+1U) + 4U*VU_BITS_TO_WORDS(2U*bit_size+1U) + 4U*VU_BITS_TO_WORDS(bit_size)];
 
   uint32_t    bitsize    = VU_BITS_TO_WORDS(bit_size);
   cy_stc_cryptolite_descr_t *vu_struct0 = &cfContext->vu_desptr[0U];
   cy_stc_cryptolite_descr_t *vu_struct1 = &cfContext->vu_desptr[1U];

   exp_bit_size = Cy_Cryptolite_Vu_Get_Msb_Bit(cfContext, p_exp, exp_bit_size);

   (void)Cy_Cryptolite_Vu_mov_hw (base, vu_struct0, p_msg, bitsize, (uint8_t*)p_a, bitsize);

   Cy_Cryptolite_Rsa_Mont_Transform (base, cfContext, p_msg, p_barrett_u, p_mod, p_t1_2n1, p_t2_2n1, bit_size);

   (void)Cy_Cryptolite_Vu_mov_hw (base, vu_struct0, p_z, bitsize, p_msg, bitsize);


   if (exp_bit_size != 1U) {
      for (i = ((int)exp_bit_size-2); i >= 0; i--) {
         Cy_Cryptolite_Rsa_Mont_Mul (base, cfContext, p_t3_n, p_z, p_z, p_mont_mod_der, p_mod, p_t1_2n1, p_t2_2n1, bit_size);

         if ((bool)Cy_Cryptolite_Vu_get_bit (p_exp, (uint32_t)i)){
            Cy_Cryptolite_Rsa_Mont_Mul (base, cfContext, p_z, p_t3_n, p_msg, p_mont_mod_der, p_mod, p_t1_2n1, p_t2_2n1, bit_size);
         }else {
            p = p_t3_n; p_t3_n = p_z; p_z = p;                  // swap
         }
      }

      if (p_local_z != p_z) {
         (void)Cy_Cryptolite_Vu_mov_hw (base, vu_struct1, p_local_z, bitsize, p_z, bitsize);
      }
   }

   Cy_Cryptolite_Rsa_Mont_Inv_Transform (base, cfContext, p_local_z, p_barrett_u, p_mont_r_inv, p_mod, p_t1_2n1, p_t2_2n1, bit_size);
}

static void Cy_Cryptolite_Rsa_Coeff (
                CRYPTOLITE_Type *base,
                cy_stc_cryptolite_context_rsa_t *cfContext,
                uint8_t* p_barrett_u,     // bit_size + 1
                uint8_t* p_mont_r_inv,    // bit_size + 1      to allow for the addition
                uint8_t* p_mont_mod_der,  // bit_size
                uint8_t* p_mod,           // bit_size
                uint8_t* p_buffer,        // (bit_size + 1) + (bit_size + 1)
                uint32_t bit_size )
{
   int         i;
   uint8_t*    p;
   uint32_t    sign;
   bool    even;
   uint32_t    bitsize_p1 = VU_BITS_TO_WORDS(bit_size+1U);
   uint32_t    bitsize    = VU_BITS_TO_WORDS(bit_size);
   uint8_t*    p_t1_n1    = &p_buffer[0U];
   uint8_t*    p_t2_n1    = &p_buffer[4U*bitsize_p1];
   uint8_t*    p_dividend = p_t1_n1;

   cy_stc_cryptolite_descr_t *vu_struct0 = &cfContext->vu_desptr[0U];
   cy_stc_cryptolite_descr_t *vu_struct1 = &cfContext->vu_desptr[1U];

   Cy_Cryptolite_Vu_clr     (p_dividend, bitsize_p1 );
   Cy_Cryptolite_Vu_set_bit (p_dividend, bit_size);
   Cy_Cryptolite_Vu_clr     (p_barrett_u, bitsize_p1);

   Cy_Cryptolite_Vu_clr     (p_mont_r_inv, bitsize_p1);
   Cy_Cryptolite_Vu_set_bit (p_mont_r_inv, 0U);
   Cy_Cryptolite_Vu_clr     (p_mont_mod_der, bitsize);

   // Barrett "barrett_u[bit_size]",

   (void)Cy_Cryptolite_Vu_sub_hw  (base, vu_struct0, p_dividend, bitsize_p1, p_dividend, bitsize_p1, p_mod, bitsize);

   Cy_Cryptolite_Vu_set_bit (p_barrett_u, bit_size);

   Cy_Cryptolite_Vu_wait_hw (base);
   Cy_Cryptolite_Vu_clr_bit (p_dividend, bit_size);                           // drop top bit
   (void)Cy_Cryptolite_Vu_lsl1_hw (base, vu_struct1, p_dividend, bitsize_p1, p_dividend, bitsize_p1);

   for (i = ((int)bit_size-1); i >= 0; i--)
   {
      (void)Cy_Cryptolite_Vu_sub_hw  (base, vu_struct0, p_t2_n1, bitsize_p1, p_dividend, bitsize_p1, p_mod, bitsize);
      (void)Cy_Cryptolite_Vu_lsr1_hw (base, vu_struct1, p_mont_mod_der, bitsize, p_mont_mod_der, bitsize);

      even = Cy_Cryptolite_Vu_test_even (p_mont_r_inv);

      if (even)
      {
            (void)Cy_Cryptolite_Vu_lsr1_hw (base, vu_struct0, p_mont_r_inv, bitsize,   p_mont_r_inv, bitsize);
      }
      else
      {
            (void)Cy_Cryptolite_Vu_add_hw  (base, vu_struct0, p_mont_r_inv, bitsize_p1, p_mont_r_inv, bitsize, p_mod, bitsize); // needs extra bit
            (void)Cy_Cryptolite_Vu_lsr1_hw (base, vu_struct1, p_mont_r_inv, bitsize_p1, p_mont_r_inv, bitsize_p1);
            Cy_Cryptolite_Vu_set_bit (p_mont_mod_der, bit_size-1U);
      }

      sign = Cy_Cryptolite_Vu_get_bit (p_t2_n1, bit_size);  // sign = (dividend < mod)

      if (!(bool)sign) {
         Cy_Cryptolite_Vu_set_bit (p_barrett_u, (uint32_t)i);
         p = p_t2_n1; p_t2_n1 = p_dividend; p_dividend = p; // swap
      }

      Cy_Cryptolite_Vu_clr_bit (p_dividend, bit_size);   // drop top bit
      (void)Cy_Cryptolite_Vu_lsl1_hw (base, vu_struct0, p_dividend, bitsize_p1, p_dividend, bitsize_p1);
   }
}

/*******************************************************************************
* Function Name: Cy_Cryptolite_Rsa_Init
****************************************************************************//*
*
* Initialize the RSA context.
*
* \param base
* The pointer to the CRYPTOLITE instance.
*
* \param cfContext
* The pointer to the CRYPTOLITE context.
*
* \param rsaBuffers
* The pointer to the RSA buffers.
*
* \return
* \ref cy_en_cryptolite_status_t
*
*******************************************************************************/
cy_en_cryptolite_status_t Cy_Cryptolite_Rsa_Init(CRYPTOLITE_Type *base,
                                              cy_stc_cryptolite_context_rsa_t *cfContext,
                                              cy_stc_cryptolite_rsa_buffer_t *rsaBuffers)
{
    cy_en_cryptolite_status_t status = CY_CRYPTOLITE_SUCCESS;
    uint32_t address_offset=0u;

    if (base == NULL || cfContext == NULL || rsaBuffers == NULL)
    {
        return CY_CRYPTOLITE_BAD_PARAMS;
    }

    /*Aligning the buffer address by 4 bytes*/
    if(((uint32_t)rsaBuffers & 0x03U) != 0u)
    {
        address_offset = 4u - ((uint32_t)rsaBuffers & 0x03U);
    }
 
    cfContext->p_buffer = (uint8_t*)((cy_stc_cryptolite_rsa_buffer_t *)((uint32_t)rsaBuffers + address_offset))->p_buffer;
    return status;
}

/*******************************************************************************
* Function Name: Cy_Cryptolite_Rsa_Free
****************************************************************************//*
*
* Cleanup the RSA context.
*
* \param base
* The pointer to the CRYPTOLITE instance.
*
* \param cfContext
* The pointer to the CRYPTOLITE context.
*
* \return
* \ref cy_en_cryptolite_status_t
*
*******************************************************************************/
cy_en_cryptolite_status_t Cy_Cryptolite_Rsa_Free(CRYPTOLITE_Type *base,
                                              cy_stc_cryptolite_context_rsa_t *cfContext)
{
    cy_en_cryptolite_status_t status = CY_CRYPTOLITE_SUCCESS;
    (void)base;

    if (base == NULL || cfContext == NULL)
    {
        return CY_CRYPTOLITE_BAD_PARAMS;
    }

    Cy_Cryptolite_Vu_clr((uint8_t*)cfContext->vu_desptr, (sizeof(cy_stc_cryptolite_descr_t) *2U)/4U);

    if(cfContext->p_buffer != NULL)
    {
        Cy_Cryptolite_Vu_clr(cfContext->p_buffer, CY_CRYPTOLITE_RSA_BUFFER_SIZE/4u);
        cfContext->p_buffer = NULL;
    }

    return status;
}

/*******************************************************************************
* Function Name: Cy_Cryptolite_Core_Rsa_Proc
****************************************************************************//*
*
* RSA process algorithm based on the Montgomery algorithm
* using Barrett reduction
*
* https://en.wikipedia.org/wiki/RSA_%28cryptosystem%29
*
* Key, message, processedMessage  buffers must be 4 byte aligned and end with 4 byte boundary.
*
* \param base
* The pointer to the CRYPTOLITE instance.
*
* \param cfContext
* The pointer to the CRYPTOLITE context.
*
* \param key
* The pointer to the \ref cy_stc_cryptolite_rsa_pub_key_t structure that stores
* public key.
*
* \param message
* The pointer to the message to be processed.
*
* \param messageSize
* The length of the message to be processed.
*
* \param processedMessage
* The pointer to processed message.
*
* \return
* \ref cy_en_cryptolite_status_t
*
*******************************************************************************/
cy_en_cryptolite_status_t Cy_Cryptolite_Rsa_Proc(CRYPTOLITE_Type *base,
                                              cy_stc_cryptolite_context_rsa_t *cfContext,
                                              cy_stc_cryptolite_rsa_pub_key_t *key,
                                              uint8_t const *message,
                                              uint32_t messageSize,
                                              uint8_t *processedMessage)
{
    cy_en_cryptolite_status_t status = CY_CRYPTOLITE_SUCCESS;
    (void)messageSize;

    uint8_t *barretCoefPtrRemap;
    uint8_t *inverseModuloPtrRemap;
    uint8_t *rBarPtrRemap;
    uint8_t *moduloPtrRemap;
    uint8_t *pubExpPtrRemap;
    uint8_t *messagePtrRemap;

    barretCoefPtrRemap =  (uint8_t *)CY_REMAP_ADDRESS_CRYPTOLITE(key->barretCoefPtr);
    inverseModuloPtrRemap =  (uint8_t *)CY_REMAP_ADDRESS_CRYPTOLITE(key->inverseModuloPtr);
    rBarPtrRemap =  (uint8_t *)CY_REMAP_ADDRESS_CRYPTOLITE(key->rBarPtr);
    moduloPtrRemap =  (uint8_t *)CY_REMAP_ADDRESS_CRYPTOLITE(key->moduloPtr);
    pubExpPtrRemap =  (uint8_t *)CY_REMAP_ADDRESS_CRYPTOLITE(key->pubExpPtr);
    messagePtrRemap =  (uint8_t *)CY_REMAP_ADDRESS_CRYPTOLITE(message);

    if(key->preCalculatedCoeff == false)
    {      
        Cy_Cryptolite_Rsa_Coeff(base, cfContext, barretCoefPtrRemap, inverseModuloPtrRemap, rBarPtrRemap, moduloPtrRemap, cfContext->p_buffer, key->moduloLength);
        key->preCalculatedCoeff = true;
    }

    Cy_Cryptolite_Rsa_Exp(base, cfContext, processedMessage, messagePtrRemap, pubExpPtrRemap, barretCoefPtrRemap, inverseModuloPtrRemap, rBarPtrRemap, moduloPtrRemap, cfContext->p_buffer, key->moduloLength, key->pubExpLength);

    return status;
}

/*******************************************************************************
* Function Name: Cy_Cryptolite_Rsa_Coef
****************************************************************************//*
*
* Calculation constant coefficients to speed-up Montgomery algorithm.
* These coefficients are:
*                         coefficient for Barrett reduction,
*                         binary inverse of the modulo,
*                         result of (2^moduloLength mod modulo)
*
* \param base
* The pointer to the CRYPTOLITE instance.
*
* \param cfContext
* The pointer to the CRYPTOLITE context.
*
* \param key
* The pointer to the \ref cy_stc_cryptolite_rsa_pub_key_t structure that stores a
* public key.
*
* \return
* \ref cy_en_cryptolite_status_t
*
*******************************************************************************/
cy_en_cryptolite_status_t Cy_Cryptolite_Rsa_Coef(CRYPTOLITE_Type *base,
                                              cy_stc_cryptolite_context_rsa_t *cfContext,
                                              cy_stc_cryptolite_rsa_pub_key_t *key)
{
    cy_en_cryptolite_status_t status = CY_CRYPTOLITE_SUCCESS;

    uint8_t *barretCoefPtrRemap;
    uint8_t *inverseModuloPtrRemap;
    uint8_t *rBarPtrRemap;
    uint8_t *moduloPtrRemap;

    if((NULL == key->barretCoefPtr) || (NULL == key->inverseModuloPtr) || (NULL == key->rBarPtr) || (NULL == key->moduloPtr) || (NULL == cfContext))
    {
       return  CY_CRYPTOLITE_BAD_PARAMS;
    }


    barretCoefPtrRemap =  (uint8_t *)CY_REMAP_ADDRESS_CRYPTOLITE(key->barretCoefPtr);
    inverseModuloPtrRemap =  (uint8_t *)CY_REMAP_ADDRESS_CRYPTOLITE(key->inverseModuloPtr);
    rBarPtrRemap =  (uint8_t *)CY_REMAP_ADDRESS_CRYPTOLITE(key->rBarPtr);
    moduloPtrRemap =  (uint8_t *)CY_REMAP_ADDRESS_CRYPTOLITE(key->moduloPtr);

    Cy_Cryptolite_Rsa_Coeff(base, cfContext, barretCoefPtrRemap, inverseModuloPtrRemap, rBarPtrRemap, moduloPtrRemap, cfContext->p_buffer, key->moduloLength);

    key->preCalculatedCoeff = true;

    return status;
}

/*******************************************************************************
* Function Name: Cy_Cryptolite_Rsa_Verify
****************************************************************************//*
*
* RSA verification with checks for content, paddings and signature format.
* SHA digest of the message and decrypted message should be calculated before.
* Supports only PKCS1-v1_5 format, inside of this format supported padding
* using only SHA, cases with MD2 and MD5 are not supported.
* PKCS1-v1_5 described here, page 31:
* http://www.emc.com/collateral/white-papers/h11300-pkcs-1v2-2-rsa-cryptography-standard-wp.pdf
*
* The digest and decryptedSignature buffers must be 4 byte aligned
*
* Returns the verification result \ref cy_en_cryptolite_sig_verify_result_t.
*
* \param base
* The pointer to the CRYPTOLITE instance.
*
* \param cfContext
* The pointer to the CRYPTOLITE context.
*
* \param verResult
* The pointer to the verification result \ref cy_en_cryptolite_sig_verify_result_t.
*
* \param digestType
* SHA mode used for hash calculation \ref cy_en_cryptolite_sha_mode_t.
*
* \param digest
* The pointer to the hash of the message or the message whose signature is to be verified.
*
* \param digestLength
* The length of the message whose signature is to be verified and is applicable for CY_CRYPTOLITE_MODE_SHA_NONE mode.
*
* \param decryptedSignature
* The pointer to the decrypted signature to be verified.
*
* \param decryptedSignatureLength
* The length of the decrypted signature to be verified (in bytes)
*
* \return
* \ref cy_en_cryptolite_status_t
*
*******************************************************************************/
#ifdef CY_CRYPTOLITE_CFG_RSA_VERIFY_ENABLED
cy_en_cryptolite_status_t Cy_Cryptolite_Rsa_Verify(CRYPTOLITE_Type *base,
                            cy_stc_cryptolite_context_rsa_t *cfContext,
                            cy_en_cryptolite_sig_verify_result_t *verResult,
                            cy_en_cryptolite_sha_mode_t digestType,
                            uint8_t const *digest,
                            uint32_t digestLength,
                            uint8_t const *decryptedSignature,
                            uint32_t decryptedSignatureLength)
{
    cy_en_cryptolite_status_t tmpResult = CY_CRYPTOLITE_SUCCESS;
    (void)base;
    (void)cfContext;

    uint8_t *digestRemap;
    uint8_t *decryptedSignatureRemap;

    digestRemap =  (uint8_t *)CY_REMAP_ADDRESS_CRYPTOLITE(digest);
    decryptedSignatureRemap =  (uint8_t *)CY_REMAP_ADDRESS_CRYPTOLITE(decryptedSignature);

    /* Encodings for hash functions */

#ifdef CY_CRYPTOLITE_CFG_RSA_VERIFY_SHA1
    static const uint8_t sha1EncStr[CY_CRYPTOLITE_SHA1_PADDING_SIZE] =
    {
        0x30u, 0x21u, 0x30u, 0x09u, 0x06u, 0x05u, 0x2Bu, 0x0Eu,
        0x03u, 0x02u, 0x1Au, 0x05u, 0x00u, 0x04u, 0x14u
    };
#endif /* #if (CY_CRYPTOLITE_CFG_RSA_VERIFY_SHA1 == 1) */

#ifdef CY_CRYPTOLITE_CFG_RSA_VERIFY_SHA256
    static const uint8_t sha224EncStr[CY_CRYPTOLITE_SHA256_512_PADDING_SIZE] =
    {
        0x30u, 0x2Du, 0x30u, 0x0Du, 0x06u, 0x09u, 0x60u, 0x86u,
        0x48u, 0x01u, 0x65u, 0x03u, 0x04u, 0x02u, 0x04u, 0x05u,
        0x00u, 0x04u, 0x1Cu
    };

    static const uint8_t sha256EncStr[CY_CRYPTOLITE_SHA256_512_PADDING_SIZE] =
    {
        0x30u, 0x31u, 0x30u, 0x0Du, 0x06u, 0x09u, 0x60u, 0x86u,
        0x48u, 0x01u, 0x65u, 0x03u, 0x04u, 0x02u, 0x01u, 0x05u,
        0x00u, 0x04u, 0x20u
    };
#endif /* #if (CY_CRYPTOLITE_CFG_RSA_VERIFY_SHA256 == 1) */

#ifdef CY_CRYPTOLITE_CFG_RSA_VERIFY_SHA512
    static const uint8_t sha384EncStr[CY_CRYPTOLITE_SHA256_512_PADDING_SIZE] =
    {
        0x30u, 0x41u, 0x30u, 0x0Du, 0x06u, 0x09u, 0x60u, 0x86u,
        0x48u, 0x01u, 0x65u, 0x03u, 0x04u, 0x02u, 0x02u, 0x05u,
        0x00u, 0x04u, 0x30u
    };

    static const uint8_t sha512EncStr[CY_CRYPTOLITE_SHA256_512_PADDING_SIZE] =
    {
        0x30u, 0x51u, 0x30u, 0x0Du, 0x06u, 0x09u, 0x60u, 0x86u,
        0x48u, 0x01u, 0x65u, 0x03u, 0x04u, 0x02u, 0x03u, 0x05u,
        0x00u, 0x04u, 0x40u
    };

    static const uint8_t sha512_224EncStr[CY_CRYPTOLITE_SHA256_512_PADDING_SIZE] =
    {
        0x30u, 0x2Du, 0x30u, 0x0Du, 0x06u, 0x09u, 0x60u, 0x86u,
        0x48u, 0x01u, 0x65u, 0x03u, 0x04u, 0x02u, 0x05u, 0x05u,
        0x00u, 0x04u, 0x1Cu
    };

    static const uint8_t sha512_256EncStr[CY_CRYPTOLITE_SHA256_512_PADDING_SIZE] =
    {
        0x30u, 0x31u, 0x30u, 0x0Du, 0x06u, 0x09u, 0x60u, 0x86u,
        0x48u, 0x01u, 0x65u, 0x03u, 0x04u, 0x02u, 0x06u, 0x05u,
        0x00u, 0x04u, 0x20u
    };
#endif /* #if (CY_CRYPTOLITE_CFG_RSA_VERIFY_SHA512 == 1) */

    uint8_t  const *encodingArr = NULL;
    uint32_t encodingArrSize = 0u;
    uint32_t locDigestSize = 0u;
    uint32_t i;
    uint32_t psLength;
    uint32_t cmpRes = 0u;


    switch (digestType)
    {

#ifdef CY_CRYPTOLITE_CFG_RSA_VERIFY_SHA1
    case CY_CRYPTOLITE_MODE_SHA1:
        encodingArr = sha1EncStr;
        encodingArrSize = sizeof(sha1EncStr);
        locDigestSize = CY_CRYPTOLITE_SHA1_DIGEST_SIZE;
        break;
#endif /* #if (CY_CRYPTOLITE_CFG_RSA_VERIFY_SHA1 == 1) */

#ifdef CY_CRYPTOLITE_CFG_RSA_VERIFY_SHA256
    case CY_CRYPTOLITE_MODE_SHA224:
        encodingArr = sha224EncStr;
        encodingArrSize = sizeof(sha224EncStr);
        locDigestSize = CY_CRYPTOLITE_SHA224_DIGEST_SIZE;
        break;

    case CY_CRYPTOLITE_MODE_SHA256:
        encodingArr = sha256EncStr;
        encodingArrSize = sizeof(sha256EncStr);
        locDigestSize = CY_CRYPTOLITE_SHA256_DIGEST_SIZE;
        break;
#endif /* #if (CY_CRYPTOLITE_CFG_RSA_VERIFY_SHA256 == 1) */

#ifdef CY_CRYPTOLITE_CFG_RSA_VERIFY_SHA512
    case CY_CRYPTOLITE_MODE_SHA384:
        encodingArr = sha384EncStr;
        encodingArrSize = sizeof(sha384EncStr);
        locDigestSize = CY_CRYPTOLITE_SHA384_DIGEST_SIZE;
        break;

    case CY_CRYPTOLITE_MODE_SHA512:
        encodingArr = sha512EncStr;
        encodingArrSize = sizeof(sha512EncStr);
        locDigestSize = CY_CRYPTOLITE_SHA512_DIGEST_SIZE;
        break;

    case CY_CRYPTOLITE_MODE_SHA512_224:
        encodingArr  = sha512_224EncStr;
        encodingArrSize = sizeof(sha512_224EncStr);
        locDigestSize      = CY_CRYPTOLITE_SHA512_224_DIGEST_SIZE;
        break;

    case CY_CRYPTOLITE_MODE_SHA512_256:
        encodingArr = sha512_256EncStr;
        encodingArrSize = sizeof(sha512_256EncStr);
        locDigestSize = CY_CRYPTOLITE_SHA512_256_DIGEST_SIZE;
        break;
#endif /* #if (CY_CRYPTOLITE_CFG_RSA_VERIFY_SHA512 == 1) */
    case CY_CRYPTOLITE_MODE_SHA_NONE:
        encodingArr = NULL;
        encodingArrSize = 0U;
        locDigestSize = digestLength;
        break;
    default:
    /* Unknown Digest Type */
        break;
    }

    /* Fail by default */
    *verResult = CY_CRYPTOLITE_SIG_INVALID;

    if (CY_CRYPTOLITE_MODE_SHA_NONE != digestType)
    {
        /* Check size of decrypted message */
        if (decryptedSignatureLength < (encodingArrSize + locDigestSize + 11u))
        {
            cmpRes = 1u;  /* further checking is not needed */
        }
    }

    psLength = decryptedSignatureLength - locDigestSize - encodingArrSize - 3u;

    /* Check whether the begin of message is 0x00, 0x01 and after PS string (before T string) is 0x00 byte.*/
    if ( (0u != cmpRes) ||
         (0x00u != *(decryptedSignatureRemap)) ||
         (0x01u != *(decryptedSignatureRemap + 1u)) ||
         (0x00u != *(decryptedSignatureRemap + psLength + 2u)) )
    {
        cmpRes = 1u;  /* Further checking is not needed */
    }

    /* Check FFs */
    if (0u == cmpRes )
    {
        for (i = 0u; i < psLength; i++)
        {
            if (0xFFu != *(decryptedSignatureRemap + 2u + i))
            {
                cmpRes = 1u;  /* Further checking is not needed */
                break;
            }
        }
    }

    if (CY_CRYPTOLITE_MODE_SHA_NONE != digestType)
    {
        /* Check the padding (T string) */
        if (0u == cmpRes)
        {
            cmpRes = Cy_Cryptolite_Vu_memcmp(encodingArr,
                            (decryptedSignatureRemap + psLength + 3u),
                            (uint16_t)encodingArrSize);
        }
    }

    /* Check the digest */
    if (0u == cmpRes)
    {
        cmpRes = Cy_Cryptolite_Vu_memcmp(digestRemap,
                        (decryptedSignatureRemap + (decryptedSignatureLength - locDigestSize)),
                        (uint16_t)locDigestSize);
    }

    if (0u == cmpRes )
    {
        *verResult = CY_CRYPTOLITE_SIG_VALID;
    }

    return (tmpResult);
}
#endif /* CY_CRYPTOLITE_CFG_RSA_VERIFY_ENABLED */

#endif  /*#if defined(CY_CRYPTOLITE_CFG_RSA_C)*/
#endif  /*#if (CPUSS_CRYPTOLITE_VU == 1)*/

#if defined(__cplusplus)
}
#endif

#endif /* CY_IP_MXCRYPTOLITE */
