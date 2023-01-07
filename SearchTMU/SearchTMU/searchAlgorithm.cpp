#include "searchAlgorithm.h"
#include <fstream>
//path searchAlgorithm::myPath;

pathcell::pathcell(int x, int y) : x(x), y(y)
{
}
pathcell::pathcell() : x(0), y(0)
{
}
pathcell::~pathcell()
{
}

char** searchAlgorithm::getPath(char** grid, unsigned int& x, unsigned int& y)
{
	//searchAlgorithm::myPath.addCoordinate(new coordinate(x, y));
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

void searchAlgorithm::printPath(std::vector<pathcell>* path)
{
	std::ofstream f;
	f.open("path.txt");
	for (auto pc : *path)
	{
		f << pc.x << " " << pc.y << std::endl;
	}
	f.close();
}

void searchAlgorithm::getIntelligentPath(char** grid, const unsigned int& sizeX, const unsigned int& sizeY, std::vector<pathcell>* path, pathcell& player, pathcell& dest)
{
	std::cout << player.y << ":" << player.x << std::endl;
	std::cout << dest.y << ":" << dest.x << std::endl;
	grid[player.y][player.x] = 'X';
	grid[dest.y][dest.x] = 'D';
	
	if (player.x * player.y * dest.x * dest.y < 0) {//smth went wrong
		return;
	}
	//variables below are used to limit the area of search
	int upperY = (player.y > dest.y) ? player.y + 1 : dest.y + 1;
	int lowerY = (player.y > dest.y) ? dest.y - 1 : player.y - 1;
	int upperX = (player.x > dest.x) ? player.x + 1 : dest.x + 1;
	int lowerX = (player.x > dest.x) ? dest.x - 1 : player.x - 1;
	int limit = (sizeX > sizeY) ? sizeX : sizeY;
	for (int i = 0; i < limit; i++)
	{
		char** tempgrid = nextIntelligentDirection(mapLimiter(grid, upperY + i, lowerY - i, upperX + i, lowerX - i, sizeY, sizeX, LIMIT), sizeX, sizeY, player.x, player.y, dest.x, dest.y,0, path);
		mapLimiter(grid, upperY + i, lowerY - i, upperX + i, lowerX - i, sizeY, sizeX, RELEASE);

		if (tempgrid != nullptr) return;

	}
	return;
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


char** searchAlgorithm::nextIntelligentDirection(char** grid, const int sizeX, const int sizeY, int pX, int pY, int dX, int dY, int loops, std::vector<pathcell>* path)
{
	path->push_back(pathcell(pX, pY));
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
			char** tempgrid = nextIntelligentDirection(grid, sizeX, sizeY, pX + xstep, pY, dX, dY, ++loops, path);
			if (tempgrid == nullptr) { grid[pY][pX + xstep] = ' '; }
			else return tempgrid;
		}
		if (grid[pY + ystep][pX] == ' ') //still gotta change this line and below such that the grid is accessed by [y][x] instead of [x][y]
		{
			grid[pY + ystep][pX] = '.';
			char** tempgrid = nextIntelligentDirection(grid, sizeX, sizeY, pX, pY + ystep, dX, dY, ++loops, path);
			if (tempgrid == nullptr) { grid[pY + ystep][pX] = ' '; }
			else return tempgrid;
		}
		if (grid[pY - ystep][pX] == ' ')
		{
			grid[pY - ystep][pX] = '.';
			char** tempgrid = nextIntelligentDirection(grid, sizeX, sizeY, pX, pY - ystep, dX, dY, ++loops, path);
			if (tempgrid == nullptr) { grid[pY - ystep][pX] = ' '; }
			else return tempgrid;
		}
		if (grid[pY][pX - xstep] == ' ')
		{
			grid[pY][pX - xstep] = '.';
			char** tempgrid = nextIntelligentDirection(grid, sizeX, sizeY, pX - xstep, pY, dX, dY, ++loops, path);
			if (tempgrid == nullptr) { grid[pY][pX - xstep] = ' '; }
			else return tempgrid;
		}


	}
	else
	{
		if (grid[pY + ystep][pX] == ' ') //still gotta change this line and below such that the grid is accessed by [y][x] instead of [x][y]
		{
			grid[pY + ystep][pX] = '.';
			char** tempgrid = nextIntelligentDirection(grid, sizeX, sizeY, pX, pY + ystep, dX, dY, ++loops, path);
			if (tempgrid == nullptr) { grid[pY + ystep][pX] = ' '; }
			else return tempgrid;
		}
		if (grid[pY][pX + xstep] == ' ')
		{
			grid[pY][pX + xstep] = '.';
			char** tempgrid = nextIntelligentDirection(grid, sizeX, sizeY, pX + xstep, pY, dX, dY, ++loops, path);
			if (tempgrid == nullptr) { grid[pY][pX + xstep] = ' '; }
			else return tempgrid;
		}
		if (grid[pY][pX - xstep] == ' ')
		{
			grid[pY][pX - xstep] = '.';
			char** tempgrid = nextIntelligentDirection(grid, sizeX, sizeY, pX - xstep, pY, dX, dY, ++loops, path);
			if (tempgrid == nullptr) { grid[pY][pX - xstep] = ' '; }
			else return tempgrid;
		}
		if (grid[pY - ystep][pX] == ' ')
		{
			grid[pY - ystep][pX] = '.';
			char** tempgrid = nextIntelligentDirection(grid, sizeX, sizeY, pX, pY - ystep, dX, dY, ++loops, path);
			if (tempgrid == nullptr) { grid[pY - ystep][pX] = ' '; }
			else return tempgrid;
		}


	}
	path->pop_back();

	return nullptr;
}

