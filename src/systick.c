/**
 * @file    systick.c
 * @author  Timo Oosterom
 * @brief   STM32F0x1 HAL: SysTick Driver
 * @date    feb 28 2026
 * * @copyright Copyright (c) 2026 Timo Oosterom
 * Licensed under the MIT License. See LICENSE file in the project root.
 * * ⚠️ ACADEMIC NOTICE: For portfolio use only. Students at Avans UAS 
 * are prohibited from using this code in graded assignments.
 */


#include "systick.h"

volatile uint32_t ms_ticks = 0;

static systick_callback_t callback = 0;
static uint32_t callback_interval = 0;
static uint32_t callback_counter = 0;

void SysTick_Handler(void) {
    ms_ticks++;

    if (callback && ++callback_counter >= callback_interval) {
        callback_counter = 0;
        callback();
    }
}

void systick_init(uint32_t reload_value) {
    // TODO: Auto reload value calibration from system clock?

    // set reload value and ensure its 24-bit.
    SYSTICK->RVR = (reload_value & SYSTICK_RVR_RELOAD_Msk);
    // clear current value.
    SYSTICK->CVR = 0;
    // configure CSR
    SYSTICK->CSR = SYSTICK_CSR_CLKSOURCE_Msk | // Clock source AHB (CPU)
                   SYSTICK_CSR_TICKINT_Msk   | // Enable Interrupt
                   SYSTICK_CSR_ENABLE_Msk;     // Enable counter
}

void systick_enable(bool enable){
    SYSTICK->CSR = (SYSTICK->CSR & ~SYSTICK_CSR_ENABLE_Msk) | enable << SYSTICK_CSR_ENABLE_Pos;

}

void systick_interrupt_enable(bool enable) {
    SYSTICK->CSR = (SYSTICK->CSR & ~SYSTICK_CSR_TICKINT_Msk) | (enable << SYSTICK_CSR_TICKINT_Pos);
}

void systick_set_clksource(SYSTICK_CLK_SOURCE source) {
    SYSTICK->CSR = (SYSTICK->CSR & ~SYSTICK_CSR_CLKSOURCE_Msk) | (source << SYSTICK_CSR_CLKSOURCE_Pos);
}

SYSTICK_CLK_SOURCE systick_get_clksource(void) {
    return (SYSTICK_CLK_SOURCE)(SYSTICK->CSR & SYSTICK_CSR_CLKSOURCE_Msk) >> SYSTICK_CSR_CLKSOURCE_Pos;
}

bool systick_get_countflag(void) {
    return (bool)(SYSTICK->CSR & SYSTICK_CSR_COUNTFLAG_Msk) >> SYSTICK_CSR_COUNTFLAG_Pos; 
}

void systick_set_reload_value(uint32_t reload_value) {
    SYSTICK->RVR = (reload_value & SYSTICK_RVR_RELOAD_Msk);
}

uint32_t systick_get_current_value(void) {
    return (SYSTICK->CVR & SYSTICK_CVR_CURRENT_Msk);
}

void systick_set_callback_interval(systick_callback_t cb, uint32_t interval_ms) {
    callback = cb;
    callback_interval = interval_ms;
    callback_counter = 0;
}
