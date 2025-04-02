/***************************************************************************//**
* \file cy_tcpwm_motif.c
* \version 1.80
*
* \brief
*  The source file of the tcpwm motif driver.
*
********************************************************************************
* \copyright
* Copyright 2023-2024 Cypress Semiconductor Corporation (an Infineon company) or
* an affiliate of Cypress Semiconductor Corporation.
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

#include "cy_tcpwm_motif.h"

#ifdef CY_IP_MXTCPWM

#if defined (CY_IP_MXS40TCPWM)
#if defined(__cplusplus)
extern "C" {
#endif


/******************************************************************************
* Function Name: Cy_TCPWM_MOTIF_Hall_Sensor_Init
***************************************************************************//**
*
* MOTIF module initialization in Hall sensor Mode
*
*******************************************************************************/
cy_en_tcpwm_status_t Cy_TCPWM_MOTIF_Hall_Sensor_Init(TCPWM_MOTIF_GRP_MOTIF_Type *base, cy_stc_tcpwm_motif_hall_sensor_config_t const *config)
{
    cy_en_tcpwm_status_t status = CY_TCPWM_BAD_PARAM;
    /* The Hall Sensor mode is divided in three major loops:
     * detection of an update in the Hall inputs,
     * delay between the detection and the sampling of the Hall inputs for comparison against the expected
     * Hall Pattern and the update of the Multi-Channel pattern. */

    if ((NULL != base) && (NULL != config))
    {
        TCPWM_MOTIF_PCONF(base) = (_VAL2FLD(TCPWM_MOTIF_GRP_MOTIF_PCONF_FSEL, CY_MOTIF_HALL_SENSOR_MODE) |
                                  _VAL2FLD(TCPWM_MOTIF_GRP_MOTIF_PCONF_SPES, config->edge_for_sampling_trigger) |
                                  _VAL2FLD(TCPWM_MOTIF_GRP_MOTIF_PCONF_LPC, config->low_pass_filter_config) |
                                  _VAL2FLD(TCPWM_MOTIF_GRP_MOTIF_PCONF_MSES, config->edge_for_mset_trigger) |
                                  _VAL2FLD(TCPWM_MOTIF_GRP_MOTIF_PCONF_MSYES, config->edge_for_msync_trigger) |
                                  _VAL2FLD(TCPWM_MOTIF_GRP_MOTIF_PCONF_MCUE, config->mcp_mode) |
                                  _VAL2FLD(TCPWM_MOTIF_GRP_MOTIF_PCONF_EWIE, config->external_wrong_hall_event_enable) |
                                  _VAL2FLD(TCPWM_MOTIF_GRP_MOTIF_PCONF_EWIL, config->external_wrong_hall_event_active_level) |
                                  _VAL2FLD(TCPWM_MOTIF_GRP_MOTIF_PCONF_FTS, config->fault_event_selection) |
                                  _VAL2FLD(TCPWM_MOTIF_GRP_MOTIF_PCONF_CHEC, config->correct_event_selection) |
                                  _VAL2FLD(TCPWM_MOTIF_GRP_MOTIF_PCONF_ENABLE, 1U));

        TCPWM_MOTIF_HMEC(base)  = (_VAL2FLD(TCPWM_MOTIF_GRP_MOTIF_HMEC_HDBP, config->debounce_bypass) |
                                   _VAL2FLD(TCPWM_MOTIF_GRP_MOTIF_HMEC_HPPE, config->pp_compare));
        TCPWM_MOTIF_MCMEC(base) = (_VAL2FLD(TCPWM_MOTIF_GRP_MOTIF_MCMEC_MSBP, config->sync_bypass) |
                                   _VAL2FLD(TCPWM_MOTIF_GRP_MOTIF_MCMEC_MFCE, config->fault_clear) |
                                   _VAL2FLD(TCPWM_MOTIF_GRP_MOTIF_MCMEC_MEBP, config->delay_bypass));
        if(config->output_config != NULL)
        {
            TCPWM_MOTIF_HOSC(base) = (_VAL2FLD(TCPWM_MOTIF_GRP_MOTIF_HOSC_EDN,  config->output_config->edge_detect_event_config)        |
                                      _VAL2FLD(TCPWM_MOTIF_GRP_MOTIF_HOSC_CHN,  config->output_config->correct_hall_event_config)       |
                                      _VAL2FLD(TCPWM_MOTIF_GRP_MOTIF_HOSC_IDN,  config->output_config->idle_wrong_hall_event_config)    |
                                      _VAL2FLD(TCPWM_MOTIF_GRP_MOTIF_HOSC_HSTN, config->output_config->start_event_config)              |
                                      _VAL2FLD(TCPWM_MOTIF_GRP_MOTIF_HOSC_SPN,  config->output_config->pattern_mismatch_event_config)   |
                                      _VAL2FLD(TCPWM_MOTIF_GRP_MOTIF_HOSC_CPN,  config->output_config->curr_pattern_match_event_config) |
                                      _VAL2FLD(TCPWM_MOTIF_GRP_MOTIF_HOSC_PPN,  config->output_config->prev_pattern_match_event_config));
        }
        /* Each MOTIF module contains two LUT's(Look Up Tables). Hall LUT (HLUT, also called "input LUT") and Modulation LUT (MLUT, also called  "output LUT").
         HLUT contains Hall input pattern which gets loaded to HALP registers.
         MLUT contains output PWM modulation pattern which gets loaded to MCM.MCMP register.
         HLUT is 3x6 bits. MLUT is 32x6 bits
         */
        if (config->lut_enable)
        {
            TCPWM_MOTIF_CLUT(base) &= ~TCPWM_MOTIF_GRP_MOTIF_CLUT_LUTEN_Msk;
            TCPWM_MOTIF_CLUT(base) |= (_VAL2FLD(TCPWM_MOTIF_GRP_MOTIF_CLUT_LUTEN, config->lut_enable));

            if (NULL != config->hlut_config)
            {
                TCPWM_MOTIF_HALPS(base)   = (_VAL2FLD(TCPWM_MOTIF_GRP_MOTIF_HALPS_HCPS0, config->hlut_config->hlut_data_pos0) |
                                             _VAL2FLD(TCPWM_MOTIF_GRP_MOTIF_HALPS_HEPS1, config->hlut_config->hlut_data_pos1) |
                                             _VAL2FLD(TCPWM_MOTIF_GRP_MOTIF_HALPS_HPPS2, config->hlut_config->hlut_data_pos2) |
                                             _VAL2FLD(TCPWM_MOTIF_GRP_MOTIF_HALPS_HLUT3, config->hlut_config->hlut_data_pos3) |
                                             _VAL2FLD(TCPWM_MOTIF_GRP_MOTIF_HALPS_HLUT4, config->hlut_config->hlut_data_pos4) |
                                             _VAL2FLD(TCPWM_MOTIF_GRP_MOTIF_HALPS_HLUT5, config->hlut_config->hlut_data_pos5));
            }
            if (NULL != config->mlut_config)
            {
                TCPWM_MOTIF_MCSM(base)   = (_VAL2FLD(TCPWM_MOTIF_GRP_MOTIF_MCSM_MCMPS, config->mlut_config->mlut_data_pos0));
                TCPWM_MOTIF_MCSM1(base)  = (_VAL2FLD(TCPWM_MOTIF_GRP_MOTIF_MCSM_MCMPS, config->mlut_config->mlut_data_pos1));
                TCPWM_MOTIF_MCSM2(base)  = (_VAL2FLD(TCPWM_MOTIF_GRP_MOTIF_MCSM_MCMPS, config->mlut_config->mlut_data_pos2));
                TCPWM_MOTIF_MCSM3(base)  = (_VAL2FLD(TCPWM_MOTIF_GRP_MOTIF_MCSM_MCMPS, config->mlut_config->mlut_data_pos3));
                TCPWM_MOTIF_MCSM4(base)  = (_VAL2FLD(TCPWM_MOTIF_GRP_MOTIF_MCSM_MCMPS, config->mlut_config->mlut_data_pos4));
                TCPWM_MOTIF_MCSM5(base)  = (_VAL2FLD(TCPWM_MOTIF_GRP_MOTIF_MCSM_MCMPS, config->mlut_config->mlut_data_pos5));
            }
        }

        /* The Hall inputs are directly connected to an edge detection circuitry and with any modification in any of these three inputs, an event is generated.
        This event can be connected to one TCPWM counter via trigger multiplexer that is controlling the delay between the edge detection and the next step on the Hall sensor mode, the sampling of the Hall Inputs.
        */
        status = CY_TCPWM_SUCCESS;
    }
    return(status);
}

/******************************************************************************
* Function Name: Cy_TCPWM_MOTIF_MCP_Init
***************************************************************************//**
*
* MOTIF module initialization in Multi Channel Pattern Mode
*
******************************************************************************/
cy_en_tcpwm_status_t Cy_TCPWM_MOTIF_MCP_Init(TCPWM_MOTIF_GRP_MOTIF_Type *base, cy_stc_tcpwm_motif_mcp_config_t const *mcp_config)
{
    cy_en_tcpwm_status_t status = CY_TCPWM_BAD_PARAM;

    if ((NULL != base) && (NULL != mcp_config))
    {
        TCPWM_MOTIF_PCONF(base) = (_VAL2FLD(TCPWM_MOTIF_GRP_MOTIF_PCONF_FSEL, CY_MOTIF_STANDALONE_MULTICHANNEL_MODE) |
                                  _VAL2FLD(TCPWM_MOTIF_GRP_MOTIF_PCONF_MSES, mcp_config->edge_for_mset_trigger) |
                                  _VAL2FLD(TCPWM_MOTIF_GRP_MOTIF_PCONF_MSYES, mcp_config->edge_for_msync_trigger) |
                                  _VAL2FLD(TCPWM_MOTIF_GRP_MOTIF_PCONF_MCUE, mcp_config->mcp_mode) |
                                  _VAL2FLD(TCPWM_MOTIF_GRP_MOTIF_PCONF_ENABLE, 1U));
        TCPWM_MOTIF_MCMEC(base) = (_VAL2FLD(TCPWM_MOTIF_GRP_MOTIF_MCMEC_MSBP, mcp_config->sync_bypass));

        if (NULL != mcp_config->output_config)
        {
            TCPWM_MOTIF_MOSC(base)  = (_VAL2FLD(TCPWM_MOTIF_GRP_MOTIF_MOSC_PUN,  mcp_config->output_config->pattern_update_event_config)  |
                                        _VAL2FLD(TCPWM_MOTIF_GRP_MOTIF_MOSC_SHN,  mcp_config->output_config->update_sync_event_config)     |
                                        _VAL2FLD(TCPWM_MOTIF_GRP_MOTIF_MOSC_MSTN, mcp_config->output_config->start_event_config));
        }

        if (mcp_config->lut_enable)
        {
            CY_REG32_CLR_SET(TCPWM_MOTIF_CLUT(base), TCPWM_MOTIF_GRP_MOTIF_CLUT_LUTEN, mcp_config->lut_enable);

            if (NULL != mcp_config->mlut_config)
            {
                TCPWM_MOTIF_MCSM(base)  = (_VAL2FLD(TCPWM_MOTIF_GRP_MOTIF_MCSM_MCMPS, mcp_config->mlut_config->mlut_data_pos0));
                TCPWM_MOTIF_MCSM1(base) = (_VAL2FLD(TCPWM_MOTIF_GRP_MOTIF_MCSM_MCMPS, mcp_config->mlut_config->mlut_data_pos1));
                TCPWM_MOTIF_MCSM2(base) = (_VAL2FLD(TCPWM_MOTIF_GRP_MOTIF_MCSM_MCMPS, mcp_config->mlut_config->mlut_data_pos2));
                TCPWM_MOTIF_MCSM3(base) = (_VAL2FLD(TCPWM_MOTIF_GRP_MOTIF_MCSM_MCMPS, mcp_config->mlut_config->mlut_data_pos3));
                TCPWM_MOTIF_MCSM4(base) = (_VAL2FLD(TCPWM_MOTIF_GRP_MOTIF_MCSM_MCMPS, mcp_config->mlut_config->mlut_data_pos4));
                TCPWM_MOTIF_MCSM5(base) = (_VAL2FLD(TCPWM_MOTIF_GRP_MOTIF_MCSM_MCMPS, mcp_config->mlut_config->mlut_data_pos5));
            }
        }

        status = CY_TCPWM_SUCCESS;
    }
    return(status);
}

/******************************************************************************
* Function Name: Cy_TCPWM_MOTIF_Update_MLUT
***************************************************************************//**
*
* Update look up table for multi channel pattern MLUT mode
*
* Note: Update look up table for multi channel pattern MLUT
*   User writes HLUT and MLUT when MOTIF is stopped.
*   Writing into both LUT while MOTIF is started might lead to incorrect behavior.
*   The LUT is loaded with forward or reverse pattern depending on motor desired direction.
*   The pattern is stored in LUT independently from motor position.
*   The hardware is responsible to find out the current motor position and to load the right hall and modulation pattern.
*   HLUT and MLUT share the same hardware pointer for data extraction, therefore user needs to take care of keeping them aligned with respect to LUT address.
*   A wrong programming might lead to incorrect behavior.
******************************************************************************/
void Cy_TCPWM_MOTIF_Update_MLUT(TCPWM_MOTIF_GRP_MOTIF_Type *base, cy_stc_tcpwm_motif_mlut_t *mlut_config)
{
    CY_ASSERT_L1(NULL != base);
    CY_ASSERT_L1(NULL != mlut_config);

    TCPWM_MOTIF_MCSM(base)  = (_VAL2FLD(TCPWM_MOTIF_GRP_MOTIF_MCSM_MCMPS, mlut_config->mlut_data_pos0));
    TCPWM_MOTIF_MCSM1(base) = (_VAL2FLD(TCPWM_MOTIF_GRP_MOTIF_MCSM_MCMPS, mlut_config->mlut_data_pos1));
    TCPWM_MOTIF_MCSM2(base) = (_VAL2FLD(TCPWM_MOTIF_GRP_MOTIF_MCSM_MCMPS, mlut_config->mlut_data_pos2));
    TCPWM_MOTIF_MCSM3(base) = (_VAL2FLD(TCPWM_MOTIF_GRP_MOTIF_MCSM_MCMPS, mlut_config->mlut_data_pos3));
    TCPWM_MOTIF_MCSM4(base) = (_VAL2FLD(TCPWM_MOTIF_GRP_MOTIF_MCSM_MCMPS, mlut_config->mlut_data_pos4));
    TCPWM_MOTIF_MCSM5(base) = (_VAL2FLD(TCPWM_MOTIF_GRP_MOTIF_MCSM_MCMPS, mlut_config->mlut_data_pos5));
}

/******************************************************************************
* Function Name: Cy_TCPWM_MOTIF_Quaddec_Init
***************************************************************************//**
*
* MOTIF module initialization in Quadrature Decoder Mode
*
******************************************************************************/
cy_en_tcpwm_status_t Cy_TCPWM_MOTIF_Quaddec_Init(TCPWM_MOTIF_GRP_MOTIF_Type *base, cy_stc_tcpwm_motif_quaddec_config_t const *config)
{
    cy_en_tcpwm_status_t status = CY_TCPWM_BAD_PARAM;

    if ((NULL != base) && (NULL != config))
    {
        TCPWM_MOTIF_PCONF(base) = (_VAL2FLD(TCPWM_MOTIF_GRP_MOTIF_PCONF_FSEL, CY_MOTIF_QUAD_DECODER_MODE)    |
                                   _VAL2FLD(TCPWM_MOTIF_GRP_MOTIF_PCONF_QDCM, config->position_decoder_mode) |
                                   _VAL2FLD(TCPWM_MOTIF_GRP_MOTIF_PCONF_LPC, config->low_pass_filter_config) |
                                   _VAL2FLD(TCPWM_MOTIF_GRP_MOTIF_PCONF_ENABLE, 1U));

        if(config->output_config != NULL)
        {

            TCPWM_MOTIF_QOSC(base)  = (_VAL2FLD(TCPWM_MOTIF_GRP_MOTIF_QOSC_QCN,  config->output_config->clock_event_config)         |
                                       _VAL2FLD(TCPWM_MOTIF_GRP_MOTIF_QOSC_DON,  config->output_config->direction_event_config)     |
                                       _VAL2FLD(TCPWM_MOTIF_GRP_MOTIF_QOSC_PCN,  config->output_config->period_clock_event_config)  |
                                       _VAL2FLD(TCPWM_MOTIF_GRP_MOTIF_QOSC_CCN,  config->output_config->clear_capture_event_config) |
                                       _VAL2FLD(TCPWM_MOTIF_GRP_MOTIF_QOSC_IXN,  config->output_config->index_event_config)         |
                                       _VAL2FLD(TCPWM_MOTIF_GRP_MOTIF_QOSC_QSTN, config->output_config->start_event_config));
        }

        if(config->position_decoder_mode == CY_MOTIF_PD_QUAD_MODE)
        {
            TCPWM_MOTIF_QDC(base) = (_VAL2FLD(TCPWM_MOTIF_GRP_MOTIF_QDC_PALS, config->phase_A_level_selector)      |
                                     _VAL2FLD(TCPWM_MOTIF_GRP_MOTIF_QDC_PBLS, config->phase_B_level_selector)      |
                                     _VAL2FLD(TCPWM_MOTIF_GRP_MOTIF_QDC_INDS, config->index_signal_level_selector) |
                                     _VAL2FLD(TCPWM_MOTIF_GRP_MOTIF_QDC_PACS, config->clock_signal_for_phase_A)    |
                                     _VAL2FLD(TCPWM_MOTIF_GRP_MOTIF_QDC_PBDS, config->clock_signal_for_phase_B)    |
                                     _VAL2FLD(TCPWM_MOTIF_GRP_MOTIF_QDC_IDS, config->clock_signal_for_index)       |
                                     _VAL2FLD(TCPWM_MOTIF_GRP_MOTIF_QDC_PHS, config->phase_signal_swap)            |
                                     _VAL2FLD(TCPWM_MOTIF_GRP_MOTIF_QDC_PAEM, config->phae_A_edge_mode)            |
                                     _VAL2FLD(TCPWM_MOTIF_GRP_MOTIF_QDC_PBEM, config->phae_B_edge_mode)            |
                                     _VAL2FLD(TCPWM_MOTIF_GRP_MOTIF_QDC_ICM, config->progindex_occurrence));
        }
        else
        {
            TCPWM_MOTIF_QDC(base) = (_VAL2FLD(TCPWM_MOTIF_GRP_MOTIF_QDC_PALS, config->phase_A_level_selector)   |
                                     _VAL2FLD(TCPWM_MOTIF_GRP_MOTIF_QDC_PBLS, config->phase_B_level_selector)   |
                                     _VAL2FLD(TCPWM_MOTIF_GRP_MOTIF_QDC_PACS, config->clock_signal_for_phase_A) |
                                     _VAL2FLD(TCPWM_MOTIF_GRP_MOTIF_QDC_PBDS, config->clock_signal_for_phase_B) |
                                      _VAL2FLD(TCPWM_MOTIF_GRP_MOTIF_QDC_PHS, config->phase_signal_swap)        |
                                     _VAL2FLD(TCPWM_MOTIF_GRP_MOTIF_QDC_PAEM, config->phae_A_edge_mode)         |
                                     _VAL2FLD(TCPWM_MOTIF_GRP_MOTIF_QDC_PBEM, config->phae_B_edge_mode));

        }


        status = CY_TCPWM_SUCCESS;
    }

    return(status);
}

/******************************************************************************
* Function Name: Cy_TCPWM_MOTIF_MCP_Quaddec_Init
***************************************************************************//**
*
* MOTIF module initialization in Quadrature Decoder Mode and Multi Channel Pattern mode.
*
******************************************************************************/
cy_en_tcpwm_status_t Cy_TCPWM_MOTIF_MCP_Quaddec_Init(TCPWM_MOTIF_GRP_MOTIF_Type *base, cy_stc_tcpwm_motif_mcp_quaddec_config_t const *mcp_quad_config)
{
    cy_en_tcpwm_status_t status = CY_TCPWM_BAD_PARAM;

    if ((NULL != base) && (NULL != mcp_quad_config))
    {
        if(NULL != mcp_quad_config->mcp_config)
        {
            /* Configure Multichannel pattern mode */
            status = Cy_TCPWM_MOTIF_MCP_Init(base, mcp_quad_config->mcp_config);

            if((status == CY_TCPWM_SUCCESS) && (NULL != mcp_quad_config->quaddec_config))
            {
                /* Configure Multichannel pattern mode */
                status = Cy_TCPWM_MOTIF_Quaddec_Init(base, mcp_quad_config->quaddec_config);
            }
        }
        if(status == CY_TCPWM_SUCCESS)
        {
            CY_REG32_CLR_SET(TCPWM_MOTIF_PCONF(base), TCPWM_MOTIF_GRP_MOTIF_PCONF_FSEL, CY_MOTIF_SAMC_QD_MODE);
        }

    }

    return(status);
}

/******************************************************************************
* Function Name: Cy_TCPWM_MOTIF_Get_Lowpass_Filter_Status
***************************************************************************//**
*
* Returns the status of the low pass filter.
*
******************************************************************************/
uint16_t Cy_TCPWM_MOTIF_Get_Lowpass_Filter_Status(TCPWM_MOTIF_GRP_MOTIF_Type *base, cy_en_low_pass_filter_number_t lowpass_filter)
{
    CY_ASSERT_L1(NULL != base);

    uint16_t filter_status = 0;

    switch(lowpass_filter)
    {
        case CY_LOW_PASS_FILTER_0:
        {
            filter_status = (uint16_t) (_FLD2VAL(TCPWM_MOTIF_GRP_MOTIF_PLP0S_LPP0, TCPWM_MOTIF_PLP0S(base)));
            break;
        }
        case CY_LOW_PASS_FILTER_1:
        {
            filter_status = (uint16_t) (_FLD2VAL(TCPWM_MOTIF_GRP_MOTIF_PLP1S_LPP1, TCPWM_MOTIF_PLP1S(base)));
            break;
        }
        case CY_LOW_PASS_FILTER_2:
        {
            filter_status = (uint16_t) (_FLD2VAL(TCPWM_MOTIF_GRP_MOTIF_PLP2S_LPP2, TCPWM_MOTIF_PLP2S(base)));
            break;
        }
        default:
            filter_status = 0;
        break;
    }

    return filter_status;
}


#if defined(__cplusplus)
}
#endif
#endif /*defined (CY_IP_MXS40TCPWM)*/
#endif /* CY_IP_MXTCPWM */

/* [] END OF FILE */
