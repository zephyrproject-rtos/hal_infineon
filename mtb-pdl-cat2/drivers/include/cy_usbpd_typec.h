/***************************************************************************//**
* \file cy_usbpd_typec.h
* \version 2.110
*
* Provides API declarations of the USBPD Type C driver.
*
********************************************************************************
* \copyright
* (c) (2022-2025), Cypress Semiconductor Corporation (an Infineon company) or
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

/**
* \addtogroup group_usbpd
* \{
*
* The USBPD driver provides APIs to configure and access the M0S8-USBPD and
* MX-USBPD IP block on the EZ-PD PMG1 family of devices into a high-quality,
* versatile analog front-end for PD applications. The PMG1 family is a set of
* USB Power-Delivery (USBPD) enabled Micro-Controllers for the general market.
* The devices in this family support one or two instances of the Power Delivery
* Sub-System (PDSS) in addition to other standard MCU peripherals available on
* PSoC4 devices.
*
* \image html usbpd_driver.png "USBPD Driver Solution"
* \image latex usbpd_driver.png
*
* The USBPD driver interacts directly with the hardware and provides support of
* the features available in the hardware. It implements the API interface and
* callbacks/hooks requested by the PDStack middleware to operate.
*
* The functions of the USBPD driver include
* 1. Configure the terminations on the CC pins of the PMG1 device, including support for automatic Rp-Rd toggle on parts that support Dual Role Port (DRP) functionality.
* 2. Determine the external terminations applied on the CC pins using the line comparators.
* 3. Measure Type-C VBus voltage using the 8-bit ADC.
* 4. Configure the USB-PD Transceiver (PHY) and send/receive messages, including support for Extended Data Messages.
* 5. Configure the gate driver outputs of the PMG1 device to enable power output or charging paths.
* 6. Configure the comparators and cut-off circuits to provide Over-Voltage (OV), Under-Voltage (UV), Over-Current (OC), Short-Circuit (SC) and Reverse-Current (RC) Protection.
* 7. Configure the in-built USB 2.0 and Side Band Use (SBU) Multiplexers for USB, Display and Thunderbolt data connections.
* 8. Drive/detect transitions on the HotPlug Detect (HPD) pin as required by the Display function.
* 9. Configure the terminations and measure the voltages on the D+/D- pins for BC 1.2.
* Most of the USBPD driver functions are not intended to be called directly
* from the user application as the PDStack middleware makes use of them to
* manage the functionality in a specification compliant manner.
*
* \section group_usbpd_section_configuration Configuration Considerations
*
* \subsection group_usbpd_section_configuration_personalities Use ModusToolbox Device Configurator Tool to generate initialization code
* The following are the steps to generate initialization code using the
* ModusToolbox Device Configurator Tool:
* 1. Launch the ModusToolbox Device Configurator Tool
* 2. Switch to the Peripherals tab. Enable the USB-C Power Delivery personality
* under Communication
* 3. Go to the Parameters Pane for the USBPD Personality and configure it with
* the desired parameters (Configure the clock inputs, set the fault protection
* parameters per configuration considerations, etc)
*    \image html usbpd_driver_clocks.png "USBPD Driver Clock Configuration"
*    \image latex usbpd_driver_clocks.png
*    \image html usbpd_driver_fault_protection.png "USBPD Driver Fault Protection Configuration"
*    \image latex usbpd_driver_fault_protection.png
* 4. Perform File->Save for the initialization code to generate
*
* Now, all required USBPD driver initialization code and configuration
* prerequisites will be generated:
*
* 1. The Peripheral Clock Divider assignment and analog routing are parts of
* the init_cycfg_all() routine. Place the call of cybsp_init () function
* before using any USBPD driver API functions to ensure initialization of all
* external resources required for the USBPD driver operation.
* 2. The USBPD driver configuration structure declaration is in the
* cycfg_peripherals.h file and its initialization is in the cycfg_peripherals.c
* file. The variable name is mtb_usbpd_port<port_num>_config. It must be used with
* Cy_USBPD_Init() function.
*    \snippet usbpd_sut.c snippet_configuration_structure
*    \snippet usbpd_sut.c snippet_configuration_init
*
* \section group_usbpd_section_more_information More Information
*
* For more information on the USBPD peripheral, refer to the technical
* reference manual (TRM) and the Datasheet.
*
* \section group_usbpd_changelog Changelog
* <table class="doxtable">
*   <tr><th>Version</th><th>Changes</th><th>Reason for Change</th></tr>
*    <tr>
*     <td rowspan="2">2.110</td>
*     <td>Added new APIs to enable/disable the ilimit block for CFP devices.</td>
*     <td>New feature support</td>
*    </tr>
*    <tr>
*     <td>Updated the USBPD driver with bug fixes related to Fault Protection and SBU MUX for CFP devices.</td>
*     <td>Defect Fix</td>
*    </tr>
*    <tr>
*     <td rowspan="2">2.100</td>
*     <td>Added new APIs to enable or disable the SBU ADFT block.</td>
*     <td>New feature support</td>
*    </tr>
*    <tr>
*     <td>Updated the USBPD driver to enable battery charging support on Type-A port for the CYPM1011 device.</td>
*     <td>New feature support</td>
*    </tr>
*    <tr>
*     <td rowspan="1">2.90</td>
*     <td>Updated the USBPD driver to enable support for CCG6xF_CFP family devices.</td>
*     <td>New family devices support.</td>
*    </tr>
*    <tr>
*     <td rowspan="1">2.80</td>
*     <td>Updated the USBPD driver to enable dual port support for CYPM1321 device.</td>
*     <td>Defect Fix.</td>
*    </tr>
*    <tr>
*     <td rowspan="3">2.70</td>
*     <td>Corrected REFGEN control settings for PMG1S3.</td>
*     <td>Defect Fix.</td>
*    </tr>
*    <tr>
*     <td>Updated configuration table space for Dock solutions.</td>
*     <td>New feature support.</td>
*    </tr>
*    <tr>
*     <td>Updates related to HPD handling for PMG1S3.</td>
*     <td>Defect Fix.</td>
*    </tr>
*    <tr>
*     <td rowspan="3">2.60</td>
*     <td>Added PMG1B1 BB VOUT RCP support.</td>
*     <td>New feature support.</td>
*    </tr>
*    <tr>
*     <td>Added PMG1B1 VBBOUT/VBAT protection functions to API reference manual.</td>
*     <td>API reference manual update</td>
*    </tr>
*    <tr>
*     <td>Updates to resolve compilation warnings related to casting of variables.</td>
*     <td>Defect Fix.</td>
*    </tr>
*    <tr>
*     <td rowspan="2">2.50</td>
*     <td>Updates to resolve compilation warnings related to unused variables.</td>
*     <td>Defect Fix.</td>
*    </tr>
*    <tr>
*     <td>PFET operation enabled for PMG1-B1 in a USB-PD Sink only Role.</td>
*     <td>Defect Fix.</td>
*    </tr>
*    <tr>
*     <td rowspan="3">2.40</td>
*     <td>Added LF Counter driver.</td>
*     <td>New feature support.</td>
*    </tr>
*    <tr>
*     <td>Updated configuration table space to support CCG8 device series.</td>
*     <td>Feature support.</td>
*    </tr>
*    <tr>
*     <td>Corrected the ADC detach detection input used in PMG1-S1 device.</td>
*     <td>Defect Fix.</td>
*    </tr>
*    <tr>
*     <td rowspan="3">2.30</td>
*     <td>Use WLC1 Series Code compile directive</td>
*     <td>Defect Fix</td>
*    </tr>
*    <tr>
*     <td>Changed from Cy_USBPD_Bch_Set_AfcTxData to Cy_USBPD_Bch_Afc_Set_Tx_Data</td>
*     <td>API Name Change</td>
*    </tr>
*    <tr>
*     <td>Added Cy_USBPD_Bch_AfcGetRxDataPtr and Cy_USBPD_Bch_AfcGetRxDataCount functions</td>
*     <td>APIs added for Adaptive fast charge feature(AFC)</td>
*    </tr>
*    <tr>
*     <td rowspan="4">2.20</td>
*     <td>Added support for PMG1B1 device.</td>
*     <td>New device support.</td>
*    </tr>
*    <tr>
*     <td>Added API to measure Vbus current.</td>
*     <td>New feature support.</td>
*    </tr>
*    <tr>
*     <td>Vsys-Vbus switch issue fixed.</td>
*     <td>Defect Fix</td>
*    </tr>
*    <tr>
*     <td>Fixed deep sleep reference not enabled during Type-C restart.</td>
*     <td>Defect Fix</td>
*    </tr>
*    <tr>
*     <td rowspan="1">2.10</td>
*     <td>CCG7D updates.</td>
*     <td>Feature support.</td>
*    </tr>
*    <tr>
*     <td rowspan="2">2.0</td>
*     <td>Added support for CCG7D, CCG7s and WLC1 devices.</td>
*     <td>New device support.</td>
*    </tr>
*    <tr>
*     <td>Added support for PPS source and regulation control via internal error amplifier</td>
*     <td>New feature support</td>
*    </tr>
*    <tr>
*     <td rowspan="3">1.30</td>
*     <td>Added SBU Level Detection</td>
*     <td>New feature support.</td>
*    </tr>
*    <tr>
*     <td>Updates for EPR support</td>
*     <td>New feature support</td>
*    </tr>
*    <tr>
*     <td>Added legacy charging drivers</td>
*     <td>New feature support</td>
*   </tr>
*   <tr>
*     <td>1.20.1</td>
*     <td>Update the paths to the code snippets.</td>
*     <td>PDL structure update.</td>
*   </tr>
*   <tr>
*     <td>1.20</td>
*     <td>Added APIs to control NGDO drive strength.</td>
*     <td>New feature support</td>
*   </tr>
*   <tr>
*     <td rowspan="3">1.10</td>
*     <td>Added drivers for HPD and MUX feature.
*         </td>
*     <td>New feature support.</td>
*   </tr>
*   <tr>
*     <td>Added support for VBus Over Current Protection, VBus Short Circuit
*     Protection, VBus Reverse Current Protection and VConn Over Current
*     Protection.
*         </td>
*     <td>New feature support.</td>
*   </tr>
*   <tr>
*     <td>Added support for PMG1S3 device.
*         </td>
*     <td>New device support.</td>
*   </tr>
*   <tr>
*     <td>1.0</td>
*     <td>Initial version</td>
*     <td></td>
*   </tr>
* </table>
*
* \defgroup group_usbpd_common Common
* \defgroup group_usbpd_hpd HPD (USBPD)
* \defgroup group_usbpd_legacy Legacy Charging (USBPD)
* \defgroup group_usbpd_mux MUX (USBPD)
* \defgroup group_usbpd_phy Phy (USBPD)
* \defgroup group_usbpd_typec Type C (USBPD)
* \defgroup group_usbpd_vbus_ctrl VBus Ctrl (USBPD)
* \defgroup group_usbpd_idac_ctrl IDAC (USBPD)
* \defgroup group_usbpd_buck_boost Buck Boost (USBPD)
* \defgroup group_usbpd_lf_counter LF Counter (USBPD)
*
*/

/** \} group_usbpd */

/**
* \addtogroup group_usbpd_typec
* \{
* USBPD Type C driver.
*
* \defgroup group_usbpd_typec_macros Macros
* \defgroup group_usbpd_typec_functions Functions
*
* */

#ifndef _CY_USBPD_TYPEC_H_
#define _CY_USBPD_TYPEC_H_

#include <cy_usbpd_common.h>

#if (defined(CY_IP_MXUSBPD) || defined(CY_IP_M0S8USBPD))

/** \cond DOXYGEN_HIDE */

#ifndef VBUS_IN_DISCHARGE_EN
/* VBUS in discharge enable */
#define VBUS_IN_DISCHARGE_EN                    (0u)
#endif /* VBUS_IN_DISCHARGE_EN */

/* VBUS discharge drive strength settings. */
#if VBUS_IN_DISCHARGE_EN
#ifndef VBUS_C_DISCHG_DS
#define VBUS_C_DISCHG_DS                        (1u)
#endif /* VBUS_C_DISCHG_DS */
#else /* !VBUS_IN_DISCHARGE_EN */
#ifndef VBUS_C_DISCHG_DS
#define VBUS_C_DISCHG_DS                        (4u)
#endif /* VBUS_C_DISCHG_DS */
#endif /* VBUS_IN_DISCHARGE_EN */

#ifndef VBUS_IN_DISCHG_DS
#define VBUS_IN_DISCHG_DS                       (4u)
#endif /*VBUS_IN_DISCHG_DS*/

#if VBUS_SLOW_DISCHARGE_EN
/* Time interval in ms between every steps of discharge strength setting */
#define VBUS_SLOW_DISCHARGE_TIME_MS              (1u)

/* Minimum VBUS_C Discharge Drive strength control value */
#define VBUS_C_DISCHG_DS_MIN                     (1u)

/* Minimum VBUS_IN Discharge Drive strength control value */
#define VBUS_IN_DISCHG_DS_MIN                    (1u)

#endif /* VBUS_SLOW_DISCHARGE_EN */

/* VCONN SCP limit in mA */
#define VCONN_SCP_TRIM_115_MA                   (15u)

/* VCONN ramp charging current limit for inrush control in nA */
#define VCONN_INRUSH_TRIM_50_NA                 (1u)

#if defined(CY_DEVICE_CCG3PA)
#define PDSS_CC_CTRL_0_CMP_LA_VSEL_CFG          (0UL)
#else /* !defined(CY_DEVICE_CCG3PA) */
#define PDSS_CC_CTRL_0_CMP_LA_VSEL_CFG          (7UL)
#endif /* CY_DEVICE */

/*
 * Delay required once VSYS is detected to before enabling VSYS - VDDD switch.
 * Set the macro to 0 to enable the switch immediately after detecting VSYS.
 */
#ifndef CY_USBPD_AUTO_SWITCH_VDDD_TO_VSYS_DELAY_MS
#define CY_USBPD_AUTO_SWITCH_VDDD_TO_VSYS_DELAY_MS  (1u)
#endif /*CY_USBPD_AUTO_SWITCH_VDDD_TO_VSYS_DELAY_MS*/

/* Enable Automatically switch VDDD to VSYS when VSYS is available. */
#ifndef CY_USBPD_AUTO_SWITCH_VDDD_TO_VSYS_ENABLE
#define CY_USBPD_AUTO_SWITCH_VDDD_TO_VSYS_ENABLE    (1u)
#endif /*CY_USBPD_AUTO_SWITCH_VDDD_TO_VSYS_DELAY_MS*/

/** \endcond */

/**
* \addtogroup group_usbpd_typec_macros
* \{
*/

/** \cond DOXYGEN_HIDE */
/* CC threshold definitions. */
#define PD_CMP_VSEL_0_2_V               (0u)
#define PD_CMP_VSEL_0_4_V               (1u)
#define PD_CMP_VSEL_1_43_V              (2u)
#define PD_CMP_VSEL_0_655_V             (3u)
#define PD_CMP_VSEL_0_8_V               (4u)
#define PD_CMP_VSEL_1_235_V             (5u)
#define PD_CMP_VSEL_1_77_V              (6u)
#define PD_CMP_VSEL_2_6_V               (7u)
/** \endcond */


/** The USBPD driver major version */
#define CY_USBPD_DRV_VERSION_MAJOR                       2

/** The USBPD driver minor version */
#define CY_USBPD_DRV_VERSION_MINOR                       110

/** The USBPD driver identifier */
#define CY_USBPD_ID                                      CY_PDL_DRV_ID(0x48U)

/*******************************************************************************
 * PMG1 Device Specific Constants.
 * Note: These values should not be modified.
 ******************************************************************************/

#define PDSS_CY_PD_DRP_TOGGLE_PERIOD_MS         (75u)           /**< Hardware based DRP toggle period in ms. */
#define PDSS_DRP_HIGH_PERIOD_MS                 (30u)           /**< Rp assert period in ms for hardware DRP toggle. */
#define PDSS_CY_PD_DRP_TOGGLE_PERIOD_VAL        (2500u)         /**< Hardware DRP toggle period in LF clock cycles. */
#define PDSS_DRP_HIGH_PERIOD_VAL                (1100u)         /**< Rp assert period in LF clock cycles. */
#define PDSS_CC_FILT_CYCLES                     (10)            /**< Number of LF clock cycles used for filtering
                                                                     CC comparator output. */

/** \cond DOXYGEN_HIDE */
#define PDSS_VBUS_IN_REF_SEL_VAL                (1u)            /** 500mV */

/* Location of SFLASH flag that indicates validity of VConn OCP trim setting. */
#define SFLASH_VCONN_TRIM_ENABLE_ADDR           (0x0FFFF400UL)
/** \endcond */

/** \} group_usbpd_typec_macros */

/**
* \addtogroup group_usbpd_typec_enum
* \{
*/

/**
 * @typedef cy_en_usbpd_poll_vsys_t
 * @brief List of values for poll for vsys variable.
 *
 * Bit 0 is used for enable the vsys polling.
 * Bit 1 is used for starting the delay timer in the task.
 * Bit 2 is used for stop re-starting the timer once it is started.
 *
 */
typedef enum
{
    CY_USBPD_POLL_VSYS_DO_NOT_POLL = 0,   /**< Explicit VSYS switching happened. Do not poll for VSYS change. */
    CY_USBPD_POLL_VSYS_IDLE = 1,          /**< Idle and poll for VSYS. */
    CY_USBPD_POLL_VSYS_INT_UP = 2,        /**< Interrupt happened while in explicit switch. Hence do not start the delay timer. */
    CY_USBPD_POLL_VSYS_START_TIMER = 3,   /**< Interrupt happened while in Idle state. start the delay timer. */
    CY_USBPD_POLL_VSYS_STOP_TIMER = 4,    /**< Timer is started. stop re-starting it again.. */
} cy_en_usbpd_poll_vsys_t;

/** \} group_usbpd_typec_enum */

/*******************************************************************************
*                            Function Prototypes
*******************************************************************************/

/**
* \addtogroup group_usbpd_typec_functions
* \{
*/

cy_en_usbpd_status_t Cy_USBPD_TypeC_Init (
        cy_stc_usbpd_context_t *context);

cy_en_usbpd_status_t Cy_USBPD_TypeC_Start(
        cy_stc_usbpd_context_t *context);

cy_en_usbpd_status_t Cy_USBPD_TypeC_Stop(
        cy_stc_usbpd_context_t *context);

void Cy_USBPD_TypeC_EnableRp(
        cy_stc_usbpd_context_t *context,
        uint8_t channel,
        cy_en_pd_rp_term_t rpVal);

void Cy_USBPD_TypeC_DisableRp(
        cy_stc_usbpd_context_t *context,
        uint8_t channel);

void Cy_USBPD_TypeC_EnDpSlpRp(
        cy_stc_usbpd_context_t *context);

void Cy_USBPD_TypeC_DisDpSlpRp(
        cy_stc_usbpd_context_t *context);

void Cy_USBPD_TypeC_EnableDeadBatRd (
        cy_stc_usbpd_context_t *context);

void Cy_USBPD_TypeC_EnableRd(
        cy_stc_usbpd_context_t *context,
        uint8_t channel);

void Cy_USBPD_TypeC_DisableRd(
        cy_stc_usbpd_context_t *context,
        uint8_t channel);

void Cy_USBPD_TypeC_RdEnable(
        cy_stc_usbpd_context_t *context);

void Cy_USBPD_TypeC_ChangeRp (
        cy_stc_usbpd_context_t *context,
        cy_en_pd_rp_term_t rp);

void Cy_USBPD_TypeC_SnkUpdateTrim(
        cy_stc_usbpd_context_t *context);

cy_pd_cc_state_t Cy_USBPD_TypeC_GetCCStatus(
        cy_stc_usbpd_context_t *context);

void Cy_USBPD_TypeC_SetPolarity(
        cy_stc_usbpd_context_t *context,
        uint8_t polarity);

void Cy_USBPD_TypeC_CfgAutoToggle(
        cy_stc_usbpd_context_t *context,
        bool enable);

bool Cy_USBPD_TypeC_IsAutoToggleActive(
        cy_stc_usbpd_context_t *context);

void Cy_USBPD_TypeC_AbortAutoToggle(
        cy_stc_usbpd_context_t *context);

void Cy_USBPD_TypeC_SMRestart(
        cy_stc_usbpd_context_t *context);

void Cy_USBPD_SetReference(
        cy_stc_usbpd_context_t *context,
        bool flag);

void Cy_USBPD_DisableVsysReg(
        cy_stc_usbpd_context_t *context);

void Cy_USBPD_DisableVsysSwitch (
        cy_stc_usbpd_context_t *context);

void Cy_USBPD_SwitchVsysToVbus(
        cy_stc_usbpd_context_t *context);

void Cy_USBPD_SwitchVbusToVsys(
        cy_stc_usbpd_context_t *context);

cy_en_usbpd_status_t Cy_USBPD_Init(
        cy_stc_usbpd_context_t *context,
        uint8_t port,
        void *ptrPdBaseReg,
        void *ptrPdTrimsBaseReg,
        cy_stc_usbpd_config_t *ptrUsbpdConfig,
        cy_cb_pd_dpm_get_config_t dpmGetConfigCbk);

bool Cy_USBPD_PrepareDeepSleep(
        cy_stc_usbpd_context_t *context,
        uint16_t voltage,
        int8_t percentage);

bool Cy_USBPD_Resume(
        cy_stc_usbpd_context_t *context);

cy_en_usbpd_status_t Cy_USBPD_SetSupplyChange_EvtCb(
        cy_stc_usbpd_context_t *context,
        cy_usbpd_supply_change_cbk_t cb);

void Cy_USBPD_Pump_Disable (
        cy_stc_usbpd_context_t *context,
        uint8_t index);

void Cy_USBPD_Pump_Enable (
        cy_stc_usbpd_context_t *context,
        uint8_t index);

/** \cond DOXYGEN_HIDE */
bool Cy_USBPD_IsVsysUp (
        cy_stc_usbpd_context_t *context);

void Cy_USBPD_Phy_VbusDetachCbk (
        void *context,
        bool  compOut);
#if CY_USBPD_CGND_SHIFT_ENABLE
void Cy_USBPD_TypeC_CgndWrapperEnable(
        cy_stc_usbpd_context_t *context);

void Cy_USBPD_TypeC_CgndWrapperDisable(
        cy_stc_usbpd_context_t *context);
#endif /* CY_USBPD_CGND_SHIFT_ENABLE */
/** \endcond */

bool Cy_USBPD_VsysCompStatus (
        cy_stc_usbpd_context_t *context);

cy_en_usbpd_status_t Cy_USBPD_SetEvtCb(
        cy_stc_usbpd_context_t *context,
        cy_usbpd_evt_cbk_t cb);

cy_en_usbpd_status_t Cy_USBPD_SetTypeCEvtCb(
        cy_stc_usbpd_context_t *context,
        void *callerContext,
        cy_usbpd_typec_evt_cbk_t cb);

cy_en_usbpd_status_t Cy_USBPD_SetSbuLevelDetect_EvtCb(
        cy_stc_usbpd_context_t *context,
        cy_cb_sbu_level_detect_t cb);

void Cy_USBPD_Intr1Handler (
        cy_stc_usbpd_context_t *context);

uint8_t Cy_USBPD_TypeC_GetRpRdStatus (
        cy_stc_usbpd_context_t *context, 
        uint8_t channel, 
        bool rd_idx);
        
void Cy_USBPD_TypeC_SetCC_to_0V (cy_stc_usbpd_context_t *context);

void Cy_USBPD_TypeC_SetCC_to_PrevState(cy_stc_usbpd_context_t *context);

void Cy_USBPD_EnableSwitch(cy_stc_usbpd_context_t *context);

void Cy_USBPD_VBus_Regulator_Init(cy_stc_usbpd_context_t *context);

/** \} group_usbpd_typec_functions */

#endif /* (defined(CY_IP_MXUSBPD) || defined(CY_IP_M0S8USBPD)) */

#endif /* _CY_USBPD_TYPEC_H_ */

/** \} group_usbpd_typec */

/* [] END OF FILE */
