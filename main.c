/*
 * PROJECT_FOR_ATMEGA8.c
 *
 * Created: 12.10.2023 22:05:40
 *  Author: User
 */ 

#include <avr/io.h>
#include <avr/delay.h>
#include <avr/interrupt.h>
#include <stdbool.h>

#include "interrupt_lib.h"
#include "timer_config.h"

#define F_CPU 1000000UL;

uint64_t ms_from_tc = 0;

bool external_intr_zero_flag = false;
bool external_intr_one_flag = false;

ISR(INT0_vect) 
{
	external_intr_zero_flag = true;
}

ISR(INT1_vect) 
{
	external_intr_one_flag = true;
}

int main(void)
{
	external_intr_config();
	timer_counter_zero_config();
	timer_counter_one_config();
	sei();
	DDRB |= (1 << PB0);
	PORTB &= ~(1 << PB0);
    while(1)
    {
		OCR1A = 0;
		PORTB &= ~(1 << PB0);
		count_ms_from_tc_zero(&ms_from_tc);
    }
}