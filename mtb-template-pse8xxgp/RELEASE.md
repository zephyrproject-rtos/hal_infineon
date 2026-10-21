# ModusToolbox PSE8XXGP BSP Template Library Release Notes

### What Changed?
#### v1.2.0
* Renamed functions to move core name before command ( e.g. Cy_SysEnableCM55 -> Cy_SysCM55Enable ). The old names are retained as aliases for compatibility.
* Added setting of debug port policy for Cy_SysCM55Enable
* In Cy_SysU55Enable, wait until the PPU disablement has propagated before de-initializing the corresponding Peri group slave.
#### v1.1.0
Minor bug-fixes
#### v1.0.0
Initial release

### Supported Software and Tools
This version of mtb-template-pse8xxgp was validated for compatibility with the following Software and Tools:

| Software and Tools                        | Version |
| :---                                      | :----:  |
| ModusToolbox™ Software Environment        | 3.5.0   |
| GCC Compiler                              | 11.3    |
| IAR Compiler                              | 9.50    |
| ARM Compiler                              | 6.22    |

Minimum required ModusToolbox™ Software Environment: v3.5.0

### More information
* [Development Board Documentation](https://www.cypress.com/documentation/development-kitsboards)
* [Cypress Semiconductor, an Infineon Technologies Company](https://www.cypress.com)
* [Infineon GitHub](https://github.com/infineon)
* [ModusToolbox™](https://www.cypress.com/products/modustoolbox-software-environment)

---
© Cypress Semiconductor Corporation (an Infineon company) or an affiliate of Cypress Semiconductor Corporation, 2022-2025.
