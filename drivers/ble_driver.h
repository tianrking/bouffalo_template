#ifndef BLE_DRIVER_H
#define BLE_DRIVER_H

#include <stdint.h>

void ble_driver_init(void);
void ble_task(void *pvParameters);
void ble_send_log(const char *log_message);

#endif // BLE_DRIVER_H