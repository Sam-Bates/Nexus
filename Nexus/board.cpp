#include "board.h"
#include "gridVector.h"
#include "graphics.h"
#include <random>
#include <iostream>

int board[BOARD_WIDTH][BOARD_HEIGHT];

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
				changeBall(x, y, POS_FREE);
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
	//save board[x][y]
	//check if any pieces around it match the saved board[x][y]
	//if a string of two are found check if board[x+1,2,3,4,5][y] all equals the same piecetype
	//delete them if they do
	int count = 0;
	int pieceType = 0;
	for (int x = 0; x < BOARD_WIDTH; x++)
	{
		for (int y = 0; y < BOARD_HEIGHT; y++)
		{
			pieceType = board[x][y];
			if (board[x][y + 1] == pieceType
				&& board[x][y + 2] == pieceType
				&& board[x][y + 3] == pieceType
				&& board[x][y + 4] == pieceType
				&& board[x][y] != POS_FREE)
			{
				//add new free spots to the vector
				//remove balls from board
				for (int i = 0; i < LINE_NUMBER; i++)
				{
					//board[x][y + i] = POS_FREE;
					changeBall(x, y + i, POS_FREE);
				}
			}
		}
	}
	for (int y = 0; y < BOARD_HEIGHT; y++)
	{
		for (int x = 0; x < BOARD_WIDTH; x++)
		{
			pieceType = board[x][y];
			if (board[x + 1][y] == pieceType
				&& board[x + 2][y] == pieceType
				&& board[x + 3][y] == pieceType
				&& board[x + 4][y] == pieceType
				&& board[x][y] != POS_FREE)
			{
				//add new free spots to the vector
				//remove balls from board
				for (int i = 0; i < LINE_NUMBER; i++)
				{
					//board[x + i][y] = POS_FREE;
					changeBall(x + i, y, POS_FREE);
				}
			}
		}
	}
}
void addSelected(int x, int y)
{
	int a = ((BOARD_WIDTH * y) + x);
	
}
