#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "StackLL.h"

void initStack(Stack *S) {
	*S = NULL;	
}

Stack createStack() {
	Stack S;
	initStack(&S);
	return S;	
}

bool stack_push(Stack *S, int elem) {
	Stack temp = (Stack)malloc(sizeof(struct node));
	if(temp != NULL) {
		temp->data = elem;
		temp->link = *S;
		*S = temp;
		return true;
	}
	return false;
}

bool stack_pop(Stack *S) {
	if(*S != NULL) {
		Stack temp = *S;
		*S = temp->link;
		free(temp);
		return true;
	}
	return false;
}

int stack_top(Stack S) {
	return (S != NULL) ? S->data : -1;
}

void display(Stack S) {  // do not traverse
    if (S == NULL) {
        printf("--STACK IS EMPTY--\n");
        return;
    }

    Stack temp = S; 
    Stack tempStack = createStack(); 
    
    printf("%-10s\n", "DATA");
    while (temp != NULL) {
        int topElem = stack_top(temp);
        stack_push(&tempStack, topElem);
        printf("%-10d\n", topElem);
        temp = temp->link; 
	}
    
    while (tempStack != NULL) {
        int topElem = stack_top(tempStack);
        stack_pop(&tempStack);
    }
}


void visualize(Stack S) {	// you can traverse	
    if (S != NULL) {
        printf("%-10s %-10s %-10s\n", "INDEX", "DATA", "TOP");
        Stack trav;
        int i = 0;
        for (trav = S; trav != NULL; trav = trav->link) {
            printf("%-11d %-9d", i, trav->data);
            if (i == 0) {
                printf("<--%-10s", "top"); 
            }
            printf("\n");
            i++;
        }
    } else {
        printf("--STACK IS EMPTY--\n");
    }
}

Stack get_even(Stack S) {
    Stack evenStack = createStack();
    Stack tempStack = createStack();
    Stack copyStack = createStack();

    while (S != NULL) {
        stack_push(&copyStack, stack_top(S));
        S = S->link;
    }

    while (copyStack != NULL) {
        int topElem = stack_top(copyStack);
        stack_pop(&copyStack);
        if (topElem % 2 == 0) {
            stack_push(&evenStack, topElem);
        } else {
            stack_push(&tempStack, topElem);
        }
    }

    while (tempStack != NULL) {
        stack_pop(&tempStack);
    }

    return evenStack;
}

