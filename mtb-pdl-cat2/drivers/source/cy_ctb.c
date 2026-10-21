/***************************************************************************//**
* \file cy_ctb.c
* \version 1.0.1
*
* \brief
* Provides the public functions for the CTB driver.
*
********************************************************************************
* \copyright
* (c) (2017-2021), Cypress Semiconductor Corporation (an Infineon company) or
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
#include "cy_ctb.h"

#ifdef CY_IP_M0S8PASS4A_CTB

#if (CY_IP_M0S8PASS4A_INSTANCES == 1U)
    /* Unconditionally return zero if there is one PASS instance */
    #define CY_CTB_PASS_BASE(base)      ((CTBM0 == (base)) ? PASS0 : PASS0)
#else /* two PASS instances  */
    #define CY_CTB_PASS_BASE(base)      ((CTBM0 == (base)) ? PASS0 : PASS1)
#endif /* (CY_IP_M0S8PASS4A_INSTANCES == 1U) */

/**< Internal macros for conditions used by CY_ASSERT calls */
#define CY_CTB_OPAMPNUM_0_1(num)            (((num) == CY_CTB_OPAMP_0) || ((num) == CY_CTB_OPAMP_1))
#define CY_CTB_SWITCHMASK(select,mask)      (((select) == CY_CTB_OPAMP_0) ? (((mask) & (~CY_CTB_DEINIT_OA0_SW)) == 0UL) : \
                                            (((mask) & (~CY_CTB_DEINIT_OA1_SW)) == 0UL))


/*******************************************************************************
* Function Name: Cy_CTB_Enable
****************************************************************************//**
*
* Powers up the CTB hardware block.
*
* \param base
* The pointer to structure-describing registers.
*
*******************************************************************************/
void Cy_CTB_Enable(CTBM_Type * base)
{
    CTBM_CTB_CTRL(base) |= CTBM_CTB_CTRL_ENABLED_Msk;
}


/*******************************************************************************
* Function Name: Cy_CTB_Disable
****************************************************************************//**
*
* Powers down the CTB hardware block.
*
* \param base
* The pointer to structure-describing registers.
*
*******************************************************************************/
void Cy_CTB_Disable(CTBM_Type * base)
{
    CTBM_CTB_CTRL(base) &= (~CTBM_CTB_CTRL_ENABLED_Msk);
}


/*******************************************************************************
* Function Name: Cy_CTB_Init
****************************************************************************//**
*
* Initializes or restores the CTB and both opamps per
* provided settings. Parameters are usually set only once at initialization.
*
* \note This function call disables a whole CTB block, call \ref Cy_CTB_Enable
* after this function call.
*
* \param base
* The pointer to structure-describing registers.
*
* \param config
* The pointer to a structure containing configuration data for the entire CTB.
*
* \return
* The status of initialization, \ref CY_CTB_SUCCESS or \ref CY_CTB_BAD_PARAM
*
* \funcusage
* The following code snippet configures Opamp0 as a comparator
* and Opamp1 as an opamp follower with an external (10x) drive. The terminals
* are routed to external pins by closing the switches shown.
*
* \snippet ctb_snippet.c SNIPPET_CTBINIT
*
*******************************************************************************/
cy_en_ctb_status_t Cy_CTB_Init(CTBM_Type * base, const cy_stc_ctb_config_t * config)
{
    cy_en_ctb_status_t result = CY_CTB_SUCCESS;

    CY_ASSERT_L1(NULL != base);
    CY_ASSERT_L1(NULL != config);

    if ((NULL == base) || (NULL == config))
    {
        result = CY_CTB_BAD_PARAM;
    }
    else
    {
        Cy_CTB_SetDeepSleepMode(base, config->deepSleep);

        if (NULL != config->oa0)
        {
            result = Cy_CTB_OpampInit(base, CY_CTB_OPAMP_0, config->oa0);
        }

        if ((CY_CTB_SUCCESS == result) && (NULL != config->oa1))
        {
            result = Cy_CTB_OpampInit(base, CY_CTB_OPAMP_1, config->oa1);
        }
    }

    return (result);
}


/*******************************************************************************
* Function Name: Cy_CTB_OpampInit
****************************************************************************//**
*
* Initializes each opamp separately without impacting analog routing.
* Intended for use by automatic analog routing and configuration tools
* to configure each opamp without having to integrate the settings with
* those of the other opamp first.
*
* Can also be used to configure both opamps to have the same settings.
*
* \param base
* The pointer to structure-describing registers.
*
* \param opampNum
* \ref CY_CTB_OPAMP_0, \ref CY_CTB_OPAMP_1, or \ref CY_CTB_OPAMP_BOTH
*
* \param config
* The pointer to a structure containing configuration data.
*
* \return
* The status of initialization, \ref CY_CTB_SUCCESS or \ref CY_CTB_BAD_PARAM
*
* \funcusage
* \snippet ctb_snippet.c SNIPPET_OPAMPINIT
*
*******************************************************************************/
cy_en_ctb_status_t Cy_CTB_OpampInit(CTBM_Type * base, cy_en_ctb_opamp_sel_t opampNum, const cy_stc_ctb_opamp_config_t * config)
{
    CY_ASSERT_L1(NULL != base);
    CY_ASSERT_L1(NULL != config);

    cy_en_ctb_status_t result;
    uint32_t oaResCtrl;

    if ((NULL == base) || (NULL == config))
    {
        result = CY_CTB_BAD_PARAM;
    }
    else
    {
        CY_ASSERT_L3(CY_CTB_OPAMPNUM(opampNum));
        CY_ASSERT_L3(CY_CTB_OAPOWER(config->power));
        CY_ASSERT_L3(CY_CTB_OAMODE(config->outputMode));
        CY_ASSERT_L3(CY_CTB_COMPEDGE(config->compEdge));
        CY_ASSERT_L3(CY_CTB_COMPLEVEL(config->compLevel));

        /* The two opamp control registers are identical */
        oaResCtrl = (uint32_t) config->power
                  | (uint32_t) config->outputMode
                  | ((config->pump) ? CTBM_OA_RES0_CTRL_OA0_PUMP_EN_Msk : 0UL) /* These masks are identical for both OpAmps */
                  | (uint32_t) config->compEdge
                  | (uint32_t) config->compLevel
                  | ((config->compBypass) ? CTBM_OA_RES0_CTRL_OA0_BYPASS_DSI_SYNC_Msk : 0UL)
                  | ((config->compHyst) ? CTBM_OA_RES0_CTRL_OA0_HYST_EN_Msk : 0UL);

        if ((CY_CTB_OPAMP_0 == opampNum) || (CY_CTB_OPAMP_BOTH == opampNum))
        {
            CY_ASSERT_L1(CY_CTB_SWITCHMASK(CY_CTB_OPAMP_0, config->switchCtrl));
            CTBM_OA0_SW(base) = CY_CTB_DEINIT_OA0_SW & config->switchCtrl;

            CTBM_OA_RES0_CTRL(base) = oaResCtrl;
            CTBM_OA0_COMP_TRIM(base) = (uint32_t) ((config->outputMode == CY_CTB_MODE_OPAMP_EXTERNAL) ? CY_CTB_OPAMP_COMPENSATION_CAP_MAX : CY_CTB_OPAMP_COMPENSATION_CAP_MIN);

            /* The INTR_MASK register is shared between the two OpAmps */
            CTBM_INTR_MASK(base) |= (config->compIntrEn ? CTBM_INTR_MASK_COMP0_MASK_Msk : CY_CTB_DEINIT);
            CTBM_INTR(base) |= CTBM_INTR_MASK_COMP0_MASK_Msk;
        }

        if ((CY_CTB_OPAMP_1 == opampNum) || (CY_CTB_OPAMP_BOTH == opampNum))
        {
            CY_ASSERT_L1(CY_CTB_SWITCHMASK(CY_CTB_OPAMP_1, config->switchCtrl));
            CTBM_OA1_SW(base) = CY_CTB_DEINIT_OA1_SW & config->switchCtrl;

            CTBM_OA_RES1_CTRL(base) = oaResCtrl;
            CTBM_OA1_COMP_TRIM(base) = (uint32_t) ((config->outputMode == CY_CTB_MODE_OPAMP_EXTERNAL) ? CY_CTB_OPAMP_COMPENSATION_CAP_MAX : CY_CTB_OPAMP_COMPENSATION_CAP_MIN);

            /* The INTR_MASK register is shared between the two OpAmps */
            CTBM_INTR_MASK(base) |= (config->compIntrEn ? CTBM_INTR_MASK_COMP1_MASK_Msk : CY_CTB_DEINIT);
            CTBM_INTR(base) |= CTBM_INTR_MASK_COMP1_MASK_Msk;
        }

        result = CY_CTB_SUCCESS;
    }

    return (result);
}


/*******************************************************************************
* Function Name: Cy_CTB_DeInit
****************************************************************************//**
*
* Resets CTB registers back to power on reset defaults.
*
* \param base
* The pointer to structure-describing registers.
*
* \param deInitRouting
* If true, all analog routing switches are reset to their default state.
* If false, analog switch registers are untouched.
*
* \return
* The status of initialization, \ref CY_CTB_SUCCESS or \ref CY_CTB_BAD_PARAM
*
*******************************************************************************/
cy_en_ctb_status_t Cy_CTB_DeInit(CTBM_Type * base, bool deInitRouting)
{
    CY_ASSERT_L1(NULL != base);

    cy_en_ctb_status_t result = CY_CTB_SUCCESS;

    if (NULL == base)
    {
        result = CY_CTB_BAD_PARAM;
    }
    else
    {
        CTBM_CTB_CTRL(base)          = CY_CTB_DEINIT;
        CTBM_OA_RES0_CTRL(base)      = CY_CTB_DEINIT;
        CTBM_OA_RES1_CTRL(base)      = CY_CTB_DEINIT;
        CTBM_INTR_MASK(base)         = CY_CTB_DEINIT;

        if (deInitRouting)
        {
            Cy_CTB_OpenAllSwitches(base);
        }
    }

    return (result);
}


/*******************************************************************************
* Function Name: Cy_CTB_SetDeepSleepMode
****************************************************************************//**
*
* Enables or disables the entire CTB (not per opamp) in Deep Sleep mode.
*
* If enabled, ensure that only internal CTB switches are used for routing.
* Switches on AMUXBUSA and AMUXBUSB are not enabled in Deep Sleep.
* See the \ref group_ctb_dependencies section for more information.
*
* \note
* In Deep Sleep mode, the charge pumps are disabled so the input range of the
* opamps is reduced to 0 V to VDDA - 1.5 V.
*
* \param base
* The pointer to structure-describing registers.
*
* \param deepSleep Enable operation in Deep Sleep power mode
*
* \funcusage
* \snippet ctb_snippet.c CTB_SNIPPET_SET_DEEPSLEEP_MODE
*
*******************************************************************************/
void Cy_CTB_SetDeepSleepMode(CTBM_Type * base, bool deepSleep)
{
    CY_REG32_CLR_SET(CTBM_CTB_CTRL(base), CTBM_CTB_CTRL_DEEPSLEEP_ON, ((deepSleep) ? 1UL : 0UL));
}


/*******************************************************************************
* Function Name: Cy_CTB_SetOutputMode
****************************************************************************//**
*
* Sets the opamp Output mode to internal (1x) drive, external (10x) drive,
* or Comparator mode.
*
* \param base
* The pointer to structure-describing registers.
*
* \param opampNum
* \ref CY_CTB_OPAMP_0, \ref CY_CTB_OPAMP_1, or \ref CY_CTB_OPAMP_BOTH
*
* \param outputMode
* Opamp mode selection. Select a value from \ref cy_en_ctb_output_t.
*
* \funcusage
*
* \snippet ctb_snippet.c CTB_SNIPPET_SET_OUTPUT_MODE
*
*******************************************************************************/
void Cy_CTB_SetOutputMode(CTBM_Type * base, cy_en_ctb_opamp_sel_t opampNum, cy_en_ctb_output_t outputMode)
{
    CY_ASSERT_L3(CY_CTB_OPAMPNUM(opampNum));
    CY_ASSERT_L3(CY_CTB_OAMODE(outputMode));

    uint32_t oaCtrlReg;

    if ((CY_CTB_OPAMP_0 == opampNum) || (CY_CTB_OPAMP_BOTH == opampNum))
    {
        /* Clear the three affected bits before setting them */
        oaCtrlReg = CTBM_OA_RES0_CTRL(base) & ~(CTBM_OA_RES0_CTRL_OA0_DRIVE_STR_SEL_Msk | CTBM_OA_RES0_CTRL_OA0_COMP_EN_Msk);
        CTBM_OA_RES0_CTRL(base) = oaCtrlReg | (uint32_t) outputMode;
        CTBM_OA0_COMP_TRIM(base) = (uint32_t) ((outputMode == CY_CTB_MODE_OPAMP_EXTERNAL) ? CY_CTB_OPAMP_COMPENSATION_CAP_MAX: CY_CTB_OPAMP_COMPENSATION_CAP_MIN);
    }

    if ((CY_CTB_OPAMP_1 == opampNum) || (CY_CTB_OPAMP_BOTH == opampNum))
    {
        oaCtrlReg = CTBM_OA_RES1_CTRL(base) & ~(CTBM_OA_RES1_CTRL_OA1_DRIVE_STR_SEL_Msk | CTBM_OA_RES1_CTRL_OA1_COMP_EN_Msk);
        CTBM_OA_RES1_CTRL(base) = oaCtrlReg | (uint32_t) outputMode;
        CTBM_OA1_COMP_TRIM(base) = (uint32_t) ((outputMode == CY_CTB_MODE_OPAMP_EXTERNAL) ? CY_CTB_OPAMP_COMPENSATION_CAP_MAX: CY_CTB_OPAMP_COMPENSATION_CAP_MIN);
    }
}


/*******************************************************************************
* Function Name: Cy_CTB_SetPower
****************************************************************************//**
*
* Configures the power level and charge pump for a specific opamp.
*
* At higher power levels, the opamp consumes more current but provides more
* gain bandwidth.
* Enabling the charge pump increases the current but provides
* a rail-to-rail input range. Disabling the charge pump limits the input range to
* VDDA - 1.5 V.
* See the device datasheet for performance specifications.
*
* \param base
* The pointer to structure-describing registers.
*
* \param opampNum
* \ref CY_CTB_OPAMP_0, \ref CY_CTB_OPAMP_1, or \ref CY_CTB_OPAMP_BOTH
*
* \param power
* Power mode selection. Select a value from \ref cy_en_ctb_power_t.
*
* \param pump
* Enable or disable the charge pump.
*
* \funcusage
* \snippet ctb_snippet.c CTB_SNIPPET_SET_POWER
*
*******************************************************************************/
void Cy_CTB_SetPower(CTBM_Type * base, cy_en_ctb_opamp_sel_t opampNum, cy_en_ctb_power_t power, bool pump)
{
    CY_ASSERT_L3(CY_CTB_OPAMPNUM(opampNum));
    CY_ASSERT_L3(CY_CTB_OAPOWER(power));

    uint32_t oaCtrlReg;

    if ((CY_CTB_OPAMP_0 == opampNum) || (CY_CTB_OPAMP_BOTH == opampNum))
    {
        /* Clear the two affected bits before setting them */
        oaCtrlReg = CTBM_OA_RES0_CTRL(base) & ~(CTBM_OA_RES0_CTRL_OA0_PWR_MODE_Msk | CTBM_OA_RES0_CTRL_OA0_PUMP_EN_Msk);
        CTBM_OA_RES0_CTRL(base) = oaCtrlReg | (uint32_t) power | ((pump) ? CTBM_OA_RES0_CTRL_OA0_PUMP_EN_Msk : 0UL);
    }

    if ((CY_CTB_OPAMP_1 == opampNum) || (CY_CTB_OPAMP_BOTH == opampNum))
    {
        oaCtrlReg = CTBM_OA_RES1_CTRL(base) & ~(CTBM_OA_RES1_CTRL_OA1_PWR_MODE_Msk | CTBM_OA_RES1_CTRL_OA1_PUMP_EN_Msk);
        CTBM_OA_RES1_CTRL(base) = oaCtrlReg | (uint32_t) power | ((pump) ? CTBM_OA_RES1_CTRL_OA1_PUMP_EN_Msk : 0UL);
    }
}


/*******************************************************************************
* Function Name: Cy_CTB_OpampSetOffset
****************************************************************************//**
*
* Overrides the CTB opamp offset factory trim.
* The trim is a six-bit value and the MSB is a direction bit.
*
* <table class="doxtable">
*   <tr>
*     <th>Bit 5</th>
*     <th>Bits 4:0</th>
*     <th>Note</th>
*   </tr>
*   <tr>
*     <td>0</td>
*     <td>00000</td>
*     <td>Negative trim direction - minimum setting</td>
*   </tr>
*   <tr>
*     <td>0</td>
*     <td>11111</td>
*     <td>Negative trim direction - maximum setting</td>
*   </tr>
*   <tr>
*     <td>1</td>
*     <td>00000</td>
*     <td>Positive trim direction - minimum setting</td>
*   </tr>
*   <tr>
*     <td>1</td>
*     <td>11111</td>
*     <td>Positive trim direction - maximum setting</td>
*   </tr>
* </table>
*
* \param base
* The pointer to structure-describing registers.
*
* \param opampNum
* \ref CY_CTB_OPAMP_0, \ref CY_CTB_OPAMP_1, or \ref CY_CTB_OPAMP_BOTH
*
* \param trim
* The trim value is from 0 to 63.
*
* \funcusage
* \snippet ctb_snippet.c CTB_SNIPPET_SET_OFFSET_TRIM
*
*******************************************************************************/
void Cy_CTB_OpampSetOffset(CTBM_Type * base, cy_en_ctb_opamp_sel_t opampNum, uint32_t trim)
{
    CY_ASSERT_L3(CY_CTB_OPAMPNUM(opampNum));
    CY_ASSERT_L2(CY_CTB_TRIM(trim));

    if ((CY_CTB_OPAMP_0 == opampNum) || (CY_CTB_OPAMP_BOTH == opampNum))
    {
        CTBM_OA0_OFFSET_TRIM(base) = (trim << CTBM_OA0_OFFSET_TRIM_OA0_OFFSET_TRIM_Pos) & CTBM_OA0_OFFSET_TRIM_OA0_OFFSET_TRIM_Msk;
    }

    if ((CY_CTB_OPAMP_1 == opampNum) || (CY_CTB_OPAMP_BOTH == opampNum))
    {
        CTBM_OA1_OFFSET_TRIM(base) = (trim << CTBM_OA1_OFFSET_TRIM_OA1_OFFSET_TRIM_Pos) & CTBM_OA1_OFFSET_TRIM_OA1_OFFSET_TRIM_Msk;
    }
}


/*******************************************************************************
* Function Name: Cy_CTB_OpampGetOffset
****************************************************************************//**
*
* Returns the current CTB opamp offset trim value.
*
* \param base
* The pointer to structure-describing registers.
*
* \param opampNum
* \ref CY_CTB_OPAMP_0 or \ref CY_CTB_OPAMP_1.
* \ref CY_CTB_OPAMP_NONE and \ref CY_CTB_OPAMP_BOTH are invalid options.
*
* \return Offset trim value
*
* \funcusage
* \snippet ctb_snippet.c CTB_SNIPPET_GET_OFFSET_TRIM
*
*******************************************************************************/
uint32_t Cy_CTB_OpampGetOffset(const CTBM_Type * base, cy_en_ctb_opamp_sel_t opampNum)
{
    CY_ASSERT_L3(CY_CTB_OPAMPNUM_0_1(opampNum));

    uint32_t trimReg = 0UL;

    if (CY_CTB_OPAMP_0 == opampNum)
    {
        trimReg = CTBM_OA0_OFFSET_TRIM(base);
    }
    else if (CY_CTB_OPAMP_1 == opampNum)
    {
        trimReg = CTBM_OA1_OFFSET_TRIM(base);
    }
    else
    {
        /* opampNum is invalid, return zero */
    }

    return trimReg;
}


/*******************************************************************************
* Function Name: Cy_CTB_OpampSetSlope
****************************************************************************//**
*
* Overrides the CTB opamp slope factory trim.
* The offset of the opamp will vary across the temperature.
* This trim compensates for the slope of the offset across temperature.
* This compensation uses a bias current from the Analog Reference block.
* To disable it, set the trim to 0.
*
* The trim is a six-bit value and the MSB is a direction bit.
*
* <table class="doxtable">
*   <tr>
*     <th>Bit 5</th>
*     <th>Bits 4:0</th>
*     <th>Note</th>
*   </tr>
*   <tr>
*     <td>0</td>
*     <td>00000</td>
*     <td>Negative trim direction - minimum setting</td>
*   </tr>
*   <tr>
*     <td>0</td>
*     <td>11111</td>
*     <td>Negative trim direction - maximum setting</td>
*   </tr>
*   <tr>
*     <td>1</td>
*     <td>00000</td>
*     <td>Positive trim direction - minimum setting</td>
*   </tr>
*   <tr>
*     <td>1</td>
*     <td>11111</td>
*     <td>Positive trim direction - maximum setting</td>
*   </tr>
* </table>
*
* \param base
* The pointer to structure-describing registers.
*
* \param opampNum
* \ref CY_CTB_OPAMP_0, \ref CY_CTB_OPAMP_1, or \ref CY_CTB_OPAMP_BOTH
*
* \param trim
* The trim value is from 0 to 63.
*
* \funcusage
* \snippet ctb_snippet.c CTB_SNIPPET_SET_SLOPE_TRIM
*
*******************************************************************************/
void Cy_CTB_OpampSetSlope(CTBM_Type * base, cy_en_ctb_opamp_sel_t opampNum, uint32_t trim)
{
    CY_ASSERT_L3(CY_CTB_OPAMPNUM(opampNum));
    CY_ASSERT_L2(CY_CTB_TRIM(trim));

    if ((CY_CTB_OPAMP_0 == opampNum) || (CY_CTB_OPAMP_BOTH == opampNum))
    {
        CTBM_OA0_SLOPE_OFFSET_TRIM(base) = (trim << CTBM_OA0_SLOPE_OFFSET_TRIM_OA0_SLOPE_OFFSET_TRIM_Pos) & CTBM_OA0_SLOPE_OFFSET_TRIM_OA0_SLOPE_OFFSET_TRIM_Msk;
    }

    if ((CY_CTB_OPAMP_1 == opampNum) || (CY_CTB_OPAMP_BOTH == opampNum))
    {
        CTBM_OA1_SLOPE_OFFSET_TRIM(base) = (trim << CTBM_OA1_SLOPE_OFFSET_TRIM_OA1_SLOPE_OFFSET_TRIM_Pos) & CTBM_OA1_SLOPE_OFFSET_TRIM_OA1_SLOPE_OFFSET_TRIM_Msk;
    }
}


/*******************************************************************************
* Function Name: Cy_CTB_OpampGetSlope
****************************************************************************//**
*
* Returns the CTB opamp slope trim value.
*
* \param base
* The pointer to structure-describing registers.
*
* \param opampNum
* \ref CY_CTB_OPAMP_0 or \ref CY_CTB_OPAMP_1.
* \ref CY_CTB_OPAMP_NONE and \ref CY_CTB_OPAMP_BOTH are invalid options.
*
* \return Slope trim value
*
* \funcusage
* \snippet ctb_snippet.c CTB_SNIPPET_GET_SLOPE_TRIM
*
*******************************************************************************/
uint32_t Cy_CTB_OpampGetSlope(const CTBM_Type * base, cy_en_ctb_opamp_sel_t opampNum)
{
    CY_ASSERT_L3(CY_CTB_OPAMPNUM_0_1(opampNum));

    uint32_t trimReg = 0UL;

    if (CY_CTB_OPAMP_0 == opampNum)
    {
        trimReg = CTBM_OA0_SLOPE_OFFSET_TRIM(base);
    }
    else if (CY_CTB_OPAMP_1 == opampNum)
    {
        trimReg = CTBM_OA1_SLOPE_OFFSET_TRIM(base);
    }
    else
    {
        /* opampNum is invalid, return zero */
    }

    return trimReg;
}


/*******************************************************************************
* Function Name: Cy_CTB_DSAB_SetSource
****************************************************************************//**
*
* Overrides the Deep Sleep Amplifier Bias current bias sources from
* factory trim settings.
* If the default (\ref CY_CTB_SRSS_ZTC_DSAB_PTAT) DSAB setting is changed
* then a periodic re-trim of CTB(m) offset must be performed.
*
* \param base
* The pointer to structure-describing registers.
*
* \param biasSource
* \ref cy_en_ctb_dsab_bias_source_t
*
* \funcusage
* \snippet ctb_snippet.c CTB_SNIPPET_SET_DSAB_BIAS_SOURCE
*
*******************************************************************************/
void Cy_CTB_DSAB_SetSource(CTBM_Type * base, cy_en_ctb_dsab_bias_source_t biasSource)
{
    /* Select the current source */
    uint32_t  regValue = _VAL2FLD(PASS_DSAB_DSAB_CTRL_SEL_OUT, (uint32_t) biasSource >> 1U) |
                         _VAL2FLD(PASS_DSAB_DSAB_CTRL_REF_SWAP_EN, (uint32_t) biasSource & 1U);
    PASS_DSAB_DSAB_CTRL(CY_CTB_PASS_BASE(base)) = ((PASS_DSAB_DSAB_CTRL(CY_CTB_PASS_BASE(base)) & ~CY_CTB_DSAB_CURRENT_SOURCE_CONFIG_Msk) | regValue);

    /* Enable the DSAB block */
    PASS_DSAB_DSAB_CTRL(CY_CTB_PASS_BASE(base)) |= PASS_DSAB_DSAB_CTRL_ENABLED_Msk;
}


/*******************************************************************************
* Function Name: Cy_CTB_DSAB_GetSource
****************************************************************************//**
*
* Returns the Deep Sleep Amplifier Bias current bias source.
*
* \param base
* The pointer to structure-describing registers.
*
* \return biasSource
* \ref cy_en_ctb_dsab_bias_source_t
*
* \funcusage
* \snippet ctb_snippet.c CTB_SNIPPET_GET_DSAB_BIAS_SOURCE
*
*******************************************************************************/
cy_en_ctb_dsab_bias_source_t Cy_CTB_DSAB_GetSource(const CTBM_Type *base)
{
    uint32_t biasSource;

    biasSource = (((_FLD2VAL(PASS_DSAB_DSAB_CTRL_SEL_OUT, PASS_DSAB_DSAB_CTRL(CY_CTB_PASS_BASE(base)))) << 1U) |
                _FLD2VAL(PASS_DSAB_DSAB_CTRL_REF_SWAP_EN, PASS_DSAB_DSAB_CTRL(CY_CTB_PASS_BASE(base))));

    return ((cy_en_ctb_dsab_bias_source_t) biasSource);
}


/*******************************************************************************
* Function Name: Cy_CTB_DSAB_SetCurrent
****************************************************************************//**
*
* Overrides the Deep Sleep Amplifier Bias current value from factory trim settings.
* Periodic re-trim of CTB(m) offset must be performed if these settings are
* overridden.
*
* \param base
* The pointer to structure-describing registers.
*
* \param biasCurrent
* The bias current value.
*
* \funcusage
* \snippet ctb_snippet.c CTB_SNIPPET_SET_DSAB_BIAS_CURRENT
*
*******************************************************************************/
void Cy_CTB_DSAB_SetCurrent(CTBM_Type * base, uint32_t biasCurrent)
{
    CY_ASSERT_L2(CY_CTB_CURRENT_SEL(biasCurrent));
    CY_REG32_CLR_SET(PASS_DSAB_DSAB_CTRL(CY_CTB_PASS_BASE(base)), PASS_DSAB_DSAB_CTRL_CURRENT_SEL, biasCurrent);
}


/*******************************************************************************
* Function Name: Cy_CTB_DSAB_GetCurrent
****************************************************************************//**
*
* Returns the Deep Sleep Amplifier Bias current value.
*
* \param base
* The pointer to structure-describing registers.
*
* \return The bias current value.
*
* \funcusage
* \snippet ctb_snippet.c CTB_SNIPPET_GET_DSAB_BIAS_CURRENT
*
*******************************************************************************/
uint32_t Cy_CTB_DSAB_GetCurrent(const CTBM_Type * base)
{
    return (_FLD2VAL(PASS_DSAB_DSAB_CTRL_CURRENT_SEL, PASS_DSAB_DSAB_CTRL(CY_CTB_PASS_BASE(base))));
}


#define PASS_PASS_CTRL_PMPCLK_Pos (PASS_PASS_CTRL_PMPCLK_BYP_Pos)
#define PASS_PASS_CTRL_PMPCLK_Msk (PASS_PASS_CTRL_PMPCLK_BYP_Msk | PASS_PASS_CTRL_PMPCLK_SRC_Msk)
/*******************************************************************************
* Function Name: Cy_CTB_SetPumpClkSource
****************************************************************************//**
*
* Sets the clock source for both charge pumps in the CTB. Recall that each opamp
* has its own charge pump.
*
* \param base
* The pointer to structure-describing registers.
*
* \param pumpClk
* Clock source selection for the pump. See \ref cy_en_ctb_clk_pump_source_t.
*
* \funcusage
* \snippet ctb_snippet.c CTB_SNIPPET_SET_CLK_PUMP_SOURCE_HF
* \snippet ctb_snippet.c CTB_SNIPPET_SET_CLK_PUMP_SOURCE_SRSS
*
*******************************************************************************/
void Cy_CTB_SetPumpClkSource(CTBM_Type * base, cy_en_ctb_clk_pump_source_t pumpClk)
{
    CY_ASSERT_L3(CY_CTB_CLKPUMP(pumpClk));

    CY_REG32_CLR_SET(PASS_PASS_CTRL(CY_CTB_PASS_BASE(base)), PASS_PASS_CTRL_PMPCLK, pumpClk);
}


/*******************************************************************************
* Function Name: Cy_CTB_SetAnalogSwitch
****************************************************************************//**
*
* Provides firmware control of the CTB switches. Each call to this function
* can open a set of switches or close a set of switches in one register.
*
* \param base
* The pointer to structure-describing registers.
*
* \param opampNum
* \ref CY_CTB_OPAMP_0, \ref CY_CTB_OPAMP_1, or \ref CY_CTB_OPAMP_BOTH
*
* \param switchMask
* The mask of the switches to either open or close.
* The switch masks can be found in the \ref group_ctb_opamp_switch_macros.
* Use the enum that is consistent with the specified OpAmp.
* \note Some switch mask positions may match for both OpAmps,
* so it is allowed to carefully use this function for both OpAmps simultaneously.
*
* \param switchState
* The boolean switch state: true - closed, false - opened.
*
* \funcusage
* \snippet ctb_snippet.c CTB_SNIPPET_SET_ANALOG_SWITCH
*
*******************************************************************************/
void Cy_CTB_SetAnalogSwitch(CTBM_Type * base, cy_en_ctb_opamp_sel_t opampNum, uint32_t switchMask, bool switchState)
{
    CY_ASSERT_L1(CY_CTB_OPAMPNUM(opampNum));

    if (0UL != switchMask) /* else - do nothing */
    {
        if ((CY_CTB_OPAMP_0 == opampNum) || (CY_CTB_OPAMP_BOTH == opampNum))
        {
            if (switchState)
            {
                CTBM_OA0_SW(base) = CY_CTB_DEINIT_OA0_SW & switchMask;
            }
            else
            {
                CTBM_OA0_SW_CLEAR(base) = CY_CTB_DEINIT_OA0_SW & switchMask;
            }
        }

        if ((CY_CTB_OPAMP_1 == opampNum) || (CY_CTB_OPAMP_BOTH == opampNum))
        {
            if (switchState)
            {
                CTBM_OA1_SW(base) = CY_CTB_DEINIT_OA1_SW & switchMask;
            }
            else
            {
                CTBM_OA1_SW_CLEAR(base) = CY_CTB_DEINIT_OA1_SW & switchMask;
            }
        }
    }
}


/*******************************************************************************
* Function Name: Cy_CTB_GetAnalogSwitch
****************************************************************************//**
*
* Returns the open or closed state of the specified analog switch.
*
* \param base
* The pointer to structure-describing registers.
*
* \param opampNum
* \ref CY_CTB_OPAMP_0 or \ref CY_CTB_OPAMP_1.
* \ref CY_CTB_OPAMP_NONE and \ref CY_CTB_OPAMP_BOTH are invalid options.
*
* \return
* The state of the switches in the provided OpAmp.
* Compare this value to the switch masks in the following masks:
* \ref group_ctb_opamp_switch_macros
*
* \funcusage
* \snippet ctb_snippet.c CTB_SNIPPET_GET_ANALOG_SWITCH
*
*******************************************************************************/
uint32_t Cy_CTB_GetAnalogSwitch(const CTBM_Type * base, cy_en_ctb_opamp_sel_t opampNum)
{
    CY_ASSERT_L1(CY_CTB_OPAMPNUM_0_1(opampNum));

    uint32_t switchRegValue = 0UL;

    if (CY_CTB_OPAMP_0 == opampNum)
    {
        switchRegValue = CTBM_OA0_SW(base);
    }
    else if (CY_CTB_OPAMP_1 == opampNum)
    {
        switchRegValue = CTBM_OA1_SW(base);
    }
    else
    {
        /* opampNum is invalid, return zero */
    }

    return switchRegValue;
}


/*******************************************************************************
* Function Name: Cy_CTB_CompSetInterruptEdgeType
****************************************************************************//**
*
* Configures the type of an edge that will trigger a comparator interrupt.
*
* \param base
* The pointer to structure-describing registers.
*
* \param compNum
* \ref CY_CTB_OPAMP_0, \ref CY_CTB_OPAMP_1, or \ref CY_CTB_OPAMP_BOTH
*
* \param edge
* The type of the edge that will trigger an interrupt. Select a value from \ref cy_en_ctb_comp_edge_t.
*
* \funcusage
* \snippet ctb_snippet.c CTB_SNIPPET_COMP_SET_INTERRUPT_EDGE_TYPE
*
*******************************************************************************/
void Cy_CTB_CompSetInterruptEdgeType(CTBM_Type * base, cy_en_ctb_opamp_sel_t compNum, cy_en_ctb_comp_edge_t edge)
{
    CY_ASSERT_L3(CY_CTB_OPAMPNUM(compNum));
    CY_ASSERT_L3(CY_CTB_COMPEDGE(edge));

    uint32_t opampCtrlReg;

    if ((CY_CTB_OPAMP_0 == compNum) || (CY_CTB_OPAMP_BOTH == compNum))
    {
        opampCtrlReg = CTBM_OA_RES0_CTRL(base) & ~(CTBM_OA_RES0_CTRL_OA0_COMPINT_Msk);
        CTBM_OA_RES0_CTRL(base) = opampCtrlReg | (uint32_t) edge;
    }

    if ((CY_CTB_OPAMP_1 == compNum) || (CY_CTB_OPAMP_BOTH == compNum))
    {
        opampCtrlReg = CTBM_OA_RES1_CTRL(base) & ~(CTBM_OA_RES1_CTRL_OA1_COMPINT_Msk);
        CTBM_OA_RES1_CTRL(base) = opampCtrlReg | (uint32_t) edge;
    }
}


/*******************************************************************************
* Function Name: Cy_CTB_CompGetStatus
****************************************************************************//**
*
* Returns the comparator output status.
* When the positive input voltage is greater than the negative input voltage,
* the comparator status is high. Otherwise, the status is low.
*
* \param base
* The pointer to structure-describing registers.
*
* \param compNum
* \ref CY_CTB_OPAMP_0 or \ref CY_CTB_OPAMP_1.
* \ref CY_CTB_OPAMP_NONE and \ref CY_CTB_OPAMP_BOTH are invalid options.
*
* \return
* The comparator status.
* A value of 0 is returned if compNum is invalid.
* - 0: The status is low
* - 1: The status is high
*
* \funcusage
* \snippet ctb_snippet.c CTB_SNIPPET_COMP_GET_STATUS
*
*******************************************************************************/
uint32_t Cy_CTB_CompGetStatus(const CTBM_Type * base, cy_en_ctb_opamp_sel_t compNum)
{
    CY_ASSERT_L3(CY_CTB_OPAMPNUM_0_1(compNum));

    uint32_t compStatusResult = 0UL;

    if (CY_CTB_OPAMP_0 == compNum)
    {
        compStatusResult = (CTBM_COMP_STAT(base) & CTBM_COMP_STAT_OA0_COMP_Msk) >> CTBM_COMP_STAT_OA0_COMP_Pos;
    }
    else if (CY_CTB_OPAMP_1 == compNum)
    {
        compStatusResult = (CTBM_COMP_STAT(base) & CTBM_COMP_STAT_OA1_COMP_Msk) >> CTBM_COMP_STAT_OA1_COMP_Pos;
    }
    else
    {
        /* compNum is invalid, return zero */
    }

    return compStatusResult;
}

#endif /* CY_IP_M0S8PASS4A_CTB */

/* [] END OF FILE */
