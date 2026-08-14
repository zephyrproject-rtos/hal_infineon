/***************************************************************************//**
* \file mtb_device_drivers.h
* \version 1.10
*
* \brief
* Header file that pulls in all driver files that are applicable for this device.
*
********************************************************************************
* \copyright
* Copyright(c) 2024-2026 Infineon Technologies AG or an affiliate of
* Infineon Technologies AG
*
* SPDX-License-Identifier: Apache-2.0
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

#if !defined(MTB_DEVICE_DRIVERS_H)
#define MTB_DEVICE_DRIVERS_H

#include "cy_device.h"
#include "cy_device_headers.h"

#include "cy_canfd.h"
#include "cy_cordic.h"
#include "cy_cryptolite.h"
#include "cy_dma.h"
#include "cy_efuse.h"
#include "cy_flash.h"
#include "cy_gpio.h"
#include "cy_hppass.h"
#include "cy_i3c.h"
#include "cy_ipc_drv.h"
#include "cy_ipc_pipe.h"
#include "cy_ipc_sema.h"
#include "cy_lpcomp.h"
#include "cy_lvd.h"
#include "cy_mcwdt.h"
#include "cy_promc.h"
#include "cy_rtc.h"
#include "cy_scb_ezi2c.h"
#include "cy_scb_i2c.h"
#include "cy_scb_spi.h"
#include "cy_scb_spi_ez.h"
#include "cy_scb_uart.h"
#include "cy_smartio.h"
#include "cy_svgs.h"
#include "cy_sysclk.h"
#include "cy_sysfault.h"
#include "cy_sysint.h"
#include "cy_syslib.h"
#include "cy_syspm.h"
#include "cy_systick.h"
#include "cy_tcpwm.h"
#include "cy_tcpwm_counter.h"
#include "cy_tcpwm_motif.h"
#include "cy_tcpwm_pwm.h"
#include "cy_tcpwm_quaddec.h"
#include "cy_tcpwm_shiftreg.h"
#include "cy_trigmux.h"
#include "cy_wdt.h"

#endif /* MTB_DEVICE_DRIVERS_H */
