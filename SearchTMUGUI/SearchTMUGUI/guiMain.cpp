#include "guiMain.h"

unsigned int information::x = 100;
unsigned int information::y = 100;
unsigned int information::debrisChance = 10;
char** information::grid = nullptr;
TimerCustom* information::timer = nullptr;

System::Void SearchTMUGUI::guiMain::guiMain_Shown(System::Object^ sender, System::EventArgs^ e)
{
	nUDX->Text = information::x.ToString();
	nUDY->Text = information::y.ToString();

	//load below
	srand(time(0));
	information::timer = new TimerCustom();
	//load above
	lblInfo->Hide();
	while (lblTitle->Location.Y != 25) {
		Threading::Thread::Sleep(1);

		lblTitle->Location = System::Drawing::Point(lblTitle->Location.X, lblTitle->Location.Y + 5);
		btnSolve->Location = System::Drawing::Point(btnSolve->Location.X, btnSolve->Location.Y - 10);
		btnSchedule->Location = System::Drawing::Point(btnSchedule->Location.X, btnSchedule->Location.Y - 10);
		btnSettings->Location = System::Drawing::Point(btnSettings->Location.X, btnSettings->Location.Y - 10);

		lblTitle->Refresh();
		btnSolve->Refresh();
		btnSchedule->Refresh();
		btnSettings->Refresh();
	}
}

System::Void SearchTMUGUI::guiMain::btnSolve_Click(System::Object^ sender, System::EventArgs^ e)
{
	information::timer->start();
	information::grid = generateMaze(information::x, information::y, information::debrisChance);
	information::timer->stop();
	while (pbMain->Size.Width != this->Width) {
		pbMain->Size = System::Drawing::Size(pbMain->Size.Width + 2, pbMain->Size.Height + 2);
		pbMain->Location = System::Drawing::Point(pbMain->Location.X - 1, pbMain->Location.Y - 1);
		pbMain->Refresh();
	}
	

	int* width = new int;
	int* height = new int;
	char** mapgrid = readGrid("map.txt", width, height);
	std::vector<pathcell> path;
	TimerCustom* searchAlgoTimer = new TimerCustom();
	coordinate TMUcoords("TMUCoords.txt");
	searchAlgoTimer->start();
	pathcell p = *TMUcoords.getLocation("LIB");
	searchAlgorithm::getIntelligentPath(mapgrid, *width, *height, &path, *TMUcoords.getLocation("SLC"), *TMUcoords.getLocation("TRS"));
	searchAlgoTimer->stop();
	searchAlgoTimer->print();
	lblInfo->Text = searchAlgoTimer->toString();
	SearchTMU::Image image(*width, *height);
	std::cout << "Width: " << *width << std::endl;
	std::cout << "Height: " << *height << std::endl;
	image.setColors(*width, *height, mapgrid);
	image.Export("image.bmp");

	pbMain->Image = System::Drawing::Image::FromFile("image.bmp");
}

System::Void SearchTMUGUI::guiMain::btnSettings_Click(System::Object^ sender, System::EventArgs^ e)
{
	while (lblTitle->Location.Y != -100) {
		//Threading::Thread::Sleep(1);

		lblTitle->Location = System::Drawing::Point(lblTitle->Location.X, lblTitle->Location.Y - 5);
		btnSolve->Location = System::Drawing::Point(btnSolve->Location.X, btnSolve->Location.Y + 10);
		btnSchedule->Location = System::Drawing::Point(btnSchedule->Location.X, btnSchedule->Location.Y + 10);
		btnSettings->Location = System::Drawing::Point(btnSettings->Location.X, btnSettings->Location.Y + 10);
		

		nUDX->Location = System::Drawing::Point(nUDX->Location.X - 9, nUDX->Location.Y);
		lblX->Location = System::Drawing::Point(lblX->Location.X - 9, lblX->Location.Y);
		nUDY->Location = System::Drawing::Point(nUDY->Location.X - 9, nUDY->Location.Y);
		btnSet->Location = System::Drawing::Point(btnSet->Location.X - 9, btnSet->Location.Y);
		btnBack->Location = System::Drawing::Point(btnBack->Location.X - 9, btnBack->Location.Y);

		this->Refresh();
	}
	
}

System::Void SearchTMUGUI::guiMain::btnBack_Click(System::Object^ sender, System::EventArgs^ e)
{
	while (lblTitle->Location.Y != 25) {
		//Threading::Thread::Sleep(1);

		lblTitle->Location = System::Drawing::Point(lblTitle->Location.X, lblTitle->Location.Y + 5);
		btnSolve->Location = System::Drawing::Point(btnSolve->Location.X, btnSolve->Location.Y - 10);
		btnSchedule->Location = System::Drawing::Point(btnSchedule->Location.X, btnSchedule->Location.Y - 10);
		btnSettings->Location = System::Drawing::Point(btnSettings->Location.X, btnSettings->Location.Y - 10);


		nUDX->Location = System::Drawing::Point(nUDX->Location.X + 9, nUDX->Location.Y);
		lblX->Location = System::Drawing::Point(lblX->Location.X + 9, lblX->Location.Y);
		nUDY->Location = System::Drawing::Point(nUDY->Location.X + 9, nUDY->Location.Y);
		btnSet->Location = System::Drawing::Point(btnSet->Location.X + 9, btnSet->Location.Y);
		btnBack->Location = System::Drawing::Point(btnBack->Location.X + 9, btnBack->Location.Y);

		this->Refresh();
	}
}

System::Void SearchTMUGUI::guiMain::btnSet_Click(System::Object^ sender, System::EventArgs^ e)
{
	information::x = int::Parse(nUDX->Text);
	information::y = int::Parse(nUDY->Text);
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
