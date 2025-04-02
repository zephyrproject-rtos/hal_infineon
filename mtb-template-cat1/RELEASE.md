# ModusToolbox CAT1 BSP Template Library Release Notes

### What Changed?
#### v1.7.1
* Fix compilation error in cybsp_init when HAL is not present for CAT1A/CAT1C devices.
#### v1.7.0
* Add support for PSOC Control C3 devices.
* Remove incorrect HAL dependency for Traveo II C-2D-6M devices.
* Increment BSP generation number to 5 for CAT1A and CAT1B to
  reflect that BSPs created using this template version provide
  equivalent functionality to the generation 5 kit BSPs.
#### v1.6.1
* Production support for FX2G3,FX3G2 devices. Bugfix for PSOC6 Frequencies
#### v1.6.0
* Production support for Traveo II C-2D-6M devices.
#### v1.5.0
* Production support for CYT2B6 and CYT2B9 devices
* Fixed missing file issue when using CYT2B7 devices with BSP assistant
* Removed redundant CM0P component selections for PSoC™ 64 devices.
* Update linker scripts and startup code to align with PDL 3.10.0 release.
* Apply changes from 1.3.1 on top of 1.4.0
#### v1.4.0
* Production support for Traveo II Body Entry devices.
#### v1.3.1
* Enabled Configuration of FLL,PLL,Systick,Timer clocks by default for CAT1A devices.
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
| GCC Compiler                              | 12.2.1  |
| IAR Compiler                              | 9.40.2  |
| ARM Compiler                              | 6.16    |

Minimum required ModusToolbox™ Software Environment: v3.0.0

### More information
* [Development Board Documentation](https://www.cypress.com/documentation/development-kitsboards)
* [Cypress Semiconductor, an Infineon Technologies Company](https://www.cypress.com)
* [Infineon GitHub](https://github.com/infineon)
* [ModusToolbox™](https://www.cypress.com/products/modustoolbox-software-environment)

---
© Cypress Semiconductor Corporation (an Infineon company) or an affiliate of Cypress Semiconductor Corporation, 2022-2023.
