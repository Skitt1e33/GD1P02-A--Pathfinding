#pragma once
#include <vector>
#include "Node.h"

class Graph
{
public:
	Graph();
	~Graph();
	void loadMap();
private:
	std::vector<Node*> nodes;
};

