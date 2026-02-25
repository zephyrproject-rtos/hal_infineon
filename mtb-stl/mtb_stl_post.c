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
#include <zephyr/logging/log.h>
#include <zephyr/post/post.h>
#include <zephyr/post/post_vendor.h>

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
POST_VENDOR_TEST_WRAP_FLAGS(mtb_stl_gpio,
		POST_CAT_GPIO,
		POST_LEVEL_POST_KERNEL,
		POST_FLAG_BOOT_ONLY,
		SelfTest_IO,
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

	SelfTest_Flash_init(flash_start_addr, flash_end_addr, flash_StoredCheckSum);

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
/* WDT test causes a system reset. Marking as destructive. */
POST_VENDOR_TEST_WRAP_FLAGS(mtb_stl_wdt,
		POST_CAT_WATCHDOG,
		POST_LEVEL_APPLICATION,
		POST_FLAG_DESTRUCTIVE,
		SelfTest_WDT,
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

static ifx_stl_saved_cnt_state_t ifx_saved_cnt_state_intr_test;

void Interrupt_test_Init (uint32_t cnt_num, TCPWM_Type *base)
{
	uint32_t intr_src = DT_PROP(INTERRUPT_TEST_NODE, interrupt_sources);

	Cy_TCPWM_Counter_Enable(base, cnt_num);
	Cy_TCPWM_SetInterruptMask(base, cnt_num, intr_src);
}

static enum post_result mtb_stl_interrupt_wrapper(const struct post_context *ctx)
{
	ARG_UNUSED(ctx);

	uint8_t res;
	TCPWM_Type *base;
	uint32_t savedIntrStatus;
	uint32_t clock_dest = DT_PROP(DT_PARENT(COUNTER_INTR_TEST_NODE), clk_dst);
	uint32_t period = DT_PROP(INTERRUPT_TEST_NODE, test_period);
	uint32_t compare0 = DT_PROP(INTERRUPT_TEST_NODE, test_compare0);
	uint32_t compare1 = DT_PROP(INTERRUPT_TEST_NODE, test_compare1);
	const uint32_t irq_num = DT_IRQN(DT_PARENT(COUNTER_INTR_TEST_NODE));
	uint32_t divider_type = DT_PROP(CLOCK_INTR_TEST_NODE, div_type);
	uint32_t divider_channel = DT_PROP(CLOCK_INTR_TEST_NODE, channel);
	uint32_t cnt_num = DT_PROP(CLOCK_INTR_TEST_NODE, resource_channel);

	base = (TCPWM_Type *)(DT_REG_ADDR(DT_PARENT(DT_PARENT(COUNTER_INTR_TEST_NODE))));

	/* Using default counter test clock */
	Cy_SysClk_PeriphAssignDivider(clock_dest, divider_type, divider_channel);

	savedIntrStatus = Cy_SysLib_EnterCriticalSection();

	/* Save current counter state to restore after test */
	infineon_stl_save_current_cnt_state(&ifx_saved_cnt_state_intr_test, base, cnt_num);

	/* check counter enabled */
	ifx_saved_cnt_state_intr_test.enabled = infineon_stl_cnt_enabled(base, cnt_num);

	/* Restore interrupt status */
	Cy_SysLib_ExitCriticalSection(savedIntrStatus);

	/* Stop counter if running */
	infineon_stl_stop_running_cnt(base, cnt_num);

	/* Configure counter with POST test parameters */
	infineon_stl_config_post_parameter(base, cnt_num, period, compare0, compare1);

	/* IRQ setup */
	IRQ_CONNECT(irq_num, 3, SelfTest_Interrupt_ISR_TIMER, NULL, 0);
	irq_enable(irq_num);

	Interrupt_test_Init(cnt_num, base);

	res = SelfTest_Interrupt(base, cnt_num);

	/* disables interrupts and returns a value indicates whether interrupts reviously enabled */
	savedIntrStatus = Cy_SysLib_EnterCriticalSection();

	/* Stop the counter running */
	infineon_stl_stop_running_cnt(base, cnt_num);

	/* Restore the counter state using saved state */
	infineon_stl_restore_cnt_state(&ifx_saved_cnt_state_intr_test, base, cnt_num);

	/* Start the counter */
	infineon_stl_start_cnt(ifx_saved_cnt_state_intr_test.enabled, base, cnt_num);

	/* Restore interrupt status */
	Cy_SysLib_ExitCriticalSection(savedIntrStatus);

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

/*
 * In this test, we will use a default test peripheral clock divider.
 * Initially, we will check whether the app uses the same counter as
 * we are using for test, based on its clocks property. Therefore,
 * we won't assign anything in the clocks property in the
 * counter test node, but we will enable the clocks we intend to use.
 *
 * If the app uses a different divider channel with a different
 * divider value, the test won't pass. Therefore, we use the test-specific
 * peripheral divider here, and we will assign the divider channel back
 * to what the app uses if it is available or was originally used.
 */

static ifx_stl_saved_cnt_state_t ifx_saved_cnt_state_clk_test;

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
	TCPWM_Type *base;
	uint32_t savedIntrStatus;
	uint32_t clock_dest = DT_PROP(DT_PARENT(COUNTER_CLK_TEST_NODE), clk_dst);
	uint32_t period = DT_PROP(CLOCK_TEST_NODE, test_period);
	uint32_t compare0 = DT_PROP(CLOCK_TEST_NODE, test_compare0);
	uint32_t compare1 = DT_PROP(CLOCK_TEST_NODE, test_compare1);
	const uint32_t irq_num = DT_IRQN(DT_PARENT(COUNTER_CLK_TEST_NODE));
#if DT_NODE_HAS_PROP(COUNTER_CLK_TEST_NODE, clocks)
	uint32_t divider_type = DT_PROP(CLOCK_CLK_TEST_NODE, div_type);
	uint32_t divider_channel = DT_PROP(CLOCK_CLK_TEST_NODE, channel);
	uint32_t cnt_num = DT_PROP(CLOCK_CLK_TEST_NODE, resource_channel);
#else
	uint32_t cnt_num = DT_PROP(DEFAULT_CLOCK_CLK_TEST_NODE, resource_channel);
#endif
	uint32_t def_divider_type = DT_PROP(DEFAULT_CLOCK_CLK_TEST_NODE, div_type);
	uint32_t def_divider_channel = DT_PROP(DEFAULT_CLOCK_CLK_TEST_NODE, channel);

	IRQ_CONNECT(irq_num, 3, SelfTest_Clock_ISR_TIMER, NULL, 0);
	irq_enable(irq_num);

	Cy_SysClk_PeriphAssignDivider(clock_dest, def_divider_type, def_divider_channel);

	base = (TCPWM_Type *)(DT_REG_ADDR(DT_PARENT(DT_PARENT(COUNTER_CLK_TEST_NODE))));

	savedIntrStatus = Cy_SysLib_EnterCriticalSection();

	infineon_stl_save_current_cnt_state(&ifx_saved_cnt_state_clk_test, base, cnt_num);

	ifx_saved_cnt_state_clk_test.enabled = infineon_stl_cnt_enabled(base, cnt_num);

	Cy_SysLib_ExitCriticalSection(savedIntrStatus);

	infineon_stl_stop_running_cnt(base, cnt_num);

	infineon_stl_config_post_parameter(base, cnt_num, period, compare0, compare1);

	clock_test_init(cnt_num, base);

	/* Add timeout to prevent infinite hang */
	uint32_t start = k_cycle_get_32();
	uint32_t timeout_cycles = k_ms_to_cyc_ceil32(100); /* 100ms timeout */

	do {
		res = SelfTest_Clock(base, cnt_num);
		if ((k_cycle_get_32() - start) > timeout_cycles) {
			return POST_RESULT_FAIL; /* Timeout */
		}
	} while (res == 2);

	savedIntrStatus = Cy_SysLib_EnterCriticalSection();

	infineon_stl_stop_running_cnt(base, cnt_num);

	infineon_stl_restore_cnt_state(&ifx_saved_cnt_state_clk_test, base, cnt_num);

	infineon_stl_start_cnt(ifx_saved_cnt_state_clk_test.enabled, base, cnt_num);

	Cy_SysLib_ExitCriticalSection(savedIntrStatus);

	Cy_WDT_ClearInterrupt();
	Cy_WDT_Disable();

#if DT_NODE_HAS_PROP(COUNTER_CLK_TEST_NODE, clocks)
	Cy_SysClk_PeriphAssignDivider(clock_dest, divider_type, divider_channel);
#endif

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

static ifx_stl_saved_cnt_state_t ifx_saved_cnt_state_cnt_test;

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
	uint32_t savedIntrStatus;
	uint32_t divider_type = DT_PROP(CLOCK_CNT_TEST_NODE, div_type);
	uint32_t divider_channel = DT_PROP(CLOCK_CNT_TEST_NODE, channel);
	uint32_t clock_dest = DT_PROP(DT_PARENT(COUNTER_CNT_TEST_NODE), clk_dst);
	uint32_t cnt_num = DT_PROP(CLOCK_CNT_TEST_NODE, resource_channel);
	uint32_t period = DT_PROP(COUNTER_TEST_NODE, test_period);
	uint32_t compare0 = DT_PROP(COUNTER_TEST_NODE, test_compare0);
	uint32_t compare1 = DT_PROP(COUNTER_TEST_NODE, test_compare1);
	const uint32_t irq_num = DT_IRQN(DT_PARENT(COUNTER_CNT_TEST_NODE));

	Cy_SysClk_PeriphAssignDivider(clock_dest, divider_type, divider_channel);

	base = (TCPWM_Type *)(DT_REG_ADDR(DT_PARENT(DT_PARENT(COUNTER_CNT_TEST_NODE))));

	savedIntrStatus = Cy_SysLib_EnterCriticalSection();

	infineon_stl_save_current_cnt_state(&ifx_saved_cnt_state_cnt_test, base, cnt_num);
	ifx_saved_cnt_state_cnt_test.enabled = infineon_stl_cnt_enabled(base, cnt_num);

	Cy_SysLib_ExitCriticalSection(savedIntrStatus);

	infineon_stl_stop_running_cnt(base, cnt_num);
	infineon_stl_config_post_parameter(base, cnt_num, period, compare0, compare1);

	SelfTest_Timer_Counter_init(base, cnt_num, &ifx_timer_counter_config, irq_num);

	result = SelfTest_Counter_Timer();

	savedIntrStatus = Cy_SysLib_EnterCriticalSection();

	infineon_stl_stop_running_cnt(base, cnt_num);
	infineon_stl_restore_cnt_state(&ifx_saved_cnt_state_cnt_test, base, cnt_num);
	infineon_stl_start_cnt(ifx_saved_cnt_state_cnt_test.enabled, base, cnt_num);

	Cy_SysLib_ExitCriticalSection(savedIntrStatus);

	return (result == OK_STATUS) ? POST_RESULT_PASS : POST_RESULT_FAIL;
}

POST_TEST_DEFINE(mtb_stl_counter,
		POST_CAT_COUNTER,
		POST_LEVEL_APPLICATION,
		10, 0,
		mtb_stl_counter_wrapper,
		"MTB-STL TCPWM Counter Self-Test");

#endif /* CONFIG_POST_MTB_STL_COUNTER */

/* PWM_GATEKILL test */
#ifdef CONFIG_POST_MTB_STL_PWM_GATEKILL

static enum post_result mtb_stl_pwm_gatekill_wrapper(const struct post_context *ctx)
{
	ARG_UNUSED(ctx);

	uint8_t result = ERROR_STATUS;
	TCPWM_Type *base_gk_cnt;
	uint32_t cnt_num = DT_PROP(CLOCK_PWM_GK_TEST_NODE, resource_channel);
	uint32_t divider_type = DT_PROP(CLOCK_PWM_GK_TEST_NODE, div_type);
	uint32_t divider_channel = DT_PROP(CLOCK_PWM_GK_TEST_NODE, channel);
	uint32_t clock_dest = DT_PROP(DT_PARENT(COUNTER_PWM_GK_TEST_NODE), clk_dst);

	Cy_SysClk_PeriphAssignDivider(clock_dest, divider_type, divider_channel);

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
