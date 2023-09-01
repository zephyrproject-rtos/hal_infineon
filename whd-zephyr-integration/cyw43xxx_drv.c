/*
 * Copyright (c) 2023 Cypress Semiconductor Corporation (an Infineon company) or
 * an affiliate of Cypress Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 * @brief CYW43xxx wifi driver.
 */

#define DT_DRV_COMPAT infineon_cyw43xxx_wifi_sdio

#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(infineon_cyw43xxx_wifi, CONFIG_WIFI_LOG_LEVEL);

#include <zephyr/net/ethernet.h>
#include <zephyr/net/net_pkt.h>
#include <zephyr/net/net_if.h>
#include <zephyr/device.h>
#include <soc.h>

#include <zephyr/net/wifi_mgmt.h>
#include <zephyr/net/net_offload.h>
#include <zephyr/net/net_event.h>
#include <zephyr/net/net_mgmt.h>

#include <cybsp_wifi.h>
#include <cyhal.h>
#include <whd_types.h>
#include <whd_events_int.h>
#include <whd_buffer_api.h>
#include <cy_network_buffer.h>
#include <cybsp_wifi.h>
#include <cybsp.h>

#ifndef CYW43XXX_TX_PACKET_POOL_COUNT
#define CYW43XXX_TX_PACKET_POOL_COUNT (10)
#endif

#ifndef CYW43XXX_RX_PACKET_POOL_COUNT
#define CYW43XXX_RX_PACKET_POOL_COUNT (10)
#endif

#ifndef CYW43XXX_PACKET_POOL_SIZE
#define CYW43XXX_PACKET_POOL_SIZE (1600)
#endif

#define CYW43XXX_PACKET_POOL_COUNT (CYW43XXX_TX_PACKET_POOL_COUNT + CYW43XXX_RX_PACKET_POOL_COUNT)

/* This macro is copy of NET_BUF_POOL_FIXED_DEFINE with aligning net_buf_data_##_name
 * WHD requires that network buffers is aligned, NET_BUF_POOL_FIXED_DEFINE does not
 * guarantees aligned.
 */
#define NET_BUF_POOL_FIXED_DEFINE_ALIGN(_name, _count, _data_size, _ud_size, _destroy)             \
	_NET_BUF_ARRAY_DEFINE(_name, _count, _ud_size);                                            \
	static uint8_t __noinit net_buf_data_##_name[_count][_data_size] __net_buf_align;          \
	static const struct net_buf_pool_fixed net_buf_fixed_##_name = {                           \
		.data_size = _data_size,                                                           \
		.data_pool = (uint8_t *)net_buf_data_##_name,                                      \
	};                                                                                         \
	static const struct net_buf_data_alloc net_buf_fixed_alloc_##_name = {                     \
		.cb = &net_buf_fixed_cb,                                                           \
		.alloc_data = (void *)&net_buf_fixed_##_name,                                      \
	};                                                                                         \
	static STRUCT_SECTION_ITERABLE(net_buf_pool, _name) = NET_BUF_POOL_INITIALIZER(            \
		_name, &net_buf_fixed_alloc_##_name, _net_buf_##_name, _count, _ud_size, _destroy)

#define CYW43XXX_WAIT_SEMA_MS (30 * 1000)

/* Allocate network pool */
NET_BUF_POOL_FIXED_DEFINE_ALIGN(cyw43xxx_pool, CYW43XXX_PACKET_POOL_COUNT,
				CYW43XXX_PACKET_POOL_SIZE, 0, NULL);

static uint16_t ap_event_handler_index = 0xFF;

/* Use global iface pointer to support any Ethernet driver */
/* necessary for wifi callback functions */
static struct net_if *cyw43xxx_wifi_iface;

struct cyw43xxx_wifi_runtime {
	struct net_if *iface;
	bool second_interface_init;
	bool is_ap_up;
	bool is_sta_connected;
	uint8_t mac_addr[6];
	scan_result_cb_t scan_rslt_cb;
	whd_ssid_t ssid;
	whd_scan_result_t scan_result;
	struct k_sem sema_common;
	struct k_sem sema_scan;
	uint8_t frame_buf[NET_ETH_MAX_FRAME_SIZE];
#if defined(CONFIG_NET_STATISTICS_WIFI)
	struct net_stats_wifi stats;
#endif
};

struct cy43xxx_event_t {
	uint8_t is_ap_event;
	uint32_t event_type;
};

whd_interface_t cyw43xxx_if;
whd_interface_t cyw43xxx_ap_if;

static const whd_event_num_t sta_link_events[] = {
	WLC_E_LINK,    WLC_E_DEAUTH_IND,       WLC_E_DISASSOC_IND,
	WLC_E_PSK_SUP, WLC_E_CSA_COMPLETE_IND, WLC_E_NONE};

static const whd_event_num_t ap_link_events[] = {WLC_E_DISASSOC_IND, WLC_E_DEAUTH_IND,
						 WLC_E_ASSOC_IND,    WLC_E_REASSOC_IND,
						 WLC_E_AUTHORIZED,   WLC_E_NONE};

static uint16_t sta_event_handler_index = 0xFF;
static void cyw43xxx_event_task(void);
static cyhal_sdio_t sdio_obj;
static struct cyw43xxx_wifi_runtime cyw43xxx_wifi_data = {0};

K_MSGQ_DEFINE(cyw43xxx_wifi_msgq, sizeof(whd_event_header_t), 10, 4);
K_THREAD_STACK_DEFINE(cyw43xxx_wifi_event_stack, CONFIG_CYW43XXX_WIFI_EVENT_TASK_STACK_SIZE);

static struct k_thread cyw43xxx_wifi_event_thread;

cyhal_sdio_t *cybsp_get_wifi_sdio_obj(void)
{
	return &sdio_obj;
}

whd_interface_t cyw43xx_get_whd_interface(void)
{
	return cyw43xxx_if;
}

whd_result_t cy_host_buffer_get(whd_buffer_t *buffer, whd_buffer_dir_t direction, uint16_t size,
				uint32_t timeout_ms)
{
	ARG_UNUSED(direction);
	ARG_UNUSED(timeout_ms);
	struct net_buf *buf;

	buf = net_buf_alloc_len(&cyw43xxx_pool, size, K_NO_WAIT);
	if (buf == NULL) {
		return WHD_BUFFER_ALLOC_FAIL;
	}
	*buffer = buf;
	return WHD_SUCCESS;
}

void cy_buffer_release(whd_buffer_t buffer, whd_buffer_dir_t direction)
{
	CY_UNUSED_PARAMETER(direction);
	(void)net_buf_destroy((struct net_buf *)buffer);
}

uint8_t *cy_buffer_get_current_piece_data_pointer(whd_buffer_t buffer)
{
	CY_ASSERT(buffer != NULL);
	struct net_buf *buf = (struct net_buf *)buffer;

	return (uint8_t *)buf->data;
}

uint16_t cy_buffer_get_current_piece_size(whd_buffer_t buffer)
{
	CY_ASSERT(buffer != NULL);
	struct net_buf *buf = (struct net_buf *)buffer;

	return (uint16_t)buf->size;
}

whd_result_t cy_buffer_set_size(whd_buffer_t buffer, unsigned short size)
{
	CY_ASSERT(buffer != NULL);
	struct net_buf *buf = (struct net_buf *)buffer;

	buf->size = size;
	return CY_RSLT_SUCCESS;
}

whd_result_t cy_buffer_add_remove_at_front(whd_buffer_t *buffer, int32_t add_remove_amount)
{
	CY_ASSERT(buffer != NULL);
	struct net_buf **buf = (struct net_buf **)buffer;

	if (add_remove_amount > 0) {
		(*buf)->len = (*buf)->size;
		(*buf)->data = net_buf_pull(*buf, add_remove_amount);
	} else {
		(*buf)->data = net_buf_push(*buf, -add_remove_amount);
		(*buf)->len = (*buf)->size;
	}
	return WHD_SUCCESS;
}

static int cyw43xxx_mgmt_send(const struct device *dev, struct net_pkt *pkt)
{
	struct cyw43xxx_wifi_runtime *data = dev->data;
	cy_rslt_t ret = CY_RSLT_SUCCESS;
	size_t pkt_len = net_pkt_get_len(pkt);
	struct net_buf *buf = NULL;

	/* Read the packet payload */
	if (net_pkt_read(pkt, data->frame_buf, pkt_len) < 0) {
		LOG_ERR("net_pkt_read failed");
		return -EIO;
	}

	/* Allocate Network Buffer from pool with Packet Length + Data Header */
	buf = net_buf_alloc_len(&cyw43xxx_pool, pkt_len + sizeof(data_header_t), K_NO_WAIT);
	if (buf == NULL) {
		return -EIO;
	}

	/* Reserve the buffer Headroom for WHD Data header */
	net_buf_reserve(buf, sizeof(data_header_t));

	/* Copy the buffer to network Buffer pointer */
	(void)memcpy(buf->data, data->frame_buf, pkt_len);

	/* Call WHD API to send out the Packet */
	ret = whd_network_send_ethernet_data(cyw43xxx_if, (void *)buf);
	if (ret != CY_RSLT_SUCCESS) {
		LOG_ERR("whd_network_send_ethernet_data failed");
#if defined(CONFIG_NET_STATISTICS_WIFI)
		data->stats.errors.tx++;
#endif
		return -EIO;
	}

#if defined(CONFIG_NET_STATISTICS_WIFI)
	data->stats.bytes.sent += pkt_len;
	data->stats.pkts.tx++;
#endif

	return 0;
}

void cy_network_process_ethernet_data(whd_interface_t interface, whd_buffer_t buffer)
{
	struct net_pkt *pkt;
	uint8_t *data = whd_buffer_get_current_piece_data_pointer(interface->whd_driver, buffer);
	uint32_t len = whd_buffer_get_current_piece_size(interface->whd_driver, buffer);
	bool net_pkt_unref_flag = false;

	if ((interface->role == WHD_STA_ROLE) &&
	    (net_if_flag_is_set(cyw43xxx_wifi_iface, NET_IF_UP))) {
		if (cyw43xxx_wifi_iface == NULL) {
			LOG_ERR("network interface unavailable");
			cy_buffer_release(buffer, WHD_NETWORK_RX);
			return;
		}

		pkt = net_pkt_rx_alloc_with_buffer(cyw43xxx_wifi_iface, len, AF_UNSPEC, 0,
						   K_NO_WAIT);

		if (pkt != NULL) {
			if (net_pkt_write(pkt, data, len) < 0) {
				LOG_ERR("Failed to write pkt");
				net_pkt_unref_flag = true;
			}

			if ((net_pkt_unref_flag) || (net_recv_data(cyw43xxx_wifi_iface, pkt) < 0)) {
				LOG_ERR("Failed to push received data");
				net_pkt_unref_flag = true;
			}
		} else {
			LOG_ERR("Failed to get net buffer");
		}
	}
	/* Release a packet buffer */
	cy_buffer_release(buffer, WHD_NETWORK_RX);

#if defined(CONFIG_NET_STATISTICS_WIFI)
	cyw43xxx_wifi_data.stats.bytes.received += len;
	cyw43xxx_wifi_data.stats.pkts.rx++;
#endif

	if (net_pkt_unref_flag) {
		net_pkt_unref(pkt);
#if defined(CONFIG_NET_STATISTICS_WIFI)
		cyw43xxx_wifi_data.stats.errors.rx++;
#endif
	}
}

static void *link_events_handler(whd_interface_t ifp, const whd_event_header_t *event_header,
				 const uint8_t *event_data, void *handler_user_data)
{
	ARG_UNUSED(ifp);
	ARG_UNUSED(event_data);
	ARG_UNUSED(handler_user_data);

	(void)k_msgq_put(&cyw43xxx_wifi_msgq, event_header, K_FOREVER);
	return NULL;
}

static void cyw43xxx_event_task(void)
{
	whd_event_header_t event_header;

	while (1) {
		(void)k_msgq_get(&cyw43xxx_wifi_msgq, &event_header, K_FOREVER);

		switch ((whd_event_num_t)event_header.event_type) {
		case WLC_E_LINK:
			break;

		case WLC_E_DEAUTH_IND:
		case WLC_E_DISASSOC_IND:
			net_if_dormant_on(cyw43xxx_wifi_iface);
			break;

		default:
			break;
		}
	}
}

static void cyw43xxx_mgmt_init(struct net_if *iface)
{
	const struct device *dev = net_if_get_device(iface);
	struct cyw43xxx_wifi_runtime *data = dev->data;
	struct ethernet_context *eth_ctx = net_if_l2_data(iface);

	eth_ctx->eth_if_type = L2_ETH_IF_TYPE_WIFI;
	data->iface = iface;
	cyw43xxx_wifi_iface = iface;

	/* Read WLAN MAC Address */
	(void)whd_wifi_get_mac_address(cyw43xxx_if, &cyw43xxx_if->mac_addr);
	(void)memcpy(&data->mac_addr, &cyw43xxx_if->mac_addr, sizeof(cyw43xxx_if->mac_addr));

	/* Assign link local address. */
	(void)net_if_set_link_addr(iface, data->mac_addr, 6, NET_LINK_ETHERNET);

	(void)ethernet_init(iface);

	/* Not currently connected to a network */
	(void)net_if_dormant_on(iface);

	/* L1 network layer (physical layer) is up */
	(void)net_if_carrier_on(data->iface);
}

whd_result_t cy_buffer_pool_init(void *tx_packet_pool, void *rx_packet_pool)
{
	CY_UNUSED_PARAMETER(tx_packet_pool);
	CY_UNUSED_PARAMETER(rx_packet_pool);

	return 0;
}

static void scan_cb_search(whd_scan_result_t **result_ptr, void *user_data,
			   whd_scan_status_t status)
{
	if (status == WHD_SCAN_ABORTED) {
		k_sem_give(&cyw43xxx_wifi_data.sema_scan);
		return;
	}
	if (status == WHD_SCAN_COMPLETED_SUCCESSFULLY) {
		k_sem_give(&cyw43xxx_wifi_data.sema_scan);
	} else if (status == WHD_SCAN_INCOMPLETE) {
		if (user_data != NULL) {
			if ((**result_ptr).SSID.length > 0) {
				if (strcmp((**result_ptr).SSID.value,
					   ((whd_scan_result_t *)user_data)->SSID.value) == 0) {
					memcpy(user_data, *result_ptr, sizeof(whd_scan_result_t));
				}
			}
		}
	}
}

static void parse_scan_result(whd_scan_result_t *p_whd_result, struct wifi_scan_result *p_zy_result)
{
	if (p_whd_result->SSID.length != 0) {
		p_zy_result->ssid_length = p_whd_result->SSID.length;
		sprintf(p_zy_result->ssid, "%s", p_whd_result->SSID.value);
		p_zy_result->channel = p_whd_result->channel;
		p_zy_result->security = (p_whd_result->security == 0) ? WIFI_SECURITY_TYPE_NONE
								      : WIFI_SECURITY_TYPE_PSK;
		p_zy_result->rssi = (int8_t)p_whd_result->signal_strength;
		p_zy_result->mac_length = 6;
		memcpy(p_zy_result->mac, &p_whd_result->BSSID, 6);
	}
}

static void scan_callback(whd_scan_result_t **result_ptr, void *user_data, whd_scan_status_t status)
{
	struct cyw43xxx_wifi_runtime *data = (struct cyw43xxx_wifi_runtime *)user_data;
	whd_scan_result_t whd_scan_result;
	struct wifi_scan_result zephyr_scan_result;

	if (status == WHD_SCAN_COMPLETED_SUCCESSFULLY || status == WHD_SCAN_ABORTED) {
		data->scan_rslt_cb(data->iface, 0, NULL);

		return;
	}
	if ((result_ptr != NULL) || (*result_ptr != NULL)) {
		memcpy(&whd_scan_result, *result_ptr, sizeof(whd_scan_result_t));
		parse_scan_result(&whd_scan_result, &zephyr_scan_result);
		data->scan_rslt_cb(data->iface, 0, &zephyr_scan_result);
	}
	memset(*result_ptr, 0, sizeof(whd_scan_result_t));
}

static int cyw43xxx_mgmt_scan(const struct device *dev, struct wifi_scan_params *params,
			      scan_result_cb_t cb)
{
	int ret = 0;
	struct cyw43xxx_wifi_runtime *data = (struct cyw43xxx_wifi_runtime *)dev->data;

	data->scan_rslt_cb = cb;

	if (k_sem_take(&data->sema_common, K_MSEC(CYW43XXX_WAIT_SEMA_MS)) != 0) {
		return -EAGAIN;
	}

	ret = whd_wifi_scan(cyw43xxx_if, params->scan_type, WHD_BSS_TYPE_ANY, &(data->ssid), NULL,
			    NULL, NULL, scan_callback, &(data->scan_result), data);

	k_sem_give(&data->sema_common);
	return ret;
}

static int cyw43xxx_mgmt_connect(const struct device *dev, struct wifi_connect_req_params *params)
{
	struct cyw43xxx_wifi_runtime *data = (struct cyw43xxx_wifi_runtime *)dev->data;
	whd_ssid_t ssid = {0};
	int ret = 0;

	if (k_sem_take(&data->sema_common, K_MSEC(CYW43XXX_WAIT_SEMA_MS)) != 0) {
		return -EAGAIN;
	}

	if (data->is_sta_connected) {
		LOG_ERR("Already connected");
		ret = -EALREADY;
		goto error;
	}

	ssid.length = params->ssid_length;
	memcpy(ssid.value, params->ssid, params->ssid_length);

	whd_scan_result_t scan_result;
	whd_scan_result_t usr_result = {0};

	usr_result.SSID.length = ssid.length;
	memcpy(usr_result.SSID.value, ssid.value, ssid.length);

	if (whd_wifi_scan(cyw43xxx_if, WHD_SCAN_TYPE_ACTIVE, WHD_BSS_TYPE_ANY, NULL, NULL, NULL,
			  NULL, scan_cb_search, &scan_result, &(usr_result)) != WHD_SUCCESS) {
		LOG_ERR("Failed start scan");
		ret = -EAGAIN;
		goto error;
	}

	if (k_sem_take(&cyw43xxx_wifi_data.sema_scan, K_MSEC(12 * 1000)) != 0) {
		whd_wifi_stop_scan(cyw43xxx_if);
		ret = -EAGAIN;
		goto error;
	}

	if (usr_result.security == 0) {
		ret = -EAGAIN;
		goto error;
	}

	/* Connect to the network */
	if (whd_wifi_join(cyw43xxx_if, &usr_result.SSID, usr_result.security, params->psk,
			  params->psk_length) != WHD_SUCCESS) {
		LOG_ERR("Failed to connect with network");
		ret = -EAGAIN;
		goto error;
	}

error:
	if (ret < 0) {
		net_if_dormant_on(data->iface);
	} else {
		net_dhcpv4_start(data->iface);
		net_if_dormant_off(data->iface);
		data->is_sta_connected = 1;
	}

	wifi_mgmt_raise_connect_result_event(data->iface, ret);
	k_sem_give(&data->sema_common);
	return ret;
}

static int cyw43xxx_mgmt_disconnect(const struct device *dev)
{
	int ret = 0;
	struct cyw43xxx_wifi_runtime *data = (struct cyw43xxx_wifi_runtime *)dev->data;

	if (k_sem_take(&data->sema_common, K_MSEC(CYW43XXX_WAIT_SEMA_MS)) != 0) {
		return -EAGAIN;
	}

	if (whd_wifi_leave(cyw43xxx_if) != WHD_SUCCESS) {
		k_sem_give(&data->sema_common);
		ret = -EAGAIN;
	} else {
		data->is_sta_connected = 0;
		net_dhcpv4_stop(data->iface);
		net_if_dormant_on(data->iface);
	}

	wifi_mgmt_raise_disconnect_result_event(data->iface, ret);
	k_sem_give(&data->sema_common);

	return ret;
}

static void *ap_link_events_handler(whd_interface_t ifp, const whd_event_header_t *event_header,
				    const uint8_t *event_data, void *handler_user_data)
{
	struct cy43xxx_event_t cy43xxx_event = {.is_ap_event = 1,
						.event_type = event_header->event_type};

	k_msgq_put(&cyw43xxx_wifi_msgq, &cy43xxx_event, K_FOREVER);
	return NULL;
}

static int cyw43xxx_mgmt_ap_enable(const struct device *dev, struct wifi_connect_req_params *params)
{
	struct cyw43xxx_wifi_runtime *data = (struct cyw43xxx_wifi_runtime *)dev->data;
	whd_security_t security;
	whd_ssid_t ssid = {0};
	uint8_t channel = 0;

	if (k_sem_take(&data->sema_common, K_MSEC(CYW43XXX_WAIT_SEMA_MS)) != 0) {
		return -EAGAIN;
	}

	if (data->second_interface_init == 0) {
		if (cybsp_wifi_init_secondary(&cyw43xxx_ap_if, NULL) != CY_RSLT_SUCCESS) {
			LOG_ERR("Error Unable to bring up the whd secondary interface");
			k_sem_give(&data->sema_common);
			return -EAGAIN;
		}
		data->second_interface_init = 1;
	}

	if (data->is_ap_up) {
		LOG_ERR("Already AP is on - first disconnect");
		k_sem_give(&data->sema_common);
		return -EAGAIN;
	}

	ssid.length = params->ssid_length;
	memcpy((void *)ssid.value, (void *)params->ssid, ssid.length);

	if (((params->channel > 0) && (params->channel < 12)) ||
	    ((params->channel > 35) && (params->channel < 166))) {
		channel = params->channel;
	} else {
		channel = 1;
	}

	if (params->psk_length == 0) {
		security = WHD_SECURITY_OPEN;
	} else {
		security = WHD_SECURITY_WPA2_AES_PSK;
	}

	if (whd_wifi_init_ap(cyw43xxx_ap_if, &ssid, security, (const uint8_t *)params->psk,
			     params->psk_length, channel) != 0) {
		LOG_ERR("Failed to init whd ap interface");
		k_sem_give(&data->sema_common);
		return -EAGAIN;
	}

	if (whd_wifi_start_ap(cyw43xxx_ap_if) != 0) {
		LOG_ERR("Failed to start whd ap interface");
		k_sem_give(&data->sema_common);
		return -EAGAIN;
	}

	/* set event handler */
	if (whd_management_set_event_handler(cyw43xxx_ap_if, ap_link_events, ap_link_events_handler,
					     NULL, &ap_event_handler_index) != 0) {
		whd_wifi_stop_ap(cyw43xxx_ap_if);
		k_sem_give(&data->sema_common);
		return -EAGAIN;
	}

	data->is_ap_up = 1;

	k_sem_give(&data->sema_common);
	return 0;
}

#if defined(CONFIG_NET_STATISTICS_WIFI)
static int cyw43xxx_mgmt_wifi_stats(const struct device *dev, struct net_stats_wifi *stats)
{
	struct cyw43xxx_wifi_runtime *data = dev->data;

	stats->bytes.received = data->stats.bytes.received;
	stats->bytes.sent = data->stats.bytes.sent;
	stats->pkts.rx = data->stats.pkts.rx;
	stats->pkts.tx = data->stats.pkts.tx;
	stats->errors.rx = data->stats.errors.rx;
	stats->errors.tx = data->stats.errors.tx;
	stats->broadcast.rx = data->stats.broadcast.rx;
	stats->broadcast.tx = data->stats.broadcast.tx;
	stats->multicast.rx = data->stats.multicast.rx;
	stats->multicast.tx = data->stats.multicast.tx;
	stats->sta_mgmt.beacons_rx = data->stats.sta_mgmt.beacons_rx;
	stats->sta_mgmt.beacons_miss = data->stats.sta_mgmt.beacons_miss;

	return 0;
}
#endif

static int cyw43xxx_mgmt_ap_disable(const struct device *dev)
{
	int ret = 0;
	struct cyw43xxx_wifi_runtime *data = (struct cyw43xxx_wifi_runtime *)dev->data;

	if (k_sem_take(&data->sema_common, K_MSEC(CYW43XXX_WAIT_SEMA_MS)) != 0) {
		return -EAGAIN;
	}

	whd_wifi_deregister_event_handler(cyw43xxx_ap_if, ap_event_handler_index);
	whd_wifi_stop_ap(cyw43xxx_ap_if);
	data->is_ap_up = 0;

	k_sem_give(&data->sema_common);
	return ret;
}

static int cyw43xxx_init(const struct device *dev)
{
	cy_rslt_t ret = CY_RSLT_SUCCESS;
	struct cyw43xxx_wifi_runtime *data = (struct cyw43xxx_wifi_runtime *)dev->data;

	cyhal_gpio_t sdio_cmd =
		DT_GET_CYHAL_GPIO_FROM_DT_GPIOS(WHD_SDIO_NODE, sdio_cmd_gpios);

	cyhal_gpio_t sdio_clk =
		DT_GET_CYHAL_GPIO_FROM_DT_GPIOS(WHD_SDIO_NODE, sdio_clk_gpios);

	cyhal_gpio_t sdio_d0 =
		DT_GET_CYHAL_GPIO_FROM_DT_GPIOS_IDX(WHD_SDIO_NODE, sdio_data_gpios, 0);

	cyhal_gpio_t sdio_d1 =
		DT_GET_CYHAL_GPIO_FROM_DT_GPIOS_IDX(WHD_SDIO_NODE, sdio_data_gpios, 1);

	cyhal_gpio_t sdio_d2 =
		DT_GET_CYHAL_GPIO_FROM_DT_GPIOS_IDX(WHD_SDIO_NODE, sdio_data_gpios, 2);

	cyhal_gpio_t sdio_d3 =
		DT_GET_CYHAL_GPIO_FROM_DT_GPIOS_IDX(WHD_SDIO_NODE, sdio_data_gpios, 3);

	ret = cyhal_sdio_init(&sdio_obj, sdio_cmd, sdio_clk, sdio_d0, sdio_d1, sdio_d2, sdio_d3);
	if (ret != CY_RSLT_SUCCESS) {
		LOG_ERR("cyhal_sdio_init failed ret = %d \r\n", ret);
	}

	k_tid_t tid = k_thread_create(
		&cyw43xxx_wifi_event_thread, cyw43xxx_wifi_event_stack,
		CONFIG_CYW43XXX_WIFI_EVENT_TASK_STACK_SIZE, (k_thread_entry_t)cyw43xxx_event_task,
		NULL, NULL, NULL, CONFIG_CYW43XXX_WIFI_EVENT_TASK_PRIO, K_INHERIT_PERMS, K_NO_WAIT);

	k_thread_name_set(tid, "cyw43xxx_event");

	ret = cybsp_wifi_init_primary_extended(&cyw43xxx_if, NULL, NULL, NULL, NULL);
	if (ret != CY_RSLT_SUCCESS) {
		LOG_ERR("cybsp_wifi_init_primary_extended failed ret = %d \r\n", ret);
	}
	ret = whd_management_set_event_handler(cyw43xxx_if, sta_link_events, link_events_handler,
					       NULL, &sta_event_handler_index);
	if (ret != CY_RSLT_SUCCESS) {
		LOG_ERR("whd_management_set_event_handler failed ret = %d \r\n", ret);
	}

	k_sem_init(&data->sema_common, 1, 1);
	k_sem_init(&data->sema_scan, 0, 1);

	return ret;
}

/* Implement WHD memory wrappers */
void *whd_mem_malloc(size_t size)
{
	return k_malloc(size);
}

void *whd_mem_calloc(size_t nitems, size_t size)
{
	return k_calloc(nitems, size);
}

void whd_mem_free(void *ptr)
{
	k_free(ptr);
}

static const struct wifi_mgmt_ops cyw43xxx_wifi_mgmt = {
	.scan = cyw43xxx_mgmt_scan,
	.connect = cyw43xxx_mgmt_connect,
	.disconnect = cyw43xxx_mgmt_disconnect,
	.ap_enable = cyw43xxx_mgmt_ap_enable,
	.ap_disable = cyw43xxx_mgmt_ap_disable,
#if defined(CONFIG_NET_STATISTICS_ETHERNET)
	.get_stats = cyw43xxx_mgmt_wifi_stats,
#endif

};

static const struct net_wifi_mgmt_offload cyw43xxx_api = {
	.wifi_iface.iface_api.init = cyw43xxx_mgmt_init,
	.wifi_iface.send = cyw43xxx_mgmt_send,
	.wifi_mgmt_api = &cyw43xxx_wifi_mgmt,
};

NET_DEVICE_DT_INST_DEFINE(0, cyw43xxx_init, NULL, &cyw43xxx_wifi_data, NULL,
			  CONFIG_WIFI_INIT_PRIORITY, &cyw43xxx_api, ETHERNET_L2,
			  NET_L2_GET_CTX_TYPE(ETHERNET_L2), NET_ETH_MTU);
