#include "board.h"
#include "gridVector.h"
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
	for (int x = 0; x < BOARD_WIDTH; x++)
	{
		for (int y = 0; y < BOARD_HEIGHT; y++)
		{
			switch (board[x][y])
			{
			case 1:
				drawRect(x, y, POS_SELECTED);
				break;
			case 2:
				drawRect(x, y, POS_RED);
				break;
			case 3:
				drawRect(x, y, POS_YELLOW);
				break;
			case 4:
				drawRect(x, y, POS_GREEN);
				break;
			case 5:
				drawRect(x, y, POS_TURQUOISE);
				break;
			case 6:
				drawRect(x, y, POS_PURPLE);
				break;
			case 7:
				drawRect(x, y, POS_BLUE);
				break;
			default:
				drawRect(x, y, POS_FREE);
				break;

			}
		}
	}
}
void delLines()
{
	int count = 0;
	int pieceType = 0;
	for (int x = 0; x < BOARD_WIDTH; x++)
	{
		for (int y = 0; y < BOARD_HEIGHT; y++)
		{
			int previousPieceType = pieceType;
			pieceType = board[x][y];
			if (pieceType == previousPieceType && count != 0)
			{
				count++;
			}
			if (count > LINE_NUMBER)
			{
				removeFreeVecSpot(x, y);
				count = 0;
			}
		}
	}
	for (int y = 0; y < BOARD_HEIGHT; y++)
	{
		for (int x = 0; x < BOARD_WIDTH; x++)
		{
			int previousPieceType = pieceType;
			pieceType = board[x][y];
			if (pieceType == previousPieceType && count != 0)
			{
				count++;
			}
			if (count > LINE_NUMBER)
			{
				removeFreeVecSpot(x, y);
				count = 0;
			}
		}
	}
}
