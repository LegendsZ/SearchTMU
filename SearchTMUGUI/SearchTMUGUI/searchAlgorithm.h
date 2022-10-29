#pragma once

#define LIMIT 1
#define RELEASE 2


class searchAlgorithm {
public:
	static unsigned int abs(int x);
	static char** getIntelligentPath(char** grid, const unsigned int& sizeX, const unsigned int& sizeY);
	static char** nextIntelligentDirection(char** grid, const int sizeX, const int sizeY, int pX, int pY, int dX, int dY);
	static char** mapLimiter(char** grid, int upperY, int lowerY, int upperX, int lowerX, int sizeY, int sizeX, int state);
private:
};