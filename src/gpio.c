
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

    return (bool)(port->IDR >> gpio) & 1U;
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


