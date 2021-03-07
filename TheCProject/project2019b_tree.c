#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "project2019b_general.h"
#include "project2019b_tree.h"

//creates a SingleSourceMovesTree .
SingleSourceMovesTree* createSingleSourceMovesTree()
{
	SingleSourceMovesTree* tree;
	tree = (SingleSourceMovesTree*)malloc(sizeof(SingleSourceMovesTree));
	checkAllocation(tree); // check allocations
	tree->source = NULL;
	return tree;
}

//creates a SingleSourceMovesTreeNode .
SingleSourceMovesTreeNode* createSingleSourceMovesTreeNode(Board board, char row, char col, unsigned short total_captures_so_far)
{
	SingleSourceMovesTreeNode* node;
	node = (SingleSourceMovesTreeNode*)malloc(sizeof(SingleSourceMovesTreeNode));
	checkAllocation(node); // check allocations

	copyBoardToSingleSourceMovesTreeNode(node, board);
	node->total_captures_so_far = total_captures_so_far;
	node->pos = createPos(row,col);
	node->next_move[0] = NULL;
	node->next_move[1] = NULL;
	return node;
}

//copies a board to SingleSourceMovesTreeNode .
void copyBoardToSingleSourceMovesTreeNode(SingleSourceMovesTreeNode* node, Board board) 
{
	for (int i = 0;i < BOARDSIZE;i++) 
	{
		for (int j = 0;j < BOARDSIZE;j++)
		{
			node->board[i][j] = board[i][j];
		}
	}
}

//connects SingleSourceMovesTreeNode from left .
void connectSingleSourceMovesTreeNodeFromLeft(SingleSourceMovesTreeNode* node1, SingleSourceMovesTreeNode* node2) 
{
	node1->next_move[0] = node2;
}

//connects SingleSourceMovesTreeNode from right .
void connectSingleSourceMovesTreeNodeFromRight(SingleSourceMovesTreeNode* node1, SingleSourceMovesTreeNode* node2)
{
	node1->next_move[1] = node2;
}

// recursive function that deletes the nodes of the SingleSourceMovesTree .
void freeSingleSourceMovesTreeNode(SingleSourceMovesTreeNode* node)
{
	if (node != NULL)
	{
		freeSingleSourceMovesTreeNode(node->next_move[0]);
		freeSingleSourceMovesTreeNode(node->next_move[1]);
		free(node->pos);
		free(node);
	}
}

// deletes SingleSourceMovesTree .
void freeSingleSourceMovesTree(SingleSourceMovesTree* tree)
{
	freeSingleSourceMovesTreeNode(tree->source);
	tree->source = NULL;
	free(tree);
}

//returns left SingleSourceMovesTreeNode .
SingleSourceMovesTreeNode* getLeftSingleSourceMovesTreeNode(SingleSourceMovesTreeNode* node) 
{
	return node->next_move[LEFT];
}

//returns right SingleSourceMovesTreeNode .
SingleSourceMovesTreeNode* getRightSingleSourceMovesTreeNode(SingleSourceMovesTreeNode* node)
{
	return node->next_move[RIGHT];
}

//creates a pos .
checkersPos* createPos(char row, char col)
{
	checkersPos* pos;
	pos = (checkersPos*)malloc(sizeof(checkersPos));
	checkAllocation(pos); // check allocations

	pos->col = col;
	pos->row = row;
	return pos;
}

// [TEMP], recursive function, prints SingleSourceMovesTreeNode , in order method .
void printSingleSourceMovesTreeNodeInOrder(SingleSourceMovesTreeNode* node)
{
	if (node != NULL)
	{
		printSingleSourceMovesTreeNodeInOrder(node->next_move[0]);
		printf("%c%c\n", node->pos->row, node->pos->col);
		printf("%d\n", node->total_captures_so_far);
		printSingleSourceMovesTreeNodeInOrder(node->next_move[1]);
	}
}


