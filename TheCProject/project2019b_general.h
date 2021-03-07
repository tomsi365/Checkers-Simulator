#ifndef PROJECT2019B_GENERAL_H
#define PROJECT2019B_GENERAL_H 0X0001

// constants
#define BOARDSIZE 8
#define EMPTY ' '
#define PLAYER1 'B'
#define PLAYER2 'T'
#define TRUE 1
#define FALSE 0
#define LEFT 0
#define RIGHT 1
#define BOARD_BYTES_SIZE  (BOARDSIZE * BOARDSIZE * 2)/8

// type definitions
typedef int BOOL;
typedef unsigned char Player;
typedef unsigned char Board[BOARDSIZE][BOARDSIZE];


// general purpose function prototypes
void checkAllocation(void* node);
int findMax(int val1, int val2);


#endif