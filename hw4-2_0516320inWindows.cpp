#include<stdio.h>
#include<windows.h>

int days[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

void SetColor(int color)
{
HANDLE hConsole;
hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hConsole,color);
}

int main()
{
	int year,dayblank,month,day;	
	char *months[]={" ","January","February","March","April","May","June","July","August","September","October","November","December"} ;
	//address ¦s¦r¦ê 
	printf("Please enter a year (A.D.) : ");
    scanf("%d", &year);
    
    dayblank=(year+(year-1)/4-(year-1)/100+(year-1)/400)%7;
    
    if(year%4==0&&year%100!=0||year%400==0)  //leap year
	{days[2]=29;}
	else{days[2]=28;}
	
	printf("Please enter a month : ");
	scanf("%d", &month);
	printf("\n-------------------------------------------\n");
	printf("             %s %d\n", months[month],year);
	printf("-------------------------------------------\n");
	SetColor(12);
	printf("   Sun");
	SetColor(7);
	printf("   Mon   Tue   Wed   Thu   Fri   ");
	SetColor(12);
	printf("Sat\n");
	SetColor(7);
	
	for(day=days[month-1]-dayblank+1;day<=days[month-1];day++)
		{if(day==days[month-1]-dayblank+1)SetColor(120);
		 printf("%6d",day);
		 SetColor(8);}
		
	SetColor(7);
	for(day=1;day<=days[month];day++)
	{	if(dayblank==0&&day==1)SetColor(112);
		printf("%6d",day);
		SetColor(7);
		if((day+dayblank)%7<=0)
			{printf("\n");
			SetColor(112);
			}
		else if((day+dayblank)%7==6)
			SetColor(112);
			
	} 
	SetColor(8);
	if(dayblank==0&&(35-days[month]-dayblank)%7==0);
	else
	{
	for(day=1;day<=35-days[month]-dayblank;day++)
		{if(day==35-days[month]-dayblank)SetColor(120);
		 printf("%6d",day);}
	SetColor(7);
	}
	
	printf("\n");
	
	return 0;
}
