# ModusToolbox™ PSC3M8 Device Support Library 1.2.0
## What's Included?

Refer to the [README.md](./README.md) for a complete description of the ModusToolbox™ PSC3M8 Device Support Library.

## Change log

### v1.2.0
#### Drivers Update
* CORDIC: Added inverse-sine, inverse-cosine and circular square-root operations, and broadened the documented circular-angle support:
   - `Cy_CORDIC_ArcSin()`,
   - `Cy_CORDIC_ArcCos()`,
   - `Cy_CORDIC_Sqrt_Circular()`.
* TCPWM: Added custom PWM alignment support with new configuration fields and APIs for count direction, initial count and compare/overflow/underflow output actions. New API:
   - `Cy_TCPWM_PWM_CNT_SetCountDirectionMode()`,
   - `Cy_TCPWM_PWM_CNT_SetCC0MatchAction()`,
   - `Cy_TCPWM_PWM_CNT_SetCC1MatchAction()`,
   - `Cy_TCPWM_PWM_CNT_SetOverflowAction()`,
   - `Cy_TCPWM_PWM_CNT_SetUnderflowAction()`.
* PPCA: Added ADC channel-sign queries, calibration, offset, gain and test-mode controls, the DCMP source-channel accessor. New API:
   - `Cy_PPCA_ADC_Get_Gain_Setting()`,
   - `Cy_PPCA_ADC_Is_Test_Mode_Enabled()`,
   - `Cy_PPCA_ADC_Is_Channel_Signed()`,
   - `Cy_PPCA_ADC_Is_Aux_Channel_Signed()`,
   - `Cy_PPCA_ADC_Is_Alt_Aux_Channel_Signed()`,
   - `Cy_PPCA_ADC_Set_Gain_Correction()`,
   - `Cy_PPCA_ADC_Get_Gain_Correction()`,
   - `Cy_PPCA_ADC_Set_Offset()`,
   - `Cy_PPCA_ADC_Get_Offset()`,
   - `Cy_PPCA_DCMP_Get_Source_Channel()`.
* PPCA: Added HWFILT3P3Z register readback and full configuration getters for save-and-restore use cases:
   - `Cy_PPCA_HWFILT3P3Z_GetCoefficients()`,
   - `Cy_PPCA_HWFILT3P3Z_GetOffset()`,
   - `Cy_PPCA_HWFILT3P3Z_GetFilterOutLimits()`,
   - `Cy_PPCA_HWFILT3P3Z_GetCoefficientScaleFactors()`,
   - `Cy_PPCA_HWFILT3P3Z_GetGains()`,
   - `Cy_PPCA_HWFILT3P3Z_GetFilterProcessing()`,
   - `Cy_PPCA_HWFILT3P3Z_GetFilterEnable()`,
   - `Cy_PPCA_HWFILT3P3Z_SS_GetPeripheralEnable()`,
   - `Cy_PPCA_HWFILT3P3Z_GetFilterConfig()`.
* SCB (I2C): Documented the master state reported by `Cy_SCB_I2C_MasterAbortWrite()` for all FIFO and pending-transfer combinations.

#### Personality Changes
* PWM: Added HRPWM micro-tick controls for period, compare and dead-time values and packed them into the generated register values.
* PWM, Counter: Raised the supported calculated counter and PWM rate limits to 500 MHz, and corrected custom-waveform timing to include the encoded count's extra clock cycle.
* PWM: Consolidated the mode-specific waveform diagrams into a single parameterized visualization.
* TCPWM: Corrected the dead-time visualization and HRPWM guidance.
* PPCA: Added generation of the EPU feedback-combiner initialization.
* pclk_v2: Validated each active PPCA peripheral-clock group against its actual resolved source clock, with the DRC and Fix-It naming and enabling the clock that truly supplies the group.
#### Defect Fixes
* CryptoLite: ECC25519 private-key generation now reports success only after the underlying operation succeeds, preserving RNG and hardware error status.
* GPIO: Corrected the drive-mode assertion condition.
* TCPWM: Corrected initialization to use the current count direction and up-count value, fixed center-aligned period validation for the doubled counter range, and bounded glitch-filter trigger setup per group.
* PPCA: Corrected the EPU synchronous and asynchronous bypass enumeration values to match the hardware encoding.
* PPCA: Exposed ADC channel 7 datapath selection in manual and arbitrary-trigger modes when the selected input path supports it.
* PPCA: Removed odd ADC filter source channels from the selectable list when the paired even channel is configured as differential.
* PPCA: Represented unassigned ADC sequence positions with the hardware sentinel value and added a validation error when a visible slot remains unassigned.
* PPCA: Limited ADC sequence-position visibility and editing to the configured number of slots.
* PPCA: Kept PUT2 input selection visible while the processing unit is disabled and corrected the input description.
* PPCA: Constrained the CLB scan-pattern hold time to the 8-bit hardware limit of 255.
* PPCA: Changed `Cy_PPCA_CLB_Select_Output()` to a read-modify-write that preserves the CLB enable state.
* PPCA: Added a Device Configurator validation error when the PPCA HF3 source exceeds its supported 200 MHz maximum.
* SysPm: Corrected boot-mode reset-cause evaluation so warm or cold boot is classified only when both disjoint reset-cause registers are zero.
* SysLib: Masked unrelated BOOTROW bits from lifecycle-state reporting.

### v1.1.0
* HAL: Fixed issue in SPI data transfer

### v1.0.0
* Initial release

## Supported Software and Tools

This version of the ModusToolbox™ PSC3M8 Device Support Library 1.0.0 was validated for the compatibility with the following Software and Tools:

| Software and Tools                                                            | Version      |
| :---                                                                          | :----        |
| ModusToolbox™                                                                 | 3.9          |
| [Infineon Core Library](https://github.com/Infineon/core-lib)                 | 1.8.0        |
| CMSIS                                                                         | 6.1.0        |
| GCC Compiler                                                                  | 14.2.1       |
| IAR Compiler                                                                  | 9.70.4       |
| ARM Compiler 6                                                                | 6.22         |
| FreeRTOS                                                                      | 10.6.202     |


## More information

For more information, refer to the following documents:

* [Infineon Technologies AG](https://www.infineon.com)

---
© 2026, Cypress Semiconductor Corporation (an Infineon company) or an affiliate of Cypress Semiconductor Corporation.