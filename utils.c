#include "utils.h"
#include "stm32f4xx_hal.h"

void delay_ms(uint32_t ms) {
    HAL_Delay(ms);
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}
