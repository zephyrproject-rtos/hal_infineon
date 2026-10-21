/***************************************************************************//**
* \file cy_sysfault.c
* \version 1.10
*
* \brief
* Provides an API implementation of the SysFault driver.
*
********************************************************************************
* \copyright
* (c) (2024-2025), Cypress Semiconductor Corporation (an Infineon company) or
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

#include "cy_sysfault.h"

#if defined(CPUSS_FAULT_PRESENT)

cy_en_sysfault_status_t  Cy_SysFault_Init(FAULT_STRUCT_Type *base, cy_stc_sysfault_config_t *config)
{
    cy_en_sysfault_status_t status = CY_SYSFAULT_BAD_PARAM;

    if (config != NULL)
    {
        FAULT_CTL(base) = _VAL2FLD(FAULT_STRUCT_CTL_TR_EN, config->triggerEnable) |
                          _VAL2FLD(FAULT_STRUCT_CTL_OUT_EN, config->outputEnable) |
                          _VAL2FLD(FAULT_STRUCT_CTL_RESET_REQ_EN, config->resetEnable);
        status = CY_SYSFAULT_SUCCESS;
    }

    return(status);
}


cy_en_sysfault_source_t Cy_SysFault_GetErrorSource(FAULT_STRUCT_Type *base)
{
    CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 10.8','Intentional typecast to cy_en_sysfault_source_t enum.');
    cy_en_sysfault_source_t sysFaultSource = (cy_en_sysfault_source_t)CY_SYSFAULT_NO_FAULT;

    if (_FLD2BOOL(FAULT_STRUCT_STATUS_VALID, FAULT_STATUS(base)))
    {
        CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 10.8','Intentional typecast to cy_en_sysfault_source_t enum.');
        sysFaultSource = (cy_en_sysfault_source_t)(_FLD2VAL(FAULT_STRUCT_STATUS_IDX, FAULT_STATUS(base)));
    }

    return sysFaultSource;
}


uint32_t Cy_SysFault_GetPendingFault(FAULT_STRUCT_Type *base, cy_en_sysfault_set_t pendingFault)
{
    CY_ASSERT_L3(CY_SYSFAULT_IS_FAULT_SET_VALID(pendingFault));
    uint32_t retVal = 0;

    if(CY_SYSFAULT_SET0 == pendingFault)
    {
        retVal = _FLD2VAL(FAULT_STRUCT_PENDING0_SOURCE, FAULT_PENDING0(base));
    }

    return retVal;
}


#endif /* CPUSS_FAULT_PRESENT */
/* [] END OF FILE */
