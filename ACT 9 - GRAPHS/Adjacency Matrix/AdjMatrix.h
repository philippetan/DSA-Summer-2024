#ifndef ADJMATRIX_H
#define ADJMATRIX_H
#define MAX 5

typedef struct {
	int adjMatrix[MAX][MAX];
	int numOfVertices;
}Graph;

Graph *initGraph(int numOfVertices);
void addEdge(Graph *graph, char head, char tail);
void printGraph(Graph graph);

#endif
