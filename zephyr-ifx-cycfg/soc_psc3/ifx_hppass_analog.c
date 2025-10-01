/*
 * Copyright (c) 2025 Infineon Technologies AG,
 * or an affiliate of Infineon Technologies AG.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 * @brief Driver for Infineon PSOC C3 HPPASS Analog Subsystem
 *
 * This is a skeleton driver for the HPPASS analog subsystem.
 * It provides basic initialization functionality for the HPPASS
 * analog subsystem, which is required to be initialized before
 * the HPPASS SAR ADC.
 */

#include <cy_pdl.h>

/** Initialization status */
static bool ifx_hppass_initialized;

/**
 * @brief HPPASS Autonomous Controller Configuration
 *
 * This is a configuration structure for the HPPASS Autonomous Controller (AC) to enable the ADC
 * subsystem.  It defines two AC states:
 *   1. Enable the SAR block and wait for it to be ready.
 *   2. Stop the AC and generate an interrupt.
 */
const cy_stc_hppass_ac_stt_t pass_0_ac_0_stt_0_config[] = {
	{
		.condition = CY_HPPASS_CONDITION_BLOCK_READY,
		.action = CY_HPPASS_ACTION_WAIT_FOR,
		.branchStateIdx = 0U,
		.interrupt = false,
		.count = 1U,
		.gpioOutUnlock = false,
		.gpioOutMsk = 0U,
		.csgUnlock = {false, false, false, false, false},
		.csgEnable = {false, false, false, false, false},
		.csgDacTrig = {false, false, false, false, false},
		.sarUnlock = true,
		.sarEnable = true,
		.sarGrpMsk = 0U,
		.sarMux = {{false, 0U}, {false, 0U}, {false, 0U}, {false, 0U}},
	},
	{
		.condition = CY_HPPASS_CONDITION_FALSE,
		.action = CY_HPPASS_ACTION_STOP,
		.branchStateIdx = 1U,
		.interrupt = true,
		.count = 1U,
		.gpioOutUnlock = false,
		.gpioOutMsk = 0U,
		.csgUnlock = {false, false, false, false, false},
		.csgEnable = {false, false, false, false, false},
		.csgDacTrig = {false, false, false, false, false},
		.sarUnlock = false,
		.sarEnable = false,
		.sarGrpMsk = 0U,
		.sarMux = {{false, 0U}, {false, 0U}, {false, 0U}, {false, 0U}},
	},
};
const cy_stc_hppass_ac_t pass_0_ac_adc_start_config = {.sttEntriesNum = 2U,
						       .stt = pass_0_ac_0_stt_0_config,
						       .gpioOutEnMsk = 0U,
						       .startupClkDiv = 24U,
						       .startup = {
									{
										.count = 200U,
										.sar = true,
										.csgChan = true,
										.csgSlice = false,
										.csgReady = false,
									},
									{
										.count = 50U,
										.sar = false,
										.csgChan = false,
										.csgSlice = true,
										.csgReady = false,
									},
									{
										.count = 0U,
										.sar = false,
										.csgChan = false,
										.csgSlice = false,
										.csgReady = true,
									},
									{
										.count = 0U,
										.sar = false,
										.csgChan = false,
										.csgSlice = false,
										.csgReady = false,
									},
								}
							};

const cy_stc_hppass_cfg_t pass_0_config = {
	.ac = {
			.sttEntriesNum = 2U,
			.stt = pass_0_ac_0_stt_0_config,
			.gpioOutEnMsk = 0U,
			.startupClkDiv = 24U,
			.startup = {
					{
						.count = 200U,
						.sar = true,
						.csgChan = true,
						.csgSlice = false,
						.csgReady = false,
					},
					{
						.count = 50U,
						.sar = false,
						.csgChan = false,
						.csgSlice = true,
						.csgReady = false,
					},
					{
						.count = 0U,
						.sar = false,
						.csgChan = false,
						.csgSlice = false,
						.csgReady = true,
					},
					{
						.count = 0U,
						.sar = false,
						.csgChan = false,
						.csgSlice = false,
						.csgReady = false,
					},
				},
		},
	.csg = NULL,
	.sar = NULL,
	.trigIn = {
			{
				.type = CY_HPPASS_TR_FW_PULSE,
				.hwMode = CY_HPPASS_PULSE_ON_POS_DOUBLE_SYNC,
			},
			{
				.type = CY_HPPASS_TR_DISABLED,
				.hwMode = CY_HPPASS_PULSE_ON_POS_DOUBLE_SYNC,
			},
			{
				.type = CY_HPPASS_TR_DISABLED,
				.hwMode = CY_HPPASS_PULSE_ON_POS_DOUBLE_SYNC,
			},
			{
				.type = CY_HPPASS_TR_DISABLED,
				.hwMode = CY_HPPASS_PULSE_ON_POS_DOUBLE_SYNC,
			},
			{
				.type = CY_HPPASS_TR_DISABLED,
				.hwMode = CY_HPPASS_PULSE_ON_POS_DOUBLE_SYNC,
			},
			{
				.type = CY_HPPASS_TR_DISABLED,
				.hwMode = CY_HPPASS_PULSE_ON_POS_DOUBLE_SYNC,
			},
			{
				.type = CY_HPPASS_TR_DISABLED,
				.hwMode = CY_HPPASS_PULSE_ON_POS_DOUBLE_SYNC,
			},
			{
				.type = CY_HPPASS_TR_DISABLED,
				.hwMode = CY_HPPASS_PULSE_ON_POS_DOUBLE_SYNC,
			},
		},
	.trigPulse = {
			CY_HPPASS_DISABLED,
			CY_HPPASS_DISABLED,
			CY_HPPASS_DISABLED,
			CY_HPPASS_DISABLED,
			CY_HPPASS_DISABLED,
			CY_HPPASS_DISABLED,
			CY_HPPASS_DISABLED,
			CY_HPPASS_DISABLED,
		},
	.trigLevel = {
			{
				.syncBypass = true,
				.compMsk = 0U,
				.limitMsk = 0U,
			},
			{
				.syncBypass = true,
				.compMsk = 0U,
				.limitMsk = 0U,
			},
			{
				.syncBypass = true,
				.compMsk = 0U,
				.limitMsk = 0U,
			},
			{
				.syncBypass = true,
				.compMsk = 0U,
				.limitMsk = 0U,
			},
			{
				.syncBypass = true,
				.compMsk = 0U,
				.limitMsk = 0U,
			},
			{
				.syncBypass = true,
				.compMsk = 0U,
				.limitMsk = 0U,
			},
			{
				.syncBypass = true,
				.compMsk = 0U,
				.limitMsk = 0U,
			},
			{
				.syncBypass = true,
				.compMsk = 0U,
				.limitMsk = 0U,
			},
		},
};

/**
 * @brief Run the Autonomous Controller (AC) to initialize the ADC subsystem
 *
 * This function sets up the AC to enable the ADC subsystem and waits for it to complete.
 */
cy_en_hppass_status_t ifx_hppass_ac_init_adc(void)
{
	if (Cy_HPPASS_AC_IsRunning()) {
		/* AC is already running, return error */
		return CY_HPPASS_AC_INVALID_STATE;
	}

	Cy_HPPASS_AC_LoadStateTransitionTable(pass_0_ac_adc_start_config.sttEntriesNum,
					      pass_0_ac_adc_start_config.stt);

	/* Start the HPPASS autonomous controller (AC) from state 0, didn't wait for HPPASS
	 * block ready
	 */
	if (CY_HPPASS_SUCCESS != Cy_HPPASS_AC_Start(0U, 0U)) {
		CY_ASSERT(0);
	}

	uint32_t intrStatus;

	do {
		intrStatus = Cy_HPPASS_GetInterruptStatusMasked();
	} while (CY_HPPASS_INTR_AC_INT != (intrStatus & CY_HPPASS_INTR_AC_INT));

	return 0;
}

/**
 * @brief Initialize the HPPASS analog subsystem
 *
 * This function initializes the HPPASS analog subsystem.
 * It configures the power, clocks, and reference voltages required
 * for proper operation of the HPPASS components including the SAR ADC.
 *
 * @param dev Pointer to the device structure for the driver instance
 *
 * @retval 0 If successful.
 * @retval -EINVAL Invalid parameters.
 * @retval -EIO I/O error when accessing device.
 */

int ifx_hppass_init(void)
{
	if (ifx_hppass_initialized) {
		/* Already initialized */
		return 0;
	}

	cy_rslt_t hppassStatus = 0UL;

	hppassStatus = Cy_HPPASS_Init(&pass_0_config);

	Cy_HPPASS_SetInterruptMask(CY_HPPASS_INTR_AC_INT);

	if( hppassStatus != CY_RSLT_SUCCESS ) {
		return hppassStatus;
	}

	ifx_hppass_initialized = true;

	return 0;
}
