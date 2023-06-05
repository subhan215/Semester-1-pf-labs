#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// Class Practice
//int sum() ; 
/*void unparameterized_sum() {
	int a = 5 , b = 7; 
	int sum = a + b ; 
	printf("sum is %d" , sum) ; 
	
}
int parameterized_sum(int a  , int b) {
	int sum = a + b; 
	return sum ; 
}
int main() {
	int res = parameterized_sum(2 , 3) ; 
	printf("sum is : %d" ,  res) ;
	unparameterized_sum() ; 
	return 0 ; 
} */
// task 7 //
/*int swap(int a , int b) {
	int temp = a ; 
	a = b ; 
	b = temp ; 
	printf("\nAfter Swapping:\ninput1: %d , input2: %d" , a , b) ; 
    return 0 ;  
}
int main() {
	int a , b ; 
	printf("Enter 1st input: ") ; 
	scanf("%d" , &a) ; 
	printf("Enter 2nd input: ") ; 
	scanf("%d" , &b) ;
	printf("Before Swapping:\ninput1: %d , input2: %d" , a , b) ; 
	swap(a , b) ; 
	return 0 ; 
	
} */
// task 9 //
/*int min_max_Func(int num[]) {
	int max = 0  , min = 0 ; 
	for(int i = 0 ; i < 5 ; i++) {
		max = max > num[i] ? max : num[i] ; 
	}
	min = max ; 
		for(int i = 0 ; i < 5 ; i++) {
			min = min < num[i] ? min : num[i] ; 
	}
	printf("\nMaximum is :%d" , max) ;
	printf("\nMinimum is :%d" , min) ;
	return 0 ; 
}
int main() {
	int arr[5] ; 
	printf("Enter The numbers: ") ; 
	for(int i = 0 ; i < 5 ; i++) {
		scanf("%d" , &arr[i]) ; 
	} 
	printf("The Inputed Numbers: ") ; 
	for(int i = 0 ; i < 5 ; i++) {
		printf("%d , " , arr[i]) ; 
	}
	min_max_Func(arr) ;  
	return 0 ;
} */
// task 8 //
/*int largestNum(int length,int arr[]) {
	int largest = 0 ; 
	for(int i = 0 ; i< length ; i++) {
		largest = arr[i] > largest ? arr[i] : largest ; 
	}
	return largest ; 
}
int main() {
	int length ;
	printf("Enter length of the array: ") ; 
	scanf("%d" , &length) ; 
	int arr[length] ; 
	for(int i = 0 ; i < length ; i++) {
	   printf("Enter %d number: " , i + 1) ; 
	   scanf("%d" , &arr[i]) ; 
	}
	printf("The largest num is : %d" ,largestNum(length , arr)) ; 
	return 0 ; 
} */
// task 1//
/*int main() {
	char fName[20] , lName[20] ,fullName[40] ; 
	printf("Enter first name: ") ;
	gets(fName) ; 
	printf("Enter last name: ") ; 
	gets(lName) ;
	strcat(fName , " ") ; 
	strcat(fullName , strcat(fName ,  lName)) ;
	printf("Full Name: ") ; 
	puts(fullName) ;  
	printf("Backward Name: %s" , strrev(fullName)) ; 
	return 0 ; 
} */

// task 3 //
/*int main() {
	char s1[30] , s2[30] ; 
	printf("Enter string 1: ") ; 
	gets(s1) ; 
	printf("Enter string 2 :") ; 
	gets(s2) ;
	int x = strcmp(s1 , s2) ;  
	if(x < 0) {
		printf("string 2 is less than string 1") ; 
	} else if(x > 0){
		printf("String 1 is less than string 2") ; 
	} else if(x==0){
	   printf("Both strings are equal") ; 
	}
	return 0 ; 
} */
// TASK 2 //
/*int main() {
		int length ;  
		printf("Enter the length of courses") ; 
		scanf("%d" , &length) ; 
		char courses_Name[length + 1][50] ; 
		int characters[52][2] ; 
		for(int i = 0 ; i < 52 ; i++) {
			characters[i][0] = 65 + i ; 
			characters[i][1] = 0 ; 
		}
		
		for(int i = 0 ; i <= length  ; i++) {
			if(i == 0 ) {
				printf("Enter your name : ") ; 
			} else {
				printf("Enter course %d: " , i) ; 
			}
			fflush(stdin) ; 
			gets(courses_Name[i]) ; 
			
		}
	
		int string_length ; 
		for(int i = 0 ; i <= length ; i++) {
			string_length = strlen(courses_Name[i]) ;
		
			for(int j= 0 ; j < string_length ; j++) {
				for(int k = 0 ; k < 52 ; k++) {
				
					if(characters[k][0] == courses_Name[i][j]) {
					characters[k][1]++ ; 
					}
				}
			} 
		}
		 int max; 
		char max_CharArr[52] = {0} ; 
		for(int i = 0 , j = 0 ; i < 52 ; i++) {
			if(max < characters[i][1]) {
			  for(int k = 0 ; k < 52 ; k++) {
			  	max_CharArr[k] = 0 ; 
			  }
			  j = 0 ; 
			  max = characters[i][1] ;
			  max_CharArr[j] = characters[i][0] ;    
			  
	} else if(max ==  characters[i][1]) {
		j++ ; 
		max_CharArr[j] = characters[i][0] ;    

	}
}
printf("Maximum times character Occured: %d\n" , max) ; 
printf("Character: ") ; 

for(int i = 0 ; i < 52 ; i++) {
	if(max_CharArr[i] != 0) {
		printf("%c,  " , max_CharArr[i]);
	}
}

return 0 ; 
} */
// task 4 //
/*int position (int marks) {
	int exp; 
	if(marks < 50) 
	{
		printf("You are not selected for any position") ; 
	} else if(marks >=50 && marks<60) {
			printf("You are selected for the position of trainee engineer") ; 
	} else if(marks >=60 && marks < 70) {
		printf("Please enter your experience: ") ; 
		scanf("%d" , &exp) ; 
		if(exp >=1) {
			printf("You are selected for the position of assistant developer") ; 
		} else{
			printf("You are selected for the position of trainee engineer") ; 
		}
	} else if(marks >=70) {
		printf("Please enter your experience: ") ; 
		scanf("%d" , &exp) ; 
		if(exp >=2) {
			printf("You are selected for the position associate developer") ; 
		} else{
			printf("You are selected for the position of assistant developer") ; 
		}
	}
	return 0 ;
}
int main() {
	int marks ; 
	printf("Enter your test marks: ") ; 
	scanf("%d" , &marks) ; 
	position(marks) ; 
	return 0 ; 
} */
// task 5 //
/*int countFrequency(int arr[] , int length) {
	int counts[10][2] = {{1 , 0} , {2 ,0} , {3, 0} , {4 , 0} , {5 , 0} ,{6 , 0},{7 , 0} , {8 , 0} , {9 , 0} , {10 , 0}}; 
	for(int i = 0 ; i < length ; i++) {
		for(int j = 0 ; j < 10 ; j++) {
			if(counts[j][0] == arr[i]) {
		
			counts[j][1]++ ; 
		}
		}
	
	}
	printf("\nFrequency of all elements");
	for(int i = 0  ; i < 10 ; i++) {
		if(counts[i][1] != 0) {
			printf("\n%d occurs %d times in array" , counts[i][0] , counts[i][1]) ; 
		}
	}
	return 0;
}
int main() {
	printf("Input the number of elements to be stored in the array: ") ; 
	int length ; 
	scanf("%d" , &length) ; 
	int arr[length] ; 
	printf("Inputed %d elements in the array: \n" , length) ; 
	for(int i = 0 ;i < length ; i++) {
		arr[i] = (rand() % 10) + 1 ; 
		
	}
	for(int i = 0 ; i < length ; i++) {
		printf("%d , " , arr[i]) ; 
	}
	countFrequency(arr , length) ; 
	return 0; 
} */
// Task 6 //
/*int volumeCalu(float a , float h) {
	float volume = (a * a ) * (1.0 /3.0) * h ; 
	printf("Volume: %.2f" , volume ); 
	return 0 ; 
}
int getData(float a , float h ) {
	printf("Enter height: ") ; 
	scanf("%f", &h) ; 
	printf("Enter area: ") ; 
	scanf("%f" , &a) ; 
	volumeCalu(a , h) ; 
	return 0 ;
}


int main() {
	float a = 0 , h = 0 ;
	getData(a , h) ; 
	return 0 ; 
} */

