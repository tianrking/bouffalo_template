// #ifndef WIFI_DRIVER_H
// #define WIFI_DRIVER_H

// #include <stdint.h>

// // WiFi connection states
// typedef enum {
//     WIFI_STATE_DISCONNECTED,
//     WIFI_STATE_CONNECTING,
//     WIFI_STATE_CONNECTED,
//     WIFI_STATE_GOT_IP
// } wifi_state_t;

// // Function prototypes
// void wifi_driver_init(void);
// int wifi_driver_connect(const char *ssid, const char *password);
// wifi_state_t wifi_driver_get_state(void);
// void wifi_driver_disconnect(void);

// // Declare the wifi_event_handler function
// void wifi_event_handler(uint32_t code);

// #endif // WIFI_DRIVER_H