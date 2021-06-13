#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/delay.h>
#include "UART.h"
#include "SPI.h"

ISR(USART_RXC_vect)
{
    char data = UDR; //receive data from UART(blutooth or terminal)
    _delay_us(10);  
    // send data to the another device
    SPI_TREANSMIT(data);  
    
}

int main() {
    //initiate SPI
    SPI_INIT(master, SPI_PS_128);
    //initiate UART
    UART_init(9600);
    //initiate the global interrupt
    sei();
    while (1) {
    }
    return 0;
}

