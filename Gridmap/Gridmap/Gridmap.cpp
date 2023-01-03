#include "Gridmap.h"

std::vector<Gridmap*> Gridmap::maps;


Gridmap::Gridmap(const int& width, const int& height)
{
	int size = width * height / 3;
	if (size != (float)width * height / 3) {
		size++;
	}
	m_map = new Bitmap[size];
	memset(m_map, 0, size);
	maps.push_back(this);
}

int Bitmap::getVal(int index)
{
	return (vals[0] << (3 * index)) & 0xE0;
}