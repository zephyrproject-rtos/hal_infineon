#include <zephyr/kernel.h>
#include <zephyr/irq.h>

#include "cy_sysint.h"

#define MTB_STL_MAX_IRQS 100

static cy_israddress sysint_isr_table[MTB_STL_MAX_IRQS];

/* Zephyr dispatcher */
static void sysint_dispatcher(const void *arg)
{
	IRQn_Type irq = (IRQn_Type)(uintptr_t)arg;

	if ((irq < MTB_STL_MAX_IRQS) && sysint_isr_table[irq]) {
		sysint_isr_table[irq]();   /* Calls static vendor ISR */
	}
}

/*
 * Zephyr replacement for Cypress SysInt
 */
cy_en_sysint_status_t Cy_SysInt_Init(const cy_stc_sysint_t *config, cy_israddress isr)
{
	IRQn_Type irq;

	#if defined(CY_IP_M7CPUSS)
	irq = (IRQn_Type)(config->intrSrc & 0xFFFFU);
	#else
	irq = (IRQn_Type)(config->intrSrc);
	#endif

	if (irq >= MTB_STL_MAX_IRQS) {
		return CY_SYSINT_BAD_PARAM;
	}

	/* Save vendor ISR */
	sysint_isr_table[irq] = isr;

	/* Runtime-safe IRQ connection */
	irq_connect_dynamic(irq, config->intrPriority, sysint_dispatcher,
			(const void *)(uintptr_t)irq, 0);
	irq_enable(irq);

	return CY_SYSINT_SUCCESS;
}
