# ModusToolbox CAT1 BSP Template Library Release Notes

### What Changed?
#### v1.3.0
* Fixed issue where CM0P prebuilt image would enable both CM7 cores on devices which contain
* Added options for setting configuration of WL companion radio REG_ON and HOST_WAKE pins.
#### v1.2.2
* Production support for CYW20829 devices
* Updated linker scripts and startup code to align with mtb-pdl-cat1 v3.6.0
#### v1.2.1
* Added explicit include for `cycfg_pins.h` in `cybsp_hw_config.h`
* Updated linker scripts and startup code to align with mtb-pdl-cat1 v3.4.0
#### v1.2.0
* Added support for BSP Assistant chip flow
* Update MTBX dependencies to use MTB 3.0 Query APIs
#### v1.1.0
* Fix ifdef for CM0P core in cybsp.c
* Add `cybsp_hw_config.h` to fileset.
* Add pre-production support for DeepSleep-RAM warm-boot on CAT1B devices.
* Update linker scripts and startup code to align with mtb-pdl-cat1 v3.3.0
#### v1.0.0
Initial release

### Supported Software and Tools
This version of mtb-template-cat1 was validated for compatibility with the following Software and Tools:

| Software and Tools                        | Version |
| :---                                      | :----:  |
| ModusToolbox™ Software Environment        | 3.1.0   |
| GCC Compiler                              | 11.3.1  |
| IAR Compiler                              | 9.30.1  |
| ARM Compiler                              | 6.16    |

Minimum required ModusToolbox™ Software Environment: v3.0.0

### More information
* [Development Board Documentation](https://www.cypress.com/documentation/development-kitsboards)
* [Cypress Semiconductor, an Infineon Technologies Company](https://www.cypress.com)
* [Infineon GitHub](https://github.com/infineon)
* [ModusToolbox™](https://www.cypress.com/products/modustoolbox-software-environment)

---
© Cypress Semiconductor Corporation (an Infineon company) or an affiliate of Cypress Semiconductor Corporation, 2022-2023.
