#include "Graph.h"

int main()
{
	Graph graph;
	graph.loadMap("ValidMap1.txt");

	graph.aStar(0);
	graph.printMap(0);

	return 0;
}