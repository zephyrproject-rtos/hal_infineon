/*******************************************************************************
* \file cy_trigmux.h
* \version 1.70
*
*  This file provides constants and parameter values for the Trigger multiplexer driver.
*
********************************************************************************
* \copyright
* Copyright (c) (2016-2025), Cypress Semiconductor Corporation (an Infineon company) or
* an affiliate of Cypress Semiconductor Corporation.
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
* \addtogroup group_trigmux
* \{
* The trigger multiplexer provides access to the multiplexer that selects a set
* of trigger output signals from different peripheral blocks to route them to the
* specific trigger input of another peripheral block.
*
* The functions and other declarations used in this driver are in cy_trigmux.h.
* You can include cy_pdl.h to get access to all functions
* and declarations in the PDL.
*
* The TrigMux driver is based on the trigger multiplexer's hardware block.
* The Trigger multiplexer block consists of multiple trigger multiplexers.
* These trigger multiplexers are grouped in trigger groups. All the trigger
* multiplexers in the trigger group share similar input options.
*
*
* The trigger multiplexer groups structure is flat - all the groups are essentially
* distribution multiplexers (there are no any intermediate trigger signals), so the
* structure is simpler in comparison with PERI_ver1, however a bit less flexible.
* Additionally there are another type of trigger interconnections: one-to-one
* trigger lines. These are not multiplexers, only single trigger wires from/to
* the dedicated peripherals. Multiple groups of one-to-one trigger lines
* significantly improve the whole triggering interconnect system flexibility.
*
* The trigger architecture of the PSoC device is explained in the technical reference
* manual (TRM). Refer to the TRM to better understand the trigger multiplexer routing
* architecture available.
*
* \section group_trigmux_section_Configuration_Considerations Configuration Considerations
*
*
* To route a trigger signal from one peripheral in the PSoC device to another, the user can configure
* either a trigger multiplexer using \ref Cy_TrigMux_Connect or a one-to-one trigger line
* using \ref Cy_TrigMux_Select. Only one function call is required to connect one peripheral
* to another (unlike for PERI_ver1).
*
* The Cy_TrigMux_Connect() function has two main parameters, inTrig and outTrig that
* refer to the input and output trigger lines connected using the multiplexer.
* These parameters are represented in the following format:<br>
* \image html trigmux_parameter_30_2.png
* In addition, the \ref Cy_TrigMux_Connect function also has an invert and trigger type parameter.
* Refer to the API reference for a detailed description of this parameter.
* All the constants associated with the different trigger signals in the system
* (input and output) are defined as constants in the device configuration header file.
*
*
* There are two types of TrigMux signal definitions in the device configuration header:
* 1) The parameters for the trigger interconnection system input signals.
* 2) The parameters for the trigger interconnection system output signals.
* Also there are separate groups of trigger multiplexer input/outputs and groups of
* trigger one-to-one line input/outputs.
*
* Refer to the TRM for a more detailed description of this architecture and different options.
*
* The steps to connect one peripheral block to the other:
*
*
* Step 1. Find the trigger group number in the Trigger Group Inputs section of the device
* configuration header file that corresponds to the output of the source peripheral block.
* For example, TRIG_IN_MUX_0_TCPWM0_TR_OVERFLOW0 (see \ref group_trigmux_in_enums) TrigMux
* input belongs to Trigger Group 0. It is the same TCPWM0 counter 0 overflow output
* (as in the example for PERI_ver1).
*
* Step 2. Find the same trigger group number in the Trigger Group Outputs section of the
* device configuration header file that corresponds to the trigger group number found in
* Step 1. Select the TrigMux output that can be connected to the destination peripheral block.
* For example, TRIG_OUT_MUX_0_PDMA0_TR_IN0 (see \ref group_trigmux_out_enums) means that the
* trigger multiplexer Output 0 of Trigger Group 0 can be connected to the DW0 channel 0 trigger
* input (the same DMA channel as mentioned in the example for PERI_ver1).
*
* Step 3. Call Cy_TrigMux_Connect() API once:
* \snippet trigmux/snippet/main.c snippet_Cy_TrigMux_PERI_ver2
*
* \section group_trigmux_more_information More Information
* For more information on the TrigMux peripheral, refer to the technical reference manual (TRM).
*
* \section group_trigmux_Changelog Changelog
* <table class="doxtable">
*   <tr><th>Version</th><th>Changes</th><th>Reason for Change</th></tr>
*   <tr>
*     <td>1.70</td>
*     <td>Updated \ref Cy_TrigMux_SwTrigger and \ref Cy_TrigMux_Connect APIs.</td>
*     <td>Performance enhancement and bug fixes.</td>
*   </tr>
*   <tr>
*     <td>1.60.1</td>
*     <td>Updated \ref Cy_TrigMux_SwTrigger API.</td>
*     <td>Coverity error fixes.</td>
*   </tr>
*   <tr>
*     <td>1.60</td>
*     <td>Updated Cy_TrigMux_SwTrigger API and added CY_TRIGMUX_INTRIG_MASK macro.</td>
*     <td>Support for PSE8 Devices added.</td>
*   </tr>
*   <tr>
*     <td>1.50</td>
*     <td>Updated driver to support the CAT1C family of devices.</td>
*     <td>Added new family of devices.</td>
*   </tr>
*   <tr>
*     <td>1.40</td>
*     <td>Fixed MISRA violation.</td>
*     <td>MISRA compliance.</td>
*   </tr>
*   <tr>
*     <td rowspan="2">1.30</td>
*     <td>Minor bug fixes.</td>
*     <td>Keep device specific changes under a compile time device flag.</td>
*   </tr>
*   <tr>
*     <td>Added new device support.</td>
*     <td>Added new family of device.</td>
*   </tr>
*   <tr>
*     <td>1.20.3</td>
*     <td>Minor documentation updates.</td>
*     <td>Removed MISRA 2004 compliance details and verified MISRA 2012 compliance.</td>
*   </tr>
*   <tr>
*     <td>1.20.2</td>
*     <td>Minor documentation updates.</td>
*     <td>Documentation enhancement.</td>
*   </tr>
*   <tr>
*     <td>1.20.1</td>
*     <td>Documentation is extended/improved.</td>
*     <td>Enhancement based on usability feedback.</td>
*   </tr>
*   <tr>
*     <td rowspan="3">1.20</td>
*     <td>Flattened the organization of the driver source code into the single source directory and the single include directory.</td>
*     <td>Driver library directory-structure simplification.</td>
*   </tr>
*   <tr>
*     <td>Added new API functions:
*         - \ref Cy_TrigMux_Select
*         - \ref Cy_TrigMux_Deselect
*         - \ref Cy_TrigMux_SetDebugFreeze
*
*         Modified the \ref Cy_TrigMux_SwTrigger API function logic.
*     </td>
*     <td>New devices support.</td>
*   </tr>
*   <tr>
*     <td>Added register access layer. Use register access macros instead
*         of direct register access using dereferenced pointers.</td>
*     <td>Makes register access device-independent, so that the PDL does
*         not need to be recompiled for each supported part number.</td>
*   </tr>
*   <tr>
*     <td>1.10.1</td>
*     <td>Renamed the internal macro in Cy_TrigMux_Connect()
*          function to CY_TRIGMUX_IS_TRIGTYPE_VALID.</td>
*     <td></td>
*   </tr>
*   <tr>
*     <td>1.10</td>
*     <td>The input/output bit in the trigLine parameter of the
*         Cy_TrigMux_SwTrigger() function is changed to 30.<br>
*         The invert parameter type is changed to bool.<br>
*         Added input parameter validation to the API functions.</td>
*     <td></td>
*   </tr>
*   <tr>
*     <td>1.0</td>
*     <td>Initial version</td>
*     <td></td>
*   </tr>
* </table>
*
* \defgroup group_trigmux_macros Macros
* \defgroup group_trigmux_functions Functions
* \defgroup group_trigmux_enums Enumerated Types
*/

#if !defined(CY_TRIGMUX_H)
#define CY_TRIGMUX_H

#include "cy_device.h"

#if defined (CY_IP_MXSPERI) || defined (CY_IP_MXPERI)

#include "cy_syslib.h"

#if defined(__cplusplus)
extern "C" {
#endif
/******************************************************************************
 * Macros
 *****************************************************************************/

/**
* \addtogroup group_trigmux_macros
* \{
*/

/** The driver major version */
#define CY_TRIGMUX_DRV_VERSION_MAJOR       1

/** The driver minor version */
#define CY_TRIGMUX_DRV_VERSION_MINOR       70

/** TRIGMUX PDL ID */
#define CY_TRIGMUX_ID                       CY_PDL_DRV_ID(0x33UL) /**< The trigger multiplexer driver identifier */

/** Values for the cycles parameter in the \ref Cy_TrigMux_SwTrigger() function */
#define CY_TRIGGER_INFINITE                 (255UL) /**< The trigger will be active until the user clears it or a hardware deactivates it. */
#define CY_TRIGGER_DEACTIVATE               (0UL)   /**< Use this parameter value to deactivate the trigger. */
#define CY_TRIGGER_TWO_CYCLES               (2UL)   /**< The only valid cycles number value for PERI_ver2. */

/** \} group_trigmux_macros */

/** \cond BWC macros */
#define CY_TR_MUX_TR_INV_ENABLE            (0x01u)
#define CY_TR_MUX_TR_INV_DISABLE           (0x00u)
#define CY_TR_ACTIVATE_DISABLE             (0x00u)
#define CY_TR_ACTIVATE_ENABLE              (0x01u)
#define CY_TR_GROUP_MASK                   (0x0F00u)
#define CY_TR_MASK                         (0x007Fu)
#define CY_TR_GROUP_SHIFT                  (0x08u)
#define CY_TR_OUT_CTL_MASK                 (0x40000000uL)
#define CY_TR_OUT_CTL_SHIFT                (30u)
#define CY_TR_PARAM_MASK                   (CY_TR_OUT_CTL_MASK | CY_TR_GROUP_MASK | CY_TR_MASK)
#define CY_TR_CYCLES_MIN                   (0u)
#define CY_TR_CYCLES_MAX                   (255u)
/** \endcond */

/** \cond INTERNAL */
#define CY_TRIGMUX_IS_TRIGTYPE_VALID(trigType)  (((trigType) == TRIGGER_TYPE_EDGE) || \
                                                 ((trigType) == TRIGGER_TYPE_LEVEL))

#define CY_TRIGMUX_V1_IS_CYCLES_VALID(cycles)   (CY_TRIGGER_INFINITE >= (cycles))
#define CY_TRIGMUX_V2_IS_CYCLES_VALID(cycles)   ((CY_TRIGGER_DEACTIVATE == (cycles)) || \
                                                 (CY_TRIGGER_TWO_CYCLES == (cycles)) || \
                                                 (CY_TRIGGER_INFINITE   == (cycles)))
#define CY_TRIGMUX_IS_CYCLES_VALID(cycles)      (CY_TRIGMUX_V2_IS_CYCLES_VALID(cycles))


# if defined (CY_IP_MXSPERI) && (CY_IP_MXSPERI_INSTANCES == 2)
#define CY_TRIGMUX_INTRIG_MASK                  (PERI_TR_CMD_GROUP_SEL_Msk | PERI_TR_GR_TR_OUT_CTL_TR_SEL_Msk | PERI_INSTANCE_1_IDENT_Msk)
#endif
#if !defined(CY_IP_MXSPERI) || (CY_IP_MXSPERI_INSTANCES != 2)
#define CY_TRIGMUX_INTRIG_MASK                  (PERI_TR_CMD_GROUP_SEL_Msk | PERI_TR_GR_TR_OUT_CTL_TR_SEL_Msk)
#endif /* (CY_IP_MXSPERI) && (CY_IP_MXSPERI_INSTANCES==2) */
#define CY_TRIGMUX_IS_INTRIG_VALID(inTrg)       (0UL == ((inTrg) & (uint32_t)~CY_TRIGMUX_INTRIG_MASK))

# if defined (CY_IP_MXSPERI) && (CY_IP_MXSPERI_INSTANCES == 2)
#define CY_TRIGMUX_OUTTRIG_MASK                 (PERI_TR_CMD_OUT_SEL_Msk | PERI_TR_CMD_GROUP_SEL_Msk | CY_PERI_TR_CTL_SEL_Msk | PERI_INSTANCE_1_IDENT_Msk)
#else
#define CY_TRIGMUX_OUTTRIG_MASK                 (PERI_TR_CMD_OUT_SEL_Msk | PERI_TR_CMD_GROUP_SEL_Msk | CY_PERI_TR_CTL_SEL_Msk)
#endif /* (CY_IP_MXSPERI) && (CY_IP_MXSPERI_INSTANCES==2) */
#define CY_TRIGMUX_IS_OUTTRIG_VALID(outTrg)     ((0UL == ((outTrg) & (uint32_t)~CY_TRIGMUX_OUTTRIG_MASK)) && \
                                                 (0UL != ((outTrg) & PERI_TR_CMD_OUT_SEL_Msk)))

#define CY_TRIGMUX_ONETRIG_MASK                 (PERI_V2_TR_CMD_OUT_SEL_Msk | PERI_V2_TR_CMD_GROUP_SEL_Msk | CY_PERI_TR_CTL_SEL_Msk)

#if defined (CY_IP_MXSPERI) || (CY_IP_MXPERI_VERSION >= 3)
#define CY_TRIGMUX_ONETRIG_GR_START                0x10UL /* trigger 1-1 group [16-31] */
#define CY_TRIGMUX_IS_ONETRIG_VALID(oneTrg)     ((0UL == ((oneTrg) & (uint32_t)~CY_TRIGMUX_ONETRIG_MASK)) && \
                                                 (0UL != ((oneTrg) & PERI_V2_TR_CMD_OUT_SEL_Msk)) && \
                                                 (0UL != (_FLD2VAL(PERI_V2_TR_CMD_GROUP_SEL, oneTrg) & (uint32_t)CY_TRIGMUX_ONETRIG_GR_START)))
#endif
 
# if defined (CY_IP_MXSPERI) && (CY_IP_MXSPERI_INSTANCES == 2U)
#define CY_TRIGMUX_TRIGLINE_MASK                (PERI_TR_CMD_OUT_SEL_Msk | CY_PERI_TR_CMD_GROUP_SEL_Msk | CY_PERI_TR_CTL_SEL_Msk | PERI_INSTANCE_1_IDENT_Msk)
#else
#define CY_TRIGMUX_TRIGLINE_MASK                (PERI_TR_CMD_OUT_SEL_Msk | CY_PERI_TR_CMD_GROUP_SEL_Msk | CY_PERI_TR_CTL_SEL_Msk)
#endif /* (CY_IP_MXSPERI) && (CY_IP_MXSPERI_INSTANCES == 2U) */
#define CY_TRIGMUX_IS_TRIGLINE_VALID(trgLn)     (0U == ((trgLn) & (uint32_t)~CY_TRIGMUX_TRIGLINE_MASK))

#if defined (CY_IP_MXSPERI) && (CY_IP_MXSPERI_INSTANCES == 2U)
#define CY_TRIGMUX1_TR_CTL(outTrig)   (PERI1_TR_GR_TR_CTL(_FLD2VAL(CY_PERI_TR_CMD_GROUP_SEL, outTrig), _FLD2VAL(CY_PERI_TR_CTL_SEL, outTrig)))
#endif
#define CY_TRIGMUX_TR_CTL(outTrig)    (PERI_TR_GR_TR_CTL(_FLD2VAL(CY_PERI_TR_CMD_GROUP_SEL, outTrig), _FLD2VAL(CY_PERI_TR_CTL_SEL, outTrig)))

/** \endcond */

/**
* \addtogroup group_trigmux_enums
* \{
*/

/******************************************************************************
 * Enumerations
 *****************************************************************************/

/** The TRIGMUX error codes. */
typedef enum
{
    CY_TRIGMUX_SUCCESS = 0x0UL,                                             /**< Successful */
    CY_TRIGMUX_BAD_PARAM = CY_TRIGMUX_ID | CY_PDL_STATUS_ERROR | 0x1UL,     /**< One or more invalid parameters */
    CY_TRIGMUX_INVALID_STATE = CY_TRIGMUX_ID | CY_PDL_STATUS_ERROR | 0x2UL  /**< Operation not set up or is in an improper state */
} cy_en_trigmux_status_t;

/** \} group_trigmux_enums */

/**
* \addtogroup group_trigmux_functions
* \{
*/

cy_en_trigmux_status_t Cy_TrigMux_Connect(uint32_t inTrig, uint32_t outTrig, bool invert, en_trig_type_t trigType);
__STATIC_INLINE cy_en_trigmux_status_t Cy_TrigMux_SwTrigger(uint32_t trigLine, uint32_t cycles);
cy_en_trigmux_status_t Cy_TrigMux_Select(uint32_t outTrig, bool invert, en_trig_type_t trigType);
cy_en_trigmux_status_t Cy_TrigMux_Deselect(uint32_t outTrig);
cy_en_trigmux_status_t Cy_TrigMux_SetDebugFreeze(uint32_t outTrig, bool enable);

/*******************************************************************************
* Function Name: Cy_TrigMux_SwTrigger
****************************************************************************//**
*
* This function generates a software trigger on an input trigger line.
* All output triggers connected to this input trigger will be triggered.
* The function also verifies that there is no activated trigger before
* generating another activation.
*
* \param trigLine
* The input of the trigger mux.
* - Bit 30 represents if the signal is an input/output. When this bit is set,
*   the trigger activation is for an output trigger from the trigger multiplexer.
*   When this bit is reset, the trigger activation is for an input trigger to
*   the trigger multiplexer.<br>
* - For PERI_ver1 Bits 11:8 represent the trigger group selection.<br>
* - For PERI_ver2 Bits 12:8 represent the trigger group selection.<br>
* In case of output trigger line (bit 30 is set):<br>
* For PERI_ver1:
* - Bits 6:0 select the output trigger number in the trigger group.<br>
* For PERI_ver2:
* - Bits 7:0 select the output trigger number in the trigger group.<br>
* In case of input trigger line (bit 30 is unset):
* - Bits 7:0 select the input trigger signal for the trigger multiplexer.
*
* \param cycles
*  The number of "Clk_Peri" cycles during which the trigger remains activated.<br>
*  For PERI_ver1: The valid range of cycles is 1 ... 254.<br>
*  For PERI_ver2: The only valid value of cycles is 2 (\ref CY_TRIGGER_TWO_CYCLES).<br>
*  Also there are special values (supported with both PERI_ver1 and PERI_ver2):
*   - CY_TRIGGER_INFINITE - trigger remains activated until the user deactivates it by
*   calling this function with CY_TRIGGER_DEACTIVATE parameter.
*   - CY_TRIGGER_DEACTIVATE - this is used to deactivate the trigger activated by
*   calling this function with CY_TRIGGER_INFINITE parameter.
*
* \return status:
* - CY_TRIGMUX_SUCCESS: The trigger is successfully activated/deactivated.
* - CY_TRIGMUX_INVALID_STATE: The trigger is already activated/not active.
* - CY_TRIGMUX_BAD_PARAM: Some parameter is invalid.
*
* \funcusage
* \snippet trigmux/snippet/main.c snippet_Cy_TrigMux_SwTrigger
*
*******************************************************************************/
__STATIC_INLINE cy_en_trigmux_status_t Cy_TrigMux_SwTrigger(uint32_t trigLine, uint32_t cycles)
{
    cy_en_trigmux_status_t retVal = CY_TRIGMUX_INVALID_STATE;

    CY_ASSERT_L2(CY_TRIGMUX_IS_TRIGLINE_VALID(trigLine));
    CY_ASSERT_L2(CY_TRIGMUX_IS_CYCLES_VALID(cycles));

    if (CY_TRIGGER_DEACTIVATE != cycles)
    {
        /* Activate the trigger if it is not in the active state. */
        if (PERI_TR_CMD_ACTIVATE_Msk != (PERI_TR_CMD & PERI_TR_CMD_ACTIVATE_Msk))
        {

            uint32_t trCmd = (trigLine & (PERI_TR_CMD_TR_SEL_Msk |
                                          PERI_TR_CMD_OUT_SEL_Msk |
                                       CY_PERI_TR_CMD_GROUP_SEL_Msk)) |
                                          PERI_TR_CMD_ACTIVATE_Msk;

            retVal = CY_TRIGMUX_SUCCESS;

            if (CY_TRIGGER_TWO_CYCLES == cycles) /* mxperi_v2 or later, 2 cycles pulse */
            {
#if defined(CY_IP_MXSPERI_INSTANCES) && (CY_IP_MXSPERI_INSTANCES == 2U)
                if (0UL != (trigLine & PERI_INSTANCE_1_IDENT_Msk))
                {
                    PERI1_TR_CMD = trCmd | PERI_V2_TR_CMD_TR_EDGE_Msk;
                }
                else
                {
                    PERI_TR_CMD = trCmd | PERI_V2_TR_CMD_TR_EDGE_Msk;
                }
#else
                PERI_TR_CMD = trCmd | PERI_V2_TR_CMD_TR_EDGE_Msk;
#endif
            }
            else if (CY_TRIGGER_INFINITE == cycles) /* mxperi_v2 or later, infinite activating */
            {
                PERI_TR_CMD = trCmd;
            }
            else /* mxperi_v2 or later, invalid cycles value */
            {
                retVal = CY_TRIGMUX_BAD_PARAM;
            }
         }
    }
    else
    {
        /* Forcibly deactivate the trigger if it is in the active state. */
        if (PERI_TR_CMD_ACTIVATE_Msk == (PERI_TR_CMD & PERI_TR_CMD_ACTIVATE_Msk))
        {
            PERI_TR_CMD = 0UL;

            retVal = CY_TRIGMUX_SUCCESS;
        }
    }

    return retVal;
}
/** \} group_trigmux_functions */

CY_MISRA_BLOCK_END('MISRA C-2012 Rule 14.3')

#if defined(__cplusplus)
}
#endif

#endif /* CY_IP_MXSPERI, CY_IP_MXPERI */

#endif /* CY_TRIGMUX_H */

/** \} group_trigmux */

/* [] END OF FILE */
