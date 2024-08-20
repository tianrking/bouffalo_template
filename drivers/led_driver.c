#include "led_driver.h"
#include "bflb_gpio.h"
#include "bflb_mtimer.h"
#include "FreeRTOS.h"
#include "task.h"

#define LED_RED_PIN   1   // IO1
#define LED_GREEN_PIN 30  // IO30
#define LED_BLUE_PIN  0   // IO0

static struct bflb_device_s *gpio;
static led_state_t current_state = LED_OFF;
static led_color_t current_color = LED_COLOR_RED;

static void set_led_color(uint8_t r, uint8_t g, uint8_t b) {
    if (r) bflb_gpio_reset(gpio, LED_RED_PIN); else bflb_gpio_set(gpio, LED_RED_PIN);
    if (g) bflb_gpio_reset(gpio, LED_GREEN_PIN); else bflb_gpio_set(gpio, LED_GREEN_PIN);
    if (b) bflb_gpio_reset(gpio, LED_BLUE_PIN); else bflb_gpio_set(gpio, LED_BLUE_PIN);
}

void led_driver_init(void) {
    gpio = bflb_device_get_by_name("gpio");
    bflb_gpio_init(gpio, LED_RED_PIN, GPIO_OUTPUT | GPIO_PULLUP | GPIO_SMT_EN | GPIO_DRV_1);
    bflb_gpio_init(gpio, LED_GREEN_PIN, GPIO_OUTPUT | GPIO_PULLUP | GPIO_SMT_EN | GPIO_DRV_1);
    bflb_gpio_init(gpio, LED_BLUE_PIN, GPIO_OUTPUT | GPIO_PULLUP | GPIO_SMT_EN | GPIO_DRV_1);
    set_led_color(0, 0, 0);  // Turn off all LEDs initially
}

void led_set_state(led_state_t state) {
    current_state = state;
}

void led_set_color(led_color_t color) {
    current_color = color;
}

static void apply_current_color(void) {
    switch (current_color) {
        case LED_COLOR_RED:    set_led_color(1, 0, 0); break;
        case LED_COLOR_GREEN:  set_led_color(0, 1, 0); break;
        case LED_COLOR_BLUE:   set_led_color(0, 0, 1); break;
        case LED_COLOR_WHITE:  set_led_color(1, 1, 1); break;
        case LED_COLOR_PURPLE: set_led_color(1, 0, 1); break;
        case LED_COLOR_YELLOW: set_led_color(1, 1, 0); break;
        case LED_COLOR_CYAN:   set_led_color(0, 1, 1); break;
        default:               set_led_color(0, 0, 0); break;
    }
}

void led_task(void *pvParameters) {
    TickType_t xLastWakeTime;
    const TickType_t xFrequency = pdMS_TO_TICKS(100);  // 100ms tick rate

    xLastWakeTime = xTaskGetTickCount();

    while (1) {
        switch (current_state) {
            case LED_OFF:
                set_led_color(0, 0, 0);
                break;
            case LED_ON:
                apply_current_color();
                break;
            case LED_BLINK_SLOW:
                apply_current_color();
                vTaskDelay(pdMS_TO_TICKS(500));
                set_led_color(0, 0, 0);
                break;
            case LED_BLINK_FAST:
                apply_current_color();
                vTaskDelay(pdMS_TO_TICKS(100));
                set_led_color(0, 0, 0);
                break;
        }
        vTaskDelayUntil(&xLastWakeTime, xFrequency);
    }
}