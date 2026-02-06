#ifndef MTB_STL_POST_CFG_H
#define MTB_STL_POST_CFG_H

#include <zephyr/kernel.h>
#include <zephyr/irq.h>
#include <zephyr/post/post.h>
#include <zephyr/post/post_vendor.h>
#include <zephyr/logging/log.h>
#include <zephyr/devicetree.h>

#include "cy_pdl.h"
#include "mtb_stl_post.h"

/* State saved before POST test */
typedef struct {
        uint32_t period;
        uint32_t compare0;
        uint32_t compare1;
        uint32_t counter_value;
        uint32_t interrupt_mask;
        bool enabled;
        /* Save counter driver's terminal count interrupt state */
        bool counter_driver_tc_enabled;
} infineon_stl_saved_counter_state_t;

extern const cy_stc_tcpwm_counter_config_t ifx_timer_config;
extern const cy_stc_tcpwm_counter_config_t ifx_clk_test_timer_config;
extern const cy_stc_sar_channel_config_t ifx_dut_sar_adc_ch_0_cfg;
extern const cy_stc_sar_config_t ifx_dut_sar_adc_cfg;
extern const cy_stc_scb_uart_config_t ifx_uart_test_cfg;
extern const cy_stc_tcpwm_counter_config_t ifx_timer_counter_config;
extern const cy_stc_tcpwm_pwm_config_t ifx_pwm_config;
extern const cy_stc_tcpwm_pwm_config_t ifx_pwm_gatekill_config;
extern const cy_stc_scb_uart_config_t ifx_uart_master_config;
extern const cy_stc_scb_uart_config_t ifx_uart_slave_cfg;
extern const cy_stc_tcpwm_counter_config_t ifx_timer_uart_master_cfg;

static inline bool infineon_stl_cnt_enabled(TCPWM_Type const *base, uint32_t cntnum)
{
	uint32_t counter_status;
	bool enabled;

	/* Check if counter is enabled/running */
	counter_status = Cy_TCPWM_Counter_GetStatus(base, cntnum);
	enabled = (counter_status & CY_TCPWM_COUNTER_STATUS_COUNTER_RUNNING) != 0;

	return enabled;
}

static inline void infineon_stl_stop_running_cnt(TCPWM_Type *base, uint32_t cntnum)
{
	/* Stop counter if running */
#if defined(CY_IP_M0S8TCPWM)
	uint32_t shiftedValue = (uint32_t)1U << cntnum;
	Cy_TCPWM_TriggerStopOrKill(base, shiftedValue);
#else
	Cy_TCPWM_TriggerStopOrKill_Single(base, cntnum);
#endif
}

static inline void infineon_stl_start_cnt(bool savedcnt_enabled, TCPWM_Type *base, uint32_t cntnum)
{
	if (savedcnt_enabled) {
		/* Stop counter if running */
#if defined(CY_IP_M0S8TCPWM)
		uint32_t shiftedValue = (uint32_t)1U << cntnum;
		Cy_TCPWM_TriggerStart(base, shiftedValue);
#else
		Cy_TCPWM_TriggerStart_Single(base, cntnum);
#endif
	}
}

static inline void infineon_stl_save_current_cnt_state(infineon_stl_saved_counter_state_t *saved_cnt_state,
						TCPWM_Type const *base, uint32_t cntnum)
{
	saved_cnt_state->period = Cy_TCPWM_Counter_GetPeriod(base, cntnum);
	saved_cnt_state->compare0 = Cy_TCPWM_Counter_GetCompare0(base, cntnum);
	saved_cnt_state->compare1 = Cy_TCPWM_Counter_GetCompare1(base, cntnum);
	saved_cnt_state->counter_value = Cy_TCPWM_Counter_GetCounter(base, cntnum);
	saved_cnt_state->interrupt_mask = Cy_TCPWM_GetInterruptMask(base, cntnum);
}

/* Configure counter with POST test parameters */
static inline void infineon_stl_config_post_parameter(const cy_stc_tcpwm_counter_config_t *post_test_cfgs,
						TCPWM_Type *base, uint32_t cntnum)
{
	Cy_TCPWM_Counter_SetPeriod(base, cntnum, post_test_cfgs->period);
	Cy_TCPWM_Counter_SetCompare0(base, cntnum, post_test_cfgs->compare0);
	Cy_TCPWM_Counter_SetCompare1(base, cntnum, post_test_cfgs->compare1);
}

static inline void infineon_stl_restore_cnt_state(infineon_stl_saved_counter_state_t *saved_cnt_state,
						TCPWM_Type *base, uint32_t cntnum)
{
	Cy_TCPWM_Counter_SetPeriod(base, cntnum, saved_cnt_state->period);
	Cy_TCPWM_Counter_SetCompare0(base, cntnum, saved_cnt_state->compare0);
	Cy_TCPWM_Counter_SetCompare1(base, cntnum, saved_cnt_state->compare1);
	Cy_TCPWM_Counter_SetCounter(base, cntnum, saved_cnt_state->counter_value);
	Cy_TCPWM_SetInterruptMask(base, cntnum, saved_cnt_state-> interrupt_mask);
}

static inline void infineon_stl_clk_cfg(cy_en_sysclk_divider_types_t div_type, uint32_t div_ch, uint32_t div_val, en_clk_dst_t periblock_clk)
{
	Cy_SysClk_PeriphDisableDivider(div_type, div_ch);
	Cy_SysClk_PeriphSetDivider(div_type, div_ch, (div_val - 1));
	Cy_SysClk_PeriphEnableDivider(div_type, div_ch);
	Cy_SysClk_PeriphAssignDivider(periblock_clk, div_type, div_ch);
}

static inline GPIO_PRT_Type *ifx_get_port_base(uint32_t port_num)
{
	switch (port_num) {
	case 0:
		return GPIO_PRT0;
	case 1:
		return GPIO_PRT1;
	case 2:
		return GPIO_PRT2;
	case 3:
		return GPIO_PRT3;
	case 4:
		return GPIO_PRT4;
	case 5:
		return GPIO_PRT5;
	case 6:
		return GPIO_PRT6;
	default:
		return NULL;
	}

}

#endif /* MTB_STL_POST_CFG_H */
