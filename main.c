#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <lwip/sockets.h>
#include <lwip/inet.h>
#include <lwip/dns.h>

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

    // Set up the DNS server
    ip4_addr_t dns_server;
    IP4_ADDR(&dns_server, 119, 29, 29, 29);  // Use 119.29.29.29 as the DNS server
    dns_setserver(0, &dns_server);

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
            LOG_I("WiFi connection successful!\r\n");

            if (wifi_mgmr_sta_state_get() != 0) {  // Check if WiFi is connected
                // HTTP client code
                struct hostent *host;
                struct sockaddr_in server_addr;
                int sock, bytes_received;
                char recv_buf[1024] = {0};

                host = gethostbyname("www.baidu.com");
                if (host == NULL) {
                    printf("Failed to resolve Baidu's IP address\n");
                    // Use Baidu's IP address directly
                    server_addr.sin_addr.s_addr = inet_addr("180.97.33.108");
                } else {
                    server_addr.sin_addr.s_addr = *((unsigned long *)host->h_addr);
                }

                if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
                    printf("Failed to create socket\n");
                    vTaskDelay(pdMS_TO_TICKS(10000));
                    continue;
                }

                server_addr.sin_family = AF_INET;
                server_addr.sin_port = htons(80);

                if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
                    printf("Failed to connect to Baidu\n");
                    closesocket(sock);
                    vTaskDelay(pdMS_TO_TICKS(10000));
                    continue;
                }

                printf("Connected to Baidu\n");

                const char *request = "GET / HTTP/1.1\r\nHost: www.baidu.com\r\n\r\n";
                write(sock, request, strlen(request));

                printf("HTTP request sent\n");

                bytes_received = read(sock, recv_buf, sizeof(recv_buf) - 1);
                if (bytes_received > 0) {
                    recv_buf[bytes_received] = '\0';
                    printf("HTTP response:\n%s\n", recv_buf);
                } else {
                    printf("Failed to receive HTTP response\n");
                }

                closesocket(sock);
                printf("HTTP client task finished\n");
            } else {
                LOG_I("WiFi is not connected, skipping HTTP request\r\n");
                vTaskDelay(pdMS_TO_TICKS(10000));
                continue;
            }

            vTaskDelay(pdMS_TO_TICKS(10000));
        }
        vTaskDelay(pdMS_TO_TICKS(10000));
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
            // LOG_I("[APP] [EVT] CODE_WIFI_ON_DISCONNECT\r\n");
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