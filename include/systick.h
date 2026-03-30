/**
 * @file    systick.h
 * @author  Timo Oosterom
 * @brief   STM32F0x1 HAL: SysTick Driver
 * @date    feb 28 2026
 * * @copyright Copyright (c) 2026 Timo Oosterom
 * Licensed under the MIT License. See LICENSE file in the project root.
 * * ⚠️ ACADEMIC NOTICE: For portfolio use only. Students at Avans UAS 
 * are prohibited from using this code in graded assignments.
 */


#ifndef SYSTICK_H
#define SYSTICK_H

#include "stm32f0_common.h"
#include <stdbool.h>

typedef struct {
    __IO uint32_t CSR;
    __IO uint32_t RVR;
    __IO uint32_t CVR;
    __IO uint32_t CALIB;
} SYSTICK_T;

typedef enum {
    SYSTICK_CLK_EXTERNAL,
    SYSTICK_CLK_CPU
} SYSTICK_CLK_SOURCE;

typedef void (*systick_callback_t)(void);

extern volatile uint32_t ms_ticks;

#define SYSTICK ((SYSTICK_T *)0xE000E010)

#define SYSTICK_CSR_ENABLE_Pos      0
#define SYSTICK_CSR_TICKINT_Pos     1
#define SYSTICK_CSR_CLKSOURCE_Pos   2
#define SYSTICK_CSR_COUNTFLAG_Pos   16

#define SYSTICK_CSR_ENABLE_Msk      (1U << SYSTICK_CSR_ENABLE_Pos)
#define SYSTICK_CSR_TICKINT_Msk     (1U << SYSTICK_CSR_TICKINT_Pos)
#define SYSTICK_CSR_CLKSOURCE_Msk   (1U << SYSTICK_CSR_CLKSOURCE_Pos)
#define SYSTICK_CSR_COUNTFLAG_Msk   (1U << SYSTICK_CSR_COUNTFLAG_Pos)

#define SYSTICK_RVR_RELOAD_Msk      0x00FFFFFF

#define SYSTICK_CVR_CURRENT_Msk     0x00FFFFFF

#define SYSTICK_CALIB_SKEW_Msk      (1U << 30U)
#define SYSTICK_CALIB_NOREF_Msk     (1U << 32U)
#define SYSTICK_CALIB_VALUE_Msk     0x00FFFFFF

void systick_init(uint32_t reload_value);

void systick_enable(bool enable);

void systick_interrupt_enable(bool enable);

void systick_set_clksource(SYSTICK_CLK_SOURCE source);

SYSTICK_CLK_SOURCE systick_get_clksource(void);

bool systick_get_countflag(void);

void systick_set_reload_value(uint32_t reload_value);

uint32_t systick_get_current_value(void);

void systick_set_callback_interval(systick_callback_t cb, uint32_t interval_ms);

// TODO: calibration value methods
// NOREF
// SKEW
// TENMS

#endif // SYSTICK_H
