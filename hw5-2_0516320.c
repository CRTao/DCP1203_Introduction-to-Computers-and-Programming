#include<stdio.h>
#include<time.h>
#include<stdlib.h>


void randomnumber(int number[],int m){
	
	srand(time(NULL));
	for(int i=0;i<m;i++)
	{
		number[i]=rand()%10000;
	}
	
}

void sort(int number[],int m){
	
	int temp;
	
	for(int i=0;i<m-1;i++)
		for(int j=0;j<m-i-1;j++)
			{
			if(number[j]>number[j+1])
			{temp=number[j+1];
			number[j+1]=number[j];
			number[j]=temp;}				
			}
	
	
}

void binarysearch(int number[],int m,int key){
	
	int up=m-1,down=0,mid;
	while(down<=up)
	{
		mid=(up+down)/2;
		if(number[mid]==key){
			printf("Find the number %d in array[%d].\n",key,mid);
			break;
		}
		else if(number[mid]>key)
			up=mid-1;
		else if(number[mid]<key)
			down=mid+1;
	}
	
	if(down>up)printf("The number %d is not on the list.\n",key);
	
	
}

int main(){
	
	
	char c1,c2,filename[50];
	int m,state=1,number[50],dsort[50];
	FILE *in,*out;
	
	printf("Please select the way to read a set of integers.\n");
	printf("   1: Random numbers.\n   2: Read integers from a text file.\n");
	c1=getchar();
	fflush(stdin);
	if(c1=='1')
	{
		printf("How many integers do you want to generate?  ");
		scanf("%d",&m);
		randomnumber(number,m);
	}
	else if(c1=='2')
	{
		printf("Your file name:");
		gets(filename);
		in=fopen(filename,"r");
		if(in==NULL)
			{printf("Input file not found! Quit the program and go check the txt!\n");
			return 0;}
		fscanf(in,"%d",&m);
		for(int i=0;i<m;i++)
			fscanf(in,"%d",&number[i]);
		
	}
	else
	{
		printf("Wrong answer. Ending the program. \n");
	}
	
	
	while(state==1){
	fflush(stdin);
	getchar();	
	printf("\nSpecify the operation you want to do:\n");
	printf("   i: print indegers in increasing order.\n");
	printf("   d: print indegers in decreasing order.\n");
	printf("   p: perform a binary search.(increasing order)\n");
	printf("   q: quit the program.\n");
	
	c2=getchar();
	
	if(c2=='i'){
		sort(number,m);
		for(int i=0;i<m;i++)
			printf("Array[%d]: %d\n",i,number[i]);
		out=fopen("IncSort","w");
		if(out==NULL)
			printf("Cannot open the file 'IncSort'");
		else
			{
				fprintf(out,"%d\n",m);
				for(int i=0;i<m;i++)
					fprintf(out,"%d\n",number[i]);
				printf("IncSort has been saved.\n");
			}
	}	
	else if(c2=='d'){
		sort(number,m);
		for(int i=0;i<m;i++)
				dsort[m-1-i]=number[i];
		for(int i=0;i<m;i++)
			printf("Array[%d]: %d\n",i,dsort[i]);
		out=fopen("DecSort","w");
		if(out==NULL)
			printf("Cannot open the file 'IncSort'");
		else
			{
				fprintf(out,"%d\n",m);
				for(int i=0;i<m;i++)
					fprintf(out,"%d\n",number[i]);
				printf("DecSort has been saved.\n");
			}	
	}
	else if(c2=='p'){
		sort(number,m);
		int key;
		printf("Search the integer: ");
		scanf("%d",&key);
		binarysearch(number,m,key);
		
	}
	else if(c2=='q'){
		printf("\nQuit the program. ");
		return 0;
		
	}
	else{
		printf("Input Error!");
	}
	
	}
	
}
