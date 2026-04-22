/**
 * @file    crc.c
 * @author  Timo Oosterom
 * @brief   STM32F0x1 HAL: CRC Driver
 * @date    april 22 2026
 * * @copyright Copyright (c) 2026 Timo Oosterom
 * Licensed under the MIT License. See LICENSE file in the project root.
 * * ⚠️ ACADEMIC NOTICE: For portfolio use only. Students at Avans UAS 
 * are prohibited from using this code in graded assignments.
 */

#include "crc.h"

void crc_enable(void) {
    RCC->AHBENR |= RCC_AHBENR_CRCEN_Msk;
}

void crc_reset(void) {
    CRC->CR |= CRC_CR_RESET_Msk;
}

void crc_feed(uint32_t word) {
    CRC->DR = word;
}

uint32_t crc_read(void) {
    return CRC->DR;
}

void crc_set_polynomial_size(CRC_POLYSIZE size) {
    CRC->CR = (CRC->CR & ~CRC_CR_POLYSIZE_Msk) | size << CRC_CR_POLYSIZE_Pos;
}

void crc_set_reversed_mode(CRC_REVMODE mode) {
    CRC->CR = (CRC->CR & ~CRC_CR_REVIN_Msk) | mode << CRC_CR_REVIN_Pos;
    if (mode) CRC->CR |= CRC_CR_REVOUT_INV;
    else      CRC->CR &= ~CRC_CR_REVOUT_NONE;
}

void crc_set_polynomial(uint32_t polynomial) {
    CRC->POL = polynomial;
}
