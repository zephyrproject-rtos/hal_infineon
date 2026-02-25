#ifndef MTB_STL_POST_H
#define MTB_STL_POST_H

/*
 * MTB-STL includes - these come from the vendor library
 */
#if defined(CONFIG_POST_MTB_STL_STARTUP_CFGREG) ||                             \
    defined(CONFIG_POST_MTB_STL_SAVE_STARTUP_CFGREG)
#include "SelfTest_CRC_calc.h"
#include "SelfTest_ConfigRegisters.h"
#endif

#if defined(CONFIG_POST_MTB_STL_CPU_REGS) ||                                   \
    defined(CONFIG_POST_MTB_STL_CPU_PC) ||                                     \
    defined(CONFIG_POST_MTB_STL_PROGRAM_FLOW)
#include "SelfTest_CPU.h"
#endif

#if defined(CONFIG_POST_MTB_STL_RAM_MARCH) ||                                  \
    defined(CONFIG_POST_MTB_STL_STACK_MARCH)
#include "SelfTest_RAM.h"
#endif

#if defined(CONFIG_POST_MTB_STL_STACK)
#include "SelfTest_Stack.h"
#endif

#if defined(CONFIG_POST_MTB_STL_FLASH)
#include "SelfTest_Flash.h"
#include <zephyr/devicetree.h>
#include <zephyr/storage/flash_map.h>
#endif

#if defined(CONFIG_POST_MTB_STL_GPIO)
#include "SelfTest_IO.h"
#endif

#if defined(CONFIG_POST_MTB_STL_WDT)
#include "SelfTest_WDT.h"
#endif

#if defined(CONFIG_POST_MTB_STL_FPU)
#include "SelfTest_FPU_Regs.h"
#endif

#if defined(CONFIG_POST_MTB_STL_DMA)
#define DMA_TEST_NODE DT_NODELABEL(dma_test)
#include "SelfTest_DMAC.h"
#endif

#if defined(CONFIG_POST_MTB_STL_INTERRUPT)
#include "SelfTest_Interrupt.h"
#define INTERRUPT_TEST_NODE DT_NODELABEL(interrupt_test)
#define COUNTER_INTR_TEST_NODE DT_PHANDLE(INTERRUPT_TEST_NODE, tcpwm)
#define CLOCK_INTR_TEST_NODE DT_PHANDLE(COUNTER_INTR_TEST_NODE, clocks)
#endif

#if defined(CONFIG_POST_MTB_STL_CLOCK)
#include "SelfTest_Clock.h"
#define CLOCK_TEST_NODE DT_NODELABEL(clock_test)
#define COUNTER_CLK_TEST_NODE DT_PHANDLE(CLOCK_TEST_NODE, tcpwm)
#define DEFAULT_CLOCK_CLK_TEST_NODE DT_PHANDLE(CLOCK_TEST_NODE, counter_clock)
#if DT_NODE_HAS_PROP(COUNTER_CLK_TEST_NODE, clocks)
#define CLOCK_CLK_TEST_NODE DT_PHANDLE(COUNTER_CLK_TEST_NODE, clocks)
#endif
#endif

#if defined(CONFIG_POST_MTB_STL_UART_LOOPBACK)
#include "SelfTest_UART_SCB.h"
#define UART_TEST_NODE DT_NODELABEL(uart_loopback_test)
#define UART_LP_TEST_NODE DT_PHANDLE(UART_TEST_NODE, scb)
#endif

#if defined(CONFIG_POST_MTB_STL_COUNTER)
#include "SelfTest_Timer_Counter.h"
#define COUNTER_TEST_NODE DT_NODELABEL(counter_test)
#define COUNTER_CNT_TEST_NODE DT_PHANDLE(COUNTER_TEST_NODE, tcpwm)
#define CLOCK_CNT_TEST_NODE DT_PHANDLE(COUNTER_CNT_TEST_NODE, clocks)
#endif

#if defined(CONFIG_POST_MTB_STL_PWM_GATEKILL)
#include "SelfTest_PWM_GateKill.h"
#define PWM_GK_TEST_NODE DT_NODELABEL(pwm_gatekill_test)
#define COUNTER_PWM_GK_TEST_NODE DT_PHANDLE(PWM_GK_TEST_NODE, tcpwm)
#define CLOCK_PWM_GK_TEST_NODE DT_PHANDLE(COUNTER_PWM_GK_TEST_NODE, clocks)
#endif

#ifdef CONFIG_POST_MTB_STL_COMM
#include "SelfTest_CRC_calc.h"
#include "SelfTest_UART_master_message.h"
#include "SelfTest_UART_slave_message.h"
#define UART_COMMUNICATION_TEST_NODE DT_NODELABEL(uart_communication_test)
#define UART_COMM_MASTER_TEST_NODE DT_PHANDLE(UART_COMMUNICATION_TEST_NODE, scb)
#define UART_COMM_SLAVE_TEST_NODE                                              \
  DT_PHANDLE(UART_COMMUNICATION_TEST_NODE, scb_slave)
#define COUNTER_COMM_TEST_NODE DT_PHANDLE(UART_COMMUNICATION_TEST_NODE, tcpwm)
#define CNT_CLOCK_COMM_TEST_NODE DT_PHANDLE(COUNTER_COMM_TEST_NODE, clocks)
#endif

/*
 * Helper symbols
 */
extern char z_interrupt_stacks[];
extern char z_main_stack[];

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
} ifx_stl_saved_cnt_state_t;

/*
 * Helper Macros
 */

/*
 * Stack and Flash
 */
#ifndef CONFIG_MAIN_STACK_SIZE
#define DEVICE_STACK_SIZE (0x00000400) /* Default 1KB if not configured */
#else
#define DEVICE_STACK_SIZE (CONFIG_MAIN_STACK_SIZE)
#endif
#define DEVICE_SRAM_BASE DT_REG_ADDR(DT_CHOSEN(zephyr_sram))
#define DEVICE_SRAM_SIZE DT_REG_SIZE(DT_CHOSEN(zephyr_sram))
#define DEVICE_FLASH_BASE DT_REG_ADDR(DT_CHOSEN(zephyr_flash))
#define DEVICE_FLASH_SIZE DT_REG_SIZE(DT_CHOSEN(zephyr_flash))
#define DEVICE_STACK_BASE ((uintptr_t)z_main_stack)

static inline bool infineon_stl_cnt_enabled(TCPWM_Type const *base,
                                            uint32_t cntnum) {
  uint32_t counter_status;
  bool enabled;

  /* Check if counter is enabled/running */
  counter_status = Cy_TCPWM_Counter_GetStatus(base, cntnum);
  enabled = (counter_status & CY_TCPWM_COUNTER_STATUS_COUNTER_RUNNING) != 0;

  return enabled;
}

static inline void infineon_stl_stop_running_cnt(TCPWM_Type *base,
                                                 uint32_t cntnum) {
#if defined(CY_IP_M0S8TCPWM)
  uint32_t shiftedValue = (uint32_t)1U << cntnum;
  Cy_TCPWM_TriggerStopOrKill(base, shiftedValue);
#else
  Cy_TCPWM_TriggerStopOrKill_Single(base, cntnum);
#endif
}

static inline void infineon_stl_start_cnt(bool savedcnt_enabled,
                                          TCPWM_Type *base, uint32_t cntnum) {
  if (savedcnt_enabled) {
#if defined(CY_IP_M0S8TCPWM)
    uint32_t shiftedValue = (uint32_t)1U << cntnum;
    Cy_TCPWM_TriggerStart(base, shiftedValue);
#else
    Cy_TCPWM_TriggerStart_Single(base, cntnum);
#endif
  }
}

static inline void
infineon_stl_save_current_cnt_state(ifx_stl_saved_cnt_state_t *saved_cnt_state,
                                    TCPWM_Type const *base, uint32_t cntnum) {
  saved_cnt_state->period = Cy_TCPWM_Counter_GetPeriod(base, cntnum);
  saved_cnt_state->compare0 = Cy_TCPWM_Counter_GetCompare0(base, cntnum);
  saved_cnt_state->compare1 = Cy_TCPWM_Counter_GetCompare1(base, cntnum);
  saved_cnt_state->counter_value = Cy_TCPWM_Counter_GetCounter(base, cntnum);
  saved_cnt_state->interrupt_mask = Cy_TCPWM_GetInterruptMask(base, cntnum);
}

/* Configure counter with POST test parameters */
static inline void infineon_stl_config_post_parameter(TCPWM_Type *base,
                                                      uint32_t cntnum,
                                                      uint32_t test_period,
                                                      uint32_t test_compare0,
                                                      uint32_t test_compare1) {
  Cy_TCPWM_Counter_SetPeriod(base, cntnum, test_period);
  Cy_TCPWM_Counter_SetCompare0(base, cntnum, test_compare0);
  Cy_TCPWM_Counter_SetCompare1(base, cntnum, test_compare1);
}

static inline void
infineon_stl_restore_cnt_state(ifx_stl_saved_cnt_state_t *saved_cnt_state,
                               TCPWM_Type *base, uint32_t cntnum) {
  Cy_TCPWM_Counter_SetPeriod(base, cntnum, saved_cnt_state->period);
  Cy_TCPWM_Counter_SetCompare0(base, cntnum, saved_cnt_state->compare0);
  Cy_TCPWM_Counter_SetCompare1(base, cntnum, saved_cnt_state->compare1);
  Cy_TCPWM_Counter_SetCounter(base, cntnum, saved_cnt_state->counter_value);
  Cy_TCPWM_SetInterruptMask(base, cntnum, saved_cnt_state->interrupt_mask);
}

#endif /* MTB_STL_POST_H */
