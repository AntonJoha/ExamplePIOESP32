#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "driver/gpio.h"


#define ESP_INTR_FLAG_DEFAULT 0

static xQueueHandle gpio_evt_queue = NULL;

static void task_example(void* arg)
{
    uint32_t io_num;
    for(;;) {
        if(xQueueReceive(gpio_evt_queue, &io_num, portMAX_DELAY)) {
            printf("GPIO[%u] intr, val: %d\n", io_num, gpio_get_level(io_num));
        }
    }
}


void gpio_test(){


	//Output
	gpio_config_t io_conf = {};
	io_conf.intr_type = GPIO_INTR_DISABLE;
	io_conf.mode = GPIO_MODE_OUTPUT;
	io_conf.pin_bit_mask = GPIO_SEL_25;
	io_conf.pull_down_en = 0;
	io_conf.pull_up_en = 0;
	gpio_config(&io_conf);
	
	//Input
	io_conf.intr_type = GPIO_INTR_POSEDGE;
	io_conf.pin_bit_mask = GPIO_SEL_14;
	io_conf.mode = GPIO_MODE_INPUT;
	io_conf.pull_up_en = 1;
	gpio_config(&io_conf);
	
	gpio_evt_queue = xQueueCreate(10, sizeof(uint32_t));
	
	xTaskCreate(task_example, "task_example", 2048, NULL, 10, NULL);


	gpio_install_isr_service(ESP_INTR_FLAG_DEFAULT);
		
}
