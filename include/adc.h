
#ifndef ADC_H
#define ADC_H

#include "stm32f0_common.h"
#include <stdbool.h>


typedef struct {
    __IO uint32_t ISR;
    __IO uint32_t IER;
    __IO uint32_t CR;
    __IO uint32_t CFGR[2];
    __IO uint32_t SMPR;
    __IO uint32_t TR;
    __IO uint32_t CHSELR;
    __IO uint32_t DR;
    __IO uint32_t CCR;

} ADC_T;

#define ADC (ADC_T)(0x40012400)


// ADC_ISR
#define ADC_ISR_ADRDY_Pos           0
#define ADC_ISR_EOSMP_Pos           1
#define ADC_ISR_EOC_Pos             2
#define ADC_ISR_EOS_Pos             3
#define ADC_ISR_OVR_Pos             4
#define ADC_ISR_AWD_Pos             7

#define ADC_ISR_ADRDY_Msk           (1U << ADC_ISR_ADRDY_Pos)
#define ADC_ISR_EOSMP_Msk           (1U << ADC_ISR_EOSMP_Pos)
#define ADC_ISR_EOC_Msk             (1U << ADC_ISR_EOC_Pos) 
#define ADC_ISR_EOS_Msk             (1U << ADC_ISR_EOS_Pos)
#define ADC_ISR_OVR_Msk             (1U << ADC_ISR_OVR_Pos)
#define ADC_ISR_AWD_Msk             (1U << ADC_ISR_AWD_Pos)

// ADC_IER


#endif // ADC_H
