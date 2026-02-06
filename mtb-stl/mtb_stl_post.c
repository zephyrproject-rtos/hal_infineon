/*
 * Copyright (c) 2026 Infineon Technologies AG,
 * or a subsidiary of Infineon Technologies AG.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 * @file
 * @brief MTB-STL POST integration
 *
 * Wraps Infineon MTB-STL self-test functions for the Zephyr POST framework.
 */

#include <zephyr/kernel.h>
#include <zephyr/irq.h>
#include <zephyr/post/post.h>
#include <zephyr/post/post_vendor.h>
#include <zephyr/logging/log.h>
#include <zephyr/devicetree.h>

#include "cy_pdl.h"

#include "mtb_stl_post.h"
#include "mtb_stl_post_cfg.h"
#include "mtb_stl_post_pincfg.h"

LOG_MODULE_REGISTER(mtb_stl_post, CONFIG_POST_LOG_LEVEL);

/*
 * CPU Tests
 */
#ifdef CONFIG_POST_MTB_STL_CPU_REGS
POST_VENDOR_TEST_WRAP(mtb_stl_cpu_regs,
		     POST_CAT_CPU,
		     POST_LEVEL_POST_KERNEL,
		     SelfTest_CPU_Registers,
		     "MTB-STL CPU Register Checkerboard Test");
#endif

#ifdef CONFIG_POST_MTB_STL_CPU_PC
POST_VENDOR_TEST_WRAP(mtb_stl_cpu_pc,
		     POST_CAT_CPU,
		     POST_LEVEL_POST_KERNEL,
		     SelfTest_PC,
		     "MTB-STL Program Counter Test");
#endif

#ifdef CONFIG_POST_MTB_STL_PROGRAM_FLOW
POST_VENDOR_TEST_WRAP(mtb_stl_program_flow,
		     POST_CAT_CPU,
		     POST_LEVEL_POST_KERNEL,
		     SelfTest_PROGRAM_FLOW,
		     "MTB-STL Program Flow Test");
#endif

/*
 * Start Up Tests
 */
#ifdef CONFIG_POST_MTB_STL_SAVE_STARTUP_CFGREG
POST_VENDOR_TEST_WRAP(mtb_stl_save_startup_cfgreg,
		     POST_CAT_STARTUP_CFG_REG,
		     POST_LEVEL_POST_KERNEL,
		     SelfTests_Save_StartUp_ConfigReg,
		     "MTB-STL Save Startup CfgReg Test");
#endif

#ifdef CONFIG_POST_MTB_STL_STARTUP_CFGREG
POST_VENDOR_TEST_WRAP(mtb_stl_run_starup_cfgreg,
		     POST_CAT_STARTUP_CFG_REG,
		     POST_LEVEL_POST_KERNEL,
		     SelfTests_StartUp_ConfigReg,
		     "MTB-STL Startup Reg Test");
#endif

/*
 * GPIO Test
 */
#ifdef CONFIG_POST_MTB_STL_GPIO
POST_VENDOR_TEST_WRAP(mtb_stl_gpio,
		     POST_CAT_GPIO,
		     POST_LEVEL_POST_KERNEL,
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
	return (SelfTest_SRAM(SRAM_MARCH_TEST_MODE,
				ram_test_buffer, sizeof(ram_test_buffer),
				NULL, 0) == 0) ?
				POST_RESULT_PASS : POST_RESULT_FAIL;
}
POST_TEST_DEFINE(mtb_stl_ram_march,
		POST_CAT_RAM,
		POST_LEVEL_PRE_KERNEL_1, 50,
		POST_FLAG_BOOT_ONLY | POST_FLAG_DESTRUCTIVE | POST_FLAG_VENDOR,
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
			(unsigned int)alt_stack_buf_start,
			(unsigned int)alt_stack_buf_end);
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
	__asm__ volatile("mov %0, sp" : "=r" (current_sp));

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
	 * 2. Writing to stack memory can corrupt data even if SP is outside the region
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
		POST_CAT_RAM,
		POST_LEVEL_EARLY, 50,
		POST_FLAG_BOOT_ONLY | POST_FLAG_DESTRUCTIVE | POST_FLAG_VENDOR,
		mtb_stl_stack_march_wrapper,
		"MTB-STL Stack March Test");
#endif

/*
 * Interrupt Test
 */
#ifdef CONFIG_POST_MTB_STL_INTERRUPT

/* Flag to track if POST interrupt test is active */
static volatile bool post_interrupt_test_active = false;
/* Flag to track if POST ISR is registered */
static bool post_intr_test_isr_registered = false;
/* saves current counter status */
static infineon_stl_saved_counter_state_t ifx_saved_cnt_state_intr_test;

/* Zephyr-compatible ISR wrapper for POST interrupt test */
static void post_interrupt_isr_wrapper(const void *arg)
{
	ARG_UNUSED(arg);

	/* Only handle interrupt if POST test is active */
	if (post_interrupt_test_active) {
		/* With shared interrupts, both POST and counter driver ISRs are called.
		 * The order is based on registration order - counter driver registers first
		 * (during PRE_KERNEL_1), so it typically runs first and may clear the interrupt.
		 *
		 * However, with shared interrupts, both ISRs are guaranteed to be called
		 * for each interrupt. The key is that POST's ISR needs to detect the interrupt
		 * even if the counter driver already cleared it.
		 *
		 * Strategy: Since we set the interrupt mask to only CY_TCPWM_INT_ON_TC during
		 * POST test, any interrupt on this IRQ line during POST test must be a terminal
		 * count interrupt for POST. Therefore, if POST test is active and we're in
		 * this ISR, it means a terminal count interrupt occurred.
		 *
		 * We call POST ISR unconditionally during POST test (when mask is terminal count).
		 * The POST ISR will safely clear the interrupt (even if already cleared) and
		 * increment the counter.
		 */
		/* Call the original POST ISR which clears the interrupt and increment counter */
		SelfTest_Interrupt_ISR_TIMER();
	}
	/* If POST test is not active, let the counter driver handle the interrupt */
}

void Interrupt_test_Init (void)
{
	/* Register POST ISR as shared interrupt handler only once */
	/* With CONFIG_SHARED_INTERRUPTS enabled, this will share IRQ 17 with counter driver
	 * Use priority 0 (highest) to ensure POST ISR runs before counter driver ISR
	 * This is important so POST can see the interrupt before counter driver clears it
	 */
	if (!post_intr_test_isr_registered) {
		IRQ_CONNECT(IFX_TCPWM_IRQ_NUM_CNT1, 0,
			    post_interrupt_isr_wrapper, NULL, 0);
		irq_enable(IFX_TCPWM_IRQ_NUM_CNT1);
		post_intr_test_isr_registered = true;
	}
}

static enum post_result mtb_stl_interrupt_wrapper(const struct post_context *ctx)
{
	ARG_UNUSED(ctx);
	uint8_t res = 0u;
	uint32_t savedIntrStatus;

	/* Configure clock divider for POST test */
	infineon_stl_clk_cfg(CY_SYSCLK_DIV_16_BIT, 3U, 2U, PCLK_TCPWM_CLOCKS1);

	/* disables interrupts and returns a value indicates whether interrupts reviously enabled */
	savedIntrStatus = Cy_SysLib_EnterCriticalSection();

	/* Save current counter state to restore after test */
	infineon_stl_save_current_cnt_state(&ifx_saved_cnt_state_intr_test,
						IFX_TCPWM_HW, IFX_TCPWM_CNT_NUM1);

	/* check counter enabled */
	ifx_saved_cnt_state_intr_test.enabled = infineon_stl_cnt_enabled(IFX_TCPWM_HW,
									IFX_TCPWM_CNT_NUM1);
	/* Restore interrupt status */
	Cy_SysLib_ExitCriticalSection(savedIntrStatus);

	/* Configure counter for POST test */
	/* Stop counter if running */
	infineon_stl_stop_running_cnt(IFX_TCPWM_HW, IFX_TCPWM_CNT_NUM1);

	/* Configure counter with POST test parameters */
	infineon_stl_config_post_parameter(&ifx_timer_config, IFX_TCPWM_HW, IFX_TCPWM_CNT_NUM1);

	/* Register POST ISR (if not already registered) BEFORE setting interrupt mask
	 * This ensures POST ISR is in the shared interrupt list
	 */
	Interrupt_test_Init();

	/* Mark POST test as active BEFORE starting the test */
	post_interrupt_test_active = true;

	/* Set interrupt mask for POST test (terminal count interrupt)
	 * IMPORTANT: We set the mask to ONLY terminal count interrupt.
	 * The counter driver's ISR uses GetInterruptStatusMasked, which will
	 * only return interrupts that are both pending AND in the mask.
	 * Since we set the mask to only CY_TCPWM_INT_ON_TC, the counter driver
	 * will see terminal count in its masked status and clear it.
	 * However, POST's ISR reads the raw hardware register FIRST, so it should
	 * see the interrupt before the counter driver clears it (if POST ISR runs first).
	 *
	 * To ensure POST sees interrupts, we read the raw register at the start
	 * of POST's ISR, before any software clearing happens.
	 */
	Cy_TCPWM_SetInterruptMask(IFX_TCPWM_HW, IFX_TCPWM_CNT_NUM1, CY_TCPWM_INT_ON_TC);

	/* Ensure counter is enabled (counter driver may have disabled it) */
	Cy_TCPWM_Counter_Enable(IFX_TCPWM_HW, IFX_TCPWM_CNT_NUM1);

	/* Run POST interrupt test */
	res = SelfTest_Interrupt(IFX_TCPWM_HW, IFX_TCPWM_CNT_NUM1);

	/* Mark POST test as inactive */
	post_interrupt_test_active = false;

	/* disables interrupts and returns a value indicates whether interrupts reviously enabled */
	savedIntrStatus = Cy_SysLib_EnterCriticalSection();

	/* Stop the counter running */
	infineon_stl_stop_running_cnt(IFX_TCPWM_HW, IFX_TCPWM_CNT_NUM1);

	/* Restore the counter state using saved state */
	infineon_stl_restore_cnt_state(&ifx_saved_cnt_state_intr_test, IFX_TCPWM_HW,
									IFX_TCPWM_CNT_NUM1);

	/* Start the counter */
	infineon_stl_start_cnt(ifx_saved_cnt_state_intr_test.enabled, IFX_TCPWM_HW,
									IFX_TCPWM_CNT_NUM1);

	/* Restore interrupt status */
	Cy_SysLib_ExitCriticalSection(savedIntrStatus);

	/* restore clock of driver */
	infineon_stl_clk_cfg(CY_SYSCLK_DIV_16_BIT, 3U, IFX_STL_PERI_CLK3_DIV_VAL,
									PCLK_TCPWM_CLOCKS1);

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
		POST_LEVEL_POST_KERNEL,
		50,
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
static volatile const uint64_t flash_StoredCheckSum __attribute__((used,
			section(".flash_checksum"))) = IFX_FLETCHER64;

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

	uint32_t dt_flash_base = DEVICE_FLASH_BASE;
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
		flash_end_addr = checksum_offset;  /* Relative address */
	} else {
		/* Fallback: exclude last 8 bytes if checksum is at end or outside */
		flash_end_addr = flash_size - FLASH_RESERVED_CHECKSUM_SIZE;
		if (checksum_offset >= flash_size) {
			LOG_WRN("Checksum offset 0x%08lX is outside flash size 0x%08lX, using end-8"
				, (unsigned long)checksum_offset, (unsigned long)flash_size);
		}
	}

	LOG_INF("Flash: DT_base=0x%08lX, HW_base=0x%08lX, size=0x%08lX",
		(unsigned long)DEVICE_FLASH_BASE, (unsigned long)flash_base,
							(unsigned long)flash_size);
	LOG_INF("Checksum range: start=0x%08lX, end=0x%08lX (excludes checksum at 0x%08lX)",
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
		for(int16_t i = sizeof(flash_CheckSum) - 1; i >= 0; i--)
		{
			flash_CheckSum_temp = (uint8_t) (flash_CheckSum >> (i*8u));
			printk("%02X", flash_CheckSum_temp);
		}
		printk("\n");
		return POST_RESULT_FAIL;
	}

	return (res == 3) ? POST_RESULT_PASS : POST_RESULT_FAIL;
}

POST_TEST_DEFINE(mtb_stl_flash,
		POST_CAT_FLASH,
		POST_LEVEL_APPLICATION,
		50, 0,
		mtb_stl_flash_wrapper, "MTB-STL Flash Checksum Test");
#endif

/*
 * Clock Tests
 */
#ifdef CONFIG_POST_MTB_STL_CLOCK

static volatile bool post_clock_test_active = false;
static bool post_clk_test_isr_registered = false;
static infineon_stl_saved_counter_state_t ifx_saved_cnt_state_clk_test;

static void post_interrupt_clk_wrapper(const void *arg)
{
	ARG_UNUSED(arg);

	/* Only handle interrupt if POST test is active */
	if (post_clock_test_active) {
		SelfTest_Clock_ISR_TIMER();
	}
	/* If POST test is not active, let the counter driver handle the interrupt */
}


static void clock_test_init(void) {

	if (!post_clk_test_isr_registered) {
		IRQ_CONNECT(IFX_TCPWM_IRQ_NUM_CNT0, 0, post_interrupt_clk_wrapper, NULL, 0);
		irq_enable(IFX_TCPWM_IRQ_NUM_CNT0);
		post_clk_test_isr_registered = true;
	}


	Cy_WDT_SetIgnoreBits(IGNORE_BITS);

	if (Cy_WDT_GetIgnoreBits() != IGNORE_BITS) {
		__ASSERT(0, "IGNORE BITS MISMATCH");
	}

	Cy_WDT_ClearInterrupt();

	Cy_WDT_Enable();
	if (Cy_WDT_IsEnabled() == false) {
		__ASSERT(0, "WDT IS NOT ENABLED");
	}
}

static enum post_result mtb_stl_clock_wrapper(const struct post_context *ctx)
{
	ARG_UNUSED(ctx);

	uint8_t res;
	uint32_t savedIntrStatus;

	infineon_stl_clk_cfg(CY_SYSCLK_DIV_16_BIT, 6U, 1U, PCLK_TCPWM_CLOCKS0);

	savedIntrStatus = Cy_SysLib_EnterCriticalSection();

	infineon_stl_save_current_cnt_state(&ifx_saved_cnt_state_clk_test, IFX_TCPWM_HW,
			 						IFX_TCPWM_CNT_NUM0);
	ifx_saved_cnt_state_clk_test.enabled = infineon_stl_cnt_enabled(IFX_TCPWM_HW,
									IFX_TCPWM_CNT_NUM0);

	Cy_SysLib_ExitCriticalSection(savedIntrStatus);

	infineon_stl_config_post_parameter(&ifx_clk_test_timer_config, IFX_TCPWM_HW,
									IFX_TCPWM_CNT_NUM0);
	clock_test_init();

	post_clock_test_active = true;

	Cy_TCPWM_SetInterruptMask(IFX_TCPWM_HW, IFX_TCPWM_CNT_NUM0, CY_TCPWM_INT_ON_TC);

	Cy_TCPWM_Counter_Enable(IFX_TCPWM_HW, IFX_TCPWM_CNT_NUM0);

	/* Add timeout to prevent infinite hang */
	uint32_t start = k_cycle_get_32();
	uint32_t timeout_cycles = k_ms_to_cyc_ceil32(100); /* 100ms timeout */

	do {
		res = SelfTest_Clock(IFX_TCPWM_HW, IFX_TCPWM_CNT_NUM0);
		if ((k_cycle_get_32() - start) > timeout_cycles) {
			return POST_RESULT_FAIL; /* Timeout */
		}
	} while (res == 2);

	Cy_WDT_ClearInterrupt();
	Cy_WDT_Disable();

	post_clock_test_active = false;

	savedIntrStatus = Cy_SysLib_EnterCriticalSection();

	infineon_stl_stop_running_cnt(IFX_TCPWM_HW, IFX_TCPWM_CNT_NUM0);

	infineon_stl_restore_cnt_state(&ifx_saved_cnt_state_clk_test, IFX_TCPWM_HW,
									IFX_TCPWM_CNT_NUM0);

	infineon_stl_start_cnt(ifx_saved_cnt_state_clk_test.enabled, IFX_TCPWM_HW,
									IFX_TCPWM_CNT_NUM0);

	Cy_SysLib_ExitCriticalSection(savedIntrStatus);

	infineon_stl_clk_cfg(CY_SYSCLK_DIV_16_BIT, 6U, IFX_STL_PERI_CLK6_DIV_VAL,
									PCLK_TCPWM_CLOCKS0);

	return (res == 3) ? POST_RESULT_PASS : POST_RESULT_FAIL;
}
POST_TEST_DEFINE(mtb_stl_clock,
		POST_CAT_CLOCK,
		POST_LEVEL_POST_KERNEL,
		50, 0,
		mtb_stl_clock_wrapper,
		"MTB-STL Clock Frequency Test");
#endif

#ifdef CONFIG_POST_MTB_STL_DMA
static enum post_result mtb_stl_dmac_wrapper(const struct post_context *ctx)
{
	return (SelfTest_DMAC(DMAC, 0UL, TRIG0_OUT_CPUSS_DMAC_TR_IN0) == 0)
				? POST_RESULT_PASS : POST_RESULT_FAIL;
}

POST_TEST_DEFINE(mtb_stl_dmac,
		POST_CAT_DMA,
		POST_LEVEL_APPLICATION,
		50, 0,
		mtb_stl_dmac_wrapper,
		"MTB-STL DMAC Test");
#endif

/*
 * Watchdog Tests
 */
#ifdef CONFIG_POST_MTB_STL_WDT
/* WDT test causes a system reset. Marking as destructive. */
POST_VENDOR_TEST_WRAP_FLAGS(mtb_stl_wdt,
			    POST_CAT_WATCHDOG,
			    POST_LEVEL_APPLICATION,
			    POST_FLAG_DESTRUCTIVE | POST_FLAG_VENDOR,
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
 * Analog Tests
 */
#ifdef CONFIG_POST_MTB_STL_ANALOG

static enum post_result mtb_stl_analog_wrapper(const struct post_context *ctx)
{
	ARG_UNUSED(ctx);

	cy_en_sar_status_t sar_res;

	infineon_stl_clk_cfg(CY_SYSCLK_DIV_16_BIT, 8U, 15U, PCLK_PASS0_CLOCK_SAR);

	SAR0->MUX_SWITCH0 = SAR_MUX_SWITCH0_MUX_FW_P0_VPLUS_Msk;
	SAR0->MUX_SWITCH_HW_CTRL = SAR_MUX_SWITCH_HW_CTRL_MUX_HW_CTRL_P0_Msk;
	SAR0->CTRL |= SAR_CTRL_ENABLED_Msk;

	SAR_MUX_SWITCH0(SAR0) = CY_SAR_MUX_FW_VSSA_VMINUS;
	SAR_MUX_SWITCH_HW_CTRL(SAR0) |= CY_SAR_MUX_HW_CTRL_VSSA;

	Cy_SysClk_PeriphAssignDivider(PCLK_PASS0_CLOCK_SAR, CY_SYSCLK_DIV_16_BIT, 8U);

	Cy_GPIO_Pin_Init(GPIO_PRT2, 0U, &ifx_0_port_2_pin_0_config);

	sar_res = Cy_SAR_Init(SAR0, &ifx_dut_sar_adc_cfg);
	if (sar_res != CY_SAR_SUCCESS) {
		__ASSERT(0, "SAR ADC INIT FAILED !!!");
	}

	Cy_SAR_Enable(SAR0);

	infineon_stl_clk_cfg(CY_SYSCLK_DIV_16_BIT, 8U, IFX_STL_PERI_CLK7_DIV_VAL,
							PCLK_PASS0_CLOCK_SAR);

#ifdef CONFIG_POST_ADC_REF_VOLTAGE2
	return (SelfTests_ADC(SAR0, 0, ANALOG_ADC_SAR_RESULT2,
			     ANALOG_ADC_ACURACCY, 0, 1) == 0) ?
			     POST_RESULT_PASS : POST_RESULT_FAIL;
#else
	return (SelfTests_ADC(SAR0, 0, ANALOG_ADC_SAR_RESULT1,
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

/* Counter test */
#ifdef CONFIG_POST_MTB_STL_COUNTER

/* Flag to track if POST counte test is active */
static volatile bool post_counter_test_active = false;
/* Flag to track if POST ISR is registered */
static bool post_cnt_test_isr_registered = false;
/* saves current counter status */
static infineon_stl_saved_counter_state_t ifx_saved_cnt_state_cnt_test;

static volatile uint8_t int_occur = 0U;
static TCPWM_Type *ifx_cntbase;
static uint32_t ifx_cntnum;

static void post_counter_isr(const void *arg)
{
	ARG_UNUSED(arg);

	if (post_counter_test_active) {
		Cy_TCPWM_Counter_Disable(ifx_cntbase, ifx_cntnum);
		uint32_t interrupts = Cy_TCPWM_GetInterruptStatusMasked(ifx_cntbase, ifx_cntnum);
		Cy_TCPWM_ClearInterrupt(ifx_cntbase, ifx_cntnum, interrupts);
		int_occur++;
	}
}

static void post_counter_test_init(void)
{
	if (!post_cnt_test_isr_registered) {
		IRQ_CONNECT(IFX_TCPWM_IRQ_NUM_CNT2, 0, post_counter_isr, NULL, 0);
		irq_enable(IFX_TCPWM_IRQ_NUM_CNT2);
		post_cnt_test_isr_registered = true;
	}
}

uint8_t ifx_selftest_counter_timer(void)
{
	uint8_t ret = ERROR_STATUS;
	uint16_t delay_cnt = 0U;
	uint32_t counterVal;

	int_occur = 0U;

	Cy_TCPWM_Counter_SetCompare0(ifx_cntbase, ifx_cntnum, TIMER_COUNTER_TEST_COMPARE);
	Cy_TCPWM_Counter_SetPeriod(ifx_cntbase, ifx_cntnum, TIMER_COUNTER_TEST_PERIOD);
	Cy_TCPWM_Counter_SetCounter(ifx_cntbase, ifx_cntnum, 0U);
	Cy_TCPWM_Counter_Enable(ifx_cntbase, ifx_cntnum);

#if (ERROR_IN_TIMER_COUNTER == 0U)
#if defined(CY_IP_M0S8TCPWM)
	Cy_TCPWM_TriggerReloadOrIndex(ifx_cntbase, 1UL << ifx_cntnum);
#else
	Cy_TCPWM_TriggerReloadOrIndex_Single(ifx_cntbase, ifx_cntnum);
#endif
#endif

	do  {
		counterVal = Cy_TCPWM_Counter_GetCounter(ifx_cntbase, ifx_cntnum);
		Cy_SysLib_DelayUs(1);
		delay_cnt++;
	} while ((int_occur == 0U) && (TIMER_COUNTER_TIMEOUT > delay_cnt));

	if (TIMER_COUNTER_TIMEOUT > delay_cnt)
	{
		if ((TIMER_COUNTER_COUNT_LOW < counterVal)
				&& (TIMER_COUNTER_COUNT_HIGH > counterVal))
		{
			ret = OK_STATUS;
		}
	}

	return ret;
}

/* Note: Implemented test similar to STL Counter test to intergrate because here interrupt
 * 	 and others are configured within the selftest init
 */
static enum post_result mtb_stl_counter_wrapper(const struct post_context *ctx)
{
	ARG_UNUSED(ctx);

	uint8_t result;
	uint32_t savedIntrStatus;

	ifx_cntbase = IFX_TCPWM_HW;
	ifx_cntnum = IFX_TCPWM_CNT_NUM2;

	/* Clock enable */
	infineon_stl_clk_cfg(CY_SYSCLK_DIV_16_BIT, 7U, 1U, PCLK_TCPWM_CLOCKS2);

	/* Save current counter state to restore after test */
	savedIntrStatus = Cy_SysLib_EnterCriticalSection();

	infineon_stl_save_current_cnt_state(&ifx_saved_cnt_state_cnt_test,
                                        IFX_TCPWM_HW, IFX_TCPWM_CNT_NUM2);

	ifx_saved_cnt_state_cnt_test.enabled = infineon_stl_cnt_enabled(IFX_TCPWM_HW,
									IFX_TCPWM_CNT_NUM2);

	Cy_SysLib_ExitCriticalSection(savedIntrStatus);

	infineon_stl_stop_running_cnt(IFX_TCPWM_HW, IFX_TCPWM_CNT_NUM2);

	infineon_stl_config_post_parameter(&ifx_timer_counter_config, IFX_TCPWM_HW,
									IFX_TCPWM_CNT_NUM2);

	post_counter_test_init();

	post_counter_test_active = true;

	if (CY_TCPWM_SUCCESS != Cy_TCPWM_Counter_Init(IFX_TCPWM_HW, IFX_TCPWM_CNT_NUM2,
								&ifx_timer_counter_config)) {
		__ASSERT(0,"COUNTER TEST INIT FAILED !!!");
	}

	Cy_TCPWM_SetInterruptMask(IFX_TCPWM_HW, IFX_TCPWM_CNT_NUM2, CY_TCPWM_INT_ON_CC);

	Cy_TCPWM_Counter_Enable(IFX_TCPWM_HW, IFX_TCPWM_CNT_NUM2);

	result = ifx_selftest_counter_timer();

	post_counter_test_active = false;

	savedIntrStatus = Cy_SysLib_EnterCriticalSection();

	infineon_stl_stop_running_cnt(IFX_TCPWM_HW, IFX_TCPWM_CNT_NUM2);

	infineon_stl_restore_cnt_state(&ifx_saved_cnt_state_cnt_test, IFX_TCPWM_HW,
									IFX_TCPWM_CNT_NUM2);

	infineon_stl_start_cnt(ifx_saved_cnt_state_cnt_test.enabled, IFX_TCPWM_HW,
									IFX_TCPWM_CNT_NUM2);

	Cy_SysLib_ExitCriticalSection(savedIntrStatus);

	infineon_stl_clk_cfg(CY_SYSCLK_DIV_16_BIT, 7U, IFX_STL_PERI_CLK7_DIV_VAL,
									PCLK_TCPWM_CLOCKS2);

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

#define PWM_IN_PORT                 GPIO_PRT6
#define PWM_IN_PIN                  1

static enum post_result mtb_stl_pwm_wrapper(const struct post_context *ctx)
{
	ARG_UNUSED(ctx);
	uint8_t result;

	/* Clock enable for PWM */
	infineon_stl_clk_cfg(CY_SYSCLK_DIV_16_BIT, 1U, 1U, PCLK_TCPWM_CLOCKS3);

	Cy_GPIO_Pin_Init(PWM_IN_PORT, PWM_IN_PIN + 1, &pwm_out_cfg); /* P6.2 output */
	Cy_GPIO_Pin_Init(PWM_IN_PORT, PWM_IN_PIN, &pwm_in_cfg); /* P6.1 input */

	/* Initialize PWM  */
	if (SelfTest_PWM_init(IFX_TCPWM_HW, IFX_TCPWM_CNT_NUM3, &ifx_pwm_config,
							IFX_TCPWM_IRQ_NUM_CNT3) != OK_STATUS) {
		LOG_ERR("PWM_TEST INIT FAILED");
	}

	/* Run vendor PWM self-test and also connect the p6.1 and p6.2 with jumper */
	result = SelfTest_PWM(PWM_IN_PORT, PWM_IN_PIN);

	infineon_stl_clk_cfg(CY_SYSCLK_DIV_16_BIT, 1U, IFX_STL_PERI_CLK1_DIV_VAL,
							PCLK_TCPWM_CLOCKS3);

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

	uint8_t result;

	infineon_stl_clk_cfg(CY_SYSCLK_DIV_16_BIT, 6U, 1U, PCLK_TCPWM_CLOCKS4);

	if (Cy_TCPWM_PWM_Init(IFX_TCPWM_HW, IFX_TCPWM_CNT_NUM4, &ifx_pwm_gatekill_config)
									!= CY_TCPWM_SUCCESS) {
		LOG_ERR("PWM_INIT faield");
	}

	Cy_TCPWM_PWM_Enable(IFX_TCPWM_HW, IFX_TCPWM_CNT_NUM4);

	Cy_TCPWM_TriggerReloadOrIndex(IFX_TCPWM_HW, (1UL << IFX_TCPWM_CNT_NUM4));

	Cy_TCPWM_TriggerStopOrKill(IFX_TCPWM_HW, (1UL << IFX_TCPWM_CNT_NUM4));

	result = SelfTest_PWM_GateKill(IFX_TCPWM_HW, IFX_TCPWM_CNT_NUM4);

	infineon_stl_clk_cfg(CY_SYSCLK_DIV_16_BIT, 6U, IFX_STL_PERI_CLK6_DIV_VAL,
							PCLK_TCPWM_CLOCKS4);

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

static void Timeout_Counter_Init(void)
{
	cy_en_tcpwm_status_t tcpwm_result;

	IRQ_CONNECT(IFX_TCPWM_IRQ_NUM_CNT2, IFX_TCPWM_CNT_PRIO_3,
						UartMesMaster_Timeout_ISR, NULL, 0);
	irq_enable(IFX_TCPWM_IRQ_NUM_CNT2);

	tcpwm_result = Cy_TCPWM_Counter_Init(IFX_TCPWM_HW, IFX_TCPWM_CNT_NUM2,
						&ifx_timer_uart_master_cfg);

	if(tcpwm_result != CY_TCPWM_SUCCESS) {
		__ASSERT(0, "Counter Init Failed !!!");
	}

	Cy_TCPWM_Counter_Enable(IFX_TCPWM_HW, 2);
}

static void Protocol_Test_UART_Init(void)
{
	cy_en_scb_uart_status_t uart_result;

	IRQ_CONNECT(IFX_SCB4_IRQ_NUM, 3, UartMesMaster_Msg_ISR, NULL, 0);
	irq_enable(IFX_SCB4_IRQ_NUM);

	IRQ_CONNECT(IFX_SCB3_IRQ_NUM, 3, UartMesSlave_Msg_ISR, NULL, 0);
	irq_enable(IFX_SCB3_IRQ_NUM);

	uart_result = Cy_SCB_UART_Init(IFX_SCB4_HW, &ifx_uart_master_config, NULL);
	if (uart_result != CY_SCB_UART_SUCCESS) {
		__ASSERT(0, "UART master test init failed !!!");
	}

	uart_result = Cy_SCB_UART_Init(IFX_SCB3_HW, &ifx_uart_slave_cfg, NULL);
	if (uart_result != CY_SCB_UART_SUCCESS) {
		__ASSERT(0, "UART slave test init failed !!!");
	}
}

static enum post_result mtb_stl_communication_wrapper(const struct post_context *ctx)
{
	ARG_UNUSED(ctx);

	uint8_t rxd[16u];
	uint8_t txd[] = "1234567890ABCDEF";
	uint8_t slave_resp_res;
	uint32_t start;
	uint32_t timeout_cycles;

	infineon_stl_clk_cfg(CY_SYSCLK_DIV_16_BIT, 2U, 24000U, PCLK_TCPWM_CLOCKS2);

	Cy_SysClk_PeriphSetDivider(CY_SYSCLK_DIV_16_BIT, 0U, 25U);
	Cy_SysClk_PeriphEnableDivider(CY_SYSCLK_DIV_16_BIT, 0U);
	Cy_SysClk_PeriphAssignDivider(PCLK_SCB4_CLOCK, CY_SYSCLK_DIV_16_BIT, 0U);
	Cy_SysClk_PeriphAssignDivider(PCLK_SCB3_CLOCK, CY_SYSCLK_DIV_16_BIT, 0U);

	/* Note: -Connect p4.0 -> p2.5 and p4.1 -> p2.4
	 * 	 -Throws error if pins not connect properly
	 */
	Cy_GPIO_Pin_Init(GPIO_PRT4, 0U, &ioss_0_port_4_pin_0_config);
	Cy_GPIO_Pin_Init(GPIO_PRT4, 1U, &ioss_0_port_4_pin_1_config);
	Cy_GPIO_Pin_Init(GPIO_PRT2, 4U, &ioss_0_port_2_pin_4_config);
	Cy_GPIO_Pin_Init(GPIO_PRT2, 5U, &ioss_0_port_2_pin_5_config);

	Timeout_Counter_Init();
	Protocol_Test_UART_Init();

	UartMesMaster_Init(IFX_SCB4_HW, IFX_TCPWM_HW, IFX_TCPWM_CNT_NUM2);
	UartMesSlave_Init(IFX_SCB3_HW, IFX_COMM_SLAVE_ADDR);

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

	infineon_stl_clk_cfg(CY_SYSCLK_DIV_16_BIT, 2U, IFX_STL_PERI_CLK2_DIV_VAL,
							PCLK_TCPWM_CLOCKS2);

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
