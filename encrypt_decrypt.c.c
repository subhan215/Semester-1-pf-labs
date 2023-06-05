#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

bool password_verify(char*password){
	int length=strlen(password);
	if(length<8||length>16){
	return false;
	}
	bool has_upper=false;
	bool has_lower=false;
	bool has_digit=false;
	bool has_symbol=false;
	int i ; 
	for(i=0;i<length;i++)
	{
	if(isupper(password[i]))
	has_upper=true;
	if(islower(password[i]))
	has_lower=true;	
	if(isdigit(password[i]))
	has_digit=true;	
	if(ispunct(password[i]))
	has_symbol=true;	
	}
	if(!has_upper) return false;
	if(!has_lower) return false;
	if(!has_digit) return false;
	if(!has_symbol) return false;
	return true;
}
void hide_pass(char password[]){
	char character;
	int counter=0 , i;
	while((character=_getch())!=13 ){
		if(character == 8 ) {
			fflush(stdout) ; 
			printf("\b") ; 
			password[--counter] = '\0' ; 
			continue ; 
		}
		printf("*") ;
		password[counter]=character;
		counter++;
		
		}
	
	
	password[counter]='\0';
}
void encrypted_pass(char password[]){
	int counter;
	for(counter = 0; (counter < 100 && password[counter] != '\0'); counter++){
        password[counter] = password[counter] + 3;
	}
}

void decrypted_pass(char password[]){
	int counter;
	for(counter = 0; (counter < 100 && password[counter] != '\0'); counter++){
        password[counter] = password[counter] - 3;
	}
}
int main() {
	char password[16],cPassword[16],confirm[16];
	printf("\n\n\t*-->Your Password should contain atleat 8 characters(1 special character , 1 uppercase ,1 lower case and 1 number)<--*\t");
	getch();
    while(1){
	printf("\n\nCreate New Password : ");
	fflush(stdin) ; 
	hide_pass(password);
	bool result=password_verify(password);
	if (result){
	while(1)
	{
	printf("\n\nComfirm Your password : ");
	hide_pass(cPassword);
	int x;
	x=strcmp(password,cPassword);
	if(x>0||x<0)
	{
	printf("\n\n\t---\tKindly Insert The Same Password<---\t");
	continue;
	}
	else
	{printf("\n\n\t------>Your Account Has Been Created Successfully :)<-------\t");
	break;
	}
	}
	break;
}
	else{
	 printf("\n\n\t--->Kindly Enter A Strong Password , which should meet above given format<---\t ");
	 getch();
	 continue;
	}
	} 
	encrypted_pass(password);
	printf("\n\n\t--->Press Enter For Encrypted Password<---\t\n");
	getch();
	printf("\nEncypted Password : %s\n",password);
	decrypted_pass(password);
	printf("\n\t--->Press Enter For Decryted Password<---\t\n");
	getch();
	printf("\n\nDecypted Password : %s\n",password);
	}
