/***************************************************************************//**
* \file  cy_sysint.c
* \version 1.10.2
*
* \brief
* Provides an API implementation of the SysInt driver.
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

#include "cy_sysint.h"


/*******************************************************************************
* Function Name: Cy_SysInt_Init
****************************************************************************//**
*
* \brief Initializes the referenced interrupt by setting the priority and the
* interrupt vector.
*
* Use the CMSIS core function NVIC_EnableIRQ(config.intrSrc) to enable the interrupt.
*
* \param config
* Interrupt configuration structure
*
* \param userIsr
* Address of the ISR
*
* \return
* Initialization status
*
* \note The interrupt vector will be relocated only if the vector table was
* moved to __RAM_VECTOR_TABLE in SRAM. Otherwise it is ignored.
*
* \funcusage
* \snippet sysint_snippet.c snippet_Cy_SysInt_DefineInterruptSource
* \snippet sysint_snippet.c snippet_Cy_SysInt_Init
*
*******************************************************************************/
cy_en_sysint_status_t Cy_SysInt_Init(const cy_stc_sysint_t* config, cy_israddress userIsr)
{
    cy_en_sysint_status_t status = CY_SYSINT_SUCCESS;

    if(NULL != config)
    {
        CY_ASSERT_L3(CY_SYSINT_IS_PRIORITY_VALID(config->intrPriority));

        NVIC_SetPriority(config->intrSrc, config->intrPriority);

        /* Set the new vector only if it was moved to __RAM_VECTOR_TABLE */
#if (__VTOR_PRESENT == 1u)
        if (SCB->VTOR == (uint32_t)&__RAM_VECTOR_TABLE)
#else
        if (0U != _FLD2VAL(CPUSS_CONFIG_VECT_IN_RAM, CPUSS->CONFIG))
#endif /* (__VTOR_PRESENT == 1u) */
        {
            (void)Cy_SysInt_SetVector(config->intrSrc, userIsr);
        }
    }
    else
    {
        status = CY_SYSINT_BAD_PARAM;
    }

    return(status);
}


/*******************************************************************************
* Function Name: Cy_SysInt_SetVector
****************************************************************************//**
*
* \brief Changes the ISR vector for the interrupt.
*
* This function relies on the assumption that the vector table is
* relocated to __RAM_VECTOR_TABLE[RAM_VECTORS_SIZE] in SRAM. Otherwise it will
* return the address of the default ISR location in the flash vector table.
*
* \param IRQn
* Interrupt source
*
* \param userIsr
* Address of the ISR to set in the interrupt vector table
*
* \return
* Previous address of the ISR in the interrupt vector table
*
* \funcusage
* \snippet sysint_snippet.c snippet_Cy_SysInt_SetVector
*
*******************************************************************************/
cy_israddress Cy_SysInt_SetVector(IRQn_Type IRQn, cy_israddress userIsr)
{
    cy_israddress prevIsr;

    /* Set the new vector only if it was moved to __RAM_VECTOR_TABLE */
#if (__VTOR_PRESENT == 1u)
    if (SCB->VTOR == (uint32_t)&__RAM_VECTOR_TABLE)
#else
    if (0U != _FLD2VAL(CPUSS_CONFIG_VECT_IN_RAM, CPUSS->CONFIG))
#endif /* (__VTOR_PRESENT == 1u) */
    {
        CY_ASSERT_L1(CY_SYSINT_IS_VECTOR_VALID(userIsr));

        prevIsr = __RAM_VECTOR_TABLE[CY_INT_IRQ_BASE + (uint32_t) IRQn];
        __RAM_VECTOR_TABLE[CY_INT_IRQ_BASE + (uint32_t) IRQn] = userIsr;
    }
    else
    {
        prevIsr = __VECTOR_TABLE[CY_INT_IRQ_BASE + (uint32_t) IRQn];
    }

    return (prevIsr);
}


/*******************************************************************************
* Function Name: Cy_SysInt_GetVector
****************************************************************************//**
*
* \brief Gets the address of the current ISR vector for the interrupt.
*
* This function relies on the assumption that the vector table is
* relocated to __RAM_VECTOR_TABLE[RAM_VECTORS_SIZE] in SRAM. Otherwise it will
* return the address of the default ISR location in the flash vector table.
*
* \param IRQn
* Interrupt source
*
* \return
* Address of the ISR in the interrupt vector table
*
* \funcusage
* \snippet sysint_snippet.c snippet_Cy_SysInt_SetVector
*
*******************************************************************************/
cy_israddress Cy_SysInt_GetVector(IRQn_Type IRQn)
{
    cy_israddress currIsr;

    /* Return the SRAM ISR address only if it was moved to __RAM_VECTOR_TABLE */
#if (__VTOR_PRESENT == 1u)
    if (SCB->VTOR == (uint32_t)&__RAM_VECTOR_TABLE)
#else
    if (0U != _FLD2VAL(CPUSS_CONFIG_VECT_IN_RAM, CPUSS->CONFIG))
#endif /* (__VTOR_PRESENT == 1u) */
    {
        currIsr = __RAM_VECTOR_TABLE[CY_INT_IRQ_BASE + (uint32_t) IRQn];
    }
    else
    {
        currIsr = __VECTOR_TABLE[CY_INT_IRQ_BASE + (uint32_t) IRQn];
    }

    return (currIsr);
}


/* [] END OF FILE */
