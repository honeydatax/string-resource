#include "resource.h"

int main(int argc,char *argv[]){
	char *i;
	printf("\ec\e[44;36m\n\a\n");	
	if(argc>1){
		i=loadHtml(argv[1]);
		print(i);
		frees(i);
	}
}
