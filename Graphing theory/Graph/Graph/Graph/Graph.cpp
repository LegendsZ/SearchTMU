#include "Graph.h"

Graph::Graph(Vertex* starter):
	starterVertex(starter)
{
}

Graph::~Graph()
{
	for (Edge* edge : edges) {
		delete edge;
	}
}

bool Graph::addCoordinate(coordinate* coord)
{
	Vertex* closest = nullptr;
	for (Vertex* v : vertices) {
		if (closest == nullptr || v->myCoordinate->difference(coord) < closest->myCoordinate->difference(coord)) {
			closest = v;
		}
	}
	if (closest) {
		closest->addCoordinate(coord);
	}
	return true;
}

bool Graph::addVertex(Vertex* vertex)
{
	if (starterEdge == nullptr) {
		starterEdge = new Edge(starterVertex, vertex);
	}
	else {
		//algo to find cloest vertex and then attach
		Vertex* closest = nullptr;
		for (Vertex* v : vertices) {
			if (closest == nullptr || v->myCoordinate->difference(vertex->myCoordinate) < closest->myCoordinate->difference(vertex->myCoordinate)) {
				closest = v;
			}
		}
		if (closest) {
			Edge* newEdge = new Edge(closest, vertex);
			vertices.push_back(vertex);
			edges.push_back(newEdge);
		}
	}
	return true;
}
