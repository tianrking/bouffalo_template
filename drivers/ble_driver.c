#include "ble_driver.h"
#include "bluetooth.h"
#include "conn.h"
#include "conn_internal.h"
#include "btble_lib_api.h"
#include "hci_driver.h"
#include "hci_core.h"
#include "gatt.h"
#include "uuid.h"
#include "led_driver.h"

// Custom Service UUID
#define BT_UUID_CUSTOM_SERVICE BT_UUID_DECLARE_16(0xFFF0)
#define BT_UUID_CUSTOM_CHAR_RX BT_UUID_DECLARE_16(0xFFF1)

static uint8_t rx_value[244] = {0};

static void ble_start_adv(void);

static ssize_t write_rx_value(struct bt_conn *conn, const struct bt_gatt_attr *attr,
                              const void *buf, uint16_t len, uint16_t offset, uint8_t flags)
{
    if (offset + len > sizeof(rx_value)) {
        return BT_GATT_ERR(BT_ATT_ERR_INVALID_OFFSET);
    }

    memcpy(rx_value + offset, buf, len);
    printf("Received data from phone:\n");
    printf("Hex: ");
    for (int i = 0; i < len; i++) {
        printf("%02X ", ((uint8_t *)buf)[i]);
    }
    printf("\nASCII: ");
    for (int i = 0; i < len; i++) {
        char c = ((char *)buf)[i];
        if (c >= 32 && c <= 126) {  // printable ASCII range
            printf("%c", c);
        } else {
            printf(".");
        }
    }
    printf("\n");

    return len;
}

static struct bt_gatt_attr custom_attrs[] = {
    BT_GATT_PRIMARY_SERVICE(BT_UUID_CUSTOM_SERVICE),
    BT_GATT_CHARACTERISTIC(BT_UUID_CUSTOM_CHAR_RX,
                           BT_GATT_CHRC_WRITE | BT_GATT_CHRC_WRITE_WITHOUT_RESP,
                           BT_GATT_PERM_WRITE,
                           NULL, write_rx_value, NULL),
};

static struct bt_gatt_service custom_svc = {
    .attrs = custom_attrs,
    .attr_count = ARRAY_SIZE(custom_attrs),
};

static void ble_connected(struct bt_conn *conn, u8_t err)
{
    if(err || conn->type != BT_CONN_TYPE_LE)
    {
        return;
    }
    printf("Connected\n");
    led_set_state(LED_ON);
    led_set_color(LED_COLOR_GREEN);
}

static void ble_disconnected(struct bt_conn *conn, u8_t reason)
{ 
    if(conn->type != BT_CONN_TYPE_LE)
    {
        return;
    }
    printf("Disconnected (reason %u)\n", reason);
    led_set_state(LED_BLINK_SLOW);
    led_set_color(LED_COLOR_BLUE);
    ble_start_adv();
}

static struct bt_conn_cb ble_conn_callbacks = {
    .connected    = ble_connected,
    .disconnected = ble_disconnected,
};

static void ble_start_adv(void)
{
    int err;
    struct bt_le_adv_param adv_param = {
        .options = BT_LE_ADV_OPT_CONNECTABLE | BT_LE_ADV_OPT_USE_NAME,
        .interval_min = BT_GAP_ADV_FAST_INT_MIN_2,
        .interval_max = BT_GAP_ADV_FAST_INT_MAX_2,
    };
    
    struct bt_data adv_data[] = {
        BT_DATA_BYTES(BT_DATA_FLAGS, (BT_LE_AD_GENERAL | BT_LE_AD_NO_BREDR)),
        BT_DATA_BYTES(BT_DATA_UUID16_ALL, 0xF0, 0xFF),
    };

    err = bt_le_adv_start(&adv_param, adv_data, ARRAY_SIZE(adv_data), NULL, 0);
    if(err) {
        printf("Advertising failed to start (err %d)\n", err);
        return;
    }

    printf("Advertising successfully started\n");
}

static void bt_enable_cb(int err)
{
    if (!err) {
        bt_addr_le_t bt_addr;
        bt_get_local_public_address(&bt_addr);
        printf("BD_ADDR:(MSB)%02x:%02x:%02x:%02x:%02x:%02x(LSB)\n",
               bt_addr.a.val[5], bt_addr.a.val[4], bt_addr.a.val[3],
               bt_addr.a.val[2], bt_addr.a.val[1], bt_addr.a.val[0]);

        bt_conn_cb_register(&ble_conn_callbacks);
        
        err = bt_gatt_service_register(&custom_svc);
        if (err) {
            printf("Service registration failed (err %d)\n", err);
        } else {
            printf("Service registered successfully\n");
        }

        ble_start_adv();
    } else {
        printf("Bluetooth init failed (err %d)\n", err);
    }
}

void ble_driver_init(void)
{
    btble_controller_init(configMAX_PRIORITIES - 1);
    hci_driver_init();
}

void ble_task(void *pvParameters)
{
    int err = bt_enable(bt_enable_cb);
    if (err) {
        printf("Bluetooth init failed (err %d)\n", err);
        led_set_state(LED_BLINK_FAST);
        led_set_color(LED_COLOR_RED);
    } else {
        led_set_state(LED_BLINK_SLOW);
        led_set_color(LED_COLOR_BLUE);
    }

    vTaskDelete(NULL);
}