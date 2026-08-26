/*
 * Copyright (c) 2024 Infineon Technologies AG ,
 * or an affiliate of Infineon Technologies AG.
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#ifndef IFX_AUTANALOG_H
#define IFX_AUTANALOG_H

#include <zephyr/device.h>

int ifx_autanalog_init(void);
int ifx_autanalog_start_sar_autonomous_control(void);
int ifx_autanalog_pause_sar_autonomous_control(void);
void ifx_autanalog_register_adc_handler(void (*handler)(const struct device *dev),
					const struct device *adc_dev);

#endif /* IFX_AUTANALOG_H */
