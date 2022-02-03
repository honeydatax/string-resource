#include "resource.h"

int main(int argc,char *argv[]){
	char *files="my.html";
	int i;
	char *c;
	char *ccc;
	char cc[2080];
	int tt;
	srand(time(NULL));
	ccc=newString(files);
	c=newPointer(ccc);
	printf("\ec\e[46;34m\n\a\n");
	for(i=0;i<10;i++){
		tt=rand() & 0xff;
		tt=tt/5;
		sprintf(cc,"%d,%d",i,tt);
		ccc=newString(cc);
		c=addPointer(c,ccc);
	}
	saveHml(c,files,1,5000);
	printList(c);
	freeList(c);
}
