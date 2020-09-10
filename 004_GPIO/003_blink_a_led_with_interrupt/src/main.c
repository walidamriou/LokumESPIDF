/*
 ********************************************************************
  Lokum ESP-IDF
  To Learn using ESP-IDF (Espressif IoT Development Framework) to programming ESP32 boards with small programs examples
  Project Website: LokumESPIDF.walidamriou.com
  Github: https://github.com/walidamriou/LokumESPIDF
  Copyright © 2020 Walid Amriou
  Last update: September 2020
 ********************************************************************
*/

#include <stdio.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

// M5StickC use GPIO10 in ESP32 chip for its Red LED
#define CONFIG_LED_PIN 10
#define ESP_INTR_FLAG_DEFAULT 0
// M5StickC use GPIO37 in ESP32 chip for its A button (M5 button)
#define CONFIG_BUTTON_PIN 37

TaskHandle_t ISR = NULL;

// interrupt service routine, called when the button is pressed
void IRAM_ATTR button_isr_handler(void* arg) {
  
 xTaskResumeFromISR(ISR);
//portYIELD_FROM_ISR(  );
}

// task that will react to button clicks
 void button_task(void *arg)
{
bool led_status = false;
 while(1){  
vTaskSuspend(NULL);
      led_status = !led_status;
      gpio_set_level(CONFIG_LED_PIN, led_status);
printf("Button pressed!!!\n");
 }
}

void app_main()
{
  gpio_pad_select_gpio(CONFIG_BUTTON_PIN);
  gpio_pad_select_gpio(CONFIG_LED_PIN);
  
  // set the correct direction
  gpio_set_direction(CONFIG_BUTTON_PIN, GPIO_MODE_INPUT);
  gpio_set_direction(CONFIG_LED_PIN, GPIO_MODE_OUTPUT);
  
  // enable interrupt on falling (1->0) edge for button pin
  gpio_set_intr_type(CONFIG_BUTTON_PIN, GPIO_INTR_NEGEDGE);

  // Install the driver’s GPIO ISR handler service, which allows per-pin GPIO interrupt handlers.
  // install ISR service with default configuration
  gpio_install_isr_service(ESP_INTR_FLAG_DEFAULT);
  
  // attach the interrupt service routine
  gpio_isr_handler_add(CONFIG_BUTTON_PIN, button_isr_handler, NULL);
  
  //Create and start stats task

  xTaskCreate( button_task, "button_task", 4096, NULL , 10,&ISR );
}
