#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "StackLL.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Stack S = createStack();
	
	stack_push(&S, 21);
	stack_push(&S, 14);
	stack_push(&S, 22);
	stack_push(&S, 4);
	stack_push(&S, 99);
	
	stack_pop(&S);
	
	printf("--Visualize--\n");
	visualize(S);
	
	printf("\n\n--Display--\n");
	display(S);	
	
	printf("\n\n--Get even--\n");
	Stack evenStack = get_even(S);
	visualize(evenStack);

	printf("\n\nCurrent top: %d\n\n", stack_top(S));
	
	return 0;
}
