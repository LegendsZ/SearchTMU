#include <iostream>
#include <string>

#include "../include/Graph.h"


void printHelp() {
    std::cout << "Usage:\n";
    std::cout << "--f <graph file path> : Provide path of graph/map to be used\n";
}

int main(int argc, char* argv[]){
	//vars to be parsed from user input
    std::string graphFilePath;

    //assists with parsing
    size_t pos;

    if (argc != 3) {
        std::cout << "Invalid # of arguments!\n";
        return 1;
    }

    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        try {
            if (arg == "--f" && i + 1 < argc) {
				graphFilePath = argv[++i];
                /*if (pos != std::string(argv[i]).length()) {
                    l_log(2, "Invalid argument: " + std::string(argv[i]));
                    printHelp();
                    return 1;
                }*/
            }
            else if (arg == "--help") {
                printHelp();
                return 0;
            }
            else {
                std::cout << "Invalid argument: " << arg << "\n";
                printHelp();
                return 1;
            }
        }
        catch (std::exception e) {
            //l_log(2, "Invalid argument: " + arg);
            std::cout << "Invalid argument: " << arg << "\n";
            printHelp();
            return 1;
        }
    }
	//Graph* graph = GraphUtils::readGraphFromFile(graphFilePath);
	Graph* graph = GraphUtils::createNamedEmptyGraph("TestGraph");
	GraphUtils::addNode(graph, "A");
	GraphUtils::addNode(graph, "B");
	GraphUtils::addNode(graph, "C");
	GraphUtils::addNode(graph, "D");

	GraphUtils::addEdge(graph, "A", "B", 1);
	GraphUtils::addEdge(graph, "A", "C", 2);
	GraphUtils::addEdge(graph, "A", "D", 3);
	GraphUtils::addEdge(graph, "B", "C", 4);
	GraphUtils::addEdge(graph, "B", "D", 5);
	GraphUtils::addEdge(graph, "C", "D", 6);

	printGraph(graph);

    std::cout << "Goodbye!\n";
    return 0;
}