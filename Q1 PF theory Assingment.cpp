#include <stdio.h>
#include <string.h>
#include <Math.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
int main(){
	 srand(time(NULL));
char word[7];
char randAlphabets[5][6];
char id[8];
printf("Enter your NU id: ");
gets(id);
int i,j;
char randChar;
for(i  = 0 , j = 4  ; i < 4 ; i++ , j++) {
		randAlphabets[4][i] = id[j] ; 
	}
for(i = 0 ; i < 4 ;i ++ ) {
		 for(j = 0 ; j < 6  ; j++){
		 	randChar = rand()%(90-65+1)+65; 
		 	randAlphabets[i][j] = randChar ; 
		 }
	}
	randAlphabets[4][4] = 'A' + (rand() % 26) ; 
	randAlphabets[4][5] = 'A' + (rand() % 26) ;  
	for(i=0;i<5;i++){
	for(j=0;j<6;j++){
		printf("%c\t",randAlphabets[i][j]);
	}
	printf("\n");	
}
	char end[] = "END" ;
	char searchWord[30] ;
	int ans   ,score = 0 ;  
	while(strcmp(searchWord , end) != 0) {
		printf("\nEnter word: "); 
		gets(searchWord) ; 
		for(int i = 0 ; i < 5 ; i++) {
			for(int j = 0 ; j < 6 ; j++) {
				ans = 0 ; 
				for(int k = j , l = 0 ;l < strlen(searchWord) ; k++ , l++) {
					if(randAlphabets[i][k] == searchWord[l]) {
						ans++ ; 
					}
				}
				if(ans == strlen(searchWord) ) {
					break ; 
				}
			}
			if(ans == strlen(searchWord)) {
				break ; 
		   } 
		}
		if(ans != strlen(searchWord)) {
				for(int i = 0 ; i < 6 ; i++) {
			for(int j = 0 ; j < 5 ; j++) {
				ans = 0 ; 
				for(int k = j , l = 0 ;l < strlen(searchWord) ; k++ , l++) {
					if(randAlphabets[k][i] == searchWord[l]) {
						ans++ ; 
					}
				}
				if(ans == strlen(searchWord) ) {
					break ; 
				}
			}
			if(ans == strlen(searchWord)) {
				break ; 
			}
		}
		}
		if(ans == strlen(searchWord)) {
			if(strcmp(searchWord , end) !=0) {
			score++ ; 
		}	
		} 
		else if(ans != strlen(searchWord)){
			if(strcmp(searchWord , end) !=0) {
			 	score-- ; 
		}	
		}
		if(strcmp(searchWord , end) !=0) {
			 printf("\nScore : %d" , score) ; 
		}
	  
	}
	printf("Your Score: %d" , score) ; 
return 0 ; 
} 

	

