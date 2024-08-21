#ifndef STEPPER_MOTOR_H
#define STEPPER_MOTOR_H

#include <stdint.h>
#include <stdbool.h>
#include "bflb_pwm_v2.h"
#include "FreeRTOS.h"
#include "task.h"

#define STEPPER_CH0 0
#define STEPPER_CH1 1
#define STEPPER_CH2 2

#define STEPPER_FREQUENCY 1000 // 1kHz

#define STEPPER_MOTOR_PIN GPIO_PIN_0
#define STEPPER_PIN_CH1 GPIO_PIN_30
#define STEPPER_PIN_CH2 GPIO_PIN_1

// Error codes
#define STEPPER_OK 0
#define STEPPER_ERROR_INIT -1
#define STEPPER_ERROR_INVALID_CHANNEL -2

bool stepper_motor_init(void);
int stepper_motor_set_duty_cycle(uint8_t ch, uint8_t duty_cycle);
int stepper_motor_start(uint8_t ch);
int stepper_motor_stop(uint8_t ch);
void stepper_motor_task(void *pvParameters);

void stepper_motor_channel0_isr(int irq, void *arg);
void stepper_motor_set_total_steps(uint32_t steps);

#endif // STEPPER_MOTOR_H