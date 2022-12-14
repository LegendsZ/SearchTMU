#pragma once
//#include "path.h"
#include <iostream>
#include <vector>
#define LIMIT 1
#define RELEASE 2

struct pathcell
{
	int x, y;
	pathcell();
	pathcell(int x, int y);
	~pathcell();
};
class searchAlgorithm {

public:
	//getPath returns a 2d int array that will 
	//static path myPath;
	static char** getPath(char** grid, unsigned int& x, unsigned int& y);
	static char** nextDirection(char** grid, int x, int y);
	static void printPath(std::vector<pathcell>* path);
	static void getIntelligentPath(char** grid, const unsigned int& sizeX, const unsigned int& sizeY, std::vector<pathcell>* path, pathcell& player, pathcell& dest);
	static char** nextIntelligentDirection(char** grid, const int sizeX, const int sizeY, int pX, int pY, int dX, int dY, int loops, std::vector<pathcell>* path);
	static char** mapLimiter(char** grid, int upperY, int lowerY, int upperX, int lowerX, int sizeY, int sizeX, int state);
	static void DprintGrid(const int& x, const int& y, char** grid) { //debugging purposes only
		for (int i = 0; i < y; i++) {
			for (int q = 0; q < x; q++) {
				std::cout << grid[i][q];
			}
			std::cout << "\n";
		}
	}
private:

};