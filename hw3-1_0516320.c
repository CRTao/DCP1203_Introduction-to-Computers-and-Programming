#include<stdio.h>
#include<stdlib.h>

int main(){
	
	char answer[50]=" ";
	int blank=0,state=1,number=0,i=0,k=0,totalcorrect=0;
	
	while(totalcorrect==0){
		
		
		
	printf("Please input two numbers: ");
	while((answer[k] = getchar())!='\n')
        k++ ;
		
	printf("\n\n");
	while(state==1&&totalcorrect==0){
			if(answer[i]==48||answer[i]==49||answer[i]==50||answer[i]==51||answer[i]==52||answer[i]==53||answer[i]==54||answer[i]==55||answer[i]==56||answer[i]==57||answer[i]==' ')
			{	
			    if(blank==0&&answer[i]!=' '){number++;blank=1;}
                if(answer[i]==' '){blank=0;}
			}
		    else {state=0;}	
		
			if(answer[i]=='\n')totalcorrect++;
			
			if(state==1)for(i=0;i<50;i++)answer[i]=answer[i+1];	
			
			
			i=0;
					
		}
		
		printf("\nThe legal number of inputs are %d \n",number);
		if(totalcorrect==1&&number==2)printf("Your input is completely correct!\n");
		if(number!=2)printf("We do not receive two integers.\n");
		if(state==0&&totalcorrect==0)printf("The garbage in keyboard buffer is \"%s\" , we just removed them from the buffer. \n\n", answer);
		
		system("pause");
		
		system("cls");
		
		blank=0,state=1,number=0,i=0,k=0,totalcorrect=0;
		
		}
	return 0;
}


















