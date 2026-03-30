/**
 * @file    tm1637.c
 * @author  Timo Oosterom
 * @brief   STM32F0x1 HAL: TM1637 Driver
 * @date    march 20 2026
 * * @copyright Copyright (c) 2026 Timo Oosterom
 * Licensed under the MIT License. See LICENSE file in the project root.
 * * ⚠️ ACADEMIC NOTICE: For portfolio use only. Students at Avans UAS 
 * are prohibited from using this code in graded assignments.
 */

#include "TM1637.h"
#include "gpio.h"
#include "time.h"

#define BIT_DELAY 10

static GPIOx* SCK_PORT;
static GPIOx* DIO_PORT;
static uint8_t SCK_PIN;
static uint8_t DIO_PIN;
static uint8_t segment_values[4] = {0x00};

const uint8_t SEGMENTS[] = {
    0x3F, // 0
    0x06, // 1
    0x5B, // 2
    0x4F, // 3
    0x66, // 4
    0x6D, // 5
    0x7D, // 6
    0x07, // 7
    0x7F, // 8
    0x6F, // 9
    0x77, // A
    0x7C, // b
    0x39, // C
    0x5E, // d
    0x79, // E
    0x71  // F
};

void bit_delay() {
    delay_us(BIT_DELAY);
}

void tm1637_start_bit(void) {
    gpio_put(DIO_PORT, DIO_PIN, 1);
    gpio_put(SCK_PORT, SCK_PIN, 1);
    bit_delay();
    gpio_put(DIO_PORT, DIO_PIN, 0);
    bit_delay();
    gpio_put(SCK_PORT, SCK_PIN, 0);
    bit_delay();
}

void tm1637_stop_bit(void) {
    gpio_put(DIO_PORT, DIO_PIN, 0);
    gpio_put(SCK_PORT, SCK_PIN, 0);
    bit_delay();
    gpio_put(SCK_PORT, SCK_PIN, 1);
    bit_delay();
    gpio_put(DIO_PORT, DIO_PIN, 1);
    bit_delay();
}

bool tm1637_write_byte(uint8_t byte) {
    for (uint8_t i = 0 ; i < 8; i++) {
        gpio_put(DIO_PORT, DIO_PIN, (byte >> i) & 1U);
        bit_delay();
        gpio_put(SCK_PORT, SCK_PIN, 1);
        bit_delay();
        gpio_put(SCK_PORT, SCK_PIN, 0);
        bit_delay();
    }
        bit_delay();
        gpio_put(SCK_PORT, SCK_PIN, 1);
        bit_delay();
        bool ack = gpio_get(DIO_PORT, DIO_PIN);
        gpio_put(SCK_PORT, SCK_PIN, 0);
        bit_delay();

    //return ack;
    return ack;
}

void tm1637_init(GPIOx* sck_port, uint8_t sck_pin, GPIOx* dio_port, uint8_t dio_pin){
    SCK_PORT = sck_port;
    DIO_PORT = dio_port;
    SCK_PIN = sck_pin;
    DIO_PIN = dio_pin;

    gpio_set_mode(SCK_PORT, SCK_PIN, GPIO_OUTPUT);
    gpio_set_mode(DIO_PORT, DIO_PIN, GPIO_OUTPUT);
    gpio_set_output_type(SCK_PORT, SCK_PIN, GPIO_PUSH_PULL);
    gpio_set_output_type(DIO_PORT, DIO_PIN, GPIO_OPEN_DRAIN);
    gpio_set_pulls(DIO_PORT, DIO_PIN, GPIO_PULLUP);

    tm1637_start_bit();
    tm1637_write_byte(TM1637_COMMAND_MODE_DISPLAY);
    tm1637_stop_bit();
}

void tm1637_set_brightness(uint8_t brightness) {
    tm1637_start_bit();
    tm1637_write_byte(TM1637_COMMAND_CTL_DISPLAY_ON | (brightness % 8));
    tm1637_stop_bit();
}

void tm1637_write_segment(uint8_t segment, uint8_t data) {
    segment_values[segment] = data;
    tm1637_start_bit();
    tm1637_write_byte(TM1637_COMMAND_ADDR | (segment % 4));
    tm1637_write_byte(data);
    tm1637_stop_bit();
}

void tm1637_write_digit(uint8_t position, uint8_t digit) {
    tm1637_write_segment(position, SEGMENTS[digit % 16]);
}

void tm1637_write_display(uint8_t segment0, uint8_t segment1, uint8_t segment2, uint8_t segment3) {
    segment_values[0] = segment0;
    segment_values[1] = segment1;
    segment_values[2] = segment2;
    segment_values[3] = segment3;
    tm1637_start_bit();
    tm1637_write_byte(TM1637_COMMAND_ADDR);
    tm1637_write_byte(segment0);
    tm1637_write_byte(segment1);
    tm1637_write_byte(segment2);
    tm1637_write_byte(segment3);
    tm1637_stop_bit();
}


void tm1637_set_colon(bool enabled) {
    tm1637_start_bit();
    tm1637_write_byte(TM1637_COMMAND_ADDR | 0x01);
    tm1637_write_byte(segment_values[1] | (enabled << 7));
    tm1637_stop_bit();
}

