#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
class schedule {
public:
	schedule(std::vector<std::string>*);
	std::vector<std::string>* getLines(std::string filePath);
private:
};