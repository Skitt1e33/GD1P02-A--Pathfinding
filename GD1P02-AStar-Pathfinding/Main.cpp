#include "Graph.h"

int main()
{
	Graph graph;
	graph.loadMap("ValidMap2.txt");

	graph.aStar(0);
	graph.printMap(0);

	return 0;
}