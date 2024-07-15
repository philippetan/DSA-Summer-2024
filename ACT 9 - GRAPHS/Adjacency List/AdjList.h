#ifndef ADJLIST_H
#define ADJLIST_H
#define MAX 5

typedef struct node {
	char data;
	struct node *next;
}*Node;

typedef Node AdjList[MAX];

void initList(AdjList L);
void addEdge(AdjList L, char head, char tail);
void printAdjList(AdjList L);

#endif
