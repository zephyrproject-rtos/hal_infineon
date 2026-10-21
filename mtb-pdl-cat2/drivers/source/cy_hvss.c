/***************************************************************************//**
* \file cy_hvss.c
* \version 1.0
*
* \brief
* Provides the public functions for the API for the HVSS driver.
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
#include "cy_hvss.h"

#if defined (CY_IP_M0S8HVSS)
#if((defined CY_IP_M0S8HVSS_VERSION) && (2U == CY_IP_M0S8HVSS_VERSION))
    #define CY_HVSS_HVREG_CTRL_DEFAULT (0x00000003U) /* Default value of HVREG_CTRL register */
    /* HVSS interrupt mask */
    #define CY_HVSS_LIN_INTR_MSK \
    (CY_HVSS_LIN_INTR_WAKEUP_MSK | CY_HVSS_LIN_INTR_FAULT_MSK | CY_HVSS_LIN_INTR_HVREG_TSD_MSK)
#elif((defined CY_IP_M0S8HVSS_VERSION) && (1U == CY_IP_M0S8HVSS_VERSION))
    /* HVSS interrupt mask */
    #define CY_HVSS_LIN_INTR_MSK (CY_HVSS_LIN_INTR_WAKEUP_MSK | CY_HVSS_LIN_INTR_FAULT_MSK)
#else
    #error CY_IP_M0S8HVSS_VERSION is undefined!
#endif /* (defined CY_IP_M0S8HVSS_VERSION) && (2U == CY_IP_M0S8HVSS_VERSION) */

/*******************************************************************************
* Function Name: Cy_HVSS_Init
****************************************************************************//**
*
* \brief Initialize HVSS
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \param configPtr
*  The pointer to the configuration structure
*
* \return None
*
* \funcusage
* \snippet hvss_snippet.c SNIPPET_HVSS_INIT
*
*******************************************************************************/
void Cy_HVSS_Init(const cy_hvss_config_t* configPtr)
{
    CY_ASSERT_L1(NULL != configPtr);

#if(2U == CY_IP_M0S8HVSS_VERSION)
    HVSS->HVREG_CTRL = _VAL2FLD(HVSS_HVREG_CTRL_ZENER_CLAMP_MODE,(uint32_t)configPtr->hvregClampMode) |
            _VAL2FLD(HVSS_HVREG_CTRL_TSD_MODE, (uint32_t)configPtr->hvregTsdMode) |
            _BOOL2FLD(HVSS_HVREG_CTRL_EN_VDIV, configPtr->vbatDivEnable);
#endif /* 2U == CY_IP_M0S8HVSS_VERSION */
#if(1U == CY_IP_M0S8HVSS_VERSION)
    HVSS->RDIV_CTL = _BOOL2FLD(HVSS_RDIV_CTL_RDIV_EN_0, configPtr->rdiv0Enable) |
            _BOOL2FLD(HVSS_RDIV_CTL_RDIV_EN_1, configPtr->rdiv0Enable) |
            _VAL2FLD(HVSS_RDIV_CTL_RDIV_ACT_EN, (uint32_t)configPtr->rdivActiveEnable) |
            _VAL2FLD(HVSS_RDIV_CTL_RDIV_SCALE_0, (uint32_t)configPtr->rdiv0Scale) |
            _VAL2FLD(HVSS_RDIV_CTL_RDIV_SCALE_1, (uint32_t)configPtr->rdiv1Scale);
#endif /* 1U == CY_IP_M0S8HVSS_VERSION */
    HVSS->LIN_CTL = _VAL2FLD(HVSS_LIN_CTL_LIN_MODE, (uint32_t)configPtr->linMode) |
            _VAL2FLD(HVSS_LIN_CTL_RF_DETECT, (uint32_t)configPtr->rfDetect) |
            _VAL2FLD(HVSS_LIN_CTL_USE_ALT_INTERFACE, (uint32_t)configPtr->linPhyRoute) |
            _BOOL2FLD(HVSS_LIN_CTL_LIN_EN, configPtr->linEnable);
#if(2U == CY_IP_M0S8HVSS_VERSION)
    HVSS->LIN_CTL =
            _CLR_SET_FLD32U(HVSS->LIN_CTL, HVSS_LIN_CTL_SEL_CXPI_LIN, (uint32_t)configPtr->phyInterfaceSel);
#endif /* 2U == CY_IP_M0S8HVSS_VERSION */

    HVSS->LIN_TIMER = _VAL2FLD(HVSS_LIN_TIMER_WAKEUP_TIMER, (uint32_t)configPtr->wakeupTimerValue) |
            _VAL2FLD(HVSS_LIN_TIMER_FAULT_TIMER, (uint32_t)configPtr->faultTimerValue) |
            _BOOL2FLD(HVSS_LIN_TIMER_WAKEUP_TIMER_EN, configPtr->wakeupTimerEnable) |
            _BOOL2FLD(HVSS_LIN_TIMER_FAULT_TIMER_EN, configPtr->faultTimerEnable);

    /* Clear interrupt */
    HVSS->LIN_INTR = CY_HVSS_LIN_INTR_MSK;
}

/*******************************************************************************
* Function Name: Cy_HVSS_DeInit
****************************************************************************//**
*
* \brief Deinitialize HVSS
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \return None
*
*******************************************************************************/
void Cy_HVSS_DeInit(void)
{
    /* Deinitialize HVSS HW */
#if(2U == CY_IP_M0S8HVSS_VERSION)
    HVSS->HVREG_CTRL = CY_HVSS_HVREG_CTRL_DEFAULT;
#endif /* (2U == CY_IP_M0S8HVSS_VERSION) */

#if(1U == CY_IP_M0S8HVSS_VERSION)
    HVSS->RDIV_CTL = 0UL;
#endif /* (1U == CY_IP_M0S8HVSS_VERSION) */

    HVSS->LIN_CTL       = 0UL;
    HVSS->LIN_TIMER     = 0UL;
    HVSS->LIN_INTR      = CY_HVSS_LIN_INTR_MSK;
    HVSS->LIN_INTR_MASK = 0UL;
}

/*******************************************************************************
* Function Name: Cy_HVSS_Hvreg_GetStatus
****************************************************************************//**
*
* \brief Gets the status of the HVSS regulator.
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \note Cy_Hvss_Init() must be called before calling Cy_Hvss_Hvreg_GetStatus()
*
* \return  Composite bitmask. See \ref group_hvss_hvreg_status_macros
* to get the actual bit value for each status.
*
*******************************************************************************/
uint8_t Cy_HVSS_Hvreg_GetStatus(void)
{
    return ((uint8_t)HVSS->HVREG_STATUS);
}

/*******************************************************************************
* Function Name: Cy_HVSS_LinPhy_GetRxdPin
****************************************************************************//**
*
* \brief Current state of LIN pin.
* \note Except when linMode is CY_HVSS_LIN_PHY_MODE_DISABLED
* or CY_HVSS_LIN_PHY_MODE_STANDBY, when LIN RXD = 1
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \return Status of LIN RXD pin.
*
* \return None
*
*******************************************************************************/
uint8_t Cy_HVSS_LinPhy_GetRxdPin(void)
{
    return ((uint8_t)HVSS->LIN_STATUS);
}

/*******************************************************************************
* Function Name: Cy_HVSS_LinPhy_EnableWakeupTimer
****************************************************************************//**
*
* \brief Enable wakeup timer.
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \return None
*
*******************************************************************************/
void Cy_HVSS_LinPhy_EnableWakeupTimer(void)
{
    HVSS->LIN_TIMER |= HVSS_LIN_TIMER_WAKEUP_TIMER_EN_Msk;
}

/*******************************************************************************
* Function Name: Cy_HVSS_LinPhy_DisableWakeupTimer
****************************************************************************//**
*
* \brief Disable wakeup timer.
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \return None
*
*******************************************************************************/
void Cy_HVSS_LinPhy_DisableWakeupTimer(void)
{
    HVSS->LIN_TIMER &= ~HVSS_LIN_TIMER_WAKEUP_TIMER_EN_Msk;
}

/*******************************************************************************
* Function Name: Cy_HVSS_LinPhy_EnableFaultTimer
****************************************************************************//**
*
* \brief Enable the fault timer.
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \return None
*
*******************************************************************************/
void Cy_HVSS_LinPhy_EnableFaultTimer(void)
{
    HVSS->LIN_TIMER |= HVSS_LIN_TIMER_FAULT_TIMER_EN_Msk;
}

/*******************************************************************************
* Function Name: Cy_HVSS_LinPhy_DisableFaultTimer
****************************************************************************//**
*
* \brief Disable the fault timer.
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \return None
*
*******************************************************************************/
void Cy_HVSS_LinPhy_DisableFaultTimer(void)
{
    HVSS->LIN_TIMER &= ~HVSS_LIN_TIMER_FAULT_TIMER_EN_Msk;
}

/*******************************************************************************
* Function Name: Cy_HVSS_LinPhy_SetPhyMode
****************************************************************************//**
*
* \brief Set mode of LIN-PHY.
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \param mode
*  LIN-PHY mode. See \ref cy_hvss_lin_phy_mode_t
*
* \return None
*
*******************************************************************************/
void Cy_HVSS_LinPhy_SetPhyMode(cy_hvss_lin_phy_mode_t mode)
{
    CY_ASSERT_L1(CY_HVSS_LIN_PHY_MODE_FAST > mode);

    HVSS->LIN_CTL = _CLR_SET_FLD32U(HVSS->LIN_CTL, HVSS_LIN_CTL_LIN_MODE, mode);
}

/*******************************************************************************
* Function Name: Cy_Hvss_LinPhy_EnablePhy
****************************************************************************//**
*
* \brief Enable the LIN-PHY.
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \return None
*
*******************************************************************************/
void Cy_Hvss_LinPhy_EnablePhy(void)
{
    HVSS->LIN_CTL |= HVSS_LIN_CTL_LIN_EN_Msk;
}

/*******************************************************************************
* Function Name: Cy_HVSS_LinPhy_DisablePhy
****************************************************************************//**
*
* \brief Disable the LIN-PHY.
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \return None
*
*******************************************************************************/
void Cy_HVSS_LinPhy_DisablePhy(void)
{
    HVSS->LIN_CTL &= ~HVSS_LIN_CTL_LIN_EN_Msk;
}

/*******************************************************************************
* Function Name: Cy_HVSS_LinPhy_ClearInterrupt
****************************************************************************//**
*
* \brief Clear the interrupt.
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \param interrupt
*  Interrupt composite bitmask. See \ref group_hvss_lin_interrupt_macros
*
* \return None
*
*******************************************************************************/
void Cy_HVSS_LinPhy_ClearInterrupt(uint32_t interrupt)
{
    HVSS->LIN_INTR = interrupt & CY_HVSS_LIN_INTR_MSK;
}

/*******************************************************************************
* Function Name: Cy_HVSS_LinPhy_GetIntrMask
****************************************************************************//**
*
* \brief Get the interrupt mask, which indicates the enabled interrupt of HVSS
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \return Composite bitmask.
* See \ref group_hvss_lin_interrupt_macros to get the actual bit value for each interrupt.
*
* \return None
*
*******************************************************************************/
uint32_t Cy_HVSS_LinPhy_GetIntrMask(void)
{
    return (HVSS->LIN_INTR_MASK);
}

/*******************************************************************************
* Function Name: Cy_HVSS_LinPhy_SetIntrMask
****************************************************************************//**
*
* \brief Set the interrupt mask
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \param interrupt
*  Interrupt composite bitmask. See \ref group_hvss_lin_interrupt_macros
*
* \return None
*
*******************************************************************************/
void Cy_HVSS_LinPhy_SetIntrMask(uint32_t interrupt)
{
    HVSS->LIN_INTR_MASK = interrupt & CY_HVSS_LIN_INTR_MSK;
}

/*******************************************************************************
* Function Name: Cy_HVSS_LinPhy_GetIntrStatusMasked
****************************************************************************//**
*
* \brief Gets the interrupt masked status
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \return
* Bitwise AND between the interrupt request and mask registers
*
* Mask with \ref group_hvss_lin_interrupt_macros to get the actual bit value for
* each masked interrupt status.
*
*******************************************************************************/
uint32_t Cy_HVSS_LinPhy_GetIntrStatusMasked(void)
{
    return (HVSS->LIN_INTR_MASKED);
}

/*******************************************************************************
* Function Name: Cy_HVSS_LinPhy_GetIntrStatus
****************************************************************************//**
*
* \brief Gets the interrupt statuses from the LIN_INTR register.
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \return
* Mask with \ref group_hvss_lin_interrupt_macros to get the actual bit value for each interrupt
*
*******************************************************************************/
uint32_t Cy_HVSS_LinPhy_GetIntrStatus(void)
{
    return (HVSS->LIN_INTR);
}

#endif /* defined (CY_IP_M0S8HVSS) */
