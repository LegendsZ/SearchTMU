#include "searchAlgorithm.h"

unsigned int searchAlgorithm::abs(int x)
{
	return x < 0 ? x * -1 : x;
}

char** searchAlgorithm::getIntelligentPath(char** grid, const unsigned int& sizeX, const unsigned int& sizeY)
{
	int pX = -1, pY = -1, dX = -1, dY = -1;

	for (int i = 0; i < sizeY; i++) {
		for (int j = 0; j < sizeX; j++) {
			if (grid[i][j] == 'D') {
				dX = j;
				dY = i;
			}
			else if (grid[i][j] == 'X') {
				pX = j;
				pY = i;
			}
		}
	}
	if (pX * pY * dX * dY < 0) {//smth went wrong
		return nullptr;
	}
	int upperY = (pY > dY) ? pY + 1 : dY + 1;
	int lowerY = (pY > dY) ? dY - 1 : pY - 1;
	int upperX = (pX > dX) ? pX + 1 : dX + 1;
	int lowerX = (pX > dX) ? dX - 1 : pX - 1;
	int limit = (sizeX > sizeY) ? sizeX : sizeY;
	for (int i = 0; i < limit; i++)
	{
		char** tempgrid = nextIntelligentDirection(mapLimiter(grid, upperY + i, lowerY - i, upperX + i, lowerX - i, sizeY, sizeX, LIMIT), sizeX, sizeY, pX, pY, dX, dY);
		mapLimiter(grid, upperY + i, lowerY - i, upperX + i, lowerX - i, sizeY, sizeX, RELEASE);

		if (tempgrid != nullptr) return tempgrid;

	}
	return nullptr;
}


char** searchAlgorithm::mapLimiter(char** grid, int upperY, int lowerY, int upperX, int lowerX, int sizeY, int sizeX, int state)
{
	char original = (state == LIMIT) ? ' ' : '!';
	char replacement = (state == LIMIT) ? '!' : ' ';
	if (upperY < sizeY)
	{
		for (int i = 0; i < sizeX; i++)
		{
			if (grid[upperY][i] == original)
			{
				grid[upperY][i] = replacement;
			}
		}
	}
	if (lowerY > 0)
	{
		for (int i = 0; i < sizeX; i++)
		{
			if (grid[lowerY][i] == original)
			{
				grid[lowerY][i] = replacement;
			}
		}
	}
	if (upperX < sizeX)
	{
		for (int i = 0; i < sizeY; i++)
		{
			if (grid[i][upperX] == original)
			{
				grid[i][upperX] = replacement;
			}
		}
	}
	if (lowerX > 0)
	{
		for (int i = 0; i < sizeY; i++)
		{
			if (grid[i][lowerX] == original)
			{
				grid[i][lowerX] = replacement;
			}
		}
	}
	return grid;
}


char** searchAlgorithm::nextIntelligentDirection(char** grid, const int sizeX, const int sizeY, int pX, int pY, int dX, int dY)
{
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


	int ystep = (dY > pY) ? 1 : -1;
	int xstep = (dX > pX) ? 1 : -1;

	//Check magnitude of distance in x and y coordinate
	if (abs(dX - pX) > abs(dY - pY) || dX == pX)
	{
		if (grid[pY][pX + xstep] == ' ')
		{
			grid[pY][pX + xstep] = '.';
			char** tempgrid = nextIntelligentDirection(grid, sizeX, sizeY, pX + xstep, pY, dX, dY);
			if (tempgrid == nullptr) { grid[pY][pX + xstep] = ' '; }
			else return tempgrid;
		}
		if (grid[pY + ystep][pX] == ' ') //still gotta change this line and below such that the grid is accessed by [y][x] instead of [x][y]
		{
			grid[pY + ystep][pX] = '.';
			char** tempgrid = nextIntelligentDirection(grid, sizeX, sizeY, pX, pY + ystep, dX, dY);
			if (tempgrid == nullptr) { grid[pY + ystep][pX] = ' '; }
			else return tempgrid;
		}
		if (grid[pY - ystep][pX] == ' ')
		{
			grid[pY - ystep][pX] = '.';
			char** tempgrid = nextIntelligentDirection(grid, sizeX, sizeY, pX, pY - ystep, dX, dY);
			if (tempgrid == nullptr) { grid[pY - ystep][pX] = ' '; }
			else return tempgrid;
		}
		if (grid[pY][pX - xstep] == ' ')
		{
			grid[pY][pX - xstep] = '.';
			char** tempgrid = nextIntelligentDirection(grid, sizeX, sizeY, pX - xstep, pY, dX, dY);
			if (tempgrid == nullptr) { grid[pY][pX - xstep] = ' '; }
			else return tempgrid;
		}


	}
	else
	{
		if (grid[pY + ystep][pX] == ' ') //still gotta change this line and below such that the grid is accessed by [y][x] instead of [x][y]
		{
			grid[pY + ystep][pX] = '.';
			char** tempgrid = nextIntelligentDirection(grid, sizeX, sizeY, pX, pY + ystep, dX, dY);
			if (tempgrid == nullptr) { grid[pY + ystep][pX] = ' '; }
			else return tempgrid;
		}
		if (grid[pY][pX + xstep] == ' ')
		{
			grid[pY][pX + xstep] = '.';
			char** tempgrid = nextIntelligentDirection(grid, sizeX, sizeY, pX + xstep, pY, dX, dY);
			if (tempgrid == nullptr) { grid[pY][pX + xstep] = ' '; }
			else return tempgrid;
		}
		if (grid[pY][pX - xstep] == ' ')
		{
			grid[pY][pX - xstep] = '.';
			char** tempgrid = nextIntelligentDirection(grid, sizeX, sizeY, pX - xstep, pY, dX, dY);
			if (tempgrid == nullptr) { grid[pY][pX - xstep] = ' '; }
			else return tempgrid;
		}
		if (grid[pY - ystep][pX] == ' ')
		{
			grid[pY - ystep][pX] = '.';
			char** tempgrid = nextIntelligentDirection(grid, sizeX, sizeY, pX, pY - ystep, dX, dY);
			if (tempgrid == nullptr) { grid[pY - ystep][pX] = ' '; }
			else return tempgrid;
		}

	}

	return nullptr;
}
