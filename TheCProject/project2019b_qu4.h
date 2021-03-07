#ifndef PROJECT2019B_QU4_H
#define PROJECT2019B_QU4_H 0X0001

#include "project2019b_list.h" 
#include "project2019b_list2.h" 

// function prototypes

void Turn(Board board, Player player);
SingleSourceMovesList* findMultipleListOptimalMove(MultipleSourceMovesList* multipleList, Player player);
void updateBoard(SingleSourceMovesList* bestMove,Board board, Player player);
void printBestMovesList(SingleSourceMovesList* bestSingleListMove, Player player);
void printBestMoves(SingleSourceMovesListCell* ptr, Player player);

#endif