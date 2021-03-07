#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "project2019b_general.h"
#include "project2019b_tree.h"
#include "project2019b_list.h"
#include "project2019b_qu2.h"

// recursive function , returns the highest number of captures .
int getMaxNumOfCaptures(SingleSourceMovesTreeNode* node)
{
	if (getRightSingleSourceMovesTreeNode(node) == NULL && getLeftSingleSourceMovesTreeNode(node) == NULL) 
		return node->total_captures_so_far;
	if (getLeftSingleSourceMovesTreeNode(node) != NULL&& getRightSingleSourceMovesTreeNode(node) == NULL) 
		return getMaxNumOfCaptures(getLeftSingleSourceMovesTreeNode(node));
	if (getRightSingleSourceMovesTreeNode(node) != NULL&& getLeftSingleSourceMovesTreeNode(node) == NULL) 
		return getMaxNumOfCaptures(getRightSingleSourceMovesTreeNode(node));
	return findMax(getMaxNumOfCaptures(getRightSingleSourceMovesTreeNode(node)), getMaxNumOfCaptures(getLeftSingleSourceMovesTreeNode(node)));
}

// recursive function , this function follows the path with the most captures while building the list
void findOptimalPath(SingleSourceMovesTreeNode* node, SingleSourceMovesList* lst)
{
	insertNodeToTailOfSingleSourceMovesList(lst, createSingleSourceMovesListCell(node->total_captures_so_far, node->pos, NULL));
	if (getRightSingleSourceMovesTreeNode(node) != NULL && getLeftSingleSourceMovesTreeNode(node)!=NULL) 
	{
		int left = getMaxNumOfCaptures(getLeftSingleSourceMovesTreeNode(node));
		int right = getMaxNumOfCaptures(getRightSingleSourceMovesTreeNode(node));
		if (left <= right) 
			findOptimalPath(getRightSingleSourceMovesTreeNode(node), lst);
		else
			findOptimalPath(getLeftSingleSourceMovesTreeNode(node), lst);
	}
	else if (getRightSingleSourceMovesTreeNode(node) != NULL)
		findOptimalPath(getRightSingleSourceMovesTreeNode(node), lst);
	else if (getLeftSingleSourceMovesTreeNode(node) != NULL)
		findOptimalPath(getLeftSingleSourceMovesTreeNode(node), lst);	
}

// find the best move possible for a piece and make a list of its moves
SingleSourceMovesList* FindSingleSourceOptimalMove(SingleSourceMovesTree* moves_tree)
{
	SingleSourceMovesList* list = createSingleSourceMovesList();
	findOptimalPath(moves_tree->source, list);
	return list;
}