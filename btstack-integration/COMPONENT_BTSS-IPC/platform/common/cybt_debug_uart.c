#include "cybt_platform_config.h"

#ifdef ENABLE_DEBUG_UART

#define CYHAL_UART_DMA_ENABLE_RX FALSE
#define CYHAL_UART_DMA_ENABLE_TX FALSE

#include "cyhal_uart.h"
#include "cyabs_rtos.h"
#include "cybsp_types.h"
#include "cybt_platform_task.h"
#include "cybt_debug_uart.h"
#include "cybt_platform_interface.h"
#include "wiced_memory.h"

extern void host_stack_mutex_lock(void * p_lock_context);
extern void host_stack_mutex_unlock(void * p_lock_context);

#define HCI_WICED_PKT               0x19
#define HCI_WICED_OVERHEAD          5       // Type (1), opcode (2) and length (2)

#ifndef DISABLE_TX_TASK
#define BT_TASK_NAME_DEBUG_UART_TX       "TX_CYBT_DEBUG_UART_Task"
#define DEBUG_UART_TX_TASK_STACK_SIZE    (0x1700)
#define DEBUG_UART_TX_TASK_QUEUE_COUNT   (50)
#define DEBUG_UART_TX_QUEUE_ITEM_SIZE    (sizeof(void *))
#define DEBUG_UART_TX_TASK_QUEUE         cybt_debug_uart_tx_queue
#define DEBUG_UART_TX_TASK_PRIORITY      (CY_RTOS_PRIORITY_ABOVENORMAL)

#ifndef DEBUG_UART_MEMORY_SIZE
#define DEBUG_UART_MEMORY_SIZE           (6144)
#endif

wiced_bt_heap_t *debug_task_heap = NULL;
#endif

#define BT_TASK_NAME_DEBUG_UART_RX       "RX_CYBT_DEBUG_UART_Task"

#define DEBUG_UART_RX_TASK_STACK_SIZE    (0x1700)

#define DEBUG_UART_RX_TASK_PRIORITY     (CY_RTOS_PRIORITY_ABOVENORMAL)

#define WICED_HDR_SZ 5

#define MAX_RX_DATA_LEN                 1000

#define HCI_CONTROL_GROUP_DEVICE       0x00
#define HCI_CONTROL_EVENT_WICED_TRACE  ( ( HCI_CONTROL_GROUP_DEVICE << 8 ) | 0x02 )    /* WICED trace packet */
#define HCI_CONTROL_EVENT_HCI_TRACE    ( ( HCI_CONTROL_GROUP_DEVICE << 8 ) | 0x03 )    /* Bluetooth protocol trace */
#define INVALID_TYPE                    0xFF
#define GENERIC_TYPE                    0x00

enum
{
    HEADER_PHASE = 0,
    DATA_PHASE
};

typedef struct
{
    bool            inited;
    cyhal_uart_t    hal_obj;
#ifndef DISABLE_TX_TASK
    cy_semaphore_t  tx_complete;
    cy_semaphore_t  tx_ready;
    cy_mutex_t      tx_heap_lock;
#endif
    cy_semaphore_t  rx_complete;
    cy_mutex_t      tx_atomic;
} hci_uart_cb_t;

typedef struct
{
    uint16_t length;
    uint8_t *data;
}recv_data_t;

hci_uart_cb_t cy_trans_uart;
#ifndef DISABLE_TX_TASK
cy_queue_t  cybt_debug_uart_tx_queue;
cy_thread_t cybt_debug_uart_tx_task;
#endif
cy_thread_t cybt_debug_uart_rx_task;

/*
 * Global variable declarations
 */
uint8_t  wiced_rx_cmd[MAX_RX_DATA_LEN+WICED_HDR_SZ]; //RX command pool.


static bool trans_setup = false;
static cybt_debug_uart_data_handler_t  p_app_rx_cmd_handler =  NULL;
volatile bool rx_done = false;

static bool cybt_debug_uart_setup = false;

#ifdef DISABLE_TX_TASK

static cybt_result_t cybt_trans_blocking_write (uint8_t type, uint16_t opcode, uint16_t data_size, uint8_t *p_data);

#else

static cybt_result_t cybt_enqueue_tx_data (uint16_t type, uint16_t  op,uint16_t length, uint8_t* p_data);

BTSTACK_PORTING_SECTION_BEGIN
static void debug_heap_mutex_lock(void * p_lock_context)
{
    cy_rtos_get_mutex(p_lock_context, CY_RTOS_NEVER_TIMEOUT);
}
BTSTACK_PORTING_SECTION_END

BTSTACK_PORTING_SECTION_BEGIN
static void debug_heap_mutex_unlock(void * p_lock_context)
{
    cy_rtos_set_mutex(p_lock_context);
}
BTSTACK_PORTING_SECTION_END

BTSTACK_PORTING_SECTION_BEGIN
static void *cybt_platform_debug_task_mempool_alloc(uint32_t req_size)
{
    void *p_mem_block;

    if (NULL == debug_task_heap)
    {
        return NULL;
    }

    p_mem_block = (void *) wiced_bt_get_buffer_from_heap(debug_task_heap, req_size);

    return p_mem_block;
}
BTSTACK_PORTING_SECTION_END

BTSTACK_PORTING_SECTION_BEGIN
static void *cybt_memcpy (void *dest, const void *src, size_t len)
{
    uint8_t *pDest = (uint8_t*)dest;
    const uint8_t *pSrc = (const uint8_t*)src;
    while(len--)
    {
        *pDest++ = *pSrc++;
    }
    return dest;
}
BTSTACK_PORTING_SECTION_END

BTSTACK_PORTING_SECTION_BEGIN
static void cybt_platform_debug_task_mempool_free(void *p_mem_block)
{
    wiced_bt_free_buffer((wiced_bt_buffer_t *) p_mem_block);
}
BTSTACK_PORTING_SECTION_END

BTSTACK_PORTING_SECTION_BEGIN
static cybt_result_t cybt_enqueue_tx_data (uint16_t type, uint16_t  opcode, uint16_t length, uint8_t* p_data)
{
    uint8_t     *p_buf = NULL, *p_buf_start = NULL;
    cy_rslt_t   result = CYBT_ERR_GENERIC;
    size_t      count = 0;

    if (trans_setup == false)
        return CYBT_ERR_GENERIC;

    result = cy_rtos_get_semaphore(&cy_trans_uart.tx_ready, CY_RTOS_NEVER_TIMEOUT, false);

    if (CY_RSLT_SUCCESS != result)
        return CYBT_ERR_GENERIC;

    result = cy_rtos_count_queue(&DEBUG_UART_TX_TASK_QUEUE, &count);
    if ( (result != CY_RSLT_SUCCESS) || (count == DEBUG_UART_TX_TASK_QUEUE_COUNT))
    {
        cy_rtos_set_semaphore(&cy_trans_uart.tx_ready, false);
        return CYBT_ERR_QUEUE_FULL;
    }

    p_buf = cybt_platform_debug_task_mempool_alloc(length + HCI_WICED_OVERHEAD + 1);
    if (p_buf == NULL)
    {
        cy_rtos_set_semaphore(&cy_trans_uart.tx_ready, false);
        return CYBT_ERR_OUT_OF_MEMORY;
    }
    p_buf_start = p_buf;

    *p_buf++ = HCI_WICED_PKT;

    if ( (type != INVALID_TYPE) || (opcode == HCI_CONTROL_EVENT_HCI_TRACE) )
    {
        *p_buf++ = (uint8_t)(HCI_CONTROL_EVENT_HCI_TRACE);
        *p_buf++ = (uint8_t)(HCI_CONTROL_EVENT_HCI_TRACE >> 8);
        *p_buf++ = (uint8_t)(length + 1);
        *p_buf++ = (uint8_t)((length + 1) >> 8);
        *p_buf++ = type;
    }
    else
    {
        *p_buf++ = (uint8_t)(opcode);
        *p_buf++ = (uint8_t)(opcode >> 8);
        *p_buf++ = (uint8_t)(length);
        *p_buf++ = (uint8_t)(length >> 8);
    }

    cybt_memcpy (p_buf, p_data, length);

    result = cy_rtos_put_queue (&DEBUG_UART_TX_TASK_QUEUE, (void *) &p_buf_start, 0, false);

    if (CY_RSLT_SUCCESS != result)
        cybt_platform_debug_task_mempool_free((void *)p_buf_start);

    cy_rtos_set_semaphore(&cy_trans_uart.tx_ready, false);
    return CYBT_SUCCESS;
}
BTSTACK_PORTING_SECTION_END

BTSTACK_PORTING_SECTION_BEGIN
cybt_result_t cybt_debug_uart_send_wiced_hci_buf (void *p_buf)
{
    cy_rslt_t   result = CYBT_ERR_GENERIC;
    size_t      count = 0;

    if (trans_setup == false)
        return CYBT_ERR_GENERIC;

    result = cy_rtos_get_semaphore(&cy_trans_uart.tx_ready, CY_RTOS_NEVER_TIMEOUT, false);

    if (CY_RSLT_SUCCESS != result)
        return CYBT_ERR_GENERIC;

    result = cy_rtos_count_queue(&DEBUG_UART_TX_TASK_QUEUE, &count);
    if ( (result != CY_RSLT_SUCCESS) || (count == DEBUG_UART_TX_TASK_QUEUE_COUNT))
    {
        cy_rtos_set_semaphore (&cy_trans_uart.tx_ready, false);
        return CYBT_ERR_QUEUE_FULL;
    }

    result = cy_rtos_put_queue (&DEBUG_UART_TX_TASK_QUEUE, (void *) &p_buf, 0, false);

    cy_rtos_set_semaphore(&cy_trans_uart.tx_ready, false);
    return (cybt_result_t)result;
}
BTSTACK_PORTING_SECTION_END

BTSTACK_PORTING_SECTION_BEGIN
static void cybt_debug_tx_task(void *arg)
{
    cy_rslt_t   result;
    uint8_t     *p_data;
    size_t      data_len;

    while (1)
    {
        p_data = NULL;
        result = cy_rtos_get_queue(&DEBUG_UART_TX_TASK_QUEUE,
                                   (void *)&p_data,
                                   CY_RTOS_NEVER_TIMEOUT,
                                   false
                                   );

        if (CY_RSLT_SUCCESS != result || NULL == p_data)
            continue;

        // Payload is in bytes 3 and 4
        data_len = ((p_data[4] << 8) | p_data[3]);

        result = cyhal_uart_write_async (&cy_trans_uart.hal_obj, p_data, data_len + HCI_WICED_OVERHEAD);

        if (CY_RSLT_SUCCESS == result)
            cy_rtos_get_semaphore (&cy_trans_uart.tx_complete, CY_RTOS_NEVER_TIMEOUT, false);

        cybt_platform_debug_task_mempool_free (p_data);
    }
}
BTSTACK_PORTING_SECTION_END

#endif

BTSTACK_PORTING_SECTION_BEGIN
static void cybt_debug_rx_task(void *arg)
{
    cy_rslt_t result;
    volatile uint32_t numAvailable = 0;
    volatile size_t expectedlength = 0;
    volatile uint32_t head=0,phase=HEADER_PHASE,data_counter=0;

    while(1)
    {
        result = cy_rtos_get_semaphore(&cy_trans_uart.rx_complete, CY_RTOS_NEVER_TIMEOUT, false);

        if (result != CY_RSLT_SUCCESS)
            continue;

        numAvailable = 0;
        expectedlength = ( phase == DATA_PHASE ) ? ( data_counter ) : ( WICED_HDR_SZ );
        if (!rx_done)
        {
            if (CYHAL_UART_DMA_ENABLE_RX == TRUE)
            {
                cyhal_uart_enable_event(&cy_trans_uart.hal_obj, CYHAL_UART_IRQ_RX_DONE, 4u, true);
                cyhal_uart_read_async(&cy_trans_uart.hal_obj, wiced_rx_cmd + head, expectedlength);
                continue;
            }
            else
            {
                numAvailable = cyhal_uart_readable(&cy_trans_uart.hal_obj);
                if (numAvailable >= expectedlength)
                {
                    cyhal_uart_read(&cy_trans_uart.hal_obj, wiced_rx_cmd + head, (size_t *)&expectedlength);
                    numAvailable -= expectedlength;
                }
                else
                {
                    cyhal_uart_enable_event(&cy_trans_uart.hal_obj, CYHAL_UART_IRQ_RX_DONE, CYHAL_ISR_PRIORITY_DEFAULT, true);
                    cyhal_uart_read_async(&cy_trans_uart.hal_obj, wiced_rx_cmd + head, expectedlength);
                    continue;
                }
            }
        }

        if (numAvailable == 0)
        {
            rx_done = false;
            cyhal_uart_enable_event(&cy_trans_uart.hal_obj, CYHAL_UART_IRQ_RX_NOT_EMPTY, CYHAL_ISR_PRIORITY_DEFAULT, true);
        }

        switch (phase)
        {
            case HEADER_PHASE:
                if(wiced_rx_cmd[0] != HCI_WICED_PKT)
                {
                    head=0x0;
                    break;
                }
                data_counter = ( wiced_rx_cmd[3] | (uint32_t)(wiced_rx_cmd[4])<<8);
                head  = WICED_HDR_SZ;
                phase = DATA_PHASE;
                break;
            case DATA_PHASE:
                data_counter -= expectedlength;
                head         += expectedlength;
                break;
        }

        if ( (data_counter == 0) && (head != 0) && (p_app_rx_cmd_handler != NULL) )
        {
            phase = HEADER_PHASE;
            host_stack_mutex_lock(NULL);
            p_app_rx_cmd_handler(wiced_rx_cmd+1, head-1);
            host_stack_mutex_unlock(NULL);
            head = 0;
        }

        if (numAvailable != 0)
        {
            // re-enter the loop if data is available
            cy_rtos_set_semaphore(&cy_trans_uart.rx_complete, true);
            continue;
        }
    }
}
BTSTACK_PORTING_SECTION_END

cybt_result_t cybt_init_debug_trans_task(void)
{
    cy_rslt_t result;

    if(true == trans_setup)
        return CYBT_SUCCESS;

#ifndef DISABLE_TX_TASK
    {
        void *p_heap_mem = NULL;

        cy_rtos_init_mutex(&cy_trans_uart.tx_heap_lock);

        wiced_bt_lock_t lock = {
            .p_lock_context = &cy_trans_uart.tx_heap_lock,
            .pf_lock_func = debug_heap_mutex_lock,
            .pf_unlock_func = debug_heap_mutex_unlock
        };

        p_heap_mem = (wiced_bt_heap_t *)cybt_platform_malloc(DEBUG_UART_MEMORY_SIZE);
        if (p_heap_mem == NULL)
            return CYBT_ERR_OUT_OF_MEMORY;

        debug_task_heap = wiced_bt_create_heap("CYBT_DEBUG_TASK_POOL",
                                               p_heap_mem,
                                               DEBUG_UART_MEMORY_SIZE,
                                               &lock,
                                               FALSE
                                               );

        result = cy_rtos_init_queue(&DEBUG_UART_TX_TASK_QUEUE,
                                    DEBUG_UART_TX_TASK_QUEUE_COUNT,
                                    DEBUG_UART_TX_QUEUE_ITEM_SIZE
                                    );
        if (result != CY_RSLT_SUCCESS)
            return CYBT_ERR_INIT_QUEUE_FAILED;

        result = cy_rtos_create_thread(&cybt_debug_uart_tx_task,
                                       cybt_debug_tx_task,
                                       BT_TASK_NAME_DEBUG_UART_TX,
                                       NULL,
                                       DEBUG_UART_TX_TASK_STACK_SIZE,
                                       DEBUG_UART_TX_TASK_PRIORITY,
                                       (cy_thread_arg_t) NULL
                                       );
        if (result != CY_RSLT_SUCCESS)
            return CYBT_ERR_CREATE_TASK_FAILED;
    }
#endif

    result = cy_rtos_create_thread(&cybt_debug_uart_rx_task,
                                   cybt_debug_rx_task,
                                   BT_TASK_NAME_DEBUG_UART_RX,
                                   NULL,
                                   DEBUG_UART_RX_TASK_STACK_SIZE,
                                   DEBUG_UART_RX_TASK_PRIORITY,
                                   (cy_thread_arg_t) NULL
                                   );

    if (result != CY_RSLT_SUCCESS)
        return CYBT_ERR_CREATE_TASK_FAILED;

    trans_setup = true;
    return CYBT_SUCCESS;
}

#ifndef DISABLE_TX_TASK
static void cybt_uart_tx_irq(void)
{
    cy_rtos_set_semaphore(&cy_trans_uart.tx_complete, true);
}
#endif

BTSTACK_PORTING_SECTION_BEGIN
static void cybt_uart_irq_handler_(void *handler_arg, cyhal_uart_event_t event)
{
    switch(event)
    {
        case CYHAL_UART_IRQ_RX_NOT_EMPTY:
            cyhal_uart_enable_event(&cy_trans_uart.hal_obj, CYHAL_UART_IRQ_RX_NOT_EMPTY, CYHAL_ISR_PRIORITY_DEFAULT, false);
            cy_rtos_set_semaphore(&cy_trans_uart.rx_complete, true);
            break;
        case CYHAL_UART_IRQ_RX_DONE:
            rx_done = true;
            cyhal_uart_enable_event(&cy_trans_uart.hal_obj, CYHAL_UART_IRQ_RX_DONE, CYHAL_ISR_PRIORITY_DEFAULT, false);
            cy_rtos_set_semaphore(&cy_trans_uart.rx_complete, true);
            break;
#ifndef DISABLE_TX_TASK
        case CYHAL_UART_IRQ_TX_DONE:
            cybt_uart_tx_irq();
            break;
#endif
        default:
            break;
    }
}
BTSTACK_PORTING_SECTION_END

cybt_result_t cybt_debug_uart_init(cybt_debug_uart_config_t *config, cybt_debug_uart_data_handler_t p_data_handler)
{
    const cyhal_uart_cfg_t uart_config =
    {
        .data_bits = 8,
        .stop_bits = 1,
        .parity = CYHAL_UART_PARITY_NONE,
        .rx_buffer = NULL,
        .rx_buffer_size = 0,
    };
    uint16_t enable_irq_event = (CYHAL_UART_IRQ_TX_DONE
                                 | CYHAL_UART_IRQ_RX_NOT_EMPTY
                                 );
    cy_rslt_t result = CY_RSLT_SUCCESS;

    if(!cybt_debug_uart_setup)
        memset(&cy_trans_uart, 0, sizeof(hci_uart_cb_t));
    else
        memset(&cy_trans_uart.hal_obj, 0, sizeof(cyhal_uart_t));
	
    if (!config)
    {
        return CYBT_ERR_BADARG;
    }

    #if (CYHAL_API_VERSION >= 2)
    {
        /* init and setting flow control */
        result = cyhal_uart_init(&cy_trans_uart.hal_obj,
                                       config->uart_tx_pin,
                                       config->uart_rx_pin,
                                       config->uart_cts_pin,
                                       config->uart_rts_pin,
                                       NULL,
                                       &uart_config
                                      );
    }
    #else // HAL API version 1
    {
        result = cyhal_uart_init(&cy_trans_uart.hal_obj, config->uart_tx_pin, config->uart_rx_pin, NULL, &uart_config);
        if(result != CY_RSLT_SUCCESS)
            return CYBT_ERR_HCI_INIT_FAILED;

        if (config->flow_control)
        {
            result = cyhal_uart_set_flow_control(&cy_trans_uart.hal_obj, config->uart_cts_pin, config->uart_rts_pin);
        }
    }
    #endif

    if(result != CY_RSLT_SUCCESS)
        return (CYBT_ERR_HCI_INIT_FAILED);

#if ( (CYHAL_UART_DMA_ENABLE_RX == TRUE) || (CYHAL_UART_DMA_ENABLE_TX == TRUE) )
    cyhal_uart_set_async_mode(&cy_trans_uart.hal_obj, CYHAL_ASYNC_DMA, 3);
#endif

    result = cyhal_uart_set_baud(&cy_trans_uart.hal_obj, config->baud_rate, NULL);
    if(result != CY_RSLT_SUCCESS)
        return (CYBT_ERR_HCI_INIT_FAILED);

    if(!cybt_debug_uart_setup)
    {
#ifndef DISABLE_TX_TASK
        cy_rtos_init_semaphore(&cy_trans_uart.tx_complete, 1, 0);
        cy_rtos_init_semaphore(&cy_trans_uart.tx_ready, 1, 1);
#endif
        cy_rtos_init_semaphore(&cy_trans_uart.rx_complete, 1, 0);

        cy_rtos_init_mutex(&cy_trans_uart.tx_atomic);
    }

    cyhal_uart_register_callback(&cy_trans_uart.hal_obj, cybt_uart_irq_handler_, NULL);

    cyhal_uart_enable_event(&cy_trans_uart.hal_obj, (cyhal_uart_event_t)enable_irq_event,
                            CYHAL_ISR_PRIORITY_DEFAULT, true);

    cy_trans_uart.inited = true;
    p_app_rx_cmd_handler = p_data_handler;

    if(!cybt_debug_uart_setup)
    {
        cybt_debug_uart_setup = true;
	}
    return CYBT_SUCCESS;
}

void cybt_debug_uart_deinit()
{
	if(cybt_debug_uart_setup)
	{
		cyhal_uart_free(&cy_trans_uart.hal_obj);
		cy_trans_uart.inited = false;
		cy_rtos_set_semaphore(&cy_trans_uart.tx_complete, true);
	}
}

cybt_result_t cybt_debug_uart_send_trace(uint16_t length, uint8_t* p_data)
{
#ifdef DISABLE_TX_TASK
    return cybt_trans_blocking_write(INVALID_TYPE, HCI_CONTROL_EVENT_WICED_TRACE, length, p_data);
#else
    return cybt_enqueue_tx_data(INVALID_TYPE, HCI_CONTROL_EVENT_WICED_TRACE, length, p_data);
#endif
}

BTSTACK_PORTING_SECTION_BEGIN
cybt_result_t cybt_debug_uart_send_data (uint16_t opcode, uint16_t data_size, uint8_t *p_data)
{
#ifdef DISABLE_TX_TASK
    return cybt_trans_blocking_write(INVALID_TYPE,(uint16_t)opcode, data_size, p_data);
#else
    return cybt_enqueue_tx_data(INVALID_TYPE, (uint16_t)opcode, data_size, p_data);
#endif
}
BTSTACK_PORTING_SECTION_END

BTSTACK_PORTING_SECTION_BEGIN
cybt_result_t cybt_debug_uart_send_hci_trace (uint8_t type, uint16_t data_size, uint8_t *p_data)
{
#ifdef DISABLE_TX_TASK
    return cybt_trans_blocking_write((uint16_t)type, HCI_CONTROL_EVENT_HCI_TRACE, data_size, p_data);
#else
    return cybt_enqueue_tx_data((uint16_t)type, HCI_CONTROL_EVENT_HCI_TRACE, data_size, p_data);
#endif
}
BTSTACK_PORTING_SECTION_END

cybt_result_t cybt_send_coredump_hci_trace (uint16_t data_size, uint8_t *p_data)
{
#ifdef DISABLE_TX_TASK
    return cybt_trans_blocking_write(GENERIC_TYPE, HCI_CONTROL_EVENT_HCI_TRACE, data_size, p_data);
#else
    return cybt_enqueue_tx_data(GENERIC_TYPE, HCI_CONTROL_EVENT_HCI_TRACE, data_size, p_data);
#endif
}

#ifdef DISABLE_TX_TASK

BTSTACK_PORTING_SECTION_BEGIN
cybt_result_t cybt_trans_blocking_write (uint8_t type, uint16_t op, uint16_t data_size, uint8_t *p_data)
{
    cybt_result_t result = CYBT_ERR_GENERIC;
    cy_rslt_t status = CY_RSLT_SUCCESS;
    size_t index = 0;
    uint8_t opcode = (uint8_t)(op&0xff);
    uint8_t group_code = (uint8_t)((op >> 8)&0xff);
    uint8_t data[2000];
    int nChars = 0;
    char *ptr = NULL;

    if (cy_trans_uart.inited == false)
        return CYBT_ERR_GENERIC;

    status = cy_rtos_get_mutex(&cy_trans_uart.tx_atomic, CY_RTOS_NEVER_TIMEOUT);

    if(CY_RSLT_SUCCESS != status)
    {
        return result;
    }

    data[index++] = HCI_WICED_PKT;

    if ( (type != 0xFF) || ((group_code == 0x00) && (opcode == 0x03)) )
    {
        uint16_t new_size = (data_size+1);
        data[index++] = 0x03;
        data[index++] = 0x00;
        data[index++] = (uint8_t)(new_size&0xff);
        data[index++] = (uint8_t)((new_size >> 8)&0xff);
        data[index++] = type;
    }
    else
    {
        data[index++] = opcode;
        data[index++] = group_code;
        data[index++] = (uint8_t)(data_size&0xff);
        data[index++] = (uint8_t)((data_size >> 8)&0xff);
    }
    memcpy(&data[index], p_data, data_size);
    index += data_size;

    /*! NB TODO
    * Remove local data var. Print individual bytes. */
    ptr = (char *)&data[0];
    for (/* Empty */; nChars < index; ++nChars)
    {
        cyhal_uart_putc(&cy_trans_uart.hal_obj, *ptr);
        ++ptr;
    }

    cy_rtos_set_mutex(&cy_trans_uart.tx_atomic);
    return result;
}
BTSTACK_PORTING_SECTION_END
#endif // DISABLE_TX_TASK

int _write(int fd, const char* ptr, int len)
{
    if(cybt_debug_uart_send_trace(len,(uint8_t* )ptr) == CYBT_SUCCESS)
    {
        return len;
    }
    return 0;
}

#endif // ENABLE_DEBUG_UART
