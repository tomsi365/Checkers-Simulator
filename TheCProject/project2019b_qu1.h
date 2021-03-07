#ifndef PROJECT2019B_QU1_H
#define PROJECT2019B_QU1_H 0X0001
#include "project2019b_tree.h"

// function prototypes
SingleSourceMovesTree* FindSingleSourceMoves(Board board, checkersPos *src);
SingleSourceMovesTreeNode* findSingleSourceMoves(Board board, char row, char col, Player player, int steps,int captures);
Player getPlayerOnBoard(Board board, char row, char col);
BOOL isPosExistsOnBoard(char col, char row);
int getRowDirection(Player player);
int getCompetitor(Player player);
BOOL ifCanMoveOneStep(Board board, char row1, char col1, int total_captures_so_far);
BOOL ifCanCapture(Board board, char row1, char col1, char row2, char col2, Player player);
void setPlayer(Board board, char row, char col, Player player);

#endif