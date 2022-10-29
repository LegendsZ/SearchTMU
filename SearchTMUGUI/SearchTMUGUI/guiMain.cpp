#include "guiMain.h"

unsigned int information::x = 100;
unsigned int information::y = 100;
unsigned int information::debrisChance = 10;
char** information::grid = nullptr;
TimerCustom* information::timer = nullptr;

System::Void SearchTMUGUI::guiMain::guiMain_Shown(System::Object^ sender, System::EventArgs^ e)
{

	//load below
	srand(time(0));
	information::timer = new TimerCustom();
	//load above
	lblInfo->Hide();
	while (lblTitle->Location.Y != 25) {
		Threading::Thread::Sleep(1);

		lblTitle->Location = System::Drawing::Point(lblTitle->Location.X, lblTitle->Location.Y + 5);
		btnGenerate->Location = System::Drawing::Point(btnGenerate->Location.X, btnGenerate->Location.Y - 7);
		btnSchedule->Location = System::Drawing::Point(btnSchedule->Location.X, btnSchedule->Location.Y - 7);
		btnSettings->Location = System::Drawing::Point(btnSettings->Location.X, btnSettings->Location.Y - 7);

		lblTitle->Refresh();
		btnGenerate->Refresh();
		btnSchedule->Refresh();
		btnSettings->Refresh();
	}
}

char** SearchTMUGUI::guiMain::generateMaze(const unsigned int& x, const unsigned int& y, const unsigned int& debrisChance)
{
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
