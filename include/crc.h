/**
 * @file    crc.h
 * @author  Timo Oosterom
 * @brief   STM32F0x1 HAL: CRC Driver
 * @date    april 22 2026
 * * @copyright Copyright (c) 2026 Timo Oosterom
 * Licensed under the MIT License. See LICENSE file in the project root.
 * * ⚠️ ACADEMIC NOTICE: For portfolio use only. Students at Avans UAS 
 * are prohibited from using this code in graded assignments.
 */


#ifndef CRC_H
#define CRC_H

#include "stm32f0_common.h"

typedef struct {
    __IO uint32_t DR;
    __IO uint32_t IDR;
    __IO uint32_t CR;
    __IO uint32_t INIT;
    __IO uint32_t POL;
} CRC_T;

typedef enum {
    CRC_POLYSIZE_32BIT,
    CRC_POLYSIZE_16BIT,
    CRC_POLYSIZE_8BIT,
    CRC_POLYSIZE_7BIT
} CRC_POLYSIZE;

typedef enum {
    CRC_REVMODE_NONE,
    CRC_REVMODE_BYTE,
    CRC_REVMODE_LONG,
    CRC_REVMODE_WORD
} CRC_REVMODE;

#define CRC ((CRC_T *)0x48023000)

#define CRC_IDR_Pos             0
#define CRC_IDR_Msk             (0xFF << CRC_IDR_Pos)
#define CRC_CR_RESET_Pos        0
#define CRC_CR_RESET_Msk        (1U << CRC_CR_RESET_Pos)
#define CRC_CR_POLYSIZE_Pos     3
#define CRC_CR_POLYSIZE_Msk     (1U << CRC_CR_POLYSIZE_Pos)
#define CRC_CR_POLYS_32BIT      (0x0 << CRC_CR_POLYSIZE_Pos)
#define CRC_CR_POLYS_16BIT      (0x1 << CRC_CR_POLYSIZE_Pos)
#define CRC_CR_POLYS_8BIT       (0x2 << CRC_CR_POLYSIZE_Pos)
#define CRC_CR_POLYS_7BIT       (0x3 << CRC_CR_POLYSIZE_Pos)
#define CRC_CR_REVIN_Pos        5
#define CRC_CR_REVIN_Msk        (0x3 << CRC_CR_REVIN_Pos)
#define CRC_CR_REVIN_NONE       (0x0 << CRC_CR_REVIN_Pos)
#define CRC_CR_REVIN_BYTE       (0x1 << CRC_CR_REVIN_Pos)
#define CRC_CR_REVIN_LONG       (0x2 << CRC_CR_REVIN_Pos)
#define CRC_CR_REVIN_WORD       (0x3 << CRC_CR_REVIN_Pos)
#define CRC_CR_REVOUT_Pos       7
#define CRC_CR_REVOUT_Msk       (1U << CRC_CR_REVOUT_Pos)
#define CRC_CR_REVOUT_NONE      (0U << CRC_CR_REVOUT_Pos)
#define CRC_CR_REVOUT_INV       (1U << CRC_CR_REVOUT_Pos)

void crc_reset(void);

void crc_feed(uint32_t word);

uint32_t crc_read(void);

void crc_set_polynomial_size(CRC_POLYSIZE size);

void crc_set_reversed_mode(CRC_REVMODE mode);

void crc_set_polynomial(uint32_t polynomial);

#endif // CRC_H
