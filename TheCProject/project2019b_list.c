#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "project2019b_general.h"
#include "project2019b_list.h"
#include "project2019b_tree.h"

//creates SingleSourceMovesList .
SingleSourceMovesList* createSingleSourceMovesList()
{
	SingleSourceMovesList* list;
	list = (SingleSourceMovesList*)malloc(sizeof(SingleSourceMovesList));
	checkAllocation(list);
	list->head = NULL;
	list->tail = NULL;
	return list;
}

//create node of SingleSourceMovesList .
SingleSourceMovesListCell* createSingleSourceMovesListCell(int captures, checkersPos* position, SingleSourceMovesListCell* next)
{
	SingleSourceMovesListCell* cell;
	cell = (SingleSourceMovesListCell*)malloc(sizeof(SingleSourceMovesListCell));
	checkAllocation(cell); // check allocation

	cell->captures = captures;
	cell->position = createPos(position->row,position->col);
	cell->next = next;

	return cell;
}

// inserts the next node to tail of SingleSourceMovesList .
void insertNodeToTailOfSingleSourceMovesList(SingleSourceMovesList* ls, SingleSourceMovesListCell* newTail)
{
	if (isEmptySingleSourceMovesList(ls)) // if this is the first node
	{
		ls->head = ls->tail = newTail;
	}
	else
	{
		ls->tail->next = newTail;
		ls->tail = newTail;
	}
}

// check if the SingleSourceMovesList is empty
int isEmptySingleSourceMovesList(SingleSourceMovesList* ls)
{
	return (ls->head == NULL);
}

// free's a SingleSourceMovesList
void freeSingleSourceMovesList(SingleSourceMovesList* lst)
{
	freeSingleSourceMovesListCell(lst->head);
	lst->tail = NULL;
	lst->head = NULL;
	free(lst);
}

//recursive function , frees sequence of SingleSourceMovesListCell .
void freeSingleSourceMovesListCell(SingleSourceMovesListCell * cell)
{
	if (cell != NULL)
	{
		if (cell->next != NULL)
		{
			freeSingleSourceMovesListCell(cell->next);
		}
		free(cell->position);
		free(cell);
	}
}

//[TEMP] , prints SingleSourceMovesList .
void printSingleSourceMovesList(SingleSourceMovesList* lst)
{
	if (lst == NULL)
		return;
	SingleSourceMovesListCell* ptr = lst->head;
	while (ptr != NULL)
	{
		printf("captures: %d, position: %c%c\n", ptr->captures, ptr->position->row, ptr->position->col);
		ptr = ptr->next;
	}
}

