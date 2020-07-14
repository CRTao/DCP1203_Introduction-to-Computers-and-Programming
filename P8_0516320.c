#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void print(char course[2][60],int ground[],int t){
	
	int i=0,l,j=0;
		if(t+25>59)l=60;
		else l=t+25;
	
		printf("\n");
		for(i=t;i<l;i++)
			printf("%3d",i+1);
		printf("\n");
		for(i=t;i<l;i++){
			if(ground[i]==0)printf("  R");
			else if(ground[i]==1)printf("  F");
			else printf("  S");
		}
		printf("\n");
		for(i=0;i<2;i++){
			for(j=t;j<l;j++)
				printf("%3c",course[i][j]);
			printf("\n");
			
		}
		
		
}

int tf(){
	int ran;
	
	ran=rand()%10;
	if(ran==0||ran==1||ran==2||ran==3||ran==4){
		return 3;
	}
	else if(ran==5||ran==6){
		return 6;
	}
	else if(ran==7||ran==8||ran==9){
		return 1;
	}
}

int hf(){
	int ran;
	
	ran=rand()%10;
	if(ran==0||ran==1){
		return 0;
	}
	else if(ran==2||ran==3){
		return 9;
	}
	else if(ran==4){
		return 12;
	}
	else if(ran==5||ran==6||ran==7){
		return 1;
	}
	else if(ran==8||ran==9){
		return 2;
	}
}


int main(){
	srand(time(NULL));
	char course[2][60];
	int ground[60];
	
	int i=0,j=0,t,h,tl=0,hl=0,tll=0,hll=0,hbh=0,slowdown=0,e=0,fs=0;
	for(i=0;i<60;i++){
		ground[i]=rand()%5;
	}
	for(i=0;i<60;i++){
		course[0][i]=' ';
		course[1][i]=' ';
	}
	
	printf("Bang!They are off!\n\n");
	course[0][0]='T';
	course[1][0]='H';
	for(i=1;i<26;i++)
			printf("%3d",i);
	printf("\n");
	for(i=0;i<25;i++){
			if(ground[i]==0)printf("  R");
			else if(ground[i]==1)printf("  F");
			else printf("  S");
		}
	printf("\n");
	for(i=0;i<2;i++){
		for(j=0;j<25;j++)
			printf("%3c",course[i][j]);
		printf("\n");
	}
	printf("\nPress any button for next step.\n");
		getchar();
	
	while(0==0){
		e++;
		system("cls");
		course[0][tl]=' ';
		course[1][hl]=' ';
		
		t=tf();
		tll=tl;
		if(ground[tll]==0)t=3;
		
		if(t==3){
			printf("Tortoise: Fast Plod.\n");
			tl+=t;
			if(tl>=60)tl=59;
		}
		else if(t==6){
			printf("Tortoise: Slip.\n");
			tl-=t;
			if(tl<0)tl=0;
		}
		else if(t==1){
			printf("Tortoise: Slow Plod.\n");
			tl+=t;
			if(tl>=60)tl=59;
		}
		course[0][tl]='T';
		
		if(slowdown!=0)printf("Slowdown. ");
		h=hf();
		hll=hl;
		if(hbh==2)h=0;
		if(tll==hll&&e!=1){
			printf("HURT!  ");
			h=0;
			slowdown=2;
		}
		if(ground[hll]==1&&fs==0){
		h=0;
		}
		if(fs==1)fs=0;
		
		if(h==0){
			printf("Hare: Sleep.\n");
			hbh=0;
			fs++;
		}
		else if(h==9){
			printf("Hare: Big Hop.\n");
			if(slowdown!=0){
				h/=2;
				slowdown--;
			}
			hl+=h;
			hbh++;
			if(hl>=60)hl=59;
		}
		else if(h==12){
			printf("Hare: Big Slip.\n");
			hl-=h;
			hbh=0;
			if(hl<0)hl=0;
		}
		else if(h==1){
			printf("Hare: Small Hop.\n");
			if(slowdown!=0){
				h/=2;
				slowdown--;
			}
			hl+=h;
			hbh=0;
			if(hl>=60)hl=59;
		}
		else if(h==2){
			printf("Hare: Small Slip.\n");
			hl-=h;
			hbh=0;
			if(hl<0)hl=0;
		}
		
		
		
		course[1][hl]='H';
		
		
		
		if(hl==tl)printf("\n OUCH !!\n");
		
		
		
		if(hl==59){
			printf("Hare wins. Yuch. \n");
		}
		else if(tl==59){
			printf("Tortoise wins. Yay. \n");
		}
		else if(tl==hl&&tl==59){
			printf("It's tie.\n");
		}
		
		
		if(abs(hl-tl)<=24 && hl<25 && tl<25){
		print(course,ground,0);			
		}
		
		else if(abs(hl-tl)<=24 && hl<tl ){
		print(course,ground,hl);
		}
		
		else if(abs(hl-tl)<=24 && tl<hl ){
		print(course,ground,tl);
		}
		
		else if(abs(hl-tl)>24 && hl<tl ){
		print(course,ground,hl);
		print(course,ground,hl+25);
		if(abs(hl-tl)>49)print(course,ground,hl+50);
		}
		
		else if(abs(hl-tl)>24 && tl<hl ){
		print(course,ground,tl);
		print(course,ground,tl+25);
		if(abs(hl-tl)>49)print(course,ground,tl+50);
		}	
	
		
		
		if(hl==59||tl==59)break;
		printf("\nPress any button for next step.\n");
		getchar();
		}
	
	
	return 0;
}
