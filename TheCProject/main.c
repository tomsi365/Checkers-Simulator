#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "project2019b_general.h"
#include "project2019b_list2.h"
#include "project2019b_qu1.h"
#include "project2019b_qu2.h"
#include "project2019b_qu3.h"
#include "project2019b_qu4.h"
#include "project2019b_qu5.h"
#include "project2019b_qu6.h"
#include "project2019b_qu7.h"



void main()
{
	Board board;
	memset(board, EMPTY , 64); // makes an empty game board
	setPlayer(board, 'F', '7', PLAYER1);
	setPlayer(board, 'E', '6', PLAYER2);
	setPlayer(board, 'C', '6', PLAYER2);
	setPlayer(board, 'A', '8', PLAYER2);
	//init(board);
	playGame(board, PLAYER1);
	system("pause");
}



