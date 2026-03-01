
#include "time.h"

void time_init(void) {
    // TODO: check/use current clock config.

    // Hardcoded for now to a cpu clock of 48MHz
    systick_init(47999); 
}

uint32_t millis(void) {
    return ms_ticks;
}

void delay_ms(uint32_t ms) {
    uint32_t start = ms_ticks; // milis();
    uint32_t target = start + ms;
    while (ms_ticks < target);
}

__attribute((aligned(4)))
__attribute((naked))
void delay_us(__attribute__((unused)) uint32_t us) {
    // tuned 49/48 cycle per us loop.
    __asm volatile (
    "outer_loop:         \n"    // 3 cycles from branch to function
    "    mov  r1, #10    \n"    // 1
    "inner_loop:         \n"    // 10 x 4 - 2 = 38 cycles
    "    sub r1, #1      \n"    // 1
    "    bne inner_loop  \n"    // 3 when taken 1 when not
    "    nop             \n"    // 1
    "    sub r0, #1      \n"    // 1
    "    bne outer_loop  \n"    // 3 when taken 1 when not
    "    bx lr           \n"    // 3
    );
}

void millis_reset_time(void) {
    ms_ticks = 0;
}
