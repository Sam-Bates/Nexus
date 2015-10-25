/*
You may need to add all of the DLL's in the Nexus/lib/x86 directory to the C:/Windows/SysWOW64 directory to make this compile
*/

#include <SDL.h>
#include <iostream>
#include "graphics.h"
#include "board.h"
#include "gridVector.h"
#include "pathFinding.h"
#include <vector>
#include <queue>

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
			fillRandomPlaces();
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
						if (selected == false && board[x][y] != POS_FREE)
						{
							selectedX = x;
							selectedY = y;
							selectedPieceType = board[selectedX][selectedY];
							board[x][y] = POS_SELECTED;
							selected = true;
						}
						else if (selected == true && board[x][y] != POS_FREE)
						{
							board[selectedX][selectedY] = selectedPieceType;
							selectedX = x;
							selectedY = y;
							selectedPieceType = board[x][y];
							board[selectedX][selectedY] = POS_SELECTED;

							selected = true;
						}
						else if (selected == true && board[x][y] == POS_FREE)
						{
							if (checkForPath(selectedX, selectedY, x, y))
							{
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
					fillRandomPlaces();
					delLines();
					justClicked = false;
				}
				SDL_RenderClear(gRenderer);
			}
		}
	}
	return 0;
}
