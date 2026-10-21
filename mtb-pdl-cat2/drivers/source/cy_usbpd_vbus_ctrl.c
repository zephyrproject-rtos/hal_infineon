/***************************************************************************//**
* \file cy_usbpd_vbus_ctrl.c
* \version 2.110
*
* The source file of the USBPD VBUS Control driver.
*
********************************************************************************
* \copyright
* (c) (2021-2025), Cypress Semiconductor Corporation (an Infineon company) or
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

#if (defined(CY_IP_MXUSBPD) || defined(CY_IP_M0S8USBPD))
#include "cy_pdl.h"

#include "cy_usbpd_common.h"
#include "cy_usbpd_defines.h"
#include "cy_usbpd_vbus_ctrl.h"
#include "cy_usbpd_typec.h"
#include "cy_usbpd_idac_ctrl.h"
#include "cy_usbpd_config_table.h"

#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
#include "cy_usbpd_buck_boost.h"
#endif /* (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) */

/* Minimum VIN OVP Detection Voltage */
#if defined(CY_DEVICE_SERIES_WLC1)
#define VIN_OVP_DETECT_MIN                      (5000u)
#else /* !defined(CY_DEVICE_SERIES_WLC1) */
#define VIN_OVP_DETECT_MIN                      (12000u)
#endif /* defined(CY_DEVICE_SERIES_WLC1) */

/* Buck-Boost operating modes */
#define BB_BUCK_BOOST                       (0u)
#define BB_FORCED_BUCK                      (1u)
#define BB_FORCED_BOOST                     (2u)

/* Default reference voltage on M0S8-USBPD IP. */
#define PD_ADC_DEFAULT_VDDD_VOLT_MV             (3300u)

/* Bandgap voltage in millivolt. */
#define PD_ADC_BAND_GAP_VOLT_MV                 (1200u)

/* Maximum ADC count. */
#define PD_ADC_MAX_VALUE                        (0xFFu)

/* Number of ADC levels. */
#define PD_ADC_NUM_LEVELS                       (PD_ADC_MAX_VALUE + 1u)

/*
 * The minimum comparator output shall be limited to this value to guard
 * against ground bounce and other ADC noise.
 */
#define PD_ADC_LEVEL_MIN_THRESHOLD              (4u)

/*
 * The maximum comparator output shall be limited to this value to guard
 * against max level.
 */
#define PD_ADC_LEVEL_MAX_THRESHOLD              (254u)

/* Loop timeout count for ADC. */
#define PD_ADC_TIMEOUT_COUNT                    (200UL)

#define VBUS_MON_DIV_20P_VAL                    (10u)   /* Multiplied by 2. */
#define VBUS_MON_DIV_10P_VAL                    (20u)   /* Multiplied by 2. */
#define VBUS_MON_DIV_9P_VAL                     (22u)   /* Multiplied by 2. */
#define VBUS_MON_DIV_8P_VAL                     (25u)   /* Multiplied by 2. */
#define VBUS_MON_DIV_6P_VAL                     (33u)   /* Multiplied by 2. */

/* On CCG6, AMUX_NHV[4] enables connection of VBus divider to ADC_IN_2. */
#define AMUX_ADC_CCG6_VBUS_DIV_EN_POS       (4u)

/* PAG1S VBUS_IN resistor divider for Type-C VBUS monitoring using ADC. */
#define AMUX_ADC_PAG1S_VBUS_IN_8P_EN_POS    (9u)

/* PAG1S switch to 20% divider option at the final MUX. */
#define AMUX_ADC_PAG1S_VBUS_DIV_20P_EN_POS  (3u)

/* Maximum voltage in mV that can be measured with 20% divider. */
#define VBUS_DIV_20_PER_MAX_VOLT                (9000U)

/* PMG1S0 enable VBUS_IN resistor divider for TYPE-C VBUS monitoring using ADC. */
#define AMUX_ADC_PMG1S0_VBUS_IN_8P_EN_POS       (7u)
#define AMUX_ADC_PMG1S0_VBUS_IN_20P_EN_POS      (4u)

/* PMG1S0 switch to 20% divider option at the final MUX. */
#define AMUX_ADC_PMG1S0_VBUS_DIV_2OP_EN_POS     (14u)


/* AUTO_MODE control mask for PGDO_1_CFG and PGDO_PU_1_CFG registers. */
#define PGDO_1_CFG_AUTO_SEL_MASK       (PDSS_PGDO_1_CFG_SEL_CSA_OC |\
                                        PDSS_PGDO_1_CFG_SEL_SWAP_VBUS_LESS_5_MASK |\
                                        PDSS_PGDO_1_CFG_SEL_FILT2_MASK |\
                                        PDSS_PGDO_1_CFG_SEL_CC1_OCP |\
                                        PDSS_PGDO_1_CFG_SEL_CC2_OCP |\
                                        PDSS_PGDO_1_CFG_SEL_CC1_OVP |\
                                        PDSS_PGDO_1_CFG_SEL_CC2_OVP |\
                                        PDSS_PGDO_1_CFG_SEL_SBU1_OVP_MASK |\
                                        PDSS_PGDO_1_CFG_SEL_SBU2_OVP_MASK)

#define PGDO_PU_1_CFG_AUTO_SEL_MASK     (PGDO_1_CFG_AUTO_SEL_MASK)

#define AMUX_OV_VBUS_SEL_MASK           (0x00000208u)
#if defined(CY_DEVICE_CCG3PA)
#define AMUX_OV_DIV_SEL_BIT_POS         (13u)
#elif defined (CY_DEVICE_PMG1S3)
#define AMUX_OV_DIV_SEL_BIT_POS         (1u)
#elif defined (CY_DEVICE_CCG6DF_CFP)
#define AMUX_OV_DIV_SEL_BIT_POS         (1u)
#elif defined(CY_DEVICE_PAG1S) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)
#define AMUX_OV_DIV_SEL_BIT_POS         (6u)
#else
#define AMUX_OV_DIV_SEL_BIT_POS         (2u)
#endif /* CY_DEVICE_CCG3PA */

#define AMUX_UV_VBUS_SEL_MASK           (0x00000044)
#if defined (CY_DEVICE_PMG1S3)
#define AMUX_UV_DIV_SEL_BIT_POS         (0u)
#elif defined (CY_DEVICE_CCG6DF_CFP)
#define AMUX_UV_DIV_SEL_BIT_POS         (0u)
#elif defined(CY_DEVICE_PAG1S) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)
#define AMUX_UV_DIV_SEL_BIT_POS         (7u)
#else
#define AMUX_UV_DIV_SEL_BIT_POS         (12u)
#endif /* defined(CY_DEVICE_PMG1S3) */

#define VBUS_C_20_PER_DIV               (5u)       /* 20% */
#define VBUS_C_5_PER_DIV                (20u)      /* 5% */
#define VBUS_C_10_PER_DIV               (10u)      /* 10% */
#define VBUS_C_8_PER_DIV                (12u)      /* APPROX 8% */

#if defined(CY_DEVICE_CCG3PA)

/** SCP Comparator min reference voltage in mV. */
#define SCP_REF_VOLT_MIN            (130u)

/** SCP Reference voltage step size in mV. */
#define SCP_REF_VOLT_STEP           (10u)

/** SCP Gain. */
#define SCP_GAIN_VALUE              (10u)

/* AMUX Control bit to select reference voltage for OCP comparator. */
#define VBUS_OCP_AMUX_CTRL_REF_SEL_BIT_POS      (3u)

/** AMUX Control bit to select reference voltage for SCP comparator. */
#define VBUS_SCP_AMUX_CTRL_REF_SEL_BIT_POS      (2u)
#endif /* defined(CY_DEVICE_CCG3PA)*/

#if defined(CY_DEVICE_CCG3)

#define VBUS_P_NGDO_EN_LV_0 (1UL << 13)
#define VBUS_P_NGDO_EN_LV_1 (1UL << 12)
#define VBUS_C_NGDO_EN_LV_0 (1UL << 3)
#define VBUS_C_NGDO_EN_LV_1 (1UL << 4)

#define VBUS_P_PLDN_EN_LV_0 (1UL << 15)
#define VBUS_P_PLDN_EN_LV_1 (1UL << 14)
#define VBUS_C_PLDN_EN_LV_0 (1UL << 5)
#define VBUS_C_PLDN_EN_LV_1 (1UL << 6)

#endif /* defined(CY_DEVICE_CCG3) */

#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))

/** Bit mask of all the faults that can disable VBUS PFET */
#define BB_NGDO_0_GDRV_EN_CTRL_SEL_MASK (PDSS_BB_NGDO_0_GDRV_EN_CTRL_SEL_FILT2_MASK |\
                                         PDSS_BB_NGDO_0_GDRV_EN_CTRL_SEL_CC1_OCP_FOR_BB |\
                                         PDSS_BB_NGDO_0_GDRV_EN_CTRL_SEL_CC2_OCP_FOR_BB |\
                                         PDSS_BB_NGDO_0_GDRV_EN_CTRL_SEL_CC1_SCP_FOR_BB |\
                                         PDSS_BB_NGDO_0_GDRV_EN_CTRL_SEL_CC2_SCP_FOR_BB |\
                                         PDSS_BB_NGDO_0_GDRV_EN_CTRL_SEL_CC1_OVP_FOR_BB |\
                                         PDSS_BB_NGDO_0_GDRV_EN_CTRL_SEL_CC2_OVP_FOR_BB |\
                                         PDSS_BB_NGDO_0_GDRV_EN_CTRL_SEL_VIN_UV_DET |\
                                         PDSS_BB_NGDO_0_GDRV_EN_CTRL_SEL_VIN_OV_DET |\
                                         PDSS_BB_NGDO_0_GDRV_EN_CTRL_SEL_ILIM_DIG |\
                                         PDSS_BB_NGDO_0_GDRV_EN_CTRL_SEL_VREG_IN_RUSH |\
                                         PDSS_BB_NGDO_0_GDRV_EN_CTRL_SEL_VREG_VDDD_BOD |\
                                         PDSS_BB_NGDO_0_GDRV_EN_CTRL_SEL_CSA_SCP |\
                                         PDSS_BB_NGDO_0_GDRV_EN_CTRL_SEL_CSA_OCP |\
                                         PDSS_BB_NGDO_0_GDRV_EN_CTRL_SEL_PDS_SCP)

/* 
 * Bit position in T_VCONN field for slow turn ON and 
 * enable the slow charging of 20vconn switch 
 * for inrush current control
 */
#define PDSS_VCONN20_CTRL_T_VCONN_SLOW_TURN_ON_POS      (12u)

/* VCONN OCP trim */
#define VCONN_OCP_TRIM(port) (*(volatile uint8_t *)((0x0ffff13cu) + \
        (((uint32_t)(port)) * (0x32u))))

/* VCONN OCP offset on CC2 line in steps of 4.8mA */
#define VCONN_OCP_TRIM_CC2_OFFSET       (1u)

#if PDL_VBAT_GND_SCP_ENABLE

/* VBAT_GND SCP hardware debounce in uS. */
#define VBAT_GND_SCP_DEBOUNCE                       (0u)

/* VBAT_GND fault position for fault GPIO configuration */
#define FAULT_GPIO_MASK_EXTR_VBAT_GND_SCP        ((uint32_t)1u << 8u)

/* VBAT_GND SCP trims */
#define VBAT_GND_SCP_TRIM_6A_ROOM(port) (*(volatile uint8_t *)((0x0ffff480u) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))

#define VBAT_GND_SCP_TRIM_10A_ROOM(port) (*(volatile uint8_t *)((0x0ffff481u) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))

#endif /* PDL_VBAT_GND_SCP_ENABLE */

#define MAX_CLK_FILT_SEL_CYCLES         (0x20u)

#if ((PDL_VBUS_OCP_ENABLE) || (PDL_VBUS_SCP_ENABLE) || (PDL_VBUS_OVP_ENABLE) || (PDL_VBUS_UVP_ENABLE) || (defined(CY_DEVICE_SERIES_PMG1B1)))
static uint16_t system_get_clk_filt_sel(uint8_t port, uint16_t filt_debounce)
{
    uint16_t filt_sel;
    uint16_t filt_clk_khz;
    (void)port;

#if (!PSVP_FPGA_ENABLE)
    filt_clk_khz = ((Cy_SysClk_ClkHfGetFrequency()/1000u) / (23 + 1u));
#else
    filt_clk_khz = (26000 / (12 + 1u));
#endif /* (!PSVP_FPGA_ENABLE) */

    filt_sel = ((filt_debounce * filt_clk_khz) / 10000u);
    filt_sel = CY_USBPD_GET_MIN(filt_sel, MAX_CLK_FILT_SEL_CYCLES);

    return filt_sel;
}
#endif /* (PDL_VBUS_OCP_ENABLE || PDL_VBUS_SCP_ENABLE || PDL_VBUS_OVP_ENABLE || PDL_VBUS_UVP_ENABLE || (defined(CY_DEVICE_SERIES_PMG1B1))) */
#endif /* defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)  */

#if (defined(CY_DEVICE_PAG2S))

/** Bit mask of all the faults that can disable VBUS PFET */
#define PDSS_NGDO_1_CFG_AUTO_SEL_MASK (PDSS_NGDO_1_CFG_SEL_FILT2_MASK |\
                                        PDSS_NGDO_1_CFG_SEL_ZCD_OUT |\
                                        PDSS_NGDO_1_CFG_SEL_NSN_OUT |\
                                        PDSS_NGDO_1_CFG_SEL_PWM_OUT |\
                                        PDSS_NGDO_1_CFG_SEL_BURST_EXIT_OUT  |\
                                        PDSS_NGDO_1_CFG_SEL_SR_SEN_OVP_OUT |\
                                        PDSS_NGDO_1_CFG_SEL_SKIP_OUT    |\
                                        PDSS_NGDO_1_CFG_SEL_PEAKDET_OUT |\
                                        PDSS_NGDO_1_CFG_SEL_PEAKDET_RST_OUT |\
                                        PDSS_NGDO_1_CFG_SEL_PEAKDET_CLCMP_RAW_OUT |\
                                        PDSS_NGDO_1_CFG_SEL_ZCDF_OUT |\
                                        PDSS_NGDO_1_CFG_SEL_PDS_SCP  |\
                                        PDSS_NGDO_1_CFG_SEL_FF_OV    |\
                                        PDSS_NGDO_1_CFG_SEL_FF_UV)

#if (CY_USBPD_RSENSE_SHORT_DET_ENABLE)
#define RSENSE_SHORT_PW_THRESH_HIGH_LINE        63UL /*2.6us*/ /* 122 * 41n = 5u */
#define RSENSE_SHORT_PW_THRESH_LOW_LINE         145UL /* 6us */   /*270UL*/ /* 270 * 41n = 11u */
#endif /* (CY_USBPD_RSENSE_SHORT_DET_ENABLE) */

#endif /* defined(CY_DEVICE_PAG2S) */

#if defined(CY_DEVICE_CCG6DF_CFP)

/* Step size for Ilimit load current configuration.
 * Note: ILIM_CONFIG_STEP_SIZE = 65/32 when CONFIG_2X_STEP_CTRL = 1/0 */
#define ILIM_CONFIG_STEP_SIZE         (32u)

/* Minimum load current supported by Ilimit block(in mA).*/
#define ILIM_REF_LOAD_CURRENT (524u)

/* Current threshold (in %) for Ilimit feature. */
#define ILIM_THRESHOLD (10u)

#endif /* defined(CY_DEVICE_CCG6DF_CFP) */

#define MAX_OCP_DEBOUNCE_CYCLES         (0x20U)

void Cy_USBPD_SetRefgenVoltage(cy_stc_usbpd_context_t *context, uint8_t vrefSel, uint8_t vrefSelPos);

/*******************************************************************************
* Function Name: Cy_USBPD_Adc_Init
****************************************************************************//**
*
* Initializes the PD ADC block. This function enables the PD block and the registers
* required for ADC operation. It then calibrates the ADC to identify the VDDD voltage.
* It does not start any ADC operations.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \param adcId
* ADC ID. \ref cy_en_usbpd_adc_id_t
*
* \return
* CY_USBPD_STAT_SUCCESS if operation is successful,
* CY_USBPD_STAT_BAD_PARAM if the context pointer or adcID is invalid.
*
*******************************************************************************/
cy_en_usbpd_status_t Cy_USBPD_Adc_Init(cy_stc_usbpd_context_t *context, cy_en_usbpd_adc_id_t adcId)
{
    PPDSS_REGS_T pd = NULL;

    if((NULL == context)
#if !defined(CY_DEVICE_CCG3)
      || (CY_USBPD_ADC_ID_OVUV == adcId)
#endif
      )
    {
        return CY_USBPD_STAT_BAD_PARAM;
    }

    pd = context->base;

#if defined(CY_DEVICE_CCG3)
    uint16_t retVal = 0U;
#endif /* defined(CY_DEVICE_CCG3) */
#if defined (CY_DEVICE_CCG3PA)
    context->vbusDetachAdcInp = CY_USBPD_ADC_INPUT_AMUX_B;
    context->vbusDetachAdcId = CY_USBPD_ADC_ID_1;
#elif(defined(CY_DEVICE_CCG6) || defined (CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP))
    context->vbusDetachAdcInp = CY_USBPD_ADC_INPUT_AMUX_B;
    context->vbusDetachAdcId = CY_USBPD_ADC_ID_0;
#elif defined(CY_DEVICE_CCG3)
    context->vbusDetachAdcInp = CY_USBPD_ADC_INPUT_AMUX_A;
    context->vbusDetachAdcId = CY_USBPD_ADC_ID_1;
#else
    context->vbusDetachAdcInp = CY_USBPD_ADC_INPUT_AMUX_A;
    context->vbusDetachAdcId = CY_USBPD_ADC_ID_0;
#endif /* defined (CY_DEVICE_CCG3PA) */

#if (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
    /* Enable the ADC and power it down. */
    pd->adc_ctrl[adcId] = PDSS_ADC_CTRL_ADC_ISO_N | PDSS_ADC_CTRL_PD_LV;
#endif /* (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) */

#if (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_CCG6DF) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP))
    /* Enable the ADC and power it down. */
    pd->adc_ctrl = PDSS_ADC_CTRL_ADC_ISO_N | PDSS_ADC_CTRL_PD_LV;
#endif /* (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_CCG6DF) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP)) */

#if defined(CY_DEVICE_CCG3)
    context->adcRefVddd[adcId] = true;
    context->adcVdddMv[adcId]  = PD_ADC_DEFAULT_VDDD_VOLT_MV;

    /* On PMG1S2, we use 9.09 % of VBus for voltage measurements. */
    context->vbusMonDiv        = VBUS_MON_DIV_9P_VAL;

    if (adcId == CY_USBPD_ADC_ID_1)
    {
        /* Enable the ADC and power it down. */
        pd->adc2_ctrl = PDSS_ADC2_CTRL_ADC_ISO_N | PDSS_ADC2_CTRL_PD_LV;

    }
    else
    {
        /* Enable the ADC and power it down. */
        pd->adc1_ctrl = PDSS_ADC1_CTRL_ADC_ISO_N | PDSS_ADC1_CTRL_PD_LV;
    }

    /* Calibrate the ADC before starting. */
    retVal = Cy_USBPD_Adc_Calibrate (context, adcId);
    (void)retVal;
#else
    context->adcRefVddd[adcId] = false;
    context->adcVdddMv[adcId]  = MX_PD_ADC_REF_VOLT_MV;
#if defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP)
    context->vbusMonDiv        = VBUS_MON_DIV_6P_VAL;
#else
    context->vbusMonDiv        = VBUS_MON_DIV_8P_VAL;
#endif /* defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP) */
#endif /* defined(CY_DEVICE_CCG3) */

    return CY_USBPD_STAT_SUCCESS;
}

/*******************************************************************************
* Function Name: Cy_USBPD_Adc_VoltToLevel
****************************************************************************//**
*
* Converts the voltage in millivolts to ADC units. It takes a 16-bit voltage
* value in millivolts and returns the corresponding 8-bit ADC reading.
* This function does not perform any ADC operations.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \param adcId
* ADC ID. \ref cy_en_usbpd_adc_id_t
*
* \param volt
* Voltage in millivolt
*
* \return uint8_t
* 8-bit ADC reading corresponding to Voltage.
*
*******************************************************************************/
uint8_t Cy_USBPD_Adc_VoltToLevel(cy_stc_usbpd_context_t *context, cy_en_usbpd_adc_id_t adcId, uint16_t volt)
{
    uint32_t threshold;

    threshold = (((uint32_t)volt * PD_ADC_NUM_LEVELS) / context->adcVdddMv[adcId]);

    if (threshold < PD_ADC_LEVEL_MIN_THRESHOLD)
    {
        threshold = PD_ADC_LEVEL_MIN_THRESHOLD;
    }
    if (threshold > PD_ADC_LEVEL_MAX_THRESHOLD)
    {
        threshold = PD_ADC_LEVEL_MAX_THRESHOLD;
    }

    return (uint8_t)threshold;
}

/*******************************************************************************
* Function Name: Cy_USBPD_Adc_LevelToVolt
****************************************************************************//**
*
* Converts the ADC units to voltage in millivolts.
* It takes an 8-bit ADC reading and returns the corresponding 16-bit voltage
* value in millivolts. This function does not perform any ADC operations.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \param adcId
* ADC ID. \ref cy_en_usbpd_adc_id_t
*
* \param level
* The 8-bit ADC reading.
*
* \return uint16_t
* Returns voltage in mV.
*
*******************************************************************************/
uint16_t Cy_USBPD_Adc_LevelToVolt(cy_stc_usbpd_context_t *context, cy_en_usbpd_adc_id_t adcId, uint8_t level)
{
    uint16_t threshold;

    threshold = ((level * context->adcVdddMv[adcId]) / PD_ADC_NUM_LEVELS);

    return threshold;
}

/*******************************************************************************
* Function Name: Cy_USBPD_Adc_GetVbusVolt
****************************************************************************//**
*
* Converts the ADC level to VBUS voltage in millivolts.
* It takes an 8-bit ADC reading and returns the corresponding 16-bit voltage
* value in millivolts. This function does not perform any ADC operations.
* Cy_USBPD_Adc_Sample should be called to convert a divided version of VBus to
* ADC levels before calling this function.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \param adcId
* ADC ID. \ref cy_en_usbpd_adc_id_t
*
* \param level
* The 8-bit ADC reading.
*
* \return uint16_t
* Returns voltage in mV.
*
*******************************************************************************/
uint16_t Cy_USBPD_Adc_GetVbusVolt(cy_stc_usbpd_context_t *context, cy_en_usbpd_adc_id_t adcId, uint8_t level)
{
    uint16_t result;

    /* We need to multiply PD_ADC_NUM_LEVELS by 2 as vbusMonDiv has been pre-multiplied by 2. */
    result = ((level * context->adcVdddMv[adcId] * context->vbusMonDiv)/(PD_ADC_NUM_LEVELS << 1u));
    return result;
}


/*******************************************************************************
* Function Name: Cy_USBPD_Vbus_SetDetachParams
****************************************************************************//**
*
* Select the comparator block and input setting used for VBus detach
* detection. PMG1 will use the selected settings to detect Type-C disconnection
* based on removal of the VBus power.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \param adcId
* ADC ID. \ref cy_en_usbpd_adc_id_t
*
* \param adcInp
* ADC input source.
*
*******************************************************************************/
void Cy_USBPD_Vbus_SetDetachParams(cy_stc_usbpd_context_t *context, cy_en_usbpd_adc_id_t adcId, cy_en_usbpd_adc_input_t adcInp)
{
    context->vbusDetachAdcInp = adcInp;
    context->vbusDetachAdcId    = adcId;
}


/*******************************************************************************
* Function Name: Cy_USBPD_Adc_FreeRunCtrl
****************************************************************************//**
*
* Configures the ADC for comparator functionality with the requested
* threshold with no interrupts enabled.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \param adcId
* ADC ID.
*
* \param input
* ADC input source.
*
* \param level
* Comparator level (8-bit ADC count)
*
* \return
* \ref cy_en_usbpd_status_t
*
*******************************************************************************/
cy_en_usbpd_status_t Cy_USBPD_Adc_FreeRunCtrl(cy_stc_usbpd_context_t *context, cy_en_usbpd_adc_id_t adcId,
                                            cy_en_usbpd_adc_input_t input, uint8_t level)
{
    PPDSS_REGS_T pd = context->base;
#if defined(CY_IP_MXUSBPD)
    uint32_t regVal = (uint32_t)level;

    if (context->adcRefVddd[adcId])
    {
        regVal |= PDSS_ADC_CTRL_VREF_DAC_SEL;
    }
#endif /* defined(CY_IP_MXUSBPD) */

#if (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
    /* Disable interrupts. */
    pd->intr3_mask &= (uint32_t)(~((1UL << PDSS_INTR3_CMP_OUT_CHANGED_POS) << (uint8_t)adcId));
    pd->intr3 = ((1UL << PDSS_INTR3_CMP_OUT_CHANGED_POS) << (uint8_t)adcId);

    /* Configure ADC */
    pd->adc_ctrl[adcId] = regVal | PDSS_ADC_CTRL_ADC_ISO_N |
            (((uint32_t)input << PDSS_ADC_CTRL_VSEL_POS) & PDSS_ADC_CTRL_VSEL_MASK);
#endif /* defined(CY_DEVICE_CCG3PA) */

#if (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_CCG6DF) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP))
    /* Disable interrupts. */
    pd->intr3_mask &= ~PDSS_INTR3_CMP_OUT_CHANGED;
    pd->intr3 = PDSS_INTR3_CMP_OUT_CHANGED;

    /* Temporary save intr3_cfg_adc_hs reg value */
    uint32_t temp_intr3_cfg_adc_hs = pd->intr3_cfg_adc_hs;
    /*
     * Make sure filter on ADC output is disabled while configure ADC as a comparator
     * to support FRS operation to avoid any false glitch on output getting detected
     * as vbus < 5 V and enable the filter after adc inputs are stable.
     */
    pd->intr3_cfg_adc_hs &= ~(PDSS_INTR3_CFG_ADC_HS_FILT_EN | PDSS_INTR3_CFG_ADC_HS_FILT_BYPASS | PDSS_INTR3_CFG_ADC_HS_DPSLP_MODE | PDSS_INTR3_CFG_ADC_HS_FILT_CFG_MASK);

    /* Configure ADC */
    pd->adc_ctrl = regVal | PDSS_ADC_CTRL_ADC_ISO_N |
            (((uint32_t)input << PDSS_ADC_CTRL_VSEL_POS) & PDSS_ADC_CTRL_VSEL_MASK);

    /* Restore intr3_cfg_adc_hs reg value */
    Cy_SysLib_DelayUs(5u);
    pd->intr3_cfg_adc_hs = temp_intr3_cfg_adc_hs;
#endif /* (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_CCG6DF) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP)) */

#if defined(CY_DEVICE_CCG3)
    if (adcId == CY_USBPD_ADC_ID_0)
    {
        /* Disable interrupts. */
        pd->intr1_mask &= ~PDSS_INTR1_CMP_OUT1_CHANGED;
        pd->intr1 = PDSS_INTR1_CMP_OUT1_CHANGED;

        pd->adc1_ctrl = (uint32_t)level | PDSS_ADC1_CTRL_ADC_ISO_N |
            (((uint32_t)input << PDSS_ADC1_CTRL_VSEL_POS) & PDSS_ADC1_CTRL_VSEL_MASK);

    }
    else
    {
        /* Disable interrupts. */
        pd->intr1_mask &= ~PDSS_INTR1_CMP_OUT2_CHANGED;
        pd->intr1 = PDSS_INTR1_CMP_OUT2_CHANGED;

        pd->adc2_ctrl = (uint32_t)level | PDSS_ADC2_CTRL_ADC_ISO_N |
            (((uint32_t)input << PDSS_ADC2_CTRL_VSEL_POS) & PDSS_ADC2_CTRL_VSEL_MASK);
    }
#endif /* defined(CY_DEVICE_CCG3) */

    /* Only one ADC supported on some devices. */
    CY_UNUSED_PARAMETER(adcId);

    return CY_USBPD_STAT_SUCCESS;
}

/*******************************************************************************
* Function Name: Cy_USBPD_Adc_CompCtrl
****************************************************************************//**
*
* Configures the ADC for comparator functionality with
* the requested threshold, and registers a callback which shall be called
* when the comparator output changes.
* This function configures the ADC block as a comparator. The function takes
* the input to be configured and the ADC comparator threshold. It also takes a
* callback. If the callback is not NULL, then the threshold is configured and
* interrupts are enabled. If the callback is NULL, then the ADC / comparator
* is set to the low power state and interrupts are disabled.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \param adcId
* ADC ID.
*
* \param input
* ADC input source.
*
* \param level
* Comparator level (8-bit ADC count)
*
* \param intCfg
* Interrupt configuration
*
* \param cb
* Callback to be called on interrupt.
*
*******************************************************************************/
void Cy_USBPD_Adc_CompCtrl(cy_stc_usbpd_context_t *context, cy_en_usbpd_adc_id_t adcId, cy_en_usbpd_adc_input_t input,
                            uint8_t level, cy_en_usbpd_adc_int_t intCfg, cy_cb_adc_events_t cb)
{
    PPDSS_REGS_T pd = context->base;
    uint32_t state;
    bool out;
    uint32_t regVal = (uint32_t)level;

    state = Cy_SysLib_EnterCriticalSection();

    context->adcCb[adcId] = cb;
#if defined(CY_IP_MXUSBPD)
    if (context->adcRefVddd[adcId])
    {
        regVal |= PDSS_ADC_CTRL_VREF_DAC_SEL;
    }
#endif /* defined(CY_IP_MXUSBPD) */

#if (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
    if (cb != NULL)
    {
        pd->intr3_cfg_adc_hs[adcId] &= ~PDSS_INTR3_CFG_ADC_HS_FILT_CFG_MASK;
        pd->intr3_cfg_adc_hs[adcId] |= ((uint32_t)intCfg << PDSS_INTR3_CFG_ADC_HS_FILT_CFG_POS);
        pd->adc_ctrl[adcId] = regVal | PDSS_ADC_CTRL_ADC_ISO_N |
            (((uint32_t)input << PDSS_ADC_CTRL_VSEL_POS) & PDSS_ADC_CTRL_VSEL_MASK);
        /* Delay 10us for the input selection to stabilize. */
        Cy_SysLib_DelayUs(10);

        /* Clear comparator interrupts. */
        pd->intr3 = ((1UL << PDSS_INTR3_CMP_OUT_CHANGED_POS) << (uint8_t)adcId);

        /* Enable comparator interrupts. */
        pd->intr3_mask |= ((1UL << PDSS_INTR3_CMP_OUT_CHANGED_POS) << (uint8_t)adcId);

        if ((pd->adc_ctrl[adcId] & PDSS_ADC_CTRL_CMP_OUT) != 0U)
        {
            out = true;
        }
        else
        {
            out = false;
       }
        if (((intCfg ==  CY_USBPD_ADC_INT_FALLING) && (out == false)) ||
            ((intCfg ==  CY_USBPD_ADC_INT_RISING) && (out == true)))
        {
            /* Raise an interrupt. */
            pd->intr3_set |= ((uint32_t)PDSS_INTR3_CMP_OUT_CHANGED_POS << (uint8_t)adcId);
        }
    }
    else
    {
        /* Revert register configuration. */
        pd->adc_ctrl[adcId] = PDSS_ADC_CTRL_ADC_ISO_N | PDSS_ADC_CTRL_PD_LV;

        /* Disable interrupts. */
        pd->intr3_mask &= (~((1UL << PDSS_INTR3_CMP_OUT_CHANGED_POS) << (uint8_t)adcId));
        pd->intr3 = ((1UL << PDSS_INTR3_CMP_OUT_CHANGED_POS) << (uint8_t)adcId);
    }
#endif /* defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1) */

#if (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_CCG6DF) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP))
    if (cb != NULL)
    {
        pd->intr3_cfg_adc_hs = Cy_USBPD_MmioRegUpdateField(pd->intr3_cfg_adc_hs, (uint32_t)intCfg,
                PDSS_INTR3_CFG_ADC_HS_FILT_CFG_MASK, (uint8_t)PDSS_INTR3_CFG_ADC_HS_FILT_CFG_POS);
        pd->adc_ctrl = regVal | PDSS_ADC_CTRL_ADC_ISO_N |
                        (((uint32_t)input << PDSS_ADC_CTRL_VSEL_POS) & PDSS_ADC_CTRL_VSEL_MASK);
        /* Delay 10us for the input selection to stabilize. */
        Cy_SysLib_DelayUs(10);

        /* Clear comparator interrupts. */
        pd->intr3 = PDSS_INTR3_CMP_OUT_CHANGED;

        /* Enable comparator interrupts. */
        pd->intr3_mask |= PDSS_INTR3_CMP_OUT_CHANGED;

        if ((pd->adc_ctrl & PDSS_ADC_CTRL_CMP_OUT) != 0U)
        {
            out = true;
        }
        else
        {
            out = false;
        }
        if (((intCfg ==  CY_USBPD_ADC_INT_FALLING) && (out == false)) ||
            ((intCfg ==  CY_USBPD_ADC_INT_RISING) && (out == true)))
        {
            /* Raise an interrupt. */
            pd->intr3_set |= PDSS_INTR3_CMP_OUT_CHANGED;
        }
    }
    else
    {
        /* Revert register configuration. */
        pd->adc_ctrl = PDSS_ADC_CTRL_ADC_ISO_N | PDSS_ADC_CTRL_PD_LV;

        /* Disable interrupts. */
        pd->intr3_mask &= ~(PDSS_INTR3_CMP_OUT_CHANGED);
        pd->intr3 = PDSS_INTR3_CMP_OUT_CHANGED;
    }
#endif /* (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_CCG6DF) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP)) */

#if defined(CY_DEVICE_CCG3)
    if (cb != NULL)
    {
        if (adcId == CY_USBPD_ADC_ID_0)
        {
            /* Load the interrupt configuration. */
            regVal = pd->intr_1_cfg & ~PDSS_INTR_1_CFG_ADC1_CFG_MASK;
            pd->intr_1_cfg = ((uint32_t)intCfg << PDSS_INTR_1_CFG_ADC1_CFG_POS) | regVal;

            pd->adc1_ctrl = (uint32_t)level | PDSS_ADC1_CTRL_ADC_ISO_N |
                (((uint32_t)input << PDSS_ADC1_CTRL_VSEL_POS) & PDSS_ADC1_CTRL_VSEL_MASK);
            Cy_SysLib_DelayUs(10);

            /* Clear comparator interrupts. */
            pd->intr1 = PDSS_INTR1_CMP_OUT1_CHANGED;

            /* Enable comparator interrupts. */
            pd->intr1_mask |= PDSS_INTR1_CMP_OUT1_CHANGED;
            if ((pd->adc1_ctrl & PDSS_ADC1_CTRL_CMP_OUT) != 0U)
            {
                out = true;
            }
            else
            {
                out = false;
            }

            if (((intCfg ==  CY_USBPD_ADC_INT_FALLING) && (out == false)) ||
                    ((intCfg ==  CY_USBPD_ADC_INT_RISING) && (out == true)))
            {
                /* Raise an interrupt. */
                pd->intr1_set |= PDSS_INTR1_CMP_OUT1_CHANGED;
            }
        }
        else
        {
            /* Load the interrupt configuration. */
            regVal = pd->intr_1_cfg & ~PDSS_INTR_1_CFG_ADC2_CFG_MASK;
            pd->intr_1_cfg = ((uint32_t)intCfg << PDSS_INTR_1_CFG_ADC2_CFG_POS) | regVal;

            pd->adc2_ctrl = (uint32_t)level | PDSS_ADC2_CTRL_ADC_ISO_N |
                (((uint32_t)input << PDSS_ADC2_CTRL_VSEL_POS) & PDSS_ADC2_CTRL_VSEL_MASK);
            Cy_SysLib_DelayUs(10);

            /* Clear comparator interrupts. */
            pd->intr1 = PDSS_INTR1_CMP_OUT2_CHANGED;

            /* Enable comparator interrupts. */
            pd->intr1_mask |= PDSS_INTR1_CMP_OUT2_CHANGED;

            if ((pd->adc2_ctrl & PDSS_ADC2_CTRL_CMP_OUT) != 0U)
            {
                out = true;
            }
            else
            {
                out = false;
            }

            if (((intCfg == CY_USBPD_ADC_INT_FALLING) && (out == false)) ||
                    ((intCfg == CY_USBPD_ADC_INT_RISING) && (out == true)))
            {
                /* Raise an interrupt. */
                pd->intr1_set |= PDSS_INTR1_CMP_OUT2_CHANGED;
            }
        }
    }
    else
    {
        if (adcId == CY_USBPD_ADC_ID_0)
        {
            /* Revert register configuration. */
            pd->adc1_ctrl = PDSS_ADC1_CTRL_ADC_ISO_N | PDSS_ADC1_CTRL_PD_LV;

            /* Disable interrupts. */
            pd->intr1_mask &= ~PDSS_INTR1_CMP_OUT1_CHANGED;
            pd->intr1 = PDSS_INTR1_CMP_OUT1_CHANGED;
        }
        else
        {
            /* Revert register configuration. */
            pd->adc2_ctrl = PDSS_ADC2_CTRL_ADC_ISO_N | PDSS_ADC2_CTRL_PD_LV;

            /* Disable interrupts. */
            pd->intr1_mask &= ~PDSS_INTR1_CMP_OUT2_CHANGED;
            pd->intr1 = PDSS_INTR1_CMP_OUT2_CHANGED;
        }
    }
#endif /* defined(CY_DEVICE_CCG3) */

    /* Only one ADC supported on some devices. */
    CY_UNUSED_PARAMETER(adcId);

    Cy_SysLib_ExitCriticalSection(state);
}

#if defined(CY_IP_MXUSBPD)
static void pd_adc_restore_intr(cy_stc_usbpd_context_t *context, cy_en_usbpd_adc_id_t adcId, uint32_t regAdcCtrl)
{
    PPDSS_REGS_T pd = context->base;
    uint32_t regVal;
    bool out;
    (void)adcId;

#if (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
    /* Revert register configuration. */
    pd->adc_ctrl[adcId] = regAdcCtrl;
    Cy_SysLib_DelayUs(10);

    pd->intr3 = ((uint32_t)PDSS_INTR3_CMP_OUT_CHANGED_POS << (uint8_t)adcId);

    if (((pd->intr3_mask & ((1UL << PDSS_INTR3_CMP_OUT_CHANGED_POS) << (uint8_t)adcId)) != 0U) &&
        ((regAdcCtrl & PDSS_ADC_CTRL_PD_LV) == 0U))
    {
        regVal = (pd->intr3_cfg_adc_hs[adcId] & PDSS_INTR3_CFG_ADC_HS_FILT_CFG_MASK) >>
            PDSS_INTR3_CFG_ADC_HS_FILT_CFG_POS;

        if ((pd->adc_ctrl[adcId] & PDSS_ADC_CTRL_CMP_OUT) != 0U)
        {
            out = true;
        }
        else
        {
            out = false;
        }

        if (((regVal == (uint32_t)CY_USBPD_ADC_INT_FALLING) && (out == false)) ||
            ((regVal == (uint32_t)CY_USBPD_ADC_INT_RISING) && (out == true)))
        {
            /* Raise an interrupt. */
            pd->intr3_set |= ((1UL << PDSS_INTR3_CMP_OUT_CHANGED_POS) << (uint8_t)adcId);
        }
    }
#endif /* (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) */

#if (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_CCG6DF) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP))
    /* Revert register configuration. */
    pd->adc_ctrl = regAdcCtrl;
    Cy_SysLib_DelayUs(10);

    pd->intr3 = PDSS_INTR3_CMP_OUT_CHANGED;

    if (((pd->intr3_mask & PDSS_INTR3_CMP_OUT_CHANGED) != 0U) &&
        ((regAdcCtrl & PDSS_ADC_CTRL_PD_LV) == 0U))
    {
        regVal = (pd->intr3_cfg_adc_hs & PDSS_INTR3_CFG_ADC_HS_FILT_CFG_MASK) >>
            PDSS_INTR3_CFG_ADC_HS_FILT_CFG_POS;

        if ((pd->adc_ctrl & PDSS_ADC_CTRL_CMP_OUT) != 0U)
        {
            out = true;
        }
        else
        {
            out = false;
        }

        if (((regVal == (uint32_t)CY_USBPD_ADC_INT_FALLING) && (out == false)) ||
            ((regVal == (uint32_t)CY_USBPD_ADC_INT_RISING) && (out == true)))
        {
            /* Raise an interrupt. */
            pd->intr3_set |= PDSS_INTR3_CMP_OUT_CHANGED;
        }
    }
#endif /* (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_CCG6DF) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP)) */
}
#endif /* defined(CY_IP_MXUSBPD) */

/*******************************************************************************
* Function Name: Cy_USBPD_Adc_CompSample
****************************************************************************//**
*
* Temporarily configures the comparator as requested and
* checks whether the input exceeds the specified digital level.
* This function restores the comparator to its previous state after operation. This
* is useful when the comparator is already configured to function with a certain
* input and level with interrupt and another reading needs to be done without
* having to re-configure the block after the sampling.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \param adcId
* ADC ID.
*
* \param input
* ADC input source.
*
* \param level
* Value(8-bit ADC count) to compare the input voltage against.
*
* \return bool
* Returns true if voltage > level, false otherwise.
*
*******************************************************************************/
bool Cy_USBPD_Adc_CompSample(cy_stc_usbpd_context_t *context, cy_en_usbpd_adc_id_t adcId,
                             cy_en_usbpd_adc_input_t input, uint8_t level)
{
    PPDSS_REGS_T pd = context->base;
    uint32_t regAdcCtrl;
    uint32_t regVal = (uint32_t)level;
    uint32_t state;
    bool compOut = true;

#if (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_CCG6DF) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP))
    /* adcId is irrelevant as only one ADC is supported. */
    CY_UNUSED_PARAMETER(adcId);
#endif /* (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_CCG6DF) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP)) */

    /* Store previous configuration and disable interrupts. */
    state = Cy_SysLib_EnterCriticalSection();

#if defined(CY_IP_MXUSBPD)
    if (context->adcRefVddd[adcId])
    {
        regVal |= PDSS_ADC_CTRL_VREF_DAC_SEL;
    }

#if (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
    regAdcCtrl = pd->adc_ctrl[adcId];

    /* Configure the input and level. */
    pd->adc_ctrl[adcId] = regVal | PDSS_ADC_CTRL_ADC_ISO_N |
            (((uint32_t)input << PDSS_ADC_CTRL_VSEL_POS) & PDSS_ADC_CTRL_VSEL_MASK);

    /* Delay 10us for the input selection to stabilize. */
    Cy_SysLib_DelayUs(10);

    if ((pd->adc_ctrl[adcId] & PDSS_ADC_CTRL_CMP_OUT) != 0U)
    {
        compOut = false;
    }
#endif /* (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) */

#if (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_CCG6DF) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP))
    regAdcCtrl = pd->adc_ctrl;

    /* Configure the input and level. */
    pd->adc_ctrl = regVal | PDSS_ADC_CTRL_ADC_ISO_N |
            (((uint32_t)input << PDSS_ADC_CTRL_VSEL_POS) & PDSS_ADC_CTRL_VSEL_MASK);

    /* Delay 10us for the input selection to stabilize. */
    Cy_SysLib_DelayUs(10);

    if ((pd->adc_ctrl & PDSS_ADC_CTRL_CMP_OUT) != 0U)
    {
        compOut = false;
    }
#endif /* (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_CCG6DF) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP)) */

    pd_adc_restore_intr(context, adcId, regAdcCtrl);
#endif /* defined(CY_IP_MXUSBPD) */

#if defined(CY_DEVICE_CCG3)
    if (adcId == CY_USBPD_ADC_ID_0)
    {
        regAdcCtrl = pd->adc1_ctrl;

        /* Configure the input and level. */
        pd->adc1_ctrl = (uint32_t)level | PDSS_ADC1_CTRL_ADC_ISO_N |
            (((uint32_t)input << PDSS_ADC1_CTRL_VSEL_POS) & PDSS_ADC1_CTRL_VSEL_MASK);
        Cy_SysLib_DelayUs (10);

        if ((pd->adc1_ctrl & PDSS_ADC1_CTRL_CMP_OUT) != 0U)
        {
            compOut = false;
        }

        /* Revert register configuration. */
        pd->adc1_ctrl = regAdcCtrl;
        Cy_SysLib_DelayUs (10);

        pd->intr1 = PDSS_INTR1_CMP_OUT1_CHANGED;
        if (((pd->intr1_mask & PDSS_INTR1_CMP_OUT1_CHANGED) != 0U) &&
                ((regAdcCtrl & PDSS_ADC1_CTRL_PD_LV) == 0U))
        {
            regVal = (pd->intr_1_cfg & PDSS_INTR_1_CFG_ADC1_CFG_MASK) >> PDSS_INTR_1_CFG_ADC1_CFG_POS;

            if (
                    (((pd->adc1_ctrl & PDSS_ADC1_CTRL_CMP_OUT) != 0U) && (regVal == (uint32_t)CY_USBPD_ADC_INT_RISING)) ||
                    (((pd->adc1_ctrl & PDSS_ADC1_CTRL_CMP_OUT) == 0U) && (regVal == (uint32_t)CY_USBPD_ADC_INT_FALLING))
               )
            {
                /* Raise an interrupt. */
                pd->intr1_set |= PDSS_INTR1_CMP_OUT1_CHANGED;
            }
        }
    }
    else
    {
        regAdcCtrl = pd->adc2_ctrl;

        /* Configure the input and level. */
        pd->adc2_ctrl = ((uint32_t)level | PDSS_ADC2_CTRL_ADC_ISO_N |
                (((uint32_t)input << PDSS_ADC2_CTRL_VSEL_POS) & PDSS_ADC2_CTRL_VSEL_MASK));
        Cy_SysLib_DelayUs (10);

        if ((pd->adc2_ctrl & PDSS_ADC2_CTRL_CMP_OUT) != 0U)
        {
            compOut = false;
        }

        /* Revert register configuration. */
        pd->adc2_ctrl = regAdcCtrl;
        Cy_SysLib_DelayUs(10);

        pd->intr1 = PDSS_INTR1_CMP_OUT2_CHANGED;
        if (((pd->intr1_mask & PDSS_INTR1_CMP_OUT2_CHANGED) != 0U) &&
                ((regAdcCtrl & PDSS_ADC2_CTRL_PD_LV) == 0U))
        {
            regVal = (pd->intr_1_cfg & PDSS_INTR_1_CFG_ADC2_CFG_MASK) >> PDSS_INTR_1_CFG_ADC2_CFG_POS;

            if (
                    (((pd->adc2_ctrl & PDSS_ADC2_CTRL_CMP_OUT) != 0U) && (regVal == (uint32_t)CY_USBPD_ADC_INT_RISING)) ||
                    (((pd->adc2_ctrl & PDSS_ADC2_CTRL_CMP_OUT) == 0U) && (regVal == (uint32_t)CY_USBPD_ADC_INT_FALLING))
               )
            {
                /* Raise an interrupt. */
                pd->intr1_set |= PDSS_INTR1_CMP_OUT2_CHANGED;
            }
        }
    }
#endif /* defined(CY_DEVICE_CCG3) */

    Cy_SysLib_ExitCriticalSection(state);

    return compOut;
}

/*******************************************************************************
* Function Name: Cy_USBPD_Adc_GetCompStatus
****************************************************************************//**
*
* Gets the current comparator status.
* This function does not configure the ADC / comparator. It just returns the
* current state of the comparator. If true is returned, then the input voltage
* is greater than the reference and if false, the input voltage is lower than
* the reference.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \param adcId
* ADC ID.
*
* \return bool
* Returns the comparator output.
*
*******************************************************************************/
bool Cy_USBPD_Adc_GetCompStatus(cy_stc_usbpd_context_t *context, cy_en_usbpd_adc_id_t adcId)
{
    PPDSS_REGS_T pd = context->base;

    CY_UNUSED_PARAMETER(adcId);

#if (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
    if ((pd->adc_ctrl[adcId] & PDSS_ADC_CTRL_CMP_OUT) != 0U)
    {
        return false;
    }
#endif /* (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) */

#if (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_CCG6DF) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP))
    if ((pd->adc_ctrl & PDSS_ADC_CTRL_CMP_OUT) != 0U)
    {
        return false;
    }
#endif /* (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_CCG6DF) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP)) */

#if defined(CY_DEVICE_CCG3)
    if (adcId == CY_USBPD_ADC_ID_0)
    {
        if ((pd->adc1_ctrl & PDSS_ADC1_CTRL_CMP_OUT) != 0U)
        {
            return false;
        }
    }
    else
    {
        if ((pd->adc2_ctrl & PDSS_ADC2_CTRL_CMP_OUT) != 0U)
        {
            return false;
        }
    }
#endif /* defined(CY_DEVICE_CCG3) */

    return true;
}

/*******************************************************************************
* Function Name: Cy_USBPD_Adc_Sample
****************************************************************************//**
*
* Samples the ADC. This function enables the ADC block to function as an ADC and
* returns the sample value in ADC units. This function disables any previously
* configured comparator interrupts / settings before sampling and restores them
* after the sampling is done. If any interrupt scenario happens across the sampling,
*  the information is lost.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \param adcId
* ADC ID.
*
* \param input
* ADC input source.
*
* \return uint8_t
* Returns the ADC sampled value in counts.
*
*******************************************************************************/
uint8_t Cy_USBPD_Adc_Sample(cy_stc_usbpd_context_t *context, cy_en_usbpd_adc_id_t adcId, cy_en_usbpd_adc_input_t input)
{
    PPDSS_REGS_T pd = context->base;
    uint32_t state;
    uint32_t volatile timeout = 0;
    uint8_t level = 0;
    uint32_t regAdcCtrl;
    (void)adcId;

    /* Store previous configuration and disable interrupts. */
    state = Cy_SysLib_EnterCriticalSection();

#if defined(CY_IP_MXUSBPD)
#if (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
    regAdcCtrl = pd->adc_ctrl[adcId];

    /* Clear the SAR done interrupt. */
    pd->intr0 = (1UL << (PDSS_INTR0_SAR_DONE_POS + (uint32_t)adcId));

    /* Configure the input. */
    if (context->adcRefVddd[adcId])
    {
        pd->adc_ctrl[adcId] = PDSS_ADC_CTRL_VREF_DAC_SEL | PDSS_ADC_CTRL_ADC_ISO_N |
            (((uint32_t)input << PDSS_ADC_CTRL_VSEL_POS) & PDSS_ADC_CTRL_VSEL_MASK);
    }
    else
    {
        pd->adc_ctrl[adcId] = PDSS_ADC_CTRL_ADC_ISO_N | (((uint32_t)input << PDSS_ADC_CTRL_VSEL_POS) & PDSS_ADC_CTRL_VSEL_MASK);
    }
    pd->adc_sar_ctrl[adcId] |= PDSS_ADC_SAR_CTRL_SAR_EN;

    /* Wait for SAR done interrupt status or timeout. */
    while (timeout < PD_ADC_TIMEOUT_COUNT)
    {
        if ((pd->intr0 & (1UL << (PDSS_INTR0_SAR_DONE_POS + (uint32_t)adcId))) != 0UL)
        {
            break;
        }
        timeout++;
    }

    level = (uint8_t)((pd->adc_sar_ctrl[adcId] & PDSS_ADC_SAR_CTRL_SAR_OUT_MASK) >> PDSS_ADC_SAR_CTRL_SAR_OUT_POS);

    /* Clear the SAR done interrupt. */
    pd->intr0 = (1UL << (PDSS_INTR0_SAR_DONE_POS + (uint32_t)adcId));

#endif /* (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) */

#if (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_CCG6DF) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP))
    /* Disable the ADC interrupt output to prevent it from getting affected during the sample operation. */
#if defined(CY_DEVICE_CCG6DF_CFP)
    uint32_t cfg_adc_hs = pd->intr3_cfg_adc_hs;
    pd->intr3_cfg_adc_hs &= ~(PDSS_INTR3_CFG_ADC_HS_FILT_EN | PDSS_INTR3_CFG_ADC_HS_FILT_BYPASS | PDSS_INTR3_CFG_ADC_HS_DPSLP_MODE);
#else
    pd->intr3_cfg_adc_hs &= ~(PDSS_INTR3_CFG_ADC_HS_FILT_EN | PDSS_INTR3_CFG_ADC_HS_FILT_BYPASS);
#endif /* defined(CY_DEVICE_CCG6DF_CFP) */
    Cy_SysLib_DelayUs (5);

    regAdcCtrl = pd->adc_ctrl;

    /* Clear the SAR done interrupt. */
#if defined(CY_DEVICE_CCG6DF_CFP)
    pd->intr21 = PDSS_INTR21_SAR_DONE;
#else
    pd->intr0 = PDSS_INTR0_SAR_DONE;
#endif /* defined(CY_DEVICE_CCG6DF_CFP) */

    /* Configure the input. */
    if (context->adcRefVddd[adcId])
    {
        pd->adc_ctrl = PDSS_ADC_CTRL_VREF_DAC_SEL | PDSS_ADC_CTRL_ADC_ISO_N |
            (((uint32_t)input << PDSS_ADC_CTRL_VSEL_POS) & PDSS_ADC_CTRL_VSEL_MASK);
    }
    else
    {
        pd->adc_ctrl = PDSS_ADC_CTRL_ADC_ISO_N |
            (((uint32_t)input << PDSS_ADC_CTRL_VSEL_POS) & PDSS_ADC_CTRL_VSEL_MASK);
    }
    pd->adc_sar_ctrl |= PDSS_ADC_SAR_CTRL_SAR_EN;

    /* Wait for SAR done interrupt status or timeout. */
    while (timeout < PD_ADC_TIMEOUT_COUNT)
    {
#if defined(CY_DEVICE_CCG6DF_CFP)
        if ((pd->intr21 & PDSS_INTR21_SAR_DONE) != 0U)
#else
        if ((pd->intr0 & PDSS_INTR0_SAR_DONE) != 0U)
#endif /* defined(CY_DEVICE_CCG6DF_CFP) */
        {
            break;
        }
        timeout++;
    }

    /* Delay required between SAR_EN bit to be cleared and value to be loaded. */
    Cy_SysLib_DelayUs(2);

    level = (uint8_t)((pd->adc_sar_ctrl & PDSS_ADC_SAR_CTRL_SAR_OUT_MASK) >> PDSS_ADC_SAR_CTRL_SAR_OUT_POS);

    /* Clear the SAR done interrupt. */
#if defined(CY_DEVICE_CCG6DF_CFP)
    pd->intr21 = PDSS_INTR21_SAR_DONE;
#else
    pd->intr0 = PDSS_INTR0_SAR_DONE;
#endif /* defined(CY_DEVICE_CCG6DF_CFP) */
#endif /* (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_CCG6DF) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP)) */

    pd_adc_restore_intr(context, adcId, regAdcCtrl);

#if (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_CCG6DF) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP))
    /* Bypass the filter on the ADC output again. */
#if defined(CY_DEVICE_CCG6DF_CFP)
    pd->intr3_cfg_adc_hs = cfg_adc_hs;
#else
    pd->intr3_cfg_adc_hs |= PDSS_INTR3_CFG_ADC_HS_FILT_BYPASS;
#endif /* defined(CY_DEVICE_CCG6DF_CFP) */
#endif /* (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_CCG6DF) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP)) */

#endif /* defined(CY_IP_MXUSBPD) */

#if defined(CY_DEVICE_CCG3)
    uint32_t rval;

    volatile uint32_t *adc_ctrl_reg_p;
    volatile uint32_t *adc_sar_ctrl_reg_p;
    uint32_t           adc_intr_mask;
    uint32_t           adc_intr_cfg;
    uint32_t           adc_intr_cfg_pos;

    if (adcId == CY_USBPD_ADC_ID_0)
    {
        adc_ctrl_reg_p     = &(pd->adc1_ctrl);
        adc_sar_ctrl_reg_p = &(pd->adc1_sar_ctrl);
        adc_intr_mask      = PDSS_INTR1_CMP_OUT1_CHANGED;
        adc_intr_cfg       = PDSS_INTR_1_CFG_ADC1_CFG_MASK;
        adc_intr_cfg_pos   = PDSS_INTR_1_CFG_ADC1_CFG_POS;
    }
    else
    {
        adc_ctrl_reg_p     = &(pd->adc2_ctrl);
        adc_sar_ctrl_reg_p = &(pd->adc2_sar_ctrl);
        adc_intr_mask      = PDSS_INTR1_CMP_OUT2_CHANGED;
        adc_intr_cfg       = PDSS_INTR_1_CFG_ADC2_CFG_MASK;
        adc_intr_cfg_pos   = PDSS_INTR_1_CFG_ADC2_CFG_POS;
    }

    /* Store previous configuration. */
    regAdcCtrl = *adc_ctrl_reg_p;

    /* Configure the input. */
    *adc_ctrl_reg_p = PDSS_ADC1_CTRL_ADC_ISO_N |
        (((uint32_t)input << PDSS_ADC1_CTRL_VSEL_POS) & PDSS_ADC1_CTRL_VSEL_MASK);
    *adc_sar_ctrl_reg_p |= PDSS_ADC1_SAR_CTRL_SAR_EN;

    /* Wait for sampling to complete or timeout. */
    while (timeout < PD_ADC_TIMEOUT_COUNT)
    {
        if ((*adc_sar_ctrl_reg_p & PDSS_ADC1_SAR_CTRL_SAR_EN) == 0U)
        {
            break;
        }
        timeout++;
    }

    /* Delay required between SAR_EN bit to be cleared and value to be loaded. */
    Cy_SysLib_DelayUs (2);

    level = (uint8_t)((*adc_sar_ctrl_reg_p & PDSS_ADC1_SAR_CTRL_SAR_OUT_MASK) >>
            PDSS_ADC1_SAR_CTRL_SAR_OUT_POS);

    /* Revert register configuration. */
    *adc_ctrl_reg_p = regAdcCtrl;
    Cy_SysLib_DelayUs (10);
    pd->intr1 = adc_intr_mask;

    if (((pd->intr1_mask & adc_intr_mask) != 0U) && ((regAdcCtrl & PDSS_ADC1_CTRL_PD_LV) == 0U))
    {
        rval = (pd->intr_1_cfg & adc_intr_cfg) >> adc_intr_cfg_pos;

        if (
                (((*adc_ctrl_reg_p & PDSS_ADC1_CTRL_CMP_OUT) != 0U) && (rval == (uint32_t)CY_USBPD_ADC_INT_RISING)) ||
                (((*adc_ctrl_reg_p & PDSS_ADC1_CTRL_CMP_OUT) == 0U) && (rval == (uint32_t)CY_USBPD_ADC_INT_FALLING))
           )
        {
            /* Raise an interrupt. */
            pd->intr1_set |= adc_intr_mask;
        }
    }
#endif /* defined(CY_DEVICE_CCG3) */

    Cy_SysLib_ExitCriticalSection(state);

    return level;
}

/*******************************************************************************
* Function Name: Cy_USBPD_Adc_SampleInput
****************************************************************************//**
*
* Samples the ADC. This function enables the ADC block to function as an ADC and
* returns the sample value in ADC units. This function disables any previously
* configured comparator interrupts / settings before sampling and restores them
* after the sampling is done. AMUX settings can additionally be changed to select 
* different input the ADC. Also ADC reference can be selected in cases where VREF
* shall be used for temperature measurement. If any interrupt scenario happens 
* across the sampling, the information is lost.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \param adcId
* ADC ID.
*
* \param input
* ADC input source.
*
* \param amux_nhv_ctrl_clr
* Bit mask to clear fields in amux_nhv_ctrl register.
*
* \param amux_nhv_ctrl_set
* Bit mask to set fields in amux_nhv_ctrl register.
*
* \param adc_vref
* ADC reference voltage selection.
*
* \return uint8_t
* Returns the ADC sampled value in counts.
*
*******************************************************************************/
uint8_t Cy_USBPD_Adc_SampleInput(cy_stc_usbpd_context_t *context, cy_en_usbpd_adc_id_t adcId, cy_en_usbpd_adc_input_t input, 
        uint32_t amux_nhv_ctrl_clr, uint32_t amux_nhv_ctrl_set, cy_en_usbpd_adc_vref_t adc_vref)
{
    uint32_t state;
    uint8_t level = 0;
    /* Store previous configuration and disable interrupts. */
    state = Cy_SysLib_EnterCriticalSection();

#if defined(CY_DEVICE_CCG6DF_CFP)
    CY_UNUSED_PARAMETER(adcId);
    PPDSS_REGS_T pd = context->base;
    uint32_t volatile timeout = 0;
    uint32_t regAdcCtrl;
    uint32_t amux_nhv_ctrl;
    uint32_t regval;
    /* Disable the ADC interrupt output to prevent it from getting affected during the sample operation. */
    uint32_t cfg_adc_hs = pd->intr3_cfg_adc_hs;
    pd->intr3_cfg_adc_hs &= ~(PDSS_INTR3_CFG_ADC_HS_FILT_EN | PDSS_INTR3_CFG_ADC_HS_FILT_BYPASS | PDSS_INTR3_CFG_ADC_HS_DPSLP_MODE);
    Cy_SysLib_DelayUs (5);

    /* Connect the AMUX nhv ctrl to connect input to ADC. */
    regval = pd->amux_nhv_ctrl;
    amux_nhv_ctrl = regval;
    /* Apply amux_nhv_ctrl_clr bit mask on regval. */
    regval &= (uint32_t)(~amux_nhv_ctrl_clr);
    /* Apply amux_nhv_ctrl_set bit mask on regval. */
    regval |= amux_nhv_ctrl_set;
    /* If amux settings changed then apply them. */
    if (regval != amux_nhv_ctrl)
    {
        pd->amux_nhv_ctrl = regval;
    }
    regAdcCtrl = pd->adc_ctrl;

    /* Clear the SAR done interrupt. */
    pd->intr21 = PDSS_INTR21_SAR_DONE;

    /* Configure the input. */
    regval = PDSS_ADC_CTRL_ADC_ISO_N | (((uint32_t)input << PDSS_ADC_CTRL_VSEL_POS) & PDSS_ADC_CTRL_VSEL_MASK);
    if (adc_vref == CY_USBPD_ADC_VREF_VDDD)
    {
        regval |= PDSS_ADC_CTRL_VREF_DAC_SEL;
    }
    if (adc_vref == CY_USBPD_ADC_VREF_MAX)
    {
        if (context->adcRefVddd[adcId])
        {
            regval |= PDSS_ADC_CTRL_VREF_DAC_SEL;
        }
    }
    pd->adc_ctrl = regval;
    /* Delay for the vsel input to settle. */
    Cy_SysLib_DelayUs(50);
    pd->adc_sar_ctrl |= PDSS_ADC_SAR_CTRL_SAR_EN;

    /* Wait for SAR done interrupt status or timeout. */
    while (timeout < PD_ADC_TIMEOUT_COUNT)
    {
        if ((pd->intr21 & PDSS_INTR21_SAR_DONE) != 0U)
        {
            break;
        }
        timeout++;
    }

    /* Delay required between SAR_EN bit to be cleared and value to be loaded. */
    Cy_SysLib_DelayUs(2);

    level = (uint8_t)((pd->adc_sar_ctrl & PDSS_ADC_SAR_CTRL_SAR_OUT_MASK) >> PDSS_ADC_SAR_CTRL_SAR_OUT_POS);

    /* Clear the SAR done interrupt. */
    pd->intr21 = PDSS_INTR21_SAR_DONE;

    /* If amux settings changed then restore back. */
    if (amux_nhv_ctrl != pd->amux_nhv_ctrl)
    {
#if (PDL_VBUS_OVP_ENABLE)
        uint32_t ov_filter_cfg = pd->intr5_filter_cfg[CY_USBPD_VBUS_FILTER_ID_OV];
        /* Disable OV filter */
        pd->intr5_filter_cfg[CY_USBPD_VBUS_FILTER_ID_OV] &= ~(PDSS_INTR5_FILTER_CFG_FILT_EN | PDSS_INTR5_FILTER_CFG_FILT_BYPASS | PDSS_INTR5_FILTER_CFG_DPSLP_MODE);
        /* Disable NGDO auto shut down upon OV fault. */
        pd->ngdo_p5c40_ctrl_0 &= ~PDSS_NGDO_P5C40_CTRL_0_FAULT_VBUS_OV_EN;
#endif /* (PDL_VBUS_OVP_ENABLE) */
        /* restore the amux nhv register settings. */
        pd->amux_nhv_ctrl = amux_nhv_ctrl;
        /* Delay for the back-kick voltage to drop down. */
        Cy_SysLib_DelayUs(5);
#if (PDL_VBUS_OVP_ENABLE)
        /* Restore the OV settings back to previous. */
        pd->intr5_filter_cfg[CY_USBPD_VBUS_FILTER_ID_OV] = ov_filter_cfg;
        pd->ngdo_p5c40_ctrl_0 |= PDSS_NGDO_P5C40_CTRL_0_FAULT_VBUS_OV_EN;
#endif /* (PDL_VBUS_OVP_ENABLE) */
    }
    /* Restore the PD ADC interrupt configuration. */
    pd_adc_restore_intr(context, adcId, regAdcCtrl);

    /* restore the ADC comparator filter output to FRS block. */
    pd->intr3_cfg_adc_hs = cfg_adc_hs;

#else
    CY_UNUSED_PARAMETER(context);
    CY_UNUSED_PARAMETER(adcId);
    CY_UNUSED_PARAMETER(input);
    CY_UNUSED_PARAMETER(amux_nhv_ctrl_clr);
    CY_UNUSED_PARAMETER(amux_nhv_ctrl_set);
    CY_UNUSED_PARAMETER(adc_vref);
#endif /* defined(CY_DEVICE_CCG6DF_CFP) */

    /* Exit critical section as the measurement is complete. */
    Cy_SysLib_ExitCriticalSection(state);

    return level;
}

/*******************************************************************************
* Function Name: Cy_USBPD_Adc_Calibrate
****************************************************************************//**
*
* Calibrates the specified ADC for operation.
* This function calibrates the specified ADC by identifying the VDDD voltage
* for reference. It should be noted that by calling the function, the
* previously calculated threshold levels may have to be changed based on the
* VDDD reading. The VDDD level is calculated based on the bandgap voltage
* which is expected to be constant.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \param adcId
* ADC ID.
*
* \return uint16_t
* Returns the VDDD value in mV after calibration.
*
*******************************************************************************/
uint16_t Cy_USBPD_Adc_Calibrate(cy_stc_usbpd_context_t *context, cy_en_usbpd_adc_id_t adcId)
{
    uint8_t  level;
    uint32_t threshold;

#if defined(CY_IP_MXUSBPD)
    if (context->adcRefVddd[adcId])
#endif /* defined(CY_IP_MXUSBPD) */
    {
        level = Cy_USBPD_Adc_Sample(context, adcId, CY_USBPD_ADC_INPUT_BANDGAP);

        /* Check for zero. If level came out as zero, then do not calculate. */
        if (level != 0U)
        {
            threshold = ((PD_ADC_BAND_GAP_VOLT_MV * PD_ADC_NUM_LEVELS) / (uint32_t)level);
            context->adcVdddMv[adcId] = (uint16_t)threshold;
        }
    }

    return context->adcVdddMv[adcId];
}

/*******************************************************************************
* Function Name: Cy_USBPD_Adc_SelectVref
****************************************************************************//**
*
* Selects the reference voltage used by the ADC block
* on the PMG1 device. A 2.0 V supply generated by the RefGen block in the PD
* IP is used as ADC reference by default. This API can be used to select
* the VDDD supply as the ADC reference. This is useful in cases where voltages
* greater than 2.0 V need to be measured.
*
* Note: Since the VDDD supply level could vary across time, the ADC volts
* per division value needs to be calibrated before taking any ADC readings.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \param adcId
* ADC ID.
*
* \param vrefSel
* ADC reference selection.
*
* \return
* \ref cy_en_usbpd_status_t
*
*******************************************************************************/
cy_en_usbpd_status_t Cy_USBPD_Adc_SelectVref(cy_stc_usbpd_context_t *context, cy_en_usbpd_adc_id_t adcId,
                                             cy_en_usbpd_adc_vref_t vrefSel)
{
#if defined(CY_IP_M0S8USBPD)
    CY_UNUSED_PARAMETER(context);
    CY_UNUSED_PARAMETER(adcId);
    CY_UNUSED_PARAMETER(vrefSel);

    return CY_USBPD_STAT_INVALID_COMMAND;
#else
    PPDSS_REGS_T pd = context->base;
    uint16_t retVal = 0U;
    CY_UNUSED_PARAMETER(pd);

    if (vrefSel == CY_USBPD_ADC_VREF_VDDD)
    {
#if defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)
        /* Enable the ADC and power it down. */
        pd->adc_ctrl[adcId] |= PDSS_ADC_CTRL_VREF_DAC_SEL;
#endif /* defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1) */

#if (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_CCG6DF) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP))
        /* Enable the ADC and power it down. */
        pd->adc_ctrl |= PDSS_ADC_CTRL_VREF_DAC_SEL;
#endif /* (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_CCG6DF) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP)) */

        context->adcRefVddd[adcId] = true;
        retVal = Cy_USBPD_Adc_Calibrate (context, adcId);
        CY_UNUSED_PARAMETER(retVal);
    }
    else
    {
#if defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)
        /* Enable the ADC and power it down. */
        pd->adc_ctrl[adcId] &= ~PDSS_ADC_CTRL_VREF_DAC_SEL;
#endif /* defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1) */

#if (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_CCG6DF) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP))
        /* Enable the ADC and power it down. */
        pd->adc_ctrl &= ~PDSS_ADC_CTRL_VREF_DAC_SEL;
#endif /* (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_CCG6DF) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP)) */

        context->adcRefVddd[adcId] = false;
        context->adcVdddMv[adcId]  = MX_PD_ADC_REF_VOLT_MV;
    }

    return CY_USBPD_STAT_SUCCESS;
#endif /* CY_IP */
}

/*******************************************************************************
* Function Name: Cy_USBPD_Adc_GetVbusLevel
****************************************************************************//**
*
* Gets the ADC level that corresponds to the actual
* voltage on vbus. It also takes into account the VBus monitor divider.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \param adcId
* ADC ID.
*
* \param volt
* Voltage in 50mV units.
*
* \param per
* Percentage margin on the voltage.
*
* \return uint8_t
* Returns the ADC level.
*
*******************************************************************************/
uint8_t Cy_USBPD_Adc_GetVbusLevel(cy_stc_usbpd_context_t *context, cy_en_usbpd_adc_id_t adcId,
        uint16_t volt, int8_t per)
{
    int32_t threshold = ((int32_t)volt + (((int32_t)volt * (int32_t)per) / 100));

    /* Remove negative numbers. */
    if (threshold < 0)
    {
        threshold = 0;
    }

    /* Convert volts to ADC units. */
    return Cy_USBPD_Adc_VoltToLevel(context, adcId, (uint16_t)(2U * (uint32_t)threshold / context->vbusMonDiv));
}

/*******************************************************************************
* Function Name: Cy_USBPD_Vbus_Mon_SetDivider
****************************************************************************//**
*
* Specify the voltage division ratio between the voltage applied
* on VBUS_MON and the actual VBus voltage. The commonly used resistor divider
* ratio used is 1:10, giving a voltage division ratio of 1/11.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \param divider
* Divider Ratio between VBUS_MON voltage and VBus voltage.
*
*******************************************************************************/
void Cy_USBPD_Vbus_Mon_SetDivider(cy_stc_usbpd_context_t *context, uint8_t divider)
{
    /* Set the divider value */
    context->vbusMonDiv = divider;
}

/*******************************************************************************
* Function Name: Cy_USBPD_Adc_MeasureInternalTemp
****************************************************************************//**
*
* Measure the temperature using ADC and internal BJT temperature sensor.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \param adcId
* ADC ID.
*
* \param input
* ADC input source.
*
* \return int16_t
* Internal temperature in degree celsius units.
*
*******************************************************************************/
int16_t Cy_USBPD_Adc_MeasureInternalTemp(cy_stc_usbpd_context_t *context, cy_en_usbpd_adc_id_t adcId,
                                    cy_en_usbpd_adc_input_t input)
{
#if defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)
    uint8_t vbjt_code;
    int32_t internal_temp;
    uint32_t state;
    int16_t x0 = (int16_t)INTERNAL_BJT_LOW_TEMP;
    int16_t x1 = (int16_t)INTERNAL_BJT_HIGH_TEMP;
    int16_t y0 = (int16_t)*((uint8_t *)SFLASH_VBE_LOW_TEMP_TRIM_ADDR);
    int16_t y1 = (int16_t)*((uint8_t *)SFLASH_VBE_HIGH_TEMP_TRIM_ADDR);
    int16_t y2 = (int16_t)*((uint8_t *)SFLASH_VBE_25_C_TEMP_TRIM_ADDR);

    if (y0 == 0)
    {
        if(y1 == 0)
        {
            /* If sflash trims are not loaded, return fault temperature */
            return INTERNAL_BJT_FAULT_TEMP;
        }
        else
        {
            /* Use the ROOM temperature SFLASH reading as the LOW temperature to be used in calculation */
            y0 = y2;
            x0 = INTERNAL_BJT_ROOM_TEMP;
        }
    }
    else if ((y2 - y1) < (((y0 - y2) * 5) / 4))
    {
        /*
         * Check for validity of 120C ADC reading in SFLASH:
         * ADC delta from ROOM to HIGH should be at least 1.25x the delay from ROOM to LOW.
         */
            y1 = (int16_t)*((uint8_t *)SFLASH_VBE_25_C_TEMP_TRIM_ADDR);
            x1 = INTERNAL_BJT_ROOM_TEMP;
    }
    else
    {
        /* Do nothing */
    }

    int32_t y1_y0 = ((int32_t)y1 - (int32_t)y0);
    int32_t x1_x0 = ((int32_t)x1 - (int32_t)x0);
    int32_t y_y0;

    state = Cy_SysLib_EnterCriticalSection();
    vbjt_code = Cy_USBPD_Adc_Sample(context, adcId, input);
    Cy_SysLib_ExitCriticalSection(state);

    y_y0 =  ((int32_t)vbjt_code - (int16_t)y0);

    internal_temp = y_y0 * x1_x0;
    /* Shifting and performing division for rounding */
    internal_temp *= 2;
    internal_temp = internal_temp / y1_y0;
    internal_temp += 1;
    internal_temp /= 2;
    internal_temp = internal_temp + x0;
    return ((int16_t)internal_temp);
#else
    CY_UNUSED_PARAMETER(context);
    CY_UNUSED_PARAMETER(adcId);
    CY_UNUSED_PARAMETER(input);
    return 0xFF;
#endif /* defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1) */
}

/*******************************************************************************
* Function Name: Cy_USBPD_Adc_MeasureVbusIn
****************************************************************************//**
*
* Measure the current voltage on the VBus-in.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \param adcId
* ADC ID.
*
* \param input
* ADC input source.
*
* \return uint16_t
* VBus voltage in mV units.
*
*******************************************************************************/
uint16_t Cy_USBPD_Adc_MeasureVbusIn(cy_stc_usbpd_context_t *context, cy_en_usbpd_adc_id_t adcId,
                                    cy_en_usbpd_adc_input_t input)
{
#if PSVP_FPGA_ENABLE
    CY_UNUSED_PARAMETER(context);
    CY_UNUSED_PARAMETER(adcId);
    CY_UNUSED_PARAMETER(input);
#if (!defined(CY_DEVICE_CCG6DF_CFP))
    return ctrl_inf_get_vbus_in();
#else
    return false;
#endif /* (!defined(CY_DEVICE_CCG6DF_CFP)) */
#else /* !PSVP_FPGA_ENABLE */
    uint16_t retVal;

#if defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)
    uint32_t state;
    PPDSS_REGS_T pd = context->base;
    uint8_t level;

    state = Cy_SysLib_EnterCriticalSection();

#if defined(CY_DEVICE_CCG3PA)

/* Select VBUS_IN for ADC. VBUS_C in case of flipped FET control */
#if PMG1_FLIPPED_FET_CTRL
    pd->amux_nhv_ctrl &= ~((1U << AMUX_ADC_PMG1S0_VBUS_IN_8P_EN_POS) |
        (1U << AMUX_ADC_PMG1S0_VBUS_IN_20P_EN_POS));
#else /* PMG1_FLIPPED_FET_CTRL */
    pd->amux_nhv_ctrl |= ((1U << AMUX_ADC_PMG1S0_VBUS_IN_8P_EN_POS) |
        (1U << AMUX_ADC_PMG1S0_VBUS_IN_20P_EN_POS));
#endif /* PMG1_FLIPPED_FET_CTRL */

#elif defined(CY_DEVICE_PAG1S) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)

    pd->amux_nhvn_ctrl |= ((uint32_t)1u << AMUX_ADC_PAG1S_VBUS_IN_8P_EN_POS);

#endif /* defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1) */

    Cy_SysLib_DelayUs(20);

    /* Sample the VBus voltage using ADC. */
    level = Cy_USBPD_Adc_Sample(context, adcId, input);
    retVal = Cy_USBPD_Adc_GetVbusVolt(context, adcId, level);

#if defined(CY_DEVICE_CCG3PA)
    /*
     * NOTE: Currently accuracy of VBUS_IN measurement is required only for
     * direct feedback implementation. Other cases can remain using the
     * 8% divider. Switching to 20% divider takes considerably more time
     * and does not warrant locking the interrupts for that long.
     */
    /*
     * At low voltages, you may require higher accuracy. This can be done
     * by moving to a lower divider value of 20%. Do this only if required.
     */
    if (retVal < VBUS_DIV_20_PER_MAX_VOLT)
    {
        /* First set the AMUX to use 20% divider. */

        pd->amux_nhv_ctrl |= (1UL << AMUX_ADC_PMG1S0_VBUS_DIV_2OP_EN_POS);
        Cy_USBPD_Vbus_Mon_SetDivider(context, VBUS_MON_DIV_20P_VAL);
        Cy_SysLib_DelayUs(10);
        /* Now measure the voltage. */
        level = Cy_USBPD_Adc_Sample(context, adcId, input);
        retVal = Cy_USBPD_Adc_GetVbusVolt(context, adcId, level);

        /* Restore the divider value. */
        pd->amux_nhv_ctrl &= ~(1UL << AMUX_ADC_PMG1S0_VBUS_DIV_2OP_EN_POS);
        Cy_USBPD_Vbus_Mon_SetDivider(context, VBUS_MON_DIV_8P_VAL);
        Cy_SysLib_DelayUs(10);

        /*
         * NOTE: Currently ADC interrupt is not enabled when running when
         * sampling the VBUS. If this changes, the code has to be extended to
         * save and restore the status to prevent falsely triggering interrupts.
         */
    }
#endif /* defined(CY_DEVICE_CCG3PA) */

#if defined(CY_DEVICE_PAG1S) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)
    pd->amux_nhvn_ctrl &= ~((uint32_t)1u << AMUX_ADC_PAG1S_VBUS_IN_8P_EN_POS);
#else /* CCG3PA */

/* Deselect VBUS_IN for ADC. VBUS_C in case of flipped FET control */
#if PMG1_FLIPPED_FET_CTRL
    pd->amux_nhv_ctrl |= ((1UL << AMUX_ADC_PMG1S0_VBUS_IN_8P_EN_POS) |
        (1UL << AMUX_ADC_PMG1S0_VBUS_IN_20P_EN_POS));
#else /* PMG1_FLIPPED_FET_CTRL */
    pd->amux_nhv_ctrl &= ~((1UL << AMUX_ADC_PMG1S0_VBUS_IN_8P_EN_POS) |
        (1UL << AMUX_ADC_PMG1S0_VBUS_IN_20P_EN_POS));
#endif /* PMG1_FLIPPED_FET_CTRL */

#endif /* CCGx */

    Cy_SysLib_DelayUs(20);

    Cy_SysLib_ExitCriticalSection(state);
#else
    CY_UNUSED_PARAMETER(context);
    CY_UNUSED_PARAMETER(adcId);
    CY_UNUSED_PARAMETER(input);

    retVal = 0U;
#endif /* CCGx */

    return retVal;
#endif /* PSVP_FPGA_ENABLE */
}

/*******************************************************************************
* Function Name: Cy_USBPD_Adc_MeasureVbus
****************************************************************************//**
*
* Measure the current voltage on the VBus-Supply.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \param adcId
* ADC ID.
*
* \param input
* ADC input source.
*
* \return uint16_t
* VBus voltage in mV units.
*
*******************************************************************************/
uint16_t Cy_USBPD_Adc_MeasureVbus(cy_stc_usbpd_context_t *context, cy_en_usbpd_adc_id_t adcId,
                                  cy_en_usbpd_adc_input_t input)
{
#if PSVP_FPGA_ENABLE
#if (!defined(CY_DEVICE_CCG6DF_CFP))
    return ctrl_inf_get_vbus_c();
#else
    return false;
#endif /* (!defined(CY_DEVICE_CCG6DF_CFP)) */
#else /* PSVP_FPGA_ENABLE */
    /* Sample the VBus voltage using ADC. */
    uint8_t level;
    uint16_t retVal;

    retVal = Cy_USBPD_Adc_Calibrate(context, adcId);
    level = Cy_USBPD_Adc_Sample(context, adcId, input);
    retVal = Cy_USBPD_Adc_GetVbusVolt(context, adcId, level);

#if (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2) || defined(CY_DEVICE_PAG1S) || \
        defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
    /*
     * For low voltages, CCG3PA(2) requires higher accuracy. This can be done
     * by moving to a lower divider value of 20%. Do this only if required.
     */
    if (retVal < VBUS_DIV_20_PER_MAX_VOLT)
    {
        uint32_t state;
        PPDSS_REGS_T pd = context->base;

        state = Cy_SysLib_EnterCriticalSection();

        /* First set the AMUX to use 20% divider. */
#if defined(CY_DEVICE_PAG1S) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)
        pd->amux_ctrl |= ((uint32_t)1u << AMUX_ADC_PAG1S_VBUS_DIV_20P_EN_POS);
#else /* CCGx */
        pd->amux_nhv_ctrl |= ((uint32_t)1u << AMUX_ADC_PMG1S0_VBUS_DIV_2OP_EN_POS);
#endif /* CCGx */
        Cy_USBPD_Vbus_Mon_SetDivider(context, VBUS_MON_DIV_20P_VAL);
        Cy_SysLib_DelayUs(10u);
        /* Now measure the voltage. */
        level = Cy_USBPD_Adc_Sample(context, adcId, input);
        retVal = Cy_USBPD_Adc_GetVbusVolt(context, adcId, level);

        /* Restore the divider value. */
#if defined(CY_DEVICE_PAG1S) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)
        pd->amux_ctrl &= ~((uint32_t)1u << AMUX_ADC_PAG1S_VBUS_DIV_20P_EN_POS);
#else /* CCGx */
        pd->amux_nhv_ctrl &= ~((uint32_t)1u << AMUX_ADC_PMG1S0_VBUS_DIV_2OP_EN_POS);
#endif /* CCGx */
        Cy_USBPD_Vbus_Mon_SetDivider(context, VBUS_MON_DIV_8P_VAL);
        Cy_SysLib_DelayUs(10);

        /*
         * NOTE: Currently ADC interrupt is not enabled when running when
         * sampling the VBUS. If this changes, the code has to be extended to
         * save and restore the status to prevent falsely triggering interrupts.
         */

        Cy_SysLib_ExitCriticalSection(state);
    }
#endif /* (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2) || defined(CY_DEVICE_PAG1S) || \
            defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) */

    return retVal;
#endif /* PSVP_FPGA_ENABLE */
}

/*******************************************************************************
* Function Name: Cy_USBPD_Adc_IntrHandler
****************************************************************************//**
*
* ADC Comparator Interrupt Handler function.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
*******************************************************************************/
void Cy_USBPD_Adc_IntrHandler(cy_stc_usbpd_context_t *context)
{
    PPDSS_REGS_T pd = context->base;
    bool compOut = true;

#if (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
    if ((pd->intr3_masked & (1U << PDSS_INTR3_CMP_OUT_CHANGED_POS)) != 0U)
    {
        pd->intr3_mask &= ~(1U << PDSS_INTR3_CMP_OUT_CHANGED_POS);
        pd->intr3       =  (1U << PDSS_INTR3_CMP_OUT_CHANGED_POS);

        /* Check status. */
        compOut = true;
        if ((pd->adc_ctrl[CY_USBPD_ADC_ID_0] & PDSS_ADC_CTRL_CMP_OUT) != 0U)
        {
            compOut = false;
        }

        /* Report status. */
        if (context->adcCb[CY_USBPD_ADC_ID_0] != NULL)
        {
            context->adcCb[CY_USBPD_ADC_ID_0](context, compOut);
        }
    }

    if ((pd->intr3_masked & ((1U << PDSS_INTR3_CMP_OUT_CHANGED_POS) << CY_USBPD_ADC_ID_1)) != 0U)
    {
        pd->intr3_mask &= ~((1U << PDSS_INTR3_CMP_OUT_CHANGED_POS) << CY_USBPD_ADC_ID_1);
        pd->intr3       =  ((1U << PDSS_INTR3_CMP_OUT_CHANGED_POS) << CY_USBPD_ADC_ID_1);

        /* Check status. */
        compOut = true;
        if ((pd->adc_ctrl[CY_USBPD_ADC_ID_1] & PDSS_ADC_CTRL_CMP_OUT) != 0U)
        {
            compOut = false;
        }

        /* Report status. */
        if (context->adcCb[CY_USBPD_ADC_ID_1] != NULL)
        {
           context->adcCb[CY_USBPD_ADC_ID_1](context, compOut);
        }
    }
#elif (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_CCG6DF) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP))
    if ((pd->intr3_masked & PDSS_INTR3_CMP_OUT_CHANGED) != 0U)
    {
        pd->intr3_mask &= ~PDSS_INTR3_CMP_OUT_CHANGED;
        pd->intr3       =  PDSS_INTR3_CMP_OUT_CHANGED;

        /* Check status. */
        compOut = true;
        if ((pd->adc_ctrl & PDSS_ADC_CTRL_CMP_OUT) != 0U)
        {
            compOut = false;
        }

        /* Report status. */
        if (context->adcCb[CY_USBPD_ADC_ID_0] != NULL)
        {
            context->adcCb[CY_USBPD_ADC_ID_0](context, compOut);
        }
    }
#elif (defined(CY_DEVICE_CCG3))
    if ((pd->intr1_masked & PDSS_INTR1_CMP_OUT1_CHANGED) != 0U)
    {
        /* Disable the interrupt. */
        pd->intr1_mask &= ~PDSS_INTR1_CMP_OUT1_CHANGED;

        /* Check status. */
        compOut = true;
        if ((pd->adc1_ctrl & PDSS_ADC1_CTRL_CMP_OUT) != 0U)
        {
            compOut = false;
        }

        /* Report status. */
        if (context->adcCb[CY_USBPD_ADC_ID_0] != NULL)
        {
            context->adcCb[CY_USBPD_ADC_ID_0](context, compOut);
        }
    }

    if ((pd->intr1_masked & PDSS_INTR1_CMP_OUT2_CHANGED) != 0U)
    {
        /* Disable the interrupt. */
        pd->intr1_mask &= ~PDSS_INTR1_CMP_OUT2_CHANGED;

        /* Check status. */
        compOut = true;
        if ((pd->adc2_ctrl & PDSS_ADC2_CTRL_CMP_OUT) != 0U)
        {
            compOut = false;
        }

        /* Report status. */
        if (context->adcCb[CY_USBPD_ADC_ID_1] != NULL)
        {
            context->adcCb[CY_USBPD_ADC_ID_1](context, compOut);
        }
    }
#endif /* (defined(CY_DEVICE_CCG3)) */
}


/*******************************************************************************
* Function Name: Cy_USBPD_V5V_IsSupplyOn
****************************************************************************//**
*
* Checks whether the 5V supply to provide VConn power is present.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \return bool
* Returns true if 5V supply is present, false otherwise for CCG3/6/6DF/PMG1S3.
* Returns true by default for all the other devices.
*
*******************************************************************************/
bool Cy_USBPD_V5V_IsSupplyOn(cy_stc_usbpd_context_t *context)
{
    bool stat = false;

#if (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_CCG6DF) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP))
    PPDSS_REGS_T pd = context->base;

    /* If V5V is not present, return error. */
    if ((pd->intr1_status & PDSS_INTR1_STATUS_V5V_STATUS) != 0U)
    {
        stat = true;
    }

#elif defined(CY_DEVICE_CCG3)
    PPDSS_REGS_T pd = context->base;

    /* If V5V is not present, return error. */
    if ((pd->status & PDSS_STATUS_V5V_STATUS) != 0U)
    {
        stat = true;
    }
#else
    stat = true;
    CY_UNUSED_PARAMETER(context);
#endif /* defined(CY_DEVICE_CCG3) */

    return stat;
}


/*******************************************************************************
* Function Name: Cy_USBPD_Vconn_Enable
****************************************************************************//**
*
* Turns on Vconn for the specified channel.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \param channel
* Channel index, where CC1 = 0, CC2 = 1.
*
* \return
* \ref cy_en_usbpd_status_t
*
*******************************************************************************/
cy_en_usbpd_status_t Cy_USBPD_Vconn_Enable(cy_stc_usbpd_context_t *context, uint8_t channel)
{
#if defined(CY_DEVICE_CCG3PA)
    /* No VConn support in PMG1S0. */
    CY_UNUSED_PARAMETER(context);
    CY_UNUSED_PARAMETER(channel);
#endif /* defined(CY_DEVICE_CCG3PA) */

#if (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_CCG6DF) || defined(CY_DEVICE_PMG1S3)  || defined(CY_DEVICE_CCG6DF_CFP) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
    PPDSS_REGS_T pd = context->base;
    uint32_t regVal;

#if PMG1_V5V_CHANGE_DETECT
    /* If V5V is not present, return error. */
    if ((pd->intr1_status & PDSS_INTR1_STATUS_V5V_STATUS) == 0U)
    {
        return CY_USBPD_STAT_FAILURE;
    }
#endif /* PMG1_V5V_CHANGE_DETECT */

    /* Check whether VConn has already been turned ON. */
    if (Cy_USBPD_Vconn_IsPresent(context, channel))
    {
        return CY_USBPD_STAT_SUCCESS;
    }
   
#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
    PPDSS_TRIMS_REGS_T trimRegs = context->trimsBase;
     /*
     * CDT 360166:
     * Enable VCONN SCP in HW cut off and retry mode initially
     * until VCONN switch is ON. This is to cut off sudden load on VCONN that 
     * can cause Regulator Inrush fault.
     * This protection is enabled by default to address faulty active cables.
     */
    pd->vconn20_ctrl |= ((uint32_t)1u << (7u + PDSS_VCONN20_CTRL_T_VCONN_POS));

    if (channel == CY_PD_CC_CHANNEL_1)
    {
        /* Revert OCP trim offset */
        CY_USBPD_REG_FIELD_UPDATE(trimRegs->trim_bb_20vconn_2, 
            PDSS_TRIM_BB_20VCONN_2_BB_20VCONN_OCP_TRIM, 
            VCONN_OCP_TRIM(context->port));

        /* Enable SC detection on CC1/2 pins. */
        pd->vconn20_ctrl &= ~PDSS_VCONN20_CTRL_EN_OCP_CC2;
        pd->vconn20_ctrl |= PDSS_VCONN20_CTRL_EN_OCP_CC1;
    }
    else
    {
        /* Set OCP trim offset for CC2 line only */
        CY_USBPD_REG_FIELD_UPDATE(trimRegs->trim_bb_20vconn_2, 
            PDSS_TRIM_BB_20VCONN_2_BB_20VCONN_OCP_TRIM, 
            (uint32_t)VCONN_OCP_TRIM(context->port) + (uint32_t)VCONN_OCP_TRIM_CC2_OFFSET);

        /* Enable SC detection on CC1/2 pins. */
        pd->vconn20_ctrl &= ~PDSS_VCONN20_CTRL_EN_OCP_CC1;
        pd->vconn20_ctrl |= PDSS_VCONN20_CTRL_EN_OCP_CC2;
    }

#endif /* (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) */
#if defined(CY_DEVICE_CCG6DF_CFP)
    /* Enable all the outputs. */
    pd->pd_30vconn_ctrl |= PDSS_PD_30VCONN_CTRL_ISO_N;
    /* Turn on the VConn switch. */
    if (channel == CY_PD_CC_CHANNEL_1)
    {
        regVal = pd->switch_ctrl_03;
        regVal |= PDSS_SWITCH_CTRL_03_SEL_ON_OFF |
            PDSS_SWITCH_CTRL_03_EN_SWITCH_ON_VALUE;
        pd->switch_ctrl_03 = regVal;

        /* Reset edge detector. */
        pd->switch_ctrl_03 |= PDSS_SWITCH_CTRL_03_RST_EDGE_DET;
        pd->switch_ctrl_03 &= ~PDSS_SWITCH_CTRL_03_RST_EDGE_DET;

        /* Enable VCONN.*/
        pd->pd_30vconn_ctrl &= ~PDSS_PD_30VCONN_CTRL_EN_CC2_SW;
        pd->pd_30vconn_ctrl |= PDSS_PD_30VCONN_CTRL_EN_CC1_SW;
    }
    else
    {
        regVal = pd->switch_ctrl_04;
        regVal |= PDSS_SWITCH_CTRL_04_SEL_ON_OFF |
            PDSS_SWITCH_CTRL_04_EN_SWITCH_ON_VALUE;
        pd->switch_ctrl_04 = regVal;

        /* Reset edge detector. */
        pd->switch_ctrl_04 |= PDSS_SWITCH_CTRL_04_RST_EDGE_DET;
        pd->switch_ctrl_04 &= ~PDSS_SWITCH_CTRL_04_RST_EDGE_DET;

        /* Enable VCONN.*/
        pd->pd_30vconn_ctrl &= ~PDSS_PD_30VCONN_CTRL_EN_CC1_SW;
        pd->pd_30vconn_ctrl |= PDSS_PD_30VCONN_CTRL_EN_CC2_SW;
    }

    /* Turn on the VConn pump. */
    regVal = pd->switch_ctrl_05;
    regVal |= PDSS_SWITCH_CTRL_05_SEL_ON_OFF | PDSS_SWITCH_CTRL_05_EN_SWITCH_ON_VALUE;
    pd->switch_ctrl_05 = regVal;
    pd->pd_30vconn_ctrl |= PDSS_PD_30VCONN_CTRL_EN_PUMP;
#else
    /* Turn on the VConn switch. */
    if (channel == CY_PD_CC_CHANNEL_1)
    {
        regVal = pd->vconn20_cc1_switch_1_ctrl;
        regVal |= PDSS_VCONN20_CC1_SWITCH_1_CTRL_SEL_ON_OFF |
            PDSS_VCONN20_CC1_SWITCH_1_CTRL_EN_SWITCH_CC1_ON_VALUE |
            PDSS_VCONN20_CC1_SWITCH_1_CTRL_SEL_CC1_OVP |
            PDSS_VCONN20_CC1_SWITCH_1_CTRL_SEL_CC2_OVP;
        pd->vconn20_cc1_switch_1_ctrl = regVal;

        /* Reset edge detector. */
        pd->vconn20_cc1_switch_1_ctrl |= PDSS_VCONN20_CC1_SWITCH_1_CTRL_RST_EDGE_DET;
        pd->vconn20_cc1_switch_1_ctrl &= ~PDSS_VCONN20_CC1_SWITCH_1_CTRL_RST_EDGE_DET;
    }
    else
    {
        regVal = pd->vconn20_cc2_switch_1_ctrl;
        regVal |= PDSS_VCONN20_CC2_SWITCH_1_CTRL_SEL_ON_OFF |
            PDSS_VCONN20_CC2_SWITCH_1_CTRL_EN_SWITCH_CC2_ON_VALUE |
            PDSS_VCONN20_CC2_SWITCH_1_CTRL_SEL_CC1_OVP |
            PDSS_VCONN20_CC2_SWITCH_1_CTRL_SEL_CC2_OVP;
        pd->vconn20_cc2_switch_1_ctrl = regVal;

        /* Reset edge detector. */
        pd->vconn20_cc2_switch_1_ctrl |= PDSS_VCONN20_CC2_SWITCH_1_CTRL_RST_EDGE_DET;
        pd->vconn20_cc2_switch_1_ctrl &= ~PDSS_VCONN20_CC2_SWITCH_1_CTRL_RST_EDGE_DET;
    }

    /* Turn on the VConn pump. */
    regVal = pd->vconn20_pump_en_1_ctrl;
    regVal |= PDSS_VCONN20_PUMP_EN_1_CTRL_SEL_ON_OFF | PDSS_VCONN20_PUMP_EN_1_CTRL_EN_VCONN20_PUMP_ON_VALUE |
        PDSS_VCONN20_PUMP_EN_1_CTRL_SEL_CC1_OVP | PDSS_VCONN20_PUMP_EN_1_CTRL_SEL_CC2_OVP;
    pd->vconn20_pump_en_1_ctrl = regVal;
#endif /* defined(CY_DEVICE_CCG6DF_CFP) */
#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
     /* 
     * Turn ON & enable the slow charging of 20vconn switch 
     * for inrush current control.
     */
    Cy_SysLib_DelayUs(100);

    /* Turn on VCONN slow switch */
    pd->vconn20_ctrl |= ((uint32_t)1u << (PDSS_VCONN20_CTRL_T_VCONN_SLOW_TURN_ON_POS +
        PDSS_VCONN20_CTRL_T_VCONN_POS));

    /* Start firmware VCONN OCP and SCP handling after VCONN switch output is stable */   
#endif /* (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) */

    return CY_USBPD_STAT_SUCCESS;

#elif defined(CY_DEVICE_CCG3)
    PPDSS_REGS_T pd = context->base;

    if (channel == CY_PD_CC_CHANNEL_1)
    {
        pd->pfet300_ctrl |= PDSS_PFET300_CTRL_EN_SWITCH_CC1;
    }
    else
    {
        pd->pfet300_ctrl |= PDSS_PFET300_CTRL_EN_SWITCH_CC2;
    }

    return CY_USBPD_STAT_SUCCESS;
#else
    /* No VConn support in PMG1S0. */
    CY_UNUSED_PARAMETER(context);
    CY_UNUSED_PARAMETER(channel);

    return CY_USBPD_STAT_NOT_SUPPORTED;
#endif /* defined(CY_DEVICE_CCG3) */
}


/*******************************************************************************
* Function Name: Cy_USBPD_Vconn_Disable
****************************************************************************//**
*
* Turns Off Vconn for the specified channel.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \param channel
* Channel index, where CC1 = 0, CC2 = 1.
*
* \return
* \ref cy_en_usbpd_status_t
*
*******************************************************************************/
cy_en_usbpd_status_t Cy_USBPD_Vconn_Disable(cy_stc_usbpd_context_t *context, uint8_t channel)
{
#if (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_CCG6DF) || defined(CY_DEVICE_PMG1S3)  || defined(CY_DEVICE_CCG6DF_CFP) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))

    PPDSS_REGS_T pd = context->base;
    uint32_t regVal;

    /* Check whether VConn has already been turned OFF. */
    if (!Cy_USBPD_Vconn_IsPresent(context, channel))
    {
        return CY_USBPD_STAT_SUCCESS;
    }

    /* PMG1S3 */
#if defined(CY_DEVICE_PMG1S3)
    /* Gate pull up needs to be disabled. */
    pd->vconn20_ctrl &= ~(0x01UL << (0x05UL + PDSS_VCONN20_CTRL_T_VCONN_POS));
#elif (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
    /* Turn off VCONN slow switch*/
    pd->vconn20_ctrl &= ~((uint32_t)1u << (PDSS_VCONN20_CTRL_T_VCONN_SLOW_TURN_ON_POS + PDSS_VCONN20_CTRL_T_VCONN_POS));
#endif /* defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP) */

#if defined(CY_DEVICE_CCG6DF_CFP)
    /* Turn off the VConn pump. */
    regVal = pd->switch_ctrl_05;
    regVal &= ~(PDSS_SWITCH_CTRL_05_SEL_ON_OFF | PDSS_SWITCH_CTRL_05_EN_SWITCH_ON_VALUE);
    pd->switch_ctrl_05 = regVal;
    pd->pd_30vconn_ctrl &= ~(PDSS_PD_30VCONN_CTRL_EN_PUMP);

    /* Adding a small delay. */
    Cy_SysLib_DelayUs (10);

    pd->pd_30vconn_ctrl &= ~PDSS_PD_30VCONN_CTRL_EN_CC1_SW;
    pd->pd_30vconn_ctrl &= ~PDSS_PD_30VCONN_CTRL_EN_CC2_SW;
    /* Turn off the VConn switch. */
    if (channel == CY_PD_CC_CHANNEL_1)
    {
        regVal = pd->switch_ctrl_03;
        regVal &= ~(PDSS_SWITCH_CTRL_03_SEL_ON_OFF | PDSS_SWITCH_CTRL_03_EN_SWITCH_ON_VALUE);
        pd->switch_ctrl_03 = regVal;

        /* Reset edge detector. */
        pd->switch_ctrl_03 |= PDSS_SWITCH_CTRL_03_RST_EDGE_DET;
        pd->switch_ctrl_03 &= ~PDSS_SWITCH_CTRL_03_RST_EDGE_DET;
    }
    else
    {
        regVal = pd->switch_ctrl_04;
        regVal &= ~(PDSS_SWITCH_CTRL_04_SEL_ON_OFF | PDSS_SWITCH_CTRL_04_EN_SWITCH_ON_VALUE);
        pd->switch_ctrl_04 = regVal;

        /* Reset edge detector. */
        pd->switch_ctrl_04 |= PDSS_SWITCH_CTRL_04_RST_EDGE_DET;
        pd->switch_ctrl_04 &= ~PDSS_SWITCH_CTRL_04_RST_EDGE_DET;
    }

    /* Disable all the outputs only if CC1 and CC2 OVP is disabled */
    if( (pd->pd_30vconn_ctrl & (PDSS_PD_30VCONN_CTRL_EN_OVP_CC1 | PDSS_PD_30VCONN_CTRL_EN_OVP_CC2)) == 0U)
    {
        pd->pd_30vconn_ctrl &= ~(PDSS_PD_30VCONN_CTRL_ISO_N);
    }
#else
    /* Turn off the VConn pump. */
    regVal = pd->vconn20_pump_en_1_ctrl;
    regVal &= ~(PDSS_VCONN20_PUMP_EN_1_CTRL_SEL_ON_OFF | PDSS_VCONN20_PUMP_EN_1_CTRL_EN_VCONN20_PUMP_ON_VALUE |
            PDSS_VCONN20_PUMP_EN_1_CTRL_SEL_CC1_OVP | PDSS_VCONN20_PUMP_EN_1_CTRL_SEL_CC2_OVP);
    pd->vconn20_pump_en_1_ctrl = regVal;

    /* Adding a small delay. */
    Cy_SysLib_DelayUs (10);

    /* Turn off the VConn switch. */
    if (channel == CY_PD_CC_CHANNEL_1)
    {
        regVal = pd->vconn20_cc1_switch_1_ctrl;
        regVal &= ~(PDSS_VCONN20_CC1_SWITCH_1_CTRL_SEL_ON_OFF | PDSS_VCONN20_CC1_SWITCH_1_CTRL_EN_SWITCH_CC1_ON_VALUE |
                PDSS_VCONN20_CC1_SWITCH_1_CTRL_SEL_CC1_OVP);
        pd->vconn20_cc1_switch_1_ctrl = regVal;

        /* Reset edge detector. */
        pd->vconn20_cc1_switch_1_ctrl |= PDSS_VCONN20_CC1_SWITCH_1_CTRL_RST_EDGE_DET;
        pd->vconn20_cc1_switch_1_ctrl &= ~PDSS_VCONN20_CC1_SWITCH_1_CTRL_RST_EDGE_DET;
    }
    else
    {
        regVal = pd->vconn20_cc2_switch_1_ctrl;
        regVal &= ~(PDSS_VCONN20_CC2_SWITCH_1_CTRL_SEL_ON_OFF | PDSS_VCONN20_CC2_SWITCH_1_CTRL_EN_SWITCH_CC2_ON_VALUE |
                PDSS_VCONN20_CC2_SWITCH_1_CTRL_SEL_CC2_OVP);
        pd->vconn20_cc2_switch_1_ctrl = regVal;

        /* Reset edge detector. */
        pd->vconn20_cc2_switch_1_ctrl |= PDSS_VCONN20_CC2_SWITCH_1_CTRL_RST_EDGE_DET;
        pd->vconn20_cc2_switch_1_ctrl &= ~PDSS_VCONN20_CC2_SWITCH_1_CTRL_RST_EDGE_DET;
    }
#endif /* defined(CY_DEVICE_CCG6DF_CFP) */
    return CY_USBPD_STAT_SUCCESS;

#elif defined(CY_DEVICE_CCG3)
    PPDSS_REGS_T pd = context->base;

    if (channel == CY_PD_CC_CHANNEL_1)
    {
        pd->pfet300_ctrl &= ~PDSS_PFET300_CTRL_EN_SWITCH_CC1;
    }
    else
    {
        pd->pfet300_ctrl &= ~PDSS_PFET300_CTRL_EN_SWITCH_CC2;
    }

    return CY_USBPD_STAT_SUCCESS;
#else
    /* No VConn support in PMG1S0. */
    CY_UNUSED_PARAMETER(context);
    CY_UNUSED_PARAMETER(channel);

    return CY_USBPD_STAT_NOT_SUPPORTED;
#endif /* defined(CY_DEVICE_CCG3) */
}


/*******************************************************************************
* Function Name: Cy_USBPD_Vconn_GatePullUp_Enable
****************************************************************************//**
*
* Enable the gate pull up to limit the inrush current. This function needs to
* be called after at least 500 us of \ref Cy_USBPD_Vconn_Enable
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \return
* None
*
*******************************************************************************/
void Cy_USBPD_Vconn_GatePullUp_Enable(cy_stc_usbpd_context_t *context)
{
#if defined(CY_DEVICE_PMG1S3)
    PPDSS_REGS_T pd = context->base;
    /* Gate pull up needs to be enabled after 500 us of VConn Switch Enable to
     * limit inrush current. */

    pd->vconn20_ctrl |= (0x01UL << (0x05UL + PDSS_VCONN20_CTRL_T_VCONN_POS));
#elif defined(CY_DEVICE_CCG6DF_CFP)
    PPDSS_REGS_T pd = context->base;
    /* Gate pull up(dis_ocp_blanking_lv) needs to be enabled after 500 us of VConn Switch Enable to
     * limit inrush current. */

    pd->pd_30vconn_ctrl |= PDSS_PD_30VCONN_CTRL_DIS_OCP_BLANKING;
#else
    (void)context;
#endif /* defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP) */
}


/*******************************************************************************
* Function Name: Cy_USBPD_Vconn_IsPresent
****************************************************************************//**
*
* This function checks the status of the VConn.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \param channel
* Channel index, where CC1 = 0, CC2 = 1.
*
* \return bool
* Returns true if Vconn is turned on, false otherwise.
*
*******************************************************************************/
bool Cy_USBPD_Vconn_IsPresent(cy_stc_usbpd_context_t *context, uint8_t channel)
{
    bool retVal = false;

#if defined(CY_DEVICE_CCG3PA)
    /* No internal VConn support on PMG1S0. */
    CY_UNUSED_PARAMETER(context);
    CY_UNUSED_PARAMETER(channel);
#endif /* defined(CY_DEVICE_CCG3PA) */

#if (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
    PPDSS_REGS_T pd = context->base;

    /* Check whether the V5V -> VConn Switch is ON. */
    if (channel == CY_PD_CC_CHANNEL_1)
    {
        retVal = ((pd->vconn20_cc1_switch_1_ctrl & PDSS_VCONN20_CC1_SWITCH_1_CTRL_SEL_ON_OFF) != 0U);
    }
    else
    {
        retVal = ((pd->vconn20_cc2_switch_1_ctrl & PDSS_VCONN20_CC2_SWITCH_1_CTRL_SEL_ON_OFF) != 0U);
    }
#endif /* (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_CCG6DF) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) */
#if defined(CY_DEVICE_CCG6DF_CFP)
    PPDSS_REGS_T pd = context->base;

    /* Check whether the V5V -> VConn Switch is ON. */
    if (channel == CY_PD_CC_CHANNEL_1)
    {
        retVal = ((pd->switch_ctrl_03 & PDSS_SWITCH_CTRL_03_SEL_ON_OFF) != 0U);
    }
    else
    {
        retVal = ((pd->switch_ctrl_04 & PDSS_SWITCH_CTRL_04_SEL_ON_OFF) != 0U);
    }
#endif /* defined(CY_DEVICE_CCG6DF_CFP) */

#if defined(CY_DEVICE_CCG3)
    PPDSS_REGS_T pd = context->base;

    if (channel == CY_PD_CC_CHANNEL_1)
    {
        retVal = ((pd->pfet300_ctrl & PDSS_PFET300_CTRL_EN_SWITCH_CC1) != 0U);
    }
    else
    {
        retVal = ((pd->pfet300_ctrl & PDSS_PFET300_CTRL_EN_SWITCH_CC2) != 0U);
    }
#endif /* defined(CY_DEVICE_CCG3) */

    return retVal;
}

/*******************************************************************************
* Function Name: Cy_USBPD_VbusDiv_To_AMuxDiscon
****************************************************************************//**
*
* Disconnect the internal VBus divider from AMUX bus.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \return bool
* Return true if disconnected, false if disconnection not allowed.
*
*******************************************************************************/
bool Cy_USBPD_VbusDiv_To_AMuxDiscon(cy_stc_usbpd_context_t *context)
{
    CY_UNUSED_PARAMETER(context);

    return false;
}

/* The FRS comparator threshold should be set to 0.52V = 2. */
#define CMP_FS_VSEL_VALUE       (2)

/*
 * Swap CTRL default settings for FRS receive. This settings are based on 5Mhz clock
 * to the block.
 */
#define FRS_RX_SWAP_CTRL1_DFLT_VAL      ((175u << PDSS_SWAP_CTRL1_PULSE_MIN_POS)| \
                                         (650u << PDSS_SWAP_CTRL1_PULSE_MAX_POS)|\
                                         (PDSS_SWAP_CTRL1_RESET_SWAP_STATE))

#define FRS_RX_SWAP_CTRL2_DFLT_VAL      ((50u << PDSS_SWAP_CTRL2_GLITCH_WIDTH_LOW_POS) | \
                                         (1u << PDSS_SWAP_CTRL2_GLITCH_WIDTH_HIGH_POS))

#define FRS_RX_SWAP_CTRL3_DFLT_VAL      (120u << PDSS_SWAP_CTRL3_STABLE_LOW_POS)

#define FRS_RX_SWAP_CTRL5_DFLT_VAL      (750u << PDSS_SWAP_CTRL5_LONG_LOW_POS)

/*******************************************************************************
* Function Name: Cy_USBPD_Vbus_FrsRxEnable
****************************************************************************//**
*
* Enables the fast role swap receive functionality. Callback
* registered in Cy_USBPD_Phy_Init will be called when FRS signal is received.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \return bool
* Returns true if success, otherwise returns false.
*
*******************************************************************************/
bool Cy_USBPD_Vbus_FrsRxEnable(cy_stc_usbpd_context_t *context)
{
#if (CY_PD_REV3_ENABLE && CY_PD_FRS_RX_ENABLE)
    cy_stc_pd_dpm_config_t* dpmConfig = context->dpmGetConfig();
    PPDSS_REGS_T pd = context->base;
    uint32_t regVal;

    /* Set the VBus detach comparator threshold to Vsafe5V */
    uint8_t level = Cy_USBPD_Adc_GetVbusLevel (context, context->vbusDetachAdcId,
            CY_PD_VSAFE_5V, CY_PD_VSAFE_5V_FRS_SWAP_RX_MARGIN);

    /* Enable VSAFE5V comparator */
    Cy_USBPD_Adc_FreeRunCtrl(context, context->vbusDetachAdcId, context->vbusDetachAdcInp, level);

    /* Configure CC line voltage thresholds to detect frs signal */
    regVal  = (pd->cc_ctrl_1 & ~(PDSS_CC_CTRL_1_CMP_FS_VSEL_MASK | PDSS_CC_CTRL_1_CMP_FS_CC1V2));
    regVal |= (CMP_FS_VSEL_VALUE << PDSS_CC_CTRL_1_CMP_FS_VSEL_POS);

    /* See if cc polarity need update */
    if(dpmConfig->polarity == CY_PD_CC_CHANNEL_2)
    {
        regVal |= PDSS_CC_CTRL_1_CMP_FS_CC1V2;
    }
    pd->cc_ctrl_1 = regVal;

    /*
     * Set the vsafe5v comp signal source:
     * Using VBUS_MON. Also clear Rx Swap Done status.
     */
    pd->swap_ctrl0 = (context->vbusDetachAdcId << PDSS_SWAP_CTRL0_SWAPR_SOURCE_SEL_POS) |
        (1U << PDSS_SWAP_CTRL0_RX_SWAP_SOURCE_POS) |
        PDSS_SWAP_CTRL0_CLR_RX_SWAP_DONE;

    /* Now configure the Swap controller */
    pd->swap_ctrl1 = FRS_RX_SWAP_CTRL1_DFLT_VAL;
    pd->swap_ctrl2 = FRS_RX_SWAP_CTRL2_DFLT_VAL;
    pd->swap_ctrl3 = FRS_RX_SWAP_CTRL3_DFLT_VAL;
    pd->swap_ctrl5 = FRS_RX_SWAP_CTRL5_DFLT_VAL;

    /* Let thresholds settle */
    Cy_SysLib_DelayUs(10);

    /* Take swap controller out of reset */
    pd->swap_ctrl1 &= ~PDSS_SWAP_CTRL1_RESET_SWAP_STATE;

    /* Enabling the FR pulse and disconnect interrupts. FET switching will only happen on pulse. */
    pd->intr2 = PDSS_INTR2_SWAP_RCVD | PDSS_INTR2_SWAP_DISCONNECT;
    pd->intr2_mask |= PDSS_INTR2_SWAP_RCVD | PDSS_INTR2_SWAP_DISCONNECT;

#if defined(CY_DEVICE_CCG6DF_CFP)
    pd->intr20 = PDSS_INTR20_VSWAP_VBUS_LESS_5_DONE;
#else
    pd->intr1 = PDSS_INTR1_VSWAP_VBUS_LESS_5_DONE;
#endif /* defined(CY_DEVICE_CCG6DF_CFP) */

    /* Enable the swap controller */
    pd->swap_ctrl0 &= ~PDSS_SWAP_CTRL0_CLR_RX_SWAP_DONE;
    pd->swap_ctrl0 |= PDSS_SWAP_CTRL0_SWAP_ENABLED;

#if defined(CY_DEVICE_CCG6)

    /* Ensure that the FET switching happens based on SWAP IRQ and VBUS Detect. */
    pd->debug_cc_0 |= PDSS_DEBUG_CC_0_VBUS_C_SWAP_SOURCE_SEL | PDSS_DEBUG_CC_0_VBUS_P_SWAP_SOURCE_SEL;

    /* Set the sink fet OFF settings as per current HW, and enable LF filter 0 for auto FET switching. */
    regVal = pd->pgdo_1_cfg;
    regVal |= ((1U << PDSS_PGDO_1_CFG_SEL_SWAP_VBUS_LESS_5_POS) | PDSS_PGDO_1_CFG_AUTO_MODE);
    pd->pgdo_1_cfg  = regVal;

    /* Ensure that source FET is off to start with, and then configure it for turn ON on FR trigger. */
    Cy_USBPD_Vbus_GdrvPfetOff (context, false);

    /* PGDO_PU_1_CFG register is used for Provider FET */
    regVal = pd->pgdo_pu_1_cfg;
    regVal |= (PDSS_PGDO_PU_1_CFG_PGDO_PU_EN_LV_ON_VALUE |
            (1U << PDSS_PGDO_PU_1_CFG_SEL_SWAP_VBUS_LESS_5_POS) |
            PDSS_PGDO_PU_1_CFG_AUTO_MODE);
    pd->pgdo_pu_1_cfg = regVal;

    /* We can use the ISINK control of the gate driver to slowly enable the provider path instead of
     * doing an instantaneous turn-on. Programming 0x120 value to the ID SINK counter in bypass mode. */

    /* First clear the current ISINK counter value. */
    pd->pgdo_pd_isnk_cfg &= ~(PDSS_PGDO_PD_ISNK_CFG_VALUE_MASK | PDSS_PGDO_PD_ISNK_CFG_VALUE_1_MASK |
            PDSS_PGDO_PD_ISNK_CFG_STRONG_EN);
    Cy_SysLib_DelayUs (50);
    pd->pgdo_pd_isnk_cfg |= PDSS_PGDO_PD_ISNK_CFG_LOAD_INIT_VALUE;
    Cy_SysLib_DelayUs (100);
    while ((pd->pgdo_pd_isnk_cfg & PDSS_PGDO_PD_ISNK_CFG_LOAD_INIT_VALUE) != 0);

    pd->pgdo_pd_isnk_cfg &= ~PDSS_PGDO_PD_ISNK_CFG_STRONG_EN;
    pd->pgdo_pd_isnk_cfg |= (0x20 << PDSS_PGDO_PD_ISNK_CFG_VALUE_POS) |
        (0x04U << PDSS_PGDO_PD_ISNK_CFG_VALUE_1_POS) |
        PDSS_PGDO_PD_ISNK_CFG_BYPASS_PD_ISNK;

#elif defined(CY_DEVICE_CCG6DF_CFP)

    /* Ensure that the FET switching happens based on SWAP IRQ and VBUS Detect. */
    pd->debug_cc_0 |= PDSS_DEBUG_CC_0_VBUS_C_SWAP_SOURCE_SEL | PDSS_DEBUG_CC_0_VBUS_P_SWAP_SOURCE_SEL;

    /* Set all FRS sequence counter delays to minimum and enable the counter. */
    pd->frs_seq_cntr = (
            (1 << PDSS_FRS_SEQ_CNTR_NGDO_CP_EN_ON_VALUE_POS) |
            (1 << PDSS_FRS_SEQ_CNTR_NGDO_KEEP_OFF_DISABLE_ON_VALUE_POS) |
            (1 << PDSS_FRS_SEQ_CNTR_NGDO_GDRV_EN_ON_VALUE_POS) |
            (1 << PDSS_FRS_SEQ_CNTR_FRS_SW_EN_ON_VALUE_POS) |
            (1 << PDSS_FRS_SEQ_CNTR_FRS_CP_EN_ON_VALUE_POS)
            );
    pd->frs_seq_cntr |= PDSS_FRS_SEQ_CNTR_EN_FRS_SEQ;

    /* Set all NGDO signals to turn-on based on SWAP_VBUS_LESS_5 condition. */
    /* NGDO_EN --> AUTO_MODE=1, EN_SWITCH_OFF_VALUE=1, EN_SWITH_ON_VALUE=0, SEL_ON_OFF=1, VBUS-C<5V fault Enable.*/
    pd->switch_ctrl_07 = (PDSS_SWITCH_CTRL_07_AUTO_MODE | PDSS_SWITCH_CTRL_07_EN_SWITCH_OFF_VALUE |
            PDSS_SWITCH_CTRL_07_SEL_ON_OFF | (0x01u << PDSS_SWITCH_CTRL_07_SEL_FAULT_EN_POS));
    /* CP_EN --> AUTO_MODE=1, EN_SWITCH_OFF_VALUE=1, EN_SWITH_ON_VALUE=0, SEL_ON_OFF=1, VBUS-C<5V fault Enable.*/
    pd->switch_ctrl_08 = (PDSS_SWITCH_CTRL_08_AUTO_MODE | PDSS_SWITCH_CTRL_08_EN_SWITCH_OFF_VALUE |
            PDSS_SWITCH_CTRL_08_SEL_ON_OFF | (0x01u << PDSS_SWITCH_CTRL_08_SEL_FAULT_EN_POS));
    /* KEEP_OFF_DISABLE --> AUTO_MODE=1, EN_SWITCH_OFF_VALUE=1, EN_SWITH_ON_VALUE=0, SEL_ON_OFF=1, VBUS-C<5V fault Enable.*/
    pd->switch_ctrl_09 = (PDSS_SWITCH_CTRL_09_AUTO_MODE | PDSS_SWITCH_CTRL_09_EN_SWITCH_OFF_VALUE |
            PDSS_SWITCH_CTRL_09_SEL_ON_OFF | (0x01u << PDSS_SWITCH_CTRL_09_SEL_FAULT_EN_POS));
    /* GDRV_EN --> AUTO_MODE=1, EN_SWITCH_OFF_VALUE=1, EN_SWITH_ON_VALUE=0, SEL_ON_OFF=1, VBUS-C<5V fault Enable.*/
    pd->switch_ctrl_06 = (PDSS_SWITCH_CTRL_06_AUTO_MODE | PDSS_SWITCH_CTRL_06_EN_SWITCH_OFF_VALUE |
            PDSS_SWITCH_CTRL_06_SEL_ON_OFF | (0x01u << PDSS_SWITCH_CTRL_06_SEL_FAULT_EN_POS));

    /* Remove the GATE2 pull-down so that the source FET can turn ON in auto-mode */
    regVal = pd->ngdo_p5c40_ctrl_0;
    regVal &= ~PDSS_NGDO_P5C40_CTRL_0_SLEW_CTRL_MASK;
    regVal |= (0x0Eu << PDSS_NGDO_P5C40_CTRL_0_SLEW_CTRL_POS);
    pd->ngdo_p5c40_ctrl_0 = regVal;
    pd->ngdo_p5c40_ctrl_1 &= ~(PDSS_NGDO_P5C40_CTRL_1_G2_DISABLE);

    /* Configure the Provider side FRS FET for turn ON on FR */
    pd->frs_ctrl |= PDSS_FRS_CTRL_FRS_BIAS_EN | PDSS_FRS_CTRL_FRS_ISO_N | (1 << PDSS_FRS_CTRL_FRS_CLOCK_SOURCE_POS);
    /* FRS_SW_EN --> AUTO_MODE=1, EN_SWITCH_OFF_VALUE=1, EN_SWITH_ON_VALUE=0, SEL_ON_OFF=1, VBUS-C<5V fault Enable.*/
    pd->switch_ctrl_11 = (PDSS_SWITCH_CTRL_11_AUTO_MODE | PDSS_SWITCH_CTRL_11_EN_SWITCH_OFF_VALUE |
            PDSS_SWITCH_CTRL_11_SEL_ON_OFF | (0x01u << PDSS_SWITCH_CTRL_11_SEL_FAULT_EN_POS));
    /* FRS_CP_EN --> AUTO_MODE=1, EN_SWITCH_OFF_VALUE=1, EN_SWITH_ON_VALUE=0, SEL_ON_OFF=1, VBUS-C<5V fault Enable.*/
    pd->switch_ctrl_10 = (PDSS_SWITCH_CTRL_10_AUTO_MODE | PDSS_SWITCH_CTRL_10_EN_SWITCH_OFF_VALUE |
            PDSS_SWITCH_CTRL_10_SEL_ON_OFF | (0x01u << PDSS_SWITCH_CTRL_10_SEL_FAULT_EN_POS));

#endif /* CY_DEVICE */
    return true;
#else
    CY_UNUSED_PARAMETER(context);
    return false;
#endif /* (CY_PD_REV3_ENABLE && CY_PD_FRS_RX_ENABLE) */
}


/*******************************************************************************
* Function Name: Cy_USBPD_Vbus_FrsRxDisable
****************************************************************************//**
*
* Disables the fast role swap receive functionality.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \return bool
* Returns true if success, otherwise returns false.
*
*******************************************************************************/
bool Cy_USBPD_Vbus_FrsRxDisable(cy_stc_usbpd_context_t *context)
{
#if (CY_PD_REV3_ENABLE && CY_PD_FRS_RX_ENABLE)
    PPDSS_REGS_T pd = context->base;

    Cy_USBPD_Adc_CompCtrl (context, context->vbusDetachAdcId, CY_USBPD_ADC_INPUT_AMUX_A, 0, CY_USBPD_ADC_INT_DISABLED, NULL);

    /* Disable the swap controller */
    pd->swap_ctrl1 |= PDSS_SWAP_CTRL1_RESET_SWAP_STATE;
    pd->swap_ctrl0 &= ~PDSS_SWAP_CTRL0_SWAP_ENABLED;

    /* Disable and clear frs receive interrupts */
#if defined(CY_DEVICE_CCG6DF_CFP)
    pd->intr20_mask &= ~(PDSS_INTR20_VSWAP_VBUS_LESS_5_DONE);
    pd->intr20 = (PDSS_INTR20_VSWAP_VBUS_LESS_5_DONE);
#else
    pd->intr1_mask &= ~(PDSS_INTR1_VSWAP_VBUS_LESS_5_DONE);
    pd->intr1 = (PDSS_INTR1_VSWAP_VBUS_LESS_5_DONE);
#endif /* defined(CY_DEVICE_CCG6DF_CFP) */

    pd->intr2_mask &= ~(PDSS_INTR2_SWAP_RCVD | PDSS_INTR2_SWAP_DISCONNECT);
    pd->intr2 = (PDSS_INTR2_SWAP_RCVD | PDSS_INTR2_SWAP_DISCONNECT);

#if defined(CY_DEVICE_CCG6)
    /* Clear the switch on SWAP bits in the gate driver registers. */
    pd->pgdo_1_cfg &= ~PDSS_PGDO_1_CFG_SEL_SWAP_VBUS_LESS_5_MASK;
    pd->pgdo_2_cfg &= ~(1U << PDSS_PGDO_2_CFG_LS_SOURCE_SEL_POS);

    /* Use PGDO_PU_1_CFG register for Provider FET */
    pd->pgdo_pu_1_cfg &= ~PDSS_PGDO_PU_1_CFG_SEL_SWAP_VBUS_LESS_5_MASK;
    pd->pgdo_pu_2_cfg &= ~(1U << PDSS_PGDO_PU_2_CFG_LS_SOURCE_SEL_POS);

    /* Make sure auto-mode is turned off on both the provider and consumer gate drivers. */
    if (((pd->pgdo_pu_1_cfg & PGDO_PU_1_CFG_AUTO_SEL_MASK) == 0) && (pd->pgdo_pu_2_cfg == 0))
    {
        Cy_USBPD_Vbus_GdrvRstEdgeDet(context, true);
        pd->pgdo_pu_1_cfg &= ~(PDSS_PGDO_PU_1_CFG_AUTO_MODE);
    }

    if (((pd->pgdo_1_cfg & PGDO_1_CFG_AUTO_SEL_MASK) == 0) && (pd->pgdo_2_cfg == 0))
    {
        Cy_USBPD_Vbus_GdrvRstEdgeDet(context, false);
        pd->pgdo_1_cfg &= ~(PDSS_PGDO_1_CFG_AUTO_MODE);
    }
#elif defined(CY_DEVICE_CCG6DF_CFP)
    /* Disable NGDO G2 if provide FET is not turned ON for FRS. */
    if ((PDSS_SWITCH_CTRL_06_SEL_ON_OFF | PDSS_SWITCH_CTRL_06_EN_SWITCH_ON_VALUE) != (pd->switch_ctrl_06 & (PDSS_SWITCH_CTRL_06_SEL_ON_OFF | PDSS_SWITCH_CTRL_06_EN_SWITCH_ON_VALUE)))
    {
        /* Disable Gate 2 charging. */
        pd->ngdo_p5c40_ctrl_1 |= PDSS_NGDO_P5C40_CTRL_1_G2_DISABLE;
    }

    /* Disable the swap-less 5V bits of the Provider FET. Auto mode can be turned off as well. */
    /* NGDO_EN --> AUTO_MODE=0, EN_SWITCH_OFF_VALUE=0, VBUS_C < 5V=0 */
    pd->switch_ctrl_07 &= ~(PDSS_SWITCH_CTRL_07_AUTO_MODE | PDSS_SWITCH_CTRL_07_EN_SWITCH_OFF_VALUE | \
            (0x01u << PDSS_SWITCH_CTRL_07_SEL_FAULT_EN_POS));
    /* CP_EN --> AUTO_MODE=0, EN_SWITCH_OFF_VALUE=0, VBUS_C < 5V=0 */
    pd->switch_ctrl_08 &= ~(PDSS_SWITCH_CTRL_08_AUTO_MODE | PDSS_SWITCH_CTRL_08_EN_SWITCH_OFF_VALUE | \
            (0x01u << PDSS_SWITCH_CTRL_08_SEL_FAULT_EN_POS));
    /* KEEP_OFF_DISABLE --> AUTO_MODE=0, EN_SWITCH_OFF_VALUE=0, VBUS_C < 5V=0 */
    pd->switch_ctrl_09 &= ~(PDSS_SWITCH_CTRL_09_AUTO_MODE | PDSS_SWITCH_CTRL_09_EN_SWITCH_OFF_VALUE | \
            (0x01u << PDSS_SWITCH_CTRL_09_SEL_FAULT_EN_POS));
    /* GDRV_EN --> AUTO_MODE=0, EN_SWITCH_OFF_VALUE=0, VBUS_C < 5V=0 */
    pd->switch_ctrl_06 &= ~(PDSS_SWITCH_CTRL_06_AUTO_MODE | PDSS_SWITCH_CTRL_06_EN_SWITCH_OFF_VALUE | \
            (0x01u << PDSS_SWITCH_CTRL_06_SEL_FAULT_EN_POS));

    Cy_SysLib_DelayUs (100);

    /* Disable auto-mode and swap-less 5V bits of the FRS FET */
    /* FRS_SW_EN --> AUTO_MODE=0, EN_SWITCH_OFF_VALUE=0, EN_SWITH_ON_VALUE=0, SEL_ON_OFF=1 */
    pd->switch_ctrl_11 = PDSS_SWITCH_CTRL_11_SEL_ON_OFF;
    /* FRS_CP_EN --> AUTO_MODE=0, EN_SWITCH_OFF_VALUE=0, EN_SWITH_ON_VALUE=0, SEL_ON_OFF=1 */
    pd->switch_ctrl_10 = PDSS_SWITCH_CTRL_10_SEL_ON_OFF;
    Cy_SysLib_DelayUs (10);
    /* FRS_SW_EN --> RST_EDGE_DET=1 */
    pd->switch_ctrl_11 |= PDSS_SWITCH_CTRL_11_RST_EDGE_DET;
    /* FRS_CP_EN --> RST_EDGE_DET=1 */
    pd->switch_ctrl_10 |= PDSS_SWITCH_CTRL_10_RST_EDGE_DET;
    Cy_SysLib_DelayUs (10);
    /* FRS_SW_EN --> RST_EDGE_DET=0, SEL_ON_OFF=0 */
    pd->switch_ctrl_11 &= ~(PDSS_SWITCH_CTRL_11_RST_EDGE_DET | PDSS_SWITCH_CTRL_11_SEL_ON_OFF);
    /* FRS_CP_EN --> RST_EDGE_DET=0, SEL_ON_OFF=0 */
    pd->switch_ctrl_10 &= ~(PDSS_SWITCH_CTRL_10_RST_EDGE_DET | PDSS_SWITCH_CTRL_10_SEL_ON_OFF);

    pd->frs_ctrl &= ~(PDSS_FRS_CTRL_FRS_ISO_N | PDSS_FRS_CTRL_FRS_CLOCK_SOURCE_MASK);

    /* Disable the FRS sequence bit */
    pd->frs_seq_cntr &= ~PDSS_FRS_SEQ_CNTR_EN_FRS_SEQ;

#endif /* CY_DEVICE */

    /* Restore FET switch condition to default. */
    pd->debug_cc_0 &= ~(PDSS_DEBUG_CC_0_VBUS_C_SWAP_SOURCE_SEL | PDSS_DEBUG_CC_0_VBUS_P_SWAP_SOURCE_SEL);
    return true;
#else
    CY_UNUSED_PARAMETER(context);
    return false;
#endif /* (CY_PD_REV3_ENABLE && CY_PD_FRS_RX_ENABLE) */
}

/*******************************************************************************
* Function Name: Cy_USBPD_Vbus_FrsRx_IntrHandler
****************************************************************************//**
*
* Fast Role Swap Receive Interrupt Handler function.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
*******************************************************************************/
void Cy_USBPD_Vbus_FrsRx_IntrHandler(cy_stc_usbpd_context_t *context)
{
#if (CY_PD_REV3_ENABLE && CY_PD_FRS_RX_ENABLE)
#if (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_CCG6DF_CFP))
    PPDSS_REGS_T pd = context->base;
#endif /* (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_CCG6DF_CFP)) */
#if defined(CY_DEVICE_CCG6)
    uint32_t regVal;
#endif /* defined(CY_DEVICE_CCG6) */

#if defined(CY_DEVICE_CCG6)
    /*
       Clear the AUTO mode on the FETs without affecting their current state. We can
       only do this by assuming that the consumer FET is OFF and the provider FET is ON.
       Please note that it is not possible to handle OV/OC errors while going through
       the Fast Role Transition.
     */
    pd->pgdo_1_cfg &= ~(PDSS_PGDO_1_CFG_PGDO_EN_LV_OFF_VALUE | PDSS_PGDO_1_CFG_PGDO_EN_LV_ON_VALUE);
    pd->pgdo_1_cfg &= ~PDSS_PGDO_1_CFG_AUTO_MODE;
    Cy_USBPD_Vbus_GdrvRstEdgeDet(context, false);
    /* Use PGDO_PU_1_CFG register for Provider FET */
    pd->pgdo_pu_1_cfg &= ~PDSS_PGDO_PU_1_CFG_PGDO_PU_EN_LV_OFF_VALUE;
    pd->pgdo_pu_1_cfg |= PDSS_PGDO_PU_1_CFG_PGDO_PU_EN_LV_ON_VALUE;
    Cy_SysLib_DelayUs (1);

    Cy_USBPD_Vbus_GdrvRstEdgeDet(context, true);

    /* Use PGDO_PU_1_CFG register for Provider FET */
    regVal = pd->pgdo_pu_1_cfg;
    regVal &= ~(PDSS_PGDO_PU_1_CFG_AUTO_MODE | PDSS_PGDO_PU_1_CFG_PGDO_PU_IN_LV_ON_VALUE);
    regVal |= PDSS_PGDO_PU_1_CFG_SEL_ON_OFF;
    pd->pgdo_pu_1_cfg = regVal;
#elif defined(CY_DEVICE_CCG6DF_CFP)

    /* Provide some delay to allow the provider NGDO turn to be completed. */
    Cy_SysLib_DelayUs (25);

    /*
     * Remember the fact that the provider FET is on so that a subsequent
     * soft start does not cause supply to be turned off.
     */
    /* NGDO_EN SEL_ON_OFF=1, EN_SWITCH_ON_VALUE=1*/
    pd->switch_ctrl_07 |= PDSS_SWITCH_CTRL_07_EN_SWITCH_ON_VALUE;
    Cy_SysLib_DelayUs(1);
    pd->switch_ctrl_07 |= PDSS_SWITCH_CTRL_07_SEL_ON_OFF;
    Cy_SysLib_DelayUs(1);
    /* CP_EN SEL_ON_OFF=1, EN_SWITCH_ON_VALUE=1*/
    pd->switch_ctrl_08 |= PDSS_SWITCH_CTRL_08_EN_SWITCH_ON_VALUE;
    Cy_SysLib_DelayUs(1);
    pd->switch_ctrl_08 |= PDSS_SWITCH_CTRL_08_SEL_ON_OFF;
    Cy_SysLib_DelayUs(1);
    /* KEEP_OFF_DIS SEL_ON_OFF=1, EN_SWITCH_ON_VALUE=1*/
    pd->switch_ctrl_09 |= PDSS_SWITCH_CTRL_09_EN_SWITCH_ON_VALUE;
    Cy_SysLib_DelayUs(1);
    pd->switch_ctrl_09 |= PDSS_SWITCH_CTRL_09_SEL_ON_OFF;
    Cy_SysLib_DelayUs(1);
    /* GDRV_EN SEL_ON_OFF=1, EN_SWITCH_ON_VALUE=1*/
    pd->switch_ctrl_06 |= PDSS_SWITCH_CTRL_06_EN_SWITCH_ON_VALUE;
    Cy_SysLib_DelayUs(1);
    pd->switch_ctrl_06 |= PDSS_SWITCH_CTRL_06_SEL_ON_OFF;

    Cy_USBPD_Vbus_GdrvRstEdgeDet(context, true);

#endif /* defined(CY_DEVICE) */

    /* Signal event to enable provider path for devices like PMG1S3.*/
    if (NULL != context->usbpdEventsCbk)
    {
        context->usbpdEventsCbk (context, CY_USBPD_EVT_FRS_VBUS_LESS_5_DONE, (void *)(context->pdStackContext));
    }

    /* Remember the fact that the provider FET is on so that a subsequent
     * soft start does not cause supply to be turned off.
     */
    context->vbusPfetOn = true;

    Cy_SysLib_DelayUs (1);
    Cy_USBPD_Vbus_FrsRxDisable(context);
#else
    CY_UNUSED_PARAMETER(context);
#endif /* (CY_PD_REV3_ENABLE && CY_PD_FRS_RX_ENABLE) */
}

#if defined(CY_DEVICE_PMG1S3)
#define FRS_TX_GPIO_PORT_PIN_P0 (0x21)
#define FRS_TX_GPIO_PORT_PIN_P1 (0x26)
#endif /* defined(CY_DEVICE_PMG1S3) */

/* DEBUG_CC_1 Register Setting */
#define PDSS_TX_STOP_ON_SWAP_MASK       (1u << 26u)

/* Swap CTRL settings for FRS TX */
#define FRS_TX_IRQ_WIDTH                (900u)
#define FRS_TX_SWAP_CTRL1_DFLT_VAL      (FRS_TX_IRQ_WIDTH | PDSS_SWAPT_CTRL1_DEFAULT_LEVEL |    \
                                         (2u << PDSS_SWAPT_CTRL1_COMMAND_POS) |                 \
                                         PDSS_SWAPT_CTRL1_RESET_SWAPT_STATE)
/*******************************************************************************
* Function Name: Cy_USBPD_Vbus_FrsTxEnable
****************************************************************************//**
*
* Enables the fast role swap transmit functionality. Callback
* registered in Cy_USBPD_Phy_Init will be called when FRS signal is received.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \return bool
* Returns true if success, otherwise returns false.
*
*******************************************************************************/
bool Cy_USBPD_Vbus_FrsTxEnable(cy_stc_usbpd_context_t *context)
{
#if (CY_PD_REV3_ENABLE && CY_PD_FRS_TX_ENABLE && defined(CY_DEVICE_PMG1S3))
    cy_stc_pd_dpm_config_t* dpmConfig = context->dpmGetConfig();
    PPDSS_REGS_T pd = context->base;
    
    /* Configure FRS TX source */
    if(context->port == TYPEC_PORT_0_IDX)
    {
        /* Configuring a GPIO for trigering FRS signal */
        Cy_GPIO_SetDrivemode(Cy_GPIO_PortToAddr(FRS_TX_GPIO_PORT_PIN_P0 >> 4),
                (FRS_TX_GPIO_PORT_PIN_P0 & 0x0Fu), CY_GPIO_DM_HIGHZ);
        Cy_GPIO_SetHSIOM(Cy_GPIO_PortToAddr(FRS_TX_GPIO_PORT_PIN_P0 >> 4),
                (FRS_TX_GPIO_PORT_PIN_P0 & 0x0Fu), (en_hsiom_sel_t)P2_1_USBPD0_SWAPT_IN);
    }
#if PMG1_PD_DUALPORT_ENABLE
    if (context->port == TYPEC_PORT_1_IDX)
    {
        /* Configuring a GPIO for trigering FRS signal */
        Cy_GPIO_SetDrivemode(Cy_GPIO_PortToAddr(FRS_TX_GPIO_PORT_PIN_P1 >> 4),
                (FRS_TX_GPIO_PORT_PIN_P0 & 0x0Fu), CY_GPIO_DM_HIGHZ);
        Cy_GPIO_SetHSIOM(Cy_GPIO_PortToAddr(FRS_TX_GPIO_PORT_PIN_P1 >> 4),
                (FRS_TX_GPIO_PORT_PIN_P0 & 0x0Fu), (en_hsiom_sel_t)P2_6_USBPD1_SWAPT_IN);
    }
#endif /* PMG1_PD_DUALPORT_ENABLE */

    /* Configure for Auto FRS signal transmitting */
    pd->debug_cc_1 &= ~(PDSS_DEBUG_CC_1_PFET300_PULLDN_EN_CC1 |
                PDSS_DEBUG_CC_1_PFET300_PULLDN_EN_CC2 |
                PDSS_DEBUG_CC_1_SWAPT_TO_CC1_EN |
                PDSS_DEBUG_CC_1_SWAPT_TO_CC2_EN);

    /* Enable TX discard on swap */
    pd->debug_cc_1 |= PDSS_TX_STOP_ON_SWAP_MASK;

    pd->swap_ctrl0 = PDSS_SWAP_CTRL0_SWAP_ENABLED;
    pd->swap_ctrl0 |= 1UL;

    pd->swap_ctrl0 |= PDSS_SWAP_CTRL0_SWAPT_POLARITY;
    pd->swapt_ctrl1 = FRS_TX_SWAP_CTRL1_DFLT_VAL;

    /* Enable necessary interrupts */
    pd->intr2 = PDSS_INTR2_SWAP_COMMAND_DONE;
    pd->intr2_mask |= PDSS_INTR2_SWAP_COMMAND_DONE;

    /* This delay is needed otherwise swap TX indefinitely short the cc line */
    Cy_SysLib_DelayUs(10);

    /* Enable the swap tx  */
    pd->swapt_ctrl1 &= ~PDSS_SWAPT_CTRL1_RESET_SWAPT_STATE;

    /* Set cc polarity for pulldowns */
    if(dpmConfig->polarity == CY_PD_CC_CHANNEL_2)
    {
        pd->debug_cc_1 |= (PDSS_DEBUG_CC_1_SWAPT_TO_CC2_EN);
    }
    else
    {
        pd->debug_cc_1 |= (PDSS_DEBUG_CC_1_SWAPT_TO_CC1_EN);
    }

    return true;
#else
    CY_UNUSED_PARAMETER(context);
    return false;
#endif /* (CY_PD_REV3_ENABLE && CY_PD_FRS_TX_ENABLE && defined(CY_DEVICE_PMG1S3)) */
}

/*******************************************************************************
* Function Name: Cy_USBPD_Vbus_FrsTxDisable
****************************************************************************//**
*
* Disables the fast role swap transmit functionality.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \return bool
* Returns true if success, otherwise returns false.
*
*******************************************************************************/
bool Cy_USBPD_Vbus_FrsTxDisable(cy_stc_usbpd_context_t *context)
{
#if (CY_PD_REV3_ENABLE && CY_PD_FRS_TX_ENABLE && defined(CY_DEVICE_PMG1S3))
    PPDSS_REGS_T pd = context->base;

    /* Disable the swap controller */
    pd->swapt_ctrl1 = PDSS_SWAPT_CTRL1_RESET_SWAPT_STATE;
    pd->swap_ctrl0 &= ~PDSS_SWAP_CTRL0_SWAP_ENABLED;

    /* Clear and disable frs receive interrupts */
    pd->intr2_mask &= ~PDSS_INTR2_SWAP_COMMAND_DONE;
    pd->intr2       = PDSS_INTR2_SWAP_COMMAND_DONE;

    /* Disable pulldown */
    pd->debug_cc_1 &= ~(PDSS_DEBUG_CC_1_SWAPT_TO_CC1_EN |
                PDSS_DEBUG_CC_1_SWAPT_TO_CC2_EN);

    return true;
#else
    CY_UNUSED_PARAMETER(context);
    return false;
#endif /* (CY_PD_REV3_ENABLE && CY_PD_FRS_TX_ENABLE && defined(CY_DEVICE_PMG1S3)) */
}


/*******************************************************************************
* Function Name: Cy_USBPD_Vbus_GdrvRstEdgeDet
****************************************************************************//**
*
* Resets the gate driver edge detector to clear any fault state.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \param pgdoType
* Flag indicating the gate driver to be cleared, true for P_CTRL
* and false for C_CTRL.
*
*******************************************************************************/
void Cy_USBPD_Vbus_GdrvRstEdgeDet(cy_stc_usbpd_context_t *context, bool pgdoType)
{
    PPDSS_REGS_T pd = context->base;

    (void)pd;

#if (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG6))
    /* True indicates PGDO with internal pull up. */
    if (pgdoType)
    {
        /* Reset edge detector. */
        pd->pgdo_pu_1_cfg |= PDSS_PGDO_PU_1_CFG_RST_EDGE_DET;
        pd->pgdo_pu_1_cfg &= ~PDSS_PGDO_PU_1_CFG_RST_EDGE_DET;
    }
    else
    {
        /* Reset edge detector. */
        pd->pgdo_1_cfg |= PDSS_PGDO_1_CFG_RST_EDGE_DET;
        pd->pgdo_1_cfg &= ~PDSS_PGDO_1_CFG_RST_EDGE_DET;
    }
#elif defined(CY_DEVICE_CCG3)
    if (pgdoType)
    {
        pd->ngdo_ctrl_p |= PDSS_NGDO_CTRL_P_RST_EDGE_DET;
        pd->ngdo_ctrl_p &= ~PDSS_NGDO_CTRL_P_RST_EDGE_DET;
    }
    else
    {
        pd->ngdo_ctrl_c |= PDSS_NGDO_CTRL_C_RST_EDGE_DET;
        pd->ngdo_ctrl_c &= ~PDSS_NGDO_CTRL_C_RST_EDGE_DET;
    }
#elif defined(CY_DEVICE_CCG6DF_CFP)
    if (pgdoType)
    {
        /* Reset all the gate driver controls. */
        pd->switch_ctrl_07 |= PDSS_SWITCH_CTRL_07_RST_EDGE_DET;
        pd->switch_ctrl_08 |= PDSS_SWITCH_CTRL_08_RST_EDGE_DET;
        pd->switch_ctrl_09 |= PDSS_SWITCH_CTRL_09_RST_EDGE_DET;
        pd->switch_ctrl_06 |= PDSS_SWITCH_CTRL_06_RST_EDGE_DET;

        pd->switch_ctrl_07 &= ~PDSS_SWITCH_CTRL_07_RST_EDGE_DET;
        pd->switch_ctrl_08 &= ~PDSS_SWITCH_CTRL_08_RST_EDGE_DET;
        pd->switch_ctrl_09 &= ~PDSS_SWITCH_CTRL_09_RST_EDGE_DET;
        pd->switch_ctrl_06 &= ~PDSS_SWITCH_CTRL_06_RST_EDGE_DET;
    }
    else
    {
        /* CFET is external to the CFP. */
    }
#elif (defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1) || defined(CY_DEVICE_CCG7D))
    CY_UNUSED_PARAMETER(pgdoType);
    pd->bb_ngdo_0_gdrv_en_ctrl |= PDSS_BB_NGDO_0_GDRV_EN_CTRL_RST_EDGE_DET;
    pd->bb_ngdo_0_gdrv_en_ctrl &= ~PDSS_BB_NGDO_0_GDRV_EN_CTRL_RST_EDGE_DET;
#else
    CY_UNUSED_PARAMETER(context);
    CY_UNUSED_PARAMETER(pgdoType);
#endif /* CY_DEVICE */
}


/*******************************************************************************
* Function Name: Cy_USBPD_Vbus_RemoveIntrnlFbDiv
****************************************************************************//**
*
* Removes internal feedback resistor divider.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
*******************************************************************************/
void Cy_USBPD_Vbus_RemoveIntrnlFbDiv(cy_stc_usbpd_context_t *context)
{
#if defined(CY_DEVICE_CCG3PA)
    PPDSS_REGS_T pd = context->base;
    pd->ea_ctrl |= PDSS_EA_CTRL_RES_DIV_BYPASS;
#else
    CY_UNUSED_PARAMETER(context);
#endif /* defined(CY_DEVICE_CCG3PA) */
}

/*******************************************************************************
* Function Name: Cy_USBPD_Vbus_GdrvIsSnkFetOn
****************************************************************************//**
*
* Check whether the Sink FET has been turned on.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \return bool
* Returns true if the sink path is on to allow system to charge.
*
*******************************************************************************/
bool Cy_USBPD_Vbus_GdrvIsSnkFetOn (cy_stc_usbpd_context_t *context)
{
    return (context->vbusCfetOn);
}

/*******************************************************************************
* Function Name: Cy_USBPD_Vbus_NgdoEqCtrl
****************************************************************************//**
*
* Enable/Disable the equalizer between the Gates and Source/Drain of the Gate driver circuit. 
* Use this API after turning off Gate-1 during Pfet turn Off sequence. This is only 
* applicable to PMG1S3 device.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \param value
* Gate-1 control value.
* False: Disable the equalizer.
* True: Enable the equalizer.
*
*******************************************************************************/
void Cy_USBPD_Vbus_NgdoEqCtrl(cy_stc_usbpd_context_t *context, bool value)
{
#if defined(CY_DEVICE_PMG1S3)
    PPDSS_REGS_T pd = context->base;
    
    pd->v2_ngdo_0_ctrl &= ~PDSS_V2_NGDO_0_CTRL_NGDO_GRV_EN;
    if(value == true)
    {
        pd->v2_ngdo_1_ctrl |= (1UL << 23) | (1UL << 8);
    }
    else
    {
        pd->v2_ngdo_1_ctrl &= ~((1UL << 23) | (1UL << 8));
    }
#else
    CY_UNUSED_PARAMETER(context);
    CY_UNUSED_PARAMETER(value);
#endif /* defined(CY_DEVICE_PMG1S3) */
}
/*******************************************************************************
* Function Name: Cy_USBPD_Fault_Vbus_IlimConfigUpdate
****************************************************************************//**
*
* Updates the Ilimit config value
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \param current
* Load Current value in 10mA
*
*******************************************************************************/
void Cy_USBPD_Fault_Vbus_IlimConfigUpdate (cy_stc_usbpd_context_t *context, uint32_t current)
{
#if PDL_VBUS_ILIM_ENABLE
#if defined(CY_DEVICE_CCG6DF_CFP)
    PPDSS_REGS_T pd = context->base;
    uint32_t regval = 0;
    uint32_t ilim_config = 0;

    /* Calculate the current value in mA. */
    current *=  10;

    /* Calculate the load current with threshold for Ilimit. */
    current += ((current * ILIM_THRESHOLD) / 100);

    /* Check if the load current is greater than the minimum supported load current by Ilimit block.
     * IF the load current is less than the minimum supported load current,
     * then Ilimit load current configuration value will be 0 (current will be limited to ILIM_REF_LOAD_CURRENT */
    if ( current > ILIM_REF_LOAD_CURRENT)
    {
        /* Ilimit load current configuration value calculation.
         * Load current configuration needs to be set with step size = 65/32 for config_2x_step_ctrl = 1/0
         * Reference load current to be subtracted from load current.
         * Reference load current is the minimum load current required for Ilimit Block to be functional */
        ilim_config = (( current - ILIM_REF_LOAD_CURRENT ) / ILIM_CONFIG_STEP_SIZE);

    }

    regval = pd->pd_ilimt_ctrl;

    /* Config the load limit step size to 120mA by clearing config_2x_step_ctrl. */
    regval |= ~(PDSS_PD_ILIMT_CTRL_CONFIG_2X_STEP_CTRL);

    /* Set Ilimit load current configuration value. */
    regval &= ~(PDSS_PD_ILIMT_CTRL_CONFIG_ILIMIT_MASK);
    regval |= (ilim_config << PDSS_PD_ILIMT_CTRL_CONFIG_ILIMIT_POS);

    pd->pd_ilimt_ctrl = regval;
#endif /* defined(CY_DEVICE_CCG6DF_CFP) */
#else /* PDL_VBUS_ILIM_ENABLE */
    CY_UNUSED_PARAMETER(context);
    CY_UNUSED_PARAMETER(current);
#endif /* PDL_VBUS_ILIM_ENABLE */

}
/*******************************************************************************
* Function Name: Cy_USBPD_Fault_Vbus_IlimEnable
****************************************************************************//**
*
* Enables Ilimit Block
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \param current
* Load Current value in 10mA
*
*******************************************************************************/
void Cy_USBPD_Fault_Vbus_IlimEnable (cy_stc_usbpd_context_t *context, uint32_t current)
{
#if PDL_VBUS_ILIM_ENABLE
#if defined(CY_DEVICE_CCG6DF_CFP)
    PPDSS_REGS_T pd = context->base;
    uint32_t regval = 0;
    uint32_t ilim_config = 0;

    /* Reading pd_vsense_ctrl_1 register into local variable. */
    regval = pd->pd_vsense_ctrl_1;

    /* Power-up VSENSE Block. */
    regval &= ~PDSS_PD_VSENSE_CTRL_1_VSENSE_PD;

    /* Gain value selection for voltage sense output.
     * SEL_AV_VSENSE_OUT --> 2 (AV = 10% supports 1A - 3A) */
    regval &= ~(PDSS_PD_VSENSE_CTRL_1_SEL_AV_VSENSE_OUT_MASK);
    regval |= (0x02u << PDSS_PD_VSENSE_CTRL_1_SEL_AV_VSENSE_OUT_POS);

    pd->pd_vsense_ctrl_1 = regval;

    /* Disable output isolation and Enable Ilimit sense current output. */
    pd->pd_vsense_ctrl_0 |= PDSS_PD_VSENSE_CTRL_0_ISO_N | PDSS_PD_VSENSE_CTRL_0_EN_ILIMT_ISENSEOUT;

    /* 100 micro-seconds delay before enabling signal for VSENSE block. */
    Cy_SysLib_DelayUs(100);

    /* Enable signal for VSENSE Block. */
    pd->pd_vsense_ctrl_1 |= (PDSS_PD_VSENSE_CTRL_1_EN_VSENSE);

    /* Update the Ilimit config. */
    Cy_USBPD_Fault_Vbus_IlimConfigUpdate (context, current);

    /* Disable output isolation and Enable signal for Ilimit Block. */
    pd->pd_ilimt_ctrl |= (PDSS_PD_ILIMT_CTRL_ISO_N | PDSS_PD_ILIMT_CTRL_ILIMIT_EN );

#endif /* defined(CY_DEVICE_CCG6DF_CFP) */
#else /* PDL_VBUS_ILIM_ENABLE */
    CY_UNUSED_PARAMETER(context);
    CY_UNUSED_PARAMETER(current);
#endif /* PDL_VBUS_ILIM_ENABLE */
}

/*******************************************************************************
* Function Name: Cy_USBPD_Fault_Vbus_IlimDisable
****************************************************************************//**
*
* Disables Ilimit Block
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
*******************************************************************************/
void Cy_USBPD_Fault_Vbus_IlimDisable (cy_stc_usbpd_context_t *context)
{
#if PDL_VBUS_ILIM_ENABLE
#if defined(CY_DEVICE_CCG6DF_CFP)
    PPDSS_REGS_T pd = context->base;
    uint32_t regval = 0;

    /* Reading pd_ilimt_ctrl register into local variable. */
    regval = pd->pd_ilimt_ctrl;

    /* Enable output isolation and Disable signal for Ilimit Block. */
    regval &= ~(PDSS_PD_ILIMT_CTRL_ISO_N | PDSS_PD_ILIMT_CTRL_ILIMIT_EN);

    pd->pd_ilimt_ctrl = regval;

    /* Disable Vsense Block only if OCP is not enabled. */
    if ((pd->pd_vsense_ctrl_0 & PDSS_PD_VSENSE_CTRL_0_EN_OCP) != PDSS_PD_VSENSE_CTRL_0_EN_OCP)
    {
        /* Reading pd_vsense_ctrl_1 register into local variable. */
        regval = pd->pd_vsense_ctrl_1;

        /* Power-down VSENSE Block. */
        regval |= PDSS_PD_VSENSE_CTRL_1_VSENSE_PD;

        /* Disable signal for VSENSE Block. */
        regval &= ~(PDSS_PD_VSENSE_CTRL_1_EN_VSENSE);

        pd->pd_vsense_ctrl_1 = regval;

        /* Enable output isolation and Disable Ilimit sense current output. */
        pd->pd_vsense_ctrl_0 &= ~(PDSS_PD_VSENSE_CTRL_0_ISO_N | PDSS_PD_VSENSE_CTRL_0_EN_ILIMT_ISENSEOUT);

    }
#endif /* defined(CY_DEVICE_CCG6DF_CFP) */
#else /* PDL_VBUS_ILIM_ENABLE */
    CY_UNUSED_PARAMETER(context);
#endif /* PDL_VBUS_ILIM_ENABLE */
}

/*******************************************************************************
* Function Name: Cy_USBPD_Vbus_NgdoG1Ctrl
****************************************************************************//**
*
* Control the Gate-1 on the VBUS-C side of the Gate driver circuit. This is only 
* applicable to PMG1S3 device.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \param value
* Gate-1 control value.
* False: Gate-1 is pulled down to turn the FET off.
* True: Gate-1 is allowed to charge for turning on the FET.
*
*******************************************************************************/
void Cy_USBPD_Vbus_NgdoG1Ctrl(cy_stc_usbpd_context_t *context, bool value)
{
#if defined(CY_DEVICE_PMG1S3)
    PPDSS_REGS_T pd = context->base;
    
    if(value == true)
    {
        pd->v2_ngdo_1_ctrl |= PDSS_V2_NGDO_1_CTRL_V2_NGDO_EN_G1_CHRG;
    }
    else
    {
        pd->v2_ngdo_1_ctrl &= ~PDSS_V2_NGDO_1_CTRL_V2_NGDO_EN_G1_CHRG;
    }
#elif defined(CY_DEVICE_CCG6DF_CFP)
    PPDSS_REGS_T pd = context->base;
    
    if(value == true)
    {
#if defined(PDL_VBUS_SCP_ENABLE)
        /* Enable SCP comparator output after enabling the G2.
         * Make sure SCP is enabled earlier. SCP_PD shall be 0 and ISO_N shall be 1. 
         */

        if ((pd->pd_40scp_ctrl & (PDSS_PD_40SCP_CTRL_SCP_PD | PDSS_PD_40SCP_CTRL_ISO_N)) == PDSS_PD_40SCP_CTRL_ISO_N)
        {
            pd->pd_40scp_ctrl |= PDSS_PD_40SCP_CTRL_SCP_COMP_OUT_EN;
        }
#endif /* defined(PDL_VBUS_SCP_ENABLE) */
        /* Enable Gate 2 charging. */
        pd->ngdo_p5c40_ctrl_1 &= ~PDSS_NGDO_P5C40_CTRL_1_G2_DISABLE;
    }
    else
    {
        /* Disable Gate 2 charging. */
        pd->ngdo_p5c40_ctrl_1 |= PDSS_NGDO_P5C40_CTRL_1_G2_DISABLE;
    }
#else
    CY_UNUSED_PARAMETER(context);
    CY_UNUSED_PARAMETER(value);
#endif /* defined(CY_DEVICE_PMG1S3) */
}
/*******************************************************************************
* Function Name: Cy_USBPD_PfetDynDsEnable
****************************************************************************//**
*
* Dynamically change the VBUS FET drive strength.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
*******************************************************************************/
void Cy_USBPD_PfetDynDsEnable(cy_stc_usbpd_context_t *context)
{
#if CCG_DYN_PFET_GATE_DRV_ENABLE
    PPDSS_REGS_T pd = context->base;

    uint32_t ngdo_slew = CY_USBPD_REG_FIELD_GET(pd->ngdo_ctrl,
        PDSS_NGDO_CTRL_NGDO_SLEW_CTRL);

    /*
     * Vbus Source gate driver slew configuration for optimum operation.
     * Revert to config table value once FET is turned off to have
     * required drive strength for rise time.
     */
    if(ngdo_slew < CCG_DYN_PFET_GATE_DRV_TYP)
    {
        CY_USBPD_REG_FIELD_UPDATE(pd->ngdo_ctrl,
            PDSS_NGDO_CTRL_NGDO_SLEW_CTRL, CCG_DYN_PFET_GATE_DRV_TYP);
    }
    else
    {
        /* NGDO drive strength is already more than required drive strength */
    }
#else /* CCG_DYN_PFET_GATE_DRV_ENABLE */
    CY_UNUSED_PARAMETER(context);
#endif /* CCG_DYN_PFET_GATE_DRV_ENABLE */
}

/*******************************************************************************
* Function Name: Cy_USBPD_Vbus_NgdoSetDriveStrength
****************************************************************************//**
*
* Set the drive strength of the producer FET using the internal gate driver.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \param value
* The drive strength value with bit step size (current) as 150nA. 
* Max value allowed is 4200nA (0x1C).
*
*******************************************************************************/
void Cy_USBPD_Vbus_NgdoSetDriveStrength(cy_stc_usbpd_context_t *context, uint8_t value)
{
#if defined(CY_DEVICE_PMG1S3)
    PPDSS_REGS_T pd = context->base;
    
    /* Never set a higher value than maximum */
    if(value > 0x1Cu)
    {
        value = 0x1Cu; 
    }

    /* Clear the NGDO slew control field */
    pd->v2_ngdo_0_ctrl &= ~PDSS_V2_NGDO_0_CTRL_V2_NGDO_SLEW_CTRL_MASK;
    /* Set the value for NGDO slew control */ 
    pd->v2_ngdo_0_ctrl |= ((uint32_t)value << PDSS_V2_NGDO_0_CTRL_V2_NGDO_SLEW_CTRL_POS);

#elif defined(CY_DEVICE_CCG6DF_CFP)
    PPDSS_REGS_T pd = context->base;
    uint32_t regVal;
    
    /* Never set a higher value than maximum */
    if(value > 0x1Cu)
    {
        value = 0x1Cu; 
    }

    /* Clear the NGDO slew control field */
    regVal = pd->ngdo_p5c40_ctrl_0;
    regVal &= ~PDSS_NGDO_P5C40_CTRL_0_SLEW_CTRL_MASK;
    /* Set the value for NGDO slew control */ 
    regVal |= ((uint32_t)value << PDSS_NGDO_P5C40_CTRL_0_SLEW_CTRL_POS);
    pd->ngdo_p5c40_ctrl_0 = regVal;

#else
    CY_UNUSED_PARAMETER(context);
    CY_UNUSED_PARAMETER(value);
#endif /* defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP) */
}

/*******************************************************************************
* Function Name: Cy_USBPD_Vbus_GdrvPfetOn
****************************************************************************//**
*
* Turn on producer FET using the internal gate driver or dedicated GPIO.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \param turnOnSeq
* Turn On sequence On PMG1S2, this bit selects which FET turns on first.
*  - 0: FET 0 turns on first.
*  - 1: FET 1 turns on first.
*
*******************************************************************************/
void Cy_USBPD_Vbus_GdrvPfetOn(cy_stc_usbpd_context_t *context, bool turnOnSeq)
{
#if ((!CY_PD_SINK_ONLY) || (PMG1B1_USB_CHARGER))
    PPDSS_REGS_T pd = context->base;
    uint32_t regVal = 0;
    uint32_t state = 0;

    CY_UNUSED_PARAMETER(regVal);
    CY_UNUSED_PARAMETER(state);
    CY_UNUSED_PARAMETER(pd);
    CY_UNUSED_PARAMETER(turnOnSeq);

#if defined(CY_DEVICE_PMG1S3)
    pd->v2_ngdo_0_ctrl |= (PDSS_V2_NGDO_0_CTRL_NGDO_ISO_N | PDSS_V2_NGDO_0_CTRL_NGDO_EN_LV);
    Cy_SysLib_DelayUs(20);
    pd->v2_ngdo_0_ctrl |= PDSS_V2_NGDO_0_CTRL_NGDO_CP_EN;
    Cy_SysLib_DelayUs(20);
    pd->v2_ngdo_0_ctrl |= PDSS_V2_NGDO_0_CTRL_NGDO_GRV_EN;
    
    context->vbusPfetOn = true;
#endif /* defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP) */
#if defined(CY_DEVICE_CCG6DF_CFP)
    /* Enable output isolation control. */
    pd->ngdo_p5c40_ctrl_0 |= PDSS_NGDO_P5C40_CTRL_0_ISO_N;

    /* Reset the edge detector. */
    Cy_USBPD_Vbus_GdrvRstEdgeDet(context, true);

    /* NGDO_EN SEL_ON_OFF=1, EN_SWITCH_ON_VALUE=1*/
    pd->switch_ctrl_07 = PDSS_SWITCH_CTRL_07_SEL_ON_OFF | PDSS_SWITCH_CTRL_07_EN_SWITCH_ON_VALUE;
    Cy_SysLib_DelayUs(20);
    /* CP_EN SEL_ON_OFF=1, EN_SWITCH_ON_VALUE=1*/
    pd->switch_ctrl_08 = PDSS_SWITCH_CTRL_08_SEL_ON_OFF | PDSS_SWITCH_CTRL_08_EN_SWITCH_ON_VALUE;
    Cy_SysLib_DelayUs(20);
    /* KEEP_OFF_DIS SEL_ON_OFF=1, EN_SWITCH_ON_VALUE=1*/
    pd->switch_ctrl_09 = PDSS_SWITCH_CTRL_09_SEL_ON_OFF | PDSS_SWITCH_CTRL_09_EN_SWITCH_ON_VALUE;
    Cy_SysLib_DelayUs(20);
    /* GDRV_EN SEL_ON_OFF=1, EN_SWITCH_ON_VALUE=1*/
    pd->switch_ctrl_06 = PDSS_SWITCH_CTRL_06_SEL_ON_OFF | PDSS_SWITCH_CTRL_06_EN_SWITCH_ON_VALUE;
    
    context->vbusPfetOn = true;
#endif /* defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP) */


#if (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_CCG3PA))

    /* We can turn sink FET OFF if source FET is being turned ON. */
    Cy_USBPD_Vbus_GdrvCfetOff(context, turnOnSeq);

    /* Reset the edge detector. */
    Cy_USBPD_Vbus_GdrvRstEdgeDet(context, true);

    state = Cy_SysLib_EnterCriticalSection();

#if !SOFT_START_ENABLE
    /* Enable the pull-down for the FET. */
    pd->pgdo_pd_isnk_cfg = PDSS_PGDO_PD_ISNK_CFG_DEFAULT;
#endif /* SOFT_START_ENABLE */

    context->vbusPfetOn = true;

    /* Turn on the fet by setting ENABLE_ON bit and clearing IN_ON bit. */
    regVal = pd->pgdo_pu_1_cfg;
    regVal |= (PDSS_PGDO_PU_1_CFG_SEL_ON_OFF | PDSS_PGDO_PU_1_CFG_PGDO_PU_EN_LV_ON_VALUE);
    regVal &= ~PDSS_PGDO_PU_1_CFG_PGDO_PU_IN_LV_ON_VALUE;
    pd->pgdo_pu_1_cfg = regVal;

    Cy_SysLib_ExitCriticalSection (state);
#endif /* (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_CCG3PA)) */

#if defined(CY_DEVICE_CCG3)
    /* We can turn sink FET OFF if source FET is being turned ON. */
    Cy_USBPD_Vbus_GdrvCfetOff(context, turnOnSeq);

    state = Cy_SysLib_EnterCriticalSection();

    /* Assuming use of dual N-Channel FETs here. */

    /* Turn-the first FET ON. */
    regVal = pd->ngdo_ctrl_0;
    if (!turnOnSeq)
    {
        regVal &= ~VBUS_P_PLDN_EN_LV_0;
        regVal |= VBUS_P_NGDO_EN_LV_0;
    }
    else
    {
        regVal &= ~VBUS_P_PLDN_EN_LV_1;
        regVal |= VBUS_P_NGDO_EN_LV_1;
    }

    pd->ngdo_ctrl_0 = regVal;

    /* Now turn the second FET ON after a delay. */
    Cy_SysLib_DelayUs (10);

    if (!turnOnSeq)
    {
        regVal &= ~VBUS_P_PLDN_EN_LV_1;
        regVal |= VBUS_P_NGDO_EN_LV_1;
    }
    else
    {
        regVal &= ~VBUS_P_PLDN_EN_LV_0;
        regVal |= VBUS_P_NGDO_EN_LV_0;
    }

    pd->ngdo_ctrl_0 = regVal;
    context->vbusPfetOn = true;

    /* Reset the edge detector to make sure FETs turn ON. */
    Cy_USBPD_Vbus_GdrvRstEdgeDet (context, true);

    Cy_SysLib_ExitCriticalSection (state);
#endif /* defined(CY_DEVICE_CCG3) */

#if defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)
    pd->ngdo_ctrl |= (PDSS_NGDO_CTRL_NGDO_ISO_N | PDSS_NGDO_CTRL_NGDO_EN_LV);
    Cy_SysLib_DelayUs(50);
    pd->ngdo_ctrl |= (PDSS_NGDO_CTRL_NGDO_CP_EN);
    Cy_SysLib_DelayUs(50);

    /* Reset the edge detector. */
    Cy_USBPD_Vbus_GdrvRstEdgeDet(context, true);

    pd->bb_ngdo_0_gdrv_en_ctrl = (PDSS_BB_NGDO_0_GDRV_EN_CTRL_SEL_ON_OFF |
            PDSS_BB_NGDO_0_GDRV_EN_CTRL_GDRV_EN_ON_VALUE);

    context->vbusPfetOn = true;
#endif /* defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1) */

#else
    CY_UNUSED_PARAMETER(context);
    CY_UNUSED_PARAMETER(turnOnSeq);
#endif /*  ((!CY_PD_SINK_ONLY) || (PMG1B1_USB_CHARGER)) */
}


/*******************************************************************************
* Function Name: Cy_USBPD_Vbus_GdrvPfetOff
****************************************************************************//**
*
* Turn OFF producer FET using the internal gate driver or dedicated GPIO.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \param turnOffSeq
* Turn Off sequence On PMG1S2, this bit selects which FET turns on first.
*  - 0: FET 0 turns on first.
*  - 1: FET 1 turns on first.
*
*******************************************************************************/
void Cy_USBPD_Vbus_GdrvPfetOff(cy_stc_usbpd_context_t *context, bool turnOffSeq)
{
#if ((!CY_PD_SINK_ONLY) || (PMG1B1_USB_CHARGER))
    PPDSS_REGS_T pd = context->base;

    CY_UNUSED_PARAMETER(pd);
    CY_UNUSED_PARAMETER(turnOffSeq);

#if defined(CY_DEVICE_PMG1S3)
    context->vbusPfetOn = false;

    pd->v2_ngdo_0_ctrl &= ~PDSS_V2_NGDO_0_CTRL_NGDO_GRV_EN;
    Cy_SysLib_DelayUs(20);
    pd->v2_ngdo_0_ctrl &= ~PDSS_V2_NGDO_0_CTRL_NGDO_CP_EN;
    Cy_SysLib_DelayUs(20);    
    pd->v2_ngdo_0_ctrl &= ~(PDSS_V2_NGDO_0_CTRL_NGDO_ISO_N | PDSS_V2_NGDO_0_CTRL_NGDO_EN_LV);
    Cy_SysLib_DelayUs(20);
    pd->v2_ngdo_0_ctrl&= ~(PDSS_V2_NGDO_0_CTRL_NGDO_FAULT_RCP_EN | PDSS_V2_NGDO_0_CTRL_NGDO_FAULT_SCP_EN | PDSS_V2_NGDO_0_CTRL_NGDO_FAULT_VBUS_OV_EN);
#endif /* defined(CY_DEVICE_PMG1S3) */
#if defined(CY_DEVICE_CCG6DF_CFP)
    context->vbusPfetOn = false;

    /* clear all the fields including AUTO mode as well. */
    pd->switch_ctrl_06 = PDSS_SWITCH_CTRL_06_DEFAULT;
    Cy_SysLib_DelayUs(20);
    pd->switch_ctrl_09 = PDSS_SWITCH_CTRL_09_DEFAULT;
    Cy_SysLib_DelayUs(20);
    pd->switch_ctrl_08 = PDSS_SWITCH_CTRL_08_DEFAULT;
    Cy_SysLib_DelayUs(20);
    pd->switch_ctrl_07 = PDSS_SWITCH_CTRL_07_DEFAULT;

    /* Disable output isolation control. */
    pd->ngdo_p5c40_ctrl_0 &= ~(PDSS_NGDO_P5C40_CTRL_0_ISO_N);
#endif /* defined(CY_DEVICE_CCG6DF_CFP) */

#if (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_CCG3PA))

#if !SOFT_START_ENABLE
    if (context->vbusPfetOn)
    {
        /* Disable the pull-down on the FET. */
        pd->pgdo_pd_isnk_cfg &= ~PDSS_PGDO_PD_ISNK_CFG_STRONG_EN;
    }
#endif /* SOFT_START_ENABLE */
    
#if (defined(CY_DEVICE_CCG6) && PDL_VBUS_OCP_ENABLE)
    pd->pgdo_pu_1_cfg |= PDSS_PGDO_PU_1_CFG_PGDO_PU_IN_LV_OFF_VALUE | 
                         PDSS_PGDO_PU_1_CFG_PGDO_PU_EN_LV_OFF_VALUE;

    Cy_SysLib_DelayUs (10);
#endif /* defined(CY_DEVICE) */ 

    context->vbusPfetOn = false;

    /* Disable the FET first. */
    pd->pgdo_pu_1_cfg &= ~(PDSS_PGDO_PU_1_CFG_PGDO_PU_EN_LV_ON_VALUE | PDSS_PGDO_PU_1_CFG_SEL_ON_OFF |
            PDSS_PGDO_PU_1_CFG_AUTO_MODE);
    Cy_SysLib_DelayUs (10);

    /* Disable all auto mode configuration. */
    pd->pgdo_pu_2_cfg  = 0;
    pd->pgdo_pu_1_cfg &= ~(PGDO_PU_1_CFG_AUTO_SEL_MASK | PDSS_PGDO_PU_1_CFG_AUTO_MODE);
    Cy_SysLib_DelayUs (10);

    /* Program PGDO back to its default state. */
    pd->pgdo_pu_1_cfg &= ~(PDSS_PGDO_PU_1_CFG_SEL_ON_OFF
            | PDSS_PGDO_PU_1_CFG_PGDO_PU_EN_LV_ON_VALUE | PDSS_PGDO_PU_1_CFG_PGDO_PU_EN_LV_OFF_VALUE
            | PDSS_PGDO_PU_1_CFG_PGDO_PU_IN_LV_ON_VALUE | PDSS_PGDO_PU_1_CFG_PGDO_PU_IN_LV_OFF_VALUE);

    /*
     * The edge detector may have triggered later than previous fault.
     * In this case, this needs to be cleared.
     */
    Cy_USBPD_Vbus_GdrvRstEdgeDet(context, true);
#endif /* (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_CCG3PA)) */

#if defined(CY_DEVICE_CCG3)
    uint32_t regval = pd->ngdo_ctrl_0;
    uint32_t state;

    state = Cy_SysLib_EnterCriticalSection ();

    /* Turn-off the first FET. */
    if (!turnOffSeq)
    {
        regval &= ~VBUS_P_NGDO_EN_LV_0;
        regval |= VBUS_P_PLDN_EN_LV_0;
    }
    else
    {
        regval &= ~VBUS_P_NGDO_EN_LV_1;
        regval |= VBUS_P_PLDN_EN_LV_1;
    }

    pd->ngdo_ctrl_0 = regval;

    /* Turn-off the second FET after a delay. */
    Cy_SysLib_DelayUs (10);

    regval &= ~(VBUS_P_NGDO_EN_LV_0 | VBUS_P_NGDO_EN_LV_1);
    regval |= (VBUS_P_PLDN_EN_LV_0 | VBUS_P_PLDN_EN_LV_1);
    pd->ngdo_ctrl_0 = regval;

    /* Disable auto mode and reset the edge detector. */
    pd->ngdo_ctrl_p &= ~(PDSS_NGDO_CTRL_P_AUTO_MODE | PDSS_NGDO_CTRL_P_SEL_SWAP_VBUS_LESS_5);
    Cy_USBPD_Vbus_GdrvRstEdgeDet (context, true);

    context->vbusPfetOn = false;
    Cy_SysLib_ExitCriticalSection (state);
#endif /* defined(CY_DEVICE_CCG3) */

#if defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)
    context->vbusPfetOn = false;

    /*
     * The edge detector may have triggered later than previous fault.
     * In this case, this needs to be cleared.
     */
    Cy_USBPD_Vbus_GdrvRstEdgeDet(context, true);

    pd->bb_ngdo_0_gdrv_en_ctrl = PDSS_BB_NGDO_0_GDRV_EN_CTRL_DEFAULT;
    Cy_SysLib_DelayUs(50);
    pd->ngdo_ctrl &= ~(PDSS_NGDO_CTRL_NGDO_CP_EN);
    Cy_SysLib_DelayUs(50);
    pd->ngdo_ctrl &= ~(PDSS_NGDO_CTRL_NGDO_ISO_N | PDSS_NGDO_CTRL_NGDO_EN_LV);

#if CY_USE_CONFIG_TABLE
    uint8_t gdrv_slew_rate = pd_get_ptr_pwr_tbl(context)->src_gate_drv_str;
#else
    uint8_t gdrv_slew_rate = context->usbpdConfig->buckBoostConfig->src_gate_drv_str;
#endif

    /* Reset Vbus Source gate driver slew configuration to config table value */
    switch(gdrv_slew_rate)
    {
        case 0:
#if PMG1B1_USB_CHARGER
            CY_USBPD_REG_FIELD_UPDATE(pd->ngdo_ctrl, PDSS_NGDO_CTRL_NGDO_SLEW_CTRL, (uint32_t)0x09u);
#else /* !PMG1B1_USB_CHARGER */
            CY_USBPD_REG_FIELD_UPDATE(pd->ngdo_ctrl, PDSS_NGDO_CTRL_NGDO_SLEW_CTRL, (uint32_t)0x03u);
#endif /* PMG1B1_USB_CHARGER */
            break;
        case 1:
            CY_USBPD_REG_FIELD_UPDATE(pd->ngdo_ctrl, PDSS_NGDO_CTRL_NGDO_SLEW_CTRL, (uint32_t)0x01Eu);
            break;
        case 2:
            CY_USBPD_REG_FIELD_UPDATE(pd->ngdo_ctrl, PDSS_NGDO_CTRL_NGDO_SLEW_CTRL, (uint32_t)0x3Fu);
            break;
        default:
            /* No statement */
            break;
    }

#endif /* defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1) */
#else
    CY_UNUSED_PARAMETER(context);
    CY_UNUSED_PARAMETER(turnOffSeq);
#endif /*  ((!CY_PD_SINK_ONLY) || (PMG1B1_USB_CHARGER)) */
}

/*******************************************************************************
* Function Name: Cy_USBPD_Vbus_GdrvCfetOn
****************************************************************************//**
*
* Turn on consumer FET using the internal gate driver or dedicated GPIO.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \param turnOnSeq
* Turn On sequence On PMG1S2, this bit selects which FET turns on first.
*  - 0: FET 0 turns on first.
*  - 1: FET 1 turns on first.
*
*******************************************************************************/
void Cy_USBPD_Vbus_GdrvCfetOn(cy_stc_usbpd_context_t *context, bool turnOnSeq)
{
#if (PSVP_FPGA_ENABLE)
    /* No implementation necessary on PSVP. */
    CY_UNUSED_PARAMETER(context);
    CY_UNUSED_PARAMETER(turnOnSeq);
#else
#if defined(CY_DEVICE_CCG6)
    PPDSS_REGS_T pd = context->base;
    uint32_t regVal;
    uint32_t mask;
    (void)turnOnSeq;

#if (!CY_PD_SINK_ONLY)
    /* We can turn source FET OFF when turning sink FET ON. */
    Cy_USBPD_Vbus_GdrvPfetOff(context, turnOnSeq);
#endif /* (!CY_PD_SINK_ONLY) */

    /* Reset the edge detector. */
    Cy_USBPD_Vbus_GdrvRstEdgeDet(context, false);

    mask = Cy_SysLib_EnterCriticalSection ();

    /* Make sure the PD port is idle before enabling the FET. */
    while ((pd->status & (PDSS_STATUS_RX_BUSY | PDSS_STATUS_CC_DATA_VALID)) != 0U)
    {

    }

#if !SOFT_START_ENABLE
    /* Enable the pull-down for the FET. */
    pd->pgdo_pd_isnk_cfg = PDSS_PGDO_PD_ISNK_CFG_DEFAULT;
#endif /* SOFT_START_ENABLE */

    context->vbusCfetOn = true;

    /* Turn on the fet by setting ENABLE_ON bit. */
    regVal = pd->pgdo_1_cfg;
    regVal |= (PDSS_PGDO_1_CFG_SEL_ON_OFF | PDSS_PGDO_1_CFG_PGDO_EN_LV_ON_VALUE);
    pd->pgdo_1_cfg |= regVal;

    Cy_SysLib_ExitCriticalSection (mask);

#elif defined(CY_DEVICE_CCG3PA)

    PPDSS_REGS_T pd = context->base;
    uint32_t regVal;

#if !SOFT_START_ENABLE
    /* Enable strong pull-down for turning the FET ON */
    pd->pgdo_pd_isnk_cfg |= PDSS_PGDO_PD_ISNK_CFG_STRONG_EN;
#endif /* SOFT_START_ENABLE */

    context->vbusCfetOn = true;
    
    /*
     * The edge detector may have triggered later than previous fault.
     * In this case, this needs to be cleared before the FET can be
     * turned ON.
     */
    Cy_USBPD_Vbus_GdrvRstEdgeDet(context, true);

    if(turnOnSeq)
    {
        /* Turn on the fet by setting ENABLE_ON bit and clearing IN_ON bit. */
        regVal = pd->pgdo_pu_1_cfg;
        regVal &= ~PDSS_PGDO_PU_1_CFG_PGDO_PU_IN_LV_ON_VALUE;
        regVal |= (PDSS_PGDO_PU_1_CFG_SEL_ON_OFF | PDSS_PGDO_PU_1_CFG_PGDO_PU_EN_LV_ON_VALUE);
        pd->pgdo_pu_1_cfg = regVal;
    }
    else
    {
        regVal = pd->pgdo_1_cfg;
        /* Turn on the fet by setting ENABLE_ON bit. */
        regVal |= (PDSS_PGDO_1_CFG_SEL_ON_OFF | PDSS_PGDO_1_CFG_PGDO_EN_LV_ON_VALUE);
        pd->pgdo_1_cfg = regVal;
    }

#elif defined(CY_DEVICE_CCG3)

    PPDSS_REGS_T pd = context->base;
    uint32_t regval;
    uint32_t mask;

#if (!CY_PD_SINK_ONLY)
    /* Disable the provider FET before enabling consumer FET. */
    Cy_USBPD_Vbus_GdrvPfetOff(context, turnOnSeq);
#endif /* (!CY_PD_SINK_ONLY) */

    mask = Cy_SysLib_EnterCriticalSection();

    regval = pd->ngdo_ctrl_0;

    /* Turn the first FET ON. */
    if (!turnOnSeq)
    {
        regval &= ~VBUS_C_PLDN_EN_LV_0;
        regval |= VBUS_C_NGDO_EN_LV_0;
    }
    else
    {
        regval &= ~VBUS_C_PLDN_EN_LV_1;
        regval |= VBUS_C_NGDO_EN_LV_1;
    }

    pd->ngdo_ctrl_0 = regval;

    /* Turn the second FET ON after a delay. */
    Cy_SysLib_DelayUs (10);

    regval &= ~(VBUS_C_PLDN_EN_LV_0 | VBUS_C_PLDN_EN_LV_1);
    regval |= VBUS_C_NGDO_EN_LV_0 | VBUS_C_NGDO_EN_LV_1;
    pd->ngdo_ctrl_0 = regval;

    /* Reset the edge detector. */
    Cy_USBPD_Vbus_GdrvRstEdgeDet(context, false);

    context->vbusCfetOn = true;

    Cy_SysLib_ExitCriticalSection (mask);

#else

    CY_UNUSED_PARAMETER(context);
    CY_UNUSED_PARAMETER(turnOnSeq);

#endif /* CY_DEVICE */
#endif /* PSVP_FPGA_ENABLE */
}

/*******************************************************************************
* Function Name: Cy_USBPD_Vbus_GdrvCfetOff
****************************************************************************//**
*
* Turn OFF consumer FET using the internal gate driver or dedicated GPIO.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \param turnOffSeq
* Turn Off sequence On PMG1S2, this bit selects which FET turns on first.
*  - 0: FET 0 turns on first.
*  - 1: FET 1 turns on first.
*
*******************************************************************************/
void Cy_USBPD_Vbus_GdrvCfetOff(cy_stc_usbpd_context_t *context, bool turnOffSeq)
{
#if (PSVP_FPGA_ENABLE)
    /* No implementation necessary on PSVP. */
    CY_UNUSED_PARAMETER(context);
    CY_UNUSED_PARAMETER(turnOffSeq);
#else
#if defined(CY_DEVICE_CCG6)
    PPDSS_REGS_T pd = context->base;

    /* Legacy parameter - Not used. */
    (void)turnOffSeq;

    /* Disable all auto mode configuration. */
    pd->pgdo_2_cfg  = 0;
    pd->pgdo_1_cfg &= ~(PGDO_1_CFG_AUTO_SEL_MASK | PDSS_PGDO_1_CFG_AUTO_MODE);

    /* Program PGDO back to its default (OFF) state. */
    pd->pgdo_1_cfg &= ~(PDSS_PGDO_1_CFG_SEL_ON_OFF |
            PDSS_PGDO_1_CFG_PGDO_EN_LV_ON_VALUE | PDSS_PGDO_1_CFG_PGDO_EN_LV_OFF_VALUE);

    context->vbusCfetOn = false;

#elif defined(CY_DEVICE_CCG3PA)

    PPDSS_REGS_T pd = context->base;
    uint32_t regVal;

    if(turnOffSeq)
    {
        regVal = pd->pgdo_pu_1_cfg;
        regVal &= ~(PDSS_PGDO_PU_1_CFG_SEL_ON_OFF
                    | PDSS_PGDO_PU_1_CFG_PGDO_PU_EN_LV_ON_VALUE | PDSS_PGDO_PU_1_CFG_PGDO_PU_EN_LV_OFF_VALUE
                    | PDSS_PGDO_PU_1_CFG_PGDO_PU_IN_LV_ON_VALUE | PDSS_PGDO_PU_1_CFG_PGDO_PU_IN_LV_OFF_VALUE);
        regVal |= PDSS_PGDO_PU_1_CFG_PGDO_PU_IN_LV_OFF_VALUE | PDSS_PGDO_PU_1_CFG_PGDO_PU_EN_LV_OFF_VALUE;
        pd->pgdo_pu_1_cfg = regVal;
    }
    else
    {
        /* Program PGDO_PU back to its default (OFF) state. */
        pd->pgdo_1_cfg &= ~(PDSS_PGDO_1_CFG_SEL_ON_OFF
            | PDSS_PGDO_1_CFG_PGDO_EN_LV_ON_VALUE | PDSS_PGDO_1_CFG_PGDO_EN_LV_OFF_VALUE);
    }
    /*
     * The edge detector may have triggered later than previous fault.
     * In this case, this needs to be cleared.
     */
    Cy_USBPD_Vbus_GdrvRstEdgeDet(context, true);

    /* Make sure the soft start of the FET is disabled. */
    if (context->vbusCfetOn)
    {
        pd->pgdo_pd_isnk_cfg |= PDSS_PGDO_PD_ISNK_CFG_STRONG_EN;
        context->vbusCfetOn = false;
    }

#elif defined(CY_DEVICE_CCG3)

    PPDSS_REGS_T pd = context->base;
    uint32_t regval;
    uint32_t mask;

    mask = Cy_SysLib_EnterCriticalSection();

    regval = pd->ngdo_ctrl_0;

    /* Turn OFF the first FET. */
    if (!turnOffSeq)
    {
        regval &= ~VBUS_C_NGDO_EN_LV_0;
        regval |= VBUS_C_PLDN_EN_LV_0;
    }
    else
    {
        regval &= ~VBUS_C_NGDO_EN_LV_1;
        regval |= VBUS_C_PLDN_EN_LV_1;
    }

    pd->ngdo_ctrl_0 = regval;

    /* Turn the second FET off after a delay. */
    Cy_SysLib_DelayUs(10);

    regval &= ~(VBUS_C_NGDO_EN_LV_0 | VBUS_C_NGDO_EN_LV_1);
    regval |= VBUS_C_PLDN_EN_LV_0 | VBUS_C_PLDN_EN_LV_1;
    pd->ngdo_ctrl_0 = regval;

    /* Disable auto mode and reset the edge detector. */
    pd->ngdo_ctrl_c &= ~(PDSS_NGDO_CTRL_C_AUTO_MODE | PDSS_NGDO_CTRL_C_SEL_SWAP_VBUS_LESS_5);
    Cy_USBPD_Vbus_GdrvRstEdgeDet(context, false);

    context->vbusCfetOn = false;

    Cy_SysLib_ExitCriticalSection(mask);

#else

    CY_UNUSED_PARAMETER(context);
    CY_UNUSED_PARAMETER(turnOffSeq);

#endif /* CY_DEVICE */
#endif /* PSVP_FPGA_ENABLE */
}

/*******************************************************************************
* Function Name: Cy_USBPD_Vbus_NgdoOn
****************************************************************************//**
*
* Turns on the FET using the internal NGDO. This API is only applicable to PMG1S3.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \param pfet
* Flag indicating whether the NGDO is connected to Provider FET
*  - 0: Connected to Consumer FET.
*  - 1: Connected to Provider FET.
*
*******************************************************************************/
void Cy_USBPD_Vbus_NgdoOn (cy_stc_usbpd_context_t *context, bool pfet)
{
#if defined(CY_DEVICE_PMG1S3)
    PPDSS_REGS_T pd = context->base;

    pd->v2_ngdo_0_ctrl |= (PDSS_V2_NGDO_0_CTRL_NGDO_ISO_N | PDSS_V2_NGDO_0_CTRL_NGDO_EN_LV);
    Cy_SysLib_DelayUs(20);
    pd->v2_ngdo_0_ctrl |= PDSS_V2_NGDO_0_CTRL_NGDO_CP_EN;
    Cy_SysLib_DelayUs(20);
    pd->v2_ngdo_0_ctrl |= PDSS_V2_NGDO_0_CTRL_NGDO_GRV_EN;
    
    if(pfet == true)
    {
        context->vbusPfetOn = true;
    }
    else
    {
        context->vbusCfetOn = true;
    }
#else
    CY_UNUSED_PARAMETER(context);
    CY_UNUSED_PARAMETER(pfet);
#endif /* defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP) */
}

/*******************************************************************************
* Function Name: Cy_USBPD_Vbus_NgdoOff
****************************************************************************//**
*
* Turns off the FET using the internal NGDO. This API is only applicable to PMG1S3.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \param pfet
* Flag indicating whether the NGDO is connected to Provider FET
*  - 0: Connected to Consumer FET.
*  - 1: Connected to Provider FET.
*
*******************************************************************************/
void Cy_USBPD_Vbus_NgdoOff (cy_stc_usbpd_context_t *context, bool pfet)
{
#if defined(CY_DEVICE_PMG1S3)
    PPDSS_REGS_T pd = context->base;

    if(pfet == true)
    {
        context->vbusPfetOn = false;
    }
    else
    {
        context->vbusCfetOn = false;
    }
    pd->v2_ngdo_0_ctrl &= ~PDSS_V2_NGDO_0_CTRL_NGDO_GRV_EN;
    Cy_SysLib_DelayUs(20);
    pd->v2_ngdo_0_ctrl &= ~PDSS_V2_NGDO_0_CTRL_NGDO_CP_EN;
    Cy_SysLib_DelayUs(20);    
    pd->v2_ngdo_0_ctrl &= ~(PDSS_V2_NGDO_0_CTRL_NGDO_ISO_N | PDSS_V2_NGDO_0_CTRL_NGDO_EN_LV);
    Cy_SysLib_DelayUs(20);
    pd->v2_ngdo_0_ctrl&= ~(PDSS_V2_NGDO_0_CTRL_NGDO_FAULT_RCP_EN | PDSS_V2_NGDO_0_CTRL_NGDO_FAULT_SCP_EN | PDSS_V2_NGDO_0_CTRL_NGDO_FAULT_VBUS_OV_EN);
#else
    CY_UNUSED_PARAMETER(context);
    CY_UNUSED_PARAMETER(pfet);
#endif /* defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP) */
}

/** Vbus discharge drive strength at high voltages for PMG1S1. */
#define DISCHG_DRIVE_STRENGTH_VBUS_HI_REVA      (0x03UL)

/*******************************************************************************
* Function Name: Cy_USBPD_Vbus_DischargeOn
****************************************************************************//**
*
* Turn on the internal VBus discharge path.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
*******************************************************************************/
void Cy_USBPD_Vbus_DischargeOn(cy_stc_usbpd_context_t *context)
{
#if (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))

    PPDSS_REGS_T pd = context->base;

#if VBUS_SLOW_DISCHARGE_EN
    if (context->vbusSlowDischarge.vbus_is_slow_dischargeOn == 1u)
    {
        /* Last Discharge ON request ongoing. We will ignore this request */
    }
    else
    {
#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
#if VBUS_IN_DISCHARGE_EN
        if((true == Cy_USBPD_BB_IsEnabled(context)) && (false == Cy_USBPD_BB_IsReady(context)))
        {
            /*
             * If we get a discharge call while soft start is ongoing
             * then we will not handle the discharge since it is already being done in
             * the soft start sequence.
             */
            context->vbusInDischargeEn = false;
        }
        else
        {
            /* Allow the discharge request to go through if there is no soft start sequence ongoing */
            context->vbusInDischargeEn = true;
        }
#endif /* VBUS_IN_DISCHARGE_EN */
#endif /* (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1) */

        /* Set the discharge ongoing flag */
        context->vbusSlowDischarge.vbus_is_slow_dischargeOn = 1u;

        if (context->vbusSlowDischarge.vbus_is_slow_dischargeOff == 1u)
        {
            /* Last Discharge OFF request ongoing. We will stop this and start
             * processing the current request */
            context->timerStopcbk(context, (cy_en_usbpd_timer_id_t)CY_USBPD_VBUS_DISCHARGE_SCHEDULE_TIMER);
            /* We will not be disabling the discharge flag here. */
        }

        /* Obtain the current drive strength values for VBUS_IN and VBUS_C.
         * In ideal case this will be 1. This might be of higher value if
         * the last discharge OFF was not completed when this discharge ON
         * request came.
         */
        context->vbusSlowDischarge.vbus_discharge_ds0 = (uint8_t)(pd->dischg_shv_ctrl[0] & PDSS_DISCHG_SHV_CTRL_DISCHG_DS_MASK)
                        >> PDSS_DISCHG_SHV_CTRL_DISCHG_DS_POS;
        context->vbusSlowDischarge.vbus_discharge_ds1 = (uint8_t)(pd->dischg_shv_ctrl[1] & PDSS_DISCHG_SHV_CTRL_DISCHG_DS_MASK)
                        >> PDSS_DISCHG_SHV_CTRL_DISCHG_DS_POS;

        if (context->vbusSlowDischarge.vbus_is_slow_dischargeOff == 0u)
        {
            /*
             * Last Discharge completed completely before this request was
             * made. In thia case we should start discharging with the
             * minimum configured discharge strength.
             * We decrease the strength to the next lower power of 2 or 0,
             * whichever is lower here. In vbus_slow_discharge_on_process()
             * we start with the next power of 2 value. By this approach, there
             * is no skipping of minimum discharge strength configured for this
             * part.
             */
            if ((context->vbusSlowDischarge.vbus_discharge_ds0 >> 1) != 0u)
            {
                context->vbusSlowDischarge.vbus_discharge_ds0 = context->vbusSlowDischarge.vbus_discharge_ds0 >> 1;
            }
            else
            {
                context->vbusSlowDischarge.vbus_discharge_ds0 = 0u;
            }
        }
        else
        {
            /* Disable the discharge flag. We do not decrease the discharge
             * strength value, as we want to start from the next discharge
             * strength value in vbus_slow_discharge_on_process().
             */
            context->vbusSlowDischarge.vbus_is_slow_dischargeOff = 0u;
        }
        /* Call the CB directly 1st time */
        context->vbusSlowDischargecbk(context->pdStackContext);
    }
#else
#if !PMG1_FLIPPED_FET_CTRL
    /* This is VBUS_C discharge path. */
    pd->dischg_shv_ctrl[0] |= (PDSS_DISCHG_SHV_CTRL_DISCHG_EN | PDSS_DISCHG_SHV_CTRL_DISCHG_EN_CFG);
#else /* PMG1_FLIPPED_FET_CTRL */
    pd->dischg_shv_ctrl[1] |= (PDSS_DISCHG_SHV_CTRL_DISCHG_EN | PDSS_DISCHG_SHV_CTRL_DISCHG_EN_CFG);
#endif /* PMG1_FLIPPED_FET_CTRL */

#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
#if VBUS_IN_DISCHARGE_EN
    if((true == Cy_USBPD_BB_IsEnabled(context)) && (false == Cy_USBPD_BB_IsReady(context)))
    {
        /*
         * If we get a discharge call while soft start is ongoing
         * then we will not handle the discharge since it is already being done in
         * the soft start sequence.
         */
        context->vbusInDischargeEn = false;
    }
    else
    {
        context->vbusInDischargeEn = true;
        /* Allow the discharge request to go through if there is no soft start sequence ongoing */
        Cy_USBPD_VbusIn_DischargeOn(context);
    }
#endif /* VBUS_IN_DISCHARGE_EN */
#endif /* (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) */
#endif /* !VBUS_SLOW_DISCHARGE_EN */

#elif (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP))
    PPDSS_REGS_T pd = context->base;
    uint32_t regVal;

    /* Enable the VBus discharge circuit. */
    regVal = pd->dischg_shv_ctrl;
    regVal &= ~PDSS_DISCHG_SHV_CTRL_DISCHG_DS_MASK;
    regVal |= (PDSS_DISCHG_SHV_CTRL_DISCHG_EN | PDSS_DISCHG_SHV_CTRL_DISCHG_EN_CFG |
              (DISCHG_DRIVE_STRENGTH_VBUS_HI_REVA << PDSS_DISCHG_SHV_CTRL_DISCHG_DS_POS));
    pd->dischg_shv_ctrl = regVal;

#elif (defined(CY_DEVICE_CCG3))

    PPDSS_REGS_T pd = context->base;
    pd->vbus_ctrl |= PDSS_VBUS_CTRL_DISCHG_EN;

#endif /* CY_DEVICE */

#if (PSVP_FPGA_ENABLE)
#if (!defined(CY_DEVICE_CCG6DF_CFP))
    ctrl_inf_vbus_discharge_on();
#endif /* (!defined(CY_DEVICE_CCG6DF_CFP)) */
#endif /* PSVP_FPGA_ENABLE */
}

/*******************************************************************************
* Function Name: Cy_USBPD_Vbus_DischargeOff
****************************************************************************//**
*
* Turn off the internal VBus discharge path.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
*******************************************************************************/
void Cy_USBPD_Vbus_DischargeOff(cy_stc_usbpd_context_t *context)
{
#if (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
    PPDSS_REGS_T pd = context->base;

#if VBUS_SLOW_DISCHARGE_EN

    uint8_t count = 0;
    uint8_t reg_val_0;
    uint8_t reg_val_1;

    if (context->vbusSlowDischarge.vbus_is_slow_dischargeOff == 1u)
    {
        /* Last Discharge OFF request ongoing. We will ignore this request */
    }
    else
    {
        /* Set the discharge off ongoing flag */
        context->vbusSlowDischarge.vbus_is_slow_dischargeOff = 1u;

        if (context->vbusSlowDischarge.vbus_is_slow_dischargeOn == 1u)
        {
            /* Last Discharge ON request ongoing. We will stop this and start
             * processing the current request */
            context->timerStopcbk(context, (cy_en_usbpd_timer_id_t)CY_USBPD_VBUS_DISCHARGE_SCHEDULE_TIMER);
            /* Disable the discharge */
            context->vbusSlowDischarge.vbus_is_slow_dischargeOn = 0u;
        }

        /* Obtain the current drive strength values for VBUS_IN and VBUS_C.
         * In ideal case this will be maximum allowed. This might be of lesser
         * value if the last discharge ON was not completed when this discharge
         * OFF request came.
         */
        context->vbusSlowDischarge.vbus_discharge_ds0 = (uint8_t)(pd->dischg_shv_ctrl[0] & PDSS_DISCHG_SHV_CTRL_DISCHG_DS_MASK)
                        >> PDSS_DISCHG_SHV_CTRL_DISCHG_DS_POS;
        context->vbusSlowDischarge.vbus_discharge_ds1 = (uint8_t)(pd->dischg_shv_ctrl[1] & PDSS_DISCHG_SHV_CTRL_DISCHG_DS_MASK)
                        >> PDSS_DISCHG_SHV_CTRL_DISCHG_DS_POS;

        /* Keep a copy locally. Will be used later for comparison */
        reg_val_0 = context->vbusSlowDischarge.vbus_discharge_ds0;
        reg_val_1 = context->vbusSlowDischarge.vbus_discharge_ds1;

        /* Maximum discharge strength need not be power of 2. We will go to the
         * next higher power of 2. The value will be reduced in CB context.
         */
        while ((context->vbusSlowDischarge.vbus_discharge_ds0 >> 1) != 0u)
        {
            context->vbusSlowDischarge.vbus_discharge_ds0 = context->vbusSlowDischarge.vbus_discharge_ds0 >> 1;
            count = count + 1u;
        }
        context->vbusSlowDischarge.vbus_discharge_ds0 = (uint8_t)(1u << (count + 1u));

        count = 0u;

        while ((context->vbusSlowDischarge.vbus_discharge_ds1 >> 1) != 0u)
        {
            context->vbusSlowDischarge.vbus_discharge_ds1  = context->vbusSlowDischarge.vbus_discharge_ds1 >> 1;
            count = count + 1u;
        }
        context->vbusSlowDischarge.vbus_discharge_ds1 = (uint8_t)(1u << (count + 1u));

        /*
         * For power of 2 discharge strength, we should not use the above
         * calculated value. We will restore the value to the original
         */
        if (reg_val_0 == (context->vbusSlowDischarge.vbus_discharge_ds0 >> 1))
        {
            context->vbusSlowDischarge.vbus_discharge_ds0 = reg_val_0;
        }
        if (reg_val_1 == (context->vbusSlowDischarge.vbus_discharge_ds1 >> 1))
        {
            context->vbusSlowDischarge.vbus_discharge_ds1 = reg_val_1;
        }

        /* Call the CB directly 1st time */
        context->vbusSlowDischargecbk(context->pdStackContext);
    }

#else
#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
    pd->dischg_shv_ctrl[0] = ((pd->dischg_shv_ctrl[0] & ~PDSS_DISCHG_SHV_CTRL_DISCHG_EN) |
        PDSS_DISCHG_SHV_CTRL_DISCHG_EN_CFG);
#if VBUS_IN_DISCHARGE_EN
    if( context->vbusInDischargeEn == true)
    {
         Cy_USBPD_VbusIn_DischargeOff(context);
         context->vbusInDischargeEn = false;
    }
#endif /* VBUS_IN_DISCHARGE_EN */

#else /* !(defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) */
#if !PMG1_FLIPPED_FET_CTRL
    pd->dischg_shv_ctrl[0] = ((PDSS->dischg_shv_ctrl[0] & ~PDSS_DISCHG_SHV_CTRL_DISCHG_EN) |
        PDSS_DISCHG_SHV_CTRL_DISCHG_EN_CFG);
#else /* PMG1_FLIPPED_FET_CTRL */
    pd->dischg_shv_ctrl[1] = ((PDSS->dischg_shv_ctrl[1] & ~PDSS_DISCHG_SHV_CTRL_DISCHG_EN) |
        PDSS_DISCHG_SHV_CTRL_DISCHG_EN_CFG);
#endif /* PMG1_FLIPPED_FET_CTRL */
#if VBUS_IN_DISCHARGE_EN
    Cy_USBPD_VbusIn_DischargeOff(context);
#endif /* VBUS_IN_DISCHARGE_EN */

#endif /* !(defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) */
#endif /* !VBUS_SLOW_DISCHARGE_EN */

#elif (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP))

    PPDSS_REGS_T pd = context->base;

    /* Disable the discharge circuit. */
    pd->dischg_shv_ctrl &= ~PDSS_DISCHG_SHV_CTRL_DISCHG_EN;

#elif (defined(CY_DEVICE_CCG3))

    PPDSS_REGS_T pd = context->base;
    pd->vbus_ctrl &= ~PDSS_VBUS_CTRL_DISCHG_EN;

#endif /* CY_DEVICE */

#if PSVP_FPGA_ENABLE
#if (!defined(CY_DEVICE_CCG6DF_CFP))
    ctrl_inf_vbus_discharge_off();
#endif /* (!defined(CY_DEVICE_CCG6DF_CFP)) */
#endif /* PSVP_FPGA_ENABLE */
}

/*******************************************************************************
* Function Name: Cy_USBPD_VbusIn_DischargeOn
****************************************************************************//**
*
* Turn on the internal VBUS_IN discharge path.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
*******************************************************************************/
void Cy_USBPD_VbusIn_DischargeOn(cy_stc_usbpd_context_t *context)
{
#if VBUS_IN_DISCHARGE_EN
    PPDSS_REGS_T pd = context->base;

#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
/* CCG7D/7S is VIN powered, so non comparator based VBUS_IN discharge */
    pd->dischg_shv_ctrl[1] |= (PDSS_DISCHG_SHV_CTRL_DISCHG_EN | PDSS_DISCHG_SHV_CTRL_DISCHG_EN_CFG);
#else
#if !PMG1_FLIPPED_FET_CTRL
#if VBUS_IN_DISCH_BELOW_5V_EN
    pd->dischg_shv_ctrl[1] |= (PDSS_DISCHG_SHV_CTRL_DISCHG_EN | PDSS_DISCHG_SHV_CTRL_DISCHG_EN_CFG);
#else /* !VBUS_IN_DISCH_BELOW_5V_EN */
    /* Only discharge to 5V. */
    pd->dischg_shv_ctrl[1] &= ~(PDSS_DISCHG_SHV_CTRL_DISCHG_EN_CFG);
    /* Enable the comparator. */
    pd->comp_ctrl[CY_USBPD_VBUS_COMP_ID_VBUS_DISCHARGE] &= ~PDSS_COMP_CTRL_COMP_PD;
#endif /* VBUS_IN_DISCH_BELOW_5V_EN */
#else /* PMG1_FLIPPED_FET_CTRL */
    pd->dischg_shv_ctrl[0] |= (PDSS_DISCHG_SHV_CTRL_DISCHG_EN | PDSS_DISCHG_SHV_CTRL_DISCHG_EN_CFG);
#endif /* PMG1_FLIPPED_FET_CTRL */
#endif /* defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1) */
#else /* VBUS_IN_DISCHARGE_EN */
    CY_UNUSED_PARAMETER(context);
#endif /* VBUS_IN_DISCHARGE_EN */
}


/*******************************************************************************
* Function Name: Cy_USBPD_VbusIn_DischargeOff
****************************************************************************//**
*
* Turn off the internal VBUS_IN discharge path.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
*******************************************************************************/
void Cy_USBPD_VbusIn_DischargeOff(cy_stc_usbpd_context_t *context)
{
#if VBUS_IN_DISCHARGE_EN
    PPDSS_REGS_T pd = context->base;
#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
    /* CCG7D is VIN powered, so non comparator based VBUS_IN discharge */
    pd->dischg_shv_ctrl[1] = ((pd->dischg_shv_ctrl[1] & ~PDSS_DISCHG_SHV_CTRL_DISCHG_EN) | PDSS_DISCHG_SHV_CTRL_DISCHG_EN_CFG);
#else
#if !PMG1_FLIPPED_FET_CTRL
#if !VBUS_IN_DISCH_BELOW_5V_EN
    pd->comp_ctrl[CY_USBPD_VBUS_COMP_ID_VBUS_DISCHARGE] |= PDSS_COMP_CTRL_COMP_PD;
#endif /* !VBUS_IN_DISCH_BELOW_5V_EN */
    pd->dischg_shv_ctrl[1] = ((pd->dischg_shv_ctrl[1] & ~PDSS_DISCHG_SHV_CTRL_DISCHG_EN) |
        PDSS_DISCHG_SHV_CTRL_DISCHG_EN_CFG);
#else /* PMG1_FLIPPED_FET_CTRL */
    pd->dischg_shv_ctrl[0] = ((pd->dischg_shv_ctrl[0] & ~PDSS_DISCHG_SHV_CTRL_DISCHG_EN) |
        PDSS_DISCHG_SHV_CTRL_DISCHG_EN_CFG);
#endif /* PMG1_FLIPPED_FET_CTRL */
#endif /* defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1) */
#else
    CY_UNUSED_PARAMETER(context);
#endif /* VBUS_IN_DISCHARGE_EN */
}

/*******************************************************************************
* Function Name: Cy_USBPD_Fault_FetAutoModeEnable
****************************************************************************//**
*
* Enable automatic hardware control on a gate driver due to a specified
* comparator and output filter. Does not affect automatic control of the gate
* driver by other comparators of filters.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \param pctrl
* Flag indicating the type of gate driver to be controlled, true for
* P_CTRL and false for C_CTRL.
*
* \param filterIndex
* \ref cy_en_usbpd_vbus_filter_id_t enumerated type for various faults
*
*******************************************************************************/
void Cy_USBPD_Fault_FetAutoModeEnable(cy_stc_usbpd_context_t *context, bool pctrl, cy_en_usbpd_vbus_filter_id_t filterIndex)
{
#if defined(CY_DEVICE_SERIES_WLC1)
    CY_UNUSED_PARAMETER(context);
    CY_UNUSED_PARAMETER(pctrl);
    CY_UNUSED_PARAMETER(filterIndex);
    /* FET control lines are overridden in WiCG1 */
    return;
#endif /* defined(CY_DEVICE_SERIES_WLC1) */

#if !defined(CY_DEVICE_SERIES_WLC1)
#if ((defined(CY_DEVICE_CCG3PA)) || (defined(CY_DEVICE_CCG6)) || (defined(CY_DEVICE_PMG1S3)) || (defined(CY_DEVICE_CCG6DF_CFP)) || (defined(CY_DEVICE_CCG7D)) || (defined(CY_DEVICE_CCG7S)))
    PPDSS_REGS_T pd = context->base;

#if defined(CY_DEVICE_CCG3PA)
    uint32_t regVal;
    /* Provider FET. */
    if (pctrl)
    {
        regVal = pd->pgdo_pu_1_cfg;
        /* Enable auto mode. */
        regVal |= PDSS_PGDO_PU_1_CFG_AUTO_MODE;
        /* Program the off value to turn off the PFET. */
        regVal &= ~PDSS_PGDO_PU_1_CFG_PGDO_PU_EN_LV_OFF_VALUE;
        regVal |= PDSS_PGDO_PU_1_CFG_PGDO_PU_IN_LV_OFF_VALUE;
        pd->pgdo_pu_1_cfg = regVal;
        /* Select source. */
        pd->pgdo_pu_2_cfg |= 1UL << (uint8_t)filterIndex;
    }
    /* Consumer FET. */
    else
    {
        regVal = pd->pgdo_1_cfg;
        /* Enable auto mode. */
        regVal |= PDSS_PGDO_1_CFG_AUTO_MODE;
        /* Program the off value to turn off the PFET. */
        regVal &= ~PDSS_PGDO_1_CFG_PGDO_EN_LV_OFF_VALUE;
        pd->pgdo_1_cfg = regVal;
        /* Select source. */
        pd->pgdo_2_cfg |= 1UL << (uint8_t)filterIndex;
    }
#elif defined (CY_DEVICE_CCG6)
    uint32_t regVal;
    /* Provider FET. */
    if (pctrl)
    {
        /* Use PGDO_PU_1_CFG register for Provider FET */
        regVal = pd->pgdo_pu_1_cfg;

        /* Enable auto mode. */
        regVal |= PDSS_PGDO_PU_1_CFG_AUTO_MODE;

        /* Program the off value to turn off the PFET. */
        regVal &= ~PDSS_PGDO_PU_1_CFG_PGDO_PU_EN_LV_OFF_VALUE;
        pd->pgdo_pu_1_cfg = regVal;

        if (filterIndex == CY_USBPD_VBUS_FILTER_ID_HSCSA_SCP)
        {
            pd->pgdo_pu_3_cfg |= PDSS_PGDO_PU_3_CFG_PGDO_EN_SCP_LV;
        }
        else if (filterIndex == CY_USBPD_VBUS_FILTER_ID_HSCSA_RCP)
        {
            pd->pgdo_pu_3_cfg |= PDSS_PGDO_PU_3_CFG_PGDO_EN_RCP_LV | PDSS_PGDO_PU_3_CFG_PGDO_EN_VBUS_OV_LV;
        }
        else if (filterIndex == CY_USBPD_VBUS_FILTER_ID_HSCSA_OCP)
        {
            pd->pgdo_pu_1_cfg |= PDSS_PGDO_PU_1_CFG_SEL_CSA_OC;
        }
        else
        {
            pd->pgdo_pu_2_cfg |= 1UL << (uint8_t)filterIndex;
        }
    }
    /* Consumer FET. */
    else
    {
        regVal = pd->pgdo_1_cfg;
        /* Enable auto mode. */
        regVal |= PDSS_PGDO_1_CFG_AUTO_MODE;
        /* Program the off value to turn off the PFET. */
        regVal &= ~PDSS_PGDO_1_CFG_PGDO_EN_LV_OFF_VALUE;
        pd->pgdo_1_cfg = regVal;
        /* Select source. */
        pd->pgdo_2_cfg |= 1UL << (uint8_t)filterIndex;
    }
    
#elif defined(CY_DEVICE_PMG1S3)
    /* Provider FET. */
    if (pctrl)
    {
        if (filterIndex == CY_USBPD_VBUS_FILTER_ID_HSCSA_SCP)
        {
            pd->v2_ngdo_0_ctrl |= (PDSS_V2_NGDO_0_CTRL_NGDO_FAULT_SCP_EN);
        }
        else if (filterIndex == CY_USBPD_VBUS_FILTER_ID_HSCSA_RCP)
        {
            pd->v2_ngdo_0_ctrl |= (PDSS_V2_NGDO_0_CTRL_NGDO_FAULT_RCP_EN);
        }
        else
        {
            /* Do nothing */
        }
    }
    /* Consumer FET. */
    else
    {
        /* Do nothing. */
    }

#elif defined(CY_DEVICE_CCG6DF_CFP)
    /* Provider FET. */
    if (pctrl)
    {
        if (filterIndex == CY_USBPD_VBUS_FILTER_ID_HSCSA_SCP)
        {
            pd->switch_ctrl_06 |= PDSS_SWITCH_CTRL_06_AUTO_MODE | (0x01u << 12u);
            pd->switch_ctrl_07 |= PDSS_SWITCH_CTRL_07_AUTO_MODE | (0x01u << 12u);
            pd->switch_ctrl_08 |= PDSS_SWITCH_CTRL_08_AUTO_MODE | (0x01u << 12u);
            pd->switch_ctrl_09 |= PDSS_SWITCH_CTRL_09_AUTO_MODE | (0x01u << 12u);
        }
        else if (filterIndex == CY_USBPD_VBUS_FILTER_ID_HSCSA_RCP)
        {
            pd->switch_ctrl_06 |= PDSS_SWITCH_CTRL_06_AUTO_MODE | (0x01u << 13u);
            pd->switch_ctrl_07 |= PDSS_SWITCH_CTRL_07_AUTO_MODE | (0x01u << 13u);
            pd->switch_ctrl_08 |= PDSS_SWITCH_CTRL_08_AUTO_MODE | (0x01u << 13u);
            pd->switch_ctrl_09 |= PDSS_SWITCH_CTRL_09_AUTO_MODE | (0x01u << 13u);
        }
        else if (filterIndex == CY_USBPD_VBUS_FILTER_ID_UV)
        {
            pd->switch_ctrl_06 |= PDSS_SWITCH_CTRL_06_AUTO_MODE | (0x01u << 10u);
            pd->switch_ctrl_07 |= PDSS_SWITCH_CTRL_07_AUTO_MODE | (0x01u << 10u);
            pd->switch_ctrl_08 |= PDSS_SWITCH_CTRL_08_AUTO_MODE | (0x01u << 10u);
            pd->switch_ctrl_09 |= PDSS_SWITCH_CTRL_09_AUTO_MODE | (0x01u << 10u);
        }
        else if (filterIndex == CY_USBPD_VBUS_FILTER_ID_OV)
        {
            pd->switch_ctrl_06 |= PDSS_SWITCH_CTRL_06_AUTO_MODE | (0x01u << 11u);
            pd->switch_ctrl_07 |= PDSS_SWITCH_CTRL_07_AUTO_MODE | (0x01u << 11u);
            pd->switch_ctrl_08 |= PDSS_SWITCH_CTRL_08_AUTO_MODE | (0x01u << 11u);
            pd->switch_ctrl_09 |= PDSS_SWITCH_CTRL_09_AUTO_MODE | (0x01u << 11u);
        }
        else
        {
            /* Do nothing */
        }
    }
    /* Consumer FET. */
    else
    {
        /* Do nothing. */
    }

#elif defined(CY_DEVICE_CCG3)

#if (PDL_VBUS_UVP_ENABLE || PDL_VBUS_OVP_ENABLE)
    PPDSS_REGS_T pd = context->base;
    uint32_t regval;

    if (pctrl)
    {
#if PDL_VBUS_UVP_ENABLE
        if (filterIndex == CY_USBPD_VBUS_FILTER_ID_UV)
        {
            regval = pd->ngdo_ctrl_p;

            regval |= PDSS_NGDO_CTRL_P_AUTO_MODE | PDSS_NGDO_CTRL_P_SEL_UV;
            regval |= PDSS_NGDO_CTRL_P_PULLDN_EN_LV_OFF_VALUE_MASK;
            regval &= ~PDSS_NGDO_CTRL_P_EN_LV_OFF_VALUE_MASK;

            pd->ngdo_ctrl_p = regval;

            pd->intr3_cfg_0 = (pd->intr3_cfg_0 & ~PDSS_INTR3_CFG_0_UV_NEG_FILT_SEL_MASK) |
                (0x03 << PDSS_INTR3_CFG_0_UV_NEG_FILT_SEL_POS) |
                PDSS_INTR3_CFG_0_UV_NEG_FILT_EN;
        }
#endif /* PDL_VBUS_UVP_ENABLE */

#if PDL_VBUS_OVP_ENABLE
        if (filterIndex == CY_USBPD_VBUS_FILTER_ID_OV)
        {
            regval = pd->ngdo_ctrl_p;

            regval |= PDSS_NGDO_CTRL_P_AUTO_MODE | PDSS_NGDO_CTRL_P_SEL_OV;
            regval |= PDSS_NGDO_CTRL_P_PULLDN_EN_LV_OFF_VALUE_MASK;
            regval &= ~PDSS_NGDO_CTRL_P_EN_LV_OFF_VALUE_MASK;

            pd->ngdo_ctrl_p = regval;

            pd->intr3_cfg_0 = (pd->intr3_cfg_0 & ~PDSS_INTR3_CFG_0_OV_POS_FILT_SEL_MASK) |
                (0x03 << PDSS_INTR3_CFG_0_OV_POS_FILT_SEL_POS) |
                PDSS_INTR3_CFG_0_OV_POS_FILT_EN;
        }
#endif /* PDL_VBUS_OVP_ENABLE */
    }
    else
    {
#if PDL_VBUS_UVP_ENABLE
        if (filterIndex == CY_USBPD_VBUS_FILTER_ID_UV)
        {
            regval = pd->ngdo_ctrl_c;

            regval |= PDSS_NGDO_CTRL_C_AUTO_MODE | PDSS_NGDO_CTRL_C_SEL_UV;
            regval |= PDSS_NGDO_CTRL_C_PULLDN_EN_LV_OFF_VALUE_MASK;
            regval &= ~PDSS_NGDO_CTRL_C_EN_LV_OFF_VALUE_MASK;

            pd->ngdo_ctrl_c = regval;

            pd->intr3_cfg_0 = (pd->intr3_cfg_0 & ~PDSS_INTR3_CFG_0_UV_NEG_FILT_SEL_MASK) |
                (0x03 << PDSS_INTR3_CFG_0_UV_NEG_FILT_SEL_POS) |
                PDSS_INTR3_CFG_0_UV_NEG_FILT_EN;
        }
#endif /* PDL_VBUS_UVP_ENABLE */

#if PDL_VBUS_OVP_ENABLE
        if (filterIndex == CY_USBPD_VBUS_FILTER_ID_OV)
        {
            regval = pd->ngdo_ctrl_c;

            regval |= PDSS_NGDO_CTRL_C_AUTO_MODE | PDSS_NGDO_CTRL_C_SEL_OV;
            regval |= PDSS_NGDO_CTRL_C_PULLDN_EN_LV_OFF_VALUE_MASK;
            regval &= ~PDSS_NGDO_CTRL_C_EN_LV_OFF_VALUE_MASK;

            pd->ngdo_ctrl_c = regval;

            pd->intr3_cfg_0 = (pd->intr3_cfg_0 & ~PDSS_INTR3_CFG_0_OV_POS_FILT_SEL_MASK) |
                (0x03 << PDSS_INTR3_CFG_0_OV_POS_FILT_SEL_POS) |
                PDSS_INTR3_CFG_0_OV_POS_FILT_EN;
        }
#endif /* PDL_VBUS_OVP_ENABLE */
    }
#endif /* ((PDL_VBUS_OVP_ENABLE) || (PDL_VBUS_UVP_ENABLE)) */

#elif (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S))
    CY_UNUSED_PARAMETER(pctrl);
#if APP_VBUS_SRC_FET_BYPASS_EN
    CY_UNUSED_PARAMETER(pd);
    CY_UNUSED_PARAMETER(context);
    CY_UNUSED_PARAMETER(filterIndex);
    /* Do not configure FET if bypass configuration is selected */
#else
    uint32_t regval;

    regval = pd->bb_ngdo_0_gdrv_en_ctrl;
    /* Enable auto mode. */
    regval |= PDSS_BB_NGDO_0_GDRV_EN_CTRL_AUTO_MODE;
    /* Program the off value to turn off the FET. */
    regval &= ~PDSS_BB_NGDO_0_GDRV_EN_CTRL_GDRV_EN_OFF_VALUE;
    /* Select source. */
    switch (filterIndex)
    {
        case CY_USBPD_VBUS_FILTER_ID_UV:
        case CY_USBPD_VBUS_FILTER_ID_OV:
        case CY_USBPD_VBUS_FILTER_ID_DISCH_EN:
        case CY_USBPD_VBUS_FILTER_ID_LSCSA_PFC:
        case CY_USBPD_VBUS_FILTER_ID_LSCSA_SR:
        case CY_USBPD_VBUS_FILTER_ID_VSRC_NEW_P:
        case CY_USBPD_VBUS_FILTER_ID_VSRC_NEW_M:
            pd->bb_ngdo_1_gdrv_en_ctrl |= ((uint32_t)1u << (uint8_t)filterIndex);
            break;

        case CY_USBPD_VBUS_FILTER_ID_CSA_OCP:
            regval |= PDSS_BB_NGDO_0_GDRV_EN_CTRL_SEL_CSA_OCP;
            break;

        case CY_USBPD_VBUS_FILTER_ID_CSA_SCP:
            regval |= PDSS_BB_NGDO_0_GDRV_EN_CTRL_SEL_CSA_SCP;
            break;

        case CY_USBPD_VBUS_FILTER_ID_PDS_SCP:
            regval |= PDSS_BB_NGDO_0_GDRV_EN_CTRL_SEL_PDS_SCP;
            break;

        case CY_USBPD_VBUS_FILTER_ID_VIN_UVP:
            regval |= PDSS_BB_NGDO_0_GDRV_EN_CTRL_SEL_VIN_UV_DET;
            break;

        case CY_USBPD_VBUS_FILTER_ID_VIN_OVP:
            regval |= PDSS_BB_NGDO_0_GDRV_EN_CTRL_SEL_VIN_OV_DET;
            break;

        case CY_USBPD_VBUS_FILTER_ID_ILIM_DET:
            regval |= PDSS_BB_NGDO_0_GDRV_EN_CTRL_SEL_ILIM_DIG;
            break;

        case CY_USBPD_VBUS_FILTER_ID_VREG_INRUSH_DET:
            regval |= PDSS_BB_NGDO_0_GDRV_EN_CTRL_SEL_VREG_IN_RUSH;
            break;

        case CY_USBPD_VBUS_FILTER_ID_BROWN_OUT_DET:
            regval |= PDSS_BB_NGDO_0_GDRV_EN_CTRL_SEL_VREG_VDDD_BOD;
            break;

        default:
            /* Intentionally left empty. */
            break;
    }

    pd->bb_ngdo_0_gdrv_en_ctrl = regval;
#endif /* !APP_VBUS_SRC_FET_BYPASS_EN */

#endif /* (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S)) */

#endif /* CY_DEVICE */
#endif /* !defined(CY_DEVICE_SERIES_WLC1) */

#if (!defined(CY_DEVICE_SERIES_WLC1))
    CY_UNUSED_PARAMETER(context);
    CY_UNUSED_PARAMETER(pctrl);
    CY_UNUSED_PARAMETER(filterIndex);
#endif
}


/*******************************************************************************
* Function Name: Cy_USBPD_Fault_FetAutoModeDisable
****************************************************************************//**
*
* Disable automatic hardware control on a gate driver due to a specified
 * comparator and output filter. Does not affect automatic control of the gate
 * driver by other comparators of filters.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \param pctrl
* Flag indicating the type of gate driver to be controlled, true for
* P_CTRL and false for C_CTRL.
*
* \param filterIndex
* \ref cy_en_usbpd_vbus_filter_id_t enumerated type for various faults
*
*******************************************************************************/
void Cy_USBPD_Fault_FetAutoModeDisable(cy_stc_usbpd_context_t *context, bool pctrl, cy_en_usbpd_vbus_filter_id_t filterIndex)
{
#if ((defined(CY_DEVICE_CCG3PA)) || (defined(CY_DEVICE_CCG6)) || (defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP)) || (defined(CY_DEVICE_CCG7D)) || (defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)))
    PPDSS_REGS_T pd = context->base;

    (void)pd;
#if defined(CY_DEVICE_CCG3PA)
    uint32_t regValCfg1;
    uint32_t regValCfg2;

    if (pctrl)
    {
        /* Remove source. */
        regValCfg1 = pd->pgdo_pu_1_cfg;
        regValCfg2 = pd->pgdo_pu_2_cfg;

        regValCfg2 &= ~(1UL << (uint8_t)filterIndex);

        /* Disable Auto mode if no other source is active. */
        if ((regValCfg2 == 0U) && ((regValCfg1 & PGDO_PU_1_CFG_AUTO_SEL_MASK) == 0U))
        {
           regValCfg1 &= ~PDSS_PGDO_PU_1_CFG_AUTO_MODE;
        }
        pd->pgdo_pu_2_cfg = regValCfg2;
        pd->pgdo_pu_1_cfg = regValCfg1;
    }
    else
    {
        /* Remove source. */
        regValCfg1 = pd->pgdo_1_cfg;
        regValCfg2 = pd->pgdo_2_cfg;

        regValCfg2 &= ~(1UL << (uint8_t)filterIndex);

        if ((regValCfg2 == 0U) && ((regValCfg1 & PGDO_1_CFG_AUTO_SEL_MASK) == 0U))
        {
            regValCfg1 &= ~PDSS_PGDO_1_CFG_AUTO_MODE;
        }
        pd->pgdo_2_cfg = regValCfg2;
        pd->pgdo_1_cfg = regValCfg1;
    }
#elif defined(CY_DEVICE_CCG6)
    if (pctrl)
    {
        /* Use PGDO_PU_1_CFG register for Provider FET */

        /* Remove source. */
        if (filterIndex == CY_USBPD_VBUS_FILTER_ID_HSCSA_SCP)
        {
            pd->pgdo_pu_3_cfg &= ~PDSS_PGDO_PU_3_CFG_PGDO_EN_SCP_LV;
        }
        else if(filterIndex == CY_USBPD_VBUS_FILTER_ID_HSCSA_RCP)
        {
            pd->pgdo_pu_3_cfg &= ~(PDSS_PGDO_PU_3_CFG_PGDO_EN_RCP_LV | PDSS_PGDO_PU_3_CFG_PGDO_EN_VBUS_OV_LV);
        }
        else if (filterIndex == CY_USBPD_VBUS_FILTER_ID_HSCSA_OCP)
        {
            pd->pgdo_pu_1_cfg &= ~PDSS_PGDO_PU_1_CFG_SEL_CSA_OC;
        }
        else
        {
            pd->pgdo_pu_2_cfg &= ~(1UL << (uint8_t)filterIndex);
        }

        /* Disable Auto mode if no other source is active. */
        if ((pd->pgdo_pu_2_cfg == 0U) && ((pd->pgdo_pu_1_cfg & PGDO_1_CFG_AUTO_SEL_MASK) == 0U))
        {
            pd->pgdo_pu_1_cfg &= ~PDSS_PGDO_1_CFG_AUTO_MODE;
        }
    }
    else
    {
        /* Remove source. */
        pd->pgdo_2_cfg &= ~(1UL << (uint8_t)filterIndex);
        /* Disable Auto mode if no other source is active. */
        if ((pd->pgdo_2_cfg == 0U) && ((pd->pgdo_1_cfg & PGDO_1_CFG_AUTO_SEL_MASK) == 0U))
        {
            pd->pgdo_1_cfg &= ~PDSS_PGDO_1_CFG_AUTO_MODE;
        }
    }
#elif defined(CY_DEVICE_PMG1S3)
    /* Provider FET. */
    if (pctrl)
    {
        if (filterIndex == CY_USBPD_VBUS_FILTER_ID_HSCSA_SCP)
        {
            pd->v2_ngdo_0_ctrl &= ~(PDSS_V2_NGDO_0_CTRL_NGDO_FAULT_SCP_EN);
        }
        else if (filterIndex == CY_USBPD_VBUS_FILTER_ID_HSCSA_RCP)
        {
            pd->v2_ngdo_0_ctrl &= ~(PDSS_V2_NGDO_0_CTRL_NGDO_FAULT_RCP_EN);
        }
        else
        {
            /* Do nothing */
        }
    }
    /* Consumer FET. */
    else
    {
        /* Do nothing. */
    }

#elif defined(CY_DEVICE_CCG6DF_CFP)
    /* Provider FET. */
    if (pctrl)
    {
        if (filterIndex == CY_USBPD_VBUS_FILTER_ID_HSCSA_SCP)
        {
            pd->switch_ctrl_06 &= ~(PDSS_SWITCH_CTRL_06_AUTO_MODE | (0x01u << 12u));
            pd->switch_ctrl_07 &= ~(PDSS_SWITCH_CTRL_07_AUTO_MODE | (0x01u << 12u));
            pd->switch_ctrl_08 &= ~(PDSS_SWITCH_CTRL_08_AUTO_MODE | (0x01u << 12u));
            pd->switch_ctrl_09 &= ~(PDSS_SWITCH_CTRL_09_AUTO_MODE | (0x01u << 12u));
        }
        else if (filterIndex == CY_USBPD_VBUS_FILTER_ID_HSCSA_RCP)
        {
            pd->switch_ctrl_06 &= ~(PDSS_SWITCH_CTRL_06_AUTO_MODE | (0x01u << 13u));
            pd->switch_ctrl_07 &= ~(PDSS_SWITCH_CTRL_07_AUTO_MODE | (0x01u << 13u));
            pd->switch_ctrl_08 &= ~(PDSS_SWITCH_CTRL_08_AUTO_MODE | (0x01u << 13u));
            pd->switch_ctrl_09 &= ~(PDSS_SWITCH_CTRL_09_AUTO_MODE | (0x01u << 13u));
        }
        else if (filterIndex == CY_USBPD_VBUS_FILTER_ID_UV)
        {
            pd->switch_ctrl_06 &= ~(PDSS_SWITCH_CTRL_06_AUTO_MODE | (0x01u << 10u));
            pd->switch_ctrl_07 &= ~(PDSS_SWITCH_CTRL_07_AUTO_MODE | (0x01u << 10u));
            pd->switch_ctrl_08 &= ~(PDSS_SWITCH_CTRL_08_AUTO_MODE | (0x01u << 10u));
            pd->switch_ctrl_09 &= ~(PDSS_SWITCH_CTRL_09_AUTO_MODE | (0x01u << 10u));
        }
        else if (filterIndex == CY_USBPD_VBUS_FILTER_ID_OV)
        {
            pd->switch_ctrl_06 &= ~(PDSS_SWITCH_CTRL_06_AUTO_MODE | (0x01u << 11u));
            pd->switch_ctrl_07 &= ~(PDSS_SWITCH_CTRL_07_AUTO_MODE | (0x01u << 11u));
            pd->switch_ctrl_08 &= ~(PDSS_SWITCH_CTRL_08_AUTO_MODE | (0x01u << 11u));
            pd->switch_ctrl_09 &= ~(PDSS_SWITCH_CTRL_09_AUTO_MODE | (0x01u << 11u));
        }
        else
        {
            /* Do nothing */
        }
    }
    /* Consumer FET. */
    else
    {
        /* Do nothing. */
    }

#elif defined(CY_DEVICE_CCG3)

#if (PDL_VBUS_UVP_ENABLE || PDL_VBUS_OVP_ENABLE)
    PPDSS_REGS_T pd = context->base;
    uint32_t regval;

    if (pctrl)
    {
#if PDL_VBUS_UVP_ENABLE
        if (filterIndex == CY_USBPD_VBUS_FILTER_ID_UV)
        {
            regval = pd->ngdo_ctrl_p;

            regval &= ~PDSS_NGDO_CTRL_P_SEL_UV;
            if ((regval & (PDSS_NGDO_CTRL_P_SEL_OV | PDSS_NGDO_CTRL_P_SEL_OC)) == 0)
            {
                regval &= ~PDSS_NGDO_CTRL_P_AUTO_MODE;
            }

            pd->ngdo_ctrl_p = regval;
        }
#endif /* PDL_VBUS_UVP_ENABLE */

#if PDL_VBUS_OVP_ENABLE
        if (filterIndex == CY_USBPD_VBUS_FILTER_ID_OV)
        {
            regval = pd->ngdo_ctrl_p;

            regval &= ~PDSS_NGDO_CTRL_P_SEL_OV;
            if ((regval & (PDSS_NGDO_CTRL_P_SEL_UV | PDSS_NGDO_CTRL_P_SEL_OC)) == 0)
            {
                regval &= ~PDSS_NGDO_CTRL_P_AUTO_MODE;
            }

            pd->ngdo_ctrl_p = regval;
        }
#endif /* PDL_VBUS_OVP_ENABLE */
    }
    else
    {
#if PDL_VBUS_UVP_ENABLE
        if (filterIndex == CY_USBPD_VBUS_FILTER_ID_UV)
        {
            regval = pd->ngdo_ctrl_c;

            regval &= ~PDSS_NGDO_CTRL_C_SEL_UV;
            if ((regval & (PDSS_NGDO_CTRL_C_SEL_OV | PDSS_NGDO_CTRL_C_SEL_OC)) == 0)
            {
                regval &= ~PDSS_NGDO_CTRL_C_AUTO_MODE;
            }

            pd->ngdo_ctrl_c = regval;
        }
#endif /* PDL_VBUS_UVP_ENABLE */

#if PDL_VBUS_OVP_ENABLE
        if (filterIndex == CY_USBPD_VBUS_FILTER_ID_OV)
        {
            regval = pd->ngdo_ctrl_c;

            regval &= ~PDSS_NGDO_CTRL_C_SEL_OV;
            if ((regval & (PDSS_NGDO_CTRL_C_SEL_UV | PDSS_NGDO_CTRL_C_SEL_OC)) == 0)
            {
                regval &= ~PDSS_NGDO_CTRL_C_AUTO_MODE;
            }

            pd->ngdo_ctrl_c = regval;
        }
#endif /* PDL_VBUS_OVP_ENABLE */
    }
#endif /* (PDL_VBUS_UVP_ENABLE || PDL_VBUS_OVP_ENABLE) */

#elif (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
    /* Do not configure FET if bypass configuration is selected */
#if !APP_VBUS_SRC_FET_BYPASS_EN
    uint32_t regval_0_cfg;
    uint32_t regval_1_cfg;

    /* Remove source. */
    regval_0_cfg = pd->bb_ngdo_0_gdrv_en_ctrl;
    regval_1_cfg = pd->bb_ngdo_1_gdrv_en_ctrl;

    switch (filterIndex)
    {
        case CY_USBPD_VBUS_FILTER_ID_UV:
        case CY_USBPD_VBUS_FILTER_ID_OV:
        case CY_USBPD_VBUS_FILTER_ID_DISCH_EN:
        case CY_USBPD_VBUS_FILTER_ID_LSCSA_PFC:
        case CY_USBPD_VBUS_FILTER_ID_LSCSA_SR:
        case CY_USBPD_VBUS_FILTER_ID_VSRC_NEW_P:
        case CY_USBPD_VBUS_FILTER_ID_VSRC_NEW_M:
            regval_1_cfg &= ~((uint32_t)1u << (uint8_t)filterIndex);
            break;
        case CY_USBPD_VBUS_FILTER_ID_CSA_OCP:
            regval_0_cfg &= ~PDSS_BB_NGDO_0_GDRV_EN_CTRL_SEL_CSA_OCP;
            break;

        case CY_USBPD_VBUS_FILTER_ID_CSA_SCP:
            regval_0_cfg &= ~PDSS_BB_NGDO_0_GDRV_EN_CTRL_SEL_CSA_SCP;
            break;

        case CY_USBPD_VBUS_FILTER_ID_PDS_SCP:
            regval_0_cfg &= ~PDSS_BB_NGDO_0_GDRV_EN_CTRL_SEL_PDS_SCP;
            break;

        case CY_USBPD_VBUS_FILTER_ID_VIN_UVP:
            regval_0_cfg &= ~PDSS_BB_NGDO_0_GDRV_EN_CTRL_SEL_VIN_UV_DET;
            break;

        case CY_USBPD_VBUS_FILTER_ID_VIN_OVP:
            regval_0_cfg &= ~PDSS_BB_NGDO_0_GDRV_EN_CTRL_SEL_VIN_OV_DET;
            break;

        case CY_USBPD_VBUS_FILTER_ID_ILIM_DET:
            regval_0_cfg &= ~PDSS_BB_NGDO_0_GDRV_EN_CTRL_SEL_ILIM_DIG;
            break;

        case CY_USBPD_VBUS_FILTER_ID_VREG_INRUSH_DET:
            regval_0_cfg &= ~PDSS_BB_NGDO_0_GDRV_EN_CTRL_SEL_VREG_IN_RUSH;
            break;

        case CY_USBPD_VBUS_FILTER_ID_BROWN_OUT_DET:
            regval_0_cfg &= ~PDSS_BB_NGDO_0_GDRV_EN_CTRL_SEL_VREG_VDDD_BOD;
            break;

        default:
            /* Intentionally left empty. */
            break;
    }

    /* Disable Auto mode if no other source is active. */
    if ((regval_1_cfg == 0u) && ((regval_0_cfg & BB_NGDO_0_GDRV_EN_CTRL_SEL_MASK) == 0u))
    {
       regval_0_cfg &= ~PDSS_BB_NGDO_0_GDRV_EN_CTRL_AUTO_MODE;
    }
    pd->bb_ngdo_0_gdrv_en_ctrl = regval_0_cfg;
    pd->bb_ngdo_1_gdrv_en_ctrl = regval_1_cfg;
#else /* !APP_VBUS_SRC_FET_BYPASS_EN */
    CY_UNUSED_PARAMETER(pd);
    CY_UNUSED_PARAMETER(context);
    CY_UNUSED_PARAMETER(pctrl);
    CY_UNUSED_PARAMETER(filterIndex);
#endif /* !APP_VBUS_SRC_FET_BYPASS_EN */

#else /* CCGx */
    CY_UNUSED_PARAMETER(pd);
#endif /* CCGx */

#endif /* CY_DEVICE */

    CY_UNUSED_PARAMETER(context);
    CY_UNUSED_PARAMETER(pctrl);
    CY_UNUSED_PARAMETER(filterIndex);
}


/*******************************************************************************
* Function Name: Cy_USBPD_Fault_Vconn_OcpEnable
****************************************************************************//**
*
* Enable Over-Current detection on the VConn power source.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \param cb
* Callback function to be called on fault detection.
*
*******************************************************************************/
void Cy_USBPD_Fault_Vconn_OcpEnable(cy_stc_usbpd_context_t *context, cy_cb_vbus_fault_t cb)
{
#if (defined (PDL_VCONN_OCP_ENABLE) && (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)))
    PPDSS_REGS_T pd = context->base;
    uint32_t state;
    uint32_t regVal, ccInt;

    state = Cy_SysLib_EnterCriticalSection();

    /* Store the parameters. */
    context->vconnOcpCbk = cb;

    /* Configure the filter on the appropriate CC line. */
    pd->intr1_cfg_cc12_ocp_hs = 0;

    if (context->dpmGetConfig()->polarity == CY_PD_CC_CHANNEL_1)
    {
#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S))
        /*
         * Reset and Enable filter with positive edge detection with 4 HF
         * clock cycle period.
         */
        regVal = pd->intr1_cfg_cc12_ocp_hs;
        regVal &= ~(PDSS_INTR1_CFG_CC12_OCP_HS_CC2_OCP_FILT_EN |
                PDSS_INTR1_CFG_CC12_OCP_HS_CC2_OCP_FILT_CFG_MASK |
                PDSS_INTR1_CFG_CC12_OCP_HS_CC2_OCP_FILT_SEL_MASK |
                PDSS_INTR1_CFG_CC12_OCP_HS_CC2_OCP_FILT_RESET |
                PDSS_INTR1_CFG_CC12_OCP_HS_CC2_OCP_FILT_BYPASS);
#else
        regVal = 0UL;
#endif /* (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S)) */
        /* Enable filter with positive edge detection with 4 HF clock cycle period. */
        regVal |= (
                ((uint32_t)CY_USBPD_VBUS_FILTER_CFG_POS_EN_NEG_DIS << PDSS_INTR1_CFG_CC12_OCP_HS_CC2_OCP_FILT_CFG_POS) |
                (4UL << PDSS_INTR1_CFG_CC12_OCP_HS_CC2_OCP_FILT_SEL_POS) |
                PDSS_INTR1_CFG_CC12_OCP_HS_CC2_OCP_DPSLP_MODE |
                PDSS_INTR1_CFG_CC12_OCP_HS_CC2_OCP_FILT_EN
                );
        ccInt = PDSS_INTR1_CC2_OCP_CHANGED;

        /* Enable OC detection on CC2 pin. */
#if defined(CY_DEVICE_CCG6DF_CFP)
        pd->pd_30vconn_ctrl |= PDSS_PD_30VCONN_CTRL_VCONN30_EN_OCP_CC2;
#else
        pd->vconn20_ctrl |= PDSS_VCONN20_CTRL_EN_OCP_CC2;
#endif /* defined(CY_DEVICE_CCG6DF_CFP) */
    }
    else
    {
#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S))
        /*
         * Reset and Enable filter with positive edge detection with 4 HF
         * clock cycle period.
         */
        regVal = pd->intr1_cfg_cc12_ocp_hs;
        regVal &= ~(PDSS_INTR1_CFG_CC12_OCP_HS_CC1_OCP_FILT_EN |
            PDSS_INTR1_CFG_CC12_OCP_HS_CC1_OCP_FILT_CFG_MASK |
            PDSS_INTR1_CFG_CC12_OCP_HS_CC1_OCP_FILT_SEL_MASK |
            PDSS_INTR1_CFG_CC12_OCP_HS_CC1_OCP_FILT_RESET |
            PDSS_INTR1_CFG_CC12_OCP_HS_CC1_OCP_FILT_BYPASS);
            pd->intr1_cfg_cc12_ocp_hs = regVal;
#else
        regVal = 0UL;
#endif /* (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S)) */
        regVal |= (
                ((uint32_t)CY_USBPD_VBUS_FILTER_CFG_POS_EN_NEG_DIS << PDSS_INTR1_CFG_CC12_OCP_HS_CC1_OCP_FILT_CFG_POS) |
                (4UL << PDSS_INTR1_CFG_CC12_OCP_HS_CC1_OCP_FILT_SEL_POS) |
                PDSS_INTR1_CFG_CC12_OCP_HS_CC1_OCP_DPSLP_MODE |
                PDSS_INTR1_CFG_CC12_OCP_HS_CC1_OCP_FILT_EN
                );
        ccInt = PDSS_INTR1_CC1_OCP_CHANGED;

        /* Enable OC detection on CC1 pin. */
#if defined(CY_DEVICE_CCG6DF_CFP)
        pd->pd_30vconn_ctrl |= PDSS_PD_30VCONN_CTRL_VCONN30_EN_OCP_CC1;
#else
        pd->vconn20_ctrl |= PDSS_VCONN20_CTRL_EN_OCP_CC1;
#endif /* defined(CY_DEVICE_CCG6DF_CFP) */
    }

#if defined(CY_DEVICE_CCG6DF_CFP)
    /* Connect the input of the OCP comparator to CC1/CC2 and V5V pins. */
    pd->pd_30vconn_ctrl |= PDSS_PD_30VCONN_CTRL_EN_OCP_TAP;
#endif /* defined(CY_DEVICE_CCG6DF_CFP) */
    /* Set the VConn OCP configuration. */
    pd->intr1_cfg_cc12_ocp_hs = regVal;

#if !(defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1) || defined(CY_DEVICE_CCG6DF_CFP))
    /* Enable the VCONN OCP trim current and comparator */
    pd->vconn20_ctrl |= ((1UL << 6) | (1UL << 10));
#endif /* !(defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1) || defined(CY_DEVICE_CCG6DF_CFP)) */

    /* Clear and enable the interrupt associated with OC detection on CC lines. */
    pd->intr1 = (PDSS_INTR1_CC1_OCP_CHANGED | PDSS_INTR1_CC2_OCP_CHANGED);

#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
    /* Make sure VConn OCP debounce timer is not running. */
    context->timerStopcbk(context, (cy_en_usbpd_timer_id_t)CY_USBPD_PD_VCONN_OCP_DEBOUNCE_TIMER);
#endif /* (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) */

    /* Enable the interrupt. */
    pd->intr1_mask |= ccInt;

    Cy_SysLib_ExitCriticalSection (state);

#else
    /* Avoid compiler warnings about unused arguments. */
    CY_UNUSED_PARAMETER(context);
    (void)(cy_cb_vbus_fault_t)cb;
#endif /* (defined (PDL_VCONN_OCP_ENABLE) && (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))) */
}


/*******************************************************************************
* Function Name: Cy_USBPD_Fault_Vconn_OcpDisable
****************************************************************************//**
*
* Disable Over-Current detection on the VConn power source.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
*******************************************************************************/
void Cy_USBPD_Fault_Vconn_OcpDisable(cy_stc_usbpd_context_t *context)
{
#if defined(PDL_VCONN_OCP_ENABLE)
#if (defined(CY_DEVICE_CCG6)|| defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
    PPDSS_REGS_T pd = context->base;

    /* Disable OC detection on CC pins. */
#if defined(CY_DEVICE_CCG6DF_CFP)
    pd->pd_30vconn_ctrl &= ~(PDSS_PD_30VCONN_CTRL_VCONN30_EN_OCP_CC1 | PDSS_PD_30VCONN_CTRL_VCONN30_EN_OCP_CC2);
    pd->pd_30vconn_ctrl &= ~(PDSS_PD_30VCONN_CTRL_DIS_OCP_BLANKING);
    /* Disconnect the input of the OCP comparator to CC1/CC2 and V5V pins. */
    pd->pd_30vconn_ctrl &= ~(PDSS_PD_30VCONN_CTRL_EN_OCP_TAP);
#else
    pd->vconn20_ctrl &= ~(PDSS_VCONN20_CTRL_EN_OCP_CC1 | PDSS_VCONN20_CTRL_EN_OCP_CC2);
#endif /* defined(CY_DEVICE_CCG6DF_CFP) */

#if !(defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1) || defined(CY_DEVICE_CCG6DF_CFP))
    /* Disable the VCONN OCP trim current and comparator */
    pd->vconn20_ctrl &= ~((1UL << 6) | (1UL << 10));
#endif /* !(defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1) || defined(CY_DEVICE_CCG6DF_CFP)) */

    /* Disable the filter block associated with CC12 OC detection. */
    pd->intr1_cfg_cc12_ocp_hs = 0;

    /* Disable and clear the CC12 OC changed interrupt. */
    pd->intr1_mask &= ~(PDSS_INTR1_CC1_OCP_CHANGED | PDSS_INTR1_CC2_OCP_CHANGED);
    pd->intr1       = (PDSS_INTR1_CC1_OCP_CHANGED | PDSS_INTR1_CC2_OCP_CHANGED);

#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
    /* Stop the CC12 OC debounce timer if it is running. */
    context->timerStopcbk(context, (cy_en_usbpd_timer_id_t)CY_USBPD_PD_VCONN_OCP_DEBOUNCE_TIMER);
#endif /* (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) */

    /* Clear the stored configuration. */
    context->vconnOcpCbk = NULL;
#endif /* (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP)) */
#endif /* defined(PDL_VCONN_OCP_ENABLE) */

    CY_UNUSED_PARAMETER(context);
}

#if PDL_VCONN_OCP_ENABLE
#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
/*******************************************************************************
* Function Name: Cy_USBPD_Fault_Vconn_OcpTimerCb
****************************************************************************//**
*
* VCONN OCP fault interrupt handler function.
*
* \param id
* Timer ID for VCONN OCP timer callback.
*
* \param callbackContext
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
*******************************************************************************/
static void Cy_USBPD_Fault_Vconn_OcpTimerCb(uint16_t id, void *callbackContext)
{
    cy_stc_usbpd_context_t *context = (cy_stc_usbpd_context_t *)callbackContext;
    (void)id;

    /* VConn OCP debounced. Deliver callback to app layer. */
    if (context->vconnOcpCbk != NULL)
    {
        context->vconnOcpCbk(context, true);
    }
}
#endif /* (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) */
#endif /* PDL_VCONN_OCP_ENABLE */

/*******************************************************************************
* Function Name: Cy_USBPD_Fault_Vconn_OcpIntrHandler
****************************************************************************//**
*
* * VCONN OCP fault interrupt handler function.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
*******************************************************************************/
void Cy_USBPD_Fault_Vconn_OcpIntrHandler(cy_stc_usbpd_context_t *context)
{
#if PDL_VCONN_OCP_ENABLE
#if (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
    PPDSS_REGS_T pd = context->base;
    uint32_t cfgMask, cfgPos;
    uint32_t statusMask;
#if defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)
    uint8_t debounce = GET_VCONN_OCP_TABLE(context)->debounce;
#endif /* defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1) */

    /* Disable the interrupt to start with. */
    pd->intr1_mask &= ~(PDSS_INTR1_CC1_OCP_CHANGED | PDSS_INTR1_CC2_OCP_CHANGED);

    /* Identify the register fields of interest. */
    if (context->dpmGetConfig()->polarity == CY_PD_CC_CHANNEL_1)
    {
        cfgMask  = PDSS_INTR1_CFG_CC12_OCP_HS_CC2_OCP_FILT_CFG_MASK;
        cfgPos   = PDSS_INTR1_CFG_CC12_OCP_HS_CC2_OCP_FILT_CFG_POS;
        statusMask = PDSS_INTR1_STATUS_CC2_OCP_FILT;
    }
    else
    {
        cfgMask  = PDSS_INTR1_CFG_CC12_OCP_HS_CC1_OCP_FILT_CFG_MASK;
        cfgPos   = PDSS_INTR1_CFG_CC12_OCP_HS_CC1_OCP_FILT_CFG_POS;
        statusMask = PDSS_INTR1_STATUS_CC1_OCP_FILT;
    }

    /* If positive edge interrupt: Current exceeded positive threshold. */
    if (((pd->intr1_cfg_cc12_ocp_hs & cfgMask) >> cfgPos) == (uint32_t)CY_USBPD_VBUS_FILTER_CFG_POS_EN_NEG_DIS)
    {
        /* Look for negative edge of comparator. */
        pd->intr1_cfg_cc12_ocp_hs = Cy_USBPD_MmioRegUpdateField(pd->intr1_cfg_cc12_ocp_hs,
                (uint32_t)CY_USBPD_VBUS_FILTER_CFG_POS_DIS_NEG_EN, cfgMask, (uint8_t)cfgPos);

        /* If the negative edge happened already, queue the interrupt. */
        if ((pd->intr1_status & statusMask) == 0U)
        {
            if (context->dpmGetConfig()->polarity == CY_PD_CC_CHANNEL_1)
            {
                pd->intr1_set = PDSS_INTR1_SET_CC2_OCP_CHANGED;
            }
            else
            {
                pd->intr1_set = PDSS_INTR1_SET_CC1_OCP_CHANGED;
            }
        }

#if !(defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
        (void)context->vconnOcpCbk (context, true);
#else /* !(defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) */
        /* Start the debounce timer. */
        context->timerStartcbk(context, context, CY_USBPD_PD_VCONN_OCP_DEBOUNCE_TIMER, debounce, Cy_USBPD_Fault_Vconn_OcpTimerCb);
#endif /* !(defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) */
    }
    /* If negative edge interrupt: Current is back within limit. */
    else
    {
#if !(defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
        bool retval = context->vconnOcpCbk (context, false);
        if (retval == true)
        {
#else /* !(defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) */

        if (context->timerIsRunningcbk(context, CY_USBPD_PD_VCONN_OCP_DEBOUNCE_TIMER))
        {
            /* Stop the debounce timer. */
            context->timerStopcbk(context, CY_USBPD_PD_VCONN_OCP_DEBOUNCE_TIMER);
#endif /* !(defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) */

            /* Look for positive edge of comparator. */
            pd->intr1_cfg_cc12_ocp_hs = Cy_USBPD_MmioRegUpdateField(pd->intr1_cfg_cc12_ocp_hs,
                    (uint32_t)CY_USBPD_VBUS_FILTER_CFG_POS_EN_NEG_DIS, cfgMask, (uint8_t)cfgPos);

            /* If the positive edge happened already, queue the interrupt. */
            if ((pd->intr1_status & statusMask) != 0U)
            {
                if (context->dpmGetConfig()->polarity == CY_PD_CC_CHANNEL_1)
                {
                    pd->intr1_set = PDSS_INTR1_SET_CC2_OCP_CHANGED;
                }
                else
                {
                    pd->intr1_set = PDSS_INTR1_SET_CC1_OCP_CHANGED;
                }
            }
        }
    }

    /* Enable interrupt. */
    if (context->dpmGetConfig()->polarity == CY_PD_CC_CHANNEL_1)
    {
        pd->intr1_mask |= PDSS_INTR1_CC2_OCP_CHANGED;
    }
    else
    {
        pd->intr1_mask |= PDSS_INTR1_CC1_OCP_CHANGED;
    }

#endif /* (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) */
#endif /* PDL_VCONN_OCP_ENABLE */
    CY_UNUSED_PARAMETER(context);
}

/*******************************************************************************
* Function Name: Cy_USBPD_Fault_Vconn_ScpEnable
****************************************************************************//**
*
* Enable short circuit detection on the VConn power source.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \param cb
* Callback function to be called on fault detection.
*
*******************************************************************************/
void Cy_USBPD_Fault_Vconn_ScpEnable(cy_stc_usbpd_context_t *context, cy_cb_vbus_fault_t cb)
{
#if (PDL_VCONN_SCP_ENABLE && (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)))
    PPDSS_REGS_T pd = context->base;
    uint32_t state;

    state = Cy_SysLib_EnterCriticalSection();

    /* Store the parameters. */
    context->vconnScpCbk = cb;

    /* Turn on firmware vconn scp by turning off HW auto cut off and retry. */
    pd->vconn20_ctrl &= (uint32_t)~((uint32_t)1u << (7u + PDSS_VCONN20_CTRL_T_VCONN_POS));

    /* Enable VCONN SCP handling in firmware */
    if (context->dpmGetConfig()->polarity == CY_PD_CC_CHANNEL_2)
    {
        /* Clear and Enable CC1/2 SCP change interrupt. */
        pd->intr17 = PDSS_INTR17_PDBB_CC1_SCP;
        pd->intr17_mask |= PDSS_INTR17_MASK_PDBB_CC1_SCP_MASK;

        /* If SCP condition is present, set the interrupt again. */
        if ((pd->intr17_status_1 & PDSS_INTR17_STATUS_1_PDBB_CC1_SCP_FILT) != 0u)
        {
            pd->intr17_set |= PDSS_INTR17_SET_PDBB_CC1_SCP;
        }

        /* Enable OC detection on CC1 pin. */
        pd->vconn20_ctrl |= PDSS_VCONN20_CTRL_EN_OCP_CC1;
    }
    else
    {
        /* Clear and Enable CC1/2 SCP change interrupt. */
        pd->intr17 = PDSS_INTR17_PDBB_CC2_SCP;
        pd->intr17_mask |= PDSS_INTR17_MASK_PDBB_CC2_SCP_MASK;

        /* If SCP condition is present, set the interrupt again. */
        if ((pd->intr17_status_1 & PDSS_INTR17_STATUS_1_PDBB_CC2_SCP_FILT) != 0u)
        {
            pd->intr17_set |= PDSS_INTR17_SET_PDBB_CC2_SCP;
        }

        /* Enable OC/SC detection on CC2 pin. */
        pd->vconn20_ctrl |= PDSS_VCONN20_CTRL_EN_OCP_CC2;
    }

    Cy_SysLib_ExitCriticalSection (state);
#else /* (PDL_VCONN_SCP_ENABLE && (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))) */

    /* Avoid compiler warnings about unused arguments. */
    CY_UNUSED_PARAMETER(context);
    (void)(cy_cb_vbus_fault_t)cb;
#endif /* (PDL_VCONN_SCP_ENABLE && (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))) */
}

/*******************************************************************************
* Function Name: Cy_USBPD_Fault_Vconn_ScpDisable
****************************************************************************//**
*
* Disable short circuit detection on the VConn power source.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
*******************************************************************************/
void Cy_USBPD_Fault_Vconn_ScpDisable(cy_stc_usbpd_context_t *context)
{
#if (PDL_VCONN_SCP_ENABLE && (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)))
    PPDSS_REGS_T pd = context->base;

    /* Disable OCP/SCP detection on CC pins. */
    pd->vconn20_ctrl &= ~(PDSS_VCONN20_CTRL_EN_OCP_CC1 | PDSS_VCONN20_CTRL_EN_OCP_CC2);

    /* Clear and disable CC1/2 SCP change interrupt. */
    pd->intr17 = (PDSS_INTR17_PDBB_CC1_SCP |
        PDSS_INTR17_PDBB_CC2_SCP);
    pd->intr17_mask &= ~(PDSS_INTR17_MASK_PDBB_CC1_SCP_MASK |
        PDSS_INTR17_MASK_PDBB_CC2_SCP_MASK);

    pd->intr17_cfg_10 &= ~(PDSS_INTR17_CFG_10_BB_CC1_SCP_FILT_EN |
            PDSS_INTR17_CFG_10_BB_CC2_SCP_FILT_EN);

    /* Clear the stored configuration. */
    context->vconnScpCbk = NULL;
#else /* (PDL_VCONN_SCP_ENABLE && (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))) */

    /* Avoid compiler warnings about unused arguments. */
    CY_UNUSED_PARAMETER(context);
#endif /* (PDL_VCONN_SCP_ENABLE && (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))) */
}

/* Function to gradually modify a refgen output voltage so as to prevent perturbations on other outputs. */
void Cy_USBPD_SetRefgenVoltage(cy_stc_usbpd_context_t *context, uint8_t vrefSel, uint8_t vrefSelPos)
{
#if (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3))
    PPDSS_REGS_T pd = context->base;
    uint32_t vrefOldVal = 0;
    uint32_t mask = 0xFF;
    uint8_t  pos = 0;
    volatile uint32_t *regAddr = &pd->refgen_4_ctrl;
    uint32_t state;

    state = Cy_SysLib_EnterCriticalSection ();
    switch (vrefSelPos)
    {
        case 0:
        case 1:
        case 2:
        case 3:
            regAddr = &(pd->refgen_1_ctrl);
            pos      = (vrefSelPos * 8U);
            break;

        case 4:
        case 5:
        case 6:
        case 7:
            regAddr = &(pd->refgen_2_ctrl);
            pos      = (vrefSelPos - 4U) * 8U;
            break;

        case 8:
        case 9:
        case 10:
            regAddr = &(pd->refgen_3_ctrl);
            pos      = (vrefSelPos - 8U) * 8U;
            break;

        default:
            /* References in REFGEN_4 are three bits wide. */
            pos      = (vrefSelPos - 12U) * 3U;
            mask     = 0x07U;
            break;
    }

    vrefOldVal = (*regAddr >> pos) & mask;
    if (vrefSel > vrefOldVal)
    {
        while ((vrefSel - vrefOldVal) > 20U)
        {
            vrefOldVal += 20U;
            *regAddr  = (*regAddr & ~(mask << pos)) | ((vrefOldVal << pos) & (mask << pos));
            Cy_SysLib_DelayUs(10);
        }
    }
    else
    {
        while ((vrefOldVal - vrefSel) > 20U)
        {
            vrefOldVal -= 20U;
            *regAddr  = (*regAddr & ~(mask << pos)) | ((vrefOldVal << pos) & (mask << pos));
            Cy_SysLib_DelayUs(10);
        }
    }

    *regAddr  = (*regAddr & ~(mask << pos)) | (((uint32_t)vrefSel << pos) & (mask << pos));
    Cy_SysLib_ExitCriticalSection (state);
#elif defined(CY_DEVICE_CCG6DF_CFP)
    PPDSS_REGS_T pd = context->base;
    uint32_t vrefOldVal = 0;
    uint32_t mask = 0xFF;
    uint8_t  pos = 0;
    volatile uint32_t *regAddr = &pd->pd_ref_mux_ctrl_0;
    uint32_t state;

    /* Enter critical section. */
    state = Cy_SysLib_EnterCriticalSection ();
    switch (vrefSelPos)
    {
        case 0:
        case 1:
        case 2:
        case 3:
            /* VSEL 0 - 3, register is pd ref mux ctrl 0  and shift is multiplied by 8. */
            regAddr = &(pd->pd_ref_mux_ctrl_0);
            pos     = (uint8_t)(vrefSelPos << 3U);
            break;

        case 4:
            /* VSEL 4, register is pd ref mux ctrl 1 and shift is 8.*/
            regAddr = &(pd->pd_ref_mux_ctrl_1);
            pos     = 8U;
            break;

        default:
            /* Default case is left un-handled as CFP has only 5 VSELs.
             * This case defaults SEL0 which is NC. */
            break;
    }

    /* Read the old vref voltage. */
    vrefOldVal = (*regAddr >> pos) & mask;
    /* Check if new vref voltage is greater than the previous voltage. */
    if (vrefSel > vrefOldVal)
    {
        /* Increment the vref voltage in steps of 200mV. */
        while ((vrefSel - vrefOldVal) > 20U)
        {
            /* Increment the vref voltage by 200mV. */
            vrefOldVal += 20U;
            /* Apply the new vref voltage by writing to the register. */
            *regAddr  = (*regAddr & ~(mask << pos)) | ((vrefOldVal << pos) & (mask << pos));
            Cy_SysLib_DelayUs(10);
        }
    }
    /* New vref voltage is less than the previous voltage. */
    else
    {
        /* Decrement the vref voltage by 200mV. */
        while ((vrefOldVal - vrefSel) > 20U)
        {
            /* Decrement the vref voltage by 200mV. */
            vrefOldVal -= 20U;
            /* Apply the new vref voltage by writing to the register. */
            *regAddr  = (*regAddr & ~(mask << pos)) | ((vrefOldVal << pos) & (mask << pos));
            Cy_SysLib_DelayUs(10);
        }
    }

    /* Apply the remaining voltage after subtracting 200mV. */
    *regAddr  = (*regAddr & ~(mask << pos)) | (((uint32_t)vrefSel << pos) & (mask << pos));
    /* Exit out of critical section. */
    Cy_SysLib_ExitCriticalSection (state);
#else
    CY_UNUSED_PARAMETER(context);
    CY_UNUSED_PARAMETER(vrefSel);
    CY_UNUSED_PARAMETER(vrefSelPos);
#endif /* (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP)) */
}

#if PDL_VBUS_OVP_ENABLE
/* OVP min reference voltage in mV. */
#define OVP_REF_VOLT_MIN            (200u)

/* Minimum voltage for VREF8 in mV. */
#define OVP_REF8_VOLT_MIN           (130u)

/* OVP reference voltage step size in mV. */
#define OVP_REF_VOLT_STEP           (10u)

/* Min OVP detection level for VBus. */
#if PSVP_FPGA_ENABLE
#define VBUS_OVP_DETECT_MIN         (1000u)
#else
#define VBUS_OVP_DETECT_MIN         (6000u)
#endif /* PSVP_FPGA_ENABLE */

#if (defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP) && CY_PD_EPR_ENABLE)
/* VBUS max voltage in mV. */
#define VBUS_VOLT_MAX               (30000u)
#else
/* VBUS max voltage in mV. */
#define VBUS_VOLT_MAX               (24000u)
#endif /* defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP) */

/* Max. VREF setting. */
#define VREF_MAX_SETTING            (199u)

#define MAX_OVP_DEBOUNCE_CYCLES         (0x20u)
#endif /* PDL_VBUS_OVP_ENABLE */
/*******************************************************************************
* Function Name: Cy_USBPD_Fault_Vbus_OvpEnable
****************************************************************************//**
*
* Enable Over Voltage Protection (OVP) control using the internal UV-OV block.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \param volt
* Contract Voltage in mV units.
*
* \param cb
* Callback function to be called on fault detection.
*
* \param pctrl
* Flag indicating the type of gate driver to be controlled, true for
* P_CTRL and false for C_CTRL.
*
*******************************************************************************/
void Cy_USBPD_Fault_Vbus_OvpEnable(cy_stc_usbpd_context_t *context, uint16_t volt, cy_cb_vbus_fault_t cb, bool pctrl)
{
#if PDL_VBUS_OVP_ENABLE
    PPDSS_REGS_T pd = context->base;
    uint32_t regVal;
    uint16_t threshold;
    uint8_t filterSel;

#if defined(CY_IP_MXUSBPD)
    uint32_t divPos = AMUX_OV_DIV_SEL_BIT_POS;
    uint16_t vref;
#endif /* defined(CY_IP_MXUSBPD) */

#if (!defined(CY_DEVICE_CCG7S) && !defined(CY_DEVICE_CCG7D) && !defined(CY_DEVICE_SERIES_WLC1))
    filterSel = (GET_VBUS_OVP_TABLE(context)->debounce + 1) / 2;
    filterSel = CY_USBPD_GET_MIN (filterSel, MAX_OVP_DEBOUNCE_CYCLES);
#else
    /* Convert debounce delay in us to filter clock cycles. */
    filterSel = GET_VBUS_OVP_TABLE(context)->debounce;
    filterSel = (uint8_t)system_get_clk_filt_sel(context->port, (((uint16_t) filterSel) * 10u));
#endif /* (!defined(CY_DEVICE_CCG7S) && !defined(CY_DEVICE_SERIES_WLC1) && !defined(CY_DEVICE_CCG7D)) */

    /* Clear AUTO MODE OVP detect to avoid false auto off during reference change */
    if (GET_VBUS_OVP_TABLE(context)->mode == CY_USBPD_VBUS_OVP_MODE_UVOV_AUTOCTRL)
    {
        Cy_USBPD_Fault_FetAutoModeDisable (context, pctrl, CY_USBPD_VBUS_FILTER_ID_OV);
    }


    /* Store OVP parameters. */
    context->vbusOvpCbk = cb;
#if(!defined(CY_DEVICE_SERIES_WLC1)) /** DONOT APPLY THRESHOLD FOR WLC1 DEVICE SERIES */
    /* Calculate required VBUS for OVP. */
    threshold = volt + ((volt * GET_VBUS_OVP_TABLE(context)->threshold) / 100);
#else
    threshold = volt;
#endif

#if defined(CY_IP_MXUSBPD)

    /* Cap the maximum voltage to be measured. */
    if (threshold > VBUS_VOLT_MAX)
        threshold = VBUS_VOLT_MAX;
    /* Make sure threshold is above the minimum trip point to avoid false triggers. */
    if (threshold < VBUS_OVP_DETECT_MIN)
        threshold = VBUS_OVP_DETECT_MIN;

#if !defined(CY_DEVICE_CCG7D) && !defined(CY_DEVICE_CCG7S) && !defined(CY_DEVICE_SERIES_WLC1)
    regVal = pd->amux_nhv_ctrl;
#endif /* !defined(CY_DEVICE_CCG7D) && !defined(CY_DEVICE_CCG7S) && !defined(CY_DEVICE_SERIES_WLC1) */

#if defined(CY_DEVICE_CCG3PA)
#if !PMG1_FLIPPED_FET_CTRL
    /* Choose VBUS_C as source for AMUX. */
     regVal &= ~(AMUX_OV_VBUS_SEL_MASK);
#else
    /* As TYPE C VBUS is connected to VBUS_IN node, choose VBUS_IN as source. */
    regVal |= AMUX_OV_VBUS_SEL_MASK;
#endif /* PMG1_FLIPPED_FET_CTRL */
#endif /* defined(CY_DEVICE_CCG3PA) */

    /*
     * Internal divider to be used depends on VBUS to be measured.
     * On PMG1S0: for VBUS < VBUS_DIV_20_PER_MAX_VOLT, use 20% divider and for greater, use 8% divider.
     * On PMG1S1: Always use 8% divider.
     * On PMG1S3: Use 6% divider.
     */

#if defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)
    if (threshold <= VBUS_DIV_20_PER_MAX_VOLT)
    {
        vref = threshold / VBUS_C_20_PER_DIV;

#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
        (void)divPos;
        pd->amux_ctrl |= (1 << AMUX_OV_DIV_SEL_BIT_POS);
#else /* CY_DEVICE_CCG3PA */
        /* Connect output to 20% */
        regVal |= (1U << divPos);
#endif /* CY_DEVICE_CCG3PA */
    }
    else
#endif /* defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1) */
    {

        {
#if defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP)
            /* Get 6% of threshold. */
            vref = (threshold * 6) / 100;
#else            
            /* Get 8% of threshold. */
            vref = (threshold * 10) / 125;
#endif /* defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP) */
        }

        /* Connect output to divider */
#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
        pd->amux_ctrl &= ~((uint32_t)1u << AMUX_OV_DIV_SEL_BIT_POS);
#else
        regVal &= ~(1U << divPos);
#endif /* (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) */
    }

#if !defined(CY_DEVICE_CCG7D) && !defined(CY_DEVICE_CCG7S) && !defined(CY_DEVICE_SERIES_WLC1)
    pd->amux_nhv_ctrl = regVal;
#endif /* !defined(CY_DEVICE_CCG7D) && !defined(CY_DEVICE_CCG7S) && !defined(CY_DEVICE_SERIES_WLC1) */

    /* Calculate the actual reference voltage. Cap the value to the max. supported. */
#if defined(CY_DEVICE_CCG6DF_CFP)
    /* OV reference voltage min is 130mV for CFP. */
    vref = ((vref - OVP_REF8_VOLT_MIN) / OVP_REF_VOLT_STEP);
#else
    vref = ((vref - OVP_REF_VOLT_MIN) / OVP_REF_VOLT_STEP);
#endif /* defined(CY_DEVICE_CCG6DF_CFP) */
    if (vref > VREF_MAX_SETTING)
        vref = VREF_MAX_SETTING;

    /* Program reference voltage for OV comparator. */

    {
#if (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP))
        Cy_USBPD_SetRefgenVoltage (context, vref, CY_USBPD_VREF_VBUS_OV);
#else
        /* OV comparator for Port 0 uses VREF[3]. */
        regVal = pd->refgen_1_ctrl;
        regVal &= ~(PDSS_REFGEN_1_CTRL_SEL3_MASK);
        regVal |= (vref << PDSS_REFGEN_1_CTRL_SEL3_POS);
        pd->refgen_1_ctrl = regVal;
#endif /* (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP)) */
    }

    /* Turn on comparator. */
    pd->comp_ctrl[CY_USBPD_VBUS_COMP_ID_OV] |= PDSS_COMP_CTRL_COMP_ISO_N;
    pd->comp_ctrl[CY_USBPD_VBUS_COMP_ID_OV] &= ~PDSS_COMP_CTRL_COMP_PD;

    Cy_SysLib_DelayUs(10);

    /* Filter configuration. */
    pd->intr5_filter_cfg[CY_USBPD_VBUS_FILTER_ID_OV] &= ~PDSS_INTR5_FILTER_CFG_FILT_EN;
    regVal = pd->intr5_filter_cfg[CY_USBPD_VBUS_FILTER_ID_OV] & ~(PDSS_INTR5_FILTER_CFG_FILT_CFG_MASK
            | PDSS_INTR5_FILTER_CFG_FILT_SEL_MASK | PDSS_INTR5_FILTER_CFG_DPSLP_MODE |
            PDSS_INTR5_FILTER_CFG_FILT_BYPASS | PDSS_INTR5_FILTER_CFG_FILT_RESET);

    /* Set filter clock cycles if filter is required. */
    if (filterSel)
    {
        /* Subtracting 1 from filter clock cycle value as 0 translates to 1-2 clock cycles. */
        regVal |= ((((((uint8_t)filterSel - 1u) != 0u) ? ((uint32_t)filterSel - 1u) : 1u) & (uint32_t)0x1Fu) <<
            PDSS_INTR5_FILTER_CFG_FILT_SEL_POS);
        /* Set edge detection. */
        regVal |= (CY_USBPD_VBUS_FILTER_CFG_POS_EN_NEG_DIS << PDSS_INTR5_FILTER_CFG_FILT_CFG_POS);
        regVal |= PDSS_INTR5_FILTER_CFG_FILT_EN | PDSS_INTR5_FILTER_CFG_DPSLP_MODE;
    }
    else
    {
        regVal |= PDSS_INTR5_FILTER_CFG_FILT_BYPASS;
    }

    pd->intr5_filter_cfg[CY_USBPD_VBUS_FILTER_ID_OV] = regVal;

    /* Clear interrupt. */
    pd->intr5 = (1U << CY_USBPD_VBUS_FILTER_ID_OV);

    /* Enable Interrupt. */
    pd->intr5_mask |= (1U << CY_USBPD_VBUS_FILTER_ID_OV);

    /* Enable Auto mode. */
    if (GET_VBUS_OVP_TABLE(context)->mode == CY_USBPD_VBUS_OVP_MODE_UVOV_AUTOCTRL)
    {
        Cy_USBPD_Fault_FetAutoModeEnable (context, pctrl, CY_USBPD_VBUS_FILTER_ID_OV);
    }

#if PSVP_FPGA_ENABLE 
#if (!defined(CY_DEVICE_CCG6DF_CFP))
    ctrl_inf_ovp_enable(threshold);
#endif /* (!defined(CY_DEVICE_CCG6DF_CFP)) */
#endif /* PSVP_FPGA_ENABLE */

#elif defined(CY_IP_M0S8USBPD)

/*
 *  Input ladder voltages, code limits and step sizes from Table 26 of the
 *  HardIP BROS (001-98391).
 */
#define UVOV_LADDER_BOT     (2750u)
#define UVOV_LADDER_MID     (9000u)
#define UVOV_LADDER_TOP     (21500u)
#define UVOV_CODE_BOT       (0)
#define UVOV_CODE_MID       (25u)
#define UVOV_CODE_TOP       (50u)
#define UVOV_CODE_MAX       (63u)
#define UVOV_CODE_6V0       (13u)
#define UVOV_LO_STEP_SZ     (250u)
#define UVOV_HI_STEP_SZ     (500u)

    uint8_t level;

    /*
     * Calculate OVP comparator threshold setting.
     */
    if (threshold < UVOV_LADDER_BOT)
    {
        level = UVOV_CODE_BOT;
    }
    else if (threshold > UVOV_LADDER_TOP)
    {
        level = UVOV_CODE_TOP;
    }
    else if (threshold <= UVOV_LADDER_MID)
    {
        level = (uint8_t)((threshold - UVOV_LADDER_BOT) / UVOV_LO_STEP_SZ);
    }
    else
    {
        level = (uint8_t)(((threshold - UVOV_LADDER_MID) / UVOV_HI_STEP_SZ) + UVOV_CODE_MID);
    }

    /* Clear OVP positive edge notification. */
    pd->intr3 = PDSS_INTR3_POS_OV_CHANGED;

    /* Configure the UVOV block. */
    regVal = pd->uvov_ctrl & ~(PDSS_UVOV_CTRL_OV_IN_MASK | PDSS_UVOV_CTRL_PD_UVOV);
    regVal |= PDSS_UVOV_CTRL_UVOV_ISO_N;
    pd->uvov_ctrl = (level << PDSS_UVOV_CTRL_OV_IN_POS) | regVal;

    if (GET_VBUS_OVP_TABLE(context)->mode == CY_USBPD_VBUS_OVP_MODE_UVOV_AUTOCTRL)
    {
        Cy_USBPD_Fault_FetAutoModeEnable (context, pctrl, CY_USBPD_VBUS_FILTER_ID_OV);
        Cy_SysLib_DelayUs (10);
    }

    /* If the OV_DET output is already high, flag it. */
    if (pd->ncell_status & PDSS_NCELL_STATUS_OV_STATUS)
    {
        pd->intr3_set |= PDSS_INTR3_POS_OV_CHANGED;
    }

    /* Enable OVP positive edge detection. */
    pd->intr3_mask |= PDSS_INTR3_POS_OV_CHANGED;

#endif /* CY_IP */
#else
    CY_UNUSED_PARAMETER(context);
    CY_UNUSED_PARAMETER(volt);
    (void)(cy_cb_vbus_fault_t)cb;
    CY_UNUSED_PARAMETER(pctrl);
#endif /* PDL_VBUS_OVP_ENABLE */
}


/*******************************************************************************
* Function Name: Cy_USBPD_Fault_Vbus_OvpDisable
****************************************************************************//**
*
* Disable Over Voltage Protection (OVP) control.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \param pctrl
* Flag indicating the type of gate driver to be controlled, true for
* P_CTRL and false for C_CTRL.
*
*******************************************************************************/
void Cy_USBPD_Fault_Vbus_OvpDisable(cy_stc_usbpd_context_t *context, bool pctrl)
{
#if PDL_VBUS_OVP_ENABLE
#if defined(CY_IP_MXUSBPD)
    PPDSS_REGS_T pd = context->base;
    uint32_t state;
    uint16_t vref;

    state = Cy_SysLib_EnterCriticalSection();

    /* Clear AUTO MODE OVP detect. */
    if (GET_VBUS_OVP_TABLE(context)->mode == CY_USBPD_VBUS_OVP_MODE_UVOV_AUTOCTRL)
    {
        Cy_USBPD_Fault_FetAutoModeDisable (context, pctrl, CY_USBPD_VBUS_FILTER_ID_OV);
    }

    /* Disable comparator. */
    pd->comp_ctrl[CY_USBPD_VBUS_COMP_ID_OV] &= ~PDSS_COMP_CTRL_COMP_ISO_N;
    pd->comp_ctrl[CY_USBPD_VBUS_COMP_ID_OV] |= PDSS_COMP_CTRL_COMP_PD;

     /* Disable filter. */
    pd->intr5_filter_cfg[CY_USBPD_VBUS_FILTER_ID_OV] &= ~(PDSS_INTR5_FILTER_CFG_FILT_EN |
        PDSS_INTR5_FILTER_CFG_FILT_CFG_MASK | PDSS_INTR5_FILTER_CFG_FILT_SEL_MASK |
        PDSS_INTR5_FILTER_CFG_FILT_BYPASS | PDSS_INTR5_FILTER_CFG_DPSLP_MODE);

    /* Disable and clear OV interrupts. */
    pd->intr5_mask &= ~(1U << CY_USBPD_VBUS_FILTER_ID_OV);
    pd->intr5 = 1U << CY_USBPD_VBUS_FILTER_ID_OV;

#if defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)
    pd->amux_ctrl |= (1u << AMUX_OV_DIV_SEL_BIT_POS);
#else
    /* Connect OV comparator input to 20% / 10% of VBus. */
    pd->amux_nhv_ctrl |= (1U << AMUX_OV_DIV_SEL_BIT_POS);
#endif /* !defined(CY_DEVICE_CCG7D) && !defined(CY_DEVICE_CCG7S) && !defined(CY_DEVICE_SERIES_WLC1) */

    /* Restore reference voltage for OV comparator to 6V equivalent. */
#if (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
    vref = VBUS_OVP_DETECT_MIN / VBUS_C_20_PER_DIV;
#elif defined(CY_DEVICE_CCG6DF_CFP)
    vref = VBUS_OVP_DETECT_MIN / VBUS_C_8_PER_DIV;
#else /* defined (CY_DEVICE_CCG6) */
    vref = VBUS_OVP_DETECT_MIN / VBUS_C_10_PER_DIV;
#endif /* defined(CY_DEVICE_CCG3PA)  */
    vref = (vref - OVP_REF_VOLT_MIN) / OVP_REF_VOLT_STEP;

    {
        /* OV comparator on port 0 uses VREF[3]. */
#if defined(CY_DEVICE_CCG6DF_CFP)
        pd->pd_ref_mux_ctrl_0 = (pd->pd_ref_mux_ctrl_0 & ~PDSS_PD_REF_MUX_CTRL_0_VREF_SEL3_MASK) | (vref << PDSS_PD_REF_MUX_CTRL_0_VREF_SEL3_POS);
#else
        pd->refgen_1_ctrl = (pd->refgen_1_ctrl & ~PDSS_REFGEN_1_CTRL_SEL3_MASK) | (vref << PDSS_REFGEN_1_CTRL_SEL3_POS);
#endif /* defined(CY_DEVICE_CCG6DF_CFP) */
    }

    /* Clear callback. */
   context->vbusOvpCbk = NULL;

    Cy_SysLib_ExitCriticalSection(state);

#if PSVP_FPGA_ENABLE 
#if (!defined(CY_DEVICE_CCG6DF_CFP))
    ctrl_inf_ovp_disable();
#endif /* (!defined(CY_DEVICE_CCG6DF_CFP)) */
#endif /* PSVP_FPGA_ENABLE */

#elif defined(CY_IP_M0S8USBPD)

    PPDSS_REGS_T pd = context->base;
    uint32_t regval;

    Cy_USBPD_Fault_FetAutoModeDisable (context, pctrl, CY_USBPD_VBUS_FILTER_ID_OV);

    /* Disable the UVOV block, and set the OV threshold to 6V by default. */
    regval = pd->uvov_ctrl;
    regval = ((regval & ~PDSS_UVOV_CTRL_OV_IN_MASK) | (UVOV_CODE_6V0 << PDSS_UVOV_CTRL_OV_IN_POS));
    pd->uvov_ctrl = regval;

    /* Disable and clear UVOV interrupts. */
    pd->intr3_mask &= ~PDSS_INTR3_POS_OV_CHANGED;
    pd->intr3 = PDSS_INTR3_POS_OV_CHANGED;

    /* Clear callback. */
   context->vbusOvpCbk = NULL;

#endif /* CY_IP */
#else
    CY_UNUSED_PARAMETER(context);
    CY_UNUSED_PARAMETER(pctrl);
#endif /* PDL_VBUS_OVP_ENABLE */
}

/*******************************************************************************
* Function Name: Cy_USBPD_Fault_Vbus_OvpIntrHandler
****************************************************************************//**
*
* VBUS OVP fault interrupt handler function.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
*******************************************************************************/
void Cy_USBPD_Fault_Vbus_OvpIntrHandler(cy_stc_usbpd_context_t *context)
{
#if PDL_VBUS_OVP_ENABLE
    PPDSS_REGS_T pd = context->base;

#if defined(CY_IP_MXUSBPD)
    /* Disable and clear OV interrupt. */
    pd->intr5_mask &= ~(1U << CY_USBPD_VBUS_FILTER_ID_OV);
    pd->intr5 = 1U << CY_USBPD_VBUS_FILTER_ID_OV;

    /* Invoke OVP callback. */
    if (context->vbusOvpCbk != NULL)
    {
        context->vbusOvpCbk(context, true);
    }
#elif defined(CY_IP_M0S8USBPD)
    /* Disable and clear UVOV interrupts. */
    pd->intr3_mask &= ~PDSS_INTR3_POS_OV_CHANGED;
    pd->intr3 = PDSS_INTR3_POS_OV_CHANGED;

    /* Invoke OVP callback. */
    if (context->vbusOvpCbk != NULL)
    {
        context->vbusOvpCbk(context, true);
    }
#endif /* CY_IP */
#else
    CY_UNUSED_PARAMETER(context);
#endif /* PDL_VBUS_OVP_ENABLE */
}


#if PDL_VBUS_UVP_ENABLE
/* UVP min reference voltage in mV. */
#if defined(CY_DEVICE_CCG6DF_CFP)
#define UVP_REF_VOLT_MIN            (130)
#else
#define UVP_REF_VOLT_MIN            (200)
#endif /* defined(CY_DEVICE_CCG6DF_CFP) */

/* UVP min reference voltage on Port #1. */
#define UVP_REF_VOLT_MIN_P1         (130)

/* UVP Reference voltage step size in mV. */
#define UVP_REF_VOLT_STEP           (10)

/*
 * Minimum supported voltage for UVP. Any voltage lower may cause system to
 * not work as expected; the block references can get affected. This is now
 * limited to 3.1V.
 */
#define UVP_MIN_VOLT                (3100)

/*
 * Minimum supported voltage for UVP. Any voltage lower may cause system to
 * not work as expected; the block references can get affected. This is now
 * limited to 3V for Buck-Only solutions.
 */
#define UVP_MIN_VOLT_BUCK_ONLY      (3000)

#define MAX_UVP_DEBOUNCE_CYCLES     (0x20u)
#endif /* PDL_VBUS_UVP_ENABLE */

/*******************************************************************************
* Function Name: Cy_USBPD_Fault_Vbus_UvpEnable
****************************************************************************//**
*
* Enable Under Voltage Protection (UVP) control using the internal UV-OV block.
* UVP is only expected to be used while PD-port is the power source.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \param volt
* Contract Voltage in mV units.
*
* \param cb
* Callback function to be called on fault detection.
*
* \param pctrl
* Flag indicating the type of gate driver to be controlled, true for
* P_CTRL and false for C_CTRL.
*
*******************************************************************************/
void Cy_USBPD_Fault_Vbus_UvpEnable(cy_stc_usbpd_context_t *context, uint16_t volt, cy_cb_vbus_fault_t cb, bool pctrl)
{
#if PDL_VBUS_UVP_ENABLE && defined(CY_IP_MXUSBPD)
    uint16_t threshold, vref;
    uint16_t uvpLimit = UVP_MIN_VOLT;
    uint32_t regVal = 0;
    PPDSS_REGS_T pd = context->base;
    uint8_t filterSel;
    

#if (!defined(CY_DEVICE_CCG7S) && !defined(CY_DEVICE_CCG7D) && !defined(CY_DEVICE_SERIES_WLC1))
    filterSel = (GET_VBUS_UVP_TABLE(context)->debounce + 1) / 2;
    filterSel = CY_USBPD_GET_MIN(filterSel, MAX_UVP_DEBOUNCE_CYCLES);
#else
#if CY_USE_CONFIG_TABLE
    pwr_params_t *pwr_cfg = pd_get_ptr_pwr_tbl(context);
#else
    cy_stc_buck_boost_cfg_t *pwr_cfg = context->usbpdConfig->buckBoostConfig;
#endif
    /* Convert debounce delay in us to filter clock cycles. */
    filterSel = GET_VBUS_UVP_TABLE(context)->debounce;
    filterSel = (uint8_t)system_get_clk_filt_sel(context->port, (((uint16_t) filterSel) * 10u));
#endif /* (defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1) || defined(CY_DEVICE_CCG7D)) */

    if (GET_VBUS_UVP_TABLE(context)->mode == VBUS_UVP_MODE_INT_COMP_AUTOCTRL)
    {
         Cy_USBPD_Fault_FetAutoModeDisable (context, pctrl, CY_USBPD_VBUS_FILTER_ID_UV);
    }

    /* Set up UVP callback. */
    context->vbusUvpCbk = cb;

    /* Calculate required VBUS for UVP. */
    threshold = ((volt * GET_VBUS_UVP_TABLE(context)->threshold) / 100);
#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
    if(pwr_cfg->buck_boost_operating_mode == BB_FORCED_BUCK)
    {
        uvpLimit = UVP_MIN_VOLT_BUCK_ONLY;
    }
#endif /* (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) */
    /* Ensure that we are within the limits. */
    if (threshold < uvpLimit)
    {
        threshold = uvpLimit;
    }

#if (!defined(CY_DEVICE_CCG7S) && !defined(CY_DEVICE_SERIES_WLC1) && !defined(CY_DEVICE_CCG7D))
    regVal = pd->amux_nhv_ctrl;
#endif /*!defined(CY_DEVICE_CCG7S) && !defined(CY_DEVICE_SERIES_WLC1) && !defined(CY_DEVICE_CCG7D) */

#if defined(CY_DEVICE_CCG3PA)

#if !PMG1_FLIPPED_FET_CTRL
    /* Choose VBUS_C as source for AMUX. */
    regVal &= ~(AMUX_UV_VBUS_SEL_MASK);
#else
    /* Choose VBUS_IN as source for AMUX. */
    regVal |= AMUX_UV_VBUS_SEL_MASK;
#endif /* PMG1_FLIPPED_FET_CTRL */
#endif /* defined(CY_DEVICE_CCG3PA) */

#if (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))

    /*
     * Internal divider to be used depends on VBUS to be measured. For VBUS <
     * VBUS_DIV_20_PER_MAX_VOLT, use 20% divider and for greater, use 10% divider.
     */
    if (threshold <= VBUS_DIV_20_PER_MAX_VOLT)
    {
        vref = threshold / VBUS_C_20_PER_DIV;
        /* Connect output to 20% */
#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
        pd->amux_ctrl |= (1u << AMUX_UV_DIV_SEL_BIT_POS);
#else /* CCG3PA */
        regVal |= (1U << AMUX_UV_DIV_SEL_BIT_POS);
#endif /* CCGx */
    }
    else
    {
        vref = threshold / VBUS_C_10_PER_DIV;
        /* Connect output to 10% */
#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
        pd->amux_ctrl &= ~((uint32_t)1u << AMUX_UV_DIV_SEL_BIT_POS);
#else /* CCG3PA */
        regVal &= ~(1U << AMUX_UV_DIV_SEL_BIT_POS);
#endif /* CCGx */
    }
#endif /* (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) */

#if (defined(CY_DEVICE_CCG6))
    /* Use 10% of VBus as input to UVP comparator. */
    regVal &= 0xFFFFFFFD;

    vref = threshold / VBUS_C_10_PER_DIV;
#elif defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP)
    /* Use 8% of VBus as input to UVP comparator. */
    regVal &= ~(1U << AMUX_UV_DIV_SEL_BIT_POS);

    vref = threshold / VBUS_C_8_PER_DIV;
#endif /* (defined(CY_DEVICE_CCG6)) */

#if (!defined(CY_DEVICE_CCG7S) && !defined(CY_DEVICE_SERIES_WLC1) && !defined(CY_DEVICE_CCG7D))
    pd->amux_nhv_ctrl = regVal;
#endif /*!defined(CY_DEVICE_CCG7S) && !defined(CY_DEVICE_SERIES_WLC1) && !defined(CY_DEVICE_CCG7D) */

    /* Program reference voltage for UV comparator. */
    vref = ((vref - UVP_REF_VOLT_MIN) / UVP_REF_VOLT_STEP);

#if defined(CY_DEVICE_CCG6DF_CFP)
    regVal = pd->pd_ref_mux_ctrl_0;
    regVal &= ~(PDSS_PD_REF_MUX_CTRL_0_VREF_SEL2_MASK);
    regVal |= (vref << PDSS_PD_REF_MUX_CTRL_0_VREF_SEL2_POS);
    pd->pd_ref_mux_ctrl_0 = regVal;
#else
    regVal = pd->refgen_1_ctrl;
    regVal &= ~(PDSS_REFGEN_1_CTRL_SEL2_MASK);
    regVal |= (vref << PDSS_REFGEN_1_CTRL_SEL2_POS);
    pd->refgen_1_ctrl = regVal;
#endif /* defined(CY_DEVICE_CCG6DF_CFP) */

    /* Turn on comparator. */
    pd->comp_ctrl[CY_USBPD_VBUS_COMP_ID_UV] |= PDSS_COMP_CTRL_COMP_ISO_N;
    pd->comp_ctrl[CY_USBPD_VBUS_COMP_ID_UV] &= ~PDSS_COMP_CTRL_COMP_PD;

    Cy_SysLib_DelayUs(10);

    /* Filter configuration. */
    pd->intr5_filter_cfg[CY_USBPD_VBUS_FILTER_ID_UV] &= ~PDSS_INTR5_FILTER_CFG_FILT_EN;
    /* Reset filter to 1. */
    regVal = pd->intr5_filter_cfg[CY_USBPD_VBUS_FILTER_ID_UV] & ~(PDSS_INTR5_FILTER_CFG_FILT_CFG_MASK
            | PDSS_INTR5_FILTER_CFG_FILT_SEL_MASK | PDSS_INTR5_FILTER_CFG_DPSLP_MODE |
            PDSS_INTR5_FILTER_CFG_FILT_BYPASS);
    regVal |= PDSS_INTR5_FILTER_CFG_FILT_RESET;

    /* Set filter clock cycles if filter is required. */
    if (filterSel)
    {
        /* Subtracting 1 from filter clock cycle value as 0 translates to 1-2 clock cycles. */
        regVal |= ((((((uint8_t)filterSel - 1u) != 0u) ? ((uint32_t)filterSel - 1u) : 1u) & (uint32_t)0x1Fu) << PDSS_INTR5_FILTER_CFG_FILT_SEL_POS);
        /* Set edge detection. */
        regVal |= ((uint8_t)CY_USBPD_VBUS_FILTER_CFG_POS_DIS_NEG_EN << PDSS_INTR5_FILTER_CFG_FILT_CFG_POS);
        regVal |= PDSS_INTR5_FILTER_CFG_FILT_EN | PDSS_INTR5_FILTER_CFG_DPSLP_MODE;
    }
    else
    {
        regVal |= PDSS_INTR5_FILTER_CFG_FILT_BYPASS;
    }

    pd->intr5_filter_cfg[CY_USBPD_VBUS_FILTER_ID_UV] = regVal;

    /* Clear interrupt. */
    pd->intr5 = (1U << CY_USBPD_VBUS_FILTER_ID_UV);

    /* Enable Interrupt. */
    pd->intr5_mask |= (1U << CY_USBPD_VBUS_FILTER_ID_UV);

    /* Handle Auto mode. */
    if (GET_VBUS_UVP_TABLE(context)->mode == VBUS_UVP_MODE_INT_COMP_AUTOCTRL)
    {
        Cy_USBPD_Fault_FetAutoModeEnable (context, pctrl, CY_USBPD_VBUS_FILTER_ID_UV);
    }
#else
    CY_UNUSED_PARAMETER(context);
    CY_UNUSED_PARAMETER(pctrl);
    CY_UNUSED_PARAMETER(volt);
    (void)(cy_cb_vbus_fault_t)cb;
#endif /* PDL_VBUS_UVP_ENABLE && CY_IP */
}


/*******************************************************************************
* Function Name: Cy_USBPD_Fault_Vbus_UvpDisable
****************************************************************************//**
*
* Disable Under Voltage Protection (UVP) control.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \param pctrl
* Flag indicating the type of gate driver to be controlled, true for
* P_CTRL and false for C_CTRL.
*
*******************************************************************************/
void Cy_USBPD_Fault_Vbus_UvpDisable(cy_stc_usbpd_context_t *context, bool pctrl)
{
#if PDL_VBUS_UVP_ENABLE && defined(CY_IP_MXUSBPD)
    PPDSS_REGS_T pd = context->base;
    uint32_t state = 0;

    state = Cy_SysLib_EnterCriticalSection ();

    /* Clear AUTO MODE OVP detect. */
    if (GET_VBUS_UVP_TABLE(context)->mode == VBUS_UVP_MODE_INT_COMP_AUTOCTRL)
    {
        Cy_USBPD_Fault_FetAutoModeDisable (context, pctrl, CY_USBPD_VBUS_FILTER_ID_UV);
    }


    /* Disable comparator. */
    pd->comp_ctrl[CY_USBPD_VBUS_COMP_ID_UV] &= ~PDSS_COMP_CTRL_COMP_ISO_N;
    pd->comp_ctrl[CY_USBPD_VBUS_COMP_ID_UV] |= PDSS_COMP_CTRL_COMP_PD;

    /* Disable filter. */
    pd->intr5_filter_cfg[CY_USBPD_VBUS_FILTER_ID_UV] &= ~(PDSS_INTR5_FILTER_CFG_FILT_EN |
        PDSS_INTR5_FILTER_CFG_FILT_CFG_MASK | PDSS_INTR5_FILTER_CFG_FILT_SEL_MASK |
        PDSS_INTR5_FILTER_CFG_FILT_BYPASS);

    /* Disable and clear UV interrupts. */
    pd->intr5_mask &= ~(1U << CY_USBPD_VBUS_FILTER_ID_UV);
    pd->intr5 = 1U << CY_USBPD_VBUS_FILTER_ID_UV;

    /* Clear callback. */
    context->vbusUvpCbk = NULL;

    Cy_SysLib_ExitCriticalSection (state);
#else
    CY_UNUSED_PARAMETER(context);
    CY_UNUSED_PARAMETER(pctrl);
#endif /* PDL_VBUS_UVP_ENABLE && CY_IP */
}

/*******************************************************************************
* Function Name: Cy_USBPD_Fault_Vbus_UvpIntrHandler
****************************************************************************//**
*
* VBUS UVP fault interrupt handler function.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
*******************************************************************************/
void Cy_USBPD_Fault_Vbus_UvpIntrHandler(cy_stc_usbpd_context_t *context)
{
#if PDL_VBUS_UVP_ENABLE && defined(CY_IP_MXUSBPD)
    PPDSS_REGS_T pd = context->base;

    /* Disable and clear UV interrupt. */
    pd->intr5_mask &= ~(1U << CY_USBPD_VBUS_FILTER_ID_UV);
    pd->intr5 = 1U << CY_USBPD_VBUS_FILTER_ID_UV;

    /* Invoke UVP callback. */
    if (context->vbusUvpCbk != NULL)
    {
        context->vbusUvpCbk(context, false);
    }
#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
            /*
             * UVP comparator is used for buck-boost startup.
             * Invoke Buck-Boost callback.
             */
            if (context->bbOvpCbk != NULL)
            {
                context->bbOvpCbk (context, true);
            }
#endif /* (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) */
#else
    CY_UNUSED_PARAMETER(context);
#endif /* PDL_VBUS_UVP_ENABLE && CY_IP */
}

#if defined(PDL_VBUS_OCP_ENABLE)
/* Maximum limit on the VBUS current (in 10mA units) as required by compliance. */
#if !VBUS_DEFINE_SOLN_MAX_CURRENT_EN
#define VBUS_MAX_CURRENT                    (550u)
#endif /* !VBUS_DEFINE_SOLUTION_OCP_LIMIT */

#define VBUS_OCP_MODE_EXT                   (0u)  /**< OCP through external hardware. */
#define VBUS_OCP_MODE_INT                   (1u)  /**< Internal OCP without software debounce or hardware gate control. */
#define VBUS_OCP_MODE_INT_AUTOCTRL          (2u)  /**< Internal OCP with hardware gate control. */
#define VBUS_OCP_MODE_INT_SW_DB             (3u)  /**< Internal OCP with software debounce. */
#define VBUS_OCP_MODE_POLLING               (4u)  /**< Solution level polling based OCP. */

#if defined(CY_DEVICE_CCG6)
#define SFLASH_OCP_TRIM_AV50_1A_HOT         (0x0FFFF402u)
#define SFLASH_OCP_TRIM_AV20_1A_HOT         (0x0FFFF409u)
#define SFLASH_OCP_TRIM_AV50_1A_COLD        (0x0FFFF412u)
#define SFLASH_OCP_TRIM_AV20_1A_COLD        (0x0FFFF417u)

#define SFLASH_OCP_TRIM_TBL_1A_OFFSET       (0u)
#define SFLASH_OCP_TRIM_TBL_3A_OFFSET       (2u)
#endif /* defined(CY_DEVICE_CCG6) */

#define SFLASH_OCP_TRIM_ROOM_FLAG           (0x0FFFF48Au)
#define SFLASH_OCP_TRIM_5V_2A_ROOM          (0x0FFFF45Eu)
#define SFLASH_OCP_TRIM_5V_2A_HOT           (0x0FFFF432u)
#define SFLASH_OCP_TRIM_5V_2A_COLD          (0x0FFFF448u)
#define SFLASH_OCP_TRIM_TBL_2A_OFFSET       (0u)
#define SFLASH_OCP_TRIM_TBL_4A_OFFSET       (2u)
#define SFLASH_OCP_TRIM_5V_0P9A_HOT         (0x0FFFF431u)
#define SFLASH_OCP_TRIM_5V_0P9A_COLD        (0x0FFFF447u)
#define SFLASH_OCP_TRIM_TBL_0P9A_OFFSET     (0u)
#define SFLASH_OCP_TRIM_TBL_2P0A_OFFSET     (1u)
#endif /* defined(PDL_VBUS_OCP_ENABLE) */

/* Macros for OCP table. */
#if defined(CY_DEVICE_CCG3)
#define MA_PER_UNIT                     (10u)
#define VSENSE_MIN                      (10)
#define VSENSE_MAX                      (65)
/* INTR3 filter configurations. */
#define PDSS_INTR3_FILT_SEL_4_CLK_LF 1
#define PDSS_INTR3_FILT_SEL_5_CLK_LF 2
#define PDSS_INTR3_FILT_SEL_6_CLK_LF 3

#endif /* (defined(CY_DEVICE_CCG3) */

#if (PDL_VBUS_OCP_ENABLE && defined(CY_DEVICE_CCG3))
/*
 * Note: The high side CSA block used for Over-Current detection in CCG3 and CCG5 devices has
 * a non-linear measurement error. The error is as high as 26% at low sense voltages and reduces
 * to the order of 4% at higher sense voltages.
 *
 * The following table has been updated to prevent false Over-Current detection due to a worst
 * case positive measurement error. This means that the nominal Over-Current detection threshold
 * is set much higher than the expected value for low sense voltages.
 */
static const uint8_t csa_tab[] =
/* Vsense (mv) (for 10mOhm Rsense), av1(:3)-bw(:2), vref_sel code(6). */
{
    /* 10, */  0x1F,  5,        /* 100, 1.35  */
    /* 11, */  0x1F, 19,        /* 100, 1.49  */
    /* 12, */  0x1F, 32,        /* 100, 1.62  */
    /* 13, */  0x1F, 46,        /* 100, 1.76  */
    /* 14, */  0x1F, 59,        /* 100, 1.89  */
    /* 15, */  0x1B, 12,        /* 70,  1.42  */
    /* 16, */  0x1B, 21,        /* 70,  1.51  */
    /* 17, */  0x1B, 31,        /* 70,  1.61  */
    /* 18, */  0x1B, 40,        /* 70,  1.70  */
    /* 19, */  0x1B, 50,        /* 70,  1.80  */
    /* 20, */  0x1B, 39,        /* 70,  1.69  */
    /* 21, */  0x1B, 47,        /* 70,  1.77  */
    /* 22, */  0x1B, 55,        /* 70,  1.85  */
    /* 23, */  0x1B, 63,        /* 70,  1.93  */
    /* 24, */  0x16, 15,        /* 50,  1.45  */
    /* 25, */  0x16, 15,        /* 50,  1.45  */
    /* 26, */  0x16, 21,        /* 50,  1.51  */
    /* 27, */  0x16, 27,        /* 50,  1.57  */
    /* 28, */  0x16, 33,        /* 50,  1.63  */
    /* 29, */  0x16, 39,        /* 50,  1.69  */
    /* 30, */  0x16, 44,        /* 50,  1.74  */
    /* 31, */  0x16, 50,        /* 50,  1.80  */
    /* 32, */  0x16, 56,        /* 50,  1.86  */
    /* 33, */  0x16, 62,        /* 50,  1.92  */
    /* 34, */  0x12, 28,        /* 40,  1.58  */
    /* 35, */  0x12, 33,        /* 40,  1.63  */
    /* 36, */  0x12, 30,        /* 40,  1.60  */
    /* 37, */  0x12, 34,        /* 40,  1.64  */
    /* 38, */  0x12, 39,        /* 40,  1.69  */
    /* 39, */  0x12, 43,        /* 40,  1.73  */
    /* 40, */  0x12, 48,        /* 40,  1.78  */
    /* 41, */  0x12, 52,        /* 40,  1.82  */
    /* 42, */  0x12, 57,        /* 40,  1.87  */
    /* 43, */  0x12, 61,        /* 40,  1.91  */
    /* 44, */  0x0D, 17,        /* 30,  1.47  */
    /* 45, */  0x0D, 20,        /* 30,  1.50  */
    /* 46, */  0x0D, 23,        /* 30,  1.53  */
    /* 47, */  0x0D, 27,        /* 30,  1.57  */
    /* 48, */  0x0D, 30,        /* 30,  1.60  */
    /* 49, */  0x0D, 33,        /* 30,  1.63  */
    /* 50, */  0x0D, 37,        /* 30,  1.67  */
    /* 51, */  0x0D, 40,        /* 30,  1.70  */
    /* 52, */  0x0D, 43,        /* 30,  1.73  */
    /* 53, */  0x0D, 47,        /* 30,  1.77  */
    /* 54, */  0x0D, 44,        /* 30,  1.74  */
    /* 55, */  0x0D, 47,        /* 30,  1.77  */
    /* 56, */  0x0D, 51,        /* 30,  1.81  */
    /* 57, */  0x0D, 54,        /* 30,  1.84  */
    /* 58, */  0x0D, 57,        /* 30,  1.87  */
    /* 59, */  0x0D, 60,        /* 30,  1.90  */
    /* 60, */  0x0D, 63,        /* 30,  1.93  */
    /* 61, */  0x09,  1,        /* 20,  1.31  */
    /* 62, */  0x09,  3,        /* 20,  1.33 */
    /* 63, */  0x09,  5,        /* 20,  1.35  */
    /* 64, */  0x09,  8,        /* 20,  1.38  */
    /* 65, */  0x09, 10         /* 20,  1.40  */
/*
 * For an Rsense of 10 mOhm this is enough.
 */
};
#endif /* (defined(CCG3) && PDL_VBUS_OCP_ENABLE */

#if PDL_VBUS_OCP_ENABLE

#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))

#define CCG_FLASH_ROW_SHIFT_NUM                 (8u)

/* Trims flag */
#define OCP_TRIM_ROOM_FLAG(port) (*(volatile uint8_t *)((0x0ffff45Du) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))

#define OCP_TRIM_1A_ROOM(port) (*(volatile uint8_t *)((0x0ffff456u) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))
#define OCP_TRIM_2A_ROOM(port) (*(volatile uint8_t *)((0x0ffff457u) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))
#define OCP_TRIM_3A_ROOM(port) (*(volatile uint8_t *)((0x0ffff458u) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))
#define OCP_TRIM_4A_ROOM(port) (*(volatile uint8_t *)((0x0ffff459u) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))
#define OCP_TRIM_5A_ROOM(port) (*(volatile uint8_t *)((0x0ffff45Au) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))

#define OCP_TRIM_1A_H(port) (*(volatile uint8_t *)((0x0ffff431u) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))
#define OCP_TRIM_2A_H(port) (*(volatile uint8_t *)((0x0ffff433u) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))
#define OCP_TRIM_3A_H(port) (*(volatile uint8_t *)((0x0ffff434u) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))
#define OCP_TRIM_4A_H(port) (*(volatile uint8_t *)((0x0ffff435u) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))
#define OCP_TRIM_5A_H(port) (*(volatile uint8_t *)((0x0ffff436u) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))

#define OCP_TRIM_1A_C(port) (*(volatile uint8_t *)((0x0ffff445u) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))
#define OCP_TRIM_2A_C(port) (*(volatile uint8_t *)((0x0ffff447u) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))
#define OCP_TRIM_3A_C(port) (*(volatile uint8_t *)((0x0ffff448u) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))
#define OCP_TRIM_4A_C(port) (*(volatile uint8_t *)((0x0ffff449u) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))
#define OCP_TRIM_5A_C(port) (*(volatile uint8_t *)((0x0ffff44Au) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))

#define I_1P3A      (130u)
#define I_2P6A      (260u)
#define I_3P9A      (390u)
#define I_5P2A      (520u)
#define I_6P5A      (650u)
#elif defined(CY_DEVICE_CCG6DF_CFP)

#define CCG_FLASH_ROW_SHIFT_NUM                 (8u)

#define OCP_TRIM_1A_R(port) (*(volatile uint8_t *)((0x0ffff431u) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))

#define I_1P3A      (130u)

#endif /* defined(CY_DEVICE_CCG7D) */
#endif /* PDL_VBUS_OCP_ENABLE */

/*******************************************************************************
* Function Name: Cy_USBPD_Fault_Vbus_OcpEnable
****************************************************************************//**
*
* Enable Over Current Protection (OCP) control using the internal Current Sense Amplifier.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \param current
* Contract current in mA units.
*
* \param cb
* Callback function to be called on fault detection.
*
*******************************************************************************/
void Cy_USBPD_Fault_Vbus_OcpEnable(cy_stc_usbpd_context_t *context, uint32_t current, cy_cb_vbus_fault_t cb)
{
#if ((PDL_VBUS_OCP_ENABLE) && (defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP) || defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_CCG3) || defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)))
    PPDSS_REGS_T pd = context->base;
    uint32_t vsense = 0;
    uint32_t vrefSel = 0;
    uint32_t state = 0;
    uint32_t regval = 0;
#if (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
    uint8_t gainSel = 0;
#endif /* defined(CY_DEVICE_CCG6) */
    uint8_t filterSel = 0;
#if defined(CY_DEVICE_PMG1S3)
    PPDSS_TRIMS_REGS_T trimRegs = context->trimsBase;
#endif /* defined(CY_DEVICE_PMG1S3) */

#if (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP))
    /* Never set current less than 100mA */
    if (current < 10u)
    {
        current = 10u;
    }
#elif (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_SERIES_WLC1))
#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
    uint8_t ocp_trim_1A;
    uint8_t ocp_trim_2A;
    uint8_t ocp_trim_3A;
    uint8_t ocp_trim_4A;
    uint8_t ocp_trim_5A;
    int32_t vref_1;
    int32_t vref_2;
    int32_t vref_sel_signed_32;
    uint16_t cur_1;
#endif /* (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) */

    /* Never set current less than 900mA */
    if(current < 90u)
    {
        current = 90u;
    }
#endif /* CY_DEVICE */ 

#if defined(CY_DEVICE_CCG6DF_CFP)
    uint32_t ocp_trim_1A;
#endif /* CY_DEVICE_CCG6DF_CFP */

    /* Set up OCP callback. */
    context->vbusOcpCbk = cb;

    /* Calculate required current for OCP. */
    vsense = current + ((current * GET_VBUS_OCP_TABLE(context)->threshold) / 100u);

#if ((!defined(CY_DEVICE_SERIES_PMG1B1)) && (!defined(CY_DEVICE_CCG3PA_VBUS_OCP_UNLIM)))
    if(vsense > VBUS_MAX_CURRENT)
    {
        vsense = VBUS_MAX_CURRENT;
    }
#endif /* ((!defined(CY_DEVICE_SERIES_PMG1B1)) && (!defined(CY_DEVICE_CCG3PA_VBUS_OCP_UNLIM))) */

#if defined(CY_DEVICE_CCG6)
    /*
     * The voltage reference to be applied on the CSA output stage is determined
     * based on data collected during device test and programmed into the SFLASH.
     *
     * Reference data is provided for current settings of 1.3 A, 2.6 A, 3.9 A, 5.2 A and 6.5 A.
     * The following code uses the 1.3 A and 3.9 A settings to plot a line which maps current values
     * to the corresponding reference voltages. We then pick the value of reference voltage corresponding
     * to the current limit from the line.
     */

    const uint8_t *sflash_ocp_trim_hot;
    const uint8_t *sflash_ocp_trim_cold;
    uint32_t i = 0;
    int c = 0;

    /* Set the gain based on the selected Rsense value. */
    if (GET_VBUS_OCP_TABLE(context)->senseRes == 10u)
    {
        sflash_ocp_trim_hot  = (const uint8_t *)(SFLASH_OCP_TRIM_AV20_1A_HOT + (((uint32_t)context->port) << 7));
        sflash_ocp_trim_cold = (const uint8_t *)(SFLASH_OCP_TRIM_AV20_1A_COLD + (((uint32_t)context->port) << 7));

        /* Interpolating the OCP current trim value using line equation: vref_sel = vsense*m + c */
        i = (
                (
                 (uint32_t)sflash_ocp_trim_hot[SFLASH_OCP_TRIM_TBL_3A_OFFSET] +
                 (uint32_t)sflash_ocp_trim_cold[SFLASH_OCP_TRIM_TBL_3A_OFFSET]
                ) -
                (
                 (uint32_t)sflash_ocp_trim_hot[SFLASH_OCP_TRIM_TBL_1A_OFFSET] +
                 (uint32_t)sflash_ocp_trim_cold[SFLASH_OCP_TRIM_TBL_1A_OFFSET]
                )
            ) >> 1u;

        c = ((int32_t)sflash_ocp_trim_hot[SFLASH_OCP_TRIM_TBL_1A_OFFSET] +
                (int32_t)sflash_ocp_trim_cold[SFLASH_OCP_TRIM_TBL_1A_OFFSET] - (int32_t)i) / 2;

        vsense  = (vsense * 2u) / 1u;
        vrefSel = ((i * vsense) / 520u);
        if (c < 0)
        {
            int32_t temp = -c;

            vrefSel -= (uint32_t)temp;
        }
        else
        {
            vrefSel += (uint32_t)c;
        }

        gainSel = 0x09u;        /* Constant Gain = 20 (Av1:010, bw: 01) */
    }
    else
    {
        sflash_ocp_trim_hot  = (const uint8_t *)(SFLASH_OCP_TRIM_AV50_1A_HOT + (((uint32_t)context->port) << 7));
        sflash_ocp_trim_cold = (const uint8_t *)(SFLASH_OCP_TRIM_AV50_1A_COLD + (((uint32_t)context->port) << 7));

        /* Interpolating the OCP current trim value using line equation: vref_sel = vsense*m + c */
        i = (
                (
                 (uint32_t)sflash_ocp_trim_hot[SFLASH_OCP_TRIM_TBL_3A_OFFSET] +
                 (uint32_t)sflash_ocp_trim_cold[SFLASH_OCP_TRIM_TBL_3A_OFFSET]
                ) -
                (
                 (uint32_t)sflash_ocp_trim_hot[SFLASH_OCP_TRIM_TBL_1A_OFFSET] +
                 (uint32_t)sflash_ocp_trim_cold[SFLASH_OCP_TRIM_TBL_1A_OFFSET]
                )
            ) >> 1u;

        c = ((int32_t)sflash_ocp_trim_hot[SFLASH_OCP_TRIM_TBL_1A_OFFSET] +
                (int32_t)sflash_ocp_trim_cold[SFLASH_OCP_TRIM_TBL_1A_OFFSET] - (int32_t)i) / 2;
        vsense   = (vsense * 5u) >> 1u;
        vrefSel = ((i * vsense) / 650u);
        if (c < 0)
        {
            int32_t temp = -c;

            vrefSel -= (uint32_t)temp;
        }
        else
        {
            vrefSel += (uint32_t)c;
        }

        gainSel = 0x16u;        /* Constant gain = 50 (Av1:101, bw: 10) */
    }

    if(GET_VBUS_OCP_TABLE(context)->mode == VBUS_OCP_MODE_INT_AUTOCTRL)
    {
        filterSel = (context->usbpdConfig->vbusOvpConfig->debounce + 1u) / 2u;
        if(filterSel > 31u)
        {
            filterSel = 31u;
        }
    }
    state = Cy_SysLib_EnterCriticalSection();

    if(GET_VBUS_OCP_TABLE(context)->mode == VBUS_OCP_MODE_INT_AUTOCTRL)
    {
        Cy_USBPD_Fault_FetAutoModeDisable(context, true, CY_USBPD_VBUS_FILTER_ID_HSCSA_OCP);
    }

    Cy_USBPD_SetRefgenVoltage (context, (uint8_t)vrefSel, (uint8_t)CY_USBPD_VREF_CSA_OCP);

    regval = pd->csa_scp_0_ctrl;

    /* Bring the CSA out of power-down, enable outputs and clear the gain setting. */
    regval &= ~(PDSS_CSA_SCP_0_CTRL_PD_CSA | PDSS_CSA_SCP_0_CTRL_AV1_MASK | PDSS_CSA_SCP_0_CTRL_BW_MASK);
    regval |= PDSS_CSA_SCP_0_CTRL_SEL_OUT_D | PDSS_CSA_SCP_0_CTRL_CSA_ISO_N;

    /* Set the gain and bandwidth based on requirement. */
    regval |= ((((uint32_t)gainSel >> 2UL) & 0x07UL) << PDSS_CSA_SCP_0_CTRL_AV1_POS);
    regval |= ((gainSel & 0x03UL) << PDSS_CSA_SCP_0_CTRL_BW_POS);

    pd->csa_scp_0_ctrl = regval;

#elif defined(CY_DEVICE_PMG1S3)
    const uint8_t *sflash_ocp_trim_hot;
    const uint8_t *sflash_ocp_trim_cold;
#if defined(USE_OCP_ROOM_TRIMS)  
    const uint8_t *sflash_ocp_trim_room;
#endif /* defined(USE_OCP_ROOM_TRIMS) */ 
    uint32_t i = 0;
    int c = 0;
    int temp;

#if defined(USE_OCP_ROOM_TRIMS)  
    if (*((volatile uint8_t *)(SFLASH_OCP_TRIM_ROOM_FLAG + (uint16_t)(context->port * 0x100u))) == 1u)
    {
        sflash_ocp_trim_room  = (const uint8_t *)(SFLASH_OCP_TRIM_5V_2A_ROOM + (uint16_t)(context->port * 0x100u));

        i  = (uint32_t)sflash_ocp_trim_room[SFLASH_OCP_TRIM_TBL_4A_OFFSET] - 
             (uint32_t)sflash_ocp_trim_room[SFLASH_OCP_TRIM_TBL_2A_OFFSET];

        /* Take the difference of currents used. 4.8A - 2.4A */
        c = 240;

        vrefSel = sflash_ocp_trim_room[SFLASH_OCP_TRIM_TBL_2A_OFFSET];

        temp = (int32_t)vsense - 240;
        temp = (temp * (int32_t)i) / c;
        if (temp < 0)
        {
            int32_t value = -temp;
            vrefSel -= (uint32_t)value;
        }
        else
        {
            vrefSel += (uint32_t)temp;
        }
    }
    else
#endif /* USE_OCP_ROOM_TRIMS */ 
    {
        /* For 1A and less current use the 1A trim values. */
        if(current <= 100)
        {
            sflash_ocp_trim_hot  = (const uint8_t *)(SFLASH_OCP_TRIM_5V_0P9A_HOT + (uint16_t)(context->port * 0x100u));
            sflash_ocp_trim_cold = (const uint8_t *)(SFLASH_OCP_TRIM_5V_0P9A_COLD + (uint16_t)(context->port * 0x100u));

            /* Interpolating the OCP current trim value using line equation: vref_sel = vsense*m + c */
            i = (
                    (
                     (uint32_t)sflash_ocp_trim_hot[SFLASH_OCP_TRIM_TBL_2P0A_OFFSET] +
                     (uint32_t)sflash_ocp_trim_cold[SFLASH_OCP_TRIM_TBL_2P0A_OFFSET]
                    ) -
                    (
                     (uint32_t)sflash_ocp_trim_hot[SFLASH_OCP_TRIM_TBL_0P9A_OFFSET] +
                     (uint32_t)sflash_ocp_trim_cold[SFLASH_OCP_TRIM_TBL_0P9A_OFFSET]
                    )
                ) >> 1u;

            /* Take the difference of currents used. 2.4A - 1.08A */
            c = 132;

            vrefSel = (((uint32_t)sflash_ocp_trim_hot[SFLASH_OCP_TRIM_TBL_0P9A_OFFSET] + (uint32_t)sflash_ocp_trim_cold[SFLASH_OCP_TRIM_TBL_0P9A_OFFSET]) >> 1U);
            temp = (int32_t)vsense - 132;
            temp = (temp * (int32_t)i) / c;
            if (temp < 0)
            {
                int32_t value = -temp;
                vrefSel -= (uint32_t)value;
            }
            else
            {
                vrefSel += (uint32_t)temp;
            }
        }
        else
        {
            sflash_ocp_trim_hot  = (const uint8_t *)(SFLASH_OCP_TRIM_5V_2A_HOT + (uint16_t)(context->port * 0x100u));
            sflash_ocp_trim_cold = (const uint8_t *)(SFLASH_OCP_TRIM_5V_2A_COLD + (uint16_t)(context->port * 0x100u));

           /* Interpolating the OCP current trim value using line equation: vref_sel = vsense*m + c */
            i = (
                    (
                     (uint32_t)sflash_ocp_trim_hot[SFLASH_OCP_TRIM_TBL_4A_OFFSET] +
                     (uint32_t)sflash_ocp_trim_cold[SFLASH_OCP_TRIM_TBL_4A_OFFSET]
                    ) -
                    (
                     (uint32_t)sflash_ocp_trim_hot[SFLASH_OCP_TRIM_TBL_2A_OFFSET] +
                     (uint32_t)sflash_ocp_trim_cold[SFLASH_OCP_TRIM_TBL_2A_OFFSET]
                    )
                ) >> 1u;

            /* Take the difference of currents used. 4.8A - 2.4A */
            c = 240;

            vrefSel = (((uint32_t)sflash_ocp_trim_hot[SFLASH_OCP_TRIM_TBL_2A_OFFSET] + (uint32_t)sflash_ocp_trim_cold[SFLASH_OCP_TRIM_TBL_2A_OFFSET]) >> 1U);
            temp = (int32_t)vsense - 240;
            temp = (temp * (int32_t)i) / c;
            if (temp < 0)
            {
                int32_t value = -temp;
                vrefSel -= (uint32_t)value;
            }
            else
            {
                vrefSel += (uint32_t)temp;
            }
        }
    }

    state = Cy_SysLib_EnterCriticalSection();

    /* Store the calculated trims in the OCP Trims Register */
    trimRegs->trim_scp_rcp_2 = (uint32_t)vrefSel;

    /* Power-Up the SCP-RCP hard-IP */
    pd->scp_rcp_0_ctrl &= ~PDSS_SCP_RCP_0_CTRL_SCP_RCP_PD;
    Cy_SysLib_DelayUs(10);
    /* Power-Up the OCP block */
    pd->scp_rcp_0_ctrl &= ~PDSS_SCP_RCP_0_CTRL_SCP_RCP_PD_OCP;
    Cy_SysLib_DelayUs(10);
    pd->scp_rcp_0_ctrl |= PDSS_SCP_RCP_0_CTRL_SCP_RCP_ISO_N;
    
#elif defined(CY_DEVICE_CCG6DF_CFP)
    /* Enter Critical Section. */
    state = Cy_SysLib_EnterCriticalSection();

    /* Power-Up the VSENSE hard-IP */
    regval = pd->pd_vsense_ctrl_1;
    regval &= ~PDSS_PD_VSENSE_CTRL_1_VSENSE_PD;
    /* SLE_AV_OCP --> 2 (AV = 10% supports 1.3A - 3.9A), SEL_AV_VSENSE_OUT --> 2 (AV = 10% supports 1A - 3A)*/
    regval &= ~(PDSS_PD_VSENSE_CTRL_1_SEL_AV_OCP_MASK | PDSS_PD_VSENSE_CTRL_1_SEL_AV_VSENSE_OUT_MASK);
    regval |= (0x02u << PDSS_PD_VSENSE_CTRL_1_SEL_AV_OCP_POS) | (0x02u << PDSS_PD_VSENSE_CTRL_1_SEL_AV_VSENSE_OUT_POS);
    pd->pd_vsense_ctrl_1 = regval;
    regval = pd->pd_vsense_ctrl_0;
    /* SEL_OCP field in the vsense_ctrl_0 register performs OCP trip point trimming.
     * SEL_OCP value for 1A trip is 0x35
     * SEL_OCP value for 3A trip is 0x9F (0x35 * 3)
     * as the current value is in 10mA as a param to the function, 
     * divide by 2 gives the value to be written to SEL_OCP.
     */
    /* SEL_OCP is calculated as = current * (1A trim + 1). 
     * e.g. 3A OCP value = 3 * (1A trim + 1).
     * */
    ocp_trim_1A = OCP_TRIM_1A_R(context->port) + 1;
    /* Apply OCP trim value on the current multiplied by threshold so that 
     * OCP triggers below the configured current.
     * Note that OCP 1A current is actually trimmed for 1.3A. Hence divide by 1.3A 
     * to get the actual OCP threshold.
     */
    vsense = (vsense * ocp_trim_1A) / I_1P3A;

    regval &= ~(PDSS_PD_VSENSE_CTRL_0_SEL_OCP_MASK);
    regval |= (vsense << PDSS_PD_VSENSE_CTRL_0_SEL_OCP_POS);
    regval |= (PDSS_PD_VSENSE_CTRL_0_ISO_N | PDSS_PD_VSENSE_CTRL_0_EN_OCP);
    pd->pd_vsense_ctrl_0 = regval;

    /* 100 micro-seconds delay before enabling signal for Vsense block and enabling bit for OCP output. */
    Cy_SysLib_DelayUs(100);

    pd->pd_vsense_ctrl_1 |= (PDSS_PD_VSENSE_CTRL_1_EN_VSENSE);
    pd->pd_vsense_ctrl_0 |= (PDSS_PD_VSENSE_CTRL_0_EN_OCP_OUT_D);

#endif /* CY_DEVICE */

#if (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP))
    /* Configuring the CSA output filter. */
    regval = pd->intr13_cfg_csa_scp_hs;
    regval &= ~(PDSS_INTR13_CFG_CSA_SCP_HS_CSA_OCP_FILT_EN | PDSS_INTR13_CFG_CSA_SCP_HS_CSA_OCP_FILT_CFG_MASK |
            PDSS_INTR13_CFG_CSA_SCP_HS_CSA_OCP_FILT_SEL_MASK | PDSS_INTR13_CFG_CSA_SCP_HS_CSA_OCP_FILT_RESET |
            PDSS_INTR13_CFG_CSA_SCP_HS_CSA_OCP_FILT_BYPASS);

    if (GET_VBUS_OCP_TABLE(context)->mode == VBUS_OCP_MODE_INT_AUTOCTRL)
    {
        /* Configure the filter based on debounce parameter from config table. */
        regval |= ((uint32_t)CY_USBPD_VBUS_FILTER_CFG_POS_EN_NEG_DIS << PDSS_INTR13_CFG_CSA_SCP_HS_CSA_OCP_FILT_CFG_POS);
        regval |= ((uint32_t)filterSel << PDSS_INTR13_CFG_CSA_SCP_HS_CSA_OCP_FILT_SEL_POS) |
            PDSS_INTR13_CFG_CSA_SCP_HS_CSA_OCP_FILT_EN |
            PDSS_INTR13_CFG_CSA_SCP_HS_CSA_OCP_DPSLP_MODE;
    }
    else
    {
        /* Bypassing filter is causing false OC triggers. Leaving filter enabled with a 5 us debounce period. */
        regval |= ((uint32_t)CY_USBPD_VBUS_FILTER_CFG_POS_EN_NEG_DIS << PDSS_INTR13_CFG_CSA_SCP_HS_CSA_OCP_FILT_CFG_POS);
        regval |= (10UL << PDSS_INTR13_CFG_CSA_SCP_HS_CSA_OCP_FILT_SEL_POS) | PDSS_INTR13_CFG_CSA_SCP_HS_CSA_OCP_FILT_EN |
            PDSS_INTR13_CFG_CSA_SCP_HS_CSA_OCP_DPSLP_MODE;
    }
    pd->intr13_cfg_csa_scp_hs = regval;

    /* Clear and enable the OC detect interrupt. */
    pd->intr13 = PDSS_INTR13_CSA_OCP_CHANGED;
    pd->intr13_mask |= PDSS_INTR13_MASK_CSA_OCP_CHANGED_MASK;

    if (GET_VBUS_OCP_TABLE(context)->mode == VBUS_OCP_MODE_INT_AUTOCTRL)
    {
        Cy_USBPD_Fault_FetAutoModeEnable(context, true, CY_USBPD_VBUS_FILTER_ID_HSCSA_OCP);
    }

    Cy_SysLib_ExitCriticalSection(state);
#elif (PDL_VBUS_OCP_ENABLE && defined(CY_DEVICE_CCG3))

    (void)vrefSel;
    (void)filterSel;
    /* Set up OCP callback. */
    context->vbusOcpCbk = cb;

   /* Calculate required current for OCP. */
    vsense = current + ((current * context->usbpdConfig->vbusOcpConfig->threshold) / 100u);

    if(vsense > VBUS_MAX_CURRENT)
    {
        vsense = VBUS_MAX_CURRENT;
    }

    /*
     * CCG3:
     * The gain and reference voltage setting for the CSA is looked up from the csa_tab array based
     * on the sense voltage at which the trip should happen.
     */
    unsigned int i = 0u;

    /* Convert to mV, accounting for the unit of current which is 10mA and the
     * sense resistance which is in mOhm units. */
    vsense = (vsense * context->usbpdConfig->vbusOcpConfig->senseRes) / 100u ;

    if (vsense < VSENSE_MIN)
    {
        i = 0u;
    }
    else
    {
        i = ((vsense - VSENSE_MIN) << 1u);
    }

    uint8_t gain_sel = csa_tab[i];
    uint8_t vref_sel = csa_tab[i + 1u];

    uint8_t av_bw = gain_sel; 

    state = Cy_SysLib_EnterCriticalSection();
    
    regval = pd->csa_ctrl;

    /* Power up the CSA block and clear gain and bandwidth fields. */
    regval &= ~(PDSS_CSA_CTRL_PD_CSA | PDSS_CSA_CTRL_AV1_MASK | PDSS_CSA_CTRL_CSA_VREF_SEL_MASK | PDSS_CSA_CTRL_BW);
    /* Default operational settings. */
    regval |= PDSS_CSA_CTRL_SEL_OUT_D | PDSS_CSA_CTRL_CSA_ISO_N;
    pd->debug_cc_0 &= ~PDSS_DEBUG_CC_0_CSA_BW_1;

    /* Set CSA gain. */
    regval |=  (av_bw >> 2u) << PDSS_CSA_CTRL_AV1_POS;
    /* Set Vref trim select. */
    regval |= vref_sel << PDSS_CSA_CTRL_CSA_VREF_SEL_POS;
    /* Set analog bandwidth, BW[0]. */
    regval |= ((av_bw & 1u) << 30u);

    /* Write out CSA_CTRL. */
    pd->csa_ctrl = regval;
    /* Set analog bandwidth, BW[1]. */
    pd->debug_cc_0 |= ((av_bw & 2u) << 30u);

    if (context->usbpdConfig->vbusOcpConfig->mode == VBUS_OCP_MODE_INT_AUTOCTRL)
    {
        /*
         * Configure NGDO_CTRL_P to set auto shutoff for OCP.
         */
        regval = pd->ngdo_ctrl_p;
        /* Auto mode on. */
        
        regval |= PDSS_NGDO_CTRL_P_AUTO_MODE;
        /* overcurrent detection to turn off the NGDO.*/
        regval |= PDSS_NGDO_CTRL_P_SEL_OC;
        
        /* Off value used by hardware in auto mode to turn off the NGDO. */
        regval |= PDSS_NGDO_CTRL_P_PULLDN_EN_LV_OFF_VALUE_MASK;
        regval &= ~PDSS_NGDO_CTRL_P_EN_LV_OFF_VALUE_MASK;
        
        PDSS->ngdo_ctrl_p = regval;
     }

    /* Enable CSA positive edge filtering for 4 clk_lf cycles. */
    pd->intr3_cfg_0 = (pd->intr3_cfg_0 & ~PDSS_INTR3_CFG_0_CSA_POS_FILT_SEL_MASK) |
        (PDSS_INTR3_FILT_SEL_4_CLK_LF << PDSS_INTR3_CFG_0_CSA_POS_FILT_SEL_POS) |
        PDSS_INTR3_CFG_0_CSA_POS_FILT_EN;

    /* Clear interrupts. */
    pd->intr3 = PDSS_INTR3_POS_CSA_CHANGED | PDSS_INTR3_NEG_CSA_CHANGED;

    /* If the OCP_DET output is already high, flag it. */
    if (pd->ncell_status & PDSS_NCELL_STATUS_CSA_STATUS)
    {
        pd->intr3_set |= PDSS_INTR3_POS_CSA_CHANGED;
    }

    /* Enable interrupts. */
    pd->intr3_mask |= PDSS_INTR3_POS_CSA_CHANGED;

    Cy_SysLib_ExitCriticalSection(state);
    
#elif (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
    {
        /*
         * ** Silicon has room temperature trims.
         * Whereas,
         * *A silicon does not have room temperature trims.
         */
        if (OCP_TRIM_ROOM_FLAG(context->port) == 0u)
        {
            ocp_trim_1A = ((OCP_TRIM_1A_H(context->port) + OCP_TRIM_1A_C(context->port)) >> 1u);
            ocp_trim_2A = ((OCP_TRIM_2A_H(context->port) + OCP_TRIM_2A_C(context->port)) >> 1u);
            ocp_trim_3A = ((OCP_TRIM_3A_H(context->port) + OCP_TRIM_3A_C(context->port)) >> 1u);
            ocp_trim_4A = ((OCP_TRIM_4A_H(context->port) + OCP_TRIM_4A_C(context->port)) >> 1u);
            ocp_trim_5A = ((OCP_TRIM_5A_H(context->port) + OCP_TRIM_5A_C(context->port)) >> 1u);
        }
        else
        {
            ocp_trim_1A = OCP_TRIM_1A_ROOM(context->port);
            ocp_trim_2A = OCP_TRIM_2A_ROOM(context->port);
            ocp_trim_3A = OCP_TRIM_3A_ROOM(context->port);
            ocp_trim_4A = OCP_TRIM_4A_ROOM(context->port);
            ocp_trim_5A = OCP_TRIM_5A_ROOM(context->port);
        }

        /* vsense contains the current setting required in 10mA units. */
        /* Check if silicon has proper trims and then apply interpolation. */
        if((ocp_trim_1A != 0u) &&
           (ocp_trim_2A != 0u) &&
           (ocp_trim_3A != 0u) &&
           (ocp_trim_4A != 0u) &&
           (ocp_trim_5A != 0u))
        {
            /* Calculate current for the actual Rsense */
            vsense = ((vsense * context->vbusCsaRsense) / CSA_IDEAL_RSENSE);

            /* Trim values are with 30% OCP threshold */
            if(vsense >= I_5P2A)
            {
                vref_2 = (int32_t)ocp_trim_5A;
                vref_1 = (int32_t)ocp_trim_4A;
                cur_1 = I_5P2A;
            }
            else if(vsense >= I_3P9A)
            {
                vref_2 = (int32_t)ocp_trim_4A;
                vref_1 = (int32_t)ocp_trim_3A;
                cur_1 = I_3P9A;
            }
            else if(vsense >= I_2P6A)
            {
                vref_2 = (int32_t)ocp_trim_3A;
                vref_1 = (int32_t)ocp_trim_2A;
                cur_1 = I_2P6A;
            }
            else if(vsense >= I_1P3A)
            {
                vref_2 = (int32_t)ocp_trim_2A;
                vref_1 = (int32_t)ocp_trim_1A;
                cur_1 = I_1P3A;
            }
            else
            {
                /*
                 * Since reference value is 130mV by default for value '0',
                 * we need to consider corresponding negative reference
                 * for 0A base current.
                 */
                vref_2 = (int32_t)ocp_trim_1A;
                vref_1 = -13;
                cur_1 = 0;
            }

            /*
             * Calculate corrected reference with trim and rsense value.
             * Adjust for current in 10mA units.
             * Considering Ex: (2.6A - 1.3A) = 1.3A instead of 1A.
             */
            vref_sel_signed_32 = (vref_1 + (((vref_2 - vref_1) * ((int32_t)vsense - (int32_t)cur_1)) / 130));
            vrefSel = (uint8_t)vref_sel_signed_32;

            /*
             * CC trims will give refgen value directly including
             * 13 steps (130mV) offset. So, no need to adjust refgen offset.
             */
        }
        else
        {
            gainSel = OCP_GAIN_VALUE;
            Cy_USBPD_CSA_Calc_Ref(context, vsense, gainSel, &vrefSel, false);
        }
    }

    filterSel = GET_VBUS_OCP_TABLE(context)->debounce;

    if(GET_VBUS_OCP_TABLE(context)->mode == VBUS_OCP_MODE_INT_AUTOCTRL)
    {
        filterSel = (uint8_t)system_get_clk_filt_sel(context->port, (((uint16_t)filterSel) * 10u));
    }

     context->ocpSwDbMs=filterSel;

        state = Cy_SysLib_EnterCriticalSection();

        if(GET_VBUS_OCP_TABLE(context)->mode == VBUS_OCP_MODE_INT_AUTOCTRL)
        {
            Cy_USBPD_Fault_FetAutoModeDisable(context, true, CY_USBPD_VBUS_FILTER_ID_CSA_OCP);
        }


        /* Gain for OCP is fixed. So CSA programming is not required. */
        /* Power up CSA block and enable output. */
        regval = pd->csa_scp_0_ctrl;
        regval &= ~PDSS_CSA_SCP_0_CTRL_PD_CSA;
        regval |= PDSS_CSA_SCP_0_CTRL_SEL_OUT_D | PDSS_CSA_SCP_0_CTRL_CSA_ISO_N;
        pd->csa_scp_0_ctrl = regval;

        /* Configure Reference for comparator. */
#if FG_PART
        vref_sel -= (((CC_GAIN60_GM0P6_TRIM_2A_ROOM(port) - 46) * 46) / 300);
#endif /* FG_PART */

        regval = pd->refgen_2_ctrl;
        regval &= ~(PDSS_REFGEN_2_CTRL_SEL5_MASK);
        regval |= ((uint32_t)vrefSel << PDSS_REFGEN_2_CTRL_SEL5_POS);
        pd->refgen_2_ctrl = regval;

        regval = pd->refgen_2_ctrl;
        regval &= ~(PDSS_REFGEN_2_CTRL_SEL5_MASK);
        regval |= ((uint32_t)vrefSel << PDSS_REFGEN_2_CTRL_SEL5_POS);
        pd->refgen_2_ctrl = regval;

        /* Configuring the CSA output filter. */
        regval = pd->intr13_cfg_csa_scp_hs;
        regval &= ~(PDSS_INTR13_CFG_CSA_SCP_HS_CSA_OCP_FILT_EN |
                PDSS_INTR13_CFG_CSA_SCP_HS_CSA_OCP_FILT_CFG_MASK |
                PDSS_INTR13_CFG_CSA_SCP_HS_CSA_OCP_FILT_SEL_MASK |
                PDSS_INTR13_CFG_CSA_SCP_HS_CSA_OCP_FILT_RESET |
                PDSS_INTR13_CFG_CSA_SCP_HS_CSA_OCP_FILT_BYPASS);
        pd->intr13_cfg_csa_scp_hs = regval;

        /* Configure the filter based on debounce parameter from config table. */
        regval |= ((uint8_t)CY_USBPD_VBUS_FILTER_CFG_POS_EN_NEG_DIS << PDSS_INTR13_CFG_CSA_SCP_HS_CSA_OCP_FILT_CFG_POS) |
            (16u << PDSS_INTR13_CFG_CSA_SCP_HS_CSA_OCP_FILT_SEL_POS) |
            PDSS_INTR13_CFG_CSA_SCP_HS_CSA_OCP_FILT_EN |
            PDSS_INTR13_CFG_CSA_SCP_HS_CSA_OCP_DPSLP_MODE;
        pd->intr13_cfg_csa_scp_hs = regval;

        /* Clear and enable the OC detect interrupt. */
        pd->intr13 = PDSS_INTR13_CSA_OCP_CHANGED;
        pd->intr13_mask |= PDSS_INTR13_MASK_CSA_OCP_CHANGED_MASK;

        if (GET_VBUS_OCP_TABLE(context)->mode == VBUS_OCP_MODE_INT_AUTOCTRL)
        {
             Cy_USBPD_Fault_FetAutoModeEnable(context, true, CY_USBPD_VBUS_FILTER_ID_CSA_OCP);
        }

        Cy_SysLib_ExitCriticalSection(state);

#elif defined(CY_DEVICE_CCG3PA)
    filterSel = GET_VBUS_OCP_TABLE(context)->debounce;
    Cy_USBPD_LSCSA_Calc_Cfg(context,vsense, &gainSel, &vrefSel);

    if(GET_VBUS_OCP_TABLE(context)->mode == VBUS_OCP_MODE_INT_AUTOCTRL)
    {
         filterSel = (GET_VBUS_OCP_TABLE(context)->debounce + 1u) / 2u;
         if(filterSel > 31u)
         {
            filterSel = 31u;
         }
     }

    context->ocpSwDbMs=filterSel;

    state = Cy_SysLib_EnterCriticalSection();

    if(GET_VBUS_OCP_TABLE(context)->mode == VBUS_OCP_MODE_INT_AUTOCTRL)
    {
        Cy_USBPD_Fault_FetAutoModeDisable(context, true, CY_USBPD_VBUS_FILTER_ID_LSCSA_OCP);
    }

    (void)Cy_USBPD_LSCSA_Config(context, CY_USBPD_VBUS_LSCSA_OCP_CONFIG, gainSel);
    pd->lscsa_1_ctrl &= ~PDSS_LSCSA_1_CTRL_LSCSA_PD;

    /* Configure Reference for comparator. */
    regval = pd->refgen_2_ctrl;
    regval &= ~(PDSS_REFGEN_2_CTRL_SEL5_MASK);
    regval |= ((uint32_t)vrefSel << PDSS_REFGEN_2_CTRL_SEL5_POS);
    pd->refgen_2_ctrl = regval;

    /* Use Vref SEL 5 for OCP comparator. */
    pd->amux_ctrl |= ((uint32_t)1 << VBUS_OCP_AMUX_CTRL_REF_SEL_BIT_POS);

    /* Enable Comparator. */
    pd->comp_ctrl[CY_USBPD_VBUS_COMP_ID_LSCSA_OCP] |= PDSS_COMP_CTRL_COMP_ISO_N;
    pd->comp_ctrl[CY_USBPD_VBUS_COMP_ID_LSCSA_OCP] &= ~PDSS_COMP_CTRL_COMP_PD;

    Cy_SysLib_DelayUs(10);
    /*
     * By default OCP will work in software debounce mode. If end user want
     * us level debounce, then hardware filtering shall be enabled here.
     */

    /* Set edge detection. */
    pd->intr5_filter_cfg[CY_USBPD_VBUS_FILTER_ID_LSCSA_OCP] &= ~(PDSS_INTR5_FILTER_CFG_FILT_EN |
            PDSS_INTR5_FILTER_CFG_FILT_CFG_MASK |
            PDSS_INTR5_FILTER_CFG_FILT_RESET |
            PDSS_INTR5_FILTER_CFG_FILT_SEL_MASK |
            PDSS_INTR5_FILTER_CFG_FILT_BYPASS);

    pd->intr5_filter_cfg[CY_USBPD_VBUS_FILTER_ID_LSCSA_OCP] |= (
            ((uint32_t)CY_USBPD_VBUS_FILTER_CFG_POS_EN_NEG_DIS << PDSS_INTR5_FILTER_CFG_FILT_CFG_POS) |
            ((uint32_t)16<< PDSS_INTR5_FILTER_CFG_FILT_SEL_POS) |
            PDSS_INTR5_FILTER_CFG_FILT_EN);

    /* Clear interrupt. */
    pd->intr5 = ((uint32_t)1u << (uint8_t)CY_USBPD_VBUS_FILTER_ID_LSCSA_OCP);

    /* Enable Interrupt. */
    pd->intr5_mask |= ((uint32_t)1u << (uint8_t)CY_USBPD_VBUS_FILTER_ID_LSCSA_OCP);
    /* Check if Auto FET Control mode. */
    /* For PB application, P_CTRL and C_CTRL are flipped. Take care of this. */
    if (GET_VBUS_OCP_TABLE(context)->mode == VBUS_OCP_MODE_INT_AUTOCTRL)
        {
            Cy_USBPD_Fault_FetAutoModeEnable(context, true, CY_USBPD_VBUS_FILTER_ID_LSCSA_OCP);
        }

    Cy_SysLib_ExitCriticalSection(state);

#endif /* defined(CY_DEVICE_CCG3PA) */

#endif /* defined(PDL_VBUS_OCP_ENABLE) */
    CY_UNUSED_PARAMETER(context);
    CY_UNUSED_PARAMETER(current);
    (void)(cy_cb_vbus_fault_t)cb;
}

/*******************************************************************************
* Function Name: Cy_USBPD_Fault_Vbus_OcpDisable
****************************************************************************//**
*
* Disables the Over Current Protection (OCP)
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \param pctrl
* Flag indicating the type of gate driver to be controlled, true for
* P_CTRL and false for C_CTRL.
*
* \return
* None
*
*******************************************************************************/
void Cy_USBPD_Fault_Vbus_OcpDisable(cy_stc_usbpd_context_t *context, bool pctrl)
{
#if (defined(PDL_VBUS_OCP_ENABLE))
#if (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP) || defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
    PPDSS_REGS_T pd = context->base;
    uint32_t state;

    state = Cy_SysLib_EnterCriticalSection();

    /* Deregister the callback. */
    context->vbusOcpCbk = NULL;
#endif /* (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP) || defined(CY_DEVICE_CCG3PA)) */
#if (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
    uint32_t regval;
#endif /* (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP)*/
#if defined(CY_DEVICE_CCG6)
    /* Default settings and power down. */
    pd->csa_scp_0_ctrl = (pd->csa_scp_0_ctrl & ~PDSS_CSA_SCP_0_CTRL_CSA_ISO_N) | PDSS_CSA_SCP_0_CTRL_PD_CSA;
#elif defined(CY_DEVICE_PMG1S3)
    /* Default settings and power down. */
    pd->scp_rcp_0_ctrl |= PDSS_SCP_RCP_0_CTRL_SCP_RCP_PD_OCP;
#elif defined(CY_DEVICE_CCG6DF_CFP)
    /* Disable Vsense Block only if Ilimit is not enabled. */
    if ((pd->pd_ilimt_ctrl & PDSS_PD_ILIMT_CTRL_ILIMIT_EN) != PDSS_PD_ILIMT_CTRL_ILIMIT_EN )
    {
        /* Default settings and power down. */
        regval = pd->pd_vsense_ctrl_1;
        regval |= PDSS_PD_VSENSE_CTRL_1_VSENSE_PD;
        regval &= ~(PDSS_PD_VSENSE_CTRL_1_EN_VSENSE);
        pd->pd_vsense_ctrl_1 = regval;

        pd->pd_vsense_ctrl_0 &= ~(PDSS_PD_VSENSE_CTRL_0_ISO_N | PDSS_PD_VSENSE_CTRL_0_EN_OCP | PDSS_PD_VSENSE_CTRL_0_EN_OCP_OUT_D);

    }
#endif /* CY_DEVICE */

#if (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP))
    /* Disable and clear interrupts. */
    pd->intr13_mask &= ~(PDSS_INTR13_CSA_OCP_CHANGED);
    pd->intr13 = PDSS_INTR13_CSA_OCP_CHANGED;

    /* Disable the filter. */
    regval = pd->intr13_cfg_csa_scp_hs;
    regval &= ~(PDSS_INTR13_CFG_CSA_SCP_HS_CSA_OCP_FILT_EN | PDSS_INTR13_CFG_CSA_SCP_HS_CSA_OCP_FILT_CFG_MASK |
            PDSS_INTR13_CFG_CSA_SCP_HS_CSA_OCP_FILT_SEL_MASK | PDSS_INTR13_CFG_CSA_SCP_HS_CSA_OCP_FILT_RESET |
            PDSS_INTR13_CFG_CSA_SCP_HS_CSA_OCP_FILT_BYPASS);
    pd->intr13_cfg_csa_scp_hs = regval;

    if (GET_VBUS_OCP_TABLE(context)->mode == VBUS_OCP_MODE_INT_AUTOCTRL)
    {
        /* Turn-off auto mode. */
        Cy_USBPD_Fault_FetAutoModeDisable(context, pctrl, CY_USBPD_VBUS_FILTER_ID_HSCSA_OCP);
    }
    else
    {
        /* APP: The caller needs to make sure to stop the debounce timer. */
        //timer_stop(port, PD_OCP_DEBOUNCE_TIMER);
    }

    Cy_SysLib_ExitCriticalSection(state);
#elif defined(CY_DEVICE_CCG3)
    PPDSS_REGS_T pd = context->base;
    uint32_t state;
    uint32_t regval;

    state = Cy_SysLib_EnterCriticalSection();

    /* Default settings and power down. */
    pd->csa_ctrl = PDSS_CSA_CTRL_SEL_OUT_D | PDSS_CSA_CTRL_PD_CSA;

    /* Disable and clear interrupts. */
    pd->intr3_mask &= ~(PDSS_INTR3_POS_CSA_CHANGED | PDSS_INTR3_NEG_CSA_CHANGED);
    pd->intr3 = PDSS_INTR3_POS_CSA_CHANGED | PDSS_INTR3_NEG_CSA_CHANGED;
    
    if (context->usbpdConfig->vbusOcpConfig->mode == VBUS_OCP_MODE_INT_AUTOCTRL)
    {
        /* No auto mode shutoff on overcurrent detect. */  
       regval = pd->ngdo_ctrl_p;
       regval &= ~PDSS_NGDO_CTRL_P_SEL_OC;
       if ((regval & (PDSS_NGDO_CTRL_P_SEL_OV | PDSS_NGDO_CTRL_P_SEL_UV)) == 0U)
       {
           regval &= ~PDSS_NGDO_CTRL_P_AUTO_MODE;
       }
       pd->ngdo_ctrl_p = regval;
       
    }

    Cy_SysLib_ExitCriticalSection(state);
    
#elif  defined(CY_DEVICE_CCG3PA)
    /* Disable and clear interrupt. */
    pd->intr5_mask &= ~(1u << (uint8_t)CY_USBPD_VBUS_FILTER_ID_LSCSA_OCP);
    pd->intr5 = ((uint32_t)1u << (uint8_t)CY_USBPD_VBUS_FILTER_ID_LSCSA_OCP);

    /* Disable comparator. */
    pd->comp_ctrl[CY_USBPD_VBUS_COMP_ID_LSCSA_OCP] &= ~PDSS_COMP_CTRL_COMP_ISO_N;
    pd->comp_ctrl[CY_USBPD_VBUS_COMP_ID_LSCSA_OCP] |= PDSS_COMP_CTRL_COMP_PD;
    /* Clear reference. */
    pd->refgen_2_ctrl &= ~(PDSS_REFGEN_2_CTRL_SEL5_MASK);

    /* Disable filter. */
    pd->intr5_filter_cfg[CY_USBPD_VBUS_FILTER_ID_LSCSA_OCP] &= ~(PDSS_INTR5_FILTER_CFG_FILT_EN |
        PDSS_INTR5_FILTER_CFG_FILT_CFG_MASK | PDSS_INTR5_FILTER_CFG_FILT_SEL_MASK |
        PDSS_INTR5_FILTER_CFG_FILT_BYPASS);

   if(GET_VBUS_OCP_TABLE(context)->mode == VBUS_OCP_MODE_INT_AUTOCTRL)
    {
        Cy_USBPD_Fault_FetAutoModeDisable(context, pctrl, CY_USBPD_VBUS_FILTER_ID_LSCSA_OCP);
    }

#if !defined(CY_DEVICE_SERIES_PMG1S0)
    if (GET_VBUS_OCP_TABLE(context)->mode == VBUS_OCP_MODE_INT_SW_DB)
    {
        /* Make sure any debounce timer is stopped. */
        context->timerStopcbk(context, CY_USBPD_PD_OCP_DEBOUNCE_TIMER);
    }
#endif /* !defined(CY_DEVICE_SERIES_PMG1S0) */

    Cy_SysLib_ExitCriticalSection (state);

#elif  (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))

    /* Clear reference. */
    pd->refgen_2_ctrl &= ~(PDSS_REFGEN_2_CTRL_SEL5_MASK);

    /* Disable and clear interrupts. */
    pd->intr13_mask &= ~(PDSS_INTR13_CSA_OCP_CHANGED);
    pd->intr13 = PDSS_INTR13_CSA_OCP_CHANGED;

    /* Disable the filter. */
    regval = pd->intr13_cfg_csa_scp_hs;
    regval &= ~(PDSS_INTR13_CFG_CSA_SCP_HS_CSA_OCP_FILT_EN |
            PDSS_INTR13_CFG_CSA_SCP_HS_CSA_OCP_FILT_CFG_MASK |
            PDSS_INTR13_CFG_CSA_SCP_HS_CSA_OCP_FILT_SEL_MASK |
            PDSS_INTR13_CFG_CSA_SCP_HS_CSA_OCP_FILT_RESET |
            PDSS_INTR13_CFG_CSA_SCP_HS_CSA_OCP_FILT_BYPASS);
    pd->intr13_cfg_csa_scp_hs = regval;

    if(GET_VBUS_OCP_TABLE(context)->mode == VBUS_OCP_MODE_INT_AUTOCTRL)
        {
            Cy_USBPD_Fault_FetAutoModeDisable(context, pctrl, CY_USBPD_VBUS_FILTER_ID_CSA_OCP);
        }

    if (GET_VBUS_OCP_TABLE(context)->mode == VBUS_OCP_MODE_INT_SW_DB)
    {
        /* Make sure any debounce timer is stopped. */
        context->timerStopcbk(context, CY_USBPD_PD_OCP_DEBOUNCE_TIMER);
    }

    Cy_SysLib_ExitCriticalSection (state);

#endif /* defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP) */
#endif /* defined(PDL_VBUS_OCP_ENABLE) */
    CY_UNUSED_PARAMETER(context);
    CY_UNUSED_PARAMETER(pctrl);
}

#if (PDL_VBUS_OCP_ENABLE)
#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1) || (defined(CY_DEVICE_CCG3PA) && !defined(CY_DEVICE_SERIES_PMG1S0)) || defined(CY_DEVICE_PAG2S))
/*******************************************************************************
* Function Name: Cy_USBPD_OcpHandlerWrapper
****************************************************************************//**
*
* VBUS OCP Wrapper function.
*
* \param id
* Timer id
*
* \param callbackContext
* Pointer to usbpd_context structure.
*
* \return
* None
*
*******************************************************************************/
static void Cy_USBPD_OcpHandlerWrapper(uint16_t id, void *callbackContext)
{
    cy_stc_usbpd_context_t *context=callbackContext;
     /* OCP debounced. Invoke callback. */
     if(context->vbusOcpCbk != NULL)
     {
        context->vbusOcpCbk(context, true);
     }
}
#endif /* (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1) || (defined(CY_DEVICE_CCG3PA) && !defined(CY_DEVICE_SERIES_PMG1S0)) || defined(CY_DEVICE_PAG2S)) */
#endif /* PDL_VBUS_OCP_ENABLE */

/*******************************************************************************
* Function Name: Cy_USBPD_Fault_Vbus_OcpIntrHandler
****************************************************************************//**
*
* VBUS OCP fault interrupt handler function.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \return
* None
*
*******************************************************************************/
void Cy_USBPD_Fault_Vbus_OcpIntrHandler(cy_stc_usbpd_context_t *context)
{
#if PDL_VBUS_OCP_ENABLE
#if (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP))
    PPDSS_REGS_T pd = context->base;
    /*
     * CCG6 uses INTR13.CSA_OCP_CHANGED interrupt to indicate OCP condition.
     */
    if ((pd->intr13_masked & PDSS_INTR13_CSA_OCP_CHANGED) != 0u)
    {
#if (defined(CY_DEVICE_CCG6))
        if (GET_VBUS_OCP_TABLE(context)->mode == VBUS_OCP_MODE_INT_AUTOCTRL)
        {
            /* Disable and clear the interrupt. */
            pd->intr13_mask &= ~PDSS_INTR13_MASK_CSA_OCP_CHANGED_MASK;
            pd->intr13 = PDSS_INTR13_CSA_OCP_CHANGED;

            /* Make sure the provider path is turned off. This should already have been done by hardware. */
            /* Invoke OCP callback. 
             * APP: The application shouldn't start a debounce timer for this mode. */
            if (context->vbusOcpCbk != NULL)
            {
                (void)context->vbusOcpCbk(context, true);
            }
        }
        else
#endif /* CY_DEVICE_CCG6 */
        {
            /* If positive edge interrupt. */
            if (((pd->intr13_cfg_csa_scp_hs & PDSS_INTR13_CFG_CSA_SCP_HS_CSA_OCP_FILT_CFG_MASK) >> PDSS_INTR13_CFG_CSA_SCP_HS_CSA_OCP_FILT_CFG_POS) == (uint32_t)CY_USBPD_VBUS_FILTER_CFG_POS_EN_NEG_DIS)
            {
                /* Clear and disable interrupt. */
                pd->intr13_mask &= ~PDSS_INTR13_MASK_CSA_OCP_CHANGED_MASK;
                pd->intr13 = PDSS_INTR13_CSA_OCP_CHANGED;

                /* Look for negative edge of comparator. */
                pd->intr13_cfg_csa_scp_hs = Cy_USBPD_MmioRegUpdateField(pd->intr13_cfg_csa_scp_hs, (uint32_t)CY_USBPD_VBUS_FILTER_CFG_POS_DIS_NEG_EN,
                        PDSS_INTR13_CFG_CSA_SCP_HS_CSA_OCP_FILT_CFG_MASK, (uint8_t)PDSS_INTR13_CFG_CSA_SCP_HS_CSA_OCP_FILT_CFG_POS);

                /* Enable interrupt. */
                pd->intr13_mask |= PDSS_INTR13_MASK_CSA_OCP_CHANGED_MASK;

                /* Invoke OCP callback. 
                 * APP: The application should start a debounce timer when the compout is set to true. */
                if (context->vbusOcpCbk != NULL)
                {
                    (void)context->vbusOcpCbk(context, true);
                }

                /* If the negative edge has already happened, raise an interrupt. */
                if ((pd->intr13_status & PDSS_INTR13_STATUS_CSA_OCP_FILT) == 0u)
                {
                    pd->intr13_set = PDSS_INTR13_SET_CSA_OCP_CHANGED;
                }
            }
            /* If negative edge interrupt. */
            else
            {
                bool retval = true;

                /* Clear the interrupt. */
                pd->intr13 = PDSS_INTR13_CSA_OCP_CHANGED;

                /* Invoke OCP callback. 
                 * APP: The application should start a debounce timer when the compout is set to true. */
                if (context->vbusOcpCbk != NULL)
                {
                    /* APP: The callback is expected to return true, if the
                     * debounce timer was running, otherwise false. */
                    retval = context->vbusOcpCbk(context, false);
                }
                else
                {
                    /* Disable the interrupt in this case. */
                    retval = false;
                }

                /* debouncing was still going on. */
                if (retval == true)
                {
                    /* Look for positive edge of comparator. */
                    pd->intr13_cfg_csa_scp_hs = Cy_USBPD_MmioRegUpdateField(pd->intr13_cfg_csa_scp_hs,
                            (uint32_t)CY_USBPD_VBUS_FILTER_CFG_POS_EN_NEG_DIS, PDSS_INTR13_CFG_CSA_SCP_HS_CSA_OCP_FILT_CFG_MASK, (uint8_t)PDSS_INTR13_CFG_CSA_SCP_HS_CSA_OCP_FILT_CFG_POS);

                    /* If the positive edge has already happened, raise an interrupt. */
                    if ((pd->intr13_status & PDSS_INTR13_STATUS_CSA_OCP_FILT) != 0u)
                    {
                        pd->intr13_set = PDSS_INTR13_SET_CSA_OCP_CHANGED;
                    }
                }
                else
                {
                    /* Disable the interrupt here as it is no longer of interest. */
                    pd->intr13_mask &= ~PDSS_INTR13_MASK_CSA_OCP_CHANGED_MASK;
                }
            }
        }
    }

#elif defined(CY_DEVICE_CCG3)
    PPDSS_REGS_T pd = context->base;
        
    if (pd->intr3_masked & PDSS_INTR3_POS_CSA_CHANGED)
    {
        /* Disable and clear CSA interrupts. */
        pd->intr3_mask &= ~PDSS_INTR3_POS_CSA_CHANGED;
        pd->intr3 = PDSS_INTR3_POS_CSA_CHANGED;

        if (context->usbpdConfig->vbusOcpConfig->mode == VBUS_OCP_MODE_INT_AUTOCTRL)
        {
            if (context->vbusOcpCbk != NULL)
            {
                (void)context->vbusOcpCbk(context, true);
            }
        }

        else
        {
            /* Negative edge interrupt enable. */
            pd->intr3_mask |= PDSS_INTR3_NEG_CSA_CHANGED;
           
            /* Invoke OCP callback. 
             * APP: The application should start a debounce timer when the compout is set to true. */
            if (context->vbusOcpCbk != NULL)
            {
                (void)context->vbusOcpCbk(context, true);
            }

            /* If the negative edge already happened, trigger the interrupt. */
            if ((pd->ncell_status & PDSS_NCELL_STATUS_CSA_STATUS) == 0)
            {
                pd->intr3_set = PDSS_INTR3_NEG_CSA_CHANGED;
            }
        }
    }

    if (pd->intr3_masked & PDSS_INTR3_NEG_CSA_CHANGED)
    {
        /* Disable and clear the negative edge interrupt. */
        pd->intr3 = PDSS_INTR3_NEG_CSA_CHANGED;
        
        bool retval = true;
        
        if (context->usbpdConfig->vbusOcpConfig->mode != VBUS_OCP_MODE_INT_AUTOCTRL)
        {
            if (context->vbusOcpCbk != NULL)
            {
                /* APP: The callback is expected to return true, if the
                 * debounce timer was running, otherwise false. */
                retval = context->vbusOcpCbk(context, false);
            }
            else
            {
                /* Disable the interrupt in this case. */
                retval = false;
            }
            
            if(retval == true)
            {
                /* Enable positive edge interrupt. */
                pd->intr3_mask |= PDSS_INTR3_POS_CSA_CHANGED;

                /* If the positive edge already happened, trigger the interrupt. */
                if (pd->ncell_status & PDSS_NCELL_STATUS_CSA_STATUS)
                {
                    pd->intr3_set = PDSS_INTR3_POS_CSA_CHANGED;
                }
            }

            else
            {
                /* Disable interrupt as it is no longer of interest */
                pd->intr3_mask &= ~PDSS_INTR3_NEG_CSA_CHANGED;
            }
        }
    }

#endif /* defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP) */

#if defined(CY_DEVICE_CCG3PA)
    PPDSS_REGS_T pd = context->base;
    /* If positive edge interrupt. */
    if (((pd->intr5_filter_cfg[CY_USBPD_VBUS_FILTER_ID_LSCSA_OCP] & PDSS_INTR5_FILTER_CFG_FILT_CFG_MASK) >>
         PDSS_INTR5_FILTER_CFG_FILT_CFG_POS) == (uint32_t)CY_USBPD_VBUS_FILTER_CFG_POS_EN_NEG_DIS)
    {
        /* Clear and disable interrupt. */
        pd->intr5_mask &= ~(1u << (uint8_t)CY_USBPD_VBUS_FILTER_ID_LSCSA_OCP);
        pd->intr5 = (uint32_t)1u << (uint8_t)CY_USBPD_VBUS_FILTER_ID_LSCSA_OCP;

        /* If No software debounce mode. */
        if ((GET_VBUS_OCP_TABLE(context)->mode == VBUS_OCP_MODE_INT) ||
            (GET_VBUS_OCP_TABLE(context)->mode == VBUS_OCP_MODE_INT_AUTOCTRL))
        {
            /* Invoke the callback. */
            (void)context->vbusOcpCbk(context,true);
        }
        /* If software debounce mode. */
        else if (GET_VBUS_OCP_TABLE(context)->mode == VBUS_OCP_MODE_INT_SW_DB)
        {
            uint32_t regval;
            /*
             * Look for negative edge of comparator. NOTE: Here we are using filter
             * reset mechanism to simulate edge if the comparator status has already gone low.
             * This assumes that the OCP comparator filter is being used during enable.
             */
            pd->intr5_filter_cfg[CY_USBPD_VBUS_FILTER_ID_LSCSA_OCP] &= ~PDSS_INTR5_FILTER_CFG_FILT_EN;
            regval = pd->intr5_filter_cfg[CY_USBPD_VBUS_FILTER_ID_LSCSA_OCP];
            regval &= ~(PDSS_INTR5_FILTER_CFG_FILT_CFG_MASK);
            regval |= (uint32_t)CY_USBPD_VBUS_FILTER_CFG_POS_DIS_NEG_EN << PDSS_INTR5_FILTER_CFG_FILT_CFG_POS;
            regval |= (PDSS_INTR5_FILTER_CFG_FILT_RESET | PDSS_INTR5_FILTER_CFG_FILT_EN);
            pd->intr5_filter_cfg[CY_USBPD_VBUS_FILTER_ID_LSCSA_OCP] = regval;

            /* Enable interrupt. */
            pd->intr5_mask |= 1u << (uint8_t)CY_USBPD_VBUS_FILTER_ID_LSCSA_OCP;
#if defined(CY_DEVICE_SERIES_PMG1S0)
            if(context->vbusOcpCbk != NULL)
            {
                /* Invoke the callback. */
                (void)context->vbusOcpCbk(context,true);
            }
#else
            /* Start the debounce timer. */
            context->timerStartcbk(context, context, CY_USBPD_PD_OCP_DEBOUNCE_TIMER, context->ocpSwDbMs, Cy_USBPD_OcpHandlerWrapper);
#endif /* defined(CY_DEVICE_SERIES_PMG1S0) */
        }
        else
        {
            /* Do nothing */
        }
    }
    /* If negative edge interrupt. */
    else
    {
        bool retval = true;

        /* Clear the active interrupt. */
        pd->intr5 = (uint32_t)1u << (uint8_t)CY_USBPD_VBUS_FILTER_ID_LSCSA_OCP;

#if defined(CY_DEVICE_SERIES_PMG1S0)
        if(context->vbusOcpCbk != NULL)
        {
            retval = context->vbusOcpCbk(context,false);
        }
#else
        retval = context->timerIsRunningcbk(context, CY_USBPD_PD_OCP_DEBOUNCE_TIMER);
#endif /* defined(CY_DEVICE_SERIES_PMG1S0) */

        if (retval == true)
        {
            uint32_t regval;
#if !defined(CY_DEVICE_SERIES_PMG1S0)
            /* Stop the debounce timer. */
            context->timerStopcbk(context, CY_USBPD_PD_OCP_DEBOUNCE_TIMER);
#endif /* !defined(CY_DEVICE_SERIES_PMG1S0) */

            /* Clear the interrupt. */
            pd->intr5 = (uint32_t)1u << (uint8_t)CY_USBPD_VBUS_FILTER_ID_LSCSA_OCP;

            /*
             * Look for positive edge of comparator. NOTE: Here we are using filter
             * reset mechanism to simulate edge if the comparator status has already gone low.
             * This assumes that the OCP comparator filter is being used during enable.
            */
            pd->intr5_filter_cfg[CY_USBPD_VBUS_FILTER_ID_LSCSA_OCP] &= ~PDSS_INTR5_FILTER_CFG_FILT_EN;
            regval = pd->intr5_filter_cfg[CY_USBPD_VBUS_FILTER_ID_LSCSA_OCP];
            regval &= ~(PDSS_INTR5_FILTER_CFG_FILT_CFG_MASK | PDSS_INTR5_FILTER_CFG_FILT_RESET);
            regval |= (uint32_t)CY_USBPD_VBUS_FILTER_CFG_POS_EN_NEG_DIS << PDSS_INTR5_FILTER_CFG_FILT_CFG_POS;
            regval |= PDSS_INTR5_FILTER_CFG_FILT_EN;
            pd->intr5_filter_cfg[CY_USBPD_VBUS_FILTER_ID_LSCSA_OCP] = regval;
        }
        else
        {
            /* Disable the interrupt as we are no longer interested in it. */
            pd->intr5_mask &= ~(1u << (uint8_t)CY_USBPD_VBUS_FILTER_ID_LSCSA_OCP);
        }
    }
#endif /* defined(CY_DEVICE_CCG3PA)  */

#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
    PPDSS_REGS_T pd = context->base;
    if ((pd->intr13_masked & (PDSS_INTR13_MASKED_CSA_OCP_CHANGED_MASKED)) != 0u)
    {
        /* Clear the active interrupt. */
        pd->intr13 = PDSS_INTR13_CSA_OCP_CHANGED;

        /* If positive edge interrupt. */
        if (((pd->intr13_cfg_csa_scp_hs & PDSS_INTR13_CFG_CSA_SCP_HS_CSA_OCP_FILT_CFG_MASK) >>
            PDSS_INTR13_CFG_CSA_SCP_HS_CSA_OCP_FILT_CFG_POS) == (uint32_t)CY_USBPD_VBUS_FILTER_CFG_POS_EN_NEG_DIS)
        {
            /* If No software debounce mode. */
            if ((GET_VBUS_OCP_TABLE(context)->mode == VBUS_OCP_MODE_INT) ||
                (GET_VBUS_OCP_TABLE(context)->mode == VBUS_OCP_MODE_INT_AUTOCTRL))
            {
                /* Invoke the callback. */
                (void)context->vbusOcpCbk(context,true);
            }
            /* If software debounce mode. */
            else if (GET_VBUS_OCP_TABLE(context)->mode == VBUS_OCP_MODE_INT_SW_DB)
            {
                uint32_t regval2;
                /*
                 * Look for negative edge of comparator. NOTE: Here we are using filter
                 * reset mechanism to simulate edge if the comparator status has already gone low.
                 * This assumes that the OCP comparator filter is being used during enable.
                 */
                pd->intr13_cfg_csa_scp_hs &= ~PDSS_INTR13_CFG_CSA_SCP_HS_CSA_OCP_FILT_EN;
                regval2 = pd->intr13_cfg_csa_scp_hs;
                regval2 &= ~(PDSS_INTR13_CFG_CSA_SCP_HS_CSA_OCP_FILT_CFG_MASK);
                regval2 |= (uint8_t)CY_USBPD_VBUS_FILTER_CFG_POS_DIS_NEG_EN << PDSS_INTR13_CFG_CSA_SCP_HS_CSA_OCP_FILT_CFG_POS;
                regval2 |= (PDSS_INTR13_CFG_CSA_SCP_HS_CSA_OCP_FILT_RESET | PDSS_INTR13_CFG_CSA_SCP_HS_CSA_OCP_FILT_EN);
                pd->intr13_cfg_csa_scp_hs = regval2;

                /* Start the debounce timer. */
                context->timerStartcbk(context, context, CY_USBPD_PD_OCP_DEBOUNCE_TIMER, context->ocpSwDbMs, Cy_USBPD_OcpHandlerWrapper);
            }
            else
            {
                /* Do nothing */
            }
        }
        /* If negative edge interrupt. */
        else
        {
            if (context->timerIsRunningcbk(context, CY_USBPD_PD_OCP_DEBOUNCE_TIMER))
            {
                uint32_t regval1;
                /* Stop the debounce timer. */
                context->timerStopcbk(context, CY_USBPD_PD_OCP_DEBOUNCE_TIMER);

                /*
                 * Look for positive edge of comparator. NOTE: Here we are using filter
                 * reset mechanism to simulate edge if the comparator status has already gone low.
                 * This assumes that the OCP comparator filter is being used during enable.
                 */
                pd->intr13_cfg_csa_scp_hs &= ~PDSS_INTR13_CFG_CSA_SCP_HS_CSA_OCP_FILT_EN;
                regval1 = pd->intr13_cfg_csa_scp_hs;
                regval1 &= ~(PDSS_INTR13_CFG_CSA_SCP_HS_CSA_OCP_FILT_CFG_MASK | PDSS_INTR13_CFG_CSA_SCP_HS_CSA_OCP_FILT_RESET);
                regval1 |= (uint8_t)CY_USBPD_VBUS_FILTER_CFG_POS_EN_NEG_DIS << PDSS_INTR13_CFG_CSA_SCP_HS_CSA_OCP_FILT_CFG_POS;
                regval1 |= (PDSS_INTR13_CFG_CSA_SCP_HS_CSA_OCP_FILT_EN);
                pd->intr13_cfg_csa_scp_hs = regval1;
            }
            else
            {
                /* Disable the interrupt as we are no longer interested in it. */
                pd->intr13_mask &= ~PDSS_INTR13_CSA_OCP_CHANGED;
            }
        }
    }
#endif /* (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))  */
#endif /* defined(PDL_VBUS_OCP_ENABLE) */
    CY_UNUSED_PARAMETER(context);
}

/*******************************************************************************
* Function Name: Cy_USBPD_Fault_CcOvp_IntrHandler
****************************************************************************//**
*
* CC OVP fault interrupt handler function.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
*******************************************************************************/
void Cy_USBPD_Fault_CcOvp_IntrHandler(cy_stc_usbpd_context_t *context)
{
#if (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_SERIES_WLC1) || defined(CY_DEVICE_CCG6DF_CFP))
    PPDSS_REGS_T pd = context->base;

    /* No need to check current status as we only enable positive edge on the interrupt. */
    if (context->ccSbuOvpCbk != NULL)
    {
        /* Passing false to indicate CC1/2 fault. */
        (void)context->ccSbuOvpCbk (context, false);
    }

    /* Re-enable the interrupts. */
    pd->intr1_mask |= (PDSS_INTR1_MASK_CC1_OVP_CHANGED_MASK | PDSS_INTR1_MASK_CC2_OVP_CHANGED_MASK);
#else
    CY_UNUSED_PARAMETER(context);
#endif /* (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_SERIES_WLC1) || defined(CY_DEVICE_CCG6DF_CFP)) */
}

/*******************************************************************************
* Function Name: Cy_USBPD_Fault_SbuOvp_IntrHandler
****************************************************************************//**
*
* SBU OVP fault interrupt handler function.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
*******************************************************************************/
void Cy_USBPD_Fault_SbuOvp_IntrHandler(cy_stc_usbpd_context_t *context)
{
#if (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_CCG6DF_CFP))
    PPDSS_REGS_T pd = context->base;

    /* Clear the interrupt. */
    pd->intr3 = PDSS_INTR3_SBU1_SBU2_OVP_CHANGED_MASK;

    /* We don't need to check status as only positive edge triggered interrupts are enabled. */
    if (context->ccSbuOvpCbk != NULL)
    {
        /* Parameter true indicates SBU fault. */
        (void)context->ccSbuOvpCbk (context, true);
    }
#else
    CY_UNUSED_PARAMETER(context);
#endif /* defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_CCG6DF_CFP) */
}

/*******************************************************************************
* Function Name: Cy_USBPD_Vbus_V5vChangeDetectHandler
****************************************************************************//**
*
* VCONN 5V supply change interrupt handler function.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
*******************************************************************************/
void Cy_USBPD_Vbus_V5vChangeDetectHandler(cy_stc_usbpd_context_t *context)
{
#if PMG1_V5V_CHANGE_DETECT
    PPDSS_REGS_T pd = context->base;
    bool temp = false;

    /* Clear and disable the interrupt. */
    pd->intr1 = PDSS_INTR1_V5V_CHANGED;
    pd->intr1_mask &= ~PDSS_INTR1_MASK_V5V_CHANGED_MASK;

    if (context->supplyChangeCbk != NULL)
    {
        /* Store the current status of the V5V supply */
#if defined(CY_IP_MXUSBPD)
        temp = ((pd->intr1_status & PDSS_INTR1_STATUS_V5V_STATUS) != 0);
#elif defined(CY_IP_M0S8USBPD)
        temp = ((pd->status & PDSS_STATUS_V5V_STATUS) != 0);
#endif

        /* Notify application layer about absence of VSYS supply. */
        context->supplyChangeCbk (context, CY_USBPD_SUPPLY_V5V, temp);
    }

    /* Re-enable the interrupt. */
    pd->intr1_mask |= PDSS_INTR1_MASK_V5V_CHANGED_MASK;
#else
    CY_UNUSED_PARAMETER(context);
#endif /* PMG1_V5V_CHANGE_DETECT */
}


/** \cond DOXYGEN_HIDE */
void Cy_USBPD_Vbus_LoadChangeISR_En(cy_stc_usbpd_context_t *context, uint32_t cur, 
                                   uint8_t filter, cy_cb_usbpd_vbus_load_chg_t cbk)
{
    CY_UNUSED_PARAMETER(context);
    CY_UNUSED_PARAMETER(cur);
    CY_UNUSED_PARAMETER(filter);
    (void)(cy_cb_usbpd_vbus_load_chg_t)cbk;
}
/** \endcond */

#ifdef PDL_VBUS_RCP_ENABLE
#define RCP_GAIN_VALUE                  (100u)
#define SFLASH_RCP_TRIM_VBUS_OV         (0x0FFFF411u)
#define SFLASH_RCP_TRIM_CSA_HOT         (0x0FFFF410u)
#define SFLASH_RCP_TRIM_CSA_COLD        (0x0FFFF41Cu)

#define RCP_REF_VOLT_MIN                (130U)
#define RCP_REF_VOLT_STEP               (10U)
#define RCP_REF_MAX_STEP                (199U)

#define SFLASH_RCP_TRIM_ROOM_FLAG           (0x0FFFF48Bu)
#define SFLASH_RCP_TRIM_400MA_ROOM          (0x0FFFF464u)
#define SFLASH_RCP_TRIM_400MA_HOT           (0x0FFFF438u)
#define SFLASH_RCP_TRIM_400MA_COLD          (0x0FFFF44Eu) 
#define SFLASH_RCP_TRIM_VBUS_OV_5P4V_ROOM   (0x0FFFF481u)
#define SFLASH_RCP_TRIM_VBUS_OV_5P4V_HOT    (0x0FFFF473u)
#define SFLASH_RCP_TRIM_VBUS_OV_5P4V_COLD   (0x0FFFF47Au)
#endif /* PDL_VBUS_RCP_ENABLE */

/*******************************************************************************
* Function Name: Cy_USBPD_Fault_Vbus_RcpEnable
****************************************************************************//**
*
* Enable Reverse Current Protection (RCP).
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \param volt
* Contract Voltage in mV units.
*
* \param cb
* Callback function to be called on fault detection.
*
* \return
* None
*
*******************************************************************************/
void Cy_USBPD_Fault_Vbus_RcpEnable(cy_stc_usbpd_context_t *context, uint16_t volt, cy_cb_vbus_fault_t cb)
{
#if (defined(PDL_VBUS_RCP_ENABLE) && (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP)))
    PPDSS_REGS_T pd = context->base;
    uint32_t regval = 0;
    uint32_t vref = 0;
#if defined(CY_DEVICE_CCG6)    
    uint16_t trim_rcp_offset_value = 0;
#endif /* defined(CY_DEVICE_CCG6) */
    uint32_t state = 0;
#if defined(CY_DEVICE_PMG1S3)
    PPDSS_TRIMS_REGS_T trimRegs = context->trimsBase;
    uint32_t x1, x2, y1, y2, x = 0UL;
    int32_t c = 0;
#endif /* defined(CY_DEVICE_PMG1S3) */

    /* Register RCP Callback. */
    context->vbusRcpCbk = cb;
    state = Cy_SysLib_EnterCriticalSection();
    
#if defined(CY_DEVICE_CCG6)
    /* Enable pull-up of P_CTRL on VBus side when RCP detected. */
    pd->pgdo_pu_3_cfg |= (PDSS_PGDO_PU_3_CFG_PGDO_EN_RCP_LV | PDSS_PGDO_PU_3_CFG_PGDO_EN_VBUS_OV_LV);

    Cy_USBPD_Fault_FetAutoModeDisable (context, true, CY_USBPD_VBUS_FILTER_ID_HSCSA_RCP);

    /** CSA RCP detection configuration based on current measurement **/
    regval = pd->csa_rcp_0_ctrl;
    /* Power up the CSA block. */
    regval &= ~PDSS_CSA_RCP_0_CTRL_PD_CSA;
    /* Default operational settings. */
    regval |= PDSS_CSA_RCP_0_CTRL_SEL_OUT_D | PDSS_CSA_RCP_0_CTRL_CSA_ISO_N;
    /* Clear the gain and bw settings. */
    regval &= ~(PDSS_CSA_RCP_0_CTRL_AV1_MASK | PDSS_CSA_RCP_0_CTRL_BW_MASK);

    /* Write out CSA_RCP_0_CTRL to enable the block and outputs. */
    pd->csa_rcp_0_ctrl = regval;

    /* Set CSA gain of 100. */
    regval |=  0x07U;
    /* Set analog bandwidth. */
    regval |= (0x03UL << PDSS_CSA_RCP_0_CTRL_BW_POS);

    /* Write out CSA_RCP_0_CTRL. */
    pd->csa_rcp_0_ctrl = regval;

    /*
     * Configure Reference for RCP CSA comparator:
     * We use the average of the HOT and COLD RCP trims taken from SFLASH.
     */
    vref = ((uint32_t)(*((const uint8_t *) (SFLASH_RCP_TRIM_CSA_HOT))) + (uint32_t)(*((const uint8_t *) (SFLASH_RCP_TRIM_CSA_COLD))) ) / 2UL;
    Cy_USBPD_SetRefgenVoltage (context, (uint8_t)vref, (uint8_t)CY_USBPD_VREF_RCP_CSA);
    Cy_SysLib_DelayUs (50U);

    /* Enable the RCP CSA comparator */
    pd->csa_rcp_1_ctrl |= PDSS_CSA_RCP_1_CTRL_CSA_EN_LV;
    Cy_SysLib_DelayUs (100U);
    PDSS_TRIMS->trim_csa_rcp1_4 |= (1U << 7);

    /* Bypassing filter may cause false rc triggers. Leaving filter enabled with a 5 us debounce period. */
    regval = pd->intr13_cfg_csa_rcp_hs;
    regval &= ~(PDSS_INTR13_CFG_CSA_RCP_HS_CSA_OUT_FILT_EN | PDSS_INTR13_CFG_CSA_RCP_HS_CSA_OUT_FILT_CFG_MASK |
            PDSS_INTR13_CFG_CSA_RCP_HS_CSA_OUT_FILT_SEL_MASK | PDSS_INTR13_CFG_CSA_RCP_HS_CSA_OUT_FILT_RESET |
            PDSS_INTR13_CFG_CSA_RCP_HS_CSA_OUT_FILT_BYPASS);

    /* Set edge detection. */
    regval |= ((uint32_t)CY_USBPD_VBUS_FILTER_CFG_POS_EN_NEG_DIS << PDSS_INTR13_CFG_CSA_RCP_HS_CSA_OUT_FILT_CFG_POS);
    regval |= PDSS_INTR13_CFG_CSA_RCP_HS_CSA_OUT_FILT_EN | PDSS_INTR13_CFG_CSA_RCP_HS_CSA_OUT_DPSLP_MODE;
    pd->intr13_cfg_csa_rcp_hs = regval;

    /* Clear and enable the RCP CSA Detect interrupt. */
    pd->intr13 = PDSS_INTR13_CSA_OUT_CHANGED;
    pd->intr13_mask |= PDSS_INTR13_MASK_CSA_OUT_CHANGED_MASK;

    /** RCP detection configuration based on different RCP COMP **/
    /* Enable the RCP comparator */

    /* Set the RCP trim offset value based on the source voltage: Increment the
     * offset for a 3V rise in voltage. */
    if (volt > 5000U)
    {
        trim_rcp_offset_value = (uint16_t)PDSS_TRIMS->trim_csa_rcp1_2 + ((volt - 5000U) / 3000U);
        if (trim_rcp_offset_value > 7U)
        {
            trim_rcp_offset_value = 7U;
        }

        PDSS_TRIMS->trim_csa_rcp1_2 = (uint8_t)trim_rcp_offset_value;
    }

    PDSS_TRIMS->trim_csa_rcp1_4 &= ~(1U << 5);      /* Reset the latch */
    pd->csa_rcp_1_ctrl |= PDSS_CSA_RCP_1_CTRL_RCP_EN_LV;
    Cy_SysLib_DelayUs (20U);
    PDSS_TRIMS->trim_csa_rcp1_4 |= (1U << 5);        /* Enable the latch. */

    /* Bypassing filter may cause false rc triggers. Leaving filter enabled with a 5 us debounce period. */
    regval = pd->intr13_cfg_csa_rcp_hs;
    regval &= ~(PDSS_INTR13_CFG_CSA_RCP_HS_CSA_COMP_OUT_FILT_EN |
            PDSS_INTR13_CFG_CSA_RCP_HS_CSA_COMP_OUT_FILT_CFG_MASK |
            PDSS_INTR13_CFG_CSA_RCP_HS_CSA_COMP_OUT_FILT_SEL_MASK |
            PDSS_INTR13_CFG_CSA_RCP_HS_CSA_COMP_OUT_FILT_RESET |
            PDSS_INTR13_CFG_CSA_RCP_HS_CSA_COMP_OUT_FILT_BYPASS);

    /* Set edge detection. */
    regval |= ((uint32_t)CY_USBPD_VBUS_FILTER_CFG_POS_EN_NEG_DIS << PDSS_INTR13_CFG_CSA_RCP_HS_CSA_COMP_OUT_FILT_CFG_POS);
    regval |= PDSS_INTR13_CFG_CSA_RCP_HS_CSA_COMP_OUT_FILT_EN | PDSS_INTR13_CFG_CSA_RCP_HS_CSA_COMP_OUT_DPSLP_MODE;
    pd->intr13_cfg_csa_rcp_hs = regval;

    /* Clear and enable the RCP Comparator Detect interrupt. */
    pd->intr13 = PDSS_INTR13_CSA_COMP_OUT_CHANGED;
    pd->intr13_mask |= PDSS_INTR13_MASK_CSA_COMP_OUT_CHANGED_MASK;

    /**** RCP detection configuration based on VBUS OV detect ***/

    /* Reset the latch. */
    PDSS_TRIMS->trim_csa_rcp1_4 &= ~(1U << 6);

    if (volt <= 9000U)
    {
        /* If the source voltage is less than or equal to 9.0 V, we use the 20% Vbus divider for comparison. */
        pd->csa_rcp_1_ctrl &= ~(1UL << 12);

        /* If the source voltage is less than 5.5 V, we can use the trim data provided in SFLASH. */
        if (volt <= 5500U)
        {
            vref = *((const uint8_t *)(SFLASH_RCP_TRIM_VBUS_OV));
        }
        else
        {
            /* Vref calculated theoretically by adding 20% threshold to VBUS and then dividing it by 10 */
            vref = (uint32_t)((((volt * 12UL) / 50UL) - RCP_REF_VOLT_MIN) / RCP_REF_VOLT_STEP);
        }
    }
    else if (volt <= 15000U)
    {
        /* Use 10% VBUS divider for greater than 9V contract */
        pd->csa_rcp_1_ctrl |= (1UL << 12);

        /* Vref calculated theoretically by adding 20% threshold to VBUS and then dividing it by 10 */
        vref = (uint32_t)((((volt * 12UL) / 100UL) - RCP_REF_VOLT_MIN) / RCP_REF_VOLT_STEP);
    }
    else
    {
        /* Do nothing. */
    }

    if (volt <= 15000U)
    {
        if (vref > RCP_REF_MAX_STEP)
        {
            vref = RCP_REF_MAX_STEP;
        }
        /* Program the reference voltage. */
        Cy_USBPD_SetRefgenVoltage (context, (uint8_t)vref, (uint8_t)CY_USBPD_VREF_RCP_OVP);

        /* Enable the VBUS OV Detect comparator */
        pd->csa_rcp_1_ctrl |= PDSS_CSA_RCP_1_CTRL_RCP_VBUS_OVP_EN_LV;
        Cy_SysLib_DelayUs (20U);
        PDSS_TRIMS->trim_csa_rcp1_4 |= (1U << 6);

        /* Bypassing filter may cause false triggers. Leaving filter enabled with a 5 us debounce period. */
        regval = pd->intr13_cfg_csa_rcp_ovp_hs;
        regval &= ~(PDSS_INTR13_CFG_CSA_RCP_OVP_HS_CSA_VBUS_OVP_FILT_EN |
                PDSS_INTR13_CFG_CSA_RCP_OVP_HS_CSA_VBUS_OVP_FILT_CFG_MASK |
                PDSS_INTR13_CFG_CSA_RCP_OVP_HS_CSA_VBUS_OVP_FILT_SEL_MASK |
                PDSS_INTR13_CFG_CSA_RCP_OVP_HS_CSA_VBUS_OVP_FILT_RESET |
                PDSS_INTR13_CFG_CSA_RCP_OVP_HS_CSA_VBUS_OVP_FILT_BYPASS);

        /* Set edge detection. */
        regval |= ((uint32_t)CY_USBPD_VBUS_FILTER_CFG_POS_EN_NEG_DIS << PDSS_INTR13_CFG_CSA_RCP_OVP_HS_CSA_VBUS_OVP_FILT_CFG_POS);
        regval |= PDSS_INTR13_CFG_CSA_RCP_OVP_HS_CSA_VBUS_OVP_FILT_EN |
            PDSS_INTR13_CFG_CSA_RCP_OVP_HS_CSA_VBUS_OVP_DPSLP_MODE;
        pd->intr13_cfg_csa_rcp_ovp_hs = regval;

        /* Clear and enable the RCP VBUS OVP Detect interrupt. */
        pd->intr13 = PDSS_INTR13_CSA_VBUS_OVP_CHANGED;
        pd->intr13_mask |= PDSS_INTR13_MASK_CSA_VBUS_OVP_CHANGED_MASK;
    }
#elif defined (CY_DEVICE_PMG1S3)
    /* Disable FET automode */
    Cy_USBPD_Fault_FetAutoModeDisable (context, true, CY_USBPD_VBUS_FILTER_ID_HSCSA_RCP);

#if defined(USE_RCP_ROOM_TRIMS)    
    if (*((volatile uint8_t *)(SFLASH_RCP_TRIM_ROOM_FLAG + (uint16_t)(context->port * 0x100u))) == 1u)
    {
        vref = *((volatile uint8_t *)(SFLASH_RCP_TRIM_400MA_ROOM + 1UL + (uint16_t)(context->port * 0x100u)));
    }
    else
#endif /* defined(USE_RCP_ROOM_TRIMS) */
    {
        vref = (uint8_t)((*((volatile uint8_t *)(SFLASH_RCP_TRIM_400MA_HOT + 1UL + (uint16_t)(context->port * 0x100u))) + 
                        (*((volatile uint8_t *)(SFLASH_RCP_TRIM_400MA_COLD + 1UL  + (uint16_t)(context->port * 0x100u))))) / 2U);
    }
    
    /* Copy the trim value from SFLASH into the SCP Trims Register */
    trimRegs->trim_scp_rcp_1 = (uint32_t)vref;
#if defined(USE_RCP_ROOM_TRIMS)
    if (*((volatile uint8_t *)(SFLASH_RCP_TRIM_ROOM_FLAG + (uint16_t)(context->port * 0x100u))) == 1u)
    {
        if(volt <= 5000U)
        {
            /* Set the VBUS divider to 33% */
            pd->scp_rcp_1_ctrl &= ~(1UL << 23);
            pd->scp_rcp_1_ctrl |= (1UL << 24);
            vref = *((volatile uint8_t *)(SFLASH_RCP_TRIM_VBUS_OV_5P4V_ROOM + (uint16_t)(context->port * 0x100u)));
        }
        else if(volt < 20000U)
        {
            /* Set the VBUS divider to 10% */
            pd->scp_rcp_1_ctrl &= ~(1UL << 24);
            pd->scp_rcp_1_ctrl |= (1UL << 23);

            y1 = *((volatile uint8_t *)(SFLASH_RCP_TRIM_VBUS_OV_5P4V_ROOM + 1UL + (uint16_t)(context->port * 0x100u)));
            y2 = *((volatile uint8_t *)(SFLASH_RCP_TRIM_VBUS_OV_5P4V_ROOM + 2UL + (uint16_t)(context->port * 0x100u)));
            x1 = 6000U;
            x2 = 20000U;
        }
        else
        {
            /* Set the VBUS divider to 6% */
            pd->scp_rcp_1_ctrl &= ~((1UL << 24) | (1UL << 23));
            
            y1 = *((volatile uint8_t *)(SFLASH_RCP_TRIM_VBUS_OV_5P4V_ROOM + 3UL + (uint16_t)(context->port * 0x100u)));
            y2 = *((volatile uint8_t *)(SFLASH_RCP_TRIM_VBUS_OV_5P4V_ROOM + 4UL + (uint16_t)(context->port * 0x100u)));
            x1 = 20100U;
            x2 = 24000U;
        }
    }
    else
#endif /* defined(USE_RCP_ROOM_TRIMS) */
    {
        if(volt <= 5000U)
        {
            /* Set the VBUS divider to 33% */
            pd->scp_rcp_1_ctrl &= ~(1UL << 23);
            pd->scp_rcp_1_ctrl |= (1UL << 24);
            vref = (uint8_t)((*((volatile uint8_t *)(SFLASH_RCP_TRIM_VBUS_OV_5P4V_HOT + (uint16_t)(context->port * 0x100u))) + 
                             (*((volatile uint8_t *)(SFLASH_RCP_TRIM_VBUS_OV_5P4V_COLD + (uint16_t)(context->port * 0x100u))))) / 2U);
        }
        else if(volt < 20000U)
        {
            /* Set the VBUS divider to 10% */
            pd->scp_rcp_1_ctrl &= ~(1UL << 24);
            pd->scp_rcp_1_ctrl |= (1UL << 23);

            y1 = (uint8_t)((*((volatile uint8_t *)(SFLASH_RCP_TRIM_VBUS_OV_5P4V_HOT + 1UL + (uint16_t)(context->port * 0x100u))) + 
                           (*((volatile uint8_t *)(SFLASH_RCP_TRIM_VBUS_OV_5P4V_COLD + 1UL  + (uint16_t)(context->port * 0x100u))))) / 2U);
            y2 = (uint8_t)((*((volatile uint8_t *)(SFLASH_RCP_TRIM_VBUS_OV_5P4V_HOT + 2UL + (uint16_t)(context->port * 0x100u))) + 
                           (*((volatile uint8_t *)(SFLASH_RCP_TRIM_VBUS_OV_5P4V_COLD + 2UL  + (uint16_t)(context->port * 0x100u))))) / 2U);
            x1 = 6000U;
            x2 = 20000U;
        }
        else
        {
            /* Set the VBUS divider to 6% */
            pd->scp_rcp_1_ctrl &= ~((1UL << 24) | (1UL << 23));

            y1 = (uint8_t)((*((volatile uint8_t *)(SFLASH_RCP_TRIM_VBUS_OV_5P4V_HOT + 3UL + (uint16_t)(context->port * 0x100u))) + 
                           (*((volatile uint8_t *)(SFLASH_RCP_TRIM_VBUS_OV_5P4V_COLD + 3UL  + (uint16_t)(context->port * 0x100u))))) / 2U);
            y2 = (uint8_t)((*((volatile uint8_t *)(SFLASH_RCP_TRIM_VBUS_OV_5P4V_HOT + 4UL + (uint16_t)(context->port * 0x100u))) + 
                           (*((volatile uint8_t *)(SFLASH_RCP_TRIM_VBUS_OV_5P4V_COLD + 4UL  + (uint16_t)(context->port * 0x100u))))) / 2U);
            x1 = 20100U;
            x2 = 24000U;
        }
    }
    
    if(volt > 5000U)
    {
        int32_t value = 0;
        /* VBUS calculated theoretically by adding 20% threshold to VBUS */
        x = (uint32_t)((volt * 12UL) / 10UL);
        
        value = ((int32_t)y2 - (int32_t)y1) * (int32_t)x1;

        c = ((int32_t)y1 - (value / ((int32_t)x2 - (int32_t)x1)));
        
        vref = (uint32_t)(((y2 - y1)*x)/(x2 - x1));
        if (c < 0)
        {
            int temp = -c;
            vref -= (uint32_t)temp;
        }
        else
        {
            vref += (uint32_t)c;
        }
    }

    if (vref > RCP_REF_MAX_STEP)
    {
        vref = RCP_REF_MAX_STEP;
    }
    /* Program the reference voltage. */
    Cy_USBPD_SetRefgenVoltage (context, (uint8_t)vref, (uint8_t)CY_USBPD_VREF_RCP_OVP);
    
    /* Power-Up the SCP-RCP hard-IP */
    pd->scp_rcp_0_ctrl &= ~PDSS_SCP_RCP_0_CTRL_SCP_RCP_PD;
    Cy_SysLib_DelayUs(10);
    /* Power-Up the RCP block */
    pd->scp_rcp_0_ctrl &= ~PDSS_SCP_RCP_0_CTRL_SCP_RCP_PD_RCP; 
    Cy_SysLib_DelayUs(10);
    pd->scp_rcp_0_ctrl |= PDSS_SCP_RCP_0_CTRL_SCP_RCP_ISO_N | PDSS_SCP_RCP_0_CTRL_SCP_RCP_VBUS_OVP_EN;
  
    /* Remove the RCP latch from Reset mode and put it in sample mode*/
    pd->scp_rcp_0_ctrl &= ~PDSS_SCP_RCP_0_CTRL_SCP_RCP_T_RCP_RST_LATCH_N;
    Cy_SysLib_DelayUs(10);
    pd->scp_rcp_0_ctrl |= PDSS_SCP_RCP_0_CTRL_SCP_RCP_T_RCP_RST_LATCH_N;
    
    /* Bypassing filter may cause false rc triggers. Leaving filter enabled with a 5 us debounce period. */
    regval = pd->intr13_cfg_csa_rcp_hs;
    regval &= ~(PDSS_INTR13_CFG_CSA_RCP_HS_CSA_OUT_FILT_EN | PDSS_INTR13_CFG_CSA_RCP_HS_CSA_OUT_FILT_CFG_MASK |
            PDSS_INTR13_CFG_CSA_RCP_HS_CSA_OUT_FILT_SEL_MASK | PDSS_INTR13_CFG_CSA_RCP_HS_CSA_OUT_FILT_RESET |
            PDSS_INTR13_CFG_CSA_RCP_HS_CSA_OUT_FILT_BYPASS | 
            PDSS_INTR13_CFG_CSA_RCP_HS_CSA_COMP_OUT_FILT_EN |
            PDSS_INTR13_CFG_CSA_RCP_HS_CSA_COMP_OUT_FILT_CFG_MASK |
            PDSS_INTR13_CFG_CSA_RCP_HS_CSA_COMP_OUT_FILT_SEL_MASK |
            PDSS_INTR13_CFG_CSA_RCP_HS_CSA_COMP_OUT_FILT_RESET |
            PDSS_INTR13_CFG_CSA_RCP_HS_CSA_COMP_OUT_FILT_BYPASS);          
    /* Set edge detection. */
    regval |= ((uint32_t)CY_USBPD_VBUS_FILTER_CFG_POS_EN_NEG_DIS << PDSS_INTR13_CFG_CSA_RCP_HS_CSA_OUT_FILT_CFG_POS);
    regval |= PDSS_INTR13_CFG_CSA_RCP_HS_CSA_OUT_FILT_EN | PDSS_INTR13_CFG_CSA_RCP_HS_CSA_OUT_DPSLP_MODE;
    regval |= ((uint32_t)CY_USBPD_VBUS_FILTER_CFG_POS_EN_NEG_DIS << PDSS_INTR13_CFG_CSA_RCP_HS_CSA_COMP_OUT_FILT_CFG_POS);
    regval |= PDSS_INTR13_CFG_CSA_RCP_HS_CSA_COMP_OUT_FILT_EN | PDSS_INTR13_CFG_CSA_RCP_HS_CSA_COMP_OUT_DPSLP_MODE;   
    pd->intr13_cfg_csa_rcp_hs = regval;
    
    /* Bypassing filter may cause false triggers. Leaving filter enabled with a 5 us debounce period. */
    regval = pd->intr13_cfg_csa_rcp_ovp_hs;
    regval &= ~(PDSS_INTR13_CFG_CSA_RCP_OVP_HS_CSA_VBUS_OVP_FILT_EN |
            PDSS_INTR13_CFG_CSA_RCP_OVP_HS_CSA_VBUS_OVP_FILT_CFG_MASK |
            PDSS_INTR13_CFG_CSA_RCP_OVP_HS_CSA_VBUS_OVP_FILT_SEL_MASK |
            PDSS_INTR13_CFG_CSA_RCP_OVP_HS_CSA_VBUS_OVP_FILT_RESET |
            PDSS_INTR13_CFG_CSA_RCP_OVP_HS_CSA_VBUS_OVP_FILT_BYPASS);
    /* Set edge detection. */
    regval |= ((uint32_t)CY_USBPD_VBUS_FILTER_CFG_POS_EN_NEG_DIS << PDSS_INTR13_CFG_CSA_RCP_OVP_HS_CSA_VBUS_OVP_FILT_CFG_POS);
    regval |= PDSS_INTR13_CFG_CSA_RCP_OVP_HS_CSA_VBUS_OVP_FILT_EN |
        PDSS_INTR13_CFG_CSA_RCP_OVP_HS_CSA_VBUS_OVP_DPSLP_MODE;
    pd->intr13_cfg_csa_rcp_ovp_hs = regval;    
    
    /* Clear and enable the RCP Detect interrupt. */
    pd->intr13 = (PDSS_INTR13_CSA_OUT_CHANGED | PDSS_INTR13_CSA_COMP_OUT_CHANGED | PDSS_INTR13_CSA_VBUS_OVP_CHANGED);
    pd->intr13_mask |= (PDSS_INTR13_MASK_CSA_OUT_CHANGED_MASK | PDSS_INTR13_MASK_CSA_COMP_OUT_CHANGED_MASK | PDSS_INTR13_MASK_CSA_VBUS_OVP_CHANGED_MASK);
#elif defined (CY_DEVICE_CCG6DF_CFP)
    CY_UNUSED_PARAMETER(vref);
    /* Disable FET automode */
    Cy_USBPD_Fault_FetAutoModeDisable (context, true, CY_USBPD_VBUS_FILTER_ID_HSCSA_RCP);

    /* Power-Up the RCP block */
    pd->pd_40rcp_ctrl &= ~PDSS_PD_40RCP_CTRL_RCP_PD; 
    Cy_SysLib_DelayUs(10);
    pd->pd_40rcp_ctrl |= PDSS_PD_40RCP_CTRL_ISO_N;
  
    /* Remove the RCP latch from Reset mode and put it in sample mode*/
    pd->pd_40rcp_ctrl &= ~PDSS_PD_40RCP_CTRL_RCP_COMP_OUT_EN;
    Cy_SysLib_DelayUs(100);
    pd->pd_40rcp_ctrl |= PDSS_PD_40RCP_CTRL_RCP_COMP_OUT_EN;
    
    /* Bypass the rcp filter on CFP. Latch path is enabled hence, glitch filter has no effect. */
    regval = pd->intr13_cfg_csa_rcp_hs;
    regval &= ~(PDSS_INTR13_CFG_CSA_RCP_HS_CSA_COMP_OUT_FILT_EN |
            PDSS_INTR13_CFG_CSA_RCP_HS_CSA_COMP_OUT_FILT_CFG_MASK |
            PDSS_INTR13_CFG_CSA_RCP_HS_CSA_COMP_OUT_FILT_SEL_MASK |
            PDSS_INTR13_CFG_CSA_RCP_HS_CSA_COMP_OUT_FILT_RESET |
            PDSS_INTR13_CFG_CSA_RCP_HS_CSA_COMP_OUT_FILT_BYPASS);          
    /* Set edge detection. */
    regval |= ((uint32_t)CY_USBPD_VBUS_FILTER_CFG_POS_EN_NEG_DIS << PDSS_INTR13_CFG_CSA_RCP_HS_CSA_COMP_OUT_FILT_CFG_POS);
    regval |= PDSS_INTR13_CFG_CSA_RCP_HS_CSA_COMP_OUT_FILT_BYPASS;
    pd->intr13_cfg_csa_rcp_hs = regval;

    /* Clear and enable the RCP Detect interrupt. */
    pd->intr13 = PDSS_INTR13_CSA_COMP_OUT_CHANGED;
    pd->intr13_mask |= PDSS_INTR13_MASK_CSA_COMP_OUT_CHANGED_MASK;
#endif /* CY_DEVICE */

    /* Auto FET turn off mode. */
    Cy_USBPD_Fault_FetAutoModeEnable (context, true, CY_USBPD_VBUS_FILTER_ID_HSCSA_RCP);
    Cy_SysLib_ExitCriticalSection (state);
    CY_UNUSED_PARAMETER(volt);
#else
    CY_UNUSED_PARAMETER(context);
    CY_UNUSED_PARAMETER(volt);
    (void)(cy_cb_vbus_fault_t)cb;
#endif /* (defined(PDL_VBUS_RCP_ENABLE) && defined(CY_DEVICE_CCG6)) */
}

/*******************************************************************************
* Function Name: Cy_USBPD_Fault_Vbus_RcpDisable
****************************************************************************//**
*
* Disable Reverse Current Protection (RCP) control.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \return
* None
*
*******************************************************************************/
void Cy_USBPD_Fault_Vbus_RcpDisable(cy_stc_usbpd_context_t *context)
{
#if (defined(PDL_VBUS_RCP_ENABLE) && (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP)))
    PPDSS_REGS_T pd = context->base;
    uint32_t state;
#if defined(CY_DEVICE_CCG6)    
    uint32_t regval = 0;
#endif /* defined(CY_DEVICE_CCG6) */
    state = Cy_SysLib_EnterCriticalSection ();

    /* Deregister the callback. */
    context->vbusRcpCbk = NULL;

#if (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP))
#if defined(CY_DEVICE_CCG6)
    /* Power down the CSA RCP block */
    pd->csa_rcp_0_ctrl |= PDSS_CSA_RCP_0_CTRL_PD_CSA;
    pd->csa_rcp_0_ctrl &= ~(PDSS_CSA_RCP_0_CTRL_SEL_OUT_D | PDSS_CSA_RCP_0_CTRL_CSA_ISO_N);

    pd->intr13_mask &= ~(PDSS_INTR13_MASK_CSA_OUT_CHANGED_MASK | PDSS_INTR13_MASK_CSA_COMP_OUT_CHANGED_MASK |
            PDSS_INTR13_MASK_CSA_VBUS_OVP_CHANGED_MASK);
            
    regval |= (PDSS_CSA_RCP_1_CTRL_CSA_EN_LV | PDSS_CSA_RCP_1_CTRL_RCP_EN_LV | PDSS_CSA_RCP_1_CTRL_RCP_VBUS_OVP_EN_LV);
    pd->csa_rcp_1_ctrl &= ~regval;
    PDSS_TRIMS->trim_csa_rcp1_4 &= ~((1U << 5) | (1U << 6) | (1U << 7));

    /* Clear the interrupts. */
    pd->intr13 = (PDSS_INTR13_CSA_OUT_CHANGED | PDSS_INTR13_CSA_COMP_OUT_CHANGED | PDSS_INTR13_CSA_VBUS_OVP_CHANGED);
#elif defined(CY_DEVICE_PMG1S3)
    pd->intr13_mask &= ~(PDSS_INTR13_MASK_CSA_OUT_CHANGED_MASK | PDSS_INTR13_MASK_CSA_COMP_OUT_CHANGED_MASK |
            PDSS_INTR13_MASK_CSA_VBUS_OVP_CHANGED_MASK);
    pd->scp_rcp_0_ctrl |= PDSS_SCP_RCP_0_CTRL_SCP_RCP_PD_RCP; 
    pd->scp_rcp_0_ctrl &= ~(PDSS_SCP_RCP_0_CTRL_SCP_RCP_ISO_N | PDSS_SCP_RCP_0_CTRL_SCP_RCP_VBUS_OVP_EN | PDSS_SCP_RCP_0_CTRL_SCP_RCP_T_RCP_RST_LATCH_N);

    /* Clear the interrupts. */
    pd->intr13 = (PDSS_INTR13_CSA_OUT_CHANGED | PDSS_INTR13_CSA_COMP_OUT_CHANGED | PDSS_INTR13_CSA_VBUS_OVP_CHANGED);
#elif defined(CY_DEVICE_CCG6DF_CFP)
    pd->intr13_mask &= ~PDSS_INTR13_MASK_CSA_COMP_OUT_CHANGED_MASK;
    pd->pd_40rcp_ctrl |= PDSS_PD_40RCP_CTRL_RCP_PD; 
    pd->pd_40rcp_ctrl &= ~(PDSS_PD_40RCP_CTRL_ISO_N | PDSS_PD_40RCP_CTRL_RCP_COMP_OUT_EN);

    /* Clear the interrupts. */
    pd->intr13 = PDSS_INTR13_CSA_COMP_OUT_CHANGED;
#endif /* CY_DEVICE */

    /* Remove RCP as source. */
    Cy_USBPD_Fault_FetAutoModeDisable (context, true, CY_USBPD_VBUS_FILTER_ID_HSCSA_RCP);
#endif /* defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP) */
    Cy_SysLib_ExitCriticalSection (state);
#else
    CY_UNUSED_PARAMETER(context);
#endif /* (defined(PDL_VBUS_RCP_ENABLE) && defined(CY_DEVICE_CCG6)) */
}

/*******************************************************************************
* Function Name: Cy_USBPD_Fault_Vbus_RcpIntrHandler
****************************************************************************//**
*
* VBUS RCP fault interrupt handler function.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \return
* None
*
*******************************************************************************/
void Cy_USBPD_Fault_Vbus_RcpIntrHandler(cy_stc_usbpd_context_t *context)
{
#if (defined(PDL_VBUS_RCP_ENABLE) && (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP)))
    PPDSS_REGS_T pd = context->base;

#if defined(CY_DEVICE_CCG6DF_CFP)
    /* Mask used to check if RCP interrupt has occurred. */
    const uint32_t mask = PDSS_INTR13_MASKED_CSA_COMP_OUT_CHANGED_MASKED;
#else
    /* Mask used to check if RCP interrupt has occurred. */
    const uint32_t mask = PDSS_INTR13_MASKED_CSA_OUT_CHANGED_MASKED | \
                          PDSS_INTR13_MASKED_CSA_COMP_OUT_CHANGED_MASKED | \
                          PDSS_INTR13_MASKED_CSA_VBUS_OVP_CHANGED_MASKED;
#endif /* defined(CY_DEVICE_CCG6DF_CFP) */
    /*
     * RCP interrupt handling for CCG6.
     * Provider FET would have been turned off. We only need to clear the interrupt and start recovery.
     */
    if ((pd->intr13_masked & mask) != 0U)
    {
#if defined(CY_DEVICE_CCG6)
        /* Make sure P_CTRL does not get pulled up on Vin side. */
        pd->pgdo_pu_3_cfg = (PDSS_PGDO_PU_3_CFG_PGDO_EN_RCP_LV | PDSS_PGDO_PU_3_CFG_PGDO_EN_VBUS_OV_LV);
#endif /* defined(CY_DEVICE_CCG6) */

        /* Clear and disable all RCP related interrupts. */
        pd->intr13_mask &= ~(mask);
        pd->intr13 = mask;
#if defined(CY_DEVICE_CCG6)
        /* Reset PGDO edge detector logic. */
        Cy_USBPD_Vbus_GdrvRstEdgeDet(context, true);
#endif /* defined(CY_DEVICE_CCG6) */

        /* Invoke RCP callback. */
        if (context->vbusRcpCbk != NULL)
        {
            (void)context->vbusRcpCbk(context, true);
        }
    }
#else
    CY_UNUSED_PARAMETER(context);
#endif /* (defined(PDL_VBUS_RCP_ENABLE) && defined(CY_DEVICE_CCG6)) */
}

/*******************************************************************************
* Function Name: Cy_USBPD_Vbus_MeasureCur
****************************************************************************//**
*
* Sample the VBus current using ADC.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
*
* \return uint16_t
* Returns sampled current
*
*******************************************************************************/
uint16_t Cy_USBPD_Vbus_MeasureCur(cy_stc_usbpd_context_t *context)
{
    uint16_t current = 0;

#if (defined(CY_DEVICE_CCG6))
    uint8_t level;
    PPDSS_REGS_T pd = context->base;
    uint32_t state;

    state = Cy_SysLib_EnterCriticalSection();

    (void)Cy_USBPD_Adc_Calibrate(context, CY_USBPD_ADC_ID_0);

    /* Disconnect VBus divider from AMUX-B. */
    pd->amux_nhv_ctrl &= ~(1U << AMUX_ADC_CCG6_VBUS_DIV_EN_POS);
    Cy_SysLib_DelayUs (50);

    /* Use ADFT to connect the CSA stage-1 output to AMUX Bus B. */
    pd->csa_scp_0_ctrl = ((pd->csa_scp_0_ctrl & ~PDSS_CSA_SCP_0_CTRL_CSA_ADFT_CTRL_MASK) |
            (15UL << PDSS_CSA_SCP_0_CTRL_CSA_ADFT_CTRL_POS));
    Cy_SysLib_DelayUs (100);

    /* Sample and log the ADC reading. */
    level = Cy_USBPD_Adc_Sample(context, CY_USBPD_ADC_ID_0, CY_USBPD_ADC_INPUT_AMUX_B);

    /* Disconnect the stage-1 CSA output from AMUX. */
    pd->csa_scp_0_ctrl &= ~PDSS_CSA_SCP_0_CTRL_CSA_ADFT_CTRL_MASK;
    Cy_SysLib_DelayUs (50);

    /* Reconnect VBus divider to AMUX-B. */
    pd->amux_nhv_ctrl |= (1U << AMUX_ADC_CCG6_VBUS_DIV_EN_POS);

    Cy_SysLib_ExitCriticalSection(state);

    /* Calculate the amplified sense voltage in mV from the ADC reading. */
    current = ((level * context->adcVdddMv[CY_USBPD_ADC_ID_0]) / 256U);
    if (GET_VBUS_OCP_TABLE(context)->senseRes == 10U)
    {
        /*
           Convert to current in 10 mA units.
           We need to divide by gain (20) times the sense impedance (10 mOhm).
           */
        current = current / 2u;
    }
    else
    {
        /*
           Convert to current in 10 mA units.
           We need to divide by gain (50) times the sense impedance (5 mOhm).
           */
        current = (current * 2u) / 5u;
    }
#endif /* (CY_DEVICE_CCG6) */
#if (defined(CY_DEVICE_CCG6DF_CFP))
    uint32_t regval;
    uint32_t vsense_ref_out;
    uint32_t state;
    PPDSS_REGS_T pd = context->base;
    uint32_t amux_nhv_ctrl_clr;
    uint32_t amux_nhv_ctrl_set;
    state = Cy_SysLib_EnterCriticalSection();

    /* VSENSE connection to ADC through AMUX are different for Port 0 and Port 1. */
    if (context->port == 0)
    {
        /* Port 0 - VSENSE -> AMUX_NHV[6].0 -> AMUX_NHV[5].1 -> AMUX_NHV[3].1 -> AMUX_B -> ADC. */
        amux_nhv_ctrl_clr = (1u << 6u);
        amux_nhv_ctrl_set = ((1u << 5u) | (1u << 3u));
    }
    else
    {
        /* Port 1 - VSENSE -> AMUX_NHV[5].0 -> AMUX_NHV[4].1 -> AMUX_NHV[3].1 -> AMUX_B -> ADC. */
        amux_nhv_ctrl_clr = (1u << 5u);
        amux_nhv_ctrl_set = ((1u << 4u) | (1u << 3u));
    }
    /* Measure the amplified Vsense. */
    regval = Cy_USBPD_Adc_SampleInput(context, CY_USBPD_ADC_ID_0, CY_USBPD_ADC_INPUT_AMUX_B, \
            amux_nhv_ctrl_clr, amux_nhv_ctrl_set, CY_USBPD_ADC_VREF_PROG);

    /* Check if reference output is selected for measurement, then update the spare_1 register. */
    if (false == (pd->pd_vsense_ctrl_1 & PDSS_PD_VSENSE_CTRL_1_SEL_REF_VSENSE))
    {
        /* Measuring the iLoad, ref is stored in spare_1 register. */
        vsense_ref_out = pd->spare_1;
        /* iLoad(mA) = (6 / AV) * vsense_out(ADC) * 1000 / vsense_ref_out(ADC). */
        /* Make sure ref out is non-zero. */
        if (0 != vsense_ref_out)
        {
            /* with gain of 2, 6 / AV * 1000  is = 3000. */
            regval = regval * 3000;
            regval = regval / vsense_ref_out;
        }
        else
        {
            /* ref out is not yet measured, return 0. */
            regval = 0;
        }
    }
    else
    {
        /* Measuring the ref output. Store the value in the spare_1 register. */
        pd->spare_1 = regval;
    }
    /* Exit critical section as the measurement is complete. */
    Cy_SysLib_ExitCriticalSection(state);
    current = (uint16_t)regval;
#endif /* (defined(CY_DEVICE_CCG6DF_CFP)) */

#if (defined(CY_DEVICE_CCG3PA))
    /* Sample the VBus current using ADC. */
    uint8_t gain;
    cy_en_usbpd_adc_id_t adc;
    PPDSS_REGS_T pd = context->base;
    uint32_t regval;
    uint32_t state;

    state = Cy_SysLib_EnterCriticalSection();

    /* Ensure that LSCSA block is enabled. */
    pd->lscsa_1_ctrl &= ~PDSS_LSCSA_1_CTRL_LSCSA_PD;

    /*
     * ADC_0 does not have path for VOUT through any AMUX.
     * But, ADC_1 is hard wired to ADFT setting of PFC_ON signal.
     */
    adc = CY_USBPD_ADC_ID_1;

    /* Setup the ADFT for measuring the out_pfc_on:
     * 1 = scp, 2 = ocp, 3 = pfc_on, 4 = pfc_off, 5 = sr_on, 6 sr_off, 7 ea
     * Since out_pfc_on is not used for any operation, it is best suited
     * for this.
     */
    CY_USBPD_REG_FIELD_UPDATE(pd->lscsa_1_ctrl, PDSS_LSCSA_1_CTRL_LSCSA_ATSTCFG, ((uint32_t)3u));

    /* By default, use the gain setting of 125. */
    gain = 125u;
    (void)Cy_USBPD_LSCSA_Config(context, CY_USBPD_VBUS_LSCSA_PFC_ON_CONFIG, LSCSA_AV_SEL_125);

    Cy_SysLib_DelayUs(50);

    /* Measure the amplified Vsense. */
    regval = (uint32_t)Cy_USBPD_Adc_Sample(context, adc, CY_USBPD_ADC_INPUT_AMUX_B);
    regval = (uint32_t)Cy_USBPD_Adc_LevelToVolt(context, adc, (uint8_t)regval);

    if (regval > LSCSA_GAIN_MAX_VALUE)
    {
        gain = 35u;
        (void)Cy_USBPD_LSCSA_Config(context, CY_USBPD_VBUS_LSCSA_PFC_ON_CONFIG, LSCSA_AV_SEL_35);

        Cy_SysLib_DelayUs(50);

        regval = (uint32_t)Cy_USBPD_Adc_Sample(context, adc, CY_USBPD_ADC_INPUT_AMUX_B);
        regval = (uint32_t)Cy_USBPD_Adc_LevelToVolt(context, adc, (uint8_t)regval);
    }

    regval = (((regval * 1000u) + (((uint32_t)context->vbusCsaRsense * gain) >> 1)) /
        ((uint32_t)context->vbusCsaRsense * gain));

    /* Revert the ADFT and MUX configurations. */
    CY_USBPD_REG_FIELD_UPDATE(pd->lscsa_1_ctrl, PDSS_LSCSA_1_CTRL_LSCSA_ATSTCFG, 0u);

    Cy_SysLib_DelayUs(10);

    Cy_SysLib_ExitCriticalSection(state);

    current = (uint16_t)regval;

#else
    CY_UNUSED_PARAMETER(context);
#endif /* (CY_DEVICE_CCG3PA) */
    return current;
}

#if defined(PDL_VBUS_SCP_ENABLE)

#define SCP_CUR_TRIP_6A                     (600u)
#define SCP_CUR_TRIP_8A                     (800u)
#define SCP_CUR_TRIP_10A                    (1000u)
#define SCP_CUR_TRIP_12A                    (1200u)
#define SCP_CUR_TRIP_16A                    (1600u)

#if defined(CY_DEVICE_CCG6)
/* CCG6: Location of SCP configuration data. */
#define SFLASH_SCP_TRIM_AV50_6A             (0x0FFFF407u)
#define SFLASH_SCP_TRIM_AV50_10A            (0x0FFFF408u)
#define SFLASH_SCP_TRIM_AV20_6A             (0x0FFFF40Eu)
#define SFLASH_SCP_TRIM_AV20_10A            (0x0FFFF40Fu)
#endif /* defined(CY_DEVICE_CCG6) */

#if defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP)
#define SFLASH_SCP_TRIM_ROOM_FLAG           (0x0FFFF48Au)
#define SFLASH_SCP_TRIM_5V_6A_ROOM          (0x0FFFF462u)
#define SFLASH_SCP_TRIM_5V_6A_HOT           (0x0FFFF436u)
#define SFLASH_SCP_TRIM_5V_6A_COLD          (0x0FFFF44Cu)
#define SFLASH_SCP_TRIM_5V_6A_HOT_OFFSET    (0u)
#define SFLASH_SCP_TRIM_5V_10A_HOT_OFFSET   (1u)
#define SFLASH_SCP_TRIM_5V_6A_COLD_OFFSET   (22u)
#define SFLASH_SCP_TRIM_5V_10A_COLD_OFFSET  (23u)
#endif /* defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP) */

#endif /* (defined(PDL_VBUS_SCP_ENABLE) && defined(CY_DEVICE_CCG6)) */

#if PDL_VBUS_SCP_ENABLE
#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
/* Trims flag */
#define SCP_TRIM_ROOM_FLAG(port) (*(volatile uint8_t *)((0x0ffff45Du) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))

#define SCP_TRIM_6A_ROOM(port) (*(volatile uint8_t *)((0x0ffff45Bu) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))

#define SCP_TRIM_10A_ROOM(port) (*(volatile uint8_t *)((0x0ffff45Cu) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))

#define SCP_TRIM_6A_H(port) (*(volatile uint8_t *)((0x0ffff437u) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))

#define SCP_TRIM_10A_H(port) (*(volatile uint8_t *)((0x0ffff438u) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))

/* SCP Comparator min reference voltage in mV. */
#define SCP_REF_VOLT_MIN                    (130u)

/* SCP Reference voltage step size in mV. */
#define SCP_REF_VOLT_STEP                   (10u)

/* VBUS SCP threshold options in 10mA units */
#define VBUS_SCP_THRESHOLD_6A           (600u)
#define VBUS_SCP_THRESHOLD_10A          (1000u)

/*******************************************************************************
* Function Name: Cy_USBPD_Fault_Vbus_Scp_SystemCalcLimit
****************************************************************************//**
*
* Calculates system limit for Short Circuit Protection (SCP).
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \param cur
* Contract current in mA units.
*
*
* \return
* None
*
*******************************************************************************/

static uint16_t Cy_USBPD_Fault_Vbus_Scp_SystemCalcLimit(cy_stc_usbpd_context_t *context, uint32_t cur)
{
#if VBUS_SCP_THRESHOLD_OVERRIDE
    context->vbusScpLimit = VBUS_SCP_THRESHOLD;
#else /* !VBUS_SCP_THRESHOLD_OVERRIDE */
#if (CCG_LOAD_SHARING_ENABLE || CCG_TEMP_BASED_VOLTAGE_THROTTLING || CCG_VIN_BASED_VOLTAGE_THROTTLING)

#if CY_USE_CONFIG_TABLE
    uint16_t max_current = pd_get_ptr_auto_cfg_tbl(context)->max_current;
#else
    uint16_t max_current = context->usbpdConfig->autoConfig->max_current;
#endif

    if ((max_current >= CY_USBPD_I_0P9A) &&
        (max_current <= CY_USBPD_I_3A))
    {
        /* Set SCP limit to 6A */
        context->vbusScpLimit = VBUS_SCP_THRESHOLD_6A;
    }
    else
    {
        /* Set SCP limit to 6A/10A based on contract current */
        if(cur <= CY_USBPD_I_3A)
        {
            context->vbusScpLimit = VBUS_SCP_THRESHOLD_6A;
        }
        else
        {
            context->vbusScpLimit = VBUS_SCP_THRESHOLD_10A;
        }
    }

#else /* (!CCG_LOAD_SHARING_ENABLE && !CCG_TEMP_BASED_VOLTAGE_THROTTLING && !CCG_VIN_BASED_VOLTAGE_THROTTLING) */
    context->vbusScpLimit = VBUS_SCP_THRESHOLD_6A;
#endif /* (CCG_LOAD_SHARING_ENABLE || CCG_TEMP_BASED_VOLTAGE_THROTTLING || CCG_VIN_BASED_VOLTAGE_THROTTLING) */
#endif /* VBUS_SCP_THRESHOLD_OVERRIDE */

    /* Cap SCP threshold between 6A and 10A */
    context->vbusScpLimit = CY_USBPD_GET_MIN(context->vbusScpLimit, VBUS_SCP_THRESHOLD_10A);
    context->vbusScpLimit = CY_USBPD_GET_MAX(context->vbusScpLimit, VBUS_SCP_THRESHOLD_6A);

    CY_UNUSED_PARAMETER(cur);
    return(context->vbusScpLimit);
}
#endif /* (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) */
#endif /* PDL_VBUS_SCP_ENABLE */

/*******************************************************************************
* Function Name: Cy_USBPD_Fault_Vbus_ScpEnable
****************************************************************************//**
*
* Enable Short Circuit Protection (SCP).
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \param current
* Contract current in mA units.
*
* \param cb
* Callback function to be called on fault detection.
*
* \return
* None
*
*******************************************************************************/
void Cy_USBPD_Fault_Vbus_ScpEnable(cy_stc_usbpd_context_t *context, uint32_t current, cy_cb_vbus_fault_t cb)
{
#if (PDL_VBUS_SCP_ENABLE && (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP) || defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)))
    PPDSS_REGS_T pd = context->base;
    uint32_t regval = 0U;
    uint32_t vsense = 0U;
#if (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
    uint8_t debounce = 0U;
#endif /* defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_CCG3PA) */
    uint32_t state = 0U;
#if (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3))
    const uint8_t *sflash_scp_trim;
#endif /* defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3) */
#if defined(CY_DEVICE_PMG1S3)
    const uint8_t *sflash_scp_trim_room_flag;
    PPDSS_TRIMS_REGS_T trimRegs = NULL;
#endif /* defined CY_DEVICE_PMG1S3 */

    /* Register SCP Callback. */
    context->vbusScpCbk = cb;

#if defined(CY_DEVICE_CCG6)
    debounce = GET_VBUS_SCP_TABLE(context)->debounce;
    /* Divide debounce time in us by 5 to get glitch filter setting. */
    debounce /= 5U;
    if (debounce > 7U)
    {
        debounce = 7U;
    }

    if (GET_VBUS_SCP_TABLE(context)->senseRes == 10U)
    {
        /* The SCP limit can be set to 6A/10A. The setting is chosen at the application level. */
        if (current <= SCP_CUR_TRIP_6A)
        {
            sflash_scp_trim = (const uint8_t *)(SFLASH_SCP_TRIM_AV20_6A);
        }
        else
        {
            sflash_scp_trim = (const uint8_t *)(SFLASH_SCP_TRIM_AV20_10A);
        }
    }
    else
    {
        if(current <= SCP_CUR_TRIP_6A)
        {
            sflash_scp_trim = (const uint8_t *)(SFLASH_SCP_TRIM_AV50_6A);
        }
        else
        {
            sflash_scp_trim = (const uint8_t *)(SFLASH_SCP_TRIM_AV50_10A);
        }
    }

    vsense = *sflash_scp_trim;

    state = Cy_SysLib_EnterCriticalSection ();

    Cy_USBPD_Fault_FetAutoModeDisable (context, true, CY_USBPD_VBUS_FILTER_ID_HSCSA_SCP);

    /* Configure Reference for comparator. */
    Cy_USBPD_SetRefgenVoltage (context, (uint8_t)vsense, (uint8_t)CY_USBPD_VREF_CSA_SCP);

    /* Make sure the CSA block is enabled. */
    pd->csa_scp_0_ctrl &= ~(PDSS_CSA_SCP_0_CTRL_PD_CSA | PDSS_CSA_SCP_0_CTRL_BW_MASK);
    pd->csa_scp_0_ctrl |= (PDSS_CSA_SCP_0_CTRL_SEL_OUT_D | PDSS_CSA_SCP_0_CTRL_CSA_ISO_N |
            (3UL << PDSS_CSA_SCP_0_CTRL_BW_POS));

    /* Enable pull-up of P_CTRL on V_IN side when SCP detected. */
    pd->pgdo_pu_3_cfg |= PDSS_PGDO_PU_3_CFG_PGDO_EN_SCP_LV;

    /*
     * Sets the same gain of 15 for SCP, removes latch from reset and sets glitch filter duration.
     * Reset the latch and then enable it in sample mode.
     */
    pd->csa_scp_1_ctrl = 0x00U;
    Cy_SysLib_DelayUs (10U);
    pd->csa_scp_1_ctrl = (0x04UL | ((uint32_t)debounce << 3));
#endif /* CY_DEVICE_CCG6 */

#if defined(CY_DEVICE_PMG1S3)
    sflash_scp_trim_room_flag = (const uint8_t *)(SFLASH_SCP_TRIM_ROOM_FLAG + (uint16_t)(context->port * 0x100u));
    trimRegs = context->trimsBase;

    state = Cy_SysLib_EnterCriticalSection ();
    /* Select the SCP trip point to 6A or 10A */
    if(current >= SCP_CUR_TRIP_10A)
    {

#if defined(USE_SCP_ROOM_TRIMS)
        /* Check if room trims are available */
        if(*sflash_scp_trim_room_flag == (uint8_t)1U)
        {
            sflash_scp_trim = (const uint8_t *)(SFLASH_SCP_TRIM_5V_6A_ROOM + 1u + (uint16_t)(context->port * 0x100u));
            vsense = *sflash_scp_trim;
        }
        else
#else
    (void)sflash_scp_trim_room_flag; 
#endif /* USE_SCP_ROOM_TRIMS */
        {
            sflash_scp_trim = (const uint8_t *)(SFLASH_SCP_TRIM_5V_6A_HOT);
            /* Take the average of the hot and the cold trims */
            vsense = (uint8_t)((sflash_scp_trim[SFLASH_SCP_TRIM_5V_10A_HOT_OFFSET] + sflash_scp_trim[SFLASH_SCP_TRIM_5V_10A_COLD_OFFSET]) / 2U);
        }
        pd->scp_rcp_0_ctrl |= PDSS_SCP_RCP_0_CTRL_SCP_RCP_T_SEL_SCP_10A;
    }
    else
    {
 #if defined(USE_SCP_ROOM_TRIMS)         
        if(*sflash_scp_trim_room_flag == (uint8_t)1U)
        {
            sflash_scp_trim = (const uint8_t *)(SFLASH_SCP_TRIM_5V_6A_ROOM + (uint16_t)(context->port * 0x100u));
            vsense = *sflash_scp_trim;
        }
        else
#else
    (void)sflash_scp_trim_room_flag; 
#endif /* USE_SCP_ROOM_TRIMS) */ 
        {
            sflash_scp_trim = (const uint8_t *)(SFLASH_SCP_TRIM_5V_6A_HOT);
            /* Take the average of the hot and the cold trims */
            vsense = (uint8_t)((sflash_scp_trim[SFLASH_SCP_TRIM_5V_6A_HOT_OFFSET] + sflash_scp_trim[SFLASH_SCP_TRIM_5V_6A_COLD_OFFSET]) / 2U);
        }
        pd->scp_rcp_0_ctrl &= ~PDSS_SCP_RCP_0_CTRL_SCP_RCP_T_SEL_SCP_10A;
    }
    
    /* Copy the trim value from SFLASH into the SCP Trims Register */
    trimRegs->trim_scp_rcp_0 = (uint32_t)vsense;

    /* Power-Up the SCP-RCP hard-IP */
    pd->scp_rcp_0_ctrl &= ~PDSS_SCP_RCP_0_CTRL_SCP_RCP_PD;
    Cy_SysLib_DelayUs(10);
    /* Power-Up the SCP block */
    pd->scp_rcp_0_ctrl &= ~PDSS_SCP_RCP_0_CTRL_SCP_RCP_PD_SCP; 
    Cy_SysLib_DelayUs(10);
    pd->scp_rcp_0_ctrl |= PDSS_SCP_RCP_0_CTRL_SCP_RCP_ISO_N;
  
    /* Remove the SCP latch from Reset mode and put it in sample mode*/
    pd->scp_rcp_0_ctrl &= ~PDSS_SCP_RCP_0_CTRL_SCP_RCP_T_SCP_RST_LATCH_N;
    Cy_SysLib_DelayUs(10);
    pd->scp_rcp_0_ctrl |= PDSS_SCP_RCP_0_CTRL_SCP_RCP_T_SCP_RST_LATCH_N;
#endif /* (CY_DEVICE_PMG1S3) */

#if defined(CY_DEVICE_CCG6DF_CFP)
    /* Enter critical section. */
    state = Cy_SysLib_EnterCriticalSection ();

    /* if the current is < 12A, then use 8A SCP. */
    if (current < SCP_CUR_TRIP_12A)
    {
        vsense = 0x02u;
    }
    /* if the current is >= 12A and < 16A, then use 12A SCP. */
    else if (current <= SCP_CUR_TRIP_16A)
    {
        vsense = 0x03u;
    }
    /* if the current is >= 16A, then use 16A SCP. */
    else
    {
        vsense = 0x04u;
    }
    /* Do not enable SCP if it is already enabled. */
    if (false == (pd->pd_40scp_ctrl & PDSS_PD_40SCP_CTRL_SCP_COMP_OUT_EN))
    {
        regval = pd->pd_40scp_ctrl;
        regval |= PDSS_PD_40SCP_CTRL_ISO_N;
        regval &= ~PDSS_PD_40SCP_CTRL_CONFIG_SCP_VTRIP_MASK;
        regval |= (vsense << PDSS_PD_40SCP_CTRL_CONFIG_SCP_VTRIP_POS);
        pd->pd_40scp_ctrl = regval;
        Cy_SysLib_DelayUs(1);
        /* Power-Up the SCP block */
        pd->pd_40scp_ctrl &= ~PDSS_PD_40SCP_CTRL_SCP_PD;
        Cy_SysLib_DelayUs(100);

        /* Keep the SCP latch from Reset mode and enable once the G2 is made high.*/
        pd->pd_40scp_ctrl &= ~PDSS_PD_40SCP_CTRL_SCP_COMP_OUT_EN;
    }
#endif /* (CY_DEVICE_CCG6DF_CFP) */

#if (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP))
    /* Bypass the filter to speed up interrupt trigger. */
    regval = pd->intr13_cfg_csa_scp_hs;
    regval &= ~(PDSS_INTR13_CFG_CSA_SCP_HS_CSA_SCP_FILT_EN | PDSS_INTR13_CFG_CSA_SCP_HS_CSA_SCP_FILT_CFG_MASK |
            PDSS_INTR13_CFG_CSA_SCP_HS_CSA_SCP_FILT_SEL_MASK | PDSS_INTR13_CFG_CSA_SCP_HS_CSA_SCP_FILT_RESET |
            PDSS_INTR13_CFG_CSA_SCP_HS_CSA_SCP_FILT_BYPASS);

    /* Set edge detection. */
    regval |= ((uint32_t)CY_USBPD_VBUS_FILTER_CFG_POS_EN_NEG_DIS << PDSS_INTR13_CFG_CSA_SCP_HS_CSA_SCP_FILT_CFG_POS);
    regval |= PDSS_INTR13_CFG_CSA_SCP_HS_CSA_SCP_FILT_BYPASS;

    pd->intr13_cfg_csa_scp_hs = regval;

    /* Clear and enable the SC Detect interrupt. */
    pd->intr13 = PDSS_INTR13_CSA_SCP_CHANGED;
    pd->intr13_mask |= PDSS_INTR13_MASK_CSA_SCP_CHANGED_MASK;

    /* Auto FET turn off mode. */
    Cy_USBPD_Fault_FetAutoModeEnable (context, true, CY_USBPD_VBUS_FILTER_ID_HSCSA_SCP);

    Cy_SysLib_ExitCriticalSection (state);
#endif /* defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP) */

#if defined(CY_DEVICE_CCG3PA)
    debounce = GET_VBUS_SCP_TABLE(context)->debounce;

    /* Assuming use of 500KHz clock for debounce. */
    debounce = (debounce > 0x40u) ? 0x20u : ((debounce+1u) >> 1);

    current = 1000u; /* 150% of 10A is 15A */
    vsense = current + ((current * GET_VBUS_SCP_TABLE(context)->threshold) / 100u);
    /* Convert into mV. */
    vsense = (vsense * context->vbusCsaRsense) / 1000u;

    state = Cy_SysLib_EnterCriticalSection ();

    if(context->usbpdConfig->vbusScpConfig->mode == VBUS_OCP_MODE_INT_AUTOCTRL)
    {
            Cy_USBPD_Fault_FetAutoModeDisable(context,CCG_SRC_FET, CY_USBPD_VBUS_FILTER_ID_LSCSA_SCP);
    }
    /* Just power up LSCSA block. */
    pd->lscsa_1_ctrl &= ~PDSS_LSCSA_1_CTRL_LSCSA_PD;
    /* Gain for SCP is fixed to 10. So LSCSA programming is not required. */

    /*
    * We have vsense and gain = 10. So calculate vref based on that.
    * Min VREF is 130mV and each step is 10mv.
    */

    uint32_t vref = vsense * SCP_GAIN_VALUE;
    if (vref < SCP_REF_VOLT_MIN)
    {
        vref = SCP_REF_VOLT_MIN;
    }
    vref = (vref - SCP_REF_VOLT_MIN)/SCP_REF_VOLT_STEP;

    /* Configure Reference for comparator. */
    regval = pd->refgen_2_ctrl;
    regval &= ~(PDSS_REFGEN_2_CTRL_SEL4_MASK);
    regval |= (vref << PDSS_REFGEN_2_CTRL_SEL4_POS);
    pd->refgen_2_ctrl = regval;

    /* Use Vref SEL 4 for SCP comparator. */
    pd->amux_ctrl |= (1u << VBUS_SCP_AMUX_CTRL_REF_SEL_BIT_POS);

    /* Enable Comparator. */
    pd->comp_ctrl[CY_USBPD_VBUS_COMP_ID_LSCSA_SCP] |= PDSS_COMP_CTRL_COMP_ISO_N;
    pd->comp_ctrl[CY_USBPD_VBUS_COMP_ID_LSCSA_SCP] &= ~PDSS_COMP_CTRL_COMP_PD;

    pd->intr5_filter_cfg[CY_USBPD_VBUS_FILTER_ID_LSCSA_SCP] &= ~(PDSS_INTR5_FILTER_CFG_FILT_EN |
    PDSS_INTR5_FILTER_CFG_FILT_CFG_MASK | PDSS_INTR5_FILTER_CFG_FILT_SEL_MASK |
    PDSS_INTR5_FILTER_CFG_FILT_RESET | PDSS_INTR5_FILTER_CFG_FILT_BYPASS);
    /* Set edge detection. */
    regval = pd->intr5_filter_cfg[CY_USBPD_VBUS_FILTER_ID_LSCSA_SCP];
    regval |= ((uint8_t)CY_USBPD_VBUS_FILTER_CFG_POS_EN_NEG_DIS << PDSS_INTR5_FILTER_CFG_FILT_CFG_POS);

    if (debounce != 0u)
    {
        /* Subtracting 1 from filter clock cycle value as 0 translates to 1-2 clock cycles delay. */
        regval |= (((((debounce - 1u) != 0u) ? ((uint32_t)debounce - 1u) : (uint32_t)1u) & (uint32_t)0x1Fu) << PDSS_INTR5_FILTER_CFG_FILT_SEL_POS);
        regval |= (PDSS_INTR5_FILTER_CFG_FILT_EN | PDSS_INTR5_FILTER_CFG_DPSLP_MODE);
    }
    else
    {
        regval |= PDSS_INTR5_FILTER_CFG_FILT_BYPASS;
    }

    pd->intr5_filter_cfg[CY_USBPD_VBUS_FILTER_ID_LSCSA_SCP] = regval;

    /* Clear interrupt. */
    pd->intr5 = ((uint32_t)1u << (uint8_t)CY_USBPD_VBUS_FILTER_ID_LSCSA_SCP);

    /* Enable Interrupt. */
    pd->intr5_mask |= (1u << (uint8_t)CY_USBPD_VBUS_FILTER_ID_LSCSA_SCP);

    /* Auto FET turn off mode. */
    if (context->usbpdConfig->vbusScpConfig->mode == VBUS_OCP_MODE_INT_AUTOCTRL)
    {
        Cy_USBPD_Fault_FetAutoModeEnable(context,CCG_SRC_FET, CY_USBPD_VBUS_FILTER_ID_LSCSA_SCP);
    }

    Cy_SysLib_ExitCriticalSection(state);
#endif /* defined(CY_DEVICE_CCG3PA) */

#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))


    uint32_t vref;
    uint8_t scp_trim_6A;
    uint8_t scp_trim_10A;

    debounce = GET_VBUS_SCP_TABLE(context)->debounce;
    debounce = (uint8_t)system_get_clk_filt_sel(context->port, (((uint16_t)debounce) * 10u));

    vsense = Cy_USBPD_Fault_Vbus_Scp_SystemCalcLimit(context, current);
    /* Convert into mV. */
    vsense = (vsense * context->vbusCsaRsense) / 1000u;

    state = Cy_SysLib_EnterCriticalSection ();

    if(context->usbpdConfig->vbusScpConfig->mode == VBUS_OCP_MODE_INT_AUTOCTRL)
    {
        Cy_USBPD_Fault_FetAutoModeDisable(context,CCG_SRC_FET, CY_USBPD_VBUS_FILTER_ID_CSA_SCP);
    }

    /* Gain for SCP is fixed. So CSA programming is not required. */
    /* Power up CSA block and enable output. */
    regval = pd->csa_scp_0_ctrl;
    regval &= ~PDSS_CSA_SCP_0_CTRL_PD_CSA;
    regval |= PDSS_CSA_SCP_0_CTRL_SEL_OUT_D | PDSS_CSA_SCP_0_CTRL_CSA_ISO_N;
    pd->csa_scp_0_ctrl = regval;

    /*
     * ** Silicon has room temperature trims.
     * Whereas,
     * *A silicon does not have room temperature trims.
     */
    if (SCP_TRIM_ROOM_FLAG(context->port) == 0u)
    {
        scp_trim_6A = SCP_TRIM_6A_H(context->port);
        scp_trim_10A = SCP_TRIM_10A_H(context->port);
    }
    else
    {
        scp_trim_6A = SCP_TRIM_6A_ROOM(context->port);
        scp_trim_10A = SCP_TRIM_10A_ROOM(context->port);
    }

    /* We have vsense and fixed gain. So calculate vref based on that. */
    if (context->vbusScpLimit == VBUS_SCP_THRESHOLD_6A)
    {
        if (scp_trim_6A == 0u)
        {
            vref = vsense * SCP_GAIN_VALUE;
            if (vref < SCP_REF_VOLT_MIN)
            {
                vref = SCP_REF_VOLT_MIN;
            }
            vref = (vref - SCP_REF_VOLT_MIN)/SCP_REF_VOLT_STEP;
        }
        else
        {
            vref = (((((uint32_t)scp_trim_6A + 13u) * context->vbusCsaRsense) / 50u) - 13u);
        }
    }
    else
    {
        if (scp_trim_10A == 0u)
        {
            vref = vsense * SCP_GAIN_VALUE;
            if (vref < SCP_REF_VOLT_MIN)
            {
                vref = SCP_REF_VOLT_MIN;
            }
            vref = (vref - SCP_REF_VOLT_MIN)/SCP_REF_VOLT_STEP;
        }
        else
        {
            vref = (((((uint32_t)scp_trim_10A + 13u) * context->vbusCsaRsense) / 50u) - 13u);
        }
    }

    /* Configure Reference. */
#if FG_PART
    vref -= (((CC_GAIN60_GM0P6_TRIM_2A_ROOM(port) - 46) * 46) / 600);
#endif /* FG_PART */

    /* QAC suppression 2985: REG_FEILD_UPDATE is a common functional macro that is used to
     * modify a register field without affecting any other bits of the register. When the field
     * starts from bit position 0, the left shift operation is redundant. Yet this operation is
     * retained to keep it generic and compatible for bitfields starting from other bit positions. */
    CY_USBPD_REG_FIELD_UPDATE(pd->refgen_2_ctrl, PDSS_REFGEN_2_CTRL_SEL4, (uint32_t)vref); /* PRQA S 2985 */

    /* Configuring the CSA output filter. */
    regval = pd->intr13_cfg_csa_scp_hs;
    regval &= ~(PDSS_INTR13_CFG_CSA_SCP_HS_CSA_SCP_FILT_EN |
            PDSS_INTR13_CFG_CSA_SCP_HS_CSA_SCP_FILT_CFG_MASK |
            PDSS_INTR13_CFG_CSA_SCP_HS_CSA_SCP_FILT_SEL_MASK |
            PDSS_INTR13_CFG_CSA_SCP_HS_CSA_SCP_FILT_RESET |
            PDSS_INTR13_CFG_CSA_SCP_HS_CSA_SCP_FILT_BYPASS);
    
    /* Load the SCP interrupt register with filter disable configuration before enabling it. */
    pd->intr13_cfg_csa_scp_hs = regval;
    
    /* Configure the filter based on debounce parameter from config table. */
    regval |= ((uint32_t)CY_USBPD_VBUS_FILTER_CFG_POS_EN_NEG_DIS << PDSS_INTR13_CFG_CSA_SCP_HS_CSA_SCP_FILT_CFG_POS);

    if ((bool)(debounce))
    {
        /* Subtracting 1 from filter clock cycle value as 0 translates to 1-2 clock cycles delay. */
        regval |= ((((((uint32_t)debounce - 1u) != 0u) ? ((uint32_t)debounce - 1u) : (uint32_t)1u) & 0x1Fu) << PDSS_INTR13_CFG_CSA_SCP_HS_CSA_SCP_FILT_SEL_POS);
        regval |= (PDSS_INTR13_CFG_CSA_SCP_HS_CSA_SCP_FILT_EN |
            PDSS_INTR13_CFG_CSA_SCP_HS_CSA_SCP_DPSLP_MODE);
    }
    else
    {
        regval |= PDSS_INTR13_CFG_CSA_SCP_HS_CSA_SCP_FILT_BYPASS;
    }

    pd->intr13_cfg_csa_scp_hs = regval;

    /* Clear and enable the OC detect interrupt. */
    pd->intr13 = PDSS_INTR13_CSA_SCP_CHANGED;
    pd->intr13_mask |= PDSS_INTR13_MASK_CSA_SCP_CHANGED_MASK;

    /* Auto FET turn off mode. */
    if (context->usbpdConfig->vbusScpConfig->mode == VBUS_OCP_MODE_INT_AUTOCTRL)
        {
            Cy_USBPD_Fault_FetAutoModeEnable(context,CCG_SRC_FET, CY_USBPD_VBUS_FILTER_ID_CSA_SCP);
        }

    Cy_SysLib_ExitCriticalSection(state);
#endif /* (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) */
#else
    CY_UNUSED_PARAMETER(context);
    CY_UNUSED_PARAMETER(current);
    (void)(cy_cb_vbus_fault_t)cb;
#endif /* (defined(PDL_VBUS_SCP_ENABLE) && (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP) || defined(CY_DEVICE_CCG3PA))) */
}
/*******************************************************************************
* Function Name: Cy_USBPD_Vbus_HalCleanup
****************************************************************************//**
*
* This function cleans up the PD block after a disconnect.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \return
* None
*
*******************************************************************************/
void Cy_USBPD_Vbus_HalCleanup(cy_stc_usbpd_context_t *context)
{
#if (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2) || defined(CY_DEVICE_PAG1S) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
    PPDSS_REGS_T pd = context->base;
#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
    pd->csa_scp_0_ctrl |= PDSS_CSA_SCP_0_CTRL_PD_CSA;
#else
    pd->lscsa_1_ctrl |= PDSS_LSCSA_1_CTRL_LSCSA_PD;
#endif /* (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))  */
#else
    CY_UNUSED_PARAMETER(context);
#endif /* (defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2) || defined(CY_DEVICE_PAG1S) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) */
}

/*******************************************************************************
* Function Name: Cy_USBPD_Fault_Vbus_ScpDisable
****************************************************************************//**
*
* Disable Short Circuit Protection (SCP) control.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \return
* None
*
*******************************************************************************/
void Cy_USBPD_Fault_Vbus_ScpDisable(cy_stc_usbpd_context_t *context)
{
#if (defined(PDL_VBUS_SCP_ENABLE) && (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP) || defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)))
    PPDSS_REGS_T pd = context->base;
    uint32_t state;

    state = Cy_SysLib_EnterCriticalSection ();

    /* Deregister the callback. */
    context->vbusScpCbk = NULL;
#if defined(CY_DEVICE_CCG6)
    /* Power down the CSA SCP block */
    pd->csa_scp_0_ctrl |= PDSS_CSA_SCP_0_CTRL_PD_CSA;
    pd->csa_scp_0_ctrl &= ~(PDSS_CSA_SCP_0_CTRL_SEL_OUT_D | PDSS_CSA_SCP_0_CTRL_CSA_ISO_N);
#endif /* defined(CY_DEVICE_CCG6) */

#if defined(CY_DEVICE_PMG1S3)
    /* Power down the SCP block */
    pd->scp_rcp_0_ctrl |= PDSS_SCP_RCP_0_CTRL_SCP_RCP_PD_SCP; 
    /* Put the latch in Reset mode */
    pd->scp_rcp_0_ctrl &= ~(PDSS_SCP_RCP_0_CTRL_SCP_RCP_ISO_N | PDSS_SCP_RCP_0_CTRL_SCP_RCP_T_SCP_RST_LATCH_N);
#endif /* defined(CY_DEVICE_PMG1S3) */

#if defined(CY_DEVICE_CCG6DF_CFP)
    /* Power down the SCP block */
    pd->pd_40scp_ctrl |= PDSS_PD_40SCP_CTRL_SCP_PD; 
    /* Put the latch in Reset mode */
    pd->pd_40scp_ctrl &= ~(PDSS_PD_40SCP_CTRL_ISO_N | PDSS_PD_40SCP_CTRL_SCP_COMP_OUT_EN);
#endif /* defined(CY_DEVICE_CCG6DF_CFP) */

#if (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP))
    /* Disable and clear interrupt. */
    pd->intr13 = PDSS_INTR13_CSA_SCP_CHANGED;
    pd->intr13_mask &= ~PDSS_INTR13_MASK_CSA_SCP_CHANGED_MASK;

    /* Disable FET turn off on SCP fault. */
    Cy_USBPD_Fault_FetAutoModeDisable (context, true, CY_USBPD_VBUS_FILTER_ID_HSCSA_SCP);
    Cy_SysLib_ExitCriticalSection (state);
#endif /* (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP) */

#if defined(CY_DEVICE_CCG3PA)
    /* Disable and clear interrupt. */
    pd->intr5_mask &= ~(1u << (uint8_t)CY_USBPD_VBUS_FILTER_ID_LSCSA_SCP);
    pd->intr5 = ((uint32_t)1u << (uint8_t)CY_USBPD_VBUS_FILTER_ID_LSCSA_SCP);

    /* Disable comparator. */
    pd->comp_ctrl[CY_USBPD_VBUS_COMP_ID_LSCSA_SCP] &= ~PDSS_COMP_CTRL_COMP_ISO_N;
    pd->comp_ctrl[CY_USBPD_VBUS_COMP_ID_LSCSA_SCP] |= PDSS_COMP_CTRL_COMP_PD;

    /* Clear reference. */
    pd->refgen_2_ctrl &= ~(PDSS_REFGEN_2_CTRL_SEL4_MASK);

    /* Disable filter. */
    pd->intr5_filter_cfg[CY_USBPD_VBUS_FILTER_ID_LSCSA_SCP] &= ~(PDSS_INTR5_FILTER_CFG_FILT_EN |
    PDSS_INTR5_FILTER_CFG_FILT_CFG_MASK | PDSS_INTR5_FILTER_CFG_FILT_SEL_MASK |
    PDSS_INTR5_FILTER_CFG_FILT_BYPASS);

    if (context->usbpdConfig->vbusScpConfig->mode == VBUS_OCP_MODE_INT_AUTOCTRL)
    {
        Cy_USBPD_Fault_FetAutoModeDisable(context, CCG_SRC_FET, CY_USBPD_VBUS_FILTER_ID_LSCSA_SCP);
    }
    Cy_SysLib_ExitCriticalSection(state);
#endif /*CY_DEVICE_CCG3PA*/

#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
    uint32_t regval;
    /* Clear reference. */
    pd->refgen_2_ctrl &= ~(PDSS_REFGEN_2_CTRL_SEL4_MASK);

    /* Disable and clear interrupts. */
    pd->intr13_mask &= ~(PDSS_INTR13_CSA_SCP_CHANGED);
    pd->intr13 = PDSS_INTR13_CSA_SCP_CHANGED;

    /* Disable the filter. */
    regval = pd->intr13_cfg_csa_scp_hs;
    regval &= ~(PDSS_INTR13_CFG_CSA_SCP_HS_CSA_SCP_FILT_EN |
            PDSS_INTR13_CFG_CSA_SCP_HS_CSA_SCP_FILT_CFG_MASK |
            PDSS_INTR13_CFG_CSA_SCP_HS_CSA_SCP_FILT_SEL_MASK |
            PDSS_INTR13_CFG_CSA_SCP_HS_CSA_SCP_FILT_RESET |
            PDSS_INTR13_CFG_CSA_SCP_HS_CSA_SCP_FILT_BYPASS);
    pd->intr13_cfg_csa_scp_hs = regval;

    /* Remove SCP as source. */
    if (context->usbpdConfig->vbusScpConfig->mode == VBUS_OCP_MODE_INT_AUTOCTRL)
     {
        Cy_USBPD_Fault_FetAutoModeDisable(context, CCG_SRC_FET, CY_USBPD_VBUS_FILTER_ID_CSA_SCP);
     }

    Cy_SysLib_ExitCriticalSection(state);
#endif /* (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) */
#else
    CY_UNUSED_PARAMETER(context);
#endif /* (defined(PDL_VBUS_SCP_ENABLE) && (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP))) */
}

/*******************************************************************************
* Function Name: Cy_USBPD_Fault_Vbus_ScpIntrHandler
****************************************************************************//**
*
* VBUS SCP fault interrupt handler function.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \return
* None
*
*******************************************************************************/
void Cy_USBPD_Fault_Vbus_ScpIntrHandler(cy_stc_usbpd_context_t *context)
{
#if (defined(PDL_VBUS_SCP_ENABLE) && (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP) || defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)))
    PPDSS_REGS_T pd = context->base;
#if defined(CY_DEVICE_CCG6)
    /*
     * SCP interrupt handling for CCG6.
     * Provider FET would have been turned off. We only need to clear the interrupt and start recovery.
     */
    /* Make sure P_CTRL does not get pulled up on VBus side. */
    pd->pgdo_pu_3_cfg = PDSS_PGDO_PU_3_CFG_PGDO_EN_SCP_LV;

    /* Clear and disable interrupt. */
    pd->intr13_mask &= ~(PDSS_INTR13_MASKED_CSA_SCP_CHANGED_MASKED);
    pd->intr13 = PDSS_INTR13_MASKED_CSA_SCP_CHANGED_MASKED;

    /* Reset PGDO edge detector logic. */
    Cy_USBPD_Vbus_GdrvRstEdgeDet(context, true);
#endif /* defined(CY_DEVICE_CCG6) */

#if defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP)
    /* Clear and disable interrupt. */
    pd->intr13_mask &= ~(PDSS_INTR13_MASKED_CSA_SCP_CHANGED_MASKED);
    pd->intr13 = PDSS_INTR13_MASKED_CSA_SCP_CHANGED_MASKED;
#endif /* defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP) */

#if defined(CY_DEVICE_CCG3PA)
    /* SCP interrupt handling. */
     /* Clear and disable interrupt. */
     pd->intr5_mask &= ~(1u << (uint8_t)CY_USBPD_VBUS_FILTER_ID_LSCSA_SCP);
     pd->intr5 = (uint32_t)1u << (uint8_t)CY_USBPD_VBUS_FILTER_ID_LSCSA_SCP;
#endif /* CY_DEVICE_CCG3PA */

#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
     /* SCP interrupt handling. */
     /* Clear and disable interrupt. */
     pd->intr13_mask &= ~PDSS_INTR13_MASKED_CSA_SCP_CHANGED_MASKED;
     pd->intr13 = PDSS_INTR13_MASKED_CSA_SCP_CHANGED_MASKED;
#endif /* (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) */

    /* Invoke SCP callback. */
    if (context->vbusScpCbk != NULL)
    {
        (void)context->vbusScpCbk(context, true);
    }
#else
    CY_UNUSED_PARAMETER(context);
#endif /* defined(PDL_VBUS_SCP_ENABLE) && (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP) || defined(CY_DEVICE_CCG3PA)) */
}

/*******************************************************************************
* Function Name: Cy_USBPD_Fault_CcSbuSetCB
****************************************************************************//**
*
* Register a callback function for CC/SBU OVP faults.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \param cb
* Callback function to be called on fault detection.
*
* \return
* None
*
*******************************************************************************/
void Cy_USBPD_Fault_CcSbuSetCB(cy_stc_usbpd_context_t *context, cy_cb_vbus_fault_t cb)
{
    context->ccSbuOvpCbk = cb;
}
/*******************************************************************************
* Function Name: Cy_USBPD_Fault_VbatGndScpLevelSet
****************************************************************************//**
*
* Sets threshold for VBAT-GND SCP.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \param cur_level
* Current level
*
* \return
* None
*
*******************************************************************************/
void Cy_USBPD_Fault_VbatGndScpLevelSet(cy_stc_usbpd_context_t *context, cy_en_usbpd_vbat_gnd_scp_level_t cur_level)
{
#if PDL_VBAT_GND_SCP_ENABLE
    PPDSS_REGS_T pd = context->base;
    PPDSS_TRIMS_REGS_T pdtrims = (PPDSS_TRIMS_REGS_T)(context->trimsBase);

    if (cur_level == PD_VBAT_GND_SCP_10A)
    {
        /* Configure VBAT-GND SCP threshold and trim for 10A */
        CY_USBPD_REG_FIELD_UPDATE(pd->pds_scp_ctrl,
            PDSS_PDS_SCP_CTRL_SCP_TESTMODE, 0x1Cu);

        CY_USBPD_REG_FIELD_UPDATE(pdtrims->trim_scp,
            PDSS_TRIM_SCP_SCP_TRIM, VBAT_GND_SCP_TRIM_10A_ROOM(context->port));
    }
    else if (cur_level == PD_VBAT_GND_SCP_6A)
    {
        /* Configure VBAT-GND SCP threshold and trim for 6A */
        CY_USBPD_REG_FIELD_UPDATE(pd->pds_scp_ctrl,
            PDSS_PDS_SCP_CTRL_SCP_TESTMODE, 0x14u);

        CY_USBPD_REG_FIELD_UPDATE(pdtrims->trim_scp,
            PDSS_TRIM_SCP_SCP_TRIM, VBAT_GND_SCP_TRIM_6A_ROOM(context->port));
    }
    else
    {
        /* No statement */
    }
#else /* !PDL_VBAT_GND_SCP_ENABLE */
    CY_UNUSED_PARAMETER(context);
    CY_UNUSED_PARAMETER(cur_level);
#endif /* !PDL_VBAT_GND_SCP_ENABLE */
}
/*******************************************************************************
* Function Name: Cy_USBPD_Fault_VbatGndScpEn
****************************************************************************//**
*
* Enables VBAT-GND SCP Fault.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \param pctrl
* Flag indicating the type of gate driver to be controlled, true for
* P_CTRL and false for C_CTRL.
*
* \param mode
* VBAT-GND SCP Fault Mode.
*
* \return
* None
*
*******************************************************************************/
void Cy_USBPD_Fault_VbatGndScpEn(cy_stc_usbpd_context_t *context, bool pctrl, uint8_t mode)
{
#if PDL_VBAT_GND_SCP_ENABLE
    PPDSS_REGS_T pd = context->base;
    uint32_t regval;
    uint8_t debounce;
    uint32_t state;

    if (context->vbatGndScpEnStatus == false)
    {
        state = Cy_SysLib_EnterCriticalSection();

        context->vbatGndScpMode = mode;
        context->vbatGndScpPgdoType = pctrl;

        if (mode == VBAT_GND_SCP_MODE_INT_AUTOCTRL)
        {
            Cy_USBPD_Fault_FetAutoModeDisable(context, pctrl, CY_USBPD_VBUS_FILTER_ID_PDS_SCP);
        }

        /* Power up CSA block. */
        pd->csa_scp_0_ctrl &= ~PDSS_CSA_SCP_0_CTRL_PD_CSA;

        /* Enable SCP */
        pd->pds_scp_ctrl |= (PDSS_PDS_SCP_CTRL_SCP_EN | PDSS_PDS_SCP_CTRL_SCP_ISO_N);

        /*
         * VBAT-GND SCP level is set to 6A by default.
         * During active attach, it shall be set to 10A to not conflict with
         * VBUS SCP. And then reset to 6A once detach is detected.
         */
        Cy_USBPD_Fault_VbatGndScpLevelSet(context, PD_VBAT_GND_SCP_6A);

        /* Enable CSPIN to internal CSP and disable weak pull down on FET drive GPIO. */
        CY_USBPD_REG_FIELD_UPDATE(pd->bb_bat2gnd_prot_cnfg, PDSS_BB_BAT2GND_PROT_CNFG_BAT2GND_PROT_SEL, 5u);

        /* Configure filter */

        /* Convert debounce delay in us to filter clock cycles. */
        debounce = (uint8_t)system_get_clk_filt_sel(context->port, ((uint8_t)VBAT_GND_SCP_DEBOUNCE * 10u));

        /* Reset filter. */
        pd->intr15_cfg_pds_scp &= ~(PDSS_INTR15_CFG_PDS_SCP_SCP_OUT_FILT_EN |
                PDSS_INTR15_CFG_PDS_SCP_SCP_OUT_FILT_CFG_MASK |
                PDSS_INTR15_CFG_PDS_SCP_SCP_OUT_FILT_SEL_MASK |
                PDSS_INTR15_CFG_PDS_SCP_SCP_OUT_FILT_RESET |
                PDSS_INTR15_CFG_PDS_SCP_SCP_OUT_FILT_BYPASS |
                PDSS_INTR15_CFG_PDS_SCP_SCP_OUT_DPSLP_MODE);
        regval = pd->intr15_cfg_pds_scp;

        /* Set edge detection. */
        regval |= ((uint8_t)CY_USBPD_VBUS_FILTER_CFG_POS_EN_NEG_DIS << PDSS_INTR15_CFG_PDS_SCP_SCP_OUT_FILT_CFG_POS);

        /* Set filter clock cycles if filter is required. */
        if ((bool)(debounce))
        {
            /* Subtracting 1 from filter clock cycle value as 0 translates to 1-2 clock cycles delay. */
            regval |= (((((debounce - 1u) != 0u) ? ((uint32_t)debounce - 1u) : 1u) & (uint32_t)0x1Fu) <<
                PDSS_INTR15_CFG_PDS_SCP_SCP_OUT_FILT_SEL_POS);

            regval |= (PDSS_INTR15_CFG_PDS_SCP_SCP_OUT_FILT_EN |
                PDSS_INTR15_CFG_PDS_SCP_SCP_OUT_DPSLP_MODE);
        }
        else
        {
            regval |= PDSS_INTR15_CFG_PDS_SCP_SCP_OUT_FILT_BYPASS;
        }

        pd->intr15_cfg_pds_scp = regval;

        /* Clear interrupt. */
        pd->intr15 = (PDSS_INTR15_PDS_SCP_CHANGED);

        /* Enable Interrupt. */
        pd->intr15_mask |= (PDSS_INTR15_PDS_SCP_CHANGED);

        /* Auto FET turn off mode. */
        if (context->vbatGndScpMode == VBUS_OCP_MODE_INT_AUTOCTRL)
        {
            Cy_USBPD_Fault_FetAutoModeEnable(context, pctrl, CY_USBPD_VBUS_FILTER_ID_PDS_SCP);
        }

        /*
         * Configure fault status on external GPIO for auto FET cut off.
         * Use fault GPIO in asynchronous inverted latch mode.
         * Use inverted polarity as we need high during idle and low during fault.
         * Fault is persistent and cleared only when re-enabling protection.
         */
        Cy_GPIO_Pin_FastInit(context->vbatGndFetPort, context->vbatGndFetPin, CY_GPIO_DM_PULLUP,
            false, HSIOM_SEL_GPIO);

        pd->fault_gpio_ctrl_extr |= PDSS_FAULT_GPIO_CTRL_EXTR_FAULT_CLEAR;

        pd->fault_gpio_ctrl_extr = (pd->fault_gpio_ctrl_extr &
            ~(PDSS_FAULT_GPIO_CTRL_EXTR_FAULT_MASK_EXTR_MASK |
            PDSS_FAULT_GPIO_CTRL_EXTR_FAULT_CLEAR)) |
            PDSS_FAULT_GPIO_CTRL_EXTR_FAULT_EN |
            PDSS_FAULT_GPIO_CTRL_EXTR_FAULT_GPIO_EXTR_0_POLARITY |
            PDSS_FAULT_GPIO_CTRL_EXTR_FAULT_GPIO_EXTR_1_POLARITY |
            (FAULT_GPIO_MASK_EXTR_VBAT_GND_SCP << PDSS_FAULT_GPIO_CTRL_EXTR_FAULT_MASK_EXTR_POS);

        /* HSIOM mode for P0 fault out and P1 fault out is same (12) */
#if defined(CY_DEVICE_CCG7D)
        Cy_GPIO_Pin_FastInit(context->vbatGndFetPort, context->vbatGndFetPin, CY_GPIO_DM_PULLUP,
            true, P0_2_USBPD0_FAULT_GPIO0);
#else
        Cy_GPIO_Pin_FastInit(context->vbatGndFetPort, context->vbatGndFetPin, CY_GPIO_DM_PULLUP,
            true, P0_5_USBPD0_FAULT_GPIO0);
#endif /* defined(CY_DEVICE_CCG7D) */

        context->vbatGndScpEnStatus = true;

        Cy_SysLib_ExitCriticalSection(state);
    }
    else
    {
        /* Already enabled, do nothing */
    }
#else /* !PDL_VBAT_GND_SCP_ENABLE */
    CY_UNUSED_PARAMETER(context);
    CY_UNUSED_PARAMETER(pctrl);
    CY_UNUSED_PARAMETER(mode);
#endif /* !PDL_VBAT_GND_SCP_ENABLE */
}
/*******************************************************************************
* Function Name: Cy_USBPD_Fault_VbatGndScpDis
****************************************************************************//**
*
* Disables VBAT-GND SCP Fault.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
*
* \param pctrl
* Flag indicating the type of gate driver to be controlled, true for
* P_CTRL and false for C_CTRL.
*
*
* \return
* None
*
*******************************************************************************/
void Cy_USBPD_Fault_VbatGndScpDis(cy_stc_usbpd_context_t *context, bool pctrl)
{
#if PDL_VBAT_GND_SCP_ENABLE
    PPDSS_REGS_T pd = context->base;
    uint32_t state;

    state = Cy_SysLib_EnterCriticalSection ();

    /* Clear and Reset Fault GPIO to normal operation. */
    pd->fault_gpio_ctrl_extr |= PDSS_FAULT_GPIO_CTRL_EXTR_FAULT_CLEAR;
    pd->fault_gpio_ctrl_extr &= ~PDSS_FAULT_GPIO_CTRL_EXTR_FAULT_CLEAR;
    Cy_GPIO_Pin_FastInit(context->vbatGndFetPort, context->vbatGndFetPin, CY_GPIO_DM_STRONG,
        false, HSIOM_SEL_GPIO);

    pd->intr15_mask &= ~PDSS_INTR15_PDS_SCP_CHANGED;
    pd->intr15 = PDSS_INTR15_PDS_SCP_CHANGED;

    /* CDT: 331952. Need to keep the SCP block enabled. */
    CY_USBPD_REG_FIELD_UPDATE(pd->pds_scp_ctrl, PDSS_PDS_SCP_CTRL_SCP_TESTMODE, 0x30u);
    pd->pds_scp_ctrl &= ~(PDSS_PDS_SCP_CTRL_SCP_EN |
        PDSS_PDS_SCP_CTRL_SCP_ISO_N);
    pd->intr15_cfg_pds_scp &= ~(PDSS_INTR15_CFG_PDS_SCP_SCP_OUT_FILT_EN |
        PDSS_INTR15_CFG_PDS_SCP_SCP_OUT_FILT_CFG_MASK | PDSS_INTR15_CFG_PDS_SCP_SCP_OUT_FILT_SEL_MASK |
        PDSS_INTR15_CFG_PDS_SCP_SCP_OUT_FILT_BYPASS);

    /* Remove SCP as source. */
    if (context->vbatGndScpMode == VBAT_GND_SCP_MODE_INT_AUTOCTRL)
    {
        Cy_USBPD_Fault_FetAutoModeDisable(context, pctrl, CY_USBPD_VBUS_FILTER_ID_PDS_SCP);
    }

    context->vbatGndScpEnStatus = false;

    Cy_SysLib_ExitCriticalSection (state);
#else /* !PDL_VBAT_GND_SCP_ENABLE */
    CY_UNUSED_PARAMETER(context);
    CY_UNUSED_PARAMETER(pctrl);
#endif /* !PDL_VBAT_GND_SCP_ENABLE */
}

/*******************************************************************************
* Function Name: Cy_USBPD_Fault_BrownOutDetEn
****************************************************************************//**
*
* Enables the detection of Brown Out Fault.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
*
* \return
* None
*
*******************************************************************************/
void Cy_USBPD_Fault_BrownOutDetEn(cy_stc_usbpd_context_t *context)
{
#if (NO_OF_TYPEC_PORTS <= 1)
    if (context-> port == TYPEC_PORT_0_IDX)
    {
#if PDL_VREG_BROWN_OUT_DET_ENABLE
        PPDSS_REGS_T pd;
        uint32_t state;
        pd = context->base;

        if (context->brownOutDetEnStatus == false)
        {
            state = Cy_SysLib_EnterCriticalSection();
            /*
            * Enable VDDD brown out detection fault.
            * When fault is detected, buck-boost and provider fet turns off
            * automatically through hardware.
            * Delayed retry is done for the recovery.
            */
            Cy_USBPD_Fault_FetAutoModeEnable(context, CCG_SRC_FET, CY_USBPD_VBUS_FILTER_ID_BROWN_OUT_DET);

            /* Clear and Enable interrupt. */
            pd->intr17       = PDSS_INTR17_PDBB_VREG_VDDD_BOD;
            pd->intr17_mask |= PDSS_INTR17_MASK_PDBB_VREG_VDDD_BOD_MASK;

            context->brownOutDetEnStatus  = true;
            Cy_SysLib_ExitCriticalSection(state);
        }
        else
        {
            /* Already enabled, do nothing */
        }
#else /* !PDL_VREG_BROWN_OUT_DET_ENABLE */
        CY_UNUSED_PARAMETER(context);
#endif /* !PDL_VREG_BROWN_OUT_DET_ENABLE */
    }
#else
    /* Use Conditional macro for WLC1 Series,
    *  since it use only Port0 as index
    */
#if defined(CY_DEVICE_SERIES_WLC1)
    if (context-> port == TYPEC_PORT_0_IDX)
#else /* !defined(CY_DEVICE_SERIES_WLC1) */
    if (context-> port == TYPEC_PORT_1_IDX)
#endif /* defined(CY_DEVICE_SERIES_WLC1) */
    {
#if PDL_VREG_BROWN_OUT_DET_ENABLE
        PPDSS_REGS_T pd;
        uint32_t state;
        uint8_t i;
        /* For WLC1, since it uses only Port0,
         * context can be assigned directly to usbpd_ctx_temp.
         * For others, we need to decrement the context, as it use Port1.
         */
#if !defined(CY_DEVICE_SERIES_WLC1)
        cy_stc_usbpd_context_t *usbpd_ctx_temp= --context;
#else /* defined(CY_DEVICE_SERIES_WLC1) */
        cy_stc_usbpd_context_t *usbpd_ctx_temp=context;
#endif /* defined(CY_DEVICE_SERIES_WLC1) */
        pd = usbpd_ctx_temp->base;

        if (context->brownOutDetEnStatus == false)
        {
            state = Cy_SysLib_EnterCriticalSection();
            /*
             * Enable VDDD brown out detection fault.
             * When fault is detected, buck-boost and provider fet turns off
             * automatically through hardware.
             * Delayed retry is done for the recovery.
             */

            for (i = 0; i < NO_OF_TYPEC_PORTS; i++)
            {
                Cy_USBPD_Fault_FetAutoModeEnable(usbpd_ctx_temp, CCG_SRC_FET, CY_USBPD_VBUS_FILTER_ID_BROWN_OUT_DET);
#if (NO_OF_TYPEC_PORTS > 1)
                ++usbpd_ctx_temp;
#endif /* (NO_OF_TYPEC_PORTS > 1) */
            }

            /* Clear and Enable interrupt. */
            pd->intr17       = PDSS_INTR17_PDBB_VREG_VDDD_BOD;
            pd->intr17_mask |= PDSS_INTR17_MASK_PDBB_VREG_VDDD_BOD_MASK;

            context->brownOutDetEnStatus  = true;
            Cy_SysLib_ExitCriticalSection(state);
        }
        else
        {
            /* Already enabled, do nothing */
        }
#else /* !PDL_VREG_BROWN_OUT_DET_ENABLE */
        CY_UNUSED_PARAMETER(context);
#endif /* !PDL_VREG_BROWN_OUT_DET_ENABLE */
    }
#endif /* (NO_OF_TYPEC_PORTS =< 1) */

}
/*******************************************************************************
* Function Name: Cy_USBPD_Fault_BrownOutDetDis
****************************************************************************//**
*
* Disables the detection of Brown Out Fault.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
*
* \return
* None
*
*******************************************************************************/
void Cy_USBPD_Fault_BrownOutDetDis(cy_stc_usbpd_context_t *context)
{
#if (NO_OF_TYPEC_PORTS <= 1)
    if (context-> port == TYPEC_PORT_0_IDX)
    {
#if PDL_VREG_BROWN_OUT_DET_ENABLE
        PPDSS_REGS_T pd;
        uint32_t state;
        pd = context->base;

        if (context->brownOutDetEnStatus == true)
        {
            state = Cy_SysLib_EnterCriticalSection ();

            /* Disable and Clear interrupt. */
            pd->intr17_mask &= ~PDSS_INTR17_MASK_PDBB_VREG_VDDD_BOD_MASK;
            pd->intr17 = PDSS_INTR17_PDBB_VREG_VDDD_BOD;
            Cy_USBPD_Fault_FetAutoModeDisable(context, CCG_SRC_FET, CY_USBPD_VBUS_FILTER_ID_BROWN_OUT_DET);

            context->brownOutDetEnStatus = false;

            Cy_SysLib_ExitCriticalSection (state);
        }
        else
        {
            /* Do nothing */
        }
#else /* !PDL_VREG_BROWN_OUT_DET_ENABLE */
        CY_UNUSED_PARAMETER(context);
#endif /* !PDL_VREG_BROWN_OUT_DET_ENABLE */
    }
#else
    /* Use Conditional macro for WLC1 Series,
    *  since it use only Port0 as index
    */
#if defined(CY_DEVICE_SERIES_WLC1)
    if (context-> port == TYPEC_PORT_0_IDX)
#else /* !defined(CY_DEVICE_SERIES_WLC1) */
    if (context-> port == TYPEC_PORT_1_IDX)
#endif /* !defined(CY_DEVICE_SERIES_WLC1) */
    {
#if PDL_VREG_BROWN_OUT_DET_ENABLE
        PPDSS_REGS_T pd;
        uint32_t state;
        uint8_t i;
        /* For WLC1, since it uses only Port0,
         * context can be assigned directly to usbpd_ctx_temp.
         * For others, we need to decrement the context, as it use Port1.
         */
#if !defined(CY_DEVICE_SERIES_WLC1)
        cy_stc_usbpd_context_t *usbpd_ctx_temp=--context;
#else /* defined(CY_DEVICE_SERIES_WLC1) */
        cy_stc_usbpd_context_t *usbpd_ctx_temp=context;
#endif /* defined(CY_DEVICE_SERIES_WLC1) */

        pd = usbpd_ctx_temp->base;

        if (context->brownOutDetEnStatus == true)
        {
            state = Cy_SysLib_EnterCriticalSection ();

            /* Disable and Clear interrupt. */
            pd->intr17_mask &= ~PDSS_INTR17_MASK_PDBB_VREG_VDDD_BOD_MASK;
            pd->intr17 = PDSS_INTR17_PDBB_VREG_VDDD_BOD;
            for (i = 0; i < NO_OF_TYPEC_PORTS; i++)
            {
                Cy_USBPD_Fault_FetAutoModeDisable(usbpd_ctx_temp, CCG_SRC_FET, CY_USBPD_VBUS_FILTER_ID_BROWN_OUT_DET);
#if (NO_OF_TYPEC_PORTS > 1)
                ++usbpd_ctx_temp;
#endif /* (NO_OF_TYPEC_PORTS > 1) */
            }
            context->brownOutDetEnStatus = false;

            Cy_SysLib_ExitCriticalSection (state);
        }
        else
        {
            /* Do nothing */
        }
#else /* !PDL_VREG_BROWN_OUT_DET_ENABLE */
        CY_UNUSED_PARAMETER(context);
#endif /* !PDL_VREG_BROWN_OUT_DET_ENABLE */
    }
#endif /* (NO_OF_TYPEC_PORTS =< 1) */

}
/*******************************************************************************
* Function Name: Cy_USBPD_Fault_BrownOutStatus
****************************************************************************//**
*
* Returns the status of Brown Out Fault.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
*
* \return bool
* Returns the status of Brown Out Fault.
*
*******************************************************************************/
bool Cy_USBPD_Fault_BrownOutStatus(cy_stc_usbpd_context_t *context)
{
#if (NO_OF_TYPEC_PORTS <= 1)
    if (context-> port == TYPEC_PORT_0_IDX)
    {
        bool status = false;
#if PDL_VREG_BROWN_OUT_DET_ENABLE
        PPDSS_REGS_T pd;
        pd = context->base;

        if ((pd->intr17_status_1 & PDSS_INTR17_STATUS_1_PDBB_VREG_VDDD_BOD_FILT) != 0u)
        {
            status = true;
        }

#else /* !PDL_VREG_BROWN_OUT_DET_ENABLE */
        CY_UNUSED_PARAMETER(context);
#endif /* !PDL_VREG_BROWN_OUT_DET_ENABLE */
        return status;
    }
    else
    {
        return false;
    }
#else
    /* Use Conditional macro for WLC1 Series,
    *  since it use only Port0 as index
    */
#if defined(CY_DEVICE_SERIES_WLC1)
    if (context-> port == TYPEC_PORT_0_IDX)
#else /* !defined(CY_DEVICE_SERIES_WLC1) */
    if (context-> port == TYPEC_PORT_1_IDX)
#endif /* !defined(CY_DEVICE_SERIES_WLC1) */
    {
        bool status = false;
#if PDL_VREG_BROWN_OUT_DET_ENABLE
        PPDSS_REGS_T pd;
        /* For WLC1, since it uses only Port0,
         * context can be assigned directly to usbpd_ctx_temp.
         * For others, we need to decrement the context, as it use Port1.
         */
#if !defined(CY_DEVICE_SERIES_WLC1)
        cy_stc_usbpd_context_t *usbpd_ctx_temp=--context;
#else /* defined(CY_DEVICE_SERIES_WLC1) */
        cy_stc_usbpd_context_t *usbpd_ctx_temp=context;
#endif /* defined(CY_DEVICE_SERIES_WLC1) */

        pd = usbpd_ctx_temp->base;

        if ((pd->intr17_status_1 & PDSS_INTR17_STATUS_1_PDBB_VREG_VDDD_BOD_FILT) != 0u)
        {
            status = true;
        }

#else /* !PDL_VREG_BROWN_OUT_DET_ENABLE */
            CY_UNUSED_PARAMETER(context);
#endif /* !PDL_VREG_BROWN_OUT_DET_ENABLE */
            return status;
    }
    else
    {
        return false;
    }
#endif /* (NO_OF_TYPEC_PORTS =< 1) */

}
/*******************************************************************************
* Function Name: Cy_USBPD_Fault_VregInrushDetEn
****************************************************************************//**
*
* Enables the detection of Vreg Inrush Fault.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
*
* \return
* None
*
*******************************************************************************/
void Cy_USBPD_Fault_VregInrushDetEn(cy_stc_usbpd_context_t *context)
{
#if (NO_OF_TYPEC_PORTS <= 1)
    if (context-> port == TYPEC_PORT_0_IDX)
    {
#if PDL_VREG_INRUSH_DET_ENABLE
        PPDSS_REGS_T pd;
        uint32_t regval;
        uint32_t state;
        pd = context->base;

        if (context->vregInrushDetEnStatus == false)
        {

            state = Cy_SysLib_EnterCriticalSection();

            /* Reset the Inrush filter. */
            regval = pd->intr17_cfg_0;
            regval &= ~(PDSS_INTR17_CFG_0_PDBB_VREG_IN_RUSH_DET_FILT_EN |
                    PDSS_INTR17_CFG_0_PDBB_VREG_IN_RUSH_DET_CFG_MASK |
                    PDSS_INTR17_CFG_0_PDBB_VREG_IN_RUSH_DET_FILT_SEL_MASK |
                    PDSS_INTR17_CFG_0_PDBB_VREG_IN_RUSH_DET_FILT_RESET |
                    PDSS_INTR17_CFG_0_PDBB_VREG_IN_RUSH_DET_FILT_BYPASS);
            pd->intr17_cfg_0 = regval;

            /* Configure the filter. */
            regval |= (CY_USBPD_VBUS_FILTER_CFG_POS_EN_NEG_DIS << PDSS_INTR17_CFG_0_PDBB_VREG_IN_RUSH_DET_CFG_POS) |
                ((uint32_t)20u << PDSS_INTR17_CFG_0_PDBB_VREG_IN_RUSH_DET_FILT_SEL_POS) |
                PDSS_INTR17_CFG_0_PDBB_VREG_IN_RUSH_DET_FILT_EN;
            pd->intr17_cfg_0 = regval;

            /* Clear and enable vreg inrush detect interrupt. */
            pd->intr17 = PDSS_INTR17_PDBB_40VREG_IN_RUSH_DET;
            pd->intr17_mask |= PDSS_INTR17_MASK_PDBB_40VREG_IN_RUSH_DET_MASK;

            context->vregInrushDetEnStatus = true;
            Cy_SysLib_ExitCriticalSection(state);
        }
        else
        {
            /* Already enabled, do nothing */
        }
#else /* !PDL_VREG_INRUSH_DET_ENABLE */
        CY_UNUSED_PARAMETER(context);
#endif /* !PDL_VREG_INRUSH_DET_ENABLE */
    }
#else
    /* Use Conditional macro for WLC1 Series,
    *  since it use only Port0 as index
    */
#if defined(CY_DEVICE_SERIES_WLC1)
    if (context-> port == TYPEC_PORT_0_IDX)
#else /* !defined(CY_DEVICE_SERIES_WLC1) */
    if (context-> port == TYPEC_PORT_1_IDX)
#endif /* !defined(CY_DEVICE_SERIES_WLC1) */
    {
#if PDL_VREG_INRUSH_DET_ENABLE
        PPDSS_REGS_T pd;
        uint32_t regval;
        uint32_t state;
        /* For WLC1, since it uses only Port0,
         * context can be assigned directly to usbpd_ctx_temp.
         * For others, we need to decrement the context, as it use Port1.
         */
#if !defined(CY_DEVICE_SERIES_WLC1)
        cy_stc_usbpd_context_t *usbpd_ctx_temp=--context;
#else /* defined(CY_DEVICE_SERIES_WLC1) */
        cy_stc_usbpd_context_t *usbpd_ctx_temp=context;
#endif /* defined(CY_DEVICE_SERIES_WLC1) */
        pd = usbpd_ctx_temp->base;
        uint8_t i;


        if (context->vregInrushDetEnStatus == false)
        {

            state = Cy_SysLib_EnterCriticalSection();
#if defined(CY_DEVICE_CCG7D)
            /*
             * Enable Vreg Inrush fault to detect VDDD droop.
             * When fault is detected, buck-boost and provider fet turns off
             * automatically through hardware.
             * Delayed retry is done for the recovery.
             */

            for (i = 0; i < NO_OF_TYPEC_PORTS; i++)
            {
                Cy_USBPD_Fault_FetAutoModeEnable(usbpd_ctx_temp, CCG_SRC_FET, CY_USBPD_VBUS_FILTER_ID_VREG_INRUSH_DET);
#if (NO_OF_TYPEC_PORTS > 1)
                ++usbpd_ctx_temp;
#endif /* (NO_OF_TYPEC_PORTS > 1) */
            }
#endif /* defined(CY_DEVICE_CCG7D) */

            /* Reset the Inrush filter. */
            regval = pd->intr17_cfg_0;
            regval &= ~(PDSS_INTR17_CFG_0_PDBB_VREG_IN_RUSH_DET_FILT_EN |
                    PDSS_INTR17_CFG_0_PDBB_VREG_IN_RUSH_DET_CFG_MASK |
                    PDSS_INTR17_CFG_0_PDBB_VREG_IN_RUSH_DET_FILT_SEL_MASK |
                    PDSS_INTR17_CFG_0_PDBB_VREG_IN_RUSH_DET_FILT_RESET |
                    PDSS_INTR17_CFG_0_PDBB_VREG_IN_RUSH_DET_FILT_BYPASS);
            pd->intr17_cfg_0 = regval;

            /* Configure the filter. */
            regval |= (CY_USBPD_VBUS_FILTER_CFG_POS_EN_NEG_DIS << PDSS_INTR17_CFG_0_PDBB_VREG_IN_RUSH_DET_CFG_POS) |
                    ((uint32_t)20u << PDSS_INTR17_CFG_0_PDBB_VREG_IN_RUSH_DET_FILT_SEL_POS) |
                    PDSS_INTR17_CFG_0_PDBB_VREG_IN_RUSH_DET_FILT_EN;
            pd->intr17_cfg_0 = regval;

            /* Clear and enable vreg inrush detect interrupt. */
            pd->intr17 = PDSS_INTR17_PDBB_40VREG_IN_RUSH_DET;
            pd->intr17_mask |= PDSS_INTR17_MASK_PDBB_40VREG_IN_RUSH_DET_MASK;

            context->vregInrushDetEnStatus = true;
            Cy_SysLib_ExitCriticalSection(state);
        }
        else
        {
            /* Already enabled, do nothing */
        }
#else /* !PDL_VREG_INRUSH_DET_ENABLE */
        CY_UNUSED_PARAMETER(context);
#endif /* !PDL_VREG_INRUSH_DET_ENABLE */
    }
#endif /* (NO_OF_TYPEC_PORTS =< 1) */
}
/*******************************************************************************
* Function Name: Cy_USBPD_Fault_VregInrushDetDis
****************************************************************************//**
*
* Disables the detection of Vreg Inrush Fault.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
*
* \return
* None
*
*******************************************************************************/

void Cy_USBPD_Fault_VregInrushDetDis(cy_stc_usbpd_context_t *context)
{
#if (NO_OF_TYPEC_PORTS <= 1)
    if (context-> port == TYPEC_PORT_0_IDX)
    {
#if PDL_VREG_INRUSH_DET_ENABLE
        PPDSS_REGS_T pd;
        uint32_t regval;
        uint32_t state;
        pd = context->base;
        if (context->vregInrushDetEnStatus == true)
        {
            pd = context->base;
            state = Cy_SysLib_EnterCriticalSection ();

            /* Disable and clear vreg inrush detect interrupt. */
            pd->intr17_mask &= ~PDSS_INTR17_MASK_PDBB_40VREG_IN_RUSH_DET_MASK;
            pd->intr17 = PDSS_INTR17_PDBB_40VREG_IN_RUSH_DET;

            /* Reset the Inrush filter. */
            regval = pd->intr17_cfg_0;
            regval &= ~(PDSS_INTR17_CFG_0_PDBB_VREG_IN_RUSH_DET_FILT_EN |
                    PDSS_INTR17_CFG_0_PDBB_VREG_IN_RUSH_DET_CFG_MASK |
                    PDSS_INTR17_CFG_0_PDBB_VREG_IN_RUSH_DET_FILT_SEL_MASK |
                    PDSS_INTR17_CFG_0_PDBB_VREG_IN_RUSH_DET_FILT_RESET |
                    PDSS_INTR17_CFG_0_PDBB_VREG_IN_RUSH_DET_FILT_BYPASS);
            pd->intr17_cfg_0 = regval;

            context->vregInrushDetEnStatus = false;

            Cy_SysLib_ExitCriticalSection (state);
        }
        else
        {
            /* Do nothing */
        }
#else /* !PDL_VREG_INRUSH_DET_ENABLE */
        CY_UNUSED_PARAMETER(context);
#endif /* !PDL_VREG_INRUSH_DET_ENABLE */
    }
#else
    /* Use Conditional macro for WLC1 Series,
    *  since it use only Port0 as index
    */
#if defined(CY_DEVICE_SERIES_WLC1)
    if (context-> port == TYPEC_PORT_0_IDX)
#else /* !defined(CY_DEVICE_SERIES_WLC1) */
    if (context-> port == TYPEC_PORT_1_IDX)
#endif /* !defined(CY_DEVICE_SERIES_WLC1) */
    {
#if PDL_VREG_INRUSH_DET_ENABLE
        PPDSS_REGS_T pd;
        uint32_t regval;
        uint32_t state;
        /* For WLC1, since it uses only Port0,
         * context can be assigned directly to usbpd_ctx_temp.
         * For others, we need to decrement the context, as it use Port1.
         */

#if !defined(CY_DEVICE_SERIES_WLC1)
        cy_stc_usbpd_context_t *usbpd_ctx_temp=--context;
#else /* defined(CY_DEVICE_SERIES_WLC1) */
        cy_stc_usbpd_context_t *usbpd_ctx_temp=context;
#endif /* defined(CY_DEVICE_SERIES_WLC1) */
        pd = usbpd_ctx_temp->base;
        uint8_t i;
        if (context->vregInrushDetEnStatus == true)
        {
            pd = context->base;

            state = Cy_SysLib_EnterCriticalSection ();

            /* Disable and clear vreg inrush detect interrupt. */
            pd->intr17_mask &= ~PDSS_INTR17_MASK_PDBB_40VREG_IN_RUSH_DET_MASK;
            pd->intr17 = PDSS_INTR17_PDBB_40VREG_IN_RUSH_DET;

            /* Reset the Inrush filter. */
            regval = pd->intr17_cfg_0;
            regval &= ~(PDSS_INTR17_CFG_0_PDBB_VREG_IN_RUSH_DET_FILT_EN |
                    PDSS_INTR17_CFG_0_PDBB_VREG_IN_RUSH_DET_CFG_MASK |
                    PDSS_INTR17_CFG_0_PDBB_VREG_IN_RUSH_DET_FILT_SEL_MASK |
                    PDSS_INTR17_CFG_0_PDBB_VREG_IN_RUSH_DET_FILT_RESET |
                    PDSS_INTR17_CFG_0_PDBB_VREG_IN_RUSH_DET_FILT_BYPASS);
            pd->intr17_cfg_0 = regval;

#if defined(CY_DEVICE_CCG7D)
            for (i = 0; i < NO_OF_TYPEC_PORTS; i++)
            {
                Cy_USBPD_Fault_FetAutoModeDisable(usbpd_ctx_temp, CCG_SRC_FET, CY_USBPD_VBUS_FILTER_ID_VREG_INRUSH_DET);
#if (NO_OF_TYPEC_PORTS > 1)
                ++usbpd_ctx_temp;
#endif /* (NO_OF_TYPEC_PORTS > 1) */
            }
#endif /* defined(CY_DEVICE_CCG7D) */

            context->vregInrushDetEnStatus = false;

            Cy_SysLib_ExitCriticalSection (state);
        }
        else
        {
                /* Do nothing */
        }
#else /* !PDL_VREG_INRUSH_DET_ENABLE */
        CY_UNUSED_PARAMETER(context);
#endif /* !PDL_VREG_INRUSH_DET_ENABLE */
    }
#endif /* (NO_OF_TYPEC_PORTS =< 1) */
}

/*******************************************************************************
* Function Name: Cy_USBPD_Fault_VregInrushStatus
****************************************************************************//**
*
* Returns the status of Vreg Inrush Fault.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
*
* \return bool
* Returns the status of Vreg Inrush Fault.
*
*******************************************************************************/
bool Cy_USBPD_Fault_VregInrushStatus(cy_stc_usbpd_context_t *context)
{
#if (NO_OF_TYPEC_PORTS <= 1)
    if (context-> port == TYPEC_PORT_0_IDX)
    {
        bool status = false;

#if PDL_VREG_INRUSH_DET_ENABLE
        PPDSS_REGS_T pd;
        pd = context->base;

        if ((pd->intr17_status_0 & PDSS_INTR17_STATUS_0_PDBB_40VREG_IN_RUSH_DET_STATUS) != 0u)
        {
            status = true;
        }
#else /* !PDL_VREG_INRUSH_DET_ENABLE */
        CY_UNUSED_PARAMETER(context);
#endif /* !PDL_VREG_INRUSH_DET_ENABLE */
        return status;
    }
    else
    { 
        return false;
    }
#else
    /* Use Conditional macro for WLC1 Series,
    *  since it use only Port0 as index
    */
#if defined(CY_DEVICE_SERIES_WLC1)
    if (context-> port == TYPEC_PORT_0_IDX)
#else /* !defined(CY_DEVICE_SERIES_WLC1) */
    if (context-> port == TYPEC_PORT_1_IDX)
#endif /* !defined(CY_DEVICE_SERIES_WLC1) */
    {
         bool status = false;

#if PDL_VREG_INRUSH_DET_ENABLE
        PPDSS_REGS_T pd;
        /* For WLC1, since it uses only Port0,
         * context can be assigned directly to usbpd_ctx_temp.
         * For others, we need to decrement the context, as it use Port1.
         */
#if !defined(CY_DEVICE_SERIES_WLC1)
        cy_stc_usbpd_context_t *usbpd_ctx_temp=--context;
#else /* defined(CY_DEVICE_SERIES_WLC1) */
        cy_stc_usbpd_context_t *usbpd_ctx_temp=context;
#endif /* defined(CY_DEVICE_SERIES_WLC1) */
        pd = usbpd_ctx_temp->base;

        if ((pd->intr17_status_0 & PDSS_INTR17_STATUS_0_PDBB_40VREG_IN_RUSH_DET_STATUS) != 0u)
        {
            status = true;
        }
#else /* !PDL_VREG_INRUSH_DET_ENABLE */
            CY_UNUSED_PARAMETER(context);
#endif /* !PDL_VREG_INRUSH_DET_ENABLE */
            return status;
    }
    else
    { 
        return false;
    }
#endif /* (NO_OF_TYPEC_PORTS =< 1) */
}

/** \cond DOXYGEN_HIDE */
void Cy_USBPD_Fault_CcOvp_SetPending(cy_stc_usbpd_context_t *context)
{
    context->ccOvpPending = (uint8_t)true;
}

void Cy_USBPD_Fault_Vbus_SetCsaRsense(cy_stc_usbpd_context_t *context, uint8_t rsense)
{
    context->vbusCsaRsense = rsense;
}

bool Cy_USBPD_Vbus_CompGetStatus(cy_stc_usbpd_context_t *context, cy_en_usbpd_vbus_filter_id_t id, bool isFiltered)
{
    CY_UNUSED_PARAMETER(context);
    CY_UNUSED_PARAMETER(id);
    CY_UNUSED_PARAMETER(isFiltered);

    return false;
}
/** \endcond */

/*******************************************************************************
* Function Name: Cy_USBPD_Hal_Remove_Internal_Fb_Res_Div
****************************************************************************//**
*
* Removes internal feedback res divider
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
*
* \return
* None
*
*******************************************************************************/
void Cy_USBPD_Hal_Remove_Internal_Fb_Res_Div(cy_stc_usbpd_context_t *context)
{
#if defined(CY_DEVICE_CCG3PA)
    PPDSS_REGS_T pd = context->base;
    pd->ea_ctrl |= PDSS_EA_CTRL_RES_DIV_BYPASS;
#else
    CY_UNUSED_PARAMETER(context);
#endif /* defined(CY_DEVICE_CCG3PA) */
}
/*******************************************************************************
* Function Name: Cy_USBPD_Adc_GetVbatVolt
****************************************************************************//**
*
* Returns the ADC Battery voltage.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \param adcId
* ADC ID for voltage measurement.
*
* \param level
* PD_ADC_NUM levels
*
* \return uint16_t
*  Battery Voltage
*
*******************************************************************************/
uint16_t Cy_USBPD_Adc_GetVbatVolt(cy_stc_usbpd_context_t *context, cy_en_usbpd_adc_id_t adcId,
                                  uint8_t level)
{
#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
    uint32_t result;
    
    /* We need to multiply PD_ADC_NUM_LEVELS by 2 as pd_vbus_mon_divider has been pre-multiplied by 2. */
    result = (((uint32_t)level * context->adcVdddMv[adcId] * VBAT_MON_DIV_8P_VAL)/(PD_ADC_NUM_LEVELS << 1u));
    return (uint16_t)result;
#else
    CY_UNUSED_PARAMETER(context);
    CY_UNUSED_PARAMETER(adcId);
    CY_UNUSED_PARAMETER(level);
    return 0u;
#endif /*#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) */
}
/*******************************************************************************
* Function Name: Cy_USBPD_MeasureVbat
****************************************************************************//**
*
* This function measures the battery voltage on Vin.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
*
* \return uint16_t
* Returns the battery voltage on Vin.
*
*******************************************************************************/
uint16_t Cy_USBPD_MeasureVbat(cy_stc_usbpd_context_t *context)
{
#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
    uint32_t state;
    uint8_t level;
    uint16_t retval;
    uint32_t regval;
    PPDSS_REGS_T pd = context->base;
    
    /*
     * VIN_8PER is going to only Port0 ADC1. This means, we have to always
     * use the Port 0 MUX. Also, the signal comes on AMUX_B of Port 0.
     */
    
    /* Enter critical section to avoid race conditions on pd->amux_ctrl register */
    state = Cy_SysLib_EnterCriticalSection();

    /* Take backup of bb_pwm_1_ctrl register */
    regval = pd->bb_pwm_1_ctrl;

    /* Select Vin_8per which is VBAT for adc_in
     * JIRA: CCGX_PA-598 The signal has been rerouted to ADC 0 using ADFT as a workaround. */
    CY_USBPD_REG_FIELD_UPDATE((pd->bb_pwm_1_ctrl), PDSS_BB_PWM_1_CTRL_BB_PWM_PWM_ADFT, (0x43u));

    /* Wait for sometime to get stable measurement */
    Cy_SysLib_DelayUs(20u);

    /* Sample the value: Data available only on port 0 ADC 1, AMUXB setting.
     * JIRA: CCGX_PA-598 The signal has been rerouted to ADC 0 using ADFT as a workaround. */
    level = Cy_USBPD_Adc_Sample(context, CY_USBPD_ADC_ID_0, CY_USBPD_ADC_INPUT_AMUX_A);
 
    /* Revert bb_pwm_1_ctrl settings for ADFT */
    pd->bb_pwm_1_ctrl = regval;

    /* Convert ADC output to VBAT in mv */
    retval = Cy_USBPD_Adc_GetVbatVolt(context, CY_USBPD_ADC_ID_0, level);
    
    /* Exit critical section after pd->amux_ctrl operations are completed */
    Cy_SysLib_ExitCriticalSection(state);

    return retval;
#else  /* (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) */
    CY_UNUSED_PARAMETER(context);
    return 0u;
#endif /* (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) */
}

/*
 * Minimum supported voltage for UVP. Any voltage lower may cause system to
 * not work as expected; the block references can get affected. This is now
 * limited to 3.1V.
 */
#define VIN_UVP_MIN_VOLT                (3100u)
/*******************************************************************************
* Function Name: Cy_USBPD_Fault_VinUvpEn
****************************************************************************//**
*
* Enables VIN UVP Fault.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \param threshold
* Vin UVP Threshold
*
* \param cb
* Callback
*
* \param pctrl
* Flag indicating the type of gate driver to be controlled, true for
* P_CTRL and false for C_CTRL.
*
* \param mode
* Vin UVP Mode
*
* \return
* None
*
*******************************************************************************/
void Cy_USBPD_Fault_VinUvpEn(cy_stc_usbpd_context_t *context, uint16_t threshold,
        cy_cb_adc_events_t cb, bool pctrl, cy_en_usbpd_vbus_uvp_mode_t mode)
{
#if (PDL_VIN_UVP_ENABLE && (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)))
    PPDSS_REGS_T pd = context->base;
    uint32_t regval;
    uint16_t vref;
    uint32_t state;
    uint8_t filterSel = 0x0Au;

#if defined(CY_DEVICE_SERIES_WLC1)
    /* WiCG1 uses VIN as VBUS, hence read VBUS fault table for VIN fault configuration */
    /* Convert debounce delay in us to filter clock cycles. */
    filterSel = GET_VBUS_OVP_TABLE(context)->debounce;
    filterSel = (uint8_t)system_get_clk_filt_sel(context->port, (((uint16_t) filterSel) * 10u));
#endif /* defined(CY_DEVICE_SERIES_WLC1) */

    state = Cy_SysLib_EnterCriticalSection();

    /* Store UVP mode. */
    context->usbpdConfig->vinUvpConfig.mode = mode;

    /* Set up UVP callback. */
    context->vinUvpCbk = cb;

    /* Store enable status. */
    context->vinUvpIsEnabled = true;

    if (context->usbpdConfig->vinUvpConfig.mode == VBUS_UVP_MODE_INT_COMP_AUTOCTRL)
    {
        Cy_USBPD_Fault_FetAutoModeDisable (context, pctrl, CY_USBPD_VBUS_FILTER_ID_VIN_UVP);
    }

    /* Ensure that we are within the limits. */
    if (threshold < VIN_UVP_MIN_VOLT)
    {
        threshold = VIN_UVP_MIN_VOLT;
    }

    /* Turn on block to detect VIN faults. */
    pd->bb_pwm_1_ctrl |= PDSS_BB_PWM_1_CTRL_BB_PWM_EN_VINVOUT_UVOV_DET;
    Cy_SysLib_DelayUs(100u);

    /* Calculate reference setting for OVP. 10% of VIN */
    vref = (((threshold / 10u) - 200u) / 10u);

    regval = pd->refgen_1_ctrl;
    regval &= ~(PDSS_REFGEN_1_CTRL_SEL1_MASK);
    regval |= ((uint32_t)vref << PDSS_REFGEN_1_CTRL_SEL1_POS);
    pd->refgen_1_ctrl = regval;

    /* Filter is already enabled, set filter value. */
    pd->intr17_cfg_4 &= ~(PDSS_INTR17_CFG_4_BB_PWM_VIN_UV_DET_FILT_EN);
    CY_USBPD_REG_FIELD_UPDATE(pd->intr17_cfg_4, PDSS_INTR17_CFG_4_BB_PWM_VIN_UV_DET_FILT_SEL, filterSel);
    pd->intr17_cfg_4 |= (PDSS_INTR17_CFG_4_BB_PWM_VIN_UV_DET_FILT_EN);

    /* Clear interrupt. */
    pd->intr17 = PDSS_INTR17_PDBB_PWM_VIN_UV_DET;

    /* Enable Interrupt. */
    pd->intr17_mask |= PDSS_INTR17_MASK_PDBB_PWM_VIN_UV_DET_MASK;

    /* Handle Auto mode. */
    if (context->usbpdConfig->vinUvpConfig.mode == VBUS_UVP_MODE_INT_COMP_AUTOCTRL)
    {
        Cy_USBPD_Fault_FetAutoModeEnable (context, pctrl, CY_USBPD_VBUS_FILTER_ID_VIN_UVP);
    }

    Cy_SysLib_ExitCriticalSection(state);
#else /* (PDL_VIN_UVP_ENABLE && (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))) */
    CY_UNUSED_PARAMETER(context);
    CY_UNUSED_PARAMETER(threshold);
    (void)(cy_cb_adc_events_t)cb;
    CY_UNUSED_PARAMETER(pctrl);
    CY_UNUSED_PARAMETER(mode);
#endif /* (PDL_VIN_UVP_ENABLE && (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))) */
}
/*******************************************************************************
* Function Name:  Cy_USBPD_Fault_VinUvpDis
****************************************************************************//**
*
* Disables VIN UVP fault
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \param pctrl
* Flag indicating the type of gate driver to be controlled, true for
* P_CTRL and false for C_CTRL.
*
* \return 
* None
*
*******************************************************************************/
void Cy_USBPD_Fault_VinUvpDis(cy_stc_usbpd_context_t *context, bool pctrl)
{
#if (PDL_VIN_UVP_ENABLE && (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)))
    PPDSS_REGS_T pd = context->base;
    uint32_t state;

    state = Cy_SysLib_EnterCriticalSection ();

    /* Clear AUTO MODE OVP detect. */
    if (context->usbpdConfig->vinUvpConfig.mode == CY_USBPD_VBUS_OVP_MODE_UVOV_AUTOCTRL)
    {
        Cy_USBPD_Fault_FetAutoModeDisable (context, pctrl, CY_USBPD_VBUS_FILTER_ID_VIN_UVP);
    }

    /* Disable and Clear interrupt. */
    pd->intr17_mask &= ~PDSS_INTR17_MASK_PDBB_PWM_VIN_UV_DET_MASK;
    pd->intr17 = PDSS_INTR17_PDBB_PWM_VIN_UV_DET;

    /* Disable the filter */
    pd->intr17_cfg_4 &= ~(PDSS_INTR17_CFG_4_BB_PWM_VIN_UV_DET_FILT_EN);

    /* Clear callback and enable status. */
    context->vinUvpCbk = NULL;
    context->vinUvpIsEnabled = false;

    /* Disable VIN UV/OV DET only if VIN OV is also disabled */
    if (context->vinOvpIsEnabled == false)
    {
        /* Turn off block to detect VIN faults. */
        pd->bb_pwm_1_ctrl &= ~PDSS_BB_PWM_1_CTRL_BB_PWM_EN_VINVOUT_UVOV_DET;
    }

    Cy_SysLib_ExitCriticalSection (state);
#else /* (PDL_VIN_UVP_ENABLE && (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))) */
    CY_UNUSED_PARAMETER(context);
    CY_UNUSED_PARAMETER(pctrl);
#endif /* (PDL_VIN_UVP_ENABLE && (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))) */
}

/*******************************************************************************
* Function Name: Cy_USBPD_Fault_VinOvpEn
****************************************************************************//**
*
* Enables VIN OVP Fault.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \param threshold
* Vin OVP Threshold
*
* \param cb
* Callback
*
* \param pctrl
* Flag indicating the type of gate driver to be controlled, true for
* P_CTRL and false for C_CTRL.
*
* \param mode
* Vin OVP Mode
*
* \return
* None
*
*******************************************************************************/

void Cy_USBPD_Fault_VinOvpEn(cy_stc_usbpd_context_t *context, uint16_t threshold,
    cy_cb_adc_events_t cb, bool pctrl, cy_en_usbpd_vbus_ovp_mode_t mode)
{
#if (PDL_VIN_OVP_ENABLE && (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)))
    PPDSS_REGS_T pd = context->base;
    uint16_t vref;
    uint32_t state;
    uint8_t filterSel = 0x0Au;

#if defined(CY_DEVICE_SERIES_WLC1)
    /* WiCG1 uses VIN as VBUS, hence read VBUS fault table for VIN fault configuration */
    /* Convert debounce delay in us to filter clock cycles. */
    filterSel = GET_VBUS_OVP_TABLE(context)->debounce;
    filterSel = (uint8_t)system_get_clk_filt_sel(context->port, (((uint16_t) filterSel) * 10u));
#endif /* defined(CY_DEVICE_SERIES_WLC1) */

    state = Cy_SysLib_EnterCriticalSection();

    /* Store OVP mode. */
    context->usbpdConfig->vinOvpConfig.mode = mode;
    /* Set up OVP callback. */
    context->vinOvpCbk = cb;
    /* Store enable status. */
    context->vinOvpIsEnabled = true;

    if (context->usbpdConfig->vinOvpConfig.mode == CY_USBPD_VBUS_OVP_MODE_UVOV_AUTOCTRL)
    {
        Cy_USBPD_Fault_FetAutoModeDisable (context, pctrl, CY_USBPD_VBUS_FILTER_ID_VIN_OVP);
    }

    /* Ensure that we are within the limits. */
    if (threshold < VIN_OVP_DETECT_MIN)
    {
        threshold = VIN_OVP_DETECT_MIN;
    }

    /* Turn on block to detect VIN faults. */
    pd->bb_pwm_1_ctrl |= PDSS_BB_PWM_1_CTRL_BB_PWM_EN_VINVOUT_UVOV_DET;
    Cy_SysLib_DelayUs(100u);
    /*
     * Calculate reference setting for OVP. 4% of VIN.
     * 10% error may be introduced as resister divider
     * is 4% of VIN voltage.
     */
    vref = (((threshold / 25u) - 200u) / 10u);

    /* QAC suppression 2985: REG_FEILD_UPDATE is a common functional macro that is used to
     * modify a register field without affecting any other bits of the register. When the field
     * starts from bit position 0, the left shift operation is redundant. Yet this operation is
     * retained to keep it generic and compatible for bitfields starting from other bit positions. */
    CY_USBPD_REG_FIELD_UPDATE(pd->refgen_1_ctrl, PDSS_REFGEN_1_CTRL_SEL0, (uint32_t)vref); /* PRQA S 2985 */

    /* Filter is already enabled, set filter value. */
    pd->intr17_cfg_4 &= ~(PDSS_INTR17_CFG_4_BB_PWM_VIN_OV_DET_FILT_EN);
    CY_USBPD_REG_FIELD_UPDATE(pd->intr17_cfg_4, PDSS_INTR17_CFG_4_BB_PWM_VIN_OV_DET_FILT_SEL, filterSel);
    pd->intr17_cfg_4 |= (PDSS_INTR17_CFG_4_BB_PWM_VIN_OV_DET_FILT_EN);

    /* Clear interrupt. */
    pd->intr17 = PDSS_INTR17_PDBB_PWM_VIN_OV_DET;

    /* Enable Interrupt. */
    pd->intr17_mask |= PDSS_INTR17_MASK_PDBB_PWM_VIN_OV_DET_MASK;

    /* Handle Auto mode. */
    if (context->usbpdConfig->vinOvpConfig.mode == CY_USBPD_VBUS_OVP_MODE_UVOV_AUTOCTRL)
    {
        Cy_USBPD_Fault_FetAutoModeEnable (context, pctrl, CY_USBPD_VBUS_FILTER_ID_VIN_OVP);
    }

    Cy_SysLib_ExitCriticalSection(state);
#else /* (PDL_VIN_OVP_ENABLE && (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))) */
    CY_UNUSED_PARAMETER(context);
    CY_UNUSED_PARAMETER(threshold);
    (void)(cy_cb_adc_events_t)cb;
    CY_UNUSED_PARAMETER(pctrl);
    CY_UNUSED_PARAMETER(mode);
#endif /* (PDL_VIN_OVP_ENABLE && (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))) */
}
/*******************************************************************************
* Function Name: Cy_USBPD_Fault_VinOvpDis
****************************************************************************//**
*
* Disables VIN OVP Fault
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \param pctrl
* Flag indicating the type of gate driver to be controlled, true for
* P_CTRL and false for C_CTRL.
*
* \return 
* None
*
*******************************************************************************/
void Cy_USBPD_Fault_VinOvpDis(cy_stc_usbpd_context_t *context, bool pctrl)
{
#if (PDL_VIN_OVP_ENABLE && (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)))
    PPDSS_REGS_T pd = context->base;
    uint32_t state;

    state = Cy_SysLib_EnterCriticalSection ();

    /* Clear AUTO MODE OVP detect. */
    if (context->usbpdConfig->vinOvpConfig.mode == CY_USBPD_VBUS_OVP_MODE_UVOV_AUTOCTRL)
    {
        Cy_USBPD_Fault_FetAutoModeDisable (context, pctrl, CY_USBPD_VBUS_FILTER_ID_VIN_OVP);
    }

    /* Disable and Clear interrupt. */
    pd->intr17_mask &= ~PDSS_INTR17_MASK_PDBB_PWM_VIN_OV_DET_MASK;
    pd->intr17 = PDSS_INTR17_PDBB_PWM_VIN_OV_DET;

    /* Leave the filter disabled. */
    pd->intr17_cfg_4 &= ~(PDSS_INTR17_CFG_4_BB_PWM_VIN_OV_DET_FILT_EN);

    /* Clear callback. */
    context->vinOvpCbk = NULL;
    context->vinOvpIsEnabled = false;

    /* Disable VIN UV/OV DET only if VIN UV is also disabled */
    if (context->vinOvpIsEnabled == false)
    {
        /* Turn off block to detect VIN faults. */
        pd->bb_pwm_1_ctrl &= ~PDSS_BB_PWM_1_CTRL_BB_PWM_EN_VINVOUT_UVOV_DET;
    }

    Cy_SysLib_ExitCriticalSection (state);
#else /* (PDL_VIN_OVP_ENABLE && (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))) */
    CY_UNUSED_PARAMETER(context);
    CY_UNUSED_PARAMETER(pctrl);
#endif /* (PDL_VIN_OVP_ENABLE && (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))) */
}

/*******************************************************************************
* Function Name: Cy_USBPD_Vbus_Ctrl_FbGetIdacStep
****************************************************************************//**
*
* This function returns the signed iDAC step change required to reach the new
* voltage specified from the current voltage specified. It does not rely on
* the actual voltage global variables but the parameters to the function. The
* calculation is done without any voltage accuracy improvement algorithm and
* is used by the control algorithms to reach the required voltage.
*
* \param new_volt
* New voltage to reach
*
* \param cur_volt
* Current voltage
*
* \return int16_t
* Returns required signed iDAC step change.
*
*******************************************************************************/
int16_t Cy_USBPD_Vbus_Ctrl_FbGetIdacStep(uint16_t new_volt, uint16_t cur_volt)
{
#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
    return (((int16_t)new_volt - (int16_t)cur_volt) / VBUS_CHANGE_PER_DAC_BIT);
#else
    CY_UNUSED_PARAMETER(new_volt);
    CY_UNUSED_PARAMETER(cur_volt);
    return 0;
#endif /*#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) */
}
/*******************************************************************************
* Function Name: Cy_USBPD_CcOvpControl
****************************************************************************//**
*
* This function enables/disables the CC OVP.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
*
* \param flag
* Flag to indicate to enable or disable the fault.
*
* \return 
* None.
*
*******************************************************************************/

void Cy_USBPD_CcOvpControl(cy_stc_usbpd_context_t * context, bool flag)
{
#if PDL_CC_OVP_ENABLE
#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
    PPDSS_REGS_T pd = context->base;
    uint32_t reg_val;

    if (true == flag)
    {
        /* Enable CC OVP */
        reg_val = pd->vconn20_ctrl;
        reg_val |= (1u << (1u + PDSS_VCONN20_CTRL_T_VCONN_POS));
        reg_val |= (1u << (2u + PDSS_VCONN20_CTRL_T_VCONN_POS));
        reg_val &= (~((uint32_t)1u << (9u + PDSS_VCONN20_CTRL_T_VCONN_POS)));
        reg_val |= (PDSS_VCONN20_CTRL_VCONN20_EN_IBIAS);
        pd->vconn20_ctrl = reg_val;
    }
    else
    {
        /* Disable CC OVP */
        reg_val = pd->vconn20_ctrl;
        reg_val &= (~((uint32_t)1u << (1u + PDSS_VCONN20_CTRL_T_VCONN_POS)));
        reg_val &= (~((uint32_t)1u << (2u + PDSS_VCONN20_CTRL_T_VCONN_POS)));
        reg_val |= ((uint32_t)1u << (9u + PDSS_VCONN20_CTRL_T_VCONN_POS));
        reg_val &= (~PDSS_VCONN20_CTRL_VCONN20_EN_IBIAS);
        pd->vconn20_ctrl = reg_val;
    }
#elif (defined(CY_DEVICE_CCG6DF_CFP))
        PPDSS_REGS_T pd = context->base;
        uint32_t reg_val;

        /**
         * Enable CC OVP fault
         */
        if (true == flag)
        {
            /**
             * If CC OVP not enabled yet, then enable it
             */
            if((pd->pd_30vconn_ctrl & (PDSS_PD_30VCONN_CTRL_EN_OVP_CC1 | PDSS_PD_30VCONN_CTRL_EN_OVP_CC2)) == 0U)
            {
                /* Disable the CC_OVP interrupts */
                pd->intr1_cfg_cc12_ovp_hs &= ~(PDSS_INTR1_CFG_CC12_OVP_HS_CC1_OVP_FILT_EN
                        | PDSS_INTR1_CFG_CC12_OVP_HS_CC2_OVP_FILT_EN);

                reg_val = pd->pd_30vconn_ctrl;
                /* Enable OVP fault detection on CC1 and CC2 */
                reg_val |= (PDSS_PD_30VCONN_CTRL_EN_OVP_CC1 | PDSS_PD_30VCONN_CTRL_EN_OVP_CC2);

                /* Enable all the outputs. */
                reg_val |= PDSS_PD_30VCONN_CTRL_ISO_N;

                /* Enable OVP COMP */
                reg_val |= PDSS_PD_30VCONN_CTRL_EN_CC_V5V_OVP_COMP;
                pd->pd_30vconn_ctrl = reg_val;

                /* vconn Block config delay to ensure all input supplies including v5v are stable before enabling this block. */
                Cy_SysLib_DelayUs(100);
                /* Enable the CC_OVP interrupts */
                pd->intr1_cfg_cc12_ovp_hs |= (PDSS_INTR1_CFG_CC12_OVP_HS_CC1_OVP_FILT_EN
                        | PDSS_INTR1_CFG_CC12_OVP_HS_CC2_OVP_FILT_EN);
                pd->intr1_mask |= (PDSS_INTR1_CC1_OVP_CHANGED | PDSS_INTR1_CC2_OVP_CHANGED);
                /*clear the interrupt*/
                pd->intr1 = (PDSS_INTR1_CC1_OVP_CHANGED | PDSS_INTR1_CC2_OVP_CHANGED);
            }
        }
        /**
         * Disable CC OVP fault, if we are not LPM
         */
        else
        {
            /* Disable the CC_OVP interrupts */
            pd->intr1_cfg_cc12_ovp_hs &= ~(PDSS_INTR1_CFG_CC12_OVP_HS_CC1_OVP_FILT_EN
                    | PDSS_INTR1_CFG_CC12_OVP_HS_CC2_OVP_FILT_EN);
            reg_val = pd->pd_30vconn_ctrl;
            /* Disable OVP fault detection on CC1/CC2 */
            reg_val &= ~(PDSS_PD_30VCONN_CTRL_EN_OVP_CC1 | PDSS_PD_30VCONN_CTRL_EN_OVP_CC2 | PDSS_PD_30VCONN_CTRL_EN_CC_V5V_OVP_COMP);
            pd->pd_30vconn_ctrl = reg_val;
            pd->intr1_mask &= ~(PDSS_INTR1_CC1_OVP_CHANGED | PDSS_INTR1_CC2_OVP_CHANGED);
        }
#else
    CY_UNUSED_PARAMETER(context);
    CY_UNUSED_PARAMETER(flag);
#endif /*#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) */
#endif /* PDL_CC_OVP_ENABLE */
}

/*******************************************************************************
* Function Name: Cy_USBPD_Vbus_GetTrimIdac
****************************************************************************//**
*
* This function returns the iDAC value to be used for attaining the voltage.
* It calculates the value based on the TRIM setting loaded in SFLASH and is
* applicable only for opto-isolator based designs.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
*
* \param volt_mv
* Voltage in millivolts
*
* \return int16_t
* Returns the iDAC value.
*
*******************************************************************************/
int16_t Cy_USBPD_Vbus_GetTrimIdac(cy_stc_usbpd_context_t * context, uint16_t volt_mv)
{
#if (VBUS_CTRL_TRIM_ADJUST_ENABLE)
    uint8_t port = context->port;
    int16_t trim_code;
    int16_t src_adj = (int16_t)BG_ISRC_DAC_CTRL_0_3V((port));
    uint32_t trim_snk_20v;
    uint32_t trim_snk_5v;
    uint32_t trim_src_0_5v;

    trim_snk_20v = BG_ISNK_DAC_CTRL_COMBINED_20V((port));
    trim_snk_5v = BG_ISNK_DAC_CTRL_COMBINED_5V((port));
    trim_src_0_5v = BG_ISRC_DAC_CTRL_0_5V((port));

    if (volt_mv >= CY_PD_VSAFE_5V)
    {
        /* Sink iDAC will be used */
        trim_code = (((((int16_t)trim_snk_20v -
                            ((int16_t)trim_snk_5v - (int16_t)trim_src_0_5v)) *
                        (int16_t)Cy_USBPD_Vbus_Ctrl_FbGetIdacStep(volt_mv, CY_PD_VSAFE_5V)) +
                    (((int16_t)trim_snk_5v - (int16_t)trim_src_0_5v) * 750)) / 750);
    }
    else
    {
        /* Source iDac will be used */
        if(BG_ISRC_DAC_CTRL_0_3V((port)) == 0u)
        {
            src_adj = 100;
        }
        trim_code = -((((src_adj +
                            ((int16_t)trim_snk_5v - (int16_t)trim_src_0_5v)) *
                Cy_USBPD_Vbus_Ctrl_FbGetIdacStep(CY_PD_VSAFE_5V, volt_mv)) -
                    (((int16_t)trim_snk_5v - (int16_t)trim_src_0_5v) * 100)) / 100);
    }

#if FG_PART
    return (trim_code + 2);
#else /* !FG_PART */
    return trim_code;
#endif /* FG_PART */
#else /* !(VBUS_CTRL_TRIM_ADJUST_ENABLE) */
    CY_UNUSED_PARAMETER(context);
    CY_UNUSED_PARAMETER(volt_mv);
    return 0;
#endif /* !(VBUS_CTRL_TRIM_ADJUST_ENABLE) */
}
/*******************************************************************************
* Function Name: Cy_USBPD_Vbus_SystemClockDisable
****************************************************************************//**
*
* Disables the system clocks while entering into sleep.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
*
*******************************************************************************/
void Cy_USBPD_Vbus_SystemClockDisable(cy_stc_usbpd_context_t * context)
{
#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2))
    /* We can use the same clocks for both PD ports for following functions. */
    (void)Cy_SysClk_PeriphDisableDivider(CY_SYSCLK_DIV_8_BIT, 5U);

#if defined(CY_DEVICE_CCG7D)

#if (!HFCLK_CHANGE_OVER_SLEEP)
    /* Operating the below clock at 100KHz in sleep. */
    context->bbSoftClkDividerValue = Cy_SysClk_PeriphGetDivider(CY_SYSCLK_DIV_8_BIT, 7U);
    (void)Cy_SysClk_PeriphSetDivider(CY_SYSCLK_DIV_8_BIT, 7U,CYDEV_BCLK__HFCLK__MHZ * 10u);
#endif /* !HFCLK_CHANGE_OVER_SLEEP */

    (void)Cy_SysClk_PeriphDisableDivider(CY_SYSCLK_DIV_16_BIT, 0U);
    (void)Cy_SysClk_PeriphDisableDivider(CY_SYSCLK_DIV_16_BIT, 1U);
    
    /* We need separate clocks for second port for following functions */
    (void)Cy_SysClk_PeriphDisableDivider(CY_SYSCLK_DIV_16_BIT, 2U);
    (void)Cy_SysClk_PeriphDisableDivider(CY_SYSCLK_DIV_16_BIT, 3U);
    
    /* We can use the same clocks for both PD ports for following functions. */
    (void)Cy_SysClk_PeriphDisableDivider(CY_SYSCLK_DIV_8_BIT, 6U);

#if (HFCLK_CHANGE_OVER_SLEEP || SYSCLK_CHANGE_OVER_SLEEP)
    context->clkSelectValue = SRSSLT->CLK_SELECT;
#endif /* (HFCLK_CHANGE_OVER_SLEEP || SYSCLK_CHANGE_OVER_SLEEP) */
    
#if (!HFCLK_CHANGE_OVER_SLEEP)
    /* operating the below clocks at 100KHz in sleep */
    context->filt1ClkDividerValue = Cy_SysClk_PeriphGetDivider(CY_SYSCLK_DIV_8_BIT, 2U);
    (void)Cy_SysClk_PeriphSetDivider(CY_SYSCLK_DIV_8_BIT, 2U,CYDEV_BCLK__HFCLK__MHZ * 10u);
#else
    /* We can use the same clocks for both PD ports for following functions. */
    context->filt1ClkDividerValue = Cy_SysClk_PeriphGetDivider(CY_SYSCLK_DIV_8_BIT, 3U);
    (void)Cy_SysClk_PeriphSetDivider(CY_SYSCLK_DIV_8_BIT, 3U, (((context->filt1ClkDividerValue + 1u) >> 3u) - 1u));
#endif /* !HFCLK_CHANGE_OVER_SLEEP */

#if HFCLK_CHANGE_OVER_SLEEP
    CY_USBPD_REG_FIELD_UPDATE_MTB((SRSSLT->CLK_SELECT), SRSSLT_CLK_SELECT_HFCLK_DIV, (3u));
#endif /* HFCLK_CHANGE_OVER_SLEEP */

#if SYSCLK_CHANGE_OVER_SLEEP
    CY_USBPD_REG_FIELD_UPDATE_MTB(SRSSLT->CLK_SELECT, SRSSLT_CLK_SELECT_HFCLK_DIV, 3u);
#endif /* SYSCLK_CHANGE_OVER_SLEEP */
#endif /* defined(CY_DEVICE_CCG7D) */
#endif /* (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2)) */
     CY_UNUSED_PARAMETER(context);
}
/*******************************************************************************
* Function Name: Cy_USBPD_Vbus_SystemClockEnable
****************************************************************************//**
*
* Enables the system clocks with old stored value while wakeup.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
*******************************************************************************/
void Cy_USBPD_Vbus_SystemClockEnable(cy_stc_usbpd_context_t * context)
{
#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2))
#if (defined(CY_DEVICE_CCG7D))
#if (HFCLK_CHANGE_OVER_SLEEP || SYSCLK_CHANGE_OVER_SLEEP)
    SRSSLT->CLK_SELECT = context->clkSelectValue;
#endif /* (HFCLK_CHANGE_OVER_SLEEP || SYSCLK_CHANGE_OVER_SLEEP) */
#endif /* (defined(CY_DEVICE_CCG7D)) */

#if (!HFCLK_CHANGE_OVER_SLEEP)
    /* Retain the clocks to Old frequency */
    (void)Cy_SysClk_PeriphSetDivider(CY_SYSCLK_DIV_8_BIT, 2U, context->refgenClkDividerValue + 1u);
#else
    (void)Cy_SysClk_PeriphSetDivider(CY_SYSCLK_DIV_8_BIT, 3U, context->filt1ClkDividerValue + 1u);
#endif /* !HFCLK_CHANGE_OVER_SLEEP */

#if defined(CY_DEVICE_CCG7D)

#if (!HFCLK_CHANGE_OVER_SLEEP)
    (void)Cy_SysClk_PeriphSetDivider(CY_SYSCLK_DIV_8_BIT, 7U,context->bbSoftClkDividerValue + 1u);
#endif /* !HFCLK_CHANGE_OVER_SLEEP */

    (void)Cy_SysClk_PeriphEnableDivider(CY_SYSCLK_DIV_16_BIT, 0U);
    (void)Cy_SysClk_PeriphEnableDivider(CY_SYSCLK_DIV_16_BIT, 1U);

    /* We need separate clocks for second port for following functions */
    (void)Cy_SysClk_PeriphEnableDivider(CY_SYSCLK_DIV_16_BIT, 2U);
    (void)Cy_SysClk_PeriphEnableDivider(CY_SYSCLK_DIV_16_BIT, 3U);

    /* We can use the same clocks for both PD ports for following functions. */
    (void)Cy_SysClk_PeriphEnableDivider(CY_SYSCLK_DIV_8_BIT, 6U);

#endif /* defined(CY_DEVICE_CCG7D) */   
    /* We can use the same clocks for both PD ports for following functions. */
    (void)Cy_SysClk_PeriphEnableDivider(CY_SYSCLK_DIV_8_BIT, 5U);
#endif /* (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_CCG3PA) || defined(CY_DEVICE_CCG3PA2)) */
     CY_UNUSED_PARAMETER(context);
}

/* Min OVP detection level for VBAT. */
#define BAT_OVP_DETECT_MIN              (3000u)

/* min reference voltage in mV. */
#define BAT_REF_VOLT_MIN                (200u)

/* reference voltage step size in mV. */
#define BAT_REF_VOLT_STEP               (10u)

/* max voltage in mV. for 20% divider */
#define BAT_VBUS_VOLT_MAX               (9000u)

/* Max. VREF setting. */
#define BAT_VREF_MAX_SETTING            (199u)

/* Mux to select VBUS_C or VBUS_IN for GAIN 20% */
#define AMUX_NHVN_OV_BIT_0              (0u)

/* Mux to select VBUS_C or VBUS_IN for GAIN 8% */
#define AMUX_NHVN_OV_BIT_7              (7u)

/* Mux to select GAIN 20% or 8% output*/
#define AMUX_OV_BIT_10                  (10u)

/* Mux to select VBUS_C/VBUS_IN or VBUS_MON */
#define AMUX_OV_BIT_11                  (11u)

/*******************************************************************************
* Function Name: Cy_USBPD_Fault_Vbat_OvpEnable
****************************************************************************//**
*
* Enable Over Voltage Protection (OVP) control using the internal UV-OV block.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \param threshold
* OVP Voltage threshold in mV units.
*
* \param filterSel
* Filter value
*
* \param cb
* Callback function to be called on fault detection.
*
* \param pctrl
* Flag indicating the type of gate driver to be controlled, true for
* P_CTRL and false for C_CTRL.
*
*******************************************************************************/
void Cy_USBPD_Fault_Vbat_OvpEnable(cy_stc_usbpd_context_t *context, uint16_t threshold, uint8_t filterSel,
        cy_cb_vbus_fault_t cb, bool pctrl)
{
    CY_UNUSED_PARAMETER(pctrl);

#if (defined(CY_DEVICE_SERIES_PMG1B1))
    PPDSS_REGS_T pd = context->base;
    uint32_t regVal;
    uint16_t vref;

    /* Store OVP parameters. */
    context->vbatOvpCbk = cb;

    /* Make sure threshold is above the minimum trip point to avoid false triggers. */
    if (threshold < BAT_OVP_DETECT_MIN)
    {
        threshold = BAT_OVP_DETECT_MIN;
    }

    if (threshold < BAT_VBUS_VOLT_MAX)
    {
        /* Connect output to divider */
        pd->amux_nhvn_ctrl |= ((uint32_t)1u << AMUX_NHVN_OV_BIT_0);
        pd->amux_ctrl |= ((uint32_t)1u << AMUX_OV_BIT_10);
        pd->amux_ctrl &= ~((uint32_t)1u << AMUX_OV_BIT_11);

        /* Calculate the actual reference voltage. Cap the value to the max. supported. */
        /* Gain 20% */
        vref = (((threshold / 5) - BAT_REF_VOLT_MIN) / BAT_REF_VOLT_STEP);
    }
    else
    {
        /* Connect output to divider */
        pd->amux_nhvn_ctrl |= ((uint32_t)1u << AMUX_NHVN_OV_BIT_7);
        pd->amux_ctrl &= ~((uint32_t)1u << AMUX_OV_BIT_10);
        pd->amux_ctrl &= ~((uint32_t)1u << AMUX_OV_BIT_11);

        /* Calculate the actual reference voltage. Cap the value to the max. supported. */
        /* Gain 8% */
        vref = ((((threshold * 2) / 25) - BAT_REF_VOLT_MIN) / BAT_REF_VOLT_STEP);
    }

    if (vref > BAT_VREF_MAX_SETTING)
    {
        vref = BAT_VREF_MAX_SETTING;
    }

    /* Program reference voltage for OV comparator. */
    regVal = pd->refgen_1_ctrl;
    regVal &= ~(PDSS_REFGEN_1_CTRL_SEL0_MASK);
    regVal |= (vref << PDSS_REFGEN_1_CTRL_SEL0_POS);
    pd->refgen_1_ctrl = regVal;

    /* Turn on comparator. */
    pd->comp_ctrl[CY_USBPD_VBUS_COMP_ID_VSRC_NEW_P] |= PDSS_COMP_CTRL_COMP_ISO_N;
    pd->comp_ctrl[CY_USBPD_VBUS_COMP_ID_VSRC_NEW_P] &= ~PDSS_COMP_CTRL_COMP_PD;

    Cy_SysLib_DelayUs(10);

    /* Filter configuration. */
    pd->intr7_filter_cfg[CY_USBPD_VBUS_FILTER_ID_OV] &= ~PDSS_INTR7_FILTER_CFG_FILT_EN;
    regVal = pd->intr7_filter_cfg[CY_USBPD_VBUS_FILTER_ID_OV] & ~(PDSS_INTR7_FILTER_CFG_FILT_CFG_MASK
            | PDSS_INTR7_FILTER_CFG_CLK_LF_FILT_SEL_MASK | PDSS_INTR7_FILTER_CFG_CLK_LF_FILT_BYPASS);
    regVal |= PDSS_INTR7_FILTER_CFG_CLK_LF_FILT_RESET;

    /* Set filter clock cycles if filter is required. */
    regVal |= (filterSel << PDSS_INTR7_FILTER_CFG_FILT_CFG_POS);

    /* Set edge detection. */
    regVal |= (CY_USBPD_VBUS_FILTER_CFG_POS_EN_NEG_DIS << PDSS_INTR7_FILTER_CFG_FILT_CFG_POS);
    regVal |= PDSS_INTR7_FILTER_CFG_FILT_EN;

    pd->intr7_filter_cfg[CY_USBPD_VBUS_FILTER_ID_OV] = regVal;

    /* Clear interrupt. */
    pd->intr7 = (1U << CY_USBPD_VBUS_FILTER_ID_OV);

    /* Enable Interrupt. */
    pd->intr7_mask |= (1U << CY_USBPD_VBUS_FILTER_ID_OV);
#else
    CY_UNUSED_PARAMETER(context);
    CY_UNUSED_PARAMETER(threshold);
    CY_UNUSED_PARAMETER(filterSel);
    (void)(cy_cb_vbus_fault_t)cb;
#endif /* (defined(CY_DEVICE_SERIES_PMG1B1)) */
}


/*******************************************************************************
* Function Name: Cy_USBPD_Fault_Vbat_OvpDisable
****************************************************************************//**
*
* Disable Over Voltage Protection (OVP) control.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \param pctrl
* Flag indicating the type of gate driver to be controlled, true for
* P_CTRL and false for C_CTRL.
*
*******************************************************************************/
void Cy_USBPD_Fault_Vbat_OvpDisable(cy_stc_usbpd_context_t *context, bool pctrl)
{
    CY_UNUSED_PARAMETER(pctrl);

#if (defined(CY_DEVICE_SERIES_PMG1B1))
    PPDSS_REGS_T pd = context->base;
    uint32_t state;

    state = Cy_SysLib_EnterCriticalSection();

    /* Disable comparator. */
    pd->comp_ctrl[CY_USBPD_VBUS_COMP_ID_VSRC_NEW_P] &= ~PDSS_COMP_CTRL_COMP_ISO_N;
    pd->comp_ctrl[CY_USBPD_VBUS_COMP_ID_VSRC_NEW_P] |= PDSS_COMP_CTRL_COMP_PD;

    /* Disable filter. */
    pd->intr7_filter_cfg[CY_USBPD_VBUS_FILTER_ID_OV] &= ~(PDSS_INTR7_FILTER_CFG_FILT_EN |
            PDSS_INTR7_FILTER_CFG_FILT_CFG_MASK | PDSS_INTR7_FILTER_CFG_CLK_LF_FILT_SEL_MASK |
            PDSS_INTR7_FILTER_CFG_CLK_LF_FILT_BYPASS);

    /* Disable and clear OV interrupts. */
    pd->intr7_mask &= ~(1U << CY_USBPD_VBUS_FILTER_ID_OV);
    pd->intr7 = 1U << CY_USBPD_VBUS_FILTER_ID_OV;

    /* Clear callback. */
    context->vbatOvpCbk = NULL;

    Cy_SysLib_ExitCriticalSection(state);
#else
    CY_UNUSED_PARAMETER(context);
#endif /* (defined(CY_DEVICE_SERIES_PMG1B1)) */
}

/*******************************************************************************
* Function Name: Cy_USBPD_Fault_Vbat_OvpIntrHandler
****************************************************************************//**
*
* VBAT OVP fault interrupt handler function.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
*******************************************************************************/
void Cy_USBPD_Fault_Vbat_OvpIntrHandler(cy_stc_usbpd_context_t *context)
{
#if (defined(CY_DEVICE_SERIES_PMG1B1))

    PPDSS_REGS_T pd = context->base;

    /* Disable and clear OV interrupt. */
    pd->intr7_mask &= ~(1U << CY_USBPD_VBUS_FILTER_ID_OV);
    pd->intr7 = 1U << CY_USBPD_VBUS_FILTER_ID_OV;

    /* Invoke OVP callback. */
    if (context->vbatOvpCbk != NULL)
    {
        context->vbatOvpCbk(context, true);
    }
#else
    CY_UNUSED_PARAMETER(context);
#endif /* (defined(CY_DEVICE_SERIES_PMG1B1)) */
}

/*
 * Minimum supported voltage for UVP. Any voltage lower may cause system to
 * not work as expected; the block references can get affected. This is now
 * limited to 3.15V.
 */
#define BAT_UVP_MIN_VOLT                (3100)

/* Mux to select VBUS_C or VBUS_IN for GAIN 10% */
#define AMUX_NHVN_UV_BIT_5              (5u)

/* Mux to select GAIN 20% or 10% output*/
#define AMUX_UV_BIT_8                  (8u)

/* Mux to select VBUS_C/VBUS_IN or VBUS_MON */
#define AMUX_UV_BIT_9                  (9u)

/*******************************************************************************
* Function Name: Cy_USBPD_Fault_Vbat_UvpEnable
****************************************************************************//**
*
* Enable Under Voltage Protection (UVP) control using the internal UV-OV block.
* UVP is only expected to be used while PD-port is the power source.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \param threshold
* UVP threshold Voltage in mV units.
*
* \param filterSel
* Filter value
*
* \param cb
* Callback function to be called on fault detection.
*
* \param pctrl
* Flag indicating the type of gate driver to be controlled, true for
* P_CTRL and false for C_CTRL.
*
*******************************************************************************/
void Cy_USBPD_Fault_Vbat_UvpEnable(cy_stc_usbpd_context_t *context, uint16_t threshold, uint8_t filterSel, cy_cb_vbus_fault_t cb, bool pctrl)
{
    CY_UNUSED_PARAMETER(pctrl);
#if (defined(CY_DEVICE_SERIES_PMG1B1))

    uint16_t vref;
    uint32_t regVal = 0;
    PPDSS_REGS_T pd = context->base;

    /* Set up UVP callback. */
    context->vbatUvpCbk = cb;

    /* Ensure that we are within the limits. */
    if (threshold < BAT_UVP_MIN_VOLT)
    {
        threshold = BAT_UVP_MIN_VOLT;
    }

    /* Connect output to divider */
    pd->amux_nhvn_ctrl |= ((uint32_t)1u << AMUX_NHVN_UV_BIT_5);
    pd->amux_ctrl &= ~((uint32_t)1u << AMUX_UV_BIT_8);
    pd->amux_ctrl &= ~((uint32_t)1u << AMUX_UV_BIT_9);

    /* Gain 10% */
    vref = (((threshold / 10) - BAT_REF_VOLT_MIN) / BAT_REF_VOLT_STEP);

    if (vref > BAT_VREF_MAX_SETTING)
    {
        vref = BAT_VREF_MAX_SETTING;
    }

    /* Program reference voltage for UV comparator. */
    regVal = pd->refgen_1_ctrl;
    regVal &= ~(PDSS_REFGEN_1_CTRL_SEL1_MASK);
    regVal |= (vref << PDSS_REFGEN_1_CTRL_SEL1_POS);
    pd->refgen_1_ctrl = regVal;

    /* Turn on comparator. */
    pd->comp_ctrl[CY_USBPD_VBUS_COMP_ID_VSRC_NEW_M] |= PDSS_COMP_CTRL_COMP_ISO_N;
    pd->comp_ctrl[CY_USBPD_VBUS_COMP_ID_VSRC_NEW_M] &= ~PDSS_COMP_CTRL_COMP_PD;

    Cy_SysLib_DelayUs(10);

    /* Filter configuration. */
    pd->intr7_filter_cfg[CY_USBPD_VBUS_FILTER_ID_UV] &= ~PDSS_INTR7_FILTER_CFG_FILT_EN;

    /* Set filter clock cycles if filter is required. */
    regVal = pd->intr7_filter_cfg[CY_USBPD_VBUS_FILTER_ID_UV] & ~(PDSS_INTR7_FILTER_CFG_FILT_CFG_MASK
            | PDSS_INTR7_FILTER_CFG_CLK_LF_FILT_SEL_MASK | PDSS_INTR7_FILTER_CFG_CLK_LF_FILT_BYPASS);
    regVal |= PDSS_INTR7_FILTER_CFG_CLK_LF_FILT_RESET;

    /* Set filter clock cycles if filter is required. */
    regVal |= (filterSel << PDSS_INTR7_FILTER_CFG_FILT_CFG_POS);

    /* Set edge detection. */
    regVal |= (CY_USBPD_VBUS_FILTER_CFG_POS_DIS_NEG_EN << PDSS_INTR7_FILTER_CFG_FILT_CFG_POS);
    regVal |= PDSS_INTR7_FILTER_CFG_FILT_EN;

    pd->intr7_filter_cfg[CY_USBPD_VBUS_FILTER_ID_UV] = regVal;

    /* Clear interrupt. */
    pd->intr7 = (1U << CY_USBPD_VBUS_FILTER_ID_UV);

    /* Enable Interrupt. */
    pd->intr7_mask |= (1U << CY_USBPD_VBUS_FILTER_ID_UV);
#else
    CY_UNUSED_PARAMETER(context);
    CY_UNUSED_PARAMETER(threshold);
    CY_UNUSED_PARAMETER(filterSel);
    (void)(cy_cb_vbus_fault_t)cb;
#endif /* (defined(CY_DEVICE_SERIES_PMG1B1)) */
}


/*******************************************************************************
* Function Name: Cy_USBPD_Fault_Vbat_UvpDisable
****************************************************************************//**
*
* Disable Under Voltage Protection (UVP) control.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \param pctrl
* Flag indicating the type of gate driver to be controlled, true for
* P_CTRL and false for C_CTRL.
*
*******************************************************************************/
void Cy_USBPD_Fault_Vbat_UvpDisable(cy_stc_usbpd_context_t *context, bool pctrl)
{
    CY_UNUSED_PARAMETER(pctrl);

#if (defined(CY_DEVICE_SERIES_PMG1B1))
    PPDSS_REGS_T pd = context->base;
    uint32_t state;

    state = Cy_SysLib_EnterCriticalSection ();

    /* Disable comparator. */
    pd->comp_ctrl[CY_USBPD_VBUS_COMP_ID_VSRC_NEW_M] &= ~PDSS_COMP_CTRL_COMP_ISO_N;
    pd->comp_ctrl[CY_USBPD_VBUS_COMP_ID_VSRC_NEW_M] |= PDSS_COMP_CTRL_COMP_PD;

    /* Disable filter. */
    pd->intr7_filter_cfg[CY_USBPD_VBUS_FILTER_ID_UV] &= ~(PDSS_INTR7_FILTER_CFG_FILT_EN |
            PDSS_INTR7_FILTER_CFG_FILT_CFG_MASK | PDSS_INTR7_FILTER_CFG_CLK_LF_FILT_SEL_MASK |
            PDSS_INTR7_FILTER_CFG_CLK_LF_FILT_BYPASS);

    /* Disable and clear UV interrupts. */
    pd->intr7_mask &= ~(1U << CY_USBPD_VBUS_FILTER_ID_UV);
    pd->intr7 = 1U << CY_USBPD_VBUS_FILTER_ID_UV;

    /* Clear callback. */
    context->vbatUvpCbk = NULL;

    Cy_SysLib_ExitCriticalSection (state);

#else
    CY_UNUSED_PARAMETER(context);
#endif /* (defined(CY_DEVICE_SERIES_PMG1B1)) */
}

/*******************************************************************************
* Function Name: Cy_USBPD_Fault_Vbat_UvpIntrHandler
****************************************************************************//**
*
* VBAT UVP fault interrupt handler function.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
*******************************************************************************/
void Cy_USBPD_Fault_Vbat_UvpIntrHandler(cy_stc_usbpd_context_t *context)
{

#if (defined(CY_DEVICE_SERIES_PMG1B1))
    PPDSS_REGS_T pd = context->base;

    /* Disable and clear UV interrupt. */
    pd->intr7_mask &= ~(1U << CY_USBPD_VBUS_FILTER_ID_UV);
    pd->intr7 = 1U << CY_USBPD_VBUS_FILTER_ID_UV;

    /* Invoke UVP callback. */
    if (context->vbatUvpCbk != NULL)
    {
        context->vbatUvpCbk(context, false);
    }
#else
    CY_UNUSED_PARAMETER(context);
#endif /* (defined(CY_DEVICE_SERIES_PMG1B1)) */
}

#if (!PDL_VBUS_OCP_ENABLE)

#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))

#define CCG_FLASH_ROW_SHIFT_NUM                 (8u)

/* Trims flag */
#define OCP_TRIM_ROOM_FLAG(port) (*(volatile uint8_t *)((0x0ffff45Du) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))

#define OCP_TRIM_1A_ROOM(port) (*(volatile uint8_t *)((0x0ffff456u) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))
#define OCP_TRIM_2A_ROOM(port) (*(volatile uint8_t *)((0x0ffff457u) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))
#define OCP_TRIM_3A_ROOM(port) (*(volatile uint8_t *)((0x0ffff458u) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))
#define OCP_TRIM_4A_ROOM(port) (*(volatile uint8_t *)((0x0ffff459u) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))
#define OCP_TRIM_5A_ROOM(port) (*(volatile uint8_t *)((0x0ffff45Au) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))

#define OCP_TRIM_1A_H(port) (*(volatile uint8_t *)((0x0ffff431u) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))
#define OCP_TRIM_2A_H(port) (*(volatile uint8_t *)((0x0ffff433u) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))
#define OCP_TRIM_3A_H(port) (*(volatile uint8_t *)((0x0ffff434u) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))
#define OCP_TRIM_4A_H(port) (*(volatile uint8_t *)((0x0ffff435u) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))
#define OCP_TRIM_5A_H(port) (*(volatile uint8_t *)((0x0ffff436u) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))

#define OCP_TRIM_1A_C(port) (*(volatile uint8_t *)((0x0ffff445u) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))
#define OCP_TRIM_2A_C(port) (*(volatile uint8_t *)((0x0ffff447u) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))
#define OCP_TRIM_3A_C(port) (*(volatile uint8_t *)((0x0ffff448u) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))
#define OCP_TRIM_4A_C(port) (*(volatile uint8_t *)((0x0ffff449u) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))
#define OCP_TRIM_5A_C(port) (*(volatile uint8_t *)((0x0ffff44Au) + \
        (((uint32_t)(port)) << (CCG_FLASH_ROW_SHIFT_NUM))))

#define I_1P3A      (130u)
#define I_2P6A      (260u)
#define I_3P9A      (390u)
#define I_5P2A      (520u)
#define I_6P5A      (650u)
#endif /* defined(CY_DEVICE_CCG7D) */
#endif /* PDL_VBUS_OCP_ENABLE */

/*******************************************************************************
* Function Name: Cy_USBPD_Fault_Vbat_OcpEnable
****************************************************************************//**
*
* Enable Battery Over Current Protection (OCP) control using the internal Current Sense Amplifier.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \param current
* Charging current in mA units.
*
* \param cb
* Callback function to be called on fault detection.
*
*******************************************************************************/
void Cy_USBPD_Fault_Vbat_OcpEnable(cy_stc_usbpd_context_t *context, uint32_t current, cy_cb_vbus_fault_t cb)
{
#if (defined(CY_DEVICE_SERIES_PMG1B1))
    PPDSS_REGS_T pd = context->base;
    uint32_t vsense = 0;
    uint32_t vrefSel = 0;
    uint32_t state = 0;
    uint32_t regval = 0;
    uint8_t gainSel = 0;
    uint8_t filterSel = 0;

    uint8_t ocp_trim_1A;
    uint8_t ocp_trim_2A;
    uint8_t ocp_trim_3A;
    uint8_t ocp_trim_4A;
    uint8_t ocp_trim_5A;
    int32_t vref_1;
    int32_t vref_2;
    int32_t vref_sel_signed_32;
    uint16_t cur_1;

    /* Never set current less than 900mA */
    if(current < 90u)
    {
        current = 90u;
    }

    /* Set up OCP callback. */
    context->vbatOcpCbk = cb;

    /* Calculate required current for OCP. */
    vsense = current + ((current * context->usbpdConfig->vbatOcpConfig->threshold) / 100u);

    /*
     * ** Silicon has room temperature trims.
     * Whereas,
     * *A silicon does not have room temperature trims.
     */
    if (OCP_TRIM_ROOM_FLAG(context->port) == 0u)
    {
        ocp_trim_1A = ((OCP_TRIM_1A_H(context->port) + OCP_TRIM_1A_C(context->port)) >> 1u);
        ocp_trim_2A = ((OCP_TRIM_2A_H(context->port) + OCP_TRIM_2A_C(context->port)) >> 1u);
        ocp_trim_3A = ((OCP_TRIM_3A_H(context->port) + OCP_TRIM_3A_C(context->port)) >> 1u);
        ocp_trim_4A = ((OCP_TRIM_4A_H(context->port) + OCP_TRIM_4A_C(context->port)) >> 1u);
        ocp_trim_5A = ((OCP_TRIM_5A_H(context->port) + OCP_TRIM_5A_C(context->port)) >> 1u);
    }
    else
    {
        ocp_trim_1A = OCP_TRIM_1A_ROOM(context->port);
        ocp_trim_2A = OCP_TRIM_2A_ROOM(context->port);
        ocp_trim_3A = OCP_TRIM_3A_ROOM(context->port);
        ocp_trim_4A = OCP_TRIM_4A_ROOM(context->port);
        ocp_trim_5A = OCP_TRIM_5A_ROOM(context->port);
    }

    /* vsense contains the current setting required in 10mA units. */
    /* Check if silicon has proper trims and then apply interpolation. */
    if((ocp_trim_1A != 0u) &&
       (ocp_trim_2A != 0u) &&
       (ocp_trim_3A != 0u) &&
       (ocp_trim_4A != 0u) &&
       (ocp_trim_5A != 0u))
    {
        /* Calculate current for the actual Rsense */
        vsense = ((vsense * context->vbusCsaRsense) / CSA_IDEAL_RSENSE);

        /* Trim values are with 30% OCP threshold */
        if(vsense >= I_5P2A)
        {
            vref_2 = (int32_t)ocp_trim_5A;
            vref_1 = (int32_t)ocp_trim_4A;
            cur_1 = I_5P2A;
        }
        else if(vsense >= I_3P9A)
        {
            vref_2 = (int32_t)ocp_trim_4A;
            vref_1 = (int32_t)ocp_trim_3A;
            cur_1 = I_3P9A;
        }
        else if(vsense >= I_2P6A)
        {
            vref_2 = (int32_t)ocp_trim_3A;
            vref_1 = (int32_t)ocp_trim_2A;
            cur_1 = I_2P6A;
        }
        else if(vsense >= I_1P3A)
        {
            vref_2 = (int32_t)ocp_trim_2A;
            vref_1 = (int32_t)ocp_trim_1A;
            cur_1 = I_1P3A;
        }
        else
        {
            /*
             * Since reference value is 130mV by default for value '0',
             * we need to consider corresponding negative reference
             * for 0A base current.
             */
            vref_2 = (int32_t)ocp_trim_1A;
            vref_1 = -13;
            cur_1 = 0;
        }

        /*
         * Calculate corrected reference with trim and rsense value.
         * Adjust for current in 10mA units.
         * Considering Ex: (2.6A - 1.3A) = 1.3A instead of 1A.
         */
        vref_sel_signed_32 = (vref_1 + (((vref_2 - vref_1) * ((int32_t)vsense - (int32_t)cur_1)) / 130));
        vrefSel = (uint8_t)vref_sel_signed_32;

        /*
         * CC trims will give refgen value directly including
         * 13 steps (130mV) offset. So, no need to adjust refgen offset.
         */
    }
    else
    {
        gainSel = OCP_GAIN_VALUE;
        Cy_USBPD_CSA_Calc_Ref(context, vsense, gainSel, &vrefSel, false);
    }

    filterSel = context->usbpdConfig->vbatOcpConfig->debounce;

    if(context->usbpdConfig->vbatOcpConfig->mode == VBUS_OCP_MODE_INT_AUTOCTRL)
    {
        filterSel = (uint8_t)system_get_clk_filt_sel(context->port, (((uint16_t)filterSel) * 10u));
    }

    context->ocpSwDbMs = filterSel;

    if(filterSel > 31)
    {
        filterSel = 31;
    }

    state = Cy_SysLib_EnterCriticalSection();

    if(context->usbpdConfig->vbatOcpConfig->mode == VBUS_OCP_MODE_INT_AUTOCTRL)
    {
        Cy_USBPD_Fault_FetAutoModeDisable(context, true, CY_USBPD_VBUS_FILTER_ID_CSA_OCP);
    }

    /* Gain for OCP is fixed. So CSA programming is not required. */
    /* Power up CSA block and enable output. */
    regval = pd->csa_scp_0_ctrl;
    regval &= ~PDSS_CSA_SCP_0_CTRL_PD_CSA;
    regval |= PDSS_CSA_SCP_0_CTRL_SEL_OUT_D | PDSS_CSA_SCP_0_CTRL_CSA_ISO_N;
    pd->csa_scp_0_ctrl = regval;

    /* Configure Reference for comparator. */
    regval = pd->refgen_2_ctrl;
    regval &= ~(PDSS_REFGEN_2_CTRL_SEL5_MASK);
    regval |= ((uint32_t)vrefSel << PDSS_REFGEN_2_CTRL_SEL5_POS);
    pd->refgen_2_ctrl = regval;

    regval = pd->refgen_2_ctrl;
    regval &= ~(PDSS_REFGEN_2_CTRL_SEL5_MASK);
    regval |= ((uint32_t)vrefSel << PDSS_REFGEN_2_CTRL_SEL5_POS);
    pd->refgen_2_ctrl = regval;

    /* Configuring the CSA output filter. */
    regval = pd->intr13_cfg_csa_scp_hs;
    regval &= ~(PDSS_INTR13_CFG_CSA_SCP_HS_CSA_OCP_FILT_EN |
            PDSS_INTR13_CFG_CSA_SCP_HS_CSA_OCP_FILT_CFG_MASK |
            PDSS_INTR13_CFG_CSA_SCP_HS_CSA_OCP_FILT_SEL_MASK |
            PDSS_INTR13_CFG_CSA_SCP_HS_CSA_OCP_FILT_RESET |
            PDSS_INTR13_CFG_CSA_SCP_HS_CSA_OCP_FILT_BYPASS);
    pd->intr13_cfg_csa_scp_hs = regval;

    /* Configure the filter based on debounce parameter from config table. */
    regval |= ((uint8_t)CY_USBPD_VBUS_FILTER_CFG_POS_EN_NEG_DIS << PDSS_INTR13_CFG_CSA_SCP_HS_CSA_OCP_FILT_CFG_POS) |
        (filterSel << PDSS_INTR13_CFG_CSA_SCP_HS_CSA_OCP_FILT_SEL_POS) |
        PDSS_INTR13_CFG_CSA_SCP_HS_CSA_OCP_FILT_EN |
        PDSS_INTR13_CFG_CSA_SCP_HS_CSA_OCP_DPSLP_MODE;
    pd->intr13_cfg_csa_scp_hs = regval;

    /* Clear and enable the OC detect interrupt. */
    pd->intr13 = PDSS_INTR13_CSA_OCP_CHANGED;
    pd->intr13_mask |= PDSS_INTR13_MASK_CSA_OCP_CHANGED_MASK;

    if (context->usbpdConfig->vbatOcpConfig->mode == VBUS_OCP_MODE_INT_AUTOCTRL)
    {
         Cy_USBPD_Fault_FetAutoModeEnable(context, true, CY_USBPD_VBUS_FILTER_ID_CSA_OCP);
    }

    Cy_SysLib_ExitCriticalSection(state);
#else
    CY_UNUSED_PARAMETER(context);
    CY_UNUSED_PARAMETER(current);
    (void)(cy_cb_vbus_fault_t)cb;
#endif /* (defined(CY_DEVICE_SERIES_PMG1B1)) */
}

/*******************************************************************************
* Function Name: Cy_USBPD_Fault_Vbat_OcpDisable
****************************************************************************//**
*
* Disables the Battery Over Current Protection (OCP)
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \param pctrl
* Flag indicating the type of gate driver to be controlled, true for
* P_CTRL and false for C_CTRL.
*
* \return
* None
*
*******************************************************************************/
void Cy_USBPD_Fault_Vbat_OcpDisable(cy_stc_usbpd_context_t *context, bool pctrl)
{
#if (defined(CY_DEVICE_SERIES_PMG1B1))

    PPDSS_REGS_T pd = context->base;
    uint32_t state;

    state = Cy_SysLib_EnterCriticalSection();

    /* Deregister the callback. */
    context->vbatOcpCbk = NULL;

    uint32_t regval;

    /* Clear reference. */
    pd->refgen_2_ctrl &= ~(PDSS_REFGEN_2_CTRL_SEL5_MASK);

    /* Disable and clear interrupts. */
    pd->intr13_mask &= ~(PDSS_INTR13_CSA_OCP_CHANGED);
    pd->intr13 = PDSS_INTR13_CSA_OCP_CHANGED;

    /* Disable the filter. */
    regval = pd->intr13_cfg_csa_scp_hs;
    regval &= ~(PDSS_INTR13_CFG_CSA_SCP_HS_CSA_OCP_FILT_EN |
            PDSS_INTR13_CFG_CSA_SCP_HS_CSA_OCP_FILT_CFG_MASK |
            PDSS_INTR13_CFG_CSA_SCP_HS_CSA_OCP_FILT_SEL_MASK |
            PDSS_INTR13_CFG_CSA_SCP_HS_CSA_OCP_FILT_RESET |
            PDSS_INTR13_CFG_CSA_SCP_HS_CSA_OCP_FILT_BYPASS);
    pd->intr13_cfg_csa_scp_hs = regval;

    if(context->usbpdConfig->vbatOcpConfig->mode == VBUS_OCP_MODE_INT_AUTOCTRL)
    {
        Cy_USBPD_Fault_FetAutoModeDisable(context, pctrl, CY_USBPD_VBUS_FILTER_ID_CSA_OCP);
    }

    if (context->usbpdConfig->vbatOcpConfig->mode == VBUS_OCP_MODE_INT_SW_DB)
    {
        /* Make sure any debounce timer is stopped. */
        context->timerStopcbk(context, CY_USBPD_PD_OCP_DEBOUNCE_TIMER);
    }

    Cy_SysLib_ExitCriticalSection (state);
#else
    CY_UNUSED_PARAMETER(context);
    CY_UNUSED_PARAMETER(pctrl);
#endif /* (defined(CY_DEVICE_SERIES_PMG1B1)) */
}

#if (defined(CY_DEVICE_SERIES_PMG1B1))
/*******************************************************************************
* Function Name: Cy_USBPD_BatOcpHandlerWrapper
****************************************************************************//**
*
* VBAT OCP Wrapper function.
*
* \param id
* Timer id
*
* \param callbackContext
* Pointer to usbpd_context structure.
*
* \return
* None
*
*******************************************************************************/
static void Cy_USBPD_BatOcpHandlerWrapper(uint16_t id, void *callbackContext)
{
#if (defined(CY_DEVICE_SERIES_PMG1B1))
    cy_stc_usbpd_context_t *context=callbackContext;
     /* OCP debounced. Invoke callback. */
    context->vbatOcpCbk(context, true);
#else
    CY_UNUSED_PARAMETER(callbackContext);
#endif /* (defined(CY_DEVICE_SERIES_PMG1B1)) */
    CY_UNUSED_PARAMETER(id);
}
#endif /* (defined(CY_DEVICE_SERIES_PMG1B1)) */

/*******************************************************************************
* Function Name: Cy_USBPD_Fault_Vbat_OcpIntrHandler
****************************************************************************//**
*
* VBAT OCP fault interrupt handler function.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \return
* None
*
*******************************************************************************/
void Cy_USBPD_Fault_Vbat_OcpIntrHandler(cy_stc_usbpd_context_t *context)
{
#if (defined(CY_DEVICE_SERIES_PMG1B1))
    PPDSS_REGS_T pd = context->base;
    if ((pd->intr13_masked & (PDSS_INTR13_MASKED_CSA_OCP_CHANGED_MASKED)) != 0u)
    {
        /* Clear the active interrupt. */
        pd->intr13 = PDSS_INTR13_CSA_OCP_CHANGED;

        /* If positive edge interrupt. */
        if (((pd->intr13_cfg_csa_scp_hs & PDSS_INTR13_CFG_CSA_SCP_HS_CSA_OCP_FILT_CFG_MASK) >>
            PDSS_INTR13_CFG_CSA_SCP_HS_CSA_OCP_FILT_CFG_POS) == (uint32_t)CY_USBPD_VBUS_FILTER_CFG_POS_EN_NEG_DIS)
        {
            /* If No software debounce mode. */
            if ((context->usbpdConfig->vbatOcpConfig->mode == VBUS_OCP_MODE_INT) ||
                (context->usbpdConfig->vbatOcpConfig->mode == VBUS_OCP_MODE_INT_AUTOCTRL))
            {
                /* Invoke the callback. */
                (void)context->vbatOcpCbk(context,true);
            }
            /* If software debounce mode. */
            else if (context->usbpdConfig->vbatOcpConfig->mode == VBUS_OCP_MODE_INT_SW_DB)
            {
                uint32_t regval2;
                /*
                 * Look for negative edge of comparator. NOTE: Here we are using filter
                 * reset mechanism to simulate edge if the comparator status has already gone low.
                 * This assumes that the OCP comparator filter is being used during enable.
                 */
                pd->intr13_cfg_csa_scp_hs &= ~PDSS_INTR13_CFG_CSA_SCP_HS_CSA_OCP_FILT_EN;
                regval2 = pd->intr13_cfg_csa_scp_hs;
                regval2 &= ~(PDSS_INTR13_CFG_CSA_SCP_HS_CSA_OCP_FILT_CFG_MASK);
                regval2 |= (uint8_t)CY_USBPD_VBUS_FILTER_CFG_POS_DIS_NEG_EN << PDSS_INTR13_CFG_CSA_SCP_HS_CSA_OCP_FILT_CFG_POS;
                regval2 |= (PDSS_INTR13_CFG_CSA_SCP_HS_CSA_OCP_FILT_RESET | PDSS_INTR13_CFG_CSA_SCP_HS_CSA_OCP_FILT_EN);
                pd->intr13_cfg_csa_scp_hs = regval2;

                /* Start the debounce timer. */
                context->timerStartcbk(context, context, CY_USBPD_PD_OCP_DEBOUNCE_TIMER, context->ocpSwDbMs, Cy_USBPD_BatOcpHandlerWrapper);
            }
            else
            {
                /* Do nothing */
            }
        }
        /* If negative edge interrupt. */
        else
        {
            if (context->timerIsRunningcbk(context, CY_USBPD_PD_OCP_DEBOUNCE_TIMER))
            {
                uint32_t regval1;
                /* Stop the debounce timer. */
                context->timerStopcbk(context, CY_USBPD_PD_OCP_DEBOUNCE_TIMER);

                /*
                 * Look for positive edge of comparator. NOTE: Here we are using filter
                 * reset mechanism to simulate edge if the comparator status has already gone low.
                 * This assumes that the OCP comparator filter is being used during enable.
                 */
                pd->intr13_cfg_csa_scp_hs &= ~PDSS_INTR13_CFG_CSA_SCP_HS_CSA_OCP_FILT_EN;
                regval1 = pd->intr13_cfg_csa_scp_hs;
                regval1 &= ~(PDSS_INTR13_CFG_CSA_SCP_HS_CSA_OCP_FILT_CFG_MASK | PDSS_INTR13_CFG_CSA_SCP_HS_CSA_OCP_FILT_RESET);
                regval1 |= (uint8_t)CY_USBPD_VBUS_FILTER_CFG_POS_EN_NEG_DIS << PDSS_INTR13_CFG_CSA_SCP_HS_CSA_OCP_FILT_CFG_POS;
                regval1 |= (PDSS_INTR13_CFG_CSA_SCP_HS_CSA_OCP_FILT_EN);
                pd->intr13_cfg_csa_scp_hs = regval1;
            }
            else
            {
                /* Disable the interrupt as we are no longer interested in it. */
                pd->intr13_mask &= ~PDSS_INTR13_CSA_OCP_CHANGED;
            }
        }
    }
#else
    CY_UNUSED_PARAMETER(context);
#endif /* (defined(CY_DEVICE_SERIES_PMG1B1)) */
}

/*******************************************************************************
* Function Name: Cy_USBPD_Fault_Voutbb_RcpEnable
****************************************************************************//**
*
* Enables the detection of Buck-boost Vout RCP Fault.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \param cb
* Callback function to be called on fault detection.
*
* \return
* None
*
*******************************************************************************/
void Cy_USBPD_Fault_Voutbb_RcpEnable(cy_stc_usbpd_context_t *context, cy_cb_vbus_fault_t cb)
{
#if (PDL_VOUTBB_RCP_ENABLE && (defined(CY_DEVICE_SERIES_PMG1B1)))
    PPDSS_REGS_T pd;
    uint32_t state;
    pd = context->base;

    state = Cy_SysLib_EnterCriticalSection();

    /* Set up RCP callback. */
    context->voutRcpCbk = cb;

    /* Clear and enable Buck-boost Vout RCP detect interrupt. */
    pd->intr17 = PDSS_INTR17_PDBB_GDRVO_HSRCP;
    pd->intr17_mask |= PDSS_INTR17_MASK_PDBB_GDRVO_HSRCP_MASK;
    
    Cy_SysLib_ExitCriticalSection(state);
#else /* !PDL_VOUTBB_RCP_ENABLE */
    CY_UNUSED_PARAMETER(context);
    (void)(cy_cb_vbus_fault_t)cb;
#endif /* (PDL_VOUTBB_RCP_ENABLE && (defined(CY_DEVICE_SERIES_PMG1B1)) */
}

/*******************************************************************************
* Function Name: Cy_USBPD_Fault_Voutbb_RcpDisable
****************************************************************************//**
*
* Disables the detection of Buck-boost Vout RCP Fault.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
*
* \return
* None
*
*******************************************************************************/
void Cy_USBPD_Fault_Voutbb_RcpDisable(cy_stc_usbpd_context_t *context)
{
#if (PDL_VOUTBB_RCP_ENABLE && (defined(CY_DEVICE_SERIES_PMG1B1)))
    PPDSS_REGS_T pd;
    uint32_t state;
    pd = context->base;

    state = Cy_SysLib_EnterCriticalSection();

    /* Disable and Clear the interrupt. */
    pd->intr17_mask &= ~PDSS_INTR17_MASK_PDBB_GDRVO_HSRCP_MASK;
    pd->intr17 |= PDSS_INTR17_PDBB_GDRVO_HSRCP;

    /* Clear the stored configuration. */
    context->voutRcpCbk = NULL;

    Cy_SysLib_ExitCriticalSection(state);
#else /* !PDL_VOUTBB_RCP_ENABLE */
    CY_UNUSED_PARAMETER(context);
#endif /* (PDL_VOUTBB_RCP_ENABLE && (defined(CY_DEVICE_SERIES_PMG1B1)) */
}

#endif /* (defined(CY_IP_MXUSBPD) || defined(CY_IP_M0S8USBPD)) */

/* [] END OF FILE */
