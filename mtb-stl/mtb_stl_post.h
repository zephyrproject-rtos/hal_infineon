#ifndef MTB_STL_POST_H
#define MTB_STL_POST_H

/*
 * MTB-STL includes - these come from the vendor library
 */
#if defined(CONFIG_POST_MTB_STL_STARTUP_CFGREG) || \
	defined(CONFIG_POST_MTB_STL_SAVE_STARTUP_CFGREG)
#include "SelfTest_ConfigRegisters.h"
#include "SelfTest_CRC_calc.h"
#endif

#if defined(CONFIG_POST_MTB_STL_CPU_REGS) || \
	defined(CONFIG_POST_MTB_STL_CPU_PC) || \
	defined(CONFIG_POST_MTB_STL_PROGRAM_FLOW)
#include "SelfTest_CPU.h"
#endif

#if defined(CONFIG_POST_MTB_STL_RAM_MARCH) || \
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
#include "SelfTest_DMAC.h"
#endif

#if defined(CONFIG_POST_MTB_STL_INTERRUPT)
#include "SelfTest_Interrupt.h"
#define INTERRUPT_TEST_NODE DT_NODELABEL(interrupt_test)
#define COUNTER_CONFIG_NODE_INTR_TEST DT_PHANDLE(INTERRUPT_TEST_NODE, counter_cfg)
#endif

#if defined(CONFIG_POST_MTB_STL_CLOCK)
#include "SelfTest_Clock.h"
#define CLOCK_TEST_NODE DT_NODELABEL(clock_test)
#define COUNTER_CONFIG_NODE_CLK_TEST DT_PHANDLE(CLOCK_TEST_NODE, counter_cfg)
#endif

#if defined(CONFIG_POST_MTB_STL_UART_LOOPBACK)
#include "SelfTest_UART_SCB.h"
#define UART_TEST_NODE DT_NODELABEL(uart_loopback_test)
#define UART_LP_TEST_NODE DT_PHANDLE(UART_TEST_NODE, uart_scb_cfg)
#define TX_PIN_NODE DT_PHANDLE(UART_LP_TEST_NODE, tx_cfg)
#define RX_PIN_NODE DT_PHANDLE(UART_LP_TEST_NODE, rx_cfg)
#endif

#if defined(CONFIG_POST_MTB_STL_COUNTER)
#include "SelfTest_Timer_Counter.h"
#define COUNTER_TEST_NODE DT_NODELABEL(counter_test)
#define COUNTER_CONFIG_NODE_CNT_TEST DT_PHANDLE(COUNTER_TEST_NODE, counter_cfg)
#endif

#if defined(CONFIG_POST_MTB_STL_PWM_GATEKILL)
#include "SelfTest_PWM_GateKill.h"
#define PWM_GK_TEST_NODE DT_NODELABEL(pwm_gatekill_test)
#define PWM_CONFIG_NODE_GK_TEST DT_PHANDLE(PWM_GK_TEST_NODE, pwm_cfg)
#endif

/*
 * Helper symbols
 */
extern char z_interrupt_stacks[];
extern char z_main_stack[];

/*
 * Helper Macros
 */

/*
 * Stack and Flash
 */
#ifndef CONFIG_MAIN_STACK_SIZE
#define DEVICE_STACK_SIZE    (0x00000400)  /* Default 1KB if not configured */
#else
#define DEVICE_STACK_SIZE    (CONFIG_MAIN_STACK_SIZE)
#endif
#define DEVICE_SRAM_BASE     DT_REG_ADDR(DT_CHOSEN(zephyr_sram))
#define DEVICE_SRAM_SIZE     DT_REG_SIZE(DT_CHOSEN(zephyr_sram))
#define DEVICE_FLASH_BASE    DT_REG_ADDR(DT_CHOSEN(zephyr_flash))
#define DEVICE_FLASH_SIZE    DT_REG_SIZE(DT_CHOSEN(zephyr_flash))
#define DEVICE_STACK_BASE    ((uintptr_t)z_main_stack)

static inline CySCB_Type *mtb_stl_get_scb_base(uint32_t scb_block_num)
{
	switch (scb_block_num) {
	case 0:
		return SCB0;
	case 1:
		return SCB1;
	case 2:
		return SCB2;
	case 3:
		return SCB3;
	case 4:
		return SCB4;
	default:
		return NULL;
	}
}

static inline GPIO_PRT_Type *mtb_stl_get_port_base(uint32_t port_num)
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

#endif /* MTB_STL_POST_H */
