#include "searchAlgorithm.h"

path searchAlgorithm::myPath;

char** searchAlgorithm::getPath(char** grid, unsigned int& x, unsigned int& y)
{
	searchAlgorithm::myPath.addCoordinate(new coordinate(x, y));
	return nextDirection(grid, x, y);
}
///APPROACH 1: Brute Force 
char** searchAlgorithm::nextDirection(char** grid, int x, int y)
{
	//delete after debug start
	system("cls");
	searchAlgorithm::DprintGrid(20, 20,grid);
	// delete after debug end
	


	// Check if target is within range, if true then return grid 
	if (grid[y - 1][x] == 'D')
	{
		grid[y][x] = 'L';
		return grid;
	}
	if (grid[y][x - 1] == 'D')
	{
		grid[y][x] = 'L';
		return grid;
	}
	if (grid[y + 1][x] == 'D')
	{
		grid[y][x] = 'L';
		return grid;
	}
	if (grid[y][x + 1] == 'D')
	{
		grid[y][x] = 'L';
		return grid;
	}

	if (grid[y - 1][x] == ' ') //still gotta change this line and below such that the grid is accessed by [y][x] instead of [x][y]
	{
		grid[y - 1][x] = '.';
		char** tempgrid = nextDirection(grid, x, y-1);
		if (tempgrid == nullptr) { grid[y - 1][x] = ' '; }
		else return tempgrid;
	}
	if (grid[y][x - 1] == ' ')
	{
		grid[y][x - 1] = '.';
		char** tempgrid = nextDirection(grid, x-1, y);
		if (tempgrid == nullptr) { grid[y][x - 1] = ' '; }
		else return tempgrid;
	}
	if (grid[y + 1][x] == ' ')
	{
		grid[y + 1][x] = '.';
		char** tempgrid = nextDirection(grid, x, y+1);
		if (tempgrid == nullptr) { grid[y + 1][x] = ' '; }
		else return tempgrid;
	}
	if (grid[y][x + 1] == ' ')
	{
		grid[y][x + 1] = '.';
		char** tempgrid = nextDirection(grid, x+1, y);
		if (tempgrid == nullptr) { grid[y][x + 1] = ' '; }
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