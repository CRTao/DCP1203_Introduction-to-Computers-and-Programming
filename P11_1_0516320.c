#include<stdio.h>
#include<stdlib.h>

typedef struct Line
{
    int id,x,top,bottom,flag;
}Line; 

Line line[200000];
int visibleline[200000][200000];

int comparex( const void *a , const void *b )
{
struct Line *c = (Line *)a;
struct Line *d = (Line *)b;
if(c->x != d->x) return c->x - d->x;
else return d->bottom - c->bottom;
}

void vsort(int vline[200000][200000],int l){
	int i,j,k,tmp;
	
	for(i=0;i<l;i++)
		{for(j=i+1;j<l;j++)
			{
				if(vline[i][0]>vline[j][0]){
					for(k=0;k<l;k++){
					tmp=vline[j][k];
					vline[j][k]=vline[i][k];
					vline[i][k]=tmp;
					}
				}
			}
		}
	
}

void checkflag(Line line[],int l){
	int i,j;
	for(i=l-1;i>=0;i--){
		for(j=i-1;j>=0;j--){
			if( line[i].top<line[j].top && line[i].bottom>line[j].bottom && line[i].flag==0){
				line[i].flag=line[j].id;
			}
		}
	}
}

void whethervisible(Line line[],int l){
	
	int i=0,j=0,k;
	
	for(i=0;i<l;i++){
		k=1;
		visibleline[i][0]=line[i].id;
		for(j=i+1;j<l;j++){
			if( ( line[i].bottom < line[j].top && line[i].top >= line[j].top) || ( line[i].bottom <= line[j].bottom && line[i].top > line[j].bottom) || (( line[j].bottom < line[i].top && line[j].top >= line[i].top) && ( line[j].bottom <= line[i].bottom && line[j].top > line[i].bottom)) )
			{
				if(( line[i].bottom < line[j].top && line[i].top >= line[j].top) && line[j].bottom<=line[i].bottom)
					line[i].bottom=line[j].top;
				if(( line[i].bottom <= line[j].bottom && line[i].top > line[j].bottom) && line[j].top>=line[i].top)
					line[i].top=line[j].bottom;
				if((( line[j].bottom < line[i].top && line[j].top >= line[i].top) && ( line[j].bottom <= line[i].bottom && line[j].top > line[i].bottom)))
					{line[i].top=0;
					line[i].bottom=0;
					}
				if( line[j].flag == line[i].id || line[j].flag==0){
					visibleline[i][k]=line[j].id;
					k++;	
				}			
			}		
		}
	}
	
}

int main(int argc,char **argv){
	
	FILE *in,*in2;
	int l=0;
	int i=0,j=0;
	int ch;
	
	in=fopen(*(argv+1),"r");
	
 	l++;
  	while((ch=fgetc(in))!=EOF)
    {
     if (ch=='\n')
     l++;
    }
	fclose(in);
	in2=fopen(*(argv+1),"r");
	for(i=0;i<l;i++){
		fscanf(in2,"%d %d %d %d",&line[i].id,&line[i].x,&line[i].bottom,&line[i].top);
		line[i].flag=0;
	}
	fclose(in2);
	
	//sortx(line,l);
	qsort(line,l,sizeof(line[0]),comparex);
	checkflag(line,l);
	
	whethervisible(line,l);
	vsort(visibleline,l);
	
	FILE *out;
	out=fopen("vLine.out","w");
	
	for(i=0;i<l;i++){
		for(j=0;j<l;j++)
			if(visibleline[i][j]!=0)
			{
			printf("%d ",visibleline[i][j]);
			fprintf(out,"%d ",visibleline[i][j]);
			
			}
		printf("\n");
		fprintf(out,"\n");
	}
	fclose(out);
	
	return 0;
}
