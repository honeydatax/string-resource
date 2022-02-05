#include "resource.h"
#define maxs 1000
int main(int argc,char *argv[]){
	char *files="my.txt";
	int mmax=100;
	int *ii;
	int i[maxs];
	ii=i;
	char *c;
	char *cc;
	printf("\ec\e[46;34m\n\a\n");
	mmax=loadInteger(files,i,maxs);
	listInt(i,mmax);
}
