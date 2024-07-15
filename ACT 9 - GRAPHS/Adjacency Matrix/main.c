#include <stdio.h>
#include <stdlib.h>
#include "AdjMatrix.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Graph *graph = initGraph(5);
	
	addEdge(graph, 'A', 'B');
	addEdge(graph, 'A', 'C');
	addEdge(graph, 'A', 'D');

	addEdge(graph, 'B', 'C');
	addEdge(graph, 'B', 'D');
	addEdge(graph, 'B', 'E');

	addEdge(graph, 'C', 'D');

	addEdge(graph, 'D', 'E');
	
	printGraph(*graph);
	
	return 0;
}
