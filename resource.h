#include "fileList.h"
#define bufferresource 2080
int saveResource(char *files){
	int counts=0;
	char *c;
	char *cc;
	int lens;
	FILE *f1;
	FILE *f2;
	if(files!=NULL){
		f1=fopen(files,"r");
		if(f1!=NULL){
			c=newString(files);
			cc=newString(fileName(c));
			frees(c);
			c=file(cc);
			frees(cc);
			c=catString(c,".RC");
			f2=fopen(c,"w");
			frees(c);
			if(f2!=NULL){
				c=strString(' ',bufferresource);
				if(c!=NULL){
					while(1){
						if(feof(f1))break;
						c[0]=0;
						fgets(c,bufferresource-10,f1);
						c[bufferresource-10]=0;
						cc=strstr(c,"\\0_");
						lens=0;
						if(cc!=NULL){
							cc[0]=0;
							lens=1;
							counts++;
						}
						cc=c;
						fwrite(c,strlen(c)+lens,1,f2);
					}
				}
				frees(c);
			}
			fclose(f1);
		}
	}
	return counts;
}
