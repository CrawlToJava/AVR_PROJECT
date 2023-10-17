/*
 * led.c
 *
 * Created: 12.10.2023 22:21:38
 *  Author: User
 */ 
#include "led.h"

#include <avr/io.h> // allow to work with pins
#include <avr/delay.h>


/*
* DDRX - Он позволяет настроить пин на вход/выход (pinMode();)
* PORTX - Он позволяет подавать логическую 1 или 0 на пин (digitalWrite();)
* PINX - Он позволяет считать уровень сигнала на порте (digitalRead();)
*/
void led_config(void) 
{
	/*
	* DDRX |= (1 << PINX) - установка в логическую единицу pinMode(PINX, 1);
	* DDRX &= ~(1 << PINX) - сброс в 0 pinMode(PINX, 0);
	*/
	DDRC |= (1 << LED_PIN) | (1 << PC5);
	PORTC &= ~((1 << LED_PIN) | (1 << PC5));
}

void led_func(bool* is_button_pressed) 
{
	
	if (*(is_button_pressed))
	{
		PORTC |= (1 << LED_PIN);
		*(is_button_pressed) = false;
	}
	else 
	{
		PORTC &= ~(1 << LED_PIN);
	}
}

