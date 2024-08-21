#include <FreeRTOS.h>
#include "task.h"
#include "pwm_driver.h"
#include "bflb_gpio.h"
#include "bflb_mtimer.h"
#include "board.h"
#include "bflb_clock.h"

struct bflb_device_s *pwm;
struct bflb_device_s *gpio;
struct bflb_pwm_v2_config_s cfg;

void pwm_driver_init(void)
{
    gpio = bflb_device_get_by_name("gpio");

    // 配置 GPIO0 为 PWM_CH0 输出
    bflb_gpio_init(gpio, GPIO_PIN_0, GPIO_FUNC_PWM0 | GPIO_ALTERNATE | GPIO_PULLUP | GPIO_SMT_EN | GPIO_DRV_1);
    // 配置 GPIO1 为 PWM_CH1 输出
    bflb_gpio_init(gpio, GPIO_PIN_1, GPIO_FUNC_PWM0 | GPIO_ALTERNATE | GPIO_PULLUP | GPIO_SMT_EN | GPIO_DRV_1);
    // 配置 GPIO30 为 PWM_CH2 输出
    bflb_gpio_init(gpio, GPIO_PIN_30, GPIO_FUNC_PWM0 | GPIO_ALTERNATE | GPIO_PULLUP | GPIO_SMT_EN | GPIO_DRV_1);

    pwm = bflb_device_get_by_name("pwm_v2_0");

    /* period = .XCLK / .clk_div / .period = 80MHz / 80 / 1000 = 1kHz */
    cfg = (struct bflb_pwm_v2_config_s) {
        .clk_source = BFLB_SYSTEM_XCLK,
        .clk_div = 80,
        .period = 1000,
    };

    bflb_pwm_v2_init(pwm, &cfg);

    bflb_pwm_v2_channel_positive_start(pwm, PWM_CH0);
    bflb_pwm_v2_channel_positive_start(pwm, PWM_CH1);
    bflb_pwm_v2_channel_positive_start(pwm, PWM_CH2);

    // 设置初始占空比为0
    pwm_set_duty_cycle(PWM_CH0, 0);
    pwm_set_duty_cycle(PWM_CH1, 0);
    pwm_set_duty_cycle(PWM_CH2, 0);

    bflb_pwm_v2_start(pwm);
}

void pwm_set_duty_cycle(uint8_t ch, uint16_t duty_cycle)
{
    // 确保 duty_cycle 在 0-100 之间
    if (duty_cycle > 100) {
        duty_cycle = 100;
    }

    // 计算低电平和高电平的阈值
    uint16_t threshold_low = (uint16_t)(((float)duty_cycle / 100.0f) * cfg.period);
    uint16_t threshold_high = cfg.period;

    // 设置 PWM 通道的阈值
    bflb_pwm_v2_channel_set_threshold(pwm, ch, threshold_low, threshold_high);
}

// void pwm_task(void *pvParameters)
// {
//     while (1) {
//         // 这里不再自动改变占空比,而是等待蓝牙命令
//         vTaskDelay(pdMS_TO_TICKS(1000)); // 每秒检查一次
//     }
// }

void pwm_task(void *pvParameters) {
    uint16_t duty_cycle = 0;
    int8_t direction = 1;  // 1 表示增加，-1 表示减少

    while (1) {
        // 设置所有三个通道的占空比
        pwm_set_duty_cycle(PWM_CH0, duty_cycle);
        pwm_set_duty_cycle(PWM_CH1, duty_cycle);
        pwm_set_duty_cycle(PWM_CH2, duty_cycle);

        printf("Current duty cycle: %d%%\n", duty_cycle);

        // 更新占空比
        duty_cycle += direction;

        // 检查是否需要改变方向
        if (duty_cycle >= 100) {
            duty_cycle = 100;
            direction = -1;
        } else if (duty_cycle <= 0) {
            duty_cycle = 0;
            direction = 1;
        }

        // 等待一秒
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}