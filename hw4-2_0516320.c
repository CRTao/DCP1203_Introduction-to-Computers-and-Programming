#include<stdio.h>

int days[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

int main()
{
	int year,dayblank,month,day;	
	char *months[]={" ","January","February","March","April","May","June","July","August","September","October","November","December"} ;
	//address 存字串 
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
	printf("\033[40;31m   Sun\033[0m" );
	printf("   Mon   Tue   Wed   Thu   Fri   ");
	printf("\033[40;31mSat\n\033[0m" );
	
	for(day=days[month-1]-dayblank+1;day<=days[month-1];day++)
		{if(day==days[month-1]-dayblank+1)printf("\033[1;47;30m%6d\033[0m",day );
		 else 	printf("\033[1;37;30m%6d\033[0m",day );}
		

	for(day=1;day<=days[month];day++)
	{	if(dayblank==0&&day==1)printf("\033[1;47;30m%6d\033[0m",day );
		else if((day+dayblank)%7==1)
			{
			printf("\n");
			printf("\033[1;47;30m%6d\033[0m",day );
			}
		else if((day+dayblank)%7==0)
			printf("\033[1;47;30m%6d\033[0m",day );
		else printf("%6d",day);
			
	} 
	printf("\033[1;41;30m\033[0m");
	if(dayblank==0&&(35-days[month]-dayblank)%7==0);
	else
	{
	for(day=1;day<=35-days[month]-dayblank;day++)
		{
		if(day==35-days[month]-dayblank)printf("\033[1;47;30m%6d\033[0m",day );
		else printf("\033[1;37;30m%6d\033[0m",day);}
	}
	
	printf("\n");
	
	return 0;
}
