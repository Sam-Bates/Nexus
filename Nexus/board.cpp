#include "board.h"
#include "graphics.h"
#include <random>
#include <time.h>
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
void initVector()
{
	for (int i = 0; i < freePlacesVec.size(); i++)
	{
		freePlacesVec[i] = i;
	}
}
void fillRandomPlaces()
{
	srand(time(NULL));
	/*4 = number of random blocks to be spawned change this later. also check if there are actually 4 blocks available*/
	for (int i = 0; i < 4 ; i++)
	{
		int pieceType = 2 + rand() % (7 - 2); // This generates a random number between 2 - 7
		int randomFreeIndex = freePlacesVec[rand() % freePlacesVec.size()];
		int x = randomFreeIndex % BOARD_WIDTH;
		int y = randomFreeIndex / BOARD_WIDTH;
		board[x][y] = pieceType;
	}
}

/* assuming width and height are the same
Index % width = X
Index / width = Y
(width * Y) + X = Index

to remove specific spot, find the indexOf(n) vector.erase(index)
to add new taken spot pop_back(n)
*/
void removeFreeVecSpot(int y, int x)
{
	int index = (BOARD_WIDTH * y) + x;
	freePlacesVec.erase(freePlacesVec.begin() + index);
}