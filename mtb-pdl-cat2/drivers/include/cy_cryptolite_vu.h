/***************************************************************************//**
* \file cy_cryptolite_vu.h
* \version 1.40
*
* \brief
* This file provides common constants and parameters for the Cryptolite Vector 
* Unit driver.
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
#if !defined (CY_CRYPTOLITE_VU_H)
#define CY_CRYPTOLITE_VU_H

#include "cy_device.h"

#if (defined (CY_IP_M0S8CRYPTOLITE) && defined(CRYPTOLITE_VU_PRESENT)) || defined (CY_DOXYGEN)

#include "cy_syslib.h"

#if defined(__cplusplus)
extern "C" {
#endif

#include <stddef.h>
#include <stdbool.h>
#include "cy_sysint.h"
#include "cy_cryptolite_common.h"

/**
* \addtogroup group_cryptolite_vu
* \{
* Vector Unit (VU)
*
* Vector unit (VU) component to accelerate asymmetric key cryptography (e.g. RSA and ECC).
* The component supports Large integer multiplication, addition, shift etc.
*
* \defgroup group_cryptolite_vu_macros Macros
* \defgroup group_cryptolite_vu_data_structures Structures
* \defgroup group_cryptolite_vu_functions Functions
*
* */

/**
* \addtogroup group_cryptolite_vu_macros
* \{
*/
/** This macro converts bit count to word size*/
#define VU_BITS_TO_WORDS(bits)             (((bits) + 31UL) >> 5UL)

/** This macro converts bit count to byte size*/
#define VU_BITS_TO_BYTES(bits)             (((bits) + 7UL) >> 3UL)

/** This macro converts bit count to byte size in word aligned*/
#define VU_BITS_TO_BYTES_WORD_ALIGN(bits)  (4UL*(((bits) + 31UL) >> 5UL))

/** This macro converts bytes count to word size*/
#define VU_BYTES_TO_WORDS(bytes)           (((bytes) + 3UL) >> 2UL)

/** \} group_cryptolite_vu_macros */

/**
* \addtogroup group_cryptolite_vu_functions
* \{
*/

/*******************************************************************************
* Function Name: Cy_Cryptolite_Vu_WaitForComplete
****************************************************************************//**
*
* This function waits for the Vector Unit operation complete
*
* \param base
* The pointer to the Cryptolite instance.
*
* \return
* None
*
*******************************************************************************/
ATTRIBUTES_CRYPTOLITE_RSA __STATIC_INLINE void Cy_Cryptolite_Vu_WaitForComplete ( CRYPTOLITE_Type *base )
{
    while((REG_CRYPTOLITE_STATUS(base) & CRYPTOLITE_STATUS_BUSY_Msk) != 0UL) {}
}

/*******************************************************************************
* Function Name: Cy_Cryptolite_Vu_XMul_Hw
****************************************************************************//**
*
* This function performs long integer multiplication operation. This operation
* is a carry-less long integer multiplication operation.
*
* \param base
* The pointer to the Cryptolite instance.
*
* \param val1Ptr
* The pointer to the 1st operand.
*
* \param val1Size
* Length of the first operand in word size.
*
* \param val2Ptr
* The pointer to the 2nd operand.
*
* \param val2Size
* Length of the second operand in word size.
*
* \param result
* The pointer to the output result
*
* \param resultSize
* Length of the output result in word size.
*
* \return
* None
*
* \funcusage
* \snippet cryptolite_sut.c snippet_myCryptoliteVuXmulUse
*******************************************************************************/
ATTRIBUTES_CRYPTOLITE_RSA __STATIC_INLINE void Cy_Cryptolite_Vu_XMul_Hw (
                                CRYPTOLITE_Type *base,
                                uint8_t *val1Ptr,
                                uint32_t val1Size,
                                uint8_t *val2Ptr,
                                uint32_t val2Size,
                                uint8_t *result,
                                uint32_t resultSize)
{
    volatile cy_stc_cryptolite_vu_desc_t desc;

    desc.data0 = (uint32_t) ((CY_CRYPTOLITE_VU_OPCODE_XMUL << CY_CRYPTOLITE_VU_BIT_POS_OPCODE) |
                            ((resultSize - 1UL) << CY_CRYPTOLITE_VU_BIT_POS_DEST_OPERAND) |
                            ((val2Size - 1UL) << CY_CRYPTOLITE_VU_BIT_POS_OPERAND1) |
                            ((val1Size - 1UL) << CY_CRYPTOLITE_VU_BIT_POS_OPERAND0));

    desc.data1 = (uint32_t)val1Ptr;
    desc.data2 = (uint32_t)val2Ptr;
    desc.data3 = (uint32_t)result;

    REG_CRYPTOLITE_VU_DESCR(base) = (uint32_t)&(desc);
}

/*******************************************************************************
* Function Name: Cy_Cryptolite_Vu_Mul_Hw
****************************************************************************//**
*
* This function performs multiplication operation.
*
* \param base
* The pointer to the Cryptolite instance.
*
* \param val1Ptr
* The pointer to the 1st operand.
*
* \param val1Size
* Length of the first operand in word size.
*
* \param val2Ptr
* The pointer to the 2nd operand.
*
* \param val2Size
* Length of the second operand in word size.
*
* \param result
* The pointer to the output result
*
* \param resultSize
* Length of the output result in word size.
*
* \return
* None
*
* \funcusage
* \snippet cryptolite_sut.c snippet_myCryptoliteVuMulUse
*******************************************************************************/
ATTRIBUTES_CRYPTOLITE_RSA __STATIC_INLINE void Cy_Cryptolite_Vu_Mul_Hw (
                            CRYPTOLITE_Type *base,
                            uint8_t *val1Ptr,
                            uint32_t val1Size,
                            uint8_t *val2Ptr,
                            uint32_t val2Size,
                            uint8_t *result,
                            uint32_t resultSize)
{
    volatile cy_stc_cryptolite_vu_desc_t desc;

    desc.data0 = (uint32_t) ((CY_CRYPTOLITE_VU_OPCODE_MUL << CY_CRYPTOLITE_VU_BIT_POS_OPCODE) |
                            ((resultSize - 1UL) << CY_CRYPTOLITE_VU_BIT_POS_DEST_OPERAND) |
                            ((val2Size - 1UL) << CY_CRYPTOLITE_VU_BIT_POS_OPERAND1) |
                            ((val1Size - 1UL) << CY_CRYPTOLITE_VU_BIT_POS_OPERAND0));

    desc.data1 = (uint32_t)val1Ptr;
    desc.data2 = (uint32_t)val2Ptr;
    desc.data3 = (uint32_t)result;

    REG_CRYPTOLITE_VU_DESCR(base) = (uint32_t)&(desc);
}

/*******************************************************************************
* Function Name: Cy_Cryptolite_Vu_Add_Hw
****************************************************************************//**
*
* This function performs addition operation.
*
* \param base
* The pointer to the Cryptolite instance.
*
* \param val1Ptr
* The pointer to the 1st operand.
*
* \param val1Size
* Length of the first operand in word size.
*
* \param val2Ptr
* The pointer to the 2nd operand.
*
* \param val2Size
* Length of the second operand in word size.
*
* \param result
* The pointer to the output result
*
* \param resultSize
* Length of the output result in word size.
*
*
* \return
* None
*
* \funcusage
* \snippet cryptolite_sut.c snippet_myCryptoliteVuAddUse
*******************************************************************************/
ATTRIBUTES_CRYPTOLITE_RSA __STATIC_INLINE void Cy_Cryptolite_Vu_Add_Hw (
                            CRYPTOLITE_Type *base,
                            uint8_t *val1Ptr,
                            uint32_t val1Size,
                            uint8_t *val2Ptr,
                            uint32_t val2Size,
                            uint8_t *result,
                            uint32_t resultSize)
{
    volatile cy_stc_cryptolite_vu_desc_t desc;

    desc.data0 = (uint32_t) ((CY_CRYPTOLITE_VU_OPCODE_ADD << CY_CRYPTOLITE_VU_BIT_POS_OPCODE) |
                            ((resultSize - 1UL) << CY_CRYPTOLITE_VU_BIT_POS_DEST_OPERAND) |
                            ((val2Size - 1UL) << CY_CRYPTOLITE_VU_BIT_POS_OPERAND1) |
                            ((val1Size - 1UL) << CY_CRYPTOLITE_VU_BIT_POS_OPERAND0));

    desc.data1 = (uint32_t)val1Ptr;
    desc.data2 = (uint32_t)val2Ptr;
    desc.data3 = (uint32_t)result;

    REG_CRYPTOLITE_VU_DESCR(base) = (uint32_t)&(desc);
}

/*******************************************************************************
* Function Name: Cy_Cryptolite_Vu_Sub_Hw
****************************************************************************//**
*
* This function performs subtraction operation.
*
* \param base
* The pointer to the Cryptolite instance.
*
* \param val1Ptr
* The pointer to the 1st operand.
*
* \param val1Size
* Length of the first operand.
*
* \param val2Ptr
* The pointer to the 2nd operand.
*
* \param val2Size
* Length of the second operand in word size.
*
* \param result
* The pointer to the output result
*
* \param resultSize
* Length of the output result in word size.
*
* \return
* None
*
* \funcusage
* \snippet cryptolite_sut.c snippet_myCryptoliteVuSubUse
*******************************************************************************/
ATTRIBUTES_CRYPTOLITE_RSA __STATIC_INLINE void Cy_Cryptolite_Vu_Sub_Hw (
                            CRYPTOLITE_Type *base,
                            uint8_t *val1Ptr,
                            uint32_t val1Size,
                            uint8_t *val2Ptr,
                            uint32_t val2Size,
                            uint8_t *result,
                            uint32_t resultSize)
{
    volatile cy_stc_cryptolite_vu_desc_t desc;

    desc.data0 = (uint32_t) ((CY_CRYPTOLITE_VU_OPCODE_SUB << CY_CRYPTOLITE_VU_BIT_POS_OPCODE) |
                            ((resultSize - 1UL) << CY_CRYPTOLITE_VU_BIT_POS_DEST_OPERAND) |
                            ((val2Size - 1UL) << CY_CRYPTOLITE_VU_BIT_POS_OPERAND1) |
                            ((val1Size - 1UL) << CY_CRYPTOLITE_VU_BIT_POS_OPERAND0));

    desc.data1 = (uint32_t)val1Ptr;
    desc.data2 = (uint32_t)val2Ptr;
    desc.data3 = (uint32_t)result;

    REG_CRYPTOLITE_VU_DESCR(base) = (uint32_t)&(desc);
}

/*******************************************************************************
* Function Name: Cy_Cryptolite_Vu_Cond_Sub_Hw
****************************************************************************//**
*
* This function performs conditional subtraction operation.
*
* \param base
* The pointer to the Cryptolite instance.
*
* \param val1Ptr
* The pointer to the 1st operand.
*
* \param val1Size
* Length of the first operand in word size.
*
* \param val2Ptr
* The pointer to the 2nd operand.
*
* \param val2Size
* Length of the second operand in word size.
*
* \param result
* The pointer to the output result
*
* \param resultSize
* Length of the output result in word size.
*
* \return
* None
*
* \funcusage
* \snippet cryptolite_sut.c snippet_myCryptoliteVuCondSubUse
*******************************************************************************/
ATTRIBUTES_CRYPTOLITE_RSA __STATIC_INLINE void Cy_Cryptolite_Vu_Cond_Sub_Hw (
                            CRYPTOLITE_Type *base,
                            uint8_t *val1Ptr,
                            uint32_t val1Size,
                            uint8_t *val2Ptr,
                            uint32_t val2Size,
                            uint8_t *result,
                            uint32_t resultSize)
{
    volatile cy_stc_cryptolite_vu_desc_t desc;

    desc.data0 = (uint32_t) ((CY_CRYPTOLITE_VU_OPCODE_COND_SUB << CY_CRYPTOLITE_VU_BIT_POS_OPCODE) |
                            ((resultSize - 1UL) << CY_CRYPTOLITE_VU_BIT_POS_DEST_OPERAND) |
                            ((val2Size - 1UL) << CY_CRYPTOLITE_VU_BIT_POS_OPERAND1) |
                            ((val1Size - 1UL) << CY_CRYPTOLITE_VU_BIT_POS_OPERAND0));

    desc.data1 = (uint32_t)val1Ptr;
    desc.data2 = (uint32_t)val2Ptr;
    desc.data3 = (uint32_t)result;

    REG_CRYPTOLITE_VU_DESCR(base) = (uint32_t)&(desc);
}

/*******************************************************************************
* Function Name: Cy_Cryptolite_Vu_Xor_Hw
****************************************************************************//**
*
* This function performs XOR operation.
*
* \param base
* The pointer to the Cryptolite instance.
*
* \param val1Ptr
* The pointer to the 1st operand.
*
* \param val1Size
* Length of the first operand in word size.
*
* \param val2Ptr
* The pointer to the 2nd operand.
*
* \param val2Size
* Length of the second operand in word size.
*
* \param result
* The pointer to the output result
*
* \param resultSize
* Length of the output result in word size.
*
* \return
* None
*
* \funcusage
* \snippet cryptolite_sut.c snippet_myCryptoliteVuXorUse
*******************************************************************************/
ATTRIBUTES_CRYPTOLITE_RSA __STATIC_INLINE void Cy_Cryptolite_Vu_Xor_Hw (
                        CRYPTOLITE_Type *base,
                        uint8_t *val1Ptr,
                        uint32_t val1Size,
                        uint8_t *val2Ptr,
                        uint32_t val2Size,
                        uint8_t *result,
                        uint32_t resultSize)
{
    volatile cy_stc_cryptolite_vu_desc_t desc;

    desc.data0 = (uint32_t) ((CY_CRYPTOLITE_VU_OPCODE_XOR << CY_CRYPTOLITE_VU_BIT_POS_OPCODE) |
                            ((resultSize - 1UL) << CY_CRYPTOLITE_VU_BIT_POS_DEST_OPERAND) |
                            ((val2Size - 1UL) << CY_CRYPTOLITE_VU_BIT_POS_OPERAND1) |
                            ((val1Size - 1UL) << CY_CRYPTOLITE_VU_BIT_POS_OPERAND0));

    desc.data1 = (uint32_t)val1Ptr;
    desc.data2 = (uint32_t)val2Ptr;
    desc.data3 = (uint32_t)result;

    REG_CRYPTOLITE_VU_DESCR(base) = (uint32_t)&(desc);
}
/*******************************************************************************
* Function Name: Cy_Cryptolite_Vu_Mov_Hw
****************************************************************************//**
*
* This function performs copy/move operation.
*
* \param base
* The pointer to the Cryptolite instance.
*
* \param srcPtr
* The pointer to the source buffer.
*
* \param srcSize
* Length of the source buffer in word size.
*
* \param dstPtr
* The pointer to destination buffer
*
* \param dstSize
* Length of the destination buffer in word size.
*
* \return
* None
*
* \funcusage
* \snippet cryptolite_sut.c snippet_myCryptoliteVuMovUse
*******************************************************************************/
ATTRIBUTES_CRYPTOLITE_RSA __STATIC_INLINE void Cy_Cryptolite_Vu_Mov_Hw (
                        CRYPTOLITE_Type *base,
                        uint8_t *srcPtr,
                        uint32_t srcSize,
                        uint8_t *dstPtr,
                        uint32_t dstSize)
{
    volatile cy_stc_cryptolite_vu_desc_t desc;

    desc.data0 = (uint32_t) ((CY_CRYPTOLITE_VU_OPCODE_MOV << CY_CRYPTOLITE_VU_BIT_POS_OPCODE) |
                            ((dstSize - 1UL) << CY_CRYPTOLITE_VU_BIT_POS_DEST_OPERAND) |
                            ((srcSize - 1UL) << CY_CRYPTOLITE_VU_BIT_POS_OPERAND0));

    desc.data1 = (uint32_t)srcPtr;
    desc.data3 = (uint32_t)dstPtr;

    REG_CRYPTOLITE_VU_DESCR(base) = (uint32_t)&(desc);
}
/*******************************************************************************
* Function Name: Cy_Cryptolite_Vu_Lsl1_Hw
****************************************************************************//**
*
* This function performs one bit left shift operation.
*
* \param base
* The pointer to the Cryptolite instance.
*
* \param dataPtr
* The pointer to the input data buffer.
*
* \param dataSize
* Length of the input data buffer in word size.
*
* \param dstPtr
* The pointer to destination buffer
*
* \param dstSize
* Length of the destination buffer in word size.
*
* \return
* None
*
* \funcusage
* \snippet cryptolite_sut.c snippet_myCryptoliteVuLsl1Use
*******************************************************************************/
ATTRIBUTES_CRYPTOLITE_RSA __STATIC_INLINE void Cy_Cryptolite_Vu_Lsl1_Hw (
                        CRYPTOLITE_Type *base,
                        uint8_t *dataPtr,
                        uint32_t dataSize,
                        uint8_t *dstPtr,
                        uint32_t dstSize)
{
    volatile cy_stc_cryptolite_vu_desc_t desc;

    desc.data0 = (uint32_t) ((CY_CRYPTOLITE_VU_OPCODE_LSL1 << CY_CRYPTOLITE_VU_BIT_POS_OPCODE) |
                            ((dstSize - 1UL) << CY_CRYPTOLITE_VU_BIT_POS_DEST_OPERAND) |
                            ((dataSize - 1UL) << CY_CRYPTOLITE_VU_BIT_POS_OPERAND0));

    desc.data1 = (uint32_t)dataPtr;
    desc.data3 = (uint32_t)dstPtr;

    REG_CRYPTOLITE_VU_DESCR(base) = (uint32_t)&(desc);
}
/*******************************************************************************
* Function Name: Cy_Cryptolite_Vu_Lsr1_Hw
****************************************************************************//**
*
* This function performs one bit right shift operation.
*
* \param base
* The pointer to the Cryptolite instance.
*
* \param dataPtr
* The pointer to the input data buffer.
*
* \param dataSize
* Length of the input data buffer in word size.
*
* \param dstPtr
* The pointer to destination buffer
*
* \param dstSize
* Length of the destination buffer in word size.
*
* \return
* None
*
* \funcusage
* \snippet cryptolite_sut.c snippet_myCryptoliteVuLsr1Use
*******************************************************************************/
ATTRIBUTES_CRYPTOLITE_RSA __STATIC_INLINE void Cy_Cryptolite_Vu_Lsr1_Hw (
                        CRYPTOLITE_Type *base,
                        uint8_t *dataPtr,
                        uint32_t dataSize,
                        uint8_t *dstPtr,
                        uint32_t dstSize)
{
    volatile cy_stc_cryptolite_vu_desc_t desc;

    desc.data0 = (uint32_t) ((CY_CRYPTOLITE_VU_OPCODE_LSR1 << CY_CRYPTOLITE_VU_BIT_POS_OPCODE) |
                            ((dstSize - 1UL) << CY_CRYPTOLITE_VU_BIT_POS_DEST_OPERAND) |
                            ((dataSize - 1UL) << CY_CRYPTOLITE_VU_BIT_POS_OPERAND0));

    desc.data1 = (uint32_t)dataPtr;
    desc.data3 = (uint32_t)dstPtr;

    REG_CRYPTOLITE_VU_DESCR(base) = (uint32_t)&(desc);
}
/*******************************************************************************
* Function Name: Cy_Cryptolite_Vu_Lsr_Hw
****************************************************************************//**
*
* This function performs left shift by specific given number.
*
* \param base
* The pointer to the Cryptolite instance.
*
* \param dataPtr
* The pointer to the input data buffer.
*
* \param bitShift
* Number of bits to be shifted.
*
* \param dataSize
* Length of the input data buffer in word size.
*
* \param dstPtr
* The pointer to destination buffer
*
* \param dstSize
* Length of the destination buffer in word size.
*
* \return
* None
*
* \funcusage
* \snippet cryptolite_sut.c snippet_myCryptoliteVuLsrUse
*******************************************************************************/
ATTRIBUTES_CRYPTOLITE_RSA __STATIC_INLINE void Cy_Cryptolite_Vu_Lsr_Hw (
                        CRYPTOLITE_Type *base,
                        uint8_t *dataPtr,
                        uint32_t dataSize,
                        uint32_t bitShift,
                        uint8_t *dstPtr,
                        uint32_t dstSize)
{
    volatile cy_stc_cryptolite_vu_desc_t desc;

    desc.data0 = (uint32_t) ((CY_CRYPTOLITE_VU_OPCODE_LSR << CY_CRYPTOLITE_VU_BIT_POS_OPCODE) |
                            ((dstSize - 1UL) << CY_CRYPTOLITE_VU_BIT_POS_DEST_OPERAND) |
                            ((dataSize - 1UL) << CY_CRYPTOLITE_VU_BIT_POS_OPERAND0));

    desc.data1 = (uint32_t)dataPtr;
    desc.data2 = (uint32_t)bitShift;
    desc.data3 = (uint32_t)dstPtr;

    REG_CRYPTOLITE_VU_DESCR(base) = (uint32_t)&(desc);
}

/** \} group_cryptolite_vu_functions */
/** \} group_cryptolite_vu */
#if defined(__cplusplus)
}
#endif

#endif /* (defined (CY_IP_M0S8CRYPTOLITE) && defined(CRYPTOLITE_VU_PRESENT)) || defined (CY_DOXYGEN) */

#endif /* #if !defined (CY_CRYPTOLITE_VU_H) */

/* [] END OF FILE */
