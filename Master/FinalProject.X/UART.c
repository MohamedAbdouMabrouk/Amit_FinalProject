#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h> 
#include "UART.h"
    

void UART_init(int BaudRate){\
    // Enable TXEN, RXEN
    UCSRB |= (1<<TXEN)|(1<<RXEN);
    // Enable RX Interrupt
    UCSRB |= (1<<RXCIE);
    //set Baud Rate
    UART_setBaudRate(BaudRate);
}

void UART_setBaudRate(int BaudRate){
    //calculate baud rate
    int UBRR = ((F_CPU/16.0)/BaudRate)-1;
    UBRRL = (char) UBRR;
    UBRRH = (UBRR>>8);
}
void UART_transmit(char data){
    //wait for data
    while(!(UCSRA & (1<< UDRE)));
    UDR = data;
}

    
char UART_receive(){
    //wait for data
    while(!(UCSRA & (1<< RXC)));
    return UDR;
}
