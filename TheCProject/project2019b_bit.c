#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "project2019b_general.h"
#include "project2019b_bit.h"

//turns on a single bit , by index .
void turnOn(int index, BYTE* byte)
{
	BYTE MASK = MASK1;
	if (index >= 0 && index <= 7)
	{
		*(byte) = (*(byte) | (MASK << (8 - index - 1)));
	}
}

//turns off a single bit , by index .
void turnOff(int index, BYTE* byte)
{
	BYTE MASK = MASK1;
	if (index >= 0 && index <= 7)
	{
		*(byte) = (*(byte) & ~(MASK << (8 - index - 1)));
	}
}

//turns off/on a single bit , by index .
void writeBit(int index, BYTE* byte, int value)
{
	if (value == 1) 
	{
		turnOn(index, byte);
	}
	if (value == 0)
	{
		turnOff(index, byte);
	}
}

// returns the value at a certain binary index
int readBit(BYTE* bytes, int bit_index)
{
	BYTE MASK = MASK1;
	return (*(bytes) & (MASK << (8 - bit_index - 1)) ? 1 : 0); 
}

