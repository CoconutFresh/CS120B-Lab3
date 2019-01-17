/*
 * gbers002_bzhan014_lab3_part5.c
 *
 * Created: 1/17/2019 9:17:02 AM
 * Author : Glenn
 */ 

#include <avr/io.h>

unsigned char SetBit(unsigned char x, unsigned char k, unsigned char b) {
	return (b ? x | (0x01 << k) : x & ~(0x01 << k));
}


int main(void)
{
    DDRD = 0x00; PORTD = 0xFF;
	DDRB = 0xFE; PORTB = 0x01;
	unsigned char weight = 0x00;
    while (1) 
    {
		weight = (PIND << 1) | (PINB & 0x01);
		
		if (weight >= 70) {
			PORTB = SetBit(PORTB, 1, 1);
			PORTB = SetBit(PORTB, 2, 0);
		}
		else if (weight >= 5) {
			PORTB = SetBit(PORTB, 2, 1);
			PORTB = SetBit(PORTB, 1, 0);
		}
		else {
			PORTB = SetBit(PORTB, 1, 0);
			PORTB = SetBit(PORTB, 2, 0);
		}
    }
}

