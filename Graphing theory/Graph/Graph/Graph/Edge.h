#pragma once
#include "Vertex.h"


class Edge {
public:
	Vertex* vertices[2];
	Edge(Vertex* one, Vertex* two);
	~Edge();
private:
};