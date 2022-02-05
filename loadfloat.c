#include "resource.h"
#define maxs 1000
int main(int argc,char *argv[]){
	char *files="my.txt";
	int mmax=100;
	double *ii;
	double n[maxs];
	ii=n;
	char *c;
	char *cc;
	printf("\ec\e[46;34m\n\a\n");
	mmax=loadFloat(files,n,maxs);
	listFloat(n,mmax);
}
