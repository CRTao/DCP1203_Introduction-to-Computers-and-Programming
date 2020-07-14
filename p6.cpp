#include<stdio.h>

int chen(int k){
	int f[300];
	f[0]=0;
	f[1]=1;
	for(int i=2;i<=k;i++){
		f[i]=f[i-1]+f[i-2];
	}
	int total=0;
	for(int i=1;i<=k;i++){
		total+=f[i];
	}
	return total;
}

int wu(int k){
	return k*12000;	
}



int main(){
	
	int input[50];
	int k;
	printf("How many data?\n");
	scanf("%d",&k);
	
	for(int i=0;i<k;i++)
	{
		printf("Please input #%d days : ",i+1);
		scanf("%d",&input[i]);
	}
	printf("\n");
	for(int i=0;i<k;i++)
	{
		if(wu(input[i])<chen(input[i]))printf("For #%d case, choose 'Chen'\n",i+1);
		else if(wu(input[i])>chen(input[i]))printf("For #%d case, choose 'Wu'\n",i+1);
		else if(wu(input[i])==chen(input[i]))printf("For #%d case, it's the same.\n",i+1);
	}
	
	return 0;
}
