#include <stdio.h>
#include <stdlib.h>
#include "StackArray.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Stack S = createStack();
	
	stack_push(&S, 21);
	stack_push(&S, 14);
	stack_push(&S, 22);
	stack_push(&S, 12);
	stack_push(&S, 99);
	stack_push(&S, 69);
	
	stack_pop(&S);
	
	printf("--Visualize--\n");
	visualize(S);
	
	printf("\n--Get Even--\n");
	Stack newStack = get_even(S);
	visualize(newStack);
	
	printf("\n--Display stack--\n");
	display(S);
	
	printf("\n\nCurrent top: %d", stack_top(S));
	
	return 0;
}
