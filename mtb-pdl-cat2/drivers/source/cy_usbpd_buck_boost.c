/***************************************************************************//**
* \file cy_usbpd_buck_boost.c
* \version 2.110
*
* The source file of the USBPD Buck Boost Driver.
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
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either expressed or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

#include "cy_device.h"
#include "cy_device_headers.h"
#include "cy_usbpd_common.h"

#if (defined(CY_IP_MXUSBPD) || defined(CY_IP_M0S8USBPD))
#include "cy_usbpd_config_table.h"
#include "cy_sysclk.h"
#include "cy_usbpd_typec.h"
#include "cy_usbpd_vbus_ctrl.h"
#include "cy_usbpd_idac_ctrl.h"

#include "cy_usbpd_defines.h"
#include "cy_usbpd_buck_boost.h"

/* Buck-Boost (BB) clock frequency in kHz */
#if PSVP_FPGA_ENABLE
#define HFCLK_KHZ                               (26000u)
#else
#define HFCLK_KHZ                              (Cy_SysClk_ClkHfGetFrequency() / 1000u)
#endif /* PSVP_FPGA_ENABLE */
#define BBCLK_KHZ                               (HFCLK_KHZ / (Cy_SysClk_PeriphGetDivider(CY_SYSCLK_DIV_8_BIT, 6U) + (uint32_t)1u))
#define BBCLK_MHZ                              (BBCLK_KHZ / 1000u)

#define VBUS_C_20_PER_DIV                   (5u)       /* 20% */
#define VBUS_C_10_PER_DIV                   (10u)      /* 10% */
#define VBUS_C_8_PER_DIV                    (12u)      /* APPROX 8% */

/*
 * Conversion algorithm for frequency in KHz to time in units of BB clock 
 * cycle numbers.
 */
#define FREQ_KHZ_TO_CYCLE_TIME(freq)            ((BBCLK_KHZ) / (freq))

/*
 * Conversion algorithm for nanoseconds to time in units of BB clock 
 * cycle numbers.
 */
#define NS_TO_BBCLK_CYCLE_CNT(ns)                    ((BBCLK_MHZ * (ns)) / 1000u)

/* EA_OUT Pull Down bit position in T_EA field */
#define BB_EA_2_CTRL_BB_EA_T_EA_OUT_PD_POS  (15u)

/* Fixed PWM duty (in %) for EA BB Boost mode. */
#define BB_BOOST_PWM_DUTY_PER               (70u)

/* Fixed PWM duty (in %) for EA BB Buck mode. */
#define BB_BUCK_PWM_DUTY_PER                (25u)

/*
 * Time interval for which BB need to stay in IDLE mode,
 * while transitioning from soft start to normal/EA mode
 */
#if PSVP_FPGA_ENABLE
#define BB_IDLE_TIMER_PERIOD_MS             (3u)
#else /* !PSVP_FPGA_ENABLE */
#define BB_IDLE_TIMER_PERIOD_MS             (1u)
#endif /* PSVP_FPGA_ENABLE */

/*
 * Time interval for which BB need to stay PSM mode
 * before switching to FCCM once EA mode is enabled
 * during startup.
 */
#define BB_STARTUP_DONE_TIMER_PERIOD_MS     (2u)

/*
 * Lower voltage threshold (mV) to start soft start,
 * otherwise EA mode is enabled.
 */
#define BB_SOFT_START_THRESHOLD             (4500u)

/* BB soft start cut off voltage (mV) to transition to normal mode */
#if PSVP_FPGA_ENABLE
#define BB_SOFT_START_CUTOFF                (7000u)
#else /* !PSVP_FPGA_ENABLE */
#define BB_SOFT_START_CUTOFF                (3000u)
#endif /* PSVP_FPGA_ENABLE */

/* Minimum VIN voltage required to turn on buck-boost regulation */
#if PSVP_FPGA_ENABLE
#define BB_ENABLE_VIN_MIN_VOLT              (5500u)
#else /* !PSVP_FPGA_ENABLE */
#define BB_ENABLE_VIN_MIN_VOLT              (5000u)
#endif /* PSVP_FPGA_ENABLE */

/* VBUS_IN drive strength corresponding to 125Ohm */
#define BB_STARTUP_VBUS_IN_DS               (16u)

/* IDAC SRC value for 3.3V */
#define BB_IDAC_SRC_3_3_V                   (85u)

/* BB Forced Continuous/Current Conduction Mode */
#define BB_MODE_FCCM                        (4u)

/* BB Pulse Skip Mode */
#define BB_MODE_PSM                         (3u)

/* Buck-Boost operating modes */
#define BB_BUCK_BOOST                       (0u)
#define BB_FORCED_BUCK                      (1u)
#define BB_FORCED_BOOST                     (2u)

/*
 * Macro to disable FCCM during VBTR/IBTR.
 * Applicable only in FCCM mode.
 */
#define BB_VBTR_IBTR_FCCM_DIS               (0u)

/*
 * Macro calculate percentage w.r.t PWM period
 * for the requested phase angle.
 */
#define BB_PHASE_ANGLE_TO_PER(deg)          (((deg) * (100u)) / (360u))

/* Fixed Gain settings */
#define ILIM_DET_GAIN                           (10u)
#define CC_GAIN_80                              (80u)
#define CC_GAIN_80_AV1_VALUE                    (4u)
#define CC_GAIN_60                              (60u)
#define CC_GAIN_60_AV1_VALUE                    (2u)
#define OCP_GAIN_VALUE                          (40u)
#define SCP_GAIN_VALUE                          (20u)
#define CSA_GAIN_VALUE_LOW                      (40u)
#define CSA_GAIN_VALUE_HIGH                     (150u)


/* PSVP only configuration to generate AFE FW with less min duty to observe ASYNC mode operation. */
#define PSVP_LESS_MIN_DUTY (0u)

#if PDL_BB_ILIM_DET_ENABLE

/* Maximum iLim detection current in 10mA units */
#define ILIM_DET_MAX_CURRENT    (4000u)

#endif /* PDL_BB_ILIM_DET_ENABLE */

/*
 * Default iLim reference for buck-boost hardware IP. (10mA units)
 * Firmware based iLim reference shall be configured
 * using configuration utility parameter.
 */
#define ILIM_DET_REF_CUR                        (1000u)

/* iLim reference has 200mV offset. This macro defines offset in 10mV steps. */
#define ILIM_DET_REF_OFFSET                     (20u)

#if PDL_VREG_INRUSH_DET_ENABLE
/* Inrush fault is common for device. */

/*
 * Vreg inrush detect enable delay in mS.
 * Vreg inrush fault detection has to be disabled and re-enabled back
 * during buck-boost enable or Vconn enable.
 * Because, sudden Inrush on 40Vreg is expected during these operations.
 */
#define PD_VREG_INRUSH_DET_EN_DELAY_MS          (50u)

#endif /* PDL_VREG_INRUSH_DET_ENABLE */

#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))

/* To monitor VBUS_IN while enabling buck-boost. */
#define BB_SAFE_VBUS_IN_EN                  (1u)

/* Buck-boost startup monitor timer period in ms */
#define BB_STARTUP_MONITOR_TIMER_PERIOD     (250u)

/*
 * Safe VBUS_IN voltage, which is Vout to buck-boost 
 * needed to enable Buck-Boost soft start enable sequence.
 */
#if BB_SAFE_VBUS_IN_EN
#define BB_SAFE_VBUS_IN_LEVEL               (2500u)
#define BB_SAFE_VBUS_IN_TIMER_MS            (1u)
#define BB_SAFE_VBUS_IN_DISCHG_DS           (16u)
#endif /* BB_SAFE_VBUS_IN_EN */

/* EA_OUT Pull Down bit position in T_EA field */
#define BB_EA_2_CTRL_BB_EA_T_EA_OUT_PD_POS  (15u)

/* Spread Spectrum initial value field */
#define BBCTRL_FF_SPRD_CTRL_LFSR_INIT_INIT_VAL_POS      (3u)
#define BBCTRL_FF_SPRD_CTRL_LFSR_INIT_INIT_VAL_MASK     (0x000007F8u)

/* Spread Spectrum percentage value field */
#define BBCTRL_FF_SPRD_CTRL_LFSR_INIT_PER_POS           (11u)
#define BBCTRL_FF_SPRD_CTRL_LFSR_INIT_PER_MASK          (0x0000f800u)
#define BBCTRL_FF_SPRD_CTRL_LFSR_INIT_PER_MAX           (31u)
#define BB_DITHERING_MAX_SPREAD                         (BBCTRL_FF_SPRD_CTRL_LFSR_INIT_PER_MAX * 2u)

/* Spread Spectrum cycle-to-cycle variation limit value field */
#define BBCTRL_FF_SPRD_CTRL_LFSR_INIT_C2C_VAR_POS       (16u)
#define BBCTRL_FF_SPRD_CTRL_LFSR_INIT_C2C_VAR_MASK      (0x00070000u)

/* AMUX settings for < 9V VBUS_IN */

/* 20% VBUS_IN AMUX selection bit for OV comparator */
#define AMUX_NHVN_OV_VBUS_IN_20_PER_POS     (2u)

/* 20% VBUS_IN AMUX selection bit for OV comparator */
#define AMUX_OV_VBUS_IN_20_PER_POS          (7u)

/* Defines clock cycles for minimum duty cycle possible */
#define BB_HS1_LS2_MIN_DUTY_CYCLE_CLK       (6u)

/* 
 * Defines clock cycles offset from number of BB_CLK cycles 
 * for maximum duty cycle. 
 */
#define BB_HS1_LS2_MAX_DUTY_CYCLE_CLK_OFST  (3u)

/* Slope comp Inductor and Resistor values for 24x, in nH and uOhm units */
#define BB_SLOPE_COMP_24X                   (24u)
#define BB_SLOPE_COMP_24X_L                 (6800u)
#define BB_SLOPE_COMP_24X_R                 (5000u)

/* 
 * Time interval for which BB need to stay PSM mode
 * before switching to FCCM once EA mode is enabled
 * during startup.
 */
#define BB_STARTUP_DONE_TIMER_PERIOD_MS     (2u)

#define BB_SOFT_START_CUTOFF_OFCT           (500u)

#if APP_VBUS_SRC_FET_BYPASS_EN
#define BB_SOFT_START_MON_TIMER_MS          (1u)
#define BB_SOFT_START_DUTY_STEP_UP_PER      (1u)
#endif /* APP_VBUS_SRC_FET_BYPASS_EN */

/* Buck-Boost dithering modes */
#if (PSVP_FPGA_ENABLE)
#define BB_DITHER_DIS                        (0u)
#else
#define BB_DITHER_DIS                        (3u)
#endif /* (PSVP_FPGA_ENABLE) */

#define BB_DITHER_TRIANGLE                  (0u)
#define BB_DITHER_PSEUDO_RANDOM             (1u)

/********************************************************************
 ************* Buck-Boost Module Configurations**********************
 *******************************************************************/
/* GDRVO HSRCP Output Leading Edge Blanking Configuration */
#define BB_GDRVO_2_LEB_TIME_CONFIG_WEAK         ((uint32_t)0x7776u)
#define BB_GDRVO_2_LEB_TIME_CONFIG_STRONG       ((uint32_t)0x7576u)
#define BB_GDRVO_2_LEB_TIME_CONFIG_STRONG_PMG1B1    ((uint32_t)0x7574u)
/* HS1 Fixed Duty Cycle */
#define HS1_MAX_DUTY_CYCLE_PERC                 (80u)

/* LS2 Fixed Duty Cycle */
#define LS2_MIN_DUTY_CYCLE_PERC                 (20u)

/* HS1 Fixed Duty cycle for Boost configuration
 * ((1/freq) * D/100)sec = ((1000/freq_khz)*D/100)us = ((10000/freq_khz)*D)ns */
#define BB_HS1_FIXED_DUTY_CYCLE_BOOST_NS(freq)  ((10000u/freq) * HS1_MAX_DUTY_CYCLE_PERC)

/* LS2 Fixed Duty cycle for Buck configuration */
#define BB_LS2_FIXED_DUTY_CYCLE_BUCK_NS(freq)   ((10000u/freq) * LS2_MIN_DUTY_CYCLE_PERC)

/* Overriding RCP trim configuration value in FCCM mode */
#define BB_GDRVO_1_TRIM_HSRCP_VAL               (0x3Fu)

/* Overriding RCP trim configuration value FCCM mode for PMG1B1 */
#define BB_GDRVO_1_TRIM_HSRCP_VAL_PMG1B1        (0x2Cu)

static uint16_t Cy_USBPD_BB_GetFixFreq(cy_stc_usbpd_context_t *context)
{
    uint16_t fix_freq;
#if CY_USE_CONFIG_TABLE
    pwr_params_t *pwr_cfg = pd_get_ptr_pwr_tbl(context);
#else
    cy_stc_buck_boost_cfg_t *pwr_cfg = context->usbpdConfig->buckBoostConfig;
#endif

    if (pwr_cfg->pwm_dithering_type != BB_DITHER_DIS)
    {
        fix_freq = (uint16_t)pwr_cfg->pwm_fix_freq_dith * 5u;
    }
    else
    {
        fix_freq = (uint16_t)pwr_cfg->pwm_fix_freq * 5u;
    }

    return fix_freq;
}

/* 
 * This function returns number of clock cycles at HF_CLK frequency
 * needed for requested percentage of duty in EA Mode.
 */
static uint16_t bb_per_to_clk (cy_stc_usbpd_context_t *context, uint8_t percent)
{
    uint32_t clk_cycle;
    uint16_t fix_freq_khz = Cy_USBPD_BB_GetFixFreq(context);

    clk_cycle = (((BBCLK_KHZ / fix_freq_khz) * ((uint16_t)percent))/(100u));
    return (uint16_t)clk_cycle;
}

/* 
 * This function returns number of clock cycles at HF_CLK frequency
 * needed for requested percentage of duty in Soft Start Mode.
 */
static uint16_t bb_ss_per_to_clk (cy_stc_usbpd_context_t *context, uint8_t percent)
{
    (void)context;
    uint32_t clk_cycle;

    clk_cycle = (((BBCLK_KHZ / (BB_SS_PWM_FREQ_KHZ)) * ((uint16_t)percent))/(100u));
    return (uint16_t)clk_cycle;
}

/*
 * VBUS_IN OVP configuration for Buck-Boost soft start.
 * Enable sets OVP on VBUS_IN for the requested voltage.
 * This is a custom OVP with a maximum voltage limit for OVP is 9V.
 */

/* OVP min reference voltage in mV. */
#define BB_OVP_REF_VOLT_MIN            (200u)

/* OVP reference voltage step size in mV. */
#define BB_OVP_REF_VOLT_STEP           (10u)

/* VBUS max voltage in mV. */
#define BB_VBUS_VOLT_MAX               (9000u)

/* Max. VREF setting. */
#define BB_VREF_MAX_SETTING            (199u)

#if (PMG1B1_USB_CHARGER == 0)
static void pd_bb_vbus_in_ovp_en(cy_stc_usbpd_context_t *context, uint16_t volt, cy_cb_vbus_fault_t cb)
{
    PPDSS_REGS_T pd = context->base;
    uint16_t vref;
    uint32_t regval;
    uint32_t comp_id = (uint32_t)CY_USBPD_VBUS_COMP_ID_UV;
    uint32_t filter_id = (uint32_t)CY_USBPD_VBUS_FILTER_ID_UV;
    uint32_t state;

    state = Cy_SysLib_EnterCriticalSection();

    /* Store OVP parameters. */
    context->bbOvpCbk = cb;

    /* Cap the maximum voltage to be measured for 20% VBUS_IN, 9V. */
    if (volt > BB_VBUS_VOLT_MAX)
    {
        volt = BB_VBUS_VOLT_MAX;
    }

    /* Select 20% VBUS_IN to OV comparator instead of VBUS_C. */
    pd->amux_nhvn_ctrl |= (1u << AMUX_NHVN_OV_VBUS_IN_20_PER_POS);
    pd->amux_ctrl |= (1u << AMUX_OV_VBUS_IN_20_PER_POS);

    /* Calculate the actual reference voltage. Cap the value to the max. supported. */
    vref = (((volt / VBUS_C_20_PER_DIV) - BB_OVP_REF_VOLT_MIN) / BB_OVP_REF_VOLT_STEP);

    /* UV comparator VREF[2]. */
    regval = pd->refgen_1_ctrl;
    regval &= ~(PDSS_REFGEN_1_CTRL_SEL2_MASK);
    regval |= ((uint32_t)vref << PDSS_REFGEN_1_CTRL_SEL2_POS);
    pd->refgen_1_ctrl = regval;

    /* Turn on comparator. */
    pd->comp_ctrl[comp_id] |= PDSS_COMP_CTRL_COMP_ISO_N;
    pd->comp_ctrl[comp_id] &= ~PDSS_COMP_CTRL_COMP_PD;

    Cy_SysLib_DelayUs(10);

    /* Filter configuration. */
    pd->intr5_filter_cfg[filter_id] &= ~(
            PDSS_INTR5_FILTER_CFG_FILT_EN |
            PDSS_INTR5_FILTER_CFG_FILT_CFG_MASK | 
            PDSS_INTR5_FILTER_CFG_FILT_SEL_MASK | 
            PDSS_INTR5_FILTER_CFG_DPSLP_MODE |
            PDSS_INTR5_FILTER_CFG_FILT_BYPASS | 
            PDSS_INTR5_FILTER_CFG_FILT_RESET);

    /* 
     * Set soft start comparator filter to 1uS only as fast response is needed.
     * Subtracting 1 from filter clock cycle value as 0 translates to 1-2 
     * clock cycles delay. 
     */
    regval = pd->intr5_filter_cfg[filter_id];
    regval |= (((2u - 1u) & 0x1Fu) << PDSS_INTR5_FILTER_CFG_FILT_SEL_POS);
    regval |= ((uint8_t)CY_USBPD_VBUS_FILTER_CFG_POS_EN_NEG_DIS << PDSS_INTR5_FILTER_CFG_FILT_CFG_POS);
    regval |= PDSS_INTR5_FILTER_CFG_FILT_EN | PDSS_INTR5_FILTER_CFG_DPSLP_MODE;

    pd->intr5_filter_cfg[filter_id] = regval;

    /* Clear interrupt. */
    pd->intr5 = ((uint32_t)1u << filter_id);

    /* Enable Interrupt. */
    pd->intr5_mask |= ((uint32_t)1u << filter_id);
#if PSVP_FPGA_ENABLE
    ctrl_inf_ovp_enable(volt / 10u);
#endif /* PSVP_FPGA_ENABLE */

    Cy_SysLib_ExitCriticalSection(state);
}

static void pd_bb_vbus_in_ovp_dis(cy_stc_usbpd_context_t *context)
{
    PPDSS_REGS_T pd = context->base;
    uint32_t state;
    uint32_t comp_id = (uint32_t)CY_USBPD_VBUS_COMP_ID_UV;
    uint32_t filter_id = (uint32_t)CY_USBPD_VBUS_FILTER_ID_UV;

    state = Cy_SysLib_EnterCriticalSection();

    /* Disable comparator. */
    pd->comp_ctrl[comp_id] &= ~PDSS_COMP_CTRL_COMP_ISO_N;
    pd->comp_ctrl[comp_id] |= PDSS_COMP_CTRL_COMP_PD;

     /* Disable filter. */
    pd->intr5_filter_cfg[filter_id] &= ~(PDSS_INTR5_FILTER_CFG_FILT_EN |
        PDSS_INTR5_FILTER_CFG_FILT_CFG_MASK | PDSS_INTR5_FILTER_CFG_FILT_SEL_MASK |
        PDSS_INTR5_FILTER_CFG_FILT_BYPASS | PDSS_INTR5_FILTER_CFG_DPSLP_MODE);

    /* Disable and clear OV interrupts. */
    pd->intr5_mask &= ~((uint32_t)1u << filter_id);
    pd->intr5 = (uint32_t)1u << filter_id;

    /* Restore AMUX settings to VBUS_C 8% */
    pd->amux_nhvn_ctrl &= ~(1u << AMUX_NHVN_OV_VBUS_IN_20_PER_POS);
    pd->amux_ctrl &= ~(1u << AMUX_OV_VBUS_IN_20_PER_POS);

    /* Set UV reference to maximum. */
    pd->refgen_1_ctrl = (pd->refgen_1_ctrl & ~PDSS_REFGEN_1_CTRL_SEL2_MASK) | 
        ((uint32_t)0xFFu << PDSS_REFGEN_1_CTRL_SEL2_POS);

    /* Clear callback. */
    context->bbOvpCbk = NULL;

#if PSVP_FPGA_ENABLE
    ctrl_inf_ovp_disable();
#endif /* PSVP_FPGA_ENABLE*/

    Cy_SysLib_ExitCriticalSection(state);
}
#endif /* PMG1B1_USB_CHARGER == 0 */

static void Cy_USBPD_BB_SoftStartEnable(cy_stc_usbpd_context_t *context);


/* This array lists possible gate drive dead time configuration values */
static const uint8_t gl_bb_gdrv_dead_time[] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x14};

/* 
 * This function configures gate drive strength and filters for 
 * buck-boost switches (HS1, LS1, HS2, LS2).
 */

static void Cy_USBPD_BB_GdrvConfig(cy_stc_usbpd_context_t *context)
{
    PPDSS_REGS_T pd = context->base;
#if CY_USE_CONFIG_TABLE
    pwr_params_t *pwr_cfg = pd_get_ptr_pwr_tbl(context);
#else
    cy_stc_buck_boost_cfg_t *pwr_cfg = context->usbpdConfig->buckBoostConfig;
#endif
    uint8_t hs_dead_time;
    uint8_t ls_dead_time;

    /* HS1 drive strength */
    CY_USBPD_REG_FIELD_UPDATE((pd->bb_gdrvi_1_ctrl), PDSS_BB_GDRVI_1_CTRL_BB_GDRVI_HSDR1_PCONFIG, 
        ((uint32_t)pwr_cfg->pwm_gate_pull_up_drv_strnth_HS1));
    CY_USBPD_REG_FIELD_UPDATE((pd->bb_gdrvi_1_ctrl), PDSS_BB_GDRVI_1_CTRL_BB_GDRVI_HSDR1_NCONFIG, 
        ((uint32_t)pwr_cfg->pwm_gate_pull_down_drv_strnth_HS1));

    /* LS1 drive strength */
    /* QAC suppression 2985: REG_FEILD_UPDATE is a common functional macro that is used to 
     * modify a register field without affecting any other bits of the register. When the field
     * starts from bit position 0, the left shift operation is redundant. Yet this operation is 
     * retained to keep it generic and compatible for bitfields starting from other bit positions. */
    CY_USBPD_REG_FIELD_UPDATE((pd->bb_gdrvi_0_ctrl), PDSS_BB_GDRVI_0_CTRL_BB_GDRVI_LSDR1_PCONFIG, /* PRQA S 2985 */
        (pwr_cfg->pwm_gate_pull_up_drv_strnth_LS1));
    /* QAC suppression 2985: REG_FEILD_UPDATE is a common functional macro that is used to 
     * modify a register field without affecting any other bits of the register. When the field
     * starts from bit position 0, the left shift operation is redundant. Yet this operation is 
     * retained to keep it generic and compatible for bitfields starting from other bit positions. */
    CY_USBPD_REG_FIELD_UPDATE((pd->bb_gdrvi_1_ctrl), PDSS_BB_GDRVI_1_CTRL_BB_GDRVI_LSDR1_NCONFIG,  /* PRQA S 2985 */
        (pwr_cfg->pwm_gate_pull_down_drv_strnth_LS1));

    /* HS2 drive strength */
    /* QAC suppression 2985: REG_FEILD_UPDATE is a common functional macro that is used to 
     * modify a register field without affecting any other bits of the register. When the field
     * starts from bit position 0, the left shift operation is redundant. Yet this operation is 
     * retained to keep it generic and compatible for bitfields starting from other bit positions. */
    CY_USBPD_REG_FIELD_UPDATE((pd->bb_gdrvo_0_ctrl), PDSS_BB_GDRVO_0_CTRL_BB_GDRVO_HSDR2_PCONFIG, /* PRQA S 2985 */
        (pwr_cfg->pwm_gate_pull_up_drv_strnth_HS2));
    CY_USBPD_REG_FIELD_UPDATE((pd->bb_gdrvo_0_ctrl), PDSS_BB_GDRVO_0_CTRL_BB_GDRVO_HSDR2_NCONFIG, 
        (pwr_cfg->pwm_gate_pull_down_drv_strnth_HS2));

    /* LS2 drive strength */
    CY_USBPD_REG_FIELD_UPDATE(pd->bb_gdrvo_1_ctrl, PDSS_BB_GDRVO_1_CTRL_BB_GDRVO_LSDR2_PCONFIG, 
        (uint32_t)pwr_cfg->pwm_gate_pull_up_drv_strnth_LS2);
    CY_USBPD_REG_FIELD_UPDATE(pd->bb_gdrvo_0_ctrl, PDSS_BB_GDRVO_0_CTRL_BB_GDRVO_LSDR2_NCONFIG, 
        (uint32_t)pwr_cfg->pwm_gate_pull_down_drv_strnth_LS2);

    /* Filter configuration for gate drivers */
    CY_USBPD_REG_FIELD_UPDATE(pd->intr17_cfg_7, PDSS_INTR17_CFG_7_BB_GDRVO_VBST_COMP_OUT_FILT_CFG, 3u);
    CY_USBPD_REG_FIELD_UPDATE(pd->intr17_cfg_8, PDSS_INTR17_CFG_8_BB_GDRVI_VBST_COMP_OUT_FILT_CFG, 3u);

    /* Increase leading edge blanking time if drive strengths are weak */
    if((pwr_cfg->pwm_gate_pull_down_drv_strnth_LS2 < 3u) ||
            (pwr_cfg->pwm_gate_pull_up_drv_strnth_HS2 < 3u))
    {
        if((pwr_cfg->pwm_gate_pull_down_drv_strnth_LS2 < 3u) &&
                (pwr_cfg->pwm_gate_pull_up_drv_strnth_HS2 < 3u))
        {
            CY_USBPD_REG_FIELD_UPDATE(pd->bb_gdrvo_2_ctrl, PDSS_BB_GDRVO_2_CTRL_BB_GDRVO_HSRCP_LEB_TIME_CONFIG, BB_GDRVO_2_LEB_TIME_CONFIG_WEAK);
        }
        else
        {
#if PDL_VOUTBB_RCP_ENABLE
            CY_USBPD_REG_FIELD_UPDATE(pd->bb_gdrvo_2_ctrl, PDSS_BB_GDRVO_2_CTRL_BB_GDRVO_HSRCP_LEB_TIME_CONFIG, BB_GDRVO_2_LEB_TIME_CONFIG_STRONG_PMG1B1);
#else
            CY_USBPD_REG_FIELD_UPDATE(pd->bb_gdrvo_2_ctrl, PDSS_BB_GDRVO_2_CTRL_BB_GDRVO_HSRCP_LEB_TIME_CONFIG, BB_GDRVO_2_LEB_TIME_CONFIG_STRONG);
#endif /* PDL_VOUTBB_RCP_ENABLE */
        }
    }

    if((pwr_cfg->pwm_gate_pull_down_drv_strnth_LS1 < 3u) ||
            (pwr_cfg->pwm_gate_pull_up_drv_strnth_HS1 < 3u))
    {
        if((pwr_cfg->pwm_gate_pull_down_drv_strnth_LS1 < 3u) &&
                (pwr_cfg->pwm_gate_pull_up_drv_strnth_HS1 < 3u))
        {
            CY_USBPD_REG_FIELD_UPDATE(pd->bb_gdrvi_2_ctrl, PDSS_BB_GDRVI_2_CTRL_BB_GDRVI_LSZCD_LEB_TIME_CONFIG, 0x7377u);
        }
        else
        {
            CY_USBPD_REG_FIELD_UPDATE(pd->bb_gdrvi_2_ctrl, PDSS_BB_GDRVI_2_CTRL_BB_GDRVI_LSZCD_LEB_TIME_CONFIG, 0x7177u);
        }
    }

    /* Dead time configuration */
    hs_dead_time = gl_bb_gdrv_dead_time[(BB_GDRV_HS_DEAD_TIME_NS / 5u)];
    ls_dead_time = gl_bb_gdrv_dead_time[(BB_GDRV_LS_DEAD_TIME_NS / 5u)];

    CY_USBPD_REG_FIELD_UPDATE(pd->bb_gdrvi_4_ctrl, 
        PDSS_BB_GDRVI_4_CTRL_BB_GDRVI_LSDR1_DEAD_TIME_CONFIG, (uint32_t)ls_dead_time);
    CY_USBPD_REG_FIELD_UPDATE(pd->bb_gdrvo_3_ctrl,
        PDSS_BB_GDRVO_3_CTRL_BB_GDRVO_HSDR2_DEAD_TIME_CONFIG, (uint32_t)hs_dead_time);
}

/* Function to configure PWM mode (FCCM / PSM). */
static void Cy_USBPD_BB_SetMode(cy_stc_usbpd_context_t *context, uint8_t mode)
{
    PPDSS_REGS_T pd = context->base;
    PPDSS_TRIMS_REGS_T pd_trims = (PPDSS_TRIMS_REGS_T)context->trimsBase;
#if CY_USE_CONFIG_TABLE
    pwr_params_t *pwr_cfg = pd_get_ptr_pwr_tbl(context);
#else
    cy_stc_buck_boost_cfg_t *pwr_cfg = context->usbpdConfig->buckBoostConfig;
#endif

    if(mode == BB_MODE_FCCM)
    {
        /* Enable Master FCCM mode */
#if PDL_VOUTBB_RCP_ENABLE
        CY_USBPD_REG_FIELD_UPDATE(pd_trims->trim_bb_gdrvo_1,
            PDSS_TRIM_BB_GDRVO_1_TRIM_HSRCP, BB_GDRVO_1_TRIM_HSRCP_VAL_PMG1B1);
#else
        CY_USBPD_REG_FIELD_UPDATE(pd_trims->trim_bb_gdrvo_1,
            PDSS_TRIM_BB_GDRVO_1_TRIM_HSRCP, BB_GDRVO_1_TRIM_HSRCP_VAL);
#endif /* PDL_VOUTBB_RCP_ENABLE */
        CY_USBPD_REG_FIELD_UPDATE(pd->bb_gdrvo_1_ctrl, 
            PDSS_BB_GDRVO_1_CTRL_BB_GDRVO_T_HSRCP, (uint32_t)0x40u);

        CY_USBPD_REG_FIELD_UPDATE(pd->bbctrl_func_ctrl, 
            PDSS_BBCTRL_FUNC_CTRL_BBCTRL_GDRVO_RCP_DISABE, (uint32_t)0u);

        if(pwr_cfg->buck_boost_operating_mode == BB_FORCED_BUCK)
        {
            /* 
             * Configure LSZCD and corresponding trims in case of 
             * buck-only firmware. 
             */
            CY_USBPD_REG_FIELD_UPDATE(pd->bbctrl_func_ctrl, 
                PDSS_BBCTRL_FUNC_CTRL_BBCTRL_GDRVI_ZCD_DISABE, (uint32_t)4u);
            CY_USBPD_REG_FIELD_UPDATE(pd_trims->trim_bb_gdrvi_1,
                PDSS_TRIM_BB_GDRVI_1_TRIM_LSZCD, 0u);
            pd->bb_gdrvi_0_ctrl |= ((uint32_t)1u << 
                (6u + PDSS_BB_GDRVI_0_CTRL_BB_GDRVI_T_LSZCD_POS));
        }
        else
        {
            CY_USBPD_REG_FIELD_UPDATE(pd->bbctrl_func_ctrl, 
                PDSS_BBCTRL_FUNC_CTRL_BBCTRL_GDRVI_ZCD_DISABE, (uint32_t)7u);
        }

        /* Disable skip */
        pd->bb_pwm_1_ctrl &= ~PDSS_BB_PWM_1_CTRL_BB_PWM_EN_SKIP_COMP;
        pd->bbctrl_func_ctrl2 &= ~PDSS_BBCTRL_FUNC_CTRL2_BBCTRL_SKIP_DIG_EN;
    }
    else if (mode == BB_MODE_PSM)
    {
        /* Enable skip logic */
        pd->bb_pwm_1_ctrl |= PDSS_BB_PWM_1_CTRL_BB_PWM_EN_SKIP_COMP;
        pd->bbctrl_func_ctrl2 |= PDSS_BBCTRL_FUNC_CTRL2_BBCTRL_SKIP_DIG_EN;

        /* Disable Master FCCM mode */

        /* Revert HSRCP trims as these were modified when FCCM mode was enabled. */
        /* QAC suppression 2985: REG_FEILD_UPDATE is a common functional macro that is used to 
         * modify a register field without affecting any other bits of the register. When the field
         * starts from bit position 0, the left shift operation is redundant. Yet this operation is 
         * retained to keep it generic and compatible for bitfields starting from other bit positions. */
        CY_USBPD_REG_FIELD_UPDATE(pd_trims->trim_bb_gdrvo_1, /* PRQA S 2985 */
            PDSS_TRIM_BB_GDRVO_1_TRIM_HSRCP, context->trimsConfig.hsrcp_trim);
        CY_USBPD_REG_FIELD_UPDATE(pd->bb_gdrvo_1_ctrl, 
            PDSS_BB_GDRVO_1_CTRL_BB_GDRVO_T_HSRCP, (uint32_t)0x00u);

        CY_USBPD_REG_FIELD_UPDATE(pd->bbctrl_func_ctrl, 
            PDSS_BBCTRL_FUNC_CTRL_BBCTRL_GDRVO_RCP_DISABE, (uint32_t)2u);
        CY_USBPD_REG_FIELD_UPDATE(pd->bbctrl_func_ctrl, 
            PDSS_BBCTRL_FUNC_CTRL_BBCTRL_GDRVI_ZCD_DISABE, (uint32_t)4u);

        if(pwr_cfg->buck_boost_operating_mode == BB_FORCED_BUCK)
        {
            /* 
             * Revert LSZCD trims in case of buck-only firmware 
             * as these were modified when FCCM mode was enabled. 
             */
            /* QAC suppression 2985: REG_FEILD_UPDATE is a common functional macro that is used to 
             * modify a register field without affecting any other bits of the register. When the field
             * starts from bit position 0, the left shift operation is redundant. Yet this operation is 
             * retained to keep it generic and compatible for bitfields starting from other bit positions. */
            CY_USBPD_REG_FIELD_UPDATE(pd_trims->trim_bb_gdrvi_1, /* PRQA S 2985 */
                PDSS_TRIM_BB_GDRVI_1_TRIM_LSZCD, context->trimsConfig.lszcd_trim);
            pd->bb_gdrvi_0_ctrl &= ~((uint32_t)1u << 
                (6u + PDSS_BB_GDRVI_0_CTRL_BB_GDRVI_T_LSZCD_POS));
        }
    }
    else
    {
        /* Do nothing */
    }
}

#if PDL_VREG_INRUSH_DET_ENABLE

/* Function to enable Vreg inrush detection fault after a delay. */
static void Cy_USBPD_BB_VregInrushDetEnCb( uint16_t id, void *context)
{
    cy_stc_usbpd_context_t *usbpd_ctx = (cy_stc_usbpd_context_t *)context;
    bool inrush_en;
    (void)id;
    cy_stc_usbpd_context_t *usbpd_ctx_temp;
#if (NO_OF_TYPEC_PORTS > 1)
    uint8_t i;
    if(usbpd_ctx->port != 0u)
    {
        usbpd_ctx = usbpd_ctx - (NO_OF_TYPEC_PORTS - 1);
    }
    usbpd_ctx_temp = usbpd_ctx;
    for (i = TYPEC_PORT_0_IDX; i < NO_OF_TYPEC_PORTS; i++)
#else
    usbpd_ctx_temp = usbpd_ctx;
#endif /* (NO_OF_TYPEC_PORTS > 1) */
    {
        if ((usbpd_ctx_temp->bbEnableStatus == true) && (usbpd_ctx_temp->bbEnableDoneStatus == false))
        {
            inrush_en = false;
#if (NO_OF_TYPEC_PORTS > 1)
            break;
#endif /* (NO_OF_TYPEC_PORTS > 1) */
        }
        else
        {
            inrush_en = true;
        }
#if (NO_OF_TYPEC_PORTS > 1)
        usbpd_ctx_temp++;
#endif /* (NO_OF_TYPEC_PORTS > 1) */
    }
    
    if (inrush_en == true)
    {
        /* Re-enable VREG Inrush fault detection as Buck-Boost enable is done */
        Cy_USBPD_Fault_VregInrushDetEn(usbpd_ctx);
    }
    else
    {

        /* Start a timer to check buck-boost enable status */
        usbpd_ctx->timerStartcbk(usbpd_ctx, usbpd_ctx, CY_USBPD_APP_HAL_VREG_TIMER, PD_VREG_INRUSH_DET_EN_DELAY_MS, Cy_USBPD_BB_VregInrushDetEnCb);
    }
}
#endif /* PDL_VREG_INRUSH_DET_ENABLE */

static void Cy_USBPD_BB_SoftStartDoneCbk(uint16_t id, void *usbpdContext)
{
    cy_stc_usbpd_context_t *context = (cy_stc_usbpd_context_t *)usbpdContext;
#if (PMG1B1_USB_CHARGER == 0)
    PPDSS_REGS_T pd = context->base;
#endif /* PMG1B_USB_CHARGER == 0 */
#if CY_USE_CONFIG_TABLE
    pwr_params_t *pwr_cfg = pd_get_ptr_pwr_tbl(context);
#else
    cy_stc_buck_boost_cfg_t *pwr_cfg = context->usbpdConfig->buckBoostConfig;
#endif
    (void)id;

#if !BB_MODE_PSM_ONLY
    /* Enable FCCM if configured, otherwise mode stays in PSM */
    Cy_USBPD_BB_SetMode(context, pwr_cfg->pwm_mode);
#endif /* !BB_MODE_PSM_ONLY */

#if (PMG1B1_USB_CHARGER == 0)
    /* 
     * Re-enable disabled faults to buck-boost controller.
     * VBUS_OCP has debounce in mS, hence do not enable VBUS_OCP for BB auto cut off.
     * VREG Inrush detect fault is handled as part of firmware interrupt.
     */

    pd->bbctrl_func_ctrl3 &= ~(PDSS_BBCTRL_FUNC_CTRL3_BBCTRL_FAULT_DET_DIS_VOUT_UV |
        PDSS_BBCTRL_FUNC_CTRL3_BBCTRL_FAULT_DET_DIS_VOUT_OV |
        PDSS_BBCTRL_FUNC_CTRL3_BBCTRL_FAULT_DET_DIS_SCP |
        PDSS_BBCTRL_FUNC_CTRL3_BBCTRL_FAULT_DET_DIS_PDS_SCP |
        PDSS_BBCTRL_FUNC_CTRL3_BBCTRL_FAULT_DET_DIS_VDDD_BOD |
        PDSS_BBCTRL_FUNC_CTRL3_BBCTRL_FAULT_DET_DIS_VSRC_NEW_N |
        PDSS_BBCTRL_FUNC_CTRL3_BBCTRL_FAULT_DET_DIS_VSRC_NEW_P);
#endif /* PMG1B1_USB_CHARGER == 0 */

#if PDL_BB_ILIM_DET_ENABLE
    Cy_USBPD_Fault_BbIlimDetEn(context);
#endif /* PDL_BB_ILIM_DET_ENABLE */

    context->bbEnableDoneStatus = true;

    /* Stop the regulator startup monitor timer */
    context->timerStopcbk(context, (cy_en_usbpd_timer_id_t)CY_USBPD_APP_REGULATOR_STARTUP_MONITOR_TIMER);

#if PDL_VREG_INRUSH_DET_ENABLE
    /* Re-enable VREG Inrush fault detection as Buck-Boost is up */
    context->timerStartcbk(context, context, CY_USBPD_APP_HAL_VREG_TIMER, PD_VREG_INRUSH_DET_EN_DELAY_MS, Cy_USBPD_BB_VregInrushDetEnCb);
#endif /* PDL_VREG_INRUSH_DET_ENABLE */
}

static void Cy_USBPD_BB_SetVsafe5vDone(void *context, bool stat)
{
    CY_UNUSED_PARAMETER(stat);

    cy_stc_usbpd_context_t *usbpd_ctx = (cy_stc_usbpd_context_t *)context;

    /* 
     * After a timeout, once VBUS_IN is stabilized at VSAFE5V,
     * switch to configured switching mode.
     */

    (void)usbpd_ctx->timerStartcbk(usbpd_ctx, usbpd_ctx, (cy_en_usbpd_timer_id_t)CY_USBPD_APP_HAL_GENERIC_TIMER, BB_STARTUP_DONE_TIMER_PERIOD_MS, Cy_USBPD_BB_SoftStartDoneCbk);
}


static void bb_soft_start_to_ea_cb(cy_en_usbpd_timer_id_t id, void *callbackContext)
{
    (void)id;
    cy_stc_usbpd_context_t *context = (cy_stc_usbpd_context_t *)callbackContext;
    PPDSS_REGS_T pd = context->base;
#if CY_USE_CONFIG_TABLE
    pwr_params_t *pwr_cfg = pd_get_ptr_pwr_tbl(context);
#else
    cy_stc_buck_boost_cfg_t *pwr_cfg = context->usbpdConfig->buckBoostConfig;
#endif

    /* Disable soft start PWM */
    pd->bbctrl_func_ctrl &= ~PDSS_BBCTRL_FUNC_CTRL_BBCTRL_STARTUP_MODE;

    /* Release pull down on EA_OUT as voltage as soft start is completed. */
    pd->bb_ea_2_ctrl &= ~((uint32_t)1u << 
        BB_EA_2_CTRL_BB_EA_T_EA_OUT_PD_POS << 
        PDSS_BB_EA_2_CTRL_BB_EA_T_EA_POS);

    Cy_SysLib_DelayUs(10u);

    /* Wait for BB FSM state to be idle */
    while(0u != (pd->bbctrl_status & 
        PDSS_BBCTRL_STATUS_BBCTRL_FSM_STATE_MASK))
    {
        /* No statement */
    }

    /* Clear all the existing faults in buck-boost latch */
    pd->bbctrl_func_ctrl3 |= (
        PDSS_BBCTRL_FUNC_CTRL3_BBCTRL_FAULT_DET_CLR |
        PDSS_BBCTRL_FUNC_CTRL3_BBCTRL_ILIM_FAULT_DET_CLR);

    /* Reset Buck-Boost state machine */
    pd->bbctrl_func_ctrl |= PDSS_BBCTRL_FUNC_CTRL_BBCTRL_RST_CTRL;
    Cy_SysLib_DelayUs(20);
    pd->bbctrl_func_ctrl &= ~PDSS_BBCTRL_FUNC_CTRL_BBCTRL_RST_CTRL;

    /* Enable EA mode PWM */
    pd->bbctrl_func_ctrl |= PDSS_BBCTRL_FUNC_CTRL_BBCTRL_EA_MODE;

    /* Set Soft Start DONE only for 2-switch regulators */
    if (pwr_cfg->buck_boost_operating_mode != BB_BUCK_BOOST)
    {
        pd->bbctrl_func_ctrl |= PDSS_BBCTRL_FUNC_CTRL_BBCTRL_STARTUP_MODE_DONE;
    }

    Cy_SysLib_DelayUs(20);

    /* Set trimmed CY_PD_VSAFE_5V. */
#if PDL_VBTR_ENABLE
    /* 
     * VBTR configuration is done using pd_hal_vbtr_config() while 
     * configuring soft start in pd_bb_enable(). 
     * Just start the VBTR operation now.
     */
    Cy_USBPD_VBTR_Start(context);
#else /* !PDL_VBTR_ENABLE */
    Cy_USBPD_Hal_Set_Fb_Dac(context,
            Cy_USBPD_Vbus_GetTrimIdac(context, CY_PD_VSAFE_5V));
    /* As it is a direct VBTR transition, call vsafe5v completed callback */
    Cy_SysLib_DelayUs(20);
    Cy_USBPD_BB_SetVsafe5vDone(context, true);
#endif /* PDL_VBTR_ENABLE */
}

static bool bb_en_vbus_ovp_cbk(void *context, bool comp_out)
{
    cy_stc_usbpd_context_t *usbpd_ctx = (cy_stc_usbpd_context_t *)context;

#if APP_VBUS_SRC_FET_BYPASS_EN
    /* Make sure soft start monitoring timer is stopped. */
    usbpd_ctx->timerStopcbk(usbpd_ctx, CY_USBPD_APP_HAL_GENERIC_TIMER);
#endif /* APP_VBUS_SRC_FET_BYPASS_EN */

    if (comp_out == true)
    {
        /* 
         * Voltage has reached soft start cut off.
         * Switch from soft start to regular PWM mode.
         */

        /* Disable OVP for VBUS_IN and release control to VBUS_C. */
#if PMG1B1_USB_CHARGER
        Cy_USBPD_Fault_Vbat_OvpDisable(usbpd_ctx, CCG_SRC_FET);
#else
        pd_bb_vbus_in_ovp_dis(usbpd_ctx);
#endif /* PMG1B1_USB_CHARGER */

        /* Enable EA mode */
        bb_soft_start_to_ea_cb((cy_en_usbpd_timer_id_t)CY_USBPD_APP_HAL_GENERIC_TIMER, usbpd_ctx);
    }

    return true;
}

/* Revert the VBUS_IN discharge strength */
static void pd_internal_revert_vbus_in_ds(cy_stc_usbpd_context_t *context)
{
    PPDSS_REGS_T pd = context->base;
#if VBUS_SLOW_DISCHARGE_EN
    pd->dischg_shv_ctrl[1] = ((pd->dischg_shv_ctrl[1] &
        ~PDSS_DISCHG_SHV_CTRL_DISCHG_DS_MASK) |
        ((uint32_t)context->vbusSlowDischarge.vbus_discharge_ds1 << PDSS_DISCHG_SHV_CTRL_DISCHG_DS_POS));
#else /* !VBUS_SLOW_DISCHARGE_EN */
    pd->dischg_shv_ctrl[1] = ((pd->dischg_shv_ctrl[1] &
        ~PDSS_DISCHG_SHV_CTRL_DISCHG_DS_MASK) |
        ((uint32_t)VBUS_IN_DISCHG_DS << PDSS_DISCHG_SHV_CTRL_DISCHG_DS_POS));
#endif /* VBUS_SLOW_DISCHARGE_EN */
}

#if BB_SAFE_VBUS_IN_EN
static void bb_safe_vbus_in_cb(uint16_t id, void *callbackContext)
{
    uint16_t vbus_in_volt;
    cy_stc_usbpd_context_t *context = (cy_stc_usbpd_context_t *)callbackContext;
#if PMG1B1_USB_CHARGER
    PPDSS_REGS_T pd = context->base;
#endif

    (void)id;

    vbus_in_volt = Cy_USBPD_Adc_MeasureVbusIn(context, CY_USBPD_ADC_ID_0, CY_USBPD_ADC_INPUT_AMUX_B);

    /* VBUS_IN safe voltage monitor callback */
    if (vbus_in_volt > BB_SAFE_VBUS_IN_LEVEL)
    {
        /* Make sure to turn on the discharge if the discharge got disabled during the timer was 
         * running. */
#if PMG1B1_USB_CHARGER
        pd->dischg_shv_ctrl[1] |= (PDSS_DISCHG_SHV_CTRL_DISCHG_EN | PDSS_DISCHG_SHV_CTRL_DISCHG_EN_CFG);
#else
        Cy_USBPD_VbusIn_DischargeOn(context);
#endif /* PMG1B1_USB_CHARGER */
        /* VBUS_IN is not in safe range */
        (void)context->timerStartcbk(context, context, CY_USBPD_APP_HAL_GENERIC_TIMER,
            BB_SAFE_VBUS_IN_TIMER_MS, bb_safe_vbus_in_cb);
    }
    else
    {
        /* Make sure that timeout timer is off. */
        context->timerStopcbk(context, (cy_en_usbpd_timer_id_t)CY_USBPD_APP_HAL_GENERIC_TIMER);
        /* Disable VBUS_IN discharge. */
#if PMG1B1_USB_CHARGER
        pd->dischg_shv_ctrl[1] = ((pd->dischg_shv_ctrl[1] & ~PDSS_DISCHG_SHV_CTRL_DISCHG_EN) | PDSS_DISCHG_SHV_CTRL_DISCHG_EN_CFG);
#else
        Cy_USBPD_VbusIn_DischargeOff(context);
#endif /* PMG1B1_USB_CHARGER */

        /* Revert VBUS_IN discharge drive strength to configured value */
        pd_internal_revert_vbus_in_ds(context);

        /* Turn on the provider FET as VBUS_IN is in safe range */
        Cy_USBPD_BB_SoftStartEnable(context);
    }
}
#endif /* BB_SAFE_VBUS_IN_EN */

#if APP_VBUS_SRC_FET_BYPASS_EN
static void bb_soft_start_mon_cb(uint16_t id, void *callbackContext)
{
    (void)id;
    cy_stc_usbpd_context_t *context = (cy_stc_usbpd_context_t *)callbackContext;
    PPDSS_REGS_T pd = context->base;

    /* 
     * If VBUS has not reached to soft start cut off threshold, 
     * increase the soft start duty.
     */
    context->bbSsPwmDuty += BB_SOFT_START_DUTY_STEP_UP_PER;

    CY_USBPD_REG_FIELD_UPDATE(pd->bbctrl_buck_sw_ctrl, 
        PDSS_BBCTRL_BUCK_SW_CTRL_BBCTRL_SS_PW_HS1, 
        (bb_ss_per_to_clk(context, context->bbSsPwmDuty) - 1));
    /* Enable timer to keep monitor the VBUS soft start */
    context->timerStartcbk(context, context, CY_USBPD_APP_HAL_GENERIC_TIMER, BB_SOFT_START_MON_TIMER_MS, bb_soft_start_mon_cb);
}
#endif /* APP_VBUS_SRC_FET_BYPASS_EN */

static void bb_startup_monitor_cbk(uint16_t id , void *callbackContext)
{
    (void)id;
    cy_stc_usbpd_context_t *context = (cy_stc_usbpd_context_t *)callbackContext;
    /* If buck-boost startup is not completed in the given time period, disable the regulator. */
    Cy_USBPD_BB_Disable(context);
}

/* Calculate cycle to cycle variation allowed based of the
 * required spread in frequency. */
static uint8_t bb_calc_dithering_c2c_var(cy_stc_usbpd_context_t *context)
{
#if CY_USE_CONFIG_TABLE
    pwr_params_t *pwr_cfg = pd_get_ptr_pwr_tbl(context);
#else
    cy_stc_buck_boost_cfg_t *pwr_cfg = context->usbpdConfig->buckBoostConfig;
#endif
    uint8_t range = pwr_cfg->pwm_dith_spread_cycles;
    uint8_t c2c_var = 1u + (range / 5u);
    return c2c_var;
}

static void Cy_USBPD_BB_SoftStartEnable(cy_stc_usbpd_context_t *context)
{
    PPDSS_REGS_T pd = context->base;
#if CY_USE_CONFIG_TABLE
    pwr_params_t *pwr_cfg = pd_get_ptr_pwr_tbl(context);
#else
    cy_stc_buck_boost_cfg_t *pwr_cfg = context->usbpdConfig->buckBoostConfig;
#endif

#if BB_SAFE_VBUS_IN_EN
    /* Disable VBUS_IN discharge. */
    Cy_USBPD_VbusIn_DischargeOff(context);

    /* Revert VBUS_IN discharge drive strength to configured value */
    pd_internal_revert_vbus_in_ds(context);
#endif /* BB_SAFE_VBUS_IN_EN */
    
#if PDL_VREG_INRUSH_DET_ENABLE
    /* 
     * Disable VREG Inrush fault handling during Buck-Boost turn on.
     * Hard IP based auto BB gate drive cut-off is enabled by default to
     * restrict Inrush current.
     */

    context->timerStopcbk(context, CY_USBPD_APP_HAL_VREG_TIMER);

    Cy_USBPD_Fault_VregInrushDetDis(context);
#endif /* PDL_VREG_INRUSH_DET_ENABLE */

    pd->bbctrl_func_ctrl &= ~PDSS_BBCTRL_FUNC_CTRL_BBCTRL_EN;

    /* Configure PSM mode initially for the soft start */
    Cy_USBPD_BB_SetMode(context, BB_MODE_PSM);

    /* Clear all the existing faults in buck-boost latch */
    pd->bbctrl_func_ctrl3 |= (PDSS_BBCTRL_FUNC_CTRL3_BBCTRL_FAULT_DET_CLR |
        PDSS_BBCTRL_FUNC_CTRL3_BBCTRL_ILIM_FAULT_DET_CLR);

    /* Reset Buck-Boost state machine */
    pd->bbctrl_func_ctrl |= PDSS_BBCTRL_FUNC_CTRL_BBCTRL_RST_CTRL;
    Cy_SysLib_DelayUs(20);
    pd->bbctrl_func_ctrl &= ~PDSS_BBCTRL_FUNC_CTRL_BBCTRL_RST_CTRL;

    /* Always enable buck-boost through soft start. */

    /* 
     * Enable EA and CV mode.
     * EA_OUT shall be pulled low by default.
     * EA_OUT shall be released once output voltage reaches startup voltage and
     * till buck-boost regulation is kept enabled.
     * EA_OUT shall be pulled low during pd_bb_init and pd_bb_disable to 
     * make sure it gets enough time to drop to zero before pd_bb_enable is invoked.
     */
    Cy_USBPD_Hal_Enable_CV(context);

    /* 
     * Set Soft start cut-off and IDAC value corresponding to cut-off voltage.
     * Keep IDAC value little lower than cut-off voltage to make 
     * sure that there is no overshoot during soft start to EA handover.
     */
    Cy_USBPD_Hal_Set_Fb_Dac(context, Cy_USBPD_Vbus_GetTrimIdac(context,
            BB_SOFT_START_CUTOFF + BB_SOFT_START_CUTOFF_OFCT));

#if PDL_VBTR_ENABLE
    /*
     * Configure VBTR to transition from soft start cut off to CY_PD_VSAFE_5V
     * after moving to EA mode. This is only configuration and VBTR 
     * operation shall be started once moved to EA mode.
     * Configuration is done here to minimize latency during mode switch.
     */
    Cy_USBPD_VBTR_Config(context, 
        Cy_USBPD_Vbus_GetTrimIdac(context, BB_SOFT_START_CUTOFF + BB_SOFT_START_CUTOFF_OFCT),
        Cy_USBPD_Vbus_GetTrimIdac(context, BB_ENABLE_VOUT_VOLT),
        Cy_USBPD_BB_SetVsafe5vDone);
#endif /* PDL_VBTR_ENABLE */

    /*
     * Enable OVP comparator on VBUS_IN to detect soft start voltage 
     * cut off and handover to EA mode.
     */
#if PMG1B1_USB_CHARGER
    Cy_USBPD_Fault_Vbat_OvpEnable(context, BB_SOFT_START_CUTOFF, BB_BAT_OVP_DEBOUNCE, bb_en_vbus_ovp_cbk, CCG_SRC_FET);
#else
    pd_bb_vbus_in_ovp_en(context, BB_SOFT_START_CUTOFF, bb_en_vbus_ovp_cbk);
#endif /* PMG1B1_USB_CHARGER */


#if APP_VBUS_SRC_FET_BYPASS_EN
    /* Reset soft start duty to configured value */
    context->bbSsPwmDuty = BB_SS_PWM_DUTY_PER;
    CY_USBPD_REG_FIELD_UPDATE(pd->bbctrl_buck_sw_ctrl, 
        PDSS_BBCTRL_BUCK_SW_CTRL_BBCTRL_SS_PW_HS1, 
        (bb_ss_per_to_clk(context, BB_SS_PWM_DUTY_PER) - 1));

    /* 
     * Enable timer to monitor VBUS during soft start.
     * If VBUS is not building up because of load, increase 
     * the soft start PWM duty in steps until soft start 
     * cut off is reached. 
     */

    context->timerStartcbk(context, context, CY_USBPD_APP_HAL_GENERIC_TIMER, BB_SOFT_START_MON_TIMER_MS, bb_soft_start_mon_cb);

#endif /* APP_VBUS_SRC_FET_BYPASS_EN */

    /* Clear soft start done status before enabling soft start for 2-switch regulators */
    if (pwr_cfg->buck_boost_operating_mode != BB_BUCK_BOOST)
    {
        pd->bbctrl_func_ctrl &= ~PDSS_BBCTRL_FUNC_CTRL_BBCTRL_STARTUP_MODE_DONE;
    }

    /* Soft start enable */
    pd->bbctrl_func_ctrl |=  (PDSS_BBCTRL_FUNC_CTRL_BBCTRL_STARTUP_MODE |
        PDSS_BBCTRL_FUNC_CTRL_BBCTRL_EN);
}

void Cy_USBPD_BB_Enable(cy_stc_usbpd_context_t *context)
{
    /* Enable BB control block with soft start. */
#if BB_SAFE_VBUS_IN_EN
    PPDSS_REGS_T pd = context->base;
#endif /* BB_SAFE_VBUS_IN_EN */
    uint32_t state;
#if (!defined(CY_DEVICE_SERIES_WLC1) && (PMG1B1_USB_CHARGER == 0))
    uint16_t vbat_volt;
#endif /* !defined(CY_DEVICE_SERIES_WLC1) */
#if BB_SAFE_VBUS_IN_EN
    uint16_t vbus_in_volt;
#endif /* BB_SAFE_VBUS_IN_EN */

    state = Cy_SysLib_EnterCriticalSection();

    if (context->bbEnableStatus == false)
    {
#if !PSVP_FPGA_ENABLE

#if (!defined(CY_DEVICE_SERIES_WLC1) && (PMG1B1_USB_CHARGER == 0))
        /**
         * WICG1 uses AMUX for custom implementations and ensures 
         * VIN level before enabling buck-boost.
         * Hence, this check is not required.
         */
        vbat_volt = Cy_USBPD_MeasureVbat(context);

        if (vbat_volt < BB_ENABLE_VIN_MIN_VOLT)
        {
            /*
             * If the VIN voltage is below the minimum threshold, then
             * do not try to enable the regulator.
             * Also, if we have VIN_UVP enabled, trigger it.
             */
#if PDL_VIN_UVP_ENABLE
            if ((pd->intr17_mask & PDSS_INTR17_MASK_PDBB_PWM_VIN_UV_DET_MASK) != 0u)
            {
                pd->intr17_set |= PDSS_INTR17_SET_PDBB_PWM_VIN_UV_DET;
            }
#endif /* PDL_VIN_UVP_ENABLE */
            Cy_SysLib_ExitCriticalSection(state);

            /* Do not enable regulator. Just exit here. */
            return;
        }
#endif /* !defined(CY_DEVICE_SERIES_WLC1) */
#endif /* !PSVP_FPGA_ENABLE */

        /* Stop the timer to ensure that we do not get re-entry. */
        context->timerStopcbk(context,(cy_en_usbpd_timer_id_t)CY_USBPD_APP_HAL_GENERIC_TIMER);
        
        context->timerStopcbk(context, (cy_en_usbpd_timer_id_t)CY_USBPD_APP_REGULATOR_STARTUP_MONITOR_TIMER);

#if BB_SAFE_VBUS_IN_EN
        /* Don't turn on the BB if Vbus-in voltage is not in safe range. */

        vbus_in_volt = Cy_USBPD_Adc_MeasureVbusIn(context, CY_USBPD_ADC_ID_0, CY_USBPD_ADC_INPUT_AMUX_B);

        if (vbus_in_volt < BB_SAFE_VBUS_IN_LEVEL)
        {
#endif /* BB_SAFE_VBUS_IN_EN */
            /* Start buck boost in soft start mode */
            Cy_USBPD_BB_SoftStartEnable(context);
#if BB_SAFE_VBUS_IN_EN
        }
        else
        {
#if PMG1B1_USB_CHARGER
            /* Set VBUS_IN discharge drive strength to custom value and enable discharge. */
            pd->dischg_shv_ctrl[1] = ((pd->dischg_shv_ctrl[1] & 
                ~PDSS_DISCHG_SHV_CTRL_DISCHG_DS_MASK));
            pd->dischg_shv_ctrl[1] = (pd->dischg_shv_ctrl[1] |
                    (BB_SAFE_VBUS_IN_DISCHG_DS << PDSS_DISCHG_SHV_CTRL_DISCHG_DS_POS));

            pd->dischg_shv_ctrl[0] = ((pd->dischg_shv_ctrl[0] &
                ~PDSS_DISCHG_SHV_CTRL_DISCHG_DS_MASK));
            pd->dischg_shv_ctrl[0] = (pd->dischg_shv_ctrl[0] |
                    (BB_SAFE_VBUS_IN_DISCHG_DS << PDSS_DISCHG_SHV_CTRL_DISCHG_DS_POS));
#else
            /* Set VBUS_IN discharge drive strength to custom value and enable discharge. */
            pd->dischg_shv_ctrl[1] = ((pd->dischg_shv_ctrl[1] & 
                ~PDSS_DISCHG_SHV_CTRL_DISCHG_DS_MASK) |
                (BB_SAFE_VBUS_IN_DISCHG_DS << PDSS_DISCHG_SHV_CTRL_DISCHG_DS_POS));
#endif /* PMG1B1_USB_CHARGER */

#if VBUS_IN_DISCHARGE_EN
            /* Clear the VBUS_IN discharge enabled flag */
            context->vbusInDischargeEn = false;
#endif /* VBUS_IN_DISCHARGE_EN */

#if PMG1B1_USB_CHARGER
            pd->dischg_shv_ctrl[1] |= (PDSS_DISCHG_SHV_CTRL_DISCHG_EN | PDSS_DISCHG_SHV_CTRL_DISCHG_EN_CFG);
#else
            /* CCG7D is VIN powered, so non comparator based discharge can be enabled */
            Cy_USBPD_VbusIn_DischargeOn(context);
#endif /* PMG1B1_USB_CHARGER */
            (void)context->timerStartcbk(context, context, (cy_en_usbpd_timer_id_t)CY_USBPD_APP_HAL_GENERIC_TIMER,
                BB_SAFE_VBUS_IN_TIMER_MS, bb_safe_vbus_in_cb);
        }
#endif /* BB_SAFE_VBUS_IN_EN */

        context->bbEnableStatus = true;
        context->bbEnableDoneStatus = false;

#if PMG1B1_USB_CHARGER
        /* Start buck-boost startup monitor timer */
        (void)context->timerStartcbk(context, context, CY_USBPD_APP_REGULATOR_STARTUP_MONITOR_TIMER,
                BB_STARTUP_MONITOR_TIMER_PERIOD * 10u, bb_startup_monitor_cbk);
#else /* !PMG1B1_USB_CHARGER */
        /* Start buck-boost startup monitor timer */
        (void)context->timerStartcbk(context, context, CY_USBPD_APP_REGULATOR_STARTUP_MONITOR_TIMER,
                BB_STARTUP_MONITOR_TIMER_PERIOD, bb_startup_monitor_cbk);
#endif /* PMG1B1_USB_CHARGER */
    }
    else
    {
        /* Do nothing */
    }
    Cy_SysLib_ExitCriticalSection(state);
}

void Cy_USBPD_BB_Disable(cy_stc_usbpd_context_t *context)
{
    /* Disable BB control block. */
    PPDSS_REGS_T pd = context->base;
    uint32_t state;

    state = Cy_SysLib_EnterCriticalSection();
    
    if (context->bbEnableStatus == true)
    {
        /* For PMG1B1 stop BB quickly and later stop timers.This need to avoid BB VOUT spike when load is removed. */
#if !defined(CY_DEVICE_SERIES_PMG1B1)
        /* Stop the regulator startup monitor timer */
        context->timerStopcbk(context, (cy_en_usbpd_timer_id_t)CY_USBPD_APP_REGULATOR_STARTUP_MONITOR_TIMER);
    
        /* Stop OVP, discharge and timers used for bb_enable. */
        context->timerStopcbk(context, (cy_en_usbpd_timer_id_t)CY_USBPD_APP_HAL_GENERIC_TIMER);

#if PDL_VREG_INRUSH_DET_ENABLE
        /* Disable vreg fault timer */
        context->timerStopcbk(context, CY_USBPD_APP_HAL_VREG_TIMER);
#endif /* PDL_VREG_INRUSH_DET_ENABLE */
#endif /* #if !defined(CY_DEVICE_SERIES_PMG1B1) */
        /* 
         * If BB disable is called before soft start not completed, 
         * then revert the soft start assisting functions. 
         */
        if (context->bbEnableDoneStatus == false)
        {
            /* Disable soft start OVP */
#if PMG1B1_USB_CHARGER
            Cy_USBPD_Fault_Vbat_OvpDisable(context, CCG_SRC_FET);
#else
            pd_bb_vbus_in_ovp_dis(context);
#endif /* PMG1B1_USB_CHARGER */
#if VBUS_IN_DISCHARGE_EN
            /* Clear the VBUS_IN discharge enabled flag here to prevent random register writes */
            context->vbusInDischargeEn = false;
#endif /* VBUS_IN_DISCHARGE_EN */

            /* Disable soft start VBUS_IN discharge */
            Cy_USBPD_VbusIn_DischargeOff(context);

            /* Revert VBUS_IN discharge drive strength to configured value */
            pd_internal_revert_vbus_in_ds(context);
        }

        /*
         * We are detecting sharp droop in output voltage on BB disable in FCCM
         * mode. In case of WLC1 solution, this is causing audible noise during
         * turn off time. To avoid this, we are switching to PSM mode forcibly.
         * The noise scenario is not very relevant for CCG7D/7S use case as the
         * buck-boost is not frequently turned ON and OFF to generate noise.
         * But since this is an improvement, making this common for all.
         */
#if (PMG1B1_USB_CHARGER == 0)
        Cy_USBPD_BB_SetMode(context, BB_MODE_PSM);
#endif /* PMG1B1_USB_CHARGER == 0 */

        /* Disable EA BB control */
        pd->bbctrl_func_ctrl &= ~PDSS_BBCTRL_FUNC_CTRL_BBCTRL_EA_MODE;

        /* Reset Buck-Boost state machine */
        pd->bbctrl_func_ctrl |= PDSS_BBCTRL_FUNC_CTRL_BBCTRL_RST_CTRL;
        Cy_SysLib_DelayUs(20u);
        pd->bbctrl_func_ctrl &= ~PDSS_BBCTRL_FUNC_CTRL_BBCTRL_RST_CTRL;

        /* Disable BB control */
        pd->bbctrl_func_ctrl &= ~PDSS_BBCTRL_FUNC_CTRL_BBCTRL_EN;

        /* 
         * EA_OUT is at VDDD initially.
         * Required startup voltage is around 5V and it corresponds to
         * low EA_OUT. EA takes longer time to reach lower value from VDDD.
         * Hence, pull down EA_OUT to keep EA_OUT at low level initially before
         * enabling EA during buck-boost enable.
         * Pull down is maintained until VBUS voltage reaches required threshold.
         * Pull down is done here to provide enough time for EA_OUT to drop to zero.
         */
        pd->bb_ea_2_ctrl |= ((uint32_t)1u << BB_EA_2_CTRL_BB_EA_T_EA_OUT_PD_POS << 
            PDSS_BB_EA_2_CTRL_BB_EA_T_EA_POS);

        /* Disable EA after Buck-Boost is turned off */
        Cy_USBPD_Hal_Disable_CV(context);

        /* If VBTR is enabled or running, abort it */
#if PDL_VBTR_ENABLE
        Cy_USBPD_VBTR_Abort(context);
#endif /* PDL_VBTR_ENABLE */

#if PDL_BB_ILIM_DET_ENABLE
        Cy_USBPD_Fault_BbIlimDetDis(context);
#endif /* PDL_BB_ILIM_DET_ENABLE */

#if defined(CY_DEVICE_SERIES_PMG1B1)
        /* Stop the regulator startup monitor timer */
        context->timerStopcbk(context, (cy_en_usbpd_timer_id_t)CY_USBPD_APP_REGULATOR_STARTUP_MONITOR_TIMER);

        /* Stop OVP, discharge and timers used for bb_enable. */
        context->timerStopcbk(context, (cy_en_usbpd_timer_id_t)CY_USBPD_APP_HAL_GENERIC_TIMER);

#if PDL_VREG_INRUSH_DET_ENABLE
        /* Disable vreg fault timer */
        context->timerStopcbk(context,  (cy_en_usbpd_timer_id_t)CY_USBPD_APP_HAL_VREG_TIMER);
#endif /* PDL_VREG_INRUSH_DET_ENABLE */
#endif /* #if defined(CY_DEVICE_SERIES_PMG1B1) */

        context->bbEnableStatus = false;
        context->bbEnableDoneStatus = false;
    }
    else
    {
        /* Do nothing */
    }
    Cy_SysLib_ExitCriticalSection(state);
}

bool Cy_USBPD_BB_IsEnabled(cy_stc_usbpd_context_t *context)
{
    return (context->bbEnableStatus);
}

bool Cy_USBPD_BB_IsReady(cy_stc_usbpd_context_t *context)
{
    return (context->bbEnableDoneStatus);
}

void Cy_USBPD_BB_Init(cy_stc_usbpd_context_t *context)
{
    /* Initialize the BB interface. */
    PPDSS_REGS_T pd = context->base;
    cy_stc_usbpd_context_t *usbpd_ctx_temp=context;
  
#if (NO_OF_TYPEC_PORTS > 1)
    uint8_t i;
    if(context->port != 0u)
    {
        usbpd_ctx_temp=context-(NO_OF_TYPEC_PORTS - 1u);
    }
#endif /* (NO_OF_TYPEC_PORTS > 1) */

#if BB_PWM_ASYNC_MODE_ENABLE
    PPDSS_TRIMS_REGS_T pdtrims = (PPDSS_TRIMS_REGS_T)context->trimsBase;
#endif /* BB_PWM_ASYNC_MODE_ENABLE */
#if CY_USE_CONFIG_TABLE
    pwr_params_t *pwr_cfg = pd_get_ptr_pwr_tbl(context);
#else
    cy_stc_buck_boost_cfg_t *pwr_cfg = context->usbpdConfig->buckBoostConfig;
#endif
    uint32_t fix_freq_khz = Cy_USBPD_BB_GetFixFreq(context);
    uint32_t regval;
    uint32_t vref_sel = 0u;
    uint8_t percent;

    /* Configure soft start and regular operation PWM switching frequency. */
    /* QAC suppression 2985: REG_FEILD_UPDATE is a common functional macro that is used to 
     * modify a register field without affecting any other bits of the register. When the field
     * starts from bit position 0, the left shift operation is redundant. Yet this operation is 
     * retained to keep it generic and compatible for bitfields starting from other bit positions. */
    CY_USBPD_REG_FIELD_UPDATE(pd->bbctrl_ff_strtup, PDSS_BBCTRL_FF_STRTUP_BBCTRL_SS_FREQ, /* PRQA S 2985 */
        FREQ_KHZ_TO_CYCLE_TIME(BB_SS_PWM_FREQ_KHZ));
    /* QAC suppression 2985: REG_FEILD_UPDATE is a common functional macro that is used to 
     * modify a register field without affecting any other bits of the register. When the field
     * starts from bit position 0, the left shift operation is redundant. Yet this operation is 
     * retained to keep it generic and compatible for bitfields starting from other bit positions. */
    CY_USBPD_REG_FIELD_UPDATE(pd->bbctrl_clk_ctrl1, PDSS_BBCTRL_CLK_CTRL1_BBCTRL_CLK_FIX_FREQ, /* PRQA S 2985 */
        (FREQ_KHZ_TO_CYCLE_TIME(fix_freq_khz) - 1u));  
    CY_USBPD_REG_FIELD_UPDATE(pd->bbctrl_clk_ctrl1, PDSS_BBCTRL_CLK_CTRL1_BBCTRL_HS1_BLANKING_TIME_TRAIL, 
        NS_TO_BBCLK_CYCLE_CNT(84u));

    /* Configure buck-boost operating mode */
    if (pwr_cfg->buck_boost_operating_mode == BB_FORCED_BUCK)
    {
        pd->bbctrl_func_ctrl |= PDSS_BBCTRL_FUNC_CTRL_BBCTRL_FORCE_BUCK_MODE;
    }
    else if (pwr_cfg->buck_boost_operating_mode == BB_FORCED_BOOST)
    {
        pd->bbctrl_func_ctrl |= PDSS_BBCTRL_FUNC_CTRL_BBCTRL_FORCE_BOOST_MODE;
    }
    else
    {
        /* Default is buck-boost operation */
    }

    /* Duty cycle configuration for Buck and Boost. */
    pd->bbctrl_buck_sw_ctrl = ((pd->bbctrl_buck_sw_ctrl & 
        ~(PDSS_BBCTRL_BUCK_SW_CTRL_BBCTRL_HS1_MIN_DUTY_CYCLE_MASK | 
        PDSS_BBCTRL_BUCK_SW_CTRL_BBCTRL_HS1_MAX_DUTY_CYCLE_MASK |
        PDSS_BBCTRL_BUCK_SW_CTRL_BBCTRL_SS_PW_HS1_MASK)) |
        ((bb_ss_per_to_clk(context, BB_SS_PWM_DUTY_PER) - (uint32_t)1u) <<
            PDSS_BBCTRL_BUCK_SW_CTRL_BBCTRL_SS_PW_HS1_POS) |
        (BB_HS1_LS2_MIN_DUTY_CYCLE_CLK << 
            PDSS_BBCTRL_BUCK_SW_CTRL_BBCTRL_HS1_MIN_DUTY_CYCLE_POS) |
        ((FREQ_KHZ_TO_CYCLE_TIME(fix_freq_khz) - 
            BB_HS1_LS2_MAX_DUTY_CYCLE_CLK_OFST) << 
            PDSS_BBCTRL_BUCK_SW_CTRL_BBCTRL_HS1_MAX_DUTY_CYCLE_POS));

    pd->bbctrl_boost_sw_ctrl = ((pd->bbctrl_boost_sw_ctrl & 
        ~(PDSS_BBCTRL_BOOST_SW_CTRL_BBCTRL_LS2_MIN_DUTY_CYCLE_MASK | 
        PDSS_BBCTRL_BOOST_SW_CTRL_BBCTRL_LS2_MAX_DUTY_CYCLE_MASK |
        PDSS_BBCTRL_BOOST_SW_CTRL_BBCTRL_SS_PW_LS2_MASK)) |
        ((bb_ss_per_to_clk(context, BB_SS_PWM_DUTY_PER) - (uint32_t)1u) <<
            PDSS_BBCTRL_BOOST_SW_CTRL_BBCTRL_SS_PW_LS2_POS) |
        (BB_HS1_LS2_MIN_DUTY_CYCLE_CLK << 
            PDSS_BBCTRL_BOOST_SW_CTRL_BBCTRL_LS2_MIN_DUTY_CYCLE_POS) |
        ((FREQ_KHZ_TO_CYCLE_TIME(fix_freq_khz) - 
            BB_HS1_LS2_MAX_DUTY_CYCLE_CLK_OFST) << 
            PDSS_BBCTRL_BOOST_SW_CTRL_BBCTRL_LS2_MAX_DUTY_CYCLE_POS));
    
    /* HS1 duty cycle in BB-Boost mode and LS2 duty cycle in BB-Buck mode */
    /* QAC suppression 2985: REG_FEILD_UPDATE is a common functional macro that is used to 
     * modify a register field without affecting any other bits of the register. When the field
     * starts from bit position 0, the left shift operation is redundant. Yet this operation is 
     * retained to keep it generic and compatible for bitfields starting from other bit positions. */
    CY_USBPD_REG_FIELD_UPDATE(pd->bbctrl_bb_fixed_cycle_sw_ctrl, PDSS_BBCTRL_BB_FIXED_CYCLE_SW_CTRL_HS1_FIXD_DUTY_CYCLE_BBOOST, /* PRQA S 2985 */
        NS_TO_BBCLK_CYCLE_CNT(BB_HS1_FIXED_DUTY_CYCLE_BOOST_NS(fix_freq_khz)));
    CY_USBPD_REG_FIELD_UPDATE(pd->bbctrl_bb_fixed_cycle_sw_ctrl, PDSS_BBCTRL_BB_FIXED_CYCLE_SW_CTRL_LS2_FIXD_DUTY_CYCLE_BBUCK,
        NS_TO_BBCLK_CYCLE_CNT(BB_LS2_FIXED_DUTY_CYCLE_BUCK_NS(fix_freq_khz)));

    /* Transient load sample and hold configuration */
    pd->bbctrl_clk_ctrl2 = ((pd->bbctrl_clk_ctrl2 &
        ~(PDSS_BBCTRL_CLK_CTRL2_BBCTRL_PW_ILOAD_MASK |
        PDSS_BBCTRL_CLK_CTRL2_BBCTRL_PER_ILOAD_MASK)) |
        (BBCTRL_TRANS_ILOAD_PW << PDSS_BBCTRL_CLK_CTRL2_BBCTRL_PW_ILOAD_POS) |
        (BBCTRL_TRANS_ILOAD_PER << PDSS_BBCTRL_CLK_CTRL2_BBCTRL_PER_ILOAD_POS));

    /* 
     * Set Audio range MIN and MAX. From 20kHz to 21kHz.
     * This register configuration is based on PWM switching frequency.
     */
    /* QAC suppression 2985: REG_FEILD_UPDATE is a common functional macro that is used to 
     * modify a register field without affecting any other bits of the register. When the field
     * starts from bit position 0, the left shift operation is redundant. Yet this operation is 
     * retained to keep it generic and compatible for bitfields starting from other bit positions. */
    CY_USBPD_REG_FIELD_UPDATE(pd->bbctrl_audio_t_cnfg, PDSS_BBCTRL_AUDIO_T_CNFG_BBCTRL_AUDIO_TMIN, (fix_freq_khz / 21u)); /* PRQA S 2985 */
    CY_USBPD_REG_FIELD_UPDATE(pd->bbctrl_audio_t_cnfg, PDSS_BBCTRL_AUDIO_T_CNFG_BBCTRL_AUDIO_TMAX, (fix_freq_khz / 20u));

    /* Configure clock phase shift between ports */
    if ((context->port == 1u) && (pwr_cfg->phase_angle_control != 0u))
    {
        /* 
         * Apply phase shift on only one port.
         * Value to be programmed is '1' more than required value.
         */
        percent = (uint8_t)BB_PHASE_ANGLE_TO_PER((uint16_t)pwr_cfg->phase_angle_control) + 1u;
        CY_USBPD_REG_FIELD_UPDATE(pd->bbctrl_clk_ctrl1, PDSS_BBCTRL_CLK_CTRL1_BBCTRL_CLK_PHASE_SHIFT, 
            ((uint32_t)bb_per_to_clk(context, percent)));
    }

    /* Configure dithering / spread spectrum */
    if (pwr_cfg->pwm_dithering_type != BB_DITHER_DIS)
    {
        pd->bbctrl_ff_sprd_ctrl = ((pd->bbctrl_ff_sprd_ctrl &
            ~(PDSS_BBCTRL_FF_SPRD_CTRL_BBCTRL_FF_SPRD_MODE_MASK | 
            BBCTRL_FF_SPRD_CTRL_LFSR_INIT_INIT_VAL_MASK |
            BBCTRL_FF_SPRD_CTRL_LFSR_INIT_PER_MASK |
            BBCTRL_FF_SPRD_CTRL_LFSR_INIT_C2C_VAR_MASK)) |
            (((uint32_t)pwr_cfg->pwm_dithering_type) <<
                PDSS_BBCTRL_FF_SPRD_CTRL_BBCTRL_FF_SPRD_MODE_POS) |
            (0x2Cu << 
                BBCTRL_FF_SPRD_CTRL_LFSR_INIT_INIT_VAL_POS) |
            ((uint32_t)pwr_cfg->pwm_dith_spread_cycles << 
                BBCTRL_FF_SPRD_CTRL_LFSR_INIT_PER_POS) |
            ((uint32_t)bb_calc_dithering_c2c_var(context) <<
                BBCTRL_FF_SPRD_CTRL_LFSR_INIT_C2C_VAR_POS) |
            PDSS_BBCTRL_FF_SPRD_CTRL_BBCTRL_FF_SPRD_EN);
    }

    /* Configure Buck-Boost gate drivers (HS1, LS1, HS2, LS2) */
    Cy_USBPD_BB_GdrvConfig(context);

    /* 
     * Configure and enable iLim threshold for buck-boost.
     * Buck-Boost shall limit HS1 pulse width cycle-by-cycle
     * if iLim is detected.
     * Firmware need not to handle this fault.
     * Firmware based iLim handling shall be enabled post soft start
     * 5V regulation is completed.
     */

    /* iLim reference configuration */
    Cy_USBPD_CSA_Calc_Ref(context, ILIM_DET_REF_CUR, ILIM_DET_GAIN, &vref_sel, true);
    vref_sel += ILIM_DET_REF_OFFSET;
    regval = pd->refgen_2_ctrl;
    regval &= ~(PDSS_REFGEN_2_CTRL_SEL7_MASK);
    regval |= ((uint32_t)vref_sel << PDSS_REFGEN_2_CTRL_SEL7_POS);
    pd->refgen_2_ctrl = regval;

    /* iLim filter configuration. */
    regval = pd->intr17_cfg_5;
    regval &= ~(PDSS_INTR17_CFG_5_BB_40CSA_ILIM_DIG_FILT_EN | 
            PDSS_INTR17_CFG_5_BB_40CSA_ILIM_DIG_FILT_CFG_MASK |
            PDSS_INTR17_CFG_5_BB_40CSA_ILIM_DIG_FILT_SEL_MASK | 
            PDSS_INTR17_CFG_5_BB_40CSA_ILIM_DIG_FILT_RESET |
            PDSS_INTR17_CFG_5_BB_40CSA_ILIM_DIG_FILT_BYPASS);
    /* ILIM Digital filter time constant made 1 clock cycle */
    regval |= ((uint8_t)CY_USBPD_VBUS_FILTER_CFG_POS_EN_NEG_EN << PDSS_INTR17_CFG_5_BB_40CSA_ILIM_DIG_FILT_CFG_POS) |
        (1u << PDSS_INTR17_CFG_5_BB_40CSA_ILIM_DIG_FILT_SEL_POS) |
        PDSS_INTR17_CFG_5_BB_40CSA_ILIM_DIG_FILT_EN;
    pd->intr17_cfg_5 = regval;

    /* 
     * Disable the following faults to BB controller until
     * Buck-Boost 5V regulation is up.
     * Keep VBUS_UV comparator interrupt for auto cut-off as it is used for
     * soft start cut-off, which otherwise adds interrupt latency for soft
     * start disable.
     */
    pd->bbctrl_func_ctrl3 |= (PDSS_BBCTRL_FUNC_CTRL3_BBCTRL_FAULT_DET_DIS_VOUT_OV |
#if PMG1B1_USB_CHARGER
        PDSS_BBCTRL_FUNC_CTRL3_BBCTRL_FAULT_DET_DIS_VOUT_UV |
#endif
        PDSS_BBCTRL_FUNC_CTRL3_BBCTRL_FAULT_DET_DIS_VREG_INRUSH |
        PDSS_BBCTRL_FUNC_CTRL3_BBCTRL_FAULT_DET_DIS_PDS_SCP |
        PDSS_BBCTRL_FUNC_CTRL3_BBCTRL_FAULT_DET_DIS_VDDD_BOD |
        PDSS_BBCTRL_FUNC_CTRL3_BBCTRL_FAULT_DET_DIS_OCP |
        PDSS_BBCTRL_FUNC_CTRL3_BBCTRL_FAULT_DET_DIS_SCP |
        PDSS_BBCTRL_FUNC_CTRL3_BBCTRL_FAULT_DET_DIS_VSRC_NEW_N |
        PDSS_BBCTRL_FUNC_CTRL3_BBCTRL_FAULT_DET_DIS_VSRC_NEW_P);

    /* Configure and enable PWM control */
    pd->bb_pwm_0_ctrl |= PDSS_BB_PWM_0_CTRL_BB_PWM_EN_PWMCOMP;
    pd->bb_pwm_1_ctrl |= (PDSS_BB_PWM_1_CTRL_BB_PWM_ISO_N |
        PDSS_BB_PWM_1_CTRL_BB_PWM_EN_MODE_DET |
        PDSS_BB_PWM_1_CTRL_BB_PWM_EN_SKIP_COMP |
        PDSS_BB_PWM_1_CTRL_BB_PWM_ENABLE_PWM);
    pd->bb_pwm_2_ctrl |= PDSS_BB_PWM_2_CTRL_BB_PWM_EN_VIN_RES;
    /* PWM skip configuration */
    pd->bbctrl_func_ctrl2 = ((pd->bbctrl_func_ctrl2 &
        ~(PDSS_BBCTRL_FUNC_CTRL2_BBCTRL_RST_SW_BLNK_TIM_MASK |
        PDSS_BBCTRL_FUNC_CTRL2_BBCTRL_SKIP_WIDTH_LOW_MASK |
        PDSS_BBCTRL_FUNC_CTRL2_BBCTRL_SKIP_WIDTH_HIGH_MASK |
        PDSS_BBCTRL_FUNC_CTRL2_BBCTRL_SCAP_RST_CNT_WDTH_MASK)) |
        (NS_TO_BBCLK_CYCLE_CNT(167u) << PDSS_BBCTRL_FUNC_CTRL2_BBCTRL_RST_SW_BLNK_TIM_POS) |
        ((NS_TO_BBCLK_CYCLE_CNT(375u) - 1u) << PDSS_BBCTRL_FUNC_CTRL2_BBCTRL_SKIP_WIDTH_LOW_POS) |
        ((NS_TO_BBCLK_CYCLE_CNT(542u) - 1u) << PDSS_BBCTRL_FUNC_CTRL2_BBCTRL_SKIP_WIDTH_HIGH_POS) |
        (NS_TO_BBCLK_CYCLE_CNT(625u) << PDSS_BBCTRL_FUNC_CTRL2_BBCTRL_SCAP_RST_CNT_WDTH_POS) |
        PDSS_BBCTRL_FUNC_CTRL2_BBCTRL_VBST_REFRESH_DISABLE);

    /* Disable buck and boost refresh */
    pd->bbctrl_func_ctrl |= (PDSS_BBCTRL_FUNC_CTRL_BBCTRL_DISABLE_BOOST_REFRESH |
        PDSS_BBCTRL_FUNC_CTRL_BBCTRL_DISABLE_BUCK_REFRESH);

    /* Set skip comparator reference to 400mV */
    CY_USBPD_REG_FIELD_UPDATE(pd->refgen_3_ctrl, PDSS_REFGEN_3_CTRL_SEL9, (uint32_t)27u);

#if BB_PWM_ASYNC_MODE_ENABLE
    /* PWM ASYNC mode */
    pd->bbctrl_filt_ctrl &= ~(PDSS_BBCTRL_FILT_CTRL_BB_PWMCOMP_EARLY_DET_SYNC);
    pd->bbctrl_filt_ctrl |= (PDSS_BBCTRL_FILT_CTRL_BB_PWMCOMP_EARLY_DET_ASYNC);
    pd->bbctrl_filt_ctrl |= ((uint32_t)1u << 11);

    /* PWM comparator final inverter current is bypassed. */
    CY_USBPD_REG_FIELD_UPDATE(pdtrims->trim_bb_pwm_1, PDSS_TRIM_BB_PWM_1_TR_PWMCOMP_NOS_OS, 0x8u);
    pd->bb_pwm_2_ctrl |= ((uint32_t)1u << (13u + PDSS_BB_PWM_2_CTRL_BB_PWM_T_PWM_POS));
    CY_USBPD_REG_FIELD_UPDATE(pd->bb_40csa_1_ctrl, PDSS_BB_40CSA_1_CTRL_BB_40CSA_DEL_SEL_PWMOUT_BLK_LV, (uint32_t)0x8u);
#endif /* BB_PWM_ASYNC_MODE_ENABLE */

    /* Configure and enable 20CSA (VOUT sense). */
    pd->csa_scp_0_ctrl = ((pd->csa_scp_0_ctrl & 
        ~(PDSS_CSA_SCP_0_CTRL_PD_CSA |
        PDSS_CSA_SCP_0_CTRL_AV1_MASK | 
        PDSS_CSA_SCP_0_CTRL_EN_ITRAN_DET | 
        PDSS_CSA_SCP_0_CTRL_EN_ITRANCOMP_L2H | 
        PDSS_CSA_SCP_0_CTRL_EN_ITRANCOMP_H2L)) |
        (CC_GAIN_60_AV1_VALUE << PDSS_CSA_SCP_0_CTRL_AV1_POS) |
        PDSS_CSA_SCP_0_CTRL_CSA_ISO_N);
#if defined(CY_DEVICE_SERIES_WLC1)
    CY_USBPD_REG_FIELD_UPDATE(pd->csa_scp_0_ctrl, 
        PDSS_CSA_SCP_0_CTRL_BW_CC, BBCTRL_20CSA_BW_CC_18_KHZ);
#else /* !defined(CY_DEVICE_SERIES_WLC1) */
    CY_USBPD_REG_FIELD_UPDATE(pd->csa_scp_0_ctrl, 
        PDSS_CSA_SCP_0_CTRL_BW_CC, BBCTRL_20CSA_BW_CC_45_KHZ);
#endif /* defined(CY_DEVICE_SERIES_WLC1) */

    CY_USBPD_REG_FIELD_UPDATE(pd->csa_scp_0_ctrl, 
        PDSS_CSA_SCP_0_CTRL_BW, BBCTRL_20CSA_BW_OCP_100_KHZ);
    pd->csa_scp_1_ctrl |= PDSS_CSA_SCP_1_CTRL_CSA_EN_IBIAS;

    /* Configure and enable 40CSA (VIN sense). */
    pd->bb_40csa_0_ctrl |= (PDSS_BB_40CSA_0_CTRL_BB_40CSA_EN_SCOMP_DAC_LV |
        PDSS_BB_40CSA_0_CTRL_BB_40CSA_EN_40CSA_LEV_LV);
    pd->bb_40csa_1_ctrl |= (PDSS_BB_40CSA_1_CTRL_BB_40CSA_EN_SCOMP_VOUTBYR_LV |
        PDSS_BB_40CSA_1_CTRL_BB_40CSA_EN_BIAS_LV |
        PDSS_BB_40CSA_1_CTRL_BB_40CSA_EN_40CSA_STG1_LV |
        PDSS_BB_40CSA_1_CTRL_BB_40CSA_ENABLE_40CSA_LV);
    pd->bb_40csa_2_ctrl &= ~PDSS_BB_40CSA_2_CTRL_BB_40CSA_PD_ILIMCMP_LV;
    pd->bb_40csa_3_ctrl |= PDSS_BB_40CSA_3_CTRL_BB_40CSA_ISO_N;

        /* Calculate and update slope compensation. */
    regval = ((BB_SLOPE_COMP_24X * (uint32_t)BB_SLOPE_COMP_24X_L *
            pwr_cfg->peak_current_sense_resistor) /
              (pwr_cfg->power_inductor_value * (uint32_t)BB_SLOPE_COMP_24X_R));

    CY_USBPD_REG_FIELD_UPDATE(pd->bb_40csa_3_ctrl, PDSS_BB_40CSA_3_CTRL_BB_40CSA_SEL_IDAC_LV, regval);

    /* Power up EA block, configuration is done during VBTR/IBTR */
    pd->bb_ea_0_ctrl = ((pd->bb_ea_0_ctrl &
        ~(PDSS_BB_EA_0_CTRL_BB_EA_PD)) |
        PDSS_BB_EA_0_CTRL_BB_EA_ISO_N);

    /* 
     * EA_OUT is at VDDD initially.
     * Required startup voltage is around 5V and it corresponds to
     * low EA_OUT. EA takes longer time to reach lower value from VDDD.
     * Hence, pull down EA_OUT to keep EA_OUT at low level initially before
     * enabling EA during buck-boost enable.
     * Pull down is maintained until VBUS voltage reaches required threshold.
     * Pull down is done here to provide enough time for EA_OUT to drop to zero.
     */
    pd->bb_ea_2_ctrl |= ((uint32_t)1u << BB_EA_2_CTRL_BB_EA_T_EA_OUT_PD_POS << 
        PDSS_BB_EA_2_CTRL_BB_EA_T_EA_POS);

    /* Enable Gate drivers */
    if (pwr_cfg->buck_boost_operating_mode != BB_FORCED_BUCK)
    {
        pd->bb_gdrvo_0_ctrl = ((pd->bb_gdrvo_0_ctrl &
            ~(PDSS_BB_GDRVO_0_CTRL_BB_GDRVO_HSDR2_PD |
            PDSS_BB_GDRVO_0_CTRL_BB_GDRVO_HSRCP_PD |
            PDSS_BB_GDRVO_0_CTRL_BB_GDRVO_KEEPOFF_EN)) |
            PDSS_BB_GDRVO_0_CTRL_BB_GDRVO_VBST_COMP_EN);
        pd->bb_gdrvo_1_ctrl = ((pd->bb_gdrvo_1_ctrl &
            ~(PDSS_BB_GDRVO_1_CTRL_BB_GDRVO_GDRV_PD |
            PDSS_BB_GDRVO_1_CTRL_BB_GDRVO_LSDR2_PD)) |
            PDSS_BB_GDRVO_1_CTRL_BB_GDRVO_ISO_N);
    }
    if (pwr_cfg->buck_boost_operating_mode != BB_FORCED_BOOST)
    {
        pd->bb_gdrvi_1_ctrl = ((pd->bb_gdrvi_1_ctrl &
            ~(PDSS_BB_GDRVI_1_CTRL_BB_GDRVI_LSDR1_PD |
            PDSS_BB_GDRVI_1_CTRL_BB_GDRVI_HSDR1_PD |
            PDSS_BB_GDRVI_1_CTRL_BB_GDRVI_LSZCD_PD |
            PDSS_BB_GDRVI_1_CTRL_BB_GDRVI_KEEPOFF_EN)) |
            PDSS_BB_GDRVI_1_CTRL_BB_GDRVI_VBST_COMP_EN);
        pd->bb_gdrvi_2_ctrl = ((pd->bb_gdrvi_2_ctrl &
            ~(PDSS_BB_GDRVI_2_CTRL_BB_GDRVI_GDRV_PD)) |
            PDSS_BB_GDRVI_2_CTRL_BB_GDRVI_ISO_N);
    }
#if (NO_OF_TYPEC_PORTS > 1)
    for (i = TYPEC_PORT_0_IDX; i < NO_OF_TYPEC_PORTS; i++)
#endif /* (NO_OF_TYPEC_PORTS > 1) */
    {
        usbpd_ctx_temp->bbEnableStatus = false;
#if (NO_OF_TYPEC_PORTS > 1)
        usbpd_ctx_temp++;
#endif /* (NO_OF_TYPEC_PORTS > 1) */
    }
}

void Cy_USBPD_BB_PowerDown(cy_stc_usbpd_context_t *context)
{
    PPDSS_REGS_T pd = context->base;

#if CY_USE_CONFIG_TABLE
    pwr_params_t *pwr_cfg = pd_get_ptr_pwr_tbl(context);
#else
    cy_stc_buck_boost_cfg_t *pwr_cfg = context->usbpdConfig->buckBoostConfig;
#endif

    /* Disable Buck-Boost */
    pd->bbctrl_func_ctrl &= ~PDSS_BBCTRL_FUNC_CTRL_BBCTRL_EN;

    /* Power down Gate drivers */
    if (pwr_cfg->buck_boost_operating_mode != BB_FORCED_BUCK)
    {
        pd->bb_gdrvo_0_ctrl = ((pd->bb_gdrvo_0_ctrl &
            ~(PDSS_BB_GDRVO_0_CTRL_BB_GDRVO_VBST_COMP_EN |
              PDSS_BB_GDRVO_0_CTRL_BB_GDRVO_VBGBYR_EN)) |
            PDSS_BB_GDRVO_0_CTRL_BB_GDRVO_HSDR2_PD |
            PDSS_BB_GDRVO_0_CTRL_BB_GDRVO_HSRCP_PD |
            PDSS_BB_GDRVO_0_CTRL_BB_GDRVO_KEEPOFF_EN);
        pd->bb_gdrvo_1_ctrl |= (PDSS_BB_GDRVO_1_CTRL_BB_GDRVO_GDRV_PD |
            PDSS_BB_GDRVO_1_CTRL_BB_GDRVO_LSDR2_PD |
            PDSS_BB_GDRVO_1_CTRL_BB_GDRVO_ISO_N);
    }
    if (pwr_cfg->buck_boost_operating_mode != BB_FORCED_BOOST)
    {
        pd->bb_gdrvi_1_ctrl = ((pd->bb_gdrvi_1_ctrl &
            ~(PDSS_BB_GDRVI_1_CTRL_BB_GDRVI_VBST_COMP_EN |
            PDSS_BB_GDRVI_1_CTRL_BB_GDRVI_VBGBYR_EN)) |
            PDSS_BB_GDRVI_1_CTRL_BB_GDRVI_LSDR1_PD |
            PDSS_BB_GDRVI_1_CTRL_BB_GDRVI_HSDR1_PD |
            PDSS_BB_GDRVI_1_CTRL_BB_GDRVI_LSZCD_PD |
            PDSS_BB_GDRVI_1_CTRL_BB_GDRVI_KEEPOFF_EN);
        pd->bb_gdrvi_2_ctrl |= (PDSS_BB_GDRVI_2_CTRL_BB_GDRVI_GDRV_PD |
            PDSS_BB_GDRVI_2_CTRL_BB_GDRVI_ISO_N);
    }

    /* Power down PWM control */
    pd->bb_pwm_0_ctrl &= ~PDSS_BB_PWM_0_CTRL_BB_PWM_EN_PWMCOMP;
    pd->bb_pwm_1_ctrl &= ~(PDSS_BB_PWM_1_CTRL_BB_PWM_EN_MODE_DET |
        PDSS_BB_PWM_1_CTRL_BB_PWM_EN_SKIP_COMP |
        PDSS_BB_PWM_1_CTRL_BB_PWM_ENABLE_PWM);
    pd->bb_pwm_2_ctrl &= ~PDSS_BB_PWM_2_CTRL_BB_PWM_EN_VIN_RES;

    /* Power down 20CSA (VOUT sense). */
    pd->csa_scp_0_ctrl |= PDSS_CSA_SCP_0_CTRL_PD_CSA;
#if !PDL_VBAT_GND_SCP_ENABLE
    pd->csa_scp_1_ctrl &= ~PDSS_CSA_SCP_1_CTRL_CSA_EN_IBIAS;
#endif /* !PDL_VBAT_GND_SCP_ENABLE */

    /* Power down 40CSA (VIN sense). */
    pd->bb_40csa_0_ctrl &= ~(PDSS_BB_40CSA_0_CTRL_BB_40CSA_EN_SCOMP_DAC_LV |
        PDSS_BB_40CSA_0_CTRL_BB_40CSA_EN_40CSA_LEV_LV);
    pd->bb_40csa_1_ctrl &= ~(PDSS_BB_40CSA_1_CTRL_BB_40CSA_EN_SCOMP_VOUTBYR_LV |
        PDSS_BB_40CSA_1_CTRL_BB_40CSA_EN_BIAS_LV |
        PDSS_BB_40CSA_1_CTRL_BB_40CSA_EN_40CSA_STG1_LV |
        PDSS_BB_40CSA_1_CTRL_BB_40CSA_ENABLE_40CSA_LV);
    pd->bb_40csa_2_ctrl |= PDSS_BB_40CSA_2_CTRL_BB_40CSA_PD_ILIMCMP_LV;

    /* Power down EA block */
    pd->bb_ea_0_ctrl |= PDSS_BB_EA_0_CTRL_BB_EA_PD;

    /* Reset Buck-Boost state machine */
    pd->bbctrl_func_ctrl |= PDSS_BBCTRL_FUNC_CTRL_BBCTRL_RST_CTRL;
    Cy_SysLib_DelayUs(20u);
    pd->bbctrl_func_ctrl &= ~PDSS_BBCTRL_FUNC_CTRL_BBCTRL_RST_CTRL;
}

void Cy_USBPD_BB_PowerUp(cy_stc_usbpd_context_t *context)
{
    PPDSS_REGS_T pd = context->base;
#if CY_USE_CONFIG_TABLE
    pwr_params_t *pwr_cfg = pd_get_ptr_pwr_tbl(context);
#else
    cy_stc_buck_boost_cfg_t *pwr_cfg = context->usbpdConfig->buckBoostConfig;
#endif

    /* Disable Buck-Boost */
    pd->bbctrl_func_ctrl &= ~PDSS_BBCTRL_FUNC_CTRL_BBCTRL_EN;

    /* Power up PWM control */
    pd->bb_pwm_0_ctrl |= PDSS_BB_PWM_0_CTRL_BB_PWM_EN_PWMCOMP;
    pd->bb_pwm_1_ctrl |= (PDSS_BB_PWM_1_CTRL_BB_PWM_EN_MODE_DET |
        PDSS_BB_PWM_1_CTRL_BB_PWM_EN_SKIP_COMP |
        PDSS_BB_PWM_1_CTRL_BB_PWM_ENABLE_PWM);
    pd->bb_pwm_2_ctrl |= PDSS_BB_PWM_2_CTRL_BB_PWM_EN_VIN_RES;

    /* Power up 20CSA (VOUT sense). */
    pd->csa_scp_0_ctrl &= ~PDSS_CSA_SCP_0_CTRL_PD_CSA;
    pd->csa_scp_1_ctrl |= PDSS_CSA_SCP_1_CTRL_CSA_EN_IBIAS;

    /* Power up 40CSA (VIN sense). */
    pd->bb_40csa_0_ctrl |= (PDSS_BB_40CSA_0_CTRL_BB_40CSA_EN_SCOMP_DAC_LV |
        PDSS_BB_40CSA_0_CTRL_BB_40CSA_EN_40CSA_LEV_LV);
    pd->bb_40csa_1_ctrl |= (PDSS_BB_40CSA_1_CTRL_BB_40CSA_EN_SCOMP_VOUTBYR_LV |
        PDSS_BB_40CSA_1_CTRL_BB_40CSA_EN_BIAS_LV |
        PDSS_BB_40CSA_1_CTRL_BB_40CSA_EN_40CSA_STG1_LV |
        PDSS_BB_40CSA_1_CTRL_BB_40CSA_ENABLE_40CSA_LV);
    pd->bb_40csa_2_ctrl &= ~PDSS_BB_40CSA_2_CTRL_BB_40CSA_PD_ILIMCMP_LV;

    /* Power up EA block */
    pd->bb_ea_0_ctrl &= ~PDSS_BB_EA_0_CTRL_BB_EA_PD;

    /* Power up Gate drivers */
    if (pwr_cfg->buck_boost_operating_mode != BB_FORCED_BUCK)
    {
        pd->bb_gdrvo_0_ctrl = ((pd->bb_gdrvo_0_ctrl &
            ~(PDSS_BB_GDRVO_0_CTRL_BB_GDRVO_HSDR2_PD |
            PDSS_BB_GDRVO_0_CTRL_BB_GDRVO_HSRCP_PD |
            PDSS_BB_GDRVO_0_CTRL_BB_GDRVO_KEEPOFF_EN)) |
            PDSS_BB_GDRVO_0_CTRL_BB_GDRVO_VBST_COMP_EN |
            PDSS_BB_GDRVO_0_CTRL_BB_GDRVO_VBGBYR_EN);
        pd->bb_gdrvo_1_ctrl = ((pd->bb_gdrvo_1_ctrl &
            ~(PDSS_BB_GDRVO_1_CTRL_BB_GDRVO_GDRV_PD |
            PDSS_BB_GDRVO_1_CTRL_BB_GDRVO_LSDR2_PD)) |
            PDSS_BB_GDRVO_1_CTRL_BB_GDRVO_ISO_N);
    }
    if (pwr_cfg->buck_boost_operating_mode != BB_FORCED_BOOST)
    {
        pd->bb_gdrvi_1_ctrl = ((pd->bb_gdrvi_1_ctrl &
            ~(PDSS_BB_GDRVI_1_CTRL_BB_GDRVI_LSDR1_PD |
            PDSS_BB_GDRVI_1_CTRL_BB_GDRVI_HSDR1_PD |
            PDSS_BB_GDRVI_1_CTRL_BB_GDRVI_LSZCD_PD |
            PDSS_BB_GDRVI_1_CTRL_BB_GDRVI_KEEPOFF_EN)) |
            PDSS_BB_GDRVI_1_CTRL_BB_GDRVI_VBST_COMP_EN |
            PDSS_BB_GDRVI_1_CTRL_BB_GDRVI_VBGBYR_EN);
        pd->bb_gdrvi_2_ctrl = ((pd->bb_gdrvi_2_ctrl &
            ~(PDSS_BB_GDRVI_2_CTRL_BB_GDRVI_GDRV_PD)) |
            PDSS_BB_GDRVI_2_CTRL_BB_GDRVI_ISO_N);
    }

    /* Reset Buck-Boost state machine */
    pd->bbctrl_func_ctrl |= PDSS_BBCTRL_FUNC_CTRL_BBCTRL_RST_CTRL;
    Cy_SysLib_DelayUs(20);
    pd->bbctrl_func_ctrl &= ~PDSS_BBCTRL_FUNC_CTRL_BBCTRL_RST_CTRL;
}

void Cy_USBPD_Fault_BbIlimDetEn(cy_stc_usbpd_context_t *context)
{
#if PDL_BB_ILIM_DET_ENABLE
    PPDSS_REGS_T pd = context->base;
    uint32_t ilim_cur;
    uint32_t regval;
    uint32_t state;
    uint32_t vref_sel;

#if CY_USE_CONFIG_TABLE
    pwr_params_t *pwr_cfg = pd_get_ptr_pwr_tbl(context);
#else
    cy_stc_buck_boost_cfg_t *pwr_cfg = context->usbpdConfig->buckBoostConfig;
#endif

    if (context->bbIlimDetEnStatus == false)
    {
        state = Cy_SysLib_EnterCriticalSection();

        /*
         * Enable Inductor limit (iLim) fault.
         * When fault is detected, buck-boost is disabled through port disable.
         * Fault shall be cleared when buck-boost goes into IDLE.
         * Immediate retry is done for the recovery.
         */

        /*
         * Set iLim reference.
         * Config table inductor peak current limit is in 500mA units,
         * we need it in 10mA units for reference calculation.
         */
        ilim_cur = CY_USBPD_GET_MIN(ILIM_DET_MAX_CURRENT,
            ((uint32_t)50u * pwr_cfg->peak_current_limit));

        Cy_USBPD_CSA_Calc_Ref(context, ilim_cur, ILIM_DET_GAIN, &vref_sel, true);

        /* Configure Reference for comparator. */
        vref_sel += ILIM_DET_REF_OFFSET;
        regval = pd->refgen_2_ctrl;
        regval &= ~(PDSS_REFGEN_2_CTRL_SEL7_MASK);
        regval |= ((uint32_t)vref_sel << PDSS_REFGEN_2_CTRL_SEL7_POS);
        pd->refgen_2_ctrl = regval;

        /* Power up CSA block and enable output. */
        regval = pd->csa_scp_0_ctrl;
        regval &= ~PDSS_CSA_SCP_0_CTRL_PD_CSA;
        regval |= PDSS_CSA_SCP_0_CTRL_SEL_OUT_D | PDSS_CSA_SCP_0_CTRL_CSA_ISO_N;
        pd->csa_scp_0_ctrl = regval;

        Cy_USBPD_Fault_FetAutoModeEnable(context, CCG_SRC_FET, CY_USBPD_VBUS_FILTER_ID_ILIM_DET);

        /* Clear existing iLim fault in buck-boost latch */
        pd->bbctrl_func_ctrl3 |= PDSS_BBCTRL_FUNC_CTRL3_BBCTRL_ILIM_FAULT_DET_CLR;
        Cy_SysLib_DelayUs(20);

        Cy_SysLib_ExitCriticalSection(state);
    }
    else
    {
        /* Already enabled, do nothing */
    }
#else /* !PDL_BB_ILIM_DET_ENABLE */
    CY_UNUSED_PARAMETER(context);
#endif /* !PDL_BB_ILIM_DET_ENABLE */
}

void Cy_USBPD_Fault_BbIlimDetDis(cy_stc_usbpd_context_t *context)
{
    CY_UNUSED_PARAMETER(context);
}

#endif /* defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) */

#endif /* (defined(CY_IP_MXUSBPD) || defined(CY_IP_M0S8USBPD)) */

/* [] END OF FILE */
