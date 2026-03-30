/**
 * @file    nvic.c
 * @author  Timo Oosterom
 * @brief   STM32F0x1 HAL: NVIC Driver
 * @date    feb 28 2026
 * * @copyright Copyright (c) 2026 Timo Oosterom
 * Licensed under the MIT License. See LICENSE file in the project root.
 * * ⚠️ ACADEMIC NOTICE: For portfolio use only. Students at Avans UAS 
 * are prohibited from using this code in graded assignments.
 */

#include "nvic.h"

void nvic_enable_irq(uint8_t irq) {
    NVIC->ISER |= 1 << irq;
}

void nvic_disable_irq(uint8_t irq){
    NVIC->ICER |= 1 << irq;
}

void nvic_set_priority(uint8_t irq, uint8_t priority) {
    volatile uint8_t *reg = (volatile uint8_t*)&NVIC->IPR[0] + irq;
    *reg = priority;
}

void nvic_set_pending(uint8_t irq) {
    NVIC->ISPR |= 1 << irq;
}

void nvic_clear_pending(uint8_t irq) {
    NVIC->ICPR |= 1 << irq;
}
