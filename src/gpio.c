/**
 * @file    gpio.c
 * @author  Timo Oosterom
 * @brief   STM32F0x1 HAL: GPIO Driver
 * @date    feb 28 2026
 * * @copyright Copyright (c) 2026 Timo Oosterom
 * Licensed under the MIT License. See LICENSE file in the project root.
 * * ⚠️ ACADEMIC NOTICE: For portfolio use only. Students at Avans UAS 
 * are prohibited from using this code in graded assignments.
 */


#include "gpio.h"

// TODO: masked operations


void gpio_set_mode(GPIOx *port,
                   uint8_t gpio,
                   GPIO_MODE mode) {

    port->MODER &= ~(3U << (gpio * 2));
    port->MODER |= mode << (gpio * 2);
}

void gpio_set_output_type(GPIOx *port,
                          uint8_t gpio,
                          GPIO_OUTPUT_TYPE type) {

    port->OTYPER &= ~(1U << gpio);
    port->OTYPER |= type << gpio;
}

void gpio_set_pulls(GPIOx *port,
                    uint8_t gpio,
                    GPIO_PULLS pulls) {

    port->PUPDR &= ~(3U << (gpio * 2));
    port->PUPDR |= pulls << (gpio * 2);
}

bool gpio_get(GPIOx *port, uint8_t gpio) {

    return (bool)((port->IDR >> gpio) & 1U);
}


void gpio_put(GPIOx *port,
              uint8_t gpio,
              bool value) {

    port->ODR &= ~(1U << gpio);
    port->ODR |= (value << gpio);
}

void gpio_set_atomic(GPIOx *port, uint8_t gpio) {
    port->BSRR = (1U << gpio);
}

void gpio_reset_atomic(GPIOx *port, uint8_t gpio) {
    // port->BSRR |= (1U << (gpio + 16)); // oid way using the BSSR register
    // more efficient to use the BRR register as it doesn't need 16 offset shifts
    port->BRR = (1U << gpio);
}

void gpio_set_alternate_mode(GPIOx *port,
                             uint8_t gpio,
                             GPIO_ALTERNATE_FUNCTION af) {
    
    // switch pin to alternate mode automaticly
    gpio_set_mode(port, gpio, GPIO_ALTERNATE);

    uint8_t reg_idx = (gpio < 8) ? 0 : 1;
    uint8_t gpio_offset = (gpio % 8) * 4;

    port->AFR[reg_idx] &= ~(0xF << gpio_offset);
    port->AFR[reg_idx] |= af << gpio_offset;
}

void gpio_attach_interrupt(GPIOx *port,
                           uint8_t gpio,
                           exti_callback_t cb) {

    SYSCFG_EXTI_PORT exti_port;

    if      (port == GPIOA) exti_port = SYSCFG_EXTI_PORTA;
    else if (port == GPIOB) exti_port = SYSCFG_EXTI_PORTB;
    else if (port == GPIOC) exti_port = SYSCFG_EXTI_PORTC;
    else if (port == GPIOD) exti_port = SYSCFG_EXTI_PORTD;
    else if (port == GPIOE) exti_port = SYSCFG_EXTI_PORTE;
    else if (port == GPIOF) exti_port = SYSCFG_EXTI_PORTF;
    else return;

    uint8_t irq;
    if (gpio < 2) irq = 5;
    else if (gpio < 4) irq = 6;
    else if (gpio < 16) irq = 7;
    else return;

    exti_set_callback(gpio, cb);
    exti_configure(gpio, 1, 1);     // enable both edges by default
    exti_map(exti_port, gpio);
    exti_enable(gpio);

    nvic_enable_irq(irq);
}
