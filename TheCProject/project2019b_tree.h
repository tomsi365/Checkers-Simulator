#ifndef PROJECT2019B_TREE_H
#define PROJECT2019B_TREE_H 0X0001

// struct prototypes
struct _checkersPos;
struct _SingleSourceMovesTreeNode;

// struct definitions
typedef struct _checkersPos
{
	char row, col;
}
checkersPos;
typedef struct _SingleSourceMovesTreeNode
{
	Board board;
	checkersPos* pos;
	unsigned short total_captures_so_far;//מספר דילוגים עד כה
	struct _SingleSourceMovesTreeNode* next_move[2];//יעדי התנועה
}
SingleSourceMovesTreeNode;
typedef struct _SingleSourceMovesTree
{
	SingleSourceMovesTreeNode* source;
}SingleSourceMovesTree;

// function prototypes
SingleSourceMovesTreeNode* createSingleSourceMovesTreeNode(Board board, char row, char col, unsigned short total_captures_so_far);
void copyBoardToSingleSourceMovesTreeNode(SingleSourceMovesTreeNode* node, Board board);
checkersPos* createPos(char row, char col);
void connectSingleSourceMovesTreeNodeFromRight(SingleSourceMovesTreeNode* node1, SingleSourceMovesTreeNode* node2);
void connectSingleSourceMovesTreeNodeFromLeft(SingleSourceMovesTreeNode* node1, SingleSourceMovesTreeNode* node2);
checkersPos* createPos(char row, char col);
void freeSingleSourceMovesTree(SingleSourceMovesTree* tree);
void freeSingleSourceMovesTreeNode(SingleSourceMovesTreeNode* node);
SingleSourceMovesTreeNode* getLeftSingleSourceMovesTreeNode(SingleSourceMovesTreeNode * node);
SingleSourceMovesTreeNode* getRightSingleSourceMovesTreeNode(SingleSourceMovesTreeNode * node);
SingleSourceMovesTree* createSingleSourceMovesTree();
void printSingleSourceMovesTreeNodeInOrder(SingleSourceMovesTreeNode* node); //[TEMP] , recursive function , prints tree node , in order method .

#endif