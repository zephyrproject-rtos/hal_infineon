# Wi-Fi Host Driver Expansion (WHDE)

### Overview
The WHDE is an independent, embedded Wi-Fi Host Driver that provides a set of APIs to interact with Infineon WLAN chips. The WHDE is an independent firmware product that is easily portable to any embedded software environment, including popular IoT frameworks such as Zephyr and FreeRTOS on three party platform. Therefore, the WHDE includes hooks for RTOS and TCP/IP network abstraction layers.

The [release notes](./RELEASE.md) detail the current release. You can also find information about previous versions.

### WIFI6

### Supported RTOS
----------------------------------
|     RTOS     |55500|55900|55572|
|:------------:|:---:|:---:|:---:|
|  FreeRTOS    |  O  |     |     | 
|  Zephyr      |  O  |     |     |

### Supported platform
----------------------------------
|   Platform   |55500|55900|55572|
|:------------:|:---:|:---:|:---:|
|  IMXRT1170-A |  O  |     |     | 
|              |     |     |     |

### Supported bus interface
----------------------------------
|  Interface   |55500|55900|55572|
|:------------:|:---:|:---:|:---:|
|  SDIO        |  O  |     |     | 
|  SPI         |     |     |     |
|  M2M         |     |     |     |
|  OCI         |     |     |     |

### AP mode support 
----------------------------------
|   Security   |55500|55900|55572|
|:------------:|:---:|:---:|:---:|
|  WPA3        |     |     |     |
|  WPA2        |  O  |     |     |

### More information
* [Wi-Fi Host Driver API Reference Manual and Porting Guide](https://infineon.github.io/wifi-host-driver/html/index.html)
* [Wi-Fi Host Driver Release Notes](./RELEASE.md)
* [Infineon Technologies](http://www.infineon.com)

---
