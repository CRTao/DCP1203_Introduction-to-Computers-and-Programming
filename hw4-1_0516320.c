#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>

int main(){
	

	int correct=0,repeatcheck=0,vic=0,a=0,b=0,times=0,newround=0;
	int flag=0,count=0,i=0,j=0,e=0,n;
	char answer[10],decide;
	char input='\0';
	
		
	
	while(newround==0){
	
		
	system("cls");
	fflush(stdin);	
	input='\0';
	printf("Welcome to play '1A2B'!!\n\n");
	correct=0;repeatcheck=0;vic=0;a=0;b=0;times=0;
	
	//電腦亂數 
	srand(time(NULL));
	for(int p=0;p<4;p++)
	{
	answer[p]=rand()%10 +'0';
		for(int q=0;q<p;q++)      //不能重複 
			if(answer[p]==answer[q]){p--;break;}
	}
	answer[4]='\0';
	printf(">>%s<<  解答 好確定程式:) \n\n",answer);//
	
	
		while(vic==0){
			
			
		char in[20]={0},c[20]={0};
		a=0;b=0;
		
			
		printf("Please input a 4-digits numbers: ");
		
			while(correct==0){
			
			correct=0,repeatcheck=0;
			
			
			int digit[10]={0,0,0,0,0,0,0,0,0,0};
			flag=0;count=0;i=0;j=0;e=0;n;
			
				
				while((input=getchar())!='\n')
       			 {
	     		    e=1;
         		    if(isdigit(input)&&flag==0)
         		    {
					 in[i++]=input;
           		     count++;
            		}
            		else
            		{
                	 flag=1;
                	 c[j++]=input;
               			 if(count==0)
               			 {
                   			break;
              		     }
           			 }
      			 }
        
        
        	if(flag==0&&e!=0&&count==4)
       		 {	
           		for(int a=0;a<4;a++)
        		{
        		n=in[a]-'0';
        		digit[n]++;
				}
        		
        		printf("%s",digit);
        	     	        	
				for(int b=0;b<10;b++)
				if(digit[b]>1){
				repeatcheck++;
				}
			
        
        
				if(repeatcheck==0){
				printf("Your input number is %s.   ",in); 
				correct=1;
				}
				else
				printf("-!-  Your input number is %s.  It has some of same digits, please try again!\n",in); 
				break;
                      
        	}
        	else if(flag!=0&&count==0){
        			printf("-!-  Your input does not begin with a numerical character.\n");
        			fflush(stdin);
        			break;
                  	}
       		else if(flag!=0&&count!=0){
		        	printf("-!-  Your input number is %s  You must input a 4-digits number with only numerical character!  \n",in);
		        	break;
					}
    		else{
		  			if(count!=0)printf("-!-  You have to input a 4-digit number.\n");
		  			break;
					}
			getchar();
		
    		}//驗證字串 
    	
		if(correct==1){
		
		times++;
		for(int m=0;m<4;m++)
                for(int n=0;n<4;n++)
                                {
                                if(answer[m]==in[n] )
                                        if(m==n)
                                                a++;
                                        else
                                                b++;}
                
                if(a==4)
                {	printf("\n--------------------------------------------------------\n");
                	printf("Congratulation! After %d trials, you got the right number! \n",times);
                    printf("Do you want to play again? (Y/N)");
                    
					while(vic==0){
					
					decide=getchar();
                    if(decide=='y'||decide=='Y'){
                    	vic=1;
						newround==0;
					}
					else if(decide=='n'||decide=='N'){
						vic=1;
						newround=1;
					}
					else 
					printf("Really? I still need to proof the wrong value??? Try again.\n");
					}
                    
                } else {
                    printf("You got %dA%dB.\n",a,b);}
                    
       
          
		}
    
    
		fflush(stdin);
        	correct=0;
    	}//勝局 
    
	
	
	    
	}
	printf("--------------------------------------------------------\n");
	printf("\nThank you for your playing!\n");
	system("pause");


	return 0;
}
