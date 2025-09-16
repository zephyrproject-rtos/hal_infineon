/*
 *  Cypress Semiconductor Apache2 n */
/* Automatically generated file - this comment ensures resources.h file creation */
/* Auto-generated header file. Do not edit */
#ifndef INCLUDED_CLM_RESOURCES_H_
#define INCLUDED_CLM_RESOURCES_H_
#include "wiced_resource.h"

extern const resource_hnd_t wifi_firmware_clm_blob;
extern const unsigned char wifi_firmware_clm_blob_data[];

#ifndef RESOURCE_READ_FROM_C_FILE
extern uint32_t wifi_firmware_clm_blob_size;

#ifndef __IAR_SYSTEMS_ICC__
#ifdef CY_STORAGE_WIFI_DATA
RESOURCE_BIN_ADD(".cy_xip.clm", CLM_IMAGE_NAME, wifi_firmware_clm_blob_data, wifi_firmware_clm_blob_size);
#else
RESOURCE_BIN_ADD(".rodata", CLM_IMAGE_NAME, wifi_firmware_clm_blob_data, wifi_firmware_clm_blob_size);
#endif /* ifdef CY_STORAGE_WIFI_DATA */
#endif /* ifndef __IAR_SYSTEMS_ICC__ */
const resource_hnd_t wifi_firmware_clm_blob = { RESOURCE_IN_MEMORY, (unsigned long)CLM_IMAGE_SIZE, {.mem = { (const char *) wifi_firmware_clm_blob_data }}};
#endif /* ifndef RESOURCE_READ_FROM_C_FILE */

#endif /* ifndef INCLUDED_CLM_RESOURCES_H_ */
