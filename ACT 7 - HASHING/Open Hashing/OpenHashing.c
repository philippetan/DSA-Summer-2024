#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "OpenHashing.h"
#define MAX 10

void initDict(Dictionary D) {
	int i;
	for(i = 0; i < MAX; i++) {
		D[i] = NULL;
	}
}

int hash(int houseNo) {
	return houseNo % MAX;
}

void insertSortByAge(Dictionary D, PersonInfo info) {	// must be unique when inserting
	Node *trav, temp;
	int hashVal = hash(info.houseNo);
	for(trav = &D[hashVal]; *trav != NULL && (*trav)->info.person.age < info.person.age && (*trav)->info.houseNo != info.houseNo; trav = &(*trav)->next){}
	if(*trav == NULL || (*trav)->info.houseNo != info.houseNo) {
		temp = (Node)malloc(sizeof(struct node));
		if(temp != NULL) {
			temp->info = info;
			temp->next = *trav;
			*trav = temp;
		}
	}
}

void deleteInfoByHouseNo(Dictionary D, int houseNo) {
	Node *trav, temp;
	int hashVal = hash(houseNo);
	for(trav = &D[hashVal]; *trav != NULL && (*trav)->info.houseNo != houseNo; trav = &(*trav)->next){}
	if(*trav != NULL) {
		temp = *trav;
		*trav = temp->next;
		free(temp);
	} else {
		printf("--House no %d doesn't exist--\n", houseNo);
	}
}

void visualize(Dictionary D) {
	int i;
	printf("%-10s %-10s\n", "INDEX", "INFO");
	for(i = 0; i < MAX; i++) {
		printf("%-10d", i);
		if(D[i] == NULL) {
			printf("%-10s", "EMPTY");
		} else {
			Node trav;
			for(trav = D[i]; trav != NULL; trav = trav->next) {
				printf("%s, %s | %d | %s, %s | %d", trav->info.person.LN, trav->info.person.FN, trav->info.person.age, trav->info.barangay, trav->info.municipality, trav->info.houseNo);
				if(trav->next != NULL) {
					printf(" --> ");
				}
			}
		}
		printf("\n");
	}
}
