#pragma once
#include <string>
#include <vector>

struct coordinate {
	int x, y;
	int difference(coordinate* other) {
		int lx = other->x - x;
		int ly = other->y - y;
		return sqrt((lx ^ 2) + (ly ^ 2));
	}
};

class Vertex {
public:
	std::vector<coordinate*> coordinates;
	coordinate* myCoordinate;

	bool addCoordinate(coordinate* toAdd);
	Vertex(coordinate* myCoord);
	~Vertex();
private:
};