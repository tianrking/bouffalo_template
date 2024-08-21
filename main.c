#include <FreeRTOS.h>
#include "task.h" 
#include "timers.h"
#include "board.h"
#include "bflb_mtd.h"
#include "easyflash.h"
#include "shell.h"
#include "rfparam_adapter.h"
#include "led_driver.h"
#include "ble_driver.h"
#include "bflb_gpio.h"
#include "bflb_pwm_v2.h"
#include "bflb_clock.h"
#include "bflb_mtimer.h"
#include "pwm_driver.h"
#include "stepper_motor.h"
#include "wifi_driver.h"

static struct bflb_device_s *uart0;
// static struct bflb_device_s *gpio;

#include <lwip/tcpip.h>
#include <lwip/sockets.h>
#include <lwip/netdb.h>
#include "bl_fw_api.h"
#include "wifi_mgmr_ext.h"
#include "wifi_mgmr.h"
#include "bflb_irq.h"
#include "bflb_uart.h"
#include "bl616_glb.h"
#define DBG_TAG "MAIN"
#include "log.h"

#define WIFI_STACK_SIZE  (500) //  (1536)
#define TASK_PRIORITY_FW (16)

static struct bflb_device_s *uart0;
static TaskHandle_t wifi_fw_task;

static wifi_conf_t conf = {
    .country_code = "CN",
};

// WiFi connection information
static const char *wifi_ssid = "KUNIU";
static const char *wifi_password = "kuniu666";

extern void shell_init_with_task(struct bflb_device_s *shell);

int wifi_start_firmware_task(void)
{
    LOG_I("Starting wifi ...\r\n");

    GLB_PER_Clock_UnGate(GLB_AHB_CLOCK_IP_WIFI_PHY | GLB_AHB_CLOCK_IP_WIFI_MAC_PHY | GLB_AHB_CLOCK_IP_WIFI_PLATFORM);
    GLB_AHB_MCU_Software_Reset(GLB_AHB_MCU_SW_WIFI);

    extern void interrupt0_handler(void);
    bflb_irq_attach(WIFI_IRQn, (irq_callback)interrupt0_handler, NULL);
    bflb_irq_enable(WIFI_IRQn);

    xTaskCreate(wifi_main, (char *)"fw", WIFI_STACK_SIZE, NULL, TASK_PRIORITY_FW, &wifi_fw_task);

    return 0;
}

void wifi_connect_task(void *pvParameters)
{
    wifi_mgmr_sta_connect_params_t connect_params = {0};
    
    // Set up connection parameters
    strncpy((char *)connect_params.ssid, wifi_ssid, sizeof(connect_params.ssid) - 1);
    connect_params.ssid_len = strlen(wifi_ssid);
    strncpy((char *)connect_params.key, wifi_password, sizeof(connect_params.key) - 1);
    connect_params.key_len = strlen(wifi_password);
    connect_params.use_dhcp = 1;
    connect_params.pmf_cfg = 0;  // Disable PMF for older routers
    connect_params.quick_connect = 1;  // Enable quick connect

    while (1) {
        if (wifi_mgmr_sta_state_get() == 0) {  // If not connected
            LOG_I("Connecting to WiFi: %s\r\n", wifi_ssid);
            int ret = wifi_mgmr_sta_connect(&connect_params);
            if (ret != 0) {
                LOG_E("Failed to initiate WiFi connection, error code: %d\r\n", ret);
            }
        } else {
            int state = wifi_mgmr_sta_state_get();
            LOG_I("Current WiFi state: %d\r\n", state);
        }
        vTaskDelay(pdMS_TO_TICKS(5000));  // Check every 5 seconds
    }
}

void wifi_event_handler(uint32_t code)
{
    switch (code) {
        case CODE_WIFI_ON_INIT_DONE: {
            LOG_I("[APP] [EVT] CODE_WIFI_ON_INIT_DONE\r\n");
            wifi_mgmr_init(&conf);
        } break;
        case CODE_WIFI_ON_MGMR_DONE: {
            LOG_I("[APP] [EVT] CODE_WIFI_ON_MGMR_DONE\r\n");
            xTaskCreate(wifi_connect_task, (char *)"wifi_connect", WIFI_STACK_SIZE, NULL, TASK_PRIORITY_FW - 1, NULL);
        } break;
        case CODE_WIFI_ON_SCAN_DONE: {
            LOG_I("[APP] [EVT] CODE_WIFI_ON_SCAN_DONE\r\n");
        } break;
        case CODE_WIFI_ON_CONNECTED: {
            LOG_I("[APP] [EVT] CODE_WIFI_ON_CONNECTED\r\n");
        } break;
        case CODE_WIFI_ON_GOT_IP: {
            LOG_I("[APP] [EVT] CODE_WIFI_ON_GOT_IP\r\n");
            LOG_I("[SYS] Memory left is %d Bytes\r\n", kfree_size());
        } break;
        case CODE_WIFI_ON_DISCONNECT: {
            LOG_I("[APP] [EVT] CODE_WIFI_ON_DISCONNECT\r\n");
        } break;
        default: {
            LOG_I("[APP] [EVT] Unknown code %u \r\n", code);
        }
    }
}

int main(void)
{
    board_init();
    
    uart0 = bflb_device_get_by_name("uart0");
    shell_init_with_task(uart0);
    
    bflb_mtd_init();
    easyflash_init();

    if (0 != rfparam_init(0, NULL, 0)) {
        printf("PHY RF init failed!\n");
        return 0;
    }

    tcpip_init(NULL, NULL);
    wifi_start_firmware_task();

    // Initialize LED driver
    //led_driver_init(); //1 30 0
    
    // Initialize BLE driver 
    ble_driver_init();

    // Create LED task
    //xTaskCreate(led_task, "led_task", 256, NULL, configMAX_PRIORITIES - 3, NULL);

    //Create BLE task
    xTaskCreate(ble_task, "ble_task", 1024, NULL, configMAX_PRIORITIES - 2, NULL);
    
    if (!pwm_driver_init()) {
        LOG_E("PWM driver initialization failed\r\n");
        // while (1) {
        //     // 错误处理
        // }
    }

    if (xTaskCreate(pwm_task, "pwm_task", 512, NULL, configMAX_PRIORITIES - 1, NULL) != pdPASS) {
        LOG_E("Failed to create PWM task\r\n");
        // while (1) {
        //     // 错误处理
        // }
    }

    // gpio = bflb_device_get_by_name("gpio");
    // xTaskCreate(stepper_motor_task, "stepper_motor_task", 256, gpio, configMAX_PRIORITIES - 1, NULL);

    vTaskStartScheduler();

    while (1) {
        // This point should never be reached
    }
}
