PROJECT_NAME     := heart_rate_measurement
TARGETS          := nrf52832_xxaa
OUTPUT_DIRECTORY := out

SDK_ROOT := ../../SDK_NRF52/nRF5SDK160098a08e2
PROJ_DIR := ../MCU

$(OUTPUT_DIRECTORY)/$(TARGETS).out: \
	LINKER_SCRIPT  := heart_rate_measurement_gcc_nrf52.ld

# Source files common to all targets
SRC_FILES += \
  $(SDK_ROOT)/modules/nrfx/mdk/gcc_startup_nrf52.S \
  $(SDK_ROOT)/components/libraries/log/src/nrf_log_backend_rtt.c \
  $(SDK_ROOT)/components/libraries/log/src/nrf_log_backend_serial.c \
  $(SDK_ROOT)/components/libraries/log/src/nrf_log_default_backends.c \
  $(SDK_ROOT)/components/libraries/log/src/nrf_log_backend_uart.c \
  $(SDK_ROOT)/components/libraries/log/src/nrf_log_frontend.c \
  $(SDK_ROOT)/components/libraries/log/src/nrf_log_str_formatter.c \
  $(SDK_ROOT)/components/boards/boards.c \
  $(SDK_ROOT)/components/libraries/util/app_error.c \
  $(SDK_ROOT)/components/libraries/util/app_error_handler_gcc.c \
  $(SDK_ROOT)/components/libraries/util/app_error_weak.c \
  $(SDK_ROOT)/components/libraries/scheduler/app_scheduler.c \
  $(SDK_ROOT)/components/libraries/timer/app_timer2.c \
  $(SDK_ROOT)/components/libraries/util/app_util_platform.c \
  $(SDK_ROOT)/components/libraries/util/nrf_assert.c \
  $(SDK_ROOT)/components/libraries/atomic/nrf_atomic.c \
  $(SDK_ROOT)/components/libraries/balloc/nrf_balloc.c \
  $(SDK_ROOT)/external/fprintf/nrf_fprintf.c \
  $(SDK_ROOT)/external/fprintf/nrf_fprintf_format.c \
  $(SDK_ROOT)/components/libraries/memobj/nrf_memobj.c \
  $(SDK_ROOT)/components/libraries/ringbuf/nrf_ringbuf.c \
  $(SDK_ROOT)/components/libraries/strerror/nrf_strerror.c \
  $(SDK_ROOT)/integration/nrfx/legacy/nrf_drv_twi.c \
  $(SDK_ROOT)/integration/nrfx/legacy/nrf_drv_uart.c \
  $(SDK_ROOT)/modules/nrfx/soc/nrfx_atomic.c \
  $(SDK_ROOT)/modules/nrfx/drivers/src/prs/nrfx_prs.c \
  $(SDK_ROOT)/modules/nrfx/drivers/src/nrfx_twi.c \
  $(SDK_ROOT)/modules/nrfx/drivers/src/nrfx_twim.c \
  $(SDK_ROOT)/modules/nrfx/drivers/src/nrfx_uart.c \
  $(SDK_ROOT)/modules/nrfx/drivers/src/nrfx_uarte.c \
  $(SDK_ROOT)/external/segger_rtt/SEGGER_RTT.c \
  $(SDK_ROOT)/external/segger_rtt/SEGGER_RTT_Syscalls_GCC.c \
  $(SDK_ROOT)/external/segger_rtt/SEGGER_RTT_printf.c \
  $(SDK_ROOT)/modules/nrfx/mdk/system_nrf52.c \
  $(SDK_ROOT)/components/libraries/util/app_util_platform.c \
  $(SDK_ROOT)/components/libraries/crc16/crc16.c \
  $(SDK_ROOT)/components/libraries/timer/drv_rtc.c \
  $(SDK_ROOT)/components/libraries/fds/fds.c \
  $(SDK_ROOT)/components/libraries/hardfault/hardfault_implementation.c \
  $(SDK_ROOT)/components/libraries/util/nrf_assert.c \
  $(SDK_ROOT)/components/libraries/atomic_fifo/nrf_atfifo.c \
  $(SDK_ROOT)/components/libraries/atomic_flags/nrf_atflags.c \
  $(SDK_ROOT)/components/libraries/atomic/nrf_atomic.c \
  $(SDK_ROOT)/components/libraries/balloc/nrf_balloc.c \
  $(SDK_ROOT)/external/fprintf/nrf_fprintf.c \
  $(SDK_ROOT)/external/fprintf/nrf_fprintf_format.c \
  $(SDK_ROOT)/components/libraries/fstorage/nrf_fstorage.c \
  $(SDK_ROOT)/components/libraries/fstorage/nrf_fstorage_sd.c \
  $(SDK_ROOT)/components/libraries/memobj/nrf_memobj.c \
  $(SDK_ROOT)/components/libraries/pwr_mgmt/nrf_pwr_mgmt.c \
  $(SDK_ROOT)/components/libraries/ringbuf/nrf_ringbuf.c \
  $(SDK_ROOT)/components/libraries/experimental_section_vars/nrf_section_iter.c \
  $(SDK_ROOT)/components/libraries/sortlist/nrf_sortlist.c \
  $(SDK_ROOT)/components/libraries/sensorsim/sensorsim.c \
  $(SDK_ROOT)/modules/nrfx/mdk/system_nrf52.c \
  $(SDK_ROOT)/components/boards/boards.c \
  $(SDK_ROOT)/integration/nrfx/legacy/nrf_drv_clock.c \
  $(SDK_ROOT)/integration/nrfx/legacy/nrf_drv_uart.c \
  $(SDK_ROOT)/modules/nrfx/soc/nrfx_atomic.c \
  $(SDK_ROOT)/modules/nrfx/drivers/src/nrfx_clock.c \
  $(SDK_ROOT)/modules/nrfx/drivers/src/nrfx_gpiote.c \
  $(SDK_ROOT)/modules/nrfx/drivers/src/prs/nrfx_prs.c \
  $(SDK_ROOT)/modules/nrfx/drivers/src/nrfx_uart.c \
  $(SDK_ROOT)/modules/nrfx/drivers/src/nrfx_uarte.c \
  $(SDK_ROOT)/external/segger_rtt/SEGGER_RTT.c \
  $(SDK_ROOT)/external/segger_rtt/SEGGER_RTT_Syscalls_GCC.c \
  $(SDK_ROOT)/external/segger_rtt/SEGGER_RTT_printf.c \
  $(SDK_ROOT)/components/ble/peer_manager/auth_status_tracker.c \
  $(SDK_ROOT)/components/ble/common/ble_advdata.c \
  $(SDK_ROOT)/components/ble/ble_advertising/ble_advertising.c \
  $(SDK_ROOT)/components/ble/common/ble_conn_params.c \
  $(SDK_ROOT)/components/ble/common/ble_conn_state.c \
  $(SDK_ROOT)/components/ble/common/ble_srv_common.c \
  $(SDK_ROOT)/components/ble/peer_manager/gatt_cache_manager.c \
  $(SDK_ROOT)/components/ble/peer_manager/gatts_cache_manager.c \
  $(SDK_ROOT)/components/ble/peer_manager/id_manager.c \
  $(SDK_ROOT)/components/ble/nrf_ble_gatt/nrf_ble_gatt.c \
  $(SDK_ROOT)/components/ble/nrf_ble_qwr/nrf_ble_qwr.c \
  $(SDK_ROOT)/components/ble/peer_manager/peer_data_storage.c \
  $(SDK_ROOT)/components/ble/peer_manager/peer_database.c \
  $(SDK_ROOT)/components/ble/peer_manager/peer_id.c \
  $(SDK_ROOT)/components/ble/peer_manager/peer_manager.c \
  $(SDK_ROOT)/components/ble/peer_manager/peer_manager_handler.c \
  $(SDK_ROOT)/components/ble/peer_manager/pm_buffer.c \
  $(SDK_ROOT)/components/ble/peer_manager/security_dispatcher.c \
  $(SDK_ROOT)/components/ble/peer_manager/security_manager.c \
  $(SDK_ROOT)/external/utf_converter/utf.c \
	$(SDK_ROOT)/components/softdevice/common/nrf_sdh.c \
	$(SDK_ROOT)/components/softdevice/common/nrf_sdh_ble.c \
	$(SDK_ROOT)/components/softdevice/common/nrf_sdh_soc.c \

# Include folders common to all targets
INC_FOLDERS += \
  $(SDK_ROOT)/components \
  $(SDK_ROOT)/modules/nrfx/mdk \
  $(SDK_ROOT)/components/libraries/strerror \
  $(SDK_ROOT)/components/toolchain/cmsis/include \
  $(SDK_ROOT)/components/libraries/util \
  $(SDK_ROOT)/components/libraries/balloc \
  $(SDK_ROOT)/components/libraries/ringbuf \
  $(SDK_ROOT)/modules/nrfx/hal \
  $(SDK_ROOT)/components/libraries/bsp \
  $(SDK_ROOT)/components/libraries/log \
  $(SDK_ROOT)/modules/nrfx \
  $(SDK_ROOT)/components/libraries/experimental_section_vars \
  $(SDK_ROOT)/integration/nrfx/legacy \
  $(SDK_ROOT)/components/libraries/delay \
  $(SDK_ROOT)/integration/nrfx \
  $(SDK_ROOT)/external/segger_rtt \
  $(SDK_ROOT)/components/boards \
  $(SDK_ROOT)/components/libraries/memobj \
  $(SDK_ROOT)/modules/nrfx/drivers/include \
  $(SDK_ROOT)/components/libraries/log/src \
  $(SDK_ROOT)/external/fprintf \
  $(SDK_ROOT)/components/libraries/atomic \
  $(SDK_ROOT)/components/nfc/ndef/generic/message \
  $(SDK_ROOT)/components/nfc/t2t_lib \
  $(SDK_ROOT)/components/nfc/t4t_parser/hl_detection_procedure \
  $(SDK_ROOT)/components/ble/ble_services/ble_ancs_c \
  $(SDK_ROOT)/components/ble/ble_services/ble_ias_c \
  $(SDK_ROOT)/components/libraries/pwm \
  $(SDK_ROOT)/components/softdevice/s132/headers/nrf52 \
  $(SDK_ROOT)/components/libraries/usbd/class/cdc/acm \
  $(SDK_ROOT)/components/libraries/usbd/class/hid/generic \
  $(SDK_ROOT)/components/libraries/usbd/class/msc \
  $(SDK_ROOT)/components/libraries/usbd/class/hid \
  $(SDK_ROOT)/modules/nrfx/hal \
  $(SDK_ROOT)/components/nfc/ndef/conn_hand_parser/le_oob_rec_parser \
  $(SDK_ROOT)/components/libraries/log \
  $(SDK_ROOT)/components/ble/ble_services/ble_gls \
  $(SDK_ROOT)/components/libraries/fstorage \
  $(SDK_ROOT)/components/nfc/ndef/text \
  $(SDK_ROOT)/components/libraries/mutex \
  $(SDK_ROOT)/components/libraries/gpiote \
  $(SDK_ROOT)/components/libraries/bootloader/ble_dfu \
  $(SDK_ROOT)/components/nfc/ndef/connection_handover/common \
  $(SDK_ROOT)/components/boards \
  $(SDK_ROOT)/components/nfc/ndef/generic/record \
  $(SDK_ROOT)/components/nfc/t4t_parser/cc_file \
  $(SDK_ROOT)/components/ble/ble_advertising \
  $(SDK_ROOT)/external/utf_converter \
  $(SDK_ROOT)/components/ble/ble_services/ble_bas_c \
  $(SDK_ROOT)/modules/nrfx/drivers/include \
  $(SDK_ROOT)/components/libraries/experimental_task_manager \
  $(SDK_ROOT)/components/ble/ble_services/ble_hrs_c \
  $(SDK_ROOT)/components/nfc/ndef/connection_handover/le_oob_rec \
  $(SDK_ROOT)/components/libraries/queue \
  $(SDK_ROOT)/components/libraries/pwr_mgmt \
  $(SDK_ROOT)/components/ble/ble_dtm \
  $(SDK_ROOT)/components/toolchain/cmsis/include \
  $(SDK_ROOT)/components/ble/ble_services/ble_rscs_c \
  $(SDK_ROOT)/components/ble/common \
  $(SDK_ROOT)/components/ble/ble_services/ble_lls \
  $(SDK_ROOT)/components/nfc/platform \
  $(SDK_ROOT)/components/libraries/bsp \
  $(SDK_ROOT)/components/nfc/ndef/connection_handover/ac_rec \
  $(SDK_ROOT)/components/ble/ble_services/ble_bas \
  $(SDK_ROOT)/components/libraries/mpu \
  $(SDK_ROOT)/components/libraries/experimental_section_vars \
  $(SDK_ROOT)/components/softdevice/s132/headers \
  $(SDK_ROOT)/components/ble/ble_services/ble_ans_c \
  $(SDK_ROOT)/components/libraries/slip \
  $(SDK_ROOT)/components/libraries/delay \
  $(SDK_ROOT)/components/libraries/csense_drv \
  $(SDK_ROOT)/components/libraries/memobj \
  $(SDK_ROOT)/components/ble/ble_services/ble_nus_c \
  $(SDK_ROOT)/components/softdevice/common \
  $(SDK_ROOT)/components/ble/ble_services/ble_ias \
  $(SDK_ROOT)/components/libraries/usbd/class/hid/mouse \
  $(SDK_ROOT)/components/libraries/low_power_pwm \
  $(SDK_ROOT)/components/nfc/ndef/conn_hand_parser/ble_oob_advdata_parser \
  $(SDK_ROOT)/components/ble/ble_services/ble_dfu \
  $(SDK_ROOT)/external/fprintf \
  $(SDK_ROOT)/components/libraries/svc \
  $(SDK_ROOT)/components/libraries/atomic \
  $(SDK_ROOT)/components \
  $(SDK_ROOT)/components/libraries/scheduler \
  $(SDK_ROOT)/components/libraries/cli \
  $(SDK_ROOT)/components/ble/ble_services/ble_lbs \
  $(SDK_ROOT)/components/ble/ble_services/ble_hts \
  $(SDK_ROOT)/components/libraries/crc16 \
  $(SDK_ROOT)/components/nfc/t4t_parser/apdu \
  $(SDK_ROOT)/components/libraries/util \
  $(SDK_ROOT)/components/libraries/usbd/class/cdc \
  $(SDK_ROOT)/components/libraries/csense \
  $(SDK_ROOT)/components/libraries/balloc \
  $(SDK_ROOT)/components/libraries/ecc \
  $(SDK_ROOT)/components/libraries/hardfault \
  $(SDK_ROOT)/components/ble/ble_services/ble_cscs \
  $(SDK_ROOT)/components/libraries/hci \
  $(SDK_ROOT)/components/libraries/timer \
  $(SDK_ROOT)/integration/nrfx \
  $(SDK_ROOT)/components/nfc/t4t_parser/tlv \
  $(SDK_ROOT)/components/libraries/sortlist \
  $(SDK_ROOT)/components/libraries/spi_mngr \
  $(SDK_ROOT)/components/libraries/led_softblink \
  $(SDK_ROOT)/components/nfc/ndef/conn_hand_parser \
  $(SDK_ROOT)/components/libraries/sdcard \
  $(SDK_ROOT)/components/nfc/ndef/parser/record \
  $(SDK_ROOT)/modules/nrfx/mdk \
  $(SDK_ROOT)/components/ble/ble_services/ble_cts_c \
  $(SDK_ROOT)/components/ble/ble_services/ble_nus \
  $(SDK_ROOT)/components/libraries/twi_mngr \
  $(SDK_ROOT)/components/ble/ble_services/ble_hids \
  $(SDK_ROOT)/components/libraries/crc32 \
  $(SDK_ROOT)/components/nfc/ndef/connection_handover/ble_oob_advdata \
  $(SDK_ROOT)/components/nfc/t2t_parser \
  $(SDK_ROOT)/components/nfc/ndef/connection_handover/ble_pair_msg \
  $(SDK_ROOT)/components/libraries/usbd/class/audio \
  $(SDK_ROOT)/components/libraries/sensorsim \
  $(SDK_ROOT)/components/nfc/t4t_lib \
  $(SDK_ROOT)/components/ble/peer_manager \
  $(SDK_ROOT)/components/libraries/mem_manager \
  $(SDK_ROOT)/components/libraries/ringbuf \
  $(SDK_ROOT)/components/ble/ble_services/ble_tps \
  $(SDK_ROOT)/components/nfc/ndef/parser/message \
  $(SDK_ROOT)/components/ble/ble_services/ble_dis \
  $(SDK_ROOT)/components/nfc/ndef/uri \
  $(SDK_ROOT)/components/ble/nrf_ble_gatt \
  $(SDK_ROOT)/components/ble/nrf_ble_qwr \
  $(SDK_ROOT)/components/libraries/gfx \
  $(SDK_ROOT)/components/libraries/button \
  $(SDK_ROOT)/modules/nrfx \
  $(SDK_ROOT)/components/libraries/twi_sensor \
  $(SDK_ROOT)/integration/nrfx/legacy \
  $(SDK_ROOT)/components/libraries/usbd/class/hid/kbd \
  $(SDK_ROOT)/components/nfc/ndef/connection_handover/ep_oob_rec \
  $(SDK_ROOT)/external/segger_rtt \
  $(SDK_ROOT)/components/libraries/atomic_fifo \
  $(SDK_ROOT)/components/ble/ble_services/ble_lbs_c \
  $(SDK_ROOT)/components/nfc/ndef/connection_handover/ble_pair_lib \
  $(SDK_ROOT)/components/libraries/crypto \
  $(SDK_ROOT)/components/ble/ble_racp \
  $(SDK_ROOT)/components/libraries/fds \
  $(SDK_ROOT)/components/nfc/ndef/launchapp \
  $(SDK_ROOT)/components/libraries/atomic_flags \
  $(SDK_ROOT)/components/ble/ble_services/ble_hrs \
  $(SDK_ROOT)/components/ble/ble_services/ble_rscs \
  $(SDK_ROOT)/components/nfc/ndef/connection_handover/hs_rec \
  $(SDK_ROOT)/components/libraries/usbd \
  $(SDK_ROOT)/components/nfc/ndef/conn_hand_parser/ac_rec_parser \
  $(SDK_ROOT)/components/libraries/stack_guard \
  $(SDK_ROOT)/components/libraries/log/src \
  $(SDK_ROOT)/components/libraries/timer \

#MCU
INC_FOLDERS += $(PROJ_DIR)
INC_FOLDERS += $(PROJ_DIR)/application
INC_FOLDERS += $(PROJ_DIR)/oled
INC_FOLDERS += $(PROJ_DIR)/oled/lib
INC_FOLDERS += $(PROJ_DIR)/twi
INC_FOLDERS += $(PROJ_DIR)/max30102
INC_FOLDERS += $(PROJ_DIR)/si7021
INC_FOLDERS += $(PROJ_DIR)/ble_app

# Src file prj
SRC_FILES += $(PROJ_DIR)/application/main.c
SRC_FILES += $(PROJ_DIR)/oled/lib/u8g2_bitmap.c
SRC_FILES += $(PROJ_DIR)/oled/lib/u8g2_box.c
SRC_FILES += $(PROJ_DIR)/oled/lib/u8g2_buffer.c
SRC_FILES += $(PROJ_DIR)/oled/lib/u8g2_circle.c
SRC_FILES += $(PROJ_DIR)/oled/lib/u8g2_cleardisplay.c
SRC_FILES += $(PROJ_DIR)/oled/lib/u8g2_d_memory.c
SRC_FILES += $(PROJ_DIR)/oled/lib/u8g2_d_setup.c
SRC_FILES += $(PROJ_DIR)/oled/lib/u8g2_font.c
SRC_FILES += $(PROJ_DIR)/oled/lib/u8g2_fonts.c
SRC_FILES += $(PROJ_DIR)/oled/lib/u8g2_hvline.c
SRC_FILES += $(PROJ_DIR)/oled/lib/u8g2_input_value.c
SRC_FILES += $(PROJ_DIR)/oled/lib/u8g2_intersection.c
SRC_FILES += $(PROJ_DIR)/oled/lib/u8g2_kerning.c
SRC_FILES += $(PROJ_DIR)/oled/lib/u8g2_line.c
SRC_FILES += $(PROJ_DIR)/oled/lib/u8g2_ll_hvline.c
SRC_FILES += $(PROJ_DIR)/oled/lib/u8g2_message.c
SRC_FILES += $(PROJ_DIR)/oled/lib/u8g2_polygon.c
SRC_FILES += $(PROJ_DIR)/oled/lib/u8g2_selection_list.c
SRC_FILES += $(PROJ_DIR)/oled/lib/u8g2_setup.c
SRC_FILES += $(PROJ_DIR)/oled/lib/u8log_u8g2.c
SRC_FILES += $(PROJ_DIR)/oled/lib/u8log_u8x8.c
SRC_FILES += $(PROJ_DIR)/oled/lib/u8log.c
SRC_FILES += $(PROJ_DIR)/oled/lib/u8x8_8x8.c
SRC_FILES += $(PROJ_DIR)/oled/lib/u8x8_byte.c
SRC_FILES += $(PROJ_DIR)/oled/lib/u8x8_cad.c
SRC_FILES += $(PROJ_DIR)/oled/lib/u8x8_capture.c
SRC_FILES += $(PROJ_DIR)/oled/lib/u8x8_d_a2printer.c
SRC_FILES += $(PROJ_DIR)/oled/lib/u8x8_d_il3820_296x128.c
SRC_FILES += $(PROJ_DIR)/oled/lib/u8x8_d_ist3020.c
SRC_FILES += $(PROJ_DIR)/oled/lib/u8x8_d_ist7920.c
SRC_FILES += $(PROJ_DIR)/oled/lib/u8x8_d_ks0108.c
SRC_FILES += $(PROJ_DIR)/oled/lib/u8x8_d_lc7981.c
SRC_FILES += $(PROJ_DIR)/oled/lib/u8x8_d_ld7032_60x32.c
SRC_FILES += $(PROJ_DIR)/oled/lib/u8x8_d_ls013b7dh03.c
SRC_FILES += $(PROJ_DIR)/oled/lib/u8x8_d_max7219.c
SRC_FILES += $(PROJ_DIR)/oled/lib/u8x8_d_pcd8544_84x48.c
SRC_FILES += $(PROJ_DIR)/oled/lib/u8x8_d_pcf8812.c
SRC_FILES += $(PROJ_DIR)/oled/lib/u8x8_d_pcf8814_hx1230.c
SRC_FILES += $(PROJ_DIR)/oled/lib/u8x8_d_s1d15e06.c
SRC_FILES += $(PROJ_DIR)/oled/lib/u8x8_d_sbn1661.c
SRC_FILES += $(PROJ_DIR)/oled/lib/u8x8_d_sed1330.c
SRC_FILES += $(PROJ_DIR)/oled/lib/u8x8_d_sh1106_64x32.c
SRC_FILES += $(PROJ_DIR)/oled/lib/u8x8_d_sh1106_72x40.c
SRC_FILES += $(PROJ_DIR)/oled/lib/u8x8_d_sh1107.c
SRC_FILES += $(PROJ_DIR)/oled/lib/u8x8_d_sh1108.c
SRC_FILES += $(PROJ_DIR)/oled/lib/u8x8_d_sh1122.c
SRC_FILES += $(PROJ_DIR)/oled/lib/u8x8_d_ssd1305.c
SRC_FILES += $(PROJ_DIR)/oled/lib/u8x8_d_ssd1306_48x64.c
SRC_FILES += $(PROJ_DIR)/oled/lib/u8x8_d_ssd1306_64x32.c
SRC_FILES += $(PROJ_DIR)/oled/lib/u8x8_d_ssd1306_64x48.c
SRC_FILES += $(PROJ_DIR)/oled/lib/u8x8_d_ssd1306_72x40.c
SRC_FILES += $(PROJ_DIR)/oled/lib/u8x8_d_ssd1306_96x16.c
SRC_FILES += $(PROJ_DIR)/oled/lib/u8x8_d_ssd1306_128x32.c
SRC_FILES += $(PROJ_DIR)/oled/lib/u8x8_d_ssd1306_128x64_noname.c
SRC_FILES += $(PROJ_DIR)/oled/lib/u8x8_d_ssd1306_2040x16.c
SRC_FILES += $(PROJ_DIR)/oled/lib/u8x8_d_ssd1309.c
SRC_FILES += $(PROJ_DIR)/oled/lib/u8x8_d_ssd1316.c
SRC_FILES += $(PROJ_DIR)/oled/lib/u8x8_d_ssd1317.c
SRC_FILES += $(PROJ_DIR)/oled/lib/u8x8_d_ssd1318.c
SRC_FILES += $(PROJ_DIR)/oled/lib/u8x8_d_ssd1322.c
SRC_FILES += $(PROJ_DIR)/oled/lib/u8x8_d_ssd1325.c
SRC_FILES += $(PROJ_DIR)/oled/lib/u8x8_d_ssd1326.c
SRC_FILES += $(PROJ_DIR)/oled/lib/u8x8_d_ssd1327.c
SRC_FILES += $(PROJ_DIR)/oled/lib/u8x8_d_ssd1329.c
SRC_FILES += $(PROJ_DIR)/oled/lib/u8x8_d_ssd1606_172x72.c
SRC_FILES += $(PROJ_DIR)/oled/lib/u8x8_d_ssd1607_200x200.c
SRC_FILES += $(PROJ_DIR)/oled/lib/u8x8_d_st7511.c
SRC_FILES += $(PROJ_DIR)/oled/lib/u8x8_d_st7528.c
SRC_FILES += $(PROJ_DIR)/oled/lib/u8x8_d_st7565.c
SRC_FILES += $(PROJ_DIR)/oled/lib/u8x8_d_st7567.c
SRC_FILES += $(PROJ_DIR)/oled/lib/u8x8_d_st7571.c
SRC_FILES += $(PROJ_DIR)/oled/lib/u8x8_d_st7586s_erc240160.c
SRC_FILES += $(PROJ_DIR)/oled/lib/u8x8_d_st7586s_s028hn118a.c
SRC_FILES += $(PROJ_DIR)/oled/lib/u8x8_d_st7586s_ymc240160.c
SRC_FILES += $(PROJ_DIR)/oled/lib/u8x8_d_st7588.c
SRC_FILES += $(PROJ_DIR)/oled/lib/u8x8_d_st7920.c
SRC_FILES += $(PROJ_DIR)/oled/lib/u8x8_d_st75256.c
SRC_FILES += $(PROJ_DIR)/oled/lib/u8x8_d_st75320.c
SRC_FILES += $(PROJ_DIR)/oled/lib/u8x8_d_stdio.c
SRC_FILES += $(PROJ_DIR)/oled/lib/u8x8_d_t6963.c
SRC_FILES += $(PROJ_DIR)/oled/lib/u8x8_d_uc1601.c
SRC_FILES += $(PROJ_DIR)/oled/lib/u8x8_d_uc1604.c
SRC_FILES += $(PROJ_DIR)/oled/lib/u8x8_d_uc1608.c
SRC_FILES += $(PROJ_DIR)/oled/lib/u8x8_d_uc1610.c
SRC_FILES += $(PROJ_DIR)/oled/lib/u8x8_d_uc1611.c
SRC_FILES += $(PROJ_DIR)/oled/lib/u8x8_d_uc1617.c
SRC_FILES += $(PROJ_DIR)/oled/lib/u8x8_d_uc1638.c
SRC_FILES += $(PROJ_DIR)/oled/lib/u8x8_d_uc1701_dogs102.c
SRC_FILES += $(PROJ_DIR)/oled/lib/u8x8_d_uc1701_mini12864.c
SRC_FILES += $(PROJ_DIR)/oled/lib/u8x8_debounce.c
SRC_FILES += $(PROJ_DIR)/oled/lib/u8x8_display.c
SRC_FILES += $(PROJ_DIR)/oled/lib/u8x8_fonts.c
SRC_FILES += $(PROJ_DIR)/oled/lib/u8x8_gpio.c
SRC_FILES += $(PROJ_DIR)/oled/lib/u8x8_input_value.c
SRC_FILES += $(PROJ_DIR)/oled/lib/u8x8_message.c
SRC_FILES += $(PROJ_DIR)/oled/lib/u8x8_selection_list.c
SRC_FILES += $(PROJ_DIR)/oled/lib/u8x8_setup.c
SRC_FILES += $(PROJ_DIR)/oled/lib/u8x8_string.c
SRC_FILES += $(PROJ_DIR)/oled/lib/u8x8_u8toa.c
SRC_FILES += $(PROJ_DIR)/oled/lib/u8x8_u16toa.c
SRC_FILES += $(PROJ_DIR)/oled/oled.c
SRC_FILES += $(PROJ_DIR)/twi/twi.c
SRC_FILES += $(PROJ_DIR)/max30102/max30102.c
SRC_FILES += $(PROJ_DIR)/si7021/si7021.c
SRC_FILES += $(PROJ_DIR)/ble_app/ble_template.c

# Libraries common to all targets
LIB_FILES += \

# Optimization flags
OPT = -O3 -g3
# Uncomment the line below to enable link time optimization
#OPT += -flto

# C flags common to all targets
CFLAGS += $(OPT)
CFLAGS += -DAPP_TIMER_V2
CFLAGS += -DAPP_TIMER_V2_RTC1_ENABLED
CFLAGS += -DBOARD_PCA10040
CFLAGS += -DCONFIG_GPIO_AS_PINRESET
CFLAGS += -DFLOAT_ABI_HARD
CFLAGS += -DNRF52
CFLAGS += -DNRF52832_XXAA
CFLAGS += -DNRF52_PAN_74
CFLAGS += -DNRF_SD_BLE_API_VERSION=7
CFLAGS += -DS132
CFLAGS += -DSOFTDEVICE_PRESENT
CFLAGS += -mcpu=cortex-m4
CFLAGS += -mthumb -mabi=aapcs
CFLAGS += -Wall -Werror
CFLAGS += -mfloat-abi=hard -mfpu=fpv4-sp-d16
# keep every function in a separate section, this allows linker to discard unused ones
CFLAGS += -ffunction-sections -fdata-sections -fno-strict-aliasing
CFLAGS += -fno-builtin -fshort-enums

# C++ flags common to all targets
CXXFLAGS += $(OPT)
# Assembler flags common to all targets
ASMFLAGS += -g3
ASMFLAGS += -mcpu=cortex-m4
ASMFLAGS += -mthumb -mabi=aapcs
ASMFLAGS += -mfloat-abi=hard -mfpu=fpv4-sp-d16
ASMFLAGS += -DAPP_TIMER_V2
ASMFLAGS += -DAPP_TIMER_V2_RTC1_ENABLED
ASMFLAGS += -DBOARD_PCA10040
ASMFLAGS += -DCONFIG_GPIO_AS_PINRESET
ASMFLAGS += -DFLOAT_ABI_HARD
ASMFLAGS += -DNRF52
ASMFLAGS += -DNRF52832_XXAA
ASMFLAGS += -DNRF52_PAN_74
ASMFLAGS += -DNRF_SD_BLE_API_VERSION=7
ASMFLAGS += -DS132
ASMFLAGS += -DSOFTDEVICE_PRESENT


# Linker flags
LDFLAGS += $(OPT)
LDFLAGS += -mthumb -mabi=aapcs -L$(SDK_ROOT)/modules/nrfx/mdk -T$(LINKER_SCRIPT)
LDFLAGS += -mcpu=cortex-m4
LDFLAGS += -mfloat-abi=hard -mfpu=fpv4-sp-d16
# let linker dump unused sections
LDFLAGS += -Wl,--gc-sections
# use newlib in nano version
LDFLAGS += --specs=nano.specs

nrf52832_xxaa: CFLAGS += -D__HEAP_SIZE=8192
nrf52832_xxaa: CFLAGS += -D__STACK_SIZE=8192
nrf52832_xxaa: ASMFLAGS += -D__HEAP_SIZE=8192
nrf52832_xxaa: ASMFLAGS += -D__STACK_SIZE=8192

# Add standard libraries at the very end of the linker input, after all objects
# that may need symbols provided by these libraries.
LIB_FILES += -lc -lnosys -lm



.PHONY: default help

# Default target - first one defined
default: nrf52832_xxaa

# Print all targets that can be built
help:
	@echo following targets are available:
	@echo		nrf52832_xxaa
	@echo		sdk_config - starting external tool for editing sdk_config.h
	@echo		flash      - flashing binary

TEMPLATE_PATH := $(SDK_ROOT)/components/toolchain/gcc


include $(TEMPLATE_PATH)/Makefile.common

$(foreach target, $(TARGETS), $(call define_target, $(target)))

.PHONY: flash erase

# Flash the program
flash: default
	@echo Flashing: $(OUTPUT_DIRECTORY)/nrf52832_xxaa.hex
	nrfjprog -f nrf52 --program $(OUTPUT_DIRECTORY)/nrf52832_xxaa.hex --sectorerase
	nrfjprog -f nrf52 --reset

erase:
	nrfjprog -f nrf52 --eraseall

SDK_CONFIG_FILE := $(PROJ_DIR)/application/sdk_config.h
CMSIS_CONFIG_TOOL := $(SDK_ROOT)/external_tools/cmsisconfig/CMSIS_Configuration_Wizard.jar
sdk_config:
	java -jar $(CMSIS_CONFIG_TOOL) $(SDK_CONFIG_FILE)
