/*
 * interrupt.c
 *
 * Created: 18.10.2023 20:50:39
 *  Author: User
 */ 
#include "interrupt_lib.h"
#include <avr/io.h>
#include <avr/interrupt.h>

static void external_intr_zero_config(void) 
{
	/*
	* MCUCR - The MCU Control Register contains control bits for interrupt sense control
	*/
	MCUCR |= (1 << ISC01);
	MCUCR &= ~(1 << ISC00);
	GICR |= (1 << INT0);
	DDRD &= ~(1 << EXT_INTR_PIN_ZERO);
	PORTD |= (1 << EXT_INTR_PIN_ZERO);
}

static void external_intr_one_config(void) 
{
	/*
	* MCUCR - The MCU Control Register contains control bits for interrupt sense control
	*/
	MCUCR |= (1 << ISC11);
	MCUCR &= ~(1 << ISC10);
	GICR |= (1 << INT1);
	DDRD &= ~(1 << EXT_INTR_PIN_ONE);
	PORTD |= (1 << EXT_INTR_PIN_ONE);
}

void external_intr_config(void) 
{
	external_intr_zero_config();
	external_intr_one_config();
}