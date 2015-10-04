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
	if (numberOfFreeBlocks() < NUMBER_OF_RANDOM_BLOCKS)
	{
		iterateNum = numberOfFreeBlocks();
	}
	for (int i = 0; i < iterateNum; i++)
	{
		int pieceType = 2 + rand() % (7 - 2); // This generates a random number between 2 - 7
		int randomFreeIndex = rand() % freePlacesVec.size();
		int freeIndexData = freePlacesVec[randomFreeIndex];
		int x = freeIndexData % BOARD_WIDTH;
		int y = freeIndexData / BOARD_WIDTH;
		board[x][y] = pieceType;
		removeFreeVecSpot(randomFreeIndex);
	}
}
int numberOfFreeBlocks()
{
	return freePlacesVec.size();
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
	std::cout << "freePlacesVec: " << freePlacesVec.size() << std::endl;
	std::cout << "removeFreeVecSpot: " << "indexToBeRemoved: " << indexToBeRemoved << std::endl;
 	freePlacesVec.erase(freePlacesVec.begin() + indexToBeRemoved);
	std::cout << "freePlacesVec: " << freePlacesVec.size() << std::endl;
}
void removeFreeVecSpot(int x, int y)
{
	std::cout << "freePlacesVec: " << freePlacesVec.size() << std::endl;
	freePlacesVec.erase(freePlacesVec.begin() + ((BOARD_WIDTH * y) + x));
	std::cout << "removeFreeVecSpot: " << "x: " << x << "y: " << y << std::endl;
	std::cout << "freePlacesVec: " << freePlacesVec.size() << std::endl;
}
//void addBall(int x, int y)
//{
//	std::cout << "addBall: " << "x: " << x << "y: " << y << std::endl;
//	//remove vector position
//	removeFreeVecSpot(x, y);
//	//add to board
//	board[x][y] = POS_RED;
//}
void addNewBall(int x, int y)
{
	//try to find index that has the given X Y
	int boardCell = (BOARD_WIDTH * y) + x;
	for (int i = 0; i < freePlacesVec.size(); i++)
	{
		if (freePlacesVec[i] == boardCell)
		{
			removeFreeVecSpot(i);
			board[x][y] = POS_RED;
		}
	}
}
void removeBall(int x, int y)
{
	freePlacesVec.push_back((BOARD_WIDTH * y) + x);
}