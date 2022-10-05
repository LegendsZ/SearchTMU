#include "searchAlgorithm.h"
#include "schedule.h"
#pragma once

char** generateMaze(const unsigned int& x, const unsigned int& y, const unsigned int& debrisChance);
void printGrid(const int& x, const int& y, char** grid);


void menu();
void settings();


const unsigned int x = 8;
const unsigned int y = 8;
const unsigned int debrisChance = 25;
char** grid;

int main() {
	system("title Projekt SearchTMU");
	//initialization
	srand(time(0));
	grid = nullptr;
	grid = generateMaze(x, y, debrisChance);
	std::cout << "\
      ___  ___  ____     ________ ________         \n\
     / _ \\/ _ \\/ __ \\__ / / __/ //_/_  __/         \n\
    / ___/ , _/ /_/ / // / _// ,<   / /            \n\
   /_/__/_/|_|\\____/\\___/___/_/|_|_/_/__  _____  __\n\
  / __/ __/ _ | / _ \\/ ___/ // /_  __/  |/  / / / /\n\
 _\\ \\/ _// __ |/ , _/ /__/ _  / / / / /|_/ / /_/ / \n\
/___/___/_/ |_/_/|_|\\___/_//_/ /_/ /_/  /_/\\____/  \n\
                                                   \n";
	system("pause");
	//printGrid(x,y,grid);
	//std::cout << "\n\n\n===================\n";
	menu();

	//garbage collection below
	for (int i = 0; i < x; i++) {
		delete[] grid[i];
	}
	std::cout << "Deleted everything!\n";
	system("pause");
	return 0;
}

//temporary place for menu i guess
void menu() {
	system("cls");
	while (true) {
		std::cout << "\
   __  ________  ____  __\n\
  /  |/  / __/ |/ / / / /\n\
 / /|_/ / _//    / /_/ / \n\
/_/  /_/___/_/|_/\\____/  \n\
                         \n\n\n";
		std::cout << "\
         commands\n\
'exit' -> exit SearchTMU\n\
'settings' -> open settings\n\
'schedule' -> view schedule\n\
'generate' -> generate route";
		std::cout << "\n\n\n";
		std::cout << ">";
		std::string input;
		std::getline(std::cin, input);
		if (input == "exit") {
			break;
		}
		else if (input == "settings") {
			settings();
		}
		else if (input == "schedule") {
			//view schedule
		}
		else if (input == "generate") {
			const unsigned int x = 20;
			const unsigned int y = 20;
			const unsigned int debrisChance = 10;
			char** grid = nullptr;

			grid = generateMaze(x, y, debrisChance);
			printGrid(x, y, grid);
			std::cout << "\n\n";

			int pX = 0;
			int pY = 0;
			for (int i = 0; i < y; i++) {
				for (int j = 0; j < x; j++) {
					if (grid[i][j] == 'X') {
						pX = j;
						pY = i;
					}
				}
			}
			printGrid(x, y, searchAlgorithm::getPath(grid, pX, pY));
			system("pause");
		}
		else {
			std::cout << "Error: Unrecognized command!\n";
			system("pause");
		}
		system("cls");
	}
}

void settings() {
	system("cls");
	while (true) {
		std::cout << "\
   _________________________  ___________\n\
  / __/ __/_  __/_  __/  _/ |/ / ___/ __/\n\
 _\\ \\/ _/  / /   / / _/ //    / (_ /\\ \\  \n\
/___/___/ /_/   /_/ /___/_/|_/\\___/___/  \n\
                                         \n\n\n";
		std::cout << "\
           commands\n\
'exit' -> exit SearchTMU\n\
'modify schedule' -> open settings";
		std::cout << "\n\n\n";
		std::cout << ">";
		std::string input;
		std::getline(std::cin, input);
		if (input == "exit") {
			break;
		}
		else if (input == "modify schedule") {
			//modify schedule
		}
		else {
			std::cout << "Error: Unrecognized command!\n";
			system("pause");
		}
		system("cls");
	}
}


char** generateMaze(const unsigned int& x, const unsigned int& y, const unsigned int& debrisChance) {
	char** grid = new char*[y];

	//generates grid
	for (int i = 0; i < y; i++) {
		grid[i] = new char[x];
		for (int q = 0; q < x; q++) {
			if (i == 0 || i==y-1) {
				grid[i][q] = '-';
			}
			else if (q == 0 || q== x-1) {
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