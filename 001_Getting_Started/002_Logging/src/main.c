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

// The logging library provides two ways for setting log verbosity:
// ** At compile time: in menuconfig, set the verbosity level using the option CONFIG_LOG_DEFAULT_LEVEL. 
// All logging statements for verbosity levels higher than CONFIG_LOG_DEFAULT_LEVEL will be removed 
// by the preprocessor.
// ** At runtime: all logs for verbosity levels lower than CONFIG_LOG_DEFAULT_LEVEL are enabled by default.
// The function esp_log_level_set() can be used to set a logging level on a per module basis. Modules are 
// identified by their tags, which are human-readable ASCII zero-terminated strings.

// In this example, I jave used the second (At runtime).

#include <stdio.h>
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

// There are the following verbosity levels:
// Error (lowest), Warning, Info, Debug and Verbose (highest)

// In each C file that uses logging functionality, we need to define the TAG variable
static const char* TAG1 = "LOG1";
static const char* TAG2 = "LOG2";

void app_main(void)
{
  vTaskDelay(2000 / portTICK_PERIOD_MS); // 1s    

  // The function esp_log_level_set() cannot set logging levels higher than specified by CONFIG_LOG_DEFAULT_LEVEL. 
  esp_log_level_set(TAG1, ESP_LOG_VERBOSE);

  vTaskDelay(500 / portTICK_PERIOD_MS); // 1s    
  ESP_LOGE(TAG1, "This is an error");
  vTaskDelay(500 / portTICK_PERIOD_MS); // 1s    
  ESP_LOGW(TAG1, "This is a warning");
  vTaskDelay(500 / portTICK_PERIOD_MS); // 1s    
  ESP_LOGI(TAG1, "This is an info");
  vTaskDelay(500 / portTICK_PERIOD_MS); // 1s    
  ESP_LOGD(TAG1, "This is a Debug");
  vTaskDelay(500 / portTICK_PERIOD_MS); // 1s    
  ESP_LOGV(TAG1, "This is Verbose");

  int number = 0;
  vTaskDelay(500 / portTICK_PERIOD_MS); // 1s    

  ESP_LOGE(TAG2, "This is an error %d", number++);
  vTaskDelay(500 / portTICK_PERIOD_MS); // 1s    

  ESP_LOGW(TAG2, "This is a warning %d", number++);
  vTaskDelay(500 / portTICK_PERIOD_MS); // 1s    

  ESP_LOGI(TAG2, "This is an info %d", number++);
  vTaskDelay(500 / portTICK_PERIOD_MS); // 1s    

  ESP_LOGD(TAG2, "This is a Debug %d", number++);
  vTaskDelay(500 / portTICK_PERIOD_MS); // 1s    

  ESP_LOGV(TAG2, "This is Verbose %d", number++);
}