#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "project2019b_general.h"
#include "project2019b_bit.h"
#include "project2019b_qu6.h"

// reads board from file
void LoadBoard(char* filename, Board board)
{
	BYTE bytes[BOARD_BYTES_SIZE];
	FILE* file = fopen(filename, "rb");
	fread(bytes, 1, BOARD_BYTES_SIZE, file);
	fclose(file);
	translateBoard(bytes, board);
}

// translates binary data into the board
void translateBoard(BYTE bytes[], Board board)
{
	int bit_index = 0;
	int i, j;
	for (i = 0; i < BOARDSIZE;i++)
	{
		for (j = 0; j < BOARDSIZE;j++)
		{
			int leftBit = readBit(&bytes[bit_index / 8], bit_index % 8);
			bit_index++;
			int rightBit = readBit(&bytes[bit_index / 8], bit_index % 8);
			bit_index++;

			if (leftBit == 0 && rightBit == 0) // empty
				board[i][j] = EMPTY;
			else if (leftBit == 1 && rightBit == 0) // player 1
				board[i][j] = PLAYER1;
			else if (leftBit == 0 && rightBit == 1) // player 2
				board[i][j] = PLAYER2;
		}
	}
}