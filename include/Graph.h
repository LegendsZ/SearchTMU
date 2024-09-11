#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include <vector>
#include <unordered_map>

#ifdef DEBUG
#include <iostream>
#endif

struct Graph {
public:
	std::string _name;
	std::vector<std::string> _nodes;
	std::unordered_map<std::string, int> _edges;
};

namespace GraphUtils {
	//creates an empty graph with a name
	Graph* createNamedEmptyGraph(std::string name);

	//reads a graph from a file
	Graph* readGraphFromFile(std::string graphFileLocation);

	//writes a graph to a file
	void writeGraphToFile(Graph* graph);

	//prints a graph to the console
	void printGraph(Graph* graph);

	//prints a graph's nodes to the console
	void printGraphNodes(Graph* graph);

	//prints a graph's edges to the console
	void printGraphEdges(Graph* graph);

	//deletes a graph
	void deleteGraph(Graph* graph);

	//adds a node to the graph
	bool addNode(Graph* graph, std::string node);

	//adds an edge between two nodes
	bool addEdge(Graph* graph, std::string node1, std::string node2, int weight);

	//changes the weight of an edge between two nodes
	bool changeEdgeWeight(Graph* graph, std::string node1, std::string node2, int weight);

	//removes a node from the graph
	bool removeNode(Graph* graph, std::string node);

	//removes an edge between two nodes
	bool removeEdge(Graph* graph, std::string node1, std::string node2);

	//removes all edges that contain a node
	bool removeEdge(Graph* graph, std::string node1);

	//checks if a node exists in the graph NOTE: USED FOR SAFETY CHECK
	inline bool nodeExists(Graph* graph, std::string node);

	//checks if an edge exists between two nodes NOTE: NO SAFETY CHECKS
	inline bool edgeExists(Graph* graph, std::string node1, std::string node2);

	//returns the index of a node in the graph
	inline int getIndexOfNode(Graph* graph, std::string node);

	//returns the key of an edge in the graph (ex: "A", "B" may give "AB" or "BA")
	inline std::string getEdgeKey(Graph* graph, std::string node1, std::string node2);

	//removes a node from the vector of nodes
	inline void removeNodeFromVector(Graph* graph, const std::string& node);
}

#ifdef DEBUG
#define printGraph(graph) GraphUtils::printGraph(graph)
#define printGraphNodes(graph) GraphUtils::printGraphNodes(graph)
#define printGraphEdges(graph) GraphUtils::printGraphEdges(graph)
#else
#define printGraph(graph)
#define printGraphNodes(graph)
#define printGraphEdges(graph)
#endif

#endif // !GRAPH_H