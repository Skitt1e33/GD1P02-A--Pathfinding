#pragma once
#include <vector>
#include <fstream>
#include <string>
#include "Node.h"

struct map
{
	std::vector<Node*> nodes;
	bool valid = false;

};

class Graph
{
public:
	Graph();
	~Graph();
	void loadMap(std::string _filepath);
	void unload(int _index);
	Node* createNode(NodeType _type);
private:
	std::vector<map> levels;
};

