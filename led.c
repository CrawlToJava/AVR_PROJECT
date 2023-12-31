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
	DDRC |= (1 << LED_PIN) | (1 << INTR_LED_PIN);
	PORTC &= ~((1 << LED_PIN) | (1 << INTR_LED_PIN));
}

void led_intr_func(bool* itr_is_button_pressed) 
{
	if (*(itr_is_button_pressed))
		{
			PORTC |= (1 << INTR_LED_PIN);
			_delay_ms(1000);
			PORTC &= ~(1 << INTR_LED_PIN);
			_delay_ms(1000);
			PORTC |= (1 << INTR_LED_PIN);
			_delay_ms(1000);
			PORTC &= ~(1 << INTR_LED_PIN);
			*(itr_is_button_pressed) = false;
		} else {
			PORTC &= ~(1 << INTR_LED_PIN);
		}
}

