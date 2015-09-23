#include <SDL.h>
#include <iostream>
#include "graphics.h"
#include "board.h"

SDL_Event e;

int main(int argc, char* args[])
{
	initBoard();
	if (!init())
	{
		std::cout << "Failed to initialize!" << std::endl;
	}
	else
	{
		if (!loadMedia())
		{
			std::cout << "Failed to load media!" << std::endl;
		}
		while (SDL_PollEvent(&e) != 0)
		{

		}
		drawBoard();
	}

	return 0;

}