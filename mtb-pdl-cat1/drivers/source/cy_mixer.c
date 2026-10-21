/***************************************************************************//**
* \file cy_mixer.c
* \version 1.0
*
* Provides an API implementation of the mixer driver.
*
********************************************************************************
* \copyright
* Copyright 2016-2024, Cypress Semiconductor Corporation
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

#include "cy_mixer.h"

#if defined (CY_IP_MXMIXER) || defined (CY_DOXYGEN)

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/*******************************************************************************
* Function Name: Cy_Mixer_SourceInit
****************************************************************************//**
* \brief
* Initializes the Mixer source structure.
*
* \param base Pointer to the Mixer SRC Struct instance.
* \param config The pointer to a configuration structure.
*
* \return error / status code. See \ref cy_en_mixer_status_t.
*
* \funcusage
* \snippet mixer/snippet/main.c snippet_Cy_Mixer_SourceInit
*
*******************************************************************************/
cy_en_mixer_status_t Cy_Mixer_SourceInit(volatile MIXER_SRC_STRUCT_Type * base, cy_stc_mixer_src_config_t const * config)
{
    cy_en_mixer_status_t mxStatus = CY_MIXER_BAD_PARAM;

    if ((NULL != base) && (NULL != config))
    {
        /* Set Mixer SRC registers based on the config struct values */
        MIXER_SRC_STRUCT_SRC_CTL(base) = _VAL2FLD(MIXER_MIXER_SRC_STRUCT_SRC_CTL_FS_RATIO, config->fsRatio) |
                                         _VAL2FLD(MIXER_MIXER_SRC_STRUCT_SRC_CTL_CH0_SEL, config->ch0sel)   |
                                         _VAL2FLD(MIXER_MIXER_SRC_STRUCT_SRC_CTL_CH1_SEL, config->ch1sel);

        Cy_Mixer_Src_FadeControl(base, config->fadeCode);
        Cy_Mixer_Src_GainCodeSelect(base, config->gainCode);
        Cy_Mixer_Src_FifoTriggerLevel(base, config->trgLevel);

        mxStatus = CY_MIXER_SUCCESS;
    }

    return mxStatus;
}

/*******************************************************************************
* Function Name: Cy_Mixer_SourceDeInit
****************************************************************************//**
* \brief
* Deinitialize the Mixer source structure.
*
* \param base Pointer to the Mixer SRC Struct instance.
*
* \return None.
*
* \funcusage
* \snippet mixer/snippet/main.c snippet_Cy_Mixer_SourceDeInit
*
*******************************************************************************/
void Cy_Mixer_SourceDeInit(volatile MIXER_SRC_STRUCT_Type * base)
{
    if (NULL != base)
    {
        MIXER_SRC_STRUCT_SRC_CTL(base) = 0UL;
        MIXER_SRC_STRUCT_SRC_FADE_CTL(base) = 0UL;
        MIXER_SRC_STRUCT_SRC_FADE_CMD(base) = 0UL;
        MIXER_SRC_STRUCT_SRC_GAIN_CTL(base) = 0UL;
        MIXER_SRC_STRUCT_SRC_FIFO_CTL(base) = 0UL;
    }
}

/*******************************************************************************
* Function Name: Cy_Mixer_SourceStartFadeIn
****************************************************************************//**
*
* \brief triggers source fade in.
*
* \param base Pointer to the Mixer SRC Struct instance.
*
* \param pace pace of the fade in
*
* \return None.
*
* \funcusage
* \snippet mixer/snippet/main.c snippet_Cy_Mixer_SourceStartFadeIn
*
*******************************************************************************/
void Cy_Mixer_SourceStartFadeIn(volatile MIXER_SRC_STRUCT_Type * base, uint16_t pace)
{
    if (NULL != base)
    {
        MIXER_SRC_STRUCT_SRC_FADE_CMD(base) = _VAL2FLD(MIXER_MIXER_SRC_STRUCT_SRC_FADE_CMD_PACE, pace) |
                                               MIXER_MIXER_SRC_STRUCT_SRC_FADE_CMD_FADE_IN_Msk;
    }
}

/*******************************************************************************
* Function Name: Cy_Mixer_SourceHasFadeInCompleted
****************************************************************************//**
*
* \brief checks previous fade in operation already completed or not
*
* \param base Pointer to the Mixer SRC Struct instance.
*
* \return true : Previous fade in operation already completed \n
*         false: Previous fade in operation still in progress
*
* \funcusage
* \snippet mixer/snippet/main.c snippet_Cy_Mixer_SourceStartFadeIn
*
*******************************************************************************/
bool Cy_Mixer_SourceHasFadeInCompleted(volatile MIXER_SRC_STRUCT_Type * base)
{
    return (0UL == _FLD2VAL(MIXER_MIXER_SRC_STRUCT_SRC_FADE_CMD_FADE_IN, MIXER_SRC_STRUCT_SRC_FADE_CMD(base)));
}

/*******************************************************************************
* Function Name: Cy_Mixer_SourceStartFadeOut
****************************************************************************//**
*
* \brief triggers fade out
*
* \param base Pointer to the Mixer SRC Struct instance.
*
* \param pace pace of the fade out
*
* \param deact true: deactivate the src FIFO when fade out completed \n
*              false: Do not deactivate the src FIFO when fade out completed
*
* \return None.
*
* \funcusage
* \snippet mixer/snippet/main.c snippet_Cy_Mixer_SourceStartFadeOut
*
*******************************************************************************/
void Cy_Mixer_SourceStartFadeOut(volatile MIXER_SRC_STRUCT_Type * base, uint16_t pace, bool deact)
{
    if (NULL != base)
    {
        MIXER_SRC_STRUCT_SRC_FADE_CMD(base) = _VAL2FLD(MIXER_MIXER_SRC_STRUCT_SRC_FADE_CMD_PACE, pace) |
                                              _VAL2FLD(MIXER_MIXER_SRC_STRUCT_SRC_FADE_CMD_AUTO_DEACTIVATE, deact == false ? 0UL : 1UL) |
                                              MIXER_MIXER_SRC_STRUCT_SRC_FADE_CMD_FADE_OUT_Msk;
    }
}

/*******************************************************************************
* Function Name: Cy_Mixer_SourceHasFadeOutCompleted
****************************************************************************//**
*
* \brief checks previous fade out operation already completed or not
*
* \param base Pointer to the Mixer SRC Struct instance.
*
* \return true : Previous fade out operation already completed \n
*         false: Previous fade out operation still in progress
*
* \funcusage
* \snippet mixer/snippet/main.c snippet_Cy_Mixer_SourceStartFadeOut
*
*******************************************************************************/
bool Cy_Mixer_SourceHasFadeOutCompleted(volatile MIXER_SRC_STRUCT_Type * base)
{
    return (0UL == _FLD2VAL(MIXER_MIXER_SRC_STRUCT_SRC_FADE_CMD_FADE_OUT, MIXER_SRC_STRUCT_SRC_FADE_CMD(base)));
}

/*******************************************************************************
* Function Name: Cy_Mixer_DestinationInit
****************************************************************************//**
* \brief
* Initializes the Mixer destination structure.
*
* \param base Pointer to the Mixer DST Struct instance.
* \param config The pointer to a configuration structure.
*
* \return error / status code. See \ref cy_en_mixer_status_t.
*
* \funcusage
* \snippet mixer/snippet/main.c snippet_Cy_Mixer_DestinationInit
*
*******************************************************************************/
cy_en_mixer_status_t Cy_Mixer_DestinationInit(volatile MIXER_DST_STRUCT_Type * base, cy_stc_mixer_dst_config_t const * config)
{
    cy_en_mixer_status_t mxStatus = CY_MIXER_BAD_PARAM;

    if ((NULL != base) && (NULL != config))
    {
        Cy_Mixer_Dst_FadeControl(base, config->fadeCode);
        Cy_Mixer_Dst_GainCodeSelect(base, config->gainCode);
        Cy_Mixer_Dst_FifoTriggerLevel(base, config->trgLevel);

        mxStatus = CY_MIXER_SUCCESS;
    }

    return mxStatus;
}

/*******************************************************************************
* Function Name: Cy_Mixer_DestinationDeInit
****************************************************************************//**
* \brief
* DeInitializes the Mixer destination structure.
*
* \param base Pointer to the Mixer DST Struct instance.
*
* \return None.
*
* \funcusage
* \snippet mixer/snippet/main.c snippet_Cy_Mixer_DestinationDeInit
*
*******************************************************************************/
void Cy_Mixer_DestinationDeInit(volatile MIXER_DST_STRUCT_Type * base)
{
    if (NULL != base)
    {
        MIXER_DST_STRUCT_DST_FADE_CTL(base) = 0UL;
        MIXER_DST_STRUCT_DST_FADE_CMD(base) = 0UL;
        MIXER_DST_STRUCT_DST_GAIN_CTL(base) = 0UL;
        MIXER_DST_STRUCT_DST_FIFO_CTL(base) = 0UL;
    }
}

/*******************************************************************************
* Function Name: Cy_Mixer_DestinationStartFadeIn
****************************************************************************//**
*
* \brief triggers destination fade in.
*
* \param base Pointer to the Mixer DST Struct instance.
*
* \param pace pace of the fade in
*
* \return None.
*
* \funcusage
* \snippet mixer/snippet/main.c snippet_Cy_Mixer_DestinationStartFadeIn
*
*******************************************************************************/
void Cy_Mixer_DestinationStartFadeIn(volatile MIXER_DST_STRUCT_Type * base, uint16_t pace)
{
    if (NULL != base)
    {
        MIXER_DST_STRUCT_DST_FADE_CMD(base) = _VAL2FLD(MIXER_MIXER_DST_STRUCT_DST_FADE_CMD_PACE, pace) |
                                              MIXER_MIXER_DST_STRUCT_DST_FADE_CMD_FADE_IN_Msk;
    }
}

/*******************************************************************************
* Function Name: Cy_Mixer_DestinationHasFadeInCompleted
****************************************************************************//**
*
* \brief checks previous fade in operation already completed or not
*
* \param base Pointer to the Mixer DST Struct instance.
*
* \return true : Previous fade in operation already completed \n
*         false: Previous fade in operation still in progress
*
* \funcusage
* \snippet mixer/snippet/main.c snippet_Cy_Mixer_DestinationStartFadeIn
*
*******************************************************************************/
bool Cy_Mixer_DestinationHasFadeInCompleted(volatile MIXER_DST_STRUCT_Type * base)
{
    return (0UL == _FLD2VAL(MIXER_MIXER_DST_STRUCT_DST_FADE_CMD_FADE_IN, MIXER_DST_STRUCT_DST_FADE_CMD(base)));
}

/*******************************************************************************
* Function Name: Cy_Mixer_DestinationStartFadeOut
****************************************************************************//**
*
* \brief triggers fade out
*
* \param base Pointer to the Mixer DST Struct instance.
*
* \param pace pace of the fade out
*
* \param deact true: deactivate the dst FIFO when fade out completed \n
*              false: Do not deactivate the dst FIFO when fade out completed
*
* \return None.
*
* \funcusage
* \snippet mixer/snippet/main.c snippet_Cy_Mixer_DestinationStartFadeOut
*
*******************************************************************************/
void Cy_Mixer_DestinationStartFadeOut(volatile MIXER_DST_STRUCT_Type * base, uint16_t pace, bool deact)
{
    if (NULL != base)
    {
        MIXER_DST_STRUCT_DST_FADE_CMD(base) = _VAL2FLD(MIXER_MIXER_DST_STRUCT_DST_FADE_CMD_PACE, pace) |
                                              _VAL2FLD(MIXER_MIXER_DST_STRUCT_DST_FADE_CMD_AUTO_DEACTIVATE, deact == false ? 0UL : 1UL) |
                                              MIXER_MIXER_DST_STRUCT_DST_FADE_CMD_FADE_OUT_Msk;
    }
}

/*******************************************************************************
* Function Name: Cy_Mixer_DestinationHasFadeOutCompleted
****************************************************************************//**
*
* \brief checks previous fade out operation already completed or not
*
* \param base Pointer to the Mixer DST Struct instance.
*
* \return true : Previous fade out operation already completed \n
*         false: Previous fade out operation still in progress
*
* \funcusage
* \snippet mixer/snippet/main.c snippet_Cy_Mixer_DestinationStartFadeOut
*
*******************************************************************************/
bool Cy_Mixer_DestinationHasFadeOutCompleted(volatile MIXER_DST_STRUCT_Type * base)
{
    return (0UL == _FLD2VAL(MIXER_MIXER_DST_STRUCT_DST_FADE_CMD_FADE_OUT, MIXER_DST_STRUCT_DST_FADE_CMD(base)));
}

#if (defined(MIXER0_TX_PRESENT) && (MIXER0_TX_PRESENT == 1)) || (defined(MIXER1_TX_PRESENT) && (MIXER1_TX_PRESENT == 1))
/*******************************************************************************
* Function Name: Cy_Mixer_TransmitInit
****************************************************************************//**
* \brief
* Initializes the Mixer transmit structure.
*
* \param base Pointer to the Mixer TX Struct instance.
* \param config The pointer to a configuration structure.
*
* \return error / status code. See \ref cy_en_mixer_status_t.
*
* \funcusage
* \snippet mixer/snippet/main.c snippet_Cy_Mixer_TransmitInit
*
*******************************************************************************/
cy_en_mixer_status_t Cy_Mixer_TransmitInit(volatile MIXER_TX_STRUCT_Type * base, cy_stc_mixer_tx_config_t const * config)
{
    cy_en_mixer_status_t mxStatus = CY_MIXER_BAD_PARAM;

    if ((NULL != base) && (NULL != config))
    {
        MIXER_TX_STRUCT_TX_CTL(base) = _VAL2FLD(MIXER_MIXER_TX_STRUCT_TX_CTL_WORD_SIZE, config->wordSize) |
                                       _VAL2FLD(MIXER_MIXER_TX_STRUCT_TX_CTL_FORMAT, config->txFormat)    |
                                       _VAL2FLD(MIXER_MIXER_TX_STRUCT_TX_CTL_MS, config->txMode);

        MIXER_TX_STRUCT_TX_IF_CTL(base) = _VAL2FLD(MIXER_MIXER_TX_STRUCT_TX_IF_CTL_CLOCK_DIV, config->clkDiv) |
                                          _VAL2FLD(MIXER_MIXER_TX_STRUCT_TX_IF_CTL_CLOCK_SEL, config->clkSel) |
                                          (config->clkPol == true ? MIXER_MIXER_TX_STRUCT_TX_IF_CTL_SCK_POLARITY_Msk : 0UL) |
                                          (config->wSelPol == true ? MIXER_MIXER_TX_STRUCT_TX_IF_CTL_WS_POLARITY_Msk : 0UL) |
                                          (config->chl0En == true ? MIXER_MIXER_TX_STRUCT_TX_IF_CTL_CH0_EN_Msk : 0UL) |
                                          (config->chl1En == true ? MIXER_MIXER_TX_STRUCT_TX_IF_CTL_CH1_EN_Msk : 0UL) |
                                          _VAL2FLD(MIXER_MIXER_TX_STRUCT_TX_IF_CTL_CH_SIZE, chSize);

        mxStatus = CY_MIXER_SUCCESS;
    }

    return mxStatus;
}

/*******************************************************************************
* Function Name: Cy_Mixer_TransmitDeInit
****************************************************************************//**
* \brief
* DeInitializes the Mixer transmit structure.
*
* \param base Pointer to the Mixer TX Struct instance.
*
* \return error / status code. See \ref cy_en_mixer_status_t.
*
* \funcusage
* \snippet mixer/snippet/main.c snippet_Cy_Mixer_TransmitDeInit
*
*******************************************************************************/
void Cy_Mixer_TransmitDeInit(volatile MIXER_TX_STRUCT_Type * base)
{
    if (NULL != base)
    {
        MIXER_TX_STRUCT_TX_CTL(base) = 0UL;
        MIXER_TX_STRUCT_TX_IF_CTL(base) = 0UL;
    }
}

#endif /* (defined(MIXER0_TX_PRESENT) && (MIXER0_TX_PRESENT == 1)) || (defined(MIXER1_TX_PRESENT) && (MIXER1_TX_PRESENT == 1)) */

#if defined(__cplusplus)
}
#endif /* __cplusplus */

#endif /* CY_IP_MXMIXER */

/* [] END OF FILE */
