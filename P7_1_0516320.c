#include<stdio.h>
#include<stdlib.h>

int main()
{

	FILE *in,*out;
	char maze[10][10];
	int path[50][2],d[50]={'\0'};
	int len=-1,a,b,i,j;
	int wx,wy,o,ox,oy,sx,sy,ex,ey;
	
	
	
	in=fopen("input.txt","r");
	if(fopen("input.txt","r")==NULL)
			{printf("input.txt not found \n");return 0;}
	fscanf(in,"%d%d",&b,&a);
	fscanf(in,"%d%d%d%d",&sy,&sx,&ey,&ex);
	fscanf(in,"%d",&o);
	i=0;j=0;
	for(i=0;i<a;i++) {
        for(j=0;j<b;j++)
        {
				maze[i][j]='0';
        }
    }
    i=1;
	for(i=1;i<=o;i++){
		fscanf(in,"%d%d",&oy,&ox);
		ox=a-1-ox;
		maze[ox][oy]='1';		 
	}
    
	sx=a-1-sx; 
	ex=a-1-ex; 
	
	//preview
	printf("Preview.\n\n");
	maze[sx][sy]='S';
    maze[ex][ey]='E';
    i=0;j=0;
        for(i=0;i<a;i++)
    {
        for(j=0;j<b;j++)
            printf(" %c",maze[i][j]);
        printf("\n");
    }
    
    maze[sx][sy]='0';
    maze[ex][ey]='0';
    
    
    wx=sx;
	wy=sy;
    while(wx!=ex||wy!=ey)
    {	           
		if(maze[wx-1][wy]=='0'&&(wx-1)>=0)
        {   
            maze[wx][wy]='^';
            len++;					 
            path[len][0]=wx;
            path[len][1]=wy;
			d[len]=0;
            wx--;				
        }
		else if(maze[wx+1][wy]=='0'&&(wx+1)<a)
        {
            maze[wx][wy]='V';
            len++;
            path[len][0]=wx;
            path[len][1]=wy;
			d[len]=1;
            wx++;
        }
		else if(maze[wx][wy-1]=='0'&&(wy-1)>=0)
        {   
            maze[wx][wy]='<';
            len++;
            path[len][0]=wx;
            path[len][1]=wy;
			d[len]=2;
            wy--;
        }
        else if(maze[wx][wy+1]=='0'&&(wy+1)<b)
        {   
            maze[wx][wy]='>';	
            len++;						
            path[len][0]=wx;
            path[len][1]=wy;
			d[len]=3;
            wy++;
        }
        else
        {	maze[wx][wy]='X';
            wx=path[len][0];
            wy=path[len][1];
			d[len]='\0';
            len--;
			 
        }
	}
      /*  
        printf("%d %d \n",path[len][0],path[len][1]);
        for(int i=0;i<a;i++)
    {
        for(int j=0;j<b;j++)
            printf(" %c",maze[i][j]);
        printf("\n");
    }
        system("pause");
    }
	*/
	
    i=0;
    printf("\nTotal step : %d\n",len+1);    
    for(i=0;i<len+1;i++)
        {
        	if(d[i]==0)d[i]=1;
        	else if(d[i]==1)d[i]=0;
        	else if(d[i]==2)d[i]=3;
        	else if(d[i]==3)d[i]=2;
        }
    i=len;
    for(i=len;i>=0;i--)
        printf("%2d",d[i]);
    printf("\n");
    
    
    printf("\n");
    i=0;j=0;
        for(i=0;i<a;i++)
    {
        for(j=0;j<b;j++)
            printf(" %c",maze[i][j]);
        printf("\n");
    }
    printf("\n");
    
        printf("route.txt has written.\n");
    	out=fopen("route.txt","w");
		if(out==NULL)
			printf("Cannot open the file 'route.txt'");
		else
			{
				fprintf(out,"%d\n",len+1);
				i=len;
				for(i=len;i>=0;i--)
					fprintf(out,"%d ",d[i]);
        
			}

	return 0;	
}
