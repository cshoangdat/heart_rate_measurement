#ifndef _MAX30102_H_
#define _MAX30102_H_
#include "stdint.h"

void MAX30102_reset (void);

void MAX30102_init (void);

void MAX30102_read_ID (void);

void MAX30102_read_fifo (uint32_t *pun_red_led, uint32_t *pun_ir_led);

void MAX30102_write_register (uint8_t reg_address, uint8_t data);

void MAX30102_read_register (uint8_t reg_address, uint8_t *data);

void MAX30102_checkRange(void);

void MAX30102_read(void);

#endif