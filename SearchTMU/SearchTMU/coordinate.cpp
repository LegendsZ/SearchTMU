#include "coordinate.h"
#include <fstream>
Landmark::Landmark() : name(""), cell(pathcell(0,0))
{
}

Landmark::Landmark(std::string name, unsigned int x, unsigned int y) : name(name),cell(pathcell(x, y))
{
}

Landmark::~Landmark()
{
}
coordinate::coordinate(std::string filename):landmarks(std::vector<Landmark>())
{
	std::ifstream f;
	f.open(filename);
	std::string NAME;
	std::string X;
	std::string Y;
	while (f.peek() != EOF)
	{
		f >> NAME;
		f >> X;
		f >> Y;
		landmarks.push_back(Landmark(NAME, std::stoi(X), std::stoi(Y)));
	}
	f.close();
}

pathcell* coordinate::getLocation(std::string name)
{
	for (int i = 0; i < landmarks.size(); i++)
	{

		if (landmarks[i].name == name)
		{
			return &landmarks[i].cell;
		}
	}
	return nullptr;
}

void coordinate::createLandmarks(std::string name, int x, int y)
{
	for (int i = 0; i < landmarks.size(); i++)
	{
		if (landmarks[i].name == name)
		{
			return;
		}
	}
	landmarks.push_back(Landmark(name, x, y));
}
