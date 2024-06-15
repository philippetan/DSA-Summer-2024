#ifndef STACK_LINKEDLIST
#define STACK_LINKEDLIST
#include <stdbool.h>

typedef struct node {
	int data;
	struct node *link;
}*Stack;

void initStack(Stack *S);
Stack createStack();
bool stack_push(Stack *S, int elem);
bool stack_pop(Stack *S);
int stack_top(Stack S);

void display(Stack S);		// do not traverse
void visualize(Stack S); 	// you can traverse

Stack get_even(Stack S);

#endif
