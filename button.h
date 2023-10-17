/*
 * button.h
 *
 * Created: 16.10.2023 22:11:06
 *  Author: User
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#include <stdbool.h>
#include <avr/io.h>

#define BUTTON_PIN PD2

void button_config(void);

void check_button_pin_status(bool* is_button_pressed);
#endif /* BUTTON_H_ */