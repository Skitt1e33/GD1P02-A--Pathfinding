#include "Graph.h"

int main()
{
	Graph graph;
	graph.loadMap("ValidMap1.txt");

	graph.printMap(0);

	return 0;
}