/***************************************************************************//**
* \file cy_syspm_ppu.c
* \version 5.170
*
* This file provides the source code for ARM PPU Platform PD specific driver,
* where the API's are used by Syspm driver for Power Management.
*
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

#if defined (CY_IP_MXS28SRSS) || defined (CY_IP_MXS40SSRSS) || defined (CY_IP_MXS22SRSS)

#include <stdbool.h>
#include <ppu_v1.h>
#include <cy_syspm_ppu.h>
#include "cy_syslib.h"
#include "cy_syspm.h"
#if defined(CY_USE_RPC_CALL) && (CY_USE_RPC_CALL == 1)
#include "cy_secure_services.h"
#endif
/**
* \addtogroup group_syspm_ppu_functions
* \{
*/

/*******************************************************************************
* Function Name: cy_pd_ppu_init
****************************************************************************//**
*
* Initializes the PD PPU Driver.
*
*  \param ppu
*  This parameter contains PPU base pointer for which the initialization has
*  to be done.
*
*  \return the PD PPU API status \ref cy_en_syspm_status_t.
*
*******************************************************************************/
cy_en_syspm_status_t cy_pd_ppu_init(struct ppu_v1_reg *ppu)
{
    CY_ASSERT(ppu != NULL);

    ppu_v1_init(ppu);

    return CY_SYSPM_SUCCESS;
}

/*******************************************************************************
* Function Name: cy_pd_ppu_get_programmed_power_mode
****************************************************************************//**
*
* Gets the programmed power mode of the particular PPU.
*
*  \param ppu
*  This parameter contains PPU base pointer for which the initialization has
*  to be done.
*
*  \return Returns the PPU Programmed Power mode
*
*******************************************************************************/

enum ppu_v1_mode cy_pd_ppu_get_programmed_power_mode(struct ppu_v1_reg *ppu)
{
    CY_ASSERT(ppu != NULL);
#if (!defined(CY_USE_RPC_CALL) || (CY_USE_RPC_CALL == 0)) || !defined (CY_IP_MXS22SRSS) || (defined (COMPONENT_SECURE_DEVICE) && defined (CY_IP_MXS22SRSS))
    return ppu_v1_get_programmed_power_mode(ppu);
#else
    cy_rpc_service_args_t rpcInputArgs, rpcOutputArgs;
    enum ppu_v1_mode mode = PPU_V1_MODE_OFF;
    if ((ppu == (struct ppu_v1_reg *)SOCMEM_PPU_SOCMEM) || (ppu == (struct ppu_v1_reg *)U550_MXU55_PPU))
    {
      return ppu_v1_get_programmed_power_mode(ppu);
    }
    else
    {
     rpcInputArgs.argc = 3;
     rpcInputArgs.argv[0] = (uint32_t)CY_SECURE_SERVICE_TYPE_PM;
     rpcInputArgs.argv[1] = (uint32_t)CY_SECURE_SERVICE_PM_GET_PROGRAMMED_POWER_MODE;
     rpcInputArgs.argv[2] = (uint32_t)ppu;

     cy_rpc_invec_t in_vec[] = {
         { .base = &rpcInputArgs, .len = sizeof(rpcInputArgs) },
     };
     cy_rpc_outvec_t out_vec[] = {
         { .base = &rpcOutputArgs, .len = sizeof(rpcOutputArgs) },
     };
     rpcOutputArgs.argc = 0; /* updated in secure side */

     Cy_SecureServices_RPC(in_vec, CY_RPC_IOVEC_LEN(in_vec), out_vec, CY_RPC_IOVEC_LEN(out_vec));
     if (rpcOutputArgs.argc == 1)
     {
       mode = (enum ppu_v1_mode)rpcOutputArgs.argv[0];
     }

     return mode;
    }
#endif
}


/*******************************************************************************
* Function Name: cy_pd_ppu_get_power_mode
****************************************************************************//**
*
* Gets the current power mode of the particular PPU.
*
*  \param ppu
*  This parameter contains PPU base pointer for which the initialization has
*  to be done.
*
*  \return Returns the PPU Current Power mode
*
*******************************************************************************/

enum ppu_v1_mode cy_pd_ppu_get_power_mode(struct ppu_v1_reg *ppu)
{
    CY_ASSERT(ppu != NULL);
#if (!defined(CY_USE_RPC_CALL) || (CY_USE_RPC_CALL == 0)) || !defined (CY_IP_MXS22SRSS) || (defined (COMPONENT_SECURE_DEVICE) && defined (CY_IP_MXS22SRSS))
    return ppu_v1_get_power_mode(ppu);
#else
    enum ppu_v1_mode mode = PPU_V1_MODE_OFF;
    cy_rpc_service_args_t rpcInputArgs, rpcOutputArgs;

    if ((ppu == (struct ppu_v1_reg *)SOCMEM_PPU_SOCMEM) || (ppu == (struct ppu_v1_reg *)U550_MXU55_PPU))
    {
      return ppu_v1_get_power_mode(ppu);
    }
    else
    {
     rpcInputArgs.argc = 3;
     rpcInputArgs.argv[0] = (uint32_t)CY_SECURE_SERVICE_TYPE_PM;
     rpcInputArgs.argv[1] = (uint32_t)CY_SECURE_SERVICE_PM_GET_POWER_MODE;
     rpcInputArgs.argv[2] = (uint32_t)ppu;

     cy_rpc_invec_t in_vec[] = {
         { .base = &rpcInputArgs, .len = sizeof(rpcInputArgs) },
     };
     cy_rpc_outvec_t out_vec[] = {
         { .base = &rpcOutputArgs, .len = sizeof(rpcOutputArgs) },
     };
     rpcOutputArgs.argc = 0; /* updated in secure side */

     Cy_SecureServices_RPC(in_vec, CY_RPC_IOVEC_LEN(in_vec), out_vec, CY_RPC_IOVEC_LEN(out_vec));
     if (rpcOutputArgs.argc == 1)
     {
       mode = (enum ppu_v1_mode)rpcOutputArgs.argv[0];
     }
    }
    return mode;
#endif
}

/*******************************************************************************
* Function Name: cy_pd_ppu_set_power_mode
****************************************************************************//**
*
* Sets the required power mode of the particular PPU.
*
*  \param ppu
*  This parameter contains PPU base pointer for which the initialization has
*  to be done.
*
*  \param mode
*  Contains the future power mode to be set for the PPU.
*
*  \return the PD PPU API status \ref cy_en_syspm_status_t.
*
*******************************************************************************/

cy_en_syspm_status_t cy_pd_ppu_set_power_mode(struct ppu_v1_reg *ppu, uint32_t mode)
{
#if (!defined(CY_USE_RPC_CALL) || (CY_USE_RPC_CALL == 0)) || !defined (CY_IP_MXS22SRSS) || (defined (COMPONENT_SECURE_DEVICE) && defined (CY_IP_MXS22SRSS))
    cy_en_syspm_status_t status = CY_SYSPM_INVALID_STATE;
    CY_ASSERT(ppu != NULL);
    CY_ASSERT(mode < PPU_V1_MODE_COUNT);

    (void)ppu_v1_dynamic_enable(ppu, (enum ppu_v1_mode) mode); /* Suppress a compiler warning about unused return value */
    status = CY_SYSPM_SUCCESS;
    return status;
#else
    cy_en_syspm_status_t status = CY_SYSPM_INVALID_STATE;
    cy_rpc_service_args_t rpcInputArgs, rpcOutputArgs;

    if ((ppu == (struct ppu_v1_reg *)SOCMEM_PPU_SOCMEM) || (ppu == (struct ppu_v1_reg *)U550_MXU55_PPU))
    {
      (void)ppu_v1_dynamic_enable(ppu, (enum ppu_v1_mode) mode); /* Suppress a compiler warning about unused return value */
       status = CY_SYSPM_SUCCESS;
    }
    else
    {

      rpcInputArgs.argc = 4;
      rpcInputArgs.argv[0] = (uint32_t)CY_SECURE_SERVICE_TYPE_PM;
      rpcInputArgs.argv[1] = (uint32_t)CY_SECURE_SERVICE_PM_SET_POWER_MODE;
      rpcInputArgs.argv[2] = (uint32_t)ppu;
      rpcInputArgs.argv[3] = (uint32_t)mode;

      cy_rpc_invec_t in_vec[] = {
          { .base = &rpcInputArgs, .len = sizeof(rpcInputArgs) },
      };
      cy_rpc_outvec_t out_vec[] = {
          { .base = &rpcOutputArgs, .len = sizeof(rpcOutputArgs) },
      };
      rpcOutputArgs.argc = 0; /* updated in secure side */

    Cy_SecureServices_RPC(in_vec, CY_RPC_IOVEC_LEN(in_vec), out_vec, CY_RPC_IOVEC_LEN(out_vec));
    if (rpcOutputArgs.argc == 1)
    {
      status = (cy_en_syspm_status_t)rpcOutputArgs.argv[0];
    }

    }
    return status;

#endif
}

/*******************************************************************************
* Function Name: cy_pd_ppu_enable_dynamic_mode
****************************************************************************//**
*
* Enables/Disable Dynamic Mode of particular PPU.
*
*  \param ppu
*  This parameter contains PPU base pointer for which the initialization has
*  to be done.
*
*  \param enable
*  true  - Enables the Dynamic mode for the PD.
*  false - Disables the Dynamic mode for the PD.
*
*******************************************************************************/

void cy_pd_ppu_enable_dynamic_mode(struct ppu_v1_reg *ppu, bool enable)
{
    CY_ASSERT(ppu != NULL);
#if (!defined(CY_USE_RPC_CALL) || (CY_USE_RPC_CALL == 0)) || !defined (CY_IP_MXS22SRSS) || (defined (COMPONENT_SECURE_DEVICE) && defined (CY_IP_MXS22SRSS))
    if(enable)
    {
        ppu->PWPR |= PPU_V1_PWPR_DYNAMIC_EN;
    }
    else
    {
        ppu->PWPR &= ~(PPU_V1_PWPR_DYNAMIC_EN);
    }
#else
    cy_rpc_service_args_t rpcInputArgs;
    rpcInputArgs.argc = 4;
    rpcInputArgs.argv[0] = (uint32_t)CY_SECURE_SERVICE_TYPE_PM;
    rpcInputArgs.argv[1] = (uint32_t)CY_SECURE_SERVICE_PM_ENABLE_DYNAMIC_MODE;
    rpcInputArgs.argv[2] = (uint32_t)ppu;
    rpcInputArgs.argv[3] = (uint32_t)enable;
    cy_rpc_invec_t in_vec[] = {
         { .base = &rpcInputArgs, .len = sizeof(rpcInputArgs) },
     };
    Cy_SecureServices_RPC(in_vec, CY_RPC_IOVEC_LEN(in_vec), NULL, 0);

#endif
}

/*******************************************************************************
* Function Name: cy_pd_ppu_set_static_power_mode
****************************************************************************//**
*
* Sets the required static power mode of the particular PPU.
*
*  \param ppu
*  This parameter contains PPU base pointer for which the initialization has
*  to be done.
*
*  \param mode
*  Contains the future power mode to be set for the PPU.
*
*  \return the PD PPU API status \ref cy_en_syspm_status_t.
*
*******************************************************************************/

cy_en_syspm_status_t cy_pd_ppu_set_static_power_mode(struct ppu_v1_reg *ppu, uint32_t mode)
{

#if (!defined(CY_USE_RPC_CALL) || (CY_USE_RPC_CALL == 0)) || !defined (CY_IP_MXS22SRSS) || (defined (COMPONENT_SECURE_DEVICE) && defined (CY_IP_MXS22SRSS))
    cy_en_syspm_status_t status = CY_SYSPM_INVALID_STATE;
    CY_ASSERT(ppu != NULL);
    CY_ASSERT(mode < PPU_V1_MODE_COUNT);

    (void)ppu_v1_set_power_mode(ppu, (enum ppu_v1_mode) mode); /* Suppress a compiler warning about unused return value */
    status = CY_SYSPM_SUCCESS;
    return status;
#else
    cy_en_syspm_status_t status = CY_SYSPM_INVALID_STATE;
    cy_rpc_service_args_t rpcInputArgs, rpcOutputArgs;
    if ((ppu == (struct ppu_v1_reg *)SOCMEM_PPU_SOCMEM) || (ppu == (struct ppu_v1_reg *)U550_MXU55_PPU))
    {
      (void)ppu_v1_set_power_mode(ppu, (enum ppu_v1_mode) mode); /* Suppress a compiler warning about unused return value */
    status = CY_SYSPM_SUCCESS;
    }
    else
    {
    rpcInputArgs.argc = 4;
    rpcInputArgs.argv[0] = (uint32_t)CY_SECURE_SERVICE_TYPE_PM;
    rpcInputArgs.argv[1] = (uint32_t)CY_SECURE_SERVICE_PM_SET_STATIC_POWER_MODE;
    rpcInputArgs.argv[2] = (uint32_t)ppu;
    rpcInputArgs.argv[3] = (uint32_t)mode;

    cy_rpc_invec_t in_vec[] = {
        { .base = &rpcInputArgs, .len = sizeof(rpcInputArgs) },
    };

    cy_rpc_outvec_t out_vec[] = {
        { .base = &rpcOutputArgs, .len = sizeof(rpcOutputArgs) },
    };
    rpcOutputArgs.argc = 0; /* updated in secure side */

    Cy_SecureServices_RPC(in_vec, CY_RPC_IOVEC_LEN(in_vec), out_vec, CY_RPC_IOVEC_LEN(out_vec));
    if (rpcOutputArgs.argc == 1)
    {
      status = (cy_en_syspm_status_t)rpcOutputArgs.argv[0];
    }
    }
    return status;
#endif
}



/*******************************************************************************
* Function Name: cy_pd_ppu_reset
****************************************************************************//**
*
* Resets the PD using PPU.
*
*  \param ppu
*  This parameter contains PPU base pointer for which the initialization has
*  to be done.
*
*  \return the PD PPU API status \ref cy_en_syspm_status_t.
*
*******************************************************************************/

cy_en_syspm_status_t cy_pd_ppu_reset(struct ppu_v1_reg *ppu)
{
    cy_en_syspm_status_t status;
    CY_ASSERT(ppu != NULL);

    status = cy_pd_ppu_set_power_mode(ppu, (uint32_t)PPU_V1_MODE_OFF);
    if (status == CY_SYSPM_SUCCESS)
    {
        status = cy_pd_ppu_set_power_mode(ppu, (uint32_t)PPU_V1_MODE_ON);
    }

    return status;
}

/*******************************************************************************
* Function Name: cy_pd_ppu_get_ds_fail_device
****************************************************************************//**
*
* Gets the PPU's device ID(s) which caused the Deepsleep Failure.
*
*  \param ppu
*  This parameter contains PPU base pointer for which the initialization has
*  to be done.
*
*  \return Returns the PPU's device ID which caused the Deepsleep Failure
*
*******************************************************************************/
cy_pd_ppu_device_status_t cy_pd_ppu_get_ds_fail_device(struct ppu_v1_reg *ppu)
{
    CY_ASSERT(ppu != NULL);
    return (cy_pd_ppu_device_status_t)ppu_v1_get_failure_device_id(ppu);
}

/** \} group_syspm_ppu_functions */

#endif /* CY_IP_MXS28SRSS,CY_IP_MXS40SSRSS */
