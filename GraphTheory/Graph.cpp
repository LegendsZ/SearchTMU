#include "Graph.h"
#include <iostream>
#include <fstream>

Graph::Graph(std::string filename)
{

	m_locations = new std::vector<std::string>();
	std::string location;
	std::string destination;
	std::ifstream f;
	f.open(filename);

	while (f.peek() != EOF)
	{
		f >> location;
		f >> destination;
		
		m_locations->push_back(location);
	}
}

int Graph::alreadyIn(std::string location)
{
	for (int i = 0; i < m_locations->size(); i++)
	{
		if (m_locations->at(i) == location)
		{
			return i;
		}
	}
	return m_locations->size();
}
