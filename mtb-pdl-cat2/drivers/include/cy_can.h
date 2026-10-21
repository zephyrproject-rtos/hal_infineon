/***************************************************************************//**
* \file cy_can.h
* \version 1.0
*
* This file provides constants and parameter values for
* the CAN driver.
*
********************************************************************************
* \copyright
* (c) (2025), Cypress Semiconductor Corporation (an Infineon company) or
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
* \addtogroup group_can
* \{
* The CAN driver provides an easy method to access the CAN IP block registers
* and provides simple functionality for sending and receiving data between
* devices in the CAN network.
* The CAN driver provides an API to configure the main features - bit time,
* message buffers - and transmit and receive the CAN message.
* The CAN driver is not compatible with CAN FD or future versions.
*
* \image html can_solution.png "CAN Solution" width=948px
* \image latex can_solution.png
*
*
* \section group_can_section_configuration Configuration Considerations
* Specification of the sample code is as follows:
*   - Configurable CAN clock
*   - Configurable CAN Bit rate
*   - Rx buffer configuration
*   - H/W feature configuration such as test mode and byte endianness 
*   - Interrupts : \n
*                  CY_CAN_TRANSMISSION_COMPLETE (Message sent from Tx buffer) \n
*                  CY_CAN_RX_BUFFER_NEW_MESSAGE (Message stored to Rx buffer). \n
*
* Sends data of ID:0x200 periodically in the main().
* Echobacks received data by incrementing the ID of the received packet in
* the receiving interrupt.(Cy_CAN_IrqHandler() --- CanCallbackRx())
*
* \subsection group_can_section_configuration_personalities Use ModusToolbox Device Configurator Tool to generate initialization code
* The steps to generate initialization code using
* the ModusToolbox Device Configurator Tool:
*
* 1. Launch the ModusToolbox Device Configurator Tool.
* 2. Switch to the Peripherals tab. Enable the CAN channel personality
*    under Communication and enter Alias (default is can_0).
* 3. Go to the Parameters Pane for the CAN Personality and configure it with
*    the desired parameters (set the Clock Signal divider, set the bit timing
*    configuration, set the other parameters per Configuration Considerations, etc).
* 4. Perform File->Save for the initialization code to generate.
*
* Now, all required CAN initialization code and configuration prerequisites will be generated:
*
* - The Peripheral Clock Divider assignment and analog routing are parts of the
*   init_cycfg_all() routine. Place the call of the init_cycfg_all() function
*   before using any CAN API functions to ensure initialization of all external
*   resources required for the CAN operation.
* - The CAN configuration structure declaration is in the cycfg_peripherals.h
*   file and its initialization is in the cycfg_peripherals.c file. The variable
*   name is \<CAN_Alias_Name\>_config (default is can_0_config). It must be used
*   with \ref Cy_CAN_Init() function.
* - Tx Buffers are not initialized. They are set when you send a message.
*
* For the CAN interrupt service routine, \ref Cy_CAN_IrqHandler() can be used.
* It handles reading data from Rx buffers.
* Corresponding callback functions are called for error interrupts, Rx
* interrupts and Tx complete interrupt. Put the names of callback functions to
* the Callback functions parameters section. Put NULL if no callback function to
* be used.
* \note Only Tx and Rx interrupt sources are enabled by default.
* Use \ref Cy_CAN_SetInterruptMask() to enable other interrupt sources.
* \note Interrupt flags are set regardless of the interrupt enable register.
* Cy_CAN_IrqHandler will check and process all supported interrupts when
* triggered with any enabled interrupt source.
*
* \snippet can_snippet.c snippet_Cy_CAN_ISR
*
* Set up the interrupt handler to be called with CAN events. The following code
* shows how to set up the interrupt handler:
* \snippet can_snippet.c snippet_Cy_CAN_Setup_CAN_Interrupt
*
* \subsection group_can_section_configuration_manual Implement the initialization code manually
* Call Cy_CAN_Init() to initialize the CAN module.
* It initializes the CAN module with the configuration parameters, passed
* in the \ref cy_stc_can_config_t structure. It consists of several elements
* to be defined first.
* \snippet can_snippet.c snippet_Cy_CAN_Config_Struct
* The Cy_CAN_Init() function also initializes the shared context structure
* used later with other API functions.
* \snippet can_snippet.c snippet_Cy_CAN_context
* Although the callback functions are optional, they are recommended for use,
* otherwise, there is no report to the API about any error and transmission or reception events.
* The example callback function sends received data back to the bus,
* incrementing ID by 1:
* \snippet can_snippet.c snippet_Cy_CAN_RX_callback
* The CAN block uses the Port 4 or 6 pins for receive (P4[0],P6[1]) and transmit (P4[1],P6[2]).
* - Connect the specified High-Speed Input Output Multiplexer (HSIOM) selection
* to the pin.
* - Set the pins drive mode for RX and TX.
*
* \snippet can_snippet.c snippet_Cy_CAN_Assign_CAN_Pins
*
* For the CAN interrupt service routine, the Cy_CAN_IrqHandler() can be used.
* It handles reading data from Rx buffers.
* Corresponding callback functions are called for error interrupts, Rx
* interrupts and Tx complete interrupt.
* \note Only Tx and Rx interrupt sources are enabled by default.
* Use \ref Cy_CAN_SetInterruptMask() to enable other interrupt sources.
* \note Interrupt flags are set regardless of the interrupt enable register.
* Cy_CAN_IrqHandler will check and process all supported interrupts when
* triggered with any enabled interrupt source.
*
* \snippet can_snippet.c snippet_Cy_CAN_ISR
*
* Setup the interrupt handler to be called with the CAN events. The following code
* shows how to set up the interrupt handler:
* \snippet can_snippet.c snippet_Cy_CAN_Setup_CAN_Interrupt
*
* The CAN has a bit rate setting. It consists of a pre-scaler, time segment 1,
* time segment 2 and synchronization jump width.
* \note The actual interpretation by the hardware of configured values is
* one more value than programmed.
*
* The CAN time quantum (tq) may be programmed in the range of 1 to 32768 CAN clock
* periods: tq = (prescaler + 1) * Tsys, where Tsys is \ref group_sysclk_clk_sys clock period.
* The length of the bit time is (programmed values)
* [timeSegment1 + timeSegment2 + 3] tq.
* The example below shows the configuration with the 250 kbps bit rate.
* This assumes the SYSCLK frequency of 48 MHz for the CAN block.
* \snippet can_snippet.c snippet_Cy_CAN_Bitrate
* CAN driver provides API to setup Message ID filtering. One filter can be set
* for one Rx buffer. The desired count of the filters(buffers) is specified
* in the \ref cy_stc_can_config_t structure and is set once during
* block initialization. It is possible to change the configured
* filter setting with \ref Cy_CAN_UpdateRxBufferConfig().
* \snippet can_snippet.c snippet_Cy_CAN_RxBuffer
* The cy_stc_can_config_t structure is used to pass all configuration to
* Cy_CAN_Init() function. It is populated with pointers to other structures
* required and constants, defined before.
* \snippet can_snippet.c snippet_Cy_CAN_Config_Struct
* The Cy_CAN_Init() function initializes the CAN block by writing CAN
* configuration registers. Cy_CAN_Init() enables the Rx interrupts for
* new message reception into the Rx buffers. Cy_CAN_Init() also enables
* the Tx interrupts for the Tx buffers successful transmission.
* The code example also shows the test mode configuration which can be used to
* enable the internal loopback mode. See \ref cy_en_can_test_mode_t for details.
* Cy_CAN_Init() sets test mode configuration to CY_CAN_TEST_MODE_DISABLE.
* Remember to disable the echo functionality in the Rx callback when using a loopback.
* \snippet can_snippet.c snippet_Cy_CAN_Init_Example
* To send a CAN message, a message structure must be prepared
* which consists of the CAN ID , data and data length.
* \snippet can_snippet.c snippet_Cy_CAN_Prepare_TX
* To transmit CAN messages, the function \ref Cy_CAN_Transmit() is used.
* The buffer status can be retrieved by \ref Cy_CAN_GetTxBufferStatus().
* It is possible to set a callback function which will be notified whenever a
* message transmission has been completed.
* \snippet can_snippet.c snippet_Cy_CAN_Send_TX
*
* \section group_can_section_more_information More Information
*
* For more information on the CAN peripheral, refer to the technical
* reference manual (TRM).
*
* \section group_can_changelog Changelog
* <table class="doxtable">
*   <tr><th>Version</th><th>Changes</th><th>Reason for Change</th></tr>
*   <tr>
*     <td>1.0</td>
*     <td>Initial version</td>
*     <td></td>
*   </tr>
* </table>
*
* \defgroup group_can_macros Macros
* \{
*   \defgroup group_can_rx_interrupt_masks RX Interrupt masks
*   \defgroup group_can_tx_interrupt_masks TX Interrupt masks
*   \defgroup group_can_error_interrupt_masks Error Interrupt masks
*   \defgroup group_can_global_interrupt_masks Global Interrupt masks
*   \defgroup group_can_error_capture_masks Error Capture Register (ECR) masks
* \}
* \defgroup group_can_functions Functions
* \defgroup group_can_data_structures Data Structures
* \defgroup group_can_enums Enumerated Types
*
*/

#if !defined(CY_CAN_H)
#define CY_CAN_H

#include <stddef.h>
#include "cy_syslib.h"
#include "cy_device_headers.h"

#ifdef CY_IP_M0S8CAN

#if defined(__cplusplus)
extern "C" {
#endif

/** \addtogroup group_can_macros
* \{
* This section describes the CAN Macros.
* These Macros can be used to check the interrupt and status flags.
* Detailed information about the macros is available in each macro description.
*/

/** Driver major version */
#define CY_CAN_DRV_VERSION_MAJOR        1U

/** Driver minor version */
#define CY_CAN_DRV_VERSION_MINOR        0U

/** CAN driver ID */
#define CY_CAN_ID                       CY_PDL_DRV_ID(0x51U)

/******************************************************************************
* API Constants
******************************************************************************/

/** \} group_can_macros */


/**
* \addtogroup group_can_rx_interrupt_masks
* \{ This section contains interrupt bit masks to be used with:
*  - Cy_CAN_GetInterruptStatus()
*  - Cy_CAN_ClearInterrupt()
*  - Cy_CAN_GetInterruptMask()
*  - Cy_CAN_SetInterruptMask()
*/
#define CY_CAN_RX_BUFFER_NEW_MESSAGE            (CAN_INT_STATUS_RX_MSG_Msk)     /**< Indicates that a message was received */
#define CY_CAN_RTR_REPLY_COMPLETE               (CAN_INT_STATUS_RTR_MSG_Msk)    /**< RTR auto-reply message sent */

/** \} group_can_rx_interrupt_masks */


/**
* \addtogroup group_can_tx_interrupt_masks
* \{ This section contains interrupt bit masks to use with:
*  - Cy_CAN_GetInterruptStatus()
*  - Cy_CAN_ClearInterrupt()
*  - Cy_CAN_GetInterruptMask()
*  - Cy_CAN_SetInterruptMask()
*/
#define CY_CAN_TRANSMISSION_COMPLETE            (CAN_INT_STATUS_TX_MSG_Msk)     /**< Indicates that a message was sent */

/** \} group_can_tx_interrupt_masks */


/**
* \addtogroup group_can_error_interrupt_masks
* \{ This section contains interrupt bit masks to be used with:
*  - Cy_CAN_GetInterruptStatus()
*  - Cy_CAN_ClearInterrupt()
*  - Cy_CAN_GetInterruptMask()
*  - Cy_CAN_SetInterruptMask()
*/
#define CY_CAN_ARBITRATION_LOST                 (CAN_INT_STATUS_ARB_LOSS_Msk)       /**< The arbitration was lost */
#define CY_CAN_OVERLOAD_FRAME_RECEIVED          (CAN_INT_STATUS_OVR_LOAD_Msk)       /**< An overload frame was received */
#define CY_CAN_BIT_ERROR_OCCURRED               (CAN_INT_STATUS_BIT_ERR_Msk)        /**< A bit error was detected */
#define CY_CAN_STUFF_ERROR_OCCURRED             (CAN_INT_STATUS_STUFF_ERR_Msk)      /**< A bit stuffing error was detected */
#define CY_CAN_ACK_ERROR_OCCURRED               (CAN_INT_STATUS_ACK_ERR_Msk)        /**< An acknowledge error was detected */
#define CY_CAN_FORM_ERROR_OCCURRED              (CAN_INT_STATUS_FORM_ERR_Msk)       /**< A format error was detected */
#define CY_CAN_CRC_ERROR_OCCURRED               (CAN_INT_STATUS_CRC_ERR_Msk)        /**< A CRC error was detected */
#define CY_CAN_BUS_OFF_STATUS                   (CAN_INT_STATUS_BUS_OFF_Msk)        /**< The CAN has reached the bus off state */
#define CY_CAN_RX_MESSAGE_LOSS                  (CAN_INT_STATUS_RX_MSG_LOSS_Msk)    /**< The new message is discarded */
#define CY_CAN_STUCK_AT_DOMINANT                (CAN_INT_STATUS_STUCK_AT_0_Msk)     /**< Stuck at dominant error */
#define CY_CAN_SINGLE_SHOT_FAILURE              (CAN_INT_STATUS_SST_FAILURE_Msk)    /**< Single shot transmission failure */

/** \} group_can_error_interrupt_masks */


/**
* \addtogroup group_can_global_interrupt_masks
* \{ This section contains interrupt bit masks to be used with:
*  - Cy_CAN_GetInterruptMask()
*  - Cy_CAN_SetInterruptMask()
*/
#define CY_CAN_GLOBAL_INTR_SWITCH               (CAN_INT_EBL_GLOBAL_INT_ENBL_Msk)  /**< Global interrupt enable flag */

/** \} group_can_global_interrupt_masks */


/**
* \addtogroup group_can_error_capture_masks
* \{ Masks and bit positions of the Error Capture Register (ECR) fields
*/
#define CY_CAN_ECR_STATUS_POS       (CAN_ECR_ECR_STATUS_Pos)    /**< ECR status position */
#define CY_CAN_ECR_STATUS_MSK       (CAN_ECR_ECR_STATUS_Msk)    /**< ECR status bit mask */
#define CY_CAN_ECR_ERROR_TYPE_POS   (CAN_ECR_ERROR_TYPE_Pos)    /**< Error type position */
#define CY_CAN_ECR_ERROR_TYPE_MSK   (CAN_ECR_ERROR_TYPE_Msk)    /**< Error type bit mask */
#define CY_CAN_ECR_RX_MODE_POS      (CAN_ECR_RX_MODE_Pos)       /**< Rx mode position */
#define CY_CAN_ECR_RX_MODE_MSK      (CAN_ECR_RX_MODE_Msk)       /**< Rx mode bit mask */
#define CY_CAN_ECR_TX_MODE_POS      (CAN_ECR_TX_MODE_Pos)       /**< Tx mode position */
#define CY_CAN_ECR_TX_MODE_MSK      (CAN_ECR_TX_MODE_Msk)       /**< Tx mode bit mask */
#define CY_CAN_ECR_BIT_POS          (CAN_ECR_BIT_Pos)           /**< BIT position */
#define CY_CAN_ECR_BIT_MSK          (CAN_ECR_BIT_Msk)           /**< BIT bit mask */
#define CY_CAN_ECR_FIELD_POS        (CAN_ECR_FIELD_Pos)         /**< Field position */
#define CY_CAN_ECR_FIELD_MSK        (CAN_ECR_FIELD_Msk)         /**< Field bit mask */

/** \} group_can_error_capture_masks */


/** \cond INTERNAL */
/* INTERNAL_MACROS */

/** The number loops to make the timeout */
#define CY_CAN_RETRY_COUNT                      (1000UL)

/** The delay timeout in usec when stopping the controller */
#define CY_CAN_STOP_TIMEOUT_US                  (1U)

/** The delay timeout in usec when starting the controller */
#define CY_CAN_START_TIMEOUT_US                 (1U)

/** The number of max message data length in byte */
#define CY_CAN_MAX_DATA_LENGTH                  (8U)

/** The number of Rx buffers */
#define CY_CAN_MESSAGE_RX_BUFFERS_MAX_CNT       (16U)

/** The number of Tx buffers */
#define CY_CAN_MESSAGE_TX_BUFFERS_MAX_CNT       (8U)

/** Is the Rx buffer index within the valid range */
#define CY_CAN_IS_MESSAGE_RX_BUFFER_IDX_VALID(idx)  ((CY_CAN_MESSAGE_RX_BUFFERS_MAX_CNT) > (idx))

/** Is the Tx buffer index within the valid range */
#define CY_CAN_IS_MESSAGE_TX_BUFFER_IDX_VALID(idx)  ((CY_CAN_MESSAGE_TX_BUFFERS_MAX_CNT) > (idx))

/** The bit offset to Tx buffers of buffer status */
#define CY_CAN_BUFFER_STATUS_TX_OFFSET          (16U)

/** \endcond */

/***************************************
*       Enumerations
***************************************/

/**
* \addtogroup group_can_enums
* \{
*/

/** CAN status enumeration */
typedef enum
{
    CY_CAN_SUCCESS       = 0x00U,                                   /**< Returned successful */
    CY_CAN_BAD_PARAM     = CY_CAN_ID | CY_PDL_STATUS_ERROR | 0x01u, /**< Bad parameter was passed */
    CY_CAN_ERROR_TIMEOUT = CY_CAN_ID | CY_PDL_STATUS_ERROR | 0x02u, /**< A Time out error occurred */
    CY_CAN_NOT_STARTED   = CY_CAN_ID | CY_PDL_STATUS_ERROR | 0x03u, /**< CAN controller is not started */    
    CY_CAN_BUSY          = CY_CAN_ID | CY_PDL_STATUS_ERROR | 0x04u, /**< Tx Buffer is being sent */
} cy_en_can_status_t;

/** Type for indication of the received frame (Remote Transmission Request) */
typedef enum
{
    CY_CAN_RTR_DATA_FRAME               = 0x00u, /**< The received frame is a data frame */
    CY_CAN_RTR_REMOTE_FRAME             = 0x01u  /**< The received frame is a remote frame */
} cy_en_can_rtr_t;

/** IDE format type (whether the received frame has a standard or extended identifier) */
typedef enum
{
    CY_CAN_IDE_STANDARD_ID              = 0x00u, /**< The 11-bit standard identifier */
    CY_CAN_IDE_EXTENDED_ID              = 0x01u  /**< The 29-bit extended identifier */
} cy_en_can_ide_t;

/** CAN Rx Buffer status enumeration */
typedef enum
{
    CY_CAN_RX_BUFFER_EMPTY              = 0u,   /**< Rx Buffer is empty */
    CY_CAN_RX_BUFFER_FILLED             = 1u    /**< Rx Buffer contains received data */
} cy_en_can_rx_buffer_status_t;

/** CAN Tx Buffer status enumeration */
typedef enum
{
    CY_CAN_TX_BUFFER_IDLE               = 0u,   /**< Tx Buffer is idle */
    CY_CAN_TX_BUFFER_PENDING            = 1u    /**< Tx Buffer is waiting to be sent */
} cy_en_can_tx_buffer_status_t;

/** Bit sampling mode type */
typedef enum
{
    CY_CAN_SAMPLING_MODE_1              = 0u,   /**< Single sampling point */
    CY_CAN_SAMPLING_MODE_3              = 1u    /**< 3 sampling points with majority decision */
} cy_en_can_sampling_t;

/** Synchronization logic type */
typedef enum
{
    CY_CAN_EDGE_R_TO_D                  = 0u,   /**< Edge from R to D */
    CY_CAN_BOTH_EDGE                    = 1u    /**< Both edge */
} cy_en_can_edgemode_t;

/** Tx Buffer arbitration scheme type */
typedef enum
{
    CY_CAN_ROUND_ROBIN                  = 0u,   /**< Round robin arbitration */
    CY_CAN_FIXED_PRIORITY               = 1u    /**< Fixed priority arbitration */
} cy_en_can_arbiter_t;

/** Byte Endianness of the data field type */
typedef enum
{
    CY_CAN_BIG_ENDIAN                   = 0u,   /**< Big endian */
    CY_CAN_LITTLE_ENDIAN                = 1u    /**< Little endian */
} cy_en_can_endian_t;

/** Bus-off automatic restart type */
typedef enum
{
    CY_CAN_MANUAL                       = 0u,   /**< After bus-off, the controller remains stopped */
    CY_CAN_AUTOMATIC                    = 1u    /**< After bus-off, the controller will automatically restart */
} cy_en_can_busoff_restart_t;

/** Test mode type */
typedef enum
{
    CY_CAN_TEST_MODE_DISABLE            = 0u,   /**< Normal operation */
    CY_CAN_TEST_MODE_LISTEN             = 1u,   /**< Listen-only mode */
    CY_CAN_TEST_MODE_EXTERNAL_LOOP_BACK = 2u,   /**< External loopback mode */
    CY_CAN_TEST_MODE_INTERNAL_LOOP_BACK = 3u    /**< Internal loopback mode */
} cy_en_can_test_mode_t;

/** Last Error Code Type. \n
*   Used with Cy_CAN_GetErrorCapture() for ERROR_TYPE fields of the
*   Error Capture Register.
*/
typedef enum
{
    CY_CAN_LEC_ARBITRATION_LOSS     = 0x00u,    /**< Arbitration loss */
    CY_CAN_LEC_BIT_ERROR            = 0x01u,    /**< Bit error */
    CY_CAN_LEC_STUFF_ERROR          = 0x02u,    /**< Bit stuff error */
    CY_CAN_LEC_ACK_ERROR            = 0x03u,    /**< Acknowledge error */
    CY_CAN_LEC_FORM_ERROR           = 0x04u,    /**< Form error */
    CY_CAN_LEC_CRC_ERROR            = 0x05u,    /**< CRC error */

} cy_en_can_lec_t;

/** \} group_can_enums */

/** \cond INTERNAL*/
/* PARAM_CHECK_MACROS  */

#define CY_CAN_IS_ARBITER_VALID(value)          ((CY_CAN_ROUND_ROBIN == (value)) || (CY_CAN_FIXED_PRIORITY == (value)))
#define CY_CAN_IS_ENDIAN_VALID(value)           ((CY_CAN_BIG_ENDIAN == (value)) || (CY_CAN_LITTLE_ENDIAN == (value)))
#define CY_CAN_IS_AUTO_RESTART_VALID(value)     ((CY_CAN_MANUAL == (value)) || (CY_CAN_AUTOMATIC == (value)))
#define CY_CAN_IS_RX_CFG_SIZE_VALID(value)      ((CY_CAN_MESSAGE_RX_BUFFERS_MAX_CNT) >= (value))

#define CY_CAN_PRESCALER_MAX                    (32767U)
#define CY_CAN_IS_PRESCALER_VALID(brp)          ((CY_CAN_PRESCALER_MAX) >= (brp))
#define CY_CAN_TIME_SEG_1_MIN                   (2U)
#define CY_CAN_TIME_SEG_1_MAX                   (15U)
#define CY_CAN_IS_TIME_SEG_1_VALID(tseg1)       (((CY_CAN_TIME_SEG_1_MAX) >= (tseg1)) && ((CY_CAN_TIME_SEG_1_MIN) <= (tseg1)))
#define CY_CAN_TIME_SEG_2_MAX                   (7U)
#define CY_CAN_IS_TIME_SEG_2_VALID(tseg2)       (((CY_CAN_TIME_SEG_2_MAX) >= (tseg2)) && (0U < (tseg2)))
#define CY_CAN_SYNC_JUMP_WIDTH_MAX              (3U)
#define CY_CAN_IS_SYNC_JUMP_WIDTH_VALID(sjw)    ((CY_CAN_SYNC_JUMP_WIDTH_MAX) >= (sjw))
#define CY_CAN_TEST_MODE_MAX_VALUE              (3U)
#define CY_CAN_IS_TEST_MODE_VALID(mode)         ((CY_CAN_TEST_MODE_MAX_VALUE) >= (mode))

#define CY_CAN_IS_ID_TYPE_VALID(type)           ((CY_CAN_IDE_STANDARD_ID == (type)) || (CY_CAN_IDE_EXTENDED_ID == (type)))
#define CY_CAN_STD_ID_MAX                       (0x7FFUL)
#define CY_CAN_IS_STD_ID_VALID(id)              ((CY_CAN_STD_ID_MAX) >= (id))
#define CY_CAN_XTD_ID_MAX                       (0x1FFFFFFFUL)
#define CY_CAN_IS_XTD_ID_VALID(id)              ((CY_CAN_XTD_ID_MAX) >= (id))
#define CY_CAN_IS_DLC_VALID(dlc)                ((CY_CAN_MAX_DATA_LENGTH) >= (dlc))

/** \endcond */

/***************************************
*       Configuration Structures
***************************************/

/**
* \addtogroup group_can_data_structures
* \{
*/

/** Rx buffer filter element */
typedef struct
{
    uint32_t        id;         /**< Identifier field */
    cy_en_can_ide_t idType;     /**< Identifier format. See \ref cy_en_can_ide_t */
    uint16_t        data;       /**< Data byte 1(D0) and 2(D1) */
    uint8_t         rtr;        /**< RTR bit */
    uint8_t         ide;        /**< IDE bit */
} cy_stc_can_rx_filter_element_t;

/** CAN message frame */
typedef struct {
    uint32_t        id;         /**< Frame identifier */
    uint32_t        data[2];    /**< Frame data */
    uint8_t         length;     /**< Frame data length */
    bool            rtr;        /**< Set to TRUE if remote frame */
    bool            ide;        /**< Set to TRUE if extended id format */
} cy_stc_can_message_frame_t;

/** Rx buffer configuration */
typedef struct
{
    cy_stc_can_rx_filter_element_t  acceptanceMask;         /**< Acceptance mask setting. See \ref cy_stc_can_rx_filter_element_t */
    cy_stc_can_rx_filter_element_t  acceptanceCode;         /**< Acceptance code setting. See \ref cy_stc_can_rx_filter_element_t */
    bool                            linked;                 /**< Set to TRUE if this buffer is linked with next buffer */
    bool                            interruptEnabled;       /**< Set to TRUE if interrupt is enabled */
    bool                            autoReplyRtr;           /**< Set TRUE to automatically reply to remote frame */
    bool                            enable;                 /**< Set TRUE to use this buffer */
} cy_stc_can_rx_buffer_config_t;
 
/** CAN bitrate parameters */
typedef struct
{
    uint16_t                prescaler;         /**< Baud rate prescaler */
    uint8_t                 timeSegment1;      /**< Time segment before sample point */
    uint8_t                 timeSegment2;      /**< Time segment after sample point */
    uint8_t                 syncJumpWidth;     /**< Synchronization jump width */
    cy_en_can_sampling_t    samplingMode;      /**< Number of sampling time. See \ref cy_en_can_sampling_t */
    cy_en_can_edgemode_t    edgeMode;          /**< Edge used for synchronization. See \ref cy_en_can_edgemode_t */
} cy_stc_can_bitrate_t;

/**
* Message transmission complete callback function (cy_can_tx_msg_func_ptr_t).
* Signals a successful completed transmission.
* Triggered with
* \ref CY_CAN_TRANSMISSION_COMPLETE
* interrupt event
*/
typedef void (*cy_can_tx_msg_func_ptr_t)(void);

/**
* The message reception callback function for message received in the Rx Buffer
* (cy_can_rx_msg_func_ptr_t). The index indicates the number of the received
* Rx buffer.
* Signals that CAN has received a new message. \n
*
* Triggered with                    \n
* \ref CY_CAN_RX_BUFFER_NEW_MESSAGE \n
* \ref CY_CAN_RTR_REPLY_COMPLETE    \n
* interrupt events.
*/
typedef void (*cy_can_rx_msg_func_ptr_t)(uint8_t index,
                                         cy_stc_can_message_frame_t* rxMsg);

/**
* The error callback function (cy_can_error_func_ptr_t).
* Signals that the CAN bus status changed or an error occurred. \n
* Triggered with                                \n
* \ref CY_CAN_ARBITRATION_LOST                  \n
* \ref CY_CAN_OVERLOAD_FRAME_RECEIVED           \n
* \ref CY_CAN_BIT_ERROR_OCCURRED                \n
* \ref CY_CAN_STUFF_ERROR_OCCURRED              \n
* \ref CY_CAN_ACK_ERROR_OCCURRED                \n
* \ref CY_CAN_FORM_ERROR_OCCURRED               \n
* \ref CY_CAN_CRC_ERROR_OCCURRED                \n
* \ref CY_CAN_BUS_OFF_STATUS                    \n
* \ref CY_CAN_RX_MESSAGE_LOSS                   \n
* \ref CY_CAN_STUCK_AT_DOMINANT                 \n
* \ref CY_CAN_SINGLE_SHOT_FAILURE               \n
* interrupt events.
*/
typedef void (*cy_can_error_func_ptr_t)(uint32_t errorMask);

/** CAN configuration */
typedef struct
{
    cy_can_tx_msg_func_ptr_t            txCallback;         /**< Callback function for transmit completed.
                                                             * Can be NULL
                                                             */
    cy_can_rx_msg_func_ptr_t            rxCallback;         /**< Callback function for receive completed.
                                                             * Can be NULL
                                                             */
    cy_can_error_func_ptr_t             errorCallback;      /**< Callback function for CAN related errors.
                                                             * Can be NULL
                                                             */
    cy_en_can_arbiter_t                 arbiter;            /**< Tx buffer arbitration scheme setting */
    cy_en_can_endian_t                  swapEndian;         /**< Byte Endianness of the data field setting */
    cy_en_can_busoff_restart_t          busOffRestart;      /**< Bus-off automatic restart setting */
    const cy_stc_can_bitrate_t          *bitrate;           /**< Pointer to the bitrate setting */
    const cy_stc_can_rx_buffer_config_t *rxBuffer;          /**< Pointer to the Rx buffer configuration */
    uint8_t                             numOfRxBuffers;     /**< Number of the Rx buffer configured (Max 16) */
} cy_stc_can_config_t;

/** Context structure */
typedef struct
{
    cy_can_tx_msg_func_ptr_t    canTxInterruptFunction;     /**< The pointer to transmit interrupt callback */
    cy_can_rx_msg_func_ptr_t    canRxInterruptFunction;     /**< The pointer to receive interrupt callback */
    cy_can_error_func_ptr_t     canErrorInterruptFunction;  /**< The pointer to error interrupt callback */
} cy_stc_can_context_t;

/** \} group_can_data_structures */


/***************************************
*        Function Prototypes
***************************************/

/**
* \addtogroup group_can_functions
* \{
*/

cy_en_can_status_t Cy_CAN_Init(CAN_Type *base,
                               const cy_stc_can_config_t *config,
                               cy_stc_can_context_t *context);
cy_en_can_status_t Cy_CAN_DeInit(CAN_Type *base, cy_stc_can_context_t *context);
cy_en_can_rx_buffer_status_t Cy_CAN_GetRxBufferStatus(CAN_Type const *base, uint32_t index);
cy_en_can_status_t Cy_CAN_GetRxBuffer(CAN_Type *base, uint8_t index,
                                      cy_stc_can_message_frame_t *rxMsg);
cy_en_can_status_t Cy_CAN_ExtractMsgFromRxBuffer(CAN_Type *base,
                                                 cy_stc_can_message_frame_t *rxMsg,
                                                 const cy_stc_can_context_t *context);
void Cy_CAN_IrqHandler(CAN_Type *base, const cy_stc_can_context_t *context);
cy_en_can_tx_buffer_status_t Cy_CAN_GetTxBufferStatus(CAN_Type const *base, uint8_t index);
void Cy_CAN_SetBitrate(CAN_Type *base, const cy_stc_can_bitrate_t *bitrate);
cy_en_can_status_t Cy_CAN_Start(CAN_Type *base);
cy_en_can_status_t Cy_CAN_Stop(CAN_Type *base);
cy_en_can_status_t Cy_CAN_Transmit(CAN_Type *base, uint8_t index,
                                   const cy_stc_can_message_frame_t *frameData,
                                   bool interruptEnabled, bool singleShot,
                                   const cy_stc_can_context_t *context);
cy_en_can_status_t Cy_CAN_UpdateRxBufferConfig(CAN_Type *base, uint8_t index,
                                               const cy_stc_can_rx_buffer_config_t *config,
                                               const cy_stc_can_message_frame_t *remoteFrame);

/** \} group_can_functions */

/**
* \addtogroup group_can_functions
* \{
*/

__STATIC_INLINE uint32_t Cy_CAN_GetInterruptStatus(CAN_Type const *base);
__STATIC_INLINE void Cy_CAN_ClearInterrupt(CAN_Type *base, uint32_t status);
__STATIC_INLINE uint32_t Cy_CAN_GetInterruptMask(CAN_Type const *base);
__STATIC_INLINE void Cy_CAN_SetInterruptMask(CAN_Type *base, uint32_t interrupt);
__STATIC_INLINE void Cy_CAN_AckRxBuffer(CAN_Type *base, uint8_t index);
__STATIC_INLINE uint32_t Cy_CAN_GetErrorCapture(CAN_Type *base);
__STATIC_INLINE void Cy_CAN_SetTestMode(CAN_Type *base, cy_en_can_test_mode_t testMode);
__STATIC_INLINE void Cy_CAN_SetArbiter(CAN_Type *base, cy_en_can_arbiter_t arbiter);
__STATIC_INLINE void Cy_CAN_SetSwapEndian(CAN_Type *base, cy_en_can_endian_t endian);
__STATIC_INLINE void Cy_CAN_SetBusOffAutoRestart(CAN_Type *base, cy_en_can_busoff_restart_t restart);

/** \} group_can_functions */

/**
* \addtogroup group_can_functions
* \{
*/

/*******************************************************************************
* Function Name: Cy_CAN_GetInterruptStatus
****************************************************************************//**
*
* Returns a status of CAN interrupt requests.
*
* \param *base
* The pointer to a CAN instance.
*
* \return uint32_t
* The bit mask of the Interrupt Status.
* Valid masks can be found in
* \ref group_can_rx_interrupt_masks, \ref group_can_tx_interrupt_masks,
* \ref group_can_error_interrupt_masks.
*
* \funcusage
* \snippet can_snippet.c snippet_Cy_CAN_GetInterruptStatus
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_CAN_GetInterruptStatus(CAN_Type const *base)
{
    return base->INT_STATUS;
}


/*******************************************************************************
* Function Name: Cy_CAN_ClearInterrupt
****************************************************************************//**
*
* Clears CAN interrupts by setting each bit.
*
* \param *base
* The pointer to a CAN instance.
*
* \param status
* The bitmask of statuses to clear.
* Valid masks can be found in
* \ref group_can_rx_interrupt_masks, \ref group_can_tx_interrupt_masks,
* \ref group_can_error_interrupt_masks.
*
* \funcusage
* \snippet can_snippet.c snippet_Cy_CAN_ClearInterrupt
*
*******************************************************************************/
__STATIC_INLINE void Cy_CAN_ClearInterrupt(CAN_Type *base, uint32_t status)
{
    base->INT_STATUS = status;
}


/*******************************************************************************
* Function Name: Cy_CAN_GetInterruptMask
****************************************************************************//**
*
* Returns an interrupt mask.
*
* \param *base
* The pointer to a CAN instance.
*
* \return uint32_t
* The bit field determines which status changes can cause an interrupt.
* Valid masks can be found in
* \ref group_can_rx_interrupt_masks, \ref group_can_tx_interrupt_masks,
* \ref group_can_error_interrupt_masks, \ref group_can_global_interrupt_masks.
*
* \funcusage
* \snippet can_snippet.c snippet_Cy_CAN_GetInterruptMask
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_CAN_GetInterruptMask(CAN_Type const *base)
{
    return base->INT_EBL;
}


/*******************************************************************************
* Function Name: Cy_CAN_SetInterruptMask
****************************************************************************//**
*
* Configures which bits of the interrupt request register can trigger an
* interrupt event.
*
* \param *base
* The pointer to a CAN instance.
*
* \param interrupt
* The bit field determines which status changes can cause an interrupt.
* Valid masks can be found in
* \ref group_can_rx_interrupt_masks, \ref group_can_tx_interrupt_masks,
* \ref group_can_error_interrupt_masks, \ref group_can_global_interrupt_masks.
*
* \funcusage
* \snippet can_snippet.c snippet_Cy_CAN_SetInterruptMask
*
*******************************************************************************/
__STATIC_INLINE void Cy_CAN_SetInterruptMask(CAN_Type *base, uint32_t interrupt)
{
    base->INT_EBL = interrupt;
}


/*******************************************************************************
* Function Name: Cy_CAN_AckRxBuffer
****************************************************************************//**
*
* Acknowledges the data reading and makes the buffer element available for
* a next message.
*
* \param *base
* The pointer to a CAN instance.
*
* \param index
* Rx Message buffer index (0-15).
*
* \funcusage
* \snippet can_snippet.c snippet_Cy_CAN_GetRxBuffer
*
*******************************************************************************/
__STATIC_INLINE void Cy_CAN_AckRxBuffer(CAN_Type *base, uint8_t index)
{
    uint32_t work;

    CY_ASSERT_L2(CY_CAN_IS_MESSAGE_RX_BUFFER_IDX_VALID(index));

    work = base->RX[index].CONTROL;
    work |= (CAN_RX_CONTROL_WPNL_Msk | CAN_RX_CONTROL_MSG_AV_RTRSENT_Msk);
    base->RX[index].CONTROL = work;
}


/*******************************************************************************
* Function Name: Cy_CAN_GetErrorCapture
****************************************************************************//**
*
* Returns the current error information.
*
* \param *base
* The pointer to a CAN instance.
*
* \return uint32_t
* Register value of the CAN_ECR
*
* \funcusage
* \snippet can_snippet.c snippet_Cy_CAN_GetErrorCapture
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_CAN_GetErrorCapture(CAN_Type *base)
{
    uint32_t value = base->ECR;
    base->ECR = CY_CAN_ECR_STATUS_MSK; /* Arm the ECR again */
    return value;
}


/*******************************************************************************
* Function Name: Cy_CAN_SetTestMode
****************************************************************************//**
*
* Changes the test mode setting.
*
* \param *base
* The pointer to a CAN instance.
*
* \param testMode \ref cy_en_can_test_mode_t
*
* \funcusage
* \snippet can_snippet.c snippet_Cy_CAN_SetTestMode
*
*******************************************************************************/
__STATIC_INLINE void Cy_CAN_SetTestMode(CAN_Type *base, cy_en_can_test_mode_t testMode)
{
    const uint32_t mask = (CAN_COMMAND_LOOPBACK_TEST_Msk | CAN_COMMAND_LISTEN_Msk);
    uint32_t work;

    CY_ASSERT_L2(CY_CAN_IS_TEST_MODE_VALID(testMode));

    work = base->COMMAND & (~mask);
    work |= (uint32_t)(((uint32_t)testMode) << CAN_COMMAND_LISTEN_Pos);
    base->COMMAND = work;
}


/*******************************************************************************
* Function Name: Cy_CAN_SetArbiter
****************************************************************************//**
*
* Changes the Tx Buffer arbiter setting.
*
* \param *base
* The pointer to a CAN instance.
*
* \param arbiter \ref cy_en_can_arbiter_t
*
*******************************************************************************/
__STATIC_INLINE void Cy_CAN_SetArbiter(CAN_Type *base, cy_en_can_arbiter_t arbiter)
{
    CY_REG32_CLR_SET(base->CONFIG, CAN_CONFIG_CFG_ARBITER, arbiter);
}


/*******************************************************************************
* Function Name: Cy_CAN_SetSwapEndian
****************************************************************************//**
*
* Changes the byte endianness of the data field setting.
*
* \param *base
* The pointer to a CAN instance.
*
* \param endian \ref cy_en_can_endian_t
*
*******************************************************************************/
__STATIC_INLINE void Cy_CAN_SetSwapEndian(CAN_Type *base, cy_en_can_endian_t endian)
{
    CY_REG32_CLR_SET(base->CONFIG, CAN_CONFIG_SWAP_ENDIAN, endian);
}


/*******************************************************************************
* Function Name: Cy_CAN_SetBusOffAutoRestart
****************************************************************************//**
*
* Changes the bus-off auto restart setting.
*
* \param *base
* The pointer to a CAN instance.
*
* \param restart \ref cy_en_can_busoff_restart_t
*
*******************************************************************************/
__STATIC_INLINE void Cy_CAN_SetBusOffAutoRestart(CAN_Type *base, cy_en_can_busoff_restart_t restart)
{
    CY_REG32_CLR_SET(base->CONFIG, CAN_CONFIG_AUTO_RESTART, restart);
}

/** \} group_can_functions */

#if defined(__cplusplus)
}
#endif

#endif /* CY_IP_M0S8CAN */

#endif /* CY_CAN_H */

/** \} group_can */

/* [] END OF FILE */
