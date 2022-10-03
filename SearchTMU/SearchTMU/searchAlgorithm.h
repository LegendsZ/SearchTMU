#pragma once
#include "path.h"

class searchAlgorithm {

public:
	//getPath returns a 2d int array that will 
	char** getPath(char** grid, unsigned const int& x, unsigned const int& y);
	char** nextDirection(char** grid, int x, int y);
private:


};