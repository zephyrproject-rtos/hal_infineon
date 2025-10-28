/***************************************************************************//**
* \file cy_sysfault.h
* \version 1.10
*
* \brief
* Provides an API declaration of the SysFault driver.
*
********************************************************************************
* \copyright
* (c) (2024-2025), Cypress Semiconductor Corporation (an Infineon company) or
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
* \addtogroup group_sysfault
* \{
*
* The SysFault driver provides an API to configure the Fault reporting structure.
* The functions and other declarations used in this driver are in cy_sysfault.h.
* You can include cy_pdl.h to get access to all functions and declarations in the PDL.
* This driver is only available for PSOC 4 HVMS 64/128K, PSOC 4 HVPA 144K, and PAG2S devices.
*
* The fault subsystem contains information about faults that occur in the system.
* The fault subsystem captures only faults and does not take any action to correct them.
* The subsystem can cause a reset, give a pulse indication, or trigger another peripheral.
* HVMS 64/128K, PSOC 4 HVPA 144K, and PAG2S devices use a centralized fault report structure.
* The centralized nature allows for a system-wide consistent handling of faults,
* which simplifies software development. Only a single fault interrupt handler is required.
* The fault report structure provides the fault source and additional
* fault-specific information from a single set of memory mapped input/output (MMIO) registers,
* no iterative search is required for the fault source and fault information.
* All pending faults are available from a single set of MMIO registers. Below is the block
* diagram.
* \image html fault.png
*
* The Fault IP provides a fault report structure. The fault report structures capture faults.
* The number of fault report structures is specified by the design time configuration
* parameter (FAULT_NR). In CAT2, there are two instances of fault structures, each fault
* report structure has a dedicated set of MMIO control and status registers and captures
* a single fault. The fault report structure provides fault source and additional fault
* specific information from a single set of MMIO registers. The fault structures capture
* faults like peripheral specific errors, memory controller specific errors.
* E.g., SRAM controller ECC errors, FLASH controller read during program and ECC errors,
* time out errors, power errors.
*
* \note Note that some of the above faults also result in errors on the bus infrastructure.
*
* System fault will be captured by fault report structures. A fault report structure
* provides the fault source and additional fault specific information from a single
* set of MMIO registers.
* The captured fault information includes:
* * A validity bit field that indicates that a fault is captured.
* * A fault index that identifies the fault source.
* * Additional fault information that describes fault specifics
*
* \note When a fault is configured to trigger a reset, the debugging of
* the configured fault structure is not possible.
*
* \warning The ROM boot uses fault structure #0 (FAULT_STRUCT0) to detect potential
* fault sources during boot.
* It sets up fault masks to detect not correctable ECC errors for SRAM and flash.
* If fault report structure #0 is used to capture faults and is configured to trigger a reset,
* use the weak Cy_BootStatus() function and \ref Cy_SysLib_GetBootStatus()
* ~~should be used~~ to handle Boot-Up Status.
* Applicable to PSOC4 HVMS/PA only.
*
* \section group_sysfault_configuration Configuration Considerations
*
* Fault configuration includes the clearing of the existing fault status, enabling the fault source,
* setting an interrupt mask, and fault initialization.
* Below is the code snippet for the fault configuration.
* \snippet sysfault_snippet.c snippet_Cy_SysFault_Config
*
* Once a configured fault occurs, the interrupt handler will be triggered where the
* fault information can be captured.
* Below is the code snippet, which can be part of the interrupt handler.
* \snippet sysfault_snippet.c snippet_Cy_SysFault_Handle_Fault
*
* \section group_sysfault_section_more_information More Information
*
* For more information on the System Fault, refer to the technical reference
* manual (TRM).
*
* \section group_sysfault_changelog Changelog
* <table class="doxtable">
*   <tr><th>Version</th><th>Changes</th><th>Reason for Change</th></tr>
*   <tr>
*     <td>1.10</td>
*     <td> Added the \ref Cy_SysFault_SetFaultSource and \ref Cy_SysFault_SetFaultData functions.</td>
*     <td>API improvement.</td>
*   </tr>
*   <tr>
*     <td>1.0</td>
*     <td>Initial version</td>
*     <td></td>
*   </tr>
* </table>
*
* \defgroup group_sysfault_macros Macros
* \defgroup group_sysfault_enums Enums
* \defgroup group_sysfault_data_structures Data Structures
* \defgroup group_sysfault_functions Functions
*
*/

#if !defined(CY_SYSFAULT_H)
#define CY_SYSFAULT_H

#include "cy_device.h"

#if defined(CPUSS_FAULT_PRESENT)
#include "cy_syslib.h"
#include "cy_device_headers.h"

#if defined(__cplusplus)
extern "C" {
#endif

/*******************************************************************************
*       Function Constants
*******************************************************************************/

/**
* \addtogroup group_sysfault_macros
* \{
*/

/** Driver major version */
#define CY_SYSFAULT_DRV_VERSION_MAJOR    1

/** Driver minor version */
#define CY_SYSFAULT_DRV_VERSION_MINOR    10

/** Driver ID */
#define CY_SYSFAULT_ID CY_PDL_DRV_ID     (0x76U)

/** \cond INTERNAL */

/* Macro to validate parameters in Cy_SysFault_GetFaultData() function */
#define CY_SYSFAULT_IS_DATA_SET_VALID(dataSet)     (((dataSet) == CY_SYSFAULT_DATA0) || \
                                                    ((dataSet) == CY_SYSFAULT_DATA1))

/* The macro to validate parameters in the Cy_SysFault_GetPendingFault() function */
#define CY_SYSFAULT_IS_FAULT_SET_VALID(pendingFault)  ((pendingFault) == CY_SYSFAULT_SET0)

#if defined(CY_DEVICE_PSOC4HVMS128K) || defined(CY_DEVICE_PSOC4HVMS64K) || defined(CY_DEVICE_PSOC4HV144K)
    #define CY_SYSFAULT_NO_FAULT ((uint32_t)HVSS_FAULT_PWR + 1UL)
#elif defined(CY_DEVICE_PAG2S)
    #define CY_SYSFAULT_NO_FAULT ((uint32_t)SRSS_FAULT_CRWDT + 1UL)
#endif

#define cy_en_sysfault_source_t     en_sysfault_source_t

/* The macro to validate the Fault source */
#define CY_SYSFAULT_IS_FAULT_SOURCE_VALID(faultSource)  ((uint32_t)(faultSource) < CY_SYSFAULT_NO_FAULT)

/** \endcond */


/** \} group_sysfault_macros */


/**
* \addtogroup group_sysfault_enums
* \{
*/

/**
* SysFault driver error codes
*/
typedef enum
{
    CY_SYSFAULT_SUCCESS   = 0x0UL, /**< Returned successful */
    CY_SYSFAULT_BAD_PARAM = CY_SYSFAULT_ID | CY_PDL_STATUS_ERROR | 0x1UL, /**< Bad parameter was passed */
} cy_en_sysfault_status_t;

/**
* SysFault pending Fault source set.
*/
typedef enum
{
    CY_SYSFAULT_SET0 = 0UL, /**< Set of Faults in the range of 0-31 Fault ID */
} cy_en_sysfault_set_t;

/**
* Instances of Fault data register.
*/
typedef enum
{
    CY_SYSFAULT_DATA0 = 0UL, /**< Used to get the Fault data for DATA0 register */
    CY_SYSFAULT_DATA1 = 1UL, /**< Used to get the Fault data for DATA1 register */
} cy_en_sysfault_data_t;

/** \cond INTERNAL */
/* Enumeration below is only for documentation purpose.
 * Actual enumeration values come from generated headers. */
/** \endcond */

#if defined(CY_DOXYGEN)
/**
* SysFault sources for PSOC 4 HVPA 144K Family of devices.
* \note For other devices, see the Table of Fault source assignment in the device Datasheet.
*/
typedef enum
{
    CPUSS_FAULT_RAMC_C_ECC          = 0U,  /**< System memory controller 0 correctable ECC violation */
    CPUSS_FAULT_RAMC_NC_ECC         = 1U,  /**< System memory controller 0 non-correctable ECC violation */
    CPUSS_FAULT_FLASHC_C_ECC        = 4U,  /**< Flash controller 0 correctable ECC violation */
    CPUSS_FAULT_FLASHC_NC_ECC       = 5U,  /**< Flash controller 0 non-correctable ECC violation */
    CPUSS_FAULT_FLASHC_BUS_ERR      = 6U,  /**< Flash controller 0 Bus Error */
    CPUSS_FAULT_FLASHC1_C_ECC       = 7U,  /**< Flash controller 1 correctable ECC violation */
    CPUSS_FAULT_FLASHC1_NC_ECC      = 8U,  /**< Flash controller 1 non-correctable ECC violation */
    CPUSS_FAULT_FLASHC1_BUS_ERR     = 9U,  /**< Flash controller 1 Bus Error */
    SRSS_FAULT_CRWDT                = 10U, /**< Fault output for CRWDT */
    HVSS_FAULT_PWR                  = 11U, /**< Fault output for HVREG */
} cy_en_sysfault_source_t;

#endif

/** \} group_sysfault_enums */


/*******************************************************************************
*       Configuration Structure
*******************************************************************************/

/**
* \addtogroup group_sysfault_data_structures
* \{
*/

/**
* Configuration structure for a Fault control register.
*/
typedef struct {
    bool       triggerEnable;   /**< Enables the Trigger output when it is True */
    bool       outputEnable;    /**< Enables the Output signal when it is True */
    bool       resetEnable;     /**< Enables the Reset request  when it is True */
} cy_stc_sysfault_config_t;

/** \} group_sysfault_data_structures */


/*******************************************************************************
*       Function Prototypes
*******************************************************************************/

/**
* \addtogroup group_sysfault_functions
* \{
*/

/*******************************************************************************
* Function Name: Cy_SysFault_Init
****************************************************************************//**
*
* \brief
* Initializes the SysFault for recording faults.
*
* \param base
* The pointer to a Fault structure instance.
*
* \param config
* The pointer to a Configuration structure \ref cy_stc_sysfault_config_t.
*
* \return
* Fault status. Refer \ref cy_en_sysfault_status_t
*
* \funcusage
* \snippet sysfault_snippet.c snippet_Cy_SysFault_Config
*
*******************************************************************************/
cy_en_sysfault_status_t Cy_SysFault_Init(FAULT_STRUCT_Type *base, cy_stc_sysfault_config_t *config);


/*******************************************************************************
* Function Name: Cy_SysFault_ClearStatus
****************************************************************************//**
*
* \brief
* Clears the status register.
*
* \param base
* The pointer to a Fault structure instance.
*
* \funcusage
* \snippet sysfault_snippet.c snippet_Cy_SysFault_Config
*
*******************************************************************************/
__STATIC_INLINE void Cy_SysFault_ClearStatus(FAULT_STRUCT_Type *base)
{
    FAULT_STATUS(base) = 0UL;
}


/*******************************************************************************
* Function Name: Cy_SysFault_GetErrorSource
****************************************************************************//**
*
* \brief
* Returns the error source for the Fault.
*
* \param  base
* The pointer to a Fault structure instance.
*
* \return
* Fault source.
*
* \funcusage
* \snippet sysfault_snippet.c snippet_Cy_SysFault_Handle_Fault
*
*******************************************************************************/
cy_en_sysfault_source_t Cy_SysFault_GetErrorSource(FAULT_STRUCT_Type *base);


/*******************************************************************************
* Function Name: Cy_SysFault_GetFaultData
****************************************************************************//**
*
* \brief
* Returns the Fault information for the provided dataSet.
*
* \param base
* The pointer to a Fault structure instance.
*
* \param dataSet
* Instance of data register \ref cy_en_sysfault_data_t.
*
* \return
* Fault information.
*
* \funcusage
* \snippet sysfault_snippet.c snippet_Cy_SysFault_Handle_Fault
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_SysFault_GetFaultData(FAULT_STRUCT_Type *base, cy_en_sysfault_data_t dataSet)
{
    CY_ASSERT_L3(CY_SYSFAULT_IS_DATA_SET_VALID(dataSet));

    return _FLD2VAL(FAULT_STRUCT_DATA_DATA, FAULT_DATA(base)[dataSet]);
}


/*******************************************************************************
* Function Name: Cy_SysFault_GetPendingFault
****************************************************************************//**
*
* \brief
* Returns not captured sources of the pending fault.
*
* \param base
* The pointer to a Fault structure instance.
*
* \param pendingFault
* Instance of PENDING register. PENDING0 returns the occurred pending Faults
* in the range of 0-31 Fault ID.
*
* \return
* The status of pending Faults.
*
* \funcusage
* \snippet sysfault_snippet.c snippet_Cy_SysFault_PendingFault
*
*******************************************************************************/
uint32_t Cy_SysFault_GetPendingFault(FAULT_STRUCT_Type *base, cy_en_sysfault_set_t pendingFault);


/*******************************************************************************
* Function Name: Cy_SysFault_SetMaskByIdx
****************************************************************************//**
*
* \brief
* Enable the Fault to be captured.
*
* \param base
* The pointer to a Fault structure instance.
*
* \param sourceIdx
* The Fault id to be set in the mask register.
* Only members of \ref cy_en_sysfault_source_t are expected to be used.
*
* \return
* None.
*
* \funcusage
* \snippet sysfault_snippet.c snippet_Cy_SysFault_Config
*
*******************************************************************************/
__STATIC_INLINE void Cy_SysFault_SetMaskByIdx(FAULT_STRUCT_Type *base, cy_en_sysfault_source_t sourceIdx)
{
    if(CY_SYSFAULT_IS_FAULT_SOURCE_VALID(sourceIdx))
    {
        FAULT_MASK0(base) |= (1UL << (uint32_t)sourceIdx);
    }
    else
    {
        /* The sourceIdx is not valid */
        CY_ASSERT_L2(false);
    }
}


/*******************************************************************************
* Function Name: Cy_SysFault_ClearMaskByIdx
****************************************************************************//**
*
* \brief
* Disable the faults to be captured.
*
* \param base
* The pointer to a Fault structure instance.
*
* \param sourceIdx
* The fault id to be cleared in the mask register.
* Only members of \ref cy_en_sysfault_source_t are expected to be used.
*
* \return
* None.
*
* \funcusage
* \snippet sysfault_snippet.c snippet_Cy_SysFault_PendingFault
*
*******************************************************************************/
__STATIC_INLINE void Cy_SysFault_ClearMaskByIdx(FAULT_STRUCT_Type *base, cy_en_sysfault_source_t sourceIdx)
{
    if(CY_SYSFAULT_IS_FAULT_SOURCE_VALID(sourceIdx))
    {
        FAULT_MASK0(base) &= ~(1UL << (uint32_t)sourceIdx);
    }
    else
    {
        /* The sourceIdx is not valid */
        CY_ASSERT_L2(false);
    }
}

/*******************************************************************************
* Function Name: Cy_SysFault_GetInterruptStatus
****************************************************************************//**
*
* \brief
* Returns the status of the interrupt.
*
* \param base
* The pointer to a Fault structure instance.
*
* \return
* Interrupt status.
*
* \funcusage
* \snippet sysfault_snippet.c snippet_Cy_SysFault_Handle_Fault
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_SysFault_GetInterruptStatus(FAULT_STRUCT_Type *base)
{
    return _FLD2VAL(FAULT_STRUCT_INTR_FAULT, FAULT_INTR(base));
}


/*******************************************************************************
* Function Name: Cy_SysFault_ClearInterrupt
****************************************************************************//**
*
* \brief
* Clears Active Interrupt Source.
*
* \param base
* The pointer to a Fault structure instance.
*
* \return
* None.
*
* \funcusage
* \snippet sysfault_snippet.c snippet_Cy_SysFault_Handle_Fault
*
*******************************************************************************/
__STATIC_INLINE void Cy_SysFault_ClearInterrupt(FAULT_STRUCT_Type *base)
{
    FAULT_INTR(base) = FAULT_STRUCT_INTR_FAULT_Msk;
    /* Read the interrupt register to ensure that the initial clearing write has
    * been flushed out to the hardware.
    */
    (void) FAULT_INTR(base);
}


/*******************************************************************************
* Function Name: Cy_SysFault_SetInterrupt
****************************************************************************//**
*
* \brief
* Triggers an interrupt via a software write.
*
* \param base
* The pointer to a Fault structure instance.
*
* \return
* None.
*
* \funcusage
* \snippet sysfault_snippet.c snippet_Cy_SysFault_Config
*
*******************************************************************************/
__STATIC_INLINE void Cy_SysFault_SetInterrupt(FAULT_STRUCT_Type *base)
{
    FAULT_INTR_SET(base) = FAULT_STRUCT_INTR_SET_FAULT_Msk;
}


/*******************************************************************************
* Function Name: Cy_SysFault_SetInterruptMask
****************************************************************************//**
*
* \brief
* Sets an interrupt mask.
*
* \param base
* The pointer to a Fault structure instance.
*
* \return
* None.
*
* \funcusage
* \snippet sysfault_snippet.c snippet_Cy_SysFault_Config
*
*******************************************************************************/
__STATIC_INLINE void Cy_SysFault_SetInterruptMask(FAULT_STRUCT_Type *base)
{
    FAULT_INTR_MASK(base) = FAULT_STRUCT_INTR_MASK_FAULT_Msk;
}


/*******************************************************************************
* Function Name: Cy_SysFault_ClearInterruptMask
****************************************************************************//**
*
* \brief
* Clears an interrupt mask.
*
* \param base
* The pointer to a Fault structure instance.
*
* \return
* None.
*
* \funcusage
* \snippet sysfault_snippet.c snippet_Cy_SysFault_Handle_Fault
*
*******************************************************************************/
__STATIC_INLINE void Cy_SysFault_ClearInterruptMask(FAULT_STRUCT_Type *base)
{
    FAULT_INTR_MASK(base) &=  ~FAULT_STRUCT_INTR_MASK_FAULT_Msk;
}


/*******************************************************************************
* Function Name: Cy_SysFault_GetInterruptMask
****************************************************************************//**
*
* \brief Returns the interrupt mask.
*
* \param  base
* The pointer to a Fault structure instance.
*
* \return
* Interrupt Mask.
*
* \funcusage
* \snippet sysfault_snippet.c snippet_Cy_SysFault_Handle_Fault
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_SysFault_GetInterruptMask(FAULT_STRUCT_Type *base)
{
    return(FAULT_INTR_MASK(base));
}


/*******************************************************************************
* Function Name: Cy_SysFault_GetInterruptStatusMasked
****************************************************************************//**
*
* \brief
* Returns whether masked interrupt triggered the interrupt.
*
* \param base
* The pointer to a Fault structure instance.
*
* \return
* Interrupt Mask.
*
* \funcusage
* \snippet sysfault_snippet.c snippet_Cy_SysFault_Handle_Fault
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_SysFault_GetInterruptStatusMasked(FAULT_STRUCT_Type *base)
{
    return(FAULT_INTR_MASKED(base));
}


/*******************************************************************************
* Function Name: Cy_SysFault_SetFaultSource
****************************************************************************//**
*
* \brief
* Simulate rising up of hardware error.
*
* \param base
* The pointer to a Fault structure instance.
*
* \param faultSource
* The Fault id to set the error source.
* Only members of \ref cy_en_sysfault_source_t are expected to be used.
*
* \return
* Fault status. Refer \ref cy_en_sysfault_status_t
*
* \funcusage
* \snippet sysfault_snippet.c snippet_Cy_SysFault_Set_Fault
*
*******************************************************************************/
__STATIC_INLINE cy_en_sysfault_status_t Cy_SysFault_SetFaultSource(FAULT_STRUCT_Type *base, cy_en_sysfault_source_t faultSource)
{
    cy_en_sysfault_status_t status = CY_SYSFAULT_BAD_PARAM;

    if (CY_SYSFAULT_IS_FAULT_SOURCE_VALID(faultSource))
    {
        CY_REG32_CLR_SET(FAULT_STATUS(base), FAULT_STRUCT_STATUS_IDX, faultSource);
        FAULT_STATUS(base) |= FAULT_STRUCT_STATUS_VALID_Msk;

        status = CY_SYSFAULT_SUCCESS;
    }

    return(status);
}


/*******************************************************************************
* Function Name: Cy_SysFault_SetFaultData
****************************************************************************//**
*
* \brief
* Set the Fault information for the provided dataSet.
*
* \param base
* The pointer to a Fault structure instance.
*
* \param dataSet
* Instance of data register \ref cy_en_sysfault_data_t.
*
* \param data
* Set the Fault information.
*
* \return
* None.
*
* \funcusage
* \snippet sysfault_snippet.c snippet_Cy_SysFault_Set_Fault
*
*******************************************************************************/
__STATIC_INLINE void Cy_SysFault_SetFaultData(FAULT_STRUCT_Type *base, cy_en_sysfault_data_t dataSet, uint32_t data)
{
    CY_ASSERT_L3(CY_SYSFAULT_IS_DATA_SET_VALID(dataSet));

    FAULT_DATA(base)[dataSet] = data;
}

/** \} group_sysfault_functions */


#if defined(__cplusplus)
}
#endif

#endif /* CPUSS_FAULT_PRESENT */

#endif /* CY_SYSFAULT_H */

/** \} group_sysfault */

/* [] END OF FILE */
