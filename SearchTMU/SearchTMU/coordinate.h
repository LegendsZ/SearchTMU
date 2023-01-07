#pragma once
#include <string>
#include <vector>
#include "searchAlgorithm.h"
struct Landmark {
	std::string name;
	pathcell cell;
	Landmark();
	Landmark(std::string name, unsigned int x, unsigned int y);
	~Landmark();
};
class coordinate {

public:
	unsigned int x;
	unsigned int y;
	std::vector<Landmark> landmarks;
	coordinate(std::string filename);
	pathcell* getLocation(std::string name);
private:
	void createLandmarks(std::string name, int x, int y);
	std::vector<Landmark> m_Landmarks;
};