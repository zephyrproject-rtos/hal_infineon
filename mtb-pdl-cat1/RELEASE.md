# MTB CAT1 Peripheral Driver Library v3.4.0

Please refer to the [README.md](./README.md) and the
[PDL API Reference Manual](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/index.html)
for a complete description of the Peripheral Driver Library.

Some restrictions apply to the PSoC 64 devices configuration. Please refer to [PRA (Protected Register Access)](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/group__group__pra.html) driver documentation for the details.

## Implementation Details

* Cryptolite Support for ECDSA verify for HASHZERO message added.
* CAT1C:Enabled wait-states API.
* Glitch filter support added for TCPWM version 3 and above.
* CAT1A: Added new 80-m-csp package mpns in PSoC 6-256K family. MPNs starting with CY8C6144FMI, CY8C6244FMI.

## Build Changes

## Personalities Changes
* Added Personalities : smartio-4.0.cypersonality
* Updated Personalities : bakclk-3.0.cypersonality, timerclk-3.0.cypersonality, tickclk-3.0.cypersonality, sysclock-3.0.cypersonality, power_v3-1.0.cypersonality, power_v2-1.0.cypersonality, pin-3.0.cypersonality, pclk_v2-1.0.cypersonality,
  mfclk-3.0.cypersonality, hfclk-3.0.cypersonality, hfclk_v2-1.0.cypersonality, eco-3.0.cypersonality, uart-3.0.cypersonality, tdm-1.1.cypersonality, smif_v2-1.0.cypersonality, smartio-3.0.cypersonality, sd_host-1.0.cypersonality, pwm_v2-1.0.cypersonality, pdm_pcm_v2-3.0.cypersonality, mcwdt-3.0.cypersonality, i2c-4.0.cypersonality, canfd-3.0.cypersonality

## Added Drivers

## Updated Drivers

* [CANFD 1.40](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/group__group__canfd.html)
* [CRYPTO 2.90](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/group__group__crypto.html)
* [CRYPTOLITE 2.30](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/group__group__cryptolite.html)
* [DMA 2.70](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/group__group__dma.html)
* [GPIO 1.90](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/group__group__gpio.html)
* [IPC 1.91](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/group__group__ipc.html)
* [LPCOMP 1.60](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/group__group__lpcomp.html)
* [SMIF 2.60](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/group__group__smif.html)
* [SYSCLK 3.70](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/group__group__sysclk.html)
* [SYSFAULT 1.20](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/group__group__sysfault.html)
* [SYSLIB 3.40](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/group__group__syslib.html)
* [SYSPM 5.94](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/group__group__syspm.html)
* [TCPWM 1.60](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/group__group__tcpwm.html)

### Drivers with patch version updates

* [ETHIF 1.10.1](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/group__group__ephy.html)
* [PRA 2.40.1](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/group__group__pra.html)
* [SMARTIO 1.0.3](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/group__group__smartio.html)
* [SYSINT 1.90.1](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/group__group__sysint.html)
* [SYSTICK 1.70.1](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/group__group__arm__system__timer.html)
* [TRIGMUX 1.60.1](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/group__group__trigmux.html)
### Obsoleted part numbers

The ModusToolbox Device Configurator can not create the designs targeting the obsolete PSoC 6 part numbers.

Below is a list of PSoC 6 part numbers obsoleted in psoc6pdl release-v1.6.0, with the suggested next best alternative:

| Obsoleted part number | Next best alternative |
| :---                  | :----                 |
| CY8C624AAZI-D44       | CY8C624AAZI-S2D44     |
| CY8C624AFNI-D43       | CY8C624AFNI-S2D43     |
| CY8C624ABZI-D04       | CY8C624ABZI-S2D04     |
| CY8C624ABZI-D14       | CY8C624ABZI-S2D14     |
| CY8C624AAZI-D14       | CY8C624AAZI-S2D14     |
| CY8C6248AZI-D14       | CY8C6248AZI-S2D14     |
| CY8C6248BZI-D44       | CY8C6248BZI-S2D44     |
| CY8C6248AZI-D44       | CY8C6248AZI-S2D44     |
| CY8C6248FNI-D43       | CY8C6248FNI-S2D43     |
| CY8C624ALQI-D42       | N/A                   |

## Known Issues
* CAT1A: On soft reset, user need to reset back up domain using Cy_SysLib_ResetBackupDomain() to receive Cy_RTC_CenturyInterrupt() callback on Century roll over.
* On building with tools 2.2, user get warning related to the older version of tools used. To avoid this warning, user is advised to migrate to newer tools version or keep working with previous version of this library.  The warning generated is as follows:
  * _#warning "(Library) The referenced 'device support library' contains newer content than is supported. Either downgrade the version of the 'device support library' referenced or upgrade the version of tools being used_
* Design configuration will not be auto migrated from smartio-3.0.cypersonality to smartio-4.0.cypersonality. So, existing projects should use smartio-3.0.cypersonality. New projects can make use of smartio-4.0.cypersonality which includes additional improvements.
* CAT1C: This release does not support D-CACHE on CAT1C platform


## Defect Fixes

See the Changelog section of each Driver in the [PDL API Reference](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/modules.html) for all fixes and updates.

## Supported Software and Tools

This version of PDL was validated for compatibility with the following Software and Tools:

| Software and Tools                                                            | Version      |
| :---                                                                          | :----        |
| [Infineon Core Library](https://github.com/Infineon/core-lib)                 | 1.3.0        |
| [Infineon HAL](https://github.com/Infineon/mtb-hal-cat1)                      | 2.4.0        |
| CMSIS                                                                         | 5.8.0        |
| GCC Compiler                                                                  | 11.3.1       |
| IAR Compiler                                                                  | 9.3          |
| ARM Compiler 6                                                                | 6.16         |
| FreeRTOS                                                                      | 10.4.305     |

## More information

* [Peripheral Driver Library README.md](./README.md)
* [Peripheral Driver Library API Reference Manual](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/index.html)
* [ModusToolbox Software Environment, Quick Start Guide, Documentation, and Videos](https://www.infineon.com/cms/en/design-support/tools/sdk/modustoolbox-software/)
* [ModusToolbox Device Configurator Tool Guide](https://www.infineon.com/dgdl/Infineon-ModusToolbox_Device_Configurator_Guide_4-UserManual-v01_00-EN.pdf?fileId=8ac78c8c7d718a49017d99ab297631cb)
* [AN210781 Getting Started with PSoC 6 MCU with Bluetooth Low Energy (BLE) Connectivity](https://www.infineon.com/dgdl/Infineon-AN210781_Getting_Started_with_PSoC_6_MCU_with_Bluetooth_Low_Energy_(BLE)_Connectivity_on_PSoC_Creator-ApplicationNotes-v05_00-EN.pdf?fileId=8ac78c8c7cdc391c017d0d311f536528)
* [PSoC 6](https://www.infineon.com/cms/en/product/microcontroller/32-bit-psoc-arm-cortex-microcontroller/psoc-6-32-bit-arm-cortex-m4-mcu/)
* [CYW20829](https://www.infineon.com/cms/en/product/promopages/airoc20829)
* [TV-II-BH8/BH4](https://www.infineon.com/cms/en/product/microcontroller/32-bit-traveo-t2g-arm-cortex-microcontroller/)
* [XMC7000](https://www.infineon.com/cms/en/product/microcontroller/32-bit-industrial-microcontroller-based-on-arm-cortex-m/32-bit-xmc7000-industrial-microcontroller-arm-cortex-m7/)
* [Infineon](http://www.infineon.com)


---
© Cypress Semiconductor Corporation (an Infineon company), 2023.
