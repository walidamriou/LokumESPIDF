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
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"

// I have used the button A in M5STICKC (GPIO 37 in ESP32) as our restart button 

#define restart_Button 37
#define led 10
#define ESP_INTR_FLAG_DEFAULT 0

xSemaphoreHandle xSemaphore = NULL;
bool led_status = false;

// interrupt service routine, called when the button is pressed
void IRAM_ATTR button_isr_handler(void* arg) {
	
    // notify the button task
	xSemaphoreGiveFromISR(xSemaphore, NULL);
}

// task that will react to button clicks
void button_task(void* arg) {
	
	// infinite loop
	for(;;) {
		
		// wait for the notification from the ISR
		if(xSemaphoreTake(xSemaphore,portMAX_DELAY) == pdTRUE) {
			printf("Button pressed!\n");
            for(int i=0;i>5;i++){
                led_status = !led_status;
			    gpio_set_level(led, led_status);
                vTaskDelay(500 / portTICK_PERIOD_MS); // wait 0.5s   
            }
            			printf("********** Button pressed!\n");

    esp_restart();

		}
	}
}

void app_main()
{
	
	// create the binary semaphore
	xSemaphore = xSemaphoreCreateBinary();
	
	// configure button and led pins as GPIO pins
	gpio_pad_select_gpio(restart_Button);
	gpio_pad_select_gpio(led);
	
	// set the correct direction
	gpio_set_direction(restart_Button, GPIO_MODE_INPUT);
    gpio_set_direction(led, GPIO_MODE_OUTPUT);
	
	// enable interrupt on falling (1->0) edge for button pin
	gpio_set_intr_type(restart_Button, GPIO_INTR_NEGEDGE);
	
	// start the task that will handle the button
	xTaskCreate(button_task, "button_task", 2048, NULL, 10, NULL);
	
	// install ISR service with default configuration
	gpio_install_isr_service(ESP_INTR_FLAG_DEFAULT);
	
	// attach the interrupt service routine
	gpio_isr_handler_add(restart_Button, button_isr_handler, NULL);
}