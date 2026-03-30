/**
 * @file    nvic.h
 * @author  Timo Oosterom
 * @brief   STM32F0x1 HAL: NVIC Driver
 * @date    March 2 2026
 * * @copyright Copyright (c) 2026 Timo Oosterom
 * Licensed under the MIT License. See LICENSE file in the project root.
 * * ⚠️ ACADEMIC NOTICE: For portfolio use only. Students at Avans UAS 
 * are prohibited from using this code in graded assignments.
 */

#ifndef NVIC_H
#define NVIC_H

#include "stm32f0_common.h"

typedef struct {
    __IO uint32_t ISER;
         uint32_t RESERVED[31];
    __IO uint32_t ICER;
         uint32_t RESERVED2[31];
    __IO uint32_t ISPR;
         uint32_t RESERVED3[31];
    __IO uint32_t ICPR;
         uint32_t RESERVED4[95];
    __IO uint32_t IPR[8];

} NVIC_T;

#define NVIC ((NVIC_T *)0xE000E100)

// TODO: irq definitions

// TODO: Bit definitions



void nvic_enable_irq(uint8_t irq);
void nvic_disable_irq(uint8_t irq);
void nvic_set_priority(uint8_t irq, uint8_t priority);
void nvic_set_pending(uint8_t irq);
void nvic_clear_pending(uint8_t irq);

#endif // NVIC_H
