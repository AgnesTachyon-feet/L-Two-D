#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
const int seven_seg_pins[7] = {GPIO_NUM_23, GPIO_NUM_22,GPIO_NUM_1,GPIO_NUM_3, GPIO_NUM_21, GPIO_NUM_19, GPIO_NUM_18};
void setup(void)
{
    for(int i=0;i<7;i++)
    {
        gpio_reset_pin(seven_seg_pins[i]);
        gpio_set_direction(seven_seg_pins[i], GPIO_MODE_OUTPUT);
    }
}

void display(int status, int delay)
{
    for(int i=0;i<7;i++)
    {
        gpio_set_level((gpio_num_t)seven_seg_pins[i], status);
    }
    vTaskDelay(delay);
}

void app_main(void)
{
    setup();
    while(1){
        display(1, 1000 / portTICK_PERIOD_MS);
        display(2, 1000 / portTICK_PERIOD_MS);
    }
}
