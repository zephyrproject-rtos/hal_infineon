/***************************************************************************//**
* \file cy_ppca_cnfg.h
* \version 1.0
*
* Provides the API declarations of the PPCA CNFG driver.
*
********************************************************************************
* \copyright
* (c) 2017-2026, Infineon Technologies AG or an affiliate of
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
* \addtogroup group_ppca
* \{
* The Programmable Power Control Accelerator (PPCA) PDL driver provides API to use the
* PPCA hardware block.
*
* The PPCA is a programmable subsystem supporting the implementation of AC/DC, DC/AC,
* DC/DC and Switch Mode Power Supply (SMPS) digital control solutions. It operates as an
* autonomous subsystem with its own CPUs, memory, and peripherals optimized for real-time
* power conversion control loops.
*
* \section group_ppca_glossary Glossary
*
* <b>PPCPUSS</b> (CPU Subsystem):
* - Two ARM Cortex-M33 processors (CPU0 and CPU1) with local infrastructure
* - AHB5 bus matrix supporting external slave and external master interfaces
* - IPC (Inter-Processor Communication) for CPU0/CPU1 coordination
* - 5 SRAM controllers with ECC (configurable code and data memory partitions)
*
* <b>Peripheral Subsystem</b>:
* - PPSS_CNFG: Configuration block for peripheral allocation, CPU control, triggers, and interrupts
* - EPU (Event Processing Unit): Hardware event routing and processing
* - ATOPSS (Analog Top SubSystem): Contains 4 ADCs, 9 DCSGs, 2 R2R-DACs, 1 IDAC, AREF, TSNS, analog MUXes
* - HWFILT3P3Z: Hardware 3-Pole/3-Zero IIR compensator filters
* - CLB (Custom Logic Block): DICO and MACO subsystems for power conversion control
* - MXTCPWM: Configurable high-resolution PWM timers
* - CORDIC: Two CORDIC math accelerator modules
* - ADC Mirror: Provides shadow copies of ADC data for multi-core access
*
* <b>Clocking</b>:
* - PPSS_CLK: Main clock input (max 200 MHz) - drives CPU0, CPU1, and all digital peripherals
* - ATOP_CLK: Derived from PPSS_CLK through a fixed divide-by-2, feeds ADCs and DACs
* - DCSG_CLK: Derived from PPSS_CLK, feeds the DCSG analog comparators
*
* <b>Trigger Bus</b>:
* - TR_PPSSOUT[255:0]: Collects events from all PPSS peripherals (ADC EOC, DCMP outputs,
*   DCSG comparator outputs, CLB outputs, EPU events, HW filter completion, CORDIC done, etc.)
*   and exports them for inter-peripheral triggering and external system integration
*

*******************************************************************************
* \section group_ppca_changelog Changelog
*******************************************************************************
* <table class="doxtable">
*   <tr><th>Version</th><th>Changes</th><th>Reason for Change</th></tr>
*   <tr>
*     <td rowspan="1">1.0</td>
*     <td>Initial version.</td>
*     <td></td>
*   </tr>
* </table>
*
* \defgroup group_ppca_cnfg CNFG (Programmable Power Control Accelerator Configuration)
* \{
*   \section group_ppca_cnfg_overview Overview
*   The PPCA CNFG block provides configuration, control, and interrupt management
*   for the PPCA subsystem. It includes peripheral allocation between PPCA CPU0
*   and CPU1, CPU clock and reset control, and interrupt forwarding from the
*   PPCA subsystem to the host CM33 via S2IRQ (Subsystem-to-IRQ) channels.
*
*   \section group_ppca_cnfg_interrupts Interrupt Sources
*   The PPCA CNFG provides 7 interrupt sources, each mapped to a dedicated S2IRQ
*   register block. These interrupts are forwarded from the PPCA subsystem to the
*   host CM33 NVIC.
*
*   | S2IRQ Index | Enum Value                  | Host IRQn                      | Description                                    |
*   |:-----------:|:---------------------------:|:------------------------------:|:-----------------------------------------------|
*   | 0           | CY_IRQ_RDY_FOR_DEEPSLEEP    | ppca_cnfg_rdy_for_dslp_IRQn    | PPCA ready for DeepSleep                       |
*   | 1           | CY_IRQ_PPCA_CPU0_CTI_0      | ppca_cpu0_cti_0_IRQn           | CPU0 Cross-Trigger Interface channel 0         |
*   | 2           | CY_IRQ_PPCA_CPU0_CTI_1      | ppca_cpu0_cti_1_IRQn           | CPU0 Cross-Trigger Interface channel 1         |
*   | 3           | CY_IRQ_PPCA_CPU1_CTI_0      | ppca_cpu1_cti_0_IRQn           | CPU1 Cross-Trigger Interface channel 0         |
*   | 4           | CY_IRQ_PPCA_CPU1_CTI_1      | ppca_cpu1_cti_1_IRQn           | CPU1 Cross-Trigger Interface channel 1         |
*   | 5           | CY_IRQ_PPCA_CPU0_FP         | ppca_cpu0_fp_IRQn              | CPU0 Floating Point exception                  |
*   | 6           | CY_IRQ_PPCA_CPU1_FP         | ppca_cpu1_fp_IRQn              | CPU1 Floating Point exception                  |
*
*   <b>CY_IRQ_RDY_FOR_DEEPSLEEP</b> - Signals that the PPCA subsystem has completed
*   all pending operations and is ready to enter DeepSleep mode. This interrupt is
*   used by the SysPm driver in the DeepSleep entry sequence.
*
*   <b>CY_IRQ_PPCA_CPUx_CTI_0 / CY_IRQ_PPCA_CPUx_CTI_1</b> - Cross-Trigger Interface
*   (CTI) interrupts from PPCA CPU0 and CPU1. The CTI is an ARM CoreSight debug
*   component that allows cross-triggering between processors. These interrupts can
*   be used to notify the host CM33 about debug events or software-triggered
*   cross-trigger signals originating from the PPCA CPUs.
*
*   <b>CY_IRQ_PPCA_CPUx_FP</b> - Floating Point exception interrupts from PPCA CPU0
*   and CPU1. These interrupts are triggered when a floating-point exception (such as
*   invalid operation, division by zero, overflow, underflow, or inexact result)
*   occurs on the respective PPCA CPU.
*
*   \section group_ppca_cnfg_interrupt_usage Interrupt Usage
*   Each interrupt source has its own S2IRQ register block with INTR, INTR_SET,
*   INTR_MASK, and INTR_MASKED registers. The driver provides the following APIs
*   for managing these interrupts:
*   - \ref Cy_PPCA_CNFG_GetInterruptStatus - Read the raw interrupt status
*   - \ref Cy_PPCA_CNFG_ClearInterrupt - Clear a pending interrupt
*   - \ref Cy_PPCA_CNFG_SetInterrupt - Set an interrupt (software trigger)
*   - \ref Cy_PPCA_CNFG_GetInterruptMask - Read the interrupt mask
*   - \ref Cy_PPCA_CNFG_SetInterruptMask - Enable the interrupt mask
*   - \ref Cy_PPCA_CNFG_GetInterruptStatusMasked - Read the masked interrupt status
*
*   All APIs take a pointer to the first S2IRQ register block (PPCA_CNFG_S2IRQ0) as
*   the base parameter, and a \ref cy_en_ppca_cnfg_interrupts_t enum value as the
*   index to select the specific interrupt source.
*
*   \subsection group_ppca_cnfg_interrupt_code_example Code Example
*   The following example demonstrates how to configure and handle the PPCA CPU0
*   floating-point exception interrupt on the host CM33:
*
*   \code
*   #include "cy_ppca_cnfg.h"
*   #include "cy_sysint.h"
*
*   // ISR for PPCA CPU0 Floating Point exception
*   void PPCA_CPU0_FP_ISR(void)
*   {
*       // Check if CPU0 FP interrupt is pending
*       if (Cy_PPCA_CNFG_GetInterruptStatusMasked(PPCA_CNFG_S2IRQ0, CY_IRQ_PPCA_CPU0_FP) != 0U)
*       {
*           // Handle the floating-point exception from PPCA CPU0
*           // ...
*
*           // Clear the interrupt
*           Cy_PPCA_CNFG_ClearInterrupt(PPCA_CNFG_S2IRQ0, CY_IRQ_PPCA_CPU0_FP);
*       }
*   }
*
*   void Configure_PPCA_CNFG_Interrupts(void)
*   {
*       // Configure the system interrupt for PPCA CPU0 FP
*       cy_stc_sysint_t ppca_cpu0_fp_irq_cfg =
*       {
*           .intrSrc = ppca_cpu0_fp_IRQn,      // Host CM33 IRQ number
*           .intrPriority = 3U,                 // Interrupt priority
*       };
*
*       // Initialize and enable the interrupt
*       (void)Cy_SysInt_Init(&ppca_cpu0_fp_irq_cfg, PPCA_CPU0_FP_ISR);
*       NVIC_EnableIRQ(ppca_cpu0_fp_irq_cfg.intrSrc);
*
*       // Enable the S2IRQ interrupt mask for CPU0 FP
*       Cy_PPCA_CNFG_SetInterruptMask(PPCA_CNFG_S2IRQ0, CY_IRQ_PPCA_CPU0_FP);
*
*       // Similarly, other interrupt sources can be configured:
*       // Cy_PPCA_CNFG_SetInterruptMask(PPCA_CNFG_S2IRQ0, CY_IRQ_PPCA_CPU0_CTI_0);
*       // Cy_PPCA_CNFG_SetInterruptMask(PPCA_CNFG_S2IRQ0, CY_IRQ_RDY_FOR_DEEPSLEEP);
*   }
*   \endcode
*
*   \section group_ppca_cnfg_changelog Changelog
*    <table class="doxtable">
*     <tr><th>Version</th><th>Changes</th><th>Reason for Change</th></tr>
*     <tr>
*       <td>1.0</td>
*       <td>Initial version</td>
*       <td></td>
*     </tr>
*    </table>
*   \defgroup group_ppca_cnfg_functions Function Prototypes
*   \defgroup group_ppca_cnfg_structures Configuration Structures
*   \defgroup group_ppca_cnfg_enums Enumerated Types
*   \defgroup group_ppca_cnfg_macros Macros
*
* \}
* \defgroup group_ppca_startup       Startup     (Programmable Power Control Accelerator Startup)
* \defgroup group_ppca_epu           EPU         (Event Processing Unit)
* \defgroup group_ppca_hwfilt3p3z    3P3Z Filter (3Poles 3Zeros Filter)
* \defgroup group_ppca_clb           CLB         (Custom Logic Block)
* \defgroup group_ppca_atop          ATOP
*/

#if !defined(CY_PPCA_CNFG_H)
#define CY_PPCA_CNFG_H

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
* \addtogroup group_ppca_cnfg_macros
* \{
*/
/** The driver major version */
#define CY_PPCA_CNFG_DRV_VERSION_MAJOR       1U

/** The driver minor version */
#define CY_PPCA_CNFG_DRV_VERSION_MINOR       0U

/** The PPCA CNFG driver ID */
#define CY_PPCA_CNFG_ID               CY_PDL_DRV_ID(CY_PDL_RSLT_MODULE_PPCA_CNFG)

/** \cond INTERNAL */

#define CY_IS_PARAM_VALID(base)       (NULL != base)

/** \endcond */


/** \} group_ppca_cnfg_macros */


/***************************************
*       Enumerated Types
***************************************/
/**
* \addtogroup group_ppca_cnfg_enums
* \{
*/

/** CPU reset */
typedef enum
{
    CY_CPU_RESET         = 0U,         /**< CPU under reset */
    CY_CPU_RESET_RELEASE = 1U, /**< CPU reset release */
} cy_en_ppca_cpu_reset_t;


/** Peripheral allocation to CPU0/1 */
typedef enum
{
    CY_ALLOCATE_PERIPHERAL_TO_CPU0 = 0U, /**< Peripheral allocated to CPU0 */
    CY_ALLOCATE_PERIPHERAL_TO_CPU1 = 1U, /**< Peripheral allocated to CPU1 */
}cy_en_ppca_peripheral_cpuss_t;


/** ADC Group Source for TRACE_ATOP */
typedef enum
{
    
    CY_ADC_GRP0 = 0U, /**< Select ADC GROUP0 as source for TRACE_ATOP */
    CY_ADC_GRP1 = 1U, /**< Select ADC GROUP1 as source for TRACE_ATOP */
    CY_ADC_GRP2 = 2U, /**< Select ADC GROUP2 as source for TRACE_ATOP */
    CY_ADC_GRP3 = 3U, /**< Select ADC GROUP3 as source for TRACE_ATOP */

}cy_en_ppca_cnfg_sel_adc_grp_t;


/** Select TRACE_ATOP Mode */
typedef enum
{
    CY_TRACE_ATOP_TEST_MODE       = 0U,       /**< TRACE_ATOP test mode */
    CY_TRACE_ATOP_FUNCTIONAL_MODE = 1U, /**< TRACE_ATOP functional mode */
}cy_en_ppca_cnfg_trace_atop_mode_t;


/** PPCA Output Selector Source */
typedef enum
{
    CY_PPCAOUT_TCPWM_OUTPUT = 0U, /**< TCPWM Output */
    CY_PPCAOUT_CLB_OUPTUT   = 1U,   /**< CLB Output */
}cy_en_ppca_cnfg_output_sel_src_t;


/** Memory Space Access */
typedef enum
{
    CY_AHB_MEM_SPACE_ACCESS_ENABLED   = 0U,   /**< AHB memory space access is enabled */
    CY_AHB_MEM_SPACED_ACCESS_DISABLED = 1U,   /**< AHB memory space access is disabled */
}cy_en_ppca_cnfg_ahb_mem_access_t;

/** PPCA CNFG Interrupts Index
*
* Each enum value corresponds to one S2IRQ register block in the PPCA CNFG.
* The interrupt is forwarded from the PPCA subsystem to the host CM33 NVIC
* through the corresponding S2IRQ channel.
*
* \note CY_IRQ_RDY_FOR_DEEPSLEEP was available since ES10.
*       The CTI and FP interrupt sources were added post-ES10.
*/
typedef enum
{
    CY_IRQ_RDY_FOR_DEEPSLEEP = 0U, /**< PPCA ready for DeepSleep. Signals that the PPCA subsystem
                                         has completed all pending operations and is ready to enter
                                         DeepSleep mode. Maps to host IRQn \a ppca_cnfg_rdy_for_dslp_IRQn. */
    CY_IRQ_PPCA_CPU0_CTI_0   = 1U, /**< PPCA CPU0 Cross-Trigger Interface (CTI) channel 0.
                                         Triggered by the CoreSight CTI output 0 of PPCA CPU0.
                                         Maps to host IRQn \a ppca_cpu0_cti_0_IRQn. */
    CY_IRQ_PPCA_CPU0_CTI_1   = 2U, /**< PPCA CPU0 Cross-Trigger Interface (CTI) channel 1.
                                         Triggered by the CoreSight CTI output 1 of PPCA CPU0.
                                         Maps to host IRQn \a ppca_cpu0_cti_1_IRQn. */
    CY_IRQ_PPCA_CPU1_CTI_0   = 3U, /**< PPCA CPU1 Cross-Trigger Interface (CTI) channel 0.
                                         Triggered by the CoreSight CTI output 0 of PPCA CPU1.
                                         Maps to host IRQn \a ppca_cpu1_cti_0_IRQn. */
    CY_IRQ_PPCA_CPU1_CTI_1   = 4U, /**< PPCA CPU1 Cross-Trigger Interface (CTI) channel 1.
                                         Triggered by the CoreSight CTI output 1 of PPCA CPU1.
                                         Maps to host IRQn \a ppca_cpu1_cti_1_IRQn. */
    CY_IRQ_PPCA_CPU0_FP      = 5U, /**< PPCA CPU0 Floating Point exception.
                                         Triggered when a floating-point exception occurs on PPCA CPU0.
                                         Maps to host IRQn \a ppca_cpu0_fp_IRQn. */
    CY_IRQ_PPCA_CPU1_FP      = 6U, /**< PPCA CPU1 Floating Point exception.
                                         Triggered when a floating-point exception occurs on PPCA CPU1.
                                         Maps to host IRQn \a ppca_cpu1_fp_IRQn. */
}
cy_en_ppca_cnfg_interrupts_t;

/** \} group_ppca_cnfg_enums */

/** \cond INTERNAL */

/** PPCA CNFG Memory Configuration. When Remap is enabled CPU1 Code(M2) and CPU1 DATA(M3) are also assigned to CPU0. 
M0 CPU0 Code memory : 32KB
M1 CPU0 Data memory : 16KB
M2 CPU1 Code memory : 32KB
M3 CPU1 Data memory : 16KB
M4 Shared memory between CPU0 and CPU1 : 16KB
*/
typedef enum
{
    CY_PPCA_CNFG_MEMORY_HEAVY   = 0U,   /**< Code and data memory are fully available. M0 and M2 are 32KB. M1, M3 and M4 are 16KB  */
    CY_PPCA_CNFG_MEMORY_MAXY    = 2U,   /**< Code memory is fully available. Half of data memory is available  M0 and M2 are 32KB. M1 and M3 are 8KB and M4 is 16KB  */
    CY_PPCA_CNFG_MEMORY_MEDIUM  = 4U,   /**< Half of Code memory is available. Full Data memory is available.  M0 and M2 are 16KB. M1 and M3 are 16KB and M4 is 16KB  */
    CY_PPCA_CNFG_MEMORY_POR     = 6U,   /**< Half of Code memory is available. Half of data memory is available.  M0 and M2 are 16KB. M1 and M3 are 8KB and M4 is 16KB  */
    CY_PPCA_CNFG_MEMORY_LIGHT   = 7U,   /**< Half of Code memory is available. Half of data memory is available.  M0 is 16KB. M1 is 8KB. All other memories are disabled.  */
}
cy_en_ppca_cnfg_memory_config_t;

/** \endcond */

/***************************************
*       Configuration Structures
***************************************/

/**
* \addtogroup group_ppca_cnfg_structures
* \{
*/

/** Peripheral Assignment Configuration */
typedef struct cy_stc_ppca_control_config
{
    cy_en_ppca_peripheral_cpuss_t pwmSS0;            /**< PWM_SS0 Assignment */
    cy_en_ppca_peripheral_cpuss_t pwmSS1;            /**< PWM_SS1 Assignment */
    cy_en_ppca_peripheral_cpuss_t pwmSS2;            /**< PWM_SS2 Assignment */
    cy_en_ppca_peripheral_cpuss_t pwmSS3;            /**< PWM_SS3 Assignment */
    cy_en_ppca_peripheral_cpuss_t HWFILT3P3Z_SS0;    /**< HWFILT3P3Z_SS0 Assignment */
    cy_en_ppca_peripheral_cpuss_t HWFILT3P3Z_SS1;    /**< HWFILT3P3Z_SS1 Assignment */
    cy_en_ppca_peripheral_cpuss_t ADCMirror;         /**< ADC Mirror Assignment */
    cy_en_ppca_peripheral_cpuss_t CLB;               /**< CLB Mirror Assignment */
    cy_en_ppca_peripheral_cpuss_t cordic0;           /**< CORDIC0 Assignment */
    cy_en_ppca_peripheral_cpuss_t cordic1;           /**< CORDIC1 Assignment */
    cy_en_ppca_peripheral_cpuss_t adcGroup0;         /**< ADCGRP_0 Assignment */
    cy_en_ppca_peripheral_cpuss_t adcGroup1;         /**< ADCGRP_1 Assignment */
    cy_en_ppca_peripheral_cpuss_t adcGroup2;         /**< ADCGRP_2 Assignment */
    cy_en_ppca_peripheral_cpuss_t adcGroup3;         /**< ADCGRP_3 Assignment */
    cy_en_ppca_peripheral_cpuss_t dcsgGroup0;        /**< DCSGGRP_0 Assignment */
    cy_en_ppca_peripheral_cpuss_t dcsgGroup1;        /**< DCSGGRP_1 Assignment */
}cy_stc_ppca_control_config_t;


/** PPCA Output Selector Configuration */
typedef struct cy_stc_ppca_cnfg_ppcaout_output_selector
{
    cy_en_ppca_cnfg_output_sel_src_t outputSelSrc; /**< PPCA Output Selector Source */
    bool enableOutputSel;                          /**< Enable PPCA Output Selector */
}cy_stc_ppca_cnfg_ppcaout_output_selector_t;


/** PPCA Input Selector Configuration */
typedef struct cy_stc_ppca_cnfg_ppcaout_input_selector
{
    uint32_t inputSelSrc;      /**< PPCA Input Selector Source */
    bool disSynchronizerStage; /**< Disable PPCA Input Selector Output Synchronizer Stage */
}cy_stc_ppca_cnfg_ppcaout_input_selector_t;


/** PPCA CNFG Configuration */
typedef struct cy_stc_ppca_cnfg_config
{
    bool dpslpRetentionEnable;                                     /**< Enable/Disable the reset PPCA retained logic */
    bool clkShutDown;                                              /**< Enable/Disable the PPCA Clock Shut Down */
    bool cpu0HRESPError;                                           /**< Enable/Disable the CPU0 HRESP error */
    bool cpu1HRESPError;                                           /**< Enable/Disable the CPU1 HRESP error */ 
    bool cpu0Enable;                                               /**< CPU0 Clock Enable */
    bool cpu1Enable;                                               /**< CPU1 Clock Enable */
    bool remapEnable;                                              /**< This parameter enables/disables PPCA BusMatrix Remap, when enabled reduced data memory is set and CPU1 will not have any memory allocated. CPU1 should be disabled. */
    const cy_stc_ppca_control_config_t *ctrl_cnfg;                 /**< PPCA Configuration */
    uint32_t puty1ResAlloc;                                        /**< PPCA EPU PUTY1 CPU Allocation */
    uint32_t puty2ResAlloc;                                        /**< PPCA EPU PUTY2 CPU Allocation */
    const cy_stc_ppca_cnfg_ppcaout_output_selector_t *ppcaout_cnfg;      /**< PPCA_OUT Configuration */
}cy_stc_ppca_cnfg_config_t;


/** TRACE_ATOP configuration */
typedef struct cy_stc_ppca_cnfg_trace_atop
{
    cy_en_ppca_cnfg_sel_adc_grp_t selADCGrpSrc;      /**< ADC Group Source for TRACE ATOP */
    bool enableTraceATOP;                            /**< Enable Trace ATOP */
    cy_en_ppca_cnfg_trace_atop_mode_t traceATOPmode; /**< Select TRACE_ATOP mode */
}cy_stc_ppca_cnfg_trace_atop_t;


/** \} group_ppca_cnfg_structures */


/***************************************
*        Function Prototypes
***************************************/

/**
* \addtogroup group_ppca_cnfg_functions
* \{
*/
#if !defined (COMPONENT_PPCA_DEVICE)

/*******************************************************************************
* Function Name: Cy_PPCA_CNFG_Init
****************************************************************************//**
*
* Initializes the PPCA by enabling the PPCA peripherals, allocating the
* peripherals to CPU0/1, and other configurations of the block including 
* PPCA clock shut down, CPU0/1 clock enablement, HRESP error enablement, etc.,.
*
* \param *base
* The PPCA CNFG registers structure pointer.
*
* \param *config
* The pointer to the PPCA CNFG configuration structure.
*
* \snippet ppca/snippet/ppca_snippet.c SNIPPET_PPCA_CNFG_INIT
*
*******************************************************************************/ 
void Cy_PPCA_CNFG_Init(PPCA_CNFG_Type *base, cy_stc_ppca_cnfg_config_t const *config);


/*******************************************************************************
* Function Name: Cy_PPCA_Enable
****************************************************************************//**
*
* Enables PPCA block.
*
* \param *base
* The PPCA CNFG registers structure pointer.
*
*******************************************************************************/
__STATIC_INLINE void Cy_PPCA_Enable(PPCA_CNFG_Type *base)
{
    PPCA_CNFG_CTRL(base) |= PPCA_CNFG_CTRL_PPCA_EN_Msk;
}


/*******************************************************************************
* Function Name: Cy_PPCA_Disable
****************************************************************************//**
*
* Disables PPCA block. All the internal clock are gated, all registers are reset.
*
* \param *base
* The PPCA CNFG registers structure pointer.
*
*******************************************************************************/
__STATIC_INLINE void Cy_PPCA_Disable(PPCA_CNFG_Type *base)
{
    PPCA_CNFG_CTRL(base) &= (uint32_t) ~PPCA_CNFG_CTRL_PPCA_EN_Msk;
}

/*******************************************************************************
* Function Name: Cy_PPCA_Clear_Fault_Status
****************************************************************************//**
*
* Clears fault status if it is set
*
* \note When there is a HRESP error, system also generates a SysFault error.
*       SysFault error needs to be cleared before clearing this error.
*       Please check SysFault driver for more details on SysFault.
*
* \param *base
* The PPCA CNFG registers structure pointer.
*
*******************************************************************************/
__STATIC_INLINE void Cy_PPCA_Clear_Fault_Status(PPCA_CNFG_Type *base)
{
    PPCA_CNFG_CTRL(base) |= PPCA_CNFG_CTRL_FAULT_STATUS_Msk;
}

/*******************************************************************************
* Function Name: Cy_PPCA_Get_Fault_Status
****************************************************************************//**
*
* Returns fault status.
*
* \param *base
* The PPCA CNFG registers structure pointer.
*
* \return
* True if fault is active. false if fault is not active.
*
* \note please clear the fault if it is active \ref Cy_PPCA_Clear_Fault_Status
*******************************************************************************/
__STATIC_INLINE bool Cy_PPCA_Get_Fault_Status(PPCA_CNFG_Type *base)
{
    return (bool)_FLD2VAL(PPCA_CNFG_CTRL_FAULT_STATUS, PPCA_CNFG_CTRL(base));
}


/*******************************************************************************
* Function Name: Cy_PPCA_AllocatePUT1Resources
****************************************************************************//**
*
* Allocates the 32 PUT1(Processing Unit Type 1) of EPU to CPU0/1.
*
* \param *base
* The PPCA CNFG's CNFG registers structure pointer.
*
* \param put1ResAlloc
* This value corresponds to the 32 PUT1(Processing Unit Type 1) of EPU
* resources allocation to CPU0/1.
* Each bit corresponds to one PUT1.
* * Bit value 0: PUT1x allocated to CPU0.
* * Bit value 1: PUT1x allocated to CPU1.
*
*******************************************************************************/
__STATIC_INLINE void Cy_PPCA_AllocatePUT1Resources(PPCA_CNFG_CNFG_Type *base, uint32_t put1ResAlloc)
{
    PPCA_CNFG_CNFG_CNFG1(base) = put1ResAlloc;
}


/*******************************************************************************
* Function Name: Cy_PPCA_AllocatePUT2Resources
****************************************************************************//**
*
* Allocates the 16 PUT2(Processing Unit Type 2) of EPU to CPU0/1.
*
* \param *base
* The PPCA CNFG's CNFG registers structure pointer.
*
* \param put2ResAlloc
* This value corresponds to the 16 PUT2(Processing Unit Type 2) of EPU
* resources allocation to CPU0/1.
* Each bit corresponds to one PUT2.
* * Bit value 0: PUT2x allocated to CPU0.
* * Bit value 1: PUT2x allocated to CPU1.
*
*******************************************************************************/
__STATIC_INLINE void Cy_PPCA_AllocatePUT2Resources(PPCA_CNFG_CNFG_Type *base, uint16_t put2ResAlloc)
{
    PPCA_CNFG_CNFG_CNFG2(base) = (uint32_t) put2ResAlloc;
}


/*******************************************************************************
* Function Name: Cy_PPCA_CNFG_CPU0_Clock_Enable
****************************************************************************//**
*
* Enable CPU0 Clock.
*
* \param *base
* The PPCA CNFG's CNFG registers structure pointer.
*
* \param enable
* true: enable the clock.
* false: disable the clock.
*
*******************************************************************************/
__STATIC_INLINE void Cy_PPCA_CNFG_CPU0_Clock_Enable(PPCA_CNFG_CNFG_Type *base, bool enable)
{
    if(enable)
    {
        PPCA_CNFG_CNFG_CPU_CTRL(base) |= PPCA_CNFG_CNFG_CPU_CTRL_CPU0_ENABLE_Msk;
    }
    else
    {
        PPCA_CNFG_CNFG_CPU_CTRL(base) &= ~(PPCA_CNFG_CNFG_CPU_CTRL_CPU0_ENABLE_Msk);
    }
}


/*******************************************************************************
* Function Name: Cy_PPCA_CNFG_CPU1_Clock_Enable
****************************************************************************//**
*
* Enable CPU1 Clock.
*
* \param *base
* The PPCA CNFG's CNFG registers structure pointer.
*
* \param enable
* true: enable the clock.
* false: disable the clock.
*
*******************************************************************************/
__STATIC_INLINE void Cy_PPCA_CNFG_CPU1_Clock_Enable(PPCA_CNFG_CNFG_Type *base, bool enable)
{
    if(enable)
    {
        PPCA_CNFG_CNFG_CPU_CTRL(base) |= PPCA_CNFG_CNFG_CPU_CTRL_CPU1_ENABLE_Msk;
    }
    else
    {
        PPCA_CNFG_CNFG_CPU_CTRL(base) &= ~(PPCA_CNFG_CNFG_CPU_CTRL_CPU1_ENABLE_Msk);
    }
}

/*******************************************************************************
* Function Name: Cy_PPCA_CNFG_CPU0_Reset
****************************************************************************//**
*
* Release reset for CPU0.
*
* \param *base
* The PPCA CNFG's CNFG registers structure pointer.
*
* \param reset
* CPU Reset.
* See \ref cy_en_ppca_cpu_reset_t.
*
*******************************************************************************/
__STATIC_INLINE void Cy_PPCA_CNFG_CPU0_Reset(PPCA_CNFG_CNFG_Type *base, cy_en_ppca_cpu_reset_t reset)
{
    if(CY_CPU_RESET == reset)
    {
        PPCA_CNFG_CNFG_RST_CTRL(base) &= ~(PPCA_CNFG_CNFG_RST_CTRL_CPU0_RST_Msk);;
    }
    else
    {
        PPCA_CNFG_CNFG_RST_CTRL(base) |= PPCA_CNFG_CNFG_RST_CTRL_CPU0_RST_Msk;
    }
}


/*******************************************************************************
* Function Name: Cy_PPCA_CNFG_CPU1_Reset
****************************************************************************//**
*
* Release reset for CPU1.
*
* \param *base
* The PPCA CNFG's CNFG registers structure pointer.
*
* \param reset
* CPU Reset.
* See \ref cy_en_ppca_cpu_reset_t.
*
*******************************************************************************/
__STATIC_INLINE void Cy_PPCA_CNFG_CPU1_Reset(PPCA_CNFG_CNFG_Type *base, cy_en_ppca_cpu_reset_t reset)
{
    if(CY_CPU_RESET == reset)
    {
        PPCA_CNFG_CNFG_RST_CTRL(base) &= ~(PPCA_CNFG_CNFG_RST_CTRL_CPU1_RST_Msk);;
    }
    else
    {
        PPCA_CNFG_CNFG_RST_CTRL(base) |= PPCA_CNFG_CNFG_RST_CTRL_CPU1_RST_Msk;
    }}


/*******************************************************************************
* Function Name: Cy_PPCA_CNFG_TRACE_ATOP_Configuration
****************************************************************************//**
*
* Initializes the TRACE_ATOP module which includes configuring the ADC source 
* group for TRACE_ATOP, operating mode and enabling the module.
*
* \param *base
* The PPCA CNFG's CNFG registers structure pointer.
*
* \param *config
* The pointer to the TRACE_ATOP configuration structure.
* See \ref cy_stc_ppca_cnfg_trace_atop_t.
*
*******************************************************************************/
__STATIC_INLINE void Cy_PPCA_CNFG_TRACE_ATOP_Configuration(PPCA_CNFG_CNFG_Type *base, cy_stc_ppca_cnfg_trace_atop_t const *config)
{
    PPCA_CNFG_CNFG_CNFG_TRACE_ATOP(base) = _VAL2FLD(PPCA_CNFG_CNFG_CNFG_TRACE_ATOP_SEL_ADC_GRP, (uint32_t) config->selADCGrpSrc) |
                                                _BOOL2FLD(PPCA_CNFG_CNFG_CNFG_TRACE_ATOP_EN_TRACE_ATOP, config->enableTraceATOP) |
                                                _VAL2FLD(PPCA_CNFG_CNFG_CNFG_TRACE_ATOP_SEL_MODE, (uint32_t) config->traceATOPmode);
}


/*******************************************************************************
* Function Name: Cy_PPCA_CNFG_PPCA_Output_Selector
****************************************************************************//**
*
* Initializes the Output Selector module which includes enabling the module
* and configuring the PPCA output selector source.
*
* \param *base
* The PPCA CNFG's CNFG registers structure pointer.
*
* \param *config
* The pointer to the Output Selector configuration structure.
* See \ref cy_stc_ppca_cnfg_ppcaout_output_selector_t.
*
*******************************************************************************/
__STATIC_INLINE void Cy_PPCA_CNFG_PPCA_Output_Selector(PPCA_CNFG_CNFG_Type *base, cy_stc_ppca_cnfg_ppcaout_output_selector_t const *config)
{
    PPCA_CNFG_CNFG_PPCAOUT_SEL(base) = _VAL2FLD(PPCA_CNFG_CNFG_PPCAOUT_SEL_PPCAOUT_SEL_SRC, (uint32_t) config->outputSelSrc) |
                                            _BOOL2FLD(PPCA_CNFG_CNFG_PPCAOUT_SEL_PPCAOUT_SEL_EN, config->enableOutputSel);
}


/*******************************************************************************
* Function Name: Cy_PPCA_CNFG_PPCA_Input_Selector
****************************************************************************//**
*
* Configures the PPCA Input Selector module which mainly includes the selection 
* of PPCA input selector source.
*
* \param *base
* The PPCA CNFG's CNFG registers structure pointer.
*
* \param *config
* The pointer to the Input Selector configuration structure.
* See \ref cy_stc_ppca_cnfg_ppcaout_input_selector_t.
*
* \param idx
* The index to one of the 32 PPCA Input Selector.
*
*******************************************************************************/
__STATIC_INLINE void Cy_PPCA_CNFG_PPCA_Input_Selector(PPCA_CNFG_CNFG_Type *base, cy_stc_ppca_cnfg_ppcaout_input_selector_t const *config, uint8_t idx)
{
    PPCA_CNFG_CNFG_PPCAIN_SEL(base, idx) = _VAL2FLD(PPCA_CNFG_CNFG_PPCAIN_SEL_PPCAIN_SEL_SRC, (uint32_t) config->inputSelSrc) |
                                                _BOOL2FLD(PPCA_CNFG_CNFG_PPCAIN_SEL_DS_SYNCSTAGE_PPCAIN_SEL, config->disSynchronizerStage);

}


/*******************************************************************************
* Function Name: Cy_PPCA_CNFG_PPCA_Trigger_Input_Selector
****************************************************************************//**
*
* Configures the PPCA Input Selector module which mainly includes the selection 
* of PPCA trigger input selector source.
*
* \param *base
* The PPCA CNFG's CNFG registers structure pointer.
*
* \param *config
* The pointer to the Input Selector configuration structure.
* See \ref cy_stc_ppca_cnfg_ppcaout_input_selector_t.
*
* \param idx
* The index to one of the 32 PPCA Input Selector.
*
*******************************************************************************/
__STATIC_INLINE void Cy_PPCA_CNFG_PPCA_Trigger_Input_Selector(PPCA_CNFG_CNFG_Type *base, cy_stc_ppca_cnfg_ppcaout_input_selector_t const *config, uint8_t idx)
{
    PPCA_CNFG_CNFG_TR_PPCAIN_SEL(base, idx) = _VAL2FLD(PPCA_CNFG_CNFG_TR_PPCAIN_SEL_TR_PPCAIN_SEL_SRC, (uint32_t) config->inputSelSrc) |
                                                   _BOOL2FLD(PPCA_CNFG_CNFG_TR_PPCAIN_SEL_DS_SYNCSTAGE_TR_PPCAIN_SEL, config->disSynchronizerStage);

}


/*******************************************************************************
* Function Name: Cy_PPCA_CNFG_DDFT_Output_Selector
****************************************************************************//**
*
* Configures the PPCA DDFT Output Selector.
*
* \param *base
* The PPCA CNFG's CNFG registers structure pointer.
*
* \param outSrcSel
* The PPCA DDFT Output Selector value.
*
* \param idx
* The index to one of the 2 PPCA DDFT Output Selector.
*
*******************************************************************************/
__STATIC_INLINE void Cy_PPCA_CNFG_DDFT_Output_Selector(PPCA_CNFG_CNFG_Type *base, uint32_t outSrcSel, uint8_t idx)
{
    PPCA_CNFG_CNFG_DDFTOUT_SEL(base, idx) = outSrcSel;
}


/*******************************************************************************
* Function Name: Cy_PPCA_CNFG_Read_PPCAIO_IN_Status
****************************************************************************//**
*
* Reads the PPCAIO_IN Monitor register.
*
* \param *base
* The PPCA CNFG's CNFG registers structure pointer.
*
* \param ioStatus
* Reflects the status of PPCAIO Input signals synchronized with PPCA CLK.
*
*******************************************************************************/
__STATIC_INLINE void Cy_PPCA_CNFG_Read_PPCAIO_IN_Status(PPCA_CNFG_CNFG_Type *base, uint32_t *ioStatus)
{
    *ioStatus = PPCA_CNFG_CNFG_PPCAIO_IN_MON(base);
}


/*******************************************************************************
* Function Name: Cy_PPCA_CNFG_ReadScratch0Reg
****************************************************************************//**
*
* Reads the SCRATCH 0 register.
*
* \param *base
* The PPCA CNFG's CNFG registers structure pointer.
*
* \param *scratch0
* The pointer scratch0 value.
*
*******************************************************************************/
__STATIC_INLINE void Cy_PPCA_CNFG_ReadScratch0Reg(PPCA_CNFG_CNFG_Type *base, uint32_t *scratch0)
{
    *scratch0 = PPCA_CNFG_CNFG_SCRATCH0(base);
}


/*******************************************************************************
* Function Name: Cy_PPCA_CNFG_WriteScratch0Reg
****************************************************************************//**
*
* Writes the SCRATCH 0 register.
*
* \param *base
* The PPCA CNFG's CNFG registers structure pointer.
*
* \param scratch0
* The value to be written into the scratch0 register.
*
*******************************************************************************/
__STATIC_INLINE void Cy_PPCA_CNFG_WriteScratch0Reg(PPCA_CNFG_CNFG_Type *base, uint32_t scratch0)
{
    PPCA_CNFG_CNFG_SCRATCH0(base) = scratch0;
}


/*******************************************************************************
* Function Name: Cy_PPCA_CNFG_ReadScratch1Reg
****************************************************************************//**
*
* Reads the SCRATCH 1 register.
*
* \param *base
* The PPCA CNFG's CNFG registers structure pointer.
*
* \param *scratch1
* The pointer to the scratch1 value.
*
*******************************************************************************/
__STATIC_INLINE void Cy_PPCA_CNFG_ReadScratch1Reg(PPCA_CNFG_CNFG_Type *base, uint32_t *scratch1)
{
    *scratch1 = PPCA_CNFG_CNFG_SCRATCH1(base);
}


/*******************************************************************************
* Function Name: Cy_PPCA_CNFG_WriteScratch1Reg
****************************************************************************//**
*
* Writes the SCRATCH 1 register.
*
* \param *base
* The PPCA CNFG's CNFG registers structure pointer.
*
* \param scratch1
* The value to be written into the scratch1 register.
*
*******************************************************************************/
__STATIC_INLINE void Cy_PPCA_CNFG_WriteScratch1Reg(PPCA_CNFG_CNFG_Type *base, uint32_t scratch1)
{
    PPCA_CNFG_CNFG_SCRATCH1(base) = scratch1;
}


/*******************************************************************************
* Function Name: Cy_PPCA_CNFG_PPCA_Read_ADC_Mirror_Data
****************************************************************************//**
*
* Reads the ADC Mirrored Result Data.
*
* \param *base
* The PPCA CNFG's CNFG registers structure pointer.
*
* \param index
* Index to the ADCM Data. One ADC Data per channel
*
* \return
* The ADC Data out for the channel.
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_PPCA_CNFG_PPCA_Read_ADC_Mirror_Data(PPCA_CNFG_Type *base, uint32_t index )
{
    return base->ADCM.ADC_DATA[index];
}


/******************************************************************************
* Function Name: Cy_PPCA_CNFG_GetInterruptStatus
****************************************************************************//**
*
* Returns the interrupt cause register. 
*
* \param *base
* The PPCA CNFG S2IRQ registers structure pointer.
*
* \param index
* The index to one of the 7 PPCA CNFG register.
*
* \return
* The current status of the interrupt source.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_PPCA_CNFG_GetInterruptStatus(PPCA_CNFG_S2IRQ_Type *base, cy_en_ppca_cnfg_interrupts_t index)
{
    return (PPCA_CNFG_S2IRQ_INTR(base + (int16_t)index));
}


/******************************************************************************
* Function Name: Cy_PPCA_CNFG_ClearInterrupt
****************************************************************************//**
*
* Clears the interrupt source in the interrupt cause register.
*
* \param *base
* The PPCA CNFG S2IRQ registers structure pointer.
*
* \param index
* The index to one of the 7 PPCA CNFG register
*
*******************************************************************************/
__STATIC_INLINE void Cy_PPCA_CNFG_ClearInterrupt(PPCA_CNFG_S2IRQ_Type *base, cy_en_ppca_cnfg_interrupts_t index)
{
    PPCA_CNFG_S2IRQ_INTR(base + (int16_t)index) = 1u;
}


/******************************************************************************
* Function Name: Cy_PPCA_CNFG_SetInterrupt
****************************************************************************//**
*
* Sets the interrupt source in the interrupt set register.
*
* \param *base
* The PPCA CNFG S2IRQ registers structure pointer.
*
* \param index
* The index to one of the 7 PPCA CNFG register
*
*******************************************************************************/
__STATIC_INLINE void Cy_PPCA_CNFG_SetInterrupt(PPCA_CNFG_S2IRQ_Type *base, cy_en_ppca_cnfg_interrupts_t index)
{
    PPCA_CNFG_S2IRQ_INTR_SET(base + (int16_t)index) = 1U;
}


/******************************************************************************
* Function Name: Cy_PPCA_CNFG_GetInterruptMask
****************************************************************************//**
*
* Returns the interrupt mask register. This register specifies which
* bits from the interrupt cause register can trigger an interrupt event.
*
* \param *base
* The PPCA CNFG S2IRQ registers structure pointer.
*
* \param index
* The index to one of the 7 PPCA CNFG registers
*
* \return
* Enabled interrupt sources.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_PPCA_CNFG_GetInterruptMask(PPCA_CNFG_S2IRQ_Type *base, cy_en_ppca_cnfg_interrupts_t index)
{
    return (PPCA_CNFG_S2IRQ_INTR_MASK(base + (int16_t)index));
}


/******************************************************************************
* Function Name: Cy_PPCA_CNFG_SetInterruptMask
****************************************************************************//**
*
* Writes interrupt mask register.
* This register specifies which bits from the interrupt cause register
* can trigger an interrupt event.
*
* \param *base
* The PPCA CNFG S2IRQ registers structure pointer.
*
* \param index
* The index to one of the 7 PPCA CNFG register
*
*******************************************************************************/
__STATIC_INLINE void Cy_PPCA_CNFG_SetInterruptMask(PPCA_CNFG_S2IRQ_Type *base, cy_en_ppca_cnfg_interrupts_t index)
{
    PPCA_CNFG_S2IRQ_INTR_MASK(base + (int16_t)index) = 1U;
}


/******************************************************************************
* Function Name: Cy_PPCA_CNFG_GetInterruptStatusMasked
****************************************************************************//**
*
* Returns the interrupt masked register. This register contains a
* logical AND of corresponding bits from the interrupt cause and mask
* registers.
* This function is intended to be used in the interrupt service routine to
* identify which of enabled interrupt sources caused the interrupt
* event.
*
* \param *base
* The PPCA CNFG S2IRQ registers structure pointer.
*
* \param index
* The index to one of the 7 PPCA CNFG register
-
* \return
* The current status of enabled interrupt sources.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_PPCA_CNFG_GetInterruptStatusMasked(PPCA_CNFG_S2IRQ_Type *base, cy_en_ppca_cnfg_interrupts_t index)
{
    return (PPCA_CNFG_S2IRQ_INTR_MASKED(base + (int16_t)index));
}
#endif /*!defined (COMPONENT_PPCA_DEVICE)*/

/** \} group_ppca_cnfg_functions */

#if defined(__cplusplus)
}
#endif

#endif /* #if defined(CY_IP_MXS40PPSS) */

#endif /* (CY_PPCA_CNFG_H) */

/** \} group_ppca */

/* [] END OF FILE */
