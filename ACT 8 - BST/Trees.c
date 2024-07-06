#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Trees.h"

void initialize(NodePtr *T) {
	*T = NULL;
}

Product populateBST(NodePtr *T) {
	Product p1[] = {
    		{"Prada", 1.80, 110, {8, 8, 2024}},
    		{"Vuitton", 3.00, 50, {20, 7, 2024}},
    		{"Armani", 1.20, 100, {10, 7, 2024}},
    		{"BMW", 3.00, 60, {5, 8, 2024}},
    		{"Jaguar", 2.00, 200, {15, 7, 2024}},
    		{"Camaro", 2.50, 80, {25, 7, 2024}},
    		{"Zaza", 0.50, 150, {12, 7, 2024}},
    		{"Kappa", 1.50, 75, {22, 7, 2024}},
    		{"Riot", 2.00, 90, {30, 7, 2024}}
			};
	int i;
	for(i = 0; i < 9; i++) {
		insertToBST(T, p1[i]);
	}
}

void insertToBST(NodePtr *T, Product P) {
	NodePtr *trav, temp;
	for(trav = T; *trav != NULL && strcmp((*trav)->item.prodName, P.prodName) != 0; ) {
		trav = (strcmp((*trav)->item.prodName, P.prodName) > 0) ? &(*trav)->left : &(*trav)->right;
	}
	
	if(*trav == NULL) {
		temp = (NodePtr)malloc(sizeof(NodeType));
		if(temp != NULL) {
			temp->item = P;
			temp->left = NULL;
			temp->right = NULL;
			*trav = temp;
		}
	}
}

void deleteByName(NodePtr *T, char name[]) {
	NodePtr *trav = T, temp;
	for(trav = T; *trav != NULL && strcmp((*trav)->item.prodName, name) != 0; ) {
		trav = (strcmp((*trav)->item.prodName, name) > 0) ? &(*trav)->left : &(*trav)->right;
	}

	if(*trav != NULL) {
		temp = *trav;
		if((*trav)->left == NULL) {
			*trav = temp->right;
		} else if((*trav)->right == NULL) {
			*trav = temp->left;
		} else if((*trav)->left == NULL && (*trav)->right == NULL) {
			*trav = NULL;
		} else {
			NodePtr *trav2, *successor;
			trav2 = &(*trav)->left;
			while(*trav2 != NULL) {
				successor = trav2;
				trav2 = &(*trav2)->right;
			}
			temp = *successor;
			(*trav)->item = temp->item;
			*successor = NULL;
		}
		free(temp);
	} else {
		printf("Product name: %s doesn't exist.\n\n", name);
	}
}

void printBFS(NodePtr T) {
	Queue Q;
	initQueue(&Q);
	enqueue(&Q, T);
	
	while(!isEmpty(Q)) {
		NodePtr current = dequeue(&Q);
		if(current != NULL) {
			printf("%s ", current->item.prodName);
			enqueue(&Q, current->left);
			enqueue(&Q, current->right);
		}
	}
}

void printInorder(NodePtr T) {
	if(T != NULL) {
		printInorder(T->left);
		printf("%s ", T->item.prodName);
		printInorder(T->right);
	}
}

void printPreorder(NodePtr T) {
	if(T != NULL) {
		printf("%s ", T->item.prodName);
		printPreorder(T->left);
		printPreorder(T->right);
	}
}

void printPostorder(NodePtr T) {
	if(T != NULL) {
		printPostorder(T->left);
		printPostorder(T->right);
		printf("%s ", T->item.prodName);
	}
}

void initQueue(Queue *Q) {
	Q->front = NULL;
	Q->rear = NULL;	
}

bool isEmpty(Queue Q) {
	return (Q.front == NULL) ? true : false;
}

void enqueue(Queue *Q, NodePtr treeNode) {
	QueueNodePtr newQueueNode = (QueueNodePtr)malloc(sizeof(QueueNode));
	if(newQueueNode != NULL) {
		newQueueNode->treeNode = treeNode;
		newQueueNode->next = NULL;
		if(Q->rear == NULL) {
			Q->front = newQueueNode;
		} else {
			Q->rear->next = newQueueNode;
		}
		Q->rear = newQueueNode;
	}	
}

NodePtr dequeue(Queue *Q) {
	if(!isEmpty(*Q)) {
		QueueNodePtr temp = Q->front;
        NodePtr treeNode = temp->treeNode;
        Q->front = temp->next;
        
        if (Q->front == NULL) {
            Q->rear = NULL;
        }
        
        free(temp);
        return treeNode;
	}
}
