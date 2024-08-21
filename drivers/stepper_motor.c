#include "stepper_motor.h"
#include "bflb_gpio.h"
#include "bflb_clock.h"
#include "bflb_pwm_v2.h"
#include "log.h"

#define DBG_TAG "STEPPER_MOTOR"

static struct bflb_device_s *stepper_pwm;
static struct bflb_device_s *stepper_gpio;

static uint32_t stepper_pulse_count = 0;
static uint32_t stepper_total_steps = 20;

void stepper_motor_channel0_isr(int irq, void *arg)
{
    if (stepper_pulse_count < stepper_total_steps) {
        bflb_pwm_v2_channel_set_threshold(stepper_pwm, STEPPER_CH0, 0, 500); // 50% duty cycle
        stepper_pulse_count++;
        // printf("Pulse %d generated\r\n", stepper_pulse_count);
    } else {
        bflb_pwm_v2_channel_positive_stop(stepper_pwm, STEPPER_CH0);
        // printf("PWM output completed, %d pulses generated\r\n", stepper_total_steps);
    }

    bflb_pwm_v2_int_clear(stepper_pwm, PWM_INTCLR_PERIOD); // Clear period interrupt flag
    // LOG_I("Stepper motor channel 0 interrupt triggered, pulse count: %d\r\n", stepper_pulse_count);
}

void stepper_motor_set_total_steps(uint32_t steps)
{
    stepper_total_steps = steps;
    stepper_pulse_count = 0; // Reset the pulse count
}

bool stepper_motor_init(void)
{
    LOG_I("Initializing stepper motor driver\r\n");

    stepper_gpio = bflb_device_get_by_name("gpio");
    stepper_pwm = bflb_device_get_by_name("pwm_v2_0");

    if (stepper_gpio == NULL || stepper_pwm == NULL) {
        LOG_E("Failed to get device handles\r\n");
        return false;
    }

    // Configure GPIO pins for PWM output
    bflb_gpio_init(stepper_gpio, STEPPER_MOTOR_PIN, GPIO_FUNC_PWM0 | GPIO_ALTERNATE | GPIO_PULLDOWN | GPIO_SMT_EN | GPIO_DRV_1);
    bflb_gpio_init(stepper_gpio, STEPPER_PIN_CH1, GPIO_FUNC_PWM0 | GPIO_ALTERNATE | GPIO_PULLDOWN | GPIO_SMT_EN | GPIO_DRV_1);
    bflb_gpio_init(stepper_gpio, STEPPER_PIN_CH2, GPIO_FUNC_PWM0 | GPIO_ALTERNATE | GPIO_PULLDOWN | GPIO_SMT_EN | GPIO_DRV_1);

    // Configure PWM
    struct bflb_pwm_v2_config_s cfg = {
        .clk_source = BFLB_SYSTEM_PBCLK,
        .clk_div = 80,  // Assuming PBCLK is 80MHz, this gives 1MHz PWM clock
        .period = STEPPER_FREQUENCY, // 1kHz
    };

    bflb_pwm_v2_init(stepper_pwm, &cfg);
    // Configure PWM channels
    struct bflb_pwm_v2_channel_config_s ch_cfg = {
        .positive_polarity = PWM_POLARITY_ACTIVE_HIGH,
        .negative_polarity = PWM_POLARITY_ACTIVE_HIGH,
        .positive_stop_state = PWM_STATE_INACTIVE,
        .negative_stop_state = PWM_STATE_INACTIVE,
        .positive_brake_state = PWM_STATE_INACTIVE,
        .negative_brake_state = PWM_STATE_INACTIVE,
        .dead_time = 0,
    };

    bflb_pwm_v2_channel_init(stepper_pwm, STEPPER_CH0, &ch_cfg);
    bflb_pwm_v2_channel_init(stepper_pwm, STEPPER_CH1, &ch_cfg);
    bflb_pwm_v2_channel_init(stepper_pwm, STEPPER_CH2, &ch_cfg);

    // Set initial duty cycle to 0 (low level)
    stepper_motor_set_duty_cycle(STEPPER_CH0, 0);
    stepper_motor_set_duty_cycle(STEPPER_CH1, 0);
    stepper_motor_set_duty_cycle(STEPPER_CH2, 0);

    // Enable PWM period interrupt for STEPPER_CH0
    bflb_pwm_v2_int_enable(stepper_pwm, PWM_INTEN_PERIOD, true);
    bflb_irq_attach(stepper_pwm->irq_num, stepper_motor_channel0_isr, NULL);
    bflb_irq_set_priority(stepper_pwm->irq_num, 5, 1); // Set PWM interrupt priority
    bflb_irq_enable(stepper_pwm->irq_num);

    // Start PWM
    bflb_pwm_v2_start(stepper_pwm);

    LOG_I("Stepper motor driver initialized successfully\r\n");
    return true;
}

int stepper_motor_set_duty_cycle(uint8_t ch, uint8_t duty_cycle)
{
    if (ch >= PWM_V2_CH_MAX) {
        LOG_E("Invalid PWM channel: %d\r\n", ch);
        return STEPPER_ERROR_INVALID_CHANNEL;
    }

    if (duty_cycle > 100) {
        duty_cycle = 100;
    }

    uint16_t threshold = (uint16_t)(((float)duty_cycle / 100.0f) * 1000);
    bflb_pwm_v2_channel_set_threshold(stepper_pwm, ch, 0, threshold);

    LOG_I("Set stepper motor channel %d duty cycle to %d%%\r\n", ch, duty_cycle);
    return STEPPER_OK;
}

int stepper_motor_start(uint8_t ch)
{
    if (ch >= PWM_V2_CH_MAX) {
        LOG_E("Invalid PWM channel: %d\r\n", ch);
        return STEPPER_ERROR_INVALID_CHANNEL;
    }

    bflb_pwm_v2_channel_positive_start(stepper_pwm, ch);
    LOG_I("Started stepper motor channel %d\r\n", ch);
    return STEPPER_OK;
}

int stepper_motor_stop(uint8_t ch)
{
    if (ch >= PWM_V2_CH_MAX) {
        LOG_E("Invalid PWM channel: %d\r\n", ch);
        return STEPPER_ERROR_INVALID_CHANNEL;
    }

    bflb_pwm_v2_channel_positive_stop(stepper_pwm, ch);
    LOG_I("Stopped stepper motor channel %d\r\n", ch);
    return STEPPER_OK;
}

void stepper_motor_task(void *pvParameters)
{
    LOG_I("Stepper motor task started\r\n");

    if (stepper_motor_start(STEPPER_CH0) != STEPPER_OK ||
        stepper_motor_start(STEPPER_CH1) != STEPPER_OK ||
        stepper_motor_start(STEPPER_CH2) != STEPPER_OK) {
        LOG_E("Failed to start stepper motor channels\r\n");
        vTaskDelete(NULL);
        return;
    }

    while (1) {
        
        if (stepper_pulse_count >= stepper_total_steps) {
            stepper_motor_stop(STEPPER_CH0);
            printf("PWM output completed, %d pulses generated\r\n", stepper_total_steps);
            vTaskDelay(pdMS_TO_TICKS(40)); // Delay for 1 second
            stepper_motor_set_total_steps(5); // Set new total steps
            stepper_motor_start(STEPPER_CH0);
        }

        vTaskDelay(pdMS_TO_TICKS(50));
    }

    // If we've broken out of the loop due to an error, stop all PWM channels
    stepper_motor_stop(STEPPER_CH0);
    stepper_motor_stop(STEPPER_CH1);
    stepper_motor_stop(STEPPER_CH2);

    LOG_E("Stepper motor task ended unexpectedly\r\n");
    vTaskDelete(NULL);
}