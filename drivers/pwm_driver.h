#ifndef PWM_DRIVER_H
#define PWM_DRIVER_H

#include "bflb_pwm_v2.h"

void pwm_driver_init(void);
void pwm_set_duty_cycle(uint8_t ch, uint16_t duty_cycle);
void pwm_task(void *pvParameters);

#endif