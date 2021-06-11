#ifndef Transmitter__H
#define	Transmitter__H


void UART_init();
char UART_receive();
void UART_setBaudRate(int BaudRate);
void UART_transmit(char data);


#endif	

