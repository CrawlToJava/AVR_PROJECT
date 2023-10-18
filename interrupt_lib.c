/*
 * interrupt.c
 *
 * Created: 18.10.2023 20:50:39
 *  Author: User
 */ 
#include "interrupt_lib.h"
#include <avr/io.h>
#include <avr/interrupt.h>

void external_intr_config(void) 
{
	/*
	* MCUCR - The MCU Control Register contains control bits for interrupt sense control
	*/
	MCUCR |= (1 << ISC11);
	MCUCR &= ~(1 << ISC10);
	GICR |= (1 << INT1);
	DDRD &= ~(1 << PD3);
	PORTD |= (1 << PD3);
}