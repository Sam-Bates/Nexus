#include <SDL.h>
#include <iostream>
#include "graphics.h"
#include "board.h"
#include "gridVector.h"
#include <vector>
#include <queue>
bool checkForPath(int, int, int, int);
int main(int argc, char* args[])
{

	initBoard();
	initVector();
	
	bool gameOver = false;
	bool justClicked = false;
	bool selected = false;
	int selectedX = NULL;
	int selectedY = NULL;
	int selectedPieceType = NULL;
	//Start up SDL and create window
	if (!init())
	{
		std::cout << "Failed to initialize!" << std::endl;
	}
	else
	{
		//Load media
		if (!loadMedia())
		{
			std::cout << "Failed to load media!" << std::endl;
		}
		else
		{

			//Event handler
			SDL_Event e;

			//While application is running
			while (!gameOver)
			{

				//Handle events on queue
				while (SDL_PollEvent(&e) != 0)
				{

					//User requests quit
					if (e.type == SDL_QUIT)
					{
						gameOver = true;
					}
					else if (e.type == SDL_KEYDOWN)
					{
						//keyboard input
						switch (e.key.keysym.sym)
						{
						case SDLK_SPACE:
							fillRandomPlaces();
							break;
						}
					}
					else if (e.type == SDL_MOUSEBUTTONDOWN)
					{
						int x, y;
						SDL_GetMouseState(&x, &y);
						x = x / MAGNIFICATION;
						y = y / MAGNIFICATION;
						//If nothing has been selected AND the user clicked on a TAKEN space
						if (selected == false && board[x][y] != POS_FREE)
						{
							//save location of selected ball
							selectedX = x;
							selectedY = y;

							//save colour of ball
							selectedPieceType = board[selectedX][selectedY];

							//change colour of ball
							board[x][y] = POS_SELECTED;
							selected = true;
						}
						//Else if something has already been selected AND the user clicked on a TAKEN space
						else if (selected == true && board[x][y] != POS_FREE)
						{
							//revert colour of previously seleceted ball
							board[selectedX][selectedY] = selectedPieceType;

							//change current selection to new selection
							selectedX = x;
							selectedY = y;
							
							//save colour of new selected ball
							selectedPieceType = board[x][y];
							//change colour of new selected ball
							board[selectedX][selectedY] = POS_SELECTED;

							selected = true;
						}
						//Else if something has already been selected AND the user clicked on a FREE space
						else if (selected == true && board[x][y] == POS_FREE)
						{
							if (checkForPath(selectedX, selectedY, x, y))
							{
								//revert colour of selected ball
								board[x][y] = selectedPieceType;
								changeBall(x, y, selectedPieceType);
								changeBall(selectedX, selectedY, POS_FREE);
							}
							else
							{
								board[selectedX][selectedY] = selectedPieceType;
							}
							selected = false;
							justClicked = true;
						}
						
					}
				}
				drawBoard();
				SDL_RenderPresent(gRenderer);

				if (justClicked)
				{
					delLines();
					justClicked = false;
				}

				//Clear screen
				SDL_RenderClear(gRenderer);
			}
		}
	}
	//close();
	return 0;
}
bool checkForPath(int startX, int startY, int endX, int endY)
{
	std::queue<int>queue;
	std::vector<bool>visited;

	for (int i = 0; i < BOARD_WIDTH * BOARD_HEIGHT; i++)
	{
		visited.push_back(false);
	}
	int startIndex = ((BOARD_WIDTH * startX) + startY);
	int endIndex = ((BOARD_WIDTH * endX) + endY);
	queue.push(startIndex);
	visited[startIndex] = true;
	while (!queue.empty())
	{

		int current = queue.front();
		queue.pop();
		std::cout << "current: " << current << std::endl;
		if (current == endIndex)
		{
			return true;
		}
		int neighbours[4] = {};
		//north
		if (current - BOARD_HEIGHT <= 0)
		{
			neighbours[0] = current;
		}
		else
		{
			neighbours[0] = current - BOARD_HEIGHT;
		}
		//south
		if (current + BOARD_HEIGHT >= BOARD_HEIGHT * BOARD_WIDTH)
		{
			neighbours[1] = current;
		}
		else
		{
			neighbours[1] = current + BOARD_HEIGHT;
		}
		//east
		if (current % 10 == BOARD_WIDTH - 1)
		{
			neighbours[2] = current;
		}
		else
		{
			neighbours[2] = current + 1;
		}
		//west
		if (current % 10 == 0)
		{
			neighbours[3] = current;
		}
		else
		{
			neighbours[3] = current - 1;
		}
		for (int i = 0; i < 4; i++)
		{
			int X = neighbours[i] % BOARD_WIDTH;
			int Y = neighbours[i] / BOARD_HEIGHT;
			if (board[Y][X] == POS_FREE)
			{
				if (!visited[neighbours[i]])
				{
					queue.push(neighbours[i]);
					visited[neighbours[i]] = true;
				}
			}

		}
	}
	return false;
}