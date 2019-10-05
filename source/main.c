/*	Author: kma023
 *  Partner(s) Name: none
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) 
{
    DDRA = 0x00; PORTA = 0xFF;
    DDRC = 0xFF; PORTC = 0x00;
   
    unsigned char temp = 0x00;
    unsigned char cntavail = 0x00;
    unsigned char freeSpace = 0x04;

    while (1)
    {
	temp = (PINA & 0x01) + ((PINA >> 0x01) & 0x01) + ((PINA >> 0x02) & 0x01) + ((PINA >> 0x03) & 0x01);
	cntavail = freeSpace - temp;
	if(cntavail == 0)
	{
		PORTC = 0x80;
	}
	else
	{
		PORTC = cntavail;
	}
    }
    return 1;
}
