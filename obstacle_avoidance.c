/* STM32 Obstacle Avoidance Robot Example */
#include "stm32f4xx_hal.h"
#include "utils.h"

// Define pins (adjust per your STM32 board)
#define TRIG_PIN GPIO_PIN_9
#define ECHO_PIN GPIO_PIN_8
#define MOTOR_LEFT_PIN GPIO_PIN_0
#define MOTOR_RIGHT_PIN GPIO_PIN_1
#define MOTOR_PORT GPIOA

void delay_us(uint16_t us) {
    // Simple microsecond delay
    uint32_t start = HAL_GetTick();
    while ((HAL_GetTick() - start) < us/1000);
}

int read_distance() {
    // Trigger ultrasonic sensor
    HAL_GPIO_WritePin(GPIOA, TRIG_PIN, GPIO_PIN_SET);
    HAL_Delay(1);
    HAL_GPIO_WritePin(GPIOA, TRIG_PIN, GPIO_PIN_RESET);

    // Measure echo pulse duration
    uint32_t start = HAL_GetTick();
    while(HAL_GPIO_ReadPin(GPIOA, ECHO_PIN) == GPIO_PIN_RESET);
    uint32_t echo_start = HAL_GetTick();
    while(HAL_GPIO_ReadPin(GPIOA, ECHO_PIN) == GPIO_PIN_SET);
    uint32_t echo_end = HAL_GetTick();

    int duration = echo_end - echo_start;
    int distance = duration * 0.034 / 2; // cm
    return distance;
}

void set_motors(int left_speed, int right_speed) {
    // Simple motor control using PWM (adjust as needed)
    __HAL_TIM_SET_COMPARE(&htim2, MOTOR_LEFT_PIN, left_speed);
    __HAL_TIM_SET_COMPARE(&htim2, MOTOR_RIGHT_PIN, right_speed);
}

int main(void) {
    HAL_Init();
    SystemClock_Config();
    MX_GPIO_Init();
    MX_TIM2_Init();

    HAL_TIM_PWM_Start(&htim2, MOTOR_LEFT_PIN);
    HAL_TIM_PWM_Start(&htim2, MOTOR_RIGHT_PIN);

    while(1) {
        int distance = read_distance();

        if(distance < 15) {
            // Obstacle detected → stop or turn
            set_motors(0, 0);
            HAL_Delay(500);
            set_motors(150, -150); // turn
            HAL_Delay(300);
        } else {
            // Move forward
            set_motors(200, 200);
        }
    }
}
