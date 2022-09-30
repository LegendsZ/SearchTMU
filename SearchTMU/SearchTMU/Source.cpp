#include <iostream>

char** generateMaze(const int& x, const int& y);
void printGrid(const int& x, const int& y, char** grid);

int main() {
	system("title SearchTMU");

	const unsigned int x = 20;
	const unsigned int y = 20;
	char** grid = nullptr;
	
	grid = generateMaze(x, y);
	printGrid(x,y,grid);

	//garbage collection below
	for (int i = 0; i < x; i++) {
		delete[] grid[i];
	}

	system("pause");
	return 0;
}


char** generateMaze(const int& x, const int& y) {
	char** grid = new char*[y];

	for (int i = 0; i < y; i++) {
		grid[i] = new char[x];
		for (int q = 0; q < x; q++) {
			grid[i][q] = '-';
		}
	}

	/*for (int i = 0; i < x; i++) {
		std::cout << "-";
	}
	for (int i = 0; i < y - 2; i++) {
		std::cout << "\n|";
		for (int q = 0; q < x - 2; q++) {
			std::cout << " ";
		}
		std::cout << "|";
	}
	std::cout << "\n";
	for (int i = 0; i < x; i++) {
		std::cout << "-";
	}
	std::cout << "\n";*/

	return grid;
}

void printGrid(const int& x, const int& y, char** grid) {
	for (int i = 0; i < y; i++) {
		for (int q = 0; q < x; q++) {
			std::cout << grid[i][q];
		}
		std::cout << "\n";
	}
}