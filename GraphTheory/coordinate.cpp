#include "coordinate.h"
#include <fstream>

pathcell::pathcell(int x, int y) : x(x), y(y)
{
}
pathcell::pathcell() : x(0), y(0)
{
}
pathcell::~pathcell()
{
}
Landmark::Landmark() : name(""), cell(pathcell(0, 0))
{
}
Landmark::Landmark(std::string name, unsigned int x, unsigned int y) : name(name), cell(pathcell(x, y))
{
}
Landmark::~Landmark()
{
}
Street::Street(std::string name, int xstart, int xend, int ystart, int yend) : name(name), xstart(xstart), xend(xend), ystart(ystart), yend(yend)
{
}
Street::Street() : name(""), xstart(0), xend(0), ystart(0), yend(0)
{
}
Street::~Street()
{
}



coordinate::coordinate(std::string filename) :landmarks(std::vector<Landmark>()), streets(std::vector<Street>())
{
	std::ifstream f;
	f.open(filename);
	std::string type;
	std::string NAME;
	//std::string X;
	//std::string Y;
	while (f.peek() != EOF)
	{

		f >> type;
		if (type == "L")
		{
			f >> NAME;
			std::string X;
			std::string Y;
			f >> X;
			f >> Y;
			landmarks.push_back(Landmark(NAME, std::stoi(X), std::stoi(Y)));
		}
		else if (type == "S")
		{
			f >> NAME;
			std::string Xstart;
			std::string Xend;
			std::string Ystart;
			std::string Yend;
			f >> Xstart;
			f >> Xend;
			f >> Ystart;
			f >> Yend;
			streets.push_back(Street(NAME, std::stoi(Xstart), std::stoi(Xend), std::stoi(Ystart), std::stoi(Yend)));
		}

		/*f >> NAME;
		f >> X;
		f >> Y;
		landmarks.push_back(Landmark(NAME, std::stoi(X), std::stoi(Y)));*/
	}
	f.close();
}

pathcell* coordinate::getLocation(std::string name)
{
	//Optimize for vector iteration
	for (int i = 0; i < landmarks.size(); i++)
	{

		if (landmarks[i].name == name)
		{
			return &landmarks[i].cell;
		}
	}
	return nullptr;
}

Street* coordinate::getStreet(std::string name)
{
	for (int i = 0; i < streets.size(); i++)
	{
		if (streets[i].name == name)
		{
			return &streets[i];
		}
	}
	return nullptr;
}

Street* coordinate::findStreet(int x, int y)
{
	for (int i = 0; i < streets.size(); i++)
	{
		if (streets[i].xstart <= x && x <= streets[i].xend && streets[i].ystart <= y && y <= streets[i].yend) return &streets[i];
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
