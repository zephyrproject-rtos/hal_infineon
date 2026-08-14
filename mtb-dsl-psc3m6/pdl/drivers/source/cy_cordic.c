/***************************************************************************//**
* \file cy_cordic.c
* \version 2.10
*
* \brief
* Provides API implementation of the CORDIC driver.
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

#if defined (CY_IP_MXCORDIC) || defined(CY_IP_MXS40PPSS)

#include "cy_cordic.h"

#if defined(__cplusplus)
extern "C" {
#endif

CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 10.1', 6, \
'Intentional use of unsigned type with the operator >>.')

CY_CORDIC_20Q11_t Cy_CORDIC_Tan(MXCORDIC_Type *base, CY_CORDIC_Q31_t angle_in_radians)
{
    /* Input parameters verification */
    CY_ASSERT_L1(CY_IS_BASE_VALID(base));
    CY_ASSERT_L2(CY_CORDIC_IS_TAN_ANGLE_VALID(angle_in_radians));

    MXCORDIC_CON(base) = _VAL2FLD(MXCORDIC_CON_MODE, CY_CORDIC_OPERATING_MODE_CIRCULAR) |
                         _VAL2FLD(MXCORDIC_CON_ROTVEC, CY_CORDIC_ROTVEC_MODE_ROTATION)  |
                         _VAL2FLD(MXCORDIC_CON_N_ITER, CY_CORDIC_NUMBER_OF_ITERATIONS);
    MXCORDIC_CORDX(base) = _VAL2FLD(MXCORDIC_CORDX_DATA, CY_CORDIC_CIRCULAR_GAIN);
    MXCORDIC_CORDY(base) = 0UL;
    MXCORDIC_CORDZ(base) = (uint32_t)angle_in_radians;

    return (CY_CORDIC_20Q11_t)((((CY_CORDIC_Q31_t)MXCORDIC_CORRY(base)) >> ((int32_t)MXCORDIC_CORRY_RESULT_Pos)) /
            (((CY_CORDIC_Q31_t)MXCORDIC_CORRX(base)) >> ((int32_t)MXCORDIC_CORRX_RESULT_Pos) >> 11UL));
}


CY_CORDIC_20Q11_t Cy_CORDIC_Tanh(MXCORDIC_Type *base, CY_CORDIC_Q31_t angle_in_radians)
{
    /* Input parameters verification */
    CY_ASSERT_L1(CY_IS_BASE_VALID(base));
    CY_ASSERT_L2(CY_CORDIC_IS_HYPERBOLIC_ROTATION_ANGLE_VALID(angle_in_radians));

    MXCORDIC_CON(base) = _VAL2FLD(MXCORDIC_CON_MODE, CY_CORDIC_OPERATING_MODE_HYPERBOLIC) |
                         _VAL2FLD(MXCORDIC_CON_ROTVEC, CY_CORDIC_ROTVEC_MODE_ROTATION)    |
                         _VAL2FLD(MXCORDIC_CON_N_ITER, CY_CORDIC_NUMBER_OF_ITERATIONS);
    MXCORDIC_CORDX(base) = _VAL2FLD(MXCORDIC_CORDX_DATA, CY_CORDIC_HYPERBOLIC_GAIN);
    MXCORDIC_CORDY(base) = 0UL;
    MXCORDIC_CORDZ(base) = (uint32_t)angle_in_radians;

    return (CY_CORDIC_20Q11_t)((((CY_CORDIC_Q31_t)MXCORDIC_CORRY(base)) >> ((int32_t)MXCORDIC_CORRY_RESULT_Pos)) /
            (((CY_CORDIC_Q31_t)MXCORDIC_CORRX(base)) >> ((int32_t)MXCORDIC_CORRX_RESULT_Pos) >> 11UL));
}


/** Input should be a Q31 number [0, 1]
* sqrt(x) = sqrt(((x + 0.25)^2) - ((x - 0.25)^2);
* x is right shifted by 2 to handle numbers greater than 1, so:
* input is x/4 and hence output at CORRX is x/2 ;
* The result is therefore multiplied with
* scaling factor (which includes 1/K i.e., hyperbolic gain) to get a result in Q31 format.
*/
uint32_t Cy_CORDIC_Sqrt(MXCORDIC_Type *base, uint32_t x)
{
    /* Input parameters verification */
    CY_ASSERT_L1(CY_IS_BASE_VALID(base));
    CY_ASSERT_L1(CY_CORDIC_IS_INPUT_NON_ZERO(x));

    MXCORDIC_CON(base) = _VAL2FLD(MXCORDIC_CON_MODE, CY_CORDIC_OPERATING_MODE_HYPERBOLIC) |
                         _VAL2FLD(MXCORDIC_CON_ROTVEC, CY_CORDIC_ROTVEC_MODE_VECTORING)   |
                         _VAL2FLD(MXCORDIC_CON_N_ITER, CY_CORDIC_NUMBER_OF_ITERATIONS);

    x >>= 2UL; /* Q29 to handle numbers > 1.0 */

    MXCORDIC_CORDX(base) = (uint32_t)(x + 0x8000000UL); /* x + 0.25 */
    MXCORDIC_CORDY(base) = (uint32_t)(x - 0x8000000UL); /* x - 0.25 */
    MXCORDIC_CORDZ(base) = 0UL;

    return ((MXCORDIC_CORRX(base) >> 13UL) * CY_CORDIC_Q15_SCALING_FACTOR); /* Q16 * Q15 yields Q31*/
}


CY_CORDIC_Q31_t Cy_CORDIC_ArcSin(MXCORDIC_Type *base, CY_CORDIC_Q31_t w)
{
    /* asin(w) = atan(w / sqrt(1 - w^2)) */
    /* Input parameters verification */
    CY_ASSERT_L1(CY_IS_BASE_VALID(base));

    /* Compute 1 - w^2 in Q31:
     * w is Q31, so w/0x80000000 is the real value.
     * w^2 in Q31: ((int64_t)w * w) >> 31
     * 1 - w^2: 0x7FFFFFFF - w_squared
     */
    int64_t w_sq = ((int64_t)w * (int64_t)w) >> 31;
    uint32_t one_minus_w_sq = (uint32_t)((int32_t)0x7FFFFFFF - (int32_t)w_sq);

    /* sqrt(1 - w^2) in Q31 */
    uint32_t sqrt_val = Cy_CORDIC_Sqrt(base, one_minus_w_sq);

    /* Convert Q31 to 8Q23 by shifting right by 8. The ratio y/x is preserved. */
    CY_CORDIC_8Q23_t x_val = (CY_CORDIC_8Q23_t)((int32_t)sqrt_val >> 8);
    CY_CORDIC_8Q23_t y_val = (CY_CORDIC_8Q23_t)(w >> 8);

    return Cy_CORDIC_ArcTan(base, x_val, y_val);
}


CY_CORDIC_Q31_t Cy_CORDIC_ArcCos(MXCORDIC_Type *base, CY_CORDIC_Q31_t w)
{
    /* acos(w) = atan(sqrt(1 - w^2) / w) */
    /* Input parameters verification */
    CY_ASSERT_L1(CY_IS_BASE_VALID(base));

    /* Compute 1 - w^2 in Q31 */
    int64_t w_sq = ((int64_t)w * (int64_t)w) >> 31;
    uint32_t one_minus_w_sq = (uint32_t)((int32_t)0x7FFFFFFF - (int32_t)w_sq);

    /* sqrt(1 - w^2) in Q31 */
    uint32_t sqrt_val = Cy_CORDIC_Sqrt(base, one_minus_w_sq);

    /* Convert Q31 to 8Q23 by shifting right by 8. The ratio y/x is preserved. */
    CY_CORDIC_8Q23_t x_val = (CY_CORDIC_8Q23_t)(w >> 8);
    CY_CORDIC_8Q23_t y_val = (CY_CORDIC_8Q23_t)((int32_t)sqrt_val >> 8);

    return Cy_CORDIC_ArcTan(base, x_val, y_val);
}


void Cy_CORDIC_Interrupt(MXCORDIC_Type *base, cy_stc_cordic_context_t *context)
{
    uint32_t locEvents = 0UL;
    uint32_t intrStatus;

    intrStatus = Cy_CORDIC_GetInterruptStatusMasked(base);

    if(0UL != (intrStatus & CY_CORDIC_INTR_END_OF_CALCULATION))
    {
        locEvents = CY_CORDIC_END_OF_CALCULATION_EVENT;
        Cy_CORDIC_ClearInterrupt(base, CY_CORDIC_INTR_END_OF_CALCULATION);
    }

    if(0UL != (intrStatus & CY_CORDIC_INTR_ERROR_EVENT))
    {
        locEvents |= CY_CORDIC_ERROR_EVENT;
        Cy_CORDIC_ClearInterrupt(base, CY_CORDIC_INTR_ERROR_EVENT);
    }

    if (NULL != context->cbEvents)
    {
        context->cbEvents(locEvents);
    }
}

CY_MISRA_BLOCK_END('MISRA C-2012 Rule 10.1')


#if defined(__cplusplus)
}
#endif

#endif /* CY_IP_MXCORDIC */

/* [] END OF FILE */
