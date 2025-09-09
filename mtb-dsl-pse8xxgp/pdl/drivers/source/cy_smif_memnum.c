/***************************************************************************//**
* \file cy_smif_memnum.c
* \version 1.0
*
* \brief
*  This file provides the source code for the memory-level APIs of the SMIF driver.
*
* Note:
*
********************************************************************************
* \copyright
* Copyright 2025 Cypress Semiconductor Corporation (an Infineon company) or
* an affiliate of Cypress Semiconductor Corporation.
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

#if defined (CY_IP_MXSMIF)

#include "cy_smif_memnum.h"
#include "cy_pdl_srf_common.h"
#include "cycfg_ppc.h"
#include <string.h>

#if defined(__cplusplus)
extern "C" {
#endif


/*******************************************************************************
*    Secure Aware Support
*******************************************************************************/
#if defined(COMPONENT_SECURE_DEVICE)
cy_stc_smif_mem_context_t* smif_internal_secure_contexts[CY_IP_MXSMIF_INSTANCES];
#endif

//Helper to get the correct SMIF Number based on the base address
static inline uint8_t _Cy_SMIF_GetSmifNumber(SMIF_CORE_Type* baseAddress)
{
    if ((SMIF_CORE_Type*)GET_ALIAS_ADDRESS(baseAddress) == SMIF0_CORE)
    {
        return CY_SMIF_SUB_BLOCK_0;
    }
    else
    {
        return CY_SMIF_SUB_BLOCK_1;
    }
}

//Helper to get the correct MemConfig number based on the memory slot number
uint8_t _Cy_SMIF_GetConfigNumber(cy_stc_smif_mem_context_t *context, uint8_t smif_number, uint8_t memNum)
{
    uint8_t memConfigNumber = 0xFF;
    CY_ASSERT_L3(CY_SMIF_SLAVE_SEL_VALID(memNum));

#if defined(COMPONENT_SECURE_DEVICE)
    CY_UNUSED_PARAM(context);
    if(context->requires_secure_call)
    {
        for(uint32_t idx = 0; idx < smif_internal_secure_contexts[smif_number]->block_config->memCount; idx ++)
        {
            if(smif_internal_secure_contexts[smif_number]->block_config->memConfig[idx]->slaveSelect == (1 << memNum))
            {
                memConfigNumber = idx;
                break;
            }
        }
    }
    else
#endif
    {
        CY_UNUSED_PARAM(smif_number);
        for(uint32_t idx = 0; idx < context->block_config->memCount; idx ++)
        {
            if(context->block_config->memConfig[idx]->slaveSelect == (1 << memNum))
            {
                memConfigNumber = idx;
                break;
            }
        }

    }
    return memConfigNumber;
}


#if defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_SMIF_ENABLE_SRF_INTEG)
/* Helper function to check for valid access to the external memory addresses. Using address and length both
set to 0 corresponds to a special case that checks that the entire area is accessible for the EraseChip validation */
bool _Cy_SMIF_IsAddressRangeNSAccessible(cy_stc_smif_mem_context_t *context, uint8_t memNum, uint32_t address, uint32_t length)
{
    bool isAddressNSAccessible = false;
    uint8_t smif_number = _Cy_SMIF_GetSmifNumber(context->base);
    uint8_t memConfigNumber = _Cy_SMIF_GetConfigNumber(context, smif_number, memNum);
    uint32_t xipStartAddress = (uint32_t)context->block_config->memConfig[memConfigNumber]->baseAddress;
    uint32_t xipSize = (uint32_t)context->block_config->memConfig[memConfigNumber]->memMappedSize;

    if((address == 0u) && (length == 0u))
    {
        //Special case for EraseChip check
        if(xipSize == context->block_config->memConfig[memConfigNumber]->deviceCfg->memSize)
        {
            isAddressNSAccessible = mtb_srf_is_memory_ns_accessible(xipStartAddress, xipSize);
        }
    }
    else
    {
        //Check that both relative start address and relative end address are within the xip mapped region size
        if((address <= xipSize) && (length <= xipSize) && (address + length <= xipSize))
        {
            isAddressNSAccessible = mtb_srf_is_memory_ns_accessible(xipStartAddress + address, length);
        }
    }

    return isAddressNSAccessible;
}


/* Default SMIF permissions.  These may be overriden by declaring a custom structure. */
__WEAK mtb_srf_permission_s_t mtb_pdl_smif_srf_permissions[] = /* SMIF_INSTANCES */
{
    {
        .base = SMIF0_CORE,
        .sub_block = CY_SMIF_SUB_BLOCK_0,
        .write_allowed = true,
    },
    {
        .base = SMIF1_CORE,
        .sub_block = CY_SMIF_SUB_BLOCK_1,
        .write_allowed = true,
    },
    {
        .base = SMIF0_CACHE_BLOCK,
        .sub_block = CY_SMIF_SUB_BLOCK_0,
        .write_allowed = true,
    },
    {
        .base = SMIF1_CACHE_BLOCK,
        .sub_block = CY_SMIF_SUB_BLOCK_1,
        .write_allowed = true,
    },
};

cy_rslt_t cy_pdl_smif_srf_get_info_impl_s(mtb_srf_input_ns_t* inputs_ns,
                                         mtb_srf_output_ns_t* outputs_ns,
                                         mtb_srf_invec_ns_t* inputs_ptr_ns,
                                         uint8_t inputs_ptr_cnt_ns,
                                         mtb_srf_outvec_ns_t* outputs_ptr_ns,
                                         uint8_t outputs_ptr_cnt_ns)
{
    CY_UNUSED_PARAM(inputs_ptr_cnt_ns);
    CY_UNUSED_PARAM(outputs_ptr_cnt_ns);
    CY_UNUSED_PARAM(inputs_ptr_ns);

    CY_ASSERT_L2((inputs_ns->request).module_id == MTB_SRF_MODULE_PDL);
    CY_ASSERT_L2((inputs_ns->request).op_id == CY_PDL_SMIF_OP_MEM_GET_INFO);
    CY_ASSERT_L2((inputs_ns->request).submodule_id == CY_PDL_SECURE_SUBMODULE_SMIF);

    CY_ASSERT_L2(inputs_ns->input_values[0] >= sizeof(uint8_t));

    CY_ASSERT_L2(outputs_ptr_ns[0].len >= sizeof(cy_stc_smif_mem_info_t));

    cy_stc_smif_mem_context_t context =
    {
        .base = (SMIF_Type*) GET_ALIAS_ADDRESS((inputs_ns->request).base),
        .requires_secure_call = true,
    };

    cy_en_smif_status_t op_res = 0;
    op_res = Cy_SMIF_MemNumGetInfo(&context,
                                   (uint8_t)(inputs_ns->input_values[0]),
                                   (cy_stc_smif_mem_info_t*)(outputs_ptr_ns[0].base));

   memcpy(&outputs_ns->output_values[0], &op_res, sizeof(op_res));

    return CY_RSLT_SUCCESS;
}

cy_rslt_t cy_pdl_smif_srf_mem_num_read_impl_s(mtb_srf_input_ns_t* inputs_ns,
                                         mtb_srf_output_ns_t* outputs_ns,
                                         mtb_srf_invec_ns_t* inputs_ptr_ns,
                                         uint8_t inputs_ptr_cnt_ns,
                                         mtb_srf_outvec_ns_t* outputs_ptr_ns,
                                         uint8_t outputs_ptr_cnt_ns)
{
    CY_UNUSED_PARAM(inputs_ptr_cnt_ns);

    CY_ASSERT_L2((inputs_ns->request).module_id == MTB_SRF_MODULE_PDL);
    CY_ASSERT_L2((inputs_ns->request).op_id == CY_PDL_SMIF_OP_MEM_READ);
    CY_ASSERT_L2((inputs_ns->request).submodule_id == CY_PDL_SECURE_SUBMODULE_SMIF);


    CY_ASSERT_L2(outputs_ns[0].len >= sizeof(cy_en_smif_status_t));

    uint8_t memNum = 0;
    uint32_t address = 0;

    memcpy(&memNum, &(inputs_ns->input_values[0]), sizeof(memNum));
    memcpy(&address, &(inputs_ns->input_values[sizeof(memNum)]), sizeof(address));

    cy_stc_smif_mem_context_t context =
    {
        .base = (SMIF_Type*) GET_ALIAS_ADDRESS((inputs_ns->request).base),
        .requires_secure_call = true,
    };

    cy_en_smif_status_t op_res = 0;
    op_res =  Cy_SMIF_MemNumRead(&context,
                                 memNum,
                                 address,
                                 (uint8_t*)(outputs_ptr_ns[0].base),
                                 (uint32_t)(outputs_ptr_ns[0].len));

    memcpy(&outputs_ns->output_values[0], &op_res, sizeof(op_res));

    return CY_RSLT_SUCCESS;
}

cy_rslt_t cy_pdl_smif_srf_mem_num_write_impl_s(mtb_srf_input_ns_t* inputs_ns,
                                         mtb_srf_output_ns_t* outputs_ns,
                                         mtb_srf_invec_ns_t* inputs_ptr_ns,
                                         uint8_t inputs_ptr_cnt_ns,
                                         mtb_srf_outvec_ns_t* outputs_ptr_ns,
                                         uint8_t outputs_ptr_cnt_ns)
{
    CY_UNUSED_PARAM(outputs_ptr_ns);

    CY_ASSERT_L2((inputs_ns->request).module_id == MTB_SRF_MODULE_PDL);
    CY_ASSERT_L2((inputs_ns->request).op_id == CY_PDL_SMIF_OP_MEM_WRITE);
    CY_ASSERT_L2((inputs_ns->request).submodule_id == CY_PDL_SECURE_SUBMODULE_SMIF);

    CY_ASSERT_L2(outputs_ns[0].len >= sizeof(cy_en_smif_status_t));

    uint8_t memNum = 0;
    uint32_t address = 0;

    memcpy(&memNum, &(inputs_ns->input_values[0]), sizeof(memNum));
    memcpy(&address, &(inputs_ns->input_values[sizeof(memNum)]), sizeof(address));

    cy_stc_smif_mem_context_t context =
    {
        .base = (SMIF_Type*) GET_ALIAS_ADDRESS((inputs_ns->request).base),
        .requires_secure_call = true,
    };

    cy_en_smif_status_t op_res = 0;
    op_res = Cy_SMIF_MemNumWrite(&context,
                                 memNum,
                                 address,
                                 (uint8_t*)(inputs_ptr_ns[0].base),
                                 (uint32_t)(inputs_ptr_ns[0].len));
    memcpy(&outputs_ns->output_values[0], &op_res, sizeof(op_res));

    return CY_RSLT_SUCCESS;

}

cy_rslt_t cy_pdl_smif_srf_mem_num_erase_sector_impl_s(mtb_srf_input_ns_t* inputs_ns,
                                         mtb_srf_output_ns_t* outputs_ns,
                                         mtb_srf_invec_ns_t* inputs_ptr_ns,
                                         uint8_t inputs_ptr_cnt_ns,
                                         mtb_srf_outvec_ns_t* outputs_ptr_ns,
                                         uint8_t outputs_ptr_cnt_ns)
{
    CY_UNUSED_PARAM(outputs_ptr_ns);
    CY_UNUSED_PARAM(inputs_ptr_ns);

    CY_ASSERT_L2((inputs_ns->request).module_id == MTB_SRF_MODULE_PDL);
    CY_ASSERT_L2((inputs_ns->request).op_id == CY_PDL_SMIF_OP_MEM_ERASE_SECTOR);
    CY_ASSERT_L2((inputs_ns->request).submodule_id == CY_PDL_SECURE_SUBMODULE_SMIF);

    CY_ASSERT_L2(outputs_ns[0].len >= sizeof(cy_en_smif_status_t));
    uint8_t memNum = 0;
    uint32_t address = 0;
    uint32_t length = 0;

    memcpy(&memNum, &(inputs_ns->input_values[0]), sizeof(memNum));
    memcpy(&address, &(inputs_ns->input_values[sizeof(memNum)]), sizeof(address));
    memcpy(&length, &(inputs_ns->input_values[sizeof(memNum) + sizeof(address)]), sizeof(length));

    cy_stc_smif_mem_context_t context =
    {
        .base = (SMIF_Type*) GET_ALIAS_ADDRESS((inputs_ns->request).base),
        .requires_secure_call = true,
    };

    cy_en_smif_status_t op_res = 0;
    op_res =  Cy_SMIF_MemNumEraseSector(&context,
                                        memNum,
                                        address,
                                        length);

    memcpy(&outputs_ns->output_values[0], &op_res, sizeof(op_res));
    return CY_RSLT_SUCCESS;

}

cy_rslt_t cy_pdl_smif_srf_mem_num_erase_chip_impl_s(mtb_srf_input_ns_t* inputs_ns,
                                         mtb_srf_output_ns_t* outputs_ns,
                                         mtb_srf_invec_ns_t* inputs_ptr_ns,
                                         uint8_t inputs_ptr_cnt_ns,
                                         mtb_srf_outvec_ns_t* outputs_ptr_ns,
                                         uint8_t outputs_ptr_cnt_ns)
{
    CY_UNUSED_PARAM(outputs_ptr_ns);
    CY_UNUSED_PARAM(inputs_ptr_ns);

    CY_ASSERT_L2((inputs_ns->request).module_id == MTB_SRF_MODULE_PDL);
    CY_ASSERT_L2((inputs_ns->request).op_id == CY_PDL_SMIF_OP_MEM_ERASE_CHIP);
    CY_ASSERT_L2((inputs_ns->request).submodule_id == CY_PDL_SECURE_SUBMODULE_SMIF);

    CY_ASSERT_L2(outputs_ns[0].len >= sizeof(cy_en_smif_status_t));

    cy_stc_smif_mem_context_t context =
    {
        .base = (SMIF_Type*) GET_ALIAS_ADDRESS((inputs_ns->request).base),
        .requires_secure_call = true,
    };

    cy_en_smif_status_t op_res = 0;
    op_res = Cy_SMIF_MemNumEraseChip(&context,
                                     (uint8_t)(inputs_ns->input_values[0]));

    memcpy(&outputs_ns->output_values[0], &op_res, sizeof(op_res));
    return CY_RSLT_SUCCESS;
}


cy_rslt_t cy_pdl_smif_srf_mem_num_hb_read_impl_s(mtb_srf_input_ns_t* inputs_ns,
                                            mtb_srf_output_ns_t* outputs_ns,
                                            mtb_srf_invec_ns_t* inputs_ptr_ns,
                                            uint8_t inputs_ptr_cnt_ns,
                                            mtb_srf_outvec_ns_t* outputs_ptr_ns,
                                            uint8_t outputs_ptr_cnt_ns)
{
    CY_UNUSED_PARAM(inputs_ptr_cnt_ns);
    CY_UNUSED_PARAM(outputs_ptr_cnt_ns);
    CY_UNUSED_PARAM(inputs_ptr_ns);

    CY_ASSERT_L2((inputs_ns->request).module_id == MTB_SRF_MODULE_PDL);
    CY_ASSERT_L2((inputs_ns->request).op_id == CY_PDL_SMIF_OP_HB_READ);
    CY_ASSERT_L2((inputs_ns->request).submodule_id == CY_PDL_SECURE_SUBMODULE_SMIF);

    CY_ASSERT_L2(outputs_ns[0].len >= sizeof(cy_en_smif_status_t));

    cy_en_smif_status_t retVal = CY_SMIF_SUCCESS;
    uint8_t memNum = 0;
    uint32_t address = 0;

    memcpy(&memNum, &(inputs_ns->input_values[0]), sizeof(memNum));
    memcpy(&address, &(inputs_ns->input_values[sizeof(memNum)]), sizeof(address));

    cy_stc_smif_mem_context_t context =
    {
        .base = (SMIF_Type*) GET_ALIAS_ADDRESS((inputs_ns->request).base),
        .requires_secure_call = true,
    };

    retVal = Cy_SMIF_MemNumHyperBusRead(&context,
                                        memNum,
                                        address,
                                        (uint8_t*)(outputs_ptr_ns[0].base),
                                        (uint32_t)(outputs_ptr_ns[0].len));

    memcpy(&outputs_ns->output_values[0], &retVal, sizeof(retVal));
    return CY_RSLT_SUCCESS;

}

cy_rslt_t cy_pdl_smif_srf_mem_num_hb_write_impl_s(mtb_srf_input_ns_t* inputs_ns,
                                            mtb_srf_output_ns_t* outputs_ns,
                                            mtb_srf_invec_ns_t* inputs_ptr_ns,
                                            uint8_t inputs_ptr_cnt_ns,
                                            mtb_srf_outvec_ns_t* outputs_ptr_ns,
                                            uint8_t outputs_ptr_cnt_ns)
{
    CY_UNUSED_PARAM(inputs_ptr_cnt_ns);
    CY_UNUSED_PARAM(outputs_ptr_ns);
    CY_UNUSED_PARAM(outputs_ptr_cnt_ns);

    CY_ASSERT_L2((inputs_ns->request).module_id == MTB_SRF_MODULE_PDL);
    CY_ASSERT_L2((inputs_ns->request).op_id == CY_PDL_SMIF_OP_HB_WRITE);
    CY_ASSERT_L2((inputs_ns->request).submodule_id == CY_PDL_SECURE_SUBMODULE_SMIF);

    CY_ASSERT_L2(outputs_ns[0].len >= sizeof(cy_en_smif_status_t));

    cy_en_smif_status_t retVal = CY_SMIF_SUCCESS;
    uint8_t memNum = 0;
    uint32_t address = 0;

    memcpy(&memNum, &(inputs_ns->input_values[0]), sizeof(memNum));
    memcpy(&address, &(inputs_ns->input_values[sizeof(memNum)]), sizeof(address));

    cy_stc_smif_mem_context_t context =
    {
        .base = (SMIF_Type*) GET_ALIAS_ADDRESS((inputs_ns->request).base),
        .requires_secure_call = true,
    };

    retVal = Cy_SMIF_MemNumHyperBusWrite(&context,
                                         memNum,
                                         address,
                                         (uint8_t*)(inputs_ptr_ns[0U].base),
                                         (uint32_t)(inputs_ptr_ns[0U].len));

    memcpy(&outputs_ns->output_values[0], &retVal, sizeof(retVal));
    return CY_RSLT_SUCCESS;

}


cy_rslt_t cy_pdl_smif_srf_clean_cache_impl_s(mtb_srf_input_ns_t* inputs_ns,
                                            mtb_srf_output_ns_t* outputs_ns,
                                            mtb_srf_invec_ns_t* inputs_ptr_ns,
                                            uint8_t inputs_ptr_cnt_ns,
                                            mtb_srf_outvec_ns_t* outputs_ptr_ns,
                                            uint8_t outputs_ptr_cnt_ns)
{
    CY_UNUSED_PARAM(inputs_ptr_cnt_ns);
    CY_UNUSED_PARAM(outputs_ptr_ns);
    CY_UNUSED_PARAM(outputs_ptr_cnt_ns);

    CY_ASSERT_L2((inputs_ns->request).module_id == MTB_SRF_MODULE_PDL);
    CY_ASSERT_L2((inputs_ns->request).op_id == CY_PDL_SMIF_OP_CLEAN_CACHE);
    CY_ASSERT_L2((inputs_ns->request).submodule_id == CY_PDL_SECURE_SUBMODULE_SMIF);
    CY_ASSERT_L2(outputs_ns[0].len >= sizeof(cy_en_smif_status_t));

    cy_en_smif_status_t retVal = CY_SMIF_SUCCESS;
    bool is_secure_view = false;
    uint32_t address = 0;
    uint32_t size = 0;

    memcpy(&is_secure_view, &(inputs_ns->input_values[0]), sizeof(is_secure_view));
    memcpy(&address, &(inputs_ns->input_values[sizeof(is_secure_view)]), sizeof(address));
    memcpy(&size, &(inputs_ns->input_values[sizeof(is_secure_view) + sizeof(address)]), sizeof(size));

    retVal = Cy_SMIF_Clean_Cache_by_Addr((SMIF_CACHE_BLOCK_Type *)GET_ALIAS_ADDRESS((inputs_ns->request).base),
                                        is_secure_view,
                                        address,
                                        size);
    memcpy(&outputs_ns->output_values[0], &retVal, sizeof(retVal));
    return CY_RSLT_SUCCESS;
}
cy_rslt_t cy_pdl_smif_srf_invalidate_cache_impl_s(mtb_srf_input_ns_t* inputs_ns,
                                            mtb_srf_output_ns_t* outputs_ns,
                                            mtb_srf_invec_ns_t* inputs_ptr_ns,
                                            uint8_t inputs_ptr_cnt_ns,
                                            mtb_srf_outvec_ns_t* outputs_ptr_ns,
                                            uint8_t outputs_ptr_cnt_ns)
{
    CY_UNUSED_PARAM(inputs_ptr_cnt_ns);
    CY_UNUSED_PARAM(outputs_ptr_ns);
    CY_UNUSED_PARAM(outputs_ptr_cnt_ns);

    CY_ASSERT_L2((inputs_ns->request).module_id == MTB_SRF_MODULE_PDL);
    CY_ASSERT_L2((inputs_ns->request).op_id == CY_PDL_SMIF_OP_INVALIDATE_CACHE);
    CY_ASSERT_L2((inputs_ns->request).submodule_id == CY_PDL_SECURE_SUBMODULE_SMIF);
    CY_ASSERT_L2(outputs_ns[0].len >= sizeof(cy_en_smif_status_t));

    cy_en_smif_status_t retVal = CY_SMIF_SUCCESS;
    bool is_secure_view = false;
    uint32_t address = 0;
    uint32_t size = 0;

    memcpy(&is_secure_view, &(inputs_ns->input_values[0]), sizeof((is_secure_view)));
    memcpy(&address, &(inputs_ns->input_values[sizeof(is_secure_view)]), sizeof(address));
    memcpy(&size, &(inputs_ns->input_values[sizeof(is_secure_view) + sizeof(address)]), sizeof(size));

    retVal = Cy_SMIF_Invalidate_Cache_by_Addr((SMIF_CACHE_BLOCK_Type *)GET_ALIAS_ADDRESS((inputs_ns->request).base),
                                        is_secure_view,
                                        address,
                                        size);
    memcpy(&outputs_ns->output_values[0], &retVal, sizeof(retVal));
    return CY_RSLT_SUCCESS;
}
cy_rslt_t cy_pdl_smif_srf_cl_inv_cache_impl_s(mtb_srf_input_ns_t* inputs_ns,
                                            mtb_srf_output_ns_t* outputs_ns,
                                            mtb_srf_invec_ns_t* inputs_ptr_ns,
                                            uint8_t inputs_ptr_cnt_ns,
                                            mtb_srf_outvec_ns_t* outputs_ptr_ns,
                                            uint8_t outputs_ptr_cnt_ns)
{
    CY_UNUSED_PARAM(inputs_ptr_cnt_ns);
    CY_UNUSED_PARAM(outputs_ptr_ns);
    CY_UNUSED_PARAM(outputs_ptr_cnt_ns);

    CY_ASSERT_L2((inputs_ns->request).module_id == MTB_SRF_MODULE_PDL);
    CY_ASSERT_L2((inputs_ns->request).op_id == CY_PDL_SMIF_OP_CL_INV_CACHE);
    CY_ASSERT_L2((inputs_ns->request).submodule_id == CY_PDL_SECURE_SUBMODULE_SMIF);

    cy_en_smif_status_t retVal = CY_SMIF_SUCCESS;
    bool is_secure_view = false;
    uint32_t address = 0;
    uint32_t size = 0;
    memcpy(&is_secure_view, &(inputs_ns->input_values[0]), sizeof(is_secure_view));
    memcpy(&address, &(inputs_ns->input_values[sizeof(is_secure_view)]), sizeof(address));
    memcpy(&size, &(inputs_ns->input_values[sizeof(is_secure_view) + sizeof(address)]), sizeof(size));

    retVal = Cy_SMIF_Clean_And_Invalidate_Cache_by_Addr((SMIF_CACHE_BLOCK_Type *)GET_ALIAS_ADDRESS((inputs_ns->request).base),
                                        is_secure_view,
                                        address,
                                        size);
    memcpy(&outputs_ns->output_values[0], &retVal, sizeof(retVal));
    return CY_RSLT_SUCCESS;
}


/* All operations for the SMIF submodule of the PDL module */
mtb_srf_op_s_t _cy_pdl_smif_srf_operations[] =
{
    //GetInfo
    {
        .module_id = MTB_SRF_MODULE_PDL,
        .submodule_id = CY_PDL_SECURE_SUBMODULE_SMIF,
        .op_id = CY_PDL_SMIF_OP_MEM_GET_INFO,
        .write_required = false,
        .impl = cy_pdl_smif_srf_get_info_impl_s,
        .input_values_len = sizeof(uint8_t),
        .output_values_len = sizeof(cy_en_smif_status_t),
        .input_len = {0, 0, 0},
        .needs_copy = {false, false, false },
        .output_len = {sizeof(cy_stc_smif_mem_info_t), 0, 0},
        .allowed_rsc = mtb_pdl_smif_srf_permissions,
        .num_allowed = (sizeof(mtb_pdl_smif_srf_permissions)/sizeof(mtb_pdl_smif_srf_permissions[0]))
    },
    // MemRead
    {
        .module_id = MTB_SRF_MODULE_PDL,
        .submodule_id = CY_PDL_SECURE_SUBMODULE_SMIF,
        .op_id = CY_PDL_SMIF_OP_MEM_READ,
        .write_required = false,
        .impl = cy_pdl_smif_srf_mem_num_read_impl_s,
        .input_values_len = sizeof(uint8_t) + sizeof(uint32_t),
        .output_values_len = sizeof(cy_en_smif_status_t),
        .input_len = {0, 0, 0},
        .needs_copy = {false, false, false },
        //The output param is the rx_buffer and its length is part of the request so we are forced to use a minimum length here corresponding to 1 word
        .output_len = {0x1, 0, 0},
        .allowed_rsc = mtb_pdl_smif_srf_permissions,
        .num_allowed = (sizeof(mtb_pdl_smif_srf_permissions)/sizeof(mtb_pdl_smif_srf_permissions[0]))
    },
    // MemWrite
    {
        .module_id = MTB_SRF_MODULE_PDL,
        .submodule_id = CY_PDL_SECURE_SUBMODULE_SMIF,
        .op_id = CY_PDL_SMIF_OP_MEM_WRITE,
        .write_required = true,
        .impl = cy_pdl_smif_srf_mem_num_write_impl_s,
        .input_values_len = (sizeof(uint8_t) + sizeof(uint32_t)),
        .output_values_len = sizeof(cy_en_smif_status_t),
        //The first param is the tx_buffer and its length is part of the request so we are forced to use a minimum length here corresponding to 1 word
        .input_len = {0x1, 0, 0},
        .needs_copy = {false, false, false }, /* Don't copy the buffer. No validation decisions are made based on its contents */
        .output_len = {0, 0, 0},
        .allowed_rsc = mtb_pdl_smif_srf_permissions,
        .num_allowed = (sizeof(mtb_pdl_smif_srf_permissions)/sizeof(mtb_pdl_smif_srf_permissions[0]))
    },
    // MemEraseSector
    {
        .module_id = MTB_SRF_MODULE_PDL,
        .submodule_id = CY_PDL_SECURE_SUBMODULE_SMIF,
        .op_id = CY_PDL_SMIF_OP_MEM_ERASE_SECTOR,
        .write_required = true,
        .impl = cy_pdl_smif_srf_mem_num_erase_sector_impl_s,
        .input_values_len = sizeof(uint8_t) + sizeof(uint32_t) + sizeof(uint32_t),
        .output_values_len = sizeof(cy_en_smif_status_t),
        .input_len = {0, 0, 0},
        .needs_copy = {false, false, false },
        .output_len = {0, 0, 0},
        .allowed_rsc = mtb_pdl_smif_srf_permissions,
        .num_allowed = (sizeof(mtb_pdl_smif_srf_permissions)/sizeof(mtb_pdl_smif_srf_permissions[0]))
    },
    // MemEraseChip
    {
        .module_id = MTB_SRF_MODULE_PDL,
        .submodule_id = CY_PDL_SECURE_SUBMODULE_SMIF,
        .op_id = CY_PDL_SMIF_OP_MEM_ERASE_CHIP,
        .write_required = true,
        .impl = cy_pdl_smif_srf_mem_num_erase_chip_impl_s,
        .input_values_len = sizeof(uint8_t),
        .output_values_len = sizeof(cy_en_smif_status_t),
        .input_len = {0, 0, 0},
        .needs_copy = {false, false, false},
        .output_len = {0, 0, 0},
        .allowed_rsc = mtb_pdl_smif_srf_permissions,
        .num_allowed = (sizeof(mtb_pdl_smif_srf_permissions)/sizeof(mtb_pdl_smif_srf_permissions[0]))
    },
    // HyperBusMemRead
    {
        .module_id = MTB_SRF_MODULE_PDL,
        .submodule_id = CY_PDL_SECURE_SUBMODULE_SMIF,
        .op_id = CY_PDL_SMIF_OP_HB_READ,
        .write_required = false,
        .impl = cy_pdl_smif_srf_mem_num_hb_read_impl_s,
        .input_values_len = sizeof(uint8_t) + sizeof(uint32_t),
        .output_values_len = sizeof(cy_en_smif_status_t),
        .input_len = {0, 0, 0},
        .needs_copy = {false, false, false },
        //The output param is the rx_buffer and its length is part of the request so we are forced to use a minimum length here corresponding to 1 word
        .output_len = {0x1, 0, 0},
        .allowed_rsc = mtb_pdl_smif_srf_permissions,
        .num_allowed = (sizeof(mtb_pdl_smif_srf_permissions)/sizeof(mtb_pdl_smif_srf_permissions[0]))
    },
    // HyperBusMemWrite
    {
        .module_id = MTB_SRF_MODULE_PDL,
        .submodule_id = CY_PDL_SECURE_SUBMODULE_SMIF,
        .op_id = CY_PDL_SMIF_OP_HB_WRITE,
        .write_required = true,
        .impl = cy_pdl_smif_srf_mem_num_hb_write_impl_s,
        .input_values_len = sizeof(uint8_t) + sizeof(uint32_t),
        .output_values_len = sizeof(cy_en_smif_status_t),
        //The first param is the tx_buffer and its length is part of the request so we are forced to use a minimum length here corresponding to 1 word
        .input_len = {0x1, 0, 0},
        .needs_copy = {false, false, false },
        .output_len = {0, 0, 0},
        .allowed_rsc = mtb_pdl_smif_srf_permissions,
        .num_allowed = (sizeof(mtb_pdl_smif_srf_permissions)/sizeof(mtb_pdl_smif_srf_permissions[0]))
    },
    // CleanCache
    {
        .module_id = MTB_SRF_MODULE_PDL,
        .submodule_id = CY_PDL_SECURE_SUBMODULE_SMIF,
        .op_id = CY_PDL_SMIF_OP_CLEAN_CACHE,
        .write_required = true,
        .impl = cy_pdl_smif_srf_clean_cache_impl_s,
        .input_values_len = sizeof(bool) + sizeof(uint32_t) + sizeof(uint32_t),
        .output_values_len = sizeof(cy_en_smif_status_t),
        .input_len = {0, 0, 0},
        .needs_copy = {false, false, false },
        .output_len = {0, 0, 0},
        .allowed_rsc = mtb_pdl_smif_srf_permissions,
        .num_allowed = (sizeof(mtb_pdl_smif_srf_permissions)/sizeof(mtb_pdl_smif_srf_permissions[0]))
    },
    // InvalidateCache
    {
        .module_id = MTB_SRF_MODULE_PDL,
        .submodule_id = CY_PDL_SECURE_SUBMODULE_SMIF,
        .op_id = CY_PDL_SMIF_OP_INVALIDATE_CACHE,
        .write_required = true,
        .impl = cy_pdl_smif_srf_invalidate_cache_impl_s,
        .input_values_len = sizeof(bool) + sizeof(uint32_t) + sizeof(uint32_t),
        .output_values_len = sizeof(cy_en_smif_status_t),
        .input_len = {0, 0, 0},
        .needs_copy = {false, false, false },
        .output_len = {0, 0, 0},
        .allowed_rsc = mtb_pdl_smif_srf_permissions,
        .num_allowed = (sizeof(mtb_pdl_smif_srf_permissions)/sizeof(mtb_pdl_smif_srf_permissions[0]))
    },
    // CleanInvalidateCache
    {
        .module_id = MTB_SRF_MODULE_PDL,
        .submodule_id = CY_PDL_SECURE_SUBMODULE_SMIF,
        .op_id = CY_PDL_SMIF_OP_CL_INV_CACHE,
        .write_required = true,
        .impl = cy_pdl_smif_srf_cl_inv_cache_impl_s,
        .input_values_len = sizeof(bool) + sizeof(uint32_t) + sizeof(uint32_t),
        .output_values_len = sizeof(cy_en_smif_status_t),
        .input_len = {0, 0, 0},
        .needs_copy = {false, false, false },
        .output_len = {0, 0, 0},
        .allowed_rsc = mtb_pdl_smif_srf_permissions,
        .num_allowed = (sizeof(mtb_pdl_smif_srf_permissions)/sizeof(mtb_pdl_smif_srf_permissions[0]))
    },
};

#endif /* defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_SMIF_ENABLE_SRF_INTEG) */



cy_en_smif_status_t Cy_SMIF_MemNumInit(SMIF_Type *base,
                            cy_stc_smif_block_config_t const * blockConfig,
                            cy_stc_smif_mem_context_t *context)
{
    cy_en_smif_status_t result = CY_SMIF_GENERAL_ERROR;

    //Determine whether or not the peripheral is secured
#if defined(COMPONENT_SECURE_DEVICE)
    context->requires_secure_call = false;
#else
    #if defined(_CY_PDL_SMIF_PPC_SECURED) && (_CY_PDL_SMIF_PPC_SECURED)
    uint8_t smif_number = _Cy_SMIF_GetSmifNumber(base);
        #if defined(_CY_PDL_SMIF0_PPC_SECURED) && (_CY_PDL_SMIF0_PPC_SECURED)
            context->requires_secure_call = (smif_number == CY_SMIF_SUB_BLOCK_0) ? true : false;
        #endif
        #if defined(_CY_PDL_SMIF1_PPC_SECURED) && (_CY_PDL_SMIF1_PPC_SECURED)
            context->requires_secure_call |= (smif_number == CY_SMIF_SUB_BLOCK_1) ? true : false;
        #endif
    #else
        context->requires_secure_call = false;
    #endif
#endif

    if(context->requires_secure_call == false)
    {
        result = Cy_SMIF_MemInit(base, blockConfig, &context->smif_context);

        if(result == CY_SMIF_SUCCESS )
        {
            context->base = base;
            context->block_config = blockConfig;
            #if defined(COMPONENT_SECURE_DEVICE)
            //Store context info for the NS usage
            uint8_t smif_number = _Cy_SMIF_GetSmifNumber(base);
            smif_internal_secure_contexts[smif_number] = context;
            #endif
        }
    }

    return result;
}

#if !defined(COMPONENT_SECURE_DEVICE)
cy_en_smif_status_t Cy_SMIF_MemNumSetupNonSecure(SMIF_Type *base,
                            cy_stc_smif_mem_context_t *context)
{
    memset(context, 0x00, sizeof(cy_stc_smif_mem_context_t));
    uint8_t smif_number = _Cy_SMIF_GetSmifNumber(base);
    CY_UNUSED_PARAM(smif_number); /* May be unused depending on the defines below */
    //No initialization done, only populating the context with the info available to NS
    context->base = base;
#if defined(_CY_PDL_SMIF_PPC_SECURED)
    #if defined(_CY_PDL_SMIF0_PPC_SECURED) && (_CY_PDL_SMIF0_PPC_SECURED)
        context->requires_secure_call = (smif_number == CY_SMIF_SUB_BLOCK_0) ? true : false;
    #endif
    #if defined(_CY_PDL_SMIF1_PPC_SECURED) && (_CY_PDL_SMIF1_PPC_SECURED)
        context->requires_secure_call |= (smif_number == CY_SMIF_SUB_BLOCK_1) ? true : false;
    #endif
#else
    context->requires_secure_call = false;
#endif
    return CY_SMIF_SUCCESS;
}
#endif

cy_en_smif_status_t Cy_SMIF_MemNumGetInfo(cy_stc_smif_mem_context_t *context,
                            uint8_t memNum,
                            cy_stc_smif_mem_info_t *memNumInfo)
{

    uint8_t smif_number = _Cy_SMIF_GetSmifNumber(context->base);

#if !defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_SMIF_ENABLE_SRF_INTEG)
    if(context->requires_secure_call)
    {
        mtb_srf_invec_ns_t* inVec = NULL;
        mtb_srf_outvec_ns_t* outVec = NULL;
        mtb_srf_output_ns_t* output = NULL;
        uint8_t input_args[sizeof(memNum)];
        memcpy(&(input_args[0]), &memNum, sizeof(memNum));

        cy_rslt_t result = mtb_srf_pool_allocate(&cy_pdl_srf_default_pool, &inVec, &outVec, 1000);
        CY_ASSERT_L2(result == CY_RSLT_SUCCESS);

        cy_en_smif_status_t op_result = 0;

        void* outvec_bases[] = {memNumInfo, NULL};
        size_t outvec_sizes[] = {sizeof(cy_stc_smif_mem_info_t), 0UL};

        cy_pdl_invoke_srf_args invoke_args =
        {
            .inVec = inVec,
            .outVec = outVec,
            .output_ptr = &output,
            .op_id = CY_PDL_SMIF_OP_MEM_GET_INFO,
            .submodule_id = CY_PDL_SECURE_SUBMODULE_SMIF,
            .base = context->base,
            .sub_block = smif_number,
            .input_base = input_args,
            .input_len = sizeof(uint8_t),
            .output_base = (uint8_t*)&op_result,
            .output_len = sizeof(op_result),
            .invec_bases = NULL,
            .invec_sizes = NULL,
            .outvec_bases = outvec_bases,
            .outvec_sizes = outvec_sizes,
        };
        result = _Cy_PDL_Invoke_SRF(&invoke_args);
        if (result == MTB_SRF_ERR_SECURITY_POLICY_VIOLATION)
        {
            (void)mtb_srf_pool_free(&cy_pdl_srf_default_pool, inVec, outVec);
            return result;
        }
        else
        {
            CY_ASSERT_L2(result == CY_RSLT_SUCCESS);
        }

        memcpy(&op_result, (&(output->output_values[0])), sizeof(op_result));

        result = mtb_srf_pool_free(&cy_pdl_srf_default_pool, inVec, outVec);
        CY_ASSERT_L2(result == CY_RSLT_SUCCESS);
        CY_UNUSED_PARAM(result);

        return op_result;
    }
#endif

    cy_en_smif_status_t result = CY_SMIF_SUCCESS;

    uint8_t memConfigNumber = _Cy_SMIF_GetConfigNumber(context, smif_number, memNum);

#if defined(COMPONENT_SECURE_DEVICE)
    if(context->requires_secure_call)
    {
        cy_stc_smif_mem_device_cfg_t*  devCfg = smif_internal_secure_contexts[smif_number]->block_config->memConfig[memConfigNumber]->deviceCfg;
        cy_stc_smif_hbmem_device_config_t* hbDevCfg = smif_internal_secure_contexts[smif_number]->block_config->memConfig[memConfigNumber]->hbdeviceCfg;

        if((devCfg != NULL))
        {
            memNumInfo->flags = CY_SMIF_FLAG_SPI_DEVICE;
            memNumInfo->memSize = devCfg->memSize;
            memNumInfo->eraseSize = devCfg->eraseSize;
            memNumInfo->programSize = devCfg->programSize;

            //Copy info relevant to Hybrid Regions if present
            memNumInfo->hybridRegionCount = devCfg->hybridRegionCount;
            for(uint8_t index = 0; index < memNumInfo->hybridRegionCount; index ++)
            {
                memNumInfo->hybridRegionInfo[index].regionStartAddress = devCfg->hybridRegionInfo[index]->regionAddress;
                memNumInfo->hybridRegionInfo[index].eraseSize = devCfg->hybridRegionInfo[index]->eraseSize;
                memNumInfo->hybridRegionInfo[index].regionEndAddress = (devCfg->hybridRegionInfo[index]->sectorsCount * memNumInfo->hybridRegionInfo[index].eraseSize) + memNumInfo->hybridRegionInfo[index].regionStartAddress ;
            }
        }
        else
        {
            memNumInfo->flags = CY_SMIF_FLAG_HYPERBUS_DEVICE;
            memNumInfo->memSize = hbDevCfg->memSize;
            memNumInfo->eraseSize = 0;
        }
    }
    else
#endif
    {
        if(!context->requires_secure_call)
        {
            cy_stc_smif_mem_device_cfg_t*  devCfg = context->block_config->memConfig[memConfigNumber]->deviceCfg;
            cy_stc_smif_hbmem_device_config_t* hbDevCfg = context->block_config->memConfig[memConfigNumber]->hbdeviceCfg;

            if((devCfg != NULL))
            {
                memNumInfo->flags = CY_SMIF_FLAG_SPI_DEVICE;
                memNumInfo->memSize = devCfg->memSize;
                memNumInfo->eraseSize = devCfg->eraseSize;
                memNumInfo->programSize = devCfg->programSize;

                //Copy info relevant to Hybrid Regions if present
                memNumInfo->hybridRegionCount = devCfg->hybridRegionCount;
                for(uint8_t index = 0; index < memNumInfo->hybridRegionCount; index ++)
                {
                    memNumInfo->hybridRegionInfo[index].regionStartAddress = devCfg->hybridRegionInfo[index]->regionAddress;
                    memNumInfo->hybridRegionInfo[index].eraseSize = devCfg->hybridRegionInfo[index]->eraseSize;
                    memNumInfo->hybridRegionInfo[index].regionEndAddress = (devCfg->hybridRegionInfo[index]->sectorsCount * memNumInfo->hybridRegionInfo[index].eraseSize) + memNumInfo->hybridRegionInfo[index].regionStartAddress ;
                }
            }
            else
            {
                memNumInfo->flags = CY_SMIF_FLAG_HYPERBUS_DEVICE;
                memNumInfo->memSize = hbDevCfg->memSize;
                memNumInfo->eraseSize = 0;
            }
        }
        else
        {
            result = CY_SMIF_GENERAL_ERROR;
        }
    }

    return result;
}

cy_en_smif_status_t Cy_SMIF_MemNumRead(cy_stc_smif_mem_context_t *context, uint8_t memNum,
                                    uint32_t address, uint8_t rxBuffer[],
                                    uint32_t length)
{
    uint8_t smif_number = _Cy_SMIF_GetSmifNumber(context->base);

#if !defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_SMIF_ENABLE_SRF_INTEG)
    if(context->requires_secure_call)
    {

        mtb_srf_invec_ns_t* inVec = NULL;
        mtb_srf_outvec_ns_t* outVec = NULL;
        mtb_srf_output_ns_t* output = NULL;

        uint8_t input_args[sizeof(memNum) + sizeof(address)];
        memcpy(&(input_args[0]), &memNum, sizeof(memNum));
        memcpy(&(input_args[sizeof(memNum)]), &address, sizeof(address));

        cy_rslt_t result = mtb_srf_pool_allocate(&cy_pdl_srf_default_pool, &inVec, &outVec, 1000);
        CY_ASSERT_L2(result == CY_RSLT_SUCCESS);

        void* outvec_bases[] = {rxBuffer, NULL};
        size_t outvec_sizes[] = {length, 0UL};

        cy_en_smif_status_t op_result = 0;

        cy_pdl_invoke_srf_args invoke_args =
        {
            .inVec = inVec,
            .outVec = outVec,
            .output_ptr = &output,
            .op_id = CY_PDL_SMIF_OP_MEM_READ,
            .submodule_id = CY_PDL_SECURE_SUBMODULE_SMIF,
            .base = context->base,
            .sub_block = smif_number,
            .input_base = input_args,
            .input_len = sizeof(uint8_t) + sizeof(uint32_t) + sizeof(uint32_t),
            .output_base = (uint8_t*)&op_result,
            .output_len = sizeof(op_result),
            .invec_bases = NULL,
            .invec_sizes = NULL,
            .outvec_bases = outvec_bases,
            .outvec_sizes = outvec_sizes
        };

        result = _Cy_PDL_Invoke_SRF(&invoke_args);
        if (result == MTB_SRF_ERR_SECURITY_POLICY_VIOLATION)
        {
            (void)mtb_srf_pool_free(&cy_pdl_srf_default_pool, inVec, outVec);
            return result;
        }
        else
        {
            CY_ASSERT_L2(result == CY_RSLT_SUCCESS);
        }

        memcpy(&op_result, (cy_rslt_t*)(&(output->output_values[0])), sizeof(op_result));

        result = mtb_srf_pool_free(&cy_pdl_srf_default_pool, inVec, outVec);
        CY_ASSERT_L2(result == CY_RSLT_SUCCESS);
        CY_UNUSED_PARAM(result);

        return op_result;
    }

#endif

#if defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_SMIF_ENABLE_SRF_INTEG)
    if(context->requires_secure_call && !_Cy_SMIF_IsAddressRangeNSAccessible(smif_internal_secure_contexts[smif_number], memNum, address, length))
    {
        return MTB_SRF_ERR_SECURITY_POLICY_VIOLATION;
    }
    else
#endif
    {
        uint8_t memConfigNumber = _Cy_SMIF_GetConfigNumber(context, smif_number, memNum);
#if defined(COMPONENT_SECURE_DEVICE)
        if(context->requires_secure_call)
        {
            cy_en_smif_status_t result = Cy_SMIF_MemRead((SMIF_Type*)(GET_ALIAS_ADDRESS(context->base)), smif_internal_secure_contexts[smif_number]->block_config->memConfig[memConfigNumber],
                                                        address, rxBuffer, length, &smif_internal_secure_contexts[smif_number]->smif_context );
            return result;
        }
        else
#endif
        {
            cy_en_smif_status_t result = Cy_SMIF_MemRead(context->base, context->block_config->memConfig[memConfigNumber], address, rxBuffer, length, &context->smif_context );
            return result;
        }
    }
}

cy_en_smif_status_t Cy_SMIF_MemNumWrite(cy_stc_smif_mem_context_t *context, uint8_t memNum,
                                     uint32_t address, uint8_t const txBuffer[],
                                     uint32_t length)
{
    uint8_t smif_number = _Cy_SMIF_GetSmifNumber(context->base);

#if !defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_SMIF_ENABLE_SRF_INTEG)
    if(context->requires_secure_call)
    {
        mtb_srf_invec_ns_t* inVec = NULL;
        mtb_srf_outvec_ns_t* outVec = NULL;
        mtb_srf_output_ns_t* output = NULL;

        uint8_t input_args[sizeof(memNum) + sizeof(address)];
        memcpy(&(input_args[0]), &memNum, sizeof(memNum));
        memcpy(&(input_args[sizeof(memNum)]), &address, sizeof(address));

        cy_rslt_t result = mtb_srf_pool_allocate(&cy_pdl_srf_default_pool, &inVec, &outVec, 1000);
        CY_ASSERT_L2(result == CY_RSLT_SUCCESS);

        void* invec_bases[] = {(void*)txBuffer, NULL};
        size_t invec_sizes[] = {length, 0UL};

        cy_en_smif_status_t op_result = 0;

        cy_pdl_invoke_srf_args invoke_args =
        {
            .inVec = inVec,
            .outVec = outVec,
            .output_ptr = &output,
            .op_id = CY_PDL_SMIF_OP_MEM_WRITE,
            .submodule_id = CY_PDL_SECURE_SUBMODULE_SMIF,
            .base = context->base,
            .sub_block = smif_number,
            .input_base = input_args,
            .input_len = sizeof(input_args),
            .output_base = (uint8_t*)&op_result,
            .output_len = sizeof(op_result),
            .invec_bases = invec_bases,
            .invec_sizes = invec_sizes,
            .outvec_bases = NULL,
            .outvec_sizes = NULL
        };

        result = _Cy_PDL_Invoke_SRF(&invoke_args);
        if (result == MTB_SRF_ERR_SECURITY_POLICY_VIOLATION)
        {
            (void)mtb_srf_pool_free(&cy_pdl_srf_default_pool, inVec, outVec);
            return result;
        }
        else
        {
            CY_ASSERT_L2(result == CY_RSLT_SUCCESS);
        }

        memcpy(&op_result, (cy_rslt_t*)(&(output->output_values[0])), sizeof(op_result));

        result = mtb_srf_pool_free(&cy_pdl_srf_default_pool, inVec, outVec);
        CY_ASSERT_L2(result == CY_RSLT_SUCCESS);
        CY_UNUSED_PARAM(result);

        return op_result;
    }

#endif
#if defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_SMIF_ENABLE_SRF_INTEG)
    if(context->requires_secure_call && !_Cy_SMIF_IsAddressRangeNSAccessible(smif_internal_secure_contexts[smif_number], memNum, address, length))
    {
        return MTB_SRF_ERR_SECURITY_POLICY_VIOLATION;
    }
    else
#endif
    {
        uint8_t memConfigNumber = _Cy_SMIF_GetConfigNumber(context, smif_number, memNum);
#if defined(COMPONENT_SECURE_DEVICE)
        if(context->requires_secure_call)
        {
            cy_en_smif_status_t result = Cy_SMIF_MemWrite((SMIF_Type*)(GET_ALIAS_ADDRESS(context->base)), smif_internal_secure_contexts[smif_number]->block_config->memConfig[memConfigNumber],
                                                            address, txBuffer, length, &smif_internal_secure_contexts[smif_number]->smif_context );
            return result;
        }
        else
#endif
        {
            cy_en_smif_status_t result = Cy_SMIF_MemWrite(context->base, context->block_config->memConfig[memConfigNumber], address, txBuffer, length, &context->smif_context );
            return result;
        }
    }
}

cy_en_smif_status_t Cy_SMIF_MemNumEraseSector(cy_stc_smif_mem_context_t *context, uint8_t memNum,
                                           uint32_t address, uint32_t length)
{
    uint8_t smif_number = _Cy_SMIF_GetSmifNumber(context->base);

#if !defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_SMIF_ENABLE_SRF_INTEG)
    if(context->requires_secure_call)
    {
        mtb_srf_invec_ns_t* inVec = NULL;
        mtb_srf_outvec_ns_t* outVec = NULL;
        mtb_srf_output_ns_t* output = NULL;

        uint8_t input_args[sizeof(memNum) + sizeof(address) + sizeof(length)];
        memcpy(&(input_args[0]), &memNum, sizeof(memNum));
        memcpy(&(input_args[sizeof(memNum)]), &address, sizeof(address));
        memcpy(&(input_args[sizeof(memNum) + sizeof(address)]), &length, sizeof(length));

        cy_rslt_t result = mtb_srf_pool_allocate(&cy_pdl_srf_default_pool, &inVec, &outVec, 1000);
        CY_ASSERT_L2(result == CY_RSLT_SUCCESS);

        cy_en_smif_status_t op_result = 0;

        cy_pdl_invoke_srf_args invoke_args =
        {
            .inVec = inVec,
            .outVec = outVec,
            .output_ptr = &output,
            .op_id = CY_PDL_SMIF_OP_MEM_ERASE_SECTOR,
            .submodule_id = CY_PDL_SECURE_SUBMODULE_SMIF,
            .base = context->base,
            .sub_block = smif_number,
            .input_base = input_args,
            .input_len = sizeof(uint8_t) + sizeof(uint32_t) + sizeof(uint32_t),
            .output_base = (uint8_t*)&op_result,
            .output_len = sizeof(op_result),
            .invec_bases = NULL,
            .invec_sizes = NULL,
            .outvec_bases = NULL,
            .outvec_sizes = NULL
        };

        result = _Cy_PDL_Invoke_SRF(&invoke_args);
        if (result == MTB_SRF_ERR_SECURITY_POLICY_VIOLATION)
        {
            (void)mtb_srf_pool_free(&cy_pdl_srf_default_pool, inVec, outVec);
            return result;
        }
        else
        {
            CY_ASSERT_L2(result == CY_RSLT_SUCCESS);
        }

        memcpy(&op_result, (cy_rslt_t*)(&(output->output_values[0])), sizeof(op_result));

        result = mtb_srf_pool_free(&cy_pdl_srf_default_pool, inVec, outVec);
        CY_ASSERT_L2(result == CY_RSLT_SUCCESS);
        CY_UNUSED_PARAM(result);

        return op_result;
    }

#endif

 #if defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_SMIF_ENABLE_SRF_INTEG)
   if(context->requires_secure_call && !_Cy_SMIF_IsAddressRangeNSAccessible(smif_internal_secure_contexts[smif_number], memNum, address, length))
    {
        return MTB_SRF_ERR_SECURITY_POLICY_VIOLATION;
    }
    else
#endif
    {
        uint8_t memConfigNumber = _Cy_SMIF_GetConfigNumber(context, smif_number, memNum);
#if defined(COMPONENT_SECURE_DEVICE)
        if(context->requires_secure_call)
        {
            cy_en_smif_status_t result = Cy_SMIF_MemEraseSector((SMIF_Type*)(GET_ALIAS_ADDRESS(context->base)), smif_internal_secure_contexts[smif_number]->block_config->memConfig[memConfigNumber],
                                                            address, length, &smif_internal_secure_contexts[smif_number]->smif_context );
            return result;
        }
        else
#endif
        {
            cy_en_smif_status_t result = Cy_SMIF_MemEraseSector(context->base, context->block_config->memConfig[memConfigNumber], address, length, &context->smif_context );
            return result;
        }
    }
}


cy_en_smif_status_t Cy_SMIF_MemNumEraseChip(cy_stc_smif_mem_context_t *context, uint8_t memNum)
{
    uint8_t smif_number = _Cy_SMIF_GetSmifNumber(context->base);

#if !defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_SMIF_ENABLE_SRF_INTEG) && defined(_CY_PDL_SMIF_PPC_SECURED)
    if(context->requires_secure_call)
    {
        mtb_srf_invec_ns_t* inVec = NULL;
        mtb_srf_outvec_ns_t* outVec = NULL;
        mtb_srf_output_ns_t* output = NULL;

        uint8_t input_args[sizeof(memNum)];
        memcpy(&(input_args[0]), &memNum, sizeof(memNum));

        cy_rslt_t result = mtb_srf_pool_allocate(&cy_pdl_srf_default_pool, &inVec, &outVec, 1000);
        CY_ASSERT_L2(result == CY_RSLT_SUCCESS);

        cy_en_smif_status_t op_result = 0;

        cy_pdl_invoke_srf_args invoke_args =
        {
            .inVec = inVec,
            .outVec = outVec,
            .output_ptr = &output,
            .op_id = CY_PDL_SMIF_OP_MEM_ERASE_CHIP,
            .submodule_id = CY_PDL_SECURE_SUBMODULE_SMIF,
            .base = context->base,
            .sub_block = smif_number,
            .input_base = input_args,
            .input_len = sizeof(uint8_t),
            .output_base = (uint8_t*)&op_result,
            .output_len = sizeof(op_result),
            .invec_bases = NULL,
            .invec_sizes = NULL,
            .outvec_bases = NULL,
            .outvec_sizes = NULL
        };

        result = _Cy_PDL_Invoke_SRF(&invoke_args);
        if (result == MTB_SRF_ERR_SECURITY_POLICY_VIOLATION)
        {
            (void)mtb_srf_pool_free(&cy_pdl_srf_default_pool, inVec, outVec);
            return result;
        }
        else
        {
            CY_ASSERT_L2(result == CY_RSLT_SUCCESS);
        }
        memcpy(&op_result, (cy_rslt_t*)(&(output->output_values[0])), sizeof(op_result));

        result = mtb_srf_pool_free(&cy_pdl_srf_default_pool, inVec, outVec);
        CY_ASSERT_L2(result == CY_RSLT_SUCCESS);
        CY_UNUSED_PARAM(result);

        return op_result;
    }
#endif

#if defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_SMIF_ENABLE_SRF_INTEG)
    if(context->requires_secure_call && !_Cy_SMIF_IsAddressRangeNSAccessible(smif_internal_secure_contexts[smif_number], memNum, 0u, 0u))
    {
        return MTB_SRF_ERR_SECURITY_POLICY_VIOLATION;
    }
    else
#endif
    {
        uint8_t memConfigNumber = _Cy_SMIF_GetConfigNumber(context, smif_number, memNum);
#if defined(COMPONENT_SECURE_DEVICE)
        if(context->requires_secure_call)
        {
            cy_en_smif_status_t result = Cy_SMIF_MemEraseChip((SMIF_Type*)(GET_ALIAS_ADDRESS(context->base)), smif_internal_secure_contexts[smif_number]->block_config->memConfig[memConfigNumber], &smif_internal_secure_contexts[smif_number]->smif_context );
            return result;
        }
        else
#endif
        {
            cy_en_smif_status_t result = Cy_SMIF_MemEraseChip(context->base, context->block_config->memConfig[memConfigNumber], &context->smif_context );
            return result;
        }
    }
}

cy_en_smif_status_t Cy_SMIF_MemNumHyperBusRead(cy_stc_smif_mem_context_t *context, uint8_t memNum,
                                    uint32_t address, uint8_t rxBuffer[],
                                    uint32_t length)
{
    uint8_t smif_number = _Cy_SMIF_GetSmifNumber(context->base);

#if !defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_SMIF_ENABLE_SRF_INTEG)
    if(context->requires_secure_call)
    {
        mtb_srf_invec_ns_t* inVec = NULL;
        mtb_srf_outvec_ns_t* outVec = NULL;
        mtb_srf_output_ns_t* output = NULL;

        cy_rslt_t result = mtb_srf_pool_allocate(&cy_pdl_srf_default_pool, &inVec, &outVec, 1000);
        CY_ASSERT_L2(result == CY_RSLT_SUCCESS);

        uint8_t input_args[sizeof(memNum) + sizeof(address)];
        memcpy(&(input_args[0]), &memNum, sizeof(memNum));
        memcpy(&(input_args[sizeof(memNum)]), &address, sizeof(address));

        cy_en_smif_status_t op_result = 0;

        void* outvec_bases[] = {rxBuffer, NULL};
        size_t outvec_sizes[] = {length, 0UL};
        cy_pdl_invoke_srf_args invoke_args =
        {
            .inVec = inVec,
            .outVec = outVec,
            .output_ptr = &output,
            .op_id = CY_PDL_SMIF_OP_HB_READ,
            .submodule_id = CY_PDL_SECURE_SUBMODULE_SMIF,
            .base = context->base,
            .sub_block = smif_number,
            .input_base = (uint8_t*)input_args,
            .input_len = sizeof(input_args),
            .output_base = (uint8_t*)&op_result,
            .output_len = sizeof(op_result),
            .invec_bases = NULL,
            .invec_sizes = NULL,
            .outvec_bases = outvec_bases,
            .outvec_sizes = outvec_sizes
        };
        result = _Cy_PDL_Invoke_SRF(&invoke_args);
        if (result == MTB_SRF_ERR_SECURITY_POLICY_VIOLATION)
        {
            (void)mtb_srf_pool_free(&cy_pdl_srf_default_pool, inVec, outVec);
            return result;
        }
        else
        {
            CY_ASSERT_L2(result == CY_RSLT_SUCCESS);
        }

        memcpy(&op_result, (cy_rslt_t*)(&(output->output_values[0])), sizeof(op_result));

        result = mtb_srf_pool_free(&cy_pdl_srf_default_pool, inVec, outVec);
        CY_ASSERT_L2(result == CY_RSLT_SUCCESS);
        CY_UNUSED_PARAM(result);

        return op_result;
    }
#endif

#if defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_SMIF_ENABLE_SRF_INTEG)
    if(context->requires_secure_call && !_Cy_SMIF_IsAddressRangeNSAccessible(smif_internal_secure_contexts[smif_number], memNum, address, length))
    {
        return MTB_SRF_ERR_SECURITY_POLICY_VIOLATION;
    }
    else
#endif
    {
        uint8_t memConfigNumber = _Cy_SMIF_GetConfigNumber(context, smif_number, memNum);
#if defined(COMPONENT_SECURE_DEVICE)
        if(context->requires_secure_call)
        {
	        cy_en_smif_status_t result = Cy_SMIF_HyperBus_Read((SMIF_Type*)GET_ALIAS_ADDRESS(context->base),
                                    smif_internal_secure_contexts[smif_number]->block_config->memConfig[memConfigNumber],
                                    CY_SMIF_HB_CONTINUOUS_BURST,
                                    address,
                                    length / 2, // size in half word
                                    (uint16_t*)rxBuffer,
                                    smif_internal_secure_contexts[smif_number]->block_config->memConfig[memConfigNumber]->hbdeviceCfg->dummyCycles,
                                    false, // Double initial latency
                                    true, // Blocking mode
                                    &smif_internal_secure_contexts[smif_number]->smif_context
                                    );
	        return result;
        }
        else
#endif
        {
            cy_en_smif_status_t result = Cy_SMIF_HyperBus_Read(context->base,
                                    context->block_config->memConfig[memConfigNumber],
                                    CY_SMIF_HB_CONTINUOUS_BURST,
                                    address,
                                    length / 2, // size in half word
                                    (uint16_t*)rxBuffer,
                                    context->block_config->memConfig[memConfigNumber]->hbdeviceCfg->dummyCycles,
                                    false, // Double initial latency
                                    true, // Blocking mode
                                    &context->smif_context
                                    );
        return result;
        }
    }
}

cy_en_smif_status_t Cy_SMIF_MemNumHyperBusWrite(cy_stc_smif_mem_context_t *context, uint8_t memNum,
                                     uint32_t address, uint8_t const txBuffer[],
                                     uint32_t length)
{
    uint8_t smif_number = _Cy_SMIF_GetSmifNumber(context->base);

#if !defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_SMIF_ENABLE_SRF_INTEG)
    if(context->requires_secure_call)
    {
        mtb_srf_invec_ns_t* inVec = NULL;
        mtb_srf_outvec_ns_t* outVec = NULL;
        mtb_srf_output_ns_t* output = NULL;

        cy_rslt_t result = mtb_srf_pool_allocate(&cy_pdl_srf_default_pool, &inVec, &outVec, 1000);
        CY_ASSERT_L2(result == CY_RSLT_SUCCESS);

        uint8_t input_args[sizeof(memNum) + sizeof(address)];
        memcpy(&(input_args[0]), &memNum, sizeof(memNum));
        memcpy(&(input_args[sizeof(memNum)]), &address, sizeof(address));

        cy_en_smif_status_t op_result = 0;

        void* invec_bases[] = {(void*)txBuffer, NULL};
        size_t invec_sizes[] = {length, 0UL};
        cy_pdl_invoke_srf_args invoke_args =
        {
            .inVec = inVec,
            .outVec = outVec,
            .output_ptr = &output,
            .op_id = CY_PDL_SMIF_OP_HB_WRITE,
            .submodule_id = CY_PDL_SECURE_SUBMODULE_SMIF,
            .base = context->base,
            .sub_block = smif_number,
            .input_base = (uint8_t*)input_args,
            .input_len = sizeof(input_args),
            .output_base = (uint8_t*)&op_result,
            .output_len = sizeof(op_result),
            .invec_bases = invec_bases,
            .invec_sizes = invec_sizes,
            .outvec_bases = NULL,
            .outvec_sizes = NULL
        };
        result = _Cy_PDL_Invoke_SRF(&invoke_args);
        if (result == MTB_SRF_ERR_SECURITY_POLICY_VIOLATION)
        {
            (void)mtb_srf_pool_free(&cy_pdl_srf_default_pool, inVec, outVec);
            return result;
        }
        else
        {
            CY_ASSERT_L2(result == CY_RSLT_SUCCESS);
        }

        memcpy(&op_result, (cy_rslt_t*)(&(output->output_values[0])), sizeof(op_result));

        result = mtb_srf_pool_free(&cy_pdl_srf_default_pool, inVec, outVec);
        CY_ASSERT_L2(result == CY_RSLT_SUCCESS);
        CY_UNUSED_PARAM(result);

        return op_result;
    }
#endif

#if defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_SMIF_ENABLE_SRF_INTEG)
    if(context->requires_secure_call && !_Cy_SMIF_IsAddressRangeNSAccessible(smif_internal_secure_contexts[smif_number], memNum, address, length))
    {
        return MTB_SRF_ERR_SECURITY_POLICY_VIOLATION;
    }
    else
#endif
    {
        uint8_t memConfigNumber = _Cy_SMIF_GetConfigNumber(context, smif_number, memNum);
#if defined(COMPONENT_SECURE_DEVICE)
        if(context->requires_secure_call)
        {
            cy_en_smif_status_t result = Cy_SMIF_HyperBus_Write((SMIF_Type*)GET_ALIAS_ADDRESS(context->base),
                                    smif_internal_secure_contexts[smif_number]->block_config->memConfig[memConfigNumber],
                                    CY_SMIF_HB_CONTINUOUS_BURST,
                                    address,
                                    length / 2, // size in half word
                                    (uint16_t*)txBuffer,
                                    smif_internal_secure_contexts[smif_number]->block_config->memConfig[memConfigNumber]->hbdeviceCfg->hbDevType,
                                    smif_internal_secure_contexts[smif_number]->block_config->memConfig[memConfigNumber]->hbdeviceCfg->dummyCycles, // Double initial latency
                                    true, // Blocking mode
                                    &smif_internal_secure_contexts[smif_number]->smif_context
                                    );
            return result;
        }
        else
#endif
        {
            cy_en_smif_status_t result = Cy_SMIF_HyperBus_Write(context->base,
                                    context->block_config->memConfig[memConfigNumber],
                                    CY_SMIF_HB_CONTINUOUS_BURST,
                                    address,
                                    length / 2, // size in half word
                                    (uint16_t*)txBuffer,
                                    context->block_config->memConfig[memConfigNumber]->hbdeviceCfg->hbDevType,
                                    context->block_config->memConfig[memConfigNumber]->hbdeviceCfg->dummyCycles,
                                    true, // Blocking mode
                                    &context->smif_context
                                    );
            return result;
        }
    }
}

#if defined(__cplusplus)
}
#endif

#endif /* CY_IP_MXSMIF */

/* [] END OF FILE */
