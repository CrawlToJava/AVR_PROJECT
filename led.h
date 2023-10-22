/*
 * led.h
 *
 * Created: 12.10.2023 22:22:11
 *  Author: User
 */ 


#ifndef LED_H_
#define LED_H_
#include <stdbool.h>

#define LED_PIN PC1
#define INTR_LED_PIN PC5

void led_config(void);

void led_intr_func(bool* itr_is_button_pressed);

#endif /* LED_H_ */