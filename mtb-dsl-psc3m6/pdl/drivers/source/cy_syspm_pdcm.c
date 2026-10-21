/***************************************************************************//**
* \file cy_syspm_pdcm.c
* \version 5.170
*
* This file provides the source code for PDCM driver, where the API's are used
* by Syspm driver and BTSS driver.
*
********************************************************************************
* \copyright
* (c) 2016-2026, Infineon Technologies AG or an affiliate of
* Infineon Technologies AG.
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

#if defined(CY_IP_MXS40SSRSS) || defined(CY_IP_MXS22SRSS) || defined (CY_DOXYGEN)

#include <stdbool.h>
#include <cy_syspm_pdcm.h>

/* Macros */
#define CY_PD_PDCM_DEPENDENCY_MASK        0x00000001UL
#define CY_PD_PDCM_DEPENDENCY_CONFIG1     0x00000002UL
#define CY_PD_PDCM_DEPENDENCY_CONFIG2     0x00000003UL


/*******************************************************************************
* Function Name: cy_pd_pdcm_get_dependency
****************************************************************************//**
*
* Gets the dependency between two Power Domains.
*
*  \param host_pd
*  This parameter contains the Host Power Domain ID from where the dependency
*  has to be obtained at w.r.to dest_pd(Destination Power Domain).
*  \ref cy_pd_pdcm_id_t.
*
*  \param dest_pd
*  This parameter contains the Destination Power Domain ID \ref cy_pd_pdcm_id_t
*
*  \return Contains the dependency \ref cy_pd_pdcm_dep_t
*
*******************************************************************************/
cy_pd_pdcm_dep_t cy_pd_pdcm_get_dependency(cy_pd_pdcm_id_t host_pd,cy_pd_pdcm_id_t dest_pd)
{
    uint32_t dep = 0;

    CY_ASSERT(CY_SYSPM_IS_PDCM_ID_VALID(host_pd));
    CY_ASSERT(CY_SYSPM_IS_PDCM_ID_VALID(dest_pd));
    #if defined (CY_IP_MXS22SRSS) && (CY_IP_MXS22SRSS_VERSION >= 2UL)
    dep = (((_FLD2VAL(PWRCTL_MAIN_LV_REG_PDCM_PD_SPT_PD_FORCE_ON, CY_PDCM_PD_SPT(host_pd)) >> ((uint32_t)dest_pd)) & CY_PD_PDCM_DEPENDENCY_MASK) |
            (((_FLD2VAL(PWRCTL_MAIN_LV_REG_PDCM_PD_SPT_PD_CONFIG_ON, CY_PDCM_PD_SPT(host_pd)) >> ((uint32_t)dest_pd)) & CY_PD_PDCM_DEPENDENCY_MASK ) << CY_PD_PDCM_DEPENDENCY_MASK));
    #else
    dep = (((_FLD2VAL(PWRMODE_PD_PD_SPT_PD_FORCE_ON, CY_PDCM_PD_SPT(host_pd)) >> ((uint32_t)dest_pd)) & CY_PD_PDCM_DEPENDENCY_MASK) |
            (((_FLD2VAL(PWRMODE_PD_PD_SPT_PD_CONFIG_ON, CY_PDCM_PD_SPT(host_pd)) >> ((uint32_t)dest_pd)) & CY_PD_PDCM_DEPENDENCY_MASK ) << CY_PD_PDCM_DEPENDENCY_MASK));
    #endif
    if((dep == CY_PD_PDCM_DEPENDENCY_CONFIG1) || (dep == CY_PD_PDCM_DEPENDENCY_CONFIG2))
    {
        dep = (uint32_t)CY_PD_PDCM_DEP_CONFIG;
    }
    return (cy_pd_pdcm_dep_t)dep;
}

/*******************************************************************************
* Function Name: cy_pd_pdcm_set_dependency
****************************************************************************//**
*
* Set the dependency between two Power Domains.
*
*  \param host_pd
*  This Parameter contains the Host Power Domain ID from where the dependency
*  has to be set w.r.to dest_pd(Destination Power Domain).
*  \ref cy_pd_pdcm_id_t.
*
*  \param dest_pd
*  This Parameter contains the Destination Power Domain ID \ref cy_pd_pdcm_id_t
*
*  \return Contains the status of the API call \ref cy_en_syspm_status_t
*
*******************************************************************************/
cy_en_syspm_status_t cy_pd_pdcm_set_dependency(cy_pd_pdcm_id_t host_pd,cy_pd_pdcm_id_t dest_pd)
{
    cy_en_syspm_status_t ret = CY_SYSPM_FAIL;
    CY_ASSERT(CY_SYSPM_IS_PDCM_ID_VALID(host_pd));
    CY_ASSERT(CY_SYSPM_IS_PDCM_ID_VALID(dest_pd));
    if(CY_PD_PDCM_DEP_CONFIG == cy_pd_pdcm_get_dependency(host_pd,dest_pd))
    {
        CY_PDCM_PD_SENSE(host_pd) |= (CY_PD_PDCM_DEPENDENCY_MASK << ((uint32_t)dest_pd));
        ret = CY_SYSPM_SUCCESS;
    }
    return ret;
}

/*******************************************************************************
* Function Name: cy_pd_pdcm_clear_dependency
****************************************************************************//**
*
* Clears the dependency between two Power Domains.
*
*  \param host_pd
*  This parameter contains the Host Power Domain ID from where the dependency
*  has to be cleared w.r.to dest_pd(Destination Power Domain).
*  \ref cy_pd_pdcm_id_t.
*
*  \param dest_pd
*  This Parameter contains the Destination Power Domain ID \ref cy_pd_pdcm_id_t
*
*  \return Contains the status of the API call \ref cy_en_syspm_status_t
*
*******************************************************************************/
cy_en_syspm_status_t cy_pd_pdcm_clear_dependency(cy_pd_pdcm_id_t host_pd,cy_pd_pdcm_id_t dest_pd)
{
    cy_en_syspm_status_t ret = CY_SYSPM_FAIL;
    CY_ASSERT(CY_SYSPM_IS_PDCM_ID_VALID(host_pd));
    CY_ASSERT(CY_SYSPM_IS_PDCM_ID_VALID(dest_pd));
    if(CY_PD_PDCM_DEP_CONFIG == cy_pd_pdcm_get_dependency(host_pd,dest_pd))
    {
        CY_PDCM_PD_SENSE(host_pd) &= ~(CY_PD_PDCM_DEPENDENCY_MASK << ((uint32_t)dest_pd));
        ret = CY_SYSPM_SUCCESS;
    }
    return ret;
}

#if defined (CY_IP_MXS22SRSS) && (CY_IP_MXS22SRSS_VERSION >= 2)

cy_en_syspm_status_t Cy_SysPm_PDResourceMapEnable(cy_pd_pdcm_id_t pd, cy_en_syspm_pd_resource_t resource, bool enable)
{
    cy_en_syspm_status_t status = CY_SYSPM_FAIL;
    CY_ASSERT(CY_SYSPM_IS_PDCM_ID_VALID(pd));
    CY_ASSERT(CY_SYSPM_IS_PD_RESOURCE_VALID(resource));

    /* If the resource is configurable  */
    if((((uint32_t)resource) & (~CY_PD_RESOURCE_MAP_CONFIG_ON(pd))) == 0UL)
    {
        /* Set the corresponding bit(s) in the resource map dependency sense register */
        enable ? (CY_PD_RESOURCE_MAP_SENSE(pd) |= (uint32_t)resource) : (CY_PD_RESOURCE_MAP_SENSE(pd) &= ~((uint32_t)resource));
        status = CY_SYSPM_SUCCESS;
    }
    return status;
}

#if (CY_IP_MXS22SRSS_VERSION_MINOR == 2)
cy_en_syspm_status_t Cy_SysPm_PDResourceMapDisable(cy_pd_pdcm_id_t pd, cy_en_syspm_pd_resource_t resource)
{
    cy_en_syspm_status_t status = CY_SYSPM_FAIL;
    CY_ASSERT(CY_SYSPM_IS_PDCM_ID_VALID(pd));
    CY_ASSERT(CY_SYSPM_IS_PD_RESOURCE_VALID(resource));

    /* If the resource is configurable */
    if((((uint32_t)resource) & (~CY_PD_RESOURCE_MAP_CONFIG_ON(pd))) == 0UL)
    {
        /* Clear the corresponding bit(s) in the resource map dependency sense register */
        CY_PD_RESOURCE_MAP_SENSE(pd) &= ~((uint32_t)resource);
        status = CY_SYSPM_SUCCESS;
    }
    return status;
}

uint32_t Cy_SysPm_PDResourceMapGet(cy_pd_pdcm_id_t pd)
{
    CY_ASSERT(CY_SYSPM_IS_PDCM_ID_VALID(pd));
    return CY_PD_RESOURCE_MAP_SENSE(pd);
}
#endif /* (CY_IP_MXS22SRSS_VERSION_MINOR == 2) */

#endif /* defined (CY_IP_MXS22SRSS) && (CY_IP_MXS22SRSS_VERSION >= 2) */

#endif /* defined(CY_IP_MXS40SSRSS) || defined(CY_IP_MXS22SRSS) */
