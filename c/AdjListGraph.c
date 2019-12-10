// Written by wickwickthedog, December 2019
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h> 
#include <assert.h>
#include <string.h>
#include "AdjListGraph.h"

// data struct for Graph's node
typedef struct adjacentListNode {
	Vertex dest;
	int weight;
	struct adjacentListNode *next;
} *AdjList;

struct graphRep {
	char *name;
	int numOfVertices;
	int numOfEdges;
	AdjList *node;
};

// Helper functions
static AdjList insertNode(Vertex v, int weight);
static bool isAdjacent(AdjList edges, Vertex dest); //, int weight);
static void outIncident(AdjList edges);
static void inIncident(Graph g, Vertex dest);

/** 
 * creates an empty graph
 *
 * @param name of the graph
 * @param number of nodes
 * @return ptr to an empty graph
 */
Graph newGraph(char *name, int numOfNodes) {
	Graph g = malloc(sizeof(struct graphRep));
	assert(g != NULL);
	g -> name = name;
	g -> numOfVertices = numOfNodes;
	g -> numOfEdges = 0;
	g -> node = malloc(numOfNodes * sizeof(AdjList));
	AdjList edges = NULL;
	for (int i = 0; i < g -> numOfVertices; i ++) {
		g -> node[i] = edges;
	}
	return g;
}

/**
 * prints all nodes in graph
 * Time Complexity : O(|V| + |E|)
 * 
 * @param graph
 */ 
void  showGraph(Graph g) {
	assert(g != NULL);
	printf("> %s\n", g -> name);
	printf("Number of Vertices: %d\n", g -> numOfVertices);
	printf("Number of edges: %d\n", g -> numOfEdges);
	for (int i = 0; i < g -> numOfVertices; i++) {
		
		printf("Vertex %d: ", i);
		inIncident(g, i);
		if (g -> node[i] != NULL) {
			printf("\n");
			// AdjList edges = g -> node[i];
			// outIncident(edges);
			outIncident(g -> node[i]);
		}
		else printf("\n\tno outgoing edges\n");
	}
}

/** 
 * creates an edge between source and destination
 * Time Complexity: not O(|V|) but O(|V| + |E|) since i didn't keep track of last elem in list
 *
 * @param graph
 * @param soucre vertex/ node
 * @param destination vertex/ node
 * @param weight of the edge/ link
 */
void insertEdge(Graph g, Vertex src, Vertex dest, int weight) {
	assert(g != NULL);
	printf("> Attempt to create link from (%d) to (%d)\n", src, dest);
	if ((src >= 0 && src < g -> numOfVertices ) && (dest >= 0 && dest < g -> numOfVertices)) {
		// AdjList edges = NULL;
		// edges = g -> node[src]; 
		// ^ seg fault
		if (isAdjacent(g -> node[src], dest)) {
			printf("There is already a link from (%d) - (%d)\n", src, dest);
			return;
		} 
		if (g -> node[src] == NULL) {
			g -> node[src] = insertNode(dest, weight);
		}
		else {
			AdjList temp = g -> node[src];
			while(temp -> next != NULL) temp = temp -> next;
			temp -> next = insertNode(dest, weight);
		}
		printf("Created new edge (%d) ~~> (%d) from %s\n", src, dest, g -> name);
		g -> numOfEdges ++;
	}
	else {
		printf("Invalid source Vertex or destination Vertex!\n");
	}
}

/** 
 * removes the edge between source and destination
 * Time Complexity: not O(|V|) but O(|V| + |E|) because delete specific elem in list
 *
 * @param graph
 * @param soucre vertex/ node
 * @param destination vertex/ node
 */
void  removeEdge(Graph g, Vertex src, Vertex dest) {
	assert(g != NULL);
	printf("> Attempt to delete link from (%d) to (%d)\n", src, dest);
	if (isAdjacent(g -> node[src], dest)) {
		AdjList temp = g -> node[src];
		if (temp == g -> node[src] && temp -> dest == dest) {
			g -> node[src] = g -> node[src] -> next;
			free(temp);
		}
		else {
			while(temp) {
				if (temp -> next -> dest == dest) {
					AdjList toDel = temp -> next;
					temp -> next = temp -> next -> next;
					free(toDel); 
				}
				temp = temp -> next;
			}
		}
		printf("Deleted edge (%d) ~~> (%d) from %s\n", src, dest, g -> name);
	}
	else {
		printf("Invalid source Vertex or destination Vertex!\n");
	}

}

/** 
 * free memory for all edges and nodes
 * Time Complexity : O(|V| + |E|) 
 *
 * @param graph
 */
void  freeGraph(Graph g) {
	assert(g != NULL);
	printf("> Attempt to free %s\n", g -> name);
	for(int i = 0; i < g -> numOfVertices; i ++) {
		while(g -> node[i]) {
			free(g -> node[i]);
			g -> node[i] = g -> node[i] -> next;
		}
	}
	free(g -> node);
	free(g);
	printf("freed %s\n", g -> name);
}

/**
 * Helper function - 
 * creates a vertex/ node
 *
 * @param graph
 * @param source vertex/ node
 * @param destination vertex/ node
 * @return ptr to vertex/ node
 */
static AdjList insertNode(Vertex v, int weight) {
	AdjList newLink = malloc(sizeof(AdjList));
	assert(newLink != NULL);
	newLink -> dest = v;
	newLink -> weight = weight;
	newLink -> next = NULL;
	return newLink;
}

/**
 * Helper function - 
 * check is source and destination is adjacent
 * (updates weight if link already exist)
 * Time Complexity: O(|V| + |E|)
 *
 * @param graph
 * @param source vertex/ node
 * @param destination vertex/ node
 * @return true if is adjacent else false
 */
static bool isAdjacent(AdjList edges, Vertex dest) { //, int weight) {
	if (!edges) return false;
	while(edges) {
		if (edges -> dest == dest) {
			// if (edges -> weight != weight) edges -> weight = weight;
			return true;
		}
		edges = edges -> next; 
	}
	return false;
}

/**
 * Helper function - 
 * list of adjacent vertices
 * on outgoing edges from a given vertex.
 * Time Complexity: O(|E|)
 *
 * @param source edges
 */
static void outIncident(AdjList edges) {
	while(edges != NULL) {
		printf("\t~~> (Vertex: %d, weight: %d)\n", edges -> dest, edges -> weight);
		edges = edges -> next;
	}
}

/**
 * Helper function - 
 * list of adjacent vertices
 * on incoming edges from a given vertex.
 * Time Complexity: O(|V| + |E|)
 *
 * @param graph
 * @param given vertex/ node
 */
static void inIncident(Graph g, Vertex dest) {
	for (int i = 0; i < g -> numOfVertices; i ++) {
		AdjList edges = g -> node[i];
		while(edges) {
			if (edges -> dest == dest) {
				printf("\n\t<~~ (Vertex: %d, weight: %d)", i, edges -> weight);
			}
			edges = edges -> next;
		}
	}
}