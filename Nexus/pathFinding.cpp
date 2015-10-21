#include "pathFinding.h"
#include "board.h"

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
		if (current == endIndex)
		{
			return true;
		}
		int neighbours[4] = {};
		int sizeOfNeighbours = sizeof(neighbours) / sizeof(int);
		//finding the neighbours
		if (current - BOARD_HEIGHT <= 0)
		{
			neighbours[0] = current;
		}
		else
		{
			neighbours[0] = current - BOARD_HEIGHT;
		}
		if (current + BOARD_HEIGHT >= BOARD_HEIGHT * BOARD_WIDTH)
		{
			neighbours[1] = current;
		}
		else
		{
			neighbours[1] = current + BOARD_HEIGHT;
		}
		if (current % 10 == BOARD_WIDTH - 1)
		{
			neighbours[2] = current;
		}
		else
		{
			neighbours[2] = current + 1;
		}
		if (current % 10 == 0)
		{
			neighbours[3] = current;
		}
		else
		{
			neighbours[3] = current - 1;
		}
		for (int i = 0; i < sizeOfNeighbours; i++)
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