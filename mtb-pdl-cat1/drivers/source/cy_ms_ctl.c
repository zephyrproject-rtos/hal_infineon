/***************************************************************************//**
* \file  cy_ms_ctl.c
* \version 1.2
*
* \brief
* Provides an API implementation of the master security control driver.
*
********************************************************************************
* \copyright
* Copyright 2016-2020 Cypress Semiconductor Corporation
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

#include "cy_ms_ctl.h"

cy_en_ms_ctl_status_t Cy_Ms_Ctl_ConfigBusMaster(en_ms_ctl_master_t busMaster, bool privileged, bool nonSecure, uint32_t pcMask)
{
    uint32_t value;

    value = MS_CTL_PC_CTL_VX(busMaster);

    if (privileged)
    {
        value = value | ((1U << MS_CTL_P_Pos) & MS_CTL_P_Msk);
    }
    else
    {
        value = value & (~((1U << MS_CTL_P_Pos) & MS_CTL_P_Msk));
    }
    if (nonSecure)
    {
        value = value | ((1U << MS_CTL_NS_Pos) & MS_CTL_NS_Msk);
    }
    else
    {
        value = value & (~((1U << MS_CTL_NS_Pos) & MS_CTL_NS_Msk));
    }

    value &= (~MS_CTL_PC_MASK_Msk);
    value = value | ((pcMask << MS_CTL_PC_MASK_Pos) & MS_CTL_PC_MASK_Msk);
    MS_CTL_PC_CTL_VX(busMaster) = value;

    return CY_MS_CTL_SUCCESS;
}

cy_en_ms_ctl_status_t Cy_Ms_Ctl_ConfigMscAcgResp(en_ms_ctl_master_sc_acg_t busMaster, cy_en_ms_ctl_cfg_gate_resp_t gateResp, cy_en_ms_ctl_sec_resp_t secResp)
{
    uint32_t value;
    cy_en_ms_ctl_status_t ret_value = CY_MS_CTL_BAD_PARAM;
    switch (busMaster)
    {
        case CODE_MS0_MSC:
        {
            value = MS_CTL_CODE_MS0_MSC_ACG_CTL_VX;
            value &= (~(MS_CTL_CODE_MS0_MSC_ACG_CTL_CFG_GATE_RESP_VX_Msk | MS_CTL_CODE_MS0_MSC_ACG_CTL_SEC_RESP_VX_Msk));
            if (gateResp == CY_MS_CTL_GATE_RESP_ERR)
            {
                value = value | ((1U << MS_CTL_CODE_MS0_MSC_ACG_CTL_CFG_GATE_RESP_VX_Pos) & MS_CTL_CODE_MS0_MSC_ACG_CTL_CFG_GATE_RESP_VX_Msk);
            }
            if (secResp == CY_MS_CTL_SEC_RESP_ERR)
            {
                value = value | ((1U << MS_CTL_CODE_MS0_MSC_ACG_CTL_SEC_RESP_VX_Pos) & MS_CTL_CODE_MS0_MSC_ACG_CTL_SEC_RESP_VX_Msk);
            }
            MS_CTL_CODE_MS0_MSC_ACG_CTL_VX = value;
            ret_value = CY_MS_CTL_SUCCESS;
            break;
        }

        case SYS_MS0_MSC:
        {
            value = MS_CTL_SYS_MS0_MSC_ACG_CTL_VX;
            value &= (~(MS_CTL_SYS_MS0_MSC_ACG_CTL_CFG_GATE_RESP_VX_Msk | MS_CTL_SYS_MS0_MSC_ACG_CTL_SEC_RESP_VX_Msk));
            if (gateResp == CY_MS_CTL_GATE_RESP_ERR)
            {
                value = value | ((1U << MS_CTL_SYS_MS0_MSC_ACG_CTL_CFG_GATE_RESP_VX_Pos) & MS_CTL_SYS_MS0_MSC_ACG_CTL_CFG_GATE_RESP_VX_Msk);
            }
            if (secResp == CY_MS_CTL_SEC_RESP_ERR)
            {
                value = value | ((1U << MS_CTL_SYS_MS0_MSC_ACG_CTL_SEC_RESP_VX_Pos) & MS_CTL_SYS_MS0_MSC_ACG_CTL_SEC_RESP_VX_Msk);
            }
            MS_CTL_SYS_MS0_MSC_ACG_CTL_VX = value;
            ret_value = CY_MS_CTL_SUCCESS;
            break;
        }

        case SYS_MS1_MSC:
        {
            value = MS_CTL_SYS_MS1_MSC_ACG_CTL_VX;
            value &= (~(MS_CTL_SYS_MS1_MSC_ACG_CTL_CFG_GATE_RESP_VX_Msk | MS_CTL_SYS_MS1_MSC_ACG_CTL_SEC_RESP_VX_Msk));
            if (gateResp == CY_MS_CTL_GATE_RESP_ERR)
            {
                value = value | ((1U << MS_CTL_SYS_MS1_MSC_ACG_CTL_CFG_GATE_RESP_VX_Pos) & MS_CTL_SYS_MS1_MSC_ACG_CTL_CFG_GATE_RESP_VX_Msk);
            }
            if (secResp == CY_MS_CTL_SEC_RESP_ERR)
            {
                value = value | ((1U << MS_CTL_SYS_MS1_MSC_ACG_CTL_SEC_RESP_VX_Pos) & MS_CTL_SYS_MS1_MSC_ACG_CTL_SEC_RESP_VX_Msk);
            }
            MS_CTL_SYS_MS1_MSC_ACG_CTL_VX = value;
            ret_value = CY_MS_CTL_SUCCESS;
            break;
        }

        case EXP_MS_MSC:
        {
            value = MS_CTL_EXP_MS_MSC_ACG_CTL_VX;
            value &= (~(MS_CTL_EXP_MS_MSC_ACG_CTL_CFG_GATE_RESP_VX_Msk | MS_CTL_EXP_MS_MSC_ACG_CTL_SEC_RESP_VX_Msk));
            if (gateResp == CY_MS_CTL_GATE_RESP_ERR)
            {
                   value = value | ((1U << MS_CTL_EXP_MS_MSC_ACG_CTL_CFG_GATE_RESP_VX_Pos) & MS_CTL_EXP_MS_MSC_ACG_CTL_CFG_GATE_RESP_VX_Msk);
            }
            if (secResp == CY_MS_CTL_SEC_RESP_ERR)
            {
                value = value | ((1U << MS_CTL_EXP_MS_MSC_ACG_CTL_SEC_RESP_VX_Pos) & MS_CTL_EXP_MS_MSC_ACG_CTL_SEC_RESP_VX_Msk);
            }
            MS_CTL_EXP_MS_MSC_ACG_CTL_VX = value;
            ret_value = CY_MS_CTL_SUCCESS;
            break;
        }

        case DMAC0_MSC:
        {
            value = MS_CTL_DMAC0_MSC_ACG_CTL_VX;
            value &= (~(MS_CTL_DMAC0_MSC_ACG_CTL_CFG_GATE_RESP_VX_Msk | MS_CTL_DMAC0_MSC_ACG_CTL_SEC_RESP_VX_Msk));
            if (gateResp == CY_MS_CTL_GATE_RESP_ERR)
            {
                value = value | ((1U << MS_CTL_DMAC0_MSC_ACG_CTL_CFG_GATE_RESP_VX_Pos) & MS_CTL_DMAC0_MSC_ACG_CTL_CFG_GATE_RESP_VX_Msk);
            }
            if (secResp == CY_MS_CTL_SEC_RESP_ERR)
            {
                value = value | ((1U << MS_CTL_DMAC0_MSC_ACG_CTL_SEC_RESP_VX_Pos) & MS_CTL_DMAC0_MSC_ACG_CTL_SEC_RESP_VX_Msk);
            }
            MS_CTL_DMAC0_MSC_ACG_CTL_VX = value;
            ret_value = CY_MS_CTL_SUCCESS;
            break;
        }

        case DMAC1_MSC:
        {
            value = MS_CTL_DMAC1_MSC_ACG_CTL_VX;
            value &= (~(MS_CTL_DMAC1_MSC_ACG_CTL_CFG_GATE_RESP_VX_Msk | MS_CTL_DMAC1_MSC_ACG_CTL_SEC_RESP_VX_Msk));
            if (gateResp == CY_MS_CTL_GATE_RESP_ERR)
            {
                value = value | ((1U << MS_CTL_DMAC1_MSC_ACG_CTL_CFG_GATE_RESP_VX_Pos) & MS_CTL_DMAC1_MSC_ACG_CTL_CFG_GATE_RESP_VX_Msk);
            }
            if (secResp == CY_MS_CTL_SEC_RESP_ERR)
            {
                value = value | ((1U << MS_CTL_DMAC1_MSC_ACG_CTL_SEC_RESP_VX_Pos) & MS_CTL_DMAC1_MSC_ACG_CTL_SEC_RESP_VX_Msk);
            }
            MS_CTL_DMAC1_MSC_ACG_CTL_VX = value;
            ret_value = CY_MS_CTL_SUCCESS;
            break;
        }

        default:
        {
            // default case and will return error */
            break;
        }
    }

    return ret_value;
}


cy_en_ms_ctl_status_t Cy_Ms_Ctl_SetActivePC(en_ms_ctl_master_t busMaster, uint32_t pc)
{
    CY_REG32_CLR_SET(MS_CTL_PC_VAL_VX(busMaster), MS_PC_PC_PC , pc);
    return CY_MS_CTL_SUCCESS;
}

uint32_t Cy_Ms_Ctl_GetActivePC(en_ms_ctl_master_t busMaster)
{
    return ((uint32_t)_FLD2VAL(MS_PC_PC_READ_MIR_PC, MS_CTL_PC_READ_MIRROR_VX(busMaster)));
}

cy_en_ms_ctl_status_t Cy_Ms_Ctl_SetSavedPC(en_ms_ctl_master_t busMaster, uint32_t savedPc)
{
    CY_REG32_CLR_SET(MS_CTL_PC_VAL_VX(busMaster), MS_PC_PC_PC_SAVED , savedPc);
    return CY_MS_CTL_SUCCESS;
}


uint32_t Cy_Ms_Ctl_GetSavedPC(en_ms_ctl_master_t busMaster)
{
    return ((uint32_t)_FLD2VAL(MS_PC_PC_READ_MIR_PC_SAVED, MS_CTL_PC_READ_MIRROR_VX(busMaster)));
}

cy_en_ms_ctl_status_t Cy_Ms_Ctl_SetPcHandler(uint32_t pc, cy_israddress handler)
{
    cy_en_ms_ctl_status_t ret = CY_MS_CTL_BAD_PARAM;

#if (defined(CY_IP_M33SYSCPUSS_VERSION) && defined(CY_IP_M33SYSCPUSS_VERSION_MINOR)) && \
    ((CY_IP_M33SYSCPUSS_VERSION <= 2u) && (CY_IP_M33SYSCPUSS_VERSION_MINOR < 2u))

    if (pc < 4UL)
    {
        MXCM33->CM33_PC_CTL = (((MXCM33->CM33_PC_CTL)|(0x1UL << pc)) & (MXCM33_CM33_PC_CTL_VALID_Msk));
    }

#endif /* (CY_IP_M33SYSCPUSS_VERSION <= 2u) && (CY_IP_M33SYSCPUSS_VERSION_MINOR < 2u) */

    switch(pc)
    {
        case 0:
        {
            MXCM33->CM33_PC0_HANDLER = (uint32_t)handler;
            ret = CY_MS_CTL_SUCCESS;
            break;
        }
        case 1:
        {
            MXCM33->CM33_PC1_HANDLER = (uint32_t)handler;
            ret = CY_MS_CTL_SUCCESS;
            break;
        }
        case 2:
        {
            MXCM33->CM33_PC2_HANDLER = (uint32_t)handler;
            ret = CY_MS_CTL_SUCCESS;
            break;
        }
        case 3:
        {
            MXCM33->CM33_PC3_HANDLER = (uint32_t)handler;
            ret = CY_MS_CTL_SUCCESS;
            break;
        }
        default:
        {
            // default case and will return error */
            break;
        }
    }
    return ret;
}

cy_israddress Cy_Ms_Ctl_GetPcHandler(uint32_t pc)
{
    cy_israddress handler = NULL;
    switch(pc)
    {
        case 0:
        {
            handler = (cy_israddress)MXCM33->CM33_PC0_HANDLER;
            break;
        }
        case 1:
        {
            handler = (cy_israddress)MXCM33->CM33_PC1_HANDLER;
            break;
        }
        case 2:
        {
            handler = (cy_israddress)MXCM33->CM33_PC2_HANDLER;
            break;
        }
        case 3:
        {
            handler = (cy_israddress)MXCM33->CM33_PC3_HANDLER;
            break;
        }
        default:
        {
            // default case and will return error */
            break;
        }
    }
    return handler;
}

#if defined (CY_IP_M55APPCPUSS)

cy_en_ms_ctl_status_t Cy_Ms_Ctl_ConfigBusMasterV1(en_ms_ctl_master_t busMaster, bool privileged, bool nonSecure, uint32_t pcMask)
{
    uint32_t value;

    value = MS_CTL_PC_CTL_V1(busMaster);

    if (privileged)
    {
        value = value | ((1U << MS_CTL_P_Pos) & MS_CTL_P_Msk);
    }
    else
    {
        value = value & (~((1U << MS_CTL_P_Pos) & MS_CTL_P_Msk));
    }
    if (nonSecure)
    {
        value = value | ((1U << MS_CTL_NS_Pos) & MS_CTL_NS_Msk);
    }
    else
    {
        value = value & (~((1U << MS_CTL_NS_Pos) & MS_CTL_NS_Msk));
    }

    value &= (~MS_CTL_PC_MASK_Msk);
    value = value | ((pcMask << MS_CTL_PC_MASK_Pos) & MS_CTL_PC_MASK_Msk);
    MS_CTL_PC_CTL_V1(busMaster) = value;

    return CY_MS_CTL_SUCCESS;
}

cy_en_ms_ctl_status_t Cy_Ms_Ctl_ConfigMscAcgRespV1(en_ms_ctl_master_sc_acg_v1_t busMaster, cy_en_ms_ctl_cfg_gate_resp_t gateResp, cy_en_ms_ctl_sec_resp_t secResp)
{
    uint32_t value;
    cy_en_ms_ctl_status_t ret_value = CY_MS_CTL_BAD_PARAM;
    switch (busMaster)
    {
        case APP_SYS_MS0_MSC:
        {
            value = MS_CTL_SYS_MS0_MSC_ACG_CTL_V1;
            value &= (~(MS_CTL_SYS_MS0_MSC_ACG_CTL_CFG_GATE_RESP_V1_Msk | MS_CTL_SYS_MS0_MSC_ACG_CTL_SEC_RESP_V1_Msk));
            if (gateResp == CY_MS_CTL_GATE_RESP_ERR)
            {
                value = value | ((1U << MS_CTL_SYS_MS0_MSC_ACG_CTL_CFG_GATE_RESP_V1_Pos) & MS_CTL_SYS_MS0_MSC_ACG_CTL_CFG_GATE_RESP_V1_Msk);
            }
            if (secResp == CY_MS_CTL_SEC_RESP_ERR)
            {
                value = value | ((1U << MS_CTL_SYS_MS0_MSC_ACG_CTL_SEC_RESP_V1_Pos) & MS_CTL_SYS_MS0_MSC_ACG_CTL_SEC_RESP_V1_Msk);
            }
            MS_CTL_SYS_MS0_MSC_ACG_CTL_V1 = value;
            ret_value = CY_MS_CTL_SUCCESS;
            break;
        }

        case APP_SYS_MS1_MSC:
        {
            value = MS_CTL_SYS_MS1_MSC_ACG_CTL_V1;
            value &= (~(MS_CTL_SYS_MS1_MSC_ACG_CTL_CFG_GATE_RESP_V1_Msk | MS_CTL_SYS_MS1_MSC_ACG_CTL_SEC_RESP_V1_Msk));
            if (gateResp == CY_MS_CTL_GATE_RESP_ERR)
            {
                value = value | ((1U << MS_CTL_SYS_MS1_MSC_ACG_CTL_CFG_GATE_RESP_V1_Pos) & MS_CTL_SYS_MS1_MSC_ACG_CTL_CFG_GATE_RESP_V1_Msk);
            }
            if (secResp == CY_MS_CTL_SEC_RESP_ERR)
            {
                value = value | ((1U << MS_CTL_SYS_MS1_MSC_ACG_CTL_SEC_RESP_V1_Pos) & MS_CTL_SYS_MS1_MSC_ACG_CTL_SEC_RESP_V1_Msk);
            }
            MS_CTL_SYS_MS1_MSC_ACG_CTL_V1 = value;
            ret_value = CY_MS_CTL_SUCCESS;
            break;
        }

        case APP_AXIDMAC0_MSC:
        {
            value = MS_CTL_AXIDMAC0_MSC_ACG_CTL_V1;
            value &= (~(MS_CTL_AXIDMAC0_MSC_ACG_CTL_CFG_GATE_RESP_V1_Msk | MS_CTL_AXIDMAC0_MSC_ACG_CTL_SEC_RESP_V1_Msk));
            if (gateResp == CY_MS_CTL_GATE_RESP_ERR)
            {
                value = value | ((1U << MS_CTL_AXIDMAC0_MSC_ACG_CTL_CFG_GATE_RESP_V1_Pos) & MS_CTL_AXIDMAC0_MSC_ACG_CTL_CFG_GATE_RESP_V1_Msk);
            }
            if (secResp == CY_MS_CTL_SEC_RESP_ERR)
            {
                value = value | ((1U << MS_CTL_AXIDMAC0_MSC_ACG_CTL_SEC_RESP_V1_Pos) & MS_CTL_AXIDMAC0_MSC_ACG_CTL_SEC_RESP_V1_Msk);
            }
            MS_CTL_AXIDMAC0_MSC_ACG_CTL_V1 = value;
            ret_value = CY_MS_CTL_SUCCESS;
            break;
        }

        case APP_AXIDMAC1_MSC:
        {
            value = MS_CTL_AXIDMAC1_MSC_ACG_CTL_V1;
            value &= (~(MS_CTL_AXIDMAC1_MSC_ACG_CTL_CFG_GATE_RESP_V1_Msk | MS_CTL_AXIDMAC1_MSC_ACG_CTL_SEC_RESP_V1_Msk));
            if (gateResp == CY_MS_CTL_GATE_RESP_ERR)
            {
                value = value | ((1U << MS_CTL_AXIDMAC1_MSC_ACG_CTL_CFG_GATE_RESP_V1_Pos) & MS_CTL_AXIDMAC1_MSC_ACG_CTL_CFG_GATE_RESP_V1_Msk);
            }
            if (secResp == CY_MS_CTL_SEC_RESP_ERR)
            {
                value = value | ((1U << MS_CTL_AXIDMAC1_MSC_ACG_CTL_SEC_RESP_V1_Pos) & MS_CTL_AXIDMAC1_MSC_ACG_CTL_SEC_RESP_V1_Msk);
            }
            MS_CTL_AXIDMAC1_MSC_ACG_CTL_V1 = value;
            ret_value = CY_MS_CTL_SUCCESS;
            break;
        }

        case APP_AXI_MS0_MSC:
        {
            value = MS_CTL_AXI_MS0_MSC_ACG_CTL_V1;
            value &= (~(MS_CTL_AXI_MS0_MSC_ACG_CTL_CFG_GATE_RESP_V1_Msk | MS_CTL_AXI_MS0_MSC_ACG_CTL_SEC_RESP_V1_Msk));
            if (gateResp == CY_MS_CTL_GATE_RESP_ERR)
            {
                value = value | ((1U << MS_CTL_AXI_MS0_MSC_ACG_CTL_CFG_GATE_RESP_V1_Pos) & MS_CTL_AXI_MS0_MSC_ACG_CTL_CFG_GATE_RESP_V1_Msk);
            }
            if (secResp == CY_MS_CTL_SEC_RESP_ERR)
            {
                value = value | ((1U << MS_CTL_AXI_MS0_MSC_ACG_CTL_SEC_RESP_V1_Pos) & MS_CTL_AXI_MS0_MSC_ACG_CTL_SEC_RESP_V1_Msk);
            }
            MS_CTL_AXI_MS0_MSC_ACG_CTL_V1 = value;
            ret_value = CY_MS_CTL_SUCCESS;
            break;
        }

        case APP_AXI_MS1_MSC:
        {
            value = MS_CTL_AXI_MS1_MSC_ACG_CTL_V1;
            value &= (~(MS_CTL_AXI_MS1_MSC_ACG_CTL_CFG_GATE_RESP_V1_Msk | MS_CTL_AXI_MS1_MSC_ACG_CTL_SEC_RESP_V1_Msk));
            if (gateResp == CY_MS_CTL_GATE_RESP_ERR)
            {
                value = value | ((1U << MS_CTL_AXI_MS1_MSC_ACG_CTL_CFG_GATE_RESP_V1_Pos) & MS_CTL_AXI_MS1_MSC_ACG_CTL_CFG_GATE_RESP_V1_Msk);
            }
            if (secResp == CY_MS_CTL_SEC_RESP_ERR)
            {
                value = value | ((1U << MS_CTL_AXI_MS1_MSC_ACG_CTL_SEC_RESP_V1_Pos) & MS_CTL_AXI_MS1_MSC_ACG_CTL_SEC_RESP_V1_Msk);
            }
            MS_CTL_AXI_MS1_MSC_ACG_CTL_V1 = value;
            ret_value = CY_MS_CTL_SUCCESS;
            break;
        }

        case APP_AXI_MS2_MSC:
        {
            value = MS_CTL_AXI_MS2_MSC_ACG_CTL_V1;
            value &= (~(MS_CTL_AXI_MS2_MSC_ACG_CTL_CFG_GATE_RESP_V1_Msk | MS_CTL_AXI_MS2_MSC_ACG_CTL_SEC_RESP_V1_Msk));
            if (gateResp == CY_MS_CTL_GATE_RESP_ERR)
            {
                value = value | ((1U << MS_CTL_AXI_MS2_MSC_ACG_CTL_CFG_GATE_RESP_V1_Pos) & MS_CTL_AXI_MS2_MSC_ACG_CTL_CFG_GATE_RESP_V1_Msk);
            }
            if (secResp == CY_MS_CTL_SEC_RESP_ERR)
            {
                value = value | ((1U << MS_CTL_AXI_MS2_MSC_ACG_CTL_SEC_RESP_V1_Pos) & MS_CTL_AXI_MS2_MSC_ACG_CTL_SEC_RESP_V1_Msk);
            }
            MS_CTL_AXI_MS2_MSC_ACG_CTL_V1 = value;
            ret_value = CY_MS_CTL_SUCCESS;
            break;
        }

        case APP_AXI_MS3_MSC:
        {
            value = MS_CTL_AXI_MS3_MSC_ACG_CTL_V1;
            value &= (~(MS_CTL_AXI_MS3_MSC_ACG_CTL_CFG_GATE_RESP_V1_Msk | MS_CTL_AXI_MS3_MSC_ACG_CTL_SEC_RESP_V1_Msk));
            if (gateResp == CY_MS_CTL_GATE_RESP_ERR)
            {
                value = value | ((1U << MS_CTL_AXI_MS3_MSC_ACG_CTL_CFG_GATE_RESP_V1_Pos) & MS_CTL_AXI_MS3_MSC_ACG_CTL_CFG_GATE_RESP_V1_Msk);
            }
            if (secResp == CY_MS_CTL_SEC_RESP_ERR)
            {
                value = value | ((1U << MS_CTL_AXI_MS3_MSC_ACG_CTL_SEC_RESP_V1_Pos) & MS_CTL_AXI_MS3_MSC_ACG_CTL_SEC_RESP_V1_Msk);
            }
            MS_CTL_AXI_MS3_MSC_ACG_CTL_V1 = value;
            ret_value = CY_MS_CTL_SUCCESS;
            break;
        }

        case APP_EXP_MS0_MSC:
        {
            value = MS_CTL_EXP_MS0_MSC_ACG_CTL_V1;
            value &= (~(MS_CTL_EXP_MS0_MSC_ACG_CTL_CFG_GATE_RESP_V1_Msk | MS_CTL_EXP_MS0_MSC_ACG_CTL_SEC_RESP_V1_Msk));
            if (gateResp == CY_MS_CTL_GATE_RESP_ERR)
            {
                value = value | ((1U << MS_CTL_EXP_MS0_MSC_ACG_CTL_CFG_GATE_RESP_V1_Pos) & MS_CTL_EXP_MS0_MSC_ACG_CTL_CFG_GATE_RESP_V1_Msk);
            }
            if (secResp == CY_MS_CTL_SEC_RESP_ERR)
            {
                value = value | ((1U << MS_CTL_EXP_MS0_MSC_ACG_CTL_SEC_RESP_V1_Pos) & MS_CTL_EXP_MS0_MSC_ACG_CTL_SEC_RESP_V1_Msk);
            }
            MS_CTL_EXP_MS0_MSC_ACG_CTL_V1 = value;
            ret_value = CY_MS_CTL_SUCCESS;
            break;
        }

        case APP_EXP_MS1_MSC:
        {
            value = MS_CTL_EXP_MS1_MSC_ACG_CTL_V1;
            value &= (~(MS_CTL_EXP_MS1_MSC_ACG_CTL_CFG_GATE_RESP_V1_Msk | MS_CTL_EXP_MS1_MSC_ACG_CTL_SEC_RESP_V1_Msk));
            if (gateResp == CY_MS_CTL_GATE_RESP_ERR)
            {
                value = value | ((1U << MS_CTL_EXP_MS1_MSC_ACG_CTL_CFG_GATE_RESP_V1_Pos) & MS_CTL_EXP_MS1_MSC_ACG_CTL_CFG_GATE_RESP_V1_Msk);
            }
            if (secResp == CY_MS_CTL_SEC_RESP_ERR)
            {
                value = value | ((1U << MS_CTL_EXP_MS1_MSC_ACG_CTL_SEC_RESP_V1_Pos) & MS_CTL_EXP_MS1_MSC_ACG_CTL_SEC_RESP_V1_Msk);
            }
            MS_CTL_EXP_MS1_MSC_ACG_CTL_V1 = value;
            ret_value = CY_MS_CTL_SUCCESS;
            break;
        }

        case APP_EXP_MS2_MSC:
        {
            value = MS_CTL_EXP_MS2_MSC_ACG_CTL_V1;
            value &= (~(MS_CTL_EXP_MS2_MSC_ACG_CTL_CFG_GATE_RESP_V1_Msk | MS_CTL_EXP_MS2_MSC_ACG_CTL_SEC_RESP_V1_Msk));
            if (gateResp == CY_MS_CTL_GATE_RESP_ERR)
            {
                value = value | ((1U << MS_CTL_EXP_MS2_MSC_ACG_CTL_CFG_GATE_RESP_V1_Pos) & MS_CTL_EXP_MS2_MSC_ACG_CTL_CFG_GATE_RESP_V1_Msk);
            }
            if (secResp == CY_MS_CTL_SEC_RESP_ERR)
            {
                value = value | ((1U << MS_CTL_EXP_MS2_MSC_ACG_CTL_SEC_RESP_V1_Pos) & MS_CTL_EXP_MS2_MSC_ACG_CTL_SEC_RESP_V1_Msk);
            }
            MS_CTL_EXP_MS2_MSC_ACG_CTL_V1 = value;
            ret_value = CY_MS_CTL_SUCCESS;
            break;
        }

        case APP_EXP_MS3_MSC:
        {
            value = MS_CTL_EXP_MS3_MSC_ACG_CTL_V1;
            value &= (~(MS_CTL_EXP_MS3_MSC_ACG_CTL_CFG_GATE_RESP_V1_Msk | MS_CTL_EXP_MS3_MSC_ACG_CTL_SEC_RESP_V1_Msk));
            if (gateResp == CY_MS_CTL_GATE_RESP_ERR)
            {
                value = value | ((1U << MS_CTL_EXP_MS3_MSC_ACG_CTL_CFG_GATE_RESP_V1_Pos) & MS_CTL_EXP_MS3_MSC_ACG_CTL_CFG_GATE_RESP_V1_Msk);
            }
            if (secResp == CY_MS_CTL_SEC_RESP_ERR)
            {
                value = value | ((1U << MS_CTL_EXP_MS3_MSC_ACG_CTL_SEC_RESP_V1_Pos) & MS_CTL_EXP_MS3_MSC_ACG_CTL_SEC_RESP_V1_Msk);
            }
            MS_CTL_EXP_MS3_MSC_ACG_CTL_V1 = value;
            ret_value = CY_MS_CTL_SUCCESS;
            break;
        }

        default:
        {
            // default case and will return error */
            break;
        }
    }

    return ret_value;
}

cy_en_ms_ctl_status_t Cy_Ms_Ctl_SetActivePCV1(en_ms_ctl_master_t busMaster, uint32_t pc)
{
    CY_REG32_CLR_SET(MS_CTL_PC_VAL_V1(busMaster), MS_CTL_MS_PC_PC_PC , pc);
    return CY_MS_CTL_SUCCESS;
}

uint32_t Cy_Ms_Ctl_GetActivePCV1(en_ms_ctl_master_t busMaster)
{
    return ((uint32_t)_FLD2VAL(MS_CTL_MS_PC_PC_READ_MIR_PC, MS_CTL_PC_READ_MIRROR_V1(busMaster)));
}


#endif /* #if defined (CY_IP_M55APPCPUSS) */

#endif /* #if defined (CY_IP_M33SYSCPUSS) */

/* [] END OF FILE */
