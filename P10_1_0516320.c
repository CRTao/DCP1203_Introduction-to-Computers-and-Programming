#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

//peremeter: line1.txt

typedef struct Line
{
    int left,right;
}Line; 

LARGE_INTEGER startTime,endTime,fre;
double times;
Line aftersort[200000];

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
				QueryPerformanceCounter(&endTime); //取得開機到程式執行完成經過幾個CPU Cycle
   				times=((double)endTime.QuadPart-(double)startTime.QuadPart)/fre.QuadPart;
   				
	printf("Sorting Time Took : %.10lfs \n",times);
}

void runaftersort(Line line[],int tl){
				QueryPerformanceFrequency(&fre); //取得CPU頻率
    			QueryPerformanceCounter(&startTime); //取得開機到現在經過幾個CPU Cycle
					
	int i,j;
	double totallen=0;
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
	printf("        Total Length : %lf\n",totallen);		
	
				QueryPerformanceCounter(&endTime); //取得開機到程式執行完成經過幾個CPU Cycle
   				times=((double)endTime.QuadPart-(double)startTime.QuadPart)/fre.QuadPart;
   				
	printf("        Time Took : %.10lfs \n",times);
	printf("******  End Program after Sorting  ******\n\n");
}

void runin_nxn(Line line[],int tl){
				QueryPerformanceFrequency(&fre); //取得CPU頻率
    			QueryPerformanceCounter(&startTime); //取得開機到現在經過幾個CPU Cycle

	int i,j;
	double totallen=0;
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
	
	printf("        Total Length : %lf\n",totallen);	
	
				QueryPerformanceCounter(&endTime); //取得開機到程式執行完成經過幾個CPU Cycle
   				times=((double)endTime.QuadPart-(double)startTime.QuadPart)/fre.QuadPart;
   				
	printf("        Time Took : %.10lfs \n",times);
	printf("******  End Program in O(n^2)  ******\n\n");

}

int main(int argc,char **argv){
	FILE *in;
	int tl=0,i,j=0;
	Line line[200000];
	
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
	
	return 0;
}

