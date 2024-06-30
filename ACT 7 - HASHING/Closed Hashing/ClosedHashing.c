#include <stdio.h>
#include "ClosedHashing.h"

void initDict(Dictionary D) {
	int i;
	for(i = 0; i < MAX; i++) {
		D[i].status = EMPTY;
	}
}

int hash(int houseNo) {
	return houseNo % MAX;
}

void insert(Dictionary D, PersonInfo info) {
	int hashVal = hash(info.houseNo);
	int index = hashVal;
	int start = index;
	
	while(D[index].houseNo != info.houseNo && D[index].status != EMPTY && D[index].status != DELETED){
		index = (index + 1) % MAX;
		if(index == start) {
			printf("Error: Dictionary is full. Couldn't insert new info with house no: %d", info.houseNo);
			return;
		}
	}
	if(D[index].status == EMPTY || D[index].status == DELETED) {
		D[index] = info;
	} else if (D[index].houseNo == info.houseNo) {
		printf("Error: Duplicate house no: %d\n", info.houseNo);
		return;
	}
}

void deleteInfoByHouseNo(Dictionary D, int houseNo) {
	int hashVal = hash(houseNo);
	int index = hashVal;
	int start = index;
	
	while(D[index].houseNo != houseNo) {
		index = (index + 1) % MAX;
		if(index == start) {
			printf("Error: Couldn't find house no: %d\n", houseNo);
			return;
		}
	}
	
	if(D[index].houseNo == houseNo) {
		D[index].status = DELETED;
	}
}

void visualize(Dictionary D) {
	int i;
	printf("%-10s %-10s\n", "INDEX", "DATA");
	for(i = 0; i < MAX; i++) {
		printf("%-10d", i);
		if(D[i].status == EMPTY) {
			printf("%-10s", "EMPTY"); 
		} else if(D[i].status == DELETED) {
			printf("%-10s", "DELETED");
		} else {
			printf("%-8s, %-8s %-8d | %-8s, %-8s %-8d", D[i].person.LN, D[i].person.FN, D[i].person.age, D[i].municipality, D[i].barangay, D[i].houseNo);
		}
		printf("\n");
	}
}
