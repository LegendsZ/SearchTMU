#include <iostream>


char** generateMaze(const unsigned int& x, const unsigned int& y, const unsigned int& debrisChance);
void printGrid(const int& x, const int& y, char** grid);

int main() {
	system("title SearchTMU");
	srand(time(0));
	const unsigned int x = 20;
	const unsigned int y = 20;
	const unsigned int debrisChance = 10;
	char** grid = nullptr;

	grid = generateMaze(x, y, debrisChance);
	printGrid(x,y,grid);

	//garbage collection below
	for (int i = 0; i < x; i++) {
		delete[] grid[i];
	}

	system("pause");
	return 0;
}


char** generateMaze(const unsigned int& x, const unsigned int& y, const unsigned int& debrisChance) {
	char** grid = new char*[y];

	unsigned int iter = rand() % (2 * x + 2 * y - 2);
	unsigned int iterCtr = 0;

	for (int i = 0; i < y; i++) {
		grid[i] = new char[x];
		for (int q = 0; q < x; q++) {
			if (i == 0 || i==y-1) {
				if (iterCtr++ == iter) {
					grid[i][q] = ' ';
				}
				else {
					grid[i][q] = '-';
				}
			}
			else if (q == 0 || q== x-1) {
				if (iterCtr++ == iter) {
					grid[i][q] = ' ';
				}
				else {
					grid[i][q] = '|';
				}
			}
			else {
				if (rand() % 100 >= debrisChance) {
					grid[i][q] = ' ';
				}
				else {
					grid[i][q] = '#';
				}
			}
		}
	}

	while (true) {
		unsigned int xp = rand() % x;
		unsigned int yp = rand() % y;
		if (grid[yp][xp] == ' ') {
			grid[yp][xp] = 'X';
			break;
		}
	}

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