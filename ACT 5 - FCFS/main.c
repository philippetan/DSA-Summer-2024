#include <stdio.h>
#include <stdlib.h>
#include "FCFS.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Process P;
	initProcess(&P);
	
	printf("Enter the number of processes: ");
	scanf("%d", &P.count);
	printf("\nEnter BT and AT for: \n");
	input(&P);
	
	visualize(P);
	
	return 0;
}
