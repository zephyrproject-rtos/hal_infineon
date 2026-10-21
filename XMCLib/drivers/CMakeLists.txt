# SPDX-License-Identifier: Apache-2.0
#
# Copyright (c) 2020 Linumiz
# Author: Parthiban Nallathambi <parthiban@linumiz.com>

if(CONFIG_CPU_CORTEX_M4)
  zephyr_compile_definitions( -DCORE_CM4 )
endif()

zephyr_include_directories(inc)

# TODO: conditional include for PIO & SCU after zephyr support
zephyr_sources(src/xmc_usic.c)
zephyr_sources(src/xmc4_scu.c)
zephyr_sources(src/xmc_gpio.c)
zephyr_sources(src/xmc4_gpio.c)
zephyr_sources_ifdef(CONFIG_HAS_XMCLIB_UART src/xmc_uart.c)
zephyr_sources_ifdef(CONFIG_HAS_XMCLIB_ERU  src/xmc_eru.c src/xmc4_eru.c)
zephyr_sources_ifdef(CONFIG_HAS_XMCLIB_ACMP  src/xmc_acmp.c)
zephyr_sources_ifdef(CONFIG_HAS_XMCLIB_CAN  src/xmc_can.c)
zephyr_sources_ifdef(CONFIG_HAS_XMCLIB_CCU src/xmc_ccu4.c src/xmc_ccu8.c)
zephyr_sources_ifdef(CONFIG_HAS_XMCLIB_DAC  src/xmc_dac.c)
zephyr_sources_ifdef(CONFIG_HAS_XMCLIB_DMA src/xmc_dma.c)
zephyr_sources_ifdef(CONFIG_HAS_XMCLIB_DSD  src/xmc_dsd.c)
zephyr_sources_ifdef(CONFIG_HAS_XMCLIB_EBU  src/xmc_ebu.c)
zephyr_sources_ifdef(CONFIG_HAS_XMCLIB_ECAT  src/xmc_ecat.c)
zephyr_sources_ifdef(CONFIG_HAS_XMCLIB_ETH  src/xmc_eth_mac.c)
zephyr_sources_ifdef(CONFIG_HAS_XMCLIB_ETH_PHY_DP83848  src/xmc_eth_phy_dp83848.c)
zephyr_sources_ifdef(CONFIG_HAS_XMCLIB_ETH_PHY_KSZ8031RNL src/xmc_eth_phy_ksz8031rnl.c)
zephyr_sources_ifdef(CONFIG_HAS_XMCLIB_ETH_PHY_KSZ8081RNB src/xmc_eth_phy_ksz8081rnb.c)
zephyr_sources_ifdef(CONFIG_HAS_XMCLIB_FCE src/xmc_fce.c)
zephyr_sources_ifdef(CONFIG_HAS_XMCLIB_FLASH  src/xmc4_flash.c)
zephyr_sources_ifdef(CONFIG_HAS_XMCLIB_I2C  src/xmc_i2c.c)
zephyr_sources_ifdef(CONFIG_HAS_XMCLIB_I2S src/xmc_i2s.c)
zephyr_sources_ifdef(CONFIG_HAS_XMCLIB_LEDTS src/xmc_ledts.c)
zephyr_sources_ifdef(CONFIG_HAS_XMCLIB_POSIF src/xmc_posif.c)
zephyr_sources_ifdef(CONFIG_HAS_XMCLIB_PRNG src/xmc_prng.c)
zephyr_sources_ifdef(CONFIG_HAS_XMCLIB_RTC  src/xmc_rtc.c src/xmc4_rtc.c)
zephyr_sources_ifdef(CONFIG_HAS_XMCLIB_SDMMC src/xmc_sdmmc.c)
zephyr_sources_ifdef(CONFIG_HAS_XMCLIB_SPI  src/xmc_spi.c)
zephyr_sources_ifdef(CONFIG_HAS_XMCLIB_USBD src/xmc_usbd.c)
zephyr_sources_ifdef(CONFIG_HAS_XMCLIB_USBH src/xmc_usbh.c)
zephyr_sources_ifdef(CONFIG_HAS_XMCLIB_VADC src/xmc_vadc.c)
zephyr_sources_ifdef(CONFIG_HAS_XMCLIB_WDT src/xmc_wdt.c)
