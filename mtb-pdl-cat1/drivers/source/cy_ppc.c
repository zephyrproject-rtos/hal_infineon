/***************************************************************************//**
* \file  cy_ppc.c
* \version 1.0
*
* \brief
* Provides an API implementation of the secure PPC driver.
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

#include "cy_ppc.h"
/* forward declaration */
void prog_attribute(PPC_Type* base, cy_stc_ppc_attribute_t* attribute, uint32_t value, uint32_t offset);

/*******************************************************************************
* Function Name: Cy_Ppc_InitPpc
****************************************************************************//**
*
* \brief Initializes the referenced ppc
*
* \param base
* Base address of ppc being configured
*
* \param ppcInit
* PPC initialization structure
*
* \return
* Initialization status
*
*******************************************************************************/
cy_en_ppc_status_t Cy_Ppc_InitPpc(PPC_Type* base, const cy_stc_ppc_init_t* ppcInit)
{
    if (ppcInit->respConfig > CY_PPC_BUS_ERR)
    {
        return CY_PPC_BAD_PARAM;
    }

    if (ppcInit->respConfig == CY_PPC_RZWI)
    {
        base->CTL = base->CTL & (~PPC_CTL_RESP_CFG_Msk);
    }
    else
    {
        base->CTL = base->CTL | PPC_CTL_RESP_CFG_Msk;
    }

    return CY_PPC_SUCCESS;
}

void prog_attribute(PPC_Type* base, cy_stc_ppc_attribute_t* attribute, uint32_t value, uint32_t offset)
{
    uint32_t cValue;
    uint32_t *nsAttPtr = (uint32_t*) (base->NS_ATT);
    uint32_t *sPrivAttPtr = (uint32_t*) base->S_P_ATT;
    uint32_t *nsPrivAttPtr = (uint32_t*) base->NS_P_ATT;

    if(offset < 32U)
    {
        /* Configure Security attribute */
        if (attribute->secAttribute == CY_PPC_SECURE)
        {
            cValue = ~value;
            *(nsAttPtr + offset) = (uint32_t)(*(nsAttPtr + offset) & cValue);
        }
        else
        {
            *(nsAttPtr + offset) = (uint32_t)(*(nsAttPtr + offset) | value);
        }
        #if 1
        /* Configure Secure privilege attribute */
        if (attribute->secPrivAttribute == CY_PPC_SEC_PRIV)
        {
            cValue = ~value;
            *(sPrivAttPtr + offset) = *(sPrivAttPtr + offset) & cValue;
        }
        else
        {
            *(sPrivAttPtr + offset) = *(sPrivAttPtr + offset) | value;
        }

        /* Configure Non-secure privilege attribute */
        if (attribute->nsPrivAttribute == CY_PPC_NON_SEC_PRIV)
        {
            cValue = ~value;
            *(nsPrivAttPtr + offset) = *(nsPrivAttPtr + offset) & cValue;
        }
        else
        {
            *(nsPrivAttPtr + offset) = *(nsPrivAttPtr + offset) | value;
        }
        #endif
    }
}

/*******************************************************************************
* Function Name: Cy_Ppc_ConfigAttrib
****************************************************************************//**
*
* \brief Configure the referenced ppc with the security and access attributes
*
* \param base
* Base address of ppc being configured
*
* \param attribute
* PPC attribute configuration structure
*
* \return
* Initialization status
*
*******************************************************************************/
cy_en_ppc_status_t Cy_Ppc_ConfigAttrib(PPC_Type* base, cy_stc_ppc_attribute_t* attribute)
{
    uint32_t startRegion, endRegion;
    uint32_t sPriv, nsPriv, totalRegions;
    uint32_t startBit, freeRegions, endBit;
    uint32_t newRegions;
    uint32_t i, partBlocks, value, blkIdx, loopCnt;
    uint32_t secure;

    startRegion = (uint32_t)attribute->startRegion;
    endRegion = (uint32_t)attribute->endRegion;
    secure = (uint32_t)(attribute->secAttribute);
    nsPriv = (uint32_t)(attribute->nsPrivAttribute);
    sPriv  = (uint32_t)(attribute->secPrivAttribute);

    if (startRegion > endRegion)
    {
        return CY_PPC_BAD_PARAM;
    }

    if (!(PPC_VALIDATE(base, startRegion)))
    {
        return CY_PPC_BAD_PARAM;
    }

    if (!(PPC_VALIDATE(base, endRegion)))
    {
        return CY_PPC_BAD_PARAM;
    }

    if(secure > (uint32_t)CY_PPC_NON_SECURE)
    {
        return CY_PPC_BAD_PARAM;
    }

    if (sPriv > (uint32_t)CY_PPC_SEC_NONPRIV)
    {
        return CY_PPC_BAD_PARAM;
    }

    if (nsPriv  > (uint32_t)CY_PPC_NON_SEC_NONPRIV)
    {
        return CY_PPC_BAD_PARAM;
    }

    if (startRegion > endRegion)
    {
        return CY_PPC_BAD_PARAM;
    }

    totalRegions = endRegion - startRegion + 1U;
    startBit = startRegion % 32U;
    freeRegions = 32U - startBit;

    blkIdx = startRegion / 32U;

    value = 0UL;
    if (totalRegions <= freeRegions)
    {
        endBit = (totalRegions + startBit - 1U) % 32U;
        for (i = startBit; i <= endBit; i++)
        {
            value = value | (1UL << i);
        }
        prog_attribute(base, attribute, value, blkIdx);
        return CY_PPC_SUCCESS;
    }
    else
    {
        endBit = 31U;
        newRegions = totalRegions - freeRegions;
        for (i = startBit; i <= endBit; i++)
        {
            value = value | (1UL << i);
        }
        prog_attribute(base, attribute, value, blkIdx);
        blkIdx++;
    }

    loopCnt = newRegions / 32U;
    partBlocks = newRegions % 32U;

    for (i = 0U; i < loopCnt; i++)
    {
        value = 0xFFFFFFFFUL;
        prog_attribute(base, attribute, value, blkIdx);
        blkIdx++;
    }

    if (partBlocks > 0U)
    {
        value = 0UL;
        for (i = 0U; i < partBlocks; i++)
        {
            value = value | (1UL << i);
        }
        prog_attribute(base, attribute, value, blkIdx);
    }

    return CY_PPC_SUCCESS;
}

/*******************************************************************************
* Function Name: Cy_Ppc_SetPcMask
****************************************************************************//**
*
* \brief Configure the PC mask for a given range of regions of referenced ppc
*
* \param base
* Base address of ppc being configured
*
* \param pcMaskConfig
* PPC mask configuration structure
*
* \return
* Initialization status
*
*******************************************************************************/
cy_en_ppc_status_t Cy_Ppc_SetPcMask(PPC_Type* base, cy_stc_ppc_pc_mask_t* pcMaskConfig)
{
    uint32_t i;
    uint32_t startRegion, endRegion;

    startRegion = (uint32_t)pcMaskConfig->startRegion;
    endRegion = (uint32_t)pcMaskConfig->endRegion;

    if (startRegion > endRegion)
    {
        return CY_PPC_BAD_PARAM;
    }

    if (!(PPC_VALIDATE(base, startRegion)))
    {
        return CY_PPC_BAD_PARAM;
    }

    if (!(PPC_VALIDATE(base, endRegion)))
    {
        return CY_PPC_BAD_PARAM;
    }

    for (i = startRegion; i <= endRegion; i++)
    {
        base->PC_MASK[i] = pcMaskConfig->pcMask;
    }
    return CY_PPC_SUCCESS;
}

/*******************************************************************************
* Function Name: Cy_Ppc_SetLockMask
****************************************************************************//**
*
* \brief Configures the lock mask for the referenced ppc
*
*
* \param base
* Base address of ppc being configured
*
* \param lockMask
* Mask value to be set
*
* \return
* Initialization status
*
*******************************************************************************/
cy_en_ppc_status_t Cy_Ppc_SetLockMask(PPC_Type* base, uint32_t lockMask)
{
    base->LOCK_MASK = lockMask;
    return CY_PPC_SUCCESS;
}

/*******************************************************************************
* Function Name: Cy_Ppc_GetLockMask
****************************************************************************//**
*
* \brief Reads the lock mask value for the referenced ppc
*
*
* \param base
* Base address of ppc being configured
*
* \return
* Mask value read
*
*******************************************************************************/
uint32_t Cy_Ppc_GetLockMask(PPC_Type* base)
{
    return base->LOCK_MASK;
}

#endif
/* [] END OF FILE */


