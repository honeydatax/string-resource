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
void saveResource(const char *cc,char *files,int start,int endss){
	int *i;
	char *c;
	int counts=0;
	int countss=endss;
	int n;
	int count=0;
	FILE *f1;
	if(cc!=NULL && files!=NULL){
		f1=fopen(files,"w");
		if(f1!=NULL){
			i=(int *) cc;
			count=*(i+0);
			if(countss>count)countss=count;
			for(n=start;n<countss;n++){
				c=(char *) *(i+(n+1));
				fwrite(c,strlen(c),1,f1);
				fprintf(f1,"|");
			}
			fclose(f1);
		}
	}
}
void saveList(const char *cc,char *files,int start,int endss){
	int *i;
	char *c;
	int counts=0;
	int countss=endss;
	int n;
	int count=0;
	FILE *f1;
	if(cc!=NULL && files!=NULL){
		f1=fopen(files,"w");
		if(f1!=NULL){
			i=(int *) cc;
			count=*(i+0);
			if(countss>count)countss=count;
			for(n=start;n<countss;n++){
				c=(char *) *(i+(n+1));
				fwrite(c,strlen(c),1,f1);
				fprintf(f1,"\n");
			}
			fclose(f1);
		}
	}
}
char *loadList(char *files){
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
				fgetstr(ccc,bufferresource-10,"\n",f1);
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
void cvsList(const char *cc){
	int *i;
	char *c;
	char *l1;
	char *s;
	int counts=0;
	int n;
	int count=0;
	if(cc!=NULL){
		i=(int *) cc;
		count=*(i+0);
		for(n=0;n<count;n++){
			c=(char *) *(i+(n+1));
			s=newString(c);
			l1=splitString(s,',');
			print("-------------");
			printList(l1);
			frees(l1);
			frees(s);
			counts++;
		}
	}
}
void data(FILE *f1){
	char *a="						<Data ss:Type=\"String\">";
	fprintf (f1,"%s",a);
}
void enddata(FILE *f1){
	char *a="</Data>";
	fprintf (f1,"%s\n",a);
}
void cell(FILE *f1){
	char *a="					<Cell>";
	fprintf (f1,"%s\n",a);
}
void endcell(FILE *f1){
	char *a="					</Cell>";
	fprintf (f1,"%s\n",a);
}
void row(FILE *f1){
	char *a="				<Row ss:Height=\"12,8126\">";
	fprintf (f1,"%s\n",a);
}
void endrow(FILE *f1){
	char *a="				</Row>";
	fprintf (f1,"%s\n",a);
}
void endtable(FILE *f1){
	char *a="			</Table>";
	char *b="			<x:WorksheetOptions/>";
	fprintf (f1,"%s\n",a);
	fprintf (f1,"%s\n",b);
}
void table(FILE *f1){
	char *a="			<Table>";
	fprintf (f1,"%s\n",a);


}
void worksheet(FILE *f1){
	char *a="		<ss:Worksheet>";
	fprintf (f1,"%s\n",a);
}
void endworksheet(FILE *f1){
	char *a="		</ss:Worksheet>";
	fprintf (f1,"%s\n",a);
}

void types(FILE *f1){
	char *a="	<?mso-application progid=\"Excel.Sheet\"?>";
	char *b="	<Workbook xmlns=\"urn:schemas-microsoft-com:office:spreadsheet\" xmlns:c=\"urn:schemas-microsoft-com:office:component:spreadsheet\" xmlns:html=\"http://www.w3.org/TR/REC-html40\" xmlns:o=\"urn:schemas-microsoft-com:office:office\" xmlns:ss=\"urn:schemas-microsoft-com:office:spreadsheet\" xmlns:x2=\"http://schemas.microsoft.com/office/excel/2003/xml\" xmlns:x=\"urn:schemas-microsoft-com:office:excel\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\">";
	fprintf (f1,"%s\n",a);
	fprintf (f1,"%s\n",b);

}
void endxml(FILE *f1){
	char *a="	</Workbook>";
	fprintf (f1,"%s\n",a);
}
void xml(FILE *f1){
	char *a="<?xml version=\"1.0\" encoding=\"UTF-8\"?>";
	fprintf (f1,"%s\n",a);
}
void saveXmlLine(FILE *f1,char *lines){
	int *i;
	char *c;
	char *cc;
	int counts=0;
	int n;
	int count=0;
	cc=lines;
	if(cc!=NULL){
		i=(int *) cc;
		count=*(i+0);
		row(f1);
		for(n=0;n<count;n++){
			cell(f1);
			data(f1);
			c=(char *) *(i+(n+1));
			fprintf(f1,"%s\n",c);
			enddata(f1);
			endcell(f1);
		}
		endrow(f1);
	}
}
void saveXmlNode(FILE *f1,char *node){
	int *i;
	char *c;
	char *l1;
	char *s;
	int counts=0;
	int n;
	int count=0;
	if(node!=NULL){
			s=newString(node);
			l1=splitString(s,',');
			saveXmlLine(f1,l1);
			frees(l1);
			frees(s);
			counts++;

	}
}
void saveXml(const char *cc,char *files,int start,int endss){
	int *i;
	char *c;
	int counts=0;
	int countss=endss;
	int n;
	int count=0;
	FILE *f1;
	if(cc!=NULL && files!=NULL){
		f1=fopen(files,"w");
		if(f1!=NULL){
		xml(f1);
		types(f1);
		worksheet(f1);
		table(f1);
			i=(int *) cc;
			count=*(i+0);
			if(countss>count)countss=count;
			for(n=start;n<countss;n++){
				c=(char *) *(i+(n+1));
				saveXmlNode(f1,c);
			}
			endtable(f1);
			endworksheet(f1);
			endxml(f1);
			fclose(f1);
		}
	}
}
char *loadXml(char *files){
	FILE *f1;
	char *xml;
	char *xml2;
	char *buf;
	char *ffind;
	char *c;
	char *cc;
	char *ccc;
	char *cccc;
	int style3=0;
	int style2=0;
	int style=0;
	int r=0;
	xml=NULL;
	if(files!=NULL){
		f1=fopen(files,"r");
		if(f1!=NULL){
			xml2=newString(files);
			xml=newPointer(xml2);
			buf=strString(' ',bufferresource);
			xml2=newString("");
			style=0;
			while(1){
				buf[0]=0;
				fgetstr(buf,bufferresource-10,">",f1);
				buf[bufferresource-10]=0;
				replaceCharString(buf,'\n',' ');
				replaceCharString(buf,'\r',' ');
				replaceCharString(buf,'\t',' ');
				replaceCharString(buf,',',' ');
				r=0;
				c=buf;
				ccc=buf;
						while(r!=1){
							cc=strstr(ccc,"<");
							if(cc!=NULL){
								cccc=ccc;
								ccc=cc+1;
								cc[0]=0;
							}else{
								cccc=ccc;
								r=1;
							}
							
							cc=strstr(ccc,"row");
							if(cc!=NULL && cc-ccc<3){
								style2=0;
							}
							cc=strstr(ccc,"ROW");
							if(cc!=NULL && cc-ccc<3){
								style2=0;
							}
							cc=strstr(ccc,"Row");
							if(cc!=NULL && cc-ccc<3){
								style2=0;
							}

							cc=strstr(ccc,"/row");
							if(cc!=NULL && cc-ccc<3){
								xml=addPointer(xml,xml2);
								xml2=newString("");
								style2=0;
								style=0;
							}
							cc=strstr(ccc,"/ROW");
							if(cc!=NULL && cc-ccc<3){
								xml=addPointer(xml,xml2);
								xml2=newString("");
								style2=0;
								style=0;
							}
							cc=strstr(ccc,"/Row");
							if(cc!=NULL && cc-ccc<3){
								xml=addPointer(xml,xml2);
								xml2=newString("");
								style2=0;
								style=0;
							}
							
							cc=strstr(ccc,"/DATA");
							if(cc!=NULL && cc-ccc<3){
								xml2=catString(xml2,cccc);
								style2=1;
								style=0;
							}
							cc=strstr(ccc,"/data");
							if(cc!=NULL && cc-ccc<3){
								xml2=catString(xml2,cccc);
								style2=1;
								style=0;
							}
							cc=strstr(ccc,"/Data");
							if(cc!=NULL && cc-ccc<3){
								xml2=catString(xml2,cccc);
								style2=1;
								style=0;
							}
							cc=strstr(ccc,"Data");
							if(cc!=NULL && cc-ccc<3){
								if(style==1 && style2==1)xml2=catString(xml2,",");
								style=1;
							}
							cc=strstr(ccc,"DATA");
							if(cc!=NULL && cc-ccc<3){
								if(style==1 && style2==1)xml2=catString(xml2,",");
								style=1;
							}
							cc=strstr(ccc,"data");
							if(cc!=NULL && cc-ccc<3){
								if(style==1 && style2==1)xml2=catString(xml2,",");
								style=1;
							}
							if(style==1){
								//xml2=catString(xml2,cccc);
							}

							cc=strstr(ccc,">");
							if(cc!=NULL){
								ccc=cc+1;
								r=0;
							}else{
								r=1;
							}

							
						}
				if(feof(f1))break;
			}
			frees(xml2);
			frees(buf);
			fclose(f1);
		}
	}
	
	return xml;
}
void htmltd(FILE *f1){
	char *a="				<td width=\"50%\" style=\"border: 1px solid #000000; padding: 0.1cm\">";
	fprintf (f1,"%s",a);
}
void endhtmltd(FILE *f1){
	char *a="</td>";
	fprintf (f1,"%s\n",a);
}
void htmlrow(FILE *f1){
	char *a="				<tr>";
	fprintf (f1,"%s\n",a);
}
void endhtmlrow(FILE *f1){
	char *a="				</tr>";
	fprintf (f1,"%s\n",a);
}

void htmltable(FILE *f1){
	char *a="			<table width=\"100%\" cellpadding=\"5\" cellspacing=\"0\">";
	fprintf (f1,"%s\n",a);
}
void endhtmltable(FILE *f1){
	fprintf (f1,"			</table>\n");
}
void htmlstyle(FILE *f1){
	char *a="				<style type=\"text/css\">";
	char *b="					@page { margin: 2cm }";
	char *c="					p { margin-bottom: 0.25cm; line-height: 120% }";
	char *d="					td p { margin-bottom: 0cm }";
	char *e="				</style>";
	fprintf (f1,"%s\n",a);
	fprintf (f1,"%s\n",b);
	fprintf (f1,"%s\n",c);
	fprintf (f1,"%s\n",d);
	fprintf (f1,"%s\n",e);
}
void htmlhead (FILE *f1){
	fprintf (f1,"	<head>\n");
}
void endhtmlhead (FILE *f1){
	fprintf (f1,"	</head>\n");
}

void htmlbody (FILE *f1){
	fprintf (f1,"	<body>\n");
}
void endhtmlbody (FILE *f1){
	fprintf (f1,"	</body>\n");
}
void htmltitle (FILE *f1){
	fprintf (f1,"		<title>\n");
}
void endhtmltitle (FILE *f1){
	fprintf (f1,"		</title>\n");
}

void html (FILE *f1){
	fprintf (f1,"<html>\n");
}

 void endhtml (FILE *f1){
	fprintf (f1,"</html>\n");
}
void saveHtmlLine(FILE *f1,char *lines){
	int *i;
	char *c;
	char *cc;
	int counts=0;
	int n;
	int count=0;
	cc=lines;
	if(cc!=NULL){
		i=(int *) cc;
		count=*(i+0);
		row(f1);
		for(n=0;n<count;n++){
			htmltd(f1);
			c=(char *) *(i+(n+1));
			fprintf(f1,"%s\n",c);
			endhtmltd(f1);

		}
		endrow(f1);
	}
}
void saveHmlNode(FILE *f1,char *node){
	int *i;
	char *c;
	char *l1;
	char *s;
	int counts=0;
	int n;
	int count=0;
	if(node!=NULL){
			s=newString(node);
			l1=splitString(s,',');
			saveHtmlLine(f1,l1);
			frees(l1);
			frees(s);
			counts++;

	}
}
void saveHml(const char *cc,char *files,int start,int endss){
	int *i;
	char *c;
	int counts=0;
	int countss=endss;
	int n;
	int count=0;
	FILE *f1;
	if(cc!=NULL && files!=NULL){
		f1=fopen(files,"w");
		if(f1!=NULL){
		html(f1);
		htmlhead(f1);
		htmltitle(f1);
		fprintf(f1,"%s",files);
		endhtmltitle(f1);
		htmlstyle(f1);
		endhtmlhead(f1);
		htmlbody(f1);
		htmltable(f1);
			i=(int *) cc;
			count=*(i+0);
			if(countss>count)countss=count;
			for(n=start;n<countss;n++){
				c=(char *) *(i+(n+1));
				htmlrow(f1);
				saveHmlNode(f1,c);
				endhtmlrow(f1);
			}
		endhtmltable(f1);
		endhtmlbody(f1);
		endhtml(f1);
		}
	}
}
char *loadHtml(char *files){
	FILE *f1;
	char *hml;
	char *hml2;
	char *buf;
	char *ffind;
	char *c;
	char *cc;
	char *ccc;
	char *cccc;
	int style3=0;
	int style2=0;
	int style=0;
	int r=0;
	hml=NULL;
	if(files!=NULL){
		f1=fopen(files,"r");
		if(f1!=NULL){
			hml=newString("");
			buf=strString(' ',bufferresource);
			style=0;
			while(1){
				buf[0]=0;
				fgetstr(buf,bufferresource-10,">",f1);
				buf[bufferresource-10]=0;
				replaceCharString(buf,'\n',' ');
				replaceCharString(buf,'\r',' ');
				replaceCharString(buf,'\t',' ');
				replaceCharString(buf,',',' ');
				r=0;
				c=buf;
				ccc=buf;
					while(r!=1){
							cc=strstr(ccc,"<");
							if(cc!=NULL){
								cccc=ccc;
								ccc=cc+1;
								cc[0]=0;
								if(style==1)hml=catString(hml,cccc);
							}else{
								cccc=ccc;
								r=1;
							}
							cc=strstr(ccc,"BODY");
							if(cc!=NULL && cc-ccc<3)style=1;
							cc=strstr(ccc,"body");
							if(cc!=NULL && cc-ccc<3)style=1;
							cc=strstr(ccc,"Body");
							if(cc!=NULL && cc-ccc<3)style=1;
							cc=strstr(ccc,"br");
							if(cc!=NULL && cc-ccc<3)hml=catString(hml,"\n");
							cc=strstr(ccc,"Br");
							if(cc!=NULL && cc-ccc<3)hml=catString(hml,"\n");
							cc=strstr(ccc,"BR");
							if(cc!=NULL && cc-ccc<3)hml=catString(hml,"\n");
							cc=strstr(ccc,"p");
							if(cc!=NULL && cc-ccc<3)hml=catString(hml,"\n");
							cc=strstr(ccc,"P");
							if(cc!=NULL && cc-ccc<3)hml=catString(hml,"\n");
							cc=strstr(ccc,"/p");
							if(cc!=NULL && cc-ccc<3)hml=catString(hml,"\n");
							cc=strstr(ccc,"/P");
							if(cc!=NULL && cc-ccc<3)hml=catString(hml,"\n");
							cc=strstr(ccc,"/row");
							if(cc!=NULL && cc-ccc<3)hml=catString(hml,"\n");
							cc=strstr(ccc,"/Row");
							if(cc!=NULL && cc-ccc<3)hml=catString(hml,"\n");
							cc=strstr(ccc,"/ROW");
							cc=strstr(ccc,">");
							if(cc!=NULL){
								ccc=cc+1;
								r=0;
							}else{
								r=1;
							}
						}

				if(feof(f1))break;
			}
			frees(buf);
			fclose(f1);
		}
	}
	
	return hml;
}
void savePs(char *cc,char *files,int starts){
	int *i;
	char *c;
	int counts=0;
	int n;
	int count=0;
	int ss=starts;
	int lines=800;
	int pages=1;
	FILE *f1;
	if(cc!=NULL && files!=NULL){
		f1=fopen(files,"w");
		if(f1!=NULL){
			i=(int *) cc;
			count=*(i+0);
			fprintf (f1,"%!PS\n%%Pages: %d\n/Free-Mono findfont\n12 scalefont\nsetfont\nnewpath\n",count/50+3);
			fprintf (f1,"\n/Free-Mono findfont\n12 scalefont\nsetfont\nnewpath\n%%%%page: 1 1\n");
			for(n=ss;n<count;n++){
				c=(char *) *(i+(n+1));
				replaceCharString(c,'\n',' ');
				replaceCharString(c,'\r',' ');
				replaceCharString(c,'\t',' ');
				fprintf(f1,"\n30 %d moveto\n( %s ) show\n",lines,c);
				lines=lines-15;
				if (lines < 32){
					lines=800;
					pages++;
					fprintf(f1,"\nshowpage\n%%%%page: %d %d\n",pages,pages);
				} 
				counts++;
			}
			fprintf(f1,"\nshowpage\n%%%%EOF\n\n");
			fclose(f1);
		}
	}
}

