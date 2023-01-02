#include "searchAlgorithm.h"
#include "schedule.h"
#include "Image.h"
#include "Timer.h"
#pragma once

char** generateMaze(const unsigned int& x, const unsigned int& y, const unsigned int& debrisChance);
void printGrid(const int& x, const int& y, char** grid);
char** readGrid(std::string fname);

void menu();
void settings();


const unsigned int x = 100;
const unsigned int y = 100;
const unsigned int debrisChance = 10;
char** grid;

int main() {

	char** gridRead = readGrid("readme.txt");
	char** tempgrid = searchAlgorithm::getIntelligentPath(gridRead, 5,4);
	if (tempgrid == nullptr) { std::cout << "No solutions\n"; }
	else printGrid(5, 4, tempgrid); //i only put 5/4 for debugging purpose (need to make a grid class that stores member variables for this etc

	system("pause");
	system("cls");

	system("title Projekt SearchTMU");
	//initialization
	//time_t x = time(0);
	//std::cout << "\nSeed: " << x << "\n\n";
	srand(time(0));
	grid = nullptr;
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
'generate' -> generate route\n\
'solve'    -> solve given map";
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

			grid = generateMaze(x, y, debrisChance);
			//printGrid(x, y, grid);
			std::cout << "\n\n";

			unsigned int pX = 0;
			unsigned int pY = 0;
			for (int i = 0; i < y; i++) {
				for (int j = 0; j < x; j++) {
					if (grid[i][j] == 'X') {
						pX = j;
						pY = i;
					}
				}
			}
			//printGrid(x, y, searchAlgorithm::getPath(grid, pX, pY));

			//BELOW STARTS SOMETHING TO BE DELETED
			char** tgridLOOP = nullptr;
			Timer* searchAlgoTimerLOOP = new Timer();
			unsigned int counter = 0;
			while (tgridLOOP == nullptr) {
				searchAlgoTimerLOOP->start();
				tgridLOOP = searchAlgorithm::getIntelligentPath(grid, x, y);
				searchAlgoTimerLOOP->stop();
				counter++;
			}
			char** tempgrid = tgridLOOP;
			//ABOVE IS SOMETHING TO BE DELETED

			//Timer* searchAlgoTimer = new Timer();
			//searchAlgoTimer->start();
			//char** tempgrid = searchAlgorithm::getIntelligentPath(grid, x, y);
			//searchAlgoTimer->stop();
			
			if (tempgrid == nullptr) { std::cout << "No solutions\n"; }
			else
			{
				printGrid(x, y, tempgrid);
				Image image(x, y);
				for (int i = 0; i < y; i++)
				{
					for (int j = 0; j < x; j++)
					{
						
						image.setColor(Color((float)tempgrid[i][j], (float)tempgrid[i][j], (float)tempgrid[i][j]), j, y - i - 1);
					}
				}
				image.Export("image.bmp");
				//printGrid(x, y, tempgrid);
			}
			//printGrid(x, y, searchAlgorithm::getIntelligentPath(grid, x, y);

			std::cout << "Grid Size: " << x << " x " << y << "\nAmount of attempts: " << counter<<"\n";
			//searchAlgoTimer->print();
			searchAlgoTimerLOOP->print();

			system("pause");
		}
		else if (input == "solve")
		{
			int width = 427;
			int height = 280;
			char** mapgrid = readGrid("map.txt");
			printGrid(427, 280, mapgrid);
			char** solved = searchAlgorithm::getIntelligentPath(mapgrid, 427, 280);
			printGrid(427, 280, solved);
			
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

char** readGrid(std::string fname) {
	std::vector<std::string> lines;
	std::fstream myfile;
	myfile.open(fname, std::ios::in);
	if (myfile.is_open()) {
		std::string line;
		while (getline(myfile, line)) {
			lines.push_back(line);
		}
		myfile.close();
	}
	char** grid = new char* [lines.size()];
	for (int i = 0; i < lines.size(); i++) {
		grid[i] = new char[lines[0].length()];
		for (int j = 0; j < lines[0].length(); j++) {
			grid[i][j] = lines[i][j];
		}
	}
	return grid;
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