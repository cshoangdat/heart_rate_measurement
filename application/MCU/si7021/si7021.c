#include "si7021.h"
#include "common.h"
#include "SEGGER_RTT.h"
#include <stdlib.h>
#include "nrf_delay.h"

// SI7021 commands
#define MEASURE_RH_HM	0xE9
#define MEASURE_RH_NHM	0xF5
#define MEASURE_T_HM	0xE3
#define MEASURE_T_NHM	0xF3
#define READ_T_PREV_RH	0xE0
#define RESET			0xE9
#define WRITE_RHT_USER	0xE6
#define READ_RHT_USER	0xE7
#define WRITE_HEATER	0x51
#define READ_HEATER		0x11
#define READ_EID_1BYTE	0xFA0F
#define READ_EID_2BYTE	0xFCC9
#define READ_FIRMWARE	0x84B8

// user register masks
#define USER_MASK_VDDS	(1 << 6)
#define USER_MASK_HTRE	(1 << 2)
#define USER_MASK_RES	0x81
#define HEATER_MASK		0x0F

static const nrf_drv_twi_t m_twi = NRF_DRV_TWI_INSTANCE(0);

void si7021_write_register (const uint8_t cmd)
{
    ret_code_t err_code; 

    err_code = nrf_drv_twi_tx(&m_twi, SI7021_ADDR, &cmd, sizeof(cmd), true);
		
    APP_ERROR_CHECK(err_code);
    while (globalVar.m_xfer_done == false);
    globalVar.m_xfer_done = false;
}


void si7021_read_register (uint8_t *data)
{
    ret_code_t err_code;	

    err_code = nrf_drv_twi_rx(&m_twi, SI7021_ADDR, data, sizeof(data));
    APP_ERROR_CHECK(err_code);	
    while (globalVar.m_xfer_done == false);	
    globalVar.m_xfer_done = false;	
	
}

void si7021_read(uint16_t *humidity, int16_t *temperature){
    uint8_t rx[2];
    int32_t data;
    // char* log = (char*) malloc(512*sizeof(char));
    si7021_write_register(MEASURE_RH_NHM);
    nrf_delay_ms(300);
    si7021_read_register(rx);
	data = (uint32_t) ((rx[0] << 8) | rx[1]);
    data = ((data * 1250) >> 16) - 60;
    *humidity = (uint16_t) data;
    if (*humidity > 1000) *humidity = 1000;
    *humidity = (uint16_t) data;
    si7021_write_register(READ_T_PREV_RH);
    nrf_delay_ms(300);
    si7021_read_register(rx);
	data = (int32_t) ((rx[0] << 8) | rx[1]);
	data = ((data * 17572) >> 16) - 4685;
	*temperature = (int16_t) data / 100;

    // sprintf(log, "humid: %i, temp: %i \r\n", *humidity, *temperature, a);
    // SEGGER_RTT_WriteString(0, log); 
    // free(log); 
}

void si7021_init(void){
    si7021_write_register(WRITE_RHT_USER);
}

void si7021_reset(void){
    si7021_write_register(RESET);
}