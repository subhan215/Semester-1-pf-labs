#include <stdio.h>
#include <math.h>
#include<stdlib.h>

// Question 5 //
/*int main() {
	float noOfIce , hrsPerDay , total , consumeDays , hrsConsume , costDouble , costSingle;
	printf("One Ice-Cream cost is 60Rs\n") ; 
	printf("How many ice-creams you want to order: " , noOfIce) ; 
	scanf("%f" , &noOfIce)  ; 
	printf("how many hours you want to run the plant in a day: 8 OR 16 (After 8 hours price will be doubled)") ; 
	scanf("%f" , &hrsPerDay) ; 
	consumeDays = noOfIce / (hrsPerDay * 50) ;
	hrsConsume = noOfIce / 50 ; 
	printf("Consume Days : %.1f\n" , consumeDays) ; 
	printf("Consume Hours : %.0f\n" , hrsConsume) ; 
	
	if(hrsPerDay == 16) {
		costSingle = 60 * (noOfIce - (50 * (consumeDays - floor(consumeDays) > 0.5 ? consumeDays + ((consumeDays - floor(consumeDays)) - 0.5 ) : floor(consumeDays) ) * 8) ) ; 
		costDouble = 120 * (50 * (consumeDays - floor(consumeDays) > 0.5 ? consumeDays + ((consumeDays - floor(consumeDays)) - 0.5 ) : floor(consumeDays) ) * 8); 
		total = costDouble + costSingle ; 
		printf("Before 8 hours Cost : %.0f\n" , costSingle) ; 
		printf("After 8 hours Cost : %.0f\n" , costDouble) ; 
		
	} else {
		total = 60 * noOfIce ; 
		
	}
	printf("Total Cost : %.0f" , total) ; 
	return 0 ;
} */
// Question 1 //
/*float distance(int x2 , int y2) {
	int x1 = 1 , y1 = 3 ; 
	float formula;
    formula = sqrt(pow((x2-x1),2)+pow((y2-y1),2));
    return formula;
}
int main() {
	int Lsd , N  , i  , a , b; 
	float res ; 
	printf("Enter LSD of your mobile number: ") ; 
	scanf("%d" , &Lsd) ; 
	if(Lsd > 0 && Lsd < 4) {
		N = pow((2) , Lsd) * 2 ; 
	} else if(Lsd == 0) {
			N = pow((2) , Lsd) * 4 + 3 ; 
	} else {
		N = Lsd ; 
	}
	printf("Number of Locations : %d\n" , N) ; 
	for(i = 1 ; i <=N ; i++) {
		printf("Enter the abscissa of location: ") ;
		scanf("%d" , &a) ; 
		printf("Enter the ordinate of location: ") ; 
		scanf("%d" , &b) ;
		res =   distance(a , b) ;     
		printf("The distance between Reference Point (1 , 3) and (%d , %d) is : %.2f\n" , a , b , res) ; 
		 
		
	}
	return 0 ; 
} */
// Question 2 //
/*int main(){
	int age , N , i , area;
	printf("For how many persons you want the program to run: ") ; 
	scanf("%d" , &N) ; 
	for( i = 1 ; i <= N ; i++) {
		printf("Enter your age: ") ; 
		scanf("%d" , &age) ; 
		printf("Enter your area  (1 for urban and 2 for rural): ") ; 
		scanf("%d" , &area) ; 
		if(age >=18 || area == 1) {
			printf("Eligible for the vaccine. Kindly proceed for the vaccination\n") ; 
		} else if(age < 18 || area == 2) {
			printf("Not Eligible for the vaccine. Kindly wait for the vaccination\n") ; 
		} else {
			printf("Invalid Input!\n") ; 
		}
	} 
	return 0 ; 
	// Other Possibilities
	// We can also do this question using while and do-while loop with switch statement/if else... 
    
} */
// Question 3 // 
int main() {
	int ans  , i = 0 , j = 0 , k = 0  ,a ,  num; 
	
	char str[100] , revStr[100]  , decNum[100]  ; 
	printf("What do you want to perform (1 for encryption and 2 for decryption): ") ; 
	scanf("%d" , &ans) ; 
	if(ans == 1) {
		printf("Enter the integer for encryption: ") ; 
		scanf("%d" , &num) ; 
	
		while(num !=0) {
			a = num%10 ; 
			num = num / 10 ; 
			printf("%c" , a + 65) ; 
		}
	} else if(ans == 2){
		int length , counter , digit = 0 , b = 1  , c;
		printf("Enter the number of letters : ")  ; 
		char ch ;  
		scanf("%d" , &length) ; 
		for(counter = 0 ;  counter < length ; counter++) {
			printf("Enter the character: ") ; 
			fflush(stdin) ; 
			scanf("%c" , &ch) ; 
		digit = digit + ((ch - 65) * b) ; 
		b = b * 10 ; 
			
		}
		if(digit == 0) {
			for(c = 1 ; c<= length ; c++) {
				printf("%d" , digit) ; 
			}
			
		} else {
			printf("%d" , digit) ; 
		} 
		/*printf("Enter the number of letters : ")  ; 
		char ch ;  
		scanf("%d" , &length) ; 
		for(counter = 0 ;  counter < length ; counter++) {
			printf("Enter the character: ") ; 
			fflush(stdin) ; 
			scanf("%c" , &ch) ; 
		digit = ch - 65 ;
		printf("%d\n" , digit) ; */
	}
		
		/*printf("Enter the string for decryption: ") ; 
		scanf("%s" , &str) ; 
		while (str[j]) {
			j++ ; 
		} 
		i = j - 1 ; 
		while(str[k]){
	     revStr[k] = str[i] ; 
		 i--   , k++;   		
}
		for(i = 0 , k = 0 ; i<j ; i++ , k++) {
			a = revStr[i] % 65 ; 
		
			if(a >=10) {
				decNum[k] = (a / 10) + 48 ; 
				k++ ; 
				decNum[k] = (a%10) + 48 ; 
				
			} else {
				decNum[k] = a + 48; 
			}
		}
		printf("%s" , decNum) ; */
	
	else {
		printf("Invalid Input!") ; 
	}
	return 0 ; 	
} 
// Question 4 //
/*int main() {
	int num ; 
	int age , gender  , j = 0 , sum = 0  , a , output , verCode ;  
	printf("Enter the input string: ") ;
	scanf("%d" , &num) ; 
	printf("Enter your age: ")  ; 
	scanf("%d" , &age) ; 
	printf("Enter your gender (1 for Male and 0 for female): ") ; 
	scanf("%d" , &gender) ;  
	num = num + age + gender ; 
	while(num != 0 ) {
		a = num % 10 ; 
		num = num / 10 ; 
		sum = sum + a ; 
	}
	output = sum % 5 ; 
	printf("Input the verification code: ") ; 
	scanf("%d" , &verCode) ; 
	if(verCode == output) {
		printf("Correct Code!") ; 
	} else {
		printf("Incorrect Code!") ; 
	}
	return 0 ; 
	
} */
// Question 6 //
/*int main() {
	char ans ;  
	int messageIteration , counter  , counter1 , counter2; 
	printf("Enter message iteration: ") ; 
	scanf("%d" , &messageIteration) ; 
	for(counter = 0 ; counter < messageIteration ; counter++ ) {
			printf("Communicating with SD/mobile (s for SD , m for mobile): ") ; 
			fflush(stdin) ; 
	        scanf("%c" , &ans) ;
			for(counter1 = 0 ; counter1 < 4 ; counter1++){
			
		     printf("***\n") ; 
		     for(counter2 = 0 ; counter2 < 5 ; counter2++) {
			 
		          if(ans == 115){	
		           printf("Move Straight!\n") ;  
		          } 
	              else{	 
	     	    printf("Mobile is in city zone!\n") ; 	    
                  } 
            }
		 printf("***\n") ;
	}
	
	}
	return 0 ; 
} */
