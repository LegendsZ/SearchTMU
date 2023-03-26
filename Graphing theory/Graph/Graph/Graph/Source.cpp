#include "Node.h"

int main()
{
	Node TMUnodes("graph.txt");
	TMUnodes.printPath(TMUnodes.returnpath("DunE", "Gould"));
}