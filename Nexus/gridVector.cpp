#include "gridVector.h"
#include "board.h"
#include <time.h>
#include <iostream>

void initVector()
{
	srand(time(NULL));
	for (int i = 0; i < freePlacesVec.size(); i++)
	{
		freePlacesVec[i] = i;
	}
}
void fillRandomPlaces()
{
	//checking to see if there are less than 4 blocks
	int iterateNum = NUMBER_OF_RANDOM_BLOCKS;
	if (freePlacesVec.size() < NUMBER_OF_RANDOM_BLOCKS)
	{
		iterateNum = freePlacesVec.size();
	}
	for (int i = 0; i < iterateNum; i++)
	{
		//########################
		int pieceType = 2 + rand() % (7 - 2); // This generates a random number between 2 - 7
		int randomFreeIndex = rand() % freePlacesVec.size();
		int freeIndexData = freePlacesVec[randomFreeIndex];
		int x = freeIndexData % BOARD_WIDTH;
		int y = freeIndexData / BOARD_WIDTH;
		board[x][y] = pieceType;
		removeFreeVecSpot(randomFreeIndex);
	}
}
 
/* assuming width and height are the same
Index % width = X
Index / width = Y
(width * Y) + X = Index

to remove specific spot, find the indexOf(n) vector.erase(index)
to add new taken spot pop_back(n)
*/
void removeFreeVecSpot(int indexToBeRemoved)
{
 	freePlacesVec.erase(freePlacesVec.begin() + indexToBeRemoved);
}
void removeFreeVecSpot(int x, int y)
{
	freePlacesVec.erase(freePlacesVec.begin() + ((BOARD_WIDTH * y) + x));
}
void changeBall(int x, int y, int pieceType)
{
	//check if the pieceType is going to be free
	//IF the pieceType is free, add to the freePlacesVec and set the board spot to free
	//IF the pieceType is NOT free, remove it from the freePlacesVec and set the baord spot to that pieceType
	
	//if a block is being REMOVED i.e adding to the vector
	if (pieceType == POS_FREE)
	{
		//add to freePlacesVec
		freePlacesVec.push_back((BOARD_WIDTH * y) + x);
	}
	//if a block is being ADDED i.e removing from the vector
	else
	{
		int a = ((BOARD_WIDTH * y) + x);
		for (int i = 0; i < freePlacesVec.size(); i++)
		{
			if (a == freePlacesVec[i])
			{
				removeFreeVecSpot(i);
			}
			
		}
		
	}
	board[x][y] = pieceType;
}