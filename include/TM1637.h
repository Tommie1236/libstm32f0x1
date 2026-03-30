/**
 * @file    tm1637.h
 * @author  Timo Oosterom
 * @brief   STM32F0x1 HAL: TM1637 Driver
 * @date    march 20 2026
 * * @copyright Copyright (c) 2026 Timo Oosterom
 * Licensed under the MIT License. See LICENSE file in the project root.
 * * ⚠️ ACADEMIC NOTICE: For portfolio use only. Students at Avans UAS 
 * are prohibited from using this code in graded assignments.
 */


#ifndef TM1637_H
#define TM1637_H

#include "gpio.h"



#define TM1637_COMMAND_MODE_DISPLAY         0x40
#define TM1637_COMMAND_MODE_KEYPAD          0x42
#define TM1637_COMMAND_CTL_DISPLAY_ON       0x88
#define TM1637_COMMAND_CTL_DISPLAY_OFF      0x80
#define TM1637_COMMAND_CTL_BRIGHTNESS_Msk   0x07
#define TM1637_COMMAND_ADDR                 0xC0
#define TM1637_COMMAND_ADDR_DISP_Msk        0x07


extern const uint8_t SEGMENTS[];


void tm1637_start_bit(void);
void tm1637_stop_bit(void);
bool tm1637_write_byte(uint8_t byte);

void tm1637_init(GPIOx* sck_port, uint8_t sck_pin, GPIOx* dio_port, uint8_t dio_pin);
void tm1637_set_brightness(uint8_t brightness);
void tm1637_write_segment(uint8_t position, uint8_t data);
void tm1637_write_digit(uint8_t position, uint8_t digit);
void tm1637_write_display(uint8_t segment0, uint8_t segment1, uint8_t segment2, uint8_t segment3);
void tm1637_set_colon(bool enabled);

#endif // TM1637_H
