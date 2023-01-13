#pragma once
#include "Grid.h"

void Grid::print(char** grid, int x, int y)
{
	for (int i = 0; i < y; i++) {
		for (int q = 0; q < x; q++) {
			std::cout << grid[i][q];
		}
		std::cout << "\n";
	}
}
