#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
struct node
{
	std::string location;
	std::vector<node*> connections;
	bool visited;
	node();
	node(std::string location);
	~node();
};
class Node {
public:
	std::vector<node*> m_nodes;
	std::vector<node*> m_connections;
	Node(std::string filename);
	void print();
	std::vector<node*>* returnpath(std::string start, std::string end);
	std::vector<node*>* findpath(node* start, node* end, std::vector<node*>* path, int maxdist);
	void printPath(std::vector<node*>* path);
private:
	node* exists(std::string nodename);
	bool isConnected(node* node1, node* node2);
};