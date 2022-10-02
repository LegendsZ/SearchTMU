#include "path.h"

path::path(std::vector<coordinate*> coordinates): coordinates(coordinates)
{
}

bool path::addCoordinate(coordinate* coord)
{
	coordinates.push_back(coord);
	return true;
}

float path::findDistance()
{
	unsigned totalDistance = 0;
	for (int i = 0; i < coordinates.size()-1; i++) {
		coordinate* now = coordinates[i];
		coordinate* next = coordinates[i + 1];
		totalDistance += findSeparation(now, next);
	}
	return totalDistance;
}

float path::findDisplacement()
{
	return findSeparation(coordinates[0], coordinates[coordinates.size() - 1]);
}

float path::findSeparation(coordinate* one, coordinate* two)
{
	return sqrtf((two->y - one->y)^2 + (two->x - one->x)^2);
}
