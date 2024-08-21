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

#define AP_STACK_SIZE  (1536)
#define TASK_PRIORITY_AP (16)

static struct bflb_device_s *uart0;
static TaskHandle_t ap_task_handle;

static wifi_conf_t conf = {
    .country_code = "CN",
};

// AP configuration
static const char *ap_ssid = "MyWiFiAP";
static const char *ap_password = "myappassword";
static const int ap_channel = 6;

extern void shell_init_with_task(struct bflb_device_s *shell);

int wifi_start_firmware_task(void)
{
    LOG_I("Starting wifi ...\r\n");

    GLB_PER_Clock_UnGate(GLB_AHB_CLOCK_IP_WIFI_PHY | GLB_AHB_CLOCK_IP_WIFI_MAC_PHY | GLB_AHB_CLOCK_IP_WIFI_PLATFORM);
    GLB_AHB_MCU_Software_Reset(GLB_AHB_MCU_SW_WIFI);

    extern void interrupt0_handler(void);
    bflb_irq_attach(WIFI_IRQn, (irq_callback)interrupt0_handler, NULL);
    bflb_irq_enable(WIFI_IRQn);

    xTaskCreate(wifi_main, (char *)"fw", AP_STACK_SIZE, NULL, TASK_PRIORITY_AP, &ap_task_handle);

    return 0;
}

void ap_task(void *pvParameters)
{
    wifi_mgmr_ap_params_t ap_params = {
        .ssid = ap_ssid,
        .key = ap_password,
        .channel = ap_channel,
        .use_dhcpd = true,
        .ap_max_inactivity = 300, // 5 minutes inactivity timeout
    };
    
    while (1) {
        if (wifi_mgmr_ap_state_get() == 0) {  // If AP is not started
            LOG_I("Starting AP: %s\r\n", ap_ssid);
            int ret = wifi_mgmr_ap_start(&ap_params);
            if (ret != 0) {
                LOG_E("Failed to start AP, error code: %d\r\n", ret);
            }
        } else {
            // AP is running, you can add periodic checks or management tasks here
            uint8_t sta_count = 0;
            struct wifi_sta_basic_info sta_info;
            
            for (int i = 0; i < 4; i++) {  // Assuming max 4 stations, adjust as needed
                if (wifi_mgmr_ap_sta_info_get(&sta_info, i) == 0) {
                    sta_count++;
                    LOG_I("STA %d connected, MAC: %02X:%02X:%02X:%02X:%02X:%02X\r\n", 
                          i, sta_info.sta_mac[0], sta_info.sta_mac[1], sta_info.sta_mac[2],
                          sta_info.sta_mac[3], sta_info.sta_mac[4], sta_info.sta_mac[5]);
                }
            }
            LOG_I("Total connected stations: %d\r\n", sta_count);
        }
        vTaskDelay(pdMS_TO_TICKS(10000));  // Check every 10 seconds
    }
}

void wifi_event_handler(uint32_t code)
{
    switch (code) {
        case CODE_WIFI_ON_INIT_DONE:
            LOG_I("[APP] [EVT] CODE_WIFI_ON_INIT_DONE\r\n");
            wifi_mgmr_init(&conf);
            break;
        case CODE_WIFI_ON_MGMR_DONE:
            LOG_I("[APP] [EVT] CODE_WIFI_ON_MGMR_DONE\r\n");
            xTaskCreate(ap_task, (char *)"ap_task", AP_STACK_SIZE, NULL, TASK_PRIORITY_AP - 1, NULL);
            break;
        case CODE_WIFI_ON_AP_STARTED:
            LOG_I("[APP] [EVT] CODE_WIFI_ON_AP_STARTED\r\n");
            break;
        case CODE_WIFI_ON_AP_STOPPED:
            LOG_I("[APP] [EVT] CODE_WIFI_ON_AP_STOPPED\r\n");
            break;
        case CODE_WIFI_ON_AP_STA_ADD:
            LOG_I("[APP] [EVT] CODE_WIFI_ON_AP_STA_ADD\r\n");
            break;
        case CODE_WIFI_ON_AP_STA_DEL:
            LOG_I("[APP] [EVT] CODE_WIFI_ON_AP_STA_DEL\r\n");
            break;
        default:
            LOG_I("[APP] [EVT] Unknown code %u \r\n", code);
    }
}

int main(void)
{
    board_init();

    uart0 = bflb_device_get_by_name("uart0");
    shell_init_with_task(uart0);

    if (0 != rfparam_init(0, NULL, 0)) {
        LOG_E("PHY RF init failed!\r\n");
        return 0;
    }

    LOG_I("PHY RF init success!\r\n");

    tcpip_init(NULL, NULL);
    wifi_start_firmware_task();

    vTaskStartScheduler();

    while (1) {
        bflb_mtimer_delay_ms(100);
    }
}