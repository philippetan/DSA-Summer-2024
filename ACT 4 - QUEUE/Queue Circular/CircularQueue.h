#ifndef CIRCULAR_QUEUE
#define CIRCULAR_QUEUE
#include <stdbool.h>
#define MAX 10

typedef struct {
	int data[MAX];
	int front;
	int rear;
}circularQ;

void initQueue(circularQ *CQ);
void enqueue(circularQ *CQ, int elem);
void dequeue(circularQ *CQ);
int front(circularQ CQ);
bool isEmpty(circularQ CQ);
bool isFull(circularQ CQ);
void visualizeCQ(circularQ CQ);

#endif
