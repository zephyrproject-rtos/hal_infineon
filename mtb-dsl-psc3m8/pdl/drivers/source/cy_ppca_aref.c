/***************************************************************************//**
* \file cy_ppca_aref.c
* \version 1.0
*
* \brief
* Provides API implementation of the PPCA AREF driver.
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

#include "cy_device.h"

#if defined (CY_IP_MXS40PPSS)

#include "cy_ppca_aref.h"

#if defined(__cplusplus)
extern "C" {
#endif

#if defined (LOAD_PPCA_TRIMS)
static void Cy_PPCA_AREF_ApplyTrims(void);
#endif /* defined (LOAD_PPCA_TRIMS) */
/******************************************************************************
* Function Name: Cy_PPCA_AREF_Init
***************************************************************************//**
*
* Initializes and enables the AREF
*
* \param config AREF configuration.
*
* \param base The pointer to the AREF instance address.
*
******************************************************************************/
void Cy_PPCA_AREF_Init(ATOPSS_AREF_TYPE *base, cy_stc_ppca_aref_config_t const *config)
{
    /* Input parameters verification */
    CY_ASSERT(NULL != base);
    CY_ASSERT(NULL != config);

    PPCA_ATOP_AREF_CTL(base) = _VAL2FLD(PPCA_ATOPSS_ADC_GRP_AREF_AREF_CTL_AREF_MODE, config->aref_mode)                     |
                               _VAL2FLD(PPCA_ATOPSS_ADC_GRP_AREF_AREF_CTL_TSNS_CUR_ENABLED, config->enable_current_to_ts)   |
                               _VAL2FLD(PPCA_ATOPSS_ADC_GRP_AREF_AREF_CTL_AREF_BIAS_SCALE, 3U)                 |
                               _VAL2FLD(PPCA_ATOPSS_ADC_GRP_AREF_AREF_CTL_AREF_RMB, 0U)                        |
                               _VAL2FLD(PPCA_ATOPSS_ADC_GRP_AREF_AREF_CTL_CTB_IPTAT_SCALE, 0U)                 |
                               _VAL2FLD(PPCA_ATOPSS_ADC_GRP_AREF_AREF_CTL_CTB_IPTAT_REDIRECT, 0U)              |
                               _VAL2FLD(PPCA_ATOPSS_ADC_GRP_AREF_AREF_CTL_IZTAT_SEL, 1U)                       |
                               _VAL2FLD(PPCA_ATOPSS_ADC_GRP_AREF_AREF_CTL_VREF_SEL, config->vref_source_sel)   |
                               _VAL2FLD(PPCA_ATOPSS_ADC_GRP_AREF_AREF_CTL_ENABLED, 0U);

    PPCA_ATOP_AREF_ANA_CTL(base) = (uint32_t)(config->analog_ctrl);
#if defined (LOAD_PPCA_TRIMS)
    if((uint32_t)SFLASH_SVN_ES100 <= (uint32_t)SFLASH_SVN_VALUE)
    {
        Cy_PPCA_AREF_ApplyTrims();
    }
#endif /* defined (LOAD_PPCA_TRIMS) */

}


#if defined (LOAD_PPCA_TRIMS)
static void Cy_PPCA_AREF_ApplyTrims(void)
{
    /* The max number of trim pair entries */
    #define CY_PPCA_TRIMS_ENTRIES_NUM (8U)

    /* Trim data structure: address and value */
    typedef struct
    {
        volatile uint32_t * address;    /* Trim address */
        uint32_t value;                 /* Trim value */
    } cy_stc_ppca_trim_entry_t;

    /* SAR INFRA trim data structure*/
    typedef struct
    {
        uint32_t num_entries;           /* Number of trims entries */
        cy_stc_ppca_trim_entry_t entry[CY_PPCA_TRIMS_ENTRIES_NUM]; /* Array of address-value pairs */
    } cy_stc_ppca_trims_t;


    /* Copy AREF trimming values from SFLASH */
    CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 11.3','Intentional typecast to cy_stc_ppca_trims_t.');
    const cy_stc_ppca_trims_t * infraTrims = (cy_stc_ppca_trims_t*)SFLASH_SAR_INFRA_TRIM_TABLE;

    if (CY_PPCA_TRIMS_ENTRIES_NUM == infraTrims->num_entries)
    {
        for (uint32_t i = 0UL; i < CY_PPCA_TRIMS_ENTRIES_NUM; i++)
        {
            volatile uint32_t * trimAddr = infraTrims->entry[i].address;
            * trimAddr = infraTrims->entry[i].value;
        }
    }
    return;
}
#endif /* defined (LOAD_PPCA_TRIMS) */

#if defined(__cplusplus)
}
#endif

#endif /* CY_IP_MXS40PPSS */

/* [] END OF FILE */
