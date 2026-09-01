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
#include "SelfTest_DMA_DW.h"
#endif

#if defined(CONFIG_POST_MTB_STL_INTERRUPT)
#include "SelfTest_Interrupt.h"
#define INTERRUPT_TEST_NODE DT_NODELABEL(interrupt_test)
#define COUNTER_INTR_TEST_NODE DT_PHANDLE(INTERRUPT_TEST_NODE, tcpwm)
#endif

#if defined(CONFIG_POST_MTB_STL_CLOCK)
#include "SelfTest_Clock.h"
#define CLOCK_TEST_NODE DT_NODELABEL(clock_test)
#define COUNTER_CLK_TEST_NODE DT_PHANDLE(CLOCK_TEST_NODE, tcpwm)
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
#endif

#if defined(CONFIG_POST_MTB_STL_PWM)
#include "SelfTest_PWM.h"
#define PWM_TEST_NODE DT_NODELABEL(pwm_test)
#define TCPWM_PWM_TEST_NODE DT_PHANDLE(PWM_TEST_NODE, tcpwm)
#endif

#if defined(CONFIG_POST_MTB_STL_PWM_GATEKILL)
#include "SelfTest_PWM_GateKill.h"
#define PWM_GK_TEST_NODE DT_NODELABEL(pwm_gatekill_test)
#define COUNTER_PWM_GK_TEST_NODE DT_PHANDLE(PWM_GK_TEST_NODE, tcpwm)
#endif

#if defined(CONFIG_POST_MTB_STL_COMM)
#include "SelfTest_CRC_calc.h"
#include "SelfTest_UART_master_message.h"
#include "SelfTest_UART_slave_message.h"
#define UART_COMMUNICATION_TEST_NODE DT_NODELABEL(uart_communication_test)
#define UART_COMM_MASTER_TEST_NODE DT_PHANDLE(UART_COMMUNICATION_TEST_NODE, scb)
#define UART_COMM_SLAVE_TEST_NODE DT_PHANDLE(UART_COMMUNICATION_TEST_NODE, scb_slave)
#define COUNTER_COMM_TEST_NODE DT_PHANDLE(UART_COMMUNICATION_TEST_NODE, tcpwm)
#define CNT_CLOCK_COMM_TEST_NODE DT_PHANDLE(COUNTER_COMM_TEST_NODE, clocks)
#endif

#ifdef CONFIG_POST_MTB_STL_SPI_LOOPBACK
#include "SelfTest_SPI_SCB.h"
#define SPI_TEST_NODE DT_NODELABEL(spi_loopback_test)
#define SPI_LB_TEST_NODE DT_PHANDLE(SPI_TEST_NODE, scb)
#endif

#if defined(CONFIG_POST_MTB_STL_I2C)
#include "SelfTest_I2C_SCB.h"
#define I2C_TEST_NODE DT_NODELABEL(i2c_test)
#define I2C_MASTER_TEST_NODE DT_PHANDLE(I2C_TEST_NODE, scb)
#define I2C_SLAVE_TEST_NODE DT_PHANDLE(I2C_TEST_NODE, scb_slave)
#endif

#ifdef CONFIG_POST_MTB_STL_ANALOG
#include "SelfTest_Analog.h"
#define ANALOG_TEST_NODE DT_NODELABEL(analog_test)
#define ADC_TEST_NODE DT_PHANDLE(ANALOG_TEST_NODE, adc)
#define ADC_CHAN0_NODE DT_CHILD(ADC_TEST_NODE, channel_0)
#endif

#ifdef CONFIG_POST_MTB_STL_COMPARATOR
#include "SelfTest_Analog.h"
#define COMP_TEST_NODE DT_NODELABEL(lpcomp0_0)
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

#if defined(CONFIG_SOC_FAMILY_INFINEON_PSOC4)
#define IFX_TCPWM_CNT_NUM(cnt_node) \
	((DT_REG_ADDR(DT_PARENT(cnt_node)) - \
	  DT_REG_ADDR(DT_PARENT(DT_PARENT(cnt_node))) - 0x100UL) / 0x40UL)
#else
#define IFX_TCPWM_CNT_NUM(cnt_node) \
	((DT_REG_ADDR(DT_PARENT(cnt_node)) - \
	  DT_REG_ADDR(DT_PARENT(DT_PARENT(cnt_node)))) / \
	 DT_REG_SIZE(DT_PARENT(cnt_node)))
#endif

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

static inline void infineon_stl_stop_running_cnt(TCPWM_Type *base,
                                                 uint32_t cntnum) {
#if defined(CY_IP_M0S8TCPWM)
  uint32_t shiftedValue = (uint32_t)1U << cntnum;
  Cy_TCPWM_TriggerStopOrKill(base, shiftedValue);
#else
  Cy_TCPWM_TriggerStopOrKill_Single(base, cntnum);
#endif
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

#endif /* MTB_STL_POST_H */
