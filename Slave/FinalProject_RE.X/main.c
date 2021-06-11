#include "SPI.h"
#include "LED.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

ISR(SPI_STC_vect) {
    char data = SPDR;
    _delay_ms(20);
    if (data == 'a') {
        LED0_ON();
    }
    else if (data == 'b') {
        LED0_OFF();
    } else if (data == 'c') {
        LED1_ON();
    } else if (data == 'd') {
        LED1_OFF();
    }
}

int main() {
    LEDs_init();
    SPI_INIT(slave, SPI_PS_128);
    SPI_INTEN();
    sei();
    while (1) {
    }
    return 0;
}
