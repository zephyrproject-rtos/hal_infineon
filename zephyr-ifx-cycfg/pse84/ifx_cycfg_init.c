/*
 * Copyright (c) 2024 Infineon Technologies AG ,
 * or an affiliate of Infineon Technologies AG.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <cy_sysint.h>
#include <system_edge.h>

#include <ifx_autanalog.h>

void ifx_cycfg_init(void)
{
	/* Initializes the system */
	SystemInit();
#if defined(CONFIG_ADC_INFINEON_AUTANALOG_SAR)
	ifx_autanalog_init();
#endif
}
