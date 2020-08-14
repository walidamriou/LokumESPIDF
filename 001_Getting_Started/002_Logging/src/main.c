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

/* 
In this example, I jave used the second (At runtime).
in this example, We use all verbosity levels so we need to change in CONFIG_LOG_DEFAULT_LEVEL in 
"sdkconfig" file, to VERBOSE level, so edit some lines like that: 
...
# CONFIG_LOG_DEFAULT_LEVEL_NONE is not set
# CONFIG_LOG_DEFAULT_LEVEL_ERROR is not set
# CONFIG_LOG_DEFAULT_LEVEL_WARN is not set
# CONFIG_LOG_DEFAULT_LEVEL_INFO is not set
# CONFIG_LOG_DEFAULT_LEVEL_DEBUG is not set
CONFIG_LOG_DEFAULT_LEVEL_VERBOSE=y
CONFIG_LOG_DEFAULT_LEVEL=5
...

*/

#include <stdio.h>
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

// There are the following verbosity levels:
// Error (lowest), Warning, Info, Debug and Verbose (highest)

// In each C file that uses logging functionality, we need to define the TAG variable
// example: (1194) LOG2: This is Verbose ; TAG help use to see wich code part we get LOG
// We can say that tag like a label of a log
static const char* TAG1 = "LOG1"; 
static const char* TAG2 = "LOG2";

void app_main(void)
{
  // The function esp_log_level_set() cannot set logging levels higher than specified by CONFIG_LOG_DEFAULT_LEVEL. 
  esp_log_level_set(TAG1, ESP_LOG_VERBOSE); // this effect TAG1 and TAG2

  ESP_LOGE(TAG1, "This is an error log");
  ESP_LOGW(TAG1, "This is a warning log");
  ESP_LOGI(TAG1, "This is an info log");
  ESP_LOGD(TAG1, "This is a Debug log");
  ESP_LOGV(TAG1, "This is Verbose log");
  
  // We can print/log numbers with ESP log's
  int i = 0;

  ESP_LOGE(TAG2, "This is an error %d log", i++);
  ESP_LOGW(TAG2, "This is a warning %d log", i++);
  ESP_LOGI(TAG2, "This is an info %d log", i++);
  ESP_LOGD(TAG2, "This is a Debug %d log", i++);
  ESP_LOGV(TAG2, "This is Verbose %d log", i++);
}