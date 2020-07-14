#include<stdio.h>
#include<limits.h>

int main(){
	
	char letter;
	printf("//It will only scan the first letter in string!\n\n");
	goto Ask;
	
	Ask: 
	printf("Please input letter 'y'or'n'\n");
	
	scanf("%c",&letter);
	
	if( letter==89 || letter==121 || letter==78 || letter==110)
		goto Exit;
	else
		goto Wrong;
	
	Wrong:
		
		printf("No No No! You must input letter 'y'or'n',ok?\n");
		printf("Not '%c' !\n",letter);
        fflush(stdin);
		if(letter==48||letter==49||letter==50||letter==51||letter==52||letter==53||letter==54||letter==55||letter==56||letter==57)
		printf("It's a number!\n");
				
		goto Ask;
		
	Exit:
		printf("You got it! Well done.\n");
		
		return 0;
		
}
