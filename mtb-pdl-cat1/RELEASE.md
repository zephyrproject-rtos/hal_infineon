# MTB CAT1 Peripheral Driver Library v3.16.0

Please refer to the [README.md](./README.md) and the
[PDL API Reference Manual](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/index.html)
for a complete description of the Peripheral Driver Library.


## Implementation Details
* CAT1B: Added support for ED25519 DSA and EC25519 ECDH for CYW20829 device
* Personality re-structuring: Personality supporting Schema v10 added. Personalities_10.0 is a copy of ‘personalities_9.0’ with needed personalities updated to use schema v10. These personalities are available in folder device-info/personalities_10.0. Personalities supporting schema v10 are visible in MTB 3.4. For backward compatibility with MTB 3.3, this release will also have older personalities in folder device-info/personalities.

## Build Changes

## Personality Changes in personalities_10:

Newly added personalities: 
* hppass_sar_seq_grp-2.0.cypersonality, 
 
Updated personalities: 
* Hppass: hppass_sar_chan-1.0.cypersonality, hppass_sar_limit-1.0.cypersonality, hppass_sar_seq_grp-1.0.cypersonality,        hppass_sar-1.0.cypersonality.

* Peripheral: connectivity_bt_intrinsic-1.0.cypersonality, connectivity_bt-1.0.cypersonality, connectivity_wifi-1.0.cypersonality, counter_v2-1.0.cypersonality, counter-1.0.cypersonality, emusb_v2-1.0.cypersonality, eth-1.0.cypersonality, 
lpcomp-3.0.cypersonality, motif_mcp_quaddec-1.0.cypersonality, pdm_pcm_v2-4.0.cypersonality, pwm_v2-1.0.cypersonality,
pwm-1.0.cypersonality, quaddec_v2-1.0.cypersonality, sd_host-1.0.cypersonality, smif_core-1.0.cypersonality, smif_v2-1.0.cypersonality, spi-3.0.cypersonality, uart-3.0.cypersonality.

* Platform: axidmac-1.0.cypersonality, debug-2.0.cypersonality, dmac-1.0.cypersonality, dmac-2.0.cypersonality, em_eeprom-2.1.cypersonality, hfclk_v2-1.0.cypersonality, hfclk-3.0.cypersonality, lfclk-3.0.cypersonality, pll250-1.0.cypersonality, sysclock-3.0.cypersonality, tickclk-3.0.cypersonality.


## Added Drivers

## Updated Drivers
* [CORDIC 2.10](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/group__group__cordic.html)
* [CRYPTO 2.150](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/group__group__crypto.html)
* [CRYPTOLITE 2.80](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/group__group__cryptolite.html)
* [GPIO 1.140](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/group__group__gpio.html)
* [FLASH 3.130](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/group__group__flash.html)
* [HPPASS 1.30](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/group__group__hppass.html)
* [IPC 1.140](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/group__group__ipc.html)
* [MPC 1.10](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/group__group__mpc.html)
* [MSCTL 1.20](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/group__group__ms__ctl.html)
* [SCB 3.30](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/group__group__scb.html)
* [SYSCLK 3.140](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/group__group__sysclk.html)
* [SYSLIB 3.80](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/group__group__syslib.html)
* [SYSPM 5.180](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/group__group__syspm.html)
* [SD HOST 2.40](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/group__group__sd__host.html)
* [SMIF 2.130](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/group__group__smif.html)
* [SMARTIO 1.0.4](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/group__group__smartio.html)



### Drivers with patch version updates


### Obsoleted part numbers


## Known Issues

* Traveo II C-2D-6M: Some Fault numbers defined in cy_en_SysFault_source_t for CAT1C do not match the device fault numbers.
* CAT1A: In device-configurator, certain IP is not completely available for some devices as some combinations of pin connections are not valid.
  * CYT2BL4BAS/CYT2BL4CAE: SCB6 is complete only for UART, cannot support I2C, EZI2C, or SPI.
  * CYT2BL3CAE, CYT2B7CAE: SCB1 is complete only for UART, cannot support I2C, EZI2C, or SPI.
  * On the following devices: CAN FD 0 Channel 3, CAN FD 1 Channel 1, CAN FD 1 Channel 3 is not available (no signal for CAN Rx Pin available).
    * CYT2BL4BAS, CYT2BL3CAE, CYT2BL3CAS, CYT2BL4CAE, CYT2BL3BAE, CYT2BL4BAE, CYT2BL4CAS, CYT2BL3BAS, CYT2B73BAS, CYT2B73CAS, CYT2B73BAE
* Traveo II B-E: Does not support emulated eeprom.
* CAT1A: On soft reset, user need to reset back up domain using Cy_SysLib_ResetBackupDomain() to receive Cy_RTC_CenturyInterrupt() callback on Century roll over.
* On building with tools 2.2, user get warning related to the older version of tools used. To avoid this warning, user is advised to migrate to newer tools version or keep working with previous version of this library.  The warning generated is as follows:
  * _#warning "(Library) The referenced 'device support library' contains newer content than is supported. Either downgrade the version of the 'device support library' referenced or upgrade the version of tools being used_
* Design configuration will not be auto migrated from smartio-3.0.cypersonality to smartio-4.0.cypersonality. So, existing projects should use smartio-3.0.cypersonality. New projects can make use of smartio-4.0.cypersonality which includes additional improvements.
* PSOC C3:
*   Overriding Cy_SysLib_ProcessingFault() function in the Non-Secure application does not work.
*   DFU flow: P2_3 is not configurable in the Non-secure application. The workaround: Do not configure/use P2_3 in the design when moved to Non-Secure Trustzone.
*   The Serial Trace feature is not available on the PSOC C3.
*   The application may fault when it was configured to start from RAM.
*   There is a hardware issue related to HRPWM activation on TCPWM block. The workaround for the PSOC C3 device with HRPWM feature available is described in the Cy_TCPWM_PWM_Init() documentation. The device-configurator will generate appropriate code for TCPWM to activate HRPWM on the device on which this feature is available.
*   When the core is clocked from the FLL the device might goes to HardFault. The flash wait states are calculated for the best performance and accurate Core clock. The recommendation is to avoid clocking the core from the FLL clock.
*   Flash refresh feature is not working.


## Defect Fixes

See the Changelog section of each Driver in the [PDL API Reference](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/modules.html) for all fixes and updates.


## Supported Software and Tools

This version of PDL was validated for compatibility with the following Software and Tools:

| Software and Tools                                                            | Version      |
| :---                                                                          | :----        |
| [Infineon Core Library](https://github.com/Infineon/core-lib)                 | 1.4.3        |
| CMSIS                                                                         | 5.8.2        |
| GCC Compiler                                                                  | 11.3.1       |
| IAR Compiler                                                                  | 9.50.2       |
| ARM Compiler 6                                                                | 6.22         |
| FreeRTOS                                                                      | 10.4.305     |
| [Device Database](https://github.com/Infineon/device-db)                      | 4.22.0       |

## More information

* [Peripheral Driver Library README.md](./README.md)
* [Peripheral Driver Library API Reference Manual](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/index.html)
* [ModusToolbox Software Environment, Quick Start Guide, Documentation, and Videos](https://www.infineon.com/cms/en/design-support/tools/sdk/modustoolbox-software/)
* [ModusToolbox Device Configurator Tool Guide](https://www.infineon.com/dgdl/Infineon-ModusToolbox_Device_Configurator_Guide_4-UserManual-v01_00-EN.pdf?fileId=8ac78c8c7d718a49017d99ab297631cb)
* [AN210781 Getting Started with PSOC 6 MCU with Bluetooth Low Energy (BLE) Connectivity](https://www.infineon.com/dgdl/Infineon-AN210781_Getting_Started_with_PSoC_6_MCU_with_Bluetooth_Low_Energy_(BLE)_Connectivity_on_PSoC_Creator-ApplicationNotes-v05_00-EN.pdf?fileId=8ac78c8c7cdc391c017d0d311f536528)
* [PSOC 6](https://www.infineon.com/cms/en/product/microcontroller/32-bit-psoc-arm-cortex-microcontroller/psoc-6-32-bit-arm-cortex-m4-mcu/)
* [CYW20829](https://www.infineon.com/cms/en/product/promopages/airoc20829)
* [TV-II-BH8/BH4](https://www.infineon.com/cms/en/product/microcontroller/32-bit-traveo-t2g-arm-cortex-microcontroller/)
* [TV-II-BE4/BE2/BE1/BE512K](https://www.infineon.com/cms/en/product/microcontroller/32-bit-traveo-t2g-arm-cortex-microcontroller/)
* [TV-II-C-2D-6M](https://www.infineon.com/cms/en/product/microcontroller/32-bit-traveo-t2g-arm-cortex-microcontroller/32-bit-traveo-t2g-arm-cortex-for-cluster/)
* [XMC7000](https://www.infineon.com/cms/en/product/microcontroller/32-bit-industrial-microcontroller-based-on-arm-cortex-m/32-bit-xmc7000-industrial-microcontroller-arm-cortex-m7/)
* [Infineon](http://www.infineon.com)


---
© Cypress Semiconductor Corporation (an Infineon company), 2020-2025.
