#include "board.h"
#include "graphics.h"
#include <random>
#include <iostream>

int board[BOARD_WIDTH][BOARD_HEIGHT];

std::vector<int> freePlacesVec(BOARD_HEIGHT * BOARD_WIDTH);// setting the size of the vector to be the total size of the board
//This method creates a 2X2 array that is used to define where blocks are drawn
void initBoard()
{
	//creating board array
	for (int x = 0; x < BOARD_WIDTH; x++)
	{
		for (int y = 0; y < BOARD_HEIGHT; y++)
		{
			if (x > BOARD_WIDTH || y > BOARD_HEIGHT)
			{
				board[x][y] = POS_FREE;
			}
		}
	}
}

void drawBoard()
{
	for (int i = 0; i < BOARD_WIDTH; i++)
	{
		for (int j = 0; j < BOARD_HEIGHT; j++)
		{
			switch (board[i][j])
			{
			case 1:
				drawRect(i, j, POS_SELECTED);
				break;
			case 2:
				drawRect(i, j, POS_RED);
				break;
			case 3:
				drawRect(i, j, POS_YELLOW);
				break;
			case 4:
				drawRect(i, j, POS_GREEN);
				break;
			case 5:
				drawRect(i, j, POS_TURQUOISE);
				break;
			case 6:
				drawRect(i, j, POS_PURPLE);
				break;
			case 7:
				drawRect(i, j, POS_BLUE);
				break;
			default:
				drawRect(i, j, POS_FREE);
				break;

			}
		}
	}
}
