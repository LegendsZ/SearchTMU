#ifndef GRAPH_H
#define GRAPH_H

#include <string>

struct Graph {

};


namespace GraphUtils {
	Graph* readGraphFromFile(std::string graphFileLocation);
	void writeGraphToFile(Graph* graph);
	void printGraph(Graph* graph);
	void deleteGraph(Graph* graph);
}

#endif // !GRAPH_H
