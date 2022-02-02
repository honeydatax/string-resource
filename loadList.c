#include "resource.h"

int main(int argc,char *argv[]){
	char *i;
	printf("\ec\e[44;36m\n\a\n");	
	if(argc>1){
		i=loadList(argv[1]);
		printList(i);
		freeList(i);
	}
}
