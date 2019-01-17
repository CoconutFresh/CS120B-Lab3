/*	Glenn Bersabe Email: Gbers002@ucr.edu
 *  Bohan Zhang Email: Bzhan014@ucr.edu
 *	Lab Section: 023
 *	Assignment: Lab 3  Exercise 1
 *	Exercise Description: Checks for 1s in port A and B, port C displays the amount of 1s in binary.
 *	
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */

#include <avr/io.h>


int main(void)
{
    DDRA = 0x00; PORTA = 0x00;
	DDRB = 0x00; PORTB = 0x00;
	DDRC = 0xFF; PORTC = 0x00;
	unsigned char count = 0x00;
    while (1) 
    {
		//PORTC = 0x00;
		PORTA = PINA;
		PORTB = PINB;
		if (count == 0)
		for (unsigned char i = 0; i < 8; i++) {
			if ((PORTA & (0x01 << i)) == (0x01 << i)) {
				count++;
			}
			if ((PORTB & (0x01 << i)) == (0x01 << i)) {
				count++;
			}
		}
		PORTC = count;
    }
}

