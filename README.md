# STM32F0x1 HAL Library

A custom-built Hardware Abstraction Layer (HAL) designed to simplify development for the STM32F0x1 microcontroller family by abstracting register-level operations into a clean, modular API.

## Implemented Peripherals & Features
* **RCC:** System clock init (HSE + PLL → 48 MHz), peripheral clock gating for AHB/APB1/APB2.
* **FLASH:** Latency and prefetch configuration (used internally by clock init).
* **SysTick:** Millisecond counter, enable/disable, clock source selection, and periodic callback support.
* **TIME:** `delay_ms`, assembly-tuned `delay_us`, `millis`, and counter reset.
* **GPIO:** Mode, output type, pull-up/down, read/write, atomic set/reset, and alternate function mapping.
* **EXTI / SYSCFG:** External GPIO interrupts with configurable edge, port mapping, and per-line callbacks for all 16 lines.
* **NVIC:** IRQ enable/disable, priority control, and pending set/clear.
* **ADC:** Single-ended blocking conversions with auto-calibration, configurable channel, resolution, and sample time.
* **TIM2 / TIM3:** Prescaler, auto-reload, start/stop/reset, and compare register read/write/flag.
* **TM1637:** Bit-bang driver for 4-digit 7-segment TM1637 display modules.

For a full breakdown of what is done, partially done, and still missing across all STM32F091RC peripherals, see [TODO.md](TODO.md).

---

## Academic Integrity & Plagiarism
**Notice to students at Avans University of Applied Sciences:**
This library is a personal project developed for the ET/TI curriculum. 
* **Do not use this code in your own submissions.** Automated tools like **MOSS** are used to detect similarities in embedded C/C++ code.
* My work is timestamped via GitHub commits; any unauthorized use will be flagged as a violation of the student code of conduct.

---

## License
This project is licensed under the **MIT License**. You are free to use this for personal learning or reference, provided that the original copyright notice and this permission notice are included in all copies or substantial portions of the software.
