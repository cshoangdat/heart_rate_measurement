#include "nrf_drv_twi.h"

#define I2C_SCL_PIN         26
#define I2C_SDA_PIN         27

#define OLED_ADDR           0x3C
#define MAX30102_ADDR	    0x57
#define SI7021_ADDR 	    0x40

#define TWI_ADDRESSES       127

typedef struct
{
    volatile bool m_xfer_done;
    volatile bool readsomething;
    int16_t temperature;
}globalVar_t;

globalVar_t globalVar;

typedef struct
{
    uint32_t aun_ir_buffer[500];        //IR LED sensor data
    uint32_t aun_red_buffer[500]; 
    int32_t n_sp02;                     //SPO2 value
    int8_t ch_spo2_valid;               //indicator to show if the SP02 calculation is valid
    int32_t n_heart_rate;               //heart rate value
    int8_t  ch_hr_valid; 
}max30102Data_t;

max30102Data_t max30102Data;