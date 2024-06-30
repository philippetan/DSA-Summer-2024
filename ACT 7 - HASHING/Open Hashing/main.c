#include <stdio.h>
#include <stdlib.h>
#include "OpenHashing.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Dictionary D;
	initDict(D);

	PersonInfo info1 = {{"Tan", "Philippe", 24}, "Liloan", "Yati", 144890};
	PersonInfo info2 = {{"Aguhob", "Victor", 20}, "Oslob", "Nasipit", 14560};
	PersonInfo info3 = {{"Novicio", "Vanessa", 23}, "Lapulapu", "Basak", 784109};
	PersonInfo info4 = {{"Ponce", "Raine", 19}, "Liloan", "Poblacion", 112475};
	
	insertSortByAge(D, info1);
	insertSortByAge(D, info2);
	insertSortByAge(D, info3);
	insertSortByAge(D, info4);
	
	deleteInfoByHouseNo(D, 212121);
	
	visualize(D);
	
	return 0;
}
