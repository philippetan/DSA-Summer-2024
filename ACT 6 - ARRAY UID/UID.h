#ifndef UID_H
#define UID_H
#define MAX 10

typedef struct {
	int elem[MAX];
	int count;
}SET;

void initSet(SET *S);
SET set_union(SET A, SET B);
SET set_intersection(SET A, SET B);
void insertLastUnique(SET *S, int elem);
void deleteElem(SET *S, int elem);
void displaySet(SET S);

#endif
