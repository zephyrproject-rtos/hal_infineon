/*
 * Copyright (c) 2024 Infineon Technologies AG ,
 * or an affiliate of Infineon Technologies AG.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <errno.h>
#include <ifx_autanalog.h>
#include <cy_pdl.h>

#include <zephyr/device.h>
#include <zephyr/irq.h>
#include <zephyr/devicetree.h>
#include <zephyr/logging/log.h>

/* Initialization Status */
static bool ifx_autanalog_initialized = false;

LOG_MODULE_REGISTER(ifx_autanalog, CONFIG_ADC_LOG_LEVEL);

#define IFX_AUTANALOG_SAR_ADC_INTR_MASK                                                            \
	(CY_AUTANALOG_INT_SAR0_DONE | CY_AUTANALOG_INT_SAR0_EOS | CY_AUTANALOG_INT_SAR0_RESULT |   \
	 CY_AUTANALOG_INT_SAR0_RANGE0 | CY_AUTANALOG_INT_SAR0_RANGE1 |                             \
	 CY_AUTANALOG_INT_SAR0_RANGE2 | CY_AUTANALOG_INT_SAR0_RANGE3 |                             \
	 CY_AUTANALOG_INT_SAR0_FIR0_RESULT | CY_AUTANALOG_INT_SAR0_FIR1_RESULT)

#define IFX_AUTANALOG_DAC0_INTR_MASK                                                               \
	(CY_AUTANALOG_INT_DAC0_RANGE0 | CY_AUTANALOG_INT_DAC0_RANGE1 |                             \
	 CY_AUTANALOG_INT_DAC0_RANGE2 | CY_AUTANALOG_INT_DAC0_EPOCH | CY_AUTANALOG_INT_DAC0_EMPTY)

#define IFX_AUTANALOG_DAC1_INTR_MASK                                                               \
	(CY_AUTANALOG_INT_DAC1_RANGE0 | CY_AUTANALOG_INT_DAC1_RANGE1 |                             \
	 CY_AUTANALOG_INT_DAC1_RANGE2 | CY_AUTANALOG_INT_DAC1_EPOCH | CY_AUTANALOG_INT_DAC1_EMPTY)

#define IFX_AUTANALOG_CTB0_INTR_MASK (CY_AUTANALOG_INT_CTB0_COMP0 | CY_AUTANALOG_INT_CTB0_COMP1)

#define IFX_AUTANALOG_CTB1_INTR_MASK (CY_AUTANALOG_INT_CTB1_COMP0 | CY_AUTANALOG_INT_CTB1_COMP1)

#define IFX_AUTANALOG_PTCOMP0_INTR_MASK                                                            \
	(CY_AUTANALOG_INT_PTC0_COMP0 | CY_AUTANALOG_INT_PTC0_COMP1 |                               \
	 CY_AUTANALOG_INT_PTC0_RANGE0 | CY_AUTANALOG_INT_PTC0_RANGE1)

#define IFX_AUTANALOG_AC_INTR_MASK CY_AUTANALOG_INT_AC

/* Get the interrupt information from the devicetree */
#define AUTANALOG_NODE DT_NODELABEL(autanalog)

static const IRQn_Type AUTANALOG_IRQ_NUM = (IRQn_Type)DT_IRQN(AUTANALOG_NODE);
static const uint8_t AUTANALOG_IRQ_PRIO = (uint8_t)DT_IRQ(AUTANALOG_NODE, priority);

/* PDL Configuration Structures */
cy_en_autanalog_ac_out_trigger_mask_t CYBSP_AUTONOMOUS_CONTROLLER_out_trig_mask[] = {
	CY_AUTANALOG_AC_OUT_TRIG_MASK_EMPTY, CY_AUTANALOG_AC_OUT_TRIG_MASK_EMPTY,
	CY_AUTANALOG_AC_OUT_TRIG_MASK_EMPTY, CY_AUTANALOG_AC_OUT_TRIG_MASK_EMPTY,
	CY_AUTANALOG_AC_OUT_TRIG_MASK_EMPTY, CY_AUTANALOG_AC_OUT_TRIG_MASK_EMPTY,
	CY_AUTANALOG_AC_OUT_TRIG_MASK_EMPTY, CY_AUTANALOG_AC_OUT_TRIG_MASK_EMPTY,
};

cy_stc_autanalog_ac_t CYBSP_AUTONOMOUS_CONTROLLER_cfg = {
	.gpioOutEn = CY_AUTANALOG_STT_AC_GPIO_OUT_DISABLED,
	.mask =
		{
			&CYBSP_AUTONOMOUS_CONTROLLER_out_trig_mask[0U],
			&CYBSP_AUTONOMOUS_CONTROLLER_out_trig_mask[1U],
			&CYBSP_AUTONOMOUS_CONTROLLER_out_trig_mask[2U],
			&CYBSP_AUTONOMOUS_CONTROLLER_out_trig_mask[3U],
			&CYBSP_AUTONOMOUS_CONTROLLER_out_trig_mask[4U],
			&CYBSP_AUTONOMOUS_CONTROLLER_out_trig_mask[5U],
			&CYBSP_AUTONOMOUS_CONTROLLER_out_trig_mask[6U],
			&CYBSP_AUTONOMOUS_CONTROLLER_out_trig_mask[7U],
		},
	.timer =
		{
			.enable = false,
			.clkSrc = CY_AUTANALOG_TIMER_CLK_LP,
			.period = 0U,
		},
};

cy_stc_autanalog_stt_ac_t CYBSP_AUTONOMOUS_CONTROLLER_stt[] = {
	{
		.unlock = true,
		.lpMode = false,
		.condition = CY_AUTANALOG_STT_AC_CONDITION_BLOCK_READY,
		.action = CY_AUTANALOG_STT_AC_ACTION_WAIT_FOR,
		.branchState = 1U,
		.trigInt = false,
		.count = 0U,
		.unlockGpioOut = false,
		.gpioOut = CY_AUTANALOG_STT_AC_GPIO_OUT_DISABLED,
	},
	{
		.unlock = false,
		.lpMode = false,
		.condition = CY_AUTANALOG_STT_AC_CONDITION_SAR_DONE,
		.action = CY_AUTANALOG_STT_AC_ACTION_WAIT_FOR,
		.branchState = 0U,
		.trigInt = false,
		.count = 0U,
		.unlockGpioOut = false,
		.gpioOut = CY_AUTANALOG_STT_AC_GPIO_OUT_DISABLED,
	},
	{
		.unlock = false,
		.lpMode = false,
		.condition = CY_AUTANALOG_STT_AC_CONDITION_FALSE,
		.action = CY_AUTANALOG_STT_AC_ACTION_STOP,
		.branchState = 0U,
		.trigInt = false,
		.count = 0U,
		.unlockGpioOut = false,
		.gpioOut = CY_AUTANALOG_STT_AC_GPIO_OUT_DISABLED,
	},
};

cy_stc_autanalog_stt_sar_t CYBSP_SAR_ADC_stt[] = {
	{
		.unlock = true,
		.enable = true,
		.trigger = false,
		.entryState = 0U,
	},
	{
		.unlock = true,
		.enable = true,
		.trigger = true,
		.entryState = 0U,
	},
	{
		.unlock = true,
		.enable = true,
		.trigger = false,
		.entryState = 0U,
	},
};

cy_stc_autanalog_stt_t autonomous_analog_stt[] = {
	{
		.ac = &CYBSP_AUTONOMOUS_CONTROLLER_stt[0U],
		.prb = NULL,
		.ctb =
			{
				NULL,
				NULL,
			},
		.ptcomp =
			{
				NULL,
			},
		.dac =
			{
				NULL,
				NULL,
			},
		.sar =
			{
				&CYBSP_SAR_ADC_stt[0U],
			},
	},
	{
		.ac = &CYBSP_AUTONOMOUS_CONTROLLER_stt[1U],
		.prb = NULL,
		.ctb =
			{
				NULL,
				NULL,
			},
		.ptcomp =
			{
				NULL,
			},
		.dac =
			{
				NULL,
				NULL,
			},
		.sar =
			{
				&CYBSP_SAR_ADC_stt[1U],
			},
	},
	{
		.ac = &CYBSP_AUTONOMOUS_CONTROLLER_stt[2U],
		.prb = NULL,
		.ctb =
			{
				NULL,
				NULL,
			},
		.ptcomp =
			{
				NULL,
			},
		.dac =
			{
				NULL,
				NULL,
			},
		.sar =
			{
				&CYBSP_SAR_ADC_stt[2U],
			},
	},
};

cy_stc_autanalog_cfg_t ifx_autonomous_analog_cfg = {
	.prb = NULL,
	.ac = &CYBSP_AUTONOMOUS_CONTROLLER_cfg,
	.ctb =
		{
			NULL,
			NULL,
		},
	.ptcomp =
		{
			NULL,
		},
	.dac =
		{
			NULL,
			NULL,
		},
	.sar =
		{
			NULL,
		},
};

cy_stc_autanalog_t ifx_autonomous_analog_init = {
	.configuration = &ifx_autonomous_analog_cfg,
	.numSttEntries = sizeof(autonomous_analog_stt) / sizeof(autonomous_analog_stt[0U]),
	.stateTransitionTable = &autonomous_analog_stt[0U],
};

/* Autanalog data structure, contains pointers to interrupt handlers for peripherals that share the
 * Autanalog interrupt.
 */
struct ifx_autanalog_data {
	void (*adc_handler)(const struct device *dev);
	const struct device *adc_dev;
	void (*dac0_handler)(const struct device *dev);
	const struct device *dac0_dev;
	void (*dac1_handler)(const struct device *dev);
	const struct device *dac1_dev;
	void (*ctb0_handler)(const struct device *dev);
	const struct device *ctb0_dev;
	void (*ctb1_handler)(const struct device *dev);
	const struct device *ctb1_dev;
	void (*ptcomp0_handler)(const struct device *dev);
	const struct device *ptcomp0_dev;
	void (*ac_handler)(const struct device *dev);
	const struct device *ac_dev;
};

struct ifx_autanalog_data data = {
	.adc_handler = NULL,
	.adc_dev = NULL,
	.dac0_handler = NULL,
	.dac0_dev = NULL,
	.dac1_handler = NULL,
	.dac1_dev = NULL,
	.ctb0_handler = NULL,
	.ctb0_dev = NULL,
	.ctb1_handler = NULL,
	.ctb1_dev = NULL,
	.ptcomp0_handler = NULL,
	.ptcomp0_dev = NULL,
	.ac_handler = NULL,
	.ac_dev = NULL,
};

/**
 * @brief AutAnalog Register ADC Handler
 *
 * Register an ADC interrupt handler to be called from the AutAnalog ISR when an ADC interrupt
 * occurs.
 */
void ifx_autanalog_register_adc_handler(void (*handler)(const struct device *dev),
					const struct device *adc_dev)
{
	if (handler == NULL || adc_dev == NULL) {
		return;
	}

	data.adc_handler = handler;
	data.adc_dev = adc_dev;
} /* ifx_autanalog_register_adc_handler() */

/**
 * @brief Start SAR Autonomous Control
 *
 * Start the SAR ADC autonomous control state machine.  For now this function is just a wrapper to
 * allow the ADC to control the AC.  When more devices are using the AC, this function will be used
 * to oversee access to the AC.
 *
 * @return 0 on success, -1 if AutAnalog is not initialized
 */
int ifx_autanalog_start_sar_autonomous_control(void)
{
	if (ifx_autanalog_initialized == false) {
		return -1;
	}

	Cy_AutAnalog_StartAutonomousControl();

	return 0;
} /* ifx_autanalog_start_sar_autonomous_control() */

/**
 * @brief Pause SAR Autonomous Control
 *
 * Pause the SAR ADC autonomous control state machine.  For now this function is just a wrapper to
 * allow the ADC to control the AC.  When more devices are using the AC, this function will be used
 * to oversee access to the AC.
 *
 * @return 0 on success, -1 if AutAnalog is not initialized
 */
int ifx_autanalog_pause_sar_autonomous_control(void)
{
	if (ifx_autanalog_initialized == false) {
		return -1;
	}

	Cy_AutAnalog_PauseAutonomousControl();

	return 0;
} /* ifx_autanalog_pause_sar_autonomous_control() */

/**
 * @brief AutAnalog Interrupt Service Routine
 *
 * Shared interrupt handler for peripherals share the AutANalog interrupt.  Currently only ADC is
 * supported, but this can also include DAC, CTB, etc.
 */
void ifx_autanalog_isr(const void *arg)
{
	ARG_UNUSED(arg);

	uint32_t int_source = Cy_AutAnalog_GetInterruptCause();

	if (int_source & IFX_AUTANALOG_SAR_ADC_INTR_MASK) {
		if (data.adc_handler != NULL) {
			data.adc_handler(data.adc_dev);
		} else {
			LOG_ERR("AutAnalog ADC Unhandled Interrupt");
		}
	}

	if (int_source & IFX_AUTANALOG_DAC0_INTR_MASK) {
		if (data.dac0_handler != NULL) {
			data.dac0_handler(data.dac0_dev);
		} else {
			LOG_ERR("AutAnalog DAC0 Unhandled Interrupt");
		}
	}

	if (int_source & IFX_AUTANALOG_DAC1_INTR_MASK) {
		if (data.dac1_handler != NULL) {
			data.dac1_handler(data.dac1_dev);
		} else {
			LOG_ERR("AutAnalog DAC1 Unhandled Interrupt");
		}
	}

	if (int_source & IFX_AUTANALOG_CTB0_INTR_MASK) {
		if (data.ctb0_handler != NULL) {
			data.ctb0_handler(data.ctb0_dev);
		} else {
			LOG_ERR("AutAnalog CTB0 Unhandled Interrupt");
		}
	}

	if (int_source & IFX_AUTANALOG_CTB1_INTR_MASK) {
		if (data.ctb1_handler != NULL) {
			data.ctb1_handler(data.ctb1_dev);
		} else {
			LOG_ERR("AutAnalog CTB1 Unhandled Interrupt");
		}
	}

	if (int_source & IFX_AUTANALOG_PTCOMP0_INTR_MASK) {
		if (data.ptcomp0_handler != NULL) {
			data.ptcomp0_handler(data.ptcomp0_dev);
		} else {
			LOG_ERR("AutAnalog PTCOMP0 Unhandled Interrupt");
		}
	}

	if (int_source & IFX_AUTANALOG_AC_INTR_MASK) {
		if (data.ac_handler != NULL) {
			data.ac_handler(data.ac_dev);
		} else {
			LOG_ERR("AutAnalog AC Unhandled Interrupt");
		}
	}

	Cy_AutAnalog_ClearInterrupt(int_source);
} /* ifx_autanalog_isr() */

/**
 * @brief Initialize the AutAnalog driver
 *
 * @return 0 on success, -EIO on failure
 */
int ifx_autanalog_init(void)
{
	cy_rslt_t result_val;

	if (ifx_autanalog_initialized == false) {
		Cy_SysClk_PeriGroupSlaveInit(CY_MMIO_PASS_PERI_NR, CY_MMIO_PASS_GROUP_NR,
					     CY_MMIO_PASS_SLAVE_NR, CY_MMIO_PASS_CLK_HF_NR);

		result_val = Cy_AutAnalog_Init(&ifx_autonomous_analog_init);
		if (result_val != CY_RSLT_SUCCESS) {
			return -EIO;
		}

		IRQ_CONNECT(AUTANALOG_IRQ_NUM, AUTANALOG_IRQ_PRIO, ifx_autanalog_isr, NULL, 0);
		Cy_AutAnalog_SetInterruptMask(IFX_AUTANALOG_SAR_ADC_INTR_MASK);
		irq_enable(AUTANALOG_IRQ_NUM);

		ifx_autanalog_initialized = true;
	}

	return 0;
} /* ifx_autanalog_init() */
