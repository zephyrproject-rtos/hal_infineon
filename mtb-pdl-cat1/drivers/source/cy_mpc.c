/***************************************************************************//**
* \file  cy_mpc.c
* \version 1.1
*
* \brief
* Provides an API implementation of the secure MPC driver.
*
********************************************************************************
* \copyright
* Copyright 2016-2019 Cypress Semiconductor Corporation
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

#include "cy_device.h"

#if defined (CY_IP_M33SYSCPUSS)

#include "cy_mpc.h"

/** rot: Number of blocks per index */
#define CY_MPC_ROT_BLOCKS_PER_IDX       (8UL)
/** rot: Number of bits used to configure attributes of a block */
#define CY_MPC_ROT_BLOCK_BIT_COUNT      (4UL)
/** rot: Mask of block attribute */
#define CY_MPC_ROT_BLOCK_MASK           (0x00000007UL)
/** rot: Mask of Read bit */
#define CY_MPC_ROT_READ_MASK            (0x00000002UL)
/** rot: Mask of Write bit */
#define CY_MPC_ROT_WRITE_MASK           (0x00000004UL)
/** rot: Mask of Security bit */
#define CY_MPC_NS_MASK                  (0x00000001UL)
/** Number of blocks per index */
#define CY_MPC_BLOCKS_PER_IDX           (32UL)
/** Number of bits used to configure attributes of a block */
#define CY_MPC_BLOCK_BIT_COUNT          (1UL)
/** Mask of Security bit */
#define CY_MPC_BLOCK_MASK               (0x00000001UL)
/** Init in progress check timeout value */
#define CY_MPC_INIT_IN_PROG_TIMEOUT     (10UL)

/*******************************************************************************
* Function Name: _Cy_Mpc_CheckRotInitInProgress
****************************************************************************//**
*
* \brief Checks the INIT_IN_PROGRESS bit within the ROT_BLK_CFG register
* to see if SMIF is enabled.
*
*
* \param base
* Base address of mpc being configured
*
* \return
* Check status
*
*******************************************************************************/
__STATIC_INLINE cy_en_mpc_status_t _Cy_Mpc_CheckRotInitInProgress(MPC_Type* base)
{
    // Check if initialization is still in progress
    uint32_t timeout = 0UL;
    while (((base->ROT_BLK_CFG) & (RAMC_MPC_ROT_BLK_CFG_INIT_IN_PROGRESS_Msk)) != 0UL)
    {
        if (timeout == CY_MPC_INIT_IN_PROG_TIMEOUT)
        {
            return CY_MPC_INVALID_STATE;
        }
        else
        {
            Cy_SysLib_Delay(1);
            timeout++;
        }
    }
    return CY_MPC_SUCCESS;
}

/*******************************************************************************
* Function Name: _Cy_Mpc_CheckInitInProgress
****************************************************************************//**
*
* \brief Checks the INIT_IN_PROGRESS bit within the BLK_CFG register
* to see if SMIF is enabled.
*
*
* \param base
* Base address of mpc being configured
*
* \return
* Check status
*
*******************************************************************************/
__STATIC_INLINE cy_en_mpc_status_t _Cy_Mpc_CheckInitInProgress(MPC_Type* base)
{
    // Check if initialization is still in progress
    uint32_t timeout = 0UL;
    while (((base->BLK_CFG) & (RAMC_MPC_BLK_CFG_INIT_IN_PROGRESS_Msk)) != 0UL)
    {
        if (timeout == CY_MPC_INIT_IN_PROG_TIMEOUT)
        {
            return CY_MPC_INVALID_STATE;
        }
        else
        {
            Cy_SysLib_Delay(1);
            timeout++;
        }
    }
    return CY_MPC_SUCCESS;
}

/*******************************************************************************
* Function Name: Cy_Mpc_ConfigRotMpcStruct
****************************************************************************//**
*
* \brief Initializes the referenced mpc by setting the PC, NS/S and RW/R/W
* permissions. This is called by ROT module.
*
*
* \param base
* Base address of mpc being configured
*
* \param rotConfig
* MPC configuration structure to be used by the ROT code
*
* \return
* Initialization status
*
*******************************************************************************/
cy_en_mpc_status_t Cy_Mpc_ConfigRotMpcStruct(MPC_Type* base, const cy_stc_mpc_rot_cfg_t* rotConfig)
{
    uint32_t addr;
    uint32_t size;
    uint32_t addrBoundary, sizeBoundary;
    uint32_t totalBlocks, startNib, freeBlocks, endNib, temp1;
    uint32_t newAddr, newSize;
    uint32_t i, partBlocks, value, blkIdx,loopCnt;
    uint32_t secure, access, mask;
    uint32_t blockSize;
    uint32_t pc;
    uint32_t fieldMask;
    uint32_t fieldMaskVal;
    uint8_t autoInc;

    addr = rotConfig->addrOffset;
    size = rotConfig->size;
    access = (uint32_t)rotConfig->access;
    secure = (uint32_t)rotConfig->secure;
    pc = (uint32_t)rotConfig->pc;
    //To get Block size follow expression (1<<(BLOCK_SIZE+5))
    blockSize = 1UL << ((uint32_t)rotConfig->regionSize + 5UL);
    addrBoundary = addr%(blockSize);
    sizeBoundary = size%(blockSize);

    if (size == 0UL) {
        return CY_MPC_BAD_PARAM;
    }

    if (addrBoundary != 0UL) {
        return CY_MPC_BAD_PARAM;
    }

    if (sizeBoundary != 0UL) {
        return CY_MPC_BAD_PARAM;
    }

    if (pc >= (uint32_t)MPC_PC_NR)
    {
        return CY_MPC_BAD_PARAM;
    }

    // Check if initialization is still in progress
    if(CY_MPC_SUCCESS != _Cy_Mpc_CheckRotInitInProgress(base))
    {
        return CY_MPC_INVALID_STATE;
    }

    /*
    For each nibble:
    - bit[0] : NS (0 indicates secure, 1 indicates non-secure)
    - bit[1] : R (0 indicates read access not allowed. 1 indicates read access allowed)
    - bit[2] : W (0 indicates write access not allowed, 1 indicates write access allowed)
    - bit[3] : Reserved
    */
    if (access == (uint32_t)CY_MPC_ACCESS_DISABLED)
    {
        mask = 0x00000000UL;
    }
    else if (access == (uint32_t)CY_MPC_ACCESS_R)
    {
        mask = 0x00000002UL;
    }
    else if (access == (uint32_t)CY_MPC_ACCESS_W)
    {
        mask = 0x00000004UL;
    }
    else if (access == (uint32_t)CY_MPC_ACCESS_RW)
    {
        mask = 0x00000006UL;
    }
    else
    {
        return CY_MPC_BAD_PARAM;
    }

    if (secure == (uint32_t)CY_MPC_SECURE)
    {
        mask &= 0xFFFFFFFEUL;
    }
    else if (secure == (uint32_t)CY_MPC_NON_SECURE)
    {
        mask |= 0x00000001UL;
    }
    else
    {
        return CY_MPC_BAD_PARAM;
    }

    /* disabling auto increment */
    autoInc = (uint8_t)_FLD2VAL(RAMC_MPC_ROT_CTRL_AUTO_INC, base->ROT_CTRL);
    Cy_Mpc_RotAutoInc(base, 0u);

    //Set PC value
    base->ROT_BLK_PC = pc;


    totalBlocks = size/blockSize;
    temp1 = addr/blockSize;
    startNib = temp1 % 8UL;
    freeBlocks = 8UL - startNib;
    blkIdx = addr/(blockSize * 8UL);
    value = 0;
    fieldMask = 0xF;
    fieldMaskVal = 0;

    if (totalBlocks <= freeBlocks)
    {
        endNib = (totalBlocks + startNib - 1UL) % 8U;

        for (i = startNib; i <= endNib; i++)
        {
            fieldMaskVal = fieldMaskVal | (fieldMask << (4UL * i));
            value = value | (mask << (4UL * i));
        }

        fieldMaskVal = ~fieldMaskVal;
        base->ROT_BLK_IDX = blkIdx;
        base->ROT_BLK_LUT = (base->ROT_BLK_LUT & fieldMaskVal) | value;

        /* restore auto increment */
        Cy_Mpc_RotAutoInc(base, autoInc);

        return CY_MPC_SUCCESS;
    }
    else
    {
        endNib = 7;
        newAddr = ((addr/(8UL * blockSize)) + 1UL) * blockSize * 8UL;
        newSize = size - (freeBlocks*blockSize);

        for (i = startNib; i <= endNib; i++)
        {
            value = value | (mask << 4UL * i);
            fieldMaskVal = fieldMaskVal | (fieldMask << 4UL * i);
        }

        fieldMaskVal = ~fieldMaskVal;
        base->ROT_BLK_IDX = blkIdx;
        base->ROT_BLK_LUT = (base->ROT_BLK_LUT & fieldMaskVal) | value;
    }

    blkIdx = newAddr/(blockSize * 8UL);
    loopCnt = newSize/(blockSize * 8UL);
    totalBlocks = newSize/(blockSize);
    partBlocks = totalBlocks % 8UL;

    value = 0;
    for (i = 0U; i < loopCnt; i++)
    {
        int j;
        for ( j = 0; j < 8; j++)
        {
            value = value | (mask << (4UL * ((uint32_t)j)));
        }
        base->ROT_BLK_IDX = blkIdx;
        base->ROT_BLK_LUT = value;
        blkIdx++;
    }

    if (partBlocks != 0UL)
    {
        value = 0;
        fieldMask = 0xF;
        fieldMaskVal = 0;
        for (i = 0; i < partBlocks; i++)
        {
            value = value | (mask << 4UL * i);
            fieldMaskVal = fieldMaskVal | (fieldMask << 4UL * i);
        }

        fieldMaskVal = ~fieldMaskVal;
        base->ROT_BLK_IDX = blkIdx;
        base->ROT_BLK_LUT = (base->ROT_BLK_LUT & fieldMaskVal) | value;
    }

    /* restore auto increment */
    Cy_Mpc_RotAutoInc(base, autoInc);

    return CY_MPC_SUCCESS;
}

/*******************************************************************************
* Function Name: Cy_Mpc_ConfigMpcStruct
****************************************************************************//**
*
* \brief Initializes the referenced mpc by setting the NS/S
* permissions. This is called by TFM module.
*
*
* \param base
* Base address of mpc being configured
*
* \param config
* MPC configuration structure to be used by the TFM code
*
* \return
* Initialization status
*
*******************************************************************************/
cy_en_mpc_status_t Cy_Mpc_ConfigMpcStruct(MPC_Type* base, const cy_stc_mpc_cfg_t* config)
{
    uint32_t addr;
    uint32_t size;
    uint32_t addrBoundary, sizeBoundary;
    uint32_t totalBlocks, startBit, freeBlocks, endBit, temp1;
    uint32_t newAddr, newSize;
    uint32_t i, partBlocks, value, blkIdx,loopCnt;
    uint32_t blockSize, secure;
    uint8_t autoInc;

    addr = config->addrOffset;
    size = config->size;
    secure = (uint32_t)config->secure;

    if (config->regionSize != CY_MPC_SIZE_4KB)
    {
         return CY_MPC_BAD_PARAM;
    }

    // Check if initialization is still in progress
    if(CY_MPC_SUCCESS != _Cy_Mpc_CheckInitInProgress(base))
    {
        return CY_MPC_INVALID_STATE;
    }

    blockSize = 1UL << ((uint32_t)config->regionSize + 5UL);

    addrBoundary = addr%(blockSize);
    sizeBoundary = size%(blockSize);

    if (addrBoundary != 0UL) {
      return CY_MPC_BAD_PARAM;
    }

    if (sizeBoundary != 0UL) {
      return CY_MPC_BAD_PARAM;
    }

    /* disabling auto increment */
    autoInc = (uint8_t)_FLD2VAL(RAMC_MPC_ROT_CTRL_AUTO_INC, base->ROT_CTRL);
    Cy_Mpc_AutoInc(base, 0u);

    totalBlocks = size/blockSize;
    temp1 = addr/blockSize;

    startBit = temp1 % 32UL;
    freeBlocks = 32UL - startBit;

    blkIdx = addr/(blockSize * 32UL);

    value = 0;
    if (totalBlocks <= freeBlocks)
    {
        endBit = (totalBlocks + startBit - 1UL) % 32U;

        for (i = startBit; i <= endBit; i++)
        {
            value = value | (1UL << i);
        }

        base->BLK_IDX = blkIdx;

        if (secure == (uint32_t)CY_MPC_SECURE)
        {
            value = ~value;
            base->BLK_LUT = base->BLK_LUT & value;
        }
        else
        {
            base->BLK_LUT = base->BLK_LUT | value;
        }

        /* restore auto increment bit */
        Cy_Mpc_AutoInc(base, autoInc);
        return CY_MPC_SUCCESS;
    }
    else
    {
        endBit = 31;
        newAddr = ((addr/(32UL * blockSize)) + 1UL) * blockSize * 32UL;
        newSize = size - (freeBlocks * blockSize);

        base->BLK_IDX = blkIdx;

        for (i = startBit; i <= endBit; i++)
        {
            value = value | (1UL << i);
        }

        if (secure == (uint32_t)CY_MPC_SECURE)
        {
            value = ~value;
            base->BLK_LUT = base->BLK_LUT & value;
        }
        else
        {
            base->BLK_LUT = base->BLK_LUT | value;
        }
    }

    blkIdx = newAddr/(blockSize * 32UL);
    loopCnt = newSize/(blockSize * 32UL);
    totalBlocks = newSize/(blockSize);
    partBlocks = totalBlocks % 32UL;

    for (i = 0U; i < loopCnt; i++)
    {
        value = 0xFFFFFFFFUL;
        base->BLK_IDX = blkIdx;

        if (secure == (uint32_t)CY_MPC_SECURE)
        {
            value = ~value;
            base->BLK_LUT = base->BLK_LUT & value;
        }
        else
        {
            base->BLK_LUT = base->BLK_LUT | value;
        }
        blkIdx++;
    }

    if (partBlocks != 0UL)
    {
        value = 0;
        for (i = 0; i < partBlocks; i++)
        {
            value = value | (1UL << i);
        }

        base->BLK_IDX = blkIdx;
        if (secure == (uint32_t)CY_MPC_SECURE)
        {
            value = ~value;
            base->BLK_LUT = base->BLK_LUT & value;
        }
        else
        {
            base->BLK_LUT = base->BLK_LUT | value;
        }
    }

    /* restore auto increment bit */
    Cy_Mpc_AutoInc(base, autoInc);

    return CY_MPC_SUCCESS;
}

/*******************************************************************************
* Function Name: Cy_Mpc_Lock
****************************************************************************//**
*
* \brief Locks the MPC configuration
*
*
* \param base
* Base address of mpc being configured
*
*******************************************************************************/
void Cy_Mpc_Lock(MPC_Type* base)
{
    base->CTRL |= _VAL2FLD(RAMC_MPC_CTRL_LOCK, 1);
}

/*******************************************************************************
* Function Name: Cy_Mpc_RotLock
****************************************************************************//**
*
* \brief Locks the MPC configuration for ROT
*
*
* \param base
* Base address of mpc being configured
*
*******************************************************************************/
void Cy_Mpc_RotLock(MPC_Type* base)
{
    base->ROT_CTRL |= _VAL2FLD(RAMC_MPC_ROT_CTRL_LOCK, 1);
}

/*******************************************************************************
* Function Name: Cy_Mpc_RotAutoInc
****************************************************************************//**
*
* \brief Auto increment of BLK ID for ROT
*
*
* \param base
* Base address of mpc being configured
*
* \param control
* Auto increment control
*
*******************************************************************************/
void Cy_Mpc_RotAutoInc(MPC_Type* base, uint8_t control)
{
    if (control == 0u)
    {
        /* reset auto_inc bit */
        base->ROT_CTRL &= ~(_VAL2FLD(RAMC_MPC_ROT_CTRL_AUTO_INC, 1u));
    }
    else
    {
        /* set auto_inc bit */
        base->ROT_CTRL |= RAMC_MPC_ROT_CTRL_AUTO_INC_Msk;
    }
}

/*******************************************************************************
* Function Name: Cy_Mpc_AutoInc
****************************************************************************//**
*
* \brief Auto increment of BLK ID
*
*
* \param base
* Base address of mpc being configured
*
* \param control
* Auto increment control
*
*******************************************************************************/
void Cy_Mpc_AutoInc(MPC_Type* base, uint8_t control)
{
    if (control == 0u)
    {
        /* reset auto_inc bit */
        base->CTRL &= ~(_VAL2FLD(RAMC_MPC_CTRL_AUTO_INC, 1u));
    }
    else
    {
        /* set auto_inc bit */
        base->CTRL |= RAMC_MPC_CTRL_AUTO_INC_Msk;
    }

}


/*******************************************************************************
* Function Name: Cy_Mpc_GetRotBlockAttr
****************************************************************************//**
*
* \brief Get MPC attributes settings corresponding to block and the PC for ROT
*
*
* \param base
* Base address of mpc being configured
*
* \param pc
* Protection Context
*
* \param block
* Index of MPC block for PC. Use \ref CY_MPC_GET_BLOCK_INDEX to get index of block.
*
* \param p_block_settings
* Pointer to return value of block settings
*
* \return
* Initialization status
*
*******************************************************************************/
cy_en_mpc_status_t Cy_Mpc_GetRotBlockAttr(MPC_Type* base, cy_en_mpc_prot_context_t pc, uint32_t block, cy_stc_mpc_rot_block_attr_t* p_block_settings)
{
    if ((base == NULL) || ((uint32_t)pc >= (uint32_t)MPC_PC_NR)) {
        return CY_MPC_BAD_PARAM;
    }

    // Check if initialization is still in progress
    if(CY_MPC_SUCCESS != _Cy_Mpc_CheckRotInitInProgress(base))
    {
        return CY_MPC_INVALID_STATE;
    }

    base->ROT_BLK_PC     = (uint32_t)pc;
    base->ROT_BLK_IDX    = (block / CY_MPC_ROT_BLOCKS_PER_IDX);
    uint32_t blk_settings = (base->ROT_BLK_LUT >> ((block % CY_MPC_ROT_BLOCKS_PER_IDX) * CY_MPC_ROT_BLOCK_BIT_COUNT)) & CY_MPC_ROT_BLOCK_MASK;

    if ((blk_settings & CY_MPC_NS_MASK) != 0UL) {
        p_block_settings->secure = CY_MPC_NON_SECURE;
    } else {
        p_block_settings->secure = CY_MPC_SECURE;
    }

    if (((blk_settings & CY_MPC_ROT_READ_MASK) != 0UL) &&
        ((blk_settings & CY_MPC_ROT_WRITE_MASK) != 0UL)) {
        p_block_settings->access = CY_MPC_ACCESS_RW;
    } else if ((blk_settings & CY_MPC_ROT_READ_MASK) != 0UL){
        p_block_settings->access = CY_MPC_ACCESS_R;
    } else if ((blk_settings & CY_MPC_ROT_WRITE_MASK) != 0UL){
        p_block_settings->access = CY_MPC_ACCESS_W;
    } else {
        p_block_settings->access = CY_MPC_ACCESS_DISABLED;
    }

    return CY_MPC_SUCCESS;
}


/*******************************************************************************
* Function Name: Cy_Mpc_GetBlockAttr
****************************************************************************//**
*
* \brief Get MPC attributes settings corresponding to a block
*
*
* \param base
* Base address of mpc being configured
*
* \param block
* Index of MPC block for PC. Use \ref CY_MPC_GET_BLOCK_INDEX to get index of block.
*
* \param p_block_settings
* Pointer to return value of block settings
*
* \return
* Initialization status
*
*******************************************************************************/
cy_en_mpc_status_t Cy_Mpc_GetBlockAttr(MPC_Type* base, uint32_t block, cy_stc_mpc_block_attr_t* p_block_settings)
{
    if (base == NULL) {
        return CY_MPC_BAD_PARAM;
    }

    // Check if initialization is still in progress
    if(CY_MPC_SUCCESS != _Cy_Mpc_CheckInitInProgress(base))
    {
        return CY_MPC_INVALID_STATE;
    }

    base->BLK_IDX    = (block / CY_MPC_BLOCKS_PER_IDX);
    uint32_t blk_settings = (base->BLK_LUT >> ((block % CY_MPC_BLOCKS_PER_IDX) * CY_MPC_BLOCK_BIT_COUNT)) & CY_MPC_BLOCK_MASK;

    if ((blk_settings & CY_MPC_NS_MASK) != 0UL) {
        p_block_settings->secure = CY_MPC_NON_SECURE;
    } else {
        p_block_settings->secure = CY_MPC_SECURE;
    }

    return CY_MPC_SUCCESS;
}

/*******************************************************************************
* Function Name: Cy_Mpc_SetViolationResponse
****************************************************************************//**
*
* \brief Set MPC Violation Response
*
* \param base
* Base address of mpc being configured
*
* \param mpcResponse
* Enable/Disable MPC Response on violation
*
* \return
* API status
*
*******************************************************************************/
cy_en_mpc_status_t Cy_Mpc_SetViolationResponse(MPC_Type* base, bool mpcResponse)
{

  if (base == NULL)
  {
    return CY_MPC_BAD_PARAM;
  }

  if (mpcResponse)
  {
    /* Enable response for MPC violation */
    base->CFG |= RAMC_MPC_CFG_RESPONSE_Msk;
  }
  else
  {
    /* Disable response for MPC violation */
    base->CFG &= (~RAMC_MPC_CFG_RESPONSE_Msk);
  }

  return CY_MPC_SUCCESS;
}

#endif
/* [] END OF FILE */
