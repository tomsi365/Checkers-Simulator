#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "project2019b_general.h"
#include "project2019b_qu5.h"
#include "project2019b_bit.h"


//stores current board in a binary file .
void storeBoard(Board board, char* filename) 
{
	BYTE bytes [BOARD_BYTES_SIZE];
	scanBoard(board, bytes, BOARD_BYTES_SIZE);
	FILE* file = fopen(filename, "wb");
	fwrite(bytes, 1, BOARD_BYTES_SIZE, file);
	fclose(file);
}

//scans board cells , and updates the bytes arr .
void scanBoard(Board board, BYTE bytes [], int bytes_size)
{
	int bit_index = 0;
	for (int i = 0;i < BOARDSIZE;i++) 
	{
		for (int j = 0;j < BOARDSIZE;j++)
		{
			int leftBit = 0, rightBit = 0;

			if (board[i][j] == PLAYER1) 
				leftBit = 1, rightBit = 0;
			else if (board[i][j] == PLAYER2)
				leftBit = 0, rightBit = 1;
			else if (board[i][j] == EMPTY)
				leftBit = 0, rightBit = 0;

			writeBit(bit_index % 8, &bytes[bit_index / 8], leftBit);
			bit_index++;
			writeBit(bit_index % 8, &bytes[bit_index / 8], rightBit);
			bit_index++;
		}
	}
}