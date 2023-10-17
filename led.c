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
* DDRX - �� ��������� ��������� ��� �� ����/����� (pinMode();)
* PORTX - �� ��������� �������� ���������� 1 ��� 0 �� ��� (digitalWrite();)
* PINX - �� ��������� ������� ������� ������� �� ����� (digitalRead();)
*/
void led_config(void) 
{
	/*
	* DDRX |= (1 << PINX) - ��������� � ���������� ������� pinMode(PINX, 1);
	* DDRX &= ~(1 << PINX) - ����� � 0 pinMode(PINX, 0);
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

