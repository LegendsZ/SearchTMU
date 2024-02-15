#include "Graph.h"

Graph::Graph(std::vector<Street> streets)
{
	int** edges = new int* [streets.size()];
	for (int i = 0; i < streets.size(); i++)
	{
		int* temp = new int[streets.size()];
		for (int j = i + 1; j < streets.size(); j++)
		{

		}
	}
}