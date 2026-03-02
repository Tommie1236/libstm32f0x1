/**
 * @file    adc.c
 * @author  Timo Oosterom
 * @brief   STM32F0x1 HAL: ADC Driver
 * @date    feb 28 2026
 * * @copyright Copyright (c) 2026 Timo Oosterom
 * Licensed under the MIT License. See LICENSE file in the project root.
 * * ⚠️ ACADEMIC NOTICE: For portfolio use only. Students at Avans UAS 
 * are prohibited from using this code in graded assignments.
 */

#include "adc.h"
#include "clock.h"

// TODO: most methods should only be called with adc disabled, add guards. 

static bool adc_not_calibrated = 1;

void adc_init(void){
    RCC->APB2ENR |= RCC_APB2ENR_ADCEN_Msk;
    adc_set_clock(ADC_ADCCLK);
    adc_auto_calibrate();
    adc_enable();
}

void adc_enable(void) {
    // Enable sequence from ST RM0091 A.7.2 

    // Calibrate adc if not done already.
    if (adc_not_calibrated) adc_auto_calibrate();

    // Check if ADC is ready and clear ADRDY.
    if ((ADC->ISR & ADC_ISR_ADRDY_Msk) != 0) ADC->ISR |= ADC_ISR_ADRDY_Msk;

    // Enable ADC and wait until ready (ADRDY = 1)
    ADC->CR |= ADC_CR_ADEN_Msk;
    while ((ADC->ISR & ADC_ISR_ADRDY_Msk) == 0);    // TODO: Add timeout?
};

void adc_disable(void) {
    // Disable sequence from ST RM0091 A.7.3

    // Stop conversion if active and wait until stop (ADSTP = 0).
     if (ADC->CR & ADC_CR_ADSTART_Msk) {
        ADC->CR |= ADC_CR_ADSTP_Msk;
        while (ADC->CR & ADC_CR_ADSTP_Msk);         // TODO: Add timeout?
    }  

    // Disable and wait until disabled (ADEN = 0).
    ADC->CR |= ADC_CR_ADDIS_Msk;
    while ((ADC->CR & ADC_CR_ADEN_Msk));            // TODO: Add timeout?

}

bool adc_is_enabled(void) {
    return ADC->CR & ADC_CR_ADEN_Msk;
}

void adc_auto_calibrate(void) {
    // Calibration sequence from ST RM0091 A.7.1 

    // disable adc if enabled.
    if ((ADC->CR & ADC_CR_ADEN_Msk) != 0) ADC->CR |= ADC_CR_ADDIS_Msk;
    // Wait until disabled (enable bit cleared)
    while ((ADC->CR & ADC_CR_ADEN_Msk) != 0);       // TODO: Add timeout?

    // Disable DMA
    ADC->CFGR1 &= ~ADC_CFGR1_DMAEN_Msk;

    // Start calibration and wait for finish (ADDCAL = 0).
    ADC->CR |= ADC_CR_ADCAL_Msk;
    while ((ADC->CR & ADC_CR_ADCAL_Msk) != 0);      // TODO: Add timeout?

    adc_not_calibrated = 0;
}

void adc_set_clock(ADC_CLKSRC clk) {
    ADC->CFGR2 &= ~ADC_CFGR2_CKMODE_Msk;
    ADC->CFGR2 |= clk << ADC_CFGR2_CKMODE_Pos;
}



void adc_set_channel(ADC_CHANNEL channel) {
    ADC->CHSELR = 1 << channel;
    // TODO: wake peripherals for vref, temp and vbat 
    // ADC->CCR
}

void adc_set_resolution(ADC_RESOLUTION resolution){
    ADC->CFGR1 &= ~ADC_CFGR1_RES_Msk;
    ADC->CFGR1 |= resolution << ADC_CFGR1_RES_Pos;
}

void adc_set_sample_time(ADC_SAMPLE_TIME time){
    ADC->SMPR = time;
}

uint16_t adc_read_single(ADC_CHANNEL channel){
    adc_disable();
    adc_set_channel(channel);
    adc_set_sample_time(ADC_SMPT_293);
    adc_enable();
    
    ADC->CR |= ADC_CR_ADSTART_Msk;
    // wait for conversion.
    while ((ADC->ISR & ADC_ISR_EOC_Msk) == 0);      // TODO: Add timeout?
    
    return ADC->DR & ADC_DR_DATA_Msk;
}
