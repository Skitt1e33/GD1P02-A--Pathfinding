#pragma once
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <Windows.h>
#include "Node.h"

// Contains list of all nodes in a map and whether the map is valid or not.
//@breif also contains three validator variables;
struct map
{
	std::vector<Node*> nodes;
	bool valid = false;
	int entranceCount;
	int exitCount;
	int itemCount;
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

	// Marks a possible path between all items. Ignores walls.
	//@brief searches using a breadth first algorithm.
	//@param _index: index of map to search
	void breadthFirst();

	// Marks an efficient route from the entrance to the exit.
	//@brief Searches based on an A* algorithm.
	//@param _index: index of map to search
	void aStar(int _index);
private:
	std::vector<map*> levels;
};

