#include "searchAlgorithm.h"
#include "schedule.h"
#include "Image.h"
#include "Timer.h"
#include "coordinate.h"
#pragma once

char** generateMaze(const unsigned int& x, const unsigned int& y, const unsigned int& debrisChance, pathcell& player, pathcell& dest);
void printGrid(const int& x, const int& y, char** grid);
char** readGrid(std::string fname, int* w, int* h);

void menu();
void settings();


const unsigned int x = 100;
const unsigned int y = 100;
const unsigned int debrisChance = 10;
char** grid = nullptr;

int main() {

	/*
	char** gridRead = readGrid("readme.txt");
	char** tempgrid = searchAlgorithm::getIntelligentPath(gridRead, 5,4);
	if (tempgrid == nullptr) { std::cout << "No solutions\n"; }
	else printGrid(5, 4, tempgrid); //i only put 5/4 for debugging purpose (need to make a grid class that stores member variables for this etc

	system("pause");
	system("cls");*/

	system("title Projekt SearchTMU");

	srand(time(0)); //randomize seed
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
	menu();

	//garbage collection below
	for (int i = 0; i < y; i++) {
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
'solve'    -> solve given map\n\
'travel'   -> go to set locations";
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
			pathcell player;
			pathcell dest;
			grid = generateMaze(x, y, debrisChance, player, dest);
			std::cout << "\n\n";
			//BELOW STARTS SOMETHING TO BE DELETED
			Timer* searchAlgoTimer = new Timer();
			unsigned int counter = 0;
			std::vector<pathcell> path;
			
			searchAlgoTimer->start();
			searchAlgorithm::getIntelligentPath(grid, x, y, &path, player, dest);
			searchAlgoTimer->stop();

			std::cout << "Grid Size: " << x << " x " << y << "\n";
			searchAlgoTimer->print();
			//ABOVE IS SOMETHING TO BE DELETED

			if (path.size() == 0) { std::cout << "No solutions\n"; }
			else
			{
				printGrid(x, y, grid);
				std::cout << "\n Would you like to export? (Y/y/N/n): ";
				std::getline(std::cin, input);
				if (input[0] == 'y' || input[0] == 'Y') {
					Image image(x, y);
					image.setColors(x, y, grid);
					image.Export("image.bmp");
				}
			}
			system("pause");
		}
		else if (input == "solve")
		{
			int* width = new int;
			int* height = new int;
			char** mapgrid = readGrid("map.txt", width, height);
			std::vector<pathcell> path;
			Timer* searchAlgoTimer = new Timer();
			coordinate TMUcoords("TMUCoords.txt");
			searchAlgoTimer->start();
			pathcell p = *TMUcoords.getLocation("LIB");
			searchAlgorithm::getIntelligentPath(mapgrid, *width, *height, &path, *TMUcoords.getLocation("SLC"), *TMUcoords.getLocation("TRS"));
			searchAlgoTimer->stop();
			searchAlgoTimer->print();
			Image image(*width, *height);
			std::cout << "Width: " << *width << std::endl;
			std::cout << "Height: " << *height << std::endl;
			image.setColors(*width, *height, mapgrid);
			image.Export("image.bmp");
			system("pause");
		}
		else if (input == "travel")
		{
			std::string user;
			std::string dest;
			std::cout << "Enter current location: ";
			std::getline(std::cin, user);
			std::cout << "Enter target destination: ";
			std::getline(std::cin, dest);
			int* width = new int;
			int* height = new int;
			char** mapgrid = readGrid("map.txt", width, height);
			std::vector<pathcell> path;
			Timer* searchAlgoTimer = new Timer();
			coordinate TMUcoords("TMUCoords.txt");
			searchAlgoTimer->start();
			searchAlgorithm::getIntelligentPath(mapgrid, *width, *height, &path, *TMUcoords.getLocation(user), *TMUcoords.getLocation(dest));
			searchAlgoTimer->stop();
			searchAlgoTimer->print();
			Image image(*width, *height);
			std::cout << "Width: " << *width << std::endl;
			std::cout << "Height: " << *height << std::endl;
			image.setColors(*width, *height, mapgrid);
			image.Export("image.bmp");
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

char** readGrid(std::string fname, int* w, int* h) {
	*w = 0;
	std::vector<std::string> lines;
	std::fstream myfile;
	myfile.open(fname, std::ios::in);
	if (myfile.is_open()) {
		std::string line;
		while (getline(myfile, line)) {
			lines.push_back(line);
			if (line.length() > *w) {
				*w = line.length();
			}
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
	*h = lines.size();
	return grid;
}

char** generateMaze(const unsigned int& x, const unsigned int& y, const unsigned int& debrisChance, pathcell &player, pathcell &dest) {
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
			player = pathcell(xp, yp);
			break;
		}
	}

	//generates destination
	while (true) {
		unsigned int xp = rand() % x;
		unsigned int yp = rand() % y;
		if (grid[yp][xp] == ' ') {
			grid[yp][xp] = 'D';
			dest = pathcell(xp, yp);
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