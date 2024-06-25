#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_PROCESS 15
#include "FCFS.h"

void initQueue(Queue *Q) {
	Q->front = NULL;
	Q->rear = NULL;
}

void initProcess(Process *P) {
	int i;
	for(i = 0; i < MAX_PROCESS; i++) {
		initQueue(&P->procs[i]);
		P->processIDs[i] = 'A' + i;
	}
	P->count = 0;
}

void enqueue(Queue *Q, UserInput input) {
	Node temp = (Node)malloc(sizeof(struct node));
	if(temp != NULL) {
		temp->input = input;
		temp->time.ET = 0;
		temp->time.WT = 0;
		temp->time.TT = 0;
		temp->next = NULL;
		if(Q->front == NULL) {
			Q->front = temp;
		} else {
			Q->rear->next = temp;
		}
		Q->rear = temp;
	}
}

void dequeue(Queue *Q) {
	Node temp = Q->front;
	Q->front = temp->next;
	if(Q->front == NULL) {
		Q->rear = NULL;
	}
	free(temp);
}

int get_BT(Queue Q) {
	return(Q.front != NULL) ? Q.front->input.BT : -1;
}

int get_AT(Queue Q) {
	return(Q.front != NULL) ? Q.front->input.AT : -1;
}

void input(Process *P) {
	int i;
	UserInput input;
	for(i = 0; i < P->count; i++) {
		printf("Process %c: ", i + 65);
		scanf("%d %d", &input.BT, &input.AT);
		enqueue(&P->procs[i], input);
	}
	system("cls");
	calculate(P);
	sort(P);
}

void calculate(Process *P) {
	bool visited[MAX_PROCESS] = { false };
	int i, j = 0, currentTime = 0, minIndex;
	
	while(j < P->count) {
		int minArrival = 999;
		minIndex = -1;
		
		for(i = 0; i < P->count; i++) {
			int AT = get_AT(P->procs[i]);
			if(AT < minArrival && visited[i] == false) {
				minArrival = AT;
				minIndex = i;
			}
		}
		
		int BT = get_BT(P->procs[minIndex]);
		int AT = get_AT(P->procs[minIndex]);
		
		P->procs[minIndex].front->time.ET = currentTime + BT;
		
		currentTime = P->procs[minIndex].front->time.ET;
		
		P->procs[minIndex].front->time.WT = P->procs[minIndex].front->time.ET - BT - AT;
		
		P->procs[minIndex].front->time.TT = P->procs[minIndex].front->time.WT + BT;
		
		visited[minIndex] = true;
		
		j++;
	}
}

int getTotalWT(Process P) {
	int i, total = 0;
	for(i = 0; i < P.count; i++) {
		total += P.procs[i].front->time.WT;
	}
	return total;
}

int getTotalTT(Process P) {
	int i, total = 0;
	for(i = 0; i < P.count; i++) {
		total += P.procs[i].front->time.TT;
	}
	return total;
}

float getAverage(int total, int count) {
	return (float)total/count;
}

void sort(Process *P) {
    int i, j;
    for(i = 0; i < P->count; i++) {
        for(j = i + 1; j < P->count; j++) {
            if(P->procs[i].front->time.ET > P->procs[j].front->time.ET) {
                Queue tempQueue = P->procs[i];
                P->procs[i] = P->procs[j];
                P->procs[j] = tempQueue;
                
                char tempID = P->processIDs[i];
                P->processIDs[i] = P->processIDs[j];
                P->processIDs[j] = tempID;
            }
        }
    }
}

void cleanupProcess(Process *P) {
    int i;
    for (i = 0; i < P->count; i++) {
        while (P->procs[i].front != NULL) {
            dequeue(&P->procs[i]);
        }
    }
}

void visualize(Process P) {
	if(P.count != 0) {
		printf("Total process: %d", P.count);
		printf("\n\nOUTPUT INFORMATION\n");
		printf("%10s : %-5d", "WT Total", getTotalWT(P));
		printf("\n%10s : %-5.2f", "WT Average", getAverage(getTotalWT(P), P.count));
		printf("\n%10s : %-5d", "TT Total", getTotalTT(P));
		printf("\n%10s : %-5.2f", "TT Average", getAverage(getTotalTT(P), P.count));
		printf("\n\n\n%10s | %5s | %5s | %5s | %5s | %5s\n", "PROCESS", "BT", "AT", "ET", "WT", "TT");
    	int i;
    	for(i = 0; i < P.count; i++) { 
    		printf("%10c | %5d | %5d | %5d | %5d | %5d\n", P.processIDs[i], P.procs[i].front->input.BT, P.procs[i].front->input.AT, P.procs[i].front->time.ET, P.procs[i].front->time.WT, P.procs[i].front->time.TT);
		}
		printf("%10s - ----- - ----- - ----- | %5d | %5d\n\n\n", "TOTAL", getTotalWT(P), getTotalTT(P));
	}
	
	cleanupProcess(&P);
}
