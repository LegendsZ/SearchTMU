#pragma once
#include <string>
#include <vector>
struct pathcell
{
	int x, y;
	pathcell();
	pathcell(int x, int y);
	~pathcell();
};
struct Landmark {
	std::string name;
	pathcell cell;
	Landmark();
	Landmark(std::string name, unsigned int x, unsigned int y);
	~Landmark();
};
struct Street {
	std::string name;
	int xstart;
	int xend;
	int ystart;
	int yend;
	Street();
	Street(std::string, int xstart, int xend, int ystart, int yend);
	~Street();
};

class coordinate {

public:
	unsigned int x;
	unsigned int y;
	std::vector<Landmark> landmarks;
	std::vector<Street> streets;
	coordinate(std::string filename);
	pathcell* getLocation(std::string name);
private:
	void createLandmarks(std::string name, int x, int y);
	std::vector<Landmark> m_Landmarks;
};