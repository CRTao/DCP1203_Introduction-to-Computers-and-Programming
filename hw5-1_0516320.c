#include<stdio.h>

int main(){
	
	int input[50],output[50],fifty[50],ten[50],five[50],one[50];
	int k;
	printf("How many data?\n");
	scanf("%d",&k);
	
	for(int i=0;i<k;i++)
	{
		printf("Please input #%d dollars : ",i+1);
		scanf("%d",&input[i]);
	}
	
	for(int i=0;i<k;i++)
	{
		fifty[i]=input[i]/50;
		ten[i]=input[i]%50/10;
		five[i]=input[i]%50%10/5;
		one[i]=input[i]%50%10%5;
		output[i]=fifty[i]+ten[i]+five[i]+one[i];
		
	}
	
	
	for(int i=0;i<k;i++)
	{
		printf("\nYour #%d total coins: %d    ",i+1,output[i]);
		printf("Each coin have ( %d , %d , %d , %d )\n",fifty[i],ten[i],five[i],one[i]);
	}
	
	
	return 0;
}

