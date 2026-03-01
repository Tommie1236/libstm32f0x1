/**
 * @file    adc.h
 * @author  Timo Oosterom
 * @brief   STM32F0x1 HAL: ADC Driver
 * @date    feb 28 2026
 * * @copyright Copyright (c) 2026 Timo Oosterom
 * Licensed under the MIT License. See LICENSE file in the project root.
 * * ⚠️ ACADEMIC NOTICE: For portfolio use only. Students at Avans UAS 
 * are prohibited from using this code in graded assignments.
 */


#ifndef ADC_H
#define ADC_H

#include "stm32f0_common.h"
#include "stdbool.h"

typedef struct {
    __IO uint32_t ISR;          // done
    __IO uint32_t IER;          // done
    __IO uint32_t CR;           // done
    __IO uint32_t CFGR1;        // done
    __IO uint32_t CFGR2;        // done
    __IO uint32_t SMPR;         // done
    __IO uint32_t TR;           // done
    __IO uint32_t CHSELR;       // done
         uint16_t RESERVED[5];
    __IO uint32_t DR;           // done
    __IO uint32_t CCR;          // done

} ADC_T;

typedef struct {
    __IO uint32_t CCR;
} ADC_COMMON_T;

typedef enum {
    ADC_12_BIT,
    ADC_10_BIT,
    ADC_8_BIT,
    ADC_6_BIT
} ADC_RESOLUTION;

typedef enum {
    ADC_CH_0,
    ADC_CH_1,
    ADC_CH_2,
    ADC_CH_3, 
    ADC_CH_4,
    ADC_CH_5,
    ADC_CH_6,
    ADC_CH_7,
    ADC_CH_8,
    ADC_CH_9,
    ADC_CH_10,
    ADC_CH_11,
    ADC_CH_12,
    ADC_CH_13,
    ADC_CH_14,
    ADC_CH_15,
    ADC_CH_TEMP,
    ADC_CH_VREF,
    ADC_CH_VBAT
} ADC_CHANNEL;

typedef enum {
    ADC_ADCCLK,
    ADC_PCLK2,
    ADC_PCLK4
} ADC_CLKSRC;

typedef enum {
    ADC_SMPT_1,
    ADC_SMPT_7,
    ADC_SMPT_13,
    ADC_SMPT_28,
    ADC_SMPT_41,
    ADC_SMPT_55,
    ADC_SMPT_71,
    ADC_SMPT_293
} ADC_SAMPLE_TIME;


#define ADC                         ((ADC_T *)0x40012400)
#define ADC_COMMON                  ((ADC_COMMON_T *)0x40012708)


#define ADC_ISR_ADRDY_Pos           0
#define ADC_ISR_ADRDY_Msk           (1U << ADC_ISR_ADRDY_Pos)
#define ADC_ISR_EOSMP_Pos           1
#define ADC_ISR_EOSMP_Msk           (1U << ADC_ISR_EOSMP_Pos)
#define ADC_ISR_EOC_Pos             2
#define ADC_ISR_EOC_Msk             (1U << ADC_ISR_EOC_Pos) 
#define ADC_ISR_EOS_Pos             3
#define ADC_ISR_EOS_Msk             (1U << ADC_ISR_EOS_Pos)
#define ADC_ISR_OVR_Pos             4
#define ADC_ISR_OVR_Msk             (1U << ADC_ISR_OVR_Pos)
#define ADC_ISR_AWD_Pos             7
#define ADC_ISR_AWD_Msk             (1U << ADC_ISR_AWD_Pos)

#define ADC_IER_ADCRYIE_Pos         0
#define ADC_IER_ADCRYIE_Msk         (1U << ADC_IER_ADCRYIE_Pos)
#define ADC_IER_EOSMPIE_Pos         1
#define ADC_IER_EOSMPIE_Msk         (1U << ADC_IER_EOSMPIE_Pos)
#define ADC_IER_EOCIE_Pos           2
#define ADC_IER_EOCIE_Msk           (1U << ADC_IER_EOCIE_Pos)
#define ADC_IER_EOSIE_Pos           3
#define ADC_IER_EOSIE_Msk           (1U << ADC_IER_EOSIE_Pos)
#define ADC_IER_OVRIE_Pos           4
#define ADC_IER_OVRIE_Msk           (1U << ADC_IER_OVRIE_Pos)
#define ADC_IER_AWDIE_Pos           7
#define ADC_IER_AWDIE_Msk           (1U << ADC_IER_AWDIE_Pos)

#define ADC_CR_ADEN_Pos             0
#define ADC_CR_ADEN_Msk             (1U << ADC_CR_ADEN_Pos)
#define ADC_CR_ADDIS_Pos            1
#define ADC_CR_ADDIS_Msk            (1U << ADC_CR_ADDIS_Pos)
#define ADC_CR_ADSTART_Pos          2
#define ADC_CR_ADSTART_Msk          (1U << ADC_CR_ADSTART_Pos)
#define ADC_CR_ADSTP_Pos            4
#define ADC_CR_ADSTP_Msk            (1U << ADC_CR_ADSTP_Pos)
#define ADC_CR_ADCAL_Pos            31
#define ADC_CR_ADCAL_Msk            (1U << ADC_CR_ADCAL_Pos)

#define ADC_CFGR1_DMAEN_Pos         0
#define ADC_CFGR1_DMAEN_Msk         (1U << ADC_CFGR1_DMAEN_Pos)
#define ADC_CFGR1_DMACFG_Pos        1
#define ADC_CFGR1_DMACFG_Msk        (1U << ADC_CFGR1_DMACFG_Pos)
#define ADC_CFGR1_SCANDIR_Pos       2
#define ADC_CFGR1_SCANDIR_Msk       (1U << ADC_CFGR1_SCANDIR_Pos)
#define ADC_CFGR1_RES_Pos           3
#define ADC_CFGR1_RES_Msk           (0x3 << ADC_CFGR1_RES_Pos)
#define ADC_CFGR1_RES_12BIT         (0x0 << ADC_CFGR1_RES_Pos)
#define ADC_CFGR1_RES_10BIT         (0x1 << ADC_CFGR1_RES_Pos)
#define ADC_CFGR1_RES_8BIT          (0x2 << ADC_CFGR1_RES_Pos)
#define ADC_CFGR1_RES_6BIT          (0x3 << ADC_CFGR1_RES_Pos)
#define ADC_CFGR1_ALIGN_Pos         5
#define ADC_CFGR1_ALIGN_Msk         (1U << ADC_CFGR1_ALIGN_Pos)
#define ADC_CFGR1_EXTSEL_Pos        6
#define ADC_CFGR1_EXTSEL_Msk        (0x3 << ADC_CFGR1_EXTSEL_Pos)
#define ADC_CFGR1_EXTSEL_TRG0       (0x0 << ADC_CFGR1_EXTSEL_Pos)
#define ADC_CFGR1_EXTSEL_TRG1       (0x1 << ADC_CFGR1_EXTSEL_Pos)
#define ADC_CFGR1_EXTSEL_TRG2       (0x2 << ADC_CFGR1_EXTSEL_Pos)
#define ADC_CFGR1_EXTSEL_TRG3       (0x3 << ADC_CFGR1_EXTSEL_Pos)
#define ADC_CFGR1_EXTSEL_TRG4       (0x4 << ADC_CFGR1_EXTSEL_Pos)
#define ADC_CFGR1_EXTSEL_TRG5       (0x5 << ADC_CFGR1_EXTSEL_Pos)
#define ADC_CFGR1_EXTSEL_TRG6       (0x6 << ADC_CFGR1_EXTSEL_Pos)
#define ADC_CFGR1_EXTSEL_TRG7       (0x7 << ADC_CFGR1_EXTSEL_Pos)
#define ADC_CFGR1_EXTEN_Pos         10
#define ADC_CFGR1_EXTEN_Msk         (0x3 << ADC_CFGR1_EXTEN_Pos)
#define ADC_CFGR1_EXTEN_DIS         (0x0 << ADC_CFGR1_EXTEN_Pos)
#define ADC_CFGR1_EXTEN_REDG        (0x1 << ADC_CFGR1_EXTEN_Pos)
#define ADC_CFGR1_EXTEN_FEDG        (0x2 << ADC_CFGR1_EXTEN_Pos)
#define ADC_CFGR1_EXTEN_RFEDG       (0x3 << ADC_CFGR1_EXTEN_Pos)
#define ADC_CFGR1_OVRMOD_Pos        12
#define ADC_CFGR1_OVRMOD_Msk        (1U << ADC_CFGR1_OVRMOD_Pos)
#define ADC_CFGR1_CONT_Pos          13
#define ADC_CFGR1_CONT_Msk          (1U << ADC_CFGR1_CONT_Pos)
#define ADC_CFGR1_WAIT_Pos          14
#define ADC_CFGR1_WAIT_Msk          (1U << ADC_CFGR1_WAIT_Pos)
#define ADC_CFGR1_AUTOFF_Pos        15
#define ADC_CFGR1_AUTOFF_Msk        (1U << ADC_CFGR1_AUTOFF_Pos)
#define ADC_CFGR1_DISCEN_Pos        16
#define ADC_CFGR1_DISCEN_Msk        (1U << ADC_CFGR1_DISCEN_Pos)
#define ADC_CFGR1_AWDSGL_Pos        22
#define ADC_CFGR1_AWDSGL_Msk        (1U << ADC_CFGR1_AWDSGL_Pos)
#define ADC_CFGR1_AWDEN_Pos         23
#define ADC_CFGR1_AWDEN_Msk         (1U << ADC_CFGR1_AWDEN_Pos)

#define ADC_CFGR1_AWDCH_Pos         26
#define ADC_CFGR1_AWDCH_Msk         (0x1F << ADC_CFGR1_AWDCH_Pos)
#define ADC_CFGR1_AWDCH_CH0         (0x00 << ADC_CFGR1_AWDCH_Pos)
#define ADC_CFGR1_AWDCH_CH1         (0x01 << ADC_CFGR1_AWDCH_Pos)
#define ADC_CFGR1_AWDCH_CH2         (0x02 << ADC_CFGR1_AWDCH_Pos)
#define ADC_CFGR1_AWDCH_CH3         (0x03 << ADC_CFGR1_AWDCH_Pos)
#define ADC_CFGR1_AWDCH_CH4         (0x04 << ADC_CFGR1_AWDCH_Pos)
#define ADC_CFGR1_AWDCH_CH5         (0x05 << ADC_CFGR1_AWDCH_Pos)
#define ADC_CFGR1_AWDCH_CH6         (0x06 << ADC_CFGR1_AWDCH_Pos)
#define ADC_CFGR1_AWDCH_CH7         (0x07 << ADC_CFGR1_AWDCH_Pos)
#define ADC_CFGR1_AWDCH_CH8         (0x08 << ADC_CFGR1_AWDCH_Pos)
#define ADC_CFGR1_AWDCH_CH9         (0x09 << ADC_CFGR1_AWDCH_Pos)
#define ADC_CFGR1_AWDCH_CH10        (0x0A << ADC_CFGR1_AWDCH_Pos)
#define ADC_CFGR1_AWDCH_CH11        (0x0B << ADC_CFGR1_AWDCH_Pos)
#define ADC_CFGR1_AWDCH_CH12        (0x0C << ADC_CFGR1_AWDCH_Pos)
#define ADC_CFGR1_AWDCH_CH13        (0x0D << ADC_CFGR1_AWDCH_Pos)
#define ADC_CFGR1_AWDCH_CH14        (0x0E << ADC_CFGR1_AWDCH_Pos)
#define ADC_CFGR1_AWDCH_CH15        (0x0F << ADC_CFGR1_AWDCH_Pos)
#define ADC_CFGR1_AWDCH_CHTEMP      (0x10 << ADC_CFGR1_AWDCH_Pos)
#define ADC_CFGR1_AWDCH_CHVREF      (0x11 << ADC_CFGR1_AWDCH_Pos)
#define ADC_CFGR1_AWDCH_CHVBAT      (0x12 << ADC_CFGR1_AWDCH_Pos)

#define ADC_CFGR2_CKMODE_Pos        30
#define ADC_CFGR2_CKMODE_Msk        (0x3 << ADC_CFGR2_CKMODE_Pos)
#define ADC_CFGR2_CKMODE_ADCCLK     (0x0 << ADC_CFGR2_CKMODE_Pos)
#define ADC_CFGR2_CKMODE_PCLK2      (0x1 << ADC_CFGR2_CKMODE_Pos)
#define ADC_CFGR2_CKMODE_PCLK4      (0x2 << ADC_CFGR2_CKMODE_Pos)

#define ADC_SMPR_SMP_Pos            0
#define ADC_SMPR_SMP_Msk            (0x7 << ADC_SMPR_SMP_Pos)
#define ADC_SMPR_SMP_1CYC           (0x0 << ADC_SMPR_SMP_Pos)
#define ADC_SMPR_SMP_7CYC           (0x1 << ADC_SMPR_SMP_Pos)
#define ADC_SMPR_SMP_13CYC          (0x2 << ADC_SMPR_SMP_Pos)
#define ADC_SMPR_SMP_28CYC          (0x3 << ADC_SMPR_SMP_Pos)
#define ADC_SMPR_SMP_41CYC          (0x4 << ADC_SMPR_SMP_Pos)
#define ADC_SMPR_SMP_55CYC          (0x5 << ADC_SMPR_SMP_Pos)
#define ADC_SMPR_SMP_71CYC          (0x6 << ADC_SMPR_SMP_Pos)
#define ADC_SMPR_SMP_239CYC         (0x7 << ADC_SMPR_SMP_Pos)

#define ADC_TR_HT_Pos               0
#define ADC_TR_HT_Msk               (0xFFF << ADC_TR_HT_Pos)
#define ADC_TR_LT_Pos               16
#define ADC_TR_LT_Msk               (0xFFF << ADC_TR_LT_Pos)

#define ADC_CHSELR_CHSEL0_Pos       0
#define ADC_CHSELR_CHSEL0_Msk       (1U << ADC_CHSELR_CHSEL0_Pos)
#define ADC_CHSELR_CHSEL1_Pos       1
#define ADC_CHSELR_CHSEL1_Msk       (1U << ADC_CHSELR_CHSEL1_Pos)
#define ADC_CHSELR_CHSEL2_Pos       2
#define ADC_CHSELR_CHSEL2_Msk       (1U << ADC_CHSELR_CHSEL2_Pos)
#define ADC_CHSELR_CHSEL3_Pos       3
#define ADC_CHSELR_CHSEL3_Msk       (1U << ADC_CHSELR_CHSEL3_Pos)
#define ADC_CHSELR_CHSEL4_Pos       4
#define ADC_CHSELR_CHSEL4_Msk       (1U << ADC_CHSELR_CHSEL4_Pos)
#define ADC_CHSELR_CHSEL5_Pos       5
#define ADC_CHSELR_CHSEL5_Msk       (1U << ADC_CHSELR_CHSEL5_Pos)
#define ADC_CHSELR_CHSEL6_Pos       6
#define ADC_CHSELR_CHSEL6_Msk       (1U << ADC_CHSELR_CHSEL6_Pos)
#define ADC_CHSELR_CHSEL7_Pos       7
#define ADC_CHSELR_CHSEL7_Msk       (1U << ADC_CHSELR_CHSEL7_Pos)
#define ADC_CHSELR_CHSEL8_Pos       8
#define ADC_CHSELR_CHSEL8_Msk       (1U << ADC_CHSELR_CHSEL8_Pos)
#define ADC_CHSELR_CHSEL9_Pos       9
#define ADC_CHSELR_CHSEL9_Msk       (1U << ADC_CHSELR_CHSEL9_Pos)
#define ADC_CHSELR_CHSEL10_Pos      10
#define ADC_CHSELR_CHSEL10_Msk      (1U << ADC_CHSELR_CHSEL10_Pos)
#define ADC_CHSELR_CHSEL11_Pos      11
#define ADC_CHSELR_CHSEL11_Msk      (1U << ADC_CHSELR_CHSEL11_Pos)
#define ADC_CHSELR_CHSEL12_Pos      12
#define ADC_CHSELR_CHSEL12_Msk      (1U << ADC_CHSELR_CHSEL12_Pos)
#define ADC_CHSELR_CHSEL13_Pos      13
#define ADC_CHSELR_CHSEL13_Msk      (1U << ADC_CHSELR_CHSEL13_Pos)
#define ADC_CHSELR_CHSEL14_Pos      14
#define ADC_CHSELR_CHSEL14_Msk      (1U << ADC_CHSELR_CHSEL14_Pos)
#define ADC_CHSELR_CHSEL15_Pos      15
#define ADC_CHSELR_CHSEL15_Msk      (1U << ADC_CHSELR_CHSEL15_Pos)
#define ADC_CHSELR_CHSELTEMP_Pos    16
#define ADC_CHSELR_CHSELTEMP_Msk    (1U << ADC_CHSELR_CHSELTEMP_Pos)
#define ADC_CHSELR_CHSELVREF_Pos    17
#define ADC_CHSELR_CHSELVREF_Msk    (1U << ADC_CHSELR_CHSELVREF_Pos)
#define ADC_CHSELR_CHSELVBAT_Pos    18
#define ADC_CHSELR_CHSELVBAT_Msk    (1U << ADC_CHSELR_CHSELVBAT_Pos)

#define ADC_DR_DATA_Pos             0
#define ADC_DR_DATA_Msk             (0xFFFF << ADC_DR_DATA_Pos)
#define ADC_DR_CALFAC_Pos           0
#define ADC_DR_CALFAC_Msk           (0x7F << ADC_DR_CALFAC_Pos)

#define ADC_CCR_VREFEN_Pos          22
#define ADC_CCR_VREFEN_Msk          (1U << ADC_CCR_VREFEN_Pos)
#define ADC_CCR_TSEN_Pos            23
#define ADC_CCR_TSEN_Msk            (1U << ADC_CCR_TSEN_Pos)
#define ADC_CCR_VBATEN_Pos          24
#define ADC_CCR_VBATEN_Msk          (1U << ADC_CCR_VBATEN_Pos)

// methods

void adc_init(void);

void adc_enable(void);

void adc_disable(void);

bool adc_is_enabled(void);

void adc_auto_calibrate(void);

void adc_set_clock(ADC_CLKSRC clk);



void adc_set_channel(ADC_CHANNEL channel);

// void adc_set_channels_masked(uint32_t mask);

void adc_set_resolution(ADC_RESOLUTION resolution);

void adc_set_sample_time(ADC_SAMPLE_TIME time);

uint16_t adc_read_single(ADC_CHANNEL channel);

#endif // ADC_H
