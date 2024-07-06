#include <stdio.h>
#include <stdlib.h>
#include "Trees.h"

int main(int argc, char *argv[]) {
	NodePtr T;
	initialize(&T);
	
	Product prod = populateBST(&T);
	Product p1 = {"Honda", 9.00, 30, {22, 10, 2024}};
	
	insertToBST(&T, p1);
	
	printf("BFS traversal:\n");
	printBFS(T);
	
	printf("\n\nAfter deleting the root: 'Prada'\n");
	deleteByName(&T, "Prada"); // deleting the root
	
	printf("\n--Inorder traversal:--\n");
	printInorder(T);
	
	printf("\n\n--Preorder traversal:--\n");
	printPreorder(T);
	
	printf("\n\n--Postorder traversal:--\n");
	printPostorder(T);
	
	return 0;
}
