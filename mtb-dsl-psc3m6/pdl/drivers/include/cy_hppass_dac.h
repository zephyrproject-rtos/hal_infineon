/***************************************************************************//**
* \file cy_hppass_dac.h
* \version 1.0.0
*
* Header file for the DAC subsystem of the High Performance Programmable Analog Sub-System.
*
********************************************************************************
* \copyright
* (c) 2024-2026, Infineon Technologies AG, or an affiliate of Infineon
* Technologies AG.
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
* \addtogroup group_hppass_dac
* \{
* The DAC driver provides an API to configure and control the Digital-to-Analog
* Converter (DAC) Buffer subsystem within the High Performance Programmable
* Analog Sub-System (HPPASS).
*
* The HPPASS DAC Buffer subsystem provides two independent 12-bit DAC instances
* with integrated output buffers. Each DAC includes bit resynchronization to ensure
* proper time alignment of all bits before conversion. The integrated buffer provides
* 10mA drive capability for external loads or can drive internal analog IPs (ADC, AFE,
* Comparator) at reduced current (50uA). The DAC can generate DC voltages or AC
* waveforms including sine waves, square waves, and triangle waves.
*
* \section section_hppass_dac_features Features
* * Two independent DAC buffer instances (0 and 1)
* * 12-bit DAC resolution with bit resynchronization
* * Integrated output buffer with 10mA drive capability
* * Dual output modes:
*   - External pin drive: Full 10mA current capability
*   - Internal IP drive: 50uA to ADC/AFE/Comparator (pin in HiZ)
* * Supply voltage range: 1.71V to 3.63V
* * Reference voltage:
*   - VDDA (typically 3.3V)
*   \note External VREF is not supported for DAC. Only VDDA reference is available.
* * Integrated Sample and Hold circuit:
*   - Glitch suppression during DAC transitions
*   - Selectable enable/disable in active mode
* * Buffer drive strength modes:
*   - Low: Minimal power consumption, lighter loads
*   - Medium: Balanced power and drive capability
*   - High: Increased drive capability (default)
*   - Ultra: Maximum drive current for heavy loads
* * Scalable buffer drive capability:
*   - Maximum: 10mA DC load
*   - Minimum: 100pF capacitive load
* * Multiple DAC operating modes:
*   - Buffered Mode: Single value transfer on trigger
*   - Hysteretic Mode: Toggle between two values
*   - Rising/Falling/Triangular Slope Modes: Automatic ramping
*   - LUT Modes: Waveform generation from lookup table
*   - FIFO Mode: Stream data from FIFO
*   - ADC Loopback Mode: Direct ADC to DAC connection
* * Hardware trigger support (TR0-TR15 from MCPASS infrastructure)
* * Programmable update period with integer and fractional dividers
* * 8-entry FIFO (8 32-bit entries, always 8 entries regardless of access mode)
* * Four FIFO access modes: Single/Double Word, LSB/MSB alignment
* * Seven interrupt sources for event notification
* * Integrated comparator with hysteresis control
* * Parameter synchronization for atomic multi-register updates
* * Continuous and one-shot operation modes
* * DAC usable independently with buffer disabled
*
* \section section_hppass_dac_configuration Configuration Considerations
*
* The DAC Buffer is configured using the \ref cy_stc_hppass_dac_buf_config_t
* structure which provides access to all DAC control registers:
*
* \subsection subsection_dac_buffer_drive Buffer Drive Strength Modes
* The integrated output buffer supports four drive strength modes to optimize
* power consumption based on load requirements:
* * **Low (0)**: Minimum power consumption
*   - Suitable for light resistive loads or high-impedance inputs
*   - Lowest current drive capability
*   - Reduced power consumption
* * **Medium (1)**: Balanced performance
*   - Moderate loads up to several kOhm
*   - Balance between power and drive capability
* * **High (2)**: Enhanced drive capability (Default)
*   - Standard loads, typical operating mode
*   - Good balance of performance and power
* * **Ultra (3)**: Maximum drive capability
*   - Heavy capacitive loads (up to 100pF) or low-impedance loads
*   - Maximum DC current capability (up to 10mA)
*   - Highest power consumption
*
* Select the lowest drive strength mode that meets your load requirements to
* minimize power consumption. The drive strength affects both output current
* capability and settling time characteristics.
*
* \note HPPASS DAC Buffer operates only in CPU Active mode. The peripheral is
* automatically disabled in Deep Sleep and Hibernate modes.
*
* \subsection subsection_dac_output_routing Output Routing
* The buffer can drive two different paths:
* * **External Pin Drive**: Direct connection to pin
*   - No mux in path
*   - Full 10mA current capability
*   - Primary application mode
* * **Internal IP Drive**: Connection to ADC, AFE, or Comparator
*   - 50uA drive current
*   - External pin must be set to HiZ mode
*
* \subsection subsection_dac_reference Reference Voltage Selection
* Only VDDA reference is supported for the DAC:
* * **VDDA**: Typically 3.3V, suitable for full-range operation
*
* \note External VREF is not supported for the DAC. The referenceSelect
*       field in \ref cy_stc_hppass_dac_buf_config_t must be set to 0 (VDDA).
*
* Supply voltage range: 1.71V to 3.63V
*
* \subsection subsection_dac_sample_hold Sample and Hold Operation
* Integrated Sample and Hold circuit provides:
* * Glitch suppression during DAC value transitions
* * Output transitions to final value before being sampled
* * Prevents unwanted glitches from propagating through buffer
* * Holding capacitor used only for glitch suppression
* * Can be enabled or disabled via configuration
*   - S&H Enabled: Used only during transitions, then direct drive
*   - S&H Disabled: S&H switch always ON, continuous drive
* * Special pulse generation for hibernate/deep sleep entry
*
* \subsection subsection_dac_triggers Trigger Configuration
* Both start and update triggers can be selected from TR0-TR15 or disabled:
* * Start Trigger: Initiates DAC_MODE operation
* * Update Trigger: Updates DAC value or advances through mode sequence
* * Triggers must be configured in PULSE mode
* * Maximum trigger frequency: CSG_CLOCK/2
*
* \subsection subsection_dac_modes Operating Modes
* The DAC supports 10 distinct operating modes:
* * **Buffered (0)**: Transfer DAC_VAL_A to DAC output on trigger
* * **Hysteretic (1)**: Toggle between DAC_VAL_A (high) and DAC_VAL_B (low)
* * **Rising Slope (2)**: Increment from DAC_VAL_A to DAC_VAL_B by DAC_STEP
* * **Falling Slope (3)**: Decrement from DAC_VAL_A to DAC_VAL_B by DAC_STEP
* * **Triangular Slope (4)**: Rising then falling slope between values
* * **LUT Forward (5)**: Output LUT waveform with incrementing addresses
* * **LUT Reverse (6)**: Output LUT waveform with decrementing addresses
* * **LUT Forward Reverse (7)**: LUT with incrementing then decrementing addresses
* * **FIFO (8)**: Source data from the FIFO buffer
* * **ADC Loopback (9)**: Source data from ADC loopback path
*
* \subsection subsection_dac_continuous Continuous vs One-Shot
* Slope and LUT modes support continuous operation:
* * One-Shot (continuousMode = false): Operation stops at end value, last output held
* * Continuous (continuousMode = true): Operation automatically restarts when end reached
*
* \subsection subsection_dac_step Step Size Configuration
* For Slope and LUT modes, step size determines advancement rate:
* * Actual step = DAC_STEP + 1 (range: 1-64)
* * In LUT mode, each step jumps to new LUT value on WORD boundaries
*   - DAC_STEP = 0 (step size 1): advances LUT address by 4
*   - DAC_STEP = 1 (step size 2): advances LUT address by 8, etc.
*
* \subsection subsection_dac_lut LUT Operation
* The LUT (Look-Up Table) contains 128 entries of 12-bit DAC values (0-4095).
* Each entry is stored in a 32-bit register, using bits [11:0].
* To populate the LUT, use the provided PDL functions:
* \code
* // Example: Write a sine wave to LUT
* uint16_t sineWave[128] = { ... 128 sine values 0-4095 ... };
* Cy_HPPASS_DAC_LutFill(0, 0, sineWave, 128);
* \endcode
* Or write individual entries:
* \code
* Cy_HPPASS_DAC_LutWrite(0, 0, 2048); // Mid-scale value
* \endcode
* To read LUT entries:
* \code
* uint16_t value = Cy_HPPASS_DAC_LutRead(0, 0);
* \endcode
* LUT modes use the step size to control address advancement rate.
*
* \subsection subsection_dac_fifo FIFO Operation
* The FIFO has 8 32-bit entries and supports four access modes that determine how
* DAC values are packed:
* * Single Word modes: one 12-bit DAC value per 32-bit entry
* * Double Word modes: two 12-bit DAC values packed per 32-bit entry
*
* Access modes:
* * Single Word LSB Alignment (0): Data[11:0]
* * Single Word MSB Alignment (1): Data[31:20]
* * Double Word LSB Alignment (2): Word0[11:0], Word1[27:16]
* * Double Word MSB Alignment (3): Word0[15:4], Word1[31:20]
*
* \note The FIFO entry count is always 8, regardless of access mode.
*   Each 32-bit FIFO entry stores:
*   - Single Word mode: One 12-bit DAC value (in bits [11:0] or [31:20])
*   - Double Word mode: Two 12-bit DAC values (in Word0 and Word1 positions)
*
* \subsection subsection_dac_param_sync Parameter Synchronization
* When enabled, parameter updates are synchronized:
* * Write to DAC_VAL_A, DAC_VAL_B, DAC_PERIOD, DAC_STEP registers
* * Set DAC_PARAM_SYNC.READY to indicate parameters are ready
* * On next DAC trigger, all parameters update atomically
* * Hardware automatically clears READY flag after update
* * Useful for cascade operation across multiple DAC slices
*
* \subsection subsection_dac_interrupts Interrupt Sources
* Seven interrupt sources provide event notification:
* * FIFO_OVERFLOW: FIFO full condition reached
* * FIFO_UNDERFLOW: FIFO empty (0 elements)
* * FIFO_PAST_UNDERFLOW: Trigger attempted to pull from empty FIFO
* * FIFO_LOW_THRESHOLD: Only 3 32-bit FIFO entries remaining
* * HW_START: DAC_MODE started by hardware trigger
* * SLOPE_DONE: Slope or LUT mode sequence completed
* * BUF_EMPTY: Buffered/Hysteretic value transferred to active
*
* \section section_hppass_dac_usage Usage Examples
*
* \subsection subsection_dac_basic_init Basic Initialization
* \code
* // Configure DAC for buffered mode with TR0 trigger
* cy_stc_hppass_dac_buf_config_t dacConfig =
* {
*     .startTriggerSelect = CY_HPPASS_DAC_TRIG_TR0,
*     .updateTriggerSelect = CY_HPPASS_DAC_TRIG_TR0,
*     .mode = CY_HPPASS_DAC_BUF_MODE_BUFFERED,
*     .continuousMode = false,
*     .skipTriggerEnable = false,
*     .paramSyncEnable = false,
*     .stepSize = 0,
*     .fifoAccessMode = 0,
*     .paramSyncReady = false,
*     .valueA = 2048,  // Mid-scale value
*     .valueB = 0,
*     .updatePeriodInteger = 100,
*     .updatePeriodFractional = 0,
*     .powerEnable = true,
*     .comparatorEnable = false,
*     .compDirection = CY_HPPASS_DAC_COMP_DIR_RISING,
*     .comparatorHysteresisEnable = false,
*     .enableGainBoost = false,
*     .referenceSelect = 0,  // VDDA
*     .bufferOutputSelect = 0,
*     .powerMode = 2,  // High drive strength mode (default)
* };
*
* // Initialize DAC instance 0
* Cy_HPPASS_DAC_Init(0, &dacConfig);
*
* // Enable DAC
* Cy_HPPASS_DAC_Enable(0);
* \endcode
*
* \subsection subsection_dac_slope_example Slope Mode Example
* \code
* // Configure DAC for rising slope mode
* cy_stc_hppass_dac_buf_config_t slopeConfig =
* {
*     .startTriggerSelect = CY_HPPASS_DAC_TRIG_TR1,
*     .updateTriggerSelect = CY_HPPASS_DAC_TRIG_TIMER,
*     .mode = CY_HPPASS_DAC_BUF_MODE_SLOPE_RISING,
*     .continuousMode = true,  // Restart at end
*     .stepSize = 15,  // Step size = 16
*     .valueA = 0,     // Start value
*     .valueB = 4095,  // End value
*     .updatePeriodInteger = 10,  // Update every 11 clocks
*     .updatePeriodFractional = 0,
*     .powerEnable = true,
*     .powerMode = 2
* };
*
* Cy_HPPASS_DAC_Init(0, &slopeConfig);
* Cy_HPPASS_DAC_Enable(0);
*
* // Start slope generation via firmware
* Cy_HPPASS_DAC_FWStart(0, true);
* \endcode
*
* \subsection subsection_dac_fifo_example FIFO Mode Example
* \code
* // Example for Single Word mode (8 DAC values max)
* uint32_t waveform[8];
* uint32_t count = 8;
*
* // Fill waveform buffer with sine wave samples (8 values for Single Word mode)
* for (int i = 0; i < 8; i++) {
*     waveform[i] = (uint32_t)(2048 + 2000 * sin(2 * PI * i / 8));
* }
*
* // Note: Using Double Word access mode allows 16 DAC values to be stored
* // in the 8 32-bit FIFO entries (two 12-bit values packed per entry).
*
* // Configure DAC for FIFO mode
* cy_stc_hppass_dac_buf_config_t fifoConfig =
* {
*     .mode = CY_HPPASS_DAC_BUF_MODE_FIFO,
*     .fifoAccessMode = 0,  // Single word LSB
*     .updateTriggerSelect = CY_HPPASS_DAC_TRIG_TIMER,
*     .powerEnable = true
* };
*
* Cy_HPPASS_DAC_Init(0, &fifoConfig);
*
* // Clear and fill FIFO
* Cy_HPPASS_DAC_FIFO_Clear(0);
* Cy_HPPASS_DAC_FIFO_DataFill(0, waveform, &count);
*
* // Enable interrupts for FIFO management
* Cy_HPPASS_DAC_Buf_SetInterruptMask(0, CY_HPPASS_DAC_INTR_FIFO_LOW_THRESHOLD);
*
* Cy_HPPASS_DAC_Enable(0);
* \endcode
*
* \section section_hppass_dac_notes Important Notes
* * Always call Cy_HPPASS_DAC_Init() before enabling the DAC
* * Supply voltage must be within 1.71V to 3.63V range
* * DAC includes bit resynchronization for proper time alignment
* * DAC can be used independently without enabling the buffer
* * When buffer is disabled, output is in HiZ and doesn't load DAC
* * Buffer drive strength should match load requirements (up to 10mA max with 100pF capacitive)
* * For external pin drive, use full 10mA capability
* * For internal IP drive (ADC/AFE/Comparator), use 50uA mode and set pin to HiZ
* * Sample and Hold suppresses glitches during transitions
* * In S&H enabled mode, switch closes after transition for direct drive
* * HPPASS operates only in CPU Active mode (not available in Deep Sleep/Hibernate)
* * DAC reference must be VDDA (3.3V typ); external VREF is not supported
* * MCPASS HW/FW triggers (TR0-TR15) must be configured in PULSE mode
* * Maximum trigger frequency is limited to CSG_CLOCK/2
* * Writing to DAC_VAL register stops active DAC_MODE operation
* * Parameter sync is useful for glitch-free updates of multiple parameters
* * Skip trigger enable should be set before operation begins and remain set
* * FIFO has 8 32-bit entries (8 DAC values in Single Word mode, 16 in Double Word mode);
*   monitor FIFO_LOW_THRESHOLD interrupt to avoid underflow
* * Update period: actual period = (1 + PERIOD_INT) + (PERIOD_FRAC/32) clocks
* * DAC can generate DC voltages or AC waveforms (sine, square, triangle)
* * DAC_BUFFER_ANA_CTRL_1 is a non-retention register; its contents are lost
*   when the DAC is not enabled. Cy_HPPASS_DAC_Init() enables the DAC before
*   writing ANA_CTRL_1 to ensure the configuration is retained.
*
* \defgroup group_hppass_dac_macros Macros
* \defgroup group_hppass_dac_functions Functions
* \defgroup group_hppass_dac_data_structures Data Structures
* \defgroup group_hppass_dac_enums Enumerated Types
*
* \} */

#if !defined(CY_HPPASS_DAC_H)
#define CY_HPPASS_DAC_H

#include "cy_device.h"

#if defined(CY_IP_MXS40MCPASS) && (CY_IP_MXS40MCPASS_VERSION >= 3u)

#include "cy_syslib.h"
#include <stddef.h>
#include <stdbool.h>

#if defined(__cplusplus)
extern "C" {
#endif

/**
* \addtogroup group_hppass_dac_macros
* \{
*/

/** Driver major version */
#define CY_HPPASS_DAC_DRV_VERSION_MAJOR       1

/** Driver minor version */
#define CY_HPPASS_DAC_DRV_VERSION_MINOR       0

/** DAC BUFFER FIFO overflow interrupt. Set once when FIFO reaches full. If no data is pulled from the FIFO,
 *  this interrupt shall not continue firing. This interrupt will be asserted when there is 0 room for data
 *  available during Single Word access mode. This interrupt will be asserted when there is room for 0 or 1
 *  words available during Double Word access mode. */
#define CY_HPPASS_DAC_INTR_FIFO_OVERFLOW              (HPPASS_DAC_BUFFER_DAC_BUFFER_DAC_BUFFER_INTR_DAC_BUFFER_FIFO_OVERFLOW_Msk)

/** DAC BUFFER FIFO underflow interrupt. Set when FIFO has 0 elements i.e. is empty. */
#define CY_HPPASS_DAC_INTR_FIFO_UNDERFLOW             (HPPASS_DAC_BUFFER_DAC_BUFFER_DAC_BUFFER_INTR_DAC_BUFFER_FIFO_UNDERFLOW_Msk)

/** DAC BUFFER FIFO past underflow interrupt. Set when FIFO is empty, but Trigger tries to pull data from the empty FIFO. */
#define CY_HPPASS_DAC_INTR_FIFO_PAST_UNDERFLOW        (HPPASS_DAC_BUFFER_DAC_BUFFER_DAC_BUFFER_INTR_DAC_BUFFER_FIFO_PAST_UNDERFLOW_Msk)

/** DAC BUFFER FIFO low threshold interrupt. Set when FIFO is almost empty i.e. FIFO space left with just 3 entries. */
#define CY_HPPASS_DAC_INTR_FIFO_LOW_THRESHOLD         (HPPASS_DAC_BUFFER_DAC_BUFFER_DAC_BUFFER_INTR_DAC_BUFFER_FIFO_LOW_THRESHOLD_Msk)

/** DAC hardware start interrupt. This DAC_MODE operation was started with a HW START trigger. */
#define CY_HPPASS_DAC_INTR_HW_START                   (HPPASS_DAC_BUFFER_DAC_BUFFER_DAC_BUFFER_INTR_DAC_HW_START_Msk)

/** DAC slope done interrupt. When SLOPE or LUT mode is enabled, this interrupt is set when the SLOPE
 *  (or LUT waveform) has completed. This interrupt is also set periodically on the last value of a DAC
 *  SLOPE in continuous mode. */
#define CY_HPPASS_DAC_INTR_SLOPE_DONE                 (HPPASS_DAC_BUFFER_DAC_BUFFER_DAC_BUFFER_INTR_DAC_SLOPE_DONE_Msk)

/** DAC buffer empty interrupt. When BUFFERED or HYSTERETIC mode is enabled, this interrupt is set when
 *  there is a DAC UPDATE trigger that transfers the buffered value(s) to active value(s) (see mode operation)
 *  and it means that the user may write new values to the buffer registers. */
#define CY_HPPASS_DAC_INTR_BUF_EMPTY                  (HPPASS_DAC_BUFFER_DAC_BUFFER_DAC_BUFFER_INTR_DAC_BUF_EMPTY_Msk)

#define CY_HPPASS_DAC_NUM_INSTANCE             (2U)  /**< The number of DAC buffer instances available */
#define CY_HPPASS_DAC_INDEX_VALID(dacIdx)      (CY_HPPASS_DAC_NUM_INSTANCE > (dacIdx))  /**< For validating the DAC buffer index passed */

/** \} group_hppass_dac_macros */


/**
* \addtogroup group_hppass_dac_enums
* \{
*/

/** DAC status definitions */
typedef enum
{
    CY_HPPASS_DAC_SUCCESS   = 0x00UL,  /**< Success */
    CY_HPPASS_DAC_BAD_PARAM = 0x01UL,  /**< Invalid parameter */
} cy_en_hppass_dac_status_t;

/** DAC Buffer trigger source selection (for both start and update triggers) */
typedef enum
{
    CY_HPPASS_DAC_TRIG_DISABLED             = 0UL,  /**< Trigger disabled */
    CY_HPPASS_DAC_TRIG_TR0                  = 1UL,  /**< MCPASS HW/FW Trigger TR0 (PULSE mode) */
    CY_HPPASS_DAC_TRIG_TR1                  = 2UL,  /**< MCPASS HW/FW Trigger TR1 (PULSE mode) */
    CY_HPPASS_DAC_TRIG_TR2                  = 3UL,  /**< MCPASS HW/FW Trigger TR2 (PULSE mode) */
    CY_HPPASS_DAC_TRIG_TR3                  = 4UL,  /**< MCPASS HW/FW Trigger TR3 (PULSE mode) */
    CY_HPPASS_DAC_TRIG_TR4                  = 5UL,  /**< MCPASS HW/FW Trigger TR4 (PULSE mode) */
    CY_HPPASS_DAC_TRIG_TR5                  = 6UL,  /**< MCPASS HW/FW Trigger TR5 (PULSE mode) */
    CY_HPPASS_DAC_TRIG_TR6                  = 7UL,  /**< MCPASS HW/FW Trigger TR6 (PULSE mode) */
    CY_HPPASS_DAC_TRIG_TR7                  = 8UL,  /**< MCPASS HW/FW Trigger TR7 (PULSE mode) */
    CY_HPPASS_DAC_TRIG_TR8                  = 9UL,  /**< MCPASS HW/FW Trigger TR8 (PULSE mode) */
    CY_HPPASS_DAC_TRIG_TR9                  = 10UL, /**< MCPASS HW/FW Trigger TR9 (PULSE mode) */
    CY_HPPASS_DAC_TRIG_TR10                 = 11UL, /**< MCPASS HW/FW Trigger TR10 (PULSE mode) */
    CY_HPPASS_DAC_TRIG_TR11                 = 12UL, /**< MCPASS HW/FW Trigger TR11 (PULSE mode) */
    CY_HPPASS_DAC_TRIG_TR12                 = 13UL, /**< MCPASS HW/FW Trigger TR12 (PULSE mode) */
    CY_HPPASS_DAC_TRIG_TR13                 = 14UL, /**< MCPASS HW/FW Trigger TR13 (PULSE mode) */
    CY_HPPASS_DAC_TRIG_TR14                 = 15UL, /**< MCPASS HW/FW Trigger TR14 (PULSE mode) */
    CY_HPPASS_DAC_TRIG_TR15                 = 16UL, /**< MCPASS HW/FW Trigger TR15 (PULSE mode) */
} cy_en_hppass_dac_buf_trigger_sel_t;

/** DAC Buffer mode selection */
typedef enum
{
    CY_HPPASS_DAC_BUF_MODE_BUFFERED             = 0UL,  /**< Single Value Buffered Mode: Transfer data from DAC_VAL_A to DAC_VAL on trigger */
    CY_HPPASS_DAC_BUF_MODE_HYSTERETIC           = 1UL,  /**< Two Value Hysteretic Buffered Mode: Toggle between DAC_VAL_A (high) and DAC_VAL_B (low) */
    CY_HPPASS_DAC_BUF_MODE_SLOPE_RISING         = 2UL,  /**< Rising Slope Mode: Increment from DAC_VAL_A to DAC_VAL_B by DAC_STEP */
    CY_HPPASS_DAC_BUF_MODE_SLOPE_FALLING        = 3UL,  /**< Falling Slope Mode: Decrement from DAC_VAL_A to DAC_VAL_B by DAC_STEP */
    CY_HPPASS_DAC_BUF_MODE_SLOPE_TRIANGULAR     = 4UL,  /**< Triangular Slope Mode: Rising then Falling slope between DAC_VAL_A and DAC_VAL_B */
    CY_HPPASS_DAC_BUF_MODE_LUT_FORWARD          = 5UL,  /**< LUT Forward Mode: Output LUT waveform with incrementing addresses */
    CY_HPPASS_DAC_BUF_MODE_LUT_REVERSE          = 6UL,  /**< LUT Reverse Mode: Output LUT waveform with decrementing addresses */
    CY_HPPASS_DAC_BUF_MODE_LUT_FWD_REV          = 7UL,  /**< LUT Forward Reverse Mode: LUT with incrementing then decrementing addresses */
    CY_HPPASS_DAC_BUF_MODE_FIFO                 = 8UL,  /**< FIFO Mode: Source data from the FIFO */
    CY_HPPASS_DAC_BUF_MODE_ADC_LOOPBACK         = 9UL,  /**< ADC Loopback Mode: Source data from the ADC loopback mechanism */
} cy_en_hppass_dac_buf_mode_sel_t;

/** DAC Buffer comparator direction */
typedef enum
{
    CY_HPPASS_DAC_COMP_DIR_RISING           = 0UL,  /**< Rising direction */
    CY_HPPASS_DAC_COMP_DIR_FALLING          = 1UL,  /**< Falling direction */
} cy_en_hppass_dac_buf_comp_direction_t;

/** \} group_hppass_dac_enums */


/**
* \addtogroup group_hppass_dac_data_structures
* \{
*/

/** DAC Buffer configuration structure */
typedef struct
{
    /* DAC_BUFFER_CFG register fields */
    cy_en_hppass_dac_buf_trigger_sel_t startTriggerSelect;   /**< DAC start trigger select: Select one of the MCPASS HW or FW triggers (PULSE mode) */
    cy_en_hppass_dac_buf_trigger_sel_t updateTriggerSelect;  /**< DAC update trigger select: Select one of the triggers or internal events (max freq <= CSG_CLOCK/2) */
    cy_en_hppass_dac_buf_mode_sel_t mode;                    /**< DAC Buffer mode */
    bool continuousMode;                                     /**< DAC Continuous Mode (Only valid for Slope and LUT modes): 0=One-Shot (last output value held), 1=Continuous (operation restarted when end value reached) */
    bool skipTriggerEnable;                                  /**< Skip the first DAC hardware update trigger after mode is enabled. Allows minimum of full trigger period before first HW update. Should be set before and during operation. 0=First trigger updates DAC, 1=First trigger skipped */
    bool paramSyncEnable;                                /**< Parameter sync enable */
    uint8_t stepSize;                                    /**< Step size */

    /* DAC_BUFFER_FIFO_CTRL */
    uint8_t fifoAccessMode;                              /**< FIFO access mode: 0=Single LSB, 1=Single MSB, 2=Double LSB, 3=Double MSB */

    /* DAC_BUFFER_PARAM_SYNC */
    bool paramSyncReady;                                 /**< Parameter sync ready flag */

    /* DAC_BUFFER_VAL_A and DAC_BUFFER_VAL_B */
    uint16_t valueA;                                     /**< DAC Value A register */
    uint16_t valueB;                                     /**< DAC Value B register */

    /* DAC_BUFFER_PERIOD */
    uint8_t updatePeriodInteger;                         /**< Update period integer part */
    uint8_t updatePeriodFractional;                      /**< Update period fractional part */

    /* DAC_BUFFER_ANA_CTRL_1 */
    bool powerEnable;                                    /**< DAC power enable */
    bool comparatorEnable;                               /**< Comparator enable */
    cy_en_hppass_dac_buf_comp_direction_t compDirection; /**< Comparator hysteresis direction */
    bool comparatorHysteresisEnable;                     /**< Comparator hysteresis enable */
    bool enableGainBoost;                                /**< Buffer gain boost enable */

    /* DAC_BUFFER_ANA_CTRL_2 */
    bool referenceSelect;                                /**< Reference select: must be 0 (VDDA). External VREF (1) is not supported. */
    bool bufferOutputSelect;                             /**< Buffer output select */
    uint8_t powerMode;                                   /**< Buffer drive strength: 0=Low, 1=Medium, 2=High, 3=Ultra */

    /* DAC_BUFFER_ANA_MITIGATION_CTRL */
    bool chargePumpEnable;                               /**< Charge pump enable (DAC_RMP_PMP bit).
                                                         *   Enables the opamp charge pump for rail-to-rail output.
                                                         *   Should be enabled when output needs to swing close to supply rails.
                                                         */

    /* ADC_LOOPBACK_CTRL (SAR_CFG) */
    uint8_t adcLoopbackChannel;                          /**< ADC channel for loopback mode.
                                                         *   Selects which SAR ADC channel result feeds
                                                         *   the DAC in \ref CY_HPPASS_DAC_BUF_MODE_ADC_LOOPBACK mode.
                                                         *   Valid range: 0..(CY_HPPASS_SAR_CHAN_NUM - 1).
                                                         */
} cy_stc_hppass_dac_buf_config_t;

/** \} group_hppass_dac_data_structures */


/**
* \addtogroup group_hppass_dac_functions
* \{
*/

/*******************************************************************************
* Function Name: Cy_HPPASS_DAC_Enable
****************************************************************************//**
*
* Enables DAC BUFFER and charge pump.
*
* \param dacIdx
* DAC instance number (0-1)
*
*******************************************************************************/
__STATIC_INLINE void Cy_HPPASS_DAC_Enable(uint8_t dacIdx)
{

    CY_ASSERT_L1(CY_HPPASS_DAC_INDEX_VALID(dacIdx));
    HPPASS_DAC_CFG(HPPASS_BASE, dacIdx) |= HPPASS_DAC_BUFFER_DAC_BUFFER_DAC_BUFFER_CFG_ENABLE_Msk;
}

/*******************************************************************************
* Function Name: Cy_HPPASS_DAC_Disable
****************************************************************************//**
*
* Disables DAC BUFFER and charge pump.
*
* \param dacIdx
* DAC instance number (0-1)
*
* \note The DAC_BUFFER_ANA_CTRL_1 register is non-retention and its contents
* are lost when the DAC is disabled. After re-enabling the DAC, ANA_CTRL_1
* must be reconfigured (e.g. by calling Cy_HPPASS_DAC_Init()).
*
*******************************************************************************/
__STATIC_INLINE void Cy_HPPASS_DAC_Disable(uint8_t dacIdx)
{

    CY_ASSERT_L1(CY_HPPASS_DAC_INDEX_VALID(dacIdx));
    HPPASS_DAC_CFG(HPPASS_BASE, dacIdx) &= ~HPPASS_DAC_BUFFER_DAC_BUFFER_DAC_BUFFER_CFG_ENABLE_Msk;
}

/*******************************************************************************
* Function Name: Cy_HPPASS_DAC_WriteParamSync
****************************************************************************//**
*
* Set parameter sync ready flag to synchronize the update of multiple DAC parameters.
*
* \param dacIdx
* DAC buffer index (0 or 1).
*
* \param enable
* true - set sync ready, false - clear sync ready.
*
* \note If DAC_PARAM_SYNC_EN bit is '1', then set this bit after writes to all
* parameter registers (VAL_A, VAL_B, DAC_PERIOD, DAC_STEP) are complete to
* synchronize parameter update on a subsequent DAC trigger. This allows for
* writes to multiple registers to be written before new parameters are updated
* to avoid partial updates.
*
* \note This bit is cleared by HW on the parameter update event. If DAC_PARAM_SYNC_EN
* is '0', this bit is ignored and parameters are updated on the following UPDATE trigger.
*
* \note This bit can be used in conjunction with DAC_CASCADE_EN to synchronize the
* parameter update of multiple CSG slices.
*
*******************************************************************************/
__STATIC_INLINE void Cy_HPPASS_DAC_WriteParamSync(uint8_t dacIdx, bool enable)
{

    CY_ASSERT_L1(CY_HPPASS_DAC_INDEX_VALID(dacIdx));
    if (enable)
    {
        HPPASS_DAC_PARAM_SYNC(HPPASS_BASE, dacIdx) |= HPPASS_DAC_BUFFER_DAC_BUFFER_DAC_BUFFER_PARAM_SYNC_READY_Msk;
    }
    else
    {
        HPPASS_DAC_PARAM_SYNC(HPPASS_BASE, dacIdx) &= ~HPPASS_DAC_BUFFER_DAC_BUFFER_DAC_BUFFER_PARAM_SYNC_READY_Msk;
    }
}

/*******************************************************************************
* Function Name: Cy_HPPASS_DAC_WriteValueA
****************************************************************************//**
*
* Write DAC Buffer value A.
*
* \param dacIdx
* DAC instance number (0-1)
*
* \param data
* 16-bit DAC value A.
*
*******************************************************************************/
__STATIC_INLINE void Cy_HPPASS_DAC_WriteValueA(uint8_t dacIdx, uint16_t data)
{

    CY_ASSERT_L1(CY_HPPASS_DAC_INDEX_VALID(dacIdx));
    CY_REG32_CLR_SET(HPPASS_DAC_VAL_A(HPPASS_BASE, dacIdx), HPPASS_DAC_BUFFER_DAC_BUFFER_DAC_BUFFER_VAL_A_VALUE, data);
}

/*******************************************************************************
* Function Name: Cy_HPPASS_DAC_WriteValueB
****************************************************************************//**
*
* Write DAC Buffer value B.
*
* \param dacIdx
* DAC instance number (0-1)
*
* \param data
* 16-bit DAC value B.
*
*******************************************************************************/
__STATIC_INLINE void Cy_HPPASS_DAC_WriteValueB(uint8_t dacIdx, uint16_t data)
{

    CY_ASSERT_L1(CY_HPPASS_DAC_INDEX_VALID(dacIdx));
    CY_REG32_CLR_SET(HPPASS_DAC_VAL_B(HPPASS_BASE, dacIdx), HPPASS_DAC_BUFFER_DAC_BUFFER_DAC_BUFFER_VAL_B_VALUE, data);
}

/*******************************************************************************
* Function Name: Cy_HPPASS_DAC_WriteUpdatePeriod
****************************************************************************//**
*
* Set DAC update period.
*
* \param dacIdx
* DAC buffer index (0 or 1).
*
* \param integer
* Integer Divide Value (12-bit).
* only the lower 12 bits are used. Integer count by (1+PERIOD_INT).
* Allows for integer counts in the range [1, 4096].
*
* \param fractional
* 5-bit Fractional Divide Value. Allows for fractional count in
* the range [0, 31/32].
*
*******************************************************************************/
__STATIC_INLINE void Cy_HPPASS_DAC_WriteUpdatePeriod(uint8_t dacIdx, uint16_t integer, uint8_t fractional)
{

    CY_ASSERT_L1(CY_HPPASS_DAC_INDEX_VALID(dacIdx));
    uint32_t temp = HPPASS_DAC_PERIOD(HPPASS_BASE, dacIdx);
    temp &= ~(HPPASS_DAC_BUFFER_DAC_BUFFER_DAC_BUFFER_PERIOD_PERIOD_INT_Msk | HPPASS_DAC_BUFFER_DAC_BUFFER_DAC_BUFFER_PERIOD_PERIOD_FRAC_Msk);
    temp |= _VAL2FLD(HPPASS_DAC_BUFFER_DAC_BUFFER_DAC_BUFFER_PERIOD_PERIOD_INT, integer);
    temp |= _VAL2FLD(HPPASS_DAC_BUFFER_DAC_BUFFER_DAC_BUFFER_PERIOD_PERIOD_FRAC, fractional);
    HPPASS_DAC_PERIOD(HPPASS_BASE, dacIdx) = temp;
}

/*******************************************************************************
* Function Name: Cy_HPPASS_DAC_Init
****************************************************************************//**
*
* Initializes the DAC with provided configuration parameters.
*
* \param dacIdx
* DAC instance number (0-1)
*
* \param config
* Pointer to the DAC BUFFER configuration structure.
*
* \note The DAC_BUFFER_ANA_CTRL_1 register is non-retention: its contents are
* lost when the DAC is disabled. This function enables the DAC before writing
* ANA_CTRL_1 to ensure the configuration is retained.
*
* \return
* \ref CY_HPPASS_DAC_SUCCESS - initialization was successful.
* \ref CY_HPPASS_DAC_BAD_PARAM - input parameter is invalid.
*
*******************************************************************************/
__STATIC_INLINE cy_en_hppass_dac_status_t Cy_HPPASS_DAC_Init(uint8_t dacIdx, const cy_stc_hppass_dac_buf_config_t *config)
{

    CY_ASSERT_L1(CY_HPPASS_DAC_INDEX_VALID(dacIdx));
    CY_ASSERT_L1(NULL != config);
    if ((NULL == config) || (!CY_HPPASS_DAC_INDEX_VALID(dacIdx)))
    {
        return CY_HPPASS_DAC_BAD_PARAM;
    }
    else
    {
        uint32_t cfgReg = 0UL;
        uint32_t anaCtrl1 = 0UL;
        uint32_t anaCtrl2 = 0UL;

        /* Enable DAC first — ANA_CTRL_1 is a non-retention register and
         * loses its contents when the DAC is not enabled. */
        HPPASS_DAC_CFG(HPPASS_BASE, dacIdx) |= HPPASS_DAC_BUFFER_DAC_BUFFER_DAC_BUFFER_CFG_ENABLE_Msk;

        /* Build DAC_BUFFER_CFG register — preserve ENABLE bit so that
         * ANA_CTRL_1 (non-retention) keeps its contents. */
        cfgReg = HPPASS_DAC_BUFFER_DAC_BUFFER_DAC_BUFFER_CFG_ENABLE_Msk |
                 _VAL2FLD(HPPASS_DAC_BUFFER_DAC_BUFFER_DAC_BUFFER_CFG_DAC_TR_START_SEL, config->startTriggerSelect) |
                 _VAL2FLD(HPPASS_DAC_BUFFER_DAC_BUFFER_DAC_BUFFER_CFG_DAC_TR_UPDATE_SEL, config->updateTriggerSelect) |
                 _VAL2FLD(HPPASS_DAC_BUFFER_DAC_BUFFER_DAC_BUFFER_CFG_DAC_MODE, config->mode) |
                 _VAL2FLD(HPPASS_DAC_BUFFER_DAC_BUFFER_DAC_BUFFER_CFG_DAC_CONT, config->continuousMode) |
                 _VAL2FLD(HPPASS_DAC_BUFFER_DAC_BUFFER_DAC_BUFFER_CFG_DAC_SKIP_TR_EN, config->skipTriggerEnable) |
                 _VAL2FLD(HPPASS_DAC_BUFFER_DAC_BUFFER_DAC_BUFFER_CFG_DAC_PARAM_SYNC_EN, config->paramSyncEnable) |
                 _VAL2FLD(HPPASS_DAC_BUFFER_DAC_BUFFER_DAC_BUFFER_CFG_DAC_STEP, config->stepSize);
        HPPASS_DAC_CFG(HPPASS_BASE, dacIdx) = cfgReg;

        /* Set FIFO access mode */
        CY_REG32_CLR_SET(HPPASS_DAC_FIFO_CTRL(HPPASS_BASE, dacIdx), HPPASS_DAC_BUFFER_DAC_BUFFER_DAC_BUFFER_FIFO_CTRL_ACCESS_MODE, config->fifoAccessMode);

        /* Set parameter sync ready */
        Cy_HPPASS_DAC_WriteParamSync(dacIdx, config->paramSyncReady);

        /* Set value A and B */
        Cy_HPPASS_DAC_WriteValueA(dacIdx, config->valueA);
        Cy_HPPASS_DAC_WriteValueB(dacIdx, config->valueB);

        /* Set update period */
        Cy_HPPASS_DAC_WriteUpdatePeriod(dacIdx, config->updatePeriodInteger, config->updatePeriodFractional);

        /* Build DAC_BUFFER_ANA_CTRL_1 register */
        anaCtrl1 = _VAL2FLD(HPPASS_DAC_BUFFER_DAC_BUFFER_DAC_BUFFER_ANA_CTRL_1_DAC_CTRL_PWR_EN, config->powerEnable) |
                   _VAL2FLD(HPPASS_DAC_BUFFER_DAC_BUFFER_DAC_BUFFER_ANA_CTRL_1_DAC_COMP_EN, config->comparatorEnable) |
                   _VAL2FLD(HPPASS_DAC_BUFFER_DAC_BUFFER_DAC_BUFFER_ANA_CTRL_1_DAC_COMP_HYST_DIR, config->compDirection) |
                   _VAL2FLD(HPPASS_DAC_BUFFER_DAC_BUFFER_DAC_BUFFER_ANA_CTRL_1_DAC_COMP_HYST_EN, config->comparatorHysteresisEnable) |
                   _VAL2FLD(HPPASS_DAC_BUFFER_DAC_BUFFER_DAC_BUFFER_ANA_CTRL_1_DAC_ENABLE_GB, config->enableGainBoost);
        HPPASS_DAC_ANA_CTRL_1(HPPASS_BASE, dacIdx) = anaCtrl1;

        /* Build DAC_BUFFER_ANA_CTRL_2 register - use SFLASH trim values.
         * Force REF_SEL to 0 (VDDA) — external VREF is not supported for DAC. */
        {
            uint32_t sflashTrim = SFLASH_DAC_BUFFER_TRIM(dacIdx);
            anaCtrl2 = _VAL2FLD(HPPASS_DAC_BUFFER_DAC_BUFFER_DAC_BUFFER_ANA_CTRL_2_DAC_CTRL_REF_SEL, 0UL) |
                       _VAL2FLD(HPPASS_DAC_BUFFER_DAC_BUFFER_DAC_BUFFER_ANA_CTRL_2_DAC_CTRL_BUF_OUT_SEL, config->bufferOutputSelect) |
                       _VAL2FLD(HPPASS_DAC_BUFFER_DAC_BUFFER_DAC_BUFFER_ANA_CTRL_2_DAC_CTRL_PWR_MODE, config->powerMode) |
                       (sflashTrim & (HPPASS_DAC_BUFFER_DAC_BUFFER_DAC_BUFFER_ANA_CTRL_2_DAC_TRIM_OFFSET_Msk |
                                      HPPASS_DAC_BUFFER_DAC_BUFFER_DAC_BUFFER_ANA_CTRL_2_DAC_COMPENSATION_TRIM_Msk |
                                      HPPASS_DAC_BUFFER_DAC_BUFFER_DAC_BUFFER_ANA_CTRL_2_DAC_SLOPE_TRIM_OFFSET_Msk));
        }
        HPPASS_DAC_ANA_CTRL_2(HPPASS_BASE, dacIdx) = anaCtrl2;

        /* Set DAC_BUFFER_ANA_MITIGATION_CTRL - charge pump */
        CY_REG32_CLR_SET(HPPASS_DAC_ANA_MITIGATION_CTRL(HPPASS_BASE, dacIdx),
                         HPPASS_DAC_BUFFER_DAC_BUFFER_DAC_BUFFER_ANA_MITIGATION_CTRL_DAC_RMP_PMP,
                         config->chargePumpEnable);

        /* Set ADC loopback channel selection */
        if (0U == dacIdx)
        {
            CY_REG32_CLR_SET(HPPASS_SAR_ADC_LOOPBACK_CTRL(HPPASS_BASE),
                             HPPASS_SAR_CFG_ADC_LOOPBACK_CTRL_ADC_CHANNEL_SEL_0,
                             config->adcLoopbackChannel);
        }
        else
        {
            CY_REG32_CLR_SET(HPPASS_SAR_ADC_LOOPBACK_CTRL(HPPASS_BASE),
                             HPPASS_SAR_CFG_ADC_LOOPBACK_CTRL_ADC_CHANNEL_SEL_1,
                             config->adcLoopbackChannel);
        }

        return CY_HPPASS_DAC_SUCCESS;
    }
}

/*******************************************************************************
* Function Name: Cy_HPPASS_DAC_UpdateTriggerSet
****************************************************************************//**
*
* Update DAC Buffer update trigger source.
*
* \param dacIdx
* DAC instance number (0-1)
*
* \param src_sel
* Update trigger source selection.
*
*******************************************************************************/
__STATIC_INLINE void Cy_HPPASS_DAC_UpdateTriggerSet(uint8_t dacIdx, cy_en_hppass_dac_buf_trigger_sel_t src_sel)
{

    CY_ASSERT_L1(CY_HPPASS_DAC_INDEX_VALID(dacIdx));
    CY_REG32_CLR_SET(HPPASS_DAC_CFG(HPPASS_BASE, dacIdx), HPPASS_DAC_BUFFER_DAC_BUFFER_DAC_BUFFER_CFG_DAC_TR_UPDATE_SEL, src_sel);
}

/*******************************************************************************
* Function Name: Cy_HPPASS_DAC_ModeSet
****************************************************************************//**
*
* Update DAC Buffer mode.
*
* \param dacIdx
* DAC buffer index (0 or 1).
*
* \param mode_sel
* DAC Buffer mode selection:
* - CY_HPPASS_DAC_BUF_MODE_BUFFERED: Single Value Buffered Mode
* - CY_HPPASS_DAC_BUF_MODE_HYSTERETIC: Two Value Hysteretic Buffered Mode
* - CY_HPPASS_DAC_BUF_MODE_SLOPE_RISING: Rising Slope Mode
* - CY_HPPASS_DAC_BUF_MODE_SLOPE_FALLING: Falling Slope Mode
* - CY_HPPASS_DAC_BUF_MODE_SLOPE_TRIANGULAR: Triangular Slope Mode
* - CY_HPPASS_DAC_BUF_MODE_LUT_FORWARD: LUT Forward Mode
* - CY_HPPASS_DAC_BUF_MODE_LUT_REVERSE: LUT Reverse Mode
* - CY_HPPASS_DAC_BUF_MODE_LUT_FWD_REV: LUT Forward Reverse Mode
* - CY_HPPASS_DAC_BUF_MODE_FIFO: FIFO Mode
* - CY_HPPASS_DAC_BUF_MODE_ADC_LOOPBACK: ADC Loopback Mode
*
* \note When DAC_MODE is enabled and Cy_HPPASS_DAC_WriteValue is called,
* it will STOP the current DAC_MODE operation and subsequent DAC triggers are ignored.
*
*******************************************************************************/
__STATIC_INLINE void Cy_HPPASS_DAC_ModeSet(uint8_t dacIdx, cy_en_hppass_dac_buf_mode_sel_t mode_sel)
{

    CY_ASSERT_L1(CY_HPPASS_DAC_INDEX_VALID(dacIdx));
    CY_REG32_CLR_SET(HPPASS_DAC_CFG(HPPASS_BASE, dacIdx), HPPASS_DAC_BUFFER_DAC_BUFFER_DAC_BUFFER_CFG_DAC_MODE, mode_sel);
}

/*******************************************************************************
* Function Name: Cy_HPPASS_DAC_ContinuousModeSet
****************************************************************************//**
*
* Enable / Disable DAC Buffer continuous mode.
*
* \param dacIdx
* DAC instance number (0-1)
*
* \param enable
* true - enable continuous mode, false - disable continuous mode.
*
*******************************************************************************/
__STATIC_INLINE void Cy_HPPASS_DAC_ContinuousModeSet(uint8_t dacIdx, bool enable)
{

    CY_ASSERT_L1(CY_HPPASS_DAC_INDEX_VALID(dacIdx));
    if (enable)
    {
        HPPASS_DAC_CFG(HPPASS_BASE, dacIdx) |= HPPASS_DAC_BUFFER_DAC_BUFFER_DAC_BUFFER_CFG_DAC_CONT_Msk;
    }
    else
    {
        HPPASS_DAC_CFG(HPPASS_BASE, dacIdx) &= ~HPPASS_DAC_BUFFER_DAC_BUFFER_DAC_BUFFER_CFG_DAC_CONT_Msk;
    }
}

/*******************************************************************************
* Function Name: Cy_HPPASS_DAC_WriteStepSize
****************************************************************************//**
*
* Sets the 6 bit DAC Step size.
*
* \param dacIdx
* DAC instance number (0-1)
*
* \param step_size
* 6-bit step size value. The 2 MSB bits are ignored, only bits [5:0] are used.
*
*******************************************************************************/
__STATIC_INLINE void Cy_HPPASS_DAC_WriteStepSize(uint8_t dacIdx, uint8_t step_size)
{

    CY_ASSERT_L1(CY_HPPASS_DAC_INDEX_VALID(dacIdx));
    CY_REG32_CLR_SET(HPPASS_DAC_CFG(HPPASS_BASE, dacIdx), HPPASS_DAC_BUFFER_DAC_BUFFER_DAC_BUFFER_CFG_DAC_STEP, step_size);
}

/*******************************************************************************
* Function Name: Cy_HPPASS_DAC_Buf_IsBusy
****************************************************************************//**
*
* To read DAC Mode Busy status.
*
* \param dacIdx
* DAC instance number (0-1)
*
* \return
* true - DAC is busy, false - DAC is not busy.
*
*******************************************************************************/
__STATIC_INLINE bool Cy_HPPASS_DAC_Buf_IsBusy(uint8_t dacIdx)
{

    CY_ASSERT_L1(CY_HPPASS_DAC_INDEX_VALID(dacIdx));
    return (_FLD2BOOL(HPPASS_DAC_BUFFER_DAC_BUFFER_DAC_BUFFER_MODE_START_BUSY, HPPASS_DAC_MODE_START(HPPASS_BASE, dacIdx)));
}

/*******************************************************************************
* Function Name: Cy_HPPASS_DAC_WriteValue
****************************************************************************//**
*
* Write DAC Buffer data directly to the DAC Hard IP for output.
*
* \param dacIdx
* DAC buffer index (0 or 1).
*
* \param data
* 32-bit DAC value. Data Access Mode of Operation:
* - Single Word LSB Alignment: Data[11:0]
* - Single Word MSB Alignment: Data[31:20]
* - Double Word Access LSB Alignment: Word 0: Data[11:0], Word 1[27:16]
* - Double Word Access MSB Alignment: Word 0: Data[15:4], Word 1[31:20]
*
* \note When DAC_MODE is '0', the value in this register is output directly to DAC.
* A write to this register also STOPs the current DAC_MODE operation, and
* subsequent DAC triggers are ignored. Bits outside of these configurations
* shall return 0x0.
*
*******************************************************************************/
__STATIC_INLINE void Cy_HPPASS_DAC_WriteValue(uint8_t dacIdx, uint32_t data)
{

    CY_ASSERT_L1(CY_HPPASS_DAC_INDEX_VALID(dacIdx));
    HPPASS_DAC_VAL(HPPASS_BASE, dacIdx) = data;
}

/*******************************************************************************
* Function Name: Cy_HPPASS_DAC_ReadValue
****************************************************************************//**
*
* Read current DAC value.
*
* \param dacIdx
* DAC instance number (0-1)
*
* \return
* Current DAC value.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_HPPASS_DAC_ReadValue(uint8_t dacIdx)
{

    CY_ASSERT_L1(CY_HPPASS_DAC_INDEX_VALID(dacIdx));
    return (_FLD2VAL(HPPASS_DAC_BUFFER_DAC_BUFFER_DAC_BUFFER_STATUS_DAC_VAL, HPPASS_DAC_STATUS(HPPASS_BASE, dacIdx)));
}

/*******************************************************************************
* Function Name: Cy_HPPASS_DAC_ComparatorEnable
****************************************************************************//**
*
* Enable / Disable DAC Comparator.
*
* \param dacIdx
* DAC instance number (0-1)
*
* \param enable
* true - enable comparator, false - disable comparator.
*
*******************************************************************************/
__STATIC_INLINE void Cy_HPPASS_DAC_ComparatorEnable(uint8_t dacIdx, bool enable)
{

    CY_ASSERT_L1(CY_HPPASS_DAC_INDEX_VALID(dacIdx));
    if (enable)
    {
        HPPASS_DAC_ANA_CTRL_1(HPPASS_BASE, dacIdx) |= HPPASS_DAC_BUFFER_DAC_BUFFER_DAC_BUFFER_ANA_CTRL_1_DAC_COMP_EN_Msk;
    }
    else
    {
        HPPASS_DAC_ANA_CTRL_1(HPPASS_BASE, dacIdx) &= ~HPPASS_DAC_BUFFER_DAC_BUFFER_DAC_BUFFER_ANA_CTRL_1_DAC_COMP_EN_Msk;
    }
}

/*******************************************************************************
* Function Name: Cy_HPPASS_DAC_ComparatorDirectionSet
****************************************************************************//**
*
* Set DAC Buffer comparator direction.
*
* \param dacIdx
* DAC instance number (0-1)
*
* \param direction
* Comparator direction (rising or falling).
*
*******************************************************************************/
__STATIC_INLINE void Cy_HPPASS_DAC_ComparatorDirectionSet(uint8_t dacIdx, cy_en_hppass_dac_buf_comp_direction_t direction)
{

    CY_ASSERT_L1(CY_HPPASS_DAC_INDEX_VALID(dacIdx));
    CY_REG32_CLR_SET(HPPASS_DAC_ANA_CTRL_1(HPPASS_BASE, dacIdx), HPPASS_DAC_BUFFER_DAC_BUFFER_DAC_BUFFER_ANA_CTRL_1_DAC_COMP_HYST_DIR, direction);
}

/*******************************************************************************
* Function Name: Cy_HPPASS_DAC_ComparatorHystEnable
****************************************************************************//**
*
* Enable / Disable Comparator hysteresis.
*
* \param dacIdx
* DAC instance number (0-1)
*
* \param enable
* true - enable hysteresis, false - disable hysteresis.
*
*******************************************************************************/
__STATIC_INLINE void Cy_HPPASS_DAC_ComparatorHystEnable(uint8_t dacIdx, bool enable)
{

    CY_ASSERT_L1(CY_HPPASS_DAC_INDEX_VALID(dacIdx));
    if (enable)
    {
        HPPASS_DAC_ANA_CTRL_1(HPPASS_BASE, dacIdx) |= HPPASS_DAC_BUFFER_DAC_BUFFER_DAC_BUFFER_ANA_CTRL_1_DAC_COMP_HYST_EN_Msk;
    }
    else
    {
        HPPASS_DAC_ANA_CTRL_1(HPPASS_BASE, dacIdx) &= ~HPPASS_DAC_BUFFER_DAC_BUFFER_DAC_BUFFER_ANA_CTRL_1_DAC_COMP_HYST_EN_Msk;
    }
}

/*******************************************************************************
* Function Name: Cy_HPPASS_DAC_ChargePumpEnable
****************************************************************************//**
*
* Enable / Disable the DAC opamp charge pump for rail-to-rail output.
*
* \param dacIdx
* DAC instance number (0-1)
*
* \param enable
* true - enable charge pump, false - disable charge pump.
*
*******************************************************************************/
__STATIC_INLINE void Cy_HPPASS_DAC_ChargePumpEnable(uint8_t dacIdx, bool enable)
{

    CY_ASSERT_L1(CY_HPPASS_DAC_INDEX_VALID(dacIdx));
    if (enable)
    {
        HPPASS_DAC_ANA_MITIGATION_CTRL(HPPASS_BASE, dacIdx) |= HPPASS_DAC_BUFFER_DAC_BUFFER_DAC_BUFFER_ANA_MITIGATION_CTRL_DAC_RMP_PMP_Msk;
    }
    else
    {
        HPPASS_DAC_ANA_MITIGATION_CTRL(HPPASS_BASE, dacIdx) &= ~HPPASS_DAC_BUFFER_DAC_BUFFER_DAC_BUFFER_ANA_MITIGATION_CTRL_DAC_RMP_PMP_Msk;
    }
}

/*******************************************************************************
* Function Name: Cy_HPPASS_DAC_IsChargePumpEnabled
****************************************************************************//**
*
* Returns the current state of the DAC opamp charge pump.
*
* \param dacIdx
* DAC instance number (0-1)
*
* \return
* true - charge pump is enabled, false - charge pump is disabled.
*
*******************************************************************************/
__STATIC_INLINE bool Cy_HPPASS_DAC_IsChargePumpEnabled(uint8_t dacIdx)
{

    CY_ASSERT_L1(CY_HPPASS_DAC_INDEX_VALID(dacIdx));
    return (_FLD2BOOL(HPPASS_DAC_BUFFER_DAC_BUFFER_DAC_BUFFER_ANA_MITIGATION_CTRL_DAC_RMP_PMP, HPPASS_DAC_ANA_MITIGATION_CTRL(HPPASS_BASE, dacIdx)));
}

/*******************************************************************************
* Function Name: Cy_HPPASS_DAC_Is_Ready
****************************************************************************//**
*
* Returns ready status of the comparator.
*
* \param dacIdx
* DAC instance number (0-1)
*
* \return
* true - DAC is ready, false - DAC is not ready.
*
*******************************************************************************/
__STATIC_INLINE bool Cy_HPPASS_DAC_Is_Ready(uint8_t dacIdx)
{

    CY_ASSERT_L1(CY_HPPASS_DAC_INDEX_VALID(dacIdx));
    return (_FLD2BOOL(HPPASS_DAC_BUFFER_DAC_BUFFER_DAC_BUFFER_ANA_CTRL_1_DAC_READY, HPPASS_DAC_ANA_CTRL_1(HPPASS_BASE, dacIdx)));
}

/*******************************************************************************
* Function Name: Cy_HPPASS_DAC_FIFO_Clear
****************************************************************************//**
*
* Clears DAC BUFFER FIFO.
*
* \param dacIdx
* DAC instance number (0-1)
*
*******************************************************************************/
__STATIC_INLINE void Cy_HPPASS_DAC_FIFO_Clear(uint8_t dacIdx)
{

    CY_ASSERT_L1(CY_HPPASS_DAC_INDEX_VALID(dacIdx));
    HPPASS_DAC_FIFO_CTRL(HPPASS_BASE, dacIdx) |= HPPASS_DAC_BUFFER_DAC_BUFFER_DAC_BUFFER_FIFO_CTRL_CLEAR_FIFO_Msk;
}

/*******************************************************************************
* Function Name: Cy_HPPASS_DAC_FIFO_DataIn
****************************************************************************//**
*
* Writes a 32 bit data to the FIFO.
*
* \param dacIdx
* DAC instance number (0-1)
*
* \param data
* 32-bit data to write to FIFO.
*
*******************************************************************************/
__STATIC_INLINE void Cy_HPPASS_DAC_FIFO_DataIn(uint8_t dacIdx, uint32_t data)
{

    CY_ASSERT_L1(CY_HPPASS_DAC_INDEX_VALID(dacIdx));
    HPPASS_DAC_FIFO_DATA_IN(HPPASS_BASE, dacIdx) = data;
}

/*******************************************************************************
* Function Name: Cy_HPPASS_DAC_FIFOAvailable_Read
****************************************************************************//**
*
* To read the amount FIFO available.
*
* \param dacIdx
* DAC instance number (0-1)
*
* \return
* Number of FIFO elements available.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_HPPASS_DAC_FIFOAvailable_Read(uint8_t dacIdx)
{

    CY_ASSERT_L1(CY_HPPASS_DAC_INDEX_VALID(dacIdx));
    return (_FLD2VAL(HPPASS_DAC_BUFFER_DAC_BUFFER_DAC_BUFFER_FIFO_CTRL_FIFO_AVAILABLE, HPPASS_DAC_FIFO_CTRL(HPPASS_BASE, dacIdx)));
}

/*******************************************************************************
* Function Name: Cy_HPPASS_DAC_FIFO_DataFill
****************************************************************************//**
*
* Writes data to multiple FIFO elements.
*
* \param dacIdx
* DAC instance number (0-1)
*
* \param buffer
* Pointer to the data buffer.
*
* \param size
* Pointer to the size variable (number of elements to write).
* On return, contains the actual number of elements written.
*
*******************************************************************************/
__STATIC_INLINE void Cy_HPPASS_DAC_FIFO_DataFill(uint8_t dacIdx, uint32_t* buffer, uint32_t* size)
{

    CY_ASSERT_L1(CY_HPPASS_DAC_INDEX_VALID(dacIdx));
    CY_ASSERT_L1(NULL != buffer);
    CY_ASSERT_L1(NULL != size);
    uint32_t count = 0;
    uint32_t available = Cy_HPPASS_DAC_FIFOAvailable_Read(dacIdx);
    uint32_t toWrite = (*size < available) ? *size : available;

    for (count = 0; count < toWrite; count++)
    {
        Cy_HPPASS_DAC_FIFO_DataIn(dacIdx, buffer[count]);
    }

    *size = count;
}

/*******************************************************************************
* Function Name: Cy_HPPASS_DAC_FIFOUsed_Read
****************************************************************************//**
*
* To read the amount FIFO in use.
*
* \param dacIdx
* DAC instance number (0-1)
*
* \return
* Number of FIFO elements in use.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_HPPASS_DAC_FIFOUsed_Read(uint8_t dacIdx)
{

    CY_ASSERT_L1(CY_HPPASS_DAC_INDEX_VALID(dacIdx));
    return (_FLD2VAL(HPPASS_DAC_BUFFER_DAC_BUFFER_DAC_BUFFER_FIFO_CTRL_FIFO_USED, HPPASS_DAC_FIFO_CTRL(HPPASS_BASE, dacIdx)));
}

/*******************************************************************************
* Function Name: Cy_HPPASS_DAC_FIFO_IsEmpty
****************************************************************************//**
*
* Returns whether the FIFO is empty or not.
*
* \param dacIdx
* DAC instance number (0-1)
*
* \return
* true - FIFO is empty, false - FIFO is not empty.
*
*******************************************************************************/
__STATIC_INLINE bool Cy_HPPASS_DAC_FIFO_IsEmpty(uint8_t dacIdx)
{

    CY_ASSERT_L1(CY_HPPASS_DAC_INDEX_VALID(dacIdx));
    return (_FLD2BOOL(HPPASS_DAC_BUFFER_DAC_BUFFER_DAC_BUFFER_FIFO_CTRL_EMPTY_FLAG, HPPASS_DAC_FIFO_CTRL(HPPASS_BASE, dacIdx)));
}

/*******************************************************************************
* Function Name: Cy_HPPASS_DAC_FIFO_IsFull
****************************************************************************//**
*
* Returns whether the FIFO is full or not.
*
* \param dacIdx
* DAC instance number (0-1)
*
* \return
* true - FIFO is full, false - FIFO is not full.
*
*******************************************************************************/
__STATIC_INLINE bool Cy_HPPASS_DAC_FIFO_IsFull(uint8_t dacIdx)
{

    CY_ASSERT_L1(CY_HPPASS_DAC_INDEX_VALID(dacIdx));
    return (_FLD2BOOL(HPPASS_DAC_BUFFER_DAC_BUFFER_DAC_BUFFER_FIFO_CTRL_FULL_FLAG, HPPASS_DAC_FIFO_CTRL(HPPASS_BASE, dacIdx)));
}

/*******************************************************************************
* Function Name: Cy_HPPASS_DAC_LutWrite
****************************************************************************//**
*
* Writes a 12-bit value to a specific LUT entry.
*
* \param dacIdx
* DAC instance number (0-1)
*
* \param lutIdx
* LUT entry index (0-127)
*
* \param data
* 12-bit DAC value (0-4095)
*
*******************************************************************************/
__STATIC_INLINE void Cy_HPPASS_DAC_LutWrite(uint8_t dacIdx, uint8_t lutIdx, uint16_t data)
{
    CY_ASSERT_L1(CY_HPPASS_DAC_INDEX_VALID(dacIdx));
    CY_ASSERT_L1(lutIdx < 128);
    CY_ASSERT_L1(data <= 4095);

    HPPASS_DAC_LUT(HPPASS_BASE, dacIdx, lutIdx) = data;
}

/*******************************************************************************
* Function Name: Cy_HPPASS_DAC_LutRead
****************************************************************************//**
*
* Reads a 12-bit value from a specific LUT entry.
*
* \param dacIdx
* DAC instance number (0-1)
*
* \param lutIdx
* LUT entry index (0-127)
*
* \return
* 12-bit DAC value (0-4095) from the specified LUT entry
*
*******************************************************************************/
__STATIC_INLINE uint16_t Cy_HPPASS_DAC_LutRead(uint8_t dacIdx, uint8_t lutIdx)
{
    CY_ASSERT_L1(CY_HPPASS_DAC_INDEX_VALID(dacIdx));
    CY_ASSERT_L1(lutIdx < 128);

    return (uint16_t)(HPPASS_DAC_LUT(HPPASS_BASE, dacIdx, lutIdx) & 0x0FFFu);
}

/*******************************************************************************
* Function Name: Cy_HPPASS_DAC_LutFill
****************************************************************************//**
*
* Writes multiple 12-bit values to consecutive LUT entries.
*
* \param dacIdx
* DAC instance number (0-1)
*
* \param startIdx
* Starting LUT entry index (0-127)
*
* \param buffer
* Pointer to the 12-bit data buffer (uint16_t array)
*
* \param size
* Number of entries to write (must not exceed 128 - startIdx)
*
*******************************************************************************/
__STATIC_INLINE void Cy_HPPASS_DAC_LutFill(uint8_t dacIdx, uint8_t startIdx, uint16_t* buffer, uint32_t size)
{
    CY_ASSERT_L1(CY_HPPASS_DAC_INDEX_VALID(dacIdx));
    CY_ASSERT_L1(startIdx < 128U);
    CY_ASSERT_L1(size <= (128U - (uint32_t)startIdx));
    CY_ASSERT_L1(NULL != buffer);

    for (uint32_t i = 0; i < size; i++)
    {
        CY_ASSERT_L1(buffer[i] <= 4095);
        HPPASS_DAC_LUT(HPPASS_BASE, dacIdx, startIdx + i) = buffer[i];
    }
}

/*******************************************************************************
* Function Name: Cy_HPPASS_DAC_Buf_GetInterruptStatus
****************************************************************************//**
*
* Get DAC Buffer interrupt status.
*
* \param dacIdx
* DAC instance number (0-1)
*
* \return
* The interrupt status. Bit fields are:
* - CY_HPPASS_DAC_INTR_FIFO_OVERFLOW (Bit 0)
* - CY_HPPASS_DAC_INTR_FIFO_UNDERFLOW (Bit 1)
* - CY_HPPASS_DAC_INTR_FIFO_PAST_UNDERFLOW (Bit 2)
* - CY_HPPASS_DAC_INTR_FIFO_LOW_THRESHOLD (Bit 3)
* - CY_HPPASS_DAC_INTR_HW_START (Bit 4)
* - CY_HPPASS_DAC_INTR_SLOPE_DONE (Bit 5)
* - CY_HPPASS_DAC_INTR_BUF_EMPTY (Bit 6)
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_HPPASS_DAC_Buf_GetInterruptStatus(uint8_t dacIdx)
{

    CY_ASSERT_L1(CY_HPPASS_DAC_INDEX_VALID(dacIdx));
    return (HPPASS_DAC_INTR(HPPASS_BASE, dacIdx));
}

/*******************************************************************************
* Function Name: Cy_HPPASS_DAC_Buf_ClearInterrupt
****************************************************************************//**
*
* Clear DAC Buffer interrupt.
*
* \param dacIdx
* DAC instance number (0-1)
*
* \param source
* Interrupt source mask to clear. See Cy_HPPASS_DAC_Buf_GetInterruptStatus() return
* value for available interrupt bit field definitions.
*
*******************************************************************************/
__STATIC_INLINE void Cy_HPPASS_DAC_Buf_ClearInterrupt(uint8_t dacIdx, uint32_t source)
{

    CY_ASSERT_L1(CY_HPPASS_DAC_INDEX_VALID(dacIdx));
    HPPASS_DAC_INTR(HPPASS_BASE, dacIdx) = source;
    (void)HPPASS_DAC_INTR(HPPASS_BASE, dacIdx);
}

/*******************************************************************************
* Function Name: Cy_HPPASS_DAC_Buf_SetInterrupt
****************************************************************************//**
*
* Set DAC Buffer interrupt for test/debug purposes. This function is used to trigger
* interrupts via software for testing the interrupt handling.
*
* \param dacIdx
* DAC instance number (0-1)
*
* \param source
* Interrupt source mask to set.
*
*******************************************************************************/
__STATIC_INLINE void Cy_HPPASS_DAC_Buf_SetInterrupt(uint8_t dacIdx, uint32_t source)
{

    CY_ASSERT_L1(CY_HPPASS_DAC_INDEX_VALID(dacIdx));
    HPPASS_DAC_INTR_SET(HPPASS_BASE, dacIdx) = source;
}

/*******************************************************************************
* Function Name: Cy_HPPASS_DAC_Buf_SetInterruptMask
****************************************************************************//**
*
* Set DAC Buffer interrupt mask.
*
* \param dacIdx
* DAC instance number (0-1)
*
* \param mask
* Interrupt mask value. Bit fields are:
* - CY_HPPASS_DAC_INTR_FIFO_OVERFLOW (Bit 0)
* - CY_HPPASS_DAC_INTR_FIFO_UNDERFLOW (Bit 1)
* - CY_HPPASS_DAC_INTR_FIFO_PAST_UNDERFLOW (Bit 2)
* - CY_HPPASS_DAC_INTR_FIFO_LOW_THRESHOLD (Bit 3)
* - CY_HPPASS_DAC_INTR_HW_START (Bit 4)
* - CY_HPPASS_DAC_INTR_SLOPE_DONE (Bit 5)
* - CY_HPPASS_DAC_INTR_BUF_EMPTY (Bit 6)
*
*******************************************************************************/
__STATIC_INLINE void Cy_HPPASS_DAC_Buf_SetInterruptMask(uint8_t dacIdx, uint32_t mask)
{

    CY_ASSERT_L1(CY_HPPASS_DAC_INDEX_VALID(dacIdx));
    HPPASS_DAC_INTR_MASK(HPPASS_BASE, dacIdx) = mask;
}

/*******************************************************************************
* Function Name: Cy_HPPASS_DAC_Buf_GetInterruptMask
****************************************************************************//**
*
* Get DAC Buffer interrupt mask.
*
* \param dacIdx
* DAC instance number (0-1)
*
* \return
* Current interrupt mask value.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_HPPASS_DAC_Buf_GetInterruptMask(uint8_t dacIdx)
{

    CY_ASSERT_L1(CY_HPPASS_DAC_INDEX_VALID(dacIdx));
    return (HPPASS_DAC_INTR_MASK(HPPASS_BASE, dacIdx));
}

/*******************************************************************************
* Function Name: Cy_HPPASS_DAC_Buf_GetInterruptStatusMasked
****************************************************************************//**
*
* Get DAC Buffer interrupt masked data.
*
* \param dacIdx
* DAC instance number (0-1)
*
* \return
* Masked interrupt status.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_HPPASS_DAC_Buf_GetInterruptStatusMasked(uint8_t dacIdx)
{

    CY_ASSERT_L1(CY_HPPASS_DAC_INDEX_VALID(dacIdx));
    return (HPPASS_DAC_INTR_MASKED(HPPASS_BASE, dacIdx));
}

/*******************************************************************************
* Function Name: Cy_HPPASS_DAC_FWStart
****************************************************************************//**
*
* To start DAC using firmware.
*
* \param dacIdx
* DAC instance number (0-1)
*
* \param dac_start
* true - start DAC, false - stop DAC.
*
*******************************************************************************/
__STATIC_INLINE void Cy_HPPASS_DAC_FWStart(uint8_t dacIdx, bool dac_start)
{

    CY_ASSERT_L1(CY_HPPASS_DAC_INDEX_VALID(dacIdx));
    if (dac_start)
    {
        HPPASS_DAC_MODE_START(HPPASS_BASE, dacIdx) |= HPPASS_DAC_BUFFER_DAC_BUFFER_DAC_BUFFER_MODE_START_FW_START_Msk;
    }
    else
    {
        HPPASS_DAC_MODE_START(HPPASS_BASE, dacIdx) &= ~HPPASS_DAC_BUFFER_DAC_BUFFER_DAC_BUFFER_MODE_START_FW_START_Msk;
    }
}

/*******************************************************************************
* Function Name: Cy_HPPASS_DAC_HWStart
****************************************************************************//**
*
* Enables or disables DAC hardware start trigger.
* When enabled, the DAC will start on the hardware trigger selected by
* \ref Cy_HPPASS_DAC_Init (startTriggerSelect).
*
* \param dacIdx
* DAC instance number (0-1)
*
* \param dac_start
* true - enable HW start, false - disable HW start.
*
*******************************************************************************/
__STATIC_INLINE void Cy_HPPASS_DAC_HWStart(uint8_t dacIdx, bool dac_start)
{

    CY_ASSERT_L1(CY_HPPASS_DAC_INDEX_VALID(dacIdx));
    if (dac_start)
    {
        HPPASS_DAC_MODE_START(HPPASS_BASE, dacIdx) |= HPPASS_DAC_BUFFER_DAC_BUFFER_DAC_BUFFER_MODE_START_HW_START_Msk;
    }
    else
    {
        HPPASS_DAC_MODE_START(HPPASS_BASE, dacIdx) &= ~HPPASS_DAC_BUFFER_DAC_BUFFER_DAC_BUFFER_MODE_START_HW_START_Msk;
    }
}

/*******************************************************************************
* Function Name: Cy_HPPASS_DAC_DeInit
****************************************************************************//**
*
* Resets all DAC Buffer registers of the specified instance to default values.
*
* \param dacIdx
* DAC instance number (0-1)
*
*******************************************************************************/
__STATIC_INLINE void Cy_HPPASS_DAC_DeInit(uint8_t dacIdx)
{
    CY_ASSERT_L1(CY_HPPASS_DAC_INDEX_VALID(dacIdx));
    if (CY_HPPASS_DAC_INDEX_VALID(dacIdx))
    {
        HPPASS_DAC_CFG(HPPASS_BASE, dacIdx) = 0UL;
        HPPASS_DAC_ANA_CTRL_1(HPPASS_BASE, dacIdx) = 0UL;
        HPPASS_DAC_ANA_CTRL_2(HPPASS_BASE, dacIdx) = 0UL;
        HPPASS_DAC_VAL_A(HPPASS_BASE, dacIdx) = 0UL;
        HPPASS_DAC_VAL_B(HPPASS_BASE, dacIdx) = 0UL;
        HPPASS_DAC_PERIOD(HPPASS_BASE, dacIdx) = 0UL;
        HPPASS_DAC_PARAM_SYNC(HPPASS_BASE, dacIdx) = 0UL;
        HPPASS_DAC_FIFO_CTRL(HPPASS_BASE, dacIdx) = 0UL;
        HPPASS_DAC_INTR(HPPASS_BASE, dacIdx) = 0x7FUL;  /* W1C: clear all interrupt flags */
        HPPASS_DAC_INTR_MASK(HPPASS_BASE, dacIdx) = 0UL;
    }
}

/** \} group_hppass_dac_functions */


#if defined(__cplusplus)
}
#endif

#endif /* CY_IP_MXS40MCPASS && CY_IP_MXS40MCPASS_VERSION >= 3u */

#endif /* CY_HPPASS_DAC_H */

/* [] END OF FILE */
