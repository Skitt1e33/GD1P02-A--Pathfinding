#include "Graph.h"

int main()
{
	Graph graph;
	graph.loadMap("InvalidMap1.txt");

	graph.printMap(0);

	return 0;
}