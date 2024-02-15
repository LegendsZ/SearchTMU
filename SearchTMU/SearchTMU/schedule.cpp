#include "schedule.h"

schedule::schedule(std::vector<std::string>*)
{

}

std::vector<std::string>* schedule::getLines(std::string filePath)
{
	std::vector<std::string>* lines = new std::vector<std::string>;
	std::fstream newfile;
	newfile.open(filePath, std::ios::in);
	if (newfile.is_open()) { //error check
		std::string line;
		while (getline(newfile, line)) {
			lines->push_back(line);
		}
		newfile.close();
	}
	return lines;
}

