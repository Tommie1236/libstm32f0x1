/**
 * @file    spi.c
 * @author  Timo Oosterom
 * @brief   STM32F0x1 HAL: TIMERS
 * @date    march 20 2026
 * * @copyright Copyright (c) 2026 Timo Oosterom
 * Licensed under the MIT License. See LICENSE file in the project root.
 * * ⚠️ ACADEMIC NOTICE: For portfolio use only. Students at Avans UAS 
 * are prohibited from using this code in graded assignments.
 */

#include "timer.h"
#include "clock.h"



void timer23_init(void) {
    RCC->APB1ENR |= RCC_APB1ENR_TIM2EN_Msk | RCC_APB1ENR_TIM3EN_Msk;
}

void timer23_start(TIMER23_T *timer){
    timer->CR1 |= TIMER23_CR1_CEN_Msk;
}

void timer23_stop(TIMER23_T *timer){
    timer->CR1 &= ~TIMER23_CR1_CEN_Msk;
}

void timer23_reset(TIMER23_T *timer){
    timer->CNT = 0;
}

void timer23_set_prescaler(TIMER23_T *timer, uint32_t prescaler) {
    timer->PSC = prescaler;    
}

void timer23_set_auto_reload(TIMER23_T *timer, uint32_t value) {
    timer->ARR = value;
}

uint16_t timer23_get_count(TIMER23_T *timer) {
    return timer->CNT;
}

void timer23_set_compare(TIMER23_T *timer, TIMER_CHANNEL channel, uint16_t value) {
    (&timer->CCR1)[channel] = value;
}

bool timer23_get_compare_flag(TIMER23_T *timer, TIMER_CHANNEL channel) {
    return (timer->SR >> (TIMER23_SR_CC1F_Pos + channel)) &1U;
}

void timer23_clear_compare_flag(TIMER23_T *timer, TIMER_CHANNEL channel) {
    timer->SR &= ~(1U << (TIMER23_SR_CC1F_Pos + channel));
}

