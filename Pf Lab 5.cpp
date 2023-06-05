#include <stdio.h>
#include <math.h>
/*int main() {
	int x ; 
	printf("Enter an integer : ") ; 
	scanf("%d" , &x)  ; 
	if(x%2== 0) {
		printf("\nEven Number") ; 
	} else {
		printf("\nOdd Number") ; 
	}
	return 0 ; 
}  */

// Question 1 //
/*int main() {
	int x ; 
	printf("Enter an integer : ") ; 
	scanf("%d" , &x)  ; 
	if(x%3== 0){
		printf("\nThe number is multiple of 3") ; 
	} else {
		printf("\nThe number is not multiple of 3") ; 
	}
	return 0 ; 
} */
// Question 2 //
/*int main() {
		int x ; 
	    printf("Enter what hour is it: ") ; 
	    scanf("%d" , &x)  ; 
	    printf("Current Status : ") ; 
	    if(x >=5 && x <= 11) {
	    	printf("Good Morning!") ; 
		} else if(x>=12 && x<=18) {
			printf("Good Evening!") ; 
		} else if(x>=19 && x<=24) {
			printf("Good Night!");
		}
		return 0 ; 
} */
/*int main() {
	char ch ; 
	printf("Enter alphabets ") ; 
	scanf("%c" , &ch)  ; 
	switch(ch) {
		case 'a' :
		printf("a is 1st alphabet ") ; 
		break ;  
		case 'b' : 
		printf("b is 2nd alphabet") ; 
		break ;  
		case 'c' : 
		printf("c is 3rd alphabet") ; 
		break ;  
		case 'd' : 
		printf("d is 4th alphabet") ; 
		break ;
		case 'e' : 
		printf("e is 5th alphabet") ; 
		break ;    
		case 'f' : 
		printf("f is 6th alphabet") ; 
		break ;
		case 'g' : 
		printf("g is 7th alphabet") ; 
		break ;
		default:
		printf("Not in given alphabets") ;  
	} 
	return 0 ; 
} */
// Question 3 //
/*int main() {
	printf("Are you sure to delete ? [Y/y] or [N/n]") ; 
	char ans ; 
	scanf("%c" , &ans) ; 
	switch(ans) {
		case 'Y' :
		printf("Deleted Successfully") ; 
		break ; 
		case 'y' :
		printf("Deleted Successfully") ; 
		break ; 
		case 'N' :
		printf("Delete Cancelled") ; 
		break ; 
		case 'n' :
		printf("Delete Cancelled") ; 
		break ; 
		default :
		printf("Select the right option") ; 
			
	}
	return 0 ; 
} */
//  Question 4 //
/*int main() {
	char opt ; 
	float num1, num2 , sum , sub , div , mul ;
	printf("Enter operator: ") ; 
	scanf("%c" , &opt) ; 
	printf("Enter num1: ") ;
	scanf("%f" , &num1) ; 
	printf("Enter num2: ") ;
	scanf("%f" , &num2) ;
	
	switch(opt) {
		case '+' : 
		sum = num1 + num2 ; 
		printf("The sum is : %.2f" , sum) ; 
		break ; 
		case '-' : 
		sub = num1 - num2 ; 
		printf("The subtract is : %.2f" , sub) ; 
		break ; 
		case '/' : 
		div = num1 / num2 ; 
		printf("The division is : %.2f" , div) ; 
		break ; 
		case '*' : 
		mul = num1 + num2 ; 
		printf("The multiplication is : %.2f" , mul) ; 
		break ; 
		default : 
		printf("Please enter right operator") ; 
	} 
	return 0 ; 
} */
// Question 5 //

/*int main() {
	char ch ; 
	printf("Enter a character") ; 
	scanf("%c" , &ch) ; 
	if(ch >= 'a' && ch <= 'z') {
		printf("Small Alphabet!") ; 
	} else if(ch >= 'A' && ch <= 'Z') {
		printf("Capital Alphabet!") ; 
	} else if(ch>='0' && ch <='9') {
		printf("Digit!") ; 
	} 
    else {
    	printf("Special Character!") ; 
	}	
 return 0;
} */
// Question 6 //
int main() {
   int num1 , num2 , num3 ;
   printf("Enter number 1 : ") ; 
   scanf("%d" , &num1) ; 
   printf("Enter number 2 : ") ; 
   scanf("%d" , &num2) ; 
   printf("Enter number 3 : ") ; 
   scanf("%d" , &num3) ; 
   if(num1 > num2 && num3 < num2) {
   	printf("\nvalue 1 is greater than value 2 and value 3 is lesser than value 2 " ) ; 
   }
   else if(num2 > num1 && num2 < num3){
   	printf("\nvalue 1 is lesser than value 2 and value 3 is greater than value 2" ) ; 
   	
   } else if(num2 == num3 && num2 > num1) {
   	printf("\nvalue 2 is greater than value 1 and value 2 is equal to value 3" ) ; 
   } else if(num2 == num3 && num2 < num1) {
   	printf("\nvalue 2 is lesser than value 1 and value 2 is equal to value 3" ) ; 
   } else if(num2 == num1 && num2 > num3){
   	printf("\nvalue 2 is equal to value 1 and value 2 is greater than value 3" ) ;
   } else if(num2 == num1 && num2 < num3) {
   	printf("\nvalue 2 is equal to value 1 and value 2 is lesser than value 3" ) ;
   } else if(num1 == num3 && num1 == num2) {
   	printf("\nall values are equal") ; 
   } else if(num1 == num3 && num2 > num1) {
   	printf("\nvalue 1 and value 3 are equal and both values are greater than value 2 ") ; 
   	
   } else if(num1 == num3 && num2 < num1) {
   	printf("\nvalue 1 and value are equal and both values are lesser than value 2 ") ; 
   } else if(num1 > num2 && num3 > num2) {
   	  printf("both values are greater than value 2 ") ; 
   } else if(num2 > num1 && num2 > num3) {
   	printf("both values are lesser than value 2") ; 
   }
   return 0 ; 
   	
}  
// Question 7 //
/*int main() {
	float costOfItems , discount , amountAfterDis ;
	printf("Enter the cost of your items : ") ; 
	scanf("%f" , &costOfItems) ; 
	if(costOfItems < 1999) {
	     discount = 0 ; 
	} else if(costOfItems >= 2000 && costOfItems <=4000) {
		discount = costOfItems * 0.2 ; 
	} else if(costOfItems >= 4001 && costOfItems <=6000) {
			discount = costOfItems * 0.3 ; 
	} else if(costOfItems >= 6000) {
		discount = costOfItems * 0.5 ; 
	}
	amountAfterDis = costOfItems - discount ; 
	printf("Actual Amount : %.2f" , costOfItems) ;
	printf("\nDiscount : %.2f" , discount ) ; 
	printf("\nAmount after discount : %.2f" , amountAfterDis) ; 
	return 0 ; 
} */
// Question 8 //
/*int main() {
	int lightSen ; 
	printf("Enter the light sensor value (0-1000) : ") ; 
	scanf("%d" , &lightSen) ; 
	if(lightSen > 500) {
		printf("mobile is exposed under sunshine!") ; 
		
	} else if(lightSen >0 && lightSen < 100) {
		printf("It's evening'") ; 
		
	} else if(lightSen >=100 && lightSen <=500) {
		printf("It's lighting") ; 
	}
} */
//Question 9 //
/*int main() {
	float a,b,c,root1 , root2 , discriminant , real , imag ; 
	printf ("Enter the coefficients : \n") ; 
	scanf("%f%f%f" , &a , &b , &c) ; 
	discriminant = (b * b ) - (4 * a * c) ; 
	printf("%f" , discriminant) ; 
	if(discriminant > 0) {
		root1 = (-b+ sqrt(discriminant)) / (2*a) ; 
		root2 = (-b - sqrt(discriminant)) / (2*a) ; 
		printf("root1 = %.2f and root2 = %.2f", root1, root2);
	}
	else if(discriminant == 0) {
		   root1 = root2 = -b / (2 *a ) ; 
		    printf("root1 = root2 = %.2f;", root1);
		} 
	else {
			real = -b / (2 *a ) ; 
			imag = sqrt(-discriminant) / (2*a) ; 
			printf("root1 = %.2f+%.2fi and root2 = %.2f-%.2fi", real, imag, real, imag);
    }

    return 0;	
} */
// Question 10 //
/*int main () {
	int num ; 
	printf("Enter an 8 bit number : ") ; 
	scanf("%d" , &num) ; 
	if(num > 9) {
		printf("\nExchanging higher four bits with the lower bits : %d" , num >> 4) ; 
	} else {
		printf("Invalid Input") ; 
	}
	return 0 ; 
} */
 
