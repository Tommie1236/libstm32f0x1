/**
 * @file    time.h
 * @author  Timo Oosterom
 * @brief   STM32F0x1 HAL: Time/Clock Driver
 * @date    feb 28 2026
 * * @copyright Copyright (c) 2026 Timo Oosterom
 * Licensed under the MIT License. See LICENSE file in the project root.
 * * ⚠️ ACADEMIC NOTICE: For portfolio use only. Students at Avans UAS 
 * are prohibited from using this code in graded assignments.
 */


#ifndef TIME_H
#define TIME_H

#include "stm32f0_common.h"
#include "systick.h"

void time_init(void);

uint32_t millis(void);

// uint64_t micros(void);  // TODO: add micros() maybe?

void delay_ms(uint32_t ms);

void delay_us(uint32_t us);

void millis_reset_time(void);

// TODO:
// time reached?
// time elapsed?

#endif // TIME_H
