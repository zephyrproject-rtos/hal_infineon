/***************************************************************************//**
* \file cy_ctb.h
* \version 1.0.1
*
* The header file for the CTB driver.
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

/**
* \addtogroup group_ctb
* \{
* This driver provides API functions to configure and use the analog CTB.
*
* The functions and other declarations used in this driver are in cy_ctb.h.
* You can include cy_pdl.h to get access to all functions
* and declarations in the PDL.
*
* The CTB comprises two identical operational amplifiers (opamps) and a switch
* routing matrix. The high-level features are:
*
*   - Two highly-configurable opamps:
*       - Feature programmable power and output drive strength
*       - Can be configured as a voltage follower using internal routing
*       - Can be configured as a comparator with an optional 10 mV hysteresis
*   - Flexible input and output routing
*   - Can be used as a buffer or amplifier for SAR ADC inputs
*   - Can operate in Deep Sleep power mode.
*
* Each opamp, marked OA0 and OA1, has one input and three output stages, all of
* which share the common input stage. The only one output stage can be selected
* at a time.
*
* The output stage can operate as a low-drive strength opamp for internal
* connections (1X), a high-drive strength opamp for driving a device pin (10X),
* or a comparator.
*
* Using the switching matrix, the opamp inputs and outputs can be connected to
* dedicated general-purpose I/Os or other internal analog blocks. See the device
* datasheet for the dedicated CTB port.
*
* \image html ctb_block_diagram.png "CTB Switch Diagram" width=1000px
* \image latex ctb_block_diagram.png
*
* \section group_ctb_init Initialization and Enable
*
* Before enabling the CTB, set up any external components (such as resistors)
* needed for the design.
*
* To configure the entire hardware CTB block, call \ref Cy_CTB_Init.
* Alternatively, to configure only one opamp, call \ref Cy_CTB_OpampInit.
* The base address of the CTB hardware can be found in the device specific
* header file.
*
* After initialization, call \ref Cy_CTB_Enable to enable the hardware.
*
* \section group_ctb_io_connections Input/Output Connections
*
* The CTB has internal switches to support flexible input and output routing.
* If these switches have not been configured during initialization, call
* \ref Cy_CTB_SetAnalogSwitch to make the input and output connections.
* See the architecture TRM for more details.
*
* \snippet ctb_snippet.c CTB_SNIPPET_SET_ANALOG_SWITCH
*
* As shown in the CTB switch diagram, the external (10x) output of OA0 and OA1
* have dedicated connections. If different output connections are required, the
* AMUXBUX A/B switches can be used.
*
* \section group_ctb_comparator Comparator Mode
*
* Each opamp can be configured as a comparator. Note that when used as a
* comparator, the hardware shuts down the 1X and 10X output drivers.
* Specific to Comparator mode, there is an optional 10 mV input hysteresis
* and configurable edge detection interrupt handling.
*
* - Negative input terminal: Usually connected to the reference voltage.
* - Positive input terminal: Usually connected to the voltage being compared.
* - Comparator digital output: Rises high when the positive input
*   voltage is greater than the negative input voltage and vice versa.
*
* The comparator output can be routed to a pin or other component using HSIOM
* or trigger muxes.
*
* \snippet ctb_snippet.c SNIPPET_COMP_OUT_ROUTING
*
* \subsection group_ctb_comparator_handling_interrupts Handling interrupts
*
* The comparator output is connected to an edge detector block used to
* detect the edge (rising, falling, both, or disabled) for interrupt generation.
*
* The following code snippet demonstrates how to implement a routine to handle
* the interrupt. The routine gets called when any comparator on the device
* generates an interrupt.
*
* \snippet ctb_snippet.c SNIPPET_COMP_ISR
*
* The following code snippet demonstrates how to configure and enable the
* interrupt.
*
* \snippet ctb_snippet.c SNIPPET_COMP_INTR_SETUP
*
* \section group_ctb_opamp_range Opamp Input Range
*
* The input range of the opamp can be rail-to-rail if the charge pump is
 enabled. See the device datasheet for more details.
*
* \section group_ctb_dependencies Configuration Dependencies
*
* The CTB relies on other blocks to function properly. The dependencies
* are documented here.
*
* \subsection group_ctb_dependencies_charge_pump Charge Pump Configuration
*
* Each opamp of the CTB has a charge pump that when enabled increases the
* input range to the supply rails. Call the \ref Cy_CTB_SetPumpClkSource
* function to set the clock source for all CTBs. This clock can come from one of
* three sources:
*
*   -# The dedicated clock from the SRSS
*
*      Call the following functions to configure the pump clock from the SRSS:
*       - \ref Cy_SysClk_ClkPumpSetSource
*
*      \snippet ctb_snippet.c CTB_SNIPPET_SET_CLK_PUMP_SOURCE_SRSS
*
*   -# The high frequency clock
*
*      \snippet ctb_snippet.c CTB_SNIPPET_SET_CLK_PUMP_SOURCE_HF
*
*   -# The high frequency clock divided by 2
*
* \note The same pump clock is used by all opamps on the device. Be aware of
* this when configuring different opamps to different power levels.
*
* \subsection group_ctb_dependencies_reference_current Reference Current Configurations
*
* The CTB uses reference current generator from the  Deep-Sleep Amplifier Bias
* (DSAB) block.
*
* If the CTB is configured to operate in Deep Sleep mode, the appropriate
* reference current generator from the DSAB block must be enabled in
* Deep Sleep.
*
* \section group_ctb_more_information More Information
*
* Refer to technical reference manual (TRM) and the device datasheet.
*
* \section group_ctb_changelog Changelog
* <table class="doxtable">
*   <tr><th>Version</th><th>Changes</th><th>Reason for Change</th></tr>
*   <tr>
*     <td>1.0.1</td>
*     <td>Update the paths to the code snippets.</td>
*     <td>PDL structure update.</td>
*   </tr>
*   <tr>
*     <td>1.0</td>
*     <td>Initial version</td>
*     <td></td>
*   </tr>
* </table>
*
* \defgroup group_ctb_macros Macros
* \{
*     \defgroup group_ctb_opamp_switch_macros OpAmp Switch Macros
*     \defgroup group_ctb_sar_seq_switch_macros SAR Sequencer Controlled Switch Macros
* \}
* \defgroup group_ctb_functions Functions
* \{
*     \defgroup group_ctb_functions_init          Initialization Functions
*     \defgroup group_ctb_functions_basic         Basic Configuration Functions
*     \defgroup group_ctb_functions_comparator    Comparator Functions
*     \defgroup group_ctb_functions_interrupts    Interrupt Functions
*     \defgroup group_ctb_functions_switches      Switch Control Functions
*     \defgroup group_ctb_functions_trim          Offset and Slope Trim Functions
* \}
* \defgroup group_ctb_data_structures Data Structures
* \defgroup group_ctb_enums Enumerated Types
*/

#if !defined(CY_CTB_H)
#define CY_CTB_H

#include "cy_device.h"

#ifdef CY_IP_M0S8PASS4A_CTB

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include "cy_syslib.h"

#if defined(__cplusplus)
extern "C" {
#endif

/** \addtogroup group_ctb_macros
* \{
*/

/** Driver major version */
#define CY_CTB_DRV_VERSION_MAJOR            1

/** Driver minor version */
#define CY_CTB_DRV_VERSION_MINOR            0

/** CTB driver identifier*/
#define CY_CTB_ID                           CY_PDL_DRV_ID(0x0Bu)


/** \addtogroup group_ctb_opamp_switch_macros
* \{
*/

/** Switch masks for Opamp0 to be used in \ref Cy_CTB_SetAnalogSwitch. */
#define CY_CTB_SW_OA0_POS_AMUXBUSA     (CTBM_OA0_SW_OA0P_A00_Msk)       /**< Switch A00: Opamp0 non-inverting input to AMUXBUS A */
#define CY_CTB_SW_OA0_POS_PIN0         (CTBM_OA0_SW_OA0P_A20_Msk)       /**< Switch A20: CTB0 Opamp0 non-inverting input to Pin 0 of CTB0 device port */
#define CY_CTB_SW_OA0_POS_PIN1         (CTBM_OA0_SW_OA0P_A20_Msk)       /**< Switch A20: CTB1 Opamp0 non-inverting input to Pin 1 of CTB1 device port */
#define CY_CTB_SW_OA0_POS_PIN6         (CTBM_OA0_SW_OA0P_A30_Msk)       /**< Switch A30: CTB0 Opamp0 non-inverting input to Pin 6 of CTB0 device port */
#define CY_CTB_SW_OA0_POS_PIN5         (CTBM_OA0_SW_OA0P_A30_Msk)       /**< Switch A30: CTB1 Opamp0 non-inverting input to Pin 5 of CTB1 device port */
#define CY_CTB_SW_OA0_NEG_PIN1         (CTBM_OA0_SW_OA0M_A11_Msk)       /**< Switch A11: CTB0 Opamp0 inverting input to Pin 1 of CTB0 device port */
#define CY_CTB_SW_OA0_NEG_PIN2         (CTBM_OA0_SW_OA0M_A11_Msk)       /**< Switch A11: CTB1 Opamp0 inverting input to Pin 2 of CTB1 device port */
#define CY_CTB_SW_OA0_NEG_OUT          (CTBM_OA0_SW_OA0M_A81_Msk)       /**< Switch A81: Opamp0 inverting input to Opamp0 output */
#define CY_CTB_SW_OA0_OUT_SARBUS0      (CTBM_OA0_SW_OA0O_D51_Msk)       /**< Switch D51: Opamp0 output to sarbus0 */
#define CY_CTB_SW_OA0_OUT_SHORT_IN_EXT (CTBM_OA0_SW_OA0O_D81_Msk)       /**< Switch D81: Short Opamp0 internal (1x) with external (10x) outputs */

/** Switch masks for Opamp1 to be used in \ref Cy_CTB_SetAnalogSwitch. */
#define CY_CTB_SW_OA1_POS_AMUXBUSB     (CTBM_OA1_SW_OA1P_A03_Msk)       /**< Switch A03: Opamp1 non-inverting input to AMUXBUS B */
#define CY_CTB_SW_OA1_POS_PIN5         (CTBM_OA1_SW_OA1P_A13_Msk)       /**< Switch A13: Opamp1 non-inverting input to Pin 5 of CTB device port */
#define CY_CTB_SW_OA1_POS_PIN7         (CTBM_OA1_SW_OA1P_A43_Msk)       /**< Switch A43: Opamp1 non-inverting input to Pin 7 of CTB device port */
#define CY_CTB_SW_OA1_NEG_PIN4         (CTBM_OA1_SW_OA1M_A22_Msk)       /**< Switch A22: Opamp1 inverting input to Pin 4 of CTB device port */
#define CY_CTB_SW_OA1_NEG_OUT          (CTBM_OA1_SW_OA1M_A82_Msk)       /**< switch A82: Opamp1 inverting input to Opamp1 output */
#define CY_CTB_SW_OA1_OUT_SARBUS0      (CTBM_OA1_SW_OA1O_D52_Msk)       /**< Switch D52: Opamp1 output to sarbus0 */
#define CY_CTB_SW_OA1_OUT_SARBUS1      (CTBM_OA1_SW_OA1O_D62_Msk)       /**< Switch D62: Opamp1 output to sarbus1 */
#define CY_CTB_SW_OA1_OUT_SHORT_IN_EXT (CTBM_OA1_SW_OA1O_D82_Msk)       /**< Switch D82: Short Opamp1 internal (1x) with external (10x) outputs */

/** Common switch masks for OpAmp0 and OpAmp1 to be used in \ref Cy_CTB_SetAnalogSwitch. */
#define CY_CTB_SW_OA_NEG_OUT           (CY_CTB_SW_OA0_NEG_OUT)           /**< Switch OA0 A81 and OA1 A82 */
#define CY_CTB_SW_OA_OUT_SARBUS0       (CY_CTB_SW_OA0_OUT_SARBUS0)       /**< Switch OA0 A51 and OA1 A52 */
#define CY_CTB_SW_OA_OUT_SHORT_IN_EXT  (CY_CTB_SW_OA0_OUT_SHORT_IN_EXT)  /**< Switch OA0 D81 and OA1 D82 */
/** \} group_ctb_opamp_switch_macros */


/** \addtogroup group_ctb_sar_seq_switch_macros
* \{
*/
/**
* Masks for CTB switches that can be controlled by the hardware
* These masks are used in \ref Cy_CTB_EnableSarSeqCtrl and \ref Cy_CTB_DisableSarSeqCtrl.
*
* The SAR ADC subsystem supports analog routes through three CTB switches on SARBUS0 and SARBUS1.
* This control allows for pins on the CTB dedicated port to route to the SAR ADC input channels:
*
*   - D51: Connects the inverting terminal of OA0 to SARBUS0
*   - D52: Connects the inverting terminal of OA1 to SARBUS0
*   - D62: Connects the inverting terminal of OA1 to SARBUS1
*/
#define CY_CTB_SW_HW_CTRL_D51         (CTBM_CTB_SW_HW_CTRL_P2_HW_CTRL_Msk)  /**< Enable hardware control of the D51 switch */
#define CY_CTB_SW_HW_CTRL_D52_D62     (CTBM_CTB_SW_HW_CTRL_P3_HW_CTRL_Msk)  /**< Enable hardware control of the D52 and D62 switches */
#define CY_CTB_SW_HW_CTRL_D51_D52_D62 (CTBM_CTB_SW_HW_CTRL_P2_HW_CTRL_Msk | CTBM_CTB_SW_HW_CTRL_P3_HW_CTRL_Msk) /**< Enable hardware control of all three switches */
/** \} group_ctb_sar_seq_switch_macros */



/** \cond INTERNAL */
/**< The de-init value for most CTB registers */
#define CY_CTB_DEINIT                       (0UL)

/**< The de-init value for the Opamp0 switch control register */
#define CY_CTB_DEINIT_OA0_SW                (CTBM_OA0_SW_CLEAR_OA0P_A00_Msk \
                                            | CTBM_OA0_SW_CLEAR_OA0P_A20_Msk \
                                            | CTBM_OA0_SW_CLEAR_OA0P_A30_Msk \
                                            | CTBM_OA0_SW_CLEAR_OA0M_A11_Msk \
                                            | CTBM_OA0_SW_CLEAR_OA0M_A81_Msk \
                                            | CTBM_OA0_SW_CLEAR_OA0O_D51_Msk \
                                            | CTBM_OA0_SW_CLEAR_OA0O_D81_Msk)

/**< The de-init value for the Opamp1 switch control register */
#define CY_CTB_DEINIT_OA1_SW                (CTBM_OA1_SW_CLEAR_OA1P_A03_Msk \
                                            | CTBM_OA1_SW_CLEAR_OA1P_A13_Msk \
                                            | CTBM_OA1_SW_CLEAR_OA1P_A43_Msk \
                                            | CTBM_OA1_SW_CLEAR_OA1M_A22_Msk \
                                            | CTBM_OA1_SW_CLEAR_OA1M_A82_Msk \
                                            | CTBM_OA1_SW_CLEAR_OA1O_D52_Msk \
                                            | CTBM_OA1_SW_CLEAR_OA1O_D62_Msk \
                                            | CTBM_OA1_SW_CLEAR_OA1O_D82_Msk)

#define CY_CTB_TRIM_VALUE_MAX               (63UL)
#define CY_CTB_CURRENT_SEL_VALUE_MAX        (63UL)

/**< Macros for the conditions used by CY_ASSERT calls */

#define CY_CTB_OPAMPNUM(num)                (((num) == CY_CTB_OPAMP_0) || ((num) == CY_CTB_OPAMP_1) || ((num) == CY_CTB_OPAMP_BOTH))
#define CY_CTB_OPAMPNUM_ALL(num)            (((num) == CY_CTB_OPAMP_NONE) \
                                            || ((num) == CY_CTB_OPAMP_0) \
                                            || ((num) == CY_CTB_OPAMP_1) \
                                            || ((num) == CY_CTB_OPAMP_BOTH))

#define CY_CTB_CLKPUMP(clkPump)         (((clkPump) == CY_CTB_CLK_PUMP_HF      ) || \
                                         ((clkPump) == CY_CTB_CLK_PUMP_SRSS    ) || \
                                         ((clkPump) == CY_CTB_CLK_PUMP_HF_DIV_2))

#define CY_CTB_OAPOWER(power)               ((power) <= CY_CTB_POWER_HIGH)
#define CY_CTB_OAMODE(mode)                 (((mode) == CY_CTB_MODE_OPAMP_INTERNAL) \
                                            || ((mode) == CY_CTB_MODE_OPAMP_EXTERNAL) \
                                            || ((mode) == CY_CTB_MODE_COMP))
#define CY_CTB_OAPUMP(pump)                 (((pump) == CY_CTB_PUMP_DISABLE) || ((pump) == CY_CTB_PUMP_ENABLE))
#define CY_CTB_COMPEDGE(edge)               (((edge) == CY_CTB_COMP_EDGE_DISABLE) \
                                            || ((edge) == CY_CTB_COMP_EDGE_RISING) \
                                            || ((edge) == CY_CTB_COMP_EDGE_FALLING) \
                                            || ((edge) == CY_CTB_COMP_EDGE_BOTH))
#define CY_CTB_COMPLEVEL(level)             (((level) == CY_CTB_COMP_TRIGGER_OUT_PULSE) || ((level) == CY_CTB_COMP_TRIGGER_OUT_LEVEL))
#define CY_CTB_CURRENTMODE(mode)            (((mode) == CY_CTB_CURRENT_HIGH_ACTIVE) \
                                            || ((mode) == CY_CTB_CURRENT_HIGH_ACTIVE_DEEPSLEEP) \
                                            || ((mode) == CY_CTB_CURRENT_LOW_ACTIVE_DEEPSLEEP))
#define CY_CTB_TRIM(trim)                   ((trim) <= CY_CTB_TRIM_VALUE_MAX)
#define CY_CTB_OA0SWITCH(mask)              (((mask) & (~CY_CTB_DEINIT_OA0_SW)) == 0UL)
#define CY_CTB_OA1SWITCH(mask)              (((mask) & (~CY_CTB_DEINIT_OA1_SW)) == 0UL)

#define CY_CTB_SARSEQCTRL(mask)             (((mask) == CY_CTB_SW_HW_CTRL_D51) \
                                            || ((mask) == CY_CTB_SW_HW_CTRL_D52_D62) \
                                            || ((mask) == CY_CTB_SW_HW_CTRL_D51_D52_D62))
#define CY_CTB_CURRENT_SEL(biasCurrent)     ((biasCurrent) <= CY_CTB_CURRENT_SEL_VALUE_MAX)

#define CY_CTB_DSAB_CURRENT_SOURCE_CONFIG_Pos    PASS_DSAB_DSAB_CTRL_SEL_OUT_Pos
#define CY_CTB_DSAB_CURRENT_SOURCE_CONFIG_Msk    (PASS_DSAB_DSAB_CTRL_SEL_OUT_Msk | \
                                                  PASS_DSAB_DSAB_CTRL_REF_SWAP_EN_Msk)

/** \endcond */

/** \} group_ctb_macros */

/***************************************
*       Enumerated Types
***************************************/

/**
* \addtogroup group_ctb_enums
* \{
*/

/**
* Most functions allow you to configure a single opamp or both opamps at once.
* The \ref Cy_CTB_SetInterruptMask function can be called with \ref CY_CTB_OPAMP_NONE
* and interrupts will be disabled.
*/
typedef enum{
    CY_CTB_OPAMP_NONE    = 0UL,                                        /**< For disabling interrupts for both opamps. */
    CY_CTB_OPAMP_0       = CTBM_INTR_COMP0_Msk,                        /**< For configuring Opamp0 */
    CY_CTB_OPAMP_1       = CTBM_INTR_COMP1_Msk,                        /**< For configuring Opamp1 */
    CY_CTB_OPAMP_BOTH    = CTBM_INTR_COMP0_Msk | CTBM_INTR_COMP1_Msk,  /**< For configuring both Opamp0 and Opamp1 */
}cy_en_ctb_opamp_sel_t;


/**
* Configure the power mode of each opamp. Each power setting consumes different
* levels of current and supports a different input range and gain bandwidth.
* See the device datasheet for more details.
*/
typedef enum {
    CY_CTB_POWER_OFF       = 0UL,     /**< Opamp is off */
    CY_CTB_POWER_LOW       = 1UL,     /**< Low power mode */
    CY_CTB_POWER_MEDIUM    = 2UL,     /**< Medium power mode */
    CY_CTB_POWER_HIGH      = 3UL,     /**< High power mode */
}cy_en_ctb_power_t;

/**
* The output stage of each OpAmp can be configured for low-drive strength (1x) to drive internal circuits,
* for high-drive strength (10x) to drive external circuits, or as a comparator.
*/
typedef enum {
    CY_CTB_MODE_OPAMP_INTERNAL = 0UL,                                               /**< Configure opamp for low-drive strength for internal connections (1x) */
    CY_CTB_MODE_OPAMP_EXTERNAL = 1UL << CTBM_OA_RES0_CTRL_OA0_DRIVE_STR_SEL_Pos,    /**< Configure opamp high-drive strength for driving a device pin (10x) */
    CY_CTB_MODE_COMP           = 1UL << CTBM_OA_RES0_CTRL_OA0_COMP_EN_Pos,          /**< Configure opamp as a comparator */
}cy_en_ctb_output_t;

/**
* Each opamp has a charge pump to increase the input range to the rails.
* When the charge pump is enabled, the input range is 0 to VDDA.
* When disabled, the input range is 0 to VDDA - 1.5 V.
*
** <table class="doxtable">
*   <tr><th>Charge Pump</th><th>Input Range (V)</th></tr>
*   <tr>
*     <td>OFF</td>
*     <td>0 to VDDA-1.5</td>
*   </tr>
*   <tr>
*     <td>ON</td>
*     <td>0 to VDDA</td>
*   </tr>
* </table>
*
* Note that in Deep Sleep mode, the charge pump is disabled so the input
* range is reduced.
*/


/**
* Configure the type of edge that will trigger a comparator interrupt or
* disable the interrupt entirely.
*/
typedef enum
{
    CY_CTB_COMP_EDGE_DISABLE       = 0UL,                                       /**< Disabled, no interrupts generated */
    CY_CTB_COMP_EDGE_RISING        = 1UL << CTBM_OA_RES0_CTRL_OA0_COMPINT_Pos,  /**< The rising edge generates an interrupt */
    CY_CTB_COMP_EDGE_FALLING       = 2UL << CTBM_OA_RES0_CTRL_OA0_COMPINT_Pos,  /**< The falling edge generates an interrupt */
    CY_CTB_COMP_EDGE_BOTH          = 3UL << CTBM_OA_RES0_CTRL_OA0_COMPINT_Pos,  /**< Both edges generate an interrupt */
}cy_en_ctb_comp_edge_t;

/** Configure the comparator trigger output level when the output is synchronized. */
typedef enum
{
    CY_CTB_COMP_TRIGGER_OUT_PULSE    = 0UL,                                       /**< Send trigger pulse on each edge of the comparator output */
    CY_CTB_COMP_TRIGGER_OUT_LEVEL    = CTBM_OA_RES0_CTRL_OA0_DSI_LEVEL_Msk,       /**< The trigger output is the synchronized version of a comparator output */
}cy_en_ctb_comp_level_t;


/**
* Each opamp also has a programmable compensation capacitor block,
* that optimizes the stability of the opamp performance based on output load.
* The compensation cap will be set by the driver based on the OpAmp drive strength
* (internal 1x or external 10x) selection.
*/
typedef enum
{
    CY_CTB_OPAMP_COMPENSATION_CAP_OFF      = 0UL,       /**< No compensation */
    CY_CTB_OPAMP_COMPENSATION_CAP_MIN      = 1UL,       /**< Minimum compensation - for internal (1x) drive*/
    CY_CTB_OPAMP_COMPENSATION_CAP_MED      = 2UL,       /**< Medium compensation */
    CY_CTB_OPAMP_COMPENSATION_CAP_MAX      = 3UL,       /**< Maximum compensation - for external (10x) drive */
}cy_en_ctb_compensation_cap_t;


/** CTB charge pump clock sources */
typedef enum
{
    /** Use the high frequency clock divided by 2. See \ref group_sysclk_clk_hf. */
    CY_CTB_CLK_PUMP_HF_DIV_2    = 0UL,

    /** Use the high frequency clock. See \ref group_sysclk_clk_hf. */
    CY_CTB_CLK_PUMP_HF          = 1UL,

    /** Use a dedicated pump clock from SRSS \ref group_sysclk_clk_pump.
    *   Call the \ref Cy_SysClk_ClkPumpSetSource()  to configure the pump clock.
    */
    CY_CTB_CLK_PUMP_SRSS        = 3UL
}cy_en_ctb_clk_pump_source_t;

/**
* CTB  bias current sources
* The CTB uses two reference current generators, IPTAT and IZTC from DSAB block
*/
typedef enum
{
    CY_CTB_SRSS_ZTC_DSAB_PTAT    = 0UL,    /**< (default value) The ZTC output from SRSS and PTAT output from Deep Sleep Amplifier Bias (DSAB) */
    CY_CTB_DSAB_PTAT_SRSS_ZTC    = 1UL,    /**< The ZTC output from Deep Sleep Amplifier Bias (DSAB) and PTAT output from SRSS */
    CY_CTB_DSAB_PTAT_NO_ZTC      = 2UL,    /**< the ZTC output from Deep Sleep Analog Bias (DSAB) and No PTAT output */
    CY_CTB_NO_ZTC_DSAB_PTAT      = 3UL     /**< No ZTC output and PTAT output from Deep Sleep Amplifier Bias (DSAB) */
}cy_en_ctb_dsab_bias_source_t;


/** Return states for \ref Cy_CTB_Init, \ref Cy_CTB_OpampInit and \ref Cy_CTB_DeInit */
typedef enum {
    CY_CTB_SUCCESS    = 0x00UL,                                      /**< The initialization is completed successfully */
    CY_CTB_BAD_PARAM  = CY_CTB_ID | CY_PDL_STATUS_ERROR | 0x01UL,    /**< The input pointers were NULL and the initialization could not be completed */
}cy_en_ctb_status_t;

/** \} group_ctb_enums */

/***************************************
*       Configuration Structures
***************************************/

/**
* \addtogroup group_ctb_data_structures
* \{
*/

/**
* This configuration structure is used to initialize only one opamp of the CTB block.
* This structure is used with \ref Cy_CTB_OpampInit.
*/
typedef struct
{
    cy_en_ctb_power_t           power;          /**< Opamp power mode: off, low, medium, or high */
    cy_en_ctb_output_t          outputMode;     /**< Opamp usage mode: internal (1x) drive, external (10x) drive, or as a comparator */
    bool                        pump;           /**< Opamp charge pump: enable to increase input range for rail-to-rail operation */
    cy_en_ctb_comp_edge_t       compEdge;       /**< Comparator edge detection: disable, rising, falling, or both */
    cy_en_ctb_comp_level_t      compLevel;      /**< Comparator trigger output: pulse or level */
    bool                        compBypass;     /**< Comparator trigger output synchronization bypass */
    bool                        compHyst;       /**< Comparator hysteresis: enable 10 mV hysteresis */
    bool                        compIntrEn;     /**< Comparator interrupt enable */
    /* Routing control */
    uint32_t                    switchCtrl;     /**< The mask of switches to be closed.
                                                 *   Zero means do nothing with switches.
                                                 *   Be careful with these switches masks - they may be not identical for both OpAmps.
                                                 */
}cy_stc_ctb_opamp_config_t;

/**
* The configuration structure to set up the entire CTB to be used with \ref Cy_CTB_Init.
*/
typedef struct
{
    bool                        deepSleep;      /**< Enable the CTB during Deep Sleep */
    cy_stc_ctb_opamp_config_t const * oa0;      /**< Opamp0 configuration */
    cy_stc_ctb_opamp_config_t const * oa1;      /**< Opamp1 configuration */
}cy_stc_ctb_config_t;

/** \} group_ctb_data_structures */

/***************************************
*        Function Prototypes
***************************************/

/**
* \addtogroup group_ctb_functions
* \{
*/

/**
* \addtogroup group_ctb_functions_init
* This set of functions is for initializing, enabling, and disabling the CTB.
* \{
*/
cy_en_ctb_status_t Cy_CTB_Init(CTBM_Type * base, const cy_stc_ctb_config_t * config);
cy_en_ctb_status_t Cy_CTB_OpampInit(CTBM_Type * base, cy_en_ctb_opamp_sel_t opampNum, const cy_stc_ctb_opamp_config_t * config);
cy_en_ctb_status_t Cy_CTB_DeInit(CTBM_Type * base, bool deInitRouting);
              void Cy_CTB_Enable(CTBM_Type * base);
              void Cy_CTB_Disable(CTBM_Type * base);
/** \} */

/**
* \addtogroup group_ctb_functions_basic
* This set of functions is for configuring basic usage of the CTB.
* \{
*/
void Cy_CTB_SetDeepSleepMode(CTBM_Type * base, bool deepSleep);
void Cy_CTB_SetOutputMode(CTBM_Type * base, cy_en_ctb_opamp_sel_t opampNum, cy_en_ctb_output_t outputMode);
void Cy_CTB_SetPower(CTBM_Type * base, cy_en_ctb_opamp_sel_t opampNum, cy_en_ctb_power_t power, bool pump);
void Cy_CTB_SetPumpClkSource(CTBM_Type * base, cy_en_ctb_clk_pump_source_t pumpClk);
/** \} */

/**
* \addtogroup group_ctb_functions_comparator
* This set of functions is specific to Comparator mode
* \{
*/
void Cy_CTB_CompSetInterruptEdgeType(CTBM_Type * base, cy_en_ctb_opamp_sel_t compNum, cy_en_ctb_comp_edge_t edge);
uint32_t Cy_CTB_CompGetStatus(const CTBM_Type * base, cy_en_ctb_opamp_sel_t compNum);
/** \} */

/**
* \addtogroup group_ctb_functions_trim
* These are advanced functions for trimming the offset and slope of the opamps.
* Most users do not need to call these functions and can use the factory trimmed values.
* \{
*/
void Cy_CTB_OpampSetOffset(CTBM_Type * base, cy_en_ctb_opamp_sel_t opampNum, uint32_t trim);
uint32_t Cy_CTB_OpampGetOffset(const CTBM_Type * base, cy_en_ctb_opamp_sel_t opampNum);
void Cy_CTB_OpampSetSlope(CTBM_Type * base, cy_en_ctb_opamp_sel_t opampNum, uint32_t trim);
uint32_t Cy_CTB_OpampGetSlope(const CTBM_Type * base, cy_en_ctb_opamp_sel_t opampNum);
void Cy_CTB_DSAB_SetSource(CTBM_Type * base, cy_en_ctb_dsab_bias_source_t biasSource);
cy_en_ctb_dsab_bias_source_t Cy_CTB_DSAB_GetSource(const CTBM_Type * base);
void Cy_CTB_DSAB_SetCurrent(CTBM_Type * base, uint32_t biasCurrent);
uint32_t Cy_CTB_DSAB_GetCurrent(const CTBM_Type * base);
/** \} */

/**
* \addtogroup group_ctb_functions_switches
* This set of functions is for controlling routing switches.
* \{
*/
void Cy_CTB_SetAnalogSwitch(CTBM_Type * base, cy_en_ctb_opamp_sel_t opampNum, uint32_t switchMask, bool switchState);
uint32_t Cy_CTB_GetAnalogSwitch(const CTBM_Type * base, cy_en_ctb_opamp_sel_t opampNum);
__STATIC_INLINE void Cy_CTB_OpenAllSwitches(CTBM_Type * base);
__STATIC_INLINE void Cy_CTB_EnableSarSeqCtrl(CTBM_Type * base, uint32_t switchMask);
__STATIC_INLINE void Cy_CTB_DisableSarSeqCtrl(CTBM_Type * base, uint32_t switchMask);
/** \} */

/**
* \addtogroup group_ctb_functions_interrupts
* This set of functions is related to the comparator interrupts.
* \{
*/
__STATIC_INLINE uint32_t Cy_CTB_GetInterruptStatus(const CTBM_Type * base, cy_en_ctb_opamp_sel_t compNum);
__STATIC_INLINE void Cy_CTB_ClearInterrupt(CTBM_Type * base, cy_en_ctb_opamp_sel_t compNum);
__STATIC_INLINE void Cy_CTB_SetInterrupt(CTBM_Type * base, cy_en_ctb_opamp_sel_t compNum);
__STATIC_INLINE void Cy_CTB_SetInterruptMask(CTBM_Type * base, cy_en_ctb_opamp_sel_t compNum);
__STATIC_INLINE uint32_t Cy_CTB_GetInterruptMask(const CTBM_Type * base, cy_en_ctb_opamp_sel_t compNum);
__STATIC_INLINE uint32_t Cy_CTB_GetInterruptStatusMasked(const CTBM_Type * base, cy_en_ctb_opamp_sel_t compNum);
/** \} */

/**
* \addtogroup group_ctb_functions_switches
* \{
*/


/*******************************************************************************
* Function Name: Cy_CTB_OpenAllSwitches
****************************************************************************//**
*
* Open all the switches and disable all hardware control of the switches.
* Primarily used as a quick method of re-configuring all analog connections
* that are sparsely closed.
*
* \param base
* The pointer to structure-describing registers.
*
* \funcusage
* \snippet ctb_snippet.c CTB_SNIPPET_OPEN_ALL_SWITCHES
*
*******************************************************************************/
__STATIC_INLINE void Cy_CTB_OpenAllSwitches(CTBM_Type * base)
{
    CTBM_OA0_SW_CLEAR(base) = CY_CTB_DEINIT_OA0_SW;
    CTBM_OA1_SW_CLEAR(base) = CY_CTB_DEINIT_OA1_SW;
    CTBM_CTB_SW_HW_CTRL(base) = CY_CTB_DEINIT;
}


/*******************************************************************************
* Function Name: Cy_CTB_EnableSarSeqCtrl
****************************************************************************//**
*
* Enables the SAR sequencer control of specified switch(es).
*
* This allows the SAR ADC to use routes through the CTB when configuring its
* channels. See \ref group_sar_sarmux_ctb for the more details.
*
* There are three switches in the CTB that can be enabled by the SAR sequencer.
* - D51: This switch connects the output of Opamp0 to the SARBUS0
* - D52: This switch connects the output of Opamp1 to the SARBUS0
* - D62: This switch connects the output of Opamp1 to the SARBUS1
*
* \param base
* Pointer to structure describing registers
*
* \param switchMask
* The switch(es) in which to enable SAR sequencer control \ref group_ctb_sar_seq_switch_macros
*
* \funcusage
* \snippet ctb_snippet.c CTB_SNIPPET_ENABLE_SAR_SEQ_CTRL
*
*******************************************************************************/
__STATIC_INLINE void Cy_CTB_EnableSarSeqCtrl(CTBM_Type * base, uint32_t switchMask)
{
    CY_ASSERT_L3(CY_CTB_SARSEQCTRL(switchMask));

    CTBM_CTB_SW_HW_CTRL(base) |= CY_CTB_SW_HW_CTRL_D51_D52_D62 & switchMask;
}


/*******************************************************************************
* Function Name: Cy_CTB_DisableSarSeqCtrl
****************************************************************************//**
*
* Disables the SAR sequencer control of specified switch(es).
*
* \param base
* The pointer to structure-describing registers.
*
* \param switchMask
* The switch(es) in which to disable SAR sequencer control \ref group_ctb_sar_seq_switch_macros
*
* \funcusage \snippet ctb_snippet.c CTB_SNIPPET_DISABLE_SAR_SEQ_CTRL
*
*******************************************************************************/
__STATIC_INLINE void Cy_CTB_DisableSarSeqCtrl(CTBM_Type * base, uint32_t switchMask)
{
    CY_ASSERT_L3(CY_CTB_SARSEQCTRL(switchMask));

    CTBM_CTB_SW_HW_CTRL(base) &= ~(CY_CTB_SW_HW_CTRL_D51_D52_D62 & switchMask);
}
/** \} */

/**
* \addtogroup group_ctb_functions_interrupts
* \{
*/

/*******************************************************************************
* Function Name: Cy_CTB_GetInterruptStatus
****************************************************************************//**
*
* Returns the status of the interrupt when the configured comparator
* edge is detected.
*
* \param base
* The pointer to structure-describing registers.
*
* \param compNum
* \ref CY_CTB_OPAMP_0, \ref CY_CTB_OPAMP_1, or \ref CY_CTB_OPAMP_BOTH
*
* \return
* The interrupt status.
* If compNum is \ref CY_CTB_OPAMP_BOTH, cast the returned status
* to \ref cy_en_ctb_opamp_sel_t to determine which comparator edge (or both)
* was detected.
* - 0: The edge was not detected
* - Non-zero: The configured edge type was detected.
*
* \funcusage
* \snippet ctb_snippet.c SNIPPET_COMP_GETINTERRUPTSTATUS
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_CTB_GetInterruptStatus(const CTBM_Type * base, cy_en_ctb_opamp_sel_t compNum)
{
    CY_ASSERT_L3(CY_CTB_OPAMPNUM(compNum));

    return CTBM_INTR(base) & (uint32_t) compNum;
}


/*******************************************************************************
* Function Name: Cy_CTB_ClearInterrupt
****************************************************************************//**
*
* Clears the CTB comparator triggered interrupt.
* The interrupt must be cleared with this function so that the hardware
* can set subsequent interrupts and those interrupts can be forwarded
* to the interrupt controller, if enabled.
*
* \param base
* The pointer to structure-describing registers.
*
* \param compNum
* \ref CY_CTB_OPAMP_0, \ref CY_CTB_OPAMP_1, or \ref CY_CTB_OPAMP_BOTH
*
*******************************************************************************/
__STATIC_INLINE void Cy_CTB_ClearInterrupt(CTBM_Type * base, cy_en_ctb_opamp_sel_t compNum)
{
    CY_ASSERT_L3(CY_CTB_OPAMPNUM(compNum));

    CTBM_INTR(base) = (uint32_t) compNum;

    /* Dummy read for buffered writes. */
    (void) CTBM_INTR(base);
}


/*******************************************************************************
* Function Name: Cy_CTB_SetInterrupt
****************************************************************************//**
*
* Forces the CTB interrupt to trigger using software.
*
* \param base
* The pointer to structure-describing registers.
*
* \param compNum
* \ref CY_CTB_OPAMP_0, \ref CY_CTB_OPAMP_1, or \ref CY_CTB_OPAMP_BOTH
*
*******************************************************************************/
__STATIC_INLINE void Cy_CTB_SetInterrupt(CTBM_Type * base, cy_en_ctb_opamp_sel_t compNum)
{
    CY_ASSERT_L3(CY_CTB_OPAMPNUM(compNum));

    CTBM_INTR_SET(base) = (uint32_t) compNum;
}


/*******************************************************************************
* Function Name: Cy_CTB_SetInterruptMask
****************************************************************************//**
*
* Configures the CTB comparator edge interrupt to be forwarded to the CPU
* interrupt controller.
*
* \param base
* The pointer to structure-describing registers.
*
* \param compNum
* \ref CY_CTB_OPAMP_NONE, \ref CY_CTB_OPAMP_0, \ref CY_CTB_OPAMP_1, or \ref CY_CTB_OPAMP_BOTH.
* Calling this function with CY_CTB_OPAMP_NONE will disable all interrupt requests.
*
* \funcusage
* \snippet ctb_snippet.c CTB_SNIPPET_SET_INTERRUPT_MASK
*
*******************************************************************************/
__STATIC_INLINE void Cy_CTB_SetInterruptMask(CTBM_Type * base, cy_en_ctb_opamp_sel_t compNum)
{
    CY_ASSERT_L3(CY_CTB_OPAMPNUM_ALL(compNum));

    CTBM_INTR_MASK(base) = (uint32_t) compNum;
}


/*******************************************************************************
* Function Name: Cy_CTB_GetInterruptMask
****************************************************************************//**
*
* Returns whether the CTB comparator edge interrupt output is
* forwarded to the CPU interrupt controller as configured by
* \ref Cy_CTB_SetInterruptMask.
*
* \param base
* The pointer to structure-describing registers.
*
* \param compNum
* \ref CY_CTB_OPAMP_0, \ref CY_CTB_OPAMP_1, or \ref CY_CTB_OPAMP_BOTH
*
* \return
* The interrupt mask.
* If compNum is \ref CY_CTB_OPAMP_BOTH, cast the returned mask
* to \ref cy_en_ctb_opamp_sel_t to determine which comparator interrupt
* output (or both) is forwarded.
* - 0: None interrupt output was forwarded to the interrupt controller.
* - Non-zero: An interrupt output was forwarded to the interrupt controller.
*
* \funcusage
* \snippet ctb_snippet.c CTB_SNIPPET_GET_INTERRUPT_MASK
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_CTB_GetInterruptMask(const CTBM_Type * base, cy_en_ctb_opamp_sel_t compNum)
{
    CY_ASSERT_L3(CY_CTB_OPAMPNUM(compNum));

    return CTBM_INTR_MASK(base)  & (uint32_t) compNum;
}


/*******************************************************************************
* Function Name: Cy_CTB_GetInterruptStatusMasked
****************************************************************************//**
*
* Returns the CTB comparator edge output interrupt state after being masked.
* This is the bitwise AND of \ref Cy_CTB_GetInterruptStatus and \ref Cy_CTB_GetInterruptMask.
*
* \param base
* The pointer to structure-describing registers.
*
* \param compNum
* \ref CY_CTB_OPAMP_0, \ref CY_CTB_OPAMP_1, or \ref CY_CTB_OPAMP_BOTH
*
* \return
* If compNum is \ref CY_CTB_OPAMP_BOTH, cast the returned value
* to \ref cy_en_ctb_opamp_sel_t to determine which comparator interrupt
* output (or both) was detected and masked.
* - 0: The configured edge was not detected or masked.
* - Non-zero: The configured edge type was detected and masked
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_CTB_GetInterruptStatusMasked(const CTBM_Type * base, cy_en_ctb_opamp_sel_t compNum)
{
    CY_ASSERT_L3(CY_CTB_OPAMPNUM(compNum));

    return CTBM_INTR_MASKED(base) & (uint32_t) compNum;
}
/** \} */
/** \} group_ctb_functions */

#if defined(__cplusplus)
}
#endif

#endif /* CY_IP_M0S8PASS4A_CTB */
#endif /** !defined(CY_CTB_H) */

/** \} group_ctb */

/* [] END OF FILE */
