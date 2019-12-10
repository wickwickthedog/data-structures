#ifndef ADJACENT_LIST_GRAPH_H 
#define ADJACENT_LIST_GRAPH_H 

typedef struct graphRep *Graph;
typedef int Vertex;
/** 
 * creates an empty graph
 *
 * @param name of the graph
 * @param number of nodes
 * @return ptr to an empty graph
 */
Graph newGraph(char *name, int numOfNodes);

/** 
 * creates an edge between source and destination
 * Time Complexity: not O(|V|) but O(|V| + |E|) since i didn't keep track of last elem in list
 *
 * @param graph
 * @param soucre vertex/ node
 * @param destination vertex/ node
 * @param weight of the edge/ link
 */
void  insertEdge(Graph g, Vertex src, Vertex dest, int weight);

/** 
 * removes the edge between source and destination
 * Time Complexity: not O(|V|) but O(|V| + |E|) since check duplicates
 *
 * @param graph
 * @param soucre vertex/ node
 * @param destination vertex/ node
 */
void  removeEdge(Graph g, Vertex src, Vertex dest);

/**
 * prints all nodes in graph
 * Time Complexity : O(|V| + |E|)
 * 
 * @param graph
 */
void  showGraph(Graph g);

/** 
 * free memory for all edges and nodes
 * Time Complexity : O(|V| + |E|)
 *
 * @param graph
 */
void  freeGraph(Graph g);

#endif