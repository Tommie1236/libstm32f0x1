/**
 * @file    gpio.h
 * @author  Timo Oosterom
 * @brief   STM32F0x1 HAL: GPIO Driver
 * @date    feb 28 2026
 * * @copyright Copyright (c) 2026 Timo Oosterom
 * Licensed under the MIT License. See LICENSE file in the project root.
 * * ⚠️ ACADEMIC NOTICE: For portfolio use only. Students at Avans UAS 
 * are prohibited from using this code in graded assignments.
 */


#ifndef GPIO_H
#define GPIO_H

#include "stm32f0_common.h"
#include <stdbool.h>

typedef struct {
    // TODO: all still need bit definitionsi
    __IO uint32_t MODER;    // done
    __IO uint32_t OTYPER;   // done
    __IO uint32_t OSPEEDR;
    __IO uint32_t PUPDR;    // done
    __I  uint32_t IDR;      // done
    __IO uint32_t ODR;      // done
    __O  uint32_t BSRR;     // done
    __IO uint32_t LCKR;
    __IO uint32_t AFR[2];   // done   alternate function low/high
    __O  uint32_t BRR;      // done
} GPIOx;

typedef enum {
    GPIO_INPUT      = 0x00,
    GPIO_OUTPUT     = 0x01,
    GPIO_ALTERNATE  = 0x02,
    GPIO_ANALOG     = 0x03
} GPIO_MODE;

typedef enum {
    GPIO_PUSH_PULL  = 0x00,
    GPIO_OPEN_DRAIN = 0x01
} GPIO_OUTPUT_TYPE;

typedef enum {
    GPIO_NO_PULL    = 0x00,
    GPIO_PULLUP     = 0x01,
    GPIO_PULLDOWN   = 0x10
} GPIO_PULLS;

typedef enum {
    GPIO_AF0,
    GPIO_AF1,
    GPIO_AF2,
    GPIO_AF3,
    GPIO_AF4,
    GPIO_AF5,
    GPIO_AF6,
    GPIO_AF7
} GPIO_ALTERNATE_FUNCTION;

#define GPIOA ((GPIOx *)0x48000000)
#define PORTA GPIOA
#define GPIOB ((GPIOx *)0x48000400)
#define PORTB GPIOB
#define GPIOC ((GPIOx *)0x48000800)
#define PORTC GPIOC
#define GPIOD ((GPIOx *)0x48000c00)
#define PORTD GPIOD
#define GPIOE ((GPIOx *)0x48001000)
#define PORTE GPIOE
#define GPIOF ((GPIOx *)0x48001400)
#define PORTF GPIOF


// TODO: Bit definitions/masks


void gpio_set_mode(GPIOx *port,
                   uint8_t gpio,
                   GPIO_MODE mode);

void gpio_set_output_type(GPIOx *port,
                          uint8_t gpio,
                          GPIO_OUTPUT_TYPE type);

// speed control

void gpio_set_pulls(GPIOx *port,
                    uint8_t gpio,
                    GPIO_PULLS pulls);

bool gpio_get(GPIOx *port,
              uint8_t gpio);

void gpio_put(GPIOx *port,
              uint8_t gpio,
              bool value);

void gpio_set_atomic(GPIOx *port,
              uint8_t gpio);

void gpio_reset_atomic(GPIOx *port,
              uint8_t gpio);

void gpio_set_alternate_mode(GPIOx *port,
                             uint8_t gpio,
                             GPIO_ALTERNATE_FUNCTION af);

#endif // GPI H
