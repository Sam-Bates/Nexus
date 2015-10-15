#include <SDL.h>
#include <iostream>
#include "graphics.h"
#include "board.h"
#include "gridVector.h"
#include <vector>

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
						std::cout << "Current Mouse Pos: "<< "x: " << x << "y: " << y << std::endl;
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
							board[x][y] = selectedPieceType;

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
							//revert colour of selected ball
							board[x][y] = selectedPieceType;

							//A*
							std::vector<int> openList;
							std::vector<int> closedList;
							int orignalSquare = 0; // find original square
							int destinationSquare = ((BOARD_WIDTH * y) + x);
							openList.push_back((BOARD_WIDTH * y) + x); //add original square
							do{
								int currentSquareIndex = getLowestFscore();//search for lowest Fscore
								closedList.push_back((BOARD_WIDTH * y) + x);
								openList.erase(openList.begin() + getCurrentSquareIndex());

								if (searchForIndex(destinationSquare))
								{
									break;
								}

								//adjacentSquares = 
								
							} while (!openList.empty());
							//[openList add : originalSquare]; // start by adding the original position to the open list
							
							//do {
							//	currentSquare = [openList squareWithLowestFScore]; // Get the square with the lowest F score

							//	[closedList add : currentSquare]; // add the current square to the closed list
							//	[openList remove : currentSquare]; // remove it to the open list

							//	if ([closedList contains : destinationSquare]) { // if we added the destination to the closed list, we've found a path
							//		// PATH FOUND
							//		break; // break the loop
							//	}

							//	adjacentSquares = [currentSquare walkableAdjacentSquares]; // Retrieve all its walkable adjacent squares

							//	foreach(aSquare in adjacentSquares) {

							//		if ([closedList contains : aSquare]) { // if this adjacent square is already in the closed list ignore it
							//			continue; // Go to the next adjacent square
							//		}

							//		if (![openList contains : aSquare]) { // if its not in the open list

							//			// compute its score, set the parent
							//			[openList add : aSquare]; // and add it to the open list

							//		}
							//		else { // if its already in the open list

							//			// test if using the current G score make the aSquare F score lower, if yes update the parent because it means its a better path

							//		}
							//	}

							//} while (![openList isEmpty]); // Continue until there is no more available square in the open list (which means there is no path)


							//swap contents of cells
							changeBall(x, y, selectedPieceType);
							changeBall(selectedX, selectedY, POS_FREE);

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
int getLowestFscore()
{
	return 0;
}
int getCurrentSquareIndex()
{
	return 0;
}
bool searchForIndex(int index)
{
	return true;
}