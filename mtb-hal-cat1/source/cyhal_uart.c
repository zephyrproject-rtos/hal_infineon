/*******************************************************************************
* File Name: cyhal_uart.c
*
* Description:
* Provides a high level interface for interacting with the Infineon UART. This is
* a wrapper around the lower level PDL API.
*
********************************************************************************
* \copyright
* Copyright 2018-2022 Cypress Semiconductor Corporation (an Infineon company) or
* an affiliate of Cypress Semiconductor Corporation
*
* SPDX-License-Identifier: Apache-2.0
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

#include <stdlib.h>
#include <string.h>
#include "cyhal_uart.h"
#include "cyhal_scb_common.h"
#include "cyhal_gpio.h"
#include "cyhal_system_impl.h"
#include "cyhal_hwmgr.h"
#include "cyhal_syspm.h"
#include "cyhal_clock.h"
#if (CYHAL_DRIVER_AVAILABLE_DMA)
#include "cyhal_dma.h"
#endif
#include "cyhal_interconnect.h"
#include "cyhal_irq_impl.h"

#if (CYHAL_DRIVER_AVAILABLE_UART)

/** \addtogroup group_hal_uart UART
 * \ingroup group_hal
 * \{
 * \section group_hal_uart_dma_transfers Asynchronous DMA Transfers
 * Asynchronous transfers can be performed using DMA to load data into
 * and from the FIFOs. The purpose of this is to minimize CPU load on
 * large transfers. Unlike SW async mode, DMA async mode does not support an
 * overflow buffer as it would cause CPU load and go against the fundamental
 * principle of using DMA transfers. Trying to set DMA async mode when an
 * overflow buffer is enabled will return an error. If an application wants
 * to transition from SW to DMA async modes it is recommended to perform the following
 * sequence:
 * 1. Read until the ring buffer is empty. This can be determined by checking
 * that cyhal_uart_readable returns a number that is smaller than the hardware fifo size.
 * 2. Enter a critical section, to prevent any interrupts from refilling the ring buffer.
 * 3. Repeat step 1 if necessary
 * 4. Use cyhal_uart_configure to disable the ring buffer, or free and reinit the UART
 *    instance with no SW buffer
 * 5. Exit the critical section
 * 6. Call cyhal_uart_set_async_mode to change the async mode to DMA.
 * 
 * If an application wants to transition from DMA to SW async modes, and enable
 * the ring buffer, it is recommended to perform the following sequence:
 * 1. Call cyhal_uart_set_async_mode to change the async mode to SW.
 * 2. Use cyhal_uart_config_software_buffer to enable the ring buffer 
 * 
 * \section group_hal_uart_pm_strategy UART at different power modes
 * In order to allow UART to maintain the specified baud rate in all 
 * power modes it was necessary to introduce a power management callback 
 * that deals with the state switching for supported power modes 
 * (e.g. normal, low power).
 * As the clock inputs can change when switching power modes it is necessary
 * to reset the baud rate. Since it is not possible to pause a transmission 
 * and then restart it after the power mode has been updated whenever a system
 * state change is detected any ongoing transmission is aborted. 
 * It is then up to the user to make sure that all transmissions are finished 
 * Therefore, power state transition is prevented if the FIFO is not empty.
 * It's also important to note that if a custom cyhal_clock_t value was provided
 * during cyhal_uart_init, the UART HAL cannot automatically update the baud rate
 * because it does not own the source clock. 
 * In that case, the application must adjust the UART source clock itself to retain
 * the desired frequency.
 * \} group_hal_uart
 */


#if defined(__cplusplus)
extern "C"
{
#endif

#if defined(COMPONENT_CAT5)
/* CAT5 SCB System Clock Maximum frequency is 192MHz, maximum divider
 * value is 128 and hence the minimum valid oversample value possible is 13
 */
#define _CYHAL_UART_OVERSAMPLE                 13UL
#else
#define _CYHAL_UART_OVERSAMPLE                 12UL
#endif
#define _CYHAL_UART_OVERSAMPLE_MIN             8UL
#define _CYHAL_UART_OVERSAMPLE_MAX             16UL

/* Default UART configuration */
static const cy_stc_scb_uart_config_t _cyhal_uart_default_config = {
    .uartMode                   = CY_SCB_UART_STANDARD,
    .enableMutliProcessorMode   = false,
    .smartCardRetryOnNack       = false,
    .irdaInvertRx               = false,
    .irdaEnableLowPowerReceiver = false,

    .oversample                 = _CYHAL_UART_OVERSAMPLE,

    .enableMsbFirst             = false,
    .dataWidth                  = 8UL,
    .parity                     = CY_SCB_UART_PARITY_NONE,
    .stopBits                   = CY_SCB_UART_STOP_BITS_1,
    .enableInputFilter          = false,
    .breakWidth                 = 11UL,
    .dropOnFrameError           = false,
    .dropOnParityError          = false,

    .receiverAddress            = 0x0UL,
    .receiverAddressMask        = 0x0UL,
    .acceptAddrInFifo           = false,

    .enableCts                  = false,
    .ctsPolarity                = CY_SCB_UART_ACTIVE_LOW,
#if defined(COMPONENT_CAT1A) || defined(COMPONENT_CAT1B) || defined(COMPONENT_CAT1C) || defined(COMPONENT_CAT1D) || defined(COMPONENT_CAT5)
    .rtsRxFifoLevel             = 20UL,
#elif defined(COMPONENT_CAT2)
    .rtsRxFifoLevel             = 3UL,
#endif
    .rtsPolarity                = CY_SCB_UART_ACTIVE_LOW,

    .rxFifoTriggerLevel         = 0UL,  /* Level triggers when at least one element is in FIFO */
    .rxFifoIntEnableMask        = 0x0UL,

    .txFifoTriggerLevel         = (CY_SCB_FIFO_SIZE/2 - 1), /* Level triggers when half-fifo is half empty */
    .txFifoIntEnableMask        = 0x0UL
};

/* The PDL clears the IRQ status during Cy_SCB_UART_Interrupt which prevents _cyhal_scb_get_irq_obj()
 * from working properly in _cyhal_uart_cb_wrapper on devices with muxed IRQs, because they can't tell
 * at that point which system IRQ caused the CPU IRQ. So we need to save this value at the beginning of the
 * IRQ handler when we are able to determine what it is */
static volatile cyhal_uart_t* _cyhal_uart_irq_obj = NULL;

#if defined (COMPONENT_CAT5)
static void _cyhal_uart_irq_handler(_cyhal_system_irq_t irqn)
#elif defined (COMPONENT_CAT1C)
void cyhal_uart_irq_handler(cyhal_uart_t* cyhal_uart_irq_obj)
#else
static void _cyhal_uart_irq_handler(void)
#endif
{
    /* Save the old value and store it aftewards in case we get into a nested IRQ situation */
    /* Safe to cast away volatile because we don't expect this pointer to be changed while we're in here, they
     * just might change where the original pointer points */
    cyhal_uart_t* old_irq_obj = (cyhal_uart_t*)_cyhal_uart_irq_obj;
#if defined (COMPONENT_CAT5)
    _cyhal_uart_irq_obj = (cyhal_uart_t*) _cyhal_scb_get_irq_obj(irqn);
#elif defined (COMPONENT_CAT1C)
    _cyhal_uart_irq_obj = cyhal_uart_irq_obj;
#else
    _cyhal_uart_irq_obj = (cyhal_uart_t*) _cyhal_scb_get_irq_obj();
#endif

    if (NULL == _cyhal_uart_irq_obj)
    {
        return;  /* The interrupt object is not valid */
    }

    cyhal_uart_t* obj = (cyhal_uart_t*)_cyhal_uart_irq_obj;

    /* Cy_SCB_UART_Interrupt() manipulates the interrupt masks. Save a copy to work around it. */
    uint32_t txMasked = Cy_SCB_GetTxInterruptStatusMasked(obj->base);
    uint32_t rxMasked = Cy_SCB_GetRxInterruptStatusMasked(obj->base);

   /* SCB high-level API interrupt handler. Must be called as high-level API is used in the HAL */
    Cy_SCB_UART_Interrupt(obj->base, &(obj->context));

    /* Custom handling for TX overflow (cannot occur using HAL API but can occur if user makes custom modifications)
        Note: This is partially handled in Cy_SCB_UART_Interrupt()
        but it only takes care of NACK and ARB_LOST errors. */
    if (0UL != (CY_SCB_UART_TX_OVERFLOW & txMasked))
    {
        Cy_SCB_ClearTxInterrupt(obj->base, CY_SCB_UART_TX_OVERFLOW);

        if (NULL != obj->context.cbEvents)
        {
            obj->context.cbEvents(CY_SCB_UART_TRANSMIT_ERR_EVENT);
        }
    }

    /* Custom handling for TX underflow (cannot occur using HAL API but can occur if user makes custom modifications)
        Note: This is partially handled in Cy_SCB_UART_Interrupt()
        but it only takes care of NACK and ARB_LOST errors. */
    if (0UL != (CY_SCB_UART_TX_UNDERFLOW & txMasked))
    {
        Cy_SCB_ClearTxInterrupt(obj->base, CY_SCB_UART_TX_UNDERFLOW);

        if (NULL != obj->context.cbEvents)
        {
            obj->context.cbEvents(CY_SCB_UART_TRANSMIT_ERR_EVENT);
        }
    }

    /* Custom handling for TX FIFO trigger.
        Note: This is partially handled in Cy_SCB_UART_Interrupt()
        when processing CY_SCB_TX_INTR_LEVEL. Do not clear the interrupt. */
    if (0UL != (CY_SCB_UART_TX_TRIGGER & txMasked))
    {
        if (NULL != obj->context.cbEvents)
        {
            // Need to shift by 1 due to to existing logic in _cyhal_utils_convert_flags()
            obj->context.cbEvents(CYHAL_UART_IRQ_TX_FIFO >> 1u);
        }
    }

    /* Manually clear the tx done interrupt and re-enable the interrupt mask */
    if (0UL != (CY_SCB_UART_TX_DONE & txMasked))
    {
        Cy_SCB_ClearTxInterrupt(obj->base, CY_SCB_UART_TX_DONE);
        Cy_SCB_SetTxInterruptMask(obj->base, Cy_SCB_GetTxInterruptMask(obj->base) | CY_SCB_UART_TX_DONE);
    }

    /* Custom handling for RX underflow (cannot occur using HAL API but can occur if user makes custom modifications)
        Note: This is partially handled in Cy_SCB_UART_Interrupt()
        which takes care of overflow, frame and parity errors. */
    if (0UL != (CY_SCB_RX_INTR_UNDERFLOW & rxMasked))
    {
        Cy_SCB_ClearRxInterrupt(obj->base, CY_SCB_RX_INTR_UNDERFLOW);

        if (NULL != obj->context.cbEvents)
        {
            obj->context.cbEvents(CY_SCB_UART_RECEIVE_ERR_EVENT);
        }
    }

    /* Custom handling for RX FIFO trigger
        Note: This is partially handled in Cy_SCB_UART_Interrupt()
        when processing CY_SCB_RX_INTR_LEVEL. Do not clear the interrupt. */
    if (0UL != (CY_SCB_UART_RX_TRIGGER & rxMasked))
    {
        if (NULL != obj->context.cbEvents)
        {
            // Need to shift by 1 due to to existing logic in _cyhal_utils_convert_flags()
            obj->context.cbEvents(CYHAL_UART_IRQ_RX_FIFO >> 1u);
        }
    }

    _cyhal_uart_irq_obj = old_irq_obj;
}

#if defined (COMPONENT_CAT5)
// CAT5 interrupts are implemented oddly in PDL: they auto-disable themselves after firing.  So re-enable
static void _cyhal_uart0_irq_handler(void)
{
    _cyhal_uart_irq_handler(scb_0_interrupt_IRQn);
    Cy_SCB_EnableInterrupt(SCB0);
}

static void _cyhal_uart1_irq_handler(void)
{
    _cyhal_uart_irq_handler(scb_1_interrupt_IRQn);
    Cy_SCB_EnableInterrupt(SCB1);
}

static void _cyhal_uart2_irq_handler(void)
{
    _cyhal_uart_irq_handler(scb_2_interrupt_IRQn);
    Cy_SCB_EnableInterrupt(SCB2);
}

static CY_SCB_IRQ_THREAD_CB_t _cyhal_irq_cb[3] = {_cyhal_uart0_irq_handler, _cyhal_uart1_irq_handler, _cyhal_uart2_irq_handler};
#endif

#if (CYHAL_DRIVER_AVAILABLE_DMA)
cy_rslt_t _cyhal_uart_dma_write_async(cyhal_uart_t *obj);

static void _cyhal_uart_dma_handler_tx(void* arg, cyhal_dma_event_t event)
{
    CY_ASSERT(CYHAL_DMA_TRANSFER_COMPLETE == event);
    CY_UNUSED_PARAMETER(event);
    cyhal_uart_t* obj = (cyhal_uart_t*)arg;
    CY_ASSERT(CYHAL_ASYNC_DMA == obj->async_mode);

    if(obj->async_tx_length > 0)
    {
        /* Setup another transfer if we're expecting more */
        _cyhal_uart_dma_write_async(obj);
    }
    else
    {
        obj->async_tx_buff = NULL;
        /* We may have lowered the FIFO to complete a small transfer. Restore it */
        if(obj->user_fifo_level != ((SCB_TX_FIFO_CTRL(obj->base) & SCB_TX_FIFO_CTRL_TRIGGER_LEVEL_Msk)))
        {
            _cyhal_scb_set_fifo_level(obj->base, (cyhal_scb_fifo_type_t)CYHAL_UART_FIFO_TX, obj->user_fifo_level);
        }

        if(0 == (CYHAL_UART_IRQ_TX_FIFO & ((cyhal_uart_event_t)obj->irq_cause)))
        {
             Cy_SCB_SetTxInterruptMask(obj->base, Cy_SCB_GetTxInterruptMask(obj->base) & ~CY_SCB_TX_INTR_LEVEL);
        }

        if(0 != ((cyhal_uart_event_t)obj->irq_cause & CYHAL_UART_IRQ_TX_TRANSMIT_IN_FIFO))
        {
            cyhal_uart_event_callback_t callback = (cyhal_uart_event_callback_t)obj->callback_data.callback;
            if(NULL != callback)
            {
                callback(obj->callback_data.callback_arg, CYHAL_UART_IRQ_TX_TRANSMIT_IN_FIFO);
            }
        }
    }
}

cy_rslt_t _cyhal_uart_dma_read_async(cyhal_uart_t *obj);

static void _cyhal_uart_dma_handler_rx(void* arg, cyhal_dma_event_t event)
{
    CY_ASSERT(CYHAL_DMA_TRANSFER_COMPLETE == event);
    CY_UNUSED_PARAMETER(event);
    cyhal_uart_t* obj = (cyhal_uart_t*)arg;
    CY_ASSERT(CYHAL_ASYNC_DMA == obj->async_mode);

    if(obj->async_rx_length > 0)
    {
        /* Setup another transfer if we're expecting more */
        _cyhal_uart_dma_read_async(obj);
    }
    else
    {
        obj->async_rx_buff = NULL;
        /* We may have lowered the FIFO to complete a small transfer. Restore it */
        if(obj->user_fifo_level != ((SCB_RX_FIFO_CTRL(obj->base) & SCB_RX_FIFO_CTRL_TRIGGER_LEVEL_Msk)))
        {
            _cyhal_scb_set_fifo_level(obj->base, (cyhal_scb_fifo_type_t)CYHAL_UART_FIFO_RX, obj->user_fifo_level);
        }

        if(0 != ((cyhal_uart_event_t)obj->irq_cause & CYHAL_UART_IRQ_RX_DONE))
        {
            cyhal_uart_event_callback_t callback = (cyhal_uart_event_callback_t)obj->callback_data.callback;
            if(NULL != callback)
            {
                callback(obj->callback_data.callback_arg, CYHAL_UART_IRQ_RX_DONE);
            }
        }
    }
}
#endif

static void _cyhal_uart_cb_wrapper(uint32_t event)
{
    static const uint32_t status_map[] =
    {
        /* The ordering here has to match group_scb_uart_macros_callback_events in the PDL since it uses
           the high-level APIs to perform the callback handling.
           Note: Remember that the values are shifted by 1. */
        (uint32_t)CYHAL_UART_IRQ_NONE,                 // 0: Default no IRQ
        (uint32_t)CYHAL_UART_IRQ_TX_TRANSMIT_IN_FIFO,  // 1: CY_SCB_UART_TRANSMIT_IN_FIFO_EVENT
        (uint32_t)CYHAL_UART_IRQ_TX_DONE,              // 2: CY_SCB_UART_TRANSMIT_DONE_EVENT
        (uint32_t)CYHAL_UART_IRQ_RX_DONE,              // 3: CY_SCB_UART_RECEIVE_DONE_EVENT
        (uint32_t)CYHAL_UART_IRQ_RX_FULL,              // 4: CY_SCB_UART_RB_FULL_EVENT
        (uint32_t)CYHAL_UART_IRQ_RX_ERROR,             // 5: CY_SCB_UART_RECEIVE_ERR_EVENT
        (uint32_t)CYHAL_UART_IRQ_TX_ERROR,             // 6: CY_SCB_UART_TRANSMIT_ERR_EVENT
        (uint32_t)CYHAL_UART_IRQ_RX_NOT_EMPTY,         // 7: CY_SCB_UART_RECEIVE_NOT_EMTPY
        (uint32_t)CYHAL_UART_IRQ_TX_EMPTY,             // 8: CY_SCB_UART_TRANSMIT_EMTPY
        // Custom events from HAL
        (uint32_t)CYHAL_UART_IRQ_TX_FIFO,              // 9: CYHAL_UART_IRQ_TX_FIFO
        (uint32_t)CYHAL_UART_IRQ_RX_FIFO,              // 10: CYHAL_UART_IRQ_RX_FIFO
    };
    uint32_t hal_event = _cyhal_utils_convert_flags(status_map, sizeof(status_map) / sizeof(uint32_t), event);

    /* Safe to cast away volatile because we don't expect this pointer to be changed while we're in here, they
     * just might change where the original pointer points */
    cyhal_uart_t *obj = (cyhal_uart_t*)_cyhal_uart_irq_obj;
    cyhal_uart_event_t anded_events = (cyhal_uart_event_t)(obj->irq_cause & hal_event);
    if (anded_events)
    {
        cyhal_uart_event_callback_t callback = (cyhal_uart_event_callback_t) obj->callback_data.callback;
        callback(obj->callback_data.callback_arg, anded_events);
    }
}

static bool _cyhal_uart_pm_callback_instance(void *obj_ptr, cyhal_syspm_callback_state_t state, cy_en_syspm_callback_mode_t pdl_mode)
{
    cyhal_uart_t *obj = (cyhal_uart_t*)obj_ptr;
    bool allow = false;

    // The output pins need to be set to high before going to deepsleep.
    // Otherwise the UART on the other side would see incoming data as '0'.
    GPIO_PRT_Type *txport = obj->pin_tx != NC ? CYHAL_GET_PORTADDR(obj->pin_tx) : NULL;
    GPIO_PRT_Type *rtsport = ((obj->pin_rts != NC) && obj->rts_enabled) ? CYHAL_GET_PORTADDR(obj->pin_rts) : NULL;
    uint8_t txpin = (uint8_t)CYHAL_GET_PIN(obj->pin_tx);
    uint8_t rtspin = (uint8_t)CYHAL_GET_PIN(obj->pin_rts);
    #if defined (COMPONENT_CAT5)
        CY_UNUSED_PARAMETER(txpin);
        CY_UNUSED_PARAMETER(rtspin);
    #endif

   if (state == CYHAL_SYSPM_CB_SYSTEM_NORMAL || state == CYHAL_SYSPM_CB_SYSTEM_LOW)
    {
        if(pdl_mode == CY_SYSPM_CHECK_READY)
        {
            /* Check whether the High-level API is not busy executing the transmit
            * or receive operation.
            */
            if ((0UL == (CY_SCB_UART_TRANSMIT_ACTIVE & Cy_SCB_UART_GetTransmitStatus(obj->base, &(obj->context)))) &&
                (0UL == (CY_SCB_UART_RECEIVE_ACTIVE  & Cy_SCB_UART_GetReceiveStatus (obj->base, &(obj->context))))
            #if (CYHAL_DRIVER_AVAILABLE_DMA)
                & (obj->async_rx_buff == NULL) & (obj->async_tx_buff == NULL))
            #else
                )
            #endif /* CYHAL_DRIVER_AVAILABLE_DMA */
            {
                /* If all data elements are transmitted from the TX FIFO and
                * shifter and the RX FIFO is empty: the UART is ready to enter
                * Deep Sleep mode.
                */
                if (Cy_SCB_UART_IsTxComplete(obj->base))
                {
                    if (0UL == Cy_SCB_UART_GetNumInRxFifo(obj->base))
                    {
                        allow = true;
                    }
                }
            }
        }
        if (pdl_mode == CY_SYSPM_AFTER_TRANSITION)
        {        
            allow = true;    
            //Return of the function is ignored as failing to reset the baud rate
            //does not classify as reason to interrupt the power mode transition
            cyhal_uart_set_baud(obj, obj->baud_rate, NULL);

            if (NULL != rtsport)
            {
                Cy_GPIO_SetHSIOM(rtsport, rtspin, obj->saved_rts_hsiom);
            }
        }
        if (pdl_mode == CY_SYSPM_BEFORE_TRANSITION)
        {
            allow = true;

            if (NULL != rtsport)
            {
                obj->saved_rts_hsiom = Cy_GPIO_GetHSIOM(rtsport, rtspin);
                Cy_GPIO_Set(rtsport, rtspin);
                Cy_GPIO_SetHSIOM(rtsport, rtspin, HSIOM_SEL_GPIO);
            }
        }
    }
    else
    {
        switch (pdl_mode)
        {
            case CY_SYSPM_CHECK_READY:
                /* Check whether the High-level API is not busy executing the transmit
                * or receive operation.
                */
                if ((0UL == (CY_SCB_UART_TRANSMIT_ACTIVE & Cy_SCB_UART_GetTransmitStatus(obj->base, &(obj->context)))) &&
                    (0UL == (CY_SCB_UART_RECEIVE_ACTIVE  & Cy_SCB_UART_GetReceiveStatus (obj->base, &(obj->context))))
                #if (CYHAL_DRIVER_AVAILABLE_DMA)
                    & (obj->async_rx_buff == NULL) & (obj->async_tx_buff == NULL))
                #else
                    )
                #endif /* CYHAL_DRIVER_AVAILABLE_DMA */
                {
                    /* Not all interrupts are preserved across DeepSleep entry/exit. For example,
                     * TX_UART_DONE is not. So block DeepSleep entry if any of our interrupts are
                     * unmasked. It is safe to check at the SCB level rather than the NVIC because
                     * the HAL never unmasks an interrupt without registering a handler.
                     *
                     * Neither of the FIFOs are preserved, so also block DeepSleep if either of them
                     * has contents.
                     */
                    uint32_t txMasked = Cy_SCB_GetTxInterruptStatusMasked(obj->base);
                    uint32_t rxMasked = Cy_SCB_GetRxInterruptStatusMasked(obj->base);
                    /* If all data elements are transmitted from the TX FIFO and
                    * shifter and the RX FIFO is empty: the UART is ready to enter
                    * Deep Sleep mode.
                    */

                    if (Cy_SCB_UART_IsTxComplete(obj->base)
                         && (0UL == Cy_SCB_UART_GetNumInRxFifo(obj->base))
                         && (0UL == txMasked) && (0UL == rxMasked))
                    {
                        /* Disable the UART. The transmitter stops driving the
                        * lines and the receiver stops receiving data until
                        * the UART is enabled.
                        * This happens when the device failed to enter Deep
                        * Sleep or it is awaken from Deep Sleep mode.
                        */

                        if (NULL != txport)
                        {
                            obj->saved_tx_hsiom = Cy_GPIO_GetHSIOM(txport, txpin);
                            Cy_GPIO_Set(txport, txpin);
                            Cy_GPIO_SetHSIOM(txport, txpin, HSIOM_SEL_GPIO);
                        }
                        if (NULL != rtsport)
                        {
                            obj->saved_rts_hsiom = Cy_GPIO_GetHSIOM(rtsport, rtspin);
                            Cy_GPIO_Set(rtsport, rtspin);
                            Cy_GPIO_SetHSIOM(rtsport, rtspin, HSIOM_SEL_GPIO);
                        }

                        Cy_SCB_UART_Disable(obj->base, &(obj->context));
                        allow = true;
                    }
                }

                break;

            case CY_SYSPM_CHECK_FAIL:
            case CY_SYSPM_AFTER_TRANSITION:
                allow = true;
                Cy_SCB_UART_Enable(obj->base);
                if (NULL != txport)
                {
                    Cy_GPIO_SetHSIOM(txport, txpin, obj->saved_tx_hsiom);
                }
                if (NULL != rtsport)
                {
                    Cy_GPIO_SetHSIOM(rtsport, rtspin, obj->saved_rts_hsiom);
                }
                break;

            case CY_SYSPM_BEFORE_TRANSITION:
                allow = true;
                break;
    #if defined(COMPONENT_CAT1B)
            case CY_SYSPM_AFTER_DS_WFI_TRANSITION:
                allow = true;
                break;
    #endif
            default:
                CY_ASSERT(false);
                break;
        }
    }
    return allow;
}
static cy_en_scb_uart_parity_t _cyhal_uart_convert_parity(cyhal_uart_parity_t parity)
{
    switch (parity)
    {
        case CYHAL_UART_PARITY_NONE:
            return CY_SCB_UART_PARITY_NONE;
        case CYHAL_UART_PARITY_EVEN:
            return CY_SCB_UART_PARITY_EVEN;
        case CYHAL_UART_PARITY_ODD:
            return CY_SCB_UART_PARITY_ODD;
        default:
            return CY_SCB_UART_PARITY_NONE;
    }
}

static cy_en_scb_uart_stop_bits_t _cyhal_uart_convert_stopbits(uint8_t stopbits)
{
    switch (stopbits)
    {
        case 1:
            return CY_SCB_UART_STOP_BITS_1;
        case 2:
            return CY_SCB_UART_STOP_BITS_2;
        case 3:
            return CY_SCB_UART_STOP_BITS_3;
        case 4:
            return CY_SCB_UART_STOP_BITS_4;
        default:
            CY_ASSERT(false);
            return CY_SCB_UART_STOP_BITS_1;
    }
}

static uint32_t _cyhal_uart_actual_baud(const cyhal_resource_inst_t *resource, uint32_t divider, uint32_t oversample)
{
    return _cyhal_utils_get_peripheral_clock_frequency(resource) / (divider * oversample);
}

static uint32_t _cyhal_uart_baud_perdif(uint32_t desired_baud, uint32_t actual_baud)
{
    return (actual_baud > desired_baud)
        ? ((actual_baud * 100) - (desired_baud * 100)) / desired_baud
        : ((desired_baud * 100) - (actual_baud * 100)) / desired_baud;
}

static uint8_t _cyhal_uart_best_oversample(const cyhal_resource_inst_t *resource, uint32_t baudrate)
{
    uint8_t best_oversample = _CYHAL_UART_OVERSAMPLE_MIN;
    uint8_t best_difference = 0xFF;

    for (uint8_t i = _CYHAL_UART_OVERSAMPLE_MIN; i < _CYHAL_UART_OVERSAMPLE_MAX + 1; i++)
    {
        uint32_t divider = _cyhal_utils_divider_value(resource, baudrate * i, 0);

        #if defined(COMPONENT_CAT5)
        if(!_cyhal_clock_is_divider_valid(resource, divider))
        {
            continue;
        }
        #endif
        uint8_t difference = (uint8_t)_cyhal_uart_baud_perdif(baudrate, _cyhal_uart_actual_baud(resource, divider, i));

        if (difference < best_difference)
        {
            best_difference = difference;
            best_oversample = i;
        }
    }

    return best_oversample;
}

static cy_rslt_t _cyhal_uart_setup_resources(cyhal_uart_t *obj, cyhal_gpio_t tx, cyhal_gpio_t rx, cyhal_gpio_t cts,
                                             cyhal_gpio_t rts, const cyhal_clock_t *clk)
{
    cy_rslt_t result;

    // Explicitly marked not allocated resources as invalid to prevent freeing them.
    obj->resource.type = CYHAL_RSC_INVALID;
    obj->is_clock_owned = false;
    obj->pin_rx = CYHAL_NC_PIN_VALUE;
    obj->pin_tx = CYHAL_NC_PIN_VALUE;
    obj->pin_cts = CYHAL_NC_PIN_VALUE;
    obj->pin_rts = CYHAL_NC_PIN_VALUE;

    // checking for invalid flow control pin combinations (corresponding pin required) and checking that at least TX or RX is specified (both cannot be NC)
    if ((NC == tx && NC != rts) || (NC == rx && NC != cts) || (NC == tx && NC == rx))
    {
        return CYHAL_UART_RSLT_ERR_INVALID_PIN;
    }

    uint32_t saved_intr_status = cyhal_system_critical_section_enter();

    // pins_blocks will contain bit representation of blocks, that are connected to specified pin
    // 1 block - 1 bit, so, for example, pin_blocks = 0x00000006 means that certain pin
    // can belong to next non-reserved blocks SCB2 and SCB1
    uint32_t pins_blocks = _CYHAL_SCB_AVAILABLE_BLOCKS_MASK;
    if (NC != tx)
    {
        pins_blocks &= _CYHAL_SCB_CHECK_AFFILIATION(tx, cyhal_pin_map_scb_uart_tx);
    }
    if (NC != rx)
    {
        pins_blocks &= _CYHAL_SCB_CHECK_AFFILIATION(rx, cyhal_pin_map_scb_uart_rx);
    }
    if (NC != cts)
    {
        pins_blocks &= _CYHAL_SCB_CHECK_AFFILIATION(cts, cyhal_pin_map_scb_uart_cts);
    }
    if (NC != rts)
    {
        pins_blocks &= _CYHAL_SCB_CHECK_AFFILIATION(rts, cyhal_pin_map_scb_uart_rts);
    }
    // One (or more) pin does not belong to any SCB instance or all corresponding SCB instances
    // are reserved
    if (0 == pins_blocks)
    {
        cyhal_system_critical_section_exit(saved_intr_status);
        return CYHAL_UART_RSLT_ERR_INVALID_PIN;
    }

    uint8_t found_block_idx = 0;
    while(((pins_blocks >> found_block_idx) & 0x1) == 0)
    {
        found_block_idx++;
    }

    cyhal_resource_inst_t uart_rsc = { CYHAL_RSC_SCB, found_block_idx, 0 };

    // Reserve the UART
    const cyhal_resource_pin_mapping_t *tx_map = _CYHAL_SCB_FIND_MAP_BLOCK(tx, cyhal_pin_map_scb_uart_tx, &uart_rsc);
    const cyhal_resource_pin_mapping_t *rx_map = _CYHAL_SCB_FIND_MAP_BLOCK(rx, cyhal_pin_map_scb_uart_rx, &uart_rsc);
    const cyhal_resource_pin_mapping_t *cts_map = _CYHAL_SCB_FIND_MAP_BLOCK(cts, cyhal_pin_map_scb_uart_cts, &uart_rsc);
    const cyhal_resource_pin_mapping_t *rts_map = _CYHAL_SCB_FIND_MAP_BLOCK(rts, cyhal_pin_map_scb_uart_rts, &uart_rsc);

    if ((NC != tx && NULL == tx_map) || (NC != rx && NULL == rx_map) || (NC != cts && NULL == cts_map) || (NC != rts && NULL == rts_map))
    {
        // Should never enter here, as _CYHAL_SCB_CHECK_AFFILIATION above garantee that all of these pin maps exist.
        CY_ASSERT(false);
    }

    cyhal_resource_inst_t rsc_to_reserve = { CYHAL_RSC_SCB, _cyhal_scb_get_block_index(found_block_idx), 0 };
    result = cyhal_hwmgr_reserve(&rsc_to_reserve);
    cyhal_system_critical_section_exit(saved_intr_status);
    if (CY_RSLT_SUCCESS != result)
    {
        return result;
    }

    obj->resource = uart_rsc;

    // reserve the TX pin
    if ((result == CY_RSLT_SUCCESS) && NC != tx)
    {
        result = _cyhal_utils_reserve_and_connect(tx_map, (uint8_t)CYHAL_PIN_MAP_DRIVE_MODE_SCB_UART_TX);
        if (result == CY_RSLT_SUCCESS)
        {
            obj->pin_tx = tx;
        }
    }

    // reserve the RX pin
    if ((result == CY_RSLT_SUCCESS) && NC != rx)
    {
        result = _cyhal_utils_reserve_and_connect(rx_map, (uint8_t)CYHAL_PIN_MAP_DRIVE_MODE_SCB_UART_RX);
        if (result == CY_RSLT_SUCCESS)
        {
            obj->pin_rx = rx;
        }
    }

    if ((result == CY_RSLT_SUCCESS) && (NULL != cts_map))
    {
        // reserve the CTS pin
        result = _cyhal_utils_reserve_and_connect(cts_map, (uint8_t)CYHAL_PIN_MAP_DRIVE_MODE_SCB_UART_CTS);
        if (result == CY_RSLT_SUCCESS)
        {
            obj->cts_enabled = true;
            obj->pin_cts = cts;
        }
    }

    if ((result == CY_RSLT_SUCCESS) && (NULL != rts_map))
    {
        // reserve the RTS pin
        result = _cyhal_utils_reserve_and_connect(rts_map, (uint8_t)CYHAL_PIN_MAP_DRIVE_MODE_SCB_UART_RTS);
        if (result == CY_RSLT_SUCCESS)
        {
            obj->rts_enabled = true;
            obj->pin_rts = rts;
        }
    }

    if (result == CY_RSLT_SUCCESS)
    {
        if (clk == NULL)
        {
            result = _cyhal_utils_allocate_clock(&(obj->clock), &obj->resource, CYHAL_CLOCK_BLOCK_PERIPHERAL_16BIT, true);
            obj->is_clock_owned = (CY_RSLT_SUCCESS == result);
        }
        else
        {
            obj->is_clock_owned = false;
            obj->clock = *clk;
        }
    }

    if (result == CY_RSLT_SUCCESS)
    {
        result = _cyhal_utils_peri_pclk_assign_divider(
            _cyhal_scb_get_clock_index(obj->resource.block_num), &(obj->clock));
    }

    return result;
}

static cy_rslt_t _cyhal_uart_init_hw(cyhal_uart_t *obj)
{
    uint8_t scb_arr_index = _cyhal_scb_get_block_index(obj->resource.block_num);
    obj->base = _CYHAL_SCB_BASE_ADDRESSES[scb_arr_index];

    #if defined(COMPONENT_CAT5)
    // CAT5 SCBs must be enabled prior to UART init
    if(obj->is_clock_owned == true)
    {
        cyhal_uart_set_baud(obj, CYHAL_UART_DEFAULT_BAUD, NULL);
    }
    else
    {
        // Ensure user-provided clock is enabled
        Cy_SCB_EnableClock(obj->base, cyhal_clock_get_frequency(&(obj->clock)), false);
    }
    #endif

    cy_rslt_t result = (cy_rslt_t) Cy_SCB_UART_Init(obj->base, &(obj->config), &(obj->context));

    if (CY_RSLT_SUCCESS == result)
    {
        obj->callback_data.callback = NULL;
        obj->callback_data.callback_arg = NULL;
        obj->irq_cause = CYHAL_UART_IRQ_NONE;

    #if defined (COMPONENT_CAT5)
        Cy_SCB_RegisterInterruptCallback(obj->base, _cyhal_irq_cb[_CYHAL_SCB_IRQ_N[scb_arr_index]]);
        Cy_SCB_EnableInterrupt(obj->base);
    #endif

        #if !defined (COMPONENT_CAT1C)
        _cyhal_irq_register(_CYHAL_SCB_IRQ_N[scb_arr_index], CYHAL_ISR_PRIORITY_DEFAULT, (cy_israddress)_cyhal_uart_irq_handler);
        _cyhal_irq_enable(_CYHAL_SCB_IRQ_N[scb_arr_index]);
        #endif

        _cyhal_scb_update_instance_data(obj->resource.block_num, (void*)obj, &_cyhal_uart_pm_callback_instance);

        Cy_SCB_UART_Enable(obj->base);
    }

    return result;
}

cy_rslt_t cyhal_uart_init(cyhal_uart_t *obj, cyhal_gpio_t tx, cyhal_gpio_t rx, cyhal_gpio_t cts, cyhal_gpio_t rts,
                          const cyhal_clock_t *clk, const cyhal_uart_cfg_t *cfg)
{
    CY_ASSERT(NULL != obj);
    memset(obj, 0, sizeof(cyhal_uart_t));

    obj->dc_configured = false;
    #if (CYHAL_DRIVER_AVAILABLE_DMA)
    obj->async_mode = CYHAL_ASYNC_SW;
    /* resource type used to check if DMAs have been initialized before freeing */
    obj->dma_tx.resource.type = CYHAL_RSC_INVALID;
    obj->dma_rx.resource.type = CYHAL_RSC_INVALID;
    #endif
    obj->baud_rate = CYHAL_UART_DEFAULT_BAUD;
    cy_rslt_t result = _cyhal_uart_setup_resources(obj, tx, rx, cts, rts, clk);

    if (CY_RSLT_SUCCESS == result)
    {
        obj->config = _cyhal_uart_default_config;
        obj->config.enableCts = obj->cts_enabled;

        if (cfg != NULL)
        {
            obj->config.dataWidth = cfg->data_bits;
            obj->config.stopBits = _cyhal_uart_convert_stopbits((uint8_t)cfg->stop_bits);
            obj->config.parity = _cyhal_uart_convert_parity(cfg->parity);
        }

        result = _cyhal_uart_init_hw(obj);
    }

    if (CY_RSLT_SUCCESS == result)
    {
        if ((cfg != NULL) && (cfg->rx_buffer != NULL))
        {
            cyhal_uart_config_software_buffer(obj, cfg->rx_buffer, cfg->rx_buffer_size);
        }

        #if !defined(COMPONENT_CAT5)
        // This was done earlier for CAT5
        if (obj->is_clock_owned)
        {
            result = cyhal_uart_set_baud(obj, obj->baud_rate, NULL);
        }
        #endif

        #if (CYHAL_DRIVER_AVAILABLE_DMA)
        /* Use default FIFO level until user changes it */
        obj->user_fifo_level = (Cy_SCB_GetFifoSize(obj->base) / 2);
        #endif
    }

    if (CY_RSLT_SUCCESS != result)
    {
        cyhal_uart_free(obj);
    }
    return result;
}

cy_rslt_t cyhal_uart_init_cfg(cyhal_uart_t *obj, const cyhal_uart_configurator_t *cfg)
{
    CY_ASSERT(NULL != obj);
    CY_ASSERT(NULL != cfg);
    CY_ASSERT(NULL != cfg->config);
    memset(obj, 0, sizeof(cyhal_uart_t));

    obj->resource = *cfg->resource;
    obj->clock = *cfg->clock;
    obj->is_clock_owned = false;
    obj->pin_tx = cfg->gpios.pin_tx;
    obj->pin_rts = cfg->gpios.pin_rts;
    obj->pin_cts = cfg->gpios.pin_cts;
    obj->dc_configured = true;
    obj->cts_enabled = cfg->config->enableCts;
    obj->rts_enabled = (NC != cfg->gpios.pin_rts);
    #if (CYHAL_DRIVER_AVAILABLE_DMA)
    obj->async_mode = CYHAL_ASYNC_SW;
    obj->dma_tx.resource.type = CYHAL_RSC_INVALID;
    obj->dma_rx.resource.type = CYHAL_RSC_INVALID;
    #endif

    obj->config = *cfg->config;
    cy_rslt_t result = _cyhal_uart_init_hw(obj);

    #if (CYHAL_DRIVER_AVAILABLE_DMA)
    if(result == CY_RSLT_SUCCESS)
    {
        /* Use default FIFO level until user changes it */
        obj->user_fifo_level = (Cy_SCB_GetFifoSize(obj->base) / 2);
    }
    #endif

    return result;
}

void cyhal_uart_free(cyhal_uart_t *obj)
{
    CY_ASSERT(NULL != obj);

    if (NULL != obj->base)
    {
        Cy_SCB_UART_Disable(obj->base, &obj->context);
        Cy_SCB_UART_DeInit(obj->base);
        obj->base = NULL;
    }

    if (obj->resource.type != CYHAL_RSC_INVALID)
    {
        uint8_t scb_arr_index = _cyhal_scb_get_block_index(obj->resource.block_num);
        _cyhal_system_irq_t irqn = _CYHAL_SCB_IRQ_N[scb_arr_index];
        _cyhal_irq_free(irqn);

        _cyhal_scb_update_instance_data(obj->resource.block_num, NULL, NULL);

        if (false == obj->dc_configured)
        {
            cyhal_resource_inst_t rsc_to_free = { CYHAL_RSC_SCB, _cyhal_scb_get_block_index(obj->resource.block_num), obj->resource.channel_num };
            cyhal_hwmgr_free(&(rsc_to_free));
        }

        obj->resource.type = CYHAL_RSC_INVALID;
    }

    if (false == obj->dc_configured)
    {
        _cyhal_utils_release_if_used(&(obj->pin_rx));
        _cyhal_utils_release_if_used(&(obj->pin_tx));
        _cyhal_utils_release_if_used(&(obj->pin_rts));
        _cyhal_utils_release_if_used(&(obj->pin_cts));

        if (obj->is_clock_owned)
        {
            cyhal_clock_free(&(obj->clock));
        }
    }

    #if (CYHAL_DRIVER_AVAILABLE_DMA)
    if(obj->async_mode == CYHAL_ASYNC_DMA)
    {
        if(CYHAL_RSC_INVALID != obj->dma_tx.resource.type)
        {
            cyhal_dma_free(&obj->dma_tx);
            obj->dma_tx.resource.type = CYHAL_RSC_INVALID;
        }
        if(CYHAL_RSC_INVALID != obj->dma_rx.resource.type)
        {
            cyhal_dma_free(&obj->dma_rx);
            obj->dma_rx.resource.type = CYHAL_RSC_INVALID;
        }
    }
    #endif
}

cy_rslt_t cyhal_uart_set_baud(cyhal_uart_t *obj, uint32_t baudrate, uint32_t *actualbaud)
{
    cy_rslt_t status;
    if( obj->baud_rate != baudrate)
    {
        obj->baud_rate = baudrate;
    }
    
    if (obj->is_clock_owned)
    {
        uint8_t oversample_value;
        uint32_t calculated_baud;
        uint32_t divider;

        Cy_SCB_UART_Disable(obj->base, NULL);
        status = cyhal_clock_set_enabled(&(obj->clock), false, false);
        if(status != CY_RSLT_SUCCESS)
        {
            Cy_SCB_UART_Enable(obj->base);
            return status;
        }

        oversample_value = _cyhal_uart_best_oversample(&(obj->resource), baudrate);
        obj->config.oversample = oversample_value;

        divider = _cyhal_utils_divider_value(&(obj->resource), baudrate * oversample_value, 0);
        #if defined(COMPONENT_CAT5)
        if( !_cyhal_clock_is_divider_valid(&(obj->resource),divider))
        {
            Cy_SCB_UART_Enable(obj->base);
            status = CYHAL_UART_RSLT_ERR_UNSUPPORTED_CONFIG;
            return status;
        }
        #endif
        /* Set baud rate */
        #if defined (COMPONENT_CAT5)
        status = _cyhal_utils_peri_pclk_set_freq(0, &(obj->clock), baudrate, oversample_value);
        #else
        status = cyhal_clock_set_divider(&(obj->clock), divider);
        #endif
        if(status != CY_RSLT_SUCCESS)
        {
            cyhal_clock_set_enabled(&(obj->clock), true, false);
            Cy_SCB_UART_Enable(obj->base);
            return status;
        }

        calculated_baud = _cyhal_uart_actual_baud(&(obj->resource), divider, oversample_value);

        if (actualbaud != NULL)
            *actualbaud = calculated_baud;
        uint32_t baud_difference = _cyhal_uart_baud_perdif(baudrate, calculated_baud);
        if (baud_difference > CYHAL_UART_MAX_BAUD_PERCENT_DIFFERENCE)
            status = CY_RSLT_WRN_CSP_UART_BAUD_TOLERANCE;

        status = cyhal_clock_set_enabled(&(obj->clock), true, false);

        /* Configure the UART interface */
        #if (CY_IP_MXSCB_VERSION >= 2) || (CY_IP_MXS22SCB_VERSION >= 1)
        uint32_t mem_width = (obj->config.dataWidth <= CY_SCB_BYTE_WIDTH)
            #if defined(COMPONENT_CAT1) || defined (COMPONENT_CAT5)
            ? CY_SCB_MEM_WIDTH_BYTE : CY_SCB_MEM_WIDTH_HALFWORD;
            #elif defined(COMPONENT_CAT2)
            ? CY_SCB_CTRL_MEM_WIDTH_BYTE : CY_SCB_CTRL_MEM_WIDTH_HALFWORD;
            #endif

        SCB_CTRL(obj->base) = _BOOL2FLD(SCB_CTRL_ADDR_ACCEPT, obj->config.acceptAddrInFifo)     |
                    _BOOL2FLD(SCB_CTRL_MEM_WIDTH, mem_width)                                    |
                    _VAL2FLD(SCB_CTRL_OVS, oversample_value - 1)                                |
                    _VAL2FLD(SCB_CTRL_MODE, CY_SCB_CTRL_MODE_UART);
        #else /* Older versions of the block */
        SCB_CTRL(obj->base) = _BOOL2FLD(SCB_CTRL_ADDR_ACCEPT, obj->config.acceptAddrInFifo)     |
                    _BOOL2FLD(SCB_CTRL_BYTE_MODE, (obj->config.dataWidth <= CY_SCB_BYTE_WIDTH)) |
                    _VAL2FLD(SCB_CTRL_OVS, oversample_value - 1)                                |
                    _VAL2FLD(SCB_CTRL_MODE, CY_SCB_CTRL_MODE_UART);
        #endif

        Cy_SCB_UART_Enable(obj->base);
    }
    else
    {
        /* Not able to make changes in user-provided clock */
        status = CYHAL_UART_RSLT_CLOCK_ERROR;
    }

    return status;
}

cy_rslt_t cyhal_uart_configure(cyhal_uart_t *obj, const cyhal_uart_cfg_t *cfg)
{
    CY_ASSERT(NULL != obj);
    CY_ASSERT(NULL != cfg);
    Cy_SCB_UART_Disable(obj->base, NULL);
    obj->config.dataWidth = cfg->data_bits;
    obj->config.stopBits = _cyhal_uart_convert_stopbits((uint8_t)cfg->stop_bits);
    obj->config.parity = _cyhal_uart_convert_parity(cfg->parity);
    obj->config.enableCts = obj->cts_enabled;
    // Do not pass obj->context here because Cy_SCB_UART_Init will destroy it
    Cy_SCB_UART_Init(obj->base, &(obj->config), NULL);
    Cy_SCB_UART_Enable(obj->base);
    return CY_RSLT_SUCCESS;
}

cy_rslt_t cyhal_uart_getc(cyhal_uart_t *obj, uint8_t *value, uint32_t timeout)
{
    if (_cyhal_scb_pm_transition_pending())
        return CYHAL_SYSPM_RSLT_ERR_PM_PENDING;

    uint32_t read_value = Cy_SCB_UART_Get(obj->base);
    uint32_t timeoutTicks = timeout;
    while (read_value == CY_SCB_UART_RX_NO_DATA)
    {
        if(timeout != 0UL)
        {
            if(timeoutTicks > 0UL)
            {
                cyhal_system_delay_ms(1);
                timeoutTicks--;
            }
            else
            {
                return CY_RSLT_ERR_CSP_UART_GETC_TIMEOUT;
            }
        }
        read_value = Cy_SCB_UART_Get(obj->base);
    }
    *value = (uint8_t)read_value;
    return CY_RSLT_SUCCESS;
}

cy_rslt_t cyhal_uart_putc(cyhal_uart_t *obj, uint32_t value)
{
    if (_cyhal_scb_pm_transition_pending())
        return CYHAL_SYSPM_RSLT_ERR_PM_PENDING;

    uint32_t count = 0;
    while (count == 0)
    {
        count = Cy_SCB_UART_Put(obj->base, value);
    }

    return CY_RSLT_SUCCESS;
}

uint32_t cyhal_uart_readable(cyhal_uart_t *obj)
{
    uint32_t number_available = Cy_SCB_UART_GetNumInRxFifo(obj->base);
    if(obj->context.rxRingBuf != NULL)
    {
        number_available += Cy_SCB_UART_GetNumInRingBuffer(obj->base, &(obj->context));
    }
    return number_available;
}

uint32_t cyhal_uart_writable(cyhal_uart_t *obj)
{
    return Cy_SCB_GetFifoSize(obj->base) - Cy_SCB_GetNumInTxFifo(obj->base);
}

cy_rslt_t cyhal_uart_clear(cyhal_uart_t *obj)
{
    Cy_SCB_UART_ClearRxFifo(obj->base);
    Cy_SCB_UART_ClearTxFifo(obj->base);

    if(obj->context.rxRingBuf != NULL)
    {
        Cy_SCB_UART_ClearRingBuffer(obj->base, &(obj->context));
    }

    return CY_RSLT_SUCCESS;
}

cy_rslt_t cyhal_uart_enable_flow_control(cyhal_uart_t *obj, bool enable_cts, bool enable_rts)
{
    cy_rslt_t result = CY_RSLT_SUCCESS;

    if (obj->pin_cts != NC)
    {
        if (enable_cts && (false == obj->cts_enabled))
        {
            const cyhal_resource_pin_mapping_t *cts_map = _CYHAL_SCB_FIND_MAP_BLOCK(obj->pin_cts, cyhal_pin_map_scb_uart_cts, &obj->resource);
            if (false == obj->dc_configured)
            {
                result = _cyhal_utils_reserve_and_connect(cts_map, (uint8_t)CYHAL_PIN_MAP_DRIVE_MODE_SCB_UART_CTS);
            }
            else
            {
                result = cyhal_connect_pin(cts_map, (uint8_t)CYHAL_PIN_MAP_DRIVE_MODE_SCB_UART_CTS);
            }
            if (CY_RSLT_SUCCESS == result)
            {
                Cy_SCB_UART_EnableCts(obj->base);
                obj->cts_enabled = true;
            }
        }
        else if (!enable_cts)
        {
            if (false == obj->dc_configured)
            {
                _cyhal_utils_disconnect_and_free(obj->pin_cts);
            }
            else
            {
                result = cyhal_disconnect_pin(obj->pin_cts);
            }
            if (CY_RSLT_SUCCESS == result)
            {
                Cy_SCB_UART_DisableCts(obj->base);
                obj->cts_enabled = false;
            }
        }
    }

    if ((CY_RSLT_SUCCESS == result) && (obj->pin_rts != NC))
    {
        if (enable_rts && (false == obj->rts_enabled))
        {
            const cyhal_resource_pin_mapping_t *rts_map = _CYHAL_SCB_FIND_MAP_BLOCK(obj->pin_rts, cyhal_pin_map_scb_uart_rts, &obj->resource);
            if (false == obj->dc_configured)
            {
                result = _cyhal_utils_reserve_and_connect(rts_map, (uint8_t)CYHAL_PIN_MAP_DRIVE_MODE_SCB_UART_RTS);
            }
            else
            {
                result = cyhal_connect_pin(rts_map, (uint8_t)CYHAL_PIN_MAP_DRIVE_MODE_SCB_UART_RTS);
            }
            obj->rts_enabled = (CY_RSLT_SUCCESS == result);
        }
        else if (!enable_rts)
        {
            if (false == obj->dc_configured)
            {
                _cyhal_utils_disconnect_and_free(obj->pin_rts);
            }
            else
            {
                result = cyhal_disconnect_pin(obj->pin_rts);
            }
            if (CY_RSLT_SUCCESS == result)
            {
                obj->rts_enabled = false;
            }
        }
    }

    return result;
}

cy_rslt_t cyhal_uart_write(cyhal_uart_t *obj, void *tx, size_t *tx_length)
{
    if (_cyhal_scb_pm_transition_pending())
        return CYHAL_SYSPM_RSLT_ERR_PM_PENDING;

    *tx_length = Cy_SCB_UART_PutArray(obj->base, tx, *tx_length);

    return CY_RSLT_SUCCESS;
}

cy_rslt_t cyhal_uart_read(cyhal_uart_t *obj, void *rx, size_t *rx_length)
{
    if (_cyhal_scb_pm_transition_pending())
        return CYHAL_SYSPM_RSLT_ERR_PM_PENDING;

    *rx_length = Cy_SCB_UART_GetArray(obj->base, rx, *rx_length);
    return CY_RSLT_SUCCESS;
}

cy_rslt_t cyhal_uart_set_async_mode(cyhal_uart_t *obj, cyhal_async_mode_t mode, uint8_t dma_priority)
{
    CY_ASSERT(NULL != obj);

    if (_cyhal_scb_pm_transition_pending())
        return CYHAL_SYSPM_RSLT_ERR_PM_PENDING;

    #if (CYHAL_DRIVER_AVAILABLE_DMA)
    if((obj->async_tx_buff != NULL) || (obj->async_rx_buff != NULL))
    {
        return CYHAL_DMA_RSLT_ERR_CHANNEL_BUSY;
    }
    #endif

    cy_rslt_t result = CY_RSLT_SUCCESS;

    if(mode == CYHAL_ASYNC_DMA)
    {
    #if (CYHAL_DRIVER_AVAILABLE_DMA)
        if (obj->context.rxRingBuf != NULL)
        {
            return CYHAL_UART_RSLT_ERR_UNSUPPORTED_CONFIG;
        }
        else
        {
            /* Setup DMA for TX */
            if(CYHAL_RSC_INVALID == obj->dma_tx.resource.type && obj->pin_tx != CYHAL_NC_PIN_VALUE)
            {
                cyhal_source_t source_tx;
                cyhal_uart_disable_output(obj, CYHAL_UART_OUTPUT_TRIGGER_TX_FIFO_LEVEL_REACHED);
                cyhal_uart_enable_output(obj, CYHAL_UART_OUTPUT_TRIGGER_TX_FIFO_LEVEL_REACHED, &source_tx);
                cyhal_dma_src_t dma_src_tx =
                {
                    .source = source_tx,
                    .input = CYHAL_DMA_INPUT_TRIGGER_ALL_ELEMENTS,
                };
                /* Set the DMA to correct direction and connect appropriate triggers */
                result = cyhal_dma_init_adv(&(obj->dma_tx), &dma_src_tx, NULL, NULL, dma_priority, CYHAL_DMA_DIRECTION_MEM2PERIPH);
            }
            cyhal_dma_register_callback(&(obj->dma_tx), &_cyhal_uart_dma_handler_tx, obj);

            /* Setup DMA for RX */
            if(CYHAL_RSC_INVALID == obj->dma_rx.resource.type && obj->pin_rx != CYHAL_NC_PIN_VALUE)
            {
                cyhal_source_t source_rx;
                cyhal_uart_disable_output(obj, CYHAL_UART_OUTPUT_TRIGGER_RX_FIFO_LEVEL_REACHED);
                cyhal_uart_enable_output(obj, CYHAL_UART_OUTPUT_TRIGGER_RX_FIFO_LEVEL_REACHED, &source_rx);
                cyhal_dma_src_t dma_src_rx =
                {
                    .source = source_rx,
                    .input = CYHAL_DMA_INPUT_TRIGGER_ALL_ELEMENTS,
                };
                /* Set the DMA to correct direction and connect appropriate triggers */
                cyhal_dma_init_adv(&(obj->dma_rx), &dma_src_rx, NULL, NULL, dma_priority, CYHAL_DMA_DIRECTION_PERIPH2MEM);
            }
            cyhal_dma_register_callback(&(obj->dma_rx), &_cyhal_uart_dma_handler_rx, obj);

            // Default RTS level (20 or 3) may lead to DMA waiting for more data before reading and RTS waiting for data read
            // before allowing more.  Raise RTS to near-max to ensure DMA runs smoothest
            Cy_SCB_UART_SetRtsFifoLevel(obj->base, Cy_SCB_GetFifoSize(obj->base) - 1);
        }
    #else
        CY_UNUSED_PARAMETER(obj);
        CY_UNUSED_PARAMETER(dma_priority);
        result = CYHAL_UART_RSLT_ERR_UNSUPPORTED_OPERATION; // DMA not supported
    #endif
    }
    else
    {
    #if (CYHAL_DRIVER_AVAILABLE_DMA)
        /* Free the DMA instances if we reserved them but don't need them anymore */
        if(CYHAL_RSC_INVALID != obj->dma_tx.resource.type)
        {
            cyhal_dma_free(&obj->dma_tx);
            obj->dma_tx.resource.type = CYHAL_RSC_INVALID;
        }
        if(CYHAL_RSC_INVALID != obj->dma_rx.resource.type)
        {
            cyhal_dma_free(&obj->dma_rx);
            obj->dma_rx.resource.type = CYHAL_RSC_INVALID;
        }

        // Restore RTS values for SW mode.  Values taken from _cyhal_uart_default_config
        Cy_SCB_UART_SetRtsFifoLevel(obj->base, _cyhal_uart_default_config.rtsRxFifoLevel);
    #endif
    }

    #if (CYHAL_DRIVER_AVAILABLE_DMA)
    if(CY_RSLT_SUCCESS == result)
    {
        obj->async_mode = mode;
    }
    #endif
    return result;
}

#if (CYHAL_DRIVER_AVAILABLE_DMA)
cy_rslt_t _cyhal_uart_dma_write_async(cyhal_uart_t *obj)
{
    if(cyhal_dma_is_busy(&(obj->dma_tx)))
    {
        return CYHAL_DMA_RSLT_ERR_CHANNEL_BUSY;
    }

    CY_ASSERT(NULL != obj->async_tx_buff);

    /* If tranfer exceeds FIFO level, break into many small transfers */
    uint32_t length = obj->async_tx_length;
    if(length >= Cy_SCB_GetFifoSize(obj->base))
    {
        length = (Cy_SCB_GetFifoSize(obj->base) / 2);
    }

    uint32_t mem_width = (obj->config.dataWidth <= CY_SCB_BYTE_WIDTH) ? 8 : 16;
    cyhal_dma_cfg_t dma_config =
    {
        .src_addr = (uint32_t)obj->async_tx_buff,
        .src_increment = 1,
        .dst_addr = (uint32_t)&obj->base->TX_FIFO_WR,
        .dst_increment = 0,
        .length = length,
        .transfer_width = mem_width,
        .burst_size = 0,
        .action = CYHAL_DMA_TRANSFER_FULL_DISABLE,
    };

    /* Move next src up and keep track of how much data has already been sent */
    uint32_t savedIntrStatus = cyhal_system_critical_section_enter();
    obj->async_tx_buff = ((length * (mem_width / 8)) + (char*)obj->async_tx_buff);
    obj->async_tx_length -= length;
    cyhal_system_critical_section_exit(savedIntrStatus);

    /* Transmit once UART is full */
    cy_rslt_t result = cyhal_uart_set_fifo_level(obj, CYHAL_UART_FIFO_TX, Cy_SCB_GetFifoSize(obj->base) - length);
    if(result == CY_RSLT_SUCCESS)
    {
        cyhal_dma_enable_event(&(obj->dma_tx), CYHAL_DMA_TRANSFER_COMPLETE, CYHAL_DMA_PRIORITY_DEFAULT, true);
        #if defined(CY_IP_M4CPUSS_DMA) || defined(CY_IP_M7CPUSS_DMA) || defined(CY_IP_MXDW)
        obj->dma_tx.descriptor_config.dw.retrigger = CY_DMA_WAIT_FOR_REACT;
        #endif
        result = cyhal_dma_configure(&(obj->dma_tx), &dma_config);
    }

    #if defined (__DCACHE_PRESENT) && (__DCACHE_PRESENT == 1U)
    SCB_CleanDCache_by_Addr((void *)obj->async_tx_buff, (length * (mem_width / 8)));
    #endif /* defined (__DCACHE_PRESENT) && (__DCACHE_PRESENT == 1U) */

    if(result == CY_RSLT_SUCCESS)
    {
        result = cyhal_dma_enable(&(obj->dma_tx));
    }
    return result;
}
#endif

cy_rslt_t cyhal_uart_write_async(cyhal_uart_t *obj, void *tx, size_t length)
{
    if (_cyhal_scb_pm_transition_pending())
        return CYHAL_SYSPM_RSLT_ERR_PM_PENDING;

    cy_rslt_t result;
    #if (CYHAL_DRIVER_AVAILABLE_DMA)
    if(obj->async_mode == CYHAL_ASYNC_DMA)
    {
        uint32_t savedIntrStatus = cyhal_system_critical_section_enter();
        obj->async_tx_buff = tx;
        obj->async_tx_length = length;
        result = _cyhal_uart_dma_write_async(obj);
        cyhal_system_critical_section_exit(savedIntrStatus);
    }
    else
    #endif
    {
        result = Cy_SCB_UART_Transmit(obj->base, tx, length, &(obj->context));
    }
    return result;
}

#if (CYHAL_DRIVER_AVAILABLE_DMA)
cy_rslt_t _cyhal_uart_dma_read_async(cyhal_uart_t *obj)
{
    if(cyhal_dma_is_busy(&(obj->dma_rx)))
    {
        return CYHAL_DMA_RSLT_ERR_CHANNEL_BUSY;
    }

    CY_ASSERT(NULL != obj->async_rx_buff);

    /* If tranfer exceeds FIFO size, break into many small transfers */
    uint32_t length = obj->async_rx_length;
    if(length >= Cy_SCB_GetFifoSize(obj->base))
    {
        length = (Cy_SCB_GetFifoSize(obj->base) / 2);
    }

    uint32_t mem_width = (obj->config.dataWidth <= CY_SCB_BYTE_WIDTH) ? 8 : 16;
    cyhal_dma_cfg_t dma_config =
    {
        .src_addr = (uint32_t)(&(obj->base->RX_FIFO_RD)),
        .src_increment = 0,
        .dst_addr = (uint32_t)obj->async_rx_buff,
        .dst_increment = 1,
        .length = length,
        .transfer_width = mem_width,
        .burst_size = 0,
        .action = CYHAL_DMA_TRANSFER_FULL_DISABLE,
    };

    /* Move next src up and keep track of how much data has already been sent */
    uint32_t savedIntrStatus = cyhal_system_critical_section_enter();
    obj->async_rx_buff = ((length * (mem_width / 8)) + (char*)obj->async_rx_buff);
    obj->async_rx_length -= length;
    cyhal_system_critical_section_exit(savedIntrStatus);

    /* Read once UART is full */
    cy_rslt_t result = CY_RSLT_SUCCESS;
    result = _cyhal_scb_set_fifo_level(obj->base, (cyhal_scb_fifo_type_t)CYHAL_UART_FIFO_RX, length - 1);
    if(result == CY_RSLT_SUCCESS)
    {
        cyhal_dma_enable_event(&(obj->dma_rx), CYHAL_DMA_TRANSFER_COMPLETE, CYHAL_DMA_PRIORITY_DEFAULT, true);
        #if defined(CY_IP_M4CPUSS_DMA) || defined(CY_IP_M7CPUSS_DMA) || defined(CY_IP_MXDW)
        obj->dma_tx.descriptor_config.dw.retrigger = CY_DMA_WAIT_FOR_REACT;
        #endif
        result = cyhal_dma_configure(&(obj->dma_rx), &dma_config);
    }

    #if defined (__DCACHE_PRESENT) && (__DCACHE_PRESENT == 1U)
    SCB_InvalidateDCache_by_Addr((void *)obj->async_rx_buff, (length * (mem_width / 8)));
    #endif /* defined (__DCACHE_PRESENT) && (__DCACHE_PRESENT == 1U) */

    if(result == CY_RSLT_SUCCESS)
    {
        result = cyhal_dma_enable(&(obj->dma_rx));
    }

    return result;
}
#endif

cy_rslt_t cyhal_uart_read_async(cyhal_uart_t *obj, void *rx, size_t length)
{
    if (_cyhal_scb_pm_transition_pending())
        return CYHAL_SYSPM_RSLT_ERR_PM_PENDING;

    cy_rslt_t result = CY_RSLT_SUCCESS;
    #if (CYHAL_DRIVER_AVAILABLE_DMA)
    if(obj->async_mode == CYHAL_ASYNC_DMA)
    {
        uint32_t savedIntrStatus = cyhal_system_critical_section_enter();
        obj->async_rx_buff = rx;
        obj->async_rx_length = length;
        cyhal_system_critical_section_exit(savedIntrStatus);

        result = _cyhal_uart_dma_read_async(obj);
    }
    else
    #endif
    {
        result = Cy_SCB_UART_Receive(obj->base, rx, length, &(obj->context));
    }
    return result;
}

bool cyhal_uart_is_tx_active(cyhal_uart_t *obj)
{
    return (0UL != (obj->context.txStatus & CY_SCB_UART_TRANSMIT_ACTIVE)) || !Cy_SCB_IsTxComplete(obj->base)
    #if (CYHAL_DRIVER_AVAILABLE_DMA)
            || (obj->async_tx_buff != NULL)
    #endif
            ;
}

bool cyhal_uart_is_rx_active(cyhal_uart_t *obj)
{
    return (0UL != (obj->context.rxStatus & CY_SCB_UART_RECEIVE_ACTIVE))
    #if (CYHAL_DRIVER_AVAILABLE_DMA)
            || (obj->async_rx_buff != NULL)
    #endif
            ;
}

cy_rslt_t cyhal_uart_write_abort(cyhal_uart_t *obj)
{
    #if (CYHAL_DRIVER_AVAILABLE_DMA)
    if(obj->async_mode == CYHAL_ASYNC_DMA && (obj->async_tx_buff != NULL))
    {
        uint32_t savedIntrStatus = cyhal_system_critical_section_enter();
        obj->async_tx_buff = NULL;
        cyhal_dma_enable_event(&(obj->dma_tx), CYHAL_DMA_TRANSFER_COMPLETE, CYHAL_DMA_PRIORITY_DEFAULT, false);
        cyhal_dma_disable(&(obj->dma_tx));
        cyhal_system_critical_section_exit(savedIntrStatus);
        Cy_SCB_UART_ClearTxFifo(obj->base);
    }
    else
    #endif
    {
        Cy_SCB_UART_AbortTransmit(obj->base, &(obj->context));
    }
    return CY_RSLT_SUCCESS;
}

cy_rslt_t cyhal_uart_read_abort(cyhal_uart_t *obj)
{
    #if (CYHAL_DRIVER_AVAILABLE_DMA)
    if(obj->async_mode == CYHAL_ASYNC_DMA && (obj->async_rx_buff != NULL))
    {
        uint32_t savedIntrStatus = cyhal_system_critical_section_enter();
        obj->async_rx_buff = NULL;
        cyhal_dma_enable_event(&(obj->dma_rx), CYHAL_DMA_TRANSFER_COMPLETE, CYHAL_DMA_PRIORITY_DEFAULT, false);
        cyhal_dma_disable(&(obj->dma_rx));
        cyhal_system_critical_section_exit(savedIntrStatus);
    }
    else
    #endif
    {
        Cy_SCB_UART_AbortReceive(obj->base, &(obj->context));
    }
    return CY_RSLT_SUCCESS;
}

void cyhal_uart_register_callback(cyhal_uart_t *obj, cyhal_uart_event_callback_t callback, void *callback_arg)
{
    uint32_t savedIntrStatus = cyhal_system_critical_section_enter();
    obj->callback_data.callback = (cy_israddress) callback;
    obj->callback_data.callback_arg = callback_arg;
    cyhal_system_critical_section_exit(savedIntrStatus);
    Cy_SCB_UART_RegisterCallback(obj->base, _cyhal_uart_cb_wrapper, &(obj->context));

    obj->irq_cause = CYHAL_UART_IRQ_NONE;
}

void cyhal_uart_enable_event(cyhal_uart_t *obj, cyhal_uart_event_t event, uint8_t intr_priority, bool enable)
{
    uint8_t scb_arr_index = _cyhal_scb_get_block_index(obj->resource.block_num);
    #if defined(COMPONENT_CAT5)
    Cy_SCB_DisableInterrupt(obj->base);
    #else
    _cyhal_irq_disable(_CYHAL_SCB_IRQ_N[scb_arr_index]);
    _cyhal_irq_clear_pending(_CYHAL_SCB_IRQ_N[scb_arr_index]);
    #endif

    if (enable)
    {
        obj->irq_cause |= event;
        if (event & CYHAL_UART_IRQ_TX_EMPTY)
        {
            Cy_SCB_ClearTxInterrupt(obj->base, CY_SCB_UART_TX_EMPTY);
            Cy_SCB_SetTxInterruptMask(obj->base, Cy_SCB_GetTxInterruptMask(obj->base) | CY_SCB_UART_TX_EMPTY);
        }
        if (event & CYHAL_UART_IRQ_TX_DONE)
        {
            Cy_SCB_ClearTxInterrupt(obj->base, CY_SCB_UART_TX_DONE);
            Cy_SCB_SetTxInterruptMask(obj->base, Cy_SCB_GetTxInterruptMask(obj->base) | CY_SCB_UART_TX_DONE);
        }
        if (event & CYHAL_UART_IRQ_TX_ERROR)
        {
            // Omit underflow condition as the interrupt perpetually triggers
            //Standard mode only uses OVERFLOW irq
            if(obj->config.uartMode == CY_SCB_UART_STANDARD)
            {
                Cy_SCB_ClearTxInterrupt(obj->base, (CY_SCB_UART_TX_OVERFLOW | CY_SCB_UART_TRANSMIT_ERR));
                Cy_SCB_SetTxInterruptMask(obj->base, Cy_SCB_GetTxInterruptMask(obj->base) | (CY_SCB_UART_TX_OVERFLOW | CY_SCB_UART_TRANSMIT_ERR));
            }
            //SMARTCARD mode uses OVERFLOW, NACK, and ARB_LOST irq's
            else if(obj->config.uartMode == CY_SCB_UART_SMARTCARD)
            {
                Cy_SCB_ClearTxInterrupt(obj->base, (CY_SCB_UART_TX_OVERFLOW | CY_SCB_TX_INTR_UART_NACK | CY_SCB_TX_INTR_UART_ARB_LOST | CY_SCB_UART_TRANSMIT_ERR));
                Cy_SCB_SetTxInterruptMask(obj->base, Cy_SCB_GetTxInterruptMask(obj->base) | (CY_SCB_UART_TX_OVERFLOW | CY_SCB_TX_INTR_UART_NACK | CY_SCB_TX_INTR_UART_ARB_LOST | CY_SCB_UART_TRANSMIT_ERR));
            }
            //LIN Mode only uses OVERFLOW, ARB_LOST irq's
            else
            {
                Cy_SCB_ClearTxInterrupt(obj->base, (CY_SCB_UART_TX_OVERFLOW | CY_SCB_TX_INTR_UART_ARB_LOST | CY_SCB_UART_TRANSMIT_ERR));
                Cy_SCB_SetTxInterruptMask(obj->base, Cy_SCB_GetTxInterruptMask(obj->base) | (CY_SCB_UART_TX_OVERFLOW | CY_SCB_TX_INTR_UART_ARB_LOST | CY_SCB_UART_TRANSMIT_ERR));
            }
        }
        if (event & CYHAL_UART_IRQ_TX_FIFO)
        {
            Cy_SCB_ClearTxInterrupt(obj->base, CY_SCB_UART_TX_TRIGGER);
            Cy_SCB_SetTxInterruptMask(obj->base, Cy_SCB_GetTxInterruptMask(obj->base) | CY_SCB_UART_TX_TRIGGER);
        }

        if (event & CYHAL_UART_IRQ_RX_NOT_EMPTY)
        {
            Cy_SCB_ClearRxInterrupt(obj->base, CY_SCB_UART_RX_NOT_EMPTY);
            Cy_SCB_SetRxInterruptMask(obj->base, Cy_SCB_GetRxInterruptMask(obj->base) | CY_SCB_UART_RX_NOT_EMPTY);
        }
        if (event & CYHAL_UART_IRQ_RX_ERROR)
        {
            // Omit underflow condition as the interrupt perpetually triggers.
            Cy_SCB_ClearRxInterrupt(obj->base, CY_SCB_UART_RECEIVE_ERR);
            Cy_SCB_SetRxInterruptMask(obj->base, Cy_SCB_GetRxInterruptMask(obj->base) | CY_SCB_UART_RECEIVE_ERR);
        }
        if (event & CYHAL_UART_IRQ_RX_FIFO)
        {
            Cy_SCB_ClearRxInterrupt(obj->base, CY_SCB_UART_RX_TRIGGER);
            Cy_SCB_SetRxInterruptMask(obj->base, Cy_SCB_GetRxInterruptMask(obj->base) | CY_SCB_UART_RX_TRIGGER);
        }
    }
    else
    {
        obj->irq_cause &= ~event;
        if (event & CYHAL_UART_IRQ_TX_EMPTY)
        {
            Cy_SCB_SetTxInterruptMask(obj->base, Cy_SCB_GetTxInterruptMask(obj->base) & ~CY_SCB_UART_TX_EMPTY);
        }
        if (event & CYHAL_UART_IRQ_TX_DONE)
        {
            Cy_SCB_SetTxInterruptMask(obj->base, Cy_SCB_GetTxInterruptMask(obj->base) & ~CY_SCB_UART_TX_DONE);
        }
        if (event & CYHAL_UART_IRQ_TX_ERROR)
        {
            Cy_SCB_SetTxInterruptMask(obj->base, Cy_SCB_GetTxInterruptMask(obj->base) & ~(CY_SCB_UART_TX_OVERFLOW | CY_SCB_UART_TRANSMIT_ERR));
        }
        if (event & CYHAL_UART_IRQ_TX_FIFO)
        {
            Cy_SCB_SetTxInterruptMask(obj->base, Cy_SCB_GetTxInterruptMask(obj->base) & ~CY_SCB_UART_TX_TRIGGER);
        }

        if (event & CYHAL_UART_IRQ_RX_NOT_EMPTY)
        {
            Cy_SCB_SetRxInterruptMask(obj->base, Cy_SCB_GetRxInterruptMask(obj->base) & ~CY_SCB_UART_RX_NOT_EMPTY);
        }
        if (event & CYHAL_UART_IRQ_RX_ERROR)
        {
            Cy_SCB_SetRxInterruptMask(obj->base, Cy_SCB_GetRxInterruptMask(obj->base) & ~CY_SCB_UART_RECEIVE_ERR);
        }
        if (event & CYHAL_UART_IRQ_RX_FIFO)
        {
            Cy_SCB_SetRxInterruptMask(obj->base, Cy_SCB_GetRxInterruptMask(obj->base) & ~CY_SCB_UART_RX_TRIGGER);
        }
    }

    if (event & CYHAL_UART_IRQ_TX_TRANSMIT_IN_FIFO)
    {
        /* This is a software event only. It is only applicable for cyhal_uart_write_async() */
    }
    if (event & CYHAL_UART_IRQ_RX_FULL)
    {
        /* This is a software event only. It is only applicable when using rx software buffer */
    }
    if (event & CYHAL_UART_IRQ_RX_DONE)
    {
        /* This is a software event only. It is only applicable for cyhal_uart_read_async() */
    }
    if (event == CYHAL_UART_IRQ_NONE)
    {
        /* "No interrupt" is equivalent for both "enable" and "disable" */
        Cy_SCB_ClearRxInterrupt(obj->base, CY_SCB_RX_INTR_MASK);
        Cy_SCB_ClearTxInterrupt(obj->base, CY_SCB_TX_INTR_MASK);
        Cy_SCB_SetRxInterruptMask(obj->base, Cy_SCB_GetRxInterruptMask(obj->base) & ~CY_SCB_RX_INTR_MASK);
        Cy_SCB_SetTxInterruptMask(obj->base, Cy_SCB_GetTxInterruptMask(obj->base) & ~CY_SCB_TX_INTR_MASK);
    }

    #if !defined (COMPONENT_CAT1C)
    _cyhal_irq_set_priority(_CYHAL_SCB_IRQ_N[scb_arr_index], intr_priority);
    #endif
    _cyhal_irq_enable(_CYHAL_SCB_IRQ_N[scb_arr_index]);
    #if defined(COMPONENT_CAT5)
    // The above Cy_SCB_DisableInterrupt also disconnects all the callback functions. They need to be registered again
    Cy_SCB_RegisterInterruptCallback(obj->base, _cyhal_irq_cb[_CYHAL_SCB_IRQ_N[scb_arr_index]]);
    Cy_SCB_EnableInterrupt(obj->base);
    #endif
}

cy_rslt_t cyhal_uart_set_fifo_level(cyhal_uart_t *obj, cyhal_uart_fifo_type_t type, uint16_t level)
{
    cy_rslt_t result = _cyhal_scb_set_fifo_level(obj->base, (cyhal_scb_fifo_type_t)type, level);
    #if (CYHAL_DRIVER_AVAILABLE_DMA)
    // Note: Because of this, it is important that any internal FIFO level setting is done via the above command directly
    if(result == CY_RSLT_SUCCESS)
    {
        obj->user_fifo_level = level;
    }
    #endif
    return result;
}

cy_rslt_t cyhal_uart_enable_output(cyhal_uart_t *obj, cyhal_uart_output_t output, cyhal_source_t *source)
{
    return _cyhal_scb_enable_output(obj->resource, (cyhal_scb_output_t)output, source);
}

cy_rslt_t cyhal_uart_disable_output(cyhal_uart_t *obj, cyhal_uart_output_t output)
{
    CY_UNUSED_PARAMETER(obj);
    return _cyhal_scb_disable_output((cyhal_scb_output_t)output);
}

cy_rslt_t cyhal_uart_config_software_buffer(cyhal_uart_t *obj, uint8_t *rx_buffer, uint32_t rx_buffer_size)
{
    cy_rslt_t result = CY_RSLT_SUCCESS;
    CY_ASSERT(NULL != obj);
    CY_ASSERT(NULL != rx_buffer);

#if (CYHAL_DRIVER_AVAILABLE_DMA)
    if(obj->async_mode == CYHAL_ASYNC_DMA)
    {
        result =  CYHAL_UART_RSLT_ERR_UNSUPPORTED_CONFIG;
    }
    else
#endif
    {

        Cy_SCB_UART_StartRingBuffer(obj->base, rx_buffer, rx_buffer_size, &(obj->context));
    }

    return result;
}

#if defined(__cplusplus)
}
#endif

#endif /* CYHAL_DRIVER_AVAILABLE_UART */
