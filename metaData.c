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
		saveMeta(f1,&sss,sizeof(sss));
		fclose(f1);
	}
}
