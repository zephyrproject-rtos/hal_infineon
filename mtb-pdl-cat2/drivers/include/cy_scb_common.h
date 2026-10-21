/***************************************************************************//**
* \file cy_scb_common.h
* \version 4.70
*
* Provides common API declarations of the SCB driver.
*
********************************************************************************
* \copyright
* (c) (2016-2025), Cypress Semiconductor Corporation (an Infineon company) or
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
* \addtogroup group_scb
* \{
* The Serial Communications Block (SCB) supports three serial communication
* protocols: Serial Peripheral Interface (SPI), Universal Asynchronous Receiver
* Transmitter (UART), and Inter Integrated Circuit (I2C or IIC). Only one of
* the protocols is supported by an SCB at any given time.
*
* The functions and other declarations used in this driver are in cy_scb_spi.h,
* cy_scb_uart.h, cy_scb_ezi2c.h, cy_scb_i2c.h respectively. Include cy_pdl.h
* to get access to all functions and declarations in the PDL.

* \defgroup group_scb_common Common
* \defgroup group_scb_ezi2c  EZI2C (SCB)
* \defgroup group_scb_i2c    I2C (SCB)
* \defgroup group_scb_spi    SPI (SCB)
* \defgroup group_scb_uart   UART (SCB)
* \} */

/**
* \addtogroup group_scb
* \{
*
********************************************************************************
* \section group_scb_more_information More Information
********************************************************************************
* For more information on the SCB peripheral, refer to the technical reference
* manual (TRM).
*
*******************************************************************************
* \section group_scb_common_changelog Changelog
*******************************************************************************
* <table class="doxtable">
*   <tr><th>Version</th><th>Changes</th><th>Reason for Change</th></tr>
*   <tr>
*     <td>4.70</td>
*     <td>EZI2C: Fixed issue with the address being interpreted as a data byte if
*         the interrupt is not handled in time, particularly when the transfer has
*         a Repeated Start or when several transfers are initiated one-by-one with
*         the minimal time interval. Applicable only if two addresses are enabled.</td>
*     <td>Bug fix.</td>
*   </tr>
*   <tr>
*     <td>4.60</td>
*     <td>I2C: In SlaveHandleStop, discard the data in RxFifo, if address match
*         Interrupt is not set.</td>
*     <td>Functionality improvement.</td>
*   </tr>
*   <tr>
*     <td>4.50</td>
*     <td>I2C: Interrupt logic updated to handle the slave not ready condition.
*         Provided new function \ref Cy_SCB_I2C_SlaveSendAckNack() that the
*         user application can send ACK/NACK and configure buffer.</td>
*     <td>Functionality improvement.</td>
*   </tr>
*   <tr>
*     <td rowspan="3">4.40</td>
*     <td>SPI: Provided new functions to define a custom value
*         of the default TX value when no TX buffer is defined:
*              \ref Cy_SCB_SPI_SetTxDefaultValue(),
*              \ref Cy_SCB_SPI_GetTxDefaultValue().</td>
*     <td>High-Level API improvement.</td>
*   </tr>
*   <tr>
*     <td>I2C: Added a new documentation section about
*         \ref group_scb_i2c_mclk_sync.</td>
*     <td>Documentation enhancement.</td>
*   </tr>
*   <tr>
*     <td>Minor documentation updates.</td>
*     <td>Documentation enhancement.</td>
*   </tr>
*   <tr>
*     <td rowspan="2">4.30</td>
*     <td>Changed __STATIC_INLINE functions attribute to __STATIC_FORCEINLINE
*              for the functions:
*              \ref Cy_SCB_ReadRxFifo,
*              \ref Cy_SCB_WriteTxFifo</td>
*     <td>Improve compiler compatibility</td>
*   </tr>
*   <tr>
*     <td>Fixed no zeroing of the buffer size of the secondary slave in the
*              \ref Cy_SCB_EZI2C_Init() function.</td>
*     <td>Bug fix.</td>
*   </tr>
*   <tr>
*     <td>4.20</td>
*     <td>The \ref Cy_SCB_EZI2C_DeepSleepCallback,
*             \ref Cy_SCB_I2C_DeepSleepCallback, 
*             \ref Cy_SCB_SPI_DeepSleepCallback, and 
*             \ref Cy_SCB_UART_DeepSleepCallback parameter types are changed
*             to match the \ref cy_stc_syspm_callback_t::callback type.</td>
*     <td>Eliminate compiler warnings</td>
*   </tr>
*   <tr>
*     <td>4.10</td>
*     <td>SPI: Fixed the issue when SPI Master and Slave interrupts are not
*         enabled by the \ref Cy_SCB_SPI_Init() function.</td>
*     <td>Bug fixes.</td>
*   </tr>
*   <tr>
*     <td rowspan="3">4.0</td>
*     <td>Update the paths to the code snippets.</td>
*     <td>PDL structure update.</td>
*   </tr>
*   <tr>
*     <td>Minor documentation updates. Code snippets were updated.</td>
*     <td>Documentation enhancement.</td>
*   </tr>
*   <tr>
*     <td>I2C: Removed the unused members of the configuration structure.</td>
*     <td>Reduced the memory footprint.</td>
*   </tr>
*   <tr>
*     <td rowspan="3">3.20</td>
*     <td>UART: Newly added API's for runtime parameter set/get functionality:
*         \ref Cy_SCB_UART_SetOverSample to set oversample bits of UART,
*         \ref Cy_SCB_UART_GetOverSample to add return value of oversample.</td>
*     <td>To improve functionality.</td>
*   </tr>
*   <tr>
*     <td>UART: Fixed an issue with sending short transactions on high
*         baud rates.</td>
*     <td></td>
*   </tr>
*   <tr>
*     <td>I2C: Fixed the defect in the \ref Cy_SCB_I2C_MasterAbortWrite()
*         function to prevent device stuck in the \ref CY_SCB_I2C_MASTER_BUSY
*         state on some devices.</td>
*     <td></td>
*   </tr>
*   <tr>
*     <td rowspan="5">3.10</td>
*     <td>I2C: Fixed the issue when an address byte is treated as a data byte
*         with an enabled Accepting address in the FIFO option.
*         For the PSOC P4000S, P4100S, P4100S Plus, and PSOC 4500S devices,
*         added the parameter to \ref cy_stc_scb_i2c_config_t to configure
*         a delay after the Address Match event.</td>
*     <td>To improve the Accepting address in FIFO, if enabled.</td>
*   </tr>
*   <tr>
*     <td>SPI: Fixed the parity error report for High-Level functions.
*         As a result, the registered callback function reports the
*         CY_SCB_SPI_TRANSFER_ERR_EVENT event and
*         Cy_SCB_SPI_GetTransferStatus() returns CY_SCB_SPI_RX_ERR_PARITY when
*         a parity error happens.
*         </td>
*     <td>Earlier, High-level functions didn't report about parity errors.</td>
*   </tr>
*   <tr>
*     <td>SPI: Added information that for the PSOC 4000S, PSOC 4100S,
*        PSOC 4100 Plus, and PSOC 4500S series, the SPI in Motorola mode
*        generates a spare \ref CY_SCB_TX_INTR_UNDERFLOW interrupt at the end
*        of the transmission (the TX FIFO buffer is empty and no additional
*        data is requested by Master) in \ref CY_SCB_SPI_CPHA0_CPOL0
*        and \ref CY_SCB_SPI_CPHA1_CPOL0 SCLK modes.</td>
*     <td>Documentation updates.</td>
*   </tr>
*   <tr>
*     <td>SPI: Now Cy_SCB_SPI_Transfer() clears RX FIFO buffer before start of
*         the transfer.</td>
*     <td>High-Level API operation improvement.</td>
*   </tr>
*   <tr>
*     <td>Minor documentation updates.</td>
*     <td>Documentation enhancement.</td>
*   </tr>
*   <tr>
*     <td rowspan="3">3.0.1</td>
*     <td>UART: Added information that for PSOC 4000S, PSOC 4100S, PSOC 4100S
*         Plus, and PSOC 4500S series, a stop bits error is detected only if
*         the stop bits length equals or exceeds 1.5 bits.</td>
*     <td>Documentation updates.</td>
*   </tr>
*   <tr>
*     <td>UART: Added information that for PSOC 4000S, PSOC 4100S, PSOC 4100S
*         Plus, and PSOC 4500S series, the actual break width may be up to one
*         bit less than the specified break width.</td>
*     <td>Documentation updates.</td>
*   </tr>
*   <tr>
*     <td>Minor documentation updates.</td>
*     <td>Documentation enhancement.</td>
*   </tr>
*   <tr>
*     <td rowspan="2">3.0</td>
*     <td>Added support of SCB blocks with FIFO buffers size other than 32 byte.</td>
*     <td>New device support.</td>
*   </tr>
*   <tr>
*     <td>Added \ref Cy_SCB_UART_GetBaudRateCount() to get number of peripheral
*         clock periods that constitutes the transmission of the LIN's sync byte. \n
*         Added enableLinMode member to \ref cy_stc_scb_uart_config_t.
*         \note enableLinMode has effect on \ref CY_SCB_UART_TX_ARB_LOST and
*         \ref CY_SCB_UART_RX_BREAK_DETECT interrupts.
*     </td>
*     <td>LIN mode support.</td>
*   </tr>
*   <tr>
*     <td rowspan="5">2.0</td>
*     <td>Added new features:
*         - High-speed mode for I2C Slave
*         - SPI Parity
*         - Setup delay for SPI Master
*         - Hold delay for SPI Master
*         - Inter-dataframe delay for SPI Master
*         - UART break level
*
*         Updated interface of the Cy_SCB_I2C_Enable() by adding additional
*         parameter for the context.
*     </td>
*     <td>New device support.</td>
*   </tr>
*   <tr>
*     <td>Added new functions:
*         - Cy_SCB_EZI2C_RegisterDSClockConfig()
*         - Cy_SCB_I2C_RegisterDSClockConfig()
*         - Cy_SCB_SPI_RegisterDSClockConfig()
*
*         Modified following function:
*         - Cy_SCB_EZI2C_DeepSleepCallback()
*         - Cy_SCB_I2C_DeepSleepCallback()
*         - Cy_SCB_SPI_DeepSleepCallback()</td>
*     <td>Low power feature support.</td>
*   </tr>
*   <tr>
*     <td>Fixed the Cy_SCB_SPI_SetActiveSlaveSelectPolarity() function to properly
*         configure the polarity of the slave select line.</td>
*     <td>Defect fix.</td>
*   </tr>
*   <tr>
*     <td>Minor documentation updates.</td>
*     <td>Documentation enhancement.</td>
*   </tr>
*   <tr>
*     <td>Fixed MISRA violations.</td>
*     <td>MISRA compliance.</td>
*   </tr>
*   <tr>
*     <td>1.0</td>
*     <td>Initial version.</td>
*     <td></td>
*   </tr>
* </table>
*/
/** \} group_scb */

/**
* \addtogroup group_scb_common
* \{
*
* Common API for the Serial Communication Block.
*
* This is the common API that provides an interface to the SCB hardware.
* The I2C, SPI, and UART drivers use this common API.
* Most users will use individual drivers and do not need to use the common
* API for the SCB. However, you can use the common SCB API to implement
* a custom driver based on the SCB hardware.
*
* The functions and other declarations used in this part of the driver are in
* cy_scb_common.h. You can include either of cy_scb_spi.h, cy_scb_uart.h,
* cy_scb_ezi2c.h, cy_scb_i2c.h depending on the desired functionality.
* You can also include cy_pdl.h to get access to all functions and declarations
* in the PDL.
*
*******************************************************************************
* \section group_scb_common_configuration Configuration Considerations
********************************************************************************
* This is not a driver and it does not require configuration.
*
* \defgroup group_scb_common_macros Macros
* \defgroup group_scb_common_functions Functions
* \defgroup group_scb_common_data_structures Data Structures
*
*/

#if !defined(CY_SCB_COMMON_H)
#define CY_SCB_COMMON_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include "cy_device.h"
#include "cy_syslib.h"
#include "cy_syspm.h"

#if defined (CY_IP_M0S8SCB) || defined (CY_IP_MXSCB)

#if defined(__cplusplus)
extern "C" {
#endif


/*******************************************************************************
*                            Function Prototypes
*******************************************************************************/

/**
* \addtogroup group_scb_common_functions
* \{
*/
__STATIC_FORCEINLINE uint32_t Cy_SCB_ReadRxFifo    (CySCB_Type const *base);
__STATIC_INLINE void     Cy_SCB_SetRxFifoLevel(CySCB_Type *base, uint32_t level);
__STATIC_INLINE uint32_t Cy_SCB_GetNumInRxFifo(CySCB_Type const *base);
__STATIC_INLINE uint32_t Cy_SCB_GetRxSrValid  (CySCB_Type const *base);
__STATIC_INLINE void     Cy_SCB_ClearRxFifo   (CySCB_Type *base);

__STATIC_FORCEINLINE void     Cy_SCB_WriteTxFifo   (CySCB_Type *base, uint32_t data);
__STATIC_INLINE void     Cy_SCB_SetTxFifoLevel(CySCB_Type *base, uint32_t level);
__STATIC_INLINE uint32_t Cy_SCB_GetNumInTxFifo(CySCB_Type const *base);
__STATIC_INLINE uint32_t Cy_SCB_GetTxSrValid  (CySCB_Type const *base);
__STATIC_INLINE bool     Cy_SCB_IsTxComplete  (CySCB_Type const *base);
__STATIC_INLINE void     Cy_SCB_ClearTxFifo   (CySCB_Type *base);

__STATIC_INLINE void     Cy_SCB_SetByteMode(CySCB_Type *base, bool byteMode);

__STATIC_INLINE uint32_t Cy_SCB_GetInterruptCause(CySCB_Type const *base);

__STATIC_INLINE uint32_t Cy_SCB_GetRxInterruptStatus(CySCB_Type const *base);
__STATIC_INLINE void     Cy_SCB_SetRxInterruptMask  (CySCB_Type *base, uint32_t interruptMask);
__STATIC_INLINE uint32_t Cy_SCB_GetRxInterruptMask  (CySCB_Type const *base);
__STATIC_INLINE uint32_t Cy_SCB_GetRxInterruptStatusMasked(CySCB_Type const *base);
__STATIC_INLINE void     Cy_SCB_ClearRxInterrupt    (CySCB_Type *base, uint32_t interruptMask);
__STATIC_INLINE void     Cy_SCB_SetRxInterrupt      (CySCB_Type *base, uint32_t interruptMask);

__STATIC_INLINE uint32_t Cy_SCB_GetTxInterruptStatus(CySCB_Type const *base);
__STATIC_INLINE void     Cy_SCB_SetTxInterruptMask  (CySCB_Type *base, uint32_t interruptMask);
__STATIC_INLINE uint32_t Cy_SCB_GetTxInterruptMask  (CySCB_Type const *base);
__STATIC_INLINE uint32_t Cy_SCB_GetTxInterruptStatusMasked(CySCB_Type const *base);
__STATIC_INLINE void     Cy_SCB_ClearTxInterrupt    (CySCB_Type *base, uint32_t interruptMask);
__STATIC_INLINE void     Cy_SCB_SetTxInterrupt      (CySCB_Type *base, uint32_t interruptMask);

__STATIC_INLINE uint32_t Cy_SCB_GetMasterInterruptStatus(CySCB_Type const *base);
__STATIC_INLINE void     Cy_SCB_SetMasterInterruptMask  (CySCB_Type *base, uint32_t interruptMask);
__STATIC_INLINE uint32_t Cy_SCB_GetMasterInterruptMask  (CySCB_Type const *base);
__STATIC_INLINE uint32_t Cy_SCB_GetMasterInterruptStatusMasked(CySCB_Type const *base);
__STATIC_INLINE void     Cy_SCB_ClearMasterInterrupt    (CySCB_Type *base, uint32_t interruptMask);
__STATIC_INLINE void     Cy_SCB_SetMasterInterrupt      (CySCB_Type *base, uint32_t interruptMask);

__STATIC_INLINE uint32_t Cy_SCB_GetSlaveInterruptStatus(CySCB_Type const *base);
__STATIC_INLINE void     Cy_SCB_SetSlaveInterruptMask  (CySCB_Type *base, uint32_t interruptMask);
__STATIC_INLINE uint32_t Cy_SCB_GetSlaveInterruptMask  (CySCB_Type const *base);
__STATIC_INLINE uint32_t Cy_SCB_GetSlaveInterruptStatusMasked(CySCB_Type const *base);
__STATIC_INLINE void     Cy_SCB_ClearSlaveInterrupt    (CySCB_Type *base, uint32_t interruptMask);
__STATIC_INLINE void     Cy_SCB_SetSlaveInterrupt      (CySCB_Type *base, uint32_t interruptMask);

__STATIC_INLINE uint32_t Cy_SCB_GetI2CInterruptStatus(CySCB_Type const *base);
__STATIC_INLINE void     Cy_SCB_SetI2CInterruptMask  (CySCB_Type *base, uint32_t interruptMask);
__STATIC_INLINE uint32_t Cy_SCB_GetI2CInterruptMask  (CySCB_Type const *base);
__STATIC_INLINE uint32_t Cy_SCB_GetI2CInterruptStatusMasked(CySCB_Type const *base);
__STATIC_INLINE void     Cy_SCB_ClearI2CInterrupt    (CySCB_Type *base, uint32_t interruptMask);

__STATIC_INLINE uint32_t Cy_SCB_GetSpiInterruptStatus(CySCB_Type const *base);
__STATIC_INLINE void     Cy_SCB_SetSpiInterruptMask  (CySCB_Type *base, uint32_t interruptMask);
__STATIC_INLINE uint32_t Cy_SCB_GetSpiInterruptMask  (CySCB_Type const *base);
__STATIC_INLINE uint32_t Cy_SCB_GetSpiInterruptStatusMasked(CySCB_Type const *base);
__STATIC_INLINE void     Cy_SCB_ClearSpiInterrupt    (CySCB_Type *base, uint32_t interruptMask);


/*******************************************************************************
*                         Internal Function Prototypes
*******************************************************************************/

/** \cond INTERNAL */
void     Cy_SCB_ReadArrayNoCheck  (CySCB_Type const *base, void *buffer, uint32_t size);
uint32_t Cy_SCB_ReadArray         (CySCB_Type const *base, void *buffer, uint32_t size);
void     Cy_SCB_ReadArrayBlocking (CySCB_Type const *base, void *buffer, uint32_t size);
uint32_t Cy_SCB_Write             (CySCB_Type *base, uint32_t data);
void     Cy_SCB_WriteArrayNoCheck (CySCB_Type *base, void const *buffer, uint32_t size);
uint32_t Cy_SCB_WriteArray        (CySCB_Type *base, void const *buffer, uint32_t size);
void     Cy_SCB_WriteArrayBlocking(CySCB_Type *base, void *buffer, uint32_t size);
void     Cy_SCB_WriteString       (CySCB_Type *base, char_t const string[]);
void     Cy_SCB_WriteDefaultArrayNoCheck(CySCB_Type *base, uint32_t txData, uint32_t size);
uint32_t Cy_SCB_WriteDefaultArray (CySCB_Type *base, uint32_t txData, uint32_t size);

__STATIC_INLINE uint32_t Cy_SCB_GetFifoSize (CySCB_Type const *base);
__STATIC_INLINE void     Cy_SCB_FwBlockReset(CySCB_Type *base);
__STATIC_INLINE bool     Cy_SCB_IsRxDataWidthByte(CySCB_Type const *base);
__STATIC_INLINE bool     Cy_SCB_IsTxDataWidthByte(CySCB_Type const *base);
__STATIC_INLINE uint32_t Cy_SCB_GetRxFifoLevel   (CySCB_Type const *base);
/** \endcond */

/** \} group_scb_common_functions */


/*******************************************************************************
*                        API Constants
*******************************************************************************/

/**
* \addtogroup group_scb_common_macros
* \{
*/

/** Driver major version */
#define CY_SCB_DRV_VERSION_MAJOR    (4)

/** Driver minor version */
#define CY_SCB_DRV_VERSION_MINOR    (70)

/** SCB driver identifier */
#define CY_SCB_ID           CY_PDL_DRV_ID(0x2AU)

/** Position for SCB driver sub mode */
#define CY_SCB_SUB_MODE_Pos (13UL)

/** EZI2C mode identifier */
#define CY_SCB_EZI2C_ID     (0x0UL << CY_SCB_SUB_MODE_Pos)

/** EZI2C mode identifier */
#define CY_SCB_I2C_ID       (0x1UL << CY_SCB_SUB_MODE_Pos)

/** EZI2C mode identifier */
#define CY_SCB_SPI_ID       (0x2UL << CY_SCB_SUB_MODE_Pos)

/** EZI2C mode identifier */
#define CY_SCB_UART_ID      (0x3UL << CY_SCB_SUB_MODE_Pos)

/**
* \defgroup group_scb_common_macros_intr_cause SCB Interrupt Causes
* \{
*/
/** Interrupt from Master interrupt sources */
#define CY_SCB_MASTER_INTR SCB_INTR_CAUSE_M_Msk

/** Interrupt from Slave interrupt sources  */
#define CY_SCB_SLAVE_INTR  SCB_INTR_CAUSE_S_Msk

/** Interrupt from TX interrupt sources */
#define CY_SCB_TX_INTR     SCB_INTR_CAUSE_TX_Msk

/** Interrupt from RX interrupt sources */
#define CY_SCB_RX_INTR     SCB_INTR_CAUSE_RX_Msk

/** Interrupt from I2C externally clocked interrupt sources */
#define CY_SCB_I2C_INTR    SCB_INTR_CAUSE_I2C_EC_Msk

/** Interrupt from SPI externally clocked interrupt sources */
#define CY_SCB_SPI_INTR    SCB_INTR_CAUSE_SPI_EC_Msk
/** \} group_scb_common_macros_intr_cause */

/**
* \defgroup group_scb_common_macros_tx_intr TX Interrupt Statuses
* \{
*/
/**
* The number of data elements in the TX FIFO is less than the value
* of the TX FIFO level
*/
#define CY_SCB_TX_INTR_LEVEL           SCB_INTR_TX_TRIGGER_Msk

/** The TX FIFO is not full */
#define CY_SCB_TX_INTR_NOT_FULL        SCB_INTR_TX_NOT_FULL_Msk

/** The TX FIFO is empty */
#define CY_SCB_TX_INTR_EMPTY           SCB_INTR_TX_EMPTY_Msk

/** An attempt to write to a full TX FIFO */
#define CY_SCB_TX_INTR_OVERFLOW        SCB_INTR_TX_OVERFLOW_Msk

/** An attempt to read from an empty TX FIFO */
#define CY_SCB_TX_INTR_UNDERFLOW       SCB_INTR_TX_UNDERFLOW_Msk

/** The UART transfer is complete: all data elements from the TX FIFO are sent
*/
#define CY_SCB_TX_INTR_UART_DONE       SCB_INTR_TX_UART_DONE_Msk

/** SmartCard only: UART received a NACK */
#define CY_SCB_TX_INTR_UART_NACK       SCB_INTR_TX_UART_NACK_Msk

/**
* SmartCard and LIN only: the value on the TX line of the UART does not match the
* value on the RX line
*/
#define CY_SCB_TX_INTR_UART_ARB_LOST   SCB_INTR_TX_UART_ARB_LOST_Msk
/** \} group_scb_common_macros_tx_intr */

/**
* \defgroup group_scb_common_macros_rx_intr RX Interrupt Statuses
* \{
*/
/**
* The number of data elements in the RX FIFO is greater than the value of the
* RX FIFO level
*/
#define CY_SCB_RX_INTR_LEVEL             SCB_INTR_RX_TRIGGER_Msk

/** The RX FIFO is not empty */
#define CY_SCB_RX_INTR_NOT_EMPTY         SCB_INTR_RX_NOT_EMPTY_Msk

/** The RX FIFO is full */
#define CY_SCB_RX_INTR_FULL              SCB_INTR_RX_FULL_Msk

/** An attempt to write to a full RX FIFO */
#define CY_SCB_RX_INTR_OVERFLOW          SCB_INTR_RX_OVERFLOW_Msk

/** An attempt to read from an empty RX FIFO */
#define CY_SCB_RX_INTR_UNDERFLOW         SCB_INTR_RX_UNDERFLOW_Msk

/** LIN baudrate detection is completed */
#define CY_SCB_RX_INTR_BAUD_DETECT       SCB_INTR_RX_BAUD_DETECT_Msk

/** A UART framing error detected */
#define CY_SCB_RX_INTR_UART_FRAME_ERROR  SCB_INTR_RX_FRAME_ERROR_Msk

/** A UART parity error detected  */
#define CY_SCB_RX_INTR_UART_PARITY_ERROR SCB_INTR_RX_PARITY_ERROR_Msk

#if defined (CY_IP_MXSCB) || defined (CY_DOXYGEN)
/** A SPI parity error detected  */
#define CY_SCB_RX_INTR_SPI_PARITY_ERROR  SCB_INTR_RX_PARITY_ERROR_Msk
#endif /* defined (CY_IP_MXSCB) || defined (CY_DOXYGEN) */

/** A UART break detected */
#define CY_SCB_RX_INTR_UART_BREAK_DETECT SCB_INTR_RX_BREAK_DETECT_Msk
/** \} group_scb_common_macros_rx_intr */

/**
* \defgroup group_scb_common_macros_slave_intr Slave Interrupt Statuses
* \{
*/
/**
* I2C slave lost arbitration: the value driven on the SDA line is not the same
* as the value observed on the SDA line
*/
#define CY_SCB_SLAVE_INTR_I2C_ARB_LOST      SCB_INTR_S_I2C_ARB_LOST_Msk

/** The I2C slave received a NAK */
#define CY_SCB_SLAVE_INTR_I2C_NACK          SCB_INTR_S_I2C_NACK_Msk

/** The I2C slave received  an ACK */
#define CY_SCB_SLAVE_INTR_I2C_ACK           SCB_INTR_S_I2C_ACK_Msk

/**
* A Stop or Repeated Start event for a write transfer intended for this slave
* was detected.
*/
#define CY_SCB_SLAVE_INTR_I2C_WRITE_STOP    SCB_INTR_S_I2C_WRITE_STOP_Msk

/** A Stop or Repeated Start event intended for this slave was detected */
#define CY_SCB_SLAVE_INTR_I2C_STOP          SCB_INTR_S_I2C_STOP_Msk

/** The I2C slave received a Start condition */
#define CY_SCB_SLAVE_INTR_I2C_START         SCB_INTR_S_I2C_START_Msk

/** The I2C slave received the matching address */
#define CY_SCB_SLAVE_INTR_I2C_ADDR_MATCH    SCB_INTR_S_I2C_ADDR_MATCH_Msk

/** The I2C Slave received the general call address */
#define CY_SCB_SLAVE_INTR_I2C_GENERAL_ADDR  SCB_INTR_S_I2C_GENERAL_Msk

/** The I2C slave bus error (detection of unexpected Start or Stop condition) */
#define CY_SCB_SLAVE_INTR_I2C_BUS_ERROR     SCB_INTR_S_I2C_BUS_ERROR_Msk

/**
* The SPI slave select line is deselected at an expected time during an
* SPI transfer.
*/
#define CY_SCB_SLAVE_INTR_SPI_BUS_ERROR     SCB_INTR_S_SPI_BUS_ERROR_Msk

#if defined (CY_IP_MXSCB) || defined (CY_DOXYGEN)
/** I2C slave RESTART received */
#define CY_SCB_SLAVE_INTR_I2C_RESTART       SCB_INTR_S_I2C_RESTART_Msk

/** Entered I2C Hs-mode */
#define CY_SCB_SLAVE_INTR_I2C_HS_ENTER      SCB_INTR_S_I2C_HS_ENTER_Msk

/** Exited I2C Hs-mode, after STOP detection */
#define CY_SCB_SLAVE_INTR_I2C_HS_EXIT       SCB_INTR_S_I2C_HS_EXIT_Msk
#endif /* defined (CY_IP_MXSCB) || defined (CY_DOXYGEN) */
/** \} group_scb_common_macros_slave_intr */

/**
* \defgroup group_scb_common_macros_master_intr Master Interrupt Statuses
* \{
*/
/** The I2C master lost arbitration */
#define CY_SCB_MASTER_INTR_I2C_ARB_LOST    SCB_INTR_M_I2C_ARB_LOST_Msk

/** The I2C master received a NACK */
#define CY_SCB_MASTER_INTR_I2C_NACK        SCB_INTR_M_I2C_NACK_Msk

/** The I2C master received an ACK */
#define CY_SCB_MASTER_INTR_I2C_ACK         SCB_INTR_M_I2C_ACK_Msk

/** The I2C master generated a Stop */
#define CY_SCB_MASTER_INTR_I2C_STOP        SCB_INTR_M_I2C_STOP_Msk

/** The I2C master bus error (detection of unexpected START or STOP condition)
*/
#define CY_SCB_MASTER_INTR_I2C_BUS_ERROR   SCB_INTR_M_I2C_BUS_ERROR_Msk

/**
* The SPI master transfer is complete: all data elements transferred from the
* TX FIFO and TX shift register.
*/
#define CY_SCB_MASTER_INTR_SPI_DONE        SCB_INTR_M_SPI_DONE_Msk

#if defined (CY_IP_MXSCB) || defined (CY_DOXYGEN)
/** Entered I2C Hs-mode */
#define CY_SCB_MASTER_INTR_I2C_HS_ENTER    SCB_INTR_M_I2C_HS_ENTER_Msk

/** Exited I2C Hs-mode, after STOP detection */
#define CY_SCB_MASTER_INTR_I2C_HS_EXIT     SCB_INTR_M_I2C_HS_EXIT_Msk
#endif /* defined (CY_IP_MXSCB) || defined (CY_DOXYGEN) */
/** \} group_scb_common_macros_master_intr */

/**
* \defgroup group_scb_common_macros_i2c_intr I2C Interrupt Statuses
* \{
*/
/**
* Wake up request: the I2C slave received the matching address.
* Note that this interrupt source triggers in active mode.
*/
#define CY_SCB_I2C_INTR_WAKEUP     SCB_INTR_I2C_EC_WAKE_UP_Msk
/** \} group_scb_common_macros_i2c_intr */

/**
* \defgroup group_scb_common_macros_SpiIntrStatuses SPI Interrupt Statuses
* \{
*/
/**
* Wake up request: the SPI slave detects an active edge of the slave select
* signal. Note that this interrupt source triggers in active mode.
*/
#define CY_SCB_SPI_INTR_WAKEUP     SCB_INTR_SPI_EC_WAKE_UP_Msk
/** \} group_scb_common_macros_SpiIntrStatuses */


/*******************************************************************************
*                           Internal Constants
*******************************************************************************/

/** \cond INTERNAL */

/* Default registers values */
#ifdef CY_IP_M0S8SCB

#define CY_SCB_CTRL_DEF_VAL         (_VAL2FLD(SCB_CTRL_OVS, 15UL) | \
                                     _VAL2FLD(SCB_CTRL_MODE, 3UL))

#define CY_SCB_SPI_CTRL_DEF_VAL     _VAL2FLD(SCB_SPI_CTRL_MODE, 3UL)

#define CY_SCB_TX_CTRL_DEF_VAL      (_VAL2FLD(SCB_TX_CTRL_DATA_WIDTH, 7UL) | \
                                     _VAL2FLD(SCB_TX_CTRL_MSB_FIRST,  1UL))

#else /* CY_IP_MXSCB */

#define CY_SCB_CTRL_DEF_VAL         (_VAL2FLD(SCB_CTRL_OVS, 15UL) | \
                                     _VAL2FLD(SCB_CTRL_MEM_WIDTH, 1UL) | \
                                     _VAL2FLD(SCB_CTRL_MODE, 3UL))

#define CY_SCB_SPI_CTRL_DEF_VAL     (_VAL2FLD(SCB_SPI_CTRL_MODE, 3UL) | \
                                     _VAL2FLD(SCB_SPI_CTRL_LATE_MISO_SAMPLE, 1UL))

#define CY_SCB_TX_CTRL_DEF_VAL      (_VAL2FLD(SCB_TX_CTRL_DATA_WIDTH, 7UL) | \
                                     _VAL2FLD(SCB_TX_CTRL_MSB_FIRST,  1UL) | \
                                     _VAL2FLD(SCB_TX_CTRL_OPEN_DRAIN_SCL,  1UL))

#endif /* CY_IP_M0S8SCB */

#define CY_SCB_I2C_CTRL_DEF_VAL     (_VAL2FLD(SCB_I2C_CTRL_HIGH_PHASE_OVS, 8UL)        | \
                                     _VAL2FLD(SCB_I2C_CTRL_HIGH_PHASE_OVS, 8UL)        | \
                                     _VAL2FLD(SCB_I2C_CTRL_M_READY_DATA_ACK, 1UL)      | \
                                     _VAL2FLD(SCB_I2C_CTRL_M_NOT_READY_DATA_NACK, 1UL) | \
                                     _VAL2FLD(SCB_I2C_CTRL_S_GENERAL_IGNORE, 1UL)      | \
                                     _VAL2FLD(SCB_I2C_CTRL_S_READY_ADDR_ACK, 1UL)      | \
                                     _VAL2FLD(SCB_I2C_CTRL_S_READY_DATA_ACK, 1UL)      | \
                                     _VAL2FLD(SCB_I2C_CTRL_S_NOT_READY_ADDR_NACK, 1UL) | \
                                     _VAL2FLD(SCB_I2C_CTRL_S_NOT_READY_DATA_NACK, 1UL))

#define CY_SCB_I2C_CFG_DEF_VAL      (_VAL2FLD(SCB_I2C_CFG_SDA_IN_FILT_TRIM, 3UL)   | \
                                     _VAL2FLD(SCB_I2C_CFG_SDA_IN_FILT_SEL, 1UL)    | \
                                     _VAL2FLD(SCB_I2C_CFG_SCL_IN_FILT_SEL, 1UL)    | \
                                     _VAL2FLD(SCB_I2C_CFG_SDA_OUT_FILT0_TRIM, 2UL) | \
                                     _VAL2FLD(SCB_I2C_CFG_SDA_OUT_FILT1_TRIM, 2UL) | \
                                     _VAL2FLD(SCB_I2C_CFG_SDA_OUT_FILT2_TRIM, 2UL))

#define CY_SCB_UART_CTRL_DEF_VAL    _VAL2FLD(SCB_UART_CTRL_MODE, 3UL)

#define CY_SCB_UART_RX_CTRL_DEF_VAL (_VAL2FLD(SCB_UART_RX_CTRL_STOP_BITS, 2UL) | \
                                     _VAL2FLD(SCB_UART_RX_CTRL_BREAK_WIDTH, 10UL))

#define CY_SCB_UART_TX_CTRL_DEF_VAL _VAL2FLD(SCB_UART_TX_CTRL_STOP_BITS, 2UL)

#define CY_SCB_RX_CTRL_DEF_VAL      (_VAL2FLD(SCB_RX_CTRL_DATA_WIDTH, 7UL) | \
                                     _VAL2FLD(SCB_RX_CTRL_MSB_FIRST,  1UL))


#ifdef CY_IP_MXSCB
/* SCB MEM_WIDTH modes */
#define CY_SCB_CTRL_MEM_WIDTH_BYTE      (0U)
#define CY_SCB_CTRL_MEM_WIDTH_HALFWORD  (1U)
#endif /* CY_IP_MXSCB */

/* SCB CTRL modes */
#define CY_SCB_CTRL_MODE_I2C   (0UL)
#define CY_SCB_CTRL_MODE_SPI   (1UL)
#define CY_SCB_CTRL_MODE_UART  (2UL)

/* The position and mask to set the I2C mode */
#define CY_SCB_I2C_CTRL_MODE_Pos    SCB_I2C_CTRL_SLAVE_MODE_Pos
#define CY_SCB_I2C_CTRL_MODE_Msk    (SCB_I2C_CTRL_SLAVE_MODE_Msk | \
                                     SCB_I2C_CTRL_MASTER_MODE_Msk)

/* I2C has fixed data width */
#define CY_SCB_I2C_DATA_WIDTH   (7UL)

/* RX and TX control register values */
#define CY_SCB_I2C_RX_CTRL      (_VAL2FLD(SCB_RX_CTRL_DATA_WIDTH, CY_SCB_I2C_DATA_WIDTH) | \
                                 SCB_RX_CTRL_MSB_FIRST_Msk)
#define CY_SCB_I2C_TX_CTRL      (_VAL2FLD(SCB_TX_CTRL_DATA_WIDTH, CY_SCB_I2C_DATA_WIDTH) | \
                                 SCB_TX_CTRL_MSB_FIRST_Msk)

/* The position and mask to make an address byte */
#define CY_SCB_I2C_ADDRESS_Pos  (1UL)
#define CY_SCB_I2C_ADDRESS_Msk  (0xFEUL)

/* SPI slave select polarity */
#define CY_SCB_SPI_CTRL_SSEL_POLARITY_Pos   SCB_SPI_CTRL_SSEL_POLARITY0_Pos
#define CY_SCB_SPI_CTRL_SSEL_POLARITY_Msk   (SCB_SPI_CTRL_SSEL_POLARITY0_Msk | \
                                             SCB_SPI_CTRL_SSEL_POLARITY1_Msk | \
                                             SCB_SPI_CTRL_SSEL_POLARITY2_Msk | \
                                             SCB_SPI_CTRL_SSEL_POLARITY3_Msk)

/* SPI clock modes: CPHA and CPOL */
#define CY_SCB_SPI_CTRL_CLK_MODE_Pos    SCB_SPI_CTRL_CPHA_Pos
#define CY_SCB_SPI_CTRL_CLK_MODE_Msk    (SCB_SPI_CTRL_CPHA_Msk | SCB_SPI_CTRL_CPOL_Msk)

#ifdef CY_IP_MXSCB
/* SPI parity and parity enable combination */
#define CY_SCB_SPI_RX_CTRL_SET_PARITY_Msk      (SCB_SPI_RX_CTRL_PARITY_ENABLED_Msk | \
                                                 SCB_SPI_RX_CTRL_PARITY_Msk)
#define CY_SCB_SPI_RX_CTRL_SET_PARITY_Pos      SCB_SPI_RX_CTRL_PARITY_Pos

#define CY_SCB_SPI_TX_CTRL_SET_PARITY_Msk      (SCB_SPI_TX_CTRL_PARITY_ENABLED_Msk | \
                                                 SCB_SPI_TX_CTRL_PARITY_Msk)
#define CY_SCB_SPI_TX_CTRL_SET_PARITY_Pos      SCB_SPI_TX_CTRL_PARITY_Pos
#endif /* CY_IP_MXSCB */

/* UART parity and parity enable combination */
#define CY_SCB_UART_RX_CTRL_SET_PARITY_Msk      (SCB_UART_RX_CTRL_PARITY_ENABLED_Msk | \
                                                 SCB_UART_RX_CTRL_PARITY_Msk)
#define CY_SCB_UART_RX_CTRL_SET_PARITY_Pos      SCB_UART_RX_CTRL_PARITY_Pos

#define CY_SCB_UART_TX_CTRL_SET_PARITY_Msk      (SCB_UART_TX_CTRL_PARITY_ENABLED_Msk | \
                                                 SCB_UART_TX_CTRL_PARITY_Msk)
#define CY_SCB_UART_TX_CTRL_SET_PARITY_Pos      SCB_UART_TX_CTRL_PARITY_Pos

/* Max number of bits for byte mode */
#define CY_SCB_BYTE_WIDTH   (8UL)

/* Single unit to wait */
#define CY_SCB_WAIT_1_UNIT  (1U)

/* Clear interrupt sources */
#define CY_SCB_CLEAR_ALL_INTR_SRC   (0UL)

/* Hardware FIFO size */
#define CY_SCB_FIFO_SIZE            (SCB_EZ_DATA_NR / 2U)

/* Provides a list of allowed sources */
#define CY_SCB_TX_INTR_MASK     (CY_SCB_TX_INTR_LEVEL     | CY_SCB_TX_INTR_NOT_FULL  | CY_SCB_TX_INTR_EMPTY     | \
                                 CY_SCB_TX_INTR_OVERFLOW  | CY_SCB_TX_INTR_UNDERFLOW | CY_SCB_TX_INTR_UART_DONE | \
                                 CY_SCB_TX_INTR_UART_NACK | CY_SCB_TX_INTR_UART_ARB_LOST)

#ifdef CY_IP_M0S8SCB
#define CY_SCB_RX_INTR_MASK     (CY_SCB_RX_INTR_LEVEL             | CY_SCB_RX_INTR_NOT_EMPTY | CY_SCB_RX_INTR_FULL | \
                                 CY_SCB_RX_INTR_OVERFLOW          | CY_SCB_RX_INTR_UNDERFLOW                       | \
                                 CY_SCB_RX_INTR_UART_FRAME_ERROR  | CY_SCB_RX_INTR_UART_PARITY_ERROR               | \
                                 CY_SCB_RX_INTR_UART_BREAK_DETECT | CY_SCB_RX_INTR_BAUD_DETECT)
#else /* CY_IP_MXSCB */
#define CY_SCB_RX_INTR_MASK     (CY_SCB_RX_INTR_LEVEL             | CY_SCB_RX_INTR_NOT_EMPTY | CY_SCB_RX_INTR_FULL | \
                                 CY_SCB_RX_INTR_OVERFLOW          | CY_SCB_RX_INTR_UNDERFLOW                       | \
                                 CY_SCB_RX_INTR_UART_FRAME_ERROR  | CY_SCB_RX_INTR_UART_PARITY_ERROR               | \
                                 CY_SCB_RX_INTR_UART_BREAK_DETECT | CY_SCB_RX_INTR_BAUD_DETECT                     | \
                                 CY_SCB_RX_INTR_SPI_PARITY_ERROR)
#endif /* CY_IP_M0S8SCB */

#ifdef CY_IP_M0S8SCB
#define CY_SCB_SLAVE_INTR_MASK  (CY_SCB_SLAVE_INTR_I2C_ARB_LOST   | CY_SCB_SLAVE_INTR_I2C_NACK | CY_SCB_SLAVE_INTR_I2C_ACK   | \
                                 CY_SCB_SLAVE_INTR_I2C_WRITE_STOP | CY_SCB_SLAVE_INTR_I2C_STOP | CY_SCB_SLAVE_INTR_I2C_START | \
                                 CY_SCB_SLAVE_INTR_I2C_ADDR_MATCH | CY_SCB_SLAVE_INTR_I2C_GENERAL_ADDR                       | \
                                 CY_SCB_SLAVE_INTR_I2C_BUS_ERROR  | CY_SCB_SLAVE_INTR_SPI_BUS_ERROR)
#else /* CY_IP_MXSCB */
#define CY_SCB_SLAVE_INTR_MASK  (CY_SCB_SLAVE_INTR_I2C_ARB_LOST   | CY_SCB_SLAVE_INTR_I2C_NACK | CY_SCB_SLAVE_INTR_I2C_ACK   | \
                                 CY_SCB_SLAVE_INTR_I2C_WRITE_STOP | CY_SCB_SLAVE_INTR_I2C_STOP | CY_SCB_SLAVE_INTR_I2C_START | \
                                 CY_SCB_SLAVE_INTR_I2C_ADDR_MATCH | CY_SCB_SLAVE_INTR_I2C_GENERAL_ADDR                       | \
                                 CY_SCB_SLAVE_INTR_I2C_BUS_ERROR  | CY_SCB_SLAVE_INTR_SPI_BUS_ERROR                          | \
                                 CY_SCB_SLAVE_INTR_I2C_HS_ENTER   | CY_SCB_SLAVE_INTR_I2C_HS_EXIT)
#endif /* CY_IP_M0S8SCB */

#ifdef CY_IP_M0S8SCB
#define CY_SCB_MASTER_INTR_MASK (CY_SCB_MASTER_INTR_I2C_ARB_LOST  | CY_SCB_MASTER_INTR_I2C_NACK | \
                                 CY_SCB_MASTER_INTR_I2C_ACK       | CY_SCB_MASTER_INTR_I2C_STOP | \
                                 CY_SCB_MASTER_INTR_I2C_BUS_ERROR | CY_SCB_MASTER_INTR_SPI_DONE)
#else /* CY_IP_MXSCB */
#define CY_SCB_MASTER_INTR_MASK (CY_SCB_MASTER_INTR_I2C_ARB_LOST  | CY_SCB_MASTER_INTR_I2C_NACK | \
                                 CY_SCB_MASTER_INTR_I2C_ACK       | CY_SCB_MASTER_INTR_I2C_STOP | \
                                 CY_SCB_MASTER_INTR_I2C_BUS_ERROR | CY_SCB_MASTER_INTR_SPI_DONE | \
                                 CY_SCB_MASTER_INTR_I2C_HS_ENTER  | CY_SCB_MASTER_INTR_I2C_HS_EXIT)
#endif /* CY_IP_M0S8SCB */

#define CY_SCB_I2C_INTR_MASK    CY_SCB_I2C_INTR_WAKEUP

#define CY_SCB_SPI_INTR_MASK    CY_SCB_SPI_INTR_WAKEUP

#define CY_SCB_IS_INTR_VALID(intr, mask)            ( 0UL == ((intr) & ((uint32_t) ~(mask))) )
#define CY_SCB_IS_TRIGGER_LEVEL_VALID(base, level)  ((level) < Cy_SCB_GetFifoSize(base))

#define CY_SCB_IS_I2C_ADDR_VALID(addr)              ( (0U == ((addr) & 0x80U)) )
#define CY_SCB_IS_BUFFER_VALID(buffer, size)        ( (NULL != (buffer)) && ((size) > 0UL) )
#define CY_SCB_IS_I2C_BUFFER_VALID(buffer, size)    ( (0UL == (size)) ? true : (NULL != (buffer)) )
/** \endcond */

/** \} group_scb_common_macros */


/*******************************************************************************
*                       In-line Function Implementation
*******************************************************************************/

/**
* \addtogroup group_scb_common_functions
* \{
*/

/*******************************************************************************
* Function Name: Cy_SCB_ReadRxFifo
****************************************************************************//**
*
* Reads a data element directly out of the RX FIFO.
* This function does not check whether the RX FIFO has data before reading it.
*
* \param base
* The pointer to the SCB instance.
*
* \return
* Data from RX FIFO.
*
*******************************************************************************/
__STATIC_FORCEINLINE uint32_t Cy_SCB_ReadRxFifo(CySCB_Type const *base)
{
    return (SCB_RX_FIFO_RD(base));
}

/*******************************************************************************
* Function Name: Cy_SCB_SetRxFifoLevel
****************************************************************************//**
*
* Sets the RX FIFO level. When there are more data elements in the RX FIFO than
* this level, the RX FIFO level interrupt is triggered.
*
* \param base
* The pointer to the SCB instance.
*
* \param level
* When there are more data elements in the FIFO than this level, the RX level
* interrupt is triggered.
*
*******************************************************************************/
__STATIC_INLINE void Cy_SCB_SetRxFifoLevel(CySCB_Type *base, uint32_t level)
{
    CY_ASSERT_L2(CY_SCB_IS_TRIGGER_LEVEL_VALID(base, level));

    CY_REG32_CLR_SET(SCB_RX_FIFO_CTRL(base), SCB_RX_FIFO_CTRL_TRIGGER_LEVEL, level);
}


/*******************************************************************************
* Function Name: Cy_SCB_GetNumInRxFifo
****************************************************************************//**
*
* Returns the number of data elements currently in the RX FIFO.
*
* \param base
* The pointer to the SCB instance.
*
* \return
* The number or data elements in RX FIFO.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_SCB_GetNumInRxFifo(CySCB_Type const *base)
{
    return _FLD2VAL(SCB_RX_FIFO_STATUS_USED, SCB_RX_FIFO_STATUS(base));
}


/*******************************************************************************
* Function Name: Cy_SCB_GetRxSrValid
****************************************************************************//**
*
* Returns the status of the RX FIFO Shift Register valid bit.
*
* \param base
* The pointer to the SCB instance.
*
* \return
* 1 - RX shift register valid; 0 - RX shift register not valid.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_SCB_GetRxSrValid(CySCB_Type const *base)
{
    return _FLD2VAL(SCB_RX_FIFO_STATUS_SR_VALID, SCB_RX_FIFO_STATUS(base));
}


/*******************************************************************************
* Function Name: Cy_SCB_ClearRxFifo
****************************************************************************//**
*
* Clears the RX FIFO and shifter.
*
* \param base
* The pointer to the SCB instance.
*
* \note
* If there is partial data in the shifter, it is cleared and lost.
*
*******************************************************************************/
__STATIC_INLINE void Cy_SCB_ClearRxFifo(CySCB_Type* base)
{
    SCB_RX_FIFO_CTRL(base) |= (uint32_t)  SCB_RX_FIFO_CTRL_CLEAR_Msk;
    SCB_RX_FIFO_CTRL(base) &= (uint32_t) ~SCB_RX_FIFO_CTRL_CLEAR_Msk;

    (void) SCB_RX_FIFO_CTRL(base);
}


/*******************************************************************************
* Function Name: Cy_SCB_WriteTxFifo
****************************************************************************//**
*
* Writes data directly into the TX FIFO.
* This function does not check whether the TX FIFO is not full before writing
* into it.
*
* \param base
* The pointer to the SCB instance.
*
* \param data
* Data to write to the TX FIFO.
*
*******************************************************************************/
__STATIC_FORCEINLINE void Cy_SCB_WriteTxFifo(CySCB_Type* base, uint32_t data)
{
    SCB_TX_FIFO_WR(base) = data;
}


/*******************************************************************************
* Function Name: Cy_SCB_SetTxFifoLevel
****************************************************************************//**
*
* Sets the TX FIFO level. When there are fewer data elements in the TX FIFO than
* this level, the TX FIFO level interrupt is triggered.
*
* \param base
* The pointer to the SCB instance.
*
* \param level
* When there are fewer data elements in the FIFO than this level, the TX level
* interrupt is triggered.
*
*******************************************************************************/
__STATIC_INLINE void Cy_SCB_SetTxFifoLevel(CySCB_Type *base, uint32_t level)
{
    CY_ASSERT_L2(CY_SCB_IS_TRIGGER_LEVEL_VALID(base, level));

    CY_REG32_CLR_SET(SCB_TX_FIFO_CTRL(base), SCB_TX_FIFO_CTRL_TRIGGER_LEVEL, level);
}


/*******************************************************************************
* Function Name: Cy_SCB_GetNumInTxFifo
****************************************************************************//**
*
* Returns the number of data elements currently in the TX FIFO.
*
* \param base
* The pointer to the SCB instance.
*
* \return
* The number or data elements in the TX FIFO.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_SCB_GetNumInTxFifo(CySCB_Type const *base)
{
    return _FLD2VAL(SCB_TX_FIFO_STATUS_USED, SCB_TX_FIFO_STATUS(base));
}


/*******************************************************************************
* Function Name: Cy_SCB_GetTxSrValid
****************************************************************************//**
*
* Returns the status of the TX FIFO Shift Register valid bit.
*
* \param base
* The pointer to the SCB instance.
*
* \return
* 1 - TX shift register valid; 0 - TX shift register not valid.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_SCB_GetTxSrValid(CySCB_Type const *base)
{
    return _FLD2VAL(SCB_TX_FIFO_STATUS_SR_VALID, SCB_TX_FIFO_STATUS(base));
}


/*******************************************************************************
* Function Name: Cy_SCB_IsTxComplete
****************************************************************************//**
*
* Checks whether the TX FIFO and Shifter are empty and there is no more data to send.
*
* \param base
* Pointer to SPI the SCB instance.
*
* \return
* If true, transmission complete. If false, transmission is not complete.
*
*******************************************************************************/
__STATIC_INLINE bool Cy_SCB_IsTxComplete(CySCB_Type const *base)
{
     return (0UL == (Cy_SCB_GetNumInTxFifo(base) + Cy_SCB_GetTxSrValid(base)));
}


/*******************************************************************************
* Function Name: Cy_SCB_ClearTxFifo
****************************************************************************//**
*
* Clears the TX FIFO.
*
* \param base
* The pointer to the SCB instance.
*
* \note
* The TX FIFO clear operation also clears the shift register. Thus the shifter
* could be cleared in the middle of a data element transfer. Thia results in
* "ones" being sent on the bus for the remainder of the transfer.
*
*******************************************************************************/
__STATIC_INLINE void Cy_SCB_ClearTxFifo(CySCB_Type *base)
{
    SCB_TX_FIFO_CTRL(base) |= (uint32_t)  SCB_TX_FIFO_CTRL_CLEAR_Msk;
    SCB_TX_FIFO_CTRL(base) &= (uint32_t) ~SCB_TX_FIFO_CTRL_CLEAR_Msk;

    (void) SCB_TX_FIFO_CTRL(base);
}


/*******************************************************************************
* Function Name: Cy_SCB_SetByteMode
****************************************************************************//**
*
* Sets whether the RX and TX FIFOs are in byte mode.
* The FIFOs are either 16-bit wide or 8-bit wide (byte mode).
* When the FIFO is in byte mode it is twice as deep. See the device datasheet
* for FIFO depths.
*
* \param base
* The pointer to the SCB instance.
*
* \param byteMode
* If true, TX and RX FIFOs are 8-bit wide. If false, the FIFOs are 16-bit wide.
*
*******************************************************************************/
__STATIC_INLINE void Cy_SCB_SetByteMode(CySCB_Type *base, bool byteMode)
{
#ifdef CY_IP_M0S8SCB
    if (byteMode)
    {
        SCB_CTRL(base) |=  SCB_CTRL_BYTE_MODE_Msk;
    }
    else
    {
        SCB_CTRL(base) &= ~SCB_CTRL_BYTE_MODE_Msk;
    }
#else /* CY_IP_MXSCB */
    if (byteMode)
    {
        SCB_CTRL(base) |= _VAL2FLD(SCB_CTRL_MEM_WIDTH, CY_SCB_CTRL_MEM_WIDTH_BYTE);
    }
    else
    {
        SCB_CTRL(base) |= _VAL2FLD(SCB_CTRL_MEM_WIDTH, CY_SCB_CTRL_MEM_WIDTH_HALFWORD);
    }
#endif /* CY_IP_M0S8SCB */
}


/*******************************************************************************
* Function Name: Cy_SCB_GetInterruptCause
****************************************************************************//**
*
* Returns the mask of bits showing the source of the current triggered
* interrupt. This is useful for modes of operation where an interrupt can
* be generated by conditions in multiple interrupt source registers.
*
* \param base
* The pointer to the SCB instance.
*
* \return
* The mask with the OR of the following conditions that have been triggered.
* See \ref group_scb_common_macros_intr_cause for the set of constants.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_SCB_GetInterruptCause(CySCB_Type const *base)
{
    return (SCB_INTR_CAUSE(base));
}


/*******************************************************************************
* Function Name: Cy_SCB_GetRxInterruptStatus
****************************************************************************//**
*
* Returns the RX interrupt request register. This register contains the current
* status of the RX interrupt sources.
*
* \param base
* The pointer to the SCB instance.
*
* \return
* The current status of the RX interrupt sources. Each constant is a bit field
* value. The value returned may have multiple bits set to indicate the
* current status.
* See \ref group_scb_common_macros_rx_intr for the set of constants.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_SCB_GetRxInterruptStatus(CySCB_Type const *base)
{
    return (SCB_INTR_RX(base) & CY_SCB_RX_INTR_MASK);
}


/*******************************************************************************
* Function Name: Cy_SCB_SetRxInterruptMask
****************************************************************************//**
*
* Writes the RX interrupt mask register. This register configures which bits
* from the RX interrupt request register can trigger an interrupt event.
*
* \param base
* The pointer to the SCB instance.
*
* \param interruptMask
* Enabled RX interrupt sources.
* See \ref group_scb_common_macros_rx_intr.
*
*******************************************************************************/
__STATIC_INLINE void Cy_SCB_SetRxInterruptMask(CySCB_Type *base, uint32_t interruptMask)
{
    CY_ASSERT_L2(CY_SCB_IS_INTR_VALID(interruptMask, CY_SCB_RX_INTR_MASK));

    SCB_INTR_RX_MASK(base) = interruptMask;
}


/*******************************************************************************
* Function Name: Cy_SCB_GetRxInterruptMask
****************************************************************************//**
*
* Returns the RX interrupt mask register. This register specifies which bits
* from the RX interrupt request register trigger can an interrupt event.
*
* \param base
* The pointer to the SCB instance.
*
* \return
* Enabled RX interrupt sources.
* See \ref group_scb_common_macros_rx_intr for the set of constants.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_SCB_GetRxInterruptMask(CySCB_Type const *base)
{
    return (SCB_INTR_RX_MASK(base));
}


/*******************************************************************************
* Function Name: Cy_SCB_GetRxInterruptStatusMasked
****************************************************************************//**
*
* Returns the RX interrupt masked request register. This register contains
* a logical AND of corresponding bits from the RX interrupt request and
* mask registers.
* This function is intended to be used in the interrupt service routine to
* identify which of the enabled RX interrupt sources caused the interrupt event.
*
* \param base
* The pointer to the SCB instance.
*
* \return
* The current status of enabled RX interrupt sources.
* See \ref group_scb_common_macros_rx_intr for the set of constants.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_SCB_GetRxInterruptStatusMasked(CySCB_Type const *base)
{
    return (SCB_INTR_RX_MASKED(base));
}


/*******************************************************************************
* Function Name: Cy_SCB_ClearRxInterrupt
****************************************************************************//**
*
* Clears the RX interrupt sources in the interrupt request register.
*
* \param base
* The pointer to the SCB instance.
*
* \param interruptMask
* The RX interrupt sources to be cleared.
* See \ref group_scb_common_macros_rx_intr for the set of constants.
*
* \note
*  - CY_SCB_INTR_RX_FIFO_LEVEL interrupt source is not cleared when
*    the RX FIFO has more entries than the level.
*  - CY_SCB_INTR_RX_NOT_EMPTY interrupt source is not cleared when the
*    RX FIFO is not empty.
*  - CY_SCB_INTR_RX_FULL interrupt source is not cleared when the
*    RX FIFO is full.
*
*******************************************************************************/
__STATIC_INLINE void Cy_SCB_ClearRxInterrupt(CySCB_Type *base, uint32_t interruptMask)
{
    CY_ASSERT_L2(CY_SCB_IS_INTR_VALID(interruptMask, CY_SCB_RX_INTR_MASK));

    SCB_INTR_RX(base) = interruptMask;
    (void) SCB_INTR_RX(base);
}


/*******************************************************************************
* Function Name: Cy_SCB_SetRxInterrupt
****************************************************************************//**
*
* Sets the RX interrupt sources in the interrupt request register.
*
* \param base
* The pointer to the SCB instance.
*
* \param interruptMask
* The RX interrupt sources to set in the RX interrupt request register.
* See \ref group_scb_common_macros_rx_intr for the set of constants.
*
*******************************************************************************/
__STATIC_INLINE void Cy_SCB_SetRxInterrupt(CySCB_Type *base, uint32_t interruptMask)
{
    CY_ASSERT_L2(CY_SCB_IS_INTR_VALID(interruptMask, CY_SCB_RX_INTR_MASK));

    SCB_INTR_RX_SET(base) = interruptMask;
}


/*******************************************************************************
* Function Name: Cy_SCB_GetTxInterruptStatus
****************************************************************************//**
*
* Returns the TX interrupt request register. This register contains the current
* status of the TX interrupt sources.
*
* \param base
* The pointer to the SCB instance.
*
* \return
* The current status of TX interrupt sources.
* Each constant is a bit field value. The value returned may have multiple
* bits set to indicate the current status.
* See \ref group_scb_common_macros_tx_intr for the set of constants.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_SCB_GetTxInterruptStatus(CySCB_Type const *base)
{
    return (SCB_INTR_TX(base) & CY_SCB_TX_INTR_MASK);
}


/*******************************************************************************
* Function Name: Cy_SCB_SetTxInterruptMask
****************************************************************************//**
*
* Writes the TX interrupt mask register. This register configures which bits
* from the TX interrupt request register can trigger an interrupt event.
*
* \param base
* The pointer to the SCB instance.
*
* \param interruptMask
* Enabled TX interrupt sources.
* See \ref group_scb_common_macros_tx_intr for the set of constants.
*
*******************************************************************************/
__STATIC_INLINE void Cy_SCB_SetTxInterruptMask(CySCB_Type *base, uint32_t interruptMask)
{
    CY_ASSERT_L2(CY_SCB_IS_INTR_VALID(interruptMask, CY_SCB_TX_INTR_MASK));

    SCB_INTR_TX_MASK(base) = interruptMask;
}


/*******************************************************************************
* Function Name: Cy_SCB_GetTxInterruptMask
****************************************************************************//**
*
* Returns the TX interrupt mask register. This register specifies which
* bits from the TX interrupt request register can trigger an interrupt event.
*
* \param base
* The pointer to the SCB instance.
*
* \return
* Enabled TX interrupt sources.
* See \ref group_scb_common_macros_tx_intr for the set of constants.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_SCB_GetTxInterruptMask(CySCB_Type const *base)
{
    return (SCB_INTR_TX_MASK(base));
}


/*******************************************************************************
* Function Name: Cy_SCB_GetTxInterruptStatusMasked
****************************************************************************//**
*
* Returns the TX interrupt masked request register. This register contains
* a logical AND of corresponding bits from the TX interrupt request and
* mask registers.
* This function is intended to be used in the interrupt service routine to
* identify which of enabled TX interrupt sources caused the interrupt event.
*
* \param base
* The pointer to the SCB instance.
*
* \return
* The current status of enabled TX interrupt sources.
* See \ref group_scb_common_macros_tx_intr for the set of constants.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_SCB_GetTxInterruptStatusMasked(CySCB_Type const *base)
{
    return (SCB_INTR_TX_MASKED(base));
}


/*******************************************************************************
* Function Name: Cy_SCB_ClearTxInterrupt
****************************************************************************//**
*
* Clears the TX interrupt sources in the interrupt request register.
*
* \param base
* The pointer to the SCB instance.
*
* \param interruptMask
* The TX interrupt sources to be cleared.
* See \ref group_scb_common_macros_tx_intr for the set of constants.
*
* \note
*  - CY_SCB_INTR_TX_FIFO_LEVEL interrupt source is not cleared when the
*    TX FIFO has fewer entries than the TX level.
*  - CY_SCB_INTR_TX_NOT_FULL interrupt source is not cleared when the
*    TX FIFO has empty entries in the TX FIFO.
*  - CY_SCB_INTR_TX_EMPTY interrupt source is not cleared when the
*    TX FIFO is empty.
*  - CY_SCB_INTR_TX_UNDERFLOW interrupt source is not cleared when the
*    TX FIFO is empty. Put data into the TX FIFO before clearing it.
*
*******************************************************************************/
__STATIC_INLINE void Cy_SCB_ClearTxInterrupt(CySCB_Type *base, uint32_t interruptMask)
{
    CY_ASSERT_L2(CY_SCB_IS_INTR_VALID(interruptMask, CY_SCB_TX_INTR_MASK));

    SCB_INTR_TX(base) = interruptMask;
    (void) SCB_INTR_TX(base);
}


/*******************************************************************************
* Function Name: Cy_SCB_SetTxInterrupt
****************************************************************************//**
*
* Sets TX interrupt sources in the interrupt request register.
*
* \param base
* The pointer to the SCB instance.
*
* \param interruptMask
* The TX interrupt sources to set in the TX interrupt request register.
* See \ref group_scb_common_macros_tx_intr for the set of constants.
*
*******************************************************************************/
__STATIC_INLINE void Cy_SCB_SetTxInterrupt(CySCB_Type *base, uint32_t interruptMask)
{
    CY_ASSERT_L2(CY_SCB_IS_INTR_VALID(interruptMask, CY_SCB_TX_INTR_MASK));

    SCB_INTR_TX_SET(base) = interruptMask;
}


/*******************************************************************************
* Function Name: Cy_SCB_GetMasterInterruptStatus
****************************************************************************//**
*
* Returns the master interrupt request register. This register contains the current
* status of the master interrupt sources.
*
* \param base
* The pointer to the SCB instance.
*
* \return
* The current status of the master interrupt sources.
* Each constant is a bit field value. The value returned may have multiple
* bits set to indicate the current status.
* See \ref group_scb_common_macros_master_intr for the set of constants.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_SCB_GetMasterInterruptStatus(CySCB_Type const *base)
{
    return (SCB_INTR_M(base) & CY_SCB_MASTER_INTR_MASK);
}


/*******************************************************************************
* Function Name: Cy_SCB_SetMasterInterruptMask
****************************************************************************//**
*
* Writes the master interrupt mask register. This register specifies which bits
* from the master interrupt request register can trigger an interrupt event.
*
* \param base
* The pointer to the SCB instance.
*
* \param interruptMask
* The master interrupt sources to be enable.
* See \ref group_scb_common_macros_master_intr for the set of constants.
*
*******************************************************************************/
__STATIC_INLINE void Cy_SCB_SetMasterInterruptMask(CySCB_Type *base, uint32_t interruptMask)
{
    CY_ASSERT_L2(CY_SCB_IS_INTR_VALID(interruptMask, CY_SCB_MASTER_INTR_MASK));

    SCB_INTR_M_MASK(base) = interruptMask;
}


/*******************************************************************************
* Function Name: Cy_SCB_GetMasterInterruptMask
****************************************************************************//**
*
* Returns the master interrupt mask register. This register specifies which bits
* from the master interrupt request register can trigger an interrupt event.
*
* \param base
* The pointer to the SCB instance.
*
* \return
* Enabled master interrupt sources.
* See \ref group_scb_common_macros_master_intr for the set of constants.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_SCB_GetMasterInterruptMask(CySCB_Type const *base)
{
    return (SCB_INTR_M_MASK(base));
}


/*******************************************************************************
* Function Name: Cy_SCB_GetMasterInterruptStatusMasked
****************************************************************************//**
*
* Returns the master interrupt masked request register. This register contains a
* logical AND of corresponding bits from the master interrupt request and mask
* registers.
* This function is intended to be used in the interrupt service routine to
* identify which of the enabled master interrupt sources caused the interrupt
* event.
*
* \param base
* The pointer to the SCB instance.
*
* \return
* The current status of enabled master interrupt sources.
* See \ref group_scb_common_macros_master_intr for the set of constants.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_SCB_GetMasterInterruptStatusMasked(CySCB_Type const *base)
{
    return (SCB_INTR_M_MASKED(base));
}


/*******************************************************************************
* Function Name: Cy_SCB_ClearMasterInterrupt
****************************************************************************//**
*
* Clears master interrupt sources in the interrupt request register.
*
* \param base
* The pointer to the SCB instance.
*
* \param interruptMask
* The master interrupt sources to be cleared.
* See \ref group_scb_common_macros_master_intr for the set of constants.
*
*******************************************************************************/
__STATIC_INLINE void Cy_SCB_ClearMasterInterrupt(CySCB_Type *base, uint32_t interruptMask)
{
    CY_ASSERT_L2(CY_SCB_IS_INTR_VALID(interruptMask, CY_SCB_MASTER_INTR_MASK));

    SCB_INTR_M(base) = interruptMask;
    (void) SCB_INTR_M(base);
}


/*******************************************************************************
* Function Name: Cy_SCB_SetMasterInterrupt
****************************************************************************//**
*
* Sets master interrupt sources in the interrupt request register.
*
* \param base
* The pointer to the SCB instance.
*
* \param interruptMask
* The master interrupt sources to set in the master interrupt request register.
* See \ref group_scb_common_macros_master_intr for the set of constants.
*
*******************************************************************************/
__STATIC_INLINE void Cy_SCB_SetMasterInterrupt(CySCB_Type *base, uint32_t interruptMask)
{
    CY_ASSERT_L2(CY_SCB_IS_INTR_VALID(interruptMask, CY_SCB_MASTER_INTR_MASK));

    SCB_INTR_M_SET(base) = interruptMask;
}


/*******************************************************************************
* Function Name: Cy_SCB_GetSlaveInterruptStatus
****************************************************************************//**
*
* Returns the slave interrupt request register. This register contains the current
* status of the slave interrupt sources.
*
* \param base
* The pointer to the SCB instance.
*
* \return
* The current status of the slave interrupt sources.
* Each constant is a bit field value. The value returned may have multiple
* bits set to indicate the current status.
* See \ref group_scb_common_macros_slave_intr for the set of constants.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_SCB_GetSlaveInterruptStatus(CySCB_Type const *base)
{
    return (SCB_INTR_S(base) & CY_SCB_SLAVE_INTR_MASK);
}


/*******************************************************************************
* Function Name: Cy_SCB_SetSlaveInterruptMask
****************************************************************************//**
*
* Writes slave interrupt mask register.
* This register specifies which bits from the slave interrupt request register
* can trigger an interrupt event.
*
* \param base
* The pointer to the SCB instance.
*
* \param interruptMask
* Enabled slave interrupt sources.
* See \ref group_scb_common_macros_slave_intr for the set of constants.
*
*******************************************************************************/
__STATIC_INLINE void Cy_SCB_SetSlaveInterruptMask(CySCB_Type *base, uint32_t interruptMask)
{
    CY_ASSERT_L2(CY_SCB_IS_INTR_VALID(interruptMask, CY_SCB_SLAVE_INTR_MASK));

    SCB_INTR_S_MASK(base) = interruptMask;
}


/*******************************************************************************
* Function Name: Cy_SCB_GetSlaveInterruptMask
****************************************************************************//**
*
* Returns the slave interrupt mask register.
* This register specifies which bits from the slave interrupt request register
* can trigger an interrupt event.
*
* \param base
* The pointer to the SCB instance.
*
* \return
* Enabled slave interrupt sources.
* See \ref group_scb_common_macros_slave_intr for the set of constants.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_SCB_GetSlaveInterruptMask(CySCB_Type const *base)
{
    return (SCB_INTR_S_MASK(base));
}


/*******************************************************************************
* Function Name: Cy_SCB_GetSlaveInterruptStatusMasked
****************************************************************************//**
*
* Returns the slave interrupt masked request register. This register contains a
* logical AND of corresponding bits from the slave interrupt request and mask
* registers.
* This function is intended to be used in the interrupt service routine to
* identify which of enabled slave interrupt sources caused the interrupt
* event.
*
* \param base
* The pointer to the SCB instance.
*
* \return
* The current status of enabled slave interrupt sources.
* See \ref group_scb_common_macros_slave_intr for the set of constants.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_SCB_GetSlaveInterruptStatusMasked(CySCB_Type const *base)
{
    return (SCB_INTR_S_MASKED(base));
}


/*******************************************************************************
* Function Name: Cy_SCB_ClearSlaveInterrupt
****************************************************************************//**
*
* Clears the slave interrupt sources in the interrupt request register.
*
* \param base
* The pointer to the SCB instance.
*
* \param interruptMask
* Slave interrupt sources to be cleared.
* See \ref group_scb_common_macros_slave_intr for the set of constants.
*
*******************************************************************************/
__STATIC_INLINE void Cy_SCB_ClearSlaveInterrupt(CySCB_Type *base, uint32_t interruptMask)
{
    CY_ASSERT_L2(CY_SCB_IS_INTR_VALID(interruptMask, CY_SCB_SLAVE_INTR_MASK));

    SCB_INTR_S(base) = interruptMask;
    (void) SCB_INTR_S(base);
}


/*******************************************************************************
* Function Name: Cy_SCB_SetSlaveInterrupt
****************************************************************************//**
*
* Sets slave interrupt sources in the interrupt request register.
*
* \param base
* The pointer to the SCB instance.
*
* \param interruptMask
* The slave interrupt sources to set in the slave interrupt request register
* See \ref group_scb_common_macros_slave_intr for the set of constants.
*
*******************************************************************************/
__STATIC_INLINE void Cy_SCB_SetSlaveInterrupt(CySCB_Type *base, uint32_t interruptMask)
{
    CY_ASSERT_L2(CY_SCB_IS_INTR_VALID(interruptMask, CY_SCB_SLAVE_INTR_MASK));

    SCB_INTR_S_SET(base) = interruptMask;
}


/*******************************************************************************
* Function Name: Cy_SCB_GetI2CInterruptStatus
****************************************************************************//**
*
* Returns the I2C interrupt request register. This register contains the
* current status of the I2C interrupt sources.
*
* \param base
* The pointer to the SCB instance.
*
* \return
* The current status of the I2C interrupt sources. Each constant is a bit
* field value.
* The value returned may have multiple bits set to indicate the current status.
* See \ref group_scb_common_macros_slave_intr for the set of constants.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_SCB_GetI2CInterruptStatus(CySCB_Type const *base)
{
    return (SCB_INTR_I2C_EC(base) & CY_SCB_I2C_INTR_MASK);
}


/*******************************************************************************
* Function Name: Cy_SCB_SetI2CInterruptMask
****************************************************************************//**
*
* Writes the I2C interrupt mask register. This register specifies which bits
* from the I2C interrupt request register can trigger an interrupt event.
*
* \param base
* The pointer to the SCB instance.
*
* \param interruptMask
* Enabled I2C interrupt sources.
* See \ref group_scb_common_macros_i2c_intr for the set of constants.
*
*******************************************************************************/
__STATIC_INLINE void Cy_SCB_SetI2CInterruptMask(CySCB_Type *base, uint32_t interruptMask)
{
    CY_ASSERT_L2(CY_SCB_IS_INTR_VALID(interruptMask, CY_SCB_I2C_INTR_MASK));

    SCB_INTR_I2C_EC_MASK(base) = interruptMask;
}


/*******************************************************************************
* Function Name: Cy_SCB_GetI2CInterruptMask
****************************************************************************//**
*
* Returns the I2C interrupt mask register. This register specifies which bits
* from the I2C interrupt request register can trigger an interrupt event.
*
* \param base
* The pointer to the SCB instance.
*
* \return
* Enabled I2C interrupt sources.
* See \ref group_scb_common_macros_i2c_intr.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_SCB_GetI2CInterruptMask(CySCB_Type const *base)
{
    return (SCB_INTR_I2C_EC_MASK(base));
}


/*******************************************************************************
* Function Name: Cy_SCB_GetI2CInterruptStatusMasked
****************************************************************************//**
*
* Returns the I2C interrupt masked request register. This register contains
* a logical AND of corresponding bits from I2C interrupt request and mask
* registers.
* This function is intended to be used in the interrupt service routine to
* identify which of enabled I2C interrupt sources caused the interrupt event.
*
* \param base
* The pointer to the SCB instance.
*
* \return
* The current status of enabled I2C interrupt sources.
* See \ref group_scb_common_macros_i2c_intr for the set of constants.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_SCB_GetI2CInterruptStatusMasked(CySCB_Type const *base)
{
    return (SCB_INTR_I2C_EC_MASKED(base));
}


/*******************************************************************************
* Function Name: Cy_SCB_ClearI2CInterrupt
****************************************************************************//**
*
* Clears I2C interrupt sources in the interrupt request register.
*
* \param base
* The pointer to the SCB instance.
*
* \param interruptMask
* The I2C interrupt sources to be cleared.
* See \ref group_scb_common_macros_i2c_intr for the set of constants.
*
*******************************************************************************/
__STATIC_INLINE void Cy_SCB_ClearI2CInterrupt(CySCB_Type *base, uint32_t interruptMask)
{
    CY_ASSERT_L2(CY_SCB_IS_INTR_VALID(interruptMask, CY_SCB_I2C_INTR_MASK));

    SCB_INTR_I2C_EC(base) = interruptMask;
    (void) SCB_INTR_I2C_EC(base);
}


/*******************************************************************************
* Function Name: Cy_SCB_GetSpiInterruptStatus
****************************************************************************//**
*
* Returns the SPI interrupt request register. This register contains the current
* status of the SPI interrupt sources.
*
* \param base
* The pointer to the SCB instance.
*
* \return
* The current status of SPI interrupt sources. Each constant is a bit field value.
* The value returned may have multiple bits set to indicate the current status
* See \ref group_scb_common_macros_SpiIntrStatuses for the set of constants.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_SCB_GetSpiInterruptStatus(CySCB_Type const *base)
{
    return (SCB_INTR_SPI_EC(base) & CY_SCB_SPI_INTR_MASK);
}


/*******************************************************************************
* Function Name: Cy_SCB_SetSpiInterruptMask
****************************************************************************//**
*
* Writes the SPI interrupt mask register. This register specifies which
* bits from the SPI interrupt request register can trigger an interrupt event.
*
* \param base
* The pointer to the SCB instance.
*
* \param interruptMask
* Enabled SPI interrupt sources.
* See \ref group_scb_common_macros_SpiIntrStatuses for the set of constants.
*
*******************************************************************************/
__STATIC_INLINE void Cy_SCB_SetSpiInterruptMask(CySCB_Type *base, uint32_t interruptMask)
{
    CY_ASSERT_L2(CY_SCB_IS_INTR_VALID(interruptMask, CY_SCB_SPI_INTR_MASK));

    SCB_INTR_SPI_EC_MASK(base) = interruptMask;
}


/*******************************************************************************
* Function Name: Cy_SCB_GetSpiInterruptMask
****************************************************************************//**
*
* Returns the SPI interrupt mask register. This register specifies which bits
* from the SPI interrupt request register can trigger an interrupt event.
*
* \param base
* The pointer to the SCB instance.
*
* \return
* Enabled SPI interrupt sources.
* See \ref group_scb_common_macros_SpiIntrStatuses for the set of constants.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_SCB_GetSpiInterruptMask(CySCB_Type const *base)
{
    return (SCB_INTR_SPI_EC_MASK(base));
}


/*******************************************************************************
* Function Name: Cy_SCB_GetSpiInterruptStatusMasked
****************************************************************************//**
*
* Returns the SPI interrupt masked request register. This register contains
* a logical AND of corresponding bits from the SPI interrupt request and
* mask registers.
* This function is intended to be used in the interrupt service routine to
* identify which of enabled SPI interrupt sources caused the interrupt event.
*
* \param base
* The pointer to the SCB instance.
*
* \return
* The current status of enabled SPI interrupt sources.
* See \ref group_scb_common_macros_SpiIntrStatuses for the set of constants.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_SCB_GetSpiInterruptStatusMasked(CySCB_Type const *base)
{
    return (SCB_INTR_SPI_EC_MASKED(base));
}


/*******************************************************************************
* Function Name: Cy_SCB_ClearSpiInterrupt
****************************************************************************//**
*
* Clears SPI interrupt sources in the interrupt request register.
*
* \param base
* The pointer to the SCB instance.
*
* \param interruptMask
* The SPI interrupt sources to be cleared.
* See \ref group_scb_common_macros_SpiIntrStatuses for the set of constants.
*
*******************************************************************************/
__STATIC_INLINE void Cy_SCB_ClearSpiInterrupt(CySCB_Type *base, uint32_t interruptMask)
{
    CY_ASSERT_L2(CY_SCB_IS_INTR_VALID(interruptMask, CY_SCB_SPI_INTR_MASK));

    SCB_INTR_SPI_EC(base) = interruptMask;
    (void) SCB_INTR_SPI_EC(base);
}

/** \cond INTERNAL */
/*******************************************************************************
* Function Name: Cy_SCB_GetFifoSize
****************************************************************************//**
*
* Returns the RX and TX FIFO depth.
*
* \param base
* The pointer to the SCB instance.
*
* \return
* FIFO depth.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_SCB_GetFifoSize(CySCB_Type const *base)
{
#ifdef CY_IP_M0S8SCB
    return (_FLD2BOOL(SCB_CTRL_BYTE_MODE, SCB_CTRL(base)) ?
                (CY_SCB_FIFO_SIZE) : (CY_SCB_FIFO_SIZE / 2UL));
#else /* CY_IP_MXSCB */
    return (_FLD2BOOL(SCB_CTRL_MEM_WIDTH, SCB_CTRL(base)) ?
                (CY_SCB_FIFO_SIZE / 2UL) : (CY_SCB_FIFO_SIZE));
#endif /* CY_IP_M0S8SCB */
}


/*******************************************************************************
* Function Name: Cy_SCB_IsRxDataWidthByte
****************************************************************************//**
*
* Returns true if the RX data width is a byte (8 bits).
*
* \param base
* The pointer to the SCB instance.
*
* \return
* True if the RX data width is a byte (8 bits).
*
*******************************************************************************/
__STATIC_INLINE bool Cy_SCB_IsRxDataWidthByte(CySCB_Type const *base)
{
    return (_FLD2VAL(SCB_RX_CTRL_DATA_WIDTH, SCB_RX_CTRL(base)) < CY_SCB_BYTE_WIDTH);
}


/*******************************************************************************
* Function Name: Cy_SCB_IsTxDataWidthByte
****************************************************************************//**
*
* Returns true if the TX data width is a byte (8 bits).
*
* \param base
* The pointer to the SCB instance.
*
* \return
* If true, the TX data width is a byte (8 bits). Otherwise, false.
*
*******************************************************************************/
__STATIC_INLINE bool Cy_SCB_IsTxDataWidthByte(CySCB_Type const *base)
{
    return (_FLD2VAL(SCB_TX_CTRL_DATA_WIDTH, SCB_TX_CTRL(base)) < CY_SCB_BYTE_WIDTH);
}


/*******************************************************************************
* Function Name: Cy_SCB_FwBlockReset
****************************************************************************//**
*
* Disables and enables the block to return it into the known state (default):
* FIFOs and interrupt statuses are cleared.
*
* \param base
* The pointer to the SCB instance.
*
*******************************************************************************/
__STATIC_INLINE void Cy_SCB_FwBlockReset(CySCB_Type *base)
{
    SCB_CTRL(base) &= (uint32_t) ~SCB_CTRL_ENABLED_Msk;

    /* Clean-up command registers */
    SCB_I2C_M_CMD(base) = 0UL;
    SCB_I2C_S_CMD(base) = 0UL;

    SCB_CTRL(base) |= (uint32_t)  SCB_CTRL_ENABLED_Msk;

    (void) SCB_CTRL(base);
}


/*******************************************************************************
* Function Name: Cy_SCB_GetRxFifoLevel
****************************************************************************//**
*
* Returns the RX FIFO level when there are more words in the RX FIFO than the
* level, the RX FIFO level interrupt is triggered.
*
* \param base
* The pointer to the SCB instance.
*
* \return
* RX FIFO level.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_SCB_GetRxFifoLevel(CySCB_Type const *base)
{
    return _FLD2VAL(SCB_RX_FIFO_CTRL_TRIGGER_LEVEL, SCB_RX_FIFO_CTRL(base));
}

/** \endcond */
/** \} group_scb_common_functions */

#if defined(__cplusplus)
}
#endif

/** \} group_scb_common */

#endif /* defined (CY_IP_M0S8SCB) || defined (CY_IP_MXSCB) */

#endif /* (CY_SCB_COMMON_H) */

/* [] END OF FILE */
