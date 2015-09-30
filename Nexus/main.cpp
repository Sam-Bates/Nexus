#include <SDL.h>
#include <iostream>
#include "graphics.h"
#include "board.h"

int main(int argc, char* args[])
{

	initBoard();
	initVector();
	bool gameOver = false;
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
				}
				drawBoard();
				SDL_RenderPresent(gRenderer);


				//Clear screen
				SDL_RenderClear(gRenderer);
			}
		}
	}
	//close();
	return 0;
}