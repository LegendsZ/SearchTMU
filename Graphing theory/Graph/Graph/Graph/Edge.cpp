#include "Edge.h"

Edge::Edge(Vertex* one, Vertex* two)
{
	vertices[0] = one;
	vertices[1] = two;
}

Edge::~Edge()
{
	if (vertices[0] != 0) {
		delete vertices[0];
		vertices[0]=0;
	}
	if (vertices[1] != 0) {
		delete vertices[1];
		vertices[1]=0;
	}
}
