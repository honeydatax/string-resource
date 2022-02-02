#include "resource.h"

int main(int argc,char *argv[]){
	char *files="my.lst";
	int i;
	char *c;
	char *ccc;
	char cc[2080];
	ccc=newString(files);
	c=newPointer(ccc);
	printf("\ec\e[46;34m\n\a\n");
	for(i=0;i<20;i++){
		sprintf(cc,"item %d",i);
		ccc=newString(cc);
		c=addPointer(c,ccc);
	}
	saveList(c,files,1,500);
	printList(c);
	freeList(c);
}
