#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h> 

struct user{
	char name[10];
	char username[10];
	char password[10];
	char accType[10];
};

void delay(int number_of_seconds) 
{ 
    int milli_seconds = 1000 * number_of_seconds; 
    clock_t start_time = clock();  
    while (clock() < start_time + milli_seconds); 
} 

void write_user(){
	
	struct user u;
	
	printf("\t\t\t\t\t\tName: ");
	scanf("%s", u.name);
	printf("\t\t\t\t\t\tUsername: ");
	scanf("%s", u.username);
	printf("\t\t\t\t\t\tPassword: ");
	scanf("%s", u.password);
	
	FILE *fusers = NULL;
	fusers = fopen("Users/Users.txt", "a");
	
	if(fusers == NULL){
		return;
	}
	
	fprintf(fusers, "%10s %10s %10s\n", u.name, u.username, u.password);
	printf("\t\t\t\t\tUser added with success!\n");
	fclose(fusers);
}

int login(){
	
	struct user u;
	
	strcpy(u.username, "admin");
	strcpy(u.password, "pw");
	strcpy(u.accType, "administrator");
	
	char un[10];
	char pw[10];
	
	start:
	
	system("cls");
	
	printf("\n\n\n\n\n\n\n\n");
	printf("\t\t\t\t\t\tUsername: ");
	scanf("%s", un);
	printf("\t\t\t\t\t\tPassword: ");
	scanf("%s", pw);
	
	if((strcmp(un, u.username) == 0) && (strcmp(pw, u.password) == 0)){
		printf("\t\t\t\t\t\tSuccessful Login!\n");
		printf("\t\t\t\t\t\t      ");
		if((strcmp(u.accType, "administrator") == 0)){
			for (int i = 0; i < 3; i++) { 
        		delay(1);
				printf(".");
    		}
    		return 1;
		}
		if((strcmp(u.accType, "employer") == 0)){
			for (int i = 0; i < 3; i++) { 
        		delay(1);
				printf(".");
    		}
    		return 2;
		}
	}	
	else{
		printf("\t\t\t\t\tUsername or Password incorrect!\n");
		system("pause");
		system("cls");
		goto start;
		return 0;
	}
	
	
}

int main() {
	struct user u;
	
	int op;
	
	strcpy(u.name, "Saraiva");
	strcpy(u.accType, "admin");
	
	if(login() == 1){
		startadmin:
			
		system("cls");
		
		printf("%100s Welcome\n");
		printf("\n\n\n\n\n\n\n\n");
		printf("\t\t\t\t\t\t   Admin Menu\n");
		printf("\t\t\t\t\t\t1 - Create User\n");
		printf("\t\t\t\t\t\t2 - Delete User\n");
		printf("\t\t\t\t\t\t3 - Loans\n");
		printf("\t\t\t\t\t\t4 - Exit\n");
		printf("\t\t\t\t\t\t-> ");
		scanf("%d", &op);
		
		switch(op){
		case 1:
			system("cls");
			write_user();
			system("pause");
			system("cls");
			goto startadmin;
		case 2:
			system("cls");
			system("pause");
			system("cls");
			goto startadmin;
		case 3:
			system("cls");
			system("pause");
			system("cls");
			goto startadmin;
		case 4:
			goto fim;
		default:
			system("cls");
			printf("Erro 404\n");
			system("pause");
			system("cls");
			goto startadmin;
		}
	}
	if(login() == 2){
		
		startemployee:
			
		system("cls");
		
		printf("%100s, Welcome\n", u.name);
		printf("\n\n\n\n\n\n\n\n");
		printf("\t\t\t\t\t\t Employee Menu\n");
		printf("\t\t\t\t\t\t1 - Create Client\n");
		printf("\t\t\t\t\t\t2 - Check Balance\n");
		printf("\t\t\t\t\t\t3 - Loans\n");
		printf("\t\t\t\t\t\t4 - Exit\n");
		printf("\t\t\t\t\t\t-> ");
		scanf("%d", &op);
		
		switch(op){
			case 1:
				system("cls");
				system("pause");
				system("cls");
				goto startemployee;
			case 2:
				system("cls");
				system("pause");
				system("cls");
				goto startemployee;
			case 3:
				system("cls");
				system("pause");
				system("cls");
				goto startemployee;
			case 4:
				goto fim;
				break;
			default:
				system("cls");
				printf("Erro 404\n");
				system("pause");
				system("cls");
				goto startemployee;
			}	
		}
	fim:
	return 0;
}
