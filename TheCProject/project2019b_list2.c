#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "project2019b_general.h"
#include "project2019b_list2.h"
#include "project2019b_list.h"

// create node of MultipleSourceMovesList .
MultipleSourceMovesList* createMultipleSourceMovesList ()
{
	MultipleSourceMovesList* list = (MultipleSourceMovesList*)malloc(sizeof(MultipleSourceMovesList));
	checkAllocation(list);
	list->head = NULL;
	list->tail = NULL;
	return list;
}

// create node of MultipleSourceMovesListCell .
MultipleSourceMovesListCell* createMultipleSourceMovesListCell(SingleSourceMovesList * list)
{
	MultipleSourceMovesListCell* cell = (MultipleSourceMovesListCell*)malloc(sizeof(MultipleSourceMovesListCell));
	checkAllocation(cell);
	cell->next = NULL;
	cell->single_source_moves_list = list;
	return cell;
}

// inserts the next node to tail of MultipleSourceMovesList .
void insertNodeToTailOfMultipleSourceMovesList(MultipleSourceMovesList* ls, MultipleSourceMovesListCell* newTail)
{
	if (isEmptyMultipleSourceMovesList(ls)) // if this is the first node
	{
		ls->head = ls->tail = newTail;
	}
	else
	{
		ls->tail->next = newTail;
		ls->tail = newTail;
	}
}

// check if the MultipleSourceMovesList is empty
int isEmptyMultipleSourceMovesList(MultipleSourceMovesList* ls)
{
	return (ls->head == NULL);
}

// free's a MultipleSourceMovesList
void freeMultipleSourceMovesList(MultipleSourceMovesList* lst)
{
	freeMultipleSourceMovesListCell(lst->head);
	lst->tail = NULL;
	lst->head = NULL;
	free(lst);
}

//recursive function , frees sequence of MultipleSourceMovesListCell .
void freeMultipleSourceMovesListCell(MultipleSourceMovesListCell * cell)
{
	if (cell != NULL)
	{
		if (cell->next != NULL)
		{
			freeMultipleSourceMovesListCell(cell->next);
		}
		freeSingleSourceMovesList(cell->single_source_moves_list);
		free(cell);
	}
}

//[TEMP] prints MultipleSourceMovesList .
void printMultipleSourceMovesList(MultipleSourceMovesList* lst)
{
	MultipleSourceMovesListCell* ptr = lst->head;
	while (ptr != NULL)
	{
		char row = ptr->single_source_moves_list->head->position->row;
		char col = ptr->single_source_moves_list->head->position->col;
		printf("player pos , row: %c , col: %c\n",row,col);
		printSingleSourceMovesList(ptr->single_source_moves_list);
		ptr = ptr->next;
	}
	
	printf("\n");
}
