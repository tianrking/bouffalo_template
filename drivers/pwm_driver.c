#include "pwm_driver.h"
#include "bflb_gpio.h"
#include "bflb_clock.h"
#include "bflb_pwm_v2.h"
#include "log.h"

#define DBG_TAG "PWM"

static struct bflb_device_s *pwm;
static struct bflb_device_s *gpio;

bool pwm_driver_init(void)
{
    LOG_I("Initializing PWM driver\r\n");

    gpio = bflb_device_get_by_name("gpio");
    pwm = bflb_device_get_by_name("pwm_v2_0");

    if (gpio == NULL || pwm == NULL) {
        LOG_E("Failed to get device handles\r\n");
        return false;
    }

    // Configure GPIO pins for PWM output
    bflb_gpio_init(gpio, PWM_PIN_CH0, GPIO_FUNC_PWM0 | GPIO_ALTERNATE | GPIO_PULLDOWN | GPIO_SMT_EN | GPIO_DRV_1);
    bflb_gpio_init(gpio, PWM_PIN_CH1, GPIO_FUNC_PWM0 | GPIO_ALTERNATE | GPIO_PULLDOWN | GPIO_SMT_EN | GPIO_DRV_1);
    bflb_gpio_init(gpio, PWM_PIN_CH2, GPIO_FUNC_PWM0 | GPIO_ALTERNATE | GPIO_PULLDOWN | GPIO_SMT_EN | GPIO_DRV_1);

    // Configure PWM
    struct bflb_pwm_v2_config_s cfg = {
        .clk_source = BFLB_SYSTEM_PBCLK,
        .clk_div = 80,  // Assuming PBCLK is 80MHz, this gives 1MHz PWM clock
        .period = 1000, // 1MHz / 1000 = 1kHz
    };

    bflb_pwm_v2_init(pwm, &cfg);
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

    bflb_pwm_v2_channel_init(pwm, PWM_CH0, &ch_cfg);
    bflb_pwm_v2_channel_init(pwm, PWM_CH1, &ch_cfg);
    bflb_pwm_v2_channel_init(pwm, PWM_CH2, &ch_cfg);

    // Set initial duty cycle to 0 (low level)
    pwm_set_duty_cycle(PWM_CH0, 0);
    pwm_set_duty_cycle(PWM_CH1, 0);
    pwm_set_duty_cycle(PWM_CH2, 0);

    // Start PWM
    bflb_pwm_v2_start(pwm);

    LOG_I("PWM driver initialized successfully\r\n");
    return true;
}

int pwm_set_duty_cycle(uint8_t ch, uint8_t duty_cycle)
{
    if (ch >= PWM_V2_CH_MAX) {
        LOG_E("Invalid PWM channel: %d\r\n", ch);
        return PWM_ERROR_INVALID_CHANNEL;
    }

    if (duty_cycle > 100) {
        duty_cycle = 100;
    }

    uint16_t threshold = (uint16_t)(((float)duty_cycle / 100.0f) * 1000);
    bflb_pwm_v2_channel_set_threshold(pwm, ch, 0, threshold);

    LOG_I("Set PWM channel %d duty cycle to %d%%\r\n", ch, duty_cycle);
    return PWM_OK;
}

int pwm_start(uint8_t ch)
{
    if (ch >= PWM_V2_CH_MAX) {
        LOG_E("Invalid PWM channel: %d\r\n", ch);
        return PWM_ERROR_INVALID_CHANNEL;
    }

    bflb_pwm_v2_channel_positive_start(pwm, ch);
    LOG_I("Started PWM channel %d\r\n", ch);
    return PWM_OK;
}

int pwm_stop(uint8_t ch)
{
    if (ch >= PWM_V2_CH_MAX) {
        LOG_E("Invalid PWM channel: %d\r\n", ch);
        return PWM_ERROR_INVALID_CHANNEL;
    }

    bflb_pwm_v2_channel_positive_stop(pwm, ch);
    LOG_I("Stopped PWM channel %d\r\n", ch);
    return PWM_OK;
}

void pwm_task(void *pvParameters)
{
    uint8_t duty_cycle = 0;
    int8_t direction = 1;

    LOG_I("PWM task started\r\n");

    if (pwm_start(PWM_CH0) != PWM_OK ||
        pwm_start(PWM_CH1) != PWM_OK ||
        pwm_start(PWM_CH2) != PWM_OK) {
        LOG_E("Failed to start PWM channels\r\n");
        vTaskDelete(NULL);
        return;
    }

    while (1) {
        
        // if (pwm_set_duty_cycle(PWM_CH0, duty_cycle) != PWM_OK ||
        //     pwm_set_duty_cycle(PWM_CH1, duty_cycle) != PWM_OK ||
        //     pwm_set_duty_cycle(PWM_CH2, duty_cycle) != PWM_OK) {
        //     LOG_E("Failed to set PWM duty cycle\r\n");
        //     break;
        // }

        // duty_cycle += direction;

        // if (duty_cycle >= 100 || duty_cycle <= 0) {
        //     direction *= -1;
        // }

        vTaskDelay(pdMS_TO_TICKS(50));
    }

    // If we've broken out of the loop due to an error, stop all PWM channels
    pwm_stop(PWM_CH0);
    pwm_stop(PWM_CH1);
    pwm_stop(PWM_CH2);

    LOG_E("PWM task ended unexpectedly\r\n");
    vTaskDelete(NULL);
}