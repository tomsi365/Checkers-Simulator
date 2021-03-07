#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "project2019b_general.h"
#include "project2019b_tree.h"
#include "project2019b_qu1.h"

//returns tree of single source moves .
SingleSourceMovesTree* FindSingleSourceMoves(Board board, checkersPos* src) 
{
	char row = src->row;
	char col = src->col;
	if (getPlayerOnBoard(board, row,col) != EMPTY)
	{
		SingleSourceMovesTree* tree=createSingleSourceMovesTree();

		if (getPlayerOnBoard(board, row, col) == PLAYER1) // if its player1
			tree->source = findSingleSourceMoves(board, row, col, PLAYER1, 0,0);

		else if (getPlayerOnBoard(board, row, col) == PLAYER2) // if its player2
			tree->source = findSingleSourceMoves(board, row, col, PLAYER2, 0,0);

		return tree;
	}
		return NULL; 
}

//recursive function , returns root tree node of single source moves .
SingleSourceMovesTreeNode* findSingleSourceMoves(Board board, char row, char col, Player player,int steps,int captures )
{
	SingleSourceMovesTreeNode* node = createSingleSourceMovesTreeNode(board, row, col, captures);
	int row_direction = getRowDirection(player);
	SingleSourceMovesTreeNode* left = NULL;
	SingleSourceMovesTreeNode* right = NULL;

	if( ifCanCapture(board  , row + row_direction, col + 1, row + (row_direction*2), col + 2,player)==TRUE)
		right= findSingleSourceMoves(board, row + (row_direction * 2),col+2, player, steps+2, captures+1);

	else if (ifCanMoveOneStep(board, row + row_direction, col + 1, steps) == TRUE)
		right = createSingleSourceMovesTreeNode(board, row + row_direction, col + 1, 0);

	if (ifCanCapture(board,  row + row_direction, col - 1, row + (row_direction * 2), col - 2, player) == TRUE)
		left = findSingleSourceMoves(board, row + (row_direction * 2), col-2, player, steps + 2, captures + 1);

	else if (ifCanMoveOneStep(board, row + row_direction, col - 1,steps) == TRUE)
		left = createSingleSourceMovesTreeNode(board, row + row_direction,col-1, 0);

	connectSingleSourceMovesTreeNodeFromLeft(node, left);
	connectSingleSourceMovesTreeNodeFromRight(node, right);
	return node;
}

//returns the player located at the board , by row and col .
Player getPlayerOnBoard(Board board, char row, char col)
{
	return board[row - 'A'][col - '1'];
}

//checks if position in range of board .
BOOL isPosExistsOnBoard(char row,char col)
{
	int row_index = row - 'A';
	int col_index = col - '1';
	if (row_index >= 0 && row_index <= BOARDSIZE && col_index >= 0 && col_index < BOARDSIZE) 
	{
		return TRUE;
	}
	return FALSE;
}

//returns direction of player , (Y Axis) .
int getRowDirection(Player player) 
{
	if (player == PLAYER1) 
	{
		return -1;
	}
	return 1;
}

//returns competitor of player .
int getCompetitor(Player player)
{
	if (player == PLAYER1)
	{
		return PLAYER2;
	}
	return PLAYER1;
}

//checks if player can move one step .
BOOL ifCanMoveOneStep(Board board, char row1, char col1,  int total_captures_so_far)
{
	if (isPosExistsOnBoard(row1, col1) && total_captures_so_far==0)
	{
		if (getPlayerOnBoard(board, row1, col1) == EMPTY)
		{
			return TRUE;
		}
	}
	return FALSE;
}

//checks if the player can do a "capture" .
BOOL ifCanCapture(Board board, char row1, char col1, char row2, char col2, Player player)
{
	if (isPosExistsOnBoard(row1,col1)&& isPosExistsOnBoard(row2,col2))
	{
		if (getPlayerOnBoard(board, row1, col1) == getCompetitor(player)&& getPlayerOnBoard(board, row2, col2) == EMPTY)
		{
			return TRUE;
		}
	}
	return FALSE;
}

//sets player on board , by row and col .
void setPlayer(Board board, char row, char col,Player player) 
{
	board[row - 'A'][col - '1']=player;
}

