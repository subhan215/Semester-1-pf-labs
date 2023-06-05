#include<stdio.h>
int main()
{
	int degree,coefficient,term;
	float final;
	char power= '^';
	printf("\t\t----------Welcome to the Polynomial AntiDerivative Calculator-----------\n\n\tKindly input the maximum degree of your polynomial:  ");
	scanf("%d",&degree);
		while(degree<-1 )
		{
			printf("\n\nEnter coefficient of x%c%d",power,degree);
			printf("\nx%c%d: ",power,degree);
			scanf("%d",&coefficient);
			final=(float)coefficient/(degree+1);
			
			printf("The Antiderivative of %dx%c%d is: %0.2fx%c%d",coefficient,power,degree,final,power,degree+1);
			break;
		}
	while(degree==-1){
		printf("\n\t\t\tWhenever the maximum power is -1\n\t\t\t   The antidervative is 0.");
		break;
	}
		while(degree>-1 )
		{
			printf("\n\nEnter coefficient of x%c%d",power,degree);
			printf("\nx%c%d: ",power,degree);
			scanf("%d",&coefficient);
			final=(float)coefficient/(degree+1);
			
			printf("The Antiderivative of %dx%c%d is: %0.2fx%c%d",coefficient,power,degree,final,power,degree+1);
			break;
		}
	printf("\n\n\t\t-----------------Thank you for using this calculator--------- ");
	printf("\n\n\t\t\t\t Made by Muzamil Soomro of BSCS-1F.");
}
	
