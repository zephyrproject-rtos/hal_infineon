/*
 * Copyright (c) 2026 Infineon Technologies AG,
 * or an affiliate of Infineon Technologies AG.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <system_cat1b.h>
#include <cy_pdl.h>

void ifx_cycfg_init(void)
{
	/* Initializes the system */
	SystemInit();
	Cy_PPCA_Enable(PPCA_CNFG);
	cy_stc_ppca_cnfg_ppcaout_output_selector_t ppcaoutCfg = {0, 1};
	Cy_PPCA_CNFG_PPCA_Output_Selector(PPCA_CNFG_CNFG, &ppcaoutCfg);
}
