// #include "stepper_motor.h"
// #include "bflb_mtimer.h"
// #include "bflb_gpio.h"
// #include "board.h"

// void stepper_motor_init(void *gpio)
// {
//     // 配置步进电机脉冲引脚
//     bflb_gpio_init((struct bflb_device_s *)gpio, STEPPER_MOTOR_0_PULSE_PIN, GPIO_OUTPUT | GPIO_PULLDOWN | GPIO_SMT_EN | GPIO_DRV_1);
//     bflb_gpio_init((struct bflb_device_s *)gpio, STEPPER_MOTOR_1_PULSE_PIN, GPIO_OUTPUT | GPIO_PULLDOWN | GPIO_SMT_EN | GPIO_DRV_1);
//     bflb_gpio_init((struct bflb_device_s *)gpio, STEPPER_MOTOR_2_PULSE_PIN, GPIO_OUTPUT | GPIO_PULLDOWN | GPIO_SMT_EN | GPIO_DRV_1);
// }

// void stepper_motor_move(void *gpio, uint8_t motor_id, uint32_t steps)
// {
//     if (motor_id >= STEPPER_MOTOR_COUNT) {
//         return;
//     }

//     uint32_t pulse_pin;
//     switch (motor_id) {
//     case 0:
//         pulse_pin = STEPPER_MOTOR_0_PULSE_PIN;
//         break;
//     case 1:
//         pulse_pin = STEPPER_MOTOR_1_PULSE_PIN;
//         break;
//     case 2:
//         pulse_pin = STEPPER_MOTOR_2_PULSE_PIN;
//         break;
//     default:
//         return;
//     }

//     for (uint32_t i = 0; i < steps; i++) {
//         bflb_gpio_toggle((struct bflb_device_s *)gpio, pulse_pin);
//         arch_delay_ms(1); // 延时 1ms
//     }
// }

// void stepper_motor_task(void *pvParameters)
// {
//     void *gpio = pvParameters;
//     stepper_motor_init(gpio);

//     while (1)
//     {
//         stepper_motor_move(gpio, 0, 100); // 驱动 0 号步进电机 100 个脉冲
//         vTaskDelay(pdMS_TO_TICKS(1000)); // 等待 1 秒
//         stepper_motor_move(gpio, 1, 200); // 驱动 1 号步进电机 200 个脉冲
//         vTaskDelay(pdMS_TO_TICKS(1000)); // 等待 1 秒
//         stepper_motor_move(gpio, 2, 150); // 驱动 2 号步进电机 150 个脉冲
//         vTaskDelay(pdMS_TO_TICKS(1000)); // 等待 1 秒
//     }
// }