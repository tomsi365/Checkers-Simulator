#ifndef PROJECT2019B_LIST_H
#define PROJECT2019B_LIST_H 0X0001
#include "project2019b_tree.h"

// struct prototypes
struct _SingleSourceMovesListCell;
struct _SingleSourceMovesList;

// struct definitions
typedef struct _SingleSourceMovesListCell
{
	checkersPos* position;
	unsigned short captures;
	struct _SingleSourceMovesListCell* next;
}SingleSourceMovesListCell;
typedef struct _SingleSourceMovesList
{
	SingleSourceMovesListCell* head;
	SingleSourceMovesListCell* tail;
}SingleSourceMovesList;

// function prototypes
SingleSourceMovesListCell* createSingleSourceMovesListCell(int captures, checkersPos* position, SingleSourceMovesListCell* next);
int isEmptySingleSourceMovesList(SingleSourceMovesList* ls);
void insertNodeToTailOfSingleSourceMovesList(SingleSourceMovesList* ls, SingleSourceMovesListCell* newTail);
void freeSingleSourceMovesList(SingleSourceMovesList* lst);
SingleSourceMovesList* createSingleSourceMovesList();
void freeSingleSourceMovesListCell(SingleSourceMovesListCell * cell);
void printSingleSourceMovesList(SingleSourceMovesList* lst);//[TEMP] , prints SingleSourceMovesList .

#endif
