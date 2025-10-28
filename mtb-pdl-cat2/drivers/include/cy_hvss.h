/***************************************************************************//**
* \file cy_hvss.h
* \version 1.0
*
* Provides the API declarations of the HVSS driver.
*
********************************************************************************
* \copyright
* Copyright 2024 Cypress Semiconductor Corporation
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

#if !defined(CY_HVSS_H)
#define CY_HVSS_H
/**
* \addtogroup group_hvss
* \{
* High-Voltage Subsystem (HVSS)
*
* The functions and other declarations used in this driver are in cy_hvss.h.
* You can include cy_pdl.h to get access to all functions
* and declarations in the PDL.
*
* The High-Voltage Subsystem (HVSS) contains a series of power management circuits.
* The applications are directly connected to a battery
* and tolerate up to 42 V.
* The HVSS has two public cells: HVREG and LIN/CXPI PHY.
* The following shows the block diagram for the HVSS.
*
* ![](hvss_diagram.png)
*
* Both HVREG and LIN/CXPI PHY can generate \ref group_hvss_lin_interrupt_macros
* - HVREG can generate an interrupt if a thermal shutdown occurs
* - LIN/CXPI PHY has a 12-bit timer that can generate a wakeup interrupt
* - LIN/CXPI PHY has another 12-bit timer that can generate a fault interrupt.
* (Must not be confused with sysfault, which is related to the LIN line fault)
*
* All interrupt sources share the same interrupt handler. To handle interrupts properly,
* use \ref Cy_HVSS_LinPhy_GetIntrStatus to get bitmasks of the interrupt sources.
* Also, to prevent trigger interrupt handler, mask some of the sources.
* see \ref Cy_HVSS_LinPhy_GetIntrMask \ref Cy_HVSS_LinPhy_SetIntrMask \ref Cy_HVSS_LinPhy_GetIntrStatusMasked
*
* HVREG can trigger \ref group_sysfault see \ref HVSS_FAULT_PWR in case if output of the regulator is not good
*
********************************************************************************
* \section group_hvss_more_information More Information
********************************************************************************
*
* See the technical reference manual (TRM) for more information about the HVSS
* architecture.
*
********************************************************************************
* \section group_hvss_changelog Changelog
********************************************************************************
*
* <table class="doxtable">
*   <tr><th>Version</th><th style="width: 52%;">Changes</th><th>Reason for Change</th></tr>
*   <tr>
*     <td>1.0</td>
*     <td>Initial version</td>
*     <td></td>
*   </tr>
* </table>
*
* \defgroup group_hvss_macros Macros
* \{
*     \defgroup group_hvss_general_macros HVSS general parameters
*     \defgroup group_hvss_hvreg_status_macros HV regulator status
*     \defgroup group_hvss_lin_interrupt_macros HVSS interrupts
* \}
* \defgroup group_hvss_functions Functions
* \defgroup group_hvss_data_structures Data Structure
* \defgroup group_hvss_enumerated_types Enumerated Types
*/

#include "cy_device.h"
#include <cy_device_headers.h>

#include "cy_syslib.h"

#if defined(__cplusplus)
extern "C" {
#endif

/***************************************
* Macro definitions
***************************************/
/**
* \addtogroup group_hvss_general_macros
* \{
*/

/** Driver major version */
#define CY_HVSS_DRV_VERSION_MAJOR       1

/** Driver minor version */
#define CY_HVSS_DRV_VERSION_MINOR       0

#define CY_HVSS_ID              (CY_PDL_DRV_ID(0x31UL))                          /**< HVSS PDL ID */

#define CY_HVSS_ID_INFO          (uint32_t)(CY_HVSS_ID | CY_PDL_STATUS_INFO)    /**< Return prefix for HVSS driver function status codes */
#define CY_HVSS_ID_WARNING       (uint32_t)(CY_HVSS_ID | CY_PDL_STATUS_WARNING) /**< Return prefix for HVSS driver function warning return values */
#define CY_HVSS_ID_ERROR         (uint32_t)(CY_HVSS_ID | CY_PDL_STATUS_ERROR)   /**< Return prefix for HVSS driver function error return values */

/** \} group_hvss_general_macros */

/**
* \addtogroup group_hvss_hvreg_status_macros
* \{
*/
#define CY_HVSS_HVREG_STATUS_PWR_GOOD_MSK         HVSS_HVREG_STATUS_PWR_GOOD_Msk         /**< High if regulator is settled and operating within normal limits */
#define CY_HVSS_HVREG_STATUS_PWR_GOOD_MAST_MSK    HVSS_HVREG_STATUS_PWR_GOOD_MAST_Msk    /**< Master Power Good.
                                                                                          * \note This Macro is applicable to PSOC4 HVMS only.
                                                                                          */
#define CY_HVSS_HVREG_STATUS_THERMAL_SHUTDOWN_MSK HVSS_HVREG_STATUS_THERMAL_SHUTDOWN_Msk /**< Thermal Shutdown Active.
                                                                                          * \note This Macro is applicable to PSOC4 HVMS only.
                                                                                          */

/** \} group_hvss_hvreg_status_macros */

/**
* \addtogroup group_hvss_lin_interrupt_macros
* \{
*/
#define CY_HVSS_LIN_INTR_WAKEUP_MSK    HVSS_LIN_INTR_WAKEUP_Msk    /**< Master-asserted dominant state wakeup (timeout of wakeup timer) */
#define CY_HVSS_LIN_INTR_FAULT_MSK     HVSS_LIN_INTR_FAULT_Msk     /**< Too long interface-asserted state (dominant state timeout) */
#define CY_HVSS_LIN_INTR_HVREG_TSD_MSK HVSS_LIN_INTR_HVREG_TSD_Msk /**< Thermal Shutdown Detected.
                                                                    * \note Applicable to PSOC4 HVMS only.
                                                                    */

/** \} group_hvss_lin_interrupt_macros */

/**
* \addtogroup group_hvss_enumerated_types
* \{
*/

#if (defined (CY_IP_M0S8HVSS_VERSION) && (2U == CY_IP_M0S8HVSS_VERSION)) || defined (CY_DOXYGEN)
/** Define Zener diode clamp mode values.
 * \note This Enum is applicable to PSOC4 HVMS only.
 */
typedef enum
{
    CY_HVSS_HVREG_DIS_CLAMP_DIS_DIODE = 0, /**< Zener clamp disable, diode disable */
    CY_HVSS_HVREG_DIS_CLAMP_EN_DIODE,      /**< Zener clamp disable, diode enable */
    CY_HVSS_HVREG_EN_CLAMP_DIS_DIODE,      /**< Zener clamp enable, diode disable */
    CY_HVSS_HVREG_EN_CLAMP_EN_DIODE        /**< Zener clamp enable, diode enable */
} cy_hvss_hvreg_clamp_mode_t;

/** Define HVREG thermal shutdown(TSD) mode values.
 * \note This Enum is applicable to PSOC4 HVMS only.
 */
typedef enum
{
    CY_HVSS_HVREG_REG_ON_FOR_TSD  = 0, /**< Keep Vdd on for TSD event (LIN turns off) */
    CY_HVSS_HVREG_REG_OFF_FOR_TSD = 1, /**< Turn off Vdd and LIN on TSD event */
    CY_HVSS_HVREG_OFF_TSD_CKT     = 3  /**< Turn off TSD circuit */
} cy_hvss_hvreg_tsd_mode_t;

/** Define LIN or CXPI PHY interface values.
 * \note This Enum is applicable to PSOC4 HVMS only.
 */
typedef enum
{
    CY_HVSS_LIN_PHY_0_INTERFACE = 0, /**< Select LIN-PHY 0 interface */
    CY_HVSS_LIN_PHY_1_INTERFACE,     /**< Select LIN-PHY 1 interface */
    CY_HVSS_CXPI_MASTER_INTERFACE,   /**< Select CXPI master interface */
    CY_HVSS_CXPI_SLAVE_INTERFACE     /**< Select CXPI slave interface */
} cy_hvss_phy_interface_t;
#endif /* (2U == CY_IP_M0S8HVSS_VERSION) */

/** Define resistor attenuator power mode values. */
typedef enum
{
    CY_HVSS_RDIV_MODE_ACTIVE_DEEPSLEEP = 0, /**< Enable in Active and Deep Sleep modes */
    CY_HVSS_RDIV_MODE_ACTIVE_ONLY           /**< Enable in Active mode only */
} cy_hvss_rdiv_power_mode_t;

/** Define resistor attenuator control values. */
typedef enum
{
    CY_HVSS_RDIV_ATTENUATION_16X = 0, /**< 16x attenuation */
    CY_HVSS_RDIV_ATTENUATION_24X      /**< 24x attenuation */
} cy_hvss_rdiv_attenuation_t;

/** Define LIN-PHY mode values */
typedef enum
{
    CY_HVSS_LIN_PHY_MODE_DISABLED = 0, /**< OFF (TX off, Rx off, Bias Circuits Off), LIN pin recessive */
    CY_HVSS_LIN_PHY_MODE_SLEEP,        /**< TX off, RX on, LIN pin recessive (typically used in Deep Sleep) */
    CY_HVSS_LIN_PHY_MODE_STANDBY,      /**< TX off, RX off, Bias circuits on (faster turn-on, not normally used) */
    CY_HVSS_LIN_PHY_MODE_DIAGNOSIS,    /**< TX on, RX on, TX weak pull-down (diagram of broken wire detection) */
    CY_HVSS_LIN_PHY_MODE_NORMAL_1_0,   /**< TX on, RX on, 1.0V/us TX edge rate */
    CY_HVSS_LIN_PHY_MODE_NORMAL_1_5,   /**< TX on, RX on, 1.5V/us TX edge rate */
    CY_HVSS_LIN_PHY_MODE_NORMAL_2_0,   /**< TX on, RX on, 2.0V/us TX edge rate */
    CY_HVSS_LIN_PHY_MODE_FAST          /**< Fast mode (non-lin compliant, up to 100kb/s capable) */
} cy_hvss_lin_phy_mode_t;

/** Define LIN-PHY slew rate */
typedef enum
{
    CY_HVSS_LIN_PHY_SL_ROUND_NORMAL = 0, /**< Normal */
    CY_HVSS_LIN_PHY_SL_ROUND_MODERATE    /**< More moderate (rounded) for lower EMI */
} cy_hvss_lin_phy_sl_round_t;

/** Define LIN-PHY interface values */
typedef enum
{
    CY_HVSS_LIN_PHY_INTERFACE_PRIMARY = 0, /**< Primary interface (connected to internal LIN controller through HSIOM) */
    CY_HVSS_LIN_PHY_INTERFACE_ALTERNATE    /**< Alternate interface (connected to GPIOs through HSIOM) */
} cy_hvss_lin_phy_route_t;
/** \} group_hvss_enumerated_types */

/** \addtogroup group_hvss_data_structures
* \{
*/

/** Define configuration values for init */
typedef struct
{
    uint16_t                    wakeupTimerValue;  /**< Number of LFCLK edges before a wakeup interrupt is triggered */
    uint16_t                    faultTimerValue;   /**< Number of LFCLK edges before a fault interrupt is triggered */
    cy_hvss_lin_phy_mode_t      linMode;           /**< Select the LIN-PHY mode of operation */
    cy_hvss_lin_phy_sl_round_t  rfDetect;          /**< Select the slew rate for LIN-PHY */
    cy_hvss_lin_phy_route_t     linPhyRoute;       /**< Select LIN-PHY route through HSIOM */
#if (defined (CY_IP_M0S8HVSS_VERSION) && (2U == CY_IP_M0S8HVSS_VERSION)) || defined (CY_DOXYGEN)
    cy_hvss_hvreg_clamp_mode_t  hvregClampMode;    /**< Select Zener diode clamp mode
                                                    * \note Applicable to PSOC4 HVMS only
                                                    */
    cy_hvss_hvreg_tsd_mode_t    hvregTsdMode;      /**< Select thermal shutdown mode
                                                    * \note Applicable to PSOC4 HVMS only
                                                    */
    cy_hvss_phy_interface_t     phyInterfaceSel;   /**< Select LIN or CXPI PHY interface
                                                    * \note Applicable to PSOC4 HVMS only
                                                    */
    bool                        vbatDivEnable;     /**< Enable VBAT voltage divider
                                                    * \note Applicable to PSOC4 HVMS only
                                                    */
#endif /* (2U == CY_IP_M0S8HVSS_VERSION) */
#if (defined (CY_IP_M0S8HVSS_VERSION) && (1U == CY_IP_M0S8HVSS_VERSION)) || defined (CY_DOXYGEN)
    cy_hvss_rdiv_power_mode_t   rdivActiveEnable;  /**< Power modes where RDIV is enabled */
    cy_hvss_rdiv_attenuation_t  rdiv0Scale;        /**< VS0 attenuation */
    cy_hvss_rdiv_attenuation_t  rdiv1Scale;        /**< VS1 attenuation */
    bool                        rdiv0Enable;       /**< Enable resistor attenuator control VS0 */
    bool                        rdiv1Enable;       /**< Enable resistor attenuator control VS1 */
#endif /* (1U == CY_IP_M0S8HVSS_VERSION) */
    bool                        linEnable;         /**< Transmit enable of the LIN interface */
    bool                        wakeupTimerEnable; /**< Wakeup timer is running,
                                                    * required for full LIN compatibility in Deep Sleep
                                                    */
    bool                        faultTimerEnable;  /**< Fault timer is running, required for full LIN compatibility */
} cy_hvss_config_t;

/** \} group_hvss_data_structures */

/***************************************
* Function Prototypes
***************************************/

/**
* \addtogroup group_hvss_functions
* \{
*/
#if defined (CY_IP_M0S8HVSS)
void Cy_HVSS_Init(const cy_hvss_config_t* configPtr);
void Cy_HVSS_DeInit(void);
uint8_t Cy_HVSS_Hvreg_GetStatus(void);
uint8_t Cy_HVSS_LinPhy_GetRxdPin(void);
void Cy_HVSS_LinPhy_EnableWakeupTimer(void);
void Cy_HVSS_LinPhy_DisableWakeupTimer(void);
void Cy_HVSS_LinPhy_EnableFaultTimer(void);
void Cy_HVSS_LinPhy_DisableFaultTimer(void);
void Cy_HVSS_LinPhy_SetPhyMode(cy_hvss_lin_phy_mode_t mode);
void Cy_Hvss_LinPhy_EnablePhy(void);
void Cy_HVSS_LinPhy_DisablePhy(void);
void Cy_HVSS_LinPhy_ClearInterrupt(uint32_t interrupt);
uint32_t Cy_HVSS_LinPhy_GetIntrMask(void);
void Cy_HVSS_LinPhy_SetIntrMask(uint32_t interrupt);
uint32_t Cy_HVSS_LinPhy_GetIntrStatusMasked(void);
uint32_t Cy_HVSS_LinPhy_GetIntrStatus(void);
#endif /* defined (CY_IP_M0S8HVSS) */

/** \} group_hvss_functions */

/** \} group_hvss */

#if defined(__cplusplus)
}
#endif

#endif /* #if !defined(CY_HVSS_H) */

/* [] END OF FILE */
