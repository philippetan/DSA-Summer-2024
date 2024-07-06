#ifndef TREES_H
#define TREES_H
#include <stdbool.h>

typedef struct {
	int day, month, year;
}Date;

typedef struct {
	char prodName[20]; // mag agad sa name for less than or greater than ig butang sa BST
	float prodPrice;
	int prodQty;
	Date expDate;  
}Product;

typedef struct node {
	Product item;
	struct node *left, *right;
}NodeType, *NodePtr;

// Queue for BFS
typedef struct queueNode {
	NodePtr treeNode;
	struct queueNode *next;
}QueueNode, *QueueNodePtr;

typedef struct {
	QueueNodePtr front;
	QueueNodePtr rear;
}Queue;

// insert
// delete
// traversal
//		BFS
//		DFS - inorder, preorder, postorder

void initialize(NodePtr *T);
Product populateBST(NodePtr *T);
void insertToBST(NodePtr *T, Product P);
void deleteByName(NodePtr *T, char name[]);
void printBFS(NodePtr T);
void printInorder(NodePtr T);
void printPreorder(NodePtr T);
void printPostorder(NodePtr T);

void initQueue(Queue *Q);
bool isEmpty(Queue Q);
void enqueue(Queue *Q, NodePtr treeNode);
NodePtr dequeue(Queue *Q);

#endif
