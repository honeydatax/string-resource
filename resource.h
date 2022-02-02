#include "fileList.h"
#define bufferresource 2080
char *loadResource(char *files){
	int i=0;
	char *list;
	int counts=0;
	char *c;
	char *cc;
	char *ccc;
	FILE *f1;
	list=NULL;
	if(files!=NULL){
		f1=fopen(files,"r");
		if(f1!=NULL){
			ccc=strString(' ',bufferresource);
			cc=newString(files);
			list=newPointer(cc);
			while(1){
				if(feof(f1))break;
				ccc[0]=0;
				fgetstr(ccc,bufferresource-10,"|",f1);
				ccc[bufferresource-10]=0;
				c=newString(ccc);
				list=addPointer(list,c);
				counts++;
			}
			frees(ccc);
		}
	}
	return list;
}
void resourceList(const char *cc){
	int *i;
	char *c;
	int counts=0;
	int n;
	int count=0;
	if(cc!=NULL){
		i=(int *) cc;
		count=*(i+0);
		for(n=0;n<count;n++){
			c=(char *) *(i+(n+1));
			printf("%d--------------------\n",counts);
			print(c);
			counts++;
		}
	}
}
