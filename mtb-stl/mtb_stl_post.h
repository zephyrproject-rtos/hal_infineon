#ifndef MTB_STL_POST_H
#define MTB_STL_POST_H

/*                                                                                 
 * MTB-STL includes - these come from the vendor library                           
 */                                                                                
#ifdef CONFIG_POST_MTB_STL_CFGREG                                                  
#include "SelfTest_ConfigRegisters.h"                                              
#include "SelfTest_CRC_calc.h"                                                     
#endif                                                                             
                                                                                   
#ifdef CONFIG_POST_MTB_STL_CPU                                                     
#include "SelfTest_CPU.h"                                                          
#endif                                                                             
                                                                                   
#ifdef CONFIG_POST_MTB_STL_RAM                                                     
#include "SelfTest_RAM.h"                                                          
#endif                                                                             
                                                                                   
#ifdef CONFIG_POST_MTB_STL_STACK                                                   
#include "SelfTest_Stack.h"                                                        
#endif                                                                             
                                                                                   
#ifdef CONFIG_POST_MTB_STL_FLASH                                                   
#include "SelfTest_Flash.h"                                                        
#include <zephyr/devicetree.h>                                                     
#include <zephyr/storage/flash_map.h>                                              
#endif                                                                             
                                                                                   
#ifdef CONFIG_POST_MTB_STL_CLOCK                                                   
#include "SelfTest_Clock.h"                                                        
#endif                                                                             
                                                                                   
#ifdef CONFIG_POST_MTB_STL_GPIO                                                    
#include "SelfTest_IO.h"                                                           
#endif                                                                             
                                                                                   
#ifdef CONFIG_POST_MTB_STL_INTERRUPT                                               
#include "SelfTest_Interrupt.h"                                                    
#endif                                                                             
                                                                                   
#ifdef CONFIG_POST_MTB_STL_DMA                                                     
#include "SelfTest_DMAC.h"                                                         
#endif                                                                             
                                                                                   
#ifdef CONFIG_POST_MTB_STL_WDT                                                     
#include "SelfTest_WDT.h"                                                          
#endif                                                                             
                                                                                   
#ifdef CONFIG_POST_MTB_STL_FPU                                                     
#include "SelfTest_FPU_Regs.h"                                                     
#endif                                                                             
                                                                                   
#ifdef CONFIG_POST_MTB_STL_ANALOG                                                  
#include "SelfTest_Analog.h"                                                       
#endif                                                                             
                                                                                   
#ifdef CONFIG_POST_MTB_STL_UART_LOOPBACK
#include "SelfTest_UART_SCB.h"
#include <zephyr/drivers/uart.h>
#include <zephyr/drivers/clock_control/clock_control_ifx_cat1.h>
#include <cy_gpio.h>
#include <cy_sysclk.h>
#include <cy_scb_uart.h>


#define _GPIO_PORT(num) GPIO_PRT##num

#define UART_STL_LP_TX_PORT CONFIG_POST_MTB_STL_UART_LOOPBACK_TX_PORT
#define UART_STL_LP_RX_PORT CONFIG_POST_MTB_STL_UART_LOOPBACK_RX_PORT
#define UART_STL_LP_TX_PIN  CONFIG_POST_MTB_STL_UART_LOOPBACK_TX_PIN
#define UART_STL_LP_RX_PIN  CONFIG_POST_MTB_STL_UART_LOOPBACK_RX_PIN


#define UART_STL_HSIOM(port, pin, scb_num, dir) \
    P##port##_##pin##_SCB##scb_num##_UART_##dir

struct ifx_cat1_uart_data {
	struct uart_config cfg;
	struct ifx_cat1_resource_inst hw_resource;
	struct ifx_cat1_clock clock;
#if defined(COMPONENT_CAT1B) || defined(COMPONENT_CAT1C) || defined(CONFIG_SOC_FAMILY_INFINEON_EDGE)
	uint8_t clock_peri_group;
#endif
#if CONFIG_UART_INTERRUPT_DRIVEN
	uart_irq_callback_user_data_t irq_cb;
	void *irq_cb_data;
#endif
	bool cts_enabled;
	bool rts_enabled;
	cy_stc_scb_uart_context_t context;
	cy_stc_scb_uart_config_t scb_config;
	uint32_t baud_rate;
};

struct ifx_cat1_uart_config {
	const struct pinctrl_dev_config *pcfg;
	CySCB_Type *reg_addr;
	struct uart_config dt_cfg;
	uint16_t irq_num;
	uint8_t irq_priority;
};

/* Driver state structure for save/restore */
struct uart_driver_state {
	/* Driver data structure */
	struct uart_config uart_cfg;
	cy_stc_scb_uart_context_t context;
	cy_stc_scb_uart_config_t scb_config;
	
	/* Clock configuration */
	uint32_t clock_divider;
	uint32_t clock_block;
	uint32_t clock_channel;
	bool clock_enabled;
	
	/* Pin configuration (TX/RX) */
	cy_stc_gpio_pin_config_t tx_pin_cfg;
	cy_stc_gpio_pin_config_t rx_pin_cfg;
	GPIO_PRT_Type *tx_port;
	uint32_t tx_pin;
	GPIO_PRT_Type *rx_port;
	uint32_t rx_pin;
	
	/* SCB register state */
	uint32_t scb_ctrl;
	uint32_t scb_rx_fifo_ctrl;
	uint32_t scb_tx_fifo_ctrl;
	uint32_t scb_intr_rx_mask;
	uint32_t scb_intr_tx_mask;
	
	/* Interrupt state */
	bool irq_enabled;
	uint32_t irq_priority;
	
	/* SCB base address */
	CySCB_Type *scb_base;
	uint32_t scb_block_num;
};

#endif
                                                                                   
#ifdef CONFIG_POST_MTB_STL_PWM                                                     
#include "SelfTest_PWM.h"                                                          
#endif                                                                             
                                                                                   
#ifdef CONFIG_POST_MTB_STL_COUNTER                                                 
#include "SelfTest_Timer_Counter.h"                                                
#endif                                                                             
                                                                                   
#ifdef CONFIG_POST_MTB_STL_PWM_GATEKILL                                            
#include "SelfTest_PWM_GateKill.h"                                                 
#endif                                                                             
                                                                                   
#ifdef CONFIG_POST_MTB_STL_COMM                                                    
#include "SelfTest_UART_master_message.h"                                          
#include "SelfTest_UART_slave_message.h"                                           
#include "SelfTest_CRC_calc.h"                                                     
#endif                                                                             
                                                                                   
/*                                                                                 
 * Helper symbols                                                       
 */                                                                                
extern char z_interrupt_stacks[];                                                  
extern char z_main_stack[];                                                        
          
/*
 * Dts Helper macros
 */

/*
 * Counter dts
 */
#define IFX_STL_CNT0_NODE DT_NODELABEL(counter0_0)
#define IFX_STL_CNT1_NODE DT_NODELABEL(counter0_1)
#define IFX_STL_CNT2_NODE DT_NODELABEL(counter0_2)
#define IFX_STL_CNT3_NODE DT_NODELABEL(counter0_3)
#define IFX_STL_CNT4_NODE DT_NODELABEL(counter0_3)

/*
 * Clock dts
 */
#define IFX_STL_PERI_CLK0_NODE DT_NODELABEL(peri_clk_div0) 
#define IFX_STL_PERI_CLK1_NODE DT_NODELABEL(peri_clk_div1)
#define IFX_STL_PERI_CLK2_NODE DT_NODELABEL(peri_clk_div2)
#define IFX_STL_PERI_CLK3_NODE DT_NODELABEL(peri_clk_div3)
#define IFX_STL_PERI_CLK6_NODE DT_NODELABEL(peri_clk_div6)
#define IFX_STL_PERI_CLK7_NODE DT_NODELABEL(peri_clk_div7)
#define IFX_STL_PERI_CLK8_NODE DT_NODELABEL(peri_clk_div8)
#define IFX_STL_PERI_CLK9_NODE DT_NODELABEL(peri_clk_div9)
#define IFX_STL_PERI_CLK10_NODE DT_NODELABEL(peri_clk_div10)
#define IFX_STL_PERI_CLK0_DIV_VAL DT_PROP(IFX_STL_PERI_CLK0_NODE, clock_div)
#define IFX_STL_PERI_CLK1_DIV_VAL DT_PROP(IFX_STL_PERI_CLK1_NODE, clock_div)
#define IFX_STL_PERI_CLK2_DIV_VAL DT_PROP(IFX_STL_PERI_CLK2_NODE, clock_div)
#define IFX_STL_PERI_CLK3_DIV_VAL DT_PROP(IFX_STL_PERI_CLK3_NODE, clock_div)
#define IFX_STL_PERI_CLK6_DIV_VAL DT_PROP(IFX_STL_PERI_CLK6_NODE, clock_div)
#define IFX_STL_PERI_CLK7_DIV_VAL DT_PROP(IFX_STL_PERI_CLK7_NODE, clock_div)
#define IFX_STL_PERI_CLK8_DIV_VAL DT_PROP(IFX_STL_PERI_CLK8_NODE, clock_div)
#define IFX_STL_PERI_CLK9_DIV_VAL DT_PROP(IFX_STL_PERI_CLK9_NODE, clock_div)
#define IFX_STL_PERI_CLK10_DIV_VAL DT_PROP(IFX_STL_PERI_CLK10_NODE, clock_div)

/*
 * Helper Macros
 */

/*
 * Stack and Flash 
 */
#ifndef CONFIG_MAIN_STACK_SIZE                                                     
#define DEVICE_STACK_SIZE    (0x00000400)  /* Default 1KB if not configured */     
#else                                                                              
#define DEVICE_STACK_SIZE    (CONFIG_MAIN_STACK_SIZE)                              
#endif                                                                             
#define DEVICE_SRAM_BASE     DT_REG_ADDR(DT_CHOSEN(zephyr_sram))                   
#define DEVICE_SRAM_SIZE     DT_REG_SIZE(DT_CHOSEN(zephyr_sram))                   
#define DEVICE_FLASH_BASE    DT_REG_ADDR(DT_CHOSEN(zephyr_flash))                  
#define DEVICE_FLASH_SIZE    DT_REG_SIZE(DT_CHOSEN(zephyr_flash))                  
#define DEVICE_STACK_BASE    ((uintptr_t)z_main_stack)                             
                   
/*
 * TCPWM 
 */
#define IFX_TCPWM_HW TCPWM                                                         
#define IFX_TCPWM_INPUT_DISABLED 0x7                                               
#define IFX_TCPWM_IRQ_NUM_CNT0 tcpwm_interrupts_0_IRQn                             
#define IFX_TCPWM_IRQ_NUM_CNT1 tcpwm_interrupts_1_IRQn                             
#define IFX_TCPWM_IRQ_NUM_CNT2 tcpwm_interrupts_2_IRQn                             
#define IFX_TCPWM_IRQ_NUM_CNT3 tcpwm_interrupts_3_IRQn                             
#define IFX_TCPWM_CNT_PRIO_1 1                                                     
#define IFX_TCPWM_CNT_PRIO_2 2                                                     
#define IFX_TCPWM_CNT_PRIO_3 3                                                     
#define IFX_TCPWM_CNT_NUM0 0                                                       
#define IFX_TCPWM_CNT_NUM1 1                                                       
#define IFX_TCPWM_CNT_NUM2 2                                                       
#define IFX_TCPWM_CNT_NUM3 3                                                       
#define IFX_TCPWM_CNT_NUM4 4                                                       
#define IFX_ILO_START_UP_TIME 2                                                    
         
/*
 * SCBs
 */
#define IFX_SCB1_HW SCB1                                                           
#define IFX_SCB3_HW SCB3                                                           
#define IFX_SCB4_HW SCB4                                                           
#define IFX_SCB3_IRQ_NUM scb_3_interrupt_IRQn                                      
#define IFX_SCB4_IRQ_NUM scb_4_interrupt_IRQn                                      

/*
 * Analog
 */
#define IFX_SAR0_VPLUS0_PIN 0
#define IFX_SAR0_VPLUS0_PORT 0

#endif /* MTB_STL_POST_H */
