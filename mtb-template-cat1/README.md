# ModusToolbox CAT1 BSP Template Library

## Overview

mtb-template-cat1 provides BSP template files for the BSP Assistant tool. mtb-template-cat1 contains files for the following devices:

* CY8C6xxx
* CYB06xxx
* CYS06xxx
* CYT2Bxx
* XMC71xx
* XMC72xx
* CYT4DNx

## BSP Configuration

The BSP has a few hooks that allow its behavior to be configured. Some of these items are enabled by default while others must be explicitly enabled. Items enabled by default are specified in the {{ name }}.mk file. The items that are enabled can be changed by creating a custom BSP or by editing the application makefile.

Components:
* CM0P_SLEEP - Cortex-M0+ pre-built image to start the CM4 or CM7_0 core.
* DUAL_CM0P_SLEEP - Cortex-M0+ pre-built image to start both cores in dual core CM7 applications.
* CM0P_CRYPTO - Cortex-M0+ pre-built image to start the CM4 and perform cryptographic operations.
* CM0P_BLESS - Cortex-M0+ pre-built image to start the CM4 and perform BLE operations.
* CM0P_SECURE - Cortex-M0+ pre-built image for PSoC 64.
* UDB_SDIO - Adds SDIO support for devices that do not have a native SDIO block (PSoC 61, PSoC 62, PSoC 64)
* HCI-UART - The UART HCI mode used by bluetooth-freertos
* HCI-SHAREDBUS - The Shared Bus HCI mode used by bluetooth-freertos

Defines:
* CYBSP_WIFI_CAPABLE - This define, disabled by default, causes the BSP to initialize the interface to an onboard wireless chip if it has one.
* CY_USING_HAL - This define, enabled by default, specifies that the HAL is intended to be used by the application. This will cause the BSP to include the applicable header file and to initialize the system level drivers.
* CYHAL_UDB_SIO - Enables UDB_SDIO component


## More information
* [Development Board Documentation](https://www.cypress.com/documentation/development-kitsboards)
* [Cypress Semiconductor, an Infineon Technologies Company](https://www.cypress.com)
* [Infineon GitHub](https://github.com/infineon)
* [ModusToolbox™](https://www.cypress.com/products/modustoolbox-software-environment)

---
© Cypress Semiconductor Corporation (an Infineon company) or an affiliate of Cypress Semiconductor Corporation, 2022-2024.
