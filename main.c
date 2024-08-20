#include "bflb_gpio.h"
#include "bflb_mtimer.h"
#include "board.h"

struct bflb_device_s *gpio;

#define LED_RED_PIN   1   // IO1
#define LED_GREEN_PIN 30  // IO30
#define LED_BLUE_PIN  0   // IO0

void gpio_init(void)
{
    gpio = bflb_device_get_by_name("gpio");
    
    // 配置 GPIO 为输出模式
    bflb_gpio_init(gpio, LED_RED_PIN, GPIO_OUTPUT | GPIO_PULLUP | GPIO_SMT_EN | GPIO_DRV_1);
    bflb_gpio_init(gpio, LED_GREEN_PIN, GPIO_OUTPUT | GPIO_PULLUP | GPIO_SMT_EN | GPIO_DRV_1);
    bflb_gpio_init(gpio, LED_BLUE_PIN, GPIO_OUTPUT | GPIO_PULLUP | GPIO_SMT_EN | GPIO_DRV_1);

    // 初始状态设为高电平（LED关闭，假设是共阳极LED）
    bflb_gpio_set(gpio, LED_RED_PIN);
    bflb_gpio_set(gpio, LED_GREEN_PIN);
    bflb_gpio_set(gpio, LED_BLUE_PIN);
}

void set_led_color(uint8_t r, uint8_t g, uint8_t b)
{
    // 假设是共阳极LED，低电平点亮LED
    if (r) bflb_gpio_reset(gpio, LED_RED_PIN); else bflb_gpio_set(gpio, LED_RED_PIN);
    if (g) bflb_gpio_reset(gpio, LED_GREEN_PIN); else bflb_gpio_set(gpio, LED_GREEN_PIN);
    if (b) bflb_gpio_reset(gpio, LED_BLUE_PIN); else bflb_gpio_set(gpio, LED_BLUE_PIN);
}

int main(void)
{
    board_init();
    gpio_init();

    printf("RGB LED GPIO 控制开始\r\n");
    
    while (1) {
        // 红色
        set_led_color(1, 0, 0);
        printf("红色 LED 亮起\r\n");
        bflb_mtimer_delay_ms(2000);
        
        // 绿色
        set_led_color(0, 1, 0);
        printf("绿色 LED 亮起\r\n");
        bflb_mtimer_delay_ms(2000);
        
        // 蓝色
        set_led_color(0, 0, 1);
        printf("蓝色 LED 亮起\r\n");
        bflb_mtimer_delay_ms(2000);
        
        // 白色 (所有 LED 亮起)
        set_led_color(1, 1, 1);
        printf("白色 (所有 LED 亮起)\r\n");
        bflb_mtimer_delay_ms(2000);
        
        // 紫色 (红+蓝)
        set_led_color(1, 0, 1);
        printf("紫色 LED 亮起\r\n");
        bflb_mtimer_delay_ms(2000);
        
        // 黄色 (红+绿)
        set_led_color(1, 1, 0);
        printf("黄色 LED 亮起\r\n");
        bflb_mtimer_delay_ms(2000);
        
        // 青色 (绿+蓝)
        set_led_color(0, 1, 1);
        printf("青色 LED 亮起\r\n");
        bflb_mtimer_delay_ms(2000);
        
        // 关闭所有 LED
        set_led_color(0, 0, 0);
        printf("所有 LED 关闭\r\n");
        bflb_mtimer_delay_ms(2000);
    }
}