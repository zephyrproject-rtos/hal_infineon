# ModusToolbox PSE8XXGP BSP Template Library

## Overview

mtb-template-pse8xxgp provides BSP template files for the BSP Assistant tool. mtb-template-pse8xxgp contains files for the PSOC EDGE family

## BSP Configuration

The BSP has a few hooks that allow its behavior to be configured. Some of these items are enabled by default while others must be explicitly enabled. Items enabled by default are specified in the {{ name }}.mk file. The items that are enabled can be changed by creating a custom BSP or by editing the application makefile.

Components:
* HCI-UART - The UART HCI mode used by bluetooth-freertos

Defines:
* CYBSP_WIFI_CAPABLE - This define, disabled by default, causes the BSP to initialize the interface to an onboard wireless chip if it has one.


## More information
* [Development Board Documentation](https://www.cypress.com/documentation/development-kitsboards)
* [Cypress Semiconductor, an Infineon Technologies Company](https://www.cypress.com)
* [Infineon GitHub](https://github.com/infineon)
* [ModusToolbox™](https://www.cypress.com/products/modustoolbox-software-environment)

---
© Cypress Semiconductor Corporation (an Infineon company) or an affiliate of Cypress Semiconductor Corporation, 2022-2025.
