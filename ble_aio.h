#ifndef BLE_AIO_H
#define BLE_AIO_H

#include <stdint.h>
#include <stdbool.h>
#include "ble.h"
#include "ble_srv_common.h"
#include "nrf_log.h"
#include "sensor_gpio.h"
// #include "nrf_ble_gatt.h"

#ifdef __cplusplus
extern "C" {
#endif

#define UUID_AUTOMATION_IO_SERVICE       0x1815
#define UUID_DIGITAL_CHARACTERISTIC      0x2A56


uint32_t ble_aio_init();


void ble_aio_on_ble_evt(ble_evt_t * p_ble_evt);

ret_code_t ble_aio_characteristic_digital_add(
    char *description_str, 
    uint8_t number_of_digitals,
    uint8_t description,
    uint8_t is_writable, 
    uint8_t is_notifiable, 
    uint16_t *value_handle,
    uint16_t *cccd_handle
);
void ble_aio_authorize_digital_out();

void ble_aio_on_authorize(ble_evt_t *p_ble_evt);
void encode_states_to_bytes(uint8_t *states, uint32_t state_count, uint8_t *buffer);
uint32_t ble_aio_get_byte_count_from_pins(uint32_t pin_count);

#ifdef __cplusplus
}
#endif

#endif // BLE_AIO_H

/** @} */