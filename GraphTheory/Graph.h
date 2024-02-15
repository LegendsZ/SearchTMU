
#include <vector>
#include <string>


class Graph
{
public:
	int** m_edgeMatrix;
	std::vector<std::string>* m_locations;
	Graph(std::string filename);
	~Graph();
	int alreadyIn(std::string location);
};