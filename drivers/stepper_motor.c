// #include <FreeRTOS.h>
// #include "task.h"
// #include "timers.h"
// #include "stepper_motor.h"
// #include "bflb_clock.h"
// #include "bflb_mtimer.h"
// #include "bflb_pwm_v2.h"
// #include "board.h"
// #include "bl616_irq.h"
// #include "bflb_uart.h"
// #include "log.h"
// #include "bflb_gpio.h"

// #define STEPPER_MOTOR_PIN GPIO_PIN_1

// static struct bflb_device_s *pwm;
// static uint32_t pulse_count = 0;
// static uint32_t total_steps = 0;

// void stepper_motor_pwm_isr(int irq, void *arg)
// {
//     if (pulse_count < total_steps) {
//         bflb_pwm_v2_channel_set_threshold(pwm, PWM_CH0, 0, 2400); // 60% duty cycle
//         pulse_count++;
//         printf("Pulse %d generated\r\n", pulse_count);
//     } else {
//         bflb_pwm_v2_channel_positive_stop(pwm, PWM_CH0);
//         printf("PWM output completed, %d pulses generated\r\n", total_steps);
//     }

//     bflb_pwm_v2_int_clear(pwm, PWM_INTCLR_PERIOD); // Clear period interrupt flag
//     LOG_I("PWM interrupt triggered, pulse count: %d\r\n", pulse_count);
// }

// void stepper_motor_init(struct bflb_device_s *gpio_dev)
// {
//     struct bflb_device_s *gpio = bflb_device_get_by_name("gpio");
//     bflb_gpio_init(gpio, STEPPER_MOTOR_PIN, GPIO_FUNC_PWM0 | GPIO_ALTERNATE | GPIO_PULLDOWN | GPIO_SMT_EN | GPIO_DRV_1);

//     pwm = bflb_device_get_by_name("pwm_v2_0");

//     struct bflb_pwm_v2_config_s cfg = {
//         .clk_source = BFLB_SYSTEM_PBCLK,
//         .clk_div = 2, // Adjust the clock divider to get the desired PWM frequency
//         .period = 4000, // Adjust the period to get the desired PWM resolution
//     };

//     bflb_pwm_v2_init(pwm, &cfg);

//     struct bflb_pwm_v2_channel_config_s ch_cfg = {
//         .positive_polarity = PWM_POLARITY_ACTIVE_HIGH,
//         .negative_polarity = PWM_POLARITY_ACTIVE_HIGH,
//         .positive_stop_state = PWM_STATE_INACTIVE,
//         .negative_stop_state = PWM_STATE_INACTIVE,
//         .positive_brake_state = PWM_STATE_INACTIVE,
//         .negative_brake_state = PWM_STATE_INACTIVE,
//         .dead_time = 0,
//     };

//     bflb_pwm_v2_channel_init(pwm, PWM_CH0, &ch_cfg);
//     bflb_pwm_v2_channel_set_threshold(pwm, PWM_CH0, 0, 2400); // 60% duty cycle

//     bflb_pwm_v2_int_enable(pwm, PWM_INTEN_PERIOD, true); // Enable PWM period interrupt
//     bflb_irq_attach(pwm->irq_num, stepper_motor_pwm_isr, NULL);
//     bflb_irq_set_priority(pwm->irq_num, 5, 1); // Set PWM interrupt priority
//     bflb_irq_enable(pwm->irq_num);
// }

// void stepper_motor_task(void *pvParameters)
// {
//     printf("START STEP TASK\r\n");

//     stepper_motor_set_steps(10); // Set number of pulses to output
//     bflb_pwm_v2_channel_positive_start(pwm, PWM_CH0); // Start PWM output

//     while (pulse_count < total_steps)
//     {
//         vTaskDelay(pdMS_TO_TICKS(10)); // Wait for pulses to complete
//     }

//     printf("PWM output completed, %d pulses generated\r\n", total_steps);
//     vTaskDelete(NULL);
// }

// void stepper_motor_set_steps(uint32_t steps)
// {
//     pulse_count = 0;
//     total_steps = steps;
// }