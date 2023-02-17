#include "Vertex.h"

bool Vertex::addCoordinate(coordinate* toAdd)
{
    coordinates.push_back(toAdd);
    return false;
}

Vertex::Vertex(coordinate* myCoord):
    myCoordinate(myCoord)
{
}

Vertex::~Vertex()
{
    delete myCoordinate;
    for (coordinate* x : coordinates) {
        delete x;
    }
}
