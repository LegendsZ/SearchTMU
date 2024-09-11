#include "../include/Graph.h"

namespace GraphUtils {
	Graph* createNamedEmptyGraph(std::string name) {
		Graph* graph = new Graph();
		graph->_name = name;
		return graph;
	}

	Graph* readGraphFromFile(std::string graphFileLocation) {
		return nullptr;
	}

	void writeGraphToFile(Graph* graph) {

	}

	void printGraph(Graph* graph) {
		if (!graph) {
			std::cout << "Graph is null\n";
			return;
		}
		std::cout << "Graph Name: " << graph->_name << "\n";
		printGraphNodes(graph);
		printGraphEdges(graph);
	}

	void printGraphNodes(Graph* graph) {
		std::cout << "Nodes: \n|";
		for (std::string node : graph->_nodes) {
			std::cout << node << " ";
		}
		std::cout << "|\n";
	}

	void printGraphEdges(Graph* graph) {
		for (auto const& edge : graph->_edges) {
			std::string attachedNodes = edge.first;
			std::string node1 = attachedNodes.substr(0, attachedNodes.length() / 2);
			std::string node2 = attachedNodes.substr(attachedNodes.length() / 2);
			std::cout << "Edge: " << node1 << " - " << node2 << " Weight: " << edge.second << "\n";
		}
	}

	void deleteGraph(Graph* graph) {
		delete graph;
	}

	bool addNode(Graph* graph, std::string node) {
		if (!nodeExists(graph, node)) {
			graph->_nodes.push_back(node);
			return true;
		}
		return false;
	}

	bool addEdge(Graph* graph, std::string node1, std::string node2, int weight) {
		if (nodeExists(graph, node1) && nodeExists(graph, node2) && !edgeExists(graph, node1,node2)) {
			std::string attachedNodes = node1 + node2;
			graph->_edges[attachedNodes] = weight;
			return true;
		}
		return false;
	}

	bool changeEdgeWeight(Graph* graph, std::string node1, std::string node2, int weight) {
		if (edgeExists(graph, node1, node2)) {
			std::string edgeKey = getEdgeKey(graph, node1, node2);
			graph->_edges[edgeKey] = weight;
			return true;
		}
		return false;
	}

	bool removeNode(Graph* graph, std::string node) {
		if (nodeExists(graph, node)) {
			removeNodeFromVector(graph, node);
			return true;
		}
		return false;
	}

	bool removeEdge(Graph* graph, std::string node1, std::string node2) {
		std::string edgeKey = getEdgeKey(graph, node1, node2);
		if (!edgeKey.empty()) {
			graph->_edges.erase(edgeKey);
			return true;
		}
		return false;
	}

	bool removeEdge(Graph* graph, std::string node1) { //NOTE: could be more efficient
		for (int i = 0; i < graph->_nodes.size(); ++i) {
			std::string node = graph->_nodes[i];
			if (node != node1) {
				removeEdge(graph, node, node1);
			}
		}
		return true;
	}

	inline bool nodeExists(Graph* graph, std::string node) {
		return std::find(graph->_nodes.begin(), graph->_nodes.end(), node) != graph->_nodes.end();
	}

	inline bool edgeExists(Graph* graph, std::string node1, std::string node2) {
		std::string attachedNodesOne = node1 + node2;
		std::string attachedNodesTwo = node2 + node1;
		return (graph->_edges.find(attachedNodesOne) != graph->_edges.end()) || (graph->_edges.find(attachedNodesTwo) != graph->_edges.end());
	}

	inline int getIndexOfNode(Graph* graph, std::string node) {
		return std::find(graph->_nodes.begin(), graph->_nodes.end(), node) - graph->_nodes.begin();
	}

	inline std::string getEdgeKey(Graph* graph, std::string node1, std::string node2) {
		std::string attachedNodesOne = node1 + node2;
		std::string attachedNodesTwo = node2 + node1;
		if (graph->_edges.find(attachedNodesOne) != graph->_edges.end()) {
			return attachedNodesOne;
		}
		if (graph->_edges.find(attachedNodesTwo) != graph->_edges.end()) {
			return attachedNodesTwo;
		}
		return ""; //should never reach here
	}

	inline void removeNodeFromVector(Graph* graph, const std::string& node) {
		graph->_nodes.erase(std::remove(graph->_nodes.begin(), graph->_nodes.end(), node), graph->_nodes.end());
	}
}