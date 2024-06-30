#ifndef OPEN_HASHING
#define OPEN_HASHING
#define MAX 10

typedef struct {
	char LN[24];
	char FN[16];
	int age;
}PersonType;

typedef struct {
	PersonType person;
	char municipality[24];
	char barangay[16];
	int houseNo;		// must be unique to prevent duplication
}PersonInfo;

typedef struct node {
	PersonInfo info;
	struct node *next;
}*Node;

typedef Node Dictionary[MAX];

void initDict(Dictionary D);
int hash(int houseNo);
void insertSortByAge(Dictionary D, PersonInfo info);
void deleteInfoByHouseNo(Dictionary D, int houseNo);
void visualize(Dictionary D);

#endif
