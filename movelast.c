#include "resource.h"

struct s1{
	char c[80];
	char cc[80];
};
struct header{
	char c[3];
	float version;
};
int main(int argc,char *argv[]){
	char *files="my.meta";
	int i;
	char *c;
	char *cc;
	FILE *f1;
	struct s1 sss;
	struct s1 *ss;
	struct header h1;
	struct header *hs1;
	printf("\ec\e[46;34m\n\a\n");
	f1=fopen(files,"w");
	ss=&sss;
	hs1=&h1;
	if(f1!=NULL){
		hs1->c[0]='M';
		hs1->c[1]='T';
		hs1->c[2]='A';
		hs1->version=0.01;
		printf("ver %f\n",hs1->version);
		strcpy(ss->c,"hello world\n");
		strcpy(ss->cc,"hi\n");
		fileHeads(f1,&h1,sizeof(h1));
		fclose(f1);
	}
	f1=fopen(files,"r+");
	if(f1!=NULL){
		fileMoveStart(f1,1024);
		fileMoveLast(f1,1024,2048,sizeof(sss));
		saveMeta(f1,&sss,sizeof(sss));
		fclose(f1);
	}
}
