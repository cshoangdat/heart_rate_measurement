#include <stdio.h>
#include "boards.h"
#include "app_util_platform.h"
#include "app_error.h"
#include "SEGGER_RTT.h"

#include "nrf_delay.h"
#include "app_timer.h"
#include "nrf_drv_timer.h"
#include "nrf_drv_rng.h"
#include "nrf_delay.h"
#include "nrf_drv_clock.h"
#include "nrf_nvmc.h"

#include "nrf_log.h"
#include "nrf_log_ctrl.h"
#include "nrf_log_default_backends.h"

#include "twi.h"
#include "oled.h"
#include "max30102.h"
#include "common.h"
#include "si7021.h"
#include "ble_template.h"

// APP_TIMER_DEF(m_repeated_timer_id); 

void init_timer(){
    ret_code_t ret;
    ret = app_timer_init();
    APP_ERROR_CHECK(ret);
    // ret = app_timer_create(&m_repeated_timer_id,
    //                             APP_TIMER_MODE_REPEATED,
    //                             NULL);
    // APP_ERROR_CHECK(ret);

}

int main(void)
{
    uint16_t humiditity = 0;
    // int16_t temp = 0;
    int32_t spo2 = 0;
    int32_t hr = 0;
    globalVar.temperature = 30;
    APP_ERROR_CHECK(NRF_LOG_INIT(NULL));
    NRF_LOG_DEFAULT_BACKENDS_INIT(); 

    init_timer();

    ble_stack_init();
    gap_params_init();
    gatt_init();
    services_init();
    advertising_init();
    conn_params_init();
    peer_manager_init(); 

    advertising_start(true);

    twi_init();
    twi_detect();
    u8g2_init();
    MAX30102_read_ID();
    MAX30102_reset();
    MAX30102_init();
    MAX30102_checkRange();
    si7021_reset();
    si7021_init();
    
    while (true)
    {
        MAX30102_read();
        if(max30102Data.ch_spo2_valid != 0){
            spo2 = max30102Data.n_sp02;

        }
        if(max30102Data.ch_hr_valid){
            hr = max30102Data.n_heart_rate;
        }
        si7021_read(&humiditity, &globalVar.temperature);
        oled_display(spo2, hr, globalVar.temperature);
        nrf_delay_ms(1000);
        ble_lbs_on_temp_change(globalVar.temperature);
        nrf_delay_ms(1000); 
        ble_lbs_on_spo2_change(spo2);
        nrf_delay_ms(1000); 
        ble_lbs_on_heartrate_change(hr);
        nrf_delay_ms(1000); 
    }
}