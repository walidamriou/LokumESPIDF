/*
 ********************************************************************
  Lokum ESP-IDF
  To Learn using ESP-IDF (Espressif IoT Development Framework) to programming ESP32 boards with small programs examples
  Project Website: LokumESPIDF.walidamriou.com
  Github: https://github.com/walidamriou/LokumESPIDF

  Copyright © 2020 Walid Amriou

  Last update: August 2020
 ********************************************************************
*/

#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include <string.h>

// Miscellaneous system api's is part of esp_system.h
// The full functions here: https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/system/system.html?highlight=esp_chip_info_t

void app_main() {
    vTaskDelay(2000 / portTICK_PERIOD_MS); // wait 2s   
    
    esp_chip_info_t chip_info;
    esp_chip_info(&chip_info);
    int cores = chip_info.cores;
    char text[] = ""; 
    char bluetooth_text[]="/Bluetooth";
    char ble_text[]="/BLE";

    if(true) {
        strcat(text,&bluetooth_text);
    }
    if(true){
        strcat(text,&ble_text);
    } 


    printf("This is ESP32 chip with %d CPU cores, WiFi%s \n",cores,text);

    printf("silicon revision %d, \n", chip_info.revision);

    printf("%dMB %s flash\n", spi_flash_get_chip_size() / (1024 * 1024),
            (chip_info.features & CHIP_FEATURE_EMB_FLASH) ? "embedded" : "external");


}