#ifndef PWM_DRIVER_H
#define PWM_DRIVER_H

#include <stdint.h>
#include <stdbool.h>
#include "bflb_pwm_v2.h"
#include "FreeRTOS.h"
#include "task.h"

#define PWM_CH0 0
#define PWM_CH1 1
#define PWM_CH2 2

#define PWM_FREQUENCY 1000 // 1kHz

#define PWM_PIN_CH0 GPIO_PIN_0
#define PWM_PIN_CH1 GPIO_PIN_30
#define PWM_PIN_CH2 GPIO_PIN_1

// Error codes
#define PWM_OK 0
#define PWM_ERROR_INIT -1
#define PWM_ERROR_INVALID_CHANNEL -2

bool pwm_driver_init(void);
int pwm_set_duty_cycle(uint8_t ch, uint8_t duty_cycle);
int pwm_start(uint8_t ch);
int pwm_stop(uint8_t ch);
void pwm_task(void *pvParameters);

#endif // PWM_DRIVER_H