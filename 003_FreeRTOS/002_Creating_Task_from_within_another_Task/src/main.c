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

// if you don't defin the task_2 function here, you will can't create it within task_1 function
void task_2(void *params);

// The function of Task 1 
void task_1(void *params){
    // Create task 2 within task 1 
    xTaskCreate(&task_2,"Task 2",2048,NULL,1,NULL);
    
    // most tasks are implemented in an infinite loop
while (true){
    // we use logging info to see the task text
    ESP_LOGI(TAG1, "Task 1");
    // delay of 3s to print the next text
    // portTICK_PERIOD_MS = 10
    // 3000 / portTICK_PERIOD_MS = 300 ticks
    // 300 * 10ms = 3s
    vTaskDelay(3000 / portTICK_PERIOD_MS);  
}
}

// The function of Task 2
void task_2(void *params){
// most tasks are implemented in an infinite loop
while (true){
    // we use logging info to see the task text
    ESP_LOGI(TAG1,"Task 2");
    // delay of 3s to print the next text
    vTaskDelay(3000 / portTICK_PERIOD_MS);  
}
}

void app_main() {
    // wait 3 s 
    vTaskDelay(3000 / portTICK_PERIOD_MS);  
    // for logging 
    esp_log_level_set(TAG1, ESP_LOG_VERBOSE); 
    // Create Tasks
    // xTaskCreate() should return "pdTRUE" to indicate that the task was created successfully 
    xTaskCreate(&task_1, // pointer to the task function
                "Task 1", // text name for debugging only
                2048, // Stack depth 
                NULL, // We aren't using task parameter here, but in general use it to pass parameters from main to the task function
                1, // priority 1
                NULL // We aren't using the task handle 
               );

    // If you use FreeRTOS with other board (STM32) you will call vTaskStartScheduler() here,
    // but don't call it with ESP32, because this function is called before app_main starts. 
    // In fact, app_main runs within a FreeRTOS task already!

}