/*
 * Copyright 2025, Cypress Semiconductor Corporation (an Infineon company)
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
 */

/** @file
 * Defines WHD resource functions for BCM943340WCD1 platform
 */
#ifndef WHD_FREERTOS
#include "cy_utils.h"
#endif  /* WHD_FREERTOS */
#include "cmsis_compiler.h"
#include "resources.h"
#if !defined(NO_CLM_BLOB_FILE)
#include "clm_resources.h"
#endif /* NO_CLM_BLOB_FILE */
#ifndef RESOURCE_READ_FROM_C_FILE
#include "wifi_nvram_image.h"
#else
#include "wifi_nvram_image_data.h"
#endif /* #ifndef RESOURCE_READ_FROM_C_FILE */
#include "whd_resource_api.h"
#include "whd_debug.h"
#include "whd.h"
#include "whd_utils.h"

/******************************************************
*                      Macros
******************************************************/
#define BLOCK_BUFFER_SIZE                    (1024)

/******************************************************
*                    Constants
******************************************************/

#if defined(WHD_DYNAMIC_NVRAM)
#define NVRAM_SIZE             dynamic_nvram_size
#define NVRAM_IMAGE_VARIABLE   dynamic_nvram_image
#else
#ifndef RESOURCE_READ_FROM_C_FILE
#define NVRAM_SIZE             NVRAM_IMAGE_SIZE
#else
#define NVRAM_SIZE             sizeof(wifi_nvram_image)
#endif /* ifndef RESOURCE_READ_FROM_C_FILE */
#define NVRAM_IMAGE_VARIABLE   wifi_nvram_image
#endif /* defined(WHD_DYNAMIC_NVRAM) */

#ifndef RESOURCE_READ_FROM_C_FILE
#define CLM_SIZE CLM_IMAGE_SIZE
#endif /* ifndef RESOURCE_READ_FROM_C_FILE */

/******************************************************
*                   Enumerations
******************************************************/

/******************************************************
*                 Type Definitions
******************************************************/

/******************************************************
*                    Structures
******************************************************/

/******************************************************
*               Static Function Declarations
******************************************************/
whd_result_t host_platform_resource_size(whd_driver_t whd_drv, whd_resource_type_t resource, uint32_t *size_out);
whd_result_t host_get_resource_block(whd_driver_t whd_drv, whd_resource_type_t type,
                                 uint32_t blockno, const uint8_t **data, uint32_t *size_out);
whd_result_t host_get_resource_no_of_blocks(whd_driver_t whd_drv, whd_resource_type_t type, uint32_t *block_count);
whd_result_t host_get_resource_block_size(whd_driver_t whd_drv, whd_resource_type_t type, uint32_t *size_out);
resource_result_t resource_read(const resource_hnd_t *resource, uint32_t offset, uint32_t maxsize, uint32_t *size,
                                void *buffer);
whd_result_t host_resource_read(whd_driver_t whd_drv, whd_resource_type_t type,
                            uint32_t offset, uint32_t size, uint32_t *size_out, void *buffer);
/******************************************************
*               Variable Definitions
******************************************************/

#ifdef DOWNLOAD_RAM_BOOTLOADER
extern const resource_hnd_t wifi_bootloader_image;
#endif /* DOWNLOAD_RAM_BOOTLOADER */

#ifndef WHD_FREERTOS
CY_ALIGN(4) unsigned char r_buffer[BLOCK_BUFFER_SIZE];
#else
unsigned char r_buffer[BLOCK_BUFFER_SIZE];
#endif /* WHD_FREERTOS */

#if defined(WHD_DYNAMIC_NVRAM)
uint32_t dynamic_nvram_size = sizeof(wifi_nvram_image);
void *dynamic_nvram_image = &wifi_nvram_image;
#endif

/******************************************************
*               Function Definitions
******************************************************/

resource_result_t resource_read(const resource_hnd_t *resource, uint32_t offset, uint32_t maxsize, uint32_t *size,
                                void *buffer)
{
    if (offset > resource->size)
    {
        return RESOURCE_OFFSET_TOO_BIG;
    }

    *size = MIN(maxsize, resource->size - offset);

    if (resource->location == RESOURCE_IN_MEMORY)
    {
        whd_mem_memcpy(buffer, &resource->val.mem.data[offset], *size);
    }
#ifdef USES_RESOURCES_IN_EXTERNAL_STORAGE
    else if (resource->location == RESOURCE_IN_EXTERNAL_STORAGE)
    {
        return platform_read_external_resource(resource, offset, maxsize, size, buffer);
    }
#endif
#ifdef USES_RESOURCE_GENERIC_FILESYSTEM
    else
    {
        wiced_file_t file_handle;
        uint64_t size64;
        uint64_t maxsize64 =  maxsize;
        if (WICED_SUCCESS !=
            wiced_filesystem_file_open (&resource_fs_handle, &file_handle, resource->val.fs.filename,
                                        WICED_FILESYSTEM_OPEN_FOR_READ) )
        {
            return RESOURCE_FILE_OPEN_FAIL;
        }
        if (WICED_SUCCESS != wiced_filesystem_file_seek (&file_handle, (offset + resource->val.fs.offset), SEEK_SET) )
        {
            return RESOURCE_FILE_SEEK_FAIL;
        }
        if (WICED_SUCCESS != wiced_filesystem_file_read (&file_handle, buffer, maxsize64, &size64) )
        {
            wiced_filesystem_file_close (&file_handle);
            return RESOURCE_FILE_READ_FAIL;
        }
        *size = (uint32_t)size64;
        wiced_filesystem_file_close (&file_handle);
    }
#else
#ifdef USES_RESOURCE_FILESYSTEM
    else
    {
        wicedfs_file_t file_hnd;

        if (0 != wicedfs_fopen(&resource_fs_handle, &file_hnd, resource->val.fs.filename) )
        {
            return RESOURCE_FILE_OPEN_FAIL;
        }

        if (0 != wicedfs_fseek(&file_hnd, (long)(offset + resource->val.fs.offset), SEEK_SET) )
        {
            wicedfs_fclose(&file_hnd);
            return RESOURCE_FILE_SEEK_FAIL;
        }

        if (*size != wicedfs_fread(buffer, 1, *size, &file_hnd) )
        {
            wicedfs_fclose(&file_hnd);
            return RESOURCE_FILE_READ_FAIL;
        }

        wicedfs_fclose(&file_hnd);
    }
#endif /* ifdef USES_RESOURCE_FILESYSTEM */
#endif /* USES_RESOURCE_GENERIC_FILESYSTEM */
    return RESOURCE_SUCCESS;
}

whd_result_t host_platform_resource_size(whd_driver_t whd_drv, whd_resource_type_t resource, uint32_t *size_out)
{
    if (resource == WHD_RESOURCE_WLAN_FIRMWARE)
    {
#ifdef NO_WIFI_FIRMWARE
        whd_assert("Request firmware in a no wifi firmware application", 0 == 1);
        *size_out = 0;
#else
#ifdef WIFI_FIRMWARE_IN_MULTI_APP
        wiced_app_t wifi_app;

        *size_out = 0;
        if (wiced_waf_app_open(DCT_WIFI_FIRMWARE_INDEX, &wifi_app) != WICED_SUCCESS)
        {
            return ( whd_result_t )RESOURCE_UNSUPPORTED;
        }
        wiced_waf_app_get_size(&wifi_app, size_out);
#else
        *size_out = (uint32_t)resource_get_size(&wifi_firmware_image);
#endif /* WIFI_FIRMWARE_IN_MULTI_APP */
#endif /* NO_WIFI_FIRMWARE */

    }
#ifdef DOWNLOAD_RAM_BOOTLOADER
    else if (resource == WHD_RESOURCE_BL_IMAGE)
    {
        *size_out = (uint32_t)resource_get_size(&wifi_bootloader_image);
    }
#endif
    else if (resource == WHD_RESOURCE_WLAN_NVRAM)
    {
        *size_out = (uint32_t)NVRAM_SIZE;
    }
    else
    {
#if defined(NO_CLM_BLOB_FILE)
        *size_out = 0;
#else
#ifndef RESOURCE_READ_FROM_C_FILE
        *size_out = (uint32_t)CLM_SIZE;
#else
        *size_out = (uint32_t)resource_get_size(&wifi_firmware_clm_blob);
#endif /* ifndef RESOURCE_READ_FROM_C_FILE */
#endif /* NO_CLM_BLOB_FILE */
    }
    return WHD_SUCCESS;
}

whd_result_t host_get_resource_block(whd_driver_t whd_drv, whd_resource_type_t type,
                                 uint32_t blockno, const uint8_t **data, uint32_t *size_out)
{
    uint32_t resource_size;
    uint32_t block_size;
    uint32_t block_count;
    uint32_t read_pos;
    uint32_t result;

    host_platform_resource_size(whd_drv, type, &resource_size);
    host_get_resource_block_size(whd_drv, type, &block_size);
    host_get_resource_no_of_blocks(whd_drv, type, &block_count);
    whd_mem_memset(r_buffer, 0, block_size);
    read_pos = blockno * block_size;

    if (blockno >= block_count)
    {
        return WHD_BADARG;
    }

    if (type == WHD_RESOURCE_WLAN_FIRMWARE)
    {
        result = resource_read( (const resource_hnd_t *)&wifi_firmware_image, read_pos, block_size, size_out,
                                r_buffer );
        if (result != WHD_SUCCESS)
        {
            return result;
        }
        *data = (uint8_t *)&r_buffer;
        /*
         * In case of local buffer read use the following code
         *
         *  *size_out = MIN(BLOCK_BUFFER_SIZE, resource_size - transfer_progress);
         *  *data = (uint8_t *)wifi_firmware_image_data;
         *
         * For sending the entire buffer in single block set size out as following
         *  *size_out = (uint32_t)resource_get_size(&wifi_firmware_image);
         */
    }
#ifdef DOWNLOAD_RAM_BOOTLOADER
    else if (type == WHD_RESOURCE_BL_IMAGE)
    {

        result = resource_read( (const resource_hnd_t *)&wifi_bootloader_image, read_pos, block_size, size_out,
                                     r_buffer );

        if (result != WHD_SUCCESS)
        {
            return result;
        }
        *data = (uint8_t *)&r_buffer;

    }
#endif /* DOWNLOAD_RAM_BOOTLOADER */
    else if (type == WHD_RESOURCE_WLAN_NVRAM)
    {
#ifndef RESOURCE_READ_FROM_C_FILE
        uint32_t i;
        result = resource_read( (const resource_hnd_t *)&wifi_nvram_image, read_pos, block_size, size_out,
                                r_buffer );
        /* convert the newline to null-terminator */
        for (i = 0; i < block_size; i++)
        {
            if (r_buffer[i] == 0xa)
            {
                r_buffer[i] = 0x0;
            }
        }
        if (result != WHD_SUCCESS)
        {
            return result;
        }
        *data = (uint8_t *)&r_buffer;
#else
        if (NVRAM_SIZE - read_pos > block_size)
        {
            *size_out = block_size;
        }
        else
        {
            *size_out = NVRAM_SIZE - read_pos;
        }
        *data = ( (uint8_t *)NVRAM_IMAGE_VARIABLE ) + read_pos;
#endif /* ifndef RESOURCE_READ_FROM_C_FILE */
    }
    else
    {
#if defined(NO_CLM_BLOB_FILE)
        size_out = 0;
        return WHD_SUCCESS;
#else
        result = resource_read( (const resource_hnd_t *)&wifi_firmware_clm_blob, read_pos, block_size,
                                size_out,
                                r_buffer );
#endif /* NO_CLM_BLOB_FILE */
        if (result != WHD_SUCCESS)
        {
            return result;
        }
        *data = (uint8_t *)&r_buffer;
        /*
         * In case of local buffer read use the following code
         *
         *  *size_out = MIN(BLOCK_BUFFER_SIZE, resource_size - transfer_progress);
         *  *data = (uint8_t *)wifi_firmware_clm_blob_image_data;
         *
         * For sending the entire buffer in single block set size out as following
         *  *size_out = sizeof(wifi_firmware_clm_blob_image_data);
         */

    }

    return WHD_SUCCESS;
}

whd_result_t host_get_resource_block_size(whd_driver_t whd_drv, whd_resource_type_t type, uint32_t *size_out)
{
    *size_out = BLOCK_BUFFER_SIZE;
    return WHD_SUCCESS;
}

whd_result_t host_get_resource_no_of_blocks(whd_driver_t whd_drv, whd_resource_type_t type, uint32_t *block_count)
{
    uint32_t resource_size;
    uint32_t block_size;

    host_platform_resource_size(whd_drv, type, &resource_size);
    host_get_resource_block_size(whd_drv, type, &block_size);
    *block_count = resource_size / block_size;
    if (resource_size % block_size)
        *block_count += 1;

    return WHD_SUCCESS;
}

whd_result_t host_resource_read(whd_driver_t whd_drv, whd_resource_type_t type,
                            uint32_t offset, uint32_t size, uint32_t *size_out, void *buffer)
{
    uint32_t result;

    if (type == WHD_RESOURCE_WLAN_FIRMWARE)
    {
        result = resource_read( (const resource_hnd_t *)&wifi_firmware_image, offset, size,
                                size_out, buffer );
        if (result != WHD_SUCCESS)
            return result;

    }
#ifdef DOWNLOAD_RAM_BOOTLOADER
    else if (type == WHD_RESOURCE_BL_IMAGE)
    {

        result = resource_read( (const resource_hnd_t *)&wifi_bootloader_image, offset, size,
                                size_out, buffer );

        if (result != WHD_SUCCESS)
            return result;

    }
#endif /* DOWNLOAD_RAM_BOOTLOADER */
    else if (type == WHD_RESOURCE_WLAN_NVRAM)
    {
#ifndef RESOURCE_READ_FROM_C_FILE
        uint32_t i,len;
        uint8_t *nvrame_data = NULL;
        result = resource_read( (const resource_hnd_t *)&wifi_nvram_image, offset, size,
                                size_out, buffer );
        nvrame_data = (uint8_t *) buffer;
        len=*size_out;
        /* convert the newline to null-terminator */
        for (i = 0; i < len; i++)
        {
            if (nvrame_data[i] == 0xa)
            {
                nvrame_data[i] = 0x0;
            }
        }
        if (result != WHD_SUCCESS)
            return result;
#else
        if (size != sizeof(wifi_nvram_image) )
        {
            return WHD_BUFFER_SIZE_SET_ERROR;
        }
        whd_mem_memcpy( (uint8_t *)buffer, wifi_nvram_image, sizeof(wifi_nvram_image) );
        *size_out = sizeof(wifi_nvram_image);
#endif /* ifndef RESOURCE_READ_FROM_C_FILE */
     }
    return WHD_SUCCESS;
}

whd_resource_source_t resource_ops =
{
    .whd_resource_size = host_platform_resource_size,
    .whd_get_resource_block_size = host_get_resource_block_size,
    .whd_get_resource_no_of_blocks = host_get_resource_no_of_blocks,
    .whd_get_resource_block = host_get_resource_block,
    .whd_resource_read = host_resource_read
};
