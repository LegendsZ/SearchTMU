#include "searchAlgorithm.h"

char** getPath(char** grid, unsigned const int& x, unsigned const int& y)
{
	int** path = nullptr;

	for (int i = 0; i < y; i++)
	{
		
	}


	return grid;
}
///APPROACH 1: Brute Force 
char** nextDirection(char** grid, unsigned const int& x, unsigned const int& y)
{
	/*
	// Check if target is within range, if true then return grid 
	if (grid[x-1][y] == 'D')
	{
		return grid;
	}
	if (grid[x][y-1] == 'D')
	{
		return grid;
	}
	if (grid[x+1][y] == 'D')
	{
		return grid;
	}
	if (grid[x][y+1] == 'D')
	{
		return grid;
	}


	if (grid[x-1][y] == ' ') 
	{
	grid[x-1][y] = 0;
	if nextDirection(grid, x-1, y)

	}
	if (grid[x][y-1] == ' ') 
	{
	grid[x-1][y] = 0;
	nextDirection(grid, x-1, y)
	}
	if (grid[x-1][y] == ' ') 
	{
	grid[x-1][y] = 0;
	nextDirection(grid, x-1, y)
	}
	if (grid[x-1][y] == ' ') 
	{
	grid[x-1][y] = 0;
	nextDirection(grid, x-1, y)
	}

	

	


	//if (grid[x][y] == ' ') {}
	//if (grid[x][y] == ' ') {}
	//if (grid[x][y] == ' ') {}*/
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