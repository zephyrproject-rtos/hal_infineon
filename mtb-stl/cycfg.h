#ifndef CYCFG_H
#define CYCFG_H

#include <zephyr/devicetree.h>

/* Derive IMO frequency from the clk_imo DTS node so this file stays
 * consistent with the board's actual clock configuration. */
#define CY_CFG_SYSCLK_IMO_FREQ_HZ \
	DT_PROP(DT_NODELABEL(clk_imo), clock_frequency)

#define CY_CFG_PWR_VDDA_MV 5000

#endif /* CYCFG_H */
