#include "Gridmap.h"

std::vector<Gridmap*> Gridmap::maps;


Gridmap::Gridmap(const int& width, const int& height, char def):
	m_width(width), m_height(height)
{
	int size = width * height;
	m_map = new char* [height];
	for (int i = 0; i < height; i++) {
		m_map[i] = new char[width];
		/*for (int j = 0; j < width; j++) {
			m_map[i][j] = def;
		}*/
		memset(&(m_map[i]), def, width);
	}
	m_size = size;
	maps.push_back(this);
}

const int Gridmap::getVal(const int& x, const int& y)
{
	return m_map[y][x];
}

void const Gridmap::print()
{
	for (int i = 0; i < m_height; i++) {
		for (int j = 0; j < m_width; j++) {
			std::cout << m_map[i][j];
		}
		std::cout << "\n";
	}
}
