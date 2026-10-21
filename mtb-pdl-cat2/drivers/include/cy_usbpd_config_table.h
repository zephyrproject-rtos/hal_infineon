/***************************************************************************//**
* \file cy_usbpd_config_table.h
* \version 2.110
*
* This file specifies the structure and helper functions for Configuration table
* present in flash for various supported devices.
*
********************************************************************************
* \copyright
* (c) (2022 - 2025), Cypress Semiconductor Corporation (an Infineon company) or
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
#ifndef CONFIG_TABLE_H_
#define CONFIG_TABLE_H_

#include "cy_device.h"
#include "cy_device_headers.h"

#if (defined(CY_IP_MXUSBPD) || defined(CY_IP_M0S8USBPD))

#include "cy_usbpd_defines.h"
#include "cy_usbpd_common.h"

#define CY_CONFIG_TABLE_AUTO                (0)
/**< Auto configuration table type. */
#define CY_CONFIG_TABLE_WIRELESS            (1)
/**< Wireless configuration table type. */
#define CY_CONFIG_TABLE_POWER               (2)
/**< Power configuration table type. */
#define CY_CONFIG_TABLE_HOST                (3)
/**< Host configuration table type. */
#define CY_CONFIG_TABLE_DOCK                (4)
/**< Dock configuration table type. */

/** \cond DOXYGEN_HIDE */

#define GET_DR_SWAP_RESP(resp)              ((resp) & 0x3u)
/**< Macro to extract the default DR_SWAP command response from the swap_response field
     in the configuration table. */

#define GET_PR_SWAP_RESP(resp)              (((resp) & 0xCu) >> 2u)
/**< Macro to extract the default PR_SWAP command response from the swap_response field in the configuration table. */

#define GET_VCONN_SWAP_RESP(resp)           (((resp) & 0x30u) >> 4u)
/**< Macro to extract the default VCONN_SWAP command response from the swap_response field
     in the configuration table. */

#define CY_MAX_DEV_COUNT_CDTT                (16u)
/**< Maximum device count. Indicates the maximum number of device connection supported by the DMC */

#define CY_CONFIG_GET_PPS_SNK_ENABLED(resp)  ((resp) & 0x01u)
/**< Macro to extract the PPS Sink Enable/Disable field from the config field.*/

#define CY_CONFIG_GET_PPS_SRC_ENABLED(resp)  (((resp) >> 0x01u) & 0x01u)
/**< Macro to extract the PPS Source Enable/Disable field from the config field.*/

/**
 * @brief Struct to hold the Alt modes settings.
 */
typedef struct
{
    uint8_t dfp_alt_mode_mask;        /**< Custom DFP SVID mask */
    uint8_t ufp_alt_mode_mask;        /**< Custom UFP SVID mask.Should be set to 0 as custom alt. modes are not supported in UFP role.*/
    uint16_t disc_id_len;             /**< Size of the Discover identity response in bytes. */
    uint16_t disc_id_offset;          /**< Size of the Discover SVID response in bytes. */
    uint16_t disc_svid_len;           /**< Offset of the Discover SVID response. */
    uint16_t disc_svid_offset;        /**< Size of the Discover mode response in bytes. */
    uint16_t disc_mode_len;           /**< Size of the Discover mode response in bytes.  */
    uint16_t disc_mode_offset;        /**< Offset of the Discover mode response.There are two options available for handling the discover mode responses:
                                        * 1) First option is to restrict firmware to have only four modes in total.
                                        * 2) Second option is to have a single discover mode response and each of the response will be programmed one after the other.
                                        * The size of each response needs to be maintained separately.*/
    uint8_t reserved[2];              /**< Reserved for future use */
    uint16_t base_am_info;            /**< This is a data with unknown length which contains all base alternate mode related configurations like
                                        *  supported SVIDs and information which of SVIDs could be run simultaneously */
} cy_stc_pdaltmode_cfg_settings_t;

/**
 * @brief Struct to hold the Custom Alt mode settings.
 */
typedef struct
{
    uint16_t custom_alt_mode;        /**< Custom alt mode */
    uint8_t dfp_alt_mode_mask;       /**< Custom DFP SVID mask */
    uint8_t ufp_alt_mode_mask;       /**< Custom UFP SVID mask.Should be set to 0 as custom alt. modes are not supported in UFP role.*/
    uint8_t reserved[4];             /**< Reserved for future */
} cy_stc_pdaltmode_custom_alt_cfg_settings_t;

#if CY_USE_CONFIG_TABLE

/**
 * @brief Struct to hold the automotive charger settings.
 */
typedef struct
{
    uint8_t reserved;                 /**< Reserved for ROM issue. */
    bool policy_manager_enable;      /**< Source policy manager.
                                      * Source policy manager Enable/Disable
                                      *  0 -> Disable
                                      * 1 ->Enable */
    uint8_t sys_power;                /**< VBUS total system power in Watts. Fractional input in 0.5 Watts increment is acceptable provided the difference between this value and port maximum power is in the range of 7.5 Watts - 9.5 Watts. */
    uint8_t port_power;               /**< VBUS per port maximum power in Watts */
    uint8_t configurable_power_OC2;   /**< Maximum Port's Budget @OC2 Level either in % or Value  */
    uint8_t configurable_power_OC3;   /**< Maximum Port's Budget @OC3 Level either in % or Value  */
    bool pps_enable;                  /**< PPS Enable/Disable
                                        * 0 -> Disable
                                        * 1 ->Enable */
    bool unconstrained_power_enable;   /**< Unconstrained Power Enable/Disable
                                        * 0 -> Disable
                                        *  1 ->Enable*/
    uint8_t vin_throttling_ctrl;  /**< Battery voltage throttling control */
    uint8_t vin_oc1;              /**< Minimum input voltage in 100mV units required for the system to supply OC1 (100%) power rating */
    uint8_t vin_oc2;              /**< Minimum input voltage in 100mV units required for the system to supply OC2 (50%) power rating.
                                   *   To skip this power level, load with the 0xFF.
                                   *   To terminate at this level, load with 0.
                                   */
    uint8_t vin_oc3;              /**< Minimum input voltage in 100mV units required for the system to supply OC3 (15W) power rating. To skip this power level, load with the 0xFF. To terminate at this level, load with 0.
                                   *   Beyond this threshold, the port shall be shutoff.
                                   */
    sensor_data_t sensor_data[4]; /**< Temperature throttling information for sensors */
    uint8_t vin_fault_max_safe_voltage; /**< VIN maximum safe voltage */
    uint8_t pdo_all_voltage_rail; /**< Enable/Disable all PDO voltage rail availability in SRC_CAP,
                                   * instead of spec recommended PDO source voltages for the
                                   * given port power (PDP).
                                   * PDO list customization option.
                                   */
    uint16_t max_current;         /**<  Maximum current that can be sourced in steps of 10 mA units.
                                   * All PDOs generated through Automotive policy/features are
                                   * capped with this maximum current limit.
                                   * PDO list customization option.
                                   */
    bool fractional_system_power; /**< Gets set if valid fractional total system power is selected.
                                      * 0->Selected Total System Power is an integer
                                      * 1->Selected Total System Power is a fraction. Actual selected system power is 0.5 Watts more than the integer value present in ""sys_pwr"" field.
                                      * This field is not visible in EZ-PD Config utility GUI and is updated internally by the tool as required.
                                      */
    uint8_t reserved_1[3];           /**< Reserved bytes */

} auto_cfg_settings_t;

/**
 * @brief Struct to hold the OVP settings.
 */
typedef struct
{
    uint8_t enable;         /**< Whether to enable/disable OVP */
    uint8_t mode;           /**< VBUS OVP Mode Selection
                             *    0 - OVP using ADC comparator
                             *    1 - OVP using dedicated comparator, Firmware detects trips and turns off FETs
                             *    2 - OVP using dedicated comparator, Hardware detects trips and turns off FETs */
    uint8_t threshold;       /**< OVP threshold: Excess voltage above expected value in percentage of expected voltage */
    uint8_t debounce;       /**< OVP debounce duration in micro-seconds.
                             *   If a non-zero debounce is specified,
                             *   there can be an error of upto 35 us due to the device being in sleep mode.
                             */
    uint8_t retryCount;      /**< Number of consecutive OVP events allowed before the port operation is
                                 suspended by CCG firmware. */
    uint8_t reserved[3];    /**< Reserved for future use */
} ovp_settings_t;

/**
 * @brief Struct to hold the OCP settings.
 */
typedef struct
{
    uint8_t enable;         /**< Whether to enable/disable OCP */
    uint8_t mode;           /**< VBUS OCP Mode Selection
                                 *    0 - OCP using external hardware
                                 *    1 - Internal OCP with neither software debounce nor automatic FET control
                                 *    2 - Internal OCP with automatic FET control by hardware when an OCP event is detected
                                 *    3 - Internal OCP with software debounce using delay in milliseconds specified by the user */
    uint8_t threshold;      /**< OCP threshold: Excess current in percentage of maximum allowed current. */
    uint8_t debounce;       /**< OCP debounce period in milliseconds. OCP handling is only performed if
                             *   the OCP condition persists for this duration. */
    uint8_t retryCount;      /**< Number of consecutive OCP events allowed before the port is suspended by CCG firmware. */
    uint8_t senseRes;      /**< Sense Resistor impedance in milli-Ohm units. */
    uint8_t csRes;         /**< Current sense tuning resistor impedance in 100 Ohm units. */
    uint8_t threshold2;     /**< Secondary OCP threshold (corresponding to peak current condition). Set to 0 if not used. */
    uint8_t debounce2;      /**< Debounce period in ms corresponding to secondary threshold. */
    uint8_t reserved[3];    /** < Reserved for future use */

} ocp_settings_t;

/**
 * @brief Struct to hold the RCP settings.
 */
typedef struct
{
    uint8_t enable;         /**< Whether to enable/disable RCP */
    uint8_t retryCount;      /**< Number of retries allowed for recovery. */
    uint16_t reserved;      /**< Reserved bytes. */
} rcp_settings_t;

/**
 * @brief Struct to hold the UVP settings.
 */
typedef struct
{
    uint8_t enable;         /**< Whether to enable/disable UVP */
    uint8_t mode;           /**< VBUS UVP Mode Selection
                             *    0 - UVP using ADC comparator
                             *    1 - UVP using dedicated comparator, Firmware detects trips and turns off FETs
                             *    2 - UVP using dedicated comparator, Hardware detects trips and turns off FETs */
    uint8_t threshold;      /**< UVP threshold: Reduced voltage below expected value in percentage of
                                 expected voltage */
    uint8_t debounce;       /**< UVP debounce duration in micro-seconds.
                             *   If a non-zero debounce is specified,
                             *   there can be an error of upto 35 us due to the device being in sleep mode. */
    uint8_t retryCount;      /**< Number of consecutive UVP events allowed before the port operation is
                                 suspended by CCG firmware. */
    uint8_t reserved[3];    /** < Reserved for future use */
} uvp_settings_t;

/**
 * @brief Struct to hold the SCP settings.
 */
typedef struct
{
    uint8_t enable;         /**< Whether to enable/disable SCP */
    uint8_t senseRes;      /**< Sense Resistor impedance in milli-Ohm units. */
    uint8_t threshold;      /**< SCP threshold: Excess current in percentage of maximum allowed current. */
    uint8_t debounce;       /**< SCP debounce duration in micro-seconds. This should ideally be set to 0. */
    uint8_t retryCount;      /**< Number of consecutive SCP events allowed before the port operation is suspended. */
    uint8_t mode;           /** < SCP mode */
    uint8_t reserved[2];    /** < Reserved for future use */
} scp_settings_t;

/**
 * @brief Struct to hold the Vconn OCP settings.
 */
typedef struct
{
    uint8_t enable;             /**< Whether to enable/disable VCONN OCP */
    uint8_t threshold;          /**< Max. Vconn current allowed in 10 mA units. */
    uint8_t debounce;           /**< Vconn OCP debounce period in ms. */
    uint8_t retryCount;         /**< Number of consecutive OCP events allowed before the port is suspended by CCG firmware. */
} vconn_ocp_settings_t;

/**
 * @brief Struct to hold the OTP settings.
 */
typedef struct
{
    uint8_t enable;             /**< Whether to enable/disable OTP */
    uint8_t therm_type;         /**< Type of thermistor used for temperature sensing:
                                 *   0 = Negative Temperature Coefficient (NTC)
                                 *   1 = Positive Temperature Coefficient (PTC)
                                 *   2 = Internal VBJT measurement.
                                 */
    uint16_t cutoff_val;        /**< Reading corresponding to the temperature at which OTP cutoff is to be
                                     performed (in mV or degrees C) */
    uint16_t restart_val;       /**< Reading corresponding to the temperature at which system operation
                                     can be resumed (in mV or degrees C) */
    uint16_t debounce;          /**< OTP debounce duration in ms. */
    uint8_t therm_1_enable;     /**< Enable/Disable the second thermistor */
    uint8_t therm_1_type;        /**< Type of thermistor used for temperature sensing:
                                 *   0 = Negative Temperature Coefficient (NTC)
                                 *   1 = Positive Temperature Coefficient (PTC)
                                 *   2 = Internal BJT sensing.
                                 */
    uint16_t cutoff_val_1;      /**< Reading corresponding to the temperature at which OTP cutoff is to be
                                     performed (in mV or degrees C) */
    uint16_t restart_val_1;     /**< Reading corresponding to the temperature at which system operation
                                     can be resumed (in mV or degrees C) */
    uint8_t reserved[2];         /**< Reserved for future use */
} otp_settings_t;

/**
 *  @brief PD port-specific configuration data from the configuration table.
 */
typedef struct
{
    /** Structure Signature - 'PDSC' */
    uint32_t signature;

    /** Configuration parameter version. Consists of 8-bit major(bits 15:8) and
    * 8-bit minor(bits 7:0) version */
    uint16_t version;

    /** Length of Manufacturer Information.
    * 0 - For no information.
    * 5 to 26: For valid information. */
    uint8_t mfgLenInfo;

    /** Reserved byte for alignment. */
    uint8_t reserved_0;

    /** Manufacturer Vendor Id. Range 0x0000 - 0xFFFF. */
    uint16_t mfgVid;

    /** Manufacturer Product Id. Range 0x0000 - 0xFFFF. */
    uint16_t mfgPid;

    /** Manufacturer Name. Null terminated string. */
    uint8_t mfgName[22];

    /** Extended Source Capability message support
     * 1 - Enable support
     * 0 - Disable support */
    uint8_t scedbEn;

    /** Extended Sink Capability message support
     * 1 - Enable support
     * 0 - Disable support */
    uint8_t skedbEn;

    /** Extended Source Capability response */
    uint8_t extSrcCap[25];

    uint8_t reserved[3];

    /** Extended Sink Capability response */
    uint8_t extSnkCap[24];

    /** PD port role:
     *  0 - Sink
     *  1 - Source
     *  2 - Dual Role */
    uint8_t portRole;

    /** Default port role in case of dual role ports:
     *  0 - Sink
     *  1 - Source */
    uint8_t defPortRole;

    /** Type-C current level (Rp value) used as source:
     *  0 - 900 mA
     *  1 - 1.5 A
     *  2 - 3 A */
    uint8_t curLevel;

    /** Number of cable discovery attempts to be made
     *  Range: 0x00 - 0x14 */
    uint8_t cableDiscCount;

    /** B29:B20 of the first 5V Fixed Source PDO */
    uint8_t srcPdoFlags[2];

    /** B29:B20 of the first 5V Fixed Sink PDO */
    uint8_t snkPdoFlags[2];

    /** Whether Rp-Rd toggle is enabled in unattached state. */
    uint8_t drpToggleEn;

    /** Bitmask that specifies supported Rp values:
     *  Bit 0 - 900 mA Rp
     *  Bit 1 - 1.5 A Rp
     *  Bit 2 - 3 A Rp */
    uint8_t rpSupported;

    /** Whether USB-PD operation is supported on the port.
     *  1 - Enable PD Operation
     *  0 - Disable PD Operation */
    uint8_t pdOpEn;

    /** Whether Try.Src or Try.Sink is enabled for the port:
     *  0 - No Try.Src or Try.Sink supported
     *  1 - Try.Src supported
     *  2 - Try.Sink supported */
    uint8_t prefPwrRole;

    /** Whether the PD port is to be disabled at start-up. */
    uint8_t portDis;

    /** Whether cable discovery is enabled as part of the source state machine.
     *  1 - Enable Cable Discovery
     *  0 - Disable Cable Discovery */
    uint8_t cableDiscEn;

    /** Whether dead battery operation is supported.
     *  1 - Dead battery operation is supported.
     *  0 - Dead battery operation is not supported. */
    uint8_t deadBatSupp;

    /** Whether Type C Error Recovery is enabled.
     *  1 - Enable error recovery
     *  0 - Disable error recovery */
    uint8_t errorRecoveryEn;

    /** Whether to enable/disable accessory mode
     *  1 - Enable accessory mode
     *  0 - Disable accessory mode */
    uint8_t accessoryEn;

    /** Whether to enable/disable disconnect detect mechanism using Rp in Sink
     * role
     * 1 - Enable disconnect detect using Rp in Sink Role
     * 0 - Disable disconnect detect using Rp in Sink Role */
    uint8_t rpDetachEn;

    /** Whether Vconn supply should be left enabled even if the EMCA's cable
     * VDO indicates that Vconn is not required. */
    uint8_t vconnRetain;

    /** Fast Role Swap feature enabled flags:
     *  Bit 0 - FRS receive enable
     *  Bit 1 - FRS transmit enable */
    uint8_t frsConfig;

    /** Number of source PDOs supported (max. value is 7) */
    uint8_t srcPdoCount;

    /** Bitmask that enables specified entries in the Src. PDO list. */
    uint8_t defSrcPdoMask;

    /** Number of sink PDOs supported (max. value is 7) */
    uint8_t snkPdoCount;

    /** Bitmask that enables specified entries in the Sink PDO list. */
    uint8_t defSnkPdoMask;

    /** Source PDO list  */
    uint32_t srcPdo[7];

    /** Sink PDO list  */
    uint32_t snkPdo[7];

    /** Sink PDO Min/Max Current list */
    uint16_t snkPdoMinMaxCur[7];

    /** Reserved for future use. */
    uint16_t reserved_2;

    /** Get_Revision message response */
    uint32_t pdRevision;

    /** Get_Source_Info message response */
    uint32_t srcInfo;

    /** Number of EPR source PDOs supported. Non-zero value enables EPR source
     * operation. Range: 0 - 6 */
    uint8_t eprSrcPdoCount;

    /** Bit-mask enabling each EPR source PDO. */
    uint8_t eprSrcPdoMask;

    /** Number of EPR sink PDOs supported. Non-zero value enables EPR sink
     * operation. Range: 0 - 6 */
    uint8_t eprSnkPdoCount;

    /** Bit-mask enabling each EPR sink PDO. */
    uint8_t eprSnkPdoMask;

    /** EPR Source PDO List */
    uint32_t eprSrcPdo[6];

    /** EPR Sink PDO List */
    uint32_t eprSnkPdo[6];

    /** EPR Sink PDO Min/Max Current list */
    uint16_t eprSnkPdoMinMaxCur[6];
} cy_stc_pdstack_port_cfg_t;

#endif /* CY_USE_CONFIG_TABLE */

/**
 * @brief Struct to hold the Billboard settings.
 */
typedef struct
{

    uint8_t volatile bb_enable;     /**< Billboard enable and type selection:
                                      *0 --> No billboard
                                      *1 --> External billboard
                                      *2 --> Internal billboard
                                      *3 --> External billboard. Billboard configurations are stored in the configuration table of DMC.
                                     */
    uint8_t volatile bb_always_on;  /**< Billboard operation control:
                                     *    0 => Enable the billboard device only on error.
                                     *    1 => Always enable billboard on connection.
                                     */
    uint8_t volatile bb_option;     /**< This field provides the various functionalities supported by
                                     *   the device.
                                     *    Bit 0    => 0 = No HID interface, 1 = Enable HID interface.
                                     *    Bits 1:7 => Reserved.
                                     */
    uint8_t    bb_cur_draw;          /**< Max current draw in multiple of 2mA units. */
    uint16_t    bb_timeout;         /**< This field is valid only if bb_enable is non-zero. The field
                                     *   determines how long the billboard interface stays on, in seconds.
                                     *   FFFFh    => Stays on until disconnect.
                                     *   000Ah to FFFEh => Timeout in seconds.
                                     */

    uint8_t volatile bb_bus_power;  /**< This field is valid only for devices that have internal USB
                                     *   support. The field indicates whether the device is bus powered or not.
                                     */
    uint8_t volatile bb_unique_container_id;   /**< This field is valid only for devices that have
                                                    internal USB support. The field indicates whether the device
                                                    creates the container ID descriptor or uses what is provided
                                                    in the BOS descriptor.
                                                */
    uint16_t    bb_vid;                         /**<  VID for the Billboard device. Used only when bb_enable is set to 3. */
    uint16_t    bb_pid;                         /**<  PID for the Billboard device.Used only when bb_enable is set to 3. */

    uint8_t    reserved_0[2];                   /**< Reserved area for future expansion. */
    uint16_t volatile bb_bos_dscr_offset;       /**<  This field is valid only for devices that have
                                                     internal USB support. The field provides the offset inside
                                                     the table where the BOS descriptor for the device is located.
                                                     The BOS descriptor is mandatory for billboard support.
                                                 */
    uint16_t    bb_string_dscr_offset[15];      /**< This field is valid only for devices that have
                                                     internal USB support. The field provides the offset inside
                                                     the table where the various string descriptors for the device
                                                     are located. The descriptors are expected to be in a fixed order
                                                     and is mandatory. The following are the usage models for the
                                                     various string indices:
                                                 *     0   => Manufacturer string (mandatory).
                                                 *     1   => Product string (mandatory).
                                                 *     2   => Serial string (optional).
                                                 *            0000h = No serial string descriptor,
                                                 *            FFFFh = Unique serial string generated by device,
                                                 *            Any other offset is treated as a valid serial string.
                                                 *     3   => Configuration string (mandatory).
                                                 *     4   => Billboard interface string (mandatory).
                                                 *     5   => HID interface string (mandatory).
                                                 *     6   => Additional info URL string (mandatory).
                                                 *     7-8 => Alternate mode strings (mandatory for all valid modes).
                                                 */
    uint8_t    reserved_1[2];                   /**< Reserved area for future expansion. */

} cy_stc_bb_settings_t;


/**
 * @brief Structure to hold the Qi main configuration parameters list.
 */
typedef struct 
{
    /** Qi Main Configuration - 80 Bytes */

    /** Profile - 12 Bytes */

    /** PTMC Defined by WPC for Infineon its 0x0067 */
    uint16_t ptmc;
    /** WPC Version  MSbyte is not used ; LSByte has High Nibble as Major version and Low Nibble as Minor Version Valid Values are 0x0012 and 0x0013*/
    uint16_t wpcVersion;
    /* Console verbosity levels */
    uint8_t consoleVerbosity;
    uint8_t reserved_1[7];

    /** Coil Configuration - 4 Bytes*/

    /** Number of Coils is Always 1 for WiCG1 */
    uint8_t numCoils;
    uint8_t reserved_2[3];

    /** Wireless Mode Configuration - 16 Bytes */

    /** Enable EPP mode */
    uint8_t eppEnable;
    /** Enable HiPP Mode */
    uint8_t hippEnable;

    /** Enable Samsung Ppde */
    uint8_t samsungPpdeEnable;
    /** Enable PPP Mode */
    uint8_t externalClockEnable;
    uint8_t reserved_3[12];

    /** Packet Timeout Configuration - 16 Bytes*/

    /** ASK Packet Timeout */
    uint16_t askPacketTimeout;
    /** CEP Packet Timeout */
    uint16_t cepPacketTimeout;
    /** RPP Packet Timeout */
    uint16_t rppPacketTimeout;
    uint8_t reserved_5[10];

    /** EPT Timer Configuration - 20 Bytes*/

    /** Digital Ping retry Count on unknown fault */
    uint8_t eptUnknownRetCnt;
    /** Digital Ping retry Count on Charge Completion */
    uint8_t eptChgCmpltRetCnt;
    /** Digital Ping retry Count on Internal Fault */
    uint8_t eptIntrFaultRetCnt;
    /** Digital Ping retry Count on Over Temperature */
    uint8_t eptOTPRetCnt;
    /** Digital Ping retry Count on Over Voltage */
    uint8_t eptOVPRetCnt;
    /** Digital Ping retry Count on Over Current */
    uint8_t eptOCPRetCnt;
    /** Digital Ping retry Count on Battery Failure */
    uint8_t eptPingDelayBatFailRetCnt;
    uint8_t reserved_6[13];

} cy_stc_qi_main_cfg_t;


/**
 * @brief Structure to hold the Qi Coil Configuration parameters list.
 */
typedef struct
{
    /* Qi COIL Configuration */

    /** Qi Coil Operation Configuration - 36 Bytes */

    /** Qi Coil operating mode */
    uint8_t coilOPMode;
    /** Reserved */
    uint8_t reserved_0;
    /** Minimum operating frequency in frequency control mode. */
    uint16_t pwmMinFreq;
    /** Maximum operating frequency in frequency control mode. */
    uint16_t pwmMaxFreq;
    /** Minimum duty in frequency control mode.  */
    uint16_t pwmMinDuty;
    /** Reserved.  */
    uint16_t reserved_1;
    /** Analog ping time Vbridge voltage.  */
    uint16_t vbridgeAnaPingVolt;
    /** Reserved  */
    uint16_t reserved_2;
    /** Maximum Vbridge voltage in BPP Mode*/
    uint16_t vbridgeMaxBPPVolt;
    /** Maximum Vbridge voltage in EPP Mode*/
    uint16_t vbridgeMaxEPPVolt;
    /** Maximum Vbridge voltage in HiPP Mode*/
    uint16_t vbridgeMaxHiPPVolt;
    /** Reserved  */
    uint16_t reserved_13;
    /** EPP mode potential load power*/
    uint8_t eppPotentialPow;
    /** HiPP mode potential load power*/
    uint8_t hippPotentialPow;
    /** EPP mode guaranteed load power*/
    uint16_t guaranteedPow;
     /** HiPP mode guaranteed load power*/
    uint16_t hippGuaranteedPow;
    uint8_t reserved_3[12];


    /** Analog Ping Configuration - 12 Bytes*/

    /** Analog Ping Interval */
    uint16_t anaPingInterval;
    /** Analog Ping Interval during Error */
    uint16_t anaPingIntervalInERR;
    /** Analog Ping frequency for Q */
    uint16_t anaPingFreq;
    /** Analog Ping duty cycles for Q */
    uint16_t anaPingdutyCycles;
    /** Minimum number of Analog Pings for Q */
    uint8_t anaPingMinCount;
    uint8_t reserved_4[3];

    /** Digital Ping Configuration - 24 Bytes*/

    /** Digital ping voltage */
    uint16_t digPingVol;
    /** Digital ping Frequency */
    uint16_t digPingFreq;
    /** Digital ping Duty */
    uint16_t digPingDuty;
    /** Digital ping Interval */
    uint16_t digPingIntr;
    /** Error Mode Digital ping Interval */
    uint16_t digPingIntrInErr;
    uint8_t reserved_5[14];


    /** ASK Demod Configuration - 12 Bytes*/

    /** ASK demod voltage path gain - High */
    uint8_t askDemodVoltHighGain;
    /** ASK demod voltage path gain - Low */
    uint8_t askDemodVoltLowGain;
    /** ASK demod current path gain */
    uint8_t askDemodCurrGain;
    /** ASK Demod Sequence selection */
    uint8_t askDemodSeqSel;
    /**Qi Timer FSK response time minimum & maximum in mS*/
    uint8_t fskRespTimeMin;
    uint8_t fskRespTimeMax;
    uint8_t reserved_6[6];

    /** PID Configuration - 28 Bytes */

    /** Coil proportional  Gain*/
    uint16_t pidKp;
    /** Coil Integral Gain*/
    uint16_t pidKi;
    /** Coil Differential Gain*/
    uint16_t pidKd;
    /** Coil SV MV Selection */
    uint8_t pidSvMvSel;
    /** Reserved */
    uint8_t reserved_7;
    /** Coil SV MV ; PID Scaling Multiplication Factor*/
    uint16_t pidSvMvScale;
    /** Coil Integral Term Maximum Change*/
    uint16_t pidMi;
    /** Coil PID Maximum Change*/
    uint16_t pidMaxpid;
    /** vbridge low load level for BPP */
    uint8_t pidBPPlowLoadThr;
    /** vbridge low load level for EPP */
    uint8_t pidEPPlowLoadThr;
    /** High gain Kp to be used for low load conditions*/
    uint16_t pidLowLoadKp;
    /** PID Max duty change */
    uint16_t maxDutyChange;
    /** PID supported duty */
    uint16_t supportedDuty;
    /** PID max frequency change */
    uint16_t maxFreqChange;
    uint8_t reserved_8[72];

    /** Buck Boost Base Configuration  - 20 Bytes*/

    /** Vbridge Regulator Selection */
    uint8_t vbridgeRegulatorSel;
    /** Reserved */
    uint8_t reserved_9;
    /** Vbridge Regulation Table Offset */
    uint16_t vbridgeRegTableoffset;
    /** Vbridge Regulation Table Length */
    uint16_t vbridgeRegTableLen;
    uint8_t reserved_10[14];

    /** Inverter Bridge Configuration  - 20 Bytes*/

    /** Vbridge Regulation Table Offset */
    uint16_t invBridgeTableoffset;
    /** Vbridge Regulation Table Length */
    uint16_t invBridgeTableLen;
    uint8_t reserved_11[16];

    /** FOD Base Configuration - 16 Bytes*/

    /** FOD Configuration Table Offset */
    uint16_t fodTableOffset;
    /** FOD Configuration Table Length */
    uint16_t fodTableLen;
    uint8_t reserved_12[12];
} cy_stc_qi_coil_cfg_t;

typedef struct 
{
    /** FOD manual calibration coefficients A,B and C*/
    float   PowLossFODCoeffA;
    float   PowLossFODCoeffB;
    float   PowLossFODCoeffC;
    /** Threshold for a likely FO presence */
    uint16_t PowLossFODThr;
    /** Threshold for a Certain FO presence */
    uint16_t PowLossFODThrMax;
    /** Count for Power Recycle  after FOD */
    uint8_t PowLossFODAssertCnt;
    /** Count for Power Disconnect after FOD */
    uint8_t PowLossFODDisconnectCnt;
    /** Receiver power offset during guaranteed power */
    uint16_t PowerLossFODCalibOffset;
} cy_stc_qi_fod_powloss_cfg_t;


typedef struct 
{
    /** Threshold for a likely FO presence */
    uint16_t PowLossFODThr;
    /** Threshold for a Certain FO presence */
    uint16_t PowLossFODThrMax;
} cy_stc_qi_fod_powloss_cfg_ppde_t;

/**
 * @brief Structure to hold the FOD Configuration parameters list.
 */
typedef struct 
{

    /** FOD Configuration Total - 152 Bytes */

    /** Q Factor FOD Configuration - 20 Bytes*/

    /** Q free air FOD enable/disable. */
    uint8_t qFODEn;
    /* reserved */
    uint8_t reserved_0;
    /** Q free air value. Measured by LCR meter without anything on the Tx */
    uint8_t qFreeAirVal;
    /** Q Tolerance to consider */
    uint8_t qTolerance;
    /** Q Free AIR FOD threshold percentage*/
    uint8_t qFreeAirFODThrPer;
    /** Digital ping re-try count in free air FOD, 0 means disable it */
    uint8_t qDigPingRetryCnt;
    /** Scale factor for high reported Q calibration, percentage */
    uint8_t qHiScaleFactor;
    /** Scale factor for low reported Q calibration, percentage */
    uint8_t qLoScaleFactor;
    uint8_t reserved_1[12];

    /** Resonant Frequency  - 32 Bytes*/

    /** Resonance frequency threshold in % */
    uint16_t resFreqThresholdPer;
    /** Resonance frequency calibration factor */
    uint16_t resFreqScaleFactor;
    uint8_t reserved_2[24];

    /** Power Loss FOD Configuration - 112 Bytes*/

    /** FOD Power Loss Feature Enable/Disable with FOD manual calibration parameters for given power  
        0x03 - Enable FOD with BPP 
        0x07 - Enable FOD with BPP and 5w EPP 
        0x0F - Enable FOD ; BPP FOD;5w EPP and 15w EPP
        0x1F - Enable FOD ; BPP FOD;5w EPP 15w EPP and 50w HiPP */
    uint8_t powLossFODEn;
    uint8_t reserved_3[3];

    /** Power Loss FOD Configuration for BPP */
    cy_stc_qi_fod_powloss_cfg_t powLossFODBppCfg;
    uint8_t reserved_4[4];
    /** Power Loss FOD Configuration for EPP - 5w */
    cy_stc_qi_fod_powloss_cfg_t powLossFODEpp5wCfg;
    uint8_t reserved_5[4];
    /** Power Loss FOD Configuration for EPP - 15w */
    cy_stc_qi_fod_powloss_cfg_t powLossFODEpp15wCfg;
    /** Power Loss FOD Configuration for Samsung PPDE */
    cy_stc_qi_fod_powloss_cfg_ppde_t powLossFODPpdeCfg;
     /** Power Loss FOD Configuration for HiPP - 50w */
    cy_stc_qi_fod_powloss_cfg_t powLossFODHipp50wCfg;
    uint8_t reserved_6[16];
}cy_stc_fod_cfg_t;

/**
 * @brief Structure to hold the Vin configuration parameters list.
 */
typedef struct 
{
    /** Vin Configuration - 24 Bytes */

    /** Enables dynamic PD contract selection based on 
     * PRx requirements to optimize power usage */
    uint8_t pdPowerOptimizationEnable;
    uint8_t reserved[23];
}cy_stc_vin_cfg_t;

/**
 * @brief Structure to hold the Fault Protection configuration parameters list.
 */
typedef struct 
{

    /** Fault Protection Configuration - 36 Bytes */

    /** OCP Threshold ; 0-Disable */
    uint16_t faultOCPThr;
    /** Persistent OCP condition debounce time in mS */
    uint8_t faultOCPDeb;
    /** OCP retry count.*/
    uint8_t faultOCPRetryCnt;
    /** Maximum power limit threshold*/
    uint8_t maxPowThr;
    uint8_t reserved_0[3];
    /** Vbridge OVP Threshold ; 0-Disable */
    uint16_t faultOVPThr;
    /** Persistent OVP condition debounce time in uS */
    uint8_t faultOVPDeb;
    /** OVP retry count.*/
    uint8_t faultOVPRetryCnt;
    /**System  Over temperature protection triggering threshold; 0-Disable */
    uint8_t faultSysOTPTrigThr;
    /**System  Over temperature protection release threshold */
    uint8_t faultSysOTPRelThr;
    /** Coil Over temperature protection release threshold;  0-Disable*/
    uint8_t faultCoilOTPTrigThr;
    /**Coil  Over temperature protection release threshold */
    uint8_t faultCoilOTPRelThr;
    uint8_t reserved_1[20];

}cy_stc_fault_protect_cfg_t;

/**
 * @brief Structure to hold the Wireless Configuration will be populated by Solution
 */
typedef struct {
    uint16_t qiMainTableOffset;
    uint16_t qiMainTableLen;
    uint16_t qiCoil0TableOffset;
    uint16_t qiCoil0TableLen;
    uint16_t qiCoil1TableOffset;
    uint16_t qiCoil1TableLen;
    uint16_t qiCoil2TableOffset;
    uint16_t qiCoil2TableLen;
    uint16_t qiCoil3TableOffset;
    uint16_t qiCoil3TableLen;
    uint16_t vinConfigTableOffset;
    uint16_t vinConfigTableLen;
    uint16_t faultProtectTableOffset;
    uint16_t faultProtectTableLen;
    uint16_t port0OvpTableOffset;
    uint16_t port0OvpTableLen;
    uint16_t port0OcpTableOffset;
    uint16_t port0OcpTableLen;
    uint16_t port0UvpTableOffset;
    uint16_t port0UvpTableLen;
    uint16_t port0ScpTableOffset;
    uint16_t port0ScpTableLen;
    uint16_t legacyChargingConfigTableOffset;
    uint16_t legacyChargingConfigTableLen;
    uint32_t reserved_1[4];
}cy_wireless_port_config;

typedef struct
{
    uint16_t table_sign;             /**< Two byte signature to indicate validity of the configuration. */
    uint8_t     table_type;          /**< The table type indicates the type of solution.
                                      *   0 => Auto
                                      *   1 => WICG1
                                      *   2 => Power
                                      *   3 => Host
                                      *   4 => Dock
                                      */
    uint8_t     application;          /**< This field specifies the type of PD application supported:
                                       *   A => Auto
                                       *   B => WICG1
                                       *   C => Power
                                       *   D => Host
                                       *   F => DMC
                                       */
    uint16_t    table_version;        /**< Table version: This contains 4 bit major version, 4 bit minor
                                       *   version and 8 bit patch number.
                                       */
    uint16_t    table_size;           /**< Size of the configuration table in bytes. */
    uint32_t    table_checksum;       /**< 4-byte CRC. CRC32 is calculated over bytes 12 to bytes (table_size - 1).*/
    uint8_t     app_table_size;       /**< Size of auto application table in bytes. */
    uint8_t     reserved_0[7];        /**< Reserved for future use */
    uint16_t    port_0_config_offset; /**< Offset of the Port 0 Configuration table */
    uint16_t    port_0_config_size;   /**< Size of the Port 0 Configuration table in bytes. */
    uint16_t    port_1_config_offset; /**< Offset of the Port 1 Configuration table */
    uint16_t    port_1_config_size;   /**< Size of the Port 1 Configuration table in bytes. */
    uint16_t    auto_config_offset;   /**< Offset of the Auto Configuration table */
    uint16_t    auto_config_size;     /**< Size of the Auto Configuration table in bytes*/
    uint16_t    bb_offset;            /**< Offset of the Port 1 Configuration table */
    uint16_t    bb_size;              /**< Size of the Port 1 Configuration table in bytes*/
    uint16_t    user_area_offset;     /**< Offset of the User Parameter Configuration */
    uint16_t    user_area_size;       /**< Size of the User Parameter Configuration in bytes*/
} auto_config_t;

typedef struct
{
    uint16_t    table_sign;           /**< Two byte signature to indicate validity of the configuration. */
    uint8_t     table_type;           /**< The table type indicates the type of solution.
                                       *   0 => Auto
                                       *   1 => WICG1
                                       *   2 => Power
                                       *   3 => Host
                                       *   4 => Dock
                                       */
    uint8_t     application;          /**< This field specifies the type of PD application supported:
                                       *   A => Auto
                                       *   B => WICG1
                                       *   C => Power
                                       *   D => Host
                                       *   F => DMC
                                       */
    uint16_t    table_version;        /**< Table version: This contains 4 bit major version, 4 bit minor
                                       *   version and 8 bit patch number.
                                       */
    uint16_t    table_size;           /**< Size of the configuration table in bytes. */
    uint32_t    table_checksum;       /**< 4-byte CRC. CRC32 is calculated over bytes 12 to bytes (table_size - 1).*/
    uint8_t     reserved_0[8];        /**< Reserved for future use */
    uint16_t    port_0_config_offset; /**< Offset of the Port 0 Configuration table */
    uint16_t    port_0_config_size;   /**< Size of the Port 0 Configuration table in bytes*/
    uint16_t    port_1_config_offset; /**< Offset of the Port 1 Configuration table */
    uint16_t    port_1_config_size;   /**< Size of the Port 1 Configuration table in bytes */
    uint16_t    host_config_offset;   /**< Offset of the Host Configuration Table */
    uint16_t    host_config_size;     /**< Size of the Host Configuration Table */
    uint16_t    bb_offset;            /**< Offset of billboard table */
    uint16_t    bb_size;              /**< Size of billboard table */
    uint16_t    user_area_offset;     /**< Offset of the User Configuration area. */
    uint16_t    user_area_size;       /**< Size of the User Configuration area in bytes */
} host_config_t;

typedef struct
{
    uint16_t    table_sign;           /**< Two byte signature to indicate validity of the configuration. */
    uint8_t     table_type;           /**< The table type indicates the type of solution.
                                       *   0 => Auto
                                       *   1 => WICG1
                                       *   2 => Power
                                       *   3 => Host
                                       *   4 => DMC
                                       */
    uint8_t     application;          /**<  This field specifies the type of PD application supported:
                                       *   A => Auto
                                       *   B => WICG1
                                       *   C => Power
                                       *   D => Host
                                       *   F => DMC
                                       */
    uint16_t    table_version;        /**< Table version: This contains 4 bit major version, 4 bit minor
                                       *   version and 8 bit patch number.
                                       */
    uint16_t    table_size;           /**< Size of the configuration table in bytes. */
    uint32_t    table_checksum;       /**< 4-byte CRC. CRC32 is calculated over bytes 12 to bytes (table_size - 1).*/
    uint8_t     reserved_0[8];        /**< Reserved for future use */
    uint16_t    wireless_config_offset; /**< Offset of the Wireless Configuration table */
    uint16_t    wireless_config_size;   /**< Size of the Wireless Configuration table in bytes*/
    uint16_t    port_0_config_offset;   /**< Offset of the Port 0 Configuration table */
    uint16_t    port_0_config_size;     /**< Size of the Port 0 Configuration table in bytes*/
    uint8_t     reserved_1[8];          /**< Reserved area for future expansion. */
} wireless_config_t;


/**
 *  @typedef dock_config_t
 *  @brief Dock configuration data from the configuration table.
 */
typedef struct
{
    uint16_t    table_sign;             /**< Two byte signature to indicate validity of the configuration. */
    uint8_t     table_type;             /**< The table type indicates the type of solution.
                                         *  0 => Auto
                                         *  1 => WICG1
                                         *  2 => Power
                                         *  3 => Host
                                         *  4 => Dock
                                         */
    uint8_t     application;            /**< This field specifies the type of application supported:
                                         */
    uint16_t    table_version;          /**< Table version: This contains 4 bit major version, 4 bit minor
                                         * version and 8 bit patch number.
                                         */
    uint16_t    table_size;             /**< Size of the configuration table in bytes. */
    uint32_t    table_checksum;         /**< 4-byte CRC. CRC32 is calculated over bytes 12 to bytes (table_size - 1).
                                         */
    uint8_t     app_table_size;         /**< The size of DMC application table in bytes. */
    uint8_t     reserved_0[7];          /**< Reserved bytes for future expansion. */

    uint16_t    port_0_config_offset;   /** < Offset of the Port 0 Configuration table */
    uint16_t    port_0_config_size;     /** < Size of the Port 0 Configuration table in bytes*/

    uint16_t    port_1_config_offset;   /** < Offset of the Port 1 Configuration table */
    uint16_t    port_1_config_size;     /** < Size of the Port 1 Configuration table in bytes*/

    uint16_t    cdtt_offset;            /**< Offset of the Composite Dock Topology table. */
    uint16_t    cdtt_size;              /**< Size of the Composite Dock Topology table in bytes. */

    uint16_t    smart_power_offset;     /**< Offset of the Smart Power table. */
    uint16_t    smart_power_size;       /**< Size of the Smart Power table in bytes. */

    uint16_t    bb_offset;              /**< Offset of the Billboard table. */
    uint16_t    bb_size;                /**< Size of the Billboard table in bytes. */

    uint16_t    sec_config_offset;      /**< Offset of the Security Configuration table. */
    uint16_t    sec_config_size;        /**< Size of the Security Configuration table in bytes. */

    uint16_t    user_area_offset;       /**< Offset of the User Configuration area. */
    uint16_t    user_area_size;         /**< Size of the User Configuration area in bytes */
}dock_config_t;

/**
 * @brief Struct to hold Thunderbolt Host related config settings.
 */
typedef struct
{
    uint8_t tbt_controller;     /**< Ridge type:
                                  * 0 -> Alpine Ridge Single Port
                                  * 1 -> Alpine Ridge Dual Port
                                  * 2-> Titan Ridge Single Port
                                  * 3 -> Titan Ridge Dual Port
                                  * 4 -> Goshen Ridge */
    uint8_t hpd_handling;       /**< Handle the HPD signal via GPIO or I2C
                                  * 0 -> GPIO
                                  * 1 ->Virtual HPD */
    uint8_t vpro_capable;       /**< Whether the host supports VPRO docks. */
    uint8_t sbu_conf;           /**< SBU MUX configuration to be used:
                                  * 0 -> Full SBU MUX Configuration
                                  * 1 -> SBU MUX without polarity change
                                  * 2 -> SBU MUX pass-through */
    uint8_t usb4_supp;         /**< USB4 data roles supported by the design:
                                  * 0 -> None
                                  * 1 -> Host
                                  * 2 -> Dual-Role
                                  * 3 -> Device */
    uint8_t usb3_supp;         /**< USB3 data roles supported by the design:
                                  * 0 -> None
                                  * 1 -> Host
                                  * 2 -> Dual-role
                                  * 3 -> Device */
    uint8_t host_supp;         /**< USB4 host features supported bit map (this field is copied into b16:b13 of the EUDO sent by the host):
                                  * b0 -> Host present
                                  * b1 -> TBT3 is supported by the host's connection manager.
                                  * b2 -> DP tunneling over USB4 supported
                                  * b3 -> PCIe tunneling over USB4 supported. */
    uint8_t non_tbt_mux;       /**< 1- Non-TB Mux used . */
} tbthost_cfg_settings_t;

/**
 * @struct custom_host_cfg_settings_t
 * @brief Struct to hold the Custom Alt mode settings.
 */
typedef struct
{
    uint32_t pwr_threshold;             /**< Minimal power to turn the FET ON if source provides at least this. */
    uint8_t snk_path_enable;            /**< Sink path enable/disable */
    uint8_t req_max_pwr;                /**< Option to request max current provided by the port partner instead of the current
                                             * mentioned in the sink capabilities */
    uint8_t ext_powered_prs;            /**< Option to accept PR_SWAP even if there is an external powered bit is set */
    uint8_t pdo_sel_alg;                /**< Source PDO selection algorithm (Default, max Power, Voltage or Current ) */
    uint8_t pps_enable;                 /**< PPS Enable/Disable:
                                          * b0 - PPS Sink Enable/Disable.
                                          * b1 - PPS Source Enable/Disable.
                                          * b2-7 - Reserved. */
    uint8_t reserved[3];                /**< Reserved.*/
} custom_host_cfg_settings_t;

/**
 * @struct cy_stc_pdaltmode_dp_cfg_settings_t
 * @brief Struct to hold Display port related config settings.
 */
typedef struct
{
     uint8_t dp_config_supported;        /**< Byte 0xA0: Supported Pin configurations for DP modes
                                                 *  0b00000000: USB SS only.
                                                 *  0b00000001: Reserved for future use (A).
                                                 *  0b00000010: Reserved for future use (B).
                                                 *  0b00000100: Pin Config C.
                                                 *  0b00001000: Pin Config D.
                                                 *  0b00010000: Pin Config E.
                                                 *  0b00100000: Pin Config F.
                                                 */
     uint8_t dp_mux_control;             /**< Byte 0xA1: DP_MUX_CONTROL method:
                                                 *  0 => DP MUX Controlled by CCG.
                                                 *  1 => DP MUX Controlled by EC.
                                                 */
     uint8_t dp_mode_trigger;            /**< Byte 0xA2: DP_MODE_TRIGGER: Trigger for initializing DP modes.
                                                 *  0 => CCG initiates DP after contract.
                                                 *  1 => CCG waits for a trigger from EC.
                                                 */
     uint8_t dp_operation;               /**< Byte 0xA3: Type of DP operation supported.
                                                 *  Bit 0: DP Sink supported.
                                                 *  Bit 1: DP Source supported.
                                                 *  Bit 7: DP 2.1 supported.
                                                 */
     uint8_t dp_pref_mode;               /**< Byte 0xA4: DP preferred mode.
                                                 *  Bit 0:
                                                 *   0: CCG as DP Sink prefers 4 lane DP mode only.
                                                 *   1: CCG as DP Sink prefers 2 lane DP + USB SS Mode.
                                                 *  All other bits are reserved. */
     uint8_t reserved_6[3];              /**< Byte 0xA5: Reserved area for future expansion. */

}cy_stc_pdaltmode_dp_cfg_settings_t;


typedef struct
{
   uint16_t port_n_pd_table_offset;     /**< Offset of the PD Port n configuration table */
   uint16_t port_n_pd_table_len;        /** < Size of the PD Port n configuration table in bytes */
   uint16_t port_n_app_table_offset;    /**< Offset of the App Port n configuration table */
   uint16_t port_n_app_table_len;       /** < Size of the App Port n configuration table in bytes */
   uint16_t port_n_base_alt_mode_table_offset;  /**< Offset of the Port n base alternate configuration table */
   uint16_t port_n_base_alt_mode_table_len;     /** < Size of the  Port n base alternate configuration table in bytes */
   uint16_t port_n_tbt_table_offset;            /**< Offset of the Port n TBT alternate mode configuration table */
   uint16_t port_n_tbt_table_len;               /**< Size of the Port n TBT alternate mode configuration table */
   uint16_t port_n_dp_table_offset;             /**< Offset of the Port n DP alternate mode configuration table */
   uint16_t port_n_dp_table_len;                /**< Size of the Port n DP alternate mode configuration table */
   uint16_t port_n_soc_table_offset;            /**< Offset of the Port n SoC configuration table  */
   uint16_t port_n_soc_table_len;               /**< Size of the Port n SoC configuration table  */
   uint16_t port_n_custom_alt_mode_table_offset; /**< Offset of the Port n custom alternate configuration table */
   uint16_t port_n_custom_alt_mode_table_len;    /**< Size of the Port n custom alternate configuration table */
   uint16_t port_n_ovp_table_offset;            /**< Offset of the Port n OVP configuration table */
   uint16_t port_n_ovp_table_len;               /**< Size of the Port n OVP configuration table */
   uint16_t port_n_ocp_table_offset;            /**< Offset of the Port n OCP configuration table */
   uint16_t port_n_ocp_table_len;               /**< Size of the Port n OCP configuration table */
   uint16_t port_n_uvp_table_offset;            /**< Offset of the Port n UVP configuration table */
   uint16_t port_n_uvp_table_len;               /**< Size of the Port n UVP configuration table */
   uint16_t port_n_scp_table_offset;            /**< Offset of the Port n SCP configuration table */
   uint16_t port_n_scp_table_len;               /**< Size of the Port n SCP configuration table */
   uint16_t port_n_rcp_table_offset;            /**< Offset of the Port n RCP configuration table */
   uint16_t port_n_rcp_table_len;               /**< Size of the Port n RCP configuration table */
   uint16_t port_n_otp_table_offset;            /**< Offset of the Port n OTP configuration table */
   uint16_t port_n_otp_table_len;               /**< Size of the Port n OTP configuration table */
   uint16_t port_n_vconn_ocp_table_offset;      /**< Offset of the Port n Vconn OCP configuration table */
   uint16_t port_n_vconn_ocp_table_len;         /**< Size of the Port n Vconn OCP configuration table */
   uint16_t port_n_power_table_offset;          /**< Offset of the Port n Power configuration table */
   uint16_t port_n_power_table_len;             /**< Size of the Port n Power configuration table */
   uint16_t port_n_bch_table_offset;            /**< Offset of the Battery charging configuration table */
   uint16_t port_n_bch_table_len;               /**< Size of the Battery charging configuration table */
   uint16_t custom_host_config_table_offset;    /**< Offset of the Custom host configuration table */
   uint16_t custom_host_config_table_len;       /**< Size of the Custom host configuration table in bytes */
   uint16_t amd_config_table_offset;            /**< Offset of the AMD configuration table */
   uint16_t amd_config_table_len;               /**< Size of the AMD configuration table in bytes */
   uint16_t mtk_config_table_offset;            /**< Offset of the MTK configuration table */
   uint16_t mtk_config_table_len;               /**< Size of the MTK configuration table in bytes */

} pd_port_config_t;



typedef struct
{
    uint8_t pref_data_role;             /**< Indicates the preferred data role for the device:
                                         *   0 -> UFP
                                         *   1 -> DFP
                                         *   2 -> No preference */
    uint8_t pref_power_role;            /**< 0 - source
                                         *   1 - sink
                                         *   2- No preference */
    uint16_t port_func;                 /**< Bit 0 => USB3(Will be enabled if this bit is 1)
                                         *   Bit 1 => MFDP
                                         *   Bit 2 => TBT3
                                         *   Bit 3 => USB4
                                         *   Bit 4 => Prefer DP 4 Lane(Prefer to be in a 4 lane configuration) otherwise prefer DP 2 Lane
                                         *   Bit 5 => Rsvd
                                         *   Bit 6 => Rsvd
                                         *   Bit 7 => Rsvd */
    uint16_t flashing_vid;              /**< USB-PD VID used for the CC based flashing mode support. */
    uint16_t flashing_mode;             /**< USB-PD mode index used for the CC based flashing support.*/
    uint8_t snk_usb_susp_enable;        /**< Whether the device supports USB suspend as sink. */
    uint8_t snk_usb_comm_enable;        /**< Whether the device supports USB communication as sink. */
    uint8_t swap_response;              /**< Default response to be sent for various SWAP requests.
                                         *   Bits 1:0 => DR_SWAP
                                         *   Bits 3:2 => PR_SWAP
                                         *   Bits 5:4 => VCONN_SWAP
                                         *   0 -> Accept, 1 -> Reject, 2 -> Wait, 3 -> NOT_SUPPORTED.
                                         *   When using value '3', the device responds with NOT_SUPPORTED in PD 3.0 connection and
                                         *   responds with REJECT in PD 2.0 connection. */
    uint8_t reserved[9];                /**< Reserved for future */
} app_config_t;

/**
 * @struct soc_cfg_settings_t
 * @brief Struct to hold the ICL/TGL settings.
 */
typedef struct
{
    uint8_t soc_i2c_address;              /**< Configuring I2C Slave address to Intel SoC */
    uint8_t reserved;                     /**< Reserved for future use*/
    uint16_t soc_mux_init_delay;          /**< SoC MUX Init Delay configuration. Time allowed for the MUX to get initialized before Vbus power is enabled. */
    uint16_t soc_mux_config_delay;        /**< SoC MUX configuration delay. Time delay to be enforced between successive updates to the SoC MUX. */
    uint16_t tame_timeout_period;         /**< tAMEtimeout period in milliseconds.*/
} soc_cfg_t;

/**
 * @struct soc_cfg_settings_t
 * @brief Struct to hold the ICL/TGL settings.
 */
typedef struct
{
    uint8_t soc_i2c_address;              /**< Configuring I2C Slave address to Intel SoC */
    uint8_t platform_selection;           /**< Intel SoC Platform Selection:
                                           *   Unknown = 0
                                           *   Ice Lake = 1
                                           *   Tiger Lake = 2
                                           *   Rocket Lake / Maple Ridge = 3
                                           *   Meteor Lake = 4 */
    uint16_t soc_mux_init_delay;          /**< SoC MUX Init Delay configuration. Time allowed for the MUX to get initialized before Vbus power is enabled. */
    uint16_t soc_mux_config_delay;        /**< SoC MUX configuration delay. Time delay to be enforced between successive updates to the SoC MUX. */
    uint16_t tame_timeout_period;         /**< tAMEtimeout period in milliseconds.*/
    uint8_t retimer_i2c_address[2];       /**< Configuring I2C Master address to Retimer. Different addresses should be specified if two retimers are associated with a single PD port. */
    uint8_t retimer_count;                /**< Number of retimers per PD port (max=2) */
    uint8_t hpd_irq_ack_clear_method;     /**< Clear HPD_IRQ ACK method:
                                           *   0 - Clear implicitly.  SoC will implicitly clear its own HPD_IRQ bit after it is set to 1 by the PD Controller.
                                           *   1 - Clear explicitly. PD Controller will explicitly clear the HPD_IRQ bit back to 0 before setting it to 1 again. */
    uint8_t reserved[4];                  /**< Reserved for future use */
} intel_soc_cfg_settings_t;

/**
 * @struct amd_cfg_settings_t
 * @brief Struct to hold the AMD APU related config settings.
 */
typedef struct
{
    uint8_t amd_platform_type;          /**< Type AMD APU used in the design. */
    uint8_t amd_apu_mode;               /**< APU Polling or Interrupt based mode */
    uint8_t amd_apu_address;            /**< Configuring I2C slave address */
    uint8_t amd_apu_index;              /**< Configuring APU index which corresponds to slave address */
    uint8_t retimer_type;               /**< Retimer IC type which used in design. */
    uint8_t i2c_retimer_address;        /**< Configuring I2C Retimer address */
    uint8_t usb4_captive;               /**< Indicates whether design supports USB4 handling */
    uint8_t host_support;               /**< Protocol capabilities (TBT, DP, PCIe) of the host controller. */
    uint8_t usb4_support;               /**< USB4 roles supported by the host design. */
    uint8_t usb3_support;               /**< USB 3.2 roles supported by the host design. */
    uint8_t reserved[2];                /**< Reserved for future */
} amd_cfg_settings_t;

/* @struct mtk_cfg_settings_t
* @brief Struct to hold the MTK SoC USB4 MUX related config settings.
*/
typedef struct
{
   uint8_t mtk_platform_type;          /**< Type SoC USB4 MUX used in the design. */
   uint8_t soc_u4mux_mode;             /**< SoC USB4 MUX Polling or Interrupt based mode */
   uint16_t pd_controller_id;          /**< Configuring PD controller 2-byte id */
   uint8_t soc_u4mux_address;          /**< Configuring I2C slave address */
   uint8_t ipmux_offset;               /**< IPMUX Offset */
   uint8_t sideband_offset;            /**< SideBand Offset */
   uint8_t retimer_type;               /**< Retimer IC type which used in design. */
   uint8_t i2c_retimer_address;        /**< Configuring I2C Retimer address */
   uint8_t usb4_support;               /**< Indicates whether design supports USB4 handling */
   uint8_t host_support;               /**< Protocol capabilities (TBT, DP, PCIe) of the host controller. */
   uint8_t usb4_data_role;             /**< USB4 roles supported by the host design. */
   uint8_t usb3_data_role;             /**< USB 3.2 roles supported by the host design. */
   uint8_t sbu_conf;                   /**< SBU MUX configuration to be used:
                                          * 0 -> Full SBU MUX Configuration
                                          * 1 -> SBU MUX without polarity change
                                          * 2 -> SBU MUX pass-through */
   uint8_t reserved[2];                /**< Reserved for future */
} mtk_cfg_settings_t;

typedef struct
{
    uint16_t    table_sign;             /**< Two byte signature to indicate validity of the configuration. */
    uint8_t     table_type;             /**< The table type indicates the type of solution.
                                         *   0 => Auto
                                         *   1 => WICG1
                                         *   2 => Power
                                         *   3 => Host
                                         *   4 => Dock
                                         */
    uint8_t     application;            /**<  This field specifies the type of PD application supported:
                                         *   A => Auto
                                         *   B => WICG1
                                         *   C => Power
                                         *   D => Host
                                         *   F => DMC
                                         */
    uint16_t    table_version;          /**< Table version: This contains 4 bit major version, 4 bit minor
                                         *   version and 8 bit patch number.
                                         */
    uint16_t    table_size;             /**< Size of the configuration table in bytes.
                                         */
    uint32_t    table_checksum;         /**< 4-byte CRC. CRC32 is calculated over bytes 12 to bytes (table_size - 1).
                                         */
    uint8_t     reserved_0[8];          /** < Reserved for future use */
    uint16_t    port_0_config_offset;   /** < Offset of the Port 0 Configuration table */
    uint16_t    port_0_config_size;     /** < Size of the Port 0 Configuration table in bytes*/
    uint16_t    port_1_config_offset;   /** < Offset of the Port 1 Configuration table */
    uint16_t    port_1_config_size;     /** < Size of the Port 1 Configuration table bytes*/
    uint8_t    reserved_1[8];           /**< Reserved area for future expansion. */
} power_config_t;

/**
 *  @typedef dev_topology_t
 *  @brief Composite Dock Topology Table(CDTT) data structure for specific devices.
 *  Size of this structure is 16 bytes.
 */
typedef struct
{
    uint8_t     device_type;            /**< Device type indicates the type of device.
                                         * Refer dmc_dev_type_t for device type values.
                                         */
    uint8_t     comp_id;                /**< Component ID indicates instance of same device type. */
    uint8_t     image_mode;             /**< Image mode
                                         * B7:B4 => 0 = Single Image
                                         *          1 = Dual images, Symmetric Images
                                         *          2 = Dual images, Asymmetric Images
                                         *          3-0xF = Reserved/ Invalid
                                         * B3:B0 => Reserved
                                         */
    uint8_t     row_size_ind;           /**< Row size indicator.
                                         * Actual row size = row size indicator * 64
                                         */
    uint8_t     reserved_0[4];          /**< Padding for 4 byte alignment. */
    uint8_t     access_param[8];        /**< Access parameters. */
}dev_topology_t;

/**
 *  @typedef cdtt_config_t
 *  @brief CDTT (Composite Dock Topology Table) configuration data.
 */
typedef struct
{
    uint8_t     signature;              /**< 1-byte signature "C" for the CDTT configuration table. */
    uint8_t     cdtt_version;           /**< CDTT version. Version number for this table. */
    uint16_t    vendor_id;              /**< Vendor ID. 2-byte ID NUMBER to identify the customer/vendor corresponding to the dock.
                                         *   This is only used for dock identification. It is not the same as the DMC VID with which it enumerates.*/
    uint16_t    product_id;             /**< Product ID. 2-byte ID NUMBER to identify the product corresponding to the dock.
                                         *   This is only used for dock identification. It is not the same as the DMC PID with which it enumerates.*/
    uint16_t    device_id;              /**< Device ID. This is only used for dock identification. */
    uint8_t     vendor_str[32];         /**< Vendor string. This is only used for dock identification. */
    uint8_t     product_str[32];        /**< Product string. This is only used for dock identification. */
    uint8_t     dev_count;              /**< Device count. Indicates the number of devices used for firmware download (connected to DMC). */
    uint8_t     dig_sign_alg;           /**< Digital signature algorithm used for signing.
                                         *   0 - Unsigned
                                         *   1 - ECDSA
                                         *   2 - RSA 1024
                                         *   3 - RSA 2048
                                         */
    uint8_t     dock_type;              /**< This is for the tool to identify the TBT ref design and display related details for the user. */
    uint8_t     reserved_1[5];          /**< Reserved for alignment. */
    dev_topology_t dev_info[CY_MAX_DEV_COUNT_CDTT]; /**< Device topology info. */
}cdtt_config_t;

/**
 *  @typedef smart_power_config_t
 *  @brief Smart Power (power throttling) configuration data which is part of DMC configuration table.
 */
typedef struct
{
    uint8_t smart_pwr_enable;           /**< Enable/disable smart power feature. */
    uint8_t adp_det_enable;             /**< Adapter detect mechanism to be followed.
                                         *   0 - Adapter power will be used from the configuration table.
                                         *   1 - On-board jumper settings will be used for determining the adapter power.
                                         */
    uint16_t adp_pwr_watts;             /**< Adapter power in watts. Applicable only when adapter detect is disabled. */
    uint8_t buffer_pwr_watts;           /**< Buffer power in watts to be detected from adapter power for dock board. */
    uint8_t pwr_step_size_watts;        /**< Step size in watts at which power should be increased. */
    uint16_t pwr_monitor_period;        /**< Interval in ms at which power should be monitored. */
    uint8_t debounce_count;             /**< Debounce count for throttling. */
    uint8_t max_us_power;               /**< Max US power in watts. */
    uint8_t reserved_0[6];              /**< Reserved for future use. */
}smart_power_config_t;


/**
 *  @typedef sec_config_t
 *  @brief Signed fw update specific configuration data which is part of DMC configuration table.
 *   This configuration area is 400 bytes, the definition of this depends on the security algorithm used.
 */
typedef union
{
    uint8_t data[400];                  /**< security config area. */

    struct RSA_2048
    {
        uint8_t public_key[260];        /**< Public key for RSA-2048 along with 4-bytes of exponent.
                                         *   It should be 4-byte aligned. */
        uint8_t reserved[140];          /**< Reserved. */
    }rsa_2048;                          /**< RSA-2048 specific configuration area. */

    struct RSA_3072
    {
        uint8_t public_key[388];        /**< Public key for RSA-3072 along with 4-bytes of exponent.
                                         *   It should be 4-byte aligned. */
        uint8_t reserved[12];           /**< Reserved. */
    }rsa_3072;                          /**< RSA-3072 specific configuration area. */

}sec_config_t;

/**
 * @struct host_config_param_t
 * @brief Struct to hold the sub-host configuration table for Host SDK.
 */
typedef struct
{
    uint32_t db_event_mask;                     /**< Default value of HPI event mask that will be applied to all PD ports on the device */
    uint32_t io_port_level;                     /**< IO level on the GPIO ports */
}host_config_param_t;

#if CY_USE_CONFIG_TABLE
typedef struct
{

    uint8_t fb_type;                            /**< Type of power feedback:
                                                 *   Bit 0 --> No feedback
                                                 *   Bit 1 --> PWM
                                                 *   Bit 2 --> Direct feedback
                                                 *   Bit 3 --> Opto-isolator based feedback
                                                 */
    uint8_t reserved;                           /**< Reserved area for future expansion. */
    uint16_t vbus_min_volt;                     /**< VBus minimum voltage in mV */
    uint16_t vbus_max_volt;                     /**< VBus maximum voltage in mV */
    uint16_t vbus_dflt_volt;                    /**< Default VBus supply voltage when feedback control is tri-stated. */
    uint16_t cable_resistance;                  /**< Cable resistance in mOhm */
    uint16_t vbus_offset_volt;                  /**< VBus offset voltage in addition to contracted voltage in mV */
    uint8_t current_sense_res;                  /**< Available to adjust CSA accuracy on board. Unit of 0.1mOhm min_value = 10  max_value = 100*/
    uint8_t src_gate_drv_str;                   /**< Vbus source gate drive strength.
                                                 *   0 -> Slow
                                                 *   1 -> Normal
                                                 *   2 -> Fast*/
    uint16_t vbtr_up_step_width;                /**< Vbtr Upward transition step width in 1us units. For single slope
                                                 *   design, this shall be used for full voltage range. For dual slope
                                                 *   design this shall be used only for transitions above 5v. */
    uint16_t vbtr_down_step_width;              /**< Vbtr Downward transition step width in 1us units For single slope
                                                 *   design, this shall be used for full voltage range. For dual slope
                                                 *   design this shall be used only for transitions above 5v. */
    uint8_t prim_sec_turns_ratio;               /**< Primary to secondary turns ratio rounded to nearest decimal. min_value = 4 max_value = 10 */
    uint8_t sr_enable;                          /**< Enable/Disable the SR controller */
    uint8_t sr_rise_time;                       /**< SR gate driver rise time configuration.
                                                 *   0 -> Slow
                                                 *   1 -> Normal
                                                 *   2 -> Fast */
    uint8_t sr_fall_time;                       /**< SR gate driver fall time configuration
                                                 *   0 -> Slow
                                                 *   1 -> Normal
                                                 *   2 -> Fast */
    uint8_t sr_async_thresh;                    /**< Secondary width below which GDRV will be gated. Units in number of PASC Clock cycles. */
    uint8_t sr_supply_doubler;                  /**< Enable/Disable the doubler for gate drive function */
    uint8_t reserved_1;                         /**< Reserved for future use */
    uint8_t buck_boost_operating_mode;          /**< Indicates mode of Buck-Boost regulation. */
    uint8_t pwm_mode;                           /**< Indicates operational mode of power adapter secondary controller */
    uint8_t pwm_min_freq;                       /**< Minimum allowed switching frequency in QR/QR+FF mode in KHz */
    uint8_t pwm_max_freq;                       /**< Maximum allowed switching frequency in QR/QR+FF mode in KHz */
    uint8_t pwm_fix_freq;                       /**< PWM switching frequency in FF mode in KHz */
    uint8_t max_pwm_duty_cycle;                 /**< Maximum allowed PWM pulse duty cycle */
    uint8_t min_pwm_duty_cycle;                 /**< Minimum allowed PWM pulse duty cycle */
    uint8_t pwm_gate_pull_up_drv_strnth_LS1;    /**< adjust gate pull-up drive strength */
    uint8_t pwm_gate_pull_up_drv_strnth_LS2;    /**< adjust gate pull-up drive strength */
    uint8_t pwm_gate_pull_up_drv_strnth_HS1;    /**< adjust gate pull-up drive strength */
    uint8_t pwm_gate_pull_up_drv_strnth_HS2;    /**< adjust gate pull-up drive strength */
    uint8_t pwm_dithering_type;                 /**< enable / disable the dithering frequency configuration and pwm_dithering_type  */
    uint8_t pwm_dithering_freq_range;           /**< % of frequency dithering based on the set switching frequency */
    uint8_t power_inductor_value;               /**< Inductance L required for slope_comp_control calculation */
    uint8_t peak_current_sense_resistor;        /**< Ri required for slope_comp_control calculation */
    uint8_t phase_angle_control;                /**< phase angle between ports in degrees */
    uint8_t peak_current_limit;                 /**< Set the Current limit to shutdown the converter so that inductor shall not saturate */
    uint8_t max_pwm_duty_cycle_high_line;       /**< Maximum allowed PWM pulse duty cycle for high line condition */
    uint8_t reserved_2;                         /**< Reserved for future use */
    uint16_t vbtr_up_step_width_below_5v;       /**< Vbtr Upward transition step width in 1us units for dual slope
                                                 *   design when VBUS is below 5V */
    uint16_t vbtr_down_step_width_below_5V;     /**< Vbtr Downward transition step width in 1us units for dual slope
                                                 *   design when VBUS is below 5V */
    uint16_t pwm_max_freq_ex;                   /**< Maximum allowed switching frequency in QR/QR+FF mode in KHz, extended
                                                 *   for more than 254kHz operation. */
    uint8_t pwm_gate_pull_down_drv_strnth_LS1;  /**< adjust gate pull-down drive strength */
    uint8_t pwm_gate_pull_down_drv_strnth_LS2;  /**< adjust gate pull-down drive strength */
    uint8_t pwm_gate_pull_down_drv_strnth_HS1;  /**< adjust gate pull-down drive strength */
    uint8_t pwm_gate_pull_down_drv_strnth_HS2;  /**< adjust gate pull-down drive strength */
    uint8_t bbclk_freq;                         /**< Buck boost controller clock frequency in units of MHz */
    uint8_t pwm_fix_freq_dith;                  /**< Center PWM switching frequency when dithering is enabled */
    uint8_t pwm_dith_spread_cycles;             /**< Number of BBCLK cycles of spread required to achieve
                                                 * configured range of frequency spread */
    uint8_t reserved_3[8];                      /**< Reserved for future use */
} pwr_params_t;

/*****************************************************************************
 * Global Function Declarations
 *****************************************************************************/

/**
 * @brief This function gets the Auto config table data.
 * @return Returns a pointer to the config table info structure for various MPNs
 * @warning The information provided by this API must not be altered by the
 * application.
 */
const auto_config_t * get_auto_config(cy_stc_usbpd_context_t *context);

/**
 * @brief This function gets the Wireless config table data.
 * @return Returns a pointer to the config table info structure for various MPNs
 * @warning The information provided by this API must not be altered by the
 * application.
 */
const wireless_config_t * get_wireless_config(cy_stc_usbpd_context_t *context);

/**
 * @brief This function gets the Host config table data.
 * @return Returns a pointer to the config table info structure for various MPNs
 * @warning The information provided by this API must not be altered by the
 * application.
 */
const host_config_t * get_host_config(cy_stc_usbpd_context_t *context);

/**
 * @brief This function gets the Dock config table data.
 * @return Returns a pointer to the config table info structure
 * @warning The information provided by this API must not be altered by the
 * application.
 */
const dock_config_t * get_dock_config(cy_stc_usbpd_context_t *context);

/**
 * @brief This function gets the configuration information for the specified port.
 * @param port Port index.
 * @return Returns a pointer to the port specific config table info structure.
 * @warning The information provided by this API must not be altered by the
 * application.
 */
const pd_port_config_t * get_pd_port_config(cy_stc_usbpd_context_t *context);

/**
 * @brief Retrieve pointer to VBus OVP settings from the configuration table.
 *
 * This function retrieves the VBus OVP settings that is stored in
 * the configuration table and stores it in the run-time data structures.
 *
 * @param port USB-PD port for which the data is to be retrieved.
 * @return Pointer to VBus OVP settings.
 */
ovp_settings_t* pd_get_ptr_ovp_tbl(cy_stc_usbpd_context_t *context);

/**
 * @brief Retrieve pointer to VBus RCP settings from the configuration table.
 *
 * This function retrieves the VBus RCP settings that is stored in
 * the configuration table and stores it in the run-time data structures.
 *
 * @param port USB-PD port for which the data is to be retrieved.
 * @return Pointer to VBus RCP settings.
 */
rcp_settings_t* pd_get_ptr_rcp_tbl(cy_stc_usbpd_context_t *context);

/**
 * @brief Retrieve pointer to VBus OCP settings from the configuration table.
 *
 * This function retrieves the VBus OCP settings that is stored in
 * the configuration table and stores it in the run-time data structures.
 *
 * @param port USB-PD port for which the data is to be retrieved.
 * @return Pointer to VBus OCP settings.
 */
ocp_settings_t* pd_get_ptr_ocp_tbl(cy_stc_usbpd_context_t *context);

/**
 * @brief Retrieve pointer to VBus UVP settings from the configuration table.
 *
 * This function retrieves the VBus UVP settings that is stored in
 * the configuration table and stores it in the run-time data structures.
 *
 * @param port USB-PD port for which the data is to be retrieved.
 * @return Pointer to VBus UVP settings.
 */
uvp_settings_t* pd_get_ptr_uvp_tbl(cy_stc_usbpd_context_t *context);

/**
 * @brief Retrieve pointer to VBus SCP settings from the configuration table.
 *
 * This function retrieves the VBus SCP settings that is stored in
 * the configuration table and stores it in the run-time data structures.
 *
 * @param port USB-PD port for which the data is to be retrieved.
 * @return Pointer to VBus SCP settings.
 */
scp_settings_t* pd_get_ptr_scp_tbl(cy_stc_usbpd_context_t *context);

/**
 * @brief Retrieve pointer to Vconn OCP settings from the configuration table.
 *
 * This function retrieves the Vconn OCP settings that is stored in
 * the configuration table and stores it in the run-time data structures.
 *
 * @param port USB-PD port for which the data is to be retrieved.
 * @return Pointer to Vconn OCP settings.
 */
vconn_ocp_settings_t* pd_get_ptr_vconn_ocp_tbl(cy_stc_usbpd_context_t *context);

/**
 * @brief Retrieve pointer to OTP settings from the configuration table.
 *
 * This function retrieves the OTP settings that is stored in
 * the configuration table and stores it in the run-time data structures.
 *
 * @param port USB-PD port for which the data is to be retrieved.
 *
 * @return Pointer to OTP settings.
 */
otp_settings_t* pd_get_ptr_otp_tbl(cy_stc_usbpd_context_t *context);

/**
 * @brief Retrieve pointer to battery charging parameters from the configuration table.
 *
 * This function retrieves the legacy charging parameters that is stored in
 * the configuration table and stores it in the run-time data structures.
 *
 * @param port USB-PD port for which the data is to be retrieved.
 *
 * @return Pointer to legacy charging parameters.
 */
#if (BATTERY_CHARGING_ENABLE) || (QC_PPS_ENABLE)
cy_stc_legacy_charging_cfg_t* pd_get_ptr_chg_cfg_tbl(cy_stc_usbpd_context_t *context);
#endif /* (BATTERY_CHARGING_ENABLE) || (QC_PPS_ENABLE) */
/**
 * @brief Retrieve pointer to pdstack parameters from the configuration table.
 *
 * This function retrieves the pdstack parameters that is stored in
 * the configuration table and stores it in the run-time data structures.
 *
 * @param port USB-PD port for which the data is to be retrieved.
 *
 * @return Pointer to pdstack parameters.
 */
const cy_stc_pdstack_port_cfg_t* pd_get_ptr_pdstack_tbl(cy_stc_usbpd_context_t *context);

/**
 * @brief Retrieve pointer to power parameters from the configuration table.
 *
 * This function retrieves the power parameters that is stored in
 * the configuration table and stores it in the run-time data structures.
 *
 * @param port USB-PD port for which the data is to be retrieved.
 *
 * @return Pointer to power parameters.
 */
pwr_params_t* pd_get_ptr_pwr_tbl(cy_stc_usbpd_context_t *context);

/**
 * @brief Retrieve pointer to Automotive Charger settings from the configuration table.
 *
 * This function retrieves the Automotive Charger settings that is stored in
 * the configuration table and stores it in the run-time data structures.
 *
 * @param port USB-PD port for which the data is to be retrieved.
 *
 * @return Pointer to Automotive Charger settings.
 */
#if (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_CCG3PA))
auto_cfg_settings_t* pd_get_ptr_auto_cfg_tbl(cy_stc_usbpd_context_t *context);
#endif /* (defined(CY_DEVICE_CCG7D) || defined(CY_DEVICE_CCG7S) || defined(CY_DEVICE_CCG3PA)) */

/**
 * @brief Retrieve pointer to application parameters from the configuration table.
 *
 * This function retrieves the application parameters that is stored in
 * the configuration table and stores it in the run-time data structures.
 *
 * @param port USB-PD port for which the data is to be retrieved.
 *
 * @return Pointer to application parameters.
 */
app_config_t* pd_get_ptr_app_tbl(cy_stc_usbpd_context_t *context);

/**
 * @brief Retrieve pointer to Base Alt parameters(Discover ID etc) from the configuration table.
 *
 * This function retrieves the Base Alt parameters(Discover ID etc) parameters that is stored in
 * the configuration table and stores it in the run-time data structures.
 *
 * @param port USB-PD port for which the data is to be retrieved.
 *
 * @return Pointer to Base Alt parameters(Discover ID etc) parameters.
 */
cy_stc_pdaltmode_cfg_settings_t* pd_get_ptr_base_alt_tbl(cy_stc_usbpd_context_t *context);

#if (defined(CY_DEVICE_SERIES_WLC1))
const cy_wireless_port_config * get_wireless_port_config(const void *cfgPtr);

const cy_stc_qi_main_cfg_t * get_wireless_main_config(const void *cfgPtr);

const cy_stc_qi_coil_cfg_t * get_wireless_coil_config(const void *cfgPtr, uint8_t coilNum);

const pwr_params_t * get_wireless_regulation_config(const void *cfgPtr, uint8_t coilNum);

const pwr_params_t * get_wireless_invbridge_config(const void *cfgPtr, uint8_t coilNum);

const cy_stc_fod_cfg_t * get_wireless_fod_config(const void *cfgPtr, uint8_t coilNum);

const cy_stc_vin_cfg_t  * get_wireless_vin_config(const void *cfgPtr);

const cy_stc_fault_protect_cfg_t * get_wireless_fault_config(const void *cfgPtr);
#endif /* (defined(CY_DEVICE_SERIES_WLC1))*/

cy_pd_pd_do_t* pd_get_ptr_disc_id(cy_stc_usbpd_context_t *context);

cy_pd_pd_do_t* pd_get_ptr_disc_svid(cy_stc_usbpd_context_t *context);

cy_pd_pd_do_t* pd_get_ptr_disc_mode(cy_stc_usbpd_context_t *context);

cy_stc_pdaltmode_custom_alt_cfg_settings_t* pd_get_ptr_custom_alt_tbl(cy_stc_usbpd_context_t *context);

custom_host_cfg_settings_t* pd_get_ptr_custom_host_tbl(cy_stc_usbpd_context_t *context);

tbthost_cfg_settings_t* pd_get_ptr_tbt_host_tbl(cy_stc_usbpd_context_t *context);

cy_stc_pdaltmode_dp_cfg_settings_t* pd_get_ptr_dp_config_tbl(cy_stc_usbpd_context_t *context);

intel_soc_cfg_settings_t* pd_get_ptr_intel_soc_config_tbl(cy_stc_usbpd_context_t *context);

amd_cfg_settings_t* pd_get_ptr_amd_config_tbl(cy_stc_usbpd_context_t *context);

mtk_cfg_settings_t* pd_get_ptr_mtk_config_tbl(cy_stc_usbpd_context_t *context);

cy_stc_bb_settings_t* pd_get_ptr_bb_tbl(cy_stc_usbpd_context_t *context);

#if defined(CY_DEVICE_CCG7D)
cy_stc_pdaltmode_dp_cfg_settings_t* pd_get_ptr_dp_tbl(cy_stc_usbpd_context_t *context);
#endif /* defined(CY_DEVICE_CCG7D) */

host_config_param_t* pd_get_ptr_host_config_param_tbl(cy_stc_usbpd_context_t *context);

#endif /* CY_USE_CONFIG_TABLE */

/** \endcond */
#endif /* (defined(CY_IP_MXUSBPD) || defined(CY_IP_M0S8USBPD)) */
#endif /* CONFIG_TABLE_H_ */

/* [] END OF FILE */

