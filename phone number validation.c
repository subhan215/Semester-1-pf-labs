#include<stdio.h>
#include<string.h>
void numbervalidation(char number[]);
int main(){
	char phoneNo[50] ; 
	numbervalidation(phoneNo);
	printf("%s" , phoneNo) ; 
}
void numbervalidation(char number[]){
	char i,length;
	while(1) {
	printf("\nEnter Your Phone Number : ");
	fflush(stdin) ; 
	scanf("%s",number);
	length=strlen(number);

	
	if(number[0]=='0'){
		if(length==11){
			printf("\nPhone Number is verified :");
			break ; 
		} else {
			printf("Enter a valid phone number!") ; 
		}
	}
	else if(number[0]=='+'){
		if(number[1]=='9'){
			if(number[2]=='2'){
				if(length==13){
					printf("\nPhone Number is verified :");
					break ;
				}
				
			}
		}
	}
	else{
		printf("Enter a valid phone number : \n");
	}
	}
	
}


