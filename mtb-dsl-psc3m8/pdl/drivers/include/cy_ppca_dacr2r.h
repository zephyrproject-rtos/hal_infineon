/***************************************************************************//**
* \file cy_ppca_dacr2r.h
* \version 1.0
*
* The header file of the PPCA DACR2R driver.
*
********************************************************************************
* \copyright
* (c) 2024-2026, Infineon Technologies AG or an affiliate of
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


#if !defined(CY_PPCA_DACR2R_H)
#define CY_PPCA_DACR2R_H

#include "cy_device.h"

#if defined (CY_IP_MXS40PPSS) || defined (CY_DOXYGEN)

#if defined(__cplusplus)
extern "C" {
#endif

/**
* \addtogroup group_ppca_dacr2r
* The DAC R2R driver provides an interface to the 12-bit R2R-ladder
* Digital-to-Analog Converter within the ATOPSS. The ATOPSS contains 2 DAC R2R
* instances, one per DCSG group (GRP_0 and GRP_1).
*
* \section group_ppca_dacr2r_overview Overview
*
* Each DAC R2R converts a 12-bit digital code to an analog voltage output.
* The DAC output can be routed to the DCSG comparator for slope compensation,
* looped back to the ADC for self-test, or connected to external pins via the
* analog MUX.
*
* <b>Key Specifications:</b>
* - 12-bit resolution, 10-bit accuracy
* - Up to 2 MHz refresh rate
* - 50 pF load driver capability
* - Single-ended output (VDAC_OUT max = VREF or VDDA/2)
*
* <b>Operating Modes:</b>
* - Loopback single-ended (P-G, 0 V to 3.3 V)
* - DAC buffer with 1.2 V full range
* - DAC buffer with VDDA/2 full range
* - Loopback differential 200 mV (VDDREF = 0.4 V, +/-200 mV)
* - Loopback differential 3.3 V (VDDREF = VDDA, +/-3.3 V)
*
* <b>Correction Features:</b>
* - Offset correction: compensates for DAC zero-code offset
* - Gain correction: compensates for DAC full-scale error
* - Buffer offset correction: compensates for output buffer offset
*
* The DAC output can also be connected as a reference to its output buffer,
* and VREF can optionally serve as the buffer reference.
*
* \note Initialization (Cy_PPCA_DAC_Init) must be called from the Main core
* so that trim registers are configured correctly.
*
* \{
*/

/**
* \defgroup group_ppca_dacr2r_macros                Macros
* \defgroup group_ppca_dacr2r_functions             Functions
* \defgroup group_ppca_dacr2r_data_structures Data Structures
* \} */

/**
* \addtogroup group_ppca_dacr2r_macros
* \{
*/
/** Macros */
#define ATOPSS_DAC_TYPE PPCA_ATOPSS_DCSG_GRP_DAC_R2R_Type

/** \} group_ppca_dacr2r_macros */

/**
* \addtogroup group_ppca_dacr2r_data_structures
* \{
*/

/** R2R DAC Configuration */
typedef enum
{
    CY_DACR2R_CNFG_LOOPBACK_SINGLE_ENDED_MODE        = 1UL,        /**<Loopback Single Ended Mode (P-G) from 0V to 3.3V) and Loopback Differential Mode (P-N) from 0V to 3.3V) */
    CY_DACR2R_CNFG_DAC_BUF_WITH_1_2_FULL_RANGE       = 2UL,        /**<DAC Buffer with 1.2 Full Range */
    CY_DACR2R_CNFG_DAC_BUF_WITH_VDDABY2_FULL_RANGE   = 3UL,        /**<DAC Buffer with VDDA/2 Full Range */
    CY_DACR2R_CNFG_LOOPBACK_200MV_DIFFERENTIAL_MODE  = 4UL,        /**<Loopback Differential Mode (VDDREF=0.4V, from -0.2V to 0.2V)200 mV  */
    CY_DACR2R_CNFG_LOOPBACK_3V_DIFFERENTIAL_MODE     = 5UL,        /**<Loopback Differential Mode (VDDREF=VDDA, from -3.3V to 3.3V)  */
} cy_en_dacr2r_cnfg_mode_t;


/** PPCA DACR2R configuration structure */
typedef struct cy_stc_ppca_dacr2r_config
{
    bool                           dac_buf_enable;                    /**< if set to true, buf offset will be enabled. */
    cy_en_dacr2r_cnfg_mode_t       dacr2r_cnfg;                       /**< R2R DAC Configuration */
    bool                           offset_correction_disable;         /**< Offset Correction is added to DOUT value before sending to R2R_DAC Analog module. false: correction enabled. true: correction disabled. */
    bool                           gain_correction_disable;           /**< Gain Correction is added to DOUT value before sending to R2R_DAC Analog module. false: correction enabled. true: correction disabled. */
    bool                           buf_offset_correction_disable;     /**< Buf Offset Correction is added to DOUT value before sending to R2R_DAC Analog module. false: correction enabled. true: correction disabled. */
    bool                           vref_to_buf_enable;                /**< Enable VREF as reference to Buffer. false - VREF is not connected as reference true - VREF is connected as reference.  */
    bool                           dac_out_to_buf_enable;             /**< Enable DAC_Output as reference to Buffer. false - DAC_Output is not connected as reference. true - DAC_Output is connected as reference.  */
}cy_stc_ppca_dacr2r_config_t;


/** \} group_ppca_dacr2r_data_structures */


/**
* \addtogroup group_ppca_dacr2r_functions
* \{
*/

/******************************************************************************
* Function Name: Cy_PPCA_DAC_Init
***************************************************************************//**
*
* Initializes the 12-bit R2R DAC. Configures the operating mode (loopback,
* buffered), correction features (offset, gain, buffer offset), and reference
* connections. Also loads trim values from the SFLASH region.
*
* \param base The pointer to the DACR2R instance address.
*
* \param config The pointer to the DAC config structure \ref cy_stc_ppca_dacr2r_config_t.
*
* \note Must be called from the Main core so that trim registers are
* configured correctly. Trim values are not loaded if called from PPCA cores.
*
* \snippet ppca/snippet/ppca_snippet.c SNIPPET_PPCA_DAC_INIT
******************************************************************************/
#if defined (COMPONENT_PPCA_DEVICE) && !defined (__ICCARM__)
void Cy_PPCA_DAC_Init(ATOPSS_DAC_TYPE *base, cy_stc_ppca_dacr2r_config_t const *config )__attribute__((warning("Initialization of PPCA peripherals like AREF, ADC, DAC and DCSG to be done on Main core. Trim values are not configured if called on PPCA cores.")));
#else
void Cy_PPCA_DAC_Init(ATOPSS_DAC_TYPE *base, cy_stc_ppca_dacr2r_config_t const *config );
#endif

/******************************************************************************
* Function Name: Cy_PPCA_DAC_Enable
***************************************************************************//**
*
* Enables the DAC
*
* \param base The pointer to the DACR2R instance address.
*
******************************************************************************/
__STATIC_INLINE void Cy_PPCA_DAC_Enable(ATOPSS_DAC_TYPE *base)
{
    PPCA_ATOP_DAC_CTL(base) |= PPCA_ATOPSS_DCSG_GRP_DAC_R2R_DAC_CTL_DAC_EN_Msk;
}

/******************************************************************************
* Function Name: Cy_PPCA_DAC_Disable
***************************************************************************//**
*
* Disables the DAC
*
* \param base The pointer to the DACR2R instance address.
*
******************************************************************************/
__STATIC_INLINE void Cy_PPCA_DAC_Disable(ATOPSS_DAC_TYPE *base)
{
    PPCA_ATOP_DAC_CTL(base) &= (uint32_t) ~PPCA_ATOPSS_DCSG_GRP_DAC_R2R_DAC_CTL_DAC_EN_Msk;
}

/******************************************************************************
* Function Name: Cy_PPCA_DACBUF_Enable
***************************************************************************//**
*
* Enables the DAC Buf
*
* \param base The pointer to the DACR2R instance address.
*
******************************************************************************/
__STATIC_INLINE void Cy_PPCA_DACBUF_Enable(ATOPSS_DAC_TYPE *base)
{
    PPCA_ATOP_DAC_CTL(base) |= PPCA_ATOPSS_DCSG_GRP_DAC_R2R_DAC_CTL_DAC_BUFF_EN_Msk;
}

/******************************************************************************
* Function Name: Cy_PPCA_DACBUF_Disable
***************************************************************************//**
*
* Disables the DAC Buf
*
* \param base The pointer to the DACR2R instance address.
*
******************************************************************************/
__STATIC_INLINE void Cy_PPCA_DACBUF_Disable(ATOPSS_DAC_TYPE *base)
{
    PPCA_ATOP_DAC_CTL(base) &= (uint32_t) ~PPCA_ATOPSS_DCSG_GRP_DAC_R2R_DAC_CTL_DAC_BUFF_EN_Msk;
}

/******************************************************************************
* Function Name: Cy_PPCA_DAC_Set_DACOut
***************************************************************************//**
*
* Sets DAC Data Output
*
* \param base The pointer to the DACR2R instance address.
*
* \param dac_output_value 12 bit DAC output value.
*
******************************************************************************/
__STATIC_INLINE void Cy_PPCA_DAC_Set_DACOut(ATOPSS_DAC_TYPE *base, uint16_t dac_output_value)
{
    PPCA_ATOP_DAC_DOUT(base) = _VAL2FLD(PPCA_ATOPSS_DCSG_GRP_DAC_R2R_DAC_DOUT_DOUT, dac_output_value);
}

/** \} group_ppca_dacr2r_functions */



#if defined(__cplusplus)
}
#endif
#endif /*defined (CY_IP_MXS40PPSS) || defined (CY_DOXYGEN) */

#endif /* CY_PPCA_DACR2R_H */

