/**
 * @file    clock.h
 * @author  Timo Oosterom
 * @brief   STM32F0x1 HAL: RCC Driver
 * @date    feb 28 2026
 * * @copyright Copyright (c) 2026 Timo Oosterom
 * Licensed under the MIT License. See LICENSE file in the project root.
 * * ⚠️ ACADEMIC NOTICE: For portfolio use only. Students at Avans UAS 
 * are prohibited from using this code in graded assignments.
 */


#ifndef CLOCKS_H
#define CLOCKS_H

#include "stm32f0_common.h"

typedef struct {
    __IO uint32_t CR;       // done
    __IO uint32_t CFGR;     // done
    __IO uint32_t CIR;
    __IO uint32_t APB2RSTR; // done
    __IO uint32_t APB1RSTR;
    __IO uint32_t AHBENR;   // done
    __IO uint32_t APB2ENR;  // done
    __IO uint32_t APB1ENR;
    __IO uint32_t BDCR;
    __IO uint32_t CSR;
    __IO uint32_t AHBRSTR;
    __IO uint32_t CFGR2;
    __IO uint32_t CFGR3;
    __IO uint32_t CR2;
} RCC_T;

#define RCC ((RCC_T *)0x40021000)

// bitfields / masks
#define RCC_CR_HSION_Pos            0
#define RCC_CR_HSION_Msk            (1U << RCC_CR_HSION_Pos)
#define RCC_CR_HSIRDY_Pos           1
#define RCC_CR_HSIRDY_Msk           (1U << RCC_CR_HSIRDY_Pos)
#define RCC_CR_HSITRIM_Pos          3
#define RCC_CR_HSITRIM_Msk          (0xF << RCC_CR_HSITRIM_Pos)
#define RCC_CR_HSICAL_Pos           8
#define RCC_CR_HSICAL_Msk           (0xFF << RCC_CR_HSICAL_Pos)

#define RCC_CR_HSEON_Pos            16
#define RCC_CR_HSEON_Msk            (1U << RCC_CR_HSEON_Pos)
#define RCC_CR_HSERDY_Pos           17
#define RCC_CR_HSERDY_Msk           (1U << RCC_CR_HSERDY_Pos)
#define RCC_CR_HSEBYP_Pos           18
#define RCC_CR_HSEBYP_Msk           (1U << RCC_CR_HSEBYP_Pos)
#define RCC_CR_CSSON_Pos            19
#define RCC_CR_CSSON_Msk            (1U << RCC_CR_CSSON_Pos)
#define RCC_CR_PLLON_Pos            24
#define RCC_CR_PLLON_Msk            (1U << RCC_CR_PLLON_Pos)
#define RCC_CR_PLLRDY_Pos           25
#define RCC_CR_PLLRDY_Msk           (1U << RCC_CR_PLLRDY_Pos)

#define RCC_CFGR_SW_Pos             0
#define RCC_CFGR_SW_Msk             (0x3 << RCC_CFGR_SW_Pos)
#define RCC_CFGR_SW_HSI             (0x0 << RCC_CFGR_SW_Pos)
#define RCC_CFGR_SW_HSE             (0x1 << RCC_CFGR_SW_Pos)
#define RCC_CFGR_SW_PLL             (0x2 << RCC_CFGR_SW_Pos)
#define RCC_CFGR_SW_HSI48           (0x3 << RCC_CFGR_SW_Pos)

#define RCC_CFGR_SWS_Pos            2
#define RCC_CFGR_SWS_Msk            (0x3 << RCC_CFGR_SWS_Pos)
#define RCC_CFGR_SWS_HSI            (0x0 << RCC_CFGR_SWS_Pos)
#define RCC_CFGR_SWS_HSE            (0x1 << RCC_CFGR_SWS_Pos)
#define RCC_CFGR_SWS_PLL            (0x2 << RCC_CFGR_SWS_Pos)
#define RCC_CFGR_SWS_HSI48          (0x3 << RCC_CFGR_SWS_Pos)

#define RCC_CRGR_HPRE_Pos           4
#define RCC_CRGR_HPRE_Msk           (0xF << RCC_CRGR_HPRE_Pos)
#define RCC_CRGR_HPRE_DIV_0         (0x0 << RCC_CRGR_HPRE_Pos)
#define RCC_CRGR_HPRE_DIV_2         (0x8 << RCC_CRGR_HPRE_Pos)
#define RCC_CRGR_HPRE_DIV_4         (0x9 << RCC_CRGR_HPRE_Pos)
#define RCC_CRGR_HPRE_DIV_8         (0xA << RCC_CRGR_HPRE_Pos)
#define RCC_CRGR_HPRE_DIV_16        (0xB << RCC_CRGR_HPRE_Pos)
#define RCC_CRGR_HPRE_DIV_64        (0xC << RCC_CRGR_HPRE_Pos)
#define RCC_CRGR_HPRE_DIV_128       (0xD << RCC_CRGR_HPRE_Pos)
#define RCC_CRGR_HPRE_DIV_256       (0xE << RCC_CRGR_HPRE_Pos)
#define RCC_CRGR_HPRE_DIV_512       (0xF << RCC_CRGR_HPRE_Pos)

#define RCC_CRGR_PPRE_Pos           8
#define RCC_CRGR_PPRE_Msk           (0x7 << RCC_CRGR_PPRE_Pos)
#define RCC_CRGR_PPRE_DIV_0         (0x0 << RCC_CRGR_PPRE_Pos)
#define RCC_CRGR_PPRE_DIV_2         (0x4 << RCC_CRGR_PPRE_Pos)
#define RCC_CRGR_PPRE_DIV_4         (0x5 << RCC_CRGR_PPRE_Pos)
#define RCC_CRGR_PPRE_DIV_8         (0x6 << RCC_CRGR_PPRE_Pos)
#define RCC_CRGR_PPRE_DIV_16        (0x7 << RCC_CRGR_PPRE_Pos)

#define RCC_CRGR_PLLSRC_Pos         15
#define RCC_CRGR_PLLSRC_Msk         (0x3 << RCC_CRGR_PLLSRC_Pos)
#define RCC_CRGR_PLLSRC_HSI_DIV_2   (0x0 << RCC_CRGR_PLLSRC_Pos)        
#define RCC_CRGR_PLLSRC_HSI         (0x1 << RCC_CRGR_PLLSRC_Pos)
#define RCC_CRGR_PLLSRC_HSE         (0x2 << RCC_CRGR_PLLSRC_Pos)
#define RCC_CRGR_PLLSRC_HSI48       (0x3 << RCC_CRGR_PLLSRC_Pos)

#define RCC_CRGR_PLLXTPRE_Pos       17
#define RCC_CRGR_PLLXTPRE_Msk       (1U << RCC_CRGR_PLLXTPRE_Pos)

#define RCC_CRGR_PLLMUL_Pos         18
#define RCC_CRGR_PLLMUL_Msk         (0xF << RCC_CRGR_PLLMUL_Pos)
#define RCC_CRGR_PLLMUL_2           (0x0 << RCC_CRGR_PLLMUL_Pos)
#define RCC_CRGR_PLLMUL_3           (0x1 << RCC_CRGR_PLLMUL_Pos)
#define RCC_CRGR_PLLMUL_4           (0x2 << RCC_CRGR_PLLMUL_Pos)
#define RCC_CRGR_PLLMUL_5           (0x3 << RCC_CRGR_PLLMUL_Pos)
#define RCC_CRGR_PLLMUL_6           (0x4 << RCC_CRGR_PLLMUL_Pos)
#define RCC_CRGR_PLLMUL_7           (0x5 << RCC_CRGR_PLLMUL_Pos)
#define RCC_CRGR_PLLMUL_8           (0x6 << RCC_CRGR_PLLMUL_Pos)
#define RCC_CRGR_PLLMUL_9           (0x7 << RCC_CRGR_PLLMUL_Pos)
#define RCC_CRGR_PLLMUL_10          (0x8 << RCC_CRGR_PLLMUL_Pos)
#define RCC_CRGR_PLLMUL_11          (0x9 << RCC_CRGR_PLLMUL_Pos)
#define RCC_CRGR_PLLMUL_12          (0xA << RCC_CRGR_PLLMUL_Pos)
#define RCC_CRGR_PLLMUL_13          (0xB << RCC_CRGR_PLLMUL_Pos)
#define RCC_CRGR_PLLMUL_14          (0xC << RCC_CRGR_PLLMUL_Pos)
#define RCC_CRGR_PLLMUL_15          (0xD << RCC_CRGR_PLLMUL_Pos)
// #define RCC_CRGR_PLLMUL_16          (0xE << RCC_CRGR_PLLMUL_Pos)
#define RCC_CRGR_PLLMUL_16          (0xF << RCC_CRGR_PLLMUL_Pos)

#define RCC_CRGR_MCO_Pos            24
#define RCC_CRGR_MCO_Msk            (0xF << RCC_CRGR_MCO_Pos)
#define RCC_CRGR_MCO_DIS            (0x0 << RCC_CRGR_MCO_Pos)
#define RCC_CRGR_MCO_HSI14          (0x1 << RCC_CRGR_MCO_Pos)
#define RCC_CRGR_MCO_LSI            (0x2 << RCC_CRGR_MCO_Pos)
#define RCC_CRGR_MCO_LSE            (0x3 << RCC_CRGR_MCO_Pos)
#define RCC_CRGR_MCO_SYSCLK         (0x4 << RCC_CRGR_MCO_Pos)
#define RCC_CRGR_MCO_HSI            (0x5 << RCC_CRGR_MCO_Pos)
#define RCC_CRGR_MCO_HSE            (0x6 << RCC_CRGR_MCO_Pos)
#define RCC_CRGR_MCO_PLL            (0x7 << RCC_CRGR_MCO_Pos)
#define RCC_CRGR_MCO_HSI48          (0x8 << RCC_CRGR_MCO_Pos)

#define RCC_CRGR_MCOPRE_Pos         28
#define RCC_CRGR_MCOPRE_Msk         (0x7 << RCC_CRGR_MCOPRE_Pos)
#define RCC_CRGR_MCOPRE_DIV_1       (0x0 << RCC_CRGR_MCOPRE_Pos)
#define RCC_CRGR_MCOPRE_DIV_2       (0x1 << RCC_CRGR_MCOPRE_Pos)
#define RCC_CRGR_MCOPRE_DIV_4       (0x2 << RCC_CRGR_MCOPRE_Pos)
#define RCC_CRGR_MCOPRE_DIV_8       (0x3 << RCC_CRGR_MCOPRE_Pos)
#define RCC_CRGR_MCOPRE_DIV_16      (0x4 << RCC_CRGR_MCOPRE_Pos)
#define RCC_CRGR_MCOPRE_DIV_32      (0x5 << RCC_CRGR_MCOPRE_Pos)
#define RCC_CRGR_MCOPRE_DIV_64      (0x6 << RCC_CRGR_MCOPRE_Pos)
#define RCC_CRGR_MCOPRE_DIV_128     (0x7 << RCC_CRGR_MCOPRE_Pos)

#define RCC_CRGR_PLLNODIV_Pos       31
#define RCC_CRGR_PLLNODIV_Msk       (1U << RCC_CRGR_PLLNODIV_Pos)

// TODO: CIR

#define RCC_APB2RSTR_SYSCFGRST_Pos  0
#define RCC_APB2RSTR_SYSCFGRST_Msk  (1U << RCC_APB2RSTR_SYSCFGRST_Pos)
#define RCC_APB2RSTR_USART6RST_Pos  5
#define RCC_APB2RSTR_USART6RST_Msk  (1U << RCC_APB2RSTR_USART6RST_Pos)
#define RCC_APB2RSTR_USART7RST_Pos  6
#define RCC_APB2RSTR_USART7RST_Msk  (1U << RCC_APB2RSTR_USART7RST_Pos)
#define RCC_APB2RSTR_USART8RST_Pos  7
#define RCC_APB2RSTR_USART8RST_Msk  (1U << RCC_APB2RSTR_USART8RST_Pos)
#define RCC_APB2RSTR_ADCRST_Pos     9
#define RCC_APB2RSTR_ADCRST_Msk     (1U << RCC_APB2RSTR_ADCRST_Pos)
#define RCC_APB2RSTR_TIM1RST_Pos    11
#define RCC_APB2RSTR_TIM1RST_Msk    (1U << RCC_APB2RSTR_TIM1RST_Pos)
#define RCC_APB2RSTR_SPI1RST_Pos    12
#define RCC_APB2RSTR_SPI1RST_Msk    (1U << RCC_APB2RSTR_SPI1RST_Pos)
#define RCC_APB2RSTR_USART1RST_Pos  14
#define RCC_APB2RSTR_USART1RST_Msk  (1U << RCC_APB2RSTR_USART1RST_Pos)
#define RCC_APB2RSTR_TIM15RST_Pos   16
#define RCC_APB2RSTR_TIM15RST_Msk   (1U << RCC_APB2RSTR_TIM15RST_Pos)
#define RCC_APB2RSTR_TIM16RST_Pos   17
#define RCC_APB2RSTR_TIM16RST_Msk   (1U << RCC_APB2RSTR_TIM16RST_Pos)
#define RCC_APB2RSTR_TIM17RST_Pos   18
#define RCC_APB2RSTR_TIM17RST_Msk   (1U << RCC_APB2RSTR_TIM17RST_Pos)
#define RCC_APB2RSTR_DBGMCURST_Pos  22 
#define RCC_APB2RSTR_DBGMCURST_Msk  (1U << RCC_APB2RSTR_DBGMCURST_Pos)

// TODO: APB1RSTR

#define RCC_AHBENR_DMAEN_Pos        0
#define RCC_AHBENR_DMAEN_Msk        (1U << RCC_AHBENR_DMAEN_Pos)        
#define RCC_AHBENR_DMA2EN_Pos       1
#define RCC_AHBENR_DMA2EN_Msk       (1U << RCC_AHBENR_DMA2EN_Pos)       
#define RCC_AHBENR_SRAMEN_Pos       2
#define RCC_AHBENR_SRAMEN_Msk       (1U << RCC_AHBENR_SRAMEN_Pos)       
#define RCC_AHBENR_FLITFEN_Pos      4
#define RCC_AHBENR_FLITFE_Msk       (1U << RCC_AHBENR_FLITFEN_Pos)      
#define RCC_AHBENR_CRCEN_Pos        6
#define RCC_AHBENR_CRCEN_Msk        (1U << RCC_AHBENR_CRCEN_Pos)        
#define RCC_AHBENR_IOPAEN_Pos       17
#define RCC_AHBENR_IOPAEN_Msk       (1U << RCC_AHBENR_IOPAEN_Pos)       
#define RCC_AHBENR_IOPBEN_Pos       18
#define RCC_AHBENR_IOPBEN_Msk       (1U << RCC_AHBENR_IOPBEN_Pos)       
#define RCC_AHBENR_IOPCEN_Pos       19
#define RCC_AHBENR_IOPCEN_Msk       (1U << RCC_AHBENR_IOPCEN_Pos)       
#define RCC_AHBENR_IOPDEN_Pos       20
#define RCC_AHBENR_IOPDEN_Msk       (1U << RCC_AHBENR_IOPDEN_Pos)       
#define RCC_AHBENR_IOPEEN_Pos       21
#define RCC_AHBENR_IOPEEN_Msk       (1U << RCC_AHBENR_IOPEEN_Pos)       
#define RCC_AHBENR_IOPFEN_Pos       22
#define RCC_AHBENR_IOPFEN_Msk       (1U << RCC_AHBENR_IOPFEN_Pos)       
#define RCC_AHBENR_TSCEN_Pos        24
#define RCC_AHBENR_TSCEN_Msk        (1U << RCC_AHBENR_TSCEN_Pos)

#define RCC_APB2ENR_SYSCFGCOMPEN_Pos    0
#define RCC_APB2ENR_SYSCFGCOMPEN_Msk    (1U << RCC_APB2ENR_SYSCFGCOMPEN_Pos)
#define RCC_APB2ENR_USART6EN_Pos    5
#define RCC_APB2ENR_USART6EN_Msk    (1U << RCC_APB2ENR_USART6EN_Pos)
#define RCC_APB2ENR_USART7EN_Pos    6
#define RCC_APB2ENR_USART7EN_Msk    (1U << RCC_APB2ENR_USART7EN_Pos)
#define RCC_APB2ENR_USART8EN_Pos    7
#define RCC_APB2ENR_USART8EN_Msk    (1U << RCC_APB2ENR_USART8EN_Pos)
#define RCC_APB2ENR_ADCEN_Pos       9
#define RCC_APB2ENR_ADCEN_Msk       (1U << RCC_APB2ENR_ADCEN_Pos)
#define RCC_APB2ENR_TIM1EN_Pos      11
#define RCC_APB2ENR_TIM1EN_Msk      (1U << RCC_APB2ENR_TIM1EN_Pos)
#define RCC_APB2ENR_SPI1EN_Pos      12
#define RCC_APB2ENR_SPI1EN_Msk      (1U << RCC_APB2ENR_SPI1EN_Pos)
#define RCC_APB2ENR_USART1EN_Pos    14
#define RCC_APB2ENR_USART1EN_Msk    (1U << RCC_APB2ENR_USART1EN_Pos)
#define RCC_APB2ENR_TIM15_Pos       16
#define RCC_APB2ENR_TIM15_Msk       (1U << RCC_APB2ENR_TIM15_Pos)
#define RCC_APB2ENR_TIM16_Pos       17
#define RCC_APB2ENR_TIM16_Msk       (1U << RCC_APB2ENR_TIM16_Pos)
#define RCC_APB2ENR_TIM17_Pos       18
#define RCC_APB2ENR_TIM17_Msk       (1U << RCC_APB2ENR_TIM17_Pos)
#define RCC_APB2ENR_DBGMCUEN_Pos    22
#define RCC_APB2ENR_DBGMCUEN_Msk    (1U << RCC_APB2ENR_DBGMCUEN_Pos)

#define RCC_APB1ENR_TIM2EN_Pos      0
#define RCC_APB1ENR_TIM2EN_Msk      (1U << RCC_APB1ENR_TIM2EN_Pos)
#define RCC_APB1ENR_TIM3EN_Pos      1
#define RCC_APB1ENR_TIM3EN_Msk      (1U << RCC_APB1ENR_TIM3EN_Pos)
#define RCC_APB1ENR_TIM6EN_Pos      4
#define RCC_APB1ENR_TIM6EN_Msk      (1U << RCC_APB1ENR_TIM6EN_Pos)
#define RCC_APB1ENR_TIM7EN_Pos      5
#define RCC_APB1ENR_TIM7EN_Msk      (1U << RCC_APB1ENR_TIM7EN_Pos)
#define RCC_APB1ENR_TIM14EN_Pos     8
#define RCC_APB1ENR_TIM14EN_Msk     (1U << RCC_APB1ENR_TIM14EN_Pos)
#define RCC_APB1ENR_WWDGEN_Pos      11
#define RCC_APB1ENR_WWDGEN_Msk      (1U << RCC_APB1ENR_WWDGEN_Pos)
#define RCC_APB1ENR_SPI2EN_Pos      14
#define RCC_APB1ENR_SPI2EN_Msk      (1U << RCC_APB1ENR_SPI2EN_Pos)
#define RCC_APB1ENR_USART2EN_Pos    17
#define RCC_APB1ENR_USART2EN_Msk    (1U << RCC_APB1ENR_USART2EN_Pos)
#define RCC_APB1ENR_USART3EN_Pos    18
#define RCC_APB1ENR_USART3EN_Msk    (1U << RCC_APB1ENR_USART3EN_Pos)
#define RCC_APB1ENR_USART4EN_Pos    19
#define RCC_APB1ENR_USART4EN_Msk    (1U << RCC_APB1ENR_USART4EN_Pos)
#define RCC_APB1ENR_USART5EN_Pos    20
#define RCC_APB1ENR_USART5EN_Msk    (1U << RCC_APB1ENR_USART5EN_Pos)
#define RCC_APB1ENR_I2C1EN_Pos      21
#define RCC_APB1ENR_I2C1EN_Msk      (1U << RCC_APB1ENR_I2C1EN_Pos)
#define RCC_APB1ENR_I2C2EN_Pos      22
#define RCC_APB1ENR_I2C2EN_Msk      (1U << RCC_APB1ENR_I2C2EN_Pos)
#define RCC_APB1ENR_USBEN_Pos       23
#define RCC_APB1ENR_USBEN_Msk       (1U << RCC_APB1ENR_USBEN_Pos)
#define RCC_APB1ENR_CRSEN_Pos       27
#define RCC_APB1ENR_CRSEN_Msk       (1U << RCC_APB1ENR_CRSEN_Pos)
#define RCC_APB1ENR_PWREN_Pos       28
#define RCC_APB1ENR_PWREN_Msk       (1U << RCC_APB1ENR_PWREN_Pos)
#define RCC_APB1ENR_DACEN_Pos       29
#define RCC_APB1ENR_DACEN_Msk       (1U << RCC_APB1ENR_DACEN_Pos)
#define RCC_APB1ENR_CECEN_Pos       30
#define RCC_APB1ENR_CECEN_Msk       (1U << RCC_APB1ENR_CECEN_Pos)



// Methods

void clock_init(void);

#endif // CLOCKS_H
