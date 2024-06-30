#include "app_error.h"
#include "twi.h"
#include "common.h"
#include "stdlib.h"
#include <stdio.h>
#include "nrf_log.h"
#include "nrf_log_ctrl.h"
#include "nrf_log_default_backends.h"
#include "SEGGER_RTT.h"
#include "app_error.h"

static const nrf_drv_twi_t m_twi = NRF_DRV_TWI_INSTANCE(0);

/**
 * @brief TWI events handler.
 */
static void twi_handler(nrf_drv_twi_evt_t const * p_event, void * p_context)
{
    switch(p_event->type)
    {
        case NRF_DRV_TWI_EVT_ADDRESS_NACK:
        {
            // NRF_LOG_ERROR("Got back NACK");
            globalVar.m_xfer_done = true;            
            break;
        }
        case NRF_DRV_TWI_EVT_DATA_NACK:
        {
            // NRF_LOG_ERROR("Got back D NACK");
            globalVar.m_xfer_done = true;            
            break;
        }        
        case NRF_DRV_TWI_EVT_DONE:
        {
            if (p_event->xfer_desc.type == NRF_DRV_TWI_XFER_RX)
            {
                globalVar.readsomething=true;
            }
            globalVar.m_xfer_done = true;
            break;
        }        
        default:
        {
            globalVar.m_xfer_done = false;
            break;
        }
    }    
}

/**
 * @brief UART initialization.
 */
void twi_init(void)
{
    ret_code_t err_code;

    const nrf_drv_twi_config_t twi_config = {
       .scl                = I2C_SCL_PIN,
       .sda                = I2C_SDA_PIN,
       .frequency          = NRF_DRV_TWI_FREQ_400K,
       .interrupt_priority = APP_IRQ_PRIORITY_HIGH,
       .clear_bus_init     = false,       
    };

    err_code = nrf_drv_twi_init(&m_twi, &twi_config, twi_handler, NULL);    
    APP_ERROR_CHECK(err_code);

    nrf_drv_twi_enable(&m_twi);
}

bool twi_read(uint8_t address, uint8_t * buffer, size_t length)
{
    ret_code_t err_code;
    globalVar.m_xfer_done = false;
    globalVar.readsomething = false;

    err_code = nrf_drv_twi_rx(&m_twi, address, buffer, length);
    if (err_code != NRF_SUCCESS)
    {
        return false;
    }

    while (!globalVar.m_xfer_done)
    {
        __WFE();
    }

    return globalVar.readsomething;
}

bool twi_write(uint8_t address, const uint8_t * buffer, size_t length)
{
    ret_code_t err_code;
    globalVar.m_xfer_done = false;

    err_code = nrf_drv_twi_tx(&m_twi, address, buffer, length, false);
    if (err_code != NRF_SUCCESS)
    {
        return false;
    }

    while (!globalVar.m_xfer_done)
    {
        __WFE();
    }

    return true;
}

void twi_detect(void)
{
    bool detected_device = false;
    uint8_t address, sample;

    for (address = 1; address <= TWI_ADDRESSES; address++)
    {
        if (twi_read(address, &sample, sizeof(sample)))
        {
            detected_device = true;
            // char* log = (char*) malloc(512*sizeof(char));
            // sprintf(log, "TWI device detected at address 0x%x: Read value 0x%02x\n", address, sample);
            // SEGGER_RTT_WriteString(0, log);
            // free(log);
        }
        NRF_LOG_FLUSH();
    }

    if (!detected_device)
    {
        NRF_LOG_INFO("No device was found.");
        NRF_LOG_FLUSH();
        while (true)
        {
            // Do nothing
        }
    }
}