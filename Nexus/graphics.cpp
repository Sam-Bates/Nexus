#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "board.h"
#include "graphics.h"

void drawRect(int x, int y, int pieceType)
{
	SDL_Rect a = { x * MAGNIFICATION, y * MAGNIFICATION, MAGNIFICATION/*size*/, MAGNIFICATION/*size*/ };
	//TODO make a case which looks through the current board and decides which texture to draw based on the passed in pieceType variable use board.h
}

bool init()
{
	//Initialization flag
	bool success = true;
	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "SDL could not initialize! SDL Error: " << SDL_GetError() << std::endl;
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			std::cout << "Warning: Linear texture filtering not enabled!" << std::endl;
		}

		//Create window
		gWindow = SDL_CreateWindow("Tetris", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			std::cout << "Window could not be created! SDL Error: " << SDL_GetError() << std::endl;
			success = false;
		}
		else
		{
			//Create renderer for window
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
			if (gRenderer == NULL)
			{
				std::cout << "Renderer could not be created! SDL Error: " << SDL_GetError() << std::endl;
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					std::cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << std::endl;
					success = false;
				}
			}
		}
	}
	return success;
}

bool loadMedia()
{
	//Loading success flag
	bool success = true;

	//Load PNG texture
	try
	{
		tTurquoise = loadTexture("turquoise.png");
		tBlue = loadTexture("blue.png");
		tFree = loadTexture("free.png");
		tGreen = loadTexture("green.png");
		tPurple = loadTexture("purple.png");
		tRed = loadTexture("red.png");
		tSelected = loadTexture("selected.png");
		tYellow = loadTexture("yellow.png");
	}
	catch (std::exception &e)
	{
		std::cout << "Exception " << e.what() << std::endl;
	}

	/*if (blockTexture == NULL || borderTexture == NULL || pieceTexture == NULL)
	{
		std::cout << "Failed to load texture image!" << std::endl;
		success = false;
	}*/

	return success;
}
