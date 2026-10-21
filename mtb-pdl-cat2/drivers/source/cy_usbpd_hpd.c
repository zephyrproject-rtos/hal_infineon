/***************************************************************************//**
* \file cy_usbpd_hpd.c
* \version 2.110
*
* The source file of the USBPD Hot-Plug Detect driver.
*
********************************************************************************
* \copyright
* (c) (2021-2025), Cypress Semiconductor Corporation (an Infineon company) or
* an affiliate of Cypress Semiconductor Corporation.
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
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either expressed or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

#include "cy_device.h"
#include "cy_device_headers.h"

#if (defined(CY_IP_MXUSBPD) || defined(CY_IP_M0S8USBPD))

#include "cy_usbpd_common.h"
#include "cy_usbpd_hpd.h"
#include "cy_gpio.h"

/*******************************************************************************
* Function Name: Cy_USBPD_Hpd_ReceiveInit
****************************************************************************//**
*
* Enables the HPD-Receive functionality for the specified PD port based on passed context.
* This function shall be used in DP Sink designs and should not be combined
* with the Cy_USBPD_Hpd_TransmitInit call.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \param cbk
* Callback function to be called when there is an HPD event.
*
* \return
* \ref cy_en_usbpd_status_t
*
*******************************************************************************/
cy_en_usbpd_status_t Cy_USBPD_Hpd_ReceiveInit(cy_stc_usbpd_context_t *context, cy_cb_usbpd_hpd_events_t cbk)
{
    PPDSS_REGS_T pd = context->base;
    uint32_t dummy = 0;

    if (cbk == NULL)
    {
        return CY_USBPD_STAT_BAD_PARAM;
    }

    if ((context->hpdTransmitEnable) || (context->hpdReceiveEnable))
    {
        return CY_USBPD_STAT_BUSY;
    }

    /* PD block should have been enabled. */
    if ((pd->ctrl & PDSS_CTRL_IP_ENABLED) == 0UL)
    {
        return CY_USBPD_STAT_NOT_READY;
    }

    /* Store the callback pointer. */
    context->hpdCbk = cbk;
    context->hpdReceiveEnable = true;

    /* Configure the relevant GPIO for HPD functionality. */
    if (context->port == 0U)
    {
        Cy_GPIO_SetDrivemode(Cy_GPIO_PortToAddr(HPD_P0_PORT_PIN >> 4),
                (HPD_P0_PORT_PIN & 0x0Fu), CY_GPIO_DM_HIGHZ);
        Cy_GPIO_SetHSIOM(Cy_GPIO_PortToAddr(HPD_P0_PORT_PIN >> 4),
                (HPD_P0_PORT_PIN & 0x0Fu), (en_hsiom_sel_t)HPD_HSIOM_SETTING_P0);
    }
    else
    {
        Cy_GPIO_SetDrivemode(Cy_GPIO_PortToAddr(HPD_P1_PORT_PIN >> 4),
                (HPD_P1_PORT_PIN & 0x0Fu), CY_GPIO_DM_HIGHZ);
        Cy_GPIO_SetHSIOM(Cy_GPIO_PortToAddr(HPD_P1_PORT_PIN >> 4),
                (HPD_P1_PORT_PIN & 0x0Fu), (en_hsiom_sel_t)HPD_HSIOM_SETTING_P1);
    }

    /* Set the default values for the HPD config settings. */
    pd->hpd_ctrl1 = PDSS_HPD_CTRL1_DEFAULT_VALUE;
    pd->hpd_ctrl2 = PDSS_HPD_CTRL2_DEFAULT;
    pd->hpd_ctrl3 = PDSS_HPD_CTRL3_DEFAULT_VALUE;
    pd->hpd_ctrl4 = PDSS_HPD_CTRL4_DEFAULT;
    pd->hpd_ctrl5 = PDSS_HPD_CTRL5_DEFAULT;

    /* Reading the register empties the queue. */
    dummy = pd->hpd_queue;

    /* Enable the HPD queue interrupt. */
    pd->intr2 = PDSS_INTR2_MASK_HPD_QUEUE_MASK;
    pd->intr2_mask |= PDSS_INTR2_MASK_HPD_QUEUE_MASK;

#if (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG6DF_CFP) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S))
    pd->intr1_cfg |= (3UL << PDSS_INTR1_CFG_HPDIN_CFG_POS);
    /* Disable HPD IN filter. */
    pd->intr1_cfg &= ~(PDSS_INTR1_CFG_HPDIN_FILT_EN);
    /* Bypass filter. */
    pd->intr1_cfg |= (PDSS_INTR1_CFG_HPDIN_FILT_BYPASS);
#endif /* (defined(CY_DEVICE_CCG6) || defined(CY_DEVICE_PMG1S3) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S)) */

#if defined(CY_DEVICE_CCG3)
    pd->intr_1_cfg |= (3UL << PDSS_INTR_1_CFG_HPDIN_CFG_POS);
    /* Disable HPD IN filter. */
    pd->intr_1_cfg &= ~(PDSS_INTR_1_CFG_HPDIN_FILT_EN);
#endif /* defined(CY_DEVICE_CCG3) */

    /* Clear and then enable the interrupt. */
    pd->intr1 = PDSS_INTR1_HPDIN_CHANGED;
    pd->intr1_mask |= PDSS_INTR1_HPDIN_CHANGED;

    /* Enable the HPD function and the bring the HPD receiver out of reset. */
    pd->ctrl = (pd->ctrl & ~(PDSS_CTRL_HPD_DIRECTION | PDSS_CTRL_HPDT_ENABLED)) |
        PDSS_CTRL_HPD_ENABLED;
    pd->hpd_ctrl1 &= ~(PDSS_HPD_CTRL1_RESET_HPD_STATE);

    /* If HPD line state goes high before initializing the HPD receiver block,
     * then set the HPD input change interrupt.
     */
    if(Cy_USBPD_Hpd_ReceiveGetStatus(context))
    {
        pd->intr1_set |= PDSS_INTR1_HPDIN_CHANGED;
    }

    CY_UNUSED_PARAMETER(dummy);
    return CY_USBPD_STAT_SUCCESS;
}


/*******************************************************************************
* Function Name: Cy_USBPD_Hpd_TransmitInit
****************************************************************************//**
*
* Enables the HPD-Transmit functionality for the specified PD port.
* This function shall be used in DP source designs and should not be combined
* with the Cy_USBPD_Hpd_ReceiveInit call.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \param cbk
* Callback function to be used for command completion event.
*
* \return
* \ref cy_en_usbpd_status_t
*
*******************************************************************************/
cy_en_usbpd_status_t Cy_USBPD_Hpd_TransmitInit(cy_stc_usbpd_context_t *context, cy_cb_usbpd_hpd_events_t cbk)
{
    PPDSS_REGS_T pd = context->base;
    if (context->hpdTransmitEnable || context->hpdReceiveEnable)
    {
        return CY_USBPD_STAT_BUSY;
    }

    /* Store the callback pointer. */
    context->hpdCbk = cbk;
    context->hpdTransmitEnable = true;

    /* Configure the relevant GPIO for HPD functionality. */
    if (context->port == 0U)
    {
        Cy_GPIO_SetDrivemode(Cy_GPIO_PortToAddr(HPD_P0_PORT_PIN >> 4),
                (HPD_P0_PORT_PIN & 0x0Fu), CY_GPIO_DM_STRONG);
        Cy_GPIO_SetHSIOM(Cy_GPIO_PortToAddr(HPD_P0_PORT_PIN >> 4),
                (HPD_P0_PORT_PIN & 0x0Fu), (en_hsiom_sel_t)HPD_HSIOM_SETTING_P0);
    }
    else
    {
        Cy_GPIO_SetDrivemode(Cy_GPIO_PortToAddr(HPD_P1_PORT_PIN >> 4),
                (HPD_P1_PORT_PIN & 0x0Fu), CY_GPIO_DM_STRONG);
        Cy_GPIO_SetHSIOM(Cy_GPIO_PortToAddr(HPD_P1_PORT_PIN >> 4),
                (HPD_P1_PORT_PIN & 0x0Fu), (en_hsiom_sel_t)HPD_HSIOM_SETTING_P1);
    }

    /* Set the default values for the HPDT config settings. */
    pd->hpdt_ctrl1 = PDSS_HPDT_CTRL1_DEFAULT;
#if defined(CY_DEVICE_PMG1S3)
    pd->hpdt_ctrl2 = PDSS_HPDT_CTRL2_DEFAULT_VALUE;
#else
    pd->hpdt_ctrl2 = PDSS_HPDT_CTRL2_DEFAULT;
#endif /* defined(CY_DEVICE_PMG1S3) */

    /* Enable the HPD queue interrupt. */
    pd->intr2 = PDSS_INTR2_MASK_HPDT_COMMAND_DONE_MASK;
    pd->intr2_mask |= PDSS_INTR2_MASK_HPDT_COMMAND_DONE_MASK;

    /* Enable the HPDT function and the bring the HPD transmitter out of reset. */
    pd->ctrl = (pd->ctrl & ~(PDSS_CTRL_HPD_ENABLED)) |
        PDSS_CTRL_HPDT_ENABLED | PDSS_CTRL_HPD_DIRECTION;
    pd->hpdt_ctrl1 &= ~(PDSS_HPDT_CTRL1_RESET_HPDT_STATE);

    return CY_USBPD_STAT_SUCCESS;
}


/*******************************************************************************
* Function Name: Cy_USBPD_Hpd_SleepEntry
****************************************************************************//**
*
* Prepares the HPD transmit block for deep-sleep. This function changes
* the IO mode of the HPD signal to GPIO, so as to avoid glitches on the signal
* during the active - sleep - active power mode transitions of the device.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \return
* None
*
*******************************************************************************/
void Cy_USBPD_Hpd_SleepEntry(cy_stc_usbpd_context_t *context)
{
#if (defined(CY_DEVICE_CCG3) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S))
    /* Configure the relevant pin for GPIO functionality. */
    if (context->hpdTransmitEnable)
    {
        if (context->port == 0U)
        {
            Cy_GPIO_SetHSIOM(Cy_GPIO_PortToAddr(HPD_P0_PORT_PIN >> 4), (HPD_P0_PORT_PIN & 0x0Fu), (en_hsiom_sel_t)HSIOM_SEL_GPIO);
        }
        else
        {
            Cy_GPIO_SetHSIOM(Cy_GPIO_PortToAddr(HPD_P1_PORT_PIN >> 4), (HPD_P1_PORT_PIN & 0x0Fu), (en_hsiom_sel_t)HSIOM_SEL_GPIO);
        }
    }
#else
    CY_UNUSED_PARAMETER(context);
#endif /* (defined(CY_DEVICE_CCG3) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S)) */
}


/*******************************************************************************
* Function Name: Cy_USBPD_Hpd_Wakeup
****************************************************************************//**
*
* Restores the HPD Tx signal driver after device wakes up from deep-sleep.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \param value
* Startup value for the HPD signal. The APP layer is expected
* to identify the desired (PLUG/UNPLUG) state of the signal and pass it to
* the PDL.
* 
* \return
* None

*******************************************************************************/
void Cy_USBPD_Hpd_Wakeup(cy_stc_usbpd_context_t *context, bool value)
{
#if (defined(CY_DEVICE_CCG3) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S))
    PPDSS_REGS_T pd = context->base;

    /* Configure the relevant GPIO for HPD functionality. */
    if (context->hpdTransmitEnable)
    {
        /* Set the default values for the HPDT config settings. */
        if (value)
        {
            /* Start HPD off in the high state and queue a PLUG event. */
            pd->hpdt_ctrl1 = PDSS_HPDT_CTRL1_DEFAULT | PDSS_HPDT_CTRL1_DEFAULT_LEVEL;
#if defined(CY_DEVICE_PMG1S3)
            pd->hpdt_ctrl2 = PDSS_HPDT_CTRL2_DEFAULT_VALUE;
#else
            pd->hpdt_ctrl2 = PDSS_HPDT_CTRL2_DEFAULT;
#endif /* defined(CY_DEVICE_PMG1S3) */
        }
        else
        {
            /* Start HPD off in the low state. */
            pd->hpdt_ctrl1 = PDSS_HPDT_CTRL1_DEFAULT;
#if defined(CY_DEVICE_PMG1S3)
            pd->hpdt_ctrl2 = PDSS_HPDT_CTRL2_DEFAULT_VALUE;
#else
            pd->hpdt_ctrl2 = PDSS_HPDT_CTRL2_DEFAULT;
#endif /* defined(CY_DEVICE_PMG1S3) */
        }

        /*
         * Bring the HPDT block out of reset. We need a small delay here to
         * ensure that there is no glitch on the HPD line.
         */
        Cy_SysLib_DelayUs(5);
        pd->hpdt_ctrl1 &= ~(PDSS_HPDT_CTRL1_RESET_HPDT_STATE);

        if (context->port == 0U)
        {
            Cy_GPIO_SetHSIOM(Cy_GPIO_PortToAddr(HPD_P0_PORT_PIN >> 4), (HPD_P0_PORT_PIN & 0x0Fu), (en_hsiom_sel_t)HPD_HSIOM_SETTING_P0);
        }
        else
        {
            Cy_GPIO_SetHSIOM(Cy_GPIO_PortToAddr(HPD_P1_PORT_PIN >> 4), (HPD_P1_PORT_PIN & 0x0Fu), (en_hsiom_sel_t)HPD_HSIOM_SETTING_P1);
        }
    }
#else
    CY_UNUSED_PARAMETER(context);
    CY_UNUSED_PARAMETER(value);
#endif /* (defined(CY_DEVICE_CCG3) || defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S)) */
}

/*
* This reads the level of HPD input from GPIO.
*/
#define PDSS_STATUS_HPD_STATUS (1UL << 24) /* <24:24> RW:R:0: */

/*******************************************************************************
* Function Name: Cy_USBPD_Hpd_ReceiveGetStatus
****************************************************************************//**
*
* This function is used to fetch the current state of the signal if the HPD
* receive block is turned ON.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \return
* true if HPD input from GPIO is high
* false if HPD input from GPIO is low
*
*******************************************************************************/
bool Cy_USBPD_Hpd_ReceiveGetStatus(cy_stc_usbpd_context_t *context)
{
    bool ret = false;

#if PMG1_HPD_RX_ENABLE
    PPDSS_REGS_T pd = context->base;

    /* If the HPD receive block is turned ON, get the current state of the signal. */
    if (context->hpdReceiveEnable)
    {
#if defined(CY_DEVICE_PMG1S3)
        /* Obtain the HPD line status from INTR1_STATUS register. */
        ret = ((pd->intr1_status & PDSS_INTR1_STATUS_HPD_STATUS) != 0) ? true : false;
#else
        ret = ((pd->status & PDSS_STATUS_HPD_STATUS) != 0) ? true : false;
#endif /* defined(CY_DEVICE_PMG1S3) */
    }
#else
    (void) context;
#endif /* PMG1_HPD_RX_ENABLE */

    return ret;
}

/*******************************************************************************
* Function Name: Cy_USBPD_Hpd_RxSleepEntry
****************************************************************************//**
*
* Prepares the HPD RX block for deep-sleep.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \param hpdState
* Connection status of HPD.
*
* \return
* None
*******************************************************************************/
void Cy_USBPD_Hpd_RxSleepEntry(cy_stc_usbpd_context_t *context, bool hpdState)
{
    /* Store HPD Connection status. */
    context->hpdState = hpdState;

    /*
     * CCG7D does not go into deep sleep in unattached state.
     * So work around for wakeup interrupts are not required.
     */
#if (!(defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S)))
    PPDSS_REGS_T pd = context->base;

    if (context->hpdReceiveEnable)
    {
        /* If HPD is connected, implement the CDT 245126 workaround. */
        if (hpdState)
        {
            /* Ensure default level of HPD TX is high. */
            pd->hpdt_ctrl1 |= PDSS_HPDT_CTRL1_DEFAULT_LEVEL;

            /* Enable HPD TX. */
            pd->ctrl |= PDSS_CTRL_HPDT_ENABLED;

            /* Enable HPD loop back. */
            pd->hpd_ctrl1 |= PDSS_HPD_CTRL1_LOOPBACK_EN;

            /* Update HPD RX Stable High minimum time to a very small value (<50us) */
            pd->hpd_ctrl3 = ((pd->hpd_ctrl3 & ~PDSS_HPD_CTRL3_STABLE_HIGH_MASK)
                | (1U << PDSS_HPD_CTRL3_STABLE_HIGH_POS));
            pd->hpd_ctrl5 = ((pd->hpd_ctrl5 & ~PDSS_HPD_CTRL5_LONG_HIGH_MASK)
                | (1U << PDSS_HPD_CTRL5_LONG_HIGH_POS));

            /*
             * Disable HPD Queue interrupt. There is no point in using Queue interrupt
             * for HPD high detection once device wakes up. We can poll for this.
             */
            pd->intr2 = PDSS_INTR2_HPD_QUEUE;
            pd->intr2_mask &= ~PDSS_INTR2_MASK_HPD_QUEUE_MASK;
        }
    }
#endif /* (!(defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S))) */
}

/*******************************************************************************
* Function Name: Cy_USBPD_Hpd_RxWakeup
****************************************************************************//**
*
* Restores the HPD Tx signal driver after device wakes up from deep-sleep.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
*\return
* None
*
*******************************************************************************/
void Cy_USBPD_Hpd_RxWakeup(cy_stc_usbpd_context_t *context)
{
    /*
     * CCG7D does not go into deep sleep in unattached state.
     * So work around for wakeup interrupts are not required.
     */
#if (!(defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S)))
    /* CDT 245126 workaround: This routine implements the wakeup portion of workaround. */    
    PPDSS_REGS_T pd = context->base;
    uint8_t timeout = 0;

    if (context->hpdReceiveEnable)
    {
        /* Revert the settings only if Loopback was enabled before entering deep sleep. */
        if ((pd->hpd_ctrl1 & PDSS_HPD_CTRL1_LOOPBACK_EN) != 0UL)
        {
            /*
             * Wait for the HPD Queue connect event. This is the fake HPD Queue connect
             * event triggered due to CDT 245126 workaround. 20us wait is enough.
             */
            while ((HPD_GET_EVENT_0(pd->hpd_queue) != (uint32_t)CY_USBPD_HPD_EVENT_PLUG) && (timeout < 20U))
            {
                Cy_SysLib_DelayUs (1);
                timeout++;
            }

            /* Ensure that HPD RX high time is reset back to default. */
            pd->hpd_ctrl3 = PDSS_HPD_CTRL3_DEFAULT_VALUE;
            pd->hpd_ctrl5 = PDSS_HPD_CTRL5_DEFAULT;

            /* Ensure that Loopback is disabled. */
            pd->hpd_ctrl1 &= ~PDSS_HPD_CTRL1_LOOPBACK_EN;
            /* Disable HPD TX. */
            pd->ctrl &= ~PDSS_CTRL_HPDT_ENABLED;

            /* Enable the HPD Queue interrupt to capture true HPD interrupts from now on. */
            pd->intr2 = PDSS_INTR2_HPD_QUEUE;
            pd->intr2_mask |= PDSS_INTR2_MASK_HPD_QUEUE_MASK;
        }
    }
#else
    (void)context;
#endif /* (!(defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S))) */
}


/*******************************************************************************
* Function Name: Cy_USBPD_Hpd_Deinit
****************************************************************************//**
*
* Disable the HPD functionality on the specified PD port. This
* is used for HPD receive as well transmit de-initialization.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \return
* \ref cy_en_usbpd_status_t
*
*******************************************************************************/
cy_en_usbpd_status_t Cy_USBPD_Hpd_Deinit(cy_stc_usbpd_context_t *context)
{
    PPDSS_REGS_T pd = context->base;
    uint32_t pin;

    if ((!context->hpdTransmitEnable) && (!context->hpdReceiveEnable))
    {
        return CY_USBPD_STAT_FAILURE;
    }

    /* Disable all HPD related interrupts. */
    pd->intr2 = PDSS_INTR2_MASK_HPDT_COMMAND_DONE_MASK | PDSS_INTR2_MASK_HPD_QUEUE_MASK;
    pd->intr2_mask &= ~(PDSS_INTR2_MASK_HPD_QUEUE_MASK | PDSS_INTR2_MASK_HPDT_COMMAND_DONE_MASK);

    pd->intr1 = PDSS_INTR1_HPDIN_CHANGED;
    pd->intr1_mask &= ~PDSS_INTR1_MASK_HPDIN_CHANGED_MASK;

    /* Disable both HPD transmit and receive blocks. */
    pd->ctrl &= ~(PDSS_CTRL_HPDT_ENABLED | PDSS_CTRL_HPD_ENABLED);

    if (context->port == 0U)
    {
        pin = HPD_P0_PORT_PIN;
    }
    else
    {
        pin = HPD_P1_PORT_PIN;
    }

    /* Revert the HPD pin to GPIO mode. */
    Cy_GPIO_SetHSIOM(Cy_GPIO_PortToAddr(pin >> 4), (pin & 0x0FUL), (en_hsiom_sel_t)HSIOM_SEL_GPIO);

    if (context->hpdTransmitEnable)
    {
        /* Make sure that the HPD signal is driven to zero. */
        Cy_GPIO_Write(Cy_GPIO_PortToAddr(pin >> 4), (pin & 0x0FUL), 0);
    }

    context->hpdCbk = NULL;
    context->hpdTransmitEnable = false;
    context->hpdReceiveEnable = false;

    return CY_USBPD_STAT_SUCCESS;
}


/*******************************************************************************
* Function Name: Cy_USBPD_Hpdt_IsCommandActive
****************************************************************************//**
*
* Checks whether the CtrlReg Command is already started.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \return
* Returns true if not started, false otherwise.
*
*******************************************************************************/
bool Cy_USBPD_Hpdt_IsCommandActive(cy_stc_usbpd_context_t *context)
{
    PPDSS_REGS_T pd = context->base;
    if ((pd->hpdt_ctrl1 & PDSS_HPDT_CTRL1_COMMAND_START) == 0UL)
    {
        return true;
    }
    else
    {
        return false;
    }
}


/*******************************************************************************
* Function Name: Cy_USBPD_Hpd_TransmitSendevt
****************************************************************************//**
*
* Sends the desired HPD event out through the HPD GPIO. Only
* the CY_USBPD_HPD_EVENT_UNPLUG, CY_USBPD_HPD_EVENT_UNPLUG and CY_USBPD_HPD_EVENT_IRQ events
* should be requested.
*
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
* \param evtype
* Type of HPD event to be sent.
*
* \return
* \ref cy_en_usbpd_status_t
*
*******************************************************************************/
cy_en_usbpd_status_t Cy_USBPD_Hpd_TransmitSendevt(cy_stc_usbpd_context_t *context, cy_en_usbpd_hpd_events_t evtype)
{
    PPDSS_REGS_T pd = context->base;
    cy_en_usbpd_status_t status = CY_USBPD_STAT_SUCCESS;
    uint32_t val = 0;

    if (Cy_USBPD_Hpdt_IsCommandActive(context) == false)
    {
        status = CY_USBPD_STAT_BUSY;
    }

    /* Update HPD-out as required. */
    switch (evtype)
    {
        case CY_USBPD_HPD_EVENT_UNPLUG:
            break;

        case CY_USBPD_HPD_EVENT_PLUG:
            val = 1UL;
            break;

        case CY_USBPD_HPD_EVENT_IRQ:
            val = 2UL;
            break;

        default:
            status = CY_USBPD_STAT_BAD_PARAM;
            break;
    }

    pd->hpdt_ctrl1 = (pd->hpdt_ctrl1 & ~PDSS_HPDT_CTRL1_COMMAND_MASK) | (val << PDSS_HPDT_CTRL1_COMMAND_POS);
    pd->hpdt_ctrl1 |= PDSS_HPDT_CTRL1_COMMAND_START;

    return status;
}

/*******************************************************************************
* Function Name: Cy_USBPD_Hpd_Intr0Handler
****************************************************************************//**
*
* HPD Interrupt handler. Expected to be called from PD Interrupt 0 handler.
* 
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
*******************************************************************************/
void Cy_USBPD_Hpd_Intr0Handler(cy_stc_usbpd_context_t *context)
{
    PPDSS_REGS_T pd = context->base; 
    uint8_t hpdEvt = 0;

    /* Clear the interrupt and send callbacks for all queued events. */
    if ((pd->intr2_masked & PDSS_INTR2_HPD_QUEUE) != 0UL)
    {
        /* Clear the interrupt and send callbacks for all queued events. */
        pd->intr2 = PDSS_INTR2_HPD_QUEUE;

        uint8_t hpdQueueStat = (uint8_t)(pd->hpd_queue & 0xFFUL);
        if (context->hpdCbk != NULL)
        {
            hpdEvt = HPD_GET_EVENT_0(hpdQueueStat);
            if ((cy_en_usbpd_hpd_events_t)hpdEvt != CY_USBPD_HPD_EVENT_NONE)
            {
                context->hpdCbk (context, (cy_en_usbpd_hpd_events_t)hpdEvt);
            }
            
            hpdEvt = HPD_GET_EVENT_1(hpdQueueStat);
            if ((cy_en_usbpd_hpd_events_t)hpdEvt != CY_USBPD_HPD_EVENT_NONE)
            {
                context->hpdCbk (context, (cy_en_usbpd_hpd_events_t)hpdEvt);
            }

            hpdEvt = HPD_GET_EVENT_2(hpdQueueStat);
            if ((cy_en_usbpd_hpd_events_t)hpdEvt != CY_USBPD_HPD_EVENT_NONE)
            {
                context->hpdCbk (context, (cy_en_usbpd_hpd_events_t)hpdEvt);
            }

            hpdEvt = HPD_GET_EVENT_3(hpdQueueStat);
            if ((cy_en_usbpd_hpd_events_t)hpdEvt != CY_USBPD_HPD_EVENT_NONE)
            {
                context->hpdCbk (context, (cy_en_usbpd_hpd_events_t)hpdEvt);
            }
        }
    }

    if ((pd->intr2_masked & PDSS_INTR2_HPDT_COMMAND_DONE) != 0UL)
    {
        /* Clear the interrupt and send the callback. */
        pd->intr2 = PDSS_INTR2_HPDT_COMMAND_DONE;

        if (context->hpdCbk != NULL)
        {
            context->hpdCbk(context, CY_USBPD_HPD_COMMAND_DONE);
        }
    }
}

/*******************************************************************************
* Function Name: Cy_USBPD_Hpd_Intr1Handler
****************************************************************************//**
*
* HPD Interrupt handler. Expected to be called from PD Interrupt 1 handler.
* 
* \param context
* The pointer to the context structure \ref cy_stc_usbpd_context_t allocated
* by the user. The structure is used during the USBPD operation for internal
* configuration and data retention. The user must not modify anything
* in this structure.
*
*******************************************************************************/
void Cy_USBPD_Hpd_Intr1Handler(cy_stc_usbpd_context_t *context)
{
    PPDSS_REGS_T pd = context->base;

    if ((pd->intr1_masked & PDSS_INTR1_HPDIN_CHANGED) != 0UL)
    {
        /* Clear the interrupt. */
        pd->intr1 = PDSS_INTR1_HPDIN_CHANGED;

        /*
         * Notify the application that HPD raw line status has changed.
         * The application should not attempt low power entry for 100 ms after receiving this event.
         */
        if (context->hpdCbk != NULL)
        {
            context->hpdCbk(context, CY_USBPD_HPD_INPUT_CHANGE);
        }
    }
}

#endif /* (defined(CY_IP_MXUSBPD) || defined(CY_IP_M0S8USBPD)) */

/* [] END OF FILE */
