#include <FreeRTOS.h>
#include "task.h"
#include "board.h"
#include "bflb_mtd.h"
#include "easyflash.h"
#include "shell.h"
#include "rfparam_adapter.h"
#include "led_driver.h"
#include "ble_driver.h"

static struct bflb_device_s *uart0;

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

    // Initialize LED driver
    led_driver_init(); //1 30 0
    
    // Initialize BLE driver
    ble_driver_init();

    // Create LED task
    xTaskCreate(led_task, "led_task", 256, NULL, configMAX_PRIORITIES - 3, NULL);

    // Create BLE task
    xTaskCreate(ble_task, "ble_task", 1024, NULL, configMAX_PRIORITIES - 2, NULL);
    
    vTaskStartScheduler();

    while (1) {
        // This point should never be reached
    }
}