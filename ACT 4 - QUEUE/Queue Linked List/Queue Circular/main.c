#include <stdio.h>
#include <stdlib.h>
#include "CircularQueue.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main () {
	circularQ Q;
	initQueue(&Q);
	
	enqueue(&Q, 21);
	enqueue(&Q, 14);
	
	dequeue(&Q);
	dequeue(&Q);
	
	enqueue(&Q, 69);
	enqueue(&Q, 32);
	enqueue(&Q, 12);
	enqueue(&Q, 78);
	enqueue(&Q, 55);
	enqueue(&Q, 45);
	enqueue(&Q, 77);
	enqueue(&Q, 90);
	
	dequeue(&Q);
	
	enqueue(&Q, 12);
	enqueue(&Q, 777);

	
	dequeue(&Q);
	enqueue(&Q, 245);
	enqueue(&Q, 1221);
	
	visualizeCQ(Q);
	
	return 0;
}
