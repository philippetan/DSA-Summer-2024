#include <stdio.h>
#include <stdlib.h>
#include "UID.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	SET A = {{1, 2, 3, 4, 5, 7}, 6};
	SET B = {{2, 4, 6, 8, 9}, 5};
	
	printf("Set A:\n");
	displaySet(A);
	
	
	printf("\nSet B: \n");
	displaySet(B);
	
	SET C_union = set_union(A, B);
	printf("\n\nUnion of Set A and B:\n");
	displaySet(C_union);
	
	SET C_intersection = set_intersection(A, B);
	printf("\n\nIntersection of Set A and B:\n");
	displaySet(C_intersection);
	
	printf("\n\nIntegrity of the 2 initial sets are ok:");
	printf("\nSet A:\n");
	displaySet(A);
	
	
	printf("\nSet B: \n");
	displaySet(B);
	
	printf("\n\nInserting a unique element in SET A:\n");
	insertLastUnique(&A, 99);
	displaySet(A);
	
	printf("\n\nDeleting an element 8 in SET B:\n");
	deleteElem(&B, 8);
	displaySet(B);
	
	return 0;
}
