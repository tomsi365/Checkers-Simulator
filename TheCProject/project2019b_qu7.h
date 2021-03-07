#ifndef PROJECT2019B_QU7_H
#define PROJECT2019B_QU7_H 0X0001

void printBoard(Board board);//prints board .
void printHorizontalBorder();
void printColsLine();
BOOL isTwoPlayersExisted(Board board);
BOOL isThereAPlayerAtLastRow(Board board);
BOOL isGameOver(Board board);
void playGame(Board board, Player starting_player);
void init(Board board);
void printPlayer(Player player);

#endif