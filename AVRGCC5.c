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
#include "interrupt_lib.h"
#include <avr/interrupt.h>
#define F_CPU 8000000UL

bool is_button_pressed = false;
bool itr_is_button_pressed = false;

ISR(INT1_vect) 
{
	itr_is_button_pressed = true;
}

int main(void)
{
	led_config();
	button_config();
	external_intr_config();
	sei();
    while(1)
    {
		if (itr_is_button_pressed)
		{
			PORTC |= (1 << PC5);
			itr_is_button_pressed = false;
		}	
		else 
		{
			PORTC &= ~(1 << PC5);
		}
		check_button_pin_status(&is_button_pressed);
		led_func(&is_button_pressed);
    }
}