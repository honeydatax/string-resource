#include "resource.h"

struct s1{
	char c[80];
	char cc[80];
};
int main(int argc,char *argv[]){
	char *files="my.meta";
	int i;
	char *c;
	char *cc;
	FILE *f1;
	struct s1 sss;
	struct s1 *ss;
	printf("\ec\e[46;34m\n\a\n");
	f1=fopen(files,"w");
	ss=&sss;
	if(f1!=NULL){
		strcpy(ss->c,"hello world\n");
		strcpy(ss->cc,"hi\n");
		fileHeads(f1,&sss,sizeof(sss));
		fclose(f1);
	}
	f1=fopen(files,"r+");
	if(f1!=NULL){
		fileHole(f1,180);
		workSpace(f1,0,sizeof(sss));
		fclose(f1);
	}
}
