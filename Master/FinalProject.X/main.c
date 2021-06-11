#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/delay.h>
#include "UART.h"
#include "SPI.h"

ISR(USART_RXC_vect)
{
    char data = UDR;
    _delay_us(10);  
    SPI_TREANSMIT(data);  
    
}

int main() {
    SPI_INIT(master, SPI_PS_128);
    UART_init(9600);
    sei();
    while (1) {
    }
    return 0;
}

