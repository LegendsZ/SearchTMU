//Customized map assuming each coordinate would need only 3 bits to represent all possible values.

#pragma once
#include <vector>

class Bitmap {
public:
	char vals[3];
	int getVal(int index);
private:
};

class Gridmap {
public:
	static std::vector<Gridmap*> maps;
	Bitmap* m_map;
	Gridmap(const int& width, const int& height);
private:
};