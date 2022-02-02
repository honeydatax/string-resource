#include "resource.h"

int main(int argc,char *argv[]){
	char *files="list.rc";
	int i;
	char *c;
	char *ccc;
	char cc[2080];
	ccc=newString(files);
	c=newPointer(ccc);
	for(i=0;i<20;i++){
		sprintf(cc,"item %d",i);
		ccc=newString(cc);
		c=addPointer(c,ccc);
	}
	saveResource(c,files,1,500);
	freeList(c);
}
