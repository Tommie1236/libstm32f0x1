/**
 * @file    flash.h
 * @author  Timo Oosterom
 * @brief   STM32F0x1 HAL: FLASH Driver
 * @date    feb 28 2026
 * * @copyright Copyright (c) 2026 Timo Oosterom
 * Licensed under the MIT License. See LICENSE file in the project root.
 * * ⚠️ ACADEMIC NOTICE: For portfolio use only. Students at Avans UAS 
 * are prohibited from using this code in graded assignments.
 */


#ifndef FLASH_H
#define FLASH_H

#include "stm32f0_common.h"

typedef struct {
    __IO uint32_t ACR;      // done
    __O  uint32_t KEYR;
    __O  uint32_t OPTKEYR;
    __IO uint32_t SR;
    __IO uint32_t CR;
    __O  uint32_t AR;
    __I  uint32_t OBR;
    __IO uint32_t WRPR;
} FLASH_T;

#define FLASH ((FLASH_T *)0x40022000)

#define FLASH_ACR_PRFTBS_Pos        5
#define FLASH_ACR_PRFTBS_Msk        (1U << FLASH_ACR_PRFTBS_Pos)
#define FLASH_ACR_PRFTBE_Pos        4
#define FLASH_ACR_PRFTBE_Msk        (1U << FLASH_ACR_PRFTBE_Pos)

#define FLASH_ACR_LATENCY_Pos       0
#define FLASH_ACR_LATENCY_Msk       (0x3 << FLASH_ACR_LATENCY_Pos)
#define FLASH_ACR_LATENCY_0         (0x0 << FLASH_ACR_LATENCY_Pos)
#define FLASH_ACR_LATENCY_1         (0x1 << FLASH_ACR_LATENCY_Pos)






#endif // FLASH_H
