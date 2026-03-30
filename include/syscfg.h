/**
 * @file    syscfg.h
 * @author  Timo Oosterom
 * @brief   STM32F0x1 HAL: SYSCFG Driver
 * @date    mar 03 2026
 * * @copyright Copyright (c) 2026 Timo Oosterom
 * Licensed under the MIT License. See LICENSE file in the project root.
 * * ⚠️ ACADEMIC NOTICE: For portfolio use only. Students at Avans UAS 
 * are prohibited from using this code in graded assignments.
 */

#ifndef SYSCFG_H
#define SYSCFG_H

#include "stm32f0_common.h"
#include "clock.h"

// #include "gpio.h"
typedef struct GPIOx_s GPIOx;


typedef struct {
    __IO uint32_t CFGR1;        // done (for f091, skipped all unavailable functions)
         uint32_t RESERVED;
    __IO uint32_t EXTICR[4];
    /*__IO uint32_t EXTICR1;      // done
    __IO uint32_t EXTICR2;      // done
    __IO uint32_t EXTICR3;      // done
    __IO uint32_t EXTICR4;      // done */
    __IO uint32_t CFGR2;        // done
} SYSCFG_T;

typedef struct {
    __IO uint32_t IMR;
    __IO uint32_t EMR;
    __IO uint32_t RTSR;
    __IO uint32_t FTSR;
    __IO uint32_t SWIER;
    __IO uint32_t PR;
} EXTI_T;

// TODO: shared interrupt registers (RM0091 table 27).


typedef enum {
    SYSCFG_EXTI_PORTA,
    SYSCFG_EXTI_PORTB,
    SYSCFG_EXTI_PORTC,
    SYSCFG_EXTI_PORTD,
    SYSCFG_EXTI_PORTE,
    SYSCFG_EXTI_PORTF
} SYSCFG_EXTI_PORT;

typedef enum {
    EXTI_GPIO_0,
    EXTI_GPIO_1,
    EXTI_GPIO_2,
    EXTI_GPIO_3,
    EXTI_GPIO_4,
    EXTI_GPIO_5,
    EXTI_GPIO_6,
    EXTI_GPIO_7,
    EXTI_GPIO_8,
    EXTI_GPIO_9,
    EXTI_GPIO_10,
    EXTI_GPIO_11,
    EXTI_GPIO_12,
    EXTI_GPIO_13,
    EXTI_GPIO_14,
    EXTI_GPIO_15,

} SYSCFG_EXTI;

typedef void (*exti_callback_t)(void);


#define SYSCFG  ((SYSCFG_T*)0x40010000)
#define EXTI    ((EXTI_T*)  0x40010400)


#define SYSCFG_CFGR1_MEM_MODE_Pos           0
#define SYSCFG_CFGR1_MEM_MODE_Msk           (0x3 << SYSCFG_CFGR1_MEM_MODE_Pos)
#define SYSCFG_CFGR1_MEM_MODE_MFLASH_Msk    (0x0 << SYSCFG_CFGR1_MEM_MODE_Pos)
#define SYSCFG_CFGR1_MEM_MODE_SFLASH_Msk    (0x1 << SYSCFG_CFGR1_MEM_MODE_Pos)
#define SYSCFG_CFGR1_MEM_MODE_SRAM          (0x3 << SYSCFG_CFGR1_MEM_MODE_Pos)
#define SYSCFG_CFGR1_IR_MOD_Pos             6
#define SYSCFG_CFGR1_IR_MOD_Msk             (0x3 << SYSCFG_CFGR1_IR_MOD_Pos)
#define SYSCFG_CFGR1_IR_MOD_TIM16_Msk       (0x0 << SYSCFG_CFGR1_IR_MOD_Pos)
#define SYSCFG_CFGR1_IR_MOD_USART1_Msk      (0x1 << SYSCFG_CFGR1_IR_MOD_Pos)
#define SYSCFG_CFGR1_IR_MOD_USART4_Msk      (0x2 << SYSCFG_CFGR1_IR_MOD_Pos)
#define SYSCFG_CFGR1_I2C_PB6_FMP_Pos        16
#define SYSCFG_CFGR1_I2C_PB6_FMP_Msk        (1U << SYSCFG_CFGR1_I2C_PB6_FMP_Pos)
#define SYSCFG_CFGR1_I2C_PB7_FMP_Pos        17
#define SYSCFG_CFGR1_I2C_PB7_FMP_Msk        (1U << SYSCFG_CFGR1_I2C_PB7_FMP_Pos)
#define SYSCFG_CFGR1_I2C_PB8_FMP_Pos        18
#define SYSCFG_CFGR1_I2C_PB8_FMP_Msk        (1U << SYSCFG_CFGR1_I2C_PB8_FMP_Pos)
#define SYSCFG_CFGR1_I2C_PB9_FMP_Pos        19
#define SYSCFG_CFGR1_I2C_PB9_FMP_Msk        (1U << SYSCFG_CFGR1_I2C_PB9_FMP_Pos)
#define SYSCFG_CFGR1_I2C1_FMP_Pos           20
#define SYSCFG_CFGR1_I2C1_FMP_Msk           (1U << SYSCFG_CFGR1_I2C1_FMP_Pos)
#define SYSCFG_CFGR1_I2C2_FMP_Pos           21
#define SYSCFG_CFGR1_I2C2_FMP_Msk           (1U << SYSCFG_CFGR1_I2C2_FMP_Pos)
#define SYSCFG_CFGR1_I2C_PA9_FMP_Pos        22
#define SYSCFG_CFGR1_I2C_PA9_FMP_Msk        (1U << SYSCFG_CFGR1_I2C_PA9_FMP_Pos)
#define SYSCFG_CFGR1_I2C_PA10_FMP_Pos       23
#define SYSCFG_CFGR1_I2C_PA10_FMP_Msk       (1U << SYSCFG_CFGR1_I2C_PA10_FMP_Pos)


#define SYSCFG_EXTICRx_EXTI_0_Pos     0
#define SYSCFG_EXTICRx_EXTI_0_Msk     (0xF << SYSCFG_EXTICRx_EXTI_0_Pos)
#define SYSCFG_EXTICRx_EXTI_1_Pos     4
#define SYSCFG_EXTICRx_EXTI_1_Msk     (0xF << SYSCFG_EXTICRx_EXTI_1_Pos)
#define SYSCFG_EXTICRx_EXTI_2_Pos     8
#define SYSCFG_EXTICRx_EXTI_2_Msk     (0xF << SYSCFG_EXTICRx_EXTI_2_Pos)
#define SYSCFG_EXTICRx_EXTI_3_Pos     12
#define SYSCFG_EXTICRx_EXTI_3_Msk     (0xF << SYSCFG_EXTICRx_EXTI_3_Pos)

/*
#define SYSCFG_EXTICR1_EXTI_0_Pos    0
#define SYSCFG_EXTICR1_EXTI_0_Msk    (0xF << SYSCFG_EXTICR1_EXTI_0_Pos)
#define SYSCFG_EXTICR1_EXTI_1_Pos    4
#define SYSCFG_EXTICR1_EXTI_1_Msk    (0xF << SYSCFG_EXTICR1_EXTI_1_Pos)
#define SYSCFG_EXTICR1_EXTI_2_Pos    8
#define SYSCFG_EXTICR1_EXTI_2_Msk    (0xF << SYSCFG_EXTICR1_EXTI_2_Pos)
#define SYSCFG_EXTICR1_EXTI_3_Pos    12
#define SYSCFG_EXTICR1_EXTI_3_Msk    (0xF << SYSCFG_EXTICR1_EXTI_3_Pos)

#define SYSCFG_EXTICR2_EXTI_4_Pos    0
#define SYSCFG_EXTICR2_EXTI_4_Msk    (0xF << SYSCFG_EXTICR2_EXTI_4_Pos)
#define SYSCFG_EXTICR2_EXTI_5_Pos    4
#define SYSCFG_EXTICR2_EXTI_5_Msk    (0xF << SYSCFG_EXTICR2_EXTI_5_Pos)
#define SYSCFG_EXTICR2_EXTI_6_Pos    8
#define SYSCFG_EXTICR2_EXTI_6_Msk    (0xF << SYSCFG_EXTICR2_EXTI_6_Pos)
#define SYSCFG_EXTICR2_EXTI_7_Pos    12
#define SYSCFG_EXTICR2_EXTI_7_Msk    (0xF << SYSCFG_EXTICR2_EXTI_7_Pos)

#define SYSCFG_EXTICR3_EXTI_8_Pos    0
#define SYSCFG_EXTICR3_EXTI_8_Msk    (0xF << SYSCFG_EXTICR3_EXTI_8_Pos)
#define SYSCFG_EXTICR3_EXTI_9_Pos    4
#define SYSCFG_EXTICR3_EXTI_9_Msk    (0xF << SYSCFG_EXTICR3_EXTI_9_Pos)
#define SYSCFG_EXTICR3_EXTI_10_Pos   8
#define SYSCFG_EXTICR3_EXTI_10_Msk   (0xF << SYSCFG_EXTICR3_EXTI_10_Pos)
#define SYSCFG_EXTICR3_EXTI_11_Pos   12
#define SYSCFG_EXTICR3_EXTI_11_Msk   (0xF << SYSCFG_EXTICR3_EXTI_11_Pos)

#define SYSCFG_EXTICR4_EXTI_12_Pos   0
#define SYSCFG_EXTICR4_EXTI_12_Msk   (0xF << SYSCFG_EXTICR4_EXTI_12_Pos)
#define SYSCFG_EXTICR4_EXTI_13_Pos   4
#define SYSCFG_EXTICR4_EXTI_13_Msk   (0xF << SYSCFG_EXTICR4_EXTI_13_Pos)
#define SYSCFG_EXTICR4_EXTI_14_Pos   8
#define SYSCFG_EXTICR4_EXTI_14_Msk   (0xF << SYSCFG_EXTICR4_EXTI_14_Pos)
#define SYSCFG_EXTICR4_EXTI_15_Pos   12
#define SYSCFG_EXTICR4_EXTI_15_Msk   (0xF << SYSCFG_EXTICR4_EXTI_15_Pos)
*/

#define SYSCFG_CRGR2_LOCKUP_Pos             0
#define SYSCFG_CRGR2_LOCKUP_Msk             (1U << SYSCFG_CRGR2_LOCKUP_Pos)
#define SYSCFG_CRGR2_SRAM_PARITY_LOCK_Pos   1
#define SYSCFG_CRGR2_SRAM_PARITY_LOCK_Msk   (1U << SYSCFG_CRGR2_SRAM_PARITY_LOCK_Pos)
#define SYSCFG_CRGR2_PVD_LOCK_Pos           2
#define SYSCFG_CRGR2_PVD_LOCK_Msk           (1U << SYSCFG_CRGR2_PVD_LOCK_Pos)
#define SYSCFG_CRGR2_SRAM_PEF_Pos           8
#define SYSCFG_CRGR2_SRAM_PEF_Msk           (1U << SYSCFG_CRGR2_SRAM_PEF_Pos)



// Methods

void exti_init(void);
void exti_configure(uint8_t line, bool rising, bool falling);
void exti_map(SYSCFG_EXTI_PORT port, uint8_t pin);
void exti_enable(uint8_t line);
void exti_disable(uint8_t line);
void exti_set_sw_irq(uint8_t line);
void exti_clear_pending(uint8_t line);
bool exti_get_pending(uint8_t line);
void exti_set_callback(uint8_t line, exti_callback_t cb);

// TODO: Exti events.

#endif // SYSCFG_H
