/***************************************************************************//**
* \file cy_trigmux.c
* \version 1.0.1
*
* \brief Trigger mux API.
*
********************************************************************************
* \copyright
* Copyright 2016-2020 Cypress Semiconductor Corporation
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

#include "cy_trigmux.h"
#include "cy_device.h"

#if defined(CY_IP_M0S8PERI_TR)

#define CY_TRIGMUX_IS_CYCLES_VALID(cycles)      (CY_TRIGGER_INFINITE >= (cycles))

#define CY_TRIGMUX_INTRIG_MASK                  (PERI_TR_CTL_TR_GROUP_Msk | PERI_TR_GROUP_TR_OUT_CTL_SEL_Msk)
#define CY_TRIGMUX_IS_INTRIG_VALID(inTrg)       (0UL == ((inTrg) & (uint32_t)~CY_TRIGMUX_INTRIG_MASK))

#define CY_TRIGMUX_OUTTRIG_MASK                 (PERI_TR_CTL_TR_OUT_Msk | PERI_TR_CTL_TR_GROUP_Msk | PERI_TR_CTL_TR_SEL_Msk)
#define CY_TRIGMUX_IS_OUTTRIG_VALID(outTrg)     ((0UL == ((outTrg) & (uint32_t)~CY_TRIGMUX_OUTTRIG_MASK)) && \
                                                 (0UL != ((outTrg) & PERI_TR_CTL_TR_OUT_Msk)))

#define CY_TRIGMUX_TRIGLINE_MASK                (PERI_TR_CTL_TR_OUT_Msk | PERI_TR_CTL_TR_GROUP_Msk | PERI_TR_CTL_TR_SEL_Msk)
#define CY_TRIGMUX_IS_TRIGLINE_VALID(trgLn)     (0U == ((trgLn) & (uint32_t)~CY_TRIGMUX_TRIGLINE_MASK))

#define CY_TRIGMUX_TR_CTL(outTrig)              (PERI_TR_GR_TR_CTL(_FLD2VAL(PERI_TR_CTL_TR_GROUP, outTrig), \
                                                                   _FLD2VAL(PERI_TR_CTL_TR_SEL,   outTrig)))


/*******************************************************************************
* Function Name: Cy_TrigMux_Connect
****************************************************************************//**
*
* Connects an input trigger source and output trigger.
*
* \param inTrig
* An input selection for the trigger mux.
* - Bit 30 should be cleared.
* - Bits 11:8 represent the trigger group selection.
* - Bits 6:0 select the input trigger signal for the specified trigger multiplexer.
*
* \param outTrig
* The output of the trigger mux. This refers to the consumer of the trigger mux.
* - Bit 30 should be set.
* - Bits 11:8 represent the trigger group selection.<br>
* - Bits 6:0 select the output trigger number in the trigger group.<br>
*
* \return status:
* - CY_TRIGMUX_SUCCESS: The connection is made successfully.
* - CY_TRIGMUX_BAD_PARAM: Some parameter is invalid.
*
* \funcusage
* \snippet trigmux_snippet.c snippet_Cy_TrigMux_Connect
*  
*******************************************************************************/
cy_en_trigmux_status_t Cy_TrigMux_Connect(uint32_t inTrig, uint32_t outTrig)
{
    cy_en_trigmux_status_t retVal = CY_TRIGMUX_BAD_PARAM;
    CY_ASSERT_L2(CY_TRIGMUX_IS_INTRIG_VALID(inTrig));
    CY_ASSERT_L2(CY_TRIGMUX_IS_OUTTRIG_VALID(outTrig));

    /* inTrig and outTrig should be in the same group */
    if ((inTrig & PERI_TR_CTL_TR_GROUP_Msk) == (outTrig & PERI_TR_CTL_TR_GROUP_Msk))
    {
        uint32_t interruptState = Cy_SysLib_EnterCriticalSection();

        CY_TRIGMUX_TR_CTL(outTrig) = (CY_TRIGMUX_TR_CTL(outTrig) &
                                      (uint32_t)~(PERI_TR_GROUP_TR_OUT_CTL_SEL_Msk)) |
                                        (_VAL2FLD(PERI_TR_GROUP_TR_OUT_CTL_SEL, inTrig));

        Cy_SysLib_ExitCriticalSection(interruptState);

        retVal = CY_TRIGMUX_SUCCESS;
    }

    return retVal;
}


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
*   the trigger multiplexer.
* - Bits 11:8 represent the trigger group selection.<br>
* In case of output trigger line (bit 30 is set):
* - Bits 6:0 select the output trigger number in the trigger group.
* In case of input trigger line (bit 30 is unset):
* - Bits 6:0 select the input trigger signal for the trigger multiplexer.
*
* \param cycles
*  The number of "Clk_Peri" cycles during which the trigger remains activated.<br>
*  The valid range of cycles is 1 ... 254.<br>
*  Also there are special values:
*   - CY_TRIGGER_INFINITE - trigger remains activated until the user deactivates it by
*   calling this function with CY_TRIGGER_DEACTIVATE parameter.
*   - CY_TRIGGER_DEACTIVATE - this is used to deactivate the trigger activated by
*   calling this function with CY_TRIGGER_INFINITE parameter.
* 
* \return status:
* - CY_TRIGMUX_SUCCESS: The trigger is successfully activated/deactivated.
* - CY_TRIGMUX_INVALID_STATE: The trigger is already activated/not active.
*
* \funcusage
* \snippet trigmux_snippet.c snippet_Cy_TrigMux_SwTrigger
*
*******************************************************************************/
cy_en_trigmux_status_t Cy_TrigMux_SwTrigger(uint32_t trigLine, uint32_t cycles)
{
    cy_en_trigmux_status_t retVal = CY_TRIGMUX_INVALID_STATE;

    CY_ASSERT_L2(CY_TRIGMUX_IS_TRIGLINE_VALID(trigLine));
    CY_ASSERT_L2(CY_TRIGMUX_IS_CYCLES_VALID(cycles));

    if (CY_TRIGGER_DEACTIVATE != cycles)
    {
        /* Activate the trigger if it is not in the active state. */
        if (PERI_TR_CTL_TR_ACT_Msk != (PERI_TR_CTL & PERI_TR_CTL_TR_ACT_Msk))
        {

            uint32_t trCmd = (trigLine & (PERI_TR_CTL_TR_SEL_Msk |
                                          PERI_TR_CTL_TR_OUT_Msk |
                                          PERI_TR_CTL_TR_GROUP_Msk)) |
                                          PERI_TR_CTL_TR_ACT_Msk;
            
            PERI_TR_CTL = trCmd | _VAL2FLD(PERI_TR_CTL_TR_COUNT, cycles);

            retVal = CY_TRIGMUX_SUCCESS;
        }
    }
    else
    {
        /* Forcibly deactivate the trigger if it is in the active state. */
        if (PERI_TR_CTL_TR_ACT_Msk == (PERI_TR_CTL & PERI_TR_CTL_TR_ACT_Msk))
        {
            PERI_TR_CTL = 0UL;

            retVal = CY_TRIGMUX_SUCCESS;
        }
    }

    return retVal;
}


#endif /* defined(CY_IP_M0S8PERI_TR) */

/* [] END OF FILE */
