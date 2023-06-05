#include <stdio.h>
#include <math.h>
/*int main(){
	float marks ; 
	printf("how many percent marks have you obtained : ") ;
	scanf("%f" , &marks) ; 
	if(marks < 40) {
		printf("Your grade is F") ; 		
	}
	else if(marks > 100) {
		printf("Invalid Input") ; 
	}  
	else{
		if(marks >=91 && marks <=100) {
			printf("Your grade is A+") ; 
		} else 	if(marks >=81 && marks <=90) {
			printf("Your grade is A");
		}
		else if(marks >=71 && marks <=80) {
			printf("Your grade is B");
		}
			else if(marks >=61 && marks <=70) {
			printf("Your grade is C");
		}
			else if(marks >=51 && marks <=60) {
			printf("Your grade is D");
		} else {
				printf("Your grade is E");
		}
	}
	return 0 ; 

} */
/*int main() {
	char item , color  ; 
	printf("Enter food or vegetable (f/F for fruits and v/V for vegetable): \n") ; 
	printf("Enter color name (r/R for red and g/G for green): \n") ; 
	scanf("%c \n %c" , &item , &color) ; 
	
    
    switch(item){
    	case 'f' : 
    	case 'F' : 
    	  switch(color) {
    	  	case 'r':
    	  	case 'R' : 
    	  	    printf("Apple is red") ; 
    	  	    break ;  
    	  	case 'G' : 
			case 'g' : 
			printf("Grapes are green") ; 
			break ;    
			default : {
		 	printf("Invalid Input") ; 
			break;
		 }   
		  }
		 break ; 
		 case 'V' : 
		 case 'v' : 
		 switch(color) {
		 		case 'r':
    	  	    case 'R' : 
    	  	    printf("Red Chillie is red") ; 
    	  	    break ;  
    	  	case 'G' : 
			case 'g' : 
			printf("Cabbages are green") ; 
			break ;      
			default : {
		 	printf("Invalid Input") ; 
			break;
		 } 
		 } 
		 break ; 
		 default : {
		 	printf("Invalid Input") ; 
			break;
		 }
	}
	return 0 ; 
} */
// Question 1 //
/*int main() {
	int num ; 
	printf("Enter a number: ") ; 
	scanf("%d" , &num) ; 
	int res = ((num%2==0) ? 1 : 0) ;
	char odd[15] = "odd Number" ; 
	char even[15] = "even Number" ;  
	printf("%s" , res ? even : odd) ; 
	return 0 ; 
} */
// Question 2 // 
/*int main() {
	int a , b , c ; 
	printf("Enter first Number: ") ; 
	scanf("%d" , &a) ; 
	printf("Enter Second Number: ") ; 
	scanf("%d" , &b) ; 
	printf("Enter Third Number: ") ; 
	scanf("%d" , &c) ; 
	if(a > b) {
		if(a > c) {
			printf("First Number is greater: %d" , a) ; 
		} else {
			printf("Third Number is great: %d" , c) ; 
		}
	} else if(b > a) {
		if(b > c) {
			printf("Second number is greater: %d" , b) ; 
		} else{
			printf("Third Number is greater: %d" , c) ; 
		}
		
	}
	return 0 ; 
} */
// Question 3 //
/*int main() {
	float marks; 
	char grade ; 
	printf("Enter your marks: ") ; 
	scanf("%f" , &marks) ;
	if(marks < 80) {
		grade = 'C' ; 
		printf("Grade is %c" , grade) ; 
	} else if(marks > 79 && marks <= 100){
		if(marks >=80 && marks < 90) {
			grade = 'B' ; 
			printf("Grade is %c" , grade) ; 
		} else {
			grade = 'A' ; 
			printf("Grade is %c" , grade) ; 
		}
	} else {
		printf("Invalid Input!") ; 
	}
	return 0 ; 
} */
// Question 4 //
/*int main() {
	int opt ; 
	int secOpt ; 
	printf("Please select which type of sandwich you want: \n 1: Chicken \n 2: Beef \n 3: Vegetarian\n") ; 
	scanf("%d" , &opt) ; 
    if(opt ==3) {
    	printf("Please select a vegetarian combination: \n 1: Tomato and mozzarella \n 2: Eggplant and parmesan \n 3: Cucumber and Swiss cheese \n") ; 
    	scanf("%d" , &secOpt) ; 
    	switch(secOpt) {
    		case 1 : 
    		printf("You ordered a Tomato and mozzarella vegetarian sandwich") ; 
    		break ; 
    		case 2 : 
    			printf("You ordered a Eggplant and parmesan vegetarian sandwich") ; 
				break;
			case 3 : 
			printf("You ordered a Cucumber and Swiss cheese vegetarian sandwich") ; 
			break;
			default : 
			printf("Invalid Input") ; 
		}
	} else if(opt ==2) {
		printf("You ordered a Beef Sandwich") ; 
	} else if(opt == 1) {
		printf("You ordered a Chicken Sandwich") ; 
	} else {
		printf("Invalid Input!"); 
	}
	return 0 ; 
} */
// Question 9 //
/*int main() {
	int accNum , mortAm , mortTerm ; 
	 
	float intRate ;
	printf("Enter Account Number: ") ;
	
	scanf("%d" , &accNum) ;
 	for( ; 1 ; ){
	 
	if(accNum < 100 || accNum > 99999){
		printf("Invalid Account Number!\n") ; 
		printf("Enter Account Number: ") ;
		scanf("%d" , &accNum) ;
		continue ; 
	}
	
	else 
	break ; 
}
	printf("Enter Mortgage Amount (In Dollars):  ") ; 
	scanf("%d" , &mortAm) ; 
	printf("Enter Mortgage Term (In Years): ") ; 
	scanf("%d" , &mortTerm) ; 
	printf("Enter interest Rate (As a Decimal): ") ; 
	scanf("%f" , &intRate ) ;
	float totalInt = mortAm * mortTerm * intRate ; 
	mortAm = mortAm + totalInt ; 
	float Payment = mortAm / 12 ;
	printf("Your total Monthly Amount payable is: %.0f%c" , Payment , 36) ; 
	return 0 ; 
	
	 
} */
// Question 5 //
/*int main() {
	int year ; 
	printf("Enter a year: ") ;
	scanf("%d" , &year) ;  
	if(year %4 == 0 ) {
		printf("It's a Leap Year!") ; 
		
	} else if(year %100 == 0 ){
		if(year %400 == 0) {
			printf("It's a leap year!") ; 
		} else {
			printf("It's not a leap year!") ; 
		}
	} else {
		printf("Its not a leap year!") ; 
	}
	return 0 ; 
	
} */
// Question 6 //
/*int main() {
	float a,b,c ; 
	printf("Enter the sides of the triangle : ") ; 
	printf("\nSide 1(in cm): ") ; 
	scanf("%f" , &a) ; 
	printf("Side 2 (in cm): ") ; 
	scanf("%f" , &b) ;
	printf("Side 3 (in cm): ") ; 
	scanf("%f" , &c) ; 
	if(a == b) {
		if(a == c) {
			printf("It's an equilateral triangle!") ; 
			
		}
	} 
	else if(a==b || a==c || b==c) {
			printf("It's an isosceles triangle!") ; 
	} else {
			printf("It's a scalene triangle!") ; 
	
	}
	return 0 ; 
} */
// Question 7 //
/*int main() {
	char type ;
	int size ;  
	float time ;
	printf("Enter a Coffee Type (B/b for Black and W/w for White): ") ; 
	scanf("%c" , &type) ; 

	switch(type) {
		case 'W' : 
		case 'w' : 
			printf("Enter coffee size (2 for double and 1 for single): ") ; 
        	scanf("%d" , &size) ;
	       if(size == 2) {
	           printf("\nOperation 1 Put Water : %.0f min" , 15 * 1.5) ;
			   printf("\nOperation 2 Sugar :  %.0f min" , 15 * 1.5)  ; 
			   printf("\nOperation 3 Mix Well :  %.0f min" , 20 * 1.5) ; 
			   printf("\nOperation 4 Add Coffee :  %.0f min" , 2 * 1.5) ; 
			   printf("\nOperation 5 Add Milk :  %.0f min" , 4 * 1.5) ; 
			   printf("\nOperation 6 Mix Well :  %.0f min" , 20 * 1.5) ; 
			   time =  15 * 1.5 + 15 * 1.5 + 20 * 1.5 + 2 * 1.5 + 4 * 1.5 + 20 * 1.5 ; 
			   printf("\nTotal Baking Time: %.0f min" , time) ; 
		   } else if(size ==1) {
		   	 printf("\nOperation 1 Put Water :  %d min" , 15 ) ;
			   printf("\nOperation 2 Sugar :  %d min" , 15 )  ; 
			   printf("\nOperation 3 Mix Well :  %d min" , 20) ; 
			   printf("\nOperation 4 Add Coffee :  %d min" , 2 ) ; 
			   printf("\nOperation 5 Add Milk :  %d min" , 4 ) ; 
			   printf("\nOperation 6 Mix Well :  %d min" , 20) ;
			    time =  15 + 15  + 20  + 2  + 4  + 20  ; 
			    printf("\nTotal Baking Time:  %.0f min" , time) ; 
		   } else {
		   	printf("Invalid Size !") ; 
		   	
		   }
		break ; 
		case 'B' :
		case 'b' : 
		 if(size == 2) {
		 	printf("Enter coffee size (2 for double and 1 for single): ") ; 
	        scanf("%d" , &size) ;
	           printf("\nOperation 1 Put Water :  %.0f min" , 20 * 1.5) ;
			   printf("\nOperation 2 Sugar :  %.0f min" , 20 * 1.5)  ; 
			   printf("\nOperation 3 Mix Well :  %.0f min" , 25 * 1.5) ; 
			   printf("\nOperation 4 Add Coffee :  %.0f min" , 15 * 1.5) ; 
			   printf("\nOperation 5 Add Milk :  %.0f min" , 0) ; 
			   printf("\nOperation 6 Mix Well : %.0f min" , 25 * 1.5) ;
			   time =  20 * 1.5 + 20 * 1.5 + 25 * 1.5 + 15 * 1.5 + 25 * 1.5 ;  
			     printf("\nTotal Baking Time:  %.0f min" , time) ; 
		   } else if(size ==1) {
		   	 printf("\nOperation 1 Put Water :  %d min" , 20 ) ;
			   printf("\nOperation 2 Sugar :  %d min" , 20)  ; 
			   printf("\nOperation 3 Mix Well :  %d min" , 25) ; 
			   printf("\nOperation 4 Add Coffee :  %d min" , 15 ) ; 
			   printf("\nOperation 5 Add Milk :  %d min" , 0 ) ; 
			   printf("\nOperation 6 Mix Well :  %d min" , 25) ; 
			    time =  20  + 20  + 25  + 15  + 25  ;  
			     printf("\nTotal Baking Time:  %.0f min" , time) ; 
			   
		   } else {
		   	printf("Invalid Size !") ; 
		   	
		   }
		   break ; 
		default : 
		printf("Invalid Type!") ; 
		   
	}
	return 0 ; 
} */
// Question 8 //
int main() {
	int schoolOpt , depOpt  ;
	char course ; 
	printf("Please Select a School: \n 1: School of Computer Science \n 2: School of Business \n 3: School of Engineering\n") ; 
	scanf("%d" , &schoolOpt) ; 
	if(schoolOpt ==1) {
		printf("\nPlease select a department: \n1: Department of Informatics: \n2: Department of Machine Learning\n") ; 
		scanf("%d" , &depOpt) ; 
		if(depOpt ==1) {
	    	printf("Please select a course: \n Course A \n Course B \n Course C \n Course D") ; 
	    	scanf("%c" , &course) ; 
	}
	    	else if(depOpt == 2){
	    		printf("Please select a course: \n Course E \n Course F \n Course G \n Course H \n Course I") ; 
					scanf("%c" , &course) ; 
			 	
		} 
		}
		else if(schoolOpt ==2) {
		
			printf("\nPlease select a department: \n1: Department of Commerce: \n2:Department of purchasing\n") ; 
			scanf("%d" , &depOpt) ; 
				if(depOpt == 1) {
	    	
	    	printf("Please select a course: \n Course X \n Course Y \n Course Z") ; 
	    	scanf("%c" , &course) ; 
	    }
	    	else if(depOpt == 2) {
			
	    		printf("Please select a course: \n Course M \n Course N \n Course O \n Course P") ; 
					scanf("%c" , &course) ; 
				
		} 
	}
		else if(schoolOpt ==3) {
		
	     	printf("\nPlease select a department: \n1: Department of Mechanical Engineering: \n2: Department of Mechatronics Engineering\n") ; 
	     	scanf("%d" , &depOpt) ; 
	     	if(depOpt ==1 ) {
	    	printf("Please select a course: \n Course R \n Course S") ; 
	    	scanf("%c" , &course) ; 
	    }
	    	else if(depOpt ==2) {
			
	    	printf("Please select a course: \n Course J \n Course K \n Course L") ; 
			scanf("%c" , &course) ; 
	}
		}
	
printf("\nYour Selected School : %s" , schoolOpt ==1 ? "School of Computer Science" : schoolOpt ==2 ? "School of Business" : "School of Engineering") ; 
printf("\nYour Selected Department: %s" , schoolOpt ==1 ? (depOpt ==1 ? "Department of Informatics" : "Department of Machine Learning") : schoolOpt ==2 ? 
                                        (depOpt == 1 ? "Department of Commerce" : "Department of purchasing") : 
										(depOpt == 1 ? "Department of Mechanical Engineering" : "Department of Mechatronics Engineering")) ; 
printf("\nYour Selected Course : %c" , course) ; 
return 0 ; 
	
	
} 
