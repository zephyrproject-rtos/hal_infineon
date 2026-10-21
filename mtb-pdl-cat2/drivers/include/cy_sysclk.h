/***************************************************************************//**
* \file cy_sysclk.h
* \version 3.50
*
* Provides an API declaration of the sysclk driver.
*
********************************************************************************
* \copyright
* (c) (2016-2025), Cypress Semiconductor Corporation (an Infineon company) or
* an affiliate of Cypress Semiconductor Corporation.
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
* Firmware uses the API to configure, enable, calibrate or disable a clock.
*
* The clock system includes a variety of resources that can vary per device, including:
* - Internal clock sources such as internal oscillators
* - External clock sources such as crystal oscillators or a signal on an I/O pin
* - Generated clocks such as a PLL, System clock and peripheral clocks
*
* Consult the Technical Reference Manual for your device for details of the
* clock system.
*
* \section group_sysclk_configuration Configuration Considerations
* The availability of clock functions depend on the availability of the chip
* resources that support those functions. Consult the device TRM before
* attempting to use these functions.
*
* Usually the default clock configuration is IMO (24 MHz) -> ClkHf (24 MHz) -> SysClk (24 MHz)
*
* The example of ECO -> HFCLK clock initialization:
*
* \snippet sysclk/snippet/sysclk_snippet.c SNIPPET_ECO_CONFIG_MACRO
* \snippet sysclk/snippet/sysclk_snippet.c SNIPPET_ECO_INIT
*
* The example of ECO -> PLL -> HFCLK clock initialization (taking into account the previous code snippet):
* \snippet sysclk/snippet/sysclk_snippet.c SNIPPET_PLL_INIT
*
* Low power modes may limit the maximum clock frequency.
* Refer to the SysPm driver and the TRM for details.
*
* Interrupts calibration:
* \snippet sysclk_snippet.c snippet_Cy_SysClk_CalibIsr_Config
* \snippet sysclk_snippet.c snippet_Cy_SysClk_CalibInterrupt
*
* Calibration clock sources example:
* \snippet sysclk_snippet.c snippet_Cy_SysClk_StartClkMeasurementCounters
*
* \section group_sysclk_more_information More Information
* Refer to the technical reference manual (TRM) and the device datasheet.
*
* \section group_sysclk_changelog Changelog
* <table class="doxtable">
*   <tr><th>Version</th><th>Changes</th><th>Reason for Change</th></tr>
*   <tr>
*     <td>3.50</td>
*     <td>Added overtemperature interrupt support. See \ref Cy_SysClk_OverTempSetInterrupt, \ref Cy_SysClk_OverTempClearInterrupt,
*       \ref Cy_SysClk_OverTempGetInterruptStatus, \ref Cy_SysClk_OverTempGetInterruptStatusMasked and \ref Cy_SysClk_OverTempSetInterruptMask.</td>
*     <td>API improvement.</td>
*   </tr>
*   <tr>
*     <td>3.40</td>
*     <td> \ref CY_SYSCLK_PERI_DIV_NUM_Pos and \ref CY_SYSCLK_PERI_DIV_NUM_Msk implementation is updated.</td>
*     <td>Bug fixing.</td>
*   </tr>
*   <tr>
*     <td>3.30</td>
*     <td>Added the Cy_SysClk_ImoTempTrim() function.</td>
*     <td>Feature enhancement.</td>
*   </tr>
*   <tr>
*     <td>3.20</td>
*     <td>Added support for PSOC4 HVMS/PA platform.\n
*       Updated APIs to incorporate PSOC4 HVMS/PA platform configuration.\n
*       Added PILO and HPOSC APIs support. See \ref group_sysclk_pilo and \ref group_sysclk_hposc.\n
*       Added LFCLK APIs support. See \ref group_sysclk_lf.\n
*       Added Clock Calibration and Clock Trim support. See \ref group_sysclk_calclk and \ref group_sysclk_trim.</td>
*     <td>Added support for PSOC4 HVMS/PA platform.</td>
*   </tr>
*   <tr>
*     <td>3.10.1</td>
*     <td>Added note for the \ref Cy_SysClk_IloStopMeasurement.</td>
*     <td>Documentation enhancement.</td>
*   </tr>
*   <tr>
*     <td rowspan="2">3.10</td>
*     <td>The documentation of the ILO compensation algorithm is more detailed.</td>
*     <td>Documentation enhancement.</td>
*   </tr>
*   <tr>
*     <td> \ref Cy_SysClk_IloCompensate() API function implementation is updated.</td>
*     <td>Corner case bug fixing.</td>
*   </tr>
*   <tr>
*     <td>3.0</td>
*     <td>Removed the legacy deprecated interfaces.</td>
*     <td>PDL major revision.</td>
*   </tr>
*   <tr>
*     <td rowspan="3">2.20</td>
*     <td>The implementation of the \ref Cy_SysClk_ClkHfSetSource function is updated.</td>
*     <td>Memory consumption optimization.</td>
*   </tr>
*   <tr>
*     <td>Update the paths to the code snippets.</td>
*     <td>PDL structure update.</td>
*   </tr>
*   <tr>
*     <td>Minor documentation updates. Code snippets were updated.</td>
*     <td>Documentation enhancement.</td>
*   </tr>
*   <tr>
*     <td rowspan="3">2.10</td>
*     <td>Added the \ref Cy_SysClk_PeriphSetFrequency API function</td>
*     <td>API improvement</td>
*   </tr>
*   <tr>
*     <td>Added API for the \ref group_sysclk_csv, \ref group_sysclk_pgm_dly and \ref group_sysclk_int features </td>
*     <td>New features support for PSOC 4500S and 4100S Max devices</td>
*   </tr>
*   <tr>
*     <td>Minor documentation updates. Code snippets were updated.</td>
*     <td>Documentation enhancement.</td>
*   </tr>
*   <tr>
*     <td rowspan="13">2.0</td>
*     <td>Added the \ref Cy_SysClk_DeepSleepCallback and \ref Cy_SysClk_RegisterCallback functions</td>
*     <td>Power management performance enhancement, see \ref group_sysclk_pm</td>
*   </tr>
*   <tr>
*     <td>The next functions are changed: \ref Cy_SysClk_ExtClkSetFrequency and \ref Cy_SysClk_ExtRefSetFrequency -
*         now there are opportunities to set a zero frequency which means the clock signal is disabled</td>
*     <td>Clock system management enhancement</td>
*   </tr>
*   <tr>
*     <td>The next API are changed: \ref cy_en_sysclk_clkhf_src_t and \ref cy_en_sysclk_pll_bypass_t,
*         the backward compatibility of the \ref Cy_SysClk_ClkHfSetSource and \ref Cy_SysClk_PllBypass
*         functions is preserved, however the deprecated interface items are strongly not recommended for new designs</td>
*     <td>Clock switching management bugs fixes</td>
*   </tr>
*   <tr>
*     <td>The \ref Cy_SysClk_PllConfigure is changed do that the PLL output frequency could never overcome 48MHz</td>
*     <td>Documentation improvements, bug fixes</td>
*   </tr>
*   <tr>
*     <td>Updated the \ref Cy_SysClk_PllGetFrequency() function - now it returns a more precise result</td>
*     <td>Usability improvement</td>
*   </tr>
*   <tr>
*     <td>Updated the \ref Cy_SysClk_PllSetSource() and \ref Cy_SysClk_ClkPumpSetSource functions -
*         now they check the source validness even it is already connected</td>
*     <td>Usability improvement</td>
*   </tr>
*   <tr>
*     <td>Updated the \ref Cy_SysClk_PllDisable() function</td>
*     <td>Code optimization</td>
*   </tr>
*   <tr>
*     <td>Updated the \ref Cy_SysClk_WcoEnable() function - now the WCO startup delay recommended by the TRM is supported</td>
*     <td>Performance improvement</td>
*   </tr>
*   <tr>
*     <td>The external PLL reference clock (EXTREF) frequency maximum is reduced to 48MHz</td>
*     <td>Bug fix</td>
*   </tr>
*   <tr>
*     <td>The external clock input (EXTCLK) frequency minimum is reduced to 0MHz</td>
*     <td>Bug fix</td>
*   </tr>
*   <tr>
*     <td>The external crystal oscillator (ECO) frequency maximum is reduced to 33.33MHz</td>
*     <td>Bug fix</td>
*   </tr>
*   <tr>
*     <td>Updated the WCO documentation, especially the Bypass feature, see \ref group_sysclk_WCO_bypass_mode</td>
*     <td>Documentation improvement</td>
*   </tr>
*   <tr>
*     <td>Minor documentation updates</td>
*     <td>Documentation enhancement</td>
*   </tr>
*   <tr>
*     <td>1.20</td>
*     <td>Fixed the \ref Cy_SysClk_ImoLock function to properly lock IMO.</td>
*     <td>Defect fix.</td>
*   </tr>
*   <tr>
*     <td rowspan="2">1.10</td>
*     <td>New feature is added: external reference signal for PLL.\n
*         New items: \ref CY_SYSCLK_PLL_SRC_EXTREF, \ref Cy_SysClk_ExtRefSetFrequency and \ref Cy_SysClk_ExtRefGetFrequency\n
*         Updated functions: \ref Cy_SysClk_PllSetSource and \ref Cy_SysClk_PllGetFrequency.</td>
*     <td>Added support of PSOC 4500S device EXCO block.</td>
*   </tr>
*   <tr>
*     <td>The implementation of \ref Cy_SysClk_ExtClkSetFrequency,
*                               \ref Cy_SysClk_IloCompensate,
*                               \ref Cy_SysClk_EcoConfigure,
*                               \ref Cy_SysClk_PllSetSource,
*                               \ref Cy_SysClk_PllConfigure,
*                               \ref Cy_SysClk_ClkHfSetSource,
*                               \ref Cy_SysClk_ClkHfGetSource
*                           and \ref Cy_SysClk_ClkHfGetFrequency
*         functions is updated.</td>
*     <td>Bug fixing and code optimization.</td>
*   </tr>
*   <tr>
*     <td>1.0</td>
*     <td>Initial version</td>
*     <td></td>
*   </tr>
* </table>
*
* \defgroup group_sysclk_macros           Macros
* \{
* \}
* \defgroup group_sysclk_enums           General Enumerated Types
* \{
*   \defgroup group_sysclk_returns         Function return values
* \}
* \defgroup group_sysclk_imo             Internal Main Oscillator (IMO)
* \{
*   The Internal Main Oscillator (IMO) is a primary clock source for
*   the CPU core and most of the peripherals. It is enabled by default
*   and is not recommended to disable without a critical need.
*
*   \defgroup group_sysclk_imo_funcs       Functions
*   \defgroup group_sysclk_imo_enums       Enumerated Types
* \}
* \defgroup group_sysclk_ext_clk           External Clock Source (EXTCLK)
* \{
*   The External Clock Source (EXTCLK) is a clock source routed into PSOC
*   through a GPIO pin. The EXTCLK is a source clock that can be used to
*   source the processors and peripherals \ref group_sysclk_clk_hf.
*
*   The EXTCLK relies on the presence of an external clock signal applied
*   to the GPIO pin. The pin must be configured to operate in Digital
*   High-Z drive mode with input buffer on and HSIOM connection
*   set to HSIOM_SEL_ACT_0 (P0_6_SRSS_EXT_CLK).
*
*   \defgroup group_sysclk_ext_clk_funcs       Functions
* \}
* \defgroup group_sysclk_ext_ref External PLL Reference Clock Source (EXTREF)
* \{
*   The External PLL Reference Clock Source (EXTREF) is a clock source routed
*   into PSOC through a GPIO pin.
*   The EXTREF can be used as reference clock for the \ref group_sysclk_pll.
*
*   The EXTREF relies on the presence of an external clock signal applied
*   to the GPIO pin. The pin must be configured to operate in Digital
*   High-Z drive mode with input buffer on and HSIOM connection
*   set to HSIOM_SEL_ACT_2 (P0_6_EXCO_PLL_REF_IN).
*
*   \defgroup group_sysclk_ext_ref_funcs       Functions
* \}
* \defgroup group_sysclk_eco             External Crystal Oscillator (ECO)
* \{
*   The External Crystal Oscillator (ECO) is a clock source that consists
*   of an oscillator circuit that drives an external crystal through its
*   dedicated ECO pins.
*
*   The ECO is a source clock that can be used to drive the processor
*   and peripherals.
*
*   The ECO relies on the presence of an external crystal. The pins
*   connected to this crystal must be configured to operate in analog
*   drive mode with HSIOM connection set to GPIO control (HSIOM_SEL_GPIO).
*
*   \note Not applicable for PSOC4 HVMS/PA.
*
*   \defgroup group_sysclk_eco_funcs       Functions
*   \defgroup group_sysclk_eco_enums       Enumerated Types
* \}
* \defgroup group_sysclk_pll             Phase Locked Loop (PLL)
* \{
*   The PLL is a clock generation circuit that can be used to produce a
*   higher frequency clock from a reference clock. The output clock exhibits
*   characteristics of the reference clock such as the accuracy of the source
*   and its phase.
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
*
* \defgroup group_sysclk_ilo             Internal Low-Speed Oscillator (ILO)
* \{
*   The ILO operates with no external components and outputs a clock signal at roughly
*   40 kHz. The ILO is relatively low power and low accuracy. It is available
*   in all power modes. The ILO can be used as a low-frequency clock (LFCLK)
*   or as a source for the \ref group_wdt, \ref group_wdc.
*
*   \defgroup group_sysclk_ilo_funcs       Functions
* \}
* \defgroup group_sysclk_pilo            Precision Internal Low-speed Oscillator (PILO)
* \{
*   The Precision Internal Low-speed Oscillator (PILO operates with no external
*   components and outputs a clock signal at nominal 32768 Hz with 5% accuracy
*   when not tracking HPOSC and 1% accuracy when tracking HPOSC.
*   The PILO is a relatively low-power clock source. It is available
*   in all power modes. The PILO can be used as a low-frequency clock (LFCLK)
*   or as a source for \ref group_wdt
*
*   \defgroup group_sysclk_pilo_funcs       Functions
* \}
* \defgroup group_sysclk_hposc          High-Precision Oscillator (HPOSC)
* \{
*   The high-precision internal oscillator (HPOSC) operates with no external components
*   and outputs a clock signal at roughly 2 MHz.
*
*   This oscillator is intended to trim other blocks to maintain 1% accurate timing
*   throughout the chip. \ref group_sysclk_calclk can be achieved
*   using on-chip counters to compare clock rates and make appropriate adjustments via
*   firmware. Refer to the \ref group_sysclk_trim "Clock Trim" API.
*
*   The HPOSC operates from the low-voltage (1.8 V) VCCD supply, and uses
*   an available 1.2 uA current for fast startup. After startup, or when disabled,
*   this current is not used and is cut off. The block is low power,
*   typically using less than 10 uA.
*
*   The HPOSC can be used as \ref group_sysclk_clk_hf (HFCLK). The high-frequency clocks
*   including the HPOSC operate only in Active and Sleep modes.
*
*   \defgroup group_sysclk_hposc_funcs       Functions
* \}
* \defgroup group_sysclk_lf             Low-Frequency Clock
* \{
*   The low-frequency clock is the source clock for the \ref group_wdt,
*   and other peripherals which depends on certain chip.
*
*   \note For PSOC4 HVMS/PA devices the low-frequency clock also can be the source clock for \ref group_arm_system_timer.
*
*   The low-frequency clock clock can be sourced by
*   \ref group_sysclk_ilo "ILO", \ref group_sysclk_pilo "PILO", etc.
*   For details, Refer to the technical reference manual (TRM) and the device datasheet.
*
*   \defgroup group_sysclk_clk_lf_enums      Enumerated Types
*   \defgroup group_sysclk_clk_lf_funcs      Functions
* \}
* \defgroup group_sysclk_calclk          Clock Calibration
* \{
*   Clock calibration allows measuring the number of clock cycles (counter 2) that
*   occur within a time window. The time window is created by counting clock
*   cycles of a reference clock (counter 1).
*   It allows a programmable choice of the clock for both counter 1 and counter 2.
*   This gives it the capability to more quickly calibrate a low-speed clock
*   (eg. counter2 = clk_ilo) with a faster clock (counter1 = clk_imo).
*
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
* \}
* \defgroup group_sysclk_trim            Clock Trim (IMO, PILO)
* \{
*   These functions perform a single trim operation on the IMO or PILO. Each
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
*   \defgroup group_sysclk_trim_enums      Enumerated Types
* \}
* \defgroup group_sysclk_wco             Watch Crystal Oscillator (WCO)
* \{
*   The WCO is a highly accurate 32.768 kHz clock source capable of operating
*   in all power modes. The WCO can be used as a source for the \ref group_wdc.
*
*   \note Please refer to the product Datasheet about presence of WCO in your device.
*
*   ![](wco_clk.png)
*
*   The WCO requires the configuration of the dedicated WCO pins (wco_in,
*   wco_out). These must be configured as Analog Hi-Z drive modes and the
*   HSIOM selection set to GPIO.
*
*   \section group_sysclk_WCO_bypass_mode Bypass mode
*   The WCO can also be used in bypass mode, where an external
*   square wave is brought in directly through the wco_out pin.
*   Even though driving wco_in pin would work, better performance will be achieved
*   using wco_out pin since we can bypass the feedback resistor
*   which causes an RC delay and duty cycle variation. The wco_in pin
*   should be floating, however, if floating is not desirable,
*   then a minimum input impedance of 500kOhm to ground is required on the wco_in pin.
*   An external clock source should toggles from 0V to a minimum of 1.0V and 0V to
*   a maximum of 1.6V with duty cycle 20% to 80%.
*   For stable WCO operation using an external clock source,
*   the VDDA/VDDD external supply should be in the range of 1.65V to 5V.
*
*   \subsection group_sysclk_WCO_configuration Configuration Considerations
*   Start up sequence of the WCO in bypass mode:
*   - Configure wco_out pin in Analog Hi-Z drive mode and
*     with the HSIOM selection set to GPIO;
*   - Disable the WCO by calling function Cy_SysClk_WcoDisable();
*   - Drive the wco_out pin to a voltage between 1.0V and 1.6V
*     since this would be the range of the high potential
*     specified when forcing the external clock;
*   - Configure WCO in bypass mode by calling function Cy_SysClk_WcoBypass()
*     with parameter "true";
*   - Enable the WCO with delay at least 15us by calling function
*     Cy_SysClk_WcoEnable() with parameter "15";
*   - Start clocking wco_out pin with desired frequency;
*
*   \note Do not use oscillator output clock prior to the 15us delay. \n
*         There are no limitations on the external clock frequency. \n
*         When external clock source was selected to drive WCO block
*         the IMO can be trimmed only when external clock source period
*         is equal to WCO external crystal period. \n
*         Also accuracy of the external clock source should be
*         higher or equal to the accuracy of WCO external crystal.
*
*   \defgroup group_sysclk_wco_funcs       Functions
* \}
* \defgroup group_sysclk_clk_hf          High-Frequency Clock
* \{
*   The high frequency clock HFCLK is a source for the system clock for CPU and
*   the peripheral clock dividers.
*   The high frequency clock can be sourced by IMO, EXCO (PLL or ECO), EXTCLK, etc.
*   Consult the Technical Reference Manual for your device for details.
*
*   \defgroup group_sysclk_clk_hf_funcs    Functions
*   \defgroup group_sysclk_clk_hf_enums    Enumerated Types
* \}
* \defgroup group_sysclk_clk_peripheral  Peripherals Clock Dividers
* \{
*   There are multiple peripheral clock dividers that, in effect, create
*   multiple separate peripheral clocks:
*
*   - Integer 8-bit dividers
*   - Integer 16-bit dividers
*   - Fractional 16.5-bit dividers (16 integer bits, 5 fractional bits)
*   - Fractional 24.5-bit divider (24 integer bits, 5 fractional bits)
*
*   The availability and number of each type of dividers depends on the certain device family.
*   Consult the Technical Reference Manual for your device for details.
*
*   The integer dividers work simply: a divider value of 1
*   means the output frequency matches the input frequency (that is, there is
*   no change). Otherwise the frequency is divided by the value of the divider.
*   For example, if the input frequency is 24 MHz, and the divider value is 10,
*   the output frequency is 2.4 MHz.
*
*   The five fractional bits support further precision in 1/32nd increments. For
*   example, a divider with an integer value of 3 and a fractional value of
*   4 (4/32 or 1/8) result in a divider of 3.125. Fractional dividers are useful when
*   a high-precision clock frequency is required, for example, for a UART/SPI serial
*   interface.
*
*   ![](sysclk_peri_divs.png)
*
*   Each peripheral can connect to any one of the programmable dividers. A
*   particular peripheral clock divider can drive multiple peripherals.
*
*   The SysClk driver also supports phase aligning two peripheral clock dividers using
*   Cy_SysClk_PeriphEnablePhaseAlignDivider(). Alignment works for both integer
*   and fractional dividers. The divider to which a second divider is aligned
*   must already be enabled.
*
*   \defgroup group_sysclk_clk_peripheral_macros Macros
*   \defgroup group_sysclk_clk_peripheral_funcs  Functions
*   \defgroup group_sysclk_clk_peripheral_enums  Enumerated Types
* \}
* \defgroup group_sysclk_clk_sys        System Clock
* \{
*   The system clock is the source clock for CPU core (Cortex-M0+ in PSOC 4).
*   This clock is a divided version of the \ref group_sysclk_clk_hf. A divider
*   value of 1, 2, 4 or 8 can be used to further divide the High Frequency
*   clock to a desired clock speed for the processor.
*
*   \defgroup group_sysclk_clk_sys_funcs  Functions
* \}
* \defgroup group_sysclk_clk_pump        Pump Clock
* \{
*   The pump clock is a clock source used to provide analog precision in low voltage
*   applications. Depending on the usage scenario, it may be required to drive the
*   internal voltage pump for the Continuous Time Block mini (CTBm) in the analog
*   subsystem.
*
*   \defgroup group_sysclk_clk_pump_funcs  Functions
*   \defgroup group_sysclk_clk_pump_enums  Enumerated Types
* \}
* \defgroup group_sysclk_csv               Clock Supervision Block (CSV)
* \{
*   The clock supervision block uses a reference clock (IMO clock) to check that a monitored
*   clock (clk_exco) is within an allowed frequency window.
*
*   This feature is available on devices with the EXCO_ver2 (i.e. PSOC 4500S and 4100S Max).
*   Refer to the Device Datasheet to check the CSV feature support.
*   Also see the TRM for more details about CSV itself.
*
*   \defgroup group_sysclk_csv_funcs       Functions
*   \defgroup group_sysclk_csv_structs     Data Structures
* \}
* \defgroup group_sysclk_pgm_dly           Programmable Delay Block (PGM_DELAY)
* \{
*   The PGM_DELAY block is a 16-bit down counter
*   clocked by IMO clock and being triggered by the CSV.
*
*   This feature is available on devices with the EXCO_ver2 (i.e. PSOC 4500S and 4100S Max).
*   Refer to the Device Datasheet to check the PGM_DELAY feature support.
*   Also see the TRM for more details about PGM_DELAY itself.
*
*   \defgroup group_sysclk_pgm_dly_funcs   Functions
* \}
* \defgroup group_sysclk_int               Interrupts
* \{
*   This API is to manage a few interrupt sources
*
*   Supported interrupt sources can be within
*   - the EXCO block on devices with the EXCO_ver2 (i.e. PSOC 4500S and 4100S Max)
*   - the clock calibration block on PSOC4 HVMS/PA devices.
*
*   Refer to the Device Datasheet to check the detailed set of interrupts support.
*   Also see the TRM for more details about the interrupts themselves.
*
*   \defgroup group_sysclk_int_macros      Interrupt Masks
*   \defgroup group_sysclk_int_funcs       Functions
* \}
* \defgroup group_sysclk_pm              Low Power Callback
* \{
*   Entering and exiting low power modes require compatible clock configurations
*   to be set before entering low power and restored upon wakeup and exit.
*   The SysClk driver provides a \ref Cy_SysClk_DeepSleepCallback() function
*   to support the Deep Sleep mode entry.
*   This is needed especially in cases of PLL or/and ECO usage.
*   Also there is a possibility of indication the PLL/ECO startup timeout
*   after the wakeup, see \ref Cy_SysClk_RegisterCallback for details.
*
*   \note If \ref group_sysclk_csv and \ref group_sysclk_pgm_dly are used,
*   they also require proper preparation for the Deep Sleep mode,
*   which for example could be done by the separate custom Deep Sleep callback:
*   \snippet sysclk/snippet/sysclk_snippet.c SNIPPET_SYSCLK_CSV_DSCB_DEC
*   \snippet sysclk/snippet/sysclk_snippet.c SNIPPET_SYSCLK_CSV_DSCB_STC
*   \snippet sysclk/snippet/sysclk_snippet.c SNIPPET_SYSCLK_CSV_DSCB_REG
*
*   \defgroup group_sysclk_pm_events       Callback Timeout Events
*   \defgroup group_sysclk_pm_structs      Data Structures
*   \defgroup group_sysclk_pm_funcs        Functions
* \}
*/

#if !defined(CY_SYSCLK_H)
#define CY_SYSCLK_H

#include <stdbool.h>
#include "cy_device.h"
#include "cy_device_headers.h"
#include "cy_syslib.h"
#include "cy_syspm.h"
#include "cy_wdt.h"


#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */
#if defined (CY_IP_M0S8SRSSHV)
    /** \cond internal */
    extern uint32_t iterationNum;
    extern int32_t errorIntegralHz;
    /** \endcond */
#endif

/**
* \addtogroup group_sysclk_macros
* \{
*/
/** Driver major version */
#define  CY_SYSCLK_DRV_VERSION_MAJOR   3
/** Driver minor version */
#define  CY_SYSCLK_DRV_VERSION_MINOR   50
/** Sysclk driver identifier */
#define CY_SYSCLK_ID   CY_PDL_DRV_ID(0x12U)

/** ILO clock frequency */
#define CY_SYSCLK_ILO_FREQ  (40000UL)   /* Hz */
/** PILO clock frequency */
#define CY_SYSCLK_PILO_FREQ (32768UL)   /* Hz */
/** WCO clock frequency */
#define CY_SYSCLK_WCO_FREQ  (32768UL)   /* Hz */
/** HPOSC clock frequency */
#define CY_SYSCLK_HPOSC_FREQ  (2000000UL)   /* Hz */
/** \} group_sysclk_macros */

/**
* \addtogroup group_sysclk_returns
* \{
*/
/** Defines general-purpose function return values */
typedef enum
{
    CY_SYSCLK_SUCCESS       = 0x00UL, /**< Command completed with no errors */
    CY_SYSCLK_BAD_PARAM     = (CY_SYSCLK_ID | CY_PDL_STATUS_ERROR | 0x01UL), /**< Invalid function input parameter */
    CY_SYSCLK_TIMEOUT       = (CY_SYSCLK_ID | CY_PDL_STATUS_ERROR | 0x02UL), /**< Timeout occurred */
    CY_SYSCLK_INVALID_STATE = (CY_SYSCLK_ID | CY_PDL_STATUS_ERROR | 0x03UL), /**< Clock is in an invalid state */
    CY_SYSCLK_STARTED       = (CY_SYSCLK_ID | CY_PDL_STATUS_WARNING | 0x04UL)  /**< Clock measurement is running */
} cy_en_sysclk_status_t;
/** \} group_sysclk_returns */


/* ========================================================================== */
/* =========================    EXTCLK SECTION    =========================== */
/* ========================================================================== */

/**
* \addtogroup group_sysclk_ext_clk_funcs
* \{
*/
    void Cy_SysClk_ExtClkSetFrequency(uint32_t freq);
uint32_t Cy_SysClk_ExtClkGetFrequency(void);
/** \} group_sysclk_ext_clk_funcs */


/* ========================================================================== */
/* =========================    EXTREF SECTION    =========================== */
/* ========================================================================== */
#if (defined(CY_IP_M0S8EXCO) && (CY_IP_M0S8EXCO == 1u))
#if (CY_IP_M0S8EXCO_VERSION == 2U)
/**
* \addtogroup group_sysclk_ext_ref_funcs
* \{
*/
    void Cy_SysClk_ExtRefSetFrequency(uint32_t freq);
uint32_t Cy_SysClk_ExtRefGetFrequency(void);
/** \} group_sysclk_ext_ref_funcs */
#endif /* CY_IP_M0S8EXCO_VERSION == 2U */
#endif /* CY_IP_M0S8EXCO */

#if defined (CY_IP_M0S8SRSSHV)
/* ========================================================================== */
/* =========================   Protection SECTION   ========================= */
/* ========================================================================== */

/** \cond internal */
/** Unlock the value of lock-protected registers */
#define CY_SYSCLK_PROTREG_UNLOCK    (0xF08169E7UL)

__STATIC_INLINE void Cy_SysClk_UnlockProtReg(void);
__STATIC_INLINE void Cy_SysClk_LockProtReg(void);

/*******************************************************************************
* Function Name: Cy_SysClk_UnlockProtReg()
****************************************************************************//**
*
* Unlocks the access to lock-protected registers
*
* \note Applicable to PSOC4 HVMS/PA only.
*
*******************************************************************************/
__STATIC_INLINE void Cy_SysClk_UnlockProtReg(void)
{
    (((SRSS_Type *) SRSS)->REG_PROT) = CY_SYSCLK_PROTREG_UNLOCK;
}

/*******************************************************************************
* Function Name: Cy_SysClk_LockProtReg()
****************************************************************************//**
*
* Locks access to lock protected registers.
*
* \note Applicable to PSOC4 HVMS/PA only.
*
*******************************************************************************/
__STATIC_INLINE void Cy_SysClk_LockProtReg(void)
{
    (((SRSS_Type *) SRSS)->REG_PROT) = ~CY_SYSCLK_PROTREG_UNLOCK;
}
/** \endcond */


/* ========================================================================== */
/* ==========================    LFCLK SECTION    =========================== */
/* ========================================================================== */
/**
* \addtogroup group_sysclk_clk_lf_enums
* \{
*/
/**
* Selects which LFCLK input to configure.
* Used with functions \ref Cy_SysClk_ClkLfSetSource and \ref Cy_SysClk_ClkLfGetSource.
*/
typedef enum
{
    CY_SYSCLK_CLKLF_IN_ILO  = 0U,   /**< ILO - Internal Low Frequency Oscillator */
    CY_SYSCLK_CLKLF_IN_PILO = 1U,   /**< PILO - Precision Internal Low Frequency Oscillator */
} cy_en_sysclk_clklf_src_t;

/** \} group_sysclk_clk_lf_enums */

/**
* \addtogroup group_sysclk_clk_lf_funcs
* \{
*/
    cy_en_sysclk_status_t Cy_SysClk_ClkLfSetSource(cy_en_sysclk_clklf_src_t source);
                 uint32_t Cy_SysClk_ClkLfGetFrequency(void);

/*******************************************************************************
* Function Name: Cy_SysClk_ClkLfGetSource
****************************************************************************//**
*
* Reports the source of the LFCLK.
*
* \return \ref cy_en_sysclk_clklf_src_t : \n
* \ref CY_SYSCLK_CLKLF_IN_ILO - ILO - Internal Low Frequency Oscillator. \n
* \ref CY_SYSCLK_CLKLF_IN_PILO - PILO - Precision Internal Low Frequency Oscillator. \n
*
* \note Only applicable for PSOC4 HVMS/PA.
*
* \funcusage
* \snippet sysclk_snippet.c snippet_Cy_SysClk_ClkLfSetSource
*
*******************************************************************************/
__STATIC_INLINE cy_en_sysclk_clklf_src_t Cy_SysClk_ClkLfGetSource(void)
{
    uint32_t source = _FLD2VAL(SRSSHV_CLK_SELECT_LFCLK_SEL, SRSS_CLK_SELECT);
    return ((cy_en_sysclk_clklf_src_t) source);
}
/** \} group_sysclk_clk_lf_funcs */
#endif /* defined (CY_IP_M0S8SRSSHV) */

/* ========================================================================== */
/* ===========================    IMO SECTION    ============================ */
/* ========================================================================== */

/**
* \addtogroup group_sysclk_imo_enums
* \{
*/

/** IMO frequencies */
typedef enum
{
    CY_SYSCLK_IMO_24MHZ = 24000000UL, /**< 24 MHz */
    CY_SYSCLK_IMO_28MHZ = 28000000UL, /**< 28 MHz */
    CY_SYSCLK_IMO_32MHZ = 32000000UL, /**< 32 MHz */
    CY_SYSCLK_IMO_36MHZ = 36000000UL, /**< 36 MHz */
    CY_SYSCLK_IMO_40MHZ = 40000000UL, /**< 40 MHz */
    CY_SYSCLK_IMO_44MHZ = 44000000UL, /**< 44 MHz */
    CY_SYSCLK_IMO_48MHZ = 48000000UL,  /**< 48 MHz */
    CY_SYSCLK_IMO_49_152MHZ= 49152000UL   /**< 49.152 MHz */
} cy_en_sysclk_imo_freq_t;

#if defined(CY_IP_M0S8WCO)
/** IMO lock sources */
typedef enum
{
    CY_SYSCLK_IMO_LOCK_NONE     =     0U, /**< Disable IMO Locking */
    CY_SYSCLK_IMO_LOCK_WCO      =     1U, /**< Lock IMO by WCO clock */
} cy_en_sysclk_imo_lock_t;
#endif /* (CY_IP_M0S8WCO) */
/** \} group_sysclk_imo_enums */

/**
* \addtogroup group_sysclk_imo_funcs
* \{
*/

cy_en_sysclk_status_t Cy_SysClk_ImoSetFrequency(cy_en_sysclk_imo_freq_t freq);
uint32_t Cy_SysClk_ImoGetFrequency(void);
#if defined(CY_IP_M0S8WCO)
cy_en_sysclk_status_t Cy_SysClk_ImoLock(cy_en_sysclk_imo_lock_t lock);
cy_en_sysclk_imo_lock_t Cy_SysClk_ImoGetLockStatus(void);
#endif /* (CY_IP_M0S8WCO) */
#if defined (SFLASH_HAS_DYNAMIC_IMO)
void Cy_SysClk_ImoTempTrim(int16_t tenthDegreeC);
#endif
__STATIC_INLINE void Cy_SysClk_ImoEnable(void);
__STATIC_INLINE void Cy_SysClk_ImoDisable(void);
__STATIC_INLINE bool Cy_SysClk_ImoIsEnabled(void);

/** \} group_sysclk_imo_funcs */


/*******************************************************************************
* Function Name: Cy_SysClk_ImoEnable
****************************************************************************//**
*
* Enables IMO.
*
*******************************************************************************/
__STATIC_INLINE void Cy_SysClk_ImoEnable(void)
{
#if defined (CY_IP_M0S8SRSSHV)
    /* Avoid lock register's potential race condition. */
    uint32_t intrState = Cy_SysLib_EnterCriticalSection();
    Cy_SysClk_UnlockProtReg();
#endif /* defined (CY_IP_M0S8SRSSHV) */
    SRSS_CLK_IMO_CONFIG = SRSS_CLK_IMO_CONFIG_ENABLE_Msk;
#if defined (CY_IP_M0S8SRSSHV)
    Cy_SysClk_LockProtReg();
    Cy_SysLib_ExitCriticalSection(intrState);
#endif /* defined (CY_IP_M0S8SRSSHV) */
}

/*******************************************************************************
* Function Name: Cy_SysClk_ImoDisable
****************************************************************************//**
*
* Returns IMO enable/disable state.
*
*******************************************************************************/
__STATIC_INLINE bool Cy_SysClk_ImoIsEnabled(void)
{
    return(_FLD2BOOL(SRSS_CLK_IMO_CONFIG_ENABLE, SRSS_CLK_IMO_CONFIG));
}

/*******************************************************************************
* Function Name: Cy_SysClk_ImoDisable
****************************************************************************//**
*
* Disables IMO.
*
*******************************************************************************/
__STATIC_INLINE void Cy_SysClk_ImoDisable(void)
{
#if defined(CY_IP_M0S8WCO)
    (void) Cy_SysClk_ImoLock(CY_SYSCLK_IMO_LOCK_NONE);
#endif /* (CY_IP_M0S8WCO) */
#if defined (CY_IP_M0S8SRSSHV)
    /* Avoid lock register's potential race condition. */
    uint32_t intrState = Cy_SysLib_EnterCriticalSection();
    Cy_SysClk_UnlockProtReg();
#endif /* defined (CY_IP_M0S8SRSSHV) */
    SRSS_CLK_IMO_CONFIG = 0UL;
#if defined (CY_IP_M0S8SRSSHV)
    Cy_SysClk_LockProtReg();
    Cy_SysLib_ExitCriticalSection(intrState);
    /* clear history for second order trim */
    iterationNum = 0UL;
    errorIntegralHz = 0;
#endif /* defined (CY_IP_M0S8SRSSHV) */
}
/** \} group_sysclk_imo_funcs */


#if (defined(CY_IP_M0S8EXCO) && (CY_IP_M0S8EXCO == 1u)) || defined(CY_DOXYGEN)
/* ========================================================================== */
/* ===========================    ECO SECTION    ============================ */
/* ========================================================================== */

/**
* \addtogroup group_sysclk_eco_enums
* \{
*/

/** Defines return values for \ref Cy_SysClk_EcoGetStatus */
typedef enum
{
    CY_SYSCLK_ECO_STABLE         = 0U, /**< ECO is stable */
    CY_SYSCLK_ECO_WATCHDOG_ERROR = 1U, /**< ECO oscillator is stuck */
} cy_en_sysclk_eco_stat_t;
/** \} group_sysclk_eco_enums */

/** \cond */
#define SRSS_CLK_ECO_STATUS_Msk (SRSS_CLK_ECO_STATUS_ECO_OK_Msk | SRSS_CLK_ECO_STATUS_ECO_READY_Msk)
/** \endcond */



/**
* \addtogroup group_sysclk_eco_funcs
* \{
*/
cy_en_sysclk_status_t Cy_SysClk_EcoConfigure(uint32_t freq, uint32_t cLoad, uint32_t esr, uint32_t driveLevel);
cy_en_sysclk_status_t Cy_SysClk_EcoEnable(uint32_t timeoutUs);
             uint32_t Cy_SysClk_EcoGetFrequency(void);
 __STATIC_INLINE bool Cy_SysClk_EcoIsEnabled(void);
 __STATIC_INLINE void Cy_SysClk_EcoDisable(void);
 __STATIC_INLINE cy_en_sysclk_eco_stat_t Cy_SysClk_EcoGetStatus(void);


/*******************************************************************************
* Function Name: Cy_SysClk_EcoIsEnabled
****************************************************************************//**
*
* Returns the ECO enable/disable state.
*
* \note Not applicable for PSOC4 HVMS/PA.
*
* \return
* false = disabled \n
* true = enabled
*
* \funcusage
* \snippet sysclk_snippet.c snippet_Cy_SysClk_EcoDisable
*
*******************************************************************************/
__STATIC_INLINE bool Cy_SysClk_EcoIsEnabled(void)
{
    return(_FLD2BOOL(EXCO_ECO_CONFIG_ENABLE, EXCO_ECO_CONFIG));
}


/*******************************************************************************
* Function Name: Cy_SysClk_EcoDisable
****************************************************************************//**
*
* Disables the external crystal oscillator (ECO). This function should not be
* called if the ECO is sourcing other resources.
*
* \note Not applicable for PSOC4 HVMS/PA.
*
* \funcusage
* \snippet sysclk_snippet.c snippet_Cy_SysClk_EcoDisable
*
*******************************************************************************/
__STATIC_INLINE void Cy_SysClk_EcoDisable(void)
{
    EXCO_ECO_CONFIG &= ~(EXCO_ECO_CONFIG_ENABLE_Msk | EXCO_ECO_CONFIG_CLK_EN_Msk);
}


/*******************************************************************************
* Function Name: Cy_SysClk_EcoGetStatus
****************************************************************************//**
*
* Reports the current status of the external crystal oscillator (ECO).
*
* \note Not applicable for PSOC4 HVMS/PA.
*
* \note This function returns just a register value, for example,
* \ref CY_SYSCLK_ECO_STABLE can be returned even when ECO is not enabled.
* To get a precise ECO status use also \ref Cy_SysClk_EcoIsEnabled.
*
* \return \ref cy_en_sysclk_eco_stat_t : \n
* \ref CY_SYSCLK_ECO_STABLE - ECO is stable. \n
* \ref CY_SYSCLK_ECO_WATCHDOG_ERROR - ECO oscillator is stuck.
*
* \funcusage
* \snippet sysclk/snippet/sysclk_snippet.c snippet_Cy_SysClk_EcoPllHfClk
*
*******************************************************************************/
__STATIC_INLINE cy_en_sysclk_eco_stat_t Cy_SysClk_EcoGetStatus(void)
{
    CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 10.8', 'The field values match the enumeration.');
    return ((cy_en_sysclk_eco_stat_t) _FLD2VAL(EXCO_ECO_STATUS_WATCHDOG_ERROR, EXCO_ECO_STATUS));
}
/** \} group_sysclk_eco_funcs */


#if (defined(EXCO_PLL_PRESENT) && (EXCO_PLL_PRESENT == 1U))
/* ========================================================================== */
/* ===========================    PLL SECTION    ============================ */
/* ========================================================================== */
#if (defined (EXCO_PLL_REF_IN_EN) && (EXCO_PLL_REF_IN_EN == 1U))
/**
* \addtogroup group_sysclk_pll_enums
* \{
*/

/** \cond INTERNAL */
#if (CY_IP_M0S8EXCO_VERSION == 1U)
    #define CY_SYSCLK_PLL_SRC_IMO_NUM (1U)
#endif /* (CY_IP_M0S8EXCO_VERSION == 1U) */
#if (CY_IP_M0S8EXCO_VERSION == 2U)
    #define CY_SYSCLK_PLL_SRC_IMO_NUM (2U)
#endif /* (CY_IP_M0S8EXCO_VERSION == 2U) */
/** \endcond */

/**
* The PLL input clock source selection.
* Used with functions \ref Cy_SysClk_PllSetSource and \ref Cy_SysClk_PllGetSource.
*/
typedef enum
{
    CY_SYSCLK_PLL_SRC_ECO = 0U, /**< PLL runs from ECO. */
#if (CY_IP_M0S8EXCO_VERSION == 2U)
    CY_SYSCLK_PLL_SRC_EXTREF = 1U, /**< PLL runs from the external reference.
                                    *   It is not the same as CY_SYSCLK_CLKHF_IN_EXTCLK.
                                    *   It may be the same GPIO pin but with different HSIOM connection, usually commented with 'exco.pll_ref_in'.
                                    *   Note the clock source may be absent on some devices.
                                    */
#endif /* (CY_IP_M0S8EXCO_VERSION == 2U) */
    CY_SYSCLK_PLL_SRC_IMO = CY_SYSCLK_PLL_SRC_IMO_NUM, /**< PLL runs from IMO. */
} cy_en_sysclk_pll_src_t;

/** \} group_sysclk_pll_enums */


/**
* \addtogroup group_sysclk_pll_funcs
* \{
*/

                cy_en_sysclk_status_t  Cy_SysClk_PllSetSource(uint32_t pllNum, cy_en_sysclk_pll_src_t source);
__STATIC_INLINE cy_en_sysclk_pll_src_t Cy_SysClk_PllGetSource(uint32_t pllNum);

/*******************************************************************************
* Function Name: Cy_SysClk_PllGetSource
****************************************************************************//**
*
* Returns the clock source of the specified PLL.
*
* \note Not applicable for PSOC4 HVMS/PA.
*
* \param pllNum the number of PLL instance, starting from 0.
* If there is only one PLL in device - the 0 is the only valid number.
* For other pllNum values the default CY_SYSCLK_PLL_SRC_ECO value is returned.
*
* \return \ref cy_en_sysclk_pll_src_t : \n
* \ref CY_SYSCLK_PLL_SRC_ECO - PLL runs from ECO. \n
* \ref CY_SYSCLK_PLL_SRC_EXTREF - PLL runs from the external reference. \n
* \ref CY_SYSCLK_PLL_SRC_IMO - PLL runs from IMO.
*
* \funcusage
* \snippet sysclk_snippet.c snippet_Cy_SysClk_PllConfigure
*
*******************************************************************************/
__STATIC_INLINE cy_en_sysclk_pll_src_t Cy_SysClk_PllGetSource(uint32_t pllNum)
{
    cy_en_sysclk_pll_src_t retVal = CY_SYSCLK_PLL_SRC_ECO;
    CY_ASSERT_L1(0UL == pllNum);

    if (0UL == pllNum)
    {
        CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 10.8', 'The field values match the enumeration.');
        retVal = (cy_en_sysclk_pll_src_t)_FLD2VAL(EXCO_CLK_SELECT_REF_SEL, EXCO_CLK_SELECT);
    } /*  Else return the default value */

    return (retVal);
}


/** \} group_sysclk_pll_funcs */
#endif /* EXCO_PLL_REF_IN_EN */


/**
* \addtogroup group_sysclk_pll_enums
* \{
*/

/** PLL bypass mode. See register CLK_PLL_CONFIG, bits BYPASS_SEL. */

typedef enum
{
    CY_SYSCLK_PLL_BYP_AUTO      = 0U,     /**< ECO when PLL is not locked, and PLL output when locked. Not valid if ECO is disabled. */
    CY_SYSCLK_PLL_BYP_ECO       = 2U,     /**< ECO regardless of PLL lock/enable status. Not valid if ECO is disabled. */
    CY_SYSCLK_PLL_BYP_PLL       = 3U,     /**< PLL Output regardless of lock status.
                                           *   In case of ECO is enabled - this option can be dangerous, because PLL output may be unstable,
                                           *   so the \ref CY_SYSCLK_PLL_BYP_AUTO is preferable;
                                           *   In case of ECO is disabled - this is the only valid PLL bypass option.
                                           */
} cy_en_sysclk_pll_bypass_t;

/** \} group_sysclk_pll_enums */

/**
* \addtogroup group_sysclk_pll_structs
* \{
*/
/** Structure containing information for configuration of a PLL. */
typedef struct
{
    uint32_t                       inputFreq;  /**< Frequency of the PLL source clock, in Hz.
                                                 *  This value can be left 0, then the \ref Cy_SysClk_PllConfigure
                                                 *  will get the source frequency automatically.
                                                 *  The desired source clock should be already enabled and selected
                                                 *  using \ref Cy_SysClk_PllSetSource.
                                                 */
    uint32_t                       outputFreq; /**< Frequency of the PLL output, in Hz. */
} cy_stc_sysclk_pll_config_t;

/** The structure containing information for PLL manual configuration.
 *  The values are directly mapped onto the register bitfields,
 *  see TRM for details.
 */
typedef struct
{
    uint8_t                        feedbackDiv;  /**< EXCO_PLL_CONFIG.FEEDBACK_DIV (P) bits */
    uint8_t                        referenceDiv; /**< EXCO_PLL_CONFIG.REFERENCE_DIV (Q) bits */
    uint8_t                        outputDiv;    /**< EXCO_PLL_CONFIG.OUTPUT_DIV bits */
    uint8_t                        icp;          /**< EXCO_PLL_CONFIG.ICP_SEL bits \cond usually CY_SYSCLK_IS_PLL_ICP_LT67MHZ value is recommended \endcond */
} cy_stc_sysclk_pll_manual_config_t;
/** \} group_sysclk_pll_structs */

/** \cond */
#define CY_SYSCLK_IS_PLL_ICP_LT67MHZ (2U) /* PLL Fout <= 67MHz*/
#define CY_SYSCLK_IS_PLL_ICP_GT67MHZ (3U) /* PLL Fout >  67MHz*/
/** \endcond */

/**
* \addtogroup group_sysclk_pll_funcs
* \{
*/

cy_en_sysclk_status_t Cy_SysClk_PllConfigure(uint32_t pllNum, const cy_stc_sysclk_pll_config_t * config);
cy_en_sysclk_status_t Cy_SysClk_PllManualConfigure(uint32_t pllNum, const cy_stc_sysclk_pll_manual_config_t * config);
cy_en_sysclk_status_t Cy_SysClk_PllEnable(uint32_t pllNum, uint32_t timeoutUs);
                 void Cy_SysClk_PllGetConfiguration(uint32_t pllNum, cy_stc_sysclk_pll_manual_config_t * config);
             uint32_t Cy_SysClk_PllGetFrequency(uint32_t pllNum);
 __STATIC_INLINE bool Cy_SysClk_PllIsEnabled(uint32_t pllNum);
 __STATIC_INLINE bool Cy_SysClk_PllIsLocked(uint32_t pllNum);
                 void Cy_SysClk_PllBypass(uint32_t pllNum, cy_en_sysclk_pll_bypass_t mode);
 __STATIC_INLINE cy_en_sysclk_pll_bypass_t Cy_SysClk_PllGetBypassState(uint32_t pllNum);
 __STATIC_INLINE bool Cy_SysClk_PllLostLock(uint32_t pllNum);
 __STATIC_INLINE void Cy_SysClk_PllDisable(uint32_t pllNum);


/*******************************************************************************
* Function Name: Cy_SysClk_PllIsEnabled
****************************************************************************//**
*
* Reports whether or not the selected PLL is enabled.
*
* \param pllNum the number of PLL instance, starting from 0.
* If there is only one PLL in device - the 0 is the only valid number.
* For other pllNum values the false (disabled) is returned.
*
* \return
* false = disabled \n
* true = enabled
*
* \note Not applicable for PSOC4 HVMS/PA.
*
* \funcusage
* \snippet sysclk_snippet.c snippet_Cy_SysClk_PllManualConfigure
*
*******************************************************************************/
__STATIC_INLINE bool Cy_SysClk_PllIsEnabled(uint32_t pllNum)
{
    bool retVal = false;
    CY_ASSERT_L1(0UL == pllNum);
    if (0UL == pllNum)
    {
        retVal = _FLD2BOOL(EXCO_PLL_CONFIG_ENABLE, EXCO_PLL_CONFIG);
    } /*  Else return false (disabled) */
    return (retVal);
}


/*******************************************************************************
* Function Name: Cy_SysClk_PllIsLocked
****************************************************************************//**
*
* Reports whether or not the selected PLL is locked.
*
* \param pllNum the number of PLL instance, starting from 0.
* If there is only one PLL in device - the 0 is the only valid number.
* For other pllNum values the false (unlocked) is returned.
*
* \return
* false = not locked \n
* true = locked
*
* \note Not applicable for PSOC4 HVMS/PA.
*
* \funcusage
* \snippet sysclk_snippet.c snippet_Cy_SysClk_PllManualConfigure
*
*******************************************************************************/
__STATIC_INLINE bool Cy_SysClk_PllIsLocked(uint32_t pllNum)
{
    bool retVal = false;
    CY_ASSERT_L1(0UL == pllNum);
    if (0UL == pllNum)
    {
        retVal = _FLD2BOOL(EXCO_PLL_STATUS_LOCKED, EXCO_PLL_STATUS);
    } /*  Else return false (unlocked) */
    return (retVal);
}


/*******************************************************************************
* Function Name: Cy_SysClk_PllLostLock
****************************************************************************//**
*
* Reports whether or not the selected PLL lost its lock since the last time this
* function was called. Clears the lost lock indicator.
*
* \param pllNum the number of PLL instance, starting from 0.
* If there is only one PLL in device - the 0 is the only valid number.
* For other pllNum values the false (did not lose lock) is returned.
*
* \return
* false = did not lose lock \n
* true = lost lock
*
* \note Not applicable for PSOC4 HVMS/PA.
*
* \funcusage
* \snippet sysclk_snippet.c snippet_Cy_SysClk_PllLostLock
*
*******************************************************************************/
__STATIC_INLINE bool Cy_SysClk_PllLostLock(uint32_t pllNum)
{
    bool retVal = false;
    CY_ASSERT_L1(0UL == pllNum);
    if (0UL == pllNum)
    {
        uint32_t locReg = EXCO_PLL_TEST;
        /* write a 1 to clear the UNLOCK_OCCURRED bit */
        EXCO_PLL_TEST = locReg;
        retVal = _FLD2BOOL(EXCO_PLL_TEST_UNLOCK_OCCURRED, locReg);
    } /*  Else return false (did not lose lock) */
    return (retVal);
}


/*******************************************************************************
* Function Name: Cy_SysClk_PllDisable
****************************************************************************//**
*
* Disables the selected PLL.
*
* \param pllNum the number of PLL instance, starting from 0.
* If there is only one PLL in device - the 0 is the only valid number.
*
* \note
* Call \ref SystemCoreClockUpdate after this function calling
* if it affects the HFCLK frequency.
*
* \note
* Call \ref Cy_SysLib_SetWaitStates before calling this function if
* the PLL is the source of HFCLK and the HFCLK frequency is increasing.
*
* \note
* Call \ref Cy_SysLib_SetWaitStates after calling this function if
* the PLL is the source of HFCLK and the HFCLK frequency is decreasing.
*
* \note Not applicable for PSOC4 HVMS/PA.
*
* \funcusage
* \snippet sysclk_snippet.c snippet_Cy_SysClk_PllManualConfigure
*
*******************************************************************************/
__STATIC_INLINE void Cy_SysClk_PllDisable(uint32_t pllNum)
{
    CY_ASSERT_L1(0UL == pllNum);
    if (0UL == pllNum)
    {
        EXCO_PLL_CONFIG &= ~(EXCO_PLL_CONFIG_ENABLE_Msk | EXCO_PLL_CONFIG_ISOLATE_N_Msk);
    }
}


/*******************************************************************************
* Function Name: Cy_SysClk_PllGetBypassState
****************************************************************************//**
*
* Returns the PLL bypass state.
*
* \param pllNum the number of PLL instance, starting from 0.
* If there is only one PLL in device - the 0 is the only valid number.
*
* \return The bypass state \ref cy_en_sysclk_pll_bypass_t : \n
* \ref CY_SYSCLK_PLL_BYP_AUTO - ECO when PLL is not locked, and PLL output when locked. \n
* \ref CY_SYSCLK_PLL_BYP_ECO - ECO regardless of PLL lock/enable status. \n
* \ref CY_SYSCLK_PLL_BYP_PLL - PLL Output regardless of lock status.
*
* \note Not applicable for PSOC4 HVMS/PA.
*
* \funcusage
* \snippet sysclk/snippet/sysclk_snippet.c snippet_Cy_SysClk_EcoPllHfClk
*
*******************************************************************************/
__STATIC_INLINE cy_en_sysclk_pll_bypass_t Cy_SysClk_PllGetBypassState(uint32_t pllNum)
{
    cy_en_sysclk_pll_bypass_t retVal = CY_SYSCLK_PLL_BYP_AUTO;
    CY_ASSERT_L1(0UL == pllNum);
    if (0UL == pllNum)
    {
        CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 10.8', 'The field values match the enumeration.');
        retVal = (cy_en_sysclk_pll_bypass_t)_FLD2VAL(EXCO_PLL_CONFIG_BYPASS_SEL, EXCO_PLL_CONFIG);
    } /*  Else return the default value */
    return (retVal);
}

/** \} group_sysclk_pll_funcs */


#if (CY_IP_M0S8EXCO_VERSION == 2U)
/* ========================================================================== */
/* ===========================    CSV SECTION    ============================ */
/* ========================================================================== */

/**
* \addtogroup group_sysclk_csv_structs
* \{
*/
/** The CSV configuration structure */
typedef struct
{
    uint16_t startupDelay;  /**< Startup delay time -1 (in reference clock cycles),
                             *   after enable or DeepSleep wakeup, from reference clock start to monitored clock start.
                             *   At a minimum (both clocks running): STARTUP >= (PERIOD +3) * FREQ_RATIO - UPPER,
                             *   with FREQ_RATIO = (Reference frequency / Monitored frequency)
                             *   On top of that the actual clock startup delay and the margin
                             *   for accuracy of both clocks must be added.
                             *
                             *   \note The startupDelay is applicable only when CSV is enabled before PLL and/or ECO has started.
                             *   Otherwise, CSV starts monitoring immediately after enabling and regardless of the startupDelay setting.
                             */
    uint16_t period;        /**< Period time.  Set the Period -1, in monitored clock cycles,
                             *   before the next monitored clock event happens.
                             *   PERIOD <=  (UPPER+1) / FREQ_RATIO -1,
                             *   with FREQ_RATIO = (Reference frequency / Monitored frequency)
                             *   In case the clocks are asynchronous: PERIOD <=  UPPER / FREQ_RATIO -1
                             *   Additionally margin must be added for accuracy of both clocks.
                             */
    uint16_t lowerLimit;    /**< Cycle time lower limit.  Set the lower limit -1, in reference clock cycles,
                             *   before the next monitored clock event is allowed to happen.
                             *   If a monitored clock event happens before this limit is reached a CSV error is detected.
                             *   LOWER must be at least 1 less than UPPER.
                             *   In case the clocks are asynchronous LOWER must be at least 3 less than UPPER.
                             */
    uint16_t upperLimit;    /**< Cycle time upper limit.  Set the upper limit -1, in reference clock cycles,
                             *   before (or same time) the next monitored clock event must happen.
                             *   If a monitored clock event does not happen before this limit is reached,
                             *   or does not happen at all (clock loss), a CSV error is detected.
                             */
    bool clkSwitchEn;       /**< Enable the clock switching to IMO feature */
    bool triggerEn;         /**< Enable the HW trigger when a clock switching to IMO occurs */
    bool interruptEn;       /**< Enable the \ref CY_SYSCLK_INTR_SW_IMO interrupt when a clock switching to IMO occurs */
}cy_stc_sysclk_csv_config_t;
/** \} group_sysclk_csv_structs */

/**
* \addtogroup group_sysclk_csv_funcs
* \{
*/

void Cy_SysClk_CsvInit(cy_stc_sysclk_csv_config_t * config);


/*******************************************************************************
* Function Name: Cy_SysClk_CsvEnable
****************************************************************************//**
*
* Enables the Clock Supervision block.
*
* This API is available on devices with the CSV Feature (i.e. PSOC 4500S and 4100S Max).
* Refer to the Device Datasheet to check the CSV feature support.
*
* \funcusage
* \snippet sysclk/snippet/sysclk_snippet.c SNIPPET_SYSCLK_CSV_ISR
* \snippet sysclk/snippet/sysclk_snippet.c SNIPPET_SYSCLK_CSV_INT
* \snippet sysclk/snippet/sysclk_snippet.c SNIPPET_SYSCLK_CSV_CFG
* \snippet sysclk/snippet/sysclk_snippet.c SNIPPET_SYSCLK_CSV_EN
*
*******************************************************************************/
__STATIC_INLINE void Cy_SysClk_CsvEnable(void)
{
    EXCO_REF_CTL |= EXCO_REF_CTL_CSV_EN_Msk;
}


/*******************************************************************************
* Function Name: Cy_SysClk_CsvIsEnabled
****************************************************************************//**
*
* Checks the Clock Supervision block enable/disable state.
*
* This API is available on devices with the CSV Feature (i.e. PSOC 4500S and 4100S Max).
* Refer to the Device Datasheet to check the CSV feature support.
*
* \funcusage
* \snippet sysclk/snippet/sysclk_snippet.c SNIPPET_SYSCLK_CSV_DSCB_DEC
*
*******************************************************************************/
__STATIC_INLINE bool Cy_SysClk_CsvIsEnabled(void)
{
    return _FLD2BOOL(EXCO_REF_CTL_CSV_EN, EXCO_REF_CTL);
}


/*******************************************************************************
* Function Name: Cy_SysClk_CsvDisable
****************************************************************************//**
*
* Disables clock supervision.
*
* This API is available on devices with the CSV Feature (i.e. PSOC 4500S and 4100S Max).
* Refer to the Device Datasheet to check the CSV feature support.
*
* \funcusage
* \snippet sysclk/snippet/sysclk_snippet.c SNIPPET_SYSCLK_CSV_DIS
*
*******************************************************************************/
__STATIC_INLINE void Cy_SysClk_CsvDisable(void)
{
    EXCO_REF_CTL &= ~EXCO_REF_CTL_CSV_EN_Msk;
}
/** \} group_sysclk_csv_funcs */


/**
* \addtogroup group_sysclk_pgm_dly_funcs
* \{
*/

/*******************************************************************************
* Function Name: Cy_SysClk_DelayCounterInit
****************************************************************************//**
*
* Initializes the programmable delay (PGM_DELAY) counter reload value.
*
* This API is available on devices with the CSV Feature (i.e. PSOC 4500S and 4100S Max).
* Refer to the Device Datasheet to check the CSV feature support.
*
* \param delayCount:
*  Valid range 0-65535, device default value is 256.
*  Sets the # of counts of IMO clock before system reset is asserted.
*
* \funcusage
* \snippet sysclk/snippet/sysclk_snippet.c SNIPPET_SYSCLK_PGM_DLY_EN
*
*******************************************************************************/
__STATIC_INLINE void Cy_SysClk_DelayCounterInit(uint16_t delayCount)
{
    EXCO_RSTDLY = _VAL2FLD(EXCO_RSTDLY_DLYCOUNT, delayCount);
}


/*******************************************************************************
* Function Name: Cy_SysClk_DelayCounterEnable
****************************************************************************//**
*
* Enables the PGM_DELAY block.
* A programmable delay counter starts at delay count
* value (see \ref Cy_SysClk_DelayCounterInit API) and counts down.
*
* The PGM_DELAY block will assert system reset when the counter reaches zero
* unless firmware intervenes and reloads the counter using
* \ref Cy_SysClk_DelayCounterReload() function.
*
* Also for the PGM_DELAY counter proper starting the \ref Cy_SysClk_DelayCounterReload()
* function should be called before this function.
*
* This API is available on devices with the CSV Feature (i.e. PSOC 4500S and 4100S Max).
* Refer to the Device Datasheet to check the CSV feature support.
*
* \funcusage \snippet sysclk/snippet/sysclk_snippet.c SNIPPET_SYSCLK_PGM_DLY_EN
*
*******************************************************************************/
__STATIC_INLINE void Cy_SysClk_DelayCounterEnable(void)
{
    EXCO_RSTDLY_CTL |= EXCO_RSTDLY_CTL_EN_Msk;
}


/*******************************************************************************
* Function Name: Cy_SysClk_DelayCounterIsEnabled
****************************************************************************//**
*
* Checks the PGM_DELAY block enable/disable state.
*
* This API is available on devices with the CSV Feature (i.e. PSOC 4500S and 4100S Max).
* Refer to the Device TRM to check the CSV feature support.
*
* \funcusage
* \snippet sysclk/snippet/sysclk_snippet.c SNIPPET_SYSCLK_CSV_DSCB_DEC
*
*******************************************************************************/
__STATIC_INLINE bool Cy_SysClk_DelayCounterIsEnabled(void)
{
    return _FLD2BOOL(EXCO_RSTDLY_CTL_EN, EXCO_RSTDLY_CTL);
}


/*******************************************************************************
* Function Name: Cy_SysClk_DelayCounterDisable
****************************************************************************//**
*
* Disables the PGM_DELAY block.
*
* This API is available on devices with the CSV Feature (i.e. PSOC 4500S and 4100S Max).
* Refer to the Device Datasheet to check the CSV feature support.
*
*******************************************************************************/
__STATIC_INLINE void Cy_SysClk_DelayCounterDisable(void)
{
    EXCO_RSTDLY_CTL &= ~EXCO_RSTDLY_CTL_EN_Msk;
}


/*******************************************************************************
* Function Name: Cy_SysClk_DelayCounterReload
****************************************************************************//**
*
* Reloads the PGM_DELAY counter with the delay count value.
*
* This API is available on devices with the CSV Feature (i.e. PSOC 4500S and 4100S Max).
* Refer to the Device Datasheet to check the CSV feature support.
*
* For the PGM_DELAY counter proper functioning, this function should be called
* before \ref Cy_SysClk_DelayCounterEnable.
*
* \funcusage
* \snippet sysclk/snippet/sysclk_snippet.c SNIPPET_SYSCLK_PGM_DLY_REL
*
*******************************************************************************/
__STATIC_INLINE void Cy_SysClk_DelayCounterReload(void)
{
    EXCO_RSTDLY_CTL |= EXCO_RSTDLY_CTL_LOAD_Msk;
}
/** \} group_sysclk_pgm_dly_funcs */


/**
* \addtogroup group_sysclk_int_macros
* \{
* \note This macro is available only for PSOC 4500S and 4100S Max devices.
*/
#define CY_SYSCLK_INTR_PLL_LOCK (EXCO_INTR_PLL_LOCK_Msk)   /**< PLL lock interrupt mask */
#define CY_SYSCLK_INTR_WD_ERR   (EXCO_INTR_WD_ERR_Msk)     /**< WatchDog error interrupt mask */
#define CY_SYSCLK_INTR_SW_IMO   (EXCO_INTR_CSV_CLK_SW_Msk) /**< Clock Supervisor Switched Clock Source to IMO interrupt mask */
/** \} group_sysclk_int_macros */

/** \cond internal */
#define CY_SYSCLK_INTR          (CY_SYSCLK_INTR_PLL_LOCK | CY_SYSCLK_INTR_WD_ERR | CY_SYSCLK_INTR_SW_IMO)
/** \endcond */


/**
* \addtogroup group_sysclk_int_funcs
* \{
*/

/*******************************************************************************
* Function Name: Cy_SysClk_GetInterruptStatus
****************************************************************************//**
*
* Returns the interrupt status.
*
* \note This API is available only for PSOC 4500S and 4100S Max devices.
*
* \return
* The interrupt status, see \ref group_sysclk_int_macros :
* - \ref CY_SYSCLK_INTR_PLL_LOCK
* - \ref CY_SYSCLK_INTR_WD_ERR
* - \ref CY_SYSCLK_INTR_SW_IMO
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_SysClk_GetInterruptStatus(void)
{
    return (EXCO_INTR);
}


/*******************************************************************************
* Function Name: Cy_SysClk_GetInterruptStatusMasked
****************************************************************************//**
*
* Returns the logical AND of the corresponding INTR and INTR_MASK registers
* in a single-load operation.
*
* \note This API is available only for PSOC 4500S and 4100S Max devices.
*
* \return
* The masked interrupt status, see \ref group_sysclk_int_macros :
* - \ref CY_SYSCLK_INTR_PLL_LOCK
* - \ref CY_SYSCLK_INTR_WD_ERR
* - \ref CY_SYSCLK_INTR_SW_IMO
*
* \funcusage
* \snippet sysclk/snippet/sysclk_snippet.c SNIPPET_SYSCLK_CSV_ISR
* Also refer to \ref group_sysclk_csv_funcs
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_SysClk_GetInterruptStatusMasked(void)
{
    return (EXCO_INTR_MASKED & CY_SYSCLK_INTR);
}


/*******************************************************************************
* Function Name: Cy_SysClk_ClearInterrupt
****************************************************************************//**
*
* Clears the interrupt status.
*
* \note This API is available only for PSOC 4500S and 4100S Max devices.
*
* \param intrMask
* The mask of interrupts to clear. Typically this is the value returned
* by \ref Cy_SysClk_GetInterruptStatusMasked or \ref Cy_SysClk_GetInterruptStatus.
* Alternately, select one or more values from \ref group_sysclk_int_macros and "OR" them together.
* - \ref CY_SYSCLK_INTR_PLL_LOCK
* - \ref CY_SYSCLK_INTR_WD_ERR
* - \ref CY_SYSCLK_INTR_SW_IMO
*
* \funcusage
* \snippet sysclk/snippet/sysclk_snippet.c SNIPPET_SYSCLK_CSV_ISR
* Also refer to \ref group_sysclk_csv_funcs
*
*******************************************************************************/
__STATIC_INLINE void Cy_SysClk_ClearInterrupt(uint32_t intrMask)
{
    EXCO_INTR = intrMask & CY_SYSCLK_INTR;
    (void) EXCO_INTR;
}


/*******************************************************************************
* Function Name: Cy_SysClk_SetInterrupt
****************************************************************************//**
*
* Sets the specified interrupt status.
* Intended mostly for debugging.
*
* \note This API is available only for PSOC 4500S and 4100S Max devices.
*
* \param intrMask
* The mask of interrupts to set.
* Select one or more values from \ref group_sysclk_int_macros and "OR" them together.
* - \ref CY_SYSCLK_INTR_PLL_LOCK
* - \ref CY_SYSCLK_INTR_WD_ERR
* - \ref CY_SYSCLK_INTR_SW_IMO
*
*******************************************************************************/
__STATIC_INLINE void Cy_SysClk_SetInterrupt(uint32_t intrMask)
{
    EXCO_INTR_SET = intrMask & CY_SYSCLK_INTR;
}


/*******************************************************************************
* Function Name: Cy_SysClk_GetInterruptMask
****************************************************************************//**
*
* Returns the interrupt mask value.
*
* \note This API is available only for PSOC 4500S and 4100S Max devices.
*
* \return
* The interrupt mask value, see \ref group_sysclk_int_macros :
* - \ref CY_SYSCLK_INTR_PLL_LOCK
* - \ref CY_SYSCLK_INTR_WD_ERR
* - \ref CY_SYSCLK_INTR_SW_IMO
*
* \funcusage \snippet sysclk_snippet.c snippet_Cy_SysClk_GetInterruptMask
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_SysClk_GetInterruptMask(void)
{
    return (EXCO_INTR_MASK & CY_SYSCLK_INTR);
}


/*******************************************************************************
* Function Name: Cy_SysClk_SetInterruptMask
****************************************************************************//**
*
* Sets the specified interrupt mask value.
*
* \note This API is available only for PSOC 4500S and 4100S Max devices.
*
* \param intrMask
* The mask of interrupts.
* Select one or more values from \ref group_sysclk_int_macros and "OR" them together.
* - \ref CY_SYSCLK_INTR_PLL_LOCK
* - \ref CY_SYSCLK_INTR_WD_ERR
* - \ref CY_SYSCLK_INTR_SW_IMO
*
* \funcusage
* \snippet sysclk/snippet/sysclk_snippet.c SNIPPET_SYSCLK_CSV_EN
*
*******************************************************************************/
__STATIC_INLINE void Cy_SysClk_SetInterruptMask(uint32_t intrMask)
{
    EXCO_INTR_MASK = intrMask & CY_SYSCLK_INTR;
}


/** \} group_sysclk_int_funcs */
#endif /* CY_IP_M0S8EXCO_VERSION == 2U */
#endif /* EXCO_PLL_PRESENT */
#endif /* CY_IP_M0S8EXCO */


/* ========================================================================== */
/* ===========================    ILO SECTION    ============================ */
/* ========================================================================== */
/**
* \addtogroup group_sysclk_ilo_funcs
* \{
*/
__STATIC_INLINE void Cy_SysClk_IloEnable(void);
__STATIC_INLINE bool Cy_SysClk_IloIsEnabled(void);
__STATIC_INLINE cy_en_sysclk_status_t Cy_SysClk_IloDisable(void);
                 void Cy_SysClk_IloStartMeasurement(void);
                 void Cy_SysClk_IloStopMeasurement(void);
cy_en_sysclk_status_t Cy_SysClk_IloCompensate(uint32_t desiredDelay , uint32_t * compensatedCycles);


/*******************************************************************************
* Function Name: Cy_SysClk_IloEnable
****************************************************************************//**
*
* Enables the ILO.
*
* \note The watchdog timer (WDT) should be disabled before calling this function.
* ILO Enable are ignored unless the WDT is disabled.
* Call the \ref Cy_WDT_Disable() API to disable the WDT.
* Not applicable for PSOC4 HVMS/PA.
*
* \note ILO Enable are ignored if ILO is selected as LFCLK source.
* Applicable to PSOC4 HVMS/PA only.
*
* \warning The Watchdog timer should be unlocked before ILO being enabled.
* Call the \ref Cy_WDT_Unlock() API to unlock the WDT.
* Applicable to PSOC4 HVMS/PA only.
*
* \funcusage
* \snippet sysclk_snippet.c snippet_Cy_SysClk_WcoDisable
* \snippet sysclk_snippet.c snippet_Cy_SysClk_IloEnable_PiloDisable
*
*******************************************************************************/
__STATIC_INLINE void Cy_SysClk_IloEnable(void)
{
#if defined (CY_IP_M0S8SRSSHV)
    CY_ASSERT_L2(false == Cy_WDT_Locked());
    /* Avoid lock register's potential race condition. */
    uint32_t intrState = Cy_SysLib_EnterCriticalSection();
    Cy_SysClk_UnlockProtReg();
#endif /* defined (CY_IP_M0S8SRSSHV) */
    SRSS_CLK_ILO_CONFIG |= SRSS_CLK_ILO_CONFIG_ENABLE_Msk;
#if defined (CY_IP_M0S8SRSSHV)
    Cy_SysClk_LockProtReg();
    Cy_SysLib_ExitCriticalSection(intrState);
#endif /* defined (CY_IP_M0S8SRSSHV) */
}


/*******************************************************************************
* Function Name: Cy_SysClk_IloIsEnabled
****************************************************************************//**
*
* Returns the ILO enable/disable state.
*
* \funcusage
* \snippet sysclk_snippet.c snippet_Cy_SysClk_IloDisable
*
*******************************************************************************/
__STATIC_INLINE bool Cy_SysClk_IloIsEnabled(void)
{
    return(_FLD2BOOL(SRSS_CLK_ILO_CONFIG_ENABLE, SRSS_CLK_ILO_CONFIG));
}


/*******************************************************************************
* Function Name: Cy_SysClk_IloDisable
****************************************************************************//**
*
* Disables the ILO. ILO can't be disabled if WDT is enabled or
* the ILO is selected as a LFCLK source.
*
* \return Error / status code, \ref cy_en_sysclk_status_t : \n
* \ref CY_SYSCLK_SUCCESS - ILO successfully disabled \n
* \ref CY_SYSCLK_INVALID_STATE - Cannot disable the ILO if the WDT is enabled or
* the ILO is selected as a LFCLK source.
*
* \note Do not call this function if the WDT is enabled, and if the WDT is clocked by
* the ILO. Call the \ref Cy_WDT_Disable() API to disable the WDT.
*
* \warning The Watchdog timer should be unlocked before ILO being disabled.
* Call the \ref Cy_WDT_Unlock() API to unlock the WDT.
* Applicable to PSOC4 HVMS/PA only.
*
* \funcusage
* \snippet sysclk_snippet.c snippet_Cy_SysClk_IloDisable
* \snippet sysclk_snippet.c snippet_Cy_SysClk_IloEnable_PiloDisable
*
*******************************************************************************/
__STATIC_INLINE cy_en_sysclk_status_t Cy_SysClk_IloDisable(void)
{
    cy_en_sysclk_status_t retVal = CY_SYSCLK_INVALID_STATE;

#if defined (CY_IP_M0S8SRSSHV)
    if (!Cy_WDT_Locked())
    {
        /* If WDT is not enabled
         * or if WDT is driven by another source,
         * then ILO can be disabled
         */
        if (!Cy_WDT_IsEnabled() || (CY_SYSCLK_CLKLF_IN_ILO != Cy_SysClk_ClkLfGetSource()))
        {
            /* Avoid lock register's potential race condition. */
            uint32_t intrState = Cy_SysLib_EnterCriticalSection();
            Cy_SysClk_UnlockProtReg();
            SRSS_CLK_ILO_CONFIG &= ~SRSS_CLK_ILO_CONFIG_ENABLE_Msk;
            Cy_SysClk_LockProtReg();
            Cy_SysLib_ExitCriticalSection(intrState);
            retVal = CY_SYSCLK_SUCCESS;
        }
    }
#elif defined(CY_IP_S8SRSSLT)
    if (!Cy_WDT_IsEnabled())
    {
        SRSS_CLK_ILO_CONFIG &= ~SRSS_CLK_ILO_CONFIG_ENABLE_Msk;
        retVal = CY_SYSCLK_SUCCESS;
    }
#endif /* defined (CY_IP_M0S8SRSSHV) */

    return (retVal);
}
/** \} group_sysclk_ilo_funcs */


#if defined(CY_IP_M0S8WCO)
/* ========================================================================== */
/* ===========================    WCO SECTION    ============================ */
/* ========================================================================== */

#define CY_SYSCLK_WCO_CONFIG_DPLL_LF_LIMIT_MAX         (0xFFUL)
#define CY_SYSCLK_WCO_CONFIG_DPLL_LF_LIMIT_STEP        (16UL)
#define CY_SYSCLK_WCO_IMO_TIMEOUT_MS                   (20UL)
#define CY_SYSCLK_WCO_DPLL_TIMEOUT_MS                  (1UL)
#define CY_SYSCLK_WCO_DPLL_LF_IGAIN                    (4UL)
#define CY_SYSCLK_WCO_DPLL_LF_PGAIN                    (2UL)
#define CY_SYSCLK_WCO_TRIM_GM_HPM                      (0x1UL)
#define CY_SYSCLK_WCO_TRIM_XGM_2620NA                  (0x01UL)

/** Recommended WCO startup timeout for blocking \ref Cy_SysClk_WcoEnable execution */
#define CY_SYSCLK_WCO_TIMEOUT_US                       (500000UL)

/**
* \addtogroup group_sysclk_wco_funcs
* \{
*/
__STATIC_INLINE void Cy_SysClk_WcoEnable(uint32_t timeoutUs);
__STATIC_INLINE void Cy_SysClk_WcoDisable(void);
__STATIC_INLINE bool Cy_SysClk_WcoIsEnabled(void);
__STATIC_INLINE void Cy_SysClk_WcoBypass(bool bypass);


 /*******************************************************************************
 * Function Name: Cy_SysClk_WcoEnable
 ****************************************************************************//**
 *
 * Enables the WCO.
 *
 * This API is available on devices with the WCO Feature (i.e. PSOC 4000S and 4100S Max).
 * Refer to the Device Datasheet to check the WCO feature support.
 *
 * \param timeoutUs - WCO startup delay in microseconds.
 *
 * \funcusage
 * \snippet sysclk_snippet.c snippet_Cy_SysClk_WcoEnable
 *
 *******************************************************************************/
__STATIC_INLINE void Cy_SysClk_WcoEnable(uint32_t timeoutUs)
{
    WCO_CONFIG |= WCO_CONFIG_IP_ENABLE_Msk;
    Cy_SysLib_Delay(timeoutUs / 1000UL);
    Cy_SysLib_DelayUs((uint16_t)(timeoutUs % 1000UL));
}


/*******************************************************************************
* Function Name: Cy_SysClk_WcoIsEnabled
****************************************************************************//**
*
* Returns the WCO enable/disable state.
*
* This API is available on devices with the WCO Feature (i.e. PSOC 4000S and 4100S Max).
* Refer to the Device Datasheet to check the WCO feature support.
*
*******************************************************************************/
__STATIC_INLINE bool Cy_SysClk_WcoIsEnabled(void)
{
    return(_FLD2BOOL(WCO_CONFIG_IP_ENABLE, WCO_CONFIG));
}


/*******************************************************************************
* Function Name: Cy_SysClk_WcoDisable
****************************************************************************//**
*
* Disables the WCO.
*
* This API is available on devices with the WCO Feature (i.e. PSOC 4000S and 4100S Max).
* Refer to the Device Datasheet to check the WCO feature support.
*
*******************************************************************************/
__STATIC_INLINE void Cy_SysClk_WcoDisable(void)
{
    WCO_CONFIG &= ~WCO_CONFIG_IP_ENABLE_Msk;
}


/*******************************************************************************
* Function Name: Cy_SysClk_WcoBypass
****************************************************************************//**
*
* Enables/disables external clock input through the WCO input pin.
*
* This API is available on devices with the WCO Feature (i.e. PSOC 4000S and 4100S Max).
* Refer to the Device Datasheet to check the WCO feature support.
*
* \param bypass:
* - true - external clock input through the WCO input pin (WCO bypass enabled)
* - false - regular WCO operation (bypass disabled)
*
* \funcusage
* \snippet sysclk_snippet.c snippet_Cy_SysClk_WcoBypass
*
*******************************************************************************/
__STATIC_INLINE void Cy_SysClk_WcoBypass(bool bypass)
{
    if (bypass)
    {
        WCO_CONFIG |= WCO_CONFIG_EXT_INPUT_EN_Msk;
    }
    else
    {
        WCO_CONFIG &= ~WCO_CONFIG_EXT_INPUT_EN_Msk;
    }
}

/** \} group_sysclk_wco_funcs */
#endif /* (CY_IP_M0S8WCO) */


/* ========================================================================== */
/* ==========================    HFCLK SECTION    =========================== */
/* ========================================================================== */
/**
* \addtogroup group_sysclk_clk_hf_enums
* \{
*/
/**
* Selects which HFCLK input to configure.
* Used with functions \ref Cy_SysClk_ClkHfSetSource and \ref Cy_SysClk_ClkHfGetSource.
*/
typedef enum
{
    CY_SYSCLK_CLKHF_IN_IMO    = 0U,  /**< IMO - Internal R/C Oscillator */
    CY_SYSCLK_CLKHF_IN_EXTCLK = 1U,  /**< EXTCLK - External Clock Pin.
                                      *   Note that there may be HW collisions with the ECO connection (if supported)
                                      */
#if defined (CY_IP_M0S8EXCO)
    CY_SYSCLK_CLKHF_IN_EXCO   = 2U,  /**< EXCO block output, ECO or PLL, use \ref Cy_SysClk_PllBypass to select between them */
    /** \cond */
    CY_SYSCLK_CLKHF_IN_ECO   = 10U,  /* Deprecated, BWC for HAL 2.0.0 only,
                                      * use CY_SYSCLK_CLKHF_IN_EXCO and
                                      * Cy_SysClk_PllBypass(CY_SYSCLK_PLL_BYP_ECO)
                                      */
#if (defined(EXCO_PLL_PRESENT) && (EXCO_PLL_PRESENT == 1U))
    CY_SYSCLK_CLKHF_IN_PLL    = 6U,  /* Deprecated, BWC for HAL 2.0.0 only,
                                      * use CY_SYSCLK_CLKHF_IN_EXCO and
                                      * Cy_SysClk_PllBypass() with CY_SYSCLK_PLL_BYP_AUTO or CY_SYSCLK_PLL_BYP_PLL
                                      */
#endif /* EXCO_PLL_PRESENT */
    /** \endcond */
#endif /* CY_IP_M0S8EXCO */
#if defined (CY_IP_M0S8SRSSHV)
    CY_SYSCLK_CLKHF_IN_HPOSC    = 3U,  /**< HPOSC - High Precision Oscillator */
#endif /* CY_IP_M0S8SRSSHV */
} cy_en_sysclk_clkhf_src_t;

/**
* Clock divider values.
* Used with functions \ref Cy_SysClk_ClkHfSetDivider, \ref Cy_SysClk_ClkHfGetDivider,
*                     \ref Cy_SysClk_ClkSysSetDivider and \ref Cy_SysClk_ClkSysGetDivider.
*/
typedef enum
{
    CY_SYSCLK_NO_DIV = 0U,    /**< don't divide */
    CY_SYSCLK_DIV_2  = 1U,    /**< divide by 2 */
    CY_SYSCLK_DIV_4  = 2U,    /**< divide by 4 */
    CY_SYSCLK_DIV_8  = 3U     /**< divide by 8 */
} cy_en_sysclk_dividers_t;
/** \} group_sysclk_clk_hf_enums */

/** \cond */
#define CY_SYSCLK_IS_DIV_VALID(div) (((div) == CY_SYSCLK_NO_DIV) || \
                                     ((div) == CY_SYSCLK_DIV_2)  || \
                                     ((div) == CY_SYSCLK_DIV_4)  || \
                                     ((div) == CY_SYSCLK_DIV_8))
/** \endcond */

/**
* \addtogroup group_sysclk_clk_hf_funcs
* \{
*/
                  cy_en_sysclk_status_t Cy_SysClk_ClkHfSetSource(cy_en_sysclk_clkhf_src_t source);
               cy_en_sysclk_clkhf_src_t Cy_SysClk_ClkHfGetSource(void);
__STATIC_INLINE                    void Cy_SysClk_ClkHfSetDivider(cy_en_sysclk_dividers_t divider);
__STATIC_INLINE cy_en_sysclk_dividers_t Cy_SysClk_ClkHfGetDivider(void);
                               uint32_t Cy_SysClk_ClkHfGetFrequency(void);


/*******************************************************************************
* Function Name: Cy_SysClk_ClkHfSetDivider
****************************************************************************//**
*
* Sets a divider value for HFCLK.
*
* \param divider \ref cy_en_sysclk_dividers_t
*
* \note Also call \ref Cy_SysClk_ClkHfSetSource to set the HFCLK source.
*
* \note Call \ref SystemCoreClockUpdate after this function calling.
*
* \note Call \ref Cy_SysLib_SetWaitStates before calling this function if
* SYSCLK frequency is increasing.
*
* \note Call \ref Cy_SysLib_SetWaitStates after calling this function if
* SYSCLK frequency is decreasing.
*
* \funcusage
* \snippet sysclk_snippet.c snippet_Cy_SysClk_ClkHfSetDivider
*
*******************************************************************************/
__STATIC_INLINE void Cy_SysClk_ClkHfSetDivider(cy_en_sysclk_dividers_t divider)
{
    if (CY_SYSCLK_IS_DIV_VALID(divider))
    {
    #if defined (CY_IP_M0S8SRSSHV)
        /* Avoid lock register's potential race condition. */
        uint32_t intrState = Cy_SysLib_EnterCriticalSection();
        Cy_SysClk_UnlockProtReg();
    #endif /* defined (CY_IP_M0S8SRSSHV) */
        CY_REG32_CLR_SET(SRSS_CLK_SELECT, SRSS_CLK_SELECT_HFCLK_DIV, divider);
    #if defined (CY_IP_M0S8SRSSHV)
        Cy_SysClk_LockProtReg();
        Cy_SysLib_ExitCriticalSection(intrState);
    #endif /* defined (CY_IP_M0S8SRSSHV) */
    }
}


/*******************************************************************************
* Function Name: Cy_SysClk_ClkHfGetDivider
****************************************************************************//**
*
* Returns the HFCLK divider value.
*
* \return \ref cy_en_sysclk_dividers_t : \n
* \ref CY_SYSCLK_NO_DIV - don't divide. \n
* \ref CY_SYSCLK_DIV_2 - divide by 2 \n
* \ref CY_SYSCLK_DIV_4 - divide by 4 \n
* \ref CY_SYSCLK_DIV_8 - divide by 8
*
* \funcusage
* \snippet sysclk_snippet.c snippet_Cy_SysClk_ClkHfSetDivider
*
*******************************************************************************/
__STATIC_INLINE cy_en_sysclk_dividers_t Cy_SysClk_ClkHfGetDivider(void)
{
    CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 10.8', 'The field values match the enumeration.');
    return ((cy_en_sysclk_dividers_t)(_FLD2VAL(SRSS_CLK_SELECT_HFCLK_DIV, SRSS_CLK_SELECT)));
}
/** \} group_sysclk_clk_hf_funcs */


#if defined (CY_IP_M0S8SRSSHV)
/* ========================================================================== */
/* ===========================    PILO SECTION   ============================ */
/* ========================================================================== */
/**
* \addtogroup group_sysclk_pilo_funcs
* \{
*/
__STATIC_INLINE void Cy_SysClk_PiloEnable(void);
__STATIC_INLINE bool Cy_SysClk_PiloIsEnabled(void);
__STATIC_INLINE cy_en_sysclk_status_t Cy_SysClk_PiloDisable(void);


/*******************************************************************************
* Function Name: Cy_SysClk_PiloEnable
****************************************************************************//**
*
* Enables the PILO.
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \note PILO Enable are ignored if PILO is selected as LFCLK source.
*
* \warning The Watchdog timer should be unlocked before PILO being enabled.
* Call the \ref Cy_WDT_Unlock() API to unlock the WDT.
*
* \funcusage
* \snippet sysclk_snippet.c snippet_Cy_SysClk_PiloEnable
*
*******************************************************************************/
__STATIC_INLINE void Cy_SysClk_PiloEnable(void)
{
    CY_ASSERT_L2(CY_SYSCLK_CLKLF_IN_PILO != Cy_SysClk_ClkLfGetSource());
    CY_ASSERT_L2(false == Cy_WDT_Locked());
    /* Avoid lock register's potential race condition. */
    uint32_t intrState = Cy_SysLib_EnterCriticalSection();
    Cy_SysClk_UnlockProtReg();
    SRSS_PILO_CTL |= SRSS_PILO_CTL_ILO_EN_Msk;
    Cy_SysClk_LockProtReg();
    Cy_SysLib_ExitCriticalSection(intrState);
}

/*******************************************************************************
* Function Name: Cy_SysClk_PiloIsEnabled
****************************************************************************//**
*
* Returns the PILO enable/disable state.
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \funcusage
* \snippet sysclk_snippet.c snippet_Cy_SysClk_PiloDisable
*
*******************************************************************************/
__STATIC_INLINE bool Cy_SysClk_PiloIsEnabled(void)
{
    return(_FLD2BOOL(SRSS_PILO_CTL_ILO_EN, SRSS_PILO_CTL));
}

/*******************************************************************************
* Function Name: Cy_SysClk_PiloDisable
****************************************************************************//**
*
* Disables the PILO. PILO can't be disabled if WDT is enabled or
* the PILO is selected as a LFCLK source.
*
* \return Error / status code, \ref cy_en_sysclk_status_t : \n
* \ref CY_SYSCLK_SUCCESS - PILO successfully disabled \n
* \ref CY_SYSCLK_INVALID_STATE - Cannot disable the PILO if the WDT is enabled or
* the PILO is selected as a LFCLK source.
*
* \note Do not call this function if the WDT is enabled, and if the WDT is clocked by
* the PILO.
*
* \warning The Watchdog timer should be unlocked before PILO being disabled.
* Call the \ref Cy_WDT_Unlock() API to unlock the WDT.
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \funcusage
* \snippet sysclk_snippet.c snippet_Cy_SysClk_PiloDisable
*
*******************************************************************************/
__STATIC_INLINE cy_en_sysclk_status_t Cy_SysClk_PiloDisable(void)
{
    cy_en_sysclk_status_t retVal = CY_SYSCLK_INVALID_STATE;

    if (!Cy_WDT_Locked())
    {
        /* If WDT is not enabled
         * or if WDT is driven by another source,
         * then PILO can be disabled
         */
        if (!Cy_WDT_IsEnabled() || (CY_SYSCLK_CLKLF_IN_PILO != Cy_SysClk_ClkLfGetSource()))
        {
            /* Avoid lock register's potential race condition. */
            uint32_t intrState = Cy_SysLib_EnterCriticalSection();
            Cy_SysClk_UnlockProtReg();
            SRSS_PILO_CTL &= ~SRSS_PILO_CTL_ILO_EN_Msk;
            Cy_SysClk_LockProtReg();
            Cy_SysLib_ExitCriticalSection(intrState);
            retVal = CY_SYSCLK_SUCCESS;
        }
    }
    /* clear history for second order trim */
    iterationNum = 0UL;
    errorIntegralHz = 0;
    return (retVal);
}
/** \} group_sysclk_pilo_funcs */


/* ========================================================================== */
/* ===========================   HPOSC SECTION   ============================ */
/* ========================================================================== */
/**
* \addtogroup group_sysclk_hposc_funcs
* \{
*/
__STATIC_INLINE void Cy_SysClk_HposcEnable(void);
__STATIC_INLINE bool Cy_SysClk_HposcIsEnabled(void);
__STATIC_INLINE cy_en_sysclk_status_t Cy_SysClk_HposcDisable(void);


/*******************************************************************************
* Function Name: Cy_SysClk_HposcEnable
****************************************************************************//**
*
* Enables the HPOSC.
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \funcusage
* \snippet sysclk_snippet.c snippet_Cy_SysClk_HposcEnable
*
*******************************************************************************/
__STATIC_INLINE void Cy_SysClk_HposcEnable(void)
{
    /* Avoid lock register's potential race condition. */
    uint32_t intrState = Cy_SysLib_EnterCriticalSection();
    Cy_SysClk_UnlockProtReg();
    SRSS_HPOSC_CTL |= SRSS_HPOSC_CTL_IMO_EN_Msk;
    Cy_SysClk_LockProtReg();
    Cy_SysLib_ExitCriticalSection(intrState);
}

/*******************************************************************************
* Function Name: Cy_SysClk_HposcIsEnabled
****************************************************************************//**
*
* Returns the HPOSC enable/disable state.
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \funcusage
* \snippet sysclk_snippet.c snippet_Cy_SysClk_HposcDisable
*
*******************************************************************************/
__STATIC_INLINE bool Cy_SysClk_HposcIsEnabled(void)
{
    return(_FLD2BOOL(SRSS_HPOSC_CTL_IMO_EN, SRSS_HPOSC_CTL));
}

/*******************************************************************************
* Function Name: Cy_SysClk_HposcDisable
****************************************************************************//**
*
* Disables the HPOSC. HPOSC can't be disabled if the HPOSC is selected as a HFCLK source.
*
* \return Error / status code, \ref cy_en_sysclk_status_t : \n
* \ref CY_SYSCLK_SUCCESS - HPOSC successfully disabled \n
* \ref CY_SYSCLK_INVALID_STATE - Cannot disable the HPOSC if selected as the HFCLK source.
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \funcusage
* \snippet sysclk_snippet.c snippet_Cy_SysClk_HposcDisable
*
*******************************************************************************/
__STATIC_INLINE cy_en_sysclk_status_t Cy_SysClk_HposcDisable(void)
{
    cy_en_sysclk_status_t retVal = CY_SYSCLK_INVALID_STATE;

    if (CY_SYSCLK_CLKHF_IN_HPOSC != Cy_SysClk_ClkHfGetSource())
    {
        /* Avoid lock register's potential race condition. */
        uint32_t intrState = Cy_SysLib_EnterCriticalSection();
        Cy_SysClk_UnlockProtReg();
        SRSS_HPOSC_CTL &= ~SRSS_HPOSC_CTL_IMO_EN_Msk;
        Cy_SysClk_LockProtReg();
        Cy_SysLib_ExitCriticalSection(intrState);
        retVal = CY_SYSCLK_SUCCESS;
    }

    return (retVal);
}
/** \} group_sysclk_hposc_funcs */


/* ========================================================================== */
/* ====================    CLOCK CALIBRATION SECTION    ===================== */
/* ========================================================================== */
/**
* \addtogroup group_sysclk_calclk_enums
* \{
*/
/** Defines all possible clock sources */
typedef enum
{
    CY_SYSCLK_MEAS_CLK_NC =     0U, /**< Disabled - output is 0 */
    CY_SYSCLK_MEAS_CLK_ILO =    1U, /**< ILO output */
    CY_SYSCLK_MEAS_CLK_IMO =    2U, /**< IMO primary output */
    CY_SYSCLK_MEAS_CLK_SYSCLK = 7U, /**< SYSCLK output */
    CY_SYSCLK_MEAS_CLK_HPOSC =  10U, /**< HPOSC output. Applicable only if HPOSC_PRESENT=1 */
    CY_SYSCLK_MEAS_CLK_PILO =   11U /**< PILO output. Applicable only if PILO_PRESENT=1 */
} cy_en_meas_clks_t;
/** \} group_sysclk_calclk_enums */

/**
* \addtogroup group_sysclk_trim_enums
* \{
*/
/** Defines all possible formulas to calculate trim */
typedef enum
{
    CY_SYSCLK_CALIB_FIRST_ORDER = 0U,   /**< Calibration using first order for non-periodic calibration */
    CY_SYSCLK_CALIB_SECOND_ORDER = 1U   /**< Calibration using second order for periodic calibration */
} cy_en_sysclk_calib_formula_t;
/** \} group_sysclk_trim_enums */

/**
* \addtogroup group_sysclk_calclk_funcs
* \{
*/
cy_en_sysclk_status_t   Cy_SysClk_CalibStart(cy_en_meas_clks_t clock1, uint16_t count1, cy_en_meas_clks_t clock2);
uint32_t                Cy_SysClk_CalibGetFreq(bool measuredClock, uint16_t count1);
bool                    Cy_SysClk_CalibDone(void);
/** \} group_sysclk_calclk_funcs */

/**
* \addtogroup group_sysclk_int_funcs
* \{
*/

__STATIC_INLINE void  Cy_SysClk_CalibSetInterrupt(void);
__STATIC_INLINE void  Cy_SysClk_CalibClearInterrupt(void);
__STATIC_INLINE bool  Cy_SysClk_CalibGetInterruptStatus(void);
__STATIC_INLINE bool  Cy_SysClk_CalibGetInterruptStatusMasked(void);
__STATIC_INLINE void  Cy_SysClk_CalibSetInterruptMask(bool enable);

/*******************************************************************************
* Function Name: Cy_SysClk_CalibSetInterrupt
****************************************************************************//**
*
* Set interrupt for clock calibration counter done.
* Can be used to set interrupts for firmware testing.
* This field is reset during DeepSleep mode.
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \funcusage
* \snippet sysclk_snippet.c snippet_Cy_SysClk_CalibInterrupt
*
*******************************************************************************/
__STATIC_INLINE void Cy_SysClk_CalibSetInterrupt(void)
{
    /* Write a "1" to Set the SRSS_INTR_SET_CLK_CAL bit */
    SRSS_SRSS_INTR_SET = SRSSHV_SRSS_INTR_SET_CLK_CAL_Msk;
}

/*******************************************************************************
* Function Name: Cy_SysClk_CalibClearInterrupt
****************************************************************************//**
*
* Clears the interrupt status.
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \funcusage
* \snippet sysclk_snippet.c snippet_Cy_SysClk_CalibInterrupt
*
*******************************************************************************/
__STATIC_INLINE void Cy_SysClk_CalibClearInterrupt(void)
{
    /* Write a "1" to Clear the SRSS_INTR_CLK_CAL bit */
    SRSS_SRSS_INTR = SRSSHV_SRSS_INTR_CLK_CAL_Msk;
    /* Read the interrupt register to ensure that the initial clearing write has
    * been flushed out to the hardware.
    */
    (void) SRSS_SRSS_INTR;
}

/*******************************************************************************
* Function Name: Cy_SysClk_CalibGetInterruptStatus
****************************************************************************//**
*
* Returns the interrupt status.
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \funcusage
* \snippet sysclk_snippet.c snippet_Cy_SysClk_CalibInterrupt
*
*******************************************************************************/
__STATIC_INLINE bool Cy_SysClk_CalibGetInterruptStatus(void)
{
    return _FLD2BOOL(SRSSHV_SRSS_INTR_CLK_CAL, SRSS_SRSS_INTR);
}

/*******************************************************************************
* Function Name: Cy_SysClk_CalibGetInterruptStatusMasked
****************************************************************************//**
*
* Returns an interrupt request register masked by an interrupt mask.
* Returns the result of the bitwise AND operation between the corresponding
* interrupt request and mask bits.
*
* \return
* The masked interrupt status.
* true  : Masked interrupt occurs.
* false : No Masked interrupt occurs.
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \funcusage
* \snippet sysclk_snippet.c snippet_Cy_SysClk_CalibInterrupt
*
*******************************************************************************/
__STATIC_INLINE bool Cy_SysClk_CalibGetInterruptStatusMasked(void)
{
    return _FLD2BOOL(SRSSHV_SRSS_MASKED_CLK_CAL, SRSS->SRSS_MASKED);
}

/*******************************************************************************
* Function Name: Cy_SysClk_CalibSetInterruptMask
****************************************************************************//**
*
* Sets the clock calibration interrupt mask.
*
* \param enable
* - true - to masking interrupt for calibration counter done
* - false - to reset masking interrupt
*
* \note Applicable to PSOC4 HVMS/PA only.
*
*******************************************************************************/
__STATIC_INLINE void Cy_SysClk_CalibSetInterruptMask(bool enable)
{
    if (!enable)
    {
        SRSS_SRSS_INTR_MASK |= SRSSHV_SRSS_INTR_MASK_CLK_CAL_Msk;
    }
    else
    {
        SRSS_SRSS_INTR_MASK &= ~SRSSHV_SRSS_INTR_MASK_CLK_CAL_Msk;
    }
}
/** \} group_sysclk_int_funcs */


/* ========================================================================== */
/* =====================    OVERTEMPERATURE SECTION    ====================== */
/* ========================================================================== */
/**
* \addtogroup group_sysclk_int_funcs
* \{
*/

__STATIC_INLINE void  Cy_SysClk_OverTempSetInterrupt(void);
__STATIC_INLINE void  Cy_SysClk_OverTempClearInterrupt(void);
__STATIC_INLINE bool  Cy_SysClk_OverTempGetInterruptStatus(void);
__STATIC_INLINE bool  Cy_SysClk_OverTempGetInterruptStatusMasked(void);
__STATIC_INLINE void  Cy_SysClk_OverTempSetInterruptMask(bool enable);

/*******************************************************************************
* Function Name: Cy_SysClk_OverTempSetInterrupt
****************************************************************************//**
*
* Sets interrupt for overheating issue.
* Can be used to set interrupts for firmware testing.
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \funcusage
* \snippet sysclk_snippet.c snippet_Cy_SysClk_OverTempInterrupt
*
*******************************************************************************/
__STATIC_INLINE void Cy_SysClk_OverTempSetInterrupt(void)
{
    /* Write a "1" to Set the SRSS_INTR_SET_TEMP_HIGH bit */
    SRSS_SRSS_INTR_SET = SRSSHV_SRSS_INTR_SET_TEMP_HIGH_Msk;
}

/*******************************************************************************
* Function Name: Cy_SysClk_OverTempClearInterrupt
****************************************************************************//**
*
* Clears the interrupt status.
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \funcusage
* \snippet sysclk_snippet.c snippet_Cy_SysClk_OverTempInterrupt
*
*******************************************************************************/
__STATIC_INLINE void Cy_SysClk_OverTempClearInterrupt(void)
{
    /* Write a "1" to Clear the SRSS_INTR_TEMP_HIGH bit */
    SRSS_SRSS_INTR = SRSSHV_SRSS_INTR_TEMP_HIGH_Msk;
    /* Read the interrupt register to ensure that the initial clearing write has
    * been flushed out to the hardware.
    */
    (void) SRSS_SRSS_INTR;
}

/*******************************************************************************
* Function Name: Cy_SysClk_OverTempGetInterruptStatus
****************************************************************************//**
*
* Returns the interrupt status.
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \funcusage
* \snippet sysclk_snippet.c snippet_Cy_SysClk_OverTempInterrupt
*
*******************************************************************************/
__STATIC_INLINE bool Cy_SysClk_OverTempGetInterruptStatus(void)
{
    return _FLD2BOOL(SRSSHV_SRSS_INTR_TEMP_HIGH, SRSS_SRSS_INTR);
}

/*******************************************************************************
* Function Name: Cy_SysClk_OverTempGetInterruptStatusMasked
****************************************************************************//**
*
* Returns an interrupt request register masked by an interrupt mask.
* Returns the result of the bitwise AND operation between the corresponding
* interrupt request and mask bits.
*
* \return
* The masked interrupt status.
* true  : Masked interrupt occurs.
* false : No Masked interrupt occurs.
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \funcusage
* \snippet sysclk_snippet.c snippet_Cy_SysClk_OverTempInterrupt
*
*******************************************************************************/
__STATIC_INLINE bool Cy_SysClk_OverTempGetInterruptStatusMasked(void)
{
    return _FLD2BOOL(SRSSHV_SRSS_MASKED_TEMP_HIGH, SRSS->SRSS_MASKED);
}

/*******************************************************************************
* Function Name: Cy_SysClk_OverTempSetInterruptMask
****************************************************************************//**
*
* Sets the overtemperature interrupt mask.
*
* \param enable
* - true - to masking interrupt
* - false - to reset masking interrupt
*
* \note Applicable to PSOC4 HVMS/PA only.
*
*******************************************************************************/
__STATIC_INLINE void Cy_SysClk_OverTempSetInterruptMask(bool enable)
{
    if (!enable)
    {
        SRSS_SRSS_INTR_MASK |= SRSSHV_SRSS_INTR_MASK_TEMP_HIGH_Msk;
    }
    else
    {
        SRSS_SRSS_INTR_MASK &= ~SRSSHV_SRSS_INTR_MASK_TEMP_HIGH_Msk;
    }
}
/** \} group_sysclk_int_funcs */


/* ========================================================================== */
/* ==========================    TRIM SECTION    ============================ */
/* ========================================================================== */
/**
* \addtogroup group_sysclk_trim_funcs
* \{
*/
int32_t Cy_SysClk_ImoTrim(uint32_t imoFreq, cy_en_sysclk_calib_formula_t order);
int32_t Cy_SysClk_PiloTrim(uint32_t piloFreq, cy_en_sysclk_calib_formula_t order);

/** \} group_sysclk_trim_funcs */
#endif /* CY_IP_M0S8SRSSHV */


/* ========================================================================== */
/* =========================    clk_sys SECTION    ========================== */
/* ========================================================================== */

/**
* \addtogroup group_sysclk_clk_sys_funcs
* \{
*/
__STATIC_INLINE void Cy_SysClk_ClkSysSetDivider(cy_en_sysclk_dividers_t divider);
__STATIC_INLINE cy_en_sysclk_dividers_t Cy_SysClk_ClkSysGetDivider(void);
__STATIC_INLINE uint32_t Cy_SysClk_ClkSysGetFrequency(void);


/*******************************************************************************
* Function Name: Cy_SysClk_ClkSysGetFrequency
****************************************************************************//**
*
* Reports the frequency of the SYSCLK clock.
*
* \return The frequency, in Hz.
*
* \funcusage
* \snippet sysclk_snippet.c snippet_Cy_SysClk_ClkSysSetDivider
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_SysClk_ClkSysGetFrequency(void)
{
    /* Convert the SYSCLK divider enumeration value into a natural number */
    uint32_t locDiv = 1UL << (uint32_t)Cy_SysClk_ClkSysGetDivider();
    /* Divide the SYSCLK input frequency by the SYSCLK divider */
    return (CY_SYSLIB_DIV_ROUND(Cy_SysClk_ClkHfGetFrequency(), locDiv));
}


/*******************************************************************************
* Function Name: Cy_SysClk_ClkSysSetDivider
****************************************************************************//**
*
* Sets the SYSCLK clock divider, which sources the main processor.
* The source of this divider is HFCLK.
*
* \param divider - SYSCLK divider value \ref cy_en_sysclk_dividers_t.
*
* \note
* Call \ref SystemCoreClockUpdate after this function calling.
*
* \note
* Call \ref Cy_SysLib_SetWaitStates before calling this function if
* SYSCLK frequency is increasing.
*
* \note
* Call \ref Cy_SysLib_SetWaitStates after calling this function if
* SYSCLK frequency is decreasing.
*
* \funcusage
* \snippet sysclk_snippet.c snippet_Cy_SysClk_ClkSysSetDivider
*
*******************************************************************************/
__STATIC_INLINE void Cy_SysClk_ClkSysSetDivider(cy_en_sysclk_dividers_t divider)
{
    if (CY_SYSCLK_IS_DIV_VALID(divider))
    {
#if defined (CY_IP_M0S8SRSSHV)
        /* Avoid lock register's potential race condition. */
        uint32_t intrState = Cy_SysLib_EnterCriticalSection();
        Cy_SysClk_UnlockProtReg();
#endif /* defined (CY_IP_M0S8SRSSHV) */
        CY_REG32_CLR_SET(SRSS_CLK_SELECT, SRSS_CLK_SELECT_SYSCLK_DIV, divider);
#if defined (CY_IP_M0S8SRSSHV)
        Cy_SysClk_LockProtReg();
        Cy_SysLib_ExitCriticalSection(intrState);
#endif /* defined (CY_IP_M0S8SRSSHV) */
    }
}


/*******************************************************************************
* Function Name: Cy_SysClk_ClkSysGetDivider
****************************************************************************//**
*
* Returns the SYSCLK clock divider.
*
* \return The SYSCLK divider value, \ref cy_en_sysclk_dividers_t : \n
* \ref CY_SYSCLK_NO_DIV - don't divide. \n
* \ref CY_SYSCLK_DIV_2 - divide by 2 \n
* \ref CY_SYSCLK_DIV_4 - divide by 4 \n
* \ref CY_SYSCLK_DIV_8 - divide by 8
*
* \funcusage
* \snippet sysclk_snippet.c snippet_Cy_SysClk_ClkSysSetDivider
*
*******************************************************************************/
__STATIC_INLINE cy_en_sysclk_dividers_t Cy_SysClk_ClkSysGetDivider(void)
{
    CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 10.8', 'The field values match the enumeration.');
    return ((cy_en_sysclk_dividers_t)_FLD2VAL(SRSS_CLK_SELECT_SYSCLK_DIV, SRSS_CLK_SELECT));
}
/** \} group_sysclk_clk_sys_funcs */


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
    CY_SYSCLK_DIV_8_BIT    = 0U, /**< Divider Type is an 8 bit integer divider. Note the divider of this type may be absent on some devices */
    CY_SYSCLK_DIV_16_BIT   = 1U, /**< Divider Type is a 16 bit integer divider. Note the divider of this type may be absent on some devices */
    CY_SYSCLK_DIV_16_5_BIT = 2U, /**< Divider Type is a 16.5 bit fractional divider. Note the divider of this type may be absent on some devices */
    CY_SYSCLK_DIV_24_5_BIT = 3U  /**< Divider Type is a 24.5 bit fractional divider. Note the divider of this type may be absent on some devices */
} cy_en_sysclk_divider_types_t;
/** \} group_sysclk_clk_peripheral_enums */

/** \cond */
#define cy_en_divider_types_t cy_en_sysclk_divider_types_t /* Deprecated, BWC for HAL 2.0.0 only */
/** \endcond */


/**
* \addtogroup group_sysclk_clk_peripheral_macros
* \{
*/
/** Mask and position definitions to be used with \ref Cy_SysClk_PeriphGetAssignedDivider return value. */
#define CY_SYSCLK_PERI_DIV_TYPE_Pos (PERI_DIV_CMD_SEL_TYPE_Pos) /**< The PERI divider type value position */
#define CY_SYSCLK_PERI_DIV_TYPE_Msk (PERI_DIV_CMD_SEL_TYPE_Msk) /**< The PERI divider type value mask */
#define CY_SYSCLK_PERI_DIV_NUM_Pos (PERI_DIV_CMD_SEL_DIV_Pos)  /**< The PERI divider number value position */
#define CY_SYSCLK_PERI_DIV_NUM_Msk (PERI_DIV_CMD_SEL_DIV_Msk)  /**< The PERI divider number value mask */
/** \} group_sysclk_clk_peripheral_macros */

/**
* \addtogroup group_sysclk_clk_peripheral_funcs
* \{
*/
cy_en_sysclk_status_t Cy_SysClk_PeriphSetDivider(cy_en_sysclk_divider_types_t dividerType, uint32_t dividerNum, uint32_t dividerValue);
             uint32_t Cy_SysClk_PeriphGetDivider(cy_en_sysclk_divider_types_t dividerType, uint32_t dividerNum);
cy_en_sysclk_status_t Cy_SysClk_PeriphSetFracDivider(cy_en_sysclk_divider_types_t dividerType, uint32_t dividerNum, uint32_t dividerIntValue, uint32_t dividerFracValue);
                 void Cy_SysClk_PeriphGetFracDivider(cy_en_sysclk_divider_types_t dividerType, uint32_t dividerNum, uint32_t *dividerIntValue, uint32_t *dividerFracValue);
cy_en_sysclk_status_t Cy_SysClk_PeriphAssignDivider(en_clk_dst_t periphNum, cy_en_sysclk_divider_types_t dividerType, uint32_t dividerNum);
cy_en_sysclk_status_t Cy_SysClk_PeriphEnableDivider(cy_en_sysclk_divider_types_t dividerType, uint32_t dividerNum);
cy_en_sysclk_status_t Cy_SysClk_PeriphDisableDivider(cy_en_sysclk_divider_types_t dividerType, uint32_t dividerNum);
cy_en_sysclk_status_t Cy_SysClk_PeriphEnablePhaseAlignDivider(cy_en_sysclk_divider_types_t dividerType, uint32_t dividerNum, cy_en_sysclk_divider_types_t dividerTypePA, uint32_t dividerNumPA);
                 bool Cy_SysClk_PeriphDividerIsEnabled(cy_en_sysclk_divider_types_t dividerType, uint32_t dividerNum);
             uint32_t Cy_SysClk_PeriphGetFrequency(cy_en_sysclk_divider_types_t dividerType, uint32_t dividerNum);
             uint32_t Cy_SysClk_PeriphSetFrequency(cy_en_sysclk_divider_types_t dividerType, uint32_t dividerNum, uint32_t frequency);
__STATIC_INLINE uint32_t Cy_SysClk_PeriphGetAssignedDivider(en_clk_dst_t periphNum);


/*******************************************************************************
* Function Name: Cy_SysClk_PeriphGetAssignedDivider
****************************************************************************//**
*
* Reports which clock divider is assigned to a selected IP block.
*
* \param periphNum specifies the peripheral block \ref en_clk_dst_t.
*
* \return The divider type and number, where bits [7:6] = type, bits[5:0] = divider
* number within that type
*
* \funcusage \snippet sysclk/snippet/sysclk_snippet.c SNIPPET_SYSCLK_PERI_SET_FREQ
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_SysClk_PeriphGetAssignedDivider(en_clk_dst_t periphNum)
{
    CY_ASSERT_L1(PERI_PCLK_CLOCK_NR > (uint32_t)periphNum);
    return (PERI_PCLK_CTL[periphNum] & (PERI_PCLK_CTL_SEL_DIV_Msk | PERI_PCLK_CTL_SEL_TYPE_Msk));
}

/** \} group_sysclk_clk_peripheral_funcs */


/* ========================================================================== */
/* =========================    clk_pump SECTION    ========================= */
/* ========================================================================== */
/**
* \addtogroup group_sysclk_clk_pump_enums
* \{
*/
/**
* Pump clock (clk_pump) input sources. See CLK_SELECT register, PUMP_SEL bits.
* Used with functions \ref Cy_SysClk_ClkPumpSetSource, and \ref Cy_SysClk_ClkPumpGetSource.
*/
typedef enum
{
    CY_SYSCLK_PUMP_IN_GND   = 0UL,  /**< No clock, connect to gnd */
    CY_SYSCLK_PUMP_IN_IMO   = 1UL,  /**< Use main IMO output */
    CY_SYSCLK_PUMP_IN_HFCLK = 2UL   /**< Use clk_hf (using selected source after predivider but before prescaler) */
} cy_en_sysclk_clkpump_src_t;
/** \} group_sysclk_clk_pump_enums */

/** \cond */
#define  CY_SYSCLK_IS_PUMP_SRC_VALID(src) (((src) == CY_SYSCLK_PUMP_IN_GND) || \
                                           ((src) == CY_SYSCLK_PUMP_IN_IMO) || \
                                           ((src) == CY_SYSCLK_PUMP_IN_HFCLK))
/** \endcond */

/**
* \addtogroup group_sysclk_clk_pump_funcs
* \{
*/
                     cy_en_sysclk_status_t Cy_SysClk_ClkPumpSetSource(cy_en_sysclk_clkpump_src_t source);
__STATIC_INLINE cy_en_sysclk_clkpump_src_t Cy_SysClk_ClkPumpGetSource(void);
__STATIC_INLINE                   uint32_t Cy_SysClk_ClkPumpGetFrequency(void);


/*******************************************************************************
* Function Name: Cy_SysClk_ClkPumpGetSource
****************************************************************************//**
*
* Reports the source for the pump clock (clk_pump).
*
* \return \ref cy_en_sysclk_clkpump_src_t : \n
* \ref CY_SYSCLK_PUMP_IN_GND - No clock, connect to gnd. \n
* \ref CY_SYSCLK_PUMP_IN_IMO - Use main IMO output. \n
* \ref CY_SYSCLK_PUMP_IN_HFCLK - Use clk_hf (using selected source after predivider but before prescaler).
*
* \funcusage
* \snippet sysclk_snippet.c snippet_Cy_SysClk_ClkPumpSetSource
*
*******************************************************************************/
__STATIC_INLINE cy_en_sysclk_clkpump_src_t Cy_SysClk_ClkPumpGetSource(void)
{
    CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 10.8', 'The field values match the enumeration.');
    return ((cy_en_sysclk_clkpump_src_t)_FLD2VAL(SRSS_CLK_SELECT_PUMP_SEL, SRSS_CLK_SELECT));
}


/*******************************************************************************
* Function Name: Cy_SysClk_ClkPumpGetFrequency
****************************************************************************//**
*
* Reports the frequency of the pump clock (clk_pump).
*
* \return The frequency of the pump clock in Hz.
*
* \funcusage
* \snippet sysclk_snippet.c snippet_Cy_SysClk_ClkPumpSetSource
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_SysClk_ClkPumpGetFrequency(void)
{
    uint32_t freq = 0UL;

    switch (Cy_SysClk_ClkPumpGetSource())
    {
        case CY_SYSCLK_PUMP_IN_IMO:
            freq = Cy_SysClk_ImoGetFrequency();
            break;

        case CY_SYSCLK_PUMP_IN_HFCLK:
            freq = Cy_SysClk_ClkHfGetFrequency();
            break;

        default: /* return zero for CY_SYSCLK_PUMP_IN_GND */
            break;
    }

    return (freq);
}
/** \} group_sysclk_clk_pump_funcs */

/* ========================================================================== */
/* ======================    POWER MANAGEMENT SECTION    ==================== */
/* ========================================================================== */

/**
* \addtogroup group_sysclk_pm_events
* \{
*/
#define CY_SYSCLK_ECO_TIMEOUT_EVENT (0x1UL) /**< ECO startup timeout at the waking up from Deep Sleep */
#define CY_SYSCLK_PLL_TIMEOUT_EVENT (0x2UL) /**< PLL startup timeout at the waking up from Deep Sleep */
/** \} group_sysclk_pm_events */

/**
* \addtogroup group_sysclk_pm_structs
* \{
*/

/** The type for sysclk callback */
typedef void (*cy_cb_sysclk_t) (uint32_t event);

/** The context structure type to be passed into the \ref cy_stc_syspm_callback_params_t::context.
 *  The user should not modify anything in this structure.
 *  Use \ref Cy_SysClk_RegisterCallback to register a timeout callback.
 */
typedef struct
{
/** \cond */
    cy_cb_sysclk_t callback; /*   The callback handler function
                              *   See \ref Cy_SysClk_DeepSleepCallback for details.
                              */
/** \endcond */
} cy_stc_sysclk_context_t;

/** \} group_sysclk_pm_structs */

/**
* \addtogroup group_sysclk_pm_funcs
* \{
*/
__STATIC_INLINE void Cy_SysClk_RegisterCallback(cy_cb_sysclk_t callback, cy_stc_sysclk_context_t * context);
cy_en_syspm_status_t Cy_SysClk_DeepSleepCallback(cy_stc_syspm_callback_params_t * callbackParams, cy_en_syspm_callback_mode_t mode);


/*******************************************************************************
* Function Name: Cy_SysClk_RegisterCallback
****************************************************************************//**
*
* Registers a callback function that notifies that the timeout occurred in the
* \ref Cy_SysClk_DeepSleepCallback.
*
* \param callback
* The pointer to a callback function.
* See \ref cy_cb_sysclk_t for the function prototype.
*
* \param context
* The pointer to context structure \ref cy_stc_sysclk_context_t allocated by
* the user. The user should not modify anything in this structure.
*
* \note To remove/unregister the callback, pass NULL as the pointer to the callback function.
*
* \funcusage \snippet sysclk/snippet/sysclk_snippet.c snippet_Cy_SysClk_DeepSleepCallback_prep
* \funcusage \snippet sysclk/snippet/sysclk_snippet.c snippet_Cy_SysClk_DeepSleepCallback_reg
*
*******************************************************************************/
__STATIC_INLINE void Cy_SysClk_RegisterCallback(cy_cb_sysclk_t callback, cy_stc_sysclk_context_t * context)
{
    if (NULL != context)
    {
        context->callback = callback;
    }
}

/** \} group_sysclk_pm_funcs */

#if defined(__cplusplus)
}
#endif /* __cplusplus */

#endif /* CY_SYSCLK_H */

/** \} group_sysclk */


/* [] END OF FILE */
