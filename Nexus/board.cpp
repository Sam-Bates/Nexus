#include "board.h"
#include "graphics.h"

int board[BOARD_WIDTH][BOARD_HEIGHT];

//This method creates a 2X2 array that is used to define where blocks are drawn
void initBoard()
{
	for (int x = 0; x < BOARD_WIDTH; x++)
	{
		for (int y = 0; y < BOARD_HEIGHT; y++)
		{
			if ( x > BOARD_WIDTH || y > BOARD_HEIGHT)
			{
				board[x][y] = POS_FREE;
			}
		}
	}
}

void defineBoard()
{
	for (int i = 0; i < BOARD_WIDTH; i++)
	{
		for (int j = 0; j < BOARD_HEIGHT; j++)
		{
			switch (board[i][j])
			{
			case 0:
				drawRect(i, j, POS_FREE);
				break;
			case 1:
				drawRect(i, j, POS_)
			default:
				break;
			}

			/*if (board[i][j] == POS_TAKEN)
			{
				drawRect(i, j, POS_TAKEN);
			}
			else if (board[i][j] == BORDER) //Same thing as above, expect loading borderTexture instead of the block texture
			{
				drawRect(i, j, BORDER);
			}*/
		}
	}
}