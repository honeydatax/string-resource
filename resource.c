#include "resource.h"

int main(int argc,char *argv[]){
	int i;
	if(argc>1){
		i=saveResource(argv[1]);
		printf("%d\n",i);
	}
}
