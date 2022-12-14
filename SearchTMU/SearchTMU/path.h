#pragma once
#include <vector>
#include "coordinate.h"

class path {
public:
	std::vector<coordinate*> coordinates;
	path(std::vector<coordinate*> coordinates);
	path();
	bool addCoordinate(coordinate* coord);
	bool removeCoordinate(coordinate* coord);

	float findDistance();
	float findDisplacement();
	float findSeparation(coordinate* one, coordinate* two);
private:
};