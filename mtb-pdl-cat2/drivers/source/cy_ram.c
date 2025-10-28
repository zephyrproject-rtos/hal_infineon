/***************************************************************************//**
* \file cy_ram.c
* \version 1.0
*
* \brief
* Provides the public functions for the API for the RAM driver.
*
********************************************************************************
* \copyright
* Copyright 2024 Cypress Semiconductor Corporation
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
#include "cy_ram.h"
#include "cy_sysclk.h"
#include "cy_device.h"
#include "cy_syslib.h"

#include <string.h>

/***************************************
* Macro definitions
***************************************/
/* Maximum of RAM ECC parity */
#define CY_RAM_PARITY_MAX (0x7FU)

#if defined (CPUSS_RAMC_ECC_PRESENT) || defined (CY_DOXYGEN)
/*******************************************************************************
* Function Name: Cy_RAM_ECC_Init
****************************************************************************//**
*
* \brief Initializes SRAM ECC with the configuration value
*
* \param base
*  The pointer to the structure, which describes the RAM (CPU Subsystem) instance registers
* \param config
*  Composite config bitmask, see \ref group_ram_init_macros
*
* \return None
*
* \funcusage
* \snippet ram_snippet.c SNIPPET_RAM_ECC_INIT
*
*******************************************************************************/
void Cy_RAM_ECC_Init (CPUSS_Type* base, uint32_t config)
{
    CY_ASSERT_L1(NULL != base);
    CY_ASSERT_L1(0U == (config & (uint32_t)(~CY_RAM_ECC_CHECK_MSK)));

    /* Get the control state, clear ECC CHECK MASK defined bits, and put there new configuration */
    (base->RAM_CTL) = (((base->RAM_CTL) & ((uint32_t)(~CY_RAM_ECC_CHECK_MSK))) | config);
}

/*******************************************************************************
* Function Name: Cy_RAM_SetupEccInjection
****************************************************************************//**
*
* \brief Sets the CPUSS_ECC_TEST register to set up ECC injection.
*
* \param base
*  The pointer to the structure, which describes RAM (CPU Subsystem) instance registers
* \param address
*  Specifies the address where an ECC error will be injected.
* \param parity
*  Specifies the parity (ECC syndrome), which will be injected to the word address.
*
* \return None
*
* \note
*  Set the lowest two bits of the address to zero.
*  For SRAM ECC, the word address WORD_ADDR[24:0] is device address A[26:2].
*
* \funcusage
* \snippet ram_snippet.c SNIPPET_RAM_ECC_INJ_INIT
*
*******************************************************************************/
void Cy_RAM_SetupEccInjection (CPUSS_Type* base, const uint32_t address, const uint8_t parity)
{
    CY_ASSERT_L1(NULL != base);
    /* The lowest two bits of the address should be zero. */
    CY_ASSERT_L1(0U == (address & CY_RAM_WORD_ADDR_CHECK_MSK));
    /* Address should be in the RAM range */
    CY_ASSERT_L1((address > CY_SRAM_BASE) && (address <= (CY_SRAM_BASE + CY_SRAM_SIZE)));
    /* Injected parity should not exceed available maximum */
    CY_ASSERT_L1((uint32_t)parity < CY_RAM_PARITY_MAX);

    (base->ECC_TEST) = _VAL2FLD(CPUSS_ECC_TEST_WORD_ADDR, (address >> CY_RAM_WORD_ADDR_CHECK_POS)) |
            _VAL2FLD(CPUSS_ECC_TEST_SYND_DATA, parity);
    return;
}

/*******************************************************************************
* Function Name: Cy_RAM_EnableEccInjection
****************************************************************************//**
*
* \brief Sets the CPUSS_RAM_CTL register to enable ECC injection.
*
* \param base
*  The pointer to the structure, which describes RAM (CPU Subsystem) instance registers
*
* \return None
*
* \funcusage
* \snippet ram_snippet.c SNIPPET_RAM_ECC_INJ_INIT
*
*******************************************************************************/
void Cy_RAM_EnableEccInjection(CPUSS_Type* base)
{
    CY_ASSERT_L1(NULL != base);
    (base->RAM_CTL) |= CPUSS_RAM_CTL_ECC_INJ_EN_Msk;
}

/*******************************************************************************
* Function Name: Cy_RAM_DisableEccInjection
****************************************************************************//**
*
* \brief Set CPUSS_RAM_CTL register to disable ECC injection.
*
* \param base
*  The pointer to the structure, which describes RAM (CPU Subsystem) instance registers
*
* \return None
*
* \funcusage
* \snippet ram_snippet.c SNIPPET_RAM_ECC_INJ_INIT
*
*******************************************************************************/
void Cy_RAM_DisableEccInjection(CPUSS_Type* base)
{
    CY_ASSERT_L1(NULL != base);
    (base->RAM_CTL) &= ~CPUSS_RAM_CTL_ECC_INJ_EN_Msk;
}

/*******************************************************************************
* Function Name: Cy_RAM_IsEccInjectionEnabled
****************************************************************************//**
*
* \brief Check whether the ECC error injection of SRAM is enabled.
*
* \param base
*  The pointer to the structure, which describes RAM (CPU Subsystem) instance registers
*
* \return TRUE if injection enabled, FALSE - otherwise.
*
* \funcusage
* \snippet ram_snippet.c SNIPPET_RAM_ECC_INJ_INIT
*
*******************************************************************************/
bool Cy_RAM_IsEccInjectionEnabled(CPUSS_Type* base)
{
    CY_ASSERT_L1(NULL != base);
    return _FLD2BOOL(CPUSS_RAM_CTL_ECC_INJ_EN, (base->RAM_CTL));
}

/*******************************************************************************
* Function Name: Cy_RAM_GetEccWordAddr
****************************************************************************//**
*
* \brief Gets the ECC injection word address.
*
* \param base
*  The pointer to the structure, which describes RAM (CPU Subsystem) instance registers
*
* \return ECC injection word address.
*
* \note Returns zero if no valid address is present
*
* \funcusage
* \snippet ram_snippet.c SNIPPET_RAM_ECC
*
*******************************************************************************/
uint32_t Cy_RAM_GetEccWordAddr(CPUSS_Type* base)
{
    CY_ASSERT_L1(NULL != base);
    uint32_t address = 0UL;
    if (_FLD2BOOL(CPUSS_RAM_ECC_STATUS0_ECC_CAPTURE_ADDR_SYNDROME_VALID, (base->RAM_ECC_STATUS0)))
    {
        address = _FLD2VAL(CPUSS_RAM_ECC_STATUS0_ECC_CAPTURE_ADDR_31_2, (base->RAM_ECC_STATUS0)) << CY_RAM_WORD_ADDR_CHECK_POS;
    }

    return address;
}

/*******************************************************************************
* Function Name: Cy_RAM_GetEccSyndrome
****************************************************************************//**
*
* \brief Gets the ECC error Syndrome.
*
* \param base
*  The pointer to the structure, which describes RAM (CPU Subsystem) instance registers
*
* \return ECC error Syndrome.
*
* \note Returns zero if no valid ECC syndrome is present
*
* \funcusage
* \snippet ram_snippet.c SNIPPET_RAM_ECC
*
*******************************************************************************/
uint8_t Cy_RAM_GetEccSyndrome(CPUSS_Type* base)
{
    CY_ASSERT_L1(NULL != base);
    uint8_t syndrome = 0U;
    if (_FLD2BOOL(CPUSS_RAM_ECC_STATUS0_ECC_CAPTURE_ADDR_SYNDROME_VALID, (base->RAM_ECC_STATUS0)))
    {
        syndrome = (uint8_t)_FLD2VAL(CPUSS_RAM_ECC_STATUS1_ECC_CAPTURE_SYNDROME, (base->RAM_ECC_STATUS1));
    }
    return syndrome;
}

/*******************************************************************************
* Function Name: Cy_RAM_ClearEccSyndrome
****************************************************************************//**
*
* \brief Clears the valid status of ECC capture address and syndrome.
*
* \param base
*  The pointer to the structure, which describes RAM (CPU Subsystem) instance registers
*
* \return None
*
* \funcusage
* \snippet ram_snippet.c SNIPPET_RAM_ECC
*
*******************************************************************************/
void Cy_RAM_ClearEccSyndrome(CPUSS_Type* base)
{
    CY_ASSERT_L1(NULL != base);
    (base->RAM_ECC_STATUS0) |= _VAL2FLD(CPUSS_RAM_ECC_STATUS0_ECC_CAPTURE_ADDR_SYNDROME_VALID, 1U);
}

/*******************************************************************************
* Function Name: Cy_RAM_IsWritebufferEmpty
****************************************************************************//**
*
* \brief Checks whether the Write Buffer is empty or not.
*
* \param base
*  The pointer to the structure, which describes RAM (CPU Subsystem) instance registers
*
* \return TRUE if buffer is empty, FALSE otherwise.
*
* \note  This information is used when entering DeepSleep power mode:
* WB_EMPTY must be '1' before a transition to system DeepSleep power mode.
* '0': Write buffer NOT empty.
* '1': Write buffer empty.
* The SRAM controller write buffer is only used when ECC checking is enabled.
* if ECC not enabled result should be always true (buffer empty).
*
*******************************************************************************/
bool Cy_RAM_IsWritebufferEmpty(CPUSS_Type* base)
{
    CY_ASSERT_L1(NULL != base);
    if ((bool)_FLD2VAL(CPUSS_RAM_CTL_ECC_ENABLE,(base->RAM_CTL)))
    {
        return _FLD2BOOL(CPUSS_RAM_STATUS_WB_EMPTY,(base->RAM_STATUS));
    }
    else
    {
        return true;
    }
}
#endif /* defined (CPUSS_RAMC_ECC_PRESENT) || defined (CY_DOXYGEN) */

/* [] END OF FILE */
