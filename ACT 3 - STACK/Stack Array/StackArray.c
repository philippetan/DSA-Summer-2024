#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "StackArray.h"

void initStack(Stack *S) {
	S->top = -1;
}

Stack createStack() {
	Stack S;
	initStack(&S);
	return S;
}

bool stack_push(Stack *S, int elem) {
	if(S->top != MAX-1) {
		S->data[++S->top] = elem;
		return true;
	}
	return false;
}

bool stack_pop(Stack *S) {
	if(S->top != -1) {
		S->top--;
		return true;
	}
	return false;
}

int stack_top(Stack S) {
	return(S.top != -1) ? S.data[S.top] : -1;
}

void display(Stack S) {		// do not traverse
	Stack tempStack = createStack();
	while(S.top != -1) {
		int topElem = stack_top(S);
		stack_pop(&S);
		stack_push(&tempStack, topElem);
	}
	printf("%5s\n", "DATA");
	while(tempStack.top != -1) {
		stack_push(&S, stack_top(tempStack));
		stack_pop(&tempStack);
		printf("%4d\n", S.data[S.top]);
	}
}

void visualize(Stack S) {	// you can traverse
	if(S.top != -1) {
		int i;
		printf("%-10s %-10s %-10s\n", "INDEX", "DATA", "TOP");
		for(i = 0; i <= S.top; i++) {
			printf("%-11d %-9d", i, S.data[i]);
			if(i == S.top) {
				printf("<--%-10s", "top");
			}
		printf("\n");
		}
	} else {
		printf("--STACK IS EMPTY--");
	}
}

Stack get_even(Stack S) {
    Stack newStack = createStack();
    Stack tempStack = createStack();

    while (S.top != -1) {
        int topElem = stack_top(S);
        stack_pop(&S);
        if (topElem % 2 == 0) {
            stack_push(&newStack, topElem);
        } else {
            stack_push(&tempStack, topElem);
        }
    }

    while (tempStack.top != -1) {
        stack_push(&S, stack_top(tempStack));
        stack_pop(&tempStack);
    }

    return newStack;
}

