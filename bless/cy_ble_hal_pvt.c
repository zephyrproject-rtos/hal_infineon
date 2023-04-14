/***************************************************************************//**
* \file cy_ble_hal_pvt.c
* \version 3.60
*
* \brief
*  This file contains the source code for the HAL section of the PSoC 6 BLE Middleware.
*
********************************************************************************
* \copyright
* Copyright 2017-2021, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "cy_device.h"
#include "cy_syspm.h"
#include "cy_sysclk.h"
#include "cy_ble_hal_pvt.h"

#if defined(CY_IP_MXBLESS)


/*******************************************************************************
* Global Variables
*******************************************************************************/

/* BLE application IPC notification handler */
cy_ble_app_notify_callback_t Cy_BLE_HostRegisteredCallback = NULL;

/* Interrupt Notification Feature variables */
cy_ble_intr_callback_t Cy_BLE_InterruptCallback = NULL;
cy_stc_ble_intr_notify_t *intrNotifyPtr = NULL;

/* Nominal trim step size */
#if ((CY_SYSCLK_DRV_VERSION_MAJOR == 2) && (CY_SYSCLK_DRV_VERSION_MINOR <= 10)) || \
     (CY_SYSCLK_DRV_VERSION_MAJOR < 2)
static uint32 piloTrimStepSize = CY_BLE_PILO_TRIM_STEP;
#endif /* (CY_SYSCLK_DRV_VERSION_MAJOR == 2) && (CY_SYSCLK_DRV_VERSION_MINOR <= 10) */

/* Pointer to BLE configuration structure (uses in hal only) */
static cy_stc_ble_config_t *cy_ble_halConfigPtr = NULL;

/** BLE interrupt notification structure */
cy_stc_ble_intr_notify_t intrNotify =
{
   /* clientID       */  CY_BLE_CYPIPE_MSG_CMD_ID,
   /* pktType        */  CY_BLE_CYPIPE_INTR_NOTIFY_CMD,
   /* intrRelMask    */  0x00u,
   /* configFlag     */  false,
   /* mask           */  0x00u,
   /* data           */  0x00u,
   /* userIpcChan    */  0x00u,
   /* userIpcIntr    */  0x00u,
   /* userIntrPrior  */  0x00u
};


/*******************************************************************************
* Function Name: Cy_BLE_HAL_BlessStart
****************************************************************************//**
*
*  Starts Interrupt Controller.
*
*******************************************************************************/
void Cy_BLE_HAL_BlessStart(void)
{
    /* Initialize HAL */
    Cy_BLE_HAL_Init();

    /* Configures external power amplifier outputs. */
    Cy_BLE_ConfigureExtPA(BLE_BLESS_EXT_PA_LNA_CTRL_ENABLE_EXT_PA_LNA_Msk);

    /* Enable BLESS ISR */
    NVIC_EnableIRQ((IRQn_Type)cy_ble_halConfigPtr->hw->blessIsrConfig->intrSrc);
}


/*******************************************************************************
* Function Name: Cy_BLE_HAL_GetIpBlockVersion
****************************************************************************//**
*
* This function returns the version of m0s8bless ip block.
*
* \return
*   uint32_t bits:
*     7:0 - ip version ( 1 - BLE_ver1, 2 - BLE_ver2, 3 - BLE_ver3, 4 - BLE_ver3 (*A) )
*     31:8 - reserved for future usage
*
*******************************************************************************/
uint32_t Cy_BLE_HAL_GetIpBlockVersion(void)
{
    return(CY_BLE_M0S8BLESS_VERSION);
}


/*******************************************************************************
* Function Name: Cy_BLE_HAL_CalcCRC8
****************************************************************************//**
*
* Implements CRC-8 calculation
*
* \param data
* The data to be used to calculate the CRC.
*
* \param length
* The length of data.
*
* \return
* The calculated CRC value.
*
*******************************************************************************/
uint8_t Cy_BLE_HAL_CalcCRC8(uint8_t data[], uint32_t length)
{
    return (Cy_BLE_HAL_BlockCalcCRC8(data, length, 0u));
}


/*******************************************************************************
* Function Name: Cy_BLE_HAL_BlockCalcCRC8
****************************************************************************//**
*
* Implements CRC-8 calculation
*
* \param data
* The data to be used to calculate the CRC.
*
* \param length
* The length of data.
*
* \param crcSeed
* Init value of CRC. Use in case if we need calculate large buffer size by block
*
* \return
* The calculated CRC value.
*
*******************************************************************************/
uint8_t Cy_BLE_HAL_BlockCalcCRC8(uint8_t data[], uint32_t length, uint8_t crcSeed)
{
    const uint8_t Crc8Table[256] = {
    0x00u, 0x31u, 0x62u, 0x53u, 0xC4u, 0xF5u, 0xA6u, 0x97u,
    0xB9u, 0x88u, 0xDBu, 0xEAu, 0x7Du, 0x4Cu, 0x1Fu, 0x2Eu,
    0x43u, 0x72u, 0x21u, 0x10u, 0x87u, 0xB6u, 0xE5u, 0xD4u,
    0xFAu, 0xCBu, 0x98u, 0xA9u, 0x3Eu, 0x0Fu, 0x5Cu, 0x6Du,
    0x86u, 0xB7u, 0xE4u, 0xD5u, 0x42u, 0x73u, 0x20u, 0x11u,
    0x3Fu, 0x0Eu, 0x5Du, 0x6Cu, 0xFBu, 0xCAu, 0x99u, 0xA8u,
    0xC5u, 0xF4u, 0xA7u, 0x96u, 0x01u, 0x30u, 0x63u, 0x52u,
    0x7Cu, 0x4Du, 0x1Eu, 0x2Fu, 0xB8u, 0x89u, 0xDAu, 0xEBu,
    0x3Du, 0x0Cu, 0x5Fu, 0x6Eu, 0xF9u, 0xC8u, 0x9Bu, 0xAAu,
    0x84u, 0xB5u, 0xE6u, 0xD7u, 0x40u, 0x71u, 0x22u, 0x13u,
    0x7Eu, 0x4Fu, 0x1Cu, 0x2Du, 0xBAu, 0x8Bu, 0xD8u, 0xE9u,
    0xC7u, 0xF6u, 0xA5u, 0x94u, 0x03u, 0x32u, 0x61u, 0x50u,
    0xBBu, 0x8Au, 0xD9u, 0xE8u, 0x7Fu, 0x4Eu, 0x1Du, 0x2Cu,
    0x02u, 0x33u, 0x60u, 0x51u, 0xC6u, 0xF7u, 0xA4u, 0x95u,
    0xF8u, 0xC9u, 0x9Au, 0xABu, 0x3Cu, 0x0Du, 0x5Eu, 0x6Fu,
    0x41u, 0x70u, 0x23u, 0x12u, 0x85u, 0xB4u, 0xE7u, 0xD6u,
    0x7Au, 0x4Bu, 0x18u, 0x29u, 0xBEu, 0x8Fu, 0xDCu, 0xEDu,
    0xC3u, 0xF2u, 0xA1u, 0x90u, 0x07u, 0x36u, 0x65u, 0x54u,
    0x39u, 0x08u, 0x5Bu, 0x6Au, 0xFDu, 0xCCu, 0x9Fu, 0xAEu,
    0x80u, 0xB1u, 0xE2u, 0xD3u, 0x44u, 0x75u, 0x26u, 0x17u,
    0xFCu, 0xCDu, 0x9Eu, 0xAFu, 0x38u, 0x09u, 0x5Au, 0x6Bu,
    0x45u, 0x74u, 0x27u, 0x16u, 0x81u, 0xB0u, 0xE3u, 0xD2u,
    0xBFu, 0x8Eu, 0xDDu, 0xECu, 0x7Bu, 0x4Au, 0x19u, 0x28u,
    0x06u, 0x37u, 0x64u, 0x55u, 0xC2u, 0xF3u, 0xA0u, 0x91u,
    0x47u, 0x76u, 0x25u, 0x14u, 0x83u, 0xB2u, 0xE1u, 0xD0u,
    0xFEu, 0xCFu, 0x9Cu, 0xADu, 0x3Au, 0x0Bu, 0x58u, 0x69u,
    0x04u, 0x35u, 0x66u, 0x57u, 0xC0u, 0xF1u, 0xA2u, 0x93u,
    0xBDu, 0x8Cu, 0xDFu, 0xEEu, 0x79u, 0x48u, 0x1Bu, 0x2Au,
    0xC1u, 0xF0u, 0xA3u, 0x92u, 0x05u, 0x34u, 0x67u, 0x56u,
    0x78u, 0x49u, 0x1Au, 0x2Bu, 0xBCu, 0x8Du, 0xDEu, 0xEFu,
    0x82u, 0xB3u, 0xE0u, 0xD1u, 0x46u, 0x77u, 0x24u, 0x15u,
    0x3Bu, 0x0Au, 0x59u, 0x68u, 0xFFu, 0xCEu, 0x9Du, 0xACu };

    uint8_t crc = crcSeed;

    while (length > 0u)
    {
        crc = Crc8Table[crc ^ *data];
        data++;
        length--;
    }

    return(crc);
}


/*******************************************************************************
* Function Name: Cy_BLE_HAL_GetIcPackageType
****************************************************************************//**
*
*  This function returns package type
*
*  return:
*   0 - BGA_116 package
*   1 - CSP_104 package
*   2 - BGA_124 package
*   3 - QFN_68 package
*
*******************************************************************************/
uint32_t Cy_BLE_HAL_GetIcPackageType(void)
{
    /* Constants used in this function */
    const uint8_t PACKAGE_68_PINS  = 68u;
    const uint8_t PACKAGE_116_PINS = 116u;
    const uint8_t PACKAGE_104_PINS = 104u;
    const uint8_t PACKAGE_124_PINS = 124u;

    /* Get package type */
    uint8_t pType = (uint8_t)
            (cy_ble_halConfigPtr->stackParam->packageType & CY_BLE_PACKAGE_TYPE_MASK);

    /* Get package pins number */
    uint8_t pinCount = (uint8_t)
            (cy_ble_halConfigPtr->stackParam->packageType >> CY_BLE_PACKAGE_PIN_NUM_OFFSET);

    cy_en_ble_ic_package_type_t ret;

    if( ((pType == CY_BLE_PACKAGE_BGA) && (pinCount == 0u)) ||
        ((pType == CY_BLE_PACKAGE_BGA) && (pinCount == PACKAGE_116_PINS)) )
    {
        ret = CY_BLE_IC_PACKAGE_TYPE_BGA_116;
    }
    else if( ((pType == CY_BLE_PACKAGE_CSP) && (pinCount == 0u)) ||
             ((pType == CY_BLE_PACKAGE_CSP) && (pinCount == PACKAGE_104_PINS)) )
    {
        ret = CY_BLE_IC_PACKAGE_TYPE_CSP_104;
    }
    else if((pType == CY_BLE_PACKAGE_BGA) && (pinCount == PACKAGE_124_PINS))
    {
        ret = CY_BLE_IC_PACKAGE_TYPE_BGA_124;
    }
    else if((pType == CY_BLE_PACKAGE_QFN) && (pinCount == PACKAGE_68_PINS))
    {
        ret = CY_BLE_IC_PACKAGE_TYPE_QFN_68;
    }
    else
    {
        ret = CY_BLE_IC_PACKAGE_TYPE_BGA_116;
    }

    return((uint32_t)ret);
}


/*******************************************************************************
* Function Name: Cy_BLE_HAL_GetUniqueId
****************************************************************************//**
* Interface to Cy_SysLib_GetUniqueId function.
*
* This function returns the silicon unique ID.
* The ID includes Die lot[3]#, Die Wafer#, Die X, Die Y, Die Sort#, Die Minor
* and Die Year.
*
* \return  A combined 64-bit unique ID.
*          [63:57] - DIE_YEAR
*          [56:56] - DIE_MINOR
*          [55:48] - DIE_SORT
*          [47:40] - DIE_Y
*          [39:32] - DIE_X
*          [31:24] - DIE_WAFER
*          [23:16] - DIE_LOT[2]
*          [15: 8] - DIE_LOT[1]
*          [ 7: 0] - DIE_LOT[0]
*
*******************************************************************************/
uint64_t Cy_BLE_HAL_GetUniqueId(void)
{
    return(Cy_SysLib_GetUniqueId());
}


/*******************************************************************************
* Function Name: Cy_BLE_HAL_GetSiliconId
****************************************************************************//**
*
* This function returns the Silicon ID of the device.
*
* \return  Silicon ID
*
*******************************************************************************/
uint16_t Cy_BLE_HAL_GetSiliconId(void)
{
    return(SFLASH_SILICON_ID);
}


/*******************************************************************************
* Function Name: Cy_BLE_HAL_IsDefinedTx5dbm
****************************************************************************//**
*
*  This function returns true if Tx 5dbm mode is defined
*
* return:
*  true  - Tx 5dbm mode is defined
*  false - Tx 5dbm mode is not defined
*
*******************************************************************************/
bool Cy_BLE_HAL_IsDefinedTx5dbm(void)
{
    bool ret = false;

    if((cy_ble_halConfigPtr != NULL) &&
       (cy_ble_halConfigPtr->stackParam->tx5dbmModeEn))
    {
        ret = true;
    }
    return(ret);
}


/*******************************************************************************
* Function Name: Cy_BLE_HAL_SoftHciHostWritePkt
****************************************************************************//**
*
* This function writes received package from host to controller queue for
* processing.
*
* \param hciPktParams
*  Pointer to the received package from host.
*
*  \return
*   CY_BLE_SUCCESS - A successful operation,
*   CY_BLE_ERROR_INSUFFICIENT_RESOURCES - BLE Controller queue is full.
*
*******************************************************************************/
cy_en_ble_api_result_t Cy_BLE_HAL_SoftHciHostWritePkt(cy_stc_ble_hci_tx_packet_info_t *hciPktParams)
{
    return Cy_BLE_HAL_MappingSoftHciControllerReceiveHostPkt(hciPktParams);
}


/*******************************************************************************
***
****   BLE Stack Interface to flash
***
*******************************************************************************/

/*******************************************************************************
* Function Name: Cy_BLE_HAL_NvramWrite
****************************************************************************//**
*
* This function writes the data to the NVRAM store. It will check the
* appropriate alignment of a start address and also perform an address range
* check based on the length before performing the write operation.
* This function performs memory compare and writes only row where there are new
* data to write.
*
* \param buffer:   Pointer to the buffer containing the data to be stored.
* \param varFlash: Pointer to the array or variable in the flash.
* \param length:   The length of the data in bytes.
* \param mode:     Flash operation mode:
*                     CY_BLE_FLASH_NON_BLOCKING_MODE - operate with non
*                     blocking flash API
*                     CY_BLE_FLASH_BLOCKING_MODE - operate with blocking
*                     flash API
*
* \return
*  CY_BLE_SUCCESS                         | A successful write
*  CY_BLE_ERROR_INVALID_PARAMETER         | At least one of the input parameters is invalid
*  CY_BLE_ERROR_FLASH_WRITE               | Error in flash write
*  CY_BLE_ERROR_FLASH_WRITE_NOT_PERMITED  | Flash operation is not permitted (see Note)
*
* \note: flash operation is not permitted with protection context (PC)
*        value > 0 and core voltage 0.9V, because of a preproduction
*        hardware limitation.
*
*******************************************************************************/
cy_en_ble_api_result_t Cy_BLE_HAL_NvramWrite(const uint8_t buffer[],
                                             const uint8_t varFlash[],
                                             uint32_t length,
                                             uint32_t mode)
{
    cy_en_ble_api_result_t bleReturn;
    cy_en_flashdrv_status_t flashReturn = CY_FLASH_DRV_SUCCESS;
    cy_en_syspm_status_t syspmReturn = CY_SYSPM_SUCCESS;
    uint32_t writeBuffer[CY_FLASH_SIZEOF_ROW / sizeof(uint32_t)];
    uint32_t rowId;
    uint32_t dstIndex;
    uint32_t srcIndex = 0u;
    uint32_t eeOffset;
    uint32_t byteOffset;
    bool rowsNotEqual;
    uint8_t *writeBufferPointer;

    eeOffset = (uint32_t)varFlash;
    writeBufferPointer = (uint8_t*)writeBuffer;

    /* Make sure, that varFlash[] points to application flash or auxiliary flash (AUXflash) Emulated EEPROM flash */
    if( (eeOffset >= CY_FLASH_BASE) ||
        ((eeOffset >= CY_EM_EEPROM_BASE) &&
         ((eeOffset + length) <= (CY_EM_EEPROM_BASE + CY_EM_EEPROM_SIZE))) ||
        ((eeOffset >= (uint32_t)SFLASH_BLE_DEVICE_ADDRESS) &&
         ((eeOffset + length) <= ((uint32_t)SFLASH_BLE_DEVICE_ADDRESS + CY_FLASH_SIZEOF_ROW))) )
    {
        cy_en_syspm_simo_buck_voltage1_t simoVoltage = CY_SYSPM_SIMO_BUCK_OUT1_VOLTAGE_1_1V;
        cy_en_syspm_ldo_voltage_t ldoVoltage = CY_SYSPM_LDO_VOLTAGE_1_1V;
        bool writeFlag = false;

        /* Increase core voltage for write to flash operation */
        if(Cy_SysPm_SimoBuckIsEnabled())
        {
            simoVoltage = Cy_SysPm_SimoBuckGetVoltage1();
            if(simoVoltage == CY_SYSPM_SIMO_BUCK_OUT1_VOLTAGE_0_9V)
            {   /* Increase core voltage (SIMO) for write to flash operation */
                do /* Polls whether syspm is not busy */
                {
                    syspmReturn = Cy_SysPm_BuckSetVoltage1(CY_SYSPM_SIMO_BUCK_OUT1_VOLTAGE_1_1V);
                } while(syspmReturn == CY_SYSPM_CANCELED);
            }
        }
        else
        {
            ldoVoltage = Cy_SysPm_LdoGetVoltage();
            if(ldoVoltage == CY_SYSPM_LDO_VOLTAGE_0_9V)
            {   /* Increase core voltage (LDO) for write to flash operation */
                do /* Polls whether syspm is not busy */
                {
                    syspmReturn = Cy_SysPm_LdoSetVoltage(CY_SYSPM_LDO_VOLTAGE_1_1V);
                } while(syspmReturn == CY_SYSPM_CANCELED);
            }
        }

        /*
         * Increase core voltage to 1.1V for Flash operation is not permitted
         * with protection context (PC) value > 0, because of a preproduction
         * hardware limitation.
         */
        CY_ASSERT(syspmReturn != CY_SYSPM_INVALID_STATE);

        eeOffset -= CY_FLASH_BASE;
        rowId = eeOffset / CY_FLASH_SIZEOF_ROW;
        byteOffset = CY_FLASH_SIZEOF_ROW * rowId;

        /* Inform Controller core about write operation */
        while (CY_IPC_SEMA_SUCCESS != Cy_IPC_Sema_Set(CY_BLE_SEMA, false))
        {
            /* Polls whether sema is not set */
        }

        while((syspmReturn == CY_SYSPM_SUCCESS) &&
              (flashReturn == CY_FLASH_DRV_SUCCESS) && (srcIndex < length))
        {
            rowsNotEqual = false;
            /* Copy data to the write buffer either from the source buffer or from the flash */
            for(dstIndex = 0u; dstIndex < CY_FLASH_SIZEOF_ROW; dstIndex++)
            {
                if((byteOffset >= eeOffset) && (srcIndex < length))
                {
                    uint8_t bufferValue;

                    bufferValue = (buffer == NULL) ? 0u : buffer[srcIndex];

                    writeBufferPointer[dstIndex] = bufferValue;
                    /* Detect that row programming is required */
                    if((rowsNotEqual == false) && (CY_GET_REG8(CY_FLASH_BASE + byteOffset) != bufferValue))
                    {
                        rowsNotEqual = true;
                    }
                    srcIndex++;
                }
                else
                {
                    writeBufferPointer[dstIndex] = CY_GET_REG8(CY_FLASH_BASE + byteOffset);
                }
                byteOffset++;
            }

            if((rowsNotEqual) && (syspmReturn == CY_SYSPM_SUCCESS))
            {
                uint32_t oprTimeout = CY_BLE_FLASH_OPR_TIMEOUT; /* us */
                if(mode == CY_BLE_FLASH_NON_BLOCKING_MODE) /* NON-BLOCKING FLASH OPERATION */
                {
                    /* Perform Erase flash row operation */
                    oprTimeout = CY_BLE_FLASH_OPR_TIMEOUT; /* us */
                    do
                    {
                        flashReturn = Cy_Flash_StartErase((rowId * CY_FLASH_SIZEOF_ROW) + CY_FLASH_BASE);

                        /* Timeout if flash operation return error */
                        oprTimeout--;
                        Cy_SysLib_DelayUs(1u);

                    }while(((flashReturn & CY_FLASH_ID_ERROR) == CY_FLASH_ID_ERROR) && (oprTimeout != 0u));

                    /* Waiting completion of the Erase flash row operation */
                    if(flashReturn == CY_FLASH_DRV_OPERATION_STARTED)
                    {
                        /* Polls whether the Flash operation is performed */
                        do
                        {
                            flashReturn = Cy_Flash_IsEraseComplete();
                        }
                        while (flashReturn == CY_FLASH_DRV_OPCODE_BUSY);
                    }

                    /* Perform Program flash row operation */
                    if(flashReturn == CY_FLASH_DRV_SUCCESS)
                    {
                        oprTimeout = CY_BLE_FLASH_OPR_TIMEOUT; /* us */

                        /* Program flash row */
                        do
                        {
                            flashReturn = Cy_Flash_StartProgram((rowId * CY_FLASH_SIZEOF_ROW) + CY_FLASH_BASE,
                                                                 writeBuffer);

                            /* Timeout if flash operation return error */
                            oprTimeout--;
                            Cy_SysLib_DelayUs(1u);

                        }while(((flashReturn & CY_FLASH_ID_ERROR) == CY_FLASH_ID_ERROR) && (oprTimeout != 0u));
                    }

                    /* Waiting completion of the Program flash row operation */
                    if(flashReturn == CY_FLASH_DRV_OPERATION_STARTED)
                    {
                        /* Polls whether the Flash operation is performed */
                        do
                        {
                            flashReturn = Cy_Flash_IsOperationComplete();
                        }
                        while (flashReturn == CY_FLASH_DRV_OPCODE_BUSY);
                    }
                }
                else /* BLOCKING FLASH OPERATION */
                {
                    /* Perform Write flash row operation (in blocking mode) */
                    flashReturn = Cy_Flash_WriteRow((rowId * CY_FLASH_SIZEOF_ROW) + CY_FLASH_BASE,
                                                     writeBuffer);
                }
                writeFlag = true;
            }

            /* Go to the next row */
            rowId++;
        }

        /* Clear Flash Cache and Buffer after write operation */
        if(writeFlag == true)
        {
            Cy_SysLib_ClearFlashCacheAndBuffer();
        }

        /* Inform BLE syspm callback about complete of write operation */
        while (CY_IPC_SEMA_SUCCESS != Cy_IPC_Sema_Clear(CY_BLE_SEMA, false))
        {
            /* Polls whether sema is not clear */
        }

        /* Return core voltage */
        if(syspmReturn == CY_SYSPM_SUCCESS)
        {
            /* Return core voltage (SIMO) */
            if((Cy_SysPm_SimoBuckIsEnabled()) && (simoVoltage == CY_SYSPM_SIMO_BUCK_OUT1_VOLTAGE_0_9V))
            {
                do /* Polls whether syspm is not busy */
                {
                    syspmReturn = Cy_SysPm_BuckSetVoltage1(CY_SYSPM_SIMO_BUCK_OUT1_VOLTAGE_0_9V);
                } while(syspmReturn == CY_SYSPM_CANCELED);
            }

            /* Return core voltage (LDO) */
            if((Cy_SysPm_LdoIsEnabled()) && (ldoVoltage == CY_SYSPM_LDO_VOLTAGE_0_9V))
            {
                do /* Polls whether syspm is not busy */
                {
                    syspmReturn = Cy_SysPm_LdoSetVoltage(CY_SYSPM_LDO_VOLTAGE_0_9V);
                } while(syspmReturn == CY_SYSPM_CANCELED);
            }
        }
    }
    else
    {
        flashReturn = CY_FLASH_DRV_INVALID_INPUT_PARAMETERS;
    }

    /* Return BLE error code */
    if(syspmReturn != CY_SYSPM_SUCCESS)
    {
        bleReturn = CY_BLE_ERROR_FLASH_WRITE_NOT_PERMITED;
    }
    else
    {
        switch(flashReturn)
        {
            case CY_FLASH_DRV_SUCCESS:
                bleReturn = CY_BLE_SUCCESS;
                break;

            case CY_FLASH_DRV_INVALID_INPUT_PARAMETERS:
            case CY_FLASH_DRV_INVALID_FLASH_ADDR:
                bleReturn = CY_BLE_ERROR_INVALID_PARAMETER;
                break;

            default:
                bleReturn = CY_BLE_ERROR_FLASH_WRITE;
                break;
        }
    }
    return(bleReturn);
}


/*******************************************************************************
* Function Name: Cy_BLE_HAL_StackNvramWrite
****************************************************************************//**
*
*  This function is used by stack to perform flash write
*
*  This function is designated for internal usage.
*
* \param buffer:   Pointer to the buffer containing the data to be stored.
* \param varFlash: Pointer to the array or variable in the flash.
* \param length:   The length of the data in bytes.
*
* \return
*  CY_BLE_SUCCESS                       A successful write
*  CY_BLE_INFO_FLASH_WRITE_IN_PROGRESS  Row writing in progress
*  CY_BLE_ERROR_INVALID_PARAMETER       At least one of the input parameters is invalid
*  CY_BLE_ERROR_FLASH_WRITE             Error in flash Write
*
*******************************************************************************/
cy_en_ble_api_result_t Cy_BLE_HAL_StackNvramWrite(const uint8_t buffer[],
                                                  const uint8_t varFlash[],
                                                  uint32_t length)
{
    return(Cy_BLE_HAL_NvramWrite(buffer, varFlash, length, CY_BLE_FLASH_NON_BLOCKING_MODE));
}


/*******************************************************************************
***
****   BLE Stack Interface to clock
***
*******************************************************************************/

/*******************************************************************************
* Function Name: Cy_BLE_HAL_IsEcoCpuClockSrc
****************************************************************************//**
*
*  Return 1 if ECO from BLESS in CLK_PATH_SELECT register is selected.
*
*  \return
*  uint8_t: 0 - ECO from BLESS is not used in DWR
*           1 - ECO from BLESS is selected in CLK_PATH_SELECT register
*
*******************************************************************************/
uint8_t Cy_BLE_HAL_IsEcoCpuClockSrc(void)
{
    uint8_t returnVal = 0U;
    uint32_t i;

    for(i = 0U; i < CY_SRSS_NUM_CLKPATH; i++)
    {
        if(Cy_SysClk_ClkPathGetSource(i) == CY_SYSCLK_CLKPATH_IN_ALTHF)
        {
            returnVal = 1U;
            break;
        }
    }

    return(returnVal);
}


/*******************************************************************************
* Function Name: Cy_BLE_HAL_EcoGetFrequency
****************************************************************************//**
*
*  Return the frequency of the output of a BLE ECO clock.
*
*  \return The frequency, in Hz.
*
*******************************************************************************/
uint32_t Cy_BLE_HAL_EcoGetFrequency(void)
{
    return (cy_BleEcoClockFreqHz);
}


/*******************************************************************************
* Function Name: Cy_BLE_HAL_IsWcoLfclkSrc
****************************************************************************//**
*
*  Check whether WCO or PILO are the source for the low frequency clock (clkLf)
*
*  \return
*  uint8_t: 0 - WCO or PILO are not source for the low frequency clock
*           1 - WCO or PILO are source for the low frequency clock
*
*******************************************************************************/
uint8_t Cy_BLE_HAL_IsWcoLfclkSrc(void)
{
    cy_en_clklf_in_sources_t lfclkSrs = Cy_SysClk_ClkLfGetSource();
    return(((lfclkSrs == CY_SYSCLK_CLKLF_IN_WCO) ||
            (lfclkSrs == CY_SYSCLK_CLKLF_IN_PILO)) ? 1U : 0U);
}


/*******************************************************************************
* Function Name: Cy_BLE_HAL_LfClkGetSource
****************************************************************************//**
*
*  Interface to Cy_SysClk_LfClkGetSource function.
*
*******************************************************************************/
cy_en_clklf_in_sources_t Cy_BLE_HAL_LfClkGetSource(void)
{
    return(Cy_SysClk_ClkLfGetSource());
}


/*******************************************************************************
* Function Name: Cy_BLE_HAL_ClkMeasurementCountersDone
****************************************************************************//**
*
*  Interface to Cy_SysClk_ClkMeasurementCountersDone function.
*
*******************************************************************************/
int32_t Cy_BLE_HAL_ClkMeasurementCountersDone(void)
{
    return((int32_t)Cy_SysClk_ClkMeasurementCountersDone());
}


/*******************************************************************************
* Function Name: Cy_BLE_HAL_ClkMeasurementCountersGetFreq
****************************************************************************//**
*
*  Interface to Cy_SysClk_ClkMeasurementCountersGetFreq function.
*
*******************************************************************************/
uint32_t Cy_BLE_HAL_ClkMeasurementCountersGetFreq(bool measuredClock,
                                                  uint32_t refClkFreq)
{
    return(Cy_SysClk_ClkMeasurementCountersGetFreq(measuredClock, refClkFreq));
}


/*******************************************************************************
* Function Name: Cy_BLE_HAL_StartClkMeasurementCounters
****************************************************************************//**
*
*  Interface to Cy_SysClk_StartClkMeasurementCounters function.
*
*******************************************************************************/
uint32_t Cy_BLE_HAL_StartClkMeasurementCounters(cy_en_meas_clks_t clock1,
                                                uint32_t count1,
                                                cy_en_meas_clks_t clock2)
{
    cy_en_sysclk_status_t retVal = CY_SYSCLK_INVALID_STATE;
    if(Cy_IPC_Sema_Status(CY_BLE_SEMA) != CY_IPC_SEMA_STATUS_LOCKED)
    {
        retVal = Cy_SysClk_StartClkMeasurementCounters(clock1, count1, clock2);
    }
    return((uint32_t) retVal);
}

#if ((CY_SYSCLK_DRV_VERSION_MAJOR == 2) && (CY_SYSCLK_DRV_VERSION_MINOR <= 10)) || \
     (CY_SYSCLK_DRV_VERSION_MAJOR < 2)

/*******************************************************************************
* Function Name: Cy_BLE_HAL_SetPiloTrimStep
****************************************************************************//**
*
* Set PILO trim step which will be used within BLE stack during periodical PILO
* calibration.
*
* \param stepSize: nominal trim step size.
*
*******************************************************************************/
void Cy_BLE_HAL_SetPiloTrimStep(uint32_t stepSize)
{
    piloTrimStepSize = stepSize;
}


/*******************************************************************************
* Function Name: Cy_BLE_HAL_TryPiloTrim
****************************************************************************//**
*
* Trims the PILO to be as close to 32,768 Hz as possible.
*
* \param piloFreq:   current PILO frequency. Call Cy_SysClk_StartClkMeasurementCounters
*                    and other measurement functions to obtain the current frequency of
*                    the PILO.
* \param targetFreq: target frequency.
* \param stepSize:   nominal trim step size.
*
* \return Change in trim value; 0 if done, that is, no change in trim value.
*
*******************************************************************************/
int32_t Cy_BLE_HAL_TryPiloTrim(uint32_t piloFreq, uint32_t targetFreq, uint32_t stepSize)
{
    uint32_t newTrim = 0ul;
    uint32_t curTrim = 0ul;

    /* Do nothing if piloFreq is already within one trim step from the target */
    uint32_t diff = (uint32_t)abs((int32_t)piloFreq - (int32_t)targetFreq);
    if (diff >= stepSize)
    {
        curTrim = Cy_SysClk_PiloGetTrim();
        if (piloFreq > targetFreq)
        { /* piloFreq too high. Decrease the trim value. */
            newTrim = curTrim - CY_SYSCLK_DIV_ROUND(piloFreq - targetFreq, stepSize);
            if ((int32_t)newTrim < 0) /* limit underflow */
            {
                newTrim = 0u;
            }
        }
        else
        { /* piloFreq too low. Increase the trim value. */
            newTrim = curTrim + CY_SYSCLK_DIV_ROUND(targetFreq - piloFreq, stepSize);
            if (newTrim >= SRSS_CLK_PILO_CONFIG_PILO_FFREQ_Msk) /* limit overflow */
            {
                newTrim = SRSS_CLK_PILO_CONFIG_PILO_FFREQ_Msk;
            }
        }
        Cy_SysClk_PiloSetTrim(newTrim);
    }

    return ((int32_t)curTrim -(int32_t) newTrim);
}
#endif /* (CY_SYSCLK_DRV_VERSION_MAJOR == 2) && (CY_SYSCLK_DRV_VERSION_MINOR <= 10) */


/*******************************************************************************
* Function Name: Cy_BLE_HAL_PiloTrim
****************************************************************************//**
*
*  Interface to Cy_BLE_HAL_TryPiloTrim function.
*
*******************************************************************************/
int32_t Cy_BLE_HAL_PiloTrim(uint32_t piloFreq)
{
#if ((CY_SYSCLK_DRV_VERSION_MAJOR == 2) && (CY_SYSCLK_DRV_VERSION_MINOR <= 10)) || \
     (CY_SYSCLK_DRV_VERSION_MAJOR < 2)
    return(Cy_BLE_HAL_TryPiloTrim(piloFreq, CY_BLE_PILO_TARGET_FREQ,
                                  piloTrimStepSize));
#else
    return(Cy_SysClk_PiloTrim(piloFreq));
#endif /* (CY_SYSCLK_DRV_VERSION_MAJOR == 2) && (CY_SYSCLK_DRV_VERSION_MINOR <= 10) */
}

/*******************************************************************************
* Function Name: Cy_BLE_HAL_EnableDefaultEco
****************************************************************************//**
*  This function enable BLESS ECO clock on defauld configuration.
* \return
*  CY_BLE_SUCCESS                 - A successful operation
*  CY_BLE_ERROR_HARDWARE_FAILURE  - Error during BLE ECO clock configuration
*  CY_BLE_ERROR_INVALID_OPERATION - Operation is not permitted
*
*******************************************************************************/
#if 0
cy_en_ble_api_result_t Cy_BLE_HAL_EnableDefaultEco(void)
{
    cy_en_ble_api_result_t apiResult = CY_BLE_ERROR_INVALID_OPERATION;
    cy_en_ble_eco_status_t ecoStatus;

    if (Cy_BLE_GetState() == CY_BLE_STATE_STOPPED)
    {
        ecoStatus = Cy_BLE_EcoConfigure( CY_BLE_DEFAULT_BLESS_ECO_FREQ,
                                         CY_BLE_DEFAULT_SYS_ECO_CLK_DIV,
                                         CY_BLE_DEFAULT_CAP_TRIM_VALUE,
                                         CY_BLE_DEFAULT_OSC_STARTUP_DELAY_LF,
                                         CY_BLE_DEFAULT_CY_BLE_ECO_VOLTAGE_REG );

        if ((ecoStatus != CY_BLE_ECO_SUCCESS) &&
            (ecoStatus != CY_BLE_ECO_ALREADY_STARTED))
        {
            /* CY_BLE_ERROR_HARDWARE_FAILURE */
            apiResult = CY_BLE_ERROR_HARDWARE_FAILURE;
        }
        else
        {
            apiResult = CY_BLE_SUCCESS;
        }
    }

    return(apiResult);
}
#endif

/*******************************************************************************
***
****   BLE Stack Interface to SysLib / SysPm
***
*******************************************************************************/

/*******************************************************************************
* Function Name: Cy_BLE_HAL_DelayUs
****************************************************************************//**
*
*  Interface to Cy_SysLib_DelayUs function.
*
*******************************************************************************/
void Cy_BLE_HAL_DelayUs(uint16_t delayVal)
{
    Cy_SysLib_DelayUs(delayVal);
}


/*******************************************************************************
* Function Name: Cy_BLE_HAL_DelayMs
****************************************************************************//**
*
*  Interface to Cy_SysLib_Delay function.
*
*******************************************************************************/
void Cy_BLE_HAL_DelayMs(uint32_t delayVal)
{
    Cy_SysLib_Delay(delayVal);
}


/*******************************************************************************
* Function Name: Cy_BLE_HAL_EnableBlessInterrupt
****************************************************************************//**
*
*  This function enables BLESS interrupt.
*
*******************************************************************************/
void Cy_BLE_HAL_EnableBlessInterrupt(void)
{
    if((cy_ble_halConfigPtr->hw != NULL) &&
       (cy_ble_halConfigPtr->hw->blessIsrConfig != NULL))
    {
        NVIC_EnableIRQ((IRQn_Type)cy_ble_halConfigPtr->hw->blessIsrConfig->intrSrc);
    }
}


/*******************************************************************************
* Function Name: Cy_BLE_HAL_DisableBlessInterrupt
****************************************************************************//**
*
*  This function disable BLESS interrupt.
*
*******************************************************************************/
void Cy_BLE_HAL_DisableBlessInterrupt(void)
{
    if((cy_ble_halConfigPtr->hw != NULL) &&
       (cy_ble_halConfigPtr->hw->blessIsrConfig != NULL))
    {
        NVIC_DisableIRQ((IRQn_Type)cy_ble_halConfigPtr->hw->blessIsrConfig->intrSrc);
    }
}


/*******************************************************************************
* Function Name: Cy_BLE_HAL_EnterCriticalSection
****************************************************************************//**
*
*  Interface to Cy_SysLib_EnterCriticalSection function.
*
*******************************************************************************/
uint32_t Cy_BLE_HAL_EnterCriticalSection(void)
{
    return(Cy_SysLib_EnterCriticalSection());
}


/*******************************************************************************
* Function Name: Cy_BLE_HAL_ExitCriticalSection
****************************************************************************//**
*
*  Interface to Cy_SysLib_ExitCriticalSection function.
*
*******************************************************************************/
void Cy_BLE_HAL_ExitCriticalSection(uint32_t interruptState)
{
    Cy_SysLib_ExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: Cy_BLE_HAL_SysPmSleep
****************************************************************************//**
*
*  Interface to Cy_SysPm_Sleep function.
*
*******************************************************************************/
cy_en_syspm_status_t Cy_BLE_HAL_SysPmSleep(cy_en_syspm_waitfor_t enWaitFor)
{
    return(Cy_SysPm_CpuEnterSleep(enWaitFor));
}


/*******************************************************************************
* Function Name: Cy_BLE_HAL_SimoBuckSetVoltage2
****************************************************************************//**
*
*  Interface to Cy_SysPm_SimoBuckSetVoltage2 function with disable the 200 uS
*  delay after setting a higher voltage.
*
*******************************************************************************/
void Cy_BLE_HAL_SimoBuckSetVoltage2(cy_en_syspm_simo_buck_voltage2_t voltage)
{
    Cy_SysPm_SimoBuckSetVoltage2(voltage, false);
}



/*******************************************************************************
***
****   Interrupt Notify Feature functions
***
*******************************************************************************/

/*******************************************************************************
* Function Name: Cy_BLE_HAL_IntrNotifyIpcHandler
****************************************************************************//**
*
*  Handles the IPC notification for Interrupt Notification Feature.
*
*******************************************************************************/
void Cy_BLE_HAL_IntrNotifyIpcHandler(void)
{
    uint32_t interruptMasked;
    IPC_INTR_STRUCT_Type *intrTypePtr = Cy_IPC_Drv_GetIntrBaseAddr((uint32_t)intrNotify.userIpcIntr);

   /**
    * Check that there is really the IPC Notify interrupt,
    * because the same line can be used for the IPC Release interrupt.
    */

    interruptMasked = Cy_IPC_Drv_ExtractAcquireMask(Cy_IPC_Drv_GetInterruptStatusMasked(intrTypePtr));

    if ((1uL << ((uint32_t)intrNotify.userIpcChan)) == interruptMasked )
    {
        Cy_IPC_Drv_ClearInterrupt(intrTypePtr, CY_IPC_NO_NOTIFICATION, interruptMasked);

        if(Cy_BLE_InterruptCallback != NULL)
        {
            /* Call the BLE interrupt feature handler */
            Cy_BLE_InterruptCallback(intrNotify.data);
        }

        /* Release the IPC channel with the Release interrupt */
        (void)Cy_IPC_Drv_LockRelease(Cy_IPC_Drv_GetIpcBaseAddress((uint32_t)intrNotify.userIpcChan),
                                    (1uL << (uint32_t)intrNotify.userIpcIntr));
    }
}


/*******************************************************************************
* Function Name: Cy_BLE_IPC_CommonCallBack
****************************************************************************//**
*
*  This a callback to be called when a message is received on a pipe from
*  host side. This callback uses for:
*   - Configure BLE Interrupt Notification Feature (pktType: 0xFF)
*   - Initialize and enable BLE controller (pktType: 0x01)
*

*  \param msgPtr : Pointer to the callback message.
*
*******************************************************************************/
static void Cy_BLE_IPC_CommonCallBack(uint32_t * msgPtr);
static void Cy_BLE_IPC_CommonCallBack(uint32_t * msgPtr)
{
    cy_stc_ble_ipc_msg_t * ipcMsgPtr = (cy_stc_ble_ipc_msg_t *) msgPtr;

    if((ipcMsgPtr != NULL) && (cy_ble_halConfigPtr != NULL))
    {
        switch (ipcMsgPtr->pktType)
        {
            /* Enable BLE controller (use only in BLE dual CPU mode) */
            case CY_BLE_CYPIPE_ENABLE_CONTR_CMD:
                /* Store Stack param structure in Controller configuration structure */
                cy_ble_halConfigPtr->stackParam = (cy_stc_ble_stack_params_t *)ipcMsgPtr->data;

                /* Update System Core Clock values for correct Cy_SysLib_Delay
                 * functioning. Expected that System Core Clock is finally initialized
                 * on CM4 core */
                SystemCoreClockUpdate();

                /* Enable BLE controller. Return value Cy_BLE_EnableController store
                 * back in data field */
                ipcMsgPtr->data = (uint32_t) Cy_BLE_EnableController();

                /* Signals host side that operation completed */
                ipcMsgPtr->controllerStarted = true;
                break;

            /* Configure BLE Interrupt Notification Feature */
            case CY_BLE_CYPIPE_INTR_NOTIFY_CMD:
                /* Set up Interrupt Notification Feature mask  */
                intrNotifyPtr = (cy_stc_ble_intr_notify_t *)msgPtr;
                intrNotifyPtr->configFlag = true;
                break;

            default:
                break;
        }
    }
}


/*******************************************************************************
* Function Name: Cy_BLE_HAL_RegisterCommonPipeCallback
****************************************************************************//**
*
*  This function registers IPC pipe callback for PSoC 6 BLE Middleware (for internall
*  usage).
*
*  The PSoC 6 BLE Middleware uses this callback for:
*   - Configure BLE Interrupt Notification Feature,
*   - Initialize and enable BLE controller, when PSoC 6 BLE Middleware operates in
*     BLE dual CPU mode.
*
*  \return
*   CY_BLE_SUCCESS                    A successful operation
*   CY_BLE_ERROR_INVALID_OPERATION    Error during registering PIPE callback
*
*******************************************************************************/
cy_en_ble_api_result_t Cy_BLE_HAL_RegisterCommonPipeCallback(void)
{
    cy_en_ble_api_result_t rc = CY_BLE_SUCCESS;

    if(Cy_IPC_Pipe_RegisterCallback(CY_BLE_IPC_CONTROLLER_ADDR,
            &Cy_BLE_IPC_CommonCallBack, CY_BLE_CYPIPE_MSG_CMD_ID) == CY_IPC_PIPE_SUCCESS)
    {
        rc = CY_BLE_ERROR_INVALID_OPERATION;
    }

    return(rc);
}


/*******************************************************************************
***
****   HAL API for Radio Calibration feature
***
*******************************************************************************/

/*******************************************************************************
* Function Name: Cy_BLE_HAL_RadioCalibrationWrite
****************************************************************************//**
*
*  Write radio calibration data to SFLASH
*
*  \param data:   Pointer to the buffer containing the data to be stored.
*  \param length: The length of the data in bytes.
*
*  \return
*   CY_BLE_SUCCESS                     A successful write
*   CY_BLE_ERROR_INVALID_PARAMETER     At least one of the input parameters is invalid
*   CY_BLE_ERROR_FLASH_WRITE           Error in flash Write
*
*******************************************************************************/
cy_en_ble_api_result_t Cy_BLE_HAL_RadioCalibrationWrite(const void *data, uint32_t length)
{
    cy_en_ble_api_result_t rc;

    if((data != NULL) &&
       (length <= (CY_FLASH_SIZEOF_ROW - sizeof(cy_stc_ble_bd_addr_t))))
    {
        rc = Cy_BLE_HAL_NvramWrite(data, (uint8_t *)CY_BLE_SFLASH_BLE_RADIO_CALL_ADDRESS,
                                   length, CY_BLE_FLASH_BLOCKING_MODE);
    }
    else
    {
        rc = CY_BLE_ERROR_INVALID_PARAMETER;
    }
    return(rc);
}


/*******************************************************************************
* Function Name: Cy_BLE_HAL_RadioCalibrationRead
****************************************************************************//**
*
*  Read radio calibration data from SFLASH
*
*  \param data:   Pointer to the buffer containing the data to be read from SFASH.
*  \param length: The length of the data in bytes.
*
*  \return
*   CY_BLE_SUCCESS                     A successful read
*   CY_BLE_ERROR_INVALID_PARAMETER     At least one of the input parameters is invalid
*
*******************************************************************************/
cy_en_ble_api_result_t Cy_BLE_HAL_RadioCalibrationRead(void *data, uint32_t length)
{
    cy_en_ble_api_result_t rc = CY_BLE_SUCCESS;

    if((data != NULL) &&
       (length <= (CY_FLASH_SIZEOF_ROW - sizeof(cy_stc_ble_bd_addr_t))))
    {
        (void) memcpy(data, (void *)CY_BLE_SFLASH_BLE_RADIO_CALL_ADDRESS, length);
    }
    else
    {
        rc = CY_BLE_ERROR_INVALID_PARAMETER;
    }
    return(rc);
}


/*******************************************************************************
***
****   BLE Stack Interface to IPC
***
*******************************************************************************/

/* PSoC 6 BLE Middleware IPC Controller handler */
static cy_ipc_pipe_callback_ptr_t Cy_BLE_IPC_CtrlMsgFlushRecvStackHandle;
static void Cy_BLE_IPC_CtrlMsgFlushRecvCallBack(uint32_t * msgPtr);

/* BLE Stack IPC Host handler */
static cy_ipc_pipe_callback_ptr_t Cy_BLE_IPC_HostMsgRecvStackHandle;
static cy_ipc_pipe_callback_ptr_t Cy_BLE_IPC_HostMsgFlushRecvStackHandle;

/* PSoC 6 BLE Middleware IPC Host handler */
static void Cy_BLE_IPC_HostMsgFlushRecvCallBack(uint32_t * msgPtr);
static void Cy_BLE_IPC_HostMsgRecvCallBack(uint32_t * msgPtr);


/*******************************************************************************
* Function Name: Cy_BLE_HAL_EnableControllerIpcPipeInterrupt
****************************************************************************//**
*
*   Enables the IPC pipe interrupt on controller side.
*
*******************************************************************************/
void Cy_BLE_HAL_EnableControllerIpcPipeInterrupt(void)
{
    (void)Cy_IPC_Pipe_EndpointResume(CY_BLE_IPC_CONTROLLER_ADDR);
}


/*******************************************************************************
* Function Name: Cy_BLE_HAL_SetConfigStructure
****************************************************************************//**
*
*   Store BLE configuration structure in a internal HAL pointer.
*
*******************************************************************************/
__WEAK void Cy_BLE_HAL_SetConfigStructure(const cy_stc_ble_config_t *configPtr)
{
    cy_ble_halConfigPtr = (cy_stc_ble_config_t *) configPtr;
}


/*******************************************************************************
* Function Name: Cy_BLE_HAL_DisableControllerIpcPipeInterrupt
****************************************************************************//**
*
*   Disable the IPC pipe interrupt on controller side.
*
*******************************************************************************/
void Cy_BLE_HAL_DisableControllerIpcPipeInterrupt(void)
{
    (void)Cy_IPC_Pipe_EndpointPause(CY_BLE_IPC_CONTROLLER_ADDR);
}


/*******************************************************************************
* Function Name: Cy_BLE_HAL_EnableHostIpcPipeInterrupt
****************************************************************************//**
*
*   Enables the IPC pipe interrupt on host side.
*
*******************************************************************************/
void Cy_BLE_HAL_EnableHostIpcPipeInterrupt(void)
{
    (void)Cy_IPC_Pipe_EndpointResume(CY_BLE_IPC_HOST_ADDR);
}


/*******************************************************************************
* Function Name: Cy_BLE_HAL_DisableHostIpcPipeInterrupt
****************************************************************************//**
*
*   Disable the IPC pipe interrupt on host side.
*
*******************************************************************************/
void Cy_BLE_HAL_DisableHostIpcPipeInterrupt(void)
{
    (void)Cy_IPC_Pipe_EndpointPause(CY_BLE_IPC_HOST_ADDR);
}


/*******************************************************************************
* Function Name: Cy_BLE_IPC_CtrlMsgFlushRecvCallBack
****************************************************************************//**
*
* This a callback to be called when a message is received on a pipe.
*
* \param msgPtr
* Pointer to the callback message.
*
*******************************************************************************/
static void Cy_BLE_IPC_CtrlMsgFlushRecvCallBack(uint32_t * msgPtr)
{
    /* Call BLE Stack IPC handler */
    Cy_BLE_IPC_CtrlMsgFlushRecvStackHandle(msgPtr);
}


/*******************************************************************************
* Function Name: Cy_BLE_IPC_ControllerRegisterClientCallbacks
****************************************************************************//**
*
* This function registers a callbacks to be called when a message is received on a pipe.
*
* \param ctrlMsgRecvCallBack
* Pointer to the callback to be called when the handle has received a message.
*
* \param ctrlMsgFlushRecvCallBack
* Pointer to the callback to be called when the handle has received a flush message.
*
*  \return
*    CY_IPC_PIPE_SUCCESS          - Callback registered successfully
*    CY_IPC_PIPE_ERROR_BAD_CLIENT - Client ID out of range, callback not registered.
*
*******************************************************************************/
cy_en_ipc_pipe_status_t Cy_BLE_IPC_ControllerRegisterClientCallbacks(cy_ipc_pipe_callback_ptr_t ctrlMsgRecvCallBack,
                                                                     cy_ipc_pipe_callback_ptr_t ctrlMsgFlushRecvCallBack)
{
    cy_en_ipc_pipe_status_t returnStatus;

    Cy_BLE_IPC_CtrlMsgFlushRecvStackHandle = ctrlMsgFlushRecvCallBack;

    returnStatus = Cy_IPC_Pipe_RegisterCallback(CY_BLE_IPC_CONTROLLER_ADDR, ctrlMsgRecvCallBack,
                                                CY_BLE_CYPIPE_MSG_SEND_ID);

    if(returnStatus == CY_IPC_PIPE_SUCCESS)
    {
        returnStatus = Cy_IPC_Pipe_RegisterCallback(CY_BLE_IPC_CONTROLLER_ADDR, &Cy_BLE_IPC_CtrlMsgFlushRecvCallBack,
                                                    CY_BLE_CYPIPE_MSG_COMPLETE_ID);
    }

    return(returnStatus);
}


/*******************************************************************************
* Function Name: Cy_BLE_IPC_SendMessageToHost
****************************************************************************//**
*
* This function sends a message from the Controller to Host.
*
* \param msg
* Pointer to the message structure to be sent.
*
* \param controllerIpcRelCallBack
* Pointer to the Release callback function.
*
* \param controllerPollCallBack
* Pointer to the callback to be called when the handle has received a message.
*
*  \return
*    CY_IPC_PIPE_SUCCESS    - message was sent to the other end of the pipe
*    CY_IPC_PIPE_BAD_HANDLE - the handle provided for the pipe was not valid
*    CY_IPC_PIPE_SEND_BUSY  - the pipe is already busy sending a message
*    CY_IPC_PIPE_DIR_ERROR  - tried to send on the "to" end of a unidirectional pipe
*
*******************************************************************************/
cy_en_ipc_pipe_status_t Cy_BLE_IPC_SendMessageToHost(uint32_t *msg,
                                                     cy_ipc_pipe_relcallback_ptr_t controllerIpcRelCallBack,
                                                     cy_ipc_pipe_relcallback_ptr_t controllerPollCallBack)
{
    cy_en_ipc_pipe_status_t returnStatus;

    returnStatus = Cy_IPC_Pipe_SendMessage(CY_BLE_IPC_HOST_ADDR, CY_BLE_IPC_CONTROLLER_ADDR, msg,
                                           controllerIpcRelCallBack);

    if(returnStatus != CY_IPC_PIPE_SUCCESS)
    {
        Cy_IPC_Pipe_RegisterCallbackRel(CY_BLE_IPC_CONTROLLER_ADDR, controllerPollCallBack);
    }

    return(returnStatus);
}


/*******************************************************************************
* Function Name: Cy_BLE_IPC_HostMsgFlushRecvCallBack
****************************************************************************//**
*
* This a callback to be called when the handle has received a flush message.
*
* \param msgPtr: Pointer to the callback message.
*
*******************************************************************************/
static void Cy_BLE_IPC_HostMsgFlushRecvCallBack(uint32_t *msgPtr)
{
    /* Call the BLE Stack IPC handler */
    Cy_BLE_IPC_HostMsgFlushRecvStackHandle(msgPtr);

    /* Call the application notification handler */
    if(Cy_BLE_HostRegisteredCallback != NULL)
    {
        Cy_BLE_HostRegisteredCallback();
    }
}


/*******************************************************************************
* Function Name: Cy_BLE_IPC_HostMsgRecvCallBack
****************************************************************************//**
*
* This a callback to be called when a message is received on a pipe.
*
* \param msgPtr
* Pointer to the callback message.
*
*******************************************************************************/
static void Cy_BLE_IPC_HostMsgRecvCallBack(uint32_t *msgPtr)
{
    if(msgPtr != NULL)
    {
        /* Call the BLE Stack IPC handler */
        Cy_BLE_IPC_HostMsgRecvStackHandle(msgPtr);
    }

    /* Call the application IPC notification handler */
    if(Cy_BLE_HostRegisteredCallback != NULL)
    {
        Cy_BLE_HostRegisteredCallback();
    }
}


/*******************************************************************************
* Function Name: Cy_BLE_IPC_HostRegisterClientCallbacks
****************************************************************************//**
*
* This function registers a callbacks to be called when a message is received on a pipe.
*
* \param hostMsgRecvCallBack
* Pointer to the callback to be called when the handle has received a message.
*
* \param hostMsgFlushRecvCallBack
* Pointer to the callback to be called when the handle has received a flush message.
*
*  \return
*    CY_IPC_PIPE_SUCCESS          - Callback registered successfully
*    CY_IPC_PIPE_ERROR_BAD_CLIENT - Client ID out of range, callback not registered.
*
*******************************************************************************/
cy_en_ipc_pipe_status_t Cy_BLE_IPC_HostRegisterClientCallbacks(cy_ipc_pipe_callback_ptr_t hostMsgRecvCallBack,
                                                               cy_ipc_pipe_callback_ptr_t hostMsgFlushRecvCallBack)
{
    cy_en_ipc_pipe_status_t returnStatus;

    Cy_BLE_IPC_HostMsgRecvStackHandle      = hostMsgRecvCallBack;
    Cy_BLE_IPC_HostMsgFlushRecvStackHandle = hostMsgFlushRecvCallBack;

    returnStatus = Cy_IPC_Pipe_RegisterCallback(CY_BLE_IPC_HOST_ADDR, &Cy_BLE_IPC_HostMsgRecvCallBack,
                                                CY_BLE_CYPIPE_MSG_SEND_ID);

    if(returnStatus == CY_IPC_PIPE_SUCCESS)
    {
        returnStatus = Cy_IPC_Pipe_RegisterCallback(CY_BLE_IPC_HOST_ADDR, &Cy_BLE_IPC_HostMsgFlushRecvCallBack,
                                                    CY_BLE_CYPIPE_MSG_COMPLETE_ID);
    }

    /* Call the application notification handler */
    if(Cy_BLE_HostRegisteredCallback != NULL)
    {
        Cy_BLE_HostRegisteredCallback();
    }
    return(returnStatus);
}


/*******************************************************************************
* Function Name: Cy_BLE_IPC_SendMessageToController
****************************************************************************//**
*
* This function sends a message from the Host to Controller.
*
* \param msg
* Pointer to the message structure to be sent.
*
* \param hostIpcRelCallBack
* Pointer to the Release callback function.
*
* \param hostPollCallBack
* Pointer to the callback to be called when the handle has received a message.
*
*  \return
*    CY_IPC_PIPE_SUCCESS - message was sent to the other end of the pipe
*    CY_IPC_PIPE_BAD_HANDLE - the handle provided for the pipe was not valid
*    CY_IPC_PIPE_SEND_BUSY - the pipe is already busy sending a message
*    CY_IPC_PIPE_DIR_ERROR - tried to send on the "to" end of a unidirectional pipe
*
*******************************************************************************/
cy_en_ipc_pipe_status_t Cy_BLE_IPC_SendMessageToController(uint32_t *msg,
                                                           cy_ipc_pipe_relcallback_ptr_t hostIpcRelCallBack,
                                                           cy_ipc_pipe_relcallback_ptr_t hostPollCallBack)
{
    cy_en_ipc_pipe_status_t returnStatus;

    returnStatus = Cy_IPC_Pipe_SendMessage(CY_BLE_IPC_CONTROLLER_ADDR, CY_BLE_IPC_HOST_ADDR, msg, hostIpcRelCallBack);

    if(returnStatus != CY_IPC_PIPE_SUCCESS)
    {
        Cy_IPC_Pipe_RegisterCallbackRel(CY_BLE_IPC_HOST_ADDR, hostPollCallBack);
    }

    return(returnStatus);
}


/*******************************************************************************
***
****   Battery and Temperature Monitor  Functions
***
*******************************************************************************/

/*******************************************************************************
* Function Name: Cy_BLE_HAL_RadioGetAbsVbat
****************************************************************************//**
*
* This function returns absolute value of voltage.
*
* input param: raw - pointer to the 16 bit result from MXD registers,
* output param: vbat - pointer to the calculated voltage value in mV.
*
*******************************************************************************/
void Cy_BLE_HAL_RadioGetAbsVbat(const uint16_t *raw, uint16_t *vbat)
{
     *vbat = ((CY_BLE_RADIO_VOLTAGE_MONITOR_SLOPE * (*raw)) - CY_BLE_RADIO_VOLTAGE_MONITOR_OFFSET) /
               CY_BLE_RADIO_VOLTAGE_MONITOR_SLOPE_MULTIPLIER;
}


/*******************************************************************************
* Function Name: Cy_BLE_HAL_RadioGetAbsTemp
****************************************************************************//**
*
* This function returns absolute temperature value.
*
* input param: raw - pointer to the the 16 bit result from MXD registers,
* output param: temp - pointer to the int16_t calculated temperature value in C.
*
*******************************************************************************/
void Cy_BLE_HAL_RadioGetAbsTemp(const uint16_t *raw, int16_t *temp)
{
    *temp = CY_BLE_RADIO_TEMP_MONITOR_OFFSET -
            ((CY_BLE_RADIO_TEMP_MONITOR_SLOPE * (int16_t)(*raw)) / CY_BLE_RADIO_TEMP_MONITOR_SLOPE_MULTIPLIER);
}


/*******************************************************************************
***
****   HAL for Controller only (HCI) mode
***
*******************************************************************************/

/*******************************************************************************
* Function Name: Cy_BLE_HAL_UART_Interrupt
****************************************************************************//**
*
*  Handles the Interrupt service Routine for the UART.
*
*******************************************************************************/
void Cy_BLE_HAL_UART_Interrupt(void)
{
    CY_ASSERT_L1(NULL != cy_ble_halConfigPtr->hw);

    uint8_t uartTxStatus = CY_BLE_INTR_TX_SUCCESS;
    uint32_t srcInterrupt;

    uint8_t dLength = 0u;
    uint8_t srcCount = 0u;
    uint8_t uartRxStatus = CY_BLE_INTR_RX_SUCCESS;
    uint8_t receivedData;

    /* Evaluate RX interrupt event */
    srcInterrupt = Cy_SCB_GetRxInterruptStatusMasked(cy_ble_halConfigPtr->hw->uartHw);

    if(0u != (srcInterrupt & CY_SCB_RX_INTR_NOT_EMPTY))
    {
        if(0u != (srcInterrupt & CY_SCB_RX_INTR_UART_PARITY_ERROR))
        {
            uartRxStatus |= CY_BLE_INTR_RX_PARITY_ERROR;
        }
        if(0u != (srcInterrupt & CY_SCB_RX_INTR_UART_FRAME_ERROR))
        {
            uartRxStatus |= CY_BLE_INTR_RX_FRAME_ERROR;
        }
        if(0u != (srcInterrupt & CY_SCB_RX_INTR_OVERFLOW))
        {
            uartRxStatus |= CY_BLE_INTR_RX_OVERFLOW;
        }
        if(uartRxStatus == CY_BLE_INTR_RX_SUCCESS)
        {
            dLength = (uint8_t)Cy_SCB_GetNumInRxFifo(cy_ble_halConfigPtr->hw->uartHw);
            for(srcCount = 0u; srcCount < dLength; srcCount++)
            {
                receivedData = (uint8_t)Cy_SCB_ReadRxFifo(cy_ble_halConfigPtr->hw->uartHw);
                Cy_BLE_HAL_MappingUartRxDataHandler(receivedData);
            }
        }
        else
        {
            Cy_SCB_ClearRxFifo(cy_ble_halConfigPtr->hw->uartHw);
        }
        Cy_SCB_ClearRxInterrupt(cy_ble_halConfigPtr->hw->uartHw, srcInterrupt);
    }
    else
    {
        /* No RX interrupt. Do nothing. */
    }

    /* Evaluate TX interrupt event in sequence */
    srcInterrupt = Cy_SCB_GetTxInterruptStatusMasked(cy_ble_halConfigPtr->hw->uartHw);

    /* BLE Stack manager TX UART complete */
    if(0u != (srcInterrupt & CY_SCB_TX_INTR_UART_DONE))
    {
        if(0u != (srcInterrupt & CY_SCB_TX_INTR_OVERFLOW))
        {
            /*Stack manager TX UART error */
            uartTxStatus |= CY_BLE_INTR_TX_OVERFLOW;
        }
        Cy_BLE_HAL_MappingUartTxCompltHandler();
        Cy_SCB_ClearTxInterrupt(cy_ble_halConfigPtr->hw->uartHw, srcInterrupt);
    }
    else
    {
        /* No TX interrupt. Do nothing. */
    }
}


/*******************************************************************************
* Function Name: Cy_BLE_HAL_UART_Start
****************************************************************************//**
*
*  Enables the platform UART TX and RX interrupts and then enables the UART.
*
*******************************************************************************/
void Cy_BLE_HAL_UART_Start(void)
{
    CY_ASSERT_L1(NULL != cy_ble_halConfigPtr->hw);

    /* Setup ISR */
    (void)Cy_SysInt_Init(cy_ble_halConfigPtr->hw->uartIsrConfig, &Cy_BLE_HAL_UART_Interrupt);
    NVIC_EnableIRQ((IRQn_Type)cy_ble_halConfigPtr->hw->uartIsrConfig->intrSrc);

    (void)Cy_SCB_UART_Init(cy_ble_halConfigPtr->hw->uartHw, cy_ble_halConfigPtr->hw->uartConfig, NULL);

    /* Configure interrupt sources. */
    Cy_SCB_SetRxInterruptMask(cy_ble_halConfigPtr->hw->uartHw, CY_SCB_RX_INTR_NOT_EMPTY |
                                CY_SCB_RX_INTR_OVERFLOW | CY_SCB_RX_INTR_UNDERFLOW);
    Cy_SCB_SetTxInterruptMask(cy_ble_halConfigPtr->hw->uartHw, CY_SCB_TX_INTR_OVERFLOW |
                                                        CY_SCB_TX_INTR_UART_DONE);

    Cy_SCB_UART_Enable(cy_ble_halConfigPtr->hw->uartHw);
}


/*******************************************************************************
* Function Name: Cy_BLE_HAL_UART_Stop
****************************************************************************//**
*
*  Disables the UART, clears all pending interrupts and disables the UART TX
*  and RX interrupts. This will also empty out the FIFOs.
*
*******************************************************************************/
void Cy_BLE_HAL_UART_Stop(void)
{
    CY_ASSERT_L1(NULL != cy_ble_halConfigPtr->hw);

    /* Stop interrupt and UART */
    NVIC_DisableIRQ((IRQn_Type)cy_ble_halConfigPtr->hw->uartIsrConfig->intrSrc);

    Cy_SCB_UART_Disable(cy_ble_halConfigPtr->hw->uartHw, NULL);
}


/*******************************************************************************
* Function Name: Cy_BLE_HAL_UART_Transmit
****************************************************************************//**
*
*  Sends the data to UART TX FIFO. The function handles data length up to the
*  supported TX FIFO length of the UART hardware module.
*
*  \param dataBuf: Pointer to the data to send through the UART
*  \param length:  the length of data to transmit in bytes
*
*******************************************************************************/
void Cy_BLE_HAL_UART_Transmit(uint8_t *dataBuf,
                              uint8_t length)
{
    CY_ASSERT_L1(NULL != cy_ble_halConfigPtr->hw);

    Cy_SCB_UART_PutArrayBlocking(cy_ble_halConfigPtr->hw->uartHw, dataBuf, (uint32_t)length);
}


/*******************************************************************************
* Function Name: Cy_BLE_HAL_UART_EnableInterrupt
****************************************************************************//**
*
*   Enables the UART interrupt to the interrupt controller.
*   Do not call this function unless Cy_BLE_HAL_UART_Start() has been called or the
*   functionality of the Cy_SysInt_Init() function, which sets the vector and the
*   priority, has been called.
*
*******************************************************************************/
void Cy_BLE_HAL_UART_EnableInterrupt(void)
{
    CY_ASSERT_L1(NULL != cy_ble_halConfigPtr->hw);

    NVIC_EnableIRQ((IRQn_Type)cy_ble_halConfigPtr->hw->uartIsrConfig->intrSrc);
}


/*******************************************************************************
* Function Name: Cy_BLE_HAL_UART_DisableInterrupt
****************************************************************************//**
*
*   Disables the UART Interrupt in the interrupt controller.
*
*******************************************************************************/
void Cy_BLE_HAL_UART_DisableInterrupt(void)
{
    CY_ASSERT_L1(NULL != cy_ble_halConfigPtr->hw);

    NVIC_DisableIRQ((IRQn_Type)cy_ble_halConfigPtr->hw->uartIsrConfig->intrSrc);
}

#endif /* CY_IP_MXBLESS */

/* [] END OF FILE */
