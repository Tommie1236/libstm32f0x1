
#ifndef GPIO_H
#define GPIO_H

#include "stm32f0_common.h"
#include <stdbool.h>

typedef struct {
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

typedef enum{
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
#define GPIOB ((GPIOx *)0x48000400)
#define GPIOC ((GPIOx *)0x48000800)
#define GPIOD ((GPIOx *)0x48000c00)
#define GPIOE ((GPIOx *)0x48001000)
#define GPIOF ((GPIOx *)0x48001400)

/*
#define GPIO_0  (1U << 0x0)
#define GPIO_1  (1U << 0x02)
#define GPIO_2  (1U << 0x04)
#define GPIO_3  (1U << 0x06)
#define GPIO_4  (1U << 0x08)
#define GPIO_5  (1U << 0x0A)
#define GPIO_6  (1U << 0x0C)
#define GPIO_7  (1U << 0x0E)
#define GPIO_8  (1U << 0x10)
#define GPIO_9  (1U << 0x12)
#define GPIO_10 (1U << 0x14)
#define GPIO_11 (1U << 0x16)
#define GPIO_12 (1U << 0x18)
#define GPIO_13 (1U << 0x1A)
#define GPIO_14 (1U << 0x1C)
#define GPIO_15 (1U << 0x1E)
*/

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
