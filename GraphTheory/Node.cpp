#include "Node.h"


node::node() :location(NULL), connections(NULL)
{}
node::node(std::string location) : location(location), connections(std::vector<node*>()), visited(false)
{}
node::~node()
{}

Node::Node(std::string filename): m_nodes(std::vector<node*>())
{
	std::ifstream f;
	f.open(filename);
	std::string location;
	std::string destination;

	while (f.peek() != EOF)
	{

		f >> location;
		f >> destination;
		node* temp = exists(location);



		if (!temp)
		{
			temp = new node(location);
			m_nodes.push_back(temp);
		}


		
		node* temp2 = exists(destination);
		if (!temp2)
		{
			temp2 = new node(destination);
			m_nodes.push_back(temp2);
		}
		if (!isConnected(temp, temp2) and !isConnected(temp2, temp))
		{
			std::cout << "Added " << location << ":" << destination << std::endl;
			temp->connections.push_back(temp2);
			temp2->connections.push_back(temp);
		}


	}

}

void Node::print()
{
	int i = 0;
	int nth = 0;
	for (node* ni : m_nodes)
	{
		std::cout << "Node number " << nth << std::endl;
		nth++;
		for (node* ci : ni->connections)
		{
			std::cout << ni->location << " " << ci->location << "\n";
			std::cout << i << std::endl;
			i++;
		}
	}
}

void Node::printPath(std::vector<node*>* path)
{
	for (node* ni : *path)
	{
		std::cout << "Node: " << ni->location << std::endl;
	}
}

std::vector<node*>* Node::returnpath(std::string start, std::string end)
{
	std::vector<node*>* path;
	path = new std::vector<node*>();
	node* startnode = exists(start);
	if (!startnode)
	{
		return nullptr;
	}
	node* endnode = exists(end);
	if (!endnode)
	{
		return nullptr;
	}
	int maxdist = m_nodes.size();
	std::vector<node*>* solution = findpath(startnode, endnode, path, maxdist);



	return path;
}

std::vector<node*>* Node::findpath(node* start, node* end, std::vector<node*>* path, int maxdist)
{
	
	path->push_back(start);
	if (start->location == end->location)
	{
		return path;
	}
	if (maxdist == 0) return nullptr;
	start->visited = true;
	//Check first if next node is connected
	for (node* ni : start->connections)
	{
		if (ni->location == end->location)
		{
			path->push_back(end);
			return path;
		}
	}
	for (node* ni : start->connections)
	{
		if (ni->visited) continue;
		maxdist = maxdist - 1;
		std::vector<node*>* temppath = findpath(ni, end, path, maxdist);
		if (temppath == nullptr) {}
		else
		{
			
		}
			return temppath;	
	}
	start->visited = false;
	path->pop_back();
	return nullptr;
}
node* Node::exists(std::string nodename)
{
	for (node* ni : m_nodes)
	{
		if (ni->location == nodename) return ni;
	}
	return nullptr;
}

bool Node::isConnected(node* node1, node* node2)
{
	for (node* ni : node1->connections)
	{
		if (ni->location == node2->location) return true;
	}
	return false;
}