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

char** searchAlgorithm::getIntelligentPath(char** grid, const unsigned int& sizeX, const unsigned int& sizeY)
{
	int pX = -1, pY = -1, dX = -1, dY = -1;

	for (int i = 0; i < sizeY; i++) {
		for (int j = 0; j < sizeX; j++) {
			if (grid[i][j] == 'D') {
				dX = j;
				dY = i;
			}else if (grid[i][j] == 'X') {
				pX = j;
				pY = i;
			}
		}
	}
	if (pX * pY * dX * dY < 0) {//smth went wrong
		return nullptr;
	}

	return nextIntelligentDirection(grid,sizeX,sizeY,pX,pY,dX,dY);
}

char** searchAlgorithm::nextIntelligentDirection(char** grid, const int sizeX, const int sizeY, int pX, int pY, int dX, int dY)
{
	//system("cls");
	//searchAlgorithm::DprintGrid(sizeX, sizeY, grid);

	//Check if destination is found, if true then return adjusted grid with path
	if (grid[pY - 1][pX] == 'D')
	{
		grid[pY][pX] = 'L';
		return grid;
	}
	if (grid[pY][pX - 1] == 'D')
	{
		grid[pY][pX] = 'L';
		return grid;
	}
	if (grid[pY + 1][pX] == 'D')
	{
		grid[pY][pX] = 'L';
		return grid;
	}
	if (grid[pY][pX + 1] == 'D')
	{
		grid[pY][pX] = 'L';
		return grid;
	}


	int ystep = (dY < pY) ? -1 : 1;
	int xstep = (dX < pX) ? 1 : -1;

	//Check magnitude of distance in x and y coordinate
	if (abs(dX - pX) > abs(dY - pY)) {
		if (dX == pX)
		{
		}
		if (dX < pX) {
			if (grid[pY][pX - 1] == ' ')
			{
				grid[pY][pX - 1] = '.';
				char** tempgrid = nextIntelligentDirection(grid, sizeX, sizeY, pX - 1, pY, dX, dY);
				if (tempgrid == nullptr) { grid[pY][pX - 1] = ' '; }
				else return tempgrid;
			}
			if (grid[pY + ystep][pX] == ' ') //still gotta change this line and below such that the grid is accessed by [y][x] instead of [x][y]
			{
				grid[pY - 1][pX] = '.';
				char** tempgrid = nextIntelligentDirection(grid, sizeX, sizeY, pX, pY + ystep, dX, dY);
				if (tempgrid == nullptr) { grid[pY + ystep][pX] = ' '; }
				else return tempgrid;
			}
			if (grid[pY - ystep][pX] == ' ')
			{
				grid[pY + 1][pX] = '.';
				char** tempgrid = nextIntelligentDirection(grid, sizeX, sizeY, pX, pY - ystep, dX, dY);
				if (tempgrid == nullptr) { grid[pY - ystep][pX] = ' '; }
				else return tempgrid;
			}
			
			if (grid[pY][pX + 1] == ' ')
			{
				grid[pY][pX + 1] = '.';
				char** tempgrid = nextIntelligentDirection(grid, sizeX, sizeY, pX + 1, pY, dX, dY);
				if (tempgrid == nullptr) { grid[pY][pX + 1] = ' '; }
				else return tempgrid;
			}
		}
		else if (dX == pX)
		{
			if (grid[pY + ystep][pX] == ' ') //still gotta change this line and below such that the grid is accessed by [y][x] instead of [x][y]
			{
				grid[pY - 1][pX] = '.';
				char** tempgrid = nextIntelligentDirection(grid, sizeX, sizeY, pX, pY + ystep, dX, dY);
				if (tempgrid == nullptr) { grid[pY + ystep][pX] = ' '; }
				else return tempgrid;
			}
			if (grid[pY - ystep][pX] == ' ')
			{
				grid[pY - 1][pX] = '.';
				char** tempgrid = nextIntelligentDirection(grid, sizeX, sizeY, pX, pY - ystep, dX, dY);
				if (tempgrid == nullptr) { grid[pY - ystep][pX] = ' '; }
				else return tempgrid;
			}
			if (grid[pY][pX - 1] == ' ')
			{
				grid[pY][pX - 1] = '.';
				char** tempgrid = nextIntelligentDirection(grid, sizeX, sizeY, pX - 1, pY, dX, dY);
				if (tempgrid == nullptr) { grid[pY][pX - 1] = ' '; }
				else return tempgrid;
			}
		}
		else {
			if (grid[pY][pX + 1] == ' ')
			{
				grid[pY][pX + 1] = '.';
				char** tempgrid = nextIntelligentDirection(grid, sizeX, sizeY, pX + 1, pY, dX, dY);
				if (tempgrid == nullptr) { grid[pY][pX + 1] = ' '; }
				else return tempgrid;
			}

			if (dY < pY) {
				if (grid[pY - 1][pX] == ' ') //still gotta change this line and below such that the grid is accessed by [y][x] instead of [x][y]
				{
					grid[pY - 1][pX] = '.';
					char** tempgrid = nextIntelligentDirection(grid, sizeX, sizeY, pX, pY - 1, dX, dY);
					if (tempgrid == nullptr) { grid[pY - 1][pX] = ' '; }
					else return tempgrid;
				}
				if (grid[pY + 1][pX] == ' ')
				{
					grid[pY + 1][pX] = '.';
					char** tempgrid = nextIntelligentDirection(grid, sizeX, sizeY, pX, pY + 1, dX, dY);
					if (tempgrid == nullptr) { grid[pY + 1][pX] = ' '; }
					else return tempgrid;
				}
			}
			else {
				if (grid[pY + 1][pX] == ' ')
				{
					grid[pY + 1][pX] = '.';
					char** tempgrid = nextIntelligentDirection(grid, sizeX, sizeY, pX, pY + 1, dX, dY);
					if (tempgrid == nullptr) { grid[pY + 1][pX] = ' '; }
					else return tempgrid;
				}
				if (grid[pY - 1][pX] == ' ') //still gotta change this line and below such that the grid is accessed by [y][x] instead of [x][y]
				{
					grid[pY - 1][pX] = '.';
					char** tempgrid = nextIntelligentDirection(grid, sizeX, sizeY, pX, pY - 1, dX, dY);
					if (tempgrid == nullptr) { grid[pY - 1][pX] = ' '; }
					else return tempgrid;
				}
			}
			if (grid[pY][pX - 1] == ' ')
			{
				grid[pY][pX - 1] = '.';
				char** tempgrid = nextIntelligentDirection(grid, sizeX, sizeY, pX - 1, pY, dX, dY);
				if (tempgrid == nullptr) { grid[pY][pX - 1] = ' '; }
				else return tempgrid;
			}
		}
	}else {
		









	if (dY < pY) {

		if (dY < pY) {
			if (grid[pY - 1][pX] == ' ') //still gotta change this line and below such that the grid is accessed by [y][x] instead of [x][y]
			{
				grid[pY - 1][pX] = '.';
				char** tempgrid = nextIntelligentDirection(grid, sizeX, sizeY, pX, pY - 1, dX, dY);
				if (tempgrid == nullptr) { grid[pY - 1][pX] = ' '; }
				else return tempgrid;
			}
			if (grid[pY + 1][pX] == ' ')
			{
				grid[pY + 1][pX] = '.';
				char** tempgrid = nextIntelligentDirection(grid, sizeX, sizeY, pX, pY + 1, dX, dY);
				if (tempgrid == nullptr) { grid[pY + 1][pX] = ' '; }
				else return tempgrid;
			}
		}
		else {
			if (grid[pY + 1][pX] == ' ')
			{
				grid[pY + 1][pX] = '.';
				char** tempgrid = nextIntelligentDirection(grid, sizeX, sizeY, pX, pY + 1, dX, dY);
				if (tempgrid == nullptr) { grid[pY + 1][pX] = ' '; }
				else return tempgrid;
			}
			if (grid[pY - 1][pX] == ' ') //still gotta change this line and below such that the grid is accessed by [y][x] instead of [x][y]
			{
				grid[pY - 1][pX] = '.';
				char** tempgrid = nextIntelligentDirection(grid, sizeX, sizeY, pX, pY - 1, dX, dY);
				if (tempgrid == nullptr) { grid[pY - 1][pX] = ' '; }
				else return tempgrid;
			}
		}

		if (grid[pY][pX - 1] == ' ')
		{
			grid[pY][pX - 1] = '.';
			char** tempgrid = nextIntelligentDirection(grid, sizeX, sizeY, pX - 1, pY, dX, dY);
			if (tempgrid == nullptr) { grid[pY][pX - 1] = ' '; }
			else return tempgrid;
		}
		
		if (grid[pY][pX + 1] == ' ')
		{
			grid[pY][pX + 1] = '.';
			char** tempgrid = nextIntelligentDirection(grid, sizeX, sizeY, pX + 1, pY, dX, dY);
			if (tempgrid == nullptr) { grid[pY][pX + 1] = ' '; }
			else return tempgrid;
		}
	}
	else if (dY == pY)
	{
		if (dY < pY) {
			if (grid[pY - 1][pX] == ' ') //still gotta change this line and below such that the grid is accessed by [y][x] instead of [x][y]
			{
				grid[pY - 1][pX] = '.';
				char** tempgrid = nextIntelligentDirection(grid, sizeX, sizeY, pX, pY - 1, dX, dY);
				if (tempgrid == nullptr) { grid[pY - 1][pX] = ' '; }
				else return tempgrid;
			}
			if (grid[pY + 1][pX] == ' ')
			{
				grid[pY + 1][pX] = '.';
				char** tempgrid = nextIntelligentDirection(grid, sizeX, sizeY, pX, pY + 1, dX, dY);
				if (tempgrid == nullptr) { grid[pY + 1][pX] = ' '; }
				else return tempgrid;
			}
		}
		else {
			if (grid[pY + 1][pX] == ' ')
			{
				grid[pY + 1][pX] = '.';
				char** tempgrid = nextIntelligentDirection(grid, sizeX, sizeY, pX, pY + 1, dX, dY);
				if (tempgrid == nullptr) { grid[pY + 1][pX] = ' '; }
				else return tempgrid;
			}
			if (grid[pY - 1][pX] == ' ') //still gotta change this line and below such that the grid is accessed by [y][x] instead of [x][y]
			{
				grid[pY - 1][pX] = '.';
				char** tempgrid = nextIntelligentDirection(grid, sizeX, sizeY, pX, pY - 1, dX, dY);
				if (tempgrid == nullptr) { grid[pY - 1][pX] = ' '; }
				else return tempgrid;
			}
		}
		if (grid[pY][pX - 1] == ' ')
		{
			grid[pY][pX - 1] = '.';
			char** tempgrid = nextIntelligentDirection(grid, sizeX, sizeY, pX - 1, pY, dX, dY);
			if (tempgrid == nullptr) { grid[pY][pX - 1] = ' '; }
			else return tempgrid;
		}
	}
	else {

		if (dY < pY) {
			if (grid[pY - 1][pX] == ' ') //still gotta change this line and below such that the grid is accessed by [y][x] instead of [x][y]
			{
				grid[pY - 1][pX] = '.';
				char** tempgrid = nextIntelligentDirection(grid, sizeX, sizeY, pX, pY - 1, dX, dY);
				if (tempgrid == nullptr) { grid[pY - 1][pX] = ' '; }
				else return tempgrid;
			}
			if (grid[pY + 1][pX] == ' ')
			{
				grid[pY + 1][pX] = '.';
				char** tempgrid = nextIntelligentDirection(grid, sizeX, sizeY, pX, pY + 1, dX, dY);
				if (tempgrid == nullptr) { grid[pY + 1][pX] = ' '; }
				else return tempgrid;
			}
		}
		else {
			if (grid[pY + 1][pX] == ' ')
			{
				grid[pY + 1][pX] = '.';
				char** tempgrid = nextIntelligentDirection(grid, sizeX, sizeY, pX, pY + 1, dX, dY);
				if (tempgrid == nullptr) { grid[pY + 1][pX] = ' '; }
				else return tempgrid;
			}
			if (grid[pY - 1][pX] == ' ') //still gotta change this line and below such that the grid is accessed by [y][x] instead of [x][y]
			{
				grid[pY - 1][pX] = '.';
				char** tempgrid = nextIntelligentDirection(grid, sizeX, sizeY, pX, pY - 1, dX, dY);
				if (tempgrid == nullptr) { grid[pY - 1][pX] = ' '; }
				else return tempgrid;
			}
		}

		if (grid[pY][pX + 1] == ' ')
		{
			grid[pY][pX + 1] = '.';
			char** tempgrid = nextIntelligentDirection(grid, sizeX, sizeY, pX + 1, pY, dX, dY);
			if (tempgrid == nullptr) { grid[pY][pX + 1] = ' '; }
			else return tempgrid;
		}
		
		if (grid[pY][pX - 1] == ' ')
		{
			grid[pY][pX - 1] = '.';
			char** tempgrid = nextIntelligentDirection(grid, sizeX, sizeY, pX - 1, pY, dX, dY);
			if (tempgrid == nullptr) { grid[pY][pX - 1] = ' '; }
			else return tempgrid;
		}
	}









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

