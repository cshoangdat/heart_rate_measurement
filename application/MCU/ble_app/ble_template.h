#ifndef _BLE_TEMPLATE_H_
#define _BLE_TEMPLATE_H_

#include <stdint.h>
#include "ble.h"
#include "ble_srv_common.h"

typedef struct 
{
	uint16_t service_handle;
	ble_gatts_char_handles_t heartrate_char_handles;
	ble_gatts_char_handles_t temp_char_handles;
	ble_gatts_char_handles_t spo2_char_handles;
	uint8_t uuid_type;
	uint16_t conn_handle;
} ble_lbs_s;

ble_lbs_s ble_lbs_t;

void advertising_start(bool erase_bonds);
void gap_params_init(void);
void gatt_init(void);
void services_init(void);
void conn_params_init();
void advertising_init(void);
void ble_stack_init(void);
void timers_init(void);
void peer_manager_init(void);
uint32_t ble_lbs_on_temp_change(int16_t temp_int);
uint32_t ble_lbs_on_spo2_change(int32_t spo2_int);
uint32_t ble_lbs_on_heartrate_change(int32_t hr);

#endif