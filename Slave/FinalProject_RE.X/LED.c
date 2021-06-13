#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h> 
#include "LED.h"

void LEDs_init() {
    //initiate leds
    DDRC |= (1 << LED1) | (1 << LED0);
}

void LED0_ON() {
    PORTC |= (1 << LED0);
}

void LED1_ON() {
    PORTC |= (1 << LED1);
}

void LED0_OFF() {
    PORTC &= ~(1 << LED0);
}

void LED1_OFF() {
    PORTC &= ~(1 << LED1);
}
