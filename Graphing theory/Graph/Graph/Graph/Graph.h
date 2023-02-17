#pragma once
#include "Edge.h"

class Graph {
public:
	//Vertex findClosestVertex();
	std::vector<Edge*> edges;
	std::vector<Vertex*> vertices;
	Vertex* starterVertex;
	Edge* starterEdge;

	Graph(Vertex* starter);
	~Graph();
	bool addCoordinate(coordinate* coord);
	bool addVertex(Vertex* vertex);
private:
};