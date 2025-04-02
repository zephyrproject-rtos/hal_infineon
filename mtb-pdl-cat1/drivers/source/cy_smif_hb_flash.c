/***************************************************************************//**
* \file cy_smif_hb_flash.c
* \version 2.130
*
* \brief
*  This file provides the source code for the Hyper Bus APIs of the SMIF driver.
*
* Note:
*
********************************************************************************
* \copyright
* Copyright 2021-2024 Cypress Semiconductor Corporation (an Infineon company) or
* an affiliate of Cypress Semiconductor Corporation.
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
#include "cy_device.h"

#if defined (CY_IP_MXSMIF) && (CY_IP_MXSMIF_VERSION>=2)
#ifdef __cplusplus
 extern "C" {
#endif /* __cplusplus */
#include "cy_smif_memslot.h"
#include <string.h>


/*****************************************************************************
Pattern that should be used to calibrate the delay of RWDS capturing
 *****************************************************************************/
 /* Length of the calibration data pattern (Cy_SMIF_HB_CalibrationDataPattern) for HyperBus in bytes */
#define CY_SMIF_HB_CALIBRATION_DATA_PATTERN_LENGTH    12U
static uint8_t Cy_SMIF_HB_CalibrationDataPattern[CY_SMIF_HB_CALIBRATION_DATA_PATTERN_LENGTH] = { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x10, 0x11 };
#define DEVICEREADY_CHECK_TIMEOUT 100U
static uint16_t writeBuf = 0x0000U;

/* private functions */
static void Cy_SMIF_HB_SetDummyCycles(volatile SMIF_DEVICE_Type *dev, cy_en_smif_hb_dev_type_t hbDevType, uint32_t dummyCycle);

static uint32_t Cy_SMIF_Reverse4ByteEndian(uint32_t in);


static cy_en_smif_status_t Cy_SMIF_HyperBus_MMIO_Read(SMIF_Type *base,
                                        cy_en_smif_slave_select_t slave,
                                        cy_en_hb_burst_type_t burstType,
                                        uint32_t readAddress,
                                        uint32_t sizeInHalfWord,
                                        uint16_t buf[],
                                        uint32_t dummyCycle,
                                        bool doubleLat,
                                        bool isblockingMode,
                                        cy_stc_smif_context_t *context);



/*******************************************************************************
* Function Name: Cy_SMIF_Reverse4ByteEndian
****************************************************************************//**
*
* This function reverses endianness of 32 bit input
*
* \param in
* input 32 bit data to be reversed its endianness
*
* \return 32 bit data which has been reversed its endianness
*
*******************************************************************************/
static uint32_t Cy_SMIF_Reverse4ByteEndian(uint32_t in)
{
    return ((in & 0xFF000000UL) >> 24UL) |
      ((in & 0x00FF0000UL) >> 8UL)  |
        ((in & 0x0000FF00UL) << 8UL)  |
          ((in & 0x000000FFUL) << 24UL);
}

/*******************************************************************************
* Function Name: Cy_SMIF_HyperBus_InitDevice
****************************************************************************//**
*
* This function sets up SMIF registers which is used in XIP mode for hyper bus
* memory.
*
* base: Holds the base address of the SMIF base registers.
*
* memCfg: Configuration to be applied to the SMIF device \ref cy_stc_smif_mem_config_t
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_HyperBus_InitDevice(SMIF_Type *base, const cy_stc_smif_mem_config_t *memCfg, cy_stc_smif_context_t *context)
{
    cy_stc_smif_hbmem_device_config_t *config = memCfg->hbdeviceCfg;
    SMIF_DEVICE_Type volatile * dev = Cy_SMIF_GetDeviceBySlot(base, memCfg->slaveSelect);

#if (CY_IP_MXSMIF_VERSION>=4)
    /* DDR_PIPELINE_POS_DAT should be SET for RX Capture mode xSPI */
    if (_FLD2VAL(SMIF_CORE_CTL2_RX_CAPTURE_MODE, (SMIF_CTL2(base))) == (uint32_t)CY_SMIF_SEL_XSPI_HYPERBUS_WITH_DQS)
    {
        SMIF_DEVICE_RX_CAPTURE_CONFIG(dev) |= _VAL2FLD(SMIF_CORE_DEVICE_RX_CAPTURE_CONFIG_DDR_PIPELINE_POS_DAT, 1U);
    }
#endif
    /* Check if SMIF XIP is enabled */
    if ((_FLD2VAL(SMIF_CTL_XIP_MODE, SMIF_CTL(base)) != 1U) && (0U != (context->flags & CY_SMIF_FLAG_MEMORY_MAPPED)))
    {

        /****************************/
        /*   Set XIP Read Sequence  */
        /****************************/

        SMIF_DEVICE_RD_CMD_CTL(dev) = (_VAL2FLD(SMIF_DEVICE_RD_CMD_CTL_CODE,    (uint32_t)config->xipReadCmd)  |
                                        _VAL2FLD(SMIF_DEVICE_RD_CMD_CTL_DDR_MODE,  CY_SMIF_DDR)  |
                                        _VAL2FLD(SMIF_DEVICE_RD_CMD_CTL_WIDTH, CY_SMIF_WIDTH_OCTAL) |
                                        _VAL2FLD(SMIF_DEVICE_RD_CMD_CTL_PRESENT2, CY_SMIF_PRESENT_1BYTE));

        SMIF_DEVICE_RD_ADDR_CTL(dev) = (_VAL2FLD(SMIF_DEVICE_RD_ADDR_CTL_WIDTH, CY_SMIF_WIDTH_OCTAL) |
                                        _VAL2FLD(SMIF_DEVICE_RD_ADDR_CTL_DDR_MODE, CY_SMIF_DDR));

        SMIF_DEVICE_RD_MODE_CTL(dev) = (_VAL2FLD(SMIF_DEVICE_RD_MODE_CTL_CODE,  0UL)       |
                                        _VAL2FLD(SMIF_DEVICE_RD_MODE_CTL_WIDTH, CY_SMIF_WIDTH_SINGLE) |
                                        _VAL2FLD(SMIF_DEVICE_RD_MODE_CTL_DDR_MODE, CY_SMIF_SDR) |
                                        _VAL2FLD(SMIF_DEVICE_RD_MODE_CTL_PRESENT2, CY_SMIF_NOT_PRESENT));

        SMIF_DEVICE_RD_DATA_CTL(dev) = (_VAL2FLD(SMIF_DEVICE_RD_DATA_CTL_WIDTH, CY_SMIF_WIDTH_OCTAL) |
                                        _VAL2FLD(SMIF_DEVICE_RD_DATA_CTL_DDR_MODE, CY_SMIF_DDR));



        /*****************************/
        /*   Set XIP Write Sequence  */
        /*****************************/
        SMIF_DEVICE_WR_CMD_CTL(dev) = ( _VAL2FLD(SMIF_DEVICE_WR_CMD_CTL_CODE,  config->xipWriteCmd) |
                                        _VAL2FLD(SMIF_DEVICE_WR_CMD_CTL_DDR_MODE, CY_SMIF_DDR) |
                                        _VAL2FLD(SMIF_DEVICE_WR_CMD_CTL_WIDTH, CY_SMIF_WIDTH_OCTAL) |
                                        _VAL2FLD(SMIF_DEVICE_WR_CMD_CTL_PRESENT2, CY_SMIF_PRESENT_1BYTE));

        SMIF_DEVICE_WR_ADDR_CTL(dev) = (_VAL2FLD(SMIF_DEVICE_WR_ADDR_CTL_WIDTH, CY_SMIF_WIDTH_OCTAL) |
                                        _VAL2FLD(SMIF_DEVICE_WR_ADDR_CTL_DDR_MODE, CY_SMIF_DDR));

        SMIF_DEVICE_WR_MODE_CTL(dev) = (_VAL2FLD(SMIF_DEVICE_WR_MODE_CTL_CODE,    0UL)      |
                                        _VAL2FLD(SMIF_DEVICE_WR_MODE_CTL_WIDTH, CY_SMIF_WIDTH_SINGLE) |
                                        _VAL2FLD(SMIF_DEVICE_WR_MODE_CTL_DDR_MODE, CY_SMIF_SDR) |
                                        _VAL2FLD(SMIF_DEVICE_WR_MODE_CTL_PRESENT2,CY_SMIF_NOT_PRESENT));

        SMIF_DEVICE_WR_DATA_CTL(dev) = (_VAL2FLD(SMIF_DEVICE_WR_DATA_CTL_WIDTH, CY_SMIF_WIDTH_OCTAL) |
                                        _VAL2FLD(SMIF_DEVICE_WR_DATA_CTL_DDR_MODE, CY_SMIF_DDR));

        SMIF_DEVICE_ADDR(dev) = (SMIF_DEVICE_ADDR_ADDR_Msk & memCfg->baseAddress);

        /* Convert the size in the mask */
        SMIF_DEVICE_MASK(dev)= SMIF_DEVICE_MASK_MASK_Msk & (~((uint32_t)(config->memSize)) + 1UL);

        SMIF_DEVICE_ADDR_CTL(dev) = (_VAL2FLD(SMIF_DEVICE_ADDR_CTL_SIZE3, CY_SMIF_XIP_ADDRESS_5_BYTE) |
                                    _VAL2FLD(SMIF_DEVICE_ADDR_CTL_DIV2, 0U));
    }

#if (CY_IP_MXSMIF_VERSION>=4)
    if (_FLD2VAL(SMIF_CORE_CTL2_RX_CAPTURE_MODE, (SMIF_CTL2(base))) == (uint32_t)CY_SMIF_SEL_XSPI_HYPERBUS_WITH_DQS)
    {
        Cy_SMIF_HB_SetDummyCycles(dev, config->hbDevType, config->dummyCycles - 1U);
    }
    else
    {
        Cy_SMIF_HB_SetDummyCycles(dev, config->hbDevType, config->dummyCycles);
    }
#else
    /* Note: All read/write sequence settings depending on the dummy cycles are moved to the following function   */
    /*       because it may be necessary to update them during runtime when the latency settings in the connected */
    /*       memories have been changed. Cy_SMIF_HB_SetDummyCycles can then be used for that purpose.             */
    Cy_SMIF_HB_SetDummyCycles(dev, config->hbDevType, config->dummyCycles -1U);
#endif
    context->dummyCycles = config->dummyCycles;

    context->preXIPDataRate = CY_SMIF_DDR;

    /* The device control register initialization */
    SMIF_DEVICE_CTL(dev) = _VAL2FLD(SMIF_DEVICE_CTL_WR_EN, 1U) |
                  _VAL2FLD(SMIF_DEVICE_CTL_CRYPTO_EN, 0U) |
                  _VAL2FLD(SMIF_DEVICE_CTL_DATA_SEL,  CY_SMIF_DATA_SEL0) |
                  _VAL2FLD(SMIF_DEVICE_CTL_MERGE_EN,  ((bool)(memCfg->flags & CY_SMIF_FLAG_MERGE_ENABLE))? 1U : 0U)  |
                  _VAL2FLD(SMIF_DEVICE_CTL_MERGE_TIMEOUT,  (uint32_t)memCfg->mergeTimeout) |
                  SMIF_DEVICE_CTL_ENABLED_Msk;

    return CY_SMIF_SUCCESS;
}

/*******************************************************************************
* Function Name: Cy_SMIF_HB_SetDummyCycles
****************************************************************************//**
*
* This function updates the dummy cycles in the XIP read/write sequences
* based on the specified latency code and device type.
* If called for and already initialized device during runtime (e.g. after
* updating the latency settings in the connected memory) ensure that SMIF is
* not busy and no access to XIP address space happens!
*
* dev
* Holds the base address of the SMIF Device registers.
*
* hbDevType
* Device type (HyperFlash or HyperRAM)
*
* dummyCycle
* The amount of dummy cycles to use
*
* return
*     - \ref CY_SMIF_SUCCESS
*
*******************************************************************************/
static void Cy_SMIF_HB_SetDummyCycles(volatile SMIF_DEVICE_Type *dev, cy_en_smif_hb_dev_type_t hbDevType, uint32_t dummyCycle)
{
    /**********************************************/
    /*   Set dummy cycles for XIP Read Sequence  */
    /**********************************************/

    /*** Set dummy ***/
    {
        /* For Hyperbus, (RD DUMMY_CTL SIZE5 + 2) = initial latency */
        SMIF_DEVICE_RD_DUMMY_CTL(dev) = (_VAL2FLD(SMIF_DEVICE_RD_DUMMY_CTL_SIZE5, (dummyCycle - 1UL)) |
                                         _VAL2FLD(SMIF_DEVICE_RD_DUMMY_CTL_PRESENT2, 1U));

    }

    /***  Set bound  ***/
    {
        SMIF_DEVICE_RD_BOUND_CTL(dev) = (_VAL2FLD(SMIF_DEVICE_RD_BOUND_CTL_SIZE5, dummyCycle) |
                                         _VAL2FLD(SMIF_DEVICE_RD_BOUND_CTL_SUB_PAGE_SIZE,SUB_PAGE_SIZE_16BYTE)  |
                                         _VAL2FLD(SMIF_DEVICE_RD_BOUND_CTL_SUB_PAGE_NR,SUB_PAGE_2_PER_PAGE) |
                                         _VAL2FLD(SMIF_DEVICE_RD_BOUND_CTL_SUBSEQ_BOUND_EN,0UL)  |
                                         _VAL2FLD(SMIF_DEVICE_RD_BOUND_CTL_PRESENT, 1UL));
    }

    /**********************************************/
    /*   Set dummy cycles for XIP Write Sequence  */
    /**********************************************/
    /*** Set dummy ***/
    {
        if(hbDevType == CY_SMIF_HB_FLASH)
        {
            SMIF_DEVICE_WR_DUMMY_CTL(dev) = (_VAL2FLD(SMIF_DEVICE_WR_DUMMY_CTL_SIZE5, 0UL) |
                                             _VAL2FLD(SMIF_DEVICE_WR_DUMMY_CTL_PRESENT2, CY_SMIF_NOT_PRESENT) |
                                             _VAL2FLD(SMIF_DEVICE_WR_DUMMY_CTL_RWDS_EN, 0UL));
        }
        else
        {
            // For Hyperbus, (RD DUMMY_CTL SIZE5 + 2) = initial latency
            SMIF_DEVICE_WR_DUMMY_CTL(dev) = (_VAL2FLD(SMIF_DEVICE_WR_DUMMY_CTL_SIZE5, (dummyCycle - 1U)) |
                                         _VAL2FLD(SMIF_DEVICE_WR_DUMMY_CTL_PRESENT2, 1U) |
                                         _VAL2FLD(SMIF_DEVICE_WR_DUMMY_CTL_RWDS_EN, 1UL));
        }
    }
    return;
}

/*******************************************************************************
* Function Name: Cy_SMIF_HyperBus_CalibrateDelay
****************************************************************************//**
*
* This function reads the calibration data pattern in the Hyper memory for every
* delay tap of the currently selected delay line and records whether it matches
* the reference pattern. After all taps have been scanned, it determines the
* center tap of the longest sequence of matches and applies this tap.
*
* \note Function assumes that any SMIF has the same number of delay taps
*
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_HyperBus_CalibrateDelay(SMIF_Type *base, cy_stc_smif_mem_config_t *memConfig, uint8_t dummyCycles, uint32_t calibrationDataOffsetAddress, cy_stc_smif_context_t *context)
{
    uint16_t                  tapNum;
    cy_en_smif_status_t       SMIF_Status    = CY_SMIF_SUCCESS;
    uint16_t dataRead[CY_SMIF_HB_CALIBRATION_DATA_PATTERN_LENGTH];
    uint16_t delayTapNum = SMIF_DELAY_TAPS_NR;
    CY_ASSERT(delayTapNum < 256U);  // Assume "delayTapNum" is less than 256
    static bool isMatch[256U]; // static variable to avoid consuming stack.

    //SMIF_DEVICE_Type volatile * device = Cy_SMIF_GetDeviceBySlot(base, slaveId);
    cy_en_smif_mode_t smifModeBackup = Cy_SMIF_GetMode(base);

    // Reading of calibration data pattern needs to happen in SMIF MMIO mode so that it can be ensured that
    // there will be burst access happening and there are no pauses in between reading of individual words of the pattern
    Cy_SMIF_SetMode(base, CY_SMIF_NORMAL);

    SMIF_Status = Cy_SMIF_HyperBus_EraseSector(base,memConfig,calibrationDataOffsetAddress,context);
    CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 11.3', 3, \
    'Checked manually. Intentional expression The object pointer of type non "uint8_t (*)[12]" is cast to type "uint16_t *".')
    if(SMIF_Status == CY_SMIF_SUCCESS)
    {
        SMIF_Status = Cy_SMIF_HyperBus_Write(base,
                                 memConfig,
                                 CY_SMIF_HB_COUTINUOUS_BURST,
                                 calibrationDataOffsetAddress, // address
                                 CY_SMIF_HB_CALIBRATION_DATA_PATTERN_LENGTH / 2U,            // size in half word
                                 (uint16_t*)&Cy_SMIF_HB_CalibrationDataPattern,
                                 CY_SMIF_HB_FLASH,
                                 dummyCycles,
                                 true,                              // Blocking mode
                                 context
                                 );
    }
    else
    {
        return SMIF_Status;
    }
    CY_MISRA_BLOCK_END('MISRA C-2012 Rule 11.3')
    for(tapNum = 0U; tapNum < (uint16_t)delayTapNum; tapNum++)
    {
        uint16_t timeout = DEVICEREADY_CHECK_TIMEOUT;
        while(Cy_SMIF_BusyCheck(base) && (timeout > 0UL))
        {
            timeout--;
            Cy_SysLib_Delay(100U);
            /* Wait for the device to be ready */
        }
        if(timeout == 0U)
        {
            return CY_SMIF_EXCEED_TIMEOUT;
        }
#if (CY_IP_MXSMIF_VERSION==2) || (CY_IP_MXSMIF_VERSION>=4)
        (void)Cy_SMIF_Set_DelayTapSel(base, (uint8_t)tapNum);
#endif
        (void)memset(dataRead, 0,CY_SMIF_HB_CALIBRATION_DATA_PATTERN_LENGTH * 2U);
        SMIF_Status = Cy_SMIF_HyperBus_Read(base,
                                             memConfig,
                                             CY_SMIF_HB_COUTINUOUS_BURST,
                                             calibrationDataOffsetAddress,                    // address
                                             CY_SMIF_HB_CALIBRATION_DATA_PATTERN_LENGTH / 2U,  // size in half word
                                             (uint16_t*)dataRead,
                                             dummyCycles,
                                             false,                                           // single initial latency
                                             true,                                            // blocking mode
                                             context
                                            );
        if(SMIF_Status == CY_SMIF_SUCCESS)
        {
            // Record whether the current tap read data matches the reference data
            isMatch[tapNum] = (memcmp((uint8_t*)&dataRead, Cy_SMIF_HB_CalibrationDataPattern, CY_SMIF_HB_CALIBRATION_DATA_PATTERN_LENGTH) == 0) ? true : false;
        }
    }

    uint16_t bestTapNum             = 0xffffu;
    uint16_t consecutiveMatchNum    = 0u;
    uint16_t maxConsecutiveMatchNum = 0u;

    // Determine the longest consecutive match
    for(tapNum = 0u; tapNum < delayTapNum; tapNum++)
    {
        if(isMatch[tapNum] == true)
        {
            consecutiveMatchNum += 1u;
        }
        else
        {
            if(maxConsecutiveMatchNum < consecutiveMatchNum)
            {
                // Sequence of matches ended and it is a new longest sequence -> update the best tap number and prepare vars for next run
                maxConsecutiveMatchNum = consecutiveMatchNum;
                bestTapNum             = tapNum - ((maxConsecutiveMatchNum + 1u) / 2u);
                consecutiveMatchNum    = 0u;
            }
        }
    }

    // Special case: All taps had a match -> use the center tap of the total taps number
    if(maxConsecutiveMatchNum < consecutiveMatchNum)
    {
        bestTapNum = (uint16_t)(delayTapNum - ((consecutiveMatchNum + 1u) / 2u));
    }
#if (CY_IP_MXSMIF_VERSION==2) || (CY_IP_MXSMIF_VERSION>=4)
    // If a match has been found, apply the best tap
    if(bestTapNum != 0xffffu)
    {
        (void)Cy_SMIF_Set_DelayTapSel(base,(uint8_t)bestTapNum);
    }
    else
    {
        // No match has been found
        SMIF_Status = CY_SMIF_GENERAL_ERROR;
    }
#endif /*(CY_IP_MXSMIF_VERSION==2) || (CY_IP_MXSMIF_VERSION>=4)*/
    Cy_SMIF_SetMode(base, smifModeBackup);
    (void)bestTapNum;
    return SMIF_Status;
}


/*******************************************************************************
* Function Cy_SMIF_HyperBus_Read
****************************************************************************//**
*
* This function reads data from hyper bus memory in MMIO mode.
*
* \param base
* Holds the base address of the SMIF block registers.
*
* \param memConfig
* SMIF memory configuration structure for memory mode of operation.
*
* \param burstType
* Specifies wrapped or continuous burst. \ref en_hb_bust_type_t
*
* \param readAddress
* Specifies address of external device to be read.
*
* \param sizeInHalfWord
* Specifies memory size to be read.
* Note hyper bus memory have 16bit data per each address.
*
* \param buf
* Pointer to buffer where read data to be stored
*
* \param dummyCycles
* Number of dummy cycles required before actual read data.
*
* \param doubleLat
* double initial latency or single initial latency
*
* \param isblockingMode
* Blocking mode or not. if this is true, process waits for the read finished in this
* function. unless, the process does not wait and exit function.
*
* \param context
* Passes a configuration structure that contains the transfer parameters of the
* SMIF block.
*
* \return \ref cy_en_smif_status_t
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_HyperBus_Read(SMIF_Type *base,
                                        const cy_stc_smif_mem_config_t *memConfig,
                                        cy_en_hb_burst_type_t burstType,
                                        uint32_t readAddress,
                                        uint32_t sizeInHalfWord,
                                        uint16_t buf[],
                                        uint32_t dummyCycles,
                                        bool doubleLat,
                                        bool isblockingMode,
                                        cy_stc_smif_context_t *context)
{
    cy_en_smif_status_t status;
    status = Cy_SMIF_HyperBus_MMIO_Read(base,
                                 memConfig->slaveSelect,
                                 burstType,
                                 readAddress,
                                 sizeInHalfWord,
                                 buf,
                                 dummyCycles,
                                 doubleLat,
                                 isblockingMode,
                                 context
                                 );
    return status;
}

/*******************************************************************************
* Function Cy_SMIF_HyperBus_Write
****************************************************************************//**
*
* This function writes data into hyper bus memory in MMIO mode.
*
* \param base
* Holds the base address of the SMIF block registers.
*
* \param memconfig
* * SMIF memory configuration structure for memory mode of operation.
*
* \param burstType
* Specifies wrapped or continuous burst. \ref en_hb_bust_type_t
*
* \param writeAddress
* Specifies address of external device to be write.
*
* \param sizeInHalfWord
* Specifies memory size to be read.
* Note hyper bus memory have 16bit data per each address.
*
* \param buf
* Pointer to buffer where read data to be stored
*
* \param hbDevType
* Specifies hyper bus type. FLASH or SRAM. \ref cy_en_smif_hb_dev_type_t
*
* \param dummyCycles
* Number of dummyCycles to be inserted before write operation.
*
* \param isblockingMode
* Blocking mode or not. if this is true, process waits for the read finished in this
* function. unless, the process does not wait and exit function.
*
* \param context
* Passes a configuration structure that contains the transfer parameters of the
* SMIF block.
*
* \return \ref cy_en_smif_status_t
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_HyperBus_Write(SMIF_Type *base,
                                        const cy_stc_smif_mem_config_t *memConfig,
                                        cy_en_hb_burst_type_t burstType,
                                        uint32_t writeAddress,
                                        uint32_t sizeInHalfWord,
                                        uint16_t buf[],
                                        cy_en_smif_hb_dev_type_t hbDevType,
                                        uint32_t dummyCycles,
                                        bool isblockingMode,
                                        cy_stc_smif_context_t *context)
{
    cy_en_smif_status_t status = CY_SMIF_GENERAL_ERROR;
    uint32_t i_WriteAddr = 0U;

    for(uint32_t i = 0U; i < sizeInHalfWord; i++)
    {
        if(hbDevType == CY_SMIF_HB_FLASH)
        {
           writeBuf = (uint16_t)CY_SMIF_NOR_UNLOCK_DATA1;
           status = Cy_SMIF_HyperBus_MMIO_Write(base,
                                memConfig->slaveSelect,
                                burstType,
                                (uint32_t)CY_SMIF_HB_FLASH_UNLOCK_ADDR1,
                                HB_REG_SIZE_IN_HALFWORD,
                                &writeBuf,
                                hbDevType,
                                dummyCycles,
                                isblockingMode,
                                context
                                );
        
           writeBuf = (uint16_t)CY_SMIF_NOR_UNLOCK_DATA2;
           status = Cy_SMIF_HyperBus_MMIO_Write(base,
                                memConfig->slaveSelect,
                                burstType,
                                (uint32_t)CY_SMIF_HB_FLASH_UNLOCK_ADDR2,
                                HB_REG_SIZE_IN_HALFWORD,
                                &writeBuf,
                                hbDevType,
                                dummyCycles,
                                isblockingMode,
                                context
                                );
        
           writeBuf = (uint16_t)CY_SMIF_NOR_UNLOCK_BYPASS_PROGRAM_CMD;
           status = Cy_SMIF_HyperBus_MMIO_Write(base,
                                memConfig->slaveSelect,
                                burstType,
                                (uint32_t)CY_SMIF_HB_FLASH_UNLOCK_ADDR1,
                                HB_REG_SIZE_IN_HALFWORD,
                                &writeBuf,
                                hbDevType,
                                dummyCycles,
                                isblockingMode,
                                context
                                );
           if (status != CY_SMIF_SUCCESS)
           {
               return status;
           }
        }
        status = Cy_SMIF_HyperBus_MMIO_Write(base,
                                memConfig->slaveSelect,
                                burstType,
                                i_WriteAddr + writeAddress,
                                1U,
                                (uint16_t*)&buf[i_WriteAddr],
                                hbDevType,
                                dummyCycles,
                                isblockingMode,
                                context
                                );
        
        if(hbDevType == CY_SMIF_HB_FLASH)
        {
            uint16_t readStatus = 0x0000U;
            uint16_t timeout = DEVICEREADY_CHECK_TIMEOUT;
            do
            {
                status = CY_SMIF_HyperBus_ReadStatus(base, memConfig, &readStatus,context  );
                timeout --;
                Cy_SysLib_Delay(100U);
            } while(((readStatus & (uint16_t)CY_SMIF_DEV_RDY_MASK) == 0U) && (timeout > 0U)); // wait for the device becoming ready
            if(timeout == 0U)
            {
                return CY_SMIF_EXCEED_TIMEOUT;
            }
        }
        i_WriteAddr++;
    }
    return status;
}

/*******************************************************************************
* Function Name: CY_SMIF_HyperBus_ReadStatus
****************************************************************************//**
*
* This function reads the flash status register bits.
*
* \param base
* Holds the base address of the SMIF block registers.
*
* \param memConfig
* SMIF memory configuration structure for memory mode of operation.
*
* \param regStatus
* output status register value.
*
*******************************************************************************/
cy_en_smif_status_t CY_SMIF_HyperBus_ReadStatus(SMIF_Type *base, const cy_stc_smif_mem_config_t *memConfig, uint16_t *regStatus, cy_stc_smif_context_t *context)
{
    cy_en_smif_status_t status;
    writeBuf   = (uint16_t)CY_SMIF_NOR_STATUS_REG_READ_CMD;
    uint16_t readstatus = 0x0000U;
    status = Cy_SMIF_HyperBus_MMIO_Write(base,
                         memConfig->slaveSelect,
                         CY_SMIF_HB_WRAPPED_BURST,
                         (uint32_t)CY_SMIF_HB_FLASH_UNLOCK_ADDR1,
                         HB_REG_SIZE_IN_HALFWORD,
                         &writeBuf,
                         CY_SMIF_HB_FLASH,
                         context->dummyCycles,
                         true,
                         context
                         );
    status = Cy_SMIF_HyperBus_MMIO_Read(base,
                         memConfig->slaveSelect,
                         CY_SMIF_HB_COUTINUOUS_BURST,
                         0x0000U,
                         HB_REG_SIZE_IN_HALFWORD,
                         &readstatus,
                         context->dummyCycles,
                         false,
                         true,
                         context
                         );
    *regStatus = readstatus;
    return status;
}

/*******************************************************************************
* Function Name: CY_SMIF_HyperBus_ClearStatus
****************************************************************************//**
*
* This function clears the flash status register bits.
*
* \param base
* Holds the base address of the SMIF block registers.
*
* \param memConfig
* SMIF memory configuration structure for memory mode of operation.
*
*******************************************************************************/
cy_en_smif_status_t CY_SMIF_HyperBus_ClearStatus(SMIF_Type *base, cy_stc_smif_mem_config_t *memConfig, cy_stc_smif_context_t *context)
{
    cy_en_smif_status_t status;
    writeBuf   = (uint16_t)CY_SMIF_NOR_STATUS_REG_CLEAR_CMD;

    status = Cy_SMIF_HyperBus_MMIO_Write(base,
                         memConfig->slaveSelect,
                         CY_SMIF_HB_WRAPPED_BURST,
                         (uint32_t)CY_SMIF_HB_FLASH_UNLOCK_ADDR1,
                         HB_REG_SIZE_IN_HALFWORD,
                         &writeBuf,
                         CY_SMIF_HB_FLASH,
                         context->dummyCycles,
                         true,
                         context
                         );
    return status;
}
/*******************************************************************************
* Function Name: Cy_SMIF_HyperBus_EraseSector
****************************************************************************//**
*
* This function Erases the data in the given sector.
*
* \param base
* Holds the base address of the SMIF block registers.
*
* \param memConfig
* SMIF memory configuration structure for memory mode of operation.
*
* \param offset
* offset of the sector to be erased.
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_HyperBus_EraseSector(SMIF_Type *base, const cy_stc_smif_mem_config_t *memConfig, uint32_t offset, cy_stc_smif_context_t *context)
{
    cy_en_smif_status_t status;

    writeBuf = (uint16_t)CY_SMIF_NOR_UNLOCK_DATA1;
    status = Cy_SMIF_HyperBus_MMIO_Write(base,
                         memConfig->slaveSelect,
                         CY_SMIF_HB_WRAPPED_BURST,
                         (uint32_t)CY_SMIF_HB_FLASH_UNLOCK_ADDR1,
                         HB_REG_SIZE_IN_HALFWORD,
                         &writeBuf,
                         CY_SMIF_HB_FLASH,
                         context->dummyCycles,
                         true,
                         context
                         );

    writeBuf = (uint16_t)CY_SMIF_NOR_UNLOCK_DATA2;
    status = Cy_SMIF_HyperBus_MMIO_Write(base,
                         memConfig->slaveSelect,
                         CY_SMIF_HB_WRAPPED_BURST,
                         (uint32_t)CY_SMIF_HB_FLASH_UNLOCK_ADDR2,
                         HB_REG_SIZE_IN_HALFWORD,
                         &writeBuf,
                         CY_SMIF_HB_FLASH,
                         context->dummyCycles,
                         true,
                         context
                         );

    writeBuf = (uint16_t)CY_SMIF_NOR_ERASE_SETUP_CMD;
    status = Cy_SMIF_HyperBus_MMIO_Write(base,
                         memConfig->slaveSelect,
                         CY_SMIF_HB_WRAPPED_BURST,
                         (uint32_t)CY_SMIF_HB_FLASH_UNLOCK_ADDR1,
                         HB_REG_SIZE_IN_HALFWORD,
                         &writeBuf,
                         CY_SMIF_HB_FLASH,
                         context->dummyCycles,
                         true,
                         context
                         );

    writeBuf = (uint16_t)CY_SMIF_NOR_UNLOCK_DATA1;
    status = Cy_SMIF_HyperBus_MMIO_Write(base,
                         memConfig->slaveSelect,
                         CY_SMIF_HB_WRAPPED_BURST,
                         (uint32_t)CY_SMIF_HB_FLASH_UNLOCK_ADDR1,
                         HB_REG_SIZE_IN_HALFWORD,
                         &writeBuf,
                         CY_SMIF_HB_FLASH,
                         context->dummyCycles,
                         true,
                         context
                         );

    writeBuf = (uint16_t)CY_SMIF_NOR_UNLOCK_DATA2;
    status = Cy_SMIF_HyperBus_MMIO_Write(base,
                         memConfig->slaveSelect,
                         CY_SMIF_HB_WRAPPED_BURST,
                         (uint32_t)CY_SMIF_HB_FLASH_UNLOCK_ADDR2,
                         HB_REG_SIZE_IN_HALFWORD,
                         &writeBuf,
                         CY_SMIF_HB_FLASH,
                         context->dummyCycles,
                         true,
                         context
                         );

    writeBuf = (uint16_t)CY_SMIF_NOR_SECTOR_ERASE_CMD;

    status = Cy_SMIF_HyperBus_MMIO_Write(base,
                         memConfig->slaveSelect,
                         CY_SMIF_HB_WRAPPED_BURST,
                         offset,
                         HB_REG_SIZE_IN_HALFWORD,
                         &writeBuf,
                         CY_SMIF_HB_FLASH,
                         context->dummyCycles,
                         true,
                         context
                         );

    uint16_t readStatus = 0x0000U;
    uint16_t timeout = DEVICEREADY_CHECK_TIMEOUT;
    do
    {
        status = CY_SMIF_HyperBus_ReadStatus(base, memConfig, &readStatus,context  );
        timeout --;
        Cy_SysLib_Delay(100U);
    } while(((readStatus & (uint16_t)CY_SMIF_DEV_RDY_MASK) == 0U) && (timeout > 0U)); // wait for the device becoming ready
    if(timeout == 0U)
    {
        status = CY_SMIF_EXCEED_TIMEOUT;
    }
    return status;
}

/*******************************************************************************
* Function Name: Cy_SMIF_HyperBus_EraseChip
****************************************************************************//**
*
* This function Erases the data in the entire flash memory.
*
* \param base
* Holds the base address of the SMIF block registers.
*
* \param memConfig
* SMIF memory configuration structure for memory mode of operation.
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_HyperBus_EraseChip(SMIF_Type *base, cy_stc_smif_mem_config_t *memConfig, cy_stc_smif_context_t *context)
{
    cy_en_smif_status_t status;
    uint16_t readStatus = 0x0000U;
    writeBuf = (uint16_t)CY_SMIF_NOR_UNLOCK_DATA1;
    status = Cy_SMIF_HyperBus_MMIO_Write(base,
                         memConfig->slaveSelect,
                         CY_SMIF_HB_WRAPPED_BURST,
                         (uint32_t)CY_SMIF_HB_FLASH_UNLOCK_ADDR1,
                         HB_REG_SIZE_IN_HALFWORD,
                         &writeBuf,
                         CY_SMIF_HB_FLASH,
                         context->dummyCycles,
                         true,
                         context
                         );

    writeBuf = (uint16_t)CY_SMIF_NOR_UNLOCK_DATA2;
    status = Cy_SMIF_HyperBus_MMIO_Write(base,
                         memConfig->slaveSelect,
                         CY_SMIF_HB_WRAPPED_BURST,
                         (uint32_t)CY_SMIF_HB_FLASH_UNLOCK_ADDR2,
                         HB_REG_SIZE_IN_HALFWORD,
                         &writeBuf,
                         CY_SMIF_HB_FLASH,
                         context->dummyCycles,
                         true,
                         context
                         );

    writeBuf = (uint16_t)CY_SMIF_NOR_ERASE_SETUP_CMD;
    status = Cy_SMIF_HyperBus_MMIO_Write(base,
                         memConfig->slaveSelect,
                         CY_SMIF_HB_WRAPPED_BURST,
                         (uint32_t)CY_SMIF_HB_FLASH_UNLOCK_ADDR1,
                         HB_REG_SIZE_IN_HALFWORD,
                         &writeBuf,
                         CY_SMIF_HB_FLASH,
                         context->dummyCycles,
                         true,
                         context
                         );

    writeBuf = (uint16_t)CY_SMIF_NOR_UNLOCK_DATA1;
    status = Cy_SMIF_HyperBus_MMIO_Write(base,
                         memConfig->slaveSelect,
                         CY_SMIF_HB_WRAPPED_BURST,
                         (uint32_t)CY_SMIF_HB_FLASH_UNLOCK_ADDR1,
                         HB_REG_SIZE_IN_HALFWORD,
                         &writeBuf,
                         CY_SMIF_HB_FLASH,
                         context->dummyCycles,
                         true,
                         context
                         );

    writeBuf = (uint16_t)CY_SMIF_NOR_UNLOCK_DATA2;
    status = Cy_SMIF_HyperBus_MMIO_Write(base,
                         memConfig->slaveSelect,
                         CY_SMIF_HB_WRAPPED_BURST,
                         (uint32_t)CY_SMIF_HB_FLASH_UNLOCK_ADDR2,
                         HB_REG_SIZE_IN_HALFWORD,
                         &writeBuf,
                         CY_SMIF_HB_FLASH,
                         context->dummyCycles,
                         true,
                         context
                         );

    writeBuf = (uint16_t)CY_SMIF_NOR_CHIP_ERASE_CMD;

    status = Cy_SMIF_HyperBus_MMIO_Write(base,
                         memConfig->slaveSelect,
                         CY_SMIF_HB_WRAPPED_BURST,
                         (uint32_t)CY_SMIF_HB_FLASH_UNLOCK_ADDR1,
                         HB_REG_SIZE_IN_HALFWORD,
                         &writeBuf,
                         CY_SMIF_HB_FLASH,
                         context->dummyCycles,
                         true,                    // Blocking mode
                         context
                         );

    uint16_t timeout = DEVICEREADY_CHECK_TIMEOUT;
    do
    {
        status = CY_SMIF_HyperBus_ReadStatus(base, memConfig, &readStatus,context  );
        timeout --;
        Cy_SysLib_Delay(100U);
    } while(((readStatus & (uint16_t)CY_SMIF_DEV_RDY_MASK) == 0U) && (timeout > 0U)); // wait for the device becoming ready
    if(timeout == 0U)
    {
        status = CY_SMIF_EXCEED_TIMEOUT;
    }
    return status;
}
/* END of MMIO functions */



/*******************************************************************************
* Function Cy_SMIF_HyperBus_MMIO_Read
****************************************************************************//**
*
* This function reads data from hyper bus memory in MMIO mode.
*
* \param base
* Holds the base address of the SMIF block registers.
*
* \param slave
* Specifies slave of external device to be read. \ref cy_en_smif_slave_select_t
*
* \param burstType
* Specifies wrapped or continuous burst. \ref en_hb_bust_type_t
*
* \param readAddress
* Specifies address of external device to be read.
*
* \param sizeInHalfWord
* Specifies memory size to be read.
* Note hyper bus memory have 16bit data per each address.
*
* \param buf
* Pointer to buffer where read data to be stored
*
* \param lcCode
* Latency code. This value should be set also to the hyper bus device.
*
* \param dobleLat
* double initial latency or single initial latency
*
* \param isblockingMode
* Blocking mode or not. if this is true, process waits for the read finished in this
* function. unless, the process does not wait and exit function.
*
* \param context
* Passes a configuration structure that contains the transfer parameters of the
* SMIF block.
*
* \return \ref cy_en_smif_status_t
*
*******************************************************************************/
static cy_en_smif_status_t Cy_SMIF_HyperBus_MMIO_Read(SMIF_Type *base,
                                        cy_en_smif_slave_select_t slave,
                                        cy_en_hb_burst_type_t burstType,
                                        uint32_t readAddress,
                                        uint32_t sizeInHalfWord,
                                        uint16_t buf[],
                                        uint32_t dummyCycle,
                                        bool doubleLat,
                                        bool isblockingMode,
                                        cy_stc_smif_context_t *context)
{
    cy_en_smif_status_t status;
    uint32_t pageAddr = ((uint32_t)(readAddress >> 3u) & 0x00FFFFFFU);
    uint16_t addr_first_2bytes = (uint16_t)(pageAddr);
    // This is the last 8 bits of the 24 bit address. this should go in as part of command
    uint8_t addr_last_byte = (uint8_t)((pageAddr >> 16u));

    uint32_t address = (uint32_t)( _VAL2FLD(SMIF_HYPERBUS_ADR_LOWER_COL_ADDRESS,    readAddress) |
                         _VAL2FLD(SMIF_HYPERBUS_ADR_BYTE_ENABLE,    0x0U) |
                         _VAL2FLD(SMIF_HYPERBUS_ADR_ROW_AND_UPPER_COL_ADDRESS, addr_first_2bytes));
    uint32_t revOfAddr = Cy_SMIF_Reverse4ByteEndian(address);

    uint16_t cmd = (uint16_t)( _VAL2FLD(SMIF_HYPERBUS_CMD_ADDRESS_LAST_BYTE,    addr_last_byte) |
                               _VAL2FLD(SMIF_HYPERBUS_CMD_BURST_TYPE,    burstType) |
                               _VAL2FLD(SMIF_HYPERBUS_CMD_TARGET_TYPE, CY_SMIF_HB_TARGET_MEMORY) |
                               _VAL2FLD(SMIF_HYPERBUS_CMD_READ_WRITE,    CY_SMIF_HB_READ));
    /****** Command and Address ******/
    status = Cy_SMIF_TransmitCommand_Ext(base,
                                             cmd,
                                             true,
                                             CY_SMIF_WIDTH_OCTAL,
                                             CY_SMIF_DDR,
                                             (uint8_t*)&revOfAddr,
                                             4u,
                                             CY_SMIF_WIDTH_OCTAL,
                                             CY_SMIF_DDR,
                                             slave,
                                             CY_SMIF_TX_NOT_LAST_BYTE,
                                             context);
    if(status != CY_SMIF_SUCCESS)
    {
        return status;
    }

    dummyCycle = doubleLat      ?
                 dummyCycle * 2u :
                 dummyCycle;

    if(dummyCycle > 0u)
    {
        status = Cy_SMIF_SendDummyCycles_Ext(base, CY_SMIF_WIDTH_OCTAL, CY_SMIF_DDR, dummyCycle - 1U);

        if(status != CY_SMIF_SUCCESS)
        {
            return status;
        }
    }

    if(isblockingMode == true)
    {
        status = Cy_SMIF_ReceiveDataBlocking_Ext(base, (uint8_t *)buf, (sizeInHalfWord*2u), CY_SMIF_WIDTH_OCTAL, CY_SMIF_DDR, context);
    }
    else
    {
        status = Cy_SMIF_ReceiveData_Ext(base, (uint8_t *)buf, (sizeInHalfWord*2u), CY_SMIF_WIDTH_OCTAL, CY_SMIF_DDR, NULL, context);
    }

    return status;
}

/*******************************************************************************
* Function Cy_SMIF_HyperBus_MMIO_Write
****************************************************************************//**
*
* This function writes data into hyper bus memory in MMIO mode.
*
* \param base
* Holds the base address of the SMIF block registers.
*
* \param slave
* Specifies slave of external device to be read. \ref cy_en_smif_slave_select_t
*
* \param burstType
* Specifies wrapped or continuous burst. \ref en_hb_bust_type_t
*
* \param readAddress
* Specifies address of external device to be read.
*
* \param sizeInHalfWord
* Specifies memory size to be read.
* Note hyper bus memory have 16bit data per each address.
*
* \param buf
* Pointer to buffer where read data to be stored
*
* \param hbDevType
* Specifies hyper bus type. FLASH or SRAM. \ref cy_en_smif_hb_dev_type_t
*
* \param lcCode
* Latency code. This value should be set also to the hyper bus device.
*
* \param isblockingMode
* Blocking mode or not. if this is true, process waits for the read finished in this
* function. unless, the process does not wait and exit function.
*
* \param context
* Passes a configuration structure that contains the transfer parameters of the
* SMIF block.
*
* \return \ref cy_en_smif_status_t
*
*******************************************************************************/
cy_en_smif_status_t Cy_SMIF_HyperBus_MMIO_Write(SMIF_Type *base,
                                        cy_en_smif_slave_select_t slave,
                                        cy_en_hb_burst_type_t burstType,
                                        uint32_t writeAddress,
                                        uint32_t sizeInHalfWord,
                                        uint16_t buf[],
                                        cy_en_smif_hb_dev_type_t hbDevType,
                                        uint32_t dummyCycle,
                                        bool isblockingMode,
                                        cy_stc_smif_context_t *context)
{
    cy_en_smif_status_t status;
    (void)hbDevType;

    uint32_t pageAddr = ((uint32_t)(writeAddress >> 3u) & 0x00FFFFFFU);
    uint16_t addr_first_2bytes = (uint16_t)(pageAddr);
    // THis is the last 8 bits of the 24 bit address. this should go in as part of command
    uint8_t addr_last_byte = (uint8_t)((pageAddr >> 16u));

    uint32_t address = (uint32_t)( _VAL2FLD(SMIF_HYPERBUS_ADR_LOWER_COL_ADDRESS,    writeAddress) |
                         _VAL2FLD(SMIF_HYPERBUS_ADR_BYTE_ENABLE,    0x0U) |
                         _VAL2FLD(SMIF_HYPERBUS_ADR_ROW_AND_UPPER_COL_ADDRESS, addr_first_2bytes));
    uint32_t revOfAddr = Cy_SMIF_Reverse4ByteEndian(address);

    uint8_t param_addr[4];
    ValueToByteArray(revOfAddr, param_addr, 0u, 4U);
    uint16_t cmd = (uint16_t)( _VAL2FLD(SMIF_HYPERBUS_CMD_ADDRESS_LAST_BYTE,    addr_last_byte) |
                               _VAL2FLD(SMIF_HYPERBUS_CMD_BURST_TYPE,    burstType) |
                               _VAL2FLD(SMIF_HYPERBUS_CMD_TARGET_TYPE, CY_SMIF_HB_TARGET_MEMORY) |
                               _VAL2FLD(SMIF_HYPERBUS_CMD_READ_WRITE,    CY_SMIF_HB_WRITE));

    /****** Command and Address ******/
   status = Cy_SMIF_TransmitCommand_Ext(base,
                                        cmd,
                                        true,
                                        CY_SMIF_WIDTH_OCTAL,
                                        CY_SMIF_DDR,
                                        (uint8_t*)&revOfAddr,
                                        4u,
                                        CY_SMIF_WIDTH_OCTAL,
                                        CY_SMIF_DDR,
                                        slave,
                                        CY_SMIF_TX_NOT_LAST_BYTE,
                                        context);
    if(status != CY_SMIF_SUCCESS)
    {
        return status;
    }

    if(hbDevType == CY_SMIF_HB_SRAM)
    {
        if(dummyCycle > 0u)
        {
#if (CY_IP_MXSMIF_VERSION>=2)
            status = Cy_SMIF_SendDummyCycles_With_RWDS(base, false, false, dummyCycle - 1U);
#else
            status = Cy_SMIF_SendDummyCycles_Ext(base, CY_SMIF_WIDTH_OCTAL, CY_SMIF_DDR, dummyCycle - 1U);
#endif

            if(status != CY_SMIF_SUCCESS)
            {
                return status;
            }
        }
    }
    if(isblockingMode)
    {
        status = Cy_SMIF_TransmitDataBlocking_Ext(base, (uint8_t *)buf, (sizeInHalfWord*2u), CY_SMIF_WIDTH_OCTAL, CY_SMIF_DDR, context);
    }
    else
    {
        status = Cy_SMIF_TransmitData_Ext(base, (uint8_t const *)buf, (sizeInHalfWord*2u), CY_SMIF_WIDTH_OCTAL, CY_SMIF_DDR, NULL, context);
    }

    return status;
}

#if defined(__cplusplus)
}
#endif
#endif /* defined (CY_IP_MXSMIF) && (CY_IP_MXSMIF_VERSION>=2) && (CY_IP_MXSMIF_VERSION <= 5) */
