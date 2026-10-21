/***************************************************************************//**
* \file cybsp.c
*
* Description:
* Provides initialization code for starting up the hardware contained on the
* Infineon board.
*
********************************************************************************
* \copyright
* (c) 2018-2026, Infineon Technologies AG, or an affiliate of Infineon
* Technologies AG.
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

#include <stdlib.h>

#if !defined(CYBSP_SKIP_PM_REGISTRATION)
#include "cybsp_pm.h"
#endif

#include "cy_syspm.h"
#include "cy_sysclk.h"
#include "cybsp.h"
#include "cycfg.h"
#include "cybsp_dsram.h"
#if defined(CY_IP_MXSMIF_INSTANCES) && (CY_IP_MXSMIF_INSTANCES > 0)
#include "cycfg_qspi_memslot.h"
#endif

#if ((CY_SYSTEM_CPU_M33) && defined(COMPONENT_NON_SECURE_DEVICE))
#include "cycfg_protection.h"
#endif

#ifndef CYBSP_DISABLE_SRF_INIT
#if defined(COMPONENT_SECURE_DEVICE)
#include "mtb_srf.h"
#else
#include "mtb_srf_pool_init.h"
#endif
#endif
#if (CY_SYSTEM_CPU_M33) && defined(COMPONENT_SECURE_DEVICE)
#include "partition_ARMCM33.h"
#endif // (CY_SYSTEM_CPU_M33) && defined(COMPONENT_SECURE_DEVICE)

#if defined(__cplusplus)
extern "C" {
#endif

#if defined(CYBSP_POST_CFG_INIT)
/* If this BSP requires a step immediately after init_cycfg_all, declare it */
cy_rslt_t cybsp_post_cfg_init();
#endif // defined(CYBSP_POST_CFG_INIT)

// The sysclk deep sleep callback is recommended to be the last callback that is executed before
// entry into deep sleep mode and the first one upon exit the deep sleep mode.
// Doing so minimizes the time spent on low power mode entry and exit.
#ifndef CYBSP_SYSCLK_PM_CALLBACK_ORDER
    #define CYBSP_SYSCLK_PM_CALLBACK_ORDER  (255u)
#endif

#if !defined(COMPONENT_MW_MTB_SRF) || defined(CY_SRF_DISABLE)
/* If the MTB-SRF library isn't present, disable its initialization */
#define CYBSP_DISABLE_SRF_INIT     (1)
#endif
#ifndef CYBSP_DISABLE_SRF_INIT
// Secure context and pool for use with the Secure Request Framework
#if defined(COMPONENT_SECURE_DEVICE)
#if !defined(MTB_SRF_SECURE_CONTEXT_SECTION)
// Optional macro to specify the linker section for the secure context
#define MTB_SRF_SECURE_CONTEXT_SECTION
#endif
MTB_SRF_SECURE_CONTEXT_SECTION mtb_srf_context_s_t cybsp_srf_context;
#else
mtb_srf_pool_t cy_pdl_srf_default_pool;
CY_SECTION_SHAREDMEM _MTB_SRF_DATA_ALIGN uint32_t cy_pdl_srf_default_pool_memory[(MTB_SRF_POOL_ENTRY_SIZE(
                                                                         MTB_SRF_MAX_ARG_IN_SIZE,
                                                                         MTB_SRF_MAX_ARG_OUT_SIZE)
                                                                     * MTB_SRF_POOL_SIZE) /
                                                                    sizeof(uint32_t)];
#endif // defined(COMPONENT_SECURE_DEVICE)
#endif // ifndef CYBSP_DISABLE_SRF_INIT


//--------------------------------------------------------------------------------------------------
// cybsp_init
//--------------------------------------------------------------------------------------------------
cy_rslt_t cybsp_init(void)
{
    // Setup hardware manager to track resource usage then initialize all system (clock/power) board
    // configuration
    cy_rslt_t result = CY_RSLT_SUCCESS;

    // CM33 secure is the first to boot. Initialize peripherals, SAU, any enabled MPCs, and the MPU
    // for this core
    #if (CY_SYSTEM_CPU_M33) && defined(COMPONENT_SECURE_DEVICE)

    // Setup System Control Block
    SysCtrlBlk_Setup();

    #if defined (__FPU_USED) && (__FPU_USED == 1U) && \
    defined (TZ_FPU_NS_USAGE) && (TZ_FPU_NS_USAGE == 1U)
    /*FPU initialization*/
    initFPU();
    #endif

    // Update SystemCoreClock before init_cycfg_all() enables SAU.
    // SAU Region 2 marks 0x40000000-0xFFFFFFFF as Non-Secure, which covers the
    // secure MMIO alias (0x52xxxxxx). Any peripheral register read after SAU is
    // enabled will carry the NS attribute and fault. At this point SAU is still
    // disabled (default = everything secure), so the clock register reads succeed.
    SystemCoreClockUpdate();

    // Initialize system clocks, peripheral clock dividers, pin configurations, routing, SAU, MPCs
    // and MPU for the core
    init_cycfg_all();

    if (CY_RSLT_SUCCESS == result)
    {
        #if defined(CYBSP_CUSTOM_SYSCLK_PM_CALLBACK)
        result = cybsp_register_custom_sysclk_pm_callback();
        #endif
    }


    #if defined(CYBSP_POST_CFG_INIT)
    /* Perform custom initialization step */
    result = cybsp_post_cfg_init();
    if (result != CY_RSLT_SUCCESS)
    {
        return result;
    }
    #endif

    #if !defined(CYBSP_DISABLE_SRF_INIT)
    // Set up the SRF and register the PDL module
    result = mtb_srf_init(&cybsp_srf_context);
    if (result != CY_RSLT_SUCCESS)
    {
        return result;
    }
    #if defined(CY_PDL_ENABLE_SECURE_AWARE) && (CY_PDL_ENABLE_SECURE_AWARE)
    result = cy_pdl_srf_module_register(&cybsp_srf_context);
    if (result != CY_RSLT_SUCCESS)
    {
        return result;
    }
    #endif // defined(CY_PDL_ENABLE_SECURE_AWARE) && (CY_PDL_ENABLE_SECURE_AWARE)
    #endif // !defined(CYBSP_DISABLE_SRF_INIT)

    // Setup NS NVIC interrupts - only for secure main CM33 core
    #if defined(CY_CYBSP_NVIC_NS_ENABLE)
    NVIC_NS_Setup();
    #endif // defined(CY_CYBSP_NVIC_NS_ENABLE)

    #else // CM33 non-secure

    #if !defined(CYBSP_DISABLE_SRF_INIT)
    result = mtb_srf_pool_init(&cy_pdl_srf_default_pool,
                               &cy_pdl_srf_default_pool_memory[0], MTB_SRF_POOL_SIZE,
                               MTB_SRF_MAX_ARG_IN_SIZE, MTB_SRF_MAX_ARG_OUT_SIZE);
    if (result != CY_RSLT_SUCCESS)
    {
        return result;
    }
    #endif // !defined(CYBSP_DISABLE_SRF_INIT)

    // The ECO frequency is stored in a software variable (see Cy_SysClk_EcoSetFrequency)
    // that is populated by init_cycfg_all() on the secure core only. The non-secure image
    // has its own copy of that variable, so without this call Cy_SysClk_EcoGetFrequency()
    // returns 0 on the non-secure side and every ECO-derived clock reports 0.
    #if defined(CY_CFG_SYSCLK_ECO_ENABLED) && (CY_CFG_SYSCLK_ECO_ENABLED)
    Cy_SysClk_EcoSetFrequency(CY_CFG_SYSCLK_ECO_FREQ);
    #endif // defined(CY_CFG_SYSCLK_ECO_ENABLED) && (CY_CFG_SYSCLK_ECO_ENABLED)

    // Non-secure app builds need this explicit call.
    SystemCoreClockUpdate();

    #if ((CY_SYSTEM_CPU_M33) && defined(COMPONENT_NON_SECURE_DEVICE))
    // Initialize the non-secure MPU (configured via the Device Configurator).
    // init_cycfg_protection() calls Cy_MPU_Init() when COMPONENT_NON_SECURE_DEVICE
    // is defined, which programs the MPU regions and enables the MPU.
    //init_cycfg_protection(); /* For now application needs to call this when MPU is enabled for non-secure from device-configurator */
    #endif // ((CY_SYSTEM_CPU_M33) && defined(COMPONENT_NON_SECURE_DEVICE))

    #endif // (CY_SYSTEM_CPU_M33) && defined(COMPONENT_SECURE_DEVICE)
    // Always initialize peripheral-related data structures
    // Skip PM/DSRAM registration on NS side cybsp_syspm_dsram_init() writes to secure BACKUP
    // registers and the warmboot handler calls init_cycfg_all() which accesses secure peripherals.
    #if !defined(CYBSP_SKIP_PM_REGISTRATION) && !defined(COMPONENT_NON_SECURE_DEVICE)
    if (CY_RSLT_SUCCESS == result)
    {
        result = cybsp_syspm_dsram_init();
    }

    if (CY_RSLT_SUCCESS == result)
    {
        result = cybsp_pm_callbacks_register();
    }
    #endif // !defined(CYBSP_SKIP_PM_REGISTRATION) && !defined(COMPONENT_NON_SECURE_DEVICE)

    return result;
}


#if defined(COMPONENT_MW_MTB_SRF) && !defined(MTB_SRF_CUSTOM_REQUEST_SUBMIT) && !defined(CYBSP_DISABLE_SRF_INIT)
#if defined(COMPONENT_SECURE_DEVICE)
//--------------------------------------------------------------------------------------------------
// mtb_srf_request_submit
//--------------------------------------------------------------------------------------------------
cy_rslt_t __attribute__((cmse_nonsecure_entry)) mtb_srf_request_submit(
    mtb_srf_invec_ns_t* inVec_ns, uint8_t inVec_cnt_ns,
    mtb_srf_outvec_ns_t* outVec_ns, uint8_t outVec_cnt_ns)
{
    return mtb_srf_request_execute(&cybsp_srf_context, inVec_ns, inVec_cnt_ns, outVec_ns,
                                   outVec_cnt_ns);
}
#endif /* defined(COMPONENT_SECURE_DEVICE) */
#endif /* defined(COMPONENT_MW_MTB_SRF) && !defined(MTB_SRF_CUSTOM_REQUEST_SUBMIT) && !defined(CYBSP_DISABLE_SRF_INIT) */


#if defined(__cplusplus)
}
#endif
