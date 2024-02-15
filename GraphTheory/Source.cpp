#include "Node.h"
#include "coordinate.h"

int main()
{
	coordinate TMUcoords("TMUcoordsv2.txt");
	Node TMUnodes("graph.txt");
	TMUnodes.printPath(TMUnodes.returnpath("DunS", "Gould"));
	std::cout << "Hi" << std::endl;
}