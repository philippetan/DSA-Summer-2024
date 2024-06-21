#include <stdio.h>
#include <stdbool.h>
#include "UID.h"

void initSet(SET *S) {
	S->count = 0;
}

SET set_union(SET A, SET B) {
	SET C;
	initSet(&C);
	
	int a = 0, b = 0;
	while(a < A.count && b < B.count) {
		if(A.elem[a] < B.elem[b]) {
			C.elem[C.count++] = A.elem[a++];
		} else if(A.elem[a] > B.elem[b]) {
			C.elem[C.count++] = B.elem[b++];
		} else {
			C.elem[C.count++] = A.elem[a++];
			b++;
		}
	}	
	while(a < A.count) {
		C.elem[C.count++] = A.elem[a++];
	}
	while(b < B.count) {
		C.elem[C.count++] = B.elem[b++];
	}
	return C;
}

SET set_intersection(SET A, SET B) {
	SET C;
	initSet(&C);
	
	int a = 0, b = 0;
	while(a < A.count && b < B.count) {
		if(A.elem[a] < B.elem[b]) {
			a++;
		} else if(A.elem[a] > B.elem[b]) {
			b++;
		} else {
			C.elem[C.count++] = A.elem[a++];
			b++;
		}
	}
	return C;
}

void insertLastUnique(SET *S, int elem) {
	if(S->count < MAX) {
		int i;
		bool found = false;
		for(i = 0; i < S->count; i++) {
			if(S->elem[i] == elem) {
				found = true;
				break;
			}
		}
		if(!found) {
			S->elem[S->count++] = elem;
		} else {
			printf("--Element %d already exist--\n", elem);
		}
	}
}

void deleteElem(SET *S, int elem) {
	if(S->count != 0) {
		int i, index;
		bool found = false;
		for(i = 0; i < S->count; i++) {
			if(S->elem[i] == elem) {
				found = true;
				index = i;
				break;
			}
		}
		if(found) {
			for(i = index; i < S->count; i++) {
				S->elem[i] = S->elem[i+1];
			}
			S->count--;
		} else {
			printf("--Element %d doesn't exist--\n", elem);
		}
	}
}

void displaySet(SET S) {
	if(S.count != 0) {
		int i;
		for(i = 0; i < S.count; i++) {
			printf("%d ", S.elem[i]);
		}
	}
}
