#include "resource.h"

int main(int argc,char *argv[]){
	char *i;
	
	if(argc>1){
		i=loadResource(argv[1]);
		resourceList(i);
		freeList(i);
	}
}
