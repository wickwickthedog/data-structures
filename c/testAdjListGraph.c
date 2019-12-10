#ifndef ADJACENT_LIST_GRAPH_TEST
#define ADJACENT_LIST_GRAPH_TEST
#include "AdjListGraph.h"
#endif

#include <stdlib.h>
#include <stdio.h>

int main() {
	char *name = "DEMO GRAPH";
	// printf("%s\n", name);
	printf("----- START -----\n");
	Graph g = newGraph(name, 10);
	showGraph(g);
	printf("\n");	

	printf("----- TEST INSERT -----\n");
	insertEdge(g, 11, 1, 1);
	showGraph(g);
	printf("\n");

	insertEdge(g, 9, 1, 1);
	insertEdge(g, 9, 1, 1);
	insertEdge(g, 9, 2, 1);
	insertEdge(g, 9, 3, 1);
	insertEdge(g, 1, 9, 4);
	insertEdge(g, 1, 1, 0);
	showGraph(g);
	printf("----- TEST INSERT DONE-----\n\n");

	printf("----- TEST REMOVE -----\n");
	removeEdge(g, 9, 1);
	removeEdge(g, 9, 2);
	removeEdge(g, 9, 3);
	showGraph(g);
	printf("----- TEST REMOVE DONE -----\n\n");

	freeGraph(g);
	// showGraph(g);
	printf("----- END -----\n");

	return EXIT_SUCCESS;
}
