#include "resource.h"
#define maxs 1000
int main(int argc,char *argv[]){
	char *files="my.txt";
	int mmax=100;
	int n=0;
	double *ii;
	double i[maxs];
	ii=i;
	char *c;
	char *cc;
	printf("\ec\e[44;36m\n\a\n");
	for(n=0;n<maxs-1;n++)ii[n]=(rand() & 0xffff)/100.00;
	saveFloat(files,i,maxs-1,16);
	listFloat(i,maxs-1);
}
