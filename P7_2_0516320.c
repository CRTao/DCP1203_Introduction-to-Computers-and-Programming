#include<stdio.h>
#include<stdlib.h>

	int xmove[8]={2,1,-1,-2,-2,-1,1,2};
	int ymove[8]={1,2,2,1,-1,-2,-2,-1};
	int table[8][8];
	int i,j;
	int sx,sy;
	int x,y;
	int mov=1;
	
int safemove(int x,int y,int table[8][8]){
	if(x>=0&&x<=7 && y>=0&&y<=7 && table[x][y]==0)
		return 1;
	else 
		return 0;
}

void aftersafe(int k)
	{
		table[x][y]=mov;
		mov++;
		x=x+xmove[k];
		y=y+ymove[k];
	}



int main(){
		
	printf("Start from: ");
	
	scanf("%d%d",&sx,&sy);

	if(sx>7){printf("Out of range! Set to border.\n");sx=7;}
	if(sy>7){printf("Out of range! Set to border.\n");sy=7;}
	
	printf("\n");
	for(i=0;i<8;i++)
		{
			for(j=0;j<8;j++)table[i][j]=0;
 		}
 		
 	x=sx;
 	y=sy;
	table[x][y]=mov;
 	
 	while(mov!=64)
	{
		if(safemove(x+xmove[0],y+ymove[0],table)==1)
			aftersafe(0);
		else if(safemove(x+xmove[1],y+ymove[1],table)==1)
			aftersafe(1);
		else if(safemove(x+xmove[2],y+ymove[2],table)==1)
			aftersafe(2);
		else if(safemove(x+xmove[3],y+ymove[3],table)==1)
			aftersafe(3);
		else if(safemove(x+xmove[4],y+ymove[4],table)==1)
			aftersafe(4);
		else if(safemove(x+xmove[5],y+ymove[5],table)==1)
			aftersafe(5);
		else if(safemove(x+xmove[6],y+ymove[6],table)==1)
			aftersafe(6);
		else if(safemove(x+xmove[7],y+ymove[7],table)==1)
			aftersafe(7);
		else
		 	break;
	}
	printf("      ");
	for(i=0;i<8;i++)
		printf("%2d  ",i);
	printf("\n    ¢z-------------------------------\n");
	for(i=0;i<8;i++)
	{	
		printf(" %2d¢y ",i);
		for(j=0;j<8;j++)
			printf("%2d  ",table[i][j]);
		printf("\n");
	}
	
	printf("\nTotal moves: %d\n",mov-1);
	
	return 0;
}
 	
 	
 	
	
 	

