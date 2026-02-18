/***************************************************************************//**
* \file cy_ppca_epu.c
* \version 1.0
*
* \brief
* Provides API implementation of the PPCA EPU driver.
*
********************************************************************************
* \copyright
* (c) 2023-2026, Infineon Technologies AG or an affiliate of
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

#include "cy_device.h"

#if defined (CY_IP_MXS40PPSS)

#include "cy_ppca_epu.h"

#if defined(__cplusplus)
extern "C" {
#endif

void Cy_PPCA_EPU_PU_T1_Configure( PPCA_EPU_EPU_Type *base, uint32_t index, cy_stc_ppca_epu_PU_T1_config_t const *config)
{
    CY_ASSERT_L1(CY_IS_PARAM_VALID(base));
    CY_ASSERT_L1(CY_IS_PARAM_VALID(config));
    CY_ASSERT_L2(CY_IS_PUT1_INDEX_VALID(index));

    PPCA_EPU_EPU_PU_T1_CNFG(base, index) = _VAL2FLD(PPCA_EPU_EPU_PU_T1_CNFG_PUT1_EN, CY_PU_DISABLE)                              |
                                                 _BOOL2FLD(PPCA_EPU_EPU_PU_T1_CNFG_PUT1_POL, config->inpPolarityInv)             |
                                                 _VAL2FLD(PPCA_EPU_EPU_PU_T1_CNFG_PUT1_IN_SEL, config->PUT1_IN_Sel)              |
                                                 _VAL2FLD(PPCA_EPU_EPU_PU_T1_CNFG_OPCODE, config->opcode)                        |
                                                 _VAL2FLD(PPCA_EPU_EPU_PU_T1_CNFG_DATA, (uint32_t)config->clk_cycles)            |
                                                 _BOOL2FLD(PPCA_EPU_EPU_PU_T1_CNFG_PUT1_ENQ, config->PUT1_ENQ)                   |
                                                 _BOOL2FLD(PPCA_EPU_EPU_PU_T1_CNFG_PUT1_SEL_CONSTANT_IN, config->swEventEnable)  |
                                                 _VAL2FLD(PPCA_EPU_EPU_PU_T1_CNFG_PUT1_CONSTANT_IN, config->inputLevel)          |
                                                 _VAL2FLD(PPCA_EPU_EPU_PU_T1_CNFG_PUT1_SRC_SEL, (uint32_t)config->PUT1_SRC_SEL)  |
                                                 _VAL2FLD(PPCA_EPU_EPU_PU_T1_CNFG_PUT1_SRCQ_SEL, (uint32_t)config->PUT1_SRCQ_SEL);
}


void Cy_PPCA_EPU_PU_T2_Configure( PPCA_EPU_EPU_Type *base, uint32_t index, cy_stc_ppca_epu_PU_T2_config_t const *config)
{
    CY_ASSERT_L1(CY_IS_PARAM_VALID(base));
    CY_ASSERT_L1(CY_IS_PARAM_VALID(config));
    CY_ASSERT_L2(CY_IS_PUT2_INDEX_VALID(index));

    PPCA_EPU_EPU_PU_T2_CNFG(base, index) = _VAL2FLD(PPCA_EPU_EPU_PU_T2_CNFG_PUT2_EN, CY_PU_DISABLE)                              |
                                                 _BOOL2FLD(PPCA_EPU_EPU_PU_T2_CNFG_PUT2_POL, config->inpPolarityInv)             |
                                                 _BOOL2FLD(PPCA_EPU_EPU_PU_T2_CNFG_PUT2_SEL_CONSTANT_IN, config->swEventEnable)  |
                                                 _VAL2FLD(PPCA_EPU_EPU_PU_T2_CNFG_PUT2_CONSTANT_IN, config->inputLevel)          |
                                                 _VAL2FLD(PPCA_EPU_EPU_PU_T2_CNFG_PUT2_IN_SEL, config->PUT2_IN_Sel)              |
                                                 _VAL2FLD(PPCA_EPU_EPU_PU_T2_CNFG_PUT2_SRC_SEL,(uint32_t) config->PUT2_SRC_SEL);
}


void Cy_PPCA_EPU_Combo_Configure( PPCA_EPU_EPU_Type *base, uint32_t index, cy_stc_ppca_epu_combo_config_t const *config)
{
    CY_ASSERT_L1(CY_IS_PARAM_VALID(base));
    CY_ASSERT_L1(CY_IS_PARAM_VALID(config));
    CY_ASSERT_L2(CY_IS_COMBO_INDEX_VALID(index));

    PPCA_EPU_EPU_COMBO_CNFG(base, index) = _VAL2FLD(PPCA_EPU_EPU_COMBO_CNFG_BANK_SEL, config->bankSel)             |
                                         _VAL2FLD(PPCA_EPU_EPU_COMBO_CNFG_PUT1_IN_EN, config->put1InEnable)        |
                                         _VAL2FLD(PPCA_EPU_EPU_COMBO_CNFG_PU_SRC_IN, config->puSrcIn)              |
                                         _VAL2FLD(PPCA_EPU_EPU_COMBO_CNFG_PU_SRC_IN_EN, config->srcInEnable)       |
                                         _VAL2FLD(PPCA_EPU_EPU_COMBO_CNFG_PU_IN_QUALIFIER, config->inQual)         |
                                         _BOOL2FLD(PPCA_EPU_EPU_COMBO_CNFG_PU_IN_QUALIFIER_EN, config->enableQual) |
                                         _BOOL2FLD(PPCA_EPU_EPU_COMBO_CNFG_COMBO_POL, config->enablePolInv);
}


void Cy_PPCA_EPU_PU_T1_Enable(PPCA_EPU_EPU_Type *base, uint32_t index, cy_en_ppca_epu_en_pu_t enable)
{
    uint32_t tempReg;
    tempReg = (PPCA_EPU_EPU_PU_T1_CNFG(base, index) & (~PPCA_EPU_EPU_PU_T1_CNFG_PUT1_EN_Msk));
    PPCA_EPU_EPU_PU_T1_CNFG(base, index) = tempReg | _VAL2FLD(PPCA_EPU_EPU_PU_T1_CNFG_PUT1_EN, enable);
}


void Cy_PPCA_EPU_PU_T1_Select_Input(PPCA_EPU_EPU_Type *base, uint32_t index, cy_en_ppca_epu_input_pu_t input)
{
    uint32_t tempReg;
    tempReg = (PPCA_EPU_EPU_PU_T1_CNFG(base, index) & (~PPCA_EPU_EPU_PU_T1_CNFG_PUT1_IN_SEL_Msk));
    PPCA_EPU_EPU_PU_T1_CNFG(base, index) = tempReg | _VAL2FLD(PPCA_EPU_EPU_PU_T1_CNFG_PUT1_IN_SEL, input);
}


void Cy_PPCA_EPU_PU_T1_Select_ProcessingFunc(PPCA_EPU_EPU_Type *base, uint32_t index, cy_en_ppca_epu_pu_processing_func_t func, uint32_t clk_cycles)
{
    uint32_t tempReg;
    tempReg = (PPCA_EPU_EPU_PU_T1_CNFG(base, index) & 
              (~(PPCA_EPU_EPU_PU_T1_CNFG_OPCODE_Msk | PPCA_EPU_EPU_PU_T1_CNFG_DATA_Msk)));
    PPCA_EPU_EPU_PU_T1_CNFG(base, index) = tempReg | _VAL2FLD(PPCA_EPU_EPU_PU_T1_CNFG_OPCODE, func) |
                                                           _VAL2FLD(PPCA_EPU_EPU_PU_T1_CNFG_DATA, clk_cycles);
}


void Cy_PPCA_EPU_PU_T1_Config_QualifierInput(PPCA_EPU_EPU_Type *base, uint32_t index, bool enable, uint8_t qualInSrc)
{
    if(enable)
    {
        uint32_t tempReg;
        tempReg = (PPCA_EPU_EPU_PU_T1_CNFG(base, index) & 
                  (~(PPCA_EPU_EPU_PU_T1_CNFG_PUT1_ENQ_Msk | PPCA_EPU_EPU_PU_T1_CNFG_PUT1_SRCQ_SEL_Msk)));
        PPCA_EPU_EPU_PU_T1_CNFG(base, index) = tempReg | _VAL2FLD(PPCA_EPU_EPU_PU_T1_CNFG_PUT1_ENQ, enable) |
                                                               _VAL2FLD(PPCA_EPU_EPU_PU_T1_CNFG_PUT1_SRCQ_SEL, qualInSrc);
    }
    else
    {
        PPCA_EPU_EPU_PU_T1_CNFG(base, index) &= (uint32_t)(~PPCA_EPU_EPU_PU_T1_CNFG_PUT1_ENQ_Msk);
    }
}


void Cy_PPCA_EPU_PU_T1_Config_InputSource(PPCA_EPU_EPU_Type *base, uint32_t index, uint8_t inSrc)
{
    uint32_t tempReg;
    tempReg = (PPCA_EPU_EPU_PU_T1_CNFG(base, index) & (~PPCA_EPU_EPU_PU_T1_CNFG_PUT1_SRC_SEL_Msk));
    PPCA_EPU_EPU_PU_T1_CNFG(base, index) = tempReg | _VAL2FLD(PPCA_EPU_EPU_PU_T1_CNFG_PUT1_SRC_SEL, inSrc);
}


void Cy_PPCA_EPU_PU_T1_Config_NumOfClkCycles(PPCA_EPU_EPU_Type *base, uint32_t index, uint8_t data)
{
    uint32_t tempReg;
    tempReg = (PPCA_EPU_EPU_PU_T1_CNFG(base, index) & (~PPCA_EPU_EPU_PU_T1_CNFG_DATA_Msk ));
    PPCA_EPU_EPU_PU_T1_CNFG(base, index) = tempReg | _VAL2FLD(PPCA_EPU_EPU_PU_T1_CNFG_DATA, data);
}


void Cy_PPCA_EPU_PU_T1_TestInConfig(PPCA_EPU_EPU_Type *base, uint32_t index, bool enableTestIn, bool testInVal)
{
    uint32_t tempReg;
    tempReg = (PPCA_EPU_EPU_PU_T1_CNFG(base, index) & 
              (~(PPCA_EPU_EPU_PU_T1_CNFG_PUT1_SEL_CONSTANT_IN_Msk | PPCA_EPU_EPU_PU_T1_CNFG_PUT1_CONSTANT_IN_Msk)));

    PPCA_EPU_EPU_PU_T1_CNFG(base, index) = tempReg | _BOOL2FLD(PPCA_EPU_EPU_PU_T1_CNFG_PUT1_SEL_CONSTANT_IN, enableTestIn) |
                                                           _VAL2FLD(PPCA_EPU_EPU_PU_T1_CNFG_PUT1_CONSTANT_IN, testInVal);
}


void Cy_PPCA_EPU_PU_T2_Enable(PPCA_EPU_EPU_Type *base, uint32_t index, cy_en_ppca_epu_en_pu_t enable)
{
    uint32_t tempReg;
    tempReg = (PPCA_EPU_EPU_PU_T2_CNFG(base, index) & (~PPCA_EPU_EPU_PU_T2_CNFG_PUT2_EN_Msk));
    PPCA_EPU_EPU_PU_T2_CNFG(base, index) = tempReg | _VAL2FLD(PPCA_EPU_EPU_PU_T2_CNFG_PUT2_EN, enable);
}


void Cy_PPCA_EPU_PU_T2_Select_Input(PPCA_EPU_EPU_Type *base, uint32_t index, cy_en_ppca_epu_input_pu_t input)
{
    uint32_t tempReg;
    tempReg = (PPCA_EPU_EPU_PU_T2_CNFG(base, index) & (~PPCA_EPU_EPU_PU_T2_CNFG_PUT2_IN_SEL_Msk));
    PPCA_EPU_EPU_PU_T2_CNFG(base, index) = tempReg | _VAL2FLD(PPCA_EPU_EPU_PU_T2_CNFG_PUT2_IN_SEL, input);
}


void Cy_PPCA_EPU_PU_T2_Config_InputSource(PPCA_EPU_EPU_Type *base, uint32_t index, uint8_t inSrc)
{
    uint32_t tempReg;
    tempReg = (PPCA_EPU_EPU_PU_T2_CNFG(base, index) & (~PPCA_EPU_EPU_PU_T2_CNFG_PUT2_SRC_SEL_Msk));
    PPCA_EPU_EPU_PU_T2_CNFG(base, index) = tempReg | _VAL2FLD(PPCA_EPU_EPU_PU_T2_CNFG_PUT2_SRC_SEL, inSrc);
}


void Cy_PPCA_EPU_PU_T2_TestInConfig(PPCA_EPU_EPU_Type *base, uint32_t index, bool enableTestIn, bool testInVal)
{
    uint32_t tempReg;
    tempReg = (PPCA_EPU_EPU_PU_T2_CNFG(base, index) &
              (~(PPCA_EPU_EPU_PU_T2_CNFG_PUT2_SEL_CONSTANT_IN_Msk | PPCA_EPU_EPU_PU_T2_CNFG_PUT2_CONSTANT_IN_Msk)));

    PPCA_EPU_EPU_PU_T2_CNFG(base, index) = tempReg | _BOOL2FLD(PPCA_EPU_EPU_PU_T2_CNFG_PUT2_SEL_CONSTANT_IN, enableTestIn) |
                                                           _VAL2FLD(PPCA_EPU_EPU_PU_T2_CNFG_PUT2_CONSTANT_IN, testInVal);
}


void Cy_PPCA_EPU_COMBO_InputSignals_PUT1_0_15(PPCA_EPU_EPU_Type *base, uint32_t index, cy_en_ppca_epu_bank_sel_t bankSel, cy_en_ppca_epu_en_input_signal_t put1InEnable)
{
    uint32_t tempReg;
    tempReg = (PPCA_EPU_EPU_COMBO_CNFG(base, index) & 
              (~(PPCA_EPU_EPU_COMBO_CNFG_BANK_SEL_Msk | PPCA_EPU_EPU_COMBO_CNFG_PUT1_IN_EN_Msk)));
    PPCA_EPU_EPU_COMBO_CNFG(base, index) = tempReg | _VAL2FLD(PPCA_EPU_EPU_COMBO_CNFG_BANK_SEL, bankSel) |
                                                           _VAL2FLD(PPCA_EPU_EPU_COMBO_CNFG_PUT1_IN_EN, put1InEnable);
}


void Cy_PPCA_EPU_COMBO_InputSignals_PUT1_PUT2(PPCA_EPU_EPU_Type *base, uint32_t index, cy_en_ppca_epu_pu_src_in_t puSrcIn, cy_en_ppca_epu_en_input_signal_t srcInEnable)
{
    uint32_t tempReg;
    tempReg = (PPCA_EPU_EPU_COMBO_CNFG(base, index) & 
              (~(PPCA_EPU_EPU_COMBO_CNFG_PU_SRC_IN_Msk | PPCA_EPU_EPU_COMBO_CNFG_PU_SRC_IN_EN_Msk)));
    PPCA_EPU_EPU_COMBO_CNFG(base, index) = tempReg | _VAL2FLD(PPCA_EPU_EPU_COMBO_CNFG_PU_SRC_IN, puSrcIn) |
                                                           _VAL2FLD(PPCA_EPU_EPU_COMBO_CNFG_PU_SRC_IN_EN, srcInEnable);
}


void Cy_PPCA_EPU_COMBO_QualifierInput(PPCA_EPU_EPU_Type *base, uint32_t index, bool enableQual, cy_en_ppca_epu_in_qual_t inQual)
{
    if(enableQual)
    {
        uint32_t tempReg;
        tempReg = (PPCA_EPU_EPU_COMBO_CNFG(base, index) & 
                  (~(PPCA_EPU_EPU_COMBO_CNFG_PU_IN_QUALIFIER_EN_Msk | PPCA_EPU_EPU_COMBO_CNFG_PU_IN_QUALIFIER_Msk)));
        PPCA_EPU_EPU_COMBO_CNFG(base, index) = tempReg | _VAL2FLD(PPCA_EPU_EPU_COMBO_CNFG_PU_IN_QUALIFIER_EN, enableQual) |
                                                               _VAL2FLD(PPCA_EPU_EPU_COMBO_CNFG_PU_IN_QUALIFIER, inQual);
    }
    else
    {
        PPCA_EPU_EPU_COMBO_CNFG(base, index) &= (~PPCA_EPU_EPU_COMBO_CNFG_PU_IN_QUALIFIER_EN_Msk);
    }
}

#if defined(__cplusplus)
}
#endif

#endif /* CY_IP_MXS40PPSS */

/* [] END OF FILE */
