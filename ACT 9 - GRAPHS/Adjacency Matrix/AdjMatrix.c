#include "AdjMatrix.h"
#include <stdio.h>
#include <stdlib.h>

Graph *initGraph(int numOfVertices) {
	Graph *graph = (Graph*)malloc(sizeof(Graph));
	if(graph != NULL) {
		graph->numOfVertices = numOfVertices;
		int i, j;
		for(i = 0; i < graph->numOfVertices; i++) {
			for(j = 0; j < graph->numOfVertices; j++) {
				graph->adjMatrix[i][j] = 0;
			}
		}
	}	
	return graph;
}

void addEdge(Graph *graph, char head, char tail) {
	graph->adjMatrix[head - 'A'][tail - 'A'] = 1;
	graph->adjMatrix[tail - 'A'][head - 'A'] = 1;
}
void printGraph(Graph graph) {
	printf("Adjacency Matrix:\n\n");
	printf("  ");
	int i, j;
	
	for(i = 0; i < graph.numOfVertices; i++) {
		printf("%c ", 'A' + i);
	}
	printf("\n");
	
	for(i = 0; i < graph.numOfVertices; i++) {
		printf("%c ", 'A' + i);
		for(j = 0; j < graph.numOfVertices; j++) {
			printf("%d ", graph.adjMatrix[i][j]);
		}
		printf("\n");
	}
}
