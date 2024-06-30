#include <stdio.h>
#include <stdlib.h>
#include "ClosedHashing.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Dictionary D;
	initDict(D);
	
	PersonInfo info1 = {{"Tan", "Philippe", 24}, "Liloan", "Yati", 144890};
	PersonInfo info2 = {{"Aguhob", "Victor", 20}, "Oslob", "Nasipit", 457130};
	PersonInfo info3 = {{"Novicio", "Vanessa", 23}, "Lapulapu", "Basak", 981246};
	PersonInfo info4 = {{"Ponce", "Raine", 19}, "Liloan", "Proper", 112475};
	PersonInfo info5 = {{"Abella", "Joseph", 22}, "Liloan", "Bahak", 173258};
	PersonInfo info6 = {{"Tan", "Genevive", 28}, "Liloan", "Crescent", 558888};
	PersonInfo info7 = {{"Tanjiro", "Kamado", 16}, "Nagasaki", "Japan", 145673};
	
	insert(D, info1);
	insert(D, info2);
	insert(D, info3);
	insert(D, info4);
	insert(D, info5);
	insert(D, info6);
	
	deleteInfoByHouseNo(D, 144890);
	deleteInfoByHouseNo(D, 144891);
	
	insert(D, info7);
	
	visualize(D);
	
	return 0;
}
