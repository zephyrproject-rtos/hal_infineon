# MTB CAT1 Peripheral Driver Library v3.18.0

Please refer to the [README.md](./README.md) and the
[PDL API Reference Manual](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/index.html)
for a complete description of the Peripheral Driver Library.

## Implementation Details
* SCB I2C enhancements: added new callback events and I2C Slave Status macros, added support for the I2C Byte Received callback.

## Build Changes

## Personality Changes
* Updated Personalities (in 10.0 folder):
  * peripheral:
    * mcwdt_v2-1.0.cypersonality
    * mcwdt-3.0.cypersonality
    * uart-3.0.cypersonality
  * platform:
    * axidmac-1.0.cypersonality

## Added Drivers

## Updated Drivers
* [SCB 3.40](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/group__group__scb.html)

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
* axidmac-1.0.cypersonality - fixed macros code generation for the TRAVEO™ T2G devices.
* uart-3.0.cypersonality - fixed code generation error for the TRAVEO™ T2G devices.
* Fixed address handling in the SCB EZI2C driver.

See the Changelog section of each Driver in the [PDL API Reference](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/modules.html) for all fixes and updates.


## Supported Software and Tools

This version of PDL was validated for compatibility with the following Software and Tools:

| Software and Tools                                                            | Version      |
| :---                                                                          | :----        |
| [Infineon Core Library](https://github.com/Infineon/core-lib)                 | 1.4.4        |
| CMSIS                                                                         | 5.8.2        |
| GCC Compiler                                                                  | 14.2.1       |
| IAR Compiler                                                                  | 9.50.2       |
| ARM Compiler 6                                                                | 6.22         |
| FreeRTOS                                                                      | 10.4.305     |
| [Device Database](https://github.com/Infineon/device-db)                      | 4.26.0       |

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
