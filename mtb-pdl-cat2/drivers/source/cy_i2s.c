/***************************************************************************//**
* \file cy_i2s.c
* \version 1.10
*
* The source code file for the I2S driver.
*
********************************************************************************
* \copyright
* (c) (2020-2022), Cypress Semiconductor Corporation (an Infineon company) or
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

#include "cy_device_headers.h"

#if defined (CY_IP_MXAUDIOSS)

#include "cy_i2s.h"


/*******************************************************************************
* Function Name: Cy_I2S_Init
****************************************************************************//**
*
* Initializes the I2S module in accordance with a configuration structure.
*
* \pre If the I2S module is initialized previously, the \ref Cy_I2S_DeInit()
* must be called before calling this function.
*
* \param base      The pointer to the I2S instance address.
*
* \param config    The pointer to a configuration structure.
*
* \return error / status code. See \ref cy_en_i2s_status_t.
*
* \funcusage
* \snippet i2s_snippet.c snippet_Cy_I2S_Init
*
*******************************************************************************/
cy_en_i2s_status_t Cy_I2S_Init(I2S_Type * base, cy_stc_i2s_config_t const * config)
{
    cy_en_i2s_status_t ret = CY_I2S_BAD_PARAM;

    if((NULL != base) && (NULL != config))
    {
        cy_en_i2s_ws_pw_t wsPulseWidth;
        cy_en_i2s_len_t channelLength;
        uint32_t channels;
        uint32_t clockDiv = (uint32_t)config->clkDiv - 1U;

        CY_ASSERT_L2(CY_I2S_IS_CLK_DIV_VALID(clockDiv));

        I2S_INTR_MASK(base) = 0UL; /* Disable interrupts prior to stopping the operation */
        I2S_CMD(base) = 0UL; /* Stop any communication */
        I2S_CTL(base) = 0UL; /* Disable TX sub-block before clock changing */

        /* The clock setting */
        I2S_CLOCK_CTL(base) = _VAL2FLD(I2S_CLOCK_CTL_CLOCK_DIV, clockDiv) |
                                 _BOOL2FLD(I2S_CLOCK_CTL_CLOCK_SEL, config->extClk);

        /* The TX setting */
        CY_ASSERT_L3(CY_I2S_IS_ALIGNMENT_VALID(config->txAlignment));
        CY_ASSERT_L3(CY_I2S_IS_OVHDATA_VALID(config->txOverheadValue));

        if ((CY_I2S_TDM_MODE_A == config->txAlignment) || (CY_I2S_TDM_MODE_B == config->txAlignment))
        {
            channels = (uint32_t)config->txChannels - 1UL;
            wsPulseWidth = config->txWsPulseWidth;
            channelLength = CY_I2S_LEN32;

            CY_ASSERT_L2(CY_I2S_IS_CHANNELS_VALID(channels));
            CY_ASSERT_L3(CY_I2S_IS_WSPULSE_VALID(wsPulseWidth));
            CY_ASSERT_L3(CY_I2S_IS_LEN_VALID(config->txWordLength));
        }
        else
        {
            channels = 1UL;
            wsPulseWidth = CY_I2S_WS_ONE_CHANNEL_LENGTH;
            channelLength = config->txChannelLength;

            CY_ASSERT_L3(CY_I2S_IS_CHAN_WORD_VALID(channelLength, config->txWordLength));
        }

        CY_ASSERT_L2(CY_I2S_IS_TRIG_LEVEL_VALID(config->txFifoTriggerLevel, channels));

        I2S_TX_CTL(base) = _VAL2FLD(I2S_TX_CTL_I2S_MODE, config->txAlignment) |
                           _VAL2FLD(I2S_TX_CTL_CH_NR, channels) |
                           I2S_TX_CTL_MS_Msk |
                           _VAL2FLD(I2S_TX_CTL_WS_PULSE, wsPulseWidth) |
                           _BOOL2FLD(I2S_TX_CTL_SCKO_POL, config->txSckoInversion) |
                           _VAL2FLD(I2S_TX_CTL_CH_LEN, channelLength) |
                           _VAL2FLD(I2S_TX_CTL_WORD_LEN, config->txWordLength) |
                           _VAL2FLD(I2S_TX_CTL_OVHDATA, config->txOverheadValue);

        /* The I2S enable setting */
        I2S_CTL(base) |= I2S_CTL_TX_ENABLED_Msk;

        /* The FIFO setting */
        I2S_TX_FIFO_CTL(base) = _VAL2FLD(I2S_TX_FIFO_CTL_TRIGGER_LEVEL, config->txFifoTriggerLevel);

        ret = CY_I2S_SUCCESS;
    }

    return (ret);
}


/*******************************************************************************
* Function Name: Cy_I2S_DeInit
****************************************************************************//**
*
* Uninitializes the I2S module (reverts default register values).
*
* \param base The pointer to the I2S instance address.
*
* \funcusage
* \snippet i2s_snippet.c snippet_Cy_I2S_DeInit
*
*******************************************************************************/
void Cy_I2S_DeInit(I2S_Type * base)
{
    I2S_INTR_MASK(base) = 0UL; /* Disable interrupts prior to stopping the operation */
    I2S_CMD(base) = 0UL;
    I2S_TX_FIFO_CTL(base) = 0UL;
    I2S_CTL(base) = 0UL;
    I2S_TX_CTL(base) = CY_I2S_TX_CTL_DEFAULT;
    I2S_CLOCK_CTL(base) = 0UL;
}


/*******************************************************************************
* Function Name: Cy_I2S_DeepSleepCallback
****************************************************************************//**
*
* This callback function is used at the application layer to
* manage an I2S operation during the Deep Sleep cycle. It stores the I2S state
* (TX enabled/disabled/paused) into the context structure and stops the
* communication before entering Deep Sleep power mode and restores the I2S
* state after waking up.
*
* \param
* callbackParams - The pointer to the callback parameters structure,
* see \ref cy_stc_syspm_callback_params_t.
*
* \param mode
* Callback mode, see \ref cy_en_syspm_callback_mode_t
*
* \return The SysPm callback status \ref cy_en_syspm_status_t.
*
* \note Use the \ref cy_stc_i2s_context_t data type for definition of the
* *context element of the \ref cy_stc_syspm_callback_params_t structure.
*
* \funcusage
* \snippet i2s_snippet.c snippet_Cy_I2S_DeepSleepCallback
*
*******************************************************************************/
cy_en_syspm_status_t Cy_I2S_DeepSleepCallback (cy_stc_syspm_callback_params_t *callbackParams, cy_en_syspm_callback_mode_t mode)
{
    cy_en_syspm_status_t ret = CY_SYSPM_SUCCESS;
    CY_ASSERT_L1(NULL != callbackParams->context);
    I2S_Type * locBase = (I2S_Type*) callbackParams->base;
    uint32_t * locInterruptMask = (uint32_t*) &(((cy_stc_i2s_context_t*)(callbackParams->context))->interruptMask);
    uint32_t * locState = (uint32_t*) &(((cy_stc_i2s_context_t*)(callbackParams->context))->enableState);

    switch(mode)
    {
        case CY_SYSPM_CHECK_READY:
        case CY_SYSPM_CHECK_FAIL:
            break;

        case CY_SYSPM_BEFORE_TRANSITION:
            *locInterruptMask = Cy_I2S_GetInterruptMask(locBase); /* Store I2S interrupts */
            *locState = Cy_I2S_GetCurrentState(locBase); /* Store I2S state */
            if (0UL != (*locState & I2S_CMD_TX_START_Msk))
            {
                Cy_I2S_DisableTx(locBase); /* Stop TX operation */
            }
            Cy_I2S_SetInterruptMask(locBase, 0UL); /* Disable I2S interrupts */
            /* Unload FIFOs to not lose data (if needed) */
            break;

        case CY_SYSPM_AFTER_TRANSITION:
            if (0UL != (*locState & I2S_CMD_TX_START_Msk))
            {
                Cy_I2S_ClearTxFifo(locBase); /* Clear the TX FIFO */
                Cy_I2S_WriteTxData(locBase, 0UL); /* Fill at least one TX frame */
                Cy_I2S_WriteTxData(locBase, 0UL);
                if (0UL != (*locState & I2S_CMD_TX_PAUSE_Msk))
                {
                    Cy_I2S_PauseTx(locBase); /* Restore the TX paused state */
                }
                Cy_I2S_EnableTx(locBase); /* Start TX operation */
            }
            Cy_I2S_ClearInterrupt(locBase, *locInterruptMask); /* Clear possible pending I2S interrupts */
            Cy_I2S_SetInterruptMask(locBase, *locInterruptMask); /* Restore I2S interrupts */
            break;

        default:
            ret = CY_SYSPM_FAIL;
            break;
    }

    return(ret);
}


#endif /* CY_IP_MXAUDIOSS */

/* [] END OF FILE */
