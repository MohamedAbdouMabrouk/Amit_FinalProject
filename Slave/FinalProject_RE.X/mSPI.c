#include <avr/io.h>
#include "mSPI.h"

void SPI_INIT(int Master_Slave, int PRESCALER) {
    if (Master_Slave) {
        SPCR |= (1 << MSTR);
        SPCR |= (PRESCALER > 3) ? (PRESCALER & 0xFD) : PRESCALER;
        SPCR |= (PRESCALER > 3) ? (1 << SPI2X) : 0;
        //pin config for master 
        DDRB |= (1 << MOSI) | (1 << SCK) | (1 << SS);
    } else {
        SPCR &= ~(1 << MSTR);
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
    while (!(SPSR & (1 << SPIF)));
}

void SPI_TREANSMIT_slave(char slaveSelect , char data) {
    PORTA &= ~(1<<slaveSelect);
    SPDR = data;
    while (!(SPSR & (1 << SPIF)));
    PORTA |= (1<<slaveSelect);
    
}

char SPI_RECIVIER() {
    while (!(SPSR & (1 << SPIF)));

    return SPDR;
}
