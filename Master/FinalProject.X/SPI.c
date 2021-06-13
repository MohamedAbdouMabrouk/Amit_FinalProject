#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h> 
#include "SPI.h"

void SPI_INIT(int Master_Slave, int PRESCALER) {
    if (Master_Slave) {
        SPCR |= (1 << MSTR);
        SPCR |= (1<<0)|(1<<1);
        //pin config for master 
        DDRB |= (1 << MOSI) | (1 << SCK) | (1 << SS);
    } else {  
        // pin config for Slave
        DDRB |= (1 << MISO);
    }
    SPCR |= (1 << SPE);
}

void SPI_INTEN()
{
    SPCR |= (1 << SPIE);
}

void SPI_TREANSMIT(char data) {
    SPDR = data;
    //wait for data
    while (!(SPSR & (1 << SPIF)));
}

