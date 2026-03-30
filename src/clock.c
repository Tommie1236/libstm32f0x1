/**
 * @file    clock.c
 * @author  Timo Oosterom
 * @brief   STM32F0x1 HAL: RCC Driver
 * @date    feb 28 2026
 * * @copyright Copyright (c) 2026 Timo Oosterom
 * Licensed under the MIT License. See LICENSE file in the project root.
 * * ⚠️ ACADEMIC NOTICE: For portfolio use only. Students at Avans UAS 
 * are prohibited from using this code in graded assignments.
 */


#include "clock.h"
#include "flash.h"

void clock_init(void) {
    // set clock to HSE (bypass)
    RCC->CR |= RCC_CR_HSEBYP_Msk | 
               RCC_CR_HSEON_Msk;

    // wait for HSE to be stable
    while (!(RCC->CR & RCC_CR_HSERDY_Msk));

    // configure pll and wait for stable. enable:ON, src: HSE, mul:6 
    RCC->CFGR |= RCC_CRGR_PLLSRC_HSE | RCC_CRGR_PLLMUL_6;
    RCC->CR |= RCC_CR_PLLON_Msk;
    while (!(RCC->CR & RCC_CR_PLLRDY_Msk));

    // set flash wait state to 1 as its not fast enough for a SYSCLK > 24MHz.
    FLASH->ACR |= FLASH_ACR_LATENCY_1;

    // set clk src to PLL and wat for switch
    RCC->CFGR |= RCC_CFGR_SW_PLL;
    while ((RCC->CFGR & RCC_CFGR_SWS_Msk) != RCC_CFGR_SWS_PLL);

    // enable gpio clk's
    RCC->AHBENR |= RCC_AHBENR_IOPAEN_Msk |
                   RCC_AHBENR_IOPBEN_Msk |
                   RCC_AHBENR_IOPCEN_Msk |
                   RCC_AHBENR_IOPDEN_Msk |
                   RCC_AHBENR_IOPEEN_Msk |
                   RCC_AHBENR_IOPFEN_Msk;

    RCC->APB2ENR |= RCC_APB2ENR_SYSCFGCOMPEN_Msk;
}


