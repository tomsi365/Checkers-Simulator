#ifndef PROJECT2019B_LIST2_H
#define PROJECT2019B_LIST2_H 0X0001
#include "project2019b_list.h"

// struct prototypes
struct _multipleSourceMovesListCell;
struct _multipleSourceMovesList;

// struct definitions
typedef struct _multipleSourceMovesListCell 
{
	SingleSourceMovesList *single_source_moves_list;
	struct _multipleSourceMovesListCell *next;
}
MultipleSourceMovesListCell;
typedef struct _multipleSourceMovesList
{
	MultipleSourceMovesListCell *head;
	MultipleSourceMovesListCell *tail;
}
MultipleSourceMovesList;

// function prototypes
MultipleSourceMovesList* createMultipleSourceMovesList();
MultipleSourceMovesListCell* createMultipleSourceMovesListCell(SingleSourceMovesList * list);
int isEmptyMultipleSourceMovesList(MultipleSourceMovesList* ls);
void insertNodeToTailOfMultipleSourceMovesList(MultipleSourceMovesList* ls, MultipleSourceMovesListCell* newTail);
void freeMultipleSourceMovesList(MultipleSourceMovesList* lst);
void freeMultipleSourceMovesListCell(MultipleSourceMovesListCell * cell);
void printMultipleSourceMovesList(MultipleSourceMovesList* lst);//[TEMP] prints MultipleSourceMovesList .

#endif