#include <stdio.h>
#include <string.h>
struct employee {
	int emp_id ; 
	char emp_name[20] ; 
	
};
typedef struct{
	char name[30] ; 
	int marks ; 
} students;
/*float product(float a , float b , float c , float d , float e) {
	float p = a * b * c * d * e ; 
	float w = (a / 10) 
}
int main() {
	
} */
/*int main() {
	struct employee emp1 ; 
	printf("Enter employee id") ; 
	scanf("%d" , &emp1.emp_id) ;
    printf("Enter employee name: ") ;
    fflush(stdin) ; 
    gets(emp1.emp_name) ; 
    printf("The id is %d" , emp1.emp_id) ; 
    printf("The name is %s" , emp1.emp_name) ; 
    return 0 ; 
} */
/*int main() {
	int i = 0 ; 
	students s1[3] ; 
	for(i ; i < 3 ; i++) {
		printf("Enter Name: ") ; 
		fflush(stdin) ; 
		gets(s1[i].name) ; 
		printf("Enter marks: ") ; 
		scanf("%d" , &s1[i].marks) ; 
	}
	for(i =0 ; i < 3 ; i++) {
		printf("Name: %s\n" ,s1[i].name ) ;
		printf("Marks: %d\n" ,s1[i].marks ) ;

}
return 0 ; 
} */
// Question 1 //
/*typedef struct{
	char itemName[50] ; 
	int price ; 
	int quantity ;  
	int amount = quantity * price ; 
}Details;
int main() {
	printf("Enter how many item are there? ") ; 
		int length ;
	scanf("%d" , &length) ; 
	Details itemDetails[length] ;
	int i = 0 ;
	float total ;  
	for(i ; i < length ; i++) {
		printf("\nItem %d" , i + 1) ;
		printf("\nEnter Item Name: ") ; 
		fflush(stdin) ; 
		gets(itemDetails[i].itemName) ; 
		printf("Enter per item price: ") ; 
		scanf("%d" , &itemDetails[i].price) ; 
		printf("Enter item quantity: ") ; 
		scanf("%d" , &itemDetails[i].quantity) ;
	    total = total + (itemDetails[i].quantity * itemDetails[i].price) ; 
	}
	printf("Enter how many friends: ") ; 
	int noOfFriends ; 
	scanf("%d" , &noOfFriends) ;
	printf("Total: %.0f" , total) ; 
	printf("\nShare for each friend: %.0f" , total / noOfFriends) ; 
	return 0 ;  
} */
// miss example //
/*typedef struct{
	int x ; 
	int y ; 
}Point;
void sum(Point P1 , Point P2) {
	int x = P1.x + P2.x ; 
	int y = P1.y + P2.y ;
	printf("X_coordinate: %d" , x) ;  
	printf("Y_coordinate: %d" , y) ;  

}
int main() {
	  Point P1 , P2 ; 
	  printf("Enter coordinates of P1: ") ;
	  scanf("%d %d" , &P1.x , &P1.y) ;  
	   printf("Enter coordinates of P2: ") ;
	  scanf("%d %d" , &P2.x , &P2.y) ;  
      sum(P1 , P2) ; 
} */
// Question 2 //
/*typedef struct{
	int feet ; 
	int inches ; 
}distance;
int addDistance(distance d1 , distance d2) {
	int feet = d1.feet + d2.feet ; 
	int inches = d1.inches + d2.inches ; 
    feet = feet + inches / 12 ; 
    inches = inches % 12 ; 
	printf("Total Distance\nfeet: %d" , feet) ; 
	printf("\ninches: %d" , inches) ;
	return 0 ; 
}
int main() {
	distance d1, d2 ; 
	printf("Enter feet for d1: ") ;
	scanf("%d" , &d1.feet) ; 
	printf("Enter inches for d1: ") ;
	scanf("%d" , &d1.inches) ; 
	printf("Enter feet for d2: ") ;
	scanf("%d" , &d2.feet) ; 
	printf("Enter inches for d1: ") ;
	scanf("%d" , &d2.inches) ; 
	addDistance(d1 , d2) ;
	return 0 ; 
} */
// miss example //
/*struct Address{
	int zip ; 
	int post_No ; 
};
struct Employee {
	char emp_name[30] ;
	struct Address adr ;  
};
int main() {
	struct Employee emp ; 
	printf("Enter employee name: ") ; 
	gets(emp.emp_name); 
	printf("Employee Address: ") ; 
	scanf("%d" , &emp.adr.zip) ; 
	scanf("%d" , &emp.adr.post_No) ; 
	printf("Employee Name : %s" , emp.emp_name) ; 
	printf("\nEmployee Address : %d %d " , emp.adr.zip , emp.adr.post_No) ; 
} */
// Question 3 //
/*typedef struct {
	int price ; 
	int book_No ; 
	char book_Author[50] ; 
	char book_Title[50] ;
	char book_Publisher[50] ;  
}bookDetails; 
void booksOfAuthor(int noOfBooks , bookDetails books[] , char book_Author[]) {
	int i ; 
	for(i = 0 ; i < noOfBooks ; i++) {
		if(strcmp(books[i].book_Author , book_Author) == 0) {
			printf("\nBook Title : %s" , books[i].book_Title) ; 
			printf("\nBook No : %d" , books[i].book_No) ; 
		    printf("\nBook Author : %s" , books[i].book_Author) ;
			printf("\nBook Publisher : %s" , books[i].book_Publisher) ;
			printf("\nBook Price : %d" , books[i].price) ;
		}
	}
}
void booksOfPublisher(int noOfBooks , bookDetails books[] , char book_Publisher[]) {
	int i ; 
	for(i = 0 ; i < noOfBooks ; i++) {
		if(strcmp(books[i].book_Publisher , book_Publisher) == 0) {
			printf("\nBook Title : %s" , books[i].book_Title) ; 
			printf("\nBook No : %d" , books[i].book_No) ; 
		    printf("\nBook Author : %s" , books[i].book_Author) ;
			printf("\nBook Publisher : %s" , books[i].book_Publisher) ;
			printf("\nBook Price : %d" , books[i].price) ;
		}
	}
}
void booksOfPrice(int noOfBooks , bookDetails books[]) {
	int i ; 
	for(i = 0 ; i < noOfBooks ; i++) {
		if(books[i].price >= 500) {
			printf("\nBook Title : %s" , books[i].book_Title) ; 
			printf("\nBook No : %d" , books[i].book_No) ; 
		    printf("\nBook Author : %s" , books[i].book_Author) ;
			printf("\nBook Publisher : %s" , books[i].book_Publisher) ;
			printf("\nBook Price : %d" , books[i].price) ;
		}
	}
}

int main() {
	printf("Enter how manybooks are there?") ; 
	int noOfBooks ; 
	scanf("%d" , &noOfBooks) ; 
	bookDetails books[noOfBooks] ; 
	int i ; 
	for(i = 0 ; i < noOfBooks ; i++) {
		printf("Enter book %d details: " , i + 1) ;
		printf("\nBook Title: ") ;
		fflush(stdin) ;   
		gets(books[i].book_Title) ; 
		printf("Book No: ") ; 
		scanf("%d" , &books[i].book_No) ; 
		printf("Book Author: ") ;
		fflush(stdin) ;    
		gets(books[i].book_Author) ;
		printf("Book Publisher: ") ;
		fflush(stdin) ;   
		gets(books[i].book_Publisher) ; 
		printf("Book Price: ") ;
		scanf("%d" , &books[i].price) ;  
	}
	char searchByAuthor[50] , searchByPublisher[50]; 
	printf("Enter the author of which you to print books : \n-----------------------------\n") ;
	fflush(stdin) ;    
	gets(searchByAuthor) ; 
	booksOfAuthor( noOfBooks, books , searchByAuthor) ; 
	printf("\nEnter the publisher of which you to print books : \n-----------------------------\n") ;
	fflush(stdin) ;    
	gets(searchByPublisher) ; 
	booksOfPublisher( noOfBooks, books , searchByPublisher) ; 
	printf("\nBooks which has cost 500 and above: \n-----------------------------\n") ; 
	booksOfPrice(noOfBooks , books) ; 
	printf("\nAll Books : \n-----------------------------\n") ; 
		for(i = 0 ; i < noOfBooks ; i++) {
			printf("\nBook Title : %s" , books[i].book_Title) ; 
			printf("\nBook No : %d" , books[i].book_No) ; 
		    printf("\nBook Author : %s" , books[i].book_Author) ;
			printf("\nBook Publisher : %s" , books[i].book_Publisher) ;
			printf("\nBook Price : %d" , books[i].price) ;
	}
	return 0 ; 
} */
// Question 4 //
/*typedef struct{
	int eno ; 
	char ename[50] ;
	int salary ;   
} eDetails; 
int main() {
	int n ; 
	printf("For how many employees you want to enter data: ") ; 
	scanf("%d" , &n) ; 
	eDetails employees[n] ;
	for(int i = 0 ; i < n ; i++) {
		printf("Employee %d Data: " , i + 1) ; 
		printf("\nEnter employee name: ") ;
		fflush(stdin) ;  
		gets(employees[i].ename) ; 
		printf("Enter employee no: ") ; 
	    scanf("%d" , &employees[i].eno) ;
	    printf("Enter employee salary: ") ; 
	    scanf("%d" , &employees[i].salary) ; 
	    
	} 
	int highSalary = 0 ; 
	for(int i = 0 ; i < n ; i++) {
	  highSalary = employees[i].salary > highSalary ? employees[i].salary : highSalary ;   
	}
	printf("Employee which has highest Salary: \n-----------------------------\n") ; 
	for(int i = 0 ; i < n ; i++) {
	    if(highSalary == employees[i].salary) {
	    	printf("Employee name: %s" , employees[i].ename) ;
			printf("\nEmployee No: %d" , employees[i].eno) ; 
		    printf("\nEmployee Salary: %d" , employees[i].salary) ; 
		}
	}
   return 0 ;
} */
// Question 7 //
/*typedef struct {
      int day, month , year ;  
}dateOfBirth;
typedef struct {
	char name[30] ; 
	dateOfBirth db ; 
}personData;
int main() {
	printf("For how many persons you want to get data: ") ; 
	int length ; 
	scanf("%d" , &length) ;
	personData persons[length] ; 
	int i  = 0 ; 
	for(i ; i < length ; i++) {
		printf("Enter person %d name: " , i + 1) ;
		fflush(stdin) ; 
		gets(persons[i].name) ;  
	    printf("Enter birth month: ") ; 
	    scanf("%d" , &persons[i].db.month) ; 
	    printf("Enter birth year: ") ; 
	    scanf("%d" , &persons[i].db.year) ; 
	    printf("Enter birth day: ") ; 
	    scanf("%d" , &persons[i].db.day) ; 
	} 
	i = 0 ; 
		for(i ; i < length ; i++) {
		printf("Person %d: \n" , i + 1) ;  
		puts(persons[i].name) ; 
	    printf("Birth month: %d\n" , persons[i].db.month) ; 
	    printf("Birth year: %d\n", persons[i].db.year) ;  
	    printf("Birth day: %d\n" , persons[i].db.day) ; 
	} 
	return 0 ; } */

// Question 5 //

/*typedef struct{
	char name[50] ; 
	int accNo ; 
	int balance ; 
}cusDetails;
int length ; 
void balLess( cusDetails customers[]) {
	for(int i = 0 ; i < length ; i++) {
		if(customers[i].balance < 200  ) {
		printf("\nCustomer Name : %s" , customers[i].name) ; 
			printf("\nCustomer Account No : %d" , customers[i].accNo) ; 
		    printf("\nCustomer Balance : %d" , customers[i].balance) ;
		}
	}
	
}
void balAdd(cusDetails customers[]) {
		printf("\nCustomers which have balance more than 1000$\n----------------------------------------------------------\n") ; 
	for(int i = 0 ; i < length ; i++) {
		if(customers[i].balance > 1000  ) {
		printf("\nCustomer Name : %s" , customers[i].name) ; 
			printf("\nCustomer Account No : %d" , customers[i].accNo) ; 
		    printf("\nCustomer Increased Balance : %d" , customers[i].balance + 100) ;
		}
	}
} ; 
int main() {
   	printf("For how many customers you want to store data (more than 10): ") ; 
    while( length <= 10) {
    	scanf("%d" , &length) ; 
       printf("\nPlease enter customers greater than 10: ") ; 	
	}
   	cusDetails customers[length] ; 
   	for(int i = 0 ; i < length ; i++) {
   		printf("\nCustomer %d Details: " , i + 1) ; 
   		printf("\nEnter customer name : ") ; 
		fflush(stdin) ; 
   		gets(customers[i].name) ; 
   		printf("Enter Customer Account No: ") ; 
   		scanf("%d" , &customers[i].accNo) ; 
   		printf("Enter customer balance: ") ; 
   		scanf("%d" , &customers[i].balance) ; 
	   }
	  printf("Customers which have balance less than 200: \n-------------------------------------\n") ; 
	  balLess(customers) ; 
	  balAdd(customers ) ;  
      return 0 ; 	   
}  */
// Question 6 //
typedef struct{
	int areaCode ; 
	int exchange ; 
	int no ; 
}phone;
int main() {
	phone p1 = {212 , 767 , 8900} ; 
	phone p2 ;
	printf("Enter Area Code: ") ; 
	scanf("%d" , &p2.areaCode) ; 
	printf("Enter Exchange : ") ; 
	scanf("%d" , &p2.exchange) ; 
	printf("Enter number: ") ; 
	scanf("%d" , &p2.no) ; 
	printf("My Number is : (%d) %d-%d" , p1.areaCode , p1.exchange , p1.no) ; 
	printf("\nYour Number is : (%d) %d-%d" , p2.areaCode , p2.exchange , p2.no) ;
	return 0 ;   
	 
} 
// Question 8 //
/*typedef struct {
	char sch_Name[50] ; 
	int sch_id ; 
}school;
typedef struct{
	int stu_id ; 
	char stu_name[50] ; 
	float marks ; 
	float average ; 
	school schl ; 
}student;
void getData(int records , student std[]) {
	for(int i = 0 ; i < records ; i++) {
		printf("Student %d" , i + 1) ; 
		printf("\nEnter Student id: ") ; 
		scanf("%d" , &std[i].stu_id); 
		printf("Enter Student Name: ") ;
		fflush(stdin) ; 
		gets(std[i].stu_name) ;  
		printf("Enter Student Marks: ") ;
		scanf("%f" , &std[i].marks); 
		printf("Enter Student Average: ") ;
		scanf("%f" , &std[i].average); 
		printf("Enter School Name: ") ;
		fflush(stdin) ; 
		gets(std[i].schl.sch_Name) ;  
		printf("Enter School Id: ") ;
		scanf("%d" , &std[i].schl.sch_id); 
	} 
}
void display(int records , student inputStudents[]) {
	printf("All Students Record: \n----------------------------") ; 
	for(int i = 0 ; i < records ; i++) {
	printf("\nStudent %d" , i + 1) ; 	
	printf("\nStudent id: %d" , inputStudents[i].stu_id) ; 
	printf("\nStudent Name: %s" , inputStudents[i].stu_name) ;
	printf("\nStudent Marks: %.2f"  , inputStudents[i].marks) ;
	printf("\nStudent Average: %.2f" , inputStudents[i].average) ;
	printf("\nSchool Name: %s" , inputStudents[i].schl.sch_Name) ;
	printf("\nSchool Id: %d" , inputStudents[i].schl.sch_id) ;
	}
}
int main() {
    	printf("How many records you want to enter: ")  ; 
    	int records ; 
    	scanf("%d" , &records) ;
		student std[records] ;  
    	getData(records , std) ; 
    	display(records , std) ; 
    	return 0 ; 
} */

