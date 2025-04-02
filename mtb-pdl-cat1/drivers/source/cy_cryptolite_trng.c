/***************************************************************************//**
* \file cy_cryptolite_trng.c
* \version 2.80
*
* \brief
*  Provides API implementation of the Cryptolite TRNG PDL driver.
*
********************************************************************************
* \copyright
* Copyright (c) 2022, Cypress Semiconductor Corporation (an Infineon company) or
* an affiliate of Cypress Semiconductor Corporation.
* SPDX-License-Identifier: Apache-2.0
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*    http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/


#include "cy_device.h"

#if defined (CY_IP_MXCRYPTOLITE)

#include "cy_cryptolite_trng.h"
#include "cy_cryptolite_trng_config.h"

#if defined(__cplusplus)
extern "C" {
#endif

#if (CRYPTOLITE_TRNG_PRESENT == 1) 
#if defined(CY_CRYPTOLITE_CFG_TRNG_C)

const cy_stc_cryptolite_trng_config_t cy_cryptolite_trngDefaultConfig =
{
    (uint8_t)CY_CRYPTOLITE_DEF_TRNG_SAMPLE_CLOCK_DIV,   /* sampleClockDiv */
    (uint8_t)CY_CRYPTOLITE_DEF_TRNG_RED_CLOCK_DIV,      /* reducedClockDiv */
    (uint8_t)CY_CRYPTOLITE_DEF_TRNG_INIT_DELAY,         /* initDelay */
    CY_CRYPTOLITE_DEF_TRNG_VON_NEUMANN_CORR,            /* vnCorrectorEnable */
    CY_CRYPTOLITE_DEF_TRNG_AP_ENABLE,                   /* AP test enable */
    CY_CRYPTOLITE_DEF_TRNG_RC_ENABLE,                   /* RC test enable */
    CY_CRYPTOLITE_DEF_TRNG_STOP_ON_AP_DETECT,           /* stopOnAPDetect */
    CY_CRYPTOLITE_DEF_TRNG_STOP_ON_RC_DETECT,           /* stopOnRCDetect */
    CY_CRYPTOLITE_DEF_TRNG_GARO,                        /* garo31Poly */
    CY_CRYPTOLITE_DEF_TRNG_FIRO,                        /* firo31Poly */
    CY_CRYPTOLITE_DEF_TRNG_BITSTREAM_SEL,               /* monBitStreamSelect */
    (uint8_t)CY_CRYPTOLITE_DEF_TRNG_CUTOFF_COUNT8,      /* monCutoffCount8 */
    (uint16_t)CY_CRYPTOLITE_DEF_TRNG_CUTOFF_COUNT16,    /* monCutoffCount16 */
    (uint16_t)CY_CRYPTOLITE_DEF_TRNG_WINDOW_SIZE        /* monWindowSize */
};

/*******************************************************************************
* Function Name: Cy_Cryptolite_Trng_Init
****************************************************************************//*
*
* Initialize the TRNG hardware submodule
*
* \param base
* The pointer to the CRYPTOLITE instance.
*
* \param config
* The pointer to the configuration structure. If NULL default config is used.
*
* \return
* \ref cy_en_cryptolite_status_t
*
*******************************************************************************/
cy_en_cryptolite_status_t Cy_Cryptolite_Trng_Init(CRYPTOLITE_Type *base, cy_stc_cryptolite_trng_config_t *config)
{
    if(NULL != base)
    {
        if (NULL == config)
        {
            config = (cy_stc_cryptolite_trng_config_t *)&cy_cryptolite_trngDefaultConfig;
        }
        if(!(CY_CRYPTOLITE_IS_BS_SELECT_VALID(config->monBitStreamSelect)))
        {
            return CY_CRYPTOLITE_BAD_PARAMS;
        }

        Cy_Cryptolite_Trng_ClearInterrupt(base, CRYPTOLITE_INTR_TRNG_DATA_AVAILABLE_Msk | CRYPTOLITE_INTR_TRNG_INITIALIZED_Msk);
        Cy_Cryptolite_Trng_MonClearHealthStatus(base);

        REG_CRYPTOLITE_TRNG_GARO_CTL(base) = config->garo31Poly;
        REG_CRYPTOLITE_TRNG_FIRO_CTL(base) = config->firo31Poly;

        REG_CRYPTOLITE_TRNG_CTL0(base) = (uint32_t)(_VAL2FLD(CRYPTOLITE_TRNG_CTL0_SAMPLE_CLOCK_DIV, config->sampleClockDiv)
                                            | _VAL2FLD(CRYPTOLITE_TRNG_CTL0_RED_CLOCK_DIV, config->reducedClockDiv)
                                            | _VAL2FLD(CRYPTOLITE_TRNG_CTL0_INIT_DELAY, config->initDelay)
                                            | _VAL2FLD(CRYPTOLITE_TRNG_CTL0_VON_NEUMANN_CORR, config->vnCorrectorEnable)
                                            | _VAL2FLD(CRYPTOLITE_TRNG_CTL0_FEEDBACK_EN, 0U)
                                            | _VAL2FLD(CRYPTOLITE_TRNG_CTL0_STOP_ON_AP_DETECT, config->stopOnAPDetect)
                                            | _VAL2FLD(CRYPTOLITE_TRNG_CTL0_STOP_ON_RC_DETECT, config->stopOnRCDetect));

        REG_CRYPTOLITE_TRNG_MON_CTL(base) = (uint32_t)_VAL2FLD(CRYPTOLITE_TRNG_MON_CTL_BITSTREAM_SEL, config->monBitStreamSelect);

        /*Enable Health Monitor tests*/
        if (config->EnableAPTest)
        {
            Cy_Cryptolite_Trng_MonEnableApTest(base);
        }
        if (config->EnableRCTest)
        {
            Cy_Cryptolite_Trng_MonEnableRcTest(base);
        }

        REG_CRYPTOLITE_TRNG_MON_RC_CTL(base) = (uint32_t)_VAL2FLD(CRYPTOLITE_TRNG_MON_RC_CTL_CUTOFF_COUNT8, config->monCutoffCount8);

        REG_CRYPTOLITE_TRNG_MON_AP_CTL(base) = (uint32_t)(_VAL2FLD(CRYPTOLITE_TRNG_MON_AP_CTL_CUTOFF_COUNT16, config->monCutoffCount16)
                                                  | _VAL2FLD(CRYPTOLITE_TRNG_MON_AP_CTL_WINDOW_SIZE, config->monWindowSize));

        return (CY_CRYPTOLITE_SUCCESS);
    }
    return (CY_CRYPTOLITE_BAD_PARAMS);
}

/*******************************************************************************
* Function Name: Cy_Cryptolite_Trng_DeInit
****************************************************************************//*
*
* Clears all TRNG registers by set to hardware default values.
*
* \param base
* The pointer to the CRYPTOLITE instance.
*
* \return
* The error / status code. See \ref cy_en_cryptolite_status_t.
*
*******************************************************************************/
cy_en_cryptolite_status_t Cy_Cryptolite_Trng_DeInit(CRYPTOLITE_Type *base)
{
    cy_en_cryptolite_status_t status = CY_CRYPTOLITE_BAD_PARAMS;

    if( NULL != base)
    {
        REG_CRYPTOLITE_TRNG_CTL0(base) = (uint32_t)_VAL2FLD(CRYPTOLITE_TRNG_CTL0_INIT_DELAY, 3U);
        REG_CRYPTOLITE_TRNG_CTL1(base) = 0UL;

        REG_CRYPTOLITE_TRNG_GARO_CTL(base) = 0UL;
        REG_CRYPTOLITE_TRNG_FIRO_CTL(base) = 0UL;

        REG_CRYPTOLITE_TRNG_MON_CTL(base) = 2UL;

        REG_CRYPTOLITE_TRNG_MON_RC_CTL(base) = 0UL;
        REG_CRYPTOLITE_TRNG_MON_AP_CTL(base) = 0UL;

        Cy_Cryptolite_Trng_ClearInterrupt(base, CRYPTOLITE_INTR_TRNG_DATA_AVAILABLE_Msk | CRYPTOLITE_INTR_TRNG_INITIALIZED_Msk);
        Cy_Cryptolite_Trng_MonClearHealthStatus(base);

        status = CY_CRYPTOLITE_SUCCESS;
}

    return status;
}

/*******************************************************************************
* Function Name: Cy_Cryptolite_Trng_Enable
****************************************************************************//*
*
* Starts a random number generation.
*
* \param base
* The pointer to the CRYPTOLITE instance.
*
* \return
* The error / status code. See \ref cy_en_cryptolite_status_t.
*
*******************************************************************************/
cy_en_cryptolite_status_t Cy_Cryptolite_Trng_Enable(CRYPTOLITE_Type *base)
{
    cy_en_cryptolite_status_t status = CY_CRYPTOLITE_BAD_PARAMS;

    if( NULL != base)
    {
        status = CY_CRYPTOLITE_SUCCESS;
        if (!Cy_Cryptolite_Trng_IsEnabled(base))
        {
                Cy_Cryptolite_Trng_ClearInterrupt(base, CRYPTOLITE_INTR_TRNG_DATA_AVAILABLE_Msk | CRYPTOLITE_INTR_TRNG_INITIALIZED_Msk);

                REG_CRYPTOLITE_TRNG_CTL1(base) = (uint32_t)(_VAL2FLD(CRYPTOLITE_TRNG_CTL1_RO11_EN, CY_CRYPTOLITE_TRNG_RO_ENABLE)
                                        | _VAL2FLD(CRYPTOLITE_TRNG_CTL1_RO15_EN, CY_CRYPTOLITE_TRNG_RO_ENABLE)
                                        | _VAL2FLD(CRYPTOLITE_TRNG_CTL1_GARO15_EN, CY_CRYPTOLITE_TRNG_RO_ENABLE)
                                        | _VAL2FLD(CRYPTOLITE_TRNG_CTL1_GARO31_EN, CY_CRYPTOLITE_TRNG_RO_ENABLE)
                                        | _VAL2FLD(CRYPTOLITE_TRNG_CTL1_FIRO15_EN, CY_CRYPTOLITE_TRNG_RO_ENABLE)
                                        | _VAL2FLD(CRYPTOLITE_TRNG_CTL1_FIRO31_EN, CY_CRYPTOLITE_TRNG_RO_ENABLE));
                /*wait for TRNG Init*/
                Cy_Cryptolite_Trng_WaitForInit(base);
}
    }

    return status;
}

/*******************************************************************************
* Function Name: Cy_Cryptolite_Trng_IsEnabled
****************************************************************************//*
*
* Checks if Trng is enabled.
*
* \param base
* The pointer to the CRYPTOLITE instance.
*
* \return
* The 'true' if Trng enabled 'false' otherwise.
*
*******************************************************************************/
bool Cy_Cryptolite_Trng_IsEnabled(CRYPTOLITE_Type *base)
{
    if( NULL != base)
    {
        return ((REG_CRYPTOLITE_TRNG_CTL1(base) & CY_CRYPTOLITE_TRNG_RO_ALL_MASK) != 0U);
}

    return false;
}

/*******************************************************************************
* Function Name: Cy_Cryptolite_Trng_Disable
****************************************************************************//*
*
* Stops the random number generation.
*
* \param base
* The pointer to the CRYPTOLITE instance.
*
* \return
* The error / status code. See \ref cy_en_cryptolite_status_t.
*
*******************************************************************************/
cy_en_cryptolite_status_t Cy_Cryptolite_Trng_Disable(CRYPTOLITE_Type *base)
{
    cy_en_cryptolite_status_t status = CY_CRYPTOLITE_BAD_PARAMS;

    if( NULL != base)
    {
        status = CY_CRYPTOLITE_SUCCESS;
        if (Cy_Cryptolite_Trng_IsEnabled(base))
        {
            Cy_Cryptolite_Trng_ClearInterrupt(base, CRYPTOLITE_INTR_TRNG_DATA_AVAILABLE_Msk | CRYPTOLITE_INTR_TRNG_INITIALIZED_Msk);
            REG_CRYPTOLITE_TRNG_CTL1(base) = (uint32_t)0x0;
        }
    }

    return status;
}

/*******************************************************************************
* Function Name: Cy_Cryptolite_Trng_ReadData
****************************************************************************//*
*
* Reads in blocking mode a generated random number.
*
* \note
* Call this API only after Cy_Cryptolite_Trng_Enable() is successful.
*
* \param base
* The pointer to the CRYPTO instance.
*
* \param randomData
* The pointer to a generated true random number.
*
* \return
* The error / status code. See \ref cy_en_cryptolite_status_t.
*
*******************************************************************************/
cy_en_cryptolite_status_t Cy_Cryptolite_Trng_ReadData(CRYPTOLITE_Type *base, uint32_t *randomData)
{
    cy_en_cryptolite_status_t status = CY_CRYPTOLITE_BAD_PARAMS;
    uint8_t stateHealthMon;

    if(NULL != base && NULL != randomData)
    {
        if (Cy_Cryptolite_Trng_IsEnabled(base))
        {
            status = CY_CRYPTOLITE_SUCCESS;

            Cy_Cryptolite_Trng_WaitForComplete(base);

            *randomData = Cy_Cryptolite_Trng_GetData(base);

            stateHealthMon = Cy_Cryptolite_Trng_MonGetHealthStatus(base);
            if (0x0u != stateHealthMon)
            {
                status = CY_CRYPTOLITE_TRNG_UNHEALTHY;
            }
        }
        else
        {
            status = CY_CRYPTOLITE_TRNG_NOT_ENABLED;
        }
    }
    return status;
}

/*******************************************************************************
* Function Name: Cy_Cryptolite_Trng
****************************************************************************//*
*
* Generates a True Random Number.
*
* \param base
* The pointer to the CRYPTOLITE instance.
*
* \param randomNum
* The pointer to a generated true random number.
*
* \return
* \ref cy_en_cryptolite_status_t
*
*******************************************************************************/
cy_en_cryptolite_status_t Cy_Cryptolite_Trng(CRYPTOLITE_Type *base, uint32_t *randomNum)
{
    cy_en_cryptolite_status_t status;

    status = Cy_Cryptolite_Trng_Enable(base);

    if (CY_CRYPTOLITE_SUCCESS == status)
    {
        status = Cy_Cryptolite_Trng_ReadData(base, randomNum);
    }

    (void)Cy_Cryptolite_Trng_Disable(base);

    return (status);
}

#endif
#endif

#if defined(__cplusplus)
}
#endif


#endif /* CY_IP_MXCRYPTOLITE */


/* [] END OF FILE */
