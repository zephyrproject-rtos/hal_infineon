/***************************************************************************//**
* \file cy_syspm_regb.c
* \version 1.0
*
* This file provides the implementation for Regulator Type B Support APIs
*
*
********************************************************************************
* \copyright
* (c) 2016-2026, Infineon Technologies AG or an affiliate of
* Infineon Technologies AG.
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
#include "cy_syslib.h"
#include "cy_syspm_regb.h"

#if defined(CY_IP_MXS22SRSS) && defined(CY_IP_MXS22SRSS_VERSION) && (CY_IP_MXS22SRSS_VERSION == 2) && (CY_IP_MXS22SRSS_VERSION_MINOR == 1) && defined(CY_DEVICE_PSB3)

#define CY_SYSPM_ASSERT_PROFILE_VALID(subSystem, profile)              \
                           CY_ASSERT_L3((subSystem == CY_SYSPM_DEVICE_MCU) ? (CY_SYSPM_IS_DEVICE_MCU_PROFILE_VALID(profile)) :\
                                        (CY_SYSPM_IS_DEVICE_BT_PROFILE_VALID(profile)))

/* Sets the CLDO target voltage index */
void Cy_SysPm_CLDOSetTargetVoltageIndex(cy_en_syspm_device_sub_system_t subSystem, uint32_t profile, cy_en_syspm_cldo_index_t cldoIndex)
{
    CY_ASSERT_L3(CY_SYSPM_IS_DEVICE_SUB_SYSTEM_VALID(subSystem));
    CY_SYSPM_ASSERT_PROFILE_VALID(subSystem, profile);
    CY_ASSERT_L3(CY_SYSPM_IS_CLDO_INDEX_VALID(cldoIndex));

    CY_REG32_CLR_SET(OPMAC_MAIN->DEVICE[subSystem].DECODE[profile].PROFILE, OPMAC_MAIN_DEVICE_DECODE_PROFILE_CORE_INDEX, cldoIndex);
}

/* Sets the SR target voltage index */
void Cy_SysPm_SRSetTargetVoltageIndex(cy_en_syspm_device_sub_system_t subSystem, uint32_t profile, cy_en_syspm_sr_index_t srIndex)
{
    CY_ASSERT_L3(CY_SYSPM_IS_DEVICE_SUB_SYSTEM_VALID(subSystem));
    CY_SYSPM_ASSERT_PROFILE_VALID(subSystem, profile);
    CY_ASSERT_L3(CY_SYSPM_IS_SR_INDEX_VALID(srIndex));

    CY_REG32_CLR_SET(OPMAC_MAIN->DEVICE[subSystem].DECODE[profile].PROFILE, OPMAC_MAIN_DEVICE_DECODE_PROFILE_INDEX, srIndex);
}

/* Sets the SR target load current */
void Cy_SysPm_SRSetTargetLoadCurrent(cy_en_syspm_device_sub_system_t subSystem, uint32_t profile, cy_en_syspm_sr_load_current_threshold_t srLoadCurrent)
{
    CY_ASSERT_L3(CY_SYSPM_IS_DEVICE_SUB_SYSTEM_VALID(subSystem));
    CY_SYSPM_ASSERT_PROFILE_VALID(subSystem, profile);
    CY_ASSERT_L3(CY_SYSPM_IS_SR_LOAD_CURRENT_THRESHOLD_VALID(srLoadCurrent));

    CY_REG32_CLR_SET(OPMAC_MAIN->DEVICE[subSystem].DECODE[profile].PROFILE, OPMAC_MAIN_DEVICE_DECODE_PROFILE_LOAD, srLoadCurrent);
}

/* Sets the SR target mode */
void Cy_SysPm_SRSetTargetMode(cy_en_syspm_device_sub_system_t subSystem, uint32_t profile, cy_en_syspm_sr_target_mode_t srMode)
{
    CY_ASSERT_L3(CY_SYSPM_IS_DEVICE_SUB_SYSTEM_VALID(subSystem));
    CY_SYSPM_ASSERT_PROFILE_VALID(subSystem, profile);
    CY_ASSERT_L3(CY_SYSPM_IS_SR_TARGET_MODE_VALID(srMode));

    CY_REG32_CLR_SET(OPMAC_MAIN->DEVICE[subSystem].DECODE[profile].PROFILE, OPMAC_MAIN_DEVICE_DECODE_PROFILE_MODE, srMode);
}

/* Configures the PMU */
void Cy_SysPm_PMUConfigure( cy_stc_syspm_pmu_params_t *pmuParam)
{
    CY_ASSERT_L3(CY_SYSPM_IS_PMU_BGCHOPDELAY_VALID(pmuParam->bgChopDelay));

    uint32_t pmuConfig = SRSS_PWR_CONFIG_PMU;
    pmuConfig = _CLR_SET_FLD32U(pmuConfig, PMU_AUX_PWR_CONFIG_PMU_BG_CHOP_DELAY, pmuParam->bgChopDelay);
    pmuConfig = _CLR_SET_FLD32U(pmuConfig, PMU_AUX_PWR_CONFIG_PMU_BG_LP_CLK_SEL, ((pmuParam->bgLpClkSel) ? 1UL : 0UL));
    pmuConfig = _CLR_SET_FLD32U(pmuConfig, PMU_AUX_PWR_CONFIG_PMU_BG_FORCE_EN, ((pmuParam->bgForceEnable) ? 1UL : 0UL));
    SRSS_PWR_CONFIG_PMU = pmuConfig;
}

/* Configures the Core LDO */
void Cy_SysPm_CLDOConfigure( cy_stc_syspm_cldo_params_t *cldoParam)
{
    CY_ASSERT_L3(CY_SYSPM_IS_CLDO_BYPASS_THRESHOLD_VALID(cldoParam->cldoBypThreshold));
    CY_ASSERT_L3(CY_SYSPM_IS_CLDO_BYPASS_OFFSET_VALID(cldoParam->cldoBypOffset));
    CY_ASSERT_L3(CY_SYSPM_IS_CLDO_FALLING_BYPASS_THRESHOLD_VALID(cldoParam->cldoFallBypThreshold));

    uint32_t cldoConfig = SRSS_PWR_CONFIG_CLDO;
    cldoConfig = _CLR_SET_FLD32U(cldoConfig, PMU_AUX_PWR_CONFIG_CLDO_CLDO_EN, ((cldoParam->cldoEnable) ? 1UL : 0UL));
    cldoConfig = _CLR_SET_FLD32U(cldoConfig, PMU_AUX_PWR_CONFIG_CLDO_CLDO_LEAKSENSE_EN, ((cldoParam->cldoLeakSenseEnable) ? 1UL : 0UL));
    cldoConfig = _CLR_SET_FLD32U(cldoConfig, PMU_AUX_PWR_CONFIG_CLDO_CLDO_BYP_THRESHOLD, cldoParam->cldoBypThreshold);
    cldoConfig = _CLR_SET_FLD32U(cldoConfig, PMU_AUX_PWR_CONFIG_CLDO_CLDO_BYP_OFFSET, cldoParam->cldoBypOffset);
    cldoConfig = _CLR_SET_FLD32U(cldoConfig, PMU_AUX_PWR_CONFIG_CLDO_CLDO_FALL_BYP_VTH, cldoParam->cldoFallBypThreshold);
    SRSS_PWR_CONFIG_CLDO = cldoConfig;
}

#if defined (SRSS_PMU_CLDO_PRESENT) && (SRSS_PMU_CLDO_PRESENT == 1)
/* Sets the Core LDO output voltage */
void Cy_SysPm_CLDOSetVoltage(cy_en_syspm_cldo_index_t index, cy_en_syspm_cldo_voltage_t voltage)
{
    CY_ASSERT_L3(CY_SYSPM_IS_CLDO_INDEX_VALID(index));
    CY_ASSERT_L3(CY_SYSPM_IS_CLDO_VOLTAGE_VALID(voltage));

    if(index == CY_SYSPM_CLDO_INDEX_DS)
    {
        CY_REG32_CLR_SET(SRSS_PWR_VOLTAGE_TABLE_0, PMU_MAIN_PWR_VOLTAGE_TABLE_0_VOLTAGE_INDEX_CORE_0, voltage);
    }
    else if(index == CY_SYSPM_CLDO_INDEX_ULP)
    {
        CY_REG32_CLR_SET(SRSS_PWR_VOLTAGE_TABLE_1, PMU_MAIN_PWR_VOLTAGE_TABLE_1_VOLTAGE_INDEX_CORE_1, voltage);
    }
    else if(index == CY_SYSPM_CLDO_INDEX_MF)
    {
        CY_REG32_CLR_SET(SRSS_PWR_VOLTAGE_TABLE_2, PMU_MAIN_PWR_VOLTAGE_TABLE_2_VOLTAGE_INDEX_CORE_2, voltage);
    }
    else /* index CY_SYSPM_CLDO_INDEX_LP */
    {
        CY_REG32_CLR_SET(SRSS_PWR_VOLTAGE_TABLE_3, PMU_MAIN_PWR_VOLTAGE_TABLE_3_VOLTAGE_INDEX_CORE_3, voltage);
    }
}
#endif // defined (SRSS_PMU_CLDO_PRESENT) && (SRSS_PMU_CLDO_PRESENT == 1)

#if defined (SRSS_PMU_PALDO_PRESENT) && (SRSS_PMU_PALDO_PRESENT == 1)
/* Configures the PALDO */
void Cy_SysPm_PALDOConfigure(cy_stc_syspm_paldo_params_t *paldoParam)
{
    CY_ASSERT_L3(CY_SYSPM_IS_PALDO_INRUSH_VALID(paldoParam->paldoInrushAdjust));
    CY_ASSERT_L3(CY_SYSPM_IS_PALDO_INRUSH_VALID(paldoParam->paldoInrushDelay));

    CY_REG32_CLR_SET(SRSS_PWR_CONFIG_PALDO_0, PMU_AUX_PWR_CONFIG_PALDO_0_PALDO_INRUSH_ADJUST, paldoParam->paldoInrushAdjust);
    CY_REG32_CLR_SET(SRSS_PWR_CONFIG_PALDO_1, PMU_AUX_PWR_CONFIG_PALDO_1_PALDO_INRUSH_DELAY, paldoParam->paldoInrushDelay);
}


/* Sets the PALDO output voltage */
void Cy_SysPm_PALDOSetVoltage(cy_en_syspm_paldo_control_t control, cy_en_syspm_hvldo_voltage_t voltage)
{
    CY_ASSERT_L3(CY_SYSPM_IS_PALDO_CONTROL_VALID(control));
    CY_ASSERT_L3(CY_SYSPM_IS_HVLDO_VOLTAGE_VALID(voltage));

    if(control == CY_SYSPM_PALDO_WL_0)
    {
        CY_REG32_CLR_SET(SRSS_PWR_PALDO_WL_0, PMU_MAIN_PWR_PALDO_WL_0_PALDO_VOUT, voltage);
    }
    else if(control == CY_SYSPM_PALDO_WL_1)
    {
        CY_REG32_CLR_SET(SRSS_PWR_PALDO_WL_1, PMU_MAIN_PWR_PALDO_WL_1_PALDO_VOUT, voltage);
    }
    else if(control == CY_SYSPM_PALDO_WL_2)
    {
        CY_REG32_CLR_SET(SRSS_PWR_PALDO_WL_2, PMU_MAIN_PWR_PALDO_WL_2_PALDO_VOUT, voltage);
    }
    else /* CY_SYSPM_PALDO_DEFAULT */
    {
        CY_REG32_CLR_SET(SRSS_PWR_PALDO_DEFAULT, PMU_MAIN_PWR_PALDO_DEFAULT_PALDO_VOUT, voltage);
    }
}
#endif // defined (SRSS_PMU_PALDO_PRESENT) && (SRSS_PMU_PALDO_PRESENT == 1)

#if defined (SRSS_PMU_BTLDO_PRESENT) && (SRSS_PMU_BTLDO_PRESENT == 1)
/* Configures the BTLDO */
void Cy_SysPm_BTLDOConfigure( cy_stc_syspm_btldo_params_t *btldoParam)
{
    CY_ASSERT_L3(CY_SYSPM_IS_BTLDO_INRUSH_VALID(btldoParam->btldoInrushAdjust));
    CY_ASSERT_L3(CY_SYSPM_IS_BTLDO_INRUSH_VALID(btldoParam->btldoInrushDelay));

    CY_REG32_CLR_SET(SRSS_PWR_CONFIG_BTLDO_0, PMU_AUX_PWR_CONFIG_BTLDO_0_BTLDO_INRUSH_ADJUST, btldoParam->btldoInrushAdjust);
    CY_REG32_CLR_SET(SRSS_PWR_CONFIG_BTLDO_1, PMU_AUX_PWR_CONFIG_BTLDO_1_BTLDO_INRUSH_DELAY, btldoParam->btldoInrushDelay);
}


/* Sets the BTLDO output voltage */
void Cy_SysPm_BTLDOSetVoltage(cy_en_syspm_btldo_control_t control, cy_en_syspm_hvldo_voltage_t voltage)
{
    CY_ASSERT_L3(CY_SYSPM_IS_BTLDO_CONTROL_VALID(control));
    CY_ASSERT_L3(CY_SYSPM_IS_HVLDO_VOLTAGE_VALID(voltage));

    if(control == CY_SYSPM_BTLDO_WL_0)
    {
        CY_REG32_CLR_SET(SRSS_PWR_BTLDO_WL_0, PMU_MAIN_PWR_BTLDO_WL_0_BTLDO_VOUT, voltage);
    }
    else if(control == CY_SYSPM_BTLDO_WL_1)
    {
        CY_REG32_CLR_SET(SRSS_PWR_BTLDO_WL_1, PMU_MAIN_PWR_BTLDO_WL_1_BTLDO_VOUT, voltage);
    }
    else if(control == CY_SYSPM_BTLDO_WL_2)
    {
        CY_REG32_CLR_SET(SRSS_PWR_BTLDO_WL_2, PMU_MAIN_PWR_BTLDO_WL_2_BTLDO_VOUT, voltage);
    }
    else if(control == CY_SYSPM_BTLDO_BT_0)
    {
        CY_REG32_CLR_SET(SRSS_PWR_BTLDO_BT_0, PMU_MAIN_PWR_BTLDO_BT_0_BTLDO_VOUT, voltage);
    }
    else if(control == CY_SYSPM_BTLDO_BT_1)
    {
        CY_REG32_CLR_SET(SRSS_PWR_BTLDO_BT_1, PMU_MAIN_PWR_BTLDO_BT_1_BTLDO_VOUT, voltage);
    }
    else if(control == CY_SYSPM_BTLDO_BT_2)
    {
        CY_REG32_CLR_SET(SRSS_PWR_BTLDO_BT_2, PMU_MAIN_PWR_BTLDO_BT_2_BTLDO_VOUT, voltage);
    }
    else /* CY_SYSPM_BTLDO_DEFAULT  */
    {
        CY_REG32_CLR_SET(SRSS_PWR_BTLDO_DEFAULT, PMU_MAIN_PWR_BTLDO_DEFAULT_BTLDO_VOUT, voltage);
    }
}
#endif // defined (SRSS_PMU_BTLDO_PRESENT) && (SRSS_PMU_BTLDO_PRESENT == 1)

/* Configures the Switching Regulator */
void Cy_SysPm_SRConfigure( cy_stc_syspm_sr_params_t *srParam)
{
    CY_ASSERT_L3(CY_SYSPM_IS_SR_SS_ADJUST_VALID(srParam->srSoftStartAdj));
    CY_ASSERT_L3(CY_SYSPM_IS_SR_LP_IPEAK_VALID(srParam->srLPIpeak));
    CY_ASSERT_L3(CY_SYSPM_IS_SR_PWM_RAMPGEN_AMPLITUDE_VALID(srParam->srRampAdj));
    CY_ASSERT_L3(CY_SYSPM_IS_SR_R1_VALUE_VALID(srParam->srR1Adj));
    CY_ASSERT_L3(CY_SYSPM_IS_SR_C2_VALUE_VALID(srParam->srC2Adj));
    CY_ASSERT_L3(CY_SYSPM_IS_SR_ZCD_TRIM_VALID(srParam->srZcdTrim));
    CY_ASSERT_L3(CY_SYSPM_IS_SR_OCD_LIMIT_VALID(srParam->srOcdLimit));
    CY_ASSERT_L3(CY_SYSPM_IS_SR_OCD_BLANKTIME_VALID(srParam->srOcdBlank));
    CY_ASSERT_L3(CY_SYSPM_IS_SR_LP_VREF_HIGH_VOLTAGE_OFFSET_VALID(srParam->srLpVrefHighAdj));
    CY_ASSERT_L3(CY_SYSPM_IS_SR_LP_COUNT_LIMIT_VALID(srParam->srLpCntLimit));
    CY_ASSERT_L3(CY_SYSPM_IS_SR_STAGGER_ON_OFF_DELAY_VALID(srParam->srStaggerOnDelay));
    CY_ASSERT_L3(CY_SYSPM_IS_SR_STAGGER_ON_OFF_DELAY_VALID(srParam->srStaggerOffDelay));
    CY_ASSERT_L3(CY_SYSPM_IS_SR_GATE_DRIVE_STRENGTH_VALID(srParam->srDriveStrnp));
    CY_ASSERT_L3(CY_SYSPM_IS_SR_GATE_DRIVE_STRENGTH_VALID(srParam->srDriveStrnn));
    CY_ASSERT_L3(CY_SYSPM_IS_SR_GATE_DRIVE_STRENGTH_VALID(srParam->srDriveStrpp));
    CY_ASSERT_L3(CY_SYSPM_IS_SR_GATE_DRIVE_STRENGTH_VALID(srParam->srDriveStrpn));
    CY_ASSERT_L3(CY_SYSPM_IS_SR_NOL_OFF_DELAY_VALID(srParam->srNOffDelay));
    CY_ASSERT_L3(CY_SYSPM_IS_SR_NOL_OFF_DELAY_VALID(srParam->srPOffDelay));

    uint32_t srConfig = SRSS_PWR_CONFIG_SR_0;
    srConfig = _CLR_SET_FLD32U(srConfig, PMU_AUX_PWR_CONFIG_SR_0_SR_EN, ((srParam->srEnable) ? 1UL : 0UL));
    srConfig = _CLR_SET_FLD32U(srConfig, PMU_AUX_PWR_CONFIG_SR_0_SR_SS_ADJ, srParam->srSoftStartAdj);
    srConfig = _CLR_SET_FLD32U(srConfig, PMU_AUX_PWR_CONFIG_SR_0_SR_LP_IPEAK, srParam->srLPIpeak);
    srConfig = _CLR_SET_FLD32U(srConfig, PMU_AUX_PWR_CONFIG_SR_0_SR_RAMP_ADJ, srParam->srRampAdj);
    srConfig = _CLR_SET_FLD32U(srConfig, PMU_AUX_PWR_CONFIG_SR_0_SR_DIS_COMP_LATCH, ((srParam->srDisCompLatch) ? 1UL : 0UL));
    srConfig = _CLR_SET_FLD32U(srConfig, PMU_AUX_PWR_CONFIG_SR_0_SR_MAINCOMP_RATIO, ((srParam->srMainCompRatio) ? 1UL : 0UL));
    srConfig = _CLR_SET_FLD32U(srConfig, PMU_AUX_PWR_CONFIG_SR_0_SR_MAINCOMP_LP_DIS, ((srParam->srMainCompLpDis) ? 1UL : 0UL));
    srConfig = _CLR_SET_FLD32U(srConfig, PMU_AUX_PWR_CONFIG_SR_0_SR_R1_ADJ, srParam->srR1Adj);
    srConfig = _CLR_SET_FLD32U(srConfig, PMU_AUX_PWR_CONFIG_SR_0_SR_C2_ADJ, srParam->srC2Adj);
    srConfig = _CLR_SET_FLD32U(srConfig, PMU_AUX_PWR_CONFIG_SR_0_SR_ZCD_TRIM, srParam->srZcdTrim);
    srConfig = _CLR_SET_FLD32U(srConfig, PMU_AUX_PWR_CONFIG_SR_0_SR_DIS_OCD, ((srParam->srDisOcd) ? 1UL : 0UL));
    srConfig = _CLR_SET_FLD32U(srConfig, PMU_AUX_PWR_CONFIG_SR_0_SR_OCD_LIMIT, srParam->srOcdLimit);
    srConfig = _CLR_SET_FLD32U(srConfig, PMU_AUX_PWR_CONFIG_SR_0_SR_OCD_COUNT, ((srParam->srOcdCount) ? 1UL : 0UL));
    srConfig = _CLR_SET_FLD32U(srConfig, PMU_AUX_PWR_CONFIG_SR_0_SR_OCD_BLANK, srParam->srOcdBlank);
    srConfig = _CLR_SET_FLD32U(srConfig, PMU_AUX_PWR_CONFIG_SR_0_SR_OCD_DIS_DLY, ((srParam->srOcdResetMethod) ? 1UL : 0UL));
    SRSS_PWR_CONFIG_SR_0 = srConfig;

    srConfig = SRSS_PWR_CONFIG_SR_1;
    srConfig = _CLR_SET_FLD32U(srConfig, PMU_AUX_PWR_CONFIG_SR_1_SR_LP_VREF_HIGH_ADJ, srParam->srLpVrefHighAdj);
    srConfig = _CLR_SET_FLD32U(srConfig, PMU_AUX_PWR_CONFIG_SR_1_SR_LP_CNT_LIMIT, srParam->srLpCntLimit);
    srConfig = _CLR_SET_FLD32U(srConfig, PMU_AUX_PWR_CONFIG_SR_1_SR_STGON_DLY, srParam->srStaggerOnDelay);
    srConfig = _CLR_SET_FLD32U(srConfig, PMU_AUX_PWR_CONFIG_SR_1_SR_STGOFF_DLY, srParam->srStaggerOffDelay);
    srConfig = _CLR_SET_FLD32U(srConfig, PMU_AUX_PWR_CONFIG_SR_1_SR_DRV_STRNP, srParam->srDriveStrnp);
    srConfig = _CLR_SET_FLD32U(srConfig, PMU_AUX_PWR_CONFIG_SR_1_SR_DRV_STRNN, srParam->srDriveStrnn);
    srConfig = _CLR_SET_FLD32U(srConfig, PMU_AUX_PWR_CONFIG_SR_1_SR_DRV_STRPP, srParam->srDriveStrpp);
    srConfig = _CLR_SET_FLD32U(srConfig, PMU_AUX_PWR_CONFIG_SR_1_SR_DRV_STRPN, srParam->srDriveStrpn);
    srConfig = _CLR_SET_FLD32U(srConfig, PMU_AUX_PWR_CONFIG_SR_1_SR_NOFF_DLY, srParam->srNOffDelay);
    srConfig = _CLR_SET_FLD32U(srConfig, PMU_AUX_PWR_CONFIG_SR_1_SR_POFF_DLY, srParam->srPOffDelay);
    srConfig = _CLR_SET_FLD32U(srConfig, PMU_AUX_PWR_CONFIG_SR_1_SR_VLX_FORCE_EN, ((srParam->srVlxForceEn) ? 1UL : 0UL));
    srConfig = _CLR_SET_FLD32U(srConfig, PMU_AUX_PWR_CONFIG_SR_1_SR_VLX_FORCE_SEL, ((srParam->srVlxForceSel) ? 1UL : 0UL));
    srConfig = _CLR_SET_FLD32U(srConfig, PMU_AUX_PWR_CONFIG_SR_1_SRFREQ_OVERRIDE, ((srParam->srFreqOverride) ? 1UL : 0UL));
    SRSS_PWR_CONFIG_SR_1 = srConfig;
}

/* Sets the Switching Regulator output voltage */
void Cy_SysPm_SRSetVoltage(cy_en_syspm_sr_index_t index, cy_en_syspm_sr_voltage_t voltage)
{
    CY_ASSERT_L3(CY_SYSPM_IS_SR_INDEX_VALID(index));
    CY_ASSERT_L3(CY_SYSPM_IS_SR_VOLTAGE_VALID(voltage));

    if(index == CY_SYSPM_SR_INDEX_DS)
    {
        CY_REG32_CLR_SET(SRSS_PWR_VOLTAGE_TABLE_0, PMU_MAIN_PWR_VOLTAGE_TABLE_0_VOLTAGE_INDEX_SR_0, voltage);
    }
    else if(index == CY_SYSPM_SR_INDEX_ULP)
    {
        CY_REG32_CLR_SET(SRSS_PWR_VOLTAGE_TABLE_1, PMU_MAIN_PWR_VOLTAGE_TABLE_1_VOLTAGE_INDEX_SR_1, voltage);
    }
    else if(index == CY_SYSPM_SR_INDEX_MF)
    {
        CY_REG32_CLR_SET(SRSS_PWR_VOLTAGE_TABLE_2, PMU_MAIN_PWR_VOLTAGE_TABLE_2_VOLTAGE_INDEX_SR_2, voltage);
    }
    else if(index == CY_SYSPM_SR_INDEX_LP)
    {
        CY_REG32_CLR_SET(SRSS_PWR_VOLTAGE_TABLE_3, PMU_MAIN_PWR_VOLTAGE_TABLE_3_VOLTAGE_INDEX_SR_3, voltage);
    }
    else if(index == CY_SYSPM_SR_INDEX_BEACON_RX)
    {
        CY_REG32_CLR_SET(SRSS_PWR_VOLTAGE_TABLE_4, PMU_MAIN_PWR_VOLTAGE_TABLE_4_VOLTAGE_INDEX_SR_4, voltage);
    }
    else /* CY_SYSPM_SR_INDEX_RF_0, CY_SYSPM_SR_INDEX_RF_1, CY_SYSPM_SR_INDEX_RF_2 */
    {
        CY_REG32_CLR_SET(SRSS_PWR_VOLTAGE_TABLE_4, PMU_MAIN_PWR_VOLTAGE_TABLE_4_VOLTAGE_INDEX_SR_5, voltage);
    }
}


/* Configures the Switching Regulator Frequency Control */
void Cy_SysPm_SRFrequencyControlConfigure(cy_en_syspm_sr_frequency_control_type_t control, cy_stc_syspm_sr_freq_params_t *srFreqParam)
{
    CY_ASSERT_L3(CY_SYSPM_IS_SR_FREQUENCY_CONTROL_VALID(control));
    CY_ASSERT_L3(CY_SYSPM_IS_SR_MAINCOMP_HYST_VALID(srFreqParam->srMainCompHysteresis));
    CY_ASSERT_L3(CY_SYSPM_IS_SR_LPCOMP_HYST_VALID(srFreqParam->srLpCompHysteresis));

    uint32_t srFrequencyControl = 0;

    if(control == CY_SYSPM_SR_FREQ_WL_A)
    {
        srFrequencyControl = SRSS_PWR_SRFREQ_WL_A;
        srFrequencyControl = _CLR_SET_FLD32U(srFrequencyControl, PMU_MAIN_PWR_SRFREQ_WL_A_BG_CHOP_DISABLE, ((srFreqParam->bgChopDisable) ? 1UL : 0UL));
        srFrequencyControl = _CLR_SET_FLD32U(srFrequencyControl, PMU_MAIN_PWR_SRFREQ_WL_A_OSC4M_FREQ_SEL, ((srFreqParam->oscFreqSelect) ? 1UL : 0UL));
        srFrequencyControl = _CLR_SET_FLD32U(srFrequencyControl, PMU_MAIN_PWR_SRFREQ_WL_A_SR_FSW_DIV2, ((srFreqParam->srFreqDiv2) ? 1UL : 0UL));
        srFrequencyControl = _CLR_SET_FLD32U(srFrequencyControl, PMU_MAIN_PWR_SRFREQ_WL_A_SR_MAINCOMP_HYST, srFreqParam->srMainCompHysteresis);
        srFrequencyControl = _CLR_SET_FLD32U(srFrequencyControl, PMU_MAIN_PWR_SRFREQ_WL_A_SR_LPCOMP_HYST, srFreqParam->srLpCompHysteresis);
        SRSS_PWR_SRFREQ_WL_A = srFrequencyControl;
    }
    else if(control == CY_SYSPM_SR_FREQ_WL_B)
    {
        srFrequencyControl = SRSS_PWR_SRFREQ_WL_B;
        srFrequencyControl = _CLR_SET_FLD32U(srFrequencyControl, PMU_MAIN_PWR_SRFREQ_WL_B_BG_CHOP_DISABLE, ((srFreqParam->bgChopDisable) ? 1UL : 0UL));
        srFrequencyControl = _CLR_SET_FLD32U(srFrequencyControl, PMU_MAIN_PWR_SRFREQ_WL_B_OSC4M_FREQ_SEL, ((srFreqParam->oscFreqSelect) ? 1UL : 0UL));
        srFrequencyControl = _CLR_SET_FLD32U(srFrequencyControl, PMU_MAIN_PWR_SRFREQ_WL_B_SR_FSW_DIV2, ((srFreqParam->srFreqDiv2) ? 1UL : 0UL));
        srFrequencyControl = _CLR_SET_FLD32U(srFrequencyControl, PMU_MAIN_PWR_SRFREQ_WL_B_SR_MAINCOMP_HYST, srFreqParam->srMainCompHysteresis);
        srFrequencyControl = _CLR_SET_FLD32U(srFrequencyControl, PMU_MAIN_PWR_SRFREQ_WL_B_SR_LPCOMP_HYST, srFreqParam->srLpCompHysteresis);
        SRSS_PWR_SRFREQ_WL_B = srFrequencyControl;
    }
    else if(control == CY_SYSPM_SR_FREQ_BT_A)
    {
        srFrequencyControl = SRSS_PWR_SRFREQ_BT_A;
        srFrequencyControl = _CLR_SET_FLD32U(srFrequencyControl, PMU_MAIN_PWR_SRFREQ_BT_A_BG_CHOP_DISABLE, ((srFreqParam->bgChopDisable) ? 1UL : 0UL));
        srFrequencyControl = _CLR_SET_FLD32U(srFrequencyControl, PMU_MAIN_PWR_SRFREQ_BT_A_OSC4M_FREQ_SEL, ((srFreqParam->oscFreqSelect) ? 1UL : 0UL));
        srFrequencyControl = _CLR_SET_FLD32U(srFrequencyControl, PMU_MAIN_PWR_SRFREQ_BT_A_SR_FSW_DIV2, ((srFreqParam->srFreqDiv2) ? 1UL : 0UL));
        srFrequencyControl = _CLR_SET_FLD32U(srFrequencyControl, PMU_MAIN_PWR_SRFREQ_BT_A_SR_MAINCOMP_HYST, srFreqParam->srMainCompHysteresis);
        srFrequencyControl = _CLR_SET_FLD32U(srFrequencyControl, PMU_MAIN_PWR_SRFREQ_BT_A_SR_LPCOMP_HYST, srFreqParam->srLpCompHysteresis);
        SRSS_PWR_SRFREQ_BT_A = srFrequencyControl;
    }
    else if(control == CY_SYSPM_SR_FREQ_BT_B)
    {
        srFrequencyControl = SRSS_PWR_SRFREQ_BT_B;
        srFrequencyControl = _CLR_SET_FLD32U(srFrequencyControl, PMU_MAIN_PWR_SRFREQ_BT_B_BG_CHOP_DISABLE, ((srFreqParam->bgChopDisable) ? 1UL : 0UL));
        srFrequencyControl = _CLR_SET_FLD32U(srFrequencyControl, PMU_MAIN_PWR_SRFREQ_BT_B_OSC4M_FREQ_SEL, ((srFreqParam->oscFreqSelect) ? 1UL : 0UL));
        srFrequencyControl = _CLR_SET_FLD32U(srFrequencyControl, PMU_MAIN_PWR_SRFREQ_BT_B_SR_FSW_DIV2, ((srFreqParam->srFreqDiv2) ? 1UL : 0UL));
        srFrequencyControl = _CLR_SET_FLD32U(srFrequencyControl, PMU_MAIN_PWR_SRFREQ_BT_B_SR_MAINCOMP_HYST, srFreqParam->srMainCompHysteresis);
        srFrequencyControl = _CLR_SET_FLD32U(srFrequencyControl, PMU_MAIN_PWR_SRFREQ_BT_B_SR_LPCOMP_HYST, srFreqParam->srLpCompHysteresis);
        SRSS_PWR_SRFREQ_BT_B = srFrequencyControl;
    }
    else /* CY_SYSPM_SR_FREQ_DEFAULT */
    {
        srFrequencyControl = SRSS_PWR_SRFREQ_DEFAULT;
        srFrequencyControl = _CLR_SET_FLD32U(srFrequencyControl, PMU_MAIN_PWR_SRFREQ_DEFAULT_BG_CHOP_DISABLE, ((srFreqParam->bgChopDisable) ? 1UL : 0UL));
        srFrequencyControl = _CLR_SET_FLD32U(srFrequencyControl, PMU_MAIN_PWR_SRFREQ_DEFAULT_OSC4M_FREQ_SEL, ((srFreqParam->oscFreqSelect) ? 1UL : 0UL));
        srFrequencyControl = _CLR_SET_FLD32U(srFrequencyControl, PMU_MAIN_PWR_SRFREQ_DEFAULT_SR_FSW_DIV2, ((srFreqParam->srFreqDiv2) ? 1UL : 0UL));
        srFrequencyControl = _CLR_SET_FLD32U(srFrequencyControl, PMU_MAIN_PWR_SRFREQ_DEFAULT_SR_MAINCOMP_HYST, srFreqParam->srMainCompHysteresis);
        srFrequencyControl = _CLR_SET_FLD32U(srFrequencyControl, PMU_MAIN_PWR_SRFREQ_DEFAULT_SR_LPCOMP_HYST, srFreqParam->srLpCompHysteresis);
        SRSS_PWR_SRFREQ_DEFAULT = srFrequencyControl;
    }
}


/* Configures the Switching Regulator Frequency Control Priority */
void Cy_SysPm_SRFrequencyPriorityConfigure(cy_stc_syspm_sr_freq_priority_params_t *srFreqPriorityParam)
{
    uint32_t srFrequencyPriority = SRSS_PWR_SRFREQ_PRIORITY;
    srFrequencyPriority = _CLR_SET_FLD32U(srFrequencyPriority, PMU_MAIN_PWR_SRFREQ_PRIORITY_BG_CHOP_PRIORITY, ((srFreqPriorityParam->bgChopPriority) ? 1UL : 0UL));
    srFrequencyPriority = _CLR_SET_FLD32U(srFrequencyPriority, PMU_MAIN_PWR_SRFREQ_PRIORITY_OSC4M_FREQ_PRIORITY, ((srFreqPriorityParam->osc4mFreqPriority) ? 1UL : 0UL));
    srFrequencyPriority = _CLR_SET_FLD32U(srFrequencyPriority, PMU_MAIN_PWR_SRFREQ_PRIORITY_SR_FSW_DIV2_PRIORITY, ((srFreqPriorityParam->srFswDiv2Priority) ? 1UL : 0UL));
    srFrequencyPriority = _CLR_SET_FLD32U(srFrequencyPriority, PMU_MAIN_PWR_SRFREQ_PRIORITY_MAINCOMP_HYST_PRIORITY, ((srFreqPriorityParam->mainCompHystPriority) ? 1UL : 0UL));
    srFrequencyPriority = _CLR_SET_FLD32U(srFrequencyPriority, PMU_MAIN_PWR_SRFREQ_PRIORITY_LPCOMP_HYST_PRIORITY, ((srFreqPriorityParam->lpCompHystPriority) ? 1UL : 0UL));
    SRSS_PWR_SRFREQ_PRIORITY = srFrequencyPriority;
}



/* Configures the Switching Regulator Threshold */
void Cy_SysPm_SRThresholdConfigure(cy_stc_syspm_sr_threshold_params_t *srThresholdParam)
{
    CY_ASSERT_L3(CY_SYSPM_IS_SR_LOAD_CURRENT_THRESHOLD_VALID(srThresholdParam->currentThreshold2Slice));
    CY_ASSERT_L3(CY_SYSPM_IS_SR_LOAD_CURRENT_THRESHOLD_VALID(srThresholdParam->currentThreshold3Slice));
    CY_ASSERT_L3(CY_SYSPM_IS_SR_LOAD_CURRENT_THRESHOLD_VALID(srThresholdParam->currentThreshold4Slice));
    CY_ASSERT_L3(CY_SYSPM_IS_SR_LOAD_CURRENT_THRESHOLD_VALID(srThresholdParam->currentThreshold5Slice));
    CY_ASSERT_L3(CY_SYSPM_IS_SR_VOLTAGE_VALID(srThresholdParam->srPokThreshold));

    uint32_t srThreshold = SRSS_PWR_SR_THRESHOLD;
    srThreshold = _CLR_SET_FLD32U(srThreshold, PMU_MAIN_PWR_SR_THRESHOLD_CURRENT_THRESHOLD_2SLICE, srThresholdParam->currentThreshold2Slice);
    srThreshold = _CLR_SET_FLD32U(srThreshold, PMU_MAIN_PWR_SR_THRESHOLD_CURRENT_THRESHOLD_3SLICE, srThresholdParam->currentThreshold3Slice);
    srThreshold = _CLR_SET_FLD32U(srThreshold, PMU_MAIN_PWR_SR_THRESHOLD_CURRENT_THRESHOLD_4SLICE, srThresholdParam->currentThreshold4Slice);
    srThreshold = _CLR_SET_FLD32U(srThreshold, PMU_MAIN_PWR_SR_THRESHOLD_CURRENT_THRESHOLD_5SLICE, srThresholdParam->currentThreshold5Slice);
    srThreshold = _CLR_SET_FLD32U(srThreshold, PMU_MAIN_PWR_SR_THRESHOLD_SR_POK_THRESHOLD, srThresholdParam->srPokThreshold);
    SRSS_PWR_SR_THRESHOLD = srThreshold;
}


/* Configures the PMU Voltage Sense Control */
void Cy_SysPm_PMUVoltageSenseControlConfigure(cy_stc_syspm_pmu_voltage_sense_params_t *pmuVoltSenseParam)
{
    CY_ASSERT_L3(CY_SYSPM_IS_RLADDER_MUX_SELECT_VALID(pmuVoltSenseParam->rLadderMuxSelect));

    uint32_t senseControl = SRSS_PWR_SENSE_CONTROL;
    senseControl = _CLR_SET_FLD32U(senseControl, PMU_MAIN_PWR_SENSE_CONTROL_RLADDER_MUX_SELECT, pmuVoltSenseParam->rLadderMuxSelect);
    senseControl = _CLR_SET_FLD32U(senseControl, PMU_MAIN_PWR_SENSE_CONTROL_PALDO_OVERRIDE, ((pmuVoltSenseParam->paldoOverride) ? 1UL : 0UL));
    senseControl = _CLR_SET_FLD32U(senseControl, PMU_MAIN_PWR_SENSE_CONTROL_BTLDO_OVERRIDE, ((pmuVoltSenseParam->btldoOverride) ? 1UL : 0UL));
    SRSS_PWR_SENSE_CONTROL = senseControl;
}


/* Configures the PMU Sleep Target Settings */
void Cy_SysPm_PMUSleepTargetConfigure(cy_stc_syspm_pmu_sleep_target_params_t *pmuSleepTargetParam)
{
    CY_ASSERT_L3(CY_SYSPM_IS_CLDO_INDEX_VALID(pmuSleepTargetParam->sleepCoreTargetIndex));
    CY_ASSERT_L3(CY_SYSPM_IS_SR_INDEX_VALID(pmuSleepTargetParam->sleepSrTargetIndex));
    CY_ASSERT_L3(CY_SYSPM_IS_SR_LOAD_CURRENT_THRESHOLD_VALID(pmuSleepTargetParam->sleepSrTargetLoad));
    CY_ASSERT_L3(CY_SYSPM_IS_SR_TARGET_MODE_VALID(pmuSleepTargetParam->sleepSrTargetMode));

    uint32_t sleepTarget = SRSS_PWR_SLEEP_TARGET;
    sleepTarget = _CLR_SET_FLD32U(sleepTarget, PMU_MAIN_PWR_SLEEP_TARGET_SLEEP_CORE_TARGET_INDEX, pmuSleepTargetParam->sleepCoreTargetIndex);
    sleepTarget = _CLR_SET_FLD32U(sleepTarget, PMU_MAIN_PWR_SLEEP_TARGET_SLEEP_SR_TARGET_INDEX, pmuSleepTargetParam->sleepSrTargetIndex);
    sleepTarget = _CLR_SET_FLD32U(sleepTarget, PMU_MAIN_PWR_SLEEP_TARGET_SLEEP_SR_TARGET_LOAD, pmuSleepTargetParam->sleepSrTargetLoad);
    sleepTarget = _CLR_SET_FLD32U(sleepTarget, PMU_MAIN_PWR_SLEEP_TARGET_SLEEP_SR_TARGET_MODE, pmuSleepTargetParam->sleepSrTargetMode);
    SRSS_PWR_SLEEP_TARGET = sleepTarget;
}


/* Configures the SR trim settings */
void Cy_SysPm_SRTrimConfigure(cy_stc_syspm_sr_trim_params_t *srTrimParam)
{
    CY_ASSERT_L3(CY_SYSPM_IS_SR_PWM_PFM_TRIM_VALID(srTrimParam->srPwmPfmTrim));
    CY_ASSERT_L3(CY_SYSPM_IS_SR_LPPFM_TRIM_VALID(srTrimParam->srLPPfmTrim));
    CY_ASSERT_L3(CY_SYSPM_IS_SR_LP_TRIM_VALID(srTrimParam->srLPTrim));

    CY_REG32_CLR_SET(SRSS_PWR_TRIM_SR_0, PMU_AUX_PWR_TRIM_SR_0_SR_PWM_PFM_TRIM, srTrimParam->srPwmPfmTrim);
    CY_REG32_CLR_SET(SRSS_PWR_TRIM_SR_1, PMU_AUX_PWR_TRIM_SR_1_SR_LPPFM_TRIM, srTrimParam->srLPPfmTrim);
    CY_REG32_CLR_SET(SRSS_PWR_TRIM_SR_2, PMU_AUX_PWR_TRIM_SR_2_SR_LP_TRIM, srTrimParam->srLPTrim);
}

#endif /* defined(CY_IP_MXS22SRSS) && defined(CY_IP_MXS22SRSS_VERSION) && (CY_IP_MXS22SRSS_VERSION == 2) && (CY_IP_MXS22SRSS_VERSION_MINOR == 1) */


/* [] END OF FILE */
