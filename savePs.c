#include "resource.h"

int main(int argc,char *argv[]){
	char *files="my.ps";
	int i;
	char *c;
	char *ccc;
	char cc[2080];
	ccc=newString(files);
	c=newPointer(ccc);
	printf("\ec\e[46;34m\n\a\n");
	for(i=0;i<200;i++){
		sprintf(cc,"item %d",i);
		ccc=newString(cc);
		c=addPointer(c,ccc);
	}
	savePs(c,files,1);
	printList(c);
	freeList(c);
}
