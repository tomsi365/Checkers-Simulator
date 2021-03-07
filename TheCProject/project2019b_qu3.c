#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "project2019b_general.h"
#include "project2019b_list.h"
#include "project2019b_list2.h"
#include "project2019b_tree.h"
#include "project2019b_qu1.h"
#include "project2019b_qu2.h"
#include "project2019b_qu3.h"

//returns all the optimal paths options of player .
MultipleSourceMovesList* FindAllPossiblePlayerMoves(Board board, Player player) 
{
	MultipleSourceMovesList* multiple_moves_list = createMultipleSourceMovesList();
	for (int i = 0;i < BOARDSIZE;i++) 
	{
		for (int j = 0;j < BOARDSIZE;j++)
		{
			if (board[i][j] == player) 
			{
				checkersPos* pos = createPos('A'+i, '1'+j);
				SingleSourceMovesTree* moves_tree = FindSingleSourceMoves(board, pos);
				if (isMovableSingleSourceMovesList(moves_tree)==TRUE)
				{
					SingleSourceMovesList* optimal_moves_list = FindSingleSourceOptimalMove(moves_tree);
					insertNodeToTailOfMultipleSourceMovesList(multiple_moves_list, createMultipleSourceMovesListCell(optimal_moves_list));
				}
				freeSingleSourceMovesTree(moves_tree);
				free(pos);
			}
		}
	}
	return multiple_moves_list;
}

//checks player can move on board , by it's moves tree .
BOOL isMovableSingleSourceMovesList(SingleSourceMovesTree* tree) 
{
	if (getLeftSingleSourceMovesTreeNode(tree->source)!=NULL|| getRightSingleSourceMovesTreeNode(tree->source) != NULL)
	{
		return TRUE;
	}
	return FALSE;
}