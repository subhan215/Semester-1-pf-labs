#include <stdio.h>
datevalidation();
int main()
{
    datevalidation();
    return 0;    
}
void datevalidation(){
	int day,month,year;
     while(1) {
	 
    printf("Input Date in day-month-year fromat : ");
    scanf("%d-%d-%d",&day,&month,&year);
     
    if(year>=1900 && year<=3000)
    {
        
        if(month>=1 && month<=12)
        {
            if((day>=1 && day<=31) && (month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12))
                break ; 
                
            else if((day>=1 && day<=30) && (month==4 || month==6 || month==9 || month==11))
              break ; 
                
            else if((day>=1 && day<=28) && (month==2))
                break ; 
                
            else if(day==29 && month==2 && (year%400==0 ||(year%4==0 && year%100!=0)))
                break ; 
                
            else
                printf("You have input Invalid date :(\n");
                
        }
        else
        {
            printf("You have Input Invalid date :\n");
        }
    }
    else
    {
        printf("You have Input invalid date :(\n");
    }
}
 
}
