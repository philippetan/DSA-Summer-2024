#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char name[20];
	int idNum;
	int age;
}info;

typedef struct node {
	info data;
	struct node *next;
}*Node;

void initialize(Node *head);
void insertFirst(Node *head, info stud);
void insertLast(Node *head, info stud);
void insertAtIndex(Node *head, info stud, int pos);
void deleteFirst(Node *head);
void deleteLast(Node *head);
void deleteByIdNum(Node *head, int idNum);
void displayList(Node head);

int main () {
	Node head;	
	initialize(&head);
	
	info stud1 = {"Philippe", 18102695, 24};
	info stud2 = {"Vanessa", 18101414, 23};
	info stud3 = {"Raine", 19101123, 20};
	info stud4 = {"Genevive", 16102211, 28};
	
	printf("--Insert first--\n");
	insertFirst(&head, stud1);
	insertFirst(&head, stud2);
	displayList(head);
	
	printf("\n\n--Insert last--\n");
	insertLast(&head, stud3);
	displayList(head);
	
	printf("\n\n--Insert at index--\n");
	insertAtIndex(&head, stud4, 1);
	displayList(head);
	
	printf("\n\n--Delete first--\n");
	deleteFirst(&head);
	displayList(head);
	
	printf("\n\n--Delete last--\n");
	deleteLast(&head);
	displayList(head);
	
	printf("\n\n--Delete by id num--\n");
	deleteByIdNum(&head, 16102211);
	displayList(head);
	
	return 0;
}

void initialize(Node *head) {
	*head = NULL;
}

void insertFirst(Node *head, info stud) {
	Node temp = (Node)malloc(sizeof(struct node));
	
	if(temp != NULL) {
		temp->data = stud;
		temp->next = *head;
		*head = temp;
	}
}

void insertLast(Node *head, info stud) {
	Node *trav, temp;
	for(trav = head; *trav != NULL; trav = &(*trav)->next) {}
	if(*trav == NULL) {
		temp = (Node)malloc(sizeof(struct node));
		if(temp != NULL) {
			temp->data = stud;
			temp->next = NULL;
			*trav = temp;
		}
	}
}

void insertAtIndex(Node *head, info stud, int pos) {
	Node *trav, temp;
	int index = 0;
	for(trav = head; *trav != NULL && index < pos; index++, trav = &(*trav)->next){}
	temp = (Node)malloc(sizeof(struct node));
	if(temp != NULL) {
		temp->data = stud;
		temp->next = *trav;
		*trav = temp;
	}
}

void deleteFirst(Node *head) {
	Node *trav = head, temp;
	if(*trav != NULL) {
		temp = *trav;
		*trav = temp->next;
		free(temp);
	}
}

void deleteLast(Node *head) {
	Node *trav, temp;
	if(*head != NULL) {
		for(trav = head; *trav != NULL && (*trav)->next != NULL; trav = &(*trav)->next){}
		if(*trav != NULL) {
			temp = *trav;
			*trav = NULL;
			free(temp);
		}
	}
}

void deleteByIdNum(Node *head, int idNum) {
	if(*head != NULL) {
		Node *trav;
		for(trav = head; *trav != NULL && (*trav)->data.idNum != idNum; trav = &(*trav)->next){}
		if(*trav != NULL) {
			Node temp = *trav;
			*trav = temp->next;
			free(temp);
		}
	}
}

void displayList(Node head) {
	Node trav = head;
	printf("%-10s %-10s %-10s\n", "NAME", "IDNUM", "AGE");
	if(head != NULL) {
		for(trav = head; trav!= NULL; trav = trav->next) {
			printf("%-10s %-10d %-10d", trav->data.name, trav->data.idNum, trav->data.age);
			printf("\n");
		}
	}
}



