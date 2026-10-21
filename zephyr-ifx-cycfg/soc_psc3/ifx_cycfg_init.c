/*
 * Copyright (c) 2025 Infineon Technologies AG,
 * or an affiliate of Infineon Technologies AG.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <system_cat1b.h>
#include <ifx_hppass_analog.h>

void ifx_cycfg_init(void)
{
	/* Initializes the system */
	SystemInit();
#if defined(CONFIG_ADC_INFINEON_HPPASS_SAR)
	ifx_hppass_init();
#endif
}
