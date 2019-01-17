/*	Glenn Bersabe Email: Gbers002@ucr.edu
 *  Bohan Zhang Email: Bzhan014@ucr.edu
 *	Lab Section: 023
 *	Assignment: Lab 3  Exercise 3
 *	Exercise Description: 
 *	
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */

#include <avr/io.h>

unsigned char GetBit(unsigned char x, unsigned char k) {
	return ((x & (0x01 << k)) != 0);
}

unsigned char SetBit(unsigned char x, unsigned char k, unsigned char b) {
	return (b ? x | (0x01 << k) : x & ~(0x01 << k));
}


int main(void)
{
	DDRA = 0x00; PORTA = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;
	unsigned char count = 0x00;
	
    while (1) 
    {
			count = 0x00;
			
				if (PINA >= 13) {
					PORTC = SetBit(PORTC, 0, 1);
				}
				if (PINA >= 10) {
					PORTC = SetBit(PORTC, 1, 1);
				}
				if (PINA >= 7) {
					PORTC = SetBit(PORTC, 2, 1);
				}
				if (PINA >= 5) {
					PORTC = SetBit(PORTC, 3, 1);
				}
				if (PINA >= 3) {
					PORTC = SetBit(PORTC, 4, 1);
				}
				if (PINA >= 1) {
					PORTC = SetBit(PORTC, 5, 1);
				}
			
			
			for (unsigned char i = 4; i < 7; i++) {
				if (GetBit(PINA, i) == 0x01) {
					count++;
				}
			}
			if (count == 2) {
				PORTC = PORTC | 0x80;
			}

	}
}

