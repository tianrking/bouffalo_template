// #include <stdio.h>
// #include <string.h>
// #include "FreeRTOS.h"
// #include "task.h"
// #include "timers.h"

// #include <lwip/tcpip.h>
// #include <lwip/sockets.h>
// #include <lwip/netdb.h>

// #include "bl_fw_api.h"
// #include "wifi_mgmr_ext.h"
// #include "wifi_mgmr.h"

// #include "bflb_irq.h"
// #include "bflb_uart.h"

// #include "bl616_glb.h"
// #include "rfparam_adapter.h"

// #include "board.h"
// #include "shell.h"

// #define DBG_TAG "MAIN"
// #include "log.h"

// #define WIFI_STACK_SIZE  (1536)
// #define TASK_PRIORITY_FW (16)

// static struct bflb_device_s *uart0;
// static TaskHandle_t wifi_fw_task;

// static wifi_conf_t conf = {
//     .country_code = "CN",
// };

// void print_hex(const uint8_t *buf, uint16_t len)
// {
//     for (int i = 0; i < len; i++) {
//         printf("%02X ", buf[i]);
//         if ((i + 1) % 16 == 0) {
//             printf("\n");
//         }
//     }
//     printf("\n");
// }

// void wifi_sniffer_cb(void *env, struct bl_frame_info *frame)
// {
//     printf("RSSI: %d, Length: %d\n", frame->rssi, frame->length);
//     if (frame->payload) {
//         print_hex(frame->payload, frame->length > 64 ? 64 : frame->length);
//     }
//     printf("\n");
// }

// void enable_sniffer_mode()
// {
//     wifi_mgmr_sniffer_item_t sniffer_item = {
//         .itf = "wlan0",
//         .type = 0,  // Primary channel
//         .prim20_freq = 2412,  // Channel 1 frequency
//         .center1_freq = 2412,
//         .center2_freq = 0,
//         .cb = wifi_sniffer_cb,
//         .cb_arg = NULL
//     };

//     if (wifi_mgmr_sniffer_enable(sniffer_item) != 0) {
//         LOG_E("Failed to enable sniffer mode\r\n");
//     } else {
//         LOG_I("Sniffer mode enabled\r\n");
//     }
// }

// void wifi_event_handler(uint32_t code)
// {
//     switch (code) {
//         case CODE_WIFI_ON_INIT_DONE:
//             LOG_I("[APP] [EVT] CODE_WIFI_ON_INIT_DONE\r\n");
//             wifi_mgmr_init(&conf);
//             break;
//         case CODE_WIFI_ON_MGMR_DONE:
//             LOG_I("[APP] [EVT] CODE_WIFI_ON_MGMR_DONE\r\n");
//             enable_sniffer_mode();
//             break;
//         default:
//             LOG_I("[APP] [EVT] Unknown code %u\r\n", code);
//             break;
//     }
// }

// int wifi_start_firmware_task()
// {
//     LOG_I("Starting wifi ...\r\n");

//     GLB_PER_Clock_UnGate(GLB_AHB_CLOCK_IP_WIFI_PHY | GLB_AHB_CLOCK_IP_WIFI_MAC_PHY | GLB_AHB_CLOCK_IP_WIFI_PLATFORM);
//     GLB_AHB_MCU_Software_Reset(GLB_AHB_MCU_SW_WIFI);

//     GLB_Set_EM_Sel(GLB_WRAM160KB_EM0KB);

//     if (0 != rfparam_init(NULL, NULL, NULL)) {
//         LOG_E("PHY RF init failed!\r\n");
//         return 0;
//     }

//     LOG_I("PHY RF init success!\r\n");

//     extern void interrupt0_handler(void);
//     bflb_irq_attach(WIFI_IRQn, (irq_callback)interrupt0_handler, NULL);
//     bflb_irq_enable(WIFI_IRQn);

//     xTaskCreate(wifi_main, (char *)"fw", WIFI_STACK_SIZE, NULL, TASK_PRIORITY_FW, &wifi_fw_task);

//     return 0;
// }

// int main(void)
// {
//     board_init();

//     uart0 = bflb_device_get_by_name("uart0");
//     shell_init_with_task(uart0);

//     tcpip_init(NULL, NULL);
//     wifi_start_firmware_task();

//     vTaskStartScheduler();

//     while (1) {
//     }
// }

// #include <stdio.h>
// #include <string.h>
// #include "FreeRTOS.h"
// #include "task.h"
// #include "timers.h"

// #include <lwip/tcpip.h>
// #include <lwip/sockets.h>
// #include <lwip/netdb.h>

// #include "bl_fw_api.h"
// #include "wifi_mgmr_ext.h"
// #include "wifi_mgmr.h"

// #include "bflb_irq.h"
// #include "bflb_uart.h"

// #include "bl616_glb.h"
// #include "rfparam_adapter.h"

// #include "board.h"
// #include "shell.h"

// #define DBG_TAG "MAIN"
// #include "log.h"

// #define WIFI_STACK_SIZE  (1536)
// #define TASK_PRIORITY_FW (16)

// static struct bflb_device_s *uart0;
// static TaskHandle_t wifi_fw_task;
// static TaskHandle_t sniffer_task;

// static wifi_conf_t conf = {
//     .country_code = "CN",
// };

// void print_hex(const uint8_t *buf, uint16_t len)
// {
//     for (int i = 0; i < len; i++) {
//         printf("%02X ", buf[i]);
//         if ((i + 1) % 16 == 0) {
//             printf("\n");
//         }
//     }
//     printf("\n");
// }

// void wifi_sniffer_cb(void *env, struct bl_frame_info *frame)
// {
//     // Instead of processing here, send a message to sniffer_task
//     // This is to avoid any long processing in interrupt context
//     // Implementation depends on how you want to pass the data
// }

// void sniffer_task_function(void *pvParameters)
// {
//     while (1) {
//         // Process sniffer data here
//         // You might want to use a queue to receive data from wifi_sniffer_cb
//         vTaskDelay(pdMS_TO_TICKS(10));  // Small delay to prevent tight loop
//     }
// }

// void enable_sniffer_mode()
// {
//     wifi_mgmr_sniffer_item_t sniffer_item = {
//         .itf = "wlan0",
//         .type = 0,  // Primary channel
//         .prim20_freq = 2412,  // Channel 1 frequency
//         .center1_freq = 2412,
//         .center2_freq = 0,
//         .cb = wifi_sniffer_cb,
//         .cb_arg = NULL
//     };

//     if (wifi_mgmr_sniffer_enable(sniffer_item) != 0) {
//         LOG_E("Failed to enable sniffer mode\r\n");
//     } else {
//         LOG_I("Sniffer mode enabled\r\n");
//     }
// }

// void wifi_event_handler(uint32_t code)
// {
//     switch (code) {
//         case CODE_WIFI_ON_INIT_DONE:
//             LOG_I("[APP] [EVT] CODE_WIFI_ON_INIT_DONE\r\n");
//             wifi_mgmr_init(&conf);
//             break;
//         case CODE_WIFI_ON_MGMR_DONE:
//             LOG_I("[APP] [EVT] CODE_WIFI_ON_MGMR_DONE\r\n");
//             enable_sniffer_mode();
//             break;
//         default:
//             LOG_I("[APP] [EVT] Unknown code %u\r\n", code);
//             break;
//     }
// }

// int wifi_start_firmware_task()
// {
//     LOG_I("Starting wifi ...\r\n");

//     GLB_PER_Clock_UnGate(GLB_AHB_CLOCK_IP_WIFI_PHY | GLB_AHB_CLOCK_IP_WIFI_MAC_PHY | GLB_AHB_CLOCK_IP_WIFI_PLATFORM);
//     GLB_AHB_MCU_Software_Reset(GLB_AHB_MCU_SW_WIFI);

//     GLB_Set_EM_Sel(GLB_WRAM160KB_EM0KB);

//     if (0 != rfparam_init(NULL, NULL, NULL)) {
//         LOG_E("PHY RF init failed!\r\n");
//         return 0;
//     }

//     LOG_I("PHY RF init success!\r\n");

//     extern void interrupt0_handler(void);
//     bflb_irq_attach(WIFI_IRQn, (irq_callback)interrupt0_handler, NULL);
//     bflb_irq_enable(WIFI_IRQn);

//     xTaskCreate(wifi_main, (char *)"fw", WIFI_STACK_SIZE, NULL, TASK_PRIORITY_FW, &wifi_fw_task);

//     return 0;
// }

// void main_task(void *pvParameters)
// {
//     board_init();

//     uart0 = bflb_device_get_by_name("uart0");
//     shell_init_with_task(uart0);

//     tcpip_init(NULL, NULL);
//     wifi_start_firmware_task();

//     // Create sniffer task
//     xTaskCreate(sniffer_task_function, "sniffer_task", WIFI_STACK_SIZE, NULL, TASK_PRIORITY_FW - 1, &sniffer_task);

//     // Main task can exit now
//     vTaskDelete(NULL);
// }

// int main(void)
// {
//     xTaskCreate(main_task, (char *)"main", WIFI_STACK_SIZE, NULL, TASK_PRIORITY_FW + 1, NULL);
//     vTaskStartScheduler();

//     // We should never get here
//     while (1) {
//         __asm volatile("nop");
//     }
// }

#include <stdio.h>
#include <string.h>
#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"

#include <lwip/tcpip.h>
#include <lwip/sockets.h>
#include <lwip/netdb.h>

#include "bl_fw_api.h"
#include "wifi_mgmr_ext.h"
#include "wifi_mgmr.h"

#include "bflb_irq.h"
#include "bflb_uart.h"

#include "bl616_glb.h"
#include "rfparam_adapter.h"

#include "board.h"
#include "shell.h"

#define DBG_TAG "MAIN"
#include "log.h"

#define WIFI_STACK_SIZE  (1536)
#define TASK_PRIORITY_FW (16)

static struct bflb_device_s *uart0;
static TaskHandle_t wifi_fw_task;

static wifi_conf_t conf = {
    .country_code = "CN",
};

static uint32_t packet_count = 0;

void print_hex(const uint8_t *buf, uint16_t len)
{
    for (int i = 0; i < len; i++) {
        printf("%02X ", buf[i]);
        if ((i + 1) % 16 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}

void wifi_sniffer_cb(void *env, struct bl_frame_info *frame)
{
    packet_count++;
    printf("Packet #%lu - RSSI: %d, Length: %d\n", packet_count, frame->rssi, frame->length);
    if (frame->payload) {
        print_hex(frame->payload, frame->length > 64 ? 64 : frame->length);
    }
    printf("\n");
}

void enable_sniffer_mode()
{
    wifi_mgmr_sniffer_item_t sniffer_item = {
        .itf = "wlan0",
        .type = 0,  // Primary channel
        .prim20_freq = 2412,  // Channel 1 frequency
        .center1_freq = 2412,
        .center2_freq = 0,
        .cb = wifi_sniffer_cb,
        .cb_arg = NULL
    };

    int ret = wifi_mgmr_sniffer_enable(&sniffer_item);
    if (ret != 0) {
        LOG_E("Failed to enable sniffer mode, error code: %d\r\n", ret);
    } else {
        LOG_I("Sniffer mode enabled successfully\r\n");
    }
}

void wifi_event_handler(uint32_t code)
{
    switch (code) {
        case CODE_WIFI_ON_INIT_DONE:
            LOG_I("[APP] [EVT] WiFi initialization done\r\n");
            wifi_mgmr_init(&conf);
            break;
        case CODE_WIFI_ON_MGMR_DONE:
            LOG_I("[APP] [EVT] WiFi manager initialization done\r\n");
            enable_sniffer_mode();
            break;
        default:
            LOG_I("[APP] [EVT] Unknown event code %u\r\n", code);
            break;
    }
}

int wifi_start_firmware_task()
{
    LOG_I("Starting WiFi firmware task...\r\n");

    GLB_PER_Clock_UnGate(GLB_AHB_CLOCK_IP_WIFI_PHY | GLB_AHB_CLOCK_IP_WIFI_MAC_PHY | GLB_AHB_CLOCK_IP_WIFI_PLATFORM);
    GLB_AHB_MCU_Software_Reset(GLB_AHB_MCU_SW_WIFI);

    GLB_Set_EM_Sel(GLB_WRAM160KB_EM0KB);

    if (0 != rfparam_init(NULL, NULL, NULL)) {
        LOG_E("PHY RF initialization failed!\r\n");
        return 0;
    }

    LOG_I("PHY RF initialization successful\r\n");

    extern void interrupt0_handler(void);
    bflb_irq_attach(WIFI_IRQn, (irq_callback)interrupt0_handler, NULL);
    bflb_irq_enable(WIFI_IRQn);

    xTaskCreate(wifi_main, (char *)"fw", WIFI_STACK_SIZE, NULL, TASK_PRIORITY_FW, &wifi_fw_task);

    return 0;
}

void debug_task(void *pvParameters)
{
    TickType_t last_wake_time = xTaskGetTickCount();
    const TickType_t frequency = pdMS_TO_TICKS(5000);  // 5 seconds

    while (1) {
        vTaskDelayUntil(&last_wake_time, frequency);
        LOG_I("Debug: Packets captured in last 5 seconds: %lu\r\n", packet_count);
        packet_count = 0;  // Reset counter
    }
}

int main(void)
{
    board_init();

    uart0 = bflb_device_get_by_name("uart0");
    shell_init_with_task(uart0);

    LOG_I("BL616 WiFi Sniffer starting...\n");

    tcpip_init(NULL, NULL);
    wifi_start_firmware_task();

    xTaskCreate(debug_task, "debug", WIFI_STACK_SIZE, NULL, TASK_PRIORITY_FW - 1, NULL);

    vTaskStartScheduler();

    while (1) {
        __asm volatile("nop");
    }
}