/*
 * $ Copyright Cypress Semiconductor Apache2 $
 */

#ifndef INCLUDED_WHD_TRXHDR_H_
#define INCLUDED_WHD_TRXHDR_H_

#ifdef __cplusplus
extern "C" {
#endif

#ifdef TRXV5

#else
/* Bootloader makes special use of trx header "offsets" array */
enum
{
    TRX_V4_OFFS_SIGN_INFO_IDX                   = 0,
    TRX_V4_OFFS_DATA_FOR_SIGN1_IDX              = 1,
    TRX_V4_OFFS_DATA_FOR_SIGN2_IDX              = 2,
    TRX_V4_OFFS_ROOT_MODULUS_IDX                = 3,
    TRX_V4_OFFS_ROOT_EXPONENT_IDX               = 67,
    TRX_V4_OFFS_CONT_MODULUS_IDX                = 68,
    TRX_V4_OFFS_CONT_EXPONENT_IDX               = 132,
    TRX_V4_OFFS_HASH_FW_IDX                     = 133,
    TRX_V4_OFFS_FW_LEN_IDX                      = 149,
    TRX_V4_OFFS_TR_RST_IDX                      = 150,
    TRX_V4_OFFS_FW_VER_FOR_ANTIROOLBACK_IDX     = 151,
    TRX_V4_OFFS_IV_IDX                          = 152,
    TRX_V4_OFFS_NONCE_IDX                       = 160,
    TRX_V4_OFFS_SIGN_INFO2_IDX                  = 168,
    TRX_V4_OFFS_MAX_IDX
};
#endif
/******************************************************
*			TRX header Constants
******************************************************/

#define TRX_MAGIC       0x30524448  /* "HDR0" */

#ifdef TRXV5
#define TRX_VERSION   5           /* Version trxv5 */
#else
#define TRX_VERSION   4           /* Version trxv4 */
#define TRX_MAX_OFFSET  TRX_V4_OFFS_MAX_IDX         /* Max number of file offsets for trxv4 */
#endif
/******************************************************
*			Structures
******************************************************/
#ifdef TRXV5
typedef struct
{
    uint32_t magic;                     /* "HDR0" */
    uint32_t len;                       /* Length of file including header */
    uint32_t crc32;                     /* CRC from flag_version to end of file */
    uint32_t flag_version;              /* 0:15 flags, 16:31 version */
    uint32_t offsets[4];                /* Offsets of partitions */
} trx_header_t;
#else
typedef struct
{
    uint32_t magic;                     /* "HDR0" */
    uint32_t len;                       /* Length of file including header */
    uint32_t crc32;                     /* CRC from flag_version to end of file */
    uint32_t flag_version;              /* 0:15 flags, 16:31 version */
    uint32_t offsets[TRX_MAX_OFFSET];   /* Offsets of partitions */
} trx_header_t;
#endif

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* ifndef INCLUDED_WHD_TRXHDR_H_ */

