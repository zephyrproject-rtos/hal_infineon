/***************************************************************************//**
* \file cy_ble_hal_int.c
* \version 3.60
*
* \brief
*  This file contains the source code for the Interrupt service Routine for the
*  HAL section of the PSoC 6 BLE Middleware.
*
********************************************************************************
* \copyright
* Copyright 2017-2021, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/
#include "cy_ble.h"
#include "cy_ble_hal_pvt.h"
#include "cy_ble.h"

#if defined(CY_IP_MXBLESS)

/*******************************************************************************
* Function Name: Cy_BLE_IntrNotifyIsrHandler
****************************************************************************//**
*
*  This function sends notification (with interrupt type information) to user
*  callback for the BLE interrupts subscribed by user. The list of supported
*  interrupts described in the enumeration cy_en_ble_interrupt_callback_feature_t.
*  Cy_BLE_RegisterInterruptCallback() API used to register callback for receiving
*  the BLE interrupts.
*
*  This function must be called inside the user-defined BLESS 
*  interrupt service routine (ISR) if user uses Interrupt Notifications Feature.
*
*******************************************************************************/
void Cy_BLE_IntrNotifyIsrHandler(void)
{
    if((intrNotifyPtr != NULL) && (intrNotifyPtr->mask != 0u))
    {
        uint32_t interruptType = (uint32_t)CY_BLE_INTR_CALLBACK_NONE;

        /* Read BLE_BLELL->EVENT_INTR */
        if((intrNotifyPtr->mask & CY_BLE_INTR_CALLBACK_BLESS_STACK_ISR) != 0u)
        {
            interruptType |= CY_BLE_INTR_CALLBACK_BLESS_STACK_ISR;
        }
        else
        {
            if(((BLE_BLESS_INTR_STAT & BLE_BLESS_INTR_STAT_DSM_ENTERED_INTR_Msk) != 0u) &&
               ((intrNotifyPtr->mask & CY_BLE_INTR_CALLBACK_BLESS_INTR_STAT_DSM_ENTERED)!= 0u))
            {
                interruptType |= CY_BLE_INTR_CALLBACK_BLESS_INTR_STAT_DSM_ENTERED;
            }

            if(((BLE_BLESS_INTR_STAT & BLE_BLESS_INTR_STAT_DSM_EXITED_INTR_Msk) != 0u) &&
               ((intrNotifyPtr->mask & CY_BLE_INTR_CALLBACK_BLESS_INTR_STAT_DSM_EXITED) != 0u))
            {
                interruptType |= CY_BLE_INTR_CALLBACK_BLESS_INTR_STAT_DSM_EXITED;
            }

            if(((BLE_BLESS_INTR_STAT & BLE_BLESS_INTR_STAT_LL_INTR_Msk) != 0u))
            {
                /**
                 *  Updates the firmware and hardware to exit sleep mode, when
                 *  called from the interrupt mode, after checking the state machine.
                 */
                Cy_BLE_MappingLlIsrExitLowPowerMode();

                if(BLE_BLELL_EVENT_INTR != 0x0u)
                {
                    if((BLE_BLELL_EVENT_INTR & BLE_BLELL_EVENT_INTR_CONN_INTR_Msk) != 0u)
                    {
                        if(((BLE_BLELL_CONN_INTR & BLE_BLELL_CONN_INTR_CLOSE_CE_Msk) != 0u) &&
                            ((intrNotifyPtr->mask & CY_BLE_INTR_CALLBACK_BLELL_CONN_INTR_CLOSE_CE) != 0u))
                        {
                            /* Return interrupt type CY_BLE_INTR_CALLBACK_BLELL_CONN_INTR_CLOSE_CE */
                            interruptType |= CY_BLE_INTR_CALLBACK_BLELL_CONN_INTR_CLOSE_CE;
                        }

                        if(((BLE_BLELL_CONN_INTR & BLE_BLELL_CONN_INTR_CE_TX_ACK_Msk) != 0u) &&
                           ((intrNotifyPtr->mask & CY_BLE_INTR_CALLBACK_BLELL_CONN_INTR_CE_TX_ACK) != 0u))
                        {
                            /* Return interrupt type CY_BLE_INTR_CALLBACK_BLELL_CONN_INTR_CE_TX_ACK */
                            interruptType |= CY_BLE_INTR_CALLBACK_BLELL_CONN_INTR_CE_TX_ACK;
                        }

                        if(((BLE_BLELL_CONN_EXT_INTR & BLE_BLELL_CONN_EXT_INTR_EARLY_INTR_Msk) != 0u) &&
                           ((intrNotifyPtr->mask & CY_BLE_INTR_CALLBACK_BLELL_CONN_EXT_INTR_EARLY) != 0u))
                        {
                            /* Return interrupt type CY_BLE_INTR_CALLBACK_BLELL_CONN_EXT_INTR_EARLY */
                            interruptType |= CY_BLE_INTR_CALLBACK_BLELL_CONN_EXT_INTR_EARLY;
                        }

                        if(((BLE_BLELL_CONN_INTR & BLE_BLELL_CONN_INTR_CE_RX_Msk) != 0u) &&
                            ((intrNotifyPtr->mask & CY_BLE_INTR_CALLBACK_BLELL_CONN_INTR_CE_RX) != 0u))
                        {
                            /* Return interrupt type CY_BLE_INTR_CALLBACK_BLELL_CONN_INTR_CE_RX */
                            interruptType |= CY_BLE_INTR_CALLBACK_BLELL_CONN_INTR_CE_RX;
                        }
                    }

                    if((BLE_BLELL_EVENT_INTR & BLE_BLELL_EVENT_INTR_SCAN_INTR_Msk) != 0u)
                    {
                        if(((BLE_BLELL_SCAN_INTR & BLE_BLELL_SCAN_INTR_ADV_RX_INTR_Msk) != 0u) &&
                           ((intrNotifyPtr->mask & CY_BLE_INTR_CALLBACK_BLELL_SCAN_INTR_ADV_RX) != 0u))
                        {
                            /* Return interrupt type Return interrupt type CY_BLE_INTR_CALLBACK_BLELL_SCAN_INTR_ADV_RX */
                            interruptType |= CY_BLE_INTR_CALLBACK_BLELL_SCAN_INTR_ADV_RX;
                        }

                        if(((BLE_BLELL_SCAN_INTR & BLE_BLELL_SCAN_INTR_SCAN_RSP_RX_INTR_Msk) != 0u) &&
                           ((intrNotifyPtr->mask & CY_BLE_INTR_CALLBACK_BLELL_SCAN_INTR_SCAN_RSP_RX) != 0u))
                        {
                            /* Return interrupt type CY_BLE_INTR_CALLBACK_BLELL_SCAN_INTR_SCAN_RSP_RX */
                            interruptType |= CY_BLE_INTR_CALLBACK_BLELL_SCAN_INTR_SCAN_RSP_RX;
                        }
                    }

                    if((BLE_BLELL_EVENT_INTR & BLE_BLELL_EVENT_INTR_ADV_INTR_Msk) != 0u)
                    {
                        if(((BLE_BLELL_ADV_INTR & BLE_BLELL_ADV_INTR_CONN_REQ_RX_INTR_Msk) != 0u) &&
                           ((intrNotifyPtr->mask & CY_BLE_INTR_CALLBACK_BLELL_ADV_INTR_CONN_REQ_RX) != 0u))
                        {
                            /* Return interrupt type CY_BLE_INTR_CALLBACK_BLELL_ADV_INTR_CONN_REQ_RX */
                            interruptType |= CY_BLE_INTR_CALLBACK_BLELL_ADV_INTR_CONN_REQ_RX;
                        }
                    }
                }
            }
        }

        /* Send interrupt type information to registered callback */
        if(interruptType != (uint32_t)CY_BLE_INTR_CALLBACK_NONE)
        {
            if((!intrNotifyPtr->configFlag) && (Cy_BLE_InterruptCallback != NULL))
            {
                /* Single BLE mode */
                Cy_BLE_InterruptCallback((uint32_t)interruptType);
            }
            else
            {
                /* Dual BLE mode */
                uint32_t rTimeout = 100u; /* us */
                intrNotifyPtr->data = (uint32_t)interruptType;

                /* Check whether IPC is released */
                while((Cy_IPC_Drv_IsLockAcquired(Cy_IPC_Drv_GetIpcBaseAddress((uint32_t)intrNotifyPtr->userIpcChan))) &&
                      (rTimeout !=0u))
                {
                    Cy_SysLib_DelayUs(1u);
                    rTimeout--;
                }

                /* Generates a notify event by IPC interrupt structures */
                if(rTimeout != 0u)
                {
                    (void)Cy_IPC_Drv_AcquireNotify(Cy_IPC_Drv_GetIpcBaseAddress((uint32_t)intrNotifyPtr->userIpcChan),
                                   (1uL << (uint32_t)intrNotifyPtr->userIpcIntr));
                }

            }
        }
    }
}


/*******************************************************************************
* Function Name: Cy_BLE_BlessIsrHandler
****************************************************************************//**
*
*  Process interrupt events generated by the BLE sub-system.
*
*  The interrupts are mandatory for BLE Device operation and this function must
*  be called inside the user-defined interrupt service routine (ISR).
*
*******************************************************************************/
void Cy_BLE_BlessIsrHandler(void)
{
    bool sendNotification = false;

    /* Call BLE Stack manager bless function handler */
    sendNotification = Cy_BLE_HAL_MappingBlessInterruptHandler();
    /* Host stack takes care of clearing interrupts */

    /**
     * Call the application Host callback. 
     * This notification indicates that user should call Cy_BLE_ProcessEvents()
     * to process pending Stack events. */
    if((Cy_BLE_HostRegisteredCallback != NULL) && sendNotification)
    {
        Cy_BLE_HostRegisteredCallback();
    }
}

#endif /* CY_IP_MXBLESS */


/* [] END OF FILE */
