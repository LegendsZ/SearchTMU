//Customized map assuming each coordinate would need only 3 bits to represent all possible values.

#pragma once
#include <vector>
#include <iostream>

class Gridmap {
public:
	static std::vector<Gridmap*> maps;
	char** m_map;
	int m_width;
	int m_height;
	int m_size;

	Gridmap(const int& width, const int& height, char def = 0);
	int const getVal(const int& x, const int& y);
	void const print();
private:
};