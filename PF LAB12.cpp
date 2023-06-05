#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// Practice //
/*int main() {
	int num ; 
	printf("Enter a num: ") ; 
	scanf("%d" , &num) ; 
	FILE *filePtr ; 
	filePtr = fopen("myfile.txt" , "w") ; 
	if(filePtr == NULL) {
		printf("File doesn't exist: ") ; 
	    exit(1) ; 
	}
	fprintf(filePtr , "%d" , num) ; 
	fclose(filePtr) ; 
	return 0 ; 
} */

// Practice 2 //
/*int main() {
	FILE *filePtr ; 
    filePtr = fopen("number.txt" , "r")  ;
    if(filePtr == NULL) {
    	printf("File does not exist") ; 
    	exit(1) ; 
	}
	int num ; 
	fscanf(filePtr , "%d" , &num) ; 
	printf("The content in your file is : %d" , num) ; 
	return 0 ;
} */
// Question 1 //
int main() {
	FILE *filePtr ; 
	char text[50] , text1[50] ; 
	filePtr = fopen("file1.txt" , "w") ; 
	fprintf( filePtr , "Hello") ; 
	fclose(filePtr) ; 
	filePtr = fopen("file2.txt" , "w") ;
	fprintf(filePtr , "World") ;
	fclose(filePtr) ; 
	filePtr = fopen("file1.txt" , "r") ;
	fgets(text ,sizeof text  , filePtr ) ; 
	fclose(filePtr) ;
	filePtr = fopen("file2.txt" , "r") ;
	fgets(text1 , sizeof text1 , filePtr) ;
	fclose(filePtr) ; 
	strcat(text  , text1) ;
	filePtr = fopen("file3.txt" , "w") ; 
	fprintf(filePtr , "%s" , text) ; 
	fclose(filePtr) ;	
	printf("3rd File Text: %s" , text) ;  
	return 0 ;  
} 
// practice 3 //
/*int main() {
	int num ; 
	FILE *filePtr ; 
	filePtr = fopen("number.txt" , "r") ; 
	while(!feof(filePtr)) {
		fscanf(filePtr , "%d" , &num) ; 
		printf("%d" , num) ; 
	} 
	fclose(filePtr) ; 
	return 0 ; 
 } */
 // Question 2 //
 /*int main() {
 	int charCount[26] = {0} , totalCount = 0 , counter ;
	char fileName[50] , line[50] ;  
 	printf("Enter the file name which content you want to see: ") ; 
 	gets(fileName) ; 
 	FILE *filePtr = fopen(fileName , "r") ; 
 	printf("The content of the file is: \n") ; 
 	while(fgets(line , sizeof line , filePtr) != NULL) {
 	        printf("%s" , line) ;
	}
	fclose(filePtr) ;
	char ch = fgetc(filePtr) ; 
	while(ch!=EOF) {
		printf("%c" , ch) ; 
		if(ch != ' ' || ch == '\n') {
			totalCount++ ; 
		}
		if(ch == 65 + counter || ch == 97+counter) {
			charCount[counter]++ ; 
		}
		ch = fgetc(filePtr) ;
		counter++ ;  
	} 
	fclose(filePtr) ;
	filePtr = fopen("charOccur.txt" , "a") ;  
	for(int i = 0; i < 26 ; i++ ) {
		fprintf(filePtr , "%c: %d" , 65+i , charCount[i]) ; 
	}
	fprintf(filePtr , "Total Characters Count: %d" , totalCount) ; 
	fclose(filePtr) ; 
	return 0 ;   
 } */
 // Question 3 //
 /*typedef struct {
 	char id[10] , name[20] , sex[10] ; 
 	float quiz1Score , quiz2Score , midScore , finalScore , totalScore = quiz1Score + quiz2Score + midScore + finalScore; 
 }studentDetails;
 int main() {
 	studentDetails std[2] ; 
 	for(int i = 0 ; i < 2 ; i++) {
 		printf("Enter student id: ") ; 
 		fflush(stdin) ; 
 		gets(std[i].id) ; 
	    printf("Enter student name: ") ; 
 		fflush(stdin) ;
		gets(std[i].name) ; 
	    printf("Enter student sex: ") ; 
 		fflush(stdin) ;
		gets(std[i].sex) ; 
	    printf("Enter student quiz 1 score: ") ; 
 		scanf("%f" , &(std[i].quiz1Score)) ;
		printf("Enter student quiz 2 score: ") ; 
 		scanf("%f" , &(std[i].quiz2Score)) ;
		printf("Enter student mid score: ") ; 
 		scanf("%f" , &(std[i].midScore)) ;
		printf("Enter student final score: ") ; 
 		scanf("%f" , &(std[i].finalScore)) ;
	 }
	 FILE *filePtr = fopen("students.txt" , "a") ; 
	for(int i = 0 ; i < 2 ; i++) {
		fprintf(filePtr , "Student %d\n" , i + 1) ; 
	 	fprintf(filePtr ,"student id: %s\n" , std[i].id) ; 
	    fprintf(filePtr ,"student name: %s\n"  , std[i].name) ; 
        fprintf(filePtr ,"student sex: %s\n" , std[i].sex) ; 
        fprintf(filePtr ,"student quiz 1 score: %f\n" , std[i].quiz1Score) ; 
      	fprintf(filePtr ,"student quiz 2 score: %f\n" , std[i].quiz2Score) ; 
        fprintf(filePtr ,"student mid score: %f\n" , std[i].midScore) ; 
        fprintf(filePtr ,"student final score: %f\n" , std[i].finalScore) ;
        fprintf(filePtr ,"student total score: %f\n" , std[i].totalScore) ;
	} 
	fclose(filePtr) ; 
 } */
 // Question 4 //
 /*int main() */
