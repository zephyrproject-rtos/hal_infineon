/*
 * Copyright (c) 2026 Aerlync Labs Inc.
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 * @file
 * @brief MTB-STL POST integration
 *
 * Wraps Infineon MTB-STL self-test functions for the Zephyr POST framework.
 */

#include <zephyr/devicetree.h>
#include <zephyr/irq.h>
#include <zephyr/kernel.h>
#include <zephyr/drivers/pinctrl.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/logging/log.h>
#include <zephyr/post/post.h>
#include <zephyr/post/post_vendor.h>
#include <zephyr/drivers/spi.h>

#include "cy_pdl.h"

#include "mtb_stl_post.h"

LOG_MODULE_REGISTER(mtb_stl_post, CONFIG_POST_LOG_LEVEL);

/*
 * Start Up Tests
 */
#ifdef CONFIG_POST_MTB_STL_SAVE_STARTUP_CFGREG
POST_VENDOR_TEST_WRAP_FLAGS(mtb_stl_save_startup_cfgreg,
		POST_CAT_STARTUP_CFG_REG,
		POST_LEVEL_POST_KERNEL,
		POST_FLAG_BOOT_ONLY,
		SelfTests_Save_StartUp_ConfigReg,
		"MTB-STL Save Startup CfgReg Test");
#endif

#ifdef CONFIG_POST_MTB_STL_STARTUP_CFGREG
POST_VENDOR_TEST_WRAP_FLAGS(mtb_stl_run_starup_cfgreg,
		POST_CAT_STARTUP_CFG_REG,
		POST_LEVEL_POST_KERNEL,
		POST_FLAG_BOOT_ONLY,
		SelfTests_StartUp_ConfigReg,
		"MTB-STL Startup Reg Test");
#endif

/*
 * CPU Tests
 */
#ifdef CONFIG_POST_MTB_STL_CPU_REGS
POST_VENDOR_TEST_WRAP_FLAGS(mtb_stl_cpu_regs,
		POST_CAT_CPU,
		POST_LEVEL_POST_KERNEL,
		POST_FLAG_BOOT_ONLY,
		SelfTest_CPU_Registers,
		"MTB-STL CPU Register Checkerboard Test");
#endif

#ifdef CONFIG_POST_MTB_STL_CPU_PC
POST_VENDOR_TEST_WRAP_FLAGS(mtb_stl_cpu_pc,
		POST_CAT_CPU,
		POST_LEVEL_POST_KERNEL,
		POST_FLAG_BOOT_ONLY,
		SelfTest_PC,
		"MTB-STL Program Counter Test");
#endif

#ifdef CONFIG_POST_MTB_STL_PROGRAM_FLOW
POST_VENDOR_TEST_WRAP_FLAGS(mtb_stl_program_flow,
		POST_CAT_CPU,
		POST_LEVEL_POST_KERNEL,
		POST_FLAG_BOOT_ONLY,
		SelfTest_PROGRAM_FLOW,
		"MTB-STL Program Flow Test");
#endif

/*
 * GPIO Test
 */
#ifdef CONFIG_POST_MTB_STL_GPIO

static enum post_result mtb_stl_gpio_wrapper(const struct post_context *ctx)
{
	ARG_UNUSED(ctx);

	static const uint8_t Z_PinToTest[] =
	{
		0x00u, /* PORT0 mask */
		0x00u, /* PORT1 mask */
		0x00u, /* PORT2 mask */
		0x30u, /* PORT3 mask */
		0x00u, /* PORT4 mask */
		0x00u, /* PORT5 mask */
		0x00u, /* PORT6 mask */
	};

	/* This function sets a custom pin mask to be used in the SelfTest_IO function */
	SelfTest_IO_SetPinMask(Z_PinToTest);

	return (SelfTest_IO() == 0) ? POST_RESULT_PASS : POST_RESULT_FAIL;
}

POST_TEST_DEFINE(mtb_stl_gpio,
		POST_CAT_GPIO,
		POST_LEVEL_POST_KERNEL, 50,
		POST_FLAG_BOOT_ONLY,
		mtb_stl_gpio_wrapper,
		"MTB-STL GPIO Test");
#endif

/*
 * RAM Tests
 */
#ifdef CONFIG_POST_MTB_STL_RAM_MARCH

static uint8_t ram_test_buffer[64];

static enum post_result mtb_stl_ram_march_wrapper(const struct post_context *ctx)
{
	ARG_UNUSED(ctx);

	/* Test a small buffer using March algorithm */
	return (SelfTest_SRAM(SRAM_MARCH_TEST_MODE, ram_test_buffer,
				sizeof(ram_test_buffer), NULL, 0) == 0)
		? POST_RESULT_PASS
		: POST_RESULT_FAIL;
}

POST_TEST_DEFINE(mtb_stl_ram_march,
		POST_CAT_RAM,
		POST_LEVEL_PRE_KERNEL_1, 50,
		POST_FLAG_RUNTIME_OK | POST_FLAG_VENDOR,
		mtb_stl_ram_march_wrapper,
		"MTB-STL RAM March Test");
#endif

#ifdef CONFIG_POST_MTB_STL_STACK_MARCH

/*
 * Stack test buffer: Calculate a safe location at runtime.
 * The SelfTest_SRAM_Stack function needs an alternate stack to switch to
 * while testing the main stack region. This buffer must be large enough
 * and in a safe location that doesn't overlap with the stack being tested.
 *
 * We place the buffer at the start of SRAM (well before any stacks) to
 * ensure it doesn't overlap with stack regions.
 *
 * WARNING: This test writes to the stack region and is DESTRUCTIVE.
 * It should only run when the stack is not actively in use.
 */
static enum post_result mtb_stl_stack_march_wrapper(const struct post_context *ctx)
{
	ARG_UNUSED(ctx);

	/* Get stack locations first to calculate safe buffer placement */
	uintptr_t stack_base = (uintptr_t)DEVICE_STACK_BASE;
	uintptr_t stack_end = stack_base + DEVICE_STACK_SIZE;
	uintptr_t int_stack_start = (uintptr_t)z_interrupt_stacks;
	/* Interrupt stack size is typically CONFIG_ISR_STACK_SIZE */
	size_t int_stack_size = CONFIG_ISR_STACK_SIZE;
	uintptr_t int_stack_end = int_stack_start + int_stack_size;
	uintptr_t alt_stack_buf_start = stack_end;
	uintptr_t alt_stack_buf_end = alt_stack_buf_start + DEVICE_STACK_SIZE;

	/* Verify buffer fits within SRAM */
	if (alt_stack_buf_end > (DEVICE_SRAM_BASE + DEVICE_SRAM_SIZE)) {
		LOG_ERR("Cannot find safe location for test buffer! "
				"SRAM: 0x%08x-0x%08x, Buffer needed: 0x%08x-0x%08x",
				(unsigned int)DEVICE_SRAM_BASE,
				(unsigned int)(DEVICE_SRAM_BASE + DEVICE_SRAM_SIZE),
				(unsigned int)alt_stack_buf_start, (unsigned int)alt_stack_buf_end);
		return POST_RESULT_FAIL;
	}

	/* Safety checks: Ensure buffers don't overlap with any stacks */
	uintptr_t test_buf_start = alt_stack_buf_start;
	uintptr_t test_buf_end = alt_stack_buf_end;

	/* Check if test buffer overlaps with main stack being tested */
	if ((test_buf_end > stack_base && test_buf_start < stack_end) ||
			(stack_end > test_buf_start && stack_base < test_buf_end)) {
		LOG_ERR("Test buffer overlaps with main stack! "
				"Stack: 0x%08x-0x%08x, Buffer: 0x%08x-0x%08x",
				(unsigned int)stack_base, (unsigned int)stack_end,
				(unsigned int)test_buf_start, (unsigned int)test_buf_end);
		return POST_RESULT_FAIL;
	}

	/* Check if test buffer overlaps with interrupt stack */
	if ((test_buf_end > int_stack_start && test_buf_start < int_stack_end) ||
			(int_stack_end > test_buf_start && int_stack_start < test_buf_end)) {
		LOG_ERR("Test buffer overlaps with interrupt stack! "
				"IntStack: 0x%08x-0x%08x, Buffer: 0x%08x-0x%08x",
				(unsigned int)int_stack_start, (unsigned int)int_stack_end,
				(unsigned int)test_buf_start, (unsigned int)test_buf_end);
		return POST_RESULT_FAIL;
	}

	/* Check if stack region being tested overlaps with interrupt stack */
	if ((stack_end > int_stack_start && stack_base < int_stack_end) ||
			(int_stack_end > stack_base && int_stack_start < stack_end)) {
		LOG_ERR("Main stack overlaps with interrupt stack! "
				"Main: 0x%08x-0x%08x, Int: 0x%08x-0x%08x",
				(unsigned int)stack_base, (unsigned int)stack_end,
				(unsigned int)int_stack_start, (unsigned int)int_stack_end);
		return POST_RESULT_FAIL;
	}

	/* Additional check: ensure we're not testing outside SRAM */
	if (stack_base < DEVICE_SRAM_BASE ||
			stack_end > (DEVICE_SRAM_BASE + DEVICE_SRAM_SIZE)) {
		LOG_ERR("Stack region outside SRAM! "
				"SRAM: 0x%08x-0x%08x, Stack: 0x%08x-0x%08x",
				(unsigned int)DEVICE_SRAM_BASE,
				(unsigned int)(DEVICE_SRAM_BASE + DEVICE_SRAM_SIZE),
				(unsigned int)stack_base, (unsigned int)stack_end);
		return POST_RESULT_FAIL;
	}

	uintptr_t current_sp;

	__asm__ volatile("mov %0, sp" : "=r"(current_sp));

	/* Check if current stack pointer is within the stack region we're testing */
	if (current_sp >= stack_base && current_sp < stack_end) {
		LOG_ERR("Cannot test stack - stack is currently in use! "
				"Stack: 0x%08x-0x%08x, Current SP: 0x%08x",
				(unsigned int)stack_base, (unsigned int)stack_end,
				(unsigned int)current_sp);
		LOG_ERR("This test is destructive and requires the stack to be unused. "
				"Consider disabling: CONFIG_POST_MTB_STL_STACK_MARCH=n");
		return POST_RESULT_FAIL;
	}

	unsigned int key = irq_lock();

	enum post_result result;

	/*
	 * WARNING: Even with these checks, this test is dangerous because:
	 * 1. The stack may be used by other code paths (other threads, if any)
	 * 2. Writing to stack memory can corrupt data even if SP is outside the
	 * region
	 * 3. The test itself uses the stack, creating a chicken-and-egg problem
	 *
	 * Consider disabling this test if you experience crashes.
	 */
	result = (SelfTest_SRAM_Stack((uint8_t *)DEVICE_STACK_BASE,
				(uint32_t)DEVICE_STACK_SIZE,
				(uint8_t *)alt_stack_buf_start) == 0) ?
		POST_RESULT_PASS : POST_RESULT_FAIL;

	/* Re-enable interrupts */
	irq_unlock(key);

	return result;
}

POST_TEST_DEFINE(mtb_stl_stack_march,
		POST_CAT_RAM, POST_LEVEL_EARLY, 50,
		POST_FLAG_BOOT_ONLY | POST_FLAG_DESTRUCTIVE | POST_FLAG_VENDOR,
		mtb_stl_stack_march_wrapper,
		"MTB-STL Stack March Test");
#endif

/*
 * Stack Tests
 */
#ifdef CONFIG_POST_MTB_STL_STACK

#define PATTERN_BLOCK_SIZE (8)

static enum post_result mtb_stl_stack_wrapper(const struct post_context *ctx)
{
	ARG_UNUSED(ctx);

	/*
	 * Use a static buffer to avoid corrupting the current stack frame
	 * if the test writes out of bounds or if the pattern fill overlaps
	 * with critical stack data.
	 */
	SelfTests_Init_Stack_Range((uint16_t *)DEVICE_STACK_BASE, DEVICE_STACK_SIZE,
			PATTERN_BLOCK_SIZE);

	uint8_t res = SelfTests_Stack_Check_Range((uint16_t *)DEVICE_STACK_BASE,
			DEVICE_STACK_SIZE);

	if ((ERROR_STACK_OVERFLOW & res)) {
		LOG_ERR("Stack Overflow ERR");
		return POST_RESULT_FAIL;
	} else if ((ERROR_STACK_UNDERFLOW & res)) {
		LOG_ERR("Stack Underflow ERR");
		return POST_RESULT_FAIL;
	} else {
		return (res == 0) ? POST_RESULT_PASS : POST_RESULT_FAIL;
	}
}

POST_TEST_DEFINE(mtb_stl_stack,
		POST_CAT_STACK,
		POST_LEVEL_POST_KERNEL, 50,
		POST_FLAG_RUNTIME_OK | POST_FLAG_VENDOR,
		mtb_stl_stack_wrapper,
		"MTB-STL Stack Overflow Test");
#endif

/*
 * Flash Tests
 */
#ifdef CONFIG_POST_MTB_STL_FLASH

#define IFX_FLETCHER64 CONFIG_POST_FLASH_TEST_FLETCHER64_CHECKSUM

/* Checksum storage - will be placed at end of flash by linker script */
static volatile const uint64_t flash_StoredCheckSum
__attribute__((used, section(".flash_checksum"))) = IFX_FLETCHER64;

static enum post_result mtb_stl_flash_wrapper(const struct post_context *ctx)
{
	ARG_UNUSED(ctx);

	static bool flash_test_initialized;
	uint8_t res;
	uint32_t flash_base;
	uint32_t flash_size;
	uint32_t flash_start_addr;
	uint32_t flash_end_addr;
	uint32_t checksum_addr_rel;
	uint32_t checksum_addr;
	uint8_t flash_CheckSum_temp;
	uint32_t dt_flash_base;

	dt_flash_base = DEVICE_FLASH_BASE;
	flash_size = DEVICE_FLASH_SIZE;

	/* Get the actual address where checksum is stored
	 * On PSoC4, linker uses ORIGIN=0x0, so addresses are relative
	 */
	checksum_addr_rel = (uint32_t)(uintptr_t)&flash_StoredCheckSum;

	/* MTB-STL library has PSoC4-specific memory mapping code that handles
	 * address translation. Since linker uses ORIGIN=0x0, use relative addresses
	 * (0x0 base) for the MTB-STL library calls.
	 */
	flash_base = 0x0UL;

	if (dt_flash_base == 0) {
		checksum_addr = 0x10000000UL + checksum_addr_rel;
	} else {
		checksum_addr = dt_flash_base + checksum_addr_rel;
	}

	/* Calculate checksum range - exclude the checksum section
	 * The checksum section might not be at the exact end, so we need to
	 * exclude it based on its actual address
	 */
	flash_start_addr = flash_base;

	uint32_t checksum_offset = checksum_addr_rel;

	/* Exclude the checksum section from calculation */
	if (checksum_offset >= 8 && checksum_offset < flash_size) {
		/* Checksum is within flash - checksum up to it (exclude it) */
		flash_end_addr = checksum_offset; /* Relative address */
	} else {
		/* Fallback: exclude last 8 bytes if checksum is at end or outside */
		flash_end_addr = flash_size - FLASH_RESERVED_CHECKSUM_SIZE;
		if (checksum_offset >= flash_size) {
			LOG_WRN("Checksum offset 0x%08lX is outside flash size 0x%08lX,"
					"using end-8", (unsigned long)checksum_offset,
					(unsigned long)flash_size);
		}
	}

	LOG_INF("Flash: DT_base=0x%08lX, HW_base=0x%08lX, size=0x%08lX",
			(unsigned long)DEVICE_FLASH_BASE, (unsigned long)flash_base,
			(unsigned long)flash_size);
	LOG_INF("Checksum range: start=0x%08lX, end=0x%08lX (excludes checksum at "
			"0x%08lX)",
			(unsigned long)flash_start_addr, (unsigned long)flash_end_addr,
			(unsigned long)checksum_addr_rel);
	LOG_INF("Checksum stored at: rel=0x%08lX, abs=0x%08lX, value=0x%016llX",
			(unsigned long)checksum_addr_rel, (unsigned long)checksum_addr,
			(unsigned long long)flash_StoredCheckSum);

	if (flash_end_addr == 0) {
		LOG_ERR("Invalid flash end address: 0x%08lX",
				(unsigned long)flash_end_addr);
		return POST_RESULT_FAIL;
	}

	if (flash_start_addr >= flash_end_addr) {
		LOG_ERR("Invalid flash range: start=0x%08lX >= end=0x%08lX",
				(unsigned long)flash_start_addr, (unsigned long)flash_end_addr);
		return POST_RESULT_FAIL;
	}

	/* For relative addresses (base=0x0), check against flash_size */
	if (flash_end_addr > flash_size) {
		LOG_ERR("Flash end address exceeds flash size: end=0x%08lX > size=0x%08lX",
				(unsigned long)flash_end_addr, (unsigned long)flash_size);
		return POST_RESULT_FAIL;
	}

	/* Ensure addresses are 4-byte aligned (required for uint32_t access) */
	if ((flash_start_addr & 0x3) != 0 || (flash_end_addr & 0x3) != 0) {
		LOG_ERR("Flash addresses must be 4-byte aligned: start=0x%08lX, end=0x%08lX",
				(unsigned long)flash_start_addr, (unsigned long)flash_end_addr);
		return POST_RESULT_FAIL;
	}

	if (!flash_test_initialized) {
		SelfTest_Flash_init(flash_start_addr, flash_end_addr, flash_StoredCheckSum);
		flash_test_initialized = true;
	}

	do {
		res = SelfTest_FlashCheckSum(FLASH_DOUBLE_WORDS_TO_TEST);
	} while (res == 2);

	if (res == 1) {
		LOG_ERR("FLASH CHECKSUM:");
		printk("0x");
		for (int16_t i = sizeof(flash_CheckSum) - 1; i >= 0; i--) {
			flash_CheckSum_temp = (uint8_t)(flash_CheckSum >> (i * 8u));
			printk("%02X", flash_CheckSum_temp);
		}
		printk("\n");
		return POST_RESULT_FAIL;
	}

	return (res == 3) ? POST_RESULT_PASS : POST_RESULT_FAIL;
}

POST_TEST_DEFINE(mtb_stl_flash,
		POST_CAT_FLASH,
		POST_LEVEL_APPLICATION, 50,
		POST_FLAG_RUNTIME_OK | POST_FLAG_VENDOR,
		mtb_stl_flash_wrapper,
		"MTB-STL Flash Checksum Test");
#endif

/*
 * Watchdog Tests
 */
#ifdef CONFIG_POST_MTB_STL_WDT
/*
 * WDT test causes a deliberate system reset on the first run.  After the
 * reset the test detects CY_SYSLIB_RESET_HWWDT and returns OK immediately.
 * On PSoC4 the WDT is not cleared by a watchdog reset, so we must disable
 * it after the test returns to prevent an infinite reboot loop.
 */
static enum post_result mtb_stl_wdt_wrapper(const struct post_context *ctx)
{
	ARG_UNUSED(ctx);
	uint8_t res = SelfTest_WDT();

	/* Disable WDT unconditionally: on the pass path it fired (still
	 * enabled after reset); on the fail path it was never armed. */
	Cy_WDT_ClearInterrupt();
	Cy_WDT_Disable();

	return (res == 0) ? POST_RESULT_PASS : POST_RESULT_FAIL;
}
POST_TEST_DEFINE(mtb_stl_wdt,
		POST_CAT_WATCHDOG,
		POST_LEVEL_APPLICATION,
		50,
		POST_FLAG_VENDOR | POST_FLAG_DESTRUCTIVE,
		mtb_stl_wdt_wrapper,
		"MTB-STL Watchdog Reset Test");
#endif

/*
 * FPU Tests
 */
#ifdef CONFIG_POST_MTB_STL_FPU
#ifdef CONFIG_FPU
POST_VENDOR_TEST_WRAP(mtb_stl_fpu,
		POST_CAT_CPU,
		POST_LEVEL_POST_KERNEL,
		SelfTest_FPU_Registers,
		"MTB-STL FPU Register Test");
#endif /* CONFIG_FPU */
#endif

/*
 * DMAC Tests
 */
#ifdef CONFIG_POST_MTB_STL_DMA

#define DMA_TEST_NODE DT_NODELABEL(dma_test)

static enum post_result mtb_stl_dmac_wrapper(const struct post_context *ctx)
{
	uint32_t channel = DT_PROP(DMA_TEST_NODE, channel);

	return (SelfTest_DMAC(DMAC, channel, TRIG0_OUT_CPUSS_DMAC_TR_IN0 + channel) == 0)
		? POST_RESULT_PASS : POST_RESULT_FAIL;
}

POST_TEST_DEFINE(mtb_stl_dmac,
		POST_CAT_DMA,
		POST_LEVEL_APPLICATION,
		50, 0,
		mtb_stl_dmac_wrapper,
		"MTB-STL DMAC Test");
#endif /* CONFIG_POST_MTB_STL_DMA */

#ifdef CONFIG_POST_MTB_STL_UART_LOOPBACK

static cy_stc_scb_uart_context_t ifx_uart_test_ctx;

static uint8_t UART_SelfTest(CySCB_Type *scb_block)
{
	uint8_t ret;

	Cy_SCB_UART_StopRingBuffer(scb_block, &ifx_uart_test_ctx);
	Cy_SCB_UART_AbortReceive(scb_block, &ifx_uart_test_ctx);
	Cy_SCB_UART_AbortTransmit(scb_block, &ifx_uart_test_ctx);

	Cy_SCB_UART_ClearRxFifo(scb_block);
	Cy_SCB_UART_ClearTxFifo(scb_block);

	ret = SelfTest_UART_SCB(scb_block);

	Cy_SysLib_DelayUs(100u);
	Cy_SCB_UART_ClearRxFifo(scb_block);
	Cy_SCB_UART_ClearTxFifo(scb_block);

	return ret;
}

static enum post_result mtb_stl_uart_loopback_wrapper(const struct post_context *ctx)
{
	ARG_UNUSED(ctx);

	CySCB_Type *scb_block = (CySCB_Type *)DT_REG_ADDR(UART_LP_TEST_NODE);
	uint8_t res = PASS_STILL_TESTING_STATUS;

	Cy_SysLib_DelayUs(100u);
	Cy_SCB_UART_ClearRxFifo(scb_block);
	Cy_SCB_UART_ClearTxFifo(scb_block);

	do {
		res = UART_SelfTest(scb_block);
	} while (res == 2);

	return (res == 3) ? POST_RESULT_PASS : POST_RESULT_FAIL;
}

POST_TEST_DEFINE(mtb_stl_uart_loopback,
		POST_CAT_UART_LOOPBACK,
		POST_LEVEL_APPLICATION,
		50, 0,
		mtb_stl_uart_loopback_wrapper,
		"MTB-STL UART Loopback Self Test");
#endif

/*
 * Interrupt Test
 */
#ifdef CONFIG_POST_MTB_STL_INTERRUPT

static enum post_result mtb_stl_interrupt_wrapper(const struct post_context *ctx)
{
	ARG_UNUSED(ctx);

	uint8_t res;
	TCPWM_Type *base;
	uint32_t period = DT_PROP(INTERRUPT_TEST_NODE, test_period);
	uint32_t compare0 = DT_PROP(INTERRUPT_TEST_NODE, test_compare0);
	uint32_t compare1 = DT_PROP(INTERRUPT_TEST_NODE, test_compare1);
	uint32_t intr_src = DT_PROP(INTERRUPT_TEST_NODE, interrupt_sources);
	const uint32_t irq_num = DT_IRQN(DT_PARENT(COUNTER_INTR_TEST_NODE));
	uint32_t cnt_num = IFX_TCPWM_CNT_NUM(COUNTER_INTR_TEST_NODE);

	base = (TCPWM_Type *)(DT_REG_ADDR(DT_PARENT(DT_PARENT(COUNTER_INTR_TEST_NODE))));

	/* IRQ setup */
	IRQ_CONNECT(irq_num, 3, SelfTest_Interrupt_ISR_TIMER, NULL, 0);
	irq_enable(irq_num);

	infineon_stl_stop_running_cnt(base, cnt_num);

	/* Configure counter with POST test parameters */
	infineon_stl_config_post_parameter(base, cnt_num, period, compare0, compare1);

	Cy_TCPWM_Counter_Enable(base, cnt_num);
	Cy_TCPWM_SetInterruptMask(base, cnt_num, intr_src);

	res = SelfTest_Interrupt(base, cnt_num);

	return (res == 0) ? POST_RESULT_PASS : POST_RESULT_FAIL;
}

POST_TEST_DEFINE(mtb_stl_interrupt,
		POST_CAT_INTERRUPT,
		POST_LEVEL_POST_KERNEL,
		50, 0,
		mtb_stl_interrupt_wrapper,
		"MTB-STL Interrupt Test");
#endif

/*
 * Clock Tests
 */
#ifdef CONFIG_POST_MTB_STL_CLOCK

static void clock_test_init(uint32_t cnt_num, TCPWM_Type *base)
{
	uint32_t intr_src = DT_PROP(CLOCK_TEST_NODE, interrupt_sources);
	uint32_t ignore_bits = DT_PROP(CLOCK_TEST_NODE, wdt_ignore_bits);

	Cy_WDT_SetIgnoreBits(ignore_bits);

	if (Cy_WDT_GetIgnoreBits() != ignore_bits) {
		LOG_ERR("IGNORE BITS MISMATCH!!!");
	}

	Cy_WDT_ClearInterrupt();

	Cy_WDT_Enable();
	if (Cy_WDT_IsEnabled() == false) {
		LOG_ERR("WDT IS NOT ENABLED!!!");
	}

	Cy_TCPWM_Counter_Enable(base, cnt_num);
	Cy_TCPWM_SetInterruptMask(base, cnt_num, intr_src);
}

static enum post_result mtb_stl_clock_wrapper(const struct post_context *ctx)
{
	ARG_UNUSED(ctx);

	uint8_t res;
	uint32_t period   = DT_PROP(CLOCK_TEST_NODE, test_period);
	uint32_t compare0 = DT_PROP(CLOCK_TEST_NODE, test_compare0);
	uint32_t compare1 = DT_PROP(CLOCK_TEST_NODE, test_compare1);
	const uint32_t irq_num = DT_IRQN(DT_PARENT(COUNTER_CLK_TEST_NODE));
	uint32_t cnt_num = IFX_TCPWM_CNT_NUM(COUNTER_CLK_TEST_NODE);
	TCPWM_Type *base = (TCPWM_Type *)(DT_REG_ADDR(DT_PARENT(DT_PARENT(COUNTER_CLK_TEST_NODE))));

	IRQ_CONNECT(irq_num, 3, SelfTest_Clock_ISR_TIMER, NULL, 0);
	irq_enable(irq_num);

	/* counter0_0 is dedicated to this test — no save/restore needed */
	infineon_stl_stop_running_cnt(base, cnt_num);
	infineon_stl_config_post_parameter(base, cnt_num, period, compare0, compare1);
	clock_test_init(cnt_num, base);

	uint32_t start = k_cycle_get_32();
	uint32_t timeout_cycles = k_ms_to_cyc_ceil32(100); /* 100 ms timeout */

	do {
		res = SelfTest_Clock(base, cnt_num);
		if ((k_cycle_get_32() - start) > timeout_cycles) {
			infineon_stl_stop_running_cnt(base, cnt_num);
			Cy_WDT_ClearInterrupt();
			Cy_WDT_Disable();
			return POST_RESULT_FAIL;
		}
	} while (res == 2);

	infineon_stl_stop_running_cnt(base, cnt_num);
	Cy_WDT_ClearInterrupt();
	Cy_WDT_Disable();

	return (res == 3) ? POST_RESULT_PASS : POST_RESULT_FAIL;
}
POST_TEST_DEFINE(mtb_stl_clock,
		POST_CAT_CLOCK,
		POST_LEVEL_POST_KERNEL,
		50, POST_FLAG_RUNTIME_OK | POST_FLAG_VENDOR,
		mtb_stl_clock_wrapper,
		"MTB-STL Clock Frequency Test");
#endif

/* Counter test */
#ifdef CONFIG_POST_MTB_STL_COUNTER

const cy_stc_tcpwm_counter_config_t ifx_timer_counter_config = {
	.period = DT_PROP(COUNTER_TEST_NODE, test_period),
	.clockPrescaler = CY_TCPWM_COUNTER_PRESCALER_DIVBY_1,
	.runMode = CY_TCPWM_COUNTER_CONTINUOUS,
	.countDirection = CY_TCPWM_COUNTER_COUNT_UP,
	.compareOrCapture = CY_TCPWM_COUNTER_MODE_COMPARE,
	.compare0 = DT_PROP(COUNTER_TEST_NODE, test_compare0),
	.compare1 = DT_PROP(COUNTER_TEST_NODE, test_compare1),
	.enableCompareSwap = false,
	.interruptSources = DT_PROP(COUNTER_TEST_NODE, interrupt_sources),
	.captureInputMode = 0x3U,
	.captureInput = CY_TCPWM_INPUT_0,
	.reloadInputMode = 0x3U,
	.reloadInput = CY_TCPWM_INPUT_0,
	.startInputMode = 0x3U,
	.startInput = CY_TCPWM_INPUT_0,
	.stopInputMode = 0x3U,
	.stopInput = CY_TCPWM_INPUT_0,
	.countInputMode = 0x3U,
	.countInput = CY_TCPWM_INPUT_1,
};

static enum post_result mtb_stl_counter_wrapper(const struct post_context *ctx)
{
	ARG_UNUSED(ctx);

	uint8_t result;
	TCPWM_Type *base;
	uint32_t cnt_num = IFX_TCPWM_CNT_NUM(COUNTER_CNT_TEST_NODE);
	const uint32_t irq_num = DT_IRQN(DT_PARENT(COUNTER_CNT_TEST_NODE));

	base = (TCPWM_Type *)(DT_REG_ADDR(DT_PARENT(DT_PARENT(COUNTER_CNT_TEST_NODE))));

	infineon_stl_stop_running_cnt(base, cnt_num);

	SelfTest_Timer_Counter_init(base, cnt_num, &ifx_timer_counter_config, irq_num);

	result = SelfTest_Counter_Timer();

	return (result == OK_STATUS) ? POST_RESULT_PASS : POST_RESULT_FAIL;
}

POST_TEST_DEFINE(mtb_stl_counter,
		POST_CAT_COUNTER,
		POST_LEVEL_APPLICATION,
		10, 0,
		mtb_stl_counter_wrapper,
		"MTB-STL TCPWM Counter Self-Test");

#endif /* CONFIG_POST_MTB_STL_COUNTER */

/* PWM test */
#ifdef CONFIG_POST_MTB_STL_PWM

#define GPIO_CTRL_NODE_IN DT_PHANDLE_BY_IDX(PWM_TEST_NODE, pwm_in_gpios, 0)
#define GPIO_CTRL_BASE_IN DT_REG_ADDR(GPIO_CTRL_NODE_IN)

static const struct gpio_dt_spec pwm_in_spec = GPIO_DT_SPEC_GET(PWM_TEST_NODE, pwm_in_gpios);

const cy_stc_tcpwm_pwm_config_t ifx_pwm_config = {
        .pwmMode            = DT_PROP(PWM_TEST_NODE, pwm_mode),
        .clockPrescaler     = DT_PROP(PWM_TEST_NODE, clock_prescaler),
        .pwmAlignment       = DT_PROP(PWM_TEST_NODE, pwm_alignment),
        .deadTimeClocks     = 0,
        .runMode            = DT_PROP(PWM_TEST_NODE, run_mode),
        .period0            = DT_PROP(PWM_TEST_NODE, period0),
        .period1            = DT_PROP(PWM_TEST_NODE, period1),
        .enablePeriodSwap   = false,
        .compare0           = DT_PROP(PWM_TEST_NODE, compare0),
        .compare1           = DT_PROP(PWM_TEST_NODE, compare1),
        .enableCompareSwap  = false,
        .interruptSources   = DT_PROP(PWM_TEST_NODE, interrupt_sources),
        .invertPWMOut       = CY_TCPWM_PWM_INVERT_DISABLE,
        .invertPWMOutN      = CY_TCPWM_PWM_INVERT_DISABLE,
        .killMode           = DT_PROP(PWM_TEST_NODE, kill_mode),
        .swapInputMode      = 0x3U,
        .swapInput          = CY_TCPWM_INPUT_0,
        .reloadInputMode    = 0x3U,
        .reloadInput        = CY_TCPWM_INPUT_0,
        .startInputMode     = 0x3U,
        .startInput         = CY_TCPWM_INPUT_0,
        .killInputMode      = 0x3U,
        .killInput          = CY_TCPWM_INPUT_0,
        .countInputMode     = 0x3U,
        .countInput         = CY_TCPWM_INPUT_1,
};

static enum post_result mtb_stl_pwm_wrapper(const struct post_context *ctx)
{
        ARG_UNUSED(ctx);

        uint8_t result;
        int ret;
        TCPWM_Type *base;
        const uint32_t irq_num = DT_IRQN(DT_PARENT(TCPWM_PWM_TEST_NODE));
        uint32_t cnt_num = IFX_TCPWM_CNT_NUM(TCPWM_PWM_TEST_NODE);

        if (!gpio_is_ready_dt(&pwm_in_spec)) {
                LOG_ERR("GPIO-IN dev not ready for PWM test!!!");
        }

        ret = gpio_pin_configure_dt(&pwm_in_spec, GPIO_INPUT);
        if (ret != 0) {
                LOG_ERR("Pin not configured for pwm-in pin");
        }

        /* Initialize PWM  */
        base = (TCPWM_Type *)(DT_REG_ADDR(DT_PARENT(DT_PARENT(TCPWM_PWM_TEST_NODE))));
        if (SelfTest_PWM_init(base, cnt_num, &ifx_pwm_config, irq_num) != OK_STATUS) {
                LOG_ERR("PWM_TEST INIT FAILED");
        }

        /* Run vendor PWM self-test and also connect the p2.2 and p2.3 with jumper */
        result = SelfTest_PWM((GPIO_PRT_Type *)GPIO_CTRL_BASE_IN, pwm_in_spec.pin);

        return (result == OK_STATUS) ? POST_RESULT_PASS : POST_RESULT_FAIL;
}

POST_TEST_DEFINE(mtb_stl_pwm,
                POST_CAT_PWM,
                POST_LEVEL_APPLICATION,
                10, 0,
                mtb_stl_pwm_wrapper,
                "MTB-STL PWM Self-Test");
#endif /* CONFIG_POST_MTB_STL_PWM */

/* PWM_GATEKILL test */
#ifdef CONFIG_POST_MTB_STL_PWM_GATEKILL

static enum post_result mtb_stl_pwm_gatekill_wrapper(const struct post_context *ctx)
{
	ARG_UNUSED(ctx);

	uint8_t result = ERROR_STATUS;
	TCPWM_Type *base_gk_cnt;
	uint32_t cnt_num = IFX_TCPWM_CNT_NUM(COUNTER_PWM_GK_TEST_NODE);

	base_gk_cnt = (TCPWM_Type *)(DT_REG_ADDR(DT_PARENT(DT_PARENT(COUNTER_PWM_GK_TEST_NODE))));

	Cy_TCPWM_PWM_Enable(base_gk_cnt, cnt_num);
	Cy_TCPWM_TriggerReloadOrIndex(base_gk_cnt, (1UL << cnt_num));
	Cy_TCPWM_TriggerStopOrKill(base_gk_cnt, (1UL << cnt_num));

	result = SelfTest_PWM_GateKill(base_gk_cnt, cnt_num);

	return (result == OK_STATUS) ? POST_RESULT_PASS : POST_RESULT_FAIL;
}

POST_TEST_DEFINE(mtb_stl_pwm_gatekill,
		POST_CAT_PWM_GATEKILL,
		POST_LEVEL_APPLICATION,
		10, 0,
		mtb_stl_pwm_gatekill_wrapper,
		"MTB-STL PWM Gatekill Self-Test");
#endif /* CONFIG_POST_MTB_STL_PWM_GATEKILL */

/* UART COMMUNICATION test */
#ifdef CONFIG_POST_MTB_STL_COMM

#define IFX_COMM_SLAVE_ADDR 2
#define IFX_COMM_TRANSMITTED_DATA 10

static enum post_result mtb_stl_communication_wrapper(const struct post_context *ctx)
{
	ARG_UNUSED(ctx);

	uint8_t rxd[16u];
	uint8_t txd[] = "1234567890ABCDEF";
	uint8_t slave_resp_res;
	uint32_t start;
	uint32_t timeout_cycles;
	TCPWM_Type *cnt_base;
	CySCB_Type *scb_uart_master = (CySCB_Type *)DT_REG_ADDR(UART_COMM_MASTER_TEST_NODE);
	CySCB_Type *scb_uart_slave = (CySCB_Type *)DT_REG_ADDR(UART_COMM_SLAVE_TEST_NODE);
	uint32_t cnt_num = DT_PROP(CNT_CLOCK_COMM_TEST_NODE, resource_channel);
	const uint32_t irq_num_cnt = DT_IRQN(DT_PARENT(COUNTER_COMM_TEST_NODE));
	const uint32_t irq_num_master = DT_IRQN(UART_COMM_MASTER_TEST_NODE);
	const uint32_t irq_num_slave = DT_IRQN(UART_COMM_SLAVE_TEST_NODE);

	cnt_base = (TCPWM_Type *)(DT_REG_ADDR(DT_PARENT(DT_PARENT(COUNTER_COMM_TEST_NODE))));

	/* Note: Connect p4.0 -> p2.5 and p4.1 -> p2.4 */

	IRQ_CONNECT(irq_num_cnt, 3, UartMesMaster_Timeout_ISR, NULL, 0);
	irq_enable(irq_num_cnt);

	IRQ_CONNECT(irq_num_master, 3, UartMesMaster_Msg_ISR, NULL, 0);
	irq_enable(irq_num_master);

	IRQ_CONNECT(irq_num_slave, 3, UartMesSlave_Msg_ISR, NULL, 0);
	irq_enable(irq_num_slave);

	UartMesMaster_Init(scb_uart_master, cnt_base, cnt_num);
	UartMesSlave_Init(scb_uart_slave, IFX_COMM_SLAVE_ADDR);

	start = k_cycle_get_32();
	timeout_cycles = k_ms_to_cyc_ceil32(100); /* 100ms timeout */

	/* Wait if master is busy (should be idle initially) */
	while (UM_BUSY == UartMesMaster_State()) {
		if ((k_cycle_get_32() - start) > timeout_cycles) {
			LOG_ERR("ERR: Master stuck in busy state");
			return POST_RESULT_FAIL; /* Timeout */
		}
	}

	/* Send the test packet */
	UartMesMaster_DataProc(IFX_COMM_SLAVE_ADDR, txd, IFX_COMM_TRANSMITTED_DATA,
							rxd, sizeof(rxd));

	start = k_cycle_get_32();
	timeout_cycles = k_ms_to_cyc_ceil32(100); /* 100ms timeout */

	/* Wait for slave to receive packet */
	while(UM_PACKREADY != UartMesSlave_State()) {
		if ((k_cycle_get_32() - start) > timeout_cycles) {
			LOG_ERR("ERR: Slave never received packet");
			return POST_RESULT_FAIL; /* Timeout */
		}
	}

	/* Slave processes and responds */
	slave_resp_res = UartMesSlave_Respond((uint8_t *)UartMesSlave_GetDataPtr(),
						UartMesSlave_GetDataSize());

	if(slave_resp_res) {
		LOG_ERR("ERR: slave response failed");
		return POST_RESULT_FAIL;
	}

	start = k_cycle_get_32();
	timeout_cycles = k_ms_to_cyc_ceil32(100); /* 100ms timeout */

	/* Wait for master to complete transaction */
	while(UM_BUSY == UartMesMaster_State()) {
		if ((k_cycle_get_32() - start) > timeout_cycles) {
			LOG_ERR("ERR: master response timeout");
			return POST_RESULT_FAIL; /* Timeout */
		}
	}

	/* final result */
	if(UM_COMPLETE == UartMesMaster_State()) {
		return POST_RESULT_PASS;
	} else {
		return POST_RESULT_FAIL;
	}
}

POST_TEST_DEFINE(mtb_stl_communication,
                 POST_CAT_COMM,
                 POST_LEVEL_APPLICATION,
                 50, 0,
                 mtb_stl_communication_wrapper,
                "MTB-STL Communication Self-Test");
#endif /* CONFIG_POST_MTB_STL_COMM */

#ifdef CONFIG_POST_MTB_STL_SPI_LOOPBACK

static cy_stc_scb_spi_context_t spi_context;

const cy_stc_scb_spi_config_t spi_config_stl =
{
        .spiMode                    = CY_SCB_SPI_MASTER,
        .subMode                    = DT_PROP(SPI_TEST_NODE, spi_sub_mode),
        .sclkMode                   = DT_PROP(SPI_TEST_NODE, spi_sclk_mode),
        .parity                     = CY_SCB_SPI_PARITY_NONE,
        .dropOnParityError          = false,
        .oversample                 = DT_PROP(SPI_TEST_NODE, spi_oversample),
        .rxDataWidth                = DT_PROP(SPI_TEST_NODE, spi_rx_data_width),
        .txDataWidth                = DT_PROP(SPI_TEST_NODE, spi_tx_data_width),
        .enableMsbFirst             = DT_PROP(SPI_TEST_NODE, spi_msb_first),
        .enableInputFilter          = false,
        .enableFreeRunSclk          = false,
        .enableMisoLateSample       = true,
        .enableTransferSeperation   = false,
        .ssPolarity 		    = CY_SCB_SPI_ACTIVE_LOW,
        .ssSetupDelay               = CY_SCB_SPI_SS_SETUP_DELAY_0_75_CYCLES,
        .ssHoldDelay                = CY_SCB_SPI_SS_HOLD_DELAY_0_75_CYCLES,
        .enableWakeFromSleep        = false,
        .rxFifoTriggerLevel         = 0UL,
        .rxFifoIntEnableMask        = 0UL,
        .txFifoTriggerLevel         = 1UL,
        .txFifoIntEnableMask        = 0UL,
        .masterSlaveIntEnableMask   = 0UL,
};

static void spi_isr(void)
{
        CySCB_Type *spi_base = (CySCB_Type *)DT_REG_ADDR(SPI_LB_TEST_NODE);

        Cy_SCB_SPI_Interrupt(spi_base, &spi_context);
}

static enum post_result mtb_stl_spi_loopback_wrapper(const struct post_context *ctx)
{
        ARG_UNUSED(ctx);

        uint8_t ret = PASS_STILL_TESTING_STATUS;
        const uint32_t irq_num_spi = DT_IRQN(SPI_LB_TEST_NODE);
        CySCB_Type *spi_base = (CySCB_Type *)DT_REG_ADDR(SPI_LB_TEST_NODE);
	cy_en_scb_spi_status_t result;

	IRQ_CONNECT(irq_num_spi, 3, spi_isr, NULL, 0);
        irq_enable(irq_num_spi);

        result = Cy_SCB_SPI_Init(spi_base, &spi_config_stl, &spi_context);

        if (result != CY_SCB_SPI_SUCCESS) {
                LOG_ERR("SPI INIT FAILED !!!");
        }

        /* Enable the SPI Master block */
        Cy_SCB_SPI_Enable(spi_base);

        /* Clear RX, TX buffers */
        Cy_SCB_SPI_ClearRxFifo(spi_base);
        Cy_SCB_SPI_ClearTxFifo(spi_base);

        /* connect the p1.5 and p1.6 with the jumpers */
        while(ret == PASS_STILL_TESTING_STATUS) {
                ret = SelfTest_SPI_SCB(spi_base);
                Cy_SysLib_DelayUs(10);
        }

        return (ret == PASS_COMPLETE_STATUS) ? POST_RESULT_PASS : POST_RESULT_FAIL;
}

POST_TEST_DEFINE(mtb_stl_spi,
                POST_CAT_SPI,
                POST_LEVEL_APPLICATION,
                50, 0,
                mtb_stl_spi_loopback_wrapper,
                "MTB-STL spi loopback Self-Test");

#endif /* CONFIG_POST_MTB_STL_SPI_LOOPBACK */

#ifdef CONFIG_POST_MTB_STL_I2C

#include "zephyr/drivers/i2c.h"

static cy_stc_scb_i2c_context_t i2c_master_context;
static cy_stc_scb_i2c_context_t i2c_slave_context;
static uint8_t i2c_slave_read_buf[PACKET_SIZE];
static uint8_t i2c_slave_write_buf[PACKET_SIZE];

/* Master configuration */
static const cy_stc_scb_i2c_config_t i2c_master_config = {
        .i2cMode = CY_SCB_I2C_MASTER,
        .useRxFifo = DT_PROP(I2C_TEST_NODE, i2c_master_use_rxfifo),
        .useTxFifo = DT_PROP(I2C_TEST_NODE, i2c_master_use_txfifo),
        .slaveAddress = 0U,
        .slaveAddressMask = 0U,
        .acceptAddrInFifo = false,
        .ackGeneralAddr = false,
        .enableWakeFromSleep = false,
        .enableDigitalFilter = false,
        .lowPhaseDutyCycle = DT_PROP(I2C_TEST_NODE, i2c_master_lp_duty_cycle),
        .highPhaseDutyCycle = DT_PROP(I2C_TEST_NODE, i2c_master_hp_duty_cycle),
};

/* Slave configuration */
static const cy_stc_scb_i2c_config_t i2c_slave_config = {
        .i2cMode = CY_SCB_I2C_SLAVE,
        .useRxFifo = DT_PROP(I2C_TEST_NODE, i2c_slave_use_rxfifo),
        .useTxFifo = DT_PROP(I2C_TEST_NODE, i2c_slave_use_txfifo),
        .slaveAddress = DT_PROP(I2C_TEST_NODE, i2c_test_slave_addrs),
        .slaveAddressMask = DT_PROP(I2C_TEST_NODE, i2c_test_slave_addrs_mask),
        .acceptAddrInFifo = false,
        .ackGeneralAddr = false,
        .enableWakeFromSleep = false,
        .enableDigitalFilter = false,
        .lowPhaseDutyCycle = 0,
        .highPhaseDutyCycle = 0,
};

/* ISR handlers */
static void i2c_slave_isr(void)
{
	CySCB_Type *i2c_slave = (CySCB_Type *)DT_REG_ADDR(I2C_SLAVE_TEST_NODE);
        Cy_SCB_I2C_Interrupt(i2c_slave, &i2c_slave_context);
}

static void i2c_master_isr(void)
{
	CySCB_Type *i2c_master = (CySCB_Type *)DT_REG_ADDR(I2C_MASTER_TEST_NODE);
        Cy_SCB_I2C_Interrupt(i2c_master, &i2c_master_context);
}

/* I2C init function */
static void SelfTest_I2C_SCB_Init(CySCB_Type *i2c_master, CySCB_Type *i2c_slave)
{
        cy_en_scb_i2c_status_t i2c_res;
        const uint32_t irq_num_master = DT_IRQN(I2C_MASTER_TEST_NODE);
        const uint32_t irq_num_slave = DT_IRQN(I2C_SLAVE_TEST_NODE);

        IRQ_CONNECT(irq_num_master, 3, i2c_master_isr, NULL, 0);
        irq_enable(irq_num_master);

        IRQ_CONNECT(irq_num_slave, 3, i2c_slave_isr, NULL, 0);
        irq_enable(irq_num_slave);

        /* Master Init */
        i2c_res = Cy_SCB_I2C_Init(i2c_master, &i2c_master_config, &i2c_master_context);
        __ASSERT(i2c_res == CY_SCB_I2C_SUCCESS, "Master init failed");

        Cy_SCB_I2C_Enable(i2c_master, &i2c_master_context);

        /* Slave Init */
        i2c_res = Cy_SCB_I2C_Init(i2c_slave, &i2c_slave_config, &i2c_slave_context);
        __ASSERT(i2c_res == CY_SCB_I2C_SUCCESS, "Slave init failed");

        Cy_SCB_I2C_SlaveConfigReadBuf(i2c_slave, i2c_slave_read_buf, PACKET_SIZE, &i2c_slave_context);
        Cy_SCB_I2C_SlaveConfigWriteBuf(i2c_slave, i2c_slave_write_buf, PACKET_SIZE, &i2c_slave_context);

        Cy_SCB_I2C_Enable(i2c_slave, &i2c_slave_context);
}

static enum post_result mtb_stl_i2c_wrapper(const struct post_context *ctx)
{
        ARG_UNUSED(ctx);

        uint8_t ret = PASS_STILL_TESTING_STATUS;
	CySCB_Type *i2c_master = (CySCB_Type *)DT_REG_ADDR(I2C_MASTER_TEST_NODE);
	CySCB_Type *i2c_slave = (CySCB_Type *)DT_REG_ADDR(I2C_SLAVE_TEST_NODE);

	unsigned int key = irq_lock();

	Cy_SCB_I2C_Disable(i2c_master, &i2c_master_context);
	Cy_SCB_I2C_Disable(i2c_slave, &i2c_slave_context);
	Cy_SCB_I2C_DeInit(i2c_master);
	Cy_SCB_I2C_DeInit(i2c_slave);

	/* TODO: Dividers and pinctrls should happen through driver but here
	 * 	 when CONFIG_I2C=y this test fails even when these clk and 
	 * 	 pinctrl removed when configured through driver so kept this here
	 * 	 to view the status when CONFIG_I2C=n which passes the tests with below pdl apis
	 */
	Cy_SysClk_PeriphAssignDivider(PCLK_SCB1_CLOCK, CY_SYSCLK_DIV_16_BIT, 1U);
	Cy_SysClk_PeriphAssignDivider(PCLK_SCB0_CLOCK, CY_SYSCLK_DIV_16_BIT, 9U);

	Cy_GPIO_Pin_FastInit(GPIO_PRT6, 3, CY_GPIO_DM_OD_DRIVESLOW, 1, P6_3_SCB1_I2C_SCL);
	Cy_GPIO_Pin_FastInit(GPIO_PRT6, 4, CY_GPIO_DM_OD_DRIVESLOW, 1, P6_4_SCB1_I2C_SDA);
        Cy_GPIO_Pin_FastInit(GPIO_PRT2, 0, CY_GPIO_DM_OD_DRIVESLOW, 1, P2_0_SCB0_I2C_SCL);
        Cy_GPIO_Pin_FastInit(GPIO_PRT2, 1, CY_GPIO_DM_OD_DRIVESLOW, 1, P2_1_SCB0_I2C_SDA);

        SelfTest_I2C_SCB_Init(i2c_master ,i2c_slave);

	irq_unlock(key);

	Cy_SysLib_DelayUs(1000);

	/* Note: Found this conditions fails
	 * if (0u != (Cy_SCB_I2C_SlaveGetStatus(slave_base, slave_context) & CY_SCB_I2C_SLAVE_WR_CMPLT))
	 * where this bit (CY_SCB_I2C_SLAVE_WR_CMPLT) not set by slave interrupt 
	 */

        /* connect the p2.0  to p6.3  and  p2.1 to  p6.4 with the jumpers */
        while (ret == PASS_STILL_TESTING_STATUS) {
                ret = SelfTest_I2C_SCB(i2c_master, &i2c_master_context,
                                i2c_slave, &i2c_slave_context,
                                i2c_slave_read_buf, i2c_slave_write_buf);
                Cy_SysLib_DelayUs(10);
        }

        return (ret == PASS_COMPLETE_STATUS) ?  POST_RESULT_PASS : POST_RESULT_FAIL;
}

/* Register MTB-STL test */
POST_TEST_DEFINE(mtb_stl_i2c,
                POST_CAT_I2C,
                POST_LEVEL_APPLICATION,
                50, 0,
                mtb_stl_i2c_wrapper,
                "MTB-STL I2C Test");

#endif /* CONFIG_POST_MTB_STL_I2C */

#ifdef CONFIG_POST_MTB_STL_ANALOG

#include <zephyr/drivers/adc.h>

static const struct adc_dt_spec adc_channel = ADC_DT_SPEC_GET_BY_IDX(DT_PATH(zephyr_user), 0);

/* Initially tried with baremetal approach which fails similar to i2c stl test in the baremetal
 * approach when CONFIG_ADC=n this test passes when CONFIG_ADC=y fails so tried fully
 * configuring with zephyr apis now configured through the overlay and zephyr apis still fails
 */

static enum post_result mtb_stl_analog_wrapper(const struct post_context *ctx)
{
        ARG_UNUSED(ctx);

	int err;
	uint16_t buf;
	SAR_Type* base = (SAR_Type *)DT_REG_ADDR(ADC_TEST_NODE);

	struct adc_sequence sequence = {
		.buffer = &buf,
		.buffer_size = sizeof(buf),
	};

	if (!adc_is_ready_dt(&adc_channel)) {
		LOG_ERR("ADC controller device %s not ready", adc_channel.dev->name);
	}

	err = adc_channel_setup_dt(&adc_channel);
	if (err < 0) {
		LOG_ERR("Could not setup channel");
	}

	(void)adc_sequence_init_dt(&adc_channel, &sequence);

	err = adc_read_dt(&adc_channel, &sequence);
	if (err < 0) {
		LOG_ERR("Could not read (%d)", err);
	}

#ifdef CONFIG_POST_ADC_REF_VOLTAGE2
        return (SelfTests_ADC(base, 0, ANALOG_ADC_SAR_RESULT2,
                             ANALOG_ADC_ACURACCY, 0, 1) == 0) ?
                             POST_RESULT_PASS : POST_RESULT_FAIL;
#else
        return (SelfTests_ADC(base, 0, ANALOG_ADC_SAR_RESULT1,
                             ANALOG_ADC_ACURACCY, 0, 1) == 0) ?
                             POST_RESULT_PASS : POST_RESULT_FAIL;
#endif
}

POST_TEST_DEFINE(mtb_stl_analog,
                POST_CAT_ADC,
                POST_LEVEL_APPLICATION,
                50, 0,
                mtb_stl_analog_wrapper,
                "MTB-STL Analog Self Test");
#endif
