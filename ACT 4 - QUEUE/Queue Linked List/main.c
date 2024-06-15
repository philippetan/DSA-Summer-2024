#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "QueueLL.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Queue Q;
	initQueue(&Q);
	
	enqueue(&Q, 21);
	enqueue(&Q, 14);
	enqueue(&Q, 30);
	dequeue(&Q);
	enqueue(&Q, 22);
	
	display(Q);
	
	printf("\n\nCurrent front: %d", front(Q));
	
	printf("\n\nCurrent rear: %d", rear(Q));
	
	bool result = isEmpty(Q);
	if(result == true) {
		printf("\nn\nQueue is empty");
	} else {
		printf("\n\nQueue is not empty");
	}
	
	return 0;
}
