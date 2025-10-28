/***************************************************************************//**
* \file cy_msc.h
* \version 1.10.2
*
* The header file of the MSC driver.
*
********************************************************************************
* \copyright
* (c) (2020-2022), Cypress Semiconductor Corporation (an Infineon company) or
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

/**
* \addtogroup group_msc
*/

/**
********************************************************************************
* \addtogroup group_msc
********************************************************************************
* \{
*
* The MSC HW block represents the devices of the fifth CAPSENSE&trade; generation.
* It enables multiple sensing capabilities on PSOC&trade; devices,
* including self-cap and mutual-cap capacitive touch-sense solutions.
*
* The CAPSENSE&trade; solution includes:
* * The CAPSENSE&trade; Configurator tool, which is a configuration wizard to create
*   and configure CAPSENSE&trade; widgets. It can be launched in ModusToolbox&trade;
*   from the MSC personality as well as in standalone mode.
*   It contains separate documentation on how to create and
*   configure widgets, parameters, and algorithm descriptions.
* * An API to control the design from the application program. This
*   documentation describes the API with code snippets about how to use them.
* * The CAPSENSE&trade; Tuner tool for real-time tuning, testing, and debugging,
*   for easy and smooth design of human interfaces on customer products.
*   The Tuner tool communicates with a device through a HW bridge and
*   communication drivers (EzI2C, UART, etc.) and allows monitoring of
*   widget statuses, sensor signals, detected touch positions, gestures, etc.
* The application program does not need to interact with the MSC driver
* and/or other drivers such as GPIO or SysClk directly. All of that is
* configured and managed by the middleware.
*
* \image html capsense_solution_msc.png "CAPSENSE&trade; Solution" width=800px
* \image latex capsense_solution_msc.png
*
* This section describes only the MSC driver. Refer to the corresponding
* sections for documentation of middleware supported by the MSC HW block.
*
* The MSC driver is a low-level peripheral driver that provides an interface to
* a complex mixed signal of the MSC HW block.
*
* The MSC driver alone does not provide system-level functions. Instead, it is
* used by upper-level middleware to configure the MSC HW block required by
* an application.
*
* The MSC HW block can support only one function at a time. To allow seamless
* time-multiplex implementation of functionality and to avoid conflicting access
* to hardware from the upper level, the MSC driver also implements a lock
* semaphore mechanism.
*
* The MSC driver supports re-entrance. If a device contains several
* MSC HW blocks, the same MSC driver is used to configure any HW block. For
* that, each function of the MSC driver contains a base address to define
* the MSC HW block to which the MSC driver communicates.
*
* There is no restriction on the MSC Driver usage in RTOS.
*
********************************************************************************
* \section group_msc_config_usage Usage
********************************************************************************
*
* The MSC driver is a simple wrapper driver specifically designed to be used
* by higher level middleware. Hence, is highly not recommended to use the MSC
* driver directly in the application program. To incorporate MSC HW block
* functionality in the application program, an associated middleware
* should be used.
*
* The MSC Driver can be used to implement a custom sensing solution. In such
* a case, the application program must acquire and lock the MSC HW block prior
* to accessing it.
*
* Setting up and using the MSC driver can be summed up in these four stages:
* * Define configuration in the config structure.
* * Allocate context structure variable for the driver.
* * Capture the MSC HW block.
* * Execute the action required to perform any kind of conversion.
*
* The following code snippet demonstrates how to capture the MSC HW block for
* custom implementation:
*
* \snippet msc_snippet.c snippet_Cy_MSC_Conversion
*
* \note
* User's application code should follow these recommendations:
* 1. The last sensor configuration in the frame should have the LAST bit of
*    SNS_CTL register set.
* 2. The START_FRAME bit of FRAME_CMD register should be set prior to calling
*    the Cy_MSC_ConfigureScan() API. It should be set once per frame if the
*    frame contains multiple sensor configurations, and each frame if the
*    frame contains only one sensor configuration.
* 3. The START_SCAN bit of SNS_CTL register should be set in the sensor frame
*    to start the conversion.
*
* The entire solution, like CAPSENSE&trade;, in addition to
* the MSC HW block, incorporates the following instances:
*
* * \ref group_msc_config_clocks
* * \ref group_msc_config_interrupts
* * \ref group_msc_config_pin
*
* The MSC driver does not configure those blocks and they should be managed by
* an upper level. When using CAPSENSE&trade;, those blocks are managed by the
* middleware.
*
********************************************************************************
* \subsection group_msc_config_clocks Clocks
********************************************************************************
*
* The MSC HW block requires a peripheral clock (clk_peri) input. It can be
* assigned using two methods:
* * Using the Device Configurator (Peripheral-Clocks tab).
* * Using the SysClk (System Clock) driver. Refer to \ref group_sysclk driver
*   section for more details.
* If middleware is used, the clock is managed by middleware.
*
********************************************************************************
* \subsection group_msc_config_pin GPIO Pins
********************************************************************************
*
* CAPSENSE&trade; provides the ability to form a user interface using widgets. Each
* widget consists of one or more sensors. These sensors are connected to the
* GPIO pins.
*
* The MSC HW block supports two types of the connection GPIO pin-to-block:
*
* 1. Through analog buses.
*
* This is a legacy connection through an analog multiplexed bus (AMUXBUS)
* available in previous generations of CAPSENSE&trade; devices.
*
* Any analog-capable GPIO pin that can be connected to an analog multiplexed
* bus (AMUXBUS) can be connected to the MSC HW block as an input / sensor.
*
* A GPIO input can be assigned to the MSC HW block using the following methods:
* * Using the Device Configurator (Pins tab).
* * Using the GPIO (General Purpose Input Output) driver. Refer
*   to the \ref group_gpio driver section.
*
* If middleware is used, pin configuration is managed by the middleware.
* Under the MSC driver custom implementation, the application program must
* manage the pin connections.
*
* Each AMUXBUS can be split into multiple segments. Ensure that the MSC HW block
* and a GPIO belong to the same bus segment or join the segments to establish
* the connection GPIO-to-MSC HW block.
*
* For more information about pin configuration, refer to the \ref group_gpio
* driver.
*
* 2. With a direct pin-to-block wire.
*
* The enhanced direct HW-wire connection pin-to-MSC HW block is
* available in the devices of the fifth generation CAPSENSE&trade;.
*
* Only dedicated pins can be used for such a type of connection. Refer to
* the device datasheet for the exact pin definition.
*
* A GPIO input can be assigned to the MSC HW block only by proper configuration
* of the MSC HW block.
* If middleware is used, pin configuration is managed by the middleware.
*
* Under the MSC driver custom implementation, the application
* program must manage the pin connections.
* * Configure a pin to High-Z analog mode without any connection to analog buses.
* * Configure the pin connection inside the MSC HW block.
*
* The advantages of this type of a connection under the CAPSENSE&trade; MW usage are
* the following:
* * CAPSENSE&trade; MW pre-calculates all needed configurations in advance (during
*   initialization)
* * CAPSENSE&trade; MW triggers the next scanning by writing to several registers
*   of the MSC HW block (instead of disconnecting a previously scanned sensor
*   and connecting a new sensor).
* If in your case, the scanning refresh rate is as an important characteristic,
* use the second connection type.
*
********************************************************************************
* \subsection group_msc_config_interrupts Interrupts
********************************************************************************
*
* The MSC HW block has one interrupt. The MSC HW block can generate interrupts
* on the following events:
*
* * End of scan: scanning of a single sensor is complete.
* * End of frame: scanning of a whole set of sensors (frame) is complete.
*
* Additionally, the MSC interrupt can wake the device from the Sleep power mode.
* The MSC HW block is powered down in the Deep Sleep power mode.
* So, it cannot be used as a wake-up source in this power mode.
*
* If a CAPSENSE&trade; is used, the interrupt service routine is managed
* by middleware. When using the MSC driver for custom implementation or other
* middleware, the application program must manage the interrupt service routine.
*
* Implement an interrupt routine and assign it to the MSC interrupt. Use the
* pre-defined enumeration as the interrupt source of the MSC HW block.
* The MSC interrupt to the NVIC is raised any time the intersection
* (logic AND) of the interrupt flags and the corresponding interrupt
* masks are non-zero. The peripheral interrupt status register should be
* read in the ISR to detect which condition generated the interrupt.
* The appropriate interrupt registers should be cleared so that
* subsequent interrupts can be handled.
*
* The following code snippet demonstrates how to implement a routine to handle
* the interrupt. The routine is called when a MSC interrupt is triggered.
*
* \snippet msc_snippet.c snippet_Cy_MSC_IntHandler
*
* The following code snippet demonstrates how to configure and enable
* the MSC interrupt:
*
* \snippet msc_snippet.c snippet_Cy_MSC_IntEnabling
*
* For more information, refer to the \ref group_sysint driver.
*
* Alternatively, instead of handling the interrupts, the
* \ref Cy_MSC_GetConversionStatus() function allows for firmware
* polling of the MSC block status.
*
********************************************************************************
* \section group_msc_config_power_modes Power Modes
********************************************************************************
*
* The MSC HW block can operate in Active and Sleep CPU power modes. It is also
* possible to switch between Low power and Ultra Low power system modes.
* In Deep Sleep power mode, the MSC HW block is powered off.
* When the device wakes up from Deep Sleep, the MSC HW block resumes operation
* without the need for re-initialization.
*
* \note
* 1. The MSC driver does not provide a callback function to facilitate the
*    low-power mode transitions. The responsibility belongs to an upper
*    level that uses the MSC HW block to ensure the MSC HW block is not
*    busy prior to a power mode transition.
* 2. A power mode transition is not recommended while the MSC HW block is busy.
*    The MSC HW block status must be checked using the Cy_MSC_GetStatus()
*    function prior to a power mode transition. Instead, use the same power mode
*    for active operation of the MSC HW block. This restriction is not
*    applicable to Sleep mode and the device can seamlessly enter and exit
*    Sleep mode while the MSC HW block is busy.
*
* \warning
* 1. Do not enter Deep Sleep power mode if the MSC HW block conversion is in
*    progress. Unexpected behavior may occur.
* 2. The MSC HW block initializes in several microseconds after
*    Power on / Deep Sleep exit. Refer to the technical
*    reference manual (TRM) and the device datasheet for the exact number.
*
* Refer to the \ref group_syspm driver for more information about
* low-power mode transitions.
*
********************************************************************************
* \section group_msc_more_information More Information
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
*   * <a href="https://www.infineon.com/cms/en/product/evaluation-boards/cy8ckit-041s-max/">
*     <b>CY8CKIT-041S-MAX PSOC&trade; 4100S Max pioneer kit</b></a>
*
* * General Information:
*
*   * <a href="https://infineon.github.io/mtb-pdl-cat2/pdl_api_reference_manual/html/index.html">
*     <b>PDL API Reference</b></a>
*
*   * <a href="https://www.infineon.com/dgdl/Infineon-PSoC_4100S_and_PSoC_4100S_Plus_PSoC_4_Architecture_TRM-AdditionalTechnicalInformation-v12_00-EN.pdf?fileId=8ac78c8c7d0d8da4017d0f9433460188">
*     <b>PSOC&trade; 4100S and PSOC&trade; 4100S Plus: PSOC&trade; 4 Architecture Technical Reference Manual (TRM)</b></a>
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
* \section group_msc_changelog Changelog
********************************************************************************
* <table class="doxtable">
*   <tr><th>Version</th><th>Changes</th><th>Reason for Change</th></tr>
*   <tr>
*     <td>1.10.2</td>
*     <td>Minor documentation updates</td>
*     <td>Documentation improvement</td>
*   </tr>
*   <tr>
*     <td>1.10.1</td>
*     <td>Update the paths to the code snippets</td>
*     <td>PDL structure update</td>
*   </tr>
*   <tr>
*     <td>1.10</td>
*     <td>Added Cy_MSC_Capture() function</td>
*     <td>CAPSENSE&trade; memory consumption optimization</td>
*   </tr>
*   <tr>
*     <td>1.0</td>
*     <td>The initial version</td>
*     <td></td>
*   </tr>
* </table>
*/

/** \} group_msc */

/**
********************************************************************************
* \addtogroup group_msc
********************************************************************************
* \{
* \defgroup group_msc_macros                Macros
* \defgroup group_msc_functions             Functions
* \defgroup group_msc_data_structures       Data Structures
* \defgroup group_msc_enums                 Enumerated Types
*/


#if !defined(CY_MSC_H)
#define CY_MSC_H

#include <stdint.h>
#include <stddef.h>
#include "cy_device_headers.h"
#include "cy_syslib.h"

#if defined(CY_IP_M0S8MSCV3)

#if defined(__cplusplus)
extern "C" {
#endif

/**
* \addtogroup group_msc_macros
* \{
*/

/** Driver major version */
#define CY_MSC_DRV_VERSION_MAJOR            (1)

/** Driver minor version */
#define CY_MSC_DRV_VERSION_MINOR            (10)

/** Driver version */
#define CY_MSC_DRV2_VERSION                 (110)

/** Macro to support the backward compatibility. Do not use for new designs. */
#define CY_MSC_DRV_VERSION                  (100)

/******************************************************************************
* API Constants
******************************************************************************/

/** MSC driver identifier */
#define CY_MSC_ID                           (CY_PDL_DRV_ID(0x47u))

/** Initialization macro for the driver context variable */
#define CY_MSC_CONTEXT_INIT_VALUE           {.lockKey = CY_MSC_NONE_KEY}

/** One hundred percentage */
#define CY_MSC_PERCENTAGE_100               (100u)
/** 8-bit shift */
#define CY_MSC_8_BIT_SHIFT                  (8u)
/** The lowest 8-bit mask */
#define CY_MSC_LSB_MASK                     (0x000000FFu)
/** Maximum number of mode configurations */
#define CY_MSC_MODES_NUM                    (4u)
/** Maximum number of SW_SEL_CSW registers */
#define CY_MSC_CSW_NUM                      (32u)
/** Maximum number of SW_SEL_CSW_FUNC registers */
#define CY_MSC_CSW_FUNC_NUM                 (8u)
/** Maximum number of registers in sensor frame with support up to 8 pin states */
#define CY_MSC_6_SNS_REGS                   (6u)
/** Maximum number of registers in sensor frame with support up to 4 pin states */
#define CY_MSC_5_SNS_REGS                   (5u)

/*******************************************************************************
* The MSC HW Block Registers Constants
*******************************************************************************/

/**
* \defgroup group_msc_reg_const Registers Constants
* \{
*/

/** \} group_msc_reg_const */

/** \} group_msc_macros */


/*******************************************************************************
 * Enumerations
 ******************************************************************************/

/**
* \addtogroup group_msc_enums
* \{
*/

/** MSC status definitions */
typedef enum
{
    /** Successful */
    CY_MSC_SUCCESS = 0x00u,

    /** One or more invalid parameters */
    CY_MSC_BAD_PARAM = CY_MSC_ID | CY_PDL_STATUS_ERROR | 0x01u,

    /** The MSC HW block performs conversion */
    CY_MSC_BUSY =  CY_MSC_ID | CY_PDL_STATUS_ERROR | 0x02u,

    /** The MSC HW block is captured by another middleware */
    CY_MSC_LOCKED =  CY_MSC_ID | CY_PDL_STATUS_ERROR | 0x03u

} cy_en_msc_status_t;


/**
* Definitions of upper level keys that use the driver.
*
* Each middleware has a unique key assigned. When middleware successfully
* captures the MSC HW block, this key is placed into the MSC driver context
* structure. All attempts to capture the MSC HW block by other middleware
* are rejected. When the first middleware releases the MSC HW block,
* CY_MSC_NONE_KEY is written to the lockKey variable of the MSC driver context
* structure and any other middleware can capture the MSC HW block.
*/
typedef enum
{
    /** The MSC HW block is unused and not captured by any middleware */
    CY_MSC_NONE_KEY = 0u,

    /**
    * The MSC HW block is captured by the application program
    * directly to implement a customer's specific case
    */
    CY_MSC_USER_DEFINED_KEY = 1u,

    /** The MSC HW block is captured by a CAPSENSE middleware */
    CY_MSC_CAPSENSE_KEY = 2u,

}cy_en_msc_key_t;

/** \} group_msc_enums */


/*******************************************************************************
*       Type Definitions
*******************************************************************************/

/**
* \addtogroup group_msc_data_structures
* \{
*/

/**
* MSC driver scan configuration structure.
* This structure consolidates scan registers of the MSC HW block.
*/
typedef struct
{
    uint32_t snsSwSelCswMask2;          /**< Stores the MSC.SNS_SW_SEL_CSW_MASK2 register value */
    uint32_t snsSwSelCswMask1;          /**< Stores the MSC.SNS_SW_SEL_CSW_MASK1 register value */
    uint32_t snsSwSelCswMask0;          /**< Stores the MSC.SNS_SW_SEL_CSW_MASK0 register value */
    uint32_t snsScanCtl;                /**< Stores the MSC.SNS_SCAN_CTL register value */
    uint32_t snsCdacCtl;                /**< Stores the MSC.SNS_CDAC_CTL register value */
    uint32_t snsCtl;                    /**< Stores the MSC.SNS_CTL register value */
} cy_stc_msc_sensor_config_t;

/**
* MSC driver sense modes structure.
* This structure consolidates sense mode registers of the MSC HW block.
*/
typedef struct
{
    uint32_t senseDutyCtl;              /**< Stores the MSC.SENSE_DUTY_CTL register value */
    uint32_t swSelCdacFl;               /**< Stores the MSC.SW_SEL_CDAC_FL register value */
    uint32_t swSelTop;                  /**< Stores the MSC.SW_SEL_TOP register value */
    uint32_t swSelComp;                 /**< Stores the MSC.SW_SEL_COMP register value */
    uint32_t swSelSh;                   /**< Stores the MSC.SW_SEL_SH register value */
} cy_stc_msc_mode_config_t;

/**
* MSC configuration structure.
*
* This structure contains all register values of the MSC HW block. This
* structure is provided by middleware through the Cy_MSC_Init() and
* Cy_MSC_Configure() functions to implement the MSC HW block supported
* sensing modes like self-cap / mutual-cap scanning, etc.
*/
typedef struct
{
    uint32_t ctl;                                       /**< Stores the MSC.CTL register value */
    uint32_t spare;                                     /**< Stores the MSC.SPARE register value */
    uint32_t scanCtl1;                                  /**< Stores the MSC.SCAN_CTL1 register value */
    uint32_t scanCtl2;                                  /**< Stores the MSC.SCAN_CTL2 register value */
    uint32_t initCtl1;                                  /**< Stores the MSC.INIT_CTL1 register value */
    uint32_t initCtl2;                                  /**< Stores the MSC.INIT_CTL2 register value */
    uint32_t initCtl3;                                  /**< Stores the MSC.INIT_CTL3 register value */
    uint32_t initCtl4;                                  /**< Stores the MSC.INIT_CTL4 register value */
    uint32_t senseDutyCtl;                              /**< Stores the MSC.SENSE_DUTY_CTL register value */
    uint32_t sensePeriodCtl;                            /**< Stores the MSC.SENSE_PERIOD_CTL register value */
    uint32_t filterCtl;                                 /**< Stores the MSC.FILTER_CTL register value */
    uint32_t ccompCdacCtl;                              /**< Stores the MSC.CCOMP_CDAC_CTL register value */
    uint32_t ditherCdacCtl;                             /**< Stores the MSC.DITHER_CDAC_CTL register value */
    uint32_t cswCtl;                                    /**< Stores the MSC.CSW_CTL register value */
    uint32_t swSelGpio;                                 /**< Stores the MSC.SW_SEL_GPIO register value */
    uint32_t swSelCdacRe;                               /**< Stores the MSC.SW_SEL_CDAC_RE register value */
    uint32_t swSelCdacCo;                               /**< Stores the MSC.SW_SEL_CDAC_CO register value */
    uint32_t swSelCdacCf;                               /**< Stores the MSC.SW_SEL_CDAC_CF register value */
    uint32_t swSelCmod1;                                /**< Stores the MSC.SW_SEL_CMOD1 register value */
    uint32_t swSelCmod2;                                /**< Stores the MSC.SW_SEL_CMOD2 register value */
    uint32_t swSelCmod3;                                /**< Stores the MSC.SW_SEL_CMOD3 register value */
    uint32_t swSelCmod4;                                /**< Stores the MSC.SW_SEL_CMOD4 register value */
    uint32_t obsCtl;                                    /**< Stores the MSC.OBS_CTL register value */
    uint32_t status1;                                   /**< Stores the MSC.STATUS1 register value */
    uint32_t status2;                                   /**< Stores the MSC.STATUS2 register value */
    uint32_t status3;                                   /**< Stores the MSC.STATUS3 register value */
    uint32_t resultFifoStatus;                          /**< Stores the MSC.RESULT_FIFO_STATUS register value */
    uint32_t resultFifoRd;                              /**< Stores the MSC.RESULT_FIFO_RD register value */
    uint32_t intr;                                      /**< Stores the MSC.INTR register value */
    uint32_t intrSet;                                   /**< Stores the MSC.INTR_SET register value */
    uint32_t intrMask;                                  /**< Stores the MSC.INTR_MASK register value */
    uint32_t intrMasked;                                /**< Stores the MSC.INTR_MASKED register value */
    uint32_t frameCmd;                                  /**< Stores the MSC.FRAME_CMD register value */
    cy_stc_msc_sensor_config_t sensorConfig;            /**< Stores the MSC.SNS registers values */
    uint32_t swSelCsw[CY_MSC_CSW_NUM];                  /**< Stores the MSC.SW_SEL_CSW registers values */
    uint32_t swSelCswFunc[CY_MSC_CSW_FUNC_NUM];         /**< Stores the MSC.SW_SEL_CSW_FUNC registers values */
    cy_stc_msc_mode_config_t mode[CY_MSC_MODES_NUM];    /**< Stores the MSC.MODE registers values */
} cy_stc_msc_base_config_t;

/**
* MSC driver context structure.
* This structure is an internal structure of the MSC driver and should not be
* accessed directly by the application program.
*/
typedef struct
{
    /** Middleware ID that currently captured MSC */
    cy_en_msc_key_t lockKey;
} cy_stc_msc_context_t;

/** \} group_msc_data_structures */

/**
* \addtogroup group_msc_reg_const
* \{
*/

/** The register offset */
#define CY_MSC_REG_OFFSET_CTL                       (offsetof(MSC_Type, CTL))
/** The register offset */
#define CY_MSC_REG_OFFSET_SPARE                     (offsetof(MSC_Type, SPARE))
/** The register offset */
#define CY_MSC_REG_OFFSET_SCAN_CTL1                 (offsetof(MSC_Type, SCAN_CTL1))
/** The register offset */
#define CY_MSC_REG_OFFSET_SCAN_CTL2                 (offsetof(MSC_Type, SCAN_CTL2))
/** The register offset */
#define CY_MSC_REG_OFFSET_INIT_CTL1                 (offsetof(MSC_Type, INIT_CTL1))
/** The register offset */
#define CY_MSC_REG_OFFSET_INIT_CTL2                 (offsetof(MSC_Type, INIT_CTL2))
/** The register offset */
#define CY_MSC_REG_OFFSET_INIT_CTL3                 (offsetof(MSC_Type, INIT_CTL3))
/** The register offset */
#define CY_MSC_REG_OFFSET_INIT_CTL4                 (offsetof(MSC_Type, INIT_CTL4))
/** The register offset */
#define CY_MSC_REG_OFFSET_SENSE_DUTY_CTL            (offsetof(MSC_Type, SENSE_DUTY_CTL))
/** The register offset */
#define CY_MSC_REG_OFFSET_SENSE_PERIOD_CTL          (offsetof(MSC_Type, SENSE_PERIOD_CTL))
/** The register offset */
#define CY_MSC_REG_OFFSET_FILTER_CTL                (offsetof(MSC_Type, FILTER_CTL))
/** The register offset */
#define CY_MSC_REG_OFFSET_CCOMP_CDAC_CTL            (offsetof(MSC_Type, CCOMP_CDAC_CTL))
/** The register offset */
#define CY_MSC_REG_OFFSET_DITHER_CDAC_CTL           (offsetof(MSC_Type, DITHER_CDAC_CTL))
/** The register offset */
#define CY_MSC_REG_OFFSET_CSW_CTL                   (offsetof(MSC_Type, CSW_CTL))
/** The register offset */
#define CY_MSC_REG_OFFSET_SW_SEL_GPIO               (offsetof(MSC_Type, SW_SEL_GPIO))
/** The register offset */
#define CY_MSC_REG_OFFSET_SW_SEL_CDAC_RE            (offsetof(MSC_Type, SW_SEL_CDAC_RE))
/** The register offset */
#define CY_MSC_REG_OFFSET_SW_SEL_CDAC_CO            (offsetof(MSC_Type, SW_SEL_CDAC_CO))
/** The register offset */
#define CY_MSC_REG_OFFSET_SW_SEL_CDAC_CF            (offsetof(MSC_Type, SW_SEL_CDAC_CF))
/** The register offset */
#define CY_MSC_REG_OFFSET_SW_SEL_CMOD1              (offsetof(MSC_Type, SW_SEL_CMOD1))
/** The register offset */
#define CY_MSC_REG_OFFSET_SW_SEL_CMOD2              (offsetof(MSC_Type, SW_SEL_CMOD2))
/** The register offset */
#define CY_MSC_REG_OFFSET_SW_SEL_CMOD3              (offsetof(MSC_Type, SW_SEL_CMOD3))
/** The register offset */
#define CY_MSC_REG_OFFSET_SW_SEL_CMOD4              (offsetof(MSC_Type, SW_SEL_CMOD4))
/** The register offset */
#define CY_MSC_REG_OFFSET_OBS_CTL                   (offsetof(MSC_Type, OBS_CTL))
/** The register offset */
#define CY_MSC_REG_OFFSET_WAKEUP_CTL                (offsetof(MSC_Type, WAKEUP_CTL))
/** The register offset */
#define CY_MSC_REG_OFFSET_LP_AOC_CTL                (offsetof(MSC_Type, LP_AOC_CTL))
/** The register offset */
#define CY_MSC_REG_OFFSET_STATUS1                   (offsetof(MSC_Type, STATUS1))
/** The register offset */
#define CY_MSC_REG_OFFSET_STATUS2                   (offsetof(MSC_Type, STATUS2))
/** The register offset */
#define CY_MSC_REG_OFFSET_STATUS3                   (offsetof(MSC_Type, STATUS3))
/** The register offset */
#define CY_MSC_REG_OFFSET_RESULT_FIFO_STATUS        (offsetof(MSC_Type, RESULT_FIFO_STATUS))
/** The register offset */
#define CY_MSC_REG_OFFSET_RESULT_FIFO_RD            (offsetof(MSC_Type, RESULT_FIFO_RD))
/** The register offset */
#define CY_MSC_REG_OFFSET_INTR                      (offsetof(MSC_Type, INTR))
/** The register offset */
#define CY_MSC_REG_OFFSET_INTR_SET                  (offsetof(MSC_Type, INTR_SET))
/** The register offset */
#define CY_MSC_REG_OFFSET_INTR_MASK                 (offsetof(MSC_Type, INTR_MASK))
/** The register offset */
#define CY_MSC_REG_OFFSET_INTR_MASKED               (offsetof(MSC_Type, INTR_MASKED))
/** The register offset */
#define CY_MSC_REG_OFFSET_INTR_LP                   (offsetof(MSC_Type, INTR_LP))
/** The register offset */
#define CY_MSC_REG_OFFSET_INTR_LP_SET               (offsetof(MSC_Type, INTR_LP_SET))
/** The register offset */
#define CY_MSC_REG_OFFSET_INTR_LP_MASK              (offsetof(MSC_Type, INTR_LP_MASK))
/** The register offset */
#define CY_MSC_REG_OFFSET_INTR_LP_MASKED            (offsetof(MSC_Type, INTR_LP_MASKED))
/** The register offset */
#define CY_MSC_REG_OFFSET_FRAME_CMD                 (offsetof(MSC_Type, FRAME_CMD))
/** The register offset */
#define CY_MSC_REG_OFFSET_WAKEUP_CMD                (offsetof(MSC_Type, WAKEUP_CMD))
/** The register offset */
#define CY_MSC_REG_OFFSET_SNS_STRUCT_CTL            (offsetof(MSC_Type, SNS_STRUCT_CTL))
/** The register offset */
#define CY_MSC_REG_OFFSET_SNS_LP_AOC_SENSOR_CTL1    (offsetof(MSC_Type, SNS_LP_AOC_SENSOR_CTL1))
/** The register offset */
#define CY_MSC_REG_OFFSET_SNS_LP_AOC_SENSOR_CTL2    (offsetof(MSC_Type, SNS_LP_AOC_SENSOR_CTL2))
/** The register offset */
#define CY_MSC_REG_OFFSET_SNS_SW_SEL_CSW_MASK2      (offsetof(MSC_Type, SNS_SW_SEL_CSW_MASK2))
/** The register offset */
#define CY_MSC_REG_OFFSET_SNS_SW_SEL_CSW_MASK1      (offsetof(MSC_Type, SNS_SW_SEL_CSW_MASK1))
/** The register offset */
#define CY_MSC_REG_OFFSET_SNS_SW_SEL_CSW_MASK0      (offsetof(MSC_Type, SNS_SW_SEL_CSW_MASK0))
/** The register offset */
#define CY_MSC_REG_OFFSET_SNS_SCAN_CTL              (offsetof(MSC_Type, SNS_SCAN_CTL))
/** The register offset */
#define CY_MSC_REG_OFFSET_SNS_CDAC_CTL              (offsetof(MSC_Type, SNS_CDAC_CTL))
/** The register offset */
#define CY_MSC_REG_OFFSET_SNS_CTL                   (offsetof(MSC_Type, SNS_CTL))
/** The register offset */
#define CY_MSC_REG_OFFSET_SW_SEL_CSW0               (offsetof(MSC_Type, SW_SEL_CSW[0]))
/** The register offset */
#define CY_MSC_REG_OFFSET_SW_SEL_CSW1               (offsetof(MSC_Type, SW_SEL_CSW[1]))
/** The register offset */
#define CY_MSC_REG_OFFSET_SW_SEL_CSW2               (offsetof(MSC_Type, SW_SEL_CSW[2]))
/** The register offset */
#define CY_MSC_REG_OFFSET_SW_SEL_CSW3               (offsetof(MSC_Type, SW_SEL_CSW[3]))
/** The register offset */
#define CY_MSC_REG_OFFSET_SW_SEL_CSW4               (offsetof(MSC_Type, SW_SEL_CSW[4]))
/** The register offset */
#define CY_MSC_REG_OFFSET_SW_SEL_CSW5               (offsetof(MSC_Type, SW_SEL_CSW[5]))
/** The register offset */
#define CY_MSC_REG_OFFSET_SW_SEL_CSW6               (offsetof(MSC_Type, SW_SEL_CSW[6]))
/** The register offset */
#define CY_MSC_REG_OFFSET_SW_SEL_CSW7               (offsetof(MSC_Type, SW_SEL_CSW[7]))
/** The register offset */
#define CY_MSC_REG_OFFSET_SW_SEL_CSW8               (offsetof(MSC_Type, SW_SEL_CSW[8]))
/** The register offset */
#define CY_MSC_REG_OFFSET_SW_SEL_CSW9               (offsetof(MSC_Type, SW_SEL_CSW[9]))
/** The register offset */
#define CY_MSC_REG_OFFSET_SW_SEL_CSW10              (offsetof(MSC_Type, SW_SEL_CSW[10]))
/** The register offset */
#define CY_MSC_REG_OFFSET_SW_SEL_CSW11              (offsetof(MSC_Type, SW_SEL_CSW[11]))
/** The register offset */
#define CY_MSC_REG_OFFSET_SW_SEL_CSW12              (offsetof(MSC_Type, SW_SEL_CSW[12]))
/** The register offset */
#define CY_MSC_REG_OFFSET_SW_SEL_CSW13              (offsetof(MSC_Type, SW_SEL_CSW[13]))
/** The register offset */
#define CY_MSC_REG_OFFSET_SW_SEL_CSW14              (offsetof(MSC_Type, SW_SEL_CSW[14]))
/** The register offset */
#define CY_MSC_REG_OFFSET_SW_SEL_CSW15              (offsetof(MSC_Type, SW_SEL_CSW[15]))
/** The register offset */
#define CY_MSC_REG_OFFSET_SW_SEL_CSW16              (offsetof(MSC_Type, SW_SEL_CSW[16]))
/** The register offset */
#define CY_MSC_REG_OFFSET_SW_SEL_CSW17              (offsetof(MSC_Type, SW_SEL_CSW[17]))
/** The register offset */
#define CY_MSC_REG_OFFSET_SW_SEL_CSW18              (offsetof(MSC_Type, SW_SEL_CSW[18]))
/** The register offset */
#define CY_MSC_REG_OFFSET_SW_SEL_CSW19              (offsetof(MSC_Type, SW_SEL_CSW[19]))
/** The register offset */
#define CY_MSC_REG_OFFSET_SW_SEL_CSW20              (offsetof(MSC_Type, SW_SEL_CSW[20]))
/** The register offset */
#define CY_MSC_REG_OFFSET_SW_SEL_CSW21              (offsetof(MSC_Type, SW_SEL_CSW[21]))
/** The register offset */
#define CY_MSC_REG_OFFSET_SW_SEL_CSW22              (offsetof(MSC_Type, SW_SEL_CSW[22]))
/** The register offset */
#define CY_MSC_REG_OFFSET_SW_SEL_CSW23              (offsetof(MSC_Type, SW_SEL_CSW[23]))
/** The register offset */
#define CY_MSC_REG_OFFSET_SW_SEL_CSW24              (offsetof(MSC_Type, SW_SEL_CSW[24]))
/** The register offset */
#define CY_MSC_REG_OFFSET_SW_SEL_CSW25              (offsetof(MSC_Type, SW_SEL_CSW[25]))
/** The register offset */
#define CY_MSC_REG_OFFSET_SW_SEL_CSW26              (offsetof(MSC_Type, SW_SEL_CSW[26]))
/** The register offset */
#define CY_MSC_REG_OFFSET_SW_SEL_CSW27              (offsetof(MSC_Type, SW_SEL_CSW[27]))
/** The register offset */
#define CY_MSC_REG_OFFSET_SW_SEL_CSW28              (offsetof(MSC_Type, SW_SEL_CSW[28]))
/** The register offset */
#define CY_MSC_REG_OFFSET_SW_SEL_CSW29              (offsetof(MSC_Type, SW_SEL_CSW[29]))
/** The register offset */
#define CY_MSC_REG_OFFSET_SW_SEL_CSW30              (offsetof(MSC_Type, SW_SEL_CSW[30]))
/** The register offset */
#define CY_MSC_REG_OFFSET_SW_SEL_CSW31              (offsetof(MSC_Type, SW_SEL_CSW[31]))
/** The register offset */
#define CY_MSC_REG_OFFSET_SW_SEL_CSW_FUNC0          (offsetof(MSC_Type, SW_SEL_CSW_FUNC[0]))
/** The register offset */
#define CY_MSC_REG_OFFSET_SW_SEL_CSW_FUNC1          (offsetof(MSC_Type, SW_SEL_CSW_FUNC[1]))
/** The register offset */
#define CY_MSC_REG_OFFSET_SW_SEL_CSW_FUNC2          (offsetof(MSC_Type, SW_SEL_CSW_FUNC[2]))
/** The register offset */
#define CY_MSC_REG_OFFSET_SW_SEL_CSW_FUNC3          (offsetof(MSC_Type, SW_SEL_CSW_FUNC[3]))
/** The register offset */
#define CY_MSC_REG_OFFSET_SW_SEL_CSW_FUNC4          (offsetof(MSC_Type, SW_SEL_CSW_FUNC[4]))
/** The register offset */
#define CY_MSC_REG_OFFSET_SW_SEL_CSW_FUNC5          (offsetof(MSC_Type, SW_SEL_CSW_FUNC[5]))
/** The register offset */
#define CY_MSC_REG_OFFSET_SW_SEL_CSW_FUNC6          (offsetof(MSC_Type, SW_SEL_CSW_FUNC[6]))
/** The register offset */
#define CY_MSC_REG_OFFSET_SW_SEL_CSW_FUNC7          (offsetof(MSC_Type, SW_SEL_CSW_FUNC[7]))
/** The register offset */
#define CY_MSC_REG_OFFSET_MODE0_SENSE_DUTY_CTL      (offsetof(MSC_Type, MODE[0].SENSE_DUTY_CTL))
/** The register offset */
#define CY_MSC_REG_OFFSET_MODE0_SW_SEL_CDAC_FL      (offsetof(MSC_Type, MODE[0].SW_SEL_CDAC_FL))
/** The register offset */
#define CY_MSC_REG_OFFSET_MODE0_SW_SEL_TOP          (offsetof(MSC_Type, MODE[0].SW_SEL_TOP))
/** The register offset */
#define CY_MSC_REG_OFFSET_MODE0_SW_SEL_COMP         (offsetof(MSC_Type, MODE[0].SW_SEL_COMP))
/** The register offset */
#define CY_MSC_REG_OFFSET_MODE0_SW_SEL_SH           (offsetof(MSC_Type, MODE[0].SW_SEL_SH))
/** The register offset */
#define CY_MSC_REG_OFFSET_MODE1_SENSE_DUTY_CTL      (offsetof(MSC_Type, MODE[1].SENSE_DUTY_CTL))
/** The register offset */
#define CY_MSC_REG_OFFSET_MODE1_SW_SEL_CDAC_FL      (offsetof(MSC_Type, MODE[1].SW_SEL_CDAC_FL))
/** The register offset */
#define CY_MSC_REG_OFFSET_MODE1_SW_SEL_TOP          (offsetof(MSC_Type, MODE[1].SW_SEL_TOP))
/** The register offset */
#define CY_MSC_REG_OFFSET_MODE1_SW_SEL_COMP         (offsetof(MSC_Type, MODE[1].SW_SEL_COMP))
/** The register offset */
#define CY_MSC_REG_OFFSET_MODE1_SW_SEL_SH           (offsetof(MSC_Type, MODE[1].SW_SEL_SH))
/** The register offset */
#define CY_MSC_REG_OFFSET_MODE2_SENSE_DUTY_CTL      (offsetof(MSC_Type, MODE[2].SENSE_DUTY_CTL))
/** The register offset */
#define CY_MSC_REG_OFFSET_MODE2_SW_SEL_CDAC_FL      (offsetof(MSC_Type, MODE[2].SW_SEL_CDAC_FL))
/** The register offset */
#define CY_MSC_REG_OFFSET_MODE2_SW_SEL_TOP          (offsetof(MSC_Type, MODE[2].SW_SEL_TOP))
/** The register offset */
#define CY_MSC_REG_OFFSET_MODE2_SW_SEL_COMP         (offsetof(MSC_Type, MODE[2].SW_SEL_COMP))
/** The register offset */
#define CY_MSC_REG_OFFSET_MODE2_SW_SEL_SH           (offsetof(MSC_Type, MODE[2].SW_SEL_SH))
/** The register offset */
#define CY_MSC_REG_OFFSET_MODE3_SENSE_DUTY_CTL      (offsetof(MSC_Type, MODE[3].SENSE_DUTY_CTL))
/** The register offset */
#define CY_MSC_REG_OFFSET_MODE3_SW_SEL_CDAC_FL      (offsetof(MSC_Type, MODE[3].SW_SEL_CDAC_FL))
/** The register offset */
#define CY_MSC_REG_OFFSET_MODE3_SW_SEL_TOP          (offsetof(MSC_Type, MODE[3].SW_SEL_TOP))
/** The register offset */
#define CY_MSC_REG_OFFSET_MODE3_SW_SEL_COMP         (offsetof(MSC_Type, MODE[3].SW_SEL_COMP))
/** The register offset */
#define CY_MSC_REG_OFFSET_MODE3_SW_SEL_SH           (offsetof(MSC_Type, MODE[3].SW_SEL_SH))
/** The register offset */
#define CY_MSC_REG_OFFSET_TRIM_CTL                  (offsetof(MSC_Type, TRIM_CTL))

/** The register offset */
#define CY_MSC_REG_OFFSET_SW_SEL_CSW(index)                 (offsetof(MSC_Type, SW_SEL_CSW[(index)]))
/** The register offset */
#define CY_MSC_REG_OFFSET_SW_SEL_CSW_FUNC(index)            (offsetof(MSC_Type, SW_SEL_CSW_FUNC[(index)]))
/** The register offset */
#define CY_MSC_REG_OFFSET_MODE_SENSE_DUTY_CTL(index)        (offsetof(MSC_Type, MODE[(index)].SENSE_DUTY_CTL))
/** The register offset */
#define CY_MSC_REG_OFFSET_MODE_SW_SEL_CDAC_FL(index)        (offsetof(MSC_Type, MODE[(index)].SW_SEL_CDAC_FL))
/** The register offset */
#define CY_MSC_REG_OFFSET_MODE_SW_SEL_TOP(index)            (offsetof(MSC_Type, MODE[(index)].SW_SEL_TOP))
/** The register offset */
#define CY_MSC_REG_OFFSET_MODE_SW_SEL_COMP(index)           (offsetof(MSC_Type, MODE[(index)].SW_SEL_COMP))
/** The register offset */
#define CY_MSC_REG_OFFSET_MODE_SW_SEL_SH(index)             (offsetof(MSC_Type, MODE[(index)].SW_SEL_SH))

/** \} group_msc_reg_const */

/*******************************************************************************
*        Function Prototypes
*******************************************************************************/

/**
* \addtogroup group_msc_functions
* \{
*/

cy_en_msc_status_t Cy_MSC_Init(MSC_Type * base, cy_stc_msc_base_config_t const * config, cy_en_msc_key_t key, cy_stc_msc_context_t * context);
cy_en_msc_status_t Cy_MSC_DeInit(const MSC_Type * base, cy_en_msc_key_t key, cy_stc_msc_context_t * context);
cy_en_msc_status_t Cy_MSC_Capture(MSC_Type * base, cy_en_msc_key_t key, cy_stc_msc_context_t * context);
cy_en_msc_status_t Cy_MSC_Configure(MSC_Type * base, const cy_stc_msc_base_config_t * config, cy_en_msc_key_t key, const cy_stc_msc_context_t * context);
void Cy_MSC_ConfigureScan(MSC_Type * base, uint32_t numRegs, const uint32_t * scanConfig);

__STATIC_INLINE cy_en_msc_key_t Cy_MSC_GetLockStatus(const MSC_Type * base, const cy_stc_msc_context_t * context);
__STATIC_INLINE cy_en_msc_status_t Cy_MSC_GetConversionStatus(const MSC_Type * base, const cy_stc_msc_context_t * context);

__STATIC_INLINE uint32_t Cy_MSC_ReadReg(const MSC_Type * base, uint32_t offset);
__STATIC_INLINE void Cy_MSC_WriteReg(MSC_Type * base, uint32_t offset, uint32_t value);
__STATIC_INLINE void Cy_MSC_SetBits(MSC_Type * base, uint32_t offset, uint32_t mask);
__STATIC_INLINE void Cy_MSC_ClrBits(MSC_Type * base, uint32_t offset, uint32_t mask);
__STATIC_INLINE void Cy_MSC_WriteBits(MSC_Type* base, uint32_t offset, uint32_t mask, uint32_t value);

/*******************************************************************************
* Function Name: Cy_MSC_ReadReg
****************************************************************************//**
*
* Reads value from the specified the MSC HW block register.
*
* \param base
* Pointer to a MSC HW block base address.
*
* \param offset
* Register offset relative to base address.
*
* \return
* Returns a value of the MSC HW block register, specified by the offset
* parameter.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_MSC_ReadReg(const MSC_Type * base, uint32_t offset)
{
    return(* (volatile uint32_t *)((uint32_t)base + offset));
}


/*******************************************************************************
* Function Name: Cy_MSC_WriteReg
****************************************************************************//**
*
* Writes a value to the specified MSC HW block register.
*
* \param base
* Pointer to a MSC HW block base address.
*
* \param offset
* Register offset relative to base address.
*
* \param value
* Value to be written to the register.
*
*******************************************************************************/
__STATIC_INLINE void Cy_MSC_WriteReg(MSC_Type * base, uint32_t offset, uint32_t value)
{
    (* (volatile uint32_t *)((uint32_t)base + offset)) = value;
}


/*******************************************************************************
* Function Name: Cy_MSC_SetBits
****************************************************************************//**
*
* Sets bits, specified by the Mask parameter in the MSC HW block register,
* specified by the Offset parameter.
*
* \param base
* Pointer to a MSC HW block base address.
*
* \param offset
* Register offset relative to base address.
*
* \param mask
* Mask value for register bits to be set.
*
*******************************************************************************/
__STATIC_INLINE void Cy_MSC_SetBits(MSC_Type * base, uint32_t offset, uint32_t mask)
{
    volatile uint32_t * regPtr = (volatile uint32_t *)((uint32_t)base + offset);
    (* regPtr) |= mask;
}


/*******************************************************************************
* Function Name: Cy_MSC_ClrBits
****************************************************************************//**
*
* Clears bits, specified by the Mask parameter in the MSC HW block register,
* specified by the Offset parameter.
*
* \param base
* Pointer to a MSC HW block base address.
*
* \param offset
* Register offset relative to base address.
*
* \param mask
* Mask value for register bits to be cleared.
*
*******************************************************************************/
__STATIC_INLINE void Cy_MSC_ClrBits(MSC_Type * base, uint32_t offset, uint32_t mask)
{
    volatile uint32_t * regPtr = (volatile uint32_t *)((uint32_t)base + offset);
    (* regPtr) &= ~mask;
}


/*******************************************************************************
* Function Name: Cy_MSC_WriteBits
****************************************************************************//**
*
* Writes field, specified by the Mask parameter with the value, specified by
* the Value parameter.
*
* \param base
* Pointer to a MSC HW block base address.
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
__STATIC_INLINE void Cy_MSC_WriteBits(MSC_Type * base, uint32_t offset, uint32_t mask, uint32_t value)
{
    volatile uint32_t * regPtr = (volatile uint32_t *)((uint32_t)base + offset);
    (* regPtr) = ((* regPtr) & ~mask) | (value & mask);
}


/*******************************************************************************
* Function Name: Cy_MSC_GetLockStatus
****************************************************************************//**
*
* Verifies whether the specified MSC HW block is acquired and locked by a
* higher-level firmware.
*
* \param base
* Pointer to a MSC HW block base address.
*
* \param context
* The pointer to the context structure allocated by a user or middleware.
*
* \return
* Returns a key code. See \ref cy_en_msc_key_t.
*
* \funcusage
*
* \snippet msc_snippet.c snippet_Cy_MSC_CheckKey
*
*******************************************************************************/
__STATIC_INLINE cy_en_msc_key_t Cy_MSC_GetLockStatus(const MSC_Type * base, const cy_stc_msc_context_t * context)
{
    (void)base;
    return(context->lockKey);
}


/*******************************************************************************
* Function Name: Cy_MSC_GetConversionStatus
****************************************************************************//**
*
* Verifies whether the specified MSC HW block is busy
* (performing scan or conversion).
*
* \param base
* Pointer to a MSC HW block base address.
*
* \param context
* The pointer to the context structure allocated by a user or middleware.
*
* \return
* Returns status code. See \ref cy_en_msc_status_t.
*
* \funcusage
*
* \snippet msc_snippet.c snippet_Cy_MSC_CheckStatus
*
*******************************************************************************/
__STATIC_INLINE cy_en_msc_status_t Cy_MSC_GetConversionStatus(const MSC_Type * base, const cy_stc_msc_context_t * context)
{
    cy_en_msc_status_t mscStatus = CY_MSC_BUSY;

    (void)context;
    if (((base->SNS_CTL & MSC_SNS_CTL_START_SCAN_Msk) == 0u) && ((base->STATUS3 & MSC_STATUS3_SEQ_STATE_Msk) == 0u))
    {
        mscStatus = CY_MSC_SUCCESS;
    }

    return(mscStatus);
}
/** \} group_msc_functions */

/** \} group_msc */

#if defined(__cplusplus)
}
#endif

#endif /* CY_IP_M0S8MSCV3 */

#endif /* CY_MSC_H */


/* [] END OF FILE */
