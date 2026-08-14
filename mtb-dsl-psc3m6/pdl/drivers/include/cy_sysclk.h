/***************************************************************************//**
* \file cy_sysclk.h
* \version 3.150
*
* \brief
* Provides an API declaration of the sysclk driver.
*
********************************************************************************
* \copyright
* Copyright(c) 2016-2026 Infineon Technologies AG or an affiliate of
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


/**
* \addtogroup group_sysclk
* \{
* The System Clock (SysClk) driver contains the API for configuring system and
* peripheral clocks.
*
* The functions and other declarations used in this driver are in cy_sysclk.h.
* You can include cy_pdl.h to get access to all functions
* and declarations in the PDL.
*
* Firmware uses the API to configure, enable, or disable a clock.
*
* The clock system includes a variety of resources that can vary per device, including:
* - Internal clock sources such as internal oscillators
* - External clock sources such as crystal oscillators or a signal on an I/O pin
* - Generated clocks such as a PLL, and peripheral clocks
*
* Consult the Technical Reference Manual for your device for details of the
* clock system.
*
* The PDL defines clock system capabilities in:\n
* devices/include/\<series\>_config.h. (E.g.
* devices/include/pse84_config.h).
*
* The sysclk driver supports multiple peripheral clocks, as well as the fast
* clock, slow clock, backup domain clock, timer clock, and pump clock. The API
* for any given clock contains the functions to manage that clock. Functions
* for clock measurement and trimming are also provided.
*
* \section group_sysclk_configuration Configuration Considerations
* The availability of clock functions depend on the availability of the chip
* resources that support those functions. Consult the device TRM before
* attempting to use these functions.
*
*
* \section group_sysclk_section_secure_aware Secure Aware SysCLK
* Some SysCLK APIs are marked as Secure Aware.  This means that if the clock hardware
* is marked as a secure resource in the Peripheral Protection Controller (PPC) and these
* APIs are called from a non-secure CPU state, the PDL will submit a request to the Secure
* Request Framework (SRF) middleware to transition to a secure CPU state to perform the
* operation.  From the application's perspective, the API will behave the same whether it
* is called from a secure or non-secure CPU state albeit slower.
*
* SysCLK requires that the clock trees are secured upwards. That is, if a peripheral clock divider
* is secured, then the HF clk that sources it must be secured, and then the CLK_PATH and so on.
* The inverse is not true. If a HF clk is secured, the peripheral clock divider can be either
* secured or non-secured. Similarly, if the peripheral clock divider is non-secured, then the HF clk
* can be either secured or non-secured.
*
* This functionality is automatically enabled on devices with ARM TrustZone processors.
* To disable, set the DEFINE+=CY_PDL_ENABLE_SECURE_AWARE_SYSCLK=0 in the application
* Makefile.
*
* For more information on Secure Aware PDL behavior, see \ref group_pdl_srf_general.
*
* \section group_sysclk_more_information More Information
* Refer to the technical reference manual (TRM) and the device datasheet.
*
* \defgroup group_sysclk_macros           Macros
* \{
* \}
* \defgroup group_sysclk_enums           General Enumerated Types
* \{
*   \defgroup group_sysclk_returns         Function return values
* \}
* \defgroup group_sysclk_ext             External Clock Source (EXTCLK)
* \{
*   The External Clock Source (EXTCLK) is a clock source routed into SOC
*   through a GPIO pin. The EXTCLK is a source clock that can be used to
*   source one or more clock paths (Refer to \ref group_sysclk_path_src).
*   These clock paths can then source the processors and peripherals in
*   the device.
*
*   The EXTCLK relies on the presence of an external clock signal applied
*   to the GPIO pin. The pin must be configured to operate in Digital
*   High-Z drive mode with input buffer on and HSIOM connection
*   set to HSIOM_SEL_ACT_4.
*
*   \defgroup group_sysclk_ext_funcs       Functions
* \}
* \defgroup group_sysclk_eco             External Crystal Oscillator (ECO)
* \{
*   The External Crystal Oscillator (ECO) is a clock source that consists
*   of an oscillator circuit that drives an external crystal through its
*   dedicated ECO pins. The ECO is a source clock that can be used to
*   source one or more clock paths (Refer to \ref group_sysclk_path_src).
*   These clock paths can then source the processors and peripherals in
*   the device.
*
*   The ECO relies on the presence of an external crystal. The pins
*   connected to this crystal must be configured to operate in analog
*   drive mode with HSIOM connection set to GPIO control (HSIOM_SEL_GPIO).
*
*
*   \defgroup group_sysclk_eco_macros    Macros
*   \defgroup group_sysclk_eco_funcs     Functions
*   \defgroup group_sysclk_eco_structs   Data Structures
* \}
* \defgroup group_sysclk_path_src           Clock Path Source
* \{
*   Clock paths are a series of multiplexers that allow a source clock
*   to drive multiple clocking resources down the chain. These paths are
*   used for active domain clocks that are not operational during chip
*   Deep Sleep, hibernate and off modes. Illustrated below is a diagram
*   of the clock paths for the PSOC 63 series, showing the first three
*   clock paths. The source clocks for these paths are highlighted in
*   the red box.
*
*   - IMO: 8 MHz Internal Main Oscillator (Default)
*   - EXTCLK: External clock (signal brought in through dedicated pins)
*   - ECO: External Crystal Oscillator (requires external crystal on dedicated pins)
*   - ALTHF: Select on-chip signals (e.g. \ref group_ble_clk)
*   - Digital Signal (DSI): Digital signal from a UDB source
*
*   Some clock paths such as path 0 and path 1 have additional resources
*   that can be utilized to provide a higher frequency clock. For example,
*   path 0 source clock can be used as the reference clock for the FLL and
*   path 1 source clock can be used as the reference clock for the PLL.
*
*   ![](sysclk_path_source.png)
*
*   \note The PDL driver cannot configure a clock path to use Digital Signal
*   Interconnect (DSI) outputs as sources. This must be done through DSI
*   configuration tool such as PSOC Creator.
*
*   \defgroup group_sysclk_path_src_funcs     Functions
*   \defgroup group_sysclk_path_src_enums     Enumerated Types
* \}
* \defgroup group_sysclk_fll             Frequency Locked Loop (FLL)
* \{
*   The FLL is a clock generation circuit that can be used to produce a
*   higher frequency clock from a reference clock. The output clock exhibits
*   some characteristics of the reference clock such as the accuracy of the
*   source. However other attributes such as the clock phase are not preserved.
*   The FLL is similar in purpose to a (Phase locked loop) PLL but they are
*   not equivalent.
*
*   - They may have different frequency ranges.
*   - The FLL starts up (locks) faster and consumes less current than the PLL.
*   - The FLL accepts a source clock with lower frequency than PLL, such as the WCO (32 KHz).
*   - The FLL does not lock phase. The hardware consist of a counter with a
*     current-controlled oscillator (CCO). The counter counts the number of output
*     clock edges in a reference clock period and adjusts the CCO until the
*     expected ratio is achieved (locked). After initial lock, the CCO is
*     adjusted dynamically to keep the ratio within tolerance. The lock tolerance
*     is user-adjustable.
*   ![](sysclk_fll.png)
*
*   The SysClk driver supports two models for configuring the FLL. The first
*   model is to call the Cy_SysClk_FllConfigure() function, which calculates the
*   necessary parameters for the FLL at run-time. This may be necessary for dynamic
*   run-time changes to the FLL. However this method is slow as it needs to perform
*   the calculation before configuring the FLL. The other model is to call
*   Cy_SysClk_FllManualConfigure() function with pre-calculated parameter values.
*   This method is faster but requires prior knowledge of the necessary parameters.
*   Consult the device TRM for the FLL calculation equations.
*
*   \defgroup group_sysclk_fll_funcs       Functions
*   \defgroup group_sysclk_fll_structs     Data Structures
*   \defgroup group_sysclk_fll_enums       Enumerated Types
* \}
* \defgroup group_sysclk_pll             Phase Locked Loop (PLL)
* \{
*   The PLL is a clock generation circuit that can be used to produce a
*   higher frequency clock from a reference clock. The output clock exhibits
*   characteristics of the reference clock such as the accuracy of the source
*   and its phase. The PLL is similar in purpose to a (Frequency locked loop) FLL
*   but they are not equivalent.
*
*   - They may have different frequency ranges.
*   - The PLL starts up more slowly and consumes more current than the FLL.
*   - The PLL requires a higher frequency source clock than FLL.
*   ![](sysclk_pll.png)
*
*   The SysClk driver supports two models for configuring the PLL. The first
*   model is to call the Cy_SysClk_PllConfigure() function, which calculates the
*   necessary parameters for the PLL at run-time. This may be necessary for dynamic
*   run-time changes to the PLL. However this method is slow as it needs to perform
*   the calculation before configuring the PLL. The other model is to call
*   Cy_SysClk_PllManualConfigure() function with pre-calculated parameter values.
*   This method is faster but requires prior knowledge of the necessary parameters.
*   Consult the device TRM for the PLL calculation equations.
*
*   \defgroup group_sysclk_pll_funcs       Functions
*   \defgroup group_sysclk_pll_structs     Data Structures
*   \defgroup group_sysclk_pll_enums       Enumerated Types
* \}
* \defgroup group_sysclk_ilo             Internal Low-Speed Oscillator (ILO)
* \{
*   The ILO operates with no external components and outputs a stable clock at
*   32.768 kHz nominal. The ILO is relatively low power and low accuracy. It is
*   available in all power modes and can be used as a source for the Backup domain clock.
*   ![](sysclk_backup.png)
*
*   To ensure the ILO remains active in Hibernate mode, and across power-on-reset
*   (POR) or brown out detect (BOD), firmware must call Cy_SysClk_IloHibernateOn().
*
*   Additionally, the ILO clock can be trimmed to +/- 1.5% of nominal frequency using
*   a higher precision clock source. Use the \ref group_sysclk_calclk API to measure
*   the current ILO frequency before trimming.
*
*   \note The ILO is always the source clock for the \ref group_wdt. Therefore:
*   - The WDT must be unlocked when making an ILO function call in the PDL
*   - It is recommended to always have the ILO enabled
*
*   \defgroup group_sysclk_ilo_funcs       Functions
* \}
* \defgroup group_sysclk_pilo            Precision Internal Low-Speed Oscillator (PILO)
* \{
*   PILO provides a higher accuracy 32.768 kHz clock than the \ref group_sysclk_ilo "ILO".
*   When periodically calibrated using a high-accuracy clock such as the
*   \ref group_sysclk_eco "ECO", the PILO can achieve 250 ppm accuracy of nominal frequency.
*   The PILO is capable of operating in device Active, Sleep and Deep-Sleep power modes.
*   It is not available in Hibernate mode.
*
*   The PILO can be used as a source for the \ref group_sysclk_clk_lf. However,
*   because PILO is disabled in Hibernate mode, RTC timers cannot operate in this mode
*   when clocked using the PILO. Instead, either the \ref group_sysclk_ilo "ILO" or
*   \ref group_sysclk_wco "WCO" should be used when hibernate operation is required.
*
*   ![](sysclk_backup.png)
*
*   Periodic calibration to a high-accuracy clock (such as ECO) is required to
*   maintain accuracy. The application should use the functions described in the
*   \ref group_sysclk_calclk API to measure the current PILO frequency before trimming.
*
*   \defgroup group_sysclk_pilo_funcs      Functions
* \}
* \defgroup group_sysclk_calclk          Clock Measurement
* \{
*   These functions measure the frequency of a specified clock relative to a
*   reference clock. They are typically called in the following order:
*
*   1. Specify the measured clock, the count, and the reference clock
*   2. Start the counters
*   3. Wait for the measurement counter to finish counting
*   4. Retrieve the measured frequency
*
*   \note These functions may also be used as part of a clock trimming
*   process. Refer to the \ref group_sysclk_trim "Clock Trim" API.
*
*   \defgroup group_sysclk_calclk_funcs    Functions
*   \defgroup group_sysclk_calclk_enums    Enumerated Types
*   \defgroup group_sysclk_calclk_structs  Data Structures
* \}
* \defgroup group_sysclk_trim            Clock Trim (ILO, PILO)
* \{
*   These functions perform a single trim operation on the ILO or PILO. Each
*   function's parameter is the actual frequency of the clock. To measure the
*   frequency, use the functions described in the \ref group_sysclk_calclk API.
*
*   To trim the clock as close as possible to the target frequency, multiple
*   calls to the trim function may be needed. A typical usage example is to:
*   1. Call the clock measurement functions to get the actual frequency of the clock
*   2. Call the trim function, passing in the measured frequency
*   3. Repeat the above until the trim function reports that the clock is trimmed to within limits.
*
*   \defgroup group_sysclk_trim_funcs      Functions
* \}
* \defgroup group_sysclk_pm              Low Power Callback
* \{
*   Entering and exiting low power modes require compatible clock configurations
*   to be set before entering low power and restored upon wake-up and exit. The
*   SysClk driver provides a Cy_SysClk_DeepSleepCallback() function to support
*   Deep Sleep mode entry.
*
*   This function can be called either by itself before initiating low-power mode
*   entry or it can be used in conjunction with the SysPm driver as a registered
*   callback. To do so, register this function as a callback before calling
*   Cy_SysPm_DeepSleep(). Specify \ref CY_SYSPM_DEEPSLEEP as the callback type,
*   and call Cy_SysPm_RegisterCallback().
*
*   \note If the FLL or PLL source is the ECO, this function must be called.
*
*   \defgroup group_sysclk_pm_funcs        Functions
* \}
* \defgroup group_sysclk_wco             Watch Crystal Oscillator (WCO)
* \{
*   The WCO is a highly accurate 32.768 kHz clock source capable of operating
*   in all power modes (excluding the Off mode). It is the primary clock source for
*   the backup domain clock, which is used by the real-time clock (RTC). The
*   WCO can also be used as a source for the low-frequency clock to support other
*   low power mode peripherals.
*
*   ![](sysclk_backup.png)
*
*   The WCO requires the configuration of the dedicated WCO pins (SRSS_WCO_IN_PIN,
*   SRSS_WCO_OUT_PIN). These must be configured as Analog Hi-Z drive modes and the
*   HSIOM selection set to GPIO. The WCO can also be used in bypass mode, where
*   an external 32.768 kHz square wave is brought in directly through the
*   SRSS_WCO_OUT_PIN pin.
*
*   \defgroup group_sysclk_wco_funcs       Functions
*   \defgroup group_sysclk_wco_enums       Enumerated Types
* \}
* \defgroup group_sysclk_clk_hf          High-Frequency Clocks
* \{
*   Multiple high frequency clocks (CLK_HF) are available in the device. For example,
*   PSOC 63 series has five high-frequency root clocks. Each CLK_HF has a particular
*   connection and chip-specific destination on the device.
*
*   |Name     |Description                                             |
*   |:--------|:-------------------------------------------------------|
*   |CLK_HF[0]| Root clock for CPUs, PERI, and AHB infrastructure      |
*   |CLK_HF[1]| Root clock for the PDM/PCM and I2S audio subsystem     |
*   |CLK_HF[2]| Root clock for the Serial Memory Interface subsystem   |
*   |CLK_HF[3]| Root clock for USB communications                      |
*   |CLK_HF[4]| Clock output on clk_ext pin (when used as an output)   |
*
*   ![](sysclk_hf.png)
*
*   Note this is a particular example. The actual tree may vary depending on the device series.
*   Consult the Technical Reference Manual for your device for details.
*
*   High frequency clocks are sourced by path clocks, which should be configured
*   first. An exception to this rule is CLK_HF[0], which cannot be disabled.
*   This divided clock drives the core processors and the peripherals in the system.
*   In order to update its clock source, CLK_HF[0] source must be selected without
*   disabling the clock.
*
*   ![](sysclk_hf_dist.png)
*
*   \defgroup group_sysclk_clk_hf_funcs    Functions
*   \defgroup group_sysclk_clk_hf_structs  Data Structures
*   \defgroup group_sysclk_clk_hf_enums    Enumerated Types
* \}
* \defgroup group_sysclk_clk_peripheral  Peripherals Clock Dividers
* \{
*   There are multiple peripheral clock dividers that, in effect, create
*   multiple separate peripheral clocks. The available dividers vary per device
*   series.
*  The PSOC™ Edge E84 MCU has 26 peripheral clock dividers:
*
*  - Fourteen 8-bit dividers
*  - Five 16-bit integer dividers
*  - Six 16.5 fractional dividers (16 integer bits, five fractional bits)
*  - One 24.5 fractional divider (24 integer bits, five fractional bits)
*
*
*   The 8-bit and 16-bit dividers are integer dividers. A divider value of 1
*   means the output frequency matches the input frequency (that is, there is
*   no change). Otherwise the frequency is divided by the value of the divider.
*   For example, if the input frequency is 50 MHz, and the divider is value 10,
*   the output frequency is 5 MHz.
*
*   The five fractional bits supports further precision in 1/32nd increments. For
*   example, a divider with an integer value of 3 and a fractional value of
*   4 (4/32) results in a divider of 3.125. Fractional dividers are useful when
*   a high-precision clock is required, for example, for a UART/SPI serial
*   interface.
*
*   ![](sysclk_peri_divs.png)*
*   Each peripheral can connect to any one of the programmable dividers. A
*   particular peripheral clock divider can drive multiple peripherals.
*
*   The SysClk driver also supports phase aligning two peripheral clock dividers using
*   Cy_SysClk_PeriphEnablePhaseAlignDivider(). Alignment works for both integer
*   and fractional dividers. The divider to which a second divider is aligned
*   must already be enabled.
*
*   \defgroup group_sysclk_clk_peripheral_funcs Functions
*   \defgroup group_sysclk_clk_peripheral_enums Enumerated Types
* \}
* \defgroup group_sysclk_clk_peripheral_group  Peripheral Group(MMIO Group) Controls
* \{
*   All the peripherals in the SOC belongs to certain MMIO groups.
*   Below control operations can be done on each MMIO group
*      - MMIO Group level clock division, 8-bit Integer divider
*      - Peripheral Slave Enabling/Disabling
*      - Peripheral Slave Reset Enabling/Disabling
*
*   The 8-bit divider is an integer divider. Actual divider will be (divider + 1).
*   For example with a divider of 0, actual divider = 0 + 1 = 1,means the output
*   frequency matches the input frequency (that is, there is
*   no change). Otherwise the frequency is divided by the value of the (divider + 1).
*   For example, if the input frequency is 50 MHz, and the divider is value 9,
*   the output frequency is 5 MHz i.e. 50/(9+1).
*
*
*   ![](sysclk_peri_group.png)
*
*   \defgroup group_sysclk_clk_peripheral_group_funcs Functions
*   \defgroup group_sysclk_clk_peripheral_group_enums Enumerated Types
* \}
* \defgroup group_sysclk_clk_slow        Slow Clock
* \{
*   The slow clock is the source clock for a low-power processor core.
*   This clock is a divided version of the \ref group_sysclk_clk_peri, which in turn is
*   a divided version of CLK_HF[0] (\ref group_sysclk_clk_hf "HF Clocks"). A divider
*   value of 1~256 can be used to further divide the Peri clock to a desired clock speed
*   for the processor.
*
*   ![](sysclk_slow.png)
*
*   \defgroup group_sysclk_clk_slow_funcs  Functions
* \}
* \defgroup group_sysclk_clk_lf          Low-Frequency Clock
* \{
*   The low-frequency clock is the source clock for the \ref group_mcwdt
*   and can be the source clock for \ref group_sysclk_clk_bak, which drives the
*   \ref group_rtc.
*
*   The low-frequency clock has three possible source clocks:
*   \ref group_sysclk_ilo "ILO", \ref group_sysclk_pilo "PILO", and
*   \ref group_sysclk_wco "WCO".
*
*   ![](sysclk_lf.png)
*
*   \defgroup group_sysclk_clk_lf_funcs    Functions
*   \defgroup group_sysclk_clk_lf_structs  Data Structures
*   \defgroup group_sysclk_clk_lf_enums    Enumerated Types
* \}
* \defgroup group_sysclk_clk_pump        Pump Clock
* \{
*   The pump clock is a clock source used to provide analog precision in low voltage
*   applications. Depending on the usage scenario, it may be required to drive the
*   internal voltage pump for the Continuous Time Block mini (CTBm) in the analog
*   subsystem. The pump clock is a divided clock of one of the clock paths
*   (\ref group_sysclk_path_src).
*
*   \defgroup group_sysclk_clk_pump_funcs  Functions
*   \defgroup group_sysclk_clk_pump_enums  Enumerated Types
* \}
* \defgroup group_sysclk_clk_bak         Backup Domain Clock
* \{
*   The backup domain clock drives the \ref group_rtc.
*   This clock has two possible source clocks: \ref group_sysclk_wco "WCO"
*   or the \ref group_sysclk_clk_lf. In turn the low frequency clock is sourced by
*   \ref group_sysclk_ilo "ILO", \ref group_sysclk_pilo "PILO", or
*   \ref group_sysclk_wco "WCO". Typically the ILO is not suitable as an RTC source,
*   because of its low accuracy. However the ILO does operate in hibernate mode and
*   may be used as an alternative to the WCO with a tradeoff in precision.
*
*   \defgroup group_sysclk_clk_bak_funcs   Functions
*   \defgroup group_sysclk_clk_bak_enums   Enumerated Types
* \}
* \defgroup group_sysclk_mf         Medium Frequency Domain Clock
* \{
*   The Medium Frequency Domain Clock is present only in SRSS_ver1_3.
*   Consists of MFO - the Medium Frequency Oscillator,
*   and CLK_MF - the Medium Frequency Clock divider.
*   This clock chain is designed to source the LCD block
*   in Deep Sleep mode, see \ref cy_en_seglcd_lsclk_t.
*
*   \defgroup group_sysclk_mf_funcs   Functions
*   \defgroup group_sysclk_mf_enums    Enumerated Types
* \}
* \defgroup group_sysclk_iho         Internal High Frequency(IHO) Clock
* \{
*   The IHO Clock is Internal High-speed Oscillator, which is present in PSC(48MHz)
*   and PSE8(50MHz) devices.
*
*   \defgroup group_sysclk_iho_funcs   Functions
* \}
* \defgroup group_sysclk_imo         Internal Main Oscillator(IMO) Clock
* \{
*   The IMO Clock is Internal Main Oscillator.
*   The IMO frequency is 8MHz.
*
*   \defgroup group_sysclk_imo_funcs   Functions
* \}
* \defgroup group_sysclk_clk_pwr         Power Clock
* \{
*   Clock for the power architecture components.

*   \defgroup group_sysclk_clk_pwr_funcs   Functions
*   \defgroup group_sysclk_clk_pwr_enums    Enumerated Types
* \}
*/

#if !defined (CY_SYSCLK_H)
#define CY_SYSCLK_H

#include "cy_device.h"

#if defined (CY_IP_MXS28SRSS) || defined (CY_IP_MXS40SRSS) || defined (CY_IP_MXS40SSRSS) || defined (CY_IP_MXS22SRSS)
#include <stdbool.h>
#include "cy_syslib.h"
#include "cy_syspm.h"

#if defined(CY_DEVICE_SECURE)
#include "cy_pra.h"
#endif /* defined(CY_DEVICE_SECURE) */

#include "cy_pdl_srf.h"
#include "cy_pdl_srf_common.h"

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/**
* \addtogroup group_sysclk_macros
* \{
*/
/** Driver major version */
#define  CY_SYSCLK_DRV_VERSION_MAJOR   3
/** Driver minor version */
#define  CY_SYSCLK_DRV_VERSION_MINOR   150
/** Sysclk driver identifier */
#define CY_SYSCLK_ID   CY_PDL_DRV_ID(CY_PDL_RSLT_MODULE_SYSCLK)

/** ILO clock frequency */
#define CY_SYSCLK_ILO_FREQ  (32768UL)   /* Hz */
/** WCO clock frequency */
#define CY_SYSCLK_WCO_FREQ  (32768UL)   /* Hz */
/** PILO clock frequency */
#define CY_SYSCLK_PILO_FREQ (32768UL)   /* Hz */

/** IMO clock frequency */
#define CY_SYSCLK_IMO_FREQ  (8000000UL) /* Hz */

/** MFO clock frequency */
#define CY_SYSCLK_MFO_FREQ  (2000000UL) /* Hz */

/** CY_SYSCLK_PILO_TRIM_STEP is the default PILO TRIM Step value */
#define CY_SYSCLK_PILO_TRIM_STEP  (5UL) /* Default PILO TRIM Step size */

#if defined (CY_IP_MXS40SSRSS) || defined (CY_IP_MXS28SRSS)
#define CY_SYSCLK_IHO_FREQ  (48000000UL) /* Hz */
#endif





#if defined (CY_IP_MXS40SSRSS)|| defined (CY_IP_MXS22SRSS)
/** FLL BYPASS configure Delay , As per SAS
* "When changing BYPASS_SEL, do not turn off the reference clock
* or CCO clock for ten cycles (whichever is slower)"
* Slower if IMO, so delay = (10 * 1/(IMO freq in Mhz))  = 1.25 micro seconds,
* approximated to 2 micro second
 **/
#define CY_SYSCLK_BYPASS_CONFIGURE_DELAY  (2UL) /* micro seconds */

/** FLL Disable Timeout value
**/
#define CY_SYSCLK_FLL_DISABLE_TIMEOUT     (100UL) /* micro seconds */

#endif


/*******************************************************************************
*       Internal Defines
*******************************************************************************/

#if defined (CY_IP_MXS40SSRSS) && (defined (SRSS_ECO_PRESENT) && ((SRSS_ECO_PRESENT) > 0))
/* Macro to validate parameters in Cy_SysClk_ClkPathSetSource() function */
#define CY_SYSCLK_IS_CLKPATH_SOURCE_VALID(clkSrc)        (((clkSrc) == CY_SYSCLK_CLKPATH_IN_IMO)  || \
                                                         ((clkSrc) == CY_SYSCLK_CLKPATH_IN_EXT)   || \
                                                         ((clkSrc) == CY_SYSCLK_CLKPATH_IN_ECO)   || \
                                                         ((clkSrc) == CY_SYSCLK_CLKPATH_IN_ALTHF) || \
                                                         ((clkSrc) == CY_SYSCLK_CLKPATH_IN_IHO)   || \
                                                         ((clkSrc) == CY_SYSCLK_CLKPATH_IN_ILO)   || \
                                                         ((clkSrc) == CY_SYSCLK_CLKPATH_IN_WCO)   || \
                                                         ((clkSrc) == CY_SYSCLK_CLKPATH_IN_PILO))
#elif defined (CY_IP_MXS40SSRSS)
/* Macro to validate parameters in Cy_SysClk_ClkPathSetSource() function */
#define CY_SYSCLK_IS_CLKPATH_SOURCE_VALID(clkSrc)        (((clkSrc) == CY_SYSCLK_CLKPATH_IN_IMO) || \
                                                         ((clkSrc) == CY_SYSCLK_CLKPATH_IN_EXT)  || \
                                                         ((clkSrc) == CY_SYSCLK_CLKPATH_IN_ALTHF) || \
                                                         ((clkSrc) == CY_SYSCLK_CLKPATH_IN_ECO) || \
                                                         ((clkSrc) == CY_SYSCLK_CLKPATH_IN_IHO)  || \
                                                         ((clkSrc) == CY_SYSCLK_CLKPATH_IN_ILO)  || \
                                                         ((clkSrc) == CY_SYSCLK_CLKPATH_IN_WCO) || \
                                                         ((clkSrc) == CY_SYSCLK_CLKPATH_IN_PILO))
#endif /* #if defined (CY_IP_MXS40SSRSS) && (defined (SRSS_ECO_PRESENT) && ((SRSS_ECO_PRESENT) > 0)) */

/** \} group_sysclk_macros */


/**
* \addtogroup group_sysclk_returns
* \{
*/
/** Defines general-purpose function return values */
typedef enum
{
    CY_SYSCLK_SUCCESS           = 0x00UL, /**< Command completed with no errors */
    CY_SYSCLK_BAD_PARAM         = (CY_SYSCLK_ID | CY_PDL_STATUS_ERROR | 0x01UL), /**< Invalid function input parameter */
    CY_SYSCLK_TIMEOUT           = (CY_SYSCLK_ID | CY_PDL_STATUS_ERROR | 0x02UL), /**< Timeout occurred */
    CY_SYSCLK_INVALID_STATE     = (CY_SYSCLK_ID | CY_PDL_STATUS_ERROR | 0x03UL), /**< Clock is in an invalid state */
    CY_SYSCLK_UNSUPPORTED_STATE = (CY_SYSCLK_ID | CY_PDL_STATUS_ERROR | 0x04UL) /**< Feature Unsupported */
} cy_en_sysclk_status_t;
/** \} group_sysclk_returns */


/* ========================================================================== */
/* ===========================    EXT SECTION    ============================ */
/* ========================================================================== */


/**
* \addtogroup group_sysclk_ext_funcs
* \{
*/
/*******************************************************************************
* Function Name: Cy_SysClk_ExtClkSetFrequency
****************************************************************************//**
*
* Sets the signal frequency of the External Clock Source (EXTCLK) into the
* internal storage to be used in \ref Cy_SysClk_ClkHfGetFrequency.
*
* \param freq The frequency of the External Clock Source.
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_ExtClkSetFrequency
*
*******************************************************************************/
void Cy_SysClk_ExtClkSetFrequency(uint32_t freq);


/*******************************************************************************
* Function Name: Cy_SysClk_ExtClkGetFrequency
****************************************************************************//**
*
* Returns the frequency of the External Clock Source (EXTCLK) from the
* internal storage.
*
* \return The frequency of the External Clock Source.
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_ExtClkSetFrequency
*
*******************************************************************************/
uint32_t Cy_SysClk_ExtClkGetFrequency(void);
/** \} group_sysclk_ext_funcs */

/* ========================================================================== */
/* ===========================    ECO SECTION    ============================ */
/* ========================================================================== */

/**
* \addtogroup group_sysclk_eco_macros
* \{
*/

/**
* \defgroup group_sysclk_ecostatus ECO status
* \{
* Constants used for expressing ECO status.
*/
#define CY_SYSCLK_ECOSTAT_UNUSABLE       0UL /**< \brief ECO does not have sufficient amplitude and not stable power */
#define CY_SYSCLK_ECOSTAT_OK             1UL /**< \brief ECO has sufficient amplitude but may not be meeting accuracy and duty cycle specifications */
#define CY_SYSCLK_ECOSTAT_READY          2UL /**< \brief ECO has sufficient time to stabilize it's power */
#define CY_SYSCLK_ECOSTAT_OK_AND_READY   3UL /**< \brief ECO has fully stabilized */


/** \} group_sysclk_ecostatus */

/** \cond internal */
/* Kept it for Backward compatibility */
#define CY_SYSCLK_ECOSTAT_AMPLITUDE      CY_SYSCLK_ECOSTAT_UNUSABLE
#define CY_SYSCLK_ECOSTAT_INACCURATE     CY_SYSCLK_ECOSTAT_OK
#define CY_SYSCLK_ECOSTAT_STABLE         CY_SYSCLK_ECOSTAT_OK_AND_READY
/** \endcond */


/** \} group_sysclk_eco_macros */

# if (defined (CY_DEVICE_SECURE))
/**
* \addtogroup group_sysclk_eco_structs
* \{
*/
/** PRA structure for Cy_SysClk_EcoConfigure function parameters */
typedef struct
{
    uint32_t praClkEcofreq;                           /**< freq */
    uint32_t praCsum;                           /**< cSum */
    uint32_t praEsr;                             /**< esr */
    uint32_t praDriveLevel;                     /**< drivelevel */
} cy_stc_pra_clk_eco_configure_t;
/** \} group_sysclk_eco_structs */
#endif /* (defined (CY_DEVICE_SECURE)) */

#if defined (CY_IP_MXS40SRSS)  || defined (CY_IP_MXS22SRSS) || (defined (CY_IP_MXS40SSRSS) && (SRSS_ECO_PRESENT == 1UL))
/** \cond */
#define SRSS_CLK_ECO_STATUS_Msk (SRSS_CLK_ECO_STATUS_ECO_OK_Msk | SRSS_CLK_ECO_STATUS_ECO_READY_Msk)
/** \endcond */
#endif /* defined (CY_IP_MXS40SRSS)  || defined (CY_IP_MXS22SRSS) || (defined (CY_IP_MXS40SSRSS) && (SRSS_ECO_PRESENT == 1UL)) */



/**
* \addtogroup group_sysclk_eco_funcs
* \{
*/
#if (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION < 2)) || (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION >= 3)) || defined (CY_IP_MXS22SRSS) || \
     (defined (CY_IP_MXS40SSRSS) && (SRSS_ECO_PRESENT == 1UL)) || defined (CY_DOXYGEN)
/*******************************************************************************
* Function Name: Cy_SysClk_EcoSetFrequency
****************************************************************************//**
*
* Stores the external crystal oscillator (ECO) frequency in a global variable
* within Sysclk driver.
*
* \param freq Operating frequency of the crystal in Hz.
* Valid range: 16000000...35000000 (16..35 MHz).
*
*******************************************************************************/
void Cy_SysClk_EcoSetFrequency(uint32_t freq);
#endif /* (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION < 2)) */

 #if defined (CY_IP_MXS40SRSS) || defined (CY_IP_MXS22SRSS) || (defined (CY_IP_MXS40SSRSS) && (SRSS_ECO_PRESENT == 1UL))


#if !defined (CY_IP_MXS22SRSS) || defined(CY_DOXYGEN)
/*******************************************************************************
* Function Name: Cy_SysClk_EcoConfigure
****************************************************************************//**
*
* Configures the external crystal oscillator (ECO) trim bits based on crystal
* characteristics. This function should be called only when the ECO is disabled.
*
* \param freq Operating frequency of the crystal in Hz.
* Valid range: 16000000...35000000 (16..35 MHz).
*
* \param cSum The summary capacitance of
* C0 (the crystal itself shunt capacitance) and
* Cload (the parallel load capacitance), in pF.
* So cSum = C0 + Cload.
* Valid range: 1...100.
* \note
* cSum stands for crystal load capacitance in pF.
*
* \param esr Effective series resistance of the crystal in Ohms.
* Valid range: 1...1000.
*
* \param driveLevel Crystal drive level in uW.
* Valid range: 1...2000.
*
* \return Error / status code: \n
* CY_SYSCLK_SUCCESS - ECO configuration completed successfully \n
* CY_SYSCLK_BAD_PARAM - One or more invalid parameters \n
* CY_SYSCLK_INVALID_STATE - ECO already enabled
* \note Behavior of this API is IP dependent. \n
*
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_EcoConfigure
*
*******************************************************************************/
cy_en_sysclk_status_t Cy_SysClk_EcoConfigure(uint32_t freq, uint32_t cSum, uint32_t esr, uint32_t driveLevel);

#endif /* !defined (CY_IP_MXS22SRSS) || defined(CY_DOXYGEN) */


/*******************************************************************************
* Function Name: Cy_SysClk_EcoEnable
****************************************************************************//**
*
* Enables the external crystal oscillator (ECO). This function should be called
* after \ref Cy_SysClk_EcoConfigure.
*
* \param timeoutus Amount of time in microseconds to wait for the ECO to stabilize.
* To avoid waiting for stabilization, set this parameter to 0.
*
* \return Error / status code: \n
* CY_SYSCLK_SUCCESS - ECO locked \n
* CY_SYSCLK_TIMEOUT - ECO timed out and did not lock \n
* CY_SYSCLK_INVALID_STATE - ECO already enabled \n
* CY_SYSCLK_UNSUPPORTED_STATE - ECO is not present
*
* \note
* Call \ref SystemCoreClockUpdate after this function calling
* if it affects the CLK_HF0 frequency.
*
* \note
* Take into account the possible platform specific clkHf (and further
* clocking chain links) frequency limitations while using this API.
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_EcoEnable
*
*******************************************************************************/
cy_en_sysclk_status_t Cy_SysClk_EcoEnable(uint32_t timeoutus);

/*******************************************************************************
* Function Name: Cy_SysClk_EcoGetFrequency
****************************************************************************//**
*
* Returns the frequency of the external crystal oscillator (ECO).
*
* \return The frequency of the ECO.
*
* \note If the ECO is not enabled or stable - a zero is returned.
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_EcoEnable
*
*******************************************************************************/
uint32_t Cy_SysClk_EcoGetFrequency(void);

/*******************************************************************************
* Function Name: Cy_SysClk_EcoDisable
****************************************************************************//**
*
* Disables the external crystal oscillator (ECO). This function should not be
* called if the ECO is sourcing clkHf[0].
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_EcoDisable
*
*******************************************************************************/
void Cy_SysClk_EcoDisable(void);


/*******************************************************************************
* Function Name: Cy_SysClk_EcoGetStatus
****************************************************************************//**
*
* Reports the current status of the external crystal oscillator (ECO).
*
* \return
* CY_SYSCLK_ECOSTAT_UNUSABLE = ECO does not have sufficient amplitude \n
* CY_SYSCLK_ECOSTAT_OK = ECO has sufficient amplitude but may not be meeting accuracy and duty cycle specifications \n
* CY_SYSCLK_ECOSTAT_READY = ECO has sufficient time to stabilize it's power \n
* CY_SYSCLK_ECOSTAT_OK_AND_READY = ECO has fully stabilized
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_EcoGetStatus
*
*******************************************************************************/
uint32_t Cy_SysClk_EcoGetStatus(void);
#endif /* defined (CY_IP_MXS40SRSS) || defined (CY_IP_MXS22SRSS) || (defined (CY_IP_MXS40SSRSS) && (SRSS_ECO_PRESENT == 1UL)) */

#if (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION >= 2)) || defined (CY_IP_MXS22SRSS) || (defined (CY_IP_MXS40SSRSS) && (SRSS_ECO_PRESENT == 1UL))

/*******************************************************************************
* Function Name: Cy_SysClk_EcoPrescaleConfigure
****************************************************************************//**
*
* Configures the external crystal oscillator (ECO) using ECO Prescaler
* Configuration Register and derives clk_eco_prescaler
*
* \param enable ECO Prescaler enable/disable.
*
* \param int_div 10-bit integer value.
*
* \param frac_div 8-bit fraction value.
*
* \return Error / status code: \n
* CY_SYSCLK_SUCCESS - ECO configuration completed successfully \n
* CY_SYSCLK_BAD_PARAM - One or more invalid parameters \n
* CY_SYSCLK_INVALID_STATE - ECO already enabled \n
* CY_SYSCLK_UNSUPPORTED_STATE - ECO is not present
*
*******************************************************************************/
cy_en_sysclk_status_t Cy_SysClk_EcoPrescaleConfigure(uint32_t enable, uint32_t int_div, uint32_t frac_div);

/*******************************************************************************
* Function Name: Cy_SysClk_EcoPrescaleIsEnabled
****************************************************************************//**
*
* Reports whether or not ECO Prescale is enabled.
*
* \return
* false = disabled \n
* true = enabled
*
*******************************************************************************/
bool Cy_SysClk_EcoPrescaleIsEnabled(void);


/*******************************************************************************
* Function Name: Cy_SysClk_EcoPrescaleGetFrequency
****************************************************************************//**
*
* Returns the frequency of the external crystal oscillator (ECO) prescaler.
*
* \return The frequency of the ECO Prescaler.
*
* \note If the ECO is not enabled or stable - a zero is returned.
*
*******************************************************************************/
uint32_t Cy_SysClk_EcoPrescaleGetFrequency(void);

#endif /* (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION >= 2)) || defined (CY_IP_MXS22SRSS) || (defined (CY_IP_MXS40SSRSS) && (SRSS_ECO_PRESENT == 1UL))*/


/** \} group_sysclk_eco_funcs */



/* ========================================================================== */
/* ====================    INPUT MULTIPLEXER SECTION    ===================== */
/* ========================================================================== */
/**
* \addtogroup group_sysclk_path_src_enums
* \{
*/
/**
*   Input multiplexer clock sources
*/


typedef enum
{
#if defined(CY_DOXYGEN)
    CY_SYSCLK_CLKPATH_IN_IHO,    /**< Select the IHO as the output of the path mux */
    CY_SYSCLK_CLKPATH_IN_EXT,    /**< Select the EXT as the output of the path mux */
    CY_SYSCLK_CLKPATH_IN_ECO,    /**< Select the ECO as the output of the path mux */
    CY_SYSCLK_CLKPATH_IN_IMO,    /**< Select the IMO as the output of the path mux */
    CY_SYSCLK_CLKPATH_IN_ALTHF   /**< Same as CY_SYSCLK_CLKPATH_IN_ALTHF0 */
    CY_SYSCLK_CLKPATH_IN_ALTHF0, /**< Select the ALTHF0 as the output of the path mux */
    CY_SYSCLK_CLKPATH_IN_ALTHF1, /**< Select the ALTHF1 as the output of the path mux */
    CY_SYSCLK_CLKPATH_IN_LPECO,  /**< Select the LPECO as the output of the path mux */
    CY_SYSCLK_CLKPATH_IN_DSIMUX, /**< Select the DSI MUX output as the output of the path mux */
    CY_SYSCLK_CLKPATH_IN_DSI,    /**< Select a DSI signal (0 - 15) as the output of the DSI mux and path mux.
                                            *   Make sure the DSI clock sources are available on used device.
                                            */
    CY_SYSCLK_CLKPATH_IN_ILO,    /**< Select the ILO (16) as the output of the DSI mux and path mux */
    CY_SYSCLK_CLKPATH_IN_ILO0,   /**< Select the ILO0 (16) as the output of the DSI mux and path mux */
    CY_SYSCLK_CLKPATH_IN_WCO,    /**< Select the WCO (17) as the output of the DSI mux and path mux */
    CY_SYSCLK_CLKPATH_IN_ALTLF,  /**< Select the ALTLF (18) as the output of the DSI mux and path mux.
                                            *   Make sure the ALTLF clock sources in available on used device.
                                            */
    CY_SYSCLK_CLKPATH_IN_PILO,   /**< Select the PILO (19) as the output of the DSI mux and path mux.
                                            *   Make sure the PILO clock sources in available on used device. */
    CY_SYSCLK_CLKPATH_IN_ILO1,   /**< Select the ILO1 (20) as the output of the DSI mux and path mux */

#elif defined (CY_IP_MXS40SSRSS)
    CY_SYSCLK_CLKPATH_IN_IMO    =     0U, /**< Select the IMO as the output of the path mux */
    CY_SYSCLK_CLKPATH_IN_EXT    =     1U, /**< Select the EXT as the output of the path mux */
    CY_SYSCLK_CLKPATH_IN_ECO    =     2U, /**< Select the ECO as the output of the path mux */
    CY_SYSCLK_CLKPATH_IN_ALTHF  =     3U, /**< Select the ALTHF as the output of the path mux */
    CY_SYSCLK_CLKPATH_IN_DSIMUX =     4U, /**< Select the DSI MUX output as the output of the path mux */
    CY_SYSCLK_CLKPATH_IN_LPECO  =     5U, /**< Select the LPECO as the output of the path mux */
    CY_SYSCLK_CLKPATH_IN_IHO    =     6U, /**< Select the IHO as the output of the path mux */
    CY_SYSCLK_CLKPATH_IN_DSI    = 0x100U, /**< Select a DSI signal (0 - 15) as the output of the DSI mux and path mux.
                                           *   Make sure the DSI clock sources are available on used device.
                                           */
    CY_SYSCLK_CLKPATH_IN_ILO    = 0x110U, /**< Select the ILO (16) as the output of the DSI mux and path mux */
    CY_SYSCLK_CLKPATH_IN_WCO    = 0x111U, /**< Select the WCO (17) as the output of the DSI mux and path mux */
    CY_SYSCLK_CLKPATH_IN_ALTLF  = 0x112U, /**< Select the ALTLF (18) as the output of the DSI mux and path mux.
                                           *   Make sure the ALTLF clock sources in available on used device.
                                           */
    CY_SYSCLK_CLKPATH_IN_PILO   = 0x113U, /**< Select the PILO (19) as the output of the DSI mux and path mux.
                                           *   Make sure the PILO clock sources in available on used device.
                                           */
    CY_SYSCLK_CLKPATH_IN_ILO1   = 0x114U, /**< Select the ILO1 (20) as the output of the DSI mux and path mux */
#endif
} cy_en_clkpath_in_sources_t;


#if (defined(CY_DEVICE_SECURE))
/** PRA structure for Cy_SysClk_ClkPathSetSource function parameters */
typedef struct
{
    uint32_t                          clk_path;      /**< clkpath  */
    cy_en_clkpath_in_sources_t         source;        /**< Source */
} cy_stc_pra_clkpathsetsource_t;
#endif /* (defined(CY_DEVICE_SECURE)) */

/** \} group_sysclk_path_src_enums */

/**
* \addtogroup group_sysclk_path_src_funcs
* \{
*/
/*******************************************************************************
* Function Name: Cy_SysClk_ClkPathSetSource
****************************************************************************//**
*
* Configures the source for the specified clock path.
*
* \param clkPath Selects which clock path to configure; 0 is the first clock
* path, which is the FLL.
*
* \param source \ref cy_en_clkpath_in_sources_t
*
* \return \ref cy_en_sysclk_status_t
*
* \note
* If calling this function changes an FLL or PLL input frequency, disable the FLL
* or PLL before calling this function. After calling this function, call the FLL
* or PLL configure function, for example \ref Cy_SysClk_FllConfigure().
*
* \note
* Call \ref SystemCoreClockUpdate after this function calling
* if it affects the CLK_HF0 frequency.
*
* \note
* Call \ref Cy_SysLib_SetWaitStates before calling this function if
* it affects the CLK_HF0 frequency and the frequency is increasing.
*
* \note
* Call \ref Cy_SysLib_SetWaitStates after calling this function if
* it affects the CLK_HF0 frequency and the frequency is decreasing.
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_ClkPathSetSource
*
* \note
* Take into account the possible platform specific clkHf (and further
* clocking chain links) frequency limitations while using this API.
*
* \note  It takes four cycles of the originally selected clock to switch away
* from it.  Do not disable the original clock during this time.
*
*******************************************************************************/
cy_en_sysclk_status_t Cy_SysClk_ClkPathSetSource(uint32_t clkPath, cy_en_clkpath_in_sources_t source);


/*******************************************************************************
* Function Name: Cy_SysClk_ClkPathGetSource
****************************************************************************//**
*
* Reports which source is selected for the path mux.
*
* \param clkPath Selects which clock path to report; 0 is the first clock path,
* which is the FLL.
*
* \return \ref cy_en_clkpath_in_sources_t
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_ClkPathGetSource
*
*******************************************************************************/
cy_en_clkpath_in_sources_t Cy_SysClk_ClkPathGetSource(uint32_t clkPath);


/*******************************************************************************
* Function Name: Cy_SysClk_ClkPathMuxGetFrequency
****************************************************************************//**
*
* Returns the output frequency of the clock path mux.
*
* \return The output frequency of the path mux.
*
* \note If the return value equals zero, that means either:
* - the selected path mux source signal frequency is unknown (e.g. dsi_out, etc.) or
* - the selected path mux source is not configured/enabled/stable (e.g. ECO, EXTCLK, etc.).
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_ClkPathSetSource
*
*******************************************************************************/
uint32_t Cy_SysClk_ClkPathMuxGetFrequency(uint32_t clkPath);


/*******************************************************************************
* Function Name: Cy_SysClk_ClkPathGetFrequency
****************************************************************************//**
*
* Returns the output frequency of the clock path mux.
*
* \return The output frequency of the path mux.
*
* \note If the return value equals zero, that means either:
* - the selected path mux source signal frequency is unknown (e.g. dsi_out, etc.) or
* - the selected path mux source is not configured/enabled/stable (e.g. ECO, EXTCLK, etc.).
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_FllEnable
*
*******************************************************************************/
uint32_t Cy_SysClk_ClkPathGetFrequency(uint32_t clkPath);
/** \} group_sysclk_path_src_funcs */


/* ========================================================================== */
/* ===========================    FLL SECTION    ============================ */
/* ========================================================================== */
/**
* \addtogroup group_sysclk_fll_enums
* \{
*/
/** FLL and PLL output mode.
* See registers CLK_FLL_CONFIG3 and CLK_PLL_CONFIG0, bits BYPASS_SEL.
*/
typedef enum
{
    CY_SYSCLK_FLLPLL_OUTPUT_AUTO   = 0U, /**< Output FLL/PLL input source when not locked, and FLL/PLL output when locked */
    CY_SYSCLK_FLLPLL_OUTPUT_AUTO1  = 1U, /**< Same as AUTO */
    CY_SYSCLK_FLLPLL_OUTPUT_INPUT  = 2U, /**< Output FLL/PLL input source regardless of lock status */
    CY_SYSCLK_FLLPLL_OUTPUT_OUTPUT = 3U  /**< Output FLL/PLL output regardless of lock status. This can be dangerous if used to clock clkHf, because FLL/PLL output may be unstable */
} cy_en_fll_pll_output_mode_t;

#if defined (CY_IP_MXS40SRSS) || defined (CY_IP_MXS40SSRSS) || defined (CY_DOXYGEN)
/** FLL current-controlled oscillator (CCO) frequency ranges.
* See register CLK_FLL_CONFIG4, bits CCO_RANGE.
*/
typedef enum
{
    CY_SYSCLK_FLL_CCO_RANGE0, /**< Target frequency is in range  48 -  64 MHz */
    CY_SYSCLK_FLL_CCO_RANGE1, /**< Target frequency is in range  64 -  85 MHz */
    CY_SYSCLK_FLL_CCO_RANGE2, /**< Target frequency is in range  85 - 113 MHz */
    CY_SYSCLK_FLL_CCO_RANGE3, /**< Target frequency is in range 113 - 150 MHz */
    CY_SYSCLK_FLL_CCO_RANGE4  /**< Target frequency is in range 150 - 200 MHz */
} cy_en_fll_cco_ranges_t;
#endif /* defined (CY_IP_MXS40SRSS) || defined (CY_IP_MXS40SSRSS) || defined (CY_DOXYGEN) */
 /** \} group_sysclk_fll_enums */

#if defined (CY_IP_MXS40SRSS) || defined (CY_IP_MXS40SSRSS) || defined (CY_DOXYGEN)

/**
* \addtogroup group_sysclk_fll_structs
* \{
*/
/** Structure containing information for manual configuration of FLL.
*/
typedef struct
{
    uint32_t                    fllMult;         /**< CLK_FLL_CONFIG  register, FLL_MULT bits */
    uint16_t                    refDiv;          /**< CLK_FLL_CONFIG2 register, FLL_REF_DIV bits */
    cy_en_fll_cco_ranges_t      ccoRange;        /**< CLK_FLL_CONFIG4 register, CCO_RANGE bits */
    bool                        enableOutputDiv; /**< CLK_FLL_CONFIG  register, FLL_OUTPUT_DIV bit */
    uint16_t                    lockTolerance;   /**< CLK_FLL_CONFIG2 register, LOCK_TOL bits */
    uint8_t                     igain;           /**< CLK_FLL_CONFIG3 register, FLL_LF_IGAIN bits */
    uint8_t                     pgain;           /**< CLK_FLL_CONFIG3 register, FLL_LF_PGAIN bits */
    uint16_t                    settlingCount;   /**< CLK_FLL_CONFIG3 register, SETTLING_COUNT bits */
    cy_en_fll_pll_output_mode_t outputMode;      /**< CLK_FLL_CONFIG3 register, BYPASS_SEL bits */
    uint16_t                    cco_Freq;        /**< CLK_FLL_CONFIG4 register, CCO_FREQ bits */
} cy_stc_fll_manual_config_t;

/** \} group_sysclk_fll_structs */

/**
* \addtogroup group_sysclk_fll_funcs
* \{
*//*******************************************************************************
* Function Name: Cy_SysClk_FllConfigure
****************************************************************************//**
*
* Configures the FLL, for best accuracy optimization.
*
* \param inputFreq frequency of input source, in Hz
*
* \param outputFreq Desired FLL output frequency, in Hz. Allowable range is
* 24 MHz to 100 MHz. In all cases, FLL_OUTPUT_DIV must be set; the output divide
* by 2 option is required.
*
* \param outputMode \ref cy_en_fll_pll_output_mode_t
* If output mode is bypass, then the output frequency equals the input source
* frequency regardless of the frequency parameter values.
*
* \return  Error / status code: \n
* CY_SYSCLK_SUCCESS - FLL successfully configured \n
* CY_SYSCLK_INVALID_STATE - FLL not configured because it is enabled \n
* CY_SYSCLK_BAD_PARAM - desired output frequency is out of valid range \n
* CY_SYSCLK_UNSUPPORTED_STATE - FLL is not present
*
* \note
* Call this function after changing the FLL input frequency, for example if
* \ref Cy_SysClk_ClkPathSetSource() is called.
*
* \note
* Do not call this function when the FLL is enabled. If it is called, then this function
* returns with an CY_SYSCLK_INVALID_STATE return value and no register updates.
*
* \note
* Call \ref SystemCoreClockUpdate after this function calling
* if it affects the CLK_HF0 frequency.
*
* \note
* Call \ref Cy_SysLib_SetWaitStates before calling this function if
* the FLL is the source of CLK_HF0 and the FLL frequency is increasing.
*
* \note
* Call \ref Cy_SysLib_SetWaitStates after calling this function if
* the FLL is the source of CLK_HF0 and the FLL frequency is decreasing.
*
* \note
* On PSOC 64 devices the configuration on the PRA driver will be reflected
* after \ref Cy_SysClk_FllEnable call. Any call to \ref Cy_SysClk_FllGetConfiguration
* before calling \ref Cy_SysClk_FllEnable returns old configuration values.
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_FllConfigure
*
*******************************************************************************/
cy_en_sysclk_status_t Cy_SysClk_FllConfigure(uint32_t inputFreq, uint32_t outputFreq, cy_en_fll_pll_output_mode_t outputMode);


/*******************************************************************************
* Function Name: Cy_SysClk_FllManualConfigure
****************************************************************************//**
*
* Manually configures the FLL based on user inputs.
*
* \param config \ref cy_stc_fll_manual_config_t
*
* \return  Error / status code: \n
* CY_SYSCLK_SUCCESS - FLL successfully configured \n
* CY_SYSCLK_INVALID_STATE - FLL not configured because it is enabled
*
* \note
* Call this function after changing the FLL input frequency, for example if
* \ref Cy_SysClk_ClkPathSetSource() is called.
*
* \note
* Do not call this function when the FLL is enabled. If it is called, then this function
* returns immediately with an CY_SYSCLK_INVALID_STATE return value and no register updates.
*
* \note
* Call \ref SystemCoreClockUpdate after this function calling
* if it affects the CLK_HF0 frequency.
*
* \note
* Call \ref Cy_SysLib_SetWaitStates before calling this function if
* the FLL is the source of CLK_HF0 and the FLL frequency is increasing.
*
* \note
* Call \ref Cy_SysLib_SetWaitStates after calling this function if
* the FLL is the source of CLK_HF0 and the FLL frequency is decreasing.
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_FllManualConfigure
*
*******************************************************************************/
cy_en_sysclk_status_t Cy_SysClk_FllManualConfigure(const cy_stc_fll_manual_config_t *config);


/*******************************************************************************
* Function Name: Cy_SysClk_FllGetConfiguration
****************************************************************************//**
*
* Reports the FLL configuration settings.
*
* \param config \ref cy_stc_fll_manual_config_t
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_FllGetConfiguration
*
*******************************************************************************/
void Cy_SysClk_FllGetConfiguration(cy_stc_fll_manual_config_t *config);


/*******************************************************************************
* Function Name: Cy_SysClk_FllEnable
****************************************************************************//**
*
* Enables the FLL. The FLL should be configured before calling this function.
*
* \param timeoutus Amount of time in micro seconds to wait for FLL to lock.
* If lock doesn't occur, the FLL is stopped. To avoid waiting for lock, set this to 0
* and manually check for lock using \ref Cy_SysClk_FllLocked.
*
* \return Error / status code: \n
* CY_SYSCLK_SUCCESS - FLL successfully enabled \n
* CY_SYSCLK_TIMEOUT - Timeout waiting for FLL lock
*
* \note
* While waiting for the FLL to lock, the FLL bypass mode is set to \ref CY_SYSCLK_FLLPLL_OUTPUT_INPUT.
* After the FLL is locked, the FLL bypass mode is then set to \ref CY_SYSCLK_FLLPLL_OUTPUT_OUTPUT.
*
* \note
* Call \ref SystemCoreClockUpdate after calling this function
* if it affects the CLK_HF0 frequency.
*
* \note
* Call \ref Cy_SysLib_SetWaitStates before calling this function if
* the FLL is the source of CLK_HF0 and the CLK_HF0 frequency is increasing.
*
* \note
* Take into account the possible platform specific clkHf (and further
* clocking chain links) frequency limitations while using this API.
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_FllEnable
*
*******************************************************************************/
cy_en_sysclk_status_t Cy_SysClk_FllEnable(uint32_t timeoutus);


/*******************************************************************************
* Function Name: Cy_SysClk_FllIsEnabled
****************************************************************************//**
*
* Reports whether or not the FLL is enabled.
*
* \return
* false = disabled \n
* true = enabled
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_FllDisable
*
*******************************************************************************/
bool Cy_SysClk_FllIsEnabled(void);


/*******************************************************************************
* Function Name: Cy_SysClk_FllIsConfigured
****************************************************************************//**
*
* Reports whether or not the FLL has been configured by the application.
*
* Unlike \ref Cy_SysClk_FllIsEnabled, this reflects the programmed FLL
* configuration (the FLL multiplier), which is retained across
* \ref Cy_SysClk_FllDisable. It therefore distinguishes an FLL that the
* application set up (and may have temporarily disabled) from one that was
* never configured.
*
* \return
* false = not configured \n
* true = configured
*
*******************************************************************************/
__STATIC_INLINE bool Cy_SysClk_FllIsConfigured(void)
{
#if ((defined CY_SRSS_FLL_PRESENT) && (CY_SRSS_FLL_PRESENT == 1U))
    /* A configured FLL always has a non-zero multiplier programmed into
     * CLK_FLL_CONFIG.FLL_MULT. That value survives Cy_SysClk_FllDisable(), so it
     * lets callers tell an application-configured FLL apart from one that was
     * never set up - without keeping any software state. */
    return (0UL != _FLD2VAL(SRSS_CLK_FLL_CONFIG_FLL_MULT, SRSS_CLK_FLL_CONFIG));
#else
    return false;
#endif
}


/*******************************************************************************
* Function Name: Cy_SysClk_FllLocked
****************************************************************************//**
*
* Reports whether the FLL is locked first time during FLL starting.
* Intended to be used with \ref Cy_SysClk_FllEnable with zero timeout.
*
* \return
* false = not locked \n
* true = locked
*
* \note
* The unlock occurrence may appear during FLL normal operation, so this function
* is not recommended to check the FLL normal operation stability.
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_FllLocked
*
*******************************************************************************/
bool Cy_SysClk_FllLocked(void);


/*******************************************************************************
* Function Name: Cy_SysClk_FllDisable
****************************************************************************//**
*
* Disables the FLL and the CCO.
*
* \return \ref cy_en_sysclk_status_t
*
* \note
* Call \ref SystemCoreClockUpdate after this function calling
* if it affects the CLK_HF0 frequency.
*
* \note
* Call \ref Cy_SysLib_SetWaitStates after calling this function if
* the FLL is the source of CLK_HF0 and the CLK_HF0 frequency is decreasing.
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_FllDisable
*
*******************************************************************************/
cy_en_sysclk_status_t Cy_SysClk_FllDisable(void);

#if defined (CY_IP_MXS40SSRSS) || (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION >= 2))

/*******************************************************************************
* Function Name: Cy_SysClk_FllOutputDividerEnable
****************************************************************************//**
*
* Enables/Disables the FLL output divider
*
* \param enable
*
*******************************************************************************/
void Cy_SysClk_FllOutputDividerEnable(bool enable);

#endif

/*******************************************************************************
* Function Name: Cy_SysClk_FllGetFrequency
****************************************************************************//**
*
* Returns the output frequency of the FLL.
*
* \return The output frequency of FLL.
*
* \note If the return value equals zero, that means FLL is disabled.
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_FllGetFrequency
*
*******************************************************************************/
uint32_t Cy_SysClk_FllGetFrequency(void);

/** \} group_sysclk_fll_funcs */
#endif /* defined (CY_IP_MXS40SRSS) || defined (CY_IP_MXS40SSRSS) || defined (CY_DOXYGEN) */

/* ========================================================================== */
/* ===========================    PLL SECTION    ============================ */
/* ========================================================================== */
#if defined (CY_IP_MXS40SRSS) || defined (CY_IP_MXS22SRSS) || (defined (CY_IP_MXS40SSRSS) && (SRSS_NUM_TOTAL_PLL > 0UL))
/**
* \addtogroup group_sysclk_pll_structs
* \{
*/
/** Structure containing information for configuration of a PLL.
*/
typedef struct
{
    uint32_t                    inputFreq;  /**< frequency of PLL source, in Hz */
    uint32_t                    outputFreq; /**< frequency of PLL output, in Hz */
    bool                        lfMode;     /**< CLK_PLL_CONFIG register, PLL_LF_MODE bit */
    cy_en_fll_pll_output_mode_t outputMode; /**< CLK_PLL_CONFIG register, BYPASS_SEL bits */
} cy_stc_pll_config_t;

#if defined (CY_IP_MXS22SRSS) || (defined (CY_IP_MXS40SSRSS) && (SRSS_NUM_TOTAL_PLL > 0UL)) || defined(CY_DOXYGEN)
/** Structure containing information for configuration of a DPLL-LP.
*/
typedef struct
{
    uint8_t                         feedbackDiv;   /**< CONFIG register, FEEDBACK_DIV (P) bits */
    uint8_t                         referenceDiv;  /**< CONFIG register, REFERENCE_DIV (Q) bits */
    uint8_t                         outputDiv;     /**< CONFIG register, OUTPUT_DIV bits */
    bool                            pllDcoMode;    /**< CONFIG register, PLL_DCO_MODE bit */
    cy_en_fll_pll_output_mode_t     outputMode;    /**< CONFIG register, BYPASS_SEL bits */
    uint32_t                        fracDiv;       /**< CONFIG2 register, FRAC_DIV bits */
    bool                            fracDitherEn;  /**< CONFIG2 register, FRAC_DITHER_EN bit */
    bool                            fracEn;        /**< CONFIG2 register, FRAC_EN bit */
    uint32_t                        sscgDepth;     /**< CONFIG3 register, SSCG_DEPTH bits */
    uint8_t                         sscgRate;      /**< CONFIG3 register, SSCG_RATE bits */
    bool                            sscgDitherEn;  /**< CONFIG3 register, SSCG_DITHER_EN bit */
    bool                            sscgMode;      /**< CONFIG3 register, SSCG_MODE bit */
    bool                            sscgEn;        /**< CONFIG3 register, SSCG_EN bit */
#if !defined(CY_IP_MXS22SRSS)
    uint32_t                        dcoCode;       /**< CONFIG4 register, DCO_CODE bits */
    uint32_t                        accMode;       /**< CONFIG4 register, ACC_MODE bits */
    uint32_t                        tdcMode;       /**< CONFIG4 register, TDC_MODE bits */
    uint32_t                        pllTg;         /**< CONFIG4 register, PLL_TG bits */
    bool                            accCntLock;    /**< CONFIG4 register, ACC_CNT_LOCK bits */
    uint32_t                        kiInt;         /**< CONFIG5 register, KI_INT bits */
    uint32_t                        kpInt;         /**< CONFIG5 register, KP_INT bits */
    uint32_t                        kiAccInt;      /**< CONFIG5 register, KI_ACC_INT bits */
    uint32_t                        kpAccInt;      /**< CONFIG5 register, KP_ACC_INT bits */
    uint32_t                        kiFrac;       /**< CONFIG6 register, KI_FRACT bits */
    uint32_t                        kpFrac;       /**< CONFIG6 register, KP_FRACT bits */
    uint32_t                        kiAccFrac;    /**< CONFIG6 register, KI_ACC_FRACT bits */
    uint32_t                        kpAccFrac;    /**< CONFIG7 register, KP_ACC_FRACT bits */
    uint32_t                        kiSscg;        /**< CONFIG7 register, KI_SSCG bits */
    uint32_t                        kpSscg;        /**< CONFIG7 register, KP_SSCG bits */
    uint32_t                        kiAccSscg;     /**< CONFIG7 register, KI_ACC_SSCG bits */
    uint32_t                        kpAccSscg;     /**< CONFIG7 register, KP_ACC_SSCG bits */
#endif
} cy_stc_dpll_lp_config_t;

#endif

/** Structure containing information for manual configuration of a PLL.
*/
typedef struct
{
#if (defined (CY_IP_MXS40SSRSS) && (SRSS_NUM_TOTAL_PLL > 0UL)) || defined(CY_DOXYGEN)
    cy_stc_dpll_lp_config_t   *lpPllCfg; /**< DPLL-LP configuration */
#endif
} cy_stc_pll_manual_config_t;
/** \} group_sysclk_pll_structs */

#if defined (CY_SRSS_PLL400M_PRESENT) && (CY_SRSS_PLL400M_PRESENT == 1u) || defined (CY_DOXYGEN)
/**
* \addtogroup group_sysclk_pll_enums
* \{
*/
/** SSCG modulation depth of PLL 400M spreading mode.
* See registers SSCG_DEPTH bit of PLL400M_STRUCT_CONFIG3.
*/
typedef enum
{
    CY_SYSCLK_SSCG_DEPTH_MINUS_0_5             = 0x029u, /**< - 0.5 [%] (down spread)  */
    CY_SYSCLK_SSCG_DEPTH_MINUS_1_0             = 0x052u, /**< - 1.0 [%] (down spread)  */
    CY_SYSCLK_SSCG_DEPTH_MINUS_2_0             = 0x0A4u, /**< - 2.0 [%] (down spread)  */
    CY_SYSCLK_SSCG_DEPTH_MINUS_3_0             = 0x0F6u, /**< - 3.0 [%] (down spread)  */
} cy_en_pll_400M_ssgc_depth_t;

/** SSCG modulation rate of PLL 400M spreading mode.
* See registers SSCG_RATE bit of PLL400M_STRUCT_CONFIG3.
*/
typedef enum
{
    CY_SYSCLK_SSCG_RATE_DIV_4096             = 0u, /**<  Modulation rate = fPFD/4096  */
    CY_SYSCLK_SSCG_RATE_DIV_2048             = 1u, /**<  Modulation rate = fPFD/2048  */
    CY_SYSCLK_SSCG_RATE_DIV_1024             = 2u, /**<  Modulation rate = fPFD/1024  */
    CY_SYSCLK_SSCG_RATE_DIV_512              = 3u, /**<  Modulation rate = fPFD/512   */
    CY_SYSCLK_SSCG_RATE_DIV_256              = 4u, /**<  Modulation rate = fPFD/256   */
} cy_en_pll_400M_ssgc_rate_t;

/** \} group_sysclk_pll_enums */
#endif /* defined (CY_SRSS_PLL400M_PRESENT) && (CY_SRSS_PLL400M_PRESENT == 1u) || defined (CY_DOXYGEN) */

#if (defined(CY_DEVICE_SECURE))

/** PRA structure for Cy_SysClk_PllManualConfigure function parameters */
typedef struct
{
    uint32_t                        clkPath;       /**< clkPath */
    cy_stc_pll_manual_config_t      *praConfig;    /**< config */
} cy_stc_pra_clk_pll_manconfigure_t;
#endif /* (defined(CY_DEVICE_SECURE)) */

/**
* \addtogroup group_sysclk_pll_funcs
* \{
*//*******************************************************************************
* Function Name: Cy_SysClk_PllConfigure
****************************************************************************//**
*
* Configures a given PLL.
* The configuration formula used is:
*   Fout = pll_clk * (P / Q / div_out), where:
*     Fout is the desired output frequency
*     pll_clk is the frequency of the input source
*     P is the feedback divider. Its value is in bitfield FEEDBACK_DIV.
*     Q is the reference divider. Its value is in bitfield REFERENCE_DIV.
*     div_out is the reference divider. Its value is in bitfield OUTPUT_DIV.
*
* \param clkPath Selects which PLL to configure. 1 is the first PLL; 0 is invalid.
*
* \param config \ref cy_stc_pll_config_t
*
* \return  Error / status code: \n
* CY_SYSCLK_SUCCESS - PLL successfully configured \n
* CY_SYSCLK_INVALID_STATE - PLL not configured because it is already enabled \n
* CY_SYSCLK_BAD_PARAM - Invalid clock path number, or input or desired output frequency is out of valid range \n
* CY_SYSCLK_UNSUPPORTED_STATE - PLL is not present
*
* \note
* Call this function after changing the PLL input frequency, for example if
* \ref Cy_SysClk_ClkPathSetSource() is called.
*
* \note
* Do not call this function when the PLL is enabled. If it is called, then this function
* returns immediately with an error return value and no register updates.
*
* \note
* Call \ref SystemCoreClockUpdate after this function calling
* if it affects the CLK_HF0 frequency.
*
* \note
* Call \ref Cy_SysLib_SetWaitStates before calling this function if
* the PLL is the source of CLK_HF0 and the PLL frequency is increasing.
*
* \note
* Call \ref Cy_SysLib_SetWaitStates after calling this function if
* the PLL is the source of CLK_HF0 and the PLL frequency is decreasing.
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_PllConfigure
*
*******************************************************************************/
cy_en_sysclk_status_t Cy_SysClk_PllConfigure(uint32_t clkPath, const cy_stc_pll_config_t *config);


/*******************************************************************************
* Function Name: Cy_SysClk_PllManualConfigure
****************************************************************************//**
*
* Manually configures a PLL based on user inputs.
*
* \param clkPath Selects which PLL to configure. 1 is the first PLL; 0 is invalid.
*
* \param config \ref cy_stc_pll_manual_config_t
*
* \return  Error / status code: \n
* CY_SYSCLK_SUCCESS - PLL successfully configured \n
* CY_SYSCLK_INVALID_STATE - PLL not configured because it is already enabled \n
* CY_SYSCLK_BAD_PARAM - invalid clock path number
* CY_SYSCLK_UNSUPPORTED_STATE - PLL is not present
*
* \note
* Call this function after changing the PLL input frequency; for example if
* \ref Cy_SysClk_ClkPathSetSource() is called.
*
* \note
* Do not call this function when the PLL is enabled. If it is called, then this function
* returns immediately with an error return value and no register updates.
*
* \note
* Call \ref SystemCoreClockUpdate after this function calling
* if it affects the CLK_HF0 frequency.
*
* \note
* Call \ref Cy_SysLib_SetWaitStates before calling this function if
* the PLL is the source of CLK_HF0 and the PLL frequency is increasing.
*
* \note
* Call \ref Cy_SysLib_SetWaitStates after calling this function if
* the PLL is the source of CLK_HF0 and the PLL frequency is decreasing.
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_PllManualConfigure
*
*******************************************************************************/
cy_en_sysclk_status_t Cy_SysClk_PllManualConfigure(uint32_t clkPath, const cy_stc_pll_manual_config_t *config);


/*******************************************************************************
* Function Name: Cy_SysClk_PllGetConfiguration
****************************************************************************//**
*
* Reports configuration settings for a PLL.
*
* \param clkPath Selects which PLL to report. 1 is the first PLL; 0 is invalid.
*
* \param config \ref cy_stc_pll_manual_config_t
*
* \return  Error / status code: \n
* CY_SYSCLK_SUCCESS - PLL data successfully reported \n
* CY_SYSCLK_BAD_PARAM - invalid clock path number
* CY_SYSCLK_UNSUPPORTED_STATE - PLL is not present
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_PllGetConfiguration
*
*******************************************************************************/
cy_en_sysclk_status_t Cy_SysClk_PllGetConfiguration(uint32_t clkPath, cy_stc_pll_manual_config_t *config);


/*******************************************************************************
* Function Name: Cy_SysClk_PllEnable
****************************************************************************//**
*
* Enables the PLL. The PLL should be configured before calling this function.
*
* \param clkPath Selects which PLL to enable. 1 is the first PLL; 0 is invalid.
*
* \param timeoutus amount of time in microseconds to wait for the PLL to lock.
* If the lock doesn't occur, PLL is stopped. To avoid waiting for lock, set this to 0
* and manually check for lock using \ref Cy_SysClk_PllLocked.
*
* \return Error / status code: \n
* CY_SYSCLK_SUCCESS - PLL successfully enabled \n
* CY_SYSCLK_TIMEOUT - Timeout waiting for PLL lock \n
* CY_SYSCLK_BAD_PARAM - invalid clock path number
* CY_SYSCLK_UNSUPPORTED_STATE - PLL is not present
*
* \note
* Call \ref SystemCoreClockUpdate after this function calling
* if it affects the CLK_HF0 frequency.
*
* \note
* Call \ref Cy_SysLib_SetWaitStates before calling this function if
* the PLL is the source of CLK_HF0 and the CLK_HF0 frequency is increasing.
*
* \note
* Call \ref Cy_SysLib_SetWaitStates after calling this function if
* the PLL is the source of CLK_HF0 and the CLK_HF0 frequency is decreasing.
*
* \note
* Take into account the possible platform specific clkHf (and further
* clocking chain links) frequency limitations while using this API.
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_PllEnable
*
*******************************************************************************/
cy_en_sysclk_status_t Cy_SysClk_PllEnable(uint32_t clkPath, uint32_t timeoutus);


/*******************************************************************************
* Function Name: Cy_SysClk_PllIsEnabled
****************************************************************************//**
*
* Reports whether or not the selected PLL is enabled.
*
* \param clkPath Selects which PLL to check. 1 is the first PLL; 0 is invalid.
*
* \return
* false = disabled \n
* true = enabled
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_PllDisable
*
*******************************************************************************/
bool Cy_SysClk_PllIsEnabled(uint32_t clkPath);


/*******************************************************************************
* Function Name: Cy_SysClk_PllIsConfigured
****************************************************************************//**
*
* Reports whether or not the selected PLL has been configured by the
* application.
*
* Unlike \ref Cy_SysClk_PllIsEnabled, this reflects the programmed PLL
* configuration (the feedback divider, or the integer feedback divider for a
* DPLL-HP), which is retained across \ref Cy_SysClk_PllDisable. It therefore
* distinguishes a PLL that the application set up (and may have temporarily
* disabled) from one that was never configured.
*
* \param clkPath Selects which PLL to check. 1 is the first PLL; 0 is invalid.
*
* \return
* false = not configured \n
* true = configured
*
*******************************************************************************/
bool Cy_SysClk_PllIsConfigured(uint32_t clkPath);


/*******************************************************************************
* Function Name: Cy_SysClk_PllLocked
****************************************************************************//**
*
* Reports whether or not the selected PLL is locked.
*
* \param clkPath Selects which PLL to check. 1 is the first PLL; 0 is invalid.
*
* \return
* false = not locked \n
* true = locked
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_PllLocked
*
*******************************************************************************/
bool Cy_SysClk_PllLocked(uint32_t clkPath);


/*******************************************************************************
* Function Name: Cy_SysClk_PllLostLock
****************************************************************************//**
*
* Reports whether or not the selected PLL lost its lock since the last time this
* function was called. Clears the lost lock indicator.
*
* \param clkPath Selects which PLL to check. 1 is the first PLL; 0 is invalid.
*
* \return
* false = did not lose lock \n
* true = lost lock
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_PllLostLock
*
*******************************************************************************/
bool Cy_SysClk_PllLostLock(uint32_t clkPath);


/*******************************************************************************
* Function Name: Cy_SysClk_PllDisable
****************************************************************************//**
*
* Disables the selected PLL.
*
* \param clkPath Selects which PLL to disable. 1 is the first PLL; 0 is invalid.
*
* \return Error / status code: \n
* CY_SYSCLK_SUCCESS - PLL successfully disabled \n
* CY_SYSCLK_BAD_PARAM - invalid clock path number
* CY_SYSCLK_UNSUPPORTED_STATE - PLL is not present
*
* \note
* Call \ref SystemCoreClockUpdate after this function calling
* if it affects the CLK_HF0 frequency.
*
* \note
* Call \ref Cy_SysLib_SetWaitStates before calling this function if
* the PLL is the source of CLK_HF0 and the CLK_HF0 frequency is increasing.
*
* \note
* Call \ref Cy_SysLib_SetWaitStates after calling this function if
* the PLL is the source of CLK_HF0 and the CLK_HF0 frequency is decreasing.
*
* \sideeffect
* This function sets PLL bypass mode to CY_SYSCLK_FLLPLL_OUTPUT_INPUT.
* If AUTO mode should be used, call \ref Cy_SysClk_PllConfigure or
* \ref Cy_SysClk_PllManualConfigure before calling \ref Cy_SysClk_PllEnable.
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_PllDisable
*
*******************************************************************************/
cy_en_sysclk_status_t Cy_SysClk_PllDisable(uint32_t clkPath);

/*******************************************************************************
* Function Name: Cy_SysClk_PllGetFrequency
****************************************************************************//**
*
* Returns the output frequency of the PLL.
*
* \param clkPath Selects the path on which the PLL frequency has to be obtained.
*
* \return The output frequency of the path PLL.
*
* \note If the return value equals zero, that means PLL is disabled.
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_PllGetFrequency
*
*******************************************************************************/
uint32_t Cy_SysClk_PllGetFrequency(uint32_t clkPath);


#if defined(CY_IP_MXS22SRSS) || (defined (CY_IP_MXS40SSRSS) && (SRSS_NUM_TOTAL_PLL > 0UL)) || defined(CY_DOXYGEN)

/*******************************************************************************
* Function Name: Cy_SysClk_DpllLpConfigure
****************************************************************************//**
*
* Configures DPLL-LP.
*
* The configuration formula used is:
*   Fout = pll_clk * (P / Q / div_out), where:
*     Fout is the desired output frequency
*     pll_clk is the frequency of the input source
*     P is the feedback divider. Its value is in bitfield FEEDBACK_DIV.
*     Q is the reference divider. Its value is in bitfield REFERENCE_DIV.
*     div_out is the reference divider. Its value is in bitfield OUTPUT_DIV.
*
* \param pllNum Selects which DPLL-LP to configure
*
* \param config \ref cy_stc_pll_config_t
*
* \return  Error / status code: \n
* CY_SYSCLK_SUCCESS - PLL successfully configured \n
* CY_SYSCLK_INVALID_STATE - PLL not configured because it is already enabled \n
* CY_SYSCLK_BAD_PARAM - Invalid clock path number, or input or desired output frequency is out of valid range \n
* CY_SYSCLK_UNSUPPORTED_STATE - PLL is not present
*
* \note
* Call this function after changing the PLL input frequency, for example if
* \ref Cy_SysClk_ClkPathSetSource() is called.
*
* \note
* Do not call this function when the PLL is enabled. If it is called, then this function
* returns immediately with an error return value and no register updates.
*
* \note
* Call \ref SystemCoreClockUpdate after this function calling
* if it affects the CLK_HF0 frequency.
*
*******************************************************************************/
cy_en_sysclk_status_t Cy_SysClk_DpllLpConfigure(uint32_t pllNum, const cy_stc_pll_config_t *config);


/*******************************************************************************
* Function Name: Cy_SysClk_DpllLpManualConfigure
****************************************************************************//**
*
* Manually configures a DPLL-LP based on user inputs.
*
* \param pllNum Selects which DPLL-LP to configure.
*
* \param config \ref cy_stc_pll_manual_config_t
*
* \return  Error / status code: \n
* CY_SYSCLK_SUCCESS - PLL successfully configured \n
* CY_SYSCLK_INVALID_STATE - PLL not configured because it is already enabled \n
* CY_SYSCLK_BAD_PARAM - invalid clock path number
* CY_SYSCLK_UNSUPPORTED_STATE - PLL is not present
*
* \note
* Call this function after changing the PLL input frequency; for example if
* \ref Cy_SysClk_ClkPathSetSource() is called.
*
* \note
* Do not call this function when the PLL is enabled. If it is called, then this function
* returns immediately with an error return value and no register updates.
*
* \note
* Call \ref SystemCoreClockUpdate after this function calling
* if it affects the CLK_HF0 frequency.
*
*******************************************************************************/
cy_en_sysclk_status_t Cy_SysClk_DpllLpManualConfigure(uint32_t pllNum, const cy_stc_pll_manual_config_t *config);


/*******************************************************************************
* Function Name: Cy_SysClk_DpllLpGetConfiguration
****************************************************************************//**
*
* Reports configuration settings for DPLL-LP.
*
* \param pllNum Selects which DPLL-LP to report.
*
* \param config \ref cy_stc_pll_manual_config_t
*
* \return  Error / status code: \n
* CY_SYSCLK_SUCCESS - PLL data successfully reported \n
* CY_SYSCLK_BAD_PARAM - invalid clock path number
* CY_SYSCLK_INVALID_STATE - PLL not configured because it is already enabled \n
* CY_SYSCLK_UNSUPPORTED_STATE - PLL is not present
*
*******************************************************************************/
cy_en_sysclk_status_t Cy_SysClk_DpllLpGetConfiguration(uint32_t pllNum, cy_stc_pll_manual_config_t *config);


/*******************************************************************************
* Function Name: Cy_SysClk_DpllLpEnable
****************************************************************************//**
*
* Enables the DPLL-LP. The PLL should be configured before calling this function.
*
* \param pllNum Selects which DPLL-LP to enable.
*
* \param timeoutus amount of time in microseconds to wait for the PLL to lock.
* If the lock doesn't occur, PLL is stopped. To avoid waiting for lock, set this to 0
* and manually check for lock using \ref Cy_SysClk_PllLocked.
*
* \return Error / status code: \n
* CY_SYSCLK_SUCCESS - PLL successfully enabled \n
* CY_SYSCLK_TIMEOUT - Timeout waiting for PLL lock \n
* CY_SYSCLK_BAD_PARAM - invalid clock path number
* CY_SYSCLK_INVALID_STATE - PLL not configured because it is already enabled \n
* CY_SYSCLK_UNSUPPORTED_STATE - PLL is not present
*
* \note
* Call \ref SystemCoreClockUpdate after this function calling
* if it affects the CLK_HF0 frequency.
*
*******************************************************************************/
cy_en_sysclk_status_t Cy_SysClk_DpllLpEnable(uint32_t pllNum, uint32_t timeoutus);


/*******************************************************************************
* Function Name: Cy_SysClk_DpllLpIsEnabled
****************************************************************************//**
*
* Reports whether or not the selected DPLL-LP is enabled.
*
* \param pllNum Selects which DPLL-LP to check.
*
* \return
* false = disabled \n
* true = enabled
*
*******************************************************************************/
bool Cy_SysClk_DpllLpIsEnabled(uint32_t pllNum);


/*******************************************************************************
* Function Name: Cy_SysClk_DpllLpLocked
****************************************************************************//**
*
* Reports whether or not the selected DPLL-LP is locked.
*
* \param pllNum Selects which DPLL-LP to check.
*
* \return
* false = not locked \n
* true = locked
*
*******************************************************************************/
bool Cy_SysClk_DpllLpLocked(uint32_t pllNum);


/*******************************************************************************
* Function Name: Cy_SysClk_DpllLpLostLock
****************************************************************************//**
*
* Reports whether or not the selected DPLL-LP lost its lock since the last time this
* function was called. Clears the lost lock indicator.
*
* \param pllNum Selects which DPLL-LP to check.
*
* \return
* false = did not lose lock \n
* true = lost lock
*
*******************************************************************************/
bool Cy_SysClk_DpllLpLostLock(uint32_t pllNum);


/*******************************************************************************
* Function Name: Cy_SysClk_DpllLpDisable
****************************************************************************//**
*
* Disables the selected DPLL-LP.
*
* \param pllNum Selects which DPLL-LP to disable.
*
* \return Error / status code: \n
* CY_SYSCLK_SUCCESS - PLL successfully disabled \n
* CY_SYSCLK_BAD_PARAM - invalid clock path number
* CY_SYSCLK_INVALID_STATE - PLL not configured because it is already enabled \n
* CY_SYSCLK_UNSUPPORTED_STATE - PLL is not present
*
* \note
* Call \ref SystemCoreClockUpdate after this function calling
* if it affects the CLK_HF0 frequency.
*
* \sideeffect
* This function sets PLL bypass mode to CY_SYSCLK_FLLPLL_OUTPUT_INPUT.
* If AUTO mode should be used, call \ref Cy_SysClk_DpllLpConfigure or
* \ref Cy_SysClk_DpllLpManualConfigure before calling \ref Cy_SysClk_DpllLpEnable.
*
*******************************************************************************/
cy_en_sysclk_status_t Cy_SysClk_DpllLpDisable(uint32_t pllNum);

/*******************************************************************************
* Function Name: Cy_SysClk_DpllLpGetFrequency
****************************************************************************//**
*
* Gets the frequency of DPLL-LP
*
* \param pllNum Selects which DPLL-LP to check.
*
* \return
* DPLL-LP Frequency
*
*******************************************************************************/
uint32_t Cy_SysClk_DpllLpGetFrequency(uint32_t pllNum);

#endif // defined(CY_IP_MXS22SRSS) || (defined (CY_IP_MXS40SSRSS) && (SRSS_NUM_TOTAL_PLL > 0UL)) || defined(CY_DOXYGEN)


/** \} group_sysclk_pll_funcs */

#endif

#if defined (CY_IP_MXS40SSRSS) || defined (CY_IP_MXS28SRSS) || defined (CY_IP_MXS22SRSS) || defined (CY_DOXYGEN)
/* ========================================================================== */
/* ===========================    IHO SECTION    ============================ */
/* ========================================================================== */

/**
* \addtogroup group_sysclk_iho_funcs
* \{
*/

#if defined (CY_IP_MXS40SSRSS) || defined (CY_IP_MXS22SRSS)

/*******************************************************************************
* Function Name: Cy_SysClk_IhoEnable
****************************************************************************//**
*
* Enables the IHO.
*
* \note
* Call \ref SystemCoreClockUpdate after this function calling
* if it affects the CLK_HF0 frequency.
*
* \note
* Take into account the possible platform specific clkHf (and further
* clocking chain links) frequency limitations while using this API.
*
*******************************************************************************/
void Cy_SysClk_IhoEnable(void);


/*******************************************************************************
* Function Name: Cy_SysClk_IhoIsEnabled
****************************************************************************//**
*
* Reports whether or not the selected IHO is enabled.
*
* \return
* false = disabled \n
* true = enabled
*
*******************************************************************************/
bool Cy_SysClk_IhoIsEnabled(void);

/*******************************************************************************
* Function Name: Cy_SysClk_IhoDisable
****************************************************************************//**
*
* Disables IHO.
*
* \note
* Call \ref SystemCoreClockUpdate after this function calling
* if it affects the CLK_HF0 frequency.
*
*******************************************************************************/
void Cy_SysClk_IhoDisable(void);

#endif


/** \} group_sysclk_iho_funcs */
#endif /* defined (CY_IP_MXS40SSRSS) || defined (CY_IP_MXS28SRSS) || defined (CY_IP_MXS22SRSS) || defined (CY_DOXYGEN)*/

/* ========================================================================== */
/* ===========================    IMO SECTION    ============================ */
/* ========================================================================== */

/**
* \addtogroup group_sysclk_imo_funcs
* \{
*/
#if defined (CY_IP_MXS40SSRSS) || (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION >= 2))

/*******************************************************************************
* Function Name: Cy_SysClk_ImoEnable
****************************************************************************//**
*
* Enables the IMO.
*
*******************************************************************************/
void Cy_SysClk_ImoEnable(void);

/*******************************************************************************
* Function Name: Cy_SysClk_ImoIsEnabled
****************************************************************************//**
*
* Reports whether or not the selected IMO is enabled.
*
* \return
* false = disabled \n
* true = enabled
*
*******************************************************************************/
bool Cy_SysClk_ImoIsEnabled(void);

/*******************************************************************************
* Function Name: Cy_SysClk_ImoDisable
****************************************************************************//**
*
* Disables IMO.
*
*
*******************************************************************************/
void Cy_SysClk_ImoDisable(void);
#endif /* defined (CY_IP_MXS40SSRSS) || (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION >= 2)) */

#if defined (CY_IP_MXS40SSRSS)

/*******************************************************************************
* Function Name: Cy_SysClk_ImoDeepsleepEnable
****************************************************************************//**
*
* Enables the IMO during deepsleep mode
*
*******************************************************************************/
void Cy_SysClk_ImoDeepsleepEnable(void);


/*******************************************************************************
* Function Name: Cy_SysClk_ImoIsDeepsleepEnabled
****************************************************************************//**
*
* Reports whether or not the selected IMO is enabled during deepsleep mode.
*
* \return
* false = disabled \n
* true = enabled
*
*******************************************************************************/
bool Cy_SysClk_ImoIsDeepsleepEnabled(void);

/*******************************************************************************
* Function Name: Cy_SysClk_ImoDeepsleepDisable
****************************************************************************//**
*
* Disables IMO during deepsleep mode.
*
*******************************************************************************/
void Cy_SysClk_ImoDeepsleepDisable(void);
#endif /* defined (CY_IP_MXS40SSRSS) */
/** \} group_sysclk_imo_funcs */

/* ========================================================================== */
/* ===========================    ILO SECTION    ============================ */
/* ========================================================================== */
/**
* \addtogroup group_sysclk_ilo_funcs
* \{
*/

#if defined (CY_IP_MXS40SSRSS) || (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION < 2)) || defined (CY_DOXYGEN)
/*******************************************************************************
* Function Name: Cy_SysClk_IloEnable
****************************************************************************//**
*
* Enables the ILO.
*
* \note The watchdog timer (WDT) must be unlocked before calling this function.
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_IloEnable
*
*******************************************************************************/
void Cy_SysClk_IloEnable(void);


/*******************************************************************************
* Function Name: Cy_SysClk_IloIsEnabled
****************************************************************************//**
*
* Reports the Enabled/Disabled status of the ILO.
*
* \return Boolean status of ILO: true - Enabled, false - Disabled.
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_IloDisable
*
*******************************************************************************/
bool Cy_SysClk_IloIsEnabled(void);


/*******************************************************************************
* Function Name: Cy_SysClk_IloDisable
****************************************************************************//**
*
* Disables the ILO. ILO can't be disabled if WDT is enabled.
*
* \return Error / status code: \n
* CY_SYSCLK_SUCCESS - ILO successfully disabled \n
* CY_SYSCLK_INVALID_STATE - Cannot disable the ILO if the WDT is enabled.
* CY_PRA_STATUS_* - For the PSOC 64 devices there are possible situations when
* function returns the PRA error status code \ref cy_en_pra_status_t instead of
* \ref cy_en_sysclk_status_t. This is because for PSOC 64 devices the function
* uses the PRA driver to change the protected registers. Refer to
* \ref cy_en_pra_status_t for more details.
*
* \note The watchdog timer (WDT) must be unlocked before calling this function.
* Do not call this function if the WDT is enabled, because the WDT is clocked by
* the ILO.
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_IloDisable
*
*******************************************************************************/
cy_en_sysclk_status_t Cy_SysClk_IloDisable(void);


/*******************************************************************************
* Function Name: Cy_SysClk_IloHibernateOn
****************************************************************************//**
*
* Controls whether the ILO stays on during a hibernate, or through an XRES or
* brown-out detect (BOD) event.
*
* \param on
* true = ILO stays on during hibernate or across XRES/BOD. \n
* false = ILO turns off for hibernate or XRES/BOD.
*
* \note Writes to the register/bit are ignored if the watchdog (WDT) is locked.
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_IloHibernateOn
*
*******************************************************************************/
void Cy_SysClk_IloHibernateOn(bool on);
#endif /* defined (CY_IP_MXS40SSRSS) || defined (CY_IP_MXS22SRSS) || (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION < 2)) || defined (CY_DOXYGEN)  */


/** \} group_sysclk_ilo_funcs */



/* ========================================================================== */
/* ===========================    PILO SECTION    =========================== */
/* ========================================================================== */
/**
* \addtogroup group_sysclk_pilo_funcs
* \{
*/

/*******************************************************************************
* Function Name: Cy_SysClk_PiloEnable
****************************************************************************//**
*
* Enables the PILO.
*
* \note This function blocks for 1 millisecond between enabling the PILO and
* releasing the PILO reset.
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_PiloEnable
*
*******************************************************************************/
void Cy_SysClk_PiloEnable(void);


/*******************************************************************************
* Function Name: Cy_SysClk_PiloIsEnabled
****************************************************************************//**
*
* Reports the Enabled/Disabled status of the PILO.
*
* \return Boolean status of PILO: true - Enabled, false - Disabled.
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_PiloDisable
*
*******************************************************************************/
bool Cy_SysClk_PiloIsEnabled(void);


/*******************************************************************************
* Function Name: Cy_SysClk_PiloDisable
****************************************************************************//**
*
* Disables the PILO.
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_PiloDisable
*
*******************************************************************************/
void Cy_SysClk_PiloDisable(void);


#if defined (CY_IP_MXS40SSRSS) || defined (CY_DOXYGEN)
/*******************************************************************************
* Function Name: Cy_SysClk_PiloBackupEnable
****************************************************************************//**
*
* Enables the PILO as always on if Backup Domain is present.
*
*******************************************************************************/
void Cy_SysClk_PiloBackupEnable(void);

/*******************************************************************************
* Function Name: Cy_SysClk_PiloBackupDisable
****************************************************************************//**
*
* Disables the PILO as always on if Backup Domain is present.
*
*******************************************************************************/
void Cy_SysClk_PiloBackupDisable(void);

/*******************************************************************************
* Function Name: Cy_SysClk_PiloOkay
****************************************************************************//**
*
* Reports the status of the PILO.
*
* \return
* true = okay \n
* false = not okay
*
*******************************************************************************/
bool Cy_SysClk_PiloOkay(void);

#endif /* defined (CY_IP_MXS40SSRSS) || defined (CY_DOXYGEN) */

#if defined (CY_IP_MXS40SSRSS) || defined (CY_DOXYGEN)

/*******************************************************************************
* Function Name: Cy_SysClk_PiloTcscEnable
****************************************************************************//**
*
* Enables the PILO TCSC(Second order temperature curvature correction) Feature.
*
*******************************************************************************/
void Cy_SysClk_PiloTcscEnable(void);


/*******************************************************************************
* Function Name: Cy_SysClk_PiloTcscDisable
****************************************************************************//**
*
* Disables the PILO TCSC(Second order temperature curvature correction) Feature.
*
*******************************************************************************/
void Cy_SysClk_PiloTcscDisable(void);

#endif /* defined (CY_IP_MXS40SSRSS) || defined (CY_DOXYGEN) */

/** \} group_sysclk_pilo_funcs */


/* ========================================================================== */
/* ==========================    ALTHF SECTION    =========================== */
/* ========================================================================== */
/**
* \addtogroup group_sysclk_alt_hf_funcs
* \{
*/
#if (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION < 2)) || defined (CY_IP_MXS40SSRSS) || defined (CY_IP_MXS22SRSS) || defined (CY_DOXYGEN)
/*******************************************************************************
* Function Name: Cy_SysClk_AltHfGetFrequency
****************************************************************************//**
*
* Reports the frequency of the Alternative High-Frequency Clock
*
* \funcusage
* \snippet bleclk/snippet/main.c BLE ECO clock API: Cy_BLE_EcoConfigure()
*
*******************************************************************************/
uint32_t Cy_SysClk_AltHfGetFrequency(void);
#endif

#if defined (CY_IP_MXS40SSRSS) || defined (CY_IP_MXS22SRSS) || defined (CY_DOXYGEN)
/*******************************************************************************
* Function Name: Cy_SysClk_AltHfEnable
****************************************************************************//**
*
* Enables the ALTHF.
*
* \return Error / status code: \n
* CY_SYSCLK_SUCCESS - ALTHF successfully disabled \n
* CY_SYSCLK_TIMEOUT - ALTHF enabling failed due to timeout
*
*******************************************************************************/
cy_en_sysclk_status_t Cy_SysClk_AltHfEnable(uint32_t timeoutus);

/*******************************************************************************
* Function Name: Cy_SysClk_IsAltHfEnabled
****************************************************************************//**
*
* Reports if ALTHF is enabled or not
*
* \return Status of ALTHF \n
* true = Enabled \n
* false = Not Enabled
*
*******************************************************************************/
bool Cy_SysClk_IsAltHfEnabled(void);

#endif /* defined (CY_IP_MXS40SSRSS) || defined (CY_IP_MXS22SRSS) */

/** \} group_sysclk_alt_hf_funcs */


/* ========================================================================== */
/* ==========================    ALTLF SECTION    =========================== */
/* ========================================================================== */
/** \cond For future usage */
uint32_t Cy_SysClk_AltLfGetFrequency(void);
bool Cy_SysClk_AltLfIsEnabled(void);
/** \endcond  */


/* ========================================================================== */
/* ====================    CLOCK MEASUREMENT SECTION    ===================== */
/* ========================================================================== */
/**
* \addtogroup group_sysclk_calclk_enums
* \{
*/
/** Defines all possible clock sources */
#if !defined(CY_IP_MXS22SRSS)
typedef enum
{
    CY_SYSCLK_MEAS_CLK_NC =                0U,
    CY_SYSCLK_MEAS_CLK_ILO =               1U,
    CY_SYSCLK_MEAS_CLK_WCO =               2U,
    CY_SYSCLK_MEAS_CLK_BAK =               3U,
    CY_SYSCLK_MEAS_CLK_ALTLF =             4U,
    CY_SYSCLK_MEAS_CLK_LFCLK =             5U,
    CY_SYSCLK_MEAS_CLK_IMO =               6U,
    CY_SYSCLK_MEAS_CLK_SLPCTRL =           7U,
    CY_SYSCLK_MEAS_CLK_PILO =              8U,
    CY_SYSCLK_MEAS_CLK_ILO1 =              9U,
    CY_SYSCLK_MEAS_CLK_ECO_PRESCALER =     10U,
    CY_SYSCLK_MEAS_CLK_LPECO =             11U,
    CY_SYSCLK_MEAS_CLK_LPECO_PRESCALER =   12U,
    CY_SYSCLK_MEAS_CLK_MFO =               13U,
    CY_SYSCLK_MEAS_CLK_FAST_CLKS =         0x100U,
    CY_SYSCLK_MEAS_CLK_ECO =               0x101U,
    CY_SYSCLK_MEAS_CLK_EXT =               0x102U,
    CY_SYSCLK_MEAS_CLK_ALTHF =             0x103U,
    CY_SYSCLK_MEAS_CLK_TIMERCLK =          0x104U,
    CY_SYSCLK_MEAS_CLK_IHO =               0x108U,
    CY_SYSCLK_MEAS_CLK_PWR =               0x109U,
    CY_SYSCLK_MEAS_CLK_PATH_CLKS =         0x500U,
    CY_SYSCLK_MEAS_CLK_PATH0 =             0x500U,
    CY_SYSCLK_MEAS_CLK_PATH1 =             0x501U,
    CY_SYSCLK_MEAS_CLK_PATH2 =             0x502U,
    CY_SYSCLK_MEAS_CLK_PATH3 =             0x503U,
    CY_SYSCLK_MEAS_CLK_PATH4 =             0x504U,
    CY_SYSCLK_MEAS_CLK_PATH5 =             0x505U,
    CY_SYSCLK_MEAS_CLK_PATH6 =             0x506U,
    CY_SYSCLK_MEAS_CLK_PATH7 =             0x507U,
    CY_SYSCLK_MEAS_CLK_PATH8 =             0x508U,
    CY_SYSCLK_MEAS_CLK_PATH9 =             0x509U,
    CY_SYSCLK_MEAS_CLK_PATH10 =            0x50AU,
    CY_SYSCLK_MEAS_CLK_PATH11 =            0x50BU,
    CY_SYSCLK_MEAS_CLK_PATH12 =            0x50CU,
    CY_SYSCLK_MEAS_CLK_PATH13 =            0x50DU,
    CY_SYSCLK_MEAS_CLK_PATH14 =            0x50EU,
    CY_SYSCLK_MEAS_CLK_PATH15 =            0x50FU,
    CY_SYSCLK_MEAS_CLK_CLKHFS =            0x600U,
    CY_SYSCLK_MEAS_CLK_CLKHF0 =            0x600U,
    CY_SYSCLK_MEAS_CLK_CLKHF1 =            0x601U,
    CY_SYSCLK_MEAS_CLK_CLKHF2 =            0x602U,
    CY_SYSCLK_MEAS_CLK_CLKHF3 =            0x603U,
    CY_SYSCLK_MEAS_CLK_CLKHF4 =            0x604U,
    CY_SYSCLK_MEAS_CLK_CLKHF5 =            0x605U,
    CY_SYSCLK_MEAS_CLK_CLKHF6 =            0x606U,
    CY_SYSCLK_MEAS_CLK_CLKHF7 =            0x607U,
    CY_SYSCLK_MEAS_CLK_CLKHF8 =            0x608U,
    CY_SYSCLK_MEAS_CLK_CLKHF9 =            0x609U,
    CY_SYSCLK_MEAS_CLK_CLKHF10 =           0x60AU,
    CY_SYSCLK_MEAS_CLK_CLKHF11 =           0x60BU,
    CY_SYSCLK_MEAS_CLK_CLKHF12 =           0x60CU,
    CY_SYSCLK_MEAS_CLK_CLKHF13 =           0x60DU,
    CY_SYSCLK_MEAS_CLK_CLKHF14 =           0x60EU,
    CY_SYSCLK_MEAS_CLK_CLKHF15 =           0x60FU,
    CY_SYSCLK_MEAS_CLK_LAST_CLK =          0x610U
} cy_en_meas_clks_t;
#endif
/** \} group_sysclk_calclk_enums */

/**
* \addtogroup group_sysclk_calclk_structs
* \{
*/
#if defined(CY_DEVICE_SECURE) || defined (CY_DOXYGEN)
/** PRA structure for Cy_SysClk_StartClkMeasurementCounters function parameters */
typedef struct
{
    cy_en_meas_clks_t clock1;        /**< clock1 */
    uint32_t          count1;        /**< count  */
    cy_en_meas_clks_t clock2;        /**< clock2 */
} cy_stc_pra_start_clk_measurement_t;

#endif /* (defined(CY_DEVICE_SECURE)) */
/** \} group_sysclk_calclk_structs */

/**
* \addtogroup group_sysclk_calclk_funcs
* \{
*/
/*******************************************************************************
* Function Name: Cy_SysClk_StartClkMeasurementCounters
****************************************************************************//**
*
* Assigns clocks to the clock measurement counters, and starts counting. The counters
* let you measure a clock frequency using another clock as a reference. There are two
* counters.
*
* - One counter (counter1), which is clocked by clock1, is loaded with an initial
*   value and counts down to zero.
* - The second counter (counter2), which is clocked by clock2, counts up until
*   the first counter reaches zero.
*
* Either clock1 or clock2 can be a reference clock; the other clock becomes the
* measured clock. The reference clock frequency is always known. \n
* After calling this function, call \ref Cy_SysClk_ClkMeasurementCountersDone()
* to determine when counting is done; that is, counter1 has counted down to zero.
* Then call \ref Cy_SysClk_ClkMeasurementCountersGetFreq() to calculate the frequency
* of the measured clock.
*
* \param clock1 The clock for counter1
*
* \param count1 The initial value for counter1, from which counter1 counts down to zero.
*
* \param clock2 The clock for counter2
*
* \return Error / status code: \n
* CY_SYSCLK_INVALID_STATE if already doing a measurement \n
* CY_SYSCLK_BAD_PARAM if invalid clock input parameter \n
* else CY_SYSCLK_SUCCESS
*
* \note The counters are both 24-bit, so the maximum value of count1 is 0xFFFFFF.
* If clock2 frequency is greater than clock1, make sure that count1 is low enough
* that counter2 does not overflow before counter1 reaches zero.
* \note The time to complete a measurement is count1 / clock1 frequency.
* \note The clocks for both counters must have a nonzero frequency, or
* \ref Cy_SysClk_ClkMeasurementCountersGetFreq() incorrectly reports the result of the
* previous  measurement.
* \note Do not enter a device low power mode (Sleep, Deep Sleep) while doing a measurement;
* the measured clock frequency may not be accurate.
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_StartClkMeasurementCounters
*
*******************************************************************************/
cy_en_sysclk_status_t Cy_SysClk_StartClkMeasurementCounters(cy_en_meas_clks_t clock1, uint32_t count1, cy_en_meas_clks_t clock2);


/*******************************************************************************
* Function Name: Cy_SysClk_ClkMeasurementCountersGetFreq
****************************************************************************//**
*
* Calculates the frequency of the indicated measured clock (clock1 or clock2).
* - If clock1 is the measured clock, its frequency is: clock1 frequency = (count1 / count2) * clock2 frequency
* - If clock2 is the measured clock, its frequency is: clock2 frequency = (count2 / count1) * clock1 frequency
*
* Call this function only after counting is done; see \ref Cy_SysClk_ClkMeasurementCountersDone().
*
* \param measuredClock False (0) if the measured clock is clock1; true (1)
* if the measured clock is clock2.
*
* \param refClkFreq The reference clock frequency (clock1 or clock2).
*
* \return The frequency of the measured clock, in Hz.
* \warning The function returns zero, if during measurement device was in the
* Deep Sleep or partially blocking flash operation occurred. It means that
* current measurement is not valid and you should call the
* Cy_SysClk_StartClkMeasurementCounters() function once again.
*
* \funcusage
* Refer to the Cy_SysClk_StartClkMeasurementCounters() function usage.
*
*******************************************************************************/
uint32_t Cy_SysClk_ClkMeasurementCountersGetFreq(bool measuredClock, uint32_t refClkFreq);


/*******************************************************************************
* Function Name: Cy_SysClk_ClkMeasurementCountersDone
****************************************************************************//**
*
* Checks if clock measurement counting is done, that is, counter1 has counted down
* to zero. Call \ref Cy_SysClk_StartClkMeasurementCounters() before calling this function.
*
* \return Status of calibration counters: \n
* true = done \n
* false = not done
*
* \funcusage
* Refer to the Cy_SysClk_StartClkMeasurementCounters() function usage.
*
*******************************************************************************/
bool Cy_SysClk_ClkMeasurementCountersDone(void);
/** \} group_sysclk_calclk_funcs */


/* ========================================================================== */
/* ==========================    TRIM SECTION    ============================ */
/* ========================================================================== */
/**
* \addtogroup group_sysclk_trim_funcs
* \{
*/

#if defined (CY_IP_MXS40SSRSS) || (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION < 2)) || defined (CY_DOXYGEN)

/*******************************************************************************
* Function Name: Cy_SysClk_IloTrim
****************************************************************************//**
*
* Trims the ILO to be as close to 32,768 Hz as possible.
*
* \param iloFreq current ILO frequency. Call \ref Cy_SysClk_StartClkMeasurementCounters
* and other measurement functions to obtain the current frequency of the ILO.
*
* \return Change in trim value - 0 if done; that is, no change in trim value.
*
* \note The watchdog timer (WDT) must be unlocked before calling this function.
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_IloTrim
*
*******************************************************************************/
int32_t Cy_SysClk_IloTrim(uint32_t iloFreq);
#endif

#if  defined (CY_IP_MXS40SSRSS) || defined (CY_DOXYGEN)
/*******************************************************************************
* Function Name: Cy_SysClk_IloSetTrim
****************************************************************************//**
*
* Set ILO Trim Value
*
* \param trimVal Trim value to be set for ILO.
*
*******************************************************************************/
void Cy_SysClk_IloSetTrim(uint32_t trimVal);


/*******************************************************************************
* Function Name: Cy_SysClk_IloGetTrim
****************************************************************************//**
*
* Gets the ILO Trim Value.
*
* \return ILO Trim Value.
*
*******************************************************************************/
uint32_t Cy_SysClk_IloGetTrim(void);

#endif /* defined (CY_IP_MXS40SSRSS) || defined (CY_DOXYGEN) */


/** \} group_sysclk_trim_funcs */


/* ========================================================================== */
/* ======================    POWER MANAGEMENT SECTION    ==================== */
/* ========================================================================== */
/**
* \addtogroup group_sysclk_pm_funcs
* \{
*/
/*******************************************************************************
* Function Name: Cy_SysClk_DeepSleepCallback
****************************************************************************//**
*
* Callback function to be used when entering system Deep Sleep mode.
* This function is applicable if:
* - The FLL is enabled
* - The PLL is enabled and is driven by ECO
*
* This function performs the following:
*
* 1. Before entering Deep Sleep, the clock configuration is saved in SRAM.
*    If the FLL/PLL source is the ECO, then the FLL/PLL is bypassed and the
*    source is changed to IMO. \n
*    If the FLL is enabled - it is just bypassed.
* 2. Upon wakeup from Deep Sleep, the function waits for ECO stabilization,
*    then restores the configuration and waits for the FLL/PLL to regain their
*    frequency locks. \n
*    If ECO is not used and FLL is enabled - it waits for FLL lock and unbypasses it.
*
* The function prevents entry into Deep Sleep mode if the measurement counters
* are currently counting; see \ref Cy_SysClk_StartClkMeasurementCounters.
*
* This function can be called during execution of \ref Cy_SysPm_CpuEnterDeepSleep.
* To do so, register this function as a callback before calling
* \ref Cy_SysPm_CpuEnterDeepSleep - specify \ref CY_SYSPM_DEEPSLEEP as the callback
* type and call \ref Cy_SysPm_RegisterCallback.
*
* \note
* This function is recommended to be the last callback that is registered.
* Doing so minimizes the time spent on low power mode entry and exit. \n
* This function implements all four SysPm callback modes \ref cy_en_syspm_callback_mode_t.
* So the \ref cy_stc_syspm_callback_t::skipMode must be set to 0UL. \n
* This function does not support such cases as, for example, FLL is enabled
* but bypassed by user code before entering Deep Sleep. \n
* You can use this callback implementation as an example to design custom low-power
* callbacks for certain user application.
*
* \param callbackParams
* structure with the syspm callback parameters,
* see \ref cy_stc_syspm_callback_params_t.
*
* \param mode
* Callback mode, see \ref cy_en_syspm_callback_mode_t
*
* \return Error / status code; see \ref cy_en_syspm_status_t. Pass if not doing
* a clock measurement, otherwise Fail. Timeout if timeout waiting for ECO, FLL
* or PLL to get stable / regain its frequency lock.
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_DeepSleepCallback
*
*******************************************************************************/
cy_en_syspm_status_t Cy_SysClk_DeepSleepCallback(cy_stc_syspm_callback_params_t * callbackParams, cy_en_syspm_callback_mode_t mode);
/** \} group_sysclk_pm_funcs */


/* ========================================================================== */
/* ===========================    WCO SECTION    ============================ */
/* ========================================================================== */
/**
* \addtogroup group_sysclk_wco_enums
* \{
*/
/** WCO bypass modes */
typedef enum
{
    CY_SYSCLK_WCO_NOT_BYPASSED = 0U, /**< WCO is not bypassed crystal is used */
    CY_SYSCLK_WCO_BYPASSED = 1U      /**< WCO is bypassed external clock must be supplied  on XTAL pin */
} cy_en_wco_bypass_modes_t;


/** \cond BWC */


/**
* Clock supervisor clock loss window. There must be one clock of the supervised
* clock within this many clocks of the supervising clock.
* See registers CLK_CSV_HF_CTL and CLK_CSV_WCO_CTL, bitfield CSV_LOSS_WINDOW.
*/
typedef enum
{
    CY_SYSCLK_CSV_LOSS_4_CYCLES =   0U, /**< 1 clock must be seen within 4 cycles of the supervising clock */
    CY_SYSCLK_CSV_LOSS_8_CYCLES =   1U, /**< 1 clock must be seen within 8 cycles of the supervising clock */
    CY_SYSCLK_CSV_LOSS_16_CYCLES =  2U, /**< 1 clock must be seen within 16 cycles of the supervising clock */
    CY_SYSCLK_CSV_LOSS_32_CYCLES =  3U, /**< 1 clock must be seen within 32 cycles of the supervising clock */
    CY_SYSCLK_CSV_LOSS_64_CYCLES =  4U, /**< 1 clock must be seen within 64 cycles of the supervising clock */
    CY_SYSCLK_CSV_LOSS_128_CYCLES = 5U, /**< 1 clock must be seen within 128 cycles of the supervising clock */
    CY_SYSCLK_CSV_LOSS_256_CYCLES = 6U, /**< 1 clock must be seen within 256 cycles of the supervising clock */
    CY_SYSCLK_CSV_LOSS_512_CYCLES = 7U  /**< 1 clock must be seen within 512 cycles of the supervising clock */
} cy_en_csv_loss_window_t;

/**
* Clock supervisor error actions. See register CLK_CSV_HF_CTL[CSV_FREQ_ACTION and CSV_LOSS_ACTION].
*/
typedef enum
{
    CY_SYSCLK_CSV_ERROR_IGNORE =      0U, /**< Ignore the error reported by the clock supervisor */
    CY_SYSCLK_CSV_ERROR_FAULT =       1U, /**< Trigger a fault when an error is reported by the clock supervisor */
    CY_SYSCLK_CSV_ERROR_RESET =       2U, /**< Trigger a reset when an error is reported by the clock supervisor */
    CY_SYSCLK_CSV_ERROR_FAULT_RESET = 3U  /**< Trigger a fault then reset when an error is reported by the supervisor */
} cy_en_csv_error_actions_t;


/** \endcond BWC */

/** \} group_sysclk_wco_enums */

/** \cond BWC */

/**
* \addtogroup group_sysclk_wco_structs
* \{
*/

/** \} group_sysclk_wco_structs */


/** \endcond BWC */

/**
* \addtogroup group_sysclk_wco_funcs
* \{
*/
/*******************************************************************************
* Function Name: Cy_SysClk_WcoEnable
****************************************************************************//**
*
* Enables the WCO.
*
* \param timeoutus amount of time in microseconds to wait for the WCO to be ready.
* If WCO is not ready, WCO is stopped. To avoid waiting for WCO ready set this to 0,
* and manually check if WCO is okay using \ref Cy_SysClk_WcoOkay.
*
* \return Error / status code: \n
* CY_SYSCLK_SUCCESS - WCO successfully enabled \n
* CY_SYSCLK_TIMEOUT - Timeout waiting for WCO to stabilize
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_WcoEnable
*
*******************************************************************************/
cy_en_sysclk_status_t Cy_SysClk_WcoEnable(uint32_t timeoutus);


/*******************************************************************************
* Function Name: Cy_SysClk_WcoOkay
****************************************************************************//**
*
* Reports the status of the WCO_OK bit.
*
* \return
* true = okay \n
* false = not okay
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_WcoOkay
*
*******************************************************************************/
bool Cy_SysClk_WcoOkay(void);


/*******************************************************************************
* Function Name: Cy_SysClk_WcoDisable
****************************************************************************//**
*
* Disables the WCO.
*
* \note
* We need to set writable option using Cy_RTC_WriteEnable
* before disabling WCO, and clear writable option after disabling WCO.
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_WcoDisable
*
*******************************************************************************/
void Cy_SysClk_WcoDisable(void);



/*******************************************************************************
* Function Name: Cy_SysClk_WcoBypass
****************************************************************************//**
*
* Sets whether the WCO is bypassed or not. If it is bypassed, then a 32-kHz clock
* must be provided on the wco_out pin.
*
* \param bypass \ref cy_en_wco_bypass_modes_t
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_WcoBypass
*
*******************************************************************************/
void Cy_SysClk_WcoBypass(cy_en_wco_bypass_modes_t bypass);


#if (defined (SRSS_WCO_PRESENT) && (SRSS_WCO_PRESENT > 0))
/*******************************************************************************
* Function Name: Cy_SysClk_Wco_LpoMode_Enable
****************************************************************************//**
*
* Selects LPO mode for the WCO. In LPO mode the WCO uses a capacitively coupled
* single-pin input (wco_in only).
* This mode is available on devices with the SRIP WCO block (e.g. PSB3xxx).
*
* \note Call this before enabling the WCO with \ref Cy_SysClk_WcoEnable.
*
*******************************************************************************/
void Cy_SysClk_Wco_LpoMode_Enable(void);


/*******************************************************************************
* Function Name: Cy_SysClk_Wco_LpoMode_Disable
****************************************************************************//**
*
* Deselects LPO mode for the WCO, reverting to normal crystal or bypass operation
* using both wco_in and wco_out pins.
*
* \note Call this before enabling the WCO with \ref Cy_SysClk_WcoEnable.
*
*******************************************************************************/
void Cy_SysClk_Wco_LpoMode_Disable(void);
#endif /* (defined (SRSS_WCO_PRESENT) && (SRSS_WCO_PRESENT > 0)) */
/** \} group_sysclk_wco_funcs */


/* ========================================================================== */
/* ============================    MF SECTION    ============================ */
/* ========================================================================== */

/**
* \addtogroup group_sysclk_mf_enums
* \{
*/
#if defined (CY_IP_MXS40SSRSS) || defined (CY_IP_MXS28SRSS) || defined(CY_IP_MXS22SRSS) || defined (CY_DOXYGEN)

/**
* Medium frequency (clkMf) input sources. See CLK_MF_SELECT register, MFCLK_SEL bits.
* Used with functions \ref Cy_SysClk_ClkMfSetSource, and \ref Cy_SysClk_ClkMfGetSource.
*/
#if !defined(CY_IP_MXS22SRSS)

typedef enum
{
    CY_SYSCLK_CLKMF_IN_MFO               = 0U, /**< clkMf is sourced by the internal low speed oscillator (MFO) */
    CY_SYSCLK_CLKMF_IN_ILO               = 1U, /**< clkMf is sourced by the internal low speed oscillator (ILO) */
    CY_SYSCLK_CLKMF_IN_WCO               = 2U, /**< clkMf is sourced by the watch crystal oscillator (WCO) */
    CY_SYSCLK_CLKMF_IN_ALTLF             = 3U, /**< clkMf is sourced by the Alternate Low Frequency Clock (ALTLF) */
    CY_SYSCLK_CLKMF_IN_PILO              = 4U, /**< clkMf is sourced by the precision low speed oscillator (PILO) */
    CY_SYSCLK_CLKMF_IN_ILO1              = 5U, /**< clkMf is sourced by the precision low speed oscillator (ILO1) */
    CY_SYSCLK_CLKMF_IN_ECO_PRESCALER     = 6U, /**< clkMf is sourced by the External Clock Oscillator (ECO Prescaler) */
    CY_SYSCLK_CLKMF_IN_LPECO             = 7U, /**< clkMf is sourced by the External Clock Oscillator (LPECO) */
} cy_en_clkmf_in_sources_t;

#endif

#endif /* defined (CY_IP_MXS40SSRSS) || defined (CY_IP_MXS28SRSS) || defined (CY_DOXYGEN) */

/** \} group_sysclk_mf_enums */

/**
* \addtogroup group_sysclk_mf_funcs
* \{
*/
#if defined (CY_IP_MXS40SSRSS) || defined (CY_IP_MXS28SRSS) || (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION < 2)) || defined (CY_DOXYGEN)

/*******************************************************************************
* Function Name: Cy_SysClk_MfoEnable
****************************************************************************//**
*
* Enables the MFO.
*
* \param deepSleepEnable enables MFO operation is Deep Sleep low power mode.
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_ClkMfEnable
*
*******************************************************************************/
void Cy_SysClk_MfoEnable(bool deepSleepEnable);


/*******************************************************************************
* Function Name: Cy_SysClk_MfoIsEnabled
****************************************************************************//**
*
* Reports whether MFO is enabled or not.
*
* \return
* false - disabled \n
* true  - enabled
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_ClkMfDisable
*
*******************************************************************************/
bool Cy_SysClk_MfoIsEnabled(void);


/*******************************************************************************
* Function Name: Cy_SysClk_MfoDisable
****************************************************************************//**
*
* Disables the MFO.
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_ClkMfDisable
*
*******************************************************************************/
void Cy_SysClk_MfoDisable(void);
#endif /* defined (CY_IP_MXS40SSRSS) || defined (CY_IP_MXS28SRSS) || (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION < 2)) || defined (CY_DOXYGEN) */

/** \cond internal */
#define CY_SYSCLK_MF_DIVIDER_MIN                  (1U)
#define CY_SYSCLK_MF_DIVIDER_MAX                  (256U)
#define CY_SYSCLK_IS_MF_DIVIDER_VALID(locDiv)     ((CY_SYSCLK_MF_DIVIDER_MIN <= (locDiv)) && ((locDiv) <= CY_SYSCLK_MF_DIVIDER_MAX))
#if defined (CY_IP_MXS40SSRSS) || defined (CY_IP_MXS28SRSS)
#define CY_SYSCLK_IF_MF_SOURCE_VALID(mfClkSrc)    (((mfClkSrc) == CY_SYSCLK_CLKMF_IN_MFO)     || \
                                                    ((mfClkSrc) == CY_SYSCLK_CLKMF_IN_ILO) || \
                                                    ((mfClkSrc) == CY_SYSCLK_CLKMF_IN_WCO) || \
                                                    ((mfClkSrc) == CY_SYSCLK_CLKMF_IN_ALTLF) || \
                                                    ((mfClkSrc) == CY_SYSCLK_CLKMF_IN_PILO) || \
                                                    ((mfClkSrc) == CY_SYSCLK_CLKMF_IN_ILO1) || \
                                                    ((mfClkSrc) == CY_SYSCLK_CLKMF_IN_ECO_PRESCALER))

#endif
/** \endcond */

#if (defined (CY_IP_MXS40SSRSS) && (CY_MXS40SSRSS_VER_1_2 == 0UL)) || defined (CY_IP_MXS28SRSS) || (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION < 2)) || defined (CY_DOXYGEN)
/*******************************************************************************
* Function Name: Cy_SysClk_ClkMfEnable
****************************************************************************//**
*
* Enables the CLK_MF.
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_ClkMfEnable
*
*******************************************************************************/
void Cy_SysClk_ClkMfEnable(void);


/*******************************************************************************
* Function Name: Cy_SysClk_ClkMfIsEnabled
****************************************************************************//**
*
* Reports whether CLK_MF is enabled or not.
*
* \return
* false - disabled \n
* true  - enabled
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_ClkMfEnable
*
*******************************************************************************/
bool Cy_SysClk_ClkMfIsEnabled(void);


/*******************************************************************************
* Function Name: Cy_SysClk_ClkMfDisable
****************************************************************************//**
*
* Disables the CLK_MF.
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_ClkMfDisable
*
*******************************************************************************/
void Cy_SysClk_ClkMfDisable(void);


/*******************************************************************************
* Function Name: Cy_SysClk_ClkMfSetDivider
****************************************************************************//**
*
* Sets the clock divider for CLK_MF.
*
* \pre If the CLK_MF is already enabled - it should be disabled
* prior to use this function by \ref Cy_SysClk_ClkMfDisable.
*
* \param divider divider value between 1 and 256.
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_ClkMfEnable
*
*******************************************************************************/
void Cy_SysClk_ClkMfSetDivider(uint32_t divider);


/*******************************************************************************
* Function Name: Cy_SysClk_ClkMfGetDivider
****************************************************************************//**
*
* Returns the clock divider of CLK_MF.
*
* \return divider value in range 1..256.
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_ClkMfEnable
*
*******************************************************************************/
uint32_t Cy_SysClk_ClkMfGetDivider(void);


/*******************************************************************************
* Function Name: Cy_SysClk_ClkMfGetFrequency
****************************************************************************//**
*
* Reports the output clock signal frequency of CLK_MF.
*
* \return The frequency, in Hz.
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_ClkMfEnable
*
*******************************************************************************/
uint32_t Cy_SysClk_ClkMfGetFrequency(void);

#endif /* (defined (CY_IP_MXS40SSRSS) && (CY_MXS40SSRSS_VER_1_2 == 0UL)) || defined (CY_IP_MXS28SRSS) || (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION < 2)) || defined (CY_DOXYGEN) */

/**
* \addtogroup group_sysclk_mf_funcs
* \{
*/
#if (defined (CY_IP_MXS40SSRSS) && (CY_MXS40SSRSS_VER_1_2 == 0UL)) || defined (CY_IP_MXS28SRSS) || (defined (CY_IP_MXS22SRSS) && (CY_IP_MXS22SRSS_VERSION == 2)) || defined (CY_DOXYGEN)

/*******************************************************************************
* Function Name: Cy_SysClk_ClkMfSetSource
****************************************************************************//**
*
* Sets the source for the Medium frequency clock(clkMf).
*
* \param source \ref cy_en_clkmf_in_sources_t
*
*******************************************************************************/
void Cy_SysClk_ClkMfSetSource(cy_en_clkmf_in_sources_t source);


/*******************************************************************************
* Function Name: Cy_SysClk_ClkMfGetSource
****************************************************************************//**
*
* Reports the source for the Medium frequency clock (clkMf).
*
* \return \ref cy_en_clkmf_in_sources_t
*
*******************************************************************************/
cy_en_clkmf_in_sources_t Cy_SysClk_ClkMfGetSource(void);

#endif /* (defined (CY_IP_MXS40SSRSS) && (CY_MXS40SSRSS_VER_1_2 == 0UL)) || defined (CY_IP_MXS28SRSS) */
/** \} group_sysclk_mf_funcs */

/* ========================================================================== */
/* =========================    clkHf[n] SECTION    ========================= */
/* ========================================================================== */
/**
* \addtogroup group_sysclk_clk_hf_enums
* \{
*/
/**
* Selects which clkHf input, or root mux, to configure.
* See CLK_ROOT_SELECT registers, bits ROOT_MUX.
* Used with functions \ref Cy_SysClk_ClkHfSetSource and \ref Cy_SysClk_ClkHfGetSource.
*/
typedef enum
{
    CY_SYSCLK_CLKHF_IN_CLKPATH0  = 0U,  /**< clkHf input is Clock Path 0 */
    CY_SYSCLK_CLKHF_IN_CLKPATH1  = 1U,  /**< clkHf input is Clock Path 1 */
    CY_SYSCLK_CLKHF_IN_CLKPATH2  = 2U,  /**< clkHf input is Clock Path 2 */
    CY_SYSCLK_CLKHF_IN_CLKPATH3  = 3U,  /**< clkHf input is Clock Path 3 */
    CY_SYSCLK_CLKHF_IN_CLKPATH4  = 4U,  /**< clkHf input is Clock Path 4 */
    CY_SYSCLK_CLKHF_IN_CLKPATH5  = 5U,  /**< clkHf input is Clock Path 5 */
    CY_SYSCLK_CLKHF_IN_CLKPATH6  = 6U,  /**< clkHf input is Clock Path 6 */
    CY_SYSCLK_CLKHF_IN_CLKPATH7  = 7U,  /**< clkHf input is Clock Path 7 */
    CY_SYSCLK_CLKHF_IN_CLKPATH8  = 8U,  /**< clkHf input is Clock Path 8 */
    CY_SYSCLK_CLKHF_IN_CLKPATH9  = 9U,  /**< clkHf input is Clock Path 9 */
    CY_SYSCLK_CLKHF_IN_CLKPATH10 = 10U, /**< clkHf input is Clock Path 10 */
    CY_SYSCLK_CLKHF_IN_CLKPATH11 = 11U, /**< clkHf input is Clock Path 11 */
    CY_SYSCLK_CLKHF_IN_CLKPATH12 = 12U, /**< clkHf input is Clock Path 12 */
    CY_SYSCLK_CLKHF_IN_CLKPATH13 = 13U, /**< clkHf input is Clock Path 13 */
    CY_SYSCLK_CLKHF_IN_CLKPATH14 = 14U, /**< clkHf input is Clock Path 14 */
    CY_SYSCLK_CLKHF_IN_CLKPATH15 = 15U, /**< clkHf input is Clock Path 15 */
} cy_en_clkhf_in_sources_t;


/** \} group_sysclk_clk_hf_enums */

/**
* \addtogroup group_sysclk_clk_hf_enums
* \{
*/
/**
* clkHf divider values. See CLK_ROOT_SELECT registers, bits ROOT_DIV.
* Used with functions \ref Cy_SysClk_ClkHfSetDivider and \ref Cy_SysClk_ClkHfGetDivider.
*/
#if defined (CY_IP_MXS22SRSS) || (defined (CY_MXS40SSRSS_VER_1_2) && (CY_MXS40SSRSS_VER_1_2 > 0UL))
typedef enum
{
    CY_SYSCLK_CLKHF_NO_DIVIDE    = 0U,    /**< don't divide clkHf */
    CY_SYSCLK_CLKHF_DIVIDE_BY_2  = 1U,    /**< divide clkHf by 2 */
    CY_SYSCLK_CLKHF_DIVIDE_BY_3  = 2U,    /**< divide clkHf by 3 */
    CY_SYSCLK_CLKHF_DIVIDE_BY_4  = 3U,     /**< divide clkHf by 4 */
    CY_SYSCLK_CLKHF_DIVIDE_BY_5  = 4U,    /**< divide clkHf by 5 */
    CY_SYSCLK_CLKHF_DIVIDE_BY_6  = 5U,    /**< divide clkHf by 6 */
    CY_SYSCLK_CLKHF_DIVIDE_BY_7  = 6U,     /**< divide clkHf by 7 */
    CY_SYSCLK_CLKHF_DIVIDE_BY_8  = 7U,    /**< divide clkHf by 8 */
    CY_SYSCLK_CLKHF_DIVIDE_BY_9  = 8U,    /**< divide clkHf by 9 */
    CY_SYSCLK_CLKHF_DIVIDE_BY_10 = 9U,     /**< divide clkHf by 10 */
    CY_SYSCLK_CLKHF_DIVIDE_BY_11 = 10U,   /**< divide clkHf by 11 */
    CY_SYSCLK_CLKHF_DIVIDE_BY_12 = 11U,   /**< divide clkHf by 12 */
    CY_SYSCLK_CLKHF_DIVIDE_BY_13 = 12U,    /**< divide clkHf by 13 */
    CY_SYSCLK_CLKHF_DIVIDE_BY_14 = 13U,   /**< divide clkHf by 14 */
    CY_SYSCLK_CLKHF_DIVIDE_BY_15 = 14U,   /**< divide clkHf by 15 */
    CY_SYSCLK_CLKHF_DIVIDE_BY_16 = 15U,   /**< divide clkHf by 16 */
    CY_SYSCLK_CLKHF_MAX_DIVIDER           /**< Max divider */
} cy_en_clkhf_dividers_t;
#endif

#if defined (CY_IP_MXS22SRSS) || (defined (CY_IP_MXS40SSRSS) && (CY_MXS40SSRSS_VER_1_2 > 0UL)) || \
    (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION >= 3))

/**
* clkhf csv reference clock input sources. See register CSV_REF_SEL
*/
#if defined (CY_IP_MXS22SRSS) || (defined (CY_IP_MXS40SSRSS) && (CY_MXS40SSRSS_VER_1_2 > 0UL))
typedef enum
{
    CY_SYSCLK_CLKHF_CSV_REF_IMO    = 0U,  /**< Reference clock is the IMO */
    CY_SYSCLK_CLKHF_CSV_REF_EXT    = 1U,  /**< Reference clock is the external clock */
    CY_SYSCLK_CLKHF_CSV_REF_ECO    = 2U,  /**< Reference clock is ECO */
    CY_SYSCLK_CLKHF_CSV_REF_ALTHF0 = 3U,  /**< Reference clock is ALTHF0 */
    CY_SYSCLK_CLKHF_CSV_REF_IHO    = 4U,  /**< Reference clock is IHO */
    CY_SYSCLK_CLKHF_CSV_REF_ALTHF1 = 5U   /**< Reference clock is ALTHF1 */
} cy_en_clkhf_csv_ref_clk_t;
#endif


/**
* clkhf csv supported action when an anomaly is detected.
*/
typedef enum
{
    CY_SYSCLK_CLKHF_CSV_ACTION_FAULT    = 0U,  /**< Generates a fault */
    CY_SYSCLK_CLKHF_CSV_ACTION_RESET    = 1U  /**< Generates a Reset */
} cy_en_clkhf_csv_action_t;
#endif /* CY_IP_MXS22SRSS, CY_IP_MXS40SSRSS && (CY_MXS40SSRSS_VER_1_2 > 0UL) || \
        * (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION >= 3)) */

/** \} group_sysclk_clk_hf_enums */



/**
* \addtogroup group_sysclk_clk_hf_structs
* \{
*/

#if defined (CY_IP_MXS22SRSS) || (defined (CY_IP_MXS40SSRSS) && (CY_MXS40SSRSS_VER_1_2 > 0UL))  || \
    (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION >= 3))

/**
* This structure is used to manually configure the clock supervisor for clkHf.
*/
typedef struct
{
    uint32_t startTime;    /**< Startup delay time, after enable or DeepSleep wakeup, from reference clock start to monitored clock start. */
    uint32_t lowerLimit;   /**< Lower limit in reference clock cycles, before the next monitored clock event is allowed to happen. */
    uint32_t upperLimit;   /**< Upper limit in reference clock cycles, before (or same time) the next monitored clock event must happen. */
    uint32_t period;     /**< Period in monitored clock cycles, before the next monitored clock event happens.  */
} cy_stc_clkhf_csv_manual_config_t;

/**
* This structure is used to select the HF clock and reference clock for csv configuration.
*/
typedef struct
{
    uint32_t clkHf;              /**< Configure CSV for the selected CLKHF */
    cy_en_clkhf_csv_ref_clk_t refClk;  /**< Reference clock */
} cy_stc_clkhf_csv_hf_config_t;
#endif

/** \} group_sysclk_clk_hf_structs */


/**
* \addtogroup group_sysclk_clk_hf_funcs
* \{
*/


/*******************************************************************************
* Function Name: Cy_SysClk_ClkHfEnable
****************************************************************************//**
*
* Enables the selected clkHf.
*
* \param clkHf Selects which clkHf to enable.
*
* \return \ref cy_en_sysclk_status_t
* CY_PRA_STATUS_* - For the PSOC 64 devices there are possible situations when
* function returns the PRA error status code \ref cy_en_pra_status_t instead of
* \ref cy_en_sysclk_status_t. This is because for PSOC 64 devices the function
* uses the PRA driver to change the protected registers. Refer to
* \ref cy_en_pra_status_t for more details.
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_ClkPathSetSource
*
*******************************************************************************/
cy_en_sysclk_status_t Cy_SysClk_ClkHfEnable(uint32_t clkHf);

/*******************************************************************************
* Function Name: Cy_SysClk_ClkHfEnable_Safe
****************************************************************************//**
*
* Verifies if selected clkHf could be enabled and if yes than enables it.
*
* \param clkHf Selects which clkHf to enable.
*
* \return \ref cy_en_sysclk_status_t
* CY_PRA_STATUS_* - For the PSOC 64 devices there are possible situations when
* function returns the PRA error status code \ref cy_en_pra_status_t instead of
* \ref cy_en_sysclk_status_t. This is because for PSOC 64 devices the function
* uses the PRA driver to change the protected registers. Refer to
* \ref cy_en_pra_status_t for more details.
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_ClkPathSetSource
*
*******************************************************************************/
cy_en_sysclk_status_t Cy_SysClk_ClkHfEnable_Safe(uint32_t clkHf);

/*******************************************************************************
* Function Name: Cy_SysClk_ClkHfIsEnabled
****************************************************************************//**
*
* Reports the Enabled/Disabled status of clkHf.
*
* \note This API is Secure Aware. On devices with ARM TrustZone enabled, it is safe
* to call on a Secure hardware resource from a Non-Secure CPU state.
* The involved PPC region is PROT_PERI0_SRSS_MAIN.
* See \ref group_sysclk_section_secure_aware for further details.
*
* \param clkHf Selects which clkHf to check.
*
* \return Boolean status of clkHf: true - Enabled, false - Disabled.
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_ClkHfDisable
*
*******************************************************************************/
bool Cy_SysClk_ClkHfIsEnabled(uint32_t clkHf);


/*******************************************************************************
* Function Name: Cy_SysClk_ClkHfDisable
****************************************************************************//**
*
* Disables the selected clkHf.
*
* \param clkHf Selects which clkHf to enable.
*
* \return \ref cy_en_sysclk_status_t
*
* \note clkHf[0] cannot be disabled.
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_ClkHfDisable
*
*******************************************************************************/
cy_en_sysclk_status_t Cy_SysClk_ClkHfDisable(uint32_t clkHf);


/*******************************************************************************
* Function Name: Cy_SysClk_ClkHfSetSource
****************************************************************************//**
*
* Selects the source of the selected clkHf.
*
* \param clkHf selects which clkHf mux to configure.
*
* \param source \ref cy_en_clkhf_in_sources_t
*
* \return \ref cy_en_sysclk_status_t
* CY_PRA_STATUS_* - For the PSOC 64 devices there are possible situations when
* function returns the PRA error status code \ref cy_en_pra_status_t instead of
* \ref cy_en_sysclk_status_t. This is because for PSOC 64 devices the function
* uses the PRA driver to change the protected registers. Refer to
* \ref cy_en_pra_status_t for more details.
*
* \note
* Call \ref SystemCoreClockUpdate after this function calling
* if it affects the CLK_HF0 frequency.
*
* \note
* Call \ref Cy_SysLib_SetWaitStates before calling this function if
* CLK_HF0 frequency is increasing.
*
* \note
* Call \ref Cy_SysLib_SetWaitStates after calling this function if
* CLK_HF0 frequency is decreasing.
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_ClkHfSetSource
*
* \note
* Take into account the possible platform specific clkHf (and further
* clocking chain links) frequency limitations while using this API.
*
* \note  It takes four cycles of the originally selected clock to switch away
* from it.  Do not disable the original clock during this time.
*
*******************************************************************************/
cy_en_sysclk_status_t Cy_SysClk_ClkHfSetSource(uint32_t clkHf, cy_en_clkhf_in_sources_t source);


/*******************************************************************************
* Function Name: Cy_SysClk_ClkHfGetSource
****************************************************************************//**
*
* Reports the source of the selected clkHf.
*
* \param clkHf selects which clkHf to get the source of.
*
* \return \ref cy_en_clkhf_in_sources_t
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_ClkHfSetSource
*
*******************************************************************************/
cy_en_clkhf_in_sources_t Cy_SysClk_ClkHfGetSource(uint32_t clkHf);


/*******************************************************************************
* Function Name: Cy_SysClk_ClkHfSetDivider
****************************************************************************//**
*
* Sets the pre-divider for a clkHf.
*
* \param clkHf selects which clkHf divider to configure.
*
* \param divider \ref cy_en_clkhf_dividers_t
*
* \return \ref cy_en_sysclk_status_t
* CY_PRA_STATUS_* - For the PSOC 64 devices there are possible situations when
* function returns the PRA error status code \ref cy_en_pra_status_t instead of
* \ref cy_en_sysclk_status_t. This is because for PSOC 64 devices the function
* uses the PRA driver to change the protected registers. Refer to
* \ref cy_en_pra_status_t for more details.
*
* \note Also call \ref Cy_SysClk_ClkHfSetSource to set the clkHf source.
*
* \note
* Call \ref SystemCoreClockUpdate after this function calling
* if it affects the CLK_HF0 frequency.
*
* \note
* Call \ref Cy_SysLib_SetWaitStates before calling this function if
* CLK_HF0 frequency is increasing.
*
* \note
* Call \ref Cy_SysLib_SetWaitStates after calling this function if
* CLK_HF0 frequency is decreasing.
*
* \note
* Take into account the possible platform specific clkHf (and further
* clocking chain links) frequency limitations while using this API.
*
* \note This API is Secure Aware. On devices with ARM TrustZone enabled, it is safe
* to call on a Secure hardware resource from a Non-Secure CPU state.
* The involved PPC region is PROT_PERI0_SRSS_MAIN.
* See \ref group_sysclk_section_secure_aware for further details.
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_ClkHfSetDivider
*
*******************************************************************************/
cy_en_sysclk_status_t Cy_SysClk_ClkHfSetDivider(uint32_t clkHf, cy_en_clkhf_dividers_t divider);


/*******************************************************************************
* Function Name: Cy_SysClk_ClkHfGetDivider
****************************************************************************//**
*
* Reports the pre-divider value for a clkHf.
*
* \note This API is Secure Aware. On devices with ARM TrustZone enabled, it is safe
* to call on a Secure hardware resource from a Non-Secure CPU state.
* The involved PPC region is PROT_PERI0_SRSS_MAIN.
* See \ref group_sysclk_section_secure_aware for further details.
*
* \param clkHf selects which clkHf to check divider of.
*
* \return \ref cy_en_clkhf_dividers_t
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_ClkHfSetDivider
*
*******************************************************************************/
cy_en_clkhf_dividers_t Cy_SysClk_ClkHfGetDivider(uint32_t clkHf);


/*******************************************************************************
* Function Name: Cy_SysClk_ClkHfGetFrequency
****************************************************************************//**
*
* Reports the frequency of the selected clkHf
*
* \param clkHf Selects the clkHf
*
* \return The frequency, in Hz.
*
* \note
* The reported frequency may be zero, which indicates unknown. This happens if
* the source input is dsi_out or clk_altlf.
*
* \note
* Calculates the HF frequency irrespective of whether HF is enabled or not.
*
* \note This API is Secure Aware. On devices with ARM TrustZone enabled, it is safe
* to call on a Secure hardware resource from a Non-Secure CPU state.
* The involved PPC regions are PROT_PERI0_SRSS_MAIN/PROT_PERI0_SRSS_GENERAL.
* Both PROT_PERI0_SRSS_MAIN/PROT_PERI0_SRSS_GENERAL should be either secure or non-secure.
* See \ref group_sysclk_section_secure_aware for further details.
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_ClkHfSetDivider
*
*******************************************************************************/
uint32_t Cy_SysClk_ClkHfGetFrequency(uint32_t clkHf);

#if defined (CY_IP_MXS40SSRSS) || defined (CY_IP_MXS22SRSS) || (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION >= 3)) || defined (CY_DOXYGEN)
/*******************************************************************************
* Function Name: Cy_SysClk_ClkHfDirectSel
****************************************************************************//**
*
* Enable/Disable the direct source selection as IMO for CLK_HF[[n]]
*
* \param clkHf Selects the clkHf
*
* \param enable True - Selects IMO/IHO (depending which is present on the device), False - Selects Root Mux
*
* \return \ref cy_en_sysclk_status_t
* CY_SYSCLK_BAD_PARAM - If clkhf is incorrect.
* CY_SYSCLK_SUCCESS - If successfully Enabled/Disabled.
*
*******************************************************************************/
cy_en_sysclk_status_t Cy_SysClk_ClkHfDirectSel(uint32_t clkHf, bool enable);

/*******************************************************************************
* Function Name: Cy_SysClk_IsClkHfDirectSelEnabled
****************************************************************************//**
*
* Checks if direct source selection as IMO for CLK_HF[[n]] is enabled/disabled
*
* \param clkHf Selects the clkHf
*
* \return
* True - IMO/IHO selected, False - Root Mux is selected.
*
*******************************************************************************/
bool Cy_SysClk_IsClkHfDirectSelEnabled(uint32_t clkHf);

#endif /* defined (CY_IP_MXS40SSRSS) || defined (CY_IP_MXS22SRSS) || (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION >= 3)) || defined (CY_DOXYGEN) */


#if defined (CY_IP_MXS22SRSS) || (defined (CY_IP_MXS40SSRSS) && (CY_MXS40SSRSS_VER_1_2 > 0UL)) || \
    ((defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION >= 3)) && defined(SRSS_CSV_HF_CSV_REF_CTL))

/*******************************************************************************
* Function Name: Cy_SysClk_ClkHfCsvGetRefFrequency
****************************************************************************//**
*
* Get the clkHf csv reference clock frequency.
*
* \param refClk Reference clock source.
*
* \return \ref cy_en_sysclk_status_t.
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_ClkHfCSVConfig
*
*******************************************************************************/
uint32_t Cy_SysClk_ClkHfCsvGetRefFrequency(cy_en_clkhf_csv_ref_clk_t refClk);


/*******************************************************************************
* Function Name: Cy_SysClk_ClkHfCsvManualConfigure
****************************************************************************//**
*
* Manually configures the clkHf csv based on user inputs.
*
* \param hfConfig Selects the clkHf, reference clock for csv operation.
*
* \param csvConfig Selects the csv configuration required.
*
* \return The frequency in Hz.
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_ClkHfCSVConfig
*
*******************************************************************************/
cy_en_sysclk_status_t Cy_SysClk_ClkHfCsvManualConfigure(const cy_stc_clkhf_csv_hf_config_t * hfConfig, const cy_stc_clkhf_csv_manual_config_t * csvConfig);


/*******************************************************************************
* Function Name: Cy_SysClk_ClkHfCsvConfigure
****************************************************************************//**
*
* Configures clkhf csv.
*
* The configuration formula used is:
* Lower_limit = Target - Required accuracy/2
* Upper_limit = Target + Required accuracy/2
* Period = Target / (Reference frequency / Monitor frequency)
* Start_time = (Period +3) * (Reference frequency / Monitor frequency) - Upper_limit
*
* \param hfConfig Selects the clkHf, reference clock for csv operation.
*
* \param accuracy Required accuracy.
*
* \return \ref cy_en_sysclk_status_t.
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_ClkHfCSVConfig
*
*******************************************************************************/
cy_en_sysclk_status_t Cy_SysClk_ClkHfCsvConfigure(const cy_stc_clkhf_csv_hf_config_t * hfConfig, uint32_t accuracy);


/*******************************************************************************
* Function Name: Cy_SysClk_ClkHfCsvAction
****************************************************************************//**
*
* Configures the action taken when an anomaly is detected on the clkHf.
*
* \param clkHf Selects the clkHf.
*
* \param action Action to be taken when anomaly is detected \ref cy_en_clkhf_csv_action_t
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_ClkHfCSVConfig
*
*******************************************************************************/
void Cy_SysClk_ClkHfCsvAction(uint32_t clkHf, cy_en_clkhf_csv_action_t action);


/*******************************************************************************
* Function Name: Cy_SysClk_ClkHfCsvEnable
****************************************************************************//**
*
* Enables the csv for the provided clkHf.
*
* \param clkHf Selects the clkHf.
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_ClkHfCSVConfig
*
*******************************************************************************/
void Cy_SysClk_ClkHfCsvEnable(uint32_t clkHf);


/*******************************************************************************
* Function Name: Cy_SysClk_ClkHfCsvDisable
****************************************************************************//**
*
* Disables the csv for the provided clkHf.
*
* \param clkHf Selects the clkHf.
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_ClkHfCSVConfig
*
*******************************************************************************/
void Cy_SysClk_ClkHfCsvDisable(uint32_t clkHf);


/*******************************************************************************
* Function Name: Cy_SysClk_IsClkHfCsvEnabled
****************************************************************************//**
*
* Returns the enabled status of csv for the provided clkHf.
*
* \param clkHf Selects the clkHf.
*
* \return \ref cy_en_sysclk_status_t.
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_ClkHfCSVConfig
*
*******************************************************************************/
bool Cy_SysClk_IsClkHfCsvEnabled(uint32_t clkHf);

#endif

/** \} group_sysclk_clk_hf_funcs */

/* ========================================================================== */
/* =========================    clk_fast SECTION    ========================= */
/* ========================================================================== */
/**
* \addtogroup group_sysclk_clk_fast_funcs
* \{
*/



/** \} group_sysclk_clk_fast_funcs */
#if defined (CY_IP_MXS28SRSS) || defined (CY_IP_MXS40SSRSS) || (defined (CY_IP_MXS40SRSS) && (CY_IP_MXPERI_VERSION >= 3))  || defined (CY_IP_MXS22SRSS)

/* ========================================================================== */
/* ========================    PERI SECTION    ========================== */
/* ========================================================================== */

/**
* \addtogroup group_sysclk_clk_peripheral_group_enums
* \{
*/
/**
* Slave control Register Numbers
*/
typedef enum
{
    CY_SYSCLK_PERI_GROUP_SL_CTL   = 0U,    /**<Selects SL_CTL*/
#if defined (CY_IP_MXS28SRSS) || defined (CY_IP_MXS40SSRSS)  || defined (CY_IP_MXS22SRSS)
    CY_SYSCLK_PERI_GROUP_SL_CTL2  = 1U,    /**<Selects SL_CTL2*/
    CY_SYSCLK_PERI_GROUP_SL_CTL3  = 2U,    /**<Selects SL_CTL3*/
#endif /* defined (CY_IP_MXS28SRSS) || defined (CY_IP_MXS40SSRSS)  || defined (CY_IP_MXS22SRSS) */
} cy_en_peri_grp_sl_ctl_num_t;

/** \} group_sysclk_clk_peripheral_group_enums */

/** \cond internal */
/* Macro to validate if the SL control register number passed */
#if defined (CY_IP_MXS28SRSS) || defined (CY_IP_MXS40SSRSS) || defined (CY_IP_MXS22SRSS)
#define CY_SYSCLK_IS_SL_CTL_NUM_VALID(slaveCtl)           (((slaveCtl) == CY_SYSCLK_PERI_GROUP_SL_CTL) || \
                                                           ((slaveCtl) == CY_SYSCLK_PERI_GROUP_SL_CTL2) || \
                                                           ((slaveCtl) == CY_SYSCLK_PERI_GROUP_SL_CTL3))
#endif

/** \endcond */


/**
* \addtogroup group_sysclk_clk_peripheral_group_funcs
* \{
*/
/*******************************************************************************
* Function Name: Cy_SysClk_PeriGroupSetDivider
****************************************************************************//**
*
* Sets the divider value for a particular group
*
* \return \ref cy_en_sysclk_status_t
*
* \param groupNum Selects the PERI Group Number
* \note
* Input of groupNum parameter will be
* group number
*
* \param divider Selects the divider value
*
* \note
* Clock divider functionality is product specific, Refer to TRM before using this API
* Example:-
* For 20829 devices Group-0 does not have the clock divider functionality.
* For XMC72 devices Group-0,1 and 2 does not have the clock divider functionality.
* For the above not supported groups this API will return success, but write will
* not happen.
*
* \note This API is Secure Aware. On devices with ARM TrustZone enabled, it is safe
* to call on a Secure hardware resource from a Non-Secure CPU state.
* The involved PPC region is PROT_PERIx_GRx_GROUP.
* See \ref group_sysclk_section_secure_aware for further details.
*
*******************************************************************************/
cy_en_sysclk_status_t Cy_SysClk_PeriGroupSetDivider(uint32_t groupNum, uint32_t divider);


/*******************************************************************************
* Function Name: Cy_SysClk_PeriGroupGetDivider
****************************************************************************//**
*
* Gets the divider value for a particular group
*
* \return Divider value
*
* \param groupNum Selects the PERI Group Number
* \note
* Input of groupNum parameter will be
* group number
*
* \note
* Clock divider functionality is product specific, Refer to TRM before using this API
* Example:-
* For 20829 devices Group-0 does not have the clock divider functionality.
* For XMC72 devices Group-0,1 and 2 does not have the clock divider functionality.
* For the above not supported groups this API returns zero.
*
* \note This API is Secure Aware. On devices with ARM TrustZone enabled, it is safe
* to call on a Secure hardware resource from a Non-Secure CPU state.
* The involved PPC region is PROT_PERIx_GRx_GROUP.
* See \ref group_sysclk_section_secure_aware for further details.
*
*******************************************************************************/
uint32_t Cy_SysClk_PeriGroupGetDivider(uint32_t groupNum);


/*******************************************************************************
* Function Name: Cy_SysClk_PeriGroupSetSlaveCtl
****************************************************************************//**
*
* Sets the particular Slave Control value for a particular group
*
* \return \ref cy_en_sysclk_status_t
*
* \param groupNum Selects the PERI Group Number
* \note
* Input of groupNum parameter will be
* group number
*
* \param slaveCtl Selects the Slave Control Register Number
*
* \param value Value to be written
*
*******************************************************************************/
cy_en_sysclk_status_t Cy_SysClk_PeriGroupSetSlaveCtl(uint32_t groupNum, cy_en_peri_grp_sl_ctl_num_t slaveCtl, uint32_t value);

/*******************************************************************************
* Function Name: Cy_SysClk_PeriGroupGetSlaveCtl
****************************************************************************//**
*
* Gets the particular Slave Control value for a particular group
*
* \return Slave Control register value for a particular group
*
* \param groupNum Selects the PERI Group Number
* \note
* Input of groupNum parameter will be
* group number
*
* \param slaveCtl Selects the Slave Control Register Number
*
*******************************************************************************/
uint32_t Cy_SysClk_PeriGroupGetSlaveCtl(uint32_t groupNum, cy_en_peri_grp_sl_ctl_num_t slaveCtl);

/*******************************************************************************
* Function Name: Cy_SysClk_IsPeriGroupSlaveCtlSet
****************************************************************************//**
*
* Gets the mask value of particular slave control register for a particular group
*
* \return Divider value
*
* \param groupNum Selects the PERI Group Number
* \note
* Input of groupNum parameter will be
* group number
*
* \param slaveCtl Selects the Slave Control Register Number
*
* \param slaveMsk Selects the bit position(s) that needs to be obtained
*
*******************************************************************************/
bool Cy_SysClk_IsPeriGroupSlaveCtlSet(uint32_t groupNum,cy_en_peri_grp_sl_ctl_num_t slaveCtl, uint32_t slaveMsk);


/** \} group_sysclk_clk_peripheral_group_funcs */
#endif /* defined (CY_IP_MXS28SRSS) || defined (CY_IP_MXS40SSRSS) || (defined (CY_IP_MXS40SRSS) && (CY_IP_MXPERI_VERSION >= 3))  || defined (CY_IP_MXS22SRSS) */

/* ========================================================================== */
/* ========================    clk_peri SECTION    ========================== */
/* ========================================================================== */

/* ========================================================================== */
/* =====================    clk_peripherals SECTION    ====================== */
/* ========================================================================== */
/**
* \addtogroup group_sysclk_clk_peripheral_enums
* \{
*/
/** Programmable clock divider types */
typedef enum
{
    CY_SYSCLK_DIV_8_BIT    = 0U, /**< Divider Type is an 8 bit divider */
    CY_SYSCLK_DIV_16_BIT   = 1U, /**< Divider Type is a 16 bit divider */
    CY_SYSCLK_DIV_16_5_BIT = 2U, /**< Divider Type is a 16.5 bit fractional divider */
    CY_SYSCLK_DIV_24_5_BIT = 3U  /**< Divider Type is a 24.5 bit fractional divider */
} cy_en_divider_types_t;
/** \} group_sysclk_clk_peripheral_enums */


/**
* \addtogroup group_sysclk_clk_peripheral_funcs
* \{
*/
#if defined (CY_IP_MXS28SRSS) || defined (CY_IP_MXS40SSRSS) || (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION >= 2)) || defined (CY_IP_MXS22SRSS)

/*******************************************************************************
* Function Name: Cy_SysClk_PeriPclkSetDivider
****************************************************************************//**
*
* Sets one of the programmable clock dividers. This is only used for integer
* dividers. Use \ref Cy_SysClk_PeriphSetFracDivider for setting factional dividers.
*
* \pre If the specified clock divider is already enabled - it should be disabled
* prior to use this function by \ref Cy_SysClk_PeriphDisableDivider.
*
* \note This API is Secure Aware. On devices with ARM TrustZone enabled, it is safe
* to call on a Secure hardware resource from a Non-Secure CPU state.
* The involved PPC region is PROT_PERIx_PERI_PCLKx_MAIN.
* See \ref group_sysclk_section_secure_aware for further details.
*
* \param ipBlock specifies ip block to connect the clock divider to.
*
* \param dividerType specifies which type of divider to use; \ref cy_en_divider_types_t
*
* \param dividerNum the divider number.
*
* \param dividerValue divider value
* Causes integer division of (divider value + 1), or division by 1 to 256
* (8-bit divider) or 1 to 65536 (16-bit divider).
*
* \return \ref cy_en_sysclk_status_t
*
*******************************************************************************/
cy_en_sysclk_status_t
                Cy_SysClk_PeriPclkSetDivider(en_clk_dst_t ipBlock, cy_en_divider_types_t dividerType,
                                           uint32_t dividerNum, uint32_t dividerValue);


/*******************************************************************************
* Function Name: Cy_SysClk_PeriPclkGetDivider
****************************************************************************//**
*
* Returns the integer divider value for the specified divider. One works for
* integer dividers. Use \ref Cy_SysClk_PeriphGetFracDivider to get the fractional
* divider value
*
* \note This API is Secure Aware. On devices with ARM TrustZone enabled, it is safe
* to call on a Secure hardware resource from a Non-Secure CPU state.
* The involved PPC region is PROT_PERIx_PERI_PCLKx_MAIN.
* See \ref group_sysclk_section_secure_aware for further details.
*
* \param ipBlock specifies ip block to connect the clock divider to.
*
* \param dividerType specifies which type of divider to use; \ref cy_en_divider_types_t
*
* \param dividerNum specifies which divider of the selected type to configure
*
* \return The divider value.
* The integer division done is by (divider value + 1), or division by 1 to 256
* (8-bit divider) or 1 to 65536 (16-bit divider).
*
*******************************************************************************/
uint32_t Cy_SysClk_PeriPclkGetDivider(en_clk_dst_t ipBlock, cy_en_divider_types_t dividerType, uint32_t dividerNum);


/*******************************************************************************
* Function Name: Cy_SysClk_PeriPclkGetFracDivider
****************************************************************************//**
*
* Reports the integer and fractional parts of the divider
*
* \note This API is Secure Aware. On devices with ARM TrustZone enabled, it is safe
* to call on a Secure hardware resource from a Non-Secure CPU state.
* The involved PPC region is PROT_PERIx_PERI_PCLKx_MAIN.
* See \ref group_sysclk_section_secure_aware for further details.
*
* \note Ensure that dividerIntValue and dividerFracValue arguments are DCache aligned
* when calling from a non-secured Core onto a secured hardware resource.  This is
* only relevent for cross-core calls, not calls between security contexts on the same
* core.
*
* \param ipBlock specifies ip block to connect the clock divider to.
*
* \param dividerType specifies which type of divider to use; \ref cy_en_divider_types_t
*
* \param dividerNum specifies which divider of the selected type to configure
*
* \param *dividerIntValue pointer to return integer divider value
*
* \param *dividerFracValue pointer to return fractional divider value
*
* \return None. Loads pointed-to variables.
*
*******************************************************************************/
void Cy_SysClk_PeriPclkGetFracDivider(en_clk_dst_t ipBlock, cy_en_divider_types_t dividerType, uint32_t dividerNum,
                                                    uint32_t *dividerIntValue, uint32_t *dividerFracValue);


/*******************************************************************************
* Function Name: Cy_SysClk_PeriPclkSetFracDivider
****************************************************************************//**
*
* Sets one of the programmable clock dividers. This function should only be used
* for fractional clock dividers.
*
* \pre If the specified clock divider is already enabled - it should be disabled
* prior to use this function by \ref Cy_SysClk_PeriphDisableDivider.
*
* \note This API is Secure Aware. On devices with ARM TrustZone enabled, it is safe
* to call on a Secure hardware resource from a Non-Secure CPU state.
* The involved PPC region is PROT_PERIx_PERI_PCLKx_MAIN.
* See \ref group_sysclk_section_secure_aware for further details.
*
* \param ipBlock specifies ip block to connect the clock divider to.
*
* \param dividerType specifies which type of divider to use; \ref cy_en_divider_types_t
*
* \param dividerNum specifies which divider of the selected type to configure
*
* \param dividerIntValue the integer divider value
* The source of the divider is peri_clk, which is a divided version of hf_clk[0].
* The divider value causes integer division of (divider value + 1), or division
* by 1 to 65536 (16-bit divider) or 1 to 16777216 (24-bit divider).
*
* \param dividerFracValue the fraction part of the divider
* The fractional divider can be 0-31, thus it divides the clock by 1/32 for each
* count. To divide the clock by 11/32nds set this value to 11.
*
* \return \ref cy_en_sysclk_status_t
*
*******************************************************************************/
cy_en_sysclk_status_t
                Cy_SysClk_PeriPclkSetFracDivider(en_clk_dst_t ipBlock, cy_en_divider_types_t dividerType, uint32_t dividerNum,
                                               uint32_t dividerIntValue, uint32_t dividerFracValue);


/*******************************************************************************
* Function Name: Cy_SysClk_PeriPclkAssignDivider
****************************************************************************//**
*
* Assigns a programmable divider to a selected IP block, such as a TCPWM or SCB.
*
* \param ipBlock specifies ip block to connect the clock divider to.
*
* \param dividerType specifies which type of divider to use; \ref cy_en_divider_types_t
*
* \param dividerNum specifies which divider of the selected type to configure
*
* \return \ref cy_en_sysclk_status_t
*
*******************************************************************************/
cy_en_sysclk_status_t
                Cy_SysClk_PeriPclkAssignDivider(en_clk_dst_t ipBlock,
                                              cy_en_divider_types_t dividerType, uint32_t dividerNum);


/*******************************************************************************
* Function Name: Cy_SysClk_PeriPclkGetAssignedDivider
****************************************************************************//**
*
* Reports which clock divider is assigned to a selected IP block.
*
* \note This API is Secure Aware. On devices with ARM TrustZone enabled, it is safe
* to call on a Secure hardware resource from a Non-Secure CPU state.
* The involved PPC region is PROT_PERIx_PERI_PCLKx_MAIN.
* See \ref group_sysclk_section_secure_aware for further details.
*
* \param ipBlock specifies ip block to connect the clock divider to.
*
* \return The divider type and number.  These are returned in one value, which can
* be split using the CY_PERI_CLOCK_CTL_DIV_SEL_Msk and CY_PERI_CLOCK_CTL_TYPE_SEL_Msk
* bitmasks.
*
*******************************************************************************/
uint32_t Cy_SysClk_PeriPclkGetAssignedDivider(en_clk_dst_t ipBlock);


/*******************************************************************************
* Function Name: Cy_SysClk_PeriPclkEnableDivider
****************************************************************************//**
*
* Enables the selected divider.
*
* \param ipBlock specifies ip block to connect the clock divider to.
*
* \param dividerType specifies which type of divider to use; \ref cy_en_divider_types_t
*
* \param dividerNum specifies which divider of the selected type to configure
*
* \note This function also sets the phase alignment bits such that the enabled
* divider is aligned to clk_peri. See \ref Cy_SysClk_PeriphDisableDivider()
* for information on how to phase-align a divider after it is enabled.
*
* \note This API is Secure Aware. On devices with ARM TrustZone enabled, it is safe
* to call on a Secure hardware resource from a Non-Secure CPU state.
* The involved PPC region is PROT_PERIx_PERI_PCLKx_MAIN.
* See \ref group_sysclk_section_secure_aware for further details..
*
*******************************************************************************/
cy_en_sysclk_status_t
                Cy_SysClk_PeriPclkEnableDivider(en_clk_dst_t ipBlock, cy_en_divider_types_t dividerType, uint32_t dividerNum);


/*******************************************************************************
* Function Name: Cy_SysClk_PeriPclkDisableDivider
****************************************************************************//**
*
* Disables a selected divider.
*
* \note This API is Secure Aware. On devices with ARM TrustZone enabled, it is safe
* to call on a Secure hardware resource from a Non-Secure CPU state.
* The involved PPC region is PROT_PERIx_PERI_PCLKx_MAIN.
* See \ref group_sysclk_section_secure_aware for further details.
*
* \param ipBlock specifies ip block to connect the clock divider to.
*
* \param dividerType specifies which type of divider to use; \ref cy_en_divider_types_t.
*
* \param dividerNum specifies which divider of the selected type to configure.
*
*******************************************************************************/
cy_en_sysclk_status_t
                Cy_SysClk_PeriPclkDisableDivider(en_clk_dst_t ipBlock, cy_en_divider_types_t dividerType, uint32_t dividerNum);


/*******************************************************************************
* Function Name: Cy_SysClk_PeriPclkEnablePhaseAlignDivider
****************************************************************************//**
*
* First disables a selected divider (\ref Cy_SysClk_PeriphDisableDivider),
* then aligns that divider to another programmable divider, and enables the
* selected divider. The divider to align to must already be enabled in order
* to align a divider to it.
*
* \param ipBlock specifies ip block to connect the clock divider to.
*
* \param dividerType specifies which type of divider to use; \ref cy_en_divider_types_t.
*
* \param dividerNum specifies which divider of the selected type to configure.
*
* \param dividerTypePA type of divider to phase-align to; \ref cy_en_divider_types_t.
*
* \param dividerNumPA divider number of type specified to phase align to.
*
* \note
* To phase-align a divider to clk_peri, set dividerTypePA to 3 and dividerNumPA
* to 63.
*
*******************************************************************************/
cy_en_sysclk_status_t
                Cy_SysClk_PeriPclkEnablePhaseAlignDivider(en_clk_dst_t ipBlock, cy_en_divider_types_t dividerType, uint32_t dividerNum,
                                                        cy_en_divider_types_t dividerTypePA, uint32_t dividerNumPA);

/*******************************************************************************
* Function Name: Cy_SysClk_PeriPclkGetFrequency
****************************************************************************//**
*
* Reports the frequency of the output of a given peripheral divider.
*
* \param ipBlock specifies ip block to connect the clock divider to.
*
* \param dividerType specifies which type of divider to use; \ref cy_en_divider_types_t
*
* \param dividerNum specifies which divider of the selected type to configure
*
* \return The frequency, in Hz.
*
* \note
* The reported frequency may be zero, which indicates unknown. This happens if
* the source input is dsi_out or clk_altlf.
*
* \note This API is Secure Aware. On devices with ARM TrustZone enabled, it is safe
* to call on a Secure hardware resource from a Non-Secure CPU state.
* The involved PPC region are PROT_PERIx_PERI_PCLKx_MAIN/PROT_PERI0_SRSS_MAIN/PROT_PERI0_SRSS_GENERAL.
* (PROT_PERIx_PERI_PCLKx_MAIN/PROT_PERI0_SRSS_MAIN/PROT_PERI0_SRSS_GENERAL) can be (secure/secure/secure),
* (non-secure/secure/secure), or (non-secure/non-secure/non-secure)
*
* See \ref group_sysclk_section_secure_aware for further details.
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_PeriphGetFrequency
*
*******************************************************************************/
uint32_t Cy_SysClk_PeriPclkGetFrequency(en_clk_dst_t ipBlock,
                                       cy_en_divider_types_t dividerType,
                                       uint32_t dividerNum);

/*******************************************************************************
* Function Name: Cy_SysClk_PeriPclkGetDividerEnabled
****************************************************************************//**
*
* Reports the enabled/disabled state of the selected divider.
*
* \param ipBlock specifies ip block to connect the clock divider to.
*
* \param dividerType specifies which type of divider to use; \ref cy_en_divider_types_t.
*
* \param dividerNum specifies which divider of the selected type to configure.
*
* \note This API is Secure Aware. On devices with ARM TrustZone enabled, it is safe
* to call on a Secure hardware resource from a Non-Secure CPU state.
* The involved PPC region is PROT_PERIx_PERI_PCLKx_MAIN.
* See \ref group_sysclk_section_secure_aware for further details.
*
*******************************************************************************/
bool Cy_SysClk_PeriPclkGetDividerEnabled(en_clk_dst_t ipBlock,
                                             cy_en_divider_types_t dividerType,
                                             uint32_t dividerNum);

/*******************************************************************************
* Function Name: Cy_Sysclk_PeriPclkGetClkHfNum
****************************************************************************//**
*
* Reports the corresponding CLK_HF* number for a particular PERI PCLK group
*
* \note For devices with ARM TrustZone enabled, this API is safe to call from both
* the secure and non-secure CPU state.  See \ref group_sysclk_section_secure_aware for
* further details.
*
* \param ipBlock specifies ip block to connect the clock divider to.
*
* \return The CLK_HF* number.
*
*******************************************************************************/
uint32_t Cy_Sysclk_PeriPclkGetClkHfNum(uint32_t ipBlock);

#endif /* defined (CY_IP_MXS28SRSS) || defined (CY_IP_MXS40SSRSS) || (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION >= 2)) || defined (CY_IP_MXS22SRSS) */

/*******************************************************************************
* Function Name: Cy_SysClk_PeriphSetDivider
****************************************************************************//**
*
* Sets one of the programmable clock dividers. This is only used for integer
* dividers. Use \ref Cy_SysClk_PeriphSetFracDivider for setting factional dividers.
*
* \pre If the specified clock divider is already enabled - it should be disabled
* prior to use this function by \ref Cy_SysClk_PeriphDisableDivider.
*
* \param dividerType specifies which type of divider to use; \ref cy_en_divider_types_t
*
* \param dividerNum the divider number.
*
* \param dividerValue divider value
* Causes integer division of (divider value + 1), or division by 1 to 256
* (8-bit divider) or 1 to 65536 (16-bit divider).
*
* \return \ref cy_en_sysclk_status_t
*
* \note
* This API is deprecated, use Cy_SysClk_PeriPclkSetDivider.
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_PeriphSetDivider
*
*******************************************************************************/
cy_en_sysclk_status_t
                Cy_SysClk_PeriphSetDivider(cy_en_divider_types_t dividerType,
                                           uint32_t dividerNum, uint32_t dividerValue);


/*******************************************************************************
* Function Name: Cy_SysClk_PeriphGetDivider
****************************************************************************//**
*
* Returns the integer divider value for the specified divider. One works for
* integer dividers. Use \ref Cy_SysClk_PeriphGetFracDivider to get the fractional
* divider value
*
* \param dividerType specifies which type of divider to use; \ref cy_en_divider_types_t
*
* \param dividerNum specifies which divider of the selected type to configure
*
* \return The divider value.
* The integer division done is by (divider value + 1), or division by 1 to 256
* (8-bit divider) or 1 to 65536 (16-bit divider).
*
* \note
* This API is deprecated, use Cy_SysClk_PeriPclkGetDivider.
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_PeriphSetDivider
*
*******************************************************************************/
uint32_t Cy_SysClk_PeriphGetDivider(cy_en_divider_types_t dividerType, uint32_t dividerNum);


/*******************************************************************************
* Function Name: Cy_SysClk_PeriphSetFracDivider
****************************************************************************//**
*
* Sets one of the programmable clock dividers. This function should only be used
* for fractional clock dividers.
*
* \pre If the specified clock divider is already enabled - it should be disabled
* prior to use this function by \ref Cy_SysClk_PeriphDisableDivider.
*
* \param dividerType specifies which type of divider to use; \ref cy_en_divider_types_t
*
* \param dividerNum specifies which divider of the selected type to configure
*
* \param dividerIntValue the integer divider value
* The source of the divider is peri_clk, which is a divided version of hf_clk[0].
* The divider value causes integer division of (divider value + 1), or division
* by 1 to 65536 (16-bit divider) or 1 to 16777216 (24-bit divider).
*
* \param dividerFracValue the fraction part of the divider
* The fractional divider can be 0-31, thus it divides the clock by 1/32 for each
* count. To divide the clock by 11/32nds set this value to 11.
*
* \return \ref cy_en_sysclk_status_t
*
* \note
* This API is deprecated, use Cy_SysClk_PeriPclkSetFracDivider.
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_PeriphSetFracDivider
*
*******************************************************************************/
cy_en_sysclk_status_t
                Cy_SysClk_PeriphSetFracDivider(cy_en_divider_types_t dividerType, uint32_t dividerNum,
                                               uint32_t dividerIntValue, uint32_t dividerFracValue);


/*******************************************************************************
* Function Name: Cy_SysClk_PeriphGetFracDivider
****************************************************************************//**
*
* Reports the integer and fractional parts of the divider
*
* \param dividerType specifies which type of divider to use; \ref cy_en_divider_types_t
*
* \param dividerNum specifies which divider of the selected type to configure
*
* \param *dividerIntValue pointer to return integer divider value
*
* \param *dividerFracValue pointer to return fractional divider value
*
* \return None. Loads pointed-to variables.
*
* \note
* This API is deprecated, use Cy_SysClk_PeriPclkGetFracDivider.
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_PeriphSetFracDivider
*
*******************************************************************************/
void Cy_SysClk_PeriphGetFracDivider(cy_en_divider_types_t dividerType, uint32_t dividerNum,
                                                    uint32_t *dividerIntValue, uint32_t *dividerFracValue);


/*******************************************************************************
* Function Name: Cy_SysClk_PeriphAssignDivider
****************************************************************************//**
*
* Assigns a programmable divider to a selected IP block, such as a TCPWM or SCB.
*
* \param ipBlock specifies ip block to connect the clock divider to.
*
* \param dividerType specifies which type of divider to use; \ref cy_en_divider_types_t
*
* \param dividerNum specifies which divider of the selected type to configure
*
* \return \ref cy_en_sysclk_status_t
*
* \note
* This API is deprecated, use Cy_SysClk_PeriPclkAssignDivider.
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_PeriphAssignDivider
*
*******************************************************************************/
cy_en_sysclk_status_t
                Cy_SysClk_PeriphAssignDivider(en_clk_dst_t ipBlock,
                                              cy_en_divider_types_t dividerType, uint32_t dividerNum);


/*******************************************************************************
* Function Name: Cy_SysClk_PeriphGetAssignedDivider
****************************************************************************//**
*
* Reports which clock divider is assigned to a selected IP block.
*
* \param ipBlock specifies ip block to connect the clock divider to.
*
* \return The divider type and number
*
* \note
* This API is deprecated, use Cy_SysClk_PeriPclkGetAssignedDivider.
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_PeriphAssignDivider
*
*******************************************************************************/
uint32_t Cy_SysClk_PeriphGetAssignedDivider(en_clk_dst_t ipBlock);


/*******************************************************************************
* Function Name: Cy_SysClk_PeriphEnableDivider
****************************************************************************//**
*
* Enables the selected divider.
*
* \param dividerType specifies which type of divider to use; \ref cy_en_divider_types_t
*
* \param dividerNum specifies which divider of the selected type to configure
*
* \note This function also sets the phase alignment bits such that the enabled
* divider is aligned to clk_peri. See \ref Cy_SysClk_PeriphDisableDivider()
* for information on how to phase-align a divider after it is enabled.
*
* \note
* This API is deprecated , use Cy_SysClk_PeriPclkEnableDivider.
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_PeriphEnableDivider
*
*******************************************************************************/
cy_en_sysclk_status_t
                Cy_SysClk_PeriphEnableDivider(cy_en_divider_types_t dividerType, uint32_t dividerNum);


/*******************************************************************************
* Function Name: Cy_SysClk_PeriphDisableDivider
****************************************************************************//**
*
* Disables a selected divider.
*
* \param dividerType specifies which type of divider to use; \ref cy_en_divider_types_t.
*
* \param dividerNum specifies which divider of the selected type to configure.
*
* \note
* This API is deprecated, use Cy_SysClk_PeriPclkDisableDivider.
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_PeriphDisableDivider
*
*******************************************************************************/
cy_en_sysclk_status_t
                Cy_SysClk_PeriphDisableDivider(cy_en_divider_types_t dividerType, uint32_t dividerNum);


/*******************************************************************************
* Function Name: Cy_SysClk_PeriphEnablePhaseAlignDivider
****************************************************************************//**
*
* First disables a selected divider (\ref Cy_SysClk_PeriphDisableDivider),
* then aligns that divider to another programmable divider, and enables the
* selected divider. The divider to align to must already be enabled in order
* to align a divider to it.
*
* \param dividerType specifies which type of divider to use; \ref cy_en_divider_types_t.
*
* \param dividerNum specifies which divider of the selected type to configure.
*
* \param dividerTypePA type of divider to phase-align to; \ref cy_en_divider_types_t.
*
* \param dividerNumPA divider number of type specified to phase align to.
*
* \note
* To phase-align a divider to clk_peri, set dividerTypePA to 3 and dividerNumPA
* to 63.
*
* \note
* This API is deprecated, use Cy_SysClk_PeriPclkEnablePhaseAlignDivider.
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_PeriphEnablePhaseAlignDivider
*
*******************************************************************************/
cy_en_sysclk_status_t
                Cy_SysClk_PeriphEnablePhaseAlignDivider(cy_en_divider_types_t dividerType, uint32_t dividerNum,
                                                        cy_en_divider_types_t dividerTypePA, uint32_t dividerNumPA);


/*******************************************************************************
* Function Name: Cy_SysClk_PeriphGetDividerEnabled
****************************************************************************//**
*
* Reports the enabled/disabled state of the selected divider.
*
* \param dividerType specifies which type of divider to use; \ref cy_en_divider_types_t.
*
* \param dividerNum specifies which divider of the selected type to configure.
*
* \return The enabled/disabled state; \n
* false = disabled \n
* true = enabled
*
* \note
* This API is deprecated, use Cy_SysClk_PeriPclkGetDividerEnabled.
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_PeriphGetDividerEnabled
*
*******************************************************************************/
bool Cy_SysClk_PeriphGetDividerEnabled(cy_en_divider_types_t dividerType, uint32_t dividerNum);


/*******************************************************************************
* Function Name: Cy_SysClk_PeriphGetFrequency
****************************************************************************//**
*
* Reports the frequency of the output of a given peripheral divider.
*
* \param dividerType specifies which type of divider to use; \ref cy_en_divider_types_t
*
* \param dividerNum specifies which divider of the selected type to configure
*
* \return The frequency, in Hz.
*
* \note
* The reported frequency may be zero, which indicates unknown. This happens if
* the source input is dsi_out or clk_altlf.
*
* \note
* This API is deprecated, use Cy_SysClk_PeriPclkGetFrequency.
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_PeriphGetFrequency
*
*******************************************************************************/
uint32_t Cy_SysClk_PeriphGetFrequency(cy_en_divider_types_t dividerType, uint32_t dividerNum);


/** \} group_sysclk_clk_peripheral_funcs */


/* ========================================================================== */
/* =========================    clk_slow SECTION    ========================= */
/* ========================================================================== */


/** \} group_sysclk_clk_mem_funcs */

/* ========================================================================== */
/* ===========================    clkLf SECTION    ========================== */
/* ========================================================================== */
/**
* \addtogroup group_sysclk_clk_lf_enums
* \{
*/
/**
* Low frequency (clkLf) input sources. See CLK_SELECT register, LFCLK_SEL bits.
* Used with functions \ref Cy_SysClk_ClkLfSetSource, and \ref Cy_SysClk_ClkLfGetSource.
*/
#if !defined(CY_IP_MXS22SRSS)
typedef enum
{
    CY_SYSCLK_CLKLF_IN_ILO               = 0U, /**< clkLf is sourced by the internal low speed oscillator (ILO) */
    CY_SYSCLK_CLKLF_IN_WCO               = 1U, /**< clkLf is sourced by the watch crystal oscillator (WCO) */
    CY_SYSCLK_CLKLF_IN_ALTLF             = 2U, /**< clkLf is sourced by the Alternate Low Frequency Clock (ALTLF) */
    CY_SYSCLK_CLKLF_IN_PILO              = 3U, /**< clkLf is sourced by the precision low speed oscillator (PILO) */
    CY_SYSCLK_CLKLF_IN_ILO1              = 4U, /**< clkLf is sourced by the internal low speed oscillator (ILO1)*/
    CY_SYSCLK_CLKLF_IN_ECO_PRESCALER     = 5U, /**< clkLf is sourced by the External Clock Oscillator (ECO Prescaler) */
    CY_SYSCLK_CLKLF_IN_LPECO_PRESCALER   = 6U, /**< clkLf is sourced by the External Clock Oscillator (LP ECO Prescaler) */
    CY_SYSCLK_CLKLF_IN_MAX               = 7U  /**< clkLf MAX value*/
} cy_en_clklf_in_sources_t;

#endif /* defined (CY_IP_MXS22SRSS) */

#if defined (CY_IP_MXS22SRSS) || (defined (CY_IP_MXS40SSRSS) && (CY_MXS40SSRSS_VER_1_2 > 0UL)) || \
    (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION >= 3))
/**
* clklf csv reference clock input sources.
*/
#if (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION >= 3))
typedef enum
{
    CY_SYSCLK_CLKLF_CSV_REF_ILO0   = 0U,  /**< Only Reference clock is the internal low speed oscillator (ILO0) */
    CY_SYSCLK_CLKLF_CSV_REF_ILO1   = 1U,  /**< Only Reference clock is the internal low speed oscillator (ILO1) */
} cy_en_clklf_csv_ref_clk_t;

#else
typedef enum
{
    CY_SYSCLK_CLKLF_CSV_REF_IMO    = 0U,  /**< Reference clock is the IMO */
    CY_SYSCLK_CLKLF_CSV_REF_EXT    = 1U,  /**< Reference clock is the external clock */
    CY_SYSCLK_CLKLF_CSV_REF_ECO    = 2U,  /**< Reference clock is ECO */
    CY_SYSCLK_CLKLF_CSV_REF_ALTHF0 = 3U,  /**< Reference clock is ALTHF0 */
    CY_SYSCLK_CLKLF_CSV_REF_IHO    = 4U,  /**< Reference clock is IHO */
    CY_SYSCLK_CLKLF_CSV_REF_ALTHF1 = 5U   /**< Reference clock is ALTHF1 */
} cy_en_clklf_csv_ref_clk_t;
#endif
#endif
/** \} group_sysclk_clk_lf_enums */

/**
* \addtogroup group_sysclk_clk_lf_structs
* \{
*/
#if defined (CY_IP_MXS22SRSS) || (defined (CY_IP_MXS40SSRSS) && (CY_MXS40SSRSS_VER_1_2 > 0UL)) || \
    (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION >= 3))
/** Manual CSV configuration struct */
typedef struct
{
    uint32_t startTime;    /**< Startup delay time, after enable or DeepSleep wakeup, from reference clock start to monitored clock start. */
    uint32_t lowerLimit;   /**< Lower limit in reference clock cycles, before the next monitored clock event is allowed to happen. */
    uint32_t upperLimit;   /**< Upper limit in reference clock cycles, before (or same time) the next monitored clock event must happen. */
    uint32_t period;       /**< Period in monitored clock cycles, before the next monitored clock event happens.  */
} cy_stc_clklf_csv_manual_config_t;

#endif

/** \} group_sysclk_clk_lf_structs */


/**
* \addtogroup group_sysclk_clk_lf_funcs
* \{
*/
/*******************************************************************************
* Function Name: Cy_SysClk_ClkLfSetSource
****************************************************************************//**
*
* Sets the source for the low frequency clock(clkLf).
*
* \param source \ref cy_en_clklf_in_sources_t
*
* \note The watchdog timer (WDT) must be unlocked before calling this function.
*
* \note  It takes four cycles of the originally selected clock to switch away
* from it.  Do not disable the original clock during this time.
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_ClkLfSetSource
*
*******************************************************************************/
void Cy_SysClk_ClkLfSetSource(cy_en_clklf_in_sources_t source);


/*******************************************************************************
* Function Name: Cy_SysClk_ClkLfGetSource
****************************************************************************//**
*
* Reports the source for the low frequency clock (clkLf).
*
* \return \ref cy_en_clklf_in_sources_t
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_ClkLfSetSource
*
*******************************************************************************/
cy_en_clklf_in_sources_t Cy_SysClk_ClkLfGetSource(void);


#if defined (CY_IP_MXS22SRSS) || (defined (CY_IP_MXS40SSRSS) && (CY_MXS40SSRSS_VER_1_2 > 0UL)) || \
    (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION >= 3))

/*******************************************************************************
* Function Name: Cy_SysClk_ClkLfGetFrequency
****************************************************************************//**
*
* Reports the frequency of the clklf
*
* \return The frequency, in Hz.
*
* \note This API is Secure Aware. On devices with ARM TrustZone enabled, it is safe
* to call on a Secure hardware resource from a Non-Secure CPU state.
* The involved PPC region is PROT_PERI0_SRSS_MAIN.
* See \ref group_sysclk_section_secure_aware for further details.
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_ClkLfCSVConfig
*
*******************************************************************************/
uint32_t Cy_SysClk_ClkLfGetFrequency(void);
#endif /* defined (CY_IP_MXS22SRSS) || (defined (CY_IP_MXS40SSRSS) && (CY_MXS40SSRSS_VER_1_2 > 0UL)) || \
    (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION >= 3)) */


#if defined (CY_IP_MXS22SRSS) || (defined (CY_IP_MXS40SSRSS) && (CY_MXS40SSRSS_VER_1_2 > 0UL)) || \
    ((defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION >= 3)) && defined(SRSS_CSV_LF_CSV_REF_CTL))
/*******************************************************************************
* Function Name: Cy_SysClk_ClkLfCsvGetRefFrequency
****************************************************************************//**
*
* Get the clklf csv reference clock frequency.
*
* \param refClk Reference clock source.
*
* \return \ref cy_en_sysclk_status_t.
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_ClkLfCSVConfig
*
*******************************************************************************/
uint32_t Cy_SysClk_ClkLfCsvGetRefFrequency(cy_en_clklf_csv_ref_clk_t refClk);


/*******************************************************************************
* Function Name: Cy_SysClk_ClkLfCsvManualConfigure
****************************************************************************//**
*
* Manually configures the clklf csv based on user inputs.
*
* \param refClk Reference clock for csv operation.
*
* \param csvConfig Selects the csv configuration required.
*
* \return The frequency in Hz.
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_ClkLfCSVConfig
*
*******************************************************************************/
cy_en_sysclk_status_t Cy_SysClk_ClkLfCsvManualConfigure(cy_en_clklf_csv_ref_clk_t refClk, const cy_stc_clklf_csv_manual_config_t * csvConfig);


/*******************************************************************************
* Function Name: Cy_SysClk_ClkLfCsvConfigure
****************************************************************************//**
*
* Configures clklf csv.
*
* The configuration formula used is:
* Lower_limit = Target - Required accuracy/2
* Upper_limit = Target + Required accuracy/2
* Period = Target / (Reference frequency / Monitor frequency)
* Start_time = (Period +3) * (Reference frequency / Monitor frequency) - Upper_limit
*
* \param refClk Selects the reference clock for csv operation.
*
* \param accuracy Required accuracy.
*
* \return \ref cy_en_sysclk_status_t.
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_ClkLfCSVConfig
*
*******************************************************************************/
cy_en_sysclk_status_t Cy_SysClk_ClkLfCsvConfigure(cy_en_clklf_csv_ref_clk_t refClk, uint32_t accuracy);


/*******************************************************************************
* Function Name: Cy_SysClk_ClkLfCsvEnable
****************************************************************************//**
*
* Enables the csv for the clklf.
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_ClkLfCSVConfig
*
*******************************************************************************/
void Cy_SysClk_ClkLfCsvEnable(void);


/*******************************************************************************
* Function Name: Cy_SysClk_ClkLfCsvDisable
****************************************************************************//**
*
* Disables the csv for the clklf.
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_ClkLfCSVConfig
*
*******************************************************************************/
void Cy_SysClk_ClkLfCsvDisable(void);


/*******************************************************************************
* Function Name: Cy_SysClk_IsClkLfCsvEnabled
****************************************************************************//**
*
* Returns the enabled status of csv for the clklf.
*
* \return \ref cy_en_sysclk_status_t.
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_ClkLfCSVConfig
*
*******************************************************************************/
bool Cy_SysClk_IsClkLfCsvEnabled(void);

#endif

/** \} group_sysclk_clk_lf_funcs */




/* ========================================================================== */
/* ========================    clk_timer SECTION    ========================= */
/* ========================================================================== */


/** \} group_sysclk_clk_timer_funcs */

#if defined (CY_IP_MXS40SSRSS) || (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION < 2))
/* ========================================================================== */
/* =========================    clk_pump SECTION    ========================= */
/* ========================================================================== */
/**
* \addtogroup group_sysclk_clk_pump_enums
* \{
*/

/**
* Pump clock (clk_pump) input sources. See CLK_SELECT register, PUMP_SEL bits.
* Used with functions \ref Cy_SysClk_ClkPumpSetSource, and
* \ref Cy_SysClk_ClkPumpGetSource.
*/
typedef enum
{
    CY_SYSCLK_PUMP_IN_CLKPATH0  = 0UL,  /**< Pump clock input is clock path 0 */
    CY_SYSCLK_PUMP_IN_CLKPATH1  = 1UL,  /**< Pump clock input is clock path 1 */
    CY_SYSCLK_PUMP_IN_CLKPATH2  = 2UL,  /**< Pump clock input is clock path 2 */
    CY_SYSCLK_PUMP_IN_CLKPATH3  = 3UL,  /**< Pump clock input is clock path 3 */
    CY_SYSCLK_PUMP_IN_CLKPATH4  = 4UL,  /**< Pump clock input is clock path 4 */
    CY_SYSCLK_PUMP_IN_CLKPATH5  = 5UL,  /**< Pump clock input is clock path 5 */
    CY_SYSCLK_PUMP_IN_CLKPATH6  = 6UL,  /**< Pump clock input is clock path 6 */
    CY_SYSCLK_PUMP_IN_CLKPATH7  = 7UL,  /**< Pump clock input is clock path 7 */
    CY_SYSCLK_PUMP_IN_CLKPATH8  = 8UL,  /**< Pump clock input is clock path 8 */
    CY_SYSCLK_PUMP_IN_CLKPATH9  = 9UL,  /**< Pump clock input is clock path 9 */
    CY_SYSCLK_PUMP_IN_CLKPATH10 = 10UL, /**< Pump clock input is clock path 10 */
    CY_SYSCLK_PUMP_IN_CLKPATH11 = 11UL, /**< Pump clock input is clock path 11 */
    CY_SYSCLK_PUMP_IN_CLKPATH12 = 12UL, /**< Pump clock input is clock path 12 */
    CY_SYSCLK_PUMP_IN_CLKPATH13 = 13UL, /**< Pump clock input is clock path 13 */
    CY_SYSCLK_PUMP_IN_CLKPATH14 = 14UL, /**< Pump clock input is clock path 14 */
    CY_SYSCLK_PUMP_IN_CLKPATH15 = 15UL  /**< Pump clock input is clock path 15 */
} cy_en_clkpump_in_sources_t;

/**
* Pump clock (clk_pump) divide options. See CLK_SELECT register, PUMP_DIV bits.
* Used with functions \ref Cy_SysClk_ClkPumpSetDivider, and
* \ref Cy_SysClk_ClkPumpGetDivider.
*/
typedef enum
{
    CY_SYSCLK_PUMP_NO_DIV = 0U, /**< No division on pump clock */
    CY_SYSCLK_PUMP_DIV_2  = 1U, /**< Pump clock divided by 2 */
    CY_SYSCLK_PUMP_DIV_4  = 2U, /**< Pump clock divided by 4 */
    CY_SYSCLK_PUMP_DIV_8  = 3U, /**< Pump clock divided by 8 */
    CY_SYSCLK_PUMP_DIV_16 = 4U  /**< Pump clock divided by 16 */
} cy_en_clkpump_divide_t;
/** \} group_sysclk_clk_pump_enums */

/** \cond */
#define  CY_SYSCLK_FLL_IS_DIVIDER_VALID(div) (((div) == CY_SYSCLK_PUMP_NO_DIV) || \
                                              ((div) == CY_SYSCLK_PUMP_DIV_2)  || \
                                              ((div) == CY_SYSCLK_PUMP_DIV_4)  || \
                                              ((div) == CY_SYSCLK_PUMP_DIV_8)  || \
                                              ((div) == CY_SYSCLK_PUMP_DIV_16))
/** \endcond */

/**
* \addtogroup group_sysclk_clk_pump_funcs
* \{
*/
/*******************************************************************************
* Function Name: Cy_SysClk_ClkPumpSetSource
****************************************************************************//**
*
* Sets the source for the pump clock (clk_pump). The pump clock can be used for
* the analog pumps in the CTBm block.
*
* \param source \ref cy_en_clkpump_in_sources_t
*
* \note
* Do not change the source while the pump clock is enabled.
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_ClkPumpSetSource
*
*******************************************************************************/
void Cy_SysClk_ClkPumpSetSource(cy_en_clkpump_in_sources_t source);


/*******************************************************************************
* Function Name: Cy_SysClk_ClkPumpGetSource
****************************************************************************//**
*
* Reports the source for the pump clock (clk_pump).
*
* \return \ref cy_en_clkpump_in_sources_t
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_ClkPumpSetSource
*
*******************************************************************************/
cy_en_clkpump_in_sources_t Cy_SysClk_ClkPumpGetSource(void);


/*******************************************************************************
* Function Name: Cy_SysClk_ClkPumpSetDivider
****************************************************************************//**
*
* Sets the divider of the pump clock (clk_pump).
*
* \param divider \ref cy_en_clkpump_divide_t
*
* \note
* Do not change the divider value while the pump clock is enabled.
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_ClkPumpSetDivider
*
*******************************************************************************/
void Cy_SysClk_ClkPumpSetDivider(cy_en_clkpump_divide_t divider);


/*******************************************************************************
* Function Name: Cy_SysClk_ClkPumpGetDivider
****************************************************************************//**
*
* Reports the divider value for the pump clock (clk_pump).
*
* \return \ref cy_en_clkpump_divide_t
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_ClkPumpSetDivider
*
*******************************************************************************/
cy_en_clkpump_divide_t Cy_SysClk_ClkPumpGetDivider(void);


/*******************************************************************************
* Function Name: Cy_SysClk_ClkPumpEnable
****************************************************************************//**
*
* Enables the pump clock (clk_pump). The pump clock can be used for the analog
* pumps in the CTBm block.
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_ClkPumpEnable
*
*******************************************************************************/
void Cy_SysClk_ClkPumpEnable(void);


/*******************************************************************************
* Function Name: Cy_SysClk_ClkPumpIsEnabled
****************************************************************************//**
*
* Reports the Enabled/Disabled status of the ClkPump.
*
* \return Boolean status of ClkPump: true - Enabled, false - Disabled.
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_ClkPumpDisable
*
*******************************************************************************/
bool Cy_SysClk_ClkPumpIsEnabled(void);


/*******************************************************************************
* Function Name: Cy_SysClk_ClkPumpDisable
****************************************************************************//**
*
* Disables the pump clock (clk_pump).
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_ClkPumpDisable
*
*******************************************************************************/
void Cy_SysClk_ClkPumpDisable(void);


/*******************************************************************************
* Function Name: Cy_SysClk_ClkPumpGetFrequency
****************************************************************************//**
*
* Reports the frequency of the pump clock (clk_pump).
* \note If the the pump clock is not enabled - a zero frequency is reported.
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_ClkPumpEnable
*
*******************************************************************************/
uint32_t Cy_SysClk_ClkPumpGetFrequency(void);
/** \} group_sysclk_clk_pump_funcs */
#endif /* defined (CY_IP_MXS40SSRSS) || (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION < 2)) */

/* ========================================================================== */
/* ==========================    clk_bak SECTION    ========================= */
/* ========================================================================== */
/**
* \addtogroup group_sysclk_clk_bak_enums
* \{
*/
/**
* Backup domain clock (clk_bak) input sources. See BACKUP->CTL register,
* CLK_SEL bits. Used with functions \ref Cy_SysClk_ClkBakSetSource, and
* \ref Cy_SysClk_ClkBakGetSource.
*/
typedef enum
{
    CY_SYSCLK_BAK_IN_WCO,   /**< Backup domain clock input is WCO */
    CY_SYSCLK_BAK_IN_CLKLF,  /**< Backup domain clock input is clkLf */
#if defined (CY_IP_MXS28SRSS) || defined (CY_IP_MXS40SSRSS) || (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION >= 2)) || defined (CY_IP_MXS22SRSS)
    CY_SYSCLK_BAK_IN_ILO,               /**< Backup domain clock input is ILO */
#if defined (CY_IP_MXS40SSRSS) || (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION >= 3))
    CY_SYSCLK_BAK_IN_LPECO_PRESCALER,   /**< Backup domain clock input is LPECO_PRESCALER  */
#endif
    CY_SYSCLK_BAK_IN_PILO,              /**< Backup domain clock input is PILO */
#endif /* CY_IP_MXS28SRSS, CY_IP_MXS40SSRSS, (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION >= 3), CY_IP_MXS22SRSS */
    CY_SYSCLK_BAK_INVALID
} cy_en_clkbak_in_sources_t;
/** \} group_sysclk_clk_bak_enums */


/**
* \addtogroup group_sysclk_clk_bak_funcs
* \{
*/
#if defined (CY_IP_MXS22SRSS) && (CY_IP_MXS22SRSS_VERSION == 2)
/*******************************************************************************
* Function Name: Cy_SysClk_ClkBakSetSource
****************************************************************************//**
*
* Sets the source for the backup domain clock (clk_bak).
*
* \param source \ref cy_en_clkbak_in_sources_t
*
* \note
* clkLf is not available in all power modes.  For this reason, WCO is the
* preferred source. If the WCO is routed through the clkLf multiplexer
* (see \ref Cy_SysClk_ClkLfSetSource), select WCO directly - do not select clkLf.
*
* \return
* Result of clock source update. See \ref cy_en_sysclk_status_t.
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_ClkBakSetSource
*
*******************************************************************************/
cy_en_sysclk_status_t Cy_SysClk_ClkBakSetSource(cy_en_clkbak_in_sources_t source);
#else
/*******************************************************************************
* Function Name: Cy_SysClk_ClkBakSetSource
****************************************************************************//**
*
* Sets the source for the backup domain clock (clk_bak).
*
* \param source \ref cy_en_clkbak_in_sources_t
*
* \note
* clkLf is not available in all power modes.  For this reason, WCO is the
* preferred source. If the WCO is routed through the clkLf multiplexer
* (see \ref Cy_SysClk_ClkLfSetSource), select WCO directly - do not select clkLf.
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_ClkBakSetSource
*
*******************************************************************************/
void Cy_SysClk_ClkBakSetSource(cy_en_clkbak_in_sources_t source);
#endif /* defined (CY_IP_MXS22SRSS) && (CY_IP_MXS22SRSS_VERSION == 2) */

/*******************************************************************************
* Function Name: Cy_SysClk_ClkBakGetSource
****************************************************************************//**
*
* Reports the source for the backup domain clock (clk_bak).
*
* \return \ref cy_en_clkbak_in_sources_t
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_ClkBakSetSource
*
*******************************************************************************/
cy_en_clkbak_in_sources_t Cy_SysClk_ClkBakGetSource(void);
/** \} group_sysclk_clk_bak_funcs */


/** \cond */
/* Deprecated macros */
#define CY_SYSCLK_DIV_ROUND(a, b)   (CY_SYSLIB_DIV_ROUND((a),(b)))
#define CY_SYSCLK_DIV_ROUNDUP(a, b) (CY_SYSLIB_DIV_ROUNDUP((a),(b)))
/** \endcond */

/* ========================================================================== */
/* ==========================     Clock Power SECTION    =============================*/
/* ========================================================================== */
/**
* \addtogroup group_sysclk_clk_pwr_enums
* \{
*/
#if (defined (CY_IP_MXS40SSRSS) && (CY_MXS40SSRSS_VER_1_2 > 0UL)) || defined(CY_DOXYGEN)
/**
* Clock power input sources. See PWRMODE_CLK_SELECT register, PWR_MUX bits.
* Used with functions \ref Cy_SysClk_ClkPwrSetSource, and \ref Cy_SysClk_ClkPwrGetSource.
*/

typedef enum
{
    CY_SYSCLK_CLKPWR_IN_IMO   = 0U, /**< clkPwr is sourced by the internal main oscillator (IMO) */
    CY_SYSCLK_CLKPWR_IN_IHO   = 1U, /**< clkPwr is sourced by the internal high speed oscillator (IHO) */
} cy_en_clkpwr_in_sources_t;

/** \} group_sysclk_clk_pwr_enums */

/** \cond internal */
#define CY_SYSCLK_CLKPWR_DIVIDER_MIN                  (1U)
#define CY_SYSCLK_CLKPWR_DIVIDER_MAX                  (256U)
#define CY_SYSCLK_IS_CLKPWR_DIVIDER_VALID(locDiv)     ((CY_SYSCLK_CLKPWR_DIVIDER_MIN <= (locDiv)) && ((locDiv) <= CY_SYSCLK_CLKPWR_DIVIDER_MAX))

#define CY_SYSCLK_IF_CLKPWR_SOURCE_VALID(pwrClkSrc)    (((pwrClkSrc) == CY_SYSCLK_CLKPWR_IN_IMO) || \
                                                         ((pwrClkSrc) == CY_SYSCLK_CLKPWR_IN_IHO))
/** \endcond */

/**
* \addtogroup group_sysclk_clk_pwr_funcs
* \{
*/
/*******************************************************************************
* Function Name: Cy_SysClk_ClkPwrSetDivider
****************************************************************************//**
*
* Sets the clock divider for Power clock.
*
* \param divider divider value between 1 and 256.
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_ClkPwrSetDivider
*
*******************************************************************************/
void Cy_SysClk_ClkPwrSetDivider(uint32_t divider);

/*******************************************************************************
* Function Name: Cy_SysClk_ClkPwrGetDivider
****************************************************************************//**
*
* Returns the clock divider of Power clock.
*
* \return divider value in range 1..256.
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_ClkPwrSetDivider
*
*******************************************************************************/
uint32_t Cy_SysClk_ClkPwrGetDivider(void);


/*******************************************************************************
* Function Name: Cy_SysClk_ClkPwrGetFrequency
****************************************************************************//**
*
* Reports the output clock signal frequency of Power clock.
*
* \return The frequency, in Hz.
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_ClkPwrSetDivider
*
*******************************************************************************/
uint32_t Cy_SysClk_ClkPwrGetFrequency(void);


/*******************************************************************************
* Function Name: Cy_SysClk_ClkPwrSetSource
****************************************************************************//**
*
* Sets the source for the Power clock.
*
* \param source \ref cy_en_clkpwr_in_sources_t
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_ClkPwrSetSource
*
*******************************************************************************/
void Cy_SysClk_ClkPwrSetSource(cy_en_clkpwr_in_sources_t source);


/*******************************************************************************
* Function Name: Cy_SysClk_ClkPwrGetSource
****************************************************************************//**
*
* Reports the source for the Power clock.
*
* \return \ref cy_en_clkpwr_in_sources_t
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_ClkPwrSetSource
*
*******************************************************************************/
cy_en_clkpwr_in_sources_t Cy_SysClk_ClkPwrGetSource(void);
/** \} group_sysclk_clk_pwr_funcs */
#endif


#if defined(__cplusplus)
}
#endif /* __cplusplus */

#endif /* defined (CY_IP_MXS28SRSS) || defined (CY_IP_MXS40SRSS) || defined (CY_IP_MXS40SSRSS) || defined (CY_IP_MXS22SRSS) */

#endif /* CY_SYSCLK_H */

/** \} group_sysclk */


/* [] END OF FILE */
