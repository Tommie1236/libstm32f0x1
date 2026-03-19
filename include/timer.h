/**
 * @file    timer.h
 * @author  Timo Oosterom
 * @brief   STM32F0x1 HAL: TIMERS
 * @date    mar 20 2026
 * * @copyright Copyright (c) 2026 Timo Oosterom
 * Licensed under the MIT License. See LICENSE file in the project root.
 * * ⚠️ ACADEMIC NOTICE: For portfolio use only. Students at Avans UAS 
 * are prohibited from using this code in graded assignments.
 */

// features
// prescale
// clk source
// clk enable
// capture compare
// 
// 
// 
// input capture
// pwm
// encoder interface


#ifndef TIMER_H
#define TIMER_H

#include "stm32f0_common.h"


typedef struct {
    __IO uint32_t CR1;          // almost done
    __IO uint32_t CR2;
    __IO uint32_t SMCR;
    __IO uint32_t DIER;
    __IO uint32_t SR;           // done
    __IO uint32_t EGR;
    __IO uint32_t CCMR1;
    __IO uint32_t CCMR2;
    __IO uint32_t CCER;
    __IO uint32_t CNT;          // done
    __IO uint32_t PSC;          // done
    __IO uint32_t ARR;          // done
         uint32_t RESERVED;
    __IO uint32_t CCR1;         // done
    __IO uint32_t CCR2;         // done
    __IO uint32_t CCR3;         // done
    __IO uint32_t CCR4;         // done
         uint32_t RESERVED2;
    __IO uint32_t DCR;
    __IO uint32_t DMAR;
} TIMER23_T;

typedef enum {
    TIMER_CH1,
    TIMER_CH2,
    TIMER_CH3,
    TIMER_CH4
} TIMER_CHANNEL;

#define TIMER2        ((TIMER23_T*) 0x40000000)
#define TIMER3        ((TIMER23_T*) 0x40000400)



// TODO: define CMS/CKD modes/presets
#define TIMER23_CR1_CEN_Pos         0
#define TIMER23_CR1_CEN_Msk         (1U << TIMER23_CR1_CEN_Pos)
#define TIMER23_CR1_UDIS_Pos        1
#define TIMER23_CR1_UDIS_Msk        (1U << TIMER23_CR1_UDIS_Pos)
#define TIMER23_CR1_URS_Pos         2
#define TIMER23_CR1_URS_Msk         (1U << TIMER23_CR1_URS_Pos)
#define TIMER23_CR1_OPM_Pos         3
#define TIMER23_CR1_OPM_Msk         (1U << TIMER23_CR1_OPM_Pos)
#define TIMER23_CR1_DIR_Pos         4
#define TIMER23_CR1_DIR_Msk         (1U << TIMER23_CR1_DIR_Pos)
#define TIMER23_CR1_CMS_Pos         5
#define TIMER23_CR1_CMS_Msk         (3U << TIMER23_CR1_CMS_Pos)
#define TIMER23_CR1_ARPE_Pos        7
#define TIMER23_CR1_ARPE_Msk        (1U << TIMER23_CR1_ARPE_Pos)
#define TIMER23_CR1_CKD_Pos         8
#define TIMER23_CR1_CKD_Msk         (3U << TIMER23_CR1_CKD_Pos)

#define TIMER23_SR_UIF_Pos          0
#define TIMER23_SR_UIF_Msk          (1U << TIMER23_SR_UIF_Pos)
#define TIMER23_SR_CC1F_Pos         1
#define TIMER23_SR_CC1F_Msk         (1U << TIMER23_SR_CC1F_Pos)
#define TIMER23_SR_CC2F_Pos         2
#define TIMER23_SR_CC2F_Msk         (1U << TIMER23_SR_CC2F_Pos)
#define TIMER23_SR_CC3F_Pos         3
#define TIMER23_SR_CC3F_Msk         (1U << TIMER23_SR_CC3F_Pos)
#define TIMER23_SR_CC4F_Pos         4
#define TIMER23_SR_CC4F_Msk         (1U << TIMER23_SR_CC4F_Pos)
#define TIMER23_SR_TIF_Pos          6
#define TIMER23_SR_TIF_Msk          (1U << TIMER23_SR_TIF_Pos)
#define TIMER23_SR_CC1OF_Pos        9
#define TIMER23_SR_CC1OF_Msk        (1U << TIMER23_SR_CC1OF_Pos)
#define TIMER23_SR_CC2OF_Pos        10
#define TIMER23_SR_CC2OF_Msk        (1U << TIMER23_SR_CC2OF_Pos)
#define TIMER23_SR_CC3OF_Pos        11
#define TIMER23_SR_CC3OF_Msk        (1U << TIMER23_SR_CC3OF_Pos)
#define TIMER23_SR_CC4OF_Pos        12
#define TIMER23_SR_CC4OF_Msk        (1U << TIMER23_SR_CC4OF_Pos)

#define TIMER23_CNT_LOW_Pos         0
#define TIMER23_CNT_LOW_Msk         (0xFFFF << TIMER23_CNT_LOW_Pos)
#define TIMER23_CNT_HIGH_Pos        16
#define TIMER23_CNT_HIGH_Msk        (0xFFFF << TIMER23_CNT_HIGH_Pos)

#define TIMER23_PSC_VALUE_Pos       0
#define TIMER23_PSC_VALUE_Msk       (0xFFFF << TIMER23_PSC_VALUE_Pos)

#define TIMER23_ARR_LOW_Pos         0
#define TIMER23_ARR_LOW_Msk         (0xFFFF << TIMER23_ARR_LOW_Pos)
#define TIMER23_ARR_HIGH_Pos        16
#define TIMER23_ARR_HIGH_Msk        (0xFFFF << TIMER23_ARR_HIGH_Pos)

#define TIMER23_CCR1_LOW_Pos        0
#define TIMER23_CCR1_LOW_Msk        (0xFFFF << TIMER23_CCR1_LOW_Pos)
#define TIMER23_CCR1_HIGH_Pos       16
#define TIMER23_CCR1_HIGH_Msk       (0xFFFF << TIMER23_CCR1_HIGH_Pos)

#define TIMER23_CCR2_LOW_Pos        0
#define TIMER23_CCR2_LOW_Msk        (0xFFFF << TIMER23_CCR2_LOW_Pos)
#define TIMER23_CCR2_HIGH_Pos       16
#define TIMER23_CCR2_HIGH_Msk       (0xFFFF << TIMER23_CCR2_HIGH_Pos)

#define TIMER23_CCR3_LOW_Pos        0
#define TIMER23_CCR3_LOW_Msk        (0xFFFF << TIMER23_CCR3_LOW_Pos)
#define TIMER23_CCR3_HIGH_Pos       16
#define TIMER23_CCR3_HIGH_Msk       (0xFFFF << TIMER23_CCR3_HIGH_Pos)

#define TIMER23_CCR4_LOW_Pos        0
#define TIMER23_CCR4_LOW_Msk        (0xFFFF << TIMER23_CCR4_LOW_Pos)
#define TIMER23_CCR4_HIGH_Pos       16
#define TIMER23_CCR4_HIGH_Msk       (0xFFFF << TIMER23_CCR4_HIGH_Pos)


void timer23_init(void);
void timer23_start(TIMER23_T *timer);
void timer23_stop(TIMER23_T *timer);
void timer23_reset(TIMER23_T *timer);
void timer23_set_prescaler(TIMER23_T *timer, uint32_t prescaler);
void timer23_set_auto_reload(TIMER23_T *timer, uint32_t value);
uint16_t timer23_get_count(TIMER23_T *timer);
void timer23_set_compare(TIMER23_T *timer, TIMER_CHANNEL channel, uint16_t value);
bool timer23_get_compare_flag(TIMER23_T *timer, TIMER_CHANNEL channel);
void timer23_clear_compare_flag(TIMER23_T *timer, TIMER_CHANNEL channel);

#endif // TIMER_H
