#include<stdio.h>
#include<stdlib.h>
// 0up 1down 2left 3right
int feasiblemove(int MAX_r,int MAX_c,int maze[MAX_r][MAX_c] , int x,int y){

	if(x>=0 && x<MAX_c && y>=0 && y<MAX_r && maze[y][x] == 0)
        return 1;
        
    return 0;
	
}

int findway(int maze[MAX_r][MAX_c] , int MAX_c,int MAX_r,int sx,int sy,int ex,int ey){
	
	int len=0,path[20],nextmove,direction=0,x,y,i=0;
	x=ex;
	y=MAX_r-1-ey;  //maze[y][x]
	while(len>=0){
		while(1){
			nextmove=feasiblemove(maze,x,y);
				if(direction==0)y=y-1;
				if(direction==1)y=y+1;
				if(direction==2)x=x-1;
				if(direction==3)y=x+1;
				if(feasiblemove(maze[MAX_r][MAX_c],x,y)==1)
					{
					path[i]=0;
					i++;
					if(x==ex&&y==MAX_r-1-ey)
						{
						break;break;
						}
					}
				else
					{
					break;
					}
				}
		if(direction==0)y=y+1;
		if(direction==1)y=y-1;
		if(direction==2)x=x+1;
		if(direction==3)y=x-1;
		i--;
		path[i]='\0';
		direction++;
		if(direction==4)direction=0;
	}
	
}


int main(){
	
	int MAX_c,MAX_r;
	printf("Enter the size of the maze. ( c , r )\n");
	scanf("%d %d",&MAX_c,&MAX_r);
	
	int maze[MAX_r][MAX_c];
	
	for(int i=0;i<MAX_r;i++)
		for(int j=0;j<MAX_c;j++)
			maze[i][j]=0;
		
		
	
	int sx,sy,ex,ey;
	printf("Start:( x , y );End:( x , y )\n");
	scanf("%d %d %d %d",&sx,&sy,&ex,&ey);
	maze[MAX_r-1-sy][sx]=1;
	maze[MAX_r-1-ey][ex]=2;
	int o,i=1,ox,oy;
	printf("Number of obstacles.\ ");
	scanf("%d",&o);
	for(i=1;i<=o;i++){
		printf("#%d Obstacle (x,y) :",i);
		scanf("%d %d",&ox,&oy);
		maze[MAX_r-1-oy][ox]=-1;
		 
	}
	
	
	printf("\n  ");
	for(int i=0;i<MAX_r;i++)
		{for(int j=0;j<MAX_c;j++)
			printf("%3d",maze[i][j]);
		printf("\n  ");
		}

	
	
	
	return 0;
}
