#ifndef STACK_LINKEDLIST
#define STACK_LINKEDLIST
#include <stdbool.h>

typedef struct node {
	int data;
	struct node *next;
}Node, *NodePtr;

typedef struct {
	NodePtr front;
	NodePtr rear;
}Queue;

void initQueue(Queue *Q);
void enqueue(Queue *Q, int elem);
void dequeue(Queue *Q);
int front(Queue Q);
int rear(Queue Q);
bool isEmpty(Queue Q);
void display(Queue Q);

#endif
