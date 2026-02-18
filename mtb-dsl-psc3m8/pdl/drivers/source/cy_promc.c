/***************************************************************************//**
* \file cy_promc.c
* \version 1.0
*
* Provides private definitions and function implementation of the PROMC
* driver.
*
********************************************************************************
* \copyright
* (c) 2024-2026, Infineon Technologies AG, or an affiliate of Infineon
* Technologies AG.
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

#include <stddef.h>

#include "cy_promc.h"

#if defined (CY_IP_MXPROMC) && (CPUSS_PROMC_PATCH_PRESENT > 0UL)

/*******************************************************************************
*                          Private Macros
*******************************************************************************/
#define CY_PROMC_ROM_BASE                CY_ROM_NS_CBUS_BASE
#define CY_PROMC_START_PATCHABLE_AREA    (CY_PROMC_ROM_BASE + CPUSS_PROMC_SROM_BOUNDARY)
#define CY_PROMC_MATCH_ADDR_MASK         0x3FFFUL


cy_en_promc_status_t Cy_PROMC_Init(PROMC_Type *base, cy_stc_promc_context_t *context)
{
    cy_en_promc_status_t status = CY_PROMC_BAD_PARAM;

    if (base != NULL)
    {
        if (context != NULL)
        {
            context->index = 0UL;
        }
        status = CY_PROMC_SUCCESS;
    }
    return status;
}


void Cy_PROMC_DeInit(PROMC_Type *base)
{
    for (uint32_t i = 0UL; i < CPUSS_PROMC_PATCH_NR; i++)
    {
        base->PATCH_STRUCT_CTL[i] = 0;
    }
}


void Cy_PROMC_Enable(PROMC_Type *base)
{
    base->PATCH_CTL = PROMC_PATCH_CTL_ENABLED_Msk;
}


void Cy_PROMC_Disable(PROMC_Type *base)
{
    base->PATCH_CTL = 0UL;
}


cy_en_promc_wait_state_t Cy_PROMC_GetWaitState(PROMC_Type *base)
{
    return (cy_en_promc_wait_state_t)_FLD2VAL(PROMC_CTL_ROM_WS, base->CTL);
}


void Cy_PROMC_SetWaitState(PROMC_Type *base, cy_en_promc_wait_state_t ws)
{
    base->CTL |= _VAL2FLD(PROMC_CTL_ROM_WS, (uint32_t)ws);
}


cy_en_promc_status_t Cy_PROMC_SetPatchEntryValidBit(PROMC_Type *base, uint32_t index)
{
    cy_en_promc_status_t status = CY_PROMC_BAD_PARAM;

    if (index <= CPUSS_PROMC_PATCH_NR)
    {
        base->PATCH_STRUCT_CTL[index] |= PROMC_PATCH_STRUCT_CTL_VALID_Msk;

        status = CY_PROMC_SUCCESS;
    }

    return status;
}

cy_en_promc_status_t Cy_PROMC_ClearPatchEntryValidBit(PROMC_Type *base, uint32_t index)
{
    cy_en_promc_status_t status = CY_PROMC_BAD_PARAM;

    if (index <= CPUSS_PROMC_PATCH_NR)
    {
        base->PATCH_STRUCT_CTL[index] &= ~PROMC_PATCH_STRUCT_CTL_VALID_Msk;

        status = CY_PROMC_SUCCESS;
    }

    return status;
}

bool Cy_PROMC_GetPatchEntryValidBit(PROMC_Type *base, uint32_t index)
{
    return (0UL != (base->PATCH_STRUCT_CTL[index] & PROMC_PATCH_STRUCT_CTL_VALID_Msk));
}


cy_en_promc_status_t Cy_PROMC_GetConfiguration(PROMC_Type *base, cy_stc_promc_config_info_t *configInfo)
{
    cy_en_promc_status_t status = CY_PROMC_BAD_PARAM;

    if (configInfo != NULL)
    {
        configInfo->patchNumber = (base->PATCH_CFG & PROMC_PATCH_CFG_PATCH_NR_Msk);
        configInfo->size = (cy_en_promc_patch_size_t)_FLD2VAL(PROMC_PATCH_CFG_PATCH_SIZE, base->PATCH_CFG);
        status = CY_PROMC_SUCCESS;
    }

    return status;
}


cy_en_promc_status_t Cy_PROMC_GetPatchEntry(PROMC_Type *base, cy_stc_promc_entry_t *entry, uint32_t index)
{
    cy_en_promc_status_t status = CY_PROMC_BAD_PARAM;
    uint32_t *patchData;

    if (index <= CPUSS_PROMC_PATCH_NR)
    {
        entry->addr = _FLD2VAL(PROMC_PATCH_STRUCT_CTL_MATCH_ADDR, base->PATCH_STRUCT_CTL[index]);

        patchData = (uint32_t*)&base->PATCH_DATA[index * CY_PROMC_ENTRY_WORDS];

        for (uint32_t i = 0; i < CY_PROMC_ENTRY_WORDS; i++)
        {
            entry->data[i] = patchData[i];
        }

        status = CY_PROMC_SUCCESS;
    }
    return status;
}


cy_en_promc_status_t Cy_PROMC_SetPatchEntry(PROMC_Type *base, cy_stc_promc_entry_t *entry, uint32_t index)
{
    cy_en_promc_status_t status = CY_PROMC_BAD_PARAM;
    uint32_t replaceAddr;
    uint32_t *patchData;

    if (index <= CPUSS_PROMC_PATCH_NR)
    {
        replaceAddr = entry->addr;
        if ((replaceAddr & 0xFUL) == 0)
        {
            if ((replaceAddr > CY_PROMC_START_PATCHABLE_AREA) && \
                (replaceAddr < (CY_PROMC_ROM_BASE + CY_ROM_SIZE)))
            {
                patchData = (uint32_t*)&base->PATCH_DATA[index * CY_PROMC_ENTRY_WORDS];

                replaceAddr = ((replaceAddr >> PROMC_PATCH_STRUCT_CTL_MATCH_ADDR_Pos) & CY_PROMC_MATCH_ADDR_MASK);

                base->PATCH_STRUCT_CTL[index] |= _VAL2FLD(PROMC_PATCH_STRUCT_CTL_MATCH_ADDR, replaceAddr);

                for (uint32_t i = 0; i < CY_PROMC_ENTRY_WORDS; i++)
                {
                    patchData[i] = entry->data[i];
                }

                Cy_PROMC_SetPatchEntryValidBit(base, index);
                status = CY_PROMC_SUCCESS;
            }
            else
            {
                status = CY_PROMC_OUT_OF_BOUNDS;
            }
        }
    }
    return status;
}


cy_en_promc_status_t Cy_PROMC_SetIndex(PROMC_Type *base, cy_stc_promc_context_t *context, uint32_t index)
{
    cy_en_promc_status_t status = CY_PROMC_BAD_PARAM;
    (void)base;

    if (index <= CPUSS_PROMC_PATCH_NR && context != NULL)
    {
        context->index = index;
        status = CY_PROMC_SUCCESS;
    }
    return status;
}


uint32_t Cy_PROMC_GetIndex(PROMC_Type *base, cy_stc_promc_context_t *context)
{
    uint32_t index;
    (void)base;

    if (context != NULL)
    {
        index = context->index;
    }
    else
    {
        index = CPUSS_PROMC_PATCH_NR + 1UL;
    }
    return index;
}


cy_en_promc_status_t Cy_PROMC_Status(PROMC_Type *base, cy_stc_promc_patch_status_t *patchStatus)
{
    cy_en_promc_status_t status = CY_PROMC_BAD_PARAM;

    if (patchStatus != NULL)
    {
        patchStatus->patchIndex = base->PATCH_STATUS & PROMC_PATCH_STATUS_PATCH_IDX_Msk;
        patchStatus->status = (bool)(base->PATCH_STATUS & PROMC_PATCH_STATUS_PATCH_VALID_Msk);
        status = CY_PROMC_SUCCESS;
    }
    return status;
}


cy_en_promc_status_t Cy_PROMC_SetPatch(PROMC_Type *base, cy_stc_promc_patch_t *patch, cy_stc_promc_context_t *context)
{
    if (NULL == patch)
    {
        return CY_PROMC_BAD_PARAM;
    }

    if ((patch->addr < CY_PROMC_START_PATCHABLE_AREA) || \
        (patch->addr > (CY_PROMC_ROM_BASE + CY_ROM_SIZE)))
    {
        return CY_PROMC_OUT_OF_BOUNDS;
    }

    /* Offset in words from patch entry boundary. */
    uint32_t offsetStart = (patch->addr & 0xFUL) / CY_PROMC_ENTRY_WORDS;

    /* Get number of entries used by this patch. */
    uint32_t numEntries = ((offsetStart + patch->size - 1UL) / CY_PROMC_ENTRY_WORDS) + 1UL;

    /* Check if there is enough room in patch table for requested patch size */
    if (numEntries > CPUSS_PROMC_PATCH_NR - context->index)
    {
        return CY_PROMC_NO_MORE_ROOM;
    }

    /* Get address aligned to patch size. */
    uint32_t replAddr = patch->addr & ~0xFUL;

    /* Get index of the first data word for this patch in MXPROMC. */
    uint32_t indexStart = context->index * CY_PROMC_ENTRY_WORDS;

    /* Copy ROM data to patch RAM.
     * Copy multiple entries if the patch crosses the patch entry boundary.
     */
    uint32_t *replAddrPtr = (uint32_t *)(replAddr);
    for (uint32_t i = 0; i < numEntries * CY_PROMC_ENTRY_WORDS; i++)
    {
        ((uint32_t*)(&base->PATCH_DATA[indexStart]))[i] = replAddrPtr[i];
    }

    /* Get patch RAM update start (accounting for offset). */
    uint32_t index_update = indexStart + offsetStart;

    /* Copy patch data to patch data RAM. */
    for (uint32_t i = 0; i < patch->size; i++)
    {
        ((uint32_t*)(&base->PATCH_DATA[index_update]))[i] = patch->data[i];
    }

    /* Enable match address across index range. */
    for (uint32_t index = 0; index < numEntries; index++)
    {
        replAddr += index * CY_PROMC_ENTRY_BYTES;
        base->PATCH_STRUCT_CTL[context->index] |= _VAL2FLD(PROMC_PATCH_STRUCT_CTL_MATCH_ADDR,
                ((replAddr >> PROMC_PATCH_STRUCT_CTL_MATCH_ADDR_Pos) & CY_PROMC_MATCH_ADDR_MASK));
        Cy_PROMC_SetPatchEntryValidBit(base, context->index);
        context->index++;
    }
    return CY_PROMC_SUCCESS;
}

#endif /* (CY_IP_MXPROMC) && (CPUSS_PROMC_PATCH_PRESENT > 0UL) */

/* [] END OF FILE */
