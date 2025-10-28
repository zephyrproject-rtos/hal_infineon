/***************************************************************************//**
* \file cy_syspm.c
* \version 3.10
*
* This driver provides the source code for API power management.
*
********************************************************************************
* \copyright
* (c) (2016-2024), Cypress Semiconductor Corporation (an Infineon company) or
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
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/
#include "cy_syspm.h"
#include "cy_sysclk.h"

/*******************************************************************************
*       Internal Defines
*******************************************************************************/

/* The define for number of callback roots. This value corresponds to the
 * number of the low power modes supported by the callback mechanism:
 * Active, Sleep and Deep Sleep. */
#define CALLBACK_ROOT_NR                (3U)

/*******************************************************************************
*       Internal Variables
*******************************************************************************/

/* Array of the callback roots */
static cy_stc_syspm_callback_t* pmCallbackRoot[CALLBACK_ROOT_NR] = {NULL, NULL, NULL};

/* The array of the pointers to failed callback */
static cy_stc_syspm_callback_t* failedCallback[CALLBACK_ROOT_NR] = {NULL, NULL, NULL};


/*******************************************************************************
* Function Name: Cy_SysPm_CpuEnterSleep
****************************************************************************//**
*
* Sets the CPU into the Sleep power mode, and calls registered callback
* functions.
*
* For more details about switching into the sleep power mode and debug, refer to
* the device TRM. If at least one callback function with the \ref CY_SYSPM_SLEEP
* type was registered, the following algorithm is executed: Prior to entering
* sleep mode, all callback functions of the \ref CY_SYSPM_SLEEP type with the
* \ref CY_SYSPM_CHECK_READY parameter are called allowing the driver to signal
* whether it is ready to enter the low power mode. If any of the callbacks of
* the \ref CY_SYSPM_SLEEP type with the \ref CY_SYSPM_CHECK_READY parameter
* returns \ref CY_SYSPM_FAIL, the remaining callback of the \ref CY_SYSPM_SLEEP
* type with the \ref CY_SYSPM_CHECK_READY parameter calls are skipped.
* After \ref CY_SYSPM_FAIL, all the \ref CY_SYSPM_SLEEP callbacks with
* the \ref CY_SYSPM_CHECK_FAIL parameter are executed.
* These are the callbacks of the \ref CY_SYSPM_SLEEP type with
* the \ref CY_SYSPM_CHECK_READY parameter that were previously executed before
* getting \ref CY_SYSPM_FAIL. If sleep mode is not entered
* the Cy_SysPm_CpuEnterSleep() function returns \ref CY_SYSPM_FAIL.
* If all of the callbacks of the \ref CY_SYSPM_SLEEP type with
* the  \ref CY_SYSPM_CHECK_READY parameter calls return \ref CY_SYSPM_SUCCESS,
* then all callbacks of the \ref CY_SYSPM_SLEEP type with
* the \ref CY_SYSPM_CHECK_FAIL parameters calls are skipped, and all
* callbacks of the \ref CY_SYSPM_SLEEP type and \ref CY_SYSPM_BEFORE_TRANSITION
* parameter calls are executed, allowing the peripherals to prepare
* for CPU sleep. The sleep mode is then entered for the CPU.
* This is a CPU-centric power mode. It means that the CPU has entered the sleep
* mode and its main clock is removed. It is identical to CPU active mode from
* a peripheral point of view. Any enabled interrupt can cause a wakeup
* from sleep mode. After wakeup from CPU sleep, all registered callbacks of
* the \ref CY_SYSPM_SLEEP type and with the \ref CY_SYSPM_AFTER_TRANSITION
* parameter are executed to return the peripherals to active operation.
* The Cy_SysPm_CpuEnterSleep() function returns \ref CY_SYSPM_SUCCESS.
* No callbacks of the \ref CY_SYSPM_SLEEP type with
* the \ref CY_SYSPM_BEFORE_TRANSITION parameter or callbacks of
* the \ref CY_SYSPM_SLEEP type and \ref CY_SYSPM_AFTER_TRANSITION parameter
* callbacks are executed if sleep mode is not entered.
*
* \note The last callback which returned \ref CY_SYSPM_FAIL is not executed
* with the \ref CY_SYSPM_CHECK_FAIL parameter because of the FAIL.
* The return values from executed callback functions with
* the \ref CY_SYSPM_CHECK_FAIL, \ref CY_SYSPM_BEFORE_TRANSITION, and
* \ref CY_SYSPM_AFTER_TRANSITION modes are ignored.
* \ref cy_en_syspm_callback_mode_t, except the \ref CY_SYSPM_CHECK_READY,
* are ignored.
*
* \return
* Entered status, see \ref cy_en_syspm_status_t.
*
*******************************************************************************/
cy_en_syspm_status_t Cy_SysPm_CpuEnterSleep(void)
{
    uint32_t interruptState;
    uint32_t cbSleepRootIdx = (uint32_t) CY_SYSPM_SLEEP;
    cy_en_syspm_status_t retVal = CY_SYSPM_SUCCESS;

    /* Call registered callback functions with CY_SYSPM_CHECK_READY parameter */
    if (pmCallbackRoot[cbSleepRootIdx] != NULL)
    {
        retVal = Cy_SysPm_ExecuteCallback(CY_SYSPM_SLEEP, CY_SYSPM_CHECK_READY);
    }

    /* The CPU can switch into the Sleep power mode only when
    *  all executed registered callback functions with the CY_SYSPM_CHECK_READY
    *  parameter return CY_SYSPM_SUCCESS.
    */
    if(retVal == CY_SYSPM_SUCCESS)
    {
        /* Call the registered callback functions with
        * CY_SYSPM_BEFORE_TRANSITION parameter
        */
        interruptState = Cy_SysLib_EnterCriticalSection();
        if (pmCallbackRoot[cbSleepRootIdx] != NULL)
        {
            (void) Cy_SysPm_ExecuteCallback(CY_SYSPM_SLEEP, CY_SYSPM_BEFORE_TRANSITION);
        }

        Cy_SysPm_CpuEnterSleepNoCallbacks();

        Cy_SysLib_ExitCriticalSection(interruptState);

        /* Call the registered callback functions with the
        *  CY_SYSPM_AFTER_TRANSITION parameter
        */
        if (pmCallbackRoot[cbSleepRootIdx] != NULL)
        {
            (void) Cy_SysPm_ExecuteCallback(CY_SYSPM_SLEEP, CY_SYSPM_AFTER_TRANSITION);
        }
    }
    else
    {
        /* Execute callback functions with the CY_SYSPM_CHECK_FAIL parameter to
        *  undo everything done in the callback with the CY_SYSPM_CHECK_READY
        *  parameter
        */
        (void) Cy_SysPm_ExecuteCallback(CY_SYSPM_SLEEP, CY_SYSPM_CHECK_FAIL);
        retVal = CY_SYSPM_FAIL;
    }
    return retVal;
}


/*******************************************************************************
* Function Name: Cy_SysPm_CpuEnterSleepNoCallbacks
****************************************************************************//**
*
* Sets the CPU to Sleep mode without calling registered callback functions. The
* application is responsible for preparing a device for entering Low-power mode
* and restoring it to the desired state on a wakeup.
*
* For more details about switching to Sleep mode and debug, refer to the device
* TRM.
*
* Refer to the \ref Cy_SysPm_CpuEnterSleep() for the automatic execution
* of registered callback functions.
*
*******************************************************************************/
void Cy_SysPm_CpuEnterSleepNoCallbacks(void)
{
    /* The CPU enters the Sleep power mode upon execution of WFI */
    SCB_SCR &= (uint32_t) ~SCB_SCR_SLEEPDEEP_Msk;
    __WFI();
}


/*******************************************************************************
* Function Name: Cy_SysPm_CpuEnterDeepSleep
****************************************************************************//**
*
* Sets the system into deep sleep power mode.
*
* Prior to entering the deep sleep mode, all callbacks of
* the \ref CY_SYSPM_DEEPSLEEP type with the \ref CY_SYSPM_CHECK_READY parameter
* registered callbacks are called, allowing the driver to signal whether it is
* ready to enter the power mode. If any \ref CY_SYSPM_DEEPSLEEP type with
* the \ref CY_SYSPM_CHECK_READY parameter call returns \ref CY_SYSPM_FAIL,
* the remaining callback \ref CY_SYSPM_DEEPSLEEP type with
* the \ref CY_SYSPM_CHECK_READY parameter calls are skipped.
* After a \ref CY_SYSPM_FAIL, all of the callbacks of
* the \ref CY_SYSPM_DEEPSLEEP type with the \ref CY_SYSPM_CHECK_FAIL parameter
* are executed that correspond to the callbacks with \ref CY_SYSPM_DEEPSLEEP
* type with \ref CY_SYSPM_CHECK_READY parameter calls that occurred up to
* the point of failure. The deep sleep mode is not entered and
* the Cy_SysPm_CpuEnterDeepSleep() function returns \ref CY_SYSPM_FAIL. If
* all callbacks of the \ref CY_SYSPM_DEEPSLEEP type with
* the \ref CY_SYSPM_CHECK_READY parameter calls return \ref CY_SYSPM_SUCCESS,
* then all callbacks of the \ref CY_SYSPM_DEEPSLEEP type with
* the \ref CY_SYSPM_CHECK_FAIL parameter calls are skipped and all callbacks of
* the \ref CY_SYSPM_DEEPSLEEP type with the \ref CY_SYSPM_BEFORE_TRANSITION
* parameter calls are executed, allowing the peripherals to prepare for deep
* sleep. The deep sleep mode is then entered. Any enabled interrupt can cause a
* wakeup from the deep sleep mode.
*
* \note The last callback which returned \ref CY_SYSPM_FAIL is not executed with
* the \ref CY_SYSPM_CHECK_FAIL parameter because of the FAIL.
*
* The return values from executed callback functions with
* the \ref CY_SYSPM_CHECK_FAIL, \ref CY_SYSPM_BEFORE_TRANSITION, and
* \ref CY_SYSPM_AFTER_TRANSITION modes are ignored.
*
* Peripherals that do not need a clock or that receive a clock from
* their external interface (e.g. I2C/SPI) continue operating. Wakeup occurs when
* an interrupt asserts from an active deep sleep peripheral. For more details,
* see the corresponding peripheral's datasheet.
*
* For more details about switching into the deep sleep power mode and debug,
* refer to the device TRM.
*
* After wakeup from Deep Sleep, all of the registered callbacks with
* \ref CY_SYSPM_DEEPSLEEP type with \ref CY_SYSPM_AFTER_TRANSITION are executed
* to return peripherals to Active operation.
* The Cy_SysPm_CpuEnterDeepSleep() function returns \ref CY_SYSPM_SUCCESS.
* No callbacks are executed with \ref CY_SYSPM_DEEPSLEEP type with
* \ref CY_SYSPM_BEFORE_TRANSITION or \ref CY_SYSPM_AFTER_TRANSITION parameter,
* if deep sleep mode was not entered.
*
* \note For proper clocks tree configuration before entering Deep Sleep mode
* and restore clock tree configuration after waking up
* the \ref Cy_SysClk_DeepSleepCallback()
* (or it's customized version, accordingly to the application specifics)
* should be registered (recommended as the last in the registration sequence).
* Otherwise, PSOC may stuck at wakeup from Deep Sleep.
*
* \return
* Entered status, see \ref cy_en_syspm_status_t.
*
*******************************************************************************/
cy_en_syspm_status_t Cy_SysPm_CpuEnterDeepSleep(void)
{
    uint32_t interruptState;
    uint32_t cbDeepSleepRootIdx = (uint32_t) CY_SYSPM_DEEPSLEEP;
    cy_en_syspm_status_t retVal = CY_SYSPM_SUCCESS;

    /* Call the registered callback functions with the CY_SYSPM_CHECK_READY
    *  parameter
    */
    if (pmCallbackRoot[cbDeepSleepRootIdx] != NULL)
    {
        retVal = Cy_SysPm_ExecuteCallback(CY_SYSPM_DEEPSLEEP, CY_SYSPM_CHECK_READY);
    }

    /* The CPU can switch into the Deep Sleep power mode only when
    *  all executed registered callback functions with the CY_SYSPM_CHECK_READY
    *  parameter return CY_SYSPM_SUCCESS
    */
    if (retVal == CY_SYSPM_SUCCESS)
    {
        /* Call the registered callback functions with the
        * CY_SYSPM_BEFORE_TRANSITION parameter
        */
        interruptState = Cy_SysLib_EnterCriticalSection();
        if (pmCallbackRoot[cbDeepSleepRootIdx] != NULL)
        {
            (void) Cy_SysPm_ExecuteCallback(CY_SYSPM_DEEPSLEEP, CY_SYSPM_BEFORE_TRANSITION);
        }

        Cy_SysPm_CpuEnterDeepSleepNoCallbacks();

        Cy_SysLib_ExitCriticalSection(interruptState);
    }

    if (retVal == CY_SYSPM_SUCCESS)
    {
        /* Call the registered callback functions with the CY_SYSPM_AFTER_TRANSITION
        *  parameter
        */
        if (pmCallbackRoot[cbDeepSleepRootIdx] != NULL)
        {
            (void) Cy_SysPm_ExecuteCallback(CY_SYSPM_DEEPSLEEP, CY_SYSPM_AFTER_TRANSITION);
        }
    }
    else
    {
        /* Execute callback functions with the CY_SYSPM_CHECK_FAIL parameter to
        *  undo everything done in the callback with the CY_SYSPM_CHECK_READY
        *  parameter
        */
        if (pmCallbackRoot[cbDeepSleepRootIdx] != NULL)
        {
            (void) Cy_SysPm_ExecuteCallback(CY_SYSPM_DEEPSLEEP, CY_SYSPM_CHECK_FAIL);
        }

    }
    return retVal;
}


/*******************************************************************************
* Function Name: Cy_SysPm_CpuEnterDeepSleepNoCallbacks
****************************************************************************//**
*
* Sets the CPU into Deep Sleep mode without calling registered callback
* functions. The application is responsible for preparing a device for entering
* Low-power mode and restoring it to the desired state on a wakeup.
*
* For more details about switching to Sleep mode and debug, refer to the device
* TRM.
*
* Refer to the \ref Cy_SysPm_CpuEnterDeepSleep() for the automatic
* execution of registered callback functions.
*
*******************************************************************************/
void Cy_SysPm_CpuEnterDeepSleepNoCallbacks(void)
{
    /* Adjust delay to wait for references to settle on wakeup from Deep Sleep */  
    SRSS_PWR_KEY_DELAY = SFLASH_DPSLP_KEY_DELAY;
        
    /* The CPU enters Deep Sleep mode upon execution of WFI */
    SCB_SCR |= SCB_SCR_SLEEPDEEP_Msk;
    __WFI();
}


/*******************************************************************************
* Function Name: Cy_SysPm_SleepOnExit
****************************************************************************//**
*
* Set Sleep on the Exit mode.
*
* This API gives a possibility to keep the CPU in the sleep mode at all times
* and only wakeup to run a single interrupt and then immediately go back
* to sleep.
*
* \param enable
*   - True  - Enable Sleep on Exit
*   - False - Disable Sleep on Exit
*
*******************************************************************************/
void Cy_SysPm_SleepOnExit(bool enable)
{
    if(enable)
    {
        /* Enable sleep-on-exit feature */
        SCB_SCR |= SCB_SCR_SLEEPONEXIT_Msk;
    }
    else
    {
        /* Disable sleep-on-exit feature */
        SCB_SCR &= (uint32_t) ~(SCB_SCR_SLEEPONEXIT_Msk);
    }

}


/*******************************************************************************
* Function Name: Cy_SysPm_RegisterCallback
****************************************************************************//**
*
* Registers a new syspm callback.
*
* A callback is a function called after an event in the driver or
* middleware module has occurred. The handler callback API will be executed if
* the specific event occurs. See \ref cy_stc_syspm_callback_t. User is
* responsible for defining a separate buffer for each of the power modes
* registered lists.
*
* \note The registered callbacks are executed in two orders, based on callback
* mode \ref cy_en_syspm_callback_mode_t. For modes \ref CY_SYSPM_CHECK_READY and
* \ref CY_SYSPM_BEFORE_TRANSITION, the order as follows: the first registered
* callback will be always the first executed. And the last registered callback
* will be executed as the last callback.
* For modes \ref CY_SYSPM_AFTER_TRANSITION and \ref CY_SYSPM_CHECK_FAIL,
* the order is as follows: the first registered callback will be always
* the last executed. And the last registered callback will be executed as
* the first callback.
*
* \param handler
* The address of the syspm callback structure. See \ref cy_stc_syspm_callback_t.
* \note Do not modify the registered structure in run-time.
*
* \return
* - True if a callback was registered.
* - False if a callback was not registered or maximum callbacks were registered.
*
* \warning After being registered, the SysPm callback structures must be
* allocated during power mode transition.
*
*******************************************************************************/
bool Cy_SysPm_RegisterCallback(cy_stc_syspm_callback_t* handler)
{
    bool retVal = false;

    /* Verify the input parameters. */
    if ((handler != NULL) && (handler->callbackParams != NULL) && (handler->callback != NULL))
    {
        uint32_t callbackRootIdx = (uint32_t) handler->type;

        /* If the callback list is not empty. */
        if (pmCallbackRoot[callbackRootIdx] != NULL)
        {
            cy_stc_syspm_callback_t* curCallback = pmCallbackRoot[callbackRootIdx];
            cy_stc_syspm_callback_t* insertPos  = curCallback;

            /* Find the callback after which the new callback is to be
             * inserted. Ensure the given callback has not been registered.
             */
            while ((NULL != curCallback->nextItm) && (curCallback != handler))
            {
                curCallback = curCallback->nextItm;
                /* Callbacks with the same order value are stored in the order
                 * they are registered.
                 */
                if (curCallback->order <= handler->order)
                {
                    insertPos = curCallback;
                }
            }
            /* If the callback has not been registered. */
            if (curCallback != handler)
            {
                /* If the callback is to be inserted at the beginning of the list. */
                if ((insertPos->prevItm == NULL) && (handler->order < insertPos->order))
                {
                    handler->nextItm = insertPos;
                    handler->prevItm = NULL;
                    handler->nextItm->prevItm = handler;
                    pmCallbackRoot[callbackRootIdx] = handler;
                }
                else
                {
                    handler->nextItm = insertPos->nextItm;
                    handler->prevItm = insertPos;

                    /* If the callback is not inserted at the end of the list. */
                    if (handler->nextItm != NULL)
                    {
                        handler->nextItm->prevItm = handler;
                    }
                    insertPos->nextItm = handler;
                }
                retVal = true;
            }
        }
        else
        {
            /* The callback list is empty. */
            pmCallbackRoot[callbackRootIdx] = handler;
            handler->nextItm = NULL;
            handler->prevItm = NULL;
            retVal = true;
        }
    }
    return retVal;
}


/*******************************************************************************
* Function Name: Cy_SysPm_UnregisterCallback
****************************************************************************//**
*
* This function unregisters a callback.
*
* The registered callback will be unregistered. Otherwise, false will be
* returned.
*
* \param handler
* The item that should be unregistered. See \ref cy_stc_syspm_callback_t.
*
* \return
* - True if callback was unregistered.
* - False if it was not unregistered or no callbacks are registered.
*
*******************************************************************************/
bool Cy_SysPm_UnregisterCallback(cy_stc_syspm_callback_t const *handler)
{
    bool retVal = false;

    if (handler != NULL)
    {
        uint32_t callbackRootIdx = (uint32_t) handler->type;
        cy_stc_syspm_callback_t* curCallback = pmCallbackRoot[callbackRootIdx];

        /* Search requested callback item in the linked list */
        while (curCallback != NULL)
        {
            /* Requested callback is found */
            if (curCallback == handler)
            {
                retVal = true;
                break;
            }

            /* Go to next callback item in the linked list */
            curCallback = curCallback->nextItm;
        }

        if (retVal)
        {
            /* Requested callback is first in the list */
            if (pmCallbackRoot[callbackRootIdx] == handler)
            {
                /* Check whether this the only callback registered */
                if (pmCallbackRoot[callbackRootIdx]->nextItm != NULL)
                {
                    pmCallbackRoot[callbackRootIdx] = pmCallbackRoot[callbackRootIdx]->nextItm;
                    pmCallbackRoot[callbackRootIdx]->prevItm = NULL;
                }
                else
                {
                    /* We had only one callback */
                    pmCallbackRoot[callbackRootIdx] = NULL;
                }
            }
            else
            {
                /* Update links of related to unregistered callback items */
                curCallback->prevItm->nextItm = curCallback->nextItm;

                if (curCallback->nextItm != NULL)
                {
                    curCallback->nextItm->prevItm = curCallback->prevItm;
                }
            }
        }
    }

    return retVal;
}


/*******************************************************************************
* Function Name: Cy_SysPm_ExecuteCallback
****************************************************************************//**
*
* The function executes all registered callbacks with provided type and mode.
*
* \note The registered callbacks will be executed in order based on
* lastCallback  value. There are two possible callback
* execution orders:
* * From first registered to last registered. This order applies to
*   callbacks with mode \ref CY_SYSPM_CHECK_READY and
*   ref\ CY_SYSPM_BEFORE_TRANSITION.
* * Backward flow execution: from last executed callback to the first registered.
*   Such order is relevant to callbacks with mode \ref CY_SYSPM_AFTER_TRANSITION
*   and \ref CY_SYSPM_CHECK_FAIL. Note that, the last registered callback
*   function is skipped with mode \ref CY_SYSPM_CHECK_FAIL. This is because
*   callback which returned \ref CY_SYSPM_FAIL already know that it failed.
*
* If no callbacks are registered, returns CY_SYSPM_SUCCESS.
*
* \param type
* The callback type. See \ref cy_en_syspm_callback_type_t.
*
* \param mode
* The callback mode. See \ref cy_en_syspm_callback_mode_t.
*
* \return
* - CY_SYSPM_SUCCESS if callback successfully completed or nor callbacks
*   registered.
* - CY_SYSPM_FAIL one of the executed callback(s) returned fail.
*
*******************************************************************************/
cy_en_syspm_status_t Cy_SysPm_ExecuteCallback(cy_en_syspm_callback_type_t type, cy_en_syspm_callback_mode_t mode)
{
    CY_ASSERT_L3(CY_SYSPM_IS_CALLBACK_TYPE_VALID(type));
    CY_ASSERT_L3(CY_SYSPM_IS_CALLBACK_MODE_VALID(mode));

    static cy_stc_syspm_callback_t* lastExecutedCallback = NULL;
    cy_en_syspm_status_t retVal = CY_SYSPM_SUCCESS;
    cy_stc_syspm_callback_t* curCallback = pmCallbackRoot[(uint32_t) type];
    cy_stc_syspm_callback_params_t curParams;

    if ((mode == CY_SYSPM_BEFORE_TRANSITION) || (mode == CY_SYSPM_CHECK_READY))
    {
        /* Execute registered callbacks with order from first registered to the
        *  last registered. Stop executing if CY_SYSPM_FAIL was returned in
        *  CY_SYSPM_CHECK_READY mode
        */
        while ((curCallback != NULL) && ((retVal != CY_SYSPM_FAIL) || (mode != CY_SYSPM_CHECK_READY)))
        {
            /* The modes defined in the .skipMode element are not executed */
            if (0UL == ((uint32_t) mode & curCallback->skipMode))
            {
                /* Update elements for local callback parameter values */
                curParams.base = curCallback->callbackParams->base;
                curParams.context = curCallback->callbackParams->context;

                retVal = curCallback->callback(&curParams, mode);

                /* Update callback pointer with value of executed callback.
                * Such update is required to execute further callbacks in
                * backward order after exit from LP mode or to undo
                * configuration after callback returned fail: from last called
                * to first registered.
                */
                lastExecutedCallback = curCallback;
            }
            curCallback = curCallback->nextItm;
        }

        if (mode == CY_SYSPM_CHECK_READY)
        {
            /* Update the pointer to  the failed callback with the result of the callback execution.
            *  If the callback fails, the value of the pointer will be updated
            *  with the address of the callback which returned CY_SYSPM_FAIL, else,
            *  it will be updated with NULL.
            */
            if(retVal == CY_SYSPM_FAIL)
            {
                failedCallback[(uint32_t) type] = lastExecutedCallback;
            }
            else
            {
                failedCallback[(uint32_t) type] = NULL;
            }
        }
    }
    else
    {
        /* Execute registered callbacks with order from lastCallback or last
        * executed to the first registered callback. Such a flow is required if
        * a previous callback function returned CY_SYSPM_FAIL or a previous
        * callback mode was CY_SYSPM_BEFORE_TRANSITION. Such an order is
        * required to undo configurations in correct backward order.
        */
        if (mode != CY_SYSPM_CHECK_FAIL)
        {
            while (curCallback->nextItm != NULL)
            {
                curCallback = curCallback->nextItm;
            }
        }
        else
        {
            /* Skip last executed callback that returns CY_SYSPM_FAIL, as this
            *  callback already knows that it failed.
            */
            curCallback = lastExecutedCallback;

            if (curCallback != NULL)
            {
                curCallback = curCallback->prevItm;
            }
        }

        /* Execute callback functions with required type and mode */
        while (curCallback != NULL)
        {
            /* The modes defined in the .skipMode element are not executed */
            if (0UL == ((uint32_t) mode & curCallback->skipMode))
            {
                /* Update elements for local callback parameter values */
                curParams.base = curCallback->callbackParams->base;
                curParams.context = curCallback->callbackParams->context;

                retVal = curCallback->callback(&curParams, mode);
            }
            curCallback = curCallback->prevItm;
        }
    }

    return retVal;
}


/*******************************************************************************
* Function Name: Cy_SysPm_GetFailedCallback
****************************************************************************//**
*
* Reads the result of the callback execution after the power mode functions
* execution.
*
* This function reads the value of the pointer that stores the result of callback
* execution. It takes power mode as the parameter and returns the address of the
* callback configuration structure in the case of failure or NULL in the case of
* success. This address of the failed callback allows finding the callback that
* blocks entering power mode.
*
* \param type
* Power mode for which a callback execution result is required.
*
* \return
* - The address of the callback configuration structure if the callback handler
* function failed.
* - NULL if the callback skipped or executed successfully.
*
*******************************************************************************/
cy_stc_syspm_callback_t* Cy_SysPm_GetFailedCallback(cy_en_syspm_callback_type_t type)
{
    return failedCallback[(uint32_t) type];
}

#if defined(CY_IP_M0S8SRSSHV)

/*******************************************************************************
* Function Name: Cy_SysPm_SupplySupervisionStatus
****************************************************************************//**
*
* Return the status of the supply supervision
*
* \param supplyEntitySelect
* \ref cy_en_syspm_supply_entity_select_t which status have to be checked
*
* \return
* - True if the supply entity is OK
* - False if if the supply entity is not OK
*
* \note Applicable to PSOC4 HVMS/PA only.
*
*******************************************************************************/
bool Cy_SysPm_SupplySupervisionStatus(cy_en_syspm_supply_entity_select_t supplyEntitySelect)
{
    bool result = false;
    switch(supplyEntitySelect)
    {
        case CY_SYSPM_OVD_VDD_OK:
            {
                result = _FLD2BOOL(SRSSHV_PWR_SSV_STATUS_OVDVDDD_OK, SRSSHV->PWR_SSV_STATUS);
            }
            break;

        case CY_SYSPM_OVD_VCC_OK:
            {
                result = _FLD2BOOL(SRSSHV_PWR_SSV_STATUS_OVDVCCD_OK, SRSSHV->PWR_SSV_STATUS);
            }
            break;

        case CY_SYSPM_BOD_VDD_OK:
            {
                result = _FLD2BOOL(SRSSHV_PWR_SSV_STATUS_BODVDDD_OK, SRSSHV->PWR_SSV_STATUS);
            }
            break;

        case CY_SYSPM_BOD_VCC_OK:
            {
                result = _FLD2BOOL(SRSSHV_PWR_SSV_STATUS_BODVCCD_OK, SRSSHV->PWR_SSV_STATUS);
            }
            break;

        case CY_SYSPM_BOD_HV_OK:
            {
                result = _FLD2BOOL(SRSSHV_PWR_SSV_STATUS_BODHVSS_OK, SRSSHV->PWR_SSV_STATUS);
            }
            break;
        default:
            {
                result = false;
            }
            break;
    }
    return result;
}

/*******************************************************************************
* Function Name: Cy_SysPm_BodHVEnable
****************************************************************************//**
*
* Enable Brown-out detection for HV supply
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \note You can check status by the \ref Cy_SysPm_SupplySupervisionStatus function
*
* \funcusage
* \snippet syspm_snippet.c snippet_Cy_SysPm_BodHVEnable
*******************************************************************************/
void Cy_SysPm_BodHVEnable(void)
{
    /*
     * To avoid LockProtReg from ISR, enter critical section.
     */
    uint32_t state = Cy_SysLib_EnterCriticalSection();
    Cy_SysClk_UnlockProtReg();
    SRSSHV->PWR_SSV_CTL |= SRSSHV_PWR_SSV_CTL_BODHVSS_ENABLE_Msk;
    Cy_SysClk_LockProtReg();
    /* Exit out of critical section. */
    Cy_SysLib_ExitCriticalSection(state);
}

/*******************************************************************************
* Function Name: Cy_SysPm_BodHVDisable
****************************************************************************//**
*
* Disable Brown-out detection for HV supply
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \note You can check status by the \ref Cy_SysPm_SupplySupervisionStatus function
*
* \funcusage
* \snippet syspm_snippet.c snippet_Cy_SysPm_BodHVDisable
*
*******************************************************************************/
void Cy_SysPm_BodHVDisable(void)
{
    /*
     * To avoid LockProtReg from ISR, enter critical section.
     */
    uint32_t state = Cy_SysLib_EnterCriticalSection();
    Cy_SysClk_UnlockProtReg();
    SRSSHV->PWR_SSV_CTL &= ~SRSSHV_PWR_SSV_CTL_BODHVSS_ENABLE_Msk;
    Cy_SysClk_LockProtReg();
    /* Exit out of critical section. */
    Cy_SysLib_ExitCriticalSection(state);
}

/*******************************************************************************
* Function Name: Cy_SysPm_OvdEnable
****************************************************************************//**
*
* Enable OverVoltage detection for selected supply
*
* \param ovdSel
* \ref cy_en_syspm_ovd_sel_t on which supply OVD have to be enabled
*
* \note You can check OVD status by the \ref Cy_SysPm_SupplySupervisionStatus function
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \funcusage
* \snippet syspm_snippet.c snippet_Cy_SysPm_OvdEnable
*
*******************************************************************************/
void Cy_SysPm_OvdEnable(cy_en_syspm_ovd_sel_t ovdSel)
{
    CY_ASSERT_L2(CY_SYSPM_OVD_SEL_IS_VALID(ovdSel));

    /* avoid (un)lock race condition */
    uint32_t intrState = Cy_SysLib_EnterCriticalSection();
    /* disable protection before operation */
    Cy_SysClk_UnlockProtReg();
    switch(ovdSel)
    {
        case CY_SYSPM_OVD_VDD:
            {
                SRSSHV->PWR_SSV_CTL |= SRSSHV_PWR_SSV_CTL_OVDVDDD_ENABLE_Msk;
            }
            break;

        case CY_SYSPM_OVD_VCC:
            {
                SRSSHV->PWR_SSV_CTL |= SRSSHV_PWR_SSV_CTL_OVDVCCD_ENABLE_Msk;
            }
            break;
        default:
            /* do nothing */
            break;
    }
    Cy_SysClk_LockProtReg();
    Cy_SysLib_ExitCriticalSection(intrState);
}

/*******************************************************************************
* Function Name: Cy_SysPm_OvdDisable
****************************************************************************//**
*
* Disable OverVoltage detection for selected supply
*
* \param ovdSel
* \ref cy_en_syspm_ovd_sel_t on which supply OVD have to be disabled
*
* \note You can check OVD status by the \ref Cy_SysPm_SupplySupervisionStatus function
*
* \note Applicable to PSOC4 HVMS/PA only.
*
* \funcusage
* \snippet syspm_snippet.c snippet_Cy_SysPm_OvdDisable
*
*******************************************************************************/
void Cy_SysPm_OvdDisable(cy_en_syspm_ovd_sel_t ovdSel)
{
    CY_ASSERT_L2(CY_SYSPM_OVD_SEL_IS_VALID(ovdSel));

    /* avoid (un)lock race condition */
    uint32_t intrState = Cy_SysLib_EnterCriticalSection();
    /* disable protection before operation */
    Cy_SysClk_UnlockProtReg();
    switch(ovdSel)
    {
        case CY_SYSPM_OVD_VDD:
            {
                SRSSHV->PWR_SSV_CTL &= ~SRSSHV_PWR_SSV_CTL_OVDVDDD_ENABLE_Msk;
            }
            break;

        case CY_SYSPM_OVD_VCC:
            {
                SRSSHV->PWR_SSV_CTL &= ~SRSSHV_PWR_SSV_CTL_OVDVCCD_ENABLE_Msk;
            }
            break;

        default:
            /* do nothing */
            break;
    }
    Cy_SysClk_LockProtReg();
    Cy_SysLib_ExitCriticalSection(intrState);
}

#endif /* defined(CY_IP_M0S8SRSSHV) */

/* [] END OF FILE */
