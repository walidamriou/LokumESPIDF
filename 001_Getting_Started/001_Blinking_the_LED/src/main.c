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

// Blinking a led in hardware/embedded world is like hello world in software world
// after " build " and " upload and monitor " you will see the led of your board
// blinking every 1s (1s off and 1.s on)

#include <stdio.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

// M5StickC use GPIO10 in ESP32 chip for its Red LED
#define PIN 10

void app_main(void)
{
  // Pins can have different functions (UART ...), GPIO being one of them. 
  // If we want to manually control or read the pin as an output or input,
  // we use that gpio_pad_select_gpio() to put it in GPIO mode. 
  gpio_pad_select_gpio(PIN);

  // gpio_set_direction to Configure GPIO direction,such as output_only,
  // input_only,output_and_input
  gpio_set_direction(PIN, GPIO_MODE_OUTPUT);
  
  // state of the led, start by off / LOW
  int state = 0;
  while (true)
  {
    // change off to on or vice varsa
    state = !state;

    // GPIO set output level, state is low=0 and state is high=1
    gpio_set_level(PIN, state);

    // portTICK_PERIOD_MS = 10
    // 1000 / portTICK_PERIOD_MS = 100 ticks
    // 100 * 10ms = 1s
    // if you don't know what is ticks in freeRTOS see it at bottom of the code
    vTaskDelay(1000 / portTICK_PERIOD_MS); // 1s    
  }
}

/*
The RTOS tick?
The RTOS tick is a fixed interval periodic interrupt generated form a hardware timer.
It is used to measure real time.   The resolution of time that can be measured is 
dependent on the tick period. For example, if the RTOS tick frequency is set to 1ms 
then time can be measured with an accuracy of 1ms  but there is also an overhead of 
having an interrupt every 1ms.  
*/