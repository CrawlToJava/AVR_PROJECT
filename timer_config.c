/*
 * timer_config.c
 *
 * Created: 22.10.2023 11:12:32
 *  Author: User
 */ 
#include "timer_config.h"
#include <avr/io.h>

void timer_counter_zero_config(void) 
{
	TCCR0 |= (1 << CS02) | (1 << CS00);
	TCCR0 &= ~(1 << CS01);
}

void count_ms_from_tc_zero(uint64_t* ms_from_tc) 
{
	if (TCNT0 == 1)
	{
		(*ms_from_tc)++;
		TCNT0 = 0;
	}
}