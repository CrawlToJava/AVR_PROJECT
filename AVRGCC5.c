/*
 * PROJECT_FOR_ATMEGA8.c
 *
 * Created: 12.10.2023 22:05:40
 *  Author: User
 */ 

#include <avr/io.h>
#include <avr/delay.h>
#include "led.h"
#include "button.h"


bool is_button_pressed = false;

int main(void)
{
	led_config();
	button_config();
    while(1)
    {
		check_button_pin_status(&is_button_pressed);
		led_func(&is_button_pressed);
    }
}