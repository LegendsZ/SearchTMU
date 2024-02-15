#include <vector>
#include <string>
#include "coordinate.h"

class Graph
{
public:
	int** m_edgeMatrix;
	std::vector<std::string>* m_locations;
	Graph(std::vector<Street> streets);
	~Graph();
	int alreadyIn(std::string location);
};