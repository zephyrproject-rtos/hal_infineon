/***************************************************************************//**
* \file cy_usbpd_mux.c
* \version 2.110
*
* Provides implementation of MUX control functions for the USBPD IP.
*
********************************************************************************
* \copyright
* (c) (2022 - 2025), Cypress Semiconductor Corporation (an Infineon company) or
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

#include "cy_device.h"
#include "cy_device_headers.h"

#if (defined(CY_IP_MXUSBPD) || defined(CY_IP_M0S8USBPD))

#include "cy_usbpd_common.h"
#include "cy_usbpd_mux.h"
#if defined(CY_DEVICE_PMG1S3)
#include "cy_gpio.h"
#endif /* CY_DEVICE_PMG1S3 */

/*******************************************************************************
* Function Name: Cy_USBPD_Mux_ConfigDpDm
****************************************************************************//**
*
* This function configures the Dp/Dm MUX.
*
* \param context
* USBPD PDL Context pointer.
*
* \param conf
* DP/DM MUX Configuration
*
* \return
*  cy_en_usbpd_status_t 
*
*******************************************************************************/
cy_en_usbpd_status_t Cy_USBPD_Mux_ConfigDpDm(cy_stc_usbpd_context_t *context, cy_en_usbpd_dpdm_mux_cfg_t conf)
{
#if defined(CY_DEVICE_CCG6)    
    PPDSS_REGS_T pd = context->base;

    /* Do nothing if the configuration is already correct. */
    if (context->curDpdmCfg == conf)
    {
        return CY_USBPD_STAT_SUCCESS;
    }
    context->curDpdmCfg = conf;

    if (conf == CY_USBPD_DPDM_MUX_CONN_NONE)
    {
        /* Disable pump first. PUMP[3] is for Port 0 */
        Cy_USBPD_Pump_Disable (context, (uint8_t)(2U));
        
        Cy_SysLib_DelayUs(2);

        /* Turn off all switches and isolate outputs. */
        pd->dpdm_ctrl &=
                        (
                        (PDSS_DPDM_CTRL_DPDM_T_DPDM_MASK) |
                        (PDSS_DPDM_CTRL_DCP_SHORT_DPDM_TOP |
                         PDSS_DPDM_CTRL_DCP_SHORT_DPDM_BOTTOM)
                        );
    }
    else
    {
        /* Enable the output switch and configure required bits. */
        pd->dpdm_ctrl = (pd->dpdm_ctrl & PDSS_DPDM_CTRL_DPDM_T_DPDM_MASK) |
            ((uint32_t)conf | PDSS_DPDM_CTRL_DPDM_ISO_N);
        Cy_SysLib_DelayUs(2);

        /* Now enable pump for slow ramp of signals. */
        Cy_USBPD_Pump_Enable (context, (uint8_t)(2U));
    }
    return CY_USBPD_STAT_SUCCESS;
#else
    CY_UNUSED_PARAMETER(context);
    CY_UNUSED_PARAMETER(conf);
    return CY_USBPD_STAT_NOT_SUPPORTED;
#endif /* defined(CY_DEVICE_CCG6) */
}

#if defined(CY_DEVICE_PMG1S3)
/*******************************************************************************
* Function Name: Cy_USBPD_Mux_ConfigDebugGpio
****************************************************************************//**
*
* This function configures DBG GPIO for CCG8/S devices.
**
*
* \param port
* Selected Type-C port
*
* \param sbuState
* SBU switch state
*
* \return
*  None
*
*******************************************************************************/
static void Cy_USBPD_Mux_ConfigDebugGpio(uint8_t port, cy_en_usbpd_sbu_switch_state_t sbuState)
{
#if !PMG1_PD_DUALPORT_ENABLE
    (void) port;
#endif /* !PMG1_PD_DUALPORT_ENABLE */

    if (sbuState == CY_USBPD_SBU_CONNECT_DBG1)
    {
        /* Configure DBG1 GPIO */
#if PMG1_PD_DUALPORT_ENABLE
        if (port == TYPEC_PORT_0_IDX)
        {
            Cy_GPIO_Pin_FastInit(GPIO_PRT0, (0x05UL & 0x0FUL), CY_GPIO_DM_PULLUP_DOWN, 0, HSIOM_SEL_DS_0);
        }
        else
#endif /* PMG1_PD_DUALPORT_ENABLE */
        {
            Cy_GPIO_Pin_FastInit(GPIO_PRT0, (0x02UL & 0x0FUL), CY_GPIO_DM_PULLUP_DOWN, 0, HSIOM_SEL_DS_0);
        }
    }
    else if (sbuState == CY_USBPD_SBU_CONNECT_DBG2)
    {
#if PMG1_PD_DUALPORT_ENABLE
        if (port == TYPEC_PORT_0_IDX)
        {
            Cy_GPIO_Pin_FastInit(GPIO_PRT0, (0x04UL & 0x0FUL), CY_GPIO_DM_PULLUP_DOWN, 0, HSIOM_SEL_DS_0);
        }
        else
#endif /* PMG1_PD_DUALPORT_ENABLE */
        {
            Cy_GPIO_Pin_FastInit(GPIO_PRT0, (0x03UL & 0x0FUL), CY_GPIO_DM_PULLUP_DOWN, 0, HSIOM_SEL_DS_0);
        }
    }
    else
    {
        /* Nothing to handle */
    }
}
#endif /* CY_DEVICE_PMG1S3 */

#if defined(CY_DEVICE_CCG6DF_CFP)
/*******************************************************************************
* Function Name: Cy_USBPD_Mux_FuncModeEn
****************************************************************************//**
*
* This function enables functional mode (FW controlled) for SBU configuration.
**
*
* \param context
* USBPD PDL Context pointer.
*
* \param enable
* Enable/disable functional mode (FW controlled) for SBU configuration.
*
* \return
*  cy_en_usbpd_status_t CY_USBPD_STAT_SUCCESS if enabling/disabling can be provided,
*  CY_USBPD_STAT_NOT_READY if SBU configuration FSM is already in progress,
*  CY_USBPD_STAT_INVALID_ARGUMENT is requested mode is already enabled/disabled.
*
*******************************************************************************/
cy_en_usbpd_status_t Cy_USBPD_Mux_FuncModeEnDis(cy_stc_usbpd_context_t *context, bool enable)
{
    cy_en_usbpd_status_t ret = CY_USBPD_STAT_NOT_READY;
    uint32_t intstate, regIndexDbg, sbuClipperCtrl, siliconId = SFLASH_SILICON_ID & 0xFFFFUL;
    PPDSS_REGS_T pd = context->base;
    PPDSS_REGS_T pdDbg = pd;

    /* Workaround for CCG6SF_CFP and CCG8SF_CFP silicon to use registers for port 1 to control SBU. */
    if (
           (siliconId == 0x3E00UL) ||
           (siliconId == 0x3E01UL) ||
           (siliconId == 0x3E80UL)
       )
    {
        pdDbg = (PPDSS_REGS_T)PDSS1_BASE_ADDR;
    }

    /*
     * Check if SBU<->DBG connection is already in the requested state by tracking
     * FSM_CURR_STATE value in HW_SBU_STATUS register where
     * 0x00 - indicates that SBU sequencer FSM is in disconnected state
     * 0x07 - indicates that SBU sequencer FSM is in connected state
     */
    if (
           (((pdDbg->hw_sbu_status & PDSS_HW_SBU_STATUS_FSM_CURR_STATE_MASK) == 0x00UL) && (enable == false)) ||
           (((pdDbg->hw_sbu_status & PDSS_HW_SBU_STATUS_FSM_CURR_STATE_MASK) == 0x07UL) && (enable))
        )
    {
        return CY_USBPD_STAT_INVALID_ARGUMENT;
    }

    intstate = Cy_SysLib_EnterCriticalSection();

    /* Change OVP threshold before disable */
    if (enable == false)
    {
        /* OVP set to 3.3V then SBU-DBG connection has to be disabled */
        regIndexDbg = pdDbg->pd_sbu_hres_ctrl;
        regIndexDbg &= ~(PDSS_PD_SBU_HRES_CTRL_IN2_OUT1_EN | PDSS_PD_SBU_HRES_CTRL_IN2_OUT2_EN |
             PDSS_PD_SBU_HRES_CTRL_IN1_OUT1_EN | PDSS_PD_SBU_HRES_CTRL_IN1_OUT2_EN);
        pdDbg->pd_sbu_hres_ctrl = regIndexDbg;

        /* Set 3.3 volt OVP threshold for AUXP/AUXN/LSTX/LSRX/None connection */
        sbuClipperCtrl = pd->pd_30sbu_clipper_ctrl;
        sbuClipperCtrl |= PDSS_PD_30SBU_CLIPPER_CTRL_DET_LEVEL_CTRL;

        /* Set SBU clipper */
        pd->pd_30sbu_clipper_ctrl     = sbuClipperCtrl;
        /* Wait to apply new OVP threshold */
        Cy_SysLib_DelayUs(2);
    }

    /* Enable SBU<->DBG connection if disabled */
    if ((enable) && ((pdDbg->hw_sbu_status & PDSS_HW_SBU_STATUS_FSM_CURR_STATE_MASK) == 0x00UL))
    {
        pdDbg->hw_sbu_ctrl_1 |= PDSS_HW_SBU_CTRL_1_SBU_DBG_EN;
        ret = CY_USBPD_STAT_SUCCESS;
    }
    else if ((!enable) && ((pdDbg->hw_sbu_status & PDSS_HW_SBU_STATUS_FSM_CURR_STATE_MASK) == 0x07UL))
    {
        pdDbg->hw_sbu_ctrl_1 &= ~PDSS_HW_SBU_CTRL_1_SBU_DBG_EN;
        ret = CY_USBPD_STAT_SUCCESS;
    }

    Cy_SysLib_ExitCriticalSection(intstate);

    return ret;
}

/*******************************************************************************
* Function Name: Cy_USBPD_Mux_SetLsTxDir
****************************************************************************//**
*
* This function configures LSTX direction.
*
* \param context
* USBPD PDL Context pointer.
*
* \param tx_mode
* True - transmitter mode (Data from SBU1/2 to LXTX)
* False - receiver mode (Data from LSTX to SBU1/2).
*
* \return
*  None
*
*******************************************************************************/
void Cy_USBPD_Mux_SetLsTxDir(cy_stc_usbpd_context_t *context, bool tx_mode)
{
    uint32_t intstate, regIndexLs;
    PPDSS_REGS_T pd = context->base;

    intstate = Cy_SysLib_EnterCriticalSection();

    regIndexLs = pd->pd_sbu_ls_ctrl_0;

    /* Set receiver mode by default.  */
    regIndexLs &= ~PDSS_PD_SBU_LS_CTRL_0_DIR_LSTX;
    /* Set transmitter mode if required.  */
    if (tx_mode)
    {
        regIndexLs |= PDSS_PD_SBU_LS_CTRL_0_DIR_LSTX;
    }

    /* Set LSTX direction. */
    pd->pd_sbu_ls_ctrl_0 = regIndexLs;

    Cy_SysLib_ExitCriticalSection(intstate);
}

/*******************************************************************************
* Function Name: Cy_USBPD_Mux_LsTermConfigure
****************************************************************************//**
*
* This function enables/disables 10KOhm Pullup resistor for LSTX and
* 1M0hm Pulldown resistor for LSRX
*
* \param context
* USBPD PDL Context pointer.
*
* \param lsTxTermEn
* Enable/disable LSTX 10KOhm Pullup resistor.
*
* \param lsRxTermEn
* Enable/disable LSRX 1M0hm Pulldown resistor.
*
* \return
*  cy_en_usbpd_status_t
*
*******************************************************************************/
cy_en_usbpd_status_t Cy_USBPD_Mux_LsTermConfigure(cy_stc_usbpd_context_t *context, bool lsTxTermEn, bool lsRxTermEn)
{
    PPDSS_REGS_T pd = context->base;

    uint32_t intstate  = Cy_SysLib_EnterCriticalSection();
    uint32_t regIndexLs = pd->pd_sbu_ls_ctrl_0;

    if (lsTxTermEn != false)
    {
        /* Enable 10KOhm Pullup resistor for LSTX. */
        regIndexLs |= PDSS_PD_SBU_LS_CTRL_0_EN_LSTX_PURES_10K;
    }
    else
    {
        /* Remove termination resistors for LSTX */
        regIndexLs &= ~ PDSS_PD_SBU_LS_CTRL_0_EN_LSTX_PURES_10K;
    }

    if (lsRxTermEn != false)
    {
        /* Enable 1M0hm Pulldown resistor for LSRX. */
        regIndexLs |= PDSS_PD_SBU_LS_CTRL_0_EN_LSRX_PDRES_1MEG;
    }
    else
    {
        /* Remove termination resistors for LSRX */
        regIndexLs &= ~ PDSS_PD_SBU_LS_CTRL_0_EN_LSRX_PDRES_1MEG;
    }

    /* Update SBU connections configuration */
    pd->pd_sbu_ls_ctrl_0 = regIndexLs;

    Cy_SysLib_ExitCriticalSection(intstate);
    return CY_USBPD_STAT_SUCCESS;
}
#endif /* CY_DEVICE_CCG6DF_CFP */

/*******************************************************************************
* Function Name: Cy_USBPD_Mux_SbuSwitchConfigure
****************************************************************************//**
*
* This function configures the SBU Switches.
*
* \param context
* USBPD PDL Context pointer.
*
* \param sbu1State
* sbu switch 1 state
*
* \param sbu2State
* sbu switch 2 state
*
* \return
*  cy_en_usbpd_status_t 
*
*******************************************************************************/
cy_en_usbpd_status_t Cy_USBPD_Mux_SbuSwitchConfigure(cy_stc_usbpd_context_t *context, 
                                                     cy_en_usbpd_sbu_switch_state_t sbu1State, 
                                                     cy_en_usbpd_sbu_switch_state_t sbu2State) 
{
#if defined(CY_DEVICE_CCG6)
    PPDSS_REGS_T pd = context->base; 
    uint32_t sbu1val;
    uint32_t sbu2val;
    uint32_t intstate;

    /* Check that state values are within allowed range. */
    if ((sbu1State >= CY_USBPD_SBU_MAX_STATE) || (sbu2State >= CY_USBPD_SBU_MAX_STATE))
    {
        /* Don't service the request. */
        return CY_USBPD_STAT_INVALID_ARGUMENT; 
    }

    intstate = Cy_SysLib_EnterCriticalSection();
    if ((sbu1State == CY_USBPD_SBU_NOT_CONNECTED) && (sbu2State == CY_USBPD_SBU_NOT_CONNECTED))
    {
        /* Turn off pump first and then disable all switches. */
        Cy_USBPD_Pump_Disable(context, (uint8_t)(1U));
        Cy_SysLib_DelayUs (2);

        pd->sbu20_sbu1_en_1_ctrl = 0;
        pd->sbu20_sbu2_en_1_ctrl = 0;
    }
    else
    {
        /* SBU1 connection. */
        /* Turn the switch off when OVP is detected on any of the CC or SBU lines. */
        sbu1val = PDSS_SBU20_SBU1_EN_1_CTRL_SEL_ON_OFF |
            PDSS_SBU20_SBU1_EN_1_CTRL_SEL_CC1_OVP | PDSS_SBU20_SBU1_EN_1_CTRL_SEL_CC2_OVP |
            PDSS_SBU20_SBU1_EN_1_CTRL_SBU1_SEL_SBU1_OVP | PDSS_SBU20_SBU1_EN_1_CTRL_SBU1_SEL_SBU2_OVP;

        switch (sbu1State)
        {
            case CY_USBPD_SBU_CONNECT_AUX1:
                sbu1val |= PDSS_SBU20_SBU1_EN_1_CTRL_AUXP_SBU1_EN_ON_VALUE;
                break;

            case CY_USBPD_SBU_CONNECT_AUX2:
                sbu1val |= PDSS_SBU20_SBU1_EN_1_CTRL_AUXN_SBU1_EN_ON_VALUE;
                break;

            case CY_USBPD_SBU_CONNECT_LSTX:
                sbu1val |= PDSS_SBU20_SBU1_EN_1_CTRL_LSTX_SBU1_EN_ON_VALUE;
                break;

            case CY_USBPD_SBU_CONNECT_LSRX:
                sbu1val |= PDSS_SBU20_SBU1_EN_1_CTRL_LSRX_SBU1_EN_ON_VALUE;
                break;

            default:
                sbu1val = 0;
                break;
        }

        /* SBU2 connection. */
        /* Turn the switch off when OVP is detected on any of the CC or SBU lines. */
        sbu2val = PDSS_SBU20_SBU2_EN_1_CTRL_SEL_ON_OFF |
            PDSS_SBU20_SBU2_EN_1_CTRL_SEL_CC1_OVP | PDSS_SBU20_SBU2_EN_1_CTRL_SEL_CC2_OVP |
            PDSS_SBU20_SBU2_EN_1_CTRL_SBU2_SEL_SBU1_OVP | PDSS_SBU20_SBU2_EN_1_CTRL_SBU2_SEL_SBU2_OVP;

        switch (sbu2State)
        {
            case CY_USBPD_SBU_CONNECT_AUX1:
                sbu2val |= PDSS_SBU20_SBU2_EN_1_CTRL_AUXP_SBU2_EN_ON_VALUE;
                break;

            case CY_USBPD_SBU_CONNECT_AUX2:
                sbu2val |= PDSS_SBU20_SBU2_EN_1_CTRL_AUXN_SBU2_EN_ON_VALUE;
                break;

            case CY_USBPD_SBU_CONNECT_LSTX:
                sbu2val |= PDSS_SBU20_SBU2_EN_1_CTRL_LSTX_SBU2_EN_ON_VALUE;
                break;

            case CY_USBPD_SBU_CONNECT_LSRX:
                sbu2val |= PDSS_SBU20_SBU2_EN_1_CTRL_LSRX_SBU2_EN_ON_VALUE;
                break;

            default:
                sbu2val = 0;
                break;
        }

        pd->sbu20_sbu1_en_1_ctrl = sbu1val;
        pd->sbu20_sbu2_en_1_ctrl = sbu2val;

        /* Provide some delay and turn the pump on. */
        Cy_SysLib_DelayUs (5);
        Cy_USBPD_Pump_Enable (context, (uint8_t)(1U));
    }

    /* Store SBU1 and SBU2 states. */
    context->sbu1State = sbu1State;
    context->sbu2State = sbu2State;

    Cy_SysLib_ExitCriticalSection(intstate);
    return CY_USBPD_STAT_SUCCESS;
#elif defined(CY_DEVICE_CCG3)
    PPDSS_REGS_T pd = context->base; 
    uint32_t regval;
    uint32_t intstate;

    /* Check that state values are within allowed range. */
    if ((sbu1State > CY_USBPD_SBU_CONNECT_AUX2) || (sbu2State > CY_USBPD_SBU_CONNECT_AUX2))
    {
        /* Don't service the request. */
        return CY_USBPD_STAT_INVALID_ARGUMENT; 
    }

    intstate = Cy_SysLib_EnterCriticalSection();
    regval = pd->sbu_ctrl;

    /* Configure SBU1 switch. */
    if (sbu1State == CY_USBPD_SBU_NOT_CONNECTED)
    {
        /* SBU1 shall not be connected to AUX1/2. */
        regval &= ~(PDSS_SBU_CTRL_IN1_OUT1_EN | PDSS_SBU_CTRL_IN1_OUT2_EN);
    }
    else if (sbu1State == CY_USBPD_SBU_CONNECT_AUX1)
    {
        /* SBU1 shall be connected to AUX1 and not to AUX2. */
        regval |= PDSS_SBU_CTRL_IN1_OUT1_EN;
        regval &= ~PDSS_SBU_CTRL_IN1_OUT2_EN;
    }
    else
    {
        /* SBU1 shall be connected to AUX2 and not to AUX1. */
        regval |= PDSS_SBU_CTRL_IN1_OUT2_EN;
        regval &= ~PDSS_SBU_CTRL_IN1_OUT1_EN;
    }

    /* Configure SBU2 switch. */
    if (sbu2State == CY_USBPD_SBU_NOT_CONNECTED)
    {
        /* SBU2 shall not be connected to AUX1/2. */
        regval &= ~(PDSS_SBU_CTRL_IN2_OUT1_EN | PDSS_SBU_CTRL_IN2_OUT2_EN);
    }
    else if (sbu2State == CY_USBPD_SBU_CONNECT_AUX1)
    {
        /* SBU2 shall be connected to AUX1 and not to AUX2. */
        regval |= PDSS_SBU_CTRL_IN2_OUT1_EN;
        regval &= ~PDSS_SBU_CTRL_IN2_OUT2_EN;
    }
    else
    {
        /* SBU2 shall be connected to AUX2 and not to AUX1. */
        regval |= PDSS_SBU_CTRL_IN2_OUT2_EN;
        regval &= ~PDSS_SBU_CTRL_IN2_OUT1_EN;
    }

    /* Store SBU1 and SBU2 states. */
    /* Store SBU1 and SBU2 states. */
    context->sbu1State = sbu1State;
    context->sbu2State = sbu2State;

    /* Update the switch register. */
    pd->sbu_ctrl = regval;
    Cy_SysLib_ExitCriticalSection(intstate);
    return CY_USBPD_STAT_SUCCESS;
#elif (defined(CY_DEVICE_PMG1S3))
    PPDSS_REGS_T pd = context->base; 
    uint32_t regIndexLs;
    uint32_t regIndexAux;
    uint32_t regFlipMux = 0u;
    uint8_t port = context->port;
    uint32_t intstate;
    uint32_t siliconId = SFLASH_SILICON_ID & 0xFFFFUL;

    /* Workaround for CCG8S to use registers for port 1 to control SBU */
    if (siliconId == 0x3581UL)
    {
        pd = (PPDSS_REGS_T)PDSS1_BASE_ADDR;
    }

    /* Check that state values are within allowed range. */
    if ((sbu1State >= CY_USBPD_SBU_MAX_STATE) || (sbu2State >= CY_USBPD_SBU_MAX_STATE))
    {
        /* Don't service the request. */
        return CY_USBPD_STAT_INVALID_ARGUMENT; 
    }

    intstate = Cy_SysLib_EnterCriticalSection();

    /* SBU Connections for PMG1S3:
     * sbu_new_ctrl[0] - LSTX and LSRX
     * sbu_new_ctrl[1] - AUX1 and AUX2
     * IN1 - SBU1
     * IN2 - SBU2
     * OUT1 - LSTX/AUX1(AUXP)
     * OUT2 - LSRX/AUX2(AUXN)
     * */
    regIndexLs  = pd->sbu_new_ctrl[0];
    regIndexAux = pd->sbu_new_ctrl[1];

    switch (sbu1State)
    {
        case CY_USBPD_SBU_CONNECT_AUX1:
            /* SBU1 shall be connected to AUX1 and not to AUX2. */
            regIndexAux |= PDSS_SBU_NEW_CTRL_SBU_NEW_IN1_OUT1_EN;
            regIndexAux &= ~PDSS_SBU_NEW_CTRL_SBU_NEW_IN1_OUT2_EN;

            /* Clear the LS connections if any */
            regIndexLs &= ~(PDSS_SBU_NEW_CTRL_SBU_NEW_IN1_OUT1_EN | PDSS_SBU_NEW_CTRL_SBU_NEW_IN1_OUT2_EN);
            break;

        case CY_USBPD_SBU_CONNECT_AUX2:
            regIndexAux |= PDSS_SBU_NEW_CTRL_SBU_NEW_IN1_OUT2_EN;
            regIndexAux &= ~PDSS_SBU_NEW_CTRL_SBU_NEW_IN1_OUT1_EN;

            /* Clear the LS connections if any */
            regIndexLs &= ~(PDSS_SBU_NEW_CTRL_SBU_NEW_IN1_OUT1_EN | PDSS_SBU_NEW_CTRL_SBU_NEW_IN1_OUT2_EN);
            break;

        case CY_USBPD_SBU_CONNECT_LSTX:
            regIndexLs |= PDSS_SBU_NEW_CTRL_SBU_NEW_IN1_OUT1_EN;
            regIndexLs &= ~PDSS_SBU_NEW_CTRL_SBU_NEW_IN1_OUT2_EN;

            /* Clear the Aux connections if any */
            regIndexAux &= ~(PDSS_SBU_NEW_CTRL_SBU_NEW_IN1_OUT1_EN | PDSS_SBU_NEW_CTRL_SBU_NEW_IN1_OUT2_EN);
            break;

        case CY_USBPD_SBU_CONNECT_LSRX:
            regIndexLs |= PDSS_SBU_NEW_CTRL_SBU_NEW_IN1_OUT2_EN;
            regIndexLs &= ~PDSS_SBU_NEW_CTRL_SBU_NEW_IN1_OUT1_EN;

            /* Clear the Aux connections if any */
            regIndexAux &= ~(PDSS_SBU_NEW_CTRL_SBU_NEW_IN1_OUT1_EN | PDSS_SBU_NEW_CTRL_SBU_NEW_IN1_OUT2_EN);
            break;

        default:
            /* Clear the Aux/LS connections if any */
            regIndexAux &= ~(PDSS_SBU_NEW_CTRL_SBU_NEW_IN1_OUT1_EN | PDSS_SBU_NEW_CTRL_SBU_NEW_IN1_OUT2_EN);
            regIndexLs &= ~(PDSS_SBU_NEW_CTRL_SBU_NEW_IN1_OUT1_EN | PDSS_SBU_NEW_CTRL_SBU_NEW_IN1_OUT2_EN);
            break;
    }

    switch (sbu2State)
    {
        case CY_USBPD_SBU_CONNECT_AUX1:
            /* SBU2 shall be connected to AUX1 and not to AUX2. */
            regIndexAux |= PDSS_SBU_NEW_CTRL_SBU_NEW_IN2_OUT1_EN;
            regIndexAux &= ~PDSS_SBU_NEW_CTRL_SBU_NEW_IN2_OUT2_EN;

            /* Clear the LS connections if any */
            regIndexLs &= ~(PDSS_SBU_NEW_CTRL_SBU_NEW_IN2_OUT1_EN | PDSS_SBU_NEW_CTRL_SBU_NEW_IN2_OUT2_EN);
            break;

        case CY_USBPD_SBU_CONNECT_AUX2:
            regIndexAux |= PDSS_SBU_NEW_CTRL_SBU_NEW_IN2_OUT2_EN;
            regIndexAux &= ~PDSS_SBU_NEW_CTRL_SBU_NEW_IN2_OUT1_EN;

            /* Clear the LS connections if any */
            regIndexLs &= ~(PDSS_SBU_NEW_CTRL_SBU_NEW_IN2_OUT1_EN | PDSS_SBU_NEW_CTRL_SBU_NEW_IN2_OUT2_EN);
            break;

        case CY_USBPD_SBU_CONNECT_LSTX:
            regIndexLs |= PDSS_SBU_NEW_CTRL_SBU_NEW_IN2_OUT1_EN;
            regIndexLs &= ~PDSS_SBU_NEW_CTRL_SBU_NEW_IN2_OUT2_EN;

            /* Clear the Aux connections if any */
            regIndexAux &= ~(PDSS_SBU_NEW_CTRL_SBU_NEW_IN2_OUT1_EN | PDSS_SBU_NEW_CTRL_SBU_NEW_IN2_OUT2_EN);
            break;

        case CY_USBPD_SBU_CONNECT_LSRX:
            regIndexLs |= PDSS_SBU_NEW_CTRL_SBU_NEW_IN2_OUT2_EN;
            regIndexLs &= ~PDSS_SBU_NEW_CTRL_SBU_NEW_IN2_OUT1_EN;

            /* Clear the Aux connections if any */
            regIndexAux &= ~(PDSS_SBU_NEW_CTRL_SBU_NEW_IN2_OUT1_EN | PDSS_SBU_NEW_CTRL_SBU_NEW_IN2_OUT2_EN);
            break;

        default:
            /* Clear the Aux/LS connections if any */
            regIndexAux &= ~(PDSS_SBU_NEW_CTRL_SBU_NEW_IN2_OUT1_EN | PDSS_SBU_NEW_CTRL_SBU_NEW_IN2_OUT2_EN);
            regIndexLs &= ~(PDSS_SBU_NEW_CTRL_SBU_NEW_IN2_OUT1_EN | PDSS_SBU_NEW_CTRL_SBU_NEW_IN2_OUT2_EN);
            break;
    }

    /* Store SBU1 and SBU2 states. */
    context->sbu1State = sbu1State;
    context->sbu2State = sbu2State;

    /* Update the switch register. */
    pd->sbu_new_ctrl[0] = regIndexLs;
    pd->sbu_new_ctrl[1] = regIndexAux;

    /* Handle SBU<->DBG Flip MUX connection for CCG8D/S silicon */
    if (
               (siliconId == 0x3580UL) ||
               (siliconId == 0x3581UL)
       )
    {
        /* Configure SBU1 connection */
        if ((sbu1State == CY_USBPD_SBU_CONNECT_DBG1) || (sbu1State == CY_USBPD_SBU_CONNECT_DBG2))
        {
            /* Configure SBU1 GPIO */
#if PMG1_PD_DUALPORT_ENABLE
            if (port == TYPEC_PORT_0_IDX)
            {
                Cy_GPIO_Pin_FastInit(GPIO_PRT6, (0x63UL & 0x0FUL), CY_GPIO_DM_PULLUP_DOWN, 0, HSIOM_SEL_DS_0);
            }
            else
#endif /* PMG1_PD_DUALPORT_ENABLE */
            {
                Cy_GPIO_Pin_FastInit(GPIO_PRT6, (0x60UL & 0x0FUL), CY_GPIO_DM_PULLUP_DOWN, 0, HSIOM_SEL_DS_0);
            }

            /* Enable UPS_OUT_EN for SBU1 */
            regFlipMux |= 0x01UL << PDSS_FMX_CTRL_UPS_OUT_EN_POS;

            if (sbu1State == CY_USBPD_SBU_CONNECT_DBG1)
            {
                /* Configure DBG1 GPIO */
                Cy_USBPD_Mux_ConfigDebugGpio(port, CY_USBPD_SBU_CONNECT_DBG1);

                /* Enable DNS_OUT_EN for DBG1 */
                regFlipMux |= 0x01UL << PDSS_FMX_CTRL_DNS_OUT_EN_POS;
                /* Select DNS_IN[0] input for UPS_MUX_SEL[1:0] */
                regFlipMux |= 0x00UL << PDSS_FMX_CTRL_UPS_MUX_SEL_POS;
                /* Select UPS_IN[0] input for DNS_MUX_SEL[1:0] */
                regFlipMux |= 0x00UL << PDSS_FMX_CTRL_DNS_MUX_SEL_POS;
            }
            else
            {
                /* Configure DBG2 GPIO */
                Cy_USBPD_Mux_ConfigDebugGpio(port, CY_USBPD_SBU_CONNECT_DBG2);

                /* Enable DNS_OUT_EN for DBG2 */
                regFlipMux |= 0x02UL << PDSS_FMX_CTRL_DNS_OUT_EN_POS;
                /* Select DNS_IN[1] input for UPS_MUX_SEL[1:0] */
                regFlipMux |= 0x01UL << PDSS_FMX_CTRL_UPS_MUX_SEL_POS;
                /* Select UPS_IN[0] input for DNS_MUX_SEL[3:2] */
                regFlipMux |= 0x00UL << PDSS_FMX_CTRL_DNS_MUX_SEL_POS;
            }
        }

        /* Configure SBU2 connection */
        if ((sbu2State == CY_USBPD_SBU_CONNECT_DBG1) || (sbu2State == CY_USBPD_SBU_CONNECT_DBG2))
        {
            /* Configure SBU2 GPIO */
#if PMG1_PD_DUALPORT_ENABLE
            if (port == TYPEC_PORT_0_IDX)
            {
                Cy_GPIO_Pin_FastInit(GPIO_PRT6, (0x62UL & 0x0FUL), CY_GPIO_DM_PULLUP_DOWN, 0, HSIOM_SEL_DS_0);
            }
            else
#endif /* PMG1_PD_DUALPORT_ENABLE */
            {
                Cy_GPIO_Pin_FastInit(GPIO_PRT6, (0x61UL & 0x0FUL), CY_GPIO_DM_PULLUP_DOWN, 0, HSIOM_SEL_DS_0);
            }

            /* Enable UPS_OUT_EN for SBU2 */
            regFlipMux |= 0x02UL << PDSS_FMX_CTRL_UPS_OUT_EN_POS;

            if (sbu2State == CY_USBPD_SBU_CONNECT_DBG1)
            {
                /* Configure DBG1 GPIO */
                Cy_USBPD_Mux_ConfigDebugGpio(port, CY_USBPD_SBU_CONNECT_DBG1);

                /* Enable DNS_OUT_EN for DBG1 */
                regFlipMux |= 0x01UL << PDSS_FMX_CTRL_DNS_OUT_EN_POS;
                /* Select DNS_IN[0] input for UPS_MUX_SEL[3:2] */
                regFlipMux |= 0x00UL << PDSS_FMX_CTRL_UPS_MUX_SEL_POS;
                /* Select UPS_IN[1] input for DNS_MUX_SEL[1:0] */
                regFlipMux |= 0x01UL << PDSS_FMX_CTRL_DNS_MUX_SEL_POS;
            }
            else
            {
                /* Configure DBG2 GPIO */
                Cy_USBPD_Mux_ConfigDebugGpio(port, CY_USBPD_SBU_CONNECT_DBG2);

                /* Enable DNS_OUT_EN for DBG2 */
                regFlipMux |= 0x02UL << PDSS_FMX_CTRL_DNS_OUT_EN_POS;
                /* Select DNS_IN[1] input for UPS_MUX_SEL[3:2] */
                regFlipMux |= 0x04UL << PDSS_FMX_CTRL_UPS_MUX_SEL_POS;
                /* Select UPS_IN[1] input for DNS_MUX_SEL[3:2] */
                regFlipMux |= 0x04UL << PDSS_FMX_CTRL_DNS_MUX_SEL_POS;
            }
        }

        /* Update Flip MUX register. */
        pd->fmx_ctrl = regFlipMux;
    }

    Cy_SysLib_ExitCriticalSection(intstate);
    return CY_USBPD_STAT_SUCCESS;
#elif defined(CY_DEVICE_CCG6DF_CFP)
    PPDSS_REGS_T pd = context->base;
    PPDSS_REGS_T pdDbg = pd;
    uint32_t siliconId = SFLASH_SILICON_ID & 0xFFFFUL;
    uint32_t regIndexLs;
    uint32_t regIndexAux;
    uint32_t regIndexDbg;
    uint32_t sbuClipperCtrl, sbuClipperCtrlDbg;
    uint32_t switchCtrl = 0u;
    uint32_t intstate;
    const uint32_t auxPathEnMask = (PDSS_PD_SBU_LRES_CTRL_IN1_OUT1_EN | PDSS_PD_SBU_LRES_CTRL_IN1_OUT2_EN | PDSS_PD_SBU_LRES_CTRL_IN2_OUT1_EN | PDSS_PD_SBU_LRES_CTRL_IN2_OUT2_EN);
    const uint32_t lsPathEnMask = (PDSS_PD_SBU_LS_CTRL_0_EN_SBU1_LSTX | PDSS_PD_SBU_LS_CTRL_0_EN_SBU1_LSRX | PDSS_PD_SBU_LS_CTRL_0_EN_SBU2_LSTX | PDSS_PD_SBU_LS_CTRL_0_EN_SBU2_LSRX);
    const uint32_t dbgPathEnMask = (PDSS_PD_SBU_HRES_CTRL_IN1_OUT1_EN | PDSS_PD_SBU_HRES_CTRL_IN1_OUT2_EN | PDSS_PD_SBU_HRES_CTRL_IN2_OUT1_EN | PDSS_PD_SBU_HRES_CTRL_IN2_OUT2_EN);

    /* Check that state values are within allowed range without cross-connections */
    if (
           ((sbu1State >= CY_USBPD_SBU_MAX_STATE) || (sbu2State >= CY_USBPD_SBU_MAX_STATE)) ||
           ((sbu1State == sbu2State) && (sbu1State > CY_USBPD_SBU_NOT_CONNECTED))
       )
    {
        /* Do not service the request. */
        return CY_USBPD_STAT_INVALID_ARGUMENT;
    }

    /* SBU Connections for CCG6DF CFP:
     * pd_sbu_ls_ctrl_0 - LSTX and LSRX
     * pd_sbu_lres_ctrl - AUX1 and AUX2
     * pd_sbu_hres_ctrl - DBG1 and DBG2
     * IN1 - SBU1
     * IN2 - SBU2
     * OUT1 - LSTX/AUX1(AUXP)/DBG1
     * OUT2 - LSRX/AUX2(AUXN)/DBG2
     * */

    /*
     * Workaround for CCG6SF_CFP and CCG8SF_CFP silicon to use registers
     * for port 1 to control SBU-DBG connection.
     * */
    if (
           (siliconId == 0x3E00UL) ||
           (siliconId == 0x3E01UL) ||
           (siliconId == 0x3E80UL)
       )
    {
        pdDbg = (PPDSS_REGS_T)PDSS1_BASE_ADDR;
    }

    /* HW DBG<->SBU connection is already established and functional mode can not be proceed */
    if ((pdDbg->hw_sbu_status & PDSS_HW_SBU_STATUS_FSM_CURR_STATE_MASK) == 0x07UL)
    {
        return CY_USBPD_STAT_NOT_READY;
    }

    intstate = Cy_SysLib_EnterCriticalSection();

    regIndexLs  = pd->pd_sbu_ls_ctrl_0;
    regIndexAux = pd->pd_sbu_lres_ctrl;
    regIndexDbg = pdDbg->pd_sbu_hres_ctrl;

    sbuClipperCtrl = pd->pd_30sbu_clipper_ctrl;
    /* Clear the bits which needs to be configured. */
    sbuClipperCtrl &= ~(PDSS_PD_30SBU_CLIPPER_CTRL_SBU1_EN |
            PDSS_PD_30SBU_CLIPPER_CTRL_SBU2_EN);

    if (sbu1State > CY_USBPD_SBU_NOT_CONNECTED)
    {
        /* Set SBU1 clipper */
        sbuClipperCtrl |= PDSS_PD_30SBU_CLIPPER_CTRL_SBU1_EN;
    }
    if (sbu2State > CY_USBPD_SBU_NOT_CONNECTED)
    {
       /* Set SBU2 clipper */
       sbuClipperCtrl |= PDSS_PD_30SBU_CLIPPER_CTRL_SBU2_EN;
    }

    if (
           ((sbu1State >= CY_USBPD_SBU_CONNECT_DBG1) && (sbu1State <= CY_USBPD_SBU_CONNECT_DBG2)) ||
           ((sbu2State >= CY_USBPD_SBU_CONNECT_DBG1) && (sbu2State <= CY_USBPD_SBU_CONNECT_DBG2))
       )
    {
        /* Set 1.8 volt OVP threshold for DBG1/DBG2 connection */
        sbuClipperCtrl &= ~PDSS_PD_30SBU_CLIPPER_CTRL_DET_LEVEL_CTRL;
    }
    else
    {
        /* Set 3.3 volt OVP threshold for AUXP/AUXN/LSTX/LSRX/None connection */
        sbuClipperCtrl |= PDSS_PD_30SBU_CLIPPER_CTRL_DET_LEVEL_CTRL;
    }

    /* Reset port-1 SBU clipper for single port devices. */
    if (
           (siliconId == 0x3E00UL) ||
           (siliconId == 0x3E01UL) ||
           (siliconId == 0x3E80UL)
       )
    {
        if ((sbu1State < CY_USBPD_SBU_CONNECT_DBG1) && (sbu2State < CY_USBPD_SBU_CONNECT_DBG1))
        {
            /* Enable OVP functionality port-0 registers. */
            sbuClipperCtrl |= (PDSS_PD_30SBU_CLIPPER_CTRL_EN_OVP_VTP | PDSS_PD_30SBU_CLIPPER_CTRL_EN_OVP_COMP | PDSS_PD_30SBU_CLIPPER_CTRL_EN_OVP_COMP_OUT);
            pd->pd_30sbu_clipper_ctrl = sbuClipperCtrl;

            /* Clear port-1 clipper register SBU connection and OVP settings for non debug connection. */
            sbuClipperCtrlDbg = pdDbg->pd_30sbu_clipper_ctrl;
            sbuClipperCtrlDbg &= ~(PDSS_PD_30SBU_CLIPPER_CTRL_SBU1_EN | PDSS_PD_30SBU_CLIPPER_CTRL_SBU2_EN |
                                       PDSS_PD_30SBU_CLIPPER_CTRL_EN_OVP_VTP | PDSS_PD_30SBU_CLIPPER_CTRL_EN_OVP_COMP |
                                           PDSS_PD_30SBU_CLIPPER_CTRL_EN_OVP_COMP_OUT);
            /* Enable port-1 clipper 3.3V OVP limit to avoid pull down SBU lines. */
            sbuClipperCtrlDbg |= PDSS_PD_30SBU_CLIPPER_CTRL_DET_LEVEL_CTRL;
            pdDbg->pd_30sbu_clipper_ctrl = sbuClipperCtrlDbg;
        }
        else
        {
            /* Enable OVP functionality port-1 registers. */
            sbuClipperCtrlDbg = pdDbg->pd_30sbu_clipper_ctrl;
            sbuClipperCtrlDbg &= ~PDSS_PD_30SBU_CLIPPER_CTRL_DET_LEVEL_CTRL;
            sbuClipperCtrlDbg |= PDSS_PD_30SBU_CLIPPER_CTRL_SBU1_EN | PDSS_PD_30SBU_CLIPPER_CTRL_SBU2_EN |
                                       PDSS_PD_30SBU_CLIPPER_CTRL_EN_OVP_VTP | PDSS_PD_30SBU_CLIPPER_CTRL_EN_OVP_COMP |
                                           PDSS_PD_30SBU_CLIPPER_CTRL_EN_OVP_COMP_OUT;
            pdDbg->pd_30sbu_clipper_ctrl = sbuClipperCtrlDbg;

            /* Clear port-0 clipper register SBU connection and OVP settings for non debug connection. */
            sbuClipperCtrl &= ~(PDSS_PD_30SBU_CLIPPER_CTRL_SBU1_EN | PDSS_PD_30SBU_CLIPPER_CTRL_SBU2_EN |
                                       PDSS_PD_30SBU_CLIPPER_CTRL_EN_OVP_VTP | PDSS_PD_30SBU_CLIPPER_CTRL_EN_OVP_COMP |
                                           PDSS_PD_30SBU_CLIPPER_CTRL_EN_OVP_COMP_OUT);
            pd->pd_30sbu_clipper_ctrl = sbuClipperCtrl;
        }
    }
    else
    {
        /* Set SBU clipper for 2-port devices as regular */
        pd->pd_30sbu_clipper_ctrl = sbuClipperCtrl;
    }

    switch (sbu1State)
    {
        case CY_USBPD_SBU_CONNECT_AUX1:
            /* SBU1 shall be connected to AUX1 and not to AUX2. */
            regIndexAux |= PDSS_PD_SBU_LRES_CTRL_IN1_OUT1_EN;
            regIndexAux &= ~PDSS_PD_SBU_LRES_CTRL_IN1_OUT2_EN;

            /* Clear the LS connections if any */
            regIndexLs &= ~(PDSS_PD_SBU_LS_CTRL_0_EN_SBU1_LSTX | PDSS_PD_SBU_LS_CTRL_0_EN_SBU1_LSRX);

            /* Clear the DBG connections if any */
            regIndexDbg &= ~(PDSS_PD_SBU_HRES_CTRL_IN1_OUT1_EN | PDSS_PD_SBU_HRES_CTRL_IN1_OUT2_EN);
            break;

        case CY_USBPD_SBU_CONNECT_AUX2:
            /* SBU1 shall be connected to AUX2 and not to AUX1. */
            regIndexAux |= PDSS_PD_SBU_LRES_CTRL_IN1_OUT2_EN;
            regIndexAux &= ~PDSS_PD_SBU_LRES_CTRL_IN1_OUT1_EN;

            /* Clear the LS connections if any */
            regIndexLs &= ~(PDSS_PD_SBU_LS_CTRL_0_EN_SBU1_LSTX | PDSS_PD_SBU_LS_CTRL_0_EN_SBU1_LSRX);

            /* Clear the DBG connections if any */
            regIndexDbg &= ~(PDSS_PD_SBU_HRES_CTRL_IN1_OUT1_EN | PDSS_PD_SBU_HRES_CTRL_IN1_OUT2_EN);
            break;

        case CY_USBPD_SBU_CONNECT_LSTX:
            /* SBU1 shall be connected to LSTX and not to LSRX. */
            regIndexLs |= PDSS_PD_SBU_LS_CTRL_0_EN_SBU1_LSTX;
            regIndexLs &= ~(PDSS_PD_SBU_LS_CTRL_0_EN_SBU1_LSRX);

            /* Clear the Aux connections if any */
            regIndexAux &= ~(PDSS_PD_SBU_LRES_CTRL_IN1_OUT1_EN | PDSS_PD_SBU_LRES_CTRL_IN1_OUT2_EN);

            /* Clear the DBG connections if any */
            regIndexDbg &= ~(PDSS_PD_SBU_HRES_CTRL_IN1_OUT1_EN | PDSS_PD_SBU_HRES_CTRL_IN1_OUT2_EN);
            break;

        case CY_USBPD_SBU_CONNECT_LSRX:
            /* SBU1 shall be connected to LSRX and not to LSTX. */
            regIndexLs |= PDSS_PD_SBU_LS_CTRL_0_EN_SBU1_LSRX;
            regIndexLs &= ~(PDSS_PD_SBU_LS_CTRL_0_EN_SBU1_LSTX);

            /* Clear the Aux connections if any */
            regIndexAux &= ~(PDSS_PD_SBU_LRES_CTRL_IN1_OUT1_EN | PDSS_PD_SBU_LRES_CTRL_IN1_OUT2_EN);

            /* Clear the DBG connections if any */
            regIndexDbg &= ~(PDSS_PD_SBU_HRES_CTRL_IN1_OUT1_EN | PDSS_PD_SBU_HRES_CTRL_IN1_OUT2_EN);
            break;

        case CY_USBPD_SBU_CONNECT_DBG1:
            /* SBU1 shall be connected to DBG1 and not to DBG2. */
            regIndexDbg |= PDSS_PD_SBU_HRES_CTRL_IN1_OUT1_EN;
            regIndexDbg &= ~(PDSS_PD_SBU_HRES_CTRL_IN1_OUT2_EN);

            /* Clear the LS connections if any */
            regIndexLs &= ~(PDSS_PD_SBU_LS_CTRL_0_EN_SBU1_LSTX | PDSS_PD_SBU_LS_CTRL_0_EN_SBU1_LSRX);

            /* Clear the Aux connections if any */
            regIndexAux &= ~(PDSS_PD_SBU_LRES_CTRL_IN1_OUT1_EN | PDSS_PD_SBU_LRES_CTRL_IN1_OUT2_EN);
            break;

        case CY_USBPD_SBU_CONNECT_DBG2:
            /* SBU1 shall be connected to DBG2 and not to DBG1. */
            regIndexDbg |= PDSS_PD_SBU_HRES_CTRL_IN1_OUT2_EN;
            regIndexDbg &= ~(PDSS_PD_SBU_HRES_CTRL_IN1_OUT1_EN);

            /* Clear the LS connections if any */
            regIndexLs &= ~(PDSS_PD_SBU_LS_CTRL_0_EN_SBU1_LSTX | PDSS_PD_SBU_LS_CTRL_0_EN_SBU1_LSRX);

            /* Clear the Aux connections if any */
            regIndexAux &= ~(PDSS_PD_SBU_LRES_CTRL_IN1_OUT1_EN | PDSS_PD_SBU_LRES_CTRL_IN1_OUT2_EN);
            break;

        default:
            /* Clear the Aux connections if any */
            regIndexAux &= ~(PDSS_PD_SBU_LRES_CTRL_IN1_OUT1_EN | PDSS_PD_SBU_LRES_CTRL_IN1_OUT2_EN);
            /* Clear the DBG connections if any */
            regIndexDbg &= ~(PDSS_PD_SBU_HRES_CTRL_IN1_OUT1_EN | PDSS_PD_SBU_HRES_CTRL_IN1_OUT2_EN);
            /* Clear the LS connections if any */
            regIndexLs &= ~(PDSS_PD_SBU_LS_CTRL_0_EN_SBU1_LSTX | PDSS_PD_SBU_LS_CTRL_0_EN_SBU1_LSRX);
            break;
    }

    switch (sbu2State)
    {
        case CY_USBPD_SBU_CONNECT_AUX1:
            /* SBU2 shall be connected to AUX1 and not to AUX2. */
            regIndexAux |= PDSS_PD_SBU_LRES_CTRL_IN2_OUT1_EN;
            regIndexAux &= ~(PDSS_PD_SBU_LRES_CTRL_IN2_OUT2_EN);

            /* Clear the LS connections if any */
            regIndexLs &= ~(PDSS_PD_SBU_LS_CTRL_0_EN_SBU2_LSTX | PDSS_PD_SBU_LS_CTRL_0_EN_SBU2_LSRX);

            /* Clear the Debug connections if any */
            regIndexDbg &= ~(PDSS_PD_SBU_HRES_CTRL_IN2_OUT1_EN | PDSS_PD_SBU_HRES_CTRL_IN2_OUT2_EN);
            break;

        case CY_USBPD_SBU_CONNECT_AUX2:
            /* SBU2 shall be connected to AUX2 and not to AUX1. */
            regIndexAux |= PDSS_PD_SBU_LRES_CTRL_IN2_OUT2_EN;
            regIndexAux &= ~(PDSS_PD_SBU_LRES_CTRL_IN2_OUT1_EN);

            /* Clear the LS connections if any */
            regIndexLs &= ~(PDSS_PD_SBU_LS_CTRL_0_EN_SBU2_LSTX | PDSS_PD_SBU_LS_CTRL_0_EN_SBU2_LSRX);

            /* Clear the Debug connections if any */
            regIndexDbg &= ~(PDSS_PD_SBU_HRES_CTRL_IN2_OUT1_EN | PDSS_PD_SBU_HRES_CTRL_IN2_OUT2_EN);
            break;

        case CY_USBPD_SBU_CONNECT_LSTX:
            /* SBU2 shall be connected to LSTX and not to LSRX. */
            regIndexLs |= PDSS_PD_SBU_LS_CTRL_0_EN_SBU2_LSTX;
            regIndexLs &= ~(PDSS_PD_SBU_LS_CTRL_0_EN_SBU2_LSRX);

            /* Clear the AUX connections if any */
            regIndexAux &= ~(PDSS_PD_SBU_LRES_CTRL_IN2_OUT1_EN | PDSS_PD_SBU_LRES_CTRL_IN2_OUT2_EN);

            /* Clear the Debug connections if any */
            regIndexDbg &= ~(PDSS_PD_SBU_HRES_CTRL_IN2_OUT1_EN | PDSS_PD_SBU_HRES_CTRL_IN2_OUT2_EN);
            break;

        case CY_USBPD_SBU_CONNECT_LSRX:
            /* SBU2 shall be connected to LSRX and not to LSTX. */
            regIndexLs |= PDSS_PD_SBU_LS_CTRL_0_EN_SBU2_LSRX;
            regIndexLs &= ~(PDSS_PD_SBU_LS_CTRL_0_EN_SBU2_LSTX);

            /* Clear the AUX connections if any */
            regIndexAux &= ~(PDSS_PD_SBU_LRES_CTRL_IN2_OUT1_EN | PDSS_PD_SBU_LRES_CTRL_IN2_OUT2_EN);

            /* Clear the Debug connections if any */
            regIndexDbg &= ~(PDSS_PD_SBU_HRES_CTRL_IN2_OUT1_EN | PDSS_PD_SBU_HRES_CTRL_IN2_OUT2_EN);
            break;

        case CY_USBPD_SBU_CONNECT_DBG1:
            /* SBU2 shall be connected to DBG1 and not to DBG2 */
            regIndexDbg |= PDSS_PD_SBU_HRES_CTRL_IN2_OUT1_EN;
            regIndexDbg &= ~(PDSS_PD_SBU_HRES_CTRL_IN2_OUT2_EN);

            /* Clear the AUX connections if any */
            regIndexAux &= ~(PDSS_PD_SBU_LRES_CTRL_IN2_OUT1_EN | PDSS_PD_SBU_LRES_CTRL_IN2_OUT2_EN);

            /* Clear the LS connections if any */
            regIndexLs &= ~(PDSS_PD_SBU_LS_CTRL_0_EN_SBU2_LSTX | PDSS_PD_SBU_LS_CTRL_0_EN_SBU2_LSRX);
            break;

        case CY_USBPD_SBU_CONNECT_DBG2:
            /* SBU2 shall be connected to DBG2 and not to DBG1 */
            regIndexDbg |= PDSS_PD_SBU_HRES_CTRL_IN2_OUT2_EN;
            regIndexDbg &= ~(PDSS_PD_SBU_HRES_CTRL_IN2_OUT1_EN);

            /* Clear the AUX connections if any */
            regIndexAux &= ~(PDSS_PD_SBU_LRES_CTRL_IN2_OUT1_EN | PDSS_PD_SBU_LRES_CTRL_IN2_OUT2_EN);

            /* Clear the LS connections if any */
            regIndexLs &= ~(PDSS_PD_SBU_LS_CTRL_0_EN_SBU2_LSTX | PDSS_PD_SBU_LS_CTRL_0_EN_SBU2_LSRX);
            break;

        default:
            /* Clear the AUX connections if any */
            regIndexAux &= ~(PDSS_PD_SBU_LRES_CTRL_IN2_OUT1_EN | PDSS_PD_SBU_LRES_CTRL_IN2_OUT2_EN);
            /* Clear the Debug connections if any */
            regIndexDbg &= ~(PDSS_PD_SBU_HRES_CTRL_IN2_OUT1_EN | PDSS_PD_SBU_HRES_CTRL_IN2_OUT2_EN);
            /* Clear the LS connections if any */
            regIndexLs &= ~(PDSS_PD_SBU_LS_CTRL_0_EN_SBU2_LSTX | PDSS_PD_SBU_LS_CTRL_0_EN_SBU2_LSRX);
            break;
    }

#if PDL_TERM_AUX_LS_ENABLE
    /* Set AUX termination resistors if required */
    if (
           ((sbu1State == CY_USBPD_SBU_CONNECT_AUX1) || (sbu1State == CY_USBPD_SBU_CONNECT_AUX2)) &&
           ((sbu2State == CY_USBPD_SBU_CONNECT_AUX1) || (sbu2State == CY_USBPD_SBU_CONNECT_AUX2))
       )
    {
        /* Set AUX1 100KOhm Pulldown and AUX2 100KOhm Pullup resistors. */
        Cy_USBPD_Mux_AuxTermConfigure(context, CY_USBPD_AUX_1_100K_PD_RESISTOR, CY_USBPD_AUX_2_100K_PU_RESISTOR);
    }
    else
    {
        /* Remove termination resistors connection if any */
        Cy_USBPD_Mux_AuxTermConfigure(context, CY_USBPD_AUX_NO_RESISTOR, CY_USBPD_AUX_NO_RESISTOR);
    }

    /* Set LS termination resistors if required. */
    if (
           ((sbu1State == CY_USBPD_SBU_CONNECT_LSTX) || (sbu1State == CY_USBPD_SBU_CONNECT_LSRX)) &&
           ((sbu2State == CY_USBPD_SBU_CONNECT_LSTX) || (sbu2State == CY_USBPD_SBU_CONNECT_LSRX))
       )
    {
        /* Enable 10KOhm Pullup resistor for LSTX. */
        regIndexLs |= PDSS_PD_SBU_LS_CTRL_0_EN_LSTX_PURES_10K;
        /* Enable 1M0hm Pulldown resistor for LSRX. */
        regIndexLs |= PDSS_PD_SBU_LS_CTRL_0_EN_LSRX_PDRES_1MEG;
    }
    else
    {
        /* Remove termination resistors connections if any */
        regIndexLs &= ~ (PDSS_PD_SBU_LS_CTRL_0_EN_LSTX_PURES_10K | PDSS_PD_SBU_LS_CTRL_0_EN_LSRX_PDRES_1MEG);
    }
#endif /* PDL_TERM_AUX_LS_ENABLE */

    /* Update SBU connections configuration */
    pd->pd_sbu_lres_ctrl = regIndexAux;
    pd->pd_sbu_ls_ctrl_0 = regIndexLs;
    pdDbg->pd_sbu_hres_ctrl = regIndexDbg;

    /* Set HW control of the gate drivers */
    switchCtrl = PDSS_SWITCH_CTRL_00_AUTO_MODE | PDSS_SWITCH_CTRL_00_SEL_ON_OFF | PDSS_SWITCH_CTRL_00_EN_SWITCH_ON_VALUE;

    /* Enable SBU1 OVP Fault */
    if (sbu1State > CY_USBPD_SBU_NOT_CONNECTED)
    {
        switchCtrl |= (0x01UL << PDSS_SWITCH_CTRL_00_SEL_FAULT_EN_POS);
    }
    /* Enable SBU2 OVP Fault */
    if (sbu2State > CY_USBPD_SBU_NOT_CONNECTED)
    {
        switchCtrl |= (0x02UL << PDSS_SWITCH_CTRL_00_SEL_FAULT_EN_POS);
    }

    /* Clear current gates configuration */
    pd->switch_ctrl_00 = PDSS_SWITCH_CTRL_00_DEFAULT;
    pd->switch_ctrl_02 = PDSS_SWITCH_CTRL_02_DEFAULT;

    if ((regIndexDbg & dbgPathEnMask)!= 0u)
    {
        /*
         * Reset the edge detector in the switch controller before setting SBU-DBG connection
         * to make sure SBU-DBG connection works after SBU OVP triggering.
         */
        pdDbg->switch_ctrl_01 = PDSS_SWITCH_CTRL_01_DEFAULT | PDSS_SWITCH_CTRL_01_RST_EDGE_DET;
    }
    else
    {
        pdDbg->switch_ctrl_01 = PDSS_SWITCH_CTRL_01_DEFAULT;
    }

    /* Configure gate drivers depending on current SBU configuration */
    if ((regIndexAux & auxPathEnMask)!= 0u)
    {
        /* SBU<->AUX connection */
        pd->switch_ctrl_00 = switchCtrl;
    }
    if ((regIndexDbg & dbgPathEnMask)!= 0u)
    {
        /* SBU<->DBG connection */
        pdDbg->switch_ctrl_01 = switchCtrl;
    }
    if ((regIndexLs & lsPathEnMask) != 0u)
    {
        /* SBU<->LS connection */
        pd->switch_ctrl_02 = switchCtrl;
    }

    /* Provide some delay and turn the pump on. */
    Cy_SysLib_DelayUs (5);
    Cy_USBPD_Pump_Enable (context, (uint8_t)(1U));

    /* Store SBU1 and SBU2 states. */
    context->sbu1State = sbu1State;
    context->sbu2State = sbu2State;

    Cy_SysLib_ExitCriticalSection(intstate);
    return CY_USBPD_STAT_SUCCESS;
#else
    CY_UNUSED_PARAMETER(context);
    CY_UNUSED_PARAMETER(sbu1State);
    CY_UNUSED_PARAMETER(sbu2State);
    return CY_USBPD_STAT_NOT_SUPPORTED;
#endif /* defined(CY_DEVICE_CCG6) */    
}

/*******************************************************************************
* Function Name: Cy_USBPD_Mux_AuxTermConfigure
****************************************************************************//**
*
* This function configures resistor values for AUX1 and AUX2.
*
* \param context
* USBPD PDL Context pointer.
*
* \param aux1Config
* Aux Resistor 1 state
*
* \param aux2Config
* Aux Resistor 2 state
*
* \return
*  cy_en_usbpd_status_t 
*
*******************************************************************************/
cy_en_usbpd_status_t Cy_USBPD_Mux_AuxTermConfigure(cy_stc_usbpd_context_t *context,
                                   cy_en_usbpd_aux_resistor_config_t aux1Config,
                                   cy_en_usbpd_aux_resistor_config_t aux2Config) 
{
#if (defined(CY_DEVICE_CCG3) || defined(CY_DEVICE_PMG1S3))
    PPDSS_REGS_T pd = context->base;
    uint32_t regval = pd->sbu_ctrl;

    /* Check if resistor values passed are correct. */
    if ((aux1Config > CY_USBPD_AUX_1_470K_PD_RESISTOR) ||
            (((aux2Config < CY_USBPD_AUX_2_100K_PU_RESISTOR) && (aux2Config != CY_USBPD_AUX_NO_RESISTOR))
             || (aux2Config > CY_USBPD_AUX_MAX_RESISTOR_CONFIG)))
    {
        /* Wrong configuration. */
        return CY_USBPD_STAT_INVALID_ARGUMENT;
    }

    /* Check if no resistor configuration for AUX1. */
    if (aux1Config == CY_USBPD_AUX_NO_RESISTOR)
    {
        regval &= ~(PDSS_SBU_CTRL_OUT1_1MEG_EN_PU | PDSS_SBU_CTRL_OUT1_100K_EN_PD
                | PDSS_SBU_CTRL_OUT1_470K_EN_PD);
    }
    else
    {
        /* Enable the requested resistor. */
        regval |= (uint32_t)(1UL << (uint32_t)aux1Config);
    }

    /* Check if no resistor configuration for AUX2. */
    if (aux2Config == CY_USBPD_AUX_NO_RESISTOR)
    {
        regval &= ~(PDSS_SBU_CTRL_OUT2_100K_EN_PU | PDSS_SBU_CTRL_OUT2_4P7MEG_EN_PD
                | PDSS_SBU_CTRL_OUT2_1MEG_EN_PD);
    }
    else
    {
        /* Enable the requested resistor. */
        regval |= (uint32_t)(1UL << (uint32_t)aux2Config);
    }

    /* Store the configuration. */
    context->aux1Config = aux1Config;
    context->aux2Config = aux2Config;

    /* Update the resistor. */
    pd->sbu_ctrl = regval;
    return CY_USBPD_STAT_SUCCESS;
#elif defined(CY_DEVICE_CCG6DF_CFP)
    PPDSS_REGS_T pd = context->base;
    uint32_t intstate, regval = 0u;

    /* Return if required configuration is already configured. */
    if ((aux1Config == context->aux1Config) && (aux2Config == context->aux2Config))
    {
        return CY_USBPD_STAT_SUCCESS;
    }

    /* Check if resistor values passed are correct. */
    if ((aux1Config > CY_USBPD_AUX_1_470K_PD_RESISTOR) ||
            (((aux2Config < CY_USBPD_AUX_2_100K_PU_RESISTOR) && (aux2Config != CY_USBPD_AUX_NO_RESISTOR))
             || (aux2Config > CY_USBPD_AUX_MAX_RESISTOR_CONFIG)))
    {
        /* Wrong configuration. */
        return CY_USBPD_STAT_INVALID_ARGUMENT;
    }

    /* Set termination for AUX1. */
    switch (aux1Config)
    {
        case CY_USBPD_AUX_1_1MEG_PU_RESISTOR:
            /* AUX1 1M0hm Pullup resistor. */
            regval |= PDSS_PD_SBU_TERM_CTRL_OUT1_1MEG_EN_PU;
            break;

        case CY_USBPD_AUX_1_100K_PD_RESISTOR:
            /* AUX1 100KOhm Pulldown resistor. */
            regval |= PDSS_PD_SBU_TERM_CTRL_OUT1_100K_EN_PD;
            break;

        case CY_USBPD_AUX_1_470K_PD_RESISTOR:
            /* AUX1 470KOhm Pulldown resistor. */
            regval |= PDSS_PD_SBU_TERM_CTRL_OUT1_470K_EN_PD;
            break;

        default:
            /* Do Nothing */
            break;
    }

    /* Set termination for AUX2. */
    switch (aux2Config)
    {
        case CY_USBPD_AUX_2_100K_PU_RESISTOR:
            /* AUX2 100KOhm Pullup resistor. */
            regval |= PDSS_PD_SBU_TERM_CTRL_OUT2_100K_EN_PU;
            break;

        case CY_USBPD_AUX_2_4P7MEG_PD_RESISTOR:
            /* AUX2 4.7M0hm Pulldown resistor. */
            regval |= PDSS_PD_SBU_TERM_CTRL_OUT2_4P7MEG_EN_PD;
            break;

        case CY_USBPD_AUX_2_1MEG_PD_RESISTOR:
            /* AUX2 1M0hm Pulldown resistor. */
            regval |= PDSS_PD_SBU_TERM_CTRL_OUT2_1MEG_EN_PD;
            break;

        default:
            /* Do Nothing */
            break;
    }

    /* Store the configuration. */
    context->aux1Config = aux1Config;
    context->aux2Config = aux2Config;

    intstate = Cy_SysLib_EnterCriticalSection();

    /* Update the register. */
    pd->pd_sbu_term_ctrl = regval;

    Cy_SysLib_ExitCriticalSection(intstate);
    return CY_USBPD_STAT_SUCCESS;
#else
    CY_UNUSED_PARAMETER(context);
    CY_UNUSED_PARAMETER(aux1Config);
    CY_UNUSED_PARAMETER(aux2Config);
    return CY_USBPD_STAT_NOT_SUPPORTED;
#endif /* defined(CY_DEVICE_CCG3) || defined(CY_DEVICE_PMG1S3) */   
}

/*******************************************************************************
* Function Name: Cy_USBPD_Mux_SbuAdftEnable
****************************************************************************//**
*
* This function enables the ADFT block of SBU.
*
* \param context
* USBPD PDL Context pointer.
*
* \param adftInput
* Input from the SBU that needs to be connected to ADFT
*
* \return
*  cy_en_usbpd_status_t
*
*******************************************************************************/
cy_en_usbpd_status_t Cy_USBPD_Mux_SbuAdftEnable(cy_stc_usbpd_context_t *context,
                                   cy_en_usbpd_sbu_adft_input_t adftInput)
{
    cy_en_usbpd_status_t status = CY_USBPD_STAT_NOT_SUPPORTED;
#if (defined(CY_DEVICE_PMG1S3))
    PPDSS_REGS_T pd = context->base;
    uint32_t regval = pd->sbu_new_ctrl[1];

    /* Check if ADFT input passed is correct. */
    if (adftInput > CY_USBPD_SBU_ADFT_AUX1_SBU2)
    {
        /* Wrong configuration. */
        status = CY_USBPD_STAT_INVALID_ARGUMENT;
    }
    else
    {
        /* Enable ADFT block of SBU */
        regval &= ~PDSS_SBU_NEW_CTRL_SBU_NEW_ADFT_SEL_MASK;
        regval |= (PDSS_SBU_NEW_CTRL_SBU_NEW_ADFT_EN | ((uint32_t)adftInput << PDSS_SBU_NEW_CTRL_SBU_NEW_ADFT_SEL_POS));

        pd->sbu_new_ctrl[1] = regval;
        status = CY_USBPD_STAT_SUCCESS;
    }
#elif (defined(CY_DEVICE_CCG6))
    PPDSS_REGS_T pd = context->base;
    uint32_t regval = pd->sbu20_0_ctrl;

    /* Enable ADFT block of SBU */
    regval &= ~PDSS_SBU20_0_CTRL_SBU20_ADFT_SEL_MASK;
    regval |= (PDSS_SBU20_0_CTRL_SBU20_ADFT_EN | ((uint32_t)adftInput << PDSS_SBU20_0_CTRL_SBU20_ADFT_SEL_POS));

    pd->sbu20_0_ctrl = regval;
    status = CY_USBPD_STAT_SUCCESS;
#elif (defined(CY_DEVICE_CCG3))
    PPDSS_REGS_T pd = context->base;
    uint32_t regval = pd->sbu_ctrl;

    /* Check if ADFT input passed is correct. */
    if ((adftInput > CY_USBPD_SBU_ADFT_AUX2) ||
            (adftInput < CY_USBPD_SBU_ADFT_SBU1))
    {
        /* Wrong configuration. */
        status = CY_USBPD_STAT_INVALID_ARGUMENT;
    }
    else
    {
        /* Enable ADFT block of SBU */
        regval &= ~PDSS_SBU_CTRL_SBU_ADFT_SEL_MASK;
        regval |= (PDSS_SBU_CTRL_SBU_ADFT_EN | ((uint32_t)adftInput << PDSS_SBU_CTRL_SBU_ADFT_SEL_POS));

        pd->sbu_ctrl = regval;
        status = CY_USBPD_STAT_SUCCESS;
    }
#elif defined(CY_DEVICE_CCG6DF_CFP)
    PPDSS_REGS_T pd = context->base;
    uint32_t sbuClipperCtrl = pd->pd_30sbu_clipper_ctrl;

    /* Enable CC Pump, this is required to measure SBU voltage */
    Cy_USBPD_Pump_Enable (context, (uint8_t)(0U));

    /* Enable ADFT block of SBU */
    sbuClipperCtrl &= ~PDSS_PD_30SBU_CLIPPER_CTRL_CLIPPER_ADFT_CTRL_MASK;
    sbuClipperCtrl |= (PDSS_PD_30SBU_CLIPPER_CTRL_CLIPPER_ADFT_EN | (adftInput << PDSS_PD_30SBU_CLIPPER_CTRL_CLIPPER_ADFT_CTRL_POS));
    pd->pd_30sbu_clipper_ctrl = sbuClipperCtrl;

    /* Provide some delay and turn on SBU pump */
    Cy_SysLib_DelayUs (5);
    Cy_USBPD_Pump_Enable (context, (uint8_t)(1U));

    status = CY_USBPD_STAT_SUCCESS;
#else
    CY_UNUSED_PARAMETER(context);
    CY_UNUSED_PARAMETER(adftInput);
#endif /* (defined(CY_DEVICE_PMG1S3)) */
    return status;
}

/*******************************************************************************
* Function Name: Cy_USBPD_Mux_SbuAdftDisable
****************************************************************************//**
*
* This function disables the ADFT block of SBU.
*
* \param context
* USBPD PDL Context pointer.
*
* \return
*  None
*
*******************************************************************************/
void Cy_USBPD_Mux_SbuAdftDisable(cy_stc_usbpd_context_t *context)
{
#if (defined(CY_DEVICE_PMG1S3))
    PPDSS_REGS_T pd = context->base;
    /* Disable the ADFT block of SBU */
    pd->sbu_new_ctrl[1] &= ~(PDSS_SBU_NEW_CTRL_SBU_NEW_ADFT_EN | PDSS_SBU_NEW_CTRL_SBU_NEW_ADFT_SEL_MASK);
#elif (defined(CY_DEVICE_CCG6))
    PPDSS_REGS_T pd = context->base;
    /* Disable the ADFT block of SBU */
    pd->sbu20_0_ctrl &= ~(PDSS_SBU20_0_CTRL_SBU20_ADFT_EN | PDSS_SBU20_0_CTRL_SBU20_ADFT_SEL_MASK);
#elif (defined(CY_DEVICE_CCG3))
    PPDSS_REGS_T pd = context->base;
    /* Disable the ADFT block of SBU */
    pd->sbu_ctrl &= ~(PDSS_SBU_CTRL_SBU_ADFT_EN | PDSS_SBU_CTRL_SBU_ADFT_SEL_MASK);
#elif defined(CY_DEVICE_CCG6DF_CFP)
    PPDSS_REGS_T pd = context->base;
    /* Disable the ADFT block of SBU */
    pd->pd_30sbu_clipper_ctrl &= ~(PDSS_PD_30SBU_CLIPPER_CTRL_CLIPPER_ADFT_EN | PDSS_PD_30SBU_CLIPPER_CTRL_CLIPPER_ADFT_CTRL_MASK);
#else
    CY_UNUSED_PARAMETER(context);
#endif /* (defined(CY_DEVICE_PMG1S3)) */
}

#endif /* (defined(CY_IP_MXUSBPD) || defined(CY_IP_M0S8USBPD)) */

/* [] END OF FILE */
