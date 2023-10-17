/*
 * button.c
 *
 * Created: 16.10.2023 22:10:54
 *  Author: User
 */

#include "button.h"
#include <avr/io.h>
#include <avr/delay.h>

void button_config(void) 
{
	DDRD &= ~(1 << BUTTON_PIN);
	PORTD |= (1 << BUTTON_PIN); 
}

void check_button_pin_status(bool* is_button_pressed) 
{
	if (~PIND & (1 << BUTTON_PIN))
	{
		_delay_ms(50);
		*(is_button_pressed) = true;
	}
}
