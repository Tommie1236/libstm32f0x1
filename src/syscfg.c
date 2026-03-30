/**
 * @file    syscfg.c
 * @author  Timo Oosterom
 * @brief   STM32F0x1 HAL: SYSCFG Driver
 * @date    mar 03 2026
 * * @copyright Copyright (c) 2026 Timo Oosterom
 * Licensed under the MIT License. See LICENSE file in the project root.
 * * ⚠️ ACADEMIC NOTICE: For portfolio use only. Students at Avans UAS 
 * are prohibited from using this code in graded assignments.
 */

#include "syscfg.h"

static exti_callback_t exti_callbacks[16] = {0};

void exti_configure(uint8_t line, bool rising, bool falling) {
    EXTI->RTSR |= rising  << line;
    EXTI->FTSR |= falling << line;
}

void exti_map(SYSCFG_EXTI_PORT port, uint8_t pin) {
    uint8_t reg = pin / 4;          // what EXTICR
    uint8_t shift = (pin % 4) * 4;  // what 4 bit field
    SYSCFG->EXTICR[reg] &= ~(0xF << shift);
    SYSCFG->EXTICR[reg] |= (port << shift);
}

void exti_enable(uint8_t line) {
    EXTI->IMR |= 1 << line;
}

void exti_disable(uint8_t line) {
    EXTI->IMR &= ~(1 << line);
}

void exti_set_sw_irq(uint8_t line) {
    EXTI->SWIER |= 1 << line;
}

void exti_clear_pending(uint8_t line) {
    EXTI->PR |= 1 << line;
}

bool exti_get_pending(uint8_t line) {
    return (EXTI->PR >> line) & 1U;
}

void exti_set_callback(uint8_t line, exti_callback_t cb) {
    exti_callbacks[line] = cb;
}

void EXTI4_15_IRQHandler(void) {
    for (uint8_t i = 4; i <= 15; i++) {
        if (exti_get_pending(i) && exti_callbacks[i]) {
            exti_clear_pending(i);
            exti_callbacks[i]();
        }
    }
}

void EXTI0_1_IRQHandler(void) {
    for (uint8_t i = 0; i <= 1; i++) {
        if (exti_get_pending(i) && exti_callbacks[i]) {
            exti_clear_pending(i);
            exti_callbacks[i]();
        }
    }
}

void EXTI2_3_IRQHandler(void) {
    for (uint8_t i = 2; i <= 3; i++) {
        if (exti_get_pending(i) && exti_callbacks[i]) {
            exti_clear_pending(i);
            exti_callbacks[i]();
        }
    }
}
