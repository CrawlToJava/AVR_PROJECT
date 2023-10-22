/*
 * PROJECT_FOR_ATMEGA8.c
 *
 * Created: 12.10.2023 22:05:40
 *  Author: User
 */ 

#include <avr/io.h>
#include <avr/delay.h>
#include <avr/interrupt.h>

#include "led.h"
#include "button.h"
#include "interrupt_lib.h"
#include "timer_config.h"

#define F_CPU 1000000UL;

uint64_t ms_from_tc = 0;

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
	timer_counter_zero_config();
	sei();
    while(1)
    {
		count_ms_from_tc_zero(&ms_from_tc);
		if(ms_from_tc >= 2000) 
		{
			PORTC |= (1 << PC1);
		} 
		if(ms_from_tc >= 4000) 
		{
			PORTC &= ~(1 << PC1);
			ms_from_tc = 0;
		}
		led_intr_func(&itr_is_button_pressed);
		check_button_pin_status(&is_button_pressed);
    }
}