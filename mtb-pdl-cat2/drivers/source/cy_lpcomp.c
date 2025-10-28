/*******************************************************************************
* \file cy_lpcomp.c
* \version 1.0.1
*
* \brief
*  This file provides the driver code to the API for the low-power comparator.
*
********************************************************************************
* \copyright
* (c) (2016-2021), Cypress Semiconductor Corporation (an Infineon company) or
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

#include "cy_lpcomp.h"

#if defined (CY_IP_M0S8LPCOMP)


/*******************************************************************************
* Function Name: Cy_LPComp_Init
****************************************************************************//**
*
* Initializes the low-power comparator.
*
* \note The interrupt mode configuration is not written to the register
* during the execution of the function. This can result in unexpected interrupts
* when the comparator is enabled. Instead the configuration is saved to the
* context and applied in the \ref Cy_LPComp_Enable() function.
*
* \param *base
* The low-power comparator registers structure-pointer.
*
* \param channel
* The low-power comparator channel number.
*
* \param *config
* The pointer to the configuration structure.
*
* \param *context
* The pointer to the context structure \ref cy_stc_lpcomp_context_t allocated
* by the user. The structure is used during the low-power comparator operation
* for internal configuration and data retention. The user must not modify
* anything in this structure.
*
* \return
* \ref cy_en_lpcomp_status_t
*
*******************************************************************************/
cy_en_lpcomp_status_t Cy_LPComp_Init(LPCOMP_Type* base, cy_en_lpcomp_channel_t channel, const cy_stc_lpcomp_config_t* config,
                                     cy_stc_lpcomp_context_t *context)
{
    cy_en_lpcomp_status_t ret = CY_LPCOMP_BAD_PARAM;

    if ((base != NULL) && (config != NULL) && (context != NULL))
    {
        CY_ASSERT_L3(CY_LPCOMP_IS_INTR_MODE_VALID(config->intType));

        Cy_LPComp_SetHysteresis(base, channel, config->hysteresis);
        Cy_LPComp_SetOutputMode(base, channel, config->outputMode);
        Cy_LPComp_SetPower(base, channel, config->power);

        /* Save to use in the Cy_LPComp_Enable() */
        context->intType[(uint8_t)channel - 1U] = config->intType;

        ret = CY_LPCOMP_SUCCESS;
    }

    return (ret);
}


/*******************************************************************************
* Function Name: Cy_LPComp_Enable
****************************************************************************//**
*
* Enables the low-power comparator and sets the interrupt mode.
*
* \param *base
* The low-power comparator registers structure-pointer.
*
* \param channel
* The low-power comparator channel number.
*
* \param *context
* The pointer to the context structure \ref cy_stc_lpcomp_context_t allocated
* by the user. The structure is used during the low-power comparator operation
* for internal configuration and data retention. The user must not modify
* anything in this structure.
*
*******************************************************************************/
void Cy_LPComp_Enable(LPCOMP_Type* base, cy_en_lpcomp_channel_t channel, cy_stc_lpcomp_context_t *context)
{
    CY_ASSERT_L3(CY_LPCOMP_IS_CHANNEL_VALID(channel));

    LPCOMP_CONFIG(base) |= ((CY_LPCOMP_CHANNEL_0 == channel) ? LPCOMP_CONFIG_ENABLE1_Msk : LPCOMP_CONFIG_ENABLE2_Msk);
    Cy_LPComp_SetInterruptTriggerMode(base, channel, context->intType[(uint8_t)channel - 1U], context);
}


/*******************************************************************************
* Function Name: Cy_LPComp_Disable
****************************************************************************//**
*
* Disables the low-power comparator and sets the interrupt mode to disabled.
*
* \note The interrupt is disabled by this function because when the comparator
* is disabled its output stops working and the interrupt triggers. The
* actual configuration is restored from the context in:
* \ref Cy_LPComp_Enable().
*
* \param *base
* The low-power comparator registers structure-pointer.
*
* \param channel
* The low-power comparator channel number.
*
* \param *context
* The pointer to the context structure \ref cy_stc_lpcomp_context_t allocated
* by the user. The structure is used during the low-power comparator operation
* for internal configuration and data retention. The user must not modify
* anything in this structure.
*
*******************************************************************************/
void Cy_LPComp_Disable(LPCOMP_Type* base, cy_en_lpcomp_channel_t channel, cy_stc_lpcomp_context_t *context)
{
    CY_ASSERT_L3(CY_LPCOMP_IS_CHANNEL_VALID(channel));

    Cy_LPComp_SetInterruptTriggerMode(base, channel, CY_LPCOMP_INTR_DISABLE, context);
    LPCOMP_CONFIG(base) &= ~((CY_LPCOMP_CHANNEL_0 == channel) ? LPCOMP_CONFIG_ENABLE1_Msk : LPCOMP_CONFIG_ENABLE2_Msk);
}


/*******************************************************************************
* Function Name: Cy_LPComp_SetInterruptTriggerMode
****************************************************************************//**
*
* Sets the interrupt Edge-detect mode.
*
* \param *base
* The low-power comparator registers structure-pointer.
*
* \param channel
* The low-power comparator channel number.
*
* \param intType
* Interrupt edge trigger selection \ref cy_en_lpcomp_int_t
*
* \param *context
* The pointer to the context structure \ref cy_stc_lpcomp_context_t allocated
* by the user. The structure is used during the low-power comparator operation
* for internal configuration and data retention. The user must not modify
* anything in this structure.
*
*******************************************************************************/
void Cy_LPComp_SetInterruptTriggerMode(LPCOMP_Type* base, cy_en_lpcomp_channel_t channel, cy_en_lpcomp_int_t intType,
                                       cy_stc_lpcomp_context_t *context)
{
    CY_ASSERT_L3(CY_LPCOMP_IS_CHANNEL_VALID(channel));
    CY_ASSERT_L3(CY_LPCOMP_IS_INTR_MODE_VALID(intType));

    if (CY_LPCOMP_CHANNEL_0 == channel)
    {
        CY_REG32_CLR_SET(LPCOMP_CONFIG(base), LPCOMP_CONFIG_INTTYPE1, intType);
    }
    else
    {
        CY_REG32_CLR_SET(LPCOMP_CONFIG(base), LPCOMP_CONFIG_INTTYPE2, intType);
    }

    /* Save interrupt type to use it in the Cy_LPComp_Enable() function */
    context->intType[(uint8_t)channel - 1U] = intType;
}


/*******************************************************************************
* Function Name: Cy_LPComp_SetPower
****************************************************************************//**
*
* Sets Drive power mode and speed configuration.
*
* The power consumption and response time vary depending on the selected power
* mode; power consumption is the highest in Fast mode and the lowest in Ultra-low-power
* mode, response time is fastest in fast mode and slowest in ultra-low-power
* mode. Refer to the device datasheet for specifications for the response time
* and power consumption for various power settings.
*
* \note The output of the comparator may stop working when Power mode is changed
* while the comparator is enabled. To avoid this, disable the comparator before
* changing Power mode.
*
* \param *base
* The low-power comparator registers structure pointer.
*
* \param channel
* The low-power comparator channel number.
*
* \param power \ref cy_en_lpcomp_pwr_t
*
*******************************************************************************/
void Cy_LPComp_SetPower(LPCOMP_Type* base, cy_en_lpcomp_channel_t channel, cy_en_lpcomp_pwr_t power)
{
    CY_ASSERT_L3(CY_LPCOMP_IS_CHANNEL_VALID(channel));
    CY_ASSERT_L3(CY_LPCOMP_IS_POWER_VALID(power));

    if (CY_LPCOMP_CHANNEL_0 == channel)
    {
        CY_REG32_CLR_SET(LPCOMP_CONFIG(base), LPCOMP_CONFIG_MODE1, power);
    }
    else
    {
        CY_REG32_CLR_SET(LPCOMP_CONFIG(base), LPCOMP_CONFIG_MODE2, power);
    }
}


/*******************************************************************************
* Function Name: Cy_LPComp_SetHysteresis
****************************************************************************//**
*
* Configures the 10 mV hysteresis level.
*
* Enabling the hysteresis helps ensure that slowly moving voltages or
* slightly noisy voltages will not cause the output of the comparator to
* oscillate when the two input voltages are nearly equal.
*
* \param *base
* The low-power comparator registers structure-pointer.
*
* \param channel
* The low-power comparator channel number.
*
* \param hysteresis \ref cy_en_lpcomp_hyst_t
*
*******************************************************************************/
void Cy_LPComp_SetHysteresis(LPCOMP_Type* base, cy_en_lpcomp_channel_t channel, cy_en_lpcomp_hyst_t hysteresis)
{
    CY_ASSERT_L3(CY_LPCOMP_IS_CHANNEL_VALID(channel));
    CY_ASSERT_L3(CY_LPCOMP_IS_HYSTERESIS_VALID(hysteresis));

    if (CY_LPCOMP_CHANNEL_0 == channel)
    {
        CY_REG32_CLR_SET(LPCOMP_CONFIG(base), LPCOMP_CONFIG_HYST1, hysteresis);
    }
    else
    {
        CY_REG32_CLR_SET(LPCOMP_CONFIG(base), LPCOMP_CONFIG_HYST2, hysteresis);
    }
}


/*******************************************************************************
* Function Name: Cy_LPComp_SetOutputMode
****************************************************************************//**
*
* Sets the comparator Output mode.
*
* \param *base
* The low-power comparator registers structure-pointer.
*
* \param channel
* The low-power comparator channel number.
*
* \param outType
* Comparator output mode \ref cy_en_lpcomp_out_t
*
*******************************************************************************/
void Cy_LPComp_SetOutputMode(LPCOMP_Type* base, cy_en_lpcomp_channel_t channel, cy_en_lpcomp_out_t outType)
{
    CY_ASSERT_L3(CY_LPCOMP_IS_CHANNEL_VALID(channel));
    CY_ASSERT_L3(CY_LPCOMP_IS_OUT_MODE_VALID(outType));

    if (CY_LPCOMP_CHANNEL_0 == channel)
    {
        CY_REG32_CLR_SET(LPCOMP_CONFIG(base), CY_LPCOMP_CMP1_OUTPUT_CONFIG, outType);
    }
    else
    {
        CY_REG32_CLR_SET(LPCOMP_CONFIG(base), CY_LPCOMP_CMP2_OUTPUT_CONFIG, outType);
    }
}


/*******************************************************************************
* Function Name: Cy_LPComp_DeepSleepCallback
****************************************************************************//**
*
* Checks the current Enable mode of LPComp and then disables the
* low-power comparator block if there is no wake-up source from the low-power
* comparator in Deep Sleep mode.
*
* Stores the Enabled state of the low-power comparator and then disables the
* low-power comparator block before going to Low-power modes, and recovers
* the low-power comparator Enabled state after a wake-up using the stored value.
*
* \param *callbackParams
* The pointer to the \ref cy_stc_syspm_callback_params_t structure.
*
* \param mode
* Callback mode, see \ref cy_en_syspm_callback_mode_t
*
* \return
* \ref cy_en_syspm_status_t
*
*******************************************************************************/
cy_en_syspm_status_t Cy_LPComp_DeepSleepCallback(cy_stc_syspm_callback_params_t *callbackParams, cy_en_syspm_callback_mode_t mode)
{
    cy_en_syspm_status_t ret = CY_SYSPM_FAIL;
    LPCOMP_Type *locBase = (LPCOMP_Type *) (callbackParams->base);
    static uint32_t enabledStatus;

    switch(mode)
    {
        case CY_SYSPM_CHECK_READY:
            {
                ret = CY_SYSPM_SUCCESS;
            }
            break;

        case CY_SYSPM_CHECK_FAIL:
            {
                ret = CY_SYSPM_SUCCESS;
            }
            break;

        case CY_SYSPM_BEFORE_TRANSITION:
            {
                /* Save the enable state */
                enabledStatus = LPCOMP_CONFIG(locBase) & (LPCOMP_CONFIG_ENABLE1_Msk | LPCOMP_CONFIG_ENABLE2_Msk);

                if (0u != enabledStatus)
                {
                    /* Disable the LPComp block when there is no wake-up source from any channel. */
                    if( !(((_FLD2VAL(LPCOMP_CONFIG_MODE1, LPCOMP_CONFIG(locBase)) == (uint32_t)CY_LPCOMP_MODE_ULP) &&
                                    _FLD2BOOL(LPCOMP_INTR_MASK_COMP1_MASK, LPCOMP_INTR_MASK(locBase))) ||
                                ((_FLD2VAL(LPCOMP_CONFIG_MODE2, LPCOMP_CONFIG(locBase)) == (uint32_t)CY_LPCOMP_MODE_ULP) &&
                                 _FLD2BOOL(LPCOMP_INTR_MASK_COMP2_MASK, LPCOMP_INTR_MASK(locBase)))))

                    {
                        /* Disable the LPComp block to avoid leakage */
                        LPCOMP_CONFIG(locBase) &= ~enabledStatus;
                    }
                    else
                    {
                        /* Clear the enable state - no nen */
                        enabledStatus = 0U;
                    }
                }
                ret = CY_SYSPM_SUCCESS;
            }
            break;

        case CY_SYSPM_AFTER_TRANSITION:
            {
                /* Restore enable state */
                LPCOMP_CONFIG(locBase) |= enabledStatus;
                ret = CY_SYSPM_SUCCESS;
            }
            break;

        default:
            /* Unknown state */
            break;
    }

    return (ret);
}


/*******************************************************************************
* Function Name: Cy_LPComp_ZeroCal
****************************************************************************//**
*
* Performs custom calibration of the input offset to minimize the error for a
* specific set of conditions: the comparator reference voltage, supply voltage,
* and operating temperature. Refer to technical reference manual (TRM) and the
* device datasheet for more details.
*
* \note The comparator offset is trimmed at the factory. For normal operation,
* further adjustment of trim values is not recommended.
*
* \note A reference voltage in the range at which the comparator will be used,
* must be applied to one of the inputs. The two inputs will be shorted
* internally to perform the offset calibration.
*
* \note Before calibration the comparator should be in the slow mode with the
* hysteresis be turned off.
*
* \param *base
* The low-power comparator registers structure-pointer.
*
* \param channel
* The low-power comparator channel number.
*
* \return
*  The value from the comparator trim register after the offset calibration is
*  complete. This value has the same format as the input parameter for the
*  Cy_LPComp_LoadTrim() API routine.
*
* \funcusage
* \snippet lpcomp_snippet.c LPCOMP_TRIM
*
*******************************************************************************/
uint32_t Cy_LPComp_ZeroCal(LPCOMP_Type const * base, cy_en_lpcomp_channel_t channel)
{
    uint32_t cmpOut;
    uint32_t i;
    uint32_t mode;

    __IOM uint32_t *trimAReg;
    __IOM uint32_t *trimBReg;

    if (CY_LPCOMP_CHANNEL_0 == channel)
    {
        trimAReg = &LPCOMP_TRIM1(base);
        trimBReg = &LPCOMP_TRIM2(base);
        mode = (LPCOMP_CONFIG(base) & LPCOMP_CONFIG_MODE1_Msk);
    }
    else
    {
        trimAReg = &LPCOMP_TRIM3(base);
        trimBReg = &LPCOMP_TRIM4(base);
        mode = ((LPCOMP_CONFIG(base) & LPCOMP_CONFIG_MODE2_Msk) >> LPCOMP_CONFIG_MODE2_Pos);
    }

    /* Setting this bit shorts the inputs of the comparators for offset measurement. */
    LPCOMP_DFT_REG |= LPCOMP_DFT_CAL_EN_Msk;

    *trimAReg = 0U;
    *trimBReg = 0U;

    Cy_SysLib_DelayUs(1U);

    cmpOut = Cy_LPComp_GetCompare(base, channel);

    if(0u != cmpOut)
    {
        *trimAReg = ((uint32_t) 0x01U << CY_LPCOMP_TRIMA_SIGNBIT);
    }

    for(i = (CY_LPCOMP_TRIMA_MAX_VALUE + 1U); i != 0U; i--)
    {
        (*trimAReg)++;
        Cy_SysLib_DelayUs(1U);
        if(cmpOut != Cy_LPComp_GetCompare(base, channel))
        {
            break;
        }
    }

    if(mode == (uint32_t)CY_LPCOMP_MODE_SLOW)
    {
        cmpOut = Cy_LPComp_GetCompare(base, channel);

        if(0U == cmpOut)
        {
            *trimBReg = ((uint32_t) 0x01U << CY_LPCOMP_TRIMB_SIGNBIT);
        }

        for(i = (CY_LPCOMP_TRIMB_MAX_VALUE + 1U); i != 0U; i--)
        {
            (*trimBReg)++;
            Cy_SysLib_DelayUs(1U);
            if(cmpOut != Cy_LPComp_GetCompare(base, channel))
            {
                break;
            }
        }
    }

    /* Disable calibration */
    LPCOMP_DFT_REG &= ((uint32_t)~LPCOMP_DFT_CAL_EN_Msk);

    return (*trimAReg | ((uint32_t)(*trimBReg) << CY_LPCOMP_TRIMB_SHIFT));
}


/*******************************************************************************
* Function Name: Cy_LPComp_LoadTrim
****************************************************************************//**
*
* Writes a value into the comparator offset trim register.
* See \ref Cy_LPComp_ZeroCal() description for the procedure of getting trim.
*
* \param *base
* The low-power comparator registers structure-pointer.
*
* \param channel
* The low-power comparator channel number.
*
* \param trimVal
*  The value to store into the comparator offset trim-register. This
*  value has the same format as the parameter returned by the
*  \ref Cy_LPComp_ZeroCal() API routine.
*
*******************************************************************************/
void Cy_LPComp_LoadTrim(LPCOMP_Type const * base, cy_en_lpcomp_channel_t channel, uint32_t trimVal)
{
    if (CY_LPCOMP_CHANNEL_0 == channel)
    {
        LPCOMP_TRIM1(base) = (trimVal & LPCOMP_TRIM1_COMP1_TRIMA_Msk);
        LPCOMP_TRIM2(base) = ((trimVal >> CY_LPCOMP_TRIMB_SHIFT) & CY_LPCOMP_TRIM2_COMP1_TRIMB_Msk);
    }
    else
    {
        LPCOMP_TRIM3(base) = (trimVal & LPCOMP_TRIM3_COMP2_TRIMA_Msk);
        LPCOMP_TRIM4(base) = ((trimVal >> CY_LPCOMP_TRIMB_SHIFT) & CY_LPCOMP_TRIM4_COMP2_TRIMB_Msk);
    }
}

#endif /* CY_IP_M0S8LPCOMP */

/* [] END OF FILE */
