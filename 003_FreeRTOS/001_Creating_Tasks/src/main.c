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
#include "esp_log.h"
#include "esp_err.h"

static const char* TAG1 = "LOG1"; 

void task_1(void *params){
//const char *Task_output_1 = "Task 1";

while (true){
    //printf(Task_output_1);
    ESP_LOGI(TAG1, "Task 1");
    vTaskDelay(3000 / portTICK_PERIOD_MS);  
}
}

void task_2(void *params){
//const char *Task_output_2 = "Task 2";

while (true){
    //printf(Task_output_2);
    ESP_LOGI(TAG1,"Task 2");
    vTaskDelay(3000 / portTICK_PERIOD_MS);  
}
}

void app_main() {
    vTaskDelay(3000 / portTICK_PERIOD_MS);  

    esp_log_level_set(TAG1, ESP_LOG_VERBOSE); 

    xTaskCreate(&task_1,"Task 1",2048,NULL,1,NULL);
    xTaskCreate(&task_2,"Task 2",2048,NULL,1,NULL);
    //vTaskStartScheduler();

}