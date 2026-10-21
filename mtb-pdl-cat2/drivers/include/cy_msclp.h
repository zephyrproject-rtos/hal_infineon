/***************************************************************************//**
* \file cy_msclp.h
* \version 2.0
*
* The header file of the MSCLP driver.
*
********************************************************************************
* \copyright
* (c) (2021-2023), Cypress Semiconductor Corporation (an Infineon company) or
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

#if !defined(CY_MSCLP_H)
#define CY_MSCLP_H

#include "cy_device_headers.h"

#if defined(CY_IP_M0S8MSCV3LP)

/**
********************************************************************************
* \addtogroup group_msclp
********************************************************************************
* \{
*
* The MSCLP HW block represents the low power family of the fifth-generation CAPSENSE&trade;
* devices.
* It enables multiple sensing capabilities on PSOC&trade; devices,
* including the self-cap and mutual-cap capacitive touch-sense solutions and flyback
* inductive sensing solution.
*
* The CAPSENSE&trade; solution includes:
* * The CAPSENSE&trade; Configurator tool, which is a configuration wizard to create
*   and configure CAPSENSE&trade; widgets. It can be launched in ModusToolbox&trade;
*   from the MSCLP personality as well as in standalone mode.
*   It contains separate documentation on how to create and
*   configure widgets, parameters, and algorithm descriptions.
* * An API to control the design from the application program. This
*   documentation describes the API with code snippets about how to use them.
* * The CAPSENSE&trade; Tuner tool for real-time tuning, testing, and debugging,
*   for easy and smooth design of human interfaces on customer products.
*   The Tuner tool communicates with a device through a HW bridge and
*   communication drivers (EzI2C, UART, etc.) and allows monitoring of
*   widget statuses, sensor signals, detected touch positions, gestures, etc.
* The application program does not need to interact with the MSCLP driver
* and/or other drivers such as GPIO or SysClk directly. All of that is
* configured and managed by the middleware.
*
* \image html capsense_solution_msclp.png "CAPSENSE&trade; Solution" width=800px
* \image latex capsense_solution_msclp.png
*
* This section describes only the MSCLP driver. Refer to the corresponding
* sections for documentation of middleware supported by the MSCLP HW block.
*
* The MSCLP driver is a low-level peripheral driver that provides an interface to
* a complex mixed signal of the MSCLP HW block.
*
* The MSCLP driver alone does not provide system-level functions. Instead, it is
* used by upper-level middleware to configure the MSCLP HW block required by
* an application.
*
* The MSCLP HW block can support only one function at a time. To allow seamless
* time-multiplex implementation of functionality and to avoid conflicting access
* to hardware from the upper level, the MSCLP driver also implements a lock
* semaphore mechanism.
*
* The MSCLP driver supports re-entrance. If a device contains several
* MSCLP HW blocks, the same MSCLP driver is used to configure any HW block. For
* that, each function of the MSCLP driver contains a base address to define
* the MSCLP HW block to which the MSCLP driver communicates.
*
* There is no restriction on the MSCLP Driver usage in RTOS.
*
********************************************************************************
* \section group_msclp_config_usage Usage
********************************************************************************
*
* The MSCLP driver is a simple wrapper driver specifically designed to be used
* by higher level middleware. Hence, it is highly not recommended to use the MSCLP
* driver directly in the application program. To incorporate MSCLP HW block
* functionality in the application program, an associated middleware
* should be used.
*
* The MSCLP Driver can be used to implement a custom sensing solution. In such
* a case, the application program must acquire and lock the MSCLP HW block prior
* to accessing it.
*
* Setting up and using the MSCLP driver can be summed up in these four stages:
* * Define configuration in the config structure.
* * Allocate context structure variable for the driver.
* * Capture the MSCLP HW block.
* * Execute the action required to perform any kind of conversion.
*
* The following code snippet demonstrates how to capture the MSCLP HW block for
* custom implementation:
*
* \snippet msclp_snippet.c snippet_Cy_MSCLP_Context
* \snippet msclp_snippet.c snippet_Cy_MSCLP_Conversion
*
* \note
* User's application code should follow these recommendations:
* 1. The last sensor configuration in the frame should have the LAST bit of
*    SNS_CTL register set.
* 2. The START_FRAME bit of FRAME_CMD register should be set prior to calling
*    the Cy_MSCLP_ConfigureScan() API. It should be set once per frame if the
*    frame contains multiple sensor configurations, and each frame if the
*    frame contains only one sensor configuration.
* 3. The START_SCAN bit of SNS_CTL register should be set in the sensor frame
*    to start the conversion.
*
* The entire solution, like CAPSENSE&trade;, in addition to
* the MSCLP HW block, incorporates the following instances:
*
* * \ref group_msclp_config_clocks
* * \ref group_msclp_config_interrupts
* * \ref group_msclp_config_pin
*
* The MSCLP driver does not configure those blocks and they should be managed by
* an upper level. When using CAPSENSE&trade;, those blocks are managed by the
* middleware.
*
********************************************************************************
* \subsection group_msclp_config_clocks Clocks
********************************************************************************
*
* The MSCLP HW block requires a low frequency clock (clk_lf) for LF-AoS operation.
* It can be enabled either:
* * Using the Device Configurator (System tab).
* * Using the \ref group_sysclk driver.
*   See the \ref group_sysclk_ilo section for more details.
*
* Also the MSCLP HW block uses internal MRSS clock source for LF-AoS operation,
* see the Cy_MSCLP_MrssStart() function.
*
* If middleware is used, the clocks are managed by the middleware.
*
********************************************************************************
* \subsection group_msclp_config_pin GPIO Pins
********************************************************************************
* CAPSENSE&trade; provides the ability to form a user interface using widgets. Each
* widget consists of one or more sensors. These sensors are connected to the
* GPIO pins.
*
* The CAPSENSE&trade;-related GPIO pins can be divided into three groups:
* 1. Legacy GPIO sensor pads - all the GPIOs, where the CSD_SENSE/CSD_SHIELD HSIOM
*    connections are supported, the AMUXBUS-A/B are used to connect the
*    sensor and CAPSENSE&trade; HW block.
*    Required an update of GPIO registers (Drive mode and the HSIOM selection)
*    for this group of pins in order to set the sensor to the specific state
*    (GND, High-Z, Tx, Rx, etc...).
* 2. MSCv3LP-compatible GPIO sensor pads - a subset of GPIOs, that can be controlled
*    by the MSCLP HW block directly, the AMUXBUS-A/B are used to connect the
*    sensor and CAPSENSE&trade; HW block.
*    Not required an update of the GPIO registers (Drive mode and the HSIOM selection)
*    for this group of pins in order to set the sensor to the specific state
*    (GND, High-Z, Tx, Rx, etc...).
* 3. New MSCv3LP GPIO Cmod pads - dedicated pads for the external integration
*    capacitors.
*    Similarly to the MSCv3LP-compatible GPIOs, Cmod pads can be controlled by
*    the MSCLP HW block directly and can be used as extra sense pins.
*    These IOs have lower resistance compared to the legacy GPIOs and
*    MSCv3LP-compatible GPIOs.
*
* Usage of the MSCv3LP-compatible GPIO sensor pads under the CAPSENSE&trade; MW has the
* following advantages:
* * The CAPSENSE&trade; MW pre-calculates all needed configurations in advance (during
*   initialization)
* * The CAPSENSE&trade; MW triggers the next scanning by writing to several registers
*   of the MSCLP HW block (instead of disconnecting a previously scanned sensor
*   and connecting a new sensor).
*
* A GPIO input can be assigned to the MSCLP HW block using the following methods:
* * Using the Device Configurator (Pins tab).
* * Using the GPIO (General Purpose Input Output) driver. Refer
*   to the \ref group_gpio driver section.
*
* If middleware is used, pin configuration is managed by the middleware.
* Under the MSCLP driver custom implementation, the application program must
* manage the pin connections.
*
* Each AMUXBUS can be split into multiple segments. Ensure that the MSCLP HW block
* and a GPIO belong to the same bus segment or join the segments to establish
* the connection GPIO-to-MSCLP HW block.
*
* For more information about pin configuration, refer to the \ref group_gpio
* driver.
*
********************************************************************************
* \subsection group_msclp_config_interrupts Interrupts
********************************************************************************
*
* The MSCLP HW block implements two interrupts:
* * Active domain interrupt
* * Deep Sleep domain interrupt.
*
* The Active domain interrupt can be triggered by the following events:
* * Sub Sample: A valid CIC2 sub-sample is complete.
* * Sample:     A single sample is complete.
* * Scan:       A single scan is complete.
* * Init:       Coarse initialization is complete.
* * Frame:      A single frame is complete.
* * CIC2 Error: A CIC2 error is detected.
*
* The Deep Sleep domain interrupt can be triggered by the following events:
* * Signal Detect: LP-AoS has detected a signal wakeup.
* * Frame Timeout: LP-AoS has detected a frame timeout.
* * Frame:         A single frame is complete.
* * CE Done:       Channel Engine done signal. Asserted '1' at the end of the
*                  Channel Engine
*                  processing pipeline.
* * IMO Up:        MSCv3LP logic has turned on the MRSS IMO.
*
* The Active domain interrupt can wake up the device from the Sleep power mode.
* The Deep Sleep domain interrupt can wake up the device from the Deep Sleep
* power mode.
*
* If CAPSENSE&trade; MW is used, the interrupt service routine is managed
* by middleware. When using the MSCLP driver for custom implementation or other
* middleware, the application program must manage the interrupt service routine.
*
* Implement an interrupt routine and assign it to the MSCLP interrupt. Use the
* pre-defined enumeration as the interrupt source of the MSCLP HW block.
* The MSCLP interrupt to the NVIC is raised any time the intersection
* (logic AND) of the interrupt flags and the corresponding interrupt
* masks are non-zero. The peripheral interrupt status register should be
* read in the ISR to detect which condition generated the interrupt.
* The appropriate interrupt registers should be cleared so that
* subsequent interrupts can be handled.
*
* The following code snippet demonstrates how to implement a routine to handle
* the interrupt. The routine is called when a MSCLP interrupt is triggered.
*
* \snippet msclp_snippet.c snippet_Cy_MSCLP_IntHandler
* \snippet msclp_snippet.c snippet_Cy_MSCLP_IntHandlerLp
*
* The following code snippet demonstrates how to configure and enable
* the MSCLP interrupt:
*
* \snippet msclp_snippet.c snippet_Cy_MSCLP_IntEnabling
*
* For more information, refer to the \ref group_sysint driver.
*
* Alternatively, instead of handling the interrupts, the
* \ref Cy_MSCLP_GetConversionStatus() function allows for firmware
* polling of the MSCLP block status.
*
********************************************************************************
* \section group_msclp_config_power_modes Power Modes
********************************************************************************
*
* The MSCLP HW block can perform scans in Active, Sleep, and DeepSleep MCU power
* modes if it is configured for operation in the AS_MS or LP_AOS modes.
* If MSCLP HW block is configured for operation in the Interrupt Driven (CPU)
* mode, it can perform scans only in in Active or Sleep MCU power modes.
*
*
* \note
* 1. The MSCLP driver does not provide a callback function to facilitate the
*    MCU low-power mode transitions. The responsibility belongs to an upper
*    level that uses the MSCLP HW block to ensure the MSCLP HW block is ready
*    to a power mode transition.
* 2. MCU transition to Deep Sleep power mode is not recommended if the MSCLP HW
*    block operates in Interrupt Driven (CPU) mode and it is busy. Unexpected
*    behavior may occur.
*    The MSCLP HW block status must be checked using the Cy_MSCLP_GetStatus()
*    function prior to a power mode transition in this case. This restriction is
*    not applicable to Sleep mode and the device can seamlessly enter and exit
*    Sleep mode while the MSCLP HW block is busy.
*
* Refer to the \ref group_syspm driver for more information about
* low-power mode transitions.
*
********************************************************************************
* \section group_msclp_more_information More Information
********************************************************************************
*
* Important information about the CAPSENSE&trade; technology overview, appropriate
* Infineon device for the design, CAPSENSE&trade; system and sensor design guidelines,
* different interfaces and tuning guidelines necessary for a successful design
* of a CAPSENSE&trade; system is available in the Getting Started with CAPSENSE&trade;
* document and the product-specific CAPSENSE&trade; design guide. Infineon highly
* recommends starting with these documents. They can be found on the
* Infineon web site at www.infineon.com
*
* For more information, refer to the following documents:
*
* * CAPSENSE&trade; Overview:
*
*   * <a href="https://github.com/Infineon/capsense">
*     <b>CAPSENSE&trade; Middleware Library</b></a>
*
*   * <a href="https://infineon.github.io/capsense/capsense_api_reference_manual/html/index.html">
*     <b>CAPSENSE&trade; Middleware API Reference Guide</b></a>
*
*   * <a href="https://documentation.infineon.com/html/modustoolbox-software/en/latest/tool-guide/ModusToolbox_CapSense_Configurator_Guide.html">
*     <b>ModusToolbox&trade; CAPSENSE&trade; Configurator Tool Guide</b></a>
*
*   * <a href="https://documentation.infineon.com/html/modustoolbox-software/en/latest/tool-guide/ModusToolbox_CapSense_Tuner_Guide.html">
*     <b>ModusToolbox&trade; CAPSENSE&trade; Tuner Tool Guide</b></a>
*
*   * <a href="https://www.infineon.com/dgdl/Infineon-AN85951_PSoC_4_and_PSoC_6_MCU_CapSense_Design_Guide-ApplicationNotes-v27_00-EN.pdf?fileId=8ac78c8c7cdc391c017d0723535d4661">
*     <b>CAPSENSE&trade; Design Guide</b></a>
*
* * ModusToolbox&trade; Overview:
*
*   * <a href="https://www.infineon.com/cms/en/design-support/tools/sdk/modustoolbox-software">
*     <b>ModusToolbox&trade; Software Environment, Quick Start Guide, Documentation, and Videos</b></a>
*
*   * <a href="https://documentation.infineon.com/html/modustoolbox-software/en/latest/tool-guide/ModusToolbox_Device_Configurator_Guide.html">
*     <b>ModusToolbox&trade; Device Configurator Tool Guide</b></a>
*
* * Infineon Kits:
*
*   * Information will be available later. In case of urgency, contact
*     the technical support group.
*
* * General Information:
*
*   * <a href="https://infineon.github.io/mtb-pdl-cat2/pdl_api_reference_manual/html/index.html">
*     <b>PDL API Reference</b></a>
*
*   * <a href="https://github.com/Infineon"><b>Infineon Technologies GitHub</b></a>
*
*   * <a href="http://www.infineon.com"><b>Infineon Technologies</b></a>
*
* \note
* The links to another software component's documentation (middleware and PDL)
* point to GitHub to the latest available version of the software.
* To get documentation of the specified version, download from GitHub and unzip
* the component archive. The documentation is available in the <i>docs</i> folder.
*
********************************************************************************
* \section group_msclp_changelog Changelog
********************************************************************************
* <table class="doxtable">
*   <tr><th>Version</th><th>Changes</th><th>Reason for Change</th></tr>
*   <tr>
*     <td>2.0</td>
*     <td>Changed name of defines:
*         CY_MSCLP_IMO_24_MHZ -> \ref CY_MSCLP_IMO_25_MHZ,
*         CY_MSCLP_IMO_36_MHZ -> \ref CY_MSCLP_IMO_38_MHZ,
*         CY_MSCLP_IMO_48_MHZ -> \ref CY_MSCLP_IMO_46_MHZ</td>
*     <td>Names consistency with HW frequency.</td>
*   </tr>
*   <tr>
*     <td>1.0</td>
*     <td>The initial version</td>
*     <td></td>
*   </tr>
* </table>
*
*
*  \defgroup group_msclp_macros                Macros
*  \defgroup group_msclp_functions             Functions
*  \defgroup group_msclp_data_structures       Data Structures
*  \defgroup group_msclp_enums                 Enumerated Types
* \}
*/

#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include "cy_syslib.h"

#if defined(__cplusplus)
extern "C" {
#endif

/**
* \addtogroup group_msclp_macros
* \{
*/

/** Driver major version */
#define CY_MSCLP_DRV_VERSION_MAJOR            (2)

/** Driver minor version */
#define CY_MSCLP_DRV_VERSION_MINOR            (0)

/** Macro to support the backward compatibility. Do not use for new designs. */
#define CY_MSCLP_DRV_VERSION                  (100)

/******************************************************************************
* API Constants
******************************************************************************/

/** MSCLP driver identifier */
#define CY_MSCLP_ID                           (CY_PDL_DRV_ID(0x49u))

/** Initialization macro for the driver context variable */
#define CY_MSCLP_CONTEXT_INIT_VALUE           {.lockKey = CY_MSCLP_NONE_KEY}

/** MRSS IMO frequencies, to be used for \ref cy_stc_msclp_mrss_config_t::imoFreq */
#define CY_MSCLP_IMO_25_MHZ                   (0u) /**< IMO frequency 25 MHz */
#define CY_MSCLP_IMO_38_MHZ                   (3u) /**< IMO frequency 38 MHz */
#define CY_MSCLP_IMO_46_MHZ                   (6u) /**< IMO frequency 46 MHz */

/** MRSS IMO_CTL.CLOCK_SYNC_DIV values, to be used for \ref cy_stc_msclp_mrss_config_t::syncDiv */
#define CY_MSCLP_SYNC_DIV_1                   (0u) /**< Dividing by 1 */
#define CY_MSCLP_SYNC_DIV_2                   (1u) /**< Dividing by 2 */
#define CY_MSCLP_SYNC_DIV_3                   (2u) /**< Dividing by 3 */
#define CY_MSCLP_SYNC_DIV_4                   (3u) /**< Dividing by 4 */
#define CY_MSCLP_SYNC_DIV_5                   (4u) /**< Dividing by 5 */
#define CY_MSCLP_SYNC_DIV_6                   (5u) /**< Dividing by 6 */
#define CY_MSCLP_SYNC_DIV_7                   (6u) /**< Dividing by 7 */
#define CY_MSCLP_SYNC_DIV_8                   (7u) /**< Dividing by 8 */

/** One hundred percentage */
#define CY_MSCLP_PERCENTAGE_100               (100u)
/** 8-bit shift */
#define CY_MSCLP_8_BIT_SHIFT                  (8u)
/** The lowest 8-bit mask */
#define CY_MSCLP_LSB_MASK                     (0x000000FFu)
/** Maximum number of registers in sensor frame with support of HW baselining (HW channel engine) */
#define CY_MSCLP_11_SNS_REGS                  (11u)
/** Maximum number of registers in sensor frame with support up to 8 pin states */
#define CY_MSCLP_6_SNS_REGS                   (6u)
/** Maximum number of registers in sensor frame with support up to 4 pin states */
#define CY_MSCLP_5_SNS_REGS                   (5u)
/** SNS.SENSOR_DATA size in 4-byte words */
#define CY_MSCLP_SNS_SRAM_WORD_SIZE           (MSCLP_SRAM_SIZE / 4U)
/** Pointer to the SNS.SENSOR_DATA[CY_MSCLP_SNS_SRAM_WORD_SIZE] internal SRAM */
#define CY_MSCLP_SENSOR_DATA_PTR(base)        ((base)->SNS.SENSOR_DATA)
/** VDDA threshold voltage in millivolts for PUMP enabling */
#define CY_MSCLP_VDDA_PUMP_TRESHOLD           (4000u)
/** The maximum possible value of the CLK_LF period in microseconds */
#define CY_MSCLP_CLK_LF_PERIOD_MAX            (63u)
/** Full (REF, IMO, PUMP) MRSS start timeout in CLK_LF periods */
#define CY_MSCLP_MRSS_TIMEOUT_FULL            (7u)
/** MRSS start timeout without PUMP (REF and IMO only) in CLK_LF periods */
#define CY_MSCLP_MRSS_TIMEOUT_SMALL           (5u)
/** The maximum possible pin function registers in the MSCLP IP block */
#define CY_MSCLP_CSW_GLOBAL_FUNC_NR_MAX       (8u)
/** The maximum possible sensing mode registers in the MSCLP IP block */
#define CY_MSCLP_SENSE_MODE_NR_MAX            (4u)
/** The maximal possible value of the \ref cy_stc_msclp_mrss_config_t::mscDiv */
#define CY_MSCLP_MSC_DIV_MAX                  (1024u)


/*******************************************************************************
* The MSCLP HW Block Registers Constants
*******************************************************************************/

/**
* \defgroup group_msclp_reg_const Registers Constants
* \{
*/

/** \} group_msclp_reg_const */

/** \} group_msclp_macros */


/*******************************************************************************
 * Enumerations
 ******************************************************************************/

/**
* \addtogroup group_msclp_enums
* \{
*/

/** MSCLP status definitions */
typedef enum
{
    /** Successful */
    CY_MSCLP_SUCCESS = 0x00u,

    /** One or more invalid parameters */
    CY_MSCLP_BAD_PARAM = CY_MSCLP_ID | CY_PDL_STATUS_ERROR | 0x01u,

    /** The MSCLP HW block performs conversion */
    CY_MSCLP_BUSY =  CY_MSCLP_ID | CY_PDL_STATUS_ERROR | 0x02u,

    /** The MSCLP HW block is captured by another middleware */
    CY_MSCLP_LOCKED =  CY_MSCLP_ID | CY_PDL_STATUS_ERROR | 0x03u,

    /** The MSCLP HW block operation reaches timeout */
    CY_MSCLP_TIMEOUT =  CY_MSCLP_ID | CY_PDL_STATUS_ERROR | 0x04u,

    /** The MRSS is disabled */
    CY_MSCLP_MRSS_DISABLED =  CY_MSCLP_ID | CY_PDL_STATUS_ERROR | 0x05u,
} cy_en_msclp_status_t;


/**
* Definitions of upper level keys that use the driver.
*
* Each middleware has a unique key assigned. When middleware successfully
* captures the MSCLP HW block, this key is placed into the MSCLP driver context
* structure. All attempts to capture the MSCLP HW block by other middleware
* are rejected. When the first middleware releases the MSCLP HW block,
* CY_MSCLP_NONE_KEY is written to the lockKey variable of the MSCLP driver context
* structure and any other middleware can capture the MSCLP HW block.
*/
typedef enum
{
    /** The MSCLP HW block is unused and not captured by any middleware */
    CY_MSCLP_NONE_KEY = 0u,

    /**
    * The MSCLP HW block is captured by the application program
    * directly to implement a customer's specific case
    */
    CY_MSCLP_USER_DEFINED_KEY = 1u,

    /** The MSCLP HW block is captured by a CAPSENSE&trade; middleware */
    CY_MSCLP_CAPSENSE_KEY = 2u,

}cy_en_msclp_key_t;
/** \} group_msclp_enums */


/*******************************************************************************
*       Type Definitions
*******************************************************************************/

/**
* \addtogroup group_msclp_data_structures
* \{
*/

/**
* Sensing method configuration structure.
* This structure consolidates sensing method registers of the MSCLP HW block.
*/
typedef struct
{
    uint32_t senseDutyCtl;              /**< Stores the MSCLP.MODE.SENSE_DUTY_CTL register value */
    uint32_t swSelCdacFl;               /**< Stores the MSCLP.MODE.SW_SEL_CDAC_FL register value */
    uint32_t swSelTop;                  /**< Stores the MSCLP.MODE.SW_SEL_TOP register value */
    uint32_t swSelComp;                 /**< Stores the MSCLP.MODE.SW_SEL_COMP register value */
    uint32_t swSelSh;                   /**< Stores the MSCLP.MODE.SW_SEL_SH register value */
    uint32_t swSelCmod1;                /**< Stores the MSCLP.MODE.SW_SEL_CMOD1 register value */
    uint32_t swSelCmod2;                /**< Stores the MSCLP.MODE.SW_SEL_CMOD2 register value */
} cy_stc_msclp_mode_config_t;

/**
* MSCLP base configuration structure.
*
* This structure contains almost all register values of the MSCLP HW block. This
* structure is provided by middleware through the Cy_MSCLP_Init() and
* Cy_MSCLP_Configure() functions to implement the MSCLP HW block supported
* sensing modes like self-cap / mutual-cap scanning, etc.
*/
typedef struct
{
    uint32_t ctl;                                         /**< Stores the MSCLP.CTL register value */
    uint32_t scanCtl1;                                    /**< Stores the MSCLP.SCAN_CTL1 register value */
    uint32_t scanCtl2;                                    /**< Stores the MSCLP.SCAN_CTL2 register value */
    uint32_t initCtl1;                                    /**< Stores the MSCLP.INIT_CTL1 register value */
    uint32_t initCtl2;                                    /**< Stores the MSCLP.INIT_CTL2 register value */
    uint32_t initCtl3;                                    /**< Stores the MSCLP.INIT_CTL3 register value */
    uint32_t initCtl4;                                    /**< Stores the MSCLP.INIT_CTL4 register value */
    uint32_t senseDutyCtl;                                /**< Stores the MSCLP.SENSE_DUTY_CTL register value */
    uint32_t sensePeriodCtl;                              /**< Stores the MSCLP.SENSE_PERIOD_CTL register value */
    uint32_t filterCtl;                                   /**< Stores the MSCLP.FILTER_CTL register value */
    uint32_t ccompCdacCtl;                                /**< Stores the MSCLP.CCOMP_CDAC_CTL register value */
    uint32_t ditherCdacCtl;                               /**< Stores the MSCLP.DITHER_CDAC_CTL register value */
    uint32_t mscCmpCtl;                                   /**< Stores the MSCLP.MSCCMP_CTL register value */
    uint32_t obsCtl;                                      /**< Stores the MSCLP.OBS_CTL register value */
    uint32_t aosCtl;                                      /**< Stores the MSCLP.AOS_CTL register value */
    uint32_t ceCtl;                                       /**< Stores the MSCLP.CE_CTL register value */
    uint32_t pumpCtl;                                     /**< Stores the MSCLP.PUMP_CTL register value */
    uint32_t imoCtl;                                      /**< Stores the MSCLP.IMO_CTL register value */
    uint32_t intr;                                        /**< Stores the MSCLP.INTR_MASK register value */
    uint32_t intrSet;                                     /**< Stores the MSCLP.INTR_MASK register value */
    uint32_t intrMask;                                    /**< Stores the MSCLP.INTR_MASK register value */
    uint32_t intrLp;                                      /**< Stores the MSCLP.INTR_LP register value */
    uint32_t intrLpSet;                                   /**< Stores the MSCLP.INTR_LP_SET register value */
    uint32_t intrLpMask;                                  /**< Stores the MSCLP.INTR_LP_MASK register value */
    uint32_t swSelCdacRe;                                 /**< Stores the MSCLP.SW_SEL_CDAC_RE register value */
    uint32_t swSelCdacCo;                                 /**< Stores the MSCLP.SW_SEL_CDAC_CO register value */
    uint32_t swSelCdacCf;                                 /**< Stores the MSCLP.SW_SEL_CDAC_CF register value */
    uint32_t swSelBgr;                                    /**< Stores the MSCLP.SW_SEL_BGR register value */
    uint32_t swSelCswFunc[CY_MSCLP_CSW_GLOBAL_FUNC_NR_MAX]; /**< Stores the MSCLP.SW_SEL_CSW_FUNC registers values,
                                                           *   The real number of these registers may be limited by the particular
                                                           *   devise settings, see MSCLP_CSW_GLOBAL_FUNC_NR in the device headers.
                                                           */
    cy_stc_msclp_mode_config_t mode[CY_MSCLP_SENSE_MODE_NR_MAX]; /**< Stores the MSCLP.MODE registers values,
                                                           *   The real number of these structures may be limited by the particular
                                                           *   devise settings, see MSCLP_SENSE_MODE_NR in the device headers.
                                                           */
} cy_stc_msclp_base_config_t;


/**
* MRSS configuration structure.
* This structure contains values needed for MRSS configuring.
*/
typedef struct
{
    uint8_t imoFreq;  /**< The clk_imo_msc frequency, \ref CY_MSCLP_IMO_25_MHZ, \ref CY_MSCLP_IMO_38_MHZ or \ref CY_MSCLP_IMO_46_MHZ */
    uint8_t syncDiv;  /**< Clock division for clk_imo_msc to clk_sync, \ref CY_MSCLP_SYNC_DIV_1...\ref CY_MSCLP_SYNC_DIV_8 */
    uint16_t mscDiv;  /**< The clk_msc divider, i.e. the ratio between clk_imo_msc and clk_msc. Valid range: 1...1024 */
    uint16_t vdda;    /**< System VDDA value in millivolts */
} cy_stc_msclp_mrss_config_t;


/**
* MSCLP driver context structure.
* This structure is an internal structure of the MSCLP driver and should not be
* accessed directly by the application program.
*/
typedef struct
{
    /** Middleware ID that currently captured MSCLP */
    cy_en_msclp_key_t lockKey;
} cy_stc_msclp_context_t;

/** \} group_msclp_data_structures */

/**
* \addtogroup group_msclp_reg_const
* \{
*/


#define CY_MSCLP_REG_OFFSET_CTL                       (offsetof(MSCLP_Type, CTL))              /**< The register offset */
#define CY_MSCLP_REG_OFFSET_SPARE                     (offsetof(MSCLP_Type, SPARE))            /**< The register offset */
#define CY_MSCLP_REG_OFFSET_SCAN_CTL1                 (offsetof(MSCLP_Type, SCAN_CTL1))        /**< The register offset */
#define CY_MSCLP_REG_OFFSET_SCAN_CTL2                 (offsetof(MSCLP_Type, SCAN_CTL2))        /**< The register offset */
#define CY_MSCLP_REG_OFFSET_INIT_CTL1                 (offsetof(MSCLP_Type, INIT_CTL1))        /**< The register offset */
#define CY_MSCLP_REG_OFFSET_INIT_CTL2                 (offsetof(MSCLP_Type, INIT_CTL2))        /**< The register offset */
#define CY_MSCLP_REG_OFFSET_INIT_CTL3                 (offsetof(MSCLP_Type, INIT_CTL3))        /**< The register offset */
#define CY_MSCLP_REG_OFFSET_INIT_CTL4                 (offsetof(MSCLP_Type, INIT_CTL4))        /**< The register offset */
#define CY_MSCLP_REG_OFFSET_SENSE_DUTY_CTL            (offsetof(MSCLP_Type, SENSE_DUTY_CTL))   /**< The register offset */
#define CY_MSCLP_REG_OFFSET_SENSE_PERIOD_CTL          (offsetof(MSCLP_Type, SENSE_PERIOD_CTL)) /**< The register offset */
#define CY_MSCLP_REG_OFFSET_FILTER_CTL                (offsetof(MSCLP_Type, FILTER_CTL))       /**< The register offset */
#define CY_MSCLP_REG_OFFSET_CCOMP_CDAC_CTL            (offsetof(MSCLP_Type, CCOMP_CDAC_CTL))   /**< The register offset */
#define CY_MSCLP_REG_OFFSET_DITHER_CDAC_CTL           (offsetof(MSCLP_Type, DITHER_CDAC_CTL))  /**< The register offset */
#define CY_MSCLP_REG_OFFSET_MSCCMP_CTL                (offsetof(MSCLP_Type, MSCCMP_CTL))       /**< The MSCCMP_CTL register offset */
#define CY_MSCLP_REG_OFFSET_OBS_CTL                   (offsetof(MSCLP_Type, OBS_CTL))          /**< The OBS_CTL register offset */
#define CY_MSCLP_REG_OFFSET_AOS_CTL                   (offsetof(MSCLP_Type, AOS_CTL))          /**< The AOS_CTL register offset */
#define CY_MSCLP_REG_OFFSET_CE_CTL                    (offsetof(MSCLP_Type, CE_CTL))           /**< The CE_CTL register offset */
#define CY_MSCLP_REG_OFFSET_PUMP_CTL                  (offsetof(MSCLP_Type, PUMP_CTL))         /**< The PUMP_CTL register offset */
#define CY_MSCLP_REG_OFFSET_IMO_CTL                   (offsetof(MSCLP_Type, IMO_CTL))          /**< The IMO_CTL register offset */

#define CY_MSCLP_REG_OFFSET_INTR                      (offsetof(MSCLP_Type, INTR))             /**< The  register offset */
#define CY_MSCLP_REG_OFFSET_INTR_SET                  (offsetof(MSCLP_Type, INTR_SET))         /**< The  register offset */
#define CY_MSCLP_REG_OFFSET_INTR_MASK                 (offsetof(MSCLP_Type, INTR_MASK))        /**< The  register offset */
#define CY_MSCLP_REG_OFFSET_INTR_MASKED               (offsetof(MSCLP_Type, INTR_MASKED))      /**< The  register offset */
#define CY_MSCLP_REG_OFFSET_INTR_LP                   (offsetof(MSCLP_Type, INTR_LP))          /**< The  register offset */
#define CY_MSCLP_REG_OFFSET_INTR_LP_SET               (offsetof(MSCLP_Type, INTR_LP_SET))      /**< The  register offset */
#define CY_MSCLP_REG_OFFSET_INTR_LP_MASK              (offsetof(MSCLP_Type, INTR_LP_MASK))     /**< The  register offset */
#define CY_MSCLP_REG_OFFSET_INTR_LP_MASKED            (offsetof(MSCLP_Type, INTR_LP_MASKED))   /**< The  register offset */

#define CY_MSCLP_REG_OFFSET_WAKEUP_CMD                (offsetof(MSCLP_Type, WAKEUP_CMD))         /**< The WAKEUP_CMD register offset */
#define CY_MSCLP_REG_OFFSET_MRSS_CMD                  (offsetof(MSCLP_Type, MRSS_CMD))           /**< The MRSS_CMD register offset */
#define CY_MSCLP_REG_OFFSET_MRSS_STATUS               (offsetof(MSCLP_Type, MRSS_STATUS))        /**< The MRSS_STATUS register offset */
#define CY_MSCLP_REG_OFFSET_AOS_STATUS                (offsetof(MSCLP_Type, AOS_STATUS))         /**< The AOS_STATUS register offset */
#define CY_MSCLP_REG_OFFSET_SW_SEL_GPIO               (offsetof(MSCLP_Type, SW_SEL_GPIO))        /**< The SW_SEL_GPIO register offset */
#define CY_MSCLP_REG_OFFSET_SW_SEL_CDAC_RE            (offsetof(MSCLP_Type, SW_SEL_CDAC_RE))     /**< The SW_SEL_CDAC_RE register offset */
#define CY_MSCLP_REG_OFFSET_SW_SEL_CDAC_CO            (offsetof(MSCLP_Type, SW_SEL_CDAC_CO))     /**< The SW_SEL_CDAC_CO register offset */
#define CY_MSCLP_REG_OFFSET_SW_SEL_CDAC_CF            (offsetof(MSCLP_Type, SW_SEL_CDAC_CF))     /**< The SW_SEL_CDAC_CF register offset */
#define CY_MSCLP_REG_OFFSET_SW_SEL_BGR                (offsetof(MSCLP_Type, SW_SEL_BGR))         /**< The SW_SEL_BGR register offset */

#define CY_MSCLP_REG_OFFSET_SW_SEL_CSW_FUNC0          (offsetof(MSCLP_Type, SW_SEL_CSW_FUNC[0]))     /**< The SW_SEL_CSW_FUNC[0] register offset */
#define CY_MSCLP_REG_OFFSET_SW_SEL_CSW_FUNC1          (offsetof(MSCLP_Type, SW_SEL_CSW_FUNC[1]))     /**< The SW_SEL_CSW_FUNC[1] register offset */
#define CY_MSCLP_REG_OFFSET_SW_SEL_CSW_FUNC2          (offsetof(MSCLP_Type, SW_SEL_CSW_FUNC[2]))     /**< The SW_SEL_CSW_FUNC[2] register offset */
#define CY_MSCLP_REG_OFFSET_SW_SEL_CSW_FUNC3          (offsetof(MSCLP_Type, SW_SEL_CSW_FUNC[3]))     /**< The SW_SEL_CSW_FUNC[3] register offset */
#define CY_MSCLP_REG_OFFSET_SW_SEL_CSW_FUNC4          (offsetof(MSCLP_Type, SW_SEL_CSW_FUNC[4]))     /**< The SW_SEL_CSW_FUNC[4] register offset */
#define CY_MSCLP_REG_OFFSET_SW_SEL_CSW_FUNC5          (offsetof(MSCLP_Type, SW_SEL_CSW_FUNC[5]))     /**< The SW_SEL_CSW_FUNC[5] register offset */
#define CY_MSCLP_REG_OFFSET_SW_SEL_CSW_FUNC6          (offsetof(MSCLP_Type, SW_SEL_CSW_FUNC[6]))     /**< The SW_SEL_CSW_FUNC[6] register offset */
#define CY_MSCLP_REG_OFFSET_SW_SEL_CSW_FUNC7          (offsetof(MSCLP_Type, SW_SEL_CSW_FUNC[7]))     /**< The SW_SEL_CSW_FUNC[7] register offset */

#define CY_MSCLP_REG_OFFSET_CSW_CTL_LO                (offsetof(MSCLP_Type, CSW_CTL_LO))             /**< The CSW_CTL_LO register offset */

#define CY_MSCLP_REG_OFFSET_MODE0_SENSE_DUTY_CTL      (offsetof(MSCLP_Type, MODE[0].SENSE_DUTY_CTL)) /**< The  register offset */
#define CY_MSCLP_REG_OFFSET_MODE0_SW_SEL_CDAC_FL      (offsetof(MSCLP_Type, MODE[0].SW_SEL_CDAC_FL)) /**< The  register offset */
#define CY_MSCLP_REG_OFFSET_MODE0_SW_SEL_TOP          (offsetof(MSCLP_Type, MODE[0].SW_SEL_TOP))     /**< The  register offset */
#define CY_MSCLP_REG_OFFSET_MODE0_SW_SEL_COMP         (offsetof(MSCLP_Type, MODE[0].SW_SEL_COMP))    /**< The  register offset */
#define CY_MSCLP_REG_OFFSET_MODE0_SW_SEL_SH           (offsetof(MSCLP_Type, MODE[0].SW_SEL_SH))      /**< The  register offset */
#define CY_MSCLP_REG_OFFSET_MODE0_SW_SEL_CMOD1        (offsetof(MSCLP_Type, MODE[0].SW_SEL_CMOD1))   /**< The MODE[0].SW_SEL_CMOD1 register offset */
#define CY_MSCLP_REG_OFFSET_MODE0_SW_SEL_CMOD2        (offsetof(MSCLP_Type, MODE[0].SW_SEL_CMOD2))   /**< The MODE[0].SW_SEL_CMOD2 register offset */
#define CY_MSCLP_REG_OFFSET_MODE0_SW_SEL_CMOD3        (offsetof(MSCLP_Type, MODE[0].SW_SEL_CMOD3))   /**< The MODE[0].SW_SEL_CMOD3 register offset */
#define CY_MSCLP_REG_OFFSET_MODE0_SW_SEL_CMOD4        (offsetof(MSCLP_Type, MODE[0].SW_SEL_CMOD4))   /**< The MODE[0].SW_SEL_CMOD4 register offset */

#define CY_MSCLP_REG_OFFSET_MODE1_SENSE_DUTY_CTL      (offsetof(MSCLP_Type, MODE[1].SENSE_DUTY_CTL)) /**< The  register offset */
#define CY_MSCLP_REG_OFFSET_MODE1_SW_SEL_CDAC_FL      (offsetof(MSCLP_Type, MODE[1].SW_SEL_CDAC_FL)) /**< The  register offset */
#define CY_MSCLP_REG_OFFSET_MODE1_SW_SEL_TOP          (offsetof(MSCLP_Type, MODE[1].SW_SEL_TOP))     /**< The  register offset */
#define CY_MSCLP_REG_OFFSET_MODE1_SW_SEL_COMP         (offsetof(MSCLP_Type, MODE[1].SW_SEL_COMP))    /**< The  register offset */
#define CY_MSCLP_REG_OFFSET_MODE1_SW_SEL_SH           (offsetof(MSCLP_Type, MODE[1].SW_SEL_SH))      /**< The  register offset */
#define CY_MSCLP_REG_OFFSET_MODE1_SW_SEL_CMOD1        (offsetof(MSCLP_Type, MODE[1].SW_SEL_CMOD1))   /**< The MODE[1].SW_SEL_CMOD1 register offset */
#define CY_MSCLP_REG_OFFSET_MODE1_SW_SEL_CMOD2        (offsetof(MSCLP_Type, MODE[1].SW_SEL_CMOD2))   /**< The MODE[1].SW_SEL_CMOD2 register offset */
#define CY_MSCLP_REG_OFFSET_MODE1_SW_SEL_CMOD3        (offsetof(MSCLP_Type, MODE[1].SW_SEL_CMOD3))   /**< The MODE[1].SW_SEL_CMOD3 register offset */
#define CY_MSCLP_REG_OFFSET_MODE1_SW_SEL_CMOD4        (offsetof(MSCLP_Type, MODE[1].SW_SEL_CMOD4))   /**< The MODE[1].SW_SEL_CMOD4 register offset */

#define CY_MSCLP_REG_OFFSET_MODE2_SENSE_DUTY_CTL      (offsetof(MSCLP_Type, MODE[2].SENSE_DUTY_CTL)) /**< The  register offset */
#define CY_MSCLP_REG_OFFSET_MODE2_SW_SEL_CDAC_FL      (offsetof(MSCLP_Type, MODE[2].SW_SEL_CDAC_FL)) /**< The  register offset */
#define CY_MSCLP_REG_OFFSET_MODE2_SW_SEL_TOP          (offsetof(MSCLP_Type, MODE[2].SW_SEL_TOP))     /**< The  register offset */
#define CY_MSCLP_REG_OFFSET_MODE2_SW_SEL_COMP         (offsetof(MSCLP_Type, MODE[2].SW_SEL_COMP))    /**< The  register offset */
#define CY_MSCLP_REG_OFFSET_MODE2_SW_SEL_SH           (offsetof(MSCLP_Type, MODE[2].SW_SEL_SH))      /**< The  register offset */
#define CY_MSCLP_REG_OFFSET_MODE2_SW_SEL_CMOD1        (offsetof(MSCLP_Type, MODE[2].SW_SEL_CMOD1))   /**< The MODE[2].SW_SEL_CMOD1 register offset */
#define CY_MSCLP_REG_OFFSET_MODE2_SW_SEL_CMOD2        (offsetof(MSCLP_Type, MODE[2].SW_SEL_CMOD2))   /**< The MODE[2].SW_SEL_CMOD2 register offset */
#define CY_MSCLP_REG_OFFSET_MODE2_SW_SEL_CMOD3        (offsetof(MSCLP_Type, MODE[2].SW_SEL_CMOD3))   /**< The MODE[2].SW_SEL_CMOD3 register offset */
#define CY_MSCLP_REG_OFFSET_MODE2_SW_SEL_CMOD4        (offsetof(MSCLP_Type, MODE[2].SW_SEL_CMOD4))   /**< The MODE[2].SW_SEL_CMOD4 register offset */

#define CY_MSCLP_REG_OFFSET_MODE3_SENSE_DUTY_CTL      (offsetof(MSCLP_Type, MODE[3].SENSE_DUTY_CTL)) /**< The  register offset */
#define CY_MSCLP_REG_OFFSET_MODE3_SW_SEL_CDAC_FL      (offsetof(MSCLP_Type, MODE[3].SW_SEL_CDAC_FL)) /**< The  register offset */
#define CY_MSCLP_REG_OFFSET_MODE3_SW_SEL_TOP          (offsetof(MSCLP_Type, MODE[3].SW_SEL_TOP))     /**< The  register offset */
#define CY_MSCLP_REG_OFFSET_MODE3_SW_SEL_COMP         (offsetof(MSCLP_Type, MODE[3].SW_SEL_COMP))    /**< The  register offset */
#define CY_MSCLP_REG_OFFSET_MODE3_SW_SEL_SH           (offsetof(MSCLP_Type, MODE[3].SW_SEL_SH))      /**< The  register offset */
#define CY_MSCLP_REG_OFFSET_MODE3_SW_SEL_CMOD1        (offsetof(MSCLP_Type, MODE[3].SW_SEL_CMOD1))   /**< The MODE[3].SW_SEL_CMOD1 register offset */
#define CY_MSCLP_REG_OFFSET_MODE3_SW_SEL_CMOD2        (offsetof(MSCLP_Type, MODE[3].SW_SEL_CMOD2))   /**< The MODE[3].SW_SEL_CMOD2 register offset */
#define CY_MSCLP_REG_OFFSET_MODE3_SW_SEL_CMOD3        (offsetof(MSCLP_Type, MODE[3].SW_SEL_CMOD3))   /**< The MODE[3].SW_SEL_CMOD3 register offset */
#define CY_MSCLP_REG_OFFSET_MODE3_SW_SEL_CMOD4        (offsetof(MSCLP_Type, MODE[3].SW_SEL_CMOD4))   /**< The MODE[3].SW_SEL_CMOD4 register offset */

#define CY_MSCLP_REG_OFFSET_SENSOR_DATA               (offsetof(MSCLP_Type, SENSOR_DATA))            /**< The SENSOR_DATA memory array offset */

#define CY_MSCLP_REG_OFFSET_SNS_LP_AOS_SNS_CTL0       (offsetof(MSCLP_Type, SNS.SNS_LP_AOS_SNS_CTL0))       /**< The SNS_LP_AOS_SNS_CTL0 register offset */
#define CY_MSCLP_REG_OFFSET_SNS_LP_AOS_SNS_CTL1       (offsetof(MSCLP_Type, SNS.SNS_LP_AOS_SNS_CTL1))       /**< The SNS_LP_AOS_SNS_CTL1 register offset */
#define CY_MSCLP_REG_OFFSET_SNS_LP_AOS_SNS_CTL2       (offsetof(MSCLP_Type, SNS.SNS_LP_AOS_SNS_CTL2))       /**< The SNS_LP_AOS_SNS_CTL2 register offset */
#define CY_MSCLP_REG_OFFSET_SNS_LP_AOS_SNS_CTL3       (offsetof(MSCLP_Type, SNS.SNS_LP_AOS_SNS_CTL3))       /**< The SNS_LP_AOS_SNS_CTL3 register offset */
#define CY_MSCLP_REG_OFFSET_SNS_LP_AOS_SNS_CTL4       (offsetof(MSCLP_Type, SNS.SNS_LP_AOS_SNS_CTL4))       /**< The SNS_LP_AOS_SNS_CTL4 register offset */
#define CY_MSCLP_REG_OFFSET_SNS_SW_SEL_CSW_HI_MASK2   (offsetof(MSCLP_Type, SNS.SNS_SW_SEL_CSW_HI_MASK2))   /**< The SNS_SW_SEL_CSW_HI_MASK2 register offset */
#define CY_MSCLP_REG_OFFSET_SNS_SW_SEL_CSW_HI_MASK1   (offsetof(MSCLP_Type, SNS.SNS_SW_SEL_CSW_HI_MASK1))   /**< The SNS_SW_SEL_CSW_HI_MASK1 register offset */
#define CY_MSCLP_REG_OFFSET_SNS_SW_SEL_CSW_HI_MASK0   (offsetof(MSCLP_Type, SNS.SNS_SW_SEL_CSW_HI_MASK0))   /**< The SNS_SW_SEL_CSW_HI_MASK0 register offset */
#define CY_MSCLP_REG_OFFSET_SNS_SW_SEL_CSW_LO_MASK2   (offsetof(MSCLP_Type, SNS.SNS_SW_SEL_CSW_LO_MASK2))   /**< The SNS_SW_SEL_CSW_LO_MASK2 register offset */
#define CY_MSCLP_REG_OFFSET_SNS_SW_SEL_CSW_LO_MASK1   (offsetof(MSCLP_Type, SNS.SNS_SW_SEL_CSW_LO_MASK1))   /**< The SNS_SW_SEL_CSW_LO_MASK1 register offset */
#define CY_MSCLP_REG_OFFSET_SNS_SW_SEL_CSW_LO_MASK0   (offsetof(MSCLP_Type, SNS.SNS_SW_SEL_CSW_LO_MASK0))   /**< The SNS_SW_SEL_CSW_LO_MASK0 register offset */
#define CY_MSCLP_REG_OFFSET_SNS_SCAN_CTL              (offsetof(MSCLP_Type, SNS.SNS_SCAN_CTL))              /**< The SNS_SCAN_CTL register offset */
#define CY_MSCLP_REG_OFFSET_SNS_CDAC_CTL              (offsetof(MSCLP_Type, SNS.SNS_CDAC_CTL))              /**< The SNS_CDAC_CTL register offset */
#define CY_MSCLP_REG_OFFSET_SNS_CTL                   (offsetof(MSCLP_Type, SNS.SNS_CTL))                   /**< The SNS_CTL register offset */
#define CY_MSCLP_REG_OFFSET_RESULT_FIFO_RD            (offsetof(MSCLP_Type, SNS.RESULT_FIFO_RD))            /**< The RESULT_FIFO_RD register offset */
#define CY_MSCLP_REG_OFFSET_STATUS1                   (offsetof(MSCLP_Type, SNS.STATUS1))                   /**< The STATUS1 register offset */
#define CY_MSCLP_REG_OFFSET_STATUS2                   (offsetof(MSCLP_Type, SNS.STATUS2))                   /**< The STATUS2 register offset */
#define CY_MSCLP_REG_OFFSET_STATUS3                   (offsetof(MSCLP_Type, SNS.STATUS3))                   /**< The STATUS3 register offset */
#define CY_MSCLP_REG_OFFSET_RESULT_FIFO_STATUS        (offsetof(MSCLP_Type, SNS.RESULT_FIFO_STATUS))        /**< The RESULT_FIFO_STATUS register offset */
#define CY_MSCLP_REG_OFFSET_RESULT_FIFO_STATUS2       (offsetof(MSCLP_Type, SNS.RESULT_FIFO_STATUS2))       /**< The RESULT_FIFO_STATUS2 register offset */
#define CY_MSCLP_REG_OFFSET_CE_STATUS                 (offsetof(MSCLP_Type, SNS.CE_STATUS))                 /**< The CE_STATUS register offset */
#define CY_MSCLP_REG_OFFSET_BRIDGE_STATUS             (offsetof(MSCLP_Type, SNS.BRIDGE_STATUS))             /**< The BRIDGE_STATUS register offset */
#define CY_MSCLP_REG_OFFSET_FRAME_CMD                 (offsetof(MSCLP_Type, SNS.FRAME_CMD))                 /**< The FRAME_CMD register offset */
#define CY_MSCLP_REG_OFFSET_CE_CMD                    (offsetof(MSCLP_Type, SNS.CE_CMD))                    /**< The CE_CMD register offset */
#define CY_MSCLP_REG_OFFSET_FIFO_CMD                  (offsetof(MSCLP_Type, SNS.FIFO_CMD))                  /**< The FIFO_CMD register offset */
#define CY_MSCLP_REG_OFFSET_CE_INIT_CTL               (offsetof(MSCLP_Type, SNS.CE_INIT_CTL))               /**< The CE_INIT_CTL register offset */

#define CY_MSCLP_REG_OFFSET_TRIM_CTL                  (offsetof(MSCLP_Type, TRIM_CTL))                      /**< The TRIM_CTL register offset */
#define CY_MSCLP_REG_OFFSET_CLK_IMO_TRIM1             (offsetof(MSCLP_Type, CLK_IMO_TRIM1))                 /**< The CLK_IMO_TRIM1 register offset */
#define CY_MSCLP_REG_OFFSET_CLK_IMO_TRIM2             (offsetof(MSCLP_Type, CLK_IMO_TRIM2))                 /**< The CLK_IMO_TRIM2 register offset */
#define CY_MSCLP_REG_OFFSET_CLK_IMO_TRIM3             (offsetof(MSCLP_Type, CLK_IMO_TRIM3))                 /**< The CLK_IMO_TRIM3 register offset */
#define CY_MSCLP_REG_OFFSET_PWR_BG_TRIM1              (offsetof(MSCLP_Type, PWR_BG_TRIM1))                  /**< The PWR_BG_TRIM1 register offset */
#define CY_MSCLP_REG_OFFSET_PWR_BG_TRIM2              (offsetof(MSCLP_Type, PWR_BG_TRIM2))                  /**< The PWR_BG_TRIM2 register offset */
#define CY_MSCLP_REG_OFFSET_PWR_BG_TRIM3              (offsetof(MSCLP_Type, PWR_BG_TRIM3))                  /**< The PWR_BG_TRIM3 register offset */

#define CY_MSCLP_REG_OFFSET_SW_SEL_CSW(index)          (offsetof(MSCLP_Type, SW_SEL_CSW[(index)]))          /**< The SW_SEL_CSW[x] register offset */
#define CY_MSCLP_REG_OFFSET_SW_SEL_CSW_FUNC(index)     (offsetof(MSCLP_Type, SW_SEL_CSW_FUNC[(index)]))     /**< The SW_SEL_CSW_FUNC[x] register offset */
#define CY_MSCLP_REG_OFFSET_MODE_SENSE_DUTY_CTL(index) (offsetof(MSCLP_Type, MODE[(index)].SENSE_DUTY_CTL)) /**< The MODE[x].SENSE_DUTY_CTL register offset */
#define CY_MSCLP_REG_OFFSET_MODE_SW_SEL_CDAC_FL(index) (offsetof(MSCLP_Type, MODE[(index)].SW_SEL_CDAC_FL)) /**< The MODE[x].SW_SEL_CDAC_FL register offset */
#define CY_MSCLP_REG_OFFSET_MODE_SW_SEL_TOP(index)     (offsetof(MSCLP_Type, MODE[(index)].SW_SEL_TOP))     /**< The MODE[x].SW_SEL_TOP register offset */
#define CY_MSCLP_REG_OFFSET_MODE_SW_SEL_COMP(index)    (offsetof(MSCLP_Type, MODE[(index)].SW_SEL_COMP))    /**< The MODE[x].SW_SEL_COMP register offset */
#define CY_MSCLP_REG_OFFSET_MODE_SW_SEL_SH(index)      (offsetof(MSCLP_Type, MODE[(index)].SW_SEL_SH))      /**< The MODE[x].SW_SEL_SH register offset */
#define CY_MSCLP_REG_OFFSET_MODE_SW_SEL_CMOD1(index)   (offsetof(MSCLP_Type, MODE[(index)].SW_SEL_CMOD1))   /**< The MODE[x].SW_SEL_CMOD1 register offset */
#define CY_MSCLP_REG_OFFSET_MODE_SW_SEL_CMOD2(index)   (offsetof(MSCLP_Type, MODE[(index)].SW_SEL_CMOD2))   /**< The MODE[x].SW_SEL_CMOD2 register offset */
#define CY_MSCLP_REG_OFFSET_MODE_SW_SEL_CMOD3(index)   (offsetof(MSCLP_Type, MODE[(index)].SW_SEL_CMOD3))   /**< The MODE[x].SW_SEL_CMOD3 register offset */
#define CY_MSCLP_REG_OFFSET_MODE_SW_SEL_CMOD4(index)   (offsetof(MSCLP_Type, MODE[(index)].SW_SEL_CMOD4))   /**< The MODE[x].SW_SEL_CMOD4 register offset */

/** \} group_msclp_reg_const */

/*******************************************************************************
*        Function Prototypes
*******************************************************************************/

/**
* \addtogroup group_msclp_functions
* \{
*/

cy_en_msclp_status_t Cy_MSCLP_Init(MSCLP_Type * base, cy_stc_msclp_base_config_t const * config,
                                   cy_en_msclp_key_t key, cy_stc_msclp_context_t * context);
cy_en_msclp_status_t Cy_MSCLP_DeInit(MSCLP_Type * base, cy_en_msclp_key_t key, cy_stc_msclp_context_t * context);
cy_en_msclp_status_t Cy_MSCLP_Capture(MSCLP_Type * base, cy_en_msclp_key_t key, cy_stc_msclp_context_t * context);
cy_en_msclp_status_t Cy_MSCLP_Configure(MSCLP_Type * base, cy_stc_msclp_base_config_t const * config,
                                        cy_en_msclp_key_t key, cy_stc_msclp_context_t const * context);
cy_en_msclp_status_t Cy_MSCLP_MrssStart(MSCLP_Type * base, cy_stc_msclp_mrss_config_t const * mrssCfg,
                                         cy_en_msclp_key_t key, cy_stc_msclp_context_t const * context);
cy_en_msclp_status_t Cy_MSCLP_MrssStop(MSCLP_Type * base, cy_en_msclp_key_t key,
                                        cy_stc_msclp_context_t const * context);
cy_en_msclp_status_t Cy_MSCLP_MrssStatus(MSCLP_Type * base, cy_en_msclp_key_t key,
                                        cy_stc_msclp_context_t const * context);
void Cy_MSCLP_ConfigureScan(MSCLP_Type * base, uint32_t numRegs, uint32_t const * scanConfig);

__STATIC_INLINE cy_en_msclp_key_t Cy_MSCLP_GetLockStatus(const MSCLP_Type * base,
                                                         const cy_stc_msclp_context_t * context);
__STATIC_INLINE cy_en_msclp_status_t Cy_MSCLP_GetConversionStatus(const MSCLP_Type * base,
                                                                  const cy_stc_msclp_context_t * context);

__STATIC_INLINE uint32_t Cy_MSCLP_ReadReg(const MSCLP_Type * base, uint32_t offset);
__STATIC_INLINE void Cy_MSCLP_WriteReg(MSCLP_Type * base, uint32_t offset, uint32_t value);
__STATIC_INLINE void Cy_MSCLP_SetBits(MSCLP_Type * base, uint32_t offset, uint32_t mask);
__STATIC_INLINE void Cy_MSCLP_ClrBits(MSCLP_Type * base, uint32_t offset, uint32_t mask);
__STATIC_INLINE void Cy_MSCLP_WriteBits(MSCLP_Type* base, uint32_t offset, uint32_t mask, uint32_t value);
__STATIC_INLINE void Cy_MSCLP_SwStartFrame(MSCLP_Type * base);
__STATIC_INLINE void Cy_MSCLP_SwStartAosFrame(MSCLP_Type * base);


__STATIC_INLINE uint32_t Cy_MSCLP_ReadSensorDataWord(MSCLP_Type const * base, uint32_t addr);
void Cy_MSCLP_ReadSensorDataArray(MSCLP_Type const * base, uint32_t startAddr,
                                                  uint32_t * ptrData, uint32_t dataSize);
__STATIC_INLINE void Cy_MSCLP_WriteSensorDataWord(MSCLP_Type * base, uint32_t addr, uint32_t data);
cy_en_msclp_status_t Cy_MSCLP_WriteSensorDataArray(MSCLP_Type * base, uint32_t startAddr,
                                                   uint32_t const * ptrData, uint32_t dataSize);


/*******************************************************************************
* Function Name: Cy_MSCLP_ReadReg
****************************************************************************//**
*
* Reads value from the specified the MSCLP HW block register.
*
* \note Accessing the SNS group registers under disabled MRSS might lead to the
* device hard fault. Therefore, access the SNS group registers of the
* MSCLP HW block only under enabled MRSS. To enable, disable or check the MRSS
* power status, use the Cy_MSCLP_MrssStart(), Cy_MSCLP_MrssStop() or
* Cy_MSCLP_MrssStatus() functions respectively.
*
* \param base
* Pointer to a MSCLP HW block base address.
*
* \param offset
* Register offset relative to base address.
*
* \return
* Returns a value of the MSCLP HW block register, specified by the offset
* parameter.
*
* \funcusage \snippet msclp_snippet.c snippet_Cy_MSCLP_IntHandler
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_MSCLP_ReadReg(const MSCLP_Type * base, uint32_t offset)
{
    return (* (volatile uint32_t *)((uint32_t)base + offset));
}


/*******************************************************************************
* Function Name: Cy_MSCLP_WriteReg
****************************************************************************//**
*
* Writes a value to the specified MSCLP HW block register.
*
* \note Accessing the SNS group registers under disabled MRSS might lead to the
* device hard fault. Therefore, access the SNS group registers of the
* MSCLP HW block only under enabled MRSS. To enable, disable or check the MRSS
* power status, use the Cy_MSCLP_MrssStart(), Cy_MSCLP_MrssStop() or
* Cy_MSCLP_MrssStatus() functions respectively.
*
* \param base
* Pointer to a MSCLP HW block base address.
*
* \param offset
* Register offset relative to base address.
*
* \param value
* Value to be written to the register.
*
* \funcusage \snippet msclp_snippet.c snippet_Cy_MSCLP_IntHandler
*
*******************************************************************************/
__STATIC_INLINE void Cy_MSCLP_WriteReg(MSCLP_Type * base, uint32_t offset, uint32_t value)
{
    (* (volatile uint32_t *)((uint32_t)base + offset)) = value;
}


/*******************************************************************************
* Function Name: Cy_MSCLP_SetBits
****************************************************************************//**
*
* Sets bits, specified by the Mask parameter in the MSCLP HW block register,
* specified by the Offset parameter.
*
* \note Accessing the SNS group registers under disabled MRSS might lead to the
* device hard fault. Therefore, access the SNS group registers of the
* MSCLP HW block only under enabled MRSS. To enable, disable or check the MRSS
* power status, use the Cy_MSCLP_MrssStart(), Cy_MSCLP_MrssStop() or
* Cy_MSCLP_MrssStatus() functions respectively.
*
* \param base
* Pointer to a MSCLP HW block base address.
*
* \param offset
* Register offset relative to base address.
*
* \param mask
* Mask value for register bits to be set.
*
*******************************************************************************/
__STATIC_INLINE void Cy_MSCLP_SetBits(MSCLP_Type * base, uint32_t offset, uint32_t mask)
{
    volatile uint32_t * regPtr = (volatile uint32_t *)((uint32_t)base + offset);
    (* regPtr) |= mask;
}


/*******************************************************************************
* Function Name: Cy_MSCLP_ClrBits
****************************************************************************//**
*
* Clears bits, specified by the Mask parameter in the MSCLP HW block register,
* specified by the Offset parameter.
*
* \note Accessing the SNS group registers under disabled MRSS might lead to the
* device hard fault. Therefore, access the SNS group registers of the
* MSCLP HW block only under enabled MRSS. To enable, disable or check the MRSS
* power status, use the Cy_MSCLP_MrssStart(), Cy_MSCLP_MrssStop() or
* Cy_MSCLP_MrssStatus() functions respectively.
*
* \param base
* Pointer to a MSCLP HW block base address.
*
* \param offset
* Register offset relative to base address.
*
* \param mask
* Mask value for register bits to be cleared.
*
*******************************************************************************/
__STATIC_INLINE void Cy_MSCLP_ClrBits(MSCLP_Type * base, uint32_t offset, uint32_t mask)
{
    volatile uint32_t * regPtr = (volatile uint32_t *)((uint32_t)base + offset);
    (* regPtr) &= ~mask;
}


/*******************************************************************************
* Function Name: Cy_MSCLP_WriteBits
****************************************************************************//**
*
* Writes field, specified by the Mask parameter with the value, specified by
* the Value parameter.
*
* \note Accessing the SNS group registers under disabled MRSS might lead to the
* device hard fault. Therefore, access the SNS group registers of the
* MSCLP HW block only under enabled MRSS. To enable, disable or check the MRSS
* power status, use the Cy_MSCLP_MrssStart(), Cy_MSCLP_MrssStop() or
* Cy_MSCLP_MrssStatus() functions respectively.
*
* \param base
* Pointer to a MSCLP HW block base address.
*
* \param offset
* Register offset relative to base address.
*
* \param mask
* Specifies bits to be modified.
*
* \param value
* Specifies a value to be written to the register.
*
*******************************************************************************/
__STATIC_INLINE void Cy_MSCLP_WriteBits(MSCLP_Type * base, uint32_t offset, uint32_t mask, uint32_t value)
{
    volatile uint32_t * regPtr = (volatile uint32_t *)((uint32_t)base + offset);
    (* regPtr) = ((* regPtr) & ~mask) | (value & mask);
}


/*******************************************************************************
* Function Name: Cy_MSCLP_GetLockStatus
****************************************************************************//**
*
* Verifies whether the specified MSCLP HW block is acquired and locked by a
* higher-level firmware.
*
* \param base
* Pointer to a MSCLP HW block base address.
*
* \param context
* The pointer to the context structure allocated by a user or middleware.
*
* \return
* Returns a key code. See \ref cy_en_msclp_key_t.
*
* \funcusage
*
* \snippet msclp_snippet.c snippet_Cy_MSCLP_CheckKey
*
*******************************************************************************/
__STATIC_INLINE cy_en_msclp_key_t Cy_MSCLP_GetLockStatus(const MSCLP_Type * base, const cy_stc_msclp_context_t * context)
{
    (void)base;
    return (context->lockKey);
}


/*******************************************************************************
* Function Name: Cy_MSCLP_GetConversionStatus
****************************************************************************//**
*
* Verifies whether the specified MSCLP HW block is busy
* (performing scan or conversion).
*
* \note Accessing the SNS group registers under disabled MRSS might lead to the
* device hard fault. Therefore, access the SNS group registers of the
* MSCLP HW block only under enabled MRSS. To enable, disable or check the MRSS
* power status, use the Cy_MSCLP_MrssStart(), Cy_MSCLP_MrssStop() or
* Cy_MSCLP_MrssStatus() functions respectively.
*
* \param base
* Pointer to a MSCLP HW block base address.
*
* \param context
* The pointer to the context structure allocated by a user or middleware.
*
* \return
* Returns status code. See \ref cy_en_msclp_status_t.
*
* \funcusage
*
* \snippet msclp_snippet.c snippet_Cy_MSCLP_CheckStatus
*
*******************************************************************************/
__STATIC_INLINE cy_en_msclp_status_t Cy_MSCLP_GetConversionStatus(const MSCLP_Type * base, const cy_stc_msclp_context_t * context)
{
    cy_en_msclp_status_t msclpStatus = CY_MSCLP_BUSY;

    (void)context;

    if (((base->SNS.SNS_CTL & MSCLP_SNS_SNS_CTL_START_SCAN_Msk) == 0uL) && ((base->SNS.STATUS3 & MSCLP_SNS_STATUS3_SEQ_STATE_Msk) == 0uL))
    {
        msclpStatus = CY_MSCLP_SUCCESS;
    }

    return msclpStatus;
}


/*******************************************************************************
* Function Name: Cy_MSCLP_SwStartFrame
****************************************************************************//**
*
* The function initiates the non-blocking scan of an entire configured
* frame by launch the MSCLP HW block state machine.
*
* The function requires the following things to be done ahead 
* the function call:
* * the MRSS is enabled
* * MSCLP is configured to AS-MS mode and clearly defines a frame 
*   location inside MSCLP Sensor Data RAM
* * Sensor Data RAM is updated with the sensors frame configuration.
*
* The MSCLP HW block takes the first sensor configuration from 
* Sensor Data RAM and executes the scan. After scan is complete, 
* the next sensor configuration is taken (without MCU involvement) 
* and the scan is executes. It happens till the scan of the last sensor 
* of a frame is complete. Then MSCLP state machine goes to the idle state.
*
* \note Accessing the SNS group registers under disabled MRSS might lead to the
* device hard fault. Therefore, access the SNS group registers of the
* MSCLP HW block only under enabled MRSS. To enable, disable or check the MRSS
* power status, use the Cy_MSCLP_MrssStart(), Cy_MSCLP_MrssStop() or
* Cy_MSCLP_MrssStatus() functions respectively.
*
* \param base
* The pointer to the MSCLP HW block base address.
*
*******************************************************************************/
__STATIC_INLINE void Cy_MSCLP_SwStartFrame(MSCLP_Type * base)
{
    base->SNS.FRAME_CMD = MSCLP_SNS_FRAME_CMD_START_FRAME_Msk;
}


/*******************************************************************************
* Function Name: Cy_MSCLP_SwStartAosFrame
****************************************************************************//**
*
* The function initiates the non-blocking scan of an entire configured
* frame by launch the MSCLP HW block state machine.
*
* The function requires the following things to be done ahead 
* the function call:
* * MSCLP is configured to LP-AOS mode and clearly defines a frame 
*   location inside MSCLP Sensor Data RAM
* * Sensor Data RAM is updated with the sensors frame configuration.
*
* The MSCLP HW block launches internal timer. After timeout the block
* takes the first sensor configuration from Sensor Data RAM and 
* executes the scan. After scan is complete, the next sensor configuration 
* is taken (without MCU involvement) and the scan is executes. 
* It happens till the scan of the last sensor in a frame is complete. 
* Then the MSCLP state machine goes to the idle state if number 
* of frame scans is configured to one. Otherwise frame is scanned 
* the configured number of times with configured timeout.
*
* \note Accessing the SNS group registers under disabled MRSS might lead to the
* device hard fault. Therefore, access the SNS group registers of the
* MSCLP HW block only under enabled MRSS. To enable, disable or check the MRSS
* power status, use the Cy_MSCLP_MrssStart(), Cy_MSCLP_MrssStop() or
* Cy_MSCLP_MrssStatus() functions respectively.
*
* \param base
* The pointer to the MSCLP HW block base address.
*
*******************************************************************************/
__STATIC_INLINE void Cy_MSCLP_SwStartAosFrame(MSCLP_Type * base)
{
    base->WAKEUP_CMD = MSCLP_WAKEUP_CMD_START_FRAME_AOS_Msk;
}


/*******************************************************************************
* Function Name: Cy_MSCLP_WriteSensorDataWord
****************************************************************************//**
*
* Writes one 32-bit data word into the SNS.SENSOR_DATA memory.
*
* \note Accessing the SNS group registers under disabled MRSS might lead to the
* device hard fault. Therefore, access the SNS group registers of the
* MSCLP HW block only under enabled MRSS. To enable, disable or check the MRSS
* power status, use the Cy_MSCLP_MrssStart(), Cy_MSCLP_MrssStop() or
* Cy_MSCLP_MrssStatus() functions respectively.
*
* \param base
* Pointer to a MSCLP HW block base address.
*
* \param addr
* The address (index of the 32-bit word) in the SNS.SENSOR_DATA.
*
* \param data
* The 32-bit data word value.
*
*******************************************************************************/
__STATIC_INLINE void Cy_MSCLP_WriteSensorDataWord(MSCLP_Type * base, uint32_t addr, uint32_t data)
{
    base->SNS.SENSOR_DATA[addr] = data;
}


/*******************************************************************************
* Function Name: Cy_MSCLP_ReadSensorDataWord
****************************************************************************//**
*
* Reads one 32-bit data word from the SNS.SENSOR_DATA memory.
*
* \note Accessing the SNS group registers under disabled MRSS might lead to the
* device hard fault. Therefore, access the SNS group registers of the
* MSCLP HW block only under enabled MRSS. To enable, disable or check the MRSS
* power status, use the Cy_MSCLP_MrssStart(), Cy_MSCLP_MrssStop() or
* Cy_MSCLP_MrssStatus() functions respectively.
*
* \param base
* Pointer to a MSCLP HW block base address.
*
* \param addr
* The address (index of the 32-bit word) in the SNS.SENSOR_DATA.
*
* \return The 32-bit data word value.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_MSCLP_ReadSensorDataWord(MSCLP_Type const * base, uint32_t addr)
{
    return (base->SNS.SENSOR_DATA[addr]);
}

/** \} group_msclp_functions */

#if defined(__cplusplus)
}
#endif

#endif /* CY_IP_M0S8MSCV3LP */

#endif /* CY_MSCLP_H */


/* [] END OF FILE */
