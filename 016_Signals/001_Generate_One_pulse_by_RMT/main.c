

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "driver/rmt.h"

#define M5stickC

#ifdef M5stickC
#include "m5stickc_library/AXP192.h"
#include "m5stickc_library/m5stickc.h"
#include "m5stickc_library/wire.h"
#endif

/*********** Generate one pulse by ESP32 RMT **********/
#define RMT_TX_CHANNEL RMT_CHANNEL_3
#define RMT_TX_GPIO 26

rmt_item32_t items[1];
rmt_config_t config = RMT_DEFAULT_CONFIG_TX(RMT_TX_GPIO, RMT_TX_CHANNEL);

static void walidamriou_one_pulse_generator_rmt_tx_init(void)
{
    rmt_config_t config = RMT_DEFAULT_CONFIG_TX(RMT_TX_GPIO, RMT_TX_CHANNEL);

    config.rmt_mode = RMT_MODE_TX;
    config.channel = RMT_TX_CHANNEL;
    config.gpio_num = RMT_TX_GPIO;
    config.mem_block_num = 1;
    config.tx_config.loop_en = 0;
    config.tx_config.carrier_en = 0;
    config.tx_config.idle_output_en = 0;
    //config.tx_config.idle_level = RMT_IDLE_LEVEL_LOW;
    //config.tx_config.carrier_level = RMT_CARRIER_LEVEL_HIGH;
    //config.tx_config.carrier_duty_percent = 70;
    config.clk_div = 80; 

    ESP_ERROR_CHECK(rmt_config(&config));
    ESP_ERROR_CHECK(rmt_driver_install(config.channel, 0, 0));

    items[0].duration0 = 1000;
    items[0].level0 = 1;
    items[0].duration1 = 1000;
    items[0].level1 = 0; 
}

/*********** ****************************** **********/

void app_main(void *ignore)
{
    #ifdef M5stickC
    M5Init();
    #endif

    walidamriou_one_pulse_generator_rmt_tx_init();
    
    // wait 5 s
    vTaskDelay(5000 / portTICK_PERIOD_MS);
    
    // generate one pulse of 1ms mark and 1ms space
    rmt_write_items(config.channel, items, 1, 1);
    printf("Out RMT\n");

}