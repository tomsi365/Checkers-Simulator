#ifndef PROJECT2019B_BIT_H
#define PROJECT2019B_BIT_H 0X0001

typedef unsigned char BYTE;
#define MASK1  1
void turnOn(int index, BYTE* byte);
void turnOff(int index, BYTE* byte);
int readBit(BYTE* bytes, int bit_index);
void writeBit(int index, BYTE* byte, int value);

#endif