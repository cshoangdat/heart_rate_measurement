#ifndef _OLED_H_
#define _OLED_H_

#include "u8g2.h"
#include "u8x8.h"
#include <stdio.h>

uint8_t u8g2_nrf_gpio_and_delay_twi_cb(u8x8_t *u8x8, uint8_t msg, uint8_t arg_int, void *arg_ptr);
uint8_t u8x8_HW_com_twi_nrf52832(u8x8_t *u8x8, uint8_t msg, uint8_t arg_int, void *arg_ptr);
void u8g2_init(void);
void oled_display(int32_t spo2, int32_t heartRate, int16_t temp);

#endif