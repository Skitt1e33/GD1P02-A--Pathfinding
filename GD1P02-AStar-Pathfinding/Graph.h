#pragma once
#include "STLIncludes.h"
#include <Windows.h>
#include "Node.h"

// Contains list of all nodes in a map and whether the map is valid or not.
//@breif also contains three validator variables;
struct map
{
	std::vector<Node*> nodes;
	bool valid = false;
	char entranceCount = 0;
	char exitCount = 0;
	char itemCount = 0;
};

class Graph
{
public:
	Graph();
	~Graph();

	// Loads a map at a given filepath.
	//@param _filepath: filepath to file to load
	void loadMap(std::string _filepath);

	// Prints given map to screen.
	//@param _index: index of map to print
	void printMap(int _index);

	// Unloads map at given index
	//@param _index: index of map to unload
	void unload(int _index);

	// Marks a possible path between all items. Ignores walls.
	//@brief searches using a depth first algorithm.
	//@param _index: index of map to search
	void depthFirst(int _index);

	// Handles searching a given graph in a depth first search fashion recursively.
	// //@brief Expands a node at a given index then recursively expands the rest of a given graph.
	//@param _graph: the graph to search
	//@param _index: index of node to expand
	void dFSRecursion(std::vector<Node*>& _graph, int _index);

	// Marks a possible path between all items. Ignores walls.
	//@brief searches using a breadth first algorithm.
	//@param _index: index of map to search
	void breadthFirst(int _index);

	// Marks an efficient route from the entrance to the exit.
	//@brief Searches based on an A* algorithm.
	//@param _index: index of map to search
	void aStar(int _index);

	// Returns euclidean distance between two given nodes
	//@param _n1: first node
	//@param _n2: second node
	float getDistance(Node* _n1, Node* _n2);

	// Returns manhattan distance between two given nodes
	//@param _n1: first node
	//@param _n2: second node
	float getManhattan(Node* _n1, Node* _n2);

	// Passes all items on a map into a given node list
	void getItems(std::vector<Node*>& _itemList, int _index);
private:
	std::vector<map*> levels;
};

