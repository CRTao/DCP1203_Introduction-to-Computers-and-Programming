#include <stdio.h>
#include <stdlib.h>


typedef struct node{
    int data;
    struct node* next[10];
}node;

node* create_node(int);
void insert_node(node*, node*,int);
void print_lists(node*,int,int,int);
int nc[10]={0};
int max=0;
int npointed[10]={0};
int arrayn[10]={0};
int array[10][20]={0};

int main(int argc,char **argv)
{
    node* n1 = create_node(1);
    node* n2 = create_node(2);
    node* n3 = create_node(3);
    node* n4 = create_node(4);
    node* n5 = create_node(5);
	node* n6 = create_node(6);
    node* n7 = create_node(7);
    node* n8 = create_node(8);
    node* n9 = create_node(9);
    node* n10 = create_node(10);
    node* nn[10]={n1,n2,n3,n4,n5,n6,n7,n8,n9,n10};
	
	
	FILE *check = fopen(*(argv+1),"r");
	int c=0,lines=1;
	while((c = fgetc(check)) != EOF){ 
	if (c == '\n')lines++;
	}
	fclose(check);
	
	FILE *in = fopen(*(argv+1),"r");
	int i=0,j,head,behind;
	for(i=0;i<lines;i++){
		fscanf(in,"%d %d",&head,&behind);
		npointed[behind-1]++;
		if(1<=head && head<=10 && 1<=behind && behind<=10)insert_node(nn[behind-1],nn[head-1],behind);		
	}	
    	
	print_lists(n1,1,1,0);

	print_lists(n2,2,2,0);

	print_lists(n3,3,3,0);

	print_lists(n4,4,4,0);

	print_lists(n5,5,5,0);

	print_lists(n6,6,6,0);

	print_lists(n7,7,7,0);

	print_lists(n8,8,8,0);

	print_lists(n9,9,9,0);

	print_lists(n10,10,10,0);	

    
	
	//printf("Level: ");
	for(i=0;i<10;i++){
		nc[i]++;
    	//printf("%d",nc[i]);	
    }
    //printf("\n");
    
    i=1;
    for(i=1;i<=max+1;i++){
    	for(j=0;j<10;j++){
    		int k=0;
    		if(nc[j]==i){
    			while(array[i-1][k]!=0)k++;
    			array[i-1][k]=j+1;
    			arrayn[i-1]=k+1;
    		}
    	}
    }
	
	for(i=1;i<=max+1;i++){
		printf("%d %d",i,arrayn[i-1]);
		printf("\n");
		for(j=0;j<arrayn[i-1];j++){
			printf("%d ",array[i-1][j]);
		}
		printf("\n");
	}
		
	
    	
}

node* create_node(int data)
{
	int i=0;
    node* n = (node*)malloc(sizeof(node));
    n->data = data;
    for(i=0;i<10;i++)n->next[i] = NULL;
    return n;
}
	
void insert_node(node* n1, node* n2,int t)
{
	int i=0;
	//if(n1->next!=NULL)n2->next=n1->next;
	while(n1->next[i]!=NULL)i++;
	n1->next[i]=n2;
}
	

void print_lists(node* lists,int t,int head,int c)
{
	int i;
	if(lists){
		if(c>nc[head-1])nc[head-1]=c;
		if(c>max)max=c;
		for(i=0;i<npointed[t-1];i++){
			//printf(" %d",lists->data);
			print_lists(lists->next[i],lists->next[i]->data,head,c+1);
		}
	}
}


