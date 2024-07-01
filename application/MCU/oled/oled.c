#include "common.h"
#include "oled.h"
#include <stdio.h>
#include "nrf_delay.h"
#include "nrf_log.h"
#include "nrf_log_ctrl.h"
#include "nrf_log_default_backends.h"
#include "SEGGER_RTT.h"

/* Indicates if operation has ended. */
static u8g2_t u8g2;

static const nrf_drv_twi_t m_twi = NRF_DRV_TWI_INSTANCE(0);

uint8_t u8g2_nrf_gpio_and_delay_twi_cb(u8x8_t *u8x8, uint8_t msg, uint8_t arg_int, void *arg_ptr)
{
    switch(msg)
    {   
        case U8X8_MSG_DELAY_MILLI:
            // NRF_LOG_INFO("nrf_delay_ms(%d)", arg_int);
            nrf_delay_ms(arg_int);
            break;

        case U8X8_MSG_DELAY_10MICRO:
            // NRF_LOG_INFO("nrf_delay_us(%d)", 10*arg_int);
            nrf_delay_us(10*arg_int);
            break;
        
        default:
            u8x8_SetGPIOResult(u8x8, 1); // default return value
            break;  
    }
    return 1;
}

uint8_t u8x8_HW_com_twi_nrf52832(u8x8_t *u8x8, uint8_t msg, uint8_t arg_int, void *arg_ptr)
{
    uint8_t *data;
    //bool res = false;
    ret_code_t err_code;    
    static uint8_t buffer[32];
    static uint8_t buf_idx;
    switch(msg)
    {
      case U8X8_MSG_BYTE_SEND:
      {
            data = (uint8_t *)arg_ptr;      
            while( arg_int > 0 )
            {
              buffer[buf_idx++] = *data;
              data++;
              arg_int--;
            }      
            break;  
      }      
      case U8X8_MSG_BYTE_START_TRANSFER:                    
      {
            buf_idx = 0;            
            globalVar.m_xfer_done = false;
            break;
      }
      case U8X8_MSG_BYTE_END_TRANSFER:
      {            
            //uint8_t addr = u8x8_GetI2CAddress(u8x8);
                       
            err_code = nrf_drv_twi_tx(&m_twi, u8x8_GetI2CAddress(u8x8) , buffer, buf_idx, false);
            APP_ERROR_CHECK(err_code);
            while (!globalVar.m_xfer_done)
            {
                __WFE();
            }
            break;
      }
      default:
            return 0;
    }
    return 1;
}

void u8g2_init(void){        
    u8g2_Setup_sh1106_i2c_128x64_noname_f(&u8g2, U8G2_R0, u8x8_HW_com_twi_nrf52832, u8g2_nrf_gpio_and_delay_twi_cb);    
    u8g2_SetI2CAddress(&u8g2, OLED_ADDR); 
    u8g2_InitDisplay(&u8g2);    
    u8g2_SetPowerSave(&u8g2,0); 
    u8g2_ClearBuffer(&u8g2); 
    globalVar.m_xfer_done = false;
}

void oled_display(int32_t spo2, int32_t heartRate, int16_t temp)
{
        char* spo2_str = (char*)malloc(50*sizeof(char));
        char* heartRate_str = (char*)malloc(50*sizeof(char));
        char* temp_str = (char*)malloc(50*sizeof(char));
        int x= 10;
        int y =10; 
        
        u8g2_SetFont(&u8g2, u8g2_font_ncenB08_tr);

        // u8g2_DrawStr(&u8g2, y, x, "Dung - Thien");
        x = (x+15);
        // Buffer for converting number to string
        sprintf(spo2_str, "SPO2: %li %%", spo2);  // Format number as string
        u8g2_DrawStr(&u8g2, y, x, spo2_str);
        x = (x+15);
        sprintf(heartRate_str, "Heatrate: %li BPM", heartRate);  // Format number as string
        u8g2_DrawStr(&u8g2, y, x, heartRate_str);
        x = (x+15);
        sprintf(temp_str, "Temperature: %i *C", temp);   
        u8g2_DrawStr(&u8g2, y, x, temp_str);
        u8g2_SendBuffer(&u8g2);
        nrf_delay_ms(100);
        u8g2_ClearBuffer(&u8g2);

        free(spo2_str);
        free(heartRate_str);
        free(temp_str);
        globalVar.m_xfer_done = false;
}