/***************************************************************************//**
* \file cy_dmac.h
* \version 1.20
*
* \brief
* The header file of the DMAC driver.
*
********************************************************************************
* \copyright
* (c) (2020-2021), Cypress Semiconductor Corporation (an Infineon company) or
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
* \addtogroup group_dmac
* \{
* Configures the DMA Controller block, channels and descriptors.
*
* The functions and other declarations used in this driver are in cy_dmac.h.
* You can include cy_pdl.h to get access to all functions
* and declarations in the PDL.
*
* The DMA Controller channel is used in any project to transfer data
* without CPU intervention basing on a hardware trigger signal from another component.
*
* The DMA Controller block has a set of registers, a base hardware address,
* and supports multiple channels with ping and pong descriptors. Many API functions
* for the DMAC driver require a base hardware address, channel number and descriptor.
* Ensure that you use the correct hardware address for the DMA Controller block in use.
*
* Features:
* * Multiple channels (device specific).
* * Four priority levels for each channel.
* * Ping and pong descriptors for each channel.
* * Descriptor chaining.
* * Configurable data transfer width/masking: byte, half-word (2-byte), and word (4-byte).
* * Configurable source and destination addresses.
* * Single data transfer, entire descriptor and descriptor list transfer supported.
* * Configurable input/output triggers and interrupts.
*
* \section group_dmac_configuration Configuration Considerations
*
* To set up a DMAC driver, initialize and validate a descriptor
* and channel, then enable the DMAC block.
*
* To set up a descriptor, provide the configuration parameters for the
* descriptor in the \ref cy_stc_dmac_descriptor_config_t structure. Then call the
* \ref Cy_DMAC_Descriptor_Init function to initialize the descriptor.
* You can modify the source and destination addresses dynamically by calling
* \ref Cy_DMAC_Descriptor_SetSrcAddress and \ref Cy_DMAC_Descriptor_SetDstAddress.
*
* To set up a DMAC channel, provide a filled \ref cy_stc_dmac_channel_config_t
* structure. Call the \ref Cy_DMAC_Channel_Init function, specifying the channel
* number. Use \ref Cy_DMAC_Channel_Enable to enable the configured DMAC channel.
*
* Call \ref Cy_DMAC_Channel_Enable for each DMAC channel in use.
*
* When configured, another peripheral typically triggers the DMAC channel. The trigger is
* connected to the DMAC channel using the trigger multiplexer. The trigger multiplexer
* driver has a software trigger you can use in firmware to trigger the DMAC channel. See the
* <a href="group__group__trigmux.html">Trigger Multiplexer</a> documentation.
*
* The following is a simplified structure of the DMAC driver API interdependencies
* in a typical user application:
*
*
* <B>NOTE:</B> Even if a DMAC channel is enabled and the descriptor is validated, the channel
* is not operational until the DMAC block is enabled using function \ref Cy_DMAC_Enable.\n
* <B>NOTE:</B> If the DMAC descriptor is configured to generate an interrupt,
* the interrupt must be enabled using the \ref Cy_DMAC_SetInterruptMask
* function for each DMAC channel.
*
* For example:
* \snippet dmac_snippet.c snippet_Cy_DMAC_Enable
*
* \section group_dmac_power_modes Power Modes.
*
* The DMA controller provides the Active/Sleep functionality and is not available in
* Deep-Sleep power mode.
* Before transition to Deep-Sleep, handle pending interrupts and triggers for channels
* because they will be cleared on transition or wait for completion using the
* \ref Cy_DMAC_GetActiveChannel function.
* \snippet dmac_snippet.c snippet_Cy_DMAC_WaitForCompletion
*
* Refer to the \ref group_syspm driver for more information about
* low-power mode transitions.
*
* \section group_dmac_more_information More Information.
* See the DMAC chapter of the device technical reference manual (TRM).
*
* \section group_dmac_changelog Changelog
*
* <table class="doxtable">
*   <tr><th>Version</th><th>Changes</th><th>Reason for Change</th></tr>
*   <tr>
*     <td>1.20</td>
*     <td>Interface update for Cy_DMAC_Descriptor_SetSrcAddress() and Cy_DMAC_Descriptor_SetDstAddress(), parameter update for cy_stc_dmac_descriptor_config_t. </td>
*     <td>MISRA violation fix.</td>
*   </tr>
*   <tr>
*     <td>1.10.1</td>
*     <td>Update the paths to the code snippets.</td>
*     <td>PDL structure update.</td>
*   </tr>
*   <tr>
*     <td>1.10</td>
*     <td>Fixed the \ref Cy_DMAC_Descriptor_SetState() function to properly clear status register.</td>
*     <td>Defect fix.</td>
*   </tr>
*   <tr>
*     <td>1.0.1</td>
*     <td>Corrected source code comments text.</td>
*     <td></td>
*   </tr>
*   <tr>
*     <td>1.0</td>
*     <td>The initial version.</td>
*     <td></td>
*   </tr>
* </table>
*
* \defgroup group_dmac_macros Macros
* \defgroup group_dmac_macros_interrupt_masks Interrupt Masks
* \defgroup group_dmac_functions Functions
* \{
* \defgroup group_dmac_block_functions Block Functions
* \defgroup group_dmac_channel_functions Channel Functions
* \defgroup group_dmac_descriptor_functions Descriptor Functions
* \}
* \defgroup group_dmac_data_structures Data Structures
* \defgroup group_dmac_enums Enumerated Types
*/

#if !defined(CY_DMAC_H)
#define CY_DMAC_H

#include "cy_device.h"
#include "cy_device_headers.h"
#include "cy_syslib.h"
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#if defined(CY_IP_M0S8CPUSSV3_DMAC)

#if defined(__cplusplus)
extern "C" {
#endif

/******************************************************************************
 * Macro definitions                                                          *
 ******************************************************************************/

/**
* \addtogroup group_dmac_macros
* \{
*/

/** The driver major version */
#define CY_DMAC_DRV_VERSION_MAJOR       1

/** The driver minor version */
#define CY_DMAC_DRV_VERSION_MINOR       10

/** The DMAC driver identifier */
#define CY_DMAC_ID                      (CY_PDL_DRV_ID(0x3FU))

/**
* \addtogroup group_dmac_macros_interrupt_masks Interrupt Masks
* \{
*/

#define CY_DMAC_INTR_CHAN_0 (0x1UL)     /**< Channel 0 interrupt mask */
#define CY_DMAC_INTR_CHAN_1 (0x2UL)     /**< Channel 1 interrupt mask */
#define CY_DMAC_INTR_CHAN_2 (0x4UL)     /**< Channel 2 interrupt mask */
#define CY_DMAC_INTR_CHAN_3 (0x8UL)     /**< Channel 3 interrupt mask */
#define CY_DMAC_INTR_CHAN_4 (0x10UL)    /**< Channel 4 interrupt mask */
#define CY_DMAC_INTR_CHAN_5 (0x20UL)    /**< Channel 5 interrupt mask */
#define CY_DMAC_INTR_CHAN_6 (0x40UL)    /**< Channel 6 interrupt mask */
#define CY_DMAC_INTR_CHAN_7 (0x80UL)    /**< Channel 7 interrupt mask */

#if (8U < CPUSS_DMAC_CH_NR) || defined(CY_DOXYGEN) /* For devices with more then 8 DMAC channels */
#define CY_DMAC_INTR_CHAN_8  (0x100UL)  /**< Channel 8 interrupt mask */
#define CY_DMAC_INTR_CHAN_9  (0x200UL)  /**< Channel 9 interrupt mask */
#define CY_DMAC_INTR_CHAN_10 (0x400UL)  /**< Channel 10 interrupt mask */
#define CY_DMAC_INTR_CHAN_11 (0x800UL)  /**< Channel 11 interrupt mask */
#define CY_DMAC_INTR_CHAN_12 (0x1000UL) /**< Channel 12 interrupt mask */
#define CY_DMAC_INTR_CHAN_13 (0x2000UL) /**< Channel 13 interrupt mask */
#define CY_DMAC_INTR_CHAN_14 (0x4000UL) /**< Channel 14 interrupt mask */
#define CY_DMAC_INTR_CHAN_15 (0x8000UL) /**< Channel 15 interrupt mask */
#endif

/** \} group_dmac_macros_interrupt_masks */

/** \} group_dmac_macros */


/**
* \addtogroup group_dmac_enums
* \{
*/

/** Descriptor type */
typedef enum
{
    CY_DMAC_DESCRIPTOR_PING  = 0U,          /**< Ping descriptor.  */
    CY_DMAC_DESCRIPTOR_PONG  = 1U,          /**< Pong descriptor.  */
} cy_en_dmac_descriptor_t;

/** Triggering Type */
typedef enum
{
    CY_DMAC_SINGLE_ELEMENT = 0U,   /**< A single trigger initiates a single data element transfer. */
    CY_DMAC_SINGLE_DESCR   = 1U,   /**< A single trigger initiates a single descriptor transfer. */
    CY_DMAC_DESCR_LIST     = 2U    /**< A single trigger initiates a descriptor list transfer.
                                    *   This option relies on \ref cy_stc_dmac_descriptor_config_t::flipping to be set to 'true',
                                    *   such that the cy_stc_dmac_channel_config_t::descriptor field is flipped/inverted and the successive descriptor is used.
                                    */
}cy_en_dmac_trigger_type_t;

/** Contains the options for the data size */
typedef enum
{
    CY_DMAC_BYTE     = 0U,                  /**< One byte.               */
    CY_DMAC_HALFWORD = 1U,                  /**< Half word (two bytes).  */
    CY_DMAC_WORD     = 2U                   /**< Full word (four bytes). */
} cy_en_dmac_data_size_t;

/** Contains the options for descriptor retriggering */
typedef enum
{
    CY_DMAC_RETRIG_IM      = 0U,            /**< Retrigger immediately.              */
    CY_DMAC_RETRIG_4CYC    = 1U,            /**< Retrigger after 4 Clk_Slow cycles.  */
    CY_DMAC_RETRIG_16CYC   = 2U,            /**< Retrigger after 16 Clk_Slow cycles. */
    CY_DMAC_WAIT_FOR_REACT = 3U             /**< Wait for trigger reactivation.      */
} cy_en_dmac_retrigger_t;

/** Contains the options for the transfer size */
typedef enum
{
    CY_DMAC_TRANSFER_SIZE_DATA = 0U,        /**< As specified by dataSize. */
    CY_DMAC_TRANSFER_SIZE_WORD = 1U,        /**< A full word (four bytes). */
} cy_en_dmac_transfer_size_t;

/** Contains the return values of the DMAC driver */
typedef enum
{
    CY_DMAC_SUCCESS          = 0x0UL,      /**< Success. */
    CY_DMAC_BAD_PARAM        = CY_DMAC_ID | CY_PDL_STATUS_ERROR | 0x1UL /**< The input parameters passed to the DMAC API are not valid. */
} cy_en_dmac_status_t;

/**
* The descriptor response codes.
* The first two codes NO_ERROR and DONE are the result of normal behavior, the other codes are the result of erroneous behavior.
*/
typedef enum
{
    CY_DMAC_NO_ERROR      = 0x0UL,    /**< No error. Setting this response does NOT set the interrupt cause bit.
                                       *   The descriptor validness status is not affected.
                                       *   The channel enable state is not affected.
                                       *   The channel current descriptor status is not updated.
                                       *   This response is used for an unused or not completed descriptor.
                                       */
    CY_DMAC_DONE          = 0x1UL,    /**< The descriptor is done (without errors).
                                       *   Setting this response sets the interrupt bit if \ref cy_stc_dmac_descriptor_config_t::interrupt is true.
                                       *   The descriptor is invalidated if \ref cy_stc_dmac_descriptor_config_t::cpltState is true.
                                       *   The channel enable state is not affected.
                                       *   The channel current descriptor status is updated if \ref cy_stc_dmac_descriptor_config_t::flipping is true.
                                       */
    CY_DMAC_SRC_BUS_ERROR = 0x2UL,    /**< A bus error while loading data from the source location.
                                       *   Setting this response sets the correspondent interrupt bit.
                                       *   The descriptor is invalidated.
                                       *   The channel is disabled.
                                       *   The channel current descriptor status is not updated (it identifies the descriptor that caused the error).
                                       */
    CY_DMAC_DST_BUS_ERROR = 0x3UL,    /**< A bus error while storing data to the destination location.
                                       *   Setting this response sets the correspondent interrupt bit.
                                       *   The descriptor is invalidated.
                                       *   The channel is disabled.
                                       *   The channel current descriptor status is not updated (it identifies the descriptor that caused the error).
                                       */
    CY_DMAC_SRC_MISAL     = 0x4UL,    /**< Misalignment of the source address.
                                       *   This occurs on a source 16-bit bus transfer that is not 2-byte aligned or
                                       *   on a 32-bit bus transfer that is not 4-byte aligned.
                                       *   Setting this response sets the correspondent interrupt bit.
                                       *   The descriptor is invalidated.
                                       *   The channel is disabled.
                                       *   The channel current descriptor status is not updated (it identifies the descriptor that caused the error).
                                       */
    CY_DMAC_DST_MISAL     = 0x5UL,    /**< Misalignment of the destination address.
                                       *   This occurs on a destination 16-bit bus transfer that is not 2-byte aligned or
                                       *   on a 32-bit bus transfer that is not 4-byte aligned.
                                       *   Setting this response sets the correspondent interrupt bit.
                                       *   The descriptor is invalidated.
                                       *   The channel is disabled.
                                       *   The channel current descriptor status is not updated (it identifies the descriptor that caused the error).
                                       */
    CY_DMAC_INVALID_DESCR = 0x6UL     /**< The invalid descriptor.
                                       *   This occurs when an activated channel has an invalidated/disabled descriptor (either by HW or FW).
                                       *   The channel is disabled.
                                       *   The channel current descriptor status is not updated (it identifies the descriptor that caused the error).
                                       */
} cy_en_dmac_response_t;

/** \} group_dmac_enums */

/** \cond Macros for the conditions used by CY_ASSERT calls */

#define CY_DMAC_IS_PRIORITY_VALID(prio)         ((prio) <= 3UL)

#define CY_DMAC_IS_RETRIGGER_VALID(retrigger)   ((CY_DMAC_RETRIG_IM      == (retrigger)) || \
                                                 (CY_DMAC_RETRIG_4CYC    == (retrigger)) || \
                                                 (CY_DMAC_RETRIG_16CYC   == (retrigger)) || \
                                                 (CY_DMAC_WAIT_FOR_REACT == (retrigger)))

#define CY_DMAC_IS_XFER_SIZE_VALID(xferSize)    ((CY_DMAC_TRANSFER_SIZE_DATA == (xferSize)) || \
                                                 (CY_DMAC_TRANSFER_SIZE_WORD == (xferSize)))

#define CY_DMAC_IS_DATA_SIZE_VALID(dataSize)    ((CY_DMAC_BYTE     == (dataSize)) || \
                                                 (CY_DMAC_HALFWORD == (dataSize)) || \
                                                 (CY_DMAC_WORD     == (dataSize)))

#define CY_DMAC_IS_DATA_CNT_VALID(dataCnt)      ((1UL <= (dataCnt)) && ((dataCnt) <= 0x10000)) /* 16-bit + 1 */

#define CY_DMAC_IS_TRIG_TYPE_VALID(trig)        ((CY_DMAC_SINGLE_ELEMENT == (trig)) || \
                                                 (CY_DMAC_SINGLE_DESCR   == (trig)) || \
                                                 (CY_DMAC_DESCR_LIST     == (trig)))

#define CY_DMAC_IS_DESCR_VALID(descr)           ((CY_DMAC_DESCRIPTOR_PING == (descr)) || \
                                                 (CY_DMAC_DESCRIPTOR_PONG == (descr)))

#define CY_DMAC_IS_CH_NR_VALID(chNr)            (CPUSS_DMAC_CH_NR > (chNr))

#define CY_DMAC_INTR_MASK                       ((1UL << CPUSS_DMAC_CH_NR) - 1UL)
#define CY_DMAC_IS_INTR_MASK_VALID(intr)        (0UL == ((intr) & ((uint32_t) ~CY_DMAC_INTR_MASK)))

/** \endcond */


/**
* \addtogroup group_dmac_data_structures
* \{
*/


/**
* This structure holds initialization values for the DMAC ping/pong descriptor.
*
* It contains descriptor configuration elements and is pre-initialized by user.
* It passed as a parameter to the \ref Cy_DMAC_Descriptor_Init().
*
*/
typedef struct
{
    void volatile const *        srcAddress;       /**< The source address of the transfer. */
    void volatile *              dstAddress;       /**< The destination address of the transfer. */
    uint32_t                     dataCount;        /**< The natural number of data elements to transfer,
                                                     *  for example, "1" means one data element is transferred.
                                                     *  The valid range is 1...65536. */
    cy_en_dmac_data_size_t       dataSize;         /**< The data size. */
    cy_en_dmac_transfer_size_t   srcTransferSize;  /**< The source transfer size. */
    bool                         srcAddrIncrement; /**< Increment the source address (by value defined by srcTransferSize) after each transfer. */
    cy_en_dmac_transfer_size_t   dstTransferSize;  /**< The destination transfer size. */
    bool                         dstAddrIncrement; /**< Increment the destination address (by value defined by dstTransferSize) after each transfer */
    cy_en_dmac_retrigger_t       retrigger;        /**< Specifies whether the DMA controller should wait for the input trigger to be deactivated. */
    bool                         cpltState;        /**< Invalidate the descriptor on completion. */
    bool                         interrupt;        /**< Set an interrupt on descriptor completion. */
    bool                         preemptable;      /**< The transfer is preemptable. */
    bool                         flipping;         /**< Flip the active channel descriptor after completion. */
    cy_en_dmac_trigger_type_t    triggerType;      /**< Sets what type of transfer is triggered. See \ref cy_en_dmac_trigger_type_t. */
} cy_stc_dmac_descriptor_config_t;

/** This structure holds initialization values for the DMAC channel */
typedef struct
{
    uint32_t priority;                  /**< This parameter specifies the channel's priority. */
    bool     enable;                    /**< This parameter specifies if the channel is enabled after initializing. */
    cy_en_dmac_descriptor_t descriptor; /**< This field identifies the descriptor structure, which is currently used by the controller. */
} cy_stc_dmac_channel_config_t;

/** \} group_dmac_data_structures */


/**
* \addtogroup group_dmac_functions
* \{
*/

/**
* \addtogroup group_dmac_block_functions
* \{
*/

__STATIC_INLINE void     Cy_DMAC_Enable              (DMAC_Type       * base);
__STATIC_INLINE void     Cy_DMAC_Disable             (DMAC_Type       * base);
__STATIC_INLINE uint32_t Cy_DMAC_GetActiveChannel    (DMAC_Type const * base);
__STATIC_INLINE void *   Cy_DMAC_GetActiveSrcAddress (DMAC_Type const * base);
__STATIC_INLINE void *   Cy_DMAC_GetActiveDstAddress (DMAC_Type const * base);
__STATIC_INLINE uint32_t Cy_DMAC_GetCurrentIndex     (DMAC_Type const * base);
__STATIC_INLINE uint32_t Cy_DMAC_GetInterruptStatus       (DMAC_Type const * base);
__STATIC_INLINE uint32_t Cy_DMAC_GetInterruptStatusMasked (DMAC_Type const * base);
__STATIC_INLINE uint32_t Cy_DMAC_GetInterruptMask         (DMAC_Type const * base);
__STATIC_INLINE void     Cy_DMAC_SetInterruptMask         (DMAC_Type       * base, uint32_t interrupt);
__STATIC_INLINE void     Cy_DMAC_SetInterrupt             (DMAC_Type       * base, uint32_t interrupt);
__STATIC_INLINE void     Cy_DMAC_ClearInterrupt           (DMAC_Type       * base, uint32_t interrupt);

/** \} group_dmac_block_functions */

/**
* \addtogroup group_dmac_channel_functions
* \{
*/
     cy_en_dmac_status_t Cy_DMAC_Channel_Init                    (DMAC_Type       * base, uint32_t channel, cy_stc_dmac_channel_config_t const * config);
                void     Cy_DMAC_Channel_DeInit                  (DMAC_Type       * base, uint32_t channel);
__STATIC_INLINE void     Cy_DMAC_Channel_Enable                  (DMAC_Type       * base, uint32_t channel);
__STATIC_INLINE void     Cy_DMAC_Channel_Disable                 (DMAC_Type       * base, uint32_t channel);
__STATIC_INLINE void     Cy_DMAC_Channel_SetPriority             (DMAC_Type       * base, uint32_t channel, uint32_t priority);
__STATIC_INLINE uint32_t Cy_DMAC_Channel_GetPriority             (DMAC_Type const * base, uint32_t channel);
__STATIC_INLINE void     Cy_DMAC_Channel_SetCurrentDescriptor    (DMAC_Type       * base, uint32_t channel, cy_en_dmac_descriptor_t descriptor);
__STATIC_INLINE cy_en_dmac_descriptor_t Cy_DMAC_Channel_GetCurrentDescriptor(DMAC_Type const * base, uint32_t channel);

/** \} group_dmac_channel_functions */


/**
* \addtogroup group_dmac_descriptor_functions
* \{
*/

 cy_en_dmac_status_t Cy_DMAC_Descriptor_Init              (DMAC_Type * base, uint32_t channel, cy_en_dmac_descriptor_t descriptor, const cy_stc_dmac_descriptor_config_t * config);
                void Cy_DMAC_Descriptor_DeInit            (DMAC_Type * base, uint32_t channel, cy_en_dmac_descriptor_t descriptor);
__STATIC_INLINE void Cy_DMAC_Descriptor_SetState          (DMAC_Type * base, uint32_t channel, cy_en_dmac_descriptor_t descriptor, bool valid);
__STATIC_INLINE void Cy_DMAC_Descriptor_SetSrcAddress     (DMAC_Type * base, uint32_t channel, cy_en_dmac_descriptor_t descriptor, void volatile const * srcAddress);
__STATIC_INLINE void Cy_DMAC_Descriptor_SetDstAddress     (DMAC_Type * base, uint32_t channel, cy_en_dmac_descriptor_t descriptor, void volatile * dstAddress);
__STATIC_INLINE void Cy_DMAC_Descriptor_SetDataCount      (DMAC_Type * base, uint32_t channel, cy_en_dmac_descriptor_t descriptor, uint32_t count);
__STATIC_INLINE void Cy_DMAC_Descriptor_SetSrcIncrement   (DMAC_Type * base, uint32_t channel, cy_en_dmac_descriptor_t descriptor, bool increment);
__STATIC_INLINE void Cy_DMAC_Descriptor_SetDstIncrement   (DMAC_Type * base, uint32_t channel, cy_en_dmac_descriptor_t descriptor, bool increment);
__STATIC_INLINE void Cy_DMAC_Descriptor_SetDataSize       (DMAC_Type * base, uint32_t channel, cy_en_dmac_descriptor_t descriptor, cy_en_dmac_data_size_t dataSize);
__STATIC_INLINE void Cy_DMAC_Descriptor_SetSrcTransferSize(DMAC_Type * base, uint32_t channel, cy_en_dmac_descriptor_t descriptor, cy_en_dmac_transfer_size_t srcTransferSize);
__STATIC_INLINE void Cy_DMAC_Descriptor_SetDstTransferSize(DMAC_Type * base, uint32_t channel, cy_en_dmac_descriptor_t descriptor, cy_en_dmac_transfer_size_t dstTransferSize);
__STATIC_INLINE void Cy_DMAC_Descriptor_SetRetrigger      (DMAC_Type * base, uint32_t channel, cy_en_dmac_descriptor_t descriptor, cy_en_dmac_retrigger_t retrigger);
__STATIC_INLINE void Cy_DMAC_Descriptor_SetFlipping       (DMAC_Type * base, uint32_t channel, cy_en_dmac_descriptor_t descriptor, bool flipping);
__STATIC_INLINE void Cy_DMAC_Descriptor_SetTriggerType    (DMAC_Type * base, uint32_t channel, cy_en_dmac_descriptor_t descriptor, cy_en_dmac_trigger_type_t triggerType);
__STATIC_INLINE void Cy_DMAC_Descriptor_SetPreemptable    (DMAC_Type * base, uint32_t channel, cy_en_dmac_descriptor_t descriptor, bool preemptable);
__STATIC_INLINE void Cy_DMAC_Descriptor_SetCpltState      (DMAC_Type * base, uint32_t channel, cy_en_dmac_descriptor_t descriptor, bool invalidate);

__STATIC_INLINE bool                       Cy_DMAC_Descriptor_GetState          (DMAC_Type const * base, uint32_t channel, cy_en_dmac_descriptor_t descriptor);
__STATIC_INLINE void *                     Cy_DMAC_Descriptor_GetSrcAddress     (DMAC_Type const * base, uint32_t channel, cy_en_dmac_descriptor_t descriptor);
__STATIC_INLINE void *                     Cy_DMAC_Descriptor_GetDstAddress     (DMAC_Type const * base, uint32_t channel, cy_en_dmac_descriptor_t descriptor);
__STATIC_INLINE uint32_t                   Cy_DMAC_Descriptor_GetDataCount      (DMAC_Type const * base, uint32_t channel, cy_en_dmac_descriptor_t descriptor);
__STATIC_INLINE bool                       Cy_DMAC_Descriptor_GetSrcIncrement   (DMAC_Type const * base, uint32_t channel, cy_en_dmac_descriptor_t descriptor);
__STATIC_INLINE bool                       Cy_DMAC_Descriptor_GetDstIncrement   (DMAC_Type const * base, uint32_t channel, cy_en_dmac_descriptor_t descriptor);
__STATIC_INLINE uint32_t                   Cy_DMAC_Descriptor_GetCurrentIndex   (DMAC_Type const * base, uint32_t channel, cy_en_dmac_descriptor_t descriptor);
__STATIC_INLINE cy_en_dmac_data_size_t     Cy_DMAC_Descriptor_GetDataSize       (DMAC_Type const * base, uint32_t channel, cy_en_dmac_descriptor_t descriptor);
__STATIC_INLINE cy_en_dmac_transfer_size_t Cy_DMAC_Descriptor_GetSrcTransferSize(DMAC_Type const * base, uint32_t channel, cy_en_dmac_descriptor_t descriptor);
__STATIC_INLINE cy_en_dmac_transfer_size_t Cy_DMAC_Descriptor_GetDstTransferSize(DMAC_Type const * base, uint32_t channel, cy_en_dmac_descriptor_t descriptor);
__STATIC_INLINE cy_en_dmac_retrigger_t     Cy_DMAC_Descriptor_GetRetrigger      (DMAC_Type const * base, uint32_t channel, cy_en_dmac_descriptor_t descriptor);
__STATIC_INLINE bool                       Cy_DMAC_Descriptor_GetFlipping       (DMAC_Type const * base, uint32_t channel, cy_en_dmac_descriptor_t descriptor);
__STATIC_INLINE cy_en_dmac_trigger_type_t  Cy_DMAC_Descriptor_GetTriggerType    (DMAC_Type const * base, uint32_t channel, cy_en_dmac_descriptor_t descriptor);
__STATIC_INLINE cy_en_dmac_response_t      Cy_DMAC_Descriptor_GetResponse       (DMAC_Type const * base, uint32_t channel, cy_en_dmac_descriptor_t descriptor);
__STATIC_INLINE bool                       Cy_DMAC_Descriptor_GetPreemptable    (DMAC_Type const * base, uint32_t channel, cy_en_dmac_descriptor_t descriptor);
__STATIC_INLINE bool                       Cy_DMAC_Descriptor_GetCpltState      (DMAC_Type const * base, uint32_t channel, cy_en_dmac_descriptor_t descriptor);


/** \} group_dmac_descriptor_functions */


/***************************************
*    In-line Function Implementation
***************************************/


/**
* \addtogroup group_dmac_block_functions
* \{
*/


/*******************************************************************************
* Function Name: Cy_DMAC_Enable
****************************************************************************//**
*
* Enables the DMAC block.
*
* \param base
* The pointer to the hardware DMAC block.
*
* \funcusage
* \snippet dmac_snippet.c snippet_Cy_DMAC_Enable
*
*******************************************************************************/
__STATIC_INLINE void Cy_DMAC_Enable(DMAC_Type * base)
{
    DMAC_CTL(base) |= DMAC_CTL_ENABLED_Msk;
}


/*******************************************************************************
* Function Name: Cy_DMAC_Disable
****************************************************************************//**
*
* Disables the DMAC block.
*
* \param base
* The pointer to the hardware DMAC block.
*
* \funcusage
* \snippet dmac_snippet.c snippet_Cy_DMAC_Disable
*
*******************************************************************************/
__STATIC_INLINE void Cy_DMAC_Disable(DMAC_Type * base)
{
    DMAC_CTL(base) &= (uint32_t) ~DMAC_CTL_ENABLED_Msk;
}


/*******************************************************************************
* Function Name: Cy_DMAC_GetActiveChannel
****************************************************************************//**
*
* Returns the status of the active/pending channels of the DMAC block.
*
* \param base
* The pointer to the hardware DMAC block.
*
* \return
* Returns a bit-field with all of the currently active/pending channels in the
* DMAC block.
*
* \funcusage
* \snippet dmac_snippet.c snippet_Cy_DMAC_Disable
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_DMAC_GetActiveChannel(DMAC_Type const * base)
{
    return(DMAC_STATUS_CH_ACT(base));
}

CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 11.6', 8, 'Casting uint32_t to \
void* and void* to uint32_t is used only for set or get DMAC HW register. \
The address is checked to be valid, no unaligned access could occur and return \
value will always fit in unit32_t.');

/*******************************************************************************
* Function Name: Cy_DMAC_GetActiveSrcAddress
****************************************************************************//**
*
* Returns the source address of the active descriptor.
*
* \param base
* The pointer to the hardware DMAC block.
*
* \return
* The source address value of the DMAC block.
*
* \funcusage
* \snippet dmac_snippet.c snippet_Cy_DMAC_Channel_GetCurrentSrcAddress
*
*******************************************************************************/
__STATIC_INLINE void * Cy_DMAC_GetActiveSrcAddress(DMAC_Type const * base)
{
    return((void *) DMAC_STATUS_SRC_ADDR(base));
}


/*******************************************************************************
* Function Name: Cy_DMAC_GetActiveDstAddress
****************************************************************************//**
*
* Returns the destination address of the active descriptor.
*
* \param base
* The pointer to the hardware DMAC block.
*
* \return
* The destination address value of the DMAC block.
*
* \funcusage
* \snippet dmac_snippet.c snippet_Cy_DMAC_Channel_GetCurrentSrcAddress
*
*******************************************************************************/
__STATIC_INLINE void * Cy_DMAC_GetActiveDstAddress(DMAC_Type const * base)
{
    return ((void *) DMAC_STATUS_DST_ADDR(base));
}


/*******************************************************************************
* Function Name: Cy_DMAC_GetCurrentIndex
****************************************************************************//**
*
* Returns the current transfer index.
*
* \param base
* The pointer to the hardware DMAC block.
*
* \return
* The current transfer index.
*
* \funcusage
* \snippet dmac_snippet.c snippet_Cy_DMAC_Channel_GetCurrentIndex
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_DMAC_GetCurrentIndex (DMAC_Type const * base)
{
    return _FLD2VAL(DMAC_STATUS_DATA_NR, DMAC_STATUS(base));
}


/*******************************************************************************
* Function Name: Cy_DMAC_GetInterruptStatus
****************************************************************************//**
*
* Returns the interrupt(s) status.
*
* \param base
* The pointer to the hardware DMAC block.
*
* \return
* The interrupt status, see \ref group_dmac_macros_interrupt_masks.
*
* \funcusage
* \snippet dmac_snippet.c snippet_Cy_DMAC_GetInterruptStatus
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_DMAC_GetInterruptStatus(DMAC_Type const * base)
{
    return (DMAC_INTR(base));
}


/*******************************************************************************
* Function Name: Cy_DMAC_ClearInterrupt
****************************************************************************//**
*
* Clears the specified interrupt(s).
*
* \param base
* The pointer to the hardware DMAC block.
*
* \param interrupt
* The interrupt mask, see \ref group_dmac_macros_interrupt_masks.
*
* \funcusage
* \snippet dmac_snippet.c snippet_Cy_DMAC_ClearInterrupt
*
*******************************************************************************/
__STATIC_INLINE void Cy_DMAC_ClearInterrupt(DMAC_Type * base, uint32_t interrupt)
{
    CY_ASSERT_L2(CY_DMAC_IS_INTR_MASK_VALID(interrupt));
    DMAC_INTR(base) = interrupt & CY_DMAC_INTR_MASK;
    (void)DMAC_INTR(base);
}


/*******************************************************************************
* Function Name: Cy_DMAC_SetInterrupt
****************************************************************************//**
*
* Sets the specified interrupt(s).
*
* \param base
* The pointer to the hardware DMAC block.
*
* \param interrupt
* The interrupt mask. See \ref group_dmac_macros_interrupt_masks.
*
* \funcusage
* \snippet dmac_snippet.c snippet_Cy_DMAC_SetInterruptMask
*
*******************************************************************************/
__STATIC_INLINE void Cy_DMAC_SetInterrupt(DMAC_Type * base, uint32_t interrupt)
{
    CY_ASSERT_L2(CY_DMAC_IS_INTR_MASK_VALID(interrupt));
    DMAC_INTR_SET(base) = interrupt & CY_DMAC_INTR_MASK;
}


/*******************************************************************************
* Function Name: Cy_DMAC_Channel_GetInterruptMask
****************************************************************************//**
*
* Returns the interrupt mask value.
*
* \param base
* The pointer to the hardware DMAC block.
*
* \return
* The interrupt mask value. See \ref group_dmac_macros_interrupt_masks.
*
* \funcusage
* \snippet dmac_snippet.c snippet_Cy_DMAC_SetInterruptMask
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_DMAC_GetInterruptMask(DMAC_Type const * base)
{
    return (DMAC_INTR_MASK(base));
}


/*******************************************************************************
* Function Name: Cy_DMAC_SetInterruptMask
****************************************************************************//**
*
* Sets an interrupt mask value for the specified channel.
*
* \param base
* The pointer to the hardware DMAC block.
*
* \param interrupt
* The interrupt mask, see \ref group_dmac_macros_interrupt_masks.
*
* \funcusage
* \snippet dmac_snippet.c snippet_Cy_DMAC_SetInterruptMask
*
*******************************************************************************/
__STATIC_INLINE void Cy_DMAC_SetInterruptMask(DMAC_Type * base, uint32_t interrupt)
{
    CY_ASSERT_L2(CY_DMAC_IS_INTR_MASK_VALID(interrupt));
    DMAC_INTR_MASK(base) = interrupt & CY_DMAC_INTR_MASK;
}


/*******************************************************************************
* Function Name: Cy_DMAC_GetInterruptStatusMasked
****************************************************************************//**
*
* Returns the logical AND of the corresponding INTR and INTR_MASK registers
* in a single-load operation.
*
* \param base
* The pointer to the hardware DMAC block.
*
* \return
* The masked interrupt status. See \ref group_dmac_macros_interrupt_masks.
*
* \funcusage
* \snippet dmac_snippet.c snippet_Cy_DMAC_ClearInterrupt
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_DMAC_GetInterruptStatusMasked(DMAC_Type const * base)
{
    return (DMAC_INTR_MASKED(base));
}

/** \} group_dmac_block_functions */

/**
* \addtogroup group_dmac_descriptor_functions
* \{
*/


/*******************************************************************************
* Function Name: Cy_DMAC_Descriptor_SetState
****************************************************************************//**
*
* Sets the state of the specified descriptor.
*
* \param base
* The pointer to the hardware DMAC block.
*
* \param channel
* The channel number.
*
* \param descriptor
* The ping/pong descriptor.
*
* \param valid
* true - validate, false - invalidate.
*
* \note
* If descriptor is initialized dynamically there is a need to set state
* to invalid before initialization and to valid after. Do this to
* prevent the descriptor execution with wrong parameters.
*
* \funcusage
* \snippet dmac_snippet.c snippet_Cy_DMAC_SetState
*
*******************************************************************************/
__STATIC_INLINE void Cy_DMAC_Descriptor_SetState(DMAC_Type * base,
                                                    uint32_t channel,
                                     cy_en_dmac_descriptor_t descriptor,
                                                        bool valid)
{
    CY_ASSERT_L1(CY_DMAC_IS_CH_NR_VALID(channel));
    CY_ASSERT_L3(CY_DMAC_IS_DESCR_VALID(descriptor));

    if (CY_DMAC_DESCRIPTOR_PING == descriptor)
    {
        if (valid == true)
        {
            /* Validate descriptor, also clear CURR_DATA_NR and RESPONSE */
            DMAC_DESCR_PING_STATUS(base, channel) = DMAC_DESCR_PING_STATUS_VALID_Msk;
        }
        else
        {
            /* Invalidate descriptor, also clear CURR_DATA_NR and RESPONSE */
            DMAC_DESCR_PING_STATUS(base, channel) = 0UL;
        }

    }
    else
    {
        if (valid == true)
        {
            /* Validate descriptor, also clear CURR_DATA_NR and RESPONSE */
            DMAC_DESCR_PONG_STATUS(base, channel) = DMAC_DESCR_PONG_STATUS_VALID_Msk;
        }
        else
        {
            /* Invalidate descriptor, also clear CURR_DATA_NR and RESPONSE */
            DMAC_DESCR_PONG_STATUS(base, channel) = 0UL;
        }
    }
}


/*******************************************************************************
* Function Name: Cy_DMAC_Descriptor_GetState
****************************************************************************//**
*
* Returns a state of the specified descriptor.
*
* \param base
* The pointer to the hardware DMAC block.
*
* \param channel
* The channel number.
*
* \param descriptor
* The ping/pong descriptor.
*
* \return
* The state of descriptor. true - validated, false - invalidated.
*
* \funcusage
* \snippet dmac_snippet.c snippet_Cy_DMAC_InvalidateDescriptor
*
*******************************************************************************/
__STATIC_INLINE bool Cy_DMAC_Descriptor_GetState(DMAC_Type const * base,
                                                          uint32_t channel,
                                           cy_en_dmac_descriptor_t descriptor)
{
    CY_ASSERT_L1(CY_DMAC_IS_CH_NR_VALID(channel));
    CY_ASSERT_L3(CY_DMAC_IS_DESCR_VALID(descriptor));

    return(_FLD2BOOL(DMAC_DESCR_PING_STATUS_VALID, DMAC_DESCR_GET_STATUS(base, channel, descriptor)));
}


/*******************************************************************************
* Function Name: Cy_DMAC_Descriptor_SetSrcAddress
****************************************************************************//**
*
* Sets the source address parameter for the specified descriptor.
*
* \param base
* The pointer to the hardware DMAC block.
*
* \param channel
* The channel number.
*
* \param descriptor
* The ping/pong descriptor.
*
* \param srcAddress
* The source address value for the descriptor.
*
* \funcusage
* \snippet dmac_snippet.c snippet_Cy_DMAC_Descriptor_SetterFunctions
*
*******************************************************************************/
__STATIC_INLINE void Cy_DMAC_Descriptor_SetSrcAddress(DMAC_Type * base,
                                                         uint32_t channel,
                                          cy_en_dmac_descriptor_t descriptor,
                                            void volatile const * srcAddress)
{
    CY_ASSERT_L1(CY_DMAC_IS_CH_NR_VALID(channel));
    CY_ASSERT_L3(CY_DMAC_IS_DESCR_VALID(descriptor));

    DMAC_DESCR_SET_SRC(base, channel, descriptor, (uint32_t) srcAddress);
}


/*******************************************************************************
* Function Name: Cy_DMAC_Descriptor_GetSrcAddress
****************************************************************************//**
*
* Returns the source address parameter of the specified descriptor.
*
* \param base
* The pointer to the hardware DMAC block.
*
* \param channel
* The channel number.
*
* \param descriptor
* The ping/pong descriptor.
*
* \return
* The source address value of the descriptor.
*
* \funcusage
* \snippet dmac_snippet.c snippet_Cy_DMAC_Descriptor_GetterFunctions
*
*******************************************************************************/
__STATIC_INLINE void * Cy_DMAC_Descriptor_GetSrcAddress(DMAC_Type const * base,
                                                        uint32_t channel,
                                                        cy_en_dmac_descriptor_t descriptor)
{
    CY_ASSERT_L1(CY_DMAC_IS_CH_NR_VALID(channel));
    CY_ASSERT_L3(CY_DMAC_IS_DESCR_VALID(descriptor));

    return ((void *) DMAC_DESCR_GET_SRC(base, channel, descriptor));
}


/*******************************************************************************
* Function Name: Cy_DMAC_Descriptor_SetDstAddress
****************************************************************************//**
*
* Sets the destination address parameter for the specified descriptor.
*
* \param base
* The pointer to the hardware DMAC block.
*
* \param channel
* The channel number.
*
* \param descriptor
* The ping/pong descriptor.
*
* \param dstAddress
* The destination address value for the descriptor.
*
* \funcusage
* \snippet dmac_snippet.c snippet_Cy_DMAC_Descriptor_SetterFunctions
*
*******************************************************************************/
__STATIC_INLINE void Cy_DMAC_Descriptor_SetDstAddress(DMAC_Type * base,
                                                         uint32_t channel,
                                          cy_en_dmac_descriptor_t descriptor,
                                                  void volatile * dstAddress)
{

    CY_ASSERT_L1(CY_DMAC_IS_CH_NR_VALID(channel));
    CY_ASSERT_L3(CY_DMAC_IS_DESCR_VALID(descriptor));

    DMAC_DESCR_SET_DST(base, channel, descriptor, (uint32_t) dstAddress);
}


/*******************************************************************************
* Function Name: Cy_DMAC_Descriptor_GetDstAddress
****************************************************************************//**
*
* Returns the destination address parameter of the specified descriptor.
*
* \param base
* The pointer to the hardware DMAC block.
*
* \param channel
* The channel number.
*
* \param descriptor
* The ping/pong descriptor.
*
* \return
* The destination address value of the descriptor.
*
* \funcusage
* \snippet dmac_snippet.c snippet_Cy_DMAC_Descriptor_GetterFunctions
*
*******************************************************************************/
__STATIC_INLINE void * Cy_DMAC_Descriptor_GetDstAddress(DMAC_Type const * base,
                                                        uint32_t channel,
                                                        cy_en_dmac_descriptor_t descriptor)
{
    CY_ASSERT_L1(CY_DMAC_IS_CH_NR_VALID(channel));
    CY_ASSERT_L3(CY_DMAC_IS_DESCR_VALID(descriptor));

    return ((void *) DMAC_DESCR_GET_DST(base, channel, descriptor));
}

CY_MISRA_BLOCK_END('MISRA C-2012 Rule 11.6');

/*******************************************************************************
* Function Name: Cy_DMAC_Descriptor_SetDataCount
****************************************************************************//**
*
* Sets the number of data elements of the specified descriptor.
*
* \param base
* The pointer to the hardware DMAC block.
*
* \param channel
* The channel number.
*
* \param descriptor
* The ping/pong descriptor.
*
* \param count
* The natural number of data elements to transfer,
* for example, "1" means one data element is transferred.
* The valid range is 1...65536.
*
* \funcusage
* \snippet dmac_snippet.c snippet_Cy_DMAC_Descriptor_SetterFunctions
*
*******************************************************************************/
__STATIC_INLINE void Cy_DMAC_Descriptor_SetDataCount(DMAC_Type * base,
                                                        uint32_t channel,
                                         cy_en_dmac_descriptor_t descriptor,
                                                        uint32_t count)
{
    CY_ASSERT_L1(CY_DMAC_IS_CH_NR_VALID(channel));
    CY_ASSERT_L3(CY_DMAC_IS_DESCR_VALID(descriptor));
    CY_ASSERT_L1(CY_DMAC_IS_DATA_CNT_VALID(count));

    uint32_t reg;
    reg = _CLR_SET_FLD32U(DMAC_DESCR_GET_CTL(base, channel, descriptor), DMAC_DESCR_PONG_CTL_DATA_NR, count - 1UL);
    DMAC_DESCR_SET_CTL(base, channel, descriptor, reg);
}


/*******************************************************************************
* Function Name: Cy_DMAC_Descriptor_GetDataCount
****************************************************************************//**
*
* Returns the number of data elements of the specified descriptor.
*
* \param base
* The pointer to the hardware DMAC block.
*
* \param channel
* The channel number.
*
* \param descriptor
* The ping/pong descriptor.
*
* \return
* The natural number of data elements to transfer,
* for example, "1" means one data element is transferred.
* The range is 1...65536.
*
* \funcusage
* \snippet dmac_snippet.c snippet_Cy_DMAC_Descriptor_GetterFunctions
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_DMAC_Descriptor_GetDataCount(DMAC_Type const * base,
                                                         uint32_t channel,
                                                         cy_en_dmac_descriptor_t descriptor)
{
    CY_ASSERT_L1(CY_DMAC_IS_CH_NR_VALID(channel));
    CY_ASSERT_L3(CY_DMAC_IS_DESCR_VALID(descriptor));

    return (1UL + _FLD2VAL(DMAC_DESCR_PING_CTL_DATA_NR, DMAC_DESCR_GET_CTL(base, channel, descriptor)));
}


/*******************************************************************************
* Function Name: Cy_DMAC_Descriptor_SetDataSize
****************************************************************************//**
*
* Sets the Data Element Size parameter for the specified descriptor.
*
* \param base
* The pointer to the hardware DMAC block.
*
* \param channel
* The channel number.
*
* \param descriptor
* The ping/pong descriptor.
*
* \param dataSize
* The Data Element Size \ref cy_en_dmac_data_size_t
*
* \funcusage
* \snippet dmac_snippet.c snippet_Cy_DMAC_Descriptor_SetterFunctions
*
*******************************************************************************/
__STATIC_INLINE void Cy_DMAC_Descriptor_SetDataSize(DMAC_Type * base,
                                                       uint32_t channel,
                                        cy_en_dmac_descriptor_t descriptor,
                                         cy_en_dmac_data_size_t dataSize)
{
    CY_ASSERT_L1(CY_DMAC_IS_CH_NR_VALID(channel));
    CY_ASSERT_L3(CY_DMAC_IS_DESCR_VALID(descriptor));
    CY_ASSERT_L1(CY_DMAC_IS_DATA_SIZE_VALID(dataSize));

    uint32_t reg;
    reg = _CLR_SET_FLD32U(DMAC_DESCR_GET_CTL(base, channel, descriptor), DMAC_DESCR_PONG_CTL_DATA_SIZE, dataSize);
    DMAC_DESCR_SET_CTL(base, channel, descriptor, reg);
}


/*******************************************************************************
* Function Name: Cy_DMAC_Descriptor_GetDataSize
****************************************************************************//**
*
* Returns the Data Element Size of the specified descriptor.
*
* \param base
* The pointer to the hardware DMAC block.
*
* \param channel
* The channel number.
*
* \param descriptor
* The ping/pong descriptor.
*
* \return
* The Data Element Size \ref cy_en_dmac_data_size_t.
*
* \funcusage
* \snippet dmac_snippet.c snippet_Cy_DMAC_Descriptor_GetterFunctions
*
*******************************************************************************/
__STATIC_INLINE cy_en_dmac_data_size_t Cy_DMAC_Descriptor_GetDataSize(DMAC_Type const * base,
                                                                      uint32_t channel,
                                                                      cy_en_dmac_descriptor_t descriptor)
{
    CY_ASSERT_L1(CY_DMAC_IS_CH_NR_VALID(channel));
    CY_ASSERT_L3(CY_DMAC_IS_DESCR_VALID(descriptor));
CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 10.8', 4, \
'Value extracted from _FLD2VAL macro will not exceed enum range.');
    return((cy_en_dmac_data_size_t)_FLD2VAL(DMAC_DESCR_PONG_CTL_DATA_SIZE, DMAC_DESCR_GET_CTL(base, channel, descriptor)));
}


/*******************************************************************************
* Function Name: Cy_DMAC_Descriptor_SetSrcTransferSize
****************************************************************************//**
*
* Sets the Source Transfer Size parameter for the specified descriptor.
*
* \param base
* The pointer to the hardware DMAC block.
*
* \param channel
* The channel number.
*
* \param descriptor
* The ping/pong descriptor.
*
* \param srcTransferSize
* The Source Transfer Size \ref cy_en_dmac_transfer_size_t.
*
* \funcusage
* \snippet dmac_snippet.c snippet_Cy_DMAC_Descriptor_SetterFunctions
*******************************************************************************/
__STATIC_INLINE void Cy_DMAC_Descriptor_SetSrcTransferSize(DMAC_Type * base,
                                                              uint32_t channel,
                                               cy_en_dmac_descriptor_t descriptor,
                                            cy_en_dmac_transfer_size_t srcTransferSize)
{
    CY_ASSERT_L1(CY_DMAC_IS_CH_NR_VALID(channel));
    CY_ASSERT_L3(CY_DMAC_IS_DESCR_VALID(descriptor));
    CY_ASSERT_L1(CY_DMAC_IS_XFER_SIZE_VALID(srcTransferSize));

    uint32_t reg;
    reg = _CLR_SET_FLD32U(DMAC_DESCR_GET_CTL(base, channel, descriptor), DMAC_DESCR_PONG_CTL_SRC_TRANSFER_SIZE, srcTransferSize);
    DMAC_DESCR_SET_CTL(base, channel, descriptor, reg);
}


/*******************************************************************************
* Function Name: Cy_DMAC_Descriptor_GetSrcTransferSize
****************************************************************************//**
*
* Returns the Source Transfer Size of the specified descriptor.
*
* \param base
* The pointer to the hardware DMAC block.
*
* \param channel
* The channel number.
*
* \param descriptor
* The ping/pong descriptor.
*
* \return
* The Source Transfer Size \ref cy_en_dmac_transfer_size_t.
*
* \funcusage
* \snippet dmac_snippet.c snippet_Cy_DMAC_Descriptor_GetterFunctions
*
*******************************************************************************/
__STATIC_INLINE cy_en_dmac_transfer_size_t Cy_DMAC_Descriptor_GetSrcTransferSize(DMAC_Type const * base,
                                                                                 uint32_t channel,
                                                                                 cy_en_dmac_descriptor_t descriptor)
{
    uint32_t size;
    CY_ASSERT_L1(CY_DMAC_IS_CH_NR_VALID(channel));
    CY_ASSERT_L3(CY_DMAC_IS_DESCR_VALID(descriptor));

    size = _FLD2VAL(DMAC_DESCR_PONG_CTL_SRC_TRANSFER_SIZE, DMAC_DESCR_GET_CTL(base, channel, descriptor));
    return ((uint32_t)CY_DMAC_TRANSFER_SIZE_DATA == size)? CY_DMAC_TRANSFER_SIZE_DATA:
                                                           CY_DMAC_TRANSFER_SIZE_WORD;

}


/*******************************************************************************
* Function Name: Cy_DMAC_Descriptor_SetDstTransferSize
****************************************************************************//**
*
* Sets the Destination Transfer Size parameter for the specified descriptor.
*
* \param base
* The pointer to the hardware DMAC block.
*
* \param channel
* The channel number.
*
* \param descriptor
* The ping/pong descriptor.
*
* \param dstTransferSize
* The Destination Transfer Size \ref cy_en_dmac_transfer_size_t.
*
* \funcusage
* \snippet dmac_snippet.c snippet_Cy_DMAC_Descriptor_SetterFunctions
*
*******************************************************************************/
__STATIC_INLINE void Cy_DMAC_Descriptor_SetDstTransferSize(DMAC_Type * base,
                                                              uint32_t channel,
                                               cy_en_dmac_descriptor_t descriptor,
                                            cy_en_dmac_transfer_size_t dstTransferSize)
{
    CY_ASSERT_L1(CY_DMAC_IS_CH_NR_VALID(channel));
    CY_ASSERT_L3(CY_DMAC_IS_DESCR_VALID(descriptor));
    CY_ASSERT_L1(CY_DMAC_IS_XFER_SIZE_VALID(dstTransferSize));

    uint32_t reg;
    reg = _CLR_SET_FLD32U(DMAC_DESCR_GET_CTL(base, channel, descriptor), DMAC_DESCR_PONG_CTL_DST_TRANSFER_SIZE, dstTransferSize);
    DMAC_DESCR_SET_CTL(base, channel, descriptor, reg);
}


/*******************************************************************************
* Function Name: Cy_DMAC_Descriptor_GetDstTransferSize
****************************************************************************//**
*
* Returns the Destination Transfer Size of the specified descriptor.
*
* \param base
* The pointer to the hardware DMAC block.
*
* \param channel
* The channel number.
*
* \param descriptor
* The ping/pong descriptor.
*
* \return
* The Destination Transfer Size \ref cy_en_dmac_transfer_size_t
*
* \funcusage
* \snippet dmac_snippet.c snippet_Cy_DMAC_Descriptor_GetterFunctions
*
*******************************************************************************/
__STATIC_INLINE cy_en_dmac_transfer_size_t Cy_DMAC_Descriptor_GetDstTransferSize(DMAC_Type const * base,
                                                                                 uint32_t channel,
                                                                                 cy_en_dmac_descriptor_t descriptor)
{
    uint32_t size;
    CY_ASSERT_L1(CY_DMAC_IS_CH_NR_VALID(channel));
    CY_ASSERT_L3(CY_DMAC_IS_DESCR_VALID(descriptor));

    size = _FLD2VAL(DMAC_DESCR_PING_CTL_DST_TRANSFER_SIZE, DMAC_DESCR_GET_CTL(base, channel, descriptor));
    return ((uint32_t)CY_DMAC_TRANSFER_SIZE_DATA == size)? CY_DMAC_TRANSFER_SIZE_DATA:
                                                           CY_DMAC_TRANSFER_SIZE_WORD;
}


/*******************************************************************************
* Function Name: Cy_DMAC_Descriptor_SetRetrigger
****************************************************************************//**
*
* Sets the retrigger value which specifies whether the controller should
* wait for the input trigger to be deactivated.
*
* \param base
* The pointer to the hardware DMAC block.
*
* \param channel
* The channel number.
*
* \param descriptor
* The ping/pong descriptor.
*
* \param retrigger
* The \ref cy_en_dmac_retrigger_t parameter specifies whether the controller
* should wait for the input trigger to be deactivated.
*
* \funcusage
* \snippet dmac_snippet.c snippet_Cy_DMAC_Descriptor_SetterFunctions
*
*******************************************************************************/
__STATIC_INLINE void Cy_DMAC_Descriptor_SetRetrigger(DMAC_Type * base,
                                                        uint32_t channel,
                                         cy_en_dmac_descriptor_t descriptor,
                                          cy_en_dmac_retrigger_t retrigger)
{
    CY_ASSERT_L1(CY_DMAC_IS_CH_NR_VALID(channel));
    CY_ASSERT_L3(CY_DMAC_IS_DESCR_VALID(descriptor));
    CY_ASSERT_L1(CY_DMAC_IS_RETRIGGER_VALID(retrigger));

    uint32_t reg;
    reg = _CLR_SET_FLD32U(DMAC_DESCR_GET_CTL(base, channel, descriptor), DMAC_DESCR_PONG_CTL_WAIT_FOR_DEACT, retrigger);
    DMAC_DESCR_SET_CTL(base, channel, descriptor, reg);
}


/*******************************************************************************
* Function Name: Cy_DMAC_Descriptor_GetRetrigger
****************************************************************************//**
*
* Returns the value, which specifies whether the controller should
* wait for the input trigger to be deactivated.
*
* \param base
* The pointer to the hardware DMAC block.
*
* \param channel
* The channel number.
*
* \param descriptor
* The ping/pong descriptor.
*
* \return
* The Retrigger setting \ref cy_en_dmac_retrigger_t.
*
* \funcusage
* \snippet dmac_snippet.c snippet_Cy_DMAC_Descriptor_GetterFunctions
*
*******************************************************************************/
__STATIC_INLINE cy_en_dmac_retrigger_t Cy_DMAC_Descriptor_GetRetrigger(DMAC_Type const * base,
                                                                       uint32_t channel,
                                                                       cy_en_dmac_descriptor_t descriptor)
{
    CY_ASSERT_L1(CY_DMAC_IS_CH_NR_VALID(channel));
    CY_ASSERT_L3(CY_DMAC_IS_DESCR_VALID(descriptor));
    return((cy_en_dmac_retrigger_t) _FLD2VAL(DMAC_DESCR_PONG_CTL_WAIT_FOR_DEACT, DMAC_DESCR_GET_CTL(base, channel, descriptor)));
}


/*******************************************************************************
* Function Name: Cy_DMAC_Descriptor_SetFlipping
****************************************************************************//**
*
* Enables/disables the descriptor flipping parameter of the specified descriptor.
*
* \param base
* The pointer to the hardware DMAC block.
*
* \param channel
* The channel number.
*
* \param descriptor
* The ping/pong descriptor.
*
* \param flipping
* Enable descriptor flipping.
*
* \funcusage
* \snippet dmac_snippet.c snippet_Cy_DMAC_Descriptor_SetterFunctions
*
*******************************************************************************/
__STATIC_INLINE void Cy_DMAC_Descriptor_SetFlipping(DMAC_Type * base,
                                                       uint32_t channel,
                                        cy_en_dmac_descriptor_t descriptor,
                                                           bool flipping)
{
    CY_ASSERT_L1(CY_DMAC_IS_CH_NR_VALID(channel));
    CY_ASSERT_L3(CY_DMAC_IS_DESCR_VALID(descriptor));

    uint32_t reg;
    reg = _CLR_SET_FLD32U(DMAC_DESCR_GET_CTL(base, channel, descriptor), DMAC_DESCR_PONG_CTL_FLIPPING, (uint32_t) flipping);
    DMAC_DESCR_SET_CTL(base, channel, descriptor, reg);
}


/*******************************************************************************
* Function Name: Cy_DMAC_Descriptor_GetFlipping
****************************************************************************//**
*
* Returns the flipping parameter of the specified descriptor.
*
* \param base
* The pointer to the hardware DMAC block.
*
* \param channel
* The channel number.
*
* \param descriptor
* The ping/pong descriptor.
*
* \return
* The flipping mode.
*
* \funcusage
* \snippet dmac_snippet.c snippet_Cy_DMAC_Descriptor_GetterFunctions
*
*******************************************************************************/
__STATIC_INLINE bool Cy_DMAC_Descriptor_GetFlipping(DMAC_Type const * base,
                                                    uint32_t channel,
                                                    cy_en_dmac_descriptor_t descriptor)
{
    CY_ASSERT_L1(CY_DMAC_IS_CH_NR_VALID(channel));
    CY_ASSERT_L3(CY_DMAC_IS_DESCR_VALID(descriptor));

    return(_FLD2BOOL(DMAC_DESCR_PONG_CTL_FLIPPING, DMAC_DESCR_GET_CTL(base, channel, descriptor)));
}

/*******************************************************************************
* Function Name: Cy_DMAC_Descriptor_SetTriggerType
****************************************************************************//**
*
* Sets the mode of the specified descriptor
*
* \param base
* The pointer to the hardware DMAC block.
*
* \param channel
* The channel number.
*
* \param descriptor
* The ping/pong descriptor.
*
* \param triggerType
* The descriptor trigger type, see \ref cy_en_dmac_trigger_type_t.
*
* \funcusage
* \snippet dmac_snippet.c snippet_Cy_DMAC_Descriptor_SetterFunctions
*
*******************************************************************************/
__STATIC_INLINE void Cy_DMAC_Descriptor_SetTriggerType (DMAC_Type * base,
                                                           uint32_t channel,
                                            cy_en_dmac_descriptor_t descriptor,
                                          cy_en_dmac_trigger_type_t triggerType)
{
    CY_ASSERT_L1(CY_DMAC_IS_CH_NR_VALID(channel));
    CY_ASSERT_L3(CY_DMAC_IS_DESCR_VALID(descriptor));
    CY_ASSERT_L3(CY_DMAC_IS_TRIG_TYPE_VALID(triggerType));

    uint32_t reg = _CLR_SET_FLD32U(DMAC_DESCR_GET_CTL(base, channel, descriptor), DMAC_DESCR_PONG_CTL_OPCODE, triggerType);
    DMAC_DESCR_SET_CTL(base, channel, descriptor, reg);
}


/*******************************************************************************
* Function Name: Cy_DMAC_Descriptor_GetTriggerType
****************************************************************************//**
*
* Returns the mode of the specified descriptor
*
* \param base
* The pointer to the hardware DMAC block.
*
* \param channel
* The channel number.
*
* \param descriptor
* The ping/pong descriptor.
*
* \return
* The descriptor trigger type \ref cy_en_dmac_trigger_type_t
*
* \funcusage
* \snippet dmac_snippet.c snippet_Cy_DMAC_Descriptor_GetterFunctions
*
*******************************************************************************/
__STATIC_INLINE cy_en_dmac_trigger_type_t Cy_DMAC_Descriptor_GetTriggerType (DMAC_Type const * base,
                                                                                      uint32_t channel,
                                                                       cy_en_dmac_descriptor_t descriptor)
{
    CY_ASSERT_L1(CY_DMAC_IS_CH_NR_VALID(channel));
    CY_ASSERT_L3(CY_DMAC_IS_DESCR_VALID(descriptor));

    return ((cy_en_dmac_trigger_type_t) _FLD2VAL(DMAC_DESCR_PONG_CTL_OPCODE, DMAC_DESCR_GET_CTL(base, channel, descriptor)));
}


/*******************************************************************************
* Function Name: Cy_DMAC_Descriptor_SetSrcIncrement
****************************************************************************//**
*
* Sets the source increment parameter for the specified descriptor.
*
* \param base
* The pointer to the hardware DMAC block.
*
* \param channel
* The channel number.
*
* \param descriptor
* The ping/pong descriptor.
*
* \param increment
* The value of the source increment parameter,
* true - the address increment is enabled.
*
* \funcusage
* \snippet dmac_snippet.c snippet_Cy_DMAC_Descriptor_SetterFunctions
*
*******************************************************************************/
__STATIC_INLINE void Cy_DMAC_Descriptor_SetSrcIncrement(DMAC_Type * base,
                                                           uint32_t channel,
                                            cy_en_dmac_descriptor_t descriptor,
                                                               bool increment)
{
    CY_ASSERT_L1(CY_DMAC_IS_CH_NR_VALID(channel));
    CY_ASSERT_L3(CY_DMAC_IS_DESCR_VALID(descriptor));

    uint32_t reg;
    reg = _CLR_SET_FLD32U(DMAC_DESCR_GET_CTL(base, channel, descriptor), DMAC_DESCR_PONG_CTL_SRC_ADDR_INCR, (increment ? 1UL : 0UL));
    DMAC_DESCR_SET_CTL(base, channel, descriptor, reg);
}


/*******************************************************************************
* Function Name: Cy_DMAC_Descriptor_GetSrcIncrement
****************************************************************************//**
*
* Returns the source increment parameter for the specified descriptor.
*
* \param base
* The pointer to the hardware DMAC block.
*
* \param channel
* The channel number.
*
* \param descriptor
* The ping/pong descriptor.
*
* \return
* The value of the source increment parameter,
* true - the address increment is enabled.
*
* \funcusage
* \snippet dmac_snippet.c snippet_Cy_DMAC_Descriptor_GetterFunctions
*
*******************************************************************************/
__STATIC_INLINE bool Cy_DMAC_Descriptor_GetSrcIncrement(DMAC_Type const * base,
                                                        uint32_t channel,
                                                        cy_en_dmac_descriptor_t descriptor)
{
    CY_ASSERT_L1(CY_DMAC_IS_CH_NR_VALID(channel));
    CY_ASSERT_L3(CY_DMAC_IS_DESCR_VALID(descriptor));

    return(_FLD2BOOL(DMAC_DESCR_PONG_CTL_SRC_ADDR_INCR, DMAC_DESCR_GET_CTL(base, channel, descriptor)));
}


/*******************************************************************************
* Function Name: Cy_DMAC_Descriptor_SetDstIncrement
****************************************************************************//**
*
* Sets the destination increment parameter for the specified descriptor.
*
* \param base
* The pointer to the hardware DMAC block.
*
* \param channel
* The channel number.
*
* \param descriptor
* The ping/pong descriptor.
*
* \param increment
* The value of the destination increment parameter,
* true - the address increment is enabled.
*
* \funcusage
* \snippet dmac_snippet.c snippet_Cy_DMAC_Descriptor_SetterFunctions
*
*******************************************************************************/
__STATIC_INLINE void Cy_DMAC_Descriptor_SetDstIncrement(DMAC_Type * base,
                                                           uint32_t channel,
                                            cy_en_dmac_descriptor_t descriptor,
                                                               bool increment)
{
    CY_ASSERT_L1(CY_DMAC_IS_CH_NR_VALID(channel));
    CY_ASSERT_L3(CY_DMAC_IS_DESCR_VALID(descriptor));

    uint32_t reg;
    reg = _CLR_SET_FLD32U(DMAC_DESCR_GET_CTL(base, channel, descriptor), DMAC_DESCR_PING_CTL_DST_ADDR_INCR, (increment ? 1UL : 0UL));
    DMAC_DESCR_SET_CTL(base, channel, descriptor, reg);
}


/*******************************************************************************
* Function Name: Cy_DMAC_Descriptor_GetDstIncrement
****************************************************************************//**
*
* Returns the destination increment parameter for the specified descriptor.
*
* \param base
* The pointer to the hardware DMAC block.
*
* \param channel
* The channel number.
*
* \param descriptor
* The ping/pong descriptor.
*
* \return
* The value of the destination increment parameter,
* true - the address increment is enabled.
*
* \funcusage
* \snippet dmac_snippet.c snippet_Cy_DMAC_Descriptor_GetterFunctions
*
*******************************************************************************/
__STATIC_INLINE bool Cy_DMAC_Descriptor_GetDstIncrement (DMAC_Type const * base,
                                                                  uint32_t channel,
                                                   cy_en_dmac_descriptor_t descriptor)
{
    CY_ASSERT_L1(CY_DMAC_IS_CH_NR_VALID(channel));
    CY_ASSERT_L3(CY_DMAC_IS_DESCR_VALID(descriptor));

    return(_FLD2BOOL(DMAC_DESCR_PONG_CTL_DST_ADDR_INCR, DMAC_DESCR_GET_CTL(base, channel, descriptor)));
}


/*******************************************************************************
* Function Name: Cy_DMAC_Descriptor_GetCurrentIndex
****************************************************************************//**
*
* Returns the current transfer data element index of the specified descriptor.
*
* \param base
* The pointer to the hardware DMAC block.
*
* \param channel
* The channel number.
*
* \param descriptor
* The ping/pong descriptor.
*
* \return
* Returns the current transfer index for the desired descriptor.
*
* \funcusage
* \snippet dmac_snippet.c snippet_Cy_DMAC_Channel_GetCurrentDescriptorIndex
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_DMAC_Descriptor_GetCurrentIndex (DMAC_Type const * base,
                                                                      uint32_t channel,
                                                       cy_en_dmac_descriptor_t descriptor)
{
    CY_ASSERT_L1(CY_DMAC_IS_CH_NR_VALID(channel));
    CY_ASSERT_L3(CY_DMAC_IS_DESCR_VALID(descriptor));

    return _FLD2VAL(DMAC_DESCR_PING_STATUS_CURR_DATA_NR, DMAC_DESCR_GET_STATUS(base, channel, descriptor));
}


/*******************************************************************************
* Function Name: Cy_DMAC_Descriptor_GetResponse
****************************************************************************//**
*
* Returns the last transfer response code.
*
* \param base
* The pointer to the hardware DMAC block.
*
* \param channel
* The channel number.
*
* \param descriptor
* The ping/pong descriptor.
*
* \return
* Returns the response code \ref cy_en_dmac_response_t.
*
* \funcusage
* \snippet dmac_snippet.c snippet_Cy_DMAC_SetState
*
*******************************************************************************/
__STATIC_INLINE cy_en_dmac_response_t Cy_DMAC_Descriptor_GetResponse (DMAC_Type const * base,
                                                                               uint32_t channel,
                                                                cy_en_dmac_descriptor_t descriptor)
{
    CY_ASSERT_L1(CY_DMAC_IS_CH_NR_VALID(channel));
    CY_ASSERT_L3(CY_DMAC_IS_DESCR_VALID(descriptor));

    return ((cy_en_dmac_response_t) _FLD2VAL(DMAC_DESCR_PING_STATUS_RESPONSE, DMAC_DESCR_GET_STATUS(base, channel, descriptor)));
CY_MISRA_BLOCK_END('MISRA C-2012 Rule 10.8');
}


/*******************************************************************************
* Function Name: Cy_DMAC_Descriptor_SetPreemptable
****************************************************************************//**
*
* Sets the preemptable value for the specified descriptor.
*
* \param base
* The pointer to the hardware DMAC block.
*
* \param channel
* The channel number.
*
* \param descriptor
* The ping/pong descriptor.
*
* \param preemptable
* The preemptable control value: true - enabled, false - disabled.
*
* \funcusage
* \snippet dmac_snippet.c snippet_Cy_DMAC_Descriptor_SetterFunctions
*
*******************************************************************************/
__STATIC_INLINE void Cy_DMAC_Descriptor_SetPreemptable (DMAC_Type * base,
                                                           uint32_t channel,
                                            cy_en_dmac_descriptor_t descriptor,
                                                               bool preemptable)
{
    CY_ASSERT_L1(CY_DMAC_IS_CH_NR_VALID(channel));
    CY_ASSERT_L3(CY_DMAC_IS_DESCR_VALID(descriptor));

    uint32_t locReg = _CLR_SET_FLD32U(DMAC_DESCR_GET_CTL(base, channel, descriptor), DMAC_DESCR_PING_CTL_PREEMPTABLE, (preemptable ? 1UL : 0UL));
    DMAC_DESCR_SET_CTL(base, channel, descriptor, locReg);
}


/*******************************************************************************
* Function Name: Cy_DMAC_Descriptor_GetPreemptable
****************************************************************************//**
*
* Returns the preemptable value for the specified descriptor.
*
* \param base
* The pointer to the hardware DMAC block.
*
* \param channel
* The channel number.
*
* \param descriptor
* The ping/pong descriptor.
*
* \return
* The preemptable control value: true - enabled, false - disabled.
*
* \funcusage
* \snippet dmac_snippet.c snippet_Cy_DMAC_Descriptor_GetterFunctions
*
*******************************************************************************/
__STATIC_INLINE bool Cy_DMAC_Descriptor_GetPreemptable (DMAC_Type const * base,
                                                                 uint32_t channel,
                                                  cy_en_dmac_descriptor_t descriptor)
{
    CY_ASSERT_L1(CY_DMAC_IS_CH_NR_VALID(channel));
    CY_ASSERT_L3(CY_DMAC_IS_DESCR_VALID(descriptor));

    return (_FLD2BOOL(DMAC_DESCR_PING_CTL_PREEMPTABLE, DMAC_DESCR_GET_CTL(base, channel, descriptor)));
}


/*******************************************************************************
* Function Name: Cy_DMAC_Descriptor_SetCpltState
****************************************************************************//**
*
* Sets the invalidate value for the specified descriptor.
* If true - the descriptor will be invalidated on completion.
*
* \param base
* The pointer to the hardware DMAC block.
*
* \param channel
* The channel number.
*
* \param descriptor
* The ping/pong descriptor.
*
* \param invalidate
* The invalidate control value: true - enabled, false - disabled.
*
* \funcusage
* \snippet dmac_snippet.c snippet_Cy_DMAC_Descriptor_SetterFunctions
*
*******************************************************************************/
__STATIC_INLINE void Cy_DMAC_Descriptor_SetCpltState(DMAC_Type * base,
                                                        uint32_t channel,
                                         cy_en_dmac_descriptor_t descriptor,
                                                            bool invalidate)
{
    CY_ASSERT_L1(CY_DMAC_IS_CH_NR_VALID(channel));
    CY_ASSERT_L3(CY_DMAC_IS_DESCR_VALID(descriptor));

    uint32_t locReg = _CLR_SET_FLD32U(DMAC_DESCR_GET_CTL(base, channel, descriptor), DMAC_DESCR_PING_CTL_INV_DESCR, (invalidate ? 1UL : 0UL));
    DMAC_DESCR_SET_CTL(base, channel, descriptor, locReg);
}


/*******************************************************************************
* Function Name: Cy_DMAC_Descriptor_GetCpltState
****************************************************************************//**
*
* Returns the completion state parameter for the specified descriptor.
* If true - the descriptor will be invalidated on completion.
*
* \param base
* The pointer to the hardware DMAC block.
*
* \param channel
* The channel number.
*
* \param descriptor
* The ping/pong descriptor.
*
* \return
* Returns the invalidate control value: true - enabled, false - disabled.
*
* \funcusage
* \snippet dmac_snippet.c snippet_Cy_DMAC_Descriptor_GetterFunctions
*
*******************************************************************************/
__STATIC_INLINE bool Cy_DMAC_Descriptor_GetCpltState(DMAC_Type const * base,
                                                              uint32_t channel,
                                               cy_en_dmac_descriptor_t descriptor)
{
    CY_ASSERT_L1(CY_DMAC_IS_CH_NR_VALID(channel));
    CY_ASSERT_L3(CY_DMAC_IS_DESCR_VALID(descriptor));

    return (_FLD2BOOL(DMAC_DESCR_PING_CTL_INV_DESCR, DMAC_DESCR_GET_CTL(base, channel, descriptor)));
}


/** \} group_dmac_descriptor_functions */

/**
* \addtogroup group_dmac_channel_functions
* \{
*/


/*******************************************************************************
* Function Name: Cy_DMAC_Channel_SetCurrentDescriptor
****************************************************************************//**
*
* Sets a descriptor as current for the specified DMAC channel.
*
* \param base
* The pointer to the hardware DMAC block.
*
* \param channel
* The channel number.
*
* \param descriptor
* The descriptor to be associated with the channel.
*
* \funcusage
* \snippet dmac_snippet.c snippet_Cy_DMAC_InvalidateDescriptor
*
*******************************************************************************/
__STATIC_INLINE void Cy_DMAC_Channel_SetCurrentDescriptor(DMAC_Type * base,
                                                             uint32_t channel,
                                              cy_en_dmac_descriptor_t descriptor)
{
    CY_ASSERT_L1(CY_DMAC_IS_CH_NR_VALID(channel));

    DMAC_CH_CTL(base, channel) = _CLR_SET_FLD32U(DMAC_CH_CTL(base, channel),DMAC_CH_CTL_PING_PONG, descriptor);
}


/*******************************************************************************
* Function Name: Cy_DMAC_Channel_Enable
****************************************************************************//**
*
* Enables a DMAC channel.
*
* \param base
* The pointer to the hardware DMAC block.
*
* \param channel
* The  channel number.
*
* \funcusage
* \snippet dmac_snippet.c snippet_Cy_DMAC_Enable
*
*******************************************************************************/
__STATIC_INLINE void Cy_DMAC_Channel_Enable(DMAC_Type * base, uint32_t channel)
{
    CY_ASSERT_L1(CY_DMAC_IS_CH_NR_VALID(channel));

    DMAC_CH_CTL(base, channel) |= DMAC_CH_CTL_ENABLED_Msk;
}


/*******************************************************************************
* Function Name: Cy_DMAC_Channel_Disable
****************************************************************************//**
*
* Disables a DMAC channel.
*
* \param base
* The pointer to the hardware DMAC block.
*
* \param channel
* The channel number.
*
* \funcusage
* \snippet dmac_snippet.c snippet_Cy_DMAC_Disable
*
*******************************************************************************/
__STATIC_INLINE void Cy_DMAC_Channel_Disable(DMAC_Type * base, uint32_t channel)
{
    CY_ASSERT_L1(CY_DMAC_IS_CH_NR_VALID(channel));

    DMAC_CH_CTL(base, channel) &= (uint32_t) ~DMAC_CH_CTL_ENABLED_Msk;
}


/*******************************************************************************
* Function Name: Cy_DMAC_Channel_SetPriority
****************************************************************************//**
*
* The function is used to set a priority for the DMAC channel.
*
* \param base
* The pointer to the hardware DMAC block.
*
* \param channel
* The channel number.
*
* \param priority
* The priority to be set for the DMAC channel. The allowed values are 0,1,2,3,
* with "0" representing the highest priority and "3" representing the lowest priority
*
* \funcusage
* \snippet dmac_snippet.c snippet_Cy_DMAC_Disable
*
*******************************************************************************/
__STATIC_INLINE void Cy_DMAC_Channel_SetPriority(DMAC_Type * base, uint32_t channel, uint32_t priority)
{
    CY_ASSERT_L1(CY_DMAC_IS_CH_NR_VALID(channel));
    CY_ASSERT_L2(CY_DMAC_IS_PRIORITY_VALID(priority));

    DMAC_CH_CTL(base, channel) = _CLR_SET_FLD32U(DMAC_CH_CTL(base, channel), DMAC_CH_CTL_PRIO, priority);
}


/*******************************************************************************
* Function Name: Cy_DMAC_Channel_GetPriority
****************************************************************************//**
*
* Returns the priority of the DMAC channel.
*
* \param base
* The pointer to the hardware DMAC block.
*
* \param channel
* The channel number.
*
* \return
* The priority of the channel.
*
* \funcusage
* \snippet dmac_snippet.c snippet_Cy_DMAC_Disable
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_DMAC_Channel_GetPriority(DMAC_Type const * base, uint32_t channel)
{
     CY_ASSERT_L1(CY_DMAC_IS_CH_NR_VALID(channel));

     return ((uint32_t) _FLD2VAL(DMAC_CH_CTL_PRIO, DMAC_CH_CTL(base, channel)));
}


/*******************************************************************************
* Function Name: Cy_DMAC_Channel_GetCurrentDescriptor
****************************************************************************//**
*
* Returns the descriptor, which is active in the channel at the moment.
*
* \param base
* The pointer to the hardware DMAC block.
*
* \param channel
* The channel number.
*
* \return
* The active descriptor.
*
* \funcusage
* \snippet dmac_snippet.c snippet_Cy_DMAC_Descriptor_Deinit
*
*******************************************************************************/
__STATIC_INLINE cy_en_dmac_descriptor_t Cy_DMAC_Channel_GetCurrentDescriptor(DMAC_Type const * base, uint32_t channel)
{
    uint32_t channelType;
    CY_ASSERT_L1(CY_DMAC_IS_CH_NR_VALID(channel));

    channelType = _FLD2VAL(DMAC_CH_CTL_PING_PONG, DMAC_CH_CTL(base, channel));
    return  ((uint32_t)CY_DMAC_DESCRIPTOR_PING == channelType)? CY_DMAC_DESCRIPTOR_PING:
                                                                CY_DMAC_DESCRIPTOR_PONG;
}

/** \} group_dmac_channel_functions */

/** \} group_dmac_functions */

#if defined(__cplusplus)
}
#endif

#endif /* defined(CY_IP_M0S8CPUSSV3_DMAC) */

#endif  /* !defined(CY_DMAC_H) */

/** \} group_dmac */


/* [] END OF FILE */
