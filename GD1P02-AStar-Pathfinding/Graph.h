#pragma once
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include "Node.h"

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
	void loadMap(std::string _filepath);
	void printMap(int _index);
	void unload(int _index);
	Node* createNode(NodeType _type);
private:
	std::vector<map*> levels;
};

