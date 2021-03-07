#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "project2019b_general.h"
#include "project2019b_qu1.h"
#include "project2019b_qu4.h"
#include "project2019b_qu7.h"

//prints board .
void printBoard(Board board)
{
	printHorizontalBorder();
	printColsLine();
	printHorizontalBorder();
	for (int i = 0;i < BOARDSIZE;i++)
	{
		printf("|%c", 'A'+i);
		for (int j = 0;j < BOARDSIZE;j++)
		{
			printf("|%c", board[i][j]);
		}
		printf("|\n");
		printHorizontalBorder();
	}
}

//prints horizantal line by the format .
void printHorizontalBorder() 
{
	for (int i = 0;i <= BOARDSIZE;i++) 
	{
		printf("+-");
	}
	printf("+\n");
}

//prints cols line by the format .
void printColsLine() 
{
	printf("+ ");
	for (int i = 1;i <= BOARDSIZE;i++)
	{
		printf("|%d",i);
	}
	printf("|\n");
}

//loop function , performes turns , each time other player , until the game ends .
void playGame(Board board, Player starting_player) 
{
	printBoard(board);
	Player current_player = starting_player;
	while (isGameOver(board) == FALSE)
	{
		printPlayer(current_player);
		Turn(board, current_player);
		current_player = getCompetitor(current_player);
	}
	printPlayer(current_player);
}

//checks if there are game tools of two players on the board .
BOOL isTwoPlayersExisted(Board board) 
{
	int counter1 = 0;
	int counter2 = 0;
	for (int i = 0;i < BOARDSIZE;i++) 
	{
		for (int j = 0;j < BOARDSIZE;j++)
		{
			if (board[i][j] == PLAYER1) 
			{
				counter1++;
			}
			if (board[i][j] == PLAYER2) 
			{
				counter2++;
			}
		}
	}
	
	if(counter1 == 0 || counter2 == 0 )
		return FALSE; 
	else 
		return TRUE;
}

//check if some player has reached to end of board .
BOOL isThereAPlayerAtLastRow(Board board)
{
	for (int i = 0;i < BOARDSIZE;i++) 
	{
		if (board[0][i]== PLAYER1)
		{
			return TRUE;
		}
		if ( board[7][i] == PLAYER2)
		{
			return TRUE;
		}
	}
	return FALSE;
}

//checks if game is over .
BOOL isGameOver(Board board)
{
	if (isThereAPlayerAtLastRow(board) == TRUE || isTwoPlayersExisted(board) == FALSE) 
	{
		return TRUE;
	}
	return FALSE;
}

//installizes the board .
void init(Board board) 
{
	memset(board, EMPTY, 64);
	for (int i = 0;i < 3;i++) 
	{
		for (int k = (i + 1) % 2;k < 8;k+=2)
		{
			board[i][k] = PLAYER2;
		}
	}
	for (int j =5 ;j < 8;j++)
	{
		for (int m = (j+1) % 2;m < 8;m += 2)
		{
			board[j][m] = PLAYER1;
		}
	}
}

//prints who's turn .
void printPlayer(Player player) 
{
	char* player2_name = "TOP_DOWN's";
	char* player1_name = "BOTTOM_UP's";
	if (player == PLAYER1)
		printf("player %s turn \n", player1_name);
	else
		printf("player %s turn \n", player2_name);
}

