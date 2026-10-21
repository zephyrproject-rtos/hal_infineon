/** file: s_ipc.c */

#include "cy_ms_ctl.h"
#include "cy_ipc_drv.h"
#include "cy_sysint.h"
#include "cy_ipc_sema.h"
#include "cy_ipc_pipe.h"

/* Note: To test PIPE user needs to define this macro TEST_PIPE in makefile */
//#define TEST_PIPE     /* Enables pipe test code for testing purpose */

/** Make sure that cm33-ns app should use same ipc channel to send message to cm33-s */
#define CM33_NS_IPC_CH_NUM                 (CY_IPC_CHAN_USER)
#define CM33_NS_IPC_CH_MASK                (CY_IPC_CH_MASK(CM33_NS_IPC_CH_NUM))
#define CM33_NS_IPC_INTR_NUM               (CY_IPC_INTR_USER)
#define CM33_NS_IPC_INTR_MASK              (CY_IPC_INTR_MASK(CM33_NS_IPC_INTR_NUM))
#define CM33_NS_IPC_INTR_MUX               (CY_IPC_INTR_MUX(CM33_NS_IPC_INTR_NUM))
/******************************************************************************/

#define CM33_S_IPC_INTR_PRIORITY       (1U)

/* Interrupt configuration */
/* Setup the  IPC Interrupt */
const cy_stc_sysint_t ipcIntConfig =
{
    .intrSrc = (IRQn_Type)CM33_S_IPC_INTR_MUX,
    .intrPriority = CM33_S_IPC_INTR_PRIORITY
};

CY_SECTION_SHAREDMEM uint32_t writeMesg;    /** cm33-s shared memory*/

CY_SECTION_SHAREDMEM
CY_ALIGN(32) uint32_t mySemaData; /* So there are 32 semaphores */
#define  SEMAPHORE_COUNT    (sizeof(uint32_t)*8UL)
#define MY_SEMA_NUM                     (3UL)

void ipc_cm33_s_isr(void);
int config_ipc(void);

/*******************************************************************************/
/************************************** PIPE ***********************************/
#ifdef TEST_PIPE

#define CY_IPC_MAX_ENDPOINTS            (2UL) /* <<< 2 endpoints */
#define CY_IPC_CYPIPE_CLIENT_CNT        (2UL)
#define CM33_S_CH_NUM               (CM33_S_IPC_CH_NUM)
#define CM33_S_INTR_NUM             (CM33_S_IPC_INTR_NUM)

#define CM33_NS_CH_NUM              (CM33_NS_IPC_CH_NUM)
#define CM33_NS_INTR_NUM            (CM33_NS_IPC_INTR_NUM)

#define CM33_S_INTR_MUX            (CY_IPC_INTR_MUX(CM33_S_INTR_NUM))
#define CM33_S_CH_MASK              (CY_IPC_CH_MASK(CM33_S_CH_NUM))

typedef struct
{
    uint8_t  clientID;      /**< Client ID */
    uint8_t  pktType;       /**< Message Type */
    uint16_t intrRelMask;   /**< Mask */
} cy_stc_ipc_testmsg_t;

typedef enum
{
    CY_IPC_PKT_FROM_CM33S_TO_CM33NS,
    CY_IPC_PKT_FROM_CM33NS_TO_CM33S,
} cy_en_ipc_pktType_t;

/* Channel 0 goes to EP1 */
#define CY_IPC_CHAN_CYPIPE_EP1          (CM33_S_CH_NUM) /* IPC data channel for CYPIPE EP1 */
#define CY_IPC_CYPIPE_CHAN_MASK_EP1     CY_IPC_CH_MASK(CY_IPC_CHAN_CYPIPE_EP1)
#define CY_IPC_INTR_CYPIPE_EP1          (CM33_S_INTR_NUM)   /* IPC Intr for EP1 */
#define CY_IPC_CYPIPE_INTR_MASK_EP1     CY_IPC_INTR_MASK(CY_IPC_INTR_CYPIPE_EP1)   /* IPC Intr Mask for EP1 */
#define CY_IPC_INTR_CYPIPE_PRIOR_EP1    (1UL)   /* Notifier Priority */
#define CY_IPC_INTR_CYPIPE_MUX_EP1      CY_IPC_INTR_MUX(CY_IPC_INTR_CYPIPE_EP1)  /* Intr Mux for CM33 */
#define CY_IPC_EP_CYPIPE_CM33S_ADDR      (0UL)   /* EP1 Index of Endpoint Array */
#define CY_CLIENT_CYPIPE0_CM33S_ID0      (0UL)   /* EP1 Pipe0 (CM33S <--> CM33NS) Index of client cb Array */

/* Channel 1 goes to EP2 */
#define CY_IPC_CHAN_CYPIPE_EP2          (CM33_NS_CH_NUM) /* IPC data channel for CYPIPE EP2 */
#define CY_IPC_CYPIPE_CHAN_MASK_EP2     CY_IPC_CH_MASK(CY_IPC_CHAN_CYPIPE_EP2)
#define CY_IPC_INTR_CYPIPE_EP2          (CM33_NS_INTR_NUM)
#define CY_IPC_CYPIPE_INTR_MASK_EP2     CY_IPC_INTR_MASK(CY_IPC_INTR_CYPIPE_EP2)   /* IPC Intr Mask for EP2 */
#define CY_IPC_INTR_CYPIPE_PRIOR_EP2    (1UL)   /* Notifier Priority */
#define CY_IPC_INTR_CYPIPE_MUX_EP2      CY_IPC_INTR_MUX(CY_IPC_INTR_CYPIPE_EP2)   /* Intr Mux for CM33 */
#define CY_IPC_EP_CYPIPE_CM33NS_ADDR    (1UL)   /* EP2 Index of Endpoint Array */
#define CY_CLIENT_CYPIPE0_CM33NS_ID0    (1UL)   /* EP2 Pipe1 (CM33NS <--> CM33S) Index of client cb Array */

#define CY_IPC_CYPIPE_INTR_MASK   (CY_IPC_CYPIPE_CHAN_MASK_EP1 | CY_IPC_CYPIPE_CHAN_MASK_EP2)


#define CY_IPC_CYPIPE_CONFIG_EP1  ( (CY_IPC_CYPIPE_INTR_MASK << CY_IPC_PIPE_CFG_IMASK_Pos) \
                                   | (CY_IPC_INTR_CYPIPE_EP1 << CY_IPC_PIPE_CFG_INTR_Pos) \
                                    | CY_IPC_CHAN_CYPIPE_EP1)

#define CY_IPC_CYPIPE_CONFIG_EP2  ( (CY_IPC_CYPIPE_INTR_MASK << CY_IPC_PIPE_CFG_IMASK_Pos) \
                                   | (CY_IPC_INTR_CYPIPE_EP2 << CY_IPC_PIPE_CFG_INTR_Pos) \
                                    | CY_IPC_CHAN_CYPIPE_EP2)

bool cm33_pipe0_msg_executed = false;
bool cm33_pipe0_msg_received = false;

void Pipe0_cm33_RecvMsgCallback(uint32_t * msgData)
{
    /* The release callback will be automatically called on the sender side
     * just after returning from this callback
     */
#if CM33_PRINT_ON
    cy_stc_ipc_testmsg_t *pData = (cy_stc_ipc_testmsg_t*)msgData;
    Cy_SysLib_Delay(10);
    printf ("[Pipe0][EP1][CM33] RecvMsgCallback ---> \r\n\n");
    printf("[Pipe0][EP1][CM33] Received data for Client[%d] message Type is %d \r\n", pData->clientID, pData->pktType);
    printf ("<--- [Pipe0][EP1][CM33] RecvMsgCallback\r\n\n");
#endif
    Cy_SysLib_Delay(10);
    cm33_pipe0_msg_received = true;
    CY_UNUSED_PARAMETER(msgData);
}

void Pipe0_cm33_ReleaseCallback(void)
{
    /* The sent data is already processed on the receiver side,
     * the pipe is ready for next transactions
     */
#if CM33_PRINT_ON
    Cy_SysLib_Delay(10);
    printf ("[Pipe0][EP1][CM33] ReleaseCallback ---> \r\n\n");
    printf ("<--- [Pipe0][EP1][CM33] ReleaseCallback\r\n\n");
#endif
    cm33_pipe0_msg_executed = true;
    Cy_SysLib_Delay(10);
}

void Pipe0_cm33_DefaultReleaseCallback(void)
{
    /* The Cy_IPC_Pipe_SendMessage was called without a pointer to specific callback,
     * therefore this one is called.
     * The sent data is already processed on the receiver side,
     * the pipe is ready for next transactions
     */
#if CM33_PRINT_ON
    Cy_SysLib_Delay(10);
    printf ("[Pipe0][EP1][CM33] DefaultReleaseCallback ---> \r\n\n");
    printf ("<--- [Pipe0][EP1][CM33] DefaultReleaseCallback\r\n\n");
#endif
    Cy_SysLib_Delay(10);
}

cy_stc_ipc_testmsg_t cm33MsgData0 CY_SECTION_SHAREDMEM;

/* configure ipc between cm33-s and cm33-ns */
void config_ipc_pipe(void)
{
    cy_en_ipc_pipe_status_t pipeStatus;

    /* Create an array of endpoint structures */
    static cy_stc_ipc_pipe_ep_t systemIpcPipeEpArray[CY_IPC_MAX_ENDPOINTS];

    Cy_IPC_Pipe_Config(systemIpcPipeEpArray);
#if CM33_PRINT_ON
    printf("[CM33] IPC Application Main...\r\n");
#endif
    static cy_ipc_pipe_callback_ptr_t ep0CbArray[CY_IPC_CYPIPE_CLIENT_CNT]; /* CB Array for EP0 */

    static const cy_stc_ipc_pipe_config_t systemIpcPipe0ConfigCm33s =
    {
        {
            /* .ipcNotifierNumber     */  CY_IPC_INTR_CYPIPE_EP1,
            /* .ipcNotifierPriority  */  CY_IPC_INTR_CYPIPE_PRIOR_EP1,
            /* .ipcNotifierMuxNumber */  CY_IPC_INTR_CYPIPE_MUX_EP1,
            /* .epAddress             */  CY_IPC_EP_CYPIPE_CM33S_ADDR,
            /* .epConfig              */ CY_IPC_CYPIPE_CONFIG_EP1
        },
        {
            /* .ipcNotifierNumber     */  CY_IPC_INTR_CYPIPE_EP2,
            /* .ipcNotifierPriority  */  CY_IPC_INTR_CYPIPE_PRIOR_EP2,
            /* .ipcNotifierMuxNumber */  CY_IPC_INTR_CYPIPE_MUX_EP2,
            /* .epAddress             */  CY_IPC_EP_CYPIPE_CM33NS_ADDR,
            /* .epConfig              */ CY_IPC_CYPIPE_CONFIG_EP2
        },
    /* .endpointClientsCount     */  CY_IPC_CYPIPE_CLIENT_CNT,
    /* .endpointsCallbacksArray  */  ep0CbArray,
    /* .userPipeIsrHandler         */  &ipc_cm33_s_isr
    };

#if CM33_PRINT_ON
#if defined (__ARMCC_VERSION)
    printf ("[CM33][EP0] IPC Channel-%ld address[0x%x] Intr-%ld address[0x%x] \r\n", CY_IPC_CHAN_CYPIPE_EP1,
                                                                                    (uint32_t)Cy_IPC_Drv_GetIpcBaseAddress(CY_IPC_CHAN_CYPIPE_EP1),
                                                                                    CY_IPC_INTR_CYPIPE_EP1,
                                                                                    (uint32_t)Cy_IPC_Drv_GetIntrBaseAddr(CY_IPC_INTR_CYPIPE_EP1));
#else
    printf ("[CM33][EP0] IPC Channel-%d address[0x%lx] Intr-%d address[0x%lx] \r\n", CY_IPC_CHAN_CYPIPE_EP1,
                                                                                    (uint32_t)Cy_IPC_Drv_GetIpcBaseAddress(CY_IPC_CHAN_CYPIPE_EP1),
                                                                                    CY_IPC_INTR_CYPIPE_EP1,
                                                                                    (uint32_t)Cy_IPC_Drv_GetIntrBaseAddr(CY_IPC_INTR_CYPIPE_EP1));
#endif // __ARMCC_VERSION
#endif

    Cy_IPC_Pipe_Init(&systemIpcPipe0ConfigCm33s); /* PIPE-0 EP0 <--> EP1 */

    /* pipe-0 register callback (epAddr, callBackPtr, clientId) */
    pipeStatus = Cy_IPC_Pipe_RegisterCallback(CY_IPC_EP_CYPIPE_CM33S_ADDR, &Pipe0_cm33_RecvMsgCallback,
                                                      (uint32_t)CY_CLIENT_CYPIPE0_CM33S_ID0);
#if CM33_PRINT_ON
    printf ("[Pipe-0][EP0][CM33] Register Receive Callback status[0x%x]\r\n",pipeStatus);

#else
    (void)pipeStatus;
#endif
}


/* This is the interrupt service routine for the system pipe. */
void ipc_cm33_s_isr(void)
{
    Cy_SysLib_Delay(10);
    
#if CM33_PRINT_ON
    printf("[CM33]EP[1] is interrupted \r\n");
#endif
    Cy_SysLib_Delay(10);
    Cy_IPC_Pipe_ExecuteCallback(CY_IPC_EP_CYPIPE_CM33S_ADDR);

    /* set pc value to cm33-ns before returning from this isr */
    Cy_Ms_Ctl_SetActivePC(CPUSS_MS_ID_CM33_0, CM33_NS_PC_VALUE);
}

void send_pipe_secure_msg(void)
{
    /* Sending message to CM33 */
    cm33MsgData0.clientID = CY_CLIENT_CYPIPE0_CM33NS_ID0; /* Client CM33_ID0 will process this message */
    cm33MsgData0.pktType = CY_IPC_PKT_FROM_CM33S_TO_CM33NS;
    cm33MsgData0.intrRelMask = CY_IPC_CYPIPE_INTR_MASK_EP1; /* set the interrupt mask for EP0 interrupt number */
#if CM33_PRINT_ON
    /* Sending Data on Pipe-0 from EP0 to EP1 (toAddr, fromAddr, *msgPtr, callBackPtr) */
    printf ("[Pipe-0][EP0][CM33] Sending Packet Type [%d] to client [%d] \r\n",cm33MsgData0.pktType, cm33MsgData0.clientID);
#endif

    cy_en_ipc_pipe_status_t pipeStatus = Cy_IPC_Pipe_SendMessage(CY_IPC_EP_CYPIPE_CM33NS_ADDR, CY_IPC_EP_CYPIPE_CM33S_ADDR, (void *) &cm33MsgData0, Pipe0_cm33_ReleaseCallback);
#if CM33_PRINT_ON
    printf ("[Pipe-0][EP0][CM33] Send Message Status [0x%x] \r\n",pipeStatus);
#endif
    /* Wait for release callback of message */
    while(!cm33_pipe0_msg_executed)
    {
        Cy_SysLib_Delay(1000);
    }
    cm33_pipe0_msg_executed = false;
}

#else  /* TEST_PIPE */
/* Process IPC message received from remote core. returns a dummy message to be sent to remote core. */
void process_ipc_notify(uint32_t msg)
{
    /* read the data from memory address and write back the message to cm33-s shared memory */
    uint32_t *msgptr = (uint32_t*)GET_ALIAS_ADDRESS(msg);   /* Make sure it is a secure address */
    writeMesg = *msgptr;
    writeMesg++;
    *msgptr = (uint32_t)(writeMesg); /* write shared mem address */
}

/* post processing after successful message sent to remote core */
void process_ipc_release(void)
{
    /**/
}

/* message handling from remote core */
void ipc_cm33_s_isr(void)
{
    uint32_t shadowIntr;
    IPC_STRUCT_Type *ipcPtr;
    IPC_INTR_STRUCT_Type *ipcIntrPtr;
    uint32_t notifyMask;
    uint32_t relMask;
    uint32_t readMesg;

    ipcIntrPtr = Cy_IPC_Drv_GetIntrBaseAddr(CM33_S_IPC_INTR_NUM); /** all interrupt to cm33-s has to come from ipc-intr 0 */
    shadowIntr = Cy_IPC_Drv_GetInterruptStatusMasked(ipcIntrPtr);
    notifyMask = Cy_IPC_Drv_ExtractAcquireMask(shadowIntr);
    relMask = Cy_IPC_Drv_ExtractReleaseMask(shadowIntr);

    /* Notify Interrupt: Remote core sent message to cm33-s */
    if (0UL != notifyMask)
    {
        /* Clear the notify interrupt in IPC interrupt register */
        Cy_IPC_Drv_ClearInterrupt(ipcIntrPtr, CY_IPC_NO_NOTIFICATION, notifyMask);
        ipcPtr = Cy_IPC_Drv_GetIpcBaseAddress (CM33_S_IPC_CH_NUM);
        if (Cy_IPC_Drv_IsLockAcquired(ipcPtr))
        {
            readMesg = (uint32_t)Cy_IPC_Drv_ReadDataValue (ipcPtr);
            process_ipc_notify(readMesg);
        }

        /* release the current channel and trigger release event to the remote core */
        Cy_IPC_Drv_LockRelease(ipcPtr, CY_IPC_INTR_MASK(CM33_NS_IPC_INTR_NUM));
        //Cy_IPC_Drv_LockRelease(ipcPtr, CY_IPC_NO_NOTIFICATION);
    }

    /* Release Interrupt: Ack to cm33-s sent message from remote core */
    if (0UL != relMask)  /* Check for a Release interrupt */
    {
        /* Clear the release interrupt */
        Cy_IPC_Drv_ClearInterrupt(ipcIntrPtr, relMask, CY_IPC_NO_NOTIFICATION);
        process_ipc_release();
    }
    /* set pc value to cm33-ns before returning from this isr */
    Cy_Ms_Ctl_SetActivePC(CPUSS_MS_ID_CM33_0, CM33_NS_PC_VALUE);
}
#endif /* TEST_PIPE */


void send_ipc_secure_msg(void)
{
    writeMesg = 10;
    Cy_IPC_Drv_SendMsgPtr(Cy_IPC_Drv_GetIpcBaseAddress(CM33_NS_IPC_CH_NUM),
                                CM33_NS_IPC_INTR_MASK,
                                &writeMesg);
}


/* configure ipc between cm33-s and cm33-ns */
int config_ipc(void)
{
    cy_en_sysint_status_t intrStatus = CY_SYSINT_SUCCESS;

#if !defined(TEST_PIPE)
    intrStatus = Cy_SysInt_Init(&ipcIntConfig, ipc_cm33_s_isr);

    /* enable interrupts */
    __enable_irq();
    NVIC_EnableIRQ((IRQn_Type)CM33_S_IPC_INTR_MUX);

    /* Set IPC Interrupt mask to allow remote core to interrupt cm33-s core */
    Cy_IPC_Drv_SetInterruptMask(    Cy_IPC_Drv_GetIntrBaseAddr(CM33_S_IPC_INTR_NUM),
                                    (CM33_S_IPC_CH_MASK | CM33_NS_IPC_CH_MASK),
                                    (CM33_S_IPC_CH_MASK | CM33_NS_IPC_CH_MASK));

#if 0 /* test code for sema */
    Cy_IPC_Sema_Init(CM33_S_IPC_CH_NUM, SEMAPHORE_COUNT, &mySemaData);

    Cy_IPC_Sema_Set(MY_SEMA_NUM, false);
#endif

#else /* TEST_PIPE */
    config_ipc_pipe();
#endif /* TEST_PIPE */
    return (int)intrStatus;
}
