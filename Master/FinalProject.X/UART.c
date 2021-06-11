#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h> 
#include "UART.h"
    

void UART_init(int BaudRate){
    UCSRB |= (1<<TXEN)|(1<<RXEN);
    UCSRB |= (1<<RXCIE);
    UART_setBaudRate(BaudRate);
}

void UART_setBaudRate(int BaudRate){
  
    int UBRR = ((F_CPU/16.0)/BaudRate)-1;
    UBRRL = (char) UBRR;
    UBRRH = (UBRR>>8);
}
void UART_transmit(char data){
    while(!(UCSRA & (1<< UDRE)));
    UDR = data;
}

    
char UART_receive(){
    while(!(UCSRA & (1<< RXC)));
    return UDR;
}
