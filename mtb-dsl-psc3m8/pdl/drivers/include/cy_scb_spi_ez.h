/***************************************************************************//**
* \file cy_scb_spi_ez.h
* \version 1.0
*
* \brief
* Provides SPI EZ mode API declarations of the SCB driver.
*
********************************************************************************
* \copyright
* Copyright(c) 2024-2026 Infineon Technologies AG or an affiliate of
* Infineon Technologies AG
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
* \addtogroup group_scb_spi_ez
* \{
* Driver API for SPI EZ (Easy) mode operation.
*
* SPI EZ mode uses the hardware EZ protocol where each SPI
* transaction begins with a command byte:
* - 0x00 + address byte: Sets the internal base_addr pointer.
* - 0x01 + data bytes:   Writes data to EZ_DATA starting at base_addr.
* - 0x02:                Reads data from EZ_DATA starting at base_addr.
*
* This module provides APIs to:
* - Set/reset the EZ base address from the controller side
* - Read data from the EZ_DATA buffer on the target side
* - Write data through the EZ protocol from the controller side
* - Get/clear EZ-specific slave interrupt status flags
*
* \defgroup group_scb_spi_ez_macros Macros
* \defgroup group_scb_spi_ez_functions Functions
*
* \} group_scb_spi_ez
*/

#if !defined(CY_SCB_SPI_EZ_H)
#define CY_SCB_SPI_EZ_H

#include "cy_scb_common.h"
#include "cy_scb_spi.h"
#include "cy_syspm.h"

#if defined(__cplusplus)
extern "C" {
#endif

/*******************************************************************************
*                            Macro Definitions
*******************************************************************************/

/**
* \addtogroup group_scb_spi_ez_macros
* \{
*/

/** EZ mode command bytes */
#define CY_SCB_SPI_EZ_CMD_SET_ADDR    (0x00U)  /**< Set base address command */
#define CY_SCB_SPI_EZ_CMD_WRITE       (0x01U)  /**< Write data command */
#define CY_SCB_SPI_EZ_CMD_READ        (0x02U)  /**< Read data command */

/** Maximum EZ data buffer size (bytes) */
#define CY_SCB_SPI_EZ_DATA_SIZE       (512U)

/**
* \defgroup group_scb_spi_ez_macros_status EZ Mode Slave Status Flags
* \{
* Status flags from INTR_S register relevant to EZ mode operation.
*/
/** An EZ write transfer completed (slave deselected after write) */
#define CY_SCB_SPI_EZ_WRITE_STOP     (SCB_INTR_S_SPI_EZ_WRITE_STOP_Msk)

/** An EZ transfer completed (slave deselected - covers both read and write) */
#define CY_SCB_SPI_EZ_STOP           (SCB_INTR_S_SPI_EZ_STOP_Msk)

/** \} group_scb_spi_ez_macros_status */

/**
* \defgroup group_scb_spi_ez_macros_ec_status EZ Mode EC Interrupt Flags
* \{
* Status flags from INTR_SPI_EC register for externally-clocked EZ operation.
* These flags are set by the external-clock domain logic and are valid in
* both ACTIVE and DEEPSLEEP power modes (when EC_AM_MODE=1, EC_OP_MODE=1).
*/
/** Wakeup: slave select activated (use as DeepSleep wakeup source) */
#define CY_SCB_SPI_EZ_EC_WAKEUP          (SCB_INTR_SPI_EC_WAKE_UP_Msk)

/** EZ transfer complete: slave deselected after any EZ transfer */
#define CY_SCB_SPI_EZ_EC_STOP            (SCB_INTR_SPI_EC_EZ_STOP_Msk)

/** EZ write transfer complete: slave deselected after a write operation */
#define CY_SCB_SPI_EZ_EC_WRITE_STOP      (SCB_INTR_SPI_EC_EZ_WRITE_STOP_Msk)

/** EZ read transfer complete: slave deselected after a read operation */
#define CY_SCB_SPI_EZ_EC_READ_STOP       (SCB_INTR_SPI_EC_EZ_READ_STOP_Msk)

/** Mask of all valid SPI EC EZ interrupt flags */
#define CY_SCB_SPI_EZ_EC_INTR_MASK       (CY_SCB_SPI_EZ_EC_WAKEUP     | \
                                           CY_SCB_SPI_EZ_EC_STOP        | \
                                           CY_SCB_SPI_EZ_EC_WRITE_STOP  | \
                                           CY_SCB_SPI_EZ_EC_READ_STOP)

/** \} group_scb_spi_ez_macros_ec_status */

/** \} group_scb_spi_ez_macros */


/*******************************************************************************
*                         Function Prototypes
*******************************************************************************/

/**
* \addtogroup group_scb_spi_ez_functions
* \{
*/

cy_en_syspm_status_t Cy_SCB_SPI_EZ_DeepSleepCallback(
    cy_stc_syspm_callback_params_t *callbackParams,
    cy_en_syspm_callback_mode_t mode);

__STATIC_INLINE uint8_t  Cy_SCB_SPI_EZ_ReadData(CySCB_Type const *base, uint32_t offset);
__STATIC_INLINE void     Cy_SCB_SPI_EZ_ReadArray(CySCB_Type const *base, uint32_t offset, uint8_t *dst, uint32_t size);
__STATIC_INLINE void     Cy_SCB_SPI_EZ_WriteData(CySCB_Type *base, uint32_t offset, uint8_t data);
__STATIC_INLINE uint32_t Cy_SCB_SPI_EZ_GetSlaveStatus(CySCB_Type const *base);
__STATIC_INLINE void     Cy_SCB_SPI_EZ_ClearSlaveStatus(CySCB_Type *base, uint32_t clearMask);
__STATIC_INLINE uint32_t Cy_SCB_SPI_EZ_GetEcStatus(CySCB_Type const *base);
__STATIC_INLINE void     Cy_SCB_SPI_EZ_ClearEcStatus(CySCB_Type *base, uint32_t clearMask);
__STATIC_INLINE void     Cy_SCB_SPI_EZ_SetEcInterruptMask(CySCB_Type *base, uint32_t interruptMask);
__STATIC_INLINE uint32_t Cy_SCB_SPI_EZ_GetEcInterruptMask(CySCB_Type const *base);

/** \} group_scb_spi_ez_functions */


/*******************************************************************************
*                     In-line Function Implementation
*******************************************************************************/

/**
* \addtogroup group_scb_spi_ez_functions
* \{
*/

/*******************************************************************************
* Function Name: Cy_SCB_SPI_EZ_ReadData
****************************************************************************//**
*
* Reads a single byte from the EZ_DATA buffer at the specified offset.
*
* \param base
* The pointer to the SPI target SCB instance.
*
* \param offset
* The byte offset into the EZ_DATA buffer (0 to CY_SCB_SPI_EZ_DATA_SIZE-1).
*
* \return
* The data byte at the specified offset (bits [7:0]).
*
*******************************************************************************/
__STATIC_INLINE uint8_t Cy_SCB_SPI_EZ_ReadData(CySCB_Type const *base,
                                                uint32_t offset)
{
    CY_ASSERT_L2(offset < CY_SCB_SPI_EZ_DATA_SIZE);

    return (uint8_t)(base->EZ_DATA[offset] & SCB_EZ_DATA_EZ_DATA_Msk);
}


/*******************************************************************************
* Function Name: Cy_SCB_SPI_EZ_ReadArray
****************************************************************************//**
*
* Reads multiple bytes from the EZ_DATA buffer starting at the specified offset.
*
* \param base
* The pointer to the SPI target SCB instance.
*
* \param offset
* The starting byte offset into the EZ_DATA buffer.
*
* \param dst
* Pointer to the destination buffer where data will be copied.
*
* \param size
* Number of bytes to read.
*
*******************************************************************************/
__STATIC_INLINE void Cy_SCB_SPI_EZ_ReadArray(CySCB_Type const *base,
                                              uint32_t offset,
                                              uint8_t *dst,
                                              uint32_t size)
{
    CY_ASSERT_L2((offset + size) <= CY_SCB_SPI_EZ_DATA_SIZE);
    CY_ASSERT_L2(NULL != dst);

    for (uint32_t i = 0U; i < size; i++)
    {
        dst[i] = (uint8_t)(base->EZ_DATA[offset + i] & SCB_EZ_DATA_EZ_DATA_Msk);
    }
}


/*******************************************************************************
* Function Name: Cy_SCB_SPI_EZ_WriteData
****************************************************************************//**
*
* Writes a single byte to the EZ_DATA buffer at the specified offset.
* This performs a direct CPU write to the target's EZ_DATA memory.
*
* \param base
* The pointer to the SPI target SCB instance.
*
* \param offset
* The byte offset into the EZ_DATA buffer (0 to CY_SCB_SPI_EZ_DATA_SIZE-1).
*
* \param data
* The data byte to write.
*
*******************************************************************************/
__STATIC_INLINE void Cy_SCB_SPI_EZ_WriteData(CySCB_Type *base,
                                              uint32_t offset,
                                              uint8_t data)
{
    CY_ASSERT_L2(offset < CY_SCB_SPI_EZ_DATA_SIZE);

    base->EZ_DATA[offset] = (uint32_t)data;
}


/*******************************************************************************
* Function Name: Cy_SCB_SPI_EZ_GetSlaveStatus
****************************************************************************//**
*
* Returns the EZ mode specific bits of the slave interrupt status register
* (INTR_S). Use \ref CY_SCB_SPI_EZ_WRITE_STOP and \ref CY_SCB_SPI_EZ_STOP
* masks to check individual flags.
*
* \param base
* The pointer to the SPI target SCB instance.
*
* \return
* A bit mask of EZ-relevant INTR_S flags that are set.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_SCB_SPI_EZ_GetSlaveStatus(CySCB_Type const *base)
{
    return (SCB_INTR_S(base) & (CY_SCB_SPI_EZ_WRITE_STOP | CY_SCB_SPI_EZ_STOP));
}


/*******************************************************************************
* Function Name: Cy_SCB_SPI_EZ_ClearSlaveStatus
****************************************************************************//**
*
* Clears the specified EZ mode slave interrupt status flags.
* Write 1 to clear the corresponding INTR_S bits.
*
* \param base
* The pointer to the SPI target SCB instance.
*
* \param clearMask
* A bit mask of flags to clear. Use \ref CY_SCB_SPI_EZ_WRITE_STOP and/or
* \ref CY_SCB_SPI_EZ_STOP.
*
*******************************************************************************/
__STATIC_INLINE void Cy_SCB_SPI_EZ_ClearSlaveStatus(CySCB_Type *base,
                                                     uint32_t clearMask)
{
    SCB_INTR_S(base) = (clearMask & (CY_SCB_SPI_EZ_WRITE_STOP | CY_SCB_SPI_EZ_STOP));
    (void)SCB_INTR_S(base);
}


/*******************************************************************************
* Function Name: Cy_SCB_SPI_EZ_GetEcStatus
****************************************************************************//**
*
* Returns the SPI EC (externally-clocked) interrupt status from the
* INTR_SPI_EC register. These flags are set by the external-clock domain
* logic and are valid in both ACTIVE and DEEPSLEEP power modes.
*
* \param base
* The pointer to the SPI target SCB instance.
*
* \return
* A bit mask of INTR_SPI_EC flags that are set. Use
* \ref CY_SCB_SPI_EZ_EC_WAKEUP, \ref CY_SCB_SPI_EZ_EC_STOP,
* \ref CY_SCB_SPI_EZ_EC_WRITE_STOP, \ref CY_SCB_SPI_EZ_EC_READ_STOP.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_SCB_SPI_EZ_GetEcStatus(CySCB_Type const *base)
{
    return (SCB_INTR_SPI_EC(base) & CY_SCB_SPI_EZ_EC_INTR_MASK);
}


/*******************************************************************************
* Function Name: Cy_SCB_SPI_EZ_ClearEcStatus
****************************************************************************//**
*
* Clears the specified SPI EC interrupt status flags.
*
* \param base
* The pointer to the SPI target SCB instance.
*
* \param clearMask
* A bit mask of flags to clear. Use \ref CY_SCB_SPI_EZ_EC_WAKEUP,
* \ref CY_SCB_SPI_EZ_EC_STOP, \ref CY_SCB_SPI_EZ_EC_WRITE_STOP,
* \ref CY_SCB_SPI_EZ_EC_READ_STOP.
*
*******************************************************************************/
__STATIC_INLINE void Cy_SCB_SPI_EZ_ClearEcStatus(CySCB_Type *base,
                                                   uint32_t clearMask)
{
    SCB_INTR_SPI_EC(base) = (clearMask & CY_SCB_SPI_EZ_EC_INTR_MASK);
    (void)SCB_INTR_SPI_EC(base);
}


/*******************************************************************************
* Function Name: Cy_SCB_SPI_EZ_SetEcInterruptMask
****************************************************************************//**
*
* Sets the SPI EC interrupt mask (INTR_SPI_EC_MASK). Enabled interrupts
* can trigger a DeepSleep-domain interrupt to wake the system.
*
* \param base
* The pointer to the SPI target SCB instance.
*
* \param interruptMask
* A bit mask of interrupts to enable. Use \ref CY_SCB_SPI_EZ_EC_WAKEUP,
* \ref CY_SCB_SPI_EZ_EC_STOP, \ref CY_SCB_SPI_EZ_EC_WRITE_STOP,
* \ref CY_SCB_SPI_EZ_EC_READ_STOP.
*
*******************************************************************************/
__STATIC_INLINE void Cy_SCB_SPI_EZ_SetEcInterruptMask(CySCB_Type *base,
                                                       uint32_t interruptMask)
{
    SCB_INTR_SPI_EC_MASK(base) = (interruptMask & CY_SCB_SPI_EZ_EC_INTR_MASK);
}


/*******************************************************************************
* Function Name: Cy_SCB_SPI_EZ_GetEcInterruptMask
****************************************************************************//**
*
* Returns the current SPI EC interrupt mask (INTR_SPI_EC_MASK).
*
* \param base
* The pointer to the SPI target SCB instance.
*
* \return
* The current interrupt mask value.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_SCB_SPI_EZ_GetEcInterruptMask(CySCB_Type const *base)
{
    return (SCB_INTR_SPI_EC_MASK(base) & CY_SCB_SPI_EZ_EC_INTR_MASK);
}


/** \} group_scb_spi_ez_functions */

#if defined(__cplusplus)
}
#endif

#endif /* CY_SCB_SPI_EZ_H */

/* [] END OF FILE */
