#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "project2019b_general.h"
#include "project2019b_list2.h"
#include "project2019b_qu1.h"
#include "project2019b_qu3.h"
#include "project2019b_qu4.h"

void Turn(Board board, Player player)
{
	MultipleSourceMovesList* multiList = FindAllPossiblePlayerMoves(board, player); // create the moveList
	SingleSourceMovesList* bestSingleListMove = NULL;
	if (multiList != NULL) // at least one move
	{
		bestSingleListMove = findMultipleListOptimalMove(multiList, player); // find the best move
		printBestMovesList(bestSingleListMove, player);
		updateBoard(bestSingleListMove, board, player); // execute the best move and update the board
		freeMultipleSourceMovesList(multiList); // since board is updated there is no need for any lists
	}
}

// finds best singleSourceMoveList inside MultipleSourceMovesList and 
// returns the list for execution
SingleSourceMovesList* findMultipleListOptimalMove(MultipleSourceMovesList* multipleList, Player player)
{
	SingleSourceMovesList* result = NULL;
		MultipleSourceMovesListCell* listPtr = multipleList->head;
		result = listPtr->single_source_moves_list; // base case
		while (listPtr != NULL)
		{
			char last_pos_row = listPtr->single_source_moves_list->tail->position->row;
			if (last_pos_row == 'H' && player == PLAYER2 || last_pos_row == 'A' && player == PLAYER1) // if one of the moves is towards the end of the board
			{
				result = listPtr->single_source_moves_list;
				break;
			}
			if (result->tail->captures < listPtr->single_source_moves_list->tail->captures) // if there are captures
			{
				result = listPtr->single_source_moves_list;
			}
			listPtr = listPtr->next;
		}
	return result;
}

// updates the board during the turn
void updateBoard(SingleSourceMovesList* bestMove,Board board, Player player)
{
	char row = bestMove->head->position->row;
	char col = bestMove->head->position->col;
	SingleSourceMovesListCell* listPtr = bestMove->head; 
		setPlayer(board, row, col, EMPTY); // delete first location
		while (listPtr != NULL)
		{
			col = listPtr->position->col;
			row = listPtr->position->row;
			if (listPtr->next != NULL && listPtr->captures < listPtr->next->captures) // next move is capture
			{
				row += getRowDirection(player);
				if (listPtr->position->col > listPtr->next->position->col) // left
					col += -1;
				else if (listPtr->position->col < listPtr->next->position->col) // right
					col += +1;
				setPlayer(board, row, col, EMPTY);
			}
			if (listPtr->next == NULL) 	// its the last case update the location of the player
			{
			setPlayer(board, row, col, player); // set new location
		    }

			listPtr = listPtr->next;
		}
}

//prints BestMovesList of current player .
void printBestMovesList(SingleSourceMovesList* bestSingleListMove, Player player)
{
	if(bestSingleListMove!=NULL)
	{
		printBestMoves(bestSingleListMove->head, player);
	}
}

//recursive function , prints sequence of moves of player .
void printBestMoves(SingleSourceMovesListCell* ptr,Player player)
{
		if (ptr != NULL&& ptr->next!=NULL)
		{
			printf("%c%c->",ptr->position->row, ptr->position->col);
			printBestMoves(ptr->next, player);
		}
		else if (ptr != NULL)
		{
			printf("%c%c\n", ptr->position->row, ptr->position->col);
		}
}

