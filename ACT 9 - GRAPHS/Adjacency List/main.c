#include <stdio.h>
#include <stdlib.h>
#include "AdjList.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	AdjList L;
	initList(L);
	
	addEdge(L, 'A', 'B');
	addEdge(L, 'A', 'C');
	addEdge(L, 'A', 'D');

	addEdge(L, 'B', 'C');
	addEdge(L, 'B', 'D');
	addEdge(L, 'B', 'E');

	addEdge(L, 'C', 'D');
	
	addEdge(L, 'D', 'E');	
		
	printAdjList(L);
	
	return 0;
}
