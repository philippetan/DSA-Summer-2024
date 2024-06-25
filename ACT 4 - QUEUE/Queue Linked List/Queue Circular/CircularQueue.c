#include <stdio.h>
#include <stdbool.h>
#include "CircularQueue.h"

void initQueue(circularQ *CQ) {
	CQ->front = 0;
	CQ->rear = MAX-1;	
}

void enqueue(circularQ *CQ, int elem) {
	if((CQ->rear + 2) % MAX != CQ->front) {
		CQ->rear = (CQ->rear + 1) % MAX;
		CQ->data[CQ->rear] = elem;
	}
}

void dequeue(circularQ *CQ) {
	if((CQ->rear + 1) % MAX != CQ->front) {
		CQ->front = (CQ->front + 1) % MAX;
	}
}

int front(circularQ CQ) {
	return ((CQ.rear + 1) % MAX != CQ.front) ? CQ.data[CQ.front] : -1;
}

bool isEmpty(circularQ CQ) {
	return ((CQ.rear + 1) % MAX == CQ.front) ? true : false;	
}

bool isFull(circularQ CQ) {
	return ((CQ.rear + 2) % MAX == CQ.front) ? true : false;
}

void visualizeCQ(circularQ Q) {
	printf("%-10s %-10s %-10s\n", "INDEX", "DATA", "FRONT/REAR");
	int i;
	for(i = Q.front; i != (Q.rear + 1) % MAX; i = (i + 1) % MAX) {
		printf("%-10d %-10d", i, Q.data[i]);
		if(i == Q.front) {
			printf("<--FRONT");
		}
		if(i == Q.rear) {
			printf("<--REAR");
		}
		
		printf("\n");
	}
}
