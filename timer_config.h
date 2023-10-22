/*
 * timer_config.h
 *
 * Created: 22.10.2023 11:11:38
 *  Author: User
 */ 


#ifndef TIMER_CONFIG_H_
#define TIMER_CONFIG_H_

#include <stdint.h>

void timer_counter_zero_config(void);

void count_ms_from_tc_zero(uint64_t* ms_from_tc);

#endif /* TIMER_CONFIG_H_ */