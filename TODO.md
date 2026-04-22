# STM32F091RC — Peripheral Implementation Status

Legend: ✅ Done &nbsp;|&nbsp; ⚠️ Partial &nbsp;|&nbsp; ❌ Not started

Sorted from highest to lowest implementation priority.

---

## Core / System

| Peripheral | Status | Notes |
|---|---|---|
| **RCC** | ⚠️ Partial | Clock init (HSE + PLL → 48 MHz), all AHB/APB1/APB2 enable/reset bits defined. Missing: CIR (interrupt flags), APB1RSTR, dynamic runtime clock switching, LSE/LSI/HSI14 setup. |
| **FLASH** | ⚠️ Partial | Only ACR (latency, prefetch) implemented, used internally by clock init. Missing: unlock/lock, page erase, word program, option bytes (KEYR, OPTKEYR, SR, CR, AR, OBR, WRPR). |
| **SysTick** | ✅ Done | Init, enable/disable, interrupt, clock source, reload value, `ms_ticks` counter, callback interval. Missing: calibration value helpers (NOREF, SKEW, TENMS). |
| **NVIC** | ⚠️ Partial | Enable/disable IRQ, priority, set/clear pending. Missing: named IRQ number `#define` list — callers must know raw numbers manually. |
| **PWR** | ❌ Not started | Sleep, Stop, Standby mode entry; wake-up sources; PVD (voltage detector). |
| **IWDG** | ❌ Not started | Independent watchdog — prescaler, reload, key register, start/feed. |
| **WWDG** | ❌ Not started | Window watchdog — prescaler, window value, enable, feed. |

---

## GPIO & Interrupts

| Peripheral | Status | Notes |
|---|---|---|
| **GPIO** | ⚠️ Partial | Mode, output type, pull-up/down, read/write, atomic set/reset (BSRR/BRR), alternate function. Missing: speed control (OSPEEDR), pin locking (LCKR), raw bit-field `#define` masks. |
| **EXTI / SYSCFG** | ✅ Done | Configure rising/falling edge, port mapping, enable/disable, software IRQ, pending flag get/clear, per-line callback, ISR handlers for all three EXTI groups (0–1, 2–3, 4–15). Missing: event outputs (EMR). |

---

## Communication

| Peripheral | Status | Notes |
|---|---|---|
| **USART 1–8** | ❌ Not started | All 8 USART instances. Header and source files exist but are empty. Needed: init, baud rate, TX/RX (polling + interrupt), async RX with DMA. |
| **SPI 1–2** | ❌ Not started | SPI1 (APB2) and SPI2 (APB1). Header and source files exist but are empty. Needed: master/slave, full-duplex, CPOL/CPHA, NSS, DMA. |
| **I2C 1–2** | ❌ Not started | I2C1/I2C2 with Fast Mode+ support. Header and source files exist but are empty. Needed: init, 7/10-bit addressing, TX/RX (polling + interrupt), DMA. |
| **CAN (bxCAN)** | ❌ Not started | Single CAN 2.0B peripheral. Needed: init, filter config, TX mailbox, RX FIFO, interrupt handler. |

---

## Timers

| Peripheral | Status | Notes |
|---|---|---|
| **TIM2 / TIM3** | ⚠️ Partial | Clock enable, start/stop/reset, prescaler, auto-reload, counter read, compare register read/write/flag. Missing: CR2, SMCR (slave/trigger), DIER (interrupts), CCMR (output compare / PWM / input capture modes), CCER (channel enable), EGR, DMA burst (DCR/DMAR). **No PWM, no input capture, no encoder mode.** |
| **TIM1** | ❌ Not started | Advanced-control timer. Needed: all TIM2/3 features plus complementary outputs, dead-time, break input (BDTR). |
| **TIM6 / TIM7** | ❌ Not started | Basic 16-bit up-counters. Needed: prescaler, auto-reload, update interrupt, DAC trigger. |
| **TIM14** | ❌ Not started | General-purpose 16-bit, 1 capture/compare channel. |
| **TIM15** | ❌ Not started | General-purpose 16-bit, 2 capture/compare channels, complementary output on CH1. |
| **TIM16 / TIM17** | ❌ Not started | General-purpose 16-bit, 1 capture/compare channel each, complementary output. |

---

## Analog

| Peripheral | Status | Notes |
|---|---|---|
| **ADC** | ⚠️ Partial | Init, enable/disable, auto-calibration, clock source, channel select, resolution, sample time, single blocking read. Missing: DMA mode, continuous/scan mode, interrupt-driven conversions, watchdog threshold (TR), internal channel wake-up (temp sensor, VREF, VBAT via CCR). |
| **DAC** | ❌ Not started | 2-channel 12-bit DAC. Needed: init, channel enable, software/hardware trigger, output buffer, DMA. |
| **COMP 1–2** | ❌ Not started | Voltage comparators with programmable reference, hysteresis, and output routing. |

---

## DMA

| Peripheral | Status | Notes |
|---|---|---|
| **DMA1** (7 ch) | ❌ Not started | Required for efficient ADC, USART, SPI, and I2C transfers. Needed: channel config, transfer size, memory/peripheral addressing, interrupt on complete/error. |
| **DMA2** (5 ch) | ❌ Not started | Same as DMA1. |

---

## Other Peripherals

| Peripheral | Status | Notes |
|---|---|---|
| **RTC** | ❌ Not started | Real-time clock with calendar, alarm, and wakeup timer. Needs backup domain unlock. |
| **CRC** | ❌ Not started | Hardware CRC-32 accelerator. Simple DR/CR/IDR interface. |
| **TSC** | ❌ Not started | Touch Sensing Controller. Needed: group/channel config, acquisition, threshold. |
| **CEC** | ❌ Not started | HDMI-CEC controller. Needed: init, TX/RX, interrupt handling. |
| **CRS** | ❌ Not started | Clock Recovery System — trims HSI48 using an external reference (SOF or GPIO). |
