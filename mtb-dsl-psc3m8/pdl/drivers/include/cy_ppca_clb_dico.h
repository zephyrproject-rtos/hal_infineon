/***************************************************************************//**
* \file cy_ppca_clb_dico.h
* \version 1.00
*
* Provides the API declarations of the PPCA CLB DICO driver.
*
********************************************************************************
* \copyright
* (c) 2024-2026, Infineon Technologies AG or an affiliate of
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
/**
* \addtogroup group_ppca_clb_dico
* \{
*
* The Digital Current Observer (DICO) subsystem is used for Totem-Pole PFC AC-DC
* conversion. It consists of three Phase Current Observers (PCOs) and a
* Multi-Phase Adapter (MPA).
*
* Each PCO manages PFC for its respective phase and contains:
* - Current Estimator: estimates inductor current by integrating inductor voltage
* - Modulator: produces PWM signals based on IMIN/IMAX thresholds with dead time support
* - Error Observer: measures difference between estimated and sensed current for
*   PI controller correction
*
* The MPA provides multi-phase support (up to 3 phases) through:
* - Phase Enabler (PE): controls insertion/removal of 2nd and 3rd phase PCOs
* - Phase Synchronizer (PS): maintains phase offset between phase-currents by
*   adjusting IMIN/IMAX of each PCO
*
* DICO selects ADC filter data channels for five input signals (Vac, Vo, iL0, iL1, iL2)
* via the CNFG register (SEL_VAC, SEL_VBUS, SEL_IL0, SEL_IL1, SEL_IL2).
*
* During mask or kill events, DICO continues running but its pwm/pwm_compl outputs
* are driven by the SAFE_REG register. On de-assertion, outputs resume after the
* rising edge of the charging signal.
*
* \defgroup group_ppca_clb_dico_macros Macros
* \defgroup group_ppca_clb_dico_enums Enumerations
* \defgroup group_ppca_clb_dico_structures Configuration Structures
* \defgroup group_ppca_clb_dico_functions Functions
*
*/
#if !defined(CY_PPCA_CLB_DICO_H)
#define CY_PPCA_CLB_DICO_H

#include "cy_device.h"

#if defined (CY_IP_MXS40PPSS) || defined (CY_DOXYGEN)

#include "cy_syslib.h"

#if defined(__cplusplus)
extern "C" {
#endif

/***************************************
*       Macros
***************************************/

/**
* \addtogroup group_ppca_clb_dico_macros
* \{
*/

/**
* \defgroup group_ppca_clb_dico_status DICO Status
* Macros to check current DICO status returned by
* \ref Cy_PPCA_CLB_DICO_ReadStatus function. Each status is encoded
* in a separate bit, therefore multiple bits may be set to indicate the
* current status.
* \{
*/

/** Report maximum on time reached */
#define CY_MAX_ON_TIME_REACHED       0x01U

/** Report active state of PCO0 */
#define CY_PCO0_ACTIVE               0x02U

/** Report active state of PCO1 */
#define CY_PCO1_ACTIVE               0x04U

/** Report active state of PCO2 */
#define CY_PCO2_ACTIVE               0x08U

/** Report incorrect setting of DICO */
#define CY_INCORR_SETTING            0x10U

/** Report mask state of DICO */
#define CY_MASK_STATE                0x20U

/** Report kill state of DICO */
#define CY_KILL_STATE                0x40U

/** Report safe state of DICO */
#define CY_SAFE_STATE                0x80U

/** Report minimum on time not reached when PWM modulator FSM state is ready to transit */
#define CY_MIN_ON_TIME_NOT_STATE     0x100U

/** \} group_ppca_clb_dico_status */

/**
* \defgroup group_ppca_clb_dico_intr_status DICO Interrupt Status Macros
* This section contains interrupt bit masks to use with:
*  - Cy_PPCA_CLB_DICO_GetInterruptStatus()
*  - Cy_PPCA_CLB_DICO_ClearInterrupt()
*  - Cy_PPCA_CLB_DICO_SetInterrupt()
*  - Cy_PPCA_CLB_DICO_GetInterruptMask()
*  - Cy_PPCA_CLB_DICO_SetInterruptMask()
*  - Cy_PPCA_CLB_DICO_GetInterruptStatusMasked()
* \{
*/

/** Phase-Shift interrupt 0: fires when a completed switching cycle is
 *  measured by the MAX_ON_TIME timer (Fsys/4 clock). This interrupt is
 *  generated autonomously by the DICO state machine independent of current
 *  accumulation. Fires even when FILT_OUT = 0 and no live converter is
 *  connected. See also \ref Cy_PPCA_CLB_DICO_ConfigPhase1. */
#define CY_DICO_INTR_PS_0       0x01U

/** Phase-Shift interrupt 1: fires when a completed switching cycle is
 *  measured by the MAX_ON_TIME timer (Fsys/4 clock). This interrupt is
 *  generated autonomously by the DICO state machine independent of current
 *  accumulation. Fires even when FILT_OUT = 0 and no live converter is
 *  connected. See also \ref Cy_PPCA_CLB_DICO_ConfigPhase1. */
#define CY_DICO_INTR_PS_1       0x02U

/** PE_USI */
#define CY_DICO_INTR_PE_USI     0x04U

/** PE_SCE1 */
#define CY_DICO_INTR_PE_SCE1    0x08U

/** PE_SCE2 */
#define CY_DICO_INTR_PE_SCE2    0x10U

/** Interrupt event caused by Error Observer of PCO_0 at every "num_period" switch cycles */
#define CY_DICO_INTR_PCO_0      0x20U

/** Interrupt event caused by Error Observer of PCO_1 at every "num_period" switch cycles */
#define CY_DICO_INTR_PCO_1      0x40U

/** Interrupt event caused by Error Observer of PCO_2 at every "num_period" switch cycles */
#define CY_DICO_INTR_PCO_2      0x80U

/** \} group_ppca_clb_dico_intr_status */

/** \cond INTERNAL */

#define CY_IS_PARAM_VALID(base)       (NULL != base)

/** \endcond */

/** \} group_ppca_clb_dico_macros */


/***************************************
*       Enumerations
***************************************/
/**
* \addtogroup group_ppca_clb_dico_enums
* \{
*/

/** VAC Polarity */
typedef enum
{
    CY_NEG_VAC_POL  = 0U,   /**< Negative VAC Polarity */
    CY_ZERO_VAC_POL = 1U,   /**< Zero VAC Polarity */
    CY_POS_VAC_POL  = 2U,   /**< Positive VAC Polarity */
}cy_en_ppca_clb_dico_vac_pol_t;


/** ADC FILT outputs for DICO inputs */
typedef enum
{
    CY_ADC_GROUP_0_FILT_OUT0 = 0U,   /**< Output of the ADC Group 0 ATOPSS analog
                                       *   filter chain (AFLT[0]). This is the source
                                       *   routed to the DICO IL1 input (SEL_IL0 in
                                       *   DICO_CNFG) for inductor current observation. */
    CY_ADC_GROUP_0_FILT_OUT1 = 1U,   /**< ADC_GROUP0 filter data out 1 */
    CY_ADC_GROUP_1_FILT_OUT2 = 2U,   /**< ADC_GROUP1 filter data out 2 */
    CY_ADC_GROUP_2_FILT_OUT3 = 3U,   /**< ADC_GROUP2 filter data out 3 */
    CY_ADC_GROUP_3_FILT_OUT4 = 4U,   /**< ADC_GROUP3 filter data out 4 */
    CY_ADC_GROUP_3_FILT_OUT5 = 5U,   /**< ADC_GROUP3 filter data out 5 */
}cy_en_ppca_clb_dico_adc_out_sel_t;


/** Error Observer: Number of periods to be measured */
typedef enum
{
    CY_SINGLE_PERIOD = 0U,   /**< Single Period  */
    CY_TWO_PERIODS   = 1U,   /**< Two Periods */
    CY_THREE_PERIODS = 2U,   /**< Three Periods */
    CY_FOUR_PERIODS  = 3U,   /**< Four Periods */
}cy_en_ppca_clb_dico_num_periods_t;


/** Signals to monitor */
typedef enum
{
    CY_PCO_0_SIGNALS = 0U,   /**< Monitor Phase Current Observer 0 (PCO0) Signals */
    CY_PCO_1_SIGNALS = 1U,   /**< Monitor Phase Current Observer 1 (PCO1) Signals */
    CY_PCO_2_SIGNALS = 2U,   /**< Monitor Phase Current Observer 2 (PCO2) Signals */
    CY_PE_SIGNALS    = 3U,   /**< Monitor Phase Enabler (PE) Signals */
    CY_PS_SIGNALS    = 4U,   /**< Monitor Phase Shift(PS) Signals */
}cy_en_ppca_clb_dico_monitor_sel_t;

/** \} group_ppca_clb_dico_enums */


/***************************************
*       Configuration Structures
***************************************/

/**
* \addtogroup group_ppca_clb_dico_structures
* \{
*/

/** Error Observer */
typedef struct cy_stc_ppca_clb_dico_errorObserver
{
    uint16_t   periodMeas;  /**< Measured interval time */
    uint32_t   iestIndAccu; /**< Accumulated estimated current */
    uint32_t   ilAccu;      /**< Accumulated sensored inductor current.
                             *   This value only advances while PCO switching
                             *   periods are actively running. A configured
                             *   input with no active PCO switching will not
                             *   increment this accumulator. */
}cy_stc_ppca_clb_dico_errorObserver_t;


/** Parameters for calculating Up-Slope and Down-Slope */
typedef struct cy_stc_ppca_clb_dico_up_down_config
{
    uint32_t   peIMINL;    /**< Instant IMINL for calculating up and down slope */
    uint32_t   peIMAXL;    /**< Instant IMAXL for calculating up and down slope */
    uint16_t   upCount;    /**< Count of charging phase */
    uint16_t   downCount;  /**< Count of discharging phase */
}cy_stc_ppca_clb_dico_updown_slope_param_t;


/** Phase Corrector Information for adjusting IMINL/IMAXL for PS */
typedef struct cy_stc_ppca_clb_dico_pc_info_t
{
    bool       upFlag;        /**< Indicates the phase is UP or DOWN */
    uint16_t   phaseShiftCnt; /**< Count of phase shift */
    uint16_t   periodCnt;     /**< Count of switch period */
}cy_stc_ppca_clb_dico_pc_info_t;


/** CLB DICO configuration structure */
typedef struct cy_stc_ppca_clb_dico_config
{
    bool enablePhase1;                                     /**< Phase1 enable */
    bool enablePhase2;                                     /**< Phase2 enable */
    bool enablePhase3;                                     /**< Phase3 enable */
    bool enablePhaseEnabler;                               /**< Phase Enabler (PE) Enable */
    cy_en_ppca_clb_dico_adc_out_sel_t vac;                 /**< Select Which ADC FILT out as input to VAC */
    cy_en_ppca_clb_dico_adc_out_sel_t vbus;                /**< Select Which ADC FILT out as input to VBUS */
    cy_en_ppca_clb_dico_adc_out_sel_t il1;                 /**< Select Which ADC FILT out as input to IL1 */
    cy_en_ppca_clb_dico_adc_out_sel_t il2;                 /**< Select Which ADC FILT out as input to IL2 */
    cy_en_ppca_clb_dico_adc_out_sel_t il3;                 /**< Select Which ADC FILT out as input to IL3 */
    cy_en_ppca_clb_dico_vac_pol_t vacPol;                  /**< VAC Polarity */
    cy_en_ppca_clb_dico_num_periods_t numPeriod;           /**< Error Observer: Number of periods to be measured */
    uint8_t pwmDeadTime;                                   /**< pwm Dead Time */
    bool skipslopeCal;                                     /**< Skip FSM states for calculating UP and DOWN slope */
    bool recalSlope;                                       /**< Recalculate slopes when in the state of PE_IDLE1 */
    cy_en_ppca_clb_dico_monitor_sel_t monitorSignalSel;    /**< Signals to monitor */
    bool onlyCorrCharg;                                    /**< Correct only the IMIN or IMAX reached during the charging phase. Specifically, correct IMAX when Vac < 0 and IMIN when Vac < 0. */
    uint8_t safeState;                                     /**< Safe state of DICO output. */
    uint32_t imaxl;                                        /**< maximum current */
    uint32_t iminl;                                        /**< minimum current */
    uint32_t peTPHD1;                                      /**< TPHD Value for activating PCO_1 */
    uint32_t peTPHD2;                                      /**< TPHD Value for activating PCO_2 */
    uint32_t psThld;                                       /**< Threshold for the comparator in Phase Synchronizer (PS).  */
    uint16_t pwmMaxOnTime;                                 /**< Maximum on-time, forces PWM switching when reached. The counting  frequency is equal to one quarter of the system clock. */
    uint16_t pwmMinOnTime;                                 /**< Minimum on-time, enables PWM switching when reached. The counting  frequency is equal to one quarter of the system clock. */
}cy_stc_ppca_clb_dico_config_t;
//missing: iestCorr, currCorr;

/** \} group_ppca_clb_dico_structures */


/***************************************
*        Function Prototypes
***************************************/

/**
* \addtogroup group_ppca_clb_dico_functions
* \{
*/

/* DICO */

/*******************************************************************************
* Function Name: Cy_PPCA_CLB_DICO_Enable
****************************************************************************//**
*
* Enables the DICO block. The CLB must be enabled first via
* \ref Cy_PPCA_CLB_Enable. Individual PCO phases should be enabled
* separately via \ref Cy_PPCA_CLB_DICO_ConfigPhase1,
* \ref Cy_PPCA_CLB_DICO_ConfigPhase2, \ref Cy_PPCA_CLB_DICO_ConfigPhase3.
*
* \note When DICO is enabled without any PCO phase configured, hardware
* immediately sets CY_INCORR_SETTING in DICO_STAT. This is expected
* behaviour and does not indicate a driver error. Additionally, on the
* first cold-start kill cycle (KillEvent + KillExit), DICO_STAT will
* read CY_SAFE_STATE | CY_INCORR_SETTING; CY_KILL_STATE is not set on
* the first cycle and only appears from the second kill cycle onward.
* For self-test without a live converter, configure PCO dummy switching
* to obtain a representative kill-cycle sequence and suppress
* CY_INCORR_SETTING.
*
* \param *base
* The PPCA CLB DICO registers structure pointer.
*
*******************************************************************************/
__STATIC_INLINE void Cy_PPCA_CLB_DICO_Enable(PPCA_CLB_DICO_Type *base)
{
    PPCA_CLB_DICO_CTRL(base) |= PPCA_CLB_DICO_CTRL_EN_Msk;
}


/*******************************************************************************
* Function Name: Cy_PPCA_CLB_DICO_Disable
****************************************************************************//**
*
* Disables the DICO block. When disabled, all internal registers and outputs
* are synchronously reset to 0, so DICO starts from a clean initial state
* the next time it is enabled.
*
* \param *base
* The PPCA CLB DICO registers structure pointer.
*
*******************************************************************************/
__STATIC_INLINE void Cy_PPCA_CLB_DICO_Disable(PPCA_CLB_DICO_Type *base)
{
    PPCA_CLB_DICO_CTRL(base) &= (uint32_t)~PPCA_CLB_DICO_CTRL_EN_Msk;
}


/*******************************************************************************
* Function Name: Cy_PPCA_CLB_InitConfig_DICO
****************************************************************************//**
*
* Configures the initial parameters for the DICO block including:
* - Phase enables (PCO 1/2/3) and Phase Enabler (PE)
* - ADC filter channel assignments for Vac, Vbus, iL1, iL2, iL3
* - VAC polarity, Error Observer period, PWM dead time
* - Phase Enabler slope calculation options
* - Monitor signal selection, correction charging mode
* - Safe state, IMIN/IMAX current thresholds
* - Phase delay values (TPHD) for PCO activation
* - Phase Synchronizer comparator threshold
* - PWM max/min on-time limits
*
* \param *base
* The PPCA CLB DICO registers structure pointer.
*
* \param *config
* The pointer to the CLB DICO configuration structure.
* See \ref cy_stc_ppca_clb_dico_config_t.
*
* \snippet ppca/snippet/ppca_snippet.c SNIPPET_PPCA_CLB_DICO_INIT
*
*******************************************************************************/
void Cy_PPCA_CLB_InitConfig_DICO(PPCA_CLB_DICO_Type *base, cy_stc_ppca_clb_dico_config_t const *config);


/*******************************************************************************
* Function Name: Cy_PPCA_CLB_DICO_Config_VACPol
****************************************************************************//**
*
* Configures the VAC Polarity. The polarity determines the operational mode
* of the totem-pole PFC:
* - Negative (vac_pol=0): pwm_compl represents the charging signal
* - Zero (vac_pol=1): zero-crossing range; PCO registers are synchronously reset
* - Positive (vac_pol=2): pwm represents the charging signal
*
* This value is typically set by the voltage loop in software.
*
* \param *base
* The PPCA CLB DICO registers structure pointer.
*
* \param polarity
* The VAC polarity. See \ref cy_en_ppca_clb_dico_vac_pol_t.
*
*******************************************************************************/
__STATIC_INLINE void Cy_PPCA_CLB_DICO_Config_VACPol(PPCA_CLB_DICO_Type *base, cy_en_ppca_clb_dico_vac_pol_t polarity)
{
    PPCA_CLB_DICO_VAC_POL(base) = _VAL2FLD(PPCA_CLB_DICO_VAC_POL_POL, polarity);
}


/*******************************************************************************
* Function Name: Cy_PPCA_CLB_DICO_Config_VAC_VBUS
****************************************************************************//**
*
* Configures few of the DICO inputs: VAC and VBUS
* Select ADC FILT outputs as input to VAC and VBUS.
*
* \param *base
* The PPCA CLB DICO registers structure pointer.
*
* \param vac
* The VAC. See \ref cy_en_ppca_clb_dico_adc_out_sel_t.
*
* \param vbus
* The vbus. See \ref cy_en_ppca_clb_dico_adc_out_sel_t.
*
*******************************************************************************/
__STATIC_INLINE void Cy_PPCA_CLB_DICO_Config_VAC_VBUS(PPCA_CLB_DICO_Type *base, cy_en_ppca_clb_dico_adc_out_sel_t vac, cy_en_ppca_clb_dico_adc_out_sel_t vbus)
{
    PPCA_CLB_DICO_CNFG(base) = (PPCA_CLB_DICO_CNFG(base) & ~(PPCA_CLB_DICO_CNFG_SEL_VAC_Msk | PPCA_CLB_DICO_CNFG_SEL_VBUS_Msk)) |
                               (_VAL2FLD(PPCA_CLB_DICO_CNFG_SEL_VAC, vac)) | (_VAL2FLD(PPCA_CLB_DICO_CNFG_SEL_VBUS, vbus));
}


/*******************************************************************************
* Function Name: Cy_PPCA_CLB_DICO_Config_IL1
****************************************************************************//**
*
* Configures one the DICO input IL1.
* Selects one of the ADC FILT outputs as input to IL1.
*
* \param *base
* The PPCA CLB DICO registers structure pointer.
*
* \param il1
* Phase current il1. See \ref cy_en_ppca_clb_dico_adc_out_sel_t.
*
*******************************************************************************/
__STATIC_INLINE void Cy_PPCA_CLB_DICO_Config_IL1(PPCA_CLB_DICO_Type *base, cy_en_ppca_clb_dico_adc_out_sel_t il1)
{
    PPCA_CLB_DICO_CNFG(base) = (PPCA_CLB_DICO_CNFG(base) & ~(PPCA_CLB_DICO_CNFG_SEL_IL1_Msk)) |
                               (_VAL2FLD(PPCA_CLB_DICO_CNFG_SEL_IL1, il1));
}


/*******************************************************************************
* Function Name: Cy_PPCA_CLB_DICO_Config_IL2
****************************************************************************//**
*
* Configures one the DICO input IL2.
* Selects one of the ADC FILT outputs as input to IL2.
*
* \param *base
* The PPCA CLB DICO registers structure pointer.
*
* \param il2
* Phase current il2. See \ref cy_en_ppca_clb_dico_adc_out_sel_t.
*
*******************************************************************************/
__STATIC_INLINE void Cy_PPCA_CLB_DICO_Config_IL2(PPCA_CLB_DICO_Type *base, uint8_t il2)
{
    PPCA_CLB_DICO_CNFG(base) = (PPCA_CLB_DICO_CNFG(base) & ~(PPCA_CLB_DICO_CNFG_SEL_IL2_Msk)) |
                               (_VAL2FLD(PPCA_CLB_DICO_CNFG_SEL_IL1, il2));
}


/*******************************************************************************
* Function Name: Cy_PPCA_CLB_DICO_Config_IL3
****************************************************************************//**
*
* Configures one the DICO input IL3.
* Selects one of the ADC FILT outputs as input to IL3.
*
* \param *base
* The PPCA CLB DICO registers structure pointer.
*
* \param il3
* Phase current il3. See \ref cy_en_ppca_clb_dico_adc_out_sel_t.
*
*******************************************************************************/
__STATIC_INLINE void Cy_PPCA_CLB_DICO_Config_IL3(PPCA_CLB_DICO_Type *base, uint8_t il3)
{
    PPCA_CLB_DICO_CNFG(base) = (PPCA_CLB_DICO_CNFG(base) & ~(PPCA_CLB_DICO_CNFG_SEL_IL3_Msk)) |
                               (_VAL2FLD(PPCA_CLB_DICO_CNFG_SEL_IL1, il3));
}


/*******************************************************************************
* Function Name: Cy_PPCA_CLB_DICO_ReadStatus
****************************************************************************//**
*
* Reports the statuses of DICO sub-blocks and event statuses including:
* maximum on-time reached, active state of each PCO (0/1/2), incorrect
* setting detection, mask state, kill state, safe state, and minimum
* on-time not reached.
*
* \note CY_INCORR_SETTING (bit 4) being set is expected when no PCO
* phase is configured — it does not indicate a driver or hardware fault.
* While CY_INCORR_SETTING is active, any interrupt bits written via
* \ref Cy_PPCA_CLB_DICO_SetInterrupt are cleared by hardware within
* microseconds due to a clock-domain-crossing effect. Suppress
* CY_INCORR_SETTING by enabling PCO dummy switching before relying on
* interrupt injection for self-test.
*
* \param *base
* The PPCA CLB DICO registers structure pointer.
*
* \return
* Bitwise OR of \ref group_ppca_clb_dico_status macros.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_PPCA_CLB_DICO_ReadStatus(PPCA_CLB_DICO_Type *base)
{
    return PPCA_CLB_DICO_STAT(base);
}


/*******************************************************************************
* Function Name: Cy_PPCA_CLB_DICO_WriteSafeState
****************************************************************************//**
*
* Writes the safe state of the DICO output. During mask or kill events,
* the DICO output (pwm and pwm_compl) is driven by this safe state value
* instead of the normal PCO-generated PWM signals. The safe state protects
* the power plant by ensuring MOSFETs are in a known-safe switch configuration.
*
* \param *base
* The PPCA CLB DICO registers structure pointer.
*
* \param state
* Safe state value for the DICO output.
*
*******************************************************************************/
__STATIC_INLINE void Cy_PPCA_CLB_DICO_WriteSafeState(PPCA_CLB_DICO_Type *base, uint8_t state)
{
    PPCA_CLB_DICO_SAFE(base) = (PPCA_CLB_DICO_SAFE(base) & ~(PPCA_CLB_DICO_SAFE_STATE_Msk)) |
                               (_VAL2FLD(PPCA_CLB_DICO_SAFE_STATE, state));
}


/*******************************************************************************
* Function Name: Cy_PPCA_CLB_DICO_KillEvent
****************************************************************************//**
*
* Triggers the kill event for DICO. The kill event can also originate from
* the EPU. When asserted, DICO enters the kill state and its pwm/pwm_compl
* outputs are driven by the SAFE_REG. DICO continues running internally.
* To exit, the kill event must be de-asserted and \ref Cy_PPCA_CLB_DICO_KillExit
* must be called.
*
* \param *base
* The PPCA CLB DICO registers structure pointer.
*
*******************************************************************************/
__STATIC_INLINE void Cy_PPCA_CLB_DICO_KillEvent(PPCA_CLB_DICO_Type *base)
{
    PPCA_CLB_DICO_EVENT(base) = PPCA_CLB_DICO_EVENT_KILL_EVENT_Msk;
}


/*******************************************************************************
* Function Name: Cy_PPCA_CLB_DICO_KillExit
****************************************************************************//**
*
* Exits the kill state for DICO. The KILL_EVENT from CPU or EPU must be
* de-asserted before or at the same time as calling this function.
* After exiting kill, DICO outputs remain driven by SAFE_REG until the
* rising edge of the charging signal.
*
* \param *base
* The PPCA CLB DICO registers structure pointer.
*
*******************************************************************************/
__STATIC_INLINE void Cy_PPCA_CLB_DICO_KillExit(PPCA_CLB_DICO_Type *base)
{
    PPCA_CLB_DICO_EVENT(base) = PPCA_CLB_DICO_EVENT_KILL_EXIT_Msk;
}


/*******************************************************************************
* Function Name: Cy_PPCA_CLB_DICO_AtomicRead_ErrorObserver_Values
****************************************************************************//**
*
* Atomically reads Error Observer values for the specified PCO phase.
* Uses the freeze mechanism to ensure consistent reading of il_accu,
* iest_ind_accu, and period_meas. While frozen, these registers cannot
* be updated by hardware; shadow registers ensure no updates are lost.
*
* The CPU uses these values to compute the PI controller correction
* that minimizes the error between estimated and sensed inductor current.
*
* \param *base
* The PPCA CLB DICO registers structure pointer.
*
* \param phaseNum
* The PCO phase number (1 = PCO_0, 2 = PCO_1, 3 = PCO_2).
*
* \param *read
* The pointer to store the Error Observer values.
* See \ref cy_stc_ppca_clb_dico_errorObserver_t.
*
*******************************************************************************/
__STATIC_INLINE void Cy_PPCA_CLB_DICO_AtomicRead_ErrorObserver_Values(PPCA_CLB_DICO_Type *base, uint8_t phaseNum, cy_stc_ppca_clb_dico_errorObserver_t *read)
{
    PPCA_CLB_DICO_OBS_CTRL(base) = 1UL << (phaseNum - 1UL);
    read->periodMeas = (uint16_t)(PPCA_CLB_DICO_PERIOD_MEAS(base, (phaseNum - 1UL)));
    read->iestIndAccu = PPCA_CLB_DICO_IEST_IND_ACCU(base, (phaseNum - 1UL));
    read->ilAccu     = PPCA_CLB_DICO_IL_ACCU(base, (phaseNum - 1UL));
    PPCA_CLB_DICO_OBS_CTRL(base) = 0UL;
}


/*******************************************************************************
* Function Name: Cy_PPCA_CLB_DICO_Config_Switching_Period
****************************************************************************//**
*
* Configures the switching period, "num_period". If the "num_period"
* period is reached, the Error Observer triggers an interrupt and
* synchronously resets the counter and both accumulators in Error Observer. 
*
* \param *base
* The PPCA CLB DICO registers structure pointer.
*
* \param numPeriod
* The number of periods over which the error is computed. //tbc
* \ref cy_en_ppca_clb_dico_num_periods_t .
*
* \note
* The observer integrates the digitalized input current and the 
* estimated input current, then it computes the error over a 
* defined interval time (the switching period or multiple switching period),
* finally it computes a correction value to be applied 
* to the Estimator by mean of PID filter.
*******************************************************************************/
__STATIC_INLINE void Cy_PPCA_CLB_DICO_Config_Switching_Period(PPCA_CLB_DICO_Type *base, cy_en_ppca_clb_dico_num_periods_t numPeriod)
{
    PPCA_CLB_DICO_CNFG(base) = (PPCA_CLB_DICO_CNFG(base) & ~(PPCA_CLB_DICO_CNFG_NUM_OF_MEAS_PERIOD_Msk)) |
                               (_VAL2FLD(PPCA_CLB_DICO_CNFG_NUM_OF_MEAS_PERIOD, numPeriod));
}


/*******************************************************************************
* Function Name: Cy_PPCA_CLB_DICO_Config_CorrectionValue
****************************************************************************//**
*
* Writes the correction value to current observer that measures voltages.
*
* \param *base
* The PPCA CLB DICO registers structure pointer.
*
* \param phaseNum
* The inductor current phase number.
* Range 1 - 3.
*
* \param iestCorr
* The correction for adjusting the estimated current.
*
*******************************************************************************/
__STATIC_INLINE void Cy_PPCA_CLB_DICO_Config_CorrectionValue(PPCA_CLB_DICO_Type *base, uint8_t phaseNum, uint16_t iestCorr)
{
    PPCA_CLB_DICO_IEST_CORR(base, (phaseNum - 1U)) = iestCorr;
}


/*******************************************************************************
* Function Name: Cy_PPCA_CLB_DICO_Config_PWM_Deadtime
****************************************************************************//**
*
* Configures the PWM Modulator dead time. Dead time is inserted when the
* [pwm, pwm_compl] signal transitions between [0,1] and [1,0]. During
* dead time, both outputs are forced to [0,0] to prevent shoot-through
* conditions where both switches are simultaneously ON.
*
* \param *base
* The PPCA CLB DICO registers structure pointer.
*
* \param pwmDeadTime
* The PWM dead time value in system clock cycles.
*
*******************************************************************************/
__STATIC_INLINE void Cy_PPCA_CLB_DICO_Config_PWM_Deadtime(PPCA_CLB_DICO_Type *base, uint8_t pwmDeadTime)
{
    PPCA_CLB_DICO_CNFG(base) = (PPCA_CLB_DICO_CNFG(base) & ~(PPCA_CLB_DICO_CNFG_PWM_DEADTIME_Msk)) |
                               (_VAL2FLD(PPCA_CLB_DICO_CNFG_PWM_DEADTIME, pwmDeadTime));
}


/*******************************************************************************
* Function Name: Cy_PPCA_CLB_DICO_Config_MaxCurrent
****************************************************************************//**
*
* Configures the maximum inductor current for the 
* modulator setting: IMAX_ANA * L * F * ADC_GAIN.
*
* \param *base
* The PPCA CLB DICO registers structure pointer.
*
* \param imaxl
* The maximum inductor current for the modulator setting.
*
*******************************************************************************/
__STATIC_INLINE void Cy_PPCA_CLB_DICO_Config_MaxCurrent(PPCA_CLB_DICO_Type *base, uint32_t imaxl)
{
    PPCA_CLB_DICO_IMAXL(base) = imaxl;
}


/*******************************************************************************
* Function Name: Cy_PPCA_CLB_DICO_Config_MinCurrent
****************************************************************************//**
*
* Configures the minimum inductor current for the 
* modulator setting: IMIN_ANA * L * F *  ADC_GAIN
*
* \param *base
* The PPCA CLB DICO registers structure pointer.
*
* \param iminl
* The  minimum inductor current for the modulator setting.
*
*******************************************************************************/
__STATIC_INLINE void Cy_PPCA_CLB_DICO_Config_MinCurrent(PPCA_CLB_DICO_Type *base, uint32_t iminl)
{
    PPCA_CLB_DICO_IMINL(base) = iminl;
}


/*******************************************************************************
* Function Name: Cy_PPCA_CLB_DICO_Config_CorrectionCharg
****************************************************************************//**
*
* Configures to which signal an available correction from 
* phase synchronizer is applied to.
*
* \param *base
* The PPCA CLB DICO registers structure pointer.
*
* \param onlyCorrCharg
* false: the correction is applied to the upcoming IMIN or IMAX,
*        whichever comes first.
* true: the correction is applied to the upcoming IMAX when Vac is positive 
*       or the upcoming IMIN when Vac is negative.
*
*******************************************************************************/
__STATIC_INLINE void Cy_PPCA_CLB_DICO_Config_CorrectionCharg(PPCA_CLB_DICO_Type *base, uint8_t onlyCorrCharg)
{
    PPCA_CLB_DICO_CNFG(base) = (PPCA_CLB_DICO_CNFG(base) & ~(PPCA_CLB_DICO_CNFG_ONLY_CORR_CHARG_Msk)) |
                               (_VAL2FLD(PPCA_CLB_DICO_CNFG_ONLY_CORR_CHARG, onlyCorrCharg));
}


/*******************************************************************************
* Function Name: Cy_PPCA_CLB_DICO_Config_Max_Min_OnTime
****************************************************************************//**
*
* Configures the Maximum on-time which forces PWM switching when reached and
* Minimum on-time which enables PWM switching when reached.
*
* \param *base
* The PPCA CLB DICO registers structure pointer.
*
* \param maxOnTime
* The Maximum on-time which forces PWM switching when reached.
*
* \param minOnTime
* The Minimum on-time which enables PWM switching when reached.
*
* \note
* The counting frequency is equal to one quarter of the system clock.
*
*******************************************************************************/
__STATIC_INLINE void Cy_PPCA_CLB_DICO_Config_Max_Min_OnTime(PPCA_CLB_DICO_Type *base, uint32_t maxOnTime, uint32_t minOnTime)
{
    PPCA_CLB_DICO_SAFE(base) = (PPCA_CLB_DICO_SAFE(base) & ~(PPCA_CLB_DICO_SAFE_MAX_ON_TIME_Msk | PPCA_CLB_DICO_SAFE_MIN_ON_TIME_Msk)) |
                               (_VAL2FLD(PPCA_CLB_DICO_SAFE_MAX_ON_TIME, maxOnTime)) | (_VAL2FLD(PPCA_CLB_DICO_SAFE_MIN_ON_TIME, minOnTime));
}


/*******************************************************************************
* Function Name: Cy_PPCA_CLB_DICO_EnablePhaseEnabler
****************************************************************************//**
*
* Enables the Phase Enabler (PE) block of the Multi-Phase Adapter.
* The PE is only active when at least two PCOs are required. It controls
* the insertion of the 2nd and 3rd phase PCOs at the appropriate time
* to reduce overall current ripple and improve power factor.
*
* \param *base
* The PPCA CLB DICO registers structure pointer.
*
*******************************************************************************/
__STATIC_INLINE void Cy_PPCA_CLB_DICO_EnablePhaseEnabler(PPCA_CLB_DICO_Type *base)
{
    PPCA_CLB_DICO_CTRL(base) = (PPCA_CLB_DICO_CTRL(base) & ~(PPCA_CLB_DICO_CTRL_PE_EN_Msk)) |
                               (_VAL2FLD(PPCA_CLB_DICO_CTRL_PE_EN, 1UL));
}


/*******************************************************************************
* Function Name: Cy_PPCA_CLB_DICO_DisablePhaseEnabler
****************************************************************************//**
*
* Disables the Phase Enabler.
*
* \param *base
* The PPCA CLB DICO registers structure pointer.
*
*******************************************************************************/
__STATIC_INLINE void Cy_PPCA_CLB_DICO_DisablePhaseEnabler(PPCA_CLB_DICO_Type *base)
{
    PPCA_CLB_DICO_CTRL(base) = (PPCA_CLB_DICO_CTRL(base) & ~(PPCA_CLB_DICO_CTRL_PE_EN_Msk)) |
                               (_VAL2FLD(PPCA_CLB_DICO_CTRL_PE_EN, 0UL));
}


/*******************************************************************************
* Function Name: Cy_PPCA_CLB_DICO_ConfigPhaseEnabler
****************************************************************************//**
*
* Configures the Phase Enabler parameters.
*
* \param *base
* The PPCA CLB DICO registers structure pointer.
*
* \param skipSlopeCal
* If true, skips FSM states for calculating UP and DOWN slope.
*
* \param recalSlope
* If true, recalculates slopes when in the state of PE_IDLE1.
*
*******************************************************************************/
__STATIC_INLINE void Cy_PPCA_CLB_DICO_ConfigPhaseEnabler(PPCA_CLB_DICO_Type *base, bool skipSlopeCal, bool recalSlope)
{
    PPCA_CLB_DICO_CNFG(base) = (PPCA_CLB_DICO_CNFG(base) & ~(PPCA_CLB_DICO_CNFG_PE_SKIP_SLOPE_Msk | PPCA_CLB_DICO_CNFG_PE_IDLE1_RECAL_SLOPE_Msk)) |
                               (_VAL2FLD(PPCA_CLB_DICO_CNFG_PE_SKIP_SLOPE, skipSlopeCal)) | (_VAL2FLD(PPCA_CLB_DICO_CNFG_PE_IDLE1_RECAL_SLOPE, recalSlope));
}


/*******************************************************************************
* Function Name: Cy_PPCA_CLB_DICO_ConfigPhase1
****************************************************************************//**
*
* Enables/Disables Phase 1.
*
* \param *base
* The PPCA CLB DICO registers structure pointer.
*
* \param enable
* true: Enable Phase 1.
* false: Disable Phase 1.
*
* \note When Phase 1 is enabled, the DICO state machine generates Phase-Shift
* (PS) interrupt bits (e.g. \ref CY_DICO_INTR_PS_0, \ref CY_DICO_INTR_PS_1)
* autonomously, driven by the internal MAX_ON_TIME counter (Fsys/4 clock).
* These interrupts reflect completed switching cycles measured by the timer and
* are independent of current accumulation — they fire even when FILT_OUT = 0
* and no live converter is present. With a small MAX_ON_TIME value (~50), the
* first PS interrupt typically fires within ~200 us of enabling Phase 1.
*
*******************************************************************************/
__STATIC_INLINE void Cy_PPCA_CLB_DICO_ConfigPhase1(PPCA_CLB_DICO_Type *base, bool enable)
{
    PPCA_CLB_DICO_CTRL(base) = (PPCA_CLB_DICO_CTRL(base) & ~(PPCA_CLB_DICO_CTRL_EN_PH1_Msk)) |
                               (_BOOL2FLD(PPCA_CLB_DICO_CTRL_EN_PH1, enable));
}


/*******************************************************************************
* Function Name: Cy_PPCA_CLB_DICO_ConfigPhase2
****************************************************************************//**
*
* Enables/Disables Phase 2.
*
* \param *base
* The PPCA CLB DICO registers structure pointer.
*
* \param enable
* true: Enable Phase 2.
* false: Disable Phase 2.
*
*******************************************************************************/
__STATIC_INLINE void Cy_PPCA_CLB_DICO_ConfigPhase2(PPCA_CLB_DICO_Type *base, bool enable)
{
    PPCA_CLB_DICO_CTRL(base) = (PPCA_CLB_DICO_CTRL(base) & ~(PPCA_CLB_DICO_CTRL_EN_PH2_Msk)) |
                               (_BOOL2FLD(PPCA_CLB_DICO_CTRL_EN_PH2, enable));
}


/*******************************************************************************
* Function Name: Cy_PPCA_CLB_DICO_ConfigPhase3
****************************************************************************//**
*
* Enables/Disables Phase 3.
*
* \param *base
* The PPCA CLB DICO registers structure pointer.
*
* \param enable
* true: Enable Phase 3.
* false: Disable Phase 3.
*
*******************************************************************************/
__STATIC_INLINE void Cy_PPCA_CLB_DICO_ConfigPhase3(PPCA_CLB_DICO_Type *base, bool enable)
{
    PPCA_CLB_DICO_CTRL(base) = (PPCA_CLB_DICO_CTRL(base) & ~(PPCA_CLB_DICO_CTRL_EN_PH3_Msk)) |
                               (_BOOL2FLD(PPCA_CLB_DICO_CTRL_EN_PH3, enable));
}


/*******************************************************************************
* Function Name: Cy_PPCA_CLB_DICO_Config_TPHD_PCO1
****************************************************************************//**
*
* Configures the TPHD value for activating the PCO_1.
*
* \param *base
* The PPCA CLB DICO registers structure pointer.
*
*\param tphd
* The TPHD(Time of phase delay) value for activating the PCO_1.
*
* \param pending
* true: The TPHD value is valid.
* false: The TPHD value is no more valid.
*
*******************************************************************************/
__STATIC_INLINE void Cy_PPCA_CLB_DICO_Config_TPHD_PCO1(PPCA_CLB_DICO_Type *base, uint32_t tphd, bool pending)
{
    PPCA_CLB_DICO_PE_TPHD_1(base) = (PPCA_CLB_DICO_PE_TPHD_1(base) & ~(PPCA_CLB_DICO_PE_TPHD_1_TPHD_1_Msk | PPCA_CLB_DICO_PE_TPHD_1_PENDING_1_Msk)) |
                                    (_VAL2FLD(PPCA_CLB_DICO_PE_TPHD_1_TPHD_1, tphd)) | (_BOOL2FLD(PPCA_CLB_DICO_PE_TPHD_1_PENDING_1, pending));
}


/*******************************************************************************
* Function Name: Cy_PPCA_CLB_DICO_Config_TPHD_PCO2
****************************************************************************//**
*
* Configures the TPHD value for activating the PCO_2.
*
* \param *base
* The PPCA CLB DICO registers structure pointer.
*
*\param tphd
* The TPHD(Time of phase delay) value for activating the PCO_2.
*
* \param pending
* true: The TPHD value is valid.
* false: The TPHD value is no more valid.
*
*******************************************************************************/
__STATIC_INLINE void Cy_PPCA_CLB_DICO_Config_TPHD_PCO2(PPCA_CLB_DICO_Type *base, uint32_t tphd, bool pending)
{
    PPCA_CLB_DICO_PE_TPHD_2(base) = (PPCA_CLB_DICO_PE_TPHD_2(base) & ~(PPCA_CLB_DICO_PE_TPHD_2_TPHD_2_Msk | PPCA_CLB_DICO_PE_TPHD_2_PENDING_2_Msk)) |
                                    (_VAL2FLD(PPCA_CLB_DICO_PE_TPHD_2_TPHD_2, tphd)) | (_BOOL2FLD(PPCA_CLB_DICO_PE_TPHD_2_PENDING_2, pending));
}


/*******************************************************************************
* Function Name: Cy_PPCA_CLB_DICO_Read_UpDown_Slope_Params
****************************************************************************//**
*
* Reads the parameters required for Up and Down Slope calculation.
*
* \param *base
* The PPCA CLB DICO registers structure pointer.
*
*\param *params
* The pointer to the location to store the Read parameters.
* \ref cy_stc_ppca_clb_dico_updown_slope_param_t.
*
*******************************************************************************/
__STATIC_INLINE void Cy_PPCA_CLB_DICO_Read_UpDown_Slope_Params(PPCA_CLB_DICO_Type *base, cy_stc_ppca_clb_dico_updown_slope_param_t *params)
{
    params->peIMINL   = PPCA_CLB_DICO_PE_IMINL(base);
    params->peIMAXL   = PPCA_CLB_DICO_PE_IMAXL(base);
    params->upCount   = (uint16_t) PPCA_CLB_DICO_PE_UP_COUNT(base);
    params->downCount = (uint16_t) PPCA_CLB_DICO_PE_DN_COUNT(base);
}


/*******************************************************************************
* Function Name: Cy_PPCA_CLB_DICO_Config_PS_ComparatorTH
****************************************************************************//**
*
* Configures the threshold for the anti-jitter comparator in the Phase
* Synchronizer (PS). The PS maintains the required phase offset between
* phase-currents (180 degrees for two-phase, 120 degrees for three-phase)
* by adjusting IMIN/IMAX of each PCO.
*
* \param *base
* The PPCA CLB DICO registers structure pointer.
*
* \param threshold
* The threshold value for the PS comparator.
*
*******************************************************************************/
__STATIC_INLINE void Cy_PPCA_CLB_DICO_Config_PS_ComparatorTH(PPCA_CLB_DICO_Type *base, uint32_t threshold)
{
    PPCA_CLB_DICO_PS_TH(base) = threshold;
}


/*******************************************************************************
* Function Name: Cy_PPCA_CLB_DICO_Read_PhaseCorrector1_Info
****************************************************************************//**
*
* Provides IMINL/IMAXL Current Correction Information for Phase Corrector 1
* of the Phase Synchronizer (PS).
*
* \param *base
* The PPCA CLB DICO registers structure pointer.
*
*\param *info
* The pointer to the location to store the Phase Corrector Information 
* for adjusting IMINL/IMAXL for PS. \ref cy_stc_ppca_clb_dico_pc_info_t.
*
*******************************************************************************/
__STATIC_INLINE void Cy_PPCA_CLB_DICO_Read_PhaseCorrector1_Info(PPCA_CLB_DICO_Type *base, cy_stc_ppca_clb_dico_pc_info_t *info )
{
    info->upFlag = _FLD2BOOL(PPCA_CLB_DICO_PS_CC_INFO_UP_FLAG, PPCA_CLB_DICO_PS_CC_INFO(base, 0U));
    info->phaseShiftCnt = (uint16_t)(_FLD2VAL(PPCA_CLB_DICO_PS_CC_INFO_PHASE_SHIFT_COUNT, PPCA_CLB_DICO_PS_CC_INFO(base, 0U)));
    info->periodCnt = (uint16_t)(_FLD2VAL(PPCA_CLB_DICO_PS_CC_INFO_PERIOD_COUNT, PPCA_CLB_DICO_PS_CC_INFO(base, 0U)));
}


/*******************************************************************************
* Function Name: Cy_PPCA_CLB_DICO_Read_PhaseCorrector2_Info
****************************************************************************//**
*
* Provides IMINL/IMAXL Current Correction Information for Phase Corrector 2 
* of the Phase Synchronizer (PS).
*
* \param *base
* The PPCA CLB DICO registers structure pointer.
*
*\param *info
* The pointer to the location to store the Phase Corrector Information 
* for adjusting IMINL/IMAXL for PS. \ref cy_stc_ppca_clb_dico_pc_info_t.
*
*******************************************************************************/
__STATIC_INLINE void Cy_PPCA_CLB_DICO_Read_PhaseCorrector2_Info(PPCA_CLB_DICO_Type *base, cy_stc_ppca_clb_dico_pc_info_t *info )
{
    info->upFlag = _FLD2BOOL(PPCA_CLB_DICO_PS_CC_INFO_UP_FLAG, PPCA_CLB_DICO_PS_CC_INFO(base, 1U));
    info->phaseShiftCnt = (uint16_t)(_FLD2VAL(PPCA_CLB_DICO_PS_CC_INFO_PHASE_SHIFT_COUNT, PPCA_CLB_DICO_PS_CC_INFO(base, 1U)));
    info->periodCnt = (uint16_t)(_FLD2VAL(PPCA_CLB_DICO_PS_CC_INFO_PERIOD_COUNT, PPCA_CLB_DICO_PS_CC_INFO(base, 1U)));
}


/*******************************************************************************
* Function Name: Cy_PPCA_CLB_DICO_Config_PhaseShift_CC1
****************************************************************************//**
*
* Configures Phase Shift Information for adjusting IMINL/IMAXL
* for Phase Shift 1 of the Phase synchronizer (PS).
*
* \param *base
* The PPCA CLB DICO registers structure pointer.
*
*\param currCorr
* The Correction term of IMINL and IMAXL for DICO.
*
* \param pending
* true: Correction value is valid.
* false: Correction value is no more valid.
*
*******************************************************************************/
__STATIC_INLINE void Cy_PPCA_CLB_DICO_Config_PhaseShift_CC1(PPCA_CLB_DICO_Type *base, uint32_t currCorr, bool pending)
{
    PPCA_CLB_DICO_PS_CC(base, 0U) = _BOOL2FLD(PPCA_CLB_DICO_PS_CC_CC_PENDING, pending) |
                                    _VAL2FLD(PPCA_CLB_DICO_PS_CC_CORR_CURR, currCorr);
}


/*******************************************************************************
* Function Name: Cy_PPCA_CLB_DICO_Config_PhaseShift_CC2
****************************************************************************//**
*
* Configures Phase Shift Information for adjusting IMINL/IMAXL
* for Phase Shift 2 of the Phase synchronizer (PS).
*
* \param *base
* The PPCA CLB DICO registers structure pointer.
*
*\param currCorr
* The Correction term of IMINL and IMAXL for DICO.
*
* \param pending
* true: Correction value is valid.
* false: Correction value is no more valid.
*
*******************************************************************************/
__STATIC_INLINE void Cy_PPCA_CLB_DICO_Config_PhaseShift_CC2(PPCA_CLB_DICO_Type *base,  uint32_t currCorr, bool pending)
{
    PPCA_CLB_DICO_PS_CC(base, 1U) = _BOOL2FLD(PPCA_CLB_DICO_PS_CC_CC_PENDING, pending) |
                                   _VAL2FLD(PPCA_CLB_DICO_PS_CC_CORR_CURR, currCorr);
}


/*******************************************************************************
* Function Name: Cy_PPCA_CLB_DICO_Read_Corrected_IEst
****************************************************************************//**
*
* Reads the corrected estimated current.
*
* \param *base
* The PPCA CLB DICO registers structure pointer.
*
* \param phaseNum
* The inductor current phase number.
* Range 1 - 3.
*
* \return
* The Corrected estimated current.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_PPCA_CLB_DICO_Read_Corrected_IEst(PPCA_CLB_DICO_Type *base, uint8_t phaseNum)
{
    return PPCA_CLB_DICO_PCO_CORR_IEST(base, (phaseNum - 1UL));
}


/******************************************************************************
* Function Name: Cy_PPCA_CLB_DICO_GetInterruptStatus
****************************************************************************//**
*
* Returns the interrupt request register. This register contains the current
* status of the interrupt sources.
*
* \note Phase-Shift interrupt bits (\ref CY_DICO_INTR_PS_0,
* \ref CY_DICO_INTR_PS_1) and PCO Error Observer interrupt bits
* (\ref CY_DICO_INTR_PCO_0, \ref CY_DICO_INTR_PCO_1,
* \ref CY_DICO_INTR_PCO_2) are generated autonomously by the DICO state
* machine and reflect completed switching cycles measured by the MAX_ON_TIME
* timer (Fsys/4 clock). These bits fire independently of current accumulation
* — they will assert even when FILT_OUT = 0 and no live converter is present.
* See \ref Cy_PPCA_CLB_DICO_ConfigPhase1 for details.
*
* \note If called immediately after \ref Cy_PPCA_CLB_DICO_SetInterrupt or
* \ref Cy_PPCA_CLB_DICO_ClearInterrupt, this function may return stale data.
* DICO interrupt registers are clocked in the DICO hardware clock domain and
* require at least 5 us to synchronise to the CPU clock domain after any
* write to INTR_SET or INTR (write-1-to-clear).
*
* \param *base
* The PPCA CLB DICO registers structure pointer.
*
* \return
* The current status of the interrupt source.
* \ref group_ppca_clb_dico_intr_status.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_PPCA_CLB_DICO_GetInterruptStatus(PPCA_CLB_DICO_Type *base)
{
    return (PPCA_CLB_DICO_INTR(base));
}


/*******************************************************************************
* Function Name: Cy_PPCA_CLB_DICO_ClearInterrupt
****************************************************************************//**
*
* Clears the interrupt sources in the interrupt request register.
*
* \note DICO interrupt registers are clocked in the DICO hardware clock
* domain. After writing to INTR (write-1-to-clear), wait at least 5 us
* before reading INTR, INTR_MASK, or INTR_MASKED to allow clock-domain
* synchronisation. Reading too soon returns stale data (observed on
* PSC3M8-A0). The delay belongs in the caller — do not assume the bit
* has cleared on an immediate readback.
*
* \param base
* The PPCA CLB DICO registers structure pointer.
*
* \param interruptMask
* The interrupt sources to be cleared.
* \ref group_ppca_clb_dico_intr_status.
*
*******************************************************************************/
__STATIC_INLINE void Cy_PPCA_CLB_DICO_ClearInterrupt(PPCA_CLB_DICO_Type *base, uint32_t interruptMask)
{
    PPCA_CLB_DICO_INTR(base) = interruptMask;
}


/*******************************************************************************
* Function Name: Cy_PPCA_CLB_DICO_SetInterrupt
****************************************************************************//**
*
* Sets slave interrupt sources in the interrupt request register.
*
* \note Interrupt bits set by this function may be cleared by hardware
* within microseconds while CY_INCORR_SETTING is active in DICO_STAT
* (which occurs when no PCO phase is configured). This is a
* clock-domain-crossing effect. Enable PCO dummy switching to suppress
* CY_INCORR_SETTING before using this function for interrupt injection
* testing.
*
* \note DICO interrupt registers are clocked in the DICO hardware clock
* domain. After writing to INTR_SET, wait at least 5 us before reading
* INTR, INTR_MASK, or INTR_MASKED to allow clock-domain synchronisation.
* An immediate \ref Cy_PPCA_CLB_DICO_GetInterruptStatus after this call
* will return 0x00 — the bit has not yet propagated across the clock-domain
* boundary (observed on PSC3M8-A0).
*
* \param base
* The PPCA CLB DICO registers structure pointer.
*
* \param interruptMask
* The interrupt sources to set in the interrupt request register.
* \ref group_ppca_clb_dico_intr_status.
*
*******************************************************************************/
__STATIC_INLINE void Cy_PPCA_CLB_DICO_SetInterrupt(PPCA_CLB_DICO_Type *base, uint32_t interruptMask)
{
    PPCA_CLB_DICO_INTR_SET(base) = interruptMask;
}


/*******************************************************************************
* Function Name: Cy_PPCA_CLB_DICO_GetInterruptMask
****************************************************************************//**
*
* Returns the interrupt mask register.
* This register specifies which bits from the interrupt request register
* can trigger an interrupt event.
*
* \param base
* The PPCA CLB DICO registers structure pointer.
*
* \return
* Enabled interrupt sources.
* \ref group_ppca_clb_dico_intr_status.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_PPCA_CLB_DICO_GetInterruptMask(PPCA_CLB_DICO_Type *base)
{
    return (PPCA_CLB_DICO_INTR_MASK(base));
}

/*******************************************************************************
* Function Name: Cy_PPCA_CLB_DICO_SetInterruptMask
****************************************************************************//**
*
* Writes the DICO interrupt mask register.
* This register specifies which bits from the interrupt request register
* can trigger an interrupt event.
*
* \param base
* The PPCA CLB DICO registers structure pointer.
*
* \param interruptMask
* Enabled interrupt sources.
* \ref group_ppca_clb_dico_intr_status.
*
*******************************************************************************/
__STATIC_INLINE void Cy_PPCA_CLB_DICO_SetInterruptMask(PPCA_CLB_DICO_Type *base, uint32_t interruptMask)
{
    PPCA_CLB_DICO_INTR_MASK(base) = interruptMask;
}


/*******************************************************************************
* Function Name: Cy_PPCA_CLB_DICO_GetInterruptStatusMasked
****************************************************************************//**
*
* Returns the DICO interrupt masked request register. This register contains
* a logical AND of corresponding bits from the interrupt request and mask
* registers.
* This function is intended to be used in the interrupt service routine to
* identify which of enabled DICO interrupt sources caused the interrupt
* event.
*
* \param base
* The PPCA CLB DICO registers structure pointer.
*
* \return
* The current status of enabled interrupt sources.
* \ref group_ppca_clb_dico_intr_status.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_PPCA_CLB_DICO_GetInterruptStatusMasked(PPCA_CLB_DICO_Type *base)
{
    return (PPCA_CLB_DICO_INTR_MASKED(base));
}

/** \} group_ppca_clb_dico_functions */

#if defined(__cplusplus)
}
#endif

#endif /* #if defined(CY_IP_MXS40PPSS) */

#endif /* (CY_PPCA_CLB_H) */

/** \} group_ppca_clb_dico */

/* [] END OF FILE */
