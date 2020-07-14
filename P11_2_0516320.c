#include<stdio.h>
#include<stdlib.h>

typedef struct Line
{
    int id,x,top,bottom,flag;
}Line; 

typedef struct Rec
{
    int x,y,lx,ly,area;
}Rec; 

	int tp,k=0;
	float average;
	int xy[2][500];
	int question[50][200]={'\0'};
	int answer[50]={0};
	Line line[500];
	Rec rec[500];

int comparely( const void *a , const void *b )
{
struct Rec *c = (Rec *)a;
struct Rec *d = (Rec *)b;
if(c->ly != d->ly) return c->ly - d->ly;
else return c->lx - d->lx;
}

void sort(int t[2][500],int tp){
	int i,j,k,tmp;
	
	for(i=0;i<tp;i++)
		{for(j=i+1;j<tp;j++)
			{
				if(t[0][i]>t[0][j]){
					tmp=t[1][j];
					t[1][j]=t[1][i];
					t[1][i]=tmp;
					tmp=t[0][j];
					t[0][j]=t[0][i];
					t[0][i]=tmp;
				}
				else if(t[0][i]==t[0][j]){
				if(t[1][i]>t[1][j]){
					tmp=t[1][j];
					t[1][j]=t[1][i];
					t[1][i]=tmp;
					tmp=t[0][j];
					t[0][j]=t[0][i];
					t[0][i]=tmp;
					}
				}
			}
		}
	
}

void checkvisible(Line line[500],int tp){
	
	int i=0,j=0,tmp;
	
	for(i=0;i<tp/2;i++){
		for(j=i+1;j<tp/2;j++){
			if( ( line[i].bottom <= line[j].top && line[i].top >= line[j].top) || ( line[i].bottom <= line[j].bottom && line[i].top >= line[j].bottom) || (( line[j].bottom <= line[i].top && line[j].top >= line[i].top) && ( line[j].bottom <= line[i].bottom && line[j].top >= line[i].bottom) && line[i].flag==0) )
			{
				if(( line[i].bottom < line[j].top && line[i].top >= line[j].top) && line[j].bottom<=line[i].bottom){
					rec[k].y=line[j].top-line[i].bottom;
					rec[k].x=line[j].x-line[i].x;
					rec[k].lx=line[i].x;
					rec[k].ly=line[i].bottom;
					line[j].flag=1;
					tmp=line[i].bottom;
					line[i].bottom=line[j].top;
					line[j].top=tmp;
					k++;
					}
				if(( line[i].bottom <= line[j].bottom && line[i].top > line[j].bottom) && line[j].top>=line[i].top){
					rec[k].y=line[i].top-line[j].bottom;
					rec[k].x=line[j].x-line[i].x;
					rec[k].lx=line[i].x;
					rec[k].ly=line[j].bottom;
					line[j].flag=1;
					tmp=line[i].top;
					line[i].top=line[j].bottom;
					line[j].bottom=tmp;
					k++;
					}
				if( line[i].top == line[j].top && line[i].bottom==line[j].bottom){
					rec[k].y=line[i].top-line[i].bottom;
					rec[k].x=line[i].x-line[j].x;
					rec[k].lx=line[i].x;
					rec[k].ly=line[i].bottom;
					line[i].top=line[j].bottom;
					k++;
					break;	
				}			
			}		
		}
	}
}

int main(int argc,char **argv){
	
	FILE *in;
	int i=0,j=0,q=0,qn=0,m;
	
	in=fopen(*(argv+1),"r");
	
	fscanf(in,"%d",&tp);
	
	for(i=0;i<tp;i++){
		fscanf(in,"%d %d",&xy[0][i],&xy[1][i]);
	}
	for(i=0;i<500;i++)
		answer[i]=0;	
	sort(xy,tp);
	
	for(i=0;i<tp/2;i++){
		line[i].id=i+1;
		line[i].x=xy[0][2*i];
		line[i].top=xy[1][2*i+1];
		line[i].bottom=xy[1][2*i];
		line[i].flag=0;
	}
	
	checkvisible(line,tp);
	qsort(rec,k,sizeof(rec[0]),comparely);
	
	for(i=0;i<k;i++){
		rec[i].area=rec[i].x*rec[i].y;
		average+=rec[i].area;
	}
	average/=k;
	for(i=0;i<k;i++){
		if(rec[i].area>=average)answer[1]+=rec[i].area;
		if(i%2==0)answer[0]+=rec[i].area;
	}
	
	while(q!=-1){
		fscanf(in,"%d",&q);
		if(q==-1)break;
		for(i=0;i<q;i++){
			fscanf(in,"%d",&question[qn][i]);
			answer[qn+2]+=rec[question[qn][i]-1].area;
		}
		qn++;
	}
	fclose(in);		
	
	printf("%d\n",k);
	
	for(i=0;i<qn+2;i++){
		printf("%d\n",answer[i]);
	}
	
	return 0;
}
