#include<stdio.h>
int main()
{
	int degree,coefficient,term;
	char power= '^';
	printf("\t\t----------Welcome to the Polynomial Derivative Calculator-----------\n\n\tKindly input the maximum degree of your polynomial:  ");
	scanf("%d",&degree);

	while(degree<0)
	{ 
		printf("\n\nEnter coefficient of x%c%d",power,degree);
			printf("\nx%c%d: ",power,degree);
			scanf("%d",&coefficient);	
			term=(coefficient*degree);
			printf("The derivative of %dx%c%d is: %dx%c%d",coefficient,power,degree,term,power,degree-1);
			degree--;
		}
	if(degree==0)
	{ 
	printf("\nSince the derivative of a (constant and 0) number  is zero.");
	printf("\nTherefore, the derivative of x%c%u is 0\n",power,degree);
	}
		while(degree!=0 && degree>0)
		{
			printf("\n\nEnter coefficient of x%c%d",power,degree);
			printf("\nx%c%u: ",power,degree);
			scanf("%d",&coefficient);	
			term=(coefficient*degree);
			printf("The derivative of %dx%c%u is: %dx%c%u",coefficient,power,degree,term,power,degree-1);
			degree--;
		}
	printf("\n\n\t\t-----------------Thank you for using this calculator--------- ");
	printf("\n\n\t\t\t\t Made by Muzamil Soomro of BSCS-1F.");
}
	
