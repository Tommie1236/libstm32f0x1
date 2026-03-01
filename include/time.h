

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
