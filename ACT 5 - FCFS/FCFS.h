#ifndef FCFS_H
#define FCFS_H
#define MAX_PROCESS 15

typedef struct {
	int BT;
	int AT;
} UserInput;

typedef struct {
	int ET;
	int WT;
	int TT;
} TimeType;

typedef struct node{
	UserInput input;
	TimeType time;
	struct node *next;
} *Node;

typedef struct {
	Node front;
	Node rear;
} Queue;

typedef struct {
    Queue procs[MAX_PROCESS];
    char processIDs[MAX_PROCESS];
    int count;
} Process;

void initQueue(Queue *Q);
void initProcess(Process *P);
void enqueue(Queue *Q, UserInput input);
void dequeue(Queue *Q);
int get_BT(Queue Q);
int get_AT(Queue Q);
void input(Process *P);
void calculate(Process *P);
int getTotalWT(Process P);
int getTotalTT(Process P);
float getAverage(int total, int count);
void sort(Process *P);
void cleanupProcess(Process *P);
void visualize(Process P);

#endif
