#include <stdio.h>
#include <stdlib.h>
/*int main(){
	int i , N;
	printf("Please enter the number of persons for which you want to run the process: "/) ; 
	scanf("%d" , &N) ; 
	for(i = 0 ; i <N ; i++) {
		
	}
} */
// Question 1 //
/*int main() {
	int items , i   , tons; 
	float miniBus = 0 , truck = 0 , train = 0  , sum ;
	printf("Enter how many cargos you want to transport: ") ; 
	scanf("%d" , &items) ; 
	for(i = 1 ; i <= items ; i++) {
		printf("How many tons in %d cargo: " , i) ; 
		scanf("%d" , &tons) ; 
		if(tons <=3) {
			
             miniBus = miniBus + tons ; 			
		} else if(tons > 3 && tons <=11) {
			truck = truck + tons ; 
		} else if(tons > 11){
			train = train + tons ; 
		}
	}
	sum = train + miniBus + truck ; 
	printf("Percentage of the cargo by mini bus %.2f%c\n" , (miniBus/sum  * 100) , 37) ; 
	printf("Percentage of the cargo by truck %.2f%c\n" , (truck/sum  * 100) , 37) ; 
	printf("Percentage of the cargo by train %.2f%c\n" , (train/sum  * 100) , 37) ; 
	printf("Average price per ton of carried cargo %.2f\n" , (miniBus * 200 + truck * 175 + train * 120) / sum ) ; 
	return 0 ; 
	
} */
// Question 2 //
/*int main() {
	int docs = 7 ; 
	int patients ; 
	int i; 
    int period ;
    int treat = 0, untreat = 0 ; 
	printf("For how many days you want to run the program: ") ;  
	scanf("%d" , &period) ; 	
	for(i = 1 ; i <= period ; i++ ) {
		  printf("Enter patients for Day %d: " , i) ; 
		  scanf("%d" , &patients) ; 
		  if(i %3 == 0 && untreat > treat) {
		  	docs ++ ; 
		  } 
		  if(patients > docs) {
		  	treat += docs ; 
		  	untreat += patients - docs ; 
		  } else {
		  	treat += patients ; 
		  } 
		  
	}
	printf("Treated Patients: %d\n" , treat) ;
	printf("Untreated Patients: %d\n" , untreat) ;  
	return 0 ; 
} */

// Question 7 //

/*int main() {
	int rs1 , paisa1 ; 
	int rs2 , paisa2;
	int sumRs , sumPaisa ;
	char ans; 
	do{
	
	printf("Enter 1st amount : \n") ; 
	scanf("%d" ,&rs1 ) ;
	printf(" - ") ; 
	scanf("%d" , &paisa1) ; 
	printf("Enter 2nd amount : \n") ;  
	scanf("%d" , &rs2) ;
	printf(" - ") ; 
	scanf("%d" , &paisa2) ;   
	sumRs = rs1 + rs2 + (paisa1 > 100 ? paisa1 / 100 : 0) + (paisa2 > 100 ? paisa2 / 100 : 0);
	sumPaisa = (paisa1 > 100 ? paisa1 % 100 : paisa1) + (paisa2 > 100 ? paisa2 % 100: paisa2) ; 
	printf("sum = %d : %d\n" , sumRs , sumPaisa) ;
	fflush(stdin) ; 
	printf("Do you wish to continue : (Y/y OR N/n)") ;  
    scanf("%c" , &ans) ; 
} while (ans != 'N' && ans != 'n') ; 
return 0 ; 
} */
// Question 8 // 
/*int main() {
	int numToGuess ; 
	int guess ; 
	int totalGuess = 0, highGuess = 0 , lowGuess = 0 ;
	int chances = 5; 
	numToGuess = rand() % 10 + 1 ; 
	printf("Entered your guess number between 1-10: \n") ; 
	printf("(You will have %d chances)\n" , chances) ; 
	scanf("%d" , &guess) ;
	while((guess != numToGuess) && chances != 0) {
		printf("Your guess is wrong!\n") ; 
		if(guess > numToGuess){
			printf("Your guess is too high!\n") ; 
			highGuess++ ;
			
		} else if(guess < numToGuess){
			printf("Your guess is too low!\n") ; 
			lowGuess++ ; 
		} 
		printf("You have %d chances left \n" , --chances) ; 
		printf("Entered another guess: \n") ;
		scanf("%d" , &guess) ; 
	}
	totalGuess = highGuess + lowGuess ; 
	printf("Your guess is right: \n") ; 
	printf("Total Guesses : %d\n" , totalGuess) ; 
	printf("High Guesses : %d\n" , highGuess) ; 
	printf("Low Guesses : %d\n" , lowGuess) ; 

	
	
	return 0 ; 
} */
// Question 6 //
/*int main() {
	int amount = 200000 ; 
	int rtn = 100000 ; 
	int years = 5 ; 
	int i  ;
	for(i = 1 ; i <=5 ; i++ ) {
		if(i %2 == 0) {
			rtn = rtn - 25563 ; 
		} else {
			rtn = rtn - 25563 - 12580 ; 
		}
	}
	if(rtn >=0) {
		printf("money will be enough for 5 years!") ; 
	} else {
		printf("money will not be enough") ; 
	}
	return 0 ;
} */
// Question 4 //
/*int main() {
	int N ;
	int i ;  
	int num ; 
	printf("Enter the range of numbers: ") ; 
	scanf("%d" , &N) ; 
	
	float countp1, countp2 , countp3 , countp4 , countp5 ; 
	float p1 , p2 , p3 , p4 , p5 ; 
	for(i = 1 ; i <= N; i++) {
		printf("Enter a number: ") ; 
		scanf("%d" , &num) ;
		if(num < 200) {
			countp1 = countp1 + 1 ; 
		} else if(num >=200 && num < 400) {
			countp2 = countp2 + 1 ; 
		} else if(num >=400 && num < 600) {
			countp3 = countp3 + 1 ; 
		} else if(num >= 600 && num < 800) {
			countp4 = countp4 + 1 ; 
			
		} else if(num>=800 && num <=1000) {
			countp5 = countp5 + 1 ; 
		} else {
			printf("Invalid Input!\n") ; 
			--i ; 
		}
	}
	p1 = (countp1 / N ) * 100 ; 
	p2 = (countp2 / N ) * 100 ;
	p3 = (countp3 / N ) * 100  ; 
	p4 = (countp4 / N ) * 100  ; 
	p5 = (countp5 / N ) * 100 ;
	printf("Under 200: %.2f%c\n" , p1 , 37) ; 
	printf("200 to 399: %.2f%c\n" , p2 , 37) ; 
	printf("400 to 599: %.2f%c\n" , p3, 37) ; 
	printf("600 to 799: %.2f%c\n" , p4, 37) ; 
	printf("800 Upwards: %.2f%c\n" , p5 , 37) ; 
	return 0 ; 
} */
// Question 5 //
/*int main() {
	int num ; 
	int i  , j ; 
	long long int fact = 1; 
	for(i = 0 ; i < 1 ; i++) {
		printf("Enter a number for calculating factorial: ") ; 
		scanf("%d" , &num) ; 
	    if(num < 0) {
	    	printf("Number should be a non-negative integer! \n") ; 
	    	--i ; 
		} else if(num == 0) {
			printf("Factorial of 0! = 1") ; 
		} else {
			for( j = 1 ; j <= num ; j++) {
				fact = fact * j ; 
			}
			printf("Factorial of %d = %d" , num , fact) ; 
		}
	}
	return 0;
} */
// Question 9 //
int main() {
	char ans ; 
	int voteA = 0 , voteB = 0 , districtsA = 0 , districtsB = 0 , draw = 0    ; 
	float  totalA = 0 , totalB = 0 , total = 0  , totalEach; 
	int districts = 0 ; 
	do {
	   districts ++ ; 
	   printf("Enter the votes for candidate A in district %d: " , districts) ; 
	   scanf("%d" , &voteA) ; 
	   printf("Enter the votes for candidate B in district %d: " , districts) ; 
	   scanf("%d" , &voteB) ; 
	   totalEach = voteA + voteB ; 
	   printf("Candidate A got %d votes in district %d\n" , voteA , districts) ; 
	   printf("Candidate B got %d votes in district %d\n" , voteB,  districts) ; 
	   printf("Total Votes in district %d: %d\n" , districts , (voteA + voteB)) ; 
	   printf("Candidate A got %.2f%c votes in district %d\n" , (voteA / (totalEach)) * 100, 37,  districts) ; 
	   printf("Candidate B got %.2f%c votes in district %d\n" , (voteB / (totalEach)) * 100, 37,  districts) ; 
	   totalA = totalA + voteA ; 
	   totalB = totalB + voteB ; 
	   if(voteA > voteB) {
	   	districtsA++ ; 
	   	
	   } else if(voteB > voteA){
	   	districtsB++ ; 
	   } else {
	   	draw++ ; 
	   }
	   printf("Are there more districts to report: (y/Y OR n/N) ") ; 
	   fflush(stdin) ; 
	   scanf("%c" , &ans) ; 
	} while(ans !='n' && ans!= 'N') ;
	total = totalA + totalB ;
	printf("%d%d" , totalA , totalB) ;   
	printf("Candidate A got %.0f votes out of %.0f votes\n" , totalA, total) ; 
	printf("Candidate B got %.0f votes out of %.0f votes\n" , totalB , total) ; 
	printf("Candidate A got %.2f%c votes\n" , ((totalA / total) * 100) , 37) ; 
	printf("Candidate B got %.2f%c votes\n" , ((totalB / total) * 100) , 37) ; 
	printf("Candidate A won in %d districts\n" , districtsA) ; 
	printf("Candidate B won in %d districts\n" , districtsB) ; 
	printf("Both tied/draw in %d districts", draw) ;  
	return 0 ; 
} 
// Question 3 //
/*int main() {
	int age = 0  , toys = 0 , totalRs = 0 , i; 
	int amountInc = 0 ; 
	printf("Enter Sara's Age: ") ;
    scanf("%d" , &age) ; 
	for(i = 1 ; i <= age ; i++) {
		if(i %2!=0 ) {
			toys = toys + 1 ; 
		} else {
			if(i == 2) {
				totalRs = (totalRs + 100) - 30 ; 
			} else {
				amountInc = amountInc + 200 ; 
				totalRs = (totalRs + 100 + amountInc) - 30 ; 
			}
		}
	}
	printf("%d" , toys) ; 
	totalRs = totalRs + (toys * 130) ; 
	printf("Sara's Saved Money: %dRs\n" , totalRs) ; 
	if(totalRs >=10000) {
		printf("It is enough to buy a washing machine!\n") ; 
	}
	 else {
	 	printf("It is not enough to buy a washing machine!\n") ; 
	 }
	 return 0 ; 
} */
