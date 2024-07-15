#include <stdio.h>
#include <stdlib.h>
#include "AdjList.h"

void initList(AdjList L) {
	int i;
	for(i = 0; i < MAX; i++) {
		L[i] = NULL;
	}	
}

void addEdge(AdjList L, char head, char tail) {
	if(head - 'A' < MAX) {
		Node *trav, temp;
		for(trav = &L[head-'A']; *trav != NULL; trav = &(*trav)->next){}
		if(*trav == NULL) {
			temp = (Node)malloc(sizeof(struct node));
			if(temp != NULL) {
				temp->data = tail;
				temp->next = *trav;
				*trav = temp;
			}
		}
	}
	
	if(tail - 'A' < MAX) {
		Node *trav1, temp1;
		for(trav1 = &L[tail - 'A']; *trav1 != NULL; trav1 = &(*trav1)->next){}
		if(*trav1 == NULL) {
			temp1 = (Node)malloc(sizeof(struct node));
			if(temp1 != NULL) {
				temp1->data = head;
				temp1->next = *trav1;
				*trav1 = temp1;
			}
		}
	}
}

void printAdjList(AdjList L) {
	int i;
	printf("Adjacency List:\n\n");
	for(i = 0; i < MAX; i++) {
		printf("%c: ", i + 65);
		if(L[i] == NULL) {
			printf("EMPTY");
		}else {
			Node trav;
			for(trav = L[i]; trav != NULL; trav = trav->next) {
				printf("%c", trav->data);
				if(trav->next != NULL) {
					printf(" -> ");
				}
			}
		}
		
		printf("\n");
	}
}
