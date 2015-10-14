#ifndef board_h_
#define board_h_

void drawBoard();
void initBoard();
void addSelected(int, int);

const int BOARD_WIDTH = 10; //in blocks
const int BOARD_HEIGHT = 10; //in blocks
const int POS_FREE = 0;
const int POS_SELECTED = 1;
const int POS_RED = 2;
const int POS_YELLOW = 3;
const int POS_GREEN = 4;
const int POS_TURQUOISE = 5;
const int POS_PURPLE = 6;
const int POS_BLUE = 7;
const int NUMBER_OF_RANDOM_BLOCKS = 4;
const int LINE_NUMBER = 5;

extern int board[BOARD_WIDTH][BOARD_HEIGHT];

#endif