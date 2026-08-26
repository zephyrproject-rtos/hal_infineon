/*******************************************************************************
 * File Name: cycfg_routing.c
 *
 * Description:
 * Establishes all necessary connections between hardware elements.
 * This file was automatically generated and should not be modified.
 * Configurator Backend 3.80.0
 * device-db 4.39.0.10988
 * ifx-mcuboot-pse84 1.4.0.518
 * ifx-tf-m 2.1.600.18307
 * mtb-dsl-pse8xxgp 1.6.0.1310
 *
 *******************************************************************************
 * Copyright 2026, Infineon Technologies AG, or an affiliate of Infineon
 * Technologies AG. All rights reserved.
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
 ******************************************************************************/

#include "cycfg_routing.h"
#include "cy_trigmux.h"
#include "stdbool.h"
#include "cy_device_headers.h"

void init_cycfg_routing(void)
{
    Cy_TrigMux_Connect(PERI_0_TRIG_IN_MUX_0_SCB_TX_TR_OUT10, PERI_0_TRIG_OUT_MUX_0_PDMA0_TR_IN1, false, TRIGGER_TYPE_LEVEL);
}
