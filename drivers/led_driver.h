#ifndef LED_DRIVER_H
#define LED_DRIVER_H

#include <stdint.h>

// LED states
typedef enum {
    LED_OFF,
    LED_ON,
    LED_BLINK_SLOW,
    LED_BLINK_FAST
} led_state_t;

// LED colors
typedef enum {
    LED_COLOR_RED,
    LED_COLOR_GREEN,
    LED_COLOR_BLUE,
    LED_COLOR_WHITE,
    LED_COLOR_PURPLE,
    LED_COLOR_YELLOW,
    LED_COLOR_CYAN
} led_color_t;

void led_driver_init(void);
void led_set_state(led_state_t state);
void led_set_color(led_color_t color);
void led_task(void *pvParameters);

#endif // LED_DRIVER_H