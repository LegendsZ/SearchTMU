#pragma once
#include "path.h"

class searchAlgorithm {

public:
	//getPath returns a 2d int array that will 
	static path myPath;
	static char** getPath(char** grid, unsigned int& x, unsigned int& y);
	static char** nextDirection(char** grid, int x, int y);
private:


};