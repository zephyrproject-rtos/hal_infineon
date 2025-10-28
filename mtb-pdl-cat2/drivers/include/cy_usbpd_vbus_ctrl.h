/***************************************************************************//**
* \file cy_usbpd_vbus_ctrl.h
* \version 2.110
*
* Provides API declarations of the USBPD VBUS Control driver.
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
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/
#ifndef _CY_USBPD_VBUS_CTRL_H_
#define _CY_USBPD_VBUS_CTRL_H_

#include "cy_usbpd_common.h"

/**
* \addtogroup group_usbpd_vbus_ctrl
* \{
* USBPD VBus Control driver.
*
* \defgroup group_usbpd_vbus_ctrl_enums Enumerated Types
* \defgroup group_usbpd_vbus_ctrl_functions Functions
*/

#if (defined(CY_IP_MXUSBPD) || defined(CY_IP_M0S8USBPD))


#if CY_USE_CONFIG_TABLE
    /** VBUS OVP TABLE */
    #define GET_VBUS_OVP_TABLE(x) pd_get_ptr_ovp_tbl(x)
    /** VBUS OCP TABLE */
    #define GET_VBUS_OCP_TABLE(x) pd_get_ptr_ocp_tbl(x)
    /** VBUS RCP TABLE */
    #define GET_VBUS_RCP_TABLE(x) pd_get_ptr_rcp_tbl(x)
    /** VBUS UVP TABLE */
    #define GET_VBUS_UVP_TABLE(x) pd_get_ptr_uvp_tbl(x)
    /** VCONN OCP TABLE */
    #define GET_VCONN_OCP_TABLE(x) pd_get_ptr_vconn_ocp_tbl(x)
    /** VBUS SCP TABLE */
    #define GET_VBUS_SCP_TABLE(x) pd_get_ptr_scp_tbl(x)
#else
    /** VBUS OVP TABLE */
    #define GET_VBUS_OVP_TABLE(x) (((cy_stc_usbpd_context_t *)x)->usbpdConfig->vbusOvpConfig)
    /** VBUS OCP TABLE */
    #define GET_VBUS_OCP_TABLE(x) (((cy_stc_usbpd_context_t *)x)->usbpdConfig->vbusOcpConfig)
    /** VBUS RCP TABLE */
    #define GET_VBUS_RCP_TABLE(x) (((cy_stc_usbpd_context_t *)x)->usbpdConfig->vbusRcpConfig)
    /** VBUS UVP TABLE */
    #define GET_VBUS_UVP_TABLE(x) (((cy_stc_usbpd_context_t *)x)->usbpdConfig->vbusUvpConfig)
    /** VCONN OCP TABLE */
    #define GET_VCONN_OCP_TABLE(x) (((cy_stc_usbpd_context_t *)x)->usbpdConfig->vconnOcpConfig)
    /** VBUS SCP TABLE */
    #define GET_VBUS_SCP_TABLE(x) (((cy_stc_usbpd_context_t *)x)->usbpdConfig->vbusScpConfig)
#endif /* CY_USE_CONFIG_TABLE */

/** Default reference voltage on M0S8-USBPD IP. */
#define PD_ADC_DEFAULT_VDDD_VOLT_MV             (3300u)

#if defined(CY_DEVICE_CCG6DF_CFP)
/** Reference voltage in CCG6DF_CFP is 2.2 V */
#define MX_PD_ADC_REF_VOLT_MV                   (2200u)
#else
/** Reference voltage in MX_PD IP (2.0 V) */
#define MX_PD_ADC_REF_VOLT_MV                   (2000u)
#endif /* defined(CY_DEVICE_CCG6DF_CFP) */

/** Bandgap voltage in millivolt. */
#define PD_ADC_BAND_GAP_VOLT_MV                 (1200u)

/** Maximum ADC count. */
#define PD_ADC_MAX_VALUE                        (0xFFu)

/** Number of ADC levels. */
#define PD_ADC_NUM_LEVELS                       (PD_ADC_MAX_VALUE + 1u)

/**
 * The minimum comparator output shall be limited to this value to guard
 * against ground bounce and other ADC noise.
 */
#define PD_ADC_LEVEL_MIN_THRESHOLD              (4u)

/**
 * The maximum comparator output shall be limited to this value to guard
 * against max level.
 */
#define PD_ADC_LEVEL_MAX_THRESHOLD              (254u)

/** Loop timeout count for ADC. */
#define PD_ADC_TIMEOUT_COUNT                    (200UL)

/** VBus current usage = 0.9 A. */
#define CY_USBPD_I_0P9A                         (90u)

/** VBus current usage = 1.0 A. */
#define CY_USBPD_I_1A                           (100u)

/** VBus current usage = 2.0 A. */
#define CY_USBPD_I_2A                           (200u)

/** VBus current usage = 3.0 A. */
#define CY_USBPD_I_3A                           (300u)

/** VBus current usage = 4.0 A. */
#define CY_USBPD_I_4A                           (400u)

/** VBus current usage = 5.0 A. */
#define CY_USBPD_I_5A                           (500u)

/** Multiplied by 2. */
#define VBUS_MON_DIV_20P_VAL                    (10u)

/** Multiplied by 2. */
#define VBUS_MON_DIV_10P_VAL                    (20u)

/** Multiplied by 2. */
#define VBUS_MON_DIV_9P_VAL                     (22u)

/** Multiplied by 2. */
#define VBUS_MON_DIV_8P_VAL                     (25u)

/** Multiplied by 2. */
#define VBUS_MON_DIV_6P_VAL                     (33u)

/** Multiplied by 2. */
#define VBUS_MON_DIV_5P_VAL                     (40u)

/** Multiplied by 2. */
#define VBAT_MON_DIV_8P_VAL                     (25u)

/** Maximum voltage in mV that can be measured with 20% divider. */
#define VBUS_DIV_20_PER_MAX_VOLT                (9000U)

/** Ideal Rsense value in 0.1mOhm units */
#define CSA_IDEAL_RSENSE                         (50u)

/**
 * The macro holds the VBUS change per change in iDAC setting. This voltage assumes
 * that the feedback divider resistance (R1) is 200KOhms. It needs to be 200KOhm
 * for supporting PPS operation. This value is used in signed number operation
 * and should be left as signed.
 * This value should not be changed. The iDAC sink has 1024 steps of 20mV and iDAC
 * source has 128 steps of 20mV. No bound checks are added as extreme values are
 * outside operating condition.
 */
#define VBUS_CHANGE_PER_DAC_BIT             (20)

#if defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)
/* Fixed Gain settings */
#define CC_GAIN_VALUE                           (80u)
#define OCP_GAIN_VALUE                          (40u)
#define SCP_GAIN_VALUE                          (20u)
#define CSA_GAIN_VALUE_LOW                      (40u)
#define CSA_GAIN_VALUE_HIGH                     (150u)

/* CCG7D VOUT_MON and VOUT_CBL gain options mask */
#define CSA_VOUT_MON_CBL_GAIN_OPTIONS_MASK      (3u)

/* CCG7D VOUT_MON and VOUT_CBL gain selection */
#define CSA_VOUT_MON_CBL_GAIN_OPTIONS_70_150    (0u)
#define CSA_VOUT_MON_CBL_GAIN_OPTIONS_40_150    (1u)
#define CSA_VOUT_MON_CBL_GAIN_OPTIONS_70_200    (2u)
#define CSA_VOUT_MON_CBL_GAIN_OPTIONS_40_200    (3u)

/* CCG7D VOUT_MON gain mask */
#define CSA_VOUT_MON_GAIN_MASK                  ((uint32_t)1u << 7u)

/* CCG7D VOUT_MON gain selection */
#define CSA_VOUT_MON_GAIN_SEL_LOW               ((uint32_t)0u << 7u)
#define CSA_VOUT_MON_GAIN_SEL_HIGH              ((uint32_t)1u << 7u)

/* CCG7D VOUT_CBL gain mask */
#define CSA_VOUT_CBL_GAIN_MASK                  ((uint32_t)1u << 6u)

/* CCG7D VOUT_CBL gain selection */
#define CSA_VOUT_CBL_GAIN_SEL_LOW               ((uint32_t)0u << 6u)
#define CSA_VOUT_CBL_GAIN_SEL_HIGH              ((uint32_t)1u << 6u)

#if (VBUS_CTRL_TRIM_ADJUST_ENABLE)

#if !PSVP_FPGA_ENABLE
/** Hardware register address information. Should not be modified. **/

/* Sink DAC trim - 5V */
#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
#define BG_ISNK_DAC_CTRL_0_5V(port) (*(volatile uint8_t *)((0x0ffff461u) + \
        (((uint32_t)port) << (CCG_FLASH_ROW_SHIFT_NUM))))
#define BG_ISNK_DAC_CTRL_1_5V(port) (*(volatile uint8_t *)((0x0ffff460u) + \
        (((uint32_t)port) << (CCG_FLASH_ROW_SHIFT_NUM))))
#else /* !(defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) */
#define BG_ISNK_DAC_CTRL_0_5V(port) (*(volatile uint8_t *)(0x0FFFF28Eu))
#define BG_ISNK_DAC_CTRL_1_5V(port) (*(volatile uint8_t *)(0x0FFFF28Fu))
#endif /* !(defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) */
#define BG_ISNK_DAC_CTRL_COMBINED_5V(port) (BG_ISNK_DAC_CTRL_0_5V(port) | \
        ((uint32_t)BG_ISNK_DAC_CTRL_1_5V(port) << 8))

/* Sink DAC trim - 20V */
#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1))
#define BG_ISNK_DAC_CTRL_0_20V(port) (*(volatile uint8_t *)((0x0ffff464u) + \
        (((uint32_t)port) << (CCG_FLASH_ROW_SHIFT_NUM))))
#define BG_ISNK_DAC_CTRL_1_20V(port) (*(volatile uint8_t *)((0x0ffff463u) + \
        (((uint32_t)port) << (CCG_FLASH_ROW_SHIFT_NUM))))
#else /* !(defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) */
#define BG_ISNK_DAC_CTRL_0_20V(port) (*(volatile uint8_t *)(0x0FFFF291u))
#define BG_ISNK_DAC_CTRL_1_20V(port) (*(volatile uint8_t *)(0x0FFFF292u))
#endif /* !(defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1)) */
#define BG_ISNK_DAC_CTRL_COMBINED_20V(port) (BG_ISNK_DAC_CTRL_0_20V(port) | \
        ((uint32_t)BG_ISNK_DAC_CTRL_1_20V(port) << 8))

/* Source DAC trim - 3V */
#define BG_ISRC_DAC_CTRL_0_3V(port)  (*(volatile uint8_t *)((0x0ffff46Eu) + \
        (((uint32_t)port) << (CCG_FLASH_ROW_SHIFT_NUM))))
/* Source DAC trim - 5V */
#define BG_ISRC_DAC_CTRL_0_5V(port)  (*(volatile uint8_t *)((0x0ffff462u) + \
        (((uint32_t)port) << (CCG_FLASH_ROW_SHIFT_NUM))))
/* Source DAC trim - 20V */
#define BG_ISRC_DAC_CTRL_0_20V(port) (*(volatile uint8_t *)((0x0ffff465u) + \
        (((uint32_t)port) << (CCG_FLASH_ROW_SHIFT_NUM))))
#else /* PSVP_FPGA_ENABLE */
/* Source DAC trim - 3V */
#define BG_ISRC_DAC_CTRL_0_3V(port)  (*(volatile uint8_t *)(0x0FFFF2A6u))
/* Source DAC trim - 5V */
#define BG_ISRC_DAC_CTRL_0_5V(port)  (*(volatile uint8_t *)(0x0FFFF290u))
/* Source DAC trim - 20V */
#define BG_ISRC_DAC_CTRL_0_20V(port) (*(volatile uint8_t *)(0x0FFFF293u))

#endif /* PSVP_FPGA_ENABLE */
#endif /* (VBUS_CTRL_TRIM_ADJUST_ENABLE) */
#endif /* defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_SERIES_WLC1) */

#if defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S)
#define CYDEV_BCLK__HFCLK__MHZ                    (48U)
/**<HF Clock in MHz. */

#define SFLASH_VBE_LOW_TEMP_TRIM_ADDR            (0x0FFFF479)
/**< Low temperature VBJT code sflash address. */

#define SFLASH_VBE_HIGH_TEMP_TRIM_ADDR           (0x0FFFF478)
/**< High temperature VBJT code sflash address. */

#define SFLASH_VBE_25_C_TEMP_TRIM_ADDR           (0x0FFFF47A)
/**< 25C temperature VBJT code sflash address. */

#define INTERNAL_BJT_LOW_TEMP                    (-40)
/**< Low temperature which corresponds to low temperature VBJT code stored in sflash (in Celsius degrees) */

#define INTERNAL_BJT_HIGH_TEMP                   (120u)
/**< High temperature which corresponds to high temperature VBJT code stored in sflash (in Celsius degrees) */

#define INTERNAL_BJT_ROOM_TEMP                   (25)
/**< Room temperature used for VBJT code stored in sflash (in Celsius degrees) */

#define VBJT_LSB_TEMP_DELTA                      (5u)
/**< Approximate temperature change for each LSB change in VBJT ADC reading. */

#define INTERNAL_BJT_FAULT_TEMP                               (255)
/**< Fault temperature value returned when sflash VBJT code is not correct (in Celsius degrees) */
#endif /* defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) */

/*******************************************************************************
*                            Enumerated Types
*******************************************************************************/

/**
* \addtogroup group_usbpd_vbus_ctrl_enums
* \{
*/
/** List of RefGen Outputs **/
typedef enum
{
    CY_USBPD_VREF_VBUS_UV = 2,              /**< Vref used for UVP on PMG1S1. */
    CY_USBPD_VREF_VBUS_OV = 3,              /**< Vref used for OVP on PMG1S1. */
    CY_USBPD_VREF_CSA_OCP = 5,              /**< Vref used for CSA OCP on PMG1S1. */
    CY_USBPD_VREF_CSA_SCP = 7,              /**< Vref used for CSA SCP on PMG1S1. */
    CY_USBPD_VREF_RCP_CSA = 8,              /**< Vref used for Reverse current sensing on PMG1S1. */
    CY_USBPD_VREF_RCP_OVP = 10              /**< Vref used for RCP based on VBus over-voltage on PMG1S1. */
} cy_en_usbpd_refgen_op_t;

/** \} group_usbpd_vbus_ctrl_enums */

/*******************************************************************************
*                            Function Prototypes
*******************************************************************************/

/**
* \addtogroup group_usbpd_vbus_ctrl_functions
* \{
*/

cy_en_usbpd_status_t Cy_USBPD_Adc_Init(cy_stc_usbpd_context_t *context, cy_en_usbpd_adc_id_t adcId);

uint8_t Cy_USBPD_Adc_VoltToLevel(cy_stc_usbpd_context_t *context, cy_en_usbpd_adc_id_t adcId, uint16_t volt);

uint16_t Cy_USBPD_Adc_LevelToVolt(cy_stc_usbpd_context_t *context, cy_en_usbpd_adc_id_t adcId, uint8_t level);

uint16_t Cy_USBPD_Adc_GetVbusVolt(cy_stc_usbpd_context_t *context, cy_en_usbpd_adc_id_t adcId, uint8_t level);

cy_en_usbpd_status_t  Cy_USBPD_Adc_FreeRunCtrl(cy_stc_usbpd_context_t *context, cy_en_usbpd_adc_id_t adcId, 
                                            cy_en_usbpd_adc_input_t input, uint8_t level);

void Cy_USBPD_Adc_CompCtrl(cy_stc_usbpd_context_t *context, cy_en_usbpd_adc_id_t adcId, cy_en_usbpd_adc_input_t input,
                            uint8_t level, cy_en_usbpd_adc_int_t intCfg, cy_cb_adc_events_t cb);
                            
bool Cy_USBPD_Adc_CompSample(cy_stc_usbpd_context_t *context, cy_en_usbpd_adc_id_t adcId, cy_en_usbpd_adc_input_t input, uint8_t level);

bool Cy_USBPD_Adc_GetCompStatus(cy_stc_usbpd_context_t *context, cy_en_usbpd_adc_id_t adcId);

uint8_t Cy_USBPD_Adc_Sample(cy_stc_usbpd_context_t *context, cy_en_usbpd_adc_id_t adcId, cy_en_usbpd_adc_input_t input);

uint8_t Cy_USBPD_Adc_SampleInput(cy_stc_usbpd_context_t *context, cy_en_usbpd_adc_id_t adcId, cy_en_usbpd_adc_input_t input, 
        uint32_t amux_nhv_ctrl_clr, uint32_t amux_nhv_ctrl_set, cy_en_usbpd_adc_vref_t adc_vref);

uint16_t Cy_USBPD_Adc_Calibrate(cy_stc_usbpd_context_t *context, cy_en_usbpd_adc_id_t adcId);

cy_en_usbpd_status_t Cy_USBPD_Adc_SelectVref(cy_stc_usbpd_context_t *context, cy_en_usbpd_adc_id_t adcId, cy_en_usbpd_adc_vref_t vrefSel);

uint8_t Cy_USBPD_Adc_GetVbusLevel(cy_stc_usbpd_context_t *context, cy_en_usbpd_adc_id_t adcId, uint16_t volt, int8_t per);

int16_t Cy_USBPD_Adc_MeasureInternalTemp(cy_stc_usbpd_context_t *context, cy_en_usbpd_adc_id_t adcId,
                                    cy_en_usbpd_adc_input_t input);

uint16_t Cy_USBPD_Adc_MeasureVbusIn(cy_stc_usbpd_context_t *context, cy_en_usbpd_adc_id_t adcId,
                                  cy_en_usbpd_adc_input_t input);

uint16_t Cy_USBPD_Adc_MeasureVbus(cy_stc_usbpd_context_t *context, cy_en_usbpd_adc_id_t adcId,
                                  cy_en_usbpd_adc_input_t input);
                                

void Cy_USBPD_Vbus_SetDetachParams(cy_stc_usbpd_context_t *context, cy_en_usbpd_adc_id_t adcId, cy_en_usbpd_adc_input_t adcInp);

void Cy_USBPD_Adc_IntrHandler(cy_stc_usbpd_context_t *context);

/** \} group_usbpd_vbus_ctrl_functions */


/**
* \addtogroup group_usbpd_vbus_ctrl_functions
* \{
*/

bool Cy_USBPD_V5V_IsSupplyOn(cy_stc_usbpd_context_t *context);

cy_en_usbpd_status_t Cy_USBPD_Vconn_Enable(cy_stc_usbpd_context_t *context, uint8_t channel);

cy_en_usbpd_status_t Cy_USBPD_Vconn_Disable(cy_stc_usbpd_context_t *context, uint8_t channel);

void Cy_USBPD_Vconn_GatePullUp_Enable(cy_stc_usbpd_context_t *context);

bool Cy_USBPD_Vconn_IsPresent(cy_stc_usbpd_context_t *context, uint8_t channel);

bool Cy_USBPD_VbusDiv_To_AMuxDiscon(cy_stc_usbpd_context_t *context);

bool Cy_USBPD_Vbus_FrsRxEnable(cy_stc_usbpd_context_t *context);

bool Cy_USBPD_Vbus_FrsRxDisable(cy_stc_usbpd_context_t *context);

void Cy_USBPD_Vbus_FrsRx_IntrHandler(cy_stc_usbpd_context_t *context);

bool Cy_USBPD_Vbus_FrsTxEnable(cy_stc_usbpd_context_t *context);

bool Cy_USBPD_Vbus_FrsTxDisable(cy_stc_usbpd_context_t *context);

void Cy_USBPD_Vbus_GdrvRstEdgeDet(cy_stc_usbpd_context_t *context, bool pgdoType);

void Cy_USBPD_Vbus_RemoveIntrnlFbDiv(cy_stc_usbpd_context_t *context);

bool Cy_USBPD_Vbus_GdrvIsSnkFetOn(cy_stc_usbpd_context_t *context);

uint16_t Cy_USBPD_Adc_GetVbatVolt(cy_stc_usbpd_context_t *context, cy_en_usbpd_adc_id_t adcId,
                                  uint8_t level);
                                  
uint16_t Cy_USBPD_MeasureVbat(cy_stc_usbpd_context_t *context);

void Cy_USBPD_PfetDynDsEnable(cy_stc_usbpd_context_t *context);

void Cy_USBPD_Vbus_GdrvPfetOn(cy_stc_usbpd_context_t *context, bool turnOnSeq);

void Cy_USBPD_Vbus_GdrvPfetOff(cy_stc_usbpd_context_t *context, bool turnOffSeq);

void Cy_USBPD_Vbus_GdrvCfetOn(cy_stc_usbpd_context_t *context, bool turnOnSeq);

void Cy_USBPD_Vbus_GdrvCfetOff(cy_stc_usbpd_context_t *context, bool turnOffSeq);

void Cy_USBPD_Vbus_NgdoOn(cy_stc_usbpd_context_t *context, bool pfet);

void Cy_USBPD_Vbus_NgdoSetDriveStrength(cy_stc_usbpd_context_t *context, uint8_t value);

void Cy_USBPD_Vbus_NgdoOff(cy_stc_usbpd_context_t *context, bool pfet);

void Cy_USBPD_Vbus_DischargeOn(cy_stc_usbpd_context_t *context);

void Cy_USBPD_Vbus_DischargeOff(cy_stc_usbpd_context_t *context);

void Cy_USBPD_VbusIn_DischargeOn(cy_stc_usbpd_context_t *context);

void Cy_USBPD_VbusIn_DischargeOff(cy_stc_usbpd_context_t *context);

/** \cond DOXYGEN_HIDE */
void Cy_USBPD_Vbus_LoadChangeISR_En(cy_stc_usbpd_context_t *context, uint32_t cur, 
                                   uint8_t filter, cy_cb_usbpd_vbus_load_chg_t cbk);
/** \endcond */

uint16_t Cy_USBPD_Vbus_MeasureCur(cy_stc_usbpd_context_t *context);

void Cy_USBPD_Vbus_NgdoG1Ctrl(cy_stc_usbpd_context_t *context, bool value);

void Cy_USBPD_Vbus_NgdoEqCtrl(cy_stc_usbpd_context_t *context, bool value);

void Cy_USBPD_Vbus_HalCleanup(cy_stc_usbpd_context_t *context);

void Cy_USBPD_Vbus_Mon_SetDivider(cy_stc_usbpd_context_t *context, uint8_t divider);

/** \} group_usbpd_vbus_ctrl_functions */

/**
* \addtogroup group_usbpd_vbus_ctrl_functions
* \{
*/

void Cy_USBPD_Fault_Vbus_IlimConfigUpdate (cy_stc_usbpd_context_t *context, uint32_t current);

void Cy_USBPD_Fault_Vbus_IlimEnable (cy_stc_usbpd_context_t *context, uint32_t current);

void Cy_USBPD_Fault_Vbus_IlimDisable (cy_stc_usbpd_context_t *context);

void Cy_USBPD_Hal_Remove_Internal_Fb_Res_Div(cy_stc_usbpd_context_t *context);

void Cy_USBPD_Fault_VbatGndScpLevelSet(cy_stc_usbpd_context_t *context, cy_en_usbpd_vbat_gnd_scp_level_t cur_level);

void Cy_USBPD_Fault_VbatGndScpEn(cy_stc_usbpd_context_t *context, bool pctrl, uint8_t mode);

void Cy_USBPD_Fault_VbatGndScpDis(cy_stc_usbpd_context_t *context, bool pctrl);

void Cy_USBPD_Fault_BrownOutDetEn(cy_stc_usbpd_context_t *context);

void Cy_USBPD_Fault_BrownOutDetDis(cy_stc_usbpd_context_t *context);

bool Cy_USBPD_Fault_BrownOutStatus(cy_stc_usbpd_context_t *context);

void Cy_USBPD_Fault_VregInrushDetEn(cy_stc_usbpd_context_t *context);

void Cy_USBPD_Fault_VregInrushDetDis(cy_stc_usbpd_context_t *context);

bool Cy_USBPD_Fault_VregInrushStatus(cy_stc_usbpd_context_t *context);

void Cy_USBPD_Fault_Vbat_OvpIntrHandler(cy_stc_usbpd_context_t *context);

void Cy_USBPD_Fault_Vbat_UvpIntrHandler(cy_stc_usbpd_context_t *context);

void Cy_USBPD_Fault_Vbat_OcpIntrHandler(cy_stc_usbpd_context_t *context);

void Cy_USBPD_Fault_Vbus_OvpIntrHandler(cy_stc_usbpd_context_t *context);

void Cy_USBPD_Fault_Vbus_UvpIntrHandler(cy_stc_usbpd_context_t *context);

void Cy_USBPD_Fault_Vconn_OcpIntrHandler(cy_stc_usbpd_context_t *context);

void Cy_USBPD_Fault_Vbus_RcpIntrHandler(cy_stc_usbpd_context_t *context);

void Cy_USBPD_Fault_Vbus_ScpIntrHandler(cy_stc_usbpd_context_t *context);

void Cy_USBPD_Fault_Vbus_OcpIntrHandler(cy_stc_usbpd_context_t *context);

void Cy_USBPD_Fault_CcOvp_IntrHandler(cy_stc_usbpd_context_t *context);

void Cy_USBPD_Fault_SbuOvp_IntrHandler(cy_stc_usbpd_context_t *context);

void Cy_USBPD_Fault_Vbus_OcpEnable(cy_stc_usbpd_context_t *context, uint32_t current, cy_cb_vbus_fault_t cb);

void Cy_USBPD_Fault_Vbus_OcpDisable(cy_stc_usbpd_context_t *context, bool pctrl);

void Cy_USBPD_Fault_Vbus_OvpEnable(cy_stc_usbpd_context_t *context, uint16_t volt, cy_cb_vbus_fault_t cb, bool pctrl);

void Cy_USBPD_Fault_Vbus_OvpDisable(cy_stc_usbpd_context_t *context, bool pctrl);

void Cy_USBPD_Fault_Vbus_UvpEnable(cy_stc_usbpd_context_t *context, uint16_t volt, cy_cb_vbus_fault_t cb, bool pctrl);

void Cy_USBPD_Fault_Vbus_UvpDisable(cy_stc_usbpd_context_t *context, bool pctrl);

void Cy_USBPD_Fault_Vbat_OvpEnable(cy_stc_usbpd_context_t *context, uint16_t threshold, uint8_t filterSel, cy_cb_vbus_fault_t cb, bool pctrl);

void Cy_USBPD_Fault_Vbat_OvpDisable(cy_stc_usbpd_context_t *context, bool pctrl);

void Cy_USBPD_Fault_Vbat_UvpEnable(cy_stc_usbpd_context_t *context, uint16_t threshold, uint8_t filterSel, cy_cb_vbus_fault_t cb, bool pctrl);

void Cy_USBPD_Fault_Vbat_UvpDisable(cy_stc_usbpd_context_t *context, bool pctrl);

void Cy_USBPD_Fault_Vbat_OcpEnable(cy_stc_usbpd_context_t *context, uint32_t current, cy_cb_vbus_fault_t cb);

void Cy_USBPD_Fault_Vbat_OcpDisable(cy_stc_usbpd_context_t *context, bool pctrl);

void Cy_USBPD_Fault_Voutbb_RcpEnable(cy_stc_usbpd_context_t *context, cy_cb_vbus_fault_t cb);

void Cy_USBPD_Fault_Voutbb_RcpDisable(cy_stc_usbpd_context_t *context);

void Cy_USBPD_Fault_Vconn_OcpEnable(cy_stc_usbpd_context_t *context, cy_cb_vbus_fault_t cb);

void Cy_USBPD_Fault_Vconn_OcpDisable(cy_stc_usbpd_context_t *context);

void Cy_USBPD_Fault_Vconn_ScpEnable(cy_stc_usbpd_context_t *context, cy_cb_vbus_fault_t cb);

void Cy_USBPD_Fault_Vconn_ScpDisable(cy_stc_usbpd_context_t *context);

void Cy_USBPD_Fault_Vbus_ScpEnable(cy_stc_usbpd_context_t *context, uint32_t current, cy_cb_vbus_fault_t cb);

void Cy_USBPD_Fault_Vbus_ScpDisable(cy_stc_usbpd_context_t *context);

void Cy_USBPD_Fault_Vbus_RcpEnable(cy_stc_usbpd_context_t *context, uint16_t volt, cy_cb_vbus_fault_t cb);

void Cy_USBPD_Fault_Vbus_RcpDisable(cy_stc_usbpd_context_t *context);

void Cy_USBPD_Fault_FetAutoModeEnable(cy_stc_usbpd_context_t *context, bool pctrl, cy_en_usbpd_vbus_filter_id_t filterIndex);

void Cy_USBPD_Fault_FetAutoModeDisable(cy_stc_usbpd_context_t *context, bool pctrl, cy_en_usbpd_vbus_filter_id_t filterIndex);

void Cy_USBPD_Fault_CcSbuSetCB(cy_stc_usbpd_context_t *context, cy_cb_vbus_fault_t cb);

void Cy_USBPD_Fault_VinUvpEn(cy_stc_usbpd_context_t *context, uint16_t threshold,
        cy_cb_adc_events_t cb, bool pctrl, cy_en_usbpd_vbus_uvp_mode_t mode);

void Cy_USBPD_Fault_VinUvpDis(cy_stc_usbpd_context_t *context, bool pctrl);

void Cy_USBPD_Fault_VinOvpEn(cy_stc_usbpd_context_t *context, uint16_t threshold,
    cy_cb_adc_events_t cb, bool pctrl, cy_en_usbpd_vbus_ovp_mode_t mode);

void Cy_USBPD_Fault_VinOvpDis(cy_stc_usbpd_context_t *context, bool pctrl);

/** \cond DOXYGEN_HIDE */
void Cy_USBPD_Fault_CcOvp_SetPending(cy_stc_usbpd_context_t *context);

void Cy_USBPD_Fault_Vbus_SetCsaRsense(cy_stc_usbpd_context_t *context, uint8_t rsense);

bool Cy_USBPD_Vbus_CompGetStatus(cy_stc_usbpd_context_t *context, cy_en_usbpd_vbus_filter_id_t id, bool isFiltered);
/** \endcond */

void Cy_USBPD_CcOvpControl(cy_stc_usbpd_context_t * context, bool flag);

void Cy_USBPD_Vbus_V5vChangeDetectHandler(cy_stc_usbpd_context_t *context);

int16_t Cy_USBPD_Vbus_Ctrl_FbGetIdacStep(uint16_t new_volt, uint16_t cur_volt);

int16_t Cy_USBPD_Vbus_GetTrimIdac(cy_stc_usbpd_context_t * context, uint16_t volt_mv);

void Cy_USBPD_Vbus_SystemClockDisable(cy_stc_usbpd_context_t * context);

void Cy_USBPD_Vbus_SystemClockEnable(cy_stc_usbpd_context_t * context);
/** \} group_usbpd_vbus_ctrl_functions */

#endif /* (defined(CY_IP_MXUSBPD) || defined(CY_IP_M0S8USBPD)) */

#endif /* _CY_USBPD_VBUS_CTRL_H_ */

/** \} group_usbpd_vbus_ctrl */

/* [] END OF FILE */
