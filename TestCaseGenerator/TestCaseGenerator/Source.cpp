#include <iostream>
#include <fstream>


char** generateMaze(const unsigned int& x, const unsigned int& y, const unsigned int& debrisChance);
void printGrid(const int& x, const int& y, char** grid);
std::string returnString(const int& x, const int& y, char** grid);

int main() {
	system("title Map Generator");

	const unsigned int maps = 5;
	const unsigned int dChance = 10;
	const unsigned int base = 5;

	char*** grids = new char**[maps];

	for (int i = 0; i < maps; i++) {
		grids[i] = generateMaze(base+i,base+i, dChance);
	}

	for (int i = 0; i < maps; i++) {
		printGrid(base+i, base+i, grids[i]);
	}


	std::ofstream myfile;
	myfile.open("generated_grids.txt");

	std::string output = "";
	for (int i = 0; i < maps; i++) {
		output += returnString(base + i, base + i, grids[i]);
		output += "\n";
	}
	myfile << output << "\n-----------------------------------------------\n" <<output;

	myfile.close();

	//garbage collection
	for (int i = 0; i < maps; i++) {
		for (int j = 0; j < base + i; j++) {
			delete grids[i][j];
		}
	}

	system("pause");
}



char** generateMaze(const unsigned int& x, const unsigned int& y, const unsigned int& debrisChance) {
	char** grid = new char* [y];
	//generates grid
	for (int i = 0; i < y; i++) {
		grid[i] = new char[x];
		for (int q = 0; q < x; q++) {
			if (i == 0 || i == y - 1) {
				grid[i][q] = '-';
			}
			else if (q == 0 || q == x - 1) {
				grid[i][q] = '|';
			}
			else {
				if (rand() % 100 >= debrisChance) {
					grid[i][q] = ' ';
				}
				else { //generates debris
					grid[i][q] = '#';
				}
			}
		}
	}

	//generates player
	while (true) {
		unsigned int xp = rand() % x;
		unsigned int yp = rand() % y;
		if (grid[yp][xp] == ' ') {
			grid[yp][xp] = 'X';
			break;
		}
	}

	//generates destination
	while (true) {
		unsigned int xp = rand() % x;
		unsigned int yp = rand() % y;
		if (grid[yp][xp] == ' ') {
			grid[yp][xp] = 'D';
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

std::string returnString(const int& x, const int& y, char** grid) {
	std::string output = "";
	for (int i = 0; i < y; i++) {
		for (int q = 0; q < x; q++) {
			output += grid[i][q];
		}
		output += "\n";
	}
	return output;
}