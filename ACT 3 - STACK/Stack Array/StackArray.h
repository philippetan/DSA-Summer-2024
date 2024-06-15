#ifndef STACK_ARRAY
#define STACK_ARRAY
#define MAX 10
#include <stdbool.h>

typedef struct {
	int data[MAX];
	int top;
} Stack;

void initStack(Stack *S);
Stack createStack();

bool stack_push(Stack *S, int elem);
bool stack_pop(Stack *S);
int stack_top(Stack S);

void display(Stack S);		// do not traverse
void visualize(Stack S);	// you can traverse

// others
// create a function that would get all even numbers and return as a new stack 
// removing from the old stack

Stack get_even(Stack S);

#endif
