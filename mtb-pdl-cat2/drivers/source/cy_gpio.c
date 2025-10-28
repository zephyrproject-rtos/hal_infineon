/***************************************************************************//**
* \file cy_gpio.c
* \version 3.0
*
* Provides an API implementation of the GPIO driver
*
********************************************************************************
* \copyright
* (c) (2016-2021), Cypress Semiconductor Corporation (an Infineon company) or
* an affiliate of Cypress Semiconductor Corporation.
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

#include "cy_gpio.h"

#if defined(__cplusplus)
extern "C" {
#endif


/* Define for AMUX A splitters */
#define GPIO_AMUXA_SPLITTER_MASK     (uint32_t)(HSIOM_AMUX_SPLIT_CTL_SWITCH_AA_SL_Msk \
                                              | HSIOM_AMUX_SPLIT_CTL_SWITCH_AA_SR_Msk \
                                              | HSIOM_AMUX_SPLIT_CTL_SWITCH_AA_S0_Msk)

/* Define for AMUX B splitters */
#define GPIO_AMUXB_SPLITTER_MASK     (uint32_t)(HSIOM_AMUX_SPLIT_CTL_SWITCH_BB_SL_Msk \
                                              | HSIOM_AMUX_SPLIT_CTL_SWITCH_BB_SR_Msk \
                                              | HSIOM_AMUX_SPLIT_CTL_SWITCH_BB_S0_Msk)



/*******************************************************************************
* Function Name: Cy_GPIO_Pin_Init
****************************************************************************//**
*
* Initializes all pin configuration settings for the specified pin.
*
* \param base
* Pointer to the pin's port register base address
*
* \param pinNum
* Position of the pin bit-field within the port register
*
* \param config
* Pointer to the pin config structure base address
*
* \return
* Initialization status
*
* \note
* This function modifies port registers in read-modify-write operations. It is
* not thread safe as the resource is shared among multiple pins on a port.
*
* \funcusage
* \snippet gpio_snippet.c snippet_Cy_GPIO_Pin_Init
*
*******************************************************************************/
cy_en_gpio_status_t Cy_GPIO_Pin_Init(GPIO_PRT_Type *base, uint32_t pinNum, const cy_stc_gpio_pin_config_t *config)
{
    cy_en_gpio_status_t status = CY_GPIO_BAD_PARAM;

    if ((NULL != base) && (NULL != config))
    {

        CY_ASSERT_L2(CY_GPIO_IS_PIN_VALID(pinNum));
        CY_ASSERT_L2(CY_GPIO_IS_VALUE_VALID(config->outVal));
        CY_ASSERT_L2(CY_GPIO_IS_DM_VALID(config->driveMode));
        CY_ASSERT_L2(CY_GPIO_IS_HSIOM_VALID(config->hsiom));
        CY_ASSERT_L2(CY_GPIO_IS_INT_EDGE_VALID(config->intEdge));
        CY_ASSERT_L2(CY_GPIO_IS_VALUE_VALID(config->vtrip));
        CY_ASSERT_L2(CY_GPIO_IS_VALUE_VALID(config->slewRate));

        Cy_GPIO_Write(base, pinNum, config->outVal);
        Cy_GPIO_SetDrivemode(base, pinNum, config->driveMode);
        Cy_GPIO_SetHSIOM(base, pinNum, config->hsiom);

        Cy_GPIO_SetInterruptEdge(base, pinNum, config->intEdge);
        Cy_GPIO_SetVtrip(base, config->vtrip);
        Cy_GPIO_SetSlewRate(base, config->slewRate);

        status = CY_GPIO_SUCCESS;
    }

    return(status);
}


/*******************************************************************************
* Function Name: Cy_GPIO_Port_Init
****************************************************************************//**
*
* Initialize a complete port of pins from a single init structure.
*
* The configuration structure used in this function has a 1:1 mapping to the
* GPIO and HSIOM registers. Refer to the device Technical Reference Manual (TRM)
* for the register details on how to populate them.
*
* \param base
* Pointer to the pin's port register base address
*
* \param config
* Pointer to the pin config structure base address
*
* \return
* Initialization status
*
* \funcusage
* \snippet gpio_snippet.c snippet_Cy_GPIO_Port_Init
*
*******************************************************************************/
cy_en_gpio_status_t Cy_GPIO_Port_Init(GPIO_PRT_Type* base, const cy_stc_gpio_prt_config_t *config)
{
    cy_en_gpio_status_t status = CY_GPIO_BAD_PARAM;

    if ((NULL != base) && (NULL != config))
    {
        uint32_t portNum;
        HSIOM_PRT_Type* baseHSIOM;

        CY_ASSERT_L2(CY_GPIO_IS_PIN_BIT_VALID(config->dr));
        CY_ASSERT_L2(CY_GPIO_IS_PIN_BIT_VALID(config->pc2));
        CY_ASSERT_L2(CY_GPIO_IS_INTR_CFG_VALID(config->intrCfg));
        CY_ASSERT_L2(CY_GPIO_IS_SEL_ACT_VALID(config->selActive));

        portNum = ((uint32_t)(base) - GPIO_BASE) / GPIO_PRT_SECTION_SIZE;
        baseHSIOM = (HSIOM_PRT_Type*)(HSIOM_BASE + (HSIOM_PRT_SECTION_SIZE * portNum));

        GPIO_PRT_DR(base)              = config->dr;
        GPIO_PRT_PC(base)              = config->pc;
        GPIO_PRT_PC2(base)             = config->pc2;
        GPIO_PRT_INTR_CFG(base)        = config->intrCfg;
        HSIOM_PRT_PORT_SEL(baseHSIOM)  = config->selActive;

        status = CY_GPIO_SUCCESS;
    }

    return (status);
}


/*******************************************************************************
* Function Name: Cy_GPIO_SetAmuxSplit
****************************************************************************//**
*
* Configure a specific AMux bus splitter switch cell into a specific
* configuration.
*
* \param switchCtrl
* Selects specific AMux bus splitter cell between two segments.
* The cy_en_amux_split_t enumeration can be found in the GPIO header file
* for the device package.
*
* \param amuxConnect
* Selects configuration of the three switches within the splitter cell
*
* \param amuxBus
* Selects which AMux bus within the splitter is being configured
*
*******************************************************************************/
void Cy_GPIO_SetAmuxSplit(cy_en_amux_split_t switchCtrl, cy_en_gpio_amuxconnect_t amuxConnect,
                                                         cy_en_gpio_amuxselect_t amuxBus)
{
    CY_ASSERT_L2(CY_GPIO_IS_AMUX_SPLIT_VALID(switchCtrl));
    CY_ASSERT_L3(CY_GPIO_IS_AMUX_CONNECT_VALID(amuxConnect));
    CY_ASSERT_L3(CY_GPIO_IS_AMUX_SELECT_VALID(amuxBus));

    uint32_t tmpReg;

    if (amuxBus != CY_GPIO_AMUXBUSB)
    {
        tmpReg = HSIOM_AMUX_SPLIT_CTL(switchCtrl) & GPIO_AMUXB_SPLITTER_MASK;
        HSIOM_AMUX_SPLIT_CTL(switchCtrl) = tmpReg | ((uint32_t) amuxConnect & GPIO_AMUXA_SPLITTER_MASK);
    }
    else
    {
        tmpReg = HSIOM_AMUX_SPLIT_CTL(switchCtrl) & GPIO_AMUXA_SPLITTER_MASK;
        HSIOM_AMUX_SPLIT_CTL(switchCtrl) =
        tmpReg | (((uint32_t) amuxConnect << HSIOM_AMUX_SPLIT_CTL_SWITCH_BB_SL_Pos) & GPIO_AMUXB_SPLITTER_MASK);
    }
}


/*******************************************************************************
* Function Name: Cy_GPIO_GetAmuxSplit
****************************************************************************//**
*
* Returns the configuration of a specific AMux bus splitter switch cell.
*
* \param switchCtrl
* Selects specific AMux bus splitter cell between two segments.
* The cy_en_amux_split_t enumeration can be found in the GPIO header file
* for the device package.
*
* \param amuxBus
* Selects which AMux bus within the splitter is being configured
*
* \return
* Returns configuration of the three switches in the selected splitter cell
*
*******************************************************************************/
cy_en_gpio_amuxconnect_t Cy_GPIO_GetAmuxSplit(cy_en_amux_split_t switchCtrl, cy_en_gpio_amuxselect_t amuxBus)
{
    CY_ASSERT_L2(CY_GPIO_IS_AMUX_SPLIT_VALID(switchCtrl));
    CY_ASSERT_L3(CY_GPIO_IS_AMUX_SELECT_VALID(amuxBus));

    uint32_t retVal;

    if (amuxBus != CY_GPIO_AMUXBUSB)
    {
        retVal = HSIOM_AMUX_SPLIT_CTL(switchCtrl) & GPIO_AMUXA_SPLITTER_MASK;
    }
    else
    {
        retVal = ((uint32_t) ((HSIOM_AMUX_SPLIT_CTL(switchCtrl) & GPIO_AMUXB_SPLITTER_MASK)
                                                     >> HSIOM_AMUX_SPLIT_CTL_SWITCH_BB_SL_Pos));
    }

    return ((cy_en_gpio_amuxconnect_t) retVal);
}

#if defined(__cplusplus)
}
#endif


/* [] END OF FILE */
