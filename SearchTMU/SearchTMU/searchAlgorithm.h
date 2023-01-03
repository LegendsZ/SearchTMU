#pragma once
//#include "path.h"
#include <iostream>

#define LIMIT 1
#define RELEASE 2


class searchAlgorithm {

public:
	//getPath returns a 2d int array that will 
	//static path myPath;
	static char** getPath(char** grid, unsigned int& x, unsigned int& y);
	static char** nextDirection(char** grid, int x, int y);

	static char** getIntelligentPath(char** grid, const unsigned int& sizeX, const unsigned int& sizeY);
	static char** nextIntelligentDirection(char** grid, const int sizeX, const int sizeY,int pX, int pY, int dX, int dY, int loops);
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