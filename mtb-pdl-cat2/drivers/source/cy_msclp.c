/***************************************************************************//**
* \file cy_msclp.c
* \version 2.0
*
* The source file of the MSCLP driver.
*
********************************************************************************
* \copyright
* (c) (2021-2023), Cypress Semiconductor Corporation (an Infineon company) or
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
#include "cy_msclp.h"

#if defined(CY_IP_M0S8MSCV3LP)

/**
* \addtogroup group_msclp_functions
* \{
*/

/*******************************************************************************
* Function Name: Cy_MSCLP_Init
****************************************************************************//**
*
* Acquires, locks, and configures the MSCLP HW block.
*
* If the MSCLP HW block is already in use by other middleware or by
* the application program, the function
* returns the CY_MSCLP_LOCKED status and does not configure the MSCLP HW block.
*
* If the acquisition is successful, this function writes configuration data
* into all MSCLP HW block registers (except read-only registers and SEQ_START
* register) at once. Because the SEQ_START register is excluded from write,
* use the Cy_MSCLP_WriteReg() function to trigger the state machine
* for scan or conversion.
*
* To capture the MSCLP block without its reconfiguration use the
* Cy_MSCLP_Capture() function.
*
* \param base
* The pointer to a MSCLP HW block base address.
*
* \param config
* The pointer to a configuration structure that contains the initial
* configuration.
*
* \param key
* The ID of middleware or a user-level function to work with
* the specified MSCLP HW block.
*
* \param context
* The pointer to the context structure allocated by the user or middleware.
*
* \return
* Returns the operation result status (MSCLP status code).
* See \ref cy_en_msclp_status_t.
*
*
* \funcusage \snippet msclp_snippet.c snippet_Cy_MSCLP_Conversion
*
*******************************************************************************/
cy_en_msclp_status_t Cy_MSCLP_Init(
                MSCLP_Type * base,
                cy_stc_msclp_base_config_t const * config,
                cy_en_msclp_key_t key,
                cy_stc_msclp_context_t * context)
{
    cy_en_msclp_status_t msclpStatus = CY_MSCLP_LOCKED;

    if ((NULL == base) || (CY_MSCLP_NONE_KEY == key) || (NULL == config) || (NULL == context))
    {
        msclpStatus = CY_MSCLP_BAD_PARAM;
    }
    else
    {
        if (CY_MSCLP_NONE_KEY == context->lockKey)
        {
            context->lockKey = key;
            msclpStatus = Cy_MSCLP_Configure(base, config, key, context);
        }
    }

    return msclpStatus;
}


/*******************************************************************************
* Function Name: Cy_MSCLP_DeInit
****************************************************************************//**
*
* Releases the MSCLP HW block previously captured and locked by the caller.
*
* If the MSCLP HW block is acquired by another caller or the block is in the
* busy state (performing scan or conversion), the de-initialization request
* is ignored and the corresponding status is returned.
*
* \param base
* The pointer to a MSCLP HW block base address.
*
* \param key
* The ID of middleware or a user-level function to work with
* the specified MSCLP HW block.
*
* \param context
* The pointer to the context structure allocated by the user or middleware.
*
* \return
* Returns the operation result status (MSCLP status code).
* See \ref cy_en_msclp_status_t.
*
*******************************************************************************/
cy_en_msclp_status_t Cy_MSCLP_DeInit(
                MSCLP_Type * base,
                cy_en_msclp_key_t key,
                cy_stc_msclp_context_t * context)
{
    cy_en_msclp_status_t msclpStatus = CY_MSCLP_LOCKED;
    uint32_t mrssState = 0u;
    uint32_t msclpState = 0u;
    uint32_t waitTime;

    if (key == context->lockKey)
    {
        mrssState = base->MRSS_STATUS & MSCLP_MRSS_STATUS_MRSS_UP_Msk;
        msclpState = base->CTL & MSCLP_CTL_ENABLED_Msk;
        msclpStatus = CY_MSCLP_SUCCESS;

        if (0u == mrssState)
        {
            base->CTL &= ~MSCLP_CTL_ENABLED_Msk;

            /* Start the MRSS */
            base->MRSS_CMD = MSCLP_MRSS_CMD_MRSS_START_Msk;
            waitTime = CY_MSCLP_CLK_LF_PERIOD_MAX * CY_MSCLP_MRSS_TIMEOUT_SMALL;

            /* Check if the MRSS is up, else break with CY_MSCLP_MRSS_TIMEOUT */
            while (0u == (base->MRSS_STATUS & MSCLP_MRSS_STATUS_MRSS_UP_Msk))
            {
               if(0uL == waitTime)
               {
                   msclpStatus = CY_MSCLP_TIMEOUT;
                   break;
               }

               /* Delay for 1us */
               Cy_SysLib_DelayUs(1u);
               waitTime--;
            }
        }

        if (CY_MSCLP_SUCCESS == msclpStatus)
        {
            msclpStatus = Cy_MSCLP_GetConversionStatus((const MSCLP_Type *)base, context);
            if (CY_MSCLP_SUCCESS == msclpStatus)
            {
               /* Restore HW state */
               if (0u == mrssState)
               {
                   /* Stop MRSS and delay for CY_MSCLP_MRSS_TIMEOUT */
                   base->MRSS_CMD = MSCLP_MRSS_CMD_MRSS_STOP_Msk;
                   waitTime = CY_MSCLP_CLK_LF_PERIOD_MAX;

                   /* Check if the MRSS is stopped, else break with CY_MSCLP_MRSS_TIMEOUT */
                   while (0u != (base->MRSS_STATUS & MSCLP_MRSS_STATUS_MRSS_UP_Msk))
                   {
                       if(0uL == waitTime)
                       {
                           msclpStatus = CY_MSCLP_TIMEOUT;
                           break;
                       }

                       /* Delay for 1us */
                       Cy_SysLib_DelayUs(1u);
                       waitTime--;
                   }
                   if (0u == msclpState)
                   {
                       base->CTL &= ~MSCLP_CTL_ENABLED_Msk;
                   }
               }
               if (CY_MSCLP_SUCCESS == msclpStatus)
               {
                   context->lockKey = CY_MSCLP_NONE_KEY;
               }
            }
        }
    }

    return msclpStatus;
}


/*******************************************************************************
* Function Name: Cy_MSCLP_Capture
****************************************************************************//**
*
* Acquires and locks the MSCLP HW block without changing its configuration.
*
* If the MSCLP HW block is already in use by other middleware or by
* the application program, then the function
* returns the CY_MSCLP_LOCKED status.
*
* \note This is a low-level function. Use the Cy_MSCLP_Init() function instead.
* The Cy_MSCLP_Capture() function is used by upper-level middleware to improve
* efficiency. It also can be used to implement specific use cases. If this
* function is used, configure the MSCLP block using the Cy_MSCLP_Configure()
* function.
*
* \param base
* The pointer to a MSCLP HW block base address.
*
* \param key
* The ID of middleware or a user-level function to work with
* the specified MSCLP HW block.
*
* \param context
* The pointer to the context structure allocated by the user or middleware.
*
* \return
* Returns the operation result status (MSCLP status code).
* See \ref cy_en_msclp_status_t.
*
* \funcusage \snippet msclp_snippet.c snippet_Cy_MSCLP_Capture
*
*******************************************************************************/
cy_en_msclp_status_t Cy_MSCLP_Capture(
                MSCLP_Type * base,
                cy_en_msclp_key_t key,
                cy_stc_msclp_context_t * context)
{
    cy_en_msclp_status_t msclpStatus = CY_MSCLP_LOCKED;

    if ((NULL == base) || (CY_MSCLP_NONE_KEY == key) || (NULL == context))
    {
        msclpStatus = CY_MSCLP_BAD_PARAM;
    }
    else
    {
        if (CY_MSCLP_NONE_KEY == context->lockKey)
        {
            context->lockKey = key;
            msclpStatus = CY_MSCLP_SUCCESS;
        }
    }

    return msclpStatus;
}


/*******************************************************************************
* Function Name: Cy_MSCLP_Configure
****************************************************************************//**
*
* Sets configuration of all MSCLP HW block registers at once.
*
* This function writes configuration data into all MSCLP block registers
* (except read-only registers and the SEQ_START register) at once. Because the
* SEQ_START register is excluded from write, use the Cy_MSCLP_WriteReg()
* function to perform triggering state machine for scan or conversion.
*
* \param base
* The pointer to a MSCLP HW block base address.
*
* \param config
* The pointer to a configuration structure that contains initial configuration.
*
* \param key
* The ID of middleware or a user-level function to work with
* the specified MSCLP HW block.
*
* \param context
* The pointer to the context structure allocated by the user or middleware.
*
* \return
* Returns the operation result status (MSCLP status code).
* See \ref cy_en_msclp_status_t.
*
*******************************************************************************/
cy_en_msclp_status_t Cy_MSCLP_Configure(
                MSCLP_Type * base,
                const cy_stc_msclp_base_config_t * config,
                cy_en_msclp_key_t key,
                const cy_stc_msclp_context_t * context)
{
    uint32_t index;
    cy_en_msclp_status_t msclpStatus = CY_MSCLP_SUCCESS;

    if (key == CY_MSCLP_NONE_KEY)
    {
        msclpStatus = CY_MSCLP_BAD_PARAM;
    }
    else if (key != context->lockKey)
    {
        msclpStatus = CY_MSCLP_LOCKED;
    }
    else
    {
        base->CTL                       = config->ctl;
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
        base->MSCCMP_CTL                = config->mscCmpCtl;
        base->OBS_CTL                   = config->obsCtl;
        base->AOS_CTL                   = config->aosCtl;
        base->CE_CTL                    = config->ceCtl;
        base->PUMP_CTL                  = config->pumpCtl;
        base->IMO_CTL                   = config->imoCtl;
        base->INTR                      = config->intr;
        base->INTR_SET                  = config->intrSet;
        base->INTR_MASK                 = config->intrMask;
        base->INTR_LP                   = config->intrLp;
        base->INTR_LP_SET               = config->intrLpSet;
        base->INTR_LP_MASK              = config->intrLpMask;
        base->SW_SEL_CDAC_RE            = config->swSelCdacRe;
        base->SW_SEL_CDAC_CO            = config->swSelCdacCo;
        base->SW_SEL_CDAC_CF            = config->swSelCdacCf;
        base->SW_SEL_BGR                = config->swSelBgr;

        /* Load Switch Control Global Functions configuration */
        for (index = 0u; index < MSCLP_CSW_GLOBAL_FUNC_NR; index++)
        {
            base->SW_SEL_CSW_FUNC[index]    = config->swSelCswFunc[index];
        }

        /* Load sense mode configuration */
        for (index = 0u; index < MSCLP_SENSE_MODE_NR; index++)
        {
            base->MODE[index].SENSE_DUTY_CTL    = config->mode[index].senseDutyCtl;
            base->MODE[index].SW_SEL_CDAC_FL    = config->mode[index].swSelCdacFl;
            base->MODE[index].SW_SEL_TOP        = config->mode[index].swSelTop;
            base->MODE[index].SW_SEL_COMP       = config->mode[index].swSelComp;
            base->MODE[index].SW_SEL_SH         = config->mode[index].swSelSh;
            base->MODE[index].SW_SEL_CMOD1      = config->mode[index].swSelCmod1;
            base->MODE[index].SW_SEL_CMOD2      = config->mode[index].swSelCmod2;
        }

        switch (config->imoCtl & MSCLP_IMO_CTL_FREQ_Msk)
        {
            case CY_MSCLP_IMO_25_MHZ:
                base->CLK_IMO_TRIM1 = SFLASH_MSCLP0_CLK_IMO_TRIM1_25_MHZ;
                base->CLK_IMO_TRIM3 = SFLASH_MSCLP0_CLK_IMO_TRIM3_25_MHZ;
                break;

            case CY_MSCLP_IMO_38_MHZ:
                base->CLK_IMO_TRIM1 = SFLASH_MSCLP0_CLK_IMO_TRIM1_38_MHZ;
                base->CLK_IMO_TRIM3 = SFLASH_MSCLP0_CLK_IMO_TRIM3_38_MHZ;
                break;

            case CY_MSCLP_IMO_46_MHZ:
                base->CLK_IMO_TRIM1 = SFLASH_MSCLP0_CLK_IMO_TRIM1_46_MHZ;
                base->CLK_IMO_TRIM3 = SFLASH_MSCLP0_CLK_IMO_TRIM3_46_MHZ;
                break;

            default:
                msclpStatus = CY_MSCLP_BAD_PARAM;
                break;
        }
    }

    return msclpStatus;
}


/*******************************************************************************
* Function Name: cy_en_msclp_status_t Cy_MSCLP_MrssStart
****************************************************************************//**
*
* Turns on the MRSS resources. Checks the system defined VDDA value and turns on
* PUMP if VDDA is less then the threshold defined
* by the CY_MSCLP_VDDA_PUMP_TRESHOLD macro, else turns on only REF and IMO.
*
* \param base
* The pointer to a MSCLP HW block base address.
*
* \param mrssCfg
* The pointer to the MRSS configuration structure \ref cy_stc_msclp_mrss_config_t.
*
* \param key
* The ID of middleware or a user-level function to work with
* the specified MSCLP HW block \ref cy_en_msclp_key_t.
*
* \param context
* The pointer to the context structure allocated by the user or middleware.
*
* \return
* Returns the status of the operation:
* - CY_MSCLP_SUCCESS       - The MRSS have been started successfully
* - CY_MSCLP_BAD_PARAM     - One or more invalid input parameters
* - CY_MSCLP_LOCKED        - The MSCLP HW block is captured by another
*                            middleware
* - CY_MSCLP_TIMEOUT       - It is a timeout reached while the MRSS start.
*                            The timeout value is defined
*                            as a multiplication
*                            of the CY_MSCLP_CLK_LF_PERIOD_MAX
*                            and CY_MSCLP_MRSS_TIMEOUT_FULL or
*                            CY_MSCLP_MRSS_TIMEOUT macros
*
*******************************************************************************/
cy_en_msclp_status_t Cy_MSCLP_MrssStart(MSCLP_Type * base,
                    cy_stc_msclp_mrss_config_t const * mrssCfg,
                    cy_en_msclp_key_t key,
                    cy_stc_msclp_context_t const * context)
{
    cy_en_msclp_status_t msclpStatus = CY_MSCLP_LOCKED;
    uint32_t waitTime;

    if ((key == CY_MSCLP_NONE_KEY) ||
        (NULL == mrssCfg) ||
        (NULL == context) ||
        (CY_MSCLP_SYNC_DIV_8 < mrssCfg->syncDiv) ||
        (0u == mrssCfg->mscDiv) || (CY_MSCLP_MSC_DIV_MAX < mrssCfg->mscDiv))
    {
        msclpStatus = CY_MSCLP_BAD_PARAM;
    }
    else
    {
        if (key == context->lockKey)
        {
            switch (mrssCfg->imoFreq)
            {
                case CY_MSCLP_IMO_25_MHZ:
                    base->CLK_IMO_TRIM1 = SFLASH_MSCLP0_CLK_IMO_TRIM1_25_MHZ;
                    base->CLK_IMO_TRIM3 = SFLASH_MSCLP0_CLK_IMO_TRIM3_25_MHZ;
                    break;

                case CY_MSCLP_IMO_38_MHZ:
                    base->CLK_IMO_TRIM1 = SFLASH_MSCLP0_CLK_IMO_TRIM1_38_MHZ;
                    base->CLK_IMO_TRIM3 = SFLASH_MSCLP0_CLK_IMO_TRIM3_38_MHZ;
                    break;

                case CY_MSCLP_IMO_46_MHZ:
                    base->CLK_IMO_TRIM1 = SFLASH_MSCLP0_CLK_IMO_TRIM1_46_MHZ;
                    base->CLK_IMO_TRIM3 = SFLASH_MSCLP0_CLK_IMO_TRIM3_46_MHZ;
                    break;

                default:
                    msclpStatus = CY_MSCLP_BAD_PARAM;
                    break;
            }

            if (CY_MSCLP_BAD_PARAM != msclpStatus)
            {
                /* Set the IMO_CTL */
                base->IMO_CTL = _VAL2FLD(MSCLP_IMO_CTL_FREQ,           mrssCfg->imoFreq) |
                                _VAL2FLD(MSCLP_IMO_CTL_CLOCK_SYNC_DIV, mrssCfg->syncDiv) |
                                _VAL2FLD(MSCLP_IMO_CTL_CLOCK_MSC_DIV,  (uint16_t)(mrssCfg->mscDiv - 1u));

                /* Check for system VDDA value and enable PUMP if VDDA is less then threshold */
                if (CY_MSCLP_VDDA_PUMP_TRESHOLD > mrssCfg->vdda)
                {
                    base->PUMP_CTL = MSCLP_PUMP_CTL_PUMP_MODE_Msk;
                    waitTime = CY_MSCLP_CLK_LF_PERIOD_MAX * CY_MSCLP_MRSS_TIMEOUT_FULL;
                }
                else
                {
                    base->PUMP_CTL = 0u;
                    waitTime = CY_MSCLP_CLK_LF_PERIOD_MAX * CY_MSCLP_MRSS_TIMEOUT_SMALL;
                }

                /* Start the MRSS */
                base->MRSS_CMD = MSCLP_MRSS_CMD_MRSS_START_Msk;

                msclpStatus = CY_MSCLP_SUCCESS;
                /* Check if the MRSS is up, else break with CY_MSCLP_MRSS_TIMEOUT */
                while (0u == (base->MRSS_STATUS & MSCLP_MRSS_STATUS_MRSS_UP_Msk))
                {
                    if(0uL == waitTime)
                    {
                        msclpStatus = CY_MSCLP_TIMEOUT;
                        break;
                    }
                    /* Delay for 1us */
                    Cy_SysLib_DelayUs(1u);
                    waitTime--;
                }
            }
        }
    }

    return msclpStatus;
}


/*******************************************************************************
* Function Name: cy_en_msclp_status_t Cy_MSCLP_MrssStop
****************************************************************************//**
*
* Turns off the MRSS resources.
*
* \param base
* The pointer to a MSCLP HW block base address.
*
* \param key
* The ID of middleware or a user-level function to work with
* the specified MSCLP HW block.
*
* \param context
* The pointer to the context structure allocated by the user or middleware.
*
* \return
* Returns the status of the operation:
* - CY_MSCLP_SUCCESS       - The MRSS have been stopped successfully.
* - CY_MSCLP_BAD_PARAM     - One or more invalid input parameters
* - CY_MSCLP_LOCKED        - The MSCLP HW block is captured by another
*                            middleware
* - CY_MSCLP_TIMEOUT       - The timeout is reached while the MRSS stop.
*                            The timeout value is defined
*                            by the CY_MSCLP_CLK_LF_PERIOD_MAX macro
*
*******************************************************************************/
cy_en_msclp_status_t Cy_MSCLP_MrssStop(MSCLP_Type * base,
                 cy_en_msclp_key_t key,
                 cy_stc_msclp_context_t const * context)
{
    cy_en_msclp_status_t msclpStatus = CY_MSCLP_LOCKED;
    uint32_t waitTime = CY_MSCLP_CLK_LF_PERIOD_MAX;

    if ((key == CY_MSCLP_NONE_KEY) || (NULL == context))
    {
        msclpStatus = CY_MSCLP_BAD_PARAM;
    }
    else
    {
        if (key == context->lockKey)
        {
            /* Stop MRSS and delay for CY_MSCLP_MRSS_TIMEOUT */
            base->MRSS_CMD = MSCLP_MRSS_CMD_MRSS_STOP_Msk;

            msclpStatus = CY_MSCLP_SUCCESS;
            /* Check if the MRSS is stopped, else break with CY_MSCLP_MRSS_TIMEOUT */
            while (0u != (base->MRSS_STATUS & MSCLP_MRSS_STATUS_MRSS_UP_Msk))
            {
                if(0uL == waitTime)
                {
                    msclpStatus = CY_MSCLP_TIMEOUT;
                    break;
                }
                /* Delay for 1us */
                Cy_SysLib_DelayUs(1u);
                waitTime--;
            }
        }
    }

    return msclpStatus;
}


/*******************************************************************************
* Function Name: cy_en_msclp_status_t Cy_MSCLP_MrssStatus
****************************************************************************//**
*
* Returns the MRSS status (enabled/disabled).
*
* \param base
* The pointer to a MSCLP HW block base address.
*
* \param key
* The ID of middleware or a user-level function to work with
* the specified MSCLP HW block.
*
* \param context
* The pointer to the context structure allocated by the user or middleware.
*
* \return
* Returns the status of the operation:
* - CY_MSCLP_SUCCESS       - The MRSS is enabled
* - CY_MSCLP_MRSS_DISABLED - The MRSS is disabled
* - CY_MSCLP_BAD_PARAM     - One or more invalid input parameters
* - CY_MSCLP_LOCKED        - The MSCLP HW block is captured by another
*                            middleware
*
*******************************************************************************/
cy_en_msclp_status_t Cy_MSCLP_MrssStatus(MSCLP_Type * base,
                                         cy_en_msclp_key_t key,
                                         cy_stc_msclp_context_t const * context)
{
    cy_en_msclp_status_t msclpStatus = CY_MSCLP_LOCKED;

    if ((key == CY_MSCLP_NONE_KEY) || (NULL == context))
    {
        msclpStatus = CY_MSCLP_BAD_PARAM;
    }
    else
    {
        if (key == context->lockKey)
        {
            /* Check for MRSS status */
            if (0u != (base->MRSS_STATUS & MSCLP_MRSS_STATUS_MRSS_UP_Msk))
            {
                msclpStatus = CY_MSCLP_SUCCESS;
            }
            else
            {
                msclpStatus = CY_MSCLP_MRSS_DISABLED;
            }
        }
    }

    return msclpStatus;
}


/*******************************************************************************
* Function Name: Cy_MSCLP_ConfigureScan
****************************************************************************//**
*
* Sets configuration of sensor frame registers of the MSCLP HW block and
* starts the scan.
*
* \note Accessing the SNS group registers under disabled MRSS might lead to the
* device hard fault. Therefore, access the SNS group registers of the
* MSCLP HW block only under enabled MRSS. To enable, disable or check the MRSS
* power status, use the Cy_MSCLP_MrssStart(), Cy_MSCLP_MrssStop() or
* Cy_MSCLP_MrssStatus() functions respectively.
*
* \param base
* Pointer to a MSCLP HW block base address.
*
* \param numRegs
* Number of registers in scan configuration written into MSCLP HW block.
* Possible values are \ref CY_MSCLP_6_SNS_REGS and \ref CY_MSCLP_11_SNS_REGS.
* CY_MSCLP_5_SNS_REGS is also supported.
*
* \param scanConfig
* The pointer to a scan configuration structure.
*
*******************************************************************************/
void Cy_MSCLP_ConfigureScan (
                MSCLP_Type * base,
                uint32_t numRegs,
                const uint32_t * scanConfig)
{
    uint32_t index = 0uL;

    switch (numRegs)
    {
        case CY_MSCLP_5_SNS_REGS:
            base->SNS.SNS_SW_SEL_CSW_LO_MASK2 = 0uL;
            break;

        case CY_MSCLP_11_SNS_REGS:
            base->SNS.SNS_LP_AOS_SNS_CTL0 = scanConfig[index++];
            base->SNS.SNS_LP_AOS_SNS_CTL1 = scanConfig[index++];
            base->SNS.SNS_LP_AOS_SNS_CTL2 = scanConfig[index++];
            base->SNS.SNS_LP_AOS_SNS_CTL3 = scanConfig[index++];
            base->SNS.SNS_LP_AOS_SNS_CTL4 = scanConfig[index++];
            base->SNS.SNS_SW_SEL_CSW_LO_MASK2 = scanConfig[index++];
            break;

        default: /* CY_MSCLP_6_SNS_REGS */
            base->SNS.SNS_SW_SEL_CSW_LO_MASK2 = scanConfig[index++];
            break;
    }

    base->SNS.SNS_SW_SEL_CSW_LO_MASK1 = scanConfig[index++];
    base->SNS.SNS_SW_SEL_CSW_LO_MASK0 = scanConfig[index++];
    base->SNS.SNS_SCAN_CTL            = scanConfig[index++];
    base->SNS.SNS_CDAC_CTL            = scanConfig[index++];
    base->SNS.SNS_CTL                 = scanConfig[index];
}


/*******************************************************************************
* Function Name: Cy_MSCLP_ReadSensorDataArray
****************************************************************************//**
*
* Reads an array of 32-bit data words from the SNS.SENSOR_DATA memory.
*
* \note Accessing the SNS group registers under disabled MRSS might lead to the
* device hard fault. Therefore, access the SNS group registers of the
* MSCLP HW block only under enabled MRSS. To enable, disable or check the MRSS
* power status, use the Cy_MSCLP_MrssStart(), Cy_MSCLP_MrssStop() or
* Cy_MSCLP_MrssStatus() functions respectively.
*
* \param base
* Pointer to a MSCLP HW block base address.
*
* \param startAddr
* The starting address (index of the 32-bit word) in the SNS.SENSOR_DATA.
*
* \param ptrData
* Pointer to the 32-bit data array to be copied from the SNS.SENSOR_DATA.
*
* \param dataSize
* The size of the data array (in 32-bit words).
*
* \note In case of the startAddr + dataSize exceeds the SNS.SENSOR_DATA size
* then no one data word will be copied.
*
*******************************************************************************/
void Cy_MSCLP_ReadSensorDataArray(MSCLP_Type const * base, uint32_t startAddr, uint32_t * ptrData, uint32_t dataSize)
{
    uint32_t * ptrLocData = ptrData;
    __IM uint32_t * ptrSnsData = &base->SNS.SENSOR_DATA[startAddr];
    uint32_t loopCnt;

    if (CY_MSCLP_SNS_SRAM_WORD_SIZE >= (startAddr + dataSize))
    {
        for (loopCnt = dataSize; loopCnt > 0UL; loopCnt--)
        {
            *ptrLocData = *ptrSnsData;
            ptrLocData++;
            ptrSnsData++;
        }
    }
}


/*******************************************************************************
* Function Name: Cy_MSCLP_WriteSensorDataArray
****************************************************************************//**
*
* Writes an array of 32-bit data words into the SNS.SENSOR_DATA memory.
*
* \note Accessing the SNS group registers under disabled MRSS might lead to the
* device hard fault. Therefore, access the SNS group registers of the
* MSCLP HW block only under enabled MRSS. To enable, disable or check the MRSS
* power status, use the Cy_MSCLP_MrssStart(), Cy_MSCLP_MrssStop() or
* Cy_MSCLP_MrssStatus() functions respectively.
*
* \param base
* Pointer to a MSCLP HW block base address.
*
* \param startAddr
* The starting address (index of the 32-bit word) in the SNS.SENSOR_DATA.
*
* \param ptrData
* Pointer to the 32-bit data array to be copied into the SNS.SENSOR_DATA.
*
* \param dataSize
* The size of the data array (in 32-bit words).
*
* \return
* Returns the status of the operation \ref cy_en_msclp_status_t
* - \ref CY_MSCLP_SUCCESS    - The data is written successfully
* - \ref CY_MSCLP_BAD_PARAM  - The startAddr + dataSize exceeds the SNS.SENSOR_DATA,
*                              no one data word is written.
*
*******************************************************************************/
cy_en_msclp_status_t Cy_MSCLP_WriteSensorDataArray(MSCLP_Type * base, uint32_t startAddr, uint32_t const * ptrData, uint32_t dataSize)
{
    cy_en_msclp_status_t msclpStatus = CY_MSCLP_BAD_PARAM;
    const uint32_t * ptrLocData = ptrData;
    __IOM uint32_t * ptrSnsData = &base->SNS.SENSOR_DATA[startAddr];
    uint32_t loopCnt;

    if (CY_MSCLP_SNS_SRAM_WORD_SIZE >= (startAddr + dataSize))
    {
        for (loopCnt = dataSize; loopCnt > 0UL; loopCnt--)
        {
            *ptrSnsData = *ptrLocData;
            ptrLocData++;
            ptrSnsData++;
        }
        msclpStatus = CY_MSCLP_SUCCESS;
    }

    return msclpStatus;
}

/** \} group_msclp_functions */

#endif /* CY_IP_M0S8MSCV3LP */


/* [] END OF FILE */
