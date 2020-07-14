#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <ctype.h>
 

int main(int argc,char **argv){
	
	//parameters: email~ keyword~ (Seperate with Space!!)
	// Spamkey.txt NormalEmail1.txt
	
	FILE *pfile;
	FILE *keyfile;
	FILE *report;
	char letterinline[200][200];
	char keywords[200][200];
	char keyweight[200][200];
	int keywordtime[200];
	int k=0,emailn,keyn;
	int e=0,i=0,j=0;
	
	keyfile=fopen(*(argv+1),"r");	
	pfile=fopen(*(argv+2),"r");

	if(keyfile == NULL)printf("Error opening file '%s'\n",*(argv+1));
	else{
	while(1){
			fscanf(keyfile,"%s",keyweight[j]);	
			fscanf(keyfile,"%s",keywords[i]);
			if(!strcmp(keyweight[j],"-999")){
				//printf("ENDED.\n\n");
				break;
				}
			//puts(keywords[i]);
			//puts(keyweight[j]);
			i+=1;
			j+=1;
		}
	
		}

	fclose(keyfile);	
	
	for(k=0;k<200;k++)keywordtime[k]=0; 
	
	
	if( pfile == NULL)printf("Error opening E-mail '%s'\n",*(argv+2));
	else{
				
		while( fgets( letterinline[e] , 199 , pfile) != NULL){
			e++;
		}
		fclose(pfile);				
		
	printf("******Testing E-mail '%s'****** \n\n",*(argv+2));
	char *tempstr,*pch,*temp;
 		int p=0;
 		size_t len;
 		size_t count;
 		
 	while(p<i){
 			
 			k=0;
 			while(k<e){
 				
 				len=strlen(keywords[p]);
 				count=0;
 				char *tempstr=letterinline[k];
			 	while((pch=strstr(tempstr,keywords[p]))!=NULL){
			 		temp=pch+len;
			 		keywordtime[p]++;
					tempstr=temp;
					}
				k++;
				
			}

		printf("%18s : %d\n",keywords[p],keywordtime[p]);
		p++;
		}
		
	p=0;
	int blank=0;
 	k=0;
 	while(k<e){
 		count=0;
 		char *tempstr=letterinline[k];
			while((pch=strstr(tempstr," "))!=NULL){
				temp=pch+1;
				blank++;
				tempstr=temp;
			}
		k++;
	}
	printf("\n       Total Words : %d",blank);
	
	int totalweight=0;
	int h=0;
	while(h<i){
			totalweight+=atoi(keyweight[h])*keywordtime[h];
			h++;
		} 
	printf("\n       Total Weight: %d\n",totalweight);
	
	float w_b=(float)totalweight/(float)blank;

	if(w_b>3)printf("\n******E-mail '%s' : Spam e-mail******\n\n",*(argv+2));
	else printf("\n******E-mail '%s' : Normal e-mail******\n\n",*(argv+2));
	}
	
	
	return 0;
} 
