# STM32F0x1 HAL Library

A custom-built Hardware Abstraction Layer (HAL) designed to simplify development for the STM32F0x1 microcontroller family by abstracting register-level operations into a clean, modular API.

## Supported Peripherals & Features
* **RCC:** Basic system clock configuration and peripheral clock gating.
* **FLASH:** Latency and prefetch configuration.
* **SysTick:** Millisecond-accurate hardware counter for timing operations.
* **TIME:** High-level timing functions (e.g., `delay_ms`, `delay_us`).
* **GPIO:** Port configuration, pin manipulation, and alternate function mapping.
* **EXTI / SYSCFG:** External GPIO interrupt features.
* **NVIC:** IRQ enable/disable and priority control.
* **ADC:** Basic single-ended conversions with auto-calibration.
* **TIMERS:** Basic operations for Timers 2/3.
* **CRC:** Hardware CRC accelerator with configurable polynomial, size, and bit-reversal (REVIN/REVOUT).
* **TM1637:** 4-digit 7-segment display driver.

For a full breakdown of what is done, partially done, and still missing, see [TODO.md](TODO.md).

---

## Academic Integrity & Plagiarism
**Notice to students at Avans University of Applied Sciences:**
This library is a personal project developed for the ET/TI curriculum. 
* **Do not use this code in your own submissions.** Automated tools like **MOSS** are used to detect similarities in embedded C/C++ code.
* My work is timestamped via GitHub commits; any unauthorized use will be flagged as a violation of the student code of conduct.

---

## License
This project is licensed under the **MIT License**. You are free to use this for personal learning or reference, provided that the original copyright notice and this permission notice are included in all copies or substantial portions of the software.
