#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<iostream>
#include<iomanip>
#include<windows.h>

//peremeter: line1.txt

typedef struct Line
{
    int left,right;
}Line; 

LARGE_INTEGER startTime,endTime,fre;
double times;
Line aftersort[100000];

void sort(Line line[],int tl){
				QueryPerformanceFrequency(&fre); //取得CPU頻率
    			QueryPerformanceCounter(&startTime); //取得開機到現在經過幾個CPU Cycle
	int i,j;
	Line tmp;
	for(i=0;i<tl;i++)
		{for(j=i+1;j<tl;j++)
			{
				if(line[i].left>line[j].left){
					tmp=line[j];
					line[j]=line[i];
					line[i]=tmp;
				}
			}
		}
	for(j=0;j<tl;j++)
	{
		printf("%d %d\n",line[j].left,line[j].right);
	}
				QueryPerformanceCounter(&endTime); //取得開機到程式執行完成經過幾個CPU Cycle
   				times=((double)endTime.QuadPart-(double)startTime.QuadPart)/fre.QuadPart;
   				
	printf("Sorting Time Took : %.10lfs \n",times);
}

void runaftersort(Line line[],int tl){
				QueryPerformanceFrequency(&fre); //取得CPU頻率
    			QueryPerformanceCounter(&startTime); //取得開機到現在經過幾個CPU Cycle
					
	int i,j;
	int totallen=0;
	int tmplen;
	printf("\n****** Start Program after Sorting ******\n");
	for(i=0;i<tl;i++){
		j=i+1;
		while(line[j].left<line[i].right&&j<tl){
			totallen+=(line[i].right-line[j].left);
			if(line[j].right<line[i].right)totallen-=line[i].right-line[j].right;
			j++;
		}
	}
	printf("        Total Length : %d\n",totallen);		
	
				QueryPerformanceCounter(&endTime); //取得開機到程式執行完成經過幾個CPU Cycle
   				times=((double)endTime.QuadPart-(double)startTime.QuadPart)/fre.QuadPart;
   				
	printf("        Time Took : %.10lfs \n",times);
	printf("******  End Program after Sorting  ******\n\n");
}

void runin_nxn(Line line[],int tl){
				QueryPerformanceFrequency(&fre); //取得CPU頻率
    			QueryPerformanceCounter(&startTime); //取得開機到現在經過幾個CPU Cycle

	int i,j;
	int totallen=0;
	int tmplen;

	printf("\n****** Start Program in O(n^2) ******\n");
	
	for(i=0;i<tl;i++){
		for(j=i+1;j<tl;j++)
			{
				tmplen=line[i].right-line[i].left;
				if(line[j].left>line[i].left)tmplen-=(line[j].left-line[i].left);
				if(line[i].right>line[j].right)tmplen-=(line[i].right-line[j].right);
				if(tmplen<0)tmplen=0;
				totallen+=tmplen;
			}
	}
	
	printf("        Total Length : %d\n",totallen);	
	
				QueryPerformanceCounter(&endTime); //取得開機到程式執行完成經過幾個CPU Cycle
   				times=((double)endTime.QuadPart-(double)startTime.QuadPart)/fre.QuadPart;
   				
	printf("        Time Took : %.10lfs \n",times);
	printf("******  End Program in O(n^2)  ******\n\n");

}
/*
void problem2(Line line[],int tl){
	
	int i,j;
	int totallen=0;
	int tmplen;
	int allinline[100000][2]={0,0};

		
	for(i=0;i<tl;i++){
		allinline[2*i][0]=line[i].left;
		allinline[2*i+1][0]=line[i].right;
		allinline[2*i][1]=i;
		allinline[2*i+1][1]=100+i;
	}
	
	int tmp,tmptr;
	for(i=0;i<2*tl;i++)
		{for(j=i+1;j<2*tl;j++)
			{
				if(allinline[i][0]>allinline[j][0]){
					tmp=allinline[j][0];
					allinline[j][0]=allinline[i][0];
					allinline[i][0]=tmp;
					tmptr=allinline[j][1];
					allinline[j][1]=allinline[i][1];
					allinline[i][1]=tmptr;
				}
			}
		}
	
	for(i=0;i<2*tl;i++){
		printf("%3d ",allinline[i][0]);
	}
	printf("\n");
	for(i=0;i<2*tl;i++){
		printf("%3d ",allinline[i][1]);
	}
	printf("\n");
	for(i=0;i<2*tl;i++){
		if(allinline[i][1]>=100){
			j=i-1;
			while(allinline[i][1]-allinline[j][1]!=100 && allinline[i][1]>=100){
				if(allinline[j][1]<100){
				totallen+=allinline[i][0];
				totallen-=allinline[j][0];
				printf("%d %d  \n", allinline[i][0],allinline[j][0]);
				}
				printf("** %d %d %d  ", i,j, totallen);
				j--;
				system("pause");	
			}
			allinline[j][1]+=200;
			printf("%3d ",allinline[j][1]);
		}
	}
	printf("%d",totallen);
}
*/
int main(int argc,char **argv){
	FILE *in;
	int tl=0,i,j=0;
	Line line[100000];
	
	in=fopen(*(argv+1),"r");
	
	printf("How many lines: ");
	scanf("%d",&tl);
	printf("\n");
	for(i=0;i<tl;i++){
		fscanf(in,"%d %d",&line[i].left,&line[i].right);
	}
			
	for(j=0;j<tl;j++)
	{
		aftersort[j].left=line[j].left;
		aftersort[j].right=line[j].right;
		printf("%d %d\n",line[j].left,line[j].right);
	}
	fclose(in);
	
	runin_nxn(line,tl);
	sort(aftersort,tl);
	runaftersort(aftersort,tl);
	//problem2(aftersort,tl);
	
	return 0;
}

