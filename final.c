/*#include<stdio.h>
void frontPage(){
	printf("\t\t\t\t\t\t\t\t\t\t**********  WELCOME TO EAT AND STAY  *********\n");
	printf("\n\t\t\t\t\t\tOUR PROGRAMME PROVIDES YOU THE ACCESS OF HOTELS AND RESTAURANTS, FOR BOOKING OF ROOMS AND ORDERING THE FOOD.   \n\n     \t\t\t\t\t\t\t\t\t\t\t\"SO KEEP EATING AND STAY RELAX\"\n\n");
}
int main(){
	frontPage();
}*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
typedef struct
{
	int noOfRooms, cost, disc, disc_type, noOfDays, discount, discount_cost, free, paid_Chosen, num_paid, paid_Charge;
	char paid_Fac[50], free_Fac[50];
} roomDetails;
typedef struct
{
	char name[50], location[50], description[200], free_Fac[50], paid_Fac[50];
	int hotel_Fac, paid_Fac_Charge, single, _double, triple, noOfPaidFac, noOfRooms;
} hotelDetails;
typedef struct
{
	int day, month, year;
} expireDate;

typedef struct
{
	char cardNo[20], nameOnCard[20];
	int cvv;
	expireDate date;
} creditCardDetails;
typedef struct
{
	int noOfRooms, noOfDays;
	char hotelEmail[50], paymentMethod[20], cusName[50], cusPhoneNo[50];
	int singleBedRooms, doubleBedRooms, tripleBedRooms;
	float singleBedRoomsCost, doubleBedRoomsCost, tripleBedRoomsCost, totalCost;
	creditCardDetails card;
} hotelBookDetails;
typedef struct
{
	char resEmail[50], cusName[50], cusPhoneNo[20], paymentMethod[20];
	float totalPrice;
	creditCardDetails card;
} resOrderDetails;
typedef struct
{
	char name[50];
	float price;
	int quantity;
} dishDetails;
bool password_verify(char *password);
char *vemail();
int signUpFunc();
int logInFunc();
void delFiles(); // filhal ke liye unused function
void numValid();
void nameValid(char name[]);
int *creditCardValid();
void phoneNoValidation(char number[]) ;
void frontPage();
void confirmOrder();
int main()
{
	system("color 06");
	FILE *filePtr = fopen("currently login.txt", "r");
	char fileName[50];
	fgets(fileName, sizeof fileName, filePtr);
	fclose(filePtr);
	if (strcmp(fileName, " ") != 0)
	{
		profile(fileName);
	}
	else
	{
		frontPage();
		int choice;
		printf("\n-->You Can Login If You Already Have An Account\n-->You Can Sign-up If You Want To Create An Account \n");
		printf("\n1.Login Page\n2.Sign-up Page \n");
		printf("\nEnter Your Choice : ");
		while (choice != 1 && choice != 2 )
		{
			fflush(stdin);
			scanf("%d", &choice);
			if (choice != 1 && choice != 2)
			{
				printf("\nEnter A Valid Choice : ");
			}
		}
		if (choice == 1)
		{
			system("cls");
			logInFunc();
		}
		else if (choice == 2)
		{
			system("cls");
			signUpFunc();
		}
	}
	return 0;
}
void frontPage(){
	printf("\t\t\t\t\t\t\t\t\t\t**********  WELCOME TO EAT AND STAY  *********\n");
	printf("\n\t\t\t\t\t\tOUR PROGRAMME PROVIDES YOU THE ACCESS OF HOTELS AND RESTAURANTS, FOR BOOKING OF ROOMS AND ORDERING THE FOOD.   \n\n     \t\t\t\t\t\t\t\t\t\t\t\"SO KEEP EATING AND STAY RELAX\"\n\n");
}
void phoneNoValidation(char number[])
{
	char i,length;
	while(1) {
//	printf("\nEnter Your Phone Number : ");
	fflush(stdin) ; 
	scanf("%s",number);
	length=strlen(number);

	
	if(number[0]=='0'){
		if(length==11){
			printf("\n-->Your Phone Number Is Verified ! ");
			break ; 
		} else {
			printf("\nEnter A Valid Phone Number : ") ; 
		}
	}
	else if(number[0]=='+'){
		if(number[1]=='9'){
			if(number[2]=='2'){
				if(length==13){
					printf("\nYour Phone Number Is Verified ! ");
					break ;
				}
				
			}
		}
	}
	else{
		printf("\nEnter A Valid Phone Number : ");
	}
	}
	
}
void nameValid(char name[])
{
	int i, j, k, counter = 0;
	for (i = 0; i < strlen(name); i++)
	{
		if (isalpha(name[i]) || name[i] == ' ')
		{
			counter++;
		}
	}
	if (counter != strlen(name))
	{
		do
		{
			counter = 0;
			printf("\n-->Kindly Enter Only Alphabets (A-Z) : ");
			gets(name);
			for (i = 0; i < strlen(name); i++)
			{
				if (isalpha(name[i]) || name[i] == ' ')
				{
					counter++;
				}
			}
		} while (counter != strlen(name));
	}
}
void numValid()
{
	int num;
	int correctNum = 0;
	do
	{
		while (correctNum != 1)
		{
			printf("\n-->Invalid Number Of Rooms ! ");
			scanf("%*[^\n]");
			printf("\nEnter Any Number : ");
			correctNum = scanf("%d", &num);
		}
		if (num >= 0 && num < 99)
		{
			printf("Correct Num : %d", num);
		}
		else if (num < 0 || num > 99)
		{
			printf("\nKindly Enter Correct Number Of Rooms : ");
		}

	} while (!(num >= 0 && num < 99));
}

int *creditCardValid()
{
	int a = 16, i, j, k, total, firstNumber;
	int sum1 = 0;
	int sum2 = 0;
	// Registers the number of digits in the credit card.
	int cardNumber[a];
	int *creditCardNo = (int *)malloc(sizeof(int) * a);
	// Takes the credit card number in the order from left to right.
	printf("\n-->Enter Your Credit Card Number : ");
	for (j = 1; j <= a; j++)
	{
		int num;
		printf("%d: ", j);
		scanf("%d", &num);
		cardNumber[j] = num, creditCardNo[j - 1] = num;
	}
	firstNumber = cardNumber[1];
	// Application of Luhn Algorithm.
	for (i = (a - 1); i > 0; i = i - 2)
	{
		cardNumber[i] = cardNumber[i] * 2;
		if (cardNumber[i] > 9)
		{
			cardNumber[i] = cardNumber[i] - 9;
			sum1 = sum1 + cardNumber[i];
		}
		else
		{
			sum1 = sum1 + cardNumber[i];
		}
	}
	for (k = a; k > 0; k = k - 2)
	{
		sum2 = sum2 + cardNumber[k];
	}
	total = sum1 + sum2;
	if (total % 10 == 0)
	{
		return creditCardNo;
	}
	else
	{
		printf("\n-->Your Credit Card Number Is Not Valid ! \n\n");
		creditCardValid(a);
	}
}
void delFiles()
{
	FILE *filePtr = fopen("deleted files.txt", "r");
	char filePath[50];
	while (fgets(filePath, sizeof filePath, filePtr) != NULL)
	{
		remove(filePath);
	}
	fclose(filePtr);
}
// Yeh jab koi customer/restaurant/hotel login hoga tou role ko read kare ga
char readRole(FILE *filePtr)
{
	int count = 0;
	char role[50];
	while (fgets(role, sizeof role, filePtr) != NULL)
	{

		if (count == 1)
		{
			printf("%c", role[0]);
			return role[0];
		}
		else
		{
			count++;
		}
	}
}
// yeh jab customer ko hotels ya restaurants jo dekhne honge tab tab call hoga
void homeFunc(int *choice)
{
	FILE *homePtr, *allFilesPtr;
	printf("\t\t\t\t\t\t\t\t\t\t**********  COSTUMER LOGIN  **********\n\n");
	printf("\n-->You Can Access To Hotels And Restaurants ");
	printf("\n1.Hotels\n2.Restaurants\n");
	printf("\nEnter Your Choice : ");
	char ans;
	scanf("%c", &ans);
	if (ans == '1')
	{
		homePtr = fopen("home page hotels.txt", "r");
	}
	else
	{
		homePtr = fopen("home page.txt", "r");
	}
	char line[50];
	while (fgets(line, sizeof line, homePtr) != NULL)
	{
		printf("%s", line);
	}
	fclose(homePtr);
	*choice = ans;
}

void encrypted_pass(char password[])
{
	int counter;
	for (counter = 0; (counter < 100 && password[counter] != '\0'); counter++)
	{
		password[counter] = password[counter] + 3;
	}
}

void decrypted_pass(char password[])
{
	int passCounter;
	for (passCounter = 0; (passCounter < 100 && password[passCounter] != '\0'); passCounter++)
	{
		password[passCounter] = password[passCounter] - 3;
	}
}

void hide_pass(char password[])
{
	char character;
	int counter = 0, i;
	while ((character = _getch()) != 13)
	{
		if (character == 8)
		{
			fflush(stdout);
			printf("\b \b");
			password[--counter] = '\0';
			continue;
		}
		printf("*");
		password[counter] = character;
		counter++;
	}
	password[counter] = '\0';
}
// yeh jab restaurant/customer/hotel apni restaurant/hotel ki details yah customer jab booking kar le tou sari details laye ga //
void readingDetails(int *counter, FILE *filePtr, char role)
{
	system("cls");
	char line[50];
	int i = 0;
	printf("\t\t\t\t\t\t\t\t\t\t\t**********  YOUR PROFILE  **********\n");
	while (fgets(line, sizeof line, filePtr) != NULL)
	{
		if (i == 0)
		{
			decrypted_pass(line);
			printf("-->Your Password : %s", line);
			i++;
		}
		else if (i == 1)
		{
			printf("\n-->Role : %s", line);
			i++;
		}
		else if (i == 2)
		{
			printf("-->Your E-Mail ID : %s", line);
			i++;
		}
		else if (i == 3)
		{
			printf("-->Your User Name : %s", line);
			i++;
		}
		else if (i > 3)
		{
			printf("%s", line);
			i++;
		}
	}
	*counter = i;
}
// ye customer ko read kar ne ke liye alag se ek function ha
void readingCustomer(int *counter, FILE *filePtr, char *role)
{
	system("cls");
	char line[50];
	int i = 0;
	printf("\t\t\t\t\t\t\t\t\t\t\t**********  CUSTOMER PROFILE  **********\n");
	while (fgets(line, sizeof line, filePtr) != NULL)
	{
		if (i == 0)
		{
			decrypted_pass(line);
			printf("-->Your Password : %s", line);
			i++;
		}
		else if (i == 1)
		{
			*role = line[0];
			printf("\n-->Role : %s", line);
			i++;
		}
		else if (i == 2)
		{
			printf("\n-->Your E-Mail ID : %s", line);
			i++;
		}
		else if (i == 3)
		{
			printf("\n-->Your User Name : %s", line);
			i++;
		}
		else
		{
			printf("%s", line);
			i++;
		}
	}
	*counter = i;
}
// tujhe jo kaam karna ha main is function ko sudharna ha //
int profile(char filePath[])
{
	while (1)
	{
		FILE *filePtr = fopen(filePath, "r"), *homeHotelPtr, *homeResPtr;
		int counter = 0;
		system("cls");
		char role = readRole(filePtr);
		fclose(filePtr);
		filePtr = fopen(filePath, "r");
		readingDetails(&counter, filePtr, role);
		fclose(filePtr);
		printf("\n-->Do You Want To Logout ?\n1.Yes\n2.No ");
		printf("\nEnter Your Choice : ");
		char logOutChoice;
		fflush(stdin);
		scanf("%c", &logOutChoice);
		if (logOutChoice == '1')
		{
			filePtr = fopen("currently login.txt", "w");
			fprintf(filePtr, " ");
			fclose(filePtr);
			break;
		}
		printf("\n-->Do You Want To Edit Your Profile ?\n1.Yes\n2.No ");
		printf("\nEnter Your Choice : ");
		char editProfChoice;
		fflush(stdin);
		scanf("%c", &editProfChoice);
		// Edit Profile //
		if (editProfChoice == '1')
		{
			system("cls");
			printf("\t\t\t\t\t\t\t\t\t\t**********  EDIT PROFILE  **********\n");
			printf("\n-->What Do You Wish To Edit ?\n1.Email\n2.Password\n3.UserName\n");
			printf("\nEnter Your Choice : ");
			int changeChoice, i, j, k;
			char newEmail[50], line[50], fileData[100][50], accountFileData[50][50];
			scanf("%d", &changeChoice);
			if (changeChoice == '1')
			{
				printf("\nEnter Your New E-mail : ");
				fflush(stdin);
				gets(newEmail);
				filePtr = fopen(filePath, "r");
				while (fgets(line, sizeof line, filePtr) != NULL)
				{
					if (i == 2)
					{
						strcpy(fileData[i], newEmail);
						int emailLength = strlen(newEmail);
						fileData[i][emailLength] = '\n';
					}
					else
					{
						strcpy(fileData[i], line);
					}
					i++;
				}
				fclose(filePtr);
				if (role == '2')
				{
					filePtr = fopen("restaurantAccounts.txt", "r");
					int countFilePath = 0, countAccountFileData = 0;
					k = 0;
					while (fgets(line, sizeof line, filePtr) != NULL)
					{
						countFilePath = 0;
						for (j = strlen(line) - strlen(filePath) - 1, i = 0; j < strlen(line) - 1; j++, i++)
						{
							if (line[j] == filePath[i])
							{
								countFilePath++;
							}
						}
						if (countFilePath == strlen(filePath))
						{
							break;
						}
						k++;
					}
					fclose(filePtr);
					printf("countFilePath : %d , k : %d", countFilePath, k);
					j = 0;
					filePtr = fopen("restaurantAccounts.txt", "r");
					while (fgets(line, sizeof line, filePtr) != NULL)
					{
						strcpy(accountFileData[j], line);
						j++;
						countAccountFileData++;
					}
					fclose(filePtr);

					j = 0;
					char newPath[50];
					for (j = 0; j < strlen(accountFileData[k]) - strlen(filePath) - 1; j++)
					{
						newPath[j] = accountFileData[k][j];
					}
					char newAccountPath[50];
					strcpy(newAccountPath, newEmail);
					strcat(newAccountPath, ".txt");
					for (j, i = 0; i < strlen(newAccountPath); j++, i++)
					{
						newPath[j] = newAccountPath[i];
					}
					newPath[j] = '\n';
					strcpy(accountFileData[k], newPath);
					filePtr = fopen("restaurantAccounts.txt", "w");
					for (j = 0; j < countAccountFileData; j++)
					{
						fprintf(filePtr, "%s", accountFileData[j]);
					}
					fclose(filePtr);
				}
				if (role == '3')
				{
					filePtr = fopen("hotelAccounts.txt", "r");
					int countFilePath = 0, countAccountFileData = 0;
					k = 0;
					while (fgets(line, sizeof line, filePtr) != NULL)
					{
						countFilePath = 0;
						for (j = strlen(line) - strlen(filePath) - 1, i = 0; j < strlen(line) - 1; j++, i++)
						{
							if (line[j] == filePath[i])
							{
								countFilePath++;
							}
						}
						if (countFilePath == strlen(filePath))
						{
							break;
						}
						k++;
					}
					fclose(filePtr);
					j = 0;
					filePtr = fopen("hotelAccounts.txt", "r");
					while (fgets(line, sizeof line, filePtr) != NULL)
					{
						strcpy(accountFileData[j], line);
						j++;
						countAccountFileData++;
					}
					fclose(filePtr);

					j = 0;
					char newPath[50];
					for (j = 0; j < strlen(accountFileData[k]) - strlen(filePath) - 1; j++)
					{
						newPath[j] = accountFileData[k][j];
					}

					char newAccountPath[50];
					strcpy(newAccountPath, newEmail);
					strcat(newAccountPath, ".txt");
					for (j, i = 0; i < strlen(newAccountPath); j++, i++)
					{
						newPath[j] = newAccountPath[i];
					}
					newPath[j] = '\n';

					strcpy(accountFileData[k], newPath);
					filePtr = fopen("hotelAccounts.txt", "w");
					for (j = 0; j < countAccountFileData; j++)
					{
						fprintf(filePtr, "%s", accountFileData[j]);
					}
					fclose(filePtr);
				}
				filePtr = fopen(strcat(newEmail, ".txt"), "w");
				for (j = 0; j < i; j++)
				{
					fprintf(filePtr, "%s", fileData[j]);
				}
				fclose(filePtr);
				filePtr = fopen("deleted files.txt", "a");
				fprintf(filePtr, "\n%s", filePath);
				fclose(filePtr);
				filePtr = fopen("currently login.txt", "w");
				fprintf(filePtr, "%s", newEmail);
				fclose(filePtr);
			}
			else if (changeChoice == '2' || changeChoice == '3')
			{
				filePtr = fopen(filePath, "r");
				i = 0;
				while (fgets(line, sizeof line, filePtr) != NULL)
				{
					strcpy(fileData[i], line);
					i++;
				}
			}
			fclose(filePtr);
			if (changeChoice == '2')
			{
				char prevPass[50], newPass[50], passToMatch[50] = {0};
				int k, passMatch = 0;
				for (k = 0; fileData[0][k] != '\n'; k++)
				{
					passToMatch[k] = fileData[0][k];
				}
				printf("\nEnter Your Previous Password : ");
				while (passMatch == 0)
				{
					
					hide_pass(prevPass);
					encrypted_pass(prevPass);
					if (strcmp(prevPass, passToMatch) == 0)
					{
						passMatch = 1;
					}
					if (passMatch == 0)
					{
						printf("\n-->Password Is Not Correct !");
						printf("\nEnter Again : ");
					}
				}
				bool result;
				do
				{
					printf("\nEnter A New Password : ");
					hide_pass(newPass);
					encrypted_pass(newPass);
					result = password_verify(newPass);
					if (result)
					{
						printf("\n-->Your Password Is Verified !");
					}
					else
					{
						printf("\n-->Password Is Not Verified !");
					}
				} while (!result);
				filePtr = fopen(filePath, "w");
				for (j = 0; j < i; j++)
				{
					if (j == 0)
					{
						fprintf(filePtr, "%s\n", newPass);
					}
					else
					{
						fprintf(filePtr, "%s", fileData[j]);
					}
				}
				fclose(filePtr);
			}
			else if (changeChoice == '3')
			{
				char newUserName[50];
				printf("\nEnter A New User Name : ");
				fflush(stdin);
				gets(newUserName);
				filePtr = fopen(filePath, "w");
				for (j = 0; j < i; j++)
				{
					if (j == 3)
					{
						fprintf(filePtr, "%s\n", newUserName);
					}
					else
					{
						fprintf(filePtr, "%s", fileData[j]);
					}
				}
				fclose(filePtr);
			}
		}
		char menuAns, line[50];
		// if restaurant login //
		if (counter == 4 && role == '2')
		{
			printf("\t\t\t\t\t\t\t\t\t\t**********  RESTAURANT LOGIN  **********\n");
			printf("\n-->You Have Not Entered Your Restaurant Details");
			printf("\n-->Do You Wish To Enter It ?");
			printf("\n1.Yes\n2.No");
			printf("\nEnter Your Choice : ");
			fflush(stdin);
			scanf("%c", &menuAns);
			//menuAns = menuAns < 91 ? menuAns + 26 : menuAns;
			if (menuAns == '1')
			{
				int restaurantNoMax = 0;
				filePtr = fopen("restaurantAccounts.txt", "r");
				while (fgets(line, sizeof line, filePtr) != NULL)
				{
					int restaurantNo = (int)(line[0] - '0');
					if (restaurantNo > restaurantNoMax)
					{
						restaurantNoMax = restaurantNo;
					}
				}
				fclose(filePtr);
				filePtr = fopen(filePath, "a");
				int resNameMatch;
				int typeCounter, dishesCounter;
				char name[50];
				system("cls");
				printf("\t\t\t\t\t\t\t\t\t\t**********  RESTAURANT DETAILS  **********\n");
				while (1)
				{
					homeResPtr = fopen("home page.txt", "r");
					if (homeResPtr == NULL)
					{
						perror("Error!");
					}
					printf("\nEnter Name Of Your Restaurant : ");
					fflush(stdin);
					gets(name);
					int resNameLen = strlen(name);
					char resNameFile[resNameLen + 1];
					while (fgets(resNameFile, sizeof resNameFile, homeResPtr) != NULL)
					{
						resNameMatch = 0;
						if (strcmp(name, resNameFile) == 0)
						{
							resNameMatch = 1;
							break;
						}
					}
					fclose(homeResPtr);
					if (resNameMatch == 1)
					{
						printf("\n-->Restaurant Name Already Exists ");
						printf("\nEnter A Unique Name : ");
					}
					if (resNameMatch == 0)
					{
						break;
					}
				}
				homeResPtr = fopen("home page.txt", "a");
				printf("\n-->How Many types Of Dishes Are There In Your Restaurant : ");
				scanf("%d", &typeCounter);
				printf("\nEnter Dishes In Each Type : ");
				scanf("%d", &dishesCounter);
				char restaurantMenu[typeCounter][dishesCounter + 1][50];
				int restaurantMenuPrice[typeCounter][dishesCounter + 1], i, j;
				for (i = 0; i < typeCounter; i++)
				{
					printf("\nEnter Dish type #%d : ", i + 1);
					fflush(stdin);
					gets(restaurantMenu[i][0]);
					for (j = 1; j <= dishesCounter; j++)
					{
						printf("\nName Of Dish #%d is : ", j);
						fflush(stdin);
						gets(restaurantMenu[i][j]);
						fflush(stdin);
						printf("\nEnter Price Of Dish : ");
						scanf("%d", &restaurantMenuPrice[i][j]);
					}
				}
				fprintf(homeResPtr, "\nRestaurant %d", restaurantNoMax);
				fprintf(filePtr, "\n%s", name);
				fprintf(homeResPtr, "\n%s", name);
				fprintf(filePtr, "\nYour Restaurant Menu: ");
				fprintf(homeResPtr, "\nYour Restaurant Menu: ");
				for (i = 0; i < typeCounter; i++)
				{
					for (j = 0; j < dishesCounter + 1; j++)
					{
						if (j == 0)
						{
							fprintf(filePtr, "\n%d: Dish Type : %s", i + 1, restaurantMenu[i][j]);
							fprintf(homeResPtr, "\n%d: Dish Type : %s", i + 1, restaurantMenu[i][j]);
						}
						else
						{
							fprintf(filePtr, "\n%d: %s %d", j, restaurantMenu[i][j], restaurantMenuPrice[i][j]);
							fprintf(homeResPtr, "\n%d: %s %d", j, restaurantMenu[i][j], restaurantMenuPrice[i][j]);
						}
					}
				}
				fprintf(filePtr, "\n\nAll Customer Orders: ");
				fclose(filePtr);
				fclose(homeResPtr);
				counter = 0;
				system("cls");
				filePtr = fopen(filePath, "r");
				readingDetails(&counter, filePtr, &role);
				fclose(filePtr);
			}
			else
			{
				printf("\n\n-->As your wish !!");
			}
		}
		// if hotel login
		else if (counter == 4 && role == '3')
		{
			int choice, choose, i, j, k, l, chosen;
			hotelDetails hotel;
			system("cls");
			printf("\t\t\t\t\t\t\t\t\t\t**********  HOTEL LOGIN  **********\n");
			printf("\n\nDo you want to add details of your Hotel ? \n1.Yes\n2.No\n");
			scanf("%d", &choice);
			if (choice == 1)
			{
				filePtr = fopen("hotelAccounts.txt", "r");
				int hotelNoMax = 0;
				while (fgets(line, sizeof line, filePtr) != NULL)
				{
					int hotelNo = (int)(line[0] - '0');
					if (hotelNo > hotelNoMax)
					{
						hotelNoMax = hotelNo;
					}
				}
				fclose(filePtr);
				filePtr = fopen(filePath, "a");
				printf("\n\t\t\t\t\t\t\t\t\t\t**********  HOTEL DETAILS  **********\n");
				int hotelNameMatch;
				while (1)
				{
					homeHotelPtr = fopen("home page hotels.txt", "r");
					printf("\nEnter Name Of Your Hotel : ");
					fflush(stdin);
					gets(hotel.name);
					int hotelNameLen = strlen(hotel.name);
					char hotelNameFile[hotelNameLen + 1];
					while (fgets(hotelNameFile, sizeof hotelNameFile, homeHotelPtr))
					{
						hotelNameMatch = 0;
						if (strcmp(hotel.name, hotelNameFile) == 0)
						{
							hotelNameMatch = 1;
							break;
						}
					}
					fclose(homeHotelPtr);
					if (hotelNameMatch == 1)
					{
						printf("\n-->Hotel Name Already Exists ");
						printf("\nEnter A Unique Name : ");
					}
					if (hotelNameMatch == 0)
					{
						break;
					}
				}
				homeHotelPtr = fopen("home page hotels.txt", "a");
				fprintf(homeHotelPtr, "\nHotel %d", hotelNoMax);
				fprintf(filePtr, "\n%s", hotel.name);
				fprintf(homeHotelPtr, "\n%s", hotel.name);
				printf("\nEnter Location Of Your Hotel : ");
				fflush(stdin);
				gets(hotel.location);
				fprintf(filePtr, "\n%s", hotel.location);
				fprintf(homeHotelPtr, "\n%s", hotel.location);
				printf("\t\t\t\t\t\t\t\t\t\t**********  HOTEL FACILITIES  **********\n");
				printf("\n\n-->How many free facilities are there in your hotel : ");
				scanf("%d", &hotel.hotel_Fac);
				if (hotel.hotel_Fac > 0)
				{
					printf("\n-->Enter all free facilities \n");
					fprintf(filePtr, "\nHotel Free Facilities: ");
					fprintf(homeHotelPtr, "\nHotel Free Facilities: ");
					for (l = 0; l < hotel.hotel_Fac; l++)
					{
						printf("%d. ", l + 1);
						fflush(stdin);
						gets(hotel.free_Fac);
						fprintf(filePtr, "\n%d: %s", l + 1, hotel.free_Fac);
						fprintf(homeHotelPtr, "\n%d: %s", l + 1, hotel.free_Fac);
					}
				}
				printf("\nIs There Any Paid Facility In Your Hotel ?\n1.Yes\t2.No\n");
				scanf("%d", &chosen);
				if (chosen == 1)
				{
					printf("\nHow many paid facilities are there : ");
					scanf("%d", &hotel.noOfPaidFac);
					printf("\nEnter all paid facilities : \n");
					fprintf(filePtr, "\nHotel Paid Facilities: ");
					fprintf(homeHotelPtr, "\nHotel Paid Facilities: ");
					for (i = 0; i < hotel.noOfPaidFac; i++)
					{
						printf("%d. ", i + 1);
						fflush(stdin);
						gets(hotel.paid_Fac);
						printf("\nEnter charges of facility #0%d : ", i + 1);
						scanf("%d", &hotel.paid_Fac_Charge);
						fprintf(filePtr, "\n%d: %s     %d", i + 1, hotel.paid_Fac, hotel.paid_Fac_Charge);
						fprintf(homeHotelPtr, "\n%d: %s     %d", i + 1, hotel.paid_Fac, hotel.paid_Fac_Charge);
					}
				}
				printf("\n-->Add any description for the users to read when they visit your profile (minimum 50 characters) : ");
				fflush(stdin);
				gets(hotel.description);
				fprintf(filePtr, "\ndescription: %s", hotel.description);
				fprintf(homeHotelPtr, "\ndescription: %s", hotel.description);
				printf("\n-->Do You Want To Enter Room Details Of Your Hotel ? \n1.Yes\n2.No\n3.Exit\n");
				scanf("%d", &choose);
				if (choose == 1)
				{
					printf("\t\t\t\t\t\t\t\t\t\t**********  ROOM DETAILS  **********\n");
					fprintf(filePtr, "\n\n      ..........ROOM DETAILS........\n\n");
					fprintf(homeHotelPtr, "\n\n      ..........ROOM DETAILS........\n\n");
					printf("-->How many rooms are there in your Hotel? : ");
					scanf("%d", &hotel.noOfRooms);
					fprintf(filePtr, "\nNo Of Rooms : %d", hotel.noOfRooms);
					fprintf(homeHotelPtr, "\nNo Of Rooms : %d", hotel.noOfRooms);
					printf("\nAre there any single-bed rooms ?\n1.Yes\n2.No");
					scanf("%d", &hotel.single);
					if (hotel.single == 1)
					{
						roomDetails singleBedRooms;
						fprintf(filePtr, "\nSingle Bed Rooms: ");
						fprintf(homeHotelPtr, "\nSingle Bed Rooms: ");
						printf("\n\nHow many single bed rooms are there? : ");
						scanf("%d", &singleBedRooms.noOfRooms);
						fprintf(filePtr, "\nNo Of Rooms: %d", singleBedRooms.noOfRooms);
						fprintf(homeHotelPtr, "\nNo Of Rooms: %d", singleBedRooms.noOfRooms);
						printf("\nEnter the cost of per day in single-bed room : ");
						scanf("%d", &singleBedRooms.cost);
						fprintf(filePtr, "\nPer Night Cost: \n%d", singleBedRooms.cost);
						fprintf(homeHotelPtr, "\nPer Night Cost: \n%d", singleBedRooms.cost);
						printf("\nIs there any special discount for staying longer days in these rooms ? \n1.Yes\n2.No");
						scanf("%d", &singleBedRooms.disc);
						if (singleBedRooms.disc == 1)
						{
							printf("\nHow many special discount offers are available for customers :  ");
							scanf("%d", &singleBedRooms.disc_type);
							for (j = 0; j < singleBedRooms.disc_type; j++)
							{
								printf("\nEnter the number of days : ");
								scanf("%d", &singleBedRooms.noOfDays);
								printf("\nEnter the discount without percentage sign : ");
								scanf("%d", &singleBedRooms.discount);
								singleBedRooms.discount_cost = ((singleBedRooms.cost) * singleBedRooms.noOfDays * (singleBedRooms.discount) / 100);
								printf("\n%d rupees discount on %d days \n", singleBedRooms.discount_cost, singleBedRooms.noOfDays);
								fprintf(filePtr, "\n%d rupees discount on %d days \n", singleBedRooms.discount_cost, singleBedRooms.noOfDays);
								fprintf(homeHotelPtr, "\n%d rupees discount on %d days \n", singleBedRooms.discount_cost, singleBedRooms.noOfDays);
							}
						}
						printf("\t\t\t\t\t\t\t\t\t\t**********  ROOM FACILITIES  **********\n");
						fprintf(filePtr, "\n\n      ..........ROOM FACILITIES........\n\n");
						fprintf(homeHotelPtr, "\n\n      ..........ROOM FACILITIES........\n\n");
						printf("\nHow many free facilities are there in single-bed room ? : ");
						scanf("%d", &singleBedRooms.free);
						if (singleBedRooms.free > 0)
						{
							printf("\nEnter all free facilities : \n");
							fprintf(filePtr, "\nFree Facilities: ");
							fprintf(homeHotelPtr, "\nFree Facilities: ");
							for (l = 0; l < singleBedRooms.free; l++)
							{
								printf("%d. ", l + 1);
								fflush(stdin);
								gets(singleBedRooms.free_Fac);
								fprintf(filePtr, "\n%d: %s", l + 1, singleBedRooms.free_Fac);
								fprintf(homeHotelPtr, "\n%d: %s", l + 1, singleBedRooms.free_Fac);
							}
						}
						printf("\nIs there any paid facility : \n1.Yes\t2.No\n");
						scanf("%d", &singleBedRooms.paid_Chosen);
						if (singleBedRooms.paid_Chosen == 1)
						{
							fprintf(filePtr, "\nPaid Facilities: ");
							fprintf(homeHotelPtr, "\nPaid Facilities: ");
							printf("\nHow many paid facilities are there : ");
							scanf("%d", &singleBedRooms.num_paid);
							printf("\nEnter all paid facilities : \n");
							for (i = 0; i < singleBedRooms.num_paid; i++)
							{
								printf("%d. ", i + 1);
								fflush(stdin);
								gets(singleBedRooms.paid_Fac);
								printf("\nEnter charges of facility #0%d : ", i + 1);
								scanf("%d", &singleBedRooms.paid_Charge);
								fprintf(filePtr, "\n%d: %s   %d", i + 1, singleBedRooms.paid_Fac, singleBedRooms.paid_Charge);
								fprintf(homeHotelPtr, "\n%d: %s   %d", i + 1, singleBedRooms.paid_Fac, singleBedRooms.paid_Charge);
							}
						}
					}
					printf("\n\n-->Are there any Double-bed rooms ? \n1.Yes\n2.No");
					printf("\nEnter Your Choice : ");
					scanf("%d", &hotel._double);
					if (hotel._double == 1)
					{
						roomDetails doubleBedRooms;
						fprintf(filePtr, "\n Double-Bed Rooms:");
						fprintf(homeHotelPtr, "\n Double-Bed Rooms:");
						printf("\nHow many double bed rooms are there ? : ");
						scanf("%d", &doubleBedRooms.noOfRooms);
						fprintf(filePtr, "\nNo Of Rooms: %d", doubleBedRooms.noOfRooms);
						fprintf(homeHotelPtr, "\nNo Of Rooms: %d", doubleBedRooms.noOfRooms);
						printf("\nEnter the cost of per day in double-bed room : ");
						scanf("%d", &doubleBedRooms.cost);
						fprintf(filePtr, "\nPer Night Cost: \n%d", doubleBedRooms.cost);
						fprintf(homeHotelPtr, "\nPer Night Cost: \n%d", doubleBedRooms.cost);
						printf("\nIs there any special discount for staying longer days in these rooms :\n1.Yes\n2.No");
						scanf("%d", &doubleBedRooms.disc);
						if (doubleBedRooms.disc == 1)
						{
							printf("\nHow many special discount offers are available for customers : ");
							scanf("%d", &doubleBedRooms.disc_type);
							fprintf(filePtr, "\nDiscount Offers: ");
							fprintf(homeHotelPtr, "\nDiscount Offers: ");
							for (j = 0; j < doubleBedRooms.disc_type; j++)
							{
								printf("\nEnter the number of days : ");
								scanf("%d", &doubleBedRooms.noOfDays);
								printf("\nEnter the discount without percentage sign : ");
								scanf("%d", &doubleBedRooms.discount);
								doubleBedRooms.discount_cost = ((doubleBedRooms.cost) * doubleBedRooms.noOfDays * (doubleBedRooms.discount) / 100);
								printf("%d rupees discount on %d days \n", doubleBedRooms.discount_cost, doubleBedRooms.noOfDays);
								fprintf(filePtr, "\n%d rupees discount on %d days \n", doubleBedRooms.discount_cost, doubleBedRooms.noOfDays);
								fprintf(homeHotelPtr, "\n%d rupees discount on %d days \n", doubleBedRooms.discount_cost, doubleBedRooms.noOfDays);
							}
						}
						printf("\t\t\t\t\t\t\t\t\t\t**********  ROOM FACILITIES  **********\n");
						fprintf(filePtr, "\n\n      ..........ROOM FACILITIES........\n\n");
						fprintf(homeHotelPtr, "\n\n      ..........ROOM FACILITIES........\n\n");
						printf("\nHow many free facilities are there in Double-bed room ? : ");
						scanf("%d", &doubleBedRooms.free);
						if (doubleBedRooms.free > 0)
						{
							printf("\nEnter all free facilities : \n");
							fprintf(filePtr, "\nFree facilities :");
							fprintf(homeHotelPtr, "\nFree facilities :");
							for (l = 0; l < doubleBedRooms.free; l++)
							{
								printf("%d. ", l + 1);
								fflush(stdin);
								gets(doubleBedRooms.free_Fac);
								fprintf(filePtr, "\n%d: %s", l + 1, doubleBedRooms.free_Fac);
								fprintf(homeHotelPtr, "\n%d: %s", l + 1, doubleBedRooms.free_Fac);
							}
						}
						printf("\nIs there any paid facility in Double-bed room? : \n1.Yes\t2.No\n");
						scanf("%d", &doubleBedRooms.paid_Chosen);

						if (doubleBedRooms.paid_Chosen == 1)
						{
							fprintf(filePtr, "\nPaid Facilities: ");
							fprintf(homeHotelPtr, "\nPaid Facilities: ");
							printf("\nHow many paid facilities are there : ");
							scanf("%d", &doubleBedRooms.num_paid);
							printf("\nEnter all paid facilities : \n");
							for (i = 0; i < doubleBedRooms.num_paid; i++)
							{
								printf("%d. ", i + 1);
								fflush(stdin);
								gets(doubleBedRooms.paid_Fac);
								printf("\nEnter charges of facility #0%d : ", i + 1);
								scanf("%d", &doubleBedRooms.paid_Charge);
								fprintf(filePtr, "\n%d: %s      %d", i + 1, doubleBedRooms.paid_Fac, doubleBedRooms.paid_Charge);
								fprintf(homeHotelPtr, "\n%d: %s      %d", i + 1, doubleBedRooms.paid_Fac, doubleBedRooms.paid_Charge);
							}
						}
					}
					printf("\n-->Are there any Triple-bed rooms ? \n1.Yes\n2.No");
					scanf("%d", &hotel.triple);
					if (hotel.triple == 1)
					{
						fprintf(filePtr, "\nTriple Bed Rooms: ");
						fprintf(homeHotelPtr, "\nTriple Bed Rooms: ");
						roomDetails tripleBedRooms;
						printf("\nHow many Triple bed rooms are there? : ");
						scanf("%d", &tripleBedRooms.noOfRooms);
						fprintf(filePtr, "\nNo Of Rooms: %d", tripleBedRooms.noOfRooms);
						fprintf(homeHotelPtr, "\nNo Of Rooms: %d", tripleBedRooms.noOfRooms);
						printf("\nEnter the cost of per day in Triple-bed room : ");
						scanf("%d", &tripleBedRooms.cost);
						fprintf(filePtr, "\nPer Night Cost: %d", tripleBedRooms.cost);
						fprintf(homeHotelPtr, "\nPer Night Cost: %d", tripleBedRooms.cost);
						printf("\nIs there any special discount for staying longer days in these rooms :\n1.Yes\n2.No");
						scanf("%d", &tripleBedRooms.disc);
						if (tripleBedRooms.disc == 1)
						{
							printf("\nHow many special discount offers are available for customers : ");
							scanf("%d", &tripleBedRooms.disc_type);
							fprintf(filePtr, "\nDiscount Offers: ");
							fprintf(homeHotelPtr, "\nDiscount Offers: ");
							for (j = 0; j < tripleBedRooms.disc_type; j++)
							{
								printf("\nEnter the number of days : ");
								scanf("%d", &tripleBedRooms.noOfDays);
								printf("\nEnter the discount without percentage sign : ");
								scanf("%d", &tripleBedRooms.discount);
								tripleBedRooms.discount_cost = ((tripleBedRooms.cost) * tripleBedRooms.noOfDays * (tripleBedRooms.discount) / 100);
								printf("%d rupees discount on %d days \n", tripleBedRooms.discount_cost, tripleBedRooms.noOfDays);
								fprintf(filePtr, "\n%d rupees discount on %d days \n", tripleBedRooms.discount_cost, tripleBedRooms.noOfDays);
								fprintf(homeHotelPtr, "\n%d rupees discount on %d days \n", tripleBedRooms.discount_cost, tripleBedRooms.noOfDays);
							}
						}
						printf("\t\t\t\t\t\t\t\t\t\t**********  ROOM FACILITIES  **********\n");
						fprintf(filePtr, "\n\n      ..........ROOM FACILITIES........\n\n");
						fprintf(homeHotelPtr, "\n\n      ..........ROOM FACILITIES........\n\n");
						printf("\nHow many free facilities are there in triple-bed room ? : ");
						scanf("%d", &tripleBedRooms.free);
						if (tripleBedRooms.free > 0)
						{
							printf("\nEnter all free facilities : \n");
							fprintf(filePtr, "\nFree Facilities: ");
							fprintf(homeHotelPtr, "\nFree Facilities: ");
							for (l = 0; l < tripleBedRooms.free; l++)
							{
								printf("%d. ", l + 1);
								fflush(stdin);
								gets(tripleBedRooms.free_Fac);
								fprintf(filePtr, "\n%d: %s", l + 1, tripleBedRooms.free_Fac);
								fprintf(homeHotelPtr, "\n%d: %s", l + 1, tripleBedRooms.free_Fac);
							}
						}
						printf("\nIs there any paid facility : \n1.Yes\t2.No\n");
						scanf("%d", &tripleBedRooms.paid_Chosen);
						if (tripleBedRooms.paid_Chosen == 1)
						{
							printf("\nHow many paid facilities are there : ");
							scanf("%d", &tripleBedRooms.num_paid);
							printf("\nEnter all paid facilities : \n");
							fprintf(filePtr, "\nPaid Facilities: ");
							fprintf(homeHotelPtr, "\nPaid Facilities: ");
							for (i = 0; i < tripleBedRooms.num_paid; i++)
							{
								printf("%d. ", i + 1);
								fflush(stdin);
								gets(tripleBedRooms.paid_Fac);
								printf("\nEnter charges of facility #0%d : ", i + 1);
								scanf("%d", &tripleBedRooms.paid_Charge);
								fprintf(filePtr, "\n%d: %s         %d", i + 1, tripleBedRooms.paid_Fac, tripleBedRooms.paid_Charge);
								fprintf(homeHotelPtr, "\n%d: %s         %d", i + 1, tripleBedRooms.paid_Fac, tripleBedRooms.paid_Charge);
							}
						}
						fprintf(filePtr, "\nAll Customer Bookings: ");
					}
				}
				fclose(filePtr);
				fclose(homeHotelPtr);
				counter = 0;
				system("cls");
				filePtr = fopen(filePath, "r");
				readingDetails(&counter, filePtr, &role);
				fclose(filePtr);
			}
		}
		// if customer login //
		else if (counter > 3 && role == '1')
		{
			int choice;
			homeFunc(&choice);
			char hotelName[50];
			if (choice == 1)
			{
				printf("\t\t\t\t\t\t\t\t\t\t**********  ROOM RESERVATION  **********\n");
				char hotelNo[3], fileHotelNo[3] = {0}, hotelEmail[50] = {0};
				int i = 0, j = 0;
				hotelBookDetails hotelBooking;
				hotelBooking.singleBedRooms = 0, hotelBooking.doubleBedRooms = 0, hotelBooking.tripleBedRooms = 0;
				printf("\n\nEnter hotel number which you want to book : ");
				fflush(stdin);
				gets(hotelNo);
				int length = strlen(hotelNo);
				filePtr = fopen("hotelAccounts.txt", "r");
				while (fgets(line, sizeof line, filePtr) != NULL)
				{
					for (i = 0; i < length; i++)
					{
						fileHotelNo[i] = line[i];
					}
					if (strcmp(fileHotelNo, hotelNo) == 0)
					{
						int lineLength = strlen(line);
						for (i = i + 1, j = 0; i < lineLength - 1; i++, j++)
						{
							hotelEmail[j] = line[i];
						}
						break;
					}
				}
				fclose(filePtr);
				strcpy(hotelBooking.hotelEmail, hotelEmail);
				printf("hotelEmail : %s", hotelEmail);
				hotelBooking.hotelEmail[j] = '\0';
				filePtr = fopen(hotelBooking.hotelEmail, "r");
				if (filePtr == NULL)
				{
					printf("\n\n-->Kindly Enter Correct E-Mail ID : ");
				}
				else
				{
					counter = 0;
					while (fgets(line, sizeof line, filePtr) != NULL)
					{
						if (counter == 5)
						{
							printf("%s", line);
							strcpy(hotelName, line);
						}
						counter++;
					}
					printf("\n\nEnter how many rooms do you want to book : ");
					scanf("%d", &hotelBooking.noOfRooms);
					printf("\n\nEnter single bed rooms : ");
					scanf("%d", &hotelBooking.singleBedRooms);
					if (hotelBooking.noOfRooms - hotelBooking.singleBedRooms > 0)
					{
						printf("\n\nEnter how many double bed rooms : ");
						scanf("%d", &hotelBooking.doubleBedRooms);
					}
					if (hotelBooking.noOfRooms - hotelBooking.singleBedRooms - hotelBooking.doubleBedRooms > 0)
					{
						printf("\n\nEnter how many triple bed rooms: ");
						scanf("%d", &hotelBooking.tripleBedRooms);
					}
					printf("\n\nFor how many days you want to book these rooms : ");
					scanf("%d", &hotelBooking.noOfDays);
					int bedRoomMatch = 0, counter = 0, priceCounter = 0, matchTime = 0, i = 0;
					float bedRoomPrice;
					fclose(filePtr);
					filePtr = fopen(hotelBooking.hotelEmail, "r");
					while (fgets(line, sizeof line, filePtr) != NULL)
					{
						char costMatch[15];
						for (i = 0; i < 15; i++)
						{
							costMatch[i] = line[i];
						}
						if (strcmp(costMatch, "Per Night Cost:") == 0)
						{
							bedRoomMatch = counter;
							break;
						}
						counter++;
					}
					fclose(filePtr);
					filePtr = fopen(hotelBooking.hotelEmail, "r");
					while (fgets(line, sizeof line, filePtr) != NULL)
					{
						if (priceCounter == bedRoomMatch + 1)
						{
							bedRoomPrice = ((float)(line[0] - '0') * 100) + ((float)(line[1] - '0') * 10) + (float)(line[2] - '0');
						}
						priceCounter++;
					}
					hotelBooking.singleBedRoomsCost = hotelBooking.singleBedRooms * bedRoomPrice * hotelBooking.noOfDays;
					counter = 0, priceCounter = 0, bedRoomMatch = 0, bedRoomPrice = 0;
					if (hotelBooking.doubleBedRooms > 0)
					{
						fclose(filePtr);
						filePtr = fopen(hotelBooking.hotelEmail, "r");
						while (fgets(line, sizeof line, filePtr) != NULL)
						{
							char costMatch[15];
							for (i = 0; i < 15; i++)
							{
								costMatch[i] = line[i];
							}
							if (strcmp(costMatch, "Per Night Cost:") == 0)
							{
								matchTime++;
								if (matchTime == 2)
								{
									bedRoomMatch = counter;
									break;
								}
							}
							counter++;
						}
						fclose(filePtr);
						filePtr = fopen(hotelBooking.hotelEmail, "r");
						while (fgets(line, sizeof line, filePtr) != NULL)
						{
							if (priceCounter == counter + 1)
							{
								bedRoomPrice = ((int)(line[0] - '0') * 100) + ((int)(line[1] - '0') * 10) + (int)(line[2] - '0');
							}
							priceCounter++;
						}
						hotelBooking.doubleBedRoomsCost = hotelBooking.doubleBedRooms * bedRoomPrice * hotelBooking.noOfDays;
					}

					if (hotelBooking.tripleBedRooms > 0)
					{
						bedRoomMatch = 0, counter = 0, priceCounter = 0, matchTime = 0, bedRoomPrice = 0;
						fclose(filePtr);
						filePtr = fopen(hotelBooking.hotelEmail, "r");
						while (fgets(line, sizeof line, filePtr) != NULL)
						{
							char costMatch[15];
							for (i = 0; i < 15; i++)
							{
								costMatch[i] = line[i];
							}
							if (strcmp(costMatch, "Per Night Cost:") == 0)
							{
								matchTime++;
								if (matchTime == 3)
								{
									bedRoomMatch = counter;
									break;
								}
							}
							counter++;
						}
						fclose(filePtr);
						filePtr = fopen(hotelBooking.hotelEmail, "r");
						while (fgets(line, sizeof line, filePtr) != NULL)
						{
							if (priceCounter == counter + 1)
							{
								bedRoomPrice = ((int)(line[0] - '0') * 100) + ((int)(line[1] - '0') * 10) + (int)(line[2] - '0');
							}
							priceCounter++;
						}
						hotelBooking.tripleBedRoomsCost = hotelBooking.tripleBedRooms * bedRoomPrice * hotelBooking.noOfDays;
					}
				}
				fclose(filePtr);
				printf("\n\n-->Enter Your Name : ");
				fflush(stdin);
				gets(hotelBooking.cusName);
				nameValid(hotelBooking.cusName);
				printf("\n\nEnter Your Phone Number : ");
				fflush(stdin);
				phoneNoValidation(hotelBooking.cusPhoneNo) ; 
				printf("\n\n-->Your Selected Details Are : ");
				printf("\nNo Of Rooms You Have Booked : %d", hotelBooking.noOfRooms);
				printf("\nNo Of Days : %d", hotelBooking.noOfDays);
				if (hotelBooking.singleBedRooms > 0)
				{
					printf("\nNo Of Single Bed Rooms : %d", hotelBooking.singleBedRooms);
					printf("\nSingle Bed Rooms Cost : %.2f", hotelBooking.singleBedRoomsCost);
				}
				if (hotelBooking.doubleBedRooms > 0)
				{
					printf("\nNo Of Double Bed Rooms: %d", hotelBooking.doubleBedRooms);
					printf("\nDouble Bed Rooms Cost: %.2f", hotelBooking.doubleBedRoomsCost);
				}
				if (hotelBooking.tripleBedRooms > 0)
				{
					printf("\nNo Of Triple Bed Rooms: %d", hotelBooking.tripleBedRooms);
					printf("\nTriple Bed Rooms Cost: %.2f", hotelBooking.tripleBedRoomsCost);
				}
				hotelBooking.totalCost = hotelBooking.singleBedRoomsCost + hotelBooking.doubleBedRoomsCost + hotelBooking.tripleBedRoomsCost;
				printf("\n\nTotal Cost: %.2f", hotelBooking.totalCost);
				
				confirmDetails() ;
				printf("\n-->Proceed to Payment Method (yes or no) : ");
				char paymentMethodChoice[50];
				fflush(stdin);
				gets(paymentMethodChoice);
				if (strcmp(paymentMethodChoice, "yes") == 0)
				{
					system("cls");
					printf("\nWhat payment method will you prefer(cash or card): ");
					fflush(stdin);
					gets(hotelBooking.paymentMethod);
					time_t t = time(NULL);
					struct tm tm = *localtime(&t);
					char preHotelMatch[30];
					int i, hotelMatch = 0;
					filePtr = fopen(filePath, "r");
					FILE *hotelFilePtr = fopen(hotelBooking.hotelEmail, "a");
					while (fgets(line, sizeof line, filePtr) != NULL)
					{
						for (i = 0; i < 30; i++)
						{
							preHotelMatch[i] = line[i];
						}
						if (strcmp(preHotelMatch, "Previous Hotel Booking Details") == 0)
						{
							hotelMatch = 1;
						}
					}
					fclose(filePtr);
					filePtr = fopen(filePath, "a");
					if (hotelMatch == 0)
					{
						fprintf(filePtr, "\nPrevious Hotel Booking Details: ");
					}

					fprintf(filePtr, "\n\nHotel Name: %s", hotelName);
					fprintf(hotelFilePtr, "\nHotel Name : %s", hotelName);
					fprintf(filePtr, "No Of Days: %d", hotelBooking.noOfDays);
					fprintf(hotelFilePtr, "No Of Days: %d", hotelBooking.noOfDays);
					fprintf(filePtr, "\nNo Of Rooms: %d", hotelBooking.noOfRooms);
					fprintf(hotelFilePtr, "\nNo Of Rooms: %d", hotelBooking.noOfRooms);
					if (hotelBooking.singleBedRooms > 0)
					{
						fprintf(filePtr, "\nSingle Bed Rooms: %d", hotelBooking.singleBedRooms);
						fprintf(filePtr, "\nSingle Bed Rooms Cost: %.0f", hotelBooking.singleBedRoomsCost);
						fprintf(hotelFilePtr, "\nSingle Bed Rooms: %d", hotelBooking.singleBedRooms);
						fprintf(hotelFilePtr, "\nSingle Bed Rooms Cost: %.0f", hotelBooking.singleBedRoomsCost);
					}
					if (hotelBooking.doubleBedRooms > 0)
					{
						fprintf(filePtr, "\nDouble Bed Rooms:%d", hotelBooking.doubleBedRooms);
						fprintf(filePtr, "\nDoule Bed Rooms Cost:%.0f", hotelBooking.doubleBedRoomsCost);
						fprintf(hotelFilePtr, "\nDouble Bed Rooms:%d", hotelBooking.doubleBedRooms);
						fprintf(hotelFilePtr, "\nDoule Bed Rooms Cost:%.0f", hotelBooking.doubleBedRoomsCost);
					}
					if (hotelBooking.tripleBedRooms > 0)
					{
						fprintf(filePtr, "\nTriple Bed Rooms:%d", hotelBooking.tripleBedRooms);
						fprintf(filePtr, "\nTriple Bed Rooms Cost:%.0f", hotelBooking.tripleBedRoomsCost);
						fprintf(hotelFilePtr, "\nTriple Bed Rooms:%d", hotelBooking.tripleBedRooms);
						fprintf(hotelFilePtr, "\nTriple Bed Rooms Cost:%.0f", hotelBooking.tripleBedRoomsCost);
					}
					fprintf(filePtr, "\nTotal Cost: %.0f", hotelBooking.totalCost);
					fprintf(filePtr, "\nCustomer Name: %s", hotelBooking.cusName);
					fprintf(filePtr, "\nCustomer Phone No: %s", hotelBooking.cusPhoneNo);
					fprintf(filePtr, "\nBooking Date: %d-%02d-%02d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
					fprintf(filePtr, "\nPayment Method: %s", hotelBooking.paymentMethod);
					fprintf(hotelFilePtr, "\nTotal Cost: %.0f", hotelBooking.totalCost);
					fprintf(hotelFilePtr, "\nBooking Date: %d-%02d-%02d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
					fprintf(hotelFilePtr, "\nPayment Method: %s", hotelBooking.paymentMethod);
					if (strcmp(hotelBooking.paymentMethod, "card") == 0)
					{
						printf("\n\n-->Enter Your Card Details : ");
						printf("\nEnter Your Card No : ");
						int *creditCardNo = creditCardValid();
						printf("\nName On Card : ");
						fflush(stdin);
						gets(hotelBooking.card.nameOnCard);
						nameValid(hotelBooking.card.nameOnCard);
						fflush(stdin);
						while (1)
						{
							printf("\n-->Input expiry Date in day-month-year fromat : ");
							scanf("%d-%d-%d", &hotelBooking.card.date.day, &hotelBooking.card.date.month, &hotelBooking.card.date.year);

							if (hotelBooking.card.date.year >= 1900 && hotelBooking.card.date.year <= 3000)
							{

								if (hotelBooking.card.date.month >= 1 && hotelBooking.card.date.month <= 12)
								{
									if ((hotelBooking.card.date.day >= 1 && hotelBooking.card.date.day <= 31) && (hotelBooking.card.date.month == 1 || hotelBooking.card.date.month == 3 || hotelBooking.card.date.month == 5 || hotelBooking.card.date.month == 7 || hotelBooking.card.date.month == 8 || hotelBooking.card.date.month == 10 || hotelBooking.card.date.month == 12))
										break;

									else if ((hotelBooking.card.date.day >= 1 && hotelBooking.card.date.day <= 30) && (hotelBooking.card.date.month == 4 || hotelBooking.card.date.month == 6 || hotelBooking.card.date.month == 9 || hotelBooking.card.date.month == 11))
										break;

									else if ((hotelBooking.card.date.day >= 1 && hotelBooking.card.date.day <= 28) && (hotelBooking.card.date.month == 2))
										break;

									else if (hotelBooking.card.date.day == 29 && hotelBooking.card.date.month == 2 && (hotelBooking.card.date.year % 400 == 0 || (hotelBooking.card.date.year % 4 == 0 && hotelBooking.card.date.year % 100 != 0)))
										break;

									else
										printf("\nYou have input Invalid date :\n");
								}
								else
								{
									printf("\nYou have Input Invalid date :\n");
								}
							}
							else
							{
								printf("\nYou have Input invalid date :\n");
							}
						}
						printf("\nEnter Card CVV : ");
						fflush(stdin);
						scanf("%d", &hotelBooking.card.cvv);
						fprintf(filePtr, "\nCard Details: ");
						fprintf(filePtr, "\nCard No : ");
						for (i = 0; i < 16; i++)
						{
							fprintf(filePtr, "%d", creditCardNo[i]);
						}
						fprintf(filePtr, "\nName on Card: %s", hotelBooking.card.nameOnCard);
						fprintf(filePtr, "\nExpire Date: %d-%d-%d", hotelBooking.card.date.day, hotelBooking.card.date.month, hotelBooking.card.date.year);
						fprintf(filePtr, "\nCvv: %d", hotelBooking.card.cvv);
						fprintf(hotelFilePtr, "\nCard Details: ");
						fprintf(hotelFilePtr, "\nCard No : ");
						for (i = 0; i < 16; i++)
						{
							fprintf(filePtr, "%d", creditCardNo[i]);
						}
						fprintf(hotelFilePtr, "\nName on Card: %s", hotelBooking.card.nameOnCard);
						fprintf(hotelFilePtr, "\nExpire Date: %d-%d-%d", hotelBooking.card.date.day, hotelBooking.card.date.month, hotelBooking.card.date.year);
						fprintf(hotelFilePtr, "\nCvv: %d", hotelBooking.card.cvv);
					}
					fclose(filePtr);
					fclose(hotelFilePtr);
				}
			}
			else if (choice == '2')
			{
				printf("\t\t\t\t\t\t\t\t\t\t**********  ORDER FOOD  **********\n");
				char resNo[3], line[50], fileResNo[3] = {0}, resEmail[50] = {0}, resName[50], fileDishName[50] = {0};
				resOrderDetails resOrder;
				int i, j;
				printf("\n\nEnter Restaurant Number From Which You Want To Order : ");
				fflush(stdin);
				gets(resNo);
				int length = strlen(resNo);
				filePtr = fopen("restaurantAccounts.txt", "r");
				while (fgets(line, sizeof line, filePtr) != NULL)
				{
					for (i = 0; i < length; i++)
					{
						fileResNo[i] = line[i];
					}
					if (strcmp(fileResNo, resNo) == 0)
					{

						int lineLength = strlen(line);
						for (i = i + 1, j = 0; i < lineLength; i++, j++)
						{
							resEmail[j] = line[i];
						}
						break;
					}
				}
				fclose(filePtr);
				resEmail[j] = '\0', resEmail[j - 1] = '\0';
				strcpy(resOrder.resEmail, resEmail);
				filePtr = fopen(resOrder.resEmail, "r");
				if (filePtr == NULL)
				{
					printf("\n-->Kindly Enter Correct Restaurant Number : ");
				}
				else
				{
					counter = 0;
					while (fgets(line, sizeof line, filePtr) != NULL)
					{
						if (counter == 5)
						{
							printf("%s", line);
							strcpy(resName, line);
						}
						counter++;
					}
					fclose(filePtr);
					printf("\n\nEnter how many dishes you want to order : ");
					int dishesNo;
					scanf("%d", &dishesNo);
					dishDetails dishes[dishesNo];
					for (i = 0; i < dishesNo; i++)
					{
						int dishMatch = 0;
						while (dishMatch == 0)
						{
							printf("\nEnter dish %d name: ", i + 1);
							fflush(stdin);
							gets(dishes[i].name);
							int dishLength = strlen(dishes[i].name);
							filePtr = fopen(resOrder.resEmail, "r");
							while (fgets(line, sizeof line, filePtr) != NULL)
							{
								int lineLength = strlen(line), k;
								for (j = 0, k = 3; j < dishLength; j++, k++)
								{
									fileDishName[j] = line[k];
								}
								if (strcmp(fileDishName, dishes[i].name) == 0)
								{
									dishMatch = 1;
								}
								if (dishMatch == 1)
								{

									float dishPrice = ((float)(line[2 + dishLength + 2] - '0') * 100) +
									((float)(line[2 + dishLength + 3] - '0') * 10) +
										((float)(line[2 + dishLength + 4] - '0'));
									printf("\nEnter how many quantity for %s : ", dishes[i].name);
									scanf("%d", &dishes[i].quantity);
									dishes[i].price = dishPrice * dishes[i].quantity;
									resOrder.totalPrice = resOrder.totalPrice + dishes[i].price;
									break;
								}
							}
							fclose(filePtr);
							for (j = 0; j < dishLength; j++)
							{
								fileDishName[j] = '\0';
							}
							if (dishMatch == 0)
							{
								printf("\nPlease enter correct dish name: ");
							}
						}
					}
					printf("\n\nEnter Your Name : ");
					fflush(stdin);
					gets(resOrder.cusName);
					nameValid(resOrder.cusName);
					printf("\nEnter Your Phone Number : ");
					fflush(stdin);
					phoneNoValidation(resOrder.cusPhoneNo) ; 
			
					confirmDetails() ;
					printf("\nYour Details Are : ");
					printf("\nDishes : ");
					for (i = 0; i < dishesNo; i++)
					{
						printf("\n%s", dishes[i].name);
						printf("\nQuantity: %d", dishes[i].quantity);
						printf("\nPrice: %.2f", dishes[i].price);
					}
					printf("\nTotal Price: %.0f", resOrder.totalPrice);
					printf("\nName: %s", resOrder.cusName);
					printf("\nPhone No: %s", resOrder.cusPhoneNo);
					printf("\nProceed to Payment Method (yes or no): ");
					char paymentMethodChoice[50];
					fflush(stdin);
					gets(paymentMethodChoice);
					if (strcmp(paymentMethodChoice, "yes") == 0)
					{
						system("cls");
						printf("\nWhat payment method will you prefer(cash or card): ");
						fflush(stdin);
						gets(resOrder.paymentMethod);
						time_t t = time(NULL);
						struct tm tm = *localtime(&t);
						char preResMatch[40];
						int resMatch = 0;
						filePtr = fopen(filePath, "r");
						while (fgets(line, sizeof line, filePtr) != NULL)
						{
							for (i = 0; i < strlen("Previous Restaurants Order Details"); i++)
							{
								preResMatch[i] = line[i];
							}
							if (strcmp(preResMatch, "Previous Restaurants Order Details") == 0)
							{
								resMatch = 1;
								break;
							}
						}
						fclose(filePtr);
						filePtr = fopen(filePath, "a");
						FILE *resFilePtr = fopen(resOrder.resEmail, "a");
						if (resMatch == 0)
						{
							fprintf(filePtr, "\n\nPrevious Restaurants Order Details: ");
						}
						fprintf(filePtr, "\nRestaurant Name: %s", resName);
						fprintf(filePtr, "\nDishes Details: ");
						for (i = 0; i < dishesNo; i++)
						{
							fprintf(filePtr, "\nDish %d", i + 1);
							fprintf(filePtr, "\nName: %s", dishes[i].name);
							fprintf(filePtr, "\nQuantity: %d", dishes[i].quantity);
							fprintf(filePtr, "\nPrice: %.0f", dishes[i].price);
						}
						fprintf(filePtr, "\nTotal Price: %.0f", resOrder.totalPrice);
						fprintf(filePtr, "\nCustomer Name: %s", resOrder.cusName);
						fprintf(filePtr, "\nCustomer Phone No: %s", resOrder.cusPhoneNo);
						fprintf(filePtr, "\nOrder Date: %d-%02d-%02d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
						fprintf(filePtr, "\nPayment Method: %s", resOrder.paymentMethod);
						fprintf(resFilePtr, "\nCustomer Name: %s", resOrder.cusName);
						fprintf(resFilePtr, "\nCustomer Phone No: %s", resOrder.cusPhoneNo);
						fprintf(resFilePtr, "\nOrder Date: %d-%02d-%02d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
						fprintf(resFilePtr, "\nDishes Details: ");
						for (i = 0; i < dishesNo; i++)
						{
							fprintf(resFilePtr, "\nDish %d", i + 1);
							fprintf(resFilePtr, "\nName: %s", dishes[i].name);
							fprintf(resFilePtr, "\nQuantity: %d", dishes[i].quantity);
							fprintf(resFilePtr, "\nPrice: %.0f", dishes[i].price);
						}
						fprintf(resFilePtr, "\nTotal Price: %.0f", resOrder.totalPrice);
						fprintf(resFilePtr, "\nPayment Method: %s", resOrder.paymentMethod);
						if (strcmp(resOrder.paymentMethod, "card") == 0)
						{
							printf("\n\nCard Details: ");
							printf("\nCard No: \n");
							int *creditCardNo = creditCardValid();
							printf("\nName on Card: ");
							fflush(stdin);
							gets(resOrder.card.nameOnCard);
							nameValid(resOrder.card.nameOnCard);
							fflush(stdin);
							while (1)
							{
								printf("\n-->Input expiry Date in day-month-year fromat : ");
								scanf("%d-%d-%d", &resOrder.card.date.day, &resOrder.card.date.month, &resOrder.card.date.year);

								if (resOrder.card.date.year >= 1900 && resOrder.card.date.year <= 3000)
								{

									if (resOrder.card.date.month >= 1 && resOrder.card.date.month <= 12)
									{
										if ((resOrder.card.date.day >= 1 && resOrder.card.date.day <= 31) && (resOrder.card.date.month == 1 || resOrder.card.date.month == 3 || resOrder.card.date.month == 5 || resOrder.card.date.month == 7 || resOrder.card.date.month == 8 || resOrder.card.date.month == 10 || resOrder.card.date.month == 12))
											break;

										else if ((resOrder.card.date.day >= 1 && resOrder.card.date.day <= 30) && (resOrder.card.date.month == 4 || resOrder.card.date.month == 6 || resOrder.card.date.month == 9 || resOrder.card.date.month == 11))
											break;

										else if ((resOrder.card.date.day >= 1 && resOrder.card.date.day <= 28) && (resOrder.card.date.month == 2))
											break;

										else if (resOrder.card.date.day == 29 && resOrder.card.date.month == 2 && (resOrder.card.date.year % 400 == 0 || (resOrder.card.date.year % 4 == 0 && resOrder.card.date.year % 100 != 0)))
											break;

										else
											printf("\nYou have input Invalid date :\n");
									}
									else
									{
										printf("\nYou have Input Invalid date :\n");
									}
								}
								else
								{
									printf("\nYou have Input invalid date :\n");
								}
							}
							printf("\nEnter Card CVV : ");
							fflush(stdin);
							scanf("%d", &resOrder.card.cvv);
							fprintf(filePtr, "\nCard Details: ");
							fprintf(filePtr, "\nCard No : ");
							for (i = 0; i < 16; i++)
							{
								fprintf(filePtr, "%d", creditCardNo[i]);
							}
							fprintf(filePtr, "\nName on Card: %s", resOrder.card.nameOnCard);
							fprintf(filePtr, "\nExpire Date: %d-%d-%d", resOrder.card.date.day, resOrder.card.date.month, resOrder.card.date.year);
							fprintf(filePtr, "\nCvv: %d", resOrder.card.cvv);
							fprintf(resFilePtr, "\nCard Details: ");
							fprintf(resFilePtr, "\nCard No : ");
							for (i = 0; i < 16; i++)
							{
								fprintf(resFilePtr, "%d", creditCardNo[i]);
							}
							fprintf(resFilePtr, "\nName on Card: %s", resOrder.card.nameOnCard);
							fprintf(resFilePtr, "\nExpire Date: %d-%d-%d", resOrder.card.date.day, resOrder.card.date.month, resOrder.card.date.year);
							fprintf(resFilePtr, "\nCvv: %d", resOrder.card.cvv);
						}
						fclose(filePtr), fclose(resFilePtr);
					}
				}
				filePtr = fopen(filePath, "r");
				readingCustomer(&counter, filePtr, &role);
				fclose(filePtr);
			}
		}
		// if admin login //
		else if (counter > 3 && role == '4')
		{
			printf("\t\t\t\t\t\t\t\t\t\t**********  ADMIN LOGIN  **********\n");
			printf("\n-->Hotel Accounts : \n");
			filePtr = fopen("hotelAccounts.txt", "r");
			while (fgets(line, sizeof line, filePtr) != NULL)
			{
				printf("%s", line);
			}
			fclose(filePtr);
			printf("\n\n-->Restaurant Accounts: \n");
			filePtr = fopen("restaurantAccounts.txt", "r");
			while (fgets(line, sizeof line, filePtr) != NULL)
			{
				printf("%s", line);
			}
			fclose(filePtr);
			printf("\n-->Which hotel/restaurant account you want to remove : ");
			char toBeRemove[50];
			fflush(stdin);
			gets(toBeRemove);
			strcat(toBeRemove, ".txt");
			int accountMatch = 0;
			int filePathIndex = 0, i, j;
			char fileData[100][50];
			filePtr = fopen("restaurantAccounts.txt", "r");
			while (fgets(line, sizeof toBeRemove + 2, filePtr) != NULL)
			{
				char temp[50];
				for (i = 2, j = 0; i < strlen(toBeRemove) + 2; j++, i++)
				{
					temp[j] = line[i];
				}
				if (strcmp(temp, toBeRemove) == 0)
				{
					printf("yes!");
					accountMatch = 1;
					break;
				}
				filePathIndex++;
			}
			fclose(filePtr);
			i = 0, j = 0;
			if (accountMatch == 1)
			{
				filePtr = fopen("restaurantAccounts.txt", "r");
				while (fgets(line, sizeof line, filePtr) != NULL)
				{
					strcpy(fileData[i], line);
					if (j < 1 && i == filePathIndex)
					{
						i--;
						j++;
					}
					i++;
				}
				fclose(filePtr);
				filePtr = fopen("restaurantAccounts.txt", "w");
				for (j = 0; j < i; j++)
				{
					fprintf(filePtr, "%s", fileData[j]);
				}
				fclose(filePtr);
				filePtr = fopen(toBeRemove, "r");
				char resName[50] = {0};
				int resNamePos = 5, linesOfData = 0, cusOrderTextMatch = 0;
				char cusOrderText[] = "All Customer Orders";
				i = 0;
				while (fgets(line, sizeof line, filePtr) != NULL)
				{
					if (i == resNamePos)
					{
						for (j = 0; line[j] != '\n'; j++)
						{
							resName[j] = line[j];
						}
					}
					i++;
					cusOrderTextMatch = 0;
					for (j = 0; j < strlen(cusOrderText); j++)
					{
						if (line[j] == cusOrderText[j])
						{
							cusOrderTextMatch++;
						}
					}
					if (cusOrderTextMatch != strlen(cusOrderText))
					{
						printf("\ncusOrderTextMatch : %d , length : %d", cusOrderTextMatch, strlen(cusOrderText));
						linesOfData++;
					}

					if (cusOrderTextMatch == strlen(cusOrderText))
					{
						printf("\nyes!");
						printf("\nlines of data : %d", linesOfData);
						break;
					}
				}
				printf("\nresName: %s , length: %d,  linesOfData: %d", resName, strlen(resName), linesOfData);
				fclose(filePtr);
				i = 0;
				int resNamePosInHome = 0;
				filePtr = fopen("home page.txt", "r");
				while (fgets(line, sizeof line, filePtr) != NULL)
				{
					char temp[50] = {0};
					for (i = 0; i < strlen(resName); i++)
					{
						temp[i] = line[i];
					}
					printf("\nres Name in file: %s\n , length: %d", temp, strlen(temp));
					if (strcmp(temp, resName) == 0)
					{
						break;
					}
					resNamePosInHome++;
				}
				fclose(filePtr);
				printf("\nresNamePos: %d", resNamePosInHome);
				i = 0;
				filePtr = fopen("home page.txt", "r");
				j = 0;
				while (fgets(line, sizeof line, filePtr) != NULL)
				{
					strcpy(fileData[i], line);
					if (j < linesOfData - 4 && i >= resNamePosInHome && i < resNamePosInHome + (linesOfData - 4))
					{
						i--;
						j++;
					}
					i++;
				}
				fclose(filePtr);
				printf("\nvalue of i: %d", i);
				for (j = 0; j < i; j++)
				{
					printf("%s", fileData[j]);
				}
				filePtr = fopen("home page.txt", "w");
				for (j = 0; j < i; j++)
				{
					fprintf(filePtr, "%s", fileData[j]);
				}
				fclose(filePtr);
			}

			if (accountMatch == 0)
			{
				filePathIndex = 0, i = 0, j = 0;
				filePtr = fopen("hotelAccounts.txt", "r");
				while (fgets(line, sizeof toBeRemove + 2, filePtr) != NULL)
				{
					char temp[50] = {0};
					for (i = 2, j = 0; i < strlen(toBeRemove) + 2; j++, i++)
					{
						temp[j] = line[i];
					}
					printf("\nhotel File: %s", temp);
					if (strcmp(temp, toBeRemove) == 0)
					{
						printf("yes!");
						accountMatch = 1;
						break;
					}
					filePathIndex++;
				}
				fclose(filePtr);
				i = 0, j = 0;
				if (accountMatch == 1)
				{
					filePtr = fopen("hotelAccounts.txt", "r");
					while (fgets(line, sizeof line, filePtr) != NULL)
					{
						strcpy(fileData[i], line);
						if (j < 1 && i == filePathIndex)
						{
							i--;
							j++;
						}
						i++;
					}
					fclose(filePtr);
					filePtr = fopen("hotelAccounts.txt", "w");
					for (j = 0; j < i; j++)
					{
						fprintf(filePtr, "%s", fileData[j]);
					}
					fclose(filePtr);
					filePtr = fopen(toBeRemove, "r");
					char hotelName[50] = {0};
					int hotelNamePos = 5, linesOfData = 0, cusBookTextMatch = 0;
					i = 0;
					char cusBookText[] = "All Customer Bookings";
					while (fgets(line, sizeof line, filePtr) != NULL)
					{
						if (i == hotelNamePos)
						{
							for (j = 0; line[j] != '\n'; j++)
							{
								hotelName[j] = line[j];
							}
						}
						i++;
						cusBookTextMatch = 0;
						for (j = 0; j < strlen(cusBookText); j++)
						{
							if (cusBookText[j] == line[j])
							{
								cusBookTextMatch++;
							}
						}
						if (cusBookTextMatch != strlen(cusBookText))
						{
							linesOfData++;
						}
						if (cusBookTextMatch == strlen(cusBookText))
						{
							break;
						}
					}
					printf("\nresName: %s , length: %d,  linesOfData: %d", hotelName, strlen(hotelName), linesOfData);
					fclose(filePtr);
					i = 0;
					int hotelNamePosInHome = 0;
					filePtr = fopen("home page hotels.txt", "r");
					while (fgets(line, sizeof line, filePtr) != NULL)
					{
						char temp[50] = {0};
						for (i = 0; i < strlen(hotelName); i++)
						{
							temp[i] = line[i];
						}
						printf("res Name in file: %s\n , length: %d", temp, strlen(temp));
						if (strcmp(temp, hotelName) == 0)
						{
							break;
						}
						hotelNamePosInHome++;
					}
					fclose(filePtr);
					printf("\nresNamePos: %d", hotelNamePosInHome);
					i = 0;
					filePtr = fopen("home page hotels.txt", "r");
					j = 0;
					while (fgets(line, sizeof line, filePtr) != NULL)
					{
						strcpy(fileData[i], line);
						if (j < linesOfData - 4 && i >= hotelNamePosInHome - 1 && i < hotelNamePosInHome + (linesOfData - 4))
						{
							i--;
							j++;
						}
						i++;
					}
					fclose(filePtr);
					printf("\nvalue of i: %d", i);
					for (j = 0; j < i; j++)
					{
						printf("%s", fileData[j]);
					}
					filePtr = fopen("home page hotels.txt", "w");
					for (j = 0; j < i; j++)
					{
						fprintf(filePtr, "%s", fileData[j]);
					}
					fclose(filePtr);
				}
			}
			printf("\nfileToBeRemove: %s", toBeRemove);
			if (remove(toBeRemove) == 0)
			{
				printf("\nRemoved Successfully");
			}
			else
			{
				perror("\nError! ");
			}
		}
	}
	system("cls");
	main();
}

void confirmDetails(){
		int count = 0;
	int seconds =0; char confirm;
	printf("\n-->Confirm your order?\n(y for yes and n for no) : ");
	fflush(stdin);
	scanf("%c", &confirm);
	while(1)
	{
	if(confirm != 'y' && confirm != 'Y' && confirm != 'n' && confirm != 'Y' )
	{
		printf("-->\nInvalid input..\n");
	}
	else if(confirm == 'y' || confirm == 'Y')
	{
		break;
	}
	else if(confirm == 'n' || confirm == 'N')
	{
		printf("\n-->You have 1 minutes for confirm your order(you will answer after one minute)\n");
//		int minute =01 ;
    while (count != 60)
    {
//    printf("%d : %d\t", minute , seconds);
    sleep(1);
    count++;
//    seconds++;
	}
	break;
}
}
	printf("\n-->Confirm your order?\n(y for yes and n for no):");
	fflush(stdin);
	scanf("%c", &confirm);
	while(1)
	{
	if(confirm != 'y' && confirm != 'Y' && confirm != 'n' && confirm != 'Y' )
	{
		printf("Invalid input..\n");
	}
	else if(confirm == 'y' || confirm == 'Y')
	{
		break;
	}
	else if(confirm == 'n' || confirm == 'N')
	{
		printf("\n-->Your order has been cancelled..\n");
		main();
    }
}
}
int signUpFunc()
{
	printf("\t\t\t\t\t\t\t\t\t\t**********  SIGN UP PAGE  **********\n");
	char role;
	char Name[20], email[30] = {0}, line[50];
	char filePath[50];
	printf("\n-->Enter Your Role \n\n1.Customer\n2.Restaurant Owner\n3.Hotel Owner");
	printf("\n\n-->Enter Your Choice : ");
	fflush(stdin);
	scanf("%c", &role);
	printf("\nEnter User Name : ");
	fflush(stdin);
	gets(Name);
	char *emailPtr = vemail();
	int counter = 0;
	while (*emailPtr != '\0')
	{
		email[counter] = *emailPtr;
		emailPtr++, counter++;
	}
	char password[16], cPassword[16], confirm[16];
	while (1)
	{
		printf("\nCreate Your Password : ");
		fflush(stdin);
		hide_pass(password);
		bool result = password_verify(password);
		if (result)
		{
			while (1)
			{
				printf("\nConfirm Your Password : ");
				hide_pass(cPassword);
				int x;
				x = strcmp(password, cPassword);
				if (x > 0 || x < 0)
				{
					printf("\n-->Kindly Enter The Same Password : \n");
					continue;
				}
				else
				{
					printf("\n-->Your Account Has Been Created Successfully !");
					printf("\n-->Press Any Key To Log-In Your Account \n");
					getch();
					encrypted_pass(password);
					system("cls");
					FILE *fPtr;
					FILE *accountFPtr;
					counter = 0;
					strcpy(filePath, email);
					strcat(filePath, ".txt");
					fPtr = fopen(filePath, "a");
					fprintf(fPtr, "%s\n", password);
					fprintf(fPtr, "%c\n", role);
					fprintf(fPtr, "%s\n", email);
					fprintf(fPtr, "%s\n", Name);
					fclose(fPtr);
					if (role == '2')
					{
						accountFPtr = fopen("restaurantAccounts.txt", "r");
						int accountNoMax = 0;
						while (fgets(line, sizeof line, accountFPtr) != NULL)
						{
							int accountNo = (int)(line[0] - '0');
							if (accountNo > accountNoMax)
							{
								accountNoMax = accountNo;
							}
						}
						fclose(accountFPtr);
						accountFPtr = fopen("restaurantAccounts.txt", "a");
						fprintf(accountFPtr, "%d:%s\n", accountNoMax + 1, filePath);
					}
					else if (role == '3')
					{
						accountFPtr = fopen("hotelAccounts.txt", "r");
						int accountNoMax = 0;
						while (fgets(line, sizeof line, accountFPtr) != NULL)
						{
							int accountNo = (int)(line[0] - '0');
							if (accountNo > accountNoMax)
							{
								accountNoMax = accountNo;
							}
						}
						fclose(accountFPtr);
						accountFPtr = fopen("hotelAccounts.txt", "a");
						fprintf(accountFPtr, "%d:%s\n", accountNoMax + 1, filePath);
					}
					fclose(accountFPtr);
					main();
					break;
				}
			}
			break;
		}
		else
		{
			printf("\n-->Your Password Should Meet The Above Mentioned Criteria \n");
			continue;
		}
	}

	return 0;
}
int logInFunc()
{
	printf("\t\t\t\t\t\t\t\t\t\t**********LOGIN PAGE**********\n");
	int logInSuccess = 0;
	while (logInSuccess == 0)
	{
		char email[50] = {0};
		char password[50];
		printf("\nEnter Your E-mail : ");
		fflush(stdin);
		gets(email);
		FILE *fPtr;
		char filePath[50];
		strcpy(filePath, email);
		strcat(filePath, ".txt");
		fPtr = fopen(filePath, "r");
		if (fPtr == NULL)
		{
			perror("\n-->Could'nt Find Your account :(");
		}
		else
		{
			printf("\nEnter Your Password : ");
			hide_pass(password);
			int length = strlen(password);
			char filePass[length + 1];
			fgets(filePass, sizeof(filePass), fPtr);
			decrypted_pass(filePass);
			int match = strcmp(password, filePass);
			if (match == 0)
			{
				logInSuccess = 1;
				printf("\n-->You Have Successfully Log-In To Your Account ");
				fclose(fPtr);
				printf("\n-->Press Any Key To Continue.");
				getch();
				fPtr = fopen("currently login.txt", "w");
				fprintf(fPtr, "%s", filePath);
				fclose(fPtr);

				profile(filePath);
			}
			else
			{
				printf("\n-->Your Password Is Incorrect ! ");
				fclose(fPtr);
			}
		}
	}
	return 0;
}
bool password_verify(char *password)
{
	int length = strlen(password);
	if (length < 8 || length > 16)
		return false;
	bool has_upper = false;
	bool has_lower = false;
	bool has_digit = false;
	bool has_symbol = false;
	int i;
	for (i = 0; i < length; i++)
	{
		if (isupper(password[i]))
			has_upper = true;
		if (islower(password[i]))
			has_lower = true;
		if (isdigit(password[i]))
			has_digit = true;
		if (ispunct(password[i]))
			has_symbol = true;
	}
	if (!has_upper)
		return false;
	if (!has_lower)
		return false;
	if (!has_digit)
		return false;
	if (!has_symbol)
		return false;
	return true;
}

char *vemail()
{
	char email[50];
	char *ptrEmail = email;
	FILE *fPtr;
	int counter, alpha = 0, dot = 0;
	printf("\n-->Enter Your E-Mail ID : ");
	fflush(stdin);
	gets(email);
	char filePath[50];
	strcpy(filePath, email);
	strcat(filePath, ".txt");
	fPtr = fopen(filePath, "r");
	if (fPtr != NULL)
	{
		printf("\n-->Your Account Already Exists !");
		vemail();
	}
	else
	{
		do
		{
			for (counter = 0; email[counter] != '\0'; counter++)
			{
				if (email[counter] == '@')
					alpha = counter;
				if (email[counter] == '.')
					dot = counter;
			}
			if (alpha > 2 && (dot - alpha) > 3)
			{
				printf("\nYour E-Mail Is Verified ! \n");

				return ptrEmail;
			}

			else
			{
				//printf("\nInvalid E-mail\n");
				printf("\nEnter A Valid E-Mail ID : ");
				scanf("%s", &email);
			}
		} while (alpha < 2 && (dot - alpha) < 3);
	}
}
