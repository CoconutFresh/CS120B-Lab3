/*
 * gbers002_bzhan014_lab3_part4.c
 *
 * Created: 1/17/2019 9:00:44 AM
 * Author : Glenn
 */ 

#include <avr/io.h>


int main(void)
{
    DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
	DDRC = 0xFF; PORTC = 0x00;
	unsigned char temp = 0x00;
    while (1) 
    {
		temp = (PINA & 0xF0) >> 4;
		PORTB = PORTB | temp;
		temp = (PINA & 0x0F) << 4;
		PORTC = PORTC | temp;
	}
}

