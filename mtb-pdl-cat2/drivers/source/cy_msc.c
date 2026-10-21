/***************************************************************************//**
* \file cy_msc.c
* \version 1.10.2
*
* The source file of the MSC driver.
*
********************************************************************************
* \copyright
* (c) (2020-2022), Cypress Semiconductor Corporation (an Infineon company) or
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
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either expressed or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/


#include <stdint.h>
#include "cy_device_headers.h"
#include "cy_syslib.h"
#include "cy_msc.h"

#if defined(CY_IP_M0S8MSCV3)

/**
* \addtogroup group_msc_functions
* \{
*/

/*******************************************************************************
* Function Name: Cy_MSC_Init
****************************************************************************//**
*
* Acquires, locks, and configures the MSC HW block.
*
* If the MSC HW block is already in use by other middleware or by
* the application program, the function
* returns the CY_MSC_LOCKED status and does not configure the MSC HW block.
*
* If the acquisition is successful, this function writes configuration data
* into all MSC HW block registers (except read-only registers and SEQ_START
* register) at once. Because the SEQ_START register is excluded from write,
* use the Cy_MSC_WriteReg() function to trigger the state machine
* for scan or conversion.
*
* To capture the MSC block without its reconfiguration use the
* Cy_MSC_Capture() function.
*
* \param base
* The pointer to a MSC HW block base address.
*
* \param config
* The pointer to a configuration structure that contains the initial
* configuration.
*
* \param key
* The ID of middleware or a user-level function to work with
* the specified MSC HW block.
*
* \param context
* The pointer to the context structure allocated by the user or middleware.
*
* \return
* Returns the operation result status (MSC status code).
* See \ref cy_en_msc_status_t.
*
*******************************************************************************/
cy_en_msc_status_t Cy_MSC_Init(
                MSC_Type * base,
                cy_stc_msc_base_config_t const * config,
                cy_en_msc_key_t key,
                cy_stc_msc_context_t * context)
{
    cy_en_msc_status_t mscStatus = CY_MSC_LOCKED;

    if ((NULL == base) || (CY_MSC_NONE_KEY == key) || (NULL == config) || (NULL == context))
    {
        mscStatus = CY_MSC_BAD_PARAM;
    }
    else
    {
        if(CY_MSC_NONE_KEY == context->lockKey)
        {
            context->lockKey = key;
            mscStatus = Cy_MSC_Configure(base, config, key, context);
        }
    }

    return(mscStatus);
}


/*******************************************************************************
* Function Name: Cy_MSC_DeInit
****************************************************************************//**
*
* Releases the MSC HW block previously captured and locked by the caller.
*
* If the MSC HW block is acquired by another caller or the block is in the
* busy state (performing scan or conversion), the de-initialization request
* is ignored and the corresponding status is returned.
*
* \param base
* The pointer to a MSC HW block base address.
*
* \param key
* The ID of middleware or a user-level function to work with
* the specified MSC HW block.
*
* \param context
* The pointer to the context structure allocated by the user or middleware.
*
* \return
* Returns the operation result status (MSC status code).
* See \ref cy_en_msc_status_t.
*
*******************************************************************************/
cy_en_msc_status_t Cy_MSC_DeInit(
                const MSC_Type * base,
                cy_en_msc_key_t key,
                cy_stc_msc_context_t * context)
{
    cy_en_msc_status_t mscStatus = CY_MSC_LOCKED;

    if(key == context->lockKey)
    {
        if(CY_MSC_SUCCESS == Cy_MSC_GetConversionStatus(base, context))
        {
            context->lockKey = CY_MSC_NONE_KEY;
            mscStatus = CY_MSC_SUCCESS;
        }
        else
        {
            mscStatus = CY_MSC_BUSY;
        }
    }

    return(mscStatus);
}


/*******************************************************************************
* Function Name: Cy_MSC_Capture
****************************************************************************//**
*
* Acquires and locks the MSC HW block without changing its configuration.
*
* If the MSC HW block is already in use by other middleware or by
* the application program, then the function
* returns the CY_MSC_LOCKED status.
*
* \note This is a low-level function. Use the Cy_MSC_Init() function instead.
* The Cy_MSC_Capture() function is used by upper-level middleware to improve
* efficiency. It also can be used to implement specific use cases. If this
* function is used, configure the MSC block using the Cy_MSC_Configure()
* function.
*
* \param base
* The pointer to a MSC HW block base address.
*
* \param key
* The ID of middleware or a user-level function to work with
* the specified MSC HW block.
*
* \param context
* The pointer to the context structure allocated by the user or middleware.
*
* \return
* Returns the operation result status (MSC status code).
* See \ref cy_en_msc_status_t.
*
*******************************************************************************/
cy_en_msc_status_t Cy_MSC_Capture(
                MSC_Type * base,
                cy_en_msc_key_t key,
                cy_stc_msc_context_t * context)
{
    cy_en_msc_status_t mscStatus = CY_MSC_LOCKED;

    if ((NULL == base) || (CY_MSC_NONE_KEY == key) || (NULL == context))
    {
        mscStatus = CY_MSC_BAD_PARAM;
    }
    else
    {
        if(CY_MSC_NONE_KEY == context->lockKey)
        {
            context->lockKey = key;
            mscStatus = CY_MSC_SUCCESS;
        }
    }

    return(mscStatus);
}


/*******************************************************************************
* Function Name: Cy_MSC_Configure
****************************************************************************//**
*
* Sets configuration of all MSC HW block registers at once.
*
* This function writes configuration data into all MSC block registers
* (except read-only registers and the SEQ_START register) at once. Because the
* SEQ_START register is excluded from write, use the Cy_MSC_WriteReg()
* function to perform triggering state machine for scan or conversion.
*
* \param base
* The pointer to a MSC HW block base address.
*
* \param config
* The pointer to a configuration structure that contains initial configuration.
*
* \param key
* The ID of middleware or a user-level function to work with
* the specified MSC HW block.
*
* \param context
* The pointer to the context structure allocated by the user or middleware.
*
* \return
* Returns the operation result status (MSC status code).
* See \ref cy_en_msc_status_t.
*
*******************************************************************************/
cy_en_msc_status_t Cy_MSC_Configure(
                MSC_Type * base,
                const cy_stc_msc_base_config_t * config,
                cy_en_msc_key_t key,
                const cy_stc_msc_context_t * context)
{
    uint32_t index;
    cy_en_msc_status_t mscStatus = CY_MSC_LOCKED;

    if (key == CY_MSC_NONE_KEY)
    {
        mscStatus = CY_MSC_BAD_PARAM;
    }
    else
    {
        if(key == context->lockKey)
        {
            mscStatus = CY_MSC_SUCCESS;

            base->CTL                       = config->ctl;
            base->SPARE                     = config->spare;
            base->SCAN_CTL1                 = config->scanCtl1;
            base->SCAN_CTL2                 = config->scanCtl2;
            base->INIT_CTL1                 = config->initCtl1;
            base->INIT_CTL2                 = config->initCtl2;
            base->INIT_CTL3                 = config->initCtl3;
            base->INIT_CTL4                 = config->initCtl4;
            base->SENSE_DUTY_CTL            = config->senseDutyCtl;
            base->SENSE_PERIOD_CTL          = config->sensePeriodCtl;
            base->FILTER_CTL                = config->filterCtl;
            base->CCOMP_CDAC_CTL            = config->ccompCdacCtl;
            base->DITHER_CDAC_CTL           = config->ditherCdacCtl;
            base->CSW_CTL                   = config->cswCtl;
            base->SW_SEL_GPIO               = config->swSelGpio;
            base->SW_SEL_CDAC_RE            = config->swSelCdacRe;
            base->SW_SEL_CDAC_CO            = config->swSelCdacCo;
            base->SW_SEL_CDAC_CF            = config->swSelCdacCf;
            base->SW_SEL_CMOD1              = config->swSelCmod1;
            base->SW_SEL_CMOD2              = config->swSelCmod2;
            base->SW_SEL_CMOD3              = config->swSelCmod3;
            base->SW_SEL_CMOD4              = config->swSelCmod4;
            base->OBS_CTL                   = config->obsCtl;
            base->INTR                      = config->intr;
            base->INTR_SET                  = config->intrSet;
            base->INTR_MASK                 = config->intrMask;
            base->FRAME_CMD                 = config->frameCmd;

            /* Load sense mode configuration */
            for (index = 0u; index < CY_MSC_MODES_NUM; index++)
            {
                base->MODE[index].SENSE_DUTY_CTL    = config->mode[index].senseDutyCtl;
                base->MODE[index].SW_SEL_CDAC_FL    = config->mode[index].swSelCdacFl;
                base->MODE[index].SW_SEL_TOP        = config->mode[index].swSelTop;
                base->MODE[index].SW_SEL_COMP       = config->mode[index].swSelComp;
                base->MODE[index].SW_SEL_SH         = config->mode[index].swSelSh;
            }

            /* Load control switch MUX configuration */
            for (index = 0u; index < CY_MSC_CSW_NUM; index++)
            {
                base->SW_SEL_CSW[index] = config->swSelCsw[index];
            }

            /* Load control switch MUX switch control global functions configuration */
            for (index = 0u; index < CY_MSC_CSW_FUNC_NUM; index++)
            {
                base->SW_SEL_CSW_FUNC[index] = config->swSelCswFunc[index];
            }

            (void)config->intr;
        }
    }

    return(mscStatus);
}


/*******************************************************************************
* Function Name: Cy_MSC_ConfigureScan
****************************************************************************//**
*
* Sets configuration of sensor frame registers of the MSC HW block and
* starts the scan.
*
* \param base
* Pointer to a MSC HW block base address.
*
* \param numRegs
* Number of registers in scan configuration written into MSC HW block.
* Possible values are CY_MSC_5_SNS_REGS and CY_MSC_6_SNS_REGS.
*
* \param scanConfig
* The pointer to a scan configuration structure.
*
*******************************************************************************/
void Cy_MSC_ConfigureScan (
                MSC_Type * base,
                uint32_t numRegs,
                const uint32_t * scanConfig)
{
    uint32_t index = 0u;

    if (CY_MSC_6_SNS_REGS == numRegs)
    {
        base->SNS_SW_SEL_CSW_MASK2 = scanConfig[index++];
    }
    else
    {
        base->SNS_SW_SEL_CSW_MASK2 = 0u;
    }

    base->SNS_SW_SEL_CSW_MASK1  = scanConfig[index++];
    base->SNS_SW_SEL_CSW_MASK0  = scanConfig[index++];
    base->SNS_SCAN_CTL          = scanConfig[index++];
    base->SNS_CDAC_CTL          = scanConfig[index++];
    base->SNS_CTL               = scanConfig[index];
}

/** \} group_msc_functions */

#endif /* CY_IP_M0S8MSCV3 */


/* [] END OF FILE */
