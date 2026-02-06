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
		POST_FLAG_DESTRUCTIVE | POST_FLAG_VENDOR,
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
	return (SelfTest_SRAM(SRAM_MARCH_TEST_MODE, ram_test_buffer,
				sizeof(ram_test_buffer), NULL, 0) == 0)
		? POST_RESULT_PASS
		: POST_RESULT_FAIL;
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
		POST_LEVEL_APPLICATION, 50, 0,
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

const cy_stc_gpio_pin_config_t tx_config =
{
	.outVal = DT_PROP(TX_PIN_NODE, out_val),
	.driveMode = DT_PROP(TX_PIN_NODE, drive_mode),
	.hsiom = DT_PROP(TX_PIN_NODE, hsiom),
	.intEdge = CY_GPIO_INTR_DISABLE,
	.vtrip = CY_GPIO_VTRIP_CMOS,
	.slewRate = CY_GPIO_SLEW_FAST,
};

const cy_stc_gpio_pin_config_t rx_config =
{
	.outVal = DT_PROP(RX_PIN_NODE, out_val),
	.driveMode = DT_PROP(RX_PIN_NODE, drive_mode),
	.hsiom = DT_PROP(RX_PIN_NODE, hsiom),
	.intEdge = CY_GPIO_INTR_DISABLE,
	.vtrip = CY_GPIO_VTRIP_CMOS,
	.slewRate = CY_GPIO_SLEW_FAST,
};

const cy_stc_scb_uart_config_t ifx_uart_test_cfg =
{
	.uartMode = CY_SCB_UART_STANDARD,
	.enableMutliProcessorMode = false,
	.smartCardRetryOnNack = false,
	.irdaInvertRx = false,
	.irdaEnableLowPowerReceiver = false,
	.enableLinMode = false,
	.oversample = 8,
	.enableMsbFirst = false,
	.dataWidth = 8UL,
	.parity = DT_PROP(UART_LP_TEST_NODE, parity),
	.stopBits = DT_PROP(UART_LP_TEST_NODE, stop_bits),
	.enableInputFilter = false,
	.breakWidth = 11UL,
	.breakLevel = false,
	.dropOnFrameError = false,
	.dropOnParityError = false,
	.receiverAddress = 0x0UL,
	.receiverAddressMask = 0x0UL,
	.acceptAddrInFifo = false,
	.enableCts = false,
	.ctsPolarity = CY_SCB_UART_ACTIVE_LOW,
	.rtsRxFifoLevel = 0UL,
	.rtsPolarity = CY_SCB_UART_ACTIVE_LOW,
	.rxFifoTriggerLevel = 7UL,
	.rxFifoIntEnableMask = 0UL,
	.txFifoTriggerLevel = 0UL,
	.txFifoIntEnableMask = 0UL,
};

static cy_stc_scb_uart_context_t ifx_uart_test_ctx;

static void SelfTest_UART_SCB_Init(CySCB_Type *scb_block)
{
	cy_en_scb_uart_status_t initstatus;

	initstatus = Cy_SCB_UART_Init(scb_block, &ifx_uart_test_cfg, &ifx_uart_test_ctx);
	if (initstatus != CY_SCB_UART_SUCCESS) {
		__ASSERT(0, "Test UART Init failed !!!");
	}

	Cy_SCB_UART_Enable(scb_block);

	Cy_SCB_UART_ClearRxFifo(scb_block);
	Cy_SCB_UART_ClearTxFifo(scb_block);
}

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

	uint32_t scb_block_num = DT_PROP(UART_LP_TEST_NODE, scb_instance);

	Cy_SysClk_PeriphSetDivider(CY_SYSCLK_DIV_16_BIT, 7U, 51U);
	Cy_SysClk_PeriphEnableDivider(CY_SYSCLK_DIV_16_BIT, 7U);
	Cy_SysClk_PeriphAssignDivider(PCLK_SCB1_CLOCK, CY_SYSCLK_DIV_16_BIT, 7U);

	/* default: connect the P1.4 nad P1.5 pins with the jumper */
	uint32_t tx_port_num = DT_PROP_BY_IDX(TX_PIN_NODE, gpio_val, 0);
	uint32_t tx_pin = DT_PROP_BY_IDX(TX_PIN_NODE, gpio_val, 1);
	uint32_t rx_port_num = DT_PROP_BY_IDX(RX_PIN_NODE, gpio_val, 0);
	uint32_t rx_pin = DT_PROP_BY_IDX(RX_PIN_NODE, gpio_val, 1);

	GPIO_PRT_Type *tx_port = mtb_stl_get_port_base(tx_port_num);
	GPIO_PRT_Type *rx_port = mtb_stl_get_port_base(rx_port_num);

	Cy_GPIO_Pin_Init(tx_port, tx_pin, &tx_config);
	Cy_GPIO_Pin_Init(rx_port, rx_pin, &rx_config);

	CySCB_Type *scb_block = mtb_stl_get_scb_base(scb_block_num);

	uint8_t res = PASS_STILL_TESTING_STATUS;

	SelfTest_UART_SCB_Init(scb_block);
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

const cy_stc_tcpwm_counter_config_t ifx_timer_config =
{
	.period = DT_PROP(COUNTER_CONFIG_NODE_INTR_TEST, period),
	.clockPrescaler = DT_PROP(COUNTER_CONFIG_NODE_INTR_TEST, clock_prescaler),
	.runMode = DT_PROP(COUNTER_CONFIG_NODE_INTR_TEST, run_mode),
	.countDirection = DT_PROP(COUNTER_CONFIG_NODE_INTR_TEST, count_direction),
	.compareOrCapture = DT_PROP(COUNTER_CONFIG_NODE_INTR_TEST, compare_or_capture),
	.compare0 = DT_PROP(COUNTER_CONFIG_NODE_INTR_TEST, compare0),
	.compare1 = DT_PROP(COUNTER_CONFIG_NODE_INTR_TEST, compare1),
	.enableCompareSwap = false,
	.interruptSources = DT_PROP(COUNTER_CONFIG_NODE_INTR_TEST, interrupt_sources),
	.captureInputMode = 0x7 & 0x3U,
	.captureInput = CY_TCPWM_INPUT_0,
	.reloadInputMode = 0x7 & 0x3U,
	.reloadInput = CY_TCPWM_INPUT_0,
	.startInputMode = 0x7 & 0x3U,
	.startInput = CY_TCPWM_INPUT_0,
	.stopInputMode = 0x7 & 0x3U,
	.stopInput = CY_TCPWM_INPUT_0,
	.countInputMode = 0x7 & 0x3U,
	.countInput = CY_TCPWM_INPUT_1,
};

void Interrupt_test_Init (uint32_t cnt_num)
{
	cy_rslt_t result;
	uint32_t intr_src = DT_PROP(COUNTER_CONFIG_NODE_INTR_TEST, interrupt_sources);
	const uint32_t irq_num = DT_PROP(COUNTER_CONFIG_NODE_INTR_TEST, irq_num);

	IRQ_CONNECT(irq_num, 0, SelfTest_Interrupt_ISR_TIMER, NULL, 0);
	irq_enable(irq_num);

	result = Cy_TCPWM_Counter_Init(TCPWM, cnt_num, &ifx_timer_config);

	if(result != CY_SYSINT_SUCCESS) {
		LOG_ERR("Counter init failed !!!");
	}

	Cy_TCPWM_Counter_Enable(TCPWM, cnt_num);
	Cy_TCPWM_SetInterruptMask(TCPWM, cnt_num, intr_src);
}

static enum post_result mtb_stl_interrupt_wrapper(const struct post_context *ctx)
{
	ARG_UNUSED(ctx);
	uint8_t res;

	Cy_SysClk_PeriphDisableDivider(CY_SYSCLK_DIV_16_BIT, 1U);
	Cy_SysClk_PeriphSetDivider(CY_SYSCLK_DIV_16_BIT, 1U, 3U);
	Cy_SysClk_PeriphEnableDivider(CY_SYSCLK_DIV_16_BIT, 1U);
	Cy_SysClk_PeriphAssignDivider(PCLK_TCPWM_CLOCKS1, CY_SYSCLK_DIV_16_BIT, 1U);

	uint32_t cnt_num = DT_PROP(COUNTER_CONFIG_NODE_INTR_TEST, counter_num);

	Interrupt_test_Init(cnt_num);

	res = SelfTest_Interrupt(TCPWM, cnt_num);

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

const cy_stc_tcpwm_counter_config_t ifx_clk_test_timer_config = {
	.period = DT_PROP(COUNTER_CONFIG_NODE_CLK_TEST, period),
	.clockPrescaler = DT_PROP(COUNTER_CONFIG_NODE_CLK_TEST, clock_prescaler),
	.runMode = DT_PROP(COUNTER_CONFIG_NODE_CLK_TEST, run_mode),
	.countDirection = DT_PROP(COUNTER_CONFIG_NODE_CLK_TEST, count_direction),
	.compareOrCapture = DT_PROP(COUNTER_CONFIG_NODE_CLK_TEST, compare_or_capture),
	.compare0 = DT_PROP(COUNTER_CONFIG_NODE_CLK_TEST, compare0),
	.compare1 = DT_PROP(COUNTER_CONFIG_NODE_CLK_TEST, compare1),
	.enableCompareSwap = false,
	.interruptSources = DT_PROP(COUNTER_CONFIG_NODE_CLK_TEST, interrupt_sources),
	.captureInputMode = 0x7 & 0x3,
	.captureInput = CY_TCPWM_INPUT_0,
	.reloadInputMode = 0x7 & 0x3,
	.reloadInput = CY_TCPWM_INPUT_0,
	.startInputMode = 0x7 & 0x3,
	.startInput = CY_TCPWM_INPUT_0,
	.stopInputMode = 0x7 & 0x3,
	.stopInput = CY_TCPWM_INPUT_0,
	.countInputMode = 0x7 & 0x3,
	.countInput = CY_TCPWM_INPUT_1,
};

static void clock_test_init(uint32_t cnt_num) {
	cy_en_tcpwm_status_t tcpwm_res;
	uint32_t intr_src = DT_PROP(COUNTER_CONFIG_NODE_CLK_TEST, interrupt_sources);

	Cy_WDT_SetIgnoreBits(3U);

	if (Cy_WDT_GetIgnoreBits() != 3U) {
		__ASSERT(0, "IGNORE BITS MISMATCH");
	}

	Cy_WDT_ClearInterrupt();

	Cy_WDT_Enable();
	if (Cy_WDT_IsEnabled() == false) {
		__ASSERT(0, "WDT IS NOT ENABLED");
	}

	tcpwm_res = Cy_TCPWM_Counter_Init(TCPWM, cnt_num, &ifx_clk_test_timer_config);
	if (CY_TCPWM_SUCCESS != tcpwm_res) {
		__ASSERT(0, "TCPWM INIT FAILED !!!");
	};

	Cy_TCPWM_Counter_Enable(TCPWM, cnt_num);
	Cy_TCPWM_SetInterruptMask(TCPWM, cnt_num, intr_src);
}

static enum post_result mtb_stl_clock_wrapper(const struct post_context *ctx)
{
	ARG_UNUSED(ctx);

	const uint32_t irq_num = DT_PROP(COUNTER_CONFIG_NODE_CLK_TEST, irq_num);

	IRQ_CONNECT(irq_num, 0, SelfTest_Clock_ISR_TIMER, NULL, 0);
	irq_enable(irq_num);

	uint8_t res;

	Cy_SysClk_PeriphSetDivider(CY_SYSCLK_DIV_16_BIT, 2, 0);
	Cy_SysClk_PeriphEnableDivider(CY_SYSCLK_DIV_16_BIT, 2);
	Cy_SysClk_PeriphAssignDivider(PCLK_TCPWM_CLOCKS0, CY_SYSCLK_DIV_16_BIT, 2);

	uint32_t cnt_num = DT_PROP(COUNTER_CONFIG_NODE_CLK_TEST, counter_num);

	clock_test_init(cnt_num);

	/* Add timeout to prevent infinite hang */
	uint32_t start = k_cycle_get_32();
	uint32_t timeout_cycles = k_ms_to_cyc_ceil32(100); /* 100ms timeout */

	do {
		res = SelfTest_Clock(TCPWM, cnt_num);
		if ((k_cycle_get_32() - start) > timeout_cycles) {
			return POST_RESULT_FAIL; /* Timeout */
		}
	} while (res == 2);

	Cy_WDT_ClearInterrupt();
	Cy_WDT_Disable();

	return (res == 3) ? POST_RESULT_PASS : POST_RESULT_FAIL;
}
POST_TEST_DEFINE(mtb_stl_clock,
		POST_CAT_CLOCK,
		POST_LEVEL_POST_KERNEL,
		50, 0,
		mtb_stl_clock_wrapper,
		"MTB-STL Clock Frequency Test");
#endif

/* Counter test */
#ifdef CONFIG_POST_MTB_STL_COUNTER

const cy_stc_tcpwm_counter_config_t ifx_timer_counter_config = {
	.period = DT_PROP(COUNTER_CONFIG_NODE_CNT_TEST, period),
	.clockPrescaler = DT_PROP(COUNTER_CONFIG_NODE_CNT_TEST, clock_prescaler),
	.runMode = DT_PROP(COUNTER_CONFIG_NODE_CNT_TEST, run_mode),
	.countDirection = DT_PROP(COUNTER_CONFIG_NODE_CNT_TEST, count_direction),
	.compareOrCapture = DT_PROP(COUNTER_CONFIG_NODE_CNT_TEST, compare_or_capture),
	.compare0 = DT_PROP(COUNTER_CONFIG_NODE_CNT_TEST, compare0),
	.compare1 = DT_PROP(COUNTER_CONFIG_NODE_CNT_TEST, compare1),
	.enableCompareSwap = false,
	.interruptSources = DT_PROP(COUNTER_CONFIG_NODE_CNT_TEST, interrupt_sources),
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

	/* Clock enable */
	Cy_SysClk_PeriphAssignDivider(PCLK_TCPWM_CLOCKS2, CY_SYSCLK_DIV_16_BIT, 1U);
	Cy_SysClk_PeriphSetDivider(CY_SYSCLK_DIV_16_BIT, 1U, 0U);
	Cy_SysClk_PeriphEnableDivider(CY_SYSCLK_DIV_16_BIT, 1U);

	uint32_t cnt_num = DT_PROP(COUNTER_CONFIG_NODE_CNT_TEST, counter_num);
	const uint32_t irq_num = DT_PROP(COUNTER_CONFIG_NODE_CNT_TEST, irq_num);

	/* Call vendor init  */
	SelfTest_Timer_Counter_init(TCPWM, cnt_num, &ifx_timer_counter_config, irq_num);

	/* vendor test */
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

/* PWM_GATEKILL test */
#ifdef CONFIG_POST_MTB_STL_PWM_GATEKILL

const cy_stc_tcpwm_pwm_config_t ifx_pwm_gatekill_config =
{
	.pwmMode = DT_PROP(PWM_CONFIG_NODE_GK_TEST, pwm_mode),
	.clockPrescaler = DT_PROP(PWM_CONFIG_NODE_GK_TEST, clock_prescaler),
	.pwmAlignment = DT_PROP(PWM_CONFIG_NODE_GK_TEST, pwm_alignment),
	.deadTimeClocks = DT_PROP(PWM_CONFIG_NODE_GK_TEST, dead_time_clocks),
	.runMode = DT_PROP(PWM_CONFIG_NODE_GK_TEST, run_mode),
	.period0 = DT_PROP(PWM_CONFIG_NODE_GK_TEST, period0),
	.period1 = DT_PROP(PWM_CONFIG_NODE_GK_TEST, period1),
	.enablePeriodSwap = DT_PROP(PWM_CONFIG_NODE_GK_TEST, enable_period_swap),
	.compare0 = DT_PROP(PWM_CONFIG_NODE_GK_TEST, compare0),
	.compare1 = DT_PROP(PWM_CONFIG_NODE_GK_TEST, compare1),
	.enableCompareSwap = DT_PROP(PWM_CONFIG_NODE_GK_TEST, enable_compare_swap),
	.interruptSources = DT_PROP(PWM_CONFIG_NODE_GK_TEST, interrupt_sources),
	.invertPWMOut = DT_PROP(PWM_CONFIG_NODE_GK_TEST, invert_pwm_out),
	.invertPWMOutN = DT_PROP(PWM_CONFIG_NODE_GK_TEST, invert_pwm_out_n),
	.killMode = DT_PROP(PWM_CONFIG_NODE_GK_TEST, kill_mode),
	.swapInputMode = 0x3U,
	.swapInput = CY_TCPWM_INPUT_0,
	.reloadInputMode = 0x3U,
	.reloadInput = CY_TCPWM_INPUT_0,
	.startInputMode = 0x3U,
	.startInput = CY_TCPWM_INPUT_0,
	.killInputMode = 0x3U,
	.killInput = CY_TCPWM_INPUT_0,
	.countInputMode = 0x3U,
	.countInput = CY_TCPWM_INPUT_1,
};

static enum post_result mtb_stl_pwm_gatekill_wrapper(const struct post_context *ctx)
{
	ARG_UNUSED(ctx);

	uint8_t result;
	uint32_t cnt_num = DT_PROP(PWM_CONFIG_NODE_GK_TEST, pwm_counter_num);

	Cy_SysClk_PeriphAssignDivider(PCLK_TCPWM_CLOCKS4, CY_SYSCLK_DIV_16_BIT, 6U);
	Cy_SysClk_PeriphSetDivider(CY_SYSCLK_DIV_16_BIT, 6U, 0U);
	Cy_SysClk_PeriphEnableDivider(CY_SYSCLK_DIV_16_BIT, 6U);

	if (Cy_TCPWM_PWM_Init(TCPWM, cnt_num, &ifx_pwm_gatekill_config) != CY_TCPWM_SUCCESS) {
		LOG_ERR("PWM_INIT failed");
	}

	Cy_TCPWM_PWM_Enable(TCPWM, cnt_num);

	Cy_TCPWM_TriggerReloadOrIndex(TCPWM, (1UL << cnt_num));

	Cy_TCPWM_TriggerStopOrKill(TCPWM, (1UL << cnt_num));

	result = SelfTest_PWM_GateKill(TCPWM, cnt_num);

	return (result == OK_STATUS) ? POST_RESULT_PASS : POST_RESULT_FAIL;
}

POST_TEST_DEFINE(mtb_stl_pwm_gatekill,
		POST_CAT_PWM_GATEKILL,
		POST_LEVEL_APPLICATION,
		10, 0,
		mtb_stl_pwm_gatekill_wrapper,
		"MTB-STL PWM Gatekill Self-Test");

#endif /* CONFIG_POST_MTB_STL_PWM_GATEKILL */
