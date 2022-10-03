#include "searchAlgorithm.h"

char** searchAlgorithm::getPath(char** grid, unsigned const int& x, unsigned const int& y)
{
	return nextDirection(grid, x, y);
}
///APPROACH 1: Brute Force 
char** searchAlgorithm::nextDirection(char** grid, int x, int y)
{

	// Check if target is within range, if true then return grid 
	if (grid[x - 1][y] == 'D')
	{
		return grid;
	}
	if (grid[x][y - 1] == 'D')
	{
		return grid;
	}
	if (grid[x + 1][y] == 'D')
	{
		return grid;
	}
	if (grid[x][y + 1] == 'D')
	{
		return grid;
	}

	if (grid[x - 1][y] == ' ')
	{
		grid[x - 1][y] = '.';
		char** tempgrid = nextDirection(grid, x - 1, y);
		if (tempgrid == nullptr) { grid[x - 1][y] = ' '; }
		else return tempgrid;
	}
	if (grid[x][y - 1] == ' ')
	{
		grid[x][y - 1] = '.';
		char** tempgrid = nextDirection(grid, x, y - 1);
		if (tempgrid == nullptr) { grid[x][y - 1] = ' '; }
		else return tempgrid;
	}
	if (grid[x + 1][y] == ' ')
	{
		grid[x + 1][y] = '.';
		char** tempgrid = nextDirection(grid, x + 1, y);
		if (tempgrid == nullptr) { grid[x + 1][y] = ' '; }
		else return tempgrid;
	}
	if (grid[x][y + 1] == ' ')
	{
		grid[x][y + 1] = '.';
		char** tempgrid = nextDirection(grid, x, y + 1);
		if (tempgrid == nullptr) { grid[x][y + 1] = ' '; }
		else return tempgrid;
	}



	return nullptr;

}

/*char** NorthStep(char** grid, unsigned const int& x, unsigned const int& y)
{
	grid[x][y] = '.';
	return nullptr;
}

char** SouthStep(char** grid, unsigned const int& x, unsigned const int& y)
{
	return nullptr;
}

char** WestStep(char** grid, unsigned const int& x, unsigned const int& y)
{
	return nullptr;
}

char** EastStep(char** grid, unsigned const int& x, unsigned const int& y)
{
	return nullptr;
}*/